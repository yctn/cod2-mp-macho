/* ASM dump from: win_voice.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_voice.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern const dvar_t *winvoice_mic_mute; /* 0x0 */
extern const dvar_t *winvoice_mic_reclevel; /* 0x0 */
extern const dvar_t *winvoice_save_voice; /* 0x0 */
extern const dvar_t *winvoice_mic_scaler; /* 0x0 */
extern int mic_old_reclevel; /* 0x0 */
extern int mic_current_reclevel; /* 0x0 */
extern char old_rec_source[256]; /* 0x0 */
extern float voice_current_voicelevel; /* 0x0 */
extern float voice_current_scaler; /* 0x0 */
extern int g_voice_initialized; /* 0x0 */
extern float levelSamples[6]; /* 0x0 */
extern int sampleCount; /* 0x0 */
static int count; /* 0xff20a4 */
static Bool recording; /* 0xff1e84 */
static Bool playing; /* 0xff20a0 */
static recordingSample_t *currentRecordingSample; /* 0xff1e80 */
static short unsigned int * (*s_clientSamples[64])[4]; /* 0xff1fa0 */
static int s_clientTalkTime[64]; /* 0xff1ea0 */

Bool Voice_Init(void);
float Voice_GetVoiceLevel(void);
unsigned int Voice_Playback(void);
unsigned int Voice_IncomingVoiceData(int talker, unsigned char *data, int packetDataSize);
Bool Voice_IsClientTalking(int clientNum);
unsigned int Voice_Shutdown(void);
int Voice_GetLocalVoiceData(ClientVoicePacket_t *voiceData);

/* line 64 */
__attribute__((naked))
Bool Voice_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 64 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl $0x1001, 8(%esp)\n" /* line 69 */
        "movl $1, 4(%esp)\n"
        "movl $0x2b8e5c, (%esp)\n" /* "winvoice_mic_mute" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, winvoice_mic_mute\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 70 */
        "movl $0x477fff00, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8e70, (%esp)\n" /* "winvoice_mic_reclevel" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, winvoice_mic_reclevel\n"
        "movl $0x1001, 8(%esp)\n" /* line 71 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b8e88, (%esp)\n" /* "winvoice_save_voice" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, winvoice_save_voice\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 72 */
        "movl $0x40000000, 0xc(%esp)\n"
        "movl $0x3e800000, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x2b8e9c, (%esp)\n" /* "winvoice_mic_scaler" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, winvoice_mic_scaler\n"
        "movl 0x195f984, %ebx\n" /* line 84 */
        "movl $0, (%ebx)\n"
        "movl $0, 4(%esp)\n" /* line 87 */
        "movl $0, (%esp)\n"
        "calll Record_Init\n"
        "testl %eax, %eax\n"
        "jne .Lf1e79c8_001e7a9c\n"
        "xorl %eax, %eax\n" /* line 113 */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1e79c8_001e7a9c:\n"
        "movl $0, (%esp)\n" /* line 89 */
        "calll Sound_Init\n"
        "movl (%ebx), %eax\n" /* line 90 */
        "movl %eax, (%esp)\n"
        "calll Encode_Init\n"
        "movl (%ebx), %eax\n" /* line 91 */
        "movl %eax, (%esp)\n"
        "calll Decode_Init\n"
        "movl $old_rec_source, (%esp)\n" /* line 94 */
        "calll mixerGetRecordSource\n"
        "movl $0x2b8eb0, (%esp)\n" /* line 95 */
        "calll mixerSetRecordSource\n"
        "movl $0x2b8eb0, (%esp)\n" /* line 96 */
        "calll mixerGetRecordLevel\n"
        "movl %eax, mic_old_reclevel\n"
        "movl winvoice_mic_reclevel, %edx\n" /* line 98 */
        "cvttss2si 8(%edx), %eax\n"
        "movzwl %ax, %eax\n"
        "movl %eax, mic_current_reclevel\n"
        "cvttss2si 8(%edx), %eax\n" /* line 99 */
        "movzwl %ax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8eb0, (%esp)\n" /* "Mic" */
        "calll mixerSetRecordLevel\n"
        "movl winvoice_mic_mute, %eax\n" /* line 100 */
        "movzbl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll mixerSetMicrophoneMute\n"
        "movl $1, g_voice_initialized\n" /* line 103 */
        "movl $0x100, 8(%esp)\n" /* line 105 */
        "movl $0, 4(%esp)\n"
        "movl $s_clientTalkTime, (%esp)\n"
        "calll memset\n"
        "movl $s_clientSamples, %ebx\n"
        ".Lf1e79c8_001e7b4c:\n"
        "calll Sound_NewSample\n" /* line 109 */
        "movl %eax, (%ebx)\n"
        "addl $4, %ebx\n"
        "cmpl $playing, %ebx\n" /* line 107 */
        "jne .Lf1e79c8_001e7b4c\n"
        "xorl %eax, %eax\n" /* line 113 */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 148 */
__attribute__((naked))
float Voice_GetVoiceLevel(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 148 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        /* { scope 1 */
        "movl g_voice_initialized, %eax\n" /* line 153 */
        "pxor %xmm0, %xmm0\n"
        "testl %eax, %eax\n"
        "je .Lf1e7b66_001e7bd9\n"
        "movl sampleCount, %ecx\n" /* line 156 */
        "movl $0x2aaaaaab, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "addl %edx, %edx\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "movss voice_current_voicelevel, %xmm0\n"
        "divss 0x2edaa4, %xmm0\n" /* 32767.0f */
        "divss 0x2ed5e0, %xmm0\n" /* 6.0f */
        "movss %xmm0, levelSamples(, %eax, 4)\n"
        "addl $1, %ecx\n" /* line 157 */
        "movl %ecx, sampleCount\n"
        "pxor %xmm0, %xmm0\n"
        "movl $levelSamples, %eax\n"
        ".Lf1e7b66_001e7bcb:\n"
        "addss (%eax), %xmm0\n" /* line 161 */
        "addl $4, %eax\n"
        "cmpl $voice_current_voicelevel, %eax\n" /* line 160 */
        "jne .Lf1e7b66_001e7bcb\n"
        /* } scope */
        ".Lf1e7b66_001e7bd9:\n"
        "movss %xmm0, -4(%ebp)\n" /* line 163 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 166 */
__attribute__((naked))
unsigned int Voice_Playback(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl g_voice_initialized, %edx\n" /* line 170 */
        "testl %edx, %edx\n"
        "je .Lf1e7be4_001e7c4c\n"
        "movl winvoice_mic_reclevel, %edx\n" /* line 173 */
        "cvttss2si 8(%edx), %eax\n"
        "movzwl %ax, %eax\n"
        "cmpl mic_current_reclevel, %eax\n"
        "je .Lf1e7be4_001e7c28\n"
        "movl %eax, mic_current_reclevel\n" /* line 175 */
        "cvttss2si 8(%edx), %eax\n" /* line 176 */
        "movzwl %ax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8eb0, (%esp)\n" /* "Mic" */
        "calll mixerSetRecordLevel\n"
        ".Lf1e7be4_001e7c28:\n"
        "movl $s_clientSamples, %ebx\n"
        ".Lf1e7be4_001e7c2d:\n"
        "movl (%ebx), %eax\n" /* line 180 */
        "movl %eax, (%esp)\n"
        "calll Sound_SampleFrame\n"
        "addl $4, %ebx\n"
        "cmpl $playing, %ebx\n" /* line 179 */
        "jne .Lf1e7be4_001e7c2d\n"
        "addl $0x14, %esp\n" /* line 182 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp Sound_Frame\n" /* line 181 */
        ".Lf1e7be4_001e7c4c:\n"
        "addl $0x14, %esp\n" /* line 182 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 212 */
__attribute__((naked))
unsigned int Voice_IncomingVoiceData(int talker, unsigned char *data, int packetDataSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 212 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        /* { scope 1 */
        "movl $1, %eax\n" /* line 221 */
        "cmpb $0, playing\n"
        "movzbl playing, %edx\n"
        "cmovnel %edx, %eax\n"
        "movb %al, playing\n"
        "movzbl 8(%ebp), %eax\n" /* line 227 | talker */
        "movl %eax, -0x201c(%ebp)\n"
        "calll Sys_Milliseconds\n"
        "movl -0x201c(%ebp), %edx\n"
        "movl %eax, s_clientTalkTime(, %edx, 4)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 229 | packetDataSize */
        "testl %ecx, %ecx\n"
        "jle .Lf1e7c54_001e7d44\n"
        "xorl %edi, %edi\n" /* processedBytes */
        ".Lf1e7c54_001e7ca5:\n"
        "movl 0x10(%ebp), %eax\n" /* line 231 | packetDataSize */
        "subl %edi, %eax\n" /* processedBytes */
        "cvtsi2ssl %eax, %xmm2\n"
        "movl 0x195f988, %edx\n"
        "movl (%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm2, %xmm3\n"
        "cmpltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        /* } scope */
        "cvttss2si %xmm0, %esi\n" /* line 231 | bytesToProcess */
        "movl %eax, 0xc(%esp)\n" /* line 232 */
        "leal -0x2018(%ebp), %eax\n" /* decodedData */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* bytesToProcess */
        "movl 0xc(%ebp), %edx\n" /* data */
        "leal (%edi, %edx), %eax\n" /* processedBytes */
        "movl %eax, (%esp)\n"
        "calll Decode_Sample\n"
        "movl %eax, %ebx\n" /* decodedLen */
        "testl %eax, %eax\n" /* line 233 */
        "jle .Lf1e7c54_001e7d23\n"
        "movl %eax, 8(%esp)\n" /* line 234 */
        "leal -0x2018(%ebp), %eax\n" /* decodedData */
        "movl %eax, 4(%esp)\n"
        "movl -0x201c(%ebp), %edx\n"
        "movl s_clientSamples(, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sound_UpdateSample\n"
        ".Lf1e7c54_001e7d23:\n"
        "addl %esi, %edi\n" /* line 236 | bytesToProcess, processedBytes */
        "cmpl %edi, 0x10(%ebp)\n" /* line 229 | processedBytes, packetDataSize */
        "jg .Lf1e7c54_001e7ca5\n"
        "movl winvoice_save_voice, %eax\n" /* line 240 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1e7c54_001e7d51\n"
        /* } scope */
        ".Lf1e7c54_001e7d39:\n"
        "addl $0x202c, %esp\n" /* line 251 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e7c54_001e7d44:\n"
        "xorl %ebx, %ebx\n" /* line 229 | decodedLen */
        "movl winvoice_save_voice, %eax\n" /* line 240 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1e7c54_001e7d39\n"
        /* { scope 2 */
        ".Lf1e7c54_001e7d51:\n"
        "movl $0x2b8eb4, 4(%esp)\n" /* line 243 */
        "movl $0x2b8eb8, (%esp)\n" /* "voice.wav" */
        "calll fopen\n"
        "movl %eax, %esi\n" /* fptr */
        "testl %eax, %eax\n" /* line 244 */
        "je .Lf1e7c54_001e7d39\n"
        "movl %eax, 0xc(%esp)\n" /* line 246 */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* decodedLen */
        "leal -0x2018(%ebp), %eax\n" /* decodedData */
        "movl %eax, (%esp)\n"
        "calll fwrite\n"
        "movl %esi, (%esp)\n" /* line 247 | fptr */
        "calll fclose\n"
        /* } scope */
        /* } scope */
        "addl $0x202c, %esp\n" /* line 251 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 253 */
__attribute__((naked))
Bool Voice_IsClientTalking(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 253 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll Sys_Milliseconds\n" /* line 256 */
        "movl 8(%ebp), %edx\n" /* clientNum */
        "subl s_clientTalkTime(, %edx, 4), %eax\n"
        "cmpl $0x12b, %eax\n"
        "setle %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 257 */
        "retl\n"
    );
}

/* line 115 */
__attribute__((naked))
unsigned int Voice_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 115 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl g_voice_initialized, %ebx\n" /* line 120 */
        "testl %ebx, %ebx\n"
        "jne .Lf1e7dc0_001e7dd9\n"
        "addl $0x10, %esp\n" /* line 141 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1e7dc0_001e7dd9:\n"
        "movl $s_clientSamples, %ebx\n" /* line 121 */
        "movl $playing, %esi\n"
        ".Lf1e7dc0_001e7de3:\n"
        "movl (%ebx), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll Sound_DestroySample\n"
        "addl $4, %ebx\n"
        "cmpl %ebx, %esi\n" /* line 124 */
        "jne .Lf1e7dc0_001e7de3\n"
        "cmpb $0, recording\n" /* line 281 */
        "jne .Lf1e7dc0_001e7e51\n"
        ".Lf1e7dc0_001e7dfd:\n"
        "calll Record_Shutdown\n" /* line 131 */
        "calll Encode_Shutdown\n" /* line 132 */
        "calll Decode_Shutdown\n" /* line 133 */
        "calll Sound_Shutdown\n" /* line 134 */
        "movl $1, (%esp)\n" /* line 136 */
        "calll mixerSetMicrophoneMute\n"
        "movzwl mic_old_reclevel, %eax\n" /* line 137 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8eb0, (%esp)\n" /* "Mic" */
        "calll mixerSetRecordLevel\n"
        "movl $old_rec_source, (%esp)\n" /* line 138 */
        "calll mixerSetRecordSource\n"
        "movl $0, g_voice_initialized\n" /* line 140 */
        "addl $0x10, %esp\n" /* line 141 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1e7dc0_001e7e51:\n"
        "movl currentRecordingSample, %eax\n" /* line 284 */
        "movl %eax, (%esp)\n"
        "calll Record_Stop\n"
        "movl currentRecordingSample, %eax\n" /* line 286 */
        "movl %eax, (%esp)\n"
        "calll Record_DestroySample\n"
        "movb $0, recording\n" /* line 288 */
        "jmp .Lf1e7dc0_001e7dfd\n"
    );
}

/* line 185 */
__attribute__((naked))
int Voice_GetLocalVoiceData(ClientVoicePacket_t *voiceData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 185 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl g_voice_initialized, %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf1e7e74_001e7ea6\n"
        "cmpb $0, recording\n" /* line 190 */
        "je .Lf1e7e74_001e7ece\n"
        ".Lf1e7e74_001e7e8c:\n"
        "movl winvoice_mic_scaler, %eax\n" /* line 193 */
        "movss 8(%eax), %xmm3\n"
        "ucomiss voice_current_scaler, %xmm3\n"
        "jp .Lf1e7e74_001e7eaa\n"
        "jne .Lf1e7e74_001e7eaa\n"
        "calll Record_Frame\n" /* line 201 */
        ".Lf1e7e74_001e7ea6:\n"
        "xorl %eax, %eax\n" /* line 204 */
        "leave\n"
        "retl\n"
        ".Lf1e7e74_001e7eaa:\n"
        "movss %xmm3, voice_current_scaler\n" /* line 195 */
        "ucomiss 0x2ed5d8, %xmm3\n" /* line 196 | 0.5f */
        "jae .Lf1e7e74_001e7ef0\n"
        "jp .Lf1e7e74_001e7ef0\n"
        "movl $0x3f000000, %eax\n" /* line 197 */
        "movl %eax, voice_current_scaler\n"
        "calll Record_Frame\n" /* line 201 */
        "jmp .Lf1e7e74_001e7ea6\n"
        ".Lf1e7e74_001e7ece:\n"
        "calll Record_NewSample\n" /* line 269 */
        "movl %eax, currentRecordingSample\n"
        "movl %eax, (%esp)\n" /* line 271 */
        "calll Record_Start\n"
        "movb $1, recording\n" /* line 273 */
        "addl $1, count\n" /* line 274 */
        "jmp .Lf1e7e74_001e7e8c\n"
        ".Lf1e7e74_001e7ef0:\n"
        "movss 0x2ed600, %xmm0\n" /* line 199 | 1.5f */
        "movaps %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm4\n"
        "cmpnltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss %xmm0, voice_current_scaler\n"
        "calll Record_Frame\n" /* line 201 */
        "jmp .Lf1e7e74_001e7ea6\n"
    );
}

