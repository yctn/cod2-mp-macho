/* ASM dump from: speex.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/speex.c */

#include "common_types.h"
#include "imports.h"

float * speex_encoder_init(const SpeexMode *mode);
float * speex_decoder_init(const SpeexMode *mode);
float speex_encoder_destroy(float *state);
float speex_decoder_destroy(float *state);
int speex_encode_native(float *state, spx_word16_t *in, SpeexBits *bits);
int speex_decode_native(float *state, SpeexBits *bits, spx_word16_t *out);
int speex_encoder_ctl(float *state, int request, float *ptr);
int speex_decode(float *state, SpeexBits *bits, float *out);
int speex_decoder_ctl(float *state, int request, float *ptr);
int nb_mode_query(const float *mode, int request, float *ptr);
int wb_mode_query(const float *mode, int request, float *ptr);
int speex_encode_int(float *state, const SpeexMode (*in)[4], SpeexBits *bits);

/* line 50 */
float * speex_encoder_init(const SpeexMode *mode)
{
    return ((float *(*)(const SpeexMode *))*(void **)((char *)mode + 0x14))(mode);
}

/* line 55 */
float * speex_decoder_init(const SpeexMode *mode)
{
    return ((float *(*)(const SpeexMode *))*(void **)((char *)mode + 0x20))(mode);
}

/* line 60 */
float speex_encoder_destroy(float *state)
{
    return ((float (*)(float *))*(void **)((char *)*(void **)state + 0x18))(state);
}

/* line 65 */
float speex_decoder_destroy(float *state)
{
    return ((float (*)(float *))*(void **)((char *)*(void **)state + 0x24))(state);
}

/* line 72 */
int speex_encode_native(float *state, spx_word16_t *in, SpeexBits *bits)
{
    return ((int (*)(float *, spx_word16_t *, SpeexBits *))*(void **)((char *)*(void **)state + 0x1c))(state, in, bits);
}

/* line 77 */
int speex_decode_native(float *state, SpeexBits *bits, spx_word16_t *out)
{
    return ((int (*)(float *, SpeexBits *, spx_word16_t *))*(void **)((char *)*(void **)state + 0x28))(state, bits, out);
}

/* line 175 */
int speex_encoder_ctl(float *state, int request, float *ptr)
{
    return ((int (*)(float *, int, float *))*(void **)((char *)*(void **)state + 0x2c))(state, request, ptr);
}

/* line 147 */
int speex_decode(float *state, SpeexBits *bits, float *out)
{
    return ((int (*)(float *, SpeexBits *, float *))*(void **)((char *)*(void **)state + 0x28))(state, bits, out);
}

/* line 180 */
int speex_decoder_ctl(float *state, int request, float *ptr)
{
    return ((int (*)(float *, int, float *))*(void **)((char *)*(void **)state + 0x30))(state, request, ptr);
}

/* line 187 */
__attribute__((naked))
int nb_mode_query(const float *mode, int request, float *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 187 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* request */
        "testl %eax, %eax\n" /* line 191 */
        "je .Lf1e8648_001e8671\n"
        "cmpl $1, %eax\n"
        "je .Lf1e8648_001e867f\n"
        "movl %eax, 4(%esp)\n" /* line 205 */
        "movl $0x2b8f2c, (%esp)\n" /* "Unknown nb_mode_query request: " */
        "calll speex_warning_int\n"
        "movl $0xffffffff, %eax\n"
        "leave\n" /* line 209 */
        "retl\n"
        ".Lf1e8648_001e8671:\n"
        "movl 8(%ebp), %edx\n" /* line 194 | mode */
        "movl (%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 209 */
        "retl\n"
        ".Lf1e8648_001e867f:\n"
        "movl 0x10(%ebp), %edx\n" /* line 197 | ptr */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1e8648_001e8690\n"
        "movl $5, (%edx)\n" /* line 198 */
        "leave\n" /* line 209 */
        "retl\n"
        ".Lf1e8648_001e8690:\n"
        "movl 8(%ebp), %edx\n" /* line 199 | mode */
        "movl 0x24(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e8648_001e86a7\n"
        "movl 0x40(%eax), %eax\n" /* line 202 */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 209 */
        "retl\n"
        ".Lf1e8648_001e86a7:\n"
        "movl 0x10(%ebp), %eax\n" /* line 200 | ptr */
        "movl $0xffffffff, (%eax)\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 209 */
        "retl\n"
    );
}

/* line 211 */
__attribute__((naked))
int wb_mode_query(const float *mode, int request, float *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 211 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* request */
        "testl %eax, %eax\n" /* line 215 */
        "je .Lf1e86b4_001e86dd\n"
        "cmpl $1, %eax\n"
        "je .Lf1e86b4_001e86ee\n"
        "movl %eax, 4(%esp)\n" /* line 229 */
        "movl $0x2b8f4c, (%esp)\n" /* "Unknown wb_mode_query request: " */
        "calll speex_warning_int\n"
        "movl $0xffffffff, %eax\n"
        "leave\n" /* line 233 */
        "retl\n"
        ".Lf1e86b4_001e86dd:\n"
        "movl 8(%ebp), %edx\n" /* line 218 | mode */
        "movl 4(%edx), %eax\n"
        "addl %eax, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 233 */
        "retl\n"
        ".Lf1e86b4_001e86ee:\n"
        "movl 0x10(%ebp), %edx\n" /* line 221 | ptr */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1e86b4_001e86ff\n"
        "movl $4, (%edx)\n" /* line 222 */
        "leave\n" /* line 233 */
        "retl\n"
        ".Lf1e86b4_001e86ff:\n"
        "movl 8(%ebp), %edx\n" /* line 223 | mode */
        "movl 0x28(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e86b4_001e8716\n"
        "movl 0x40(%eax), %eax\n" /* line 226 */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 233 */
        "retl\n"
        ".Lf1e86b4_001e8716:\n"
        "movl 0x10(%ebp), %eax\n" /* line 224 | ptr */
        "movl $0xffffffff, (%eax)\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 233 */
        "retl\n"
    );
}

/* line 136 */
__attribute__((naked))
int speex_encode_int(float *state, const SpeexMode (*in)[4], SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 136 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xa20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* state */
        "movl 0xc(%ebp), %esi\n" /* in */
        /* { scope 1 */
        "movl (%ebx), %edx\n" /* line 177 | state */
        "leal -0xc(%ebp), %eax\n" /* N */
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll *0x2c(%edx)\n"
        "movl -0xc(%ebp), %ecx\n" /* line 142 | N */
        "testl %ecx, %ecx\n"
        "jle .Lf1e8726_001e876f\n"
        "xorl %edx, %edx\n"
        ".Lf1e8726_001e8757:\n"
        "movswl (%esi, %edx, 2), %eax\n" /* line 143 | in */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0xa0c(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 142 */
        "cmpl %edx, %ecx\n"
        "jne .Lf1e8726_001e8757\n"
        ".Lf1e8726_001e876f:\n"
        "movl (%ebx), %edx\n" /* line 144 | state */
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, 8(%esp)\n"
        "leal -0xa0c(%ebp), %eax\n" /* float_in */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "calll *0x1c(%edx)\n"
        /* } scope */
        "addl $0xa20, %esp\n" /* line 145 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

