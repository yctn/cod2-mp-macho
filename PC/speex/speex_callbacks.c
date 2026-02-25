/* Converted to C from ASM: speex_callbacks.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/speex_callbacks.c */

#include "common_types.h"
#include "imports.h"

extern int speex_bits_unpack_unsigned(SpeexBits *bits, int nbBits);
extern void speex_bits_advance(SpeexBits *bits, int n);

int speex_inband_handler(SpeexBits *bits, SpeexCallback *callback_list, void *state)
{
    int id;
    int adv;

    id = speex_bits_unpack_unsigned(bits, 4);

    if (callback_list[id].func) {
        return callback_list[id].func(bits, state, callback_list[id].data);
    }

    if (id <= 1)
        adv = 1;
    else if (id <= 7)
        adv = 4;
    else if (id <= 9)
        adv = 8;
    else if (id <= 11)
        adv = 16;
    else if (id <= 13)
        adv = 32;
    else
        adv = 64;

    speex_bits_advance(bits, adv);
    return 0;
}

int speex_default_user_handler(SpeexBits *bits, void *state, void *data)
{
    int len;

    len = speex_bits_unpack_unsigned(bits, 4);
    speex_bits_advance(bits, 5 + len * 8);
    return 0;
}

