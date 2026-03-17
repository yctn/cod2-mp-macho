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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
sample_t * DSound_NewSample(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 47 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "cmpb $0, dsoundplay_initialized\n" /* line 49 */
        "jne .Lf1f60a6_001f60c2\n"
        ".Lf1f60a6_001f60b7:\n"
        "xorl %ebx, %ebx\n" /* line 72 | sample */
        /* } scope */
        ".Lf1f60a6_001f60b9:\n"
        "movl %ebx, %eax\n" /* line 73 | sample */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f60a6_001f60c2:\n"
        "calll DSOUNDRecord_NewSample\n" /* line 52 */
        "movl %eax, %ebx\n" /* sample */
        "testl %eax, %eax\n" /* line 53 */
        "je .Lf1f60a6_001f60b7\n"
        "movl $0x4d444449, (%esp)\n" /* line 58 */
        "calll AIL_allocate_sample_handle\n"
        "movl %eax, (%ebx)\n" /* sample */
        "testl %eax, %eax\n" /* line 59 */
        "je .Lf1f60a6_001f60b7\n"
        "movl $0x14, (%esp)\n" /* line 65 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl $0xc800, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_CCircularBuffer\n"
        "movl %esi, 4(%ebx)\n" /* sample */
        "movl (%ebx), %eax\n" /* line 67 | sample */
        "movl %eax, (%esp)\n"
        "calll AIL_init_sample\n"
        "movl 8(%ebx), %eax\n" /* line 68 | sample */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* sample */
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_playback_rate\n"
        "xorl %eax, %eax\n" /* line 69 */
        "cmpl $1, 0x14(%ebx)\n" /* sample */
        "setne %al\n"
        "leal 1(%eax, %eax), %eax\n"
        "movl $0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* sample */
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_type\n"
        "jmp .Lf1f60a6_001f60b9\n"
        "movl %eax, %ebx\n" /* sample */
        "movl %esi, (%esp)\n" /* line 65 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n" /* sample */
        "calll __Unwind_Resume\n"
    );
}

/* line 77 — C replacement from snd_mac.c */
int DSound_Init(void)
{
    if (!dsoundplay_initialized)
        dsoundplay_initialized = 1;
    return 1;
}

/* line 91 — C replacement from snd_mac.c */
void DSound_Shutdown(void)
{
    dsoundplay_initialized = 0;
}

/* line 103 — C replacement from snd_mac.c */
void DSound_Frame(void)
{
    /* empty */
}

/* line 110 */
__attribute__((naked))
void DSound_SampleFrame(sample_t *sample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 110 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* sample */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 114 | sample, status */
        "movl %eax, (%esp)\n" /* status */
        "calll AIL_sample_status\n"
        "cmpl $2, %eax\n" /* line 115 */
        "je .Lf1f618e_001f61ad\n"
        /* } scope */
        ".Lf1f618e_001f61a7:\n"
        "addl $0x24, %esp\n" /* line 138 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f618e_001f61ad:\n"
        "movl 4(%ebx), %eax\n" /* line 122 | sample */
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_ReadPtrSize\n"
        "movl %eax, -0xc(%ebp)\n" /* size */
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf1f618e_001f61a7\n"
        "leal -0xc(%ebp), %eax\n" /* line 128 | size */
        "movl %eax, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* sample */
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_ReadPtr\n"
        "movl %eax, %edx\n" /* ptr */
        "testl %eax, %eax\n" /* line 129 */
        "je .Lf1f618e_001f61a7\n"
        "movl -0xc(%ebp), %eax\n" /* line 136 | size */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* sample */
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_address\n"
        "movl (%ebx), %eax\n" /* line 137 | sample */
        "movl %eax, (%esp)\n"
        "calll AIL_resume_sample\n"
        "jmp .Lf1f618e_001f61a7\n"
    );
}
#else
sample_t * DSound_NewSample(void) { return 0; }
#endif
