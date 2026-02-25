/* ASM dump from: l_memory.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/botlib/l_memory.cpp */

#include "common_types.h"
#include "imports.h"

void * GetMemory(long unsigned int size);
void FreeMemory(void *ptr);
void * GetClearedMemory(long unsigned int size);

/* line 22 */
__attribute__((naked))
void * GetMemory(long unsigned int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 22 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 27 | size */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "testl %eax, %eax\n" /* line 28 */
        "je .Lfc3b1c_000c3b3d\n"
        "movl $0x12345678, (%eax)\n" /* line 31 */
        "addl $4, %eax\n" /* line 32 */
        /* } scope */
        ".Lfc3b1c_000c3b3d:\n"
        "leave\n" /* line 33 */
        "retl\n"
    );
}

/* line 58 */
__attribute__((naked))
void FreeMemory(void *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 58 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* ptr */
        /* { scope 1 */
        "leal -4(%eax), %edx\n" /* line 62 */
        "cmpl $0x12345678, -4(%eax)\n" /* line 64 */
        "je .Lfc3b40_000c3b54\n"
        /* } scope */
        "popl %ebp\n" /* line 68 */
        "retl\n"
        /* { scope 1 */
        ".Lfc3b40_000c3b54:\n"
        "movl %edx, 8(%ebp)\n" /* line 66 | ptr */
        /* } scope */
        "popl %ebp\n" /* line 68 */
        /* { scope 1 */
        "jmp Z_FreeInternal\n" /* line 66 */
    );
}

/* line 42 */
__attribute__((naked))
void * GetClearedMemory(long unsigned int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 42 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* size */
        /* { scope 1 */
        /* { scope 2 */
        "leal 4(%esi), %eax\n" /* line 27 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "testl %eax, %eax\n" /* line 28 */
        "je .Lfc3b5e_000c3b9e\n"
        "movl $0x12345678, (%eax)\n" /* line 31 */
        "leal 4(%eax), %ebx\n" /* line 32 */
        /* } scope */
        "movl %esi, 8(%esp)\n" /* line 47 | size */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll memset\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 49 | ptr */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfc3b5e_000c3b9e:\n"
        "xorl %ebx, %ebx\n" /* line 28 */
        /* } scope */
        "movl %esi, 8(%esp)\n" /* line 47 | size */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll memset\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 49 | ptr */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

