/* ASM dump from: MacMSS_Sample.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS_Sample.cp */

#include "common_types.h"
#include "imports.h"
#include <math.h>

void CSoundObject_CSoundObject(char *_this, CSoundEngine *engine, unsigned int busIndex);
void *CSoundEngine_GetMixerUnit(CSoundEngine *engine);

/*
 * CSampleSound layout (deduced from ASM, inherits CSoundObject):
 *   offset 0x00: vtable pointer
 *   offset 0x04: CSoundEngine *engine
 *   offset 0x08: UInt32 busIndex
 *   offset 0x64: float masterVolume
 *   offset 0x68: float leftLevel
 *   offset 0x6c: float rightLevel
 *   offset 0xe0: int scheduledSlices[10] (initialized to -1)
 *   offset 0x108: int field_108
 *   offset 0x10c: byte field_10c
 *   offset 0x10d: byte field_10d
 *   offset 0x10e: byte field_10e
 *   offset 0x10f: byte formatChanged
 *   offset 0x110: byte positionChanged
 *   offset 0x111: byte isMuted
 *   offset 0x114: int field_114
 *   offset 0x118: int field_118
 *   offset 0x11c: byte field_11c
 */

void CSampleSound_CSampleSound(CSampleSound *_this, CSoundEngine *inEngine, UInt32 inBusIndex);
void CSampleSound_TheadIdle(const CSampleSound * _this);
void CSampleSound_stop_sample(const CSampleSound * _this);
void CSampleSound_end_sample(const CSampleSound * _this);
bool CSampleSound_open_stream(const CSampleSound * _this, const char *filename);
void CSampleSound_close_stream(const CSampleSound * _this);
void CSampleSound_ChangedFormat(CSampleSound *_this);
void CSampleSound_Changed3DPosition(CSampleSound *_this);
OSStatus CSampleSound_DoConvert(const CSampleSound * _this, UInt32 *ioNumberDataPackets, AudioBufferList *ioData);
OSStatus CSampleSound_AudioConverterProc(AudioConverterRef inAudioConverter, UInt32 *ioNumberDataPackets, AudioBufferList *ioData, AudioStreamPacketDescription **outDataPacketDescription, void *inUserData);
void CSampleSound_UpdateStreamFormat(const CSampleSound * _this);
void CSampleSound_ChangedVolume(CSampleSound *_this);
void CSampleSound_Update3DValues(const CSampleSound * _this);
OSStatus CSampleSound_DoRender(const CSampleSound * _this, AudioUnitRenderActionFlags *ioActionFlags, UInt32 inNumberFrames, AudioBufferList *ioData);
OSStatus CSampleSound_RenderCallbackProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData);
void CSampleSound_resume_sample(const CSampleSound * _this);
OSStatus CSampleSound_InitSample(const CSampleSound * _this, UInt32 inSoundType, UInt32 inSpatializationAlgorithm, UInt32 in3DRenderFlags, UInt32 inDopplerShift);
void CSampleSound_Changed3DDistances(const CSampleSound * _this);
OSStatus CSampleSound_RenderNotifyProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData);
void ZN12CSampleSoundD2Ev(void); /* CSampleSound_~CSampleSound */
void ZN12CSampleSoundD1Ev(void); /* CSampleSound_~CSampleSound */
void ZN12CSampleSoundD0Ev(void); /* CSampleSound_~CSampleSound */
OSStatus CSampleSound_DoPreRender(const CSampleSound * _this);
OSStatus CSampleSound_DoPostRender(const CSampleSound * _this);

/* line 23 */
void CSampleSound_CSampleSound(CSampleSound *_this, CSoundEngine *inEngine, UInt32 inBusIndex)
{
    char *p = (char *)_this;

    CSoundObject_CSoundObject((char *)_this, inEngine, inBusIndex);

    *(int *)(p + 0x00) = 0x3322c8; /* vtable */
    *(int *)(p + 0x108) = 0;
    *(char *)(p + 0x10c) = 0;
    *(char *)(p + 0x10d) = 0;
    *(char *)(p + 0x10e) = 0;
    *(char *)(p + 0x10f) = 1; /* formatChanged = true */
    *(char *)(p + 0x110) = 0;
    *(char *)(p + 0x111) = 0;
    *(int *)(p + 0x114) = 0;
    *(int *)(p + 0x118) = 0;
    *(char *)(p + 0x11c) = 0;

    /* Initialize 10 scheduled slice entries to -1 */
    int *slices = (int *)(p + 0xe0);
    for (int i = 0; i < 10; i++)
        slices[i] = -1;
}

/* line 146 */
void CSampleSound_TheadIdle(const CSampleSound * _this)
{ }

/* line 201 */
void CSampleSound_stop_sample(const CSampleSound * _this)
{ }

/* line 252 */
void CSampleSound_end_sample(const CSampleSound * _this)
{ }

/* line 279 */
bool CSampleSound_open_stream(const CSampleSound * _this, const char *filename)
{ return 0; }

/* line 400 */
void CSampleSound_close_stream(const CSampleSound * _this)
{ }

/* line 469 */
void CSampleSound_ChangedFormat(CSampleSound *_this)
{
    *(char *)((char *)_this + 0x10f) = 1;
}

/* line 477 */
void CSampleSound_Changed3DPosition(CSampleSound *_this)
{
    *(char *)((char *)_this + 0x110) = 1;
}

/* line 926 */
OSStatus CSampleSound_DoConvert(const CSampleSound * _this, UInt32 *ioNumberDataPackets, AudioBufferList *ioData)
{ return 0; }

/* line 755 */
OSStatus CSampleSound_AudioConverterProc(AudioConverterRef inAudioConverter, UInt32 *ioNumberDataPackets, AudioBufferList *ioData, AudioStreamPacketDescription **outDataPacketDescription, void *inUserData)
{
    if (!inUserData)
        return -50; /* 0xffffffce = paramErr */

    return CSampleSound_DoConvert(inUserData, ioNumberDataPackets, ioData);
}

/* line 525 */
void CSampleSound_UpdateStreamFormat(const CSampleSound * _this)
{ }

/* line 431 */
void CSampleSound_ChangedVolume(CSampleSound *_this)
{
    char *p = (char *)_this;

    float leftLevel = *(float *)(p + 0x68);
    float rightLevel = *(float *)(p + 0x6c);
    float masterVolume = *(float *)(p + 0x64);

    float realVolume = (leftLevel + rightLevel) * 0.5f * masterVolume;

    if (realVolume > 1.0f)
        realVolume = 1.0f;

    if (realVolume <= 0.0f)
    {
        *(char *)(p + 0x111) = 1; /* muted */
        return;
    }

    float db = log10f(realVolume) * 20.0f;
    if (db < -120.0f)
        db = -120.0f;

    UInt32 busIndex = *(UInt32 *)(p + 0x08);
    CSoundEngine *engine = *(CSoundEngine **)(p + 0x04);
    AudioUnit mixerUnit = CSoundEngine_GetMixerUnit(engine);

    AudioUnitSetParameter(mixerUnit, 3 /* kStereoMixerParam_Volume */, 1 /* kAudioUnitScope_Input */, busIndex, db, 0);

    *(char *)(p + 0x111) = 0; /* not muted */
}

/* line 597 */
void CSampleSound_Update3DValues(const CSampleSound * _this)
{ }

/* line 779 */
OSStatus CSampleSound_DoRender(const CSampleSound * _this, AudioUnitRenderActionFlags *ioActionFlags, UInt32 inNumberFrames, AudioBufferList *ioData)
{ return 0; }

/* line 691 */
OSStatus CSampleSound_RenderCallbackProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData)
{
    if (!inRefCon)
        return -50; /* paramErr */

    return CSampleSound_DoRender(inRefCon, ioActionFlags, inNumberFrames, ioData);
}

/* line 223 */
void CSampleSound_resume_sample(const CSampleSound * _this)
{ }

/* line 84 */
OSStatus CSampleSound_InitSample(const CSampleSound * _this, UInt32 inSoundType, UInt32 inSpatializationAlgorithm, UInt32 in3DRenderFlags, UInt32 inDopplerShift)
{ return 0; }

/* line 485 */
void CSampleSound_Changed3DDistances(const CSampleSound * _this)
{ }

/* line 718 */
OSStatus CSampleSound_RenderNotifyProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData)
{ return 0; }

/* line 44 */
void ZN12CSampleSoundD2Ev(void) /* CSampleSound_~CSampleSound */
{ }

/* line 44 */
void ZN12CSampleSoundD1Ev(void) /* CSampleSound_~CSampleSound */
{ }

/* line 44 */
void ZN12CSampleSoundD0Ev(void) /* CSampleSound_~CSampleSound */
{ }

/* line 888 */
OSStatus CSampleSound_DoPreRender(const CSampleSound * _this)
{ return 0; }

/* line 906 */
OSStatus CSampleSound_DoPostRender(const CSampleSound * _this)
{ return 0; }

