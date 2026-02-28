/* Converted to C from ASM: record.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/groupvoice/record.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern char enc_buffer[4096]; /* 0x0 */
extern int enc_buffer_pos; /* 0x0 */
extern short int partial_audio_buffer[640]; /* 0x0 */
extern int samples_in_partial_audio_buffer; /* 0x0 */

extern int DSOUNDRecord_Start(recordingSample_t *sample);
extern int DSOUNDRecord_Stop(recordingSample_t *sample);
extern recordingSample_t *DSOUNDRecord_NewSample(void);
extern int DSOUNDRecord_DestroySample(recordingSample_t *sample);
extern void DSOUNDRecord_Shutdown(void);
extern void DSOUNDRecord_Frame(void);
extern int DSOUNDRecord_Init(int callInit, const void *handle);
extern void Encode_Shutdown(void);
extern int Encode_GetFrameSize(void);
extern int Encode_Sample(void *audioData, void *outBuf, int outSize);
extern int Voice_SendVoiceData(void);
extern int IsTalking(void);
extern void CL_VoiceTransmit(void);
extern void Client_SendVoiceData(int size, void *data);
extern void Com_Printf(const char *msg, ...);

extern byte *encode_vol_ptr;       /* imp_voice_current_voicelevel */
extern byte *voice_scale_ptr;      /* imp_voice_current_scaler */
extern byte *record_callback_ptr;  /* imp_current_audioCallback */

int Record_Start(recordingSample_t *sample);
int Record_Stop(recordingSample_t *sample);
recordingSample_t * Record_NewSample(void);
int Record_DestroySample(recordingSample_t *sample);
void Record_Shutdown(void);
void Record_Frame(void);
int Record_QueueAudioDataForEncoding(audioSample_t *sample);
int Record_AudioCallback(audioSample_t *sample);
int Record_Init(int callInit, const void *handle);

/* line 159 */
int Record_Start(recordingSample_t *sample)
{
    return DSOUNDRecord_Start(sample);
}

/* line 170 */
int Record_Stop(recordingSample_t *sample)
{
    return DSOUNDRecord_Stop(sample);
}

/* line 181 */
recordingSample_t *Record_NewSample(void)
{
    return DSOUNDRecord_NewSample();
}

/* line 192 */
int Record_DestroySample(recordingSample_t *sample)
{
    return DSOUNDRecord_DestroySample(sample);
}

/* line 203 */
void Record_Shutdown(void)
{
    Encode_Shutdown();
    DSOUNDRecord_Shutdown();
}

/* line 220 */
void Record_Frame(void)
{
    DSOUNDRecord_Frame();
}

/* line 46 */
int Record_QueueAudioDataForEncoding(audioSample_t *sample)
{
    short audio_buffer[4096];
    int total_bytes;
    int encode_frame_size;
    int ii;
    float *p_vol;
    short *data;
    int numSamples;
    int channels;
    int partial;

    /* Clear encode volume accumulator */
    p_vol = *(float **)&encode_vol_ptr;
    *p_vol = 0.0f;

    data = *(short **)sample;
    numSamples = *(int *)((byte *)sample + 8);
    channels = *(int *)((byte *)sample + 0xc);

    /* Apply volume scaling and compute average amplitude (stereo only) */
    if (channels == 2 && numSamples > 0) {
        float scale = **(float **)&voice_scale_ptr;
        for (ii = 0; ii < numSamples; ii++) {
            float fval = (float)data[ii] * scale;
            data[ii] = (short)(int)fval;
            int abs_val = (short)(int)fval;
            if (abs_val < 0) abs_val = -abs_val;
            *p_vol += (float)abs_val;
        }
        *p_vol /= (float)numSamples;
    }

    /* Check if voice data should be sent */
    if (!Voice_SendVoiceData()) {
        return 0;
    }

    if (!IsTalking()) {
        CL_VoiceTransmit();
        return 0;
    }

    /* Get encoding frame size */
    encode_frame_size = Encode_GetFrameSize();
    *(int *)((byte *)sample + 0x1c) = 0;

    if (encode_frame_size <= 0) {
        Com_Printf("Invalid encode frame size of %i\n", encode_frame_size);
        return 0;
    }

    if (*(int *)((byte *)sample + 4) <= 0) {
        Com_Printf("Invalid sample length of %i samples\n", numSamples);
        return 0;
    }

    total_bytes = 0;

    /* Main encoding loop */
    while (1) {
        int samplesProcessed = *(int *)((byte *)sample + 0x1c);
        partial = samples_in_partial_audio_buffer;

        if (numSamples - samplesProcessed + partial < encode_frame_size) {
            /* Not enough data for a full frame - store remainder */
            if (samplesProcessed < numSamples) {
                int remaining = numSamples - samplesProcessed;
                memcpy(partial_audio_buffer + partial,
                       data + samplesProcessed * channels,
                       remaining * channels);
                samples_in_partial_audio_buffer += numSamples - *(int *)((byte *)sample + 0x1c);
            }
            return total_bytes;
        }

        /* Copy from partial buffer first */
        int partial_take = 0;
        if (partial > 0) {
            int max_take = encode_frame_size - 4;
            if (partial < max_take)
                partial_take = partial;
            else
                partial_take = max_take;
            samples_in_partial_audio_buffer = partial_take;
            memcpy(audio_buffer, partial_audio_buffer, partial_take * channels);
            samples_in_partial_audio_buffer -= partial_take;
            partial = partial_take;
        }

        /* Copy remaining from source to fill frame */
        {
            int src_take = encode_frame_size - partial;
            samplesProcessed = *(int *)((byte *)sample + 0x1c);
            memcpy((byte *)audio_buffer + partial * 2,
                   data + samplesProcessed * channels,
                   src_take * channels);
            *(int *)((byte *)sample + 0x1c) += src_take;
        }

        /* Encode and send */
        {
            int avail = 4096 - enc_buffer_pos;
            int encoded = Encode_Sample(audio_buffer, enc_buffer + enc_buffer_pos, avail);
            total_bytes += encoded;
            Client_SendVoiceData(encoded, enc_buffer + enc_buffer_pos);
        }
    }
}

/* line 154 */
int Record_AudioCallback(audioSample_t *sample)
{
    return Record_QueueAudioDataForEncoding(sample);
}

/* line 231 */
int Record_Init(int callInit, const void *handle)
{
    *(void **)&record_callback_ptr = (void *)Record_AudioCallback;
    return DSOUNDRecord_Init(1, handle);
}
