/* ASM dump from: CAudioRecorder.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/CAudioRecorder.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacExceptions.h"
 */

void CAudioRecorder_CAudioRecorder(const CAudioRecorder * _this, Float64 inSampleRate, UInt32 inNumChannels, UInt32 inBitsPerChannel);
Boolean CAudioRecorder_Start(const CAudioRecorder * _this);
void CAudioRecorder_Stop(const CAudioRecorder * _this);
void CAudioRecorder_Mute(const CAudioRecorder * _this, int inMute);
Float32 CAudioRecorder_GetRecordLevel(const CAudioRecorder * _this);
void CAudioRecorder_SetRecordLevel(const CAudioRecorder * _this, Float32 inLevel);
void * CAudioRecorder_GetBuffer(const CAudioRecorder * _this, UInt32 *outSize);
OSStatus CAudioRecorder_DoRender(const CAudioRecorder * _this, const AudioTimeStamp *inTimeStamp, UInt32 inNumberFrames);
OSStatus CAudioRecorder_DoConvert(const CAudioRecorder * _this, UInt32 *ioDataSize, void * *outData);
OSStatus CAudioRecorder_RenderCallbackProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData);
void CAudioRecorder_Shutdown(const CAudioRecorder * _this);
Boolean CAudioRecorder_Initialize(const CAudioRecorder * _this);
void ZN14CAudioRecorderD1Ev(void); /* CAudioRecorder_~CAudioRecorder */
void ZN14CAudioRecorderD2Ev(void); /* CAudioRecorder_~CAudioRecorder */
OSStatus CAudioRecorder_AudioConverterProc(AudioConverterRef inAudioConverter, UInt32 *ioDataSize, void * *outData, void *inUserData);

/* line 29 */
__attribute__((naked))
void CAudioRecorder_CAudioRecorder(const CAudioRecorder * _this, Float64 inSampleRate, UInt32 inNumChannels, UInt32 inBitsPerChannel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movsd 0xc(%ebp), %xmm0\n" /* line 49 | inSampleRate */
        "movsd %xmm0, (%ebx)\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* inNumChannels */
        "movl %eax, 8(%ebx)\n" /* this */
        "movl 0x18(%ebp), %eax\n" /* inBitsPerChannel */
        "movl %eax, 0xc(%ebx)\n" /* this */
        "movl $0, 0x10(%ebx)\n" /* this */
        "movl $0, 0x14(%ebx)\n" /* this */
        "movb $0, 0x18(%ebx)\n" /* this */
        "movb $0, 0x19(%ebx)\n" /* this */
        "movl $0, 0x1c(%ebx)\n" /* this */
        "leal 0x20(%ebx), %esi\n" /* this */
        "movl %esi, (%esp)\n"
        "calll CMutex_CMutex\n"
        "movl $0, 0x4c(%ebx)\n" /* this */
        "movl $0, 0x50(%ebx)\n" /* this */
        "movl $0, 0x54(%ebx)\n" /* this */
        "movl $0, 0x58(%ebx)\n" /* this */
        "movl $0, 0x5c(%ebx)\n" /* this */
        "leal 0x60(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_CCircularBuffer\n"
        "movb $0, 0x74(%ebx)\n" /* this */
        "addl $0x10, %esp\n" /* line 58 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        "movl %esi, (%esp)\n"
        "calll ZN6CMutexD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 279 */
__attribute__((naked))
Boolean CAudioRecorder_Start(const CAudioRecorder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 279 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 0x18(%ebx)\n" /* line 283 | this */
        "je .Lf1f628c_001f62a6\n"
        /* { scope 1 */
        ".Lf1f628c_001f629c:\n"
        "movzbl 0x18(%ebx), %eax\n" /* line 289 | this */
        /* } scope */
        "addl $0x14, %esp\n" /* line 294 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f628c_001f62a6:\n"
        "movl 0x14(%ebx), %eax\n" /* line 285 | this, error */
        "movl %eax, (%esp)\n" /* error */
        "calll AudioOutputUnitStart\n"
        "testl %eax, %eax\n" /* line 287 */
        "jne .Lf1f628c_001f629c\n"
        "movb $1, 0x18(%ebx)\n" /* line 289 | this */
        "movzbl 0x18(%ebx), %eax\n" /* this */
        /* } scope */
        "addl $0x14, %esp\n" /* line 294 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 299 */
__attribute__((naked))
void CAudioRecorder_Stop(const CAudioRecorder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 299 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 0x18(%ebx)\n" /* line 303 | this */
        "je .Lf1f62c4_001f62e3\n"
        "movl 0x14(%ebx), %eax\n" /* line 305 | this */
        "movl %eax, (%esp)\n"
        "calll AudioOutputUnitStop\n"
        "movb $0, 0x18(%ebx)\n" /* line 306 | this */
        ".Lf1f62c4_001f62e3:\n"
        "addl $0x14, %esp\n" /* line 308 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 314 */
__attribute__((naked))
void CAudioRecorder_Mute(const CAudioRecorder * _this, int inMute)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 314 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* inMute */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 316 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl %edi, %eax\n" /* line 319 */
        "movb %al, 0x19(%esi)\n" /* this */
        "movl %ebx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 328 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
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
__attribute__((naked))
OSStatus CAudioRecorder_RenderCallbackProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 550 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* inRefCon */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 556 */
        "je .Lf1f669c_001f66ce\n"
        "movl 0x18(%ebp), %edx\n" /* line 558 | inNumberFrames */
        "movl %edx, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* inTimeStamp */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CAudioRecorder_DoRender\n"
        /* } scope */
        "leave\n" /* line 566 */
        "retl\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 561 */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        ".Lf1f669c_001f66ce:\n"
        "movl $0xffffffce, %eax\n"
        /* } scope */
        "leave\n" /* line 566 */
        "retl\n"
    );
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
__attribute__((naked))
Boolean CAudioRecorder_Initialize(const CAudioRecorder * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1 */
        "movl $0, -0x34(%ebp)\n" /* line 78 */
        "movl $0, -0x30(%ebp)\n" /* line 79 */
        "movl $0x61756f75, -0x40(%ebp)\n" /* line 80 | desc */
        "movl $0x6168616c, -0x3c(%ebp)\n" /* line 81 */
        "movl $0x6170706c, -0x38(%ebp)\n" /* line 82 */
        "leal -0x40(%ebp), %eax\n" /* line 84 | desc */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll FindNextComponent\n"
        "movl %eax, %edx\n" /* theComponent */
        "testl %eax, %eax\n" /* line 43 */
        "je .Lf1f6832_001f6c8a\n"
        "leal 0x14(%edi), %eax\n" /* line 87 | this */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll OpenAComponent\n"
        "movswl %ax, %ebx\n" /* error */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl $1, -0x20(%ebp)\n" /* line 92 | enableIO */
        "movl $4, 0x14(%esp)\n" /* line 93 */
        "leal -0x20(%ebp), %esi\n" /* enableIO */
        "movl %esi, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x7d3, 4(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl $0, -0x20(%ebp)\n" /* line 98 | enableIO */
        "movl $4, 0x14(%esp)\n" /* line 99 */
        "movl %esi, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0x7d3, 4(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl $4, -0x24(%ebp)\n" /* line 104 | size */
        "leal 0x10(%edi), %esi\n" /* line 106 | this */
        "movl %esi, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* size */
        "movl %eax, 4(%esp)\n"
        "movl $0x64496e20, (%esp)\n"
        "calll AudioHardwareGetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl $4, 0x14(%esp)\n" /* line 109 */
        "movl %esi, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x7d0, 4(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl $4, -0x24(%ebp)\n" /* line 114 | size */
        "leal 0x1c(%edi), %eax\n" /* line 115 | this */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* size */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x766f6c6d, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioDeviceGetProperty\n"
        "testl %eax, %eax\n" /* line 116 */
        "jne .Lf1f6832_001f6c56\n"
        ".Lf1f6832_001f69c3:\n"
        "movl $CAudioRecorder_RenderCallbackProc, -0x2c(%ebp)\n" /* line 124 | callbackInfo */
        "movl %edi, -0x28(%ebp)\n" /* line 125 | this */
        "movl $8, 0x14(%esp)\n" /* line 127 */
        "leal -0x2c(%ebp), %eax\n" /* callbackInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x7d5, 4(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl 0x14(%edi), %eax\n" /* line 132 | this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitInitialize\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl $0x28, -0x24(%ebp)\n" /* line 138 | size */
        "leal -0x24(%ebp), %eax\n" /* line 140 | size */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x68(%ebp), %esi\n" /* sourceFormat */
        "movl %esi, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl 0xc(%edi), %ecx\n" /* line 146 | this */
        "xorl %eax, %eax\n"
        "cmpl $0x10, %ecx\n"
        "sete %al\n"
        "leal 8(, %eax, 4), %eax\n"
        "movl %ecx, %edx\n" /* line 151 | bytesPerPacket */
        "shrl $3, %edx\n" /* bytesPerPacket */
        "imull 8(%edi), %edx\n" /* this, bytesPerPacket */
        "movl $0x6c70636d, -0x88(%ebp)\n" /* line 155 */
        "movl %eax, -0x84(%ebp)\n" /* line 156 */
        "movl %edx, -0x80(%ebp)\n" /* line 157 */
        "movl $1, -0x7c(%ebp)\n" /* line 158 */
        "movl %edx, -0x78(%ebp)\n" /* line 159 */
        "movl 8(%edi), %eax\n" /* line 160 | this */
        "movl %eax, -0x74(%ebp)\n"
        "movl %ecx, -0x70(%ebp)\n" /* line 161 */
        "movsd -0x68(%ebp), %xmm0\n" /* line 166 | sourceFormat */
        "movsd %xmm0, -0x90(%ebp)\n" /* destFormat */
        "movl $0x28, 0x14(%esp)\n" /* line 168 */
        "leal -0x90(%ebp), %eax\n" /* destFormat */
        "movl %eax, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl $0x28, -0x24(%ebp)\n" /* line 173 | size */
        "leal -0x24(%ebp), %eax\n" /* line 174 | size */
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movsd (%edi), %xmm0\n" /* line 180 | this */
        "movsd %xmm0, -0x90(%ebp)\n" /* destFormat */
        "leal 0x4c(%edi), %eax\n" /* line 182 | this */
        "movl %eax, 8(%esp)\n"
        "leal -0x90(%ebp), %eax\n" /* destFormat */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll AudioConverterNew\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf1f6832_001f6c62\n"
        "movl $4, -0x24(%ebp)\n" /* line 189 | size */
        "leal -0x24(%ebp), %eax\n" /* line 190 | size */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* framesPerSlice */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "movl $0x200, %edx\n" /* line 193 */
        "testl %eax, %eax\n"
        "cmovel -0x1c(%ebp), %edx\n" /* framesPerSlice */
        "movl %edx, -0x1c(%ebp)\n" /* framesPerSlice */
        "fnstcw -0x9a(%ebp)\n" /* line 199 */
        "movzwl -0x9a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x9c(%ebp)\n"
        "fldl -0x90(%ebp)\n" /* destFormat */
        "fldcw -0x9c(%ebp)\n"
        "fistpll -0xa8(%ebp)\n"
        "fldcw -0x9a(%ebp)\n"
        "movl -0xa8(%ebp), %eax\n"
        "imull -0x78(%ebp), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, 0x54(%edi)\n" /* this */
        "movl %eax, (%esp)\n" /* line 200 */
        "calll malloc\n"
        "movl %eax, 0x50(%edi)\n" /* this */
        "movl -0x50(%ebp), %eax\n" /* line 205 */
        "imull -0x1c(%ebp), %eax\n" /* framesPerSlice */
        "movl %eax, 0x5c(%edi)\n" /* this */
        "movl %eax, (%esp)\n" /* line 206 */
        "calll malloc\n"
        "movl %eax, 0x58(%edi)\n" /* this */
        "fnstcw -0x9a(%ebp)\n" /* line 211 */
        "movzwl -0x9a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x9c(%ebp)\n"
        "fldl -0x68(%ebp)\n" /* sourceFormat */
        "fldcw -0x9c(%ebp)\n"
        "fistpll -0xa8(%ebp)\n"
        "fldcw -0x9a(%ebp)\n"
        "movl -0xa8(%ebp), %eax\n"
        "imull -0x50(%ebp), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x60(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_Alloc\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1f6832_001f6c4b:\n"
        "addl $0xbc, %esp\n" /* line 228 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f6832_001f6c56:\n"
        "movl $0x3f800000, 0x1c(%edi)\n" /* line 118 | this */
        "jmp .Lf1f6832_001f69c3\n"
        ".Lf1f6832_001f6c62:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        ".Lf1f6832_001f6c70:\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        ".Lf1f6832_001f6c8a:\n"
        "movl $4, (%esp)\n"
        "calll ___cxa_allocate_exception\n"
        "movl $0xffffffce, (%eax)\n"
        "jmp .Lf1f6832_001f6c70\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 222 */
        "calll ___cxa_begin_catch\n"
        "movl %edi, (%esp)\n" /* line 224 | this */
        "calll CAudioRecorder_Shutdown\n"
        "calll ___cxa_end_catch\n" /* line 222 */
        "xorl %eax, %eax\n"
        "jmp .Lf1f6832_001f6c4b\n"
        "movl %eax, %ebx\n" /* error */
        "calll ___cxa_end_catch\n"
        "movl %ebx, (%esp)\n" /* error */
        "calll __Unwind_Resume\n"
    );
}

/* line 62 */
__attribute__((naked))
void ZN14CAudioRecorderD1Ev(void) /* CAudioRecorder_~CAudioRecorder */
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
        ".Lf1f6cc6_001f6d02:\n"
        "leal 0x20(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll ZN6CMutexD1Ev\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n"
        "jmp .Lf1f6cc6_001f6d02\n"
    );
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
__attribute__((naked))
OSStatus CAudioRecorder_AudioConverterProc(AudioConverterRef inAudioConverter, UInt32 *ioDataSize, void * *outData, void *inUserData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 575 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* ioDataSize */
        "movl 0x14(%ebp), %ebx\n" /* inUserData */
        /* { scope 1: lock */
        "testl %ebx, %ebx\n" /* line 581 | inUserData */
        "je .Lf1f6d6e_001f6df4\n"
        /* { scope 2 */
        "leal 0x20(%ebx), %eax\n" /* line 529 */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl %edi, 4(%esp)\n" /* line 531 */
        "leal 0x60(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_ReadPtr\n"
        "movl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* outData */
        "movl %edx, (%eax)\n"
        "cmpb $0, 0x19(%ebx)\n" /* line 533 */
        "jne .Lf1f6d6e_001f6dc1\n"
        ".Lf1f6d6e_001f6daf:\n"
        "movl %esi, (%esp)\n" /* line 538 */
        "calll ZN11StMutexLockD1Ev\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 591 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lock */
        /* { scope 2 */
        ".Lf1f6d6e_001f6dc1:\n"
        "testl %edx, %edx\n" /* line 533 */
        "je .Lf1f6d6e_001f6daf\n"
        "movl (%edi), %eax\n" /* line 535 */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "jmp .Lf1f6d6e_001f6daf\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 538 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        ".Lf1f6d6e_001f6de7:\n"
        "movl %ebx, (%esp)\n" /* line 586 | inUserData */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        ".Lf1f6d6e_001f6df4:\n"
        "movl $0xffffffce, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 591 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* inUserData */
        "jmp .Lf1f6d6e_001f6de7\n"
    );
}

