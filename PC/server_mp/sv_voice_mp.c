/* ASM dump from: sv_voice_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_voice_mp.cpp */

#include "common_types.h"
#include "imports.h"

void SV_SendClientVoiceData(client_t *client);
Bool SV_ClientWantsVoiceData(int clientNum);
Bool SV_ClientHasClientMuted(int listener, int talker);
void SV_QueueVoicePacket(int talkerNum, int clientNum, VoicePacket_t *voicePacket);
void SV_UserVoice(client_t *cl, msg_t *msg);
void SV_PreGameUserVoice(client_t *cl, msg_t *msg);

/* line 59 */
__attribute__((naked))
void SV_SendClientVoiceData(client_t *client)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 59 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %edi\n" /* client */
        /* { scope 1 */
        "movl $0x20000, 4(%esp)\n" /* line 62 */
        "leal -0x1c(%ebp), %eax\n" /* msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %eax\n" /* msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "cmpl $4, (%edi)\n" /* line 66 | client */
        "je .Lf1b95a0_001b95e2\n"
        ".Lf1b95a0_001b95cf:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 92 | msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        ".Lf1b95a0_001b95da:\n"
        "addl $0x5c, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b95a0_001b95e2:\n"
        "movl 0x78ec4(%edi), %ecx\n" /* line 66 | client */
        "testl %ecx, %ecx\n"
        "je .Lf1b95a0_001b95cf\n"
        "movl $0x20000, 8(%esp)\n" /* line 71 */
        "movl %eax, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_Init\n"
        "movl $0x2a9440, 4(%esp)\n" /* line 76 */
        "leal -0x40(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteString\n"
        /* { scope 2 */
        "movl 0x78ec4(%edi), %eax\n" /* line 32 */
        "movl %eax, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 0x78ec4(%edi), %eax\n" /* line 34 */
        "testl %eax, %eax\n"
        "jg .Lf1b95a0_001b96b2\n"
        /* } scope */
        ".Lf1b95a0_001b9635:\n"
        "movl -0x40(%ebp), %edx\n" /* line 83 | msg */
        "testl %edx, %edx\n"
        "je .Lf1b95a0_001b9657\n"
        "leal 0x20c48(%edi), %eax\n" /* line 85 | client */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b5814, (%esp)\n" /* "WARNING: voice msg overflowed for %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1b95a0_001b95cf\n"
        ".Lf1b95a0_001b9657:\n"
        "movl 0x6e5c4(%edi), %ebx\n" /* line 89 | client, packet */
        "movl %ebx, -0x28(%ebp)\n" /* packet */
        "movl 0x6e5c8(%edi), %ecx\n" /* client */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x6e5cc(%edi), %edx\n" /* client */
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* packet */
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandVoiceData\n"
        "movl $0, 0x78ec4(%edi)\n" /* line 92 | client */
        "leal -0x1c(%ebp), %eax\n" /* msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "jmp .Lf1b95a0_001b95da\n"
        /* { scope 2 */
        ".Lf1b95a0_001b96b2:\n"
        "movl %edi, %esi\n" /* line 34 */
        "xorl %ebx, %ebx\n" /* packet */
        ".Lf1b95a0_001b96b6:\n"
        "movzbl 0x765fc(%esi), %eax\n" /* line 37 */
        "movl %eax, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 0x766fd(%esi), %eax\n" /* line 39 */
        "movl %eax, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 0x766fd(%esi), %eax\n" /* line 40 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, %eax\n" /* packet */
        "shll $6, %eax\n"
        "addl %ebx, %eax\n" /* packet */
        "leal 0x765f0(%ebx, %eax, 4), %eax\n" /* packet */
        "leal 0xd(%edi, %eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteData\n"
        "addl $1, %ebx\n" /* line 34 | packet */
        "addl $0x105, %esi\n"
        "cmpl 0x78ec4(%edi), %ebx\n" /* packet */
        "jl .Lf1b95a0_001b96b6\n"
        "jmp .Lf1b95a0_001b9635\n"
        "movl %eax, %ebx\n" /* packet */
        /* } scope */
        "leal -0x1c(%ebp), %eax\n" /* line 92 | msg_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* packet */
        "calll __Unwind_Resume\n"
    );
}

/* line 97 */
__attribute__((naked))
Bool SV_ClientWantsVoiceData(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 97 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* clientNum */
        "movl 0x195f284, %eax\n"
        "movl 0xc(%eax), %ebx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n" /* clientNum */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x78f08(%ebx, %edx, 4), %eax\n"
        "popl %ebx\n" /* line 101 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
Bool SV_ClientHasClientMuted(int listener, int talker)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* listener */
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n" /* listener */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "addl 0xc(%ebp), %edx\n" /* talker */
        "movl 0x195f284, %eax\n"
        "addl 0xc(%eax), %edx\n"
        "movzbl 0x78ec8(%edx), %eax\n"
        "popl %ebp\n" /* line 111 */
        "retl\n"
    );
}

/* line 115 */
__attribute__((naked))
void SV_QueueVoicePacket(int talkerNum, int clientNum, VoicePacket_t *voicePacket)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 115 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %ecx\n" /* clientNum */
        "movl 0x10(%ebp), %esi\n" /* voicePacket */
        /* { scope 1 */
        "leal (%ecx, %ecx, 4), %eax\n" /* line 130 */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195f284, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* client */
        "movl 0x78ec4(%ebx), %edx\n" /* line 136 | client */
        "cmpl $0x27, %edx\n"
        "jg .Lf1b97a0_001b9846\n"
        "movl %edx, %eax\n" /* line 140 */
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x101(%esi), %edx\n" /* voicePacket */
        "movl %edx, 0x766fd(%eax, %ebx)\n"
        "movl 0x78ec4(%ebx), %edx\n" /* line 141 | client */
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "leal 0x765f0(%edx, %eax, 4), %eax\n"
        "leal 0xd(%ebx, %eax), %ecx\n" /* client */
        "leal 1(%esi), %edx\n" /* voicePacket */
        "movl 0x101(%esi), %eax\n" /* voicePacket */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x78ec4(%ebx), %edx\n" /* line 147 | client */
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movzbl 8(%ebp), %edx\n" /* talkerNum */
        "movb %dl, 0x765fc(%eax, %ebx)\n"
        "addl $1, 0x78ec4(%ebx)\n" /* line 148 | client */
        /* } scope */
        ".Lf1b97a0_001b9846:\n"
        "addl $0x10, %esp\n" /* line 150 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 153 */
__attribute__((naked))
void SV_UserVoice(client_t *cl, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 153 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* msg */
        /* { scope 1 */
        "movl 0x195f2a4, %eax\n" /* line 169 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1b984e_001b9875\n"
        /* } scope */
        ".Lf1b984e_001b986a:\n"
        "addl $0x13c, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b984e_001b9875:\n"
        "movl %esi, (%esp)\n" /* line 173 | msg */
        "calll MSG_ReadByte\n"
        "movl %eax, %edi\n" /* packetCount */
        "testl %eax, %eax\n" /* line 176 */
        "jle .Lf1b984e_001b986a\n"
        "xorl %ebx, %ebx\n" /* packet */
        "movl 8(%ebp), %eax\n" /* cl */
        "addl $0x20c48, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "jmp .Lf1b984e_001b98cd\n"
        ".Lf1b984e_001b9895:\n"
        "movl %edx, 8(%esp)\n" /* line 188 */
        "leal -0x11c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* msg */
        "calll MSG_ReadData\n"
        "leal -0x11d(%ebp), %eax\n" /* line 189 | voicePacket */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cl */
        "movl 0x20c44(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_BroadcastVoice\n"
        "addl $1, %ebx\n" /* line 176 | packet */
        "cmpl %ebx, %edi\n" /* packet, packetCount */
        "je .Lf1b984e_001b986a\n"
        ".Lf1b984e_001b98cd:\n"
        "movl %esi, (%esp)\n" /* line 179 | msg */
        "calll MSG_ReadByte\n"
        "movl %eax, %edx\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -1(%eax), %eax\n" /* line 180 */
        "cmpl $0xff, %eax\n"
        "jbe .Lf1b984e_001b9895\n"
        "movl -0x12c(%ebp), %eax\n" /* line 182 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x2b583c, (%esp)\n" /* "Received invalid voice packet of size %i from %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1b984e_001b986a\n"
    );
}

/* line 203 */
__attribute__((naked))
void SV_PreGameUserVoice(client_t *cl, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 203 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        /* { scope 1 */
        "movl 0x195f2a4, %eax\n" /* line 221 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1b9904_001b9928\n"
        /* } scope */
        ".Lf1b9904_001b991d:\n"
        "addl $0x13c, %esp\n" /* line 276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b9904_001b9928:\n"
        "movl 0x195f284, %eax\n" /* line 225 */
        "movl 8(%ebp), %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, -0x134(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* line 226 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadByte\n"
        "movl %eax, -0x130(%ebp)\n" /* packetCount */
        "testl %eax, %eax\n" /* line 228 */
        "jle .Lf1b9904_001b991d\n"
        "movl $0, -0x12c(%ebp)\n" /* packet */
        ".Lf1b9904_001b9963:\n"
        "movl 0xc(%ebp), %edx\n" /* line 231 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadShort\n"
        "movl %eax, %edx\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -1(%eax), %eax\n" /* line 232 */
        "cmpl $0xff, %eax\n"
        "ja .Lf1b9904_001b9a87\n"
        "movl %edx, 8(%esp)\n" /* line 240 */
        "leal -0x11c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadData\n"
        "xorl %esi, %esi\n" /* otherPlayer */
        "xorl %edi, %edi\n"
        "jmp .Lf1b9904_001b99b2\n"
        ".Lf1b9904_001b99a0:\n"
        "addl $1, %esi\n" /* line 248 | otherPlayer */
        "addl $0x78f0c, %edi\n"
        "cmpl $0x40, %esi\n" /* otherPlayer */
        "je .Lf1b9904_001b9a69\n"
        ".Lf1b9904_001b99b2:\n"
        "cmpl %esi, -0x134(%ebp)\n" /* line 250 | otherPlayer */
        "je .Lf1b9904_001b99a0\n"
        "movl 0x195f284, %eax\n" /* line 253 */
        "movl %edi, %ebx\n"
        "addl 0xc(%eax), %ebx\n"
        "cmpl $1, (%ebx)\n"
        "jle .Lf1b9904_001b99a0\n"
        "movl -0x134(%ebp), %eax\n" /* line 256 */
        "cmpb $0, 0x78ec8(%eax, %ebx)\n"
        "jne .Lf1b9904_001b99a0\n"
        "cmpb $0, 0x78f08(%ebx)\n" /* line 266 */
        "je .Lf1b9904_001b99a0\n"
        "movl 0x78ec4(%ebx), %edx\n" /* line 136 */
        "cmpl $0x27, %edx\n"
        "jg .Lf1b9904_001b99a0\n"
        "movl %edx, %eax\n" /* line 140 */
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0x766fd(%eax, %ebx)\n"
        "movl 0x78ec4(%ebx), %edx\n" /* line 141 */
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "leal 0x765f0(%edx, %eax, 4), %eax\n"
        "leal 0xd(%ebx, %eax), %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x11c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x78ec4(%ebx), %edx\n" /* line 147 */
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movzbl -0x134(%ebp), %edx\n"
        "movb %dl, 0x765fc(%eax, %ebx)\n"
        "addl $1, 0x78ec4(%ebx)\n" /* line 148 */
        "addl $1, %esi\n" /* line 248 | otherPlayer */
        "addl $0x78f0c, %edi\n"
        "cmpl $0x40, %esi\n" /* otherPlayer */
        "jne .Lf1b9904_001b99b2\n"
        ".Lf1b9904_001b9a69:\n"
        "addl $1, -0x12c(%ebp)\n" /* line 228 | packet */
        "movl -0x12c(%ebp), %eax\n" /* packet */
        "cmpl %eax, -0x130(%ebp)\n" /* packetCount */
        "jne .Lf1b9904_001b9963\n"
        "jmp .Lf1b9904_001b991d\n"
        ".Lf1b9904_001b9a87:\n"
        "movl 8(%ebp), %eax\n" /* line 234 | cl */
        "addl $0x20c48, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x2b583c, (%esp)\n" /* "Received invalid voice packet of size %i from %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1b9904_001b991d\n"
    );
}

