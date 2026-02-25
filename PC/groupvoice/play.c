/* ASM dump from: play.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/groupvoice/play.cpp */

#include "common_types.h"
#include "imports.h"

int Sound_UpdateSample(sample_t *sample, char *data, unsigned int data_len);
sample_t * Sound_NewSample(void);
int Sound_DestroySample(sample_t *sample);
unsigned char Sound_Frame(void);
unsigned char Sound_SampleFrame(sample_t *sample);
int Sound_Init(const unsigned char *handle);
unsigned char Sound_Shutdown(void);

/* line 16 */
__attribute__((naked))
int Sound_UpdateSample(sample_t *sample, char *data, unsigned int data_len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 16 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 25 */
        "jmp DSound_UpdateSample\n" /* line 23 */
    );
}

/* line 27 */
__attribute__((naked))
sample_t * Sound_NewSample(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 36 */
        "jmp DSound_NewSample\n" /* line 34 */
    );
}

/* line 38 */
__attribute__((naked))
int Sound_DestroySample(sample_t *sample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 41 */
        "jmp Record_DestroySample\n" /* line 40 */
    );
}

/* line 88 */
__attribute__((naked))
unsigned char Sound_Frame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 97 */
        "jmp DSound_Frame\n" /* line 95 */
    );
}

/* line 112 */
__attribute__((naked))
unsigned char Sound_SampleFrame(sample_t *sample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 112 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 121 */
        "jmp DSound_SampleFrame\n" /* line 119 */
    );
}

/* line 124 */
__attribute__((naked))
int Sound_Init(const unsigned char *handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 124 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 127 | handle */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll DSound_Init\n"
        "leave\n" /* line 129 */
        "retl\n"
    );
}

/* line 131 */
__attribute__((naked))
unsigned char Sound_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 140 */
        "jmp DSound_Shutdown\n" /* line 138 */
    );
}

