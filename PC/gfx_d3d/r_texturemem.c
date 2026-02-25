/* ASM dump from: r_texturemem.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_texturemem.cpp */

#include "common_types.h"
#include "imports.h"

unsigned int R_AvailableTextureMemory(void);

/* line 145 */
__attribute__((naked))
unsigned int R_AvailableTextureMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 145 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "leal -0x20(%ebp), %eax\n" /* line 111 */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetVideoMemoryInfo\n"
        "movl -0x1c(%ebp), %esi\n" /* line 112 */
        "movl 0x195eed0, %eax\n" /* line 155 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0x10(%edx)\n"
        "movl %eax, %ebx\n" /* texMemInMegs */
        "shrl $0x14, %ebx\n" /* line 156 | texMemInMegs */
        "testl %esi, %esi\n" /* line 158 | vidMemInMegs */
        "jne .Lf10a918_0010a973\n"
        "movl %ebx, 8(%esp)\n" /* line 160 | texMemInMegs */
        "movl $0x228ba4, 4(%esp)\n" /* "DirectX reports %i MB of available texture memory, but would" */
        "movl $0, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        /* } scope */
        ".Lf10a918_0010a969:\n"
        "movl %ebx, %eax\n" /* line 172 | texMemInMegs */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf10a918_0010a973:\n"
        "movl 0x195eee0, %edi\n" /* line 164 */
        "movl %ebx, 0xc(%esp)\n" /* texMemInMegs */
        "movl %esi, 8(%esp)\n" /* vidMemInMegs */
        "movl $0x228c04, 4(%esp)\n" /* "DirectX reports %i MB of video memory and %i MB of available" */
        "movl $0, (%esp)\n"
        "calll *(%edi)\n"
        "cmpl %ebx, %esi\n" /* line 165 | texMemInMegs, vidMemInMegs */
        "jae .Lf10a918_0010a969\n"
        "leal -0x10(%esi), %ebx\n" /* line 167 | vidMemInMegs, texMemInMegs */
        "movl %ebx, 8(%esp)\n" /* texMemInMegs */
        "movl $0x228c54, 4(%esp)\n" /* "Using video memory size to cap used texture memory at %i MB." */
        "movl $0, (%esp)\n"
        "calll *(%edi)\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 172 | texMemInMegs */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

