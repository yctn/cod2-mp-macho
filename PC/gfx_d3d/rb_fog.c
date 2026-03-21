/* Converted to C from ASM: rb_fog.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_fog.cpp */

#include "common_types.h"
#include "imports.h"

extern void **g_renderState; /* imp_r_fog */
extern void **g_viewParms;   /* imp_backEndData */
extern r_globals_t rg;      /* imp_rg */
extern r_backEndGlobals_t backEnd; /* imp_backEnd */
extern DxState *dxState;     /* imp_dxState */
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
    GfxFog *fog = (GfxFog *)(viewParms + 0x219cec);
    return fog->techniqueOffset;
}

int RB_UpdateFogColor(FogColorSrcEnum fogColorSrc)
{
    int fogIndex = rg.fogIndex;

    if (fogIndex == 0)
        return 0;

    unsigned int fogColor;

    if (fogColorSrc != 0) {
        if (fogColorSrc == 2) {
            fogColor = 0;
        } else {
            fogColor = backEnd.fogColor.packed;
        }

        fogColor |= 0xff000000;

        if (dxState->fog.color.packed == fogColor)
            return 0;

        /* Set fog color via D3D device */
        do {
            void *device = ((DxGlobals *)imp_dx)->device;
            void **vtable = *(void ***)device;
            typedef int (*SetRenderStateFn)(void *, int, unsigned int);
            ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x22, fogColor);
        } while (*(volatile int *)imp_alwaysfails != 0);

        dxState->fog.color.packed = fogColor;
    } else {
        int renderMode = dxState->refStateBits[0] & 0xf0;
        if (renderMode == 0x20) {
            fogColor = 0;
        } else {
            fogColor = backEnd.fogColor.packed;
        }

        fogColor |= 0xff000000;

        if (dxState->fog.color.packed == fogColor)
            return 0;

        do {
            void *device = ((DxGlobals *)imp_dx)->device;
            void **vtable = *(void ***)device;
            typedef int (*SetRenderStateFn)(void *, int, unsigned int);
            ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x22, fogColor);
        } while (*(volatile int *)imp_alwaysfails != 0);

        dxState->fog.color.packed = fogColor;
    }

    return 0;
}

int RB_SetIteratorFog(void)
{
    materialCommands_t *tess = *(materialCommands_t **)g_drawSurf;
    if (tess->techType == 3)
        return 0;

    byte *viewParms = *(byte **)g_viewParms;
    GfxFog *fog = (GfxFog *)(viewParms + 0x219cec);

    if (fog->techniqueOffset == 0)
        return 0;

    if (!fog->registered)
        return 0;

    /* Set backend fog color */
    unsigned int fogColorPacked = fog->color.packed;
    backEnd.fogColor.packed = fogColorPacked;

    /* Inline RB_UpdateFogColor logic */
    int fogIndex = rg.fogIndex;
    if (fogIndex != 0) {
        int renderMode = dxState->refStateBits[0] & 0xf0;
        unsigned int fogColor;
        if (renderMode == 0x20) {
            fogColor = 0;
        } else {
            fogColor = fogColorPacked;
        }
        fogColor |= 0xff000000;

        if (dxState->fog.color.packed != fogColor) {
            do {
                void *device = ((DxGlobals *)imp_dx)->device;
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, unsigned int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x22, fogColor);
            } while (*(volatile int *)imp_alwaysfails != 0);

            dxState->fog.color.packed = fogColor;
        }
    }

    /* Convert fog color bytes to floats (1/255 scale) */
    float inv255 = 0.003921568859368563f;
    float fr = (float)fog->color.array[1] * inv255;
    float fg = (float)fog->color.array[0] * inv255;
    float fa = (float)fog->color.array[3] * inv255;
    float fb = (float)fog->color.array[2] * inv255;

    /* Store fog color as vec4 at backEnd.codeConsts[29] */
    backEnd.codeConsts[29][0] = fb;
    backEnd.codeConsts[29][1] = fr;
    backEnd.codeConsts[29][2] = fg;
    backEnd.codeConsts[29][3] = fa;

    /* Compute fog parameters */
    float *viewInfo = *(float **)g_viewInfo;
    float fogEnd = viewInfo[2]; /* TODO: unknown struct - offset 8 */
    if (fogEnd == 0.0f) {
        fogEnd = fog->fogEnd;
    }
    float fogStart = fog->fogStart;
    float fogRange = fogEnd - fogStart;
    float invRange = 1.0f / fogRange;
    float density = fog->density;
    float negDensity = -density;

    /* Store fog distance params as vec4 at backEnd.codeConsts[28] */
    backEnd.codeConsts[28][0] = -invRange;
    backEnd.codeConsts[28][1] = invRange * fogEnd;
    backEnd.codeConsts[28][2] = negDensity;
    backEnd.codeConsts[28][3] = 0.0f;

    /* Check D3D caps for fog mode */
    int *dxCaps = *(int **)imp_r_rendererInUse;
    if (dxCaps[2] != 2) /* TODO: unknown struct - offset 8 */
        return 0;

    /* Set D3D fog render states based on fog type */
    if (fog->techniqueOffset == 1) {
        /* Exponential fog */
        if (dxState->fog.mode != 3) {
            do {
                void *device = ((DxGlobals *)imp_dx)->device;
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x8c, 3);
            } while (*(volatile int *)imp_alwaysfails != 0);
            dxState->fog.mode = 3;
        }

        /* Set fog start */
        if (dxState->fog.start != fogStart) {
            do {
                void *device = ((DxGlobals *)imp_dx)->device;
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x24, *(int *)&fog->fogStart);
            } while (*(volatile int *)imp_alwaysfails != 0);
            dxState->fog.start = fogStart;
        }

        /* Set fog end */
        if (dxState->fog.end != fogEnd) {
            do {
                void *device = ((DxGlobals *)imp_dx)->device;
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x25, *(int *)&fogEnd);
            } while (*(volatile int *)imp_alwaysfails != 0);
            dxState->fog.end = fogEnd;
        }
    } else {
        /* Linear fog */
        if (dxState->fog.mode != 1) {
            do {
                void *device = ((DxGlobals *)imp_dx)->device;
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x8c, 1);
            } while (*(volatile int *)imp_alwaysfails != 0);
            dxState->fog.mode = 1;
        }

        /* Set fog density */
        if (dxState->fog.density != density) {
            do {
                void *device = ((DxGlobals *)imp_dx)->device;
                void **vtable = *(void ***)device;
                typedef int (*SetRenderStateFn)(void *, int, int);
                ((SetRenderStateFn)vtable[0xe4 / 4])(device, 0x26, *(int *)&fog->density);
            } while (*(volatile int *)imp_alwaysfails != 0);
            dxState->fog.density = density;
        }
    }

    return 0;
}
