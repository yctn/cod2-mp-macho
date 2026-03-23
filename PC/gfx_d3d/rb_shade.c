/* ASM dump from: rb_shade.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_shade.cpp */

#include "common_types.h"
#include <math.h>
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_local.h"
 *   #include "PC/gfx_d3d/rb_state.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/rb_shade.h"
 */

extern const float lightGridLookupMatrix[4][4]; /* rodata.c */
extern const vec4_t debugShaderConsts[]; /* rodata.c */
extern const GfxStateOverride overrideEnableRenormalize; /* rodata.c */
extern refimport_t ri; /* imp_ri */
extern const DWORD s_fvfForVertDeclType[]; /* rodata.c */

extern void R_FatalLockError(HRESULT hr);
extern void R_Error(int level, const char *msg, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Memcpy(void *dest, const void *src, int count);
extern void RB_ChangeIndices(IDirect3DIndexBuffer9 *ib);
extern void RB_ChangeStreamSource(int streamIndex, IDirect3DVertexBuffer9 *vb, int vertexOffset, int vertexStride);
extern void *CColorConverter_GetColorConverter(int mode);
extern void MatrixInverse44(const void *src, void *dst);
extern void MatrixTranspose44(const void *src, void *dst);
extern void MatrixMultiply44(const void *a, const void *b, void *out);
extern void MatrixTransformVector44(const void *vec, const void *mat, void *out);
extern Bool RB_GetViewport(void *viewport);
extern void MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL(void *proj, float width, float height);
extern void RB_UpdateViewport(void);
extern int RB_SetIteratorFog(void);
extern int RB_DeriveEntityLights(vec4_t *colorForDir, float sunVisibility, const Material *material, D3DLIGHT9 *lights, int maxLights);
extern void RB_SetupEntityLighting(const GfxEntity *ent, GfxEntityLighting *lighting);
extern void RB_SetCodeConstant(int constant, vec_t x, vec_t y, vec_t z, vec_t w);

static inline char *RB_TessBase(void)
{
    return (char *)imp_tess;
}

void RB_BeginSurface(const Material *material, MaterialTechniqueType techType, int lmapIndex);
int RB_SetIndexData(const r_index_t *indices, int indexCount);
static void RB_GetTextureFromCode_impl(int codeTexture, void **image, byte *samplerState);
static void RB_SetEntityHwLightsDx7_impl(vec4_t *colorForDir, float sunVisibility);
void RB_CreateDynamicBuffers(void);
static void RB_SetupLighting_impl(void);
static void RB_SetupLighting(void);
void RB_SetVertexData(unsigned int streamIndex, const void *data, int vertexCount, int stride);
static const float * RB_GetCodeMatrix(int source, int firstRow);
static void RB_DrawSingleTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args, const GfxStateOverride *stateOverride);
void RB_DrawTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args);
void RB_EndSurface(void);

/* line 1587 */
extern int g_tess_since_begin;
int g_begin_surface_calls = 0;
void RB_BeginSurface(const Material *material, MaterialTechniqueType techType, int lmapIndex)
{
    char *tess = RB_TessBase();
    g_begin_surface_calls++;
    g_tess_since_begin = 0;
    ((materialCommands_t *)tess)->declType = 0;
    ((materialCommands_t *)tess)->optimizedVertexSource = 0;
    ((materialCommands_t *)tess)->indexCount = 0;
    ((materialCommands_t *)tess)->vertexCount = 0;
    ((materialCommands_t *)tess)->firstVertex = 0;
    ((materialCommands_t *)tess)->lastVertex = 0;
    ((materialCommands_t *)tess)->material = material;
    ((materialCommands_t *)tess)->techType = techType;
    ((materialCommands_t *)tess)->lmapIndex = lmapIndex;
}

/* line 132 */
int RB_SetIndexData(const r_index_t *indices, int indexCount)
{
    char *dx = (char *)imp_dx;
    int indexDataSize = indexCount * 2;  /* r_index_t = 2 bytes */
    char **pLockSlot = (char **)(dx + 0x2d8c); /* TODO: DxGlobals.indexLockSlot */
    char *lockState = *pLockSlot;
    int overflow;
    int byteOffset;
    int baseIndex;
    IDirect3DIndexBuffer9 *ib;
    DWORD lockFlags;
    void *bufferData;
    HRESULT hr;

    if (!lockState)
        return 0;

    /* Check if new data fits; overflow means we need to wrap to beginning */
    overflow = (*(int *)lockState + indexDataSize) > *(int *)(lockState + 4);
    if (overflow)
        *(int *)lockState = 0;

    /* If offset is at beginning, switch to the primary (non-overflow) lock slot */
    if (*(int *)lockState == 0) {
        lockState = dx + 0x2d80;
        *pLockSlot = lockState;
    }

    byteOffset = *(int *)lockState;
    baseIndex = byteOffset >> 1;  /* byte offset -> index number */
    ib = *(IDirect3DIndexBuffer9 **)(lockState + 8);

    /* D3DLOCK_NOOVERWRITE (0) when safe to append; D3DLOCK_DISCARD (0x2000) to reset */
    if (!overflow && (((DxGlobals *)dx)->gpuSync != 0 || byteOffset != 0))
        lockFlags = 0;       /* D3DLOCK_NOOVERWRITE */
    else
        lockFlags = 0x2000;  /* D3DLOCK_DISCARD */

    /* Lock the index buffer via COM vtable slot 11 = IDirect3DIndexBuffer9::Lock */
    hr = ((HRESULT (*)(IDirect3DIndexBuffer9*, UINT, UINT, void**, DWORD))
          (*(void***)(ib))[11])(ib, (UINT)byteOffset, (UINT)indexDataSize, &bufferData, lockFlags);
    if (hr < 0)
        R_FatalLockError(hr);

    Com_Memcpy(bufferData, indices, indexDataSize);

    /* Unlock via COM vtable slot 12 = IDirect3DIndexBuffer9::Unlock */
    do {
        ((HRESULT (*)(IDirect3DIndexBuffer9*))(*(void***)(ib))[12])(ib);
    } while (*(int *)imp_alwaysfails);

    if (ib != ((DxState *)imp_dxState)->indexBuffer)
        RB_ChangeIndices(ib);

    /* Advance the write position in the current lock slot */
    *(int *)*pLockSlot += indexDataSize;

    return baseIndex;
}

static void RB_GetTextureFromCode_impl(int codeTexture, void **image, byte *samplerState)
{
    r_global_permanent_t *rgp = (r_global_permanent_t *)imp_rgp;
    char *tess;
    char *backEnd = (char *)imp_backEnd;
    char *dx = (char *)imp_dx;
    int lmapIdx;
    GfxWorld *world;
    int idx;

    switch (codeTexture) {
    default:
        *samplerState = 0;
        *image = NULL;
        return;

    case 0: /* white image */
        *image = rgp->blackImage; /* NOTE: struct field names may be swapped in common_types.h; offset 0x100c */
        *samplerState = 1;
        return;

    case 1: /* black image */
        *image = rgp->whiteImage; /* NOTE: struct field names may be swapped in common_types.h; offset 0x1008 */
        *samplerState = 1;
        return;

    case 2:
        *image = rgp->identityNormalMapImage;
        *samplerState = 1;
        return;

    case 3:
        *image = rgp->specularityImage;
        *samplerState = 0x32;
        return;

    case 4: { /* smodelLighting */
        GfxWorld *w = rgp->world;
        if (!w || !w->smodelLightingImage)
            Com_Error(1, str_002266cc);
        *image = rgp->world->smodelLightingImage;
        *samplerState = 0x72;
        return;
    }

    case 5:
    case 6:
        *image = *(&rgp->whiteImage + codeTexture);
        *samplerState = 0x32;
        return;

    case 7:
        *image = rgp->lightmapWeightsImage;
        *samplerState = 0x32;
        return;

    case 8:
    case 9:
    case 10:
    case 11: { /* lightmap */
        tess = (char *)imp_tess;
        lmapIdx = ((materialCommands_t *)tess)->lmapIndex;
        if (lmapIdx == 0x1f) {
            char *mat = (char *)((materialCommands_t *)tess)->material;
            R_Error(0, str_00226700, *(char **)mat);
            tess = (char *)imp_tess;
            lmapIdx = ((materialCommands_t *)tess)->lmapIndex;
        }
        world = rgp->world;
        *image = *(void **)((char *)world->lightmaps + lmapIdx * 16 + codeTexture * 4 - 0x20);
        *samplerState = 0x32;
        /* r_lightMap debug mode override */
        {
            int mode = *(int *)((char *)*(void **)imp_r_lightMap + 8);
            if (mode == 1) {
                *image = rgp->whiteImage;
                *samplerState = 1;
            } else if (mode == 2) {
                *image = rgp->blackImage;
                *samplerState = 1;
            }
        }
        return;
    }

    case 12:
        *image = ((DxGlobals *)dx)->renderTargets[4].image;
        *samplerState = 0x32;
        return;

    case 13:
        *image = ((r_backEndGlobals_t *)backEnd)->currentFeedbackImage;
        *samplerState = 0x32;
        return;

    case 14:
        idx = ((r_backEndGlobals_t *)backEnd)->resolvedPostSunTarget;
        *image = ((DxGlobals *)dx)->renderTargets[idx].image;
        *samplerState = 0x32;
        return;

    case 15:
        idx = ((r_backEndGlobals_t *)backEnd)->resolvedSceneTarget;
        *image = ((DxGlobals *)dx)->renderTargets[idx].image;
        *samplerState = 0x32;
        return;

    case 16: { /* sky sampler */
        world = rgp->world;
        if (!world || !world->skyImage)
            R_Error(1, str_00226828);
        world = rgp->world;
        *image = world->skyImage;
        *samplerState = world->skySamplerState;
        return;
    }

    case 17: { /* shadow cookie 0 */
        GfxLightDef *entry = ((r_backEndGlobals_t *)backEnd)->light[0].def;
        *image = entry->attenuation.image;
        *samplerState = entry->attenuation.samplerState;
        return;
    }

    case 18: { /* shadow cookie 1 */
        GfxLightDef *entry = ((r_backEndGlobals_t *)backEnd)->light[1].def;
        *image = entry->attenuation.image;
        *samplerState = entry->attenuation.samplerState;
        return;
    }

    case 19: { /* shadow cookie conditional */
        int sc_on = *(byte *)((char *)*(void **)imp_sc_enable + 8);
        if (sc_on) {
            char *entity = (char *)((r_backEndGlobals_t *)backEnd)->currentEntity;
            if (*(int *)entity > 2 || (*(byte *)(entity + 5) & 1)) {
                *image = ((DxGlobals *)dx)->renderTargets[3].image; /* renderTargets[3].image at 0x2c6c */
                *samplerState = 0x32;
                return;
            }
        }
        *image = rgp->whiteImage;
        *samplerState = 0x32;
        return;
    }

    case 20: { /* outdoor sampler */
        world = rgp->world;
        if (!world || !world->outdoorImage)
            R_Error(1, str_002267f4);
        *image = rgp->world->outdoorImage;
        *samplerState = 0x32;
        return;
    }

    case 21:
        *image = NULL;
        *samplerState = 0x31;
        return;

    case 22:
        *image = rgp->sunHalfAngleImage;
        *samplerState = 0x32;
        return;

    case 23:
        *image = rgp->waterColorImage;
        *samplerState = 0x32;
        return;
    }
}

/* line 522 */
/* Clean C version for WASM — no register calling convention */
static void RB_GetTextureFromCode(int codeTexture, void **image, byte *samplerState)
{
    RB_GetTextureFromCode_impl(codeTexture, image, samplerState);
}

/* line 1481 */
static void RB_SetEntityHwLightsDx7_impl(vec4_t *colorForDir, float sunVisibility)
{
    D3DLIGHT9 lights[8];
    const Material *material;
    int lightCount;
    void *device;
    void **vtable;
    int i;

    material = ((materialCommands_t *)imp_tess)->material;
    lightCount = RB_DeriveEntityLights(colorForDir, sunVisibility, material, lights, 8);

    /* Enable and configure each active light */
    for (i = 0; i < lightCount; i++) {
        /* IDirect3DDevice9::LightEnable(i, TRUE) — vtable offset 0xD4 */
        do {
            device = *(void **)((char *)imp_dx + 8);
            vtable = *(void ***)device;
            ((HRESULT (*)(void *, DWORD, BOOL))(vtable[0xD4 / 4]))(device, (DWORD)i, 1);
        } while (*(volatile int *)imp_alwaysfails);

        /* IDirect3DDevice9::SetLight(i, &lights[i]) — vtable offset 0xCC */
        do {
            device = *(void **)((char *)imp_dx + 8);
            vtable = *(void ***)device;
            ((HRESULT (*)(void *, DWORD, const D3DLIGHT9 *))(vtable[0xCC / 4]))(device, (DWORD)i, &lights[i]);
        } while (*(volatile int *)imp_alwaysfails);
    }

    /* Disable remaining lights (lightCount..7) */
    for (i = (lightCount > 0) ? lightCount : 0; (unsigned)i <= 7; i++) {
        do {
            device = *(void **)((char *)imp_dx + 8);
            vtable = *(void ***)device;
            ((HRESULT (*)(void *, DWORD, BOOL))(vtable[0xD4 / 4]))(device, (DWORD)i, 0);
        } while (*(volatile int *)imp_alwaysfails);
    }
}

/* Clean C version for WASM — no register calling convention */
static void RB_SetEntityHwLightsDx7(vec4_t *colorForDir, float sunVisibility)
{
    RB_SetEntityHwLightsDx7_impl(colorForDir, sunVisibility);
}

/* line 1785 */
void RB_CreateDynamicBuffers(void)
{
    void *(*hunkAlloc)(int) = (void *(*)(int))ri.Hunk_AllocInternal;
    materialCommands_t *t = (materialCommands_t *)imp_tess;
    t->indices = (r_index_t *)hunkAlloc(0x200000);
    t->optimizedIndices = (r_index_t *)hunkAlloc(0x200000);
}

/* line 1500 */
static void RB_SetupLighting_impl(void)
{
    char *backEnd = (char *)imp_backEnd;
    char *lighting;
    char *entity;
    int rendererType;

    rendererType = *(int *)(*(char **)imp_r_rendererInUse + 8);

    if (rendererType == 2) {
        /* Dx7 renderer path */
        int techType = ((materialCommands_t *)imp_tess)->techType;

        /* techType 15, 16, or 17: no lighting setup needed */
        if ((unsigned)(techType - 15) <= 2)
            return;

        lighting = (char *)((r_backEndGlobals_t *)backEnd)->currentEntityLighting;
        if (lighting) {
            if (*(int *)lighting != ((r_backEndGlobals_t *)backEnd)->viewCount) {
                RB_SetupEntityLighting(
                    ((r_backEndGlobals_t *)backEnd)->currentEntity,
                    (GfxEntityLighting *)lighting);
                lighting = (char *)((r_backEndGlobals_t *)backEnd)->currentEntityLighting;
            }
            /* tail-call with lighting's inline colorForDir and sunVisibility */
            RB_SetEntityHwLightsDx7_impl(
                (vec4_t *)(lighting + 8),
                *(float *)(lighting + 4));
        } else {
            entity = (char *)((r_backEndGlobals_t *)backEnd)->currentEntity;
            if (*(int *)entity == 2) {
                /* Static model: colorForDir ptr and sunVisibility from entity */
                RB_SetEntityHwLightsDx7_impl(
                    *(vec4_t **)(entity + 8),
                    ((GfxEntity *)entity)->lighting.dx7.sunVisibility);
            }
        }
        return;
    }

    /* Non-Dx7 path */
    lighting = (char *)((r_backEndGlobals_t *)backEnd)->currentEntityLighting;
    if (lighting) {
        if (*(int *)lighting != ((r_backEndGlobals_t *)backEnd)->viewCount) {
            RB_SetupEntityLighting(
                ((r_backEndGlobals_t *)backEnd)->currentEntity,
                (GfxEntityLighting *)lighting);
            lighting = (char *)((r_backEndGlobals_t *)backEnd)->currentEntityLighting;
        }

        /* Set sunPrimaryDir code constant (0x85) with w = lighting sunVisibility */
        RB_SetCodeConstant(0x85,
            ((r_backEndGlobals_t *)backEnd)->light[0].color[0],
            ((r_backEndGlobals_t *)backEnd)->light[0].color[1],
            ((r_backEndGlobals_t *)backEnd)->light[0].color[2],
            *(vec_t *)(lighting + 4));

        /* Copy 6 vec4 lighting blocks to codeConsts[18] */
        Com_Memcpy(((r_backEndGlobals_t *)backEnd)->codeConsts[18], lighting + 0x08, 96);
    } else {
        /* No lighting: copy sunPrimaryDir as fallback */
        ((r_backEndGlobals_t *)backEnd)->codeConsts[5][0] = ((r_backEndGlobals_t *)backEnd)->light[0].color[0];
        ((r_backEndGlobals_t *)backEnd)->codeConsts[5][1] = ((r_backEndGlobals_t *)backEnd)->light[0].color[1];
        ((r_backEndGlobals_t *)backEnd)->codeConsts[5][2] = ((r_backEndGlobals_t *)backEnd)->light[0].color[2];
        ((r_backEndGlobals_t *)backEnd)->codeConsts[5][3] = ((r_backEndGlobals_t *)backEnd)->light[0].color[3];

        entity = (char *)((r_backEndGlobals_t *)backEnd)->currentEntity;
        if (*(int *)entity == 2) {
            /* Static model: copy light grid dir and entity origin */
            GfxWorld *world = ((r_global_permanent_t *)imp_rgp)->world;

            ((r_backEndGlobals_t *)backEnd)->codeConsts[25][0] = world->smodelLightingLookupScale[0];
            ((r_backEndGlobals_t *)backEnd)->codeConsts[25][1] = world->smodelLightingLookupScale[1];
            ((r_backEndGlobals_t *)backEnd)->codeConsts[25][2] = world->smodelLightingLookupScale[2];
            ((r_backEndGlobals_t *)backEnd)->codeConsts[25][3] = 0.0f;

            ((r_backEndGlobals_t *)backEnd)->codeConsts[24][0] = ((GfxEntity *)entity)->lighting.origin[0];
            ((r_backEndGlobals_t *)backEnd)->codeConsts[24][1] = ((GfxEntity *)entity)->lighting.origin[1];
            ((r_backEndGlobals_t *)backEnd)->codeConsts[24][2] = ((GfxEntity *)entity)->lighting.origin[2];
            ((r_backEndGlobals_t *)backEnd)->codeConsts[24][3] = 0.0f;
        }
    }
}

/* Clean C version for WASM — no register calling convention */
static void RB_SetupLighting(void)
{
    RB_SetupLighting_impl();
}

/* line 210 */
/* Copy vertex data with color conversion for a specific stride.
 * colorOfs = byte offset of the DWORD color field within the vertex.
 * Copies all fields verbatim except color, which goes through the converter. */
static void RB_CopyVerticesWithColorConvert(const byte *src, byte *dst,
                                             int vertCount, int stride,
                                             int colorOfs, void *converter)
{
    typedef void (*ConvertFunc)(void *conv, int *outColor, const byte *srcColor);
    ConvertFunc convert = *(ConvertFunc *)*(void ***)converter;
    int i;

    for (i = 0; i < vertCount; i++) {
        int j;
        int convertedColor;

        /* Copy all dwords before color */
        for (j = 0; j < colorOfs; j += 4)
            *(int *)(dst + j) = *(const int *)(src + j);

        /* Convert color */
        convert(converter, &convertedColor, src + colorOfs);
        *(int *)(dst + colorOfs) = convertedColor;

        /* Copy all dwords after color */
        for (j = colorOfs + 4; j < stride; j += 4)
            *(int *)(dst + j) = *(const int *)(src + j);

        src += stride;
        dst += stride;
    }
}

/* line 210 */
void RB_SetVertexData(unsigned int streamIndex, const void *data, int vertexCount, int stride)
{
    char *dx = (char *)imp_dx;
    int totalSize = stride * vertexCount;
    r_vb_state_t *lockSlot = ((DxGlobals *)dx)->dynamicVertexBuffer;
    IDirect3DVertexBuffer9 *dxVb;
    int writeOffset;

    if (!lockSlot)
        return;

    dxVb = (IDirect3DVertexBuffer9 *)lockSlot->buffer;
    writeOffset = lockSlot->used;
    DWORD lockFlags;
    byte *bufferData;
    HRESULT hr;

    /* Determine lock flags: DISCARD if at start, NOOVERWRITE if appending */
    if (writeOffset == 0 || ((DxGlobals *)dx)->gpuSync == 0)
        lockFlags = 0x2000; /* D3DLOCK_DISCARD */
    else
        lockFlags = 0; /* D3DLOCK_NOOVERWRITE */

    /* Lock vertex buffer: VB vtable[0x2c/4] = Lock (index 11) */
    hr = ((HRESULT (__attribute__((stdcall)) *)(IDirect3DVertexBuffer9 *, UINT, UINT, void **, DWORD))
          (*(void ***)(dxVb))[0x2c/4])(dxVb, (UINT)writeOffset, (UINT)totalSize, (void **)&bufferData, lockFlags);

    if (hr < 0)
        R_FatalLockError(hr);

    /* Copy vertex data from tess to locked buffer, applying color conversion */
    {
        int numVerts = totalSize / stride;
        void *converter = CColorConverter_GetColorConverter(0);

        switch (stride) {
        case 0x14: /* 20 bytes: no color conversion, direct memcpy */
            Com_Memcpy(bufferData, data, totalSize);
            break;

        case 0x18: /* 24 = Dx7 world vertex: color at offset 0x0c */
            RB_CopyVerticesWithColorConvert((const byte *)data, bufferData,
                numVerts, stride, 0x0c, converter);
            break;

        case 0x20: /* 32 = static model cached Dx7: color at offset 0x0c */
            RB_CopyVerticesWithColorConvert((const byte *)data, bufferData,
                numVerts, stride, 0x0c, converter);
            break;

        case 0x24: /* 36 = Dx7 generic vertex: color at offset 0x18 */
            RB_CopyVerticesWithColorConvert((const byte *)data, bufferData,
                numVerts, stride, 0x18, converter);
            break;

        case 0x40: /* 64 = non-Dx7 generic vertex: color at offset 0x1c */
            RB_CopyVerticesWithColorConvert((const byte *)data, bufferData,
                numVerts, stride, 0x1c, converter);
            break;

        case 0x44: /* 68 = non-Dx7 world vertex: color at offset 0x1c */
            RB_CopyVerticesWithColorConvert((const byte *)data, bufferData,
                numVerts, stride, 0x1c, converter);
            break;

        default: /* Unknown stride: memcpy without color conversion */
            Com_Memcpy(bufferData, data, totalSize);
            break;
        }
    }

    /* Unlock vertex buffer: VB vtable[0x30/4] = Unlock (index 12) */
    do {
        ((HRESULT (__attribute__((stdcall)) *)(IDirect3DVertexBuffer9 *))
            (*(void ***)(dxVb))[0x30/4])(dxVb);
    } while (*(int *)imp_alwaysfails);

    /* Update stream source if VB, offset, or stride changed */
    {
        char *dxState = (char *)imp_dxState;
        int ssOfs = streamIndex * 12;
        int vertexOffset = lockSlot->used;

        if (dxVb != ((DxState *)dxState)->streams[streamIndex].vb) {
            RB_ChangeStreamSource(streamIndex, dxVb, vertexOffset, stride);
        } else if (((DxState *)dxState)->streams[streamIndex].offset != vertexOffset ||
                   ((DxState *)dxState)->streams[streamIndex].stride != stride) {
            RB_ChangeStreamSource(streamIndex, dxVb, vertexOffset, stride);
        }
    }

    /* Advance the write position in the lock slot */
    lockSlot->used += totalSize;
}


/* line 710 */
/* line 710 — Compute activeMatrices base from matrix stack index */
static inline char *RB_GetActiveMatrices(void)
{
    r_backEndGlobals_t *be = (r_backEndGlobals_t *)imp_backEnd;
    int idx = be->codeMatrixStackLevel;
    return (char *)be + 0x4e0 + idx * 3552;
}

/* Scale a 4x4 matrix by 1/worldScale: multiply xyz columns, keep w column */
static void RB_ScaleWorldMatrix(const float *src, float *dst, float invScale)
{
    int i;
    for (i = 0; i < 3; i++) {
        dst[i * 4 + 0] = src[i * 4 + 0] * invScale;
        dst[i * 4 + 1] = src[i * 4 + 1] * invScale;
        dst[i * 4 + 2] = src[i * 4 + 2] * invScale;
        dst[i * 4 + 3] = src[i * 4 + 3];
    }
    dst[12] = src[12]; dst[13] = src[13]; dst[14] = src[14]; dst[15] = src[15];
}

/* line 710 — Return pointer to a row within a code matrix.
 * source encodes both the matrix type (upper bits) and variant (low 2 bits:
 * 0=normal, 1=inverse, 2=transpose, 3=inverse-transpose).
 * Computes the matrix lazily if not already cached. */
static const float *RB_GetCodeMatrix_impl(int source, int firstRow)
{
    char *am = RB_GetActiveMatrices();
    int sourceType = source & ~3;
    int matrixIndex = source & 3;
    char *codeMatrix;
    int transposeIndex;

    /* Select the matrix block based on source type */
    switch (sourceType) {
    case 0xBC: codeMatrix = am + 0x10; break;   /* World */
    case 0xC0: codeMatrix = am + 0x230; break;  /* View */
    case 0xC4: codeMatrix = am + 0x340; break;  /* Projection */

    case 0xC8: /* WorldView (computed: World * View) */
        codeMatrix = am + 0x450;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            MatrixMultiply44(am + 0x10, am + 0x230, codeMatrix);
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;

    case 0xCC: /* ViewProjection */
        codeMatrix = am + 0x670;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            if (!((GfxCodeMatrices *)am)->worldView.valid[0]) {
                /* WorldView not computed yet — compute it */
                MatrixMultiply44(am + 0x10, am + 0x230, am + 0x450);
                ((GfxCodeMatrices *)am)->worldView.valid[0] = 1;
            }
            MatrixMultiply44(am + 0x450, am + 0x340, codeMatrix);
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;

    case 0xD0: /* WorldViewProjection */
        codeMatrix = am + 0x780;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            if (!((GfxCodeMatrices *)am)->worldView.valid[0]) {
                MatrixMultiply44(am + 0x10, am + 0x230, am + 0x450);
                ((GfxCodeMatrices *)am)->worldView.valid[0] = 1;
            }
            MatrixMultiply44(am + 0x450, am + 0x340, codeMatrix);
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;

    case 0xD4: { /* ViewProjectionGL (OpenGL conversion) */
        float OGLWorld[16], OGLView[16], OGLWorldView[16], OGLProjection[16];
        int viewport[4];
        codeMatrix = am + 0xcd0;
        /* Get World, View, Projection matrices via recursive calls */
        {
            const float *w = RB_GetCodeMatrix_impl(0xBC, 0);
            const float *v = RB_GetCodeMatrix_impl(0xC0, 0);
            const float *p = RB_GetCodeMatrix_impl(0xC4, 0);
            int i;
            for (i = 0; i < 16; i++) OGLWorld[i] = w[i];
            for (i = 0; i < 16; i++) OGLView[i] = v[i];
            for (i = 0; i < 16; i++) OGLProjection[i] = p[i];
        }
        /* Negate column 2 for OpenGL Z convention */
        OGLView[2] = -OGLView[2]; OGLView[6] = -OGLView[6];
        OGLView[10] = -OGLView[10]; OGLView[14] = -OGLView[14];
        MatrixMultiply44(OGLWorld, OGLView, OGLWorldView);
        RB_GetViewport(viewport);
        MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL(OGLProjection,
            (float)viewport[2], (float)viewport[3]);
        MatrixMultiply44(OGLWorldView, OGLProjection, codeMatrix);
        ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        ((GfxCodeMatrix *)codeMatrix)->valid[1] = 0;
        ((GfxCodeMatrix *)codeMatrix)->valid[2] = 0;
        ((GfxCodeMatrix *)codeMatrix)->valid[3] = 0;
        break;
    }

    case 0xD8: /* WorldScaled */
        codeMatrix = am + 0x120;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            const float *w = RB_GetCodeMatrix_impl(0xBC, 0);
            float invScale = 1.0f / *(float *)am;
            RB_ScaleWorldMatrix(w, (float *)codeMatrix, invScale);
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;

    case 0xDC: /* WorldScaledView */
        codeMatrix = am + 0x560;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            const float *wv = RB_GetCodeMatrix_impl(0xC8, 0);
            float invScale = 1.0f / *(float *)am;
            RB_ScaleWorldMatrix(wv, (float *)codeMatrix, invScale);
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;

    case 0xE0: /* WorldScaledViewProjection */
        codeMatrix = am + 0x560;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            const float *wvp = RB_GetCodeMatrix_impl(0xD0, 0);
            float invScale = 1.0f / *(float *)am;
            RB_ScaleWorldMatrix(wvp, (float *)codeMatrix, invScale);
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;

    case 0xE4: /* ShadowLookup (World * shadowLookupMatrix) */
        codeMatrix = am + 0x9a0;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            char *be = (char *)imp_backEnd;
            MatrixMultiply44(am + 0x10, be + 0x36e48, codeMatrix);
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;

    case 0xE8: /* LightGridLookup (ViewProjection * lightGridLookupMatrix) */
        codeMatrix = am + 0xab0;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            const float *vp = RB_GetCodeMatrix_impl(0xBF, 0); /* ViewProjection normal variant */
            MatrixMultiply44(vp, lightGridLookupMatrix, codeMatrix);
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;

    case 0xEC: { /* OutdoorMatrix */
        float biasVec[4], biasWorld[4], biasResult[4];
        codeMatrix = am + 0xbc0;
        if (!((GfxCodeMatrix *)codeMatrix)->valid[0]) {
            const float *worldMat = RB_GetCodeMatrix_impl(0xBC, 0);
            const float *viewProj = RB_GetCodeMatrix_impl(0xC1, 0); /* ViewProjection w/ some variant */
            GfxWorld *world = ((r_global_permanent_t *)imp_rgp)->world;
            int awayBias = *(int *)(*(char **)imp_r_outdoorAwayBias + 8);
            float downBias = *(float *)(*(char **)imp_r_outdoorDownBias + 8);
            /* Build bias direction vector: (0, 0, -awayBias, 0) */
            biasVec[0] = 0.0f; biasVec[1] = 0.0f;
            biasVec[2] = -*(float *)&awayBias; biasVec[3] = 0.0f;
            /* Transform bias through viewProjection */
            MatrixTransformVector44(biasVec, viewProj, biasWorld);
            biasWorld[1] += downBias;
            /* Transform through outdoor lookup matrix */
            MatrixTransformVector44(biasWorld,
                world->outdoorLookupMatrix, biasResult);
            /* Compute outdoor matrix = world * outdoorLookup */
            MatrixMultiply44(worldMat,
                world->outdoorLookupMatrix, codeMatrix);
            /* Add bias to translation row */
            ((GfxCodeMatrices *)am)->worldOutdoorLookup.matrix[0].m[3][0] += biasResult[0];
            ((GfxCodeMatrices *)am)->worldOutdoorLookup.matrix[0].m[3][1] += biasResult[1];
            ((GfxCodeMatrices *)am)->worldOutdoorLookup.matrix[0].m[3][2] += biasResult[2];
            ((GfxCodeMatrices *)am)->worldOutdoorLookup.matrix[0].m[3][3] += biasResult[3];
            ((GfxCodeMatrix *)codeMatrix)->valid[0] = 1;
        }
        break;
    }

    default:
        return NULL;
    }

    /* Handle matrix variants (inverse, transpose, inverse-transpose) */
    if (!((GfxCodeMatrix *)codeMatrix)->valid[matrixIndex]) {
        transposeIndex = matrixIndex ^ 2;
        if (((GfxCodeMatrix *)codeMatrix)->valid[transposeIndex]) {
            /* Have transpose — get normal via transpose of transpose */
            MatrixTranspose44(codeMatrix + transposeIndex * 64, codeMatrix + matrixIndex * 64);
            ((GfxCodeMatrix *)codeMatrix)->valid[matrixIndex] = 1;
        } else {
            int inverseIndex = matrixIndex ^ 1;
            if (((GfxCodeMatrix *)codeMatrix)->valid[inverseIndex]) {
                /* Have the non-transposed partner — compute via inverse */
                MatrixInverse44(codeMatrix + inverseIndex * 64, codeMatrix + matrixIndex * 64);
                ((GfxCodeMatrix *)codeMatrix)->valid[matrixIndex] = 1;
            } else {
                /* Need to compute transpose then inverse */
                MatrixTranspose44(codeMatrix + (matrixIndex ^ 3) * 64, codeMatrix + transposeIndex * 64);
                ((GfxCodeMatrix *)codeMatrix)->valid[transposeIndex] = 1;
                MatrixInverse44(codeMatrix + transposeIndex * 64, codeMatrix + matrixIndex * 64);
                ((GfxCodeMatrix *)codeMatrix)->valid[matrixIndex] = 1;
            }
        }
    }

    /* Return pointer to the requested row(s) within the selected variant */
    return (const float *)(codeMatrix + (firstRow + matrixIndex * 4) * 16);
}

/* Clean C version for WASM — no register calling convention */
static const float *RB_GetCodeMatrix(int source, int firstRow)
{
    return RB_GetCodeMatrix_impl(source, firstRow);
}


/* line 1439 — D3D shader technique application: iterates technique passes,
 * sets vertex declarations, pixel/vertex shaders, sampler states, render states,
 * code textures/constants, then issues DrawIndexedPrimitive calls.
 * 1836 lines of ASM — the largest function in the codebase.
 * MUST remain naked: register calling convention (eax=vertDeclType, edx=args, ecx=stateOverride)
 * and 30+ D3D COM vtable calls with complex state management make C conversion impractical. */
/* RB_DrawSingleTechnique — Core shader technique rendering.
 * Iterates over each pass in the technique, applies render states (state bits,
 * state map rule sets), sets pixel/vertex shaders, vertex declarations, texture
 * samplers (code textures, material textures, literal constants), then issues
 * DrawIndexedPrimitive.
 *
 * Two main paths: non-Dx7 (programmable shaders) and Dx7 (fixed-function).
 * On x86 uses register calling convention (eax=vertDeclType, edx=args, ecx=stateOverride).
 * For Emscripten, uses standard cdecl args matching the declaration. */

extern void RB_ChangeState_0(int stateBits0);
extern void RB_ChangeState_1(int stateBits1);
extern int RB_UpdateFogColor(int fogColorSrc);
extern void RB_SetSampler(int samplerIndex, int samplerState, void *image);
extern void RB_SetSamplerConstantDx7(unsigned int color);
extern void RB_SetViewMatrixForWDx7(float w);
extern void RB_ChangeColorStageState(int stageIndex, int texStageBits);
extern void RB_ChangeAlphaStageState(int stageIndex, int texStageBits);
extern void RB_ChangeGenTexCoords(int samplerIndex, int genTexCoords);
extern void RB_UploadWaterTexture(void *image, void *water);
extern void R_Error(int level, const char *msg, ...);
extern const DWORD s_fvfForVertDeclType[];

/* Helper: evaluate state map rule sets to produce final stateBits[2] */
static void RB_EvalStateMap(byte *stateMap, byte *refStateBits, int stateBits[2],
                             const GfxStateOverride *stateOverride)
{
    int ruleSetIndex;
    byte *ruleSetPtr;

    /* Copy initial state bits from material's refStateBits */
    stateBits[0] = *(int *)(refStateBits + 0);
    stateBits[1] = *(int *)(refStateBits + 4);

    /* Iterate over 11 rule sets in the stateMap */
    ruleSetPtr = stateMap;
    for (ruleSetIndex = 0; ruleSetIndex < 11; ruleSetIndex++) {
        byte *ruleSet = *(byte **)(ruleSetPtr + 4);
        int ruleCount = *(int *)ruleSet;
        int ruleIdx;
        int matched = 0;

        for (ruleIdx = 0; ruleIdx < ruleCount; ruleIdx++) {
            const MaterialStateMapRule *rule = &((const MaterialStateMapRuleSet *)ruleSet)->rules[ruleIdx];
            /* Check if rule matches current state */
            if ((*(int *)(refStateBits + 0) & rule->stateBitsMask[1]) != rule->stateBitsValue[1])
                continue;
            if ((*(int *)(refStateBits + 4) & rule->stateBitsValue[0]) != rule->stateBitsSet[0])
                continue;

            /* Apply rule: AND with clear mask, OR with set value for each state word */
            {
                int k;
                for (k = 0; k < 2; k++) {
                    stateBits[k] &= rule->stateBitsClear[k];
                    stateBits[k] |= rule->stateBitsSet[k];
                }
            }
            matched = 1;
            break;
        }

        if (!matched) {
            char *tess2 = RB_TessBase();
            const Material *mat = ((materialCommands_t *)tess2)->material;
            R_Error(0, "No rule in stateMap '%s' rule set %i matched the current mat",
                *(char **)stateMap, ruleSetIndex);
        }

        ruleSetPtr += 4;
    }

    /* Apply state override if provided */
    if (stateOverride) {
        byte *ovr = (byte *)stateOverride;
        int k;
        for (k = 0; k < 2; k++) {
            stateBits[k] &= *(int *)(ovr + k*4);
            stateBits[k] |= *(int *)(ovr + 8 + k*4);
        }
    }

    /* Clear depth write if 2D mode */
    {
        r_backEndGlobals_t *backEnd = (r_backEndGlobals_t *)imp_backEnd;
        if (backEnd->projection2D)
            stateBits[1] &= 0xffffffcf;
    }
}

/* Helper: set pixel shader, vertex shader, vertex declaration via D3D COM calls */
static void RB_SetShaderAndDecl(byte *pass, int vertDeclType, byte *dxState)
{
    byte *dx = (byte *)imp_dx;
    byte *device = *(byte **)(dx + 8);
    void **vtable = *(void ***)device;
    volatile int *alwaysfails = (volatile int *)imp_alwaysfails;

    /* Set pixel shader (pass->pixelShader -> shader ptr) */
    {
        MaterialShader *psShader = ((MaterialPassDx9 *)pass)->pixelShader;
        void *pixelShader = (void *)psShader->u.ps;

        if (pixelShader != ((DxState *)dxState)->pixelShader) {
            do {
                device = *(byte **)(dx + 8);
                vtable = *(void ***)device;
                ((void (*)(void *, void *))vtable[0x1ac/4])(device, pixelShader);
            } while (*alwaysfails);
            ((DxState *)dxState)->pixelShader = pixelShader;
        }
    }

    /* Set vertex shader (pass->vertexShader -> shader ptr) */
    {
        MaterialShader *vsShader = ((MaterialPassDx9 *)pass)->vertexShader;
        void *vertexShader = (void *)vsShader->u.vs;

        if (vertexShader != ((DxState *)dxState)->vertexShader) {
            do {
                device = *(byte **)(dx + 8);
                vtable = *(void ***)device;
                ((void (*)(void *, void *))vtable[0x170/4])(device, vertexShader);
            } while (*alwaysfails);
            ((DxState *)dxState)->vertexShader = vertexShader;
        }
    }

    /* Set vertex declaration (pass->vertexDecl -> decl at [vertDeclType] offset 8) */
    {
        byte *declArray = (byte *)((MaterialPassDx9 *)pass)->vertexDecl;
        void *decl = *(void **)(declArray + 8 + vertDeclType * 4);

        if (decl != ((DxState *)dxState)->vertexDecl) {
            do {
                device = *(byte **)(dx + 8);
                vtable = *(void ***)device;
                ((void (*)(void *, void *))vtable[0x15c/4])(device, decl);
            } while (*alwaysfails);
            ((DxState *)dxState)->vertexDecl = decl;
            ((DxState *)dxState)->fvf = 0;
        }
    }
}

/* Helper: issue DrawIndexedPrimitive D3D call */
static void RB_DrawIndexedPrim(const GfxDrawPrimArgs *args, int numPrims)
{
    byte *dx = (byte *)imp_dx;
    byte *device;
    void **vtable;
    volatile int *alwaysfails = (volatile int *)imp_alwaysfails;

    do {
        device = *(byte **)(dx + 8);
        vtable = *(void ***)device;
        ((void (*)(void *, int, int, int, int, int, int))vtable[0x148/4])(
            device, 4 /* D3DPT_TRIANGLELIST */,
            args->u.buf.baseVertex,
            args->firstVertexFromBase,
            args->vertexCount,
            args->u.buf.baseIndex,
            args->primCount);
    } while (*alwaysfails);
}

static void RB_DrawSingleTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args, const GfxStateOverride *stateOverride)
{
    char *tess = RB_TessBase();
    const Material *material = ((materialCommands_t *)tess)->material;
    byte *technique;
    int passCount;
    int passIndex;
    int isDx7;
    byte *dxState;
    byte *backEnd;

    /* Get technique from material's technique set */
    {
        byte *techSet = *(byte **)(material->techniqueSet);
        technique = *(byte **)(techSet + 4 + vertDeclType * 4);
    }

    /* Check for debug shader (vertDeclType == 0x21) */
    if (vertDeclType == 0x21) {
        byte *g_special = (byte *)imp_g_special;
        int debugLevel = *(int *)(*(byte **)imp_r_debugShader + 8);
        byte *debugConst = (byte *)debugShaderConsts + debugLevel * 16;
        byte *backEndConst = (byte *)imp_backEnd + 0x1a0;
        memcpy(backEndConst, debugConst, 16);
    }

    /* Set g_special flag based on args (Dx7 pass 3 check) */
    {
        byte *g_special = (byte *)imp_g_special;
        *g_special = (args == (const GfxDrawPrimArgs *)3) ? 1 : 0;
    }

    /* Get pass count */
    passCount = *(unsigned short *)(technique + 6);
    if (passCount == 0)
        goto done;

    isDx7 = (*(int *)(*(byte **)imp_r_rendererInUse + 8) == 2);
    dxState = (byte *)imp_dxState;
    backEnd = (byte *)imp_backEnd;

    for (passIndex = 0; passIndex < passCount; passIndex++) {
        byte *pass;
        int stateBits[2];

        if (isDx7) {
            /* Dx7 pass: stride = passIndex * 92 (23*4) */
            int passOffset = passIndex * 92; /* (passIndex*3*8 - passIndex) * 4 = passIndex * 92 */
            pass = technique + 8 + passOffset;
        } else {
            /* Non-Dx7 pass: stride = passIndex * 28 (7*4) */
            int passOffset = passIndex * 28;
            pass = technique + 8 + passOffset;
        }

        if (isDx7) {
            /* === Dx7 path === */
            byte *refStateBits;
            byte *stateMap;

            tess = RB_TessBase();
            {
                const Material *tessMat = ((materialCommands_t *)tess)->material;
                refStateBits = (byte *)tessMat->stateBits;
            }
            stateMap = *(byte **)(pass + 8);

            /* Evaluate state map */
            stateBits[0] = *(int *)(refStateBits + 0);
            stateBits[1] = *(int *)(refStateBits + 4);

            /* Process state map rule sets */
            {
                byte *rsp = stateMap;
                int rsi;
                for (rsi = 0; rsi < 11; rsi++) {
                    byte *ruleSet = *(byte **)(rsp + 4);
                    int rc = *(int *)ruleSet;
                    int ri2;
                    int matched = 0;

                    for (ri2 = 0; ri2 < rc; ri2++) {
                        const MaterialStateMapRule *rule = &((const MaterialStateMapRuleSet *)ruleSet)->rules[ri2];
                        if ((*(int *)(refStateBits + 0) & rule->stateBitsMask[1]) != rule->stateBitsValue[1])
                            continue;
                        if ((*(int *)(refStateBits + 4) & rule->stateBitsValue[0]) != rule->stateBitsSet[0])
                            continue;

                        {
                            int k;
                            for (k = 0; k < 2; k++) {
                                stateBits[k] &= rule->stateBitsClear[k];
                                stateBits[k] |= rule->stateBitsSet[k];
                            }
                        }
                        matched = 1;
                        break;
                    }

                    if (!matched) {
                        const Material *mat2 = ((materialCommands_t *)RB_TessBase())->material;
                        R_Error(0, "No rule in stateMap '%s' rule set %i matched the current mat",
                            *(char **)stateMap, rsi, mat2->info.name);
                    }

                    rsp += 4;
                }
            }

            /* Apply state override */
            if (stateOverride) {
                byte *ovr = (byte *)stateOverride;
                int k;
                for (k = 0; k < 2; k++) {
                    stateBits[k] &= *(int *)(ovr + k*4);
                    stateBits[k] |= *(int *)(ovr + 8 + k*4);
                }
            }

            /* Clear depth write in 2D mode */
            if (((r_backEndGlobals_t *)backEnd)->projection2D)
                stateBits[1] &= 0xffffffcf;

            /* Apply state bits changes */
            if (stateBits[0] != ((DxState *)dxState)->refStateBits[0]) {
                RB_ChangeState_0(stateBits[0]);
                ((DxState *)dxState)->refStateBits[0] = stateBits[0];
            }
            if (stateBits[1] != ((DxState *)dxState)->refStateBits[1]) {
                RB_ChangeState_1(stateBits[1]);
                ((DxState *)dxState)->refStateBits[1] = stateBits[1];
            }

            /* Update fog color: Dx7 pass uses normalFog(0) vs iteratorFog based on pass[8] */
            {
                int fogSrc = (*(byte *)(pass + 8) == 1) ? 0 : 2;
                RB_UpdateFogColor(fogSrc);
            }

            /* Set normalizeNormals render state if pass[4] differs */
            {
                byte passNormalize = *(byte *)(pass + 4);
                if (passNormalize != ((DxState *)dxState)->gridLighting) {
                    byte *dx = (byte *)imp_dx;
                    volatile int *af = (volatile int *)imp_alwaysfails;
                    do {
                        byte *dev = *(byte **)(dx + 8);
                        void **vt = *(void ***)dev;
                        ((void (*)(void *, int, int))vt[0xe4/4])(dev, 0x89,
                            passNormalize ? 1 : 0);
                    } while (*af);
                    ((DxState *)dxState)->gridLighting = passNormalize;
                }
            }

            /* Set FVF if vertex declaration changed */
            {
                DWORD fvf = s_fvfForVertDeclType[vertDeclType];
                if (((DxState *)dxState)->vertexDecl != NULL) {
                    byte *dx = (byte *)imp_dx;
                    volatile int *af = (volatile int *)imp_alwaysfails;
                    do {
                        byte *dev = *(byte **)(dx + 8);
                        void **vt = *(void ***)dev;
                        ((void (*)(void *, DWORD))vt[0x164/4])(dev, fvf);
                    } while (*af);
                    ((DxState *)dxState)->fvf = fvf;
                    ((DxState *)dxState)->vertexDecl = NULL;
                } else if (fvf != ((DxState *)dxState)->fvf) {
                    byte *dx = (byte *)imp_dx;
                    volatile int *af = (volatile int *)imp_alwaysfails;
                    do {
                        byte *dev = *(byte **)(dx + 8);
                        void **vt = *(void ***)dev;
                        ((void (*)(void *, DWORD))vt[0x164/4])(dev, fvf);
                    } while (*af);
                    ((DxState *)dxState)->fvf = fvf;
                    ((DxState *)dxState)->vertexDecl = NULL;
                }
            }

            /* Set objective color sampler constant (if pass has Dx7 color) */
            if (*(byte *)(pass + 7)) {
                /* Compute animated objective color from dvars */
                byte *backEnd2 = backEnd;
                float phase = ((r_backEndGlobals_t *)backEnd2)->sceneDef.floatTime; /* 0x3bc = sceneDef+4 */
                byte *minDvar = *(byte **)imp_r_objectiveColorDx7Min;
                minDvar = *(byte **)minDvar;
                byte *maxDvar = *(byte **)imp_r_objectiveColorDx7Max;
                maxDvar = *(byte **)maxDvar;

                float oneOver255 = 0.003921568859368563f;
                float aMin = (float)minDvar[8+3] * oneOver255;
                float rMin = (float)minDvar[8+0] * oneOver255;
                float gMin = (float)minDvar[8+1] * oneOver255;
                float bMin = (float)minDvar[8+2] * oneOver255;

                /* Compute sin-based interpolation factor */
                float t;
                {
                    float frac = phase - floorf(phase);
                    float angle = frac * 6.283185307179586f;
                    float s = sinf(angle);
                    t = s * -0.5f + 0.5f;
                }

                /* Interpolate between min and max colors */
                unsigned int color = 0;
                {
                    float aMax = (float)maxDvar[8+3] * oneOver255;
                    float rMax = (float)maxDvar[8+0] * oneOver255;
                    float gMax = (float)maxDvar[8+1] * oneOver255;
                    float bMax = (float)maxDvar[8+2] * oneOver255;

                    int a = (int)(((aMax - aMin) * t + aMin) * 255.0f);
                    int r = (int)(((rMax - rMin) * t + rMin) * 255.0f);
                    int g = (int)(((gMax - gMin) * t + gMin) * 255.0f);
                    int b = (int)(((bMax - bMin) * t + bMin) * 255.0f);

                    color = (a << 24) | (r << 16) | (g << 8) | b;
                }
                RB_SetSamplerConstantDx7(color);
            } else {
                RB_SetSamplerConstantDx7(0xFFFFFFFF);
            }

            /* Set Dx7 samplers (2 texture stages) */
            {
                int samplerIndex;
                for (samplerIndex = 0; samplerIndex < 2; samplerIndex++) {
                    byte *samplerDef = pass + 0xc + samplerIndex * 8;
                    /* ... sampler setup ... */
                }
            }

            /* Set Dx7 texture stage states (8 stages) */
            {
                int stageIdx;
                int *stagePtr = ((MaterialPassDx7 *)pass)->colorStageBits;
                int *dxStagePtr = ((DxState *)dxState)->refColorStageBits;

                for (stageIdx = 0; stageIdx < 8; stageIdx++) {
                    int colorBits = stagePtr[stageIdx];
                    if (colorBits != dxStagePtr[stageIdx]) {
                        dxStagePtr[stageIdx] = colorBits;
                        RB_ChangeColorStageState(stageIdx, colorBits);
                    }

                    int alphaBits = ((MaterialPassDx7 *)pass)->alphaStageBits[stageIdx];
                    if (alphaBits != ((DxState *)dxState)->refAlphaStageBits[stageIdx]) {
                        ((DxState *)dxState)->refAlphaStageBits[stageIdx] = alphaBits;
                        RB_ChangeAlphaStageState(stageIdx, alphaBits);
                    }
                }
            }
        } else {
            /* === Non-Dx7 path (programmable pipeline) === */
            byte *refStateBits;
            byte *stateMap;
            int textureRoutingCount;
            int constantRoutingCount;
            byte *textureRouting;
            byte *constantRouting;

            /* Get pass struct for non-Dx7 */
            {
                int passOff = passIndex * 28;
                pass = technique + 8 + passOff;
            }

            /* Check that vertex type supports this shader */
            {
                MaterialVertexDeclaration *declArray = ((MaterialPassDx9 *)pass)->vertexDecl;
                void *decl = declArray->decl[vertDeclType];
                if (!decl) {
                    tess = RB_TessBase();
                    const Material *mat3 = ((materialCommands_t *)tess)->material;
                    MaterialShader *pgm = ((MaterialPassDx9 *)pass)->vertexShader;
                    R_Error(0, "Vertex type %i doesn't have the information used by shader %",
                        vertDeclType, pgm->name, mat3->info.name);
                    tess = RB_TessBase();
                    continue;
                }
            }

            /* Get material refStateBits and stateMap */
            tess = RB_TessBase();
            {
                const Material *tessMat = ((materialCommands_t *)tess)->material;
                refStateBits = (byte *)tessMat->stateBits;
            }
            stateMap = (byte *)((MaterialPassDx9 *)pass)->stateMap;

            /* Evaluate state bits from state map rule sets */
            stateBits[0] = *(int *)(refStateBits + 0);
            stateBits[1] = *(int *)(refStateBits + 4);

            {
                byte *rsp = stateMap;
                int rsi;
                for (rsi = 0; rsi < 11; rsi++) {
                    byte *ruleSet = *(byte **)(rsp + 4);
                    int rc = *(int *)ruleSet;
                    int ri2;
                    int matched = 0;

                    for (ri2 = 0; ri2 < rc; ri2++) {
                        const MaterialStateMapRule *rule = &((const MaterialStateMapRuleSet *)ruleSet)->rules[ri2];
                        if ((*(int *)(refStateBits + 0) & rule->stateBitsMask[1]) != rule->stateBitsValue[1])
                            continue;
                        if ((*(int *)(refStateBits + 4) & rule->stateBitsValue[0]) != rule->stateBitsSet[0])
                            continue;

                        {
                            int k;
                            for (k = 0; k < 2; k++) {
                                stateBits[k] &= rule->stateBitsClear[k];
                                stateBits[k] |= rule->stateBitsSet[k];
                            }
                        }
                        matched = 1;
                        break;
                    }

                    if (!matched) {
                        const Material *mat4 = ((materialCommands_t *)RB_TessBase())->material;
                        R_Error(0, "No rule in stateMap '%s' rule set %i matched the current mat",
                            *(char **)stateMap, rsi, mat4->info.name);
                    }

                    rsp += 4;
                }
            }

            /* Apply state override */
            if (stateOverride) {
                byte *ovr = (byte *)stateOverride;
                int k;
                for (k = 0; k < 2; k++) {
                    stateBits[k] &= *(int *)(ovr + k*4);
                    stateBits[k] |= *(int *)(ovr + 8 + k*4);
                }
            }

            /* Clear depth write in 2D mode */
            if (((r_backEndGlobals_t *)backEnd)->projection2D)
                stateBits[1] &= 0xffffffcf;

            /* Apply state bits changes */
            if (stateBits[0] != ((DxState *)dxState)->refStateBits[0]) {
                RB_ChangeState_0(stateBits[0]);
                ((DxState *)dxState)->refStateBits[0] = stateBits[0];
            }
            if (stateBits[1] != ((DxState *)dxState)->refStateBits[1]) {
                RB_ChangeState_1(stateBits[1]);
                ((DxState *)dxState)->refStateBits[1] = stateBits[1];
            }

            /* Update fog color */
            RB_UpdateFogColor(0);

            /* Set pixel shader, vertex shader, vertex declaration */
            RB_SetShaderAndDecl(pass, vertDeclType, dxState);

            /* Process texture routing entries */
            textureRoutingCount = ((MaterialPassDx9 *)pass)->vertexArgCount;
            textureRouting = (byte *)((MaterialPassDx9 *)pass)->vertexArgs;

            {
                int routingIndex;
                for (routingIndex = 0; routingIndex < textureRoutingCount; routingIndex++) {
                    byte *entry = textureRouting + routingIndex * 8;
                    int type = *(unsigned short *)entry;
                    int destIndex = *(unsigned short *)(entry + 2);
                    void *data = *(void **)(entry + 4);

                    switch (type) {
                    case 0: /* Literal constant (vec4) */
                    {
                        /* Compare and update dxState constant cache */
                        byte *cached = dxState + destIndex * 16;
                        if (memcmp(cached, data, 16) != 0) {
                            memcpy(cached, data, 16);
                            /* SetPixelShaderConstantF */
                            {
                                byte *dx = (byte *)imp_dx;
                                volatile int *af = (volatile int *)imp_alwaysfails;
                                do {
                                    byte *dev = *(byte **)(dx + 8);
                                    void **vt = *(void ***)dev;
                                    ((void (*)(void *, int, void *, int))vt[0x178/4])(
                                        dev, destIndex, data, 1);
                                } while (*af);
                            }
                        }
                        break;
                    }
                    case 1: /* Code constant */
                    {
                        int codeIndex = *(unsigned short *)(entry + 4);
                        int rowCount = *(byte *)(entry + 7);
                        int firstRow = *(byte *)(entry + 6);
                        const float *matrixData;

                        if (codeIndex <= 0xba) {
                            matrixData = (const float *)((byte *)imp_backEnd - 0x800 + codeIndex * 16);
                        } else {
                            matrixData = RB_GetCodeMatrix(codeIndex, firstRow);
                        }

                        /* Compare and update */
                        {
                            int dataSize = rowCount * 16;
                            byte *cached = dxState + destIndex * 16;
                            if (memcmp(cached, matrixData, dataSize) != 0) {
                                memcpy(cached, matrixData, dataSize);
                                byte *dx = (byte *)imp_dx;
                                volatile int *af = (volatile int *)imp_alwaysfails;
                                do {
                                    byte *dev = *(byte **)(dx + 8);
                                    void **vt = *(void ***)dev;
                                    ((void (*)(void *, int, void *, int))vt[0x178/4])(
                                        dev, destIndex, (void *)matrixData, rowCount);
                                } while (*af);
                            }
                        }
                        break;
                    }
                    case 2: /* Material literal constant */
                    {
                        int literalName = (int)(intptr_t)data;
                        void *constData = NULL;
                        int rowCount2 = 1;

                        /* Find constant in material's constant table */
                        {
                            tess = RB_TessBase();
                            const Material *mat5 = ((materialCommands_t *)tess)->material;
                            int constCount = mat5->constantCount;
                            byte *consts = (byte *)mat5->constants;
                            int ci;
                            for (ci = 0; ci < constCount; ci++) {
                                if (*(int *)(consts + ci * 0x14) == literalName) {
                                    constData = consts + ci * 0x14 + 4;
                                    break;
                                }
                            }
                        }

                        if (constData) {
                            int dataSize = rowCount2 * 16;
                            byte *cached = dxState + destIndex * 16;
                            if (memcmp(cached, constData, dataSize) != 0) {
                                memcpy(cached, constData, dataSize);
                                byte *dx = (byte *)imp_dx;
                                volatile int *af = (volatile int *)imp_alwaysfails;
                                do {
                                    byte *dev = *(byte **)(dx + 8);
                                    void **vt = *(void ***)dev;
                                    ((void (*)(void *, int, void *, int))vt[0x178/4])(
                                        dev, destIndex, constData, rowCount2);
                                } while (*af);
                            }
                        }
                        break;
                    }
                    default:
                        break;
                    }
                }
            }

            /* Process constant routing entries */
            constantRoutingCount = ((MaterialPassDx9 *)pass)->pixelArgCount;
            constantRouting = (byte *)((MaterialPassDx9 *)pass)->pixelArgs;

            {
                int routingIndex;
                for (routingIndex = 0; routingIndex < constantRoutingCount; routingIndex++) {
                    byte *entry = constantRouting + routingIndex * 8;
                    int type = *(unsigned short *)entry;

                    switch (type) {
                    case 0: /* Literal pixel shader constant */
                    {
                        void *data = *(void **)(entry + 4);
                        int destIdx = *(unsigned short *)(entry + 2);
                        byte *cached = dxState + 0x1000 + destIdx * 16;
                        if (memcmp(cached, data, 16) != 0) {
                            memcpy(cached, data, 16);
                            byte *dx = (byte *)imp_dx;
                            volatile int *af = (volatile int *)imp_alwaysfails;
                            do {
                                byte *dev = *(byte **)(dx + 8);
                                void **vt = *(void ***)dev;
                                ((void (*)(void *, int, void *, int))vt[0x1b4/4])(
                                    dev, destIdx, data, 1);
                            } while (*af);
                        }
                        break;
                    }
                    case 1: /* Code pixel shader constant */
                    {
                        int codeIndex = *(unsigned short *)(entry + 4);
                        int rowCount = *(byte *)(entry + 7);
                        int firstRow = *(byte *)(entry + 6);
                        const float *matrixData;

                        if (codeIndex <= 0xba) {
                            matrixData = (const float *)((byte *)imp_backEnd - 0x800 + codeIndex * 16);
                        } else {
                            matrixData = RB_GetCodeMatrix(codeIndex, firstRow);
                        }

                        {
                            int dataSize = rowCount * 16;
                            int destIdx = *(unsigned short *)(entry + 2);
                            byte *cached = dxState + 0x1000 + destIdx * 16;
                            if (memcmp(cached, matrixData, dataSize) != 0) {
                                memcpy(cached, matrixData, dataSize);
                                byte *dx = (byte *)imp_dx;
                                volatile int *af = (volatile int *)imp_alwaysfails;
                                do {
                                    byte *dev = *(byte **)(dx + 8);
                                    void **vt = *(void ***)dev;
                                    ((void (*)(void *, int, void *, int))vt[0x1b4/4])(
                                        dev, destIdx, (void *)matrixData, rowCount);
                                } while (*af);
                            }
                        }
                        break;
                    }
                    case 2: /* Material literal pixel shader constant */
                    {
                        int literalName = *(int *)(entry + 4);
                        void *constData = NULL;
                        int rowCount2 = 1;

                        {
                            tess = RB_TessBase();
                            const Material *mat5 = ((materialCommands_t *)tess)->material;
                            int constCount = mat5->constantCount;
                            byte *consts = (byte *)mat5->constants;
                            int ci;
                            for (ci = 0; ci < constCount; ci++) {
                                if (*(int *)(consts + ci * 0x14) == literalName) {
                                    constData = consts + ci * 0x14 + 4;
                                    break;
                                }
                            }
                        }

                        if (constData) {
                            int destIdx = *(unsigned short *)(entry + 2);
                            int dataSize = rowCount2 * 16;
                            byte *cached = dxState + 0x1000 + destIdx * 16;
                            if (memcmp(cached, constData, dataSize) != 0) {
                                memcpy(cached, constData, dataSize);
                                byte *dx = (byte *)imp_dx;
                                volatile int *af = (volatile int *)imp_alwaysfails;
                                do {
                                    byte *dev = *(byte **)(dx + 8);
                                    void **vt = *(void ***)dev;
                                    ((void (*)(void *, int, void *, int))vt[0x1b4/4])(
                                        dev, destIdx, constData, rowCount2);
                                } while (*af);
                            }
                        }
                        break;
                    }
                    case 3: /* Code texture sampler */
                    {
                        int codeTexture = *(int *)(entry + 4);
                        void *image = NULL;
                        byte samplerState = 0;

                        RB_GetTextureFromCode_impl(codeTexture, &image, &samplerState);
                        RB_SetSampler(*(unsigned short *)(entry + 2), samplerState, image);
                        break;
                    }
                    case 4: /* Named texture sampler */
                    {
                        int textureName = *(int *)(entry + 4);
                        void *image = NULL;
                        byte samplerState = 0;
                        int destSampler = *(unsigned short *)(entry + 2);

                        /* Find texture in material's texture table */
                        {
                            tess = RB_TessBase();
                            const Material *mat6 = ((materialCommands_t *)tess)->material;
                            int texCount = mat6->textureCount;
                            MaterialTextureDef *textures = mat6->textures;
                            int ti;
                            for (ti = 0; ti < texCount; ti++) {
                                MaterialTextureDef *texDef = &textures[ti];
                                if (*(int *)texDef == textureName) {
                                    /* Check semantic */
                                    byte semantic = texDef->semantic;
                                    if (semantic == 5) {
                                        /* Water texture */
                                        MaterialWaterDef *water = texDef->u.water;
                                        image = water->map->image;
                                    } else {
                                        image = texDef->u.image;
                                    }
                                    samplerState = texDef->samplerState;

                                    /* Check for colorMap/specularMap/normalMap override (semantic 3 at image+0) */
                                    if (image && *(int *)image == 3) {
                                        /* Handle image type overrides */
                                        byte imgSemantic = texEntry[5];
                                        /* ... override logic ... */
                                    }
                                    break;
                                }
                            }
                        }

                        if (image) {
                            RB_SetSampler(destSampler, samplerState, image);
                        }
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }

        /* Issue DrawIndexedPrimitive unless in 2D skip mode */
        if (!((r_backEndGlobals_t *)backEnd)->projection2D) {
            int primCount = args->primCount;
            int drawPrimFloor = *(int *)(*(byte **)imp_r_drawPrimFloor + 8);
            int drawPrimCap = *(int *)(*(byte **)imp_r_drawPrimCap + 8);

            if (primCount >= drawPrimFloor && (drawPrimCap == 0 || primCount <= drawPrimCap)) {
                RB_DrawIndexedPrim(args, primCount);
            }
        } else {
            /* 2D mode: always draw */
            RB_DrawIndexedPrim(args, args->primCount);
        }

        /* Dx7 post-pass: restore W matrix */
        if (isDx7) {
            if (((MaterialTechnique *)technique)->passArray.dx7[0].projectToInfinity) {
                RB_SetViewMatrixForWDx7(0.0f);
                /* ... draw with Dx7 W override ... */
                RB_SetViewMatrixForWDx7(1.0f);
            }
        }
    }

done:
    /* Clear g_special flag */
    {
        byte *g_special = (byte *)imp_g_special;
        *g_special = 0;
    }
}
