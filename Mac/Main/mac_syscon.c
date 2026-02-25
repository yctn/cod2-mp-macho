/* ASM dump from: mac_syscon.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_syscon.cpp */

#include "common_types.h"
#include "imports.h"

extern Boolean gConsoleRunning; /* 0x0 */
static Handle sConsoleData; /* 0x7f1708 */
static WindowRef sConsoleWindow; /* 0x7f170c */
static TXNObject sConsoleTextView; /* 0x7f1704 */
static ControlRef sConsoleEditText; /* 0x7f1700 */
static char sConsoleText[512]; /* 0x7f1920 */
static char sReturnedText[512]; /* 0x7f1720 */
static EventLoopTimerRef sTimerRef; /* 0x7f1b20 */

static Boolean EditTextHook(ControlRef inControl, int inCharCode);
Boolean BuilderCallback(WindowRef theWindow, UInt32 theCommandID);
static JCOEF TimerCallback(EventLoopTimerRef inTimerRef, JCOEF *inUserData);
static JCOEF CreateConsoleWindow(void);
JCOEF Sys_CreateConsole(HINSTANCE hInstance);
JCOEF Sys_DestroyConsole(void);
JCOEF Sys_ShowConsole(int visLevel, qboolean quitOnClose);
char * Sys_ConsoleInput(void);
JCOEF Conbuf_AppendText(const char *pMsg);
JCOEF Sys_SetErrorText(const char *buf);

/* line 104 */
static __attribute__((naked))
Boolean EditTextHook(ControlRef inControl, int inCharCode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* inCharCode */
        "cmpw $0xd, %ax\n" /* line 106 */
        "je .Lfc489c_000c48ba\n"
        "cmpw $0xa, %ax\n"
        "je .Lfc489c_000c48ba\n"
        "xorl %eax, %eax\n"
        "addl $0x14, %esp\n" /* line 123 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc489c_000c48ba:\n"
        "movl $sConsoleText, 0xc(%esp)\n" /* line 108 */
        "movl $0x200, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl sConsoleWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_GetControlText\n"
        "cmpb $0, sConsoleText\n" /* line 109 */
        "jne .Lfc489c_000c48f3\n"
        ".Lfc489c_000c48e8:\n"
        "movl $1, %eax\n" /* line 115 */
        "addl $0x14, %esp\n" /* line 123 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc489c_000c48f3:\n"
        "movl $sConsoleText, 4(%esp)\n" /* line 111 */
        "movl $0x222d28, (%esp)\n" /* "]%s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Sys_Print\n"
        "movl $sConsoleText, %edi\n" /* line 113 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movw $0xa, 0x7f191f(%ecx)\n"
        "movl $0x2157b8, 8(%esp)\n" /* line 115 */
        "movl $2, 4(%esp)\n"
        "movl sConsoleWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_SetControlText\n"
        "jmp .Lfc489c_000c48e8\n"
    );
}

/* line 128 */
__attribute__((naked))
Boolean BuilderCallback(WindowRef theWindow, UInt32 theCommandID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 128 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "cmpl $0x636c6f73, 0xc(%ebp)\n" /* line 130 | theCommandID */
        "je .Lfc4948_000c495b\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 139 */
        "retl\n"
        ".Lfc4948_000c495b:\n"
        "calll CMacGameEngine_Quit\n" /* line 132 */
        "movl $1, %eax\n"
        "leave\n" /* line 139 */
        "retl\n"
    );
}

/* line 147 */
static __attribute__((naked))
JCOEF TimerCallback(EventLoopTimerRef inTimerRef, JCOEF *inUserData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 147 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, (%esp)\n" /* line 149 */
        "calll UpdateSystemActivity\n"
        "leave\n" /* line 150 */
        "retl\n"
    );
}

/* line 156 */
static __attribute__((naked))
JCOEF CreateConsoleWindow(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 156 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "calll MacDisplay_ReleaseDisplay\n" /* line 163 */
        "calll MacGlobals_LockSystem\n" /* line 167 */
        "movl $BuilderCallback, 0xc(%esp)\n" /* line 169 */
        "movl $1, 8(%esp)\n"
        "movl $0x32e7e4, 4(%esp)\n"
        "movl $0x32e7e4, (%esp)\n"
        "calll MacBuilder_BuildWindow\n"
        "movl %eax, sConsoleWindow\n"
        "testl %eax, %eax\n" /* line 170 */
        "je .Lfc497c_000c4adc\n"
        "movl $0x32e7f4, 4(%esp)\n" /* line 175 */
        "movl %eax, (%esp)\n"
        "calll SetWindowTitleWithCFString\n"
        "movl $1, 4(%esp)\n" /* line 177 */
        "movl sConsoleWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_GetTextObject\n"
        "movl %eax, sConsoleTextView\n"
        "testl %eax, %eax\n" /* line 179 */
        "je .Lfc497c_000c4a10\n"
        "movl $9, 0xc(%esp)\n" /* line 181 */
        "movl $4, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl sConsoleWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_SetTextObjectFontStyle\n"
        ".Lfc497c_000c4a10:\n"
        "movl $2, 4(%esp)\n" /* line 184 */
        "movl sConsoleWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_GetControlRef\n"
        "movl %eax, sConsoleEditText\n"
        "testl %eax, %eax\n" /* line 186 */
        "je .Lfc497c_000c4ac1\n"
        "movl $0xa, 0xc(%esp)\n" /* line 188 */
        "movl $4, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl sConsoleWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_SetControlFontStyle\n"
        "movl $0, 0xc(%esp)\n" /* line 190 */
        "movl $EditTextHook, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl sConsoleWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_SetEditTextHook\n"
        "movl sConsoleData, %eax\n" /* line 192 */
        "testl %eax, %eax\n"
        "je .Lfc497c_000c4ac1\n"
        "movl %eax, (%esp)\n" /* line 194 */
        "calll GetHandleSize\n"
        "movl $0x7fffffff, 0x14(%esp)\n"
        "movl $0x7fffffff, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl sConsoleData, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x54455854, 4(%esp)\n"
        "movl sConsoleTextView, %eax\n"
        "movl %eax, (%esp)\n"
        "calll TXNSetData\n"
        ".Lfc497c_000c4ac1:\n"
        "movl 0x195ec98, %eax\n" /* line 202 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc497c_000c4adc\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfc497c_000c4adc\n"
        "movl sTimerRef, %eax\n" /* line 204 */
        "testl %eax, %eax\n"
        "je .Lfc497c_000c4ade\n"
        ".Lfc497c_000c4adc:\n"
        "leave\n" /* line 211 */
        "retl\n"
        ".Lfc497c_000c4ade:\n"
        "calll GetMainEventLoop\n" /* line 207 */
        "movl $sTimerRef, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $TimerCallback, 0x14(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x403e0000, 0x10(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InstallEventLoopTimer\n"
        "leave\n" /* line 211 */
        "retl\n"
    );
}

/* line 215 */
__attribute__((naked))
JCOEF Sys_CreateConsole(HINSTANCE hInstance)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 215 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl sConsoleData, %ecx\n" /* line 217 */
        "testl %ecx, %ecx\n"
        "je .Lfc4b26_000c4b46\n"
        "movb $0, sConsoleText\n" /* line 222 */
        "movb $0, sReturnedText\n" /* line 223 */
        "leave\n" /* line 224 */
        "retl\n"
        ".Lfc4b26_000c4b46:\n"
        "movl $0, (%esp)\n" /* line 219 */
        "calll NewHandle\n"
        "movl %eax, sConsoleData\n"
        "movb $0, sConsoleText\n" /* line 222 */
        "movb $0, sReturnedText\n" /* line 223 */
        "leave\n" /* line 224 */
        "retl\n"
    );
}

/* line 228 */
__attribute__((naked))
JCOEF Sys_DestroyConsole(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 228 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl sConsoleWindow, %eax\n" /* line 230 */
        "testl %eax, %eax\n"
        "je .Lfc4b68_000c4b89\n"
        "movl %eax, (%esp)\n" /* line 232 */
        "calll MacBuilder_ReleaseWindow\n"
        "movl $0, sConsoleWindow\n" /* line 233 */
        ".Lfc4b68_000c4b89:\n"
        "movl sConsoleData, %eax\n" /* line 236 */
        "testl %eax, %eax\n"
        "je .Lfc4b68_000c4ba4\n"
        "movl %eax, (%esp)\n" /* line 238 */
        "calll DisposeHandle\n"
        "movl $0, sConsoleData\n" /* line 239 */
        ".Lfc4b68_000c4ba4:\n"
        "movl sTimerRef, %eax\n" /* line 243 */
        "testl %eax, %eax\n"
        "je .Lfc4b68_000c4bbf\n"
        "movl %eax, (%esp)\n" /* line 245 */
        "calll RemoveEventLoopTimer\n"
        "movl $0, sTimerRef\n" /* line 246 */
        ".Lfc4b68_000c4bbf:\n"
        "leave\n" /* line 249 */
        "retl\n"
    );
}

/* line 253 */
__attribute__((naked))
JCOEF Sys_ShowConsole(int visLevel, qboolean quitOnClose)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 253 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* visLevel */
        "movb $0, gConsoleRunning\n" /* line 255 */
        "cmpl $1, %eax\n" /* line 260 */
        "je .Lfc4bc2_000c4c02\n"
        "cmpl $2, %eax\n"
        "je .Lfc4bc2_000c4c53\n"
        "testl %eax, %eax\n"
        "je .Lfc4bc2_000c4bf0\n"
        "movl %eax, 0xc(%ebp)\n" /* line 309 | quitOnClose */
        "movl $0x222d5c, 8(%ebp)\n" /* visLevel */
        "leave\n" /* line 313 */
        "jmp Sys_Error\n" /* line 309 */
        ".Lfc4bc2_000c4bf0:\n"
        "movl sConsoleWindow, %eax\n" /* line 264 */
        "testl %eax, %eax\n"
        "je .Lfc4bc2_000c4c51\n"
        "movl %eax, 8(%ebp)\n" /* line 266 | visLevel */
        "leave\n" /* line 313 */
        "jmp HideWindow\n" /* line 266 */
        ".Lfc4bc2_000c4c02:\n"
        "movl sConsoleWindow, %edx\n" /* line 273 */
        "testl %edx, %edx\n"
        "je .Lfc4bc2_000c4cb2\n"
        ".Lfc4bc2_000c4c10:\n"
        "movl $0xfffffffe, 8(%esp)\n" /* line 280 */
        "movl sConsoleEditText, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SetKeyboardFocus\n"
        "movl sConsoleWindow, %eax\n" /* line 281 */
        "movl %eax, (%esp)\n"
        "calll ShowWindow\n"
        "movl $0, 4(%esp)\n" /* line 282 */
        "movl $0, (%esp)\n"
        "calll MacTools_ShowCursor\n"
        "movb $1, gConsoleRunning\n" /* line 283 */
        ".Lfc4bc2_000c4c51:\n"
        "leave\n" /* line 313 */
        "retl\n"
        ".Lfc4bc2_000c4c53:\n"
        "movl sConsoleWindow, %eax\n" /* line 290 */
        "testl %eax, %eax\n"
        "je .Lfc4bc2_000c4ca2\n"
        ".Lfc4bc2_000c4c5c:\n"
        "movl %eax, (%esp)\n" /* line 297 */
        "calll IsWindowVisible\n"
        "testb %al, %al\n"
        "je .Lfc4bc2_000c4c7f\n"
        ".Lfc4bc2_000c4c68:\n"
        "movl $1, 4(%esp)\n" /* line 302 */
        "movl sConsoleWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CollapseWindow\n"
        "leave\n" /* line 313 */
        "retl\n"
        ".Lfc4bc2_000c4c7f:\n"
        "movl sConsoleWindow, %eax\n" /* line 299 */
        "movl %eax, (%esp)\n"
        "calll ShowWindow\n"
        "movl $0, 4(%esp)\n" /* line 300 */
        "movl $0, (%esp)\n"
        "calll MacTools_ShowCursor\n"
        "jmp .Lfc4bc2_000c4c68\n"
        ".Lfc4bc2_000c4ca2:\n"
        "calll CreateConsoleWindow\n" /* line 292 */
        "movl sConsoleWindow, %eax\n" /* line 295 */
        "testl %eax, %eax\n"
        "jne .Lfc4bc2_000c4c5c\n"
        "jmp .Lfc4bc2_000c4c51\n"
        ".Lfc4bc2_000c4cb2:\n"
        "calll CreateConsoleWindow\n" /* line 275 */
        "movl sConsoleWindow, %edx\n" /* line 278 */
        "testl %edx, %edx\n"
        "jne .Lfc4bc2_000c4c10\n"
        "leave\n" /* line 313 */
        "retl\n"
    );
}

/* line 317 */
__attribute__((naked))
char * Sys_ConsoleInput(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 317 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpb $0, sConsoleText\n" /* line 319 */
        "jne .Lfc4cc8_000c4cdb\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 328 */
        "retl\n"
        ".Lfc4cc8_000c4cdb:\n"
        "movl $sConsoleText, 4(%esp)\n" /* line 324 */
        "movl $sReturnedText, (%esp)\n"
        "calll strcpy\n"
        "movb $0, sConsoleText\n" /* line 325 */
        "movl $sReturnedText, %eax\n"
        "leave\n" /* line 328 */
        "retl\n"
    );
}

/* line 332 */
__attribute__((naked))
JCOEF Conbuf_AppendText(const char *pMsg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 332 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %edx\n" /* pMsg */
        "testl %edx, %edx\n" /* line 334 */
        "je .Lfc4cfe_000c4d62\n"
        "movl sConsoleWindow, %ebx\n" /* line 339 */
        "testl %ebx, %ebx\n"
        "je .Lfc4cfe_000c4da2\n"
        "movl sConsoleTextView, %ebx\n" /* line 348 */
        "testl %ebx, %ebx\n"
        "je .Lfc4cfe_000c4d62\n"
        /* { scope 1 */
        "movl $0x7fffffff, 0x14(%esp)\n" /* line 350 */
        "movl $0x7fffffff, 0x10(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n" /* error */
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n" /* error */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x54455854, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll TXNSetData\n"
        "testl %eax, %eax\n" /* line 351 */
        "je .Lfc4cfe_000c4d69\n"
        /* } scope */
        ".Lfc4cfe_000c4d62:\n"
        "addl $0x20, %esp\n" /* line 357 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc4cfe_000c4d69:\n"
        "movl $0x7fffffff, 8(%esp)\n" /* line 353 */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl sConsoleTextView, %eax\n"
        "movl %eax, (%esp)\n"
        "calll TXNSetSelection\n"
        "movl $1, 4(%esp)\n" /* line 354 */
        "movl sConsoleTextView, %eax\n"
        "movl %eax, (%esp)\n"
        "calll TXNShowSelection\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 357 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc4cfe_000c4da2:\n"
        "movl sConsoleData, %ebx\n" /* line 341 */
        "testl %ebx, %ebx\n"
        "je .Lfc4cfe_000c4d62\n"
        "cld\n" /* line 343 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll PtrAndHand\n"
        "addl $0x20, %esp\n" /* line 357 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 361 */
__attribute__((naked))
JCOEF Sys_SetErrorText(const char *buf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 361 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl sConsoleEditText, %eax\n" /* line 363 */
        "testl %eax, %eax\n"
        "je .Lfc4dd4_000c4deb\n"
        "movl %eax, (%esp)\n" /* line 365 */
        "calll HideControl\n"
        ".Lfc4dd4_000c4deb:\n"
        "movl $0x10, 0xc(%esp)\n" /* line 368 */
        "movl $0, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* buf */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll MessageBoxA\n"
        "leave\n" /* line 370 */
        "retl\n"
    );
}

