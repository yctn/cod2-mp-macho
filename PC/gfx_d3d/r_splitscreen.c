/* ASM dump from: r_splitscreen.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_splitscreen.cpp */

#include "common_types.h"
#include "imports.h"

extern GfxDrawGroupCommands delayedGroup[5]; /* 0x0 */

void R_InitDrawGroups(void);
GfxDrawGroupGlueBehavior R_BeginDrawGroupSection(GfxDrawGroupType group);
void R_BeginDrawGroupLoop(GfxDrawGroupType group, int viewIndex);
GfxDrawGroupGlueBehavior R_EndDrawGroupLoop(GfxDrawGroupType group, int viewIndex);
void R_EndDrawGroupSection(GfxDrawGroupType group);
void R_IssueDrawGroups(void);

/* line 18 */
__attribute__((naked))
void R_InitDrawGroups(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 18 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "xorl %esi, %esi\n"
        "movl $delayedGroup, %ecx\n"
        "xorl %ebx, %ebx\n"
        /* { scope 1 */
        ".Lfeea54_000eea62:\n"
        "movb $0, (%ecx)\n" /* line 25 */
        "movl $0xffffffff, 4(%ecx)\n" /* line 26 */
        "leal delayedGroup(%ebx), %eax\n"
        "movl $4, %edx\n"
        ".Lfeea54_000eea77:\n"
        "movl $0xffffffff, 8(%eax)\n" /* line 28 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 27 */
        "jne .Lfeea54_000eea77\n"
        "movl $0xffffffff, 0x18(%ecx)\n" /* line 29 */
        "addl $1, %esi\n" /* line 23 | group */
        "addl $0x1c, %ebx\n"
        "addl $0x1c, %ecx\n"
        "cmpl $5, %esi\n" /* group */
        "jne .Lfeea54_000eea62\n"
        /* } scope */
        "popl %ebx\n" /* line 31 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 35 */
__attribute__((naked))
GfxDrawGroupGlueBehavior R_BeginDrawGroupSection(GfxDrawGroupType group)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* group */
        "leal (, %eax, 4), %edx\n" /* line 41 */
        "movl %eax, %ebx\n"
        "shll $5, %ebx\n"
        "subl %edx, %ebx\n"
        "cmpl $-1, 0x1218984(%ebx)\n"
        "je .Lfeeaa0_000eeacc\n"
        "movl $1, %eax\n"
        "addl $4, %esp\n" /* line 48 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfeeaa0_000eeacc:\n"
        "movb $1, delayedGroup(%ebx)\n" /* line 44 */
        "calll R_BeginDelayedDrawing\n" /* line 45 */
        "movl %eax, 0x1218984(%ebx)\n"
        "xorl %eax, %eax\n"
        "addl $4, %esp\n" /* line 48 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 51 */
__attribute__((naked))
void R_BeginDrawGroupLoop(GfxDrawGroupType group, int viewIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* group */
        "leal (, %esi, 4), %eax\n" /* line 58 */
        "movl %esi, %ebx\n" /* group */
        "shll $5, %ebx\n"
        "subl %eax, %ebx\n"
        "cmpb $0, delayedGroup(%ebx)\n"
        "je .Lfeeae6_000eeb1d\n"
        "movl 0x1218984(%ebx), %eax\n" /* line 60 */
        "movl %eax, (%esp)\n"
        "calll R_EndDelayedDrawing\n"
        "movb $0, delayedGroup(%ebx)\n" /* line 61 */
        ".Lfeeae6_000eeb1d:\n"
        "calll R_BeginDelayedDrawing\n" /* line 64 */
        "leal (, %esi, 8), %edx\n"
        "subl %esi, %edx\n" /* group */
        "addl 0xc(%ebp), %edx\n" /* viewIndex */
        "movl $delayedGroup, %ecx\n"
        "movl %eax, 8(%ecx, %edx, 4)\n"
        "addl $0x10, %esp\n" /* line 66 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 69 */
__attribute__((naked))
GfxDrawGroupGlueBehavior R_EndDrawGroupLoop(GfxDrawGroupType group, int viewIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* group */
        "leal (, %ebx, 8), %eax\n" /* line 76 */
        "subl %ebx, %eax\n" /* group */
        "addl 0xc(%ebp), %eax\n" /* viewIndex */
        "movl 0x1218988(, %eax, 4), %eax\n"
        "cmpl $-1, %eax\n"
        "je .Lfeeb3e_000eeb68\n"
        "movl %eax, (%esp)\n" /* line 77 */
        "calll R_EndDelayedDrawing\n"
        ".Lfeeb3e_000eeb68:\n"
        "leal (, %ebx, 4), %eax\n" /* line 79 */
        "shll $5, %ebx\n" /* group */
        "subl %eax, %ebx\n" /* group */
        "cmpl $-1, 0x1218998(%ebx)\n" /* group */
        "je .Lfeeb3e_000eeb88\n"
        "movl $1, %eax\n"
        "addl $0x14, %esp\n" /* line 86 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfeeb3e_000eeb88:\n"
        "movb $1, delayedGroup(%ebx)\n" /* line 82 | group */
        "calll R_BeginDelayedDrawing\n" /* line 83 */
        "movl $0x1218990, %edx\n"
        "movl %eax, 8(%ebx, %edx)\n" /* group */
        "xorl %eax, %eax\n"
        "addl $0x14, %esp\n" /* line 86 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 89 */
__attribute__((naked))
void R_EndDrawGroupSection(GfxDrawGroupType group)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* group */
        "leal (, %eax, 4), %edx\n" /* line 94 */
        "movl %eax, %ebx\n"
        "shll $5, %ebx\n"
        "subl %edx, %ebx\n"
        "cmpb $0, delayedGroup(%ebx)\n"
        "je .Lfeeba6_000eebdc\n"
        "movl 0x1218998(%ebx), %eax\n" /* line 96 */
        "movl %eax, (%esp)\n"
        "calll R_EndDelayedDrawing\n"
        "movb $0, delayedGroup(%ebx)\n" /* line 97 */
        ".Lfeeba6_000eebdc:\n"
        "addl $0x14, %esp\n" /* line 100 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 103 */
__attribute__((naked))
void R_IssueDrawGroups(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 103 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0, -0x1c(%ebp)\n" /* group */
        "movl $delayedGroup, %edi\n"
        "movl $0, -0x20(%ebp)\n"
        /* { scope 1 */
        ".Lfeebe2_000eebfe:\n"
        "movl 4(%edi), %eax\n" /* line 113 */
        "cmpl $-1, %eax\n"
        "je .Lfeebe2_000eec15\n"
        "movl %eax, (%esp)\n" /* line 115 */
        "calll R_IssueDelayedDrawing\n"
        "movl $0xffffffff, 4(%edi)\n" /* line 116 */
        ".Lfeebe2_000eec15:\n"
        "movl -0x20(%ebp), %ebx\n"
        "addl $delayedGroup, %ebx\n"
        "movl $4, %esi\n"
        ".Lfeebe2_000eec23:\n"
        "movl 8(%ebx), %eax\n" /* line 121 */
        "cmpl $-1, %eax\n"
        "je .Lfeebe2_000eec3a\n"
        "movl %eax, (%esp)\n" /* line 123 */
        "calll R_IssueDelayedDrawing\n"
        "movl $0xffffffff, 8(%ebx)\n" /* line 124 */
        ".Lfeebe2_000eec3a:\n"
        "addl $4, %ebx\n"
        "subl $1, %esi\n" /* line 119 */
        "jne .Lfeebe2_000eec23\n"
        "movl 0x18(%edi), %eax\n" /* line 128 */
        "cmpl $-1, %eax\n"
        "je .Lfeebe2_000eec59\n"
        "movl %eax, (%esp)\n" /* line 130 */
        "calll R_IssueDelayedDrawing\n"
        "movl $0xffffffff, 0x18(%edi)\n" /* line 131 */
        ".Lfeebe2_000eec59:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 109 | group */
        "addl $0x1c, -0x20(%ebp)\n"
        "addl $0x1c, %edi\n"
        "cmpl $5, -0x1c(%ebp)\n" /* group */
        "jne .Lfeebe2_000eebfe\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

