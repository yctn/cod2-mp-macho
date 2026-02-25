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
static const DxTextureStageEnums texStageEnums; /* 0x2f249c */
static const DxTextureStageEnums texStageEnums_002f24ac; /* 0x2f24ac */
static const DxTextureStageEnums texStageEnums_002f24ac; /* 0x2f24ac */
static const byte defaultSamplerStateTable[5]; /* 0x2f22a0 */
static const DWORD s_blendTable[13]; /* 0x2f2440 */
static const DWORD s_blendOpTable[6]; /* 0x2f2474 */
static const DWORD s_cullTable[4]; /* 0x2f248c */
static const D3DTEXTUREFILTERTYPE s_filterTable[4]; /* 0x2f2290 */
static const DWORD s_stencilOpTable[8]; /* 0x2f23e0 */
static const DWORD s_stencilFuncTable[8]; /* 0x2f23a0 */
static const DxStencilDecode s_stencilOpDecode[6]; /* 0x2f2400 */
static const DxStencilDecode s_stencilFuncDecode[2]; /* 0x2f23c0 */
static const DxTextureOpDecode s_textureOpTable[23]; /* 0x2f22c0 */
static const DWORD s_textureArgTable[7]; /* 0x2f2378 */
static const GfxViewportBehavior s_viewportBehaviorForRenderTarget[12]; /* 0x2f2260 */

void RB_ChangeIndices(IDirect3DIndexBuffer9 *ib);
void RB_ChangeStreamSource(int streamIndex, IDirect3DVertexBuffer9 *vb, int vertexOffset, int vertexStride);
void RB_DecideDefaultSamplerState(void);
void RB_SetAnisotropy(void);
void RB_SetAlphaAntiAliasingState(int stateBits0);
static void RB_ChangeTextureStageState(int texStageBits, int *activeTexStageBits);
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

/* line 1805 */
__attribute__((naked))
void RB_ChangeIndices(IDirect3DIndexBuffer9 *ib)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1805 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ib */
        "movl 0x1186ccc, %eax\n" /* line 1809 */
        "movl %eax, 0x1186cdc\n"
        "movl %edi, 0x1186ccc\n" /* line 1810 | ib */
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lfcd0f0_000cd118:\n"
        "movl 8(%esi), %eax\n" /* line 1811 */
        "movl (%eax), %edx\n"
        "movl %edi, 4(%esp)\n" /* ib */
        "movl %eax, (%esp)\n"
        "calll *0x1a0(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd0f0_000cd118\n"
        "movl $0, 0x1186cdc\n" /* line 1812 */
        "addl $0x1c, %esp\n" /* line 1813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1816 */
__attribute__((naked))
void RB_ChangeStreamSource(int streamIndex, IDirect3DVertexBuffer9 *vb, int vertexOffset, int vertexStride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1816 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* streamIndex */
        "movl $0x1186cd0, %eax\n" /* line 1820 */
        "leal (%ebx, %ebx, 2), %edx\n" /* streamIndex */
        "shll $2, %edx\n"
        "movl 0x1186cd0(%edx), %ecx\n"
        "movl %ecx, 0x1186ce0\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1821 | vb */
        "movl %ecx, 0x1186cd0(%edx)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1822 | vertexOffset */
        "movl %ecx, 4(%edx, %eax)\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1823 | vertexStride */
        "movl %ecx, 8(%edx, %eax)\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcd142_000cd188:\n"
        "movl 8(%edi), %eax\n" /* line 1824 */
        "movl (%eax), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* vertexStride */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* vertexOffset */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* vb */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* streamIndex */
        "movl %eax, (%esp)\n"
        "calll *0x190(%edx)\n"
        "movl (%esi), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfcd142_000cd188\n"
        "movl $0, 0x1186ce0\n" /* line 1825 */
        "addl $0x2c, %esp\n" /* line 1826 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 899 */
__attribute__((naked))
void RB_DecideDefaultSamplerState(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 899 */
        "movl %esp, %ebp\n"
        "movl 0x195f0dc, %eax\n" /* line 903 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movzbl defaultSamplerStateTable(%eax), %edx\n"
        "movl 0x195f0c8, %eax\n"
        "movb %dl, 0x4be(%eax)\n"
        "popl %ebp\n" /* line 904 */
        "retl\n"
    );
}

/* line 907 */
__attribute__((naked))
void RB_SetAnisotropy(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 907 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 0x195f0c4, %eax\n" /* line 912 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl 0x195eed0, %edx\n"
        "movl %eax, 0x2d6c(%edx)\n"
        "movl 0x2d70(%edx), %ecx\n" /* line 913 */
        "cmpl %ecx, %eax\n"
        "jle .Lfcd1ea_000cd218\n"
        "movl %ecx, 0x2d6c(%edx)\n" /* line 914 */
        ".Lfcd1ea_000cd218:\n"
        "cmpl $1, 0x2d6c(%edx)\n" /* line 915 */
        "jle .Lfcd1ea_000cd284\n"
        ".Lfcd1ea_000cd221:\n"
        "movl 0x2d6c(%edx), %ebx\n" /* line 918 | anisotropy */
        "movl $1, %eax\n" /* line 154 */
        "cmpl %ebx, %eax\n"
        "cmovnsl %eax, %ebx\n"
        "movl 0x195eeec, %eax\n" /* line 919 */
        "movl 0x1c(%eax), %esi\n" /* samplerIndex */
        "testl %esi, %esi\n" /* samplerIndex */
        "jle .Lfcd1ea_000cd27d\n"
        "xorl %esi, %esi\n" /* samplerIndex */
        "jmp .Lfcd1ea_000cd247\n"
        ".Lfcd1ea_000cd241:\n"
        "movl 0x195eed0, %edx\n"
        ".Lfcd1ea_000cd247:\n"
        "movl 8(%edx), %eax\n" /* line 920 */
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n" /* anisotropy */
        "movl $0xa, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll *0x114(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcd1ea_000cd241\n"
        "addl $1, %esi\n" /* line 919 | samplerIndex */
        "movl 0x195eeec, %eax\n"
        "cmpl 0x1c(%eax), %esi\n" /* samplerIndex */
        "jl .Lfcd1ea_000cd241\n"
        /* } scope */
        ".Lfcd1ea_000cd27d:\n"
        "addl $0x10, %esp\n" /* line 921 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcd1ea_000cd284:\n"
        "movl $0, 0x2d6c(%edx)\n" /* line 916 */
        "jmp .Lfcd1ea_000cd221\n"
    );
}

/* line 438 */
__attribute__((naked))
void RB_SetAlphaAntiAliasingState(int stateBits0)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 438 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "testl $0xf00, 8(%ebp)\n" /* line 444 | stateBits0 */
        "je .Lfcd290_000cd2d2\n"
        "xorl %ebx, %ebx\n" /* aaAlphaFormat */
        ".Lfcd290_000cd2a2:\n"
        "movl 0x195eed0, %eax\n" /* line 450 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* aaAlphaFormat */
        "movl $0xb5, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd290_000cd2a2\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 451 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcd290_000cd2d2:\n"
        "movl 0x195f0d0, %eax\n" /* line 446 */
        "movl (%eax), %eax\n"
        "movl $0x41415353, %ebx\n" /* aaAlphaFormat */
        "cmpl $2, 8(%eax)\n"
        "movl $0x434f5441, %eax\n"
        "cmovnel %eax, %ebx\n" /* aaAlphaFormat */
        "jmp .Lfcd290_000cd2a2\n"
    );
}

/* line 781 */
static __attribute__((naked))
void RB_ChangeTextureStageState(int texStageBits, int *activeTexStageBits)
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
        "movl 0x195eed0, %edx\n" /* line 809 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl %ebx, 0xc(%esp)\n" /* texArg */
        "movl 4(%esi), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* stageIndex */
        "movl %eax, (%esp)\n"
        "calll *0x10c(%ecx)\n"
        "movl 0x195f0e0, %ecx\n"
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
        "movl 0x195eed0, %ecx\n" /* line 795 */
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
        "movl 0x195f0e0, %eax\n"
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
__attribute__((naked))
void RB_ChangeAlphaStageState(int stageIndex, int texStageBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 837 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* stageIndex */
        "movl 0xc(%ebp), %ecx\n" /* texStageBits */
        /* { scope 1 */
        "movl $0x1186c74, 8(%ebp)\n" /* line 847 | stageIndex */
        "movl $texStageEnums, %edx\n"
        /* } scope */
        "popl %ebp\n" /* line 848 */
        /* { scope 1 */
        "jmp RB_ChangeTextureStageState\n" /* line 847 */
    );
}

/* line 823 */
__attribute__((naked))
void RB_ChangeColorStageState(int stageIndex, int texStageBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 823 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* stageIndex */
        "movl 0xc(%ebp), %ecx\n" /* texStageBits */
        /* { scope 1 */
        "movl $0x1186c54, 8(%ebp)\n" /* line 833 | stageIndex */
        "movl $texStageEnums, %edx\n"
        /* } scope */
        "popl %ebp\n" /* line 834 */
        /* { scope 1 */
        "jmp RB_ChangeTextureStageState\n" /* line 833 */
    );
}

/* line 851 */
__attribute__((naked))
void RB_SetSamplerConstantDx7(unsigned int color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 851 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* color */
        "cmpl %ebx, 0x1186d4c\n" /* line 853 | color */
        "je .Lfcd47c_000cd4c2\n"
        "movl %ebx, 0x1186d4c\n" /* line 855 | color */
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcd47c_000cd4a2:\n"
        "movl 8(%edi), %eax\n" /* line 856 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* color */
        "movl $0x3c, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd47c_000cd4a2\n"
        ".Lfcd47c_000cd4c2:\n"
        "addl $0x1c, %esp\n" /* line 858 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 861 */
__attribute__((naked))
void RB_ChangeGenTexCoords(int samplerIndex, int genTexCoords)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 861 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* samplerIndex */
        "movzbl 0xc(%ebp), %eax\n" /* genTexCoords */
        "movb %al, -0x59(%ebp)\n" /* genTexCoords */
        /* { scope 1 */
        "cmpb $1, %al\n" /* line 867 */
        "je .Lfcd4ca_000cd577\n"
        "jae .Lfcd4ca_000cd55d\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcd4ca_000cd4f3:\n"
        "movl 8(%edi), %eax\n" /* line 870 */
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n" /* samplerIndex */
        "movl $0xb, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll *0x10c(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd4ca_000cd4f3\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcd4ca_000cd523:\n"
        "movl 8(%edi), %eax\n" /* line 871 */
        "movl (%eax), %edx\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll *0x10c(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd4ca_000cd523\n"
        "movzbl -0x59(%ebp), %eax\n" /* line 894 | genTexCoords */
        "movb %al, 0x1186c95(%ebx)\n" /* samplerIndex */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 895 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcd4ca_000cd55d:\n"
        "cmpb $2, %al\n" /* line 867 */
        "je .Lfcd4ca_000cd647\n"
        "movzbl -0x59(%ebp), %eax\n" /* line 894 | genTexCoords */
        "movb %al, 0x1186c95(%ebx)\n" /* samplerIndex */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 895 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcd4ca_000cd577:\n"
        "leal -0x58(%ebp), %edx\n" /* line 876 | transform */
        "movl %edx, 4(%esp)\n"
        "movl 0x195f0c8, %eax\n"
        "movl 0x3c8(%eax), %eax\n"
        "addl $0x48, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixInverse44\n"
        "xorl %eax, %eax\n" /* line 877 */
        "movl %eax, -0x28(%ebp)\n"
        "movl %eax, -0x24(%ebp)\n" /* line 878 */
        "movl %eax, -0x20(%ebp)\n" /* line 879 */
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcd4ca_000cd5ab:\n"
        "movl 8(%edi), %eax\n" /* line 880 */
        "movl (%eax), %edx\n"
        "movl $0x20000, 0xc(%esp)\n"
        "movl $0xb, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll *0x10c(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd4ca_000cd5ab\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcd4ca_000cd5df:\n"
        "movl 8(%edi), %eax\n" /* line 881 */
        "movl (%eax), %edx\n"
        "movl $3, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll *0x10c(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd4ca_000cd5df\n"
        "leal 0x10(%ebx), %esi\n" /* samplerIndex */
        "movl 0x195f0e0, %edi\n"
        ".Lfcd4ca_000cd610:\n"
        "movl 0x195eed0, %ecx\n" /* line 882 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "leal -0x58(%ebp), %ecx\n" /* transform */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%edi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcd4ca_000cd610\n"
        "movzbl -0x59(%ebp), %eax\n" /* line 894 | genTexCoords */
        "movb %al, 0x1186c95(%ebx)\n" /* samplerIndex */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 895 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcd4ca_000cd647:\n"
        "leal -0x58(%ebp), %eax\n" /* line 886 | transform */
        "movl %eax, (%esp)\n"
        "calll MatrixIdentity44\n"
        "movl 0x195f0c8, %eax\n" /* line 887 */
        "movl 0x4dc(%eax), %eax\n"
        "xorl $0x80000000, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcd4ca_000cd671:\n"
        "movl 8(%edi), %eax\n" /* line 888 */
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n" /* samplerIndex */
        "movl $0xb, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll *0x10c(%edx)\n"
        "movl (%esi), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfcd4ca_000cd671\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcd4ca_000cd6a1:\n"
        "movl 8(%edi), %eax\n" /* line 889 */
        "movl (%eax), %edx\n"
        "movl $3, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll *0x10c(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd4ca_000cd6a1\n"
        "leal 0x10(%ebx), %esi\n" /* samplerIndex */
        "movl 0x195f0e0, %edi\n"
        ".Lfcd4ca_000cd6d2:\n"
        "movl 0x195eed0, %edx\n" /* line 890 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "leal -0x58(%ebp), %ecx\n" /* transform */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd4ca_000cd6d2\n"
        "movzbl -0x59(%ebp), %eax\n" /* line 894 | genTexCoords */
        "movb %al, 0x1186c95(%ebx)\n" /* samplerIndex */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 895 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1059 */
__attribute__((naked))
D3DMATRIX * RB_GetActiveWorldMatrix(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1059 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0x195f0c8, %ebx\n"
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4f0(%eax, %ebx), %eax\n"
        "popl %ebx\n" /* line 1062 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1065 */
__attribute__((naked))
void RB_ChangedWorldMatrix(float worldScale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1065 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0x195f0c8, %ebx\n" /* line 1071 */
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %ebx), %edx\n"
        "movl 8(%ebp), %eax\n" /* line 1072 | worldScale */
        "movl %eax, (%edx)\n"
        "movb $1, 0x110(%edx)\n" /* line 1074 */
        "movb $0, 0x111(%edx)\n" /* line 1075 */
        "movb $0, 0x112(%edx)\n" /* line 1076 */
        "movb $0, 0x113(%edx)\n" /* line 1077 */
        "movb $0, 0x550(%edx)\n" /* line 1079 */
        "movb $0, 0x551(%edx)\n" /* line 1080 */
        "movb $0, 0x552(%edx)\n" /* line 1081 */
        "movb $0, 0x553(%edx)\n" /* line 1082 */
        "movb $0, 0x880(%edx)\n" /* line 1084 */
        "movb $0, 0x881(%edx)\n" /* line 1085 */
        "movb $0, 0x882(%edx)\n" /* line 1086 */
        "movb $0, 0x883(%edx)\n" /* line 1087 */
        "movb $0, 0xdd0(%edx)\n" /* line 1090 */
        "movb $0, 0xdd1(%edx)\n" /* line 1091 */
        "movb $0, 0xdd2(%edx)\n" /* line 1092 */
        "movb $0, 0xdd3(%edx)\n" /* line 1093 */
        "movb $0, 0x220(%edx)\n" /* line 1096 */
        "movb $0, 0x221(%edx)\n" /* line 1097 */
        "movb $0, 0x222(%edx)\n" /* line 1098 */
        "movb $0, 0x223(%edx)\n" /* line 1099 */
        "movb $0, 0x660(%edx)\n" /* line 1101 */
        "movb $0, 0x661(%edx)\n" /* line 1102 */
        "movb $0, 0x662(%edx)\n" /* line 1103 */
        "movb $0, 0x663(%edx)\n" /* line 1104 */
        "movb $0, 0x990(%edx)\n" /* line 1106 */
        "movb $0, 0x991(%edx)\n" /* line 1107 */
        "movb $0, 0x992(%edx)\n" /* line 1108 */
        "movb $0, 0x993(%edx)\n" /* line 1109 */
        "movb $0, 0xaa0(%edx)\n" /* line 1111 */
        "movb $0, 0xaa1(%edx)\n" /* line 1112 */
        "movb $0, 0xaa2(%edx)\n" /* line 1113 */
        "movb $0, 0xaa3(%edx)\n" /* line 1114 */
        "movb $0, 0xbb0(%edx)\n" /* line 1116 */
        "movb $0, 0xbb1(%edx)\n" /* line 1117 */
        "movb $0, 0xbb2(%edx)\n" /* line 1118 */
        "movb $0, 0xbb3(%edx)\n" /* line 1119 */
        "movb $0, 0xcc0(%edx)\n" /* line 1121 */
        "movb $0, 0xcc1(%edx)\n" /* line 1122 */
        "movb $0, 0xcc2(%edx)\n" /* line 1123 */
        "movb $0, 0xcc3(%edx)\n" /* line 1124 */
        "movl 0x195eec0, %eax\n" /* line 1127 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfcd736_000cd895\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1130 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcd736_000cd895:\n"
        "leal 0x10(%edx), %ebx\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        /* { scope 1 */
        ".Lfcd736_000cd8a4:\n"
        "movl 8(%edi), %eax\n" /* line 1128 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd736_000cd8a4\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1130 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1133 */
__attribute__((naked))
void RB_SetViewMatrix(const D3DMATRIX *matrix)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1133 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* matrix */
        /* { scope 1 */
        "movl 0x195f0c8, %ebx\n" /* line 1139 */
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %ebx), %eax\n"
        "movl (%esi), %edx\n" /* line 1141 | matrix */
        "movl %edx, 0x230(%eax)\n"
        "movl 4(%esi), %edx\n" /* matrix */
        "movl %edx, 0x234(%eax)\n"
        "movl 8(%esi), %edx\n" /* matrix */
        "movl %edx, 0x238(%eax)\n"
        "movl 0xc(%esi), %edx\n" /* matrix */
        "movl %edx, 0x23c(%eax)\n"
        "movl 0x10(%esi), %edx\n" /* matrix */
        "movl %edx, 0x240(%eax)\n"
        "movl 0x14(%esi), %edx\n" /* matrix */
        "movl %edx, 0x244(%eax)\n"
        "movl 0x18(%esi), %edx\n" /* matrix */
        "movl %edx, 0x248(%eax)\n"
        "movl 0x1c(%esi), %edx\n" /* matrix */
        "movl %edx, 0x24c(%eax)\n"
        "movl 0x20(%esi), %edx\n" /* matrix */
        "movl %edx, 0x250(%eax)\n"
        "movl 0x24(%esi), %edx\n" /* matrix */
        "movl %edx, 0x254(%eax)\n"
        "movl 0x28(%esi), %edx\n" /* matrix */
        "movl %edx, 0x258(%eax)\n"
        "movl 0x2c(%esi), %edx\n" /* matrix */
        "movl %edx, 0x25c(%eax)\n"
        "movl 0x30(%esi), %edx\n" /* matrix */
        "movl %edx, 0x260(%eax)\n"
        "movl 0x34(%esi), %edx\n" /* matrix */
        "movl %edx, 0x264(%eax)\n"
        "movl 0x38(%esi), %edx\n" /* matrix */
        "movl %edx, 0x268(%eax)\n"
        "movl 0x3c(%esi), %edx\n" /* matrix */
        "movl %edx, 0x26c(%eax)\n"
        "movb $1, 0x330(%eax)\n" /* line 1142 */
        "movb $0, 0x331(%eax)\n" /* line 1143 */
        "movb $0, 0x332(%eax)\n" /* line 1144 */
        "movb $0, 0x333(%eax)\n" /* line 1145 */
        "movb $0, 0x550(%eax)\n" /* line 1147 */
        "movb $0, 0x551(%eax)\n" /* line 1148 */
        "movb $0, 0x552(%eax)\n" /* line 1149 */
        "movb $0, 0x553(%eax)\n" /* line 1150 */
        "movb $0, 0x770(%eax)\n" /* line 1152 */
        "movb $0, 0x771(%eax)\n" /* line 1153 */
        "movb $0, 0x772(%eax)\n" /* line 1154 */
        "movb $0, 0x773(%eax)\n" /* line 1155 */
        "movb $0, 0x880(%eax)\n" /* line 1157 */
        "movb $0, 0x881(%eax)\n" /* line 1158 */
        "movb $0, 0x882(%eax)\n" /* line 1159 */
        "movb $0, 0x883(%eax)\n" /* line 1160 */
        "movb $0, 0xdd0(%eax)\n" /* line 1163 */
        "movb $0, 0xdd1(%eax)\n" /* line 1164 */
        "movb $0, 0xdd2(%eax)\n" /* line 1165 */
        "movb $0, 0xdd3(%eax)\n" /* line 1166 */
        "movb $0, 0x660(%eax)\n" /* line 1169 */
        "movb $0, 0x661(%eax)\n" /* line 1170 */
        "movb $0, 0x662(%eax)\n" /* line 1171 */
        "movb $0, 0x663(%eax)\n" /* line 1172 */
        "movb $0, 0x990(%eax)\n" /* line 1174 */
        "movb $0, 0x991(%eax)\n" /* line 1175 */
        "movb $0, 0x992(%eax)\n" /* line 1176 */
        "movb $0, 0x993(%eax)\n" /* line 1177 */
        "movl 0x195eec0, %eax\n" /* line 1180 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfcd8cc_000cda64\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcd8cc_000cda64:\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %ebx\n"
        /* { scope 1 */
        ".Lfcd8cc_000cda70:\n"
        "movl 8(%edi), %eax\n" /* line 1181 */
        "movl (%eax), %edx\n"
        "movl %esi, 8(%esp)\n" /* matrix */
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcd8cc_000cda70\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1187 */
__attribute__((naked))
void RB_SetViewMatrixForWDx7(float w)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1187 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 0x195f0c8, %eax\n" /* line 1191 */
        "movl 0x3c8(%eax), %eax\n"
        "movl 0x48(%eax), %edx\n"
        "movl %edx, -0x58(%ebp)\n" /* transform */
        "movl 0x4c(%eax), %edx\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl 0x50(%eax), %edx\n"
        "movl %edx, -0x50(%ebp)\n"
        "movl 0x54(%eax), %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl 0x58(%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl 0x5c(%eax), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "movl 0x60(%eax), %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl 0x64(%eax), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0x68(%eax), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x6c(%eax), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x70(%eax), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl 0x74(%eax), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x78(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl 0x7c(%eax), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 1196 | w */
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x58(%ebp), %edi\n" /* transform */
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lfcda98_000cdb1e:\n"
        "movl 8(%esi), %eax\n" /* line 1197 */
        "movl (%eax), %edx\n"
        "movl %edi, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfcda98_000cdb1e\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1198 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1254 */
__attribute__((naked))
void RB_SetDepthHackNearClip(float nearClip)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1254 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* nearClip */
        "movl 0x195f0c8, %esi\n" /* line 1259 */
        "movl 0x2e80(%esi), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "xorl $0x80000000, %ebx\n" /* nearClip */
        "movl %ebx, 0x858(%eax, %esi)\n" /* nearClip */
        "movl 0x2e80(%esi), %edx\n" /* line 1206 */
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %esi), %edx\n"
        "movb $1, 0x440(%edx)\n" /* line 1208 */
        "movb $0, 0x441(%edx)\n" /* line 1209 */
        "movb $0, 0x442(%edx)\n" /* line 1210 */
        "movb $0, 0x443(%edx)\n" /* line 1211 */
        "movb $0, 0x770(%edx)\n" /* line 1213 */
        "movb $0, 0x771(%edx)\n" /* line 1214 */
        "movb $0, 0x772(%edx)\n" /* line 1215 */
        "movb $0, 0x773(%edx)\n" /* line 1216 */
        "movb $0, 0x880(%edx)\n" /* line 1218 */
        "movb $0, 0x881(%edx)\n" /* line 1219 */
        "movb $0, 0x882(%edx)\n" /* line 1220 */
        "movb $0, 0x883(%edx)\n" /* line 1221 */
        "movb $0, 0xdd0(%edx)\n" /* line 1224 */
        "movb $0, 0xdd1(%edx)\n" /* line 1225 */
        "movb $0, 0xdd2(%edx)\n" /* line 1226 */
        "movb $0, 0xdd3(%edx)\n" /* line 1227 */
        "movb $0, 0x990(%edx)\n" /* line 1230 */
        "movb $0, 0x991(%edx)\n" /* line 1231 */
        "movb $0, 0x992(%edx)\n" /* line 1232 */
        "movb $0, 0x993(%edx)\n" /* line 1233 */
        "movl 0x195eec0, %eax\n" /* line 1236 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfcdb46_000cdc3b\n"
        "addl $0x1c, %esp\n" /* line 1261 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcdb46_000cdc3b:\n"
        "leal 0x340(%edx), %ebx\n" /* nearClip */
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcdb46_000cdc4d:\n"
        "movl 8(%edi), %eax\n" /* line 1237 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcdb46_000cdc4d\n"
        "addl $0x1c, %esp\n" /* line 1261 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1264 */
__attribute__((naked))
void RB_SetShadowLookupMatrix(const D3DMATRIX *matrix)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1264 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* matrix */
        "movl 0x195f0c8, %eax\n" /* line 1266 */
        "movl (%edx), %ecx\n"
        "movl %ecx, 0x36e48(%eax)\n"
        "movl 4(%edx), %ecx\n"
        "movl %ecx, 0x36e4c(%eax)\n"
        "movl 8(%edx), %ecx\n"
        "movl %ecx, 0x36e50(%eax)\n"
        "movl 0xc(%edx), %ecx\n"
        "movl %ecx, 0x36e54(%eax)\n"
        "movl 0x10(%edx), %ecx\n"
        "movl %ecx, 0x36e58(%eax)\n"
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, 0x36e5c(%eax)\n"
        "movl 0x18(%edx), %ecx\n"
        "movl %ecx, 0x36e60(%eax)\n"
        "movl 0x1c(%edx), %ecx\n"
        "movl %ecx, 0x36e64(%eax)\n"
        "movl 0x20(%edx), %ecx\n"
        "movl %ecx, 0x36e68(%eax)\n"
        "movl 0x24(%edx), %ecx\n"
        "movl %ecx, 0x36e6c(%eax)\n"
        "movl 0x28(%edx), %ecx\n"
        "movl %ecx, 0x36e70(%eax)\n"
        "movl 0x2c(%edx), %ecx\n"
        "movl %ecx, 0x36e74(%eax)\n"
        "movl 0x30(%edx), %ecx\n"
        "movl %ecx, 0x36e78(%eax)\n"
        "movl 0x34(%edx), %ecx\n"
        "movl %ecx, 0x36e7c(%eax)\n"
        "movl 0x38(%edx), %ecx\n"
        "movl %ecx, 0x36e80(%eax)\n"
        "movl 0x3c(%edx), %edx\n"
        "movl %edx, 0x36e84(%eax)\n"
        "movb $0, 0xf80(%eax)\n" /* line 1270 */
        "movb $0, 0xf81(%eax)\n" /* line 1271 */
        "movb $0, 0xf82(%eax)\n" /* line 1272 */
        "movb $0, 0xf83(%eax)\n" /* line 1273 */
        "popl %ebp\n" /* line 1274 */
        "retl\n"
    );
}

/* line 1369 */
__attribute__((naked))
void RB_SetMatricesForView(const GfxViewParms *viewParms)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1369 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* viewParms */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x195f0c8, %ebx\n" /* line 1360 */
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %ebx), %eax\n"
        "movl 0x48(%esi), %edx\n" /* line 1362 */
        "movl %edx, 0x230(%eax)\n"
        "movl 0x4c(%esi), %edx\n"
        "movl %edx, 0x234(%eax)\n"
        "movl 0x50(%esi), %edx\n"
        "movl %edx, 0x238(%eax)\n"
        "movl 0x54(%esi), %edx\n"
        "movl %edx, 0x23c(%eax)\n"
        "movl 0x58(%esi), %edx\n"
        "movl %edx, 0x240(%eax)\n"
        "movl 0x5c(%esi), %edx\n"
        "movl %edx, 0x244(%eax)\n"
        "movl 0x60(%esi), %edx\n"
        "movl %edx, 0x248(%eax)\n"
        "movl 0x64(%esi), %edx\n"
        "movl %edx, 0x24c(%eax)\n"
        "movl 0x68(%esi), %edx\n"
        "movl %edx, 0x250(%eax)\n"
        "movl 0x6c(%esi), %edx\n"
        "movl %edx, 0x254(%eax)\n"
        "movl 0x70(%esi), %edx\n"
        "movl %edx, 0x258(%eax)\n"
        "movl 0x74(%esi), %edx\n"
        "movl %edx, 0x25c(%eax)\n"
        "movl 0x78(%esi), %edx\n"
        "movl %edx, 0x260(%eax)\n"
        "movl 0x7c(%esi), %edx\n"
        "movl %edx, 0x264(%eax)\n"
        "movl 0x80(%esi), %edx\n"
        "movl %edx, 0x268(%eax)\n"
        "movl 0x84(%esi), %edx\n"
        "movl %edx, 0x26c(%eax)\n"
        "movl 0x88(%esi), %edx\n" /* line 1363 */
        "movl %edx, 0x340(%eax)\n"
        "movl 0x8c(%esi), %edx\n"
        "movl %edx, 0x344(%eax)\n"
        "movl 0x90(%esi), %edx\n"
        "movl %edx, 0x348(%eax)\n"
        "movl 0x94(%esi), %edx\n"
        "movl %edx, 0x34c(%eax)\n"
        "movl 0x98(%esi), %edx\n"
        "movl %edx, 0x350(%eax)\n"
        "movl 0x9c(%esi), %edx\n"
        "movl %edx, 0x354(%eax)\n"
        "movl 0xa0(%esi), %edx\n"
        "movl %edx, 0x358(%eax)\n"
        "movl 0xa4(%esi), %edx\n"
        "movl %edx, 0x35c(%eax)\n"
        "movl 0xa8(%esi), %edx\n"
        "movl %edx, 0x360(%eax)\n"
        "movl 0xac(%esi), %edx\n"
        "movl %edx, 0x364(%eax)\n"
        "movl 0xb0(%esi), %edx\n"
        "movl %edx, 0x368(%eax)\n"
        "movl 0xb4(%esi), %edx\n"
        "movl %edx, 0x36c(%eax)\n"
        "movl 0xb8(%esi), %edx\n"
        "movl %edx, 0x370(%eax)\n"
        "movl 0xbc(%esi), %edx\n"
        "movl %edx, 0x374(%eax)\n"
        "movl 0xc0(%esi), %edx\n"
        "movl %edx, 0x378(%eax)\n"
        "movl 0xc4(%esi), %edx\n"
        "movl %edx, 0x37c(%eax)\n"
        "movl 0xc8(%esi), %edx\n" /* line 1364 */
        "movl %edx, 0x670(%eax)\n"
        "movl 0xcc(%esi), %edx\n"
        "movl %edx, 0x674(%eax)\n"
        "movl 0xd0(%esi), %edx\n"
        "movl %edx, 0x678(%eax)\n"
        "movl 0xd4(%esi), %edx\n"
        "movl %edx, 0x67c(%eax)\n"
        "movl 0xd8(%esi), %edx\n"
        "movl %edx, 0x680(%eax)\n"
        "movl 0xdc(%esi), %edx\n"
        "movl %edx, 0x684(%eax)\n"
        "movl 0xe0(%esi), %edx\n"
        "movl %edx, 0x688(%eax)\n"
        "movl 0xe4(%esi), %edx\n"
        "movl %edx, 0x68c(%eax)\n"
        "movl 0xe8(%esi), %edx\n"
        "movl %edx, 0x690(%eax)\n"
        "movl 0xec(%esi), %edx\n"
        "movl %edx, 0x694(%eax)\n"
        "movl 0xf0(%esi), %edx\n"
        "movl %edx, 0x698(%eax)\n"
        "movl 0xf4(%esi), %edx\n"
        "movl %edx, 0x69c(%eax)\n"
        "movl 0xf8(%esi), %edx\n"
        "movl %edx, 0x6a0(%eax)\n"
        "movl 0xfc(%esi), %edx\n"
        "movl %edx, 0x6a4(%eax)\n"
        "movl 0x100(%esi), %edx\n"
        "movl %edx, 0x6a8(%eax)\n"
        "movl 0x104(%esi), %edx\n"
        "movl %edx, 0x6ac(%eax)\n"
        "movl 0x108(%esi), %edx\n" /* line 1365 */
        "movl %edx, 0x6b0(%eax)\n"
        "movl 0x10c(%esi), %edx\n"
        "movl %edx, 0x6b4(%eax)\n"
        "movl 0x110(%esi), %edx\n"
        "movl %edx, 0x6b8(%eax)\n"
        "movl 0x114(%esi), %edx\n"
        "movl %edx, 0x6bc(%eax)\n"
        "movl 0x118(%esi), %edx\n"
        "movl %edx, 0x6c0(%eax)\n"
        "movl 0x11c(%esi), %edx\n"
        "movl %edx, 0x6c4(%eax)\n"
        "movl 0x120(%esi), %edx\n"
        "movl %edx, 0x6c8(%eax)\n"
        "movl 0x124(%esi), %edx\n"
        "movl %edx, 0x6cc(%eax)\n"
        "movl 0x128(%esi), %edx\n"
        "movl %edx, 0x6d0(%eax)\n"
        "movl 0x12c(%esi), %edx\n"
        "movl %edx, 0x6d4(%eax)\n"
        "movl 0x130(%esi), %edx\n"
        "movl %edx, 0x6d8(%eax)\n"
        "movl 0x134(%esi), %edx\n"
        "movl %edx, 0x6dc(%eax)\n"
        "movl 0x138(%esi), %edx\n"
        "movl %edx, 0x6e0(%eax)\n"
        "movl 0x13c(%esi), %edx\n"
        "movl %edx, 0x6e4(%eax)\n"
        "movl 0x140(%esi), %edx\n"
        "movl %edx, 0x6e8(%eax)\n"
        "movl 0x144(%esi), %edx\n"
        "movl %edx, 0x6ec(%eax)\n"
        /* } scope */
        "movl 0x2e80(%ebx), %edx\n" /* line 1386 */
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %ebx), %eax\n"
        "movb $1, 0x330(%eax)\n" /* line 1388 */
        "movb $0, 0x331(%eax)\n" /* line 1389 */
        "movb $0, 0x332(%eax)\n" /* line 1390 */
        "movb $0, 0x333(%eax)\n" /* line 1391 */
        "movb $1, 0x440(%eax)\n" /* line 1393 */
        "movb $0, 0x441(%eax)\n" /* line 1394 */
        "movb $0, 0x442(%eax)\n" /* line 1395 */
        "movb $0, 0x443(%eax)\n" /* line 1396 */
        "movb $0, 0x550(%eax)\n" /* line 1398 */
        "movb $0, 0x551(%eax)\n" /* line 1399 */
        "movb $0, 0x552(%eax)\n" /* line 1400 */
        "movb $0, 0x553(%eax)\n" /* line 1401 */
        "movb $1, 0x770(%eax)\n" /* line 1403 */
        "movb $1, 0x771(%eax)\n" /* line 1404 */
        "movb $0, 0x772(%eax)\n" /* line 1405 */
        "movb $0, 0x773(%eax)\n" /* line 1406 */
        "movb $0, 0x880(%eax)\n" /* line 1408 */
        "movb $0, 0x881(%eax)\n" /* line 1409 */
        "movb $0, 0x882(%eax)\n" /* line 1410 */
        "movb $0, 0x883(%eax)\n" /* line 1411 */
        "movb $0, 0xdd0(%eax)\n" /* line 1414 */
        "movb $0, 0xdd1(%eax)\n" /* line 1415 */
        "movb $0, 0xdd2(%eax)\n" /* line 1416 */
        "movb $0, 0xdd3(%eax)\n" /* line 1417 */
        "movb $0, 0x990(%eax)\n" /* line 1420 */
        "movb $0, 0x991(%eax)\n" /* line 1421 */
        "movb $0, 0x992(%eax)\n" /* line 1422 */
        "movb $0, 0x993(%eax)\n" /* line 1423 */
        "movl 0x195eec0, %eax\n" /* line 1426 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfcdd2e_000ce12b\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1432 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcdd2e_000ce12b:\n"
        "leal 0x48(%esi), %ebx\n" /* viewParms */
        "movl 0x195f0e0, %edi\n"
        /* { scope 1 */
        ".Lfcdd2e_000ce134:\n"
        "movl 0x195eed0, %edx\n" /* line 1428 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcdd2e_000ce134\n"
        "leal 0x88(%esi), %ebx\n" /* viewParms */
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n" /* viewParms */
        ".Lfcdd2e_000ce16c:\n"
        "movl 8(%edi), %eax\n" /* line 1429 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%esi), %eax\n" /* viewParms */
        "testl %eax, %eax\n"
        "jne .Lfcdd2e_000ce16c\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1432 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1435 */
__attribute__((naked))
void RB_PushMatrixStack(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1435 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195f0c8, %ebx\n" /* line 1439 */
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %ebx, %eax\n"
        "leal 0x12c0(%eax), %edx\n"
        "addl $0x4e0, %eax\n"
        "movl $0xde0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "addl $1, 0x2e80(%ebx)\n" /* line 1440 */
        "addl $0x14, %esp\n" /* line 1441 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1444 */
__attribute__((naked))
void RB_PopMatrixStack(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1444 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x195f0c8, %edi\n" /* line 1448 */
        "subl $1, 0x2e80(%edi)\n"
        "movl 0x195eec0, %eax\n" /* line 1451 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfce1e6_000ce211\n"
        "addl $0x2c, %esp\n" /* line 1458 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfce1e6_000ce211:\n"
        "movl %edi, -0x1c(%ebp)\n"
        "jmp .Lfce1e6_000ce219\n"
        ".Lfce1e6_000ce216:\n"
        "movl -0x1c(%ebp), %edi\n"
        ".Lfce1e6_000ce219:\n"
        "movl 0x195eed0, %eax\n" /* line 1453 */
        "movl 8(%eax), %ebx\n"
        "movl (%ebx), %esi\n"
        "movl 0x2e80(%edi), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4f0(%eax, %edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0xb0(%esi)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce1e6_000ce216\n"
        "movl 0x195f0c8, %edi\n"
        ".Lfce1e6_000ce267:\n"
        "movl 0x195eed0, %eax\n" /* line 1454 */
        "movl 8(%eax), %ebx\n"
        "movl (%ebx), %esi\n"
        "movl 0x2e80(%edi), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x710(%eax, %edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0xb0(%esi)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce1e6_000ce267\n"
        "movl 0x195f0c8, %edi\n"
        ".Lfce1e6_000ce2b5:\n"
        "movl 0x195eed0, %eax\n" /* line 1455 */
        "movl 8(%eax), %ebx\n"
        "movl (%ebx), %esi\n"
        "movl 0x2e80(%edi), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x820(%eax, %edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0xb0(%esi)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce1e6_000ce2b5\n"
        "addl $0x2c, %esp\n" /* line 1458 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1472 */
__attribute__((naked))
void RB_InitSceneViewport(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1472 */
        "movl %esp, %ebp\n"
        "movl 0x195f0c8, %ecx\n" /* line 1474 */
        "movl 0x195eeec, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0x3e8(%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 1475 */
        "movl %eax, 0x3ec(%ecx)\n"
        "popl %ebp\n" /* line 1476 */
        "retl\n"
    );
}

/* line 1480 */
__attribute__((naked))
Bool RB_GetViewport(GfxViewport *outViewport)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1480 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* outViewport */
        "cmpl $1, 0x1186ca4\n" /* line 1487 */
        "je .Lfce328_000ce367\n"
        "movl 0x195f0c8, %edx\n" /* line 1507 */
        "movl 0x3e0(%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 0x3e4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 0x3e8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0x3ec(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl $1, %eax\n" /* line 1511 */
        "popl %ebp\n"
        "retl\n"
        ".Lfce328_000ce367:\n"
        "movl $0, (%ecx)\n" /* line 1489 */
        "movl $0, 4(%ecx)\n" /* line 1490 */
        "movl 0x1186c9c, %eax\n" /* line 1491 */
        "movl %eax, 8(%ecx)\n"
        "movl 0x1186ca0, %eax\n" /* line 1492 */
        "movl %eax, 0xc(%ecx)\n"
        "movl $1, %eax\n" /* line 1511 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1597 */
__attribute__((naked))
void RB_SetDepthRange(float nearValue, float farValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1597 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* nearValue */
        "movss 0xc(%ebp), %xmm1\n" /* farValue */
        "ucomiss 0x1186cc0, %xmm0\n" /* line 1601 */
        "jne .Lfce38c_000ce3b4\n"
        "jp .Lfce38c_000ce3b4\n"
        "ucomiss 0x1186cc4, %xmm1\n"
        "jp .Lfce38c_000ce3b4\n"
        "je .Lfce38c_000ce3ec\n"
        ".Lfce38c_000ce3b4:\n"
        "movss %xmm0, 0x1186cc0\n" /* line 1604 */
        "movss %xmm1, 0x1186cc4\n" /* line 1605 */
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lfce38c_000ce3d0:\n"
        "movl 8(%esi), %eax\n" /* line 1606 */
        "movl (%eax), %edx\n"
        "movl $0x1186cb0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xbc(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce38c_000ce3d0\n"
        ".Lfce38c_000ce3ec:\n"
        "addl $0x10, %esp\n" /* line 1607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1610 */
__attribute__((naked))
void RB_SetViewport(const GfxViewport *viewport)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1610 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* viewport */
        "movl (%edx), %ecx\n" /* line 1619 */
        "cmpl 0x1186cb0, %ecx\n"
        "je .Lfce3f4_000ce456\n"
        ".Lfce3f4_000ce409:\n"
        "movl %ecx, 0x1186cb0\n" /* line 1621 */
        "movl 4(%edx), %eax\n" /* line 1622 */
        "movl %eax, 0x1186cb4\n"
        "movl 8(%edx), %eax\n" /* line 1623 */
        "movl %eax, 0x1186cb8\n"
        "movl 0xc(%edx), %eax\n" /* line 1624 */
        "movl %eax, 0x1186cbc\n"
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lfce3f4_000ce433:\n"
        "movl 8(%esi), %eax\n" /* line 1625 */
        "movl (%eax), %edx\n"
        "movl $0x1186cb0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xbc(%edx)\n"
        "movl (%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfce3f4_000ce433\n"
        ".Lfce3f4_000ce44f:\n"
        "addl $0x10, %esp\n" /* line 1627 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfce3f4_000ce456:\n"
        "movl 4(%edx), %eax\n" /* line 1619 */
        "cmpl 0x1186cb4, %eax\n"
        "jne .Lfce3f4_000ce409\n"
        "movl 8(%edx), %eax\n"
        "cmpl 0x1186cb8, %eax\n"
        "jne .Lfce3f4_000ce409\n"
        "movl 0xc(%edx), %eax\n"
        "cmpl 0x1186cbc, %eax\n"
        "jne .Lfce3f4_000ce409\n"
        "jmp .Lfce3f4_000ce44f\n"
    );
}

/* line 1770 */
__attribute__((naked))
void RB_ReleaseVertexDecl(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1770 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x1186d40, %eax\n" /* line 272 */
        "testl %eax, %eax\n"
        "je .Lfce47c_000ce4c7\n"
        ".Lfce47c_000ce48b:\n"
        "movl 0x195eed0, %eax\n" /* line 275 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x164(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce47c_000ce48b\n"
        "movl $0, 0x1186d44\n" /* line 276 */
        "movl $0, 0x1186d40\n" /* line 277 */
        "leave\n" /* line 1774 */
        "retl\n"
        ".Lfce47c_000ce4c7:\n"
        "movl 0x1186d44, %eax\n" /* line 272 */
        "testl %eax, %eax\n"
        "jne .Lfce47c_000ce48b\n"
        "leave\n" /* line 1774 */
        "retl\n"
    );
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
        "xorl 0x1186c0c, %eax\n"
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
        "movl 0x1186c0c, %eax\n" /* line 658 */
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
        "movl 0x195eed0, %eax\n" /* line 678 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* function */
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl 0x195f0e0, %eax\n"
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
        "movl 0x195f0cc, %eax\n"
        "movl (%eax), %eax\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "mulss 0x2ed854, %xmm0\n" /* 1.52587890625e-05f */
        "movss %xmm0, -0x20(%ebp)\n" /* bias */
        "movl 0x195eed0, %edx\n" /* line 684 */
        "cmpb $0, 0x2d7a(%edx)\n"
        "je .Lfce4d2_000ce7cd\n"
        "movl 0x195f0e4, %eax\n" /* line 686 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n" /* scale */
        "leal -0x1c(%ebp), %edi\n" /* scale */
        "movl 0x195f0e0, %esi\n"
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
        "movl 0x195eed0, %edx\n"
        ".Lfce4d2_000ce5f3:\n"
        "leal -0x20(%ebp), %ebx\n" /* line 691 | bias, function */
        "jmp .Lfce4d2_000ce5fe\n"
        ".Lfce4d2_000ce5f8:\n"
        "movl 0x195eed0, %edx\n"
        ".Lfce4d2_000ce5fe:\n"
        "movl 8(%edx), %edx\n" /* line 693 */
        "movl (%edx), %ecx\n"
        "movl (%ebx), %eax\n" /* function */
        "movl %eax, 8(%esp)\n"
        "movl $0xc3, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl 0x195f0e0, %eax\n"
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
        "movl 0x195eed0, %edx\n" /* line 738 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* function */
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfce4d2_000ce678\n"
        ".Lfce4d2_000ce69f:\n"
        "addl $8, %edi\n"
        "cmpl $0x2f2430, %edi\n" /* line 732 */
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
        "movl 0x195eed0, %edx\n" /* line 751 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* function */
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce4d2_000ce6d5\n"
        ".Lfce4d2_000ce6fc:\n"
        "addl $8, %edi\n"
        "movl $0x2f23d0, %edx\n" /* line 745 */
        "cmpl %edi, %edx\n"
        "jne .Lfce4d2_000ce6b8\n"
        ".Lfce4d2_000ce708:\n"
        "movl 8(%ebp), %eax\n" /* line 756 | stateBits1 */
        "movl %eax, 0x1186c0c\n"
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
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
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
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
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
        "movl 0x1186c0c, %eax\n" /* line 719 */
        "andl $0xfff00000, %eax\n"
        "orl %eax, 8(%ebp)\n" /* stateBits1 */
        "andl $0xfffff, -0x2c(%ebp)\n" /* line 720 | changedBits */
        "jmp .Lfce4d2_000ce64d\n"
        ".Lfce4d2_000ce7b3:\n"
        "testb $0x40, -0x2c(%ebp)\n" /* line 703 | changedBits */
        "jne .Lfce4d2_000ce7db\n"
        ".Lfce4d2_000ce7b9:\n"
        "movl 0x1186c0c, %eax\n" /* line 705 */
        "andl $0xffffff80, %eax\n"
        "orl %eax, 8(%ebp)\n" /* stateBits1 */
        "andl $0x7f, -0x2c(%ebp)\n" /* line 706 | changedBits */
        "jmp .Lfce4d2_000ce639\n"
        ".Lfce4d2_000ce7cd:\n"
        "addss %xmm0, %xmm0\n" /* line 691 */
        "movss %xmm0, -0x20(%ebp)\n" /* bias */
        "jmp .Lfce4d2_000ce5f3\n"
        ".Lfce4d2_000ce7db:\n"
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n" /* function */
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
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n" /* function */
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
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n" /* function */
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
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n" /* function */
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
__attribute__((naked))
void RB_SetSampler(int samplerIndex, int samplerState, GfxImage *image)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 941 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* image */
        "movzbl 0xc(%ebp), %eax\n" /* samplerState */
        "movb %al, -0x38(%ebp)\n" /* samplerState */
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 954 | samplerIndex */
        "cmpl %ebx, 0x1186cf4(, %edx, 4)\n" /* address */
        "je .Lfce8b6_000ce917\n"
        "testl %ebx, %ebx\n" /* line 957 | address */
        "je .Lfce8b6_000ceb57\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n" /* magFilter */
        ".Lfce8b6_000ce8e9:\n"
        "movl 8(%edi), %eax\n" /* line 961 */
        "movl (%eax), %ecx\n"
        "movl 4(%ebx), %edx\n" /* address */
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* samplerIndex */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x104(%ecx)\n"
        "movl (%esi), %eax\n" /* magFilter */
        "testl %eax, %eax\n"
        "jne .Lfce8b6_000ce8e9\n"
        ".Lfce8b6_000ce90b:\n"
        "movl $0x1186cf0, %eax\n" /* line 967 */
        "movl 8(%ebp), %edx\n" /* samplerIndex */
        "movl %ebx, 4(%eax, %edx, 4)\n" /* address */
        ".Lfce8b6_000ce917:\n"
        "testl %ebx, %ebx\n" /* line 970 | address */
        "je .Lfce8b6_000cea4c\n"
        "testb $0xf, -0x38(%ebp)\n" /* line 972 | samplerState */
        "je .Lfce8b6_000cea54\n"
        ".Lfce8b6_000ce929:\n"
        "movl 8(%ebp), %eax\n" /* line 974 | samplerIndex */
        "movzbl 0x1186ce4(%eax), %edx\n"
        "movzbl -0x38(%ebp), %ecx\n" /* line 975 | samplerState */
        "xorb %dl, %cl\n"
        "movb %cl, -0x1d(%ebp)\n" /* diffSamplerState */
        "je .Lfce8b6_000cea4c\n"
        "movzbl %cl, %eax\n" /* line 977 */
        "movl %eax, -0x28(%ebp)\n"
        "testb $3, %al\n"
        "je .Lfce8b6_000ce9f0\n"
        "movzbl -0x38(%ebp), %eax\n" /* line 929 | samplerState */
        "andl $3, %eax\n"
        "movl s_filterTable(, %eax, 4), %ebx\n"
        "cmpl $3, %ebx\n" /* line 932 */
        "je .Lfce8b6_000ceba6\n"
        "movl %ebx, %esi\n"
        ".Lfce8b6_000ce969:\n"
        "movl %edx, %eax\n" /* line 929 */
        "andl $3, %eax\n"
        "movl s_filterTable(, %eax, 4), %edx\n"
        "cmpl $3, %edx\n" /* line 932 */
        "je .Lfce8b6_000ceb8b\n"
        "movl %edx, -0x1c(%ebp)\n" /* magFilterPrev */
        ".Lfce8b6_000ce981:\n"
        "cmpl %ebx, %edx\n" /* line 981 | address */
        "je .Lfce8b6_000ce9b8\n"
        "movl 0x195f0e0, %edi\n"
        ".Lfce8b6_000ce98b:\n"
        "movl 0x195eed0, %edx\n" /* line 982 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n" /* address */
        "movl $6, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* samplerIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%edx)\n"
        "movl (%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfce8b6_000ce98b\n"
        ".Lfce8b6_000ce9b8:\n"
        "cmpl %esi, -0x1c(%ebp)\n" /* line 983 | magFilter, magFilterPrev */
        "je .Lfce8b6_000ce9f0\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %ebx\n" /* address */
        ".Lfce8b6_000ce9c9:\n"
        "movl 8(%edi), %eax\n" /* line 984 */
        "movl (%eax), %edx\n"
        "movl %esi, 0xc(%esp)\n" /* magFilter */
        "movl $5, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* samplerIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%edx)\n"
        "movl (%ebx), %eax\n" /* address */
        "testl %eax, %eax\n"
        "jne .Lfce8b6_000ce9c9\n"
        ".Lfce8b6_000ce9f0:\n"
        "testb $0xc, -0x28(%ebp)\n" /* line 987 */
        "je .Lfce8b6_000cea36\n"
        "movzbl -0x38(%ebp), %eax\n" /* line 989 | samplerState */
        "andl $0xc, %eax\n"
        "movl s_filterTable(%eax), %ebx\n" /* address */
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n" /* magFilter */
        ".Lfce8b6_000cea0f:\n"
        "movl 8(%edi), %eax\n" /* line 991 */
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n" /* address */
        "movl $7, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* samplerIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%edx)\n"
        "movl (%esi), %eax\n" /* magFilter */
        "testl %eax, %eax\n"
        "jne .Lfce8b6_000cea0f\n"
        ".Lfce8b6_000cea36:\n"
        "testb $0x70, -0x28(%ebp)\n" /* line 994 */
        "jne .Lfce8b6_000cea68\n"
        ".Lfce8b6_000cea3c:\n"
        "movl $0x1186ce0, %eax\n" /* line 1013 */
        "movzbl -0x38(%ebp), %edx\n" /* samplerState */
        "movl 8(%ebp), %ecx\n" /* samplerIndex */
        "movb %dl, 4(%ecx, %eax)\n"
        /* } scope */
        ".Lfce8b6_000cea4c:\n"
        "addl $0x3c, %esp\n" /* line 1017 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfce8b6_000cea54:\n"
        "movl 0x195f0c8, %eax\n" /* line 973 */
        "movzbl 0x4be(%eax), %ecx\n"
        "orb %cl, -0x38(%ebp)\n" /* samplerState */
        "jmp .Lfce8b6_000ce929\n"
        ".Lfce8b6_000cea68:\n"
        "movzbl -0x1d(%ebp), %eax\n" /* line 996 | diffSamplerState */
        "movl %eax, -0x24(%ebp)\n"
        "testb $0x10, %al\n"
        "je .Lfce8b6_000ceab8\n"
        "movzbl -0x38(%ebp), %eax\n" /* line 998 | samplerState */
        "andl $0x10, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %ebx, %ebx\n" /* address */
        "andl $0xfffffffe, %ebx\n" /* address */
        "addl $3, %ebx\n" /* address */
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n" /* magFilter */
        ".Lfce8b6_000cea91:\n"
        "movl 8(%edi), %eax\n" /* line 999 */
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n" /* address */
        "movl $1, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* samplerIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%edx)\n"
        "movl (%esi), %eax\n" /* magFilter */
        "testl %eax, %eax\n"
        "jne .Lfce8b6_000cea91\n"
        ".Lfce8b6_000ceab8:\n"
        "testb $0x20, -0x24(%ebp)\n" /* line 1001 */
        "je .Lfce8b6_000ceb03\n"
        "movzbl -0x38(%ebp), %eax\n" /* line 1003 | samplerState */
        "andl $0x20, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %ebx, %ebx\n" /* address */
        "andl $0xfffffffe, %ebx\n" /* address */
        "addl $3, %ebx\n" /* address */
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n" /* magFilter */
        ".Lfce8b6_000ceadc:\n"
        "movl 8(%edi), %eax\n" /* line 1004 */
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n" /* address */
        "movl $2, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* samplerIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%edx)\n"
        "movl (%esi), %eax\n" /* magFilter */
        "testl %eax, %eax\n"
        "jne .Lfce8b6_000ceadc\n"
        ".Lfce8b6_000ceb03:\n"
        "testb $0x40, -0x24(%ebp)\n" /* line 1006 */
        "je .Lfce8b6_000cea3c\n"
        "movzbl -0x38(%ebp), %eax\n" /* line 1008 | samplerState */
        "andl $0x40, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %ebx, %ebx\n" /* address */
        "andl $0xfffffffe, %ebx\n" /* address */
        "addl $3, %ebx\n" /* address */
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n" /* magFilter */
        ".Lfce8b6_000ceb2b:\n"
        "movl 8(%edi), %eax\n" /* line 1009 */
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n" /* address */
        "movl $3, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* samplerIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%edx)\n"
        "movl (%esi), %ecx\n" /* magFilter */
        "testl %ecx, %ecx\n"
        "jne .Lfce8b6_000ceb2b\n"
        "jmp .Lfce8b6_000cea3c\n"
        ".Lfce8b6_000ceb57:\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n" /* magFilter */
        ".Lfce8b6_000ceb63:\n"
        "movl 8(%edi), %eax\n" /* line 965 */
        "movl (%eax), %edx\n"
        "movl $0, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* samplerIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x104(%edx)\n"
        "movl (%esi), %eax\n" /* magFilter */
        "testl %eax, %eax\n"
        "jne .Lfce8b6_000ceb63\n"
        "jmp .Lfce8b6_000ce90b\n"
        ".Lfce8b6_000ceb8b:\n"
        "movl 0x195eed0, %eax\n" /* line 935 */
        "movl 0x2d6c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfce8b6_000cebce\n"
        "movl $2, -0x1c(%ebp)\n" /* magFilterPrev */
        "jmp .Lfce8b6_000ce981\n"
        ".Lfce8b6_000ceba6:\n"
        "movl 0x195eed0, %eax\n"
        "movl 0x2d6c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfce8b6_000cebbf\n"
        "movl $2, %esi\n"
        "jmp .Lfce8b6_000ce969\n"
        ".Lfce8b6_000cebbf:\n"
        "movl $2, %ebx\n"
        "movl $2, %esi\n"
        "jmp .Lfce8b6_000ce969\n"
        ".Lfce8b6_000cebce:\n"
        "movl $2, %edx\n"
        "movl $2, -0x1c(%ebp)\n" /* magFilterPrev */
        "jmp .Lfce8b6_000ce981\n"
    );
}

/* line 1777 */
__attribute__((naked))
void RB_BindDefaultImages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1777 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "xorl %ebx, %ebx\n"
        "movl $dxState, %esi\n"
        "movl 0x195eebc, %edi\n"
        /* { scope 1 */
        ".Lfcebe0_000cebf6:\n"
        "movl 0x1008(%edi), %eax\n" /* line 1783 */
        "movl %eax, 8(%esp)\n"
        "movzbl 0x20e4(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* samplerIndex */
        "calll RB_SetSampler\n"
        "addl $1, %ebx\n" /* line 1782 | samplerIndex */
        "addl $1, %esi\n"
        "cmpl $0x10, %ebx\n" /* samplerIndex */
        "jne .Lfcebe0_000cebf6\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1784 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1030 */
__attribute__((naked))
void RB_UnbindAllImages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1030 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 0x195eed0, %eax\n" /* line 1035 */
        "cmpb $0, 0x2d3c(%eax)\n"
        "jne .Lfcec26_000cec47\n"
        "movl 0x195eeec, %eax\n" /* line 1039 */
        "movl 0x1c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lfcec26_000cec4d\n"
        /* } scope */
        ".Lfcec26_000cec47:\n"
        "addl $0x14, %esp\n" /* line 1041 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcec26_000cec4d:\n"
        "xorl %ebx, %ebx\n" /* line 1039 | samplerIndex */
        ".Lfcec26_000cec4f:\n"
        "movl $0, 8(%esp)\n" /* line 1040 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* samplerIndex */
        "calll RB_SetSampler\n"
        "addl $1, %ebx\n" /* line 1039 | samplerIndex */
        "movl 0x195eeec, %eax\n"
        "cmpl 0x1c(%eax), %ebx\n" /* samplerIndex */
        "jl .Lfcec26_000cec4f\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1041 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1020 */
__attribute__((naked))
void RB_UnbindImage(const GfxImage *image)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1020 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* image */
        /* { scope 1 */
        "movl 0x195eeec, %eax\n" /* line 1024 */
        "movl 0x1c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lfcec7a_000cecaf\n"
        "xorl %esi, %esi\n" /* samplerIndex */
        "movl $dxState, %ebx\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lfcec7a_000cec9c:\n"
        "cmpl %edi, 0x20f4(%ebx)\n" /* line 1025 | image */
        "je .Lfcec7a_000cecb7\n"
        ".Lfcec7a_000ceca4:\n"
        "addl $1, %esi\n" /* line 1024 | samplerIndex */
        "addl $4, %ebx\n"
        "cmpl %esi, 0x1c(%eax)\n" /* samplerIndex */
        "jg .Lfcec7a_000cec9c\n"
        /* } scope */
        ".Lfcec7a_000cecaf:\n"
        "addl $0x2c, %esp\n" /* line 1027 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcec7a_000cecb7:\n"
        "movl $0, 8(%esp)\n" /* line 1026 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* samplerIndex */
        "calll RB_SetSampler\n"
        "movl -0x1c(%ebp), %eax\n"
        "jmp .Lfcec7a_000ceca4\n"
    );
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
        "movl 0x195f0c8, %eax\n" /* line 1524 */
        "movb $0, 0x4bd(%eax)\n"
        "movb $1, 0x4bc(%eax)\n" /* line 1525 */
        "movl 0x1186c9c, %ebx\n" /* line 1529 */
        "cvtsi2ssl %ebx, %xmm2\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm6\n"
        "divss %xmm2, %xmm6\n"
        "movl 0x1186ca0, %esi\n" /* line 1530 */
        "cvtsi2ssl %esi, %xmm1\n"
        "movaps %xmm0, %xmm4\n"
        "divss %xmm1, %xmm4\n"
        "cmpl $1, 0x1186ca4\n" /* line 1487 */
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
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
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
        "movss 0x2ed5d0, %xmm5\n" /* 1.0f */
        /* } scope */
        /* { scope 2 */
        ".Lfcecd4_000cee12:\n"
        "cmpl $1, %esi\n"
        "ja .Lfcecd4_000cef15\n"
        ".Lfcecd4_000cee1b:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
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
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
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
__attribute__((naked))
void RB_InitImages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1787 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "xorl %ebx, %ebx\n"
        "movl $dxState, %esi\n"
        "movl 0x195eebc, %edi\n"
        ".Lfcef96_000cefac:\n"
        "movl 0x1008(%edi), %eax\n" /* line 1783 */
        "movl %eax, 8(%esp)\n"
        "movzbl 0x20e4(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_SetSampler\n"
        "addl $1, %ebx\n" /* line 1782 */
        "addl $1, %esi\n"
        "cmpl $0x10, %ebx\n"
        "jne .Lfcef96_000cefac\n"
        "addl $0x1c, %esp\n" /* line 1790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
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
        "movl 0x1186c98, %eax\n" /* line 1664 */
        "cmpl %esi, %eax\n" /* newTargetId */
        "je .Lfcefdc_000cf20c\n"
        "cmpl $4, %esi\n" /* line 1685 | newTargetId */
        "je .Lfcefdc_000cf19f\n"
        ".Lfcefdc_000ceffe:\n"
        "xorl %edx, %edx\n"
        ".Lfcefdc_000cf000:\n"
        "movl 0x195f0d4, %eax\n"
        "movb %dl, (%eax)\n"
        "movl %esi, 0x1186c98\n" /* line 1687 | newTargetId */
        "movl 0x195eed0, %ebx\n" /* line 1688 */
        "leal (%esi, %esi, 4), %eax\n" /* newTargetId */
        "movl 0x2c30(%ebx, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lfcefdc_000cf05a\n"
        /* { scope 1 */
        "movl 0x195eeec, %eax\n" /* line 1024 */
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
        "movl 0x195eed0, %ebx\n"
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
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %edi\n" /* samplerIndex */
        "testl %edi, %edi\n" /* samplerIndex */
        "jne .Lfcefdc_000cf054\n"
        "movl 0x2c34(%ebx), %eax\n" /* line 1695 */
        "movl %eax, 0x1186ca8\n"
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
        "movl 0x195f0d8, %eax\n"
        "sete (%eax)\n"
        "movl 0x1186c98, %eax\n" /* line 1731 */
        "movl s_viewportBehaviorForRenderTarget(, %eax, 4), %eax\n"
        "movl %eax, 0x1186ca4\n"
        "movl 0x195eed0, %ebx\n" /* line 1732 */
        "leal (%esi, %esi, 4), %eax\n" /* newTargetId */
        "leal (, %eax, 4), %esi\n" /* newTargetId */
        "leal (%esi, %ebx), %edx\n" /* newTargetId */
        "movl 0x2c3c(%edx), %ecx\n"
        "movl %ecx, 0x1186c9c\n"
        "movl 0x2c40(%edx), %eax\n" /* line 1733 */
        "movl %eax, 0x1186ca0\n"
        "movl $0, 0x1186cb0\n" /* line 1738 */
        "movl $0, 0x1186cb4\n" /* line 1739 */
        "movl %ecx, 0x1186cb8\n" /* line 1740 */
        "movl %eax, 0x1186cbc\n" /* line 1741 */
        "movl $0, 0x1186cc0\n" /* line 1742 */
        "movl $0x3f800000, 0x1186cc4\n" /* line 1743 */
        "movl 0x1186cac, %eax\n" /* line 1746 */
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
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcefdc_000cf160\n"
        "movl 0x2c38(%ebx), %eax\n" /* line 1749 */
        "movl %eax, 0x1186cac\n"
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
__attribute__((naked))
void RB_ClearAllStreamSources(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1829 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0x1186cd0, %eax\n" /* line 220 */
        "testl %eax, %eax\n"
        "je .Lfcf232_000cf2b7\n"
        ".Lfcf232_000cf243:\n"
        "movl %eax, 0x1186ce0\n" /* line 1820 */
        "movl $0, 0x1186cd0\n" /* line 1821 */
        "movl $0, 0x1186cd4\n" /* line 1822 */
        "movl $0, 0x1186cd8\n" /* line 1823 */
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lfcf232_000cf272:\n"
        "movl 8(%esi), %eax\n" /* line 1824 */
        "movl (%eax), %edx\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x190(%edx)\n"
        "movl (%ebx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcf232_000cf272\n"
        "movl $0, 0x1186ce0\n" /* line 1825 */
        ".Lfcf232_000cf2b0:\n"
        "addl $0x20, %esp\n" /* line 1835 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcf232_000cf2b7:\n"
        "movl 0x1186cd4, %esi\n" /* line 220 */
        "testl %esi, %esi\n"
        "jne .Lfcf232_000cf243\n"
        "movl 0x1186cd8, %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lfcf232_000cf2b0\n"
        "jmp .Lfcf232_000cf243\n"
    );
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
        "movl 0x1186c08, %eax\n" /* line 470 */
        "xorl %edi, %eax\n" /* stateBits0 */
        "movl %eax, -0x24(%ebp)\n" /* changedBits */
        "jne .Lfcf2d0_000cf2fb\n"
        "movl %edi, %eax\n" /* line 472 | stateBits0 */
        "xorl 0x1186c00, %eax\n"
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
        "movl 0x195eed0, %ebx\n" /* line 509 | disableSeparateAlphaBlend */
        "movl 8(%ebx), %eax\n" /* disableSeparateAlphaBlend */
        "movl (%eax), %edx\n"
        "movl %esi, 8(%esp)\n" /* function */
        "movl $0x19, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfcf2d0_000cf34b\n"
        "movzbl -0x1d(%ebp), %ecx\n" /* line 510 | ref */
        "cmpb %cl, 0x1186d48\n"
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
        "movb %al, 0x1186d48\n"
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
        "testl $0x700, 0x1186c00\n" /* line 540 */
        "sete %al\n"
        "cmpb %al, %bl\n" /* disableSeparateAlphaBlend */
        "je .Lfcf2d0_000cf43c\n"
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf40e:\n"
        "movl 0x195eed0, %ecx\n" /* line 541 */
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
        "movl 0x1186c08, %eax\n" /* line 546 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf47b:\n"
        "movl 0x195eed0, %ecx\n" /* line 561 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf4bc:\n"
        "movl 0x195eed0, %edx\n" /* line 568 */
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
        "testl $0x7000000, 0x1186c00\n" /* line 574 */
        "sete %al\n"
        "cmpb %al, %bl\n" /* disableSeparateAlphaBlend */
        "je .Lfcf2d0_000cf530\n"
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf502:\n"
        "movl 0x195eed0, %ecx\n" /* line 575 */
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
        "movl 0x1186c08, %eax\n" /* line 580 */
        "andl $0x7ff0000, %eax\n"
        "orl %eax, %edi\n" /* stateBits0 */
        "andl $0xf800ffff, -0x24(%ebp)\n" /* line 581 | changedBits */
        ".Lfcf2d0_000cf551:\n"
        "testl $0xff0000, -0x24(%ebp)\n" /* line 589 | changedBits */
        "je .Lfcf2d0_000cf5e6\n"
        "testl $0xf0000, -0x24(%ebp)\n" /* line 591 | changedBits */
        "je .Lfcf2d0_000cf5a2\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "sarl $0x10, %eax\n"
        "andl $0xf, %eax\n"
        "movl s_blendTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf57c:\n"
        "movl 0x195eed0, %ecx\n" /* line 595 */
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
        "testl $0xf00000, -0x24(%ebp)\n" /* line 598 | changedBits */
        "je .Lfcf2d0_000cf5e6\n"
        "movl %edi, %eax\n" /* stateBits0 */
        "sarl $0x14, %eax\n"
        "andl $0xf, %eax\n"
        "movl s_blendTable(, %eax, 4), %ebx\n" /* disableSeparateAlphaBlend */
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf5c0:\n"
        "movl 0x195eed0, %edx\n" /* line 602 */
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
        "movl 0x195eed0, %edx\n" /* line 615 */
        "cmpb $0, 0x2d7e(%edx)\n"
        "je .Lfcf2d0_000cf654\n"
        "movl 0x195f0d0, %eax\n"
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
        "movl 0x195eed0, %edx\n"
        ".Lfcf2d0_000cf62f:\n"
        "movl 8(%edx), %eax\n" /* line 450 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* aaAlphaFormat */
        "movl $0xb5, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf629\n"
        /* } scope */
        ".Lfcf2d0_000cf654:\n"
        "movl %edi, 0x1186c08\n" /* line 622 | stateBits0 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf68c:\n"
        "movl 0x195eed0, %edx\n" /* line 521 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf6cd:\n"
        "movl 0x195eed0, %ecx\n" /* line 526 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf716:\n"
        "movl 0x195eed0, %edx\n" /* line 532 */
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
        "movl 0x195eed0, %esi\n" /* function */
        "movl 0x195f0e0, %ebx\n" /* disableSeparateAlphaBlend */
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
        "movl 0x1186c08, %eax\n" /* line 486 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf7cb:\n"
        "movl 0x195eed0, %edx\n" /* line 552 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf818:\n"
        "movl 0x195eed0, %edx\n" /* line 586 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf851:\n"
        "movl 0x195eed0, %ecx\n" /* line 610 */
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
        "movl 0x195f0e0, %esi\n" /* function */
        ".Lfcf2d0_000cf88a:\n"
        "movl 0x195eed0, %edx\n" /* line 482 */
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
        "movl 0x195eed0, %eax\n" /* line 536 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl $2, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcf2d0_000cf8eb\n"
        "jmp .Lfcf2d0_000cf3ee\n"
    );
}

/* line 1242 */
__attribute__((naked))
void RB_SetProjectionMatrix(const D3DMATRIX *matrix)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1242 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* matrix */
        "movl 0x195f0c8, %ebx\n" /* line 1249 */
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %esi\n"
        "shll $4, %esi\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %esi, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl $0x4e0, %eax\n"
        "movl (%ecx), %edx\n"
        "movl %edx, 0x340(%ebx, %eax)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, 0x344(%ebx, %eax)\n"
        "movl 8(%ecx), %edx\n"
        "movl %edx, 0x348(%ebx, %eax)\n"
        "movl 0xc(%ecx), %edx\n"
        "movl %edx, 0x34c(%ebx, %eax)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, 0x350(%ebx, %eax)\n"
        "movl 0x14(%ecx), %edx\n"
        "movl %edx, 0x354(%ebx, %eax)\n"
        "movl 0x18(%ecx), %edx\n"
        "movl %edx, 0x358(%ebx, %eax)\n"
        "movl 0x1c(%ecx), %edx\n"
        "movl %edx, 0x35c(%ebx, %eax)\n"
        "movl 0x20(%ecx), %edx\n"
        "movl %edx, 0x360(%ebx, %eax)\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %edx, 0x364(%ebx, %eax)\n"
        "movl 0x28(%ecx), %edx\n"
        "movl %edx, 0x368(%ebx, %eax)\n"
        "movl 0x2c(%ecx), %edx\n"
        "movl %edx, 0x36c(%ebx, %eax)\n"
        "movl 0x30(%ecx), %edx\n"
        "movl %edx, 0x370(%ebx, %eax)\n"
        "movl 0x34(%ecx), %edx\n"
        "movl %edx, 0x374(%ebx, %eax)\n"
        "movl 0x38(%ecx), %edx\n"
        "movl %edx, 0x378(%ebx, %eax)\n"
        "movl 0x3c(%ecx), %edx\n"
        "movl %edx, 0x37c(%ebx, %eax)\n"
        "movl 0x2e80(%ebx), %edx\n" /* line 1206 */
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %ebx), %edx\n"
        "movb $1, 0x440(%edx)\n" /* line 1208 */
        "movb $0, 0x441(%edx)\n" /* line 1209 */
        "movb $0, 0x442(%edx)\n" /* line 1210 */
        "movb $0, 0x443(%edx)\n" /* line 1211 */
        "movb $0, 0x770(%edx)\n" /* line 1213 */
        "movb $0, 0x771(%edx)\n" /* line 1214 */
        "movb $0, 0x772(%edx)\n" /* line 1215 */
        "movb $0, 0x773(%edx)\n" /* line 1216 */
        "movb $0, 0x880(%edx)\n" /* line 1218 */
        "movb $0, 0x881(%edx)\n" /* line 1219 */
        "movb $0, 0x882(%edx)\n" /* line 1220 */
        "movb $0, 0x883(%edx)\n" /* line 1221 */
        "movb $0, 0xdd0(%edx)\n" /* line 1224 */
        "movb $0, 0xdd1(%edx)\n" /* line 1225 */
        "movb $0, 0xdd2(%edx)\n" /* line 1226 */
        "movb $0, 0xdd3(%edx)\n" /* line 1227 */
        "movb $0, 0x990(%edx)\n" /* line 1230 */
        "movb $0, 0x991(%edx)\n" /* line 1231 */
        "movb $0, 0x992(%edx)\n" /* line 1232 */
        "movb $0, 0x993(%edx)\n" /* line 1233 */
        "movl 0x195eec0, %eax\n" /* line 1236 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfcf91e_000cfaaa\n"
        "addl $0x1c, %esp\n" /* line 1251 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcf91e_000cfaaa:\n"
        "leal 0x340(%edx), %ebx\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfcf91e_000cfabc:\n"
        "movl 8(%edi), %eax\n" /* line 1237 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcf91e_000cfabc\n"
        "addl $0x1c, %esp\n" /* line 1251 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1630 */
__attribute__((naked))
void RB_UpdateViewport(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1630 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0x195f0c8, %eax\n" /* line 1635 */
        "movb $0, 0x4bc(%eax)\n"
        "cmpl $1, 0x1186ca4\n" /* line 1487 */
        "je .Lfcfae4_000cfb6e\n"
        "movl 0x3ec(%eax), %ebx\n" /* line 1507 */
        "movl 0x3e8(%eax), %edx\n"
        "movl 0x3e0(%eax), %ecx\n"
        "movl 0x3e4(%eax), %eax\n"
        "movb $0, 0x1186cc8\n" /* line 1641 */
        "cmpl %ecx, 0x1186cb0\n" /* line 1619 */
        "je .Lfcfae4_000cfb8d\n"
        ".Lfcfae4_000cfb28:\n"
        "movl %ecx, 0x1186cb0\n" /* line 1621 */
        "movl %eax, 0x1186cb4\n" /* line 1622 */
        "movl %edx, 0x1186cb8\n" /* line 1623 */
        "movl %ebx, 0x1186cbc\n" /* line 1624 */
        "movl 0x195eed0, %esi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lfcfae4_000cfb4b:\n"
        "movl 8(%esi), %eax\n" /* line 1625 */
        "movl (%eax), %edx\n"
        "movl $0x1186cb0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xbc(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcfae4_000cfb4b\n"
        ".Lfcfae4_000cfb67:\n"
        "addl $0x10, %esp\n" /* line 1649 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcfae4_000cfb6e:\n"
        "movl 0x1186c9c, %edx\n" /* line 1491 */
        "movl 0x1186ca0, %ebx\n" /* line 1492 */
        "xorl %ecx, %ecx\n"
        "xorl %eax, %eax\n"
        "movb $0, 0x1186cc8\n" /* line 1641 */
        "cmpl %ecx, 0x1186cb0\n" /* line 1619 */
        "jne .Lfcfae4_000cfb28\n"
        ".Lfcfae4_000cfb8d:\n"
        "cmpl %eax, 0x1186cb4\n"
        "jne .Lfcfae4_000cfb28\n"
        "cmpl 0x1186cb8, %edx\n"
        "jne .Lfcfae4_000cfb28\n"
        "cmpl 0x1186cbc, %ebx\n"
        "jne .Lfcfae4_000cfb28\n"
        "jmp .Lfcfae4_000cfb67\n"
    );
}

/* line 345 */
__attribute__((naked))
void RB_SetInitialState(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 345 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl $0x2170, 8(%esp)\n" /* line 360 */
        "movl $0, 4(%esp)\n"
        "movl $dxState, (%esp)\n"
        "calll memset\n"
        "movl 0x195f0c8, %esi\n" /* line 903 */
        "movl 0x195f0dc, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movzbl defaultSamplerStateTable(%eax), %eax\n"
        "movb %al, 0x4be(%esi)\n"
        "movl 0x195f0c4, %eax\n" /* line 912 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl 0x195eed0, %edx\n"
        "movl %eax, 0x2d6c(%edx)\n"
        "movl 0x2d70(%edx), %ecx\n" /* line 913 */
        "cmpl %ecx, %eax\n"
        "jle .Lfcfba8_000cfc0f\n"
        "movl %ecx, 0x2d6c(%edx)\n" /* line 914 */
        ".Lfcfba8_000cfc0f:\n"
        "cmpl $1, 0x2d6c(%edx)\n" /* line 915 */
        "jle .Lfcfba8_000cfe89\n"
        ".Lfcfba8_000cfc1c:\n"
        "movl 0x2d6c(%edx), %ebx\n" /* line 918 */
        "movl $1, %eax\n" /* line 154 */
        "cmpl %ebx, %eax\n"
        "cmovnsl %eax, %ebx\n"
        "movl 0x195eeec, %eax\n" /* line 919 */
        "movl 0x1c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lfcfba8_000cfc7e\n"
        "xorl %esi, %esi\n"
        "jmp .Lfcfba8_000cfc42\n"
        ".Lfcfba8_000cfc3c:\n"
        "movl 0x195eed0, %edx\n"
        ".Lfcfba8_000cfc42:\n"
        "movl 8(%edx), %eax\n" /* line 920 */
        "movl (%eax), %edx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $0xa, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcfba8_000cfc3c\n"
        "addl $1, %esi\n" /* line 919 */
        "movl 0x195eeec, %eax\n"
        "cmpl %esi, 0x1c(%eax)\n"
        "jg .Lfcfba8_000cfc3c\n"
        "movl 0x195f0c8, %esi\n"
        ".Lfcfba8_000cfc7e:\n"
        "movl $0xe00e0007, 0x1186c0c\n" /* line 270 */
        "movl $0x19128912, 0x1186c08\n" /* line 278 */
        "movl $0xe00e0007, 0x1186c04\n" /* line 270 */
        "movl $0x18128812, 0x1186c00\n" /* line 286 */
        "movl $0, 0x1186c10\n" /* line 367 */
        "movl $0, 0x3e0(%esi)\n" /* line 369 */
        "movl $0, 0x3e4(%esi)\n" /* line 370 */
        "movl (%eax), %edx\n" /* line 371 */
        "movl %edx, 0x3e8(%esi)\n"
        "movl 4(%eax), %eax\n" /* line 372 */
        "movl %eax, 0x3ec(%esi)\n"
        "movl $0, 0x1186cb0\n" /* line 373 */
        "movl $0, 0x1186cb4\n" /* line 374 */
        "movl %edx, 0x1186cb8\n" /* line 375 */
        "movl %eax, 0x1186cbc\n" /* line 376 */
        "movl $0, 0x1186cc0\n" /* line 377 */
        "movl $0x3f800000, %ebx\n" /* line 378 */
        "movl %ebx, 0x1186cc4\n"
        "movl $0xe, 0x1186c98\n" /* line 390 */
        "movl $0, (%esp)\n" /* line 391 */
        "calll RB_SetRenderTarget\n"
        "movb $0, 0x1186cc8\n" /* line 393 */
        "movl %ebx, 0x1186d64\n" /* line 299 */
        "movl %ebx, 0x1186d68\n" /* line 300 */
        "movl $dxState, %eax\n"
        ".Lfcfba8_000cfd37:\n"
        "movl $0, 0x2014(%eax)\n" /* line 304 */
        "movl $0, 0x2034(%eax)\n" /* line 305 */
        "movl $0, 0x2054(%eax)\n" /* line 306 */
        "movl $0, 0x2074(%eax)\n" /* line 307 */
        "addl $4, %eax\n"
        "cmpl $0x1184c20, %eax\n" /* line 302 */
        "jne .Lfcfba8_000cfd37\n"
        "movl 0x195eed0, %ebx\n" /* line 309 */
        "movl 8(%ebx), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0, 8(%esp)\n"
        "movl $0x89, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 312 */
        "movl (%eax), %edx\n"
        "movl $1, 8(%esp)\n"
        "movl $0x93, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl $0x3f800000, %eax\n" /* line 314 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, -0x38(%ebp)\n" /* line 315 */
        "movl %eax, -0x34(%ebp)\n" /* line 316 */
        "movl %eax, -0x30(%ebp)\n" /* line 317 */
        "movl %eax, -0x4c(%ebp)\n" /* line 318 */
        "movl %eax, -0x48(%ebp)\n" /* line 319 */
        "movl %eax, -0x44(%ebp)\n" /* line 320 */
        "movl %eax, -0x40(%ebp)\n" /* line 321 */
        "movl %eax, -0x2c(%ebp)\n" /* line 322 */
        "movl %eax, -0x28(%ebp)\n" /* line 323 */
        "movl %eax, -0x24(%ebp)\n" /* line 324 */
        "movl %eax, -0x20(%ebp)\n" /* line 325 */
        "xorl %eax, %eax\n" /* line 326 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, -0x18(%ebp)\n" /* line 327 */
        "movl %eax, -0x14(%ebp)\n" /* line 328 */
        "movl %eax, -0x10(%ebp)\n" /* line 329 */
        "movl $0x42000000, -0xc(%ebp)\n" /* line 330 */
        "movl 8(%ebx), %edx\n" /* line 331 */
        "movl (%edx), %ecx\n"
        "leal -0x4c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0xc4(%ecx)\n"
        "movb $0, 0x1186c94\n" /* line 333 */
        "movw $0, 0x1186c95\n" /* line 334 */
        "movl $dxState, %eax\n"
        "movl $dxState, %edx\n"
        ".Lfcfba8_000cfe18:\n"
        "movl $0, 0x20f4(%eax)\n" /* line 409 */
        "movb $1, 0x20e4(%edx)\n" /* line 410 */
        "addl $4, %eax\n"
        "addl $1, %edx\n"
        "cmpl $0x1184c40, %eax\n" /* line 407 */
        "jne .Lfcfba8_000cfe18\n"
        "movl $1, 0x1186d34\n" /* line 412 */
        "movl $0xffffffff, 0x1186d4c\n" /* line 418 */
        "movl $__mh_execute_header, 8(%esp)\n" /* line 422 */
        "movl $0xff, 4(%esp)\n"
        "movl $dxState, (%esp)\n"
        "calll memset\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 423 */
        "movl $0xff, 4(%esp)\n"
        "movl $0x1185c00, (%esp)\n"
        "calll memset\n"
        "addl $0x60, %esp\n" /* line 434 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcfba8_000cfe89:\n"
        "movl $0, 0x2d6c(%edx)\n" /* line 916 */
        "jmp .Lfcfba8_000cfc1c\n"
    );
}

/* line 1044 */
__attribute__((naked))
void RB_SetWorldMatrixForEntity(const GfxEntity *re)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1044 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* re */
        "movl 0x38(%esi), %eax\n" /* line 1054 | re */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x14(%esi), %eax\n" /* re */
        "movl %eax, 8(%esp)\n"
        "leal 0x3c(%esi), %eax\n" /* re */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f0c8, %ebx\n"
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4f0(%eax, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixSet44\n"
        /* { scope 1 */
        "movl 0x2e80(%ebx), %edx\n" /* line 1071 */
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %ebx), %edx\n"
        "movl 0x38(%esi), %eax\n" /* line 1072 | re */
        "movl %eax, (%edx)\n"
        "movb $1, 0x110(%edx)\n" /* line 1074 */
        "movb $0, 0x111(%edx)\n" /* line 1075 */
        "movb $0, 0x112(%edx)\n" /* line 1076 */
        "movb $0, 0x113(%edx)\n" /* line 1077 */
        "movb $0, 0x550(%edx)\n" /* line 1079 */
        "movb $0, 0x551(%edx)\n" /* line 1080 */
        "movb $0, 0x552(%edx)\n" /* line 1081 */
        "movb $0, 0x553(%edx)\n" /* line 1082 */
        "movb $0, 0x880(%edx)\n" /* line 1084 */
        "movb $0, 0x881(%edx)\n" /* line 1085 */
        "movb $0, 0x882(%edx)\n" /* line 1086 */
        "movb $0, 0x883(%edx)\n" /* line 1087 */
        "movb $0, 0xdd0(%edx)\n" /* line 1090 */
        "movb $0, 0xdd1(%edx)\n" /* line 1091 */
        "movb $0, 0xdd2(%edx)\n" /* line 1092 */
        "movb $0, 0xdd3(%edx)\n" /* line 1093 */
        "movb $0, 0x220(%edx)\n" /* line 1096 */
        "movb $0, 0x221(%edx)\n" /* line 1097 */
        "movb $0, 0x222(%edx)\n" /* line 1098 */
        "movb $0, 0x223(%edx)\n" /* line 1099 */
        "movb $0, 0x660(%edx)\n" /* line 1101 */
        "movb $0, 0x661(%edx)\n" /* line 1102 */
        "movb $0, 0x662(%edx)\n" /* line 1103 */
        "movb $0, 0x663(%edx)\n" /* line 1104 */
        "movb $0, 0x990(%edx)\n" /* line 1106 */
        "movb $0, 0x991(%edx)\n" /* line 1107 */
        "movb $0, 0x992(%edx)\n" /* line 1108 */
        "movb $0, 0x993(%edx)\n" /* line 1109 */
        "movb $0, 0xaa0(%edx)\n" /* line 1111 */
        "movb $0, 0xaa1(%edx)\n" /* line 1112 */
        "movb $0, 0xaa2(%edx)\n" /* line 1113 */
        "movb $0, 0xaa3(%edx)\n" /* line 1114 */
        "movb $0, 0xbb0(%edx)\n" /* line 1116 */
        "movb $0, 0xbb1(%edx)\n" /* line 1117 */
        "movb $0, 0xbb2(%edx)\n" /* line 1118 */
        "movb $0, 0xbb3(%edx)\n" /* line 1119 */
        "movb $0, 0xcc0(%edx)\n" /* line 1121 */
        "movb $0, 0xcc1(%edx)\n" /* line 1122 */
        "movb $0, 0xcc2(%edx)\n" /* line 1123 */
        "movb $0, 0xcc3(%edx)\n" /* line 1124 */
        "movl 0x195eec0, %eax\n" /* line 1127 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfcfe98_000d0035\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1056 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcfe98_000d0035:\n"
        "leal 0x10(%edx), %ebx\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n" /* re */
        /* { scope 1 */
        ".Lfcfe98_000d0044:\n"
        "movl 8(%edi), %eax\n" /* line 1128 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%esi), %eax\n" /* re */
        "testl %eax, %eax\n"
        "jne .Lfcfe98_000d0044\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1056 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

