/* ASM dump from: r_specularityimage.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_specularityimage.cpp */

#include "common_types.h"
#include "imports.h"

void Image_BuildSpecularityMap(float shift, byte *pic);

/* line 5 */
__attribute__((naked))
void Image_BuildSpecularityMap(float shift, byte *pic)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "xorl %edi, %edi\n"
        /* { scope 1 */
        ".Lf10a7d0_0010a7db:\n"
        "cvtsi2ssl %edi, %xmm0\n" /* line 24 | power */
        "divss 0x2ed7b4, %xmm0\n" /* 30.0f */
        "addss 8(%ebp), %xmm0\n" /* shift */
        "cvtss2sd %xmm0, %xmm0\n"
        "pxor %xmm1, %xmm1\n" /* line 25 */
        "ucomisd %xmm0, %xmm1\n"
        "ja .Lf10a7d0_0010a908\n"
        "ucomisd 0x307c10, %xmm0\n" /* 1.0 */
        "jbe .Lf10a7d0_0010a8f3\n"
        "movsd 0x307d30, %xmm0\n" /* -175.0 */
        ".Lf10a7d0_0010a814:\n"
        "movl $0xa0000000, (%esp)\n" /* line 27 */
        "movl $0x3fb99999, 4(%esp)\n"
        "movsd %xmm0, -0x48(%ebp)\n"
        "calll log\n"
        "fstpl -0x20(%ebp)\n" /* exponent */
        "movsd -0x48(%ebp), %xmm0\n"
        "addsd 0x307c38, %xmm0\n" /* 180.0 */
        "mulsd 0x307d38, %xmm0\n" /* 0.004363323129985824 */
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl (%esp)\n"
        "calll log\n"
        "fstpl -0x28(%ebp)\n"
        "movsd -0x20(%ebp), %xmm0\n" /* exponent */
        "divsd -0x28(%ebp), %xmm0\n"
        "movsd %xmm0, -0x20(%ebp)\n" /* exponent */
        ".Lf10a7d0_0010a869:\n"
        "movl 0xc(%ebp), %ebx\n" /* pic */
        "addl %edi, %ebx\n" /* power */
        "xorl %esi, %esi\n" /* level */
        ".Lf10a7d0_0010a870:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 33 | level */
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movsd -0x20(%ebp), %xmm1\n" /* exponent */
        "movsd %xmm1, 8(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll pow\n"
        "fstpl -0x50(%ebp)\n"
        "movsd -0x50(%ebp), %xmm0\n"
        "mulsd 0x307d40, %xmm0\n" /* 255.0 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %eax\n"
        "movb %al, (%ebx)\n"
        "addl $1, %esi\n" /* line 30 | level */
        "addl $0x20, %ebx\n"
        "cmpl $0x100, %esi\n" /* level */
        "jne .Lf10a7d0_0010a870\n"
        "addl $1, %edi\n" /* line 16 | power */
        "cmpl $0x1f, %edi\n" /* power */
        "jg .Lf10a7d0_0010a900\n"
        "jne .Lf10a7d0_0010a7db\n" /* line 18 */
        "movsd 0x307d20, %xmm0\n" /* 30.0 */
        "movsd %xmm0, -0x20(%ebp)\n" /* exponent */
        "jmp .Lf10a7d0_0010a869\n"
        ".Lf10a7d0_0010a8f3:\n"
        "mulsd 0x307d30, %xmm0\n" /* line 25 | -175.0 */
        "jmp .Lf10a7d0_0010a814\n"
        /* } scope */
        ".Lf10a7d0_0010a900:\n"
        "addl $0x5c, %esp\n" /* line 41 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf10a7d0_0010a908:\n"
        "movsd 0x307d28, %xmm0\n" /* line 25 | 0.0 */
        "jmp .Lf10a7d0_0010a814\n"
    );
}

