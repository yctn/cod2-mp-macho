/* ASM dump from: rb_state.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_state.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/gfx_d3d/rb_state.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

extern struct DxState dxState; /* 0x0 */
extern r_backEndGlobals_t backEnd; /* imp_backEnd */
static const DxTextureStageEnums texStageEnums; /* texStageEnums */
static const DxTextureStageEnums texStageEnums_002f24ac; /* texStageEnums */
static const DxTextureStageEnums texStageEnums_002f24ac; /* texStageEnums */
extern const byte defaultSamplerStateTable[]; /* rodata.c */
extern const DWORD s_blendTable[]; /* rodata.c */
extern const DWORD s_blendOpTable[]; /* rodata.c */
extern const DWORD s_cullTable[]; /* rodata.c */
extern const D3DTEXTUREFILTERTYPE s_filterTable[]; /* rodata.c */
extern const DWORD s_stencilOpTable[]; /* rodata.c */
extern const DWORD s_stencilFuncTable[]; /* rodata.c */
extern const DxStencilDecode s_stencilOpDecode[]; /* rodata.c */
extern const DxStencilDecode s_stencilFuncDecode[]; /* rodata.c */
extern const DxTextureOpDecode s_textureOpTable[]; /* rodata.c */
extern const DWORD s_textureArgTable[]; /* rodata.c */
extern const GfxViewportBehavior s_viewportBehaviorForRenderTarget[]; /* rodata.c */

#define VTABLE(obj) (*(void ***)((void *)(obj)))

typedef HRESULT (*SetIndicesFn)(void *device, IDirect3DIndexBuffer9 *ib);
typedef HRESULT (*SetRenderStateFn)(void *device, DWORD state, DWORD value);
typedef HRESULT (*SetRenderTargetFn)(void *device, DWORD index, IDirect3DSurface9 *surface);
typedef HRESULT (*SetDepthStencilSurfaceFn)(void *device, IDirect3DSurface9 *surface);
typedef HRESULT (*SetStreamSourceFn)(void *device, UINT streamIndex, IDirect3DVertexBuffer9 *vb, UINT vertexOffset, UINT vertexStride);
typedef HRESULT (*SetSamplerStateFn)(void *device, DWORD samplerIndex, DWORD samplerState, DWORD value);
typedef HRESULT (*SetTextureFn)(void *device, DWORD samplerIndex, IDirect3DBaseTexture9 *texture);
typedef HRESULT (*SetTextureStageStateFn)(void *device, DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value);
typedef HRESULT (*SetTransformFn)(void *device, D3DTRANSFORMSTATETYPE state, const D3DMATRIX *matrix);
typedef HRESULT (*SetMaterialFn)(void *device, const D3DMATERIAL9 *material);
typedef HRESULT (*SetViewportFn)(void *device, const D3DVIEWPORT9 *viewport);
typedef HRESULT (*SetVertexDeclarationFn)(void *device, IDirect3DVertexDeclaration9 *vertexDecl);

typedef struct {
    IDirect3DVertexBuffer9 *vb;
    int offset;
    int stride;
} DxTrackedStreamState;

extern void MatrixInverse44(const float *mat, float *dst);
extern void MatrixIdentity44(float (*out)[4]);
extern void MatrixSet44(float (*out)[4], const vec_t *origin, vec3_t *axis, vec_t scale);
extern void RB_SetCodeConstant(int constant, vec_t x, vec_t y, vec_t z, vec_t w);

enum {
    RB_STENCIL_OP_DECODE_COUNT = 6,
    RB_STENCIL_FUNC_DECODE_COUNT = 2,
    RB_STATE1_DEPTH_WRITE = 0x00000001,
    RB_STATE1_DEPTH_TEST_DISABLE = 0x00000002,
    RB_STATE1_DEPTH_FUNC_MASK = 0x0000000c,
    RB_STATE1_POLYGON_OFFSET_MASK = 0x00000030,
    RB_STATE1_STENCIL_ENABLE = 0x00000040,
    RB_STATE1_STENCIL_TWO_SIDED = 0x00000080,
    RB_STATE1_STENCIL_DISABLED_MASK = 0x0000007f,
    RB_STATE1_FRONT_STENCIL_MASK = 0x000fffff,
    RB_STATE1_STENCIL_OP_MASK = 0x1ff1ff00,
    RB_STATE1_STENCIL_FUNC_MASK = 0xe00e0000
};

void RB_ChangeIndices(IDirect3DIndexBuffer9 *ib);
void RB_ChangeStreamSource(int streamIndex, IDirect3DVertexBuffer9 *vb, int vertexOffset, int vertexStride);
void RB_DecideDefaultSamplerState(void);
void RB_SetAnisotropy(void);
void RB_SetAlphaAntiAliasingState(int stateBits0);
static __attribute__((regparm(3))) void RB_ChangeTextureStageState(int stageIndex, const DxTextureStageEnums *texStageEnums, int texStageBits, int *activeTexStageBits);
void RB_ChangeAlphaStageState(int stageIndex, int texStageBits);
void RB_ChangeColorStageState(int stageIndex, int texStageBits);
void RB_SetSamplerConstantDx7(unsigned int color);
void RB_ChangeGenTexCoords(int samplerIndex, int genTexCoords);
D3DMATRIX * RB_GetActiveWorldMatrix(void);
void RB_ChangedWorldMatrix(float worldScale);
void RB_SetViewMatrix(const D3DMATRIX *matrix);
void RB_SetViewMatrixForWDx7(float w);
void RB_SetDepthHackNearClip(float nearClip);
void RB_SetShadowLookupMatrix(const D3DMATRIX *matrix);
void RB_SetMatricesForView(const GfxViewParms *viewParms);
void RB_PushMatrixStack(void);
void RB_PopMatrixStack(void);
void RB_InitSceneViewport(void);
Bool RB_GetViewport(GfxViewport *outViewport);
void RB_SetDepthRange(float nearValue, float farValue);
void RB_SetViewport(const GfxViewport *viewport);
void RB_ReleaseVertexDecl(void);
void RB_ChangeState_1(int stateBits1);
void RB_SetSampler(int samplerIndex, int samplerState, GfxImage *image);
void RB_BindDefaultImages(void);
void RB_UnbindAllImages(void);
void RB_UnbindImage(const GfxImage *image);
void RB_UpdateViewportConstants(void);
void RB_InitImages(void);
void RB_SetRenderTarget(GfxRenderTargetId newTargetId);
void RB_ClearAllStreamSources(void);
void RB_ChangeState_0(int stateBits0);
void RB_SetProjectionMatrix(const D3DMATRIX *matrix);
void RB_UpdateViewport(void);
void RB_SetInitialState(void);
void RB_SetWorldMatrixForEntity(const GfxEntity *re);

static void RB_SetTextureStageStateDx7(int samplerIndex, D3DTEXTURESTAGESTATETYPE state, DWORD value)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetTextureStageStateFn)VTABLE(device)[0x10c / 4])(device, samplerIndex, state, value);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

static void RB_SetRenderStateDx7(DWORD state, DWORD value)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetRenderStateFn)VTABLE(device)[0xe4 / 4])(device, state, value);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

static void RB_SetTransformDx7(D3DTRANSFORMSTATETYPE state, const D3DMATRIX *matrix)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetTransformFn)VTABLE(device)[0xb0 / 4])(device, state, matrix);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

static void RB_SetViewportDx7(const D3DVIEWPORT9 *viewport)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetViewportFn)VTABLE(device)[0xbc / 4])(device, viewport);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

static void RB_SetMaterialDx7(const D3DMATERIAL9 *material)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    ((SetMaterialFn)VTABLE(device)[0xc4 / 4])(device, material);
}

static void RB_SetRenderTargetSurfaceDx7(IDirect3DSurface9 *surface)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetRenderTargetFn)VTABLE(device)[0x94 / 4])(device, 0, surface);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

static void RB_SetDepthStencilSurfaceDx7(IDirect3DSurface9 *surface)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetDepthStencilSurfaceFn)VTABLE(device)[0x9c / 4])(device, surface);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

static void RB_SetTextureDx7(int samplerIndex, IDirect3DBaseTexture9 *texture)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetTextureFn)VTABLE(device)[0x104 / 4])(device, samplerIndex, texture);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

static void RB_SetSamplerStateDx7(int samplerIndex, DWORD samplerState, DWORD value)
{
    void *device;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetSamplerStateFn)VTABLE(device)[0x114 / 4])(device, samplerIndex, samplerState, value);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

static void RB_SetRenderStateFloatDx7(DWORD state, float value)
{
    union {
        float value;
        DWORD bits;
    } packedValue;

    packedValue.value = value;
    RB_SetRenderStateDx7(state, packedValue.bits);
}

static GfxCodeMatrices *RB_GetActiveCodeMatrices(void)
{
    return &backEnd.codeMatrixStack[backEnd.codeMatrixStackLevel];
}

static Bool RB_UsingDx7Renderer(void);

static void RB_InvalidateCodeMatrix(GfxCodeMatrix *matrix)
{
    matrix->valid[0] = 0;
    matrix->valid[1] = 0;
    matrix->valid[2] = 0;
    matrix->valid[3] = 0;
}

static void RB_ValidatePrimaryCodeMatrix(GfxCodeMatrix *matrix)
{
    matrix->valid[0] = 1;
    matrix->valid[1] = 0;
    matrix->valid[2] = 0;
    matrix->valid[3] = 0;
}

static void RB_SetPrimaryCodeMatrix(GfxCodeMatrix *matrix, const D3DMATRIX *src)
{
    matrix->matrix[0] = *src;
    RB_ValidatePrimaryCodeMatrix(matrix);
}

static void RB_FinalizeWorldMatrixChange(GfxCodeMatrices *activeMatrices, float worldScale)
{
    activeMatrices->worldScale = worldScale;
    RB_ValidatePrimaryCodeMatrix(&activeMatrices->world);
    RB_InvalidateCodeMatrix(&activeMatrices->normalizedWorld);
    RB_InvalidateCodeMatrix(&activeMatrices->worldView);
    RB_InvalidateCodeMatrix(&activeMatrices->normalizedWorldView);
    RB_InvalidateCodeMatrix(&activeMatrices->worldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->normalizedWorldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->shadowLookupMatrix);
    RB_InvalidateCodeMatrix(&activeMatrices->lightGridLookupMatrix);
    RB_InvalidateCodeMatrix(&activeMatrices->worldOutdoorLookup);
    RB_InvalidateCodeMatrix(&activeMatrices->OGLworldViewProjection);

    if (RB_UsingDx7Renderer()) {
        RB_SetTransformDx7(0x100, &activeMatrices->world.matrix[0]);
    }
}

static Bool RB_UsingDx7Renderer(void)
{
    return (*(const dvar_t **)imp_r_rendererInUse)->current.integer == 2;
}

static Bool RB_SupportsSlopeScaleDepthBias(void)
{
    /* This capability flag is still only recovered as a raw DxGlobals offset. */
    return *(const byte *)((const byte *)imp_dx + 0x2d7a) != 0;
}

static int RB_NextPowerOfTwo(int value)
{
    int powerOfTwo;

    if (value <= 1) {
        return 1;
    }

    powerOfTwo = 1;
    while (powerOfTwo < value) {
        powerOfTwo <<= 1;
    }

    return powerOfTwo;
}

static void RB_GetSamplerFilterModes(byte samplerState, DWORD *minFilter, DWORD *magFilter)
{
    DxGlobals *dx;

    dx = (DxGlobals *)imp_dx;
    *minFilter = s_filterTable[samplerState & 3];
    *magFilter = *minFilter;
    if (*minFilter == D3DTEXF_ANISOTROPIC) {
        if (dx->anisotropy > 0) {
            *magFilter = D3DTEXF_LINEAR;
        } else {
            *minFilter = D3DTEXF_LINEAR;
            *magFilter = D3DTEXF_LINEAR;
        }
    }
}

/* line 1805 */
void RB_ChangeIndices(IDirect3DIndexBuffer9 *ib)
{
    void *device;

    dxState.indexBufferDeselecting = dxState.indexBuffer;
    dxState.indexBuffer = ib;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetIndicesFn)VTABLE(device)[0x1a0 / 4])(device, ib);
    } while (*(volatile int *)imp_alwaysfails != 0);

    dxState.indexBufferDeselecting = NULL;
}

/* line 1816 */
void RB_ChangeStreamSource(int streamIndex, IDirect3DVertexBuffer9 *vb, int vertexOffset, int vertexStride)
{
    DxTrackedStreamState *streamState;
    void *device;

    streamState = (DxTrackedStreamState *)((byte *)&dxState + 8400 + streamIndex * sizeof(*streamState));
    dxState.vertexBufferDeselecting = streamState->vb;
    streamState->vb = vb;
    streamState->offset = vertexOffset;
    streamState->stride = vertexStride;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetStreamSourceFn)VTABLE(device)[0x190 / 4])(device, streamIndex, vb, vertexOffset, vertexStride);
    } while (*(volatile int *)imp_alwaysfails != 0);

    dxState.vertexBufferDeselecting = NULL;
}

/* line 899 */
void RB_DecideDefaultSamplerState(void)
{
    int idx = *(int *)((byte *)*(void **)imp_r_textureMode + 8);
    *((byte *)imp_backEnd + 0x4be) = defaultSamplerStateTable[idx];
}

/* line 907 */
void RB_SetAnisotropy(void)
{
    const dvar_t *anisotropyDvar;
    DxGlobals *dx;
    void *device;
    int anisotropy;
    int samplerCount;
    int samplerIndex;

    anisotropyDvar = *(const dvar_t **)imp_r_anisotropy;
    dx = (DxGlobals *)imp_dx;
    dx->anisotropy = anisotropyDvar->current.integer;
    if (dx->anisotropy > dx->maxAnisotropy) {
        dx->anisotropy = dx->maxAnisotropy;
    }
    if (dx->anisotropy <= 1) {
        dx->anisotropy = 0;
    }

    anisotropy = dx->anisotropy;
    if (anisotropy < 1) {
        anisotropy = 1;
    }

    samplerCount = *(int *)((byte *)imp_vidConfig + 0x1c);
    if (samplerCount <= 0) {
        return;
    }

    device = *(void **)((byte *)imp_dx + 8);
    for (samplerIndex = 0; samplerIndex < samplerCount; ++samplerIndex) {
        do {
            ((SetSamplerStateFn)VTABLE(device)[0x114 / 4])(device, samplerIndex, 0xa, anisotropy);
        } while (*(volatile int *)imp_alwaysfails != 0);
    }
}

/* line 438 */
void RB_SetAlphaAntiAliasingState(int stateBits0)
{
    void *device;
    DWORD aaAlphaFormat;

    if (stateBits0 & 0xf00) {
        aaAlphaFormat = 0;
    } else if ((*(const dvar_t **)imp_r_aaAlpha)->current.integer == 2) {
        aaAlphaFormat = 0x41415353; /* 'SSAA' */
    } else {
        aaAlphaFormat = 0x434f5441; /* 'ATOC' */
    }

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetRenderStateFn)VTABLE(device)[0xe4 / 4])(device, 0xb5, aaAlphaFormat);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

/* line 781 */
static __attribute__((regparm(3)))
void RB_ChangeTextureStageState(int stageIndex, const DxTextureStageEnums *texStageEnums, int texStageBits, int *activeTexStageBits)
{
    int *activeTexStageState;
    int changedBits;
    const DxTextureOpDecode *texOp;
    int argIndex;
    int argShift;
    int argMask;

    activeTexStageState = &activeTexStageBits[stageIndex];
    changedBits = texStageBits ^ *activeTexStageState;
    texOp = &s_textureOpTable[texStageBits & 0x1f];

    if (changedBits & 0x1f) {
        RB_SetTextureStageStateDx7(stageIndex, texStageEnums->op, texOp->enumerant);
    }

    argShift = 10;
    argMask = 0x7c00;
    for (argIndex = 0; argIndex < 3; ++argIndex) {
        if (changedBits & argMask) {
            if (texOp->usedArgs & (1 << argIndex)) {
                unsigned int argStateBits;
                DWORD texArg;

                argStateBits = (unsigned int)texStageBits >> argShift;
                texArg = s_textureArgTable[argStateBits & 7];
                if (argStateBits & 8) {
                    texArg |= 0x10;
                }
                if (argStateBits & 0x10) {
                    texArg |= 0x20;
                }

                RB_SetTextureStageStateDx7(stageIndex, texStageEnums->arg[argIndex], texArg);
            } else {
                texStageBits = (texStageBits & ~argMask) | (*activeTexStageState & argMask);
            }
        }

        argShift += 5;
        argMask <<= 5;
    }

    *activeTexStageState = texStageBits;
}

/* line 837 */
void RB_ChangeAlphaStageState(int stageIndex, int texStageBits)
{
    RB_ChangeTextureStageState(stageIndex, &texStageEnums, texStageBits, dxState.activeAlphaStageBits);
}

/* line 823 */
void RB_ChangeColorStageState(int stageIndex, int texStageBits)
{
    RB_ChangeTextureStageState(stageIndex, &texStageEnums, texStageBits, dxState.activeColorStageBits);
}

/* line 851 */
void RB_SetSamplerConstantDx7(unsigned int color)
{
    void *device;

    if (color == dxState.textureFactor) {
        return;
    }

    dxState.textureFactor = color;
    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetRenderStateFn)VTABLE(device)[0xe4 / 4])(device, 0x3c, color);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

/* line 861 */
void RB_ChangeGenTexCoords(int samplerIndex, int genTexCoords)
{
    D3DMATRIX transform;

    switch ((byte)genTexCoords) {
    case 0:
        RB_SetTextureStageStateDx7(samplerIndex, D3DTSS_TEXCOORDINDEX, samplerIndex);
        RB_SetTextureStageStateDx7(samplerIndex, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
        break;
    case 1:
        MatrixInverse44((const float *)&backEnd.viewParms->viewMatrix, (float *)&transform);
        transform._41 = 0.0f;
        transform._42 = 0.0f;
        transform._43 = 0.0f;
        RB_SetTextureStageStateDx7(samplerIndex, D3DTSS_TEXCOORDINDEX, 0x20000);
        RB_SetTextureStageStateDx7(samplerIndex, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT3);
        RB_SetTransformDx7(D3DTS_TEXTURE0 + samplerIndex, &transform);
        break;
    case 2:
        MatrixIdentity44(transform.m);
        transform._32 = -backEnd.viewParms->depthHackNearClip;
        RB_SetTextureStageStateDx7(samplerIndex, D3DTSS_TEXCOORDINDEX, samplerIndex);
        RB_SetTextureStageStateDx7(samplerIndex, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT3);
        RB_SetTransformDx7(D3DTS_TEXTURE0 + samplerIndex, &transform);
        break;
    default:
        break;
    }

    dxState.genTexCoords[samplerIndex] = (byte)genTexCoords;
}

/* line 1059 */
D3DMATRIX * RB_GetActiveWorldMatrix(void)
{
    return &RB_GetActiveCodeMatrices()->world.matrix[0];
}

/* line 1065 */
void RB_ChangedWorldMatrix(float worldScale)
{
    GfxCodeMatrices *activeMatrices;

    activeMatrices = RB_GetActiveCodeMatrices();
    RB_FinalizeWorldMatrixChange(activeMatrices, worldScale);
}

/* line 1133 */
void RB_SetViewMatrix(const D3DMATRIX *matrix)
{
    GfxCodeMatrices *activeMatrices;

    activeMatrices = RB_GetActiveCodeMatrices();
    RB_SetPrimaryCodeMatrix(&activeMatrices->view, matrix);
    RB_InvalidateCodeMatrix(&activeMatrices->worldView);
    RB_InvalidateCodeMatrix(&activeMatrices->normalizedWorldView);
    RB_InvalidateCodeMatrix(&activeMatrices->viewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->worldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->normalizedWorldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->OGLworldViewProjection);

    if (RB_UsingDx7Renderer()) {
        RB_SetTransformDx7(D3DTS_VIEW, matrix);
    }
}

/* line 1187 */
void RB_SetViewMatrixForWDx7(float w)
{
    D3DMATRIX transform;

    transform = backEnd.viewParms->viewMatrix;
    transform._44 = w;
    RB_SetTransformDx7(D3DTS_VIEW, &transform);
}

/* line 1254 */
void RB_SetDepthHackNearClip(float nearClip)
{
    GfxCodeMatrices *activeMatrices;

    activeMatrices = RB_GetActiveCodeMatrices();
    activeMatrices->projection.matrix[0]._43 = -nearClip;
    RB_ValidatePrimaryCodeMatrix(&activeMatrices->projection);
    RB_InvalidateCodeMatrix(&activeMatrices->viewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->worldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->normalizedWorldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->shadowLookupMatrix);
    RB_InvalidateCodeMatrix(&activeMatrices->OGLworldViewProjection);

    if (RB_UsingDx7Renderer()) {
        RB_SetTransformDx7(D3DTS_PROJECTION, &activeMatrices->projection.matrix[0]);
    }
}

/* line 1264 */
void RB_SetShadowLookupMatrix(const D3DMATRIX *matrix)
{
    backEnd.shadowLookupMatrix = *matrix;
    RB_InvalidateCodeMatrix(&RB_GetActiveCodeMatrices()->shadowLookupMatrix);
}

/* line 1369 */
void RB_SetMatricesForView(const GfxViewParms *viewParms)
{
    GfxCodeMatrices *activeMatrices;

    activeMatrices = RB_GetActiveCodeMatrices();
    RB_SetPrimaryCodeMatrix(&activeMatrices->view, &viewParms->viewMatrix);
    RB_SetPrimaryCodeMatrix(&activeMatrices->projection, &viewParms->projectionMatrix);
    activeMatrices->viewProjection.matrix[0] = viewParms->viewProjectionMatrix;
    activeMatrices->viewProjection.matrix[1] = viewParms->inverseViewProjectionMatrix;
    activeMatrices->viewProjection.valid[0] = 1;
    activeMatrices->viewProjection.valid[1] = 1;
    activeMatrices->viewProjection.valid[2] = 0;
    activeMatrices->viewProjection.valid[3] = 0;
    RB_InvalidateCodeMatrix(&activeMatrices->worldView);
    RB_InvalidateCodeMatrix(&activeMatrices->worldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->normalizedWorldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->OGLworldViewProjection);

    if (RB_UsingDx7Renderer()) {
        RB_SetTransformDx7(D3DTS_VIEW, &viewParms->viewMatrix);
        RB_SetTransformDx7(D3DTS_PROJECTION, &viewParms->projectionMatrix);
    }
}

/* line 1435 */
void RB_PushMatrixStack(void)
{
    backEnd.codeMatrixStack[backEnd.codeMatrixStackLevel + 1] = *RB_GetActiveCodeMatrices();
    backEnd.codeMatrixStackLevel += 1;
}

/* line 1444 */
void RB_PopMatrixStack(void)
{
    GfxCodeMatrices *activeMatrices;

    backEnd.codeMatrixStackLevel -= 1;
    if (!RB_UsingDx7Renderer()) {
        return;
    }

    activeMatrices = RB_GetActiveCodeMatrices();
    RB_SetTransformDx7(0x100, &activeMatrices->world.matrix[0]);
    RB_SetTransformDx7(D3DTS_VIEW, &activeMatrices->view.matrix[0]);
    RB_SetTransformDx7(D3DTS_PROJECTION, &activeMatrices->projection.matrix[0]);
}

/* line 1472 */
void RB_InitSceneViewport(void)
{
    byte *ecx = (byte *)imp_backEnd;
    byte *edx = (byte *)imp_vidConfig;
    *(int *)(ecx + 0x3e8) = *(int *)edx;
    *(int *)(ecx + 0x3ec) = *(int *)(edx + 4);
}

/* line 1480 */
Bool RB_GetViewport(GfxViewport *outViewport)
{
    if (dxState.viewportIsNull) {
        outViewport->x = 0;
        outViewport->y = 0;
        outViewport->width = dxState.renderTargetWidth;
        outViewport->height = dxState.renderTargetHeight;
    } else {
        byte *backEnd = (byte *)imp_backEnd;
        outViewport->x = *(int *)(backEnd + 0x3e0);
        outViewport->y = *(int *)(backEnd + 0x3e4);
        outViewport->width = *(int *)(backEnd + 0x3e8);
        outViewport->height = *(int *)(backEnd + 0x3ec);
    }

    return 1;
}

/* line 1597 */
void RB_SetDepthRange(float nearValue, float farValue)
{
    if (nearValue == dxState.viewport.MinZ && farValue == dxState.viewport.MaxZ) {
        return;
    }

    dxState.viewport.MinZ = nearValue;
    dxState.viewport.MaxZ = farValue;
    RB_SetViewportDx7(&dxState.viewport);
}

/* line 1610 */
void RB_SetViewport(const GfxViewport *viewport)
{
    if ((DWORD)viewport->x == dxState.viewport.X &&
        (DWORD)viewport->y == dxState.viewport.Y &&
        (DWORD)viewport->width == dxState.viewport.Width &&
        (DWORD)viewport->height == dxState.viewport.Height)
    {
        return;
    }

    dxState.viewport.X = viewport->x;
    dxState.viewport.Y = viewport->y;
    dxState.viewport.Width = viewport->width;
    dxState.viewport.Height = viewport->height;
    RB_SetViewportDx7(&dxState.viewport);
}

/* line 1770 */
void RB_ReleaseVertexDecl(void)
{
    void *device;

    if (dxState.vertexDecl == NULL && dxState.fvf == 0) {
        return;
    }

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetVertexDeclarationFn)VTABLE(device)[0x164 / 4])(device, NULL);
    } while (*(volatile int *)imp_alwaysfails != 0);

    dxState.fvf = 0;
    dxState.vertexDecl = NULL;
}

/* line 626 */
void RB_ChangeState_1(int stateBits1)
{
    unsigned int changedBits;
    int decodeIndex;

    changedBits = stateBits1 ^ dxState.activeStateBits[1];
    if (!changedBits) {
        return;
    }

    if (changedBits & RB_STATE1_DEPTH_WRITE) {
        RB_SetRenderStateDx7(D3DRS_ZWRITEENABLE, stateBits1 & RB_STATE1_DEPTH_WRITE);
    }

    if (changedBits & RB_STATE1_DEPTH_TEST_DISABLE) {
        RB_SetRenderStateDx7(D3DRS_ZENABLE, (((unsigned int)stateBits1 >> 1) & 1) ^ 1);
    }

    if (stateBits1 & RB_STATE1_DEPTH_TEST_DISABLE) {
        stateBits1 = (stateBits1 & ~RB_STATE1_DEPTH_FUNC_MASK) | (dxState.activeStateBits[1] & RB_STATE1_DEPTH_FUNC_MASK);
        changedBits &= ~RB_STATE1_DEPTH_FUNC_MASK;
    }

    if (changedBits & RB_STATE1_DEPTH_FUNC_MASK) {
        DWORD depthFunc;

        switch (stateBits1 & RB_STATE1_DEPTH_FUNC_MASK) {
        case 0x4:
            depthFunc = 4;
            break;
        case 0x8:
            depthFunc = 3;
            break;
        default:
            depthFunc = 8;
            break;
        }

        RB_SetRenderStateDx7(D3DRS_ZFUNC, depthFunc);
    }

    if (changedBits & RB_STATE1_POLYGON_OFFSET_MASK) {
        const dvar_t *polygonOffsetBias;
        float offsetUnits;
        float depthBias;

        polygonOffsetBias = *(const dvar_t **)imp_r_polygonOffsetBias;
        offsetUnits = (float)((stateBits1 & RB_STATE1_POLYGON_OFFSET_MASK) >> 4);
        depthBias = offsetUnits * polygonOffsetBias->current.value * 1.52587890625e-05f;
        if (RB_SupportsSlopeScaleDepthBias()) {
            const dvar_t *polygonOffsetScale;

            polygonOffsetScale = *(const dvar_t **)imp_r_polygonOffsetScale;
            RB_SetRenderStateFloatDx7(D3DRS_SLOPESCALEDEPTHBIAS, offsetUnits * polygonOffsetScale->current.value);
        } else {
            depthBias *= 2.0f;
        }

        RB_SetRenderStateFloatDx7(D3DRS_DEPTHBIAS, depthBias);
    }

    if (stateBits1 & RB_STATE1_STENCIL_ENABLE) {
        if (changedBits & RB_STATE1_STENCIL_ENABLE) {
            RB_SetRenderStateDx7(D3DRS_STENCILENABLE, 1);
        }
    } else {
        if (changedBits & RB_STATE1_STENCIL_ENABLE) {
            RB_SetRenderStateDx7(D3DRS_STENCILENABLE, 0);
        }

        stateBits1 = (stateBits1 & RB_STATE1_STENCIL_DISABLED_MASK) | (dxState.activeStateBits[1] & ~RB_STATE1_STENCIL_DISABLED_MASK);
        changedBits &= RB_STATE1_STENCIL_DISABLED_MASK;
    }

    if (stateBits1 & RB_STATE1_STENCIL_TWO_SIDED) {
        if (changedBits & RB_STATE1_STENCIL_TWO_SIDED) {
            RB_SetRenderStateDx7(D3DRS_TWOSIDEDSTENCILMODE, 1);
        }
    } else {
        if (changedBits & RB_STATE1_STENCIL_TWO_SIDED) {
            RB_SetRenderStateDx7(D3DRS_TWOSIDEDSTENCILMODE, 0);
        }

        stateBits1 = (stateBits1 & RB_STATE1_FRONT_STENCIL_MASK) | (dxState.activeStateBits[1] & ~RB_STATE1_FRONT_STENCIL_MASK);
        changedBits &= RB_STATE1_FRONT_STENCIL_MASK;
    }

    if (changedBits & RB_STATE1_STENCIL_OP_MASK) {
        for (decodeIndex = 0; decodeIndex < RB_STENCIL_OP_DECODE_COUNT; ++decodeIndex) {
            const DxStencilDecode *decode;

            decode = &s_stencilOpDecode[decodeIndex];
            if (((changedBits >> decode->shift) & 7) != 0) {
                RB_SetRenderStateDx7(decode->renderState, s_stencilOpTable[((unsigned int)stateBits1 >> decode->shift) & 7]);
            }
        }
    }

    if (changedBits & RB_STATE1_STENCIL_FUNC_MASK) {
        for (decodeIndex = 0; decodeIndex < RB_STENCIL_FUNC_DECODE_COUNT; ++decodeIndex) {
            const DxStencilDecode *decode;

            decode = &s_stencilFuncDecode[decodeIndex];
            if (((changedBits >> decode->shift) & 7) != 0) {
                RB_SetRenderStateDx7(decode->renderState, s_stencilFuncTable[((unsigned int)stateBits1 >> decode->shift) & 7]);
            }
        }
    }

    dxState.activeStateBits[1] = stateBits1;
}

/* line 941 */
void RB_SetSampler(int samplerIndex, int samplerState, GfxImage *image)
{
    byte desiredSamplerState;
    byte currentSamplerState;
    byte diffSamplerState;
    DWORD minFilter;
    DWORD magFilter;
    DWORD prevMinFilter;
    DWORD prevMagFilter;

    desiredSamplerState = (byte)samplerState;
    if (dxState.samplerImage[samplerIndex] != image) {
        RB_SetTextureDx7(samplerIndex, image ? image->texture.basemap : NULL);
        dxState.samplerImage[samplerIndex] = image;
    }

    if (image == NULL) {
        return;
    }

    if ((desiredSamplerState & 0xf) == 0) {
        desiredSamplerState |= (byte)backEnd.defaultSamplerState;
    }

    currentSamplerState = dxState.samplerState[samplerIndex];
    diffSamplerState = desiredSamplerState ^ currentSamplerState;
    if (!diffSamplerState) {
        return;
    }

    if (diffSamplerState & 3) {
        RB_GetSamplerFilterModes(desiredSamplerState, &minFilter, &magFilter);
        RB_GetSamplerFilterModes(currentSamplerState, &prevMinFilter, &prevMagFilter);
        if (minFilter != prevMinFilter) {
            RB_SetSamplerStateDx7(samplerIndex, D3DSAMP_MINFILTER, minFilter);
        }
        if (magFilter != prevMagFilter) {
            RB_SetSamplerStateDx7(samplerIndex, D3DSAMP_MAGFILTER, magFilter);
        }
    }

    if (diffSamplerState & 0xc) {
        RB_SetSamplerStateDx7(samplerIndex, D3DSAMP_MIPFILTER, s_filterTable[desiredSamplerState & 0xc]);
    }

    if (diffSamplerState & 0x10) {
        RB_SetSamplerStateDx7(samplerIndex, D3DSAMP_ADDRESSU, (desiredSamplerState & 0x10) ? D3DTADDRESS_CLAMP : D3DTADDRESS_WRAP);
    }

    if (diffSamplerState & 0x20) {
        RB_SetSamplerStateDx7(samplerIndex, D3DSAMP_ADDRESSV, (desiredSamplerState & 0x20) ? D3DTADDRESS_CLAMP : D3DTADDRESS_WRAP);
    }

    if (diffSamplerState & 0x40) {
        RB_SetSamplerStateDx7(samplerIndex, D3DSAMP_ADDRESSW, (desiredSamplerState & 0x40) ? D3DTADDRESS_CLAMP : D3DTADDRESS_WRAP);
    }

    dxState.samplerState[samplerIndex] = desiredSamplerState;
}

/* line 1777 */
void RB_BindDefaultImages(void)
{
    void *defaultImage = *(void **)((byte *)imp_rgp + 0x1008);

    for (int i = 0; i < 16; i++) {
        RB_SetSampler(i, *((byte *)&dxState + 0x20e4 + i), defaultImage);
    }
}

/* line 1030 */
void RB_UnbindAllImages(void)
{
    if (*(byte *)((byte *)imp_dx + 0x2d3c))
        return;

    int count = *(int *)((byte *)imp_vidConfig + 0x1c);
    for (int i = 0; i < count; i++) {
        RB_SetSampler(i, 0, NULL);
    }
}

/* line 1020 */
void RB_UnbindImage(const GfxImage *image)
{
    int count = *(int *)((byte *)imp_vidConfig + 0x1c);

    for (int i = 0; i < count; i++) {
        if (*(const GfxImage **)((byte *)&dxState + 0x20f4 + i * 4) == image) {
            RB_SetSampler(i, 0, NULL);
        }
    }
}

/* line 1514 */
void RB_UpdateViewportConstants(void)
{
    GfxViewport viewport;
    float invRenderTargetWidth;
    float invRenderTargetHeight;
    float halfViewportWidth;
    float halfViewportHeight;
    float viewportCenterX;
    float viewportCenterY;
    float horizontalScale;
    float verticalScale;
    float xOffset;
    float yOffset;
    int potWidth;
    int potHeight;

    backEnd.projection2D = 0;
    backEnd.viewportIsDirty = 1;

    invRenderTargetWidth = 1.0f / dxState.renderTargetWidth;
    invRenderTargetHeight = 1.0f / dxState.renderTargetHeight;
    if (dxState.viewportBehavior == GFX_USE_VIEWPORT_FULL) {
        viewport.x = 0;
        viewport.y = 0;
        viewport.width = dxState.renderTargetWidth;
        viewport.height = dxState.renderTargetHeight;
    } else {
        viewport = backEnd.sceneViewport;
    }

    halfViewportWidth = 0.5f * viewport.width * invRenderTargetWidth;
    halfViewportHeight = 0.5f * viewport.height * invRenderTargetHeight;
    viewportCenterX = viewport.x * invRenderTargetWidth + halfViewportWidth;
    viewportCenterY = viewport.y * invRenderTargetHeight + halfViewportHeight;

    MacOpenGLUtils_GetSubPixelOffset(&xOffset, &yOffset);
    viewportCenterX += invRenderTargetWidth * xOffset;
    viewportCenterY += invRenderTargetHeight * yOffset;

    potWidth = RB_NextPowerOfTwo(viewport.width);
    potHeight = RB_NextPowerOfTwo(viewport.height);
    horizontalScale = (float)viewport.width / potWidth;
    verticalScale = (float)viewport.height / potHeight;

    RB_SetCodeConstant(0xab, ((float)viewport.width - 0.5f) / potWidth, ((float)viewport.height - 0.5f) / potHeight, invRenderTargetWidth, invRenderTargetHeight);
    RB_SetCodeConstant(0xae, halfViewportWidth * horizontalScale, halfViewportHeight * verticalScale, 0.0f, 1.0f);
    RB_SetCodeConstant(0xaf, viewportCenterX * horizontalScale, viewportCenterY * verticalScale, 0.0f, 0.0f);
}

/* line 1787 */
void RB_InitImages(void)
{
    int samplerIndex;

    for (samplerIndex = 0; samplerIndex < 16; ++samplerIndex) {
        RB_SetSampler(samplerIndex, dxState.samplerState[samplerIndex], *(GfxImage **)((byte *)imp_rgp + 0x1008));
    }
}

/* line 1662 */
void RB_SetRenderTarget(GfxRenderTargetId newTargetId)
{
    DxGlobals *dx;
    const vidConfig_t *vidConfig;
    GfxRenderTarget *renderTarget;
    int samplerIndex;

    if (dxState.renderTargetId == newTargetId) {
        return;
    }

    *(byte *)imp_g_InhibitCopy = (newTargetId == R_RENDERTARGET_SHADOWCOOKIE && dxState.renderTargetId == R_RENDERTARGET_DYNAMICSHADOWS);
    dxState.renderTargetId = newTargetId;

    dx = (DxGlobals *)imp_dx;
    renderTarget = &dx->renderTargets[newTargetId];
    if (renderTarget->image != NULL) {
        vidConfig = (const vidConfig_t *)imp_vidConfig;
        for (samplerIndex = 0; samplerIndex < vidConfig->maxTextureMaps; ++samplerIndex) {
            if (dxState.samplerImage[samplerIndex] == renderTarget->image) {
                RB_SetSampler(samplerIndex, 0, NULL);
            }
        }
    }

    RB_SetRenderTargetSurfaceDx7(renderTarget->colorSurface);
    dxState.renderTargetSurface = renderTarget->colorSurface;

    switch (newTargetId) {
    case R_RENDERTARGET_FRAME_BUFFER:
        glDrawBuffer(0x405);
        glReadBuffer(0x405);
        break;
    case R_RENDERTARGET_DYNAMICSHADOWS:
        glDrawBuffer(0x40A);
        glReadBuffer(0x40A);
        break;
    case R_RENDERTARGET_SHADOWCOOKIE:
    case R_RENDERTARGET_BLURRED_SCREEN:
    case R_RENDERTARGET_GLOW_0:
    case R_RENDERTARGET_PINGPONG_0:
    case R_RENDERTARGET_PINGPONG_1:
        glDrawBuffer(0x409);
        glReadBuffer(0x409);
        break;
    default:
        break;
    }

    *(byte *)imp_g_RenderToShadowCookie = (newTargetId == R_RENDERTARGET_SHADOWCOOKIE);
    dxState.viewportBehavior = s_viewportBehaviorForRenderTarget[newTargetId];
    dxState.renderTargetWidth = renderTarget->width;
    dxState.renderTargetHeight = renderTarget->height;
    dxState.viewport.X = 0;
    dxState.viewport.Y = 0;
    dxState.viewport.Width = renderTarget->width;
    dxState.viewport.Height = renderTarget->height;
    dxState.viewport.MinZ = 0.0f;
    dxState.viewport.MaxZ = 1.0f;

    if (dxState.depthStencilSurface != renderTarget->depthStencilSurface) {
        RB_SetDepthStencilSurfaceDx7(renderTarget->depthStencilSurface);
        dxState.depthStencilSurface = renderTarget->depthStencilSurface;
    }

    RB_UpdateViewportConstants();
}

/* line 1829 */
void RB_ClearAllStreamSources(void)
{
    void *device;

    if (dxState.streams[0].vb == NULL && dxState.streams[0].offset == 0 && dxState.streams[0].stride == 0) {
        return;
    }

    dxState.vertexBufferDeselecting = dxState.streams[0].vb;
    dxState.streams[0].vb = NULL;
    dxState.streams[0].offset = 0;
    dxState.streams[0].stride = 0;

    device = *(void **)((byte *)imp_dx + 8);
    do {
        ((SetStreamSourceFn)VTABLE(device)[0x190 / 4])(device, 0, NULL, 0, 0);
    } while (*(volatile int *)imp_alwaysfails != 0);

    dxState.vertexBufferDeselecting = NULL;
}

/* line 455 */
__attribute__((naked))
void RB_ChangeState_0(int stateBits0)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 455 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* stateBits0 */
        /* { scope 1 */
        "movl dxState+8200, %eax\n" /* line 470 */
        "xorl %edi, %eax\n" /* stateBits0 */
        "movl %eax, -0x24(%ebp)\n" /* changedBits */
        "jne .Lfcf2d0_000cf2fb\n"
        "movl %edi, %eax\n" /* line 472 | stateBits0 */
        "xorl dxState+8192, %eax\n"
        "testl $0x7000700, %eax\n"
        "je .Lfcf2d0_000cf65a\n"
        ".Lfcf2d0_000cf2fb:\n"
        "testl $0x800, -0x24(%ebp)\n" /* line 481 | changedBits */
        "jne .Lfcf2d0_000cf87c\n"
        "movl %edi, %ebx\n" /* stateBits0, disableSeparateAlphaBlend */
        "shrl $0xb, %ebx\n" /* disableSeparateAlphaBlend */
        "andl $1, %ebx\n" /* disableSeparateAlphaBlend */
        ".Lfcf2d0_000cf310:\n"
        "testl %ebx, %ebx\n" /* line 483 | disableSeparateAlphaBlend */
        "jne .Lfcf2d0_000cf784\n"
        "testl $0x3000, -0x24(%ebp)\n" /* line 491 | changedBits */
        "je .Lfcf2d0_000cf3bd\n"
        ".Lfcf2d0_000cf325:\n"
        "movl %edi, %eax\n" /* line 493 | stateBits0 */
        "andl $0x3000, %eax\n"
        "cmpl $__mh_execute_header, %eax\n"
        "je .Lfcf2d0_000cf8ba\n"
        "cmpl $0x2000, %eax\n" /* line 498 */
        "je .Lfcf2d0_000cf8c8\n"
        "movl $7, %esi\n" /* function */
        "movb $0x80, -0x1d(%ebp)\n" /* ref */
        ".Lfcf2d0_000cf34b:\n"
        "movl imp_dx, %ebx\n" /* line 509 | disableSeparateAlphaBlend */
        "movl 8(%ebx), %eax\n" /* disableSeparateAlphaBlend */
        "movl (%eax), %edx\n"
        "movl %esi, 8(%esp)\n" /* function */
        "movl $0x19, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfcf2d0_000cf34b\n"
        "movzbl -0x1d(%ebp), %ecx\n" /* line 510 | ref */
        "cmpb %cl, dxState+8520\n"
        "je .Lfcf2d0_000cf3bd\n"
        "movzbl %cl, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %ebx, %esi\n" /* disableSeparateAlphaBlend, function */
        "movl %eax, %ebx\n" /* disableSeparateAlphaBlend */
        "movl %edx, %ecx\n"
        "jmp .Lfcf2d0_000cf393\n"
        ".Lfcf2d0_000cf390:\n"
        "movl -0x1c(%ebp), %ecx\n"
        ".Lfcf2d0_000cf393:\n"
        "movl 8(%esi), %eax\n" /* line 512 | function */
        "movl (%eax), %edx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%ebx), %eax\n" /* disableSeparateAlphaBlend */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf390\n"
        "movzbl -0x1d(%ebp), %eax\n" /* line 513 | ref */
        "movb %al, dxState+8520\n"
        ".Lfcf2d0_000cf3bd:\n"
        "testl $0x18000000, -0x24(%ebp)\n" /* line 517 | changedBits */
        "jne .Lfcf2d0_000cf662\n"
        "testl $0x20000000, -0x24(%ebp)\n" /* line 525 | changedBits */
        "jne .Lfcf2d0_000cf6bf\n"
        ".Lfcf2d0_000cf3d7:\n"
        "testw $0xc000, -0x24(%ebp)\n" /* line 529 | changedBits */
        "jne .Lfcf2d0_000cf6ff\n"
        ".Lfcf2d0_000cf3e3:\n"
        "movl -0x24(%ebp), %eax\n" /* line 535 | changedBits */
        "testl %eax, %eax\n"
        "js .Lfcf2d0_000cf747\n"
        ".Lfcf2d0_000cf3ee:\n"
        "testl $0x700, %edi\n" /* line 538 | stateBits0 */
        "sete %bl\n" /* disableSeparateAlphaBlend */
        "testl $0x700, dxState+8192\n" /* line 540 */
        "sete %al\n"
        "cmpb %al, %bl\n" /* disableSeparateAlphaBlend */
        "je .Lfcf2d0_000cf43c\n"
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf40e:\n"
        "movl imp_dx, %ecx\n" /* line 541 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl %ebx, %edx\n" /* disableSeparateAlphaBlend */
        "xorb $1, %dl\n"
        "movzbl %dl, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x1b, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%esi), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf40e\n"
        ".Lfcf2d0_000cf43c:\n"
        "testb %bl, %bl\n" /* line 543 | disableSeparateAlphaBlend */
        "je .Lfcf2d0_000cf7a9\n"
        "andl $0xfffff800, %edi\n" /* line 545 | stateBits0 */
        "movl dxState+8200, %eax\n" /* line 546 */
        "andl $0x7ff, %eax\n"
        "orl %eax, %edi\n" /* stateBits0 */
        "andl $0xfffff800, -0x24(%ebp)\n" /* line 547 | changedBits */
        ".Lfcf2d0_000cf45d:\n"
        "cmpb $0, -0x24(%ebp)\n" /* line 555 | changedBits */
        "je .Lfcf2d0_000cf4e2\n"
        "testb $0xf, -0x24(%ebp)\n" /* line 557 | changedBits */
        "je .Lfcf2d0_000cf4a1\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "andl $0xf, %eax\n"
        "movl s_blendTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf47b:\n"
        "movl imp_dx, %ecx\n" /* line 561 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0x13, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf47b\n"
        ".Lfcf2d0_000cf4a1:\n"
        "testb $0xf0, -0x24(%ebp)\n" /* line 564 | changedBits */
        "je .Lfcf2d0_000cf4e2\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "sarl $4, %eax\n"
        "andl $0xf, %eax\n"
        "movl s_blendTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf4bc:\n"
        "movl imp_dx, %edx\n" /* line 568 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0x14, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %ecx\n" /* function */
        "testl %ecx, %ecx\n"
        "jne .Lfcf2d0_000cf4bc\n"
        ".Lfcf2d0_000cf4e2:\n"
        "testl $0x7000000, %edi\n" /* line 572 | stateBits0 */
        "sete %bl\n" /* disableSeparateAlphaBlend */
        "testl $0x7000000, dxState+8192\n" /* line 574 */
        "sete %al\n"
        "cmpb %al, %bl\n" /* disableSeparateAlphaBlend */
        "je .Lfcf2d0_000cf530\n"
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf502:\n"
        "movl imp_dx, %ecx\n" /* line 575 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl %ebx, %edx\n" /* disableSeparateAlphaBlend */
        "xorb $1, %dl\n"
        "movzbl %dl, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0xce, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%esi), %edx\n" /* function */
        "testl %edx, %edx\n"
        "jne .Lfcf2d0_000cf502\n"
        ".Lfcf2d0_000cf530:\n"
        "testb %bl, %bl\n" /* line 577 | disableSeparateAlphaBlend */
        "je .Lfcf2d0_000cf7f6\n"
        "andl $0xf800ffff, %edi\n" /* line 579 | stateBits0 */
        "movl dxState+8200, %eax\n" /* line 580 */
        "andl $0x7ff0000, %eax\n"
        "orl %eax, %edi\n" /* stateBits0 */
        "andl $0xf800ffff, -0x24(%ebp)\n" /* line 581 | changedBits */
        ".Lfcf2d0_000cf551:\n"
        "testl $0x00FF0000, -0x24(%ebp)\n" /* line 589 | changedBits */
        "je .Lfcf2d0_000cf5e6\n"
        "testl $0xf0000, -0x24(%ebp)\n" /* line 591 | changedBits */
        "je .Lfcf2d0_000cf5a2\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "sarl $0x10, %eax\n"
        "andl $0xf, %eax\n"
        "movl s_blendTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf57c:\n"
        "movl imp_dx, %ecx\n" /* line 595 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0xcf, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf57c\n"
        ".Lfcf2d0_000cf5a2:\n"
        "testl $0x00F00000, -0x24(%ebp)\n" /* line 598 | changedBits */
        "je .Lfcf2d0_000cf5e6\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "sarl $0x14, %eax\n"
        "andl $0xf, %eax\n"
        "movl s_blendTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf5c0:\n"
        "movl imp_dx, %edx\n" /* line 602 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0xd0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf5c0\n"
        ".Lfcf2d0_000cf5e6:\n"
        "testl $0x40000000, -0x24(%ebp)\n" /* line 607 | changedBits */
        "jne .Lfcf2d0_000cf843\n"
        ".Lfcf2d0_000cf5f3:\n"
        "movl imp_dx, %edx\n" /* line 615 */
        "cmpb $0, 0x2d7e(%edx)\n"
        "je .Lfcf2d0_000cf654\n"
        "movl imp_r_aaAlpha, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfcf2d0_000cf654\n"
        "testl $0xf00, -0x24(%ebp)\n" /* line 617 | changedBits */
        "je .Lfcf2d0_000cf654\n"
        /* { scope 2 */
        "testl $0xf00, %edi\n" /* line 444 */
        "je .Lfcf2d0_000cf8d6\n"
        "xorl %ebx, %ebx\n" /* aaAlphaFormat */
        "jmp .Lfcf2d0_000cf62f\n"
        ".Lfcf2d0_000cf629:\n"
        "movl imp_dx, %edx\n"
        ".Lfcf2d0_000cf62f:\n"
        "movl 8(%edx), %eax\n" /* line 450 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* aaAlphaFormat */
        "movl $0xb5, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf629\n"
        /* } scope */
        ".Lfcf2d0_000cf654:\n"
        "movl %edi, dxState+8200\n" /* line 622 | stateBits0 */
        /* } scope */
        ".Lfcf2d0_000cf65a:\n"
        "addl $0x2c, %esp\n" /* line 623 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcf2d0_000cf662:\n"
        "movl %edi, %eax\n" /* line 519 | stateBits0 */
        "andl $0x8000000, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %ebx, %ebx\n" /* disableSeparateAlphaBlend */
        "notl %ebx\n" /* disableSeparateAlphaBlend */
        "andl $7, %ebx\n" /* disableSeparateAlphaBlend */
        "movl %edi, %eax\n" /* line 520 | stateBits0 */
        "andl $0x10000000, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $8, %eax\n"
        "orl %eax, %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf68c:\n"
        "movl imp_dx, %edx\n" /* line 521 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0xa8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %ecx\n" /* function */
        "testl %ecx, %ecx\n"
        "jne .Lfcf2d0_000cf68c\n"
        "testl $0x20000000, -0x24(%ebp)\n" /* line 525 | changedBits */
        "je .Lfcf2d0_000cf3d7\n"
        ".Lfcf2d0_000cf6bf:\n"
        "movl %edi, %ebx\n" /* stateBits0, disableSeparateAlphaBlend */
        "shrl $0x1d, %ebx\n" /* disableSeparateAlphaBlend */
        "andl $1, %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf6cd:\n"
        "movl imp_dx, %ecx\n" /* line 526 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0x1c, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %edx\n" /* function */
        "testl %edx, %edx\n"
        "jne .Lfcf2d0_000cf6cd\n"
        "testw $0xc000, -0x24(%ebp)\n" /* line 529 | changedBits */
        "je .Lfcf2d0_000cf3e3\n"
        ".Lfcf2d0_000cf6ff:\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "andl $0xc000, %eax\n"
        "sarl $0xe, %eax\n"
        "movl s_cullTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf716:\n"
        "movl imp_dx, %edx\n" /* line 532 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0x16, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf716\n"
        "movl -0x24(%ebp), %eax\n" /* line 535 | changedBits */
        "testl %eax, %eax\n"
        "jns .Lfcf2d0_000cf3ee\n"
        ".Lfcf2d0_000cf747:\n"
        "testl %edi, %edi\n" /* line 622 | stateBits0 */
        "js .Lfcf2d0_000cf8eb\n"
        "movl imp_dx, %esi\n" /* function */
        "movl imp_alwaysfails, %ebx\n" /* disableSeparateAlphaBlend */
        ".Lfcf2d0_000cf75b:\n"
        "movl 8(%esi), %eax\n" /* line 536 | function */
        "movl (%eax), %edx\n"
        "movl $3, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%ebx), %eax\n" /* disableSeparateAlphaBlend */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf75b\n"
        "jmp .Lfcf2d0_000cf3ee\n"
        ".Lfcf2d0_000cf784:\n"
        "movl dxState+8200, %eax\n" /* line 486 */
        "andl $0x3000, %eax\n"
        "orl %eax, %edi\n" /* stateBits0 */
        "andl $0xffffcfff, -0x24(%ebp)\n" /* line 487 | changedBits */
        "testl $0x3000, -0x24(%ebp)\n" /* line 491 | changedBits */
        "je .Lfcf2d0_000cf3bd\n"
        "jmp .Lfcf2d0_000cf325\n"
        ".Lfcf2d0_000cf7a9:\n"
        "testl $0x700, -0x24(%ebp)\n" /* line 550 | changedBits */
        "je .Lfcf2d0_000cf45d\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "sarl $8, %eax\n"
        "andl $7, %eax\n"
        "movl s_blendOpTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf7cb:\n"
        "movl imp_dx, %edx\n" /* line 552 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0xab, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf7cb\n"
        "jmp .Lfcf2d0_000cf45d\n"
        ".Lfcf2d0_000cf7f6:\n"
        "testl $0x7000000, -0x24(%ebp)\n" /* line 584 | changedBits */
        "je .Lfcf2d0_000cf551\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "sarl $0x18, %eax\n"
        "andl $7, %eax\n"
        "movl s_blendOpTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf818:\n"
        "movl imp_dx, %edx\n" /* line 586 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0xd1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf818\n"
        "jmp .Lfcf2d0_000cf551\n"
        ".Lfcf2d0_000cf843:\n"
        "movl %edi, %ebx\n" /* line 607 | stateBits0, disableSeparateAlphaBlend */
        "shrl $0x1e, %ebx\n" /* disableSeparateAlphaBlend */
        "andl $1, %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf851:\n"
        "movl imp_dx, %ecx\n" /* line 610 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* disableSeparateAlphaBlend */
        "movl $0x8f, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf851\n"
        "jmp .Lfcf2d0_000cf5f3\n"
        ".Lfcf2d0_000cf87c:\n"
        "movl %edi, %ebx\n" /* line 481 | stateBits0, disableSeparateAlphaBlend */
        "shrl $0xb, %ebx\n" /* disableSeparateAlphaBlend */
        "andl $1, %ebx\n" /* disableSeparateAlphaBlend */
        "movl imp_alwaysfails, %esi\n" /* function */
        ".Lfcf2d0_000cf88a:\n"
        "movl imp_dx, %edx\n" /* line 482 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl %ebx, %edx\n" /* disableSeparateAlphaBlend */
        "xorl $1, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0xf, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%esi), %ecx\n" /* function */
        "testl %ecx, %ecx\n"
        "jne .Lfcf2d0_000cf88a\n"
        "jmp .Lfcf2d0_000cf310\n"
        ".Lfcf2d0_000cf8ba:\n"
        "movl $5, %esi\n" /* line 493 | function */
        "movb $0, -0x1d(%ebp)\n" /* ref */
        "jmp .Lfcf2d0_000cf34b\n"
        ".Lfcf2d0_000cf8c8:\n"
        "movl $2, %esi\n" /* line 498 | function */
        "movb $0x80, -0x1d(%ebp)\n" /* ref */
        "jmp .Lfcf2d0_000cf34b\n"
        /* { scope 2 */
        ".Lfcf2d0_000cf8d6:\n"
        "movl $0x41415353, %ebx\n" /* line 446 | aaAlphaFormat */
        "cmpl $2, %eax\n"
        "movl $0x434f5441, %eax\n"
        "cmovnel %eax, %ebx\n" /* aaAlphaFormat */
        "jmp .Lfcf2d0_000cf62f\n"
        /* } scope */
        ".Lfcf2d0_000cf8eb:\n"
        "movl imp_dx, %eax\n" /* line 536 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl $2, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf8eb\n"
        "jmp .Lfcf2d0_000cf3ee\n"
    );
}

/* line 1242 */
void RB_SetProjectionMatrix(const D3DMATRIX *matrix)
{
    GfxCodeMatrices *activeMatrices;

    activeMatrices = RB_GetActiveCodeMatrices();
    RB_SetPrimaryCodeMatrix(&activeMatrices->projection, matrix);
    RB_InvalidateCodeMatrix(&activeMatrices->viewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->worldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->normalizedWorldViewProjection);
    RB_InvalidateCodeMatrix(&activeMatrices->shadowLookupMatrix);
    RB_InvalidateCodeMatrix(&activeMatrices->OGLworldViewProjection);

    if (RB_UsingDx7Renderer()) {
        RB_SetTransformDx7(D3DTS_PROJECTION, &activeMatrices->projection.matrix[0]);
    }
}

/* line 1630 */
void RB_UpdateViewport(void)
{
    GfxViewport viewport;

    backEnd.viewportIsDirty = 0;
    if (dxState.viewportBehavior == GFX_USE_VIEWPORT_FULL) {
        viewport.x = 0;
        viewport.y = 0;
        viewport.width = dxState.renderTargetWidth;
        viewport.height = dxState.renderTargetHeight;
    } else {
        viewport = backEnd.sceneViewport;
    }

    dxState.viewportIsNull = 0;
    RB_SetViewport(&viewport);
}

/* line 345 */
void RB_SetInitialState(void)
{
    const vidConfig_t *vidConfig;
    D3DMATERIAL9 material;
    int stageIndex;

    memset(&dxState, 0, sizeof(dxState));
    RB_DecideDefaultSamplerState();
    RB_SetAnisotropy();

    vidConfig = (const vidConfig_t *)imp_vidConfig;
    dxState.refStateBits[0] = 0x18128812;
    dxState.refStateBits[1] = 0xe00e0007;
    dxState.activeStateBits[0] = 0x19128912;
    dxState.activeStateBits[1] = 0xe00e0007;
    dxState.stencilRefValue = 0;

    backEnd.sceneViewport.x = 0;
    backEnd.sceneViewport.y = 0;
    backEnd.sceneViewport.width = vidConfig->width;
    backEnd.sceneViewport.height = vidConfig->height;

    dxState.viewport.X = 0;
    dxState.viewport.Y = 0;
    dxState.viewport.Width = vidConfig->width;
    dxState.viewport.Height = vidConfig->height;
    dxState.viewport.MinZ = 0.0f;
    dxState.viewport.MaxZ = 1.0f;

    dxState.renderTargetId = R_RENDERTARGET_NONE;
    RB_SetRenderTarget(R_RENDERTARGET_FRAME_BUFFER);
    dxState.viewportIsNull = 0;

    dxState.fog.end = 1.0f;
    dxState.fog.density = 1.0f;

    for (stageIndex = 0; stageIndex < 8; ++stageIndex) {
        dxState.refColorStageBits[stageIndex] = 0;
        dxState.refAlphaStageBits[stageIndex] = 0;
        dxState.activeColorStageBits[stageIndex] = 0;
        dxState.activeAlphaStageBits[stageIndex] = 0;
    }

    RB_SetRenderStateDx7(0x89, 0);
    RB_SetRenderStateDx7(0x93, 1);

    material.Diffuse.r = 1.0f;
    material.Diffuse.g = 1.0f;
    material.Diffuse.b = 1.0f;
    material.Diffuse.a = 1.0f;
    material.Ambient = material.Diffuse;
    material.Specular = material.Diffuse;
    material.Emissive.r = 0.0f;
    material.Emissive.g = 0.0f;
    material.Emissive.b = 0.0f;
    material.Emissive.a = 0.0f;
    material.Power = 32.0f;
    RB_SetMaterialDx7(&material);

    dxState.gridLighting = 0;
    dxState.genTexCoords[0] = 0;
    dxState.genTexCoords[1] = 0;

    for (stageIndex = 0; stageIndex < 16; ++stageIndex) {
        dxState.samplerImage[stageIndex] = NULL;
        dxState.samplerState[stageIndex] = 1;
    }

    dxState.textureColorArg = 1;
    dxState.textureFactor = 0xFFFFFFFF;
    memset(dxState.vertexShaderConsts, 0xFF, sizeof(dxState.vertexShaderConsts));
    memset(dxState.pixelShaderConsts, 0xFF, sizeof(dxState.pixelShaderConsts));
}

/* line 1044 */
void RB_SetWorldMatrixForEntity(const GfxEntity *re)
{
    GfxCodeMatrices *activeMatrices;

    activeMatrices = RB_GetActiveCodeMatrices();
    MatrixSet44(activeMatrices->world.matrix[0].m, re->origin, re->axis, re->scale);
    RB_FinalizeWorldMatrixChange(activeMatrices, re->scale);
}
