/* ASM dump from: mac_record_dsound.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_record_dsound.cpp */

#include "common_types.h"
#include "imports.h"

extern int g_sound_recordFrequency; /* 0x0 */
extern int g_sound_recordVolume; /* 0x0 */
extern int g_sound_channels; /* 0x0 */
extern Bool g_recording_initialized; /* 0x0 */
extern Bool g_currently_recording; /* 0x0 */
extern int (*current_audioCallback)(); /* 0x0 */
static recordingSample_t s_recordingSamples[65]; /* 0xff2220 */
static recordingSample_t *s_recordingSamplePtr; /* 0xff2b44 */
static recordingSample_t *g_current_sample; /* 0xff2204 */
static CAudioRecorder *sAudioRecorder; /* 0xff2200 */

int DSOUNDRecord_Start(recordingSample_t *pRecSample);
int DSOUNDRecord_Stop(recordingSample_t *pRecSample);
recordingSample_t * DSOUNDRecord_NewSample(void);
int DSOUNDRecord_DestroySample(recordingSample_t *pRecSample);
int DSOUNDRecord_Init(void);
void DSOUNDRecord_Shutdown(void);
void DSOUNDRecord_Frame(void);
int mixerSetRecordLevel(char *SrcName, int newLevel);
int mixerGetRecordLevel(char *SrcName);
int mixerGetRecordSource(char *srcName);
int mixerSetRecordSource(char *SrcName);
int mixerSetMicrophoneMute(int bMute);

/* line 43 */
__attribute__((naked))
int DSOUNDRecord_Start(recordingSample_t *pRecSample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpb $0, g_recording_initialized\n" /* line 45 */
        "jne .Lf1f5d18_001f5d2e\n"
        ".Lf1f5d18_001f5d27:\n"
        "movl $0xffffffff, %eax\n" /* line 56 */
        ".Lf1f5d18_001f5d2c:\n"
        "leave\n" /* line 63 */
        "retl\n"
        ".Lf1f5d18_001f5d2e:\n"
        "movl sAudioRecorder, %eax\n" /* line 47 */
        "testl %eax, %eax\n"
        "je .Lf1f5d18_001f5d27\n"
        "movl %eax, (%esp)\n" /* line 50 */
        "calll CAudioRecorder_Start\n"
        "testb %al, %al\n"
        "je .Lf1f5d18_001f5d56\n"
        "movl 8(%ebp), %eax\n" /* line 52 | pRecSample */
        "movl %eax, g_current_sample\n"
        "movb $1, g_currently_recording\n" /* line 60 */
        "xorl %eax, %eax\n"
        "leave\n" /* line 63 */
        "retl\n"
        ".Lf1f5d18_001f5d56:\n"
        "movl $str_002b920c, (%esp)\n" /* line 56 */
        "calll Com_Printf\n"
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1f5d18_001f5d2c\n"
    );
}

/* line 67 */
__attribute__((naked))
int DSOUNDRecord_Stop(recordingSample_t *pRecSample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 67 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpb $0, g_recording_initialized\n" /* line 69 */
        "jne .Lf1f5d6a_001f5d80\n"
        ".Lf1f5d6a_001f5d79:\n"
        "movl $0xffffffff, %eax\n" /* line 71 */
        "leave\n" /* line 80 */
        "retl\n"
        ".Lf1f5d6a_001f5d80:\n"
        "movl sAudioRecorder, %eax\n" /* line 71 */
        "testl %eax, %eax\n"
        "je .Lf1f5d6a_001f5d79\n"
        "movl %eax, (%esp)\n" /* line 74 */
        "calll CAudioRecorder_Stop\n"
        "movl $0, g_current_sample\n" /* line 76 */
        "movb $0, g_currently_recording\n" /* line 77 */
        "xorl %eax, %eax\n"
        "leave\n" /* line 80 */
        "retl\n"
    );
}

/* line 84 */
__attribute__((naked))
recordingSample_t * DSOUNDRecord_NewSample(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 84 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        /* { scope 1 */
        "cmpb $0, g_recording_initialized\n" /* line 88 */
        "jne .Lf1f5da6_001f5dba\n"
        "xorl %edx, %edx\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 104 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f5da6_001f5dba:\n"
        "movl s_recordingSamplePtr, %edx\n" /* line 92 */
        "leal 0x24(%edx), %eax\n" /* line 93 */
        "movl %eax, s_recordingSamplePtr\n"
        "cld\n" /* line 94 */
        "movl $9, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl g_sound_recordFrequency, %eax\n" /* line 96 */
        "movl %eax, 8(%edx)\n"
        "movl g_sound_recordVolume, %eax\n" /* line 97 */
        "movl %eax, 0xc(%edx)\n"
        "movl $0x80, 0x10(%edx)\n" /* line 98 */
        "movl g_sound_channels, %eax\n" /* line 99 */
        "movl %eax, 0x14(%edx)\n"
        "movb $2, 0x20(%edx)\n" /* line 101 */
        /* } scope */
        "movl %edx, %eax\n" /* line 104 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 108 */
__attribute__((naked))
int DSOUNDRecord_DestroySample(recordingSample_t *pRecSample)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 108 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "cmpb $0, g_recording_initialized\n"
        "setne %al\n"
        "popl %ebp\n" /* line 122 */
        "retl\n"
    );
}

/* line 126 */
__attribute__((naked))
int DSOUNDRecord_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 126 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0xff2220, s_recordingSamplePtr\n" /* line 128 */
        "movb $0, g_recording_initialized\n" /* line 130 */
        "movl $0x78, (%esp)\n" /* line 133 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl $0x10, 0x10(%esp)\n"
        "movl g_sound_channels, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "cvtsi2sdl g_sound_recordFrequency, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CAudioRecorder_CAudioRecorder\n"
        "movl %esi, sAudioRecorder\n"
        "movl %esi, (%esp)\n" /* line 134 */
        "calll CAudioRecorder_Initialize\n"
        "testb %al, %al\n"
        "jne .Lf1f5e0e_001f5e9b\n"
        "movl sAudioRecorder, %ebx\n" /* line 136 */
        "testl %ebx, %ebx\n"
        "je .Lf1f5e0e_001f5e88\n"
        "movl %ebx, (%esp)\n"
        "calll ZN14CAudioRecorderD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __ZdlPv\n"
        ".Lf1f5e0e_001f5e88:\n"
        "movl $0, sAudioRecorder\n" /* line 137 */
        "xorl %eax, %eax\n"
        "addl $0x20, %esp\n" /* line 146 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f5e0e_001f5e9b:\n"
        "movb $1, g_recording_initialized\n" /* line 144 */
        "movl $1, %eax\n"
        "addl $0x20, %esp\n" /* line 146 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 133 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 150 */
__attribute__((naked))
void DSOUNDRecord_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 150 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl sAudioRecorder, %eax\n" /* line 152 */
        "testl %eax, %eax\n"
        "je .Lf1f5ec0_001f5efc\n"
        "movl %eax, (%esp)\n" /* line 154 */
        "calll CAudioRecorder_Shutdown\n"
        "movl sAudioRecorder, %ebx\n" /* line 155 */
        "testl %ebx, %ebx\n"
        "je .Lf1f5ec0_001f5ef2\n"
        "movl %ebx, (%esp)\n"
        "calll ZN14CAudioRecorderD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __ZdlPv\n"
        ".Lf1f5ec0_001f5ef2:\n"
        "movl $0, sAudioRecorder\n" /* line 156 */
        ".Lf1f5ec0_001f5efc:\n"
        "movb $0, g_recording_initialized\n" /* line 159 */
        "addl $0x14, %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 190 */
__attribute__((naked))
void DSOUNDRecord_Frame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 190 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "cmpb $0, g_recording_initialized\n" /* line 192 */
        "je .Lf1f5f0a_001f5f4e\n"
        "cmpb $0, g_currently_recording\n" /* line 195 */
        "je .Lf1f5f0a_001f5f4e\n"
        "movl g_current_sample, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1f5f0a_001f5f4e\n"
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 168 | size */
        "movl %eax, 4(%esp)\n"
        "movl sAudioRecorder, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CAudioRecorder_GetBuffer\n"
        "movl %eax, %ebx\n" /* buffer */
        "testl %eax, %eax\n" /* line 169 */
        "je .Lf1f5f0a_001f5f4e\n"
        "movl -0xc(%ebp), %ecx\n" /* size */
        "testl %ecx, %ecx\n"
        "jne .Lf1f5f0a_001f5f55\n"
        /* } scope */
        ".Lf1f5f0a_001f5f4e:\n"
        "addl $0x40, %esp\n" /* line 199 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f5f0a_001f5f55:\n"
        "movl g_sound_channels, %edx\n" /* line 175 */
        "cmpl $1, %edx\n"
        "setg -0x18(%ebp)\n"
        "movl $2, -0x20(%ebp)\n" /* line 176 */
        "movl g_sound_recordFrequency, %eax\n" /* line 177 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x10(%ebp)\n" /* line 178 */
        "movl %edx, -0x14(%ebp)\n" /* line 179 */
        "addl %edx, %edx\n" /* line 181 */
        "movl %ecx, %eax\n"
        "movl %edx, %esi\n"
        "xorl %edx, %edx\n"
        "divl %esi\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %ecx, -0x28(%ebp)\n" /* line 182 */
        "movl %ebx, -0x2c(%ebp)\n" /* line 183 | buffer, audioSample */
        "leal -0x2c(%ebp), %eax\n" /* line 185 | audioSample */
        "movl %eax, (%esp)\n"
        "calll *current_audioCallback\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 199 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 205 */
__attribute__((naked))
int mixerSetRecordLevel(char *SrcName, int newLevel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 205 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* newLevel */
        "movl sAudioRecorder, %edx\n" /* line 209 */
        "testl %edx, %edx\n"
        "je .Lf1f5fa2_001f5fd2\n"
        "movzwl %ax, %eax\n" /* line 212 */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss 0x2ed84c, %xmm0\n" /* 65535.0f */
        "movss %xmm0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CAudioRecorder_SetRecordLevel\n"
        ".Lf1f5fa2_001f5fd2:\n"
        "xorl %eax, %eax\n" /* line 216 */
        "leave\n"
        "retl\n"
    );
}

/* line 220 */
__attribute__((naked))
int mixerGetRecordLevel(char *SrcName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl sAudioRecorder, %eax\n" /* line 222 */
        "testl %eax, %eax\n"
        "je .Lf1f5fd6_001f6003\n"
        "movl %eax, (%esp)\n" /* line 224 */
        "calll CAudioRecorder_GetRecordLevel\n"
        "fstps -0xc(%ebp)\n"
        "cvtss2sd -0xc(%ebp), %xmm0\n"
        "mulsd 0x307fc0, %xmm0\n" /* 65535.0 */
        "cvttsd2si %xmm0, %eax\n"
        "leave\n" /* line 230 */
        "retl\n"
        ".Lf1f5fd6_001f6003:\n"
        "movw $0xffff, %ax\n" /* line 222 */
        "leave\n" /* line 230 */
        "retl\n"
    );
}

/* line 234 */
__attribute__((naked))
int mixerGetRecordSource(char *srcName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 234 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 236 | srcName */
        "movl $0x63614d, (%eax)\n"
        "movl $1, %eax\n" /* line 238 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 242 */
__attribute__((naked))
int mixerSetRecordSource(char *SrcName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 242 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n" /* line 245 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 249 */
__attribute__((naked))
int mixerSetMicrophoneMute(int bMute)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movzbl 8(%ebp), %eax\n" /* bMute */
        "movl sAudioRecorder, %edx\n" /* line 251 */
        "testl %edx, %edx\n"
        "je .Lf1f6028_001f6050\n"
        "testb %al, %al\n" /* line 253 */
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CAudioRecorder_Mute\n"
        ".Lf1f6028_001f6050:\n"
        "xorl %eax, %eax\n" /* line 257 */
        "leave\n"
        "retl\n"
    );
}

