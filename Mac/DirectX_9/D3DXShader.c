/* Clean D3DXShader implementation for Linux/WebGL2 */
/* Shader compilation stubs — WebGL2 will use GLSL ES compiled differently */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

extern void *vtbl_CD3DXBuffer[];
extern void *vtbl_CD3DXConstantTable[];

/* --- CD3DXBuffer (ID3DXBuffer) --- */

typedef struct {
    void **vtable;
    ULONG refCount;
    void *data;
    UINT32 size;
} CD3DXBufferImpl;

HRESULT CD3DXBuffer_QueryInterface(const void *_this, const IID *iid, void **ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    return 0;
}

ULONG CD3DXBuffer_AddRef(const void *_this)
{
    CD3DXBufferImpl *buf = (CD3DXBufferImpl *)_this;
    return ++buf->refCount;
}

ULONG CD3DXBuffer_Release(const void *_this)
{
    CD3DXBufferImpl *buf = (CD3DXBufferImpl *)_this;
    ULONG rc = --buf->refCount;
    if (!rc) {
        free(buf->data);
        free(buf);
    }
    return rc;
}

void *CD3DXBuffer_GetBufferPointer(const void *_this)
{
    return ((CD3DXBufferImpl *)_this)->data;
}

UINT32 CD3DXBuffer_GetBufferSize(const void *_this)
{
    return ((CD3DXBufferImpl *)_this)->size;
}

void ZN11CD3DXBufferD1Ev(const void *_this)
{
    CD3DXBufferImpl *buf = (CD3DXBufferImpl *)_this;
    buf->vtable = vtbl_CD3DXBuffer;
    free(buf->data);
    buf->data = NULL;
}

void ZN11CD3DXBufferD0Ev(const void *_this)
{
    ZN11CD3DXBufferD1Ev(_this);
    free((void *)_this);
}

static CD3DXBufferImpl *CD3DXBuffer_Create(const void *data, UINT32 size)
{
    CD3DXBufferImpl *buf = (CD3DXBufferImpl *)calloc(1, sizeof(CD3DXBufferImpl));
    buf->vtable = vtbl_CD3DXBuffer;
    buf->refCount = 1;
    buf->size = size;
    if (size && data) {
        buf->data = malloc(size);
        memcpy(buf->data, data, size);
    } else if (size) {
        buf->data = calloc(1, size);
    }
    return buf;
}

/* --- CD3DXConstantTable (ID3DXConstantTable) --- */

typedef struct {
    void **vtable;
    ULONG refCount;
    void *data;
    UINT32 size;
} CD3DXConstantTableImpl;

HRESULT CD3DXConstantTable_QueryInterface(const void *_this, const IID *iid, void **ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    return 0;
}

ULONG CD3DXConstantTable_AddRef(const void *_this)
{
    return ++((CD3DXConstantTableImpl *)_this)->refCount;
}

ULONG CD3DXConstantTable_Release(const void *_this)
{
    CD3DXConstantTableImpl *ct = (CD3DXConstantTableImpl *)_this;
    ULONG rc = --ct->refCount;
    if (!rc) {
        free(ct->data);
        free(ct);
    }
    return rc;
}

void *CD3DXConstantTable_GetBufferPointer(const void *_this) { return ((CD3DXConstantTableImpl *)_this)->data; }
UINT32 CD3DXConstantTable_GetBufferSize(const void *_this) { return ((CD3DXConstantTableImpl *)_this)->size; }
HRESULT CD3DXConstantTable_GetDesc(const void *_this, void *pDesc) { (void)_this; memset(pDesc, 0, 32); return 0; }
HRESULT CD3DXConstantTable_GetConstantDesc(const void *_this, const void *hConstant, void *pConstantDesc, UINT *pCount) { (void)_this; (void)hConstant; (void)pConstantDesc; *pCount = 0; return 0; }
UINT CD3DXConstantTable_GetSamplerIndex(const void *_this, const void *hConstant) { (void)_this; (void)hConstant; return 0; }
void *CD3DXConstantTable_GetConstant(const void *_this, const void *hConstant, UINT Index) { (void)_this; (void)hConstant; (void)Index; return NULL; }
void *CD3DXConstantTable_GetConstantByName(const void *_this, const void *hConstant, const char *pName) { (void)_this; (void)hConstant; (void)pName; return NULL; }
void *CD3DXConstantTable_GetConstantElement(const void *_this, const void *hConstant, UINT Index) { (void)_this; (void)hConstant; (void)Index; return NULL; }
HRESULT CD3DXConstantTable_SetDefaults(const void *_this, void *pDevice) { (void)_this; (void)pDevice; return 0; }
HRESULT CD3DXConstantTable_SetValue(const void *_this, void *pDevice, const void *hConstant, const void *pData, UINT Bytes) { (void)_this; (void)pDevice; (void)hConstant; (void)pData; (void)Bytes; return 0; }
HRESULT CD3DXConstantTable_SetBool(const void *_this, void *d, const void *h, BOOL b) { (void)_this; (void)d; (void)h; (void)b; return 0; }
HRESULT CD3DXConstantTable_SetBoolArray(const void *_this, void *d, const void *h, const BOOL *b, UINT n) { (void)_this; (void)d; (void)h; (void)b; (void)n; return 0; }
HRESULT CD3DXConstantTable_SetInt(const void *_this, void *d, const void *h, INT n) { (void)_this; (void)d; (void)h; (void)n; return 0; }
HRESULT CD3DXConstantTable_SetIntArray(const void *_this, void *d, const void *h, const INT *n, UINT c) { (void)_this; (void)d; (void)h; (void)n; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetFloat(const void *_this, void *d, const void *h, float f) { (void)_this; (void)d; (void)h; (void)f; return 0; }
HRESULT CD3DXConstantTable_SetFloatArray(const void *_this, void *d, const void *h, const float *f, UINT c) { (void)_this; (void)d; (void)h; (void)f; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetVector(const void *_this, void *d, const void *h, const void *v) { (void)_this; (void)d; (void)h; (void)v; return 0; }
HRESULT CD3DXConstantTable_SetVectorArray(const void *_this, void *d, const void *h, const void *v, UINT c) { (void)_this; (void)d; (void)h; (void)v; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetMatrix(const void *_this, void *d, const void *h, const void *m) { (void)_this; (void)d; (void)h; (void)m; return 0; }
HRESULT CD3DXConstantTable_SetMatrixArray(const void *_this, void *d, const void *h, const void *m, UINT c) { (void)_this; (void)d; (void)h; (void)m; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetMatrixPointerArray(const void *_this, void *d, const void *h, const void **m, UINT c) { (void)_this; (void)d; (void)h; (void)m; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetMatrixTranspose(const void *_this, void *d, const void *h, const void *m) { (void)_this; (void)d; (void)h; (void)m; return 0; }
HRESULT CD3DXConstantTable_SetMatrixTransposeArray(const void *_this, void *d, const void *h, const void *m, UINT c) { (void)_this; (void)d; (void)h; (void)m; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetMatrixTransposePointerArray(const void *_this, void *d, const void *h, const void **m, UINT c) { (void)_this; (void)d; (void)h; (void)m; (void)c; return 0; }

void ZN18CD3DXConstantTableD1Ev(const void *_this)
{
    CD3DXConstantTableImpl *ct = (CD3DXConstantTableImpl *)_this;
    ct->vtable = vtbl_CD3DXConstantTable;
    free(ct->data);
    ct->data = NULL;
}

void ZN18CD3DXConstantTableD0Ev(const void *_this)
{
    ZN18CD3DXConstantTableD1Ev(_this);
    free((void *)_this);
}

/* --- D3DXCompileShader — HLSL→ARB translator for CoD2 Mac port --- */
/*
 * The Mac port's D3DXCompileShader compiled HLSL to ARB assembly.
 * We detect the shader type from the HLSL source and return pre-written
 * ARB programs matching CoD2's register layout (see globals.hlsl):
 *
 * VS constants: c0-c3 = worldViewProjectionMatrix, c4-c7 = worldMatrix,
 *               c8-c11 = worldViewMatrix/inverseTransposeWorldMatrix
 * PS constants: c11 = fogConsts, c21 = fogColor, c23 = materialColor
 * VS semantics: position, color, texcoord0, texcoord1, texcoord2, texcoord3, normal
 * PS samplers:  texture[0]=colorMap, texture[1..4]=lightmaps, texture[5]=normalMap
 */

/* Helper: check if source contains a substring */
static int hlsl_has(const char *src, int len, const char *needle) {
    int nlen = strlen(needle);
    int i;
    for (i = 0; i <= len - nlen; i++) {
        if (memcmp(src + i, needle, nlen) == 0) return 1;
    }
    return 0;
}

/* ---- ARB Vertex Program templates ---- */

/* All VS templates use state.matrix.mvp (the GL fixed-function MVP matrix)
 * because the game's D3D constant routing doesn't populate program.env[0..3].
 * The DIP function sets up the GL matrices via glMatrixMode/glLoadMatrixf
 * before each draw, and the VP reads them via state.matrix.mvp. */

/* Lightmap VS: transform pos, pass color, texcoords, lmap coords, fog */
static const char *arb_vs_lightmap =
    "!!ARBvp1.0\n"
    "PARAM mvp[4] = { state.matrix.mvp };\n"
    ""
    "ATTRIB iPos = vertex.position;\n"
    "ATTRIB iCol = vertex.color;\n"
    "ATTRIB iTc0 = vertex.texcoord[0];\n"
    "ATTRIB iTc1 = vertex.texcoord[1];\n"
    "OUTPUT oPos = result.position;\n"
    "OUTPUT oCol = result.color;\n"
    "OUTPUT oTc0 = result.texcoord[0];\n"
    "OUTPUT oTc1 = result.texcoord[1];\n"
    "OUTPUT oFog = result.fogcoord;\n"
    ""
    "DP4 oPos.x, iPos, mvp[0];\n"
    "DP4 oPos.y, iPos, mvp[1];\n"
    "DP4 oPos.z, iPos, mvp[2];\n"
    "DP4 oPos.w, iPos, mvp[3];\n"
    "MOV oCol, iCol;\n"
    "MOV oTc0, iTc0;\n"
    "MOV oTc1, iTc1;\n"
    "MOV oFog.x, {1}.x;\n"  /* fog=1 → no fog for now */
    "END\n";

/* Simple VS: transform position, pass color + texcoord0, compute fog */
static const char *arb_vs_simple =
    "!!ARBvp1.0\n"
    "PARAM mvp[4] = { state.matrix.mvp };\n"
    ""
    "ATTRIB iPos = vertex.position;\n"
    "ATTRIB iCol = vertex.color;\n"
    "ATTRIB iTc0 = vertex.texcoord[0];\n"
    "OUTPUT oPos = result.position;\n"
    "OUTPUT oCol = result.color;\n"
    "OUTPUT oTc0 = result.texcoord[0];\n"
    "OUTPUT oFog = result.fogcoord;\n"
    ""
    "DP4 oPos.x, iPos, mvp[0];\n"
    "DP4 oPos.y, iPos, mvp[1];\n"
    "DP4 oPos.z, iPos, mvp[2];\n"
    "DP4 oPos.w, iPos, mvp[3];\n"
    "MOV oCol, iCol;\n"
    "MOV oTc0, iTc0;\n"
    "MOV oFog.x, {1}.x;\n"  /* fog=1 → no fog for now */
    "END\n";

/* Sky VS: transform position, pass direction as texcoord for cubemap */
static const char *arb_vs_sky =
    "!!ARBvp1.0\n"
    "PARAM mvp[4] = { state.matrix.mvp };\n"
    "ATTRIB iPos = vertex.position;\n"
    "OUTPUT oPos = result.position;\n"
    "OUTPUT oTc0 = result.texcoord[0];\n"
    "DP4 oPos.x, iPos, mvp[0];\n"
    "DP4 oPos.y, iPos, mvp[1];\n"
    "DP4 oPos.z, iPos, mvp[2];\n"
    "DP4 oPos.w, iPos, mvp[3];\n"
    "MOV oTc0.xyz, iPos;\n"
    "END\n";

/* Passthrough VS: just transform position, pass color */
static const char *arb_vs_passthrough =
    "!!ARBvp1.0\n"
    "PARAM mvp[4] = { state.matrix.mvp };\n"
    "ATTRIB iPos = vertex.position;\n"
    "ATTRIB iCol = vertex.color;\n"
    "ATTRIB iTc0 = vertex.texcoord[0];\n"
    "OUTPUT oPos = result.position;\n"
    "OUTPUT oCol = result.color;\n"
    "OUTPUT oTc0 = result.texcoord[0];\n"
    "DP4 oPos.x, iPos, mvp[0];\n"
    "DP4 oPos.y, iPos, mvp[1];\n"
    "DP4 oPos.z, iPos, mvp[2];\n"
    "DP4 oPos.w, iPos, mvp[3];\n"
    "MOV oCol, iCol;\n"
    "MOV oTc0, iTc0;\n"
    "END\n";

/* ---- ARB Fragment Program templates ---- */

/* Lightmap PS: sample colorMap × vertexColor, sample lightmap, combine.
 * texture[0] = colorMap, texture[1] = lightmapSun (used as simple lightmap) */
static const char *arb_ps_lightmap =
    "!!ARBfp1.0\n"
    "OPTION ARB_precision_hint_fastest;\n"
    "OUTPUT oC0AfterFog = result.color;\n"
    "TEMP r0, r1, oC0;\n"
    "ATTRIB v0 = fragment.color.primary;\n"
    "ATTRIB t0 = fragment.texcoord[0];\n"
    "ATTRIB t1 = fragment.texcoord[1];\n"
    "TEX r0, t0, texture[0], 2D;\n"      /* sample color map */
    "TEX r1, t1, texture[1], 2D;\n"      /* sample lightmap */
    "MUL r0, r0, v0;\n"                  /* color × vertex color */
    "MUL oC0.rgb, r0, r1;\n"             /* color × lightmap */
    "MOV oC0.a, r0.a;\n"
    /* Fog blend */
    "MAX r1.x, fragment.fogcoord.x, {0}.x;\n"
    "MIN r1.x, r1.x, {1}.x;\n"
    "LRP oC0AfterFog.xyz, r1.x, oC0, state.fog.color;\n"
    "MOV oC0AfterFog.w, oC0.w;\n"
    "END\n";

/* Lightmap PS with alpha test */
static const char *arb_ps_lightmap_alpha =
    "!!ARBfp1.0\n"
    "OPTION ARB_precision_hint_fastest;\n"
    "OUTPUT oC0AfterFog = result.color;\n"
    "TEMP r0, r1, oC0;\n"
    "ATTRIB v0 = fragment.color.primary;\n"
    "ATTRIB t0 = fragment.texcoord[0];\n"
    "ATTRIB t1 = fragment.texcoord[1];\n"
    "TEX r0, t0, texture[0], 2D;\n"
    "TEX r1, t1, texture[1], 2D;\n"
    "MUL r0, r0, v0;\n"
    "MUL oC0.rgb, r0, r1;\n"
    "MOV oC0.a, r0.a;\n"
    "MAX r1.x, fragment.fogcoord.x, {0}.x;\n"
    "MIN r1.x, r1.x, {1}.x;\n"
    "LRP oC0AfterFog.xyz, r1.x, oC0, state.fog.color;\n"
    "MOV oC0AfterFog.w, oC0.w;\n"
    "END\n";

/* Textured PS: sample colorMap and modulate by vertex color/alpha. */
static const char *arb_ps_textured =
    "!!ARBfp1.0\n"
    "OPTION ARB_precision_hint_fastest;\n"
    "OUTPUT oC0AfterFog = result.color;\n"
    "TEMP r0, r1;\n"
    "ATTRIB v0 = fragment.color.primary;\n"
    "ATTRIB t0 = fragment.texcoord[0];\n"
    "TEX r0, t0, texture[0], 2D;\n"
    "MUL r0, r0, v0;\n"
    "MAX r1.x, fragment.fogcoord.x, {0}.x;\n"
    "MIN r1.x, r1.x, {1}.x;\n"
    "LRP oC0AfterFog.xyz, r1.x, r0, state.fog.color;\n"
    "MOV oC0AfterFog.w, r0.w;\n"
    "END\n";

/* Vertex color only PS: just pass vertex color */
static const char *arb_ps_vertcolor =
    "!!ARBfp1.0\n"
    "OPTION ARB_precision_hint_fastest;\n"
    "OUTPUT oC0AfterFog = result.color;\n"
    "TEMP r0, oC0;\n"
    "ATTRIB v0 = fragment.color.primary;\n"
    "MOV oC0, v0;\n"
    "MAX r0.x, fragment.fogcoord.x, {0}.x;\n"
    "MIN r0.x, r0.x, {1}.x;\n"
    "LRP oC0AfterFog.xyz, r0.x, oC0, state.fog.color;\n"
    "MOV oC0AfterFog.w, oC0.w;\n"
    "END\n";

/* Sky PS: cubemap sample */
static const char *arb_ps_sky =
    "!!ARBfp1.0\n"
    "OUTPUT oC0 = result.color;\n"
    "TEMP r0;\n"
    "ATTRIB t0 = fragment.texcoord[0];\n"
    "TEX r0, t0, texture[0], CUBE;\n"
    "MOV r0.w, {0}.x;\n"
    "MOV oC0, r0;\n"
    "END\n";

/* Passthrough PS: just output vertex color */
static const char *arb_ps_passthrough =
    "!!ARBfp1.0\n"
    "OUTPUT oC0 = result.color;\n"
    "ATTRIB v0 = fragment.color.primary;\n"
    "MOV oC0, v0;\n"
    "END\n";

/* Multiply/blend PS: colorMap modulated by materialColor */
static const char *arb_ps_multiply =
    "!!ARBfp1.0\n"
    "OPTION ARB_precision_hint_fastest;\n"
    "PARAM matColor = program.env[23];\n"
    "OUTPUT oC0AfterFog = result.color;\n"
    "TEMP r0, r1, oC0;\n"
    "ATTRIB v0 = fragment.color.primary;\n"
    "ATTRIB t0 = fragment.texcoord[0];\n"
    "TEX r0, t0, texture[0], 2D;\n"
    "MUL r1.xyz, v0, r0;\n"
    "MAD oC0.xyz, matColor.w, r1, r0;\n"
    "MOV oC0.w, r0.w;\n"
    "MAX r1.x, fragment.fogcoord.x, {0}.x;\n"
    "MIN r1.x, r1.x, {1}.x;\n"
    "LRP oC0AfterFog.xyz, r1.x, oC0, state.fog.color;\n"
    "MOV oC0AfterFog.w, oC0.w;\n"
    "END\n";

/* Depth-only PS: output constant color (for z-prepass) */
static const char *arb_ps_depth =
    "!!ARBfp1.0\n"
    "OUTPUT oC0 = result.color;\n"
    "MOV oC0, {1, 1, 1, 1};\n"
    "END\n";

/* DEBUG: solid green PS to test if geometry is on screen */
static const char *arb_ps_debug_green =
    "!!ARBfp1.0\n"
    "OUTPUT oC0 = result.color;\n"
    "MOV oC0, {0, 1, 0, 1};\n"
    "END\n";

HRESULT D3DXCompileShader(
    const char *pSrcData, UINT SrcDataLen,
    const void *pDefines, void *pInclude,
    const char *pFunctionName, const char *pProfile,
    DWORD Flags, void **ppShader, void **ppErrorMsgs,
    void **ppConstantTable)
{
    const char *arbCode = NULL;
    int isVS = 0;
    int len = (int)SrcDataLen;

    (void)pDefines; (void)pInclude; (void)Flags;

    if (ppErrorMsgs) *ppErrorMsgs = NULL;

    /* Determine vertex vs pixel shader from profile string */
    if (pProfile && pProfile[0] == 'v' && pProfile[1] == 's')
        isVS = 1;

    if (isVS) {
        /* --- Vertex shader selection --- */
        if (hlsl_has(pSrcData, len, "texCUBE") || hlsl_has(pSrcData, len, "cubeMapSampler")) {
            arbCode = arb_vs_sky;
        } else if (hlsl_has(pSrcData, len, "lmapCoords") || hlsl_has(pSrcData, len, "lightmap")) {
            arbCode = arb_vs_lightmap;
        } else if (hlsl_has(pSrcData, len, "texCoords") || hlsl_has(pSrcData, len, "colorMapSampler")) {
            arbCode = arb_vs_simple;
        } else {
            arbCode = arb_vs_passthrough;
        }
    } else {
        /* --- Pixel shader selection --- */
        if (hlsl_has(pSrcData, len, "texCUBE")) {
            arbCode = arb_ps_sky;
        } else if (hlsl_has(pSrcData, len, "lightmapSampler") || hlsl_has(pSrcData, len, "lmapCoords")
                   || hlsl_has(pSrcData, len, "lightmap")) {
            arbCode = arb_ps_lightmap;
        } else if (hlsl_has(pSrcData, len, "colorMapSampler") || hlsl_has(pSrcData, len, "tex2D")) {
            arbCode = arb_ps_textured;
        } else {
            arbCode = arb_ps_vertcolor;
        }
    }

    /* Return the ARB assembly as the shader blob */
    if (ppShader) {
        int arbLen = strlen(arbCode) + 1;
        *ppShader = CD3DXBuffer_Create(arbCode, arbLen);
    }

    if (ppConstantTable) {
        CD3DXConstantTableImpl *ct = (CD3DXConstantTableImpl *)calloc(1, sizeof(CD3DXConstantTableImpl));
        ct->vtable = vtbl_CD3DXConstantTable;
        ct->refCount = 1;
        *ppConstantTable = ct;
    }

    return 0;
}

/* --- IncludeClass for D3DX shader includes --- */
/* The renderer's Material_PreLoadSingleShaderText creates an include handler.
   IncludeClass_Open is called during shader compilation to resolve #include directives. */

int IncludeClass_Open(void *_this, int IncludeType, const char *pFileName,
    const void *pParentData, const void **ppData, UINT *pBytes)
{
    (void)_this; (void)IncludeType; (void)pParentData;
    (void)pFileName;
    /* Return empty include — shader compilation is stubbed anyway */
    *ppData = "";
    *pBytes = 0;
    return 0;
}

int IncludeClass_Close(void *_this, const void *pData)
{
    (void)_this; (void)pData;
    return 0;
}
