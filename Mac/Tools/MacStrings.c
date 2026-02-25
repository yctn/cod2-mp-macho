/* ASM dump from: MacStrings.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacStrings.cp */

#include "common_types.h"
#include "imports.h"

void MacStrings_GetCString(const HFSUniStr255 *inUniStr, char *outCString, int inMaxString);
void MacStrings_CopyAndClean(const char *inSrcString, char *inDstString, int inDstSize);

/* line 33 */
__attribute__((naked))
void MacStrings_GetCString(const HFSUniStr255 *inUniStr, char *outCString, int inMaxString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 33 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edx\n" /* inUniStr */
        "movl 0xc(%ebp), %esi\n" /* outCString */
        "movl 0x10(%ebp), %edi\n" /* inMaxString */
        /* { scope 1 */
        "movb $0, (%esi)\n" /* line 35 | outCString */
        "movzwl (%edx), %eax\n" /* line 37 */
        "movl %eax, 8(%esp)\n"
        "addl $2, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithCharacters\n"
        "movl %eax, %ebx\n" /* stringRef */
        "testl %eax, %eax\n" /* line 38 */
        "je .Lfa5dc_0000a63b\n"
        "movl $0, 0xc(%esp)\n" /* line 40 */
        "movswl %di, %eax\n" /* inMaxString */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* outCString */
        "movl %ebx, (%esp)\n" /* stringRef */
        "calll CFStringGetCString\n"
        "movl %ebx, 8(%ebp)\n" /* line 42 | stringRef, inUniStr */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 44 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CFRelease\n" /* line 42 */
        /* } scope */
        ".Lfa5dc_0000a63b:\n"
        "addl $0x1c, %esp\n" /* line 44 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 163 */
__attribute__((naked))
void MacStrings_CopyAndClean(const char *inSrcString, char *inDstString, int inDstSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 163 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %ecx\n" /* inSrcString */
        "movl 0xc(%ebp), %edi\n" /* inDstString */
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 165 | inDstSize */
        "subl $1, %eax\n"
        "xorl %ebx, %ebx\n"
        "movb $0, -0xd(%ebp)\n" /* hadSpace */
        "xorl %esi, %esi\n"
        "cwtl\n"
        ".Lfa644_0000a662:\n"
        "movzbl (%ecx), %edx\n" /* line 171 */
        "testb %dl, %dl\n"
        "je .Lfa644_0000a692\n"
        ".Lfa644_0000a669:\n"
        "cmpl %ebx, %eax\n" /* i */
        "jle .Lfa644_0000a692\n"
        /* { scope 2 */
        "addl $1, %ecx\n" /* line 173 */
        "cmpb $0xa, %dl\n" /* line 175 */
        "je .Lfa644_0000a662\n"
        "cmpb $0xd, %dl\n" /* line 181 */
        "je .Lfa644_0000a69e\n"
        "cmpb $0x20, %dl\n" /* line 203 */
        "je .Lfa644_0000a6ba\n"
        "movb $0, -0xd(%ebp)\n" /* hadSpace */
        "xorl %esi, %esi\n" /* hadReturn */
        ".Lfa644_0000a685:\n"
        "movb %dl, (%edi, %ebx)\n" /* line 217 | inDstString */
        "addl $1, %ebx\n" /* i */
        /* } scope */
        "movzbl (%ecx), %edx\n" /* line 171 */
        "testb %dl, %dl\n"
        "jne .Lfa644_0000a669\n"
        ".Lfa644_0000a692:\n"
        "movb $0, (%ebx, %edi)\n" /* line 220 | i */
        /* } scope */
        "addl $4, %esp\n" /* line 221 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa644_0000a69e:\n"
        "movl %esi, %edx\n" /* line 185 | hadReturn */
        "testb %dl, %dl\n"
        "jne .Lfa644_0000a6be\n"
        "movl $1, %esi\n" /* hadReturn */
        "movl $0x20, %edx\n"
        ".Lfa644_0000a6ae:\n"
        "cmpb $0, -0xd(%ebp)\n" /* line 206 | hadSpace */
        "jne .Lfa644_0000a662\n"
        "movb $1, -0xd(%ebp)\n" /* line 208 | hadSpace */
        "jmp .Lfa644_0000a685\n"
        ".Lfa644_0000a6ba:\n"
        "xorl %esi, %esi\n" /* line 203 | hadReturn */
        "jmp .Lfa644_0000a6ae\n"
        ".Lfa644_0000a6be:\n"
        "movb $0xd, (%edi, %ebx)\n" /* line 188 | inDstString */
        "movb $0xd, 1(%ebx, %edi)\n" /* line 189 | i */
        "addl $2, %ebx\n" /* i */
        "xorl %esi, %esi\n" /* hadReturn */
        "jmp .Lfa644_0000a662\n"
    );
}

