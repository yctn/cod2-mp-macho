/* ASM dump from: mac_record_dsound.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_record_dsound.cpp */

#include "common_types.h"
#include "imports.h"

int g_sound_recordFrequency; /* 0x0 */
int g_sound_recordVolume; /* 0x0 */
int g_sound_channels; /* 0x0 */
int g_recording_initialized; /* 0x0 */
int g_currently_recording; /* 0x0 */
extern int (*current_audioCallback)(); /* 0x0 */
static recordingSample_t s_recordingSamples[65]; /* 0xff2220 */
static recordingSample_t *s_recordingSamplePtr; /* 0xff2b44 */
static recordingSample_t *g_current_sample; /* 0xff2204 */
static CAudioRecorder *sAudioRecorder; /* 0xff2200 */

int DSOUNDRecord_Start(recordingSample_t *pRecSample);
int DSOUNDRecord_Stop(recordingSample_t *pRecSample);
recordingSample_t * DSOUNDRecord_NewSample(void);
int DSOUNDRecord_DestroySample(recordingSample_t *pRecSample);
int DSOUNDRecord_Init(void);
void DSOUNDRecord_Shutdown(void);
void DSOUNDRecord_Frame(void);
int mixerSetRecordLevel(char *SrcName, int newLevel);
int mixerGetRecordLevel(char *SrcName);
int mixerGetRecordSource(char *srcName);
int mixerSetRecordSource(char *SrcName);
int mixerSetMicrophoneMute(int bMute);

/* line 43 — C replacement from snd_mac.c */
int DSOUNDRecord_Start(recordingSample_t *pRecSample)
{
    if (!g_recording_initialized)
        return -1;

    if (!sAudioRecorder)
        return -1;

    if (!CAudioRecorder_Start(sAudioRecorder))
    {
        Com_Printf(str_002b920c);
        return -1;
    }

    g_current_sample = pRecSample;
    g_currently_recording = 1;
    return 0;
}

/* line 67 — C replacement from snd_mac.c */
int DSOUNDRecord_Stop(recordingSample_t *pRecSample)
{
    if (!g_recording_initialized)
        return -1;

    if (!sAudioRecorder)
        return -1;

    CAudioRecorder_Stop(sAudioRecorder);
    g_current_sample = 0;
    g_currently_recording = 0;
    return 0;
}

/* line 84 — C replacement from snd_mac.c */
recordingSample_t * DSOUNDRecord_NewSample(void)
{
    recordingSample_t *sample;

    if (!g_recording_initialized)
        return NULL;

    sample = s_recordingSamplePtr;
    s_recordingSamplePtr = (recordingSample_t *)((char *)s_recordingSamplePtr + 0x24);

    memset(sample, 0, 9 * sizeof(int));

    sample->frequency = g_sound_recordFrequency;
    sample->volume = g_sound_recordVolume;
    sample->pan = 0x80;
    sample->channels = g_sound_channels;
    sample->playMode = 2;

    return sample;
}

/* line 108 — C replacement from snd_mac.c */
int DSOUNDRecord_DestroySample(recordingSample_t *pRecSample)
{
    return g_recording_initialized != 0;
}

/* line 126 — C replacement from snd_mac.c */
int DSOUNDRecord_Init(void)
{
    void *recorder;

    s_recordingSamplePtr = (recordingSample_t *)0xff2220;
    g_recording_initialized = 0;

    recorder = __Znwm(0x78);
    CAudioRecorder_CAudioRecorder(recorder, (double)g_sound_recordFrequency, g_sound_channels, 16);
    sAudioRecorder = recorder;

    if (!CAudioRecorder_Initialize(recorder))
    {
        if (sAudioRecorder)
        {
            ZN14CAudioRecorderD1Ev(sAudioRecorder);
            __ZdlPv(sAudioRecorder);
        }
        sAudioRecorder = 0;
        return 0;
    }

    g_recording_initialized = 1;
    return 1;
}

/* line 150 — C replacement from snd_mac.c */
void DSOUNDRecord_Shutdown(void)
{
    if (sAudioRecorder)
    {
        CAudioRecorder_Shutdown(sAudioRecorder);
        if (sAudioRecorder)
        {
            ZN14CAudioRecorderD1Ev(sAudioRecorder);
            __ZdlPv(sAudioRecorder);
        }
        sAudioRecorder = 0;
    }
    g_recording_initialized = 0;
}

/* line 190 — C replacement from snd_mac.c */
void DSOUNDRecord_Frame(void)
{
    void *buffer;
    unsigned int size;
    audioSample_t audioSample;

    if (!g_recording_initialized)
        return;
    if (!g_currently_recording)
        return;
    if (!g_current_sample)
        return;

    buffer = CAudioRecorder_GetBuffer(sAudioRecorder, &size);
    if (!buffer)
        return;
    if (!size)
        return;

    audioSample.stereo = g_sound_channels > 1;
    audioSample.bytesPerSample = 2;
    audioSample.frequency = g_sound_recordFrequency;
    audioSample.sampleOffset = 0;
    audioSample.channels = g_sound_channels;
    audioSample.lengthInSamples = size / (g_sound_channels * 2);
    audioSample.lengthInBytes = size;
    audioSample.buffer = buffer;

    current_audioCallback(&audioSample);
}

/* line 205 — C replacement from snd_mac.c */
int mixerSetRecordLevel(char *SrcName, int newLevel)
{
    if (sAudioRecorder)
    {
        float level = (float)(unsigned short)newLevel / 65535.0f;
        CAudioRecorder_SetRecordLevel(sAudioRecorder, level);
    }
    return 0;
}

/* line 220 — C replacement from snd_mac.c */
int mixerGetRecordLevel(char *SrcName)
{
    if (!sAudioRecorder)
        return 0xFFFF;

    float level = CAudioRecorder_GetRecordLevel(sAudioRecorder);
    return (int)(level * 65535.0);
}

/* line 234 — C replacement from snd_mac.c */
int mixerGetRecordSource(char *srcName)
{
    *(int *)srcName = 0x63614d; /* "Mac" */
    return 1;
}

/* line 242 — C replacement from snd_mac.c */
int mixerSetRecordSource(char *SrcName)
{
    return 1;
}

/* line 249 — C replacement from snd_mac.c */
int mixerSetMicrophoneMute(int bMute)
{
    if (sAudioRecorder)
    {
        CAudioRecorder_Mute(sAudioRecorder, !bMute);
    }
    return 0;
}
