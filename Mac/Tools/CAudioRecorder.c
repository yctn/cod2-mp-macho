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
Float32 CAudioRecorder_GetRecordLevel(const CAudioRecorder * _this) { return 0; }
