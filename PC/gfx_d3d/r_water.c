/* Decompiled from: r_water.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_water.cpp */

#include "common_types.h"
#include "imports.h"

extern float floorf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

static struct WaterGlob waterGlob; /* waterGlob */

/* Extern globals */
extern void **g_viewParms;          /* imp_backEndData */
/* g_dxCaps was imp_r_rendererInUse */
extern r_globals_t rg;             /* imp_rg */
extern r_backEndGlobals_t *backEnd; /* imp_backEnd */
extern void **g_unknown_195f22c;    /* imp_g_WarmOff - upload lock flag */
extern void **g_unknown_195f230;    /* imp_r_drawWater - water enabled check */

/* Extern functions */
extern void Image_UploadData(GfxImage *image, D3DFORMAT format, int face, int mipLevel, const byte *src);
extern void R_DownsampleMipMapBilinear(const byte *src, int srcBufferSize, int srcWidth, int srcHeight, int texelPitch, byte *dst, int dstBufferSize);
extern void FFT(complex_t *data, long unsigned int log2_count, long unsigned int stride, int *bitSwap, complex_t *trigTable);
extern float MacOpenGLUtils_SquareRootLowPrecision(float fp0);

void RB_UploadWaterTexture(GfxImage *image, water_t *water);

/* line 383 */
void RB_UploadWaterTexture(GfxImage *image, water_t *water)
{
    int currentFrame;
    float t;
    int N, M;
    int n, m, vecKIndex;
    complex_t *waterData;
    complex_t *H0;
    float *wTerm;
    int log2_n, log2_m;
    int totalSize;
    float dz_float;
    float dz_sqrd;
    int xymask, ymask;
    int ixm1y;
    byte *pixels;
    byte *uploadFlag;

    /* Treat waterGlob as an array of complex_t for FFT data */
    waterData = (complex_t *)&waterGlob;

    /* line 388: Check if water is already up to date for this frame */
    currentFrame = **(int **)g_viewParms;
    if (water->writable.frameCount == currentFrame) {
        return;
    }

    /* line 390: Update frame count */
    water->writable.frameCount = currentFrame;

    /* line 392: Check if water processing is enabled */
    {
        byte *ptr = *(byte **)g_unknown_195f230;
        if (*(byte *)(ptr + 8) == 0) {
            return;
        }
    }

    /* line 398: Get current time */
    t = backEnd->sceneDef.floatTime;

    N = water->N;
    M = water->M;

    /* line 133: Compute H(k,t) from H0 and wTerm */
    /* Iterate over wave vectors (n, m) from -N/2 to N/2-1, -M/2 to M/2-1 */
    vecKIndex = 0;
    for (n = -N / 2; n < N / 2; n++) {
        for (m = -M / 2; m < M / 2; m++) {
            float w = water->wTerm[vecKIndex];

            /* line 141: Check if wTerm is zero */
            if (w == 0.0f) {
                /* line 143-144: Set waterGlob entry to zero */
                waterData[vecKIndex].real = 0.0f;
                waterData[vecKIndex].imag = 0.0f;
            } else {
                /* line 428: Compute phase from wTerm * t */
                int phase;
                int cosPhase;
                float phaseFloat;

                phaseFloat = (float)((double)(w * t) * 162.97466172610083);
                phase = (int)floorf(phaseFloat + 0.5f) & 0x3ff;

                /* line 150: Modulate H0 by trig table */
                cosPhase = (phase + 255) & 0x3ff;
                waterData[vecKIndex].real = water->H0[vecKIndex].real * rg.sinTable[cosPhase];

                /* line 151 */
                waterData[vecKIndex].imag = water->H0[vecKIndex].imag * rg.sinTable[phase];
            }

            vecKIndex++;
            M = water->M; /* reload M since compiler used it as loop bound */
        }
    }

    /* line 174: Compute log2 of N */
    if (N == 1) {
        log2_n = 0;
    } else {
        log2_n = 0;
        do {
            log2_n++;
        } while ((1 << log2_n) != N);
    }

    /* line 177: Compute log2 of M */
    M = water->M;
    if (M == 1) {
        log2_m = 0;
    } else {
        log2_m = 0;
        do {
            log2_m++;
        } while ((1 << log2_m) != M);
    }

    /* line 181: Perform FFT on rows */
    if (N > 0) {
        int waterIndex;
        for (waterIndex = 0; waterIndex < water->N; waterIndex++) {
            FFT(&waterData[waterIndex * water->M], log2_m, 1,
                rg.fftBitswap, rg.fftTrigTable);
        }
        M = water->M;
    }

    /* line 190: Perform FFT on columns */
    if (M > 0) {
        int fftIndex;
        complex_t *ptr = waterData;
        for (fftIndex = 0; fftIndex < water->M; fftIndex++) {
            FFT(ptr, log2_n, water->M,
                rg.fftBitswap, rg.fftTrigTable);
            ptr++;
        }
    }

    /* line 406: Check if DX caps indicate normalmap generation */
    {
        int *capsPtr = *(int **)imp_r_rendererInUse;
        if (capsPtr[2] == 2) {
            goto normalmap_path;
        }
    }

    /* Heightmap path (line 349) */
    {
        float dz;
        totalSize = water->M * water->N;
        dz = (float)totalSize;

        /* line 350: Generate heightmap pixels */
        if (totalSize > 0) {
            int i;
            byte *dst = waterGlob.pixels;
            complex_t *src = waterData;

            for (i = 0; i < water->N * water->M; i++) {
                float real = src->real;
                float imag = src->imag;
                float mag = real * real + imag * imag;
                float sqrtMag;
                float val;

                sqrtMag = __builtin_sqrtf(mag);
                val = sqrtMag / dz;

                /* line 45: Clamp to [0, 255] */
                if (val - 1.0f >= 0.0f) {
                    val = 255.0f;
                } else {
                    val = val * 255.0f;
                }

                *dst = (byte)(int)floorf(val + 0.5f);
                dst++;
                src++;
            }
        }

        goto upload_heightmap;
    }

normalmap_path:
    /* line 216: Normal map generation */
    {
        int totalPixels;
        float dz_val;
        float dz_sqrd_val;

        totalPixels = water->M * water->N;
        dz_val = (float)totalPixels;
        dz_sqrd_val = dz_val * dz_val;

        /* line 227: Compute magnitudes into waterGlob real components */
        if (totalPixels > 0) {
            int i;
            complex_t *ptr = waterData;
            for (i = 0; i < totalPixels; i++) {
                float real = ptr->real;
                float imag = ptr->imag;
                float mag = real * real + imag * imag;
                ptr->real = MacOpenGLUtils_SquareRootLowPrecision(mag);
                ptr++;
            }
        }
        M = water->M;

        /* line 233: Setup normalmap generation masks */
        xymask = totalPixels - 1;
        ymask = M - 1;

        /* line 242: Generate normalmap pixels */
        if (water->N > 0) {
            int y;
            int ixy_base;
            int ixm1y_base;

            pixels = waterGlob.pixels;
            ixm1y = 0;
            ixy_base = totalPixels - M;

            for (y = 0; y < water->N; y++) {
                M = water->M;

                if (M > 0) {
                    int x;
                    int ixm1y_idx = ixm1y;
                    int ixy_idx = ixy_base;
                    int prevYm1 = ymask;

                    for (x = 0; x < water->M; x++) {
                        /* line 262: h_ixy = waterGlob[ixm1y_idx].real */
                        float h_ixm1y = waterData[ixm1y_idx].real;

                        /* line 265: dx = h_ixm1y - waterGlob[prevYm1].real */
                        float dx = h_ixm1y - waterData[prevYm1].real;

                        /* line 266: dy = h_ixm1y - waterGlob[ixy_idx].real */
                        float dy = h_ixm1y - waterData[ixy_idx].real;

                        /* line 269: Compute normal length */
                        float lenSq = dx * dx + dy * dy + dz_sqrd_val;
                        float len = MacOpenGLUtils_SquareRootLowPrecision(lenSq);
                        float invLen = 127.5f / len;

                        /* Encode normal into pixel bytes */
                        /* Pixel format: [alpha, nx, ny, nz] */
                        pixels[0] = 0xff;                                          /* line 274 */
                        pixels[1] = (byte)(int)floorf(dx * invLen + 127.5f + 0.5f);
                        pixels[2] = (byte)(int)floorf(dy * invLen + 127.5f + 0.5f);
                        pixels[3] = (byte)(int)floorf(dz_val * invLen + 127.5f + 0.5f);

                        /* line 326: Advance pixel pointer */
                        pixels += 4;

                        /* line 330: Advance indices */
                        prevYm1 = ixm1y_idx;
                        ixm1y++;
                        ixm1y_idx = ixm1y;
                        ixy_idx += 1;
                        M = water->M;
                    }
                }

                /* line 333: Advance ixy_base for next row */
                ixy_base = (totalPixels - M + ixm1y) & xymask;
            }
        }

        /* line 413: Upload normalmap */
        uploadFlag = *(byte **)g_unknown_195f22c;
        *uploadFlag = 1;
        Image_UploadData(image, D3DFMT_A8R8G8B8, 0, 0, waterGlob.pixels);
        *uploadFlag = 0;
        return;
    }

upload_heightmap:
    /* line 429: Upload heightmap as base mip */
    {
        int srcWidth, srcHeight, mipIndex;
        byte *uploadFlagPtr;

        uploadFlagPtr = *(byte **)g_unknown_195f22c;
        *uploadFlagPtr = 1;

        /* line 431: Upload base mip level */
        Image_UploadData(image, D3DFMT_L8, 0, 0, waterGlob.pixels);

        /* line 369: Generate and upload mip chain */
        srcWidth = water->M;
        srcHeight = water->N;
        mipIndex = 1;

        while (srcWidth > 1 || srcHeight > 1) {
            /* line 374: Downsample */
            R_DownsampleMipMapBilinear(waterGlob.pixels, 0x4000, srcWidth, srcHeight, 1,
                                       waterGlob.pixels, 0x4000);
            /* line 375: Upload mip level */
            Image_UploadData(image, D3DFMT_L8, 0, mipIndex, waterGlob.pixels);

            /* line 377-378: Halve dimensions, minimum 1 */
            srcWidth >>= 1;
            if (srcWidth < 1) srcWidth = 1;
            srcHeight >>= 1;
            if (srcHeight < 1) srcHeight = 1;

            mipIndex++;
        }

        /* line 437: Release upload lock */
        *uploadFlagPtr = 0;
    }
}
