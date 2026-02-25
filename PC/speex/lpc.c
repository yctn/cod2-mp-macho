/* ASM dump from: lpc.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/lpc.c */

#include "common_types.h"
#include "imports.h"

spx_word32_t _spx_lpc(spx_coef_t *lpc, const spx_word16_t *ac, int p);
inflate_blocks_statef _spx_autocorr(const spx_word16_t *x, float *ac, int lag, int n);

/* line 75 */
__attribute__((naked))
spx_word32_t _spx_lpc(spx_coef_t *lpc, const spx_word16_t *ac, int p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 79 | ac */
        "movss (%eax), %xmm3\n" /* error */
        "pxor %xmm0, %xmm0\n" /* line 81 */
        "ucomiss %xmm0, %xmm3\n"
        "jp .Lf1f5b28_001f5b71\n"
        "jne .Lf1f5b28_001f5b71\n"
        "movl 0x10(%ebp), %eax\n" /* line 83 | p */
        "testl %eax, %eax\n"
        "jle .Lf1f5b28_001f5b5e\n"
        "xorl %eax, %eax\n" /* line 81 */
        ".Lf1f5b28_001f5b4c:\n"
        "movl 8(%ebp), %edx\n" /* line 84 | lpc */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 83 */
        "cmpl %eax, 0x10(%ebp)\n" /* p */
        "jne .Lf1f5b28_001f5b4c\n"
        ".Lf1f5b28_001f5b5e:\n"
        "movaps %xmm0, %xmm3\n" /* line 88 */
        /* } scope */
        ".Lf1f5b28_001f5b61:\n"
        "movss %xmm3, -0x14(%ebp)\n" /* line 113 */
        "flds -0x14(%ebp)\n"
        "addl $8, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f5b28_001f5b71:\n"
        "movl 0x10(%ebp), %edx\n" /* line 88 | p */
        "testl %edx, %edx\n"
        "jle .Lf1f5b28_001f5b61\n"
        "movl 0xc(%ebp), %ecx\n" /* ac */
        "movl %ecx, -0x10(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* lpc */
        "xorl %esi, %esi\n"
        "movss 0x306ae0, %xmm4\n"
        "movsd 0x307fb8, %xmm5\n" /* 0.003 */
        /* { scope 2 */
        ".Lf1f5b28_001f5b93:\n"
        "movss 4(%ecx), %xmm2\n" /* line 91 | rr */
        "xorps %xmm4, %xmm2\n" /* rr */
        "testl %esi, %esi\n" /* line 92 */
        "jle .Lf1f5b28_001f5bbd\n"
        "movl %ecx, %eax\n"
        "xorl %edx, %edx\n"
        "movl 8(%ebp), %ecx\n" /* lpc */
        ".Lf1f5b28_001f5ba6:\n"
        "movss (%ecx, %edx, 4), %xmm0\n" /* line 93 */
        "mulss (%eax), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "addl $1, %edx\n" /* line 92 */
        "subl $4, %eax\n"
        "cmpl %edx, %esi\n"
        "jne .Lf1f5b28_001f5ba6\n"
        ".Lf1f5b28_001f5bbd:\n"
        "cvtss2sd %xmm2, %xmm2\n" /* line 97 */
        "cvtss2sd %xmm3, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* ac */
        "cvtss2sd (%eax), %xmm0\n"
        "mulsd %xmm5, %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "divsd %xmm1, %xmm2\n"
        "cvtsd2ss %xmm2, %xmm2\n"
        "movss %xmm2, (%edi)\n" /* line 100 */
        "movl %esi, %ebx\n" /* line 101 */
        "sarl $1, %ebx\n"
        "testl %ebx, %ebx\n"
        "jg .Lf1f5b28_001f5c35\n"
        "xorl %ebx, %ebx\n"
        ".Lf1f5b28_001f5bea:\n"
        "testl $1, %esi\n" /* line 107 */
        "je .Lf1f5b28_001f5c0b\n"
        "movl 8(%ebp), %edx\n" /* line 108 | lpc */
        "leal (%edx, %ebx, 4), %eax\n"
        "movss (%eax), %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        ".Lf1f5b28_001f5c0b:\n"
        "movaps %xmm3, %xmm0\n" /* line 110 */
        "mulss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "subss %xmm2, %xmm3\n"
        /* } scope */
        "addl $1, %esi\n" /* line 88 */
        "addl $4, -0x10(%ebp)\n"
        "addl $4, %edi\n"
        "cmpl %esi, 0x10(%ebp)\n" /* p */
        "je .Lf1f5b28_001f5b61\n"
        "movl -0x10(%ebp), %ecx\n"
        "jmp .Lf1f5b28_001f5b93\n"
        /* { scope 2 */
        ".Lf1f5b28_001f5c35:\n"
        "movl %edi, %eax\n" /* line 101 */
        "xorl %ecx, %ecx\n"
        "movl 8(%ebp), %edx\n" /* lpc */
        /* { scope 3 */
        ".Lf1f5b28_001f5c3c:\n"
        "movss (%edx), %xmm1\n" /* line 103 | tmp */
        "movaps %xmm2, %xmm0\n" /* line 104 */
        "mulss -4(%eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "mulss %xmm2, %xmm1\n" /* line 105 */
        "addss -4(%eax), %xmm1\n"
        "movss %xmm1, -4(%eax)\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 101 */
        "addl $4, %edx\n"
        "subl $4, %eax\n"
        "cmpl %ecx, %ebx\n"
        "jne .Lf1f5b28_001f5c3c\n"
        "jmp .Lf1f5b28_001f5bea\n"
    );
}

/* line 182 */
__attribute__((naked))
inflate_blocks_statef _spx_autocorr(const spx_word16_t *x, float *ac, int lag, int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 182 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ebx\n" /* line 186 | lag */
        "subl $1, %ebx\n"
        "cmpl $-1, %ebx\n"
        "je .Lf1f5c70_001f5cfa\n"
        "movl %ebx, -0x10(%ebp)\n" /* line 182 */
        "leal (, %ebx, 4), %eax\n"
        "movl 0xc(%ebp), %esi\n" /* ac */
        "addl %eax, %esi\n"
        "addl 8(%ebp), %eax\n" /* x */
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x14(%ebp), %ecx\n" /* n */
        "subl %ebx, %ecx\n"
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf1f5c70_001f5cbd\n"
        ".Lf1f5c70_001f5ca4:\n"
        "movaps %xmm2, %xmm1\n" /* line 188 */
        "movss %xmm1, (%esi)\n" /* line 190 */
        "subl $1, %ebx\n" /* line 186 */
        "subl $4, %esi\n"
        "subl $4, -0x14(%ebp)\n"
        "addl $1, %ecx\n"
        "cmpl $-1, %ebx\n"
        "je .Lf1f5c70_001f5cfa\n"
        ".Lf1f5c70_001f5cbd:\n"
        "cmpl 0x14(%ebp), %ebx\n" /* line 188 | n */
        "jge .Lf1f5c70_001f5ca4\n"
        "movl -0x14(%ebp), %edx\n"
        "movaps %xmm2, %xmm1\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* x */
        ".Lf1f5c70_001f5ccd:\n"
        "movss (%edx), %xmm0\n" /* line 189 */
        "mulss (%edi, %eax, 4), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %eax\n"
        "addl $4, %edx\n"
        "cmpl %ecx, %eax\n" /* line 188 */
        "jne .Lf1f5c70_001f5ccd\n"
        "movss %xmm1, (%esi)\n" /* line 190 */
        "subl $1, %ebx\n" /* line 186 */
        "subl $4, %esi\n"
        "subl $4, -0x14(%ebp)\n"
        "addl $1, %ecx\n"
        "cmpl $-1, %ebx\n"
        "jne .Lf1f5c70_001f5cbd\n"
        ".Lf1f5c70_001f5cfa:\n"
        "movss 0x2ed6b4, %xmm0\n" /* line 192 | 10.0f */
        "movl 0xc(%ebp), %eax\n" /* ac */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        /* } scope */
        "addl $8, %esp\n" /* line 193 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

