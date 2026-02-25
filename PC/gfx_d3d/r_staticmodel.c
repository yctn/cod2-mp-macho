/* ASM dump from: r_staticmodel.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_staticmodel.cpp */

#include "common_types.h"
#include "imports.h"

long unsigned int R_InitStaticModelDynamicData(int smodelIndex);

/* line 43 */
__attribute__((naked))
long unsigned int R_InitStaticModelDynamicData(int smodelIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* smodelIndex */
        /* { scope 1: xmodel */
        "movl 0x195eec8, %edx\n" /* line 52 */
        "movl 0x3194(%edx), %edx\n"
        "leal (%edx, %eax, 8), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* smodelDync */
        "movl 0x195eebc, %edx\n"
        "movl 0x109c(%edx), %edx\n"
        "movl 0xf8(%edx), %edx\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl 0x10(%eax, %edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* xmodel */
        /* { scope 2: xsurfs, partBits */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 31 */
        "calll XModelGetNumLods\n"
        "movl %eax, %edi\n" /* lodCount */
        "testl %eax, %eax\n" /* line 32 */
        "jg .Lffc61e_000fc6a2\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lffc61e_000fc66b:\n"
        "movl %eax, %ebx\n" /* line 55 | instanceSize */
        "shll $4, %ebx\n" /* instanceSize */
        "movl $4, 4(%esp)\n" /* line 57 */
        "movl %ebx, (%esp)\n" /* instanceSize */
        "calll Hunk_AllocAlignInternal\n"
        "movl -0x30(%ebp), %edx\n" /* smodelDync */
        "movl %eax, 4(%edx)\n"
        "movl %ebx, 8(%esp)\n" /* line 58 | instanceSize */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 60 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xmodel */
        /* { scope 2: xsurfs, partBits */
        /* { scope 3 */
        ".Lffc61e_000fc6a2:\n"
        "xorl %ebx, %ebx\n" /* line 32 | lodIndex */
        "xorl %esi, %esi\n"
        ".Lffc61e_000fc6a6:\n"
        "leal -0x20(%ebp), %eax\n" /* line 34 | partBits */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* lodIndex */
        "leal -0x1c(%ebp), %edx\n" /* xsurfs */
        "movl %edx, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* xmodel */
        "movl %eax, (%esp)\n"
        "calll XModelGetSurfaces\n"
        "cmpl %esi, %eax\n" /* line 35 */
        "cmovgl %eax, %esi\n"
        "addl $1, %ebx\n" /* line 32 | lodIndex */
        "cmpl %ebx, %edi\n" /* lodIndex, lodCount */
        "jne .Lffc61e_000fc6a6\n"
        "movl %esi, %eax\n"
        "jmp .Lffc61e_000fc66b\n"
    );
}

