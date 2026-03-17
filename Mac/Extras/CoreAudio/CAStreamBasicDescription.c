/* ASM dump from: CAStreamBasicDescription.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Extras/CoreAudio/CAStreamBasicDescription.cpp */

#include "common_types.h"
#include "imports.h"

void CAStreamBasicDescription_SetCanonical(const CAStreamBasicDescription * _this, UInt32 nChannels, int interleaved);
void CAStreamBasicDescription_CAStreamBasicDescription(const CAStreamBasicDescription * _this);

/* line 124 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void CAStreamBasicDescription_SetCanonical(const CAStreamBasicDescription * _this, UInt32 nChannels, int interleaved)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 124 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* nChannels */
        "movl $0x6c70636d, 8(%edx)\n" /* line 127 */
        "movl $9, 0xc(%edx)\n" /* line 128 */
        "movl $0x20, 0x20(%edx)\n" /* line 129 */
        "movl %eax, 0x1c(%edx)\n" /* line 130 */
        "movl $1, 0x14(%edx)\n" /* line 131 */
        "cmpb $0, 0x10(%ebp)\n" /* line 132 | interleaved */
        "je .Lf114354_0011438d\n"
        "shll $2, %eax\n" /* line 133 */
        "movl %eax, 0x18(%edx)\n"
        "movl %eax, 0x10(%edx)\n"
        "popl %ebp\n" /* line 138 */
        "retl\n"
        ".Lf114354_0011438d:\n"
        "movl $4, 0x18(%edx)\n" /* line 135 */
        "movl $4, 0x10(%edx)\n"
        "movl $0x29, 0xc(%edx)\n" /* line 136 */
        "popl %ebp\n" /* line 138 */
        "retl\n"
    );
}
#else
void CAStreamBasicDescription_SetCanonical(const CAStreamBasicDescription * _this, UInt32 nChannels, int interleaved) { }
#endif

/* line 56 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void CAStreamBasicDescription_CAStreamBasicDescription(const CAStreamBasicDescription * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "movl 8(%ebp), %edi\n" /* this */
        "cld\n"
        "movl $0xa, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* this */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void CAStreamBasicDescription_CAStreamBasicDescription(const CAStreamBasicDescription * _this) { }
#endif

