/* ASM dump from: scr_tempmemory.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_tempmemory.cpp */

#include "common_types.h"
#include "imports.h"

static int currentPos; /* 0x7ef480 */

void TempMemoryReset(void);
char * TempMalloc(int len);
char * TempMallocAlign(int len);
char * TempMallocAlignStrict(int len);
void TempMemorySetPos(char *pos);

/* line 8 */
__attribute__((naked))
void TempMemoryReset(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 8 */
        "movl %esp, %ebp\n"
        "movl $0, currentPos\n" /* line 11 */
        "popl %ebp\n" /* line 12 */
        "retl\n"
    );
}

/* line 15 */
__attribute__((naked))
char * TempMalloc(int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 15 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl currentPos, %ebx\n" /* line 22 | newCurrentPos */
        "addl 8(%ebp), %ebx\n" /* len, newCurrentPos */
        "movl %ebx, (%esp)\n" /* line 23 | newCurrentPos */
        "calll Hunk_ReallocateTempMemoryInternal\n"
        "addl currentPos, %eax\n"
        "movl %ebx, currentPos\n" /* line 24 | newCurrentPos */
        /* } scope */
        "addl $0x14, %esp\n" /* line 27 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 30 */
__attribute__((naked))
char * TempMallocAlign(int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 30 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl currentPos, %ebx\n" /* line 22 | newCurrentPos */
        "addl 8(%ebp), %ebx\n" /* len, newCurrentPos */
        "movl %ebx, (%esp)\n" /* line 23 | newCurrentPos */
        "calll Hunk_ReallocateTempMemoryInternal\n"
        "addl currentPos, %eax\n"
        "movl %ebx, currentPos\n" /* line 24 | newCurrentPos */
        /* } scope */
        "addl $0x14, %esp\n" /* line 40 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 43 */
__attribute__((naked))
char * TempMallocAlignStrict(int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl currentPos, %ebx\n" /* line 22 | newCurrentPos */
        "addl 8(%ebp), %ebx\n" /* len, newCurrentPos */
        "movl %ebx, (%esp)\n" /* line 23 | newCurrentPos */
        "calll Hunk_ReallocateTempMemoryInternal\n"
        "addl currentPos, %eax\n"
        "movl %ebx, currentPos\n" /* line 24 | newCurrentPos */
        /* } scope */
        "addl $0x14, %esp\n" /* line 53 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 56 */
__attribute__((naked))
void TempMemorySetPos(char *pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl currentPos, %ebx\n" /* line 22 */
        "movl %ebx, (%esp)\n" /* line 23 */
        "calll Hunk_ReallocateTempMemoryInternal\n"
        "addl currentPos, %eax\n"
        "subl 8(%ebp), %eax\n" /* line 62 | pos */
        "subl %eax, %ebx\n"
        "movl %ebx, currentPos\n"
        "movl %ebx, (%esp)\n" /* line 63 */
        "calll Hunk_ReallocateTempMemoryInternal\n"
        "addl $0x14, %esp\n" /* line 64 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

