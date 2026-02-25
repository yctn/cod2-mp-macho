/* ASM dump from: r_water_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_water_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

qboolean R_WatersEquivalent(const water_t *w0, const water_t *w1);
J_COLOR_SPACE R_CreateWaterSetup(const water_t *source, int waterMapSetupIndex, water_t *destination);

/* line 9 */
__attribute__((naked))
qboolean R_WatersEquivalent(const water_t *w0, const water_t *w1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 9 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* w0 */
        "movl 0xc(%ebp), %ecx\n" /* w1 */
        "movl 0xc(%edx), %eax\n" /* line 16 */
        "cmpl 0xc(%ecx), %eax\n"
        "je .Lf10a3a0_0010a3b5\n"
        ".Lf10a3a0_0010a3b1:\n"
        "xorl %eax, %eax\n" /* line 81 */
        "popl %ebp\n" /* line 32 */
        "retl\n"
        ".Lf10a3a0_0010a3b5:\n"
        "movl 0x10(%edx), %eax\n" /* line 16 */
        "cmpl 0x10(%ecx), %eax\n"
        "jne .Lf10a3a0_0010a3b1\n"
        "movss 0x14(%edx), %xmm0\n" /* line 18 */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "jne .Lf10a3a0_0010a3b1\n"
        "jp .Lf10a3a0_0010a3b1\n"
        "movss 0x18(%edx), %xmm0\n"
        "ucomiss 0x18(%ecx), %xmm0\n"
        "jne .Lf10a3a0_0010a3b1\n"
        "jp .Lf10a3a0_0010a3b1\n"
        "movss 0x2c(%edx), %xmm0\n" /* line 20 */
        "subss 0x2c(%ecx), %xmm0\n"
        "movss 0x2f30e0, %xmm6\n"
        "andps %xmm6, %xmm0\n"
        "ucomiss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "ja .Lf10a3a0_0010a3b1\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 22 */
        "subss 0x1c(%ecx), %xmm0\n"
        "andps %xmm6, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd 0x307d10, %xmm1\n" /* 0.1 */
        "ucomisd %xmm1, %xmm0\n"
        "ja .Lf10a3a0_0010a3b1\n"
        "movss 0x20(%edx), %xmm0\n" /* line 24 */
        "subss 0x20(%ecx), %xmm0\n"
        "andps %xmm6, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "ucomisd %xmm1, %xmm0\n"
        "ja .Lf10a3a0_0010a3b1\n"
        "movss 0x24(%edx), %xmm0\n" /* line 114 */
        "movss 0x24(%ecx), %xmm1\n"
        "movss 0x28(%edx), %xmm4\n"
        "movss 0x28(%ecx), %xmm5\n"
        "movaps %xmm0, %xmm3\n" /* line 28 */
        "mulss %xmm1, %xmm3\n"
        "movaps %xmm4, %xmm2\n"
        "mulss %xmm5, %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm4, %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "mulss %xmm5, %xmm5\n"
        "addss %xmm5, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd 0x307d18, %xmm0\n" /* 1e-10 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "subss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "andps %xmm6, %xmm3\n"
        "ucomiss 0x2ed658, %xmm3\n" /* 0.0010000000474974513f */
        "ja .Lf10a3a0_0010a3b1\n"
        "movl $1, %eax\n"
        "popl %ebp\n" /* line 32 */
        "retl\n"
    );
}

/* line 96 */
__attribute__((naked))
J_COLOR_SPACE R_CreateWaterSetup(const water_t *source, int waterMapSetupIndex, water_t *destination)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* destination */
        /* { scope 1: n, n_scale, m_scale, kx, ... */
        "movl 8(%ebp), %eax\n" /* line 105 | source */
        "movl 0xc(%eax), %ebx\n" /* elementCount */
        "imull 0x10(%eax), %ebx\n" /* elementCount */
        "movl $0x44, 8(%esp)\n" /* line 107 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* destination */
        "calll memcpy\n"
        "leal (, %ebx, 8), %eax\n" /* line 108 */
        "movl %eax, (%esp)\n"
        "calll Material_Alloc\n"
        "movl %eax, 4(%edi)\n" /* destination */
        "shll $2, %ebx\n" /* line 109 | elementCount */
        "movl %ebx, (%esp)\n" /* elementCount */
        "calll Material_Alloc\n"
        "movl %eax, 8(%edi)\n" /* destination */
        /* { scope 2 */
        "movss 0x20(%edi), %xmm5\n" /* line 58 */
        "mulss %xmm5, %xmm5\n"
        "mulss %xmm5, %xmm5\n" /* line 59 */
        "divss 0x1c(%edi), %xmm5\n"
        "movl 0x10(%edi), %esi\n" /* line 60 */
        "cvtsi2ssl %esi, %xmm0\n"
        "mulss 0x14(%edi), %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd 0x307c98, %xmm1\n" /* 6.283185307179586 */
        "movapd %xmm1, %xmm2\n"
        "divsd %xmm0, %xmm2\n"
        "cvtsd2ss %xmm2, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n" /* n_scale */
        "cvtsi2ssl 0xc(%edi), %xmm0\n" /* line 61 */
        "mulss 0x18(%edi), %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "divsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n" /* m_scale */
        "movl %esi, %edx\n" /* line 64 */
        "negl %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* n */
        "movl %esi, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %esi, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, -0x48(%ebp)\n" /* n */
        "jge .Lf10a4a4_0010a793\n"
        "movl $0, -0x38(%ebp)\n" /* i */
        "movl 0xc(%edi), %ecx\n"
        "jmp .Lf10a4a4_0010a58b\n"
        ".Lf10a4a4_0010a575:\n"
        "addl $1, -0x48(%ebp)\n" /* n */
        "movl %esi, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %esi, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, -0x48(%ebp)\n" /* n */
        "jge .Lf10a4a4_0010a793\n"
        ".Lf10a4a4_0010a58b:\n"
        "cvtsi2ssl -0x48(%ebp), %xmm0\n" /* line 66 | n */
        "movss -0x44(%ebp), %xmm1\n" /* n_scale */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* kx */
        "movl %ecx, %edx\n" /* line 67 */
        "negl %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %ebx\n" /* m */
        "sarl $1, %ebx\n" /* m */
        "movl %ecx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %ecx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %ebx, %eax\n" /* m */
        "jle .Lf10a4a4_0010a575\n"
        "mulss %xmm1, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movl -0x38(%ebp), %esi\n" /* line 96 | i */
        "shll $3, %esi\n"
        "movl -0x38(%ebp), %eax\n" /* i, waterMapSetupIndex */
        "shll $2, %eax\n" /* waterMapSetupIndex */
        "movl %eax, -0x2c(%ebp)\n" /* waterMapSetupIndex */
        "jmp .Lf10a4a4_0010a6c2\n"
        ".Lf10a4a4_0010a5d6:\n"
        "cvtss2sd 0x2c(%edi), %xmm1\n" /* line 81 */
        "movaps %xmm5, %xmm2\n" /* line 82 */
        "mulss %xmm3, %xmm2\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        "divss %xmm2, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "movsd %xmm1, -0x78(%ebp)\n"
        "movss %xmm3, -0x88(%ebp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "movss %xmm5, -0xa8(%ebp)\n"
        "calll exp\n"
        "fstpl -0x50(%ebp)\n"
        "movsd -0x78(%ebp), %xmm1\n"
        "mulsd -0x50(%ebp), %xmm1\n"
        "movss -0x88(%ebp), %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "cvtss2sd %xmm3, %xmm0\n"
        "divsd %xmm0, %xmm1\n"
        "movss -0x98(%ebp), %xmm4\n"
        "mulss %xmm4, %xmm4\n"
        "cvtss2sd %xmm4, %xmm0\n"
        "mulsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "sqrtss %xmm0, %xmm0\n"
        "mulss 0x2c(%edi), %xmm0\n"
        "movl 4(%edi), %eax\n" /* line 85 */
        "movaps %xmm0, %xmm1\n"
        "mulss -0x20(%ebp), %xmm1\n" /* E */
        "movss %xmm1, (%eax, %esi)\n"
        "movl 4(%edi), %eax\n" /* line 86 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%eax, %esi)\n"
        "sqrtss -0x34(%ebp), %xmm0\n" /* line 81 */
        "movl 8(%edi), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "movss %xmm0, (%eax, %edx)\n"
        "movss -0xa8(%ebp), %xmm5\n"
        "addl $1, -0x38(%ebp)\n" /* line 90 | i */
        "addl $1, %ebx\n" /* line 67 | m */
        "addl $8, %esi\n"
        "addl $4, -0x2c(%ebp)\n"
        "movl 0xc(%edi), %ecx\n"
        "movl %ecx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %ecx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %ebx, %eax\n" /* m */
        "jle .Lf10a4a4_0010a77a\n"
        ".Lf10a4a4_0010a6c2:\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 69 | m */
        "mulss -0x40(%ebp), %xmm0\n" /* m_scale */
        "leal -0x1c(%ebp), %edx\n" /* line 70 */
        "movl %edx, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* E */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "movss %xmm5, -0xa8(%ebp)\n"
        "calll GaussianRandom\n"
        "movss -0x68(%ebp), %xmm0\n" /* line 71 */
        "movaps %xmm0, %xmm3\n"
        "mulss %xmm0, %xmm3\n"
        "addss -0x30(%ebp), %xmm3\n"
        "sqrtss %xmm3, %xmm1\n" /* line 81 */
        "movss %xmm1, -0x34(%ebp)\n"
        "mulss 0x1c(%edi), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss -0x3c(%ebp), %xmm4\n" /* line 73 | kx */
        "mulss 0x24(%edi), %xmm4\n"
        "mulss 0x28(%edi), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "pxor %xmm2, %xmm2\n" /* line 74 */
        "ucomiss %xmm4, %xmm2\n"
        "movss -0xa8(%ebp), %xmm5\n"
        "jb .Lf10a4a4_0010a5d6\n"
        "movl 4(%edi), %eax\n" /* line 76 */
        "movl $0, (%eax, %esi)\n"
        "movl 4(%edi), %eax\n" /* line 77 */
        "movl $0, 4(%eax, %esi)\n"
        "movl 8(%edi), %eax\n" /* line 78 */
        "movl -0x2c(%ebp), %edx\n"
        "movl $0, (%eax, %edx)\n"
        "addl $1, -0x38(%ebp)\n" /* line 90 | i */
        "addl $1, %ebx\n" /* line 67 | m */
        "addl $8, %esi\n"
        "addl $4, -0x2c(%ebp)\n"
        "movl 0xc(%edi), %ecx\n"
        "movl %ecx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %ecx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %ebx, %eax\n" /* m */
        "jg .Lf10a4a4_0010a6c2\n"
        ".Lf10a4a4_0010a77a:\n"
        "movl 0x10(%edi), %esi\n"
        "addl $1, -0x48(%ebp)\n" /* line 64 | n */
        "movl %esi, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %esi, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, -0x48(%ebp)\n" /* n */
        "jl .Lf10a4a4_0010a58b\n"
        /* } scope */
        ".Lf10a4a4_0010a793:\n"
        "movl 8(%ebp), %eax\n" /* line 113 | source */
        "movzwl 0x10(%eax), %ebx\n" /* elementCount */
        "movzwl 0xc(%eax), %esi\n"
        "movl 0xc(%ebp), %eax\n" /* waterMapSetupIndex */
        "movl %eax, 4(%esp)\n"
        "movl $0x228b94, (%esp)\n" /* "watersetup%i" */
        "calll va\n"
        "movl %ebx, 8(%esp)\n" /* elementCount */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll R_CreateWaterMap\n"
        "movl %eax, 0x40(%edi)\n" /* line 115 | destination */
        /* } scope */
        "addl $0xac, %esp\n" /* line 116 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

