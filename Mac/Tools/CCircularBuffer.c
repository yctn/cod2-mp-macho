/* ASM dump from: CCircularBuffer.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/CCircularBuffer.cp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

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

void CCircularBuffer_Write(const CCircularBuffer * _this, const void *inBuffer, UInt32 *ioSize)
{
}
