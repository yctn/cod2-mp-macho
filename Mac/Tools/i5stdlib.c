/* ASM dump from: i5stdlib.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/i5stdlib.cp */

#include "common_types.h"
#include "imports.h"

int stricmp(const char *str1, const char *str2);
int strnicmp(const char *str1, const char *str2, size_t n);
int strcmpi(const char *str1, const char *str2);
char * strlwr(char *str);
char * strupr(char *str);
char * itoa(int val, char *str, int radix);

/* line 19 */
__attribute__((naked))
int stricmp(const char *str1, const char *str2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 19 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 25 */
        "jmp strcasecmp\n" /* line 24 */
    );
}

/* line 29 */
__attribute__((naked))
int strnicmp(const char *str1, const char *str2, size_t n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 35 */
        "jmp strncasecmp\n" /* line 34 */
    );
}

/* line 39 */
__attribute__((naked))
int strcmpi(const char *str1, const char *str2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 45 */
        "jmp strcasecmp\n" /* line 44 */
    );
}

/* line 51 */
__attribute__((naked))
char * strlwr(char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* str */
        /* { scope 1 */
        "movzbl (%esi), %eax\n" /* line 57 | str */
        "testb %al, %al\n"
        "jne .Lf26292_000262ad\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 64 | str */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf26292_000262ad:\n"
        "movl %esi, %ebx\n" /* line 57 | str, s */
        ".Lf26292_000262af:\n"
        "movsbl %al, %eax\n" /* line 59 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, (%ebx)\n" /* s */
        "addl $1, %ebx\n" /* line 60 | s */
        "movzbl (%ebx), %eax\n" /* line 57 | s */
        "testb %al, %al\n"
        "jne .Lf26292_000262af\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 64 | str */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 68 */
__attribute__((naked))
char * strupr(char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 68 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* str */
        /* { scope 1 */
        "movzbl (%esi), %eax\n" /* line 74 | str */
        "testb %al, %al\n"
        "jne .Lf262d0_000262eb\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 81 | str */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf262d0_000262eb:\n"
        "movl %esi, %ebx\n" /* line 74 | str, s */
        ".Lf262d0_000262ed:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "movb %al, (%ebx)\n" /* s */
        "addl $1, %ebx\n" /* line 77 | s */
        "movzbl (%ebx), %eax\n" /* line 74 | s */
        "testb %al, %al\n"
        "jne .Lf262d0_000262ed\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 81 | str */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 110 */
__attribute__((naked))
char * itoa(int val, char *str, int radix)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 110 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* val */
        "movl 0x10(%ebp), %ebx\n" /* radix */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 118 */
        "js .Lf26310_000263c6\n"
        "movl %eax, %ecx\n"
        "xorl %esi, %esi\n" /* isNegative */
        ".Lf26310_0002632b:\n"
        "xorl %edi, %edi\n" /* line 120 | index */
        "jmp .Lf26310_00026346\n"
        ".Lf26310_0002632f:\n"
        "leal 0x37(%edx), %eax\n" /* line 128 */
        "movl 0xc(%ebp), %edx\n" /* str */
        "movb %al, (%edx, %edi)\n"
        "addl $1, %edi\n" /* index */
        "movl %ecx, %eax\n" /* line 135 */
        "cltd\n"
        "idivl %ebx\n" /* radix */
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 124 */
        "je .Lf26310_00026367\n"
        ".Lf26310_00026346:\n"
        "movl %ecx, %eax\n" /* line 125 */
        "cltd\n"
        "idivl %ebx\n" /* radix */
        "cmpl $9, %edx\n" /* line 126 */
        "jg .Lf26310_0002632f\n"
        "leal 0x30(%edx), %eax\n" /* line 132 */
        "movl 0xc(%ebp), %edx\n" /* str */
        "movb %al, (%edx, %edi)\n"
        "addl $1, %edi\n" /* index */
        "movl %ecx, %eax\n" /* line 135 */
        "cltd\n"
        "idivl %ebx\n" /* radix */
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 124 */
        "jne .Lf26310_00026346\n"
        ".Lf26310_00026367:\n"
        "movl %esi, %edx\n" /* line 138 | isNegative */
        "testb %dl, %dl\n"
        "je .Lf26310_00026377\n"
        "movl 0xc(%ebp), %eax\n" /* line 140 | str */
        "movb $0x2d, (%eax, %edi)\n"
        "addl $1, %edi\n" /* index */
        ".Lf26310_00026377:\n"
        "movl 0xc(%ebp), %edx\n" /* line 142 | str */
        "movb $0, (%edi, %edx)\n" /* index */
        /* { scope 2 */
        "cld\n" /* line 90 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -2(%ecx), %ebx\n" /* bigIndex */
        "testl %ebx, %ebx\n" /* line 92 | bigIndex */
        "jle .Lf26310_000263bb\n"
        "leal (%ebx, %edx), %edi\n" /* bigIndex */
        "movl $1, %esi\n"
        ".Lf26310_0002639b:\n"
        "movl 0xc(%ebp), %edx\n" /* line 110 | str */
        "addl %esi, %edx\n"
        /* { scope 3 */
        "movzbl -1(%edx), %ecx\n" /* line 94 | temp */
        "movzbl (%edi), %eax\n" /* line 96 */
        "movb %al, -1(%edx)\n"
        "movb %cl, (%edi)\n" /* line 97 */
        "movl %esi, %eax\n"
        "subl $1, %ebx\n" /* line 100 | bigIndex */
        "addl $1, %esi\n"
        "subl $1, %edi\n"
        /* } scope */
        "cmpl %eax, %ebx\n" /* line 92 | bigIndex */
        "jg .Lf26310_0002639b\n"
        /* } scope */
        /* } scope */
        ".Lf26310_000263bb:\n"
        "movl 0xc(%ebp), %eax\n" /* line 147 | str */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf26310_000263c6:\n"
        "movl %eax, %ecx\n" /* line 120 */
        "negl %ecx\n"
        "movl $1, %esi\n" /* isNegative */
        "jmp .Lf26310_0002632b\n"
    );
}

