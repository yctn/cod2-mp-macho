/* ASM dump from: rb_tess.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_tess.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/rb_state.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/gfx_d3d/r_xsurface.h"
 *   #include "PC/gfx_d3d/r_local.h"
 *   #include "PC/gfx_d3d/r_material.h"
 */

void RB_TessBad(const surfaceType_t *surfType);
void RB_TessParticleCloud(const GfxEntity *re);
void RB_TessXModelRigid(const surfaceType_t *surfType);
static void RB_AddQuadStampDx7(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddQuadStamp(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1);
static void RB_BuildSprite(void);
static void RB_AddLineDx7(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddLine(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1);
void RB_TessEntity(const GfxEntity *re);
void RB_TessBackEndEntity(const surfaceType_t *surfType);
void RB_TessPoly(const surfaceType_t *surfType);
void RB_TessStaticModelCached(const surfaceType_t *surfType);
void RB_TessXModelSkinned(const surfaceType_t *surfType);
void RB_TessTriangles(const surfaceType_t *surfType);

/* line 61 */
__attribute__((naked))
void RB_TessBad(const surfaceType_t *surfType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 61 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 64 */
        "retl\n"
    );
}

/* line 1063 */
__attribute__((naked))
void RB_TessParticleCloud(const GfxEntity *re)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1063 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %edi\n" /* re */
        /* { scope 1: worldUp, scaledWorldUp, viewUp, viewAxis */
        "movl 0x195eec0, %eax\n" /* line 1066 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lffe3ae_000fe51e\n"
        "movl 0x195f160, %eax\n" /* line 261 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lffe3ae_000fe529\n"
        "movl 0x5a7e0(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lffe3ae_000fe529\n"
        ".Lffe3ae_000fe3ef:\n"
        "movl $0, -0x54(%ebp)\n" /* line 1080 */
        "movl $0, -0x50(%ebp)\n" /* line 1081 */
        "movl $0, -0x60(%ebp)\n" /* line 1082 | args */
        "movl $__mh_execute_header, -0x5c(%ebp)\n" /* line 1083 */
        "movl $0x800, -0x58(%ebp)\n" /* line 1084 */
        /* { scope 2: viewAxis */
        "movss 0x64(%edi), %xmm0\n" /* line 1036 */
        "ucomiss 0x68(%edi), %xmm0\n"
        "jp .Lffe3ae_000fe533\n"
        "jne .Lffe3ae_000fe533\n"
        ".Lffe3ae_000fe427:\n"
        "movss %xmm0, -0x4c(%ebp)\n" /* line 30 | viewAxis */
        ".Lffe3ae_000fe42c:\n"
        "xorl %eax, %eax\n" /* line 31 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x68(%edi), %edx\n" /* line 997 | y */
        /* { scope 3 */
        "movl %eax, -0x44(%ebp)\n" /* line 30 */
        "movl %edx, -0x40(%ebp)\n" /* line 31 */
        /* } scope */
        ".Lffe3ae_000fe43a:\n"
        "movl 0x195f0c8, %edx\n" /* line 275 | to */
        "addl $0x310, %edx\n" /* to */
        /* { scope 3 */
        "movl -0x4c(%ebp), %eax\n" /* line 456 | viewAxis */
        "movl %eax, (%edx)\n"
        "movl -0x48(%ebp), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl -0x44(%ebp), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl -0x40(%ebp), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "leal 0x58(%edi), %edx\n" /* line 1058 | from */
        /* { scope 3 */
        "movzbl 1(%edx), %eax\n" /* line 706 */
        "cvtsi2ssl %eax, %xmm4\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm4\n"
        "movzbl 2(%edx), %eax\n" /* line 707 */
        "cvtsi2ssl %eax, %xmm3\n"
        "mulss %xmm1, %xmm3\n"
        "movzbl 3(%edx), %eax\n" /* line 708 */
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        /* } scope */
        "movl 0x195f0c8, %edx\n" /* line 275 | to */
        "addl $0x300, %edx\n" /* to */
        /* { scope 3 */
        "movzbl 0x58(%edi), %eax\n" /* line 456 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss %xmm4, 4(%edx)\n" /* line 457 */
        "movss %xmm3, 8(%edx)\n" /* line 458 */
        "movss %xmm2, 0xc(%edx)\n" /* line 459 */
        /* } scope */
        /* } scope */
        "movl 0x195eed0, %esi\n" /* line 1098 | v1 */
        "movl 0x2dbc(%esi), %eax\n" /* v1, ib */
        /* { scope 2: viewAxis */
        "movl 0x195f138, %ebx\n" /* line 212 */
        "cmpl 0x20cc(%ebx), %eax\n"
        "je .Lffe3ae_000fe4d9\n"
        "movl %eax, (%esp)\n" /* line 213 */
        "calll RB_ChangeIndices\n"
        /* } scope */
        ".Lffe3ae_000fe4d9:\n"
        "movl 0x2db8(%esi), %eax\n" /* line 1099 | v1, vb */
        /* { scope 2: viewAxis */
        "cmpl 0x20d0(%ebx), %eax\n" /* line 220 */
        "je .Lffe3ae_000fe6c0\n"
        ".Lffe3ae_000fe4eb:\n"
        "movl $0x14, 0xc(%esp)\n" /* line 221 */
        "movl $0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll RB_ChangeStreamSource\n"
        /* } scope */
        ".Lffe3ae_000fe50b:\n"
        "leal -0x60(%ebp), %eax\n" /* line 1107 | args */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll RB_DrawTechnique\n"
        /* } scope */
        ".Lffe3ae_000fe51e:\n"
        "addl $0x8c, %esp\n" /* line 1112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: worldUp, scaledWorldUp, viewUp, viewAxis */
        ".Lffe3ae_000fe529:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lffe3ae_000fe3ef\n"
        /* { scope 2: viewAxis */
        ".Lffe3ae_000fe533:\n"
        "leal 0x48(%edi), %esi\n" /* line 1036 | v1 */
        "leal 0x3c(%edi), %ebx\n" /* v0 */
        /* { scope 3 */
        "movl $3, 0xc(%esp)\n" /* line 378 */
        "movl $0x3a83126f, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll VecNCompareCustomEpsilon\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1036 */
        "jne .Lffe3ae_000fe6e0\n"
        "movss 0x48(%edi), %xmm0\n" /* line 248 */
        "subss 0x3c(%edi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* worldUp */
        "movss 4(%esi), %xmm0\n" /* line 249 */
        "subss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%esi), %xmm0\n" /* line 250 */
        "subss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 1046 | worldUp */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss 0x68(%edi), %xmm0\n" /* line 1048 | scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm1\n" /* worldUp */
        "movss %xmm1, -0x30(%ebp)\n" /* scaledWorldUp */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        "movl 0x195f0c8, %eax\n" /* line 975 */
        "movl 0x3c8(%eax), %eax\n"
        "leal 0x48(%eax), %edx\n"
        "movl 8(%edx), %ebx\n" /* line 978 | z */
        "movl 4(%edx), %ecx\n" /* y */
        /* { scope 4 */
        "movl 0x48(%eax), %eax\n" /* line 191 */
        "movl %eax, -0x84(%ebp)\n" /* viewAxis */
        "leal -0x84(%ebp), %esi\n" /* line 192 | viewAxis */
        "movl %ecx, -0x80(%ebp)\n"
        "movl %ebx, -0x7c(%ebp)\n" /* line 193 */
        /* } scope */
        "movl 0x18(%edx), %ebx\n" /* line 979 | z */
        "movl 0x14(%edx), %ecx\n" /* y */
        /* { scope 4 */
        "movl 0x10(%edx), %eax\n" /* line 191 */
        "movl %eax, -0x78(%ebp)\n"
        "movl %ecx, -0x74(%ebp)\n" /* line 192 */
        "movl %ebx, -0x70(%ebp)\n" /* line 193 */
        /* } scope */
        "movl 0x28(%edx), %ebx\n" /* line 980 | z */
        "movl 0x24(%edx), %ecx\n" /* y */
        /* { scope 4 */
        "movl 0x20(%edx), %eax\n" /* line 191 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl %ecx, -0x68(%ebp)\n" /* line 192 */
        "movl %ebx, -0x64(%ebp)\n" /* line 193 */
        /* } scope */
        "leal -0x3c(%ebp), %eax\n" /* line 982 | viewUp */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* scaledWorldUp */
        "movl %eax, (%esp)\n"
        "calll Vec3RotateTranspose\n"
        /* } scope */
        "movss -0x3c(%ebp), %xmm1\n" /* line 994 | viewUp */
        "movss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lffe3ae_000fe6f5\n"
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lffe3ae_000fe6ea\n"
        ".Lffe3ae_000fe647:\n"
        "movss %xmm2, -0x4c(%ebp)\n" /* line 30 | viewAxis */
        "movaps %xmm1, %xmm0\n" /* line 31 */
        "xorps 0x2f2fc0, %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movss %xmm1, -0x44(%ebp)\n" /* line 30 */
        "movss %xmm2, -0x40(%ebp)\n" /* line 31 */
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "movss 0x64(%edi), %xmm1\n" /* line 1015 */
        "movaps %xmm1, %xmm3\n" /* scale */
        "divss %xmm2, %xmm3\n" /* scale */
        /* { scope 3 */
        "movaps %xmm3, %xmm0\n" /* line 86 */
        "mulss -0x4c(%ebp), %xmm0\n" /* viewAxis */
        "movss %xmm0, -0x4c(%ebp)\n" /* viewAxis */
        "movaps %xmm3, %xmm0\n" /* line 87 */
        "mulss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        /* } scope */
        "ucomiss %xmm2, %xmm1\n" /* line 1018 */
        "jbe .Lffe3ae_000fe43a\n"
        "movaps %xmm3, %xmm0\n" /* line 86 */
        "mulss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "mulss -0x40(%ebp), %xmm3\n" /* line 87 */
        "movss %xmm3, -0x40(%ebp)\n"
        "jmp .Lffe3ae_000fe43a\n"
        /* } scope */
        /* { scope 2: viewAxis */
        ".Lffe3ae_000fe6c0:\n"
        "movl 0x20d4(%ebx), %edx\n" /* line 220 */
        "testl %edx, %edx\n"
        "jne .Lffe3ae_000fe4eb\n"
        "cmpl $0x14, 0x20d8(%ebx)\n"
        "jne .Lffe3ae_000fe4eb\n"
        "jmp .Lffe3ae_000fe50b\n"
        ".Lffe3ae_000fe6e0:\n"
        "movss 0x64(%edi), %xmm0\n"
        "jmp .Lffe3ae_000fe427\n"
        /* } scope */
        /* { scope 2: viewAxis */
        ".Lffe3ae_000fe6ea:\n"
        "movl 0x64(%edi), %eax\n" /* line 30 */
        "movl %eax, -0x4c(%ebp)\n" /* viewAxis */
        "jmp .Lffe3ae_000fe42c\n"
        ".Lffe3ae_000fe6f5:\n"
        "movss -0x38(%ebp), %xmm2\n"
        "jmp .Lffe3ae_000fe647\n"
    );
}

/* line 1406 */
__attribute__((naked))
void RB_TessXModelRigid(const surfaceType_t *surfType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1406 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* surfType */
        /* { scope 1 */
        "movl 0x195f160, %eax\n" /* line 261 */
        "movl 0x5a7d0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lffe700_000fe848\n"
        "movl 0x5a7e0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffe700_000fe848\n"
        ".Lffe700_000fe72d:\n"
        "movl 4(%esi), %ebx\n" /* line 1426 | surfType, xsurf */
        "movl $0, -0x1c(%ebp)\n" /* line 1431 */
        "movl $0, -0x20(%ebp)\n" /* line 1432 */
        "movl $0, -0x2c(%ebp)\n" /* line 1433 | args */
        "movswl 2(%ebx), %eax\n" /* line 1434 | xsurf */
        "movl %eax, -0x28(%ebp)\n"
        "movswl 4(%ebx), %eax\n" /* line 1435 | xsurf */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* line 24 */
        "movl 0x195f138, %edi\n" /* line 212 */
        "cmpl 0x20cc(%edi), %eax\n"
        "je .Lffe700_000fe76c\n"
        "movl %eax, (%esp)\n" /* line 213 */
        "calll RB_ChangeIndices\n"
        ".Lffe700_000fe76c:\n"
        "movl 0x10(%ebx), %ecx\n" /* line 38 */
        "movl 0x195eec0, %eax\n" /* line 1067 */
        "movl (%eax), %eax\n"
        "movl $0x24, %edx\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x40, %eax\n"
        "cmovnel %eax, %edx\n"
        /* { scope 2 */
        "cmpl 0x20d0(%edi), %ecx\n" /* line 220 */
        "je .Lffe700_000fe852\n"
        ".Lffe700_000fe793:\n"
        "movl %edx, 0xc(%esp)\n" /* line 221 */
        "movl $0, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll RB_ChangeStreamSource\n"
        /* } scope */
        ".Lffe700_000fe7af:\n"
        "calll RB_PushMatrixStack\n" /* line 1452 */
        "movl 0x195f0c8, %eax\n"
        "movl 0x440(%eax), %ebx\n" /* xsurf */
        /* { scope 2 */
        /* { scope 3 */
        "calll RB_GetActiveWorldMatrix\n" /* line 35 */
        "movl 8(%esi), %edx\n" /* line 37 */
        "movl %edx, (%eax)\n"
        "movl 0xc(%esi), %edx\n" /* line 38 */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%esi), %edx\n" /* line 39 */
        "movl %edx, 8(%eax)\n"
        "xorl %ecx, %ecx\n" /* line 40 */
        "movl %ecx, 0xc(%eax)\n"
        "movl 0x14(%esi), %edx\n" /* line 42 */
        "movl %edx, 0x10(%eax)\n"
        "movl 0x18(%esi), %edx\n" /* line 43 */
        "movl %edx, 0x14(%eax)\n"
        "movl 0x1c(%esi), %edx\n" /* line 44 */
        "movl %edx, 0x18(%eax)\n"
        "movl %ecx, 0x1c(%eax)\n" /* line 45 */
        "movl 0x20(%esi), %edx\n" /* line 47 */
        "movl %edx, 0x20(%eax)\n"
        "movl 0x24(%esi), %edx\n" /* line 48 */
        "movl %edx, 0x24(%eax)\n"
        "movl 0x28(%esi), %edx\n" /* line 49 */
        "movl %edx, 0x28(%eax)\n"
        "movl %ecx, 0x2c(%eax)\n" /* line 50 */
        "movl 0x2c(%esi), %edx\n" /* line 52 */
        "movl %edx, 0x30(%eax)\n"
        "movl 0x30(%esi), %edx\n" /* line 53 */
        "movl %edx, 0x34(%eax)\n"
        "movl 0x34(%esi), %edx\n" /* line 54 */
        "movl %edx, 0x38(%eax)\n"
        "movl $0x3f800000, 0x3c(%eax)\n" /* line 55 */
        "movl 0x38(%ebx), %eax\n" /* line 57 */
        "movl %eax, (%esp)\n"
        "calll RB_ChangedWorldMatrix\n"
        /* } scope */
        /* } scope */
        "leal -0x2c(%ebp), %eax\n" /* line 1454 | args */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll RB_DrawTechnique\n"
        "calll RB_PopMatrixStack\n" /* line 1455 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1462 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffe700_000fe848:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lffe700_000fe72d\n"
        /* { scope 2 */
        ".Lffe700_000fe852:\n"
        "movl 0x20d4(%edi), %eax\n" /* line 220 */
        "testl %eax, %eax\n"
        "jne .Lffe700_000fe793\n"
        "cmpl 0x20d8(%edi), %edx\n"
        "jne .Lffe700_000fe793\n"
        "jmp .Lffe700_000fe7af\n"
    );
}

/* line 205 */
static __attribute__((naked))
void RB_AddQuadStampDx7(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 205 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* origin */
        "movl %edx, -0x24(%ebp)\n"
        "movl %ecx, -0x28(%ebp)\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movss %xmm2, -0x34(%ebp)\n"
        "movss %xmm3, -0x38(%ebp)\n"
        /* { scope 1 */
        "movl 0x195f160, %edx\n" /* line 344 */
        "movl 0x5a7d4(%edx), %eax\n"
        "addl $4, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lffe872_000febcc\n"
        "movl 0x5a7d0(%edx), %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lffe872_000fe929\n"
        "movl 0x195f160, %esi\n"
        ".Lffe872_000fe8c7:\n"
        "movl 0x5a7cc(%esi), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%esi), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lffe872_000fe929\n"
        "movl 0x5a7d0(%esi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lffe872_000febb3\n"
        "movl 0x5a7e0(%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lffe872_000febb3\n"
        "movl 0x195f160, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffe872_000fe935\n"
        ".Lffe872_000fe929:\n"
        "movl 0x195f160, %edx\n"
        "movl 0x195f160, %esi\n"
        ".Lffe872_000fe935:\n"
        "movl 0x5a7d4(%edx), %ebx\n" /* line 216 */
        "movl %ebx, %edx\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 217 */
        "movl 0x5a7b0(%esi), %eax\n"
        "movw %bx, (%eax, %ecx, 2)\n"
        "leal 1(%ebx), %esi\n" /* line 218 */
        "movl 0x195f160, %eax\n"
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movw %si, 2(%eax, %ecx, 2)\n"
        "leal 3(%edx), %ebx\n" /* line 219 */
        "movl 0x195f160, %eax\n"
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movw %bx, 4(%eax, %ecx, 2)\n"
        "movl 0x195f160, %eax\n" /* line 220 */
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movw %bx, 6(%eax, %ecx, 2)\n"
        "movl 0x195f160, %ebx\n" /* line 221 */
        "movl 0x5a7d0(%ebx), %ecx\n"
        "movl 0x5a7b0(%ebx), %eax\n"
        "movw %si, 8(%eax, %ecx, 2)\n"
        "movl %ebx, %esi\n" /* line 222 */
        "movl 0x5a7d0(%ebx), %ebx\n"
        "movl 0x5a7b0(%esi), %ecx\n"
        "leal 2(%edx), %eax\n"
        "movw %ax, 0xa(%ecx, %ebx, 2)\n"
        "movzwl %dx, %edx\n" /* line 224 */
        "leal (%edx, %edx, 8), %edx\n"
        "leal (%esi, %edx, 4), %edx\n"
        "movl -0x24(%ebp), %eax\n" /* line 240 */
        "movss (%eax), %xmm3\n"
        "movl -0x28(%ebp), %ebx\n"
        "movss (%ebx), %xmm5\n"
        "movaps %xmm3, %xmm6\n"
        "addss %xmm5, %xmm6\n"
        "movss 4(%eax), %xmm2\n" /* line 241 */
        "movss 4(%ebx), %xmm4\n"
        "movaps %xmm2, %xmm7\n"
        "addss %xmm4, %xmm7\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss 8(%ebx), %xmm0\n"
        "movss -0x3c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "subss %xmm5, %xmm3\n" /* line 248 */
        "subss %xmm4, %xmm2\n" /* line 249 */
        "movss -0x3c(%ebp), %xmm1\n" /* line 250 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm6, %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n" /* origin */
        "movss %xmm0, (%edx)\n"
        "movaps %xmm7, %xmm0\n" /* line 241 */
        "addss 4(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 4(%edx)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 242 */
        "addss 8(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 8(%edx)\n"
        "leal 0x24(%edx), %eax\n" /* line 228 */
        "movl %eax, -0x20(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 0x24(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x48(%edx), %esi\n" /* line 229 */
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, 0x48(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss %xmm7, %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        "leal 0x6c(%edx), %ebx\n" /* line 230 */
        "addss (%edi), %xmm3\n" /* line 240 | origin */
        "movss %xmm3, 0x6c(%edx)\n"
        "addss 4(%edi), %xmm2\n" /* line 241 | origin */
        "movss %xmm2, 4(%ebx)\n"
        "addss 8(%edi), %xmm1\n" /* line 242 | origin */
        "movss %xmm1, 8(%ebx)\n"
        "movl 0x195f0c8, %eax\n" /* line 232 */
        "movl 0x3c8(%eax), %eax\n"
        "leal 0xc(%eax), %ecx\n" /* from */
        /* { scope 2 */
        "movss 0x2f2fd0, %xmm0\n" /* line 216 */
        "movss 0xc(%eax), %xmm3\n"
        "xorps %xmm0, %xmm3\n"
        "movss 4(%ecx), %xmm2\n" /* line 217 */
        "xorps %xmm0, %xmm2\n"
        "movss 8(%ecx), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        /* } scope */
        "leal 0xc(%edx), %eax\n" /* line 233 | to */
        /* { scope 2 */
        "movss %xmm3, 0xc(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x30(%edx), %eax\n" /* line 234 | to */
        /* { scope 2 */
        "movss %xmm3, 0x30(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x54(%edx), %eax\n" /* line 235 | to */
        /* { scope 2 */
        "movss %xmm3, 0x54(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x78(%edx), %eax\n" /* line 236 | to */
        /* { scope 2 */
        "movss %xmm3, 0x78(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movss -0x2c(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x1c(%edx)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 31 */
        "movss %xmm1, 0x20(%edx)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x40(%edx)\n"
        "movss %xmm1, 0x44(%edx)\n" /* line 31 */
        "movss %xmm0, 0x64(%edx)\n" /* line 30 */
        "movss -0x38(%ebp), %xmm1\n" /* line 31 */
        "movss %xmm1, 0x68(%edx)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x88(%edx)\n"
        "movss %xmm1, 0x8c(%edx)\n" /* line 31 */
        "movl 8(%ebp), %eax\n" /* line 243 | nativeColor */
        "movl %eax, 0x18(%edx)\n"
        "movl -0x20(%ebp), %edx\n" /* line 244 */
        "movl %eax, 0x18(%edx)\n"
        "movl %eax, 0x18(%esi)\n" /* line 245 */
        "movl %eax, 0x18(%ebx)\n" /* line 246 */
        "movl 0x195f160, %ebx\n" /* line 248 */
        "addl $4, 0x5a7d4(%ebx)\n"
        "addl $6, 0x5a7d0(%ebx)\n" /* line 249 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 250 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffe872_000febb3:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl 0x195f160, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffe872_000fe935\n"
        ".Lffe872_000febcc:\n"
        "movl %edx, %esi\n"
        "jmp .Lffe872_000fe8c7\n"
    );
}

/* line 138 */
static __attribute__((naked))
void RB_AddQuadStamp(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* origin */
        "movl %edx, -0x2c(%ebp)\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movss %xmm2, -0x3c(%ebp)\n"
        "movss %xmm3, -0x40(%ebp)\n"
        /* { scope 1 */
        "movl 0x195f160, %edx\n" /* line 344 */
        "movl 0x5a7d4(%edx), %eax\n"
        "addl $4, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lffebd4_000ff026\n"
        "movl 0x5a7d0(%edx), %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lffebd4_000fec91\n"
        "movl 0x195f160, %ecx\n"
        ".Lffebd4_000fec29:\n"
        "movl 0x5a7cc(%ecx), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x195f160, %esi\n" /* line 331 */
        "movl 0x5a7c4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lffebd4_000fec91\n"
        "movl 0x5a7d0(%esi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lffebd4_000ff00d\n"
        "movl 0x5a7e0(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffebd4_000ff00d\n"
        "movl 0x195f160, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffebd4_000fec9d\n"
        ".Lffebd4_000fec91:\n"
        "movl 0x195f160, %edx\n"
        "movl 0x195f160, %esi\n"
        ".Lffebd4_000fec9d:\n"
        "movl 0x5a7d4(%edx), %ebx\n" /* line 151 */
        "movl %ebx, %edx\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 152 */
        "movl 0x5a7b0(%esi), %eax\n"
        "movw %bx, (%eax, %ecx, 2)\n"
        "leal 1(%ebx), %esi\n" /* line 153 */
        "movl 0x195f160, %eax\n"
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movw %si, 2(%eax, %ecx, 2)\n"
        "leal 3(%edx), %ebx\n" /* line 154 */
        "movl 0x195f160, %eax\n"
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movw %bx, 4(%eax, %ecx, 2)\n"
        "movl 0x195f160, %eax\n" /* line 155 */
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movw %bx, 6(%eax, %ecx, 2)\n"
        "movl 0x195f160, %ebx\n" /* line 156 */
        "movl 0x5a7d0(%ebx), %ecx\n"
        "movl 0x5a7b0(%ebx), %eax\n"
        "movw %si, 8(%eax, %ecx, 2)\n"
        "movl %ebx, %esi\n" /* line 157 */
        "movl 0x5a7d0(%ebx), %ebx\n"
        "movl 0x5a7b0(%esi), %ecx\n"
        "leal 2(%edx), %eax\n"
        "movw %ax, 0xa(%ecx, %ebx, 2)\n"
        "movzwl %dx, %edx\n" /* line 159 */
        "shll $6, %edx\n"
        "addl %esi, %edx\n"
        "movl -0x2c(%ebp), %eax\n" /* line 240 */
        "movss (%eax), %xmm3\n"
        "movl -0x30(%ebp), %ecx\n"
        "movss (%ecx), %xmm5\n"
        "movaps %xmm3, %xmm6\n"
        "addss %xmm5, %xmm6\n"
        "movss 4(%eax), %xmm2\n" /* line 241 */
        "movss 4(%ecx), %xmm4\n"
        "movaps %xmm2, %xmm7\n"
        "addss %xmm4, %xmm7\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss 8(%ecx), %xmm0\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "subss %xmm5, %xmm3\n" /* line 248 */
        "subss %xmm4, %xmm2\n" /* line 249 */
        "movss -0x4c(%ebp), %xmm1\n" /* line 250 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm6, %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n" /* origin */
        "movss %xmm0, (%edx)\n"
        "movaps %xmm7, %xmm0\n" /* line 241 */
        "addss 4(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 4(%edx)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 242 */
        "addss 8(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 8(%edx)\n"
        "leal 0x40(%edx), %eax\n" /* line 163 */
        "movl %eax, -0x28(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 0x40(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x80(%edx), %ecx\n" /* line 164 */
        "movl %ecx, -0x24(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, 0x80(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss %xmm7, %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "leal 0xc0(%edx), %ebx\n" /* line 165 */
        "movl %ebx, -0x20(%ebp)\n"
        "addss (%edi), %xmm3\n" /* line 240 | origin */
        "movss %xmm3, 0xc0(%edx)\n"
        "addss 4(%edi), %xmm2\n" /* line 241 | origin */
        "movss %xmm2, 4(%ebx)\n"
        "addss 8(%edi), %xmm1\n" /* line 242 | origin */
        "movss %xmm1, 8(%ebx)\n"
        "movl $0x3f800000, %eax\n" /* line 166 */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x28(%ebp), %esi\n" /* line 167 */
        "movl %eax, 0xc(%esi)\n"
        "movl %eax, 0xc(%ecx)\n" /* line 168 */
        "movl %eax, 0xc(%ebx)\n" /* line 169 */
        "movl 0x195f0c8, %eax\n" /* line 171 */
        "movl 0x3c8(%eax), %eax\n"
        "leal 0xc(%eax), %ecx\n" /* from */
        /* { scope 2 */
        "movss 0x2f2fe0, %xmm0\n" /* line 216 */
        "movss 0xc(%eax), %xmm3\n"
        "xorps %xmm0, %xmm3\n"
        "movss 4(%ecx), %xmm2\n" /* line 217 */
        "xorps %xmm0, %xmm2\n"
        "movss 8(%ecx), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 172 | to */
        /* { scope 2 */
        "movss %xmm3, 0x10(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x50(%edx), %eax\n" /* line 173 | to */
        /* { scope 2 */
        "movss %xmm3, 0x50(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x90(%edx), %eax\n" /* line 174 | to */
        /* { scope 2 */
        "movss %xmm3, 0x90(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xd0(%edx), %eax\n" /* line 175 | to */
        /* { scope 2 */
        "movss %xmm3, 0xd0(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 199 */
        "movl (%eax), %ecx\n"
        "movl 4(%eax), %ebx\n" /* line 200 */
        "movl 8(%eax), %esi\n" /* line 201 */
        "leal 0x28(%edx), %eax\n" /* line 178 | to */
        /* { scope 2 */
        "movl %ecx, 0x28(%edx)\n" /* line 199 */
        "movl %ebx, 4(%eax)\n" /* line 200 */
        "movl %esi, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x68(%edx), %eax\n" /* line 179 | to */
        /* { scope 2 */
        "movl %ecx, 0x68(%edx)\n" /* line 199 */
        "movl %ebx, 4(%eax)\n" /* line 200 */
        "movl %esi, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xa8(%edx), %eax\n" /* line 180 | to */
        /* { scope 2 */
        "movl %ecx, 0xa8(%edx)\n" /* line 199 */
        "movl %ebx, 4(%eax)\n" /* line 200 */
        "movl %esi, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xe8(%edx), %eax\n" /* line 181 | to */
        /* { scope 2 */
        "movl %ecx, 0xe8(%edx)\n" /* line 199 */
        "movl %ebx, 4(%eax)\n" /* line 200 */
        "movl %esi, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl -0x2c(%ebp), %ecx\n" /* line 216 */
        "movss (%ecx), %xmm3\n"
        "xorps %xmm0, %xmm3\n"
        "movss 4(%ecx), %xmm2\n" /* line 217 */
        "xorps %xmm0, %xmm2\n"
        "movss 8(%ecx), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        "leal 0x34(%edx), %eax\n" /* line 184 | to */
        /* { scope 2 */
        "movss %xmm3, 0x34(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x74(%edx), %eax\n" /* line 185 | to */
        /* { scope 2 */
        "movss %xmm3, 0x74(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xb4(%edx), %eax\n" /* line 186 | to */
        /* { scope 2 */
        "movss %xmm3, 0xb4(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xf4(%edx), %eax\n" /* line 187 | to */
        /* { scope 2 */
        "movss %xmm3, 0xf4(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movss -0x34(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x20(%edx)\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 31 */
        "movss %xmm1, 0x24(%edx)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x60(%edx)\n"
        "movss %xmm1, 0x64(%edx)\n" /* line 31 */
        "movss %xmm0, 0xa0(%edx)\n" /* line 30 */
        "movss -0x40(%ebp), %xmm1\n" /* line 31 */
        "movss %xmm1, 0xa4(%edx)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0xe0(%edx)\n"
        "movss %xmm1, 0xe4(%edx)\n" /* line 31 */
        "movl 8(%ebp), %eax\n" /* line 194 | nativeColor */
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x28(%ebp), %edx\n" /* line 195 */
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x24(%ebp), %ecx\n" /* line 196 */
        "movl %eax, 0x1c(%ecx)\n"
        "movl -0x20(%ebp), %ebx\n" /* line 197 */
        "movl %eax, 0x1c(%ebx)\n"
        "movl 0x195f160, %esi\n" /* line 199 */
        "addl $4, 0x5a7d4(%esi)\n"
        "addl $6, 0x5a7d0(%esi)\n" /* line 200 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffebd4_000ff00d:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl 0x195f160, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffebd4_000fec9d\n"
        ".Lffebd4_000ff026:\n"
        "movl %edx, %ecx\n"
        "jmp .Lffebd4_000fec29\n"
    );
}

/* line 299 */
static __attribute__((naked))
void RB_BuildSprite(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 299 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, %ebx\n" /* re */
        "movl %edx, %esi\n" /* worldRadius */
        /* { scope 1 */
        "leal 0x3c(%eax), %eax\n" /* line 317 | from */
        /* { scope 2 */
        "movl 0x3c(%ebx), %edx\n" /* line 199 */
        "movl %edx, -0x28(%ebp)\n" /* worldOrigin */
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0x24(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x20(%ebp)\n"
        /* } scope */
        "testb $0x10, 5(%ebx)\n" /* line 319 | re */
        "jne .Lfff02e_000ff17d\n"
        "leal 4(%esi), %edi\n" /* worldRadius */
        "movss 0x6c(%ebx), %xmm0\n" /* line 322 | re */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lfff02e_000ff19c\n"
        ".Lfff02e_000ff073:\n"
        "jp .Lfff02e_000ff19c\n"
        "movss (%esi), %xmm1\n" /* line 324 | worldRadius, scale */
        "movl 0x195f0c8, %eax\n"
        "movl 0x3c8(%eax), %eax\n"
        "leal 0x18(%eax), %edx\n" /* v */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x18(%eax), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* left */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "mulss 8(%edx), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x2c(%ebp)\n"
        /* } scope */
        "movss (%edi), %xmm1\n" /* line 325 | scale */
        "leal 0x24(%eax), %edx\n" /* v */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* up */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "mulss 8(%edx), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x38(%ebp)\n"
        /* } scope */
        ".Lfff02e_000ff0da:\n"
        "movzbl 0x5b(%ebx), %eax\n" /* line 341 | re */
        "movb %al, -0x1c(%ebp)\n" /* nativeColor */
        "movzbl 0x58(%ebx), %eax\n" /* line 342 | re */
        "movb %al, -0x1b(%ebp)\n"
        "movzbl 0x59(%ebx), %eax\n" /* line 343 | re */
        "movb %al, -0x1a(%ebp)\n"
        "movzbl 0x5a(%ebx), %eax\n" /* line 344 | re */
        "movb %al, -0x19(%ebp)\n"
        /* { scope 2 */
        "movl 0x54(%ebx), %eax\n" /* line 207 */
        "movzbl 0xe(%eax), %ecx\n" /* line 266 */
        "movzbl 0xf(%eax), %edx\n"
        "movl %ecx, %eax\n" /* line 271 */
        "imull %edx, %eax\n"
        "subl $1, %eax\n"
        "je .Lfff02e_000ff2dd\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 283 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 284 */
        "divss %xmm1, %xmm0\n"
        "movl 0x60(%ebx), %eax\n" /* line 286 */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "cvtsi2ssl %edx, %xmm4\n"
        "mulss %xmm2, %xmm4\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 287 */
        "mulss %xmm0, %xmm1\n"
        "addss %xmm4, %xmm2\n" /* line 288 */
        "movaps %xmm0, %xmm3\n" /* line 289 */
        "addss %xmm1, %xmm3\n"
        /* } scope */
        ".Lfff02e_000ff14d:\n"
        "movl 0x195eec0, %eax\n" /* line 352 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfff02e_000ff2be\n"
        "leal -0x40(%ebp), %ecx\n" /* line 358 | up */
        "leal -0x34(%ebp), %edx\n" /* left */
        "leal -0x28(%ebp), %eax\n" /* worldOrigin */
        "movl -0x1c(%ebp), %ebx\n" /* nativeColor, re */
        "movl %ebx, (%esp)\n" /* re */
        "movaps %xmm4, %xmm0\n"
        "calll RB_AddQuadStamp\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 359 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfff02e_000ff17d:\n"
        "leal 4(%esi), %edi\n" /* line 320 | worldRadius */
        "addss 4(%esi), %xmm0\n" /* worldRadius */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0x6c(%ebx), %xmm0\n" /* line 322 | re */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "je .Lfff02e_000ff073\n"
        ".Lfff02e_000ff19c:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 329 */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n" /* angle */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm3\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 486 | angle */
        "movss %xmm0, (%esp)\n"
        "movss %xmm3, -0x68(%ebp)\n"
        "calll cosf\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n" /* line 332 | scale */
        "mulss (%esi), %xmm1\n" /* worldRadius, scale */
        "movl 0x195f0c8, %eax\n"
        "movl 0x3c8(%eax), %eax\n"
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x18(%eax), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* left */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 0x1c(%eax), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "mulss 0x20(%eax), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x2c(%ebp)\n"
        /* } scope */
        "movss -0x68(%ebp), %xmm3\n" /* line 333 */
        "movaps %xmm3, %xmm1\n" /* scale */
        "xorps 0x2f2ff0, %xmm1\n" /* scale */
        "mulss (%esi), %xmm1\n" /* worldRadius, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x24(%eax), %xmm0\n"
        "addss -0x34(%ebp), %xmm0\n" /* left */
        "movss %xmm0, -0x34(%ebp)\n" /* left */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x28(%eax), %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "mulss 0x2c(%eax), %xmm1\n" /* line 290 */
        "addss -0x2c(%ebp), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        /* } scope */
        "mulss (%edi), %xmm2\n" /* line 335 | scale */
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* up */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 0x28(%eax), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "mulss 0x2c(%eax), %xmm2\n" /* line 274 */
        "movss %xmm2, -0x38(%ebp)\n"
        /* } scope */
        "mulss (%edi), %xmm3\n" /* line 336 | scale */
        /* { scope 2 */
        "movaps %xmm3, %xmm0\n" /* line 288 */
        "mulss 0x18(%eax), %xmm0\n"
        "addss -0x40(%ebp), %xmm0\n" /* up */
        "movss %xmm0, -0x40(%ebp)\n" /* up */
        "movaps %xmm3, %xmm0\n" /* line 289 */
        "mulss 0x1c(%eax), %xmm0\n"
        "addss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "mulss 0x20(%eax), %xmm3\n" /* line 290 */
        "addss %xmm2, %xmm3\n"
        "movss %xmm3, -0x38(%ebp)\n"
        "jmp .Lfff02e_000ff0da\n"
        /* } scope */
        ".Lfff02e_000ff2be:\n"
        "leal -0x40(%ebp), %ecx\n" /* line 354 | up */
        "leal -0x34(%ebp), %edx\n" /* left */
        "leal -0x28(%ebp), %eax\n" /* worldOrigin */
        "movl -0x1c(%ebp), %ebx\n" /* nativeColor, re */
        "movl %ebx, (%esp)\n" /* re */
        "movaps %xmm4, %xmm0\n"
        "calll RB_AddQuadStampDx7\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 359 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfff02e_000ff2dd:\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 271 | 1.0f */
        "movaps %xmm2, %xmm3\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm1\n"
        "jmp .Lfff02e_000ff14d\n"
    );
}

/* line 877 */
static __attribute__((naked))
void RB_AddLineDx7(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 877 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %edi\n" /* start */
        "movl %edx, -0x7c(%ebp)\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "movl %ecx, -0x84(%ebp)\n"
        "movss %xmm1, -0x88(%ebp)\n"
        "movss %xmm2, -0x8c(%ebp)\n"
        "movss %xmm3, -0x90(%ebp)\n"
        /* { scope 1 */
        "movl 0x195f0c8, %eax\n" /* line 888 | b */
        "movl 0x3c8(%eax), %eax\n" /* b */
        /* { scope 2 */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* v1 */
        "leal 4(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x74(%ebp)\n"
        "movss 4(%edi), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "leal 8(%edi), %ecx\n" /* line 250 */
        "movl %ecx, -0x70(%ebp)\n"
        "movss 8(%edi), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        "movl -0x7c(%ebp), %esi\n" /* line 248 */
        "movss (%esi), %xmm0\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n" /* v2 */
        "addl $4, %esi\n" /* line 249 */
        "movl %esi, -0x6c(%ebp)\n"
        "movl -0x7c(%ebp), %edx\n"
        "movss 4(%edx), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "addl $8, %edx\n" /* line 250 */
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x7c(%ebp), %ecx\n"
        "movss 8(%ecx), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "leal -0x24(%ebp), %esi\n" /* line 890 | tangent */
        "movl %esi, 8(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* v2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* v1 */
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %esi, (%esp)\n" /* line 891 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm0\n" /* tangent */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 274 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 248 */
        "movss (%eax), %xmm0\n"
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* binormal */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %ebx\n" /* line 895 | binormal, vbase */
        "movl %ebx, (%esp)\n" /* vbase */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 896 | normal */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* vbase */
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "movl 0x195f160, %edx\n" /* line 344 */
        "movl 0x5a7d4(%edx), %eax\n"
        "addl $4, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfff2f4_000ff733\n"
        "movl 0x5a7d0(%edx), %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfff2f4_000ff71e\n"
        "movl 0x195f160, %ecx\n"
        ".Lfff2f4_000ff47c:\n"
        "movl 0x5a7cc(%ecx), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x195f160, %esi\n" /* line 331 */
        "movl 0x5a7c4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lfff2f4_000ff71e\n"
        "movl 0x5a7d0(%esi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfff2f4_000ff729\n"
        "movl 0x5a7e0(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfff2f4_000ff729\n"
        ".Lfff2f4_000ff4d7:\n"
        "movl 0x195f160, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        ".Lfff2f4_000ff4e4:\n"
        "movl 0x5a7d4(%edx), %eax\n" /* line 901 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 241 */
        "movl -0x74(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 242 */
        "movl -0x70(%ebp), %esi\n"
        "addss (%esi), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x24(%eax), %edx\n" /* line 903 */
        "movl %edx, -0x78(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 0x24(%eax)\n"
        "movss (%ecx), %xmm0\n" /* line 249 */
        "subss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movss (%esi), %xmm0\n" /* line 250 */
        "subss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "leal 0x48(%eax), %esi\n" /* line 904 */
        "movss -0x5c(%ebp), %xmm0\n" /* line 240 */
        "movl -0x7c(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 0x48(%eax)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 241 */
        "movl -0x6c(%ebp), %edi\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 242 */
        "movl -0x68(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        "leal 0x6c(%eax), %ebx\n" /* line 905 | vbase */
        "movss (%ecx), %xmm0\n" /* line 248 */
        "subss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 0x6c(%eax)\n"
        "movss (%edi), %xmm0\n" /* line 249 */
        "subss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movss (%edx), %xmm0\n" /* line 250 */
        "subss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "leal 0xc(%eax), %ecx\n" /* line 907 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 199 | normal */
        "movl %edx, 0xc(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%ecx)\n"
        /* } scope */
        "leal 0x30(%eax), %ecx\n" /* line 908 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 199 | normal */
        "movl %edx, 0x30(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%ecx)\n"
        /* } scope */
        "leal 0x54(%eax), %ecx\n" /* line 909 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 199 | normal */
        "movl %edx, 0x54(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%ecx)\n"
        /* } scope */
        "leal 0x78(%eax), %ecx\n" /* line 910 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 199 | normal */
        "movl %edx, 0x78(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%ecx)\n"
        /* } scope */
        "movss -0x88(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x1c(%eax)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, 0x20(%eax)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x40(%eax)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, 0x44(%eax)\n"
        "movss -0x88(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x64(%eax)\n"
        "movss 8(%ebp), %xmm0\n" /* line 31 | t1 */
        "movss %xmm0, 0x68(%eax)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x88(%eax)\n"
        "movss 8(%ebp), %xmm0\n" /* line 31 | t1 */
        "movss %xmm0, 0x8c(%eax)\n"
        "movl -0x84(%ebp), %edx\n" /* line 917 */
        "movl %edx, 0x18(%eax)\n"
        "movl -0x78(%ebp), %ecx\n" /* line 918 */
        "movl %edx, 0x18(%ecx)\n"
        "movl %edx, 0x18(%esi)\n" /* line 919 */
        "movl %edx, 0x18(%ebx)\n" /* line 920 | vbase */
        "movl 0x195f160, %esi\n" /* line 922 */
        "movl 0x5a7d4(%esi), %ecx\n"
        "movl %ecx, %ebx\n" /* vbase */
        "movl 0x5a7d0(%esi), %edx\n" /* line 923 */
        "movl 0x5a7b0(%esi), %eax\n"
        "movw %cx, (%eax, %edx, 2)\n"
        "leal 1(%ecx), %esi\n" /* line 924 */
        "movl 0x195f160, %edi\n" /* start */
        "movl 0x5a7d0(%edi), %edx\n" /* start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %si, 2(%eax, %edx, 2)\n"
        "leal 2(%ecx), %ecx\n" /* line 925 */
        "movl 0x5a7d0(%edi), %edx\n" /* start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 927 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 928 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %si, 8(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 929 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "addl $3, %ebx\n" /* vbase */
        "movw %bx, 0xa(%eax, %edx, 2)\n" /* vbase */
        "addl $4, 0x5a7d4(%edi)\n" /* line 931 | start */
        "addl $6, 0x5a7d0(%edi)\n" /* line 932 | start */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 933 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfff2f4_000ff71e:\n"
        "movl 0x195f160, %edx\n"
        "jmp .Lfff2f4_000ff4e4\n"
        /* { scope 1 */
        ".Lfff2f4_000ff729:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfff2f4_000ff4d7\n"
        ".Lfff2f4_000ff733:\n"
        "movl %edx, %ecx\n"
        "jmp .Lfff2f4_000ff47c\n"
    );
}

/* line 803 */
static __attribute__((naked))
void RB_AddLine(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 803 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %edi\n" /* start */
        "movl %edx, -0x7c(%ebp)\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "movl %ecx, -0x84(%ebp)\n"
        "movss %xmm1, -0x88(%ebp)\n"
        "movss %xmm2, -0x8c(%ebp)\n"
        "movss %xmm3, -0x90(%ebp)\n"
        /* { scope 1 */
        "movl 0x195f0c8, %eax\n" /* line 814 | b */
        "movl 0x3c8(%eax), %eax\n" /* b */
        /* { scope 2 */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* v1 */
        "leal 4(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x74(%ebp)\n"
        "movss 4(%edi), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "leal 8(%edi), %ecx\n" /* line 250 */
        "movl %ecx, -0x70(%ebp)\n"
        "movss 8(%edi), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        "movl -0x7c(%ebp), %esi\n" /* line 248 */
        "movss (%esi), %xmm0\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n" /* v2 */
        "addl $4, %esi\n" /* line 249 */
        "movl %esi, -0x6c(%ebp)\n"
        "movl -0x7c(%ebp), %edx\n"
        "movss 4(%edx), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "addl $8, %edx\n" /* line 250 */
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x7c(%ebp), %ecx\n"
        "movss 8(%ecx), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "leal -0x24(%ebp), %esi\n" /* line 816 | tangent */
        "movl %esi, 8(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* v2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* v1 */
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %esi, (%esp)\n" /* line 817 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm0\n" /* tangent */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 274 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 248 */
        "movss (%eax), %xmm0\n"
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* binormal */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %ebx\n" /* line 821 | binormal, vbase */
        "movl %ebx, (%esp)\n" /* vbase */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 822 | normal */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* vbase */
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "movl 0x195f160, %edx\n" /* line 344 */
        "movl 0x5a7d4(%edx), %eax\n"
        "addl $4, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfff73a_000ffc69\n"
        "movl 0x5a7d0(%edx), %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfff73a_000ffc54\n"
        "movl 0x195f160, %ecx\n"
        ".Lfff73a_000ff8c2:\n"
        "movl 0x5a7cc(%ecx), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x195f160, %esi\n" /* line 331 */
        "movl 0x5a7c4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lfff73a_000ffc54\n"
        "movl 0x5a7d0(%esi), %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lfff73a_000ffc5f\n"
        "movl 0x5a7e0(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfff73a_000ffc5f\n"
        ".Lfff73a_000ff91d:\n"
        "movl 0x195f160, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %ecx\n"
        ".Lfff73a_000ff92a:\n"
        "movl 0x5a7d4(%ecx), %edx\n" /* line 827 */
        "shll $6, %edx\n"
        "addl %ecx, %edx\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 241 */
        "movl -0x74(%ebp), %esi\n"
        "addss (%esi), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 242 */
        "movl -0x70(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "leal 0x40(%edx), %ecx\n" /* line 829 */
        "movl %ecx, -0x78(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 0x40(%edx)\n"
        "movss (%esi), %xmm0\n" /* line 249 */
        "subss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss (%eax), %xmm0\n" /* line 250 */
        "subss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "leal 0x80(%edx), %esi\n" /* line 830 */
        "movss -0x5c(%ebp), %xmm0\n" /* line 240 */
        "movl -0x7c(%ebp), %edi\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, 0x80(%edx)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 241 */
        "movl -0x6c(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 242 */
        "movl -0x68(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        "leal 0xc0(%edx), %ebx\n" /* line 831 | vbase */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc0(%edx)\n"
        "movss (%eax), %xmm0\n" /* line 249 */
        "subss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movss (%ecx), %xmm0\n" /* line 250 */
        "subss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "movl $0x3f800000, %eax\n" /* line 832 */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x78(%ebp), %edi\n" /* line 833 | start */
        "movl %eax, 0xc(%edi)\n" /* start */
        "movl %eax, 0xc(%esi)\n" /* line 834 */
        "movl %eax, 0xc(%ebx)\n" /* line 835 | vbase */
        "leal 0x10(%edx), %ecx\n" /* line 837 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | normal */
        "movl %eax, 0x10(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x50(%edx), %ecx\n" /* line 838 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | normal */
        "movl %eax, 0x50(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x90(%edx), %ecx\n" /* line 839 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | normal */
        "movl %eax, 0x90(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xd0(%edx), %ecx\n" /* line 840 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | normal */
        "movl %eax, 0xd0(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x28(%edx), %ecx\n" /* line 842 | to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | binormal */
        "movl %eax, 0x28(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x68(%edx), %ecx\n" /* line 843 | to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | binormal */
        "movl %eax, 0x68(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xa8(%edx), %ecx\n" /* line 844 | to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | binormal */
        "movl %eax, 0xa8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xe8(%edx), %ecx\n" /* line 845 | to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | binormal */
        "movl %eax, 0xe8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x34(%edx), %ecx\n" /* line 847 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | tangent */
        "movl %eax, 0x34(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x74(%edx), %ecx\n" /* line 848 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | tangent */
        "movl %eax, 0x74(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xb4(%edx), %ecx\n" /* line 849 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | tangent */
        "movl %eax, 0xb4(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xf4(%edx), %ecx\n" /* line 850 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | tangent */
        "movl %eax, 0xf4(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movss -0x88(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x20(%edx)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, 0x24(%edx)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x60(%edx)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, 0x64(%edx)\n"
        "movss -0x88(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0xa0(%edx)\n"
        "movss 8(%ebp), %xmm0\n" /* line 31 | t1 */
        "movss %xmm0, 0xa4(%edx)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0xe0(%edx)\n"
        "movss 8(%ebp), %xmm0\n" /* line 31 | t1 */
        "movss %xmm0, 0xe4(%edx)\n"
        "movl -0x84(%ebp), %eax\n" /* line 857 */
        "movl %eax, 0x1c(%edx)\n"
        "movl %eax, 0x1c(%edi)\n" /* line 858 | start */
        "movl %eax, 0x1c(%esi)\n" /* line 859 */
        "movl %eax, 0x1c(%ebx)\n" /* line 860 | vbase */
        "movl 0x195f160, %edx\n" /* line 862 */
        "movl 0x5a7d4(%edx), %ecx\n"
        "movl %ecx, %ebx\n" /* vbase */
        "movl %edx, %esi\n" /* line 863 */
        "movl 0x5a7d0(%edx), %edx\n"
        "movl 0x5a7b0(%esi), %eax\n"
        "movw %cx, (%eax, %edx, 2)\n"
        "leal 1(%ecx), %esi\n" /* line 864 */
        "movl 0x195f160, %edi\n" /* start */
        "movl 0x5a7d0(%edi), %edx\n" /* start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %si, 2(%eax, %edx, 2)\n"
        "leal 2(%ecx), %ecx\n" /* line 865 */
        "movl 0x5a7d0(%edi), %edx\n" /* start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 867 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 868 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %si, 8(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 869 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "addl $3, %ebx\n" /* vbase */
        "movw %bx, 0xa(%eax, %edx, 2)\n" /* vbase */
        "addl $4, 0x5a7d4(%edi)\n" /* line 871 | start */
        "addl $6, 0x5a7d0(%edi)\n" /* line 872 | start */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 873 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfff73a_000ffc54:\n"
        "movl 0x195f160, %ecx\n"
        "jmp .Lfff73a_000ff92a\n"
        /* { scope 1 */
        ".Lfff73a_000ffc5f:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfff73a_000ff91d\n"
        ".Lfff73a_000ffc69:\n"
        "movl %edx, %ecx\n"
        "jmp .Lfff73a_000ff8c2\n"
    );
}

/* line 1151 */
__attribute__((naked))
void RB_TessEntity(const GfxEntity *re)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1151 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n" /* color */
        "movl 8(%ebp), %edi\n" /* re */
        "movl (%edi), %eax\n" /* line 1157 | re */
        "subl $4, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lfffc70_000ffe08\n"
        "jmpl *0x2f3010(, %eax, 4)\n"
        "testb $0x20, 5(%edi)\n" /* line 514 */
        "jne .Lfffc70_00100586\n"
        /* { scope 1: from, screenOffset, b, a, ... */
        "leal 0x64(%edi), %eax\n" /* line 489 */
        "movl %eax, -0xc8(%ebp)\n" /* from */
        /* { scope 2: worldOffset */
        "movss 0x64(%edi), %xmm3\n" /* line 37 */
        "movss %xmm3, -0x30(%ebp)\n" /* worldRadius */
        "leal 0x68(%edi), %esi\n" /* line 38 */
        "movss 0x68(%edi), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        /* } scope */
        "pxor %xmm4, %xmm4\n" /* line 491 */
        "movss 0x70(%edi), %xmm6\n"
        "ucomiss %xmm4, %xmm6\n"
        "jbe .Lfffc70_000ffdfe\n"
        "leal 0x3c(%edi), %edx\n" /* line 493 */
        /* { scope 2: worldOffset */
        /* { scope 3 */
        "movl 0x195f0c8, %eax\n" /* line 368 */
        "movl 0x3c8(%eax), %ecx\n"
        "leal 0xc8(%ecx), %ebx\n"
        "movss 0x3c(%edi), %xmm2\n" /* line 371 */
        "mulss 0xc(%ebx), %xmm2\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x1c(%ebx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x2c(%ebx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x3c(%ebx), %xmm2\n"
        /* } scope */
        "ucomiss %xmm2, %xmm4\n" /* line 442 */
        "jae .Lfffc70_000ffe08\n"
        "leal 0x18(%ecx), %eax\n" /* line 445 | dir */
        "movaps %xmm3, %xmm0\n" /* scale */
        "xorps 0x2f3000, %xmm0\n" /* scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm5\n" /* line 288 */
        "mulss 0x18(%ecx), %xmm5\n"
        "addss (%ecx), %xmm5\n"
        "movaps %xmm0, %xmm4\n" /* line 289 */
        "mulss 4(%eax), %xmm4\n"
        "addss 4(%ecx), %xmm4\n"
        "movaps %xmm0, %xmm3\n" /* line 290 */
        "mulss 8(%eax), %xmm3\n"
        "addss 8(%ecx), %xmm3\n"
        /* } scope */
        "leal 0x24(%ecx), %eax\n" /* line 446 | dir */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x24(%ecx), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss %xmm1, %xmm3\n"
        "movl %ebx, %eax\n"
        "xorl %edx, %edx\n"
        /* } scope */
        /* { scope 3 */
        ".Lfffc70_000ffd77:\n"
        "movaps %xmm5, %xmm0\n" /* line 384 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0x10(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x20(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss 0x30(%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 383 */
        "addl $4, %eax\n"
        "cmpl $2, %edx\n"
        "jne .Lfffc70_000ffd77\n"
        /* } scope */
        "movss 0x2ed5d0, %xmm0\n" /* line 449 | 1.0f, scale */
        "divss %xmm2, %xmm0\n" /* scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 86 */
        "mulss -0x24(%ebp), %xmm1\n" /* screenOffset */
        "movss %xmm1, -0x24(%ebp)\n" /* screenOffset */
        "mulss -0x20(%ebp), %xmm0\n" /* line 87 */
        "movss %xmm0, -0x20(%ebp)\n"
        /* } scope */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        /* } scope */
        "ucomiss %xmm0, %xmm6\n" /* line 499 */
        "jbe .Lfffc70_000ffdfe\n"
        "divss %xmm0, %xmm6\n" /* line 501 */
        "movaps %xmm6, %xmm0\n"
        /* { scope 2: worldOffset */
        "movaps %xmm6, %xmm1\n" /* line 86 */
        "movl -0xc8(%ebp), %edx\n" /* from */
        "mulss (%edx), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* worldRadius */
        "mulss (%esi), %xmm0\n" /* line 87 */
        "movss %xmm0, -0x2c(%ebp)\n"
        /* } scope */
        ".Lfffc70_000ffdfe:\n"
        "leal -0x30(%ebp), %edx\n" /* line 506 | worldRadius */
        "movl %edi, %eax\n"
        "calll RB_BuildSprite\n"
        /* } scope */
        ".Lfffc70_000ffe08:\n"
        "addl $0x13c, %esp\n" /* line 1190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0x195eec0, %eax\n" /* line 1173 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfffc70_00100996\n"
        /* { scope 1: from, screenOffset, b, a, ... */
        "leal 0x48(%edi), %ebx\n" /* line 604 */
        "movl %ebx, -0x7c(%ebp)\n" /* b */
        "leal 0x3c(%edi), %esi\n"
        "movl %esi, -0x78(%ebp)\n" /* a */
        /* { scope 2: worldOffset */
        "movss 0x3c(%edi), %xmm2\n" /* line 256 */
        "addss 0x48(%edi), %xmm2\n"
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm2\n"
        "leal 0x40(%edi), %eax\n" /* line 257 */
        "movl %eax, -0x74(%ebp)\n"
        "leal 0x4c(%edi), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movss 0x40(%edi), %xmm1\n"
        "addss 0x4c(%edi), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "leal 0x44(%edi), %ecx\n" /* line 258 */
        "movl %ecx, -0x6c(%ebp)\n"
        "leal 0x50(%edi), %ebx\n"
        "movl %ebx, -0x68(%ebp)\n"
        "movss 0x44(%edi), %xmm0\n"
        "addss 0x50(%edi), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        /* } scope */
        "movl 0x195f0c8, %ebx\n" /* line 248 */
        "subss 0x3cc(%ebx), %xmm2\n"
        "movss %xmm2, -0x48(%ebp)\n" /* midpoint */
        "subss 0x3d0(%ebx), %xmm1\n" /* line 249 */
        "movss %xmm1, -0x44(%ebp)\n"
        "subss 0x3d4(%ebx), %xmm0\n" /* line 250 */
        "movss %xmm0, -0x40(%ebp)\n"
        "leal -0x48(%ebp), %eax\n" /* line 606 | midpoint */
        "movl %eax, (%esp)\n"
        "movss %xmm3, -0xf8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm0\n"
        "mulss 0x3d8(%ebx), %xmm0\n" /* line 428 */
        "addss 0x3dc(%ebx), %xmm0\n"
        "mulss 0x2ed890, %xmm0\n" /* -0.0009765625f */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "mulss 0x2ed830, %xmm0\n" /* 32.0f */
        "movss -0xf8(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xd8(%ebp)\n"
        "cvttss2si -0xd8(%ebp), %ecx\n"
        "cmpl $7, %ecx\n" /* line 611 */
        "jg .Lfffc70_00100644\n"
        "movl $0x30, %esi\n"
        "movl $0x10, -0x60(%ebp)\n"
        "movss 0x2ed740, %xmm0\n" /* 8.0f */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movl -0x60(%ebp), %edx\n"
        ".Lfffc70_000fff39:\n"
        "movl 0x195f160, %ebx\n" /* line 344 */
        "movl 0x5a7d4(%ebx), %eax\n"
        "leal 2(%edx, %eax), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfffc70_000fff5e\n"
        "addl 0x5a7d0(%ebx), %esi\n"
        "cmpl $0x100000, %esi\n"
        "jle .Lfffc70_000fffba\n"
        ".Lfffc70_000fff5e:\n"
        "movl 0x5a7cc(%ebx), %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%ebx), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%ebx), %esi\n" /* line 310 */
        "je .Lfffc70_000fffba\n"
        "movl 0x5a7d0(%ebx), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfffc70_00100668\n"
        "movl 0x5a7e0(%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lfffc70_00100668\n"
        ".Lfffc70_000fffaf:\n"
        "movl 0x195f160, %eax\n" /* line 313 */
        "movl %esi, 0x5a7cc(%eax)\n"
        ".Lfffc70_000fffba:\n"
        "movl -0x78(%ebp), %ecx\n" /* line 248 | a */
        "movss (%ecx), %xmm0\n"
        "movl -0x7c(%ebp), %ebx\n" /* b */
        "subss (%ebx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* forward */
        "movl -0x74(%ebp), %esi\n" /* line 249 */
        "movss (%esi), %xmm0\n"
        "movl -0x70(%ebp), %eax\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n" /* line 250 */
        "movss (%edx), %xmm0\n"
        "movl -0x68(%ebp), %ecx\n"
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "leal -0x3c(%ebp), %ebx\n" /* line 620 | forward */
        "movl %ebx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x24(%ebp), %eax\n" /* line 621 | screenOffset */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* worldRadius */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MakeNormalVectors\n"
        "movl 0x195f160, %ebx\n" /* line 623 */
        "movl 0x5a7d4(%ebx), %eax\n"
        "shll $6, %eax\n"
        "addl %ebx, %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* vert */
        "leal 0x58(%edi), %edx\n" /* line 625 | rgbaFrom */
        "movzbl 1(%edx), %ecx\n"
        /* { scope 2: worldOffset */
        "movzbl 0x58(%edi), %eax\n" /* line 655 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, -0xd0(%ebp)\n" /* mtlColor */
        "orl %eax, -0xd0(%ebp)\n" /* mtlColor */
        "movl -0xd0(%ebp), %eax\n" /* line 656 | mtlColor */
        "movb %cl, %ah\n"
        "movl %eax, -0xd0(%ebp)\n" /* mtlColor */
        "movb 2(%edx), %al\n" /* line 657 */
        "movl %eax, -0xd0(%ebp)\n" /* mtlColor */
        "movzbl 3(%edx), %eax\n" /* line 658 */
        "shll $0x18, %eax\n"
        "andl $0xffffff, -0xd0(%ebp)\n" /* mtlColor */
        "orl %eax, -0xd0(%ebp)\n" /* mtlColor */
        /* } scope */
        "movss 0x2ed5d0, %xmm0\n" /* line 627 | 1.0f */
        "divss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n" /* sDelta */
        "cvtss2sd %xmm0, %xmm0\n" /* line 631 */
        "mulsd 0x307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n" /* radians */
        /* { scope 2: worldOffset */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x84(%ebp)\n" /* sinAngleDelta */
        "movss -0x64(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm5\n"
        /* } scope */
        "movl -0x60(%ebp), %ecx\n" /* line 635 */
        "testl %ecx, %ecx\n"
        "jg .Lfffc70_00100672\n"
        "xorl %eax, %eax\n"
        "movl -0x80(%ebp), %edx\n" /* vert */
        "addl $0x40, %edx\n"
        "movl %edx, -0xdc(%ebp)\n"
        ".Lfffc70_001000e6:\n"
        "shll $6, %eax\n" /* line 667 */
        "addl -0x80(%ebp), %eax\n" /* vert */
        "movl -0x80(%ebp), %ecx\n" /* line 456 | vert */
        "movl (%ecx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n" /* line 457 */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ecx), %edx\n" /* line 458 */
        "movl %edx, 8(%eax)\n"
        "movl 0xc(%ecx), %edx\n" /* line 459 */
        "movl %edx, 0xc(%eax)\n"
        "movl $0x3f800000, 0x20(%eax)\n" /* line 668 */
        "movl $0x3f800000, 0x24(%eax)\n" /* line 669 */
        "movl -0xd0(%ebp), %ebx\n" /* line 670 | mtlColor */
        "movl %ebx, 0x1c(%eax)\n"
        "leal 0x40(%eax), %ecx\n" /* line 672 */
        "movl -0x80(%ebp), %esi\n" /* line 456 | vert */
        "movl 0x40(%esi), %edx\n"
        "movl %edx, 0x40(%eax)\n"
        "movl -0xdc(%ebp), %edx\n" /* line 457 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        "movl $0x3f800000, 0x20(%ecx)\n" /* line 673 */
        "movl $0, 0x24(%ecx)\n" /* line 674 */
        "movl %ebx, 0x1c(%ecx)\n" /* line 675 */
        "movl 0x195f160, %ecx\n" /* line 677 */
        "movl 0x5a7d4(%ecx), %ecx\n"
        "addl %ecx, -0x60(%ebp)\n"
        "movl -0x60(%ebp), %eax\n"
        "addl $2, %eax\n"
        "movl 0x195f160, %ebx\n"
        "movl %eax, 0x5a7d4(%ebx)\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        "movb 0x5b(%edi), %bl\n" /* line 1130 | color */
        "movzbl 0x58(%edi), %eax\n" /* line 1131 */
        "movb %al, %bh\n" /* color */
        "movzbl 0x59(%edi), %eax\n" /* line 1132 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %ebx\n" /* color */
        "orl %eax, %ebx\n" /* color */
        "movzbl 0x5a(%edi), %eax\n" /* line 1133 */
        "shll $0x18, %eax\n"
        "andl $0xffffff, %ebx\n" /* color */
        "orl %eax, %ebx\n" /* color */
        /* { scope 2: worldOffset */
        "movl 0x54(%edi), %eax\n" /* line 207 */
        "movzbl 0xe(%eax), %ecx\n" /* line 266 */
        "movzbl 0xf(%eax), %edx\n"
        "movl %ecx, %eax\n" /* line 271 */
        "imull %edx, %eax\n"
        "subl $1, %eax\n"
        "je .Lfffc70_0010097f\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 283 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 284 */
        "divss %xmm1, %xmm0\n"
        "movl 0x60(%edi), %eax\n" /* line 286 */
        "movl %edx, %esi\n"
        "cltd\n"
        "idivl %esi\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "cvtsi2ssl %eax, %xmm4\n" /* line 287 */
        "mulss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm3\n" /* line 288 */
        "addss %xmm1, %xmm3\n"
        "movaps %xmm0, %xmm5\n" /* line 289 */
        "addss %xmm4, %xmm5\n"
        /* } scope */
        ".Lfffc70_001001f8:\n"
        "movl 0x195eec0, %eax\n" /* line 1141 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfffc70_00100960\n"
        "movss 0x64(%edi), %xmm0\n" /* line 1147 */
        "leal 0x48(%edi), %edx\n"
        "leal 0x3c(%edi), %eax\n"
        "movss %xmm5, (%esp)\n"
        "movaps %xmm4, %xmm2\n"
        "movl %ebx, %ecx\n" /* color */
        "calll RB_AddLine\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        "movss 0x64(%edi), %xmm0\n" /* line 535 */
        "movss %xmm0, -0xc4(%ebp)\n" /* scale */
        "movss 0x68(%edi), %xmm0\n" /* line 536 */
        "movss %xmm0, -0xc0(%ebp)\n" /* scale */
        "pxor %xmm0, %xmm0\n" /* line 538 */
        "ucomiss 0x6c(%edi), %xmm0\n"
        "jne .Lfffc70_0010042e\n"
        "jp .Lfffc70_0010042e\n"
        "leal -0x48(%ebp), %esi\n" /* line 540 | midpoint */
        "movl %esi, 8(%esp)\n"
        "leal -0x3c(%ebp), %ebx\n" /* forward */
        "movl %ebx, 4(%esp)\n"
        "leal 0x14(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MakeNormalVectors\n"
        /* { scope 2: worldOffset */
        "movss -0xc4(%ebp), %xmm0\n" /* line 272 | scale */
        "mulss -0x3c(%ebp), %xmm0\n" /* forward */
        "movss %xmm0, -0x3c(%ebp)\n" /* forward */
        "movss -0xc4(%ebp), %xmm0\n" /* line 273 | scale */
        "mulss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 274 | scale */
        "mulss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        /* { scope 2: worldOffset */
        "movss -0xc0(%ebp), %xmm0\n" /* line 272 | scale */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "movss %xmm0, -0x48(%ebp)\n" /* midpoint */
        "movss -0xc0(%ebp), %xmm0\n" /* line 273 | scale */
        "mulss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n" /* line 274 | scale */
        "mulss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        ".Lfffc70_001002db:\n"
        "movzbl 0x5b(%edi), %eax\n" /* line 559 */
        "movb %al, -0x30(%ebp)\n" /* worldRadius */
        "movzbl 0x58(%edi), %eax\n" /* line 560 */
        "movb %al, -0x2f(%ebp)\n"
        "movzbl 0x59(%edi), %eax\n" /* line 561 */
        "movb %al, -0x2e(%ebp)\n"
        "movzbl 0x5a(%edi), %eax\n" /* line 562 */
        "movb %al, -0x2d(%ebp)\n"
        /* { scope 2: worldOffset */
        "movl 0x54(%edi), %eax\n" /* line 207 */
        "movzbl 0xe(%eax), %ecx\n" /* line 266 */
        "movzbl 0xf(%eax), %edx\n"
        "movl %ecx, %eax\n" /* line 271 */
        "imull %edx, %eax\n"
        "subl $1, %eax\n"
        "je .Lfffc70_00100d68\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 283 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 284 */
        "divss %xmm1, %xmm0\n"
        "movl 0x60(%edi), %eax\n" /* line 286 */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "cvtsi2ssl %edx, %xmm4\n"
        "mulss %xmm2, %xmm4\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 287 */
        "mulss %xmm0, %xmm1\n"
        "addss %xmm4, %xmm2\n" /* line 288 */
        "movaps %xmm0, %xmm3\n" /* line 289 */
        "addss %xmm1, %xmm3\n"
        /* } scope */
        ".Lfffc70_0010034e:\n"
        "movl 0x195eec0, %eax\n" /* line 569 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfffc70_00100d4e\n"
        "leal 0x3c(%edi), %eax\n" /* line 575 */
        "movl -0x30(%ebp), %edx\n" /* worldRadius */
        "movl %edx, (%esp)\n"
        "movaps %xmm4, %xmm0\n"
        "movl %esi, %ecx\n"
        "movl %ebx, %edx\n"
        "calll RB_AddQuadStamp\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        "movl %edi, (%esp)\n" /* line 1182 | re */
        "calll RB_TessParticleCloud\n"
        "jmp .Lfffc70_000ffe08\n"
        /* { scope 1: from, screenOffset, b, a, ... */
        "leal 0x3c(%edi), %ebx\n" /* line 945 | from */
        "leal 0x48(%edi), %edx\n" /* line 946 */
        /* { scope 2: worldOffset */
        "movss 0x48(%edi), %xmm0\n" /* line 248 */
        "subss 0x3c(%edi), %xmm0\n"
        "movss 4(%edx), %xmm1\n" /* line 249 */
        "subss 4(%ebx), %xmm1\n"
        "movss 8(%edx), %xmm2\n" /* line 250 */
        "subss 8(%ebx), %xmm2\n"
        /* } scope */
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "movb 0x5b(%edi), %cl\n" /* line 951 */
        "movzbl 0x58(%edi), %eax\n" /* line 952 */
        "movb %al, %ch\n"
        "movzbl 0x59(%edi), %eax\n" /* line 953 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %ecx\n"
        "orl %eax, %ecx\n"
        "movzbl 0x5a(%edi), %eax\n" /* line 954 */
        "shll $0x18, %eax\n"
        "andl $0xffffff, %ecx\n"
        "orl %eax, %ecx\n"
        "movl 0x195eec0, %eax\n" /* line 960 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfffc70_00100d1a\n"
        "movl 0x195f23c, %eax\n" /* line 966 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c4, %xmm1\n" /* 0.00390625f */
        "movss %xmm1, (%esp)\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "movl %ebx, %eax\n" /* b */
        "calll RB_AddLine\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_0010042e:\n"
        "leal -0x48(%ebp), %esi\n" /* line 546 | midpoint */
        "movl %esi, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* screenOffset */
        "movl %eax, 4(%esp)\n"
        "leal 0x14(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MakeNormalVectors\n"
        "cvtss2sd 0x6c(%edi), %xmm0\n" /* line 548 */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n" /* radians */
        /* { scope 2: worldOffset */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm3\n"
        "movss -0xbc(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "movss %xmm3, -0xf8(%ebp)\n"
        "calll cosf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm2\n"
        /* } scope */
        "movss -0xc4(%ebp), %xmm0\n" /* line 551 | scale */
        "mulss %xmm2, %xmm0\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm1\n" /* screenOffset */
        "movss %xmm1, -0x3c(%ebp)\n" /* forward */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        "movss -0xf8(%ebp), %xmm3\n" /* line 552 */
        "movaps %xmm3, %xmm1\n" /* scale */
        "xorps 0x2f3000, %xmm1\n" /* scale */
        "mulss -0xc4(%ebp), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "addss -0x3c(%ebp), %xmm0\n" /* forward */
        "movss %xmm0, -0x3c(%ebp)\n" /* forward */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss -0x34(%ebp), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        /* } scope */
        "mulss -0xc0(%ebp), %xmm2\n" /* line 554 | scale */
        /* { scope 2: worldOffset */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "movss %xmm0, -0x48(%ebp)\n" /* midpoint */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "mulss -0x40(%ebp), %xmm2\n" /* line 274 */
        /* } scope */
        "mulss -0xc0(%ebp), %xmm3\n" /* line 555 | scale */
        /* { scope 2: worldOffset */
        "movaps %xmm3, %xmm0\n" /* line 288 */
        "mulss -0x24(%ebp), %xmm0\n" /* screenOffset */
        "addss -0x48(%ebp), %xmm0\n" /* midpoint */
        "movss %xmm0, -0x48(%ebp)\n" /* midpoint */
        "movaps %xmm3, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm3\n" /* line 290 */
        "addss %xmm2, %xmm3\n"
        "movss %xmm3, -0x40(%ebp)\n"
        "leal -0x3c(%ebp), %ebx\n" /* forward */
        "jmp .Lfffc70_001002db\n"
        /* } scope */
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100586:\n"
        "movss 0x68(%edi), %xmm1\n" /* line 468 | screenHeight */
        "leal 0x3c(%edi), %edx\n"
        /* { scope 2: worldOffset */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        "movl 0x195f0c8, %eax\n" /* line 368 */
        "movl 0x3c8(%eax), %ecx\n"
        "leal 0xc8(%ecx), %eax\n"
        "movss 0x3c(%edi), %xmm2\n" /* line 371 */
        "mulss 0xc(%eax), %xmm2\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x1c(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x2c(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x3c(%eax), %xmm2\n"
        /* } scope */
        /* } scope */
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 406 | 0.0f */
        "jp .Lfffc70_001005d9\n"
        "jbe .Lfffc70_000ffe08\n"
        ".Lfffc70_001005d9:\n"
        "addss %xmm1, %xmm1\n" /* line 410 */
        "leal 0x108(%ecx), %eax\n"
        "xorl %edx, %edx\n"
        ".Lfffc70_001005e5:\n"
        "movaps %xmm1, %xmm0\n" /* line 415 */
        "mulss 0x10(%eax), %xmm0\n"
        "movss %xmm0, -0x30(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 414 */
        "addl $4, %eax\n"
        "cmpl $3, %edx\n"
        "jne .Lfffc70_001005e5\n"
        "leal 0x24(%ecx), %eax\n" /* line 417 */
        "movss -0x30(%ebp), %xmm1\n" /* line 418 | worldRadius */
        "mulss 0x24(%ecx), %xmm1\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        /* } scope */
        /* } scope */
        "movss %xmm1, -0x24(%ebp)\n" /* line 472 | screenOffset */
        "leal -0x24(%ebp), %edx\n" /* line 474 | screenOffset */
        "movl %edi, %eax\n"
        "calll RB_BuildSprite\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100644:\n"
        "cmpl $0x20, %ecx\n" /* line 613 */
        "jle .Lfffc70_00100d7f\n"
        "movl $0xc0, %esi\n"
        "movl $0x40, -0x60(%ebp)\n"
        "movl $0x42000000, -0x5c(%ebp)\n"
        "movl -0x60(%ebp), %edx\n"
        "jmp .Lfffc70_000fff39\n"
        ".Lfffc70_00100668:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfffc70_000fffaf\n"
        ".Lfffc70_00100672:\n"
        "movl -0x80(%ebp), %esi\n" /* line 642 | vert */
        "movl %esi, %ecx\n" /* line 1151 */
        "addl $0x40, %ecx\n"
        "movl %ecx, -0xdc(%ebp)\n"
        "movl %esi, %ebx\n" /* color */
        "addl $0x60, %ebx\n" /* color */
        "movl %ebx, -0x4c(%ebp)\n" /* color */
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm4\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movl $0, -0x88(%ebp)\n" /* segmentX2 */
        "jmp .Lfffc70_001006a6\n"
        ".Lfffc70_001006a3:\n"
        "movaps %xmm1, %xmm2\n" /* line 635 */
        ".Lfffc70_001006a6:\n"
        "movaps %xmm2, %xmm1\n" /* line 637 | scale */
        "mulss 0x68(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x30(%ebp), %xmm0\n" /* worldRadius */
        "movl -0x78(%ebp), %eax\n" /* a */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movl -0x74(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "mulss -0x28(%ebp), %xmm1\n" /* line 290 */
        "movl -0x6c(%ebp), %ecx\n"
        "addss (%ecx), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 638 | scale */
        "mulss 0x68(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x24(%ebp), %xmm0\n" /* screenOffset */
        "addss (%esi), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%esi), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movl $0x3f800000, 0xc(%esi)\n" /* line 639 */
        "movss %xmm4, 0x20(%esi)\n" /* line 640 */
        "movl $0x3f800000, 0x24(%esi)\n" /* line 641 */
        "movl -0xd0(%ebp), %ebx\n" /* line 642 | mtlColor */
        "movl %ebx, 0x1c(%esi)\n"
        "movl -0x88(%ebp), %edx\n" /* line 644 | segmentX2 */
        "shll $6, %edx\n"
        "movl -0x80(%ebp), %eax\n" /* vert */
        "addl %edx, %eax\n"
        "leal 0x40(%eax), %ecx\n" /* result */
        "movaps %xmm2, %xmm1\n" /* scale */
        "mulss 0x64(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x30(%ebp), %xmm0\n" /* worldRadius */
        "movl -0x7c(%ebp), %ebx\n" /* b */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, 0x40(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movl -0x70(%ebp), %ebx\n"
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, 0x44(%eax)\n"
        "mulss -0x28(%ebp), %xmm1\n" /* line 290 */
        "movl -0x68(%ebp), %ebx\n"
        "addss (%ebx), %xmm1\n"
        "movss %xmm1, 0x48(%eax)\n"
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 645 | scale */
        "mulss 0x64(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x24(%ebp), %xmm0\n" /* screenOffset */
        "addss 0x40(%eax), %xmm0\n"
        "movss %xmm0, 0x40(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, 0x44(%eax)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x48(%eax)\n"
        /* } scope */
        "addl -0xdc(%ebp), %edx\n" /* line 646 */
        "movl $0x3f800000, 0xc(%edx)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 647 */
        "movss %xmm4, (%eax)\n"
        "movl $0, 4(%eax)\n" /* line 648 */
        "movl -0xd0(%ebp), %ecx\n" /* line 649 | mtlColor */
        "movl %ecx, 0x1c(%edx)\n"
        "addss -0x8c(%ebp), %xmm4\n" /* line 651 | sDelta */
        "movaps %xmm2, %xmm1\n" /* line 652 */
        "mulss %xmm5, %xmm1\n"
        "movss -0x84(%ebp), %xmm0\n" /* sinAngleDelta */
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm3\n" /* line 653 */
        "mulss -0x84(%ebp), %xmm2\n" /* sinAngleDelta */
        "subss %xmm2, %xmm3\n"
        "movl -0x88(%ebp), %ecx\n" /* segmentX2 */
        "movl 0x195f160, %eax\n" /* line 656 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x120(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl -0x120(%ebp), %eax\n"
        "movw %dx, (%eax, %ebx, 2)\n"
        "movl 0x195f160, %edx\n" /* line 657 */
        "movl 0x5a7d0(%edx), %ebx\n"
        "movl 0x5a7b0(%edx), %eax\n"
        "movl %eax, -0x124(%ebp)\n"
        "movzwl 0x5a7d4(%edx), %eax\n"
        "addl %ecx, %eax\n"
        "movw %ax, -0xfe(%ebp)\n"
        "addl $1, %eax\n"
        "movl -0x124(%ebp), %edx\n"
        "movw %ax, 2(%edx, %ebx, 2)\n"
        "movl 0x195f160, %eax\n" /* line 658 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x128(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $3, %eax\n"
        "movl -0x128(%ebp), %edx\n"
        "movw %ax, 4(%edx, %ebx, 2)\n"
        "movl 0x195f160, %eax\n" /* line 659 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "addl $3, %ebx\n"
        "movl %ebx, 0x5a7d0(%eax)\n"
        "movl 0x5a7b0(%eax), %edx\n" /* line 661 */
        "movl %edx, -0x12c(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $3, %eax\n"
        "movl -0x12c(%ebp), %edx\n"
        "movw %ax, (%edx, %ebx, 2)\n"
        "movl 0x195f160, %eax\n" /* line 662 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x130(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $2, %eax\n"
        "movl -0x130(%ebp), %edx\n"
        "movw %ax, 2(%edx, %ebx, 2)\n"
        "movl 0x195f160, %ebx\n" /* line 663 */
        "movl 0x5a7d0(%ebx), %edx\n"
        "movl 0x5a7b0(%ebx), %eax\n"
        "addw 0x5a7d4(%ebx), %cx\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "addl $3, 0x5a7d0(%ebx)\n" /* line 664 */
        "addl $2, -0x88(%ebp)\n" /* line 635 | segmentX2 */
        "subl $-0x80, %esi\n"
        "subl $-0x80, -0x4c(%ebp)\n"
        "movl -0x88(%ebp), %eax\n" /* segmentX2 */
        "cmpl %eax, -0x60(%ebp)\n"
        "jg .Lfffc70_001006a3\n"
        "jmp .Lfffc70_001000e6\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100960:\n"
        "movss 0x64(%edi), %xmm0\n" /* line 1143 */
        "leal 0x48(%edi), %edx\n"
        "leal 0x3c(%edi), %eax\n"
        "movss %xmm5, (%esp)\n"
        "movaps %xmm4, %xmm2\n"
        "movl %ebx, %ecx\n" /* color */
        "calll RB_AddLineDx7\n"
        "jmp .Lfffc70_000ffe08\n"
        /* { scope 2: worldOffset */
        ".Lfffc70_0010097f:\n"
        "movss 0x2ed5d0, %xmm3\n" /* line 271 | 1.0f */
        "movaps %xmm3, %xmm5\n"
        "pxor %xmm1, %xmm1\n"
        "movaps %xmm1, %xmm4\n"
        "jmp .Lfffc70_001001f8\n"
        /* } scope */
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100996:\n"
        "leal 0x48(%edi), %eax\n" /* line 702 */
        "movl %eax, -0xa8(%ebp)\n" /* b */
        "leal 0x3c(%edi), %edx\n"
        "movl %edx, -0xa4(%ebp)\n" /* a */
        /* { scope 2: worldOffset */
        "movss 0x3c(%edi), %xmm2\n" /* line 256 */
        "addss 0x48(%edi), %xmm2\n"
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm2\n"
        "leal 0x40(%edi), %ecx\n" /* line 257 */
        "movl %ecx, -0xa0(%ebp)\n"
        "leal 0x4c(%edi), %ebx\n"
        "movl %ebx, -0x9c(%ebp)\n"
        "movss 0x40(%edi), %xmm1\n"
        "addss 0x4c(%edi), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "leal 0x44(%edi), %esi\n" /* line 258 */
        "movl %esi, -0x98(%ebp)\n"
        "leal 0x50(%edi), %eax\n"
        "movl %eax, -0x94(%ebp)\n"
        "movss 0x44(%edi), %xmm0\n"
        "addss 0x50(%edi), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        /* } scope */
        "movl 0x195f0c8, %ebx\n" /* line 248 */
        "subss 0x3cc(%ebx), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* screenOffset */
        "subss 0x3d0(%ebx), %xmm1\n" /* line 249 */
        "movss %xmm1, -0x20(%ebp)\n"
        "subss 0x3d4(%ebx), %xmm0\n" /* line 250 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 704 | screenOffset */
        "movl %eax, (%esp)\n"
        "movss %xmm3, -0xf8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm0\n"
        "mulss 0x3d8(%ebx), %xmm0\n" /* line 428 */
        "addss 0x3dc(%ebx), %xmm0\n"
        "mulss 0x2ed890, %xmm0\n" /* -0.0009765625f */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "mulss 0x2ed830, %xmm0\n" /* 32.0f */
        "movss -0xf8(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xd4(%ebp)\n"
        "cvttss2si -0xd4(%ebp), %ecx\n"
        "cmpl $7, %ecx\n" /* line 709 */
        "jg .Lfffc70_00100d99\n"
        "movl $0x30, %esi\n"
        "movl $0x10, -0x58(%ebp)\n"
        "movss 0x2ed740, %xmm0\n" /* 8.0f */
        "movss %xmm0, -0x54(%ebp)\n"
        "movl -0x58(%ebp), %edx\n"
        ".Lfffc70_00100abd:\n"
        "movl 0x195f160, %ebx\n" /* line 344 */
        "movl 0x5a7d4(%ebx), %eax\n"
        "leal 2(%edx, %eax), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfffc70_00100ae2\n"
        "addl 0x5a7d0(%ebx), %esi\n"
        "cmpl $0x100000, %esi\n"
        "jle .Lfffc70_00100b3e\n"
        ".Lfffc70_00100ae2:\n"
        "movl 0x5a7cc(%ebx), %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%ebx), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%ebx), %esi\n" /* line 310 */
        "je .Lfffc70_00100b3e\n"
        "movl 0x5a7d0(%ebx), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfffc70_00100d10\n"
        "movl 0x5a7e0(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfffc70_00100d10\n"
        ".Lfffc70_00100b33:\n"
        "movl 0x195f160, %eax\n" /* line 313 */
        "movl %esi, 0x5a7cc(%eax)\n"
        ".Lfffc70_00100b3e:\n"
        "movl -0xa4(%ebp), %ecx\n" /* line 248 | a */
        "movss (%ecx), %xmm0\n"
        "movl -0xa8(%ebp), %ebx\n" /* b */
        "subss (%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* worldRadius */
        "movl -0xa0(%ebp), %esi\n" /* line 249 */
        "movss (%esi), %xmm0\n"
        "movl -0x9c(%ebp), %eax\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl -0x98(%ebp), %edx\n" /* line 250 */
        "movss (%edx), %xmm0\n"
        "movl -0x94(%ebp), %ecx\n"
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %ebx\n" /* line 718 | worldRadius */
        "movl %ebx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x48(%ebp), %eax\n" /* line 719 | midpoint */
        "movl %eax, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* forward */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MakeNormalVectors\n"
        "movl 0x195f160, %ebx\n" /* line 721 */
        "movl 0x5a7d4(%ebx), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl %eax, -0xac(%ebp)\n" /* vert */
        "leal 0x58(%edi), %edx\n" /* line 723 | rgbaFrom */
        "movzbl 1(%edx), %ecx\n"
        /* { scope 2: worldOffset */
        "movzbl 0x58(%edi), %eax\n" /* line 655 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, -0xcc(%ebp)\n" /* mtlColor */
        "orl %eax, -0xcc(%ebp)\n" /* mtlColor */
        "movl -0xcc(%ebp), %eax\n" /* line 656 | mtlColor */
        "movb %cl, %ah\n"
        "movl %eax, -0xcc(%ebp)\n" /* mtlColor */
        "movb 2(%edx), %al\n" /* line 657 */
        "movl %eax, -0xcc(%ebp)\n" /* mtlColor */
        "movzbl 3(%edx), %eax\n" /* line 658 */
        "shll $0x18, %eax\n"
        "andl $0xffffff, -0xcc(%ebp)\n" /* mtlColor */
        "orl %eax, -0xcc(%ebp)\n" /* mtlColor */
        /* } scope */
        "movss 0x2ed5d0, %xmm0\n" /* line 725 | 1.0f */
        "divss -0x54(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n" /* sDelta */
        "cvtss2sd %xmm0, %xmm0\n" /* line 729 */
        "mulsd 0x307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n" /* radians */
        /* { scope 2: worldOffset */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0xb0(%ebp)\n" /* sinAngleDelta */
        "movss -0x90(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm5\n"
        /* } scope */
        "movl -0x58(%ebp), %eax\n" /* line 733 */
        "testl %eax, %eax\n"
        "jg .Lfffc70_00100dbd\n"
        "xorl %eax, %eax\n"
        ".Lfffc70_00100c7a:\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 763 */
        "movl -0xac(%ebp), %edx\n" /* vert */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %edx, %ecx\n" /* line 199 */
        "movl (%edx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        "movl $0x3f800000, 0x1c(%eax)\n" /* line 764 */
        "movl $0x3f800000, 0x20(%eax)\n" /* line 765 */
        "movl -0xcc(%ebp), %ebx\n" /* line 766 | mtlColor */
        "movl %ebx, 0x18(%eax)\n"
        "leal 0x24(%eax), %ecx\n" /* line 768 */
        "movl -0xac(%ebp), %ebx\n" /* vert, from */
        "addl $0x24, %ebx\n" /* from */
        /* { scope 2: worldOffset */
        "movl -0xac(%ebp), %esi\n" /* line 199 | vert */
        "movl 0x24(%esi), %edx\n"
        "movl %edx, 0x24(%eax)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0x3f800000, 0x1c(%ecx)\n" /* line 769 */
        "movl $0, 0x20(%ecx)\n" /* line 770 */
        "movl -0xcc(%ebp), %eax\n" /* line 771 | mtlColor */
        "movl %eax, 0x18(%ecx)\n"
        "movl 0x195f160, %edx\n" /* line 773 */
        "movl 0x5a7d4(%edx), %edx\n"
        "addl %edx, -0x58(%ebp)\n"
        "movl -0x58(%ebp), %eax\n"
        "addl $2, %eax\n"
        "movl 0x195f160, %ecx\n"
        "movl %eax, 0x5a7d4(%ecx)\n"
        "jmp .Lfffc70_000ffe08\n"
        ".Lfffc70_00100d10:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfffc70_00100b33\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100d1a:\n"
        "movl 0x195f23c, %eax\n" /* line 962 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c4, %xmm1\n" /* 0.00390625f */
        "movss %xmm1, (%esp)\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "movl %ebx, %eax\n" /* b */
        "calll RB_AddLineDx7\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100d4e:\n"
        "leal 0x3c(%edi), %eax\n" /* line 571 */
        "movl -0x30(%ebp), %edx\n" /* worldRadius */
        "movl %edx, (%esp)\n"
        "movaps %xmm4, %xmm0\n"
        "movl %esi, %ecx\n"
        "movl %ebx, %edx\n"
        "calll RB_AddQuadStampDx7\n"
        "jmp .Lfffc70_000ffe08\n"
        /* { scope 2: worldOffset */
        ".Lfffc70_00100d68:\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 271 | 1.0f */
        "movaps %xmm2, %xmm3\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm1\n"
        "jmp .Lfffc70_0010034e\n"
        /* } scope */
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100d7f:\n"
        "leal (%ecx, %ecx), %edx\n" /* line 613 */
        "leal (%edx, %ecx), %eax\n"
        "leal (%eax, %eax), %esi\n"
        "movl %edx, -0x60(%ebp)\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "jmp .Lfffc70_000fff39\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100d99:\n"
        "cmpl $0x20, %ecx\n" /* line 711 */
        "jle .Lfffc70_00101099\n"
        "movl $0xc0, %esi\n"
        "movl $0x40, -0x58(%ebp)\n"
        "movl $0x42000000, -0x54(%ebp)\n"
        "movl -0x58(%ebp), %edx\n"
        "jmp .Lfffc70_00100abd\n"
        ".Lfffc70_00100dbd:\n"
        "movl -0xac(%ebp), %esi\n" /* line 739 | vert */
        "movl %esi, %eax\n"
        "addl $0x40, %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm4\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movl $0, -0xb4(%ebp)\n" /* segmentX2 */
        "jmp .Lfffc70_00100de9\n"
        ".Lfffc70_00100de6:\n"
        "movaps %xmm1, %xmm2\n" /* line 733 */
        ".Lfffc70_00100de9:\n"
        "movaps %xmm2, %xmm1\n" /* line 735 | scale */
        "mulss 0x68(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x3c(%ebp), %xmm0\n" /* forward */
        "movl -0xa4(%ebp), %edx\n" /* a */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x38(%ebp), %xmm0\n"
        "movl -0xa0(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "mulss -0x34(%ebp), %xmm1\n" /* line 290 */
        "movl -0x98(%ebp), %ebx\n"
        "addss (%ebx), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 736 | scale */
        "mulss 0x68(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "addss (%esi), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%esi), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movss %xmm4, 0x1c(%esi)\n" /* line 737 */
        "movl $0x3f800000, 0x20(%esi)\n" /* line 738 */
        "movl -0xcc(%ebp), %eax\n" /* line 739 | mtlColor */
        "movl %eax, 0x18(%esi)\n"
        "leal 0x24(%esi), %eax\n" /* line 741 | result */
        "movaps %xmm2, %xmm1\n" /* scale */
        "mulss 0x64(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x3c(%ebp), %xmm0\n" /* forward */
        "movl -0xa8(%ebp), %edx\n" /* b */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, 0x24(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x38(%ebp), %xmm0\n"
        "movl -0x9c(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 0x28(%esi)\n"
        "mulss -0x34(%ebp), %xmm1\n" /* line 290 */
        "movl -0x94(%ebp), %ebx\n"
        "addss (%ebx), %xmm1\n"
        "movss %xmm1, 0x2c(%esi)\n"
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 742 | scale */
        "mulss 0x64(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "addss 0x24(%esi), %xmm0\n"
        "movss %xmm0, 0x24(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 0x28(%esi)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 0x2c(%esi)\n"
        /* } scope */
        "movl -0x50(%ebp), %eax\n" /* line 743 */
        "movss %xmm4, (%eax)\n"
        "movl $0, 4(%eax)\n" /* line 744 */
        "movl -0xcc(%ebp), %edx\n" /* line 745 | mtlColor */
        "movl %edx, -4(%eax)\n"
        "addss -0xb8(%ebp), %xmm4\n" /* line 747 | sDelta */
        "movaps %xmm2, %xmm1\n" /* line 748 */
        "mulss %xmm5, %xmm1\n"
        "movss -0xb0(%ebp), %xmm0\n" /* sinAngleDelta */
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm3\n" /* line 749 */
        "mulss -0xb0(%ebp), %xmm2\n" /* sinAngleDelta */
        "subss %xmm2, %xmm3\n"
        "movl -0xb4(%ebp), %ecx\n" /* segmentX2 */
        "movl 0x195f160, %eax\n" /* line 752 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x10c(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl -0x10c(%ebp), %eax\n"
        "movw %dx, (%eax, %ebx, 2)\n"
        "movl 0x195f160, %edx\n" /* line 753 */
        "movl 0x5a7d0(%edx), %ebx\n"
        "movl 0x5a7b0(%edx), %eax\n"
        "movl %eax, -0x110(%ebp)\n"
        "movzwl 0x5a7d4(%edx), %eax\n"
        "addl %ecx, %eax\n"
        "movw %ax, -0xfe(%ebp)\n"
        "addl $1, %eax\n"
        "movl -0x110(%ebp), %edx\n"
        "movw %ax, 2(%edx, %ebx, 2)\n"
        "movl 0x195f160, %eax\n" /* line 754 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x114(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $3, %eax\n"
        "movl -0x114(%ebp), %edx\n"
        "movw %ax, 4(%edx, %ebx, 2)\n"
        "movl 0x195f160, %eax\n" /* line 755 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "addl $3, %ebx\n"
        "movl %ebx, 0x5a7d0(%eax)\n"
        "movl 0x5a7b0(%eax), %edx\n" /* line 757 */
        "movl %edx, -0x118(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $3, %eax\n"
        "movl -0x118(%ebp), %edx\n"
        "movw %ax, (%edx, %ebx, 2)\n"
        "movl 0x195f160, %eax\n" /* line 758 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x11c(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $2, %eax\n"
        "movl -0x11c(%ebp), %edx\n"
        "movw %ax, 2(%edx, %ebx, 2)\n"
        "movl 0x195f160, %ebx\n" /* line 759 */
        "movl 0x5a7d0(%ebx), %edx\n"
        "movl 0x5a7b0(%ebx), %eax\n"
        "addw 0x5a7d4(%ebx), %cx\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "addl $3, 0x5a7d0(%ebx)\n" /* line 760 */
        "addl $2, -0xb4(%ebp)\n" /* line 733 | segmentX2 */
        "addl $0x48, %esi\n"
        "addl $0x48, -0x50(%ebp)\n"
        "movl -0x58(%ebp), %eax\n"
        "cmpl %eax, -0xb4(%ebp)\n" /* segmentX2 */
        "jl .Lfffc70_00100de6\n"
        "movl -0xb4(%ebp), %eax\n" /* segmentX2 */
        "jmp .Lfffc70_00100c7a\n"
        ".Lfffc70_00101099:\n"
        "leal (%ecx, %ecx), %edx\n" /* line 711 */
        "leal (%edx, %ecx), %eax\n"
        "leal (%eax, %eax), %esi\n"
        "movl %edx, -0x58(%ebp)\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "jmp .Lfffc70_00100abd\n"
    );
}

/* line 1193 */
__attribute__((naked))
void RB_TessBackEndEntity(const surfaceType_t *surfType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1193 */
        "movl %esp, %ebp\n"
        "movl 0x195f0c8, %eax\n" /* line 1200 */
        "movl 0x440(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* surfType */
        "popl %ebp\n" /* line 1201 */
        "jmp RB_TessEntity\n" /* line 1200 */
    );
}

/* line 75 */
__attribute__((naked))
void RB_TessPoly(const surfaceType_t *surfType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0x195f160, %eax\n" /* line 310 */
        "cmpl $1, 0x5a7cc(%eax)\n"
        "je .Lf1010cc_0010136b\n"
        "movl 0x5a7d0(%eax), %ecx\n" /* line 261 */
        "testl %ecx, %ecx\n"
        "jne .Lf1010cc_00101310\n"
        "movl 0x5a7e0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1010cc_00101310\n"
        ".Lf1010cc_00101103:\n"
        "movl 0x195f160, %edx\n" /* line 313 */
        "movl $1, 0x5a7cc(%edx)\n"
        "movl %edx, %edi\n"
        ".Lf1010cc_00101115:\n"
        "movl 8(%ebp), %ebx\n" /* line 85 | surfType, vertIndex */
        "movzwl 0xa(%ebx), %ecx\n" /* vertIndex */
        "leal -6(%ecx, %ecx, 2), %edx\n" /* indexCount */
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 344 */
        "addl 0x5a7d4(%edi), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lf1010cc_00101364\n"
        "addl 0x5a7d0(%edi), %edx\n"
        "cmpl $0x100000, %edx\n"
        "jle .Lf1010cc_001011ba\n"
        "movl 0x195f160, %eax\n"
        ".Lf1010cc_00101146:\n"
        "movl 0x5a7cc(%eax), %ebx\n" /* line 327 | vertIndex */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x195f160, %edx\n" /* line 331 */
        "movl 0x5a7c4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "movl 0x195f160, %ecx\n" /* line 310 */
        "cmpl 0x5a7cc(%ecx), %ebx\n" /* vertIndex */
        "je .Lf1010cc_00101372\n"
        "movl 0x5a7d0(%ecx), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lf1010cc_0010131a\n"
        "movl 0x5a7e0(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1010cc_0010131a\n"
        ".Lf1010cc_001011a7:\n"
        "movl 0x195f160, %edi\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%edi)\n" /* vertIndex */
        "movl 8(%ebp), %eax\n" /* surfType */
        "movzwl 0xa(%eax), %ecx\n"
        /* } scope */
        ".Lf1010cc_001011ba:\n"
        "movl 0x195eec0, %eax\n" /* line 89 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lf1010cc_00101324\n"
        "testl %ecx, %ecx\n" /* line 92 */
        "jle .Lf1010cc_00101281\n"
        "xorl %ebx, %ebx\n" /* vertIndex */
        "xorl %esi, %esi\n"
        ".Lf1010cc_001011d7:\n"
        "movl %ebx, %eax\n" /* line 94 | vertIndex, to */
        "movl 0x195f160, %ecx\n" /* from */
        "addl 0x5a7d4(%ecx), %eax\n" /* to */
        "shll $5, %eax\n" /* to */
        "addl %ecx, %eax\n" /* from, to */
        "movl %esi, %ecx\n" /* from */
        "movl 8(%ebp), %edi\n" /* surfType */
        "addl 0xc(%edi), %ecx\n" /* from */
        /* { scope 2 */
        "movl (%ecx), %edx\n" /* line 199 */
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 95 | vertIndex */
        "movl 0x195f160, %edx\n"
        "addl 0x5a7d4(%edx), %eax\n"
        "shll $5, %eax\n"
        "movl 0xc(%edi), %edx\n"
        "movl 0x18(%esi, %edx), %edx\n"
        "movl 0x195f160, %ecx\n"
        "movl %edx, 0xc(%eax, %ecx)\n"
        "movl %ebx, %eax\n" /* line 96 | vertIndex, to */
        "addl 0x5a7d4(%ecx), %eax\n" /* to */
        "shll $5, %eax\n" /* to */
        "leal 0x10(%eax, %ecx), %eax\n" /* to */
        "movl %esi, %ecx\n"
        "addl 0xc(%edi), %ecx\n"
        /* { scope 2 */
        "movl 0x1c(%ecx), %edx\n" /* line 37 */
        "movl %edx, (%eax)\n"
        "movl 0x20(%ecx), %edx\n" /* line 38 */
        "movl %edx, 4(%eax)\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 97 | vertIndex */
        "movl 0x195f160, %edi\n"
        "addl 0x5a7d4(%edi), %eax\n"
        "shll $5, %eax\n"
        "leal 0x10(%eax, %edi), %eax\n"
        "movl %esi, %ecx\n"
        "movl 8(%ebp), %edx\n" /* surfType */
        "addl 0xc(%edx), %ecx\n"
        "movl 0x24(%ecx), %edx\n" /* line 37 */
        "movl %edx, 8(%eax)\n"
        "movl 0x28(%ecx), %edx\n" /* line 38 */
        "movl %edx, 0xc(%eax)\n"
        "addl $1, %ebx\n" /* line 92 | vertIndex */
        "addl $0x44, %esi\n"
        "movl 8(%ebp), %edi\n" /* surfType */
        "movzwl 0xa(%edi), %ecx\n"
        "cmpl %ebx, %ecx\n" /* vertIndex */
        "jg .Lf1010cc_001011d7\n"
        ".Lf1010cc_00101281:\n"
        "leal -2(%ecx), %edi\n" /* line 110 */
        "movl %edi, -0x1c(%ebp)\n" /* vertCount */
        "testl %edi, %edi\n" /* line 111 */
        "jle .Lf1010cc_001012fc\n"
        "xorl %esi, %esi\n"
        ".Lf1010cc_0010128d:\n"
        "movl 0x195f160, %eax\n" /* line 113 */
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %eax, %ebx\n" /* vertIndex */
        "movl 0x5a7d4(%eax), %eax\n"
        "movw %ax, (%edx, %ecx, 2)\n"
        "movl %esi, %edx\n"
        "movl %ebx, %edi\n" /* line 114 | vertIndex */
        "movl 0x5a7d0(%ebx), %ebx\n" /* vertIndex */
        "movl 0x5a7b0(%edi), %ecx\n"
        "movl %esi, %eax\n"
        "addw 0x5a7d4(%edi), %ax\n"
        "addl $1, %eax\n"
        "movw %ax, 2(%ecx, %ebx, 2)\n"
        "movl 0x5a7d0(%edi), %ecx\n" /* line 115 */
        "movl 0x5a7b0(%edi), %eax\n"
        "addw 0x5a7d4(%edi), %dx\n"
        "addl $2, %edx\n"
        "movw %dx, 4(%eax, %ecx, 2)\n"
        "addl $3, 0x5a7d0(%edi)\n" /* line 116 */
        "addl $1, %esi\n" /* line 111 */
        "cmpl %esi, -0x1c(%ebp)\n" /* vertCount */
        "jne .Lf1010cc_0010128d\n"
        "movl 8(%ebp), %eax\n" /* surfType */
        "movzwl 0xa(%eax), %ecx\n"
        ".Lf1010cc_001012fc:\n"
        "movl 0x195f160, %edx\n" /* line 119 */
        "addl %ecx, 0x5a7d4(%edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 122 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1010cc_00101310:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lf1010cc_00101103\n"
        /* { scope 2 */
        ".Lf1010cc_0010131a:\n"
        "calll RB_EndSurface\n"
        "jmp .Lf1010cc_001011a7\n"
        /* } scope */
        ".Lf1010cc_00101324:\n"
        "movl 0x195f160, %eax\n" /* line 105 */
        "movl 0x5a7d4(%eax), %edx\n"
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "addl 0x195f160, %edx\n"
        "movl %ecx, %eax\n"
        "shll $6, %eax\n"
        "leal (%eax, %ecx, 4), %eax\n"
        "movl 8(%ebp), %ebx\n" /* surfType, vertIndex */
        "movl 0xc(%ebx), %ecx\n" /* vertIndex */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movzwl 0xa(%ebx), %ecx\n" /* vertIndex */
        "jmp .Lf1010cc_00101281\n"
        ".Lf1010cc_00101364:\n"
        "movl %edi, %eax\n"
        "jmp .Lf1010cc_00101146\n"
        ".Lf1010cc_0010136b:\n"
        "movl %eax, %edi\n"
        "jmp .Lf1010cc_00101115\n"
        ".Lf1010cc_00101372:\n"
        "movl 8(%ebp), %edx\n" /* surfType */
        "movzwl 0xa(%edx), %ecx\n"
        "jmp .Lf1010cc_001011ba\n"
    );
}

/* line 1485 */
__attribute__((naked))
void RB_TessStaticModelCached(const surfaceType_t *surfType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1485 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 1503 | surfType */
        "movl 4(%edx), %eax\n"
        "movswl 4(%eax), %eax\n"
        "leal (%eax, %eax, 2), %esi\n"
        "movl 0x195f160, %ebx\n" /* line 352 */
        "movl %esi, %eax\n"
        "addl 0x5a7e0(%ebx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jg .Lf10137e_00101414\n"
        ".Lf10137e_001013a9:\n"
        "movl $2, 0x5a7b8(%ebx)\n" /* line 1508 */
        "movl $0, 0x5a7e8(%ebx)\n" /* line 1509 */
        "movl $0x10000, 0x5a7e4(%ebx)\n" /* line 1510 */
        "movl 0x5a7e0(%ebx), %eax\n" /* line 1521 */
        "movl 0x5a7b4(%ebx), %edx\n"
        "leal (%edx, %eax, 2), %ecx\n"
        "leal (%esi, %eax), %eax\n" /* line 1522 */
        "movl %eax, 0x5a7e0(%ebx)\n"
        "leal (%esi, %esi), %eax\n" /* line 1530 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* surfType */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x195eed0, %edx\n"
        "movl 0x2dc8(%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Com_Memcpy\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1537 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf10137e_00101414:\n"
        "movl 0x5a7cc(%ebx), %edi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%ebx), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%ebx), %edi\n" /* line 310 */
        "je .Lf10137e_001013a9\n"
        "movl 0x5a7d0(%ebx), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lf10137e_00101472\n"
        "movl 0x5a7e0(%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf10137e_00101472\n"
        "movl 0x195f160, %ebx\n" /* line 313 */
        "movl %edi, 0x5a7cc(%ebx)\n"
        "jmp .Lf10137e_001013a9\n"
        ".Lf10137e_00101472:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl 0x195f160, %ebx\n" /* line 313 */
        "movl %edi, 0x5a7cc(%ebx)\n"
        "jmp .Lf10137e_001013a9\n"
    );
}

/* line 1367 */
__attribute__((naked))
void RB_TessXModelSkinned(const surfaceType_t *surfType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1367 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* surfType */
        "movl 8(%ebx), %eax\n" /* line 1380 | surfType */
        "testl %eax, %eax\n"
        "js .Lf101488_00101586\n"
        /* { scope 1 */
        "movl 0x195f160, %eax\n" /* line 261 */
        "movl 0x5a7d0(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jne .Lf101488_00101568\n"
        "movl 0x5a7e0(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf101488_00101568\n"
        ".Lf101488_001014c0:\n"
        "movl 4(%ebx), %edi\n" /* line 1264 */
        "movl 0x195eec0, %eax\n" /* line 1067 */
        "movl (%eax), %eax\n"
        "movl $0x24, %esi\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x40, %eax\n"
        "cmovnel %eax, %esi\n"
        "movl $0, -0x1c(%ebp)\n" /* line 1274 */
        "movl 8(%ebx), %eax\n" /* line 1275 */
        "cltd\n"
        "idivl %esi\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* line 1276 | args */
        "movswl 2(%edi), %eax\n" /* line 1278 */
        "movl %eax, -0x28(%ebp)\n"
        "movswl 4(%edi), %eax\n" /* line 1279 */
        "movl %eax, -0x24(%ebp)\n"
        /* { scope 2 */
        "movl 0x14(%edi), %eax\n" /* line 24 */
        /* } scope */
        /* { scope 2 */
        "movl 0x195f138, %ebx\n" /* line 212 */
        "cmpl 0x20cc(%ebx), %eax\n"
        "je .Lf101488_00101519\n"
        "movl %eax, (%esp)\n" /* line 213 */
        "calll RB_ChangeIndices\n"
        /* } scope */
        ".Lf101488_00101519:\n"
        "movl 0x195f188, %eax\n" /* line 1005 */
        "movl (%eax), %eax\n"
        "movl 0x217c78(%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        /* { scope 2 */
        "cmpl 0x20d0(%ebx), %eax\n" /* line 220 */
        "je .Lf101488_00101572\n"
        ".Lf101488_00101531:\n"
        "movl %esi, 0xc(%esp)\n" /* line 221 */
        "movl $0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll RB_ChangeStreamSource\n"
        /* } scope */
        ".Lf101488_0010154d:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 1293 | args */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll RB_DrawTechnique\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1385 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf101488_00101568:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lf101488_001014c0\n"
        /* { scope 2 */
        ".Lf101488_00101572:\n"
        "movl 0x20d4(%ebx), %ecx\n" /* line 220 */
        "testl %ecx, %ecx\n"
        "jne .Lf101488_00101531\n"
        "cmpl 0x20d8(%ebx), %esi\n"
        "jne .Lf101488_00101531\n"
        "jmp .Lf101488_0010154d\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        ".Lf101488_00101586:\n"
        "movl 4(%ebx), %eax\n" /* line 1324 */
        "movl %eax, -0x3c(%ebp)\n" /* xsurf */
        "movl %eax, (%esp)\n" /* line 1326 */
        "calll XSurfaceGetNumVerts\n"
        "movl %eax, %edi\n" /* surface */
        "movl -0x3c(%ebp), %edx\n" /* line 1327 | xsurf */
        "movl %edx, (%esp)\n"
        "calll XSurfaceGetNumTris\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 2 */
        "movl %edi, %eax\n" /* line 344 */
        "movl 0x195f160, %edx\n"
        "addl 0x5a7d4(%edx), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lf101488_001016da\n"
        "movl -0x40(%ebp), %eax\n"
        "addl 0x5a7d0(%edx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jg .Lf101488_00101663\n"
        "movl 0x195f160, %eax\n"
        /* } scope */
        ".Lf101488_001015d9:\n"
        "testb $1, 0x5a7d0(%eax)\n" /* line 1331 */
        "jne .Lf101488_001016de\n"
        ".Lf101488_001015e6:\n"
        "movzwl 0x5a7d4(%eax), %edx\n" /* line 1335 */
        "movl 0x195eec0, %eax\n" /* line 1340 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf101488_0010174c\n"
        "movzwl %dx, %esi\n" /* line 1347 | vertexStride */
        "movl %edi, %eax\n" /* vertexCount */
        "shll $6, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, %eax\n" /* vertexStride */
        "shll $6, %eax\n"
        "addl 0x195f160, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        ".Lf101488_00101624:\n"
        "movl 0x195f160, %ebx\n" /* line 1352 */
        "addl %edi, 0x5a7d4(%ebx)\n" /* vertexCount */
        "movl %esi, 8(%esp)\n" /* line 1356 | vertexStride */
        "movl 0x5a7d0(%ebx), %eax\n"
        "movl 0x5a7b0(%ebx), %edx\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n" /* xsurf */
        "movl %eax, (%esp)\n"
        "calll XSurfaceGetTris\n"
        "movl -0x40(%ebp), %edx\n" /* line 1360 */
        "addl %edx, 0x5a7d0(%ebx)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1385 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf101488_00101663:\n"
        "movl 0x195f160, %eax\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf101488_00101668:\n"
        "movl 0x5a7cc(%eax), %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x195f160, %edx\n" /* line 331 */
        "movl 0x5a7c4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "movl 0x195f160, %eax\n" /* line 310 */
        "cmpl 0x5a7cc(%eax), %esi\n"
        "je .Lf101488_001015d9\n"
        "movl 0x5a7d0(%eax), %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lf101488_001016d3\n"
        "movl 0x5a7e0(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf101488_001016d3\n"
        ".Lf101488_001016c0:\n"
        "movl 0x195f160, %edx\n" /* line 313 */
        "movl %esi, 0x5a7cc(%edx)\n"
        "movl %edx, %eax\n"
        "jmp .Lf101488_001015d9\n"
        ".Lf101488_001016d3:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lf101488_001016c0\n"
        ".Lf101488_001016da:\n"
        "movl %edx, %eax\n"
        "jmp .Lf101488_00101668\n"
        /* } scope */
        ".Lf101488_001016de:\n"
        "movl 0x5a7cc(%eax), %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x195f160, %edx\n" /* line 331 */
        "movl 0x5a7c4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "movl 0x195f160, %eax\n" /* line 310 */
        "cmpl 0x5a7cc(%eax), %esi\n"
        "je .Lf101488_00101779\n"
        "movl 0x5a7d0(%eax), %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lf101488_00101745\n"
        "movl 0x5a7e0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf101488_00101745\n"
        ".Lf101488_00101732:\n"
        "movl 0x195f160, %edx\n" /* line 313 */
        "movl %esi, 0x5a7cc(%edx)\n"
        "movl %edx, %eax\n"
        "jmp .Lf101488_001015e6\n"
        ".Lf101488_00101745:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lf101488_00101732\n"
        ".Lf101488_0010174c:\n"
        "movzwl %dx, %esi\n" /* line 1342 | vertexStride */
        "leal (%edi, %edi, 8), %eax\n" /* vertexCount */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %esi, 8), %eax\n" /* vertexStride */
        "movl 0x195f160, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "jmp .Lf101488_00101624\n"
        ".Lf101488_00101779:\n"
        "movl 0x195f160, %eax\n"
        "jmp .Lf101488_001015e6\n"
    );
}

/* line 1553 */
__attribute__((naked))
void RB_TessTriangles(const surfaceType_t *surfType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1553 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* surfType */
        "movl 0x195f160, %edi\n" /* line 1564 */
        "movl 0x5a7e0(%edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf101784_0010180c\n"
        "movl 0x5a7e8(%edi), %eax\n"
        "cmpl 0x1c(%ebx), %eax\n" /* surfType */
        "je .Lf101784_00101874\n"
        ".Lf101784_001017af:\n"
        "movl 0x5a7cc(%edi), %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%edi), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%edi), %esi\n" /* line 310 */
        "je .Lf101784_0010180c\n"
        "movl 0x5a7d0(%edi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lf101784_001018f6\n"
        "movl 0x5a7e0(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf101784_001018f6\n"
        "movl 0x195f160, %edi\n" /* line 313 */
        "movl %esi, 0x5a7cc(%edi)\n"
        ".Lf101784_0010180c:\n"
        "movzwl 0x22(%ebx), %eax\n" /* line 352 */
        "addl 0x5a7e0(%edi), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jg .Lf101784_00101886\n"
        ".Lf101784_0010181d:\n"
        "movl $1, 0x5a7b8(%edi)\n" /* line 1573 */
        "movzwl 0x22(%ebx), %eax\n" /* line 1577 | surfType */
        "addl %eax, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x24(%ebx), %eax\n" /* surfType */
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7e0(%edi), %eax\n"
        "movl 0x5a7b4(%edi), %edx\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movzwl 0x22(%ebx), %eax\n" /* line 1581 | surfType */
        "addl %eax, 0x5a7e0(%edi)\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1584 | surfType */
        "movl %eax, 0x5a7e8(%edi)\n"
        "movzwl 0x20(%ebx), %eax\n" /* line 1585 | surfType */
        "movl %eax, 0x5a7e4(%edi)\n"
        "addl $0x1c, %esp\n" /* line 1588 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf101784_00101874:\n"
        "movzwl 0x20(%ebx), %eax\n" /* line 1564 | surfType */
        "cmpl %eax, 0x5a7e4(%edi)\n"
        "jne .Lf101784_001017af\n"
        "jmp .Lf101784_0010180c\n"
        ".Lf101784_00101886:\n"
        "movl 0x5a7cc(%edi), %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%edi), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%edi), %esi\n" /* line 310 */
        "je .Lf101784_0010190c\n"
        "movl 0x5a7d0(%edi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lf101784_001018e0\n"
        "movl 0x5a7e0(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf101784_001018e0\n"
        "movl 0x195f160, %edi\n" /* line 313 */
        "movl %esi, 0x5a7cc(%edi)\n"
        "jmp .Lf101784_0010181d\n"
        ".Lf101784_001018e0:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl 0x195f160, %edi\n" /* line 313 */
        "movl %esi, 0x5a7cc(%edi)\n"
        "jmp .Lf101784_0010181d\n"
        ".Lf101784_001018f6:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl 0x195f160, %edi\n" /* line 313 */
        "movl %esi, 0x5a7cc(%edi)\n"
        "jmp .Lf101784_0010180c\n"
        ".Lf101784_0010190c:\n"
        "movl 0x195f160, %edi\n"
        "jmp .Lf101784_0010181d\n"
    );
}

