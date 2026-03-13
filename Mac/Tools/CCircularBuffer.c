/* ASM dump from: CCircularBuffer.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/CCircularBuffer.cp */

#include "common_types.h"
#include "imports.h"

void CCircularBuffer_CCircularBuffer(CCircularBuffer *_this);
void CCircularBuffer_Reset(CCircularBuffer *_this);
UInt32 CCircularBuffer_ReadPtrSize(const CCircularBuffer *_this);
void *CCircularBuffer_ReadPtr(CCircularBuffer *_this, UInt32 *ioSize);
void ZN15CCircularBufferD1Ev(CCircularBuffer *_this); /* CCircularBuffer_~CCircularBuffer */
void CCircularBuffer_Alloc(CCircularBuffer *_this, UInt32 inBufferSize);
void CCircularBuffer_Write(const CCircularBuffer *_this, const void *inBuffer, UInt32 *ioSize);

/*
 * CCircularBuffer layout:
 *   offset 0x00: void *buffer       - allocated buffer pointer
 *   offset 0x04: UInt32 bufferSize  - total buffer size
 *   offset 0x08: UInt32 readOffset  - current read position
 *   offset 0x0c: UInt32 lastReadSize - bytes consumed in last read
 *   offset 0x10: UInt32 writeOffset - current write/end position
 */

/* line 14 */
void CCircularBuffer_CCircularBuffer(CCircularBuffer *_this)
{
    char *p = (char *)_this;
    ((int *)p)[0] = 0; /* buffer */
    ((int *)p)[1] = 0; /* bufferSize */
    ((int *)p)[2] = 0; /* readOffset */
    ((int *)p)[3] = 0; /* lastReadSize */
    ((int *)p)[4] = 0; /* writeOffset */
}

/* line 75 */
void CCircularBuffer_Reset(CCircularBuffer *_this)
{
    char *p = (char *)_this;
    ((int *)p)[2] = 0; /* readOffset */
    ((int *)p)[3] = 0; /* lastReadSize */
    ((int *)p)[4] = 0; /* writeOffset */
}

/* line 152 */
UInt32 CCircularBuffer_ReadPtrSize(const CCircularBuffer *_this)
{
    const char *p = (const char *)_this;
    UInt32 bufferSize = ((const int *)p)[1];
    UInt32 readOffset = ((const int *)p)[2];
    UInt32 lastReadSize = ((const int *)p)[3];
    UInt32 writeOffset = ((const int *)p)[4];

    UInt32 readPosition = readOffset + lastReadSize;
    if (readPosition >= bufferSize)
        readPosition = 0;

    UInt32 endPosition;
    if (readPosition <= writeOffset)
        endPosition = writeOffset;
    else
        endPosition = bufferSize;

    return endPosition - readPosition;
}

/* line 120 */
void *CCircularBuffer_ReadPtr(CCircularBuffer *_this, UInt32 *ioSize)
{
    char *p = (char *)_this;
    void *buffer = *(void **)p;
    UInt32 bufferSize = ((int *)p)[1];
    UInt32 readOffset = ((int *)p)[2];
    UInt32 lastReadSize = ((int *)p)[3];
    UInt32 writeOffset = ((int *)p)[4];

    /* Advance read position by last read size */
    readOffset = readOffset + lastReadSize;
    ((int *)p)[2] = readOffset;
    if (readOffset >= bufferSize)
    {
        readOffset = 0;
        ((int *)p)[2] = 0;
    }
    ((int *)p)[3] = 0; /* lastReadSize = 0 */

    /* Determine end position */
    UInt32 endPosition;
    if (readOffset <= writeOffset)
        endPosition = writeOffset;
    else
        endPosition = bufferSize;

    UInt32 size = endPosition - readOffset;
    UInt32 requested = *ioSize;
    if (size < requested)
    {
        *ioSize = size;
    }
    else
    {
        size = requested;
    }

    if (size == 0)
        return NULL;

    ((int *)p)[3] = size; /* lastReadSize = size */
    return (char *)buffer + readOffset;
}

/* line 38 - ~CCircularBuffer */
void ZN15CCircularBufferD1Ev(CCircularBuffer *_this)
{
    char *p = (char *)_this;
    void *buffer = *(void **)p;

    if (buffer)
    {
        free(buffer);
        ((int *)p)[0] = 0; /* buffer */
        ((int *)p)[1] = 0; /* bufferSize */
        ((int *)p)[2] = 0; /* readOffset */
        ((int *)p)[3] = 0; /* lastReadSize */
        ((int *)p)[4] = 0; /* writeOffset */
    }
}

/* line 47 */
void CCircularBuffer_Alloc(CCircularBuffer *_this, UInt32 inBufferSize)
{
    char *p = (char *)_this;
    void *buffer = *(void **)p;

    if (buffer)
    {
        free(buffer);
        ((int *)p)[0] = 0;
        ((int *)p)[1] = 0;
        ((int *)p)[2] = 0;
        ((int *)p)[3] = 0;
        ((int *)p)[4] = 0;
    }

    ((int *)p)[0] = (int)malloc(inBufferSize);
    ((int *)p)[1] = inBufferSize;
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
