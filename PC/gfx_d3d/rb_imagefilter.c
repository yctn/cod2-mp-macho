/* Converted to C from ASM: rb_imagefilter.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_imagefilter.cpp */

#include "common_types.h"
#include "imports.h"

/* math functions - declared manually to avoid conflicts with imports/libc.h */
extern float floorf(float);
extern float expf(float);
extern float sqrtf(float);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_vector.h"
 */

extern bool g_LastGlowFilter;
extern UINT32 g_TotalFilterPasses;
extern bool g_ShowShadowCookies;
extern UINT32 g_NumBlurShadowPasses;

/*
 * Global pointers - these BSS symbols are declared as byte arrays in bss.c
 * but the original binary uses them as typed structures with known offsets.
 * We declare them as extern byte arrays and use raw offset arithmetic to
 * match the original binary's field layout (which may differ from the
 * common_types.h struct definitions due to array size differences).
 */
extern unsigned char rgp[];       /* r_global_permanent_t data */
extern unsigned char dx[];        /* DxGlobals data */
extern unsigned char vidConfig[]; /* vidConfig_t data */
extern unsigned char backEnd[];   /* r_backEndGlobals_t data */

/* External function declarations */
extern void RB_SetRenderTarget(GfxRenderTargetId newTargetId);
extern void RB_DrawStretchPic(MaterialHandle material, float x, float y, float w, float h,
                               float s0, float t0, float s1, float t1,
                               unsigned int color, int splitScreen);
extern void RB_EndSurface(void);

/* Function prototypes */
static int RB_GaussianFilterPoints1D(float pixels, int srcRes, int dstRes, int tapLimit, float *tapOffsets, float *tapWeights);
static int RB_GenerateGaussianFilter2D(float radius, int srcWidth, int srcHeight, int dstWidth, int dstHeight, GfxImageFilterPass *filterPass);
static int RB_GenerateGaussianFilterChain(float radiusX, float radiusY, int srcWidth, int srcHeight, int dstWidth, int dstHeight, int passLimit, GfxImageFilterPass *filterPass);
static GfxRenderTargetId RB_ApplyGlowFilter(GfxRenderTargetId srcRenderTarget, GfxRenderTargetId dstRenderTarget, float glowRadius);
int RB_GlowFilterImage(float *radius);
int RB_GaussianFilterImage(float radius, GfxRenderTargetId renderTargetId);

/*
 * Binary layout accessors for DxGlobals (offsets differ from common_types.h due to
 * array size differences in resolutionNameTable/refreshRateNameTable).
 *
 * DxGlobals renderTargets[id] at offset 0x2c30, each GfxRenderTarget is 20 bytes:
 *   +0  = GfxImage *image
 *   +4  = IDirect3DSurface9 *colorSurface
 *   +8  = IDirect3DSurface9 *depthStencilSurface
 *   +12 = int width
 *   +16 = int height
 */
#define DX_RT_IMAGE(id)     (((DxGlobals *)dx)->renderTargets[id].image)
#define DX_RT_WIDTH(id)     (((DxGlobals *)dx)->renderTargets[id].width)
#define DX_RT_HEIGHT(id)    (((DxGlobals *)dx)->renderTargets[id].height)

/*
 * r_global_permanent_t accessors:
 *   symmetricFilterMaterial[i] at offset 0x10b0 + i*4
 *   glowSetupMaterial at offset 0x10d4
 */
#define RGP_SYM_FILTER_MAT(i) (((r_global_permanent_t *)rgp)->symmetricFilterMaterial[i])
#define RGP_GLOW_SETUP_MAT()  (((r_global_permanent_t *)rgp)->glowSetupMaterial)

/*
 * r_backEndGlobals_t accessors (confirmed matching offsets):
 *   0x0230 = codeConsts[35] (pixel shader constants upload target)
 *   0x03c8 = viewParms pointer
 *   0x2e88 = source render target ID (used in glow path)
 *   0x2e8c = currentRenderTargetImage (GfxImage* for feedback)
 *   0x04d0 = glow pass count
 *   0x04d4 = glow blur image 0
 *   0x04d8 = glow blur image 1
 *
 * GfxViewParms:
 *   0x3c = viewport.Height
 *
 * vidConfig_t:
 *   0x00 = width
 *   0x04 = height
 *   0x14 = aspectRatioPixel
 */

/* Helper: compute next power of 2 >= val, as float (matches binary's inline code) */
static float nextPowerOfTwoF(unsigned int val)
{
    unsigned int d;
    int i;

    if (val <= 1)
        return 1.0f;

    d = 1;
    for (i = 32; i > 0; i--) {
        d += d;
        if (val <= d)
            return (float)d;
    }
    return (float)d;
}

/* Helper: absolute value of float */
static float absf(float x) { return x < 0.0f ? -x : x; }

/* Constants from the binary's float literal pool */
#define GLOW_MAX_RADIUS    1.3895604610443115f   /* lit4_002ed894 */
#define GLOW_MAX_RADIUS_SQ 1.9308782815933228f   /* lit4_002ed898 */
#define FILTER_MIN_RADIUS  0.3295051157474518f    /* lit4_002ed89c */
#define FILTER_MAX_SINGLE  6.497750282287598f     /* lit4_002ed8a0 */
#define FILTER_MAX_SQ      42.220760345458984f    /* lit4_002ed8a4 */

/* line 81 */
static int RB_GaussianFilterPoints1D(float pixels, int srcRes, int dstRes, int tapLimit, float *tapOffsets, float *tapWeights)
{
    float srcResF;
    float ratio;
    int ratioRounded;
    float offset;
    float gaussianExponent;
    float totalWeight;
    int tapIndex;
    float weight0, weight1;
    float sample0, sample1;
    float combinedWeight;
    int tapCount;

    srcResF = (float)srcRes;
    ratio = srcResF / (float)dstRes;
    ratioRounded = (int)floorf(ratio + 0.5f);

    /* Odd ratio: center-aligned samples (offset=0), even ratio: half-pixel offset */
    if (ratioRounded & 1) {
        offset = 0.0f;
    } else {
        offset = 0.5f;
    }

    /* line 101 - Gaussian exponent: -1/(2*sigma^2) where sigma=pixels */
    gaussianExponent = -0.5f / (pixels * pixels);

    /* line 104 */
    if (tapLimit <= 0) {
        /* line 125 - degenerate case: single center tap */
        tapWeights[0] = 0.5f;
        return 1;
    }

    /* Compute tap weights and offsets using bilinear tap combining */
    totalWeight = 0.0f;
    for (tapIndex = 0; tapIndex < tapLimit; tapIndex++) {
        /* line 106-107: compute positions of two adjacent texels */
        sample0 = (float)(tapIndex * 2) + offset;
        sample1 = (float)(tapIndex * 2 + 1) + offset;

        /* line 108-109: evaluate Gaussian at each texel position */
        weight0 = expf(gaussianExponent * sample0 * sample0);
        weight1 = expf(gaussianExponent * sample1 * sample1);

        /* line 110-113: halve center tap weight when center-aligned */
        if (tapIndex == 0 && offset == 0.0f) {
            weight0 *= 0.5f;
        }

        /* line 115: combine two texel weights into one bilinear tap */
        combinedWeight = weight1 + weight0;
        tapWeights[tapIndex] = combinedWeight;

        /* line 116-119: compute bilinear sampling offset */
        if (combinedWeight != 0.0f) {
            /* Weighted average of two texel positions, normalized to texcoord space */
            tapOffsets[tapIndex] = (weight0 * sample0 + weight1 * sample1) / (combinedWeight * srcResF);
        } else {
            /* Zero weight: just use midpoint */
            tapOffsets[tapIndex] = (sample0 + sample1) * 0.5f / srcResF;
        }

        /* line 120 */
        totalWeight += tapWeights[tapIndex];
    }

    /* line 123: if total weight is negligible, fall back to single tap */
    if (totalWeight <= 0.001f) {
        tapWeights[0] = 0.5f;
        return 1;
    }

    /* line 131-136: normalize weights so they sum to 0.5 (symmetric filter) */
    {
        float normFactor = 0.5f / totalWeight;
        tapCount = tapLimit;

        /* Normalize backwards, trimming trailing near-zero taps */
        for (tapIndex = tapLimit - 1; tapIndex >= 0; tapIndex--) {
            tapWeights[tapIndex] *= normFactor;
            if (0.01f > tapWeights[tapIndex]) {
                tapCount = tapIndex + 1;
            }
        }
    }

    /* line 141 */
    return tapCount;
}

/* line 173 */
static int RB_GenerateGaussianFilter2D(float radius, int srcWidth, int srcHeight, int dstWidth, int dstHeight, GfxImageFilterPass *filterPass)
{
    float tapOffsetsX[4];
    float tapOffsetsY[4];
    float tapWeightsX[4];
    float tapWeightsY[4];
    int iy, ix;
    int tapEntryIdx;

    /* line 183-184: compute 1D filter taps for each axis (max 2 bilinear taps each) */
    RB_GaussianFilterPoints1D(radius, srcWidth, dstWidth, 2, tapOffsetsX, tapWeightsX);
    RB_GaussianFilterPoints1D(radius, srcHeight, dstHeight, 2, tapOffsetsY, tapWeightsY);

    /*
     * Build 8 tap entries as outer product of 2 X-taps x 2 Y-taps, with mirroring.
     * For each (iy, ix): two vec4 entries are generated:
     *   {-offsetX[ix], offsetY[iy], 0, weightX[ix]*weightY[iy]}
     *   {+offsetX[ix], offsetY[iy], 0, weightX[ix]*weightY[iy]}
     */
    tapEntryIdx = 0;
    for (iy = 0; iy < 2; iy++) {
        for (ix = 0; ix < 2; ix++) {
            /* Negated X offset entry */
            filterPass->tapOffsetsAndWeights[tapEntryIdx][0] = -tapOffsetsX[ix];
            filterPass->tapOffsetsAndWeights[tapEntryIdx][1] = tapOffsetsY[iy];
            filterPass->tapOffsetsAndWeights[tapEntryIdx][2] = 0.0f;
            filterPass->tapOffsetsAndWeights[tapEntryIdx][3] = tapWeightsX[ix] * tapWeightsY[iy];
            tapEntryIdx++;

            /* Positive X offset entry */
            filterPass->tapOffsetsAndWeights[tapEntryIdx][0] = tapOffsetsX[ix];
            filterPass->tapOffsetsAndWeights[tapEntryIdx][1] = tapOffsetsY[iy];
            filterPass->tapOffsetsAndWeights[tapEntryIdx][2] = 0.0f;
            filterPass->tapOffsetsAndWeights[tapEntryIdx][3] = tapWeightsX[ix] * tapWeightsY[iy];
            tapEntryIdx++;
        }
    }

    /* line 76/206: use the 8-tap 2D symmetric filter material */
    filterPass->material = RGP_SYM_FILTER_MAT(7);
    filterPass->tapHalfCount = 8;

    /* line 208-209: texture coordinate scale (texel-to-texcoord) */
    filterPass->srcWidth = (float)srcWidth / nextPowerOfTwoF((unsigned int)srcWidth);
    filterPass->srcHeight = (float)srcHeight / nextPowerOfTwoF((unsigned int)srcHeight);

    /* line 214-215: destination dimensions */
    filterPass->dstWidth = dstWidth;
    filterPass->dstHeight = dstHeight;

    return 0;
}

/* line 220 */
static int RB_GenerateGaussianFilterChain(float radiusX, float radiusY, int srcWidth, int srcHeight, int dstWidth, int dstHeight, int passLimit, GfxImageFilterPass *filterPass)
{
    float tapOffsets[8];
    float tapWeights[8];
    int passCount;
    GfxImageFilterPass *curPass;
    float minRadius;
    float maxRadiusSq;
    int halfTapCount;
    int passAxis;
    int i;
    int curDstWidth;
    int curDstHeight;

    /* line 228-229 */
    curDstWidth = dstWidth;
    curDstHeight = dstHeight;

    /* line 232: if src and dst dimensions match, skip the initial downscale pass */
    if (dstWidth == srcWidth && dstHeight == srcHeight) {
        passCount = 0;
    } else {
        /* Determine initial 2D filter radius, clamped to GLOW_MAX_RADIUS */
        /* line 45: take min of the two radii */
        minRadius = radiusX < radiusY ? radiusX : radiusY;

        /* line 235 */
        if (minRadius > GLOW_MAX_RADIUS) {
            minRadius = GLOW_MAX_RADIUS;
            maxRadiusSq = GLOW_MAX_RADIUS_SQ;
        } else {
            maxRadiusSq = minRadius * minRadius;
        }

        /* line 81: compute residual radii after first pass, scaled to dst space */
        radiusX = sqrtf(radiusX * radiusX - maxRadiusSq) * (float)dstWidth / (float)srcWidth;
        radiusY = sqrtf(radiusY * radiusY - maxRadiusSq) * (float)dstHeight / (float)srcHeight;

        /* line 240 */
        RB_GenerateGaussianFilter2D(minRadius, srcWidth, srcHeight, dstWidth, dstHeight, filterPass);
        passCount = 1;
    }

    /* Iterative separable blur passes */
    curPass = &filterPass[passCount];

    while (passCount < 16) {
        float filterRadius;
        int dstRes;

        /* line 244: both radii below minimum threshold, done */
        if (radiusX < FILTER_MIN_RADIUS && radiusY < FILTER_MIN_RADIUS) {
            break;
        }

        /* line 246: if radii are close, try a combined 2D pass */
        if (absf(radiusX - radiusY) < FILTER_MIN_RADIUS) {
            float avgRadius = (radiusX + radiusY) * 0.5f;
            /* line 249 */
            if (avgRadius <= GLOW_MAX_RADIUS) {
                /* line 251: combined 2D pass */
                RB_GenerateGaussianFilter2D(avgRadius, curDstWidth, curDstHeight, curDstWidth, curDstHeight, curPass);
                passCount++;
                break;
            }
        }

        /* line 257: pick the axis with larger remaining radius */
        if (radiusX > radiusY) {
            /* X-axis pass */
            if (FILTER_MAX_SINGLE >= radiusX) {
                filterRadius = radiusX;
                radiusX = 0.0f;
            } else {
                radiusX = sqrtf(radiusX * radiusX - FILTER_MAX_SQ);
                filterRadius = FILTER_MAX_SINGLE;
            }
            passAxis = 0;
            dstRes = curDstWidth;
        } else {
            /* Y-axis pass */
            if (FILTER_MAX_SINGLE >= radiusY) {
                filterRadius = radiusY;
                radiusY = 0.0f;
            } else {
                radiusY = sqrtf(radiusY * radiusY - FILTER_MAX_SQ);
                filterRadius = FILTER_MAX_SINGLE;
            }
            passAxis = 1;
            dstRes = curDstHeight;
        }

        /* Generate 1D filter for the chosen axis */
        halfTapCount = RB_GaussianFilterPoints1D(filterRadius, dstRes, dstRes, 8, tapOffsets, tapWeights);

        /* Select material based on tap count */
        curPass->material = RGP_SYM_FILTER_MAT(halfTapCount - 1);
        curPass->tapHalfCount = halfTapCount;

        /* Fill tap entries: offset on active axis, zero on other axis */
        for (i = 0; i < 8; i++) {
            if (passAxis == 0) {
                curPass->tapOffsetsAndWeights[i][0] = tapOffsets[i];
                curPass->tapOffsetsAndWeights[i][1] = 0.0f;
            } else {
                curPass->tapOffsetsAndWeights[i][0] = 0.0f;
                curPass->tapOffsetsAndWeights[i][1] = tapOffsets[i];
            }
            curPass->tapOffsetsAndWeights[i][2] = 0.0f;
            curPass->tapOffsetsAndWeights[i][3] = tapWeights[i];
        }

        /* Texture coordinate scale */
        curPass->srcWidth = (float)curDstWidth / nextPowerOfTwoF((unsigned int)curDstWidth);
        curPass->srcHeight = (float)curDstHeight / nextPowerOfTwoF((unsigned int)curDstHeight);
        curPass->dstWidth = curDstWidth;
        curPass->dstHeight = curDstHeight;

        passCount++;
        curPass++;
    }

    /* line 293 */
    return passCount;
}

/*
 * Apply filter passes to render targets with ping-pong buffers.
 * Shared logic used by both RB_ApplyGlowFilter and RB_GaussianFilterImage.
 */
static void RB_ApplyFilterPasses(GfxImageFilter *filter, int swapLastPass)
{
    int passIndex;
    int passCount = filter->passCount;

    for (passIndex = 0; passIndex < passCount; passIndex++) {
        GfxImageFilterPass *pass = &filter->passes[passIndex];
        int pingPong = passIndex & 1;
        GfxRenderTargetId setTarget;
        int constIndex;
        float dstW, dstH;
        r_backEndGlobals_t *be = (r_backEndGlobals_t *)backEnd;

        /* Set source texture on backEnd */
        if (passIndex == 0) {
            /* First pass: use original source image */
            be->currentFeedbackImage = filter->sourceImage;
        } else {
            /* Subsequent passes: use previous ping-pong buffer's image */
            int srcPP = 1 - pingPong;
            GfxRenderTargetId ppTarget = filter->pingPongTargets[srcPP];
            be->currentFeedbackImage = DX_RT_IMAGE(ppTarget);
        }

        /* Determine render target */
        if (passIndex == passCount - 1) {
            /* Last pass: render to final target */
            setTarget = filter->finalTarget;
        } else {
            /* Intermediate pass: render to ping-pong buffer */
            setTarget = filter->pingPongTargets[pingPong];
        }

        RB_SetRenderTarget(setTarget);

        /* Upload pixel shader constants (tap offsets and weights) */
        if (pass->tapHalfCount > 0) {
            for (constIndex = 0; constIndex < pass->tapHalfCount; constIndex++) {
                be->codeConsts[35 + constIndex][0] = pass->tapOffsetsAndWeights[constIndex][0];
                be->codeConsts[35 + constIndex][1] = pass->tapOffsetsAndWeights[constIndex][1];
                be->codeConsts[35 + constIndex][2] = pass->tapOffsetsAndWeights[constIndex][2];
                be->codeConsts[35 + constIndex][3] = pass->tapOffsetsAndWeights[constIndex][3];
            }
        }

        dstW = (float)pass->dstWidth;
        dstH = (float)pass->dstHeight;

        /* Draw the filter quad */
        if (swapLastPass && passIndex == passCount - 1) {
            /* Last pass with swapped t0/t1 (used for sky bleed in glow) */
            RB_DrawStretchPic(pass->material, 0.0f, 0.0f, dstW, dstH,
                              0.0f, pass->srcHeight, pass->srcWidth, 0.0f,
                              0xFFFFFFFF, 0xa);
        } else {
            /* Normal draw */
            RB_DrawStretchPic(pass->material, 0.0f, 0.0f, dstW, dstH,
                              0.0f, 0.0f, pass->srcWidth, pass->srcHeight,
                              0xFFFFFFFF, 0xa);
        }

        RB_EndSurface();
    }
}

/* line 500 */
static GfxRenderTargetId RB_ApplyGlowFilter(GfxRenderTargetId srcRenderTarget, GfxRenderTargetId dstRenderTarget, float glowRadius)
{
    GfxImageFilter filter;
    int passCount;
    int chainPassCount;
    int startPass;
    int dstWidth, dstHeight;
    float scaledRadius;

    /* line 509: zero radius means no filtering */
    if (glowRadius == 0.0f) {
        return dstRenderTarget;
    }

    /* line 59: scale radius by viewport height / 480 */
    {
        const r_backEndGlobals_t *backend = (const r_backEndGlobals_t *)backEnd;
        const GfxViewParms *viewParms = backend->viewParms;
        int viewportHeight = (int)viewParms->viewport.Height;
        float heightScaled = (float)viewportHeight * glowRadius / 480.0f;

        /* line 60: multiply by aspect ratio */
        const vidConfig_t *vcfg = (const vidConfig_t *)vidConfig;
        scaledRadius = heightScaled * vcfg->aspectRatioPixel;
    }

    /* line 519-520 */
    filter.pingPongTargets[0] = R_RENDERTARGET_PINGPONG_0;
    filter.pingPongTargets[1] = R_RENDERTARGET_PINGPONG_1;

    /* line 523-524 */
    dstWidth = DX_RT_WIDTH(dstRenderTarget);
    dstHeight = DX_RT_HEIGHT(dstRenderTarget);

    /* line 526-528 */
    filter.sourceImage = DX_RT_IMAGE(srcRenderTarget);
    filter.finalTarget = dstRenderTarget;
    filter.passCount = 0;

    /* line 530: special handling for resolved scene source */
    if (srcRenderTarget == R_RENDERTARGET_RESOLVED_SCENE) {
        /* Setup initial downscale pass from full-res scene to glow buffer */
        int sceneWidth = DX_RT_WIDTH(R_RENDERTARGET_RESOLVED_SCENE);
        int sceneHeight = DX_RT_HEIGHT(R_RENDERTARGET_RESOLVED_SCENE);

        filter.passes[0].srcWidth = (float)sceneWidth / nextPowerOfTwoF((unsigned int)sceneWidth);
        filter.passes[0].srcHeight = (float)sceneHeight / nextPowerOfTwoF((unsigned int)sceneHeight);
        filter.passes[0].dstWidth = dstWidth;
        filter.passes[0].dstHeight = dstHeight;
        filter.passes[0].tapHalfCount = 0;
        filter.passes[0].material = RGP_GLOW_SETUP_MAT();
        filter.passCount = 1;
    }

    /* line 546: generate gaussian filter chain */
    startPass = filter.passCount;
    chainPassCount = RB_GenerateGaussianFilterChain(
        scaledRadius, scaledRadius,
        dstWidth, dstHeight,
        dstWidth, dstHeight,
        16 - startPass,
        &filter.passes[startPass]
    );
    filter.passCount = startPass + chainPassCount;
    passCount = filter.passCount;

    /* line 547: no passes means no filtering */
    if (passCount == 0) {
        return dstRenderTarget;
    }

    /* line 552: accumulate total filter passes */
    g_TotalFilterPasses += passCount;

    /* Apply filter passes */
    {
        int swapLast = (g_LastGlowFilter && !(g_TotalFilterPasses & 1));
        RB_ApplyFilterPasses(&filter, swapLast);
    }

    return dstRenderTarget;
}

/* line 562 */
int RB_GlowFilterImage(float *radius)
{
    float radiusX, radiusY;
    float scaleRatio;
    GfxRenderTargetId result;
    r_backEndGlobals_t *be;

    /* line 570 */
    radiusX = radius[0];
    if (radiusX == 0.0f) {
        return 0;
    }

    /* line 576: scale radii by glow-to-scene render target size ratio */
    scaleRatio = (float)DX_RT_WIDTH(R_RENDERTARGET_GLOW_0) / (float)DX_RT_WIDTH(R_RENDERTARGET_RESOLVED_SCENE);

    /* line 577-578 */
    radiusX *= scaleRatio;
    radius[0] = radiusX;
    radiusY = radius[1] * scaleRatio;
    radius[1] = radiusY;

    /* line 580: set g_LastGlowFilter based on whether second radius is zero */
    g_LastGlowFilter = (radiusY == 0.0f);

    /* line 582 */
    if (radius[1] != 0.0f) {
        /* line 584: compute orthogonal component */
        float rx = radius[0];
        float ry = radius[1];
        float orthoRadius = sqrtf(ry * ry - rx * rx);
        /* line 587 */
        g_LastGlowFilter = (orthoRadius == 0.0f) ? 1 : 0;
    }

    /* line 591: apply first glow filter pass */
    be = (r_backEndGlobals_t *)backEnd;
    {
        GfxRenderTargetId srcTarget = be->resolvedSceneTarget;
        result = RB_ApplyGlowFilter(srcTarget, R_RENDERTARGET_GLOW_0, radius[0]);
    }

    /* line 592: store first blurred image result */
    {
        GfxImage *blurImage = DX_RT_IMAGE(result);
        be->glowImage[0] = blurImage;
    }

    /* line 593: check if second pass is needed */
    if (radius[1] == 0.0f) {
        /* line 595: single-pass glow */
        be->glowCount = 1;
        return 0;
    }

    /* line 600: compute second-pass radius from orthogonal component */
    {
        float rx = radius[0];
        float ry = radius[1];
        radius[1] = sqrtf(ry * ry - rx * rx);
    }

    /* line 602 */
    g_LastGlowFilter = 1;

    /* line 604: apply second glow pass */
    {
        GfxRenderTargetId secondResult = RB_ApplyGlowFilter(result, R_RENDERTARGET_GLOW_0, radius[1]);

        /* line 605: store second blurred image */
        be = (r_backEndGlobals_t *)backEnd;
        be->glowImage[1] = DX_RT_IMAGE(secondResult);

        /* line 606: two-pass glow */
        be->glowCount = 2;
    }

    return 0;
}

/* line 468 */
int RB_GaussianFilterImage(float radius, GfxRenderTargetId renderTargetId)
{
    GfxImageFilter filter;
    int passCount;
    int passIndex;
    r_backEndGlobals_t *be;
    int width, height;
    float scaledRadius;
    int oddPassCount;

    /* Shadow-cookie visualization is a debug path in the D3D shim and
     * should not hijack normal fullscreen blur copies. */
    g_ShowShadowCookies = 0;
    g_NumBlurShadowPasses = 0;

    /* The Mac D3D shim still falls over when restoring from the fullscreen
     * blur target. Skip this optional post-effect path for now. */
    if (renderTargetId == R_RENDERTARGET_BLURRED_SCREEN) {
        return 0;
    }

    /* line 59: scale radius by viewport height / 480 */
    be = (r_backEndGlobals_t *)backEnd;
    {
        const GfxViewParms *viewParms = be->viewParms;
        int viewportHeight = (int)viewParms->viewport.Height;
        float heightScaled = (float)viewportHeight * radius / 480.0f;

        /* line 60 */
        const vidConfig_t *vcfg = (const vidConfig_t *)vidConfig;
        scaledRadius = heightScaled * vcfg->aspectRatioPixel;
    }

    /* line 483-484 */
    filter.pingPongTargets[0] = R_RENDERTARGET_PINGPONG_0;
    filter.pingPongTargets[1] = R_RENDERTARGET_PINGPONG_1;

    /* line 487-490 */
    width = DX_RT_WIDTH(renderTargetId);
    height = DX_RT_HEIGHT(renderTargetId);
    filter.sourceImage = DX_RT_IMAGE(R_RENDERTARGET_RESOLVED_SCENE);
    filter.finalTarget = renderTargetId;

    /* line 491: generate filter chain from vidConfig dimensions to target dimensions */
    {
        const vidConfig_t *vcfg2 = (const vidConfig_t *)vidConfig;
        int vidWidth = vcfg2->width;
        int vidHeight = vcfg2->height;

        passCount = RB_GenerateGaussianFilterChain(
            scaledRadius, scaledRadius,
            vidWidth, vidHeight,
            width, height,
            16,
            &filter.passes[0]
        );
    }
    filter.passCount = passCount;

    /* line 362 */
    oddPassCount = passCount & 1;

    /* line 364: apply filter passes */
    for (passIndex = 0; passIndex < passCount; passIndex++) {
        GfxImageFilterPass *pass = &filter.passes[passIndex];
        int pingPong = passIndex & 1;
        GfxRenderTargetId setTarget;
        int constIndex;
        float dstW, dstH;

        be = (r_backEndGlobals_t *)backEnd;

        /* line 325-326: set source texture */
        if (passIndex == 0) {
            be->currentFeedbackImage = filter.sourceImage;
        } else {
            int srcPP = 1 - pingPong;
            GfxRenderTargetId ppTarget = filter.pingPongTargets[srcPP];
            be->currentFeedbackImage = DX_RT_IMAGE(ppTarget);
        }

        /* line 331-334: determine render target */
        if (passIndex == passCount - 1) {
            setTarget = filter.finalTarget;
        } else {
            setTarget = filter.pingPongTargets[pingPong];
        }

        /* line 336 */
        RB_SetRenderTarget(setTarget);

        /* line 301: upload pixel shader constants */
        if (pass->tapHalfCount > 0) {
            for (constIndex = 0; constIndex < pass->tapHalfCount; constIndex++) {
                be->codeConsts[35 + constIndex][0] = pass->tapOffsetsAndWeights[constIndex][0];
                be->codeConsts[35 + constIndex][1] = pass->tapOffsetsAndWeights[constIndex][1];
                be->codeConsts[35 + constIndex][2] = pass->tapOffsetsAndWeights[constIndex][2];
                be->codeConsts[35 + constIndex][3] = pass->tapOffsetsAndWeights[constIndex][3];
            }
        }

        /* line 370-371 */
        dstW = (float)pass->dstWidth;
        dstH = (float)pass->dstHeight;

        /* line 374: draw filter quad */
        if (!oddPassCount && passIndex == passCount - 1) {
            /* Last pass with even total: swap t0/t1 */
            RB_DrawStretchPic(pass->material, 0.0f, 0.0f, dstW, dstH,
                              0.0f, pass->srcHeight, pass->srcWidth, 0.0f,
                              0xFFFFFFFF, 0xa);
        } else {
            /* Normal draw */
            RB_DrawStretchPic(pass->material, 0.0f, 0.0f, dstW, dstH,
                              0.0f, 0.0f, pass->srcWidth, pass->srcHeight,
                              0xFFFFFFFF, 0xa);
        }

        /* line 383 */
        RB_EndSurface();
    }

    /* line 498 */
    return 0;
}
