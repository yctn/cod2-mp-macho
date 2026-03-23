/* ASM dump from: mac_play_dsound.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_play_dsound.cpp */

#include "common_types.h"
#include "imports.h"

/* Forward declarations */
void CCircularBuffer_Write(const CCircularBuffer *_this, const void *inBuffer, UInt32 *ioSize);

static Bool dsoundplay_initialized; /* 0xff2b80 */

int DSound_UpdateSample(sample_t *sample, char *data, unsigned int data_len);
sample_t * DSound_NewSample(void);
int DSound_Init(void);
void DSound_Shutdown(void);
void DSound_Frame(void);
void DSound_SampleFrame(sample_t *sample);

/* line 27 — C replacement from snd_mac.c */
int DSound_UpdateSample(sample_t *sample, char *data, unsigned int data_len)
{
    if (!dsoundplay_initialized)
        return -1;

    if (!data_len)
        return 0;

    UInt32 size = data_len;
    CCircularBuffer_Write(sample->mssBuffer, data, &size);
    return data_len;
}

/* line 47 */
sample_t * DSound_NewSample(void) { return 0; }
