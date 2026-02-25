/* ASM dump from: filters.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/filters.c */

#include "common_types.h"
#include "imports.h"

void bw_lpc(spx_word16_t gamma, const spx_coef_t *lpc_in, spx_coef_t *lpc_out, int order);
void signal_mul(const spx_sig_t *x, spx_sig_t *y, spx_word32_t scale, int len);
void signal_div(const spx_sig_t *x, spx_sig_t *y, spx_word32_t scale, int len);
spx_word16_t compute_rms(const spx_sig_t *x, int len);
void filter_mem2(const spx_sig_t *x, const spx_coef_t *num, const spx_coef_t *den, spx_sig_t *y, int N, int ord, spx_mem_t *mem);
void iir_mem2(const spx_sig_t *x, const spx_coef_t *den, spx_sig_t *y, int N, int ord, spx_mem_t *mem);
void fir_mem2(const spx_sig_t *x, const spx_coef_t *num, spx_sig_t *y, int N, int ord, spx_mem_t *mem);
void compute_impulse_response(const spx_coef_t *ak, const spx_coef_t *awk1, const spx_coef_t *awk2, spx_word16_t *y, int N, int ord, char *stack);
void qmf_decomp(const spx_word16_t *xx, const spx_word16_t *aa, spx_sig_t *y1, spx_sig_t *y2, int N, int M, spx_word16_t *mem, char *stack);
void fir_mem_up(const spx_sig_t *x, const spx_word16_t *a, spx_sig_t *y, int N, int M, spx_word32_t *mem, char *stack);
void comb_filter_mem_init(CombFilterMem *mem);
void comb_filter(spx_sig_t *exc, spx_sig_t *new_exc, spx_coef_t *ak, int p, int nsf, int pitch, spx_word16_t *pitch_gain, spx_word16_t comb_gain, CombFilterMem *mem);
void syn_percep_zero(const spx_sig_t *xx, const spx_coef_t *ak, const spx_coef_t *awk1, const spx_coef_t *awk2, spx_sig_t *y, int N, int ord, char *stack);
void residue_percep_zero(const spx_sig_t *xx, const spx_coef_t *ak, const spx_coef_t *awk1, const spx_coef_t *awk2, spx_sig_t *y, int N, int ord, char *stack);

/* line 52 */
__attribute__((naked))
void bw_lpc(spx_word16_t gamma, const spx_coef_t *lpc_in, spx_coef_t *lpc_out, int order)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 52 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movss 8(%ebp), %xmm2\n" /* gamma */
        "movl 0xc(%ebp), %ebx\n" /* lpc_in */
        "movl 0x10(%ebp), %ecx\n" /* lpc_out */
        "movl 0x14(%ebp), %edx\n" /* order */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 56 */
        "jle .Lf1ee9b8_001ee9eb\n"
        "movaps %xmm2, %xmm1\n"
        "xorl %eax, %eax\n"
        ".Lf1ee9b8_001ee9d3:\n"
        "movaps %xmm1, %xmm0\n" /* line 58 */
        "mulss (%ebx, %eax, 4), %xmm0\n" /* lpc_in */
        "movss %xmm0, (%ecx, %eax, 4)\n"
        "mulss %xmm2, %xmm1\n" /* line 59 */
        "addl $1, %eax\n" /* line 56 */
        "cmpl %eax, %edx\n"
        "jne .Lf1ee9b8_001ee9d3\n"
        /* } scope */
        ".Lf1ee9b8_001ee9eb:\n"
        "popl %ebx\n" /* line 61 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 101 */
__attribute__((naked))
void signal_mul(const spx_sig_t *x, spx_sig_t *y, spx_word32_t scale, int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* x */
        "movl 0xc(%ebp), %ecx\n" /* y */
        "movss 0x10(%ebp), %xmm1\n" /* scale */
        "movl 0x14(%ebp), %edx\n" /* len */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 104 */
        "jle .Lf1ee9ee_001eea1a\n"
        "xorl %eax, %eax\n"
        ".Lf1ee9ee_001eea06:\n"
        "movaps %xmm1, %xmm0\n" /* line 105 */
        "mulss (%ebx, %eax, 4), %xmm0\n" /* x */
        "movss %xmm0, (%ecx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 104 */
        "cmpl %eax, %edx\n"
        "jne .Lf1ee9ee_001eea06\n"
        /* } scope */
        ".Lf1ee9ee_001eea1a:\n"
        "popl %ebx\n" /* line 106 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 108 */
__attribute__((naked))
void signal_div(const spx_sig_t *x, spx_sig_t *y, spx_word32_t scale, int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 108 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* x */
        "movl 0xc(%ebp), %ecx\n" /* y */
        "movl 0x14(%ebp), %edx\n" /* len */
        /* { scope 1 */
        "movss 0x2ed5d0, %xmm1\n" /* line 111 | 1.0f, scale_1 */
        "divss 0x10(%ebp), %xmm1\n" /* scale, scale_1 */
        "testl %edx, %edx\n" /* line 112 */
        "jle .Lf1eea1e_001eea52\n"
        "xorl %eax, %eax\n"
        ".Lf1eea1e_001eea3e:\n"
        "movaps %xmm1, %xmm0\n" /* line 113 */
        "mulss (%ebx, %eax, 4), %xmm0\n" /* x */
        "movss %xmm0, (%ecx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 112 */
        "cmpl %eax, %edx\n"
        "jne .Lf1eea1e_001eea3e\n"
        /* } scope */
        ".Lf1eea1e_001eea52:\n"
        "popl %ebx\n" /* line 114 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 197 */
__attribute__((naked))
spx_word16_t compute_rms(const spx_sig_t *x, int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 197 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %ecx\n" /* x */
        "movl 0xc(%ebp), %edx\n" /* len */
        /* { scope 1 */
        "pxor %xmm1, %xmm1\n" /* line 201 */
        "testl %edx, %edx\n"
        "jle .Lf1eea56_001eea84\n"
        "xorl %eax, %eax\n"
        "pxor %xmm1, %xmm1\n"
        ".Lf1eea56_001eea70:\n"
        "movss (%ecx, %eax, 4), %xmm0\n" /* line 203 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %eax\n" /* line 201 */
        "cmpl %eax, %edx\n"
        "jne .Lf1eea56_001eea70\n"
        ".Lf1eea56_001eea84:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 205 */
        "divss %xmm0, %xmm1\n"
        "cvtss2sd %xmm1, %xmm0\n"
        "addsd 0x307d10, %xmm0\n" /* 0.1 */
        "sqrtsd %xmm0, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%ebp)\n"
        /* } scope */
        "flds -4(%ebp)\n" /* line 206 */
        "leave\n"
        "retl\n"
    );
}

/* line 232 */
__attribute__((naked))
void filter_mem2(const spx_sig_t *x, const spx_coef_t *num, const spx_coef_t *den, spx_sig_t *y, int N, int ord, spx_mem_t *mem)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 232 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0x1c(%ebp), %eax\n" /* ord */
        "movl 0x20(%ebp), %edi\n" /* mem */
        /* { scope 1 */
        "movl 0x18(%ebp), %edx\n" /* line 237 | N */
        "testl %edx, %edx\n"
        "jle .Lf1eeaaa_001eeb7f\n"
        "leal -1(%eax), %esi\n"
        "shll $2, %eax\n" /* line 246 */
        "leal -4(%edi, %eax), %edx\n" /* mem */
        "movl %edx, -0x18(%ebp)\n"
        "movl 0xc(%ebp), %ebx\n" /* num */
        "leal -4(%eax, %ebx), %ebx\n"
        "movl %ebx, -0x14(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* den */
        "leal -4(%eax, %edx), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* i */
        "movss 0x305840, %xmm5\n"
        "movl -0x1c(%ebp), %ebx\n" /* i */
        ".Lf1eeaaa_001eeaf7:\n"
        "movl 8(%ebp), %eax\n" /* line 239 | x */
        "movss (%eax, %ebx, 4), %xmm2\n"
        "movaps %xmm2, %xmm3\n" /* line 240 */
        "addss (%edi), %xmm3\n" /* mem */
        "movaps %xmm3, %xmm4\n" /* line 241 */
        "xorps %xmm5, %xmm4\n"
        "testl %esi, %esi\n" /* line 242 */
        "jle .Lf1eeaaa_001eeb46\n"
        "xorl %ecx, %ecx\n"
        ".Lf1eeaaa_001eeb12:\n"
        "leal (, %ecx, 4), %eax\n" /* line 232 | ord */
        "leal (%edi, %eax), %edx\n" /* mem */
        "movaps %xmm2, %xmm0\n" /* line 244 */
        "movl 0xc(%ebp), %ebx\n" /* num */
        "mulss (%eax, %ebx), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "movl 0x10(%ebp), %ebx\n" /* den */
        "mulss (%eax, %ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 242 */
        "cmpl %esi, %ecx\n"
        "jne .Lf1eeaaa_001eeb12\n"
        ".Lf1eeaaa_001eeb46:\n"
        "movl -0x14(%ebp), %eax\n" /* line 246 */
        "mulss (%eax), %xmm2\n"
        "movaps %xmm3, %xmm0\n"
        "movl -0x10(%ebp), %edx\n"
        "mulss (%edx), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movl -0x18(%ebp), %ebx\n"
        "movss %xmm2, (%ebx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 247 | i */
        "movl 0x14(%ebp), %edx\n" /* y */
        "movss %xmm3, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 237 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        "cmpl %eax, 0x18(%ebp)\n" /* N */
        "je .Lf1eeaaa_001eeb7f\n"
        "movl %eax, %ebx\n"
        "jmp .Lf1eeaaa_001eeaf7\n"
        /* } scope */
        ".Lf1eeaaa_001eeb7f:\n"
        "addl $0x10, %esp\n" /* line 249 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 273 */
__attribute__((naked))
void iir_mem2(const spx_sig_t *x, const spx_coef_t *den, spx_sig_t *y, int N, int ord, spx_mem_t *mem)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* den */
        "movl 0x18(%ebp), %eax\n" /* ord */
        "movl 0x1c(%ebp), %edi\n" /* mem */
        /* { scope 1 */
        "movl 0x14(%ebp), %ecx\n" /* line 278 | N */
        "testl %ecx, %ecx\n"
        "jle .Lf1eeb88_001eec15\n"
        "leal -1(%eax), %ebx\n"
        "shll $2, %eax\n" /* line 287 */
        "leal -4(%edi, %eax), %edx\n" /* mem */
        "movl %edx, -0x14(%ebp)\n"
        "leal -4(%eax, %esi), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "xorl %eax, %eax\n"
        "movss 0x305850, %xmm3\n"
        ".Lf1eeb88_001eebbf:\n"
        "movl 8(%ebp), %edx\n" /* line 281 | x */
        "movss (%edx, %eax, 4), %xmm1\n"
        "addss (%edi), %xmm1\n" /* mem */
        "movaps %xmm1, %xmm2\n" /* line 282 */
        "xorps %xmm3, %xmm2\n"
        "testl %ebx, %ebx\n" /* line 283 */
        "jle .Lf1eeb88_001eebf4\n"
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n" /* mem */
        ".Lf1eeb88_001eebd9:\n"
        "movaps %xmm2, %xmm0\n" /* line 285 */
        "mulss (%esi, %ecx, 4), %xmm0\n" /* den */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 283 */
        "addl $4, %edx\n"
        "cmpl %ebx, %ecx\n"
        "jne .Lf1eeb88_001eebd9\n"
        ".Lf1eeb88_001eebf4:\n"
        "movaps %xmm2, %xmm0\n" /* line 287 */
        "movl -0x10(%ebp), %edx\n"
        "mulss (%edx), %xmm0\n"
        "movl -0x14(%ebp), %edx\n"
        "movss %xmm0, (%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 288 | y */
        "movss %xmm1, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 278 */
        "cmpl %eax, 0x14(%ebp)\n" /* N */
        "jne .Lf1eeb88_001eebbf\n"
        /* } scope */
        ".Lf1eeb88_001eec15:\n"
        "addl $8, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 314 */
__attribute__((naked))
void fir_mem2(const spx_sig_t *x, const spx_coef_t *num, spx_sig_t *y, int N, int ord, spx_mem_t *mem)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 314 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* num */
        "movl 0x18(%ebp), %eax\n" /* ord */
        "movl 0x1c(%ebp), %edi\n" /* mem */
        /* { scope 1 */
        "movl 0x14(%ebp), %ebx\n" /* line 319 | N */
        "testl %ebx, %ebx\n"
        "jle .Lf1eec1e_001eec9d\n"
        "leal -1(%eax), %ebx\n"
        "shll $2, %eax\n" /* line 327 */
        "leal -4(%edi, %eax), %edx\n" /* mem */
        "movl %edx, -0x14(%ebp)\n"
        "leal -4(%eax, %esi), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "xorl %eax, %eax\n"
        ".Lf1eec1e_001eec4d:\n"
        "movl 8(%ebp), %edx\n" /* line 321 | x */
        "movss (%edx, %eax, 4), %xmm1\n"
        "movaps %xmm1, %xmm2\n" /* line 322 */
        "addss (%edi), %xmm2\n" /* mem */
        "testl %ebx, %ebx\n" /* line 323 */
        "jle .Lf1eec1e_001eec7f\n"
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n" /* mem */
        ".Lf1eec1e_001eec64:\n"
        "movaps %xmm1, %xmm0\n" /* line 325 */
        "mulss (%esi, %ecx, 4), %xmm0\n" /* num */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 323 */
        "addl $4, %edx\n"
        "cmpl %ebx, %ecx\n"
        "jne .Lf1eec1e_001eec64\n"
        ".Lf1eec1e_001eec7f:\n"
        "movl -0x10(%ebp), %edx\n" /* line 327 */
        "mulss (%edx), %xmm1\n"
        "movl -0x14(%ebp), %edx\n"
        "movss %xmm1, (%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 328 | y */
        "movss %xmm2, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 319 */
        "cmpl %eax, 0x14(%ebp)\n" /* N */
        "jne .Lf1eec1e_001eec4d\n"
        /* } scope */
        ".Lf1eec1e_001eec9d:\n"
        "addl $8, %esp\n" /* line 330 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 367 */
__attribute__((naked))
void compute_impulse_response(const spx_coef_t *ak, const spx_coef_t *awk1, const spx_coef_t *awk2, spx_word16_t *y, int N, int ord, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 367 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0x1c(%ebp), %ebx\n" /* ord */
        "movl 0x20(%ebp), %edx\n" /* stack */
        /* { scope 1 */
        "movl $4, %ecx\n" /* line 373 */
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, %edi\n" /* mem1 */
        "subl %eax, %edi\n" /* mem1 */
        "subl %edx, %ecx\n" /* line 374 */
        "andl $3, %ecx\n"
        "leal (%edx, %ecx), %esi\n" /* mem2 */
        "movl 0x14(%ebp), %eax\n" /* line 376 | y */
        "movl $0x3f800000, (%eax)\n"
        "testl %ebx, %ebx\n" /* line 377 | ord */
        "jg .Lf1eeca6_001eee31\n"
        "movl $1, -0x28(%ebp)\n"
        "movl -0x28(%ebp), %edx\n"
        ".Lf1eeca6_001eecf3:\n"
        "cmpl %edx, 0x18(%ebp)\n" /* line 380 | N */
        "jle .Lf1eeca6_001eed1a\n"
        "movl 0x14(%ebp), %ecx\n" /* y */
        "leal (%ecx, %edx, 4), %eax\n"
        "xorl %edx, %edx\n"
        "movl 0x18(%ebp), %ecx\n" /* N */
        "subl -0x28(%ebp), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        ".Lf1eeca6_001eed09:\n"
        "movl $0x26901d7d, (%eax)\n" /* line 381 */
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl -0x28(%ebp), %edx\n" /* line 380 */
        "jne .Lf1eeca6_001eed09\n"
        ".Lf1eeca6_001eed1a:\n"
        "testl %ebx, %ebx\n" /* line 383 | ord */
        "jle .Lf1eeca6_001eed3c\n"
        "xorl %edx, %edx\n"
        ".Lf1eeca6_001eed20:\n"
        "leal (, %edx, 4), %eax\n" /* line 367 */
        "movl $0, (%esi, %eax)\n" /* line 384 | mem2 */
        "movl $0, (%edi, %eax)\n" /* mem1 */
        "addl $1, %edx\n" /* line 383 */
        "cmpl %edx, %ebx\n" /* ord */
        "jne .Lf1eeca6_001eed20\n"
        ".Lf1eeca6_001eed3c:\n"
        "movl 0x18(%ebp), %eax\n" /* line 385 | N */
        "testl %eax, %eax\n"
        "jle .Lf1eeca6_001eee29\n"
        "leal -1(%ebx), %eax\n" /* ord */
        "movl %eax, -0x14(%ebp)\n"
        "leal (, %ebx, 4), %eax\n" /* line 396 */
        "leal -4(%edi, %eax), %edx\n" /* mem1 */
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* awk2 */
        "leal -4(%eax, %ecx), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "leal -4(%esi, %eax), %ebx\n" /* line 397 | mem2, ord */
        "movl %ebx, -0x1c(%ebp)\n" /* ord */
        "movl 8(%ebp), %edx\n" /* ak */
        "leal -4(%eax, %edx), %eax\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl $0, -0x10(%ebp)\n"
        "movss 0x305860, %xmm3\n"
        "movl 0x14(%ebp), %ecx\n" /* y */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl %ecx, %ebx\n" /* ord */
        ".Lf1eeca6_001eed8d:\n"
        "movss (%ebx), %xmm0\n" /* line 387 | ord */
        "addss (%edi), %xmm0\n" /* mem1 */
        "movaps %xmm0, %xmm2\n" /* line 388 */
        "xorps %xmm3, %xmm2\n"
        "addss (%esi), %xmm0\n" /* line 389 | mem2 */
        "movss %xmm0, (%ebx)\n" /* ord */
        "movaps %xmm0, %xmm1\n" /* line 390 */
        "xorps %xmm3, %xmm1\n"
        "movl -0x14(%ebp), %eax\n" /* line 391 */
        "testl %eax, %eax\n"
        "jle .Lf1eeca6_001eedef\n"
        "xorl %ecx, %ecx\n"
        ".Lf1eeca6_001eedb2:\n"
        "leal (, %ecx, 4), %eax\n" /* line 367 */
        "leal (%edi, %eax), %edx\n" /* stack */
        "movaps %xmm2, %xmm0\n" /* line 393 */
        "movl 0x10(%ebp), %ebx\n" /* awk2, ord */
        "mulss (%eax, %ebx), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "leal (%esi, %eax), %edx\n" /* line 367 | stack */
        "movaps %xmm1, %xmm0\n" /* line 394 */
        "movl 8(%ebp), %ebx\n" /* ak, ord */
        "mulss (%eax, %ebx), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 391 */
        "cmpl %ecx, -0x14(%ebp)\n"
        "jne .Lf1eeca6_001eedb2\n"
        ".Lf1eeca6_001eedef:\n"
        "movaps %xmm2, %xmm0\n" /* line 396 */
        "movl -0x20(%ebp), %eax\n"
        "mulss (%eax), %xmm0\n"
        "movl -0x24(%ebp), %edx\n"
        "movss %xmm0, (%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 397 */
        "movl -0x18(%ebp), %ecx\n"
        "mulss (%ecx), %xmm0\n"
        "movl -0x1c(%ebp), %ebx\n" /* ord */
        "movss %xmm0, (%ebx)\n" /* ord */
        "addl $1, -0x10(%ebp)\n" /* line 385 */
        "addl $4, -0x2c(%ebp)\n"
        "movl -0x10(%ebp), %eax\n"
        "cmpl %eax, 0x18(%ebp)\n" /* N */
        "je .Lf1eeca6_001eee29\n"
        "movl -0x2c(%ebp), %ebx\n" /* ord */
        "jmp .Lf1eeca6_001eed8d\n"
        /* } scope */
        ".Lf1eeca6_001eee29:\n"
        "addl $0x20, %esp\n" /* line 399 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1eeca6_001eee31:\n"
        "xorl %edx, %edx\n" /* line 377 */
        ".Lf1eeca6_001eee33:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 378 | awk1 */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl 0x14(%ebp), %ecx\n" /* y */
        "movl %eax, 4(%ecx, %edx, 4)\n"
        "addl $1, %edx\n" /* line 377 */
        "cmpl %edx, %ebx\n" /* ord */
        "jne .Lf1eeca6_001eee33\n"
        "leal 1(%ebx), %eax\n" /* ord */
        "movl %eax, -0x28(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf1eeca6_001eecf3\n"
    );
}

/* line 401 */
__attribute__((naked))
void qmf_decomp(const spx_word16_t *xx, const spx_word16_t *aa, spx_sig_t *y1, spx_sig_t *y2, int N, int M, spx_word16_t *mem, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 401 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 0x1c(%ebp), %edi\n" /* M */
        "movl 0x24(%ebp), %eax\n" /* stack */
        /* { scope 1 */
        "movl $4, %ecx\n" /* line 408 */
        "movl %ecx, %edx\n"
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (, %edi, 4), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "addl %edx, %eax\n"
        "movl %eax, %ebx\n"
        "subl %edx, %ebx\n"
        "movl %ebx, -0x28(%ebp)\n" /* a */
        "subl %eax, %ecx\n" /* line 409 */
        "andl $3, %ecx\n"
        "leal (%eax, %ecx), %esi\n" /* x */
        "addl %esi, %edx\n" /* line 410 | x */
        "movl %edx, -0x34(%ebp)\n"
        "subl $4, %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* x2 */
        "movl %edi, %eax\n" /* line 411 | M */
        "sarl $1, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* M2 */
        "testl %edi, %edi\n" /* line 412 | M */
        "jle .Lf1eee54_001eeebc\n"
        "movl %ebx, %edx\n" /* line 401 */
        "addl -0x3c(%ebp), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1eee54_001eeea9:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 413 | aa */
        "movl (%ebx, %ecx, 4), %eax\n"
        "movl %eax, -4(%edx)\n"
        "addl $1, %ecx\n" /* line 412 */
        "subl $4, %edx\n"
        "cmpl %ecx, %edi\n" /* M */
        "jne .Lf1eee54_001eeea9\n"
        ".Lf1eee54_001eeebc:\n"
        "subl $1, %edi\n" /* line 415 | M */
        "movl %edi, -0x30(%ebp)\n" /* M */
        "testl %edi, %edi\n" /* M */
        "jle .Lf1eee54_001eeedf\n"
        "movl 0x20(%ebp), %edx\n" /* line 401 | mem */
        "addl -0x3c(%ebp), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1eee54_001eeece:\n"
        "movl -8(%edx), %eax\n" /* line 416 */
        "movl %eax, (%esi, %ecx, 4)\n" /* x */
        "addl $1, %ecx\n" /* line 415 */
        "subl $4, %edx\n"
        "cmpl %ecx, -0x30(%ebp)\n"
        "jne .Lf1eee54_001eeece\n"
        ".Lf1eee54_001eeedf:\n"
        "movl 0x18(%ebp), %eax\n" /* line 417 | N */
        "testl %eax, %eax\n"
        "jle .Lf1eee54_001ef005\n"
        "movl -0x34(%ebp), %edx\n" /* line 401 */
        "xorl %ecx, %ecx\n"
        ".Lf1eee54_001eeeef:\n"
        "movl 8(%ebp), %ebx\n" /* line 418 | xx */
        "movl (%ebx, %ecx, 4), %eax\n"
        "movl %eax, -4(%edx)\n"
        "addl $1, %ecx\n" /* line 417 */
        "addl $4, %edx\n"
        "cmpl %ecx, 0x18(%ebp)\n" /* N */
        "jne .Lf1eee54_001eeeef\n"
        "movl -0x24(%ebp), %eax\n" /* x2 */
        "movl %eax, -0x18(%ebp)\n"
        "movl %esi, -0x14(%ebp)\n" /* x */
        "movl $2, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n"
        ".Lf1eee54_001eef16:\n"
        "addl %eax, %eax\n" /* line 401 | stack */
        "movl 0x10(%ebp), %edx\n" /* y1 */
        "addl %eax, %edx\n" /* stack */
        "leal -4(%edx), %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl $0, -4(%edx)\n" /* line 421 */
        "addl 0x14(%ebp), %eax\n" /* line 401 | y2, stack */
        "leal -4(%eax), %edi\n" /* M */
        "movl $0, -4(%eax)\n" /* line 422 */
        "movl -0x2c(%ebp), %eax\n" /* line 423 | M2 */
        "testl %eax, %eax\n"
        "jle .Lf1eee54_001eefe8\n"
        "movl -0x14(%ebp), %esi\n" /* x */
        "movl -0x18(%ebp), %ebx\n"
        "movl %esi, %ecx\n" /* x */
        "movl %ebx, -0x38(%ebp)\n"
        "movl $2, -0x20(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* a */
        "addl $8, %eax\n"
        "jmp .Lf1eee54_001eef65\n"
        ".Lf1eee54_001eef5c:\n"
        "addl $2, %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "addl $8, %eax\n"
        ".Lf1eee54_001eef65:\n"
        "movss (%esi), %xmm0\n" /* line 425 | x */
        "addss (%ebx), %xmm0\n"
        "mulss -8(%eax), %xmm0\n"
        "movl -0x10(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%esi), %xmm1\n" /* line 426 | x */
        "subss (%ebx), %xmm1\n"
        "mulss -8(%eax), %xmm1\n"
        "movss (%edi), %xmm0\n" /* M */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%edi)\n" /* M */
        "movss 4(%ecx), %xmm0\n" /* line 428 */
        "movl -0x38(%ebp), %edx\n"
        "addss -4(%edx), %xmm0\n"
        "mulss -4(%eax), %xmm0\n"
        "movl -0x10(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss 4(%ecx), %xmm0\n" /* line 429 */
        "movl -0x38(%ebp), %edx\n"
        "subss -4(%edx), %xmm0\n"
        "mulss -4(%eax), %xmm0\n"
        "addss (%edi), %xmm0\n" /* M */
        "movss %xmm0, (%edi)\n" /* M */
        "addl $8, %esi\n" /* x */
        "subl $8, %ebx\n"
        "addl $8, %ecx\n"
        "subl $8, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl -0x20(%ebp), %edx\n" /* line 423 */
        "cmpl %edx, -0x2c(%ebp)\n" /* M2 */
        "jg .Lf1eee54_001eef5c\n"
        ".Lf1eee54_001eefe8:\n"
        "addl $8, -0x18(%ebp)\n"
        "addl $8, -0x14(%ebp)\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 419 */
        "cmpl %ecx, 0x18(%ebp)\n" /* N */
        "jle .Lf1eee54_001ef005\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf1eee54_001eef16\n"
        ".Lf1eee54_001ef005:\n"
        "movl -0x30(%ebp), %eax\n" /* line 432 */
        "testl %eax, %eax\n"
        "jle .Lf1eee54_001ef02b\n"
        "movl 0x18(%ebp), %ebx\n" /* line 401 | N */
        "movl 8(%ebp), %eax\n" /* xx, stack */
        "leal (%eax, %ebx, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1eee54_001ef017:\n"
        "movl -4(%edx), %eax\n" /* line 433 */
        "movl 0x20(%ebp), %ebx\n" /* mem */
        "movl %eax, (%ebx, %ecx, 4)\n"
        "addl $1, %ecx\n" /* line 432 */
        "subl $4, %edx\n"
        "cmpl -0x30(%ebp), %ecx\n"
        "jne .Lf1eee54_001ef017\n"
        /* } scope */
        ".Lf1eee54_001ef02b:\n"
        "addl $0x30, %esp\n" /* line 434 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 438 */
__attribute__((naked))
void fir_mem_up(const spx_sig_t *x, const spx_word16_t *a, spx_sig_t *y, int N, int M, spx_word32_t *mem, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 438 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 0x20(%ebp), %eax\n" /* stack */
        /* { scope 1 */
        "movl %eax, %edx\n" /* line 446 */
        "negl %edx\n"
        "andl $3, %edx\n"
        "leal (%eax, %edx), %edx\n"
        "movl %edx, -0x18(%ebp)\n" /* xx */
        "movl 0x14(%ebp), %eax\n" /* line 448 | N */
        "shrl $0x1f, %eax\n"
        "movl 0x14(%ebp), %edx\n" /* N */
        "leal (%eax, %edx), %ebx\n"
        "sarl $1, %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf1ef034_001ef07a\n"
        "movl 8(%ebp), %ecx\n" /* line 438 | x */
        "leal (%ecx, %ebx, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ef034_001ef067:\n"
        "movl -4(%edx), %eax\n" /* line 449 */
        "movl -0x18(%ebp), %esi\n" /* xx */
        "movl %eax, (%esi, %ecx, 8)\n"
        "addl $1, %ecx\n" /* line 448 */
        "subl $4, %edx\n"
        "cmpl %ecx, %ebx\n"
        "jne .Lf1ef034_001ef067\n"
        ".Lf1ef034_001ef07a:\n"
        "movl 0x18(%ebp), %edi\n" /* line 450 | M */
        "subl $1, %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf1ef034_001ef0a2\n"
        "movl 0x14(%ebp), %eax\n" /* N */
        "movl -0x18(%ebp), %ecx\n" /* xx */
        "leal (%ecx, %eax, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ef034_001ef08f:\n"
        "movl 0x1c(%ebp), %ebx\n" /* line 451 | mem */
        "movl 4(%ebx, %ecx, 4), %eax\n"
        "movl %eax, (%edx)\n"
        "addl $2, %ecx\n" /* line 450 */
        "addl $8, %edx\n"
        "cmpl %ecx, %edi\n"
        "jg .Lf1ef034_001ef08f\n"
        ".Lf1ef034_001ef0a2:\n"
        "movl 0x14(%ebp), %edx\n" /* line 453 | N */
        "testl %edx, %edx\n"
        "jle .Lf1ef034_001ef19b\n"
        "movl 0x14(%ebp), %eax\n" /* line 438 | N, stack */
        "movl -0x18(%ebp), %edx\n" /* xx */
        "leal (%edx, %eax, 4), %esi\n"
        "movl $0, -0x10(%ebp)\n"
        "movl 0x10(%ebp), %ebx\n" /* y */
        /* { scope 2 */
        ".Lf1ef034_001ef0c0:\n"
        "movss -0x10(%esi), %xmm4\n" /* line 458 */
        "movl 0x18(%ebp), %eax\n" /* line 460 | M */
        "testl %eax, %eax\n"
        "jle .Lf1ef034_001ef1c4\n"
        "leal -8(%esi), %edx\n"
        "xorl %ecx, %ecx\n"
        "pxor %xmm5, %xmm5\n"
        "movss %xmm5, -0x14(%ebp)\n"
        "movaps %xmm5, %xmm7\n"
        "movaps %xmm5, %xmm6\n"
        "movl 0xc(%ebp), %eax\n" /* a */
        /* { scope 3 */
        ".Lf1ef034_001ef0e7:\n"
        "movss (%eax), %xmm1\n" /* line 464 */
        "movss 4(%eax), %xmm3\n" /* line 465 */
        "movss (%edx), %xmm2\n" /* line 466 */
        "movaps %xmm1, %xmm0\n" /* line 468 */
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm6\n"
        "movaps %xmm3, %xmm0\n" /* line 469 */
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm7\n"
        "mulss %xmm4, %xmm1\n" /* line 470 */
        "addss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "mulss %xmm3, %xmm4\n" /* line 471 */
        "addss %xmm4, %xmm5\n"
        "movss 8(%eax), %xmm1\n" /* line 473 */
        "movss 0xc(%eax), %xmm3\n" /* line 474 */
        "movss 8(%edx), %xmm4\n" /* line 475 */
        "movaps %xmm1, %xmm0\n" /* line 477 */
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm6\n"
        "movaps %xmm3, %xmm0\n" /* line 478 */
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm7\n"
        "mulss %xmm2, %xmm1\n" /* line 479 */
        "addss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, -0x14(%ebp)\n"
        "mulss %xmm3, %xmm2\n" /* line 480 */
        "addss %xmm2, %xmm5\n"
        /* } scope */
        "addl $4, %ecx\n" /* line 460 */
        "addl $0x10, %eax\n"
        "addl $0x10, %edx\n"
        "cmpl %ecx, 0x18(%ebp)\n" /* M */
        "jg .Lf1ef034_001ef0e7\n"
        ".Lf1ef034_001ef16d:\n"
        "movss %xmm6, (%ebx)\n" /* line 482 */
        "movss %xmm7, 4(%ebx)\n" /* line 483 */
        "movss -0x14(%ebp), %xmm0\n" /* line 484 */
        "movss %xmm0, 8(%ebx)\n"
        "movss %xmm5, 0xc(%ebx)\n" /* line 485 */
        /* } scope */
        "addl $4, -0x10(%ebp)\n" /* line 453 */
        "addl $0x10, %ebx\n"
        "subl $0x10, %esi\n"
        "movl -0x10(%ebp), %eax\n"
        "cmpl %eax, 0x14(%ebp)\n" /* N */
        "jg .Lf1ef034_001ef0c0\n"
        ".Lf1ef034_001ef19b:\n"
        "testl %edi, %edi\n" /* line 488 */
        "jle .Lf1ef034_001ef1bc\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ef034_001ef1a1:\n"
        "leal (, %ecx, 4), %edx\n" /* line 438 */
        "movl -0x18(%ebp), %ebx\n" /* line 489 | xx */
        "movl (%ebx, %edx), %eax\n"
        "movl 0x1c(%ebp), %esi\n" /* mem */
        "movl %eax, 4(%esi, %edx)\n"
        "addl $2, %ecx\n" /* line 488 */
        "cmpl %edi, %ecx\n"
        "jl .Lf1ef034_001ef1a1\n"
        /* } scope */
        ".Lf1ef034_001ef1bc:\n"
        "addl $0xc, %esp\n" /* line 490 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1ef034_001ef1c4:\n"
        "pxor %xmm5, %xmm5\n" /* line 460 */
        "movss %xmm5, -0x14(%ebp)\n"
        "movaps %xmm5, %xmm7\n"
        "movaps %xmm5, %xmm6\n"
        "jmp .Lf1ef034_001ef16d\n"
    );
}

/* line 494 */
__attribute__((naked))
void comb_filter_mem_init(CombFilterMem *mem)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 494 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* mem */
        "movl $0, (%edx)\n" /* line 496 */
        "xorl %eax, %eax\n" /* line 497 */
        "movl %eax, 0xc(%edx)\n"
        "movl %eax, 8(%edx)\n"
        "movl %eax, 4(%edx)\n"
        "movl $0x3f800000, 0x10(%edx)\n" /* line 498 */
        "popl %ebp\n" /* line 499 */
        "retl\n"
    );
}

/* line 517 */
__attribute__((naked))
void comb_filter(spx_sig_t *exc, spx_sig_t *new_exc, spx_coef_t *ak, int p, int nsf, int pitch, spx_word16_t *pitch_gain, spx_word16_t comb_gain, CombFilterMem *mem)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 517 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0x18(%ebp), %edi\n" /* nsf */
        "movss 0x24(%ebp), %xmm1\n" /* comb_gain */
        "movl 0x28(%ebp), %esi\n" /* mem */
        /* { scope 1 */
        /* { scope 2 */
        "pxor %xmm2, %xmm2\n" /* line 201 */
        "testl %edi, %edi\n"
        "jle .Lf1ef1f6_001ef22f\n"
        "xorl %eax, %eax\n"
        "pxor %xmm2, %xmm2\n"
        "movl 8(%ebp), %edx\n" /* exc */
        ".Lf1ef1f6_001ef21b:\n"
        "movss (%edx, %eax, 4), %xmm0\n" /* line 203 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $1, %eax\n" /* line 201 */
        "cmpl %eax, %edi\n"
        "jne .Lf1ef1f6_001ef21b\n"
        ".Lf1ef1f6_001ef22f:\n"
        "cvtsi2ssl %edi, %xmm0\n" /* line 205 */
        "movss %xmm0, -0x18(%ebp)\n"
        "divss %xmm0, %xmm2\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "addsd 0x307d10, %xmm0\n" /* 0.1 */
        "sqrtsd %xmm0, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* exc_energy */
        /* } scope */
        /* { scope 2 */
        "movl 0x20(%ebp), %eax\n" /* line 542 | pitch_gain */
        "addl $4, %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x20(%ebp), %edx\n" /* pitch_gain */
        "movss 4(%edx), %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1ef1f6_001ef520\n"
        "movl %edx, %eax\n"
        "cvtss2sd %xmm0, %xmm3\n"
        "movss (%eax), %xmm2\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1ef1f6_001ef53f\n"
        ".Lf1ef1f6_001ef28a:\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "addsd %xmm0, %xmm3\n"
        "movl 0x20(%ebp), %eax\n" /* pitch_gain */
        "addl $8, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x20(%ebp), %edx\n" /* pitch_gain */
        "movss 8(%edx), %xmm0\n"
        "pxor %xmm4, %xmm4\n"
        "ucomiss %xmm4, %xmm0\n"
        "jbe .Lf1ef1f6_001ef56d\n"
        ".Lf1ef1f6_001ef2b0:\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd %xmm0, %xmm3\n"
        "movss 8(%esi), %xmm6\n" /* mem */
        "movaps %xmm6, %xmm0\n"
        "pxor %xmm4, %xmm4\n"
        "ucomiss %xmm6, %xmm4\n"
        "ja .Lf1ef1f6_001ef592\n"
        ".Lf1ef1f6_001ef2cd:\n"
        "cvtss2sd %xmm0, %xmm5\n"
        "movss 4(%esi), %xmm4\n" /* mem */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "jbe .Lf1ef1f6_001ef5af\n"
        ".Lf1ef1f6_001ef2e3:\n"
        "cvtss2sd %xmm4, %xmm0\n"
        "movapd %xmm0, %xmm7\n"
        "addsd %xmm5, %xmm7\n"
        "movss 0xc(%esi), %xmm5\n" /* mem */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm5\n"
        "jbe .Lf1ef1f6_001ef5d5\n"
        ".Lf1ef1f6_001ef301:\n"
        "cvtss2sd %xmm5, %xmm0\n"
        ".Lf1ef1f6_001ef305:\n"
        "addsd %xmm7, %xmm0\n"
        "addsd %xmm0, %xmm3\n"
        "mulsd 0x307ce0, %xmm3\n" /* 0.5 */
        "cvtsd2ss %xmm3, %xmm7\n"
        "cvtss2sd %xmm7, %xmm3\n" /* line 543 */
        "movsd 0x307eb8, %xmm0\n" /* 1.3 */
        "ucomisd %xmm0, %xmm3\n"
        "jbe .Lf1ef1f6_001ef33b\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 544 */
        "divsd %xmm3, %xmm0\n"
        "mulsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        ".Lf1ef1f6_001ef33b:\n"
        "ucomiss 0x2ed5d8, %xmm7\n" /* line 545 | 0.5f */
        "jae .Lf1ef1f6_001ef356\n"
        "jp .Lf1ef1f6_001ef356\n"
        "cvtss2sd %xmm1, %xmm0\n" /* line 546 */
        "addsd %xmm3, %xmm3\n"
        "mulsd %xmm3, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm1\n"
        /* } scope */
        ".Lf1ef1f6_001ef356:\n"
        "cvtsi2sdl %edi, %xmm0\n" /* line 549 | nsf */
        "movsd 0x307c10, %xmm3\n" /* 1.0 */
        "divsd %xmm0, %xmm3\n"
        "cvtsd2ss %xmm3, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* step */
        "testl %edi, %edi\n" /* line 553 | nsf */
        "jle .Lf1ef1f6_001ef45b\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, -0x14(%ebp)\n"
        "movl 0x1c(%ebp), %eax\n" /* pitch */
        "shll $2, %eax\n"
        "movl 8(%ebp), %edx\n" /* exc */
        "subl %eax, %edx\n"
        "leal 4(%edx), %ecx\n"
        "pxor %xmm7, %xmm7\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf1ef1f6_001ef3ac\n"
        ".Lf1ef1f6_001ef396:\n"
        "movl 0x20(%ebp), %eax\n" /* pitch_gain */
        "movss (%eax), %xmm2\n"
        "movss 8(%esi), %xmm6\n" /* mem */
        "movss 4(%esi), %xmm4\n" /* mem */
        "movss 0xc(%esi), %xmm5\n" /* mem */
        ".Lf1ef1f6_001ef3ac:\n"
        "addss -0x1c(%ebp), %xmm7\n" /* line 557 | step */
        "movl %ebx, %eax\n" /* line 562 | i */
        "subl (%esi), %eax\n" /* mem */
        "movl 8(%ebp), %edx\n" /* exc */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "leal (, %ebx, 4), %eax\n" /* line 517 */
        "movl %eax, -0x2c(%ebp)\n"
        "cvtss2sd (%edx, %eax), %xmm3\n" /* line 566 */
        "mulss (%ecx), %xmm2\n"
        "movl -0x28(%ebp), %edx\n"
        "movss (%edx), %xmm0\n"
        "mulss -4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movl -0x24(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "mulss -8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss %xmm7, %xmm2\n"
        "cvtss2sd %xmm2, %xmm1\n"
        "cvtss2sd %xmm7, %xmm0\n"
        "movsd 0x307c10, %xmm2\n" /* 1.0 */
        "subsd %xmm0, %xmm2\n"
        "movl -0x30(%ebp), %edx\n"
        "mulss 4(%edx), %xmm4\n"
        "mulss (%edx), %xmm6\n"
        "addss %xmm6, %xmm4\n"
        "mulss -4(%edx), %xmm5\n"
        "addss %xmm5, %xmm4\n"
        "cvtss2sd %xmm4, %xmm0\n"
        "mulsd %xmm0, %xmm2\n"
        "addsd %xmm2, %xmm1\n"
        "mulsd -0x14(%ebp), %xmm1\n"
        "addsd %xmm1, %xmm3\n"
        "cvtsd2ss %xmm3, %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* new_exc */
        "movl -0x2c(%ebp), %edx\n"
        "movss %xmm0, (%eax, %edx)\n"
        "addl $1, %ebx\n" /* line 553 | i */
        "addl $4, %ecx\n"
        "cmpl %ebx, %edi\n" /* i, nsf */
        "jne .Lf1ef1f6_001ef396\n"
        "movl 0x20(%ebp), %eax\n" /* pitch_gain */
        "movss (%eax), %xmm2\n"
        ".Lf1ef1f6_001ef45b:\n"
        "movss %xmm2, 4(%esi)\n" /* line 569 | mem */
        "movl -0x28(%ebp), %edx\n" /* line 570 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esi)\n" /* mem */
        "movl -0x24(%ebp), %edx\n" /* line 571 */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* mem */
        "movl 0x1c(%ebp), %eax\n" /* line 572 | pitch */
        "movl %eax, (%esi)\n" /* mem */
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 201 */
        "testl %edi, %edi\n"
        "jle .Lf1ef1f6_001ef49a\n"
        "xorl %eax, %eax\n"
        "pxor %xmm1, %xmm1\n"
        "movl 0xc(%ebp), %edx\n" /* new_exc */
        ".Lf1ef1f6_001ef486:\n"
        "movss (%edx, %eax, 4), %xmm0\n" /* line 203 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %eax\n" /* line 201 */
        "cmpl %eax, %edi\n"
        "jne .Lf1ef1f6_001ef486\n"
        ".Lf1ef1f6_001ef49a:\n"
        "divss -0x18(%ebp), %xmm1\n" /* line 205 */
        "cvtss2sd %xmm1, %xmm0\n"
        "addsd 0x307d10, %xmm0\n" /* 0.1 */
        "sqrtsd %xmm0, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        /* } scope */
        "movaps %xmm0, %xmm1\n" /* line 577 */
        "minss -0x20(%ebp), %xmm1\n" /* exc_energy */
        "addss 0x2ed5d0, %xmm0\n" /* line 580 | 1.0f */
        "divss %xmm0, %xmm1\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 586 | 0.5f */
        "maxss %xmm1, %xmm0\n"
        "testl %edi, %edi\n" /* line 597 | nsf */
        "jle .Lf1ef1f6_001ef518\n"
        "cvtss2sd %xmm0, %xmm1\n"
        "mulsd 0x307ec0, %xmm1\n" /* 0.04 */
        "xorl %edx, %edx\n"
        "movsd 0x307ec8, %xmm2\n" /* 0.96 */
        "movl 0xc(%ebp), %eax\n" /* new_exc */
        ".Lf1ef1f6_001ef4f0:\n"
        "cvtss2sd 0x10(%esi), %xmm0\n" /* line 599 | mem */
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x10(%esi)\n" /* mem */
        "mulss (%eax), %xmm0\n" /* line 600 */
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 597 */
        "addl $4, %eax\n"
        "cmpl %edx, %edi\n" /* nsf */
        "jne .Lf1ef1f6_001ef4f0\n"
        /* } scope */
        ".Lf1ef1f6_001ef518:\n"
        "addl $0x24, %esp\n" /* line 603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1ef1f6_001ef520:\n"
        "xorps 0x305870, %xmm0\n" /* line 542 */
        "movl 0x20(%ebp), %eax\n" /* pitch_gain */
        "cvtss2sd %xmm0, %xmm3\n"
        "movss (%eax), %xmm2\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1ef1f6_001ef28a\n"
        ".Lf1ef1f6_001ef53f:\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "addsd %xmm0, %xmm3\n"
        "movl 0x20(%ebp), %eax\n" /* pitch_gain */
        "addl $8, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x20(%ebp), %edx\n" /* pitch_gain */
        "movss 8(%edx), %xmm0\n"
        "pxor %xmm4, %xmm4\n"
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lf1ef1f6_001ef2b0\n"
        ".Lf1ef1f6_001ef56d:\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "addsd %xmm0, %xmm3\n"
        "movss 8(%esi), %xmm6\n" /* mem */
        "movaps %xmm6, %xmm0\n"
        "pxor %xmm4, %xmm4\n"
        "ucomiss %xmm6, %xmm4\n"
        "jbe .Lf1ef1f6_001ef2cd\n"
        ".Lf1ef1f6_001ef592:\n"
        "xorps 0x305870, %xmm0\n"
        "cvtss2sd %xmm0, %xmm5\n"
        "movss 4(%esi), %xmm4\n" /* mem */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "ja .Lf1ef1f6_001ef2e3\n"
        ".Lf1ef1f6_001ef5af:\n"
        "cvtss2sd %xmm4, %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "movapd %xmm0, %xmm7\n"
        "addsd %xmm5, %xmm7\n"
        "movss 0xc(%esi), %xmm5\n" /* mem */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm5\n"
        "ja .Lf1ef1f6_001ef301\n"
        ".Lf1ef1f6_001ef5d5:\n"
        "cvtss2sd %xmm5, %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "jmp .Lf1ef1f6_001ef305\n"
    );
}

/* line 341 */
__attribute__((naked))
void syn_percep_zero(const spx_sig_t *xx, const spx_coef_t *ak, const spx_coef_t *awk1, const spx_coef_t *awk2, spx_sig_t *y, int N, int ord, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 341 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* ak */
        "movl 0x24(%ebp), %edx\n" /* stack */
        /* { scope 1: i */
        "movl %edx, %eax\n" /* line 345 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "leal (%edx, %eax), %ebx\n" /* mem */
        "movl 0x20(%ebp), %eax\n" /* line 346 | ord */
        "testl %eax, %eax\n"
        "jle .Lf1ef5e6_001ef617\n"
        "xorl %eax, %eax\n"
        ".Lf1ef5e6_001ef608:\n"
        "movl $0, (%ebx, %eax, 4)\n" /* line 347 | mem */
        "addl $1, %eax\n" /* line 346 */
        "cmpl %eax, 0x20(%ebp)\n" /* ord */
        "jne .Lf1ef5e6_001ef608\n"
        /* { scope 2 */
        ".Lf1ef5e6_001ef617:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 278 | N */
        "testl %eax, %eax\n"
        "jle .Lf1ef5e6_001ef698\n"
        "movl 0x20(%ebp), %esi\n" /* ord */
        "subl $1, %esi\n"
        "movl 0x20(%ebp), %eax\n" /* line 287 | ord */
        "shll $2, %eax\n"
        "leal -4(%ebx, %eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "leal -4(%edi, %eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "xorl %ecx, %ecx\n"
        "movss 0x305880, %xmm5\n"
        ".Lf1ef5e6_001ef642:\n"
        "movl 8(%ebp), %eax\n" /* line 281 | xx */
        "movss (%eax, %ecx, 4), %xmm1\n"
        "addss (%ebx), %xmm1\n"
        "movaps %xmm1, %xmm2\n" /* line 282 */
        "xorps %xmm5, %xmm2\n"
        "testl %esi, %esi\n" /* line 283 */
        "jle .Lf1ef5e6_001ef677\n"
        "xorl %edx, %edx\n"
        "movl %ebx, %eax\n"
        ".Lf1ef5e6_001ef65c:\n"
        "movaps %xmm2, %xmm0\n" /* line 285 */
        "mulss (%edi, %edx, 4), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 283 */
        "addl $4, %eax\n"
        "cmpl %esi, %edx\n"
        "jne .Lf1ef5e6_001ef65c\n"
        ".Lf1ef5e6_001ef677:\n"
        "movaps %xmm2, %xmm0\n" /* line 287 */
        "movl -0x1c(%ebp), %edx\n"
        "mulss (%edx), %xmm0\n"
        "movl -0x20(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 288 | y */
        "movss %xmm1, (%edx, %ecx, 4)\n"
        "addl $1, %ecx\n" /* line 278 */
        "cmpl %ecx, 0x1c(%ebp)\n" /* N */
        "jne .Lf1ef5e6_001ef642\n"
        /* } scope */
        ".Lf1ef5e6_001ef698:\n"
        "movl 0x20(%ebp), %esi\n" /* line 349 | ord */
        "testl %esi, %esi\n"
        "jle .Lf1ef5e6_001ef6b0\n"
        "xorl %eax, %eax\n"
        ".Lf1ef5e6_001ef6a1:\n"
        "movl $0, (%ebx, %eax, 4)\n" /* line 350 | mem */
        "addl $1, %eax\n" /* line 349 */
        "cmpl %eax, 0x20(%ebp)\n" /* ord */
        "jne .Lf1ef5e6_001ef6a1\n"
        /* { scope 2 */
        ".Lf1ef5e6_001ef6b0:\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 237 | N */
        "testl %ecx, %ecx\n"
        "jle .Lf1ef5e6_001ef779\n"
        "movl 0x20(%ebp), %edi\n" /* ord */
        "subl $1, %edi\n"
        "movl 0x20(%ebp), %eax\n" /* line 246 | ord */
        "shll $2, %eax\n"
        "leal -4(%ebx, %eax), %esi\n"
        "movl %esi, -0x18(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* awk1 */
        "leal -4(%edx, %eax), %edx\n"
        "movl %edx, -0x14(%ebp)\n"
        "movl 0x14(%ebp), %esi\n" /* awk2 */
        "leal -4(%esi, %eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0x24(%ebp)\n" /* i */
        "movss 0x305880, %xmm5\n"
        "movl -0x24(%ebp), %eax\n" /* i */
        ".Lf1ef5e6_001ef6f4:\n"
        "movl 0x18(%ebp), %edx\n" /* line 239 | y */
        "movss (%edx, %eax, 4), %xmm2\n"
        "movaps %xmm2, %xmm3\n" /* line 240 */
        "addss (%ebx), %xmm3\n"
        "movaps %xmm3, %xmm4\n" /* line 241 */
        "xorps %xmm5, %xmm4\n"
        "testl %edi, %edi\n" /* line 242 */
        "jle .Lf1ef5e6_001ef743\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ef5e6_001ef70f:\n"
        "leal (, %ecx, 4), %eax\n" /* line 341 */
        "leal (%ebx, %eax), %edx\n" /* stack */
        "movaps %xmm2, %xmm0\n" /* line 244 */
        "movl 0x10(%ebp), %esi\n" /* awk1 */
        "mulss (%esi, %eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "movl 0x14(%ebp), %esi\n" /* awk2 */
        "mulss (%esi, %eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 242 */
        "cmpl %edi, %ecx\n"
        "jne .Lf1ef5e6_001ef70f\n"
        ".Lf1ef5e6_001ef743:\n"
        "movl -0x14(%ebp), %eax\n" /* line 246 */
        "mulss (%eax), %xmm2\n"
        "movaps %xmm3, %xmm0\n"
        "movl -0x10(%ebp), %edx\n"
        "mulss (%edx), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movl -0x18(%ebp), %esi\n"
        "movss %xmm2, (%esi)\n"
        "movl -0x24(%ebp), %eax\n" /* line 247 | i */
        "movl 0x18(%ebp), %edx\n" /* y */
        "movss %xmm3, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 237 */
        "movl %eax, -0x24(%ebp)\n" /* i */
        "cmpl %eax, 0x1c(%ebp)\n" /* N */
        "jne .Lf1ef5e6_001ef6f4\n"
        /* } scope */
        /* } scope */
        ".Lf1ef5e6_001ef779:\n"
        "addl $0x18, %esp\n" /* line 352 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 354 */
__attribute__((naked))
void residue_percep_zero(const spx_sig_t *xx, const spx_coef_t *ak, const spx_coef_t *awk1, const spx_coef_t *awk2, spx_sig_t *y, int N, int ord, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 354 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18, %esp\n"
        "movl 0x24(%ebp), %edx\n" /* stack */
        /* { scope 1: i */
        "movl %edx, %eax\n" /* line 358 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "leal (%edx, %eax), %ebx\n" /* mem */
        "movl 0x20(%ebp), %eax\n" /* line 359 | ord */
        "testl %eax, %eax\n"
        "jle .Lf1ef782_001ef7b0\n"
        "xorl %eax, %eax\n"
        ".Lf1ef782_001ef7a1:\n"
        "movl $0, (%ebx, %eax, 4)\n" /* line 360 | mem */
        "addl $1, %eax\n" /* line 359 */
        "cmpl %eax, 0x20(%ebp)\n" /* ord */
        "jne .Lf1ef782_001ef7a1\n"
        /* { scope 2 */
        ".Lf1ef782_001ef7b0:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 237 | N */
        "testl %eax, %eax\n"
        "jle .Lf1ef782_001ef87c\n"
        "movl 0x20(%ebp), %edi\n" /* ord */
        "subl $1, %edi\n"
        "movl 0x20(%ebp), %eax\n" /* line 246 | ord */
        "shll $2, %eax\n"
        "leal -4(%ebx, %eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %esi\n" /* ak */
        "leal -4(%esi, %eax), %esi\n"
        "movl %esi, -0x18(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* awk1 */
        "leal -4(%edx, %eax), %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl $0, -0x24(%ebp)\n" /* i */
        "movss 0x305890, %xmm5\n"
        "movl -0x24(%ebp), %esi\n" /* i */
        ".Lf1ef782_001ef7f4:\n"
        "movl 8(%ebp), %eax\n" /* line 239 | xx */
        "movss (%eax, %esi, 4), %xmm2\n"
        "movaps %xmm2, %xmm3\n" /* line 240 */
        "addss (%ebx), %xmm3\n"
        "movaps %xmm3, %xmm4\n" /* line 241 */
        "xorps %xmm5, %xmm4\n"
        "testl %edi, %edi\n" /* line 242 */
        "jle .Lf1ef782_001ef843\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ef782_001ef80f:\n"
        "leal (, %ecx, 4), %eax\n" /* line 354 */
        "leal (%ebx, %eax), %edx\n" /* stack */
        "movaps %xmm2, %xmm0\n" /* line 244 */
        "movl 0xc(%ebp), %esi\n" /* ak */
        "mulss (%esi, %eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "movl 0x10(%ebp), %esi\n" /* awk1 */
        "mulss (%esi, %eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 242 */
        "cmpl %edi, %ecx\n"
        "jne .Lf1ef782_001ef80f\n"
        ".Lf1ef782_001ef843:\n"
        "movl -0x18(%ebp), %eax\n" /* line 246 */
        "mulss (%eax), %xmm2\n"
        "movaps %xmm3, %xmm0\n"
        "movl -0x14(%ebp), %edx\n"
        "mulss (%edx), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movl -0x1c(%ebp), %esi\n"
        "movss %xmm2, (%esi)\n"
        "movl -0x24(%ebp), %eax\n" /* line 247 | i */
        "movl 0x18(%ebp), %edx\n" /* y */
        "movss %xmm3, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 237 */
        "movl %eax, -0x24(%ebp)\n" /* i */
        "cmpl %eax, 0x1c(%ebp)\n" /* N */
        "je .Lf1ef782_001ef87c\n"
        "movl %eax, %esi\n"
        "jmp .Lf1ef782_001ef7f4\n"
        /* } scope */
        ".Lf1ef782_001ef87c:\n"
        "movl 0x20(%ebp), %eax\n" /* line 362 | ord */
        "testl %eax, %eax\n"
        "jle .Lf1ef782_001ef894\n"
        "xorl %eax, %eax\n"
        ".Lf1ef782_001ef885:\n"
        "movl $0, (%ebx, %eax, 4)\n" /* line 363 | mem */
        "addl $1, %eax\n" /* line 362 */
        "cmpl %eax, 0x20(%ebp)\n" /* ord */
        "jne .Lf1ef782_001ef885\n"
        /* { scope 2 */
        ".Lf1ef782_001ef894:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 319 | N */
        "testl %eax, %eax\n"
        "jle .Lf1ef782_001ef90d\n"
        "movl 0x20(%ebp), %esi\n" /* ord */
        "subl $1, %esi\n"
        "movl 0x20(%ebp), %eax\n" /* line 327 | ord */
        "shll $2, %eax\n"
        "leal -4(%ebx, %eax), %edi\n"
        "movl %edi, -0x10(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* awk2 */
        "leal -4(%edx, %eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "xorl %eax, %eax\n"
        ".Lf1ef782_001ef8ba:\n"
        "movl 0x18(%ebp), %edi\n" /* line 321 | y */
        "movss (%edi, %eax, 4), %xmm1\n"
        "movaps %xmm1, %xmm2\n" /* line 322 */
        "addss (%ebx), %xmm2\n"
        "testl %esi, %esi\n" /* line 323 */
        "jle .Lf1ef782_001ef8ef\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %edx\n"
        ".Lf1ef782_001ef8d1:\n"
        "movaps %xmm1, %xmm0\n" /* line 325 */
        "movl 0x14(%ebp), %edi\n" /* awk2 */
        "mulss (%edi, %ecx, 4), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 323 */
        "addl $4, %edx\n"
        "cmpl %esi, %ecx\n"
        "jne .Lf1ef782_001ef8d1\n"
        ".Lf1ef782_001ef8ef:\n"
        "movl -0x20(%ebp), %edx\n" /* line 327 */
        "mulss (%edx), %xmm1\n"
        "movl -0x10(%ebp), %edi\n"
        "movss %xmm1, (%edi)\n"
        "movl 0x18(%ebp), %edx\n" /* line 328 | y */
        "movss %xmm2, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 319 */
        "cmpl %eax, 0x1c(%ebp)\n" /* N */
        "jne .Lf1ef782_001ef8ba\n"
        /* } scope */
        /* } scope */
        ".Lf1ef782_001ef90d:\n"
        "addl $0x18, %esp\n" /* line 365 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

