/* ASM dump from: cl_keys_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_keys_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern void ReplaceStringInternal(char **dest, const char *src);
extern void Cmd_AddCommand(const char *name, void (*func)(void));

extern PlayerKeyState playerKeys[1]; /* 0x0 */
extern field_t *chatField; /* 0x0 */
extern qboolean *chat_team; /* 0x0 */
extern qboolean *key_overstrikeMode; /* 0x0 */
extern qboolean *anykeydown; /* 0x0 */
extern qkey_t *keys; /* 0x0 */
extern field_t historyEditLines[32]; /* 0x0 */
extern field_t g_consoleField; /* 0x0 */
extern int nextHistoryLine; /* 0x0 */
extern int historyLine; /* 0x0 */
extern keyname_t keynames[99]; /* 0x0 */
extern keyname_t keynames_localized[99]; /* 0x0 */
extern char * frenchNumberKeysMap[10]; /* 0x0 */
static char tinystr[5]; /* tinystr */
static const char *completionString; /* completionString */
static Bool hasExactMatch; /* hasExactMatch */
static char shortestMatch[1024]; /* shortestMatch */
static int matchCount; /* matchCount */

qboolean Key_GetOverstrikeMode(void);
void Field_AdjustScroll(field_t *edit);
void Key_SetOverstrikeMode(qboolean state);
static void FindMatches(const char *s);
static void PrintMatches(const char *s);
static void keyConcatArgs(void);
static int Key_StringToKeynum(void);
char * Key_KeynumToString(int keynum, qboolean translate);
void Key_SetBinding(int keynum, const char *binding);
char * Key_GetBinding(int keynum);
void CL_InitKeyCommands(void);
void Key_Shutdown(void);
void Field_Draw(field_t *edit, int x, int y, int horzAlign, int vertAlign, qboolean showCursor);
void Key_Unbind_f(void);
void Key_Unbindall_f(void);
void Key_Bind_f(void);
void Field_CharEvent(field_t *edit, int ch);
void CL_CharEvent(int key);
void Field_KeyDownEvent(field_t *edit, int key);
void Message_Key(int key);
void Console_Key(int key);
void Key_WriteBindings(fileHandle_t f);
void Key_Bindlist_f(void);
void CL_KeyEvent(int key, const qboolean down, const unsigned int time);
void Key_ClearStates(void);

/* line 1152 */
qboolean Key_GetOverstrikeMode(void)
{
    return *key_overstrikeMode;
}

/* line 451 */
__attribute__((naked))
void Field_AdjustScroll(field_t *edit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 451 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 461 | edit */
        "movss 0x10(%eax), %xmm0\n"
        "divss lit4_002ed6b8, %xmm0\n" /* 48.0f */
        "movss %xmm0, -0x24(%ebp)\n" /* fontScale */
        "cvtsi2ssl 0xc(%eax), %xmm1\n" /* line 462 */
        "movss %xmm1, -0x1c(%ebp)\n" /* lineWidth */
        "movl 0x14(%eax), %eax\n" /* line 464 */
        "testl %eax, %eax\n"
        "je .Lf13fac6_0013fc58\n"
        "movss %xmm0, (%esp)\n" /* line 466 */
        "calll GetVirtualWidthFromRealWidth\n"
        "fstps -0x24(%ebp)\n" /* fontScale */
        "movss -0x1c(%ebp), %xmm0\n" /* line 467 | lineWidth */
        "movss %xmm0, (%esp)\n"
        "calll GetVirtualHeightFromRealHeight\n"
        "fstps -0x1c(%ebp)\n" /* lineWidth */
        "movl imp_cls, %eax\n" /* line 468 */
        "movl str_002a0938+296(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* font */
        ".Lf13fac6_0013fb26:\n"
        "movl imp_re, %ebx\n" /* line 475 */
        "movss -0x24(%ebp), %xmm0\n" /* fontScale */
        "movss %xmm0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x110(%ebx)\n"
        "fstps -0x20(%ebp)\n" /* actualScale */
        "movl 8(%ebp), %edx\n" /* line 476 | edit */
        "addl $0x18, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl -0x28(%ebp), %edi\n" /* font */
        "movl %edi, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x114(%ebx)\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 479 */
        "mulss -0x20(%ebp), %xmm0\n" /* actualScale */
        "movss -0x1c(%ebp), %xmm1\n" /* lineWidth */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf13fac6_0013fd33\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 487 | 0.0f */
        "jbe .Lf13fac6_0013fc72\n"
        "movl 8(%ebp), %eax\n" /* edit */
        "movl 4(%eax), %ebx\n"
        "movl %ebx, %eax\n"
        ".Lf13fac6_0013fb90:\n"
        "testl %ebx, %ebx\n"
        "jle .Lf13fac6_0013fbe3\n"
        "movl -0x28(%ebp), %edx\n" /* line 489 | font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x2c(%ebp), %edi\n"
        "leal -1(%edi, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x114(%eax)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n" /* actualScale */
        "ucomiss -0x1c(%ebp), %xmm0\n" /* line 490 | lineWidth */
        "jae .Lf13fac6_0013fd56\n"
        "movl 8(%ebp), %edx\n" /* line 492 | edit */
        "movl 4(%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, %ebx\n"
        "movl %eax, 4(%edx)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 487 | lineWidth */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf13fac6_0013fb90\n"
        ".Lf13fac6_0013fbe3:\n"
        "movl imp_re, %esi\n" /* line 497 | textLen */
        "movl -0x28(%ebp), %edi\n" /* font */
        "movl %edi, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "addl %ebx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%esi)\n" /* textLen */
        "movl %eax, %ebx\n"
        "movl %edi, 8(%esp)\n" /* line 498 */
        "movl $0, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* edit */
        "addl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x114(%esi)\n" /* textLen */
        "cvtsi2ssl %ebx, %xmm1\n"
        "mulss -0x20(%ebp), %xmm1\n" /* actualScale */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n" /* actualScale */
        "subss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 499 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf13fac6_0013fc7d\n"
        "ucomiss -0x1c(%ebp), %xmm1\n" /* lineWidth */
        "jb .Lf13fac6_0013fca1\n"
        "movl 8(%ebp), %edx\n" /* line 510 | edit */
        "movl 4(%edx), %ebx\n"
        "addl $1, %ebx\n"
        "movl %ebx, 4(%edx)\n"
        "jmp .Lf13fac6_0013fbe3\n"
        ".Lf13fac6_0013fc58:\n"
        "movss %xmm0, 4(%esp)\n" /* line 472 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x28(%ebp)\n" /* font */
        "jmp .Lf13fac6_0013fb26\n"
        ".Lf13fac6_0013fc72:\n"
        "movl 8(%ebp), %edx\n" /* edit */
        "movl 4(%edx), %ebx\n"
        "jmp .Lf13fac6_0013fbe3\n"
        ".Lf13fac6_0013fc7d:\n"
        "movl 8(%ebp), %eax\n" /* line 503 | edit */
        "movl 4(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf13fac6_0013fc92\n"
        "subl $1, %ebx\n" /* line 506 */
        "movl %ebx, 4(%eax)\n"
        "jmp .Lf13fac6_0013fbe3\n"
        ".Lf13fac6_0013fc92:\n"
        "ucomiss -0x1c(%ebp), %xmm0\n" /* line 495 | lineWidth */
        "jae .Lf13fac6_0013fbe3\n"
        "movl 8(%ebp), %edx\n" /* edit */
        "jmp .Lf13fac6_0013fca9\n"
        ".Lf13fac6_0013fca1:\n"
        "movl 8(%ebp), %edi\n" /* edit */
        "movl 4(%edi), %ebx\n"
        "movl %edi, %edx\n"
        ".Lf13fac6_0013fca9:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 515 | textLen */
        "addl %ebx, %esi\n" /* textLen */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* textLen */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* textLen */
        "movl (%edx), %eax\n" /* line 516 */
        "subl %ebx, %eax\n"
        "movl %eax, 8(%edx)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 518 | lineWidth */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf13fac6_0013fcd4\n"
        "cmpl %eax, %esi\n" /* textLen */
        "jg .Lf13fac6_0013fcf7\n"
        /* } scope */
        ".Lf13fac6_0013fcd4:\n"
        "addl $0x3c, %esp\n" /* line 525 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13fac6_0013fcdc:\n"
        "movl 8(%ebp), %edx\n" /* line 522 | edit */
        "movl 8(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 8(%edx)\n"
        "ucomiss %xmm0, %xmm1\n" /* line 518 */
        "jbe .Lf13fac6_0013fcd4\n"
        "cmpl %esi, %eax\n" /* textLen */
        "jge .Lf13fac6_0013fcd4\n"
        "movl 8(%ebp), %edx\n" /* edit */
        "movl 4(%edx), %ebx\n"
        ".Lf13fac6_0013fcf7:\n"
        "movl -0x28(%ebp), %edi\n" /* line 520 | font */
        "movl %edi, 8(%esp)\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "addl %ebx, %eax\n"
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x114(%eax)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n" /* actualScale */
        "movss -0x1c(%ebp), %xmm1\n" /* line 521 | lineWidth */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf13fac6_0013fcdc\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 525 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13fac6_0013fd33:\n"
        "movl 8(%ebp), %eax\n" /* line 481 | edit */
        "movl $0, 4(%eax)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 482 */
        "movl %edx, (%esp)\n"
        "calll SEH_PrintStrlen\n"
        "movl 8(%ebp), %edi\n" /* edit */
        "movl %eax, 8(%edi)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 525 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13fac6_0013fd56:\n"
        "movl 8(%ebp), %eax\n" /* edit */
        "movl 4(%eax), %ebx\n"
        "jmp .Lf13fac6_0013fbe3\n"
    );
}

/* line 1158 */
void Key_SetOverstrikeMode(qboolean state)
{
    *key_overstrikeMode = state;
}

/* line 711 */
static __attribute__((naked))
void FindMatches(const char *s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 711 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl completionString, %ebx\n" /* line 715 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf13fd72_0013fdd7\n"
        "movl matchCount, %eax\n" /* line 719 */
        "addl $1, %eax\n"
        "movl %eax, matchCount\n"
        "subl $1, %eax\n" /* line 720 */
        "je .Lf13fd72_0013fe12\n"
        "movl 8(%ebp), %eax\n" /* line 729 | s */
        "cmpb $0, (%eax)\n"
        "jne .Lf13fd72_0013fddf\n"
        "xorl %edi, %edi\n" /* i */
        ".Lf13fd72_0013fdc5:\n"
        "movl $1, %eax\n" /* line 731 */
        ".Lf13fd72_0013fdca:\n"
        "movb %al, hasExactMatch\n"
        "movb $0, shortestMatch(%edi)\n" /* line 732 | i */
        /* } scope */
        ".Lf13fd72_0013fdd7:\n"
        "addl $0x1c, %esp\n" /* line 733 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13fd72_0013fddf:\n"
        "movl %eax, %esi\n" /* line 729 */
        "xorl %edi, %edi\n" /* i */
        ".Lf13fd72_0013fde3:\n"
        "movsbl shortestMatch(%edi), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %eax, %ebx\n"
        "movsbl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf13fd72_0013fe36\n"
        "addl $1, %edi\n" /* line 730 | i */
        "movl 8(%ebp), %esi\n" /* s */
        "addl %edi, %esi\n" /* i */
        "cmpb $0, (%esi)\n" /* line 729 */
        "jne .Lf13fd72_0013fde3\n"
        "jmp .Lf13fd72_0013fdc5\n"
        ".Lf13fd72_0013fe12:\n"
        "movl $0x400, 8(%esp)\n" /* line 722 */
        "movl 8(%ebp), %edi\n" /* s, i */
        "movl %edi, 4(%esp)\n" /* i */
        "movl $shortestMatch, (%esp)\n"
        "calll I_strncpyz\n"
        "movb $1, hasExactMatch\n" /* line 723 */
        "jmp .Lf13fd72_0013fdd7\n"
        ".Lf13fd72_0013fe36:\n"
        "cmpb $0, (%esi)\n" /* line 731 */
        "je .Lf13fd72_0013fdc5\n"
        "cmpb $0, hasExactMatch\n"
        "jne .Lf13fd72_0013fe48\n"
        "xorl %eax, %eax\n"
        "jmp .Lf13fd72_0013fdca\n"
        ".Lf13fd72_0013fe48:\n"
        "cmpb $0, shortestMatch(%edi)\n" /* i */
        "je .Lf13fd72_0013fdc5\n"
        "xorl %eax, %eax\n"
        "jmp .Lf13fd72_0013fdca\n"
    );
}

/* line 742 */
static __attribute__((naked))
void PrintMatches(const char *s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 742 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* s */
        "movl $shortestMatch, %edi\n" /* line 744 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $shortestMatch, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* s */
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf13fe5c_0013fea3\n"
        "movl %ebx, 4(%esp)\n" /* line 745 | s */
        "movl $str_00217190, (%esp)\n" /* "    %s
" */
        "calll Com_Printf\n"
        ".Lf13fe5c_0013fea3:\n"
        "addl $0x10, %esp\n" /* line 746 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 749 */
static __attribute__((naked))
void keyConcatArgs(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 749 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl $1, %esi\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 754 */
        "cmpl %eax, %esi\n" /* i */
        "jge .Lf13feaa_0013ff52\n"
        ".Lf13feaa_0013fec4:\n"
        "movl $str_00217914, 8(%esp)\n" /* line 756 */
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll I_strncat\n"
        "movl %esi, (%esp)\n" /* line 757 | i */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* arg */
        "movzbl (%eax), %eax\n" /* line 758 */
        "testb %al, %al\n"
        "je .Lf13feaa_0013ff1d\n"
        "jmp .Lf13feaa_0013fefd\n"
        ".Lf13feaa_0013fef3:\n"
        "addl $1, %ebx\n" /* line 765 | arg */
        "movzbl (%ebx), %eax\n" /* line 758 | arg */
        "testb %al, %al\n"
        "je .Lf13feaa_0013ff1d\n"
        ".Lf13feaa_0013fefd:\n"
        "cmpb $0x20, %al\n" /* line 760 */
        "jne .Lf13feaa_0013fef3\n"
        "movl $str_00222120, 8(%esp)\n" /* line 762 */
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll I_strncat\n"
        ".Lf13feaa_0013ff1d:\n"
        "movl %esi, (%esp)\n" /* line 767 | i */
        "calll Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll I_strncat\n"
        "cmpb $0x20, (%ebx)\n" /* line 768 | arg */
        "je .Lf13feaa_0013ff59\n"
        "addl $1, %esi\n" /* line 754 | i */
        ".Lf13feaa_0013ff45:\n"
        "calll Cmd_Argc\n"
        "cmpl %eax, %esi\n" /* i */
        "jl .Lf13feaa_0013fec4\n"
        /* } scope */
        ".Lf13feaa_0013ff52:\n"
        "addl $0x10, %esp\n" /* line 773 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13feaa_0013ff59:\n"
        "movl $str_00222120, 8(%esp)\n" /* line 770 */
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll I_strncat\n"
        "addl $1, %esi\n" /* line 754 | i */
        "jmp .Lf13feaa_0013ff45\n"
    );
}

/* line 1193 */
static __attribute__((naked))
int Key_StringToKeynum(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1193 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %ebx\n" /* str */
        "testl %eax, %eax\n" /* line 1197 */
        "jne .Lf13ff7a_0013ff94\n"
        ".Lf13ff7a_0013ff88:\n"
        "movl $0xffffffff, %eax\n" /* line 1243 */
        ".Lf13ff7a_0013ff8d:\n"
        "addl $0x10, %esp\n" /* line 1250 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13ff7a_0013ff94:\n"
        "movzbl (%eax), %eax\n" /* line 1197 */
        "testb %al, %al\n"
        "je .Lf13ff7a_0013ff88\n"
        "movzbl 1(%ebx), %edx\n" /* line 1201 | str */
        "testb %dl, %dl\n"
        "jne .Lf13ff7a_0013ffa8\n"
        "movsbl %al, %eax\n" /* line 1203 */
        "jmp .Lf13ff7a_0013ff8d\n"
        ".Lf13ff7a_0013ffa8:\n"
        "cmpb $0x30, %al\n" /* line 1207 */
        "jne .Lf13ff7a_0013ffb1\n"
        "cmpb $0x78, %dl\n"
        "je .Lf13ff7a_0013ffdf\n"
        ".Lf13ff7a_0013ffb1:\n"
        "movl keynames, %eax\n" /* line 1243 */
        "testl %eax, %eax\n"
        "je .Lf13ff7a_0013ff88\n"
        "movl $keynames, %edi\n" /* n1 */
        ".Lf13ff7a_0013ffbf:\n"
        "movl %eax, 4(%esp)\n" /* line 1245 */
        "movl %ebx, (%esp)\n" /* str */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf13ff7a_0013ffda\n"
        "addl $8, %edi\n" /* line 1243 | n1 */
        "movl (%edi), %eax\n" /* n1 */
        "testl %eax, %eax\n"
        "jne .Lf13ff7a_0013ffbf\n"
        "jmp .Lf13ff7a_0013ff88\n"
        ".Lf13ff7a_0013ffda:\n"
        "movl 4(%edi), %eax\n" /* line 1246 | n1 */
        "jmp .Lf13ff7a_0013ff8d\n"
        ".Lf13ff7a_0013ffdf:\n"
        "cld\n" /* line 1207 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* str */
        "repne scasb %es:(%edi), %al\n"
        "cmpl $-6, %ecx\n"
        "jne .Lf13ff7a_0013ffb1\n"
        /* { scope 1 */
        "movsbl 2(%ebx), %edi\n" /* line 1211 | str, n1 */
        "movl %edi, (%esp)\n" /* line 1212 | n1 */
        "calll I_isdigit\n"
        "testb %al, %al\n"
        "je .Lf13ff7a_00140031\n"
        "subl $0x30, %edi\n" /* n1 */
        "shll $4, %edi\n" /* n1 */
        ".Lf13ff7a_00140006:\n"
        "movsbl 3(%ebx), %ebx\n" /* line 1225 | str */
        "movl %ebx, (%esp)\n" /* line 1226 | str */
        "calll I_isdigit\n"
        "testb %al, %al\n"
        "je .Lf13ff7a_00140020\n"
        "leal -0x30(%ebx), %eax\n" /* line 1228 | str */
        "addl %edi, %eax\n" /* line 1239 | n1 */
        "jmp .Lf13ff7a_0013ff8d\n"
        ".Lf13ff7a_00140020:\n"
        "leal -0x61(%ebx), %eax\n" /* line 1230 | str */
        "cmpl $5, %eax\n"
        "jbe .Lf13ff7a_0014003d\n"
        "xorl %eax, %eax\n"
        "addl %edi, %eax\n" /* line 1239 | n1 */
        "jmp .Lf13ff7a_0013ff8d\n"
        ".Lf13ff7a_00140031:\n"
        "leal -0x61(%edi), %eax\n" /* line 1216 | n1 */
        "cmpl $5, %eax\n"
        "jbe .Lf13ff7a_00140047\n"
        "xorl %edi, %edi\n" /* n1 */
        "jmp .Lf13ff7a_00140006\n"
        ".Lf13ff7a_0014003d:\n"
        "leal -0x57(%ebx), %eax\n" /* line 1232 | str */
        "addl %edi, %eax\n" /* line 1239 | n1 */
        "jmp .Lf13ff7a_0013ff8d\n"
        ".Lf13ff7a_00140047:\n"
        "subl $0x57, %edi\n" /* line 1216 | n1 */
        "shll $4, %edi\n" /* n1 */
        "jmp .Lf13ff7a_00140006\n"
    );
}

/* line 1268 */
__attribute__((naked))
char * Key_KeynumToString(int keynum, qboolean translate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1268 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* keynum */
        "movl 0xc(%ebp), %esi\n" /* translate */
        /* { scope 1 */
        "cmpl $-1, %ebx\n" /* line 1275 | keynum */
        "je .Lf140050_0014015f\n"
        "cmpl $0xff, %ebx\n" /* line 1278 | keynum */
        "ja .Lf140050_001400d5\n"
        "testl %esi, %esi\n" /* line 1282 | translate */
        "jne .Lf140050_001400ee\n"
        ".Lf140050_00140073:\n"
        "leal -0x21(%ebx), %eax\n" /* line 1286 | keynum */
        "cmpl $0x5d, %eax\n"
        "jbe .Lf140050_001400af\n"
        ".Lf140050_0014007b:\n"
        "testl %esi, %esi\n" /* line 1300 | translate */
        "je .Lf140050_001400e7\n"
        "movl $keynames_localized, %eax\n"
        ".Lf140050_00140084:\n"
        "movl (%eax), %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "je .Lf140050_00140117\n"
        "cmpl 4(%eax), %ebx\n" /* line 1322 | keynum */
        "je .Lf140050_001400a6\n"
        "leal 8(%eax), %edx\n"
        ".Lf140050_00140096:\n"
        "movl (%edx), %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "je .Lf140050_00140117\n"
        "movl 4(%edx), %eax\n" /* line 1322 */
        "addl $8, %edx\n"
        "cmpl %eax, %ebx\n" /* keynum */
        "jne .Lf140050_00140096\n"
        /* } scope */
        ".Lf140050_001400a6:\n"
        "movl %ecx, %eax\n" /* line 1337 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf140050_001400af:\n"
        "cmpl $0x22, %ebx\n" /* line 1286 | keynum */
        "je .Lf140050_0014007b\n"
        "movl %ebx, (%esp)\n" /* line 1288 | keynum */
        "calll ___toupper\n"
        "movb %al, tinystr\n"
        "movb $0, tinystr+1\n" /* line 1289 */
        "cmpl $0x3b, %ebx\n" /* line 1290 | keynum */
        "je .Lf140050_001400e3\n"
        ".Lf140050_001400ce:\n"
        "movl $tinystr, %ecx\n" /* line 1336 */
        "jmp .Lf140050_001400a6\n"
        ".Lf140050_001400d5:\n"
        "movl $str_002a6ec0, %ecx\n" /* line 1278 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 1337 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf140050_001400e3:\n"
        "testl %esi, %esi\n" /* line 1290 | translate */
        "jne .Lf140050_001400ce\n"
        ".Lf140050_001400e7:\n"
        "movl $keynames, %eax\n" /* line 1300 */
        "jmp .Lf140050_00140084\n"
        ".Lf140050_001400ee:\n"
        "calll SEH_GetCurrentLanguage\n" /* line 1282 */
        "subl $1, %eax\n"
        "jne .Lf140050_00140073\n"
        "cmpl $0x2f, %ebx\n" /* keynum */
        "jle .Lf140050_00140073\n"
        "cmpl $0x39, %ebx\n" /* keynum */
        "jg .Lf140050_00140073\n"
        "movl virtualKeyConvert+224(, %ebx, 4), %ecx\n" /* line 1283 */
        "jmp .Lf140050_001400a6\n"
        ".Lf140050_00140117:\n"
        "movl %ebx, %edx\n" /* line 1327 | keynum */
        "sarl $4, %edx\n"
        "movl %ebx, %eax\n" /* line 1328 | keynum */
        "andl $0xf, %eax\n"
        "movb $0x30, tinystr\n" /* line 1330 */
        "movb $0x78, tinystr+1\n" /* line 1331 */
        "cmpl $9, %edx\n" /* line 1332 */
        "jle .Lf140050_00140171\n"
        "addb $0x57, %dl\n"
        ".Lf140050_00140137:\n"
        "movb %dl, tinystr+2\n"
        "cmpl $9, %eax\n" /* line 1333 */
        "jle .Lf140050_0014016d\n"
        "addb $0x57, %al\n"
        ".Lf140050_00140144:\n"
        "movb %al, tinystr+3\n"
        "movb $0, tinystr+4\n" /* line 1334 */
        "movl $tinystr, %ecx\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 1337 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf140050_0014015f:\n"
        "movl $str_002a6eb0, %ecx\n" /* line 1275 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 1337 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf140050_0014016d:\n"
        "addb $0x30, %al\n" /* line 1333 */
        "jmp .Lf140050_00140144\n"
        ".Lf140050_00140171:\n"
        "addb $0x30, %dl\n" /* line 1332 */
        "jmp .Lf140050_00140137\n"
    );
}

/* line 1345 */
void Key_SetBinding(int keynum, const char *binding)
{
    if (keynum == -1)
        return;
    ReplaceStringInternal((char **)((byte *)keys + keynum * 12 + 8), binding);
    *(int *)(*(int *)imp_dvar_modifiedFlags) |= 1;
}

/* line 1366 */
char * Key_GetBinding(int keynum)
{
    if (keynum == -1)
        return "";
    return *(char **)((byte *)keys + keynum * 12 + 8);
}

/* line 1611 */
void CL_InitKeyCommands(void)
{
    Cmd_AddCommand("bind", Key_Bind_f);
    Cmd_AddCommand("unbind", Key_Unbind_f);
    Cmd_AddCommand("unbindall", Key_Unbindall_f);
    Cmd_AddCommand("bindlist", Key_Bindlist_f);
}

/* line 2046 */
__attribute__((naked))
void Key_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2046 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $0, (%esp)\n" /* line 2053 */
        "calll CL_SwitchToLocalClient\n"
        "xorl %ebx, %ebx\n"
        ".Lf140224_00140239:\n"
        "movl keys, %eax\n" /* line 2056 */
        "movl 8(%eax, %ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf140224_0014025b\n"
        "movl %eax, (%esp)\n" /* line 2058 */
        "calll Z_FreeInternal\n"
        "movl keys, %eax\n" /* line 2059 */
        "movl $0, 8(%eax, %ebx)\n"
        ".Lf140224_0014025b:\n"
        "addl $0xc, %ebx\n"
        "cmpl $0xc00, %ebx\n" /* line 2054 */
        "jne .Lf140224_00140239\n"
        "addl $0x14, %esp\n" /* line 2063 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 384 */
__attribute__((naked))
void Field_Draw(field_t *edit, int x, int y, int horzAlign, int vertAlign, qboolean showCursor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 384 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4ac, %esp\n"
        "movl 8(%ebp), %esi\n" /* edit */
        /* { scope 1 */
        "movl $0x3f800000, %ebx\n" /* line 396 */
        "movl %ebx, -0x28(%ebp)\n" /* vColor */
        "movl %ebx, -0x24(%ebp)\n"
        "movl %ebx, -0x20(%ebp)\n"
        "movl %ebx, -0x1c(%ebp)\n"
        "movl 4(%esi), %eax\n" /* line 398 | edit */
        "movl $0x100, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal 0x18(%esi, %eax), %eax\n" /* edit */
        "movl %eax, 4(%esp)\n"
        "leal -0x428(%ebp), %eax\n" /* str */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%esi), %edi\n" /* line 400 | edit, cursorPos */
        "subl 4(%esi), %edi\n" /* edit, cursorPos */
        "movl 0x14(%esi), %eax\n" /* line 402 | edit */
        "testl %eax, %eax\n"
        "je .Lf14026c_001403e8\n"
        "movl imp_cls, %eax\n" /* line 404 */
        "movl str_002a0938+296(%eax), %eax\n"
        "movl %eax, -0x43c(%ebp)\n" /* font */
        "movl key_overstrikeMode, %eax\n" /* line 409 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14026c_001403c6\n"
        "movl $0, -0x438(%ebp)\n" /* fontStyle */
        "movl %ebx, -0x430(%ebp)\n" /* xScale */
        "movss -0x430(%ebp), %xmm2\n" /* xScale */
        "movl $0x5f, %ebx\n"
        ".Lf14026c_001402fd:\n"
        "cvtsi2ssl 0xc(%ebp), %xmm0\n" /* line 435 | x */
        "movss %xmm0, -0x434(%ebp)\n" /* xAdj */
        "movl -0x43c(%ebp), %eax\n" /* line 436 | font */
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "movss %xmm2, -0x468(%ebp)\n"
        "calll *0x118(%eax)\n"
        "cvtsi2ssl 0x10(%ebp), %xmm1\n" /* y */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x468(%ebp), %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl 8(%esi), %edx\n" /* line 438 | edit */
        "testl %edx, %edx\n"
        "jne .Lf14026c_0014034d\n"
        "movl $0x100, 8(%esi)\n" /* line 439 | edit */
        ".Lf14026c_0014034d:\n"
        "movl %ebx, 0x30(%esp)\n" /* line 442 */
        "movl %edi, 0x2c(%esp)\n" /* cursorPos */
        "movl -0x438(%ebp), %eax\n" /* fontStyle */
        "movl %eax, 0x28(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* vColor */
        "movl %eax, 0x24(%esp)\n"
        "movss %xmm2, 0x20(%esp)\n"
        "movss -0x430(%ebp), %xmm0\n" /* xScale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* vertAlign */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0x434(%ebp), %xmm0\n" /* xAdj */
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x43c(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl 8(%esi), %eax\n" /* edit */
        "movl %eax, 4(%esp)\n"
        "leal -0x428(%ebp), %eax\n" /* str */
        "movl %eax, (%esp)\n"
        "calll CL_DrawTextWithCursor\n"
        /* } scope */
        "addl $0x4ac, %esp\n" /* line 443 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14026c_001403c6:\n"
        "movl $0, -0x438(%ebp)\n" /* line 409 | fontStyle */
        "movl %ebx, -0x430(%ebp)\n" /* xScale */
        "movss -0x430(%ebp), %xmm2\n" /* xScale */
        "movl $0x7c, %ebx\n"
        "jmp .Lf14026c_001402fd\n"
        ".Lf14026c_001403e8:\n"
        "movss 0x10(%esi), %xmm0\n" /* line 416 | edit */
        "divss lit4_002ed6b8, %xmm0\n" /* 48.0f */
        "movss %xmm0, 4(%esp)\n" /* line 417 */
        "movl $0, (%esp)\n"
        "movss %xmm0, -0x458(%ebp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x43c(%ebp)\n" /* font */
        "movss -0x458(%ebp), %xmm0\n" /* line 418 */
        "movss %xmm0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x110(%eax)\n"
        "fstps -0x42c(%ebp)\n"
        "cmpl $5, 0x18(%ebp)\n" /* line 419 | vertAlign */
        "je .Lf14026c_00140483\n"
        "movss -0x42c(%ebp), %xmm0\n"
        "movss %xmm0, -0x430(%ebp)\n" /* xScale */
        "movaps %xmm0, %xmm2\n"
        ".Lf14026c_00140450:\n"
        "movl key_overstrikeMode, %eax\n" /* line 429 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf14026c_0014046f\n"
        "movl $3, -0x438(%ebp)\n" /* fontStyle */
        "movl $0x7c, %ebx\n"
        "jmp .Lf14026c_001402fd\n"
        ".Lf14026c_0014046f:\n"
        "movl $3, -0x438(%ebp)\n" /* fontStyle */
        "movl $0x5f, %ebx\n"
        "jmp .Lf14026c_001402fd\n"
        ".Lf14026c_00140483:\n"
        "movss -0x42c(%ebp), %xmm0\n" /* line 420 */
        "movss %xmm0, (%esp)\n"
        "calll GetRealWidthFromVirtualWidth\n"
        "fstps -0x430(%ebp)\n" /* xScale */
        "movss -0x42c(%ebp), %xmm0\n" /* line 424 */
        "movss %xmm0, (%esp)\n"
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0x46c(%ebp)\n"
        "movss -0x46c(%ebp), %xmm2\n"
        "jmp .Lf14026c_00140450\n"
    );
}

/* line 1406 */
__attribute__((naked))
void Key_Unbind_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1406 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 1410 */
        "cmpl $2, %eax\n"
        "je .Lf1404be_001404dc\n"
        "movl $str_002a6ef8, (%esp)\n" /* line 1412 */
        "calll Com_Printf\n"
        /* } scope */
        "leave\n" /* line 1424 */
        "retl\n"
        /* { scope 1 */
        ".Lf1404be_001404dc:\n"
        "movl $1, (%esp)\n" /* line 1416 */
        "calll Cmd_Argv\n"
        "calll Key_StringToKeynum\n"
        "cmpl $-1, %eax\n" /* line 1417 */
        "je .Lf1404be_00140519\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 1353 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl keys, %edx\n"
        "leal 8(%edx, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ReplaceStringInternal\n"
        "movl imp_dvar_modifiedFlags, %eax\n" /* line 1357 */
        "orl $1, (%eax)\n"
        /* } scope */
        "leave\n" /* line 1424 */
        "retl\n"
        /* { scope 1 */
        ".Lf1404be_00140519:\n"
        "movl $1, (%esp)\n" /* line 1419 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002a6f24, (%esp)\n" /* ""%s" isn't a valid key
" */
        "calll Com_Printf\n"
        /* } scope */
        "leave\n" /* line 1424 */
        "retl\n"
    );
}

/* line 1432 */
__attribute__((naked))
void Key_Unbindall_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1432 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "xorl %ebx, %ebx\n"
        "xorl %esi, %esi\n"
        "movl imp_dvar_modifiedFlags, %edi\n"
        /* { scope 1 */
        ".Lf140538_0014054b:\n"
        "movl %esi, %eax\n" /* line 1437 */
        "addl keys, %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf140538_00140575\n"
        "cmpl $-1, %ebx\n" /* line 1347 */
        "je .Lf140538_00140575\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 1353 */
        "addl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ReplaceStringInternal\n"
        "orl $1, (%edi)\n" /* line 1357 */
        ".Lf140538_00140575:\n"
        "addl $1, %ebx\n" /* line 1436 | i */
        "addl $0xc, %esi\n"
        "cmpl $0x100, %ebx\n" /* i */
        "jne .Lf140538_0014054b\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1439 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1447 */
__attribute__((naked))
void Key_Bind_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1447 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 1453 */
        "movl %eax, %esi\n" /* c */
        "cmpl $1, %eax\n" /* line 1455 */
        "jle .Lf14058c_001406b0\n"
        "movl $1, (%esp)\n" /* line 1460 */
        "calll Cmd_Argv\n"
        "calll Key_StringToKeynum\n"
        "cmpl $-1, %eax\n" /* line 1461 */
        "je .Lf14058c_00140689\n"
        "movl %eax, (%esp)\n" /* line 1468 */
        "calll ___tolower\n"
        "movl %eax, -0x41c(%ebp)\n"
        "cmpl $2, %esi\n" /* line 1470 | c */
        "je .Lf14058c_0014078a\n"
        "movb $0, -0x418(%ebp)\n" /* line 1480 | cmd */
        "jle .Lf14058c_00140648\n" /* line 1481 */
        "leal -1(%esi), %edx\n" /* c */
        "movl %edx, -0x420(%ebp)\n"
        "movl $2, %ebx\n" /* i */
        "cmpl $3, %esi\n" /* c */
        "jne .Lf14058c_00140716\n"
        ".Lf14058c_001405f9:\n"
        "movl %ebx, (%esp)\n" /* line 1486 | i */
        "calll Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* cmd */
        "movl %eax, (%esp)\n"
        "calll I_strncat\n"
        "cmpl -0x420(%ebp), %ebx\n" /* line 1489 | i */
        "je .Lf14058c_00140641\n"
        "movl $str_00217914, 8(%esp)\n" /* line 1490 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* cmd */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        ".Lf14058c_00140641:\n"
        "addl $1, %ebx\n" /* line 1481 | i */
        "cmpl %ebx, %esi\n" /* i, c */
        "jne .Lf14058c_001405f9\n"
        ".Lf14058c_00140648:\n"
        "cmpl $-1, -0x41c(%ebp)\n" /* line 1347 */
        "je .Lf14058c_0014067e\n"
        "leal -0x418(%ebp), %eax\n" /* line 1353 | cmd */
        "movl %eax, 4(%esp)\n"
        "movl -0x41c(%ebp), %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "movl keys, %edx\n"
        "leal 8(%edx, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ReplaceStringInternal\n"
        "movl imp_dvar_modifiedFlags, %eax\n" /* line 1357 */
        "orl $1, (%eax)\n"
        /* } scope */
        ".Lf14058c_0014067e:\n"
        "addl $0x42c, %esp\n" /* line 1494 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14058c_00140689:\n"
        "movl $1, (%esp)\n" /* line 1463 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002a6f24, (%esp)\n" /* ""%s" isn't a valid key
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1494 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14058c_001406b0:\n"
        "movl $str_002a6f3c, (%esp)\n" /* line 1457 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1494 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14058c_001406c7:\n"
        "movl $str_00222120, 8(%esp)\n" /* line 1488 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* cmd */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        ".Lf14058c_001406e5:\n"
        "cmpl -0x420(%ebp), %ebx\n" /* line 1489 | i */
        "je .Lf14058c_0014070b\n"
        "movl $str_00217914, 8(%esp)\n" /* line 1490 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* cmd */
        "movl %eax, (%esp)\n"
        "calll I_strncat\n"
        ".Lf14058c_0014070b:\n"
        "addl $1, %ebx\n" /* line 1481 | i */
        "cmpl %ebx, %esi\n" /* i, c */
        "je .Lf14058c_00140648\n"
        ".Lf14058c_00140716:\n"
        "movl %ebx, (%esp)\n" /* line 1483 | i */
        "calll Cmd_Argv\n"
        "movl $0x20, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf14058c_001407c5\n"
        "movl $str_00222120, 8(%esp)\n" /* line 1485 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* cmd */
        "movl %eax, (%esp)\n"
        "calll I_strncat\n"
        "movl $1, %edi\n"
        ".Lf14058c_00140759:\n"
        "movl %ebx, (%esp)\n" /* line 1486 | i */
        "calll Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* cmd */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "movl %edi, %eax\n" /* line 1487 */
        "testb %al, %al\n"
        "je .Lf14058c_001406e5\n"
        "jmp .Lf14058c_001406c7\n"
        ".Lf14058c_0014078a:\n"
        "leal (%eax, %eax, 2), %edx\n" /* line 1472 */
        "movl keys, %eax\n"
        "movl 8(%eax, %edx, 4), %ebx\n" /* i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf14058c_001407c9\n"
        "movl $1, (%esp)\n" /* line 1473 */
        "calll Cmd_Argv\n"
        "movl %ebx, 8(%esp)\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl $str_002a6f70, (%esp)\n" /* ""%s" = "%s"
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1494 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14058c_001407c5:\n"
        "xorl %edi, %edi\n" /* line 1357 */
        "jmp .Lf14058c_00140759\n"
        ".Lf14058c_001407c9:\n"
        "movl $1, (%esp)\n" /* line 1475 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002a6f80, (%esp)\n" /* ""%s" is not bound
" */
        "calll Com_Printf\n"
        "jmp .Lf14058c_0014067e\n"
    );
}

/* line 633 */
__attribute__((naked))
void Field_CharEvent(field_t *edit, int ch)
{
    __asm__ __volatile__ (
        ".Lf1407ea_001407ea:\n"
        "pushl %ebp\n" /* line 633 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* edit */
        "movl 0xc(%ebp), %ebx\n" /* ch */
        "leal 0x18(%esi), %edx\n" /* line 637 | edit */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n" /* pasteLen */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* pasteLen */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* pasteLen */
        "cmpl $0x16, %ebx\n" /* line 639 | ch */
        "je .Lf1407ea_001408b9\n"
        "cmpl $3, %ebx\n" /* line 643 | ch */
        "je .Lf1407ea_001408ea\n"
        "cmpl $8, %ebx\n" /* line 647 | ch */
        "je .Lf1407ea_00140887\n"
        "cmpl $1, %ebx\n" /* line 655 | ch */
        "je .Lf1407ea_00140872\n"
        "cmpl $5, %ebx\n" /* line 661 | ch */
        "je .Lf1407ea_00140901\n"
        "cmpl $0x1f, %ebx\n" /* line 665 | ch */
        "jle .Lf1407ea_0014087f\n"
        "movl key_overstrikeMode, %eax\n" /* line 671 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1407ea_00140912\n"
        "movl (%esi), %eax\n" /* line 673 | edit */
        "cmpl $0xff, %eax\n"
        "je .Lf1407ea_0014087f\n"
        "movb %bl, 0x18(%eax, %esi)\n" /* line 675 | ch */
        "leal 1(%eax), %edx\n" /* line 676 */
        "movl %edx, (%esi)\n" /* edit */
        ".Lf1407ea_00140858:\n"
        "leal 1(%edi), %eax\n" /* line 688 | pasteLen */
        "cmpl %eax, %edx\n"
        "je .Lf1407ea_0014094e\n"
        ".Lf1407ea_00140863:\n"
        "movl %esi, 8(%ebp)\n" /* line 692 | edit */
        "addl $0x2c, %esp\n" /* line 693 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Field_AdjustScroll\n" /* line 692 */
        ".Lf1407ea_00140872:\n"
        "movl $0, (%esi)\n" /* line 657 | edit */
        "movl $0, 4(%esi)\n" /* line 658 | edit */
        ".Lf1407ea_0014087f:\n"
        "addl $0x2c, %esp\n" /* line 693 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1407ea_00140887:\n"
        "movl (%esi), %eax\n" /* line 649 | edit */
        "testl %eax, %eax\n"
        "jle .Lf1407ea_00140863\n"
        "addl %eax, %edx\n" /* line 651 */
        "subl %eax, %edi\n" /* pasteLen */
        "leal 1(%edi), %eax\n" /* pasteLen */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "subl $1, %edx\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        "subl $1, (%esi)\n" /* line 652 | edit */
        "movl %esi, 8(%ebp)\n" /* line 692 | edit */
        "addl $0x2c, %esp\n" /* line 693 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Field_AdjustScroll\n" /* line 692 */
        /* { scope 1 */
        ".Lf1407ea_001408b9:\n"
        "calll Sys_GetClipboardData\n" /* line 538 */
        "movl %eax, -0x1c(%ebp)\n" /* cbd */
        "testl %eax, %eax\n" /* line 540 */
        "je .Lf1407ea_00140863\n"
        "cld\n" /* line 546 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n" /* pasteLen */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* pasteLen */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* pasteLen */
        "testl %edi, %edi\n" /* line 547 | pasteLen */
        "jg .Lf1407ea_00140958\n"
        ".Lf1407ea_001408da:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 552 | cbd */
        "movl %ecx, (%esp)\n"
        "calll Z_FreeInternal\n"
        "jmp .Lf1407ea_00140863\n"
        /* } scope */
        ".Lf1407ea_001408ea:\n"
        "movl %esi, (%esp)\n" /* line 645 | edit */
        "calll Field_Clear\n"
        "movl %esi, 8(%ebp)\n" /* line 692 | edit */
        "addl $0x2c, %esp\n" /* line 693 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Field_AdjustScroll\n" /* line 692 */
        ".Lf1407ea_00140901:\n"
        "movl %edi, (%esi)\n" /* line 663 | pasteLen, edit */
        "movl %esi, 8(%ebp)\n" /* line 692 | edit */
        "addl $0x2c, %esp\n" /* line 693 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Field_AdjustScroll\n" /* line 692 */
        ".Lf1407ea_00140912:\n"
        "cmpl $0xff, %edi\n" /* line 680 | pasteLen */
        "je .Lf1407ea_0014087f\n"
        "movl (%esi), %eax\n" /* line 683 | edit */
        "addl %eax, %edx\n"
        "movl %edi, %ecx\n" /* pasteLen */
        "subl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "addl $1, %edx\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        "movl (%esi), %edx\n" /* line 684 | edit */
        "movb %bl, 0x18(%edx, %esi)\n" /* ch */
        "addl $1, %edx\n" /* line 685 */
        "movl %edx, (%esi)\n" /* edit */
        "jmp .Lf1407ea_00140858\n"
        ".Lf1407ea_0014094e:\n"
        "movb $0, 0x18(%edx, %esi)\n" /* line 689 */
        "jmp .Lf1407ea_00140863\n"
        /* { scope 1 */
        ".Lf1407ea_00140958:\n"
        "xorb %bl, %bl\n" /* line 547 | i */
        ".Lf1407ea_0014095a:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 549 | cbd */
        "movsbl (%edx, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Field_CharEvent\n"
        "addl $1, %ebx\n" /* line 547 | i */
        "cmpl %ebx, %edi\n" /* i, pasteLen */
        "jne .Lf1407ea_0014095a\n"
        "jmp .Lf1407ea_001408da\n"
    );
}

/* line 1982 */
__attribute__((naked))
void CL_CharEvent(int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1982 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* key */
        "cmpl $0x60, %edx\n" /* line 1990 */
        "je .Lf14097a_001409b0\n"
        "cmpl $0x7e, %edx\n"
        "je .Lf14097a_001409b0\n"
        "movl imp_cl, %eax\n" /* line 1994 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "testb $1, %al\n"
        "jne .Lf14097a_001409b2\n"
        "testb $8, %al\n" /* line 1998 */
        "jne .Lf14097a_001409c4\n"
        "testb $0x10, %al\n" /* line 2002 */
        "jne .Lf14097a_001409d9\n"
        "movl imp_clc, %eax\n" /* line 2006 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14097a_001409b2\n"
        ".Lf14097a_001409b0:\n"
        "leave\n" /* line 2010 */
        "retl\n"
        ".Lf14097a_001409b2:\n"
        "movl %edx, 4(%esp)\n" /* line 2008 */
        "movl $g_consoleField, (%esp)\n"
        "calll Field_CharEvent\n"
        "leave\n" /* line 2010 */
        "retl\n"
        ".Lf14097a_001409c4:\n"
        "movl $1, 4(%esp)\n" /* line 2000 */
        "orb $4, %dh\n"
        "movl %edx, (%esp)\n"
        "calll UI_KeyEvent\n"
        "leave\n" /* line 2010 */
        "retl\n"
        ".Lf14097a_001409d9:\n"
        "movl %edx, 4(%esp)\n" /* line 2004 */
        "movl chatField, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Field_CharEvent\n"
        "leave\n" /* line 2010 */
        "retl\n"
    );
}

/* line 566 */
__attribute__((naked))
void Field_KeyDownEvent(field_t *edit, int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 566 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* edit */
        "movl 0xc(%ebp), %ebx\n" /* key */
        /* { scope 1: cbd */
        "leal 0x18(%esi), %edx\n" /* line 570 | edit */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n" /* len */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* len */
        "cmpl $0xa1, %ebx\n" /* line 573 | key */
        "je .Lf1409ee_00140aaa\n"
        "cmpl $0xc0, %ebx\n" /* key */
        "je .Lf1409ee_00140aaa\n"
        ".Lf1409ee_00140a29:\n"
        "cmpl $0xa2, %ebx\n" /* line 577 | key */
        "je .Lf1409ee_00140aef\n"
        "cmpl $0x9d, %ebx\n" /* line 582 | key */
        "je .Lf1409ee_00140b1d\n"
        "cmpl $0x9c, %ebx\n" /* line 596 | key */
        "je .Lf1409ee_00140bd4\n"
        "cmpl $0xa5, %ebx\n" /* line 610 | key */
        "je .Lf1409ee_00140baf\n"
        "movl %ebx, (%esp)\n" /* key */
        "calll ___tolower\n"
        "cmpl $0x61, %eax\n"
        "je .Lf1409ee_00140b9c\n"
        ".Lf1409ee_00140a6a:\n"
        "cmpl $0xa6, %ebx\n" /* line 614 | key */
        "je .Lf1409ee_00140bcd\n"
        "movl %ebx, (%esp)\n" /* key */
        "calll ___tolower\n"
        "cmpl $0x65, %eax\n"
        "je .Lf1409ee_00140bba\n"
        ".Lf1409ee_00140a87:\n"
        "cmpl $0xa1, %ebx\n" /* line 618 | key */
        "je .Lf1409ee_00140c50\n"
        ".Lf1409ee_00140a93:\n"
        "movl imp_cls, %eax\n" /* line 623 */
        "movl 0x110(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1409ee_00140b0e\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 625 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: cbd */
        ".Lf1409ee_00140aaa:\n"
        "movl keys, %eax\n" /* line 573 */
        "movl 0x780(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1409ee_00140a29\n"
        /* { scope 2 */
        "calll Sys_GetClipboardData\n" /* line 538 */
        "movl %eax, -0x1c(%ebp)\n" /* cbd */
        "testl %eax, %eax\n" /* line 540 */
        "je .Lf1409ee_00140a93\n"
        "cld\n" /* line 546 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n" /* pasteLen */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* pasteLen */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* pasteLen */
        "testl %edi, %edi\n" /* line 547 | pasteLen */
        "jg .Lf1409ee_00140cc1\n"
        ".Lf1409ee_00140ae2:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 552 | cbd */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "jmp .Lf1409ee_00140a93\n"
        /* } scope */
        ".Lf1409ee_00140aef:\n"
        "movl (%esi), %eax\n" /* line 579 | edit */
        "cmpl %eax, %edi\n" /* len */
        "jle .Lf1409ee_00140a93\n"
        "addl %eax, %edx\n" /* line 580 */
        "subl %eax, %edi\n" /* len */
        "movl %edi, 8(%esp)\n" /* len */
        "leal 1(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        "jmp .Lf1409ee_00140a93\n"
        ".Lf1409ee_00140b0e:\n"
        "movl %esi, 8(%ebp)\n" /* line 624 | edit */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 625 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: cbd */
        "jmp Field_AdjustScroll\n" /* line 624 */
        ".Lf1409ee_00140b1d:\n"
        "movl (%esi), %eax\n" /* line 584 | edit */
        "cmpl %eax, %edi\n" /* len */
        "jle .Lf1409ee_00140b28\n"
        "leal 1(%eax), %edx\n" /* line 585 */
        "movl %edx, (%esi)\n" /* edit */
        ".Lf1409ee_00140b28:\n"
        "movl keys, %eax\n" /* line 587 */
        "movl 0x774(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1409ee_00140a93\n"
        "movl (%esi), %edx\n" /* line 589 | edit */
        "movl %edx, %eax\n"
        "cmpl %edx, %edi\n" /* len */
        "jle .Lf1409ee_00140a93\n"
        "jmp .Lf1409ee_00140b73\n"
        /* { scope 2 */
        ".Lf1409ee_00140b49:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "testl $0x500, 0x34(%eax, %ecx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lf1409ee_00140b5c:\n"
        "testl %eax, %eax\n" /* line 589 */
        "je .Lf1409ee_00140c65\n"
        "leal 1(%edx), %eax\n" /* line 590 */
        "movl %eax, %edx\n"
        "movl %eax, (%esi)\n" /* edit */
        "cmpl %eax, %edi\n" /* line 589 | len */
        "jle .Lf1409ee_00140c65\n"
        ".Lf1409ee_00140b73:\n"
        "movsbl 0x18(%eax, %esi), %ecx\n" /* _c */
        /* { scope 2 */
        "testl $0xffffff80, %ecx\n" /* line 220 */
        "je .Lf1409ee_00140b49\n"
        "movl $0x500, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl (%esi), %edx\n"
        "jmp .Lf1409ee_00140b5c\n"
        /* } scope */
        ".Lf1409ee_00140b9c:\n"
        "movl keys, %eax\n" /* line 610 */
        "movl 0x774(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1409ee_00140a6a\n"
        ".Lf1409ee_00140baf:\n"
        "movl $0, (%esi)\n" /* line 612 | edit */
        "jmp .Lf1409ee_00140a93\n"
        ".Lf1409ee_00140bba:\n"
        "movl keys, %eax\n" /* line 614 */
        "movl 0x774(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1409ee_00140a87\n"
        ".Lf1409ee_00140bcd:\n"
        "movl %edi, (%esi)\n" /* line 616 | len, edit */
        "jmp .Lf1409ee_00140a93\n"
        ".Lf1409ee_00140bd4:\n"
        "movl (%esi), %edx\n" /* line 598 | edit */
        "testl %edx, %edx\n"
        "jle .Lf1409ee_00140bdf\n"
        "subl $1, %edx\n" /* line 599 */
        "movl %edx, (%esi)\n" /* edit */
        ".Lf1409ee_00140bdf:\n"
        "movl keys, %eax\n" /* line 601 */
        "movl 0x774(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1409ee_00140bf4\n"
        "movl %edx, %eax\n" /* line 603 */
        "testl %edx, %edx\n"
        "jg .Lf1409ee_00140c27\n"
        ".Lf1409ee_00140bf4:\n"
        "cmpl 4(%esi), %edx\n" /* line 607 | edit */
        "jge .Lf1409ee_00140a93\n"
        "movl %edx, 4(%esi)\n" /* line 608 | edit */
        "jmp .Lf1409ee_00140a93\n"
        /* { scope 2 */
        ".Lf1409ee_00140c05:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "testl $0x500, 0x34(%eax, %ecx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lf1409ee_00140c18:\n"
        "testl %eax, %eax\n" /* line 603 */
        "je .Lf1409ee_00140bf4\n"
        "leal -1(%edx), %eax\n" /* line 604 */
        "movl %eax, %edx\n"
        "movl %eax, (%esi)\n" /* edit */
        "testl %eax, %eax\n" /* line 603 */
        "jle .Lf1409ee_00140bf4\n"
        ".Lf1409ee_00140c27:\n"
        "movsbl 0x17(%eax, %esi), %ecx\n" /* _c */
        /* { scope 2 */
        "testl $0xffffff80, %ecx\n" /* line 220 */
        "je .Lf1409ee_00140c05\n"
        "movl $0x500, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl (%esi), %edx\n"
        "jmp .Lf1409ee_00140c18\n"
        /* } scope */
        ".Lf1409ee_00140c50:\n"
        "movl key_overstrikeMode, %edx\n" /* line 1154 */
        "xorl %eax, %eax\n" /* line 1160 */
        "cmpl $0, (%edx)\n"
        "sete %al\n"
        "movl %eax, (%edx)\n"
        "jmp .Lf1409ee_00140a93\n"
        ".Lf1409ee_00140c65:\n"
        "movl %edx, %eax\n" /* line 592 | _c */
        "cmpl %edx, %edi\n" /* _c, len */
        "jg .Lf1409ee_00140c9a\n"
        "jmp .Lf1409ee_00140a93\n"
        /* { scope 2 */
        ".Lf1409ee_00140c70:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "testl $0x500, 0x34(%eax, %edx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lf1409ee_00140c83:\n"
        "testl %eax, %eax\n" /* line 592 */
        "jne .Lf1409ee_00140a93\n"
        "movl (%esi), %eax\n" /* line 593 | edit */
        "addl $1, %eax\n"
        "movl %eax, (%esi)\n" /* edit */
        "cmpl %eax, %edi\n" /* line 592 | len */
        "jle .Lf1409ee_00140a93\n"
        ".Lf1409ee_00140c9a:\n"
        "movsbl 0x18(%eax, %esi), %edx\n" /* _c */
        /* { scope 2 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf1409ee_00140c70\n"
        "movl $0x500, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf1409ee_00140c83\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1409ee_00140cc1:\n"
        "xorl %ebx, %ebx\n" /* line 547 | i */
        ".Lf1409ee_00140cc3:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 549 | cbd */
        "movsbl (%edx, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Field_CharEvent\n"
        "addl $1, %ebx\n" /* line 547 | i */
        "cmpl %ebx, %edi\n" /* i, pasteLen */
        "jne .Lf1409ee_00140cc3\n"
        "jmp .Lf1409ee_00140ae2\n"
    );
}

/* line 1118 */
__attribute__((naked))
void Message_Key(int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1118 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x414, %esp\n"
        "movl 8(%ebp), %eax\n" /* key */
        /* { scope 1 */
        "cmpl $0x1b, %eax\n" /* line 1123 */
        "je .Lf140ce2_00140d26\n"
        "cmpl $0xd, %eax\n" /* line 1130 */
        "je .Lf140ce2_00140d1a\n"
        "cmpl $0xbf, %eax\n"
        "je .Lf140ce2_00140d1a\n"
        "movl %eax, 4(%esp)\n" /* line 1146 */
        "movl chatField, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Field_KeyDownEvent\n"
        /* } scope */
        "addl $0x414, %esp\n" /* line 1147 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf140ce2_00140d1a:\n"
        "movl chatField, %edx\n" /* line 1132 */
        "cmpb $0, 0x18(%edx)\n"
        "jne .Lf140ce2_00140d47\n"
        ".Lf140ce2_00140d26:\n"
        "movl imp_cl, %eax\n" /* line 1141 */
        "movl (%eax), %eax\n"
        "andl $0xffffffef, 4(%eax)\n"
        "movl chatField, %eax\n" /* line 1142 */
        "movl %eax, (%esp)\n"
        "calll Field_Clear\n"
        /* } scope */
        "addl $0x414, %esp\n" /* line 1147 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf140ce2_00140d47:\n"
        "movl imp_clc, %eax\n" /* line 1132 */
        "movl (%eax), %eax\n"
        "cmpl $8, (%eax)\n"
        "jne .Lf140ce2_00140d26\n"
        "movl chat_team, %eax\n" /* line 1134 */
        "movl (%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf140ce2_00140d8d\n"
        "leal 0x18(%edx), %eax\n" /* line 1135 */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a6f94, 8(%esp)\n" /* "say_team "%s"
" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* buffer */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf140ce2_00140d83:\n"
        "movl %ebx, (%esp)\n" /* line 1139 */
        "calll CL_AddReliableCommand\n"
        "jmp .Lf140ce2_00140d26\n"
        ".Lf140ce2_00140d8d:\n"
        "leal 0x18(%edx), %eax\n" /* line 1137 */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a6fa4, 8(%esp)\n" /* "say "%s"
" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* buffer */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf140ce2_00140d83\n"
    );
}

/* line 938 */
__attribute__((naked))
void Console_Key(int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 938 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x56c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* key */
        "cmpl $0x6c, %ebx\n" /* line 941 | key */
        "je .Lf140db4_00140ff5\n"
        "cmpl $0xd, %ebx\n" /* line 948 | key */
        "je .Lf140db4_00140e9f\n"
        "cmpl $0xbf, %ebx\n" /* key */
        "je .Lf140db4_00140e9f\n"
        "cmpl $9, %ebx\n" /* line 1023 | key */
        "je .Lf140db4_00141126\n"
        "cmpl $0xce, %ebx\n" /* line 1033 | key */
        "je .Lf140db4_001410a7\n"
        "cmpl $0x9a, %ebx\n" /* key */
        "je .Lf140db4_001410ba\n"
        ".Lf140db4_00140e02:\n"
        "movl %ebx, (%esp)\n" /* key */
        "calll ___tolower\n"
        "cmpl $0x70, %eax\n"
        "je .Lf140db4_00141111\n"
        ".Lf140db4_00140e13:\n"
        "cmpl $0xcd, %ebx\n" /* line 1045 | key */
        "je .Lf140db4_00141019\n"
        "cmpl $0x9b, %ebx\n" /* key */
        "je .Lf140db4_0014102c\n"
        ".Lf140db4_00140e2b:\n"
        "movl %ebx, (%esp)\n" /* key */
        "calll ___tolower\n"
        "cmpl $0x6e, %eax\n"
        "je .Lf140db4_00141092\n"
        ".Lf140db4_00140e3c:\n"
        "cmpl $0xa4, %ebx\n" /* line 1056 | key */
        "je .Lf140db4_001412b1\n"
        "cmpl $0xa3, %ebx\n" /* line 1062 | key */
        "je .Lf140db4_001412d8\n"
        "cmpl $0xce, %ebx\n" /* line 1068 | key */
        "je .Lf140db4_00141294\n"
        "cmpl $0xcd, %ebx\n" /* line 1079 | key */
        "je .Lf140db4_001412bb\n"
        "cmpl $0xa5, %ebx\n" /* line 1091 | key */
        "je .Lf140db4_0014130b\n"
        "cmpl $0xa6, %ebx\n" /* line 1098 | key */
        "je .Lf140db4_00141336\n"
        ".Lf140db4_00140e84:\n"
        "movl %ebx, 4(%esp)\n" /* line 1105 | key */
        "movl $g_consoleField, (%esp)\n"
        "calll Field_KeyDownEvent\n"
        ".Lf140db4_00140e94:\n"
        "addl $0x56c, %esp\n" /* line 1106 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf140db4_00140e9f:\n"
        "movl imp_clc, %eax\n" /* line 955 */
        "movl (%eax), %eax\n"
        "cmpl $8, (%eax)\n"
        "je .Lf140db4_00140eff\n"
        "movzbl g_consoleField+24, %eax\n"
        "cmpb $0x5c, %al\n"
        "je .Lf140db4_00140eff\n"
        "cmpb $0x2f, %al\n"
        "je .Lf140db4_00140eff\n"
        /* { scope 1 */
        "movl $0x400, 8(%esp)\n" /* line 959 */
        "movl $g_consoleField+24, 4(%esp)\n"
        "leal -0x51c(%ebp), %ebx\n" /* temp, key */
        "movl %ebx, (%esp)\n" /* key */
        "calll I_strncpyz\n"
        "movl %ebx, 0xc(%esp)\n" /* line 960 | key */
        "movl $str_002a6fb8, 8(%esp)\n" /* "\%s" */
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll Com_sprintf\n"
        "addl $1, g_consoleField\n" /* line 961 */
        /* } scope */
        ".Lf140db4_00140eff:\n"
        "movl $g_consoleField+24, 4(%esp)\n" /* line 965 */
        "movl $str_00222d28, (%esp)\n" /* "]%s
" */
        "calll Com_Printf\n"
        "movzbl g_consoleField+24, %eax\n" /* line 974 */
        "cmpb $0x5c, %al\n"
        "je .Lf140db4_001410f4\n"
        "cmpb $0x2f, %al\n"
        "je .Lf140db4_001410f4\n"
        "testb %al, %al\n" /* line 982 */
        "je .Lf140db4_00140e94\n"
        "movl $4, 8(%esp)\n" /* line 927 */
        "movl $str_002a6fbc, 4(%esp)\n" /* "rcon" */
        "movl $g_consoleField+24, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n" /* line 986 */
        "jne .Lf140db4_001412e2\n"
        ".Lf140db4_00140f56:\n"
        "cmpb $0, g_consoleField+24\n" /* line 995 */
        "je .Lf140db4_00140faa\n"
        "movl nextHistoryLine, %ebx\n" /* line 997 | key */
        "movl %ebx, %eax\n" /* key */
        "andl $0x8000001f, %eax\n"
        "js .Lf140db4_00141328\n"
        ".Lf140db4_00140f72:\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal historyEditLines(, %edx, 8), %edx\n"
        "movl $0x118, 8(%esp)\n"
        "movl $g_consoleField, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "leal 1(%ebx), %eax\n" /* line 998 | key */
        "movl %eax, nextHistoryLine\n"
        "movl %eax, historyLine\n" /* line 999 */
        ".Lf140db4_00140faa:\n"
        "movl $g_consoleField, (%esp)\n" /* line 1007 */
        "calll Field_Clear\n"
        "movl imp_g_console_field_width, %eax\n" /* line 1009 */
        "movl (%eax), %eax\n"
        "movl %eax, g_consoleField+12\n"
        "movl imp_g_console_char_height, %eax\n" /* line 1010 */
        "movl (%eax), %eax\n"
        "movl %eax, g_consoleField+16\n"
        "movl $1, g_consoleField+20\n" /* line 1011 */
        "calll CL_AllLocalClientsDisconnected\n" /* line 1013 */
        "testb %al, %al\n"
        "je .Lf140db4_00140e94\n"
        "calll SCR_UpdateScreen\n" /* line 1014 */
        "addl $0x56c, %esp\n" /* line 1106 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf140db4_00140ff5:\n"
        "movl keys, %eax\n" /* line 941 */
        "movl 0x774(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf140db4_00140e02\n"
        "movl $str_002a6fb0, (%esp)\n" /* line 943 */
        "calll Cbuf_AddText\n"
        "jmp .Lf140db4_00140e94\n"
        ".Lf140db4_00141019:\n"
        "movl keys, %eax\n" /* line 1045 */
        "movl 0x780(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf140db4_00140e2b\n"
        ".Lf140db4_0014102c:\n"
        "movl historyLine, %eax\n" /* line 1047 */
        "cmpl nextHistoryLine, %eax\n"
        "je .Lf140db4_00140e94\n"
        "addl $1, %eax\n" /* line 1049 */
        "movl %eax, historyLine\n"
        "andl $0x8000001f, %eax\n" /* line 1050 */
        "js .Lf140db4_001410e6\n"
        ".Lf140db4_00141050:\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "leal historyEditLines(, %eax, 8), %eax\n"
        "movl $0x118, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $g_consoleField, (%esp)\n"
        "calll memcpy\n"
        "movl $g_consoleField, (%esp)\n" /* line 1051 */
        "calll Field_AdjustScroll\n"
        "addl $0x56c, %esp\n" /* line 1106 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf140db4_00141092:\n"
        "movl keys, %eax\n" /* line 1045 */
        "movl 0x774(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf140db4_00140e3c\n"
        "jmp .Lf140db4_0014102c\n"
        ".Lf140db4_001410a7:\n"
        "movl keys, %eax\n" /* line 1033 */
        "movl 0x780(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf140db4_00140e02\n"
        ".Lf140db4_001410ba:\n"
        "movl historyLine, %edx\n" /* line 1035 */
        "movl nextHistoryLine, %eax\n"
        "subl %edx, %eax\n"
        "cmpl $0x1f, %eax\n"
        "jg .Lf140db4_001410d9\n"
        "testl %edx, %edx\n"
        "jle .Lf140db4_001410d9\n"
        "subl $1, %edx\n" /* line 1037 */
        "movl %edx, historyLine\n"
        ".Lf140db4_001410d9:\n"
        "movl %edx, %eax\n" /* line 1039 */
        "andl $0x8000001f, %eax\n"
        "jns .Lf140db4_00141050\n"
        ".Lf140db4_001410e6:\n"
        "subl $1, %eax\n" /* line 1050 */
        "orl $0xffffffe0, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf140db4_00141050\n"
        ".Lf140db4_001410f4:\n"
        "movl $g_consoleField+25, (%esp)\n" /* line 976 */
        "calll Cbuf_AddText\n"
        "movl $str_002160e8, (%esp)\n" /* line 977 */
        "calll Cbuf_AddText\n"
        "jmp .Lf140db4_00140f56\n"
        ".Lf140db4_00141111:\n"
        "movl keys, %eax\n" /* line 1033 */
        "movl 0x774(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf140db4_00140e13\n"
        "jmp .Lf140db4_001410ba\n"
        ".Lf140db4_00141126:\n"
        "calll Con_TokenizeInput\n" /* line 867 */
        "movl %eax, completionString\n"
        "movl $0, matchCount\n" /* line 869 */
        "movb $0, shortestMatch\n" /* line 870 */
        "cmpb $0, (%eax)\n" /* line 872 */
        "je .Lf140db4_00140e94\n"
        "movl $FindMatches, (%esp)\n" /* line 875 */
        "calll Cmd_ForEach\n"
        "movl $0xffffffff, %esi\n" /* line 876 */
        "movl $shortestMatch, %edi\n"
        "cld\n"
        "movl %esi, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x548(%ebp)\n"
        "movl $FindMatches, (%esp)\n" /* line 877 */
        "calll Dvar_ForEach\n"
        "movl $shortestMatch, %edi\n" /* line 878 */
        "cld\n"
        "movl %esi, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x544(%ebp)\n"
        "movl matchCount, %ebx\n" /* line 880 */
        "testl %ebx, %ebx\n"
        "je .Lf140db4_00140e94\n"
        "leal -0x51c(%ebp), %eax\n" /* line 884 | temp */
        "movl $0x118, 8(%esp)\n"
        "movl $g_consoleField, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "subl $1, %ebx\n" /* line 886 */
        "je .Lf140db4_001411e0\n"
        "cmpb $0, hasExactMatch\n"
        "je .Lf140db4_00141353\n"
        "calll Con_AnySpaceAfterCommand\n"
        "testb %al, %al\n"
        "je .Lf140db4_00141353\n"
        ".Lf140db4_001411e0:\n"
        "movl $shortestMatch, 0xc(%esp)\n" /* line 888 */
        "movl $str_002a6fb8, 8(%esp)\n" /* "\%s" */
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll Com_sprintf\n"
        "calll Cmd_Argc\n" /* line 890 */
        "subl $1, %eax\n"
        "je .Lf140db4_0014141f\n"
        "movl completionString, %ebx\n" /* line 896 */
        "leal -0x504(%ebp), %eax\n" /* line 780 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 781 */
        "je .Lf140db4_0014151e\n"
        "cld\n" /* line 787 */
        "movl %esi, %ecx\n"
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %edx), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll I_strncat\n"
        ".Lf140db4_0014125b:\n"
        "calll Cmd_Argc\n" /* line 897 */
        "cmpl $2, %eax\n"
        "je .Lf140db4_00141440\n"
        ".Lf140db4_00141269:\n"
        "cld\n" /* line 905 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl $g_consoleField+24, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, g_consoleField\n"
        "movl $g_consoleField, (%esp)\n" /* line 906 */
        "calll Field_AdjustScroll\n"
        "jmp .Lf140db4_00140e94\n"
        ".Lf140db4_00141294:\n"
        "calll Con_PageUp\n" /* line 1070 */
        "movl keys, %eax\n" /* line 1071 */
        "movl 0x774(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf140db4_00140e94\n"
        "calll Con_PageUp\n" /* line 1073 */
        ".Lf140db4_001412b1:\n"
        "calll Con_PageUp\n" /* line 1074 */
        "jmp .Lf140db4_00140e94\n"
        ".Lf140db4_001412bb:\n"
        "calll Con_PageDown\n" /* line 1081 */
        "movl keys, %eax\n" /* line 1082 */
        "movl 0x774(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf140db4_00140e94\n"
        "calll Con_PageDown\n" /* line 1084 */
        ".Lf140db4_001412d8:\n"
        "calll Con_PageDown\n" /* line 1085 */
        "jmp .Lf140db4_00140e94\n"
        ".Lf140db4_001412e2:\n"
        "movl $str_002a6fc4, (%esp)\n" /* line 988 */
        "calll Cbuf_AddText\n"
        "movl $g_consoleField+24, (%esp)\n" /* line 989 */
        "calll Cbuf_AddText\n"
        "movl $str_002160e8, (%esp)\n" /* line 990 */
        "calll Cbuf_AddText\n"
        "jmp .Lf140db4_00140f56\n"
        ".Lf140db4_0014130b:\n"
        "movl keys, %eax\n" /* line 1091 */
        "movl 0x774(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf140db4_00140e84\n"
        "calll Con_Top\n" /* line 1093 */
        "jmp .Lf140db4_00140e94\n"
        ".Lf140db4_00141328:\n"
        "subl $1, %eax\n" /* line 997 */
        "orl $0xffffffe0, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf140db4_00140f72\n"
        ".Lf140db4_00141336:\n"
        "movl keys, %eax\n" /* line 1098 */
        "movl 0x774(%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf140db4_00140e84\n"
        "calll Con_Bottom\n" /* line 1100 */
        "jmp .Lf140db4_00140e94\n"
        ".Lf140db4_00141353:\n"
        "movl $shortestMatch, 0xc(%esp)\n" /* line 911 */
        "movl $str_002a6fb8, 8(%esp)\n" /* "\%s" */
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $g_consoleField+24, %edi\n" /* line 912 */
        "xorl %esi, %esi\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, g_consoleField\n"
        "movl completionString, %ebx\n" /* line 913 */
        "leal -0x504(%ebp), %eax\n" /* line 780 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 781 */
        "je .Lf140db4_00141418\n"
        "cld\n" /* line 787 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "movl %esi, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %edx), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll I_strncat\n"
        ".Lf140db4_001413db:\n"
        "movl $g_consoleField, (%esp)\n" /* line 914 */
        "calll Field_AdjustScroll\n"
        "movl $g_consoleField+24, 4(%esp)\n" /* line 916 */
        "movl $str_00222d28, (%esp)\n" /* "]%s
" */
        "calll Com_Printf\n"
        "movl $PrintMatches, (%esp)\n" /* line 918 */
        "calll Cmd_ForEach\n"
        "movl $PrintMatches, (%esp)\n" /* line 919 */
        "calll Dvar_ForEach\n"
        "jmp .Lf140db4_00140e94\n"
        ".Lf140db4_00141418:\n"
        "calll keyConcatArgs\n" /* line 783 */
        "jmp .Lf140db4_001413db\n"
        ".Lf140db4_0014141f:\n"
        "movl $str_00217914, 8(%esp)\n" /* line 892 */
        "movl $0x100, 4(%esp)\n"
        "movl $g_consoleField+24, (%esp)\n"
        "calll I_strncat\n"
        "jmp .Lf140db4_00141269\n"
        ".Lf140db4_00141440:\n"
        "movl -0x544(%ebp), %edx\n" /* line 899 */
        "cmpl %edx, -0x548(%ebp)\n"
        "je .Lf140db4_00141528\n"
        "calll Con_TokenizeInput\n" /* line 844 */
        "movl %eax, (%esp)\n" /* line 845 */
        "calll Dvar_FindVar\n"
        "movl %eax, %ebx\n"
        "cmpb $6, 6(%eax)\n" /* line 847 */
        "jne .Lf140db4_00141269\n"
        "movl $1, (%esp)\n" /* line 850 */
        "calll Cmd_Argv\n"
        "movl %eax, %esi\n"
        "cmpb $0, (%eax)\n" /* line 851 */
        "je .Lf140db4_00141269\n"
        "movl $0x100, 0x10(%esp)\n" /* line 854 */
        "leal -0x11c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x18(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Con_AutoCompleteFromList\n"
        "movl $0xffffffff, %edx\n" /* line 855 */
        "xorl %eax, %eax\n"
        "cld\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x538(%ebp)\n"
        "cmpb $0, -0x11c(%ebp)\n" /* line 798 */
        "je .Lf140db4_00141269\n"
        "movl %edx, %ecx\n" /* line 801 */
        "movl $g_consoleField+24, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, %eax\n" /* line 802 */
        "subl $1, %eax\n"
        "movl %eax, -0x534(%ebp)\n"
        "jne .Lf140db4_001415ff\n"
        "xorl %edi, %edi\n"
        ".Lf140db4_001414ee:\n"
        "movl %edi, %edx\n" /* line 806 */
        "subl -0x538(%ebp), %edx\n"
        ".Lf140db4_001414f6:\n"
        "movl $0x100, %eax\n" /* line 807 */
        "subl %edx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x11c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "addl $g_consoleField+24, %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf140db4_00141269\n"
        ".Lf140db4_0014151e:\n"
        "calll keyConcatArgs\n" /* line 783 */
        "jmp .Lf140db4_0014125b\n"
        ".Lf140db4_00141528:\n"
        "calll Con_TokenizeInput\n" /* line 820 */
        "movl %eax, %ebx\n"
        "movl $1, (%esp)\n" /* line 821 */
        "calll Cmd_Argv\n"
        "movl %eax, %esi\n"
        "cmpb $0, (%eax)\n" /* line 822 */
        "je .Lf140db4_00141269\n"
        "movl $0xa, 8(%esp)\n" /* line 825 */
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Cmd_GetAutoCompleteFileList\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 826 */
        "testl %eax, %eax\n"
        "je .Lf140db4_00141269\n"
        "movl $0x100, 0x10(%esp)\n" /* line 829 */
        "leal -0x11c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Con_AutoCompleteFromList\n"
        "movl $0xa, 4(%esp)\n" /* line 830 */
        "movl %ebx, (%esp)\n"
        "calll FS_FreeFileList\n"
        "leal -0x11c(%ebp), %eax\n" /* line 831 */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_StripExtension\n"
        "movl $0xffffffff, %edx\n" /* line 832 */
        "xorl %eax, %eax\n"
        "cld\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x540(%ebp)\n"
        "cmpb $0, -0x11c(%ebp)\n" /* line 798 */
        "je .Lf140db4_00141269\n"
        "movl %edx, %ecx\n" /* line 801 */
        "movl $g_consoleField+24, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, %eax\n" /* line 802 */
        "subl $1, %eax\n"
        "movl %eax, -0x53c(%ebp)\n"
        "jne .Lf140db4_00141673\n"
        "xorl %edi, %edi\n"
        ".Lf140db4_001415f2:\n"
        "movl %edi, %edx\n" /* line 806 */
        "subl -0x540(%ebp), %edx\n"
        "jmp .Lf140db4_001414f6\n"
        ".Lf140db4_001415ff:\n"
        "leal 0xf(%ecx), %eax\n" /* line 802 */
        "leal g_consoleField+8(%eax), %esi\n"
        "movl -0x534(%ebp), %ebx\n"
        "movl $0, -0x52c(%ebp)\n"
        "subl %eax, %ecx\n"
        "addl $0xe, %ecx\n"
        "movl %ecx, -0x550(%ebp)\n"
        ".Lf140db4_00141623:\n"
        "leal -1(%ebx), %edi\n"
        "movl -0x550(%ebp), %edx\n"
        "movsbl (%edx, %esi), %eax\n"
        "testl $0xffffff80, %eax\n" /* line 220 */
        "jne .Lf140db4_001416e6\n"
        "movl __DefaultRuneLocale, %edx\n"
        "movl 0x34(%edx, %eax, 4), %eax\n"
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        ".Lf140db4_0014164b:\n"
        "testl %eax, %eax\n" /* line 802 */
        "je .Lf140db4_001416df\n"
        "addl $1, -0x52c(%ebp)\n"
        "subl $1, %esi\n"
        "movl -0x52c(%ebp), %edx\n"
        "cmpl %edx, -0x534(%ebp)\n"
        "je .Lf140db4_001414ee\n"
        "movl %edi, %ebx\n"
        "jmp .Lf140db4_00141623\n"
        ".Lf140db4_00141673:\n"
        "leal 0xf(%ecx), %eax\n"
        "leal g_consoleField+8(%eax), %esi\n"
        "movl -0x53c(%ebp), %ebx\n"
        "movl $0, -0x530(%ebp)\n"
        "subl %eax, %ecx\n"
        "addl $0xe, %ecx\n"
        "movl %ecx, -0x54c(%ebp)\n"
        ".Lf140db4_00141697:\n"
        "leal -1(%ebx), %edi\n"
        "movl -0x54c(%ebp), %edx\n"
        "movsbl (%edx, %esi), %eax\n"
        "testl $0xffffff80, %eax\n" /* line 220 */
        "jne .Lf140db4_0014170a\n"
        "movl __DefaultRuneLocale, %edx\n"
        "movl 0x34(%edx, %eax, 4), %eax\n"
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        ".Lf140db4_001416bb:\n"
        "testl %eax, %eax\n" /* line 802 */
        "je .Lf140db4_00141703\n"
        "addl $1, -0x530(%ebp)\n"
        "subl $1, %esi\n"
        "movl -0x530(%ebp), %edx\n"
        "cmpl %edx, -0x53c(%ebp)\n"
        "je .Lf140db4_001415f2\n"
        "movl %edi, %ebx\n"
        "jmp .Lf140db4_00141697\n"
        ".Lf140db4_001416df:\n"
        "movl %ebx, %edi\n"
        "jmp .Lf140db4_001414ee\n"
        ".Lf140db4_001416e6:\n"
        "movl $0x4000, 4(%esp)\n" /* line 220 */
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf140db4_0014164b\n"
        ".Lf140db4_00141703:\n"
        "movl %ebx, %edi\n" /* line 802 */
        "jmp .Lf140db4_001415f2\n"
        ".Lf140db4_0014170a:\n"
        "movl $0x4000, 4(%esp)\n" /* line 220 */
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf140db4_001416bb\n"
    );
}

/* line 1504 */
__attribute__((naked))
void Key_WriteBindings(fileHandle_t f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1504 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl $str_002162f4, 4(%esp)\n" /* line 1509 */
        "movl 8(%ebp), %eax\n" /* f */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %edi, %edi\n"
        ".Lf141724_00141744:\n"
        "movl keys, %eax\n" /* line 1513 */
        "movl 8(%eax, %edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf141724_001417fd\n"
        "cmpb $0, (%eax)\n"
        "je .Lf141724_001417fd\n"
        /* { scope 2 */
        "cmpl $-1, %esi\n" /* line 1275 */
        "je .Lf141724_001418bd\n"
        "cmpl $0xff, %esi\n" /* line 1278 */
        "jbe .Lf141724_00141817\n"
        "movl $str_002a6ec0, %ecx\n" /* "<OUT OF RANGE>" */
        /* } scope */
        ".Lf141724_00141778:\n"
        "movl %ecx, 8(%esp)\n" /* line 1515 */
        "movl $str_002a6fd0, 4(%esp)\n" /* "bind %s "" */
        "movl 8(%ebp), %eax\n" /* f */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "movl keys, %eax\n" /* line 1516 */
        "movl 8(%eax, %edi), %edx\n"
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf141724_001417ea\n"
        "movl %edx, %ebx\n"
        "jmp .Lf141724_001417c8\n"
        ".Lf141724_001417a3:\n"
        "movsbl %al, %eax\n" /* line 1521 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002a6fe0, 4(%esp)\n" /* "%c" */
        "movl 8(%ebp), %eax\n" /* f */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "movzbl 1(%ebx), %eax\n" /* line 1516 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "je .Lf141724_001417ea\n"
        ".Lf141724_001417c8:\n"
        "cmpb $0x22, %al\n" /* line 1518 */
        "jne .Lf141724_001417a3\n"
        "movl $str_002a6fdc, 4(%esp)\n" /* line 1519 */
        "movl 8(%ebp), %eax\n" /* f */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "movzbl 1(%ebx), %eax\n" /* line 1516 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf141724_001417c8\n"
        ".Lf141724_001417ea:\n"
        "movl $str_002a6fe4, 4(%esp)\n" /* line 1523 */
        "movl 8(%ebp), %eax\n" /* f */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        ".Lf141724_001417fd:\n"
        "addl $1, %esi\n" /* line 1511 | i */
        "addl $0xc, %edi\n"
        "cmpl $0x100, %esi\n" /* i */
        "jne .Lf141724_00141744\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1527 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf141724_00141817:\n"
        "leal -0x21(%esi), %eax\n" /* line 1286 */
        "cmpl $0x5d, %eax\n"
        "ja .Lf141724_00141848\n"
        "cmpl $0x22, %esi\n"
        "je .Lf141724_00141848\n"
        "movl %esi, (%esp)\n" /* line 1288 */
        "calll ___toupper\n"
        "movb %al, tinystr\n"
        "movb $0, tinystr+1\n" /* line 1289 */
        "cmpl $0x3b, %esi\n" /* line 1290 */
        "je .Lf141724_00141848\n"
        "movl $tinystr, %ecx\n" /* line 1334 */
        "jmp .Lf141724_00141778\n"
        ".Lf141724_00141848:\n"
        "movl keynames, %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "je .Lf141724_00141879\n"
        "cmpl %esi, keynames+4\n" /* line 1322 */
        "je .Lf141724_00141778\n"
        "movl $keynames+8, %edx\n" /* line 1504 */
        "jmp .Lf141724_00141873\n"
        ".Lf141724_00141865:\n"
        "movl 4(%edx), %eax\n" /* line 1322 */
        "addl $8, %edx\n"
        "cmpl %esi, %eax\n"
        "je .Lf141724_00141778\n"
        ".Lf141724_00141873:\n"
        "movl (%edx), %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "jne .Lf141724_00141865\n"
        ".Lf141724_00141879:\n"
        "movl %esi, %eax\n" /* line 1327 */
        "sarl $4, %eax\n"
        "movl %esi, %edx\n" /* line 1328 */
        "andl $0xf, %edx\n"
        "movb $0x30, tinystr\n" /* line 1330 */
        "movb $0x78, tinystr+1\n" /* line 1331 */
        "cmpl $9, %eax\n" /* line 1332 */
        "jle .Lf141724_001418cc\n"
        "addb $0x57, %al\n"
        ".Lf141724_00141898:\n"
        "movb %al, tinystr+2\n"
        "cmpl $9, %edx\n" /* line 1333 */
        "jle .Lf141724_001418c7\n"
        "leal 0x57(%edx), %eax\n"
        ".Lf141724_001418a6:\n"
        "movb %al, tinystr+3\n"
        "movb $0, tinystr+4\n" /* line 1334 */
        "movl $tinystr, %ecx\n"
        "jmp .Lf141724_00141778\n"
        ".Lf141724_001418bd:\n"
        "movl $str_002a6eb0, %ecx\n" /* line 1275 */
        "jmp .Lf141724_00141778\n"
        ".Lf141724_001418c7:\n"
        "leal 0x30(%edx), %eax\n" /* line 1333 */
        "jmp .Lf141724_001418a6\n"
        ".Lf141724_001418cc:\n"
        "addb $0x30, %al\n" /* line 1332 */
        "jmp .Lf141724_00141898\n"
    );
}

/* line 1592 */
__attribute__((naked))
void Key_Bindlist_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1592 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "xorl %esi, %esi\n"
        "xorl %edi, %edi\n"
        "jmp .Lf1418d0_0014190a\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1418d0_001418df:\n"
        "movl $str_002a6ec0, %ecx\n" /* line 1278 */
        /* } scope */
        ".Lf1418d0_001418e4:\n"
        "movl %ebx, 8(%esp)\n" /* line 1600 */
        "movl %ecx, 4(%esp)\n"
        "movl $str_00219570, (%esp)\n" /* "%s "%s"
" */
        "calll Com_Printf\n"
        ".Lf1418d0_001418f8:\n"
        "addl $1, %esi\n" /* line 1596 | i */
        "addl $0xc, %edi\n"
        "cmpl $0x100, %esi\n" /* i */
        "je .Lf1418d0_001419e3\n"
        ".Lf1418d0_0014190a:\n"
        "movl keys, %eax\n" /* line 1598 */
        "movl 8(%eax, %edi), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf1418d0_001418f8\n"
        "cmpb $0, (%ebx)\n"
        "je .Lf1418d0_001418f8\n"
        /* { scope 2 */
        "cmpl $-1, %esi\n" /* line 1275 */
        "je .Lf1418d0_001419d0\n"
        "cmpl $0xff, %esi\n" /* line 1278 */
        "ja .Lf1418d0_001418df\n"
        "leal -0x21(%esi), %eax\n" /* line 1286 */
        "cmpl $0x5d, %eax\n"
        "ja .Lf1418d0_0014195b\n"
        "cmpl $0x22, %esi\n"
        "je .Lf1418d0_0014195b\n"
        "movl %esi, (%esp)\n" /* line 1288 */
        "calll ___toupper\n"
        "movb %al, tinystr\n"
        "movb $0, tinystr+1\n" /* line 1289 */
        "cmpl $0x3b, %esi\n" /* line 1290 */
        "je .Lf1418d0_0014195b\n"
        "movl $tinystr, %ecx\n" /* line 1334 */
        "jmp .Lf1418d0_001418e4\n"
        ".Lf1418d0_0014195b:\n"
        "movl keynames, %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "je .Lf1418d0_0014198c\n"
        "cmpl %esi, keynames+4\n" /* line 1322 */
        "je .Lf1418d0_001418e4\n"
        "movl $keynames+8, %edx\n" /* line 1592 */
        "jmp .Lf1418d0_00141986\n"
        ".Lf1418d0_00141978:\n"
        "movl 4(%edx), %eax\n" /* line 1322 */
        "addl $8, %edx\n"
        "cmpl %esi, %eax\n"
        "je .Lf1418d0_001418e4\n"
        ".Lf1418d0_00141986:\n"
        "movl (%edx), %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "jne .Lf1418d0_00141978\n"
        ".Lf1418d0_0014198c:\n"
        "movl %esi, %eax\n" /* line 1327 */
        "sarl $4, %eax\n"
        "movl %esi, %edx\n" /* line 1328 */
        "andl $0xf, %edx\n"
        "movb $0x30, tinystr\n" /* line 1330 */
        "movb $0x78, tinystr+1\n" /* line 1331 */
        "cmpl $9, %eax\n" /* line 1332 */
        "jle .Lf1418d0_001419df\n"
        "addb $0x57, %al\n"
        ".Lf1418d0_001419ab:\n"
        "movb %al, tinystr+2\n"
        "cmpl $9, %edx\n" /* line 1333 */
        "jle .Lf1418d0_001419da\n"
        "leal 0x57(%edx), %eax\n"
        ".Lf1418d0_001419b9:\n"
        "movb %al, tinystr+3\n"
        "movb $0, tinystr+4\n" /* line 1334 */
        "movl $tinystr, %ecx\n"
        "jmp .Lf1418d0_001418e4\n"
        ".Lf1418d0_001419d0:\n"
        "movl $str_002a6eb0, %ecx\n" /* line 1275 */
        "jmp .Lf1418d0_001418e4\n"
        ".Lf1418d0_001419da:\n"
        "leal 0x30(%edx), %eax\n" /* line 1333 */
        "jmp .Lf1418d0_001419b9\n"
        ".Lf1418d0_001419df:\n"
        "addb $0x30, %al\n" /* line 1332 */
        "jmp .Lf1418d0_001419ab\n"
        /* } scope */
        /* } scope */
        ".Lf1418d0_001419e3:\n"
        "addl $0x1c, %esp\n" /* line 1603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1628 */
__attribute__((naked))
void CL_KeyEvent(int key, const qboolean down, const unsigned int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1628 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %esi\n" /* key */
        "movl 0xc(%ebp), %edi\n" /* down */
        /* { scope 1 */
        "leal (%esi, %esi, 2), %eax\n" /* line 1636 | key */
        "leal (, %eax, 4), %ebx\n"
        "movl keys, %eax\n"
        "movl %edi, (%ebx, %eax)\n" /* down */
        "testl %edi, %edi\n" /* line 1638 | down */
        "je .Lf1419ec_00141b71\n"
        "movl %ebx, %eax\n" /* line 1640 */
        "addl keys, %eax\n"
        "addl $1, 4(%eax)\n"
        "movl keys, %eax\n" /* line 1641 */
        "cmpl $1, 4(%ebx, %eax)\n"
        "je .Lf1419ec_00141cb7\n"
        ".Lf1419ec_00141a34:\n"
        "cmpl $0x60, %esi\n" /* line 1657 | key */
        "je .Lf1419ec_00141a50\n"
        "cmpl $0x7e, %esi\n" /* key */
        "je .Lf1419ec_00141a50\n"
        "movl imp_cl, %edx\n"
        "movl (%edx), %eax\n"
        "testb $1, 4(%eax)\n"
        "je .Lf1419ec_00141b8a\n"
        ".Lf1419ec_00141a50:\n"
        "testl %edi, %edi\n" /* line 1687 | down */
        "je .Lf1419ec_00141b51\n"
        "movl keys, %eax\n"
        ".Lf1419ec_00141a5d:\n"
        "cmpl $1, 4(%ebx, %eax)\n"
        "jle .Lf1419ec_00141b51\n"
        "movl imp_cl, %edx\n" /* line 1690 */
        "movl (%edx), %eax\n"
        "movl 4(%eax), %eax\n"
        "testb $0x11, %al\n"
        "jne .Lf1419ec_00141aa0\n"
        "testb $8, %al\n" /* line 1692 */
        "je .Lf1419ec_00141b46\n"
        "leal -0x9a(%esi), %ecx\n" /* line 1723 | key */
        "cmpl $0xa, %ecx\n"
        "ja .Lf1419ec_00141b46\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x603, %eax\n"
        "je .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141aa0:\n"
        "cmpl $0x60, %esi\n" /* line 1738 | key */
        "je .Lf1419ec_00141b46\n"
        "cmpl $0x7e, %esi\n" /* key */
        "je .Lf1419ec_00141b46\n"
        "cmpl $0x1b, %esi\n" /* line 1742 | key */
        "je .Lf1419ec_00141b46\n"
        "cmpl $0x7f, %esi\n" /* line 1807 | key */
        "jg .Lf1419ec_00141cc3\n"
        ".Lf1419ec_00141ac4:\n"
        "movl imp_clc, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x407a0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1419ec_00141d5d\n"
        "movl (%eax), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1419ec_00141d5d\n"
        "cmpl $2, %eax\n"
        "je .Lf1419ec_00141d5d\n"
        ".Lf1419ec_00141aed:\n"
        "cmpl $0x1b, %esi\n" /* line 1815 | key */
        "je .Lf1419ec_00141d21\n"
        ".Lf1419ec_00141af6:\n"
        "movl imp_cl, %edx\n" /* line 1881 */
        "movl (%edx), %eax\n"
        "cmpb $0, 9(%eax)\n"
        "jne .Lf1419ec_00141ce1\n"
        ".Lf1419ec_00141b08:\n"
        "testl %edi, %edi\n" /* line 1890 | down */
        "jne .Lf1419ec_00141c20\n"
        "movl keys, %eax\n" /* line 1892 */
        "movl 8(%ebx, %eax), %eax\n"
        "testl %eax, %eax\n" /* line 1893 */
        "je .Lf1419ec_00141b26\n"
        "cmpb $0x2b, (%eax)\n"
        "je .Lf1419ec_00141ea1\n"
        ".Lf1419ec_00141b26:\n"
        "movl imp_cl, %eax\n" /* line 1901 */
        "movl (%eax), %eax\n"
        "testb $8, 4(%eax)\n"
        "je .Lf1419ec_00141b46\n"
        "movl imp_cls, %eax\n"
        "movl 0x110(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1419ec_00141db7\n"
        /* } scope */
        ".Lf1419ec_00141b46:\n"
        "addl $0x42c, %esp\n" /* line 1972 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1419ec_00141b51:\n"
        "cmpl $0x60, %esi\n" /* line 1776 | key */
        "je .Lf1419ec_00141bdd\n"
        "cmpl $0x7e, %esi\n" /* key */
        "je .Lf1419ec_00141bdd\n"
        "testl %edi, %edi\n" /* line 1807 | down */
        "je .Lf1419ec_00141aed\n"
        "cmpl $0x7f, %esi\n" /* key */
        "jle .Lf1419ec_00141ac4\n"
        "jmp .Lf1419ec_00141cc3\n"
        ".Lf1419ec_00141b71:\n"
        "movl keys, %eax\n" /* line 1648 */
        "movl $0, 4(%ebx, %eax)\n"
        "subl $4, anykeydown\n" /* line 1649 */
        "jmp .Lf1419ec_00141a34\n"
        ".Lf1419ec_00141b8a:\n"
        "movl keys, %eax\n" /* line 1663 */
        "movl 8(%ebx, %eax), %eax\n"
        "testl %eax, %eax\n" /* line 1664 */
        "je .Lf1419ec_00141a50\n"
        "movl $str_00227174, 4(%esp)\n" /* "devgui" */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1419ec_00141a50\n"
        "testl %edi, %edi\n" /* down */
        "je .Lf1419ec_00141aed\n"
        "movl keys, %eax\n"
        "leal (%ebx, %eax), %edx\n"
        "cmpl $1, 4(%edx)\n"
        "jne .Lf1419ec_00141a5d\n"
        "movl 8(%edx), %eax\n" /* line 1666 */
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141bdd:\n"
        "testl %edi, %edi\n" /* line 1778 | down */
        "je .Lf1419ec_00141b46\n"
        "movl imp_cl, %eax\n" /* line 1784 */
        "movl (%eax), %eax\n"
        "testb $1, 4(%eax)\n"
        "je .Lf1419ec_00141cfa\n"
        ".Lf1419ec_00141bf6:\n"
        "movl keys, %eax\n" /* line 1789 */
        "movl 0x780(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1419ec_00141dad\n"
        "calll Con_IsActive\n" /* line 1791 */
        "testb %al, %al\n"
        "je .Lf1419ec_00141dcc\n"
        "calll Con_ToggleConsoleOutput\n" /* line 1793 */
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141c20:\n"
        "movl imp_cl_bypassMouseInput, %eax\n" /* line 1910 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1419ec_00141da6\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1419ec_00141da6\n"
        "leal -0xc8(%esi), %eax\n" /* line 1912 | key */
        "cmpl $2, %eax\n"
        "ja .Lf1419ec_00141d96\n"
        ".Lf1419ec_00141c48:\n"
        "movl $1, %edx\n" /* line 1916 */
        ".Lf1419ec_00141c4d:\n"
        "movl imp_cl, %eax\n" /* line 1923 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "testb $1, %al\n"
        "jne .Lf1419ec_00141d89\n"
        "testb $8, %al\n" /* line 1933 */
        "je .Lf1419ec_00141c6b\n"
        "testl %edx, %edx\n"
        "je .Lf1419ec_00141df0\n"
        ".Lf1419ec_00141c6b:\n"
        "testb $0x10, %al\n" /* line 1937 */
        "jne .Lf1419ec_00141e83\n"
        "movl imp_clc, %eax\n" /* line 1941 */
        "movl (%eax), %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1419ec_00141d89\n"
        "movl keys, %eax\n" /* line 1950 */
        "movl 8(%ebx, %eax), %eax\n"
        "testl %eax, %eax\n" /* line 1951 */
        "je .Lf1419ec_00141f18\n"
        "cmpb $0x2b, (%eax)\n" /* line 1958 */
        "je .Lf1419ec_00141ede\n"
        "movl %eax, (%esp)\n" /* line 1968 */
        "calll Cbuf_AddText\n"
        "movl $str_002160e8, (%esp)\n" /* line 1969 */
        "calll Cbuf_AddText\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141cb7:\n"
        "addl $4, anykeydown\n" /* line 1643 */
        "jmp .Lf1419ec_00141a34\n"
        ".Lf1419ec_00141cc3:\n"
        "cmpl $0xc8, %esi\n" /* line 1807 | key */
        "je .Lf1419ec_00141ac4\n"
        "movl imp_cl, %edx\n" /* line 1881 */
        "movl (%edx), %eax\n"
        "cmpb $0, 9(%eax)\n"
        "je .Lf1419ec_00141b08\n"
        ".Lf1419ec_00141ce1:\n"
        "movl %edi, 4(%esp)\n" /* down */
        "movl %esi, (%esp)\n" /* key */
        "calll CG_KeyInterceptEvent\n"
        "testl %eax, %eax\n"
        "je .Lf1419ec_00141b08\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141cfa:\n"
        "movl imp_com_sv_running, %eax\n" /* line 1784 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1419ec_00141bf6\n"
        "movl imp_sv_disableClientConsole, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1419ec_00141b46\n"
        "jmp .Lf1419ec_00141bf6\n"
        ".Lf1419ec_00141d21:\n"
        "testl %edi, %edi\n" /* line 1815 | down */
        "je .Lf1419ec_00141af6\n"
        ".Lf1419ec_00141d29:\n"
        "movl imp_cl, %edx\n" /* line 1828 */
        "movl (%edx), %eax\n"
        "movl 4(%eax), %eax\n"
        "testb $0x10, %al\n"
        "jne .Lf1419ec_00141e90\n"
        "testb $8, %al\n" /* line 1835 */
        "jne .Lf1419ec_00141ddb\n"
        "movl imp_clc, %eax\n" /* line 1837 */
        "movl (%eax), %edx\n"
        "cmpl $8, (%edx)\n"
        "ja .Lf1419ec_00141e01\n"
        "movl (%edx), %eax\n"
        "jmpl *yy_ec+2112(, %eax, 4)\n"
        ".Lf1419ec_00141d5d:\n"
        "movl imp_cl, %edx\n" /* line 1807 */
        "movl (%edx), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1419ec_00141aed\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 1810 */
        "movl imp_nextdemo, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf1419ec_00141d29\n"
        ".Lf1419ec_00141d89:\n"
        "movl %esi, (%esp)\n" /* line 1944 | key */
        "calll Console_Key\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141d96:\n"
        "movl %esi, (%esp)\n" /* line 1916 | key */
        "calll UI_checkKeyExec\n"
        "testl %eax, %eax\n"
        "je .Lf1419ec_00141c48\n"
        ".Lf1419ec_00141da6:\n"
        "xorl %edx, %edx\n"
        "jmp .Lf1419ec_00141c4d\n"
        ".Lf1419ec_00141dad:\n"
        "calll Con_ToggleConsole_f\n" /* line 1797 */
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141db7:\n"
        "movl $0, 4(%esp)\n" /* line 1903 */
        "movl %esi, (%esp)\n" /* key */
        "calll UI_KeyEvent\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141dcc:\n"
        "calll Con_ToggleConsole_f\n" /* line 1792 */
        "calll Con_ToggleConsoleOutput\n" /* line 1793 */
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141ddb:\n"
        "movl %edi, 4(%esp)\n" /* line 1876 | down */
        "movl $0x1b, (%esp)\n"
        "calll UI_KeyEvent\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141df0:\n"
        "movl %edi, 4(%esp)\n" /* line 1935 | down */
        "movl %esi, (%esp)\n" /* key */
        "calll UI_KeyEvent\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141e01:\n"
        "movl imp_cls, %eax\n" /* line 1869 */
        "movl 0x110(%eax), %esi\n" /* key */
        "testl %esi, %esi\n" /* key */
        "je .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141e14:\n"
        "movl $1, (%esp)\n" /* line 1870 */
        "calll UI_SetActiveMenu\n"
        "jmp .Lf1419ec_00141b46\n"
        "movl 0x407a0(%edx), %edi\n" /* line 1840 | down */
        "testl %edi, %edi\n" /* down */
        "jne .Lf1419ec_00141e14\n"
        "movl imp_legacyHacks, %eax\n" /* line 1843 */
        "movl (%eax), %eax\n"
        "cmpb $0, 0xdc(%eax)\n"
        "jne .Lf1419ec_00141e14\n"
        "movl $2, (%esp)\n" /* line 1846 */
        "calll UI_SetActiveMenu\n"
        "jmp .Lf1419ec_00141b46\n"
        "calll CL_StopLogoOrCinematic\n" /* line 1856 */
        "jmp .Lf1419ec_00141b46\n"
        "calll CL_Disconnect\n" /* line 1862 */
        "movl imp_com_sv_running, %eax\n" /* line 1864 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1419ec_00141b46\n"
        "movl imp_legacyHacks, %eax\n" /* line 1865 */
        "movl (%eax), %eax\n"
        "movb $1, 0xdd(%eax)\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141e83:\n"
        "movl %esi, (%esp)\n" /* line 1939 | key */
        "calll Message_Key\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141e90:\n"
        "movl $0x1b, (%esp)\n" /* line 1831 */
        "calll Message_Key\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141ea1:\n"
        "movl 0x10(%ebp), %edx\n" /* line 1897 | time */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* key */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a6fe8, 8(%esp)\n" /* "-%s %i %i
" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* cmd */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, (%esp)\n" /* line 1898 */
        "calll Cbuf_AddText\n"
        "jmp .Lf1419ec_00141b26\n"
        ".Lf1419ec_00141ede:\n"
        "movl 0x10(%ebp), %edx\n" /* line 1962 | time */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* key */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7020, 8(%esp)\n" /* "%s %i %i
" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* cmd */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, (%esp)\n" /* line 1963 */
        "calll Cbuf_AddText\n"
        "jmp .Lf1419ec_00141b46\n"
        ".Lf1419ec_00141f18:\n"
        "cmpl $0xc7, %esi\n" /* line 1953 | key */
        "jle .Lf1419ec_00141b46\n"
        /* { scope 2 */
        "cmpl $0xff, %esi\n" /* line 1278 */
        "jbe .Lf1419ec_00141f46\n"
        "movl $str_002a6ec0, %ecx\n" /* "<OUT OF RANGE>" */
        /* } scope */
        ".Lf1419ec_00141f31:\n"
        "movl %ecx, 4(%esp)\n" /* line 1955 */
        "movl $str_002a6ff4, (%esp)\n" /* "%s is unbound, use controls menu to set.
" */
        "calll Com_Printf\n"
        "jmp .Lf1419ec_00141b46\n"
        /* { scope 2 */
        ".Lf1419ec_00141f46:\n"
        "leal -0x21(%esi), %eax\n" /* line 1286 */
        "cmpl $0x5d, %eax\n"
        "jbe .Lf1419ec_00141fbb\n"
        "movl keynames, %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "je .Lf1419ec_00141f77\n"
        "cmpl keynames+4, %esi\n" /* line 1322 */
        "je .Lf1419ec_00141f31\n"
        "movl $keynames+8, %edx\n" /* line 1628 */
        "jmp .Lf1419ec_00141f71\n"
        ".Lf1419ec_00141f67:\n"
        "movl 4(%edx), %eax\n" /* line 1322 */
        "addl $8, %edx\n"
        "cmpl %eax, %esi\n"
        "je .Lf1419ec_00141f31\n"
        ".Lf1419ec_00141f71:\n"
        "movl (%edx), %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "jne .Lf1419ec_00141f67\n"
        ".Lf1419ec_00141f77:\n"
        "movl %esi, %edx\n" /* line 1327 */
        "sarl $4, %edx\n"
        "movl %esi, %eax\n" /* line 1328 */
        "andl $0xf, %eax\n"
        "movb $0x30, tinystr\n" /* line 1330 */
        "movb $0x78, tinystr+1\n" /* line 1331 */
        "cmpl $9, %edx\n" /* line 1332 */
        "jle .Lf1419ec_00141fde\n"
        "addb $0x57, %dl\n"
        ".Lf1419ec_00141f97:\n"
        "movb %dl, tinystr+2\n"
        "cmpl $9, %eax\n" /* line 1333 */
        "jle .Lf1419ec_00141fda\n"
        "addb $0x57, %al\n"
        ".Lf1419ec_00141fa4:\n"
        "movb %al, tinystr+3\n"
        "movb $0, tinystr+4\n" /* line 1334 */
        "movl $tinystr, %ecx\n"
        "jmp .Lf1419ec_00141f31\n"
        ".Lf1419ec_00141fbb:\n"
        "movl %esi, (%esp)\n" /* line 1288 */
        "calll ___toupper\n"
        "movb %al, tinystr\n"
        "movb $0, tinystr+1\n" /* line 1289 */
        "movl $tinystr, %ecx\n"
        "jmp .Lf1419ec_00141f31\n"
        ".Lf1419ec_00141fda:\n"
        "addb $0x30, %al\n" /* line 1333 */
        "jmp .Lf1419ec_00141fa4\n"
        ".Lf1419ec_00141fde:\n"
        "addb $0x30, %dl\n" /* line 1332 */
        "jmp .Lf1419ec_00141f97\n"
    );
}

/* line 2018 */
__attribute__((naked))
void Key_ClearStates(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2018 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl anykeydown, %eax\n" /* line 2022 */
        "movl $0, (%eax)\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %ebx, %ebx\n"
        "jmp .Lf141fe4_0014201f\n"
        ".Lf141fe4_00141ffd:\n"
        "movl $0, (%ebx, %eax)\n" /* line 2035 */
        "movl keys, %eax\n" /* line 2036 */
        "movl $0, 4(%ebx, %eax)\n"
        "addl $1, %esi\n" /* line 2024 | i */
        "addl $0xc, %ebx\n"
        "cmpl $0x100, %esi\n" /* i */
        "je .Lf141fe4_0014206a\n"
        ".Lf141fe4_0014201f:\n"
        "movl keys, %eax\n" /* line 2026 */
        "movl (%ebx, %eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf141fe4_00141ffd\n"
        "movl $0, 8(%esp)\n" /* line 2031 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll CL_KeyEvent\n"
        "movl keys, %eax\n"
        "movl $0, (%ebx, %eax)\n" /* line 2035 */
        "movl keys, %eax\n" /* line 2036 */
        "movl $0, 4(%ebx, %eax)\n"
        "addl $1, %esi\n" /* line 2024 | i */
        "addl $0xc, %ebx\n"
        "cmpl $0x100, %esi\n" /* i */
        "jne .Lf141fe4_0014201f\n"
        /* } scope */
        ".Lf141fe4_0014206a:\n"
        "addl $0x10, %esp\n" /* line 2038 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

