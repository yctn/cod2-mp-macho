/* ASM dump from: mac_play_dsound.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_play_dsound.cpp */

#include "common_types.h"
#include "imports.h"

static Bool dsoundplay_initialized; /* 0xff2b80 */

int DSound_UpdateSample(sample_t *sample, char *data, unsigned int data_len);
sample_t * DSound_NewSample(void);
int DSound_Init(void);
void DSound_Shutdown(void);
void DSound_Frame(void);
void DSound_SampleFrame(sample_t *sample);

/* line 27 */
__attribute__((naked))
int DSound_UpdateSample(sample_t *sample, char *data, unsigned int data_len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* data_len */
        /* { scope 1 */
        "cmpb $0, dsoundplay_initialized\n" /* line 29 */
        "je .Lf1f6054_001f609a\n"
        "testl %ebx, %ebx\n" /* line 32 | data_len */
        "jne .Lf1f6054_001f6073\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 43 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f6054_001f6073:\n"
        "movl %ebx, -0xc(%ebp)\n" /* line 38 | data_len, size */
        "leal -0xc(%ebp), %eax\n" /* line 39 | size */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* sample */
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CCircularBuffer_Write\n"
        "movl %ebx, %eax\n" /* line 42 | data_len */
        /* } scope */
        "addl $0x24, %esp\n" /* line 43 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f6054_001f609a:\n"
        "movl $0xffffffff, %eax\n" /* line 29 */
        /* } scope */
        "addl $0x24, %esp\n" /* line 43 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 47 */
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

/* line 77 */
__attribute__((naked))
int DSound_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n" /* line 84 */
        "cmpb $0, dsoundplay_initialized\n"
        "movzbl dsoundplay_initialized, %edx\n"
        "cmovnel %edx, %eax\n"
        "movb %al, dsoundplay_initialized\n"
        "movl $1, %eax\n" /* line 87 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 91 */
__attribute__((naked))
void DSound_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 91 */
        "movl %esp, %ebp\n"
        "movb $0, dsoundplay_initialized\n" /* line 98 */
        "popl %ebp\n" /* line 99 */
        "retl\n"
    );
}

/* line 103 */
__attribute__((naked))
void DSound_Frame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 103 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 106 */
        "retl\n"
    );
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

