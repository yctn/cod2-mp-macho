/* ASM dump from: vq.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/vq.c */

#include "common_types.h"
#include "imports.h"

int scal_quant(spx_word16_t in, const spx_word16_t *boundary, int entries);
long int vq_nbest(spx_word16_t *in, const spx_word16_t *codebook, int len, int entries, spx_word32_t *E, int N, int *nbest, spx_word32_t *best_dist, char *stack);
long int vq_nbest_sign(spx_word16_t *in, const spx_word16_t *codebook, int len, int entries, spx_word32_t *E, int N, int *nbest, spx_word32_t *best_dist, char *stack);

/* line 48 */
__attribute__((naked))
int scal_quant(spx_word16_t in, const spx_word16_t *boundary, int entries)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "movss 8(%ebp), %xmm0\n" /* in */
        "movl 0xc(%ebp), %ecx\n" /* boundary */
        /* { scope 1 */
        "movl 0x10(%ebp), %edx\n" /* line 51 | entries */
        "subl $1, %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1f5174_001f519f\n"
        "ucomiss (%ecx), %xmm0\n"
        "jbe .Lf1f5174_001f519f\n"
        "xorl %eax, %eax\n"
        ".Lf1f5174_001f5190:\n"
        "addl $1, %eax\n" /* line 54 */
        "cmpl %edx, %eax\n" /* line 51 */
        "je .Lf1f5174_001f519d\n"
        "ucomiss (%ecx, %eax, 4), %xmm0\n"
        "ja .Lf1f5174_001f5190\n"
        /* } scope */
        ".Lf1f5174_001f519d:\n"
        "popl %ebp\n" /* line 57 */
        "retl\n"
        /* { scope 1 */
        ".Lf1f5174_001f519f:\n"
        "xorl %eax, %eax\n" /* line 51 */
        /* } scope */
        "popl %ebp\n" /* line 57 */
        "retl\n"
    );
}

/* line 96 */
__attribute__((naked))
long int vq_nbest(spx_word16_t *in, const spx_word16_t *codebook, int len, int entries, spx_word32_t *E, int N, int *nbest, spx_word32_t *best_dist, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0x14(%ebp), %ebx\n" /* line 100 | entries */
        "testl %ebx, %ebx\n"
        "jle .Lf1f51a6_001f52b1\n"
        /* { scope 2 */
        "movl 0x1c(%ebp), %eax\n" /* line 112 | N */
        "subl $1, %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* k */
        "shll $2, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 110 | N */
        "movl 0x24(%ebp), %ecx\n" /* best_dist */
        "leal -4(%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl $0, -0x14(%ebp)\n" /* used */
        "movl $0, -0x1c(%ebp)\n" /* i */
        "pxor %xmm4, %xmm4\n"
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        ".Lf1f51a6_001f51f0:\n"
        "movl 0x10(%ebp), %edx\n" /* line 103 | len */
        "testl %edx, %edx\n"
        "jg .Lf1f51a6_001f52b9\n"
        "movaps %xmm4, %xmm1\n"
        ".Lf1f51a6_001f51fe:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 108 | i */
        "movl 0x18(%ebp), %edx\n" /* E */
        "movss (%edx, %eax, 4), %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 110 | N */
        "cmpl %ecx, %eax\n"
        "jl .Lf1f51a6_001f5224\n"
        "movl -0x20(%ebp), %esi\n"
        "movss (%esi), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf1f51a6_001f52a1\n"
        ".Lf1f51a6_001f5224:\n"
        "movl -0x18(%ebp), %ecx\n" /* line 112 | k */
        "testl %ecx, %ecx\n"
        "jle .Lf1f51a6_001f52e4\n"
        "movl 0x24(%ebp), %eax\n" /* line 96 | best_dist */
        "addl -0x10(%ebp), %eax\n"
        "leal -4(%eax), %ebx\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x10(%ebp), %edx\n"
        "movl -0x18(%ebp), %ecx\n" /* k */
        "xorl %edi, %edi\n"
        ".Lf1f51a6_001f5243:\n"
        "cmpl %ecx, -0x14(%ebp)\n" /* line 112 | used */
        "jl .Lf1f51a6_001f5257\n"
        "movl %edx, %eax\n"
        "movl -0x28(%ebp), %esi\n"
        "movss -4(%esi), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf1f51a6_001f528c\n"
        ".Lf1f51a6_001f5257:\n"
        "movss (%ebx), %xmm0\n" /* line 114 */
        "movl 0x24(%ebp), %eax\n" /* best_dist */
        "movss %xmm0, (%eax, %edx)\n"
        "movl 0x20(%ebp), %eax\n" /* line 115 | nbest */
        "movl -4(%eax, %edx), %eax\n"
        "movl 0x20(%ebp), %esi\n" /* nbest */
        "movl %eax, (%esi, %edx)\n"
        "subl $1, %ecx\n" /* line 112 */
        "addl $1, %edi\n"
        "subl $4, %ebx\n"
        "subl $4, -0x28(%ebp)\n"
        "subl $4, %edx\n"
        "cmpl -0x18(%ebp), %edi\n" /* k */
        "jne .Lf1f51a6_001f5243\n"
        "leal (, %ecx, 4), %eax\n"
        ".Lf1f51a6_001f528c:\n"
        "movl 0x24(%ebp), %edx\n" /* line 117 | best_dist */
        "movss %xmm2, (%eax, %edx)\n"
        "movl -0x1c(%ebp), %esi\n" /* line 118 | i */
        "movl 0x20(%ebp), %ecx\n" /* nbest */
        "movl %esi, (%eax, %ecx)\n"
        "addl $1, -0x14(%ebp)\n" /* line 119 | used */
        /* } scope */
        ".Lf1f51a6_001f52a1:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 100 | i */
        "movl -0x1c(%ebp), %eax\n" /* i */
        "cmpl %eax, 0x14(%ebp)\n" /* entries */
        "jne .Lf1f51a6_001f51f0\n"
        /* } scope */
        ".Lf1f51a6_001f52b1:\n"
        "addl $0x1c, %esp\n" /* line 122 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f51a6_001f52b9:\n"
        "xorl %eax, %eax\n" /* line 110 */
        "movaps %xmm4, %xmm1\n"
        "movl 8(%ebp), %ecx\n" /* in */
        "movl 0xc(%ebp), %esi\n" /* codebook */
        ".Lf1f51a6_001f52c4:\n"
        "movss (%ecx, %eax, 4), %xmm0\n" /* line 104 */
        "mulss (%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $4, %esi\n"
        "movl %esi, 0xc(%ebp)\n" /* codebook */
        "addl $1, %eax\n" /* line 103 */
        "cmpl %eax, 0x10(%ebp)\n" /* len */
        "jne .Lf1f51a6_001f52c4\n"
        "jmp .Lf1f51a6_001f51fe\n"
        ".Lf1f51a6_001f52e4:\n"
        "movl -0x10(%ebp), %eax\n" /* line 112 */
        "jmp .Lf1f51a6_001f528c\n"
    );
}

/* line 130 */
__attribute__((naked))
long int vq_nbest_sign(spx_word16_t *in, const spx_word16_t *codebook, int len, int entries, spx_word32_t *E, int N, int *nbest, spx_word32_t *best_dist, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 130 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "movl 0x14(%ebp), %eax\n" /* line 134 | entries */
        "testl %eax, %eax\n"
        "jle .Lf1f52ea_001f5410\n"
        /* { scope 2 */
        "movl 0x1c(%ebp), %eax\n" /* line 154 | N */
        "subl $1, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "shll $2, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 152 | N */
        "movl 0x24(%ebp), %ecx\n" /* best_dist */
        "leal -4(%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl $0, -0x18(%ebp)\n" /* used */
        "movl $0, -0x20(%ebp)\n" /* i */
        "pxor %xmm3, %xmm3\n"
        "movss 0x2ed5d8, %xmm4\n" /* 0.5f */
        ".Lf1f52ea_001f5334:\n"
        "movl 0x10(%ebp), %esi\n" /* line 137 | len */
        "testl %esi, %esi\n"
        "jg .Lf1f52ea_001f5418\n"
        "movaps %xmm3, %xmm1\n"
        ".Lf1f52ea_001f5342:\n"
        "movl $1, -0x1c(%ebp)\n" /* sign */
        ".Lf1f52ea_001f5349:\n"
        "movl -0x20(%ebp), %eax\n" /* line 150 | i */
        "movl 0x18(%ebp), %edx\n" /* E */
        "movss (%edx, %eax, 4), %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 152 | N */
        "cmpl %ecx, %eax\n"
        "jl .Lf1f52ea_001f5373\n"
        "movl -0x24(%ebp), %esi\n"
        "movss (%esi), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf1f52ea_001f5400\n"
        ".Lf1f52ea_001f5373:\n"
        "movl -0x10(%ebp), %eax\n" /* line 154 */
        "testl %eax, %eax\n"
        "jle .Lf1f52ea_001f545a\n"
        "movl 0x24(%ebp), %eax\n" /* line 130 | best_dist */
        "addl -0x14(%ebp), %eax\n"
        "leal -4(%eax), %ebx\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x14(%ebp), %edx\n"
        "movl -0x10(%ebp), %ecx\n"
        "xorl %edi, %edi\n"
        ".Lf1f52ea_001f5392:\n"
        "cmpl %ecx, -0x18(%ebp)\n" /* line 154 | used */
        "jl .Lf1f52ea_001f53a6\n"
        "movl %edx, %eax\n"
        "movl -0x2c(%ebp), %esi\n"
        "movss -4(%esi), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf1f52ea_001f53db\n"
        ".Lf1f52ea_001f53a6:\n"
        "movss (%ebx), %xmm0\n" /* line 156 */
        "movl 0x24(%ebp), %eax\n" /* best_dist */
        "movss %xmm0, (%eax, %edx)\n"
        "movl 0x20(%ebp), %eax\n" /* line 157 | nbest */
        "movl -4(%eax, %edx), %eax\n"
        "movl 0x20(%ebp), %esi\n" /* nbest */
        "movl %eax, (%esi, %edx)\n"
        "subl $1, %ecx\n" /* line 154 */
        "addl $1, %edi\n"
        "subl $4, %ebx\n"
        "subl $4, -0x2c(%ebp)\n"
        "subl $4, %edx\n"
        "cmpl %edi, -0x10(%ebp)\n"
        "jne .Lf1f52ea_001f5392\n"
        "leal (, %ecx, 4), %eax\n"
        ".Lf1f52ea_001f53db:\n"
        "movl 0x24(%ebp), %edx\n" /* line 159 | best_dist */
        "movss %xmm2, (%eax, %edx)\n"
        "movl 0x20(%ebp), %ecx\n" /* line 160 | nbest */
        "leal (%eax, %ecx), %edx\n"
        "movl -0x20(%ebp), %esi\n" /* i */
        "movl %esi, (%edx)\n"
        "addl $1, -0x18(%ebp)\n" /* line 161 | used */
        "movl -0x1c(%ebp), %edi\n" /* line 162 | sign */
        "testl %edi, %edi\n"
        "je .Lf1f52ea_001f5400\n"
        "movl 0x14(%ebp), %eax\n" /* line 163 | entries */
        "addl %esi, %eax\n"
        "movl %eax, (%edx)\n"
        /* } scope */
        ".Lf1f52ea_001f5400:\n"
        "addl $1, -0x20(%ebp)\n" /* line 134 | i */
        "movl -0x20(%ebp), %eax\n" /* i */
        "cmpl %eax, 0x14(%ebp)\n" /* entries */
        "jne .Lf1f52ea_001f5334\n"
        /* } scope */
        ".Lf1f52ea_001f5410:\n"
        "addl $0x20, %esp\n" /* line 166 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f52ea_001f5418:\n"
        "xorl %eax, %eax\n" /* line 152 */
        "movaps %xmm3, %xmm1\n"
        "movl 8(%ebp), %ecx\n" /* in */
        "movl 0xc(%ebp), %esi\n" /* codebook */
        ".Lf1f52ea_001f5423:\n"
        "movss (%ecx, %eax, 4), %xmm0\n" /* line 138 */
        "mulss (%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $4, %esi\n"
        "movl %esi, 0xc(%ebp)\n" /* codebook */
        "addl $1, %eax\n" /* line 137 */
        "cmpl %eax, 0x10(%ebp)\n" /* len */
        "jne .Lf1f52ea_001f5423\n"
        "ucomiss %xmm3, %xmm1\n" /* line 139 */
        "jbe .Lf1f52ea_001f5342\n"
        "xorps 0x306aa0, %xmm1\n" /* line 142 */
        "movl $0, -0x1c(%ebp)\n" /* sign */
        "jmp .Lf1f52ea_001f5349\n"
        ".Lf1f52ea_001f545a:\n"
        "movl -0x14(%ebp), %eax\n" /* line 154 */
        "jmp .Lf1f52ea_001f53db\n"
    );
}

