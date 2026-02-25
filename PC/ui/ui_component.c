/* ASM dump from: ui_component.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui/ui_component.cpp */

#include "common_types.h"
#include "imports.h"

extern UI_Component_data_t UI_Component_g; /* 0x0 */

inflate_huft UI_Component_Init(void);

/* line 31 */
__attribute__((naked))
inflate_huft UI_Component_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 31 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195ecac, %ebx\n" /* line 33 */
        "movl 0x110(%ebx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1b3326_001b3343\n"
        ".Lf1b3326_001b333d:\n"
        "addl $0x14, %esp\n" /* line 37 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b3326_001b3343:\n"
        "movl $0xac, 8(%esp)\n" /* line 48 */
        "movl $0, 4(%esp)\n"
        "movl $__ZN12UI_Component1gE, (%esp)\n"
        "calll memset\n"
        "cvtsi2ssl 0x2a0a64(%ebx), %xmm0\n" /* line 50 */
        "movss %xmm0, __ZN12UI_Component1gE\n"
        "cvtsi2ssl 0x2a0a68(%ebx), %xmm0\n" /* line 51 */
        "movss %xmm0, 0x195af24\n"
        "movl $0x41000000, 0x195af28\n" /* line 53 */
        "movl $0x41800000, %eax\n" /* line 54 */
        "movl %eax, 0x195af2c\n"
        "movl %eax, 0x195af30\n" /* line 56 */
        "movl 0x195ecc0, %eax\n" /* line 62 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1b3326_001b333d\n"
        "movl 0x195eca8, %ebx\n" /* line 80 */
        "movl $1, 8(%esp)\n"
        "movl $0x30, 4(%esp)\n"
        "movl $0x2b5218, (%esp)\n" /* "ui/assets/3_cursor3" */
        "calll *0x10(%ebx)\n"
        "movl %eax, 0x195af34\n" /* line 66 */
        "movl $1, 8(%esp)\n" /* line 80 */
        "movl $0x30, 4(%esp)\n"
        "movl $0x2a9f80, (%esp)\n" /* "ui/assets/sliderbutt_1" */
        "calll *0x10(%ebx)\n"
        "movl %eax, 0x195af44\n" /* line 68 */
        "addl $0x14, %esp\n" /* line 37 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

