/* Converted to C from ASM: win_voice.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_voice.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdio.h>

extern const dvar_t *Dvar_RegisterBool(const char *name, int defaultValue, int flags);
extern const dvar_t *Dvar_RegisterFloat(const char *name, float defaultValue, float min, float max, int flags);
extern int Record_Init(int callInit, const void *handle);
extern void Sound_Init(int freq);
extern void Encode_Init(int freq);
extern void Decode_Init(int freq);
extern void Record_Shutdown(void);
extern void Encode_Shutdown(void);
extern void Decode_Shutdown(void);
extern void Sound_Shutdown(void);
extern void *Sound_NewSample(void);
extern void Sound_SampleFrame(void *sample);
extern void Sound_DestroySample(void *sample);
extern void Sound_UpdateSample(void *sample, void *data, int size);
extern void Sound_Frame(void);
extern void Record_Frame(void);
extern int Record_Start(recordingSample_t *sample);
extern int Record_Stop(recordingSample_t *sample);
extern recordingSample_t *Record_NewSample(void);
extern int Record_DestroySample(recordingSample_t *sample);
extern void mixerGetRecordSource(char *source);
extern void mixerSetRecordSource(const char *source);
extern int mixerGetRecordLevel(const char *source);
extern void mixerSetRecordLevel(const char *source, int level);
extern void mixerSetMicrophoneMute(int mute);
extern int Sys_Milliseconds(void);
extern int Decode_Sample(void *inData, int inSize, void *outData, int maxOutSize);

extern byte *voice_freq_ptr;      /* imp_g_current_bandwidth_setting */
extern byte *voice_maxframe_ptr;  /* imp_g_frame_size */

extern const dvar_t *winvoice_mic_mute; /* 0x0 */
extern const dvar_t *winvoice_mic_reclevel; /* 0x0 */
extern const dvar_t *winvoice_save_voice; /* 0x0 */
extern const dvar_t *winvoice_mic_scaler; /* 0x0 */
extern int mic_old_reclevel; /* 0x0 */
extern int mic_current_reclevel; /* 0x0 */
extern char old_rec_source[256]; /* 0x0 */
extern float voice_current_voicelevel; /* 0x0 */
extern float voice_current_scaler; /* 0x0 */
extern int g_voice_initialized; /* 0x0 */
extern float levelSamples[6]; /* 0x0 */
extern int sampleCount; /* 0x0 */
static int count; /* count */
static Bool recording; /* recording */
static Bool playing; /* playing */
static recordingSample_t *currentRecordingSample; /* currentRecordingSample */
static short unsigned int * (*s_clientSamples[64])[4]; /* s_clientSamples */
static int s_clientTalkTime[64]; /* s_clientTalkTime */

Bool Voice_Init(void);
float Voice_GetVoiceLevel(void);
unsigned int Voice_Playback(void);
unsigned int Voice_IncomingVoiceData(int talker, unsigned char *data, int packetDataSize);
Bool Voice_IsClientTalking(int clientNum);
unsigned int Voice_Shutdown(void);
int Voice_GetLocalVoiceData(ClientVoicePacket_t *voiceData);

/* line 64 */
Bool Voice_Init(void)
{
    int *freq;
    int i;
    int level;

    winvoice_mic_mute = Dvar_RegisterBool("winvoice_mic_mute", 1, 0x1001);
    winvoice_mic_reclevel = Dvar_RegisterFloat("winvoice_mic_reclevel", 65535.0f, 0.0f, 65535.0f, 0x1001);
    winvoice_save_voice = Dvar_RegisterBool("winvoice_save_voice", 0, 0x1001);
    winvoice_mic_scaler = Dvar_RegisterFloat("winvoice_mic_scaler", 1.0f, 0.25f, 2.0f, 0x1001);

    freq = *(int **)&voice_freq_ptr;
    *freq = 0;

    if (!Record_Init(0, 0))
        return 0;

    Sound_Init(0);
    Encode_Init(*freq);
    Decode_Init(*freq);

    mixerGetRecordSource(old_rec_source);
    mixerSetRecordSource("Mic");
    mic_old_reclevel = mixerGetRecordLevel("Mic");

    level = (unsigned short)(int)*(float *)((byte *)winvoice_mic_reclevel + 8);
    mic_current_reclevel = level;

    level = (unsigned short)(int)*(float *)((byte *)winvoice_mic_reclevel + 8);
    mixerSetRecordLevel("Mic", level);

    mixerSetMicrophoneMute(*(unsigned char *)((byte *)winvoice_mic_mute + 8));

    g_voice_initialized = 1;

    memset(s_clientTalkTime, 0, 0x100);

    for (i = 0; i < 64; i++) {
        s_clientSamples[i] = Sound_NewSample();
    }

    return 0;
}

/* line 148 */
float Voice_GetVoiceLevel(void)
{
    float result;
    int idx;
    int i;

    if (!g_voice_initialized)
        return 0.0f;

    idx = sampleCount % 6;
    result = voice_current_voicelevel / 32767.0f / 6.0f;
    levelSamples[idx] = result;
    sampleCount++;

    result = 0.0f;
    for (i = 0; i < 6; i++) {
        result += levelSamples[i];
    }

    return result;
}

/* line 166 */
unsigned int Voice_Playback(void)
{
    int level;
    int i;

    if (!g_voice_initialized)
        return 0;

    level = (unsigned short)(int)*(float *)((byte *)winvoice_mic_reclevel + 8);
    if (level != mic_current_reclevel) {
        mic_current_reclevel = level;
        level = (unsigned short)(int)*(float *)((byte *)winvoice_mic_reclevel + 8);
        mixerSetRecordLevel("Mic", level);
    }

    for (i = 0; i < 64; i++) {
        Sound_SampleFrame(s_clientSamples[i]);
    }

    Sound_Frame();
}

/* line 212 */
unsigned int Voice_IncomingVoiceData(int talker, unsigned char *data, int packetDataSize)
{
    short decodedData[4096];
    int talkerIdx;
    int processedBytes;
    int maxFrameSize;
    int remaining;
    int bytesToProcess;
    int decodedLen;
    FILE *fptr;

    if (!playing)
        playing = 1;

    talkerIdx = (unsigned char)talker;
    s_clientTalkTime[talkerIdx] = Sys_Milliseconds();

    decodedLen = 0;
    if (packetDataSize > 0) {
        processedBytes = 0;
        maxFrameSize = *(int *)voice_maxframe_ptr;

        while (processedBytes < packetDataSize) {
            remaining = packetDataSize - processedBytes;
            bytesToProcess = remaining < maxFrameSize ? remaining : maxFrameSize;

            decodedLen = Decode_Sample(data + processedBytes, bytesToProcess, decodedData, maxFrameSize);
            if (decodedLen > 0) {
                Sound_UpdateSample(s_clientSamples[talkerIdx], decodedData, decodedLen);
            }
            processedBytes += bytesToProcess;
        }
    }

    if (*(unsigned char *)((byte *)winvoice_save_voice + 8)) {
        fptr = fopen("voice.wav", "a");
        if (fptr != NULL) {
            fwrite(decodedData, decodedLen, 1, fptr);
            fclose(fptr);
        }
    }
}

/* line 253 */
Bool Voice_IsClientTalking(int clientNum)
{
    return (Sys_Milliseconds() - s_clientTalkTime[clientNum]) <= 299;
}

/* line 115 */
unsigned int Voice_Shutdown(void)
{
    int i;

    if (!g_voice_initialized)
        return 0;

    for (i = 0; i < 64; i++) {
        Sound_DestroySample(s_clientSamples[i]);
    }

    if (recording) {
        Record_Stop(currentRecordingSample);
        Record_DestroySample(currentRecordingSample);
        recording = 0;
    }

    Record_Shutdown();
    Encode_Shutdown();
    Decode_Shutdown();
    Sound_Shutdown();

    mixerSetMicrophoneMute(1);
    mixerSetRecordLevel("Mic", (unsigned short)mic_old_reclevel);
    mixerSetRecordSource(old_rec_source);

    g_voice_initialized = 0;
}

/* line 185 */
int Voice_GetLocalVoiceData(ClientVoicePacket_t *voiceData)
{
    float scaler;

    if (!g_voice_initialized)
        return 0;

    if (!recording) {
        currentRecordingSample = Record_NewSample();
        Record_Start(currentRecordingSample);
        recording = 1;
        count++;
    }

    scaler = *(float *)((byte *)winvoice_mic_scaler + 8);
    if (scaler != voice_current_scaler) {
        voice_current_scaler = scaler;
        if (scaler < 0.5f)
            voice_current_scaler = 0.5f;
        else if (scaler > 1.5f)
            voice_current_scaler = 1.5f;
    }

    Record_Frame();
    return 0;
}
