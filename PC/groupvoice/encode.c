/* ASM dump from: encode.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/groupvoice/encode.cpp */

#include "common_types.h"
#include "imports.h"

extern int g_encoder_quality; /* 0x0 */
extern int g_encoder_samplerate; /* 0x0 */
extern int g_current_bandwidth_setting; /* 0x0 */
extern int g_frame_size; /* 0x0 */
extern int g_speex_initialized; /* 0x0 */
static void *g_encoder; /* 0xff21a4 */
static struct SpeexBits encodeBits; /* 0xff2180 */

void Encode_SetOptions(int frequency, int quality);
Bool Encode_Init(int bandwidthEnum);
Bool Encode_Shutdown(void);
int Encode_Sample(short int *buffer_in, char *buffer_out, int maxLength);
int Encode_GetFrameSize(void);

/* line 42 */
__attribute__((naked))
void Encode_SetOptions(int frequency, int quality)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 42 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "movb $1, -9(%ebp)\n" /* line 44 | yes */
        "leal 8(%ebp), %eax\n" /* line 46 | frequency */
        "movl %eax, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl g_encoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "leal 0xc(%ebp), %eax\n" /* line 47 | quality */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl g_encoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl $g_frame_size, 8(%esp)\n" /* line 49 */
        "movl $3, 4(%esp)\n"
        "movl g_encoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "leal -9(%ebp), %ebx\n" /* line 51 | yes */
        "movl %ebx, 8(%esp)\n"
        "movl $0x1e, 4(%esp)\n"
        "movl g_encoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl %ebx, 8(%esp)\n" /* line 52 */
        "movl $0x22, 4(%esp)\n"
        "movl g_encoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl 0xc(%ebp), %eax\n" /* line 54 | quality */
        "movl %eax, g_encoder_quality\n"
        "movl 8(%ebp), %eax\n" /* line 55 | frequency */
        "movl %eax, g_encoder_samplerate\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 56 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 58 */
__attribute__((naked))
Bool Encode_Init(int bandwidthEnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 58 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* bandwidthEnum */
        /* { scope 1 */
        "cmpl $1, %ebx\n" /* line 62 | bandwidthEnum */
        "je .Lf1e8434_001e84df\n"
        "cmpl $2, %ebx\n" /* bandwidthEnum */
        "je .Lf1e8434_001e84e9\n"
        "testl %ebx, %ebx\n" /* bandwidthEnum */
        "jne .Lf1e8434_001e84c7\n"
        "movl 0x195f99c, %eax\n"
        ".Lf1e8434_001e8459:\n"
        "movl %eax, (%esp)\n" /* line 77 */
        "calll speex_encoder_init\n"
        "movl %eax, g_encoder\n"
        "movl $encodeBits, (%esp)\n" /* line 79 */
        "calll speex_bits_init\n"
        "movl $1, g_speex_initialized\n" /* line 80 */
        "movl g_encoder_quality, %eax\n" /* line 82 */
        "movl %eax, 4(%esp)\n"
        "movl g_encoder_samplerate, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Encode_SetOptions\n"
        "movl $g_frame_size, 8(%esp)\n" /* line 84 */
        "movl $3, 4(%esp)\n"
        "movl g_encoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl %ebx, g_current_bandwidth_setting\n" /* line 86 | bandwidthEnum */
        "xorl %eax, %eax\n" /* line 88 */
        "cmpl $0, g_encoder\n"
        "setne %al\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 89 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e8434_001e84c7:\n"
        "movl %ebx, 4(%esp)\n" /* line 74 | bandwidthEnum */
        "movl $0x2b8f10, (%esp)\n" /* "Unknown bandwidth mode %i
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 89 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e8434_001e84df:\n"
        "movl 0x195f998, %eax\n" /* line 66 */
        "jmp .Lf1e8434_001e8459\n"
        ".Lf1e8434_001e84e9:\n"
        "movl 0x195f9a4, %eax\n" /* line 75 */
        "jmp .Lf1e8434_001e8459\n"
    );
}

/* line 91 */
__attribute__((naked))
Bool Encode_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 91 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl g_encoder, %eax\n" /* line 93 */
        "testl %eax, %eax\n"
        "je .Lf1e84f4_001e850b\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll speex_encoder_destroy\n"
        ".Lf1e84f4_001e850b:\n"
        "movl $0, g_encoder\n" /* line 96 */
        "movl g_speex_initialized, %eax\n" /* line 98 */
        "testl %eax, %eax\n"
        "je .Lf1e84f4_001e8534\n"
        "movl $encodeBits, (%esp)\n" /* line 100 */
        "calll speex_bits_destroy\n"
        "movl $0, g_speex_initialized\n" /* line 101 */
        ".Lf1e84f4_001e8534:\n"
        "movl $1, %eax\n" /* line 105 */
        "leave\n"
        "retl\n"
    );
}

/* line 112 */
__attribute__((naked))
int Encode_Sample(short int *buffer_in, char *buffer_out, int maxLength)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 112 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* buffer_in */
        "movl 0xc(%ebp), %edi\n" /* buffer_out */
        "movl 0x10(%ebp), %esi\n" /* maxLength */
        "movl 0x195f2d0, %eax\n" /* line 117 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl g_encoder_quality, %eax\n"
        "je .Lf1e853e_001e8584\n"
        "movl %eax, g_encoder_quality\n" /* line 119 */
        "movl $g_encoder_quality, 8(%esp)\n" /* line 120 */
        "movl $4, 4(%esp)\n"
        "movl g_encoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        ".Lf1e853e_001e8584:\n"
        "movl $encodeBits, (%esp)\n" /* line 123 */
        "calll speex_bits_reset\n"
        "movl $encodeBits, 8(%esp)\n" /* line 125 */
        "movl %ebx, 4(%esp)\n" /* buffer_in */
        "movl g_encoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encode_int\n"
        "movl %esi, 0x10(%ebp)\n" /* line 127 | maxLength */
        "movl %edi, 0xc(%ebp)\n" /* buffer_out */
        "movl $encodeBits, 8(%ebp)\n" /* buffer_in */
        "addl $0x1c, %esp\n" /* line 130 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp speex_bits_write\n" /* line 127 */
    );
}

/* line 132 */
__attribute__((naked))
int Encode_GetFrameSize(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 132 */
        "movl %esp, %ebp\n"
        "movl g_frame_size, %eax\n"
        "popl %ebp\n" /* line 135 */
        "retl\n"
    );
}

