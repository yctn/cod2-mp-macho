/* ASM dump from: cb_search.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/cb_search.c */

#include "common_types.h"
#include "imports.h"

void split_cb_shape_sign_unquant(spx_sig_t *exc, const void *par, int nsf, SpeexBits *bits, char *stack);
void noise_codebook_quant(spx_sig_t *target, spx_coef_t *ak, spx_coef_t *awk1, spx_coef_t *awk2, const void *par, int p, int nsf, spx_sig_t *exc, spx_word16_t *r, SpeexBits *bits, char *stack, int complexity, int update_target);
void noise_codebook_unquant(spx_sig_t *exc, const void *par, int nsf, SpeexBits *bits, char *stack);
void split_cb_search_shape_sign(spx_sig_t *target, spx_coef_t *ak, spx_coef_t *awk1, spx_coef_t *awk2, const void *par, int p, int nsf, spx_sig_t *exc, spx_word16_t *r, SpeexBits *bits, char *stack, int complexity, int update_target);

/* line 536 */
__attribute__((naked))
void split_cb_shape_sign_unquant(spx_sig_t *exc, const void *par, int nsf, SpeexBits *bits, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 536 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x18(%ebp), %edx\n" /* stack */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 547 | par */
        "movl (%eax), %edi\n" /* subvect_size */
        "movl 4(%eax), %ebx\n" /* line 548 | j */
        "movl %ebx, -0x24(%ebp)\n" /* j, nb_subvect */
        "movl 8(%eax), %esi\n" /* line 550 */
        "movl %esi, -0x28(%ebp)\n" /* shape_cb */
        "movl 0x10(%eax), %eax\n" /* line 551 */
        "movl %eax, -0x20(%ebp)\n" /* have_sign */
        "movl $4, %ecx\n" /* line 553 */
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "movl %ebx, %eax\n" /* j */
        "shll $2, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, %ebx\n" /* j */
        "subl %eax, %ebx\n" /* j */
        "movl %ebx, -0x30(%ebp)\n" /* j, ind */
        "subl %edx, %ecx\n" /* line 554 */
        "andl $3, %ecx\n"
        "leal (%edx, %ecx), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n" /* signs */
        "movl -0x24(%ebp), %ecx\n" /* line 557 | nb_subvect */
        "testl %ecx, %ecx\n"
        "jg .Lf1e8de0_001e8e39\n"
        /* } scope */
        ".Lf1e8de0_001e8e31:\n"
        "addl $0x4c, %esp\n" /* line 585 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e8de0_001e8e39:\n"
        "xorl %ebx, %ebx\n" /* line 557 | j */
        "xorl %esi, %esi\n"
        "movl -0x20(%ebp), %eax\n" /* have_sign */
        "testl %eax, %eax\n"
        "jne .Lf1e8de0_001e8f37\n"
        ".Lf1e8de0_001e8e48:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 562 | signs */
        "movl $0, (%eax, %ebx, 4)\n"
        "movl 0xc(%ebp), %edx\n" /* line 563 | par */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "movl -0x30(%ebp), %edx\n" /* ind */
        "movl %eax, (%edx, %esi)\n"
        "addl $1, %ebx\n" /* line 557 | j */
        "addl $4, %esi\n"
        "cmpl %ebx, -0x24(%ebp)\n" /* j, nb_subvect */
        "jne .Lf1e8de0_001e8e48\n"
        ".Lf1e8de0_001e8e78:\n"
        "movl $0, -0x1c(%ebp)\n"
        "movsd 0x307db8, %xmm3\n" /* 0.03125 */
        "movss 0x2ed5dc, %xmm5\n" /* -1.0f */
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "movl $0, -0x34(%ebp)\n"
        "leal (, %edi, 4), %ebx\n" /* j */
        "movl %ebx, -0x38(%ebp)\n" /* j */
        "movl -0x1c(%ebp), %esi\n"
        "shll $2, %esi\n" /* line 536 */
        "movl %esi, -0x3c(%ebp)\n"
        /* { scope 2 */
        "movl -0x2c(%ebp), %eax\n" /* line 569 | signs */
        "movl (%eax, %esi), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1e8de0_001e8f32\n"
        ".Lf1e8de0_001e8ebb:\n"
        "movaps %xmm5, %xmm0\n"
        ".Lf1e8de0_001e8ebe:\n"
        "testl %edi, %edi\n" /* line 581 | subvect_size */
        "jle .Lf1e8de0_001e8f0a\n"
        "cvtss2sd %xmm0, %xmm2\n"
        "mulsd %xmm3, %xmm2\n"
        "movl -0x34(%ebp), %ecx\n"
        "addl 8(%ebp), %ecx\n" /* exc */
        "xorl %ebx, %ebx\n" /* j */
        ".Lf1e8de0_001e8ed2:\n"
        "cvtss2sd (%ecx), %xmm1\n" /* line 582 */
        "movl %edi, %edx\n" /* subvect_size */
        "movl -0x30(%ebp), %esi\n" /* ind */
        "movl -0x3c(%ebp), %eax\n"
        "imull (%esi, %eax), %edx\n"
        "movl -0x28(%ebp), %esi\n" /* shape_cb */
        "leal (%ebx, %esi), %eax\n" /* j */
        "movsbl (%eax, %edx), %eax\n"
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "addl $1, %ebx\n" /* line 581 | j */
        "addl $4, %ecx\n"
        "cmpl %ebx, %edi\n" /* j, subvect_size */
        "jne .Lf1e8de0_001e8ed2\n"
        /* } scope */
        ".Lf1e8de0_001e8f0a:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 566 */
        "movl -0x38(%ebp), %eax\n"
        "addl %eax, -0x34(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "cmpl %edx, -0x24(%ebp)\n" /* nb_subvect */
        "je .Lf1e8de0_001e8e31\n"
        "movl %edx, %esi\n"
        "shll $2, %esi\n" /* line 536 */
        "movl %esi, -0x3c(%ebp)\n"
        /* { scope 2 */
        "movl -0x2c(%ebp), %eax\n" /* line 569 | signs */
        "movl (%eax, %esi), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1e8de0_001e8ebb\n"
        ".Lf1e8de0_001e8f32:\n"
        "movaps %xmm4, %xmm0\n"
        "jmp .Lf1e8de0_001e8ebe\n"
        /* } scope */
        ".Lf1e8de0_001e8f37:\n"
        "movl $1, 4(%esp)\n" /* line 560 */
        "movl 0x14(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "movl -0x2c(%ebp), %edx\n" /* signs */
        "movl %eax, (%edx, %ebx, 4)\n"
        "movl 0xc(%ebp), %edx\n" /* line 563 | par */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "movl -0x30(%ebp), %edx\n" /* ind */
        "movl %eax, (%edx, %esi)\n"
        "addl $1, %ebx\n" /* line 557 | j */
        "addl $4, %esi\n"
        "cmpl %ebx, -0x24(%ebp)\n" /* j, nb_subvect */
        "jne .Lf1e8de0_001e8f37\n"
        "jmp .Lf1e8de0_001e8e78\n"
    );
}

/* line 601 */
__attribute__((naked))
void noise_codebook_quant(spx_sig_t *target, spx_coef_t *ak, spx_coef_t *awk1, spx_coef_t *awk2, const void *par, int p, int nsf, spx_sig_t *exc, spx_word16_t *r, SpeexBits *bits, char *stack, int complexity, int update_target)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 601 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x20(%ebp), %ebx\n" /* nsf */
        "movl 0x24(%ebp), %edi\n" /* exc */
        "movl 0x30(%ebp), %edx\n" /* stack */
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 605 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal (%edx, %ebx, 4), %eax\n"
        "movl %edx, %esi\n" /* tmp */
        "movl %eax, 0x1c(%esp)\n" /* line 606 */
        "movl 0x1c(%ebp), %eax\n" /* p */
        "movl %eax, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n" /* nsf */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* awk2 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* awk1 */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* ak */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* target */
        "movl %eax, (%esp)\n"
        "calll residue_percep_zero\n"
        "testl %ebx, %ebx\n" /* line 608 | nsf */
        "jle .Lf1e8f7c_001e9006\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e8f7c_001e8fd5:\n"
        "leal (, %ecx, 4), %eax\n" /* line 601 | p */
        "leal (%edi, %eax), %edx\n" /* exc, stack */
        "movss (%edx), %xmm0\n" /* line 609 */
        "addss (%esi, %eax), %xmm0\n" /* tmp */
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 608 */
        "cmpl %ecx, %ebx\n" /* nsf */
        "jne .Lf1e8f7c_001e8fd5\n"
        "xorl %eax, %eax\n"
        ".Lf1e8f7c_001e8ff5:\n"
        "movl 8(%ebp), %edx\n" /* line 611 | target */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 610 */
        "cmpl %eax, %ebx\n" /* nsf */
        "jne .Lf1e8f7c_001e8ff5\n"
        /* } scope */
        ".Lf1e8f7c_001e9006:\n"
        "addl $0x2c, %esp\n" /* line 613 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 622 */
__attribute__((naked))
void noise_codebook_unquant(spx_sig_t *exc, const void *par, int nsf, SpeexBits *bits, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 622 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 624 | exc */
        "movl %eax, 0xc(%ebp)\n" /* par */
        "movl $0x3f800000, 8(%ebp)\n" /* exc */
        "popl %ebp\n" /* line 625 */
        "jmp speex_rand_vec\n" /* line 624 */
    );
}

/* line 252 */
__attribute__((naked))
void split_cb_search_shape_sign(spx_sig_t *target, spx_coef_t *ak, spx_coef_t *awk1, spx_coef_t *awk2, const void *par, int p, int nsf, spx_sig_t *exc, spx_word16_t *r, SpeexBits *bits, char *stack, int complexity, int update_target)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 252 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1ac, %esp\n"
        "movl 0x30(%ebp), %edi\n" /* stack */
        "movl 0x34(%ebp), %eax\n" /* complexity */
        /* { scope 1: i */
        "cmpl $0xa, %eax\n" /* line 284 */
        "jg .Lf1e9024_001e9482\n"
        "testl %eax, %eax\n" /* line 286 */
        "jle .Lf1e9024_001e904c\n"
        "cmpl $1, %eax\n" /* line 289 */
        "jne .Lf1e9024_001ea251\n"
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        ".Lf1e9024_001e904c:\n"
        "movl 0x18(%ebp), %eax\n" /* line 128 | par */
        "movl (%eax), %esi\n" /* shape */
        "movl 4(%eax), %edx\n" /* line 129 */
        "movl %edx, -0x98(%ebp)\n" /* nb_subvect */
        "movl 0xc(%eax), %ecx\n" /* line 130 */
        "movl $1, -0x8c(%ebp)\n" /* shape_cb_size */
        "shll %cl, -0x8c(%ebp)\n" /* shape_cb_size */
        "movl 8(%eax), %ecx\n" /* line 131 */
        "movl %ecx, -0x80(%ebp)\n" /* shape_cb */
        "movl 0x10(%eax), %ebx\n" /* line 132 | j */
        "movl %ebx, -0x94(%ebp)\n" /* j, have_sign */
        "movl $4, %ebx\n" /* line 133 | j */
        "movl %ebx, %eax\n" /* j */
        "subl %edi, %eax\n"
        "andl $3, %eax\n"
        "leal (%edi, %eax), %eax\n"
        "movl -0x8c(%ebp), %edx\n" /* shape_cb_size */
        "imull %esi, %edx\n" /* shape */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %eax, -0x84(%ebp)\n" /* resp2 */
        "movl %ebx, %eax\n" /* line 139 | j */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "movl -0x8c(%ebp), %edi\n" /* shape_cb_size */
        "leal (%edx, %edi, 4), %ecx\n"
        "movl %edx, -0x88(%ebp)\n" /* E */
        "movl %ebx, %eax\n" /* line 141 | j */
        "subl %ecx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %ecx\n"
        "movl 0x20(%ebp), %eax\n" /* nsf */
        "shll $2, %eax\n"
        "movl %eax, -0xa4(%ebp)\n"
        "addl %eax, %ecx\n"
        "movl %ecx, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, -0xa0(%ebp)\n" /* t */
        "subl %ecx, %ebx\n" /* line 142 | j */
        "andl $3, %ebx\n" /* j */
        "addl %ebx, %ecx\n" /* j */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x90(%ebp)\n" /* stack */
        "subl %eax, %ecx\n"
        "movl %ecx, -0x9c(%ebp)\n" /* e */
        "movl 0x20(%ebp), %eax\n" /* line 145 | nsf */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e9114\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001e90f6:\n"
        "leal (, %ecx, 4), %edx\n" /* line 252 */
        "movl 8(%ebp), %ebx\n" /* line 146 | target, j */
        "movl (%ebx, %edx), %eax\n" /* j */
        "movl -0xa0(%ebp), %edi\n" /* t */
        "movl %eax, (%edi, %edx)\n"
        "addl $1, %ecx\n" /* line 145 */
        "cmpl %ecx, 0x20(%ebp)\n" /* nsf */
        "jne .Lf1e9024_001e90f6\n"
        /* { scope 4: i, shape */
        /* { scope 5: res */
        ".Lf1e9024_001e9114:\n"
        "movl -0x90(%ebp), %eax\n" /* line 53 | stack */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl -0x90(%ebp), %eax\n" /* stack */
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, -0x78(%ebp)\n" /* shape */
        "movl -0x8c(%ebp), %eax\n" /* line 54 | shape_cb_size */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e9223\n"
        "movl $0, -0x7c(%ebp)\n" /* i */
        "pxor %xmm7, %xmm7\n"
        "movss 0x2ed878, %xmm3\n" /* 0.03125f */
        "movl -0x88(%ebp), %edi\n" /* E */
        "movl $0, -0x144(%ebp)\n"
        /* { scope 6 */
        ".Lf1e9024_001e915c:\n"
        "movl -0x144(%ebp), %eax\n" /* line 58 */
        "movl -0x84(%ebp), %edx\n" /* resp2 */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* res */
        "testl %esi, %esi\n" /* line 59 | shape */
        "jle .Lf1e9024_001e9196\n"
        "movl -0x80(%ebp), %edx\n" /* shape_cb */
        "addl -0x144(%ebp), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001e917d:\n"
        "movsbl (%edx), %eax\n" /* line 60 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl -0x78(%ebp), %ebx\n" /* shape */
        "movss %xmm0, (%ebx, %ecx, 4)\n"
        "addl $1, %ecx\n" /* line 59 */
        "addl $1, %edx\n"
        "cmpl %ecx, %esi\n" /* shape */
        "jne .Lf1e9024_001e917d\n"
        ".Lf1e9024_001e9196:\n"
        "movl $0, (%edi)\n" /* line 61 */
        "testl %esi, %esi\n" /* line 64 | shape */
        "jle .Lf1e9024_001e9207\n"
        "movl 0x28(%ebp), %eax\n" /* r */
        "movl %eax, -0x16c(%ebp)\n"
        "xorl %ecx, %ecx\n"
        "movaps %xmm3, %xmm2\n"
        "movl %eax, %edx\n"
        /* { scope 7 */
        ".Lf1e9024_001e91b0:\n"
        "xorl %eax, %eax\n" /* line 68 */
        "movaps %xmm7, %xmm1\n"
        "movl -0x78(%ebp), %ebx\n" /* shape */
        ".Lf1e9024_001e91b8:\n"
        "movss (%ebx, %eax, 4), %xmm0\n" /* line 69 */
        "mulss (%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %eax\n" /* line 68 */
        "subl $4, %edx\n"
        "cmpl %eax, %ecx\n"
        "jge .Lf1e9024_001e91b8\n"
        "mulss %xmm2, %xmm1\n"
        ".Lf1e9024_001e91d3:\n"
        "movaps %xmm1, %xmm0\n" /* line 76 */
        "mulss %xmm1, %xmm0\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movl -0x74(%ebp), %eax\n" /* line 77 | res */
        "movss %xmm1, (%eax, %ecx, 4)\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 64 */
        "addl $4, -0x16c(%ebp)\n"
        "cmpl %ecx, %esi\n" /* shape */
        "je .Lf1e9024_001e9207\n"
        "movaps %xmm7, %xmm1\n"
        /* { scope 7 */
        "testl %ecx, %ecx\n" /* line 68 */
        "js .Lf1e9024_001e91d3\n"
        "movl -0x16c(%ebp), %edx\n"
        "jmp .Lf1e9024_001e91b0\n"
        /* } scope */
        /* } scope */
        ".Lf1e9024_001e9207:\n"
        "addl $1, -0x7c(%ebp)\n" /* line 54 | i */
        "addl %esi, -0x144(%ebp)\n" /* shape */
        "addl $4, %edi\n"
        "movl -0x7c(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x8c(%ebp)\n" /* shape_cb_size */
        "jne .Lf1e9024_001e915c\n"
        /* } scope */
        /* } scope */
        ".Lf1e9024_001e9223:\n"
        "movl -0x98(%ebp), %eax\n" /* line 150 | nb_subvect */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e943c\n"
        "movl $0, -0x4c(%ebp)\n"
        "movl $0, -0x138(%ebp)\n"
        "movl $0, -0x13c(%ebp)\n"
        "leal (, %esi, 4), %ecx\n"
        "movl %ecx, -0x140(%ebp)\n"
        ".Lf1e9024_001e9259:\n"
        "movl -0xa0(%ebp), %ebx\n" /* line 152 | t, j */
        "addl -0x13c(%ebp), %ebx\n" /* j */
        "movl -0x94(%ebp), %eax\n" /* line 154 | have_sign */
        "testl %eax, %eax\n"
        "je .Lf1e9024_001ea28a\n"
        "movl -0x90(%ebp), %edi\n" /* line 155 | stack */
        "movl %edi, 0x20(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* best_dist */
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* best_index */
        "movl %edx, 0x18(%esp)\n"
        "movl $1, 0x14(%esp)\n"
        "movl -0x88(%ebp), %ecx\n" /* E */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0x8c(%ebp), %edi\n" /* shape_cb_size */
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* subvect_size */
        "movl -0x84(%ebp), %eax\n" /* resp2 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* j */
        "calll vq_nbest_sign\n"
        ".Lf1e9024_001e92bd:\n"
        "movl -0x94(%ebp), %eax\n" /* line 159 | have_sign */
        "movl 0x18(%ebp), %edi\n" /* par */
        "addl 0xc(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* best_index */
        "movl %eax, 4(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        /* { scope 4: i, shape */
        "movl -0x1c(%ebp), %eax\n" /* line 165 | best_index */
        "cmpl %eax, -0x8c(%ebp)\n" /* line 166 | shape_cb_size */
        "jle .Lf1e9024_001ea2d9\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        ".Lf1e9024_001e92f6:\n"
        "movl %eax, %edi\n" /* line 171 */
        "imull %esi, %edi\n" /* subvect_size */
        "movl -0x84(%ebp), %edx\n" /* resp2 */
        "leal (%edx, %edi, 4), %ecx\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 172 | 0.0f */
        "jbe .Lf1e9024_001ea2ec\n"
        "testl %esi, %esi\n" /* line 173 | subvect_size */
        "jle .Lf1e9024_001ea26f\n"
        "movl %ebx, %eax\n" /* j */
        "xorl %edx, %edx\n"
        ".Lf1e9024_001e931d:\n"
        "movss (%eax), %xmm0\n" /* line 174 */
        "subss (%ecx, %edx, 4), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 173 */
        "addl $4, %eax\n"
        "cmpl %edx, %esi\n" /* subvect_size */
        "jne .Lf1e9024_001e931d\n"
        ".Lf1e9024_001e9334:\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 176 */
        "movsd 0x307db8, %xmm4\n" /* 0.03125 */
        "mulsd %xmm4, %xmm1\n"
        "movl -0x80(%ebp), %ecx\n" /* shape_cb */
        "addl %edi, %ecx\n"
        "movl -0x9c(%ebp), %edx\n" /* e */
        "addl -0x13c(%ebp), %edx\n"
        "xorl %ebx, %ebx\n" /* j */
        ".Lf1e9024_001e9357:\n"
        "movsbl (%ecx), %eax\n" /* line 190 */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ebx\n" /* line 189 | j */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %ebx, %esi\n" /* j, subvect_size */
        "jne .Lf1e9024_001e9357\n"
        /* } scope */
        "addl $1, -0x4c(%ebp)\n" /* line 195 */
        "movl -0x140(%ebp), %ebx\n" /* j */
        "addl %ebx, -0x13c(%ebp)\n" /* j */
        "addl %esi, -0x138(%ebp)\n" /* subvect_size */
        "movl 0x28(%ebp), %ebx\n" /* r, j */
        "addl -0x140(%ebp), %ebx\n" /* j */
        "movl $0, -0x2c(%ebp)\n"
        "movl -0x1c(%ebp), %edi\n" /* best_index */
        "movl %edi, -0x110(%ebp)\n"
        "movl 0x20(%ebp), %edi\n" /* nsf */
        "subl -0x138(%ebp), %edi\n"
        /* { scope 4: i, shape */
        ".Lf1e9024_001e93af:\n"
        "movl -0x110(%ebp), %edx\n" /* line 200 */
        "cmpl %edx, -0x8c(%ebp)\n" /* line 201 | shape_cb_size */
        "jle .Lf1e9024_001ea25c\n"
        "movsd 0x307c10, %xmm1\n" /* 1.0 */
        ".Lf1e9024_001e93c9:\n"
        "mulsd %xmm4, %xmm1\n" /* line 213 */
        "imull %esi, %edx\n" /* subvect_size */
        "movl -0x2c(%ebp), %eax\n"
        "addl -0x80(%ebp), %eax\n" /* shape_cb */
        "movsbl (%eax, %edx), %eax\n"
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm2\n"
        "movl -0x138(%ebp), %eax\n" /* line 214 */
        "cmpl %eax, 0x20(%ebp)\n" /* nsf */
        "jle .Lf1e9024_001e9421\n"
        "movl -0xa0(%ebp), %eax\n" /* t */
        "addl -0x13c(%ebp), %eax\n"
        "movl %ebx, %edx\n" /* j */
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001e9401:\n"
        "movaps %xmm2, %xmm1\n" /* line 215 */
        "mulss (%edx), %xmm1\n"
        "movss (%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %ecx\n"
        "addl $4, %eax\n"
        "addl $4, %edx\n"
        "cmpl %edi, %ecx\n" /* line 214 */
        "jne .Lf1e9024_001e9401\n"
        /* } scope */
        ".Lf1e9024_001e9421:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 195 */
        "subl $4, %ebx\n" /* j */
        "cmpl -0x2c(%ebp), %esi\n" /* subvect_size */
        "jne .Lf1e9024_001e93af\n"
        ".Lf1e9024_001e942d:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 150 */
        "cmpl %edx, -0x98(%ebp)\n" /* nb_subvect */
        "jg .Lf1e9024_001e9259\n"
        ".Lf1e9024_001e943c:\n"
        "movl 0x20(%ebp), %edi\n" /* line 222 | nsf */
        "testl %edi, %edi\n"
        "jle .Lf1e9024_001e946c\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001e9445:\n"
        "leal (, %ecx, 4), %eax\n" /* line 252 | complexity */
        "movl 0x24(%ebp), %edx\n" /* exc */
        "addl %eax, %edx\n" /* complexity */
        "movss (%edx), %xmm0\n" /* line 223 */
        "movl -0x9c(%ebp), %ebx\n" /* e, j */
        "addss (%ebx, %eax), %xmm0\n" /* j */
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 222 */
        "cmpl %ecx, 0x20(%ebp)\n" /* nsf */
        "jne .Lf1e9024_001e9445\n"
        ".Lf1e9024_001e946c:\n"
        "movl 0x38(%ebp), %esi\n" /* line 226 | update_target, subvect_size */
        "testl %esi, %esi\n" /* subvect_size */
        "jne .Lf1e9024_001ea1d7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1e9024_001e9477:\n"
        "addl $0x1ac, %esp\n" /* line 527 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        /* { scope 4: i, shape */
        ".Lf1e9024_001e9482:\n"
        "movl $0xa, -0xb4(%ebp)\n" /* line 231 | N */
        "movl $0xa, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1e9024_001e9491:\n"
        "movl $4, %ebx\n" /* line 294 | q */
        "movl %ebx, %edx\n" /* q */
        "subl %edi, %edx\n" /* stack */
        "andl $3, %edx\n"
        "leal (%edi, %edx), %edx\n" /* stack */
        "leal (, %eax, 4), %esi\n" /* subvect_size */
        "addl %esi, %edx\n" /* subvect_size */
        "movl %edx, %edi\n" /* stack */
        "subl %esi, %edi\n" /* subvect_size, stack */
        "movl %edi, -0xe0(%ebp)\n" /* stack, ot2 */
        "movl %ebx, %eax\n" /* line 295 | q */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal (%esi, %edx), %edx\n" /* subvect_size */
        "movl %edx, %eax\n"
        "subl %esi, %eax\n" /* subvect_size */
        "movl %eax, -0xdc(%ebp)\n" /* nt2 */
        "movl %ebx, %eax\n" /* line 296 | q */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal (%esi, %edx), %edx\n" /* subvect_size */
        "movl %edx, %ecx\n"
        "subl %esi, %ecx\n" /* subvect_size */
        "movl %ecx, -0xcc(%ebp)\n" /* oind */
        "movl %ebx, %eax\n" /* line 297 | q */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal (%esi, %edx), %edx\n" /* subvect_size */
        "movl %edx, %edi\n" /* stack */
        "subl %esi, %edi\n" /* subvect_size, stack */
        "movl %edi, -0xd0(%ebp)\n" /* stack, nind */
        "movl 0x18(%ebp), %eax\n" /* line 300 | par */
        "movl (%eax), %eax\n"
        "movl %eax, -0xbc(%ebp)\n" /* subvect_size */
        "movl 0x18(%ebp), %ecx\n" /* line 301 | par */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0xb8(%ebp)\n" /* nb_subvect */
        "movl 0x18(%ebp), %edi\n" /* line 302 | par, stack */
        "movl 0xc(%edi), %ecx\n" /* stack */
        "movl $1, -0xc0(%ebp)\n" /* shape_cb_size */
        "shll %cl, -0xc0(%ebp)\n" /* shape_cb_size */
        "movl 8(%edi), %eax\n" /* line 303 | stack */
        "movl %eax, -0xc4(%ebp)\n" /* shape_cb */
        "movl 0x10(%edi), %ecx\n" /* line 304 | stack */
        "movl %ecx, -0xa8(%ebp)\n" /* have_sign */
        "movl %ebx, %eax\n" /* line 305 | q */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "movl -0xbc(%ebp), %ecx\n" /* subvect_size */
        "imull -0xc0(%ebp), %ecx\n" /* shape_cb_size */
        "leal (%edx, %ecx, 4), %ecx\n"
        "movl %edx, -0xfc(%ebp)\n" /* resp */
        "movl %ebx, %eax\n" /* line 311 | q */
        "subl %ecx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %ecx\n"
        "movl -0xc0(%ebp), %edi\n" /* shape_cb_size, stack */
        "leal (%ecx, %edi, 4), %eax\n"
        "movl %ecx, -0xf8(%ebp)\n" /* E */
        "movl %ebx, %edx\n" /* line 313 | q */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "movl 0x20(%ebp), %ecx\n" /* nsf */
        "shll $2, %ecx\n"
        "addl %ecx, %eax\n"
        "movl %eax, %edx\n"
        "subl %ecx, %edx\n"
        "movl %edx, -0xf4(%ebp)\n" /* t */
        "movl %ebx, %edx\n" /* line 314 | q */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movl %eax, %edi\n" /* stack */
        "subl %ecx, %edi\n" /* stack */
        "movl %edi, -0xf0(%ebp)\n" /* stack, e */
        "movl %ebx, %edx\n" /* line 315 | q */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movl %eax, %edx\n"
        "subl %ecx, %edx\n"
        "movl %edx, -0xec(%ebp)\n" /* r2 */
        "movl %ebx, %edx\n" /* line 316 | q */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "movl -0xb8(%ebp), %edi\n" /* nb_subvect, stack */
        "leal (%eax, %edi, 4), %edx\n"
        "movl %eax, -0xc8(%ebp)\n" /* ind */
        "subl %edx, %ebx\n" /* line 318 | q */
        "andl $3, %ebx\n" /* q */
        "addl %ebx, %edx\n" /* q */
        "movl 0x20(%ebp), %eax\n" /* nsf */
        "imull -0xb4(%ebp), %eax\n" /* N */
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl -0xb4(%ebp), %ebx\n" /* line 319 | N, q */
        "testl %ebx, %ebx\n" /* q */
        "jle .Lf1e9024_001e9631\n"
        "xorl %ebx, %ebx\n" /* q */
        "addl %edx, %ecx\n"
        "movl 0x20(%ebp), %eax\n" /* nsf */
        "shll $3, %eax\n"
        "movl %eax, -0x17c(%ebp)\n"
        ".Lf1e9024_001e95fb:\n"
        "leal (, %ebx, 4), %edi\n" /* line 252 | stack */
        "movl %edi, -0x170(%ebp)\n" /* stack */
        "movl -0xe0(%ebp), %eax\n" /* line 321 | ot2 */
        "movl %edx, (%eax, %edi)\n"
        "movl -0xdc(%ebp), %eax\n" /* line 322 | nt2 */
        "movl %ecx, (%eax, %edi)\n"
        "addl $1, %ebx\n" /* line 319 | q */
        "addl -0x17c(%ebp), %edx\n"
        "addl -0x17c(%ebp), %ecx\n"
        "cmpl %ebx, -0xb4(%ebp)\n" /* q, N */
        "jne .Lf1e9024_001e95fb\n"
        ".Lf1e9024_001e9631:\n"
        "movl $4, %ecx\n" /* line 326 */
        "movl %ecx, %eax\n"
        "subl -0x40(%ebp), %eax\n"
        "andl $3, %eax\n"
        "addl -0x40(%ebp), %eax\n"
        "leal (%esi, %eax), %eax\n" /* subvect_size */
        "movl %eax, %edx\n"
        "subl %esi, %edx\n" /* subvect_size */
        "movl %edx, -0xb0(%ebp)\n" /* best_index */
        "movl %ecx, %edx\n" /* line 327 */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%esi, %eax), %eax\n" /* subvect_size */
        "movl %eax, %ebx\n" /* q */
        "subl %esi, %ebx\n" /* subvect_size, q */
        "movl %ebx, -0xac(%ebp)\n" /* q, best_dist */
        "movl %ecx, %edx\n" /* line 328 */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%esi, %eax), %eax\n" /* subvect_size */
        "movl %eax, %edi\n" /* stack */
        "subl %esi, %edi\n" /* subvect_size, stack */
        "movl %edi, -0xe8(%ebp)\n" /* stack, ndist */
        "movl %ecx, %edx\n" /* line 329 */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%esi, %eax), %eax\n" /* subvect_size */
        "movl %eax, %edx\n"
        "subl %esi, %edx\n" /* subvect_size */
        "movl %edx, -0xe4(%ebp)\n" /* odist */
        "subl %eax, %ecx\n" /* line 331 */
        "andl $3, %ecx\n"
        "addl %ecx, %eax\n"
        "movl -0xb8(%ebp), %edx\n" /* nb_subvect */
        "imull -0xb4(%ebp), %edx\n" /* N */
        "leal (%eax, %edx, 8), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl -0xb4(%ebp), %ecx\n" /* line 332 | N */
        "testl %ecx, %ecx\n"
        "jle .Lf1e9024_001e975f\n"
        "movl $0, -0x34(%ebp)\n"
        "movl -0xb8(%ebp), %ecx\n" /* nb_subvect */
        "leal (%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x12c(%ebp)\n"
        "movl %eax, -0x130(%ebp)\n"
        "movl -0xb8(%ebp), %ebx\n" /* nb_subvect, q */
        "shll $3, %ebx\n" /* q */
        "movl %ebx, -0x134(%ebp)\n" /* q */
        "movl -0x34(%ebp), %eax\n"
        ".Lf1e9024_001e96e6:\n"
        "shll $2, %eax\n" /* line 252 | complexity */
        "movl -0xd0(%ebp), %edi\n" /* nind, stack */
        "addl %eax, %edi\n" /* complexity, stack */
        "movl -0x130(%ebp), %esi\n" /* line 334 | subvect_size */
        "movl %esi, (%edi)\n" /* subvect_size, stack */
        "movl -0xcc(%ebp), %esi\n" /* line 252 | oind, subvect_size */
        "addl %eax, %esi\n" /* complexity, subvect_size */
        "movl -0x12c(%ebp), %eax\n" /* line 335 */
        "movl %eax, (%esi)\n" /* subvect_size */
        "movl -0xb8(%ebp), %edx\n" /* line 336 | nb_subvect */
        "testl %edx, %edx\n"
        "jle .Lf1e9024_001e973a\n"
        "xorl %ebx, %ebx\n" /* q */
        ".Lf1e9024_001e9715:\n"
        "leal (, %ebx, 4), %eax\n"
        "movl %eax, %ecx\n" /* line 337 */
        "addl (%edi), %ecx\n" /* stack */
        "movl (%esi), %edx\n" /* subvect_size */
        "movl $0xffffffff, (%edx, %eax)\n"
        "movl $0xffffffff, (%ecx)\n"
        "addl $1, %ebx\n" /* line 336 | q */
        "cmpl %ebx, -0xb8(%ebp)\n" /* q, nb_subvect */
        "jne .Lf1e9024_001e9715\n"
        ".Lf1e9024_001e973a:\n"
        "addl $1, -0x34(%ebp)\n" /* line 332 */
        "movl -0x134(%ebp), %edx\n"
        "addl %edx, -0x130(%ebp)\n"
        "addl %edx, -0x12c(%ebp)\n"
        "movl -0x34(%ebp), %ecx\n"
        "cmpl %ecx, -0xb4(%ebp)\n" /* N */
        "je .Lf1e9024_001e975f\n"
        "movl %ecx, %eax\n"
        "jmp .Lf1e9024_001e96e6\n"
        ".Lf1e9024_001e975f:\n"
        "movl 0x20(%ebp), %eax\n" /* line 341 | nsf */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e9786\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001e9768:\n"
        "leal (, %ecx, 4), %edx\n" /* line 252 */
        "movl 8(%ebp), %ebx\n" /* line 342 | target, q */
        "movl (%ebx, %edx), %eax\n" /* q */
        "movl -0xf4(%ebp), %esi\n" /* t, subvect_size */
        "movl %eax, (%esi, %edx)\n" /* subvect_size */
        "addl $1, %ecx\n" /* line 341 */
        "cmpl %ecx, 0x20(%ebp)\n" /* nsf */
        "jne .Lf1e9024_001e9768\n"
        ".Lf1e9024_001e9786:\n"
        "movl -0xb4(%ebp), %eax\n" /* line 344 | N */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e97ca\n"
        "xorl %esi, %esi\n" /* subvect_size */
        ".Lf1e9024_001e9792:\n"
        "movl 0x20(%ebp), %eax\n" /* line 345 | nsf */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e97bf\n"
        "xorl %ebx, %ebx\n" /* line 344 | q */
        ".Lf1e9024_001e979b:\n"
        "leal (, %ebx, 4), %eax\n"
        "movl -0xe0(%ebp), %edi\n" /* line 346 | ot2, stack */
        "movl (%edi, %esi, 4), %ecx\n" /* stack */
        "movl -0xf4(%ebp), %edi\n" /* t, stack */
        "movl (%edi, %eax), %edx\n" /* stack */
        "movl %edx, (%ecx, %eax)\n"
        "addl $1, %ebx\n" /* line 345 | q */
        "cmpl %ebx, 0x20(%ebp)\n" /* q, nsf */
        "jne .Lf1e9024_001e979b\n"
        ".Lf1e9024_001e97bf:\n"
        "addl $1, %esi\n" /* line 344 | subvect_size */
        "cmpl %esi, -0xb4(%ebp)\n" /* subvect_size, N */
        "jne .Lf1e9024_001e9792\n"
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        ".Lf1e9024_001e97ca:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 53 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "movl -0x3c(%ebp), %esi\n" /* shape */
        "addl %eax, %esi\n" /* shape */
        "movl -0xc0(%ebp), %eax\n" /* line 54 | shape_cb_size */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e98d6\n"
        "movl $0, -0x70(%ebp)\n" /* i */
        "pxor %xmm7, %xmm7\n"
        "movss 0x2ed878, %xmm3\n" /* 0.03125f */
        "movl -0xf8(%ebp), %edi\n" /* E */
        "movl $0, -0x128(%ebp)\n"
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        ".Lf1e9024_001e9808:\n"
        "movl -0x128(%ebp), %eax\n" /* line 58 */
        "movl -0xfc(%ebp), %edx\n" /* resp */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* res */
        "movl -0xbc(%ebp), %eax\n" /* line 59 | subvect_size */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e984c\n"
        "movl -0xc4(%ebp), %edx\n" /* shape_cb */
        "addl -0x128(%ebp), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001e9832:\n"
        "movsbl (%edx), %eax\n" /* line 60 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%esi, %ecx, 4)\n" /* shape */
        "addl $1, %ecx\n" /* line 59 */
        "addl $1, %edx\n"
        "cmpl %ecx, -0xbc(%ebp)\n" /* subvect_size */
        "jne .Lf1e9024_001e9832\n"
        ".Lf1e9024_001e984c:\n"
        "movl $0, (%edi)\n" /* line 61 */
        "movl -0xbc(%ebp), %eax\n" /* line 64 | subvect_size */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e98b4\n"
        "movl 0x28(%ebp), %ebx\n" /* r */
        "xorl %ecx, %ecx\n"
        "movaps %xmm3, %xmm2\n"
        /* { scope 4: i, shape */
        ".Lf1e9024_001e9864:\n"
        "movl %ebx, %edx\n" /* line 68 */
        "xorl %eax, %eax\n"
        "movaps %xmm7, %xmm1\n"
        ".Lf1e9024_001e986b:\n"
        "movss (%esi, %eax, 4), %xmm0\n" /* line 69 | shape */
        "mulss (%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %eax\n" /* line 68 */
        "subl $4, %edx\n"
        "cmpl %eax, %ecx\n"
        "jge .Lf1e9024_001e986b\n"
        "mulss %xmm2, %xmm1\n"
        ".Lf1e9024_001e9886:\n"
        "movaps %xmm1, %xmm0\n" /* line 76 */
        "mulss %xmm1, %xmm0\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movl -0x6c(%ebp), %edx\n" /* line 77 | res */
        "movss %xmm1, (%edx, %ecx, 4)\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 64 */
        "addl $4, %ebx\n"
        "cmpl %ecx, -0xbc(%ebp)\n" /* subvect_size */
        "je .Lf1e9024_001e98b4\n"
        "movaps %xmm7, %xmm1\n"
        /* { scope 4: i, shape */
        "testl %ecx, %ecx\n" /* line 68 */
        "js .Lf1e9024_001e9886\n"
        "jmp .Lf1e9024_001e9864\n"
        /* } scope */
        /* } scope */
        ".Lf1e9024_001e98b4:\n"
        "addl $1, -0x70(%ebp)\n" /* line 54 | i */
        "movl -0xbc(%ebp), %ecx\n" /* subvect_size */
        "addl %ecx, -0x128(%ebp)\n"
        "addl $4, %edi\n"
        "movl -0x70(%ebp), %ebx\n" /* i */
        "cmpl %ebx, -0xc0(%ebp)\n" /* shape_cb_size */
        "jne .Lf1e9024_001e9808\n"
        /* } scope */
        ".Lf1e9024_001e98d6:\n"
        "movl -0xb4(%ebp), %ebx\n" /* line 354 | N, q */
        "testl %ebx, %ebx\n" /* q */
        "jle .Lf1e9024_001e98fa\n"
        "xorl %eax, %eax\n"
        ".Lf1e9024_001e98e2:\n"
        "movl -0xe4(%ebp), %esi\n" /* line 355 | odist, subvect_size */
        "movl $0, (%esi, %eax, 4)\n" /* subvect_size */
        "addl $1, %eax\n" /* line 354 */
        "cmpl %eax, -0xb4(%ebp)\n" /* N */
        "jne .Lf1e9024_001e98e2\n"
        ".Lf1e9024_001e98fa:\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 357 | nb_subvect */
        "testl %ecx, %ecx\n"
        "jle .Lf1e9024_001ea113\n"
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        "movl -0xb4(%ebp), %edi\n" /* line 410 | N, stack */
        "movl -0xe8(%ebp), %eax\n" /* ndist */
        "leal -4(%eax, %edi, 4), %edi\n" /* stack */
        "movl %edi, -0x108(%ebp)\n" /* stack */
        "movl -0xe0(%ebp), %eax\n" /* ot2 */
        "movl %eax, -0xd8(%ebp)\n" /* ot */
        "movl -0xdc(%ebp), %edx\n" /* nt2 */
        "movl %edx, -0xd4(%ebp)\n" /* nt */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1e9024_001e9974\n"
        ".Lf1e9024_001e993f:\n"
        "movl -0x30(%ebp), %ecx\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x114(%ebp)\n"
        "movl %ecx, %edi\n" /* stack */
        /* } scope */
        /* } scope */
        "movl %edi, -0x30(%ebp)\n" /* line 357 | stack */
        "movl -0xd8(%ebp), %eax\n" /* ot */
        "movl -0xd4(%ebp), %edx\n" /* nt */
        "movl %edx, -0xd8(%ebp)\n" /* ot */
        "cmpl %edi, -0xb8(%ebp)\n" /* stack, nb_subvect */
        "je .Lf1e9024_001ea029\n"
        ".Lf1e9024_001e996e:\n"
        "movl %eax, -0xd4(%ebp)\n" /* nt */
        ".Lf1e9024_001e9974:\n"
        "movl -0xb4(%ebp), %ecx\n" /* line 360 | N */
        "testl %ecx, %ecx\n"
        "jle .Lf1e9024_001e993f\n"
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        "xorl %eax, %eax\n" /* line 410 */
        /* } scope */
        /* } scope */
        ".Lf1e9024_001e9980:\n"
        "movl -0xe8(%ebp), %ecx\n" /* line 361 | ndist */
        "movl $0xc0000000, (%ecx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 360 */
        "cmpl %eax, -0xb4(%ebp)\n" /* N */
        "jne .Lf1e9024_001e9980\n"
        "movl -0x30(%ebp), %ebx\n" /* q */
        "imull -0xbc(%ebp), %ebx\n" /* subvect_size, q */
        "movl %ebx, -0x68(%ebp)\n" /* q */
        "shll $2, %ebx\n" /* q */
        "movl %ebx, -0x64(%ebp)\n" /* q */
        "movl -0x30(%ebp), %esi\n" /* line 252 | subvect_size */
        "addl $1, %esi\n" /* subvect_size */
        "movl %esi, -0x114(%ebp)\n" /* subvect_size */
        "movl -0xbc(%ebp), %edi\n" /* subvect_size, stack */
        "imull %esi, %edi\n" /* subvect_size, stack */
        "movl %edi, -0x60(%ebp)\n" /* stack */
        "movl -0x30(%ebp), %eax\n" /* complexity */
        "shll $2, %eax\n" /* complexity */
        "movl %eax, -0x54(%ebp)\n" /* complexity */
        "movl $0, -0x38(%ebp)\n"
        "shll $2, %edi\n" /* stack */
        "movl %edi, -0x120(%ebp)\n" /* stack */
        "movl -0xd8(%ebp), %edx\n" /* ot */
        "movl %edx, -0x124(%ebp)\n"
        "movl -0x60(%ebp), %ecx\n"
        "subl -0x68(%ebp), %ecx\n"
        "movl %ecx, -0x14c(%ebp)\n"
        "movl %ecx, -0x150(%ebp)\n"
        "movl %edi, -0x154(%ebp)\n" /* stack */
        "movl 0x20(%ebp), %ebx\n" /* nsf, r2 */
        "subl -0x60(%ebp), %ebx\n" /* r2 */
        "movl %ebx, -0x158(%ebp)\n" /* r2 */
        "movl %ebx, -0x15c(%ebp)\n" /* r2 */
        "movl %edx, %esi\n" /* subvect_size */
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        "movl -0x64(%ebp), %eax\n" /* line 366 | x */
        "addl (%esi), %eax\n" /* subvect_size, x */
        "movl -0xa8(%ebp), %edx\n" /* line 368 | have_sign */
        "testl %edx, %edx\n"
        "je .Lf1e9024_001e9bff\n"
        ".Lf1e9024_001e9a27:\n"
        "movl -0x3c(%ebp), %edi\n" /* line 369 | stack */
        "movl %edi, 0x20(%esp)\n" /* stack */
        "movl -0xac(%ebp), %edx\n" /* best_dist */
        "movl %edx, 0x1c(%esp)\n"
        "movl -0xb0(%ebp), %ecx\n" /* best_index */
        "movl %ecx, 0x18(%esp)\n"
        "movl -0xb4(%ebp), %ebx\n" /* N, q */
        "movl %ebx, 0x14(%esp)\n" /* q */
        "movl -0xf8(%ebp), %esi\n" /* E, subvect_size */
        "movl %esi, 0x10(%esp)\n" /* subvect_size */
        "movl -0xc0(%ebp), %edi\n" /* shape_cb_size, stack */
        "movl %edi, 0xc(%esp)\n" /* stack */
        "movl -0xbc(%ebp), %edx\n" /* subvect_size */
        "movl %edx, 8(%esp)\n"
        "movl -0xfc(%ebp), %ecx\n" /* resp */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll vq_nbest_sign\n"
        ".Lf1e9024_001e9a7c:\n"
        "movl $0, -0x104(%ebp)\n" /* line 371 | k */
        "pxor %xmm7, %xmm7\n"
        "movl -0xb0(%ebp), %eax\n" /* best_index */
        "movl %eax, -0x11c(%ebp)\n"
        "movl 0x20(%ebp), %edx\n" /* nsf */
        "subl -0x60(%ebp), %edx\n"
        "movl %edx, -0x148(%ebp)\n"
        "movsd 0x307c10, %xmm5\n" /* 1.0 */
        "movsd 0x307c78, %xmm6\n" /* -1.0 */
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        ".Lf1e9024_001e9ab2:\n"
        "movl -0x124(%ebp), %ecx\n" /* line 378 */
        "movl (%ecx), %esi\n" /* ct */
        "movl -0x68(%ebp), %ebx\n" /* line 382 | q */
        "cmpl %ebx, -0x60(%ebp)\n" /* q */
        "jle .Lf1e9024_001e9ae7\n"
        "movl -0x64(%ebp), %edi\n" /* line 252 | stack */
        "leal (%esi, %edi), %ecx\n" /* subvect_size */
        "movl -0xf4(%ebp), %edx\n" /* t */
        "addl %edi, %edx\n" /* stack */
        "xorl %ebx, %ebx\n" /* r2 */
        ".Lf1e9024_001e9ad2:\n"
        "movl (%ecx), %eax\n" /* line 383 */
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* q */
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "cmpl -0x14c(%ebp), %ebx\n" /* line 382 | q */
        "jne .Lf1e9024_001e9ad2\n"
        /* { scope 4: i, shape */
        ".Lf1e9024_001e9ae7:\n"
        "movl -0x11c(%ebp), %edx\n" /* line 390 */
        "movl (%edx), %eax\n"
        "cmpl %eax, -0xc0(%ebp)\n" /* line 391 | shape_cb_size */
        "jle .Lf1e9024_001e9ed9\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "imull -0xbc(%ebp), %eax\n" /* line 396 | subvect_size */
        "movl -0xfc(%ebp), %edi\n" /* resp, stack */
        "leal (%edi, %eax, 4), %ecx\n" /* stack */
        "ucomiss %xmm7, %xmm0\n" /* line 397 */
        "jbe .Lf1e9024_001e9f00\n"
        ".Lf1e9024_001e9b1c:\n"
        "movl -0xbc(%ebp), %edi\n" /* line 398 | subvect_size, stack */
        "testl %edi, %edi\n" /* stack */
        "jle .Lf1e9024_001e9b4c\n"
        "movl -0xf4(%ebp), %eax\n" /* t */
        "addl -0x64(%ebp), %eax\n"
        "xorl %edx, %edx\n"
        ".Lf1e9024_001e9b31:\n"
        "movss (%eax), %xmm0\n" /* line 399 */
        "subss (%ecx, %edx, 4), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 398 */
        "addl $4, %eax\n"
        "cmpl %edx, -0xbc(%ebp)\n" /* subvect_size */
        "jne .Lf1e9024_001e9b31\n"
        /* } scope */
        ".Lf1e9024_001e9b4c:\n"
        "movl -0x38(%ebp), %eax\n" /* line 406 */
        "movl -0xe4(%ebp), %edx\n" /* odist */
        "movss (%edx, %eax, 4), %xmm3\n"
        "movl -0x68(%ebp), %ecx\n" /* line 407 */
        "cmpl %ecx, -0x60(%ebp)\n"
        "jle .Lf1e9024_001e9b87\n"
        "movl -0xf4(%ebp), %eax\n" /* t */
        "addl -0x64(%ebp), %eax\n"
        "xorl %edx, %edx\n"
        ".Lf1e9024_001e9b6d:\n"
        "movss (%eax), %xmm0\n" /* line 408 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl -0x150(%ebp), %edx\n" /* line 407 */
        "jne .Lf1e9024_001e9b6d\n"
        ".Lf1e9024_001e9b87:\n"
        "movl -0x108(%ebp), %ebx\n" /* line 410 | q */
        "movss (%ebx), %xmm0\n" /* q */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lf1e9024_001e9c5f\n"
        "ucomiss 0x2ed5dc, %xmm0\n" /* -1.0f */
        "jb .Lf1e9024_001e9c59\n"
        ".Lf1e9024_001e9ba7:\n"
        "movl -0xb4(%ebp), %edx\n" /* N */
        /* } scope */
        ".Lf1e9024_001e9bad:\n"
        "addl $1, -0x104(%ebp)\n" /* line 374 | k */
        "addl $4, -0x11c(%ebp)\n"
        "cmpl %edx, -0x104(%ebp)\n" /* k */
        "jne .Lf1e9024_001e9ab2\n"
        "movl -0x30(%ebp), %ebx\n" /* line 465 | q */
        "testl %ebx, %ebx\n" /* q */
        "je .Lf1e9024_001e9f9c\n"
        /* } scope */
        "addl $1, -0x38(%ebp)\n" /* line 364 */
        "addl $4, -0x124(%ebp)\n"
        "cmpl %edx, -0x38(%ebp)\n"
        "je .Lf1e9024_001e9f9c\n"
        "movl -0x124(%ebp), %esi\n" /* subvect_size */
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        "movl -0x64(%ebp), %eax\n" /* line 366 | x */
        "addl (%esi), %eax\n" /* subvect_size, x */
        "movl -0xa8(%ebp), %edx\n" /* line 368 | have_sign */
        "testl %edx, %edx\n"
        "jne .Lf1e9024_001e9a27\n"
        ".Lf1e9024_001e9bff:\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 371 | q */
        "movl %ebx, 0x20(%esp)\n" /* q */
        "movl -0xac(%ebp), %esi\n" /* best_dist, subvect_size */
        "movl %esi, 0x1c(%esp)\n" /* subvect_size */
        "movl -0xb0(%ebp), %edi\n" /* best_index, stack */
        "movl %edi, 0x18(%esp)\n" /* stack */
        "movl -0xb4(%ebp), %edx\n" /* N */
        "movl %edx, 0x14(%esp)\n"
        "movl -0xf8(%ebp), %ecx\n" /* E */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0xc0(%ebp), %ebx\n" /* shape_cb_size, q */
        "movl %ebx, 0xc(%esp)\n" /* q */
        "movl -0xbc(%ebp), %esi\n" /* subvect_size */
        "movl %esi, 8(%esp)\n" /* subvect_size */
        "movl -0xfc(%ebp), %edi\n" /* resp, stack */
        "movl %edi, 4(%esp)\n" /* stack */
        "movl %eax, (%esp)\n"
        "calll vq_nbest\n"
        "jmp .Lf1e9024_001e9a7c\n"
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        ".Lf1e9024_001e9c59:\n"
        "jp .Lf1e9024_001e9ba7\n" /* line 410 */
        ".Lf1e9024_001e9c5f:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 414 */
        "cmpl %ecx, 0x20(%ebp)\n" /* nsf */
        "jle .Lf1e9024_001e9c91\n"
        "movl -0x120(%ebp), %ebx\n" /* line 252 | r2 */
        "leal (%esi, %ebx), %ecx\n" /* subvect_size */
        "movl -0xf4(%ebp), %edx\n" /* t */
        "addl %ebx, %edx\n" /* r2 */
        "xorl %ebx, %ebx\n" /* r2 */
        ".Lf1e9024_001e9c7a:\n"
        "movl (%ecx), %eax\n" /* line 415 */
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* q */
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "movl 0x20(%ebp), %eax\n" /* line 414 | nsf */
        "subl -0x60(%ebp), %eax\n"
        "cmpl %eax, %ebx\n" /* q */
        "jne .Lf1e9024_001e9c7a\n"
        ".Lf1e9024_001e9c91:\n"
        "movl -0xbc(%ebp), %esi\n" /* line 417 | subvect_size, ct */
        "testl %esi, %esi\n" /* ct */
        "jle .Lf1e9024_001e9d3f\n"
        "movl -0xbc(%ebp), %esi\n" /* subvect_size, ct */
        "movl 0x28(%ebp), %edi\n" /* r, stack */
        "leal (%edi, %esi, 4), %ebx\n" /* stack, q */
        "xorl %esi, %esi\n" /* ct */
        "movsd 0x307db8, %xmm4\n" /* 0.03125 */
        /* { scope 4: i, shape */
        ".Lf1e9024_001e9cb5:\n"
        "movl -0x11c(%ebp), %eax\n" /* line 422 */
        "movl (%eax), %edx\n"
        "cmpl %edx, -0xc0(%ebp)\n" /* line 423 | shape_cb_size */
        "jle .Lf1e9024_001e9eca\n"
        "movapd %xmm5, %xmm1\n"
        ".Lf1e9024_001e9ccd:\n"
        "mulsd %xmm4, %xmm1\n" /* line 435 */
        "imull -0xbc(%ebp), %edx\n" /* subvect_size */
        "movl -0xc4(%ebp), %ecx\n" /* shape_cb */
        "leal (%esi, %ecx), %eax\n" /* ct */
        "movsbl (%eax, %edx), %eax\n"
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm2\n"
        "movl -0x60(%ebp), %edi\n" /* line 436 | stack */
        "cmpl %edi, 0x20(%ebp)\n" /* stack, nsf */
        "jle .Lf1e9024_001e9d2d\n"
        "movl -0xf4(%ebp), %eax\n" /* t */
        "addl -0x154(%ebp), %eax\n"
        "movl %ebx, %edx\n" /* q */
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001e9d09:\n"
        "movaps %xmm2, %xmm1\n" /* line 437 */
        "mulss (%edx), %xmm1\n"
        "movss (%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %ecx\n"
        "addl $4, %eax\n"
        "addl $4, %edx\n"
        "cmpl -0x148(%ebp), %ecx\n" /* line 436 */
        "jne .Lf1e9024_001e9d09\n"
        /* } scope */
        ".Lf1e9024_001e9d2d:\n"
        "addl $1, %esi\n" /* line 417 | ct */
        "subl $4, %ebx\n" /* q */
        "cmpl %esi, -0xbc(%ebp)\n" /* ct, subvect_size */
        "jne .Lf1e9024_001e9cb5\n"
        ".Lf1e9024_001e9d3f:\n"
        "movl -0xe8(%ebp), %eax\n" /* line 444 | ndist */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf1e9024_001e9f39\n"
        ".Lf1e9024_001e9d52:\n"
        "movl $0, -0x44(%ebp)\n"
        "movl $0, -0x10c(%ebp)\n"
        "movl $0, -0x48(%ebp)\n"
        "movl -0x44(%ebp), %edi\n" /* stack */
        ".Lf1e9024_001e9d6d:\n"
        "movl -0xb4(%ebp), %esi\n" /* line 446 | N, ct */
        "subl $1, %esi\n" /* ct */
        "movl %esi, -0x100(%ebp)\n" /* ct, n */
        "cmpl %edi, %esi\n" /* stack, ct */
        "jle .Lf1e9024_001e9e1a\n"
        "shll $2, %esi\n" /* ct */
        "movl %esi, -0x5c(%ebp)\n" /* ct */
        "movl -0xd4(%ebp), %eax\n" /* line 252 | nt, complexity */
        "addl %esi, %eax\n" /* subvect_size, complexity */
        "movl %eax, -0x58(%ebp)\n" /* complexity */
        ".Lf1e9024_001e9d95:\n"
        "movl -0x60(%ebp), %ebx\n" /* line 448 | q */
        "cmpl %ebx, 0x20(%ebp)\n" /* q, nsf */
        "jle .Lf1e9024_001e9dc0\n"
        "movl %ebx, %ecx\n" /* q */
        "xorl %ebx, %ebx\n" /* line 252 | r2 */
        "shll $2, %ecx\n"
        ".Lf1e9024_001e9da4:\n"
        "movl -0x58(%ebp), %edx\n" /* line 449 */
        "movl (%edx), %eax\n"
        "movl -4(%edx), %edx\n"
        "movl (%edx, %ecx), %edx\n"
        "movl %edx, (%eax, %ecx)\n"
        "addl $1, %ebx\n" /* q */
        "addl $4, %ecx\n"
        "cmpl -0x158(%ebp), %ebx\n" /* line 448 | q */
        "jne .Lf1e9024_001e9da4\n"
        ".Lf1e9024_001e9dc0:\n"
        "movl -0xd0(%ebp), %edi\n" /* nind, stack */
        "addl -0x5c(%ebp), %edi\n" /* stack */
        "leal -4(%edi), %esi\n" /* stack, ct */
        "xorl %ebx, %ebx\n" /* q */
        ".Lf1e9024_001e9dce:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl (%edi), %ecx\n" /* line 451 | stack */
        "movl (%esi), %eax\n" /* ct */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 450 | q */
        "cmpl %ebx, -0xb8(%ebp)\n" /* q, nb_subvect */
        "jne .Lf1e9024_001e9dce\n"
        "movl -0xe8(%ebp), %edi\n" /* line 452 | ndist, stack */
        "movl -0x5c(%ebp), %edx\n"
        "movl -4(%edi, %edx), %eax\n" /* stack */
        "movl %eax, (%edi, %edx)\n" /* stack */
        "subl $1, -0x100(%ebp)\n" /* line 446 | n */
        "subl $4, %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        "subl $4, -0x58(%ebp)\n"
        "movl -0x44(%ebp), %ecx\n"
        "cmpl %ecx, -0x100(%ebp)\n" /* n */
        "jg .Lf1e9024_001e9d95\n"
        ".Lf1e9024_001e9e1a:\n"
        "movl -0x60(%ebp), %esi\n" /* line 454 | ct */
        "cmpl %esi, 0x20(%ebp)\n" /* ct, nsf */
        "jle .Lf1e9024_001e9e53\n"
        "movl -0xd4(%ebp), %edi\n" /* nt, stack */
        "addl -0x48(%ebp), %edi\n" /* stack */
        "movl -0x120(%ebp), %ebx\n" /* line 252 | r2 */
        "movl -0xf4(%ebp), %ecx\n" /* t */
        "addl %ebx, %ecx\n" /* r2 */
        "xorl %esi, %esi\n" /* subvect_size */
        ".Lf1e9024_001e9e3b:\n"
        "movl (%edi), %edx\n" /* line 455 | stack */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx, %ebx)\n"
        "addl $1, %esi\n" /* ct */
        "addl $4, %ebx\n" /* q */
        "addl $4, %ecx\n"
        "cmpl -0x15c(%ebp), %esi\n" /* line 454 | ct */
        "jne .Lf1e9024_001e9e3b\n"
        ".Lf1e9024_001e9e53:\n"
        "movl -0xd0(%ebp), %edi\n" /* nind, stack */
        "addl -0x48(%ebp), %edi\n" /* stack */
        "movl %edi, -0x174(%ebp)\n" /* stack */
        "xorl %ebx, %ebx\n" /* q */
        "movl %edi, %eax\n" /* stack */
        "jmp .Lf1e9024_001e9e6e\n"
        ".Lf1e9024_001e9e68:\n"
        "movl -0x174(%ebp), %eax\n"
        ".Lf1e9024_001e9e6e:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl (%eax), %ecx\n" /* line 457 */
        "movl -0x38(%ebp), %esi\n" /* ct */
        "movl -0xcc(%ebp), %edi\n" /* oind, stack */
        "movl (%edi, %esi, 4), %eax\n" /* stack */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 456 | q */
        "cmpl %ebx, -0xb8(%ebp)\n" /* q, nb_subvect */
        "jne .Lf1e9024_001e9e68\n"
        "movl -0x10c(%ebp), %ecx\n" /* line 458 */
        "shll $2, %ecx\n"
        "movl -0xd0(%ebp), %eax\n" /* nind */
        "movl (%eax, %ecx), %edx\n"
        "movl -0x11c(%ebp), %ebx\n" /* q */
        "movl (%ebx), %eax\n" /* q */
        "movl -0x54(%ebp), %esi\n" /* ct */
        "movl %eax, (%edx, %esi)\n"
        "movl -0xe8(%ebp), %edi\n" /* line 459 | ndist, stack */
        "movss %xmm3, (%edi, %ecx)\n" /* stack */
        "movl -0xb4(%ebp), %edx\n" /* N */
        "jmp .Lf1e9024_001e9bad\n"
        /* { scope 4: i, shape */
        ".Lf1e9024_001e9eca:\n"
        "subl -0xc0(%ebp), %edx\n" /* line 426 | shape_cb_size */
        "movapd %xmm6, %xmm1\n"
        "jmp .Lf1e9024_001e9ccd\n"
        /* } scope */
        /* { scope 4: i, shape */
        ".Lf1e9024_001e9ed9:\n"
        "subl -0xc0(%ebp), %eax\n" /* line 394 | shape_cb_size */
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        "imull -0xbc(%ebp), %eax\n" /* line 396 | subvect_size */
        "movl -0xfc(%ebp), %edi\n" /* resp, stack */
        "leal (%edi, %eax, 4), %ecx\n" /* stack */
        "ucomiss %xmm7, %xmm0\n" /* line 397 */
        "ja .Lf1e9024_001e9b1c\n"
        ".Lf1e9024_001e9f00:\n"
        "movl -0xbc(%ebp), %eax\n" /* line 401 | subvect_size */
        "testl %eax, %eax\n"
        "jle .Lf1e9024_001e9b4c\n"
        "movl -0xf4(%ebp), %eax\n" /* t */
        "addl -0x64(%ebp), %eax\n"
        "xorl %edx, %edx\n"
        ".Lf1e9024_001e9f19:\n"
        "movss (%eax), %xmm0\n" /* line 402 */
        "addss (%ecx, %edx, 4), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 401 */
        "addl $4, %eax\n"
        "cmpl %edx, -0xbc(%ebp)\n" /* subvect_size */
        "jne .Lf1e9024_001e9f19\n"
        "jmp .Lf1e9024_001e9b4c\n"
        /* } scope */
        ".Lf1e9024_001e9f39:\n"
        "movss 0x2ed5dc, %xmm1\n" /* line 444 | -1.0f */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1e9024_001e9d52\n"
        "movl $0, -0x44(%ebp)\n" /* line 460 */
        ".Lf1e9024_001e9f51:\n"
        "addl $1, -0x44(%ebp)\n" /* line 442 */
        "movl -0xb4(%ebp), %eax\n" /* N */
        "cmpl %eax, -0x44(%ebp)\n"
        "je .Lf1e9024_001e9f8e\n"
        "movl -0x44(%ebp), %edx\n" /* line 444 */
        "movl %edx, -0x10c(%ebp)\n"
        "movl %edx, %ecx\n"
        "shll $2, %ecx\n"
        "movl %ecx, -0x48(%ebp)\n"
        "movl -0xe8(%ebp), %ebx\n" /* ndist, q */
        "movss (%ebx, %edx, 4), %xmm0\n" /* q */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lf1e9024_001e9f95\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1e9024_001e9f51\n"
        "movl -0x44(%ebp), %edi\n" /* stack */
        "jmp .Lf1e9024_001e9d6d\n"
        ".Lf1e9024_001e9f8e:\n"
        "movl %eax, %edx\n"
        "jmp .Lf1e9024_001e9bad\n"
        ".Lf1e9024_001e9f95:\n"
        "movl %edx, %edi\n" /* stack */
        "jmp .Lf1e9024_001e9d6d\n"
        /* } scope */
        /* } scope */
        ".Lf1e9024_001e9f9c:\n"
        "xorl %esi, %esi\n" /* line 477 | ct */
        ".Lf1e9024_001e9f9e:\n"
        "xorl %ebx, %ebx\n" /* q */
        ".Lf1e9024_001e9fa0:\n"
        "leal (, %esi, 4), %eax\n" /* line 252 | complexity */
        "leal (, %ebx, 4), %edx\n"
        "movl -0xcc(%ebp), %edi\n" /* line 479 | oind, stack */
        "movl (%edi, %eax), %ecx\n" /* stack */
        "movl -0xd0(%ebp), %edi\n" /* nind, stack */
        "movl (%edi, %eax), %eax\n" /* stack */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 478 | q */
        "cmpl %ebx, -0xb8(%ebp)\n" /* q, nb_subvect */
        "jne .Lf1e9024_001e9fa0\n"
        "addl $1, %esi\n" /* line 477 | ct */
        "cmpl -0xb4(%ebp), %esi\n" /* N, ct */
        "jne .Lf1e9024_001e9f9e\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001e9fde:\n"
        "leal (, %ecx, 4), %edx\n" /* line 252 */
        "movl -0xe8(%ebp), %ebx\n" /* line 481 | ndist, q */
        "movl (%ebx, %edx), %eax\n" /* q */
        "movl -0xe4(%ebp), %esi\n" /* odist, ct */
        "movl %eax, (%esi, %edx)\n" /* ct */
        "addl $1, %ecx\n" /* line 480 */
        "cmpl -0xb4(%ebp), %ecx\n" /* N */
        "jne .Lf1e9024_001e9fde\n"
        "movl -0x114(%ebp), %edi\n" /* stack */
        "movl %edi, -0x30(%ebp)\n" /* line 357 | stack */
        "movl -0xd8(%ebp), %eax\n" /* ot */
        "movl -0xd4(%ebp), %edx\n" /* nt */
        "movl %edx, -0xd8(%ebp)\n" /* ot */
        "cmpl %edi, -0xb8(%ebp)\n" /* stack, nb_subvect */
        "jne .Lf1e9024_001e996e\n"
        ".Lf1e9024_001ea029:\n"
        "xorl %ebx, %ebx\n" /* line 360 | q */
        ".Lf1e9024_001ea02b:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl -0xd0(%ebp), %esi\n" /* line 487 | nind, ct */
        "movl (%esi), %eax\n" /* ct */
        "movl (%eax, %edx), %ecx\n"
        "movl -0xc8(%ebp), %edi\n" /* ind, stack */
        "movl %ecx, (%edi, %edx)\n" /* stack */
        "movl -0xa8(%ebp), %eax\n" /* line 488 | have_sign */
        "movl 0x18(%ebp), %edx\n" /* par */
        "addl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl 0x2c(%ebp), %ecx\n" /* bits */
        "movl %ecx, (%esp)\n"
        "calll speex_bits_pack\n"
        "addl $1, %ebx\n" /* line 485 | q */
        "cmpl %ebx, -0xb8(%ebp)\n" /* q, nb_subvect */
        "jne .Lf1e9024_001ea02b\n"
        "xorl %esi, %esi\n" /* ct */
        "movsd 0x307db8, %xmm2\n" /* 0.03125 */
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movss 0x2ed5dc, %xmm4\n" /* -1.0f */
        "xorl %edi, %edi\n" /* stack */
        "movl -0xbc(%ebp), %ebx\n" /* subvect_size, q */
        "shll $2, %ebx\n" /* q */
        "movl %ebx, -0x118(%ebp)\n" /* q */
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        ".Lf1e9024_001ea09b:\n"
        "movl -0xc8(%ebp), %edx\n" /* line 496 | ind */
        "movl (%edx, %esi, 4), %eax\n"
        "cmpl %eax, -0xc0(%ebp)\n" /* line 497 | shape_cb_size */
        "jle .Lf1e9024_001ea1c9\n"
        "movaps %xmm3, %xmm0\n"
        ".Lf1e9024_001ea0b3:\n"
        "movl -0xbc(%ebp), %edx\n" /* line 512 | subvect_size */
        "testl %edx, %edx\n"
        "jle .Lf1e9024_001ea102\n"
        "cvtss2sd %xmm0, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "imull -0xbc(%ebp), %eax\n" /* subvect_size */
        "movl -0xf0(%ebp), %ecx\n" /* e */
        "addl %edi, %ecx\n" /* stack */
        "xorl %ebx, %ebx\n" /* q */
        "movl -0xc4(%ebp), %edx\n" /* shape_cb */
        "addl %eax, %edx\n"
        ".Lf1e9024_001ea0de:\n"
        "movsbl (%edx), %eax\n" /* line 513 */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "addl $1, %ebx\n" /* line 512 | q */
        "addl $1, %edx\n"
        "addl $4, %ecx\n"
        "cmpl %ebx, -0xbc(%ebp)\n" /* q, subvect_size */
        "jne .Lf1e9024_001ea0de\n"
        /* } scope */
        ".Lf1e9024_001ea102:\n"
        "addl $1, %esi\n" /* line 492 | ct */
        "addl -0x118(%ebp), %edi\n" /* stack */
        "cmpl %esi, -0xb8(%ebp)\n" /* ct, nb_subvect */
        "jne .Lf1e9024_001ea09b\n"
        ".Lf1e9024_001ea113:\n"
        "movl 0x20(%ebp), %edi\n" /* line 517 | nsf, stack */
        "testl %edi, %edi\n" /* stack */
        "jle .Lf1e9024_001ea143\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001ea11c:\n"
        "leal (, %ecx, 4), %eax\n" /* line 252 | complexity */
        "movl 0x24(%ebp), %edx\n" /* exc */
        "addl %eax, %edx\n" /* complexity */
        "movss (%edx), %xmm0\n" /* line 518 */
        "movl -0xf0(%ebp), %ebx\n" /* e, q */
        "addss (%ebx, %eax), %xmm0\n" /* q */
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 517 */
        "cmpl %ecx, 0x20(%ebp)\n" /* nsf */
        "jne .Lf1e9024_001ea11c\n"
        ".Lf1e9024_001ea143:\n"
        "movl 0x38(%ebp), %esi\n" /* line 521 | update_target, ct */
        "testl %esi, %esi\n" /* ct */
        "je .Lf1e9024_001e9477\n"
        "movl -0x3c(%ebp), %esi\n" /* line 523 | ct */
        "movl %esi, 0x1c(%esp)\n" /* ct */
        "movl 0x1c(%ebp), %edi\n" /* p, stack */
        "movl %edi, 0x18(%esp)\n" /* stack */
        "movl 0x20(%ebp), %eax\n" /* nsf */
        "movl %eax, 0x14(%esp)\n"
        "movl -0xec(%ebp), %edx\n" /* r2 */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* awk2 */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %ebx\n" /* awk1, q */
        "movl %ebx, 8(%esp)\n" /* q */
        "movl 0xc(%ebp), %esi\n" /* ak, ct */
        "movl %esi, 4(%esp)\n" /* ct */
        "movl -0xf0(%ebp), %edi\n" /* e, stack */
        "movl %edi, (%esp)\n" /* stack */
        "calll syn_percep_zero\n"
        "movl 0x20(%ebp), %ebx\n" /* line 524 | nsf, q */
        "testl %ebx, %ebx\n" /* q */
        "jle .Lf1e9024_001e9477\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001ea19d:\n"
        "leal (, %ecx, 4), %eax\n" /* line 252 | complexity */
        "movl 8(%ebp), %edx\n" /* target */
        "addl %eax, %edx\n" /* complexity */
        "movss (%edx), %xmm0\n" /* line 525 */
        "movl -0xec(%ebp), %ebx\n" /* r2, q */
        "subss (%ebx, %eax), %xmm0\n" /* q */
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 524 */
        "cmpl %ecx, 0x20(%ebp)\n" /* nsf */
        "jne .Lf1e9024_001ea19d\n"
        "jmp .Lf1e9024_001e9477\n"
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        ".Lf1e9024_001ea1c9:\n"
        "subl -0xc0(%ebp), %eax\n" /* line 500 | shape_cb_size */
        "movaps %xmm4, %xmm0\n"
        "jmp .Lf1e9024_001ea0b3\n"
        /* } scope */
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        /* { scope 4: i, shape */
        ".Lf1e9024_001ea1d7:\n"
        "movl -0xa4(%ebp), %eax\n" /* line 229 */
        "addl -0x50(%ebp), %eax\n"
        "movl %eax, %ebx\n" /* r2 */
        "subl -0xa4(%ebp), %ebx\n" /* r2 */
        "movl %eax, 0x1c(%esp)\n" /* line 230 */
        "movl 0x1c(%ebp), %esi\n" /* p, subvect_size */
        "movl %esi, 0x18(%esp)\n" /* subvect_size */
        "movl 0x20(%ebp), %edi\n" /* nsf */
        "movl %edi, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* r2 */
        "movl 0x14(%ebp), %eax\n" /* awk2 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* awk1 */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* ak */
        "movl %ecx, 4(%esp)\n"
        "movl -0x9c(%ebp), %esi\n" /* e, subvect_size */
        "movl %esi, (%esp)\n" /* subvect_size */
        "calll syn_percep_zero\n"
        "testl %edi, %edi\n" /* line 231 */
        "jle .Lf1e9024_001e9477\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e9024_001ea22b:\n"
        "leal (, %ecx, 4), %eax\n" /* line 252 | complexity */
        "movl 8(%ebp), %edx\n" /* target */
        "addl %eax, %edx\n" /* complexity */
        "movss (%edx), %xmm0\n" /* line 232 */
        "subss (%ebx, %eax), %xmm0\n" /* r2 */
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 231 */
        "cmpl %ecx, 0x20(%ebp)\n" /* nsf */
        "jne .Lf1e9024_001ea22b\n"
        "jmp .Lf1e9024_001e9477\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1e9024_001ea251:\n"
        "movl %eax, -0xb4(%ebp)\n" /* line 289 | N */
        "jmp .Lf1e9024_001e9491\n"
        /* { scope 2: t, e, nb_subvect, best_index, ... */
        /* { scope 3: stack, shape_cb_size, E, resp2, ... */
        /* { scope 4: i, shape */
        ".Lf1e9024_001ea25c:\n"
        "subl -0x8c(%ebp), %edx\n" /* line 204 | shape_cb_size */
        "movsd 0x307c78, %xmm1\n" /* -1.0 */
        "jmp .Lf1e9024_001e93c9\n"
        /* } scope */
        ".Lf1e9024_001ea26f:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 195 */
        "movl -0x140(%ebp), %ecx\n"
        "addl %ecx, -0x13c(%ebp)\n"
        "addl %esi, -0x138(%ebp)\n" /* subvect_size */
        "jmp .Lf1e9024_001e942d\n"
        ".Lf1e9024_001ea28a:\n"
        "movl -0x90(%ebp), %edx\n" /* line 157 | stack */
        "movl %edx, 0x20(%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* best_dist */
        "movl %ecx, 0x1c(%esp)\n"
        "leal -0x1c(%ebp), %edi\n" /* best_index */
        "movl %edi, 0x18(%esp)\n"
        "movl $1, 0x14(%esp)\n"
        "movl -0x88(%ebp), %eax\n" /* E */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x8c(%ebp), %edx\n" /* shape_cb_size */
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* subvect_size */
        "movl -0x84(%ebp), %ecx\n" /* resp2 */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* j */
        "calll vq_nbest\n"
        "jmp .Lf1e9024_001e92bd\n"
        /* { scope 4: i, shape */
        ".Lf1e9024_001ea2d9:\n"
        "subl -0x8c(%ebp), %eax\n" /* line 169 | shape_cb_size */
        "movss 0x2ed5dc, %xmm1\n" /* -1.0f */
        "jmp .Lf1e9024_001e92f6\n"
        ".Lf1e9024_001ea2ec:\n"
        "testl %esi, %esi\n" /* line 176 | subvect_size */
        "jle .Lf1e9024_001ea26f\n"
        "movl %ebx, %eax\n" /* j */
        "xorl %edx, %edx\n"
        ".Lf1e9024_001ea2f8:\n"
        "movss (%eax), %xmm0\n" /* line 177 */
        "addss (%ecx, %edx, 4), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 176 */
        "addl $4, %eax\n"
        "cmpl %edx, %esi\n" /* subvect_size */
        "jne .Lf1e9024_001ea2f8\n"
        "jmp .Lf1e9024_001e9334\n"
    );
}

