/* ASM dump from: decode.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/groupvoice/decode.cpp */

#include "common_types.h"
#include "imports.h"

extern void *g_decoder; /* 0x0 */
extern int g_current_decode_bandwidth_setting; /* 0x0 */
extern int g_decode_frame_size; /* 0x0 */
static struct SpeexBits decodeBits; /* 0xff2100 */

Bool Decode_Init(int bandwidthEnum);
void Decode_Shutdown(void);
int Decode_Sample(char *buffer, int maxLength, short int *out, int frame_size);

/* line 28 */
__attribute__((naked))
Bool Decode_Init(int bandwidthEnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* bandwidthEnum */
        /* { scope 1 */
        "movl $1, -0xc(%ebp)\n" /* line 31 | tmp */
        "cmpl $1, %ebx\n" /* line 33 | bandwidthEnum */
        "je .Lf1e81f8_001e82bc\n"
        "cmpl $2, %ebx\n" /* bandwidthEnum */
        "je .Lf1e81f8_001e82c6\n"
        "testl %ebx, %ebx\n" /* bandwidthEnum */
        "jne .Lf1e81f8_001e82a4\n"
        "movl 0x195f99c, %eax\n"
        ".Lf1e81f8_001e8228:\n"
        "movl %eax, (%esp)\n" /* line 49 */
        "calll speex_decoder_init\n"
        "movl %eax, g_decoder\n"
        "leal -0xc(%ebp), %edx\n" /* line 50 | tmp */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "movl 0x195f9a0, %eax\n" /* line 51 */
        "movl %eax, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl g_decoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "movl $g_decode_frame_size, 8(%esp)\n" /* line 52 */
        "movl $3, 4(%esp)\n"
        "movl g_decoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl %ebx, g_current_decode_bandwidth_setting\n" /* line 54 | bandwidthEnum */
        "movl $decodeBits, (%esp)\n" /* line 56 */
        "calll speex_bits_init\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 59 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e81f8_001e82a4:\n"
        "movl %ebx, 4(%esp)\n" /* line 45 | bandwidthEnum */
        "movl $0x2b8f10, (%esp)\n" /* "Unknown bandwidth mode %i
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 59 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e81f8_001e82bc:\n"
        "movl 0x195f998, %eax\n" /* line 37 */
        "jmp .Lf1e81f8_001e8228\n"
        ".Lf1e81f8_001e82c6:\n"
        "movl 0x195f9a4, %eax\n" /* line 46 */
        "jmp .Lf1e81f8_001e8228\n"
    );
}

/* line 61 */
__attribute__((naked))
void Decode_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 61 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl g_decoder, %eax\n" /* line 63 */
        "testl %eax, %eax\n"
        "je .Lf1e82d0_001e82f8\n"
        "movl $decodeBits, (%esp)\n" /* line 65 */
        "calll speex_bits_destroy\n"
        "movl g_decoder, %eax\n" /* line 66 */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_destroy\n"
        ".Lf1e82d0_001e82f8:\n"
        "movl $0, g_decoder\n" /* line 68 */
        "leave\n" /* line 69 */
        "retl\n"
    );
}

/* line 80 */
__attribute__((naked))
int Decode_Sample(char *buffer, int maxLength, short int *out, int frame_size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 80 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x4014, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* out */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 89 | maxLength */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl %eax, 4(%esp)\n"
        "movl $decodeBits, (%esp)\n"
        "calll speex_bits_read_from\n"
        "leal -0x4008(%ebp), %eax\n" /* line 91 | output */
        "movl %eax, 8(%esp)\n"
        "movl $decodeBits, 4(%esp)\n"
        "movl g_decoder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_decode\n"
        "testl %eax, %eax\n"
        "je .Lf1e8304_001e835b\n"
        "xorl %ecx, %ecx\n"
        /* } scope */
        ".Lf1e8304_001e8350:\n"
        "movl %ecx, %eax\n" /* line 103 */
        "addl $0x4014, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e8304_001e835b:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 94 | frame_size */
        "addl %ecx, %ecx\n"
        "testl %ecx, %ecx\n" /* line 97 */
        "jle .Lf1e8304_001e8350\n"
        "xorl %edx, %edx\n"
        ".Lf1e8304_001e8366:\n"
        "cvttss2si -0x4008(%ebp, %edx, 4), %eax\n" /* line 98 */
        "movw %ax, (%ebx, %edx, 2)\n" /* out */
        "addl $1, %edx\n" /* line 97 */
        "cmpl %ecx, %edx\n"
        "jne .Lf1e8304_001e8366\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 103 */
        "addl $0x4014, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

