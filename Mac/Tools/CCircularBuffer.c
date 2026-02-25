/* ASM dump from: CCircularBuffer.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/CCircularBuffer.cp */

#include "common_types.h"
#include "imports.h"

void CCircularBuffer_CCircularBuffer(const CCircularBuffer * _this);
void CCircularBuffer_Reset(const CCircularBuffer * _this);
UInt32 CCircularBuffer_ReadPtrSize(const CCircularBuffer * _this);
void * CCircularBuffer_ReadPtr(const CCircularBuffer * _this, UInt32 *ioSize);
void ZN15CCircularBufferD1Ev(void); /* CCircularBuffer_~CCircularBuffer */
void CCircularBuffer_Alloc(const CCircularBuffer * _this, UInt32 inBufferSize);
void CCircularBuffer_Write(const CCircularBuffer * _this, const void *inBuffer, UInt32 *ioSize);

/* line 14 */
__attribute__((naked))
void CCircularBuffer_CCircularBuffer(const CCircularBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 14 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0, (%eax)\n" /* line 19 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "popl %ebp\n" /* line 21 */
        "retl\n"
    );
}

/* line 75 */
__attribute__((naked))
void CCircularBuffer_Reset(const CCircularBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0, 8(%eax)\n" /* line 77 */
        "movl $0, 0xc(%eax)\n" /* line 78 */
        "movl $0, 0x10(%eax)\n" /* line 79 */
        "popl %ebp\n" /* line 80 */
        "retl\n"
    );
}

/* line 152 */
__attribute__((naked))
UInt32 CCircularBuffer_ReadPtrSize(const CCircularBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 152 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movl 8(%ebx), %edx\n" /* line 154 | this, readPosition */
        "addl 0xc(%ebx), %edx\n" /* this, readPosition */
        "movl 4(%ebx), %eax\n" /* line 155 | this */
        "cmpl %eax, %edx\n"
        "movl $0, %ecx\n"
        "cmovael %ecx, %edx\n"
        "movl 0x10(%ebx), %ecx\n" /* line 160 | this */
        "cmpl %ecx, %edx\n"
        "cmovbel %ecx, %eax\n" /* endPosition */
        "subl %edx, %eax\n" /* endPosition */
        /* } scope */
        "popl %ebx\n" /* line 162 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 120 */
__attribute__((naked))
void * CCircularBuffer_ReadPtr(const CCircularBuffer * _this, UInt32 *ioSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 120 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* ioSize */
        /* { scope 1 */
        "movl 8(%ecx), %eax\n" /* line 204 */
        "addl 0xc(%ecx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "cmpl 4(%ecx), %eax\n" /* line 205 */
        "jb .Lf1f6e76_001f6e97\n"
        "xorl %eax, %eax\n" /* line 207 */
        "movl $0, 8(%ecx)\n"
        ".Lf1f6e76_001f6e97:\n"
        "movl $0, 0xc(%ecx)\n" /* line 209 */
        "movl 0x10(%ecx), %edx\n" /* line 129 | endPosition */
        "cmpl %edx, %eax\n" /* endPosition */
        "jbe .Lf1f6e76_001f6ea8\n"
        "movl 4(%ecx), %edx\n" /* endPosition */
        ".Lf1f6e76_001f6ea8:\n"
        "subl %eax, %edx\n" /* line 130 | size */
        "movl %edx, %eax\n" /* size */
        "cmpl (%ebx), %edx\n" /* line 131 | ioSize */
        "jae .Lf1f6e76_001f6ec1\n"
        "movl %edx, (%ebx)\n" /* line 133 | ioSize */
        ".Lf1f6e76_001f6eb2:\n"
        "testl %eax, %eax\n" /* line 136 */
        "je .Lf1f6e76_001f6ebe\n"
        "movl %eax, 0xc(%ecx)\n" /* line 140 */
        "movl (%ecx), %eax\n" /* line 141 */
        "addl 8(%ecx), %eax\n"
        /* } scope */
        ".Lf1f6e76_001f6ebe:\n"
        "popl %ebx\n" /* line 147 */
        "popl %ebp\n"
        "retl\n"
        ".Lf1f6e76_001f6ec1:\n"
        "movl (%ebx), %eax\n" /* ioSize */
        "jmp .Lf1f6e76_001f6eb2\n"
    );
}

/* line 38 */
__attribute__((naked))
void ZN15CCircularBufferD1Ev(void) /* CCircularBuffer_~CCircularBuffer */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl (%ebx), %eax\n" /* line 60 | this */
        "testl %eax, %eax\n"
        "je .Lf1f6ec6_001f6f00\n"
        "movl %eax, (%esp)\n" /* line 62 */
        "calll free\n"
        "movl $0, (%ebx)\n" /* line 64 | this */
        "movl $0, 4(%ebx)\n" /* line 65 | this */
        "movl $0, 8(%ebx)\n" /* line 66 | this */
        "movl $0, 0xc(%ebx)\n" /* line 67 | this */
        "movl $0, 0x10(%ebx)\n" /* line 68 | this */
        ".Lf1f6ec6_001f6f00:\n"
        "addl $0x14, %esp\n" /* line 41 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 47 */
__attribute__((naked))
void CCircularBuffer_Alloc(const CCircularBuffer * _this, UInt32 inBufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 47 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* inBufferSize */
        "movl (%ebx), %eax\n" /* line 60 | this */
        "testl %eax, %eax\n"
        "je .Lf1f6f06_001f6f44\n"
        "movl %eax, (%esp)\n" /* line 62 */
        "calll free\n"
        "movl $0, (%ebx)\n" /* line 64 | this */
        "movl $0, 4(%ebx)\n" /* line 65 | this */
        "movl $0, 8(%ebx)\n" /* line 66 | this */
        "movl $0, 0xc(%ebx)\n" /* line 67 | this */
        "movl $0, 0x10(%ebx)\n" /* line 68 | this */
        ".Lf1f6f06_001f6f44:\n"
        "movl %esi, (%esp)\n" /* line 51 | inBufferSize */
        "calll malloc\n"
        "movl %eax, (%ebx)\n" /* this */
        "movl %esi, 4(%ebx)\n" /* line 52 | inBufferSize, this */
        "addl $0x10, %esp\n" /* line 53 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* overload skip: CCircularBuffer_CCircularBuffer (0x1f6f58) */

/* line 169 */
__attribute__((naked))
void CCircularBuffer_Write(const CCircularBuffer * _this, const void *inBuffer, UInt32 *ioSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 169 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0x10(%edi), %edx\n" /* line 174 | this */
        "movl 8(%edi), %eax\n" /* this */
        "cmpl %eax, %edx\n"
        "jae .Lf1f6f9c_001f7001\n"
        /* { scope 1 */
        "subl %edx, %eax\n" /* line 246 | size */
        "movl 0x10(%ebp), %edx\n" /* line 247 | ioSize */
        "cmpl (%edx), %eax\n"
        "jae .Lf1f6f9c_001f7044\n"
        "movl %eax, (%edx)\n" /* line 249 */
        "movl 0x10(%ebp), %eax\n" /* ioSize */
        ".Lf1f6f9c_001f6fc4:\n"
        "movl (%eax), %edx\n" /* line 252 */
        "testl %edx, %edx\n"
        "je .Lf1f6f9c_001f6ff9\n"
        "movl (%edi), %eax\n" /* line 254 | this */
        "addl 0x10(%edi), %eax\n" /* this */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* inBuffer */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x10(%edi), %eax\n" /* line 255 | this */
        "movl 0x10(%ebp), %edx\n" /* ioSize */
        "addl (%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* this */
        "cmpl 4(%edi), %eax\n" /* line 257 | this */
        "jb .Lf1f6f9c_001f6ff9\n"
        "movl $0, 0x10(%edi)\n" /* line 259 | this */
        /* } scope */
        ".Lf1f6f9c_001f6ff9:\n"
        "addl $0x1c, %esp\n" /* line 194 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f6f9c_001f7001:\n"
        "movl 0x10(%ebp), %eax\n" /* line 182 | ioSize */
        "movl (%eax), %ebx\n" /* size */
        "movl %ebx, %ecx\n" /* size */
        "movl 4(%edi), %eax\n" /* line 246 | this, size */
        "subl %edx, %eax\n" /* size */
        "cmpl %eax, %ebx\n" /* line 247 | size */
        "cmoval %eax, %ebx\n" /* size */
        "testl %ebx, %ebx\n" /* line 252 | size */
        "jne .Lf1f6f9c_001f704b\n"
        ".Lf1f6f9c_001f7016:\n"
        "cmpl %ecx, %ebx\n" /* line 184 | size */
        "jae .Lf1f6f9c_001f6ff9\n"
        /* { scope 2 */
        "movl %ecx, %esi\n" /* line 189 | size2 */
        "subl %ebx, %esi\n" /* size, size2 */
        "movl 0xc(%ebp), %ecx\n" /* inBuffer */
        "addl %ebx, %ecx\n" /* size */
        /* { scope 3 */
        "movl 0x10(%edi), %edx\n" /* line 246 | this */
        "movl 8(%edi), %eax\n" /* this, size */
        "subl %edx, %eax\n" /* size */
        "cmpl %eax, %esi\n" /* line 247 | size2 */
        "cmoval %eax, %esi\n" /* size2 */
        "testl %esi, %esi\n" /* line 252 | size2 */
        "jne .Lf1f6f9c_001f707b\n"
        /* } scope */
        ".Lf1f6f9c_001f7034:\n"
        "leal (%esi, %ebx), %eax\n" /* line 191 | size2 */
        "movl 0x10(%ebp), %edx\n" /* ioSize */
        "movl %eax, (%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 194 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f6f9c_001f7044:\n"
        "movl %edx, %eax\n"
        "jmp .Lf1f6f9c_001f6fc4\n"
        /* { scope 1 */
        ".Lf1f6f9c_001f704b:\n"
        "addl (%edi), %edx\n" /* line 254 | this */
        "movl %ebx, 8(%esp)\n" /* size */
        "movl 0xc(%ebp), %eax\n" /* inBuffer */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl %ebx, %eax\n" /* line 255 | size */
        "addl 0x10(%edi), %eax\n" /* this */
        "movl %eax, 0x10(%edi)\n" /* this */
        "cmpl 4(%edi), %eax\n" /* line 257 | this */
        "jb .Lf1f6f9c_001f70a3\n"
        "movl $0, 0x10(%edi)\n" /* line 259 | this */
        "movl 0x10(%ebp), %edx\n" /* ioSize */
        "movl (%edx), %ecx\n"
        "jmp .Lf1f6f9c_001f7016\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1f6f9c_001f707b:\n"
        "addl (%edi), %edx\n" /* line 254 | this */
        "movl %esi, 8(%esp)\n" /* size2 */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl %esi, %eax\n" /* line 255 | size2 */
        "addl 0x10(%edi), %eax\n" /* this */
        "movl %eax, 0x10(%edi)\n" /* this */
        "cmpl 4(%edi), %eax\n" /* line 257 | this */
        "jb .Lf1f6f9c_001f7034\n"
        "movl $0, 0x10(%edi)\n" /* line 259 | this */
        "jmp .Lf1f6f9c_001f7034\n"
        ".Lf1f6f9c_001f70a3:\n"
        "movl 0x10(%ebp), %eax\n" /* ioSize */
        "movl (%eax), %ecx\n"
        "jmp .Lf1f6f9c_001f7016\n"
    );
}

