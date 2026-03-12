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
static __attribute__((naked, regparm(3)))
void RB_ChangeTextureStageState(int stageIndex, const DxTextureStageEnums *texStageEnums, int texStageBits, int *activeTexStageBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 781 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %edi\n" /* stageIndex */
        "movl %edx, %ebx\n" /* texStageEnums */
        "movl %ecx, -0x34(%ebp)\n"
        /* { scope 1 */
        "leal (, %eax, 4), %eax\n" /* line 790 */
        "movl 8(%ebp), %edx\n" /* activeTexStageBits */
        "addl %edx, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "xorl (%eax), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n" /* changedBits */
        "movl -0x34(%ebp), %eax\n" /* line 793 */
        "andl $0x1f, %eax\n"
        "leal s_textureOpTable(, %eax, 8), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* texOp */
        "andb $0x1f, %cl\n" /* line 794 */
        "jne .Lfcd2ec_000cd3df\n"
        ".Lfcd2ec_000cd329:\n"
        "movl %ebx, %esi\n" /* line 795 | texArg */
        "movl $0xa, -0x20(%ebp)\n" /* argShift */
        "movl $0x7c00, -0x1c(%ebp)\n" /* argMask */
        "movl $0, -0x24(%ebp)\n" /* argIndex */
        ".Lfcd2ec_000cd340:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 804 | argMask */
        "testl %edx, -0x2c(%ebp)\n" /* changedBits */
        "je .Lfcd2ec_000cd3b6\n"
        "movl -0x28(%ebp), %ecx\n" /* line 806 | texOp */
        "movl 4(%ecx), %eax\n"
        "movzbl -0x24(%ebp), %ecx\n" /* argIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lfcd2ec_000cd416\n"
        "movl -0x34(%ebp), %edx\n" /* line 808 */
        "movzbl -0x20(%ebp), %ecx\n" /* argShift */
        "sarl %cl, %edx\n"
        "movl %edx, %eax\n" /* line 765 */
        "andl $7, %eax\n"
        "movl s_textureArgTable(, %eax, 4), %ebx\n"
        "movl %ebx, %eax\n" /* line 767 */
        "orl $0x10, %eax\n"
        "testb $8, %dl\n"
        "cmovnel %eax, %ebx\n"
        "movl %ebx, %eax\n" /* line 769 */
        "orl $0x20, %eax\n"
        "andb $0x10, %dl\n"
        "cmovnel %eax, %ebx\n"
        ".Lfcd2ec_000cd387:\n"
        "movl imp_dx, %edx\n" /* line 809 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl %ebx, 0xc(%esp)\n" /* texArg */
        "movl 4(%esi), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* stageIndex */
        "movl %eax, (%esp)\n"
        "calll *0x10c(%ecx)\n"
        "movl imp_alwaysfails, %ecx\n"
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd2ec_000cd387\n"
        ".Lfcd2ec_000cd3b6:\n"
        "addl $1, -0x24(%ebp)\n" /* line 802 | argIndex */
        "addl $5, -0x20(%ebp)\n" /* argShift */
        "shll $5, -0x1c(%ebp)\n" /* argMask */
        "addl $4, %esi\n"
        "cmpl $3, -0x24(%ebp)\n" /* argIndex */
        "jne .Lfcd2ec_000cd340\n"
        ".Lfcd2ec_000cd3cf:\n"
        "movl -0x34(%ebp), %esi\n" /* line 819 */
        "movl -0x30(%ebp), %ecx\n"
        "movl %esi, (%ecx)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 820 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcd2ec_000cd3df:\n"
        "movl imp_dx, %ecx\n" /* line 795 */
        "movl 8(%ecx), %edx\n"
        "movl (%edx), %ecx\n"
        "movl -0x28(%ebp), %esi\n" /* texOp */
        "movl (%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%ebx), %eax\n" /* texArg */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* stageIndex */
        "movl %edx, (%esp)\n"
        "calll *0x10c(%ecx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd2ec_000cd3df\n"
        "jmp .Lfcd2ec_000cd329\n"
        ".Lfcd2ec_000cd416:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 813 | argMask */
        "notl %eax\n"
        "andl %eax, -0x34(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 814 | argMask */
        "movl -0x30(%ebp), %edx\n"
        "andl (%edx), %eax\n"
        "orl %eax, -0x34(%ebp)\n"
        "addl $1, -0x24(%ebp)\n" /* line 802 | argIndex */
        "addl $5, -0x20(%ebp)\n" /* argShift */
        "shll $5, -0x1c(%ebp)\n" /* argMask */
        "addl $4, %esi\n"
        "cmpl $3, -0x24(%ebp)\n" /* argIndex */
        "jne .Lfcd2ec_000cd340\n"
        "jmp .Lfcd2ec_000cd3cf\n"
    );
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
__attribute__((naked))
void RB_ChangeState_1(int stateBits1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 626 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 640 | stateBits1 */
        "xorl dxState+8204, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* changedBits */
        "je .Lfce4d2_000ce710\n"
        "testb $1, %al\n" /* line 650 */
        "jne .Lfce4d2_000ce756\n"
        "testb $2, -0x2c(%ebp)\n" /* line 653 | changedBits */
        "jne .Lfce4d2_000ce718\n"
        ".Lfce4d2_000ce4ff:\n"
        "movl 8(%ebp), %ebx\n" /* stateBits1, function */
        "shrl $1, %ebx\n" /* function */
        "andl $1, %ebx\n" /* function */
        ".Lfce4d2_000ce507:\n"
        "testl %ebx, %ebx\n" /* line 655 | function */
        "je .Lfce4d2_000ce51a\n"
        "movl dxState+8204, %eax\n" /* line 658 */
        "andl $0xc, %eax\n"
        "orl %eax, 8(%ebp)\n" /* stateBits1 */
        "andl $0xfffffff3, -0x2c(%ebp)\n" /* line 659 | changedBits */
        ".Lfce4d2_000ce51a:\n"
        "testb $0xc, -0x2c(%ebp)\n" /* line 663 | changedBits */
        "je .Lfce4d2_000ce565\n"
        "movl 8(%ebp), %eax\n" /* line 665 | stateBits1 */
        "andl $0xc, %eax\n"
        "cmpl $4, %eax\n"
        "je .Lfce4d2_000ce8ac\n"
        "xorl %ebx, %ebx\n" /* line 669 | function */
        "cmpl $8, %eax\n"
        "setne %bl\n" /* function */
        "leal 3(%ebx, %ebx, 4), %ebx\n" /* function */
        ".Lfce4d2_000ce53b:\n"
        "movl imp_dx, %eax\n" /* line 678 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* function */
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce4d2_000ce53b\n"
        ".Lfce4d2_000ce565:\n"
        "testb $0x30, -0x2c(%ebp)\n" /* line 681 | changedBits */
        "je .Lfce4d2_000ce625\n"
        "movl 8(%ebp), %eax\n" /* line 683 | stateBits1 */
        "andl $0x30, %eax\n"
        "sarl $4, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movl imp_r_polygonOffsetBias, %eax\n"
        "movl (%eax), %eax\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "mulss lit4_002ed854, %xmm0\n" /* 1.52587890625e-05f */
        "movss %xmm0, -0x20(%ebp)\n" /* bias */
        "movl imp_dx, %edx\n" /* line 684 */
        "cmpb $0, 0x2d7a(%edx)\n"
        "je .Lfce4d2_000ce7cd\n"
        "movl imp_r_polygonOffsetScale, %eax\n" /* line 686 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n" /* scale */
        "leal -0x1c(%ebp), %edi\n" /* scale */
        "movl imp_alwaysfails, %esi\n"
        "movl %edx, %ebx\n" /* function */
        "jmp .Lfce4d2_000ce5cb\n"
        ".Lfce4d2_000ce5c9:\n"
        "movl %ebx, %edx\n" /* line 687 | function */
        ".Lfce4d2_000ce5cb:\n"
        "movl 8(%edx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl (%edi), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0xaf, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce4d2_000ce5c9\n"
        "movl imp_dx, %edx\n"
        ".Lfce4d2_000ce5f3:\n"
        "leal -0x20(%ebp), %ebx\n" /* line 691 | bias, function */
        "jmp .Lfce4d2_000ce5fe\n"
        ".Lfce4d2_000ce5f8:\n"
        "movl imp_dx, %edx\n"
        ".Lfce4d2_000ce5fe:\n"
        "movl 8(%edx), %edx\n" /* line 693 */
        "movl (%edx), %ecx\n"
        "movl (%ebx), %eax\n" /* function */
        "movl %eax, 8(%esp)\n"
        "movl $0xc3, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce4d2_000ce5f8\n"
        ".Lfce4d2_000ce625:\n"
        "testb $0x40, 8(%ebp)\n" /* line 696 | stateBits1 */
        "je .Lfce4d2_000ce7b3\n"
        "testb $0x40, -0x2c(%ebp)\n" /* line 698 | changedBits */
        "jne .Lfce4d2_000ce877\n"
        ".Lfce4d2_000ce639:\n"
        "cmpb $0, 8(%ebp)\n" /* line 709 | stateBits1 */
        "jns .Lfce4d2_000ce794\n"
        "cmpb $0, -0x2c(%ebp)\n" /* line 712 | changedBits */
        "js .Lfce4d2_000ce842\n"
        ".Lfce4d2_000ce64d:\n"
        "testl $0x1ff1ff00, -0x2c(%ebp)\n" /* line 730 | changedBits */
        "je .Lfce4d2_000ce6aa\n"
        "movl $s_stencilOpDecode, %edi\n"
        ".Lfce4d2_000ce65b:\n"
        "movl (%edi), %ecx\n" /* line 734 */
        "movl -0x2c(%ebp), %eax\n" /* line 735 | changedBits */
        "sarl %cl, %eax\n"
        "testb $7, %al\n"
        "je .Lfce4d2_000ce69f\n"
        "movl 8(%ebp), %eax\n" /* line 737 | stateBits1 */
        "sarl %cl, %eax\n"
        "andl $7, %eax\n"
        "movl s_stencilOpTable(, %eax, 4), %esi\n"
        "movl 4(%edi), %ebx\n" /* function */
        ".Lfce4d2_000ce678:\n"
        "movl imp_dx, %edx\n" /* line 738 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* function */
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfce4d2_000ce678\n"
        ".Lfce4d2_000ce69f:\n"
        "addl $8, %edi\n"
        "cmpl $s_stencilOpDecode+48, %edi\n" /* line 732 */
        "jne .Lfce4d2_000ce65b\n"
        ".Lfce4d2_000ce6aa:\n"
        "testl $0xe00e0000, -0x2c(%ebp)\n" /* line 743 | changedBits */
        "je .Lfce4d2_000ce708\n"
        "movl $s_stencilFuncDecode, %edi\n"
        ".Lfce4d2_000ce6b8:\n"
        "movl (%edi), %ecx\n" /* line 747 */
        "movl -0x2c(%ebp), %eax\n" /* line 748 | changedBits */
        "sarl %cl, %eax\n"
        "testb $7, %al\n"
        "je .Lfce4d2_000ce6fc\n"
        "movl 8(%ebp), %eax\n" /* line 750 | stateBits1 */
        "sarl %cl, %eax\n"
        "andl $7, %eax\n"
        "movl s_stencilFuncTable(, %eax, 4), %esi\n"
        "movl 4(%edi), %ebx\n" /* function */
        ".Lfce4d2_000ce6d5:\n"
        "movl imp_dx, %edx\n" /* line 751 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* function */
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce4d2_000ce6d5\n"
        ".Lfce4d2_000ce6fc:\n"
        "addl $8, %edi\n"
        "movl $s_stencilFuncDecode+16, %edx\n" /* line 745 */
        "cmpl %edi, %edx\n"
        "jne .Lfce4d2_000ce6b8\n"
        ".Lfce4d2_000ce708:\n"
        "movl 8(%ebp), %eax\n" /* line 756 | stateBits1 */
        "movl %eax, dxState+8204\n"
        /* } scope */
        ".Lfce4d2_000ce710:\n"
        "addl $0x3c, %esp\n" /* line 757 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfce4d2_000ce718:\n"
        "movl 8(%ebp), %ebx\n" /* line 653 | stateBits1, function */
        "shrl $1, %ebx\n" /* function */
        "andl $1, %ebx\n" /* function */
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lfce4d2_000ce72c:\n"
        "movl 8(%edi), %eax\n" /* line 654 */
        "movl (%eax), %ecx\n"
        "movl %ebx, %edx\n" /* function */
        "xorl $1, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $7, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce4d2_000ce72c\n"
        "jmp .Lfce4d2_000ce507\n"
        ".Lfce4d2_000ce756:\n"
        "movl 8(%ebp), %ebx\n" /* line 650 | stateBits1, function */
        "andl $1, %ebx\n" /* function */
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lfce4d2_000ce768:\n"
        "movl 8(%edi), %eax\n" /* line 651 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* function */
        "movl $0xe, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfce4d2_000ce768\n"
        "testb $2, -0x2c(%ebp)\n" /* line 653 | changedBits */
        "je .Lfce4d2_000ce4ff\n"
        "jmp .Lfce4d2_000ce718\n"
        ".Lfce4d2_000ce794:\n"
        "cmpb $0, -0x2c(%ebp)\n" /* line 717 | changedBits */
        "js .Lfce4d2_000ce80d\n"
        ".Lfce4d2_000ce79a:\n"
        "movl dxState+8204, %eax\n" /* line 719 */
        "andl $0xfff00000, %eax\n"
        "orl %eax, 8(%ebp)\n" /* stateBits1 */
        "andl $0xfffff, -0x2c(%ebp)\n" /* line 720 | changedBits */
        "jmp .Lfce4d2_000ce64d\n"
        ".Lfce4d2_000ce7b3:\n"
        "testb $0x40, -0x2c(%ebp)\n" /* line 703 | changedBits */
        "jne .Lfce4d2_000ce7db\n"
        ".Lfce4d2_000ce7b9:\n"
        "movl dxState+8204, %eax\n" /* line 705 */
        "andl $0xffffff80, %eax\n"
        "orl %eax, 8(%ebp)\n" /* stateBits1 */
        "andl $0x7f, -0x2c(%ebp)\n" /* line 706 | changedBits */
        "jmp .Lfce4d2_000ce639\n"
        ".Lfce4d2_000ce7cd:\n"
        "addss %xmm0, %xmm0\n" /* line 691 */
        "movss %xmm0, -0x20(%ebp)\n" /* bias */
        "jmp .Lfce4d2_000ce5f3\n"
        ".Lfce4d2_000ce7db:\n"
        "movl imp_dx, %esi\n"
        "movl imp_alwaysfails, %ebx\n" /* function */
        ".Lfce4d2_000ce7e7:\n"
        "movl 8(%esi), %eax\n" /* line 704 */
        "movl (%eax), %edx\n"
        "movl $0, 8(%esp)\n"
        "movl $0x34, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%ebx), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfce4d2_000ce7e7\n"
        "jmp .Lfce4d2_000ce7b9\n"
        ".Lfce4d2_000ce80d:\n"
        "movl imp_dx, %esi\n"
        "movl imp_alwaysfails, %ebx\n" /* function */
        ".Lfce4d2_000ce819:\n"
        "movl 8(%esi), %eax\n" /* line 718 */
        "movl (%eax), %edx\n"
        "movl $0, 8(%esp)\n"
        "movl $0xb9, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%ebx), %ecx\n" /* function */
        "testl %ecx, %ecx\n"
        "jne .Lfce4d2_000ce819\n"
        "jmp .Lfce4d2_000ce79a\n"
        ".Lfce4d2_000ce842:\n"
        "movl imp_dx, %esi\n"
        "movl imp_alwaysfails, %ebx\n" /* function */
        ".Lfce4d2_000ce84e:\n"
        "movl 8(%esi), %eax\n" /* line 713 */
        "movl (%eax), %edx\n"
        "movl $1, 8(%esp)\n"
        "movl $0xb9, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%ebx), %edi\n" /* function */
        "testl %edi, %edi\n"
        "jne .Lfce4d2_000ce84e\n"
        "jmp .Lfce4d2_000ce64d\n"
        ".Lfce4d2_000ce877:\n"
        "movl imp_dx, %esi\n"
        "movl imp_alwaysfails, %ebx\n" /* function */
        ".Lfce4d2_000ce883:\n"
        "movl 8(%esi), %eax\n" /* line 699 */
        "movl (%eax), %edx\n"
        "movl $1, 8(%esp)\n"
        "movl $0x34, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%ebx), %eax\n" /* function */
        "testl %eax, %eax\n"
        "jne .Lfce4d2_000ce883\n"
        "jmp .Lfce4d2_000ce639\n"
        ".Lfce4d2_000ce8ac:\n"
        "movl $4, %ebx\n" /* line 665 | function */
        "jmp .Lfce4d2_000ce53b\n"
    );
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
__attribute__((naked))
void RB_UpdateViewportConstants(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1514 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x90, %esp\n"
        /* { scope 1 */
        "movl imp_backEnd, %eax\n" /* line 1524 */
        "movb $0, 0x4bd(%eax)\n"
        "movb $1, 0x4bc(%eax)\n" /* line 1525 */
        "movl dxState+8348, %ebx\n" /* line 1529 */
        "cvtsi2ssl %ebx, %xmm2\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm6\n"
        "divss %xmm2, %xmm6\n"
        "movl dxState+8352, %esi\n" /* line 1530 */
        "cvtsi2ssl %esi, %xmm1\n"
        "movaps %xmm0, %xmm4\n"
        "divss %xmm1, %xmm4\n"
        "cmpl $1, dxState+8356\n" /* line 1487 */
        "je .Lfcecd4_000cef37\n"
        "movl 0x3ec(%eax), %esi\n" /* line 1507 */
        "movl 0x3e8(%eax), %ebx\n"
        "cvtsi2ssl %esi, %xmm1\n"
        "cvtsi2ssl %ebx, %xmm2\n"
        "cvtsi2ssl 0x3e4(%eax), %xmm3\n"
        "cvtsi2ssl 0x3e0(%eax), %xmm5\n"
        ".Lfcecd4_000ced4d:\n"
        "movaps %xmm6, %xmm0\n" /* line 86 */
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss -0x24(%ebp), %xmm7\n"
        "mulss %xmm0, %xmm7\n"
        "movss %xmm7, -0x24(%ebp)\n"
        "movaps %xmm4, %xmm7\n" /* line 87 */
        "mulss %xmm1, %xmm7\n"
        "mulss %xmm7, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "mulss %xmm6, %xmm5\n" /* line 100 */
        "movss -0x24(%ebp), %xmm0\n"
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "mulss %xmm4, %xmm3\n" /* line 101 */
        "movss -0x28(%ebp), %xmm7\n"
        "addss %xmm3, %xmm7\n"
        "movss %xmm7, -0x20(%ebp)\n"
        "leal -0x10(%ebp), %eax\n" /* line 1556 | yOffset */
        "movl %eax, 4(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* xOffset */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "movss %xmm4, -0x68(%ebp)\n"
        "movss %xmm6, -0x78(%ebp)\n"
        "calll MacOpenGLUtils_GetSubPixelOffset\n"
        "movss -0x78(%ebp), %xmm6\n" /* line 1558 */
        "movaps %xmm6, %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n" /* xOffset */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0x68(%ebp), %xmm4\n" /* line 1559 */
        "movaps %xmm4, %xmm0\n"
        "mulss -0x10(%ebp), %xmm0\n" /* yOffset */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        /* { scope 2 */
        "cmpl $1, %ebx\n" /* line 144 */
        "movss -0x48(%ebp), %xmm1\n"
        "movss -0x58(%ebp), %xmm2\n"
        "ja .Lfcecd4_000ceeef\n"
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        /* } scope */
        /* { scope 2 */
        ".Lfcecd4_000cee12:\n"
        "cmpl $1, %esi\n"
        "ja .Lfcecd4_000cef15\n"
        ".Lfcecd4_000cee1b:\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        /* } scope */
        ".Lfcecd4_000cee23:\n"
        "movaps %xmm2, %xmm0\n" /* line 1571 */
        "divss %xmm5, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* horizontalScale */
        "movaps %xmm1, %xmm7\n" /* line 1572 */
        "divss %xmm3, %xmm7\n"
        "movss %xmm7, -0x2c(%ebp)\n" /* verticalScale */
        "movss %xmm4, 0x10(%esp)\n" /* line 1583 */
        "movss %xmm6, 0xc(%esp)\n"
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "subss %xmm0, %xmm1\n"
        "divss %xmm3, %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "subss %xmm0, %xmm2\n"
        "divss %xmm5, %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl $0xab, (%esp)\n"
        "calll RB_SetCodeConstant\n"
        "movl $0x3f800000, 0x10(%esp)\n" /* line 1587 */
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* verticalScale */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x24(%ebp), %xmm7\n"
        "mulss -0x30(%ebp), %xmm7\n" /* horizontalScale */
        "movss %xmm7, 4(%esp)\n"
        "movl $0xae, (%esp)\n"
        "calll RB_SetCodeConstant\n"
        "movl %ebx, 0x10(%esp)\n" /* line 1588 */
        "movl %ebx, 0xc(%esp)\n"
        "movss -0x20(%ebp), %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* verticalScale */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x1c(%ebp), %xmm7\n"
        "mulss -0x30(%ebp), %xmm7\n" /* horizontalScale */
        "movss %xmm7, 4(%esp)\n"
        "movl $0xaf, (%esp)\n"
        "calll RB_SetCodeConstant\n"
        /* } scope */
        "addl $0x90, %esp\n" /* line 1594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfcecd4_000ceeef:\n"
        "movl $1, %edx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lfcecd4_000ceef9:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ebx\n"
        "jbe .Lfcecd4_000cef6f\n"
        "subl $1, %eax\n"
        "jne .Lfcecd4_000ceef9\n"
        "testl %edx, %edx\n"
        "js .Lfcecd4_000cef43\n"
        ".Lfcecd4_000cef08:\n"
        "cvtsi2ssl %edx, %xmm5\n"
        /* } scope */
        /* { scope 2 */
        "cmpl $1, %esi\n"
        "jbe .Lfcecd4_000cee1b\n"
        ".Lfcecd4_000cef15:\n"
        "movl $1, %edx\n"
        "movl $0x20, %eax\n"
        ".Lfcecd4_000cef1f:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %esi\n"
        "jbe .Lfcecd4_000cef82\n"
        "subl $1, %eax\n"
        "jne .Lfcecd4_000cef1f\n"
        "testl %edx, %edx\n"
        "js .Lfcecd4_000cef59\n"
        ".Lfcecd4_000cef2e:\n"
        "cvtsi2ssl %edx, %xmm3\n"
        "jmp .Lfcecd4_000cee23\n"
        /* } scope */
        ".Lfcecd4_000cef37:\n"
        "pxor %xmm3, %xmm3\n" /* line 1487 */
        "movaps %xmm3, %xmm5\n"
        "jmp .Lfcecd4_000ced4d\n"
        /* { scope 2 */
        ".Lfcecd4_000cef43:\n"
        "movl %edx, %eax\n" /* line 144 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm5\n"
        "addss %xmm5, %xmm5\n"
        "jmp .Lfcecd4_000cee12\n"
        /* } scope */
        /* { scope 2 */
        ".Lfcecd4_000cef59:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm3\n"
        "addss %xmm3, %xmm3\n"
        "jmp .Lfcecd4_000cee23\n"
        /* } scope */
        /* { scope 2 */
        ".Lfcecd4_000cef6f:\n"
        "testl %edx, %edx\n"
        "jns .Lfcecd4_000cef08\n"
        "shrl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm5\n"
        "addss %xmm5, %xmm5\n"
        "jmp .Lfcecd4_000cee12\n"
        /* } scope */
        /* { scope 2 */
        ".Lfcecd4_000cef82:\n"
        "testl %edx, %edx\n"
        "jns .Lfcecd4_000cef2e\n"
        "shrl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm3\n"
        "addss %xmm3, %xmm3\n"
        "jmp .Lfcecd4_000cee23\n"
    );
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
__attribute__((naked))
void RB_SetRenderTarget(GfxRenderTargetId newTargetId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1662 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* newTargetId */
        "movl dxState+8344, %eax\n" /* line 1664 */
        "cmpl %esi, %eax\n" /* newTargetId */
        "je .Lfcefdc_000cf20c\n"
        "cmpl $4, %esi\n" /* line 1685 | newTargetId */
        "je .Lfcefdc_000cf19f\n"
        ".Lfcefdc_000ceffe:\n"
        "xorl %edx, %edx\n"
        ".Lfcefdc_000cf000:\n"
        "movl imp_g_InhibitCopy, %eax\n"
        "movb %dl, (%eax)\n"
        "movl %esi, dxState+8344\n" /* line 1687 | newTargetId */
        "movl imp_dx, %ebx\n" /* line 1688 */
        "leal (%esi, %esi, 4), %eax\n" /* newTargetId */
        "movl 0x2c30(%ebx, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lfcefdc_000cf05a\n"
        /* { scope 1 */
        "movl imp_vidConfig, %eax\n" /* line 1024 */
        "movl 0x1c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lfcefdc_000cf05a\n"
        "xorl %edi, %edi\n" /* samplerIndex */
        "movl $dxState, %ebx\n"
        "movl %eax, -0x20(%ebp)\n"
        ".Lfcefdc_000cf03a:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1025 */
        "cmpl 0x20f4(%ebx), %edx\n"
        "je .Lfcefdc_000cf1cf\n"
        ".Lfcefdc_000cf049:\n"
        "addl $1, %edi\n" /* line 1024 | samplerIndex */
        "addl $4, %ebx\n"
        "cmpl 0x1c(%eax), %edi\n" /* samplerIndex */
        "jl .Lfcefdc_000cf03a\n"
        ".Lfcefdc_000cf054:\n"
        "movl imp_dx, %ebx\n"
        /* } scope */
        ".Lfcefdc_000cf05a:\n"
        "movl 8(%ebx), %edx\n" /* line 1694 */
        "movl (%edx), %ecx\n"
        "leal (%esi, %esi, 4), %eax\n" /* newTargetId */
        "leal (%ebx, %eax, 4), %ebx\n"
        "movl 0x2c34(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x94(%ecx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %edi\n" /* samplerIndex */
        "testl %edi, %edi\n" /* samplerIndex */
        "jne .Lfcefdc_000cf054\n"
        "movl 0x2c34(%ebx), %eax\n" /* line 1695 */
        "movl %eax, dxState+8360\n"
        "testl %esi, %esi\n" /* line 1698 | newTargetId */
        "je .Lfcefdc_000cf1ef\n"
        "cmpl $4, %esi\n" /* line 1703 | newTargetId */
        "je .Lfcefdc_000cf1b2\n"
        "cmpl $8, %esi\n" /* line 1708 | newTargetId */
        "je .Lfcefdc_000cf1b2\n"
        "cmpl $3, %esi\n" /* line 1713 | newTargetId */
        "je .Lfcefdc_000cf214\n"
        "cmpl $9, %esi\n" /* line 1718 | newTargetId */
        "je .Lfcefdc_000cf1b2\n"
        "cmpl $0xb, %esi\n" /* newTargetId */
        "je .Lfcefdc_000cf1b2\n"
        "cmpl $0xc, %esi\n" /* newTargetId */
        "je .Lfcefdc_000cf1b2\n"
        ".Lfcefdc_000cf0d4:\n"
        "cmpl $4, %esi\n" /* line 1728 | newTargetId */
        "movl imp_g_RenderToShadowCookie, %eax\n"
        "sete (%eax)\n"
        "movl dxState+8344, %eax\n" /* line 1731 */
        "movl s_viewportBehaviorForRenderTarget(, %eax, 4), %eax\n"
        "movl %eax, dxState+8356\n"
        "movl imp_dx, %ebx\n" /* line 1732 */
        "leal (%esi, %esi, 4), %eax\n" /* newTargetId */
        "leal (, %eax, 4), %esi\n" /* newTargetId */
        "leal (%esi, %ebx), %edx\n" /* newTargetId */
        "movl 0x2c3c(%edx), %ecx\n"
        "movl %ecx, dxState+8348\n"
        "movl 0x2c40(%edx), %eax\n" /* line 1733 */
        "movl %eax, dxState+8352\n"
        "movl $0, dxState+8368\n" /* line 1738 */
        "movl $0, dxState+8372\n" /* line 1739 */
        "movl %ecx, dxState+8376\n" /* line 1740 */
        "movl %eax, dxState+8380\n" /* line 1741 */
        "movl $0, dxState+8384\n" /* line 1742 */
        "movl $0x3f800000, dxState+8388\n" /* line 1743 */
        "movl dxState+8364, %eax\n" /* line 1746 */
        "cmpl 0x2c38(%edx), %eax\n"
        "je .Lfcefdc_000cf193\n"
        "movl %esi, %edi\n" /* newTargetId, samplerIndex */
        "movl %ebx, %esi\n" /* newTargetId */
        "jmp .Lfcefdc_000cf162\n"
        ".Lfcefdc_000cf160:\n"
        "movl %esi, %ebx\n" /* newTargetId */
        ".Lfcefdc_000cf162:\n"
        "movl 8(%ebx), %eax\n" /* line 1748 */
        "movl (%eax), %ecx\n"
        "leal (%edi, %ebx), %ebx\n" /* samplerIndex */
        "movl 0x2c38(%ebx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x9c(%ecx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcefdc_000cf160\n"
        "movl 0x2c38(%ebx), %eax\n" /* line 1749 */
        "movl %eax, dxState+8364\n"
        ".Lfcefdc_000cf193:\n"
        "addl $0x2c, %esp\n" /* line 1753 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp RB_UpdateViewportConstants\n" /* line 1752 */
        ".Lfcefdc_000cf19f:\n"
        "cmpl $3, %eax\n" /* line 1685 */
        "jne .Lfcefdc_000ceffe\n"
        "movl $1, %edx\n"
        "jmp .Lfcefdc_000cf000\n"
        ".Lfcefdc_000cf1b2:\n"
        "movl $0x409, (%esp)\n" /* line 1720 */
        "calll glDrawBuffer\n"
        "movl $0x409, (%esp)\n" /* line 1721 */
        "calll glReadBuffer\n"
        "jmp .Lfcefdc_000cf0d4\n"
        /* { scope 1 */
        ".Lfcefdc_000cf1cf:\n"
        "movl $0, 8(%esp)\n" /* line 1026 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* samplerIndex */
        "calll RB_SetSampler\n"
        "movl -0x20(%ebp), %eax\n"
        "jmp .Lfcefdc_000cf049\n"
        /* } scope */
        ".Lfcefdc_000cf1ef:\n"
        "movl $0x405, (%esp)\n" /* line 1700 */
        "calll glDrawBuffer\n"
        "movl $0x405, (%esp)\n" /* line 1701 */
        "calll glReadBuffer\n"
        "jmp .Lfcefdc_000cf0d4\n"
        ".Lfcefdc_000cf20c:\n"
        "addl $0x2c, %esp\n" /* line 1753 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcefdc_000cf214:\n"
        "movl $0x40a, (%esp)\n" /* line 1715 */
        "calll glDrawBuffer\n"
        "movl $0x40a, (%esp)\n" /* line 1716 */
        "calll glReadBuffer\n"
        "jmp .Lfcefdc_000cf0d4\n"
    );
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
