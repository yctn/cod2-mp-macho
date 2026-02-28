/* ASM dump from: VK_Map.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/VK_Map.cp */

#include "common_types.h"
#include "imports.h"

extern UInt8 sFrench_ISO_VK_Map[128]; /* 0x0 */
extern UInt8 sGerman_ISO_VK_Map[128]; /* 0x0 */
static UInt8 *sCachedVKMap; /* 0x334c80 */
static UInt8 sANSI_VK_Map[128]; /* 0x3081c0 */

UInt8 TranslateKeyCodeToVK(UInt32 inKeyCode);

/* line 432 */
__attribute__((naked))
UInt8 TranslateKeyCodeToVK(UInt32 inKeyCode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 432 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "movl sCachedVKMap, %eax\n" /* line 437 */
        "testl %eax, %eax\n"
        "je .Lfd650_0000d66d\n"
        "movl sCachedVKMap, %eax\n"
        ".Lfd650_0000d664:\n"
        "movl 8(%ebp), %edx\n" /* line 449 | inKeyCode */
        "movzbl (%eax, %edx), %eax\n"
        /* } scope */
        "leave\n" /* line 454 */
        "retl\n"
        /* { scope 1 */
        ".Lfd650_0000d66d:\n"
        "calll MacResources_GetLanguageCode\n" /* line 439 */
        "subl $1, %eax\n"
        "jne .Lfd650_0000d688\n"
        "movl $0x308140, sCachedVKMap\n" /* line 441 */
        "movl sCachedVKMap, %eax\n"
        "jmp .Lfd650_0000d664\n"
        ".Lfd650_0000d688:\n"
        "calll MacResources_GetLanguageCode\n" /* line 443 */
        "movl $sGerman_ISO_VK_Map, %edx\n" /* line 445 */
        "cmpl $2, %eax\n"
        "movl $sANSI_VK_Map, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl %edx, sCachedVKMap\n"
        "movl %edx, %eax\n"
        "jmp .Lfd650_0000d664\n"
    );
}

