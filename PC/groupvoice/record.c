/* ASM dump from: record.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/groupvoice/record.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern char enc_buffer[4096]; /* 0x0 */
extern int enc_buffer_pos; /* 0x0 */
extern short int partial_audio_buffer[640]; /* 0x0 */
extern int samples_in_partial_audio_buffer; /* 0x0 */

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
__attribute__((naked))
int Record_Start(recordingSample_t *sample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 159 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 168 */
        "jmp DSOUNDRecord_Start\n" /* line 166 */
    );
}

/* line 170 */
__attribute__((naked))
int Record_Stop(recordingSample_t *sample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 170 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 179 */
        "jmp DSOUNDRecord_Stop\n" /* line 177 */
    );
}

/* line 181 */
__attribute__((naked))
recordingSample_t * Record_NewSample(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 181 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 190 */
        "jmp DSOUNDRecord_NewSample\n" /* line 188 */
    );
}

/* line 192 */
__attribute__((naked))
int Record_DestroySample(recordingSample_t *sample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 192 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 201 */
        "jmp DSOUNDRecord_DestroySample\n" /* line 199 */
    );
}

/* line 203 */
__attribute__((naked))
void Record_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 203 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll Encode_Shutdown\n" /* line 205 */
        "leave\n" /* line 218 */
        "jmp DSOUNDRecord_Shutdown\n" /* line 216 */
    );
}

/* line 220 */
__attribute__((naked))
void Record_Frame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 229 */
        "jmp DSOUNDRecord_Frame\n" /* line 227 */
    );
}

/* line 46 */
__attribute__((naked))
int Record_QueueAudioDataForEncoding(audioSample_t *sample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 46 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        "movl 8(%ebp), %esi\n" /* sample */
        /* { scope 1 */
        "movl 0x195f990, %edi\n" /* line 53 | encode_frame_size */
        "movl $0, (%edi)\n" /* encode_frame_size */
        "cmpl $2, 0xc(%esi)\n" /* line 54 | sample */
        "je .Lf1e7f60_001e7fce\n"
        ".Lf1e7f60_001e7f81:\n"
        "calll Voice_SendVoiceData\n" /* line 70 */
        "testb %al, %al\n"
        "jne .Lf1e7f60_001e7fa5\n"
        ".Lf1e7f60_001e7f8a:\n"
        "movl $0, -0x201c(%ebp)\n" /* line 98 | total_bytes */
        /* } scope */
        ".Lf1e7f60_001e7f94:\n"
        "movl -0x201c(%ebp), %eax\n" /* line 152 | total_bytes */
        "addl $0x202c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e7f60_001e7fa5:\n"
        "calll IsTalking\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf1e7f60_001e8027\n"
        "calll CL_VoiceTransmit\n" /* line 77 */
        "movl $0, -0x201c(%ebp)\n" /* total_bytes */
        /* } scope */
        "movl -0x201c(%ebp), %eax\n" /* line 152 | total_bytes */
        "addl $0x202c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e7f60_001e7fce:\n"
        "movl 8(%esi), %edx\n" /* line 54 | sample */
        "testl %edx, %edx\n"
        "jle .Lf1e7f60_001e7f81\n"
        "xorl %ebx, %ebx\n" /* ii */
        ".Lf1e7f60_001e7fd7:\n"
        "movl (%esi), %ecx\n" /* line 59 | sample */
        "leal (%ebx, %ebx), %edx\n" /* ii */
        "movswl (%ecx, %edx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0x195f98c, %eax\n"
        "mulss (%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movw %ax, (%ecx, %edx)\n" /* line 60 */
        "cwtl\n" /* line 61 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss (%edi), %xmm1\n" /* encode_frame_size */
        "movss %xmm1, (%edi)\n" /* encode_frame_size */
        "addl $1, %ebx\n" /* line 56 | ii */
        "movl 8(%esi), %eax\n" /* sample */
        "cmpl %eax, %ebx\n" /* ii */
        "jl .Lf1e7f60_001e7fd7\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 67 */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, (%edi)\n" /* encode_frame_size */
        "jmp .Lf1e7f60_001e7f81\n"
        ".Lf1e7f60_001e8027:\n"
        "calll Encode_GetFrameSize\n" /* line 81 */
        "movl %eax, %edi\n" /* encode_frame_size */
        "movl $0, 0x1c(%esi)\n" /* line 85 | sample */
        "testl %eax, %eax\n" /* line 90 */
        "jle .Lf1e7f60_001e81b2\n"
        "movl 4(%esi), %eax\n" /* line 96 | sample */
        "testl %eax, %eax\n"
        "jle .Lf1e7f60_001e819a\n"
        "movl 8(%esi), %ecx\n" /* line 108 | sample */
        "movl samples_in_partial_audio_buffer, %edx\n"
        "leal (%ecx, %edx), %eax\n"
        "cmpl %eax, %edi\n" /* encode_frame_size */
        "jle .Lf1e7f60_001e80a1\n"
        "movl $0, -0x201c(%ebp)\n" /* total_bytes */
        "xorl %ebx, %ebx\n" /* ii */
        ".Lf1e7f60_001e8064:\n"
        "cmpl %ebx, %ecx\n" /* line 142 | ii */
        "jle .Lf1e7f60_001e7f94\n"
        "movl 0xc(%esi), %eax\n" /* line 146 | sample */
        "leal partial_audio_buffer(%edx, %edx), %edx\n"
        "subl %ebx, %ecx\n" /* ii */
        "imull %eax, %ecx\n"
        "imull %ebx, %eax\n" /* ii */
        "addl (%esi), %eax\n" /* sample */
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%esi), %eax\n" /* line 147 | sample */
        "subl 0x1c(%esi), %eax\n" /* sample */
        "addl %eax, samples_in_partial_audio_buffer\n"
        "jmp .Lf1e7f60_001e7f94\n"
        ".Lf1e7f60_001e80a1:\n"
        "movl $0, -0x201c(%ebp)\n" /* line 108 | total_bytes */
        ".Lf1e7f60_001e80ab:\n"
        "testl %edx, %edx\n" /* line 112 */
        "je .Lf1e7f60_001e8108\n"
        "cvtsi2ssl %edx, %xmm2\n" /* line 116 */
        "leal -4(%edi), %eax\n" /* encode_frame_size */
        "cvtsi2ssl %eax, %xmm1\n"
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm3\n"
        "cmpltss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        /* } scope */
        "cvttss2si %xmm0, %ebx\n" /* line 116 | ii */
        "movl %ebx, samples_in_partial_audio_buffer\n" /* line 117 | ii */
        "movl %ebx, %eax\n" /* line 125 | ii */
        "imull 0xc(%esi), %eax\n" /* sample */
        "movl %eax, 8(%esp)\n"
        "movl $partial_audio_buffer, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* audio_buffer */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "subl %ebx, samples_in_partial_audio_buffer\n" /* line 127 | ii */
        "movl %ebx, %edx\n" /* ii */
        ".Lf1e7f60_001e8108:\n"
        "movl %edi, %ebx\n" /* line 130 | encode_frame_size, ii */
        "subl %edx, %ebx\n" /* ii */
        "movl 0xc(%esi), %eax\n" /* sample */
        "leal -0x2018(%ebp, %edx, 2), %ecx\n"
        "movl %ebx, %edx\n" /* ii */
        "imull %eax, %edx\n"
        "imull 0x1c(%esi), %eax\n" /* sample */
        "addl (%esi), %eax\n" /* sample */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "addl %ebx, 0x1c(%esi)\n" /* line 131 | ii, sample */
        "movl enc_buffer_pos, %edx\n" /* line 134 */
        "movl $__mh_execute_header, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "addl $enc_buffer, %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* audio_buffer */
        "movl %eax, (%esp)\n"
        "calll Encode_Sample\n"
        "addl %eax, -0x201c(%ebp)\n" /* line 136 | total_bytes */
        "movl enc_buffer_pos, %edx\n" /* line 138 */
        "addl $enc_buffer, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Client_SendVoiceData\n"
        "movl 8(%esi), %ecx\n" /* line 108 | sample */
        "movl 0x1c(%esi), %ebx\n" /* sample, ii */
        "movl samples_in_partial_audio_buffer, %edx\n"
        "movl %ecx, %eax\n"
        "subl %ebx, %eax\n" /* ii */
        "addl %edx, %eax\n"
        "cmpl %eax, %edi\n" /* encode_frame_size */
        "jle .Lf1e7f60_001e80ab\n"
        "jmp .Lf1e7f60_001e8064\n"
        ".Lf1e7f60_001e819a:\n"
        "movl 8(%esi), %eax\n" /* line 98 | sample */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8ee8, (%esp)\n" /* "Invalid sample length of %i samples
" */
        "calll Com_Printf\n"
        "jmp .Lf1e7f60_001e7f8a\n"
        ".Lf1e7f60_001e81b2:\n"
        "movl %eax, 4(%esp)\n" /* line 92 */
        "movl $0x2b8ec4, (%esp)\n" /* "Invalid encode frame size of %i
" */
        "calll Com_Printf\n"
        "movl $0, -0x201c(%ebp)\n" /* total_bytes */
        "jmp .Lf1e7f60_001e7f94\n"
    );
}

/* line 154 */
__attribute__((naked))
int Record_AudioCallback(audioSample_t *sample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 157 */
        "jmp Record_QueueAudioDataForEncoding\n" /* line 156 */
    );
}

/* line 231 */
__attribute__((naked))
int Record_Init(int callInit, const void *handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 231 */
        "movl %esp, %ebp\n"
        "movl 0x195f994, %eax\n" /* line 43 */
        "movl $Record_AudioCallback, (%eax)\n"
        "movl $1, 8(%ebp)\n" /* line 241 | callInit */
        "popl %ebp\n" /* line 243 */
        "jmp DSOUNDRecord_Init\n" /* line 241 */
    );
}

