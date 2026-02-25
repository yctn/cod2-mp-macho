/* ASM dump from: modes.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/modes.c */

#include "common_types.h"
#include "imports.h"

extern const SpeexMode speex_nb_mode; /* 0x0 */
extern const SpeexMode speex_wb_mode; /* 0x0 */
extern const SpeexMode speex_uwb_mode; /* 0x0 */
static const signed char gain_cdbk_nb[384]; /* 0x304620 */
static const signed char gain_cdbk_lbr[96]; /* 0x3050a0 */
static const signed char hexc_table[1024]; /* 0x303d20 */
static const signed char exc_5_256_table[1280]; /* 0x3047a0 */
static const signed char exc_5_64_table[320]; /* 0x3044e0 */
static const signed char exc_8_128_table[1024]; /* 0x304ca0 */
static const signed char exc_10_32_table[320]; /* 0x305100 */
static const signed char exc_10_16_table[160]; /* 0x305240 */
static const signed char exc_20_32_table[640]; /* 0x304260 */
static const signed char hexc_10_32_table[320]; /* 0x304120 */
static const ltp_params ltp_params_nb; /* 0x3341d8 */
static const ltp_params ltp_params_vlbr; /* 0x334418 */
static const ltp_params ltp_params_lbr; /* 0x334398 */
static const ltp_params ltp_params_med; /* 0x334318 */
static const split_cb_params split_cb_nb_vlbr; /* 0x334404 */
static const split_cb_params split_cb_nb_ulbr; /* 0x334164 */
static const split_cb_params split_cb_nb_lbr; /* 0x334384 */
static const split_cb_params split_cb_nb; /* 0x3341c4 */
static const split_cb_params split_cb_nb_med; /* 0x334304 */
static const split_cb_params split_cb_sb; /* 0x334244 */
static const split_cb_params split_cb_high; /* 0x333f64 */
static const split_cb_params split_cb_high_lbr; /* 0x334024 */
static const SpeexSubmode nb_submode1; /* 0x334440 */
static const SpeexSubmode nb_submode8; /* 0x334120 */
static const SpeexSubmode nb_submode2; /* 0x3343c0 */
static const SpeexSubmode nb_submode3; /* 0x334340 */
static const SpeexSubmode nb_submode4; /* 0x3342c0 */
static const SpeexSubmode nb_submode5; /* 0x334260 */
static const SpeexSubmode nb_submode6; /* 0x334200 */
static const SpeexSubmode nb_submode7; /* 0x334180 */
static const SpeexNBMode nb_mode; /* 0x334080 */
static const SpeexSubmode wb_submode1; /* 0x333dc0 */
static const SpeexSubmode wb_submode2; /* 0x333fe0 */
static const SpeexSubmode wb_submode3; /* 0x333f80 */
static const SpeexSubmode wb_submode4; /* 0x333f20 */
static const SpeexSBMode sb_wb_mode; /* 0x333e60 */
static const SpeexSBMode sb_uwb_mode; /* 0x333d00 */

int speex_mode_query(const SpeexMode *mode, int request, unsigned int *ptr)
{
    return mode->query(mode->mode, request, ptr);
}

