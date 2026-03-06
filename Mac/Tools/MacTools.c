/* ASM dump from: MacTools.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacTools.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacGlobals.h"
 *   #include "Mac/Tools/MacMemory.h"
 */

extern Boolean sSystemCursorVisible; /* 0x308080 */
static Point sGlobalMouse; /* 0x334b80 */

void MacTools_SetCursorID(int inCursorID);
void MacTools_ShowCursor(int inWarpIt, const Point *inWarpPt);
void MacTools_HideCursor(int inWarpIt);
Boolean MacTools_IsCursorVisible(void);
SInt16 MacTools_FindDiscVolume(CFStringRef inVolumeName, char *outVolumePath);
void MacTools_CenterRect(MacRect *ioRect, const MacRect *inBounds);
void MacTools_Sleep(UInt32 inMillisecondsToSleep);
void MacTools_SendQuitAppleEvent(const ProcessSerialNumber *inPSN);
Boolean MacTools_FindApplicationPSN(OSType inCreatorCode, ProcessSerialNumber *outPSN);
SInt32 MacTools_GetDictionaryValue(CFDictionaryRef inDictionaryRef, CFStringRef inKeyRef);
Boolean MacTools_GetIORegistryValue(io_registry_entry_t inEntryRef, CFStringRef inKeyRef, char *outValue);
Boolean MacTools_PostPrivateEventToWindow(WindowRef inWindow, UInt32 inMessage, UInt32 inParam1, UInt32 inParam2);
Boolean MacTools_QuestionAlert(CFStringRef inMessage1, CFStringRef inMessage2);
void ZN12StShowCursorD1Ev(void); /* StShowCursor_~StShowCursor */
void MacTools_MessageAlert(CFStringRef inMessage1, CFStringRef inMessage2, int inStop);
void MacTools_MessageAlertFromKey(CFStringRef inKeyRef, int inStop);
Boolean SearchForApplication(OSType inCreator, FSRef *outAppRef);
void StShowCursor_StShowCursor(const StShowCursor * _this);
void ZNSt6vectorI5FSRefSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void); /* std_vector<FSRef, std_allocator<FSRef> >__M_insert_aux */

/* line 48 */
__attribute__((naked))
void MacTools_SetCursorID(int inCursorID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movswl 8(%ebp), %eax\n" /* line 50 | inCursorID, cursH */
        "movl %eax, (%esp)\n" /* cursH */
        "calll GetCursor\n"
        "testl %eax, %eax\n" /* line 51 */
        "je .Lfa6d0_0000a6f1\n"
        "movl (%eax), %eax\n" /* line 53 */
        "movl %eax, 8(%ebp)\n" /* inCursorID */
        /* } scope */
        "leave\n" /* line 55 */
        /* { scope 1 */
        "jmp SetCursor\n" /* line 53 */
        /* } scope */
        ".Lfa6d0_0000a6f1:\n"
        "leave\n" /* line 55 */
        "retl\n"
    );
}

/* line 62 */
__attribute__((naked))
void MacTools_ShowCursor(int inWarpIt, const Point *inWarpPt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 62 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movzbl 8(%ebp), %ebx\n" /* inWarpIt */
        "cmpb $0, sSystemCursorVisible\n" /* line 64 */
        "je .Lfa6f4_0000a712\n"
        "addl $0x2c, %esp\n" /* line 89 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa6f4_0000a712:\n"
        "movl $1, (%esp)\n" /* line 66 */
        "calll CGAssociateMouseAndMouseCursorPosition\n"
        "testb %bl, %bl\n" /* line 68 | inWarpIt */
        "je .Lfa6f4_0000a757\n"
        "movl 0xc(%ebp), %eax\n" /* line 71 | inWarpPt */
        "testl %eax, %eax\n"
        "je .Lfa6f4_0000a76b\n"
        "movl 0xc(%ebp), %edx\n" /* line 73 | inWarpPt */
        "movswl 2(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movswl (%edx), %eax\n" /* line 74 */
        "cvtsi2ssl %eax, %xmm0\n"
        ".Lfa6f4_0000a73b:\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* line 82 */
        "movl -0x1c(%ebp), %edi\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "movl %edi, 4(%esp)\n"
        "calll CGWarpMouseCursorPosition\n"
        ".Lfa6f4_0000a757:\n"
        "calll InitCursor\n" /* line 85 */
        "movb $1, sSystemCursorVisible\n" /* line 87 */
        "addl $0x2c, %esp\n" /* line 89 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa6f4_0000a76b:\n"
        "movswl 0x334b82, %eax\n" /* line 78 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movswl sGlobalMouse, %eax\n" /* line 79 */
        "cvtsi2ssl %eax, %xmm0\n"
        "jmp .Lfa6f4_0000a73b\n"
    );
}

/* line 95 */
__attribute__((naked))
void MacTools_HideCursor(int inWarpIt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movzbl 8(%ebp), %ebx\n" /* inWarpIt */
        "cmpb $0, sSystemCursorVisible\n" /* line 97 */
        "jne .Lfa784_0000a7a2\n"
        "addl $0x3c, %esp\n" /* line 138 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa784_0000a7a2:\n"
        "calll HideCursor\n" /* line 99 */
        "testb %bl, %bl\n" /* line 101 | inWarpIt */
        "jne .Lfa784_0000a7c6\n"
        ".Lfa784_0000a7ab:\n"
        "movl $0, (%esp)\n" /* line 134 */
        "calll CGAssociateMouseAndMouseCursorPosition\n"
        "movb $0, sSystemCursorVisible\n" /* line 136 */
        "addl $0x3c, %esp\n" /* line 138 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa784_0000a7c6:\n"
        "movl $sGlobalMouse, (%esp)\n" /* line 103 */
        "calll GetGlobalMouse\n"
        "calll MacDisplay_IsWindowMode\n" /* line 106 */
        "testb %al, %al\n"
        "je .Lfa784_0000a850\n"
        /* { scope 1 */
        "calll MacDisplay_GetMainWindow\n" /* line 109 */
        "leal -0x24(%ebp), %edx\n" /* bounds */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GetWindowPortBounds\n"
        "movzwl -0x1e(%ebp), %edx\n" /* line 112 */
        "movl %edx, %eax\n"
        "shrw $0xf, %ax\n"
        "addl %edx, %eax\n"
        "sarw $1, %ax\n"
        "movw %ax, -0x1a(%ebp)\n"
        "movl -0x20(%ebp), %edx\n" /* line 113 */
        "movl %edx, %eax\n"
        "shrw $0xf, %ax\n"
        "addl %edx, %eax\n"
        "sarw $1, %ax\n"
        "movw %ax, -0x1c(%ebp)\n" /* pt */
        "leal -0x1c(%ebp), %eax\n" /* line 115 | pt */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_LocalToGlobal\n"
        "movswl -0x1a(%ebp), %eax\n" /* line 117 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movswl -0x1c(%ebp), %eax\n" /* line 118 | pt */
        "cvtsi2ssl %eax, %xmm0\n"
        /* } scope */
        /* { scope 1 */
        ".Lfa784_0000a82f:\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* line 131 */
        "movl -0x2c(%ebp), %edi\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movl -0x2c(%ebp), %esi\n"
        /* } scope */
        "movl %esi, (%esp)\n"
        "movl %edi, 4(%esp)\n"
        "calll CGWarpMouseCursorPosition\n"
        "jmp .Lfa784_0000a7ab\n"
        /* { scope 1 */
        ".Lfa784_0000a850:\n"
        "movw $0, -0x24(%ebp)\n" /* line 123 | bounds */
        "movw $0, -0x22(%ebp)\n"
        "movw $1, -0x20(%ebp)\n" /* line 124 */
        "movw $1, -0x1e(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 125 | bounds */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_CenterRectInDisplay\n"
        "movswl -0x22(%ebp), %eax\n" /* line 127 */
        "cvtsi2ssl %eax, %xmm1\n"
        "movswl -0x24(%ebp), %eax\n" /* line 128 | bounds */
        "cvtsi2ssl %eax, %xmm0\n"
        "jmp .Lfa784_0000a82f\n"
    );
}

/* line 143 */
__attribute__((naked))
Boolean MacTools_IsCursorVisible(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 143 */
        "movl %esp, %ebp\n"
        "movzbl sSystemCursorVisible, %eax\n"
        "popl %ebp\n" /* line 146 */
        "retl\n"
    );
}

/* line 481 */
__attribute__((naked))
SInt16 MacTools_FindDiscVolume(CFStringRef inVolumeName, char *outVolumePath)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 481 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4cc, %esp\n"
        /* { scope 1: volumeInfo, volumeName, rootDirectory */
        "movl $0, 0xc(%esp)\n" /* line 486 */
        "movl $2, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* macEvent */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll WaitNextEvent\n"
        "movl $1, %eax\n"
        /* { scope 2: volumeParms, pb */
        ".Lfa892_0000a8c6:\n"
        "leal 1(%eax), %edi\n" /* line 497 */
        "leal -0xac(%ebp), %edx\n" /* rootDirectory */
        "movl %edx, 0x18(%esp)\n"
        "leal -0x4a4(%ebp), %edx\n" /* volumeName */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x1a4(%ebp), %edx\n" /* volumeInfo */
        "movl %edx, 0x10(%esp)\n"
        "movl $0x2050, 0xc(%esp)\n"
        "leal -0x1a(%ebp), %edx\n" /* actualVolume */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n" /* error */
        "movl $0, (%esp)\n"
        "calll FSGetVolumeInfo\n"
        "testw %ax, %ax\n" /* line 498 */
        "jne .Lfa892_0000aad9\n"
        "movl -0x130(%ebp), %eax\n" /* line 505 */
        "testb %al, %al\n"
        "js .Lfa892_0000a922\n"
        "testw %ax, %ax\n"
        "js .Lfa892_0000a922\n"
        /* } scope */
        ".Lfa892_0000a91e:\n"
        "movl %edi, %eax\n" /* line 486 */
        "jmp .Lfa892_0000a8c6\n"
        /* { scope 2: volumeParms, pb */
        ".Lfa892_0000a922:\n"
        "cmpl $0, -0x178(%ebp)\n" /* line 513 */
        "ja .Lfa892_0000a937\n"
        "cmpl $0x3fffffff, -0x17c(%ebp)\n"
        "jbe .Lfa892_0000a91e\n"
        ".Lfa892_0000a937:\n"
        "cmpl $8, -0x184(%ebp)\n" /* line 532 */
        "jbe .Lfa892_0000a91e\n"
        "movzwl -0x4a4(%ebp), %eax\n" /* line 538 | volumeName */
        "movl %eax, 8(%esp)\n"
        "leal -0x4a2(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithCharacters\n"
        "movl %eax, %esi\n" /* tempRef */
        "movl $0x11, 8(%esp)\n" /* line 539 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inVolumeName */
        "movl %eax, (%esp)\n"
        "calll CFStringCompare\n"
        "movl %eax, %ebx\n" /* result */
        "movl %esi, (%esp)\n" /* line 540 | tempRef */
        "calll CFRelease\n"
        "testl %ebx, %ebx\n" /* line 541 | result */
        "jne .Lfa892_0000a91e\n"
        /* { scope 3 */
        "movl $0, -0x114(%ebp)\n" /* line 547 */
        "movzwl -0x1a(%ebp), %eax\n" /* line 548 | actualVolume */
        "movw %ax, -0x110(%ebp)\n"
        "leal -0x5c(%ebp), %eax\n" /* line 549 | volumeParms */
        "movl %eax, -0x106(%ebp)\n"
        "movl $0x20, -0x102(%ebp)\n" /* line 550 */
        "leal -0x126(%ebp), %eax\n" /* line 552 | pb */
        "movl %eax, (%esp)\n"
        "calll PBHGetVolParmsSync\n"
        "testw %ax, %ax\n" /* line 553 */
        "jne .Lfa892_0000a91e\n"
        "cmpw $3, -0x5c(%ebp)\n" /* line 557 | volumeParms */
        "jle .Lfa892_0000aaa9\n"
        "movl -0x44(%ebp), %ebx\n" /* result */
        /* { scope 4: masterPort, iter */
        /* { scope 5: iter */
        "leal -0x2c(%ebp), %eax\n" /* line 440 | masterPort, kernResult */
        "movl %eax, 4(%esp)\n" /* kernResult */
        "movl $0, (%esp)\n"
        "calll IOMasterPort\n"
        "testl %eax, %eax\n" /* line 441 */
        "jne .Lfa892_0000a91e\n"
        "movl %ebx, 8(%esp)\n" /* line 446 | isDiscMedia */
        "movl $0, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* masterPort */
        "movl %eax, (%esp)\n"
        "calll IOBSDNameMatching\n"
        "movl %eax, %edx\n" /* matchingDict */
        "testl %eax, %eax\n" /* line 447 */
        "je .Lfa892_0000a91e\n"
        "leal -0x28(%ebp), %eax\n" /* line 453 | iter */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* masterPort */
        "movl %eax, (%esp)\n"
        "calll IOServiceGetMatchingServices\n"
        "testl %eax, %eax\n" /* line 454 */
        "jne .Lfa892_0000a91e\n"
        "movl -0x28(%ebp), %eax\n" /* iter */
        "testl %eax, %eax\n"
        "je .Lfa892_0000a91e\n"
        "movl %eax, (%esp)\n" /* line 460 */
        "calll IOIteratorNext\n"
        "movl %eax, -0x4ac(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 462 | iter */
        "movl %eax, (%esp)\n"
        "calll IOObjectRelease\n"
        "movl -0x4ac(%ebp), %esi\n" /* line 464 | wholeMedia */
        "testl %esi, %esi\n" /* wholeMedia */
        "je .Lfa892_0000a91e\n"
        /* { scope 6 */
        "leal -0x24(%ebp), %eax\n" /* line 403 | iter */
        "movl %eax, 0xc(%esp)\n"
        "movl $3, 8(%esp)\n"
        "movl $str_00215908, 4(%esp)\n" /* "IOService" */
        "movl -0x4ac(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll IORegistryEntryCreateIterator\n"
        "testl %eax, %eax\n" /* line 404 */
        "jne .Lfa892_0000aa91\n"
        "movl -0x24(%ebp), %ebx\n" /* line 408 | iter, isWholeMedia */
        "testl %ebx, %ebx\n" /* isWholeMedia */
        "jne .Lfa892_0000ab07\n"
        /* { scope 7 */
        ".Lfa892_0000aa91:\n"
        "xorl %ebx, %ebx\n" /* line 420 | isDiscMedia */
        /* } scope */
        /* } scope */
        ".Lfa892_0000aa93:\n"
        "movl -0x4ac(%ebp), %eax\n" /* line 471 */
        "movl %eax, (%esp)\n"
        "calll IOObjectRelease\n"
        /* } scope */
        /* } scope */
        "testb %bl, %bl\n" /* line 559 | inBSDName */
        "je .Lfa892_0000a91e\n"
        ".Lfa892_0000aaa9:\n"
        "movl 0xc(%ebp), %edx\n" /* line 567 | outVolumePath */
        "testl %edx, %edx\n"
        "je .Lfa892_0000aadf\n"
        "movl $0x400, 8(%esp)\n" /* line 569 */
        "movl 0xc(%ebp), %edx\n" /* outVolumePath */
        "movl %edx, 4(%esp)\n"
        "leal -0xac(%ebp), %eax\n" /* rootDirectory */
        "movl %eax, (%esp)\n"
        "calll FSRefMakePath\n"
        "testl %eax, %eax\n" /* line 570 */
        "je .Lfa892_0000aaee\n"
        "movl 0xc(%ebp), %eax\n" /* line 576 | outVolumePath */
        "movb $0, (%eax)\n"
        "jmp .Lfa892_0000aadf\n"
        /* } scope */
        ".Lfa892_0000aad9:\n"
        "movw $0, -0x1a(%ebp)\n" /* line 500 | actualVolume */
        /* { scope 3 */
        ".Lfa892_0000aadf:\n"
        "movswl -0x1a(%ebp), %eax\n" /* line 576 | actualVolume */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x4cc, %esp\n" /* line 585 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: volumeInfo, volumeName, rootDirectory */
        /* { scope 2: volumeParms, pb */
        /* { scope 3 */
        ".Lfa892_0000aaee:\n"
        "cld\n" /* line 572 */
        "movl $0xffffffff, %ecx\n"
        "movl 0xc(%ebp), %edi\n" /* outVolumePath */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* outVolumePath */
        "movw $0x2f, -1(%ecx, %edx)\n"
        "jmp .Lfa892_0000aadf\n"
        /* { scope 4: masterPort, iter */
        /* { scope 5: iter */
        /* { scope 6 */
        /* { scope 7 */
        ".Lfa892_0000ab07:\n"
        "movl -0x4ac(%ebp), %eax\n" /* line 418 */
        "movl %eax, (%esp)\n"
        "calll IOObjectRetain\n"
        "movl -0x4ac(%ebp), %edx\n"
        "movl %edx, -0x4b0(%ebp)\n" /* service */
        /* { scope 8: service */
        ".Lfa892_0000ab21:\n"
        "movl $str_00215b54, 4(%esp)\n" /* line 355 */
        "movl -0x4b0(%ebp), %eax\n" /* service */
        "movl %eax, (%esp)\n"
        "calll IOObjectConformsTo\n"
        "testl %eax, %eax\n"
        "jne .Lfa892_0000ab76\n"
        /* { scope 9: iter */
        /* { scope 10: checkName */
        /* { scope 11: className */
        ".Lfa892_0000ab3b:\n"
        "xorl %eax, %eax\n" /* line 323 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfa892_0000ab3d:\n"
        "movl %eax, %ebx\n" /* line 421 | isDiscMedia */
        "movl -0x4b0(%ebp), %edx\n" /* line 422 | service */
        "movl %edx, (%esp)\n"
        "calll IOObjectRelease\n"
        "movl -0x24(%ebp), %eax\n" /* line 420 | iter */
        "movl %eax, (%esp)\n"
        "calll IOIteratorNext\n"
        "movl %eax, -0x4b0(%ebp)\n" /* service */
        "testl %eax, %eax\n"
        "je .Lfa892_0000ab66\n"
        "testb %bl, %bl\n" /* isDiscMedia */
        "je .Lfa892_0000ab21\n"
        ".Lfa892_0000ab66:\n"
        "movl -0x24(%ebp), %eax\n" /* line 425 | iter */
        "movl %eax, (%esp)\n"
        "calll IOObjectRelease\n"
        "jmp .Lfa892_0000aa93\n"
        /* { scope 8: service */
        /* { scope 9: iter */
        ".Lfa892_0000ab76:\n"
        "movl $0, 0xc(%esp)\n" /* line 357 */
        "movl kCFAllocatorDefault, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x32e7c4, 4(%esp)\n"
        "movl -0x4b0(%ebp), %edx\n" /* service */
        "movl %edx, (%esp)\n"
        "calll IORegistryEntryCreateCFProperty\n"
        "movl %eax, %esi\n" /* wholeMedia */
        "testl %eax, %eax\n" /* line 359 */
        "je .Lfa892_0000ab3b\n"
        "movl %eax, (%esp)\n" /* line 365 */
        "calll CFBooleanGetValue\n"
        "movl %eax, %ebx\n" /* isWholeMedia */
        "movl %esi, (%esp)\n" /* line 366 | wholeMedia */
        "calll CFRelease\n"
        /* } scope */
        "testb %bl, %bl\n" /* line 370 | isWholeMedia */
        "je .Lfa892_0000ab3b\n"
        "movl $str_00215b64, 4(%esp)\n" /* line 374 */
        "movl -0x4b0(%ebp), %eax\n" /* service */
        "movl %eax, (%esp)\n"
        "calll IOObjectConformsTo\n"
        "testl %eax, %eax\n"
        "jne .Lfa892_0000abf3\n"
        "movl $str_00215b70, 4(%esp)\n" /* line 378 */
        "movl -0x4b0(%ebp), %edx\n" /* service */
        "movl %edx, (%esp)\n"
        "calll IOObjectConformsTo\n"
        "testl %eax, %eax\n"
        "je .Lfa892_0000ab3b\n"
        /* { scope 9: iter */
        /* { scope 10: checkName */
        ".Lfa892_0000abf3:\n"
        "leal -0x20(%ebp), %eax\n" /* line 297 | iter */
        "movl %eax, 0xc(%esp)\n"
        "movl $3, 8(%esp)\n"
        "movl $str_00215908, 4(%esp)\n" /* "IOService" */
        "movl -0x4b0(%ebp), %eax\n" /* service */
        "movl %eax, (%esp)\n"
        "calll IORegistryEntryCreateIterator\n"
        "testl %eax, %eax\n" /* line 298 */
        "jne .Lfa892_0000ac23\n"
        "movl -0x20(%ebp), %ecx\n" /* line 302 | iter */
        "testl %ecx, %ecx\n"
        "jne .Lfa892_0000ac30\n"
        /* { scope 11: className */
        ".Lfa892_0000ac23:\n"
        "movl $1, %eax\n" /* line 323 */
        ".Lfa892_0000ac28:\n"
        "movzbl %al, %eax\n"
        "jmp .Lfa892_0000ab3d\n"
        ".Lfa892_0000ac30:\n"
        "movl -0x4b0(%ebp), %edx\n" /* line 313 | service */
        "movl %edx, (%esp)\n"
        "calll IOObjectRetain\n"
        "movb $0x72, -0x224(%ebp)\n" /* line 316 | checkName */
        "movb $0x6f, -0x223(%ebp)\n" /* line 317 */
        "movb $0x78, -0x222(%ebp)\n" /* line 318 */
        "movb $0x69, -0x221(%ebp)\n" /* line 319 */
        "movb $0x6f, -0x220(%ebp)\n" /* line 320 */
        "movb $0, -0x21f(%ebp)\n" /* line 321 */
        "movl -0x4b0(%ebp), %ebx\n" /* service */
        "movl $1, %esi\n" /* isValidParent */
        /* { scope 12 */
        ".Lfa892_0000ac73:\n"
        "leal -0x2a4(%ebp), %eax\n" /* line 325 | className */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll IOObjectGetClass\n"
        "testl %eax, %eax\n" /* line 326 */
        "jne .Lfa892_0000aca8\n"
        "leal -0x224(%ebp), %edx\n" /* line 328 | checkName */
        "movl %edx, 4(%esp)\n"
        "leal -0x2a4(%ebp), %eax\n" /* className */
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "sete %dl\n"
        "movl %edx, %esi\n" /* isValidParent */
        ".Lfa892_0000aca8:\n"
        "movl %ebx, (%esp)\n" /* line 330 */
        "calll IOObjectRelease\n"
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 323 | iter */
        "movl %eax, (%esp)\n"
        "calll IOIteratorNext\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lfa892_0000acc7\n"
        "movl %esi, %eax\n" /* isValidParent */
        "testb %al, %al\n"
        "jne .Lfa892_0000ac73\n"
        ".Lfa892_0000acc7:\n"
        "movl -0x20(%ebp), %eax\n" /* line 333 | iter */
        "movl %eax, (%esp)\n"
        "calll IOObjectRelease\n"
        "movl %esi, %eax\n" /* isValidParent */
        "jmp .Lfa892_0000ac28\n"
    );
}

/* line 594 */
__attribute__((naked))
void MacTools_CenterRect(MacRect *ioRect, const MacRect *inBounds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 594 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* inBounds */
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 596 | ioRect */
        "movzwl 6(%edx), %edx\n"
        "movw %dx, -0xe(%ebp)\n" /* rectWidth */
        "movl 8(%ebp), %edx\n" /* ioRect */
        "movzwl 2(%edx), %edx\n"
        "subw %dx, -0xe(%ebp)\n" /* rectWidth */
        "movl 8(%ebp), %edx\n" /* line 597 | ioRect */
        "movzwl 4(%edx), %ebx\n" /* rectHeight */
        "subw (%edx), %bx\n" /* rectHeight */
        "movzwl 2(%eax), %esi\n" /* line 599 */
        "movzwl (%eax), %edi\n" /* line 600 */
        "movzwl 4(%eax), %ecx\n"
        "subw %di, %cx\n"
        "movzwl 6(%eax), %eax\n" /* line 602 */
        "subw %si, %ax\n"
        "cwtl\n"
        "movswl -0xe(%ebp), %edx\n" /* rectWidth */
        "subl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "addl %edx, %esi\n"
        "movl 8(%ebp), %eax\n" /* ioRect */
        "movw %si, 2(%eax)\n"
        "movswl %cx, %ecx\n" /* line 603 */
        "movswl %bx, %eax\n" /* rectHeight */
        "subl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %ecx, %eax\n"
        "sarl $1, %eax\n"
        "addl %eax, %edi\n"
        "movl 8(%ebp), %edx\n" /* ioRect */
        "movw %di, (%edx)\n"
        "movzwl -0xe(%ebp), %edx\n" /* line 604 | rectWidth */
        "addl %esi, %edx\n"
        "movl 8(%ebp), %eax\n" /* ioRect */
        "movw %dx, 6(%eax)\n"
        "leal (%ebx, %edi), %eax\n" /* line 605 | rectHeight */
        "movl 8(%ebp), %edx\n" /* ioRect */
        "movw %ax, 4(%edx)\n"
        /* } scope */
        "addl $4, %esp\n" /* line 606 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 612 */
__attribute__((naked))
void MacTools_Sleep(UInt32 inMillisecondsToSleep)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 612 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "calll UpTime\n" /* line 614 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inMillisecondsToSleep */
        "movl %eax, (%esp)\n"
        "calll AddDurationToAbsolute\n"
        "movl %eax, -0x10(%ebp)\n" /* expirationTime */
        "movl %edx, -0xc(%ebp)\n"
        "leal -0x10(%ebp), %eax\n" /* line 615 | expirationTime */
        "movl %eax, (%esp)\n"
        "calll MPDelayUntil\n"
        /* } scope */
        "leave\n" /* line 617 */
        "retl\n"
    );
}

/* line 660 */
__attribute__((naked))
void MacTools_SendQuitAppleEvent(const ProcessSerialNumber *inPSN)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 660 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 664 | inPSN */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* theTarget */
        "movl %esi, (%esp)\n"
        "calll CAETarget_CAETarget\n"
        "leal -0x28(%ebp), %ebx\n" /* line 666 | theEvent */
        "movl %ebx, (%esp)\n"
        "calll CAEEvent_CAEEvent\n"
        "movl $0x71756974, 0xc(%esp)\n" /* line 667 */
        "movl $0x61657674, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CAEEvent_Create\n"
        "movl %ebx, (%esp)\n" /* line 669 */
        "calll CAEEvent_Send\n"
        "movl %ebx, (%esp)\n"
        "calll ZN8CAEEventD1Ev\n"
        "movl %esi, (%esp)\n"
        "calll ZN9CAETargetD1Ev\n"
        /* } scope */
        ".Lfad9e_0000adf8:\n"
        "addl $0x2c, %esp\n" /* line 675 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %edi\n"
        ".Lfad9e_0000ae02:\n"
        "movl %edi, (%esp)\n" /* line 671 */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        "jmp .Lfad9e_0000adf8\n"
        "movl %eax, %edi\n"
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 669 */
        "calll ZN8CAEEventD1Ev\n"
        ".Lfad9e_0000ae1b:\n"
        "movl %esi, (%esp)\n"
        "calll ZN9CAETargetD1Ev\n"
        "jmp .Lfad9e_0000ae02\n"
        "movl %eax, %edi\n"
        "jmp .Lfad9e_0000ae1b\n"
    );
}

/* line 716 */
__attribute__((naked))
Boolean MacTools_FindApplicationPSN(OSType inCreatorCode, ProcessSerialNumber *outPSN)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 716 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %edi\n" /* inCreatorCode */
        "movl 0xc(%ebp), %ebx\n" /* outPSN */
        "movl $0, 4(%ebx)\n" /* line 720 | outPSN */
        "movl $0, (%ebx)\n" /* outPSN */
        "leal -0x54(%ebp), %esi\n" /* info */
        ".Lfae2a_0000ae49:\n"
        "movl %ebx, (%esp)\n" /* line 722 | outPSN */
        "calll GetNextProcess\n"
        "testw %ax, %ax\n"
        "jne .Lfae2a_0000ae97\n"
        /* { scope 1 */
        "movl $0x3c, -0x54(%ebp)\n" /* line 725 | info */
        "movl $0, -0x50(%ebp)\n" /* line 726 */
        "movl $0, -0x1c(%ebp)\n" /* line 727 */
        "movl %esi, 4(%esp)\n" /* line 729 */
        "movl %ebx, (%esp)\n" /* outPSN */
        "calll GetProcessInformation\n"
        "testw %ax, %ax\n" /* line 730 */
        "jne .Lfae2a_0000ae49\n"
        "cmpl %edi, -0x40(%ebp)\n" /* line 732 | inCreatorCode */
        "jne .Lfae2a_0000ae49\n"
        "cmpl $0x4150504c, -0x44(%ebp)\n"
        "jne .Lfae2a_0000ae49\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 741 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfae2a_0000ae97:\n"
        "xorl %eax, %eax\n" /* line 722 */
        "addl $0x5c, %esp\n" /* line 741 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 750 */
__attribute__((naked))
SInt32 MacTools_GetDictionaryValue(CFDictionaryRef inDictionaryRef, CFStringRef inKeyRef)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 750 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1: floatValue */
        "movl 0xc(%ebp), %eax\n" /* line 752 | inKeyRef */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inDictionaryRef */
        "movl %eax, (%esp)\n"
        "calll CFDictionaryGetValue\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 753 */
        "je .Lfaea2_0000aee5\n"
        "leal -0xc(%ebp), %eax\n" /* line 759 | intValue */
        "movl %eax, 8(%esp)\n"
        "movl $0xa, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CFNumberGetValue\n"
        "testb %al, %al\n"
        "je .Lfaea2_0000aef0\n"
        "movl -0xc(%ebp), %eax\n" /* intValue */
        /* } scope */
        ".Lfaea2_0000aedf:\n"
        "addl $0x24, %esp\n" /* line 772 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: floatValue */
        ".Lfaea2_0000aee5:\n"
        "movl $0xffffffff, %eax\n" /* line 771 */
        /* } scope */
        "addl $0x24, %esp\n" /* line 772 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: floatValue */
        /* { scope 2 */
        ".Lfaea2_0000aef0:\n"
        "leal -0x18(%ebp), %eax\n" /* line 763 | floatValue */
        "movl %eax, 8(%esp)\n"
        "movl $0xd, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CFNumberGetValue\n"
        "testb %al, %al\n"
        "je .Lfaea2_0000aee5\n"
        "movsd -0x18(%ebp), %xmm0\n" /* line 768 | floatValue */
        "movsd %xmm0, (%esp)\n"
        "calll lround\n"
        "movl %eax, -0xc(%ebp)\n" /* intValue */
        "jmp .Lfaea2_0000aedf\n"
    );
}

/* line 780 */
__attribute__((naked))
Boolean MacTools_GetIORegistryValue(io_registry_entry_t inEntryRef, CFStringRef inKeyRef, char *outValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 780 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $0, 0xc(%esp)\n" /* line 782 */
        "movl $0, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inKeyRef */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inEntryRef */
        "movl %eax, (%esp)\n"
        "calll IORegistryEntryCreateCFProperty\n"
        "movl %eax, %ebx\n" /* dataRef */
        "testl %eax, %eax\n" /* line 783 */
        "je .Lfaf20_0000af79\n"
        "movl %eax, (%esp)\n" /* line 788 */
        "calll CFDataGetBytePtr\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* outValue */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl %ebx, (%esp)\n" /* line 790 | dataRef */
        "calll CFRelease\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 793 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf20_0000af79:\n"
        "xorl %eax, %eax\n" /* line 783 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 793 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* overload skip: MacTools_GetIORegistryValue (0xaf82) */

/* line 935 */
__attribute__((naked))
Boolean MacTools_PostPrivateEventToWindow(WindowRef inWindow, UInt32 inMessage, UInt32 inParam1, UInt32 inParam2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 935 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1: targetRef */
        "leal -0xc(%ebp), %eax\n" /* line 938 | eventRef */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inMessage */
        "movl %eax, 8(%esp)\n"
        "movl $0x50726976, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CreateEvent\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 939 */
        "jne .Lfafc6_0000b0c6\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 941 | inWindow */
        "movl %eax, (%esp)\n"
        "calll GetWindowEventTarget\n"
        "movl %eax, -0x10(%ebp)\n" /* targetRef */
        "leal -0x10(%ebp), %eax\n" /* line 942 | targetRef */
        "movl %eax, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $0x65747267, 8(%esp)\n"
        "movl $0x70747267, 4(%esp)\n"
        "movl -0xc(%ebp), %eax\n" /* eventRef */
        "movl %eax, (%esp)\n"
        "calll SetEventParameter\n"
        "leal 0x10(%ebp), %eax\n" /* line 944 | inParam1 */
        "movl %eax, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x504f6e65, 4(%esp)\n"
        "movl -0xc(%ebp), %eax\n" /* eventRef */
        "movl %eax, (%esp)\n"
        "calll SetEventParameter\n"
        "leal 0x14(%ebp), %eax\n" /* line 945 | inParam2 */
        "movl %eax, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $0x6d61676e, 8(%esp)\n"
        "movl $0x5054776f, 4(%esp)\n"
        "movl -0xc(%ebp), %eax\n" /* eventRef */
        "movl %eax, (%esp)\n"
        "calll SetEventParameter\n"
        "movl -0xc(%ebp), %ebx\n" /* line 947 | eventRef, error */
        "calll GetMainEventQueue\n"
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* error */
        "movl %eax, (%esp)\n"
        "calll PostEventToQueue\n"
        "movl %eax, %ebx\n" /* error */
        "movl -0xc(%ebp), %eax\n" /* line 949 | eventRef */
        "movl %eax, (%esp)\n"
        "calll ReleaseEvent\n"
        ".Lfafc6_0000b0c6:\n"
        "xorl %eax, %eax\n"
        "testl %ebx, %ebx\n" /* error */
        "sete %al\n"
        /* } scope */
        /* } scope */
        "addl $0x34, %esp\n" /* line 953 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1105 */
__attribute__((naked))
Boolean MacTools_QuestionAlert(CFStringRef inMessage1, CFStringRef inMessage2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1105 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1: dialogRef */
        "calll pthread_main_np\n" /* line 1107 */
        "testl %eax, %eax\n"
        "jne .Lfb0d4_0000b0ee\n"
        ".Lfb0d4_0000b0e4:\n"
        "xorl %ebx, %ebx\n" /* line 39 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1141 */
        "addl $0x54, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dialogRef */
        ".Lfb0d4_0000b0ee:\n"
        "calll MacDisplay_IsFullscreen\n" /* line 1107 */
        "testb %al, %al\n"
        "jne .Lfb0d4_0000b0e4\n"
        "calll MacGlobals_LockSystem\n" /* line 33 */
        "movl $1, 4(%esp)\n" /* line 1121 */
        "leal -0x2c(%ebp), %ebx\n" /* params */
        "movl %ebx, (%esp)\n"
        "calll GetStandardAlertDefaultParams\n"
        "testl %eax, %eax\n" /* line 1122 */
        "jne .Lfb0d4_0000b149\n"
        /* { scope 2: itemHit */
        "movl $0xffffffff, -0x22(%ebp)\n" /* line 1124 */
        "movw $2, -0x18(%ebp)\n" /* line 1125 */
        "leal -0x10(%ebp), %eax\n" /* line 1128 | dialogRef */
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inMessage2 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inMessage1 */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll CreateStandardAlert\n"
        "testl %eax, %eax\n" /* line 1129 */
        "je .Lfb0d4_0000b158\n"
        /* { scope 3 */
        ".Lfb0d4_0000b149:\n"
        "xorl %ebx, %ebx\n" /* line 1134 */
        /* } scope */
        /* } scope */
        "calll MacGlobals_UnlockSystem\n" /* line 38 */
        /* } scope */
        ".Lfb0d4_0000b150:\n"
        "movl %ebx, %eax\n" /* line 1141 */
        "addl $0x54, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dialogRef */
        /* { scope 2: itemHit */
        /* { scope 3 */
        ".Lfb0d4_0000b158:\n"
        "calll InitCursor\n" /* line 1131 */
        "movw $0, -0xa(%ebp)\n" /* line 1133 | itemHit */
        "leal -0xa(%ebp), %eax\n" /* line 1134 | itemHit */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x10(%ebp), %eax\n" /* dialogRef */
        "movl %eax, (%esp)\n"
        "calll RunStandardAlert\n"
        "xorl %ebx, %ebx\n"
        "cmpw $1, -0xa(%ebp)\n" /* itemHit */
        "sete %bl\n"
        /* } scope */
        /* } scope */
        "calll MacGlobals_UnlockSystem\n" /* line 38 */
        "jmp .Lfb0d4_0000b150\n"
        "movl %eax, %ebx\n"
        "calll MacGlobals_UnlockSystem\n"
        "movl %ebx, (%esp)\n" /* line 39 */
        "calll __Unwind_Resume\n"
    );
}

/* overload skip: MacTools_QuestionAlert (0xb19e) */

/* line 1158 */
__attribute__((naked))
void ZN12StShowCursorD1Ev(void) /* StShowCursor_~StShowCursor */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1158 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 1160 | this */
        "cmpb $0, (%eax)\n"
        "je .Lfb224_0000b231\n"
        "popl %ebp\n" /* line 1164 */
        "retl\n"
        ".Lfb224_0000b231:\n"
        "movl $1, 8(%ebp)\n" /* line 1162 | this */
        "popl %ebp\n" /* line 1164 */
        "jmp MacTools_HideCursor\n" /* line 1162 */
    );
}

/* line 1028 */
__attribute__((naked))
void MacTools_MessageAlert(CFStringRef inMessage1, CFStringRef inMessage2, int inStop)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1028 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movzbl 0x10(%ebp), %ebx\n" /* inStop */
        /* { scope 1: itemHit */
        "calll pthread_main_np\n" /* line 1030 */
        "testl %eax, %eax\n"
        "jne .Lfb23e_0000b258\n"
        /* } scope */
        ".Lfb23e_0000b252:\n"
        "addl $0x34, %esp\n" /* line 1050 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: itemHit */
        ".Lfb23e_0000b258:\n"
        "calll MacDisplay_IsFullscreen\n" /* line 1030 */
        "testb %al, %al\n"
        "jne .Lfb23e_0000b252\n"
        "calll MacGlobals_LockSystem\n" /* line 33 */
        "leal -0x10(%ebp), %eax\n" /* line 1042 | dialogRef, error */
        "movl %eax, 0x10(%esp)\n" /* error */
        "movl $0, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inMessage2, error */
        "movl %eax, 8(%esp)\n" /* error */
        "movl 8(%ebp), %eax\n" /* inMessage1, error */
        "movl %eax, 4(%esp)\n" /* error */
        "xorl %eax, %eax\n" /* error */
        "testb %bl, %bl\n" /* inStop */
        "sete %al\n" /* error */
        "movl %eax, (%esp)\n" /* error */
        "calll CreateStandardAlert\n"
        "testl %eax, %eax\n" /* line 1043 */
        "jne .Lfb23e_0000b2b5\n"
        /* { scope 2 */
        "calll InitCursor\n" /* line 1045 */
        "leal -0xa(%ebp), %eax\n" /* line 1048 | itemHit */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x10(%ebp), %eax\n" /* dialogRef */
        "movl %eax, (%esp)\n"
        "calll RunStandardAlert\n"
        /* } scope */
        ".Lfb23e_0000b2b5:\n"
        "calll MacGlobals_UnlockSystem\n" /* line 38 */
        /* } scope */
        "addl $0x34, %esp\n" /* line 1050 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* inStop */
        /* { scope 1: itemHit */
        "calll MacGlobals_UnlockSystem\n" /* line 38 */
        "movl %ebx, (%esp)\n" /* line 39 */
        "calll __Unwind_Resume\n"
    );
}

/* overload skip: MacTools_MessageAlert (0xb2d0) */

/* overload skip: MacTools_MessageAlert (0xb2f4) */

/* line 962 */
__attribute__((naked))
void MacTools_MessageAlertFromKey(CFStringRef inKeyRef, int inStop)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 962 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* inKeyRef */
        "movzbl 0xc(%ebp), %esi\n" /* inStop */
        /* { scope 1 */
        "calll CFBundleGetMainBundle\n" /* line 964 */
        "movl $0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* messageRef */
        "movl %ebx, 4(%esp)\n" /* messageRef */
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, %ebx\n" /* messageRef */
        "testl %eax, %eax\n" /* line 965 */
        "je .Lfb37e_0000b3d7\n"
        "movl %esi, %edx\n" /* line 967 | inStop */
        "movzbl %dl, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* messageRef */
        "calll MacTools_MessageAlert\n"
        "movl %ebx, 8(%ebp)\n" /* line 968 | messageRef, inKeyRef */
        /* } scope */
        "addl $0x10, %esp\n" /* line 970 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CFRelease\n" /* line 968 */
        /* } scope */
        ".Lfb37e_0000b3d7:\n"
        "addl $0x10, %esp\n" /* line 970 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 156 */
__attribute__((naked))
Boolean SearchForApplication(OSType inCreator, FSRef *outAppRef)
{
    __asm__ __volatile__ (
        ".Lfb3de_0000b3de:\n"
        "pushl %ebp\n" /* line 156 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1ac, %esp\n"
        "movl %eax, %ebx\n" /* inDirRef */
        "movl %edx, -0x178(%ebp)\n"
        "movl %ecx, -0x17c(%ebp)\n"
        /* { scope 1: ref, count, changed */
        "movl $0x1c20, (%esp)\n" /* line 129 */
        "calll __Znam\n"
        "movl %eax, -0x170(%ebp)\n"
        "movl $0xfa0, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, -0x16c(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* line 85 | directoryList */
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 167 | iterator */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* inDirRef */
        "calll FSOpenIterator\n"
        "testw %ax, %ax\n" /* line 168 */
        "je .Lfb3de_0000b505\n"
        ".Lfb3de_0000b451:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 334 | directoryList */
        "movl %ecx, %ebx\n" /* line 218 | inDirRef */
        "movl -0x2c(%ebp), %edx\n" /* line 352 */
        "cmpl %edx, %ecx\n" /* line 218 */
        "je .Lfb3de_0000b49c\n"
        "leal -0x80(%ebp), %esi\n" /* ref */
        /* { scope 2 */
        ".Lfb3de_0000b460:\n"
        "movl $0x50, 8(%esp)\n" /* line 220 */
        "movl %ebx, 4(%esp)\n" /* inDirRef */
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "movl -0x17c(%ebp), %ecx\n" /* line 221 */
        "movl -0x178(%ebp), %edx\n"
        "movl %esi, %eax\n"
        "calll SearchForApplication\n"
        "testb %al, %al\n"
        "jne .Lfb3de_0000b649\n"
        /* } scope */
        "addl $0x50, %ebx\n" /* line 623 | inDirRef */
        "movl -0x2c(%ebp), %edx\n" /* line 352 */
        "cmpl %ebx, %edx\n" /* line 218 | inDirRef */
        "jne .Lfb3de_0000b460\n"
        "movl -0x30(%ebp), %ecx\n" /* directoryList */
        ".Lfb3de_0000b49c:\n"
        "xorl %ebx, %ebx\n" /* line 273 | inDirRef */
        ".Lfb3de_0000b49e:\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lfb3de_0000b4ab\n"
        ".Lfb3de_0000b4a4:\n"
        "addl $0x50, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lfb3de_0000b4a4\n"
        ".Lfb3de_0000b4ab:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lfb3de_0000b4b7\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lfb3de_0000b4b7:\n"
        "movl -0x16c(%ebp), %eax\n" /* line 134 */
        "testl %eax, %eax\n"
        "je .Lfb3de_0000b4cf\n"
        "movl -0x16c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lfb3de_0000b4cf:\n"
        "movl -0x170(%ebp), %edi\n"
        "testl %edi, %edi\n"
        "je .Lfb3de_0000b4e7\n"
        "movl -0x170(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfb3de_0000b4e7:\n"
        "movl %ebx, %eax\n" /* line 228 | inDirRef */
        "addl $0x1ac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ref, count, changed */
        /* { scope 2 */
        ".Lfb3de_0000b4f4:\n"
        "movl -0x24(%ebp), %eax\n" /* line 175 | count */
        "testl %eax, %eax\n"
        "jne .Lfb3de_0000b574\n"
        /* } scope */
        ".Lfb3de_0000b4fb:\n"
        "cmpw $0, -0x172(%ebp)\n" /* line 170 */
        "jne .Lfb3de_0000b564\n"
        /* { scope 2 */
        ".Lfb3de_0000b505:\n"
        "movl $0, 0x20(%esp)\n" /* line 174 */
        "movl $0, 0x1c(%esp)\n"
        "movl -0x16c(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x170(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "leal -0x19(%ebp), %eax\n" /* changed */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* count */
        "movl %eax, 8(%esp)\n"
        "movl $0x32, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* iterator */
        "movl %eax, (%esp)\n"
        "calll FSGetCatalogInfoBulk\n"
        "movw %ax, -0x172(%ebp)\n"
        "testw %ax, %ax\n" /* line 175 */
        "je .Lfb3de_0000b4f4\n"
        "cmpw $0xfa77, %ax\n"
        "je .Lfb3de_0000b4f4\n"
        /* } scope */
        ".Lfb3de_0000b564:\n"
        "movl -0x20(%ebp), %eax\n" /* line 214 | iterator */
        "movl %eax, (%esp)\n"
        "calll FSCloseIterator\n"
        "jmp .Lfb3de_0000b451\n"
        /* { scope 2 */
        ".Lfb3de_0000b574:\n"
        "movl -0x170(%ebp), %ebx\n" /* line 175 | inDirRef */
        "movl -0x16c(%ebp), %esi\n"
        "xorl %edi, %edi\n"
        "jmp .Lfb3de_0000b599\n"
        /* { scope 3: catInfo */
        ".Lfb3de_0000b584:\n"
        "addl $1, %edi\n" /* line 177 | i */
        "addl $0x90, %ebx\n" /* inDirRef */
        "addl $0x50, %esi\n"
        "cmpl -0x24(%ebp), %edi\n" /* count, i */
        "jae .Lfb3de_0000b4fb\n"
        /* { scope 4: ref, itemInfo */
        ".Lfb3de_0000b599:\n"
        "movl $0x90, 8(%esp)\n" /* line 179 */
        "movl %ebx, 4(%esp)\n" /* inDirRef */
        "leal -0x160(%ebp), %eax\n" /* catInfo */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "testb $0x10, -0x160(%ebp)\n" /* line 180 | catInfo */
        "je .Lfb3de_0000b584\n"
        /* { scope 5 */
        "movl $0x50, 8(%esp)\n" /* line 182 */
        "movl %esi, 4(%esp)\n"
        "leal -0xd0(%ebp), %eax\n" /* ref */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal -0x80(%ebp), %eax\n" /* line 184 | ref */
        "movl %eax, 8(%esp)\n"
        "movl $6, 4(%esp)\n"
        "leal -0xd0(%ebp), %eax\n" /* ref */
        "movl %eax, (%esp)\n"
        "calll LSCopyItemInfoForRef\n"
        "testl %eax, %eax\n"
        "jne .Lfb3de_0000b584\n"
        "movl -0x80(%ebp), %eax\n" /* line 186 | ref */
        "testb $0x40, %al\n"
        "jne .Lfb3de_0000b584\n"
        "testb $2, %al\n" /* line 188 */
        "je .Lfb3de_0000b659\n"
        "testb $4, %al\n" /* line 191 */
        "je .Lfb3de_0000b584\n"
        "movl -0x178(%ebp), %eax\n" /* line 194 */
        "cmpl -0x78(%ebp), %eax\n"
        "jne .Lfb3de_0000b584\n"
        "movl $0x50, 8(%esp)\n" /* line 197 */
        "leal -0xd0(%ebp), %eax\n" /* ref */
        "movl %eax, 4(%esp)\n"
        "movl -0x17c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $1, %ebx\n" /* inDirRef */
        "movl -0x2c(%ebp), %edx\n"
        "movl -0x30(%ebp), %ecx\n" /* directoryList */
        "jmp .Lfb3de_0000b49e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfb3de_0000b649:\n"
        "movl $1, %ebx\n" /* line 273 | inDirRef */
        "movl -0x2c(%ebp), %edx\n"
        "movl -0x30(%ebp), %ecx\n" /* directoryList */
        "jmp .Lfb3de_0000b49e\n"
        /* { scope 2 */
        /* { scope 3: catInfo */
        /* { scope 4: ref, itemInfo */
        /* { scope 5 */
        ".Lfb3de_0000b659:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 604 */
        "cmpl -0x28(%ebp), %edx\n"
        "je .Lfb3de_0000b68d\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lfb3de_0000b682\n"
        "movl $0x50, 8(%esp)\n"
        "leal -0xd0(%ebp), %eax\n" /* ref */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x2c(%ebp), %edx\n"
        ".Lfb3de_0000b682:\n"
        "addl $0x50, %edx\n" /* line 607 */
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lfb3de_0000b584\n"
        ".Lfb3de_0000b68d:\n"
        "leal -0xd0(%ebp), %eax\n" /* line 610 | ref */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* directoryList */
        "movl %eax, (%esp)\n"
        "calll ZNSt6vectorI5FSRefSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_\n"
        "jmp .Lfb3de_0000b584\n"
        "movl %eax, %ebx\n" /* inDirRef */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfb3de_0000b6ad:\n"
        "movl -0x170(%ebp), %eax\n" /* line 134 */
        "testl %eax, %eax\n"
        "je .Lfb3de_0000b6c5\n"
        "movl -0x170(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lfb3de_0000b6c5:\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl -0x2c(%ebp), %edx\n" /* line 273 */
        "movl -0x30(%ebp), %ecx\n" /* directoryList */
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lfb3de_0000b6e2\n"
        ".Lfb3de_0000b6db:\n"
        "addl $0x50, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lfb3de_0000b6db\n"
        ".Lfb3de_0000b6e2:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lfb3de_0000b6ee\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lfb3de_0000b6ee:\n"
        "movl -0x16c(%ebp), %eax\n" /* line 134 */
        "testl %eax, %eax\n"
        "je .Lfb3de_0000b6ad\n"
        "movl -0x16c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        "jmp .Lfb3de_0000b6ad\n"
    );
}

/* line 1147 */
__attribute__((naked))
void StShowCursor_StShowCursor(const StShowCursor * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1147 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movzbl sSystemCursorVisible, %ecx\n" /* line 145 */
        "movzbl %cl, %edx\n" /* line 1148 */
        "movl 8(%ebp), %eax\n" /* this */
        "movb %dl, (%eax)\n"
        "testl %edx, %edx\n" /* line 1150 */
        "jne .Lfb708_0000b725\n"
        "testb %cl, %cl\n" /* line 64 */
        "je .Lfb708_0000b727\n"
        ".Lfb708_0000b725:\n"
        "leave\n" /* line 1154 */
        "retl\n"
        ".Lfb708_0000b727:\n"
        "movl $1, (%esp)\n" /* line 66 */
        "calll CGAssociateMouseAndMouseCursorPosition\n"
        "calll InitCursor\n" /* line 85 */
        "movb $1, sSystemCursorVisible\n" /* line 87 */
        "leave\n" /* line 1154 */
        "retl\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorI5FSRefSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<FSRef, std_allocator<FSRef> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 251 | this */
        "movl 4(%edx), %eax\n"
        "cmpl 8(%edx), %eax\n"
        "je .Lf2bc012_002bc0f8\n"
        "leal -0x50(%eax), %edx\n"
        /* { scope 1 */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 104 */
        "je .Lf2bc012_002bc216\n"
        "movl $0x50, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n"
        /* } scope */
        ".Lf2bc012_002bc058:\n"
        "movl %eax, %esi\n" /* line 255 */
        "addl $0x50, %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl $0x50, 8(%esp)\n" /* line 256 */
        "movl 0x10(%ebp), %eax\n" /* __x */
        "movl %eax, 4(%esp)\n"
        "leal -0x68(%ebp), %edx\n" /* __x_copy */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "leal -0x50(%esi), %ebx\n" /* line 257 */
        /* { scope 2 */
        "movl %ebx, %ecx\n" /* line 411 */
        "subl -0x6c(%ebp), %ecx\n"
        "sarl $4, %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf2bc012_002bc0d3\n"
        "movl %ebx, %edx\n"
        "movl %esi, %eax\n"
        "xorl %edi, %edi\n"
        ".Lf2bc012_002bc0ad:\n"
        "leal -0x50(%eax), %esi\n" /* line 412 */
        "leal -0x50(%edx), %ebx\n"
        "movl $0x50, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %edi\n"
        "movl %ebx, %edx\n"
        "movl %esi, %eax\n"
        "cmpl %edi, -0x78(%ebp)\n" /* line 411 */
        "jne .Lf2bc012_002bc0ad\n"
        /* } scope */
        ".Lf2bc012_002bc0d3:\n"
        "movl $0x50, 8(%esp)\n" /* line 260 */
        "leal -0x68(%ebp), %eax\n" /* __x_copy */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bc012_002bc0f8:\n"
        "movl %eax, %ecx\n" /* line 759 */
        "subl (%edx), %ecx\n"
        "sarl $4, %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "cmpl $0x3333333, %eax\n" /* line 265 */
        "je .Lf2bc012_002bc240\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bc012_002bc21e\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bc012_002bc132:\n"
        "leal (%edx, %edx, 4), %edx\n" /* line 88 */
        "shll $4, %edx\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 279 | this */
        "movl (%eax), %esi\n"
        /* { scope 2 */
        "movl -0x74(%ebp), %ebx\n" /* line 82 */
        "cmpl %esi, 0xc(%ebp)\n" /* line 85 | __position */
        "je .Lf2bc012_002bc17c\n"
        "movl %esi, %eax\n"
        "jmp .Lf2bc012_002bc159\n"
        ".Lf2bc012_002bc157:\n"
        "movl %eax, %esi\n"
        ".Lf2bc012_002bc159:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bc012_002bc171\n"
        "movl $0x50, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bc012_002bc171:\n"
        "leal 0x50(%esi), %eax\n" /* line 623 */
        "addl $0x50, %ebx\n"
        "cmpl %eax, 0xc(%ebp)\n" /* line 85 | __position */
        "jne .Lf2bc012_002bc157\n"
        /* } scope */
        ".Lf2bc012_002bc17c:\n"
        "testl %ebx, %ebx\n" /* line 104 */
        "je .Lf2bc012_002bc197\n"
        "movl $0x50, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bc012_002bc197:\n"
        "movl 8(%ebp), %eax\n" /* line 286 | this */
        "addl $4, %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 603 | this */
        "movl 4(%edx), %edi\n"
        "movl -0x6c(%ebp), %eax\n" /* line 286 */
        /* { scope 2 */
        "addl $0x50, %ebx\n" /* line 82 */
        "cmpl %eax, %edi\n" /* line 85 */
        "je .Lf2bc012_002bc1d4\n"
        ".Lf2bc012_002bc1b0:\n"
        "movl %eax, %esi\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bc012_002bc1ca\n"
        "movl $0x50, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bc012_002bc1ca:\n"
        "leal 0x50(%esi), %eax\n" /* line 623 */
        "addl $0x50, %ebx\n"
        "cmpl %edi, %eax\n" /* line 85 */
        "jne .Lf2bc012_002bc1b0\n"
        /* } scope */
        ".Lf2bc012_002bc1d4:\n"
        "movl -0x70(%ebp), %eax\n" /* line 352 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* line 334 | this */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bc012_002bc1eb\n"
        ".Lf2bc012_002bc1e4:\n"
        "addl $0x50, %eax\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 173 */
        "jne .Lf2bc012_002bc1e4\n"
        ".Lf2bc012_002bc1eb:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bc012_002bc1f7\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bc012_002bc1f7:\n"
        "movl -0x74(%ebp), %eax\n" /* line 302 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl %ebx, 4(%edx)\n" /* line 303 */
        "movl -0x74(%ebp), %eax\n" /* line 304 */
        "addl -0x7c(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x8c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bc012_002bc216:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "jmp .Lf2bc012_002bc058\n"
        /* { scope 1 */
        ".Lf2bc012_002bc21e:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bc012_002bc236\n"
        "cmpl $0x3333333, %edx\n" /* line 85 */
        "jbe .Lf2bc012_002bc132\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bc012_002bc236:\n"
        "movl $0x3333333, %edx\n" /* line 272 */
        "jmp .Lf2bc012_002bc132\n"
        ".Lf2bc012_002bc240:\n"
        "movl $str_00215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}

