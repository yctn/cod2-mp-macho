/* ASM dump from: rb_sky.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_sky.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_math.h"
 */

extern SunFlareDynamic sunFlareArray[4]; /* 0x0 */

/* Globals accessed via absolute addresses */
extern IDirect3DQuery9 *r_occlusionQuery;              /* 0x12184c4 */
extern void *dx_device_ptr;                             /* imp_dx - device struct, field at +8 is IDirect3DDevice9* */
extern volatile int *dx_fence;                          /* imp_alwaysfails */
extern void *r_glob;                                    /* imp_rgp - GfxGlobals */
extern void *r_frontEndDataOut;                         /* imp_backEnd */
extern void *gfx_buf;                                   /* imp_tess - tess globals */
extern void *r_dvar_sunEnable;                          /* imp_r_drawSun */
extern void *r_rendererGlob;                            /* imp_r_rendererInUse */
extern unsigned int r_defaultColor;                     /* imp_colorWhite */
extern void *r_videoConfig;                             /* imp_vidConfig */
extern void *r_phys;                                    /* imp_ri */
extern unsigned int r_contentmask;                      /* imp_vec3_origin */

/* External functions */
extern void RB_ClearScreen(int whichToClear, const vec_t *color, float depth, int stencil);
extern void RB_DrawStretchPic(const Material *material, float x, float y, float w, float h, float s0, float t0, float s1, float t1, D3DCOLOR color, GfxPrimStatsTarget statsTarget);
extern void RB_EndSurface(void);
extern void RB_BeginSurface(const Material *material, MaterialTechniqueType techType, int lmapIndex);
extern void RB_PushMatrixStack(void);
extern void RB_PopMatrixStack(void);
extern void RB_DrawFullScreenColoredQuad(const Material *material, float s0, float t0, float s1, float t1, D3DCOLOR color);
extern void MatrixIdentity44(float *matrix);
extern void RB_SetProjectionMatrix(const float *matrix);
extern void RB_SetViewMatrix(const float *matrix);
extern void RB_Set3D(void);
extern void Vec3Cross(const vec_t *v0, const vec_t *v1, vec_t *cross);
extern float Vec3Normalize(vec_t *v);
extern void RB_SetViewMatrixForWDx7(float w);
extern void WinSleep(DWORD dwMilliseconds);
extern float floorf(float x);

/* Forward declarations */
int RB_CalcSunSpriteSamples(void);
static GfxVertex * RB_SetTessQuad(union GfxColor color);
static GfxVertexDx7 * RB_SetTessQuadDx7(GfxColor color);
static unsigned char RB_TessSunBillboard(float widthInClipSpace, float heightInClipSpace);
unsigned char RB_DrawSunPostEffects(int viewIndex);
unsigned char RB_DrawSun(int viewIndex);

/*
 * Helper: access bytes at a pointer + offset, cast to desired type.
 * Used because many global pointers are opaque (their structs have only _placeholder).
 */
#define FIELD(base, offset, type) (*(type *)((char *)(base) + (offset)))
#define FIELDP(base, offset, type) ((type *)((char *)(base) + (offset)))

/* IDirect3DQuery9 vtable offsets (COM interface):
 * +0x18 = Issue(query, flags)
 * +0x1c = GetData(query, pData, dataSize, flags)
 * IDirect3DDevice9 vtable offsets:
 * +0xa4 = BeginScene (device)
 * +0xa8 = EndScene (device)
 */
typedef int (__attribute__((cdecl)) *QueryIssueFn)(void *query, int flags);
typedef int (__attribute__((cdecl)) *QueryGetDataFn)(void *query, void *pData, int dataSize, int flags);
typedef int (__attribute__((cdecl)) *DeviceBeginSceneFn)(void *device);
typedef int (__attribute__((cdecl)) *DeviceEndSceneFn)(void *device);
typedef void *(__attribute__((cdecl)) *TraceCallFn)(int hitNum, void *start, vec_t *end, float *frac1, float *frac2, int contentmask, int flags);

/* line 27 */
int RB_CalcSunSpriteSamples(void)
{
    IDirect3DQuery9 *occlusionQuery;
    void **vtable;
    void *device;
    int sampleCount;
    int result;

    occlusionQuery = r_occlusionQuery;
    if (!occlusionQuery) {
        return 0;
    }

    /* BeginScene loop */
    do {
        device = FIELD(&dx_device_ptr, 0, void *);
        device = FIELD(device, 8, void *);
        vtable = FIELD(device, 0, void **);
        ((DeviceBeginSceneFn)vtable[0xa4 / 4])(device);
    } while (FIELD(dx_fence, 0, int) != 0);

    /* Clear screen */
    RB_ClearScreen(2, (const vec_t *)&r_defaultColor, 1.0f, 0);

    /* Issue query begin */
    do {
        vtable = FIELD(occlusionQuery, 0, void **);
        ((QueryIssueFn)vtable[0x18 / 4])(occlusionQuery, 2);
    } while (FIELD(dx_fence, 0, int) != 0);

    /* Draw full screen quad */
    {
        Material *mat;
        void *glob = r_glob;
        mat = FIELD(glob, 0x1038, Material *);
        RB_DrawStretchPic(mat, 0.0f, 0.0f, 16.0f, 16.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0xffffffff, 10);
    }
    RB_EndSurface();

    /* Issue query end */
    do {
        vtable = FIELD(occlusionQuery, 0, void **);
        ((QueryIssueFn)vtable[0x18 / 4])(occlusionQuery, 1);
    } while (FIELD(dx_fence, 0, int) != 0);

    /* EndScene loop */
    do {
        device = FIELD(&dx_device_ptr, 0, void *);
        device = FIELD(device, 8, void *);
        vtable = FIELD(device, 0, void **);
        ((DeviceEndSceneFn)vtable[0xa8 / 4])(device);
    } while (FIELD(dx_fence, 0, int) != 0);

    /* GetData loop - wait for query result */
    do {
        vtable = FIELD(occlusionQuery, 0, void **);
        result = ((QueryGetDataFn)vtable[0x1c / 4])(occlusionQuery, &sampleCount, 4, 1);
        if (result == 1) {
            WinSleep(0);
        }
    } while (result == 1);

    /* If GetData returned 0 (success), use sampleCount; otherwise 256 */
    if (result != 0) {
        sampleCount = 0x100;
    }

    return sampleCount;
}

/* line 170 */
static GfxVertex * RB_SetTessQuad(union GfxColor color)
{
    char *tess;
    unsigned short vertCount;
    unsigned short indexCount;
    unsigned short *indices;
    GfxVertex *v;

    tess = (char *)gfx_buf;
    vertCount = FIELD(tess, 0x5a7d4, unsigned short);
    indexCount = FIELD(tess, 0x5a7d0, unsigned short);
    indices = FIELD(tess, 0x5a7b0, unsigned short *);

    /* Set up 6 indices for a quad (two triangles) */
    indices[indexCount + 0] = vertCount + 3;
    indices[FIELD(tess, 0x5a7d0, unsigned int) + 1] = vertCount;
    {
        unsigned short idx2 = vertCount + 2;
        indices[FIELD(tess, 0x5a7d0, unsigned int) + 2] = idx2;
        indices[FIELD(tess, 0x5a7d0, unsigned int) + 3] = idx2;
    }
    indices[FIELD(tess, 0x5a7d0, unsigned int) + 4] = vertCount;
    indices[FIELD(tess, 0x5a7d0, unsigned int) + 5] = vertCount + 1;

    /* Get pointer to vertex array; GfxVertex is 64 bytes (0x40) */
    /* Base of vertex data is tess + 0x10, each vertex is 64 bytes, starts at vertCount */
    v = (GfxVertex *)((char *)tess + 0x10 + (unsigned short)vertCount * 64);

    /* Vertex 0: normal = {0,0,1}, texCoord = {0,0}, color = color */
    v[0].xyzw[0] = 0.0f;
    v[0].xyzw[1] = 0.0f;
    v[0].xyzw[2] = 1.0f;
    v[0].texCoord[0] = 0.0f;
    v[0].texCoord[1] = 0.0f;
    v[0].color = color;

    /* Vertex 1: normal = {1,0,0}, texCoord = {0,0}, color = color */
    v[1].xyzw[0] = 1.0f;
    v[1].xyzw[1] = 0.0f;
    v[1].xyzw[2] = 0.0f;
    v[1].texCoord[0] = 0.0f;
    v[1].texCoord[1] = 0.0f;
    v[1].color = color;

    /* Vertex 2: normal = {0,1,0}, texCoord = {1,1}, color = color */
    v[2].xyzw[0] = 0.0f;
    v[2].xyzw[1] = 1.0f;
    v[2].xyzw[2] = 0.0f;
    v[2].texCoord[0] = 1.0f;
    v[2].texCoord[1] = 0.0f;
    v[2].color = color;

    /* Vertex 3: normal = {0,0,1}, texCoord = {0,1}, color = color */
    v[3].xyzw[0] = 0.0f;
    v[3].xyzw[1] = 0.0f;
    v[3].xyzw[2] = 1.0f;
    v[3].texCoord[0] = 1.0f;
    v[3].texCoord[1] = 1.0f;
    v[3].color = color;

    FIELD(tess, 0x5a7d4, unsigned int) += 4;
    FIELD(tess, 0x5a7d0, unsigned int) += 6;

    return v;
}

/* line 127 */
static GfxVertexDx7 * RB_SetTessQuadDx7(GfxColor color)
{
    char *tess;
    unsigned short vertCount;
    unsigned short indexCount;
    unsigned short *indices;
    GfxVertexDx7 *v;

    tess = (char *)gfx_buf;
    vertCount = FIELD(tess, 0x5a7d4, unsigned short);
    indexCount = FIELD(tess, 0x5a7d0, unsigned short);
    indices = FIELD(tess, 0x5a7b0, unsigned short *);

    /* Set up 6 indices for a quad */
    indices[indexCount + 0] = vertCount + 3;
    indices[FIELD(tess, 0x5a7d0, unsigned int) + 1] = vertCount;
    {
        unsigned short idx2 = vertCount + 2;
        indices[FIELD(tess, 0x5a7d0, unsigned int) + 2] = idx2;
        indices[FIELD(tess, 0x5a7d0, unsigned int) + 3] = idx2;
    }
    indices[FIELD(tess, 0x5a7d0, unsigned int) + 4] = vertCount;
    indices[FIELD(tess, 0x5a7d0, unsigned int) + 5] = vertCount + 1;

    /* GfxVertexDx7 is 36 bytes; base at tess + vertCount*36 + 0xc */
    v = (GfxVertexDx7 *)((char *)tess + (unsigned short)vertCount * 36 + 0xc);

    /* Vertex 0: normal = {0,0,1}, texCoord = {0,0}, color = color */
    v[0].normal[0] = 0.0f;
    v[0].normal[1] = 0.0f;
    v[0].normal[2] = 1.0f;
    v[0].texCoord[0] = 0.0f;
    v[0].texCoord[1] = 0.0f;
    v[0].color = color;

    /* Vertex 1: normal = {0,0,1}, texCoord = {1,0}, color = color */
    v[1].normal[0] = 0.0f;
    v[1].normal[1] = 0.0f;
    v[1].normal[2] = 1.0f;
    v[1].texCoord[0] = 1.0f;
    v[1].texCoord[1] = 0.0f;
    v[1].color = color;

    /* Vertex 2: normal = {0,0,1}, texCoord = {1,1}, color = color */
    v[2].normal[0] = 0.0f;
    v[2].normal[1] = 0.0f;
    v[2].normal[2] = 1.0f;
    v[2].texCoord[0] = 1.0f;
    v[2].texCoord[1] = 1.0f;
    v[2].color = color;

    /* Vertex 3: normal = {0,0,1}, texCoord = {0,1}, color = color */
    v[3].normal[0] = 0.0f;
    v[3].normal[1] = 0.0f;
    v[3].normal[2] = 1.0f;
    v[3].texCoord[0] = 0.0f;
    v[3].texCoord[1] = 1.0f;
    v[3].color = color;

    FIELD(tess, 0x5a7d4, unsigned int) += 4;
    FIELD(tess, 0x5a7d0, unsigned int) += 6;

    return v;
}

/*
 * Helper: compute dot product of vec3 a and column col of 4x3 matrix (row-major, stride 16 bytes).
 * matrix layout: matrix[col*4 + row] for column col, row row.
 */
static float DotColumn(const float *a, const float *matrix, int col)
{
    return a[0] * matrix[col] + a[1] * matrix[col + 4] + a[2] * matrix[col + 8];
}

/*
 * FadeToGoal: smoothly interpolate current towards goal.
 * Shared inline logic used multiple times in the assembly (lines 104-119).
 */
static float FadeToGoal(float goal, float current, int fadeInTime, int fadeOutTime, int frameTime)
{
    if (goal > current) {
        if (fadeInTime > 0) {
            float step = (float)frameTime / (float)fadeInTime;
            float newVal = current + step;
            if (newVal > goal) {
                return goal;
            }
            return newVal;
        }
        return goal;
    } else {
        /* goal <= current */
        if (goal < current) {
            if (fadeOutTime > 0) {
                float step = (float)frameTime / (float)fadeOutTime;
                float newVal = current - step;
                if (newVal < goal) {
                    return goal;
                }
                return newVal;
            }
        }
        return current;
    }
}

/* line 272 */
static unsigned char RB_TessSunBillboard(float widthInClipSpace, float heightInClipSpace)
{
    D3DCOLOR colorVal;
    void *rendererGlob;
    float *viewProjectionMatrix;
    float identity[16];
    float sunDir[3];
    float clipX, clipY, clipZ, clipW;
    float nearClip;
    float scale;
    GfxVertex *verts;
    GfxVertexDx7 *vertsDx7;

    /* Register eax = color argument (passed in eax by custom calling convention) */
    colorVal = (D3DCOLOR)(unsigned int)widthInClipSpace; /* placeholder - color comes via eax */

    /* Compiler passes color in eax, widthInClipSpace in xmm0, heightInClipSpace in xmm1 */
    /* In the naked asm, eax = color, xmm0 = widthInClipSpace, xmm1 = heightInClipSpace */

    rendererGlob = *(void **)r_rendererGlob;
    if (FIELD(rendererGlob, 8, int) == 2) {
        /* Dx7 path */
        void *frontEnd = r_frontEndDataOut;
        float *viewMat;  /* 4x4 matrix at frontEnd + 0x3c8 + 0xc8 */
        void *viewData = FIELD(frontEnd, 0x3c8, void *);
        float *matCol0 = FIELDP(viewData, 0xc8, float);  /* column 0 */
        float *matCol1 = FIELDP(viewData, 0xd8, float);  /* column 1 */
        float *matCol2 = FIELDP(viewData, 0xe8, float);  /* column 2 */

        void *glob = r_glob;
        float *sunDirPtr = FIELDP(FIELD(glob, 0x109c, void *), 0x1b4, float);
        float sx = sunDirPtr[0], sy = sunDirPtr[1], sz = sunDirPtr[2];

        clipX = sx * matCol0[0] + sy * matCol1[0] + sz * matCol2[0];
        clipY = sx * matCol0[1] + sy * matCol1[1] + sz * matCol2[1];
        clipZ = sx * matCol0[2] + sy * matCol1[2] + sz * matCol2[2];
        clipW = sx * matCol0[3] + sy * matCol1[3] + sz * matCol2[3];

        scale = 1.0f / clipW;

        clipX *= scale;
        clipY *= scale;
        clipZ *= scale;

        MatrixIdentity44(identity);
        RB_SetProjectionMatrix(identity);
        RB_SetViewMatrix(identity);

        vertsDx7 = RB_SetTessQuadDx7(*(GfxColor *)&colorVal);

        /* Set vertex positions */
        vertsDx7[0].xyz[0] = clipX;
        vertsDx7[0].xyz[1] = clipY;
        vertsDx7[0].xyz[2] = clipZ;

        vertsDx7[1].xyz[0] = clipX;
        vertsDx7[1].xyz[1] = clipY;
        vertsDx7[1].xyz[2] = clipZ;

        vertsDx7[2].xyz[0] = clipX;
        vertsDx7[2].xyz[1] = clipY;
        vertsDx7[2].xyz[2] = clipZ;

        vertsDx7[3].xyz[0] = clipX;
        vertsDx7[3].xyz[1] = clipY;
        vertsDx7[3].xyz[2] = clipZ;

        /* Offset vertices by width/height */
        vertsDx7[0].xyz[0] += widthInClipSpace;
        vertsDx7[0].xyz[1] += heightInClipSpace;
        vertsDx7[0].xyz[2] -= 0.001f;

        vertsDx7[1].xyz[0] += widthInClipSpace;
        vertsDx7[1].xyz[1] -= heightInClipSpace;
        vertsDx7[1].xyz[2] -= 0.001f;

        vertsDx7[2].xyz[0] -= widthInClipSpace;
        vertsDx7[2].xyz[1] -= heightInClipSpace;
        vertsDx7[2].xyz[2] -= 0.001f;

        vertsDx7[3].xyz[0] -= widthInClipSpace;
        vertsDx7[3].xyz[1] += heightInClipSpace;
        vertsDx7[3].xyz[2] -= 0.001f;
    } else {
        /* D3D9 path */
        void *glob = r_glob;
        void *scene = FIELD(glob, 0x109c, void *);
        float *sunDirPtr = FIELDP(scene, 0x1b4, float);
        float sx = sunDirPtr[0], sy = sunDirPtr[1], sz = sunDirPtr[2];

        viewProjectionMatrix = FIELDP(r_frontEndDataOut, 0x3f0, float);

        clipX = sx * viewProjectionMatrix[0] + sy * viewProjectionMatrix[0x10/4] + sz * viewProjectionMatrix[0x20/4];
        clipY = sx * viewProjectionMatrix[1] + sy * viewProjectionMatrix[0x14/4] + sz * viewProjectionMatrix[0x24/4];
        clipZ = sx * viewProjectionMatrix[2] + sy * viewProjectionMatrix[0x18/4] + sz * viewProjectionMatrix[0x28/4];
        clipW = sx * viewProjectionMatrix[3] + sy * viewProjectionMatrix[0x1c/4] + sz * viewProjectionMatrix[0x2c/4];

        MatrixIdentity44(identity);
        RB_SetProjectionMatrix(identity);
        RB_SetViewMatrix(identity);

        verts = RB_SetTessQuad(*(GfxColor *)&colorVal);
        nearClip = clipW * -0.001f;

        /* Set all 4 verts to the same clip-space position */
        verts[0].xyzw[0] = clipX;
        verts[0].xyzw[1] = clipY;
        verts[0].xyzw[2] = clipZ;
        verts[0].xyzw[3] = clipW;

        verts[1].xyzw[0] = clipX;
        verts[1].xyzw[1] = clipY;
        verts[1].xyzw[2] = clipZ;
        verts[1].xyzw[3] = clipW;

        verts[2].xyzw[0] = clipX;
        verts[2].xyzw[1] = clipY;
        verts[2].xyzw[2] = clipZ;
        verts[2].xyzw[3] = clipW;

        verts[3].xyzw[0] = clipX;
        verts[3].xyzw[1] = clipY;
        verts[3].xyzw[2] = clipZ;
        verts[3].xyzw[3] = clipW;

        /* Offset by width/height in clip-space */
        heightInClipSpace *= clipW;
        widthInClipSpace *= clipW;

        verts[0].xyzw[0] += widthInClipSpace;
        verts[0].xyzw[1] += heightInClipSpace;
        verts[0].xyzw[2] += nearClip;

        verts[1].xyzw[0] += widthInClipSpace;
        verts[1].xyzw[1] -= heightInClipSpace;
        verts[1].xyzw[2] += nearClip;

        verts[2].xyzw[0] -= widthInClipSpace;
        verts[2].xyzw[1] -= heightInClipSpace;
        verts[2].xyzw[2] += nearClip;

        verts[3].xyzw[0] -= widthInClipSpace;
        verts[3].xyzw[1] += heightInClipSpace;
        verts[3].xyzw[2] += nearClip;
    }

    return 0;
}

/* line 789 */
unsigned char RB_DrawSunPostEffects(int viewIndex)
{
    D3DCOLOR color;
    SunFlareDynamic *sunFlare;
    int frameTime;
    void *frontEnd;
    void *glob;
    void *scene;
    float sizeIn640x480;
    float alpha;

    color = 0;

    sunFlare = &sunFlareArray[viewIndex];

    frontEnd = r_frontEndDataOut;

    if (sunFlare->lastTime == 0) {
        frameTime = 10;
    } else {
        int backendTime = FIELD(frontEnd, 0x3b8, int);
        if (backendTime <= sunFlare->lastTime) {
            frameTime = 10;
        } else {
            frameTime = backendTime - sunFlare->lastTime;
        }
    }

    sunFlare->lastTime = FIELD(frontEnd, 0x3b8, int);

    /* Check if sun is enabled */
    {
        void *dvar = *(void **)r_dvar_sunEnable;
        if (FIELD(dvar, 8, unsigned char) == 0)
            return 0;
    }

    glob = r_glob;
    scene = FIELD(glob, 0x109c, void *);
    if (FIELD(scene, 0x160, unsigned char) == 0)
        return 0;

    {
        Material *sunMaterial = FIELD(scene, 0x168, void *);
        float sunFlareCosBegin, sunFlareCosEnd;
        float lastDot;
        float cosAngle;

        if (sunMaterial == 0)
            goto after_sunflare_material;

        lastDot = sunFlare->lastDot;
        sunFlareCosBegin = FIELD(scene, 0x174, float);

        if (sunFlareCosBegin >= lastDot)
            goto after_sunflare_material;

        sunFlareCosEnd = FIELD(scene, 0x17c, float);
        if (lastDot < sunFlareCosEnd) {
            /* Interpolate between begin and end */
            alpha = (lastDot - sunFlareCosBegin) / (sunFlareCosEnd - sunFlareCosBegin);
        } else {
            alpha = 1.0f;
        }

        {
            float spriteScale = FIELD(scene, 0x180, float);
            float spriteSize = FIELD(scene, 0x178, float);
            int iFadeInTime = FIELD(scene, 0x184, int);
            int iFadeOutTime = FIELD(scene, 0x188, int);
            float fGoalAlpha;

            fGoalAlpha = alpha * spriteScale;
            sizeIn640x480 = alpha * spriteSize;
            sizeIn640x480 += FIELD(scene, 0x170, float);

            /* Fade flareIntensity towards goal */
            sunFlare->flareIntensity = FadeToGoal(fGoalAlpha, sunFlare->flareIntensity, iFadeInTime, iFadeOutTime, frameTime);
            fGoalAlpha = sunFlare->flareIntensity;
            alpha = fGoalAlpha;
        }

        /* Begin surface for sun flare material */
        {
            char *tessBuf = (char *)gfx_buf;
            if (FIELD(tessBuf, 0x5a7d0, int) != 0 || FIELD(tessBuf, 0x5a7e0, int) != 0) {
                RB_EndSurface();
            }

            {
                Material *mat = FIELD(FIELD(r_glob, 0x109c, void *), 0x168, Material *);
                char *tb = (char *)gfx_buf;
                if (mat == FIELD(tb, 0x5a7bc, Material *) && FIELD(tb, 0x5a7c0, int) == 3) {
                    /* Already set up */
                } else {
                    if (FIELD(tb, 0x5a7d0, int) != 0 || FIELD(tb, 0x5a7e0, int) != 0) {
                        RB_EndSurface();
                    }
                    RB_BeginSurface(mat, 3, 0x1f);
                }
            }
        }

        RB_PushMatrixStack();

        /* Compute alpha byte value */
        {
            int alphaByte;
            alpha *= 255.0f;
            alphaByte = (int)floorf(alpha + 0.5f);
            color = 0;
            color = (color & 0xFFFFFF00) | 0xFF;
            color = (color & 0xFFFF00FF) | ((alphaByte & 0xFF) << 8);
            color = (color & 0xFF00FFFF) | ((alphaByte & 0xFF) << 16);
            color = (color & 0x00FFFFFF) | ((alphaByte & 0xFF) << 24);
        }

        /* Tess the sun billboard */
        RB_TessSunBillboard(sizeIn640x480 / 640.0f, sizeIn640x480 / 480.0f);
        RB_EndSurface();
        RB_PopMatrixStack();

        frontEnd = r_frontEndDataOut;
    }

after_sunflare_material:
    {
        /* Sun glare/blind effect */
        float *viewAxis;
        float *sunDirPtr;
        float dot;
        float glareGoal, blindGoal;
        float glareValue, blindValue;
        float glareAlpha, blindAlpha;
        int iFadeInTime, iFadeOutTime;
        int alphaByte, alphaByte2;
        void *viewData;

        frontEnd = r_frontEndDataOut;
        viewData = FIELD(frontEnd, 0x3c8, void *);

        glob = r_glob;
        scene = FIELD(glob, 0x109c, void *);
        sunDirPtr = FIELDP(scene, 0x1b4, float);
        viewAxis = FIELDP(viewData, 0xc, float);

        /* Dot product of sun direction and view forward */
        dot = sunDirPtr[0] * viewAxis[0] + sunDirPtr[1] * viewAxis[1] + sunDirPtr[2] * viewAxis[2];

        /* Blind effect */
        if (FIELD(scene, 0x194, float) <= 0.0f) {
            glareAlpha = 0.0f;
        } else {
            float blindCosBegin = FIELD(scene, 0x18c, float);
            if (dot > blindCosBegin) {
                float blindCosEnd = FIELD(scene, 0x190, float);
                if (dot >= blindCosEnd) {
                    blindGoal = 1.0f;
                } else {
                    blindGoal = (dot - blindCosBegin) / (blindCosEnd - blindCosBegin);
                }
            } else {
                blindGoal = 0.0f;
            }

            blindGoal *= sunFlare->lastVisibility;
            iFadeOutTime = FIELD(scene, 0x19c, int);
            iFadeInTime = FIELD(scene, 0x198, int);

            sunFlare->currentBlind = FadeToGoal(blindGoal, sunFlare->currentBlind, iFadeInTime, iFadeOutTime, frameTime);
            glareAlpha = sunFlare->currentBlind * FIELD(scene, 0x194, float) * 255.0f;
        }

        /* Glare effect */
        if (FIELD(scene, 0x1a8, float) <= 0.0f) {
            blindAlpha = 0.0f;
        } else {
            float glareCosBegin = FIELD(scene, 0x1a0, float);
            if (dot > glareCosBegin) {
                float glareCosEnd = FIELD(scene, 0x1a4, float);
                if (dot >= glareCosEnd) {
                    glareGoal = 1.0f;
                } else {
                    glareGoal = (dot - glareCosBegin) / (glareCosEnd - glareCosBegin);
                }
            } else {
                glareGoal = 0.0f;
            }

            glareGoal *= sunFlare->lastVisibility;
            iFadeOutTime = FIELD(scene, 0x1b0, int);
            iFadeInTime = FIELD(scene, 0x1ac, int);

            sunFlare->currentGlare = FadeToGoal(glareGoal, sunFlare->currentGlare, iFadeInTime, iFadeOutTime, frameTime);
            blindAlpha = sunFlare->currentGlare * FIELD(scene, 0x1a8, float) * 255.0f;
        }

        /* Build color from alpha values */
        {
            D3DCOLOR drawColor;
            alphaByte = (int)glareAlpha;
            alphaByte2 = (int)blindAlpha;
            drawColor = 0;
            ((unsigned char *)&drawColor)[0] = (unsigned char)alphaByte;
            ((unsigned char *)&drawColor)[1] = (unsigned char)alphaByte2;
            ((unsigned char *)&drawColor)[2] = (unsigned char)alphaByte2;
            ((unsigned char *)&drawColor)[3] = (unsigned char)alphaByte2;

            {
                Material *screenEffectMat = FIELD(FIELD(r_glob, 0x109c, void *), 0x1058, Material *);
                RB_DrawFullScreenColoredQuad(screenEffectMat, 0.0f, 0.0f, 1.0f, 1.0f, drawColor);
            }
        }
    }

    RB_EndSurface();
    return 0;
}

/* line 768 */
unsigned char RB_DrawSun(int viewIndex)
{
    SunFlareDynamic *sunFlare;
    float sunVisibility;
    void *frontEnd;
    void *glob;
    void *scene;
    int queryIndex;
    float savedVisibility;

    sunVisibility = 0.0f;

    /* Check if sun is enabled */
    {
        void *dvar = *(void **)r_dvar_sunEnable;
        if (FIELD(dvar, 8, unsigned char) == 0)
            return 0;
    }

    glob = r_glob;
    scene = FIELD(glob, 0x109c, void *);
    if (FIELD(scene, 0x160, unsigned char) == 0)
        return 0;

    frontEnd = r_frontEndDataOut;
    if (FIELD(frontEnd, 0x4bd, unsigned char) != 0) {
        RB_Set3D();
    }

    sunFlare = &sunFlareArray[viewIndex];

    {
        /* Compute query index */
        int numQueries = FIELD(frontEnd, 0x430, int);
        int queryBase = numQueries * 2;
        int frameCount = FIELD(frontEnd, 0x3b0, int);
        int parity = frameCount & 0x80000001;
        if (parity < 0) {
            parity = ((parity - 1) | (int)0xFFFFFFFE) + 1;
        }
        queryIndex = queryBase + parity;

        if (sunFlare->sunQuery[queryIndex] == 0) {
            /* No query available - compute screen coverage */
            float *viewMat;
            void *viewData = FIELD(frontEnd, 0x3c8, void *);
            float *transform0 = FIELDP(viewData, 0xc8, float);
            float *transform1 = FIELDP(viewData, 0xd8, float);
            float *transform2 = FIELDP(viewData, 0xe8, float);

            void *globTmp = r_glob;
            float *sDirPtr = FIELDP(FIELD(globTmp, 0x109c, void *), 0x1b4, float);
            float sx = sDirPtr[0], sy = sDirPtr[1], sz = sDirPtr[2];

            /* Compute clipW = dot(sunDir, column 3 of view matrix) */
            float cW = sx * transform0[3] + sy * transform1[3] + sz * transform2[3];
            savedVisibility = 0.0f;

            if (cW > 0.0f) {
                int vidWidth, vidHeight;
                void *videoConfig = r_videoConfig;
                vidWidth = FIELD(videoConfig, 0, int);
                vidHeight = FIELD(videoConfig, 4, int);

                /* Compute clip X */
                float cX = sx * transform0[0] + sy * transform1[0] + sz * transform2[0];
                cX = (cX / cW + 1.0f) * (float)vidWidth;
                int screenX = (int)floorf((cX - 16.0f) * 0.5f + 0.5f);

                /* Compute clip Y */
                float cY = sx * transform0[1] + sy * transform1[1] + sz * transform2[1];
                cY = (cY / cW + 1.0f) * (float)vidHeight;
                int screenY = (int)floorf((cY - 16.0f) * 0.5f + 0.5f);

                int right = screenX + 16;
                int bottom = screenY + 16;

                /* Clamp to screen */
                if (screenX < 0) screenX = 0;
                if (right > vidWidth) right = vidWidth;
                if (screenY < 0) screenY = 0;
                if (bottom > vidHeight) bottom = vidHeight;

                if (screenX < right && screenY < bottom) {
                    int area = (right - screenX) * (bottom - screenY);
                    savedVisibility = (float)area * 0.00390625f; /* 1/256 */
                }
            }

            sunFlare->lastVisibility = savedVisibility;

            if (savedVisibility == 0.0f) {
                goto after_sun_trace;
            }

            /* Do sun trace */
            {
                float sunTraceEnd[3];
                float *sDirPtr2;
                void *viewData2;
                float *startPos;

                frontEnd = r_frontEndDataOut;
                viewData2 = FIELD(frontEnd, 0x3c8, void *);
                startPos = FIELDP(viewData2, 0, float);
                globTmp = r_glob;
                sDirPtr2 = FIELDP(FIELD(globTmp, 0x109c, void *), 0x1b4, float);

                sunTraceEnd[0] = sDirPtr2[0] * 262144.0f + startPos[0];
                sunTraceEnd[1] = sDirPtr2[1] * 262144.0f + startPos[1];
                sunTraceEnd[2] = sDirPtr2[2] * 262144.0f + startPos[2];

                {
                    unsigned int contentmask = r_contentmask;
                    void *physWorld = r_phys;
                    int hitNum = sunFlare->hitNum;
                    hitNum = (int)(((int (__attribute__((cdecl)) *)(int, void *, float *, unsigned int *, unsigned int *, int, int))FIELDP(physWorld, 0x15c, void *))(hitNum, FIELDP(viewData2, 0, void *), sunTraceEnd, &contentmask, &contentmask, 0, 0x2003));
                    /* Actually: call trace function via vtable */
                    /* void *traceFn = FIELD(physWorld, 0x15c, void *); */
                    sunFlare->hitNum = hitNum;
                }

                if (sunFlare->hitNum != 0) {
                    sunFlare->lastVisibility = 0.0f;
                    savedVisibility = 0.0f;
                } else {
                    savedVisibility = 0.0f;
                }
            }

            goto after_sun_trace;
        }

        /* Have a query - draw the sun sprite for occlusion testing */
        {
            char *tessBuf = (char *)gfx_buf;
            Material *occlusionMat;

            if (FIELD(tessBuf, 0x5a7d0, int) != 0 || FIELD(tessBuf, 0x5a7e0, int) != 0) {
                RB_EndSurface();
            }

            occlusionMat = FIELD(FIELD(r_glob, 0x109c, void *), 0x103c, Material *);

            {
                char *tb = (char *)gfx_buf;
                if (occlusionMat == FIELD(tb, 0x5a7bc, Material *) && FIELD(tb, 0x5a7c0, int) == 3) {
                    /* Already set up */
                } else {
                    if (FIELD(tb, 0x5a7d0, int) != 0 || FIELD(tb, 0x5a7e0, int) != 0) {
                        RB_EndSurface();
                    }
                    RB_BeginSurface(occlusionMat, 3, 0x1f);
                }
            }

            RB_PushMatrixStack();

            /* Sun billboard size based on screen resolution */
            {
                float screenW, screenH;
                frontEnd = r_frontEndDataOut;
                screenW = (float)FIELD(frontEnd, 0x43c, int);
                screenH = (float)FIELD(frontEnd, 0x438, int);
                RB_TessSunBillboard(16.0f / screenW, 16.0f / screenH);
            }

            /* Check if query was previously issued */
            if (sunFlare->sunQueryIssued[queryIndex]) {
                unsigned int drawnSampleCount = 0;
                int getDataResult;
                IDirect3DQuery9 *query;

                /* Wait for query result */
                do {
                    query = sunFlare->sunQuery[queryIndex];
                    {
                        void **qvt = FIELD(query, 0, void **);
                        getDataResult = ((QueryGetDataFn)qvt[0x1c / 4])(query, &drawnSampleCount, 4, 1);
                    }
                    if (getDataResult == 1) {
                        WinSleep(0);
                    }
                } while (getDataResult == 1);

                if (getDataResult != 0) {
                    sunFlare->error = 1;
                }

                {
                    void *devPtr = FIELD(&dx_device_ptr, 0, void *);
                    unsigned int maxSamples = FIELD(devPtr, 0x2c2c, unsigned int);
                    if (maxSamples < drawnSampleCount) {
                        sunFlare->error = 1;
                    }

                    if ((int)drawnSampleCount < 0) {
                        /* Handle unsigned > INT_MAX */
                        unsigned int half = (drawnSampleCount >> 1) | (drawnSampleCount & 1);
                        sunVisibility = (float)(int)half * 2.0f / (float)(int)maxSamples;
                    } else {
                        sunVisibility = (float)(int)drawnSampleCount / (float)(int)maxSamples;
                    }
                }
            } else {
                sunVisibility = 0.0f;
            }

            /* Accumulate visibility */
            {
                int numQueries2;
                frontEnd = r_frontEndDataOut;
                numQueries2 = FIELD(frontEnd, 0x430, int);

                if (numQueries2 == 0) {
                    sunFlare->cumulVisibility = 0.0f;
                }

                sunFlare->cumulVisibility += sunVisibility;

                {
                    int maxQueries = FIELD(frontEnd, 0x434, int) - 1;

                    if (numQueries2 == maxQueries) {
                        /* Last query - finalize visibility */
                        if (sunFlare->cumulVisibility > 1.0f) {
                            sunFlare->cumulVisibility = 1.0f;
                        }

                        if (!sunFlare->error) {
                            sunFlare->lastVisibility = sunFlare->cumulVisibility;
                        }
                        sunFlare->error = 0;
                    }
                }
            }

            /* Issue the query */
            {
                IDirect3DQuery9 *query = sunFlare->sunQuery[queryIndex];
                void **qvt = FIELD(query, 0, void **);
                ((QueryIssueFn)qvt[0x18 / 4])(query, 2);
            }
            RB_EndSurface();

            /* Issue end query */
            {
                IDirect3DQuery9 *query = sunFlare->sunQuery[queryIndex];
                void **qvt = FIELD(query, 0, void **);
                ((QueryIssueFn)qvt[0x18 / 4])(query, 1);
            }
            sunFlare->sunQueryIssued[queryIndex] = 1;
            RB_PopMatrixStack();
            savedVisibility = 0.0f;
        }
    }

after_sun_trace:
    {
        /* Compute sun dot product for later rendering */
        float *viewAxis;
        float *sunDirPtr;
        void *viewData;
        float dot;

        frontEnd = r_frontEndDataOut;
        viewData = FIELD(frontEnd, 0x3c8, void *);
        viewAxis = FIELDP(viewData, 0xc, float);

        glob = r_glob;
        scene = FIELD(glob, 0x109c, void *);
        sunDirPtr = FIELDP(scene, 0x1b4, float);

        dot = sunDirPtr[0] * viewAxis[0] + sunDirPtr[1] * viewAxis[1] + sunDirPtr[2] * viewAxis[2];

        sunFlare->lastDot = dot;

        if (savedVisibility >= dot)
            return 0;

        /* Draw sun corona */
        {
            void *rendererGlob = *(void **)r_rendererGlob;

            if (FIELD(rendererGlob, 8, int) == 2) {
                /* Dx7 path */
                float *sunDir;
                Material *sunMat;

                scene = FIELD(glob, 0x109c, void *);
                sunDir = FIELDP(scene, 0x1b4, float);
                sunMat = FIELD(scene, 0x164, Material *);

                {
                    char *tb = (char *)gfx_buf;
                    if (sunMat == FIELD(tb, 0x5a7bc, Material *) && FIELD(tb, 0x5a7c0, int) == 1) {
                        /* Already set up */
                    } else {
                        if (FIELD(tb, 0x5a7d0, int) != 0 || FIELD(tb, 0x5a7e0, int) != 0) {
                            RB_EndSurface();
                        }
                        RB_BeginSurface(sunMat, 1, 0x1f);
                    }
                }

                {
                    GfxVertexDx7 *vd;
                    float halfSize;
                    float szZ;
                    float cross1[3], cross2[3];
                    vec3_t up;
                    float dxp1[3], dxp2[3], dxm1[3], dxm2[3];

                    vd = RB_SetTessQuadDx7(*(GfxColor *)&(D3DCOLOR){0xffffffff});

                    halfSize = 0.0013110929867252707f;
                    halfSize *= FIELD(FIELD(r_glob, 0x109c, void *), 0x16c, float);

                    szZ = sunDir[2];
                    if (szZ * szZ > 0.99f) {
                        /* Sun nearly vertical - use alternative up vector */
                        up[0] = -sunDir[0]; /* negate x */
                        up[1] = sunDir[1];
                        up[2] = 0.0f;
                    } else {
                        up[0] = 1.0f;
                        up[1] = 0.0f;
                        up[2] = 0.0f;
                    }

                    Vec3Cross(sunDir, up, cross1);
                    Vec3Normalize(cross1);

                    cross1[0] *= halfSize;
                    cross1[1] *= halfSize;
                    cross1[2] *= halfSize;

                    Vec3Cross(cross1, sunDir, cross2);

                    /* Compute 4 corner offsets */
                    dxp1[0] = cross1[0] + cross2[0];
                    dxp1[1] = cross1[1] + cross2[1];
                    dxp1[2] = cross1[2] + cross2[2];

                    dxm1[0] = cross1[0] - cross2[0];
                    dxm1[1] = cross1[1] - cross2[1];
                    dxm1[2] = cross1[2] - cross2[2];

                    /* Set vertex positions */
                    vd[0].xyz[0] = sunDir[0] + dxp1[0];
                    vd[0].xyz[1] = sunDir[1] + dxp1[1];
                    vd[0].xyz[2] = sunDir[2] + dxp1[2];

                    vd[1].xyz[0] = sunDir[0] + dxm1[0];
                    vd[1].xyz[1] = sunDir[1] + dxm1[1];
                    vd[1].xyz[2] = sunDir[2] + dxm1[2];

                    vd[2].xyz[0] = sunDir[0] - dxp1[0];
                    vd[2].xyz[1] = sunDir[1] - dxp1[1];
                    vd[2].xyz[2] = sunDir[2] - dxp1[2];

                    vd[3].xyz[0] = sunDir[0] - dxm1[0];
                    vd[3].xyz[1] = sunDir[1] - dxm1[1];
                    vd[3].xyz[2] = sunDir[2] - dxm1[2];

                    RB_SetViewMatrixForWDx7(0.0f);
                    RB_EndSurface();
                    RB_SetViewMatrixForWDx7(1.0f);
                }
            } else {
                /* D3D9 path */
                float *sunDir;
                Material *sunMat;

                scene = FIELD(glob, 0x109c, void *);
                sunDir = FIELDP(scene, 0x1b4, float);
                sunMat = FIELD(scene, 0x164, Material *);

                {
                    char *tb = (char *)gfx_buf;
                    if (sunMat == FIELD(tb, 0x5a7bc, Material *) && FIELD(tb, 0x5a7c0, int) == 1) {
                        /* Already set up */
                    } else {
                        if (FIELD(tb, 0x5a7d0, int) != 0 || FIELD(tb, 0x5a7e0, int) != 0) {
                            RB_EndSurface();
                        }
                        RB_BeginSurface(sunMat, 1, 0x1f);
                    }
                }

                {
                    GfxVertex *v;
                    float halfSize;
                    float szZ;
                    float cross1[3], cross2[3];
                    vec3_t up;
                    float dxp1[3], dxp2[3], dxm1[3], dxm2[3];

                    v = RB_SetTessQuad(*(GfxColor *)&(D3DCOLOR){0xffffffff});

                    halfSize = 0.0013110929867252707f;
                    halfSize *= FIELD(FIELD(r_glob, 0x109c, void *), 0x16c, float);

                    szZ = sunDir[2];
                    if (szZ * szZ > 0.99f) {
                        up[0] = -sunDir[0];
                        up[1] = sunDir[1];
                        up[2] = 0.0f;
                    } else {
                        up[0] = 1.0f;
                        up[1] = 0.0f;
                        up[2] = 0.0f;
                    }

                    Vec3Cross(sunDir, up, cross1);
                    Vec3Normalize(cross1);

                    cross1[0] *= halfSize;
                    cross1[1] *= halfSize;
                    cross1[2] *= halfSize;

                    Vec3Cross(cross1, sunDir, cross2);

                    dxp1[0] = cross1[0] + cross2[0];
                    dxp1[1] = cross1[1] + cross2[1];
                    dxp1[2] = cross1[2] + cross2[2];

                    dxm1[0] = cross1[0] - cross2[0];
                    dxm1[1] = cross1[1] - cross2[1];
                    dxm1[2] = cross1[2] - cross2[2];

                    v[0].xyzw[0] = sunDir[0] + dxp1[0];
                    v[0].xyzw[1] = sunDir[1] + dxp1[1];
                    v[0].xyzw[2] = sunDir[2] + dxp1[2];

                    v[1].xyzw[0] = sunDir[0] + dxm1[0];
                    v[1].xyzw[1] = sunDir[1] + dxm1[1];
                    v[1].xyzw[2] = sunDir[2] + dxm1[2];

                    v[2].xyzw[0] = sunDir[0] - dxp1[0];
                    v[2].xyzw[1] = sunDir[1] - dxp1[1];
                    v[2].xyzw[2] = sunDir[2] - dxp1[2];

                    v[3].xyzw[0] = sunDir[0] - dxm1[0];
                    v[3].xyzw[1] = sunDir[1] - dxm1[1];
                    v[3].xyzw[2] = sunDir[2] - dxm1[2];

                    v[0].xyzw[3] = 0.0f;
                    v[1].xyzw[3] = 0.0f;
                    v[2].xyzw[3] = 0.0f;
                    v[3].xyzw[3] = 0.0f;

                    RB_EndSurface();
                }
            }
        }
    }

    return 0;
}
