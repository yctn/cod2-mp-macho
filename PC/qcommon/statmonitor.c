/* ASM dump from: statmonitor.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/statmonitor.cpp */

#include "common_types.h"
#include "imports.h"

static statmonitor_t stats[7]; /* 0x4ed7a0 */
static int statCount; /* 0x4ed780 */

void StatMon_Warning(int type, int duration, const char *materialName);
void StatMon_GetStatsArray(const statmonitor_t * *array, int *count);
void StatMon_Reset(void);

/* line 37 */
__attribute__((naked))
void StatMon_Warning(int type, int duration, const char *materialName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 37 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* type */
        "movl 0x195ed14, %eax\n" /* line 39 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfaf300_000af346\n"
        "cmpl $6, %ebx\n" /* line 42 | type */
        "ja .Lfaf300_000af34c\n"
        "calll Sys_Milliseconds\n" /* line 49 */
        "addl 0xc(%ebp), %eax\n" /* duration */
        "movl %eax, stats(, %ebx, 8)\n"
        "movl 0x4ed7a4(, %ebx, 8), %edx\n" /* line 50 */
        "testl %edx, %edx\n"
        "je .Lfaf300_000af37e\n"
        ".Lfaf300_000af336:\n"
        "cmpl statCount, %ebx\n" /* line 56 | type */
        "jl .Lfaf300_000af346\n"
        "leal 1(%ebx), %eax\n" /* line 57 | type */
        "movl %eax, statCount\n"
        ".Lfaf300_000af346:\n"
        "addl $0x14, %esp\n" /* line 62 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaf300_000af34c:\n"
        "movl %ebx, 8(%esp)\n" /* line 43 | type */
        "movl $0x21e95c, 4(%esp)\n" /* "StatMon_UpdateEntry: invalid entry '%i'
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "calll Sys_Milliseconds\n" /* line 49 */
        "addl 0xc(%ebp), %eax\n" /* duration */
        "movl %eax, stats(, %ebx, 8)\n"
        "movl 0x4ed7a4(, %ebx, 8), %edx\n" /* line 50 */
        "testl %edx, %edx\n"
        "jne .Lfaf300_000af336\n"
        ".Lfaf300_000af37e:\n"
        "movl 0x195ecac, %eax\n"
        "movl 0x108(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaf300_000af336\n"
        "movl $1, 8(%esp)\n" /* line 53 */
        "movl $0x30, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* materialName */
        "movl %eax, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0x10(%eax)\n"
        "movl $stats, %edx\n"
        "movl %eax, 4(%edx, %ebx, 8)\n"
        "jmp .Lfaf300_000af336\n"
    );
}

/* line 70 */
__attribute__((naked))
void StatMon_GetStatsArray(const statmonitor_t * *array, int *count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 72 | array */
        "movl $stats, (%eax)\n"
        "movl statCount, %edx\n" /* line 73 */
        "movl 0xc(%ebp), %eax\n" /* count */
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 74 */
        "retl\n"
    );
}

/* line 82 */
__attribute__((naked))
void StatMon_Reset(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 82 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "movl $stats, %edi\n" /* line 84 */
        "cld\n"
        "movl $0xe, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $0, statCount\n" /* line 85 */
        "popl %edi\n" /* line 86 */
        "popl %ebp\n"
        "retl\n"
    );
}

