/* ASM dump from: win_localize.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_localize.cpp */

#include "common_types.h"
#include "imports.h"

static int localization; /* 0x4e9600 */
static char language_buffer[4096]; /* 0x4e9620 */

language_t Win_InitLocalization(void);
J_COLOR_SPACE Win_ShutdownLocalization(void);
const char * Win_LocalizeRef(const char *ref);

/* line 28 */
__attribute__((naked))
language_t Win_InitLocalization(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "movl $0, localization\n" /* line 35 */
        "movl $0, 0x4e9604\n" /* line 36 */
        "movl $0x21c1d4, 4(%esp)\n" /* line 38 */
        "movl $0x21c1d8, (%esp)\n" /* "localization.txt" */
        "calll FS_FileOpen\n"
        "movl %eax, %esi\n" /* fp */
        "testl %eax, %eax\n" /* line 39 */
        "je .Lf77c50_00077d5b\n"
        "movl $2, 8(%esp)\n" /* line 42 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "movl %esi, (%esp)\n" /* line 43 | fp */
        "calll ftell\n"
        "movl %eax, %ebx\n" /* size */
        "movl $0, 8(%esp)\n" /* line 44 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fp */
        "calll FS_FileSeek\n"
        "movl $0x4e9620, localization\n" /* line 47 */
        "movl %esi, 0xc(%esp)\n" /* line 48 | fp */
        "movl %ebx, 8(%esp)\n" /* size */
        "movl $1, 4(%esp)\n"
        "movl $language_buffer, (%esp)\n"
        "calll FS_FileRead\n"
        "movl %eax, %ebx\n" /* size */
        "movl %esi, (%esp)\n" /* line 49 | fp */
        "calll FS_FileClose\n"
        "testl %ebx, %ebx\n" /* line 50 | size */
        "je .Lf77c50_00077d51\n"
        "movl localization, %eax\n" /* line 55 */
        "movb $0, (%eax, %ebx)\n"
        "movl $0, -0xc(%ebp)\n" /* line 57 | lang */
        "movzbl (%eax), %edx\n" /* line 58 */
        "testb %dl, %dl\n"
        "je .Lf77c50_00077d47\n"
        "cmpb $0xa, %dl\n" /* line 60 */
        "je .Lf77c50_00077d28\n"
        "leal 1(%eax), %edx\n"
        ".Lf77c50_00077d17:\n"
        "movl %edx, %eax\n" /* line 70 */
        "movzbl (%edx), %ecx\n" /* line 58 */
        "testb %cl, %cl\n"
        "je .Lf77c50_00077d47\n"
        "addl $1, %edx\n"
        "cmpb $0xa, %cl\n" /* line 60 */
        "jne .Lf77c50_00077d17\n"
        ".Lf77c50_00077d28:\n"
        "movb $0, (%eax)\n" /* line 62 */
        "addl $1, %eax\n" /* line 63 */
        "movl %eax, 0x4e9604\n"
        "leal -0xc(%ebp), %eax\n" /* line 68 | lang */
        "movl %eax, 4(%esp)\n"
        "movl localization, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SEH_GetLanguageIndexForName\n"
        ".Lf77c50_00077d47:\n"
        "movl -0xc(%ebp), %eax\n" /* line 73 | lang */
        /* } scope */
        "addl $0x20, %esp\n" /* line 74 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf77c50_00077d51:\n"
        "movl $0, localization\n" /* line 52 */
        ".Lf77c50_00077d5b:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 74 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 82 */
__attribute__((naked))
J_COLOR_SPACE Win_ShutdownLocalization(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 82 */
        "movl %esp, %ebp\n"
        "movl $0, localization\n" /* line 84 */
        "movl $0, 0x4e9604\n" /* line 85 */
        "popl %ebp\n" /* line 86 */
        "retl\n"
    );
}

/* line 105 */
__attribute__((naked))
const char * Win_LocalizeRef(const char *ref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 105 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0x21c1ec, (%esp)\n" /* line 111 */
        "calll Com_BeginParseSession\n"
        "movl 0x4e9604, %eax\n" /* line 112 */
        "movl %eax, -0x1c(%ebp)\n" /* strings */
        "leal -0x1c(%ebp), %edi\n" /* strings */
        ".Lf77d7e_00077d9e:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll Com_Parse\n"
        "cmpb $0, (%eax)\n" /* line 116 */
        "je .Lf77d7e_00077dec\n"
        "movl 8(%ebp), %edx\n" /* line 122 | ref */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "movl %eax, %esi\n"
        "movl %edi, (%esp)\n" /* line 124 */
        "calll Com_Parse\n"
        "movl %eax, %ebx\n"
        "cmpb $0, (%eax)\n" /* line 125 */
        "je .Lf77d7e_00077dec\n"
        "testl %esi, %esi\n" /* line 132 */
        "jne .Lf77d7e_00077d9e\n"
        "calll Com_EndParseSession\n" /* line 134 */
        "movl %ebx, 4(%esp)\n" /* line 96 */
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 138 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf77d7e_00077dec:\n"
        "calll Com_EndParseSession\n" /* line 127 */
        "movl 8(%ebp), %eax\n" /* line 96 | ref */
        "movl %eax, 4(%esp)\n"
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 138 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

