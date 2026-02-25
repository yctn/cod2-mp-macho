/* ASM dump from: MacBuilder.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacBuilder.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacTools.h"
 */

static ControlKeyFilterUPP sControlKeyFilterUPP; /* 0x334708 */
static ControlEditTextValidationUPP sControlValidationUPP; /* 0x334704 */
static MacBuilderProcPtr sBuilderProcPtr; /* 0x334700 */

ControlPartCode UserPaneHitTestProc(ControlRef theControl, struct Point theWherePt);
WindowRef MacBuilder_BuildWindow(CFStringRef inName, CFStringRef inNibName, int inStandardHandler, MacBuilderProcPtr inBuilderProc);
UInt32 MacBuilder_RunModalWindow(WindowRef inWindow);
inflate_blocks_statef MacBuilder_ReleaseWindow(WindowRef inWindow);
ControlRef MacBuilder_GetControlRef(WindowRef inWindow, SInt32 inID);
static inflate_blocks_statef ValidationProc(ControlRef inControlRef);
static OSStatus HandleStandardEvents(EventRef inEvent, inflate_blocks_statef *inUserData);
static ControlKeyFilterResult KeyFilterProc(ControlRef inControlRef, SInt16 *ioCharCode, EventModifiers *ioModifiers);
inflate_blocks_statef MacBuilder_SetTextObjectFontStyle(WindowRef inWindow, SInt32 inID, int inFontFamilyID, int inFontSize);
inflate_blocks_statef MacBuilder_GetControlText(WindowRef inWindow, SInt32 inID, int inBufferSize, char *outText);
inflate_blocks_statef MacBuilder_SetControlText(WindowRef inWindow, SInt32 inID, const char *inText);
inflate_blocks_statef MacBuilder_SetControlVisible(WindowRef inWindow, SInt32 inID, int inVisible);
inflate_blocks_statef MacBuilder_SetControlEnabled(WindowRef inWindow, SInt32 inID, int inEnabled);
inflate_blocks_statef MacBuilder_SetControlFontStyle(WindowRef inWindow, SInt32 inID, int inFontFamilyID, int inFontSize);
inflate_blocks_statef MacBuilder_SetControlFocus(WindowRef inWindow, SInt32 inID);
inflate_blocks_statef MacBuilder_SetupUserPaneControl(WindowRef inWindow, SInt32 inID, ControlUserPaneDrawProcPtr inDrawProc, ControlUserPaneTrackingProcPtr inTrackingProc);
inflate_blocks_statef MacBuilder_SetEditTextHook(WindowRef inWindow, SInt32 inID, MacBuilderEditHookPtr inHookProc, int inCharLimit);
TXNObject MacBuilder_GetTextObject(WindowRef inWindow, SInt32 inID);

/* line 143 */
__attribute__((naked))
ControlPartCode UserPaneHitTestProc(ControlRef theControl, struct Point theWherePt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 143 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "leal -0x10(%ebp), %ebx\n" /* line 146 | bounds */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* theControl */
        "movl %eax, (%esp)\n"
        "calll GetControlBounds\n"
        "movl %ebx, 4(%esp)\n" /* line 148 */
        "movl 0xc(%ebp), %eax\n" /* theWherePt */
        "movl %eax, (%esp)\n"
        "calll PtInRect\n"
        "testb %al, %al\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 156 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 167 */
__attribute__((naked))
WindowRef MacBuilder_BuildWindow(CFStringRef inName, CFStringRef inNibName, int inStandardHandler, MacBuilderProcPtr inBuilderProc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 167 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* inNibName */
        "movzbl 0x10(%ebp), %esi\n" /* inStandardHandler */
        /* { scope 1: theEvents, minLimits, maxLimits */
        "movl $0, -0xc(%ebp)\n" /* line 169 | theWindow */
        "testl %ebx, %ebx\n" /* line 173 | inNibName */
        "movl $0x32e614, %eax\n"
        "cmovel %eax, %ebx\n" /* inNibName */
        "calll CFBundleGetMainBundle\n" /* line 177 */
        "leal -0x10(%ebp), %edx\n" /* nibRef */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* inNibName */
        "movl %eax, (%esp)\n" /* error */
        "calll CreateNibReferenceWithCFBundle\n"
        "testl %eax, %eax\n" /* line 178 */
        "je .Lf3726_0000376c\n"
        "movl -0xc(%ebp), %eax\n" /* line 211 | theWindow */
        /* } scope */
        "addl $0x60, %esp\n" /* line 215 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: theEvents, minLimits, maxLimits */
        ".Lf3726_0000376c:\n"
        "leal -0xc(%ebp), %eax\n" /* line 180 | theWindow */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inName */
        "movl %eax, 4(%esp)\n"
        "movl -0x10(%ebp), %eax\n" /* nibRef */
        "movl %eax, (%esp)\n"
        "calll CreateWindowFromNib\n"
        "testl %eax, %eax\n" /* line 183 */
        "jne .Lf3726_0000378f\n"
        "movl %esi, %eax\n" /* inStandardHandler */
        "testb %al, %al\n"
        "jne .Lf3726_000037a4\n"
        ".Lf3726_0000378f:\n"
        "movl -0x10(%ebp), %eax\n" /* line 211 | nibRef */
        "movl %eax, (%esp)\n"
        "calll DisposeNibReference\n"
        "movl -0xc(%ebp), %eax\n" /* theWindow */
        /* } scope */
        "addl $0x60, %esp\n" /* line 215 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: theEvents, minLimits, maxLimits */
        /* { scope 2 */
        ".Lf3726_000037a4:\n"
        "movl $0x6d6f7573, -0x40(%ebp)\n" /* line 190 | theEvents */
        "movl $5, -0x3c(%ebp)\n"
        "movl $0x77696e64, -0x38(%ebp)\n"
        "movl $0x48, -0x34(%ebp)\n"
        "movl $0x636d6473, -0x30(%ebp)\n"
        "movl $1, -0x2c(%ebp)\n"
        "movl $0x50726976, -0x28(%ebp)\n"
        "movl $0x41647643, -0x24(%ebp)\n"
        "movl -0xc(%ebp), %ebx\n" /* line 192 | theWindow, inNibName */
        "movl %ebx, (%esp)\n" /* inNibName */
        "calll GetWindowEventTarget\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* inNibName */
        "leal -0x40(%ebp), %edx\n" /* theEvents */
        "movl %edx, 0xc(%esp)\n"
        "movl $4, 8(%esp)\n"
        "movl $HandleStandardEvents, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InstallEventHandler\n"
        "movl 0x14(%ebp), %eax\n" /* line 196 | inBuilderProc */
        "movl %eax, sBuilderProcPtr\n"
        "leal -0x20(%ebp), %ebx\n" /* line 199 | maxLimits, inNibName */
        "movl %ebx, 8(%esp)\n" /* inNibName */
        "leal -0x18(%ebp), %eax\n" /* minLimits */
        "movl %eax, 4(%esp)\n"
        "movl -0xc(%ebp), %eax\n" /* theWindow */
        "movl %eax, (%esp)\n"
        "calll GetWindowResizeLimits\n"
        "testl %eax, %eax\n" /* line 200 */
        "jne .Lf3726_0000378f\n"
        "movss -0x18(%ebp), %xmm1\n" /* line 203 | minLimits */
        "movss -0x20(%ebp), %xmm0\n" /* maxLimits */
        "subss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "subl $1, %eax\n"
        "jne .Lf3726_0000378f\n"
        "movss %xmm1, -0x20(%ebp)\n" /* line 205 | maxLimits */
        "movl %ebx, 8(%esp)\n" /* line 206 | inNibName */
        "movl $0, 4(%esp)\n"
        "movl -0xc(%ebp), %eax\n" /* theWindow */
        "movl %eax, (%esp)\n"
        "calll SetWindowResizeLimits\n"
        "jmp .Lf3726_0000378f\n"
    );
}

/* line 221 */
__attribute__((naked))
UInt32 MacBuilder_RunModalWindow(WindowRef inWindow)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 221 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* inWindow */
        "calll InitCursor\n" /* line 223 */
        "movl %ebx, (%esp)\n" /* line 224 | inWindow */
        "calll ShowWindow\n"
        "movl %ebx, (%esp)\n" /* line 225 | inWindow */
        "calll RunAppModalLoopForWindow\n"
        "movl %ebx, (%esp)\n" /* line 226 | inWindow */
        "calll HideWindow\n"
        "movl %ebx, 8(%ebp)\n" /* line 228 | inWindow */
        "addl $0x14, %esp\n" /* line 229 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp GetWRefCon\n" /* line 228 */
    );
}

/* line 235 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_ReleaseWindow(WindowRef inWindow)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 235 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 237 | inWindow */
        "movl %eax, (%esp)\n"
        "calll DisposeWindow\n"
        "movl $0, sBuilderProcPtr\n" /* line 239 */
        "leave\n" /* line 240 */
        "retl\n"
    );
}

/* line 249 */
__attribute__((naked))
ControlRef MacBuilder_GetControlRef(WindowRef inWindow, SInt32 inID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl $0x4974656d, -0x14(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0xc(%ebp)\n" /* line 255 | theControl */
        "leal -0xc(%ebp), %eax\n" /* line 256 | theControl */
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* controlID */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inWindow */
        "movl %eax, (%esp)\n"
        "calll GetControlByID\n"
        "movl %eax, %edx\n" /* error */
        "xorl %eax, %eax\n" /* line 259 */
        "testl %edx, %edx\n"
        "cmovel -0xc(%ebp), %eax\n" /* theControl */
        /* } scope */
        "leave\n" /* line 263 */
        "retl\n"
    );
}

/* line 655 */
static __attribute__((naked))
inflate_blocks_statef ValidationProc(ControlRef inControlRef)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 655 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* inControlRef */
        /* { scope 1: dataSize, selRec */
        "movl %esi, (%esp)\n" /* line 657 | inControlRef */
        "calll GetControlMaximum\n"
        "movl %eax, %ebx\n" /* charLimit */
        "testw %ax, %ax\n" /* line 658 */
        "jne .Lf390a_0000392b\n"
        /* } scope */
        ".Lf390a_00003924:\n"
        "addl $0x30, %esp\n" /* line 666 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dataSize, selRec */
        /* { scope 2 */
        ".Lf390a_0000392b:\n"
        "leal -0xc(%ebp), %eax\n" /* line 583 | dataSize */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x74657874, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll GetControlDataSize\n"
        "testw %ax, %ax\n"
        "je .Lf390a_000039b3\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf390a_00003951:\n"
        "movswl %ax, %edx\n" /* line 660 */
        "movzwl %bx, %eax\n" /* charLimit */
        "cmpl %eax, %edx\n"
        "jle .Lf390a_00003924\n"
        /* { scope 2 */
        "movw %bx, -0x10(%ebp)\n" /* line 570 | selRec */
        "movw $0x7fff, -0xe(%ebp)\n" /* line 571 */
        "leal -0x10(%ebp), %eax\n" /* line 573 | selRec */
        "movl %eax, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $0x73656c65, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SetControlData\n"
        /* } scope */
        "movl $0, 0xc(%esp)\n" /* line 663 */
        "movl $8, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* inControlRef */
        "calll HandleControlKey\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 666 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dataSize, selRec */
        /* { scope 2 */
        ".Lf390a_000039b3:\n"
        "movl -0xc(%ebp), %eax\n" /* line 585 | dataSize */
        "jmp .Lf390a_00003951\n"
    );
}

/* line 34 */
static __attribute__((naked))
OSStatus HandleStandardEvents(EventRef inEvent, inflate_blocks_statef *inUserData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 34 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* inEvent */
        /* { scope 1: param, command */
        "movl %esi, (%esp)\n" /* line 40 | inEvent */
        "calll GetEventKind\n"
        "movl %eax, %ebx\n" /* eventKind */
        "movl %esi, (%esp)\n" /* line 42 | inEvent */
        "calll GetEventClass\n"
        "cmpl $0x636d6473, %eax\n"
        "je .Lf39b8_00003a6a\n"
        "jbe .Lf39b8_00003a06\n"
        "cmpl $0x6d6f7573, %eax\n"
        "je .Lf39b8_00003b19\n"
        "cmpl $0x77696e64, %eax\n"
        "je .Lf39b8_00003aec\n"
        /* { scope 2: viewKind */
        ".Lf39b8_000039f8:\n"
        "movl $0xffffd96e, %ebx\n" /* line 130 | eventKind */
        /* } scope */
        /* } scope */
        ".Lf39b8_000039fd:\n"
        "movl %ebx, %eax\n" /* line 138 | eventKind */
        "addl $0x40, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: param, command */
        ".Lf39b8_00003a06:\n"
        "cmpl $0x50726976, %eax\n" /* line 42 */
        "jne .Lf39b8_000039f8\n"
        "cmpl $0x41647643, %ebx\n" /* line 124 | eventKind */
        "jne .Lf39b8_000039f8\n"
        /* { scope 2: viewKind */
        /* { scope 3 */
        "leal -0xc(%ebp), %eax\n" /* line 37 | param, error */
        "movl %eax, 0x18(%esp)\n" /* error */
        "movl $0, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x504f6e65, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* inEvent */
        "calll GetEventParameter\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 127 */
        "jne .Lf39b8_000039f8\n"
        "movl -0xc(%ebp), %eax\n" /* line 130 | param */
        "movl %eax, (%esp)\n"
        "calll GetControlOwner\n"
        "movl %eax, (%esp)\n"
        "calll AdvanceKeyboardFocus\n"
        "movl $0xffffd96e, %ebx\n" /* eventKind */
        "jmp .Lf39b8_000039fd\n"
        /* } scope */
        ".Lf39b8_00003a6a:\n"
        "cmpl $1, %ebx\n" /* line 93 | eventKind */
        "jne .Lf39b8_000039f8\n"
        /* { scope 2: viewKind */
        /* { scope 3 */
        "leal -0x1a(%ebp), %eax\n" /* line 37 | command, error */
        "movl %eax, 0x18(%esp)\n" /* error */
        "movl $0, 0x14(%esp)\n"
        "movl $0xe, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x68636d64, 8(%esp)\n"
        "movl $0x2d2d2d2d, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* inEvent */
        "calll GetEventParameter\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 96 */
        "jne .Lf39b8_000039f8\n"
        "movl -0x16(%ebp), %eax\n" /* line 98 */
        "cmpl $0x6f6b2020, %eax\n"
        "je .Lf39b8_00003bb4\n"
        "cmpl $0x6e6f7421, %eax\n" /* line 104 */
        "jne .Lf39b8_00003b8b\n"
        "movl $0x6e6f7421, 4(%esp)\n" /* line 106 */
        "movl 0x10(%ebp), %eax\n" /* inUserData */
        "movl %eax, (%esp)\n"
        "calll SetWRefCon\n"
        "movl 0x10(%ebp), %edx\n" /* line 107 | inUserData */
        "movl %edx, (%esp)\n"
        "calll QuitAppModalLoopForWindow\n"
        "xorl %ebx, %ebx\n" /* eventKind */
        "jmp .Lf39b8_000039fd\n"
        /* } scope */
        ".Lf39b8_00003aec:\n"
        "cmpl $0x48, %ebx\n" /* line 80 | eventKind */
        "jne .Lf39b8_000039f8\n"
        "movl sBuilderProcPtr, %eax\n" /* line 82 */
        "testl %eax, %eax\n"
        "je .Lf39b8_00003bad\n"
        "movl $0x636c6f73, 4(%esp)\n" /* line 84 */
        "movl 0x10(%ebp), %edx\n" /* inUserData */
        "movl %edx, (%esp)\n"
        "calll *%eax\n"
        "xorb %bl, %bl\n" /* eventKind */
        "jmp .Lf39b8_000039fd\n"
        ".Lf39b8_00003b19:\n"
        "cmpl $5, %ebx\n" /* line 46 | eventKind */
        "jne .Lf39b8_000039f8\n"
        /* { scope 2: viewKind */
        "movl 0x10(%ebp), %eax\n" /* line 51 | inUserData */
        "movl %eax, (%esp)\n"
        "calll HIViewGetRoot\n"
        "leal -0xc(%ebp), %edx\n" /* param */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* inEvent */
        "movl %eax, (%esp)\n"
        "calll HIViewGetViewForMouseEvent\n"
        "movl %eax, %ebx\n" /* eventKind */
        "testl %eax, %eax\n" /* line 52 */
        "jne .Lf39b8_00003b75\n"
        "movl -0xc(%ebp), %edx\n" /* param */
        "testl %edx, %edx\n"
        "je .Lf39b8_00003b73\n"
        /* { scope 3 */
        "leal -0x1a(%ebp), %eax\n" /* line 58 | command */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll GetControlKind\n"
        "movl %eax, %ebx\n" /* eventKind */
        "testl %eax, %eax\n" /* line 59 */
        "jne .Lf39b8_00003b75\n"
        "movl -0x16(%ebp), %eax\n" /* line 61 */
        "cmpl $0x65747874, %eax\n"
        "je .Lf39b8_00003b84\n"
        "cmpl $0x65757478, %eax\n"
        "je .Lf39b8_00003b84\n"
        ".Lf39b8_00003b73:\n"
        "xorl %ebx, %ebx\n" /* eventKind */
        ".Lf39b8_00003b75:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf39b8_00003b77:\n"
        "movl %eax, (%esp)\n" /* line 73 */
        "calll SetThemeCursor\n"
        "jmp .Lf39b8_000039fd\n"
        /* { scope 3 */
        ".Lf39b8_00003b84:\n"
        "movl $4, %eax\n" /* line 61 */
        "jmp .Lf39b8_00003b77\n"
        /* } scope */
        /* } scope */
        /* { scope 2: viewKind */
        ".Lf39b8_00003b8b:\n"
        "movl sBuilderProcPtr, %edx\n" /* line 110 */
        "testl %edx, %edx\n"
        "je .Lf39b8_000039f8\n"
        "movl %eax, 4(%esp)\n" /* line 112 */
        "movl 0x10(%ebp), %eax\n" /* inUserData */
        "movl %eax, (%esp)\n"
        "calll *%edx\n"
        "testb %al, %al\n"
        "je .Lf39b8_000039f8\n"
        /* } scope */
        /* { scope 2: viewKind */
        ".Lf39b8_00003bad:\n"
        "xorl %ebx, %ebx\n" /* line 130 | eventKind */
        "jmp .Lf39b8_000039fd\n"
        /* } scope */
        /* { scope 2: viewKind */
        ".Lf39b8_00003bb4:\n"
        "movl $0x6f6b2020, 4(%esp)\n" /* line 100 */
        "movl 0x10(%ebp), %eax\n" /* inUserData */
        "movl %eax, (%esp)\n"
        "calll SetWRefCon\n"
        "movl 0x10(%ebp), %edx\n" /* line 101 | inUserData */
        "movl %edx, (%esp)\n"
        "calll QuitAppModalLoopForWindow\n"
        "xorb %bl, %bl\n" /* eventKind */
        "jmp .Lf39b8_000039fd\n"
    );
}

/* line 598 */
static __attribute__((naked))
ControlKeyFilterResult KeyFilterProc(ControlRef inControlRef, SInt16 *ioCharCode, EventModifiers *ioModifiers)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 598 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* inControlRef */
        "movl 0x10(%ebp), %esi\n" /* ioCharCode */
        "movl %ebx, (%esp)\n" /* line 602 | inControlRef */
        "calll GetControlReference\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 603 */
        "je .Lf3bda_00003c0b\n"
        "movswl (%esi), %eax\n" /* line 605 | ioCharCode */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* inControlRef */
        "calll *%edx\n"
        "testb %al, %al\n"
        "jne .Lf3bda_00003cb1\n"
        /* { scope 1: selRec, dataSize */
        ".Lf3bda_00003c0b:\n"
        "movl %ebx, (%esp)\n" /* line 613 | inControlRef */
        "calll GetControlMaximum\n"
        "movl %eax, %edi\n" /* charLimit */
        "testw %ax, %ax\n" /* line 614 */
        "je .Lf3bda_00003cce\n"
        "movl 0x14(%ebp), %eax\n" /* ioModifiers */
        "testb $1, 1(%eax)\n"
        "jne .Lf3bda_00003cce\n"
        "movzwl (%esi), %eax\n" /* line 616 | ioCharCode */
        "cmpw $0x1f, %ax\n"
        "jle .Lf3bda_00003cbb\n"
        "cmpw $0x7f, %ax\n"
        "je .Lf3bda_00003cce\n"
        /* { scope 2 */
        ".Lf3bda_00003c42:\n"
        "movl $0, 0x14(%esp)\n" /* line 552 */
        "leal -0x1c(%ebp), %eax\n" /* selRec */
        "movl %eax, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $0x73656c65, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll GetControlData\n"
        "testw %ax, %ax\n"
        "je .Lf3bda_00003cdb\n"
        "xorl %esi, %esi\n"
        /* } scope */
        /* { scope 2 */
        ".Lf3bda_00003c78:\n"
        "leal -0x20(%ebp), %eax\n" /* line 583 | dataSize */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x74657874, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll GetControlDataSize\n"
        "testw %ax, %ax\n"
        "je .Lf3bda_00003ce4\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf3bda_00003c9e:\n"
        "leal 1(%eax, %esi), %eax\n" /* line 635 */
        "cwtl\n"
        "movzwl %di, %edx\n" /* charLimit */
        "cmpl %edx, %eax\n"
        "je .Lf3bda_00003ce9\n"
        "jle .Lf3bda_00003cce\n" /* line 639 */
        "calll AlertSoundPlay\n" /* line 642 */
        ".Lf3bda_00003cb1:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: selRec, dataSize */
        ".Lf3bda_00003cbb:\n"
        "cmpw $0x1c, %ax\n" /* line 616 */
        "jge .Lf3bda_00003cce\n"
        "subl $8, %eax\n"
        "cmpw $1, %ax\n"
        "ja .Lf3bda_00003c42\n"
        ".Lf3bda_00003cce:\n"
        "movl $1, %eax\n" /* line 642 */
        /* } scope */
        ".Lf3bda_00003cd3:\n"
        "addl $0x3c, %esp\n" /* line 651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: selRec, dataSize */
        /* { scope 2 */
        ".Lf3bda_00003cdb:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 552 | selRec */
        "subw -0x1a(%ebp), %si\n"
        "jmp .Lf3bda_00003c78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf3bda_00003ce4:\n"
        "movl -0x20(%ebp), %eax\n" /* line 585 | dataSize */
        "jmp .Lf3bda_00003c9e\n"
        /* } scope */
        ".Lf3bda_00003ce9:\n"
        "movl %ebx, (%esp)\n" /* line 637 | inControlRef */
        "calll GetControlOwner\n"
        "movl $0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* inControlRef */
        "movl $0x41647643, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_PostPrivateEventToWindow\n"
        "movl $1, %eax\n"
        "jmp .Lf3bda_00003cd3\n"
    );
}

/* line 751 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_SetTextObjectFontStyle(WindowRef inWindow, SInt32 inID, int inFontFamilyID, int inFontSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 751 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* inFontFamilyID */
        "movl 0x14(%ebp), %eax\n" /* inFontSize, inWindow */
        "movw %ax, -0x48(%ebp)\n" /* inWindow, inFontSize */
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        "movl $0x4974656d, -0x34(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x30(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 255 | theControl */
        "leal -0x1c(%ebp), %eax\n" /* line 256 | theControl, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x34(%ebp), %esi\n" /* controlID */
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %ebx, %ebx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0x1c(%ebp), %ebx\n" /* theControl */
        "movl %ebx, -0x1c(%ebp)\n" /* theControl */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 731 */
        "je .Lf3d14_00003d73\n"
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 734 */
        "movl %ebx, (%esp)\n"
        "calll GetControlKind\n"
        "testl %eax, %eax\n" /* line 735 */
        "je .Lf3d14_00003d7b\n"
        /* } scope */
        /* } scope */
        ".Lf3d14_00003d73:\n"
        "addl $0x5c, %esp\n" /* line 767 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        ".Lf3d14_00003d7b:\n"
        "cmpl $0x68697478, -0x30(%ebp)\n" /* line 735 */
        "jne .Lf3d14_00003d73\n"
        "movl %ebx, (%esp)\n" /* line 737 */
        "calll HITextViewGetTXNObject\n"
        "movl %eax, %edx\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 754 */
        "je .Lf3d14_00003d73\n"
        /* { scope 2 */
        "movl $0x666f6e74, -0x34(%ebp)\n" /* line 757 | controlID */
        "movl $2, -0x30(%ebp)\n" /* line 758 */
        "movswl %di, %eax\n" /* line 759 | inFontFamilyID */
        "movl %eax, -0x2c(%ebp)\n"
        "movl $0x73697a65, -0x28(%ebp)\n" /* line 761 */
        "movl $2, -0x24(%ebp)\n" /* line 762 */
        "movl -0x48(%ebp), %eax\n" /* line 763 | inFontSize */
        "shll $0x10, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl $0x7fffffff, 0x10(%esp)\n" /* line 765 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll TXNSetTypeAttributes\n"
        "jmp .Lf3d14_00003d73\n"
    );
}

/* line 305 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_GetControlText(WindowRef inWindow, SInt32 inID, int inBufferSize, char *outText)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 305 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x14(%ebp), %ebx\n" /* outText */
        "movl 0x10(%ebp), %edi\n" /* inBufferSize */
        "movb $0, (%ebx)\n" /* line 307 | outText */
        /* { scope 1 */
        "movl $0x4974656d, -0x24(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 255 | theControl */
        "leal -0x1c(%ebp), %esi\n" /* line 256 | theControl */
        "movl %esi, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* controlID, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %edx, %edx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0x1c(%ebp), %edx\n" /* theControl */
        "movl %edx, -0x1c(%ebp)\n" /* theControl */
        /* } scope */
        "testl %edx, %edx\n" /* line 310 */
        "je .Lf3de4_00003e68\n"
        /* { scope 1 */
        "movl %esi, 0x14(%esp)\n" /* line 313 */
        "movl %ebx, 0x10(%esp)\n" /* outText */
        "movswl %di, %eax\n" /* inBufferSize */
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x74657874, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll GetControlData\n"
        "testw %ax, %ax\n" /* line 314 */
        "jne .Lf3de4_00003e68\n"
        "movl -0x1c(%ebp), %eax\n" /* line 316 | theControl */
        "movb $0, (%ebx, %eax)\n" /* outText */
        /* } scope */
        ".Lf3de4_00003e68:\n"
        "addl $0x3c, %esp\n" /* line 319 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 327 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_SetControlText(WindowRef inWindow, SInt32 inID, const char *inText)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 327 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* inText */
        /* { scope 1 */
        "movl $0x4974656d, -0x14(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0xc(%ebp)\n" /* line 255 | theControl */
        "leal -0xc(%ebp), %eax\n" /* line 256 | theControl, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x14(%ebp), %eax\n" /* controlID, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %edx, %edx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0xc(%ebp), %edx\n" /* theControl */
        "movl %edx, -0xc(%ebp)\n" /* theControl */
        /* } scope */
        "testl %edx, %edx\n" /* line 330 */
        "je .Lf3e70_00003ee8\n"
        "movl %ebx, 0x10(%esp)\n" /* line 332 | inText */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* inText */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl $0x74657874, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SetControlData\n"
        ".Lf3e70_00003ee8:\n"
        "addl $0x30, %esp\n" /* line 334 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 357 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_SetControlVisible(WindowRef inWindow, SInt32 inID, int inVisible)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 357 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movzbl 0x10(%ebp), %ebx\n" /* inVisible */
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        "movl $0x4974656d, -0x14(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0xc(%ebp)\n" /* line 255 | theControl */
        "leal -0xc(%ebp), %eax\n" /* line 256 | theControl, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x14(%ebp), %eax\n" /* controlID, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %edx, %edx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0xc(%ebp), %edx\n" /* theControl */
        "movl %edx, -0xc(%ebp)\n" /* theControl */
        /* } scope */
        "testl %edx, %edx\n" /* line 360 */
        "je .Lf3ef0_00003f43\n"
        "testb %bl, %bl\n" /* line 362 | inVisible */
        "jne .Lf3ef0_00003f49\n"
        "movl %edx, (%esp)\n" /* line 368 */
        "calll HideControl\n"
        /* } scope */
        ".Lf3ef0_00003f43:\n"
        "addl $0x24, %esp\n" /* line 371 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: controlID, theControl */
        ".Lf3ef0_00003f49:\n"
        "movl %edx, (%esp)\n" /* line 364 */
        "calll ShowControl\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 371 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 379 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_SetControlEnabled(WindowRef inWindow, SInt32 inID, int inEnabled)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 379 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movzbl 0x10(%ebp), %ebx\n" /* inEnabled */
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        "movl $0x4974656d, -0x14(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0xc(%ebp)\n" /* line 255 | theControl */
        "leal -0xc(%ebp), %eax\n" /* line 256 | theControl, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x14(%ebp), %eax\n" /* controlID, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %edx, %edx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0xc(%ebp), %edx\n" /* theControl */
        "movl %edx, -0xc(%ebp)\n" /* theControl */
        /* } scope */
        "testl %edx, %edx\n" /* line 382 */
        "je .Lf3f58_00003fab\n"
        "testb %bl, %bl\n" /* line 384 | inEnabled */
        "jne .Lf3f58_00003fb1\n"
        "movl %edx, (%esp)\n" /* line 390 */
        "calll DisableControl\n"
        /* } scope */
        ".Lf3f58_00003fab:\n"
        "addl $0x24, %esp\n" /* line 393 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: controlID, theControl */
        ".Lf3f58_00003fb1:\n"
        "movl %edx, (%esp)\n" /* line 386 */
        "calll EnableControl\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 393 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 402 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_SetControlFontStyle(WindowRef inWindow, SInt32 inID, int inFontFamilyID, int inFontSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 402 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* inFontFamilyID */
        "movl 0x14(%ebp), %edi\n" /* inFontSize */
        /* { scope 1 */
        "movl $0x4974656d, -0x34(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x30(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 255 | theControl */
        "leal -0x1c(%ebp), %eax\n" /* line 256 | theControl, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x34(%ebp), %ebx\n" /* controlID */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %edx, %edx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0x1c(%ebp), %edx\n" /* theControl */
        "movl %edx, -0x1c(%ebp)\n" /* theControl */
        /* } scope */
        "testl %edx, %edx\n" /* line 405 */
        "je .Lf3fc0_00004025\n"
        /* { scope 1 */
        "movw $5, -0x34(%ebp)\n" /* line 408 | controlID */
        "movw %si, -0x32(%ebp)\n" /* line 409 */
        "movw %di, -0x30(%ebp)\n" /* line 410 */
        "movl %ebx, 4(%esp)\n" /* line 412 */
        "movl %edx, (%esp)\n"
        "calll SetControlFontStyle\n"
        /* } scope */
        ".Lf3fc0_00004025:\n"
        "addl $0x3c, %esp\n" /* line 414 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 421 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_SetControlFocus(WindowRef inWindow, SInt32 inID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 421 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* inWindow */
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        "movl $0x4974656d, -0x24(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 255 | theControl */
        "leal -0x1c(%ebp), %eax\n" /* line 256 | theControl, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x24(%ebp), %esi\n" /* controlID */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll GetControlByID\n"
        "xorl %ebx, %ebx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0x1c(%ebp), %ebx\n" /* theControl */
        "movl %ebx, -0x1c(%ebp)\n" /* theControl */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 424 */
        "je .Lf402e_000040a8\n"
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 427 */
        "movl %ebx, (%esp)\n"
        "calll GetControlKind\n"
        "testl %eax, %eax\n" /* line 428 */
        "jne .Lf402e_000040a8\n"
        "movl -0x20(%ebp), %eax\n" /* line 432 */
        "cmpl $0x65747874, %eax\n"
        "je .Lf402e_00004094\n"
        "cmpl $0x65757478, %eax\n"
        "jne .Lf402e_000040a8\n"
        ".Lf402e_00004094:\n"
        "movl $5, 8(%esp)\n" /* line 439 */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* inWindow */
        "calll SetKeyboardFocus\n"
        /* } scope */
        /* } scope */
        ".Lf402e_000040a8:\n"
        "addl $0x2c, %esp\n" /* line 443 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 522 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_SetupUserPaneControl(WindowRef inWindow, SInt32 inID, ControlUserPaneDrawProcPtr inDrawProc, ControlUserPaneTrackingProcPtr inTrackingProc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x14(%ebp), %edi\n" /* inTrackingProc */
        /* { scope 1: testUPP, trackingUPP */
        "movl $0x4974656d, -0x2c(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x28(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 255 | theControl */
        "leal -0x1c(%ebp), %esi\n" /* line 256 | theControl */
        "movl %esi, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* controlID, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %ebx, %ebx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0x1c(%ebp), %ebx\n" /* theControl */
        "movl %ebx, -0x1c(%ebp)\n" /* theControl */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 525 */
        "je .Lf40b2_0000419c\n"
        /* { scope 1: testUPP, trackingUPP */
        "movl 0x10(%ebp), %eax\n" /* line 527 | inDrawProc */
        "movl %eax, (%esp)\n"
        "calll NewControlUserPaneDrawUPP\n"
        "movl %eax, -0x1c(%ebp)\n" /* theControl */
        "movl %esi, 0x10(%esp)\n" /* line 528 */
        "movl $4, 0xc(%esp)\n"
        "movl $0x64726177, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SetControlData\n"
        "testl %edi, %edi\n" /* line 530 | inTrackingProc */
        "je .Lf40b2_0000419c\n"
        /* { scope 2 */
        "movl $UserPaneHitTestProc, (%esp)\n" /* line 532 */
        "calll NewControlUserPaneHitTestUPP\n"
        "movl %eax, -0x20(%ebp)\n" /* testUPP */
        "leal -0x20(%ebp), %eax\n" /* line 533 | testUPP */
        "movl %eax, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $0x68697474, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SetControlData\n"
        "movl %edi, (%esp)\n" /* line 535 | inTrackingProc */
        "calll NewControlUserPaneTrackingUPP\n"
        "movl %eax, -0x24(%ebp)\n" /* trackingUPP */
        "leal -0x24(%ebp), %eax\n" /* line 536 | trackingUPP */
        "movl %eax, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $0x7472616b, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SetControlData\n"
        /* } scope */
        /* } scope */
        ".Lf40b2_0000419c:\n"
        "addl $0x4c, %esp\n" /* line 539 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 673 */
__attribute__((naked))
inflate_blocks_statef MacBuilder_SetEditTextHook(WindowRef inWindow, SInt32 inID, MacBuilderEditHookPtr inHookProc, int inCharLimit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 673 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* inHookProc */
        "movl 0x14(%ebp), %esi\n" /* inCharLimit */
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        "movl $0x4974656d, -0x24(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 255 | theControl */
        "leal -0x1c(%ebp), %eax\n" /* line 256 | theControl, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x24(%ebp), %eax\n" /* controlID, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %edx, %edx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0x1c(%ebp), %edx\n" /* theControl */
        "movl %edx, -0x1c(%ebp)\n" /* theControl */
        "movl %edx, %ebx\n" /* line 262 */
        /* } scope */
        "testl %edx, %edx\n" /* line 676 */
        "je .Lf41a4_00004284\n"
        /* { scope 2 */
        "movl sControlKeyFilterUPP, %edx\n" /* line 680 */
        "testl %edx, %edx\n"
        "je .Lf41a4_000042b6\n"
        ".Lf41a4_00004203:\n"
        "movl $sControlKeyFilterUPP, 0x10(%esp)\n" /* line 684 */
        "movl $4, 0xc(%esp)\n"
        "movl $0x666c7472, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theControl */
        "calll SetControlData\n"
        "movl sControlValidationUPP, %eax\n" /* line 689 */
        "testl %eax, %eax\n"
        "je .Lf41a4_000042cc\n"
        ".Lf41a4_00004238:\n"
        "movl $sControlValidationUPP, 0x10(%esp)\n" /* line 693 */
        "movl $4, 0xc(%esp)\n"
        "movl $0x76616c69, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theControl */
        "calll SetControlData\n"
        "testl %edi, %edi\n" /* line 697 | inHookProc */
        "je .Lf41a4_000042a4\n"
        "movl %edi, 4(%esp)\n" /* line 699 | inHookProc */
        "movl %ebx, (%esp)\n" /* theControl */
        "calll SetControlReference\n"
        ".Lf41a4_00004270:\n"
        "testw %si, %si\n" /* line 708 | inCharLimit */
        "jle .Lf41a4_0000428c\n"
        "movswl %si, %eax\n" /* line 710 | inCharLimit */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theControl */
        "calll SetControlMaximum\n"
        /* } scope */
        /* } scope */
        ".Lf41a4_00004284:\n"
        "addl $0x3c, %esp\n" /* line 717 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        ".Lf41a4_0000428c:\n"
        "movl $0, 4(%esp)\n" /* line 714 */
        "movl %ebx, (%esp)\n" /* theControl */
        "calll SetControlMaximum\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 717 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        ".Lf41a4_000042a4:\n"
        "movl $0, 4(%esp)\n" /* line 703 */
        "movl %ebx, (%esp)\n" /* theControl */
        "calll SetControlReference\n"
        "jmp .Lf41a4_00004270\n"
        ".Lf41a4_000042b6:\n"
        "movl $KeyFilterProc, (%esp)\n" /* line 682 */
        "calll NewControlKeyFilterUPP\n"
        "movl %eax, sControlKeyFilterUPP\n"
        "jmp .Lf41a4_00004203\n"
        ".Lf41a4_000042cc:\n"
        "movl $ValidationProc, (%esp)\n" /* line 691 */
        "calll NewControlEditTextValidationUPP\n"
        "movl %eax, sControlValidationUPP\n"
        "jmp .Lf41a4_00004238\n"
    );
}

/* line 726 */
__attribute__((naked))
TXNObject MacBuilder_GetTextObject(WindowRef inWindow, SInt32 inID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 726 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        "movl $0x4974656d, -0x14(%ebp)\n" /* line 252 | controlID */
        "movl 0xc(%ebp), %eax\n" /* line 253 | inID */
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0xc(%ebp)\n" /* line 255 | theControl */
        "leal -0xc(%ebp), %eax\n" /* line 256 | theControl, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x14(%ebp), %esi\n" /* controlID */
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inWindow, error */
        "movl %eax, (%esp)\n" /* error */
        "calll GetControlByID\n"
        "xorl %ebx, %ebx\n" /* line 259 */
        "testl %eax, %eax\n"
        "cmovel -0xc(%ebp), %ebx\n" /* theControl */
        "movl %ebx, -0xc(%ebp)\n" /* theControl */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 731 */
        "jne .Lf42e2_0000432f\n"
        /* { scope 2 */
        ".Lf42e2_00004326:\n"
        "xorl %eax, %eax\n" /* line 737 */
        /* } scope */
        /* } scope */
        ".Lf42e2_00004328:\n"
        "addl $0x20, %esp\n" /* line 742 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: controlID, theControl */
        /* { scope 2 */
        ".Lf42e2_0000432f:\n"
        "movl %esi, 4(%esp)\n" /* line 734 */
        "movl %ebx, (%esp)\n"
        "calll GetControlKind\n"
        "testl %eax, %eax\n" /* line 735 */
        "jne .Lf42e2_00004326\n"
        "cmpl $0x68697478, -0x10(%ebp)\n"
        "jne .Lf42e2_00004326\n"
        "movl %ebx, (%esp)\n" /* line 737 */
        "calll HITextViewGetTXNObject\n"
        "jmp .Lf42e2_00004328\n"
    );
}

