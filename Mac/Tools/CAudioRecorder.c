/* ASM dump from: CAudioRecorder.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/CAudioRecorder.cp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacExceptions.h"
 */

/* Forward declarations for CCircularBuffer/CMutex/StMutexLock */
void CMutex_CMutex(void *mutex);
void ZN6CMutexD1Ev(void *mutex);
void StMutexLock_StMutexLock(StMutexLock *lock, void *mutex);
void ZN11StMutexLockD1Ev(StMutexLock *lock);
void CCircularBuffer_CCircularBuffer(CCircularBuffer *_this);
void CCircularBuffer_Alloc(CCircularBuffer *_this, UInt32 inBufferSize);
void ZN15CCircularBufferD1Ev(CCircularBuffer *_this);
void *CCircularBuffer_ReadPtr(CCircularBuffer *_this, UInt32 *ioSize);

void CAudioRecorder_CAudioRecorder(CAudioRecorder * _this, Float64 inSampleRate, UInt32 inNumChannels, UInt32 inBitsPerChannel);
Boolean CAudioRecorder_Start(CAudioRecorder * _this);
void CAudioRecorder_Stop(CAudioRecorder * _this);
void CAudioRecorder_Mute(CAudioRecorder * _this, int inMute);
Float32 CAudioRecorder_GetRecordLevel(const CAudioRecorder * _this);
void CAudioRecorder_SetRecordLevel(const CAudioRecorder * _this, Float32 inLevel);
void * CAudioRecorder_GetBuffer(const CAudioRecorder * _this, UInt32 *outSize);
OSStatus CAudioRecorder_DoRender(const CAudioRecorder * _this, const AudioTimeStamp *inTimeStamp, UInt32 inNumberFrames);
OSStatus CAudioRecorder_DoConvert(const CAudioRecorder * _this, UInt32 *ioDataSize, void * *outData);
OSStatus CAudioRecorder_RenderCallbackProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData);
void CAudioRecorder_Shutdown(const CAudioRecorder * _this);
Boolean CAudioRecorder_Initialize(CAudioRecorder * _this);
void ZN14CAudioRecorderD1Ev(CAudioRecorder *_this); /* CAudioRecorder_~CAudioRecorder */
void ZN14CAudioRecorderD2Ev(void); /* CAudioRecorder_~CAudioRecorder */
OSStatus CAudioRecorder_AudioConverterProc(AudioConverterRef inAudioConverter, UInt32 *ioDataSize, void * *outData, void *inUserData);

/* line 29 */
void CAudioRecorder_CAudioRecorder(CAudioRecorder *_this, Float64 inSampleRate, UInt32 inNumChannels, UInt32 inBitsPerChannel)
{
    char *p = (char *)_this;

    *(Float64 *)(p + 0x00) = inSampleRate;
    *(UInt32 *)(p + 0x08) = inNumChannels;
    *(UInt32 *)(p + 0x0c) = inBitsPerChannel;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    *(char *)(p + 0x18) = 0;
    *(char *)(p + 0x19) = 0;
    *(int *)(p + 0x1c) = 0;

    CMutex_CMutex((void *)(p + 0x20));

    *(int *)(p + 0x4c) = 0;
    *(int *)(p + 0x50) = 0;
    *(int *)(p + 0x54) = 0;
    *(int *)(p + 0x58) = 0;
    *(int *)(p + 0x5c) = 0;

    CCircularBuffer_CCircularBuffer((CCircularBuffer *)(p + 0x60));

    *(char *)(p + 0x74) = 0;
}

/* line 279 */
Boolean CAudioRecorder_Start(CAudioRecorder *_this)
{
    char *p = (char *)_this;

    if (*(char *)(p + 0x18)) /* already running */
        return *(unsigned char *)(p + 0x18);

    OSStatus error = AudioOutputUnitStart(*(AudioUnit *)(p + 0x14));
    if (error == 0)
        *(char *)(p + 0x18) = 1;

    return *(unsigned char *)(p + 0x18);
}

/* line 299 */
void CAudioRecorder_Stop(CAudioRecorder *_this)
{
    char *p = (char *)_this;

    if (!*(char *)(p + 0x18))
        return;

    AudioOutputUnitStop(*(AudioUnit *)(p + 0x14));
    *(char *)(p + 0x18) = 0;
}

/* line 314 */
void CAudioRecorder_Mute(CAudioRecorder *_this, int inMute)
{
    char *p = (char *)_this;
    StMutexLock lock;

    StMutexLock_StMutexLock(&lock, (CMutex *)(p + 0x20));
    *(char *)(p + 0x19) = (char)inMute;
    ZN11StMutexLockD1Ev(&lock);
}

/* line 333 */
__attribute__((naked))
Float32 CAudioRecorder_GetRecordLevel(const CAudioRecorder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 333 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: volume, size */
        "leal 0x20(%esi), %eax\n" /* line 335 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x10(%esi), %eax\n" /* line 339 | this */
        "testl %eax, %eax\n"
        "je .Lf1f6320_001f63af\n"
        /* { scope 2 */
        "movl $4, -0x20(%ebp)\n" /* line 342 | size */
        "leal -0x1c(%ebp), %eax\n" /* line 344 | volume, error */
        "movl %eax, 0x14(%esp)\n" /* error */
        "leal -0x20(%ebp), %eax\n" /* size, error */
        "movl %eax, 0x10(%esp)\n" /* error */
        "movl $0x766f6c6d, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* this, error */
        "movl %eax, (%esp)\n" /* error */
        "calll AudioDeviceGetProperty\n"
        "testl %eax, %eax\n" /* line 345 */
        "jne .Lf1f6320_001f63af\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 348 | volume, level */
        "movl %ebx, -0x2c(%ebp)\n" /* level */
        "movss -0x2c(%ebp), %xmm0\n"
        "divss 0x1c(%esi), %xmm0\n" /* this */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl -0x2c(%ebp), %ebx\n" /* level */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 352 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, -0x2c(%ebp)\n" /* line 353 | level */
        "flds -0x2c(%ebp)\n"
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: volume, size */
        /* { scope 2 */
        ".Lf1f6320_001f63af:\n"
        "movl $0x3f800000, %ebx\n" /* line 348 | level */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 352 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, -0x2c(%ebp)\n" /* line 353 | level */
        "flds -0x2c(%ebp)\n"
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* level */
        /* { scope 1: volume, size */
        "movl %edi, (%esp)\n" /* line 352 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* level */
        "calll __Unwind_Resume\n"
    );
}

/* line 359 */
__attribute__((naked))
void CAudioRecorder_SetRecordLevel(const CAudioRecorder * _this, Float32 inLevel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 359 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: volume */
        "leal 0x20(%ebx), %eax\n" /* line 361 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x14(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x10(%ebx), %edx\n" /* line 363 | this */
        "testl %edx, %edx\n"
        "je .Lf1f63dc_001f6449\n"
        /* { scope 2 */
        "movss 0xc(%ebp), %xmm0\n" /* line 366 | inLevel */
        "mulss 0x1c(%ebx), %xmm0\n" /* this */
        "movss %xmm0, -0xc(%ebp)\n" /* volume */
        "leal -0xc(%ebp), %eax\n" /* line 368 | volume */
        "movl %eax, 0x18(%esp)\n"
        "movl $4, 0x14(%esp)\n"
        "movl $0x766f6c6d, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioDeviceSetProperty\n"
        /* } scope */
        ".Lf1f63dc_001f6449:\n"
        "movl %esi, (%esp)\n" /* line 370 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 371 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1: volume */
        "movl %esi, (%esp)\n" /* line 370 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 377 */
__attribute__((naked))
void * CAudioRecorder_GetBuffer(const CAudioRecorder * _this, UInt32 *outSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 377 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 379 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x54(%ebx), %eax\n" /* line 383 | this */
        "movl %eax, -0x1c(%ebp)\n" /* ioOutputDataSize */
        "movl 0x50(%ebx), %eax\n" /* line 384 | this */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* ioOutputDataSize */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* this */
        "movl $CAudioRecorder_AudioConverterProc, 4(%esp)\n"
        "movl 0x4c(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioConverterFillBuffer\n"
        "movl %eax, %esi\n" /* error */
        "cmpb $0, 0x74(%ebx)\n" /* line 390 | this */
        "jne .Lf1f646a_001f650e\n"
        "xorl %edx, %edx\n"
        ".Lf1f646a_001f64bd:\n"
        "testl %esi, %esi\n" /* line 401 | error */
        "jne .Lf1f646a_001f64c8\n"
        "movl -0x1c(%ebp), %eax\n" /* ioOutputDataSize */
        "testl %eax, %eax\n"
        "jne .Lf1f646a_001f64f4\n"
        ".Lf1f646a_001f64c8:\n"
        "testb %dl, %dl\n" /* line 403 */
        "jne .Lf1f646a_001f64d7\n"
        "movl 0x4c(%ebx), %eax\n" /* line 405 | this */
        "movl %eax, (%esp)\n"
        "calll AudioConverterReset\n"
        ".Lf1f646a_001f64d7:\n"
        "movl 0xc(%ebp), %eax\n" /* line 407 | outSize */
        "movl $0, (%eax)\n"
        "xorl %ebx, %ebx\n" /* this */
        "movl %edi, (%esp)\n" /* line 478 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 479 | this */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f646a_001f64f4:\n"
        "movl 0xc(%ebp), %edx\n" /* line 477 | outSize */
        "movl %eax, (%edx)\n"
        "movl 0x50(%ebx), %ebx\n" /* line 478 | this */
        "movl %edi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 479 | this */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f646a_001f650e:\n"
        "movl 0x4c(%ebx), %eax\n" /* line 393 | this */
        "movl %eax, (%esp)\n"
        "calll AudioConverterReset\n"
        "leal 0x60(%ebx), %eax\n" /* line 394 | this */
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_Reset\n"
        "movb $0, 0x74(%ebx)\n" /* line 395 | this */
        "movl $1, %edx\n"
        "jmp .Lf1f646a_001f64bd\n"
        "movl %eax, %ebx\n" /* this */
        "movl %edi, (%esp)\n" /* line 478 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 488 */
__attribute__((naked))
OSStatus CAudioRecorder_DoRender(const CAudioRecorder * _this, const AudioTimeStamp *inTimeStamp, UInt32 inNumberFrames)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 488 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: flags, bufferList */
        "leal 0x20(%esi), %eax\n" /* line 490 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpb $0, 0x18(%esi)\n" /* line 494 | this */
        "je .Lf1f6542_001f656c\n"
        "cmpb $0, 0x74(%esi)\n" /* this */
        "je .Lf1f6542_001f6580\n"
        /* { scope 2: size */
        /* { scope 3 */
        ".Lf1f6542_001f656c:\n"
        "xorl %ebx, %ebx\n" /* line 513 | error */
        /* } scope */
        /* } scope */
        ".Lf1f6542_001f656e:\n"
        "movl %edi, (%esp)\n" /* line 519 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 520 | error */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: flags, bufferList */
        /* { scope 2: size */
        ".Lf1f6542_001f6580:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 496 | flags */
        "movl $1, -0x38(%ebp)\n" /* line 499 | bufferList */
        "movl 8(%esi), %eax\n" /* line 500 | this */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x5c(%esi), %eax\n" /* line 501 | this */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x58(%esi), %eax\n" /* line 502 | this */
        "movl %eax, -0x2c(%ebp)\n"
        "leal -0x38(%ebp), %eax\n" /* line 504 | bufferList */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* inNumberFrames */
        "movl %eax, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inTimeStamp */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* flags */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitRender\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 505 */
        "jne .Lf1f6542_001f656e\n"
        /* { scope 3 */
        "movl -0x30(%ebp), %eax\n" /* line 507 */
        "movl %eax, -0x20(%ebp)\n" /* size */
        "testl %eax, %eax\n" /* line 508 */
        "je .Lf1f6542_001f656c\n"
        "leal -0x20(%ebp), %eax\n" /* line 510 | size */
        "movl %eax, 8(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x60(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_Write\n"
        "movl -0x30(%ebp), %eax\n" /* line 511 */
        "cmpl -0x20(%ebp), %eax\n" /* size */
        "je .Lf1f6542_001f656c\n"
        "movb $1, 0x74(%esi)\n" /* line 513 | this */
        "jmp .Lf1f6542_001f656e\n"
        "movl %eax, %ebx\n" /* error */
        /* } scope */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 519 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* error */
        "calll __Unwind_Resume\n"
    );
}

/* line 527 */
__attribute__((naked))
OSStatus CAudioRecorder_DoConvert(const CAudioRecorder * _this, UInt32 *ioDataSize, void * *outData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 527 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* ioDataSize */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 529 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl %edi, 4(%esp)\n" /* line 531 | ioDataSize */
        "leal 0x60(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_ReadPtr\n"
        "movl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* outData */
        "movl %edx, (%eax)\n"
        "cmpb $0, 0x19(%ebx)\n" /* line 533 | this */
        "je .Lf1f6620_001f6677\n"
        "testl %edx, %edx\n"
        "je .Lf1f6620_001f6677\n"
        "movl (%edi), %eax\n" /* line 535 | ioDataSize */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        ".Lf1f6620_001f6677:\n"
        "movl %esi, (%esp)\n" /* line 538 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 539 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 538 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 550 */
OSStatus CAudioRecorder_RenderCallbackProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData)
{
    if (!inRefCon)
        return -50; /* paramErr */

    return CAudioRecorder_DoRender(inRefCon, inTimeStamp, inNumberFrames);
}

/* line 233 */
__attribute__((naked))
void CAudioRecorder_Shutdown(const CAudioRecorder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 233 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0x14(%esi), %eax\n" /* line 235 | this */
        "testl %eax, %eax\n"
        "je .Lf1f66d6_001f67b6\n"
        /* { scope 1: lock */
        "cmpb $0, 0x18(%esi)\n" /* line 303 | this */
        "jne .Lf1f66d6_001f6803\n"
        ".Lf1f66d6_001f66f7:\n"
        "movl $0x2710, (%esp)\n" /* line 239 */
        "calll usleep\n"
        "movl 0x14(%esi), %eax\n" /* line 241 | this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitUninitialize\n"
        "movl $0x2710, (%esp)\n" /* line 243 */
        "calll usleep\n"
        "movl 0x4c(%esi), %eax\n" /* line 245 | this */
        "testl %eax, %eax\n"
        "je .Lf1f66d6_001f6730\n"
        "movl %eax, (%esp)\n" /* line 247 */
        "calll AudioConverterDispose\n"
        "movl $0, 0x4c(%esi)\n" /* line 248 | this */
        ".Lf1f66d6_001f6730:\n"
        "movl $0x2710, (%esp)\n" /* line 251 */
        "calll usleep\n"
        "leal 0x20(%esi), %ebx\n" /* line 253 | this */
        "movl %ebx, 4(%esp)\n"
        "leal -0x24(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        /* { scope 2: volume */
        "movl %ebx, 4(%esp)\n" /* line 361 */
        "leal -0x2c(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x10(%esi), %ecx\n" /* line 363 | this */
        "testl %ecx, %ecx\n"
        "jne .Lf1f66d6_001f67be\n"
        ".Lf1f66d6_001f6764:\n"
        "movl %ebx, (%esp)\n" /* line 370 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl 0x14(%esi), %eax\n" /* line 257 | this */
        "movl %eax, (%esp)\n"
        "calll CloseComponent\n"
        "movl $0, 0x14(%esi)\n" /* line 258 | this */
        "movl 0x50(%esi), %eax\n" /* line 260 | this */
        "testl %eax, %eax\n"
        "je .Lf1f66d6_001f6794\n"
        "movl %eax, (%esp)\n" /* line 262 */
        "calll free\n"
        "movl $0, 0x50(%esi)\n" /* line 263 | this */
        ".Lf1f66d6_001f6794:\n"
        "movl 0x58(%esi), %eax\n" /* line 266 | this */
        "testl %eax, %eax\n"
        "je .Lf1f66d6_001f67aa\n"
        "movl %eax, (%esp)\n" /* line 268 */
        "calll free\n"
        "movl $0, 0x58(%esi)\n" /* line 269 | this */
        ".Lf1f66d6_001f67aa:\n"
        "movb $0, 0x74(%esi)\n" /* line 272 | this */
        "movl %edi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        ".Lf1f66d6_001f67b6:\n"
        "addl $0x4c, %esp\n" /* line 274 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lock */
        /* { scope 2: volume */
        /* { scope 3 */
        ".Lf1f66d6_001f67be:\n"
        "movl 0x1c(%esi), %eax\n" /* line 366 | this */
        "movl %eax, -0x1c(%ebp)\n" /* volume */
        "leal -0x1c(%ebp), %eax\n" /* line 368 | volume */
        "movl %eax, 0x18(%esp)\n"
        "movl $4, 0x14(%esp)\n"
        "movl $0x766f6c6d, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioDeviceSetProperty\n"
        "jmp .Lf1f66d6_001f6764\n"
        /* } scope */
        /* } scope */
        ".Lf1f66d6_001f6803:\n"
        "movl %eax, (%esp)\n" /* line 305 */
        "calll AudioOutputUnitStop\n"
        "movb $0, 0x18(%esi)\n" /* line 306 | this */
        "jmp .Lf1f66d6_001f66f7\n"
        "movl %eax, %esi\n" /* this */
        /* { scope 2: volume */
        "movl %ebx, (%esp)\n" /* line 370 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        ".Lf1f66d6_001f681e:\n"
        "movl %edi, (%esp)\n" /* line 272 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %esi, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n" /* this */
        "jmp .Lf1f66d6_001f681e\n"
    );
}

/* line 70 */
Boolean CAudioRecorder_Initialize(CAudioRecorder *_this)
{
    char *p = (char *)_this;
    ComponentDescription desc;
    Component theComponent;
    OSStatus error;
    UInt32 enableIO;
    UInt32 size;
    AudioStreamBasicDescription sourceFormat, destFormat;
    AURenderCallbackStruct callbackInfo;
    UInt32 framesPerSlice;

    /* Find audio output unit component */
    desc.componentType = 'auou';
    desc.componentSubType = 'ahal';
    desc.componentManufacturer = 'appl';
    desc.componentFlags = 0;
    desc.componentFlagsMask = 0;

    theComponent = (Component)FindNextComponent(NULL, &desc);
    if (!theComponent)
        return 0; /* throws paramErr in original, caught and returns false */

    error = OpenAComponent(theComponent, (AudioUnit *)(p + 0x14));
    if (error != 0) return 0;

    /* Enable IO on input scope (element 1) */
    enableIO = 1;
    error = AudioUnitSetProperty(*(AudioUnit *)(p + 0x14), 0x7d3 /* kAudioOutputUnitProperty_EnableIO */,
        1 /* kAudioUnitScope_Input */, 1, &enableIO, 4);
    if (error != 0) return 0;

    /* Disable IO on output scope (element 0) */
    enableIO = 0;
    error = AudioUnitSetProperty(*(AudioUnit *)(p + 0x14), 0x7d3,
        2 /* kAudioUnitScope_Output */, 0, &enableIO, 4);
    if (error != 0) return 0;

    /* Get default input device */
    size = 4;
    error = AudioHardwareGetProperty(0x64496e20 /* kAudioHardwarePropertyDefaultInputDevice */,
        &size, (int *)(p + 0x10));
    if (error != 0) return 0;

    /* Set current device */
    error = AudioUnitSetProperty(*(AudioUnit *)(p + 0x14), 0x7d0 /* kAudioOutputUnitProperty_CurrentDevice */,
        0, 0, (int *)(p + 0x10), 4);
    if (error != 0) return 0;

    /* Get device input volume */
    size = 4;
    error = AudioDeviceGetProperty(*(int *)(p + 0x10), 0, 1, 0x766f6c6d /* 'volm' */,
        &size, (float *)(p + 0x1c));
    if (error != 0)
        *(float *)(p + 0x1c) = 1.0f;

    /* Set render callback */
    callbackInfo.inputProc = CAudioRecorder_RenderCallbackProc;
    callbackInfo.inputProcRefCon = _this;
    error = AudioUnitSetProperty(*(AudioUnit *)(p + 0x14), 0x7d5 /* kAudioOutputUnitProperty_SetInputCallback */,
        0, 0, &callbackInfo, 8);
    if (error != 0) return 0;

    /* Initialize the audio unit */
    error = AudioUnitInitialize(*(AudioUnit *)(p + 0x14));
    if (error != 0) return 0;

    /* Get source format from input scope */
    size = sizeof(AudioStreamBasicDescription);
    error = AudioUnitGetProperty(*(AudioUnit *)(p + 0x14), 8 /* kAudioUnitProperty_StreamFormat */,
        1, 1, &sourceFormat, &size);
    if (error != 0) return 0;

    /* Build destination format (linear PCM) */
    UInt32 bitsPerChannel = *(UInt32 *)(p + 0x0c);
    UInt32 numChannels = *(UInt32 *)(p + 0x08);
    UInt32 bytesPerPacket = (bitsPerChannel / 8) * numChannels;
    UInt32 formatFlags = (bitsPerChannel == 16) ? 12 : 8;

    memset(&destFormat, 0, sizeof(destFormat));
    destFormat.mFormatID = 'lpcm';
    destFormat.mFormatFlags = formatFlags;
    destFormat.mBytesPerPacket = bytesPerPacket;
    destFormat.mFramesPerPacket = 1;
    destFormat.mBytesPerFrame = bytesPerPacket;
    destFormat.mChannelsPerFrame = numChannels;
    destFormat.mBitsPerChannel = bitsPerChannel;
    destFormat.mSampleRate = sourceFormat.mSampleRate;

    /* Set output format */
    error = AudioUnitSetProperty(*(AudioUnit *)(p + 0x14), 8,
        2, 1, &destFormat, sizeof(destFormat));
    if (error != 0) return 0;

    /* Re-read actual output format */
    size = sizeof(AudioStreamBasicDescription);
    error = AudioUnitGetProperty(*(AudioUnit *)(p + 0x14), 8,
        2, 1, &sourceFormat, &size);
    if (error != 0) return 0;

    /* Create audio converter */
    destFormat.mSampleRate = *(Float64 *)(p + 0x00);
    error = AudioConverterNew(&sourceFormat, &destFormat, (AudioConverterRef *)(p + 0x4c));
    if (error != 0) return 0;

    /* Get frames per slice */
    size = 4;
    error = AudioUnitGetProperty(*(AudioUnit *)(p + 0x14), 0xe /* kAudioUnitProperty_MaximumFramesPerSlice */,
        0, 0, &framesPerSlice, &size);
    if (error != 0)
        framesPerSlice = 512;

    /* Allocate conversion buffer: sampleRate * bytesPerFrame * 3 */
    int bufSize = (int)destFormat.mSampleRate * destFormat.mBytesPerFrame * 3;
    *(int *)(p + 0x54) = bufSize;
    *(void **)(p + 0x50) = malloc(bufSize);

    /* Allocate render buffer */
    int renderBufSize = sourceFormat.mBytesPerFrame * framesPerSlice;
    *(int *)(p + 0x5c) = renderBufSize;
    *(void **)(p + 0x58) = malloc(renderBufSize);

    /* Allocate circular buffer: sourceSampleRate * sourceBytesPerFrame * 3 */
    int circBufSize = (int)sourceFormat.mSampleRate * sourceFormat.mBytesPerFrame * 3;
    CCircularBuffer_Alloc((CCircularBuffer *)(p + 0x60), circBufSize);

    return 1;
}

/* line 62 */
void ZN14CAudioRecorderD1Ev(CAudioRecorder *_this) /* CAudioRecorder_~CAudioRecorder */
{
    char *p = (char *)_this;

    CAudioRecorder_Shutdown(_this);
    ZN15CCircularBufferD1Ev((CCircularBuffer *)(p + 0x60));
    ZN6CMutexD1Ev((void *)(p + 0x20));
}

/* line 62 */
__attribute__((naked))
void ZN14CAudioRecorderD2Ev(void) /* CAudioRecorder_~CAudioRecorder */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 62 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* line 64 | this */
        "calll CAudioRecorder_Shutdown\n"
        "leal 0x60(%ebx), %eax\n" /* line 65 | this */
        "movl %eax, (%esp)\n"
        "calll ZN15CCircularBufferD1Ev\n"
        "leal 0x20(%ebx), %eax\n" /* this */
        "movl %eax, 8(%ebp)\n" /* this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp ZN6CMutexD1Ev\n"
        "movl %eax, %esi\n"
        "leal 0x60(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll ZN15CCircularBufferD1Ev\n"
        ".Lf1f6d1a_001f6d56:\n"
        "leal 0x20(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll ZN6CMutexD1Ev\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n"
        "jmp .Lf1f6d1a_001f6d56\n"
    );
}

/* line 575 */
OSStatus CAudioRecorder_AudioConverterProc(AudioConverterRef inAudioConverter, UInt32 *ioDataSize, void **outData, void *inUserData)
{
    if (!inUserData)
        return -50; /* paramErr */

    StMutexLock lock;
    char *p = (char *)inUserData;

    StMutexLock_StMutexLock(&lock, (CMutex *)(p + 0x20));

    void *readPtr = CCircularBuffer_ReadPtr((CCircularBuffer *)(p + 0x60), ioDataSize);
    *outData = readPtr;

    if (*(char *)(p + 0x19) && readPtr) /* isMuted */
    {
        memset(readPtr, 0, *ioDataSize);
    }

    ZN11StMutexLockD1Ev(&lock);
    return 0;
}

