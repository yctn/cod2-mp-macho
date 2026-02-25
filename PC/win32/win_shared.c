/* ASM dump from: win_shared.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_shared.cpp */

#include "common_types.h"
#include "imports.h"

extern int sys_timeBase; /* 0x0 */
static qboolean initialized; /* 0x4ed800 */

int Sys_Milliseconds(void);
int Sys_MillisecondsRaw(void);
inflate_huft Sys_SnapVector(float *v);

/* line 25 */
__attribute__((naked))
int Sys_Milliseconds(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "movl initialized, %eax\n" /* line 30 */
        "testl %eax, %eax\n"
        "jne .Lfaf3f0_000af413\n"
        "calll timeGetTime\n" /* line 32 */
        "movl %eax, sys_timeBase\n"
        "movl $1, initialized\n" /* line 33 */
        ".Lfaf3f0_000af413:\n"
        "calll timeGetTime\n" /* line 35 */
        "subl sys_timeBase, %eax\n"
        /* } scope */
        "leave\n" /* line 38 */
        "retl\n"
    );
}

/* line 46 */
__attribute__((naked))
int Sys_MillisecondsRaw(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 46 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 49 */
        "jmp timeGetTime\n" /* line 48 */
    );
}

/* line 71 */
__attribute__((naked))
inflate_huft Sys_SnapVector(float *v)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* v */
        "cvttss2si (%edx), %eax\n" /* line 74 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "cvttss2si 4(%edx), %eax\n" /* line 76 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "cvttss2si 8(%edx), %eax\n" /* line 78 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "popl %ebp\n" /* line 109 */
        "retl\n"
    );
}

