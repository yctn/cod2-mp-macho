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
#ifndef __EMSCRIPTEN__
static void RB_GetTextureFromCode(void);
#endif
static void RB_SetEntityHwLightsDx7_impl(vec4_t *colorForDir, float sunVisibility);
#ifndef __EMSCRIPTEN__
static void RB_SetEntityHwLightsDx7(void);
#endif
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
    *(int *)(tess + 0x5a7cc) = 0;
    *(int *)(tess + 0x5a7b8) = 0;
    *(int *)(tess + 0x5a7d0) = 0;
    *(int *)(tess + 0x5a7d4) = 0;
    *(int *)(tess + 0x5a7d8) = 0;
    *(int *)(tess + 0x5a7dc) = 0;
    *(const Material **)(tess + 0x5a7bc) = material;
    *(MaterialTechniqueType *)(tess + 0x5a7c0) = techType;
    *(int *)(tess + 0x5a7c4) = lmapIndex;
}

/* line 132 */
int RB_SetIndexData(const r_index_t *indices, int indexCount)
{
    char *dx = (char *)imp_dx;
    int indexDataSize = indexCount * 2;  /* r_index_t = 2 bytes */
    char **pLockSlot = (char **)(dx + 0x2d8c);
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
    if (!overflow && (*(int *)(dx + 0x2c20) != 0 || byteOffset != 0))
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

    if (ib != *(IDirect3DIndexBuffer9 **)(((char *)imp_dxState) + 0x20cc))
        RB_ChangeIndices(ib);

    /* Advance the write position in the current lock slot */
    *(int *)*pLockSlot += indexDataSize;

    return baseIndex;
}

static void RB_GetTextureFromCode_impl(int codeTexture, void **image, byte *samplerState)
{
    char *rgp = (char *)imp_rgp;
    char *tess;
    char *backEnd = (char *)imp_backEnd;
    char *dx = (char *)imp_dx;
    int lmapIdx;
    char *drawSurfs;
    int idx;

    switch (codeTexture) {
    default:
        *samplerState = 0;
        *image = NULL;
        return;

    case 0: /* white image */
        *image = *(void **)(rgp + 0x100c);
        *samplerState = 1;
        return;

    case 1: /* black image */
        *image = *(void **)(rgp + 0x1008);
        *samplerState = 1;
        return;

    case 2:
        *image = *(void **)(rgp + 0x1010);
        *samplerState = 1;
        return;

    case 3:
        *image = *(void **)(rgp + 0x1014);
        *samplerState = 0x32;
        return;

    case 4: { /* smodelLighting */
        char *surfs = *(char **)(rgp + 0x109c);
        if (!surfs || !*(void **)(surfs + 0x10c))
            Com_Error(1, str_002266cc);
        *image = *(void **)((char *)*(char **)(rgp + 0x109c) + 0x10c);
        *samplerState = 0x72;
        return;
    }

    case 5:
    case 6:
        *image = *(void **)(rgp + 0x1008 + codeTexture * 4);
        *samplerState = 0x32;
        return;

    case 7:
        *image = *(void **)(rgp + 0x1018);
        *samplerState = 0x32;
        return;

    case 8:
    case 9:
    case 10:
    case 11: { /* lightmap */
        tess = (char *)imp_tess;
        lmapIdx = *(int *)(tess + 0x5a7c4);
        if (lmapIdx == 0x1f) {
            char *mat = *(char **)(tess + 0x5a7bc);
            R_Error(0, str_00226700, *(char **)mat);
            tess = (char *)imp_tess;
            lmapIdx = *(int *)(tess + 0x5a7c4);
        }
        drawSurfs = *(char **)(rgp + 0x109c);
        *image = *(void **)(*(char **)(drawSurfs + 0x108) + lmapIdx * 16 + codeTexture * 4 - 0x20);
        *samplerState = 0x32;
        /* r_lightMap debug mode override */
        {
            int mode = *(int *)((char *)*(void **)imp_r_lightMap + 8);
            if (mode == 1) {
                *image = *(void **)(rgp + 0x1008);
                *samplerState = 1;
            } else if (mode == 2) {
                *image = *(void **)(rgp + 0x100c);
                *samplerState = 1;
            }
        }
        return;
    }

    case 12:
        *image = *(void **)(dx + 0x2c80);
        *samplerState = 0x32;
        return;

    case 13:
        *image = *(void **)(backEnd + 0x2e8c);
        *samplerState = 0x32;
        return;

    case 14:
        idx = *(int *)(backEnd + 0x2e84);
        *image = *(void **)(dx + 0x2c30 + idx * 20);
        *samplerState = 0x32;
        return;

    case 15:
        idx = *(int *)(backEnd + 0x2e88);
        *image = *(void **)(dx + 0x2c30 + idx * 20);
        *samplerState = 0x32;
        return;

    case 16: { /* sky sampler */
        drawSurfs = *(char **)(rgp + 0x109c);
        if (!drawSurfs || !*(void **)(drawSurfs + 0x20))
            R_Error(1, str_00226828);
        drawSurfs = *(char **)(rgp + 0x109c);
        *image = *(void **)(drawSurfs + 0x20);
        *samplerState = *(byte *)(drawSurfs + 0x24);
        return;
    }

    case 17: { /* shadow cookie 0 */
        char *entry = *(char **)(backEnd + 0x2ed0);
        *image = *(void **)(entry + 0x0c);
        *samplerState = *(byte *)(entry + 0x10);
        return;
    }

    case 18: { /* shadow cookie 1 */
        char *entry = *(char **)(backEnd + 0x2ed0 + 68);
        *image = *(void **)(entry + 0x0c);
        *samplerState = *(byte *)(entry + 0x10);
        return;
    }

    case 19: { /* shadow cookie conditional */
        int sc_on = *(byte *)((char *)*(void **)imp_sc_enable + 8);
        if (sc_on) {
            char *entity = *(char **)(backEnd + 0x440);
            if (*(int *)entity > 2 || (*(byte *)(entity + 5) & 1)) {
                *image = *(void **)(dx + 0x2c6c);
                *samplerState = 0x32;
                return;
            }
        }
        *image = *(void **)(rgp + 0x1008);
        *samplerState = 0x32;
        return;
    }

    case 20: { /* outdoor sampler */
        drawSurfs = *(char **)(rgp + 0x109c);
        if (!drawSurfs || !*(void **)(drawSurfs + 0x200))
            R_Error(1, str_002267f4);
        *image = *(void **)((char *)*(char **)(rgp + 0x109c) + 0x200);
        *samplerState = 0x32;
        return;
    }

    case 21:
        *image = NULL;
        *samplerState = 0x31;
        return;

    case 22:
        *image = *(void **)(rgp + 0x10a0);
        *samplerState = 0x32;
        return;

    case 23:
        *image = *(void **)(rgp + 0x10a4);
        *samplerState = 0x32;
        return;
    }
}

/* line 522 */
#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void RB_GetTextureFromCode(int codeTexture, void **image, byte *samplerState)
{
    RB_GetTextureFromCode_impl(codeTexture, image, samplerState);
}
#else
/* x86 trampoline: eax=codeTexture, edx=image, ecx=samplerState → cdecl _impl */
static __attribute__((naked))
void RB_GetTextureFromCode(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll RB_GetTextureFromCode_impl\n"
        "addl $12, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

/* line 1481 */
static void RB_SetEntityHwLightsDx7_impl(vec4_t *colorForDir, float sunVisibility)
{
    D3DLIGHT9 lights[8];
    const Material *material;
    int lightCount;
    void *device;
    void **vtable;
    int i;

    material = *(const Material **)((char *)imp_tess + 0x5a7bc);
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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void RB_SetEntityHwLightsDx7(vec4_t *colorForDir, float sunVisibility)
{
    RB_SetEntityHwLightsDx7_impl(colorForDir, sunVisibility);
}
#else
/* Naked trampoline: eax=colorForDir, xmm0=sunVisibility → cdecl _impl */
static __attribute__((naked))
void RB_SetEntityHwLightsDx7(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetEntityHwLightsDx7_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

/* line 1785 */
void RB_CreateDynamicBuffers(void)
{
    void *(*hunkAlloc)(int) = *(void *(**)(int))((byte *)imp_ri + 0xc);
    byte *t = (byte *)imp_tess;
    *(void **)(t + 0x5a7b0) = hunkAlloc(0x200000);
    *(void **)(t + 0x5a7b4) = hunkAlloc(0x200000);
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
        int techType = *(int *)((char *)imp_tess + 0x5a7c0);

        /* techType 15, 16, or 17: no lighting setup needed */
        if ((unsigned)(techType - 15) <= 2)
            return;

        lighting = *(char **)(backEnd + 0x444);
        if (lighting) {
            if (*(int *)lighting != *(int *)(backEnd + 0x3b4)) {
                RB_SetupEntityLighting(
                    (const GfxEntity *)*(void **)(backEnd + 0x440),
                    (GfxEntityLighting *)lighting);
                lighting = *(char **)(backEnd + 0x444);
            }
            /* tail-call with lighting's inline colorForDir and sunVisibility */
            RB_SetEntityHwLightsDx7_impl(
                (vec4_t *)(lighting + 8),
                *(float *)(lighting + 4));
        } else {
            entity = *(char **)(backEnd + 0x440);
            if (*(int *)entity == 2) {
                /* Static model: colorForDir ptr and sunVisibility from entity */
                RB_SetEntityHwLightsDx7_impl(
                    *(vec4_t **)(entity + 8),
                    *(float *)(entity + 0xc));
            }
        }
        return;
    }

    /* Non-Dx7 path */
    lighting = *(char **)(backEnd + 0x444);
    if (lighting) {
        if (*(int *)lighting != *(int *)(backEnd + 0x3b4)) {
            RB_SetupEntityLighting(
                (const GfxEntity *)*(void **)(backEnd + 0x440),
                (GfxEntityLighting *)lighting);
            lighting = *(char **)(backEnd + 0x444);
        }

        /* Set sunPrimaryDir code constant (0x85) with w = lighting sunVisibility */
        RB_SetCodeConstant(0x85,
            *(vec_t *)(backEnd + 0x2eb0),
            *(vec_t *)(backEnd + 0x2eb4),
            *(vec_t *)(backEnd + 0x2eb8),
            *(vec_t *)(lighting + 4));

        /* Copy 6 vec4 lighting blocks to backEnd */
        Com_Memcpy(backEnd + 0x120, lighting + 0x08, 96);
    } else {
        /* No lighting: copy sunPrimaryDir as fallback */
        *(float *)(backEnd + 0x50) = *(float *)(backEnd + 0x2eb0);
        *(float *)(backEnd + 0x54) = *(float *)(backEnd + 0x2eb4);
        *(float *)(backEnd + 0x58) = *(float *)(backEnd + 0x2eb8);
        *(float *)(backEnd + 0x5c) = *(float *)(backEnd + 0x2ebc);

        entity = *(char **)(backEnd + 0x440);
        if (*(int *)entity == 2) {
            /* Static model: copy light grid dir and entity origin */
            char *smodel = *(char **)((char *)imp_rgp + 0x109c);

            *(float *)(backEnd + 0x190) = *(float *)(smodel + 0x110);
            *(float *)(backEnd + 0x194) = *(float *)(smodel + 0x114);
            *(float *)(backEnd + 0x198) = *(float *)(smodel + 0x118);
            *(float *)(backEnd + 0x19c) = 0.0f;

            *(float *)(backEnd + 0x180) = *(float *)(entity + 0x08);
            *(float *)(backEnd + 0x184) = *(float *)(entity + 0x0c);
            *(float *)(backEnd + 0x188) = *(float *)(entity + 0x10);
            *(float *)(backEnd + 0x18c) = 0.0f;
        }
    }
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void RB_SetupLighting(void)
{
    RB_SetupLighting_impl();
}
#else
/* x86 trampoline: void(void), tail-call to _impl */
static __attribute__((naked))
void RB_SetupLighting(void)
{
    __asm__ __volatile__ (
        "jmp RB_SetupLighting_impl\n"
    );
}
#endif

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
    int *lockSlot = *(int **)(dx + 0x2db4);
    IDirect3DVertexBuffer9 *dxVb;
    int writeOffset;

    if (!lockSlot)
        return;

    dxVb = *(IDirect3DVertexBuffer9 **)(lockSlot + 2); /* lockSlot[8] = VB ptr */
    writeOffset = lockSlot[0];
    DWORD lockFlags;
    byte *bufferData;
    HRESULT hr;

    /* Determine lock flags: DISCARD if at start, NOOVERWRITE if appending */
    if (writeOffset == 0 || *(int *)(dx + 0x2c20) == 0)
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
        int vertexOffset = lockSlot[0];

        if (dxVb != *(IDirect3DVertexBuffer9 **)(dxState + 0x20d0 + ssOfs)) {
            RB_ChangeStreamSource(streamIndex, dxVb, vertexOffset, stride);
        } else if (*(int *)(dxState + 0x20d4 + ssOfs) != vertexOffset ||
                   *(int *)(dxState + 0x20d8 + ssOfs) != stride) {
            RB_ChangeStreamSource(streamIndex, dxVb, vertexOffset, stride);
        }
    }

    /* Advance the write position in the lock slot */
    lockSlot[0] += totalSize;
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1: i, i, i, i, ... */
        "movl 0x14(%ebp), %eax\n" /* line 224 | stride */
        "imull 0x10(%ebp), %eax\n" /* vertexCount */
        "movl %eax, -0xd8(%ebp)\n" /* totalSize */
        "movl imp_dx, %eax\n" /* line 245 | vb */
        "movl 0x2db4(%eax), %eax\n" /* vb */
        /* { scope 2: y, color, tx, ty, ... */
        "movl 8(%eax), %edx\n" /* line 1005 */
        "movl %edx, -0xdc(%ebp)\n" /* dxVb */
        /* } scope */
        "movl (%eax), %edx\n" /* line 253 */
        "cmpl $1, %edx\n"
        "sbbl %eax, %eax\n"
        "andl $__mh_execute_header, %eax\n"
        "addl $__mh_execute_header, %eax\n"
        "movl -0xdc(%ebp), %ebx\n" /* line 255 | dxVb */
        "movl (%ebx), %ecx\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* bufferData */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xd8(%ebp), %esi\n" /* totalSize */
        "movl %esi, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 257 */
        "js .Lff76c0_000f7da3\n"
        ".Lff76c0_000f772d:\n"
        "movl -0xd8(%ebp), %eax\n" /* line 265 | totalSize */
        "cltd\n"
        "idivl 0x14(%ebp)\n" /* stride */
        "movl %eax, -0xe0(%ebp)\n"
        "movl 0x14(%ebp), %ebx\n" /* line 266 | stride, strideInDWords */
        "shrl $2, %ebx\n" /* strideInDWords */
        "movl 0xc(%ebp), %edx\n" /* line 267 | data */
        "movl %edx, -0xd4(%ebp)\n" /* pSrc */
        "movl -0x1c(%ebp), %esi\n" /* line 268 | bufferData */
        "movl %esi, -0xd0(%ebp)\n" /* pDst */
        "movl $0, (%esp)\n" /* line 270 */
        "calll CColorConverter_GetColorConverter\n"
        "movl %eax, -0xcc(%ebp)\n" /* c */
        "movl 0x14(%ebp), %eax\n" /* line 271 | stride */
        "subl $0x14, %eax\n"
        "cmpl $0x30, %eax\n"
        "ja .Lff76c0_000f7795\n"
        "jmpl *.Ljt_f76c0_0(, %eax, 4)\n"
        ".Lff76c0_000f7779:\n"
        "movl -0xd8(%ebp), %edx\n" /* line 324 | totalSize */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %ebx\n" /* data, x */
        "movl %ebx, 4(%esp)\n" /* x */
        "movl -0x1c(%ebp), %eax\n" /* bufferData */
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        ".Lff76c0_000f7795:\n"
        "movl -0xdc(%ebp), %edx\n" /* line 439 | dxVb */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *0x30(%eax)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff76c0_000f7795\n"
        "movl imp_dx, %ebx\n" /* line 442 | nx */
        "movl 0x2db4(%ebx), %eax\n" /* nx */
        "movl (%eax), %ecx\n" /* vertexOffset */
        /* { scope 2: y, color, tx, ty, ... */
        "movl 8(%ebp), %esi\n" /* line 220 | streamIndex */
        "leal (%esi, %esi, 2), %eax\n"
        "shll $2, %eax\n"
        "addl imp_dxState, %eax\n"
        "leal 0x20d0(%eax), %edx\n"
        "movl -0xdc(%ebp), %esi\n" /* dxVb */
        "cmpl 0x20d0(%eax), %esi\n"
        "je .Lff76c0_000f781a\n"
        "movl 0x14(%ebp), %edx\n" /* stride */
        "movl %esi, %ebx\n"
        ".Lff76c0_000f77e4:\n"
        "movl %edx, 0xc(%esp)\n" /* line 221 */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* streamIndex */
        "movl %esi, (%esp)\n"
        "calll RB_ChangeStreamSource\n"
        "movl imp_dx, %ebx\n"
        /* } scope */
        ".Lff76c0_000f7801:\n"
        "movl 0x2db4(%ebx), %eax\n" /* line 443 | nx */
        "movl -0xd8(%ebp), %edx\n" /* totalSize */
        "addl %edx, (%eax)\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 446 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i, i, i, i, ... */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f781a:\n"
        "cmpl 4(%edx), %ecx\n" /* line 220 */
        "je .Lff76c0_000f7db0\n"
        "movl 0x14(%ebp), %edx\n" /* stride */
        "movl -0xdc(%ebp), %ebx\n" /* dxVb */
        "jmp .Lff76c0_000f77e4\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f782e:\n"
        "movl -0xe0(%ebp), %eax\n" /* line 388 */
        "testl %eax, %eax\n"
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* w */
        "movl %ebx, -0x2c(%ebp)\n" /* w */
        "movl $0, -0x68(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f7849:\n"
        "movl -0xd4(%ebp), %ebx\n" /* line 391 | pSrc, w */
        "movl 4(%ebx), %ebx\n" /* w */
        "movl %ebx, -0xfc(%ebp)\n" /* w, y */
        "movl -0xd4(%ebp), %esi\n" /* line 392 | pSrc, nx */
        "movl 8(%esi), %ecx\n" /* nx, z */
        "movl 0xc(%esi), %ebx\n" /* line 393 | nx */
        "movl %esi, %eax\n" /* line 394 | ny */
        "movl 0x10(%esi), %esi\n" /* ny */
        "movl 0x14(%eax), %edi\n" /* line 395 | nz */
        "movl 0x1c(%eax), %edx\n" /* line 397 */
        "movl %edx, -0x64(%ebp)\n" /* tx */
        "movl 0x20(%eax), %eax\n" /* line 398 */
        "movl %eax, -0x60(%ebp)\n" /* ty */
        "movl -0xd4(%ebp), %edx\n" /* line 399 | pSrc */
        "movl 0x24(%edx), %edx\n"
        "movl %edx, -0x5c(%ebp)\n" /* lx */
        "movl -0xd4(%ebp), %eax\n" /* line 400 | pSrc */
        "movl 0x28(%eax), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* ly */
        "movl -0xd4(%ebp), %edx\n" /* line 401 | pSrc */
        "movl 0x2c(%edx), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* bnx */
        "movl -0xd4(%ebp), %eax\n" /* line 402 | pSrc */
        "movl 0x30(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* bny */
        "movl -0xd4(%ebp), %edx\n" /* line 403 | pSrc */
        "movl 0x34(%edx), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* bnz */
        "movl -0xd4(%ebp), %eax\n" /* line 404 | pSrc */
        "movl 0x38(%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* tanx */
        "movl -0xd4(%ebp), %edx\n" /* line 405 | pSrc */
        "movl 0x3c(%edx), %edx\n"
        "movl %edx, -0x44(%ebp)\n" /* tany */
        "movl -0xd4(%ebp), %eax\n" /* line 406 | pSrc */
        "movl 0x40(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* tanz */
        "movl -0xd4(%ebp), %edx\n" /* line 408 | pSrc */
        "movl (%edx), %edx\n"
        "movl -0xd0(%ebp), %eax\n" /* pDst */
        "movl %edx, (%eax)\n"
        "movl -0xfc(%ebp), %edx\n" /* line 409 | y */
        "movl %edx, 4(%eax)\n"
        "movl %ecx, 8(%eax)\n" /* line 410 */
        "movl %ebx, 0xc(%eax)\n" /* line 411 | nx */
        "movl %esi, 0x10(%eax)\n" /* line 412 | ny */
        "movl %edi, 0x14(%eax)\n" /* line 413 | nz */
        "movl -0xcc(%ebp), %ebx\n" /* line 414 | c, nx */
        "movl (%ebx), %edx\n" /* nx */
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0x18, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* color, ny */
        "movl %esi, 4(%esp)\n" /* ny */
        "movl %ebx, (%esp)\n" /* nx */
        "calll *(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 415 | color */
        "movl -0xd0(%ebp), %edx\n" /* pDst */
        "movl %eax, 0x18(%edx)\n"
        "movl -0x64(%ebp), %ebx\n" /* line 416 | tx, nx */
        "movl %ebx, 0x1c(%edx)\n" /* nx */
        "movl -0x60(%ebp), %esi\n" /* line 417 | ty, ny */
        "movl %esi, 0x20(%edx)\n" /* ny */
        "movl -0x5c(%ebp), %eax\n" /* line 418 | lx */
        "movl %eax, 0x24(%edx)\n"
        "movl -0x58(%ebp), %ebx\n" /* line 419 | ly, nx */
        "movl %ebx, 0x28(%edx)\n" /* nx */
        "movl -0x54(%ebp), %esi\n" /* line 420 | bnx, ny */
        "movl %esi, 0x2c(%edx)\n" /* ny */
        "movl -0x50(%ebp), %eax\n" /* line 421 | bny */
        "movl %eax, 0x30(%edx)\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 422 | bnz, nx */
        "movl %ebx, 0x34(%edx)\n" /* nx */
        "movl -0x48(%ebp), %esi\n" /* line 423 | tanx, ny */
        "movl %esi, 0x38(%edx)\n" /* ny */
        "movl -0x44(%ebp), %eax\n" /* line 424 | tany */
        "movl %eax, 0x3c(%edx)\n"
        "movl -0x40(%ebp), %ebx\n" /* line 425 | tanz, nx */
        "movl %ebx, 0x40(%edx)\n" /* nx */
        /* } scope */
        "addl $1, -0x68(%ebp)\n" /* line 388 | i */
        "movl -0x2c(%ebp), %esi\n" /* nx */
        "addl %esi, -0xd4(%ebp)\n" /* nx, pSrc */
        "addl %esi, %edx\n" /* nx */
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0x68(%ebp), %eax\n" /* i */
        "cmpl %eax, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f7849\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f798f:\n"
        "movl -0xe0(%ebp), %edi\n" /* line 347 | z */
        "testl %edi, %edi\n" /* z */
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* x */
        "movl %ebx, -0x30(%ebp)\n" /* x */
        "movl $0, -0x90(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f79ad:\n"
        "movl -0xd4(%ebp), %ebx\n" /* line 350 | pSrc, x */
        "movl 4(%ebx), %ebx\n" /* x */
        "movl %ebx, -0xfc(%ebp)\n" /* x, y */
        "movl -0xd4(%ebp), %esi\n" /* line 351 | pSrc, y */
        "movl 8(%esi), %ecx\n" /* y, z */
        "movl 0xc(%esi), %ebx\n" /* line 352 | y, w */
        "movl %esi, %eax\n" /* line 353 | nx */
        "movl 0x10(%esi), %esi\n" /* nx */
        "movl 0x14(%eax), %edi\n" /* line 354 | ny */
        "movl 0x18(%eax), %edx\n" /* line 355 */
        "movl %edx, -0x8c(%ebp)\n" /* nz */
        "movl 0x20(%eax), %eax\n" /* line 357 */
        "movl %eax, -0x88(%ebp)\n" /* tx */
        "movl -0xd4(%ebp), %edx\n" /* line 358 | pSrc */
        "movl 0x24(%edx), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* ty */
        "movl -0xd4(%ebp), %eax\n" /* line 359 | pSrc */
        "movl 0x28(%eax), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* bnx */
        "movl -0xd4(%ebp), %edx\n" /* line 360 | pSrc */
        "movl 0x2c(%edx), %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* bny */
        "movl -0xd4(%ebp), %eax\n" /* line 361 | pSrc */
        "movl 0x30(%eax), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* bnz */
        "movl -0xd4(%ebp), %edx\n" /* line 362 | pSrc */
        "movl 0x34(%edx), %edx\n"
        "movl %edx, -0x74(%ebp)\n" /* tanx */
        "movl -0xd4(%ebp), %eax\n" /* line 363 | pSrc */
        "movl 0x38(%eax), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* tany */
        "movl -0xd4(%ebp), %edx\n" /* line 364 | pSrc */
        "movl 0x3c(%edx), %edx\n"
        "movl %edx, -0x6c(%ebp)\n" /* tanz */
        "movl -0xd4(%ebp), %eax\n" /* line 366 | pSrc */
        "movl (%eax), %eax\n"
        "movl -0xd0(%ebp), %edx\n" /* pDst */
        "movl %eax, (%edx)\n"
        "movl -0xfc(%ebp), %eax\n" /* line 367 | y */
        "movl %eax, 4(%edx)\n"
        "movl %ecx, 8(%edx)\n" /* line 368 */
        "movl %ebx, 0xc(%edx)\n" /* line 369 | w */
        "movl %esi, 0x10(%edx)\n" /* line 370 | nx */
        "movl %edi, 0x14(%edx)\n" /* line 371 | ny */
        "movl -0x8c(%ebp), %ebx\n" /* line 372 | nz, w */
        "movl %ebx, 0x18(%edx)\n" /* w */
        "movl -0xcc(%ebp), %esi\n" /* line 374 | c, nx */
        "movl (%esi), %edx\n" /* nx */
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0x1c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* nx */
        "calll *(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 375 | color */
        "movl -0xd0(%ebp), %edx\n" /* pDst */
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x88(%ebp), %ebx\n" /* line 377 | tx, w */
        "movl %ebx, 0x20(%edx)\n" /* w */
        "movl -0x84(%ebp), %esi\n" /* line 378 | ty, nx */
        "movl %esi, 0x24(%edx)\n" /* nx */
        "movl -0x80(%ebp), %eax\n" /* line 379 | bnx */
        "movl %eax, 0x28(%edx)\n"
        "movl -0x7c(%ebp), %ebx\n" /* line 380 | bny, w */
        "movl %ebx, 0x2c(%edx)\n" /* w */
        "movl -0x78(%ebp), %esi\n" /* line 381 | bnz, nx */
        "movl %esi, 0x30(%edx)\n" /* nx */
        "movl -0x74(%ebp), %eax\n" /* line 382 | tanx */
        "movl %eax, 0x34(%edx)\n"
        "movl -0x70(%ebp), %ebx\n" /* line 383 | tany, w */
        "movl %ebx, 0x38(%edx)\n" /* w */
        "movl -0x6c(%ebp), %esi\n" /* line 384 | tanz, nx */
        "movl %esi, 0x3c(%edx)\n" /* nx */
        /* } scope */
        "addl $1, -0x90(%ebp)\n" /* line 347 | i */
        "movl -0x30(%ebp), %eax\n"
        "addl %eax, -0xd4(%ebp)\n" /* pSrc */
        "addl %eax, %edx\n"
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0x90(%ebp), %edx\n" /* i */
        "cmpl %edx, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f79ad\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f7af9:\n"
        "movl -0xe0(%ebp), %esi\n" /* line 274 */
        "testl %esi, %esi\n"
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* strideInDWords */
        "movl %ebx, -0x34(%ebp)\n" /* strideInDWords */
        "movl $0, -0xc8(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f7b17:\n"
        "movl -0xd4(%ebp), %eax\n" /* line 276 | pSrc */
        "movl (%eax), %ebx\n" /* x */
        "movl 4(%eax), %esi\n" /* line 277 | y */
        "movl 8(%eax), %edi\n" /* line 278 | z */
        "movl 0xc(%eax), %edx\n" /* line 279 */
        "movl %edx, -0xc4(%ebp)\n" /* nx */
        "movl 0x10(%eax), %eax\n" /* line 280 */
        "movl %eax, -0xc0(%ebp)\n" /* ny */
        "movl -0xd4(%ebp), %edx\n" /* line 281 | pSrc */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0xbc(%ebp)\n" /* nz */
        "movl -0xd4(%ebp), %eax\n" /* line 283 | pSrc */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, -0xb8(%ebp)\n" /* tx */
        "movl -0xd4(%ebp), %edx\n" /* line 284 | pSrc */
        "movl 0x20(%edx), %edx\n"
        "movl %edx, -0xb4(%ebp)\n" /* ty */
        "movl -0xcc(%ebp), %eax\n" /* line 286 | c */
        "movl (%eax), %edx\n"
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0x18, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl -0xcc(%ebp), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0xd0(%ebp), %edx\n" /* line 288 | pDst */
        "movl %ebx, (%edx)\n" /* x */
        "movl %esi, 4(%edx)\n" /* line 289 | y */
        "movl %edi, 8(%edx)\n" /* line 290 | z */
        "movl -0xc4(%ebp), %ebx\n" /* line 291 | nx, x */
        "movl %ebx, 0xc(%edx)\n" /* x */
        "movl -0xc0(%ebp), %esi\n" /* line 292 | ny, y */
        "movl %esi, 0x10(%edx)\n" /* y */
        "movl -0xbc(%ebp), %eax\n" /* line 293 | nz */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 294 | color */
        "movl %eax, 0x18(%edx)\n"
        "movl -0xb8(%ebp), %ebx\n" /* line 295 | tx, x */
        "movl %ebx, 0x1c(%edx)\n" /* x */
        "movl -0xb4(%ebp), %esi\n" /* line 296 | ty, y */
        "movl %esi, 0x20(%edx)\n" /* y */
        /* } scope */
        "addl $1, -0xc8(%ebp)\n" /* line 274 | i */
        "movl -0x34(%ebp), %eax\n"
        "addl %eax, -0xd4(%ebp)\n" /* pSrc */
        "addl %eax, %edx\n"
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0xc8(%ebp), %edx\n" /* i */
        "cmpl %edx, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f7b17\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f7bfb:\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 300 */
        "testl %ecx, %ecx\n"
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* x */
        "movl %ebx, -0x38(%ebp)\n" /* x */
        "movl $0, -0xb0(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f7c19:\n"
        "movl -0xd4(%ebp), %esi\n" /* line 302 | pSrc, y */
        "movl (%esi), %ebx\n" /* y, x */
        "movl %esi, %eax\n" /* line 303 | y */
        "movl 4(%esi), %esi\n" /* y */
        "movl 8(%eax), %edi\n" /* line 304 | z */
        "movl 0x10(%eax), %edx\n" /* line 306 */
        "movl %edx, -0xac(%ebp)\n" /* tx0 */
        "movl 0x14(%eax), %eax\n" /* line 307 */
        "movl %eax, -0xa8(%ebp)\n" /* ty0 */
        "movl -0xd4(%ebp), %edx\n" /* line 308 | pSrc */
        "movl 0x18(%edx), %edx\n"
        "movl %edx, -0xa4(%ebp)\n" /* tx1 */
        "movl -0xd4(%ebp), %eax\n" /* line 309 | pSrc */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, -0xa0(%ebp)\n" /* ty1 */
        "movl -0xcc(%ebp), %eax\n" /* line 311 | c */
        "movl (%eax), %edx\n"
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0xc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl -0xcc(%ebp), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0xd0(%ebp), %edx\n" /* line 313 | pDst */
        "movl %ebx, (%edx)\n" /* x */
        "movl %esi, 4(%edx)\n" /* line 314 | y */
        "movl %edi, 8(%edx)\n" /* line 315 | z */
        "movl -0x20(%ebp), %eax\n" /* line 316 | color */
        "movl %eax, 0xc(%edx)\n"
        "movl -0xac(%ebp), %ebx\n" /* line 317 | tx0, x */
        "movl %ebx, 0x10(%edx)\n" /* x */
        "movl -0xa8(%ebp), %esi\n" /* line 318 | ty0, y */
        "movl %esi, 0x14(%edx)\n" /* y */
        "movl -0xa4(%ebp), %eax\n" /* line 319 | tx1 */
        "movl %eax, 0x18(%edx)\n"
        "movl -0xa0(%ebp), %ebx\n" /* line 320 | ty1, x */
        "movl %ebx, 0x1c(%edx)\n" /* x */
        /* } scope */
        "addl $1, -0xb0(%ebp)\n" /* line 300 | i */
        "movl -0x38(%ebp), %esi\n" /* y */
        "addl %esi, -0xd4(%ebp)\n" /* y, pSrc */
        "addl %esi, %edx\n" /* y */
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0xb0(%ebp), %eax\n" /* i */
        "cmpl %eax, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f7c19\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f7ce7:\n"
        "movl -0xe0(%ebp), %edx\n" /* line 327 */
        "testl %edx, %edx\n"
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* x */
        "movl %ebx, -0x3c(%ebp)\n" /* x */
        "movl $0, -0x9c(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f7d05:\n"
        "movl -0xd4(%ebp), %esi\n" /* line 329 | pSrc, y */
        "movl (%esi), %ebx\n" /* y, x */
        "movl %esi, %eax\n" /* line 330 | y */
        "movl 4(%esi), %esi\n" /* y */
        "movl 8(%eax), %edi\n" /* line 331 | z */
        "movl 0x10(%eax), %edx\n" /* line 333 */
        "movl %edx, -0x98(%ebp)\n" /* tx */
        "movl 0x14(%eax), %eax\n" /* line 334 */
        "movl %eax, -0x94(%ebp)\n" /* ty */
        "movl -0xcc(%ebp), %eax\n" /* line 336 | c */
        "movl (%eax), %edx\n"
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0xc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl -0xcc(%ebp), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0xd0(%ebp), %edx\n" /* line 338 | pDst */
        "movl %ebx, (%edx)\n" /* x */
        "movl %esi, 4(%edx)\n" /* line 339 | y */
        "movl %edi, 8(%edx)\n" /* line 340 | z */
        "movl -0x20(%ebp), %eax\n" /* line 341 | color */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x98(%ebp), %ebx\n" /* line 342 | tx, x */
        "movl %ebx, 0x10(%edx)\n" /* x */
        "movl -0x94(%ebp), %esi\n" /* line 343 | ty, y */
        "movl %esi, 0x14(%edx)\n" /* y */
        /* } scope */
        "addl $1, -0x9c(%ebp)\n" /* line 327 | i */
        "movl -0x3c(%ebp), %eax\n"
        "addl %eax, -0xd4(%ebp)\n" /* pSrc */
        "addl %eax, %edx\n"
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0x9c(%ebp), %edx\n" /* i */
        "cmpl %edx, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f7d05\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        ".Lff76c0_000f7da3:\n"
        "movl %eax, (%esp)\n" /* line 258 */
        "calll R_FatalLockError\n"
        "jmp .Lff76c0_000f772d\n"
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f7db0:\n"
        "movl 0x14(%ebp), %eax\n" /* line 220 | stride */
        "cmpl 8(%edx), %eax\n"
        "je .Lff76c0_000f7801\n"
        "movl %eax, %edx\n"
        "movl -0xdc(%ebp), %ebx\n" /* dxVb */
        "jmp .Lff76c0_000f77e4\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_f76c0_0:\n"
        ".long .Lff76c0_000f7779\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7ce7\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7bfb\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7af9\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f798f\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f782e\n"
        ".text\n"
    );
}
#endif

/* line 710 */
/* line 710 — Compute activeMatrices base from matrix stack index */
static inline char *RB_GetActiveMatrices(void)
{
    char *be = (char *)imp_backEnd;
    int idx = *(int *)(be + 0x2e80);
    return be + 0x4e0 + idx * 3552;
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
        if (!*(byte *)(codeMatrix + 0x100)) {
            MatrixMultiply44(am + 0x10, am + 0x230, codeMatrix);
            *(byte *)(codeMatrix + 0x100) = 1;
        }
        break;

    case 0xCC: /* ViewProjection */
        codeMatrix = am + 0x670;
        if (!*(byte *)(codeMatrix + 0x100)) {
            if (!*(byte *)(am + 0x550)) {
                /* WorldView not computed yet — compute it */
                MatrixMultiply44(am + 0x10, am + 0x230, am + 0x450);
                *(byte *)(am + 0x550) = 1;
            }
            MatrixMultiply44(am + 0x450, am + 0x340, codeMatrix);
            *(byte *)(codeMatrix + 0x100) = 1;
        }
        break;

    case 0xD0: /* WorldViewProjection */
        codeMatrix = am + 0x780;
        if (!*(byte *)(codeMatrix + 0x100)) {
            if (!*(byte *)(am + 0x550)) {
                MatrixMultiply44(am + 0x10, am + 0x230, am + 0x450);
                *(byte *)(am + 0x550) = 1;
            }
            MatrixMultiply44(am + 0x450, am + 0x340, codeMatrix);
            *(byte *)(codeMatrix + 0x100) = 1;
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
        *(byte *)(codeMatrix + 0x100) = 1;
        *(byte *)(codeMatrix + 0x101) = 0;
        *(byte *)(codeMatrix + 0x102) = 0;
        *(byte *)(codeMatrix + 0x103) = 0;
        break;
    }

    case 0xD8: /* WorldScaled */
        codeMatrix = am + 0x120;
        if (!*(byte *)(codeMatrix + 0x100)) {
            const float *w = RB_GetCodeMatrix_impl(0xBC, 0);
            float invScale = 1.0f / *(float *)am;
            RB_ScaleWorldMatrix(w, (float *)codeMatrix, invScale);
            *(byte *)(codeMatrix + 0x100) = 1;
        }
        break;

    case 0xDC: /* WorldScaledView */
        codeMatrix = am + 0x560;
        if (!*(byte *)(codeMatrix + 0x100)) {
            const float *wv = RB_GetCodeMatrix_impl(0xC8, 0);
            float invScale = 1.0f / *(float *)am;
            RB_ScaleWorldMatrix(wv, (float *)codeMatrix, invScale);
            *(byte *)(codeMatrix + 0x100) = 1;
        }
        break;

    case 0xE0: /* WorldScaledViewProjection */
        codeMatrix = am + 0x560;
        if (!*(byte *)(codeMatrix + 0x100)) {
            const float *wvp = RB_GetCodeMatrix_impl(0xD0, 0);
            float invScale = 1.0f / *(float *)am;
            RB_ScaleWorldMatrix(wvp, (float *)codeMatrix, invScale);
            *(byte *)(codeMatrix + 0x100) = 1;
        }
        break;

    case 0xE4: /* ShadowLookup (World * shadowLookupMatrix) */
        codeMatrix = am + 0x9a0;
        if (!*(byte *)(codeMatrix + 0x100)) {
            char *be = (char *)imp_backEnd;
            MatrixMultiply44(am + 0x10, be + 0x36e48, codeMatrix);
            *(byte *)(codeMatrix + 0x100) = 1;
        }
        break;

    case 0xE8: /* LightGridLookup (ViewProjection * lightGridLookupMatrix) */
        codeMatrix = am + 0xab0;
        if (!*(byte *)(codeMatrix + 0x100)) {
            const float *vp = RB_GetCodeMatrix_impl(0xBF, 0); /* ViewProjection normal variant */
            MatrixMultiply44(vp, lightGridLookupMatrix, codeMatrix);
            *(byte *)(codeMatrix + 0x100) = 1;
        }
        break;

    case 0xEC: { /* OutdoorMatrix */
        float biasVec[4], biasWorld[4], biasResult[4];
        codeMatrix = am + 0xbc0;
        if (!*(byte *)(codeMatrix + 0x100)) {
            const float *worldMat = RB_GetCodeMatrix_impl(0xBC, 0);
            const float *viewProj = RB_GetCodeMatrix_impl(0xC1, 0); /* ViewProjection w/ some variant */
            char *rgp = (char *)imp_rgp;
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
                (char *)*(void **)(rgp + 0x109c) + 0x1c0, biasResult);
            /* Compute outdoor matrix = world * outdoorLookup */
            MatrixMultiply44(worldMat,
                (char *)*(void **)(rgp + 0x109c) + 0x1c0, codeMatrix);
            /* Add bias to translation row */
            *(float *)(am + 0xbf0 + 0) += biasResult[0];
            *(float *)(am + 0xbf0 + 4) += biasResult[1];
            *(float *)(am + 0xbf0 + 8) += biasResult[2];
            *(float *)(am + 0xbf0 + 12) += biasResult[3];
            *(byte *)(codeMatrix + 0x100) = 1;
        }
        break;
    }

    default:
        return NULL;
    }

    /* Handle matrix variants (inverse, transpose, inverse-transpose) */
    if (!*(byte *)(codeMatrix + 0x100 + matrixIndex)) {
        transposeIndex = matrixIndex ^ 2;
        if (*(byte *)(codeMatrix + 0x100 + transposeIndex)) {
            /* Have transpose — get normal via transpose of transpose */
            MatrixTranspose44(codeMatrix + transposeIndex * 64, codeMatrix + matrixIndex * 64);
            *(byte *)(codeMatrix + 0x100 + matrixIndex) = 1;
        } else {
            int inverseIndex = matrixIndex ^ 1;
            if (*(byte *)(codeMatrix + 0x100 + inverseIndex)) {
                /* Have the non-transposed partner — compute via inverse */
                MatrixInverse44(codeMatrix + inverseIndex * 64, codeMatrix + matrixIndex * 64);
                *(byte *)(codeMatrix + 0x100 + matrixIndex) = 1;
            } else {
                /* Need to compute transpose then inverse */
                MatrixTranspose44(codeMatrix + (matrixIndex ^ 3) * 64, codeMatrix + transposeIndex * 64);
                *(byte *)(codeMatrix + 0x100 + transposeIndex) = 1;
                MatrixInverse44(codeMatrix + transposeIndex * 64, codeMatrix + matrixIndex * 64);
                *(byte *)(codeMatrix + 0x100 + matrixIndex) = 1;
            }
        }
    }

    /* Return pointer to the requested row(s) within the selected variant */
    return (const float *)(codeMatrix + (firstRow + matrixIndex * 4) * 16);
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static const float *RB_GetCodeMatrix(int source, int firstRow)
{
    return RB_GetCodeMatrix_impl(source, firstRow);
}
#else
/* x86 trampoline: eax=source, edx=firstRow → cdecl _impl */
static __attribute__((naked))
const float * RB_GetCodeMatrix(int source, int firstRow)
{
    __asm__ __volatile__ (
        "pushl %edx\n"
        "pushl %eax\n"
        "calll RB_GetCodeMatrix_impl\n"
        "addl $8, %esp\n"
        "retl\n"
    );
}
#endif

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        ".Lff7dca_000f7dca:\n"
        "pushl %ebp\n" /* line 710 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        "movl %eax, -0x138(%ebp)\n"
        "movl %edx, -0x13c(%ebp)\n"
        /* { scope 1: OGLWorld, OGLView, OGLWorldView, OGLProjection, ... */
        "movl imp_backEnd, %ebx\n" /* line 719 */
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %ecx\n" /* rowCount */
        "shll $4, %ecx\n" /* rowCount */
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n" /* rowCount */
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %ebx), %eax\n"
        "movl %eax, -0x134(%ebp)\n" /* activeMatrices */
        "movl -0x138(%ebp), %eax\n" /* line 726 */
        "andl $0xfffffffc, %eax\n"
        "subl $0xbc, %eax\n"
        "cmpl $0x30, %eax\n"
        "ja .Lff7dca_000f7e26\n"
        "jmpl *.Ljt_f7dca_0(, %eax, 4)\n"
        ".Lff7dca_000f7e26:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x14c, %esp\n" /* line 895 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: OGLWorld, OGLView, OGLWorldView, OGLProjection, ... */
        ".Lff7dca_000f7e33:\n"
        "movl -0x134(%ebp), %eax\n" /* line 729 | activeMatrices */
        "addl $0x10, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        ".Lff7dca_000f7e42:\n"
        "movl -0x138(%ebp), %esi\n" /* line 864 | matrixIndex */
        "andl $3, %esi\n" /* matrixIndex */
        "cmpb $0, 0x100(%esi, %eax)\n" /* line 865 | matrixIndex */
        "jne .Lff7dca_000f7ea9\n"
        "movl %esi, %edi\n" /* line 867 | matrixIndex, transposeIndex */
        "xorl $2, %edi\n" /* transposeIndex */
        "cmpb $0, 0x100(%edi, %eax)\n" /* line 868 | transposeIndex */
        "jne .Lff7dca_000f8697\n"
        "movl %esi, %edx\n" /* line 875 | matrixIndex */
        "xorl $1, %edx\n"
        "movl -0x130(%ebp), %ecx\n" /* line 876 | codeMatrix, rowCount */
        "cmpb $0, 0x100(%edx, %ecx)\n"
        "je .Lff7dca_000f863e\n"
        "movl %esi, %eax\n" /* line 878 | matrixIndex */
        "shll $6, %eax\n"
        "addl %ecx, %eax\n" /* rowCount */
        "movl %eax, 4(%esp)\n"
        "shll $6, %edx\n"
        "movl %ecx, %eax\n" /* rowCount */
        "addl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixInverse44\n"
        "movl -0x130(%ebp), %eax\n" /* line 879 | codeMatrix */
        "movb $1, 0x100(%esi, %eax)\n" /* matrixIndex */
        ".Lff7dca_000f7ea9:\n"
        "movl -0x13c(%ebp), %edx\n" /* line 894 */
        "leal (%edx, %esi, 4), %eax\n"
        "shll $4, %eax\n"
        "addl -0x130(%ebp), %eax\n" /* codeMatrix */
        /* } scope */
        "addl $0x14c, %esp\n" /* line 895 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: OGLWorld, OGLView, OGLWorldView, OGLProjection, ... */
        ".Lff7dca_000f7ec6:\n"
        "movl -0x134(%ebp), %edx\n" /* line 733 | activeMatrices */
        "addl $0x230, %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* codeMatrix */
        "movl %edx, %eax\n"
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7edf:\n"
        "movl -0x134(%ebp), %ecx\n" /* line 737 | activeMatrices, rowCount */
        "addl $0x340, %ecx\n" /* rowCount */
        "movl %ecx, -0x130(%ebp)\n" /* rowCount, codeMatrix */
        "movl %ecx, %eax\n" /* rowCount */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7ef8:\n"
        "movl -0x134(%ebp), %eax\n" /* line 741 | activeMatrices */
        "addl $0x450, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 742 */
        "jne .Lff7dca_000f7e42\n"
        "movl %eax, 8(%esp)\n" /* line 744 */
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "addl $0x230, %eax\n"
        ".Lff7dca_000f7f25:\n"
        "movl %eax, 4(%esp)\n" /* line 835 */
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "addl $0x10, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %edx\n" /* line 836 | codeMatrix */
        "movb $1, 0x100(%edx)\n"
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7f52:\n"
        "movl -0x134(%ebp), %ecx\n" /* line 750 | activeMatrices, rowCount */
        "addl $0x670, %ecx\n" /* rowCount */
        "movl %ecx, -0x130(%ebp)\n" /* rowCount, codeMatrix */
        "cmpb $0, 0x100(%ecx)\n" /* line 751 | rowCount */
        "je .Lff7dca_000f85a0\n"
        ".Lff7dca_000f7f71:\n"
        "movl %ecx, %eax\n" /* rowCount */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7f78:\n"
        "movl -0x134(%ebp), %edx\n" /* line 759 | activeMatrices */
        "addl $0x780, %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%edx)\n" /* line 760 */
        "jne .Lff7dca_000f856a\n"
        "movl -0x134(%ebp), %ecx\n" /* line 762 | activeMatrices, rowCount */
        "cmpb $0, 0x550(%ecx)\n" /* rowCount */
        "je .Lff7dca_000f86cc\n"
        "leal 0x450(%ecx), %ebx\n" /* rowCount */
        "movl %ecx, %eax\n" /* rowCount */
        ".Lff7dca_000f7fb2:\n"
        "movl -0x130(%ebp), %ecx\n" /* line 767 | codeMatrix, rowCount */
        "movl %ecx, 8(%esp)\n" /* rowCount */
        "addl $0x340, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %eax\n" /* line 768 | codeMatrix */
        "movb $1, 0x100(%eax)\n"
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7fe5:\n"
        "movl -0x134(%ebp), %edx\n" /* line 774 | activeMatrices */
        "addl $0xcd0, %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* codeMatrix */
        /* { scope 2 */
        "movl $4, %ecx\n" /* line 778 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xbc, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "leal -0x68(%ebp), %ebx\n" /* OGLWorld */
        "movl (%eax), %edx\n"
        "movl %edx, -0x68(%ebp)\n" /* OGLWorld */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x64(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x50(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl $4, %ecx\n" /* line 780 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xc0, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "leal -0xa8(%ebp), %ecx\n" /* OGLView, rowCount */
        "movl (%eax), %edx\n"
        "movl %edx, -0xa8(%ebp)\n" /* OGLView */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0xa4(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0xa0(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x9c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x98(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x94(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x90(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x8c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x88(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x84(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0x78(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0x74(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movss lightGridLookupMatrix+368, %xmm1\n" /* line 782 */
        "movss -0xa0(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n"
        "movss -0x90(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "movss -0x70(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "leal -0xe8(%ebp), %esi\n" /* line 784 | OGLWorldView, matrixIndex */
        "movl %esi, 8(%esp)\n" /* matrixIndex */
        "movl %ecx, 4(%esp)\n" /* rowCount */
        "movl %ebx, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl $4, %ecx\n" /* line 786 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xc4, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "leal -0x128(%ebp), %ebx\n" /* OGLProjection */
        "movl (%eax), %edx\n"
        "movl %edx, -0x128(%ebp)\n" /* OGLProjection */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x124(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x120(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x11c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x118(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x114(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x110(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x10c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x108(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x104(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x100(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0xfc(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0xf8(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0xf4(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0xf0(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0xec(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* line 789 | viewport */
        "movl %eax, (%esp)\n"
        "calll RB_GetViewport\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm0\n" /* line 790 */
        "movss %xmm0, 8(%esp)\n"
        "cvtsi2ssl -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL\n"
        "movl -0x130(%ebp), %ecx\n" /* line 792 | codeMatrix, rowCount */
        "movl %ecx, 8(%esp)\n" /* rowCount */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* matrixIndex */
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %eax\n" /* line 793 | codeMatrix */
        "movb $1, 0x100(%eax)\n"
        "movb $0, 0x101(%eax)\n" /* line 794 */
        "movb $0, 0x102(%eax)\n" /* line 795 */
        "movb $0, 0x103(%eax)\n" /* line 796 */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        /* } scope */
        ".Lff7dca_000f826e:\n"
        "movl -0x134(%ebp), %eax\n" /* line 822 | activeMatrices */
        "addl $0x560, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 823 */
        "jne .Lff7dca_000f7e42\n"
        "movl $4, %ecx\n" /* line 825 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xd0, %eax\n"
        ".Lff7dca_000f8298:\n"
        "calll RB_GetCodeMatrix\n" /* line 815 */
        "movss lit4_002ed5d0, %xmm1\n" /* line 816 | 1.0f, scale */
        "movl -0x134(%ebp), %edx\n" /* activeMatrices */
        "divss (%edx), %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 691 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, 0x560(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 692 */
        "mulss 4(%eax), %xmm0\n"
        "movl -0x130(%ebp), %ecx\n" /* codeMatrix */
        "movss %xmm0, 4(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 693 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "movl 0xc(%eax), %edx\n" /* line 694 */
        ".Lff7dca_000f82e1:\n"
        "movl %edx, 0xc(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 695 */
        "mulss 0x10(%eax), %xmm0\n"
        "movss %xmm0, 0x10(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 696 */
        "mulss 0x14(%eax), %xmm0\n"
        "movss %xmm0, 0x14(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 697 */
        "mulss 0x18(%eax), %xmm0\n"
        "movss %xmm0, 0x18(%ecx)\n"
        "movl 0x1c(%eax), %edx\n" /* line 698 */
        "movl %edx, 0x1c(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 699 */
        "mulss 0x20(%eax), %xmm0\n"
        "movss %xmm0, 0x20(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 700 */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, 0x24(%ecx)\n"
        "mulss 0x28(%eax), %xmm1\n" /* line 701 */
        "movss %xmm1, 0x28(%ecx)\n"
        "movl 0x2c(%eax), %edx\n" /* line 702 */
        "movl %edx, 0x2c(%ecx)\n"
        "movl 0x30(%eax), %edx\n" /* line 703 */
        "movl %edx, 0x30(%ecx)\n"
        "movl 0x34(%eax), %edx\n" /* line 704 */
        "movl %edx, 0x34(%ecx)\n"
        "movl 0x38(%eax), %edx\n" /* line 705 */
        "movl %edx, 0x38(%ecx)\n"
        "movl 0x3c(%eax), %eax\n" /* line 706 */
        "movl %eax, 0x3c(%ecx)\n"
        /* } scope */
        "movb $1, 0x100(%ecx)\n" /* line 817 | rowCount */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f8365:\n"
        "movl -0x134(%ebp), %eax\n" /* line 832 | activeMatrices */
        "addl $0x9a0, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 833 */
        "jne .Lff7dca_000f7e42\n"
        "movl %eax, 8(%esp)\n" /* line 835 */
        "leal 0x36e48(%ebx), %eax\n"
        "jmp .Lff7dca_000f7f25\n"
        ".Lff7dca_000f8392:\n"
        "movl -0x134(%ebp), %ecx\n" /* line 841 | activeMatrices, rowCount */
        "addl $0xab0, %ecx\n" /* rowCount */
        "movl %ecx, -0x130(%ebp)\n" /* rowCount, codeMatrix */
        "cmpb $0, 0x100(%ecx)\n" /* line 842 | rowCount */
        "jne .Lff7dca_000f7f71\n"
        "movl $4, %ecx\n" /* line 844 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xbf, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movl -0x130(%ebp), %edx\n" /* line 845 | codeMatrix */
        "movl %edx, 8(%esp)\n"
        "movl $lightGridLookupMatrix, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %ecx\n" /* line 846 | codeMatrix, rowCount */
        "movb $1, 0x100(%ecx)\n" /* rowCount */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f83f4:\n"
        "movl -0x134(%ebp), %eax\n" /* line 851 | activeMatrices */
        "addl $0xbc0, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 852 */
        "jne .Lff7dca_000f7e42\n"
        /* { scope 2 */
        "movl imp_r_outdoorAwayBias, %eax\n" /* line 932 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* awayBias */
        "movl imp_r_outdoorDownBias, %eax\n" /* line 933 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x12c(%ebp)\n" /* downBias */
        "movl $4, %ecx\n" /* line 936 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xbc, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movl %eax, %edi\n" /* worldMatrix */
        "movl $4, %ecx\n" /* line 937 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xc1, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "xorl %edx, %edx\n" /* line 447 */
        "movl %edx, -0xa8(%ebp)\n" /* OGLView */
        "movl %edx, -0xa4(%ebp)\n" /* line 448 */
        "xorl $0x80000000, %ebx\n" /* line 449 */
        "movl %ebx, -0xa0(%ebp)\n"
        "movl %edx, -0x9c(%ebp)\n" /* line 450 */
        "leal -0x68(%ebp), %esi\n" /* line 939 | OGLWorld, matrixIndex */
        "movl %esi, 8(%esp)\n" /* matrixIndex */
        "movl %eax, 4(%esp)\n"
        "leal -0xa8(%ebp), %eax\n" /* OGLView */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector44\n"
        "movss -0x12c(%ebp), %xmm0\n" /* line 940 | downBias */
        "addss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* line 942 | viewport */
        "movl %eax, 8(%esp)\n"
        "movl imp_rgp, %ebx\n" /* awayBias */
        "movl 0x109c(%ebx), %eax\n" /* awayBias */
        "addl $0x1c0, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* matrixIndex */
        "calll MatrixTransformVector44\n"
        "movl -0x130(%ebp), %eax\n" /* line 943 | codeMatrix */
        "movl %eax, 8(%esp)\n"
        "movl 0x109c(%ebx), %eax\n" /* awayBias */
        "addl $0x1c0, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* worldMatrix */
        "calll MatrixMultiply44\n"
        "movl -0x134(%ebp), %eax\n" /* line 944 | activeMatrices, sum */
        "addl $0xbf0, %eax\n" /* sum */
        /* { scope 3 */
        "movl -0x134(%ebp), %edx\n" /* line 483 | activeMatrices */
        "movss 0xbf0(%edx), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n" /* viewport */
        "movss %xmm0, 0xbf0(%edx)\n"
        "movss 4(%eax), %xmm0\n" /* line 484 */
        "addss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%eax), %xmm0\n" /* line 485 */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movss 0xc(%eax), %xmm0\n" /* line 486 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        /* } scope */
        /* } scope */
        "movl -0x130(%ebp), %ecx\n" /* line 855 | codeMatrix, rowCount */
        "movb $1, 0x100(%ecx)\n" /* rowCount */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f854f:\n"
        "movl -0x134(%ebp), %edx\n" /* line 802 | activeMatrices */
        "addl $0x120, %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%edx)\n" /* line 803 */
        "je .Lff7dca_000f85de\n"
        ".Lff7dca_000f856a:\n"
        "movl %edx, %eax\n"
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f8571:\n"
        "movl -0x134(%ebp), %eax\n" /* line 812 | activeMatrices */
        "addl $0x560, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 813 */
        "jne .Lff7dca_000f7e42\n"
        "movl $4, %ecx\n" /* line 815 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xc8, %eax\n"
        "jmp .Lff7dca_000f8298\n"
        ".Lff7dca_000f85a0:\n"
        "movl %ecx, 8(%esp)\n" /* line 753 | rowCount */
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "addl $0x340, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "addl $0x230, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %eax\n" /* line 754 | codeMatrix */
        "movb $1, 0x100(%eax)\n"
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f85de:\n"
        "movl $4, %ecx\n" /* line 805 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xbc, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 806 | 1.0f, scale */
        "movl -0x134(%ebp), %ecx\n" /* activeMatrices, rowCount */
        "divss (%ecx), %xmm1\n" /* rowCount, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 691 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, 0x120(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 692 */
        "mulss 4(%eax), %xmm0\n"
        "movl -0x130(%ebp), %edx\n" /* codeMatrix */
        "movss %xmm0, 4(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 693 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movl 0xc(%eax), %edx\n" /* line 694 */
        "movl -0x130(%ebp), %ecx\n" /* codeMatrix */
        "jmp .Lff7dca_000f82e1\n"
        /* } scope */
        ".Lff7dca_000f863e:\n"
        "movl %edi, %ebx\n" /* line 885 | transposeIndex */
        "shll $6, %ebx\n"
        "addl -0x130(%ebp), %ebx\n" /* codeMatrix */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, %eax\n" /* matrixIndex */
        "xorl $3, %eax\n"
        "shll $6, %eax\n"
        "addl -0x130(%ebp), %eax\n" /* codeMatrix */
        "movl %eax, (%esp)\n"
        "calll MatrixTranspose44\n"
        "movl -0x130(%ebp), %edx\n" /* line 886 | codeMatrix */
        "movb $1, 0x100(%edi, %edx)\n" /* transposeIndex */
        "movl %esi, %eax\n" /* line 887 | matrixIndex */
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MatrixInverse44\n"
        "movl -0x130(%ebp), %ecx\n" /* line 888 | codeMatrix, rowCount */
        "movb $1, 0x100(%esi, %ecx)\n" /* matrixIndex */
        "jmp .Lff7dca_000f7ea9\n"
        ".Lff7dca_000f8697:\n"
        "movl %esi, %eax\n" /* line 870 | matrixIndex */
        "shll $6, %eax\n"
        "addl -0x130(%ebp), %eax\n" /* codeMatrix */
        "movl %eax, 4(%esp)\n"
        "shll $6, %edi\n" /* transposeIndex */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "addl %edi, %eax\n" /* transposeIndex */
        "movl %eax, (%esp)\n"
        "calll MatrixTranspose44\n"
        "movl -0x130(%ebp), %edx\n" /* line 871 | codeMatrix */
        "movb $1, 0x100(%esi, %edx)\n" /* matrixIndex */
        "jmp .Lff7dca_000f7ea9\n"
        ".Lff7dca_000f86cc:\n"
        "movl %ecx, %ebx\n" /* line 764 | rowCount */
        "addl $0x450, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ecx, %eax\n" /* rowCount */
        "addl $0x230, %eax\n"
        "movl %eax, 4(%esp)\n"
        "subl $0x220, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x134(%ebp), %eax\n" /* line 765 | activeMatrices */
        "movb $1, 0x550(%eax)\n"
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "jmp .Lff7dca_000f7fb2\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_f7dca_0:\n"
        ".long .Lff7dca_000f7e33\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7ec6\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7edf\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7ef8\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7f52\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7f78\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7fe5\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f854f\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f8571\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f826e\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f8365\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f8392\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f83f4\n"
        ".text\n"
    );
}
#endif

/* line 1439 — D3D shader technique application: iterates technique passes,
 * sets vertex declarations, pixel/vertex shaders, sampler states, render states,
 * code textures/constants, then issues DrawIndexedPrimitive calls.
 * 1836 lines of ASM — the largest function in the codebase.
 * MUST remain naked: register calling convention (eax=vertDeclType, edx=args, ecx=stateOverride)
 * and 30+ D3D COM vtable calls with complex state management make C conversion impractical. */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void RB_DrawSingleTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args, const GfxStateOverride *stateOverride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1439 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18c, %esp\n"
        "movl %edx, -0xdc(%ebp)\n"
        "movl %ecx, -0xe0(%ebp)\n"
        /* { scope 1: pass, stateBits */
        "movl imp_tess, %esi\n" /* line 1444 | constantIndex */
        "movl 0x5a7bc(%esi), %edx\n" /* constantIndex */
        "movl 0x38(%edx), %edx\n"
        "movl 4(%edx, %eax, 4), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "cmpl $0x21, %eax\n" /* line 1450 | techType */
        "je .Lff8708_000f9b4b\n"
        ".Lff8708_000f873f:\n"
        "movl imp_g_special, %eax\n" /* line 1457 | techType */
        "cmpl $3, -0xdc(%ebp)\n"
        "sete (%eax)\n" /* techType */
        "cmpw $0, 6(%edx)\n" /* line 1459 */
        "je .Lff8708_000f9175\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl $0, -0xd8(%ebp)\n" /* passIndex */
        "movl imp_r_rendererInUse, %eax\n" /* line 1429 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lff8708_000f8d5f\n"
        ".Lff8708_000f8777:\n"
        "movl -0xd8(%ebp), %eax\n" /* line 1436 | passIndex */
        "shll $2, %eax\n"
        "movl -0xd8(%ebp), %edx\n" /* passIndex */
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl -0x3c(%ebp), %ebx\n" /* fvf */
        "addl %edx, %ebx\n" /* fvf */
        "leal 8(%ebx), %eax\n" /* fvf */
        "movl %eax, -0xc0(%ebp)\n" /* pass */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "movl %eax, %edx\n" /* line 1273 */
        "movl 4(%eax), %eax\n"
        "movl -0xdc(%ebp), %ecx\n"
        "movl 8(%eax, %ecx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9b02\n"
        ".Lff8708_000f87b0:\n"
        "movl 0x5a7bc(%esi), %esi\n" /* line 1279 | constantIndex */
        "addl $0x2c, %esi\n" /* constantIndex */
        "movl %esi, -0xb8(%ebp)\n" /* constantIndex, refStateBits */
        "movl 8(%ebx), %ebx\n" /* codeConst */
        "movl %ebx, -0x44(%ebp)\n" /* codeConst */
        "movl $1, %edx\n"
        "movl %esi, %ebx\n" /* constantIndex, codeConst */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        ".Lff8708_000f87cc:\n"
        "movl -4(%ebx, %edx, 4), %eax\n" /* line 1247 | codeConst */
        "movl %eax, -0x2c(%ebp, %edx, 4)\n"
        "addl $1, %edx\n"
        "cmpl $3, %edx\n" /* line 1246 */
        "jne .Lff8708_000f91e8\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl $0, -0xbc(%ebp)\n" /* ruleSetIndex */
        "movl %eax, %edx\n"
        "movl 4(%edx), %eax\n" /* line 1251 | ruleSet */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        "movl (%eax), %esi\n" /* line 1219 | constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jle .Lff8708_000f8c62\n"
        ".Lff8708_000f87ff:\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 1223 | refStateBits */
        "movl (%ecx), %edi\n"
        "xorl %ecx, %ecx\n"
        "movl %eax, %edx\n"
        "jmp .Lff8708_000f881b\n"
        ".Lff8708_000f880d:\n"
        "addl $1, %ecx\n" /* line 1219 */
        "addl $0x20, %edx\n"
        "cmpl %esi, %ecx\n" /* constantIndex */
        "je .Lff8708_000f8c62\n"
        ".Lff8708_000f881b:\n"
        "leal 4(%edx), %ebx\n" /* line 1221 | codeConst */
        "movl %ebx, -0x170(%ebp)\n" /* codeConst, rule */
        "movl %edi, %eax\n" /* line 1223 */
        "andl 4(%edx), %eax\n"
        "cmpl 0xc(%edx), %eax\n"
        "jne .Lff8708_000f880d\n"
        "movl -0xb8(%ebp), %ebx\n" /* refStateBits, codeConst */
        "movl 4(%ebx), %eax\n" /* codeConst */
        "andl 8(%edx), %eax\n"
        "cmpl 0x10(%edx), %eax\n"
        "jne .Lff8708_000f880d\n"
        "movl -0x170(%ebp), %ecx\n" /* rule */
        "movl $1, %ebx\n" /* codeConst */
        "leal -0x28(%ebp), %edx\n" /* stateBits */
        "addl $4, %edx\n"
        ".Lff8708_000f8850:\n"
        "movl -4(%edx), %eax\n" /* line 1227 */
        "andl 0x18(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "orl 0x10(%ecx), %eax\n" /* line 1228 */
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n" /* codeConst */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* line 1225 | codeConst */
        "jne .Lff8708_000f8850\n"
        /* } scope */
        /* } scope */
        "addl $1, -0xbc(%ebp)\n" /* line 1249 | ruleSetIndex */
        "addl $4, -0x50(%ebp)\n"
        "cmpl $0xb, -0xbc(%ebp)\n" /* ruleSetIndex */
        "jne .Lff8708_000f8cb2\n"
        /* } scope */
        ".Lff8708_000f8885:\n"
        "movl 8(%ebp), %eax\n" /* line 1281 | stateOverride */
        "testl %eax, %eax\n"
        "je .Lff8708_000f88b3\n"
        "movl 8(%ebp), %ecx\n" /* stateOverride */
        "movl $1, %ebx\n" /* codeConst */
        "leal -0x28(%ebp), %edx\n" /* stateBits */
        "addl $4, %edx\n"
        ".Lff8708_000f889a:\n"
        "movl -4(%edx), %eax\n" /* line 1285 */
        "andl (%ecx), %eax\n"
        "orl 8(%ecx), %eax\n" /* line 1286 */
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n" /* codeConst */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* line 1283 | codeConst */
        "jne .Lff8708_000f889a\n"
        ".Lff8708_000f88b3:\n"
        "movl imp_backEnd, %eax\n" /* line 1290 */
        "cmpb $0, 0x4bd(%eax)\n"
        "je .Lff8708_000f88c5\n"
        "andl $0xffffffcf, -0x24(%ebp)\n" /* line 1291 */
        ".Lff8708_000f88c5:\n"
        "movl -0x28(%ebp), %eax\n" /* line 155 | stateBits */
        "movl imp_dxState, %esi\n"
        "cmpl 0x2000(%esi), %eax\n"
        "je .Lff8708_000f88e7\n"
        "movl %eax, (%esp)\n" /* line 158 */
        "calll RB_ChangeState_0\n"
        "movl -0x28(%ebp), %eax\n" /* line 160 | stateBits */
        "movl %eax, 0x2000(%esi)\n"
        ".Lff8708_000f88e7:\n"
        "movl -0x24(%ebp), %eax\n" /* line 163 */
        "cmpl 0x2004(%esi), %eax\n"
        "je .Lff8708_000f8903\n"
        "movl %eax, (%esp)\n" /* line 166 */
        "calll RB_ChangeState_1\n"
        "movl -0x24(%ebp), %eax\n" /* line 168 */
        "movl %eax, 0x2004(%esi)\n"
        ".Lff8708_000f8903:\n"
        "movl $0, (%esp)\n" /* line 1304 */
        "calll RB_UpdateFogColor\n"
        "movl -0xc0(%ebp), %ecx\n" /* line 1306 | pass */
        "movl 0xc(%ecx), %eax\n"
        "movl 0xc(%eax), %ebx\n" /* shader */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        "cmpl 0x2138(%esi), %ebx\n" /* line 227 */
        "je .Lff8708_000f97d0\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lff8708_000f8933:\n"
        "movl 8(%edi), %eax\n" /* line 231 */
        "movl (%eax), %edx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1ac(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f8933\n"
        "movl imp_dxState, %edx\n" /* line 232 */
        "movl %ebx, 0x2138(%edx)\n"
        /* } scope */
        ".Lff8708_000f8957:\n"
        "movl -0xc0(%ebp), %ebx\n" /* line 1307 | pass, shader */
        "movl 8(%ebx), %eax\n" /* shader */
        "movl 0xc(%eax), %ebx\n" /* shader */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        "cmpl 0x213c(%edx), %ebx\n" /* line 240 */
        "je .Lff8708_000f899b\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lff8708_000f8977:\n"
        "movl 8(%edi), %eax\n" /* line 244 */
        "movl (%eax), %edx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x170(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f8977\n"
        "movl imp_dxState, %edx\n" /* line 245 */
        "movl %ebx, 0x213c(%edx)\n"
        /* } scope */
        ".Lff8708_000f899b:\n"
        "movl -0xc0(%ebp), %ecx\n" /* line 1308 | pass */
        "movl 4(%ecx), %eax\n"
        "movl -0xdc(%ebp), %ecx\n"
        "movl 8(%eax, %ecx, 4), %ebx\n" /* decl */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        "cmpl 0x2140(%edx), %ebx\n" /* line 256 */
        "je .Lff8708_000f89ef\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lff8708_000f89c2:\n"
        "movl 8(%edi), %eax\n" /* line 260 */
        "movl (%eax), %edx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x15c(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f89c2\n"
        "movl imp_dxState, %eax\n" /* line 261 */
        "movl %ebx, 0x2140(%eax)\n"
        "movl $0, 0x2144(%eax)\n" /* line 262 */
        /* } scope */
        ".Lff8708_000f89ef:\n"
        "movl -0xc0(%ebp), %ebx\n" /* line 1310 | pass, decl */
        "movzwl 0x10(%ebx), %ebx\n" /* decl */
        "movl %ebx, -0xb4(%ebp)\n" /* decl, routingCount */
        "movl -0xc0(%ebp), %eax\n" /* pass */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        "testl %ebx, %ebx\n" /* line 1131 | textureIndex */
        "jle .Lff8708_000f8c18\n"
        "movl $0, -0xb0(%ebp)\n" /* routingIndex */
        "movl imp_dx, %edx\n"
        "movl %edx, -0xf0(%ebp)\n"
        "movl imp_alwaysfails, %ecx\n"
        "movl %ecx, -0xf4(%ebp)\n"
        "movl %edx, -0xf8(%ebp)\n"
        "movl %ecx, -0xfc(%ebp)\n"
        "jmp .Lff8708_000f8aaf\n"
        ".Lff8708_000f8a43:\n"
        "movl -0x40(%ebp), %edx\n" /* line 1136 */
        "movl 4(%edx), %ebx\n" /* data */
        "movzwl 2(%edx), %ecx\n"
        "movl %ecx, -0xa4(%ebp)\n" /* destIndex */
        /* { scope 6 */
        "shll $4, %ecx\n" /* line 996 */
        "movl imp_dxState, %eax\n"
        "addl %eax, %ecx\n"
        "movl %ecx, -0x174(%ebp)\n"
        "movl $0x10, -0xe8(%ebp)\n"
        "cld\n"
        "movl %ecx, %esi\n" /* constantIndex */
        "movl %ebx, %edi\n" /* textureIndex */
        "movl $0x10, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f8a8a\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f8a8a:\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f969d\n"
        /* } scope */
        ".Lff8708_000f8a92:\n"
        "addl $8, -0x40(%ebp)\n" /* line 1158 */
        "addl $1, -0xb0(%ebp)\n" /* line 1131 | routingIndex */
        "movl -0xb0(%ebp), %eax\n" /* routingIndex */
        "cmpl %eax, -0xb4(%ebp)\n" /* routingCount */
        "je .Lff8708_000f8c18\n"
        ".Lff8708_000f8aaf:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 1133 | textureIndex */
        "movzwl (%ebx), %eax\n" /* textureIndex */
        "cmpw $1, %ax\n"
        "je .Lff8708_000f91f3\n"
        "jb .Lff8708_000f8a43\n"
        "cmpw $2, %ax\n"
        "jne .Lff8708_000f8a92\n"
        "movl -0x40(%ebp), %eax\n" /* line 1145 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x98(%ebp)\n" /* literalName */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_tess, %edx\n" /* line 971 */
        "movl 0x5a7bc(%edx), %eax\n"
        "movzwl 0x36(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff8708_000f8b27\n"
        "movl 0x40(%eax), %ecx\n" /* line 973 */
        "movl -0x98(%ebp), %eax\n" /* line 974 | literalName */
        "cmpl (%ecx), %eax\n"
        "je .Lff8708_000f8b14\n"
        "leal 0x14(%ecx), %ebx\n" /* textureIndex */
        "movl %ebx, %edx\n" /* textureIndex */
        "xorl %esi, %esi\n" /* constantIndex */
        ".Lff8708_000f8afb:\n"
        "addl $1, %esi\n" /* line 971 | constantIndex */
        "cmpl %edi, %esi\n" /* constantIndex */
        "je .Lff8708_000f8b27\n"
        "movl %ebx, %ecx\n" /* textureIndex */
        "movl (%edx), %eax\n" /* line 974 */
        "leal 0x14(%ebx), %ebx\n" /* textureIndex */
        "addl $0x14, %edx\n"
        "cmpl %eax, -0x98(%ebp)\n" /* literalName */
        "jne .Lff8708_000f8afb\n"
        ".Lff8708_000f8b14:\n"
        "addl $4, %ecx\n" /* line 976 */
        "movl %ecx, -0xa8(%ebp)\n" /* data */
        "movl $1, -0xac(%ebp)\n" /* rowCount */
        /* } scope */
        /* } scope */
        ".Lff8708_000f8b27:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 1146 */
        "movzwl 2(%ecx), %ecx\n"
        "movl %ecx, -0x94(%ebp)\n" /* destIndex */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_r_logFile, %eax\n" /* line 991 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f8b59\n"
        "movl -0xac(%ebp), %ecx\n" /* line 993 | rowCount */
        "testl %ecx, %ecx\n"
        "jle .Lff8708_000f8b59\n"
        "xorl %eax, %eax\n" /* line 991 */
        ".Lff8708_000f8b4e:\n"
        "addl $1, %eax\n" /* line 993 */
        "cmpl -0xac(%ebp), %eax\n" /* rowCount */
        "jne .Lff8708_000f8b4e\n"
        ".Lff8708_000f8b59:\n"
        "movl -0xac(%ebp), %ebx\n" /* line 996 | rowCount, textureIndex */
        "shll $4, %ebx\n" /* textureIndex */
        "movl -0x94(%ebp), %eax\n" /* destIndex */
        "shll $4, %eax\n"
        "movl imp_dxState, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x90(%ebp)\n"
        "cld\n"
        "cmpl %ebx, %ebx\n" /* textureIndex */
        "movl %eax, %esi\n" /* constantIndex */
        "movl -0xa8(%ebp), %edi\n" /* data */
        "movl %ebx, %ecx\n" /* textureIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f8b99\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f8b99:\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f8a92\n"
        "movl %ebx, 8(%esp)\n" /* line 998 | textureIndex */
        "movl -0xa8(%ebp), %ecx\n" /* data */
        "movl %ecx, 4(%esp)\n"
        "movl -0x90(%ebp), %ebx\n" /* textureIndex */
        "movl %ebx, (%esp)\n" /* textureIndex */
        "calll memcpy\n"
        ".Lff8708_000f8bbd:\n"
        "movl -0xf8(%ebp), %edx\n" /* line 999 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl -0xac(%ebp), %ecx\n" /* rowCount */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xa8(%ebp), %ebx\n" /* data, textureIndex */
        "movl %ebx, 8(%esp)\n" /* textureIndex */
        "movl -0x94(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x178(%edx)\n"
        "movl -0xfc(%ebp), %ebx\n" /* textureIndex */
        "movl (%ebx), %eax\n" /* textureIndex */
        "testl %eax, %eax\n"
        "jne .Lff8708_000f8bbd\n"
        /* } scope */
        /* } scope */
        "addl $8, -0x40(%ebp)\n" /* line 1158 */
        "addl $1, -0xb0(%ebp)\n" /* line 1131 | routingIndex */
        "movl -0xb0(%ebp), %eax\n" /* routingIndex */
        "cmpl %eax, -0xb4(%ebp)\n" /* routingCount */
        "jne .Lff8708_000f8aaf\n"
        /* } scope */
        /* } scope */
        ".Lff8708_000f8c18:\n"
        "movl -0xc0(%ebp), %edx\n" /* line 1311 | pass */
        "movzwl 0x12(%edx), %edx\n"
        "movl %edx, -0x8c(%ebp)\n" /* routingCount */
        "movl -0xc0(%ebp), %ecx\n" /* pass */
        "movl 0x18(%ecx), %ecx\n"
        "movl %ecx, -0x88(%ebp)\n" /* routingData */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        "testl %edx, %edx\n" /* line 1173 */
        "jle .Lff8708_000f90fc\n"
        "movl $0, -0x84(%ebp)\n" /* routingIndex */
        ".Lff8708_000f8c49:\n"
        "movl -0x88(%ebp), %ebx\n" /* line 1175 | routingData, codeConst */
        "movzwl (%ebx), %eax\n" /* codeConst */
        "cmpl $4, %eax\n"
        "ja .Lff8708_000f9357\n"
        "jmpl *.Ljt_f8708_0(, %eax, 4)\n"
        /* } scope */
        /* } scope */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        ".Lff8708_000f8c62:\n"
        "movl imp_tess, %eax\n" /* line 1252 */
        "movl 0x5a7bc(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0xbc(%ebp), %eax\n" /* ruleSetIndex */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00226858, 4(%esp)\n" /* "No rule in stateMap '%s' rule set %i matched the current mat" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        "addl $1, -0xbc(%ebp)\n" /* line 1249 | ruleSetIndex */
        "addl $4, -0x50(%ebp)\n"
        "cmpl $0xb, -0xbc(%ebp)\n" /* ruleSetIndex */
        "je .Lff8708_000f8885\n"
        ".Lff8708_000f8cb2:\n"
        "movl -0x50(%ebp), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1251 | ruleSet */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        "movl (%eax), %esi\n" /* line 1219 | constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jg .Lff8708_000f87ff\n"
        "jmp .Lff8708_000f8c62\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f8cc4:\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 1464 | fvf */
        "cmpb $0, 0xd(%ebx)\n" /* fvf */
        "je .Lff8708_000f910d\n"
        "movl $0, (%esp)\n" /* line 1466 */
        "calll RB_SetViewMatrixForWDx7\n"
        "movl imp_backEnd, %eax\n" /* line 75 */
        "cmpb $0, 0x4bd(%eax)\n"
        "jne .Lff8708_000f9bf2\n"
        "movl -0xe0(%ebp), %eax\n" /* line 77 */
        "movl 8(%eax), %ebx\n"
        "movl imp_r_drawPrimFloor, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n"
        "jl .Lff8708_000f8d1e\n"
        "movl imp_r_drawPrimCap, %eax\n" /* line 79 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9aa6\n"
        "cmpl %eax, %ebx\n"
        "jle .Lff8708_000f9aa6\n"
        ".Lff8708_000f8d1e:\n"
        "movl $0x3f800000, (%esp)\n" /* line 1468 */
        "calll RB_SetViewMatrixForWDx7\n"
        ".Lff8708_000f8d2a:\n"
        "addl $1, -0xd8(%ebp)\n" /* line 1459 | passIndex */
        "addl $0x5c, -0x4c(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movzwl 6(%edx), %eax\n" /* techType */
        "cmpl %eax, -0xd8(%ebp)\n" /* techType, passIndex */
        "jge .Lff8708_000f9170\n"
        ".Lff8708_000f8d48:\n"
        "movl imp_tess, %esi\n" /* constantIndex */
        "movl imp_r_rendererInUse, %eax\n" /* line 1429 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lff8708_000f8777\n"
        ".Lff8708_000f8d5f:\n"
        "movl -0xd8(%ebp), %ecx\n" /* line 1431 | passIndex */
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %ecx, %eax\n"
        "movl -0x3c(%ebp), %ebx\n" /* fvf */
        "leal (%ebx, %eax, 4), %eax\n" /* fvf */
        "leal 8(%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        "movl 0x5a7bc(%esi), %esi\n" /* line 1372 | constantIndex */
        "addl $0x2c, %esi\n" /* constantIndex */
        "movl %esi, -0xcc(%ebp)\n" /* constantIndex, refStateBits */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0xd4(%ebp)\n" /* stateMap */
        "movl $1, %edx\n"
        "movl %esi, %ecx\n" /* constantIndex */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        ".Lff8708_000f8d98:\n"
        "movl -4(%ecx, %edx, 4), %eax\n" /* line 1247 */
        "movl %eax, -0x2c(%ebp, %edx, 4)\n"
        "addl $1, %edx\n"
        "cmpl $3, %edx\n" /* line 1246 */
        "jne .Lff8708_000f96f3\n"
        "movl -0xd4(%ebp), %ebx\n" /* stateMap, codeConst */
        "movl %ebx, -0x54(%ebp)\n" /* codeConst */
        "movl $0, -0xd0(%ebp)\n" /* ruleSetIndex */
        "movl %ebx, %edx\n" /* codeConst */
        "movl 4(%edx), %eax\n" /* line 1251 | ruleSet */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        "movl (%eax), %esi\n" /* line 1219 | constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jle .Lff8708_000f9183\n"
        ".Lff8708_000f8dce:\n"
        "movl -0xcc(%ebp), %ecx\n" /* line 1223 | refStateBits */
        "movl (%ecx), %edi\n"
        "xorl %ecx, %ecx\n"
        "movl %eax, %edx\n"
        "jmp .Lff8708_000f8dea\n"
        ".Lff8708_000f8ddc:\n"
        "addl $1, %ecx\n" /* line 1219 */
        "addl $0x20, %edx\n"
        "cmpl %ecx, %esi\n" /* constantIndex */
        "je .Lff8708_000f9183\n"
        ".Lff8708_000f8dea:\n"
        "leal 4(%edx), %ebx\n" /* line 1221 | codeConst */
        "movl %ebx, -0x170(%ebp)\n" /* codeConst, rule */
        "movl %edi, %eax\n" /* line 1223 */
        "andl 4(%edx), %eax\n"
        "cmpl 0xc(%edx), %eax\n"
        "jne .Lff8708_000f8ddc\n"
        "movl -0xcc(%ebp), %ebx\n" /* refStateBits, codeConst */
        "movl 4(%ebx), %eax\n" /* codeConst */
        "andl 8(%edx), %eax\n"
        "cmpl 0x10(%edx), %eax\n"
        "jne .Lff8708_000f8ddc\n"
        "movl -0x170(%ebp), %ecx\n" /* rule */
        "movl $1, %ebx\n" /* codeConst */
        "leal -0x28(%ebp), %edx\n" /* stateBits */
        "addl $4, %edx\n"
        ".Lff8708_000f8e1f:\n"
        "movl -4(%edx), %eax\n" /* line 1227 */
        "andl 0x18(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "orl 0x10(%ecx), %eax\n" /* line 1228 */
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n" /* codeConst */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* line 1225 | codeConst */
        "jne .Lff8708_000f8e1f\n"
        /* } scope */
        /* } scope */
        "addl $1, -0xd0(%ebp)\n" /* line 1249 | ruleSetIndex */
        "addl $4, -0x54(%ebp)\n"
        "cmpl $0xb, -0xd0(%ebp)\n" /* ruleSetIndex */
        "jne .Lff8708_000f91d6\n"
        /* } scope */
        /* } scope */
        ".Lff8708_000f8e54:\n"
        "movl 8(%ebp), %eax\n" /* line 1373 | stateOverride */
        "testl %eax, %eax\n"
        "je .Lff8708_000f8e82\n"
        "movl 8(%ebp), %ecx\n" /* stateOverride */
        "movl $1, %ebx\n" /* decl */
        "leal -0x28(%ebp), %edx\n" /* stateBits */
        "addl $4, %edx\n"
        ".Lff8708_000f8e69:\n"
        "movl -4(%edx), %eax\n" /* line 1377 */
        "andl (%ecx), %eax\n"
        "orl 8(%ecx), %eax\n" /* line 1378 */
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n" /* decl */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* line 1375 | decl */
        "jne .Lff8708_000f8e69\n"
        ".Lff8708_000f8e82:\n"
        "movl imp_backEnd, %eax\n" /* line 1381 */
        "cmpb $0, 0x4bd(%eax)\n"
        "je .Lff8708_000f8e94\n"
        "andl $0xffffffcf, -0x24(%ebp)\n" /* line 1382 */
        ".Lff8708_000f8e94:\n"
        "movl -0x28(%ebp), %eax\n" /* line 155 | stateBits */
        "movl imp_dxState, %ebx\n"
        "cmpl 0x2000(%ebx), %eax\n"
        "je .Lff8708_000f8eb6\n"
        "movl %eax, (%esp)\n" /* line 158 */
        "calll RB_ChangeState_0\n"
        "movl -0x28(%ebp), %eax\n" /* line 160 | stateBits */
        "movl %eax, 0x2000(%ebx)\n"
        ".Lff8708_000f8eb6:\n"
        "movl -0x24(%ebp), %eax\n" /* line 163 */
        "cmpl 0x2004(%ebx), %eax\n"
        "je .Lff8708_000f8ed2\n"
        "movl %eax, (%esp)\n" /* line 166 */
        "calll RB_ChangeState_1\n"
        "movl -0x24(%ebp), %eax\n" /* line 168 */
        "movl %eax, 0x2004(%ebx)\n"
        ".Lff8708_000f8ed2:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 1392 */
        "cmpb $1, 8(%ecx)\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_UpdateFogColor\n"
        "movl %ebx, %edx\n" /* line 1395 | decl */
        "movzbl 0x2094(%ebx), %eax\n" /* decl */
        "movl -0x48(%ebp), %ebx\n" /* decl */
        "cmpb 4(%ebx), %al\n" /* decl */
        "je .Lff8708_000f8f45\n"
        "movl imp_dx, %esi\n" /* constantIndex */
        "movl imp_alwaysfails, %ebx\n" /* decl */
        ".Lff8708_000f8f05:\n"
        "movl 8(%esi), %eax\n" /* line 1397 | constantIndex */
        "movl (%eax), %ecx\n"
        "movl -0x48(%ebp), %edx\n"
        "cmpb $0, 4(%edx)\n"
        "setne %dl\n"
        "movzbl %dl, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x89, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%ebx), %edi\n" /* decl */
        "testl %edi, %edi\n"
        "jne .Lff8708_000f8f05\n"
        "movl imp_dxState, %edx\n" /* line 1398 */
        "movl -0x48(%ebp), %ecx\n"
        "movzbl 4(%ecx), %eax\n"
        "movb %al, 0x2094(%edx)\n"
        ".Lff8708_000f8f45:\n"
        "movl -0xdc(%ebp), %eax\n" /* line 1402 */
        "movl s_fvfForVertDeclType(, %eax, 4), %ebx\n" /* fvf */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "movl 0x2140(%edx), %ecx\n" /* line 272 */
        "testl %ecx, %ecx\n"
        "je .Lff8708_000f9805\n"
        ".Lff8708_000f8f60:\n"
        "movl imp_dx, %eax\n" /* line 275 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n" /* to */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x164(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f8f60\n"
        "movl imp_dxState, %eax\n" /* line 276 */
        "movl %ebx, 0x2144(%eax)\n"
        "movl $0, 0x2140(%eax)\n" /* line 277 */
        /* } scope */
        "movl -0x48(%ebp), %edx\n" /* line 1404 */
        "cmpb $0, 7(%edx)\n"
        "jne .Lff8708_000f981e\n"
        ".Lff8708_000f8fa4:\n"
        "movl $0xffffffff, %ecx\n"
        ".Lff8708_000f8fa9:\n"
        "movl %ecx, (%esp)\n" /* line 1409 */
        "calll RB_SetSamplerConstantDx7\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl $0, -0xc4(%ebp)\n" /* samplerIndex */
        "movl imp_dxState, %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl %eax, -0x100(%ebp)\n"
        "movl %eax, %ecx\n"
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "cmpw $3, 0xc(%ecx)\n" /* line 1321 */
        "je .Lff8708_000f9747\n"
        ".Lff8708_000f8fdd:\n"
        "movl 0x10(%ecx), %eax\n" /* line 1328 */
        "movl %eax, -0xc8(%ebp)\n" /* textureName */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        "movl imp_tess, %eax\n" /* line 671 */
        "movl 0x5a7bc(%eax), %eax\n"
        "movzwl 0x34(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff8708_000f9795\n"
        "movl 0x3c(%eax), %esi\n" /* line 673 */
        "movl -0xc8(%ebp), %ebx\n" /* line 674 | textureName, textureIndex */
        "cmpl (%esi), %ebx\n" /* textureIndex */
        "je .Lff8708_000f902e\n"
        "leal 0xc(%esi), %ecx\n"
        "movl %ecx, %edx\n"
        "xorl %ebx, %ebx\n" /* textureIndex */
        ".Lff8708_000f9011:\n"
        "addl $1, %ebx\n" /* line 671 | textureIndex */
        "cmpl %edi, %ebx\n" /* textureIndex */
        "je .Lff8708_000f9795\n"
        "movl %ecx, %esi\n"
        "movl (%edx), %eax\n" /* line 674 */
        "leal 0xc(%ecx), %ecx\n"
        "addl $0xc, %edx\n"
        "cmpl %eax, -0xc8(%ebp)\n" /* textureName */
        "jne .Lff8708_000f9011\n"
        ".Lff8708_000f902e:\n"
        "cmpb $5, 5(%esi)\n" /* line 676 */
        "je .Lff8708_000f9b3a\n"
        "movl 8(%esi), %edx\n" /* line 679 */
        "movl %edx, -0x20(%ebp)\n" /* image */
        ".Lff8708_000f903e:\n"
        "movzbl 4(%esi), %eax\n" /* line 680 */
        "movb %al, -0x19(%ebp)\n" /* samplerState */
        /* { scope 6 */
        "cmpl $3, (%edx)\n" /* line 482 */
        "je .Lff8708_000f975d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f904e:\n"
        "movl %edx, 8(%esp)\n" /* line 1330 */
        "movzbl -0x19(%ebp), %eax\n" /* samplerState */
        "movl %eax, 4(%esp)\n"
        "movl -0xc4(%ebp), %eax\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll RB_SetSampler\n"
        "movl -0x5c(%ebp), %edx\n"
        "movzbl 9(%edx), %eax\n"
        /* } scope */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "movl -0x58(%ebp), %ecx\n" /* line 176 */
        "cmpb 0x2095(%ecx), %al\n"
        "jne .Lff8708_000f96fe\n"
        "cmpb $2, %al\n"
        "je .Lff8708_000f96fe\n"
        /* } scope */
        "addl $1, -0xc4(%ebp)\n" /* line 1411 | samplerIndex */
        "addl $8, -0x100(%ebp)\n"
        "addl $1, -0x5c(%ebp)\n"
        "addl $1, -0x58(%ebp)\n"
        "cmpl $2, -0xc4(%ebp)\n" /* samplerIndex */
        "jne .Lff8708_000f9736\n"
        ".Lff8708_000f90a9:\n"
        "movl -0x48(%ebp), %ebx\n" /* fvf */
        "xorl %edi, %edi\n"
        "movl imp_dxState, %esi\n" /* constantIndex */
        ".Lff8708_000f90b4:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1419 | fvf, texStageBits */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "cmpl 0x2014(%esi), %eax\n" /* line 187 */
        "je .Lff8708_000f90d1\n"
        "movl %eax, 0x2014(%esi)\n" /* line 189 */
        "movl %eax, 4(%esp)\n" /* line 191 */
        "movl %edi, (%esp)\n"
        "calll RB_ChangeColorStageState\n"
        /* } scope */
        ".Lff8708_000f90d1:\n"
        "movl 0x3c(%ebx), %eax\n" /* line 1420 | fvf, texStageBits */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "cmpl 0x2034(%esi), %eax\n" /* line 199 */
        "je .Lff8708_000f90ee\n"
        "movl %eax, 0x2034(%esi)\n" /* line 201 */
        "movl %eax, 4(%esp)\n" /* line 203 */
        "movl %edi, (%esp)\n"
        "calll RB_ChangeAlphaStageState\n"
        /* } scope */
        ".Lff8708_000f90ee:\n"
        "addl $1, %edi\n" /* line 1417 */
        "addl $4, %ebx\n" /* fvf */
        "addl $4, %esi\n" /* constantIndex */
        "cmpl $8, %edi\n"
        "jne .Lff8708_000f90b4\n"
        /* } scope */
        ".Lff8708_000f90fc:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1464 | techType */
        "movl (%eax), %eax\n" /* techType */
        "cmpl $2, 8(%eax)\n" /* techType */
        "je .Lff8708_000f8cc4\n"
        ".Lff8708_000f910d:\n"
        "movl imp_backEnd, %eax\n" /* line 75 */
        "cmpb $0, 0x4bd(%eax)\n"
        "jne .Lff8708_000f97c2\n"
        "movl -0xe0(%ebp), %eax\n" /* line 77 */
        "movl 8(%eax), %ebx\n"
        "movl imp_r_drawPrimFloor, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n"
        "jl .Lff8708_000f8d2a\n"
        "movl imp_r_drawPrimCap, %eax\n" /* line 79 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9385\n"
        "cmpl %eax, %ebx\n"
        "jle .Lff8708_000f9385\n"
        "addl $1, -0xd8(%ebp)\n" /* line 1459 | passIndex */
        "addl $0x5c, -0x4c(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movzwl 6(%edx), %eax\n" /* techType */
        "cmpl %eax, -0xd8(%ebp)\n" /* techType, passIndex */
        "jl .Lff8708_000f8d48\n"
        ".Lff8708_000f9170:\n"
        "movl imp_g_special, %eax\n" /* techType */
        ".Lff8708_000f9175:\n"
        "movb $0, (%eax)\n" /* line 1474 | techType */
        /* } scope */
        "addl $0x18c, %esp\n" /* line 1477 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pass, stateBits */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        ".Lff8708_000f9183:\n"
        "movl imp_tess, %eax\n" /* line 1252 */
        "movl 0x5a7bc(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0xd0(%ebp), %eax\n" /* ruleSetIndex */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xd4(%ebp), %edx\n" /* stateMap */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00226858, 4(%esp)\n" /* "No rule in stateMap '%s' rule set %i matched the current mat" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        "addl $1, -0xd0(%ebp)\n" /* line 1249 | ruleSetIndex */
        "addl $4, -0x54(%ebp)\n"
        "cmpl $0xb, -0xd0(%ebp)\n" /* ruleSetIndex */
        "je .Lff8708_000f8e54\n"
        ".Lff8708_000f91d6:\n"
        "movl -0x54(%ebp), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1251 | ruleSet */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        "movl (%eax), %esi\n" /* line 1219 | constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jg .Lff8708_000f8dce\n"
        "jmp .Lff8708_000f9183\n"
        ".Lff8708_000f91e8:\n"
        "movl -0xb8(%ebp), %ebx\n" /* refStateBits, codeConst */
        "jmp .Lff8708_000f87cc\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        ".Lff8708_000f91f3:\n"
        "addl $4, %ebx\n" /* line 1140 | codeConst */
        /* { scope 6 */
        "movl -0x40(%ebp), %edx\n" /* line 953 */
        "movzwl 4(%edx), %eax\n"
        "cmpw $0xba, %ax\n"
        "ja .Lff8708_000f979d\n"
        "movzwl %ax, %eax\n" /* line 292 */
        "shll $4, %eax\n"
        "subl $0x800, %eax\n"
        "movl imp_backEnd, %ecx\n"
        "addl %ecx, %eax\n"
        "movl %eax, -0xa8(%ebp)\n" /* data */
        "movzbl 3(%ebx), %ebx\n" /* line 956 | textureIndex */
        "movl %ebx, -0xac(%ebp)\n" /* textureIndex, rowCount */
        /* } scope */
        ".Lff8708_000f922a:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 1141 | codeConst */
        "movzwl 2(%ebx), %ebx\n" /* codeConst */
        "movl %ebx, -0xa0(%ebp)\n" /* codeConst, destIndex */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_r_logFile, %eax\n" /* line 991 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f925c\n"
        "movl -0xac(%ebp), %edx\n" /* line 993 | rowCount */
        "testl %edx, %edx\n"
        "jle .Lff8708_000f925c\n"
        "xorl %eax, %eax\n" /* line 991 */
        ".Lff8708_000f9251:\n"
        "addl $1, %eax\n" /* line 993 */
        "cmpl -0xac(%ebp), %eax\n" /* rowCount */
        "jne .Lff8708_000f9251\n"
        ".Lff8708_000f925c:\n"
        "movl -0xac(%ebp), %ebx\n" /* line 996 | rowCount, textureIndex */
        "shll $4, %ebx\n" /* textureIndex */
        "movl -0xa0(%ebp), %eax\n" /* destIndex */
        "shll $4, %eax\n"
        "movl imp_dxState, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        "cld\n"
        "cmpl %ebx, %ebx\n" /* textureIndex */
        "movl %eax, %esi\n" /* constantIndex */
        "movl -0xa8(%ebp), %edi\n" /* data */
        "movl %ebx, %ecx\n" /* textureIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f929c\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f929c:\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f8a92\n"
        "movl %ebx, 8(%esp)\n" /* line 998 | textureIndex */
        "movl -0xa8(%ebp), %ecx\n" /* data */
        "movl %ecx, 4(%esp)\n"
        "movl -0x9c(%ebp), %ebx\n" /* textureIndex */
        "movl %ebx, (%esp)\n" /* textureIndex */
        "calll memcpy\n"
        ".Lff8708_000f92c0:\n"
        "movl -0xf0(%ebp), %edx\n" /* line 999 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl -0xac(%ebp), %ecx\n" /* rowCount */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xa8(%ebp), %ebx\n" /* data, textureIndex */
        "movl %ebx, 8(%esp)\n" /* textureIndex */
        "movl -0xa0(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x178(%edx)\n"
        "movl -0xf4(%ebp), %ebx\n" /* textureIndex */
        "movl (%ebx), %eax\n" /* textureIndex */
        "testl %eax, %eax\n"
        "jne .Lff8708_000f92c0\n"
        "jmp .Lff8708_000f8a92\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        ".Lff8708_000f9303:\n"
        "movl -0x88(%ebp), %eax\n" /* line 1178 | routingData */
        "movl 4(%eax), %ebx\n" /* data */
        "movzwl 2(%eax), %edx\n"
        "movl %edx, -0x78(%ebp)\n" /* destIndex */
        /* { scope 6 */
        "shll $4, %edx\n" /* line 1065 */
        "movl imp_dxState, %eax\n"
        "leal 0x1000(%edx, %eax), %edx\n"
        "movl %edx, -0x174(%ebp)\n"
        "movl $0x10, -0xec(%ebp)\n"
        "cld\n"
        "movl %edx, %esi\n" /* constantIndex */
        "movl %ebx, %edi\n" /* textureIndex */
        "movl $0x10, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f934f\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f934f:\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f9a49\n"
        /* } scope */
        ".Lff8708_000f9357:\n"
        "addl $8, -0x88(%ebp)\n" /* line 1205 | routingData */
        "addl $1, -0x84(%ebp)\n" /* line 1173 | routingIndex */
        "movl -0x84(%ebp), %ecx\n" /* routingIndex */
        "cmpl %ecx, -0x8c(%ebp)\n" /* routingCount */
        "jne .Lff8708_000f8c49\n"
        "jmp .Lff8708_000f90fc\n"
        ".Lff8708_000f937c:\n"
        "movl -0xe0(%ebp), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* codeConst */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f9385:\n"
        "movl imp_dx, %eax\n" /* line 98 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x148(%ecx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f937c\n"
        "jmp .Lff8708_000f8d2a\n"
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        ".Lff8708_000f93d5:\n"
        "movl -0x88(%ebp), %ebx\n" /* line 1182 | routingData, codeConst */
        "addl $4, %ebx\n" /* codeConst */
        /* { scope 6 */
        "movl -0x88(%ebp), %edx\n" /* line 953 | routingData */
        "movzwl 4(%edx), %eax\n"
        "cmpw $0xba, %ax\n"
        "ja .Lff8708_000f9a2a\n"
        "movzwl %ax, %eax\n" /* line 292 */
        "shll $4, %eax\n"
        "movl imp_backEnd, %edx\n"
        "leal -0x800(%eax, %edx), %eax\n"
        "movl %eax, -0x7c(%ebp)\n" /* data */
        "movzbl 3(%ebx), %ebx\n" /* line 956 | textureIndex */
        "movl %ebx, -0x80(%ebp)\n" /* textureIndex, rowCount */
        /* } scope */
        ".Lff8708_000f940f:\n"
        "movl -0x88(%ebp), %eax\n" /* line 1183 | routingData */
        "movzwl 2(%eax), %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* destIndex */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_r_logFile, %eax\n" /* line 1060 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lff8708_000f943b\n"
        "movl -0x80(%ebp), %ebx\n" /* line 1062 | rowCount, textureIndex */
        "testl %ebx, %ebx\n" /* textureIndex */
        "jle .Lff8708_000f943b\n"
        "xorl %eax, %eax\n" /* line 1060 */
        ".Lff8708_000f9433:\n"
        "addl $1, %eax\n" /* line 1062 */
        "cmpl -0x80(%ebp), %eax\n" /* rowCount */
        "jne .Lff8708_000f9433\n"
        ".Lff8708_000f943b:\n"
        "movl -0x80(%ebp), %ebx\n" /* line 1065 | rowCount, textureIndex */
        "shll $4, %ebx\n" /* textureIndex */
        "movl -0x74(%ebp), %edx\n" /* destIndex */
        "shll $4, %edx\n"
        "movl imp_dxState, %eax\n"
        "leal 0x1000(%edx, %eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "cld\n"
        "cmpl %ebx, %ebx\n" /* textureIndex */
        "movl %edx, %esi\n" /* constantIndex */
        "movl -0x7c(%ebp), %edi\n" /* data */
        "movl %ebx, %ecx\n" /* textureIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f9473\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f9473:\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9357\n"
        "movl %ebx, 8(%esp)\n" /* line 1067 | textureIndex */
        "movl -0x7c(%ebp), %edx\n" /* data */
        "movl %edx, 4(%esp)\n"
        "movl -0x70(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl imp_dx, %esi\n" /* constantIndex */
        "movl imp_alwaysfails, %ebx\n" /* textureIndex */
        ".Lff8708_000f949d:\n"
        "movl 8(%esi), %eax\n" /* line 1068 | constantIndex */
        "movl (%eax), %edx\n"
        "movl -0x80(%ebp), %ecx\n" /* rowCount */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %ecx\n" /* data */
        "movl %ecx, 8(%esp)\n"
        "movl -0x74(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1b4(%edx)\n"
        "movl (%ebx), %edx\n" /* textureIndex */
        "testl %edx, %edx\n"
        "jne .Lff8708_000f949d\n"
        "jmp .Lff8708_000f9357\n"
        /* } scope */
        /* } scope */
        ".Lff8708_000f94cb:\n"
        "leal -0x19(%ebp), %ecx\n" /* line 1192 | samplerState */
        "leal -0x20(%ebp), %edx\n" /* image */
        "movl -0x88(%ebp), %ebx\n" /* routingData, codeConst */
        "movl 4(%ebx), %eax\n" /* codeConst */
        "calll RB_GetTextureFromCode\n"
        "movl -0x20(%ebp), %eax\n" /* line 1193 | image */
        "movl %eax, 8(%esp)\n"
        "movzbl -0x19(%ebp), %eax\n" /* samplerState */
        "movl %eax, 4(%esp)\n"
        "movzwl 2(%ebx), %eax\n" /* codeConst */
        "movl %eax, (%esp)\n"
        "calll RB_SetSampler\n"
        "jmp .Lff8708_000f9357\n"
        ".Lff8708_000f94ff:\n"
        "movl -0x88(%ebp), %eax\n" /* line 1197 | routingData */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* textureName */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_tess, %eax\n" /* line 671 */
        "movl 0x5a7bc(%eax), %eax\n"
        "movzwl 0x34(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff8708_000f97fd\n"
        "movl 0x3c(%eax), %esi\n" /* line 673 */
        "movl -0x60(%ebp), %ecx\n" /* line 674 | textureName */
        "cmpl (%esi), %ecx\n"
        "je .Lff8708_000f954d\n"
        "leal 0xc(%esi), %ecx\n"
        "movl %ecx, %edx\n"
        "xorl %ebx, %ebx\n" /* textureIndex */
        ".Lff8708_000f9533:\n"
        "addl $1, %ebx\n" /* line 671 | textureIndex */
        "cmpl %edi, %ebx\n" /* textureIndex */
        "je .Lff8708_000f97fd\n"
        "movl %ecx, %esi\n"
        "movl (%edx), %eax\n" /* line 674 */
        "leal 0xc(%ecx), %ecx\n"
        "addl $0xc, %edx\n"
        "cmpl %eax, -0x60(%ebp)\n" /* textureName */
        "jne .Lff8708_000f9533\n"
        ".Lff8708_000f954d:\n"
        "cmpb $5, 5(%esi)\n" /* line 676 */
        "je .Lff8708_000f9be1\n"
        "movl 8(%esi), %edx\n" /* line 679 */
        "movl %edx, -0x20(%ebp)\n" /* image */
        ".Lff8708_000f955d:\n"
        "movzbl 4(%esi), %eax\n" /* line 680 */
        "movb %al, -0x19(%ebp)\n" /* samplerState */
        /* { scope 8 */
        "cmpl $3, (%edx)\n" /* line 482 */
        "je .Lff8708_000f9b8c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f956d:\n"
        "movl %edx, 8(%esp)\n" /* line 1198 */
        "movzbl -0x19(%ebp), %eax\n" /* samplerState */
        "movl %eax, 4(%esp)\n"
        "movl -0x88(%ebp), %edx\n" /* routingData */
        "movzwl 2(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetSampler\n"
        "jmp .Lff8708_000f9357\n"
        ".Lff8708_000f9590:\n"
        "movl -0x88(%ebp), %ebx\n" /* line 1187 | routingData, codeConst */
        "movl 4(%ebx), %ebx\n" /* codeConst */
        "movl %ebx, -0x6c(%ebp)\n" /* codeConst, literalName */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_tess, %esi\n" /* line 971 | constantIndex */
        "movl 0x5a7bc(%esi), %eax\n" /* constantIndex */
        "movzwl 0x36(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff8708_000f95e1\n"
        "movl 0x40(%eax), %ecx\n" /* line 973 */
        "cmpl (%ecx), %ebx\n" /* line 974 | textureIndex */
        "je .Lff8708_000f95d4\n"
        "leal 0x14(%ecx), %ebx\n" /* textureIndex */
        "movl %ebx, %edx\n" /* textureIndex */
        "xorl %esi, %esi\n" /* constantIndex */
        ".Lff8708_000f95be:\n"
        "addl $1, %esi\n" /* line 971 | constantIndex */
        "cmpl %edi, %esi\n" /* constantIndex */
        "je .Lff8708_000f95e1\n"
        "movl %ebx, %ecx\n" /* textureIndex */
        "movl (%edx), %eax\n" /* line 974 */
        "leal 0x14(%ebx), %ebx\n" /* textureIndex */
        "addl $0x14, %edx\n"
        "cmpl %eax, -0x6c(%ebp)\n" /* literalName */
        "jne .Lff8708_000f95be\n"
        ".Lff8708_000f95d4:\n"
        "addl $4, %ecx\n" /* line 976 */
        "movl %ecx, -0x7c(%ebp)\n" /* data */
        "movl $1, -0x80(%ebp)\n" /* rowCount */
        /* } scope */
        /* } scope */
        ".Lff8708_000f95e1:\n"
        "movl -0x88(%ebp), %eax\n" /* line 1188 | routingData */
        "movzwl 2(%eax), %eax\n"
        "movl %eax, -0x68(%ebp)\n" /* destIndex */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_r_logFile, %eax\n" /* line 1060 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f960d\n"
        "movl -0x80(%ebp), %esi\n" /* line 1062 | rowCount, constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jle .Lff8708_000f960d\n"
        "xorl %eax, %eax\n" /* line 1060 */
        ".Lff8708_000f9605:\n"
        "addl $1, %eax\n" /* line 1062 */
        "cmpl -0x80(%ebp), %eax\n" /* rowCount */
        "jne .Lff8708_000f9605\n"
        ".Lff8708_000f960d:\n"
        "movl -0x80(%ebp), %ebx\n" /* line 1065 | rowCount, textureIndex */
        "shll $4, %ebx\n" /* textureIndex */
        "movl -0x68(%ebp), %edx\n" /* destIndex */
        "shll $4, %edx\n"
        "movl imp_dxState, %eax\n"
        "leal 0x1000(%edx, %eax), %edx\n"
        "movl %edx, -0x64(%ebp)\n"
        "cld\n"
        "cmpl %ebx, %ebx\n" /* textureIndex */
        "movl %edx, %esi\n" /* constantIndex */
        "movl -0x7c(%ebp), %edi\n" /* data */
        "movl %ebx, %ecx\n" /* textureIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f9645\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f9645:\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9357\n"
        "movl %ebx, 8(%esp)\n" /* line 1067 | textureIndex */
        "movl -0x7c(%ebp), %edx\n" /* data */
        "movl %edx, 4(%esp)\n"
        "movl -0x64(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl imp_dx, %esi\n" /* constantIndex */
        "movl imp_alwaysfails, %ebx\n" /* textureIndex */
        ".Lff8708_000f966f:\n"
        "movl 8(%esi), %eax\n" /* line 1068 | constantIndex */
        "movl (%eax), %edx\n"
        "movl -0x80(%ebp), %ecx\n" /* rowCount */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %ecx\n" /* data */
        "movl %ecx, 8(%esp)\n"
        "movl -0x68(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1b4(%edx)\n"
        "movl (%ebx), %eax\n" /* textureIndex */
        "testl %eax, %eax\n"
        "jne .Lff8708_000f966f\n"
        "jmp .Lff8708_000f9357\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f969d:\n"
        "movl (%ebx), %eax\n" /* line 998 | textureIndex */
        "movl -0x174(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 0xc(%edx)\n"
        ".Lff8708_000f96b9:\n"
        "movl imp_dx, %ecx\n" /* line 999 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl $1, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* textureIndex */
        "movl -0xa4(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x178(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f96b9\n"
        "jmp .Lff8708_000f8a92\n"
        ".Lff8708_000f96f3:\n"
        "movl -0xcc(%ebp), %ecx\n" /* refStateBits */
        "jmp .Lff8708_000f8d98\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        ".Lff8708_000f96fe:\n"
        "movzbl %al, %eax\n" /* line 179 */
        "movl %eax, 4(%esp)\n"
        "movl -0xc4(%ebp), %ebx\n" /* samplerIndex */
        "movl %ebx, (%esp)\n"
        "calll RB_ChangeGenTexCoords\n"
        /* } scope */
        "addl $1, -0xc4(%ebp)\n" /* line 1411 | samplerIndex */
        "addl $8, -0x100(%ebp)\n"
        "addl $1, -0x5c(%ebp)\n"
        "addl $1, -0x58(%ebp)\n"
        "cmpl $2, -0xc4(%ebp)\n" /* samplerIndex */
        "je .Lff8708_000f90a9\n"
        ".Lff8708_000f9736:\n"
        "movl -0x100(%ebp), %ecx\n"
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "cmpw $3, 0xc(%ecx)\n" /* line 1321 */
        "jne .Lff8708_000f8fdd\n"
        ".Lff8708_000f9747:\n"
        "movl 0x10(%ecx), %eax\n" /* line 1323 */
        "leal -0x19(%ebp), %ecx\n" /* samplerState */
        "leal -0x20(%ebp), %edx\n" /* image */
        "calll RB_GetTextureFromCode\n"
        "movl -0x20(%ebp), %edx\n" /* image */
        "jmp .Lff8708_000f904e\n"
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f975d:\n"
        "movzbl 5(%esi), %eax\n" /* line 486 */
        "cmpb $3, %al\n"
        "je .Lff8708_000f9c6b\n"
        "jbe .Lff8708_000f9c00\n"
        "cmpb $4, %al\n"
        "je .Lff8708_000f9c94\n"
        "cmpb $5, %al\n"
        "jne .Lff8708_000f904e\n"
        "movl 8(%esi), %eax\n" /* line 508 */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RB_UploadWaterTexture\n"
        "movb $6, -0x19(%ebp)\n" /* line 509 | samplerState */
        ".Lff8708_000f9795:\n"
        "movl -0x20(%ebp), %edx\n" /* image */
        "jmp .Lff8708_000f904e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f979d:\n"
        "movzbl 3(%ebx), %ecx\n" /* line 960 | textureIndex */
        "movzbl 2(%ebx), %edx\n" /* textureIndex */
        "movzwl %ax, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movl %eax, -0xa8(%ebp)\n" /* data */
        "movzbl 3(%ebx), %ebx\n" /* line 961 | textureIndex */
        "movl %ebx, -0xac(%ebp)\n" /* textureIndex, rowCount */
        "jmp .Lff8708_000f922a\n"
        ".Lff8708_000f97c2:\n"
        "movl -0xe0(%ebp), %edx\n"
        "movl 8(%edx), %ebx\n" /* textureIndex */
        "jmp .Lff8708_000f9385\n"
        ".Lff8708_000f97d0:\n"
        "movl %esi, %edx\n" /* texdef */
        "jmp .Lff8708_000f8957\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f97d7:\n"
        "cmpb $4, %al\n" /* line 486 */
        "je .Lff8708_000f9ccc\n"
        "cmpb $5, %al\n"
        "jne .Lff8708_000f956d\n"
        "movl 8(%esi), %eax\n" /* line 508 */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RB_UploadWaterTexture\n"
        "movb $6, -0x19(%ebp)\n" /* line 509 | samplerState */
        ".Lff8708_000f97fd:\n"
        "movl -0x20(%ebp), %edx\n" /* image */
        "jmp .Lff8708_000f956d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        ".Lff8708_000f9805:\n"
        "cmpl 0x2144(%edx), %ebx\n" /* line 272 */
        "jne .Lff8708_000f8f60\n"
        /* } scope */
        "movl -0x48(%ebp), %edx\n" /* line 1404 */
        "cmpb $0, 7(%edx)\n"
        "je .Lff8708_000f8fa4\n"
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        ".Lff8708_000f981e:\n"
        "movl imp_backEnd, %eax\n" /* line 1346 */
        "movss 0x3bc(%eax), %xmm0\n"
        "movl imp_r_objectiveColorDx7Min, %eax\n" /* line 1348 */
        "movl (%eax), %eax\n"
        "leal 8(%eax), %edx\n" /* from */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        "movzbl 8(%eax), %eax\n" /* line 705 */
        "cvtsi2ssl %eax, %xmm3\n"
        "movss lit4_002ed5cc, %xmm5\n" /* 0.003921568859368563f */
        "mulss %xmm5, %xmm3\n"
        "movzbl 1(%edx), %eax\n" /* line 706 */
        "cvtsi2ssl %eax, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "movzbl 2(%edx), %eax\n" /* line 707 */
        "cvtsi2ssl %eax, %xmm6\n"
        "mulss %xmm5, %xmm6\n"
        "movzbl 3(%edx), %eax\n" /* line 708 */
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        /* } scope */
        "movl imp_r_objectiveColorDx7Max, %eax\n" /* line 1349 */
        "movl (%eax), %ebx\n" /* decl */
        "leal 8(%ebx), %esi\n" /* decl, constantIndex */
        "movss %xmm0, (%esp)\n" /* line 1347 */
        "movss %xmm0, -0x118(%ebp)\n"
        "movss %xmm1, -0x128(%ebp)\n"
        "movss %xmm3, -0x138(%ebp)\n"
        "movss %xmm4, -0x148(%ebp)\n"
        "movss %xmm5, -0x158(%ebp)\n"
        "movss %xmm6, -0x168(%ebp)\n"
        "calll floorf\n"
        "fstps -0xe4(%ebp)\n"
        "movss -0x118(%ebp), %xmm0\n"
        "subss -0xe4(%ebp), %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd lit8_00307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x16c(%ebp)\n"
        "movss -0x16c(%ebp), %xmm2\n"
        "mulss lit4_002ed63c, %xmm2\n" /* -0.5f */
        "addss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "movzbl 3(%esi), %eax\n" /* line 1354 | constantIndex */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x158(%ebp), %xmm5\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x128(%ebp), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss lit4_002ed5d4, %xmm7\n" /* 255.0f */
        "mulss %xmm7, %xmm1\n"
        "fnstcw -0x2a(%ebp)\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x2c(%ebp)\n"
        "movss %xmm1, -0x16c(%ebp)\n"
        "flds -0x16c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0x18, %ecx\n"
        "movzbl 8(%ebx), %eax\n" /* decl */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x138(%ebp), %xmm3\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss %xmm7, %xmm3\n"
        "movss %xmm3, -0x16c(%ebp)\n"
        "flds -0x16c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %ecx\n"
        "movzbl 1(%esi), %eax\n" /* constantIndex */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x148(%ebp), %xmm4\n"
        "subss %xmm4, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss %xmm7, %xmm4\n"
        "movss %xmm4, -0x16c(%ebp)\n"
        "flds -0x16c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %ecx\n"
        "movzbl 2(%esi), %eax\n" /* constantIndex */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x168(%ebp), %xmm6\n"
        "subss %xmm6, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm6\n"
        "mulss %xmm7, %xmm6\n"
        "movss %xmm6, -0x16c(%ebp)\n"
        "flds -0x16c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "orl %eax, %ecx\n"
        "jmp .Lff8708_000f8fa9\n"
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f9a2a:\n"
        "movzbl 3(%ebx), %ecx\n" /* line 960 | textureIndex */
        "movzbl 2(%ebx), %edx\n" /* textureIndex */
        "movzwl %ax, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movl %eax, -0x7c(%ebp)\n" /* data */
        "movzbl 3(%ebx), %ebx\n" /* line 961 | textureIndex */
        "movl %ebx, -0x80(%ebp)\n" /* textureIndex, rowCount */
        "jmp .Lff8708_000f940f\n"
        /* } scope */
        /* { scope 6 */
        ".Lff8708_000f9a49:\n"
        "movl (%ebx), %eax\n" /* line 1067 | textureIndex */
        "movl -0x174(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 0xc(%edx)\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n" /* constantIndex */
        ".Lff8708_000f9a71:\n"
        "movl 8(%edi), %eax\n" /* line 1068 */
        "movl (%eax), %edx\n"
        "movl $1, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* textureIndex */
        "movl -0x78(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1b4(%edx)\n"
        "movl (%esi), %eax\n" /* constantIndex */
        "testl %eax, %eax\n"
        "jne .Lff8708_000f9a71\n"
        "jmp .Lff8708_000f9357\n"
        ".Lff8708_000f9a9d:\n"
        "movl -0xe0(%ebp), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* textureIndex */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f9aa6:\n"
        "movl imp_dx, %eax\n" /* line 98 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x148(%ecx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f9a9d\n"
        "movl $0x3f800000, (%esp)\n" /* line 1468 */
        "calll RB_SetViewMatrixForWDx7\n"
        "jmp .Lff8708_000f8d2a\n"
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        ".Lff8708_000f9b02:\n"
        "movl 0x5a7bc(%esi), %eax\n" /* line 1276 | constantIndex */
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl $str_002268b4, 4(%esp)\n" /* "Vertex type %i doesn't have the information used by shader %" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        "movl imp_tess, %esi\n" /* constantIndex */
        "jmp .Lff8708_000f87b0\n"
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        ".Lff8708_000f9b3a:\n"
        "movl 8(%esi), %eax\n" /* line 677 */
        "movl 0x1c(%eax), %eax\n"
        "movl 0x40(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "jmp .Lff8708_000f903e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f9b4b:\n"
        "movl imp_r_debugShader, %eax\n" /* line 1451 | techType */
        "movl (%eax), %eax\n" /* techType */
        "movl 8(%eax), %eax\n" /* techType */
        "shll $4, %eax\n" /* techType */
        "leal debugShaderConsts(%eax), %ecx\n" /* techType */
        "movl imp_backEnd, %edx\n" /* line 275 | to */
        "addl $0x1a0, %edx\n" /* to */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        "movl debugShaderConsts(%eax), %eax\n" /* line 456 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x3c(%ebp), %edx\n"
        "jmp .Lff8708_000f873f\n"
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f9b8c:\n"
        "movzbl 5(%esi), %eax\n" /* line 486 */
        "cmpb $3, %al\n"
        "je .Lff8708_000f9c43\n"
        "ja .Lff8708_000f97d7\n"
        "cmpb $2, %al\n"
        "jne .Lff8708_000f956d\n"
        "movl imp_r_colorMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f956d\n"
        ".Lff8708_000f9bb8:\n"
        "cmpl $1, %eax\n" /* line 455 */
        "je .Lff8708_000f9d13\n"
        "cmpl $2, %eax\n" /* line 462 */
        "jne .Lff8708_000f956d\n"
        "movl imp_rgp, %eax\n" /* line 464 */
        "movl 0x100c(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 465 | samplerState */
        "jmp .Lff8708_000f956d\n"
        /* } scope */
        ".Lff8708_000f9be1:\n"
        "movl 8(%esi), %eax\n" /* line 677 */
        "movl 0x1c(%eax), %eax\n"
        "movl 0x40(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "jmp .Lff8708_000f955d\n"
        ".Lff8708_000f9bf2:\n"
        "movl -0xe0(%ebp), %edx\n"
        "movl 8(%edx), %ebx\n" /* textureIndex */
        "jmp .Lff8708_000f9aa6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f9c00:\n"
        "cmpb $2, %al\n" /* line 486 */
        "jne .Lff8708_000f904e\n"
        "movl imp_r_colorMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f904e\n"
        "cmpl $1, %eax\n" /* line 455 */
        "je .Lff8708_000f9ce3\n"
        "cmpl $2, %eax\n" /* line 462 */
        "jne .Lff8708_000f904e\n"
        "movl imp_rgp, %eax\n" /* line 464 */
        "movl 0x100c(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 465 | samplerState */
        "jmp .Lff8708_000f904e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f9c43:\n"
        "movl imp_r_normalMap, %eax\n" /* line 497 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jne .Lff8708_000f956d\n"
        "movl imp_rgp, %eax\n" /* line 499 */
        "movl 0x1010(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 500 | samplerState */
        "jmp .Lff8708_000f956d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f9c6b:\n"
        "movl imp_r_normalMap, %eax\n" /* line 497 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jne .Lff8708_000f904e\n"
        "movl imp_rgp, %ebx\n" /* line 499 */
        "movl 0x1010(%ebx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 500 | samplerState */
        "jmp .Lff8708_000f904e\n"
        ".Lff8708_000f9c94:\n"
        "movl imp_r_specularMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f904e\n"
        "cmpl $1, %eax\n" /* line 455 */
        "je .Lff8708_000f9cfb\n"
        "cmpl $2, %eax\n" /* line 462 */
        "jne .Lff8708_000f904e\n"
        "movl imp_rgp, %ecx\n" /* line 464 */
        "movl 0x100c(%ecx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 465 | samplerState */
        "jmp .Lff8708_000f904e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f9ccc:\n"
        "movl imp_r_specularMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f956d\n"
        "jmp .Lff8708_000f9bb8\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f9ce3:\n"
        "movl imp_rgp, %ecx\n" /* line 457 */
        "movl 0x1008(%ecx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 458 | samplerState */
        "jmp .Lff8708_000f904e\n"
        ".Lff8708_000f9cfb:\n"
        "movl imp_rgp, %ebx\n" /* line 457 */
        "movl 0x1008(%ebx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 458 | samplerState */
        "jmp .Lff8708_000f904e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f9d13:\n"
        "movl imp_rgp, %eax\n" /* line 457 */
        "movl 0x1008(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 458 | samplerState */
        "jmp .Lff8708_000f956d\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_f8708_0:\n"
        ".long .Lff8708_000f9303\n"
        ".long .Lff8708_000f93d5\n"
        ".long .Lff8708_000f9590\n"
        ".long .Lff8708_000f94cb\n"
        ".long .Lff8708_000f94ff\n"
        ".text\n"
    );
}
/* line 1556 */
void RB_DrawTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args)
{
    char *backEnd = (char *)imp_backEnd;
    char *tess = RB_TessBase();
    MaterialTechniqueType techType;
    const GfxStateOverride *stateOverride;

    /* Update viewport if pending (clears the pending flag) */
    if (*(byte *)(backEnd + 0x4bc) != 0)
        RB_UpdateViewport();

    techType = *(MaterialTechniqueType *)(tess + 0x5a7c0);

    /* techType in [6..17]: set up per-pixel lighting constants */
    if ((unsigned)(techType - 6) <= 11) {
        RB_SetupLighting();
        techType = *(MaterialTechniqueType *)(tess + 0x5a7c0);  /* re-read; SetupLighting may change it */
    }

    /* techType in [3..26]: set up fog iterator */
    if ((unsigned)(techType - 3) <= 0x17)
        RB_SetIteratorFog();

    /* Re-read techType after potential modifications by the above calls */
    techType = *(MaterialTechniqueType *)(tess + 0x5a7c0);

    /* On DX7, techType in [9..14] (skinned/lit models) need normal renormalization */
    stateOverride = NULL;
    if (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2 && (unsigned)(techType - 9) <= 5)
        stateOverride = &overrideEnableRenormalize;

    /* Diagnostic: check technique pass count */
    {
        static int dt_count = 0;
        char *_tess = RB_TessBase();
        void *mat = *(void **)(_tess + 0x5a7bc);
        if (mat) {
            void *techSet = *(void **)((char *)mat + 0x38);
            if (techSet) {
                void *tech = *(void **)((char *)techSet + 4 + (int)techType * 4);
                short passCount = tech ? *(short *)((char *)tech + 6) : -1;
                if (dt_count++ < 20)
                    fprintf(stderr, "[DrawTech] techType=%d vertDecl=%d tech=%p passCount=%d\n",
                            (int)techType, (int)vertDeclType, tech, (int)passCount);
            }
        }
    }

    /* RB_DrawSingleTechnique uses a non-standard register calling convention:
     * eax = techType (from tess), edx = vertDeclType, ecx = args, stack = stateOverride */
    __asm__ __volatile__ (
        "pushl %3\n"
        "call RB_DrawSingleTechnique\n"
        "addl $4, %%esp\n"
        :
        : "a"((int)techType), "d"((int)vertDeclType), "c"(args), "r"(stateOverride)
        : "memory"
    );
}

int g_rb_endsurface_count = 0; /* diagnostic */
int g_rb_endsurface_nomaterial = 0; /* diagnostic: tess material missing */
int g_rb_endsurface_notechnique = 0; /* diagnostic: technique==NULL */
int g_rb_endsurface_dxstate = 0; /* diagnostic: dxState+0x20c8 non-zero */
int g_rb_endsurface_draw = 0; /* diagnostic: reached RB_DrawSingleTechnique */
int g_rb_endsurface_flag1skip = 0; /* diagnostic: technique flag1 + backEnd==0xe */
int g_rb_endsurface_flag2skip = 0; /* diagnostic: technique flag2 + backEnd==0xe */
int g_rb_endsurface_idxzero = 0; /* diagnostic: indexCount==0 */
int g_rb_tess_type_counts[8] = {0}; /* diagnostic: per surface type dispatch count */
int g_rb_tess_type_idxzero[8] = {0}; /* diagnostic: per type zero-index count */
extern int g_rb_last_tess_type;
int g_tess_since_begin = 0; /* count TessXxx calls since last BeginSurface */
extern int g_begin_surface_calls;
extern int g_tt_last_cached;
extern void *g_tt_last_tess;
extern int g_tt_seq, g_tt_last_seq;
int g_es_seq = 0;
void diag_idxzero(void *tess_base) {
    (void)tess_base;
}
void diag_endsurface_entry(void *tess_base) {
    (void)tess_base;
}
/* line 1712 */
void RB_EndSurface(void)
{
    char *tess = RB_TessBase();
    const Material *material;
    MaterialTechnique *technique;
    unsigned short techFlags;
    char *backEnd;
    int isDx7;
    int indexCount;
    int cachedIndexCount;
    GfxDrawPrimArgs args;
    int vertexStride;

    /* Note: fprintf to stderr doesn't work from this function (thread/redirect issue).
     * Use file output instead. */
    diag_endsurface_entry(tess);
    tess = RB_TessBase();

    /* Validate material */
    material = *(const Material **)(tess + 0x5a7bc);
    if (!material) {
        g_rb_endsurface_nomaterial++;
        goto cleanup;
    }

    /* Look up technique for current techType */
    {
        unsigned int ts = (unsigned int)material->techniqueSet;
        if (!ts || (ts > 0x0c000000u && ts < 0xf0000000u) || ts < 0x08000000u) {
            g_rb_endsurface_notechnique++;
            goto cleanup;
        }
    }
    technique = material->techniqueSet->techniques[
        *(MaterialTechniqueType *)(tess + 0x5a7c0)];

    g_rb_endsurface_count++;

    if (!technique) {
        g_rb_endsurface_notechnique++;
        goto cleanup;
    }

    /* Update viewport if dirty */
    backEnd = (char *)imp_backEnd;
    if (*(byte *)(backEnd + 0x4bc))
        RB_UpdateViewport();

    /* Skip draw if dxState device lost / not ready */
    if (*(byte *)((char *)imp_dxState + 0x20c8)) {
        g_rb_endsurface_dxstate++;
        goto cleanup;
    }

    /* Check technique flags for shadow texture availability */
    techFlags = technique->flags;
    if (techFlags & 1) {
        if (*(int *)(backEnd + 0x2e84) == 0xe) {
            g_rb_endsurface_flag1skip++;
            goto cleanup;
        }
    }
    if (techFlags & 2) {
        if (*(int *)(backEnd + 0x2e88) == 0xe) {
            g_rb_endsurface_flag2skip++;
            goto cleanup;
        }
    }

    /* === Cached/optimized geometry path (static model cache, world VB) === */
    cachedIndexCount = *(int *)(tess + 0x5a7e0); /* optimizedIndexCount */
    if (cachedIndexCount != 0) {
        int cachedVertDeclType;
        IDirect3DVertexBuffer9 *vb;
        char *dxState;

        /* Build draw args from cached fields */
        args.firstVertexFromBase = 0;
        args.vertexCount = *(int *)(tess + 0x5a7e4); /* optimizedVertexCount */
        args.primCount = cachedIndexCount / 3;
        args.u.buf.baseIndex = RB_SetIndexData(
            *(r_index_t **)(tess + 0x5a7b4), cachedIndexCount);

        isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);

        if (*(int *)(tess + 0x5a7b8) == 1) {
            /* VERTDECL_WORLD: vertex data in world vertex buffer */
            vertexStride = isDx7 ? 0x20 : 0x44;
            vb = *(IDirect3DVertexBuffer9 **)
                ((char *)*(void **)((char *)imp_rgp + 0x109c) + 0x30);
            cachedVertDeclType = 1; /* VERTDECL_WORLD */
        } else {
            /* VERTDECL_STATICMODELCACHE: vertex data in static model cache VB */
            vertexStride = isDx7 ? 0x18 : 0x40;
            vb = *(IDirect3DVertexBuffer9 **)((char *)imp_dx + 0x2dc4);
            cachedVertDeclType = 3; /* VERTDECL_STATICMODELCACHE */
        }

        /* Update stream source if VB, offset, or stride changed */
        dxState = (char *)imp_dxState;
        if (vb != *(IDirect3DVertexBuffer9 **)(dxState + 0x20d0) ||
            *(int *)(dxState + 0x20d4) != 0 ||
            *(int *)(dxState + 0x20d8) != vertexStride) {
            RB_ChangeStreamSource(0, vb, 0, vertexStride);
        }

        args.u.buf.baseVertex = *(int *)(tess + 0x5a7e8); /* firstOptimizedVertex */

        /* Draw cached geometry: setup lighting/fog/renormalize + draw */
        RB_DrawTechnique(cachedVertDeclType, &args);

        /* Clear cached state and fall through to check main tess path */
        tess = RB_TessBase();
        *(int *)(tess + 0x5a7e0) = 0; /* optimizedIndexCount */
        *(int *)(tess + 0x5a7b8) = 0; /* optimizedVertexSource */
    }

    /* === Main tessellation path === */
    indexCount = *(int *)(tess + 0x5a7d0);
    if (indexCount == 0) {
        g_rb_endsurface_idxzero++;
        g_rb_tess_type_idxzero[g_rb_last_tess_type]++;
        diag_idxzero(tess);
        return;
    }
    /* Build draw args from main tess fields */
    args.firstVertexFromBase = 0;
    args.vertexCount = *(int *)(tess + 0x5a7d4);
    args.primCount = indexCount / 3;

    isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);
    if (*(int *)(tess + 0x5a7cc) == 1) /* declType == VERTDECL_WORLD */
        vertexStride = isDx7 ? 0x20 : 0x44;
    else
        vertexStride = isDx7 ? 0x24 : 0x40;

    /* Upload index data to GPU index buffer */
    args.u.buf.baseIndex = RB_SetIndexData(
        *(r_index_t **)(tess + 0x5a7b0), indexCount);

    /* Dynamic VB overflow check: reset write offset if data won't fit */
    {
        char *dx = (char *)imp_dx;
        int *lockSlot = *(int **)(dx + 0x2db4);
        if (!lockSlot) {
            static int lockslot_warn = 0;
            if (lockslot_warn++ < 5)
                fprintf(stderr, "[EndSurf] lockSlot NULL at dx+0x2db4, skipping draw\n");
            goto cleanup;
        }
        int needed = *(int *)(tess + 0x5a7d4) * vertexStride + lockSlot[0];
        if (needed > lockSlot[1])
            lockSlot[0] = 0;
    }

    /* Diagnostic: dump tess vertex data before upload */
    {
        static int tess_dump = 0;
        if (tess_dump++ < 3) {
            int vc = *(int *)(tess + 0x5a7d4);
            float *vp = (float *)tess;
            fprintf(stderr, "[TESS] vertCount=%d stride=%d tess=%p\n", vc, vertexStride, tess);
            if (vc >= 4) {
                int vi;
                for (vi = 0; vi < 4; vi++) {
                    float *v = (float *)(tess + vi * vertexStride);
                    fprintf(stderr, "  tv%d pos=(%.2f,%.2f,%.2f,%.2f) @%p\n",
                            vi, v[0], v[1], v[2], v[3], v);
                }
            }
        }
    }

    /* Upload vertex data to GPU vertex buffer */
    RB_SetVertexData(0, tess, *(int *)(tess + 0x5a7d4), vertexStride);
    args.u.buf.baseVertex = 0;

    /* Bind the material's first texture before drawing.
     * The ASM shader code in RB_DrawSingleTechnique calls SetTexture via
     * CreateVertexShader/CreatePixelShader which return stubs on this port,
     * so textures never get bound — everything renders as white/grey boxes.
     * We fix this by pre-binding the correct texture here. */
    {
#define RB_GL_TEXTURE_2D 0x0DE1
        const Material *mat = *(const Material **)(tess + 0x5a7bc);

        if (mat) {
            int texCount = *(unsigned short *)((byte *)mat + 0x34);
            byte *textures = *(byte **)((byte *)mat + 0x3c);
            if (texCount > 0 && textures) {
                /* MaterialTextureDef is 0xc bytes; image pointer at +0x08 */
                byte *texEntry = textures; /* textures[0] */
                void *image = *(void **)(texEntry + 8); /* GfxImage* from union u */
                if (image) {
                    /* GfxImage: texture union (IDirect3DBaseTexture9*) at +0x04 */
                    void *d3dTexture = *(void **)((byte *)image + 4);
                    if (d3dTexture) {
                        /* Call SetTexture on D3D device (vtable[0x104/4] = vtable[65]) */
                        void *device = *(void **)((byte *)imp_dx + 8);
                        void **vtable = *(void ***)device;
                        ((void (*)(void *, int, void *))vtable[0x104 / 4])(device, 0, d3dTexture);

                        /* Also bind via OpenGL directly for the fixed-function path.
                         * CDirect3DTexture: texIDStorage (GLuint) at +0x54 */
                        {
                            unsigned int texID = *(unsigned int *)((byte *)d3dTexture + 0x54);
                            /* Store for DIP to use after GL state reset */
                            extern unsigned int g_prebind_texID;
                            g_prebind_texID = texID;
                            if (texID) {
                                glBindTexture(RB_GL_TEXTURE_2D, texID);
                                glEnable(RB_GL_TEXTURE_2D);
                            }
                        }
                    }
                }
            }
        }
#undef RB_GL_TEXTURE_2D
    }

    /* Draw main tess geometry */
    g_rb_endsurface_draw++;
    RB_DrawTechnique(*(MaterialVertexDeclType *)(tess + 0x5a7cc), &args);

    /* Clear tess counts */
    tess = RB_TessBase();
    *(int *)(tess + 0x5a7d0) = 0; /* indexCount */
    *(int *)(tess + 0x5a7d4) = 0; /* vertexCount */
    return;

cleanup:
    *(int *)(tess + 0x5a7e0) = 0; /* optimizedIndexCount */
    *(int *)(tess + 0x5a7d0) = 0; /* indexCount */
    *(int *)(tess + 0x5a7d4) = 0; /* vertexCount */
}
#else
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
            byte *rule = ruleSet + 4 + ruleIdx * 0x20;
            /* Check if rule matches current state */
            if ((*(int *)(refStateBits + 0) & *(int *)(rule + 4)) != *(int *)(rule + 0xc))
                continue;
            if ((*(int *)(refStateBits + 4) & *(int *)(rule + 8)) != *(int *)(rule + 0x10))
                continue;

            /* Apply rule: AND with mask, OR with value for each state word */
            {
                int k;
                for (k = 0; k < 2; k++) {
                    stateBits[k] &= *(int *)(rule + 0x18 + k*4);
                    stateBits[k] |= *(int *)(rule + 0x10 + k*4);
                }
            }
            matched = 1;
            break;
        }

        if (!matched) {
            char *tess2 = RB_TessBase();
            const Material *mat = *(const Material **)(tess2 + 0x5a7bc);
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
        byte *backEnd = (byte *)imp_backEnd;
        if (*(byte *)(backEnd + 0x4bd))
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

    /* Set pixel shader (pass+0xc -> programData -> pixelShader at offset 0xc) */
    {
        byte *programData = *(byte **)(pass + 0xc);
        void *pixelShader = *(void **)(programData + 0xc);

        if (pixelShader != *(void **)(dxState + 0x2138)) {
            do {
                device = *(byte **)(dx + 8);
                vtable = *(void ***)device;
                ((void (*)(void *, void *))vtable[0x1ac/4])(device, pixelShader);
            } while (*alwaysfails);
            *(void **)(dxState + 0x2138) = pixelShader;
        }
    }

    /* Set vertex shader (pass+0x8 -> programData -> vertexShader at offset 0xc) */
    {
        byte *programData = *(byte **)(pass + 0x8);
        void *vertexShader = *(void **)(programData + 0xc);

        if (vertexShader != *(void **)(dxState + 0x213c)) {
            do {
                device = *(byte **)(dx + 8);
                vtable = *(void ***)device;
                ((void (*)(void *, void *))vtable[0x170/4])(device, vertexShader);
            } while (*alwaysfails);
            *(void **)(dxState + 0x213c) = vertexShader;
        }
    }

    /* Set vertex declaration (pass+0x4 -> declArray -> decl at [vertDeclType] offset 8) */
    {
        byte *declArray = *(byte **)(pass + 0x4);
        void *decl = *(void **)(declArray + 8 + vertDeclType * 4);

        if (decl != *(void **)(dxState + 0x2140)) {
            do {
                device = *(byte **)(dx + 8);
                vtable = *(void ***)device;
                ((void (*)(void *, void *))vtable[0x15c/4])(device, decl);
            } while (*alwaysfails);
            *(void **)(dxState + 0x2140) = decl;
            *(int *)(dxState + 0x2144) = 0;
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
    const Material *material = *(const Material **)(tess + 0x5a7bc);
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
            refStateBits = (byte *)(*(byte **)(tess + 0x5a7bc)) + 0x2c;
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
                        byte *rule = ruleSet + 4 + ri2 * 0x20;
                        if ((*(int *)(refStateBits + 0) & *(int *)(rule + 4)) != *(int *)(rule + 0xc))
                            continue;
                        if ((*(int *)(refStateBits + 4) & *(int *)(rule + 8)) != *(int *)(rule + 0x10))
                            continue;

                        {
                            int k;
                            for (k = 0; k < 2; k++) {
                                stateBits[k] &= *(int *)(rule + 0x18 + k*4);
                                stateBits[k] |= *(int *)(rule + 0x10 + k*4);
                            }
                        }
                        matched = 1;
                        break;
                    }

                    if (!matched) {
                        const Material *mat2 = *(const Material **)(RB_TessBase() + 0x5a7bc);
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
            if (*(byte *)(backEnd + 0x4bd))
                stateBits[1] &= 0xffffffcf;

            /* Apply state bits changes */
            if (stateBits[0] != *(int *)(dxState + 0x2000)) {
                RB_ChangeState_0(stateBits[0]);
                *(int *)(dxState + 0x2000) = stateBits[0];
            }
            if (stateBits[1] != *(int *)(dxState + 0x2004)) {
                RB_ChangeState_1(stateBits[1]);
                *(int *)(dxState + 0x2004) = stateBits[1];
            }

            /* Update fog color: Dx7 pass uses normalFog(0) vs iteratorFog based on pass[8] */
            {
                int fogSrc = (*(byte *)(pass + 8) == 1) ? 0 : 2;
                RB_UpdateFogColor(fogSrc);
            }

            /* Set normalizeNormals render state if pass[4] differs */
            {
                byte passNormalize = *(byte *)(pass + 4);
                if (passNormalize != *(byte *)(dxState + 0x2094)) {
                    byte *dx = (byte *)imp_dx;
                    volatile int *af = (volatile int *)imp_alwaysfails;
                    do {
                        byte *dev = *(byte **)(dx + 8);
                        void **vt = *(void ***)dev;
                        ((void (*)(void *, int, int))vt[0xe4/4])(dev, 0x89,
                            passNormalize ? 1 : 0);
                    } while (*af);
                    *(byte *)(dxState + 0x2094) = passNormalize;
                }
            }

            /* Set FVF if vertex declaration changed */
            {
                DWORD fvf = s_fvfForVertDeclType[vertDeclType];
                if (*(void **)(dxState + 0x2140) != NULL) {
                    byte *dx = (byte *)imp_dx;
                    volatile int *af = (volatile int *)imp_alwaysfails;
                    do {
                        byte *dev = *(byte **)(dx + 8);
                        void **vt = *(void ***)dev;
                        ((void (*)(void *, DWORD))vt[0x164/4])(dev, fvf);
                    } while (*af);
                    *(DWORD *)(dxState + 0x2144) = fvf;
                    *(void **)(dxState + 0x2140) = NULL;
                } else if (fvf != *(DWORD *)(dxState + 0x2144)) {
                    byte *dx = (byte *)imp_dx;
                    volatile int *af = (volatile int *)imp_alwaysfails;
                    do {
                        byte *dev = *(byte **)(dx + 8);
                        void **vt = *(void ***)dev;
                        ((void (*)(void *, DWORD))vt[0x164/4])(dev, fvf);
                    } while (*af);
                    *(DWORD *)(dxState + 0x2144) = fvf;
                    *(void **)(dxState + 0x2140) = NULL;
                }
            }

            /* Set objective color sampler constant (if pass has Dx7 color) */
            if (*(byte *)(pass + 7)) {
                /* Compute animated objective color from dvars */
                byte *backEnd2 = backEnd;
                float phase = *(float *)(backEnd2 + 0x3bc);
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
                byte *stagePtr = pass + 0x1c;
                byte *dxStagePtr = dxState + 0x2014;

                for (stageIdx = 0; stageIdx < 8; stageIdx++) {
                    int colorBits = *(int *)stagePtr;
                    if (colorBits != *(int *)dxStagePtr) {
                        *(int *)dxStagePtr = colorBits;
                        RB_ChangeColorStageState(stageIdx, colorBits);
                    }

                    int alphaBits = *(int *)(stagePtr + 0x20);
                    if (alphaBits != *(int *)(dxStagePtr + 0x20)) {
                        *(int *)(dxStagePtr + 0x20) = alphaBits;
                        RB_ChangeAlphaStageState(stageIdx, alphaBits);
                    }

                    stagePtr += 4;
                    dxStagePtr += 4;
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
                byte *declArray = *(byte **)(pass + 4);
                void *decl = *(void **)(declArray + 8 + vertDeclType * 4);
                if (!decl) {
                    tess = RB_TessBase();
                    const Material *mat3 = *(const Material **)(tess + 0x5a7bc);
                    byte *pgm = *(byte **)(pass + 8);
                    R_Error(0, "Vertex type %i doesn't have the information used by shader %",
                        vertDeclType, *(char **)pgm, mat3->info.name);
                    tess = RB_TessBase();
                    continue;
                }
            }

            /* Get material refStateBits and stateMap */
            tess = RB_TessBase();
            refStateBits = (byte *)(*(byte **)(tess + 0x5a7bc)) + 0x2c;
            stateMap = *(byte **)(pass + 8);

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
                        byte *rule = ruleSet + 4 + ri2 * 0x20;
                        if ((*(int *)(refStateBits + 0) & *(int *)(rule + 4)) != *(int *)(rule + 0xc))
                            continue;
                        if ((*(int *)(refStateBits + 4) & *(int *)(rule + 8)) != *(int *)(rule + 0x10))
                            continue;

                        {
                            int k;
                            for (k = 0; k < 2; k++) {
                                stateBits[k] &= *(int *)(rule + 0x18 + k*4);
                                stateBits[k] |= *(int *)(rule + 0x10 + k*4);
                            }
                        }
                        matched = 1;
                        break;
                    }

                    if (!matched) {
                        const Material *mat4 = *(const Material **)(RB_TessBase() + 0x5a7bc);
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
            if (*(byte *)(backEnd + 0x4bd))
                stateBits[1] &= 0xffffffcf;

            /* Apply state bits changes */
            if (stateBits[0] != *(int *)(dxState + 0x2000)) {
                RB_ChangeState_0(stateBits[0]);
                *(int *)(dxState + 0x2000) = stateBits[0];
            }
            if (stateBits[1] != *(int *)(dxState + 0x2004)) {
                RB_ChangeState_1(stateBits[1]);
                *(int *)(dxState + 0x2004) = stateBits[1];
            }

            /* Update fog color */
            RB_UpdateFogColor(0);

            /* Set pixel shader, vertex shader, vertex declaration */
            RB_SetShaderAndDecl(pass, vertDeclType, dxState);

            /* Process texture routing entries */
            textureRoutingCount = *(unsigned short *)(pass + 0x10);
            textureRouting = *(byte **)(pass + 0x14);

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
                            const Material *mat5 = *(const Material **)(tess + 0x5a7bc);
                            int constCount = *(unsigned short *)((byte *)mat5 + 0x36);
                            byte *consts = *(byte **)((byte *)mat5 + 0x40);
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
            constantRoutingCount = *(unsigned short *)(pass + 0x12);
            constantRouting = *(byte **)(pass + 0x18);

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
                            const Material *mat5 = *(const Material **)(tess + 0x5a7bc);
                            int constCount = *(unsigned short *)((byte *)mat5 + 0x36);
                            byte *consts = *(byte **)((byte *)mat5 + 0x40);
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
                            const Material *mat6 = *(const Material **)(tess + 0x5a7bc);
                            int texCount = *(unsigned short *)((byte *)mat6 + 0x34);
                            byte *textures = *(byte **)((byte *)mat6 + 0x3c);
                            int ti;
                            for (ti = 0; ti < texCount; ti++) {
                                byte *texEntry = textures + ti * 0xc;
                                if (*(int *)texEntry == textureName) {
                                    /* Check semantic (offset +5) */
                                    byte semantic = texEntry[5];
                                    if (semantic == 5) {
                                        /* Water texture */
                                        void *img = *(void **)(texEntry + 8);
                                        void *water = *(void **)(*(byte **)(texEntry + 8) + 0x1c);
                                        image = *(void **)(water + 0x40);
                                    } else {
                                        image = *(void **)(texEntry + 8);
                                    }
                                    samplerState = texEntry[4];

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
        if (!*(byte *)(backEnd + 0x4bd)) {
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
            byte *techPtr = technique;
            if (*(byte *)(techPtr + 0xd)) {
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
#endif
