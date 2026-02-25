/* Converted to C from ASM: CAStreamBasicDescription.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Extras/CoreAudio/CAStreamBasicDescription.cpp */

#include "common_types.h"
#include "imports.h"

void CAStreamBasicDescription_SetCanonical(CAStreamBasicDescription *_this, UInt32 nChannels, int interleaved)
{
    unsigned int *p = (unsigned int *)_this;
    p[2] = 0x6c70636d;  /* mFormatID = 'lpcm' */
    p[3] = 9;           /* mFormatFlags = kAudioFormatFlagIsFloat | kAudioFormatFlagIsPacked */
    p[8] = 32;          /* mBitsPerChannel */
    p[7] = nChannels;   /* mChannelsPerFrame */
    p[5] = 1;           /* mFramesPerPacket */
    if (interleaved) {
        unsigned int bytesPerFrame = nChannels << 2;
        p[6] = bytesPerFrame;  /* mBytesPerFrame */
        p[4] = bytesPerFrame;  /* mBytesPerPacket */
    } else {
        p[6] = 4;       /* mBytesPerFrame */
        p[4] = 4;       /* mBytesPerPacket */
        p[3] = 0x29;    /* mFormatFlags |= kAudioFormatFlagIsNonInterleaved */
    }
}

void CAStreamBasicDescription_CAStreamBasicDescription(CAStreamBasicDescription *_this)
{
    memset(_this, 0, 40);
}
