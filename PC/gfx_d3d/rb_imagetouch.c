/* ASM dump from: rb_imagetouch.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_imagetouch.cpp */

#include "common_types.h"
#include "imports.h"

static int RB_CompareTouchImages(const int *e0, const int *e1);
int RB_TouchAllImages(void);

/* line 25 */
static __attribute__((naked))
int RB_CompareTouchImages(const int *e0, const int *e1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 30 | e0 */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* line 31 | e1 */
        "movl (%eax), %eax\n"
        "movzbl 0xa(%eax), %ebx\n" /* line 33 */
        "testb %bl, %bl\n"
        "je .Lf111bac_00111beb\n"
        "movzbl 0xa(%edx), %ecx\n" /* line 35 */
        "testb %cl, %cl\n"
        "je .Lf111bac_00111be1\n"
        "movl 0x10(%eax), %eax\n" /* line 38 */
        "subl 0x10(%edx), %eax\n" /* line 39 */
        "movl %eax, %edx\n"
        "jne .Lf111bac_00111bdc\n"
        "movzbl %cl, %edx\n" /* line 42 */
        "movzbl %bl, %eax\n"
        "subl %eax, %edx\n"
        /* } scope */
        ".Lf111bac_00111bdc:\n"
        "movl %edx, %eax\n" /* line 47 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf111bac_00111be1:\n"
        "movl $1, %edx\n" /* line 35 */
        /* } scope */
        "movl %edx, %eax\n" /* line 47 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf111bac_00111beb:\n"
        "movl $0xffffffff, %edx\n" /* line 33 */
        /* } scope */
        "movl %edx, %eax\n" /* line 47 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 50 */
__attribute__((naked))
int RB_TouchAllImages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 50 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x2044, %esp\n"
        /* { scope 1 */
        "leal -0x200c(%ebp), %eax\n" /* line 56 | imageList */
        "movl %eax, (%esp)\n"
        "calll R_GetImageList\n"
        "movl $RB_CompareTouchImages, 0xc(%esp)\n" /* line 57 */
        "movl $4, 8(%esp)\n"
        "movl -0x200c(%ebp), %eax\n" /* imageList */
        "movl %eax, 4(%esp)\n"
        "leal -0x2008(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl -0x200c(%ebp), %eax\n" /* line 60 | imageList */
        "testl %eax, %eax\n"
        "jle .Lf111bf6_00111cdf\n"
        "movl -0x2008(%ebp), %edx\n"
        "cmpb $0, 0xa(%edx)\n"
        "je .Lf111bf6_00111cdf\n"
        "xorl %ebx, %ebx\n" /* imageIndex */
        "jmp .Lf111bf6_00111c70\n"
        ".Lf111bf6_00111c58:\n"
        "addl $1, %ebx\n" /* imageIndex */
        "cmpl %ebx, -0x200c(%ebp)\n" /* imageIndex, imageList */
        "jle .Lf111bf6_00111cdf\n"
        ".Lf111bf6_00111c63:\n"
        "movl -0x2008(%ebp, %ebx, 4), %edx\n"
        "cmpb $0, 0xa(%edx)\n"
        "je .Lf111bf6_00111cdf\n"
        ".Lf111bf6_00111c70:\n"
        "cmpl $3, (%edx)\n" /* line 10 */
        "jne .Lf111bf6_00111c58\n"
        "movl 0x195f0c8, %eax\n" /* line 13 */
        "movl %edx, 0x2e8c(%eax)\n"
        "movl $0xa, 0x28(%esp)\n" /* line 14 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %eax, 0x1c(%esp)\n"
        "xorl %edx, %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl $0x41000000, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x195eebc, %eax\n"
        "movl 0x10a8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 15 */
        "addl $1, %ebx\n" /* line 60 | imageIndex */
        "cmpl %ebx, -0x200c(%ebp)\n" /* imageIndex, imageList */
        "jg .Lf111bf6_00111c63\n"
        ".Lf111bf6_00111cdf:\n"
        "movl 0x195f0c8, %eax\n" /* line 66 */
        "movl $0, 0x2e8c(%eax)\n"
        /* } scope */
        "addl $0x2044, %esp\n" /* line 67 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

