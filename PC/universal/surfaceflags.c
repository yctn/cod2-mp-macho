/* ASM dump from: surfaceflags.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/surfaceflags.cpp */

#include "common_types.h"
#include "imports.h"

extern infoParm_t infoParms[53]; /* 0x0 */

int Com_SurfaceTypeFromName(const char *name);
const char * Com_SurfaceTypeToName(int iTypeIndex);

/* line 98 */
__attribute__((naked))
int Com_SurfaceTypeFromName(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 98 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "movl $0x220284, 4(%esp)\n" /* line 104 */
        "movl %edi, (%esp)\n" /* name */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfbd180_000bd1a8\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 114 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbd180_000bd1a8:\n"
        "xorl %esi, %esi\n" /* line 104 | i */
        "movl $infoParms, %ebx\n"
        "jmp .Lfbd180_000bd1bc\n"
        ".Lfbd180_000bd1b1:\n"
        "addl $1, %esi\n" /* line 107 | i */
        "addl $0x14, %ebx\n"
        "cmpl $0x16, %esi\n" /* i */
        "je .Lfbd180_000bd1e8\n"
        ".Lfbd180_000bd1bc:\n"
        "movl (%ebx), %eax\n" /* line 109 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* name */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfbd180_000bd1b1\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 110 | i */
        "movl 0x30f6a8(, %eax, 4), %eax\n"
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 114 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbd180_000bd1e8:\n"
        "movl $0xffffffff, %eax\n" /* line 107 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 114 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 124 */
__attribute__((naked))
const char * Com_SurfaceTypeToName(int iTypeIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 124 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 128 | iTypeIndex */
        "subl $1, %eax\n"
        "cmpl $0x15, %eax\n"
        "ja .Lfbd1f6_000bd210\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 131 */
        "movl infoParms(, %eax, 4), %eax\n"
        "popl %ebp\n" /* line 135 */
        "retl\n"
        ".Lfbd1f6_000bd210:\n"
        "movl $0x220284, %eax\n" /* line 128 */
        "popl %ebp\n" /* line 135 */
        "retl\n"
    );
}

