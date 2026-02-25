/* ASM dump from: r_model_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_model_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

trXSkin_t * R_LoadXSkins(struct XModel *model);

/* line 9 */
__attribute__((naked))
trXSkin_t * R_LoadXSkins(struct XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 9 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 23 | model */
        "movl %eax, (%esp)\n"
        "calll XModelGetNumLods\n"
        "movl %eax, -0x74(%ebp)\n" /* lodCount */
        "testl %eax, %eax\n" /* line 25 */
        "jg .Lfd4830_000d4942\n"
        "xorl %eax, %eax\n"
        ".Lfd4830_000d4851:\n"
        "addl -0x74(%ebp), %eax\n" /* line 28 | lodCount */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Model_Alloc\n"
        "movl %eax, -0x78(%ebp)\n" /* skins */
        "movl -0x74(%ebp), %edx\n" /* line 29 | lodCount */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* materialHandles */
        "movl -0x74(%ebp), %edx\n" /* line 31 | lodCount */
        "testl %edx, %edx\n"
        "jg .Lfd4830_000d487a\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 50 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd4830_000d487a:\n"
        "movl %eax, %edi\n" /* line 31 */
        "movl $0, -0x6c(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n"
        "jmp .Lfd4830_000d489d\n"
        ".Lfd4830_000d4888:\n"
        "addl $1, -0x6c(%ebp)\n"
        "addl $4, %edi\n"
        "movl -0x6c(%ebp), %eax\n"
        "cmpl %eax, -0x74(%ebp)\n" /* lodCount */
        "je .Lfd4830_000d4937\n"
        ".Lfd4830_000d489b:\n"
        "movl %eax, %edx\n"
        ".Lfd4830_000d489d:\n"
        "leal -0x20(%ebp), %eax\n" /* line 33 | partBits */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* surfaces */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* model */
        "movl %edx, (%esp)\n"
        "calll XModelGetSurfaces\n"
        "movl %eax, %esi\n" /* totalNumSurfaces */
        "movl -0x70(%ebp), %eax\n" /* line 35 | materialHandles */
        "movl %eax, (%edi)\n"
        "leal (%eax, %esi, 4), %eax\n" /* line 36 */
        "movl %eax, -0x70(%ebp)\n" /* materialHandles */
        "testl %esi, %esi\n" /* line 38 | totalNumSurfaces */
        "jle .Lfd4830_000d4888\n"
        "xorl %ebx, %ebx\n" /* j */
        ".Lfd4830_000d48cd:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 40 */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* j */
        "movl 8(%ebp), %eax\n" /* model */
        "movl %eax, (%esp)\n"
        "calll XModelGetSurfaceName\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* materialName */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "leal -0x60(%ebp), %eax\n" /* line 43 | materialName */
        "movl %eax, (%esp)\n"
        "calll strlwr\n"
        "movl $8, 8(%esp)\n" /* line 44 */
        "movl $0, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* materialName */
        "movl %edx, (%esp)\n"
        "calll Material_RegisterHandle\n"
        "movl (%edi), %edx\n" /* line 45 */
        "movl %eax, (%edx, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 38 | j */
        "cmpl %ebx, %esi\n" /* j, totalNumSurfaces */
        "jne .Lfd4830_000d48cd\n"
        "addl $1, -0x6c(%ebp)\n" /* line 31 */
        "addl $4, %edi\n"
        "movl -0x6c(%ebp), %eax\n"
        "cmpl %eax, -0x74(%ebp)\n" /* lodCount */
        "jne .Lfd4830_000d489b\n"
        ".Lfd4830_000d4937:\n"
        "movl -0x78(%ebp), %eax\n" /* skins */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 50 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd4830_000d4942:\n"
        "xorl %ebx, %ebx\n" /* line 25 | j */
        "xorl %esi, %esi\n" /* totalNumSurfaces */
        ".Lfd4830_000d4946:\n"
        "leal -0x20(%ebp), %edx\n" /* line 26 | partBits */
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* j */
        "leal -0x1c(%ebp), %eax\n" /* surfaces */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* model */
        "movl %edx, (%esp)\n"
        "calll XModelGetSurfaces\n"
        "addl %eax, %esi\n" /* totalNumSurfaces */
        "addl $1, %ebx\n" /* line 25 | j */
        "cmpl %ebx, -0x74(%ebp)\n" /* j, lodCount */
        "jne .Lfd4830_000d4946\n"
        "movl %esi, %eax\n" /* totalNumSurfaces */
        "jmp .Lfd4830_000d4851\n"
    );
}

