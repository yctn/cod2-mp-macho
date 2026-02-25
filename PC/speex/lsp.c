/* ASM dump from: lsp.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/lsp.c */

#include "common_types.h"
#include "imports.h"

void lsp_to_lpc(spx_lsp_t *freq, spx_coef_t *ak, int lpcrdr, char *stack);
void lsp_enforce_margin(spx_lsp_t *lsp, int len, spx_word16_t margin);
void lsp_interpolate(spx_lsp_t *old_lsp, spx_lsp_t *new_lsp, spx_lsp_t *interp_lsp, int len, int subframe, int nb_subframes);
int lpc_to_lsp(spx_coef_t *a, int lpcrdr, spx_lsp_t *freq, int nb, spx_word16_t delta, char *stack);

/* line 488 */
__attribute__((naked))
void lsp_to_lpc(spx_lsp_t *freq, spx_coef_t *ak, int lpcrdr, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 488 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* stack */
        /* { scope 1 */
        "movl 0x10(%ebp), %ebx\n" /* line 500 | lpcrdr, m */
        "sarl $1, %ebx\n" /* m */
        "movl %eax, %edx\n" /* line 502 */
        "negl %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n" /* m */
        "shll $4, %edx\n"
        "leal 8(%eax, %edx), %esi\n" /* j */
        "movl %eax, -0x10(%ebp)\n" /* Wp */
        "leal 1(, %ebx, 4), %ecx\n" /* line 507 */
        "testl %ecx, %ecx\n"
        "js .Lf1f5464_001f54a7\n"
        "xorl %edx, %edx\n"
        ".Lf1f5464_001f5497:\n"
        "movl $0, (%eax)\n" /* line 508 */
        "addl $4, %eax\n"
        "addl $1, %edx\n" /* line 507 */
        "cmpl %edx, %ecx\n"
        "jge .Lf1f5464_001f5497\n"
        ".Lf1f5464_001f54a7:\n"
        "movl %esi, %eax\n" /* line 517 | j */
        "negl %eax\n"
        "andl $3, %eax\n"
        "leal (%esi, %eax), %edi\n" /* j, x_freq */
        "cmpl $0, 0x10(%ebp)\n" /* line 518 | lpcrdr */
        "jle .Lf1f5464_001f5638\n"
        "xorl %edx, %edx\n"
        "movsd 0x307fa8, %xmm3\n" /* 1.5707963268 */
        "movss 0x2edac4, %xmm7\n" /* 0.04148774594068527f */
        "movss 0x2edac8, %xmm6\n" /* 0.49991244077682495f */
        "movss 0x2edacc, %xmm5\n" /* 0.9999933242797852f */
        "movsd 0x307c28, %xmm4\n" /* 3.141592653589793 */
        "movss 0x306ac0, %xmm2\n"
        "jmp .Lf1f5464_001f551f\n"
        /* { scope 2 */
        ".Lf1f5464_001f54ef:\n"
        "mulss %xmm0, %xmm0\n" /* line 113 */
        "movaps %xmm0, %xmm1\n" /* line 114 */
        "mulss 0x2edac0, %xmm1\n" /* -0.0012712094467133284f */
        "addss %xmm7, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "subss %xmm6, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm5, %xmm1\n"
        /* } scope */
        "movss %xmm1, (%edi, %eax)\n" /* line 519 | x_freq */
        "addl $1, %edx\n" /* line 518 */
        "cmpl %edx, 0x10(%ebp)\n" /* lpcrdr */
        "je .Lf1f5464_001f5577\n"
        ".Lf1f5464_001f551f:\n"
        "leal (, %edx, 4), %eax\n" /* line 488 | stack */
        "movl 8(%ebp), %ecx\n" /* line 519 | freq */
        "movss (%ecx, %eax), %xmm0\n" /* x */
        /* { scope 2 */
        "cvtss2sd %xmm0, %xmm1\n" /* line 111 */
        "ucomisd %xmm1, %xmm3\n"
        "ja .Lf1f5464_001f54ef\n"
        "movapd %xmm4, %xmm0\n" /* line 116 */
        "subsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "mulss %xmm0, %xmm0\n" /* line 117 */
        "movaps %xmm0, %xmm1\n" /* line 118 */
        "mulss 0x2edac0, %xmm1\n" /* -0.0012712094467133284f */
        "addss %xmm7, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "subss %xmm6, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm5, %xmm1\n"
        "xorps %xmm2, %xmm1\n"
        /* } scope */
        "movss %xmm1, (%edi, %eax)\n" /* line 519 | x_freq */
        "addl $1, %edx\n" /* line 518 */
        "cmpl %edx, 0x10(%ebp)\n" /* lpcrdr */
        "jne .Lf1f5464_001f551f\n"
        ".Lf1f5464_001f5577:\n"
        "xorl %eax, %eax\n" /* line 525 */
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm3, %xmm4\n"
        "xorl %esi, %esi\n" /* j */
        ".Lf1f5464_001f5586:\n"
        "testl %ebx, %ebx\n" /* line 527 | m */
        "jle .Lf1f5464_001f55f1\n"
        "movl -0x10(%ebp), %edx\n" /* Wp */
        "xorl %ecx, %ecx\n"
        "movss 0x2ed628, %xmm5\n" /* -2.0f */
        ".Lf1f5464_001f5597:\n"
        "leal (%edi, %ecx, 8), %eax\n" /* line 488 | stack */
        "movss (%edx), %xmm2\n" /* line 532 */
        "movss (%eax), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm3, %xmm1\n"
        "addss 4(%edx), %xmm1\n"
        "movss 4(%eax), %xmm0\n" /* line 533 */
        "mulss %xmm5, %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "addss 0xc(%edx), %xmm0\n"
        "movss %xmm2, 4(%edx)\n" /* line 534 */
        "movl 8(%edx), %eax\n" /* line 535 */
        "movl %eax, 0xc(%edx)\n"
        "movss %xmm3, (%edx)\n" /* line 536 */
        "movss %xmm4, 8(%edx)\n" /* line 537 */
        "addl $1, %ecx\n" /* line 527 */
        "addl $0x10, %edx\n"
        "movaps %xmm0, %xmm4\n"
        "movaps %xmm1, %xmm3\n"
        "cmpl %ecx, %ebx\n" /* m */
        "jne .Lf1f5464_001f5597\n"
        "leal -4(%edx), %eax\n"
        ".Lf1f5464_001f55f1:\n"
        "movaps %xmm3, %xmm0\n" /* line 541 */
        "addss 4(%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n" /* line 542 */
        "subss 8(%eax), %xmm1\n"
        "testl %esi, %esi\n" /* line 543 | j */
        "jle .Lf1f5464_001f561a\n"
        "addss %xmm1, %xmm0\n" /* line 544 */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movl 0xc(%ebp), %edx\n" /* ak */
        "movss %xmm0, -4(%edx, %esi, 4)\n"
        ".Lf1f5464_001f561a:\n"
        "movss %xmm3, 4(%eax)\n" /* line 545 */
        "movss %xmm4, 8(%eax)\n" /* line 546 */
        "addl $1, %esi\n" /* line 525 | j */
        "cmpl %esi, 0x10(%ebp)\n" /* j, lpcrdr */
        "jl .Lf1f5464_001f563e\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm4\n"
        "jmp .Lf1f5464_001f5586\n"
        ".Lf1f5464_001f5638:\n"
        "je .Lf1f5464_001f5577\n"
        /* } scope */
        ".Lf1f5464_001f563e:\n"
        "addl $4, %esp\n" /* line 552 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 594 */
__attribute__((naked))
void lsp_enforce_margin(spx_lsp_t *lsp, int len, spx_word16_t margin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 594 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* lsp */
        "movl 0xc(%ebp), %edx\n" /* len */
        "movss 0x10(%ebp), %xmm5\n" /* margin */
        /* { scope 1 */
        "ucomiss (%ebx), %xmm5\n" /* line 597 | lsp */
        "jbe .Lf1f5646_001f565e\n"
        "movss %xmm5, (%ebx)\n" /* line 598 | lsp */
        ".Lf1f5646_001f565e:\n"
        "leal (%ebx, %edx, 4), %eax\n" /* line 599 | lsp */
        "cvtss2sd %xmm5, %xmm4\n"
        "movsd 0x307c28, %xmm1\n" /* 3.141592653589793 */
        "subsd %xmm4, %xmm1\n"
        "cvtss2sd -4(%eax), %xmm0\n"
        "ucomisd %xmm1, %xmm0\n"
        "jbe .Lf1f5646_001f5685\n"
        "cvtsd2ss %xmm1, %xmm1\n" /* line 600 */
        "movss %xmm1, -4(%eax)\n"
        ".Lf1f5646_001f5685:\n"
        "leal -1(%edx), %ecx\n" /* line 601 */
        "cmpl $1, %ecx\n"
        "jle .Lf1f5646_001f56fd\n"
        "movl $1, %edx\n"
        "movsd 0x307ce0, %xmm6\n" /* 0.5 */
        "leal 4(%ebx), %eax\n" /* lsp */
        "jmp .Lf1f5646_001f56e0\n"
        ".Lf1f5646_001f569f:\n"
        "addss %xmm5, %xmm2\n" /* line 604 */
        "movss %xmm2, (%eax)\n"
        ".Lf1f5646_001f56a7:\n"
        "movss 4(%eax), %xmm3\n" /* line 606 */
        "cvtss2sd %xmm2, %xmm1\n"
        "cvtss2sd %xmm3, %xmm0\n"
        "subsd %xmm4, %xmm0\n"
        "ucomisd %xmm0, %xmm1\n"
        "jbe .Lf1f5646_001f56d6\n"
        "addss %xmm3, %xmm2\n" /* line 607 */
        "cvtss2sd %xmm2, %xmm0\n"
        "subsd %xmm4, %xmm0\n"
        "mulsd %xmm6, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        ".Lf1f5646_001f56d6:\n"
        "addl $1, %edx\n" /* line 601 */
        "addl $4, %eax\n"
        "cmpl %ecx, %edx\n"
        "je .Lf1f5646_001f56fd\n"
        ".Lf1f5646_001f56e0:\n"
        "movss -4(%eax), %xmm2\n" /* line 603 */
        "cvtss2sd (%eax), %xmm1\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "addsd %xmm4, %xmm0\n"
        "ucomisd %xmm1, %xmm0\n"
        "ja .Lf1f5646_001f569f\n"
        "movss (%eax), %xmm2\n"
        "jmp .Lf1f5646_001f56a7\n"
        /* } scope */
        ".Lf1f5646_001f56fd:\n"
        "popl %ebx\n" /* line 609 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 612 */
__attribute__((naked))
void lsp_interpolate(spx_lsp_t *old_lsp, spx_lsp_t *new_lsp, spx_lsp_t *interp_lsp, int len, int subframe, int nb_subframes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 612 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* old_lsp */
        "movl 0xc(%ebp), %esi\n" /* new_lsp */
        "movl 0x10(%ebp), %ebx\n" /* interp_lsp */
        "movl 0x14(%ebp), %ecx\n" /* len */
        /* { scope 1 */
        "cvtsi2ssl 0x18(%ebp), %xmm3\n" /* line 615 | subframe, tmp */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "addss %xmm1, %xmm3\n" /* tmp */
        "cvtsi2ssl 0x1c(%ebp), %xmm0\n" /* nb_subframes */
        "divss %xmm0, %xmm3\n" /* tmp */
        "testl %ecx, %ecx\n" /* line 616 */
        "jle .Lf1f5700_001f5760\n"
        "movaps %xmm1, %xmm2\n"
        "subss %xmm3, %xmm2\n"
        "xorl %edx, %edx\n"
        ".Lf1f5700_001f5739:\n"
        "leal (, %edx, 4), %eax\n" /* line 612 */
        "movaps %xmm2, %xmm0\n" /* line 618 */
        "mulss (%eax, %edi), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx, %eax)\n" /* interp_lsp */
        "addl $1, %edx\n" /* line 616 */
        "cmpl %edx, %ecx\n"
        "jne .Lf1f5700_001f5739\n"
        /* } scope */
        ".Lf1f5700_001f5760:\n"
        "popl %ebx\n" /* line 620 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 238 */
__attribute__((naked))
int lpc_to_lsp(spx_coef_t *a, int lpcrdr, spx_lsp_t *freq, int nb, spx_word16_t delta, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 238 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 0x1c(%ebp), %edx\n" /* stack */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 261 | lpcrdr */
        "shrl $0x1f, %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* lpcrdr */
        "leal (%eax, %ecx), %edi\n" /* k */
        "sarl $1, %edi\n" /* k */
        "leal (, %edi, 4), %ebx\n" /* line 264 | i */
        "movl $4, %ecx\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal 4(%edx, %ebx), %edx\n"
        "movl %ebx, %eax\n" /* i */
        "negl %eax\n"
        "leal (%edx, %eax), %esi\n"
        "movl %esi, -0x3c(%ebp)\n"
        "subl $4, %esi\n"
        "movl %esi, -0x34(%ebp)\n" /* Q */
        "subl %edx, %ecx\n" /* line 265 */
        "andl $3, %ecx\n"
        "addl %ecx, %edx\n"
        "leal 4(%ebx, %edx), %edx\n" /* i */
        "movl %edx, -0x1c(%ebp)\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "subl $4, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* P */
        "movl -0x6c(%ebp), %eax\n" /* line 299 */
        "movl $0x3f800000, -4(%eax)\n"
        "movl -0x3c(%ebp), %edx\n" /* line 300 */
        "movl $0x3f800000, -4(%edx)\n"
        "testl %edi, %edi\n" /* line 301 | k */
        "jle .Lf1f5766_001f5863\n"
        "movl 0xc(%ebp), %esi\n" /* line 238 | lpcrdr */
        "movl 8(%ebp), %eax\n" /* a */
        "leal (%eax, %esi, 4), %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl %eax, %esi\n"
        "jmp .Lf1f5766_001f57f0\n"
        ".Lf1f5766_001f57ed:\n"
        "movl 8(%ebp), %esi\n" /* a */
        ".Lf1f5766_001f57f0:\n"
        "leal (, %ebx, 4), %eax\n"
        "leal (%eax, %esi), %edx\n" /* stack */
        "movss (%edx), %xmm0\n" /* line 302 */
        "addss -4(%ecx), %xmm0\n"
        "movl -0x30(%ebp), %esi\n" /* P */
        "subss (%eax, %esi), %xmm0\n"
        "movl -0x6c(%ebp), %esi\n"
        "movss %xmm0, (%eax, %esi)\n"
        "movss (%edx), %xmm0\n" /* line 303 */
        "subss -4(%ecx), %xmm0\n"
        "movl -0x34(%ebp), %edx\n" /* Q */
        "addss (%eax, %edx), %xmm0\n"
        "movl -0x3c(%ebp), %esi\n"
        "movss %xmm0, (%eax, %esi)\n"
        "addl $1, %ebx\n" /* line 301 | i */
        "subl $4, %ecx\n"
        "cmpl %ebx, %edi\n" /* i, k */
        "jne .Lf1f5766_001f57ed\n"
        "movl -0x30(%ebp), %edx\n" /* P */
        "movl -0x34(%ebp), %eax\n" /* Q */
        "xorl %ecx, %ecx\n"
        ".Lf1f5766_001f583e:\n"
        "movss (%edx), %xmm0\n" /* line 308 */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%eax), %xmm0\n" /* line 309 */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $4, %edx\n" /* line 310 */
        "addl $4, %eax\n" /* line 311 */
        "addl $1, %ecx\n" /* line 307 */
        "cmpl %ecx, %edi\n" /* k */
        "jne .Lf1f5766_001f583e\n"
        ".Lf1f5766_001f5863:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 325 | lpcrdr */
        "testl %ecx, %ecx\n"
        "jle .Lf1f5766_001f5b13\n"
        "movl 0xc(%ebp), %esi\n" /* lpcrdr */
        "sarl $1, %esi\n"
        "leal (, %esi, 4), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "negl %eax\n"
        "andl $3, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "leal 4(%edx, %eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "subl $4, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm5\n"
        "movss 0x2ed5d0, %xmm6\n" /* 1.0f */
        "movl $0, -0x38(%ebp)\n" /* j */
        "movl $0, -0x2c(%ebp)\n" /* roots */
        "cvtss2sd 0x18(%ebp), %xmm0\n" /* delta */
        "movsd %xmm0, -0x48(%ebp)\n"
        "movl %eax, %edx\n"
        ".Lf1f5766_001f58be:\n"
        "testb $1, -0x38(%ebp)\n" /* line 326 | j */
        "movl -0x34(%ebp), %eax\n" /* Q */
        "cmovel -0x30(%ebp), %eax\n" /* P */
        /* { scope 2 */
        /* { scope 3 */
        "movl $0x3f800000, (%edx)\n" /* line 202 */
        "movl -0x40(%ebp), %ecx\n" /* line 203 */
        "movss %xmm6, (%ecx)\n"
        "addl -0x24(%ebp), %eax\n" /* line 207 */
        "leal -4(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movaps %xmm6, %xmm3\n"
        "mulss -4(%eax), %xmm3\n"
        "addss (%eax), %xmm3\n"
        "movaps %xmm6, %xmm1\n" /* line 208 */
        "addss %xmm6, %xmm1\n"
        "cmpl $1, %esi\n" /* line 209 */
        "jle .Lf1f5766_001f592b\n"
        "movl %eax, %ecx\n" /* line 238 */
        "movl $2, %ebx\n" /* i */
        "movl -0x20(%ebp), %edx\n" /* stack */
        "addl $8, %edx\n" /* stack */
        ".Lf1f5766_001f5904:\n"
        "movaps %xmm1, %xmm0\n" /* line 211 */
        "mulss -4(%edx), %xmm0\n"
        "subss -8(%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "mulss -8(%ecx), %xmm0\n" /* line 212 */
        "addss %xmm0, %xmm3\n"
        "addl $1, %ebx\n" /* line 209 | i */
        "addl $4, %edx\n"
        "subl $4, %ecx\n"
        "cmpl %esi, %ebx\n" /* i */
        "jle .Lf1f5766_001f5904\n"
        /* } scope */
        /* } scope */
        ".Lf1f5766_001f592b:\n"
        "ucomiss 0x2ed5dc, %xmm4\n" /* line 333 | -1.0f */
        "jb .Lf1f5766_001f5ae0\n"
        "movss 0x306ad0, %xmm7\n"
        /* { scope 2 */
        ".Lf1f5766_001f5940:\n"
        "cvtss2sd %xmm6, %xmm0\n" /* line 341 */
        "movapd %xmm0, %xmm1\n"
        "mulsd 0x307fb0, %xmm1\n" /* -0.9 */
        "mulsd %xmm1, %xmm0\n"
        "addsd 0x307c10, %xmm0\n" /* 1.0 */
        "mulsd -0x48(%ebp), %xmm0\n"
        "cvtsd2ss %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n" /* line 342 */
        "andps %xmm7, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd 0x307f60, %xmm2\n" /* 0.2 */
        "ucomisd %xmm0, %xmm2\n"
        "jbe .Lf1f5766_001f5985\n"
        "mulss 0x2ed5d8, %xmm1\n" /* line 343 | 0.5f */
        ".Lf1f5766_001f5985:\n"
        "movaps %xmm6, %xmm4\n" /* line 345 */
        "subss %xmm1, %xmm4\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl -0x20(%ebp), %edx\n" /* line 202 */
        "movl $0x3f800000, (%edx)\n"
        "movl -0x40(%ebp), %ecx\n" /* line 203 */
        "movss %xmm4, (%ecx)\n"
        "movaps %xmm4, %xmm1\n" /* line 207 */
        "movl -0x28(%ebp), %edx\n"
        "mulss (%edx), %xmm1\n"
        "addss (%eax), %xmm1\n"
        "movaps %xmm4, %xmm2\n" /* line 208 */
        "addss %xmm4, %xmm2\n"
        "cmpl $1, %esi\n" /* line 209 */
        "jle .Lf1f5766_001f59ea\n"
        "movl %eax, %ecx\n" /* line 238 */
        "movl $2, %ebx\n" /* i */
        "movl -0x20(%ebp), %edx\n" /* stack */
        "addl $8, %edx\n" /* stack */
        ".Lf1f5766_001f59c3:\n"
        "movaps %xmm2, %xmm0\n" /* line 211 */
        "mulss -4(%edx), %xmm0\n"
        "subss -8(%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "mulss -8(%ecx), %xmm0\n" /* line 212 */
        "addss %xmm0, %xmm1\n"
        "addl $1, %ebx\n" /* line 209 | i */
        "addl $4, %edx\n"
        "subl $4, %ecx\n"
        "cmpl %esi, %ebx\n" /* i */
        "jle .Lf1f5766_001f59c3\n"
        /* } scope */
        /* } scope */
        ".Lf1f5766_001f59ea:\n"
        "movaps %xmm1, %xmm0\n" /* line 359 */
        "mulss %xmm3, %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1f5766_001f5a12\n"
        /* } scope */
        "ucomiss 0x2ed5dc, %xmm4\n" /* line 333 | -1.0f */
        "jb .Lf1f5766_001f5af9\n"
        "movaps %xmm4, %xmm6\n"
        "movaps %xmm1, %xmm3\n"
        "jmp .Lf1f5766_001f5940\n"
        /* { scope 2 */
        ".Lf1f5766_001f5a12:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 361 | roots */
        "movl 0x14(%ebp), %edx\n" /* line 364 | nb */
        "testl %edx, %edx\n"
        "js .Lf1f5766_001f5ab6\n"
        "xorl %edi, %edi\n" /* k */
        "movss 0x2ed5d8, %xmm7\n" /* 0.5f */
        ".Lf1f5766_001f5a2b:\n"
        "movaps %xmm6, %xmm5\n" /* line 368 */
        "addss %xmm4, %xmm5\n"
        "mulss %xmm7, %xmm5\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl -0x20(%ebp), %edx\n" /* line 202 */
        "movl $0x3f800000, (%edx)\n"
        "movl -0x40(%ebp), %ecx\n" /* line 203 */
        "movss %xmm5, (%ecx)\n"
        "movaps %xmm5, %xmm1\n" /* line 207 */
        "movl -0x28(%ebp), %edx\n"
        "mulss (%edx), %xmm1\n"
        "addss (%eax), %xmm1\n"
        "movaps %xmm5, %xmm2\n" /* line 208 */
        "addss %xmm5, %xmm2\n"
        "cmpl $1, %esi\n" /* line 209 */
        "jle .Lf1f5766_001f5a94\n"
        "movl %eax, %ecx\n" /* line 238 */
        "movl $2, %ebx\n" /* i */
        "movl -0x20(%ebp), %edx\n" /* stack */
        "addl $8, %edx\n" /* stack */
        ".Lf1f5766_001f5a6d:\n"
        "movaps %xmm2, %xmm0\n" /* line 211 */
        "mulss -4(%edx), %xmm0\n"
        "subss -8(%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "mulss -8(%ecx), %xmm0\n" /* line 212 */
        "addss %xmm0, %xmm1\n"
        "addl $1, %ebx\n" /* line 209 | i */
        "addl $4, %edx\n"
        "subl $4, %ecx\n"
        "cmpl %esi, %ebx\n" /* i */
        "jle .Lf1f5766_001f5a6d\n"
        /* } scope */
        /* } scope */
        ".Lf1f5766_001f5a94:\n"
        "movaps %xmm1, %xmm0\n" /* line 372 */
        "mulss %xmm3, %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1f5766_001f5af4\n"
        "movaps %xmm5, %xmm6\n"
        "movaps %xmm1, %xmm3\n"
        ".Lf1f5766_001f5aaa:\n"
        "addl $1, %edi\n" /* line 364 | k */
        "cmpl %edi, 0x14(%ebp)\n" /* k, nb */
        "jge .Lf1f5766_001f5a2b\n"
        ".Lf1f5766_001f5ab6:\n"
        "movss %xmm5, (%esp)\n" /* line 383 */
        "movss %xmm4, -0x58(%ebp)\n"
        "movss %xmm5, -0x68(%ebp)\n"
        "calll acosf\n"
        "movl -0x38(%ebp), %eax\n" /* j */
        "movl 0x10(%ebp), %edx\n" /* freq */
        "fstps (%edx, %eax, 4)\n"
        "movss -0x68(%ebp), %xmm5\n"
        "movaps %xmm5, %xmm6\n"
        "movss -0x58(%ebp), %xmm4\n"
        /* } scope */
        ".Lf1f5766_001f5ae0:\n"
        "addl $1, -0x38(%ebp)\n" /* line 325 | j */
        "movl -0x38(%ebp), %ecx\n" /* j */
        "cmpl %ecx, 0xc(%ebp)\n" /* lpcrdr */
        "je .Lf1f5766_001f5b08\n"
        ".Lf1f5766_001f5aec:\n"
        "movl -0x20(%ebp), %edx\n"
        "jmp .Lf1f5766_001f58be\n"
        /* { scope 2 */
        ".Lf1f5766_001f5af4:\n"
        "movaps %xmm5, %xmm4\n" /* line 372 */
        "jmp .Lf1f5766_001f5aaa\n"
        /* } scope */
        ".Lf1f5766_001f5af9:\n"
        "movaps %xmm4, %xmm6\n" /* line 333 */
        "addl $1, -0x38(%ebp)\n" /* line 325 | j */
        "movl -0x38(%ebp), %ecx\n" /* j */
        "cmpl %ecx, 0xc(%ebp)\n" /* lpcrdr */
        "jne .Lf1f5766_001f5aec\n"
        /* } scope */
        ".Lf1f5766_001f5b08:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 394 | roots */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f5766_001f5b13:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 325 | roots */
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 394 | roots */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

