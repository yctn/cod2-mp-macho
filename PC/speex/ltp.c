/* ASM dump from: ltp.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/ltp.c */

#include "common_types.h"
#include "imports.h"

void pitch_unquant_3tap(spx_sig_t *exc, int start, int end, spx_word16_t pitch_coef, const void *par, int nsf, int *pitch_val, spx_word16_t *gain_val, SpeexBits *bits, char *stack, int count_lost, int subframe_offset, spx_word16_t last_pitch_gain, int cdbk_offset);
int forced_pitch_quant(spx_sig_t *target, spx_sig_t *sw, spx_coef_t *ak, spx_coef_t *awk1, spx_coef_t *awk2, spx_sig_t *exc, const void *par, int start, int end, spx_word16_t pitch_coef, int p, int nsf, SpeexBits *bits, char *stack, spx_sig_t *exc2, spx_word16_t *r, int complexity, int cdbk_offset, int plc_tuning);
void forced_pitch_unquant(spx_sig_t *exc, int start, int end, spx_word16_t pitch_coef, const void *par, int nsf, int *pitch_val, spx_word16_t *gain_val, SpeexBits *bits, char *stack, int count_lost, int subframe_offset, spx_word16_t last_pitch_gain, int cdbk_offset);
void open_loop_nbest_pitch(spx_sig_t *sw, int start, int end, int len, int *pitch, spx_word16_t *gain, int N, char *stack);
int pitch_search_3tap(spx_sig_t *target, spx_sig_t *sw, spx_coef_t *ak, spx_coef_t *awk1, spx_coef_t *awk2, spx_sig_t *exc, const void *par, int start, int end, spx_word16_t pitch_coef, int p, int nsf, SpeexBits *bits, char *stack, spx_sig_t *exc2, spx_word16_t *r, int complexity, int cdbk_offset, int plc_tuning);

/* line 656 */
__attribute__((naked))
void pitch_unquant_3tap(spx_sig_t *exc, int start, int end, spx_word16_t pitch_coef, const void *par, int nsf, int *pitch_val, spx_word16_t *gain_val, SpeexBits *bits, char *stack, int count_lost, int subframe_offset, spx_word16_t last_pitch_gain, int cdbk_offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 656 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x18(%ebp), %esi\n" /* par */
        "movl 0x28(%ebp), %edi\n" /* bits */
        /* { scope 1: e */
        "movl 4(%esi), %ecx\n" /* line 668 | par */
        "movl $1, %ebx\n" /* gain_cdbk */
        "shll %cl, %ebx\n" /* gain_cdbk */
        "imull 0x3c(%ebp), %ebx\n" /* cdbk_offset, gain_cdbk */
        "leal (%ebx, %ebx, 2), %ebx\n" /* gain_cdbk */
        "addl (%esi), %ebx\n" /* par, gain_cdbk */
        "movl 8(%esi), %eax\n" /* line 670 | par */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "addl 0xc(%ebp), %eax\n" /* line 671 | start */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%esi), %eax\n" /* line 672 | par */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 679 */
        "movsbl (%ebx, %eax), %edx\n" /* gain_cdbk */
        "cvtsi2sdl %edx, %xmm0\n"
        "movsd 0x307e78, %xmm2\n" /* 0.015625 */
        "mulsd %xmm2, %xmm0\n"
        "movsd 0x307ce0, %xmm1\n" /* 0.5 */
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm3\n"
        "movss %xmm3, -0x24(%ebp)\n" /* gain */
        "addl %eax, %ebx\n" /* line 680 | gain_cdbk */
        "movsbl 1(%ebx), %eax\n" /* gain_cdbk */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm4\n"
        "movss %xmm4, -0x20(%ebp)\n"
        "movsbl 2(%ebx), %eax\n" /* line 681 | gain_cdbk */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movl 0x30(%ebp), %edx\n" /* line 684 | count_lost */
        "testl %edx, %edx\n"
        "je .Lf1ed5bc_001ed679\n"
        "movl -0x3c(%ebp), %eax\n"
        "cmpl 0x34(%ebp), %eax\n" /* subframe_offset */
        "jg .Lf1ed5bc_001ed7fe\n"
        "movl %eax, %edx\n"
        "jmp .Lf1ed5bc_001ed67c\n"
        ".Lf1ed5bc_001ed679:\n"
        "movl -0x3c(%ebp), %edx\n"
        ".Lf1ed5bc_001ed67c:\n"
        "movl 0x20(%ebp), %eax\n" /* line 704 | pitch_val */
        "movl %edx, (%eax)\n"
        "movl 0x24(%ebp), %ecx\n" /* line 705 | gain_val */
        "movss %xmm3, (%ecx)\n"
        "movss %xmm4, 4(%ecx)\n" /* line 706 */
        "movss -0x1c(%ebp), %xmm5\n" /* line 707 */
        "movss %xmm5, 8(%ecx)\n"
        /* { scope 2 */
        "movl 0x2c(%ebp), %eax\n" /* line 712 | stack */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl 0x2c(%ebp), %eax\n" /* stack */
        "movl %eax, -0x30(%ebp)\n" /* line 713 | e */
        "movl 0x1c(%ebp), %esi\n" /* line 714 | nsf, par */
        "leal (%eax, %esi, 4), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "leal (%eax, %esi, 8), %eax\n" /* line 715 */
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "leal 1(%edx, %edx), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "shll $2, %eax\n"
        "movl 8(%ebp), %ecx\n" /* exc */
        "subl %eax, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl $1, -0x4c(%ebp)\n"
        "movl $4, -0x54(%ebp)\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1ed5bc_001ed6e3:\n"
        "movl -0x48(%ebp), %esi\n" /* line 735 | tmp1 */
        "cmpl %esi, 0x1c(%ebp)\n" /* tmp1, nsf */
        "cmovlel 0x1c(%ebp), %esi\n" /* nsf, tmp1 */
        "testl %esi, %esi\n" /* line 737 | tmp1 */
        "jle .Lf1ed5bc_001ed70c\n"
        "movl -0x54(%ebp), %eax\n" /* line 738 */
        "movl -0x34(%eax, %ebp), %ebx\n" /* gain_cdbk */
        "movl -0x40(%ebp), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ed5bc_001ed6fd:\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%ebx, %ecx, 4)\n" /* gain_cdbk */
        "addl $1, %ecx\n" /* line 737 */
        "addl $4, %edx\n"
        "cmpl %ecx, %esi\n" /* tmp1 */
        "jne .Lf1ed5bc_001ed6fd\n"
        ".Lf1ed5bc_001ed70c:\n"
        "movl -0x44(%ebp), %edx\n" /* line 740 */
        "cmpl %edx, 0x1c(%ebp)\n" /* nsf */
        "movl 0x1c(%ebp), %edi\n" /* nsf, tmp3 */
        "cmovgl %edx, %edi\n" /* tmp3 */
        "cmpl %edi, %esi\n" /* line 742 | tmp3, tmp1 */
        "jge .Lf1ed5bc_001ed74d\n"
        "movl %esi, %eax\n" /* tmp1 */
        "subl -0x48(%ebp), %eax\n"
        "subl -0x3c(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* exc */
        "leal (%edx, %eax, 4), %ecx\n"
        "movl -0x54(%ebp), %edx\n"
        "movl -0x34(%edx, %ebp), %eax\n"
        "leal (%eax, %esi, 4), %edx\n"
        "xorl %ebx, %ebx\n" /* gain_cdbk */
        "movl %edi, %eax\n" /* tmp3 */
        "subl %esi, %eax\n" /* tmp1 */
        "movl %eax, %esi\n" /* tmp1 */
        ".Lf1ed5bc_001ed73c:\n"
        "movl (%ecx), %eax\n" /* line 743 */
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* gain_cdbk */
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %esi, %ebx\n" /* line 742 | tmp1, gain_cdbk */
        "jne .Lf1ed5bc_001ed73c\n"
        ".Lf1ed5bc_001ed74d:\n"
        "cmpl 0x1c(%ebp), %edi\n" /* line 744 | nsf, tmp3 */
        "jge .Lf1ed5bc_001ed773\n"
        "movl -0x54(%ebp), %edx\n"
        "movl -0x34(%edx, %ebp), %eax\n"
        "leal (%eax, %edi, 4), %eax\n"
        "xorl %edx, %edx\n"
        "movl 0x1c(%ebp), %ecx\n" /* nsf */
        "subl %edi, %ecx\n" /* tmp3 */
        ".Lf1ed5bc_001ed763:\n"
        "movl $0, (%eax)\n" /* line 745 */
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl %ecx, %edx\n" /* line 744 */
        "jne .Lf1ed5bc_001ed763\n"
        ".Lf1ed5bc_001ed773:\n"
        "addl $1, -0x4c(%ebp)\n"
        "addl $4, -0x54(%ebp)\n"
        "subl $1, -0x48(%ebp)\n"
        "subl $1, -0x44(%ebp)\n"
        "addl $4, -0x40(%ebp)\n"
        /* } scope */
        /* } scope */
        "cmpl $4, -0x4c(%ebp)\n" /* line 717 */
        "jne .Lf1ed5bc_001ed6e3\n"
        "movl 0x1c(%ebp), %eax\n" /* line 757 | nsf */
        "testl %eax, %eax\n"
        "jle .Lf1ed5bc_001ed7f6\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 758 | gain_cdbk */
        "movl -0x30(%ebp), %ecx\n" /* e */
        "xorl %edx, %edx\n"
        "movsd 0x307e80, %xmm2\n" /* 1e-15 */
        ".Lf1ed5bc_001ed7a8:\n"
        "leal (, %edx, 4), %eax\n" /* line 656 | pitch_val */
        "movaps %xmm3, %xmm1\n" /* line 758 */
        "movl -0x50(%ebp), %esi\n" /* tmp1 */
        "mulss (%esi, %eax), %xmm1\n" /* tmp1 */
        "cvtss2sd %xmm1, %xmm1\n"
        "addsd %xmm2, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss (%ebx, %eax), %xmm0\n" /* gain_cdbk */
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "mulss (%ecx, %eax), %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "movl 8(%ebp), %esi\n" /* exc, tmp1 */
        "movss %xmm0, (%esi, %eax)\n" /* tmp1 */
        "addl $1, %edx\n" /* line 757 */
        "cmpl %edx, 0x1c(%ebp)\n" /* nsf */
        "jne .Lf1ed5bc_001ed7a8\n"
        /* } scope */
        /* } scope */
        ".Lf1ed5bc_001ed7f6:\n"
        "addl $0x5c, %esp\n" /* line 761 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: e */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1ed5bc_001ed7fe:\n"
        "cmpl $3, 0x30(%ebp)\n" /* line 688 | count_lost */
        "jg .Lf1ed5bc_001ed8a5\n"
        "movss 0x38(%ebp), %xmm5\n" /* last_pitch_gain, tmp */
        ".Lf1ed5bc_001ed80d:\n"
        "cvtss2sd %xmm5, %xmm0\n" /* line 689 */
        "ucomisd 0x307e00, %xmm0\n" /* 0.95 */
        "jbe .Lf1ed5bc_001ed823\n"
        "movss 0x2edaac, %xmm5\n" /* 0.949999988079071f */
        ".Lf1ed5bc_001ed823:\n"
        "movss -0x20(%ebp), %xmm4\n" /* line 691 */
        "movaps %xmm4, %xmm0\n"
        "pxor %xmm6, %xmm6\n"
        "ucomiss %xmm4, %xmm6\n"
        "ja .Lf1ed5bc_001ed8bb\n"
        ".Lf1ed5bc_001ed838:\n"
        "cvtss2sd %xmm0, %xmm2\n"
        "movss -0x24(%ebp), %xmm3\n" /* gain */
        "ucomiss %xmm6, %xmm3\n"
        "jbe .Lf1ed5bc_001ed8d5\n"
        "cvtss2sd %xmm3, %xmm0\n"
        ".Lf1ed5bc_001ed84e:\n"
        "addsd %xmm0, %xmm2\n"
        "ucomiss %xmm6, %xmm1\n"
        "jbe .Lf1ed5bc_001ed8c7\n"
        "cvtss2sd %xmm1, %xmm0\n"
        ".Lf1ed5bc_001ed85b:\n"
        "addsd %xmm2, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "ucomiss %xmm5, %xmm0\n" /* line 693 */
        "jbe .Lf1ed5bc_001ed679\n"
        /* { scope 4 */
        "movaps %xmm5, %xmm1\n" /* line 694 | fact */
        "divss %xmm0, %xmm1\n" /* fact */
        "movl $1, %edx\n"
        "leal -0x20(%ebp), %eax\n"
        ".Lf1ed5bc_001ed87b:\n"
        "movaps %xmm1, %xmm0\n" /* line 696 */
        "mulss -4(%eax), %xmm0\n"
        "movss %xmm0, -4(%eax)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 695 */
        "jne .Lf1ed5bc_001ed87b\n"
        "movss -0x20(%ebp), %xmm4\n"
        "movss -0x24(%ebp), %xmm3\n" /* gain */
        "movl -0x3c(%ebp), %edx\n"
        "jmp .Lf1ed5bc_001ed67c\n"
        /* } scope */
        ".Lf1ed5bc_001ed8a5:\n"
        "cvtss2sd 0x38(%ebp), %xmm0\n" /* line 688 | last_pitch_gain */
        "mulsd 0x307e58, %xmm0\n" /* 0.4 */
        "cvtsd2ss %xmm0, %xmm5\n" /* tmp */
        "jmp .Lf1ed5bc_001ed80d\n"
        ".Lf1ed5bc_001ed8bb:\n"
        "xorps 0x305820, %xmm0\n" /* line 691 */
        "jmp .Lf1ed5bc_001ed838\n"
        ".Lf1ed5bc_001ed8c7:\n"
        "cvtss2sd %xmm1, %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "jmp .Lf1ed5bc_001ed85b\n"
        ".Lf1ed5bc_001ed8d5:\n"
        "cvtss2sd %xmm3, %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "jmp .Lf1ed5bc_001ed84e\n"
    );
}

/* line 785 */
__attribute__((naked))
int forced_pitch_quant(spx_sig_t *target, spx_sig_t *sw, spx_coef_t *ak, spx_coef_t *awk1, spx_coef_t *awk2, spx_sig_t *exc, const void *par, int start, int end, spx_word16_t pitch_coef, int p, int nsf, SpeexBits *bits, char *stack, spx_sig_t *exc2, spx_word16_t *r, int complexity, int cdbk_offset, int plc_tuning)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 785 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0x1c(%ebp), %ebx\n" /* exc */
        "movl 0x24(%ebp), %esi\n" /* start */
        "movss 0x2c(%ebp), %xmm1\n" /* pitch_coef */
        "movl 0x34(%ebp), %ecx\n" /* nsf */
        /* { scope 1 */
        "cvtss2sd %xmm1, %xmm0\n" /* line 789 */
        "ucomisd 0x307e88, %xmm0\n" /* 0.99 */
        "jbe .Lf1ed8e6_001ed90f\n"
        "movss 0x2ed858, %xmm1\n" /* 0.9900000095367432f */
        ".Lf1ed8e6_001ed90f:\n"
        "testl %ecx, %ecx\n" /* line 791 */
        "jle .Lf1ed8e6_001ed938\n"
        "leal (, %esi, 4), %eax\n"
        "movl %ebx, %edx\n" /* exc */
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "xorl %edx, %edx\n"
        ".Lf1ed8e6_001ed922:\n"
        "movaps %xmm1, %xmm0\n" /* line 793 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%ebx, %edx, 4)\n" /* exc */
        "addl $1, %edx\n" /* line 791 */
        "addl $4, %eax\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf1ed8e6_001ed922\n"
        /* } scope */
        ".Lf1ed8e6_001ed938:\n"
        "movl %esi, %eax\n" /* line 796 | start */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 814 */
__attribute__((naked))
void forced_pitch_unquant(spx_sig_t *exc, int start, int end, spx_word16_t pitch_coef, const void *par, int nsf, int *pitch_val, spx_word16_t *gain_val, SpeexBits *bits, char *stack, int count_lost, int subframe_offset, spx_word16_t last_pitch_gain, int cdbk_offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 814 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* exc */
        "movl 0xc(%ebp), %edi\n" /* start */
        "movss 0x14(%ebp), %xmm2\n" /* pitch_coef */
        "movl 0x1c(%ebp), %ebx\n" /* nsf */
        "movl 0x24(%ebp), %ecx\n" /* gain_val */
        /* { scope 1 */
        "cvtss2sd %xmm2, %xmm0\n" /* line 818 */
        "ucomisd 0x307e88, %xmm0\n" /* 0.99 */
        "jbe .Lf1ed93e_001ed9aa\n"
        "movss 0x2ed858, %xmm1\n" /* 0.9900000095367432f */
        ".Lf1ed93e_001ed96b:\n"
        "testl %ebx, %ebx\n" /* line 820 | nsf */
        "jle .Lf1ed93e_001ed994\n"
        "leal (, %edi, 4), %eax\n"
        "movl %esi, %edx\n" /* exc */
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "xorl %edx, %edx\n"
        ".Lf1ed93e_001ed97e:\n"
        "movaps %xmm1, %xmm0\n" /* line 822 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%esi, %edx, 4)\n" /* exc */
        "addl $1, %edx\n" /* line 820 */
        "addl $4, %eax\n"
        "cmpl %edx, %ebx\n" /* nsf */
        "jne .Lf1ed93e_001ed97e\n"
        ".Lf1ed93e_001ed994:\n"
        "movl 0x20(%ebp), %eax\n" /* line 824 | pitch_val */
        "movl %edi, (%eax)\n" /* start */
        "xorl %eax, %eax\n" /* line 825 */
        "movl %eax, 8(%ecx)\n"
        "movl %eax, (%ecx)\n"
        "movss %xmm2, 4(%ecx)\n" /* line 826 */
        /* } scope */
        "popl %ebx\n" /* line 827 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ed93e_001ed9aa:\n"
        "movaps %xmm2, %xmm1\n" /* line 818 */
        "jmp .Lf1ed93e_001ed96b\n"
    );
}

/* line 153 */
__attribute__((naked))
void open_loop_nbest_pitch(spx_sig_t *sw, int start, int end, int len, int *pitch, spx_word16_t *gain, int N, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 153 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 0x14(%ebp), %edi\n" /* len */
        "movl 0x24(%ebp), %ecx\n" /* stack */
        /* { scope 1: nb_pitch */
        "movl $4, %ebx\n" /* line 164 | k */
        "movl %ebx, %eax\n" /* k */
        "subl %ecx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %ecx\n"
        "movl 0x20(%ebp), %eax\n" /* N */
        "leal (%ecx, %eax, 4), %edx\n"
        "movl %ecx, -0x30(%ebp)\n" /* best_score */
        "movl 0x10(%ebp), %ecx\n" /* line 165 | end */
        "subl 0xc(%ebp), %ecx\n" /* start */
        "movl %ecx, -0x38(%ebp)\n"
        "shll $2, %ecx\n"
        "movl %ebx, %eax\n" /* k */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal 4(%edx, %ecx), %edx\n"
        "movl %ecx, %esi\n"
        "negl %esi\n"
        "leal -4(%edx, %esi), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* corr */
        "movl %ebx, %eax\n" /* line 166 | k */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal 8(%ecx, %edx), %eax\n"
        "leal -8(%esi, %eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* energy */
        "subl %eax, %ebx\n" /* line 167 | k */
        "andl $3, %ebx\n" /* k */
        "addl %ebx, %eax\n" /* k */
        "leal 4(%ecx, %eax), %ecx\n"
        "leal -4(%esi, %ecx), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* score */
        "movl 0x20(%ebp), %eax\n" /* line 177 | N */
        "testl %eax, %eax\n"
        "jle .Lf1ed9b0_001eda44\n"
        "xorl %eax, %eax\n"
        ".Lf1ed9b0_001eda29:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 179 | best_score */
        "movl $0xbf800000, (%ecx, %eax, 4)\n"
        "movl 0xc(%ebp), %ebx\n" /* line 180 | start, k */
        "movl 0x18(%ebp), %esi\n" /* pitch */
        "movl %ebx, (%esi, %eax, 4)\n" /* k */
        "addl $1, %eax\n" /* line 177 */
        "cmpl %eax, 0x20(%ebp)\n" /* N */
        "jne .Lf1ed9b0_001eda29\n"
        ".Lf1ed9b0_001eda44:\n"
        "movl 0xc(%ebp), %eax\n" /* line 184 | start, y */
        "shll $2, %eax\n" /* y */
        "movl 8(%ebp), %edx\n" /* sw, x */
        "subl %eax, %edx\n" /* y, x */
        "movl %edx, %eax\n" /* x, y */
        /* { scope 2: i */
        /* { scope 3 */
        "movl %edi, %ebx\n" /* line 59 */
        "sarl $2, %ebx\n"
        "leal -1(%ebx), %ecx\n" /* line 60 */
        "movl %ecx, -0x10(%ebp)\n"
        "addl $1, %ecx\n"
        "je .Lf1ed9b0_001ede08\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm2\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ed9b0_001eda6e:\n"
        "movss (%edx), %xmm1\n" /* line 63 */
        "mulss (%eax), %xmm1\n"
        "addss %xmm3, %xmm1\n"
        "movss 4(%edx), %xmm0\n" /* line 64 */
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n" /* line 65 */
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n" /* line 66 */
        "mulss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x10, %edx\n"
        "addl $0x10, %eax\n"
        "addss %xmm1, %xmm2\n" /* line 68 */
        "addl $1, %ecx\n"
        "cmpl %ebx, %ecx\n" /* line 60 */
        "jne .Lf1ed9b0_001eda6e\n"
        /* } scope */
        /* } scope */
        ".Lf1ed9b0_001edab5:\n"
        "movl -0x28(%ebp), %ebx\n" /* line 184 | energy, k */
        "movss %xmm2, (%ebx)\n" /* k */
        "movl 8(%ebp), %edx\n" /* sw, x */
        "movl %edx, %eax\n" /* x, y */
        /* { scope 2: i */
        "cmpl $-1, -0x10(%ebp)\n" /* line 60 */
        "je .Lf1ed9b0_001ede00\n"
        "movaps %xmm3, %xmm6\n"
        "xorl %ecx, %ecx\n"
        "movl -0x10(%ebp), %esi\n"
        "leal 1(%esi), %ebx\n"
        ".Lf1ed9b0_001edad6:\n"
        "movss (%edx), %xmm1\n" /* line 63 */
        "mulss (%eax), %xmm1\n"
        "addss %xmm3, %xmm1\n"
        "movss 4(%edx), %xmm0\n" /* line 64 */
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n" /* line 65 */
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n" /* line 66 */
        "mulss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x10, %edx\n"
        "addl $0x10, %eax\n"
        "addss %xmm1, %xmm6\n" /* line 68 */
        "addl $1, %ecx\n"
        "cmpl %ebx, %ecx\n" /* line 60 */
        "jne .Lf1ed9b0_001edad6\n"
        /* } scope */
        ".Lf1ed9b0_001edb1d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 186 | start */
        "cmpl %eax, 0x10(%ebp)\n" /* end */
        "jl .Lf1ed9b0_001edb6c\n"
        "movl -0x28(%ebp), %edx\n" /* energy */
        "shll $2, %eax\n" /* line 153 */
        "movl 8(%ebp), %ebx\n" /* sw, len */
        "subl %eax, %ebx\n" /* len */
        "subl 0xc(%ebp), %edi\n" /* start, len */
        "movl 8(%ebp), %esi\n" /* sw */
        "leal (%esi, %edi, 4), %ecx\n" /* stack */
        "movl 0xc(%ebp), %eax\n" /* start */
        ".Lf1ed9b0_001edb3c:\n"
        "movss -4(%ebx), %xmm0\n" /* line 189 | k */
        "movss -4(%ecx), %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss (%edx), %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "addl $1, %eax\n" /* line 186 */
        "addl $4, %edx\n"
        "subl $4, %ebx\n" /* k */
        "subl $4, %ecx\n"
        "cmpl %eax, 0x10(%ebp)\n" /* end */
        "jge .Lf1ed9b0_001edb3c\n"
        ".Lf1ed9b0_001edb6c:\n"
        "movl -0x38(%ebp), %edi\n" /* line 192 | len */
        "addl $1, %edi\n" /* len */
        "movl %edi, -0x20(%ebp)\n" /* len, nb_pitch */
        "movl 0x10(%ebp), %eax\n" /* end, _y */
        "shll $2, %eax\n" /* _y */
        "movl 8(%ebp), %edx\n" /* sw */
        "subl %eax, %edx\n" /* _y */
        /* { scope 2: i */
        /* { scope 3 */
        "testl %edi, %edi\n" /* line 142 */
        "jle .Lf1ed9b0_001edc0f\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 153 | corr, len */
        "leal (%ebx, %edi, 4), %edi\n" /* len */
        "movl %edx, %ecx\n" /* stack */
        "movl $0, -0x1c(%ebp)\n" /* i */
        "movl -0x10(%ebp), %eax\n"
        "leal 1(%eax), %esi\n"
        ".Lf1ed9b0_001edb9d:\n"
        "movl %ecx, %edx\n" /* stack */
        /* { scope 4 */
        /* { scope 5 */
        "cmpl $-1, -0x10(%ebp)\n" /* line 60 */
        "je .Lf1ed9b0_001edd16\n"
        "movl 8(%ebp), %eax\n" /* sw */
        "movaps %xmm3, %xmm2\n"
        "xorl %ebx, %ebx\n"
        ".Lf1ed9b0_001edbb1:\n"
        "movss (%eax), %xmm1\n" /* line 63 */
        "mulss (%edx), %xmm1\n"
        "addss %xmm3, %xmm1\n"
        "movss 4(%eax), %xmm0\n" /* line 64 */
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n" /* line 65 */
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n" /* line 66 */
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x10, %eax\n"
        "addl $0x10, %edx\n"
        "addss %xmm1, %xmm2\n" /* line 68 */
        "addl $1, %ebx\n"
        "cmpl %esi, %ebx\n" /* line 60 */
        "jne .Lf1ed9b0_001edbb1\n"
        /* } scope */
        /* } scope */
        "movss %xmm2, -4(%edi)\n" /* line 145 */
        "addl $1, -0x1c(%ebp)\n" /* line 142 | i */
        "subl $4, %edi\n"
        "addl $4, %ecx\n"
        "movl -0x1c(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x20(%ebp)\n" /* nb_pitch */
        "jne .Lf1ed9b0_001edb9d\n"
        /* } scope */
        /* } scope */
        ".Lf1ed9b0_001edc0f:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 225 | start */
        "cmpl %ecx, 0x10(%ebp)\n" /* end */
        "jl .Lf1ed9b0_001edd39\n"
        "movl %ecx, %edx\n"
        "xorl %ecx, %ecx\n"
        "movss 0x2ed5d0, %xmm5\n" /* 1.0f */
        "movss 0x2eda74, %xmm4\n" /* -16.0f */
        "movss 0x2ed6a8, %xmm2\n" /* 16.0f */
        "jmp .Lf1ed9b0_001edc53\n"
        /* { scope 2: i */
        ".Lf1ed9b0_001edc39:\n"
        "movaps %xmm2, %xmm0\n" /* line 228 */
        "mulss %xmm1, %xmm0\n" /* line 232 */
        "movl -0x24(%ebp), %ebx\n" /* score, k */
        "movss %xmm0, (%ebx, %eax)\n" /* k */
        /* } scope */
        "addl $1, %edx\n" /* line 225 */
        "addl $1, %ecx\n"
        "cmpl %edx, 0x10(%ebp)\n" /* end */
        "jl .Lf1ed9b0_001edc9e\n"
        ".Lf1ed9b0_001edc53:\n"
        "leal (, %ecx, 4), %eax\n" /* line 153 */
        /* { scope 2: i */
        "movl -0x2c(%ebp), %ebx\n" /* line 227 | corr, k */
        "movss (%ebx, %eax), %xmm1\n" /* k */
        "movl -0x28(%ebp), %esi\n" /* energy */
        "movss (%esi, %eax), %xmm0\n" /* g */
        "addss %xmm5, %xmm0\n" /* g */
        "movaps %xmm1, %xmm7\n"
        "divss %xmm0, %xmm7\n" /* g */
        "movaps %xmm7, %xmm0\n" /* g */
        "ucomiss %xmm2, %xmm7\n" /* line 228 */
        "ja .Lf1ed9b0_001edc39\n"
        "movaps %xmm4, %xmm7\n" /* line 230 */
        "maxss %xmm0, %xmm7\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm1, %xmm0\n" /* line 232 */
        "movl -0x24(%ebp), %ebx\n" /* score, k */
        "movss %xmm0, (%ebx, %eax)\n" /* k */
        /* } scope */
        "addl $1, %edx\n" /* line 225 */
        "addl $1, %ecx\n"
        "cmpl %edx, 0x10(%ebp)\n" /* end */
        "jge .Lf1ed9b0_001edc53\n"
        ".Lf1ed9b0_001edc9e:\n"
        "movl 0x20(%ebp), %esi\n" /* N */
        "movl -0x30(%ebp), %edi\n" /* best_score, len */
        "leal -4(%edi, %esi, 4), %esi\n" /* len */
        "movl %esi, -0x18(%ebp)\n"
        "movl %ebx, -0x14(%ebp)\n" /* k */
        "movl 0xc(%ebp), %edi\n" /* start, len */
        "movl %edi, -0x40(%ebp)\n" /* len */
        "movl %ebx, %eax\n" /* k */
        "movl %esi, %edx\n"
        ".Lf1ed9b0_001edcb8:\n"
        "movss (%eax), %xmm0\n" /* line 239 */
        "ucomiss (%edx), %xmm0\n"
        "jbe .Lf1ed9b0_001edcfe\n"
        "movl 0x20(%ebp), %esi\n" /* line 241 | N */
        "testl %esi, %esi\n"
        "jle .Lf1ed9b0_001edcfe\n"
        "movl -0x30(%ebp), %ecx\n" /* line 243 | best_score */
        "ucomiss (%ecx), %xmm0\n"
        "jbe .Lf1ed9b0_001edd4f\n"
        "xorl %esi, %esi\n"
        "movl $0, -0x34(%ebp)\n"
        "movl 0x20(%ebp), %ebx\n" /* line 245 | N, k */
        "subl $1, %ebx\n" /* k */
        "cmpl %esi, %ebx\n" /* k */
        "jg .Lf1ed9b0_001edd73\n"
        ".Lf1ed9b0_001edce7:\n"
        "movl -0x34(%ebp), %eax\n" /* line 250 */
        "shll $2, %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* best_score */
        "movss %xmm0, (%ecx, %eax)\n"
        "movl -0x40(%ebp), %esi\n" /* line 251 */
        "movl 0x18(%ebp), %ebx\n" /* pitch, k */
        "movl %esi, (%ebx, %eax)\n" /* k */
        ".Lf1ed9b0_001edcfe:\n"
        "addl $1, -0x40(%ebp)\n" /* line 237 */
        "addl $4, -0x14(%ebp)\n"
        "movl -0x40(%ebp), %edi\n" /* len */
        "cmpl %edi, 0x10(%ebp)\n" /* len, end */
        "jl .Lf1ed9b0_001edd39\n"
        "movl -0x14(%ebp), %eax\n"
        "movl -0x18(%ebp), %edx\n"
        "jmp .Lf1ed9b0_001edcb8\n"
        /* { scope 2: i */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ed9b0_001edd16:\n"
        "movaps %xmm3, %xmm2\n" /* line 60 */
        /* } scope */
        /* } scope */
        "movss %xmm2, -4(%edi)\n" /* line 145 */
        "addl $1, -0x1c(%ebp)\n" /* line 142 | i */
        "subl $4, %edi\n"
        "addl $4, %ecx\n"
        "movl -0x1c(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x20(%ebp)\n" /* nb_pitch */
        "jne .Lf1ed9b0_001edb9d\n"
        "jmp .Lf1ed9b0_001edc0f\n"
        /* } scope */
        /* } scope */
        ".Lf1ed9b0_001edd39:\n"
        "movl 0x1c(%ebp), %ebx\n" /* line 259 | gain, k */
        "testl %ebx, %ebx\n" /* k */
        "je .Lf1ed9b0_001edd47\n"
        "movl 0x20(%ebp), %ecx\n" /* line 261 | N */
        "testl %ecx, %ecx\n"
        "jg .Lf1ed9b0_001eddab\n"
        /* } scope */
        ".Lf1ed9b0_001edd47:\n"
        "addl $0x34, %esp\n" /* line 272 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: nb_pitch */
        ".Lf1ed9b0_001edd4f:\n"
        "xorl %esi, %esi\n" /* line 252 */
        ".Lf1ed9b0_001edd51:\n"
        "addl $1, %esi\n" /* line 241 */
        "cmpl %esi, 0x20(%ebp)\n" /* N */
        "je .Lf1ed9b0_001edcfe\n"
        "movl %esi, -0x34(%ebp)\n" /* line 239 */
        "movl -0x30(%ebp), %ebx\n" /* line 243 | best_score, k */
        "ucomiss (%ebx, %esi, 4), %xmm0\n" /* k */
        "jbe .Lf1ed9b0_001edd51\n"
        "movl 0x20(%ebp), %ebx\n" /* line 245 | N, k */
        "subl $1, %ebx\n" /* k */
        "cmpl %esi, %ebx\n" /* k */
        "jle .Lf1ed9b0_001edce7\n"
        ".Lf1ed9b0_001edd73:\n"
        "leal (, %ebx, 4), %edi\n" /* line 153 | len */
        "movl -0x30(%ebp), %eax\n" /* best_score */
        "leal -4(%eax, %edi), %ecx\n" /* stack */
        "movl 0x18(%ebp), %eax\n" /* pitch */
        "leal -4(%eax, %edi), %edx\n"
        ".Lf1ed9b0_001edd88:\n"
        "movl (%ecx), %eax\n" /* line 247 */
        "movl %eax, 4(%ecx)\n"
        "movl (%edx), %eax\n" /* line 248 */
        "movl %eax, 4(%edx)\n"
        "subl $1, %ebx\n" /* line 245 | k */
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, %esi\n" /* k */
        "jl .Lf1ed9b0_001edd88\n"
        "movl -0x14(%ebp), %edx\n"
        "movss (%edx), %xmm0\n"
        "jmp .Lf1ed9b0_001edce7\n"
        ".Lf1ed9b0_001eddab:\n"
        "xorl %edx, %edx\n" /* line 259 */
        "sqrtss %xmm6, %xmm2\n"
        "movss 0x2ed6b4, %xmm4\n" /* 10.0f */
        /* { scope 2: i */
        ".Lf1ed9b0_001eddb9:\n"
        "movl 0x18(%ebp), %ecx\n" /* line 265 | pitch */
        "movl (%ecx, %edx, 4), %eax\n"
        "subl 0xc(%ebp), %eax\n" /* start */
        "shll $2, %eax\n"
        "movl -0x28(%ebp), %ebx\n" /* energy, k */
        "sqrtss (%ebx, %eax), %xmm1\n" /* k */
        "mulss %xmm2, %xmm1\n"
        "addss %xmm4, %xmm1\n"
        "movl -0x2c(%ebp), %esi\n" /* corr */
        "movss (%esi, %eax), %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n" /* line 267 */
        "maxss %xmm0, %xmm1\n"
        "movl 0x1c(%ebp), %eax\n" /* line 269 | gain */
        "movss %xmm1, (%eax, %edx, 4)\n"
        /* } scope */
        "addl $1, %edx\n" /* line 261 */
        "cmpl %edx, 0x20(%ebp)\n" /* N */
        "jne .Lf1ed9b0_001eddb9\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 272 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: nb_pitch */
        /* { scope 2: i */
        ".Lf1ed9b0_001ede00:\n"
        "movaps %xmm3, %xmm6\n" /* line 60 */
        "jmp .Lf1ed9b0_001edb1d\n"
        /* } scope */
        /* { scope 2: i */
        /* { scope 3 */
        ".Lf1ed9b0_001ede08:\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm2\n"
        "jmp .Lf1ed9b0_001edab5\n"
    );
}

/* line 572 */
__attribute__((naked))
int pitch_search_3tap(spx_sig_t *target, spx_sig_t *sw, spx_coef_t *ak, spx_coef_t *awk1, spx_coef_t *awk2, spx_sig_t *exc, const void *par, int start, int end, spx_word16_t pitch_coef, int p, int nsf, SpeexBits *bits, char *stack, spx_sig_t *exc2, spx_word16_t *r, int complexity, int cdbk_offset, int plc_tuning)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 572 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        "movl 0x3c(%ebp), %ebx\n" /* stack */
        "movl 0x48(%ebp), %eax\n" /* complexity */
        /* { scope 1 */
        "cmpl $0xa, %eax\n" /* line 586 */
        "jle .Lf1ede14_001ee13a\n"
        "movl $0xa, %ecx\n"
        "movl $0xa, %edx\n"
        ".Lf1ede14_001ede39:\n"
        "movl $4, %edi\n" /* line 591 */
        "movl %edi, %eax\n"
        "subl %ebx, %eax\n" /* stack */
        "andl $3, %eax\n"
        "leal (%ebx, %eax), %eax\n" /* stack */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %eax, -0xf8(%ebp)\n" /* nbest */
        "movl 0x24(%ebp), %eax\n" /* line 594 | start */
        "cmpl %eax, 0x28(%ebp)\n" /* end */
        "jl .Lf1ede14_001ee16a\n"
        ".Lf1ede14_001ede5d:\n"
        "movl %edi, %eax\n" /* line 603 */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl 0x34(%ebp), %ebx\n" /* nsf, stack */
        "shll $2, %ebx\n" /* stack */
        "addl %ebx, %eax\n" /* stack */
        "movl %eax, %edx\n"
        "subl %ebx, %edx\n" /* stack */
        "movl %edx, -0x10c(%ebp)\n" /* best_exc */
        "movl %edi, %edx\n" /* line 604 */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ebx, %eax), %eax\n" /* stack */
        "movl %eax, %edx\n"
        "subl %ebx, %edx\n" /* stack */
        "movl %edx, -0x108(%ebp)\n" /* new_target */
        "movl %edi, %edx\n" /* line 605 */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ebx, %eax), %esi\n" /* stack */
        "movl %esi, %eax\n"
        "subl %ebx, %eax\n" /* stack */
        "movl %eax, -0x104(%ebp)\n" /* best_target */
        "movl 0x28(%ebp), %eax\n" /* line 607 | end */
        "subl 0x24(%ebp), %eax\n" /* start */
        "addl $1, %eax\n"
        "cmpl %eax, %ecx\n"
        "cmovgl %eax, %ecx\n"
        "movl %ecx, -0x6c(%ebp)\n"
        "movl %esi, 0x1c(%esp)\n" /* line 609 */
        "movl %ecx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0xf8(%ebp), %edx\n" /* nbest */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x34(%ebp), %ecx\n" /* nsf */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl 0x24(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* sw */
        "movl %ecx, (%esp)\n"
        "calll open_loop_nbest_pitch\n"
        "movl -0x6c(%ebp), %eax\n" /* line 610 */
        "testl %eax, %eax\n"
        "jle .Lf1ede14_001ee1cd\n"
        /* { scope 2: j, tmp1, tmp2, x, ... */
        /* { scope 3: ptr, best_sum */
        "movl %edi, %eax\n" /* line 312 */
        "subl %esi, %eax\n"
        "andl $3, %eax\n"
        "leal (%esi, %eax), %eax\n"
        "movl 0x34(%ebp), %ecx\n" /* nsf */
        "leal (%ecx, %ecx, 2), %edx\n"
        "shll $2, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %ecx\n"
        "subl %edx, %ecx\n"
        "movl %ecx, -0xd4(%ebp)\n" /* tmp1 */
        "subl %eax, %edi\n" /* line 313 */
        "andl $3, %edi\n"
        "addl %edi, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "subl %edx, %eax\n"
        "movl %eax, -0xd0(%ebp)\n" /* tmp2 */
        "addl %ebx, %ecx\n" /* line 316 */
        "movl %ecx, -0xf4(%ebp)\n"
        "movl 0x34(%ebp), %eax\n" /* line 317 | nsf */
        "shll $3, %eax\n"
        "movl -0xd4(%ebp), %edi\n" /* tmp1 */
        "addl %eax, %edi\n"
        "movl %edi, -0xf0(%ebp)\n"
        "addl -0xd0(%ebp), %ebx\n" /* line 320 | tmp2 */
        "movl %ebx, -0xec(%ebp)\n"
        "addl -0xd0(%ebp), %eax\n" /* line 321 | tmp2 */
        "movl %eax, -0xe8(%ebp)\n"
        "movl 0x34(%ebp), %eax\n" /* line 338 | nsf */
        "subl $1, %eax\n"
        "movl %eax, -0xe4(%ebp)\n"
        "movl 0x34(%ebp), %eax\n" /* nsf */
        "sarl $2, %eax\n"
        "leal -1(%eax), %edx\n"
        "movl %edx, -0xb0(%ebp)\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        "movss %xmm0, -0xfc(%ebp)\n" /* best_err */
        "movl $0, -0x70(%ebp)\n"
        "movl $0, -0x110(%ebp)\n" /* best_gain_index */
        "movl $0, -0x100(%ebp)\n" /* best_pitch */
        "movl %eax, -0x11c(%ebp)\n"
        "movl -0x70(%ebp), %eax\n"
        /* } scope */
        /* } scope */
        ".Lf1ede14_001edfb2:\n"
        "movl -0xf8(%ebp), %edx\n" /* line 612 | nbest */
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x114(%ebp)\n" /* pitch */
        "movl 0x34(%ebp), %edi\n" /* line 613 | nsf */
        "testl %edi, %edi\n"
        "jle .Lf1ede14_001edfdc\n"
        "xorl %eax, %eax\n"
        ".Lf1ede14_001edfca:\n"
        "movl 0x1c(%ebp), %edx\n" /* line 614 | exc */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 613 */
        "cmpl %eax, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001edfca\n"
        /* { scope 2: j, tmp1, tmp2, x, ... */
        /* { scope 3: ptr, best_sum */
        ".Lf1ede14_001edfdc:\n"
        "movl 0x20(%ebp), %ebx\n" /* line 310 | par */
        "movl 4(%ebx), %ecx\n"
        "movl $1, -0xcc(%ebp)\n" /* gain_cdbk_size */
        "shll %cl, -0xcc(%ebp)\n" /* gain_cdbk_size */
        "movl 0x4c(%ebp), %eax\n" /* line 311 | cdbk_offset */
        "imull -0xcc(%ebp), %eax\n" /* gain_cdbk_size */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, -0xc8(%ebp)\n" /* ptr */
        "movl (%ebx), %edi\n"
        "addl %edi, %eax\n"
        "movl %eax, -0xc8(%ebp)\n" /* ptr */
        "movl -0xd4(%ebp), %eax\n" /* line 315 | tmp1 */
        "movl %eax, -0x24(%ebp)\n" /* x */
        "movl -0xf4(%ebp), %edx\n" /* line 316 */
        "movl %edx, -0x20(%ebp)\n"
        "movl -0xf0(%ebp), %ecx\n" /* line 317 */
        "movl %ecx, -0x1c(%ebp)\n"
        "movl -0xd0(%ebp), %ebx\n" /* line 319 | tmp2 */
        "movl %ebx, -0x30(%ebp)\n" /* e */
        "movl -0xec(%ebp), %edi\n" /* line 320 */
        "movl %edi, -0x2c(%ebp)\n"
        "movl -0xe8(%ebp), %eax\n" /* line 321 */
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x114(%ebp), %edx\n" /* line 572 | pitch */
        "negl %edx\n"
        "movl -0x114(%ebp), %ecx\n" /* pitch */
        "subl %ecx, %edx\n"
        "movl %edx, -0x9c(%ebp)\n"
        "movl 0x40(%ebp), %ebx\n" /* exc2, stack */
        "leal 4(%ebx, %edx, 4), %ebx\n" /* stack */
        "movl %ebx, -0xa0(%ebp)\n" /* stack */
        "leal -4(, %ecx, 4), %eax\n" /* complexity */
        "movl 0x40(%ebp), %edi\n" /* exc2 */
        "subl %eax, %edi\n" /* complexity */
        "movl %edi, -0x98(%ebp)\n"
        "movl $1, -0xa4(%ebp)\n"
        "movl $0xc, -0x118(%ebp)\n"
        ".Lf1ede14_001ee08e:\n"
        "movl 0x34(%ebp), %esi\n" /* line 325 | nsf */
        "testl %esi, %esi\n"
        "jle .Lf1ede14_001ee28f\n"
        "movl -0xa4(%ebp), %ebx\n"
        "subl -0x114(%ebp), %ebx\n" /* pitch */
        "movl -0x98(%ebp), %edi\n"
        "movl -0xa0(%ebp), %esi\n"
        "movl -0xa4(%ebp), %ecx\n"
        "addl -0x9c(%ebp), %ecx\n"
        "movl $0, -0xd8(%ebp)\n" /* j */
        "movl $0, -0xa8(%ebp)\n"
        "jmp .Lf1ede14_001ee11b\n"
        ".Lf1ede14_001ee0d3:\n"
        "testl %ecx, %ecx\n" /* line 329 */
        "js .Lf1ede14_001ee67f\n"
        "movl -0x118(%ebp), %edx\n" /* line 332 */
        "movl -0x34(%ebp, %edx), %eax\n"
        "movl -0xa8(%ebp), %edx\n"
        "movl $0, (%eax, %edx)\n"
        ".Lf1ede14_001ee0f2:\n"
        "addl $1, -0xd8(%ebp)\n" /* line 325 | j */
        "addl $1, %ebx\n"
        "addl $4, -0xa8(%ebp)\n"
        "addl $4, %edi\n"
        "addl $4, %esi\n"
        "addl $1, %ecx\n"
        "movl -0xd8(%ebp), %eax\n" /* j */
        "cmpl %eax, 0x34(%ebp)\n" /* nsf */
        "je .Lf1ede14_001ee28f\n"
        ".Lf1ede14_001ee11b:\n"
        "testl %ebx, %ebx\n" /* line 327 */
        "jns .Lf1ede14_001ee0d3\n"
        "movl -0x118(%ebp), %eax\n" /* line 328 */
        "movl -0x34(%ebp, %eax), %edx\n"
        "movss (%edi), %xmm0\n"
        "movl -0xa8(%ebp), %eax\n"
        "movss %xmm0, (%edx, %eax)\n"
        "jmp .Lf1ede14_001ee0f2\n"
        /* } scope */
        /* } scope */
        ".Lf1ede14_001ee13a:\n"
        "testl %eax, %eax\n" /* line 588 */
        "jle .Lf1ede14_001ee9a6\n"
        "movl %eax, %ecx\n"
        "movl %eax, %edx\n"
        "movl $4, %edi\n" /* line 591 */
        "movl %edi, %eax\n"
        "subl %ebx, %eax\n" /* stack */
        "andl $3, %eax\n"
        "leal (%ebx, %eax), %eax\n" /* stack */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %eax, -0xf8(%ebp)\n" /* nbest */
        "movl 0x24(%ebp), %eax\n" /* line 594 | start */
        "cmpl %eax, 0x28(%ebp)\n" /* end */
        "jge .Lf1ede14_001ede5d\n"
        ".Lf1ede14_001ee16a:\n"
        "movl 0x20(%ebp), %edx\n" /* line 596 | par */
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x38(%ebp), %ecx\n" /* bits */
        "movl %ecx, (%esp)\n"
        "calll speex_bits_pack\n"
        "movl 0x20(%ebp), %ebx\n" /* line 597 | par, stack */
        "movl 4(%ebx), %eax\n" /* stack */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x38(%ebp), %edi\n" /* bits */
        "movl %edi, (%esp)\n"
        "calll speex_bits_pack\n"
        "movl 0x34(%ebp), %eax\n" /* line 598 | nsf */
        "testl %eax, %eax\n"
        "jle .Lf1ede14_001ee1bf\n"
        "xorl %eax, %eax\n"
        ".Lf1ede14_001ee1ad:\n"
        "movl 0x1c(%ebp), %edx\n" /* line 599 | exc */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 598 */
        "cmpl %eax, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001ee1ad\n"
        ".Lf1ede14_001ee1bf:\n"
        "movl 0x24(%ebp), %eax\n" /* start */
        /* } scope */
        "addl $0x13c, %esp\n" /* line 639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ede14_001ee1cd:\n"
        "movl $0, -0x114(%ebp)\n" /* line 610 | pitch */
        "movl $0, -0x110(%ebp)\n" /* best_gain_index */
        "movl $0, -0x100(%ebp)\n" /* best_pitch */
        ".Lf1ede14_001ee1eb:\n"
        "movl 0x20(%ebp), %ecx\n" /* line 630 | par */
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x24(%ebp), %ebx\n" /* start, stack */
        "subl %ebx, -0x100(%ebp)\n" /* stack, best_pitch */
        "movl -0x100(%ebp), %edi\n" /* best_pitch */
        "movl %edi, 4(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        "movl 0x20(%ebp), %edx\n" /* line 631 | par */
        "movl 4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x110(%ebp), %ecx\n" /* best_gain_index */
        "movl %ecx, 4(%esp)\n"
        "movl 0x38(%ebp), %ebx\n" /* bits, stack */
        "movl %ebx, (%esp)\n" /* stack */
        "calll speex_bits_pack\n"
        "movl 0x34(%ebp), %eax\n" /* line 633 | nsf */
        "testl %eax, %eax\n"
        "jle .Lf1ede14_001ee279\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ede14_001ee23b:\n"
        "leal (, %ecx, 4), %edx\n" /* line 572 */
        "movl -0x10c(%ebp), %edi\n" /* line 634 | best_exc */
        "movl (%edi, %edx), %eax\n"
        "movl 0x1c(%ebp), %ebx\n" /* exc, stack */
        "movl %eax, (%ebx, %edx)\n" /* stack */
        "addl $1, %ecx\n" /* line 633 */
        "cmpl %ecx, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001ee23b\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ede14_001ee25b:\n"
        "leal (, %ecx, 4), %edx\n" /* line 572 */
        "movl -0x104(%ebp), %edi\n" /* line 636 | best_target */
        "movl (%edi, %edx), %eax\n"
        "movl 8(%ebp), %ebx\n" /* target, stack */
        "movl %eax, (%ebx, %edx)\n" /* stack */
        "addl $1, %ecx\n" /* line 635 */
        "cmpl %ecx, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001ee25b\n"
        ".Lf1ede14_001ee279:\n"
        "movl -0x114(%ebp), %edi\n" /* pitch */
        "movl %edi, 0x24(%ebp)\n" /* start */
        "movl %edi, %eax\n"
        /* } scope */
        "addl $0x13c, %esp\n" /* line 639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: j, tmp1, tmp2, x, ... */
        /* { scope 3: ptr, best_sum */
        ".Lf1ede14_001ee28f:\n"
        "cmpl $1, -0xa4(%ebp)\n" /* line 335 */
        "je .Lf1ede14_001ee952\n"
        "movl -0xe4(%ebp), %ebx\n" /* line 338 */
        "testl %ebx, %ebx\n"
        "jle .Lf1ede14_001ee2cf\n"
        "movl -0x118(%ebp), %edi\n" /* line 339 */
        "movl -0x28(%edi, %ebp), %esi\n"
        "movl -0x24(%edi, %ebp), %ebx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ede14_001ee2b6:\n"
        "leal (, %ecx, 4), %edx\n" /* line 572 */
        "movl (%ebx, %edx), %eax\n" /* line 339 */
        "movl %eax, 4(%esi, %edx)\n"
        "addl $1, %ecx\n" /* line 338 */
        "cmpl %ecx, -0xe4(%ebp)\n"
        "jne .Lf1ede14_001ee2b6\n"
        ".Lf1ede14_001ee2cf:\n"
        "movl -0x118(%ebp), %edx\n" /* line 340 */
        "movl -0x28(%edx, %ebp), %eax\n"
        "movl $0, (%eax)\n"
        "movl 0x34(%ebp), %ecx\n" /* line 341 | nsf */
        "testl %ecx, %ecx\n"
        "jle .Lf1ede14_001ee30b\n"
        "movl -0x34(%ebp, %edx), %ecx\n" /* line 343 */
        "xorl %edx, %edx\n"
        ".Lf1ede14_001ee2ec:\n"
        "movl 0x44(%ebp), %ebx\n" /* r */
        "movss (%ebx, %edx, 4), %xmm0\n"
        "mulss (%ecx), %xmm0\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 341 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001ee2ec\n"
        ".Lf1ede14_001ee30b:\n"
        "subl $1, -0xa4(%ebp)\n"
        "subl $4, -0x118(%ebp)\n"
        "subl $4, -0xa0(%ebp)\n"
        "subl $4, -0x98(%ebp)\n"
        "cmpl $-2, -0xa4(%ebp)\n" /* line 322 */
        "jne .Lf1ede14_001ee08e\n"
        "movl $1, %ebx\n"
        "pxor %xmm7, %xmm7\n"
        ".Lf1ede14_001ee33d:\n"
        "movl -0x28(%ebp, %ebx, 4), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "cmpl $-1, -0xb0(%ebp)\n" /* line 60 */
        "je .Lf1ede14_001ee69d\n"
        "movl 8(%ebp), %eax\n" /* target */
        "movaps %xmm7, %xmm2\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ede14_001ee356:\n"
        "movss (%edx), %xmm1\n" /* line 63 */
        "mulss (%eax), %xmm1\n"
        "addss %xmm7, %xmm1\n"
        "movss 4(%edx), %xmm0\n" /* line 64 */
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n" /* line 65 */
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n" /* line 66 */
        "mulss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x10, %edx\n"
        "addl $0x10, %eax\n"
        "addss %xmm1, %xmm2\n" /* line 68 */
        "addl $1, %ecx\n"
        "cmpl -0x11c(%ebp), %ecx\n" /* line 60 */
        "jne .Lf1ede14_001ee356\n"
        /* } scope */
        /* } scope */
        ".Lf1ede14_001ee3a1:\n"
        "movss %xmm2, -0x40(%ebp, %ebx, 4)\n" /* line 418 */
        "addl $1, %ebx\n"
        "cmpl $4, %ebx\n" /* line 417 */
        "jne .Lf1ede14_001ee33d\n"
        "movl $0, -0x90(%ebp)\n"
        ".Lf1ede14_001ee3b9:\n"
        "movl -0x90(%ebp), %eax\n" /* line 421 */
        "shll $2, %eax\n"
        "movl -0x24(%ebp, %eax), %edi\n"
        "movl %edi, -0x94(%ebp)\n"
        "leal -0x60(%ebp), %edi\n" /* A */
        "addl %eax, %edi\n"
        "movl -0x90(%ebp), %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal -0x60(%ebp, %eax, 4), %esi\n"
        "movl $1, -0xac(%ebp)\n"
        "movl -0xb0(%ebp), %ecx\n"
        "leal 1(%ecx), %ebx\n"
        "movl -0xac(%ebp), %eax\n"
        "movl -0x28(%ebp, %eax, 4), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "cmpl $-1, -0xb0(%ebp)\n" /* line 60 */
        "je .Lf1ede14_001ee492\n"
        ".Lf1ede14_001ee408:\n"
        "movl -0x94(%ebp), %eax\n"
        "movaps %xmm7, %xmm2\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ede14_001ee413:\n"
        "movss (%eax), %xmm1\n" /* line 63 */
        "mulss (%edx), %xmm1\n"
        "addss %xmm7, %xmm1\n"
        "movss 4(%eax), %xmm0\n" /* line 64 */
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n" /* line 65 */
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n" /* line 66 */
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x10, %eax\n"
        "addl $0x10, %edx\n"
        "addss %xmm1, %xmm2\n" /* line 68 */
        "addl $1, %ecx\n"
        "cmpl %ebx, %ecx\n" /* line 60 */
        "jne .Lf1ede14_001ee413\n"
        /* } scope */
        /* } scope */
        "movss %xmm2, (%edi)\n" /* line 422 */
        "movss %xmm2, (%esi)\n"
        "addl $0xc, %edi\n"
        "addl $4, %esi\n"
        "movl -0xac(%ebp), %edx\n" /* line 421 */
        "cmpl %edx, -0x90(%ebp)\n"
        "jl .Lf1ede14_001ee4b1\n"
        ".Lf1ede14_001ee476:\n"
        "addl $1, %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "movl %edx, %eax\n"
        "movl -0x28(%ebp, %eax, 4), %edx\n"
        /* { scope 4 */
        /* { scope 5 */
        "cmpl $-1, -0xb0(%ebp)\n" /* line 60 */
        "jne .Lf1ede14_001ee408\n"
        ".Lf1ede14_001ee492:\n"
        "movaps %xmm7, %xmm2\n"
        /* } scope */
        /* } scope */
        "movss %xmm2, (%edi)\n" /* line 422 */
        "movss %xmm2, (%esi)\n"
        "addl $0xc, %edi\n"
        "addl $4, %esi\n"
        "movl -0xac(%ebp), %edx\n" /* line 421 */
        "cmpl %edx, -0x90(%ebp)\n"
        "jge .Lf1ede14_001ee476\n"
        ".Lf1ede14_001ee4b1:\n"
        "addl $1, -0x90(%ebp)\n" /* line 420 */
        "cmpl $3, -0x90(%ebp)\n"
        "je .Lf1ede14_001ee4df\n"
        ".Lf1ede14_001ee4c1:\n"
        "movl -0x90(%ebp), %eax\n" /* line 421 */
        "testl %eax, %eax\n"
        "jns .Lf1ede14_001ee3b9\n"
        "addl $1, -0x90(%ebp)\n" /* line 420 */
        "cmpl $3, -0x90(%ebp)\n"
        "jne .Lf1ede14_001ee4c1\n"
        /* { scope 4 */
        ".Lf1ede14_001ee4df:\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 431 */
        "movss -0x38(%ebp), %xmm3\n" /* line 432 */
        "movss -0x3c(%ebp), %xmm4\n" /* line 433 | corr */
        "movss -0x4c(%ebp), %xmm1\n" /* line 434 */
        "movss %xmm1, -0xb4(%ebp)\n"
        "movss -0x5c(%ebp), %xmm1\n" /* line 435 */
        "movss %xmm1, -0xb8(%ebp)\n"
        "movss -0x58(%ebp), %xmm1\n" /* line 436 */
        "movss %xmm1, -0xbc(%ebp)\n"
        "movss -0x40(%ebp), %xmm5\n" /* line 437 */
        "movss -0x50(%ebp), %xmm6\n" /* line 438 */
        "movss -0x60(%ebp), %xmm1\n" /* line 439 | A */
        "movss %xmm1, -0xc0(%ebp)\n"
        "cmpl $1, 0x50(%ebp)\n" /* line 442 | plc_tuning */
        "jle .Lf1ede14_001ee999\n"
        "cvtsi2sdl 0x50(%ebp), %xmm2\n" /* plc_tuning */
        ".Lf1ede14_001ee53b:\n"
        "movapd %xmm2, %xmm1\n" /* line 449 */
        "mulsd 0x307e98, %xmm1\n" /* -0.01 */
        "addsd 0x307c10, %xmm1\n" /* 1.0 */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x78(%ebp)\n"
        "cvtss2sd %xmm3, %xmm0\n" /* line 450 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "cvtss2sd %xmm4, %xmm0\n" /* line 451 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "movapd %xmm2, %xmm1\n" /* line 452 */
        "mulsd 0x307e10, %xmm1\n" /* 0.01 */
        "addsd 0x307c10, %xmm1\n" /* 1.0 */
        "mulsd 0x307ce0, %xmm1\n" /* 0.5 */
        "cvtss2sd %xmm5, %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n"
        "cvtss2sd %xmm6, %xmm0\n" /* line 453 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "cvtss2sd -0xc0(%ebp), %xmm0\n" /* line 454 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movl -0xcc(%ebp), %eax\n" /* line 456 | gain_cdbk_size */
        "testl %eax, %eax\n"
        "jg .Lf1ede14_001ee7b7\n"
        "xorl %esi, %esi\n"
        "xorl %edx, %edx\n"
        ".Lf1ede14_001ee5f0:\n"
        "movl -0xc8(%ebp), %ecx\n" /* line 510 | ptr */
        "movsbl (%ecx, %edx), %eax\n"
        "cvtsi2sdl %eax, %xmm0\n"
        "movsd 0x307e78, %xmm1\n" /* 0.015625 */
        "mulsd %xmm1, %xmm0\n"
        "addsd 0x307ce0, %xmm0\n" /* 0.5 */
        "cvtsd2ss %xmm0, %xmm4\n"
        "addl %ecx, %edx\n" /* line 511 */
        "movsbl 1(%edx), %eax\n"
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "addsd 0x307ce0, %xmm0\n" /* 0.5 */
        "cvtsd2ss %xmm0, %xmm3\n"
        "movsbl 2(%edx), %eax\n" /* line 512 */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "addsd 0x307ce0, %xmm0\n" /* 0.5 */
        "cvtsd2ss %xmm0, %xmm2\n"
        /* } scope */
        "movl 0x34(%ebp), %eax\n" /* line 535 | nsf */
        "testl %eax, %eax\n"
        "jg .Lf1ede14_001ee70e\n"
        "movaps %xmm7, %xmm5\n"
        /* } scope */
        /* } scope */
        ".Lf1ede14_001ee656:\n"
        "movss -0xfc(%ebp), %xmm0\n" /* line 617 | best_err */
        "ucomiss %xmm5, %xmm0\n"
        "ja .Lf1ede14_001ee6a5\n"
        "ucomiss %xmm0, %xmm7\n"
        "ja .Lf1ede14_001ee6a5\n"
        ".Lf1ede14_001ee668:\n"
        "addl $1, -0x70(%ebp)\n" /* line 610 */
        "movl -0x70(%ebp), %edx\n"
        "cmpl %edx, -0x6c(%ebp)\n"
        "je .Lf1ede14_001ee1eb\n"
        "movl %edx, %eax\n"
        "jmp .Lf1ede14_001edfb2\n"
        /* { scope 2: j, tmp1, tmp2, x, ... */
        /* { scope 3: ptr, best_sum */
        ".Lf1ede14_001ee67f:\n"
        "movl -0x118(%ebp), %eax\n" /* line 330 */
        "movl -0x34(%ebp, %eax), %edx\n"
        "movss (%esi), %xmm0\n"
        "movl -0xa8(%ebp), %eax\n"
        "movss %xmm0, (%edx, %eax)\n"
        "jmp .Lf1ede14_001ee0f2\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ede14_001ee69d:\n"
        "movaps %xmm7, %xmm2\n" /* line 60 */
        "jmp .Lf1ede14_001ee3a1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1ede14_001ee6a5:\n"
        "movl 0x34(%ebp), %eax\n" /* line 619 | nsf */
        "testl %eax, %eax\n"
        "jle .Lf1ede14_001ee6ef\n"
        "xorl %ecx, %ecx\n" /* line 617 */
        ".Lf1ede14_001ee6ae:\n"
        "leal (, %ecx, 4), %edx\n" /* line 572 */
        "movl 0x1c(%ebp), %ebx\n" /* line 620 | exc, stack */
        "movl (%ebx, %edx), %eax\n" /* stack */
        "movl -0x10c(%ebp), %edi\n" /* best_exc */
        "movl %eax, (%edi, %edx)\n"
        "addl $1, %ecx\n" /* line 619 */
        "cmpl %ecx, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001ee6ae\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ede14_001ee6ce:\n"
        "leal (, %ecx, 4), %edx\n" /* line 572 */
        "movl -0x108(%ebp), %ebx\n" /* line 622 | new_target, stack */
        "movl (%ebx, %edx), %eax\n" /* stack */
        "movl -0x104(%ebp), %edi\n" /* best_target */
        "movl %eax, (%edi, %edx)\n"
        "addl $1, %ecx\n" /* line 621 */
        "cmpl %ecx, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001ee6ce\n"
        ".Lf1ede14_001ee6ef:\n"
        "movl %esi, -0x110(%ebp)\n" /* best_gain_index */
        "movl -0x114(%ebp), %eax\n" /* pitch */
        "movl %eax, -0x100(%ebp)\n" /* best_pitch */
        "movss %xmm5, -0xfc(%ebp)\n" /* best_err */
        "jmp .Lf1ede14_001ee668\n"
        /* { scope 2: j, tmp1, tmp2, x, ... */
        /* { scope 3: ptr, best_sum */
        ".Lf1ede14_001ee70e:\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 536 */
        "movl -0x30(%ebp), %ecx\n" /* e */
        "xorl %edx, %edx\n"
        ".Lf1ede14_001ee716:\n"
        "leal (, %edx, 4), %eax\n" /* line 572 | complexity */
        "movaps %xmm4, %xmm0\n" /* line 536 */
        "movl -0xe8(%ebp), %edi\n"
        "mulss (%eax, %edi), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss (%eax, %ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss (%eax, %ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movl 0x1c(%ebp), %edi\n" /* exc */
        "movss %xmm0, (%eax, %edi)\n"
        "addl $1, %edx\n" /* line 535 */
        "cmpl %edx, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001ee716\n"
        "movl -0x24(%ebp), %ebx\n" /* line 541 | x */
        "movl -0x20(%ebp), %ecx\n"
        "xorl %edx, %edx\n"
        "movaps %xmm7, %xmm5\n"
        ".Lf1ede14_001ee75e:\n"
        "leal (, %edx, 4), %eax\n" /* line 572 | complexity */
        "movaps %xmm2, %xmm1\n" /* line 542 */
        "mulss (%eax, %ebx), %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss (%eax, %ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "movl -0xf0(%ebp), %edi\n"
        "mulss (%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl 8(%ebp), %edi\n" /* target */
        "movss (%edi, %edx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movl -0x108(%ebp), %edi\n" /* new_target */
        "movss %xmm0, (%edi, %eax)\n"
        "mulss %xmm0, %xmm0\n" /* line 543 */
        "addss %xmm0, %xmm5\n"
        "addl $1, %edx\n" /* line 539 */
        "cmpl %edx, 0x34(%ebp)\n" /* nsf */
        "jne .Lf1ede14_001ee75e\n"
        "jmp .Lf1ede14_001ee656\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ede14_001ee7b7:\n"
        "mulsd 0x307ea0, %xmm2\n" /* line 481 | -0.001 */
        "movsd %xmm2, -0xe0(%ebp)\n"
        "movl -0xc8(%ebp), %edx\n" /* ptr */
        "xorl %ecx, %ecx\n"
        "movss %xmm7, -0xc4(%ebp)\n" /* best_sum */
        "xorl %esi, %esi\n"
        "movss 0x2ed830, %xmm1\n" /* 32.0f */
        "jmp .Lf1ede14_001ee8b6\n"
        ".Lf1ede14_001ee7e6:\n"
        "movss 0x2ed78c, %xmm3\n" /* line 473 | 64.0f */
        ".Lf1ede14_001ee7ee:\n"
        "movaps %xmm3, %xmm2\n" /* line 487 */
        "mulss %xmm4, %xmm2\n"
        "mulss -0x78(%ebp), %xmm2\n"
        "addss %xmm7, %xmm2\n"
        "movaps %xmm3, %xmm0\n" /* line 488 */
        "mulss %xmm6, %xmm0\n"
        "mulss -0x7c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss %xmm5, %xmm3\n" /* line 489 */
        "mulss -0x80(%ebp), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "movaps %xmm4, %xmm0\n" /* line 490 */
        "mulss %xmm6, %xmm0\n"
        "mulss -0xb4(%ebp), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm6, %xmm0\n" /* line 491 */
        "mulss %xmm5, %xmm0\n"
        "mulss -0xb8(%ebp), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm4, %xmm0\n" /* line 492 */
        "mulss %xmm5, %xmm0\n"
        "mulss -0xbc(%ebp), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm4, %xmm0\n" /* line 493 */
        "mulss %xmm4, %xmm0\n"
        "mulss -0x84(%ebp), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm6, %xmm0\n" /* line 495 */
        "mulss %xmm6, %xmm0\n"
        "mulss -0x88(%ebp), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "mulss -0x8c(%ebp), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "ucomiss -0xc4(%ebp), %xmm2\n" /* line 498 | best_sum */
        "ja .Lf1ede14_001ee89a\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1ede14_001ee8a4\n"
        ".Lf1ede14_001ee89a:\n"
        "movl %ecx, %esi\n"
        "movss %xmm2, -0xc4(%ebp)\n" /* best_sum */
        /* } scope */
        ".Lf1ede14_001ee8a4:\n"
        "addl $1, %ecx\n" /* line 456 */
        "addl $3, %edx\n"
        "cmpl %ecx, -0xcc(%ebp)\n" /* gain_cdbk_size */
        "je .Lf1ede14_001ee94a\n"
        /* { scope 5 */
        ".Lf1ede14_001ee8b6:\n"
        "movsbl (%edx), %eax\n" /* line 464 */
        "cvtsi2ssl %eax, %xmm4\n"
        "addss %xmm1, %xmm4\n"
        "movsbl 1(%edx), %eax\n" /* line 465 */
        "cvtsi2ssl %eax, %xmm6\n"
        "addss %xmm1, %xmm6\n"
        "movsbl 2(%edx), %eax\n" /* line 466 */
        "cvtsi2ssl %eax, %xmm5\n"
        "addss %xmm1, %xmm5\n"
        "ucomiss %xmm7, %xmm4\n" /* line 469 */
        "jbe .Lf1ede14_001ee945\n"
        "movaps %xmm4, %xmm0\n" /* line 470 */
        "addss %xmm6, %xmm0\n"
        ".Lf1ede14_001ee8e5:\n"
        "ucomiss %xmm7, %xmm5\n" /* line 471 */
        "jbe .Lf1ede14_001ee8ee\n"
        "addss %xmm5, %xmm0\n" /* line 472 */
        ".Lf1ede14_001ee8ee:\n"
        "ucomiss 0x2ed78c, %xmm0\n" /* line 473 | 64.0f */
        "jbe .Lf1ede14_001ee7e6\n"
        "subss 0x2ed78c, %xmm0\n" /* line 475 | 64.0f */
        "ucomiss 0x2ed718, %xmm0\n" /* line 476 | 127.0f */
        "jbe .Lf1ede14_001ee93f\n"
        "movsd 0x307ea8, %xmm0\n" /* 127.0 */
        ".Lf1ede14_001ee914:\n"
        "mulsd -0xe0(%ebp), %xmm0\n" /* line 481 */
        "addsd 0x307c10, %xmm0\n" /* 1.0 */
        "mulsd 0x307eb0, %xmm0\n" /* 64.0 */
        "cvtsd2ss %xmm0, %xmm3\n"
        "movaps %xmm7, %xmm0\n" /* line 483 */
        "maxss %xmm3, %xmm0\n"
        "movaps %xmm0, %xmm3\n"
        "jmp .Lf1ede14_001ee7ee\n"
        ".Lf1ede14_001ee93f:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 476 */
        "jmp .Lf1ede14_001ee914\n"
        ".Lf1ede14_001ee945:\n"
        "movaps %xmm6, %xmm0\n" /* line 469 */
        "jmp .Lf1ede14_001ee8e5\n"
        /* } scope */
        ".Lf1ede14_001ee94a:\n"
        "leal (%esi, %esi, 2), %edx\n" /* line 456 */
        "jmp .Lf1ede14_001ee5f0\n"
        /* } scope */
        ".Lf1ede14_001ee952:\n"
        "movl -0x74(%ebp), %edx\n" /* line 336 */
        "movl %edx, 0x1c(%esp)\n"
        "movl 0x30(%ebp), %ecx\n" /* p */
        "movl %ecx, 0x18(%esp)\n"
        "movl 0x34(%ebp), %ebx\n" /* nsf */
        "movl %ebx, 0x14(%esp)\n"
        "movl -0xf0(%ebp), %edi\n"
        "movl %edi, 0x10(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* awk2 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* awk1 */
        "movl %edx, 8(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* ak */
        "movl %ecx, 4(%esp)\n"
        "movl -0xe8(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll syn_percep_zero\n"
        "jmp .Lf1ede14_001ee30b\n"
        /* { scope 4 */
        ".Lf1ede14_001ee999:\n"
        "movsd 0x307e90, %xmm2\n" /* line 442 | 2.0 */
        "jmp .Lf1ede14_001ee53b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1ede14_001ee9a6:\n"
        "movl $1, %ecx\n" /* line 588 */
        "movl $1, %edx\n"
        "jmp .Lf1ede14_001ede39\n"
    );
}

