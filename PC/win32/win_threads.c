/* ASM dump from: win_threads.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_threads.cpp */

#include "common_types.h"
#include "imports.h"

static void * g_threadValues[5]; /* 0x334f00 */
static DWORD threadId[1]; /* 0x334f14 */

void Sys_InitMainThread(void);
Bool Sys_IsMainThread(void);
void Sys_SetValue(int valueIndex, void *data);
void * Sys_GetValue(int valueIndex);

/* line 18 */
__attribute__((naked))
void Sys_InitMainThread(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 18 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll GetCurrentThreadId\n" /* line 21 */
        "movl %eax, threadId\n"
        "movl $0, (%esp)\n" /* line 22 */
        "calll Com_InitThreadData\n"
        "leave\n" /* line 24 */
        "retl\n"
    );
}

/* line 43 */
__attribute__((naked))
Bool Sys_IsMainThread(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll GetCurrentThreadId\n" /* line 46 */
        "cmpl threadId, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 52 */
        "retl\n"
    );
}

/* line 60 */
__attribute__((naked))
void Sys_SetValue(int valueIndex, void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* line 62 | valueIndex */
        "movl 0xc(%ebp), %eax\n" /* data */
        "movl %eax, g_threadValues(, %edx, 4)\n"
        "popl %ebp\n" /* line 63 */
        "retl\n"
    );
}

/* line 71 */
__attribute__((naked))
void * Sys_GetValue(int valueIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* valueIndex */
        "movl g_threadValues(, %eax, 4), %eax\n" /* valueIndex */
        "popl %ebp\n" /* line 74 */
        "retl\n"
    );
}

