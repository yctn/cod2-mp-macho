/* ASM dump from: mac_input.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_input.cpp */

#include "common_types.h"
#include "imports.h"

extern const dvar_t *in_mouse; /* 0x0 */
static UInt32 sOldButtonState; /* 0xce7200 */
static byte virtualKeyConvert[146][2]; /* 0x311320 */
static byte extendedVirtualKeyConvert[21][2]; /* 0x3112e0 */

void CCallOfDutyEngine_DoMouseMoved(const CCallOfDutyEngine * _this, struct Point inDelta, Point inPoint, UInt32 inModifiers);
void CCallOfDutyEngine_DoMouseWheel(const CCallOfDutyEngine * _this, SInt32 inDelta, Point inPoint, UInt32 inModifiers);
void CCallOfDutyEngine_DoKeyUp(const CCallOfDutyEngine * _this, int inCharCode, UInt32 inKeyCode);
void CCallOfDutyEngine_DoTextInput(const CCallOfDutyEngine * _this, int inUniChar);
void IN_Shutdown(void);
void IN_Init(void);
void CCallOfDutyEngine_DoKeyDown(const CCallOfDutyEngine * _this, int inCharCode, UInt32 inKeyCode);
void CCallOfDutyEngine_DoMouseDown(const CCallOfDutyEngine * _this, int inButton, Point inPoint, UInt32 inModifiers, UInt32 inClickCount);
void CCallOfDutyEngine_DoMouseUp(const CCallOfDutyEngine * _this, int inButton, Point inPoint);

/* line 248 */
__attribute__((naked))
void CCallOfDutyEngine_DoMouseMoved(const CCallOfDutyEngine * _this, struct Point inDelta, Point inPoint, UInt32 inModifiers)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 248 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* inDelta */
        "movswl %ax, %edx\n" /* line 250 */
        "movl %edx, 0xc(%ebp)\n" /* inDelta */
        "sarl $0x10, %eax\n"
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 251 */
        "jmp CL_MouseEvent\n" /* line 250 */
    );
}

/* line 259 */
__attribute__((naked))
void CCallOfDutyEngine_DoMouseWheel(const CCallOfDutyEngine * _this, SInt32 inDelta, Point inPoint, UInt32 inModifiers)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 259 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 261 | inDelta */
        "testl %eax, %eax\n"
        "jle .Lf10c0d4_0010c14b\n"
        "movl $0, 0x14(%esp)\n" /* line 263 */
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0xce, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        "movl $0, 0x14(%esp)\n" /* line 264 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0xce, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        "leave\n" /* line 271 */
        "retl\n"
        ".Lf10c0d4_0010c14b:\n"
        "movl $0, 0x14(%esp)\n" /* line 268 */
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0xcd, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        "movl $0, 0x14(%esp)\n" /* line 269 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0xcd, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        "leave\n" /* line 271 */
        "retl\n"
    );
}

/* line 581 */
__attribute__((naked))
void CCallOfDutyEngine_DoKeyUp(const CCallOfDutyEngine * _this, int inCharCode, UInt32 inKeyCode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 581 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* inKeyCode */
        "movzbl 0xc(%ebp), %ebx\n" /* inCharCode */
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl $0x7f, %eax\n" /* line 489 */
        "jbe .Lf10c1b6_0010c20a\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lf10c1b6_0010c1ca:\n"
        "xorl %edx, %edx\n" /* line 532 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf10c1b6_0010c1cc:\n"
        "testb %dl, %dl\n" /* line 590 */
        "je .Lf10c1b6_0010c203\n"
        "movl $0, 0x14(%esp)\n" /* line 592 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        /* } scope */
        ".Lf10c1b6_0010c203:\n"
        "addl $0x20, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf10c1b6_0010c20a:\n"
        "movl %eax, (%esp)\n" /* line 491 */
        "calll TranslateKeyCodeToVK\n"
        "movl %eax, %edx\n" /* vkCode */
        "leal -1(%edx), %eax\n" /* line 500 */
        "cmpb $0x90, %al\n"
        "ja .Lf10c1b6_0010c288\n"
        "movzbl %dl, %eax\n" /* line 508 */
        "movzbl 0x311321(%eax, %eax), %eax\n"
        "cmpb $0xbf, %al\n" /* line 511 */
        "je .Lf10c1b6_0010c29f\n"
        "testb %al, %al\n" /* line 524 */
        "jne .Lf10c1b6_0010c297\n"
        ".Lf10c1b6_0010c22e:\n"
        "movl $2, 4(%esp)\n" /* line 526 */
        "movzbl %dl, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MapVirtualKeyA\n"
        "testb %al, %al\n" /* line 529 */
        "jne .Lf10c1b6_0010c297\n"
        /* { scope 5 */
        "movzbl extendedVirtualKeyConvert, %eax\n" /* line 532 */
        "testb %al, %al\n"
        "je .Lf10c1b6_0010c1ca\n"
        "movzbl %bl, %esi\n" /* line 535 */
        "cmpb %bl, %al\n"
        "je .Lf10c1b6_0010c2b4\n"
        "xorl %ecx, %ecx\n"
        "movl $extendedVirtualKeyConvert, %edx\n"
        ".Lf10c1b6_0010c262:\n"
        "addl $1, %ecx\n" /* line 540 */
        "movzbl 2(%edx), %eax\n" /* line 532 */
        "testb %al, %al\n"
        "je .Lf10c1b6_0010c1ca\n"
        /* } scope */
        "addl $2, %edx\n" /* line 529 */
        /* { scope 5 */
        "movzbl %al, %eax\n" /* line 535 */
        "cmpl %eax, %esi\n"
        "jne .Lf10c1b6_0010c262\n"
        ".Lf10c1b6_0010c27b:\n"
        "movzbl 0x3112e1(%ecx, %ecx), %edx\n"
        "jmp .Lf10c1b6_0010c1cc\n"
        /* } scope */
        ".Lf10c1b6_0010c288:\n"
        "cmpb $0x92, %dl\n" /* line 519 */
        "jne .Lf10c1b6_0010c22e\n"
        "movl $0xc7, %edx\n"
        "jmp .Lf10c1b6_0010c1cc\n"
        ".Lf10c1b6_0010c297:\n"
        "movzbl %al, %edx\n" /* line 529 */
        "jmp .Lf10c1b6_0010c1cc\n"
        ".Lf10c1b6_0010c29f:\n"
        "movl $0xd, %edx\n" /* line 513 */
        "cmpb $0xd, %bl\n"
        "movl $0xbf, %eax\n"
        "cmovnel %eax, %edx\n"
        "jmp .Lf10c1b6_0010c1cc\n"
        /* { scope 5 */
        ".Lf10c1b6_0010c2b4:\n"
        "xorl %ecx, %ecx\n" /* line 535 */
        "jmp .Lf10c1b6_0010c27b\n"
    );
}

/* line 599 */
__attribute__((naked))
void CCallOfDutyEngine_DoTextInput(const CCallOfDutyEngine * _this, int inUniChar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 599 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* inUniChar */
        "movzwl %bx, %esi\n" /* line 601 | inUniChar */
        "movl %esi, (%esp)\n"
        "calll isprint\n"
        "testl %eax, %eax\n"
        "jne .Lf10c2b8_0010c2df\n"
        "cmpw $8, %bx\n" /* inUniChar */
        "je .Lf10c2b8_0010c2df\n"
        "addl $0x20, %esp\n" /* line 605 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf10c2b8_0010c2df:\n"
        "movl $0, 0x14(%esp)\n" /* line 603 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl 0x195f240, %eax\n"
        "movl 0x18(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_QueEvent\n"
        "addl $0x20, %esp\n" /* line 605 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 144 */
__attribute__((naked))
void IN_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 144 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 147 */
        "retl\n"
    );
}

/* line 151 */
__attribute__((naked))
void IN_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 151 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x1021, 8(%esp)\n" /* line 154 */
        "movl $1, 4(%esp)\n"
        "movl $0x228cb0, (%esp)\n" /* "in_mouse" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, in_mouse\n"
        "cmpb $0, 8(%eax)\n" /* line 84 */
        "jne .Lf10c320_0010c35e\n"
        "movl $0x228c94, (%esp)\n" /* line 86 */
        "calll Com_Printf\n"
        "movl in_mouse, %eax\n"
        ".Lf10c320_0010c35e:\n"
        "movl %eax, (%esp)\n" /* line 139 */
        "calll Dvar_ClearModified\n"
        "leave\n" /* line 157 */
        "retl\n"
    );
}

/* line 554 */
__attribute__((naked))
void CCallOfDutyEngine_DoKeyDown(const CCallOfDutyEngine * _this, int inCharCode, UInt32 inKeyCode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 554 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* inKeyCode */
        "movzbl 0xc(%ebp), %ebx\n" /* inCharCode */
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl $0x7f, %eax\n" /* line 489 */
        "jbe .Lf10c368_0010c3bc\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lf10c368_0010c37c:\n"
        "xorl %edx, %edx\n" /* line 532 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf10c368_0010c37e:\n"
        "testb %dl, %dl\n" /* line 563 */
        "je .Lf10c368_0010c3b5\n"
        "movl $0, 0x14(%esp)\n" /* line 565 */
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        /* } scope */
        ".Lf10c368_0010c3b5:\n"
        "addl $0x20, %esp\n" /* line 574 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf10c368_0010c3bc:\n"
        "movl %eax, (%esp)\n" /* line 491 */
        "calll TranslateKeyCodeToVK\n"
        "movl %eax, %edx\n" /* vkCode */
        "leal -1(%edx), %eax\n" /* line 500 */
        "cmpb $0x90, %al\n"
        "ja .Lf10c368_0010c43a\n"
        "movzbl %dl, %eax\n" /* line 508 */
        "movzbl 0x311321(%eax, %eax), %eax\n"
        "cmpb $0xbf, %al\n" /* line 511 */
        "je .Lf10c368_0010c451\n"
        "testb %al, %al\n" /* line 524 */
        "jne .Lf10c368_0010c449\n"
        ".Lf10c368_0010c3e0:\n"
        "movl $2, 4(%esp)\n" /* line 526 */
        "movzbl %dl, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MapVirtualKeyA\n"
        "testb %al, %al\n" /* line 529 */
        "jne .Lf10c368_0010c449\n"
        /* { scope 5 */
        "movzbl extendedVirtualKeyConvert, %eax\n" /* line 532 */
        "testb %al, %al\n"
        "je .Lf10c368_0010c37c\n"
        "movzbl %bl, %esi\n" /* line 535 */
        "cmpb %bl, %al\n"
        "je .Lf10c368_0010c466\n"
        "xorl %ecx, %ecx\n"
        "movl $extendedVirtualKeyConvert, %edx\n"
        ".Lf10c368_0010c414:\n"
        "addl $1, %ecx\n" /* line 540 */
        "movzbl 2(%edx), %eax\n" /* line 532 */
        "testb %al, %al\n"
        "je .Lf10c368_0010c37c\n"
        /* } scope */
        "addl $2, %edx\n" /* line 529 */
        /* { scope 5 */
        "movzbl %al, %eax\n" /* line 535 */
        "cmpl %eax, %esi\n"
        "jne .Lf10c368_0010c414\n"
        ".Lf10c368_0010c42d:\n"
        "movzbl 0x3112e1(%ecx, %ecx), %edx\n"
        "jmp .Lf10c368_0010c37e\n"
        /* } scope */
        ".Lf10c368_0010c43a:\n"
        "cmpb $0x92, %dl\n" /* line 519 */
        "jne .Lf10c368_0010c3e0\n"
        "movl $0xc7, %edx\n"
        "jmp .Lf10c368_0010c37e\n"
        ".Lf10c368_0010c449:\n"
        "movzbl %al, %edx\n" /* line 529 */
        "jmp .Lf10c368_0010c37e\n"
        ".Lf10c368_0010c451:\n"
        "movl $0xd, %edx\n" /* line 513 */
        "cmpb $0xd, %bl\n"
        "movl $0xbf, %eax\n"
        "cmovnel %eax, %edx\n"
        "jmp .Lf10c368_0010c37e\n"
        /* { scope 5 */
        ".Lf10c368_0010c466:\n"
        "xorl %ecx, %ecx\n" /* line 535 */
        "jmp .Lf10c368_0010c42d\n"
    );
}

/* line 219 */
__attribute__((naked))
void CCallOfDutyEngine_DoMouseDown(const CCallOfDutyEngine * _this, int inButton, Point inPoint, UInt32 inModifiers, UInt32 inClickCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 219 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* inButton */
        "cmpw $0x20, %ax\n" /* line 221 */
        "ja .Lf10c46a_0010c4c7\n"
        "movzwl %ax, %ecx\n" /* line 223 */
        "subl $1, %ecx\n"
        "movl $1, %esi\n"
        "shll %cl, %esi\n"
        "orl 0x20(%edx), %esi\n"
        "movl %esi, 0x20(%edx)\n"
        "movl $0xc8, %ebx\n" /* line 224 */
        "movl $1, %edi\n"
        ".Lf10c46a_0010c49c:\n"
        "leal -0xc8(%ebx), %ecx\n"
        /* { scope 1 */
        "movl %esi, %eax\n" /* line 112 */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf10c46a_0010c4cf\n"
        "movl %edi, %eax\n"
        "shll %cl, %eax\n"
        "testl %eax, sOldButtonState\n"
        "je .Lf10c46a_0010c50d\n"
        ".Lf10c46a_0010c4b6:\n"
        "addl $1, %ebx\n" /* line 119 */
        "cmpl $0xcd, %ebx\n" /* line 110 */
        "jne .Lf10c46a_0010c49c\n"
        "movl %esi, sOldButtonState\n" /* line 123 */
        /* } scope */
        ".Lf10c46a_0010c4c7:\n"
        "addl $0x2c, %esp\n" /* line 226 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf10c46a_0010c4cf:\n"
        "movl %edi, %eax\n" /* line 117 */
        "shll %cl, %eax\n"
        "testl %eax, sOldButtonState\n"
        "je .Lf10c46a_0010c4b6\n"
        "movl $0, 0x14(%esp)\n" /* line 119 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        "jmp .Lf10c46a_0010c4b6\n"
        ".Lf10c46a_0010c50d:\n"
        "movl $0, 0x14(%esp)\n" /* line 114 */
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        "jmp .Lf10c46a_0010c4b6\n"
    );
}

/* line 233 */
__attribute__((naked))
void CCallOfDutyEngine_DoMouseUp(const CCallOfDutyEngine * _this, int inButton, Point inPoint)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 233 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* inButton */
        "cmpw $0x20, %ax\n" /* line 235 */
        "ja .Lf10c542_0010c59f\n"
        "movzwl %ax, %ecx\n" /* line 237 */
        "subl $1, %ecx\n"
        "movl $0xfffffffe, %esi\n"
        "roll %cl, %esi\n"
        "andl 0x20(%edx), %esi\n"
        "movl %esi, 0x20(%edx)\n"
        "movl $0xc8, %ebx\n" /* line 238 */
        "movl $1, %edi\n"
        ".Lf10c542_0010c574:\n"
        "leal -0xc8(%ebx), %ecx\n"
        /* { scope 1 */
        "movl %esi, %eax\n" /* line 112 */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf10c542_0010c5a7\n"
        "movl %edi, %eax\n"
        "shll %cl, %eax\n"
        "testl %eax, sOldButtonState\n"
        "je .Lf10c542_0010c5e5\n"
        ".Lf10c542_0010c58e:\n"
        "addl $1, %ebx\n" /* line 119 */
        "cmpl $0xcd, %ebx\n" /* line 110 */
        "jne .Lf10c542_0010c574\n"
        "movl %esi, sOldButtonState\n" /* line 123 */
        /* } scope */
        ".Lf10c542_0010c59f:\n"
        "addl $0x2c, %esp\n" /* line 240 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf10c542_0010c5a7:\n"
        "movl %edi, %eax\n" /* line 117 */
        "shll %cl, %eax\n"
        "testl %eax, sOldButtonState\n"
        "je .Lf10c542_0010c58e\n"
        "movl $0, 0x14(%esp)\n" /* line 119 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        "jmp .Lf10c542_0010c58e\n"
        ".Lf10c542_0010c5e5:\n"
        "movl $0, 0x14(%esp)\n" /* line 114 */
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Sys_QueEvent\n"
        "jmp .Lf10c542_0010c58e\n"
    );
}

