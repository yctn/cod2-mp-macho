/* ASM dump from: quant_lsp.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/quant_lsp.c */

#include "common_types.h"
#include "imports.h"

extern const signed char cdbk_nb[640]; /* 0x0 */
extern const signed char cdbk_nb_low1[320]; /* 0x0 */
extern const signed char cdbk_nb_low2[320]; /* 0x0 */
extern const signed char cdbk_nb_high1[320]; /* 0x0 */
extern const signed char cdbk_nb_high2[320]; /* 0x0 */
static const signed char high_lsp_cdbk[512]; /* 0x306220 */
static const signed char high_lsp_cdbk2[512]; /* 0x306020 */

void lsp_unquant_nb(spx_lsp_t *lsp, int order, SpeexBits *bits);
void lsp_unquant_lbr(spx_lsp_t *lsp, int order, SpeexBits *bits);
void lsp_quant_high(spx_lsp_t *lsp, spx_lsp_t *qlsp, int order, SpeexBits *bits);
void lsp_unquant_high(spx_lsp_t *lsp, int order, SpeexBits *bits);
void lsp_quant_nb(spx_lsp_t *lsp, spx_lsp_t *qlsp, int order, SpeexBits *bits);
void lsp_quant_lbr(spx_lsp_t *lsp, spx_lsp_t *qlsp, int order, SpeexBits *bits);

/* line 211 */
__attribute__((naked))
void lsp_unquant_nb(spx_lsp_t *lsp, int order, SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 211 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* lsp */
        "movl 0xc(%ebp), %edx\n" /* order */
        "movl 0x10(%ebp), %edi\n" /* bits */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 214 */
        "jle .Lf1ef918_001ef954\n"
        "xorl %eax, %eax\n"
        "movsd 0x307ed0, %xmm1\n" /* 0.25 */
        ".Lf1ef918_001ef938:\n"
        "cvtsi2sdl %eax, %xmm0\n" /* line 215 */
        "mulsd %xmm1, %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%esi, %eax, 4)\n" /* lsp */
        "addl $1, %eax\n" /* line 214 */
        "cmpl %eax, %edx\n"
        "jne .Lf1ef918_001ef938\n"
        ".Lf1ef918_001ef954:\n"
        "movl $6, 4(%esp)\n" /* line 218 */
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal cdbk_nb(%eax, %eax), %ecx\n"
        "movl $1, %ebx\n"
        "movsd 0x307ed8, %xmm2\n" /* 0.0039062 */
        "leal 4(%esi), %edx\n" /* lsp */
        ".Lf1ef918_001ef97e:\n"
        "cvtss2sd -4(%edx), %xmm0\n" /* line 220 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ebx\n"
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $0xb, %ebx\n" /* line 219 */
        "jne .Lf1ef918_001ef97e\n"
        "movl $6, 4(%esp)\n" /* line 222 */
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal cdbk_nb_low1(%eax, %eax, 4), %ecx\n"
        "movb $1, %bl\n"
        "movsd 0x307ee0, %xmm2\n" /* 0.0019531 */
        "leal 4(%esi), %edx\n" /* lsp */
        ".Lf1ef918_001ef9cd:\n"
        "cvtss2sd -4(%edx), %xmm0\n" /* line 224 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ebx\n"
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $6, %ebx\n" /* line 223 */
        "jne .Lf1ef918_001ef9cd\n"
        "movl $6, 4(%esp)\n" /* line 226 */
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal cdbk_nb_low2(%eax, %eax, 4), %ecx\n"
        "movb $1, %bl\n"
        "movsd 0x307ee8, %xmm2\n" /* 0.00097656 */
        "leal 4(%esi), %edx\n" /* lsp */
        ".Lf1ef918_001efa1c:\n"
        "cvtss2sd -4(%edx), %xmm0\n" /* line 228 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ebx\n"
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $6, %ebx\n" /* line 227 */
        "jne .Lf1ef918_001efa1c\n"
        "movl $6, 4(%esp)\n" /* line 230 */
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal cdbk_nb_high1(%eax, %eax, 4), %ecx\n"
        "xorb %bl, %bl\n"
        "movsd 0x307ee0, %xmm2\n" /* 0.0019531 */
        "movl %esi, %edx\n" /* lsp */
        ".Lf1ef918_001efa6a:\n"
        "cvtss2sd 0x14(%edx), %xmm0\n" /* line 232 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x14(%edx)\n"
        "addl $1, %ebx\n" /* line 231 */
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $5, %ebx\n"
        "jne .Lf1ef918_001efa6a\n"
        "movl $6, 4(%esp)\n" /* line 234 */
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal cdbk_nb_high2(%eax, %eax, 4), %ecx\n"
        "xorb %bl, %bl\n"
        "movsd 0x307ee8, %xmm2\n" /* 0.00097656 */
        "movl %esi, %edx\n" /* lsp */
        ".Lf1ef918_001efab8:\n"
        "cvtss2sd 0x14(%edx), %xmm0\n" /* line 236 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x14(%edx)\n"
        "addl $1, %ebx\n" /* line 235 */
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $5, %ebx\n"
        "jne .Lf1ef918_001efab8\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 237 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 281 */
__attribute__((naked))
void lsp_unquant_lbr(spx_lsp_t *lsp, int order, SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 281 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* lsp */
        "movl 0xc(%ebp), %edx\n" /* order */
        "movl 0x10(%ebp), %edi\n" /* bits */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 284 */
        "jle .Lf1efaec_001efb28\n"
        "xorl %eax, %eax\n"
        "movsd 0x307ed0, %xmm1\n" /* 0.25 */
        ".Lf1efaec_001efb0c:\n"
        "cvtsi2sdl %eax, %xmm0\n" /* line 285 */
        "mulsd %xmm1, %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%esi, %eax, 4)\n" /* lsp */
        "addl $1, %eax\n" /* line 284 */
        "cmpl %eax, %edx\n"
        "jne .Lf1efaec_001efb0c\n"
        ".Lf1efaec_001efb28:\n"
        "movl $6, 4(%esp)\n" /* line 288 */
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal cdbk_nb(%eax, %eax), %ecx\n"
        "movl $1, %ebx\n"
        "movsd 0x307ed8, %xmm2\n" /* 0.0039062 */
        "leal 4(%esi), %edx\n" /* lsp */
        ".Lf1efaec_001efb52:\n"
        "cvtss2sd -4(%edx), %xmm0\n" /* line 290 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ebx\n"
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $0xb, %ebx\n" /* line 289 */
        "jne .Lf1efaec_001efb52\n"
        "movl $6, 4(%esp)\n" /* line 292 */
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal cdbk_nb_low1(%eax, %eax, 4), %ecx\n"
        "movb $1, %bl\n"
        "movsd 0x307ee0, %xmm2\n" /* 0.0019531 */
        "leal 4(%esi), %edx\n" /* lsp */
        ".Lf1efaec_001efba1:\n"
        "cvtss2sd -4(%edx), %xmm0\n" /* line 294 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ebx\n"
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $6, %ebx\n" /* line 293 */
        "jne .Lf1efaec_001efba1\n"
        "movl $6, 4(%esp)\n" /* line 296 */
        "movl %edi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal cdbk_nb_high1(%eax, %eax, 4), %ecx\n"
        "xorb %bl, %bl\n"
        "movsd 0x307ee0, %xmm2\n" /* 0.0019531 */
        "movl %esi, %edx\n" /* lsp */
        ".Lf1efaec_001efbef:\n"
        "cvtss2sd 0x14(%edx), %xmm0\n" /* line 298 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x14(%edx)\n"
        "addl $1, %ebx\n" /* line 297 */
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $5, %ebx\n"
        "jne .Lf1efaec_001efbef\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 317 */
__attribute__((naked))
void lsp_quant_high(spx_lsp_t *lsp, spx_lsp_t *qlsp, int order, SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 317 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* qlsp */
        "movl 0x10(%ebp), %esi\n" /* order */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 323 | order */
        "jle .Lf1efc22_001efd44\n"
        "xorl %ecx, %ecx\n"
        ".Lf1efc22_001efc3b:\n"
        "leal (, %ecx, 4), %edx\n" /* line 317 */
        "movl 8(%ebp), %ebx\n" /* line 324 | lsp, i */
        "movl (%ebx, %edx), %eax\n" /* i */
        "movl %eax, (%edi, %edx)\n" /* qlsp */
        "addl $1, %ecx\n" /* line 323 */
        "cmpl %ecx, %esi\n" /* order */
        "jne .Lf1efc22_001efc3b\n"
        "leal -1(%esi), %eax\n" /* order */
        "movl %eax, -0x50(%ebp)\n"
        "movss (%edi), %xmm5\n" /* qlsp */
        "leal 4(%edi), %ebx\n" /* qlsp, i */
        "movl %ebx, -0x58(%ebp)\n" /* i */
        "movsd 0x307ec0, %xmm4\n" /* 0.04 */
        "movsd 0x307ef0, %xmm3\n" /* 10.0 */
        "movl %ebx, %eax\n" /* i */
        "jmp .Lf1efc22_001efc79\n"
        ".Lf1efc22_001efc76:\n"
        "movl -0x58(%ebp), %eax\n"
        /* { scope 2 */
        ".Lf1efc22_001efc79:\n"
        "movaps %xmm5, %xmm2\n" /* line 79 */
        "movl %eax, %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %edx, %edx\n"
        "cmpl -0x50(%ebp), %ebx\n" /* line 82 | i */
        "je .Lf1efc22_001efcd1\n"
        ".Lf1efc22_001efc87:\n"
        "movss (%eax), %xmm0\n" /* line 85 */
        "subss -4(%eax), %xmm0\n"
        ".Lf1efc22_001efc90:\n"
        "minss %xmm2, %xmm0\n" /* line 86 */
        "cvtss2sd %xmm0, %xmm0\n" /* line 91 */
        "addsd %xmm4, %xmm0\n"
        "movapd %xmm3, %xmm1\n"
        "divsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%ebp, %edx)\n"
        "addl $1, %ebx\n" /* line 76 | i */
        "cmpl %ebx, %esi\n" /* i */
        "jle .Lf1efc22_001efce8\n"
        /* } scope */
        "addl $4, %ecx\n" /* line 323 */
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 78 | i */
        "je .Lf1efc22_001efc76\n"
        "movss -4(%ecx), %xmm2\n" /* line 81 */
        "subss -8(%ecx), %xmm2\n"
        "cmpl -0x50(%ebp), %ebx\n" /* line 82 | i */
        "jne .Lf1efc22_001efc87\n"
        ".Lf1efc22_001efcd1:\n"
        "cvtss2sd -4(%eax), %xmm1\n" /* line 83 */
        "movsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "subsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "jmp .Lf1efc22_001efc90\n"
        ".Lf1efc22_001efce8:\n"
        "xorl %edx, %edx\n" /* line 76 */
        "movsd 0x307ef8, %xmm3\n" /* 0.3125 */
        "movsd 0x307d00, %xmm2\n" /* 0.75 */
        "movl %edi, %eax\n"
        /* } scope */
        ".Lf1efc22_001efcfc:\n"
        "cvtss2sd (%eax), %xmm1\n" /* line 338 */
        "cvtsi2sdl %edx, %xmm0\n"
        "mulsd %xmm3, %xmm0\n"
        "addsd %xmm2, %xmm0\n"
        "subsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "addl $1, %edx\n" /* line 337 */
        "addl $4, %eax\n"
        "cmpl %edx, %esi\n" /* order */
        "jne .Lf1efc22_001efcfc\n"
        "xorl %edx, %edx\n"
        "movss 0x2ed8b0, %xmm1\n" /* 256.0f */
        "movl %edi, %eax\n" /* qlsp */
        ".Lf1efc22_001efd2e:\n"
        "movss (%eax), %xmm0\n" /* line 341 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 340 */
        "addl $4, %eax\n"
        "cmpl %edx, %esi\n" /* order */
        "jne .Lf1efc22_001efd2e\n"
        ".Lf1efc22_001efd44:\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm3\n"
        "movl $0, -0x54(%ebp)\n" /* id */
        "movl $high_lsp_cdbk, %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf1efc22_001efd75\n"
        /* { scope 2 */
        ".Lf1efc22_001efd5b:\n"
        "movaps %xmm4, %xmm2\n" /* line 109 */
        "ucomiss %xmm2, %xmm3\n" /* line 114 */
        "ja .Lf1efc22_001efda5\n"
        ".Lf1efc22_001efd63:\n"
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1efc22_001efda5\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %ebx\n" /* line 106 | i */
        "cmpl $0x40, %ebx\n" /* i */
        "je .Lf1efc22_001efdb0\n"
        ".Lf1efc22_001efd72:\n"
        "movaps %xmm2, %xmm3\n"
        ".Lf1efc22_001efd75:\n"
        "testl %esi, %esi\n" /* line 109 */
        "jle .Lf1efc22_001efd5b\n"
        "xorl %edx, %edx\n"
        "movaps %xmm4, %xmm2\n"
        ".Lf1efc22_001efd7e:\n"
        "movsbl (%ecx), %eax\n" /* line 111 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss (%edi, %edx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %ecx\n"
        "mulss %xmm0, %xmm0\n" /* line 112 */
        "addss %xmm0, %xmm2\n"
        "addl $1, %edx\n" /* line 109 */
        "cmpl %edx, %esi\n"
        "jne .Lf1efc22_001efd7e\n"
        "ucomiss %xmm2, %xmm3\n" /* line 114 */
        "jbe .Lf1efc22_001efd63\n"
        ".Lf1efc22_001efda5:\n"
        "movl %ebx, -0x54(%ebp)\n" /* i, id */
        "addl $1, %ebx\n" /* line 106 | i */
        "cmpl $0x40, %ebx\n" /* i */
        "jne .Lf1efc22_001efd72\n"
        ".Lf1efc22_001efdb0:\n"
        "testl %esi, %esi\n" /* line 121 */
        "jle .Lf1efc22_001efdde\n"
        "movl -0x54(%ebp), %ebx\n" /* id, i */
        "imull %esi, %ebx\n" /* i */
        "xorl %ecx, %ecx\n"
        ".Lf1efc22_001efdbc:\n"
        "leal (%edi, %ecx, 4), %edx\n" /* line 317 | qlsp */
        "movsbl high_lsp_cdbk(%ecx, %ebx), %eax\n" /* line 122 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss (%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 121 */
        "cmpl %ecx, %esi\n"
        "jne .Lf1efc22_001efdbc\n"
        /* } scope */
        ".Lf1efc22_001efdde:\n"
        "movl $6, 8(%esp)\n" /* line 344 */
        "movl -0x54(%ebp), %eax\n" /* id */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "testl %esi, %esi\n" /* line 346 | order */
        "jle .Lf1efc22_001efe16\n"
        "xorl %edx, %edx\n"
        "movl %edi, %eax\n" /* qlsp */
        ".Lf1efc22_001efe00:\n"
        "movss (%eax), %xmm0\n" /* line 347 */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 346 */
        "addl $4, %eax\n"
        "cmpl %edx, %esi\n" /* order */
        "jne .Lf1efc22_001efe00\n"
        ".Lf1efc22_001efe16:\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm4\n"
        "movl $0, -0x4c(%ebp)\n"
        "movl $high_lsp_cdbk2, %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf1efc22_001efe47\n"
        /* { scope 2 */
        ".Lf1efc22_001efe2d:\n"
        "movaps %xmm4, %xmm2\n" /* line 139 */
        "ucomiss %xmm2, %xmm3\n" /* line 144 */
        "ja .Lf1efc22_001efe7d\n"
        ".Lf1efc22_001efe35:\n"
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1efc22_001efe7d\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %ebx\n" /* line 136 | i */
        "cmpl $0x40, %ebx\n" /* i */
        "je .Lf1efc22_001efe88\n"
        ".Lf1efc22_001efe44:\n"
        "movaps %xmm2, %xmm3\n"
        ".Lf1efc22_001efe47:\n"
        "testl %esi, %esi\n" /* line 139 */
        "jle .Lf1efc22_001efe2d\n"
        "xorl %edx, %edx\n"
        "movaps %xmm4, %xmm2\n"
        ".Lf1efc22_001efe50:\n"
        "movsbl (%ecx), %eax\n" /* line 141 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss (%edi, %edx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %ecx\n"
        "mulss %xmm0, %xmm0\n" /* line 142 */
        "mulss -0x40(%ebp, %edx, 4), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $1, %edx\n" /* line 139 */
        "cmpl %edx, %esi\n"
        "jne .Lf1efc22_001efe50\n"
        "ucomiss %xmm2, %xmm3\n" /* line 144 */
        "jbe .Lf1efc22_001efe35\n"
        ".Lf1efc22_001efe7d:\n"
        "movl %ebx, -0x4c(%ebp)\n" /* i */
        "addl $1, %ebx\n" /* line 136 | i */
        "cmpl $0x40, %ebx\n" /* i */
        "jne .Lf1efc22_001efe44\n"
        ".Lf1efc22_001efe88:\n"
        "testl %esi, %esi\n" /* line 151 */
        "jle .Lf1efc22_001efeb6\n"
        "movl -0x4c(%ebp), %ebx\n" /* i */
        "imull %esi, %ebx\n" /* i */
        "xorl %ecx, %ecx\n"
        ".Lf1efc22_001efe94:\n"
        "leal (%edi, %ecx, 4), %edx\n" /* line 317 | qlsp */
        "movsbl high_lsp_cdbk2(%ecx, %ebx), %eax\n" /* line 152 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss (%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 151 */
        "cmpl %ecx, %esi\n"
        "jne .Lf1efc22_001efe94\n"
        /* } scope */
        ".Lf1efc22_001efeb6:\n"
        "movl $6, 8(%esp)\n" /* line 350 */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "testl %esi, %esi\n" /* line 356 | order */
        "jle .Lf1efc22_001eff1d\n"
        "xorl %edx, %edx\n"
        "movsd 0x307ee0, %xmm1\n" /* 0.0019531 */
        "movl %edi, %eax\n" /* qlsp */
        ".Lf1efc22_001efee0:\n"
        "cvtss2sd (%eax), %xmm0\n" /* line 357 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 356 */
        "addl $4, %eax\n"
        "cmpl %edx, %esi\n" /* order */
        "jne .Lf1efc22_001efee0\n"
        "xorl %ecx, %ecx\n"
        ".Lf1efc22_001efefc:\n"
        "leal (, %ecx, 4), %eax\n" /* line 317 */
        "leal (%edi, %eax), %edx\n" /* qlsp */
        "movl 8(%ebp), %ebx\n" /* line 361 | lsp, i */
        "movss (%ebx, %eax), %xmm0\n" /* i */
        "subss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 360 */
        "cmpl %ecx, %esi\n" /* order */
        "jne .Lf1efc22_001efefc\n"
        /* } scope */
        ".Lf1efc22_001eff1d:\n"
        "addl $0x5c, %esp\n" /* line 362 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 364 */
__attribute__((naked))
void lsp_unquant_high(spx_lsp_t *lsp, int order, SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 364 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* lsp */
        "movl 0xc(%ebp), %esi\n" /* order */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 368 | order */
        "jle .Lf1eff26_001eff67\n"
        "xorl %eax, %eax\n"
        "movsd 0x307ef8, %xmm2\n" /* 0.3125 */
        "movsd 0x307d00, %xmm1\n" /* 0.75 */
        ".Lf1eff26_001eff4b:\n"
        "cvtsi2sdl %eax, %xmm0\n" /* line 369 */
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edi, %eax, 4)\n" /* lsp */
        "addl $1, %eax\n" /* line 368 */
        "cmpl %eax, %esi\n" /* order */
        "jne .Lf1eff26_001eff4b\n"
        ".Lf1eff26_001eff67:\n"
        "movl $6, 4(%esp)\n" /* line 372 */
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "testl %esi, %esi\n" /* line 373 | order */
        "jle .Lf1eff26_001effbb\n"
        "imull %esi, %eax\n" /* order */
        "leal high_lsp_cdbk(%eax), %ecx\n"
        "xorl %ebx, %ebx\n"
        "movsd 0x307ed8, %xmm2\n" /* 0.0039062 */
        "movl %edi, %edx\n" /* lsp */
        ".Lf1eff26_001eff93:\n"
        "cvtss2sd (%edx), %xmm0\n" /* line 374 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ebx\n" /* line 373 */
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl %ebx, %esi\n" /* order */
        "jne .Lf1eff26_001eff93\n"
        ".Lf1eff26_001effbb:\n"
        "movl $6, 4(%esp)\n" /* line 377 */
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "testl %esi, %esi\n" /* line 378 | order */
        "jle .Lf1eff26_001f000f\n"
        "imull %esi, %eax\n" /* order */
        "leal high_lsp_cdbk2(%eax), %ecx\n"
        "xorl %ebx, %ebx\n"
        "movsd 0x307ee0, %xmm2\n" /* 0.0019531 */
        "movl %edi, %edx\n" /* lsp */
        ".Lf1eff26_001effe7:\n"
        "cvtss2sd (%edx), %xmm0\n" /* line 379 */
        "movsbl (%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ebx\n" /* line 378 */
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl %ebx, %esi\n" /* order */
        "jne .Lf1eff26_001effe7\n"
        /* } scope */
        ".Lf1eff26_001f000f:\n"
        "addl $0x1c, %esp\n" /* line 380 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 157 */
__attribute__((naked))
void lsp_quant_nb(spx_lsp_t *lsp, spx_lsp_t *qlsp, int order, SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 157 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 163 | order */
        "testl %eax, %eax\n"
        "jle .Lf1f0018_001f012e\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f0018_001f002e:\n"
        "leal (, %ecx, 4), %edx\n" /* line 157 */
        "movl 8(%ebp), %ebx\n" /* line 164 | lsp, i */
        "movl (%ebx, %edx), %eax\n" /* i */
        "movl 0xc(%ebp), %ebx\n" /* qlsp, i */
        "movl %eax, (%ebx, %edx)\n" /* i */
        "addl $1, %ecx\n" /* line 163 */
        "cmpl %ecx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f0018_001f002e\n"
        "movl 0x10(%ebp), %esi\n" /* order */
        "subl $1, %esi\n"
        "movss (%ebx), %xmm5\n" /* i */
        "leal 4(%ebx), %edi\n" /* i */
        "movsd 0x307ec0, %xmm3\n" /* 0.04 */
        "movsd 0x307ef0, %xmm4\n" /* 10.0 */
        /* { scope 2 */
        ".Lf1f0018_001f0066:\n"
        "movaps %xmm5, %xmm2\n" /* line 79 */
        "movl %edi, %eax\n"
        "movl %edi, %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %edx, %edx\n"
        "cmpl %ebx, %esi\n" /* line 82 | i */
        "je .Lf1f0018_001f00bf\n"
        ".Lf1f0018_001f0075:\n"
        "movss (%eax), %xmm0\n" /* line 85 */
        "subss -4(%eax), %xmm0\n"
        ".Lf1f0018_001f007e:\n"
        "minss %xmm2, %xmm0\n" /* line 86 */
        "cvtss2sd %xmm0, %xmm0\n" /* line 91 */
        "addsd %xmm3, %xmm0\n"
        "movapd %xmm4, %xmm1\n"
        "divsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%ebp, %edx)\n"
        "addl $1, %ebx\n" /* line 76 | i */
        "cmpl %ebx, 0x10(%ebp)\n" /* i, order */
        "jle .Lf1f0018_001f00d6\n"
        /* } scope */
        "addl $4, %ecx\n" /* line 163 */
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 78 | i */
        "je .Lf1f0018_001f0066\n"
        "movss -4(%ecx), %xmm2\n" /* line 81 */
        "subss -8(%ecx), %xmm2\n"
        "cmpl %ebx, %esi\n" /* line 82 | i */
        "jne .Lf1f0018_001f0075\n"
        ".Lf1f0018_001f00bf:\n"
        "cvtss2sd -4(%eax), %xmm1\n" /* line 83 */
        "movsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "subsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "jmp .Lf1f0018_001f007e\n"
        ".Lf1f0018_001f00d6:\n"
        "xorl %edx, %edx\n" /* line 76 */
        "movsd 0x307ed0, %xmm2\n" /* 0.25 */
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        /* } scope */
        ".Lf1f0018_001f00e3:\n"
        "cvtss2sd (%eax), %xmm1\n" /* line 169 */
        "cvtsi2sdl %edx, %xmm0\n"
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm2, %xmm0\n"
        "subsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "addl $1, %edx\n" /* line 168 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f0018_001f00e3\n"
        "xorl %edx, %edx\n"
        "movss 0x2ed8b0, %xmm1\n" /* 256.0f */
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        ".Lf1f0018_001f0117:\n"
        "movss (%eax), %xmm0\n" /* line 173 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 172 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f0018_001f0117\n"
        ".Lf1f0018_001f012e:\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm3\n"
        "xorl %esi, %esi\n"
        "movl $cdbk_nb, %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf1f0018_001f015a\n"
        /* { scope 2 */
        ".Lf1f0018_001f0140:\n"
        "movaps %xmm4, %xmm2\n" /* line 109 */
        "ucomiss %xmm2, %xmm3\n" /* line 114 */
        "ja .Lf1f0018_001f0191\n"
        ".Lf1f0018_001f0148:\n"
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1f0018_001f0191\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %ebx\n" /* line 106 | i */
        "cmpl $0x40, %ebx\n" /* i */
        "je .Lf1f0018_001f019b\n"
        ".Lf1f0018_001f0157:\n"
        "movaps %xmm2, %xmm3\n"
        ".Lf1f0018_001f015a:\n"
        "movl 0x10(%ebp), %edi\n" /* line 109 | order */
        "testl %edi, %edi\n"
        "jle .Lf1f0018_001f0140\n"
        "xorl %edx, %edx\n"
        "movaps %xmm4, %xmm2\n"
        ".Lf1f0018_001f0166:\n"
        "movsbl (%ecx), %eax\n" /* line 111 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        "movss (%eax, %edx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %ecx\n"
        "mulss %xmm0, %xmm0\n" /* line 112 */
        "addss %xmm0, %xmm2\n"
        "addl $1, %edx\n" /* line 109 */
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f0018_001f0166\n"
        "ucomiss %xmm2, %xmm3\n" /* line 114 */
        "jbe .Lf1f0018_001f0148\n"
        ".Lf1f0018_001f0191:\n"
        "movl %ebx, %esi\n" /* i */
        "addl $1, %ebx\n" /* line 106 | i */
        "cmpl $0x40, %ebx\n" /* i */
        "jne .Lf1f0018_001f0157\n"
        ".Lf1f0018_001f019b:\n"
        "movl 0x10(%ebp), %eax\n" /* line 121 | order */
        "testl %eax, %eax\n"
        "jle .Lf1f0018_001f01d0\n"
        "movl 0x10(%ebp), %ebx\n" /* order, i */
        "imull %esi, %ebx\n" /* i */
        "xorl %ecx, %ecx\n"
        ".Lf1f0018_001f01aa:\n"
        "movl 0xc(%ebp), %eax\n" /* line 157 | qlsp */
        "leal (%eax, %ecx, 4), %edx\n"
        "movsbl cdbk_nb(%ecx, %ebx), %eax\n" /* line 122 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss (%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 121 */
        "cmpl %ecx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f0018_001f01aa\n"
        /* } scope */
        ".Lf1f0018_001f01d0:\n"
        "movl $6, 8(%esp)\n" /* line 176 */
        "movl %esi, 4(%esp)\n"
        "movl 0x14(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "movl 0x10(%ebp), %ecx\n" /* line 178 | order */
        "testl %ecx, %ecx\n"
        "jle .Lf1f0018_001f020a\n"
        "xorl %edx, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        ".Lf1f0018_001f01f3:\n"
        "movss (%eax), %xmm0\n" /* line 179 */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 178 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f0018_001f01f3\n"
        ".Lf1f0018_001f020a:\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm3\n"
        "xorl %edi, %edi\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $cdbk_nb_low1, %esi\n"
        ".Lf1f0018_001f021a:\n"
        "movl %esi, %edx\n"
        "movaps %xmm4, %xmm2\n"
        "movl $1, %ecx\n"
        /* { scope 2 */
        ".Lf1f0018_001f0224:\n"
        "movsbl (%edx), %eax\n" /* line 141 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        "movss -4(%eax, %ecx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %edx\n"
        "mulss %xmm0, %xmm0\n" /* line 142 */
        "mulss -0x44(%ebp, %ecx, 4), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $1, %ecx\n"
        "cmpl $6, %ecx\n" /* line 139 */
        "jne .Lf1f0018_001f0224\n"
        "ucomiss %xmm2, %xmm3\n" /* line 144 */
        "ja .Lf1f0018_001f033e\n"
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1f0018_001f033e\n"
        "addl $1, %ebx\n" /* line 136 | i */
        "addl $5, %esi\n"
        "cmpl $0x40, %ebx\n" /* i */
        "jne .Lf1f0018_001f021a\n"
        ".Lf1f0018_001f026d:\n"
        "leal (%edi, %edi, 4), %ebx\n" /* i */
        "movl $1, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* qlsp */
        "addl $4, %edx\n"
        ".Lf1f0018_001f027b:\n"
        "movsbl 0x305c5f(%ebx, %ecx), %eax\n" /* line 152 | i */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $6, %ecx\n" /* line 151 */
        "jne .Lf1f0018_001f027b\n"
        /* } scope */
        "movl $6, 8(%esp)\n" /* line 182 */
        "movl %edi, 4(%esp)\n"
        "movl 0x14(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "movl $1, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        "addl $4, %eax\n"
        ".Lf1f0018_001f02c2:\n"
        "movss -4(%eax), %xmm0\n" /* line 185 */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%eax)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $6, %edx\n" /* line 184 */
        "jne .Lf1f0018_001f02c2\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm3\n"
        "xorl %edi, %edi\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $cdbk_nb_low2, %esi\n"
        ".Lf1f0018_001f02eb:\n"
        "movl %esi, %edx\n"
        "movaps %xmm4, %xmm2\n"
        "movl $1, %ecx\n"
        /* { scope 2 */
        ".Lf1f0018_001f02f5:\n"
        "movsbl (%edx), %eax\n" /* line 141 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        "movss -4(%eax, %ecx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %edx\n"
        "mulss %xmm0, %xmm0\n" /* line 142 */
        "mulss -0x44(%ebp, %ecx, 4), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $1, %ecx\n"
        "cmpl $6, %ecx\n" /* line 139 */
        "jne .Lf1f0018_001f02f5\n"
        "ucomiss %xmm2, %xmm3\n" /* line 144 */
        "ja .Lf1f0018_001f0357\n"
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1f0018_001f0357\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %ebx\n" /* line 136 | i */
        "addl $5, %esi\n"
        "cmpl $0x40, %ebx\n" /* i */
        "je .Lf1f0018_001f0364\n"
        ".Lf1f0018_001f0339:\n"
        "movaps %xmm2, %xmm3\n"
        "jmp .Lf1f0018_001f02eb\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1f0018_001f033e:\n"
        "movaps %xmm2, %xmm3\n" /* line 144 */
        "movl %ebx, %edi\n" /* i */
        "addl $1, %ebx\n" /* line 136 | i */
        "addl $5, %esi\n"
        "cmpl $0x40, %ebx\n" /* i */
        "jne .Lf1f0018_001f021a\n"
        "jmp .Lf1f0018_001f026d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1f0018_001f0357:\n"
        "movl %ebx, %edi\n" /* line 144 | i */
        "addl $1, %ebx\n" /* line 136 | i */
        "addl $5, %esi\n"
        "cmpl $0x40, %ebx\n" /* i */
        "jne .Lf1f0018_001f0339\n"
        ".Lf1f0018_001f0364:\n"
        "leal (%edi, %edi, 4), %ebx\n" /* i */
        "movl $1, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* qlsp */
        "addl $4, %edx\n"
        ".Lf1f0018_001f0372:\n"
        "movsbl 0x305b1f(%ecx, %ebx), %eax\n" /* line 152 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $6, %ecx\n" /* line 151 */
        "jne .Lf1f0018_001f0372\n"
        /* } scope */
        "movl $6, 8(%esp)\n" /* line 188 */
        "movl %edi, 4(%esp)\n"
        "movl 0x14(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "movl 0xc(%ebp), %esi\n" /* line 190 | qlsp, x */
        "addl $0x14, %esi\n" /* x */
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm3\n"
        "movl $0, -0x4c(%ebp)\n"
        "xorl %edi, %edi\n"
        "movl $cdbk_nb_high1, -0x50(%ebp)\n"
        ".Lf1f0018_001f03cb:\n"
        "movl -0x50(%ebp), %ecx\n"
        "movaps %xmm4, %xmm2\n"
        "movl $1, %ebx\n" /* i */
        "leal -0x40(%ebp), %edx\n" /* quant_weight */
        "addl $0x14, %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1f0018_001f03dc:\n"
        "movsbl (%ecx), %eax\n" /* line 141 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%esi, %ebx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %ecx\n"
        "mulss %xmm0, %xmm0\n" /* line 142 */
        "mulss (%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $1, %ebx\n" /* i */
        "addl $4, %edx\n"
        "cmpl $6, %ebx\n" /* line 139 | i */
        "jne .Lf1f0018_001f03dc\n"
        "ucomiss %xmm2, %xmm3\n" /* line 144 */
        "ja .Lf1f0018_001f0424\n"
        "testl %edi, %edi\n"
        "je .Lf1f0018_001f0424\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %edi\n" /* line 136 */
        "addl $5, -0x50(%ebp)\n"
        "cmpl $0x40, %edi\n"
        "je .Lf1f0018_001f0433\n"
        ".Lf1f0018_001f041f:\n"
        "movaps %xmm2, %xmm3\n"
        "jmp .Lf1f0018_001f03cb\n"
        ".Lf1f0018_001f0424:\n"
        "movl %edi, -0x4c(%ebp)\n" /* line 144 */
        "addl $1, %edi\n" /* line 136 */
        "addl $5, -0x50(%ebp)\n"
        "cmpl $0x40, %edi\n"
        "jne .Lf1f0018_001f041f\n"
        ".Lf1f0018_001f0433:\n"
        "movl -0x4c(%ebp), %eax\n"
        "leal (%eax, %eax, 4), %ebx\n" /* i */
        "movl $1, %ecx\n"
        "leal 4(%esi), %edx\n"
        ".Lf1f0018_001f0441:\n"
        "movsbl 0x3059df(%ecx, %ebx), %eax\n" /* line 152 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $6, %ecx\n" /* line 151 */
        "jne .Lf1f0018_001f0441\n"
        /* } scope */
        /* } scope */
        "movl $6, 8(%esp)\n" /* line 191 */
        "movl -0x4c(%ebp), %ebx\n" /* i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 0x14(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        "xorl %edx, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        ".Lf1f0018_001f0485:\n"
        "movss 0x14(%eax), %xmm0\n" /* line 194 */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, 0x14(%eax)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $5, %edx\n" /* line 193 */
        "jne .Lf1f0018_001f0485\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm4\n"
        "movl $0, -0x58(%ebp)\n" /* id */
        "xorl %edi, %edi\n"
        "movl $cdbk_nb_high2, -0x54(%ebp)\n"
        ".Lf1f0018_001f04b5:\n"
        "movl -0x54(%ebp), %ecx\n"
        "movaps %xmm4, %xmm2\n"
        "movl $1, %ebx\n" /* i */
        "leal -0x40(%ebp), %edx\n" /* quant_weight */
        "addl $0x14, %edx\n"
        /* { scope 2 */
        ".Lf1f0018_001f04c6:\n"
        "movsbl (%ecx), %eax\n" /* line 141 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%esi, %ebx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %ecx\n"
        "mulss %xmm0, %xmm0\n" /* line 142 */
        "mulss (%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $1, %ebx\n" /* i */
        "addl $4, %edx\n"
        "cmpl $6, %ebx\n" /* line 139 | i */
        "jne .Lf1f0018_001f04c6\n"
        "ucomiss %xmm2, %xmm3\n" /* line 144 */
        "ja .Lf1f0018_001f050e\n"
        "testl %edi, %edi\n"
        "je .Lf1f0018_001f050e\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %edi\n" /* line 136 */
        "addl $5, -0x54(%ebp)\n"
        "cmpl $0x40, %edi\n"
        "je .Lf1f0018_001f051d\n"
        ".Lf1f0018_001f0509:\n"
        "movaps %xmm2, %xmm3\n"
        "jmp .Lf1f0018_001f04b5\n"
        ".Lf1f0018_001f050e:\n"
        "movl %edi, -0x58(%ebp)\n" /* line 144 | id */
        "addl $1, %edi\n" /* line 136 */
        "addl $5, -0x54(%ebp)\n"
        "cmpl $0x40, %edi\n"
        "jne .Lf1f0018_001f0509\n"
        ".Lf1f0018_001f051d:\n"
        "movl -0x58(%ebp), %eax\n" /* id */
        "leal (%eax, %eax, 4), %ebx\n" /* i */
        "movl $1, %ecx\n"
        "leal 4(%esi), %edx\n"
        ".Lf1f0018_001f052b:\n"
        "movsbl 0x30589f(%ecx, %ebx), %eax\n" /* line 152 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $6, %ecx\n" /* line 151 */
        "jne .Lf1f0018_001f052b\n"
        /* } scope */
        "movl $6, 8(%esp)\n" /* line 197 */
        "movl -0x58(%ebp), %ebx\n" /* id, i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 0x14(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        "movl 0x10(%ebp), %edx\n" /* line 203 | order */
        "testl %edx, %edx\n"
        "jle .Lf1f0018_001f05bf\n"
        "xorl %edx, %edx\n"
        "movsd 0x307ee8, %xmm1\n" /* 0.00097656 */
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        ".Lf1f0018_001f057e:\n"
        "cvtss2sd (%eax), %xmm0\n" /* line 204 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 203 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f0018_001f057e\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f0018_001f059b:\n"
        "leal (, %ecx, 4), %eax\n" /* line 157 */
        "movl 0xc(%ebp), %edx\n" /* qlsp */
        "addl %eax, %edx\n"
        "movl 8(%ebp), %ebx\n" /* line 208 | lsp, i */
        "movss (%ebx, %eax), %xmm0\n" /* i */
        "subss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 207 */
        "cmpl %ecx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f0018_001f059b\n"
        /* } scope */
        ".Lf1f0018_001f05bf:\n"
        "addl $0x5c, %esp\n" /* line 209 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 240 */
__attribute__((naked))
void lsp_quant_lbr(spx_lsp_t *lsp, spx_lsp_t *qlsp, int order, SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 240 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 246 | order */
        "testl %eax, %eax\n"
        "jle .Lf1f05c8_001f06de\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f05c8_001f05de:\n"
        "leal (, %ecx, 4), %edx\n" /* line 240 */
        "movl 8(%ebp), %ebx\n" /* line 247 | lsp, i */
        "movl (%ebx, %edx), %eax\n" /* i */
        "movl 0xc(%ebp), %ebx\n" /* qlsp, i */
        "movl %eax, (%ebx, %edx)\n" /* i */
        "addl $1, %ecx\n" /* line 246 */
        "cmpl %ecx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f05c8_001f05de\n"
        "movl 0x10(%ebp), %esi\n" /* order, id */
        "subl $1, %esi\n" /* id */
        "movss (%ebx), %xmm5\n" /* i */
        "leal 4(%ebx), %edi\n" /* i */
        "movsd 0x307ec0, %xmm3\n" /* 0.04 */
        "movsd 0x307ef0, %xmm4\n" /* 10.0 */
        /* { scope 2 */
        ".Lf1f05c8_001f0616:\n"
        "movaps %xmm5, %xmm2\n" /* line 79 */
        "movl %edi, %eax\n"
        "movl %edi, %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %edx, %edx\n"
        "cmpl %ebx, %esi\n" /* line 82 | i */
        "je .Lf1f05c8_001f066f\n"
        ".Lf1f05c8_001f0625:\n"
        "movss (%eax), %xmm0\n" /* line 85 */
        "subss -4(%eax), %xmm0\n"
        ".Lf1f05c8_001f062e:\n"
        "minss %xmm2, %xmm0\n" /* line 86 */
        "cvtss2sd %xmm0, %xmm0\n" /* line 91 */
        "addsd %xmm3, %xmm0\n"
        "movapd %xmm4, %xmm1\n"
        "divsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%ebp, %edx)\n"
        "addl $1, %ebx\n" /* line 76 | i */
        "cmpl %ebx, 0x10(%ebp)\n" /* i, order */
        "jle .Lf1f05c8_001f0686\n"
        /* } scope */
        "addl $4, %ecx\n" /* line 246 */
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 78 | i */
        "je .Lf1f05c8_001f0616\n"
        "movss -4(%ecx), %xmm2\n" /* line 81 */
        "subss -8(%ecx), %xmm2\n"
        "cmpl %ebx, %esi\n" /* line 82 | i */
        "jne .Lf1f05c8_001f0625\n"
        ".Lf1f05c8_001f066f:\n"
        "cvtss2sd -4(%eax), %xmm1\n" /* line 83 */
        "movsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "subsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "jmp .Lf1f05c8_001f062e\n"
        ".Lf1f05c8_001f0686:\n"
        "xorl %edx, %edx\n" /* line 76 */
        "movsd 0x307ed0, %xmm2\n" /* 0.25 */
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        /* } scope */
        ".Lf1f05c8_001f0693:\n"
        "cvtss2sd (%eax), %xmm1\n" /* line 252 */
        "cvtsi2sdl %edx, %xmm0\n"
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm2, %xmm0\n"
        "subsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "addl $1, %edx\n" /* line 251 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f05c8_001f0693\n"
        "xorl %edx, %edx\n"
        "movss 0x2ed8b0, %xmm1\n" /* 256.0f */
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        ".Lf1f05c8_001f06c7:\n"
        "movss (%eax), %xmm0\n" /* line 255 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 254 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f05c8_001f06c7\n"
        ".Lf1f05c8_001f06de:\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm3\n"
        "xorl %esi, %esi\n" /* id */
        "movl $cdbk_nb, %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf1f05c8_001f070a\n"
        /* { scope 2 */
        ".Lf1f05c8_001f06f0:\n"
        "movaps %xmm4, %xmm2\n" /* line 109 */
        "ucomiss %xmm2, %xmm3\n" /* line 114 */
        "ja .Lf1f05c8_001f0741\n"
        ".Lf1f05c8_001f06f8:\n"
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1f05c8_001f0741\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %ebx\n" /* line 106 | i */
        "cmpl $0x40, %ebx\n" /* i */
        "je .Lf1f05c8_001f074b\n"
        ".Lf1f05c8_001f0707:\n"
        "movaps %xmm2, %xmm3\n"
        ".Lf1f05c8_001f070a:\n"
        "movl 0x10(%ebp), %eax\n" /* line 109 | order */
        "testl %eax, %eax\n"
        "jle .Lf1f05c8_001f06f0\n"
        "xorl %edx, %edx\n"
        "movaps %xmm4, %xmm2\n"
        ".Lf1f05c8_001f0716:\n"
        "movsbl (%ecx), %eax\n" /* line 111 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        "movss (%eax, %edx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %ecx\n"
        "mulss %xmm0, %xmm0\n" /* line 112 */
        "addss %xmm0, %xmm2\n"
        "addl $1, %edx\n" /* line 109 */
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f05c8_001f0716\n"
        "ucomiss %xmm2, %xmm3\n" /* line 114 */
        "jbe .Lf1f05c8_001f06f8\n"
        ".Lf1f05c8_001f0741:\n"
        "movl %ebx, %esi\n" /* i */
        "addl $1, %ebx\n" /* line 106 | i */
        "cmpl $0x40, %ebx\n" /* i */
        "jne .Lf1f05c8_001f0707\n"
        ".Lf1f05c8_001f074b:\n"
        "movl 0x10(%ebp), %eax\n" /* line 121 | order */
        "testl %eax, %eax\n"
        "jle .Lf1f05c8_001f0780\n"
        "movl 0x10(%ebp), %ebx\n" /* order, i */
        "imull %esi, %ebx\n" /* i */
        "xorl %ecx, %ecx\n"
        ".Lf1f05c8_001f075a:\n"
        "movl 0xc(%ebp), %eax\n" /* line 240 | qlsp */
        "leal (%eax, %ecx, 4), %edx\n"
        "movsbl cdbk_nb(%ecx, %ebx), %eax\n" /* line 122 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss (%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 121 */
        "cmpl %ecx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f05c8_001f075a\n"
        /* } scope */
        ".Lf1f05c8_001f0780:\n"
        "movl $6, 8(%esp)\n" /* line 258 */
        "movl %esi, 4(%esp)\n" /* id */
        "movl 0x14(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "movl 0x10(%ebp), %eax\n" /* line 260 | order */
        "testl %eax, %eax\n"
        "jle .Lf1f05c8_001f07ba\n"
        "xorl %edx, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        ".Lf1f05c8_001f07a3:\n"
        "movss (%eax), %xmm0\n" /* line 261 */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 260 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f05c8_001f07a3\n"
        ".Lf1f05c8_001f07ba:\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm3\n"
        "xorl %edi, %edi\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $cdbk_nb_low1, %esi\n" /* id */
        ".Lf1f05c8_001f07ca:\n"
        "movl %esi, %edx\n" /* id */
        "movaps %xmm4, %xmm2\n"
        "movl $1, %ecx\n"
        /* { scope 2 */
        ".Lf1f05c8_001f07d4:\n"
        "movsbl (%edx), %eax\n" /* line 141 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        "movss -4(%eax, %ecx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %edx\n"
        "mulss %xmm0, %xmm0\n" /* line 142 */
        "mulss -0x44(%ebp, %ecx, 4), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $1, %ecx\n"
        "cmpl $6, %ecx\n" /* line 139 */
        "jne .Lf1f05c8_001f07d4\n"
        "ucomiss %xmm2, %xmm3\n" /* line 144 */
        "ja .Lf1f05c8_001f081d\n"
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1f05c8_001f081d\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %ebx\n" /* line 136 | i */
        "addl $5, %esi\n"
        "cmpl $0x40, %ebx\n" /* i */
        "je .Lf1f05c8_001f082a\n"
        ".Lf1f05c8_001f0818:\n"
        "movaps %xmm2, %xmm3\n"
        "jmp .Lf1f05c8_001f07ca\n"
        ".Lf1f05c8_001f081d:\n"
        "movl %ebx, %edi\n" /* line 144 | i */
        "addl $1, %ebx\n" /* line 136 | i */
        "addl $5, %esi\n"
        "cmpl $0x40, %ebx\n" /* i */
        "jne .Lf1f05c8_001f0818\n"
        ".Lf1f05c8_001f082a:\n"
        "leal (%edi, %edi, 4), %ebx\n" /* i */
        "movl $1, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* qlsp */
        "addl $4, %edx\n"
        ".Lf1f05c8_001f0838:\n"
        "movsbl 0x305c5f(%ebx, %ecx), %eax\n" /* line 152 | i */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $6, %ecx\n" /* line 151 */
        "jne .Lf1f05c8_001f0838\n"
        /* } scope */
        "movl $6, 8(%esp)\n" /* line 264 */
        "movl %edi, 4(%esp)\n"
        "movl 0x14(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "movl 0xc(%ebp), %edi\n" /* line 266 | qlsp, x */
        "addl $0x14, %edi\n" /* x */
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm4\n"
        "movl $0, -0x4c(%ebp)\n"
        "xorl %esi, %esi\n" /* id */
        "movl $cdbk_nb_high1, -0x50(%ebp)\n"
        ".Lf1f05c8_001f0891:\n"
        "movl -0x50(%ebp), %ecx\n"
        "movaps %xmm4, %xmm2\n"
        "movl $1, %ebx\n" /* i */
        "leal -0x40(%ebp), %edx\n" /* quant_weight */
        "addl $0x14, %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1f05c8_001f08a2:\n"
        "movsbl (%ecx), %eax\n" /* line 141 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%edi, %ebx, 4), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addl $1, %ecx\n"
        "mulss %xmm0, %xmm0\n" /* line 142 */
        "mulss (%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $1, %ebx\n" /* i */
        "addl $4, %edx\n"
        "cmpl $6, %ebx\n" /* line 139 | i */
        "jne .Lf1f05c8_001f08a2\n"
        "ucomiss %xmm2, %xmm3\n" /* line 144 */
        "ja .Lf1f05c8_001f08ea\n"
        "testl %esi, %esi\n"
        "je .Lf1f05c8_001f08ea\n"
        "movaps %xmm3, %xmm2\n"
        "addl $1, %esi\n" /* line 136 */
        "addl $5, -0x50(%ebp)\n"
        "cmpl $0x40, %esi\n"
        "je .Lf1f05c8_001f08f9\n"
        ".Lf1f05c8_001f08e5:\n"
        "movaps %xmm2, %xmm3\n"
        "jmp .Lf1f05c8_001f0891\n"
        ".Lf1f05c8_001f08ea:\n"
        "movl %esi, -0x4c(%ebp)\n" /* line 144 */
        "addl $1, %esi\n" /* line 136 */
        "addl $5, -0x50(%ebp)\n"
        "cmpl $0x40, %esi\n"
        "jne .Lf1f05c8_001f08e5\n"
        ".Lf1f05c8_001f08f9:\n"
        "movl -0x4c(%ebp), %eax\n"
        "leal (%eax, %eax, 4), %ebx\n" /* i */
        "movl $1, %ecx\n"
        "leal 4(%edi), %edx\n"
        ".Lf1f05c8_001f0907:\n"
        "movsbl 0x3059df(%ecx, %ebx), %eax\n" /* line 152 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $6, %ecx\n" /* line 151 */
        "jne .Lf1f05c8_001f0907\n"
        /* } scope */
        /* } scope */
        "movl $6, 8(%esp)\n" /* line 267 */
        "movl -0x4c(%ebp), %ebx\n" /* i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 0x14(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        "movl 0x10(%ebp), %eax\n" /* line 273 | order */
        "testl %eax, %eax\n"
        "jle .Lf1f05c8_001f099b\n"
        "xorl %edx, %edx\n"
        "movsd 0x307ee0, %xmm1\n" /* 0.0019531 */
        "movl 0xc(%ebp), %eax\n" /* qlsp */
        ".Lf1f05c8_001f095a:\n"
        "cvtss2sd (%eax), %xmm0\n" /* line 274 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 273 */
        "addl $4, %eax\n"
        "cmpl %edx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f05c8_001f095a\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f05c8_001f0977:\n"
        "leal (, %ecx, 4), %eax\n" /* line 240 */
        "movl 0xc(%ebp), %edx\n" /* qlsp */
        "addl %eax, %edx\n"
        "movl 8(%ebp), %ebx\n" /* line 278 | lsp, i */
        "movss (%ebx, %eax), %xmm0\n" /* i */
        "subss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ecx\n" /* line 277 */
        "cmpl %ecx, 0x10(%ebp)\n" /* order */
        "jne .Lf1f05c8_001f0977\n"
        /* } scope */
        ".Lf1f05c8_001f099b:\n"
        "addl $0x5c, %esp\n" /* line 279 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

