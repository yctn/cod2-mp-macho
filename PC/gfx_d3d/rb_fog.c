/* Converted to C from ASM: rb_fog.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_fog.cpp */

#include "common_types.h"
#include "imports.h"

extern void **g_renderState; /* imp_r_fog */
extern void **g_viewParms;   /* imp_backEndData */
extern r_globals_t rg;      /* imp_rg */
extern r_backEndGlobals_t backEnd; /* imp_backEnd */
extern void **g_backEndData; /* imp_dxState */
/* g_dx was imp_dx, g_dxIter was imp_alwaysfails, g_dxCaps was imp_r_rendererInUse */
extern void **g_drawSurf;    /* imp_tess */
extern void **g_viewInfo;    /* imp_r_zfar */

GfxFogOffset RB_FogOffset(void)
{
    byte *state = *(byte **)g_renderState;
    if (state[8] != 0) {
        return 0;
    }

    byte *viewParms = *(byte **)g_viewParms;
    return *(GfxFogOffset *)(viewParms + 0x219cec);
}

int RB_UpdateFogColor(FogColorSrcEnum fogColorSrc)
{
    byte *backEndPtr = (byte *)&backEnd;
    byte *rgPtr = (byte *)&rg;
    int fogIndex = *(int *)(rgPtr + 0x150c);

    if (fogIndex == 0)
        return 0;

    unsigned int fogColor;

    if (fogColorSrc != 0) {
        byte *backEndData = *(byte **)g_backEndData;
        if (fogColorSrc == 2) {
            fogColor = 0;
        } else {
            fogColor = *(unsigned int *)(backEndPtr + 0x4c8);
        }

        fogColor |= 0xff000000;

        if (*(unsigned int *)(backEndData + 0x2158) == fogColor)
            return 0;

        /* Set fog color via D3D device */
        byte *dxPtr = (byte *)imp_dx;
        do {
            void *device = *(void **)(dxPtr + 8);
            void **vtable = *(void ***)device;
            typedef int (*SetRenderStateFn)(void *, int, unsigned int);
            ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x22, fogColor);
        } while (*(volatile int *)imp_alwaysfails != 0);

        byte *bd = *(byte **)g_backEndData;
        *(unsigned int *)(bd + 0x2158) = fogColor;
    } else {
        byte *backEndData = *(byte **)g_backEndData;
        int renderMode = *(int *)(backEndData + 0x2000) & 0xf0;
        if (renderMode == 0x20) {
            fogColor = 0;
        } else {
            fogColor = *(unsigned int *)(backEndPtr + 0x4c8);
        }

        fogColor |= 0xff000000;

        if (*(unsigned int *)(backEndData + 0x2158) == fogColor)
            return 0;

        byte *dxPtr = (byte *)imp_dx;
        do {
            void *device = *(void **)(dxPtr + 8);
            void **vtable = *(void ***)device;
            typedef int (*SetRenderStateFn)(void *, int, unsigned int);
            ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x22, fogColor);
        } while (*(volatile int *)imp_alwaysfails != 0);

        byte *bd = *(byte **)g_backEndData;
        *(unsigned int *)(bd + 0x2158) = fogColor;
    }

    return 0;
}

int RB_SetIteratorFog(void)
{
    byte *drawSurf = *(byte **)g_drawSurf;
    if (*(int *)(drawSurf + 0x5a7c0) == 3)
        return 0;

    byte *viewParms = *(byte **)g_viewParms;
    byte *fog = viewParms + 0x219cec;
    int fogOffset = *(int *)fog;

    if (fogOffset == 0)
        return 0;

    if (fog[0x1c] == 0)
        return 0;

    /* Set backend fog color */
    unsigned int fogColorPacked = *(unsigned int *)(fog + 0xc);
    *(unsigned int *)((byte *)&backEnd + 0x4c8) = fogColorPacked;

    /* Inline RB_UpdateFogColor logic */
    byte *rgPtr = (byte *)&rg;
    int fogIndex = *(int *)(rgPtr + 0x150c);
    if (fogIndex != 0) {
        byte *backEndData = *(byte **)g_backEndData;
        int renderMode = *(int *)(backEndData + 0x2000) & 0xf0;
        unsigned int fogColor;
        if (renderMode == 0x20) {
            fogColor = 0;
        } else {
            fogColor = fogColorPacked;
        }
        fogColor |= 0xff000000;

        if (*(unsigned int *)(backEndData + 0x2158) != fogColor) {
            byte *dxPtr = (byte *)imp_dx;
            do {
                void *device = *(void **)(dxPtr + 8);
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, unsigned int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x22, fogColor);
            } while (*(volatile int *)imp_alwaysfails != 0);

            backEndData = *(byte **)g_backEndData;
            *(unsigned int *)(backEndData + 0x2158) = fogColor;
        }
    }

    byte *ecx = (byte *)&backEnd;

    /* Convert fog color bytes to floats (1/255 scale) */
    float inv255 = 0.003921568859368563f;
    float fr = (float)(unsigned char)fog[0xd] * inv255;
    float fg = (float)(unsigned char)fog[0xc] * inv255;
    float fa = (float)(unsigned char)fog[0xf] * inv255;
    float fb = (float)(unsigned char)fog[0xe] * inv255;

    /* Store fog color as vec4 at backEnd + 0x1d0 */
    *(float *)(ecx + 0x1d0) = fb;
    *(float *)(ecx + 0x1d4) = fr;
    *(float *)(ecx + 0x1d8) = fg;
    *(float *)(ecx + 0x1dc) = fa;

    /* Compute fog parameters */
    byte *viewInfo = *(byte **)g_viewInfo;
    float fogEnd = *(float *)(viewInfo + 8);
    if (fogEnd == 0.0f) {
        fogEnd = *(float *)(fog + 0x14);
    }
    float fogStart = *(float *)(fog + 0x10);
    float fogRange = fogEnd - fogStart;
    float invRange = 1.0f / fogRange;
    float density = *(float *)(fog + 0x18);
    float negDensity = -density;

    /* Store fog distance params as vec4 at backEnd + 0x1c0 */
    *(float *)(ecx + 0x1c0) = -invRange;
    *(float *)(ecx + 0x1c4) = invRange * fogEnd;
    *(float *)(ecx + 0x1c8) = negDensity;
    *(float *)(ecx + 0x1cc) = 0.0f;

    /* Check D3D caps for fog mode */
    byte *dxCaps = *(byte **)imp_r_rendererInUse;
    if (*(int *)(dxCaps + 8) != 2)
        return 0;

    /* Set D3D fog render states based on fog type */
    int fogType = *(int *)fog;
    if (fogType == 1) {
        /* Exponential fog */
        byte *bd = *(byte **)g_backEndData;
        if (*(int *)(bd + 0x215c) != 3) {
            byte *dxPtr = (byte *)imp_dx;
            do {
                void *device = *(void **)(dxPtr + 8);
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x8c, 3);
            } while (*(volatile int *)imp_alwaysfails != 0);
            bd = *(byte **)g_backEndData;
            *(int *)(bd + 0x215c) = 3;
        }

        /* Set fog start */
        if (*(float *)(bd + 0x2160) != fogStart) {
            byte *dxPtr = (byte *)imp_dx;
            do {
                void *device = *(void **)(dxPtr + 8);
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x24, *(int *)(fog + 0x10));
            } while (*(volatile int *)imp_alwaysfails != 0);
            bd = *(byte **)g_backEndData;
            *(float *)(bd + 0x2160) = fogStart;
        }

        /* Set fog end */
        if (*(float *)(bd + 0x2164) != fogEnd) {
            byte *dxPtr = (byte *)imp_dx;
            do {
                void *device = *(void **)(dxPtr + 8);
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x25, *(int *)&fogEnd);
            } while (*(volatile int *)imp_alwaysfails != 0);
            bd = *(byte **)g_backEndData;
            *(float *)(bd + 0x2164) = fogEnd;
        }
    } else {
        /* Linear fog */
        byte *bd = *(byte **)g_backEndData;
        if (*(int *)(bd + 0x215c) != 1) {
            byte *dxPtr = (byte *)imp_dx;
            do {
                void *device = *(void **)(dxPtr + 8);
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x8c, 1);
            } while (*(volatile int *)imp_alwaysfails != 0);
            bd = *(byte **)g_backEndData;
            *(int *)(bd + 0x215c) = 1;
        }

        /* Set fog density */
        if (*(float *)(bd + 0x2168) != density) {
            byte *dxPtr = (byte *)imp_dx;
            do {
                void *device = *(void **)(dxPtr + 8);
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x26, *(int *)(fog + 0x18));
            } while (*(volatile int *)imp_alwaysfails != 0);
            bd = *(byte **)g_backEndData;
            *(float *)(bd + 0x2168) = density;
        }
    }

    return 0;
}
