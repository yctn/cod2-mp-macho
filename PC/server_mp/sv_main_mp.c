/* ASM dump from: sv_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_main_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern void Scr_FreeValue(int value);
extern void SV_ResetSkeletonCache(void);
extern void G_RunFrame(int levelTime);

__asm__(".Lsvpkt_fmt: .asciz \"[SV_PktEvt] netchan=%d clState=%d serverId=%d relAck=%d\\n\"\n");
static int sv_pkt_dbg_count = 0;
void SV_PktEvtDbg(const char *fmt, int netchanResult, int clState, int serverId, int relAck) {
    if (sv_pkt_dbg_count < 30 || (sv_pkt_dbg_count % 500 == 0)) {
        fprintf(stderr, fmt, netchanResult, clState, serverId, relAck);
    }
    sv_pkt_dbg_count++;
}

extern struct serverStatic_t svs; /* 0x0 */
extern struct server_t sv; /* 0x0 */
extern const dvar_t *sv_fps; /* 0x0 */
extern const dvar_t *sv_timeout; /* 0x0 */
extern const dvar_t *sv_zombietime; /* 0x0 */
extern const dvar_t *rcon_password; /* 0x0 */
extern const dvar_t *sv_privatePassword; /* 0x0 */
extern const dvar_t *sv_allowDownload; /* 0x0 */
extern const dvar_t *sv_maxclients; /* 0x0 */
extern const dvar_t *sv_privateClients; /* 0x0 */
extern const dvar_t *sv_hostname; /* 0x0 */
extern const dvar_t *sv_reconnectlimit; /* 0x0 */
extern const dvar_t *sv_padPackets; /* 0x0 */
extern const dvar_t *sv_mapname; /* 0x0 */
extern const dvar_t *sv_cheats; /* 0x0 */
extern const dvar_t *sv_serverid; /* 0x0 */
extern const dvar_t *sv_maxRate; /* 0x0 */
extern const dvar_t *sv_minPing; /* 0x0 */
extern const dvar_t *sv_maxPing; /* 0x0 */
extern const dvar_t *sv_gametype; /* 0x0 */
extern const dvar_t *sv_debugRate; /* 0x0 */
extern const dvar_t *sv_debugReliableCmds; /* 0x0 */
extern const dvar_t *sv_pure; /* 0x0 */
extern const dvar_t *sv_floodProtect; /* 0x0 */
extern const dvar_t *sv_allowAnonymous; /* 0x0 */
extern const dvar_t *sv_showCommands; /* 0x0 */
extern const dvar_t *sv_packet_info; /* 0x0 */
extern const dvar_t *sv_voice; /* 0x0 */
extern const dvar_t *sv_voiceQuality; /* 0x0 */
extern const dvar_t *sv_showAverageBPS; /* 0x0 */
extern const dvar_t *sv_kickBanTime; /* 0x0 */
extern const dvar_t *sv_iwds; /* 0x0 */
extern const dvar_t *sv_iwdNames; /* 0x0 */
extern const dvar_t *sv_referencedIwds; /* 0x0 */
extern const dvar_t *sv_referencedIwdNames; /* 0x0 */
extern const dvar_t *sv_allowedClan1; /* 0x0 */
extern const dvar_t *sv_allowedClan2; /* 0x0 */
extern const dvar_t *sv_mapRotation; /* 0x0 */
extern const dvar_t *sv_mapRotationCurrent; /* 0x0 */
extern const dvar_t *sv_disableClientConsole; /* 0x0 */
static char string_00edae00[1024]; /* string */

long int SV_AddServerCommand(client_t *client, svscmd_type type, const char *cmd);
long int SV_VoicePacket(netadr_t from, msg_t *msg);
long int SVC_Status(netadr_t from);
long int SVC_GameCompleteStatus(netadr_t from);
long int SVC_Info(netadr_t from);
long int SV_ConnectionlessPacket(netadr_t from, msg_t *msg);
long int SV_PacketEvent(netadr_t from, msg_t *msg);
long int SV_FreeClientScriptId(client_t *cl);
long int SV_RunFrame(void);
long int SV_BotUserMove(client_t *cl);
long int SV_SendServerCommand(client_t *cl, svscmd_type type, const char *fmt);
long int SV_Frame(int msec);

/* line 281 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
long int SV_AddServerCommand(client_t *client, svscmd_type type, const char *cmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 281 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 288 | client */
        "movl 0x765f4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1593ae_00159569\n"
        "movl %eax, %edx\n"
        "movl 0x20814(%eax), %ebx\n" /* line 291 | i */
        "movl %ebx, %eax\n" /* i */
        "subl 0x20810(%edx), %eax\n"
        "cmpl $0x3f, %eax\n"
        "jg .Lf1593ae_00159571\n"
        "cmpl $4, (%edx)\n"
        "je .Lf1593ae_00159478\n"
        "movl 8(%ebp), %ecx\n" /* client */
        /* { scope 2: str1 */
        ".Lf1593ae_001593ed:\n"
        "movl 0x20814(%ecx), %edi\n" /* line 257 */
        "addl $1, %edi\n"
        "cmpl %edi, %ebx\n" /* line 258 | toIndex */
        "jl .Lf1593ae_0015945f\n"
        "movl %edi, %esi\n" /* to */
        "movl 8(%ebp), %ebx\n" /* client, toIndex */
        ".Lf1593ae_001593ff:\n"
        "movl %esi, %ecx\n" /* line 260 | to */
        "andl $0x7f, %ecx\n"
        "movl %ecx, %eax\n" /* line 261 */
        "shll $0xa, %eax\n"
        "leal (%eax, %ecx, 8), %eax\n"
        "leal (%eax, %ebx), %edx\n"
        "movl 0x810(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1593ae_00159454\n"
        "movl %edi, %ebx\n" /* line 263 | toIndex */
        "andl $0x7f, %ebx\n" /* toIndex */
        "cmpl %ebx, %ecx\n" /* line 264 | toIndex */
        "je .Lf1593ae_0015944e\n"
        "movl %ebx, %eax\n" /* line 265 | toIndex */
        "shll $0xa, %eax\n"
        "leal (%eax, %ebx, 8), %eax\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "leal 0x40c(%eax, %ecx), %eax\n"
        "addl $0x40c, %edx\n"
        "movl $0x408, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        ".Lf1593ae_0015944e:\n"
        "addl $1, %edi\n" /* line 266 */
        "movl 8(%ebp), %ebx\n" /* client, toIndex */
        ".Lf1593ae_00159454:\n"
        "addl $1, %esi\n" /* line 258 | to */
        "cmpl %esi, 0x20814(%ebx)\n" /* to, toIndex */
        "jge .Lf1593ae_001593ff\n"
        ".Lf1593ae_0015945f:\n"
        "leal -1(%edi), %eax\n" /* line 269 */
        "movl 8(%ebp), %edi\n" /* client */
        "movl %eax, 0x20814(%edi)\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 294 | type */
        "testl %edx, %edx\n"
        "je .Lf1593ae_00159569\n"
        "movl %eax, %ebx\n" /* i */
        /* { scope 2: str1 */
        ".Lf1593ae_00159478:\n"
        "movl 8(%ebp), %eax\n" /* line 194 | client */
        "movl 0x20814(%eax), %esi\n"
        "addl $1, %esi\n"
        "cmpl %ebx, %esi\n"
        "jg .Lf1593ae_00159507\n"
        "movl %eax, %edi\n"
        "jmp .Lf1593ae_0015949a\n"
        ".Lf1593ae_0015948c:\n"
        "addl $1, %esi\n"
        "cmpl %ebx, %esi\n"
        "jg .Lf1593ae_00159578\n"
        "movl 8(%ebp), %edi\n" /* client */
        ".Lf1593ae_0015949a:\n"
        "movl %esi, %edx\n" /* line 196 */
        "andl $0x7f, %edx\n"
        "movl %edx, %eax\n" /* line 198 */
        "shll $0xa, %eax\n"
        "leal (%eax, %edx, 8), %ecx\n"
        "leal (%ecx, %edi), %edx\n"
        "movl 0x810(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1593ae_0015948c\n"
        "movl 0x10(%ebp), %edi\n" /* line 203 | cmd */
        "movzbl (%edi), %eax\n"
        "movsbl %al, %edi\n"
        "cmpb %al, 0x40c(%edx)\n"
        "jne .Lf1593ae_0015948c\n"
        "subb $0x78, %al\n" /* line 207 */
        "cmpb $2, %al\n"
        "jbe .Lf1593ae_0015948c\n"
        "movl 8(%ebp), %edx\n" /* line 215 | client */
        "leal 0x400(%ecx, %edx), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "addl $0xd, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* cmd */
        "addl $1, %edx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1593ae_00159657\n"
        "leal -0x43(%edi), %eax\n" /* line 219 */
        "cmpl $0x33, %eax\n"
        "ja .Lf1593ae_0015948c\n"
        "jmpl *.Ljt_1593ae_0(, %eax, 4)\n"
        ".Lf1593ae_00159507:\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf1593ae_00159509:\n"
        "leal 1(%ebx), %eax\n" /* line 306 | i */
        "movl %eax, 0x20814(%edx)\n"
        "movl %eax, %ebx\n" /* i */
        "movl 8(%ebp), %edi\n" /* client, from */
        ".Lf1593ae_00159517:\n"
        "movl %ebx, %eax\n" /* line 313 | i */
        "subl 0x20810(%edi), %eax\n" /* from */
        "cmpl $0x81, %eax\n"
        "je .Lf1593ae_0015957d\n"
        "movl 0xc(%ebp), %esi\n" /* type, to */
        "movl 8(%ebp), %edx\n" /* client */
        "movl 0x10(%ebp), %ecx\n" /* cmd */
        ".Lf1593ae_0015952f:\n"
        "andl $0x7f, %ebx\n" /* line 328 | i */
        "movl $0x400, 8(%esp)\n" /* line 329 */
        "movl %ebx, %eax\n" /* i */
        "shll $0xa, %eax\n"
        "leal (%eax, %ebx, 8), %ebx\n" /* i */
        "leal 0x40c(%ebx, %edx), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll MSG_WriteReliableCommandToBuffer\n"
        "addl 8(%ebp), %ebx\n" /* line 330 | client, i */
        "movl svs+4, %eax\n"
        "movl %eax, 0x80c(%ebx)\n" /* i */
        "movl %esi, 0x810(%ebx)\n" /* line 331 | to, i */
        /* } scope */
        ".Lf1593ae_00159569:\n"
        "addl $0x5c, %esp\n" /* line 332 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1593ae_00159571:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1593ae_001593ed\n"
        ".Lf1593ae_00159578:\n"
        "movl 8(%ebp), %edx\n" /* client */
        "jmp .Lf1593ae_00159509\n"
        /* { scope 1 */
        ".Lf1593ae_0015957d:\n"
        "movl $str_002ab3d4, (%esp)\n" /* line 315 */
        "calll Com_Printf\n"
        "movl 8(%ebp), %eax\n" /* line 316 | client */
        "movl 0x20810(%eax), %ebx\n" /* i */
        "addl $1, %ebx\n" /* i */
        "cmpl 0x20814(%eax), %ebx\n" /* i */
        "jle .Lf1593ae_00159756\n"
        ".Lf1593ae_001595a1:\n"
        "movl 0x10(%ebp), %eax\n" /* line 320 | cmd */
        "movl %eax, 0xc(%esp)\n"
        "movl svs+4, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_002ab3fc, (%esp)\n" /* "cmd %5d: %8d: %s
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %edx\n" /* line 321 | client */
        "movl 0x6e5c4(%edx), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl %edx, %ebx\n" /* i */
        "movl 0x6e5c8(%edx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* i */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $str_00228e90, 0x10(%esp)\n" /* "disconnect" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl $str_002ab410, 4(%esp)\n" /* line 322 */
        "movl %ebx, (%esp)\n" /* i */
        "calll SV_DelayDropClient\n"
        "movl $0x77, 4(%esp)\n" /* line 326 */
        "movl $str_002ab42c, (%esp)\n" /* "%c "EXE_SERVERCOMMANDOVERFLOW"" */
        "calll va\n"
        "movl %eax, 0x10(%ebp)\n" /* cmd */
        "movl $1, %esi\n" /* to */
        "movl 8(%ebp), %edi\n" /* client, from */
        "movl 0x20814(%edi), %ebx\n" /* from, i */
        "movl %edi, %edx\n" /* from */
        "movl %eax, %ecx\n"
        "jmp .Lf1593ae_0015952f\n"
        /* { scope 2: str1 */
        /* { scope 3 */
        ".Lf1593ae_0015963f:\n"
        "cmpb $0x20, %dl\n" /* line 179 */
        "jne .Lf1593ae_0015948c\n"
        ".Lf1593ae_00159648:\n"
        "movzbl (%ecx), %eax\n"
        ".Lf1593ae_0015964b:\n"
        "testb %al, %al\n"
        "je .Lf1593ae_00159657\n"
        "cmpb $0x20, %al\n"
        "jne .Lf1593ae_0015948c\n"
        /* } scope */
        /* } scope */
        ".Lf1593ae_00159657:\n"
        "testl %esi, %esi\n" /* line 299 | to */
        "js .Lf1593ae_00159578\n"
        "leal 1(%esi), %ecx\n" /* line 301 | to */
        "movl %ecx, -0x30(%ebp)\n"
        "movl %ecx, %edi\n" /* from */
        "cmpl %ebx, %ecx\n" /* i */
        "jg .Lf1593ae_001597a2\n"
        "jmp .Lf1593ae_00159679\n"
        ".Lf1593ae_00159671:\n"
        "movl %esi, %eax\n" /* to */
        "addl $1, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        ".Lf1593ae_00159679:\n"
        "movl %esi, %ecx\n" /* line 302 | to */
        "andl $0x7f, %ecx\n"
        "movl %ecx, %eax\n"
        "shll $0xa, %eax\n"
        "leal (%eax, %ecx, 8), %ecx\n"
        "movl %edi, %eax\n" /* from */
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 8(%ebp), %ebx\n" /* client, i */
        "leal 0x40c(%ecx, %ebx), %ecx\n"
        "leal 0x40c(%eax, %ebx), %eax\n"
        "movl $0x408, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %edi\n" /* line 301 | from */
        "movl -0x30(%ebp), %esi\n" /* to */
        "cmpl 0x20814(%ebx), %edi\n" /* i, from */
        "jle .Lf1593ae_00159671\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "movl 0x20814(%ecx), %ebx\n" /* i */
        "movl %ecx, %edi\n" /* from */
        "jmp .Lf1593ae_00159517\n"
        /* { scope 2: str1 */
        ".Lf1593ae_001596d6:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 235 | str2 */
        "addl $2, %ecx\n" /* str2 */
        "movl 0x10(%ebp), %edi\n" /* cmd */
        "addl $2, %edi\n"
        "movl %edi, -0x3c(%ebp)\n" /* str1 */
        /* { scope 3 */
        "movl 0x10(%ebp), %eax\n" /* line 171 | cmd */
        "movzbl 2(%eax), %edx\n"
        "testb %dl, %dl\n"
        "je .Lf1593ae_001597aa\n"
        "movl -0x2c(%ebp), %edi\n"
        "movzbl 2(%edi), %eax\n"
        "testb %al, %al\n"
        "je .Lf1593ae_0015963f\n"
        "cmpb $0x20, %dl\n"
        "je .Lf1593ae_0015964b\n"
        "cmpb $0x20, %al\n"
        "je .Lf1593ae_0015963f\n"
        "cmpb %dl, %al\n" /* line 173 */
        "jne .Lf1593ae_0015948c\n"
        "movl -0x3c(%ebp), %edi\n" /* str1 */
        ".Lf1593ae_0015971f:\n"
        "addl $1, %ecx\n" /* line 176 */
        "movzbl 1(%edi), %edx\n" /* line 171 */
        "testb %dl, %dl\n"
        "je .Lf1593ae_00159648\n"
        "movzbl (%ecx), %eax\n"
        "testb %al, %al\n"
        "je .Lf1593ae_0015963f\n"
        "cmpb $0x20, %dl\n"
        "je .Lf1593ae_0015964b\n"
        "cmpb $0x20, %al\n"
        "je .Lf1593ae_0015963f\n"
        "addl $1, %edi\n"
        "cmpb %dl, %al\n" /* line 173 */
        "je .Lf1593ae_0015971f\n"
        "jmp .Lf1593ae_0015948c\n"
        ".Lf1593ae_00159756:\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1593ae_0015975c\n"
        ".Lf1593ae_0015975a:\n"
        "movl %edi, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf1593ae_0015975c:\n"
        "movl %ebx, %eax\n" /* line 318 | i */
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0x40c(%eax, %ecx), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0x80c(%eax, %ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_002ab3fc, (%esp)\n" /* "cmd %5d: %8d: %s
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 316 | i */
        "movl 8(%ebp), %edi\n" /* client, from */
        "cmpl 0x20814(%edi), %ebx\n" /* from, i */
        "jle .Lf1593ae_0015975a\n"
        "jmp .Lf1593ae_001595a1\n"
        ".Lf1593ae_001597a2:\n"
        "movl 8(%ebp), %edi\n" /* client, from */
        "jmp .Lf1593ae_00159517\n"
        ".Lf1593ae_001597aa:\n"
        "movl -0x2c(%ebp), %edx\n"
        "movzbl 2(%edx), %eax\n"
        "jmp .Lf1593ae_0015964b\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_1593ae_0:\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_001596d6\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_00159657\n"
        ".long .Lf1593ae_0015948c\n"
        ".long .Lf1593ae_001596d6\n"
        ".text\n"
    );
}

/* line 389 */
__attribute__((naked))
long int SV_VoicePacket(netadr_t from, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 389 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movzbl 0xf(%ebp), %eax\n"
        "movb %al, -0x39(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x3a(%ebp)\n"
        "movzbl 0xd(%ebp), %eax\n"
        "movb %al, -0x3b(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x3c(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* from */
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x10(%ebp), %edi\n"
        /* { scope 1 */
        "movl 0x14(%ebp), %eax\n" /* line 396 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadShort\n"
        "movl %eax, -0x44(%ebp)\n" /* qport */
        "movl svs+12, %ebx\n" /* line 400 | cl */
        "movl sv_maxclients, %eax\n"
        "movl 8(%eax), %esi\n" /* i */
        "testl %esi, %esi\n" /* i */
        "jle .Lf1597b6_001598ad\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf1597b6_0015981e\n"
        ".Lf1597b6_0015980c:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x78f0c, %ebx\n" /* cl */
        "cmpl 8(%eax), %esi\n" /* i */
        "jge .Lf1597b6_001598ad\n"
        ".Lf1597b6_0015981e:\n"
        "movl (%ebx), %ecx\n" /* line 402 | cl */
        "testl %ecx, %ecx\n"
        "je .Lf1597b6_0015980c\n"
        "movl 0x6e5c4(%ebx), %ecx\n" /* line 406 | cl */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 0x6e5c8(%ebx), %edx\n" /* cl */
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* cl */
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, -0x28(%ebp)\n"
        "movzbl -0x39(%ebp), %eax\n"
        "movb %al, -0x1d(%ebp)\n"
        "movzbl -0x3a(%ebp), %eax\n"
        "movb %al, -0x1e(%ebp)\n"
        "movzbl -0x3b(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x3c(%ebp), %eax\n"
        "movb %al, -0x20(%ebp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movw %di, -0x1c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "je .Lf1597b6_00159896\n"
        "movl -0x44(%ebp), %eax\n" /* line 414 | qport */
        "cmpl 0x6e5d0(%ebx), %eax\n" /* cl */
        "je .Lf1597b6_001598b5\n"
        ".Lf1597b6_00159896:\n"
        "movl sv_maxclients, %eax\n"
        "addl $1, %esi\n" /* line 400 | i */
        "addl $0x78f0c, %ebx\n" /* cl */
        "cmpl 8(%eax), %esi\n" /* i */
        "jl .Lf1597b6_0015981e\n"
        /* } scope */
        ".Lf1597b6_001598ad:\n"
        "addl $0x5c, %esp\n" /* line 446 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1597b6_001598b5:\n"
        "cmpw %di, 0x6e5cc(%ebx)\n" /* line 422 | cl */
        "je .Lf1597b6_001598d1\n"
        "movl $str_002ab44c, (%esp)\n" /* line 424 */
        "calll Com_Printf\n"
        "movw %di, 0x6e5cc(%ebx)\n" /* line 425 | cl */
        ".Lf1597b6_001598d1:\n"
        "cmpl $1, (%ebx)\n" /* line 432 | cl */
        "je .Lf1597b6_00159896\n"
        "movl svs+4, %eax\n" /* line 434 */
        "movl %eax, 0x20d10(%ebx)\n" /* cl */
        "cmpl $3, (%ebx)\n" /* line 435 | cl */
        "jg .Lf1597b6_001598ff\n"
        "movl 0x14(%ebp), %eax\n" /* line 437 | msg */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_PreGameUserVoice\n"
        "movl sv_maxclients, %eax\n"
        "jmp .Lf1597b6_0015980c\n"
        ".Lf1597b6_001598ff:\n"
        "movl 0x14(%ebp), %eax\n" /* line 442 | msg */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_UserVoice\n"
        "movl sv_maxclients, %eax\n"
        "jmp .Lf1597b6_0015980c\n"
    );
}

/* line 460 */
__attribute__((naked))
long int SVC_Status(netadr_t from)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 460 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x485c, %esp\n"
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x482e(%ebp)\n"
        "movzbl 0xf(%ebp), %edx\n"
        "movb %dl, -0x482f(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x4830(%ebp)\n"
        "movzbl 0xd(%ebp), %edx\n"
        "movb %dl, -0x4831(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x4832(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* from */
        "movl %edx, -0x4838(%ebp)\n"
        /* { scope 1: keywords */
        "movl $0x4000, 4(%esp)\n" /* line 463 */
        "leal -0x1c(%ebp), %eax\n" /* status_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* status_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x4844(%ebp)\n" /* status */
        "movl $0x404, (%esp)\n" /* line 484 */
        "calll Dvar_InfoString\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2828(%ebp), %eax\n" /* infostring */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl $1, (%esp)\n" /* line 488 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9338, 4(%esp)\n" /* "challenge" */
        "leal -0x2828(%ebp), %edx\n" /* infostring */
        "movl %edx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl $str_00216d6c, (%esp)\n" /* line 491 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "jne .Lf159918_00159c54\n"
        ".Lf159918_001599db:\n"
        "movl -0x4844(%ebp), %eax\n" /* line 499 | status */
        "movb $0, (%eax)\n"
        "movl sv_maxclients, %eax\n" /* line 502 */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf159918_00159b02\n"
        "movl $0, -0x483c(%ebp)\n" /* statusLength */
        "movl $0, -0x4840(%ebp)\n" /* i */
        "movl $0, -0x482c(%ebp)\n"
        "jmp .Lf159918_00159aac\n"
        ".Lf159918_00159a17:\n"
        "xorl %eax, %eax\n" /* line 508 */
        ".Lf159918_00159a19:\n"
        "movl %esi, 0x14(%esp)\n" /* count */
        "movl %edi, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002ab484, 8(%esp)\n" /* "%i %i "%s"
" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x428(%ebp), %eax\n" /* player */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "cld\n" /* line 509 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x428(%ebp), %edi\n" /* player */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x483c(%ebp), %edx\n" /* statusLength */
        "leal -1(%ecx, %edx), %ebx\n" /* cl */
        "cmpl $0x3fff, %ebx\n" /* line 510 | cl */
        "ja .Lf159918_00159b02\n"
        "leal -0x428(%ebp), %eax\n" /* line 514 | player */
        "movl %eax, 4(%esp)\n"
        "movl -0x4844(%ebp), %eax\n" /* status */
        "addl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl %ebx, -0x483c(%ebp)\n" /* cl, statusLength */
        "movl sv_maxclients, %eax\n"
        ".Lf159918_00159a90:\n"
        "addl $1, -0x4840(%ebp)\n" /* line 502 | i */
        "addl $0x78f0c, -0x482c(%ebp)\n"
        "movl -0x4840(%ebp), %edx\n" /* i */
        "cmpl %edx, 8(%eax)\n"
        "jle .Lf159918_00159b02\n"
        ".Lf159918_00159aac:\n"
        "movl -0x482c(%ebp), %ebx\n" /* line 504 | cl */
        "addl svs+12, %ebx\n" /* cl */
        "cmpl $1, (%ebx)\n" /* line 505 | cl */
        "jle .Lf159918_00159a90\n"
        "movl -0x4840(%ebp), %edx\n" /* line 507 | i */
        "movl %edx, (%esp)\n"
        "calll SV_GameClientNum\n"
        "leal 0x20c48(%ebx), %esi\n" /* line 508 | cl, count */
        "movl 0x6e5a4(%ebx), %edi\n" /* cl */
        "movl imp_gameInitialized, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf159918_00159a17\n"
        "subl svs+12, %ebx\n" /* cl */
        "sarl $2, %ebx\n" /* cl */
        "imull $0x3789a4eb, %ebx, %eax\n" /* cl */
        "movl %eax, (%esp)\n"
        "calll G_GetClientScore\n"
        "jmp .Lf159918_00159a19\n"
        ".Lf159918_00159b02:\n"
        "movl $str_002ab490, (%esp)\n" /* line 519 */
        "calll Dvar_GetString\n"
        "testl %eax, %eax\n" /* line 520 */
        "je .Lf159918_00159b1b\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf159918_00159cab\n"
        ".Lf159918_00159b1b:\n"
        "movl $str_0021952c, 8(%esp)\n" /* line 523 */
        "movl $str_002a9af0, 4(%esp)\n" /* "pswrd" */
        "leal -0x2828(%ebp), %edx\n" /* infostring */
        "movl %edx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        ".Lf159918_00159b39:\n"
        "movl $str_00216d64, (%esp)\n" /* line 526 */
        "calll Dvar_GetString\n"
        "movl %eax, %edx\n"
        "movl sv_pure, %eax\n" /* line 527 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf159918_00159b63\n"
        "testl %edx, %edx\n"
        "je .Lf159918_00159c38\n"
        "cmpb $0, (%edx)\n"
        "je .Lf159918_00159c38\n"
        ".Lf159918_00159b63:\n"
        "movl $1, %eax\n" /* line 538 */
        ".Lf159918_00159b68:\n"
        "movl %eax, 4(%esp)\n" /* line 548 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9cf4, 4(%esp)\n" /* "mod" */
        "leal -0x2828(%ebp), %eax\n" /* infostring */
        "movl %eax, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl -0x4844(%ebp), %edx\n" /* line 551 | status */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x2828(%ebp), %eax\n" /* infostring */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002ab49c, 8(%esp)\n" /* "statusResponse
%s
%s" */
        "movl $0x2000, 4(%esp)\n"
        "leal -0x4828(%ebp), %ebx\n" /* finalString, cl */
        "movl %ebx, (%esp)\n" /* cl */
        "calll Com_sprintf\n"
        "movzwl -0x482e(%ebp), %edx\n" /* line 552 */
        "movw %dx, -0x20(%ebp)\n"
        "movzbl -0x482f(%ebp), %eax\n"
        "movb %al, -0x21(%ebp)\n"
        "movzbl -0x4830(%ebp), %edx\n"
        "movb %dl, -0x22(%ebp)\n"
        "movzbl -0x4831(%ebp), %eax\n"
        "movb %al, -0x23(%ebp)\n"
        "movzbl -0x4832(%ebp), %edx\n"
        "movb %dl, -0x24(%ebp)\n"
        "movl -0x4838(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %ebx, 0x10(%esp)\n" /* cl */
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "leal -0x1c(%ebp), %eax\n" /* status_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x485c, %esp\n" /* line 553 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keywords */
        ".Lf159918_00159c38:\n"
        "movl $str_002a7220, (%esp)\n" /* line 533 */
        "calll Dvar_GetString\n"
        "cmpb $0, (%eax)\n" /* line 534 */
        "jne .Lf159918_00159cce\n"
        ".Lf159918_00159c4d:\n"
        "xorl %eax, %eax\n" /* line 538 */
        "jmp .Lf159918_00159b68\n"
        /* { scope 2 */
        ".Lf159918_00159c54:\n"
        "movl $str_002a710c, 4(%esp)\n" /* line 495 */
        "leal -0x2828(%ebp), %eax\n" /* infostring */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002ab47c, 8(%esp)\n" /* "demo %s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x828(%ebp), %ebx\n" /* keywords, cl */
        "movl %ebx, (%esp)\n" /* cl */
        "calll Com_sprintf\n"
        "movl %ebx, 8(%esp)\n" /* line 496 | cl */
        "movl $str_002a710c, 4(%esp)\n" /* "sv_keywords" */
        "leal -0x2828(%ebp), %edx\n" /* infostring */
        "movl %edx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "jmp .Lf159918_001599db\n"
        /* } scope */
        ".Lf159918_00159cab:\n"
        "movl $str_002162ac, 8(%esp)\n" /* line 521 */
        "movl $str_002a9af0, 4(%esp)\n" /* "pswrd" */
        "leal -0x2828(%ebp), %eax\n" /* infostring */
        "movl %eax, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "jmp .Lf159918_00159b39\n"
        ".Lf159918_00159cce:\n"
        "movl %eax, (%esp)\n" /* line 536 */
        "calll SV_Cmd_TokenizeString\n"
        "calll SV_Cmd_Argc\n" /* line 537 */
        "movl %eax, %esi\n" /* count */
        "testl %eax, %eax\n" /* line 538 */
        "jle .Lf159918_00159c4d\n"
        "xorl %ebx, %ebx\n" /* line 537 | cl */
        ".Lf159918_00159ce7:\n"
        "movl %ebx, (%esp)\n" /* line 540 | cl */
        "calll SV_Cmd_Argv\n"
        "movl $str_00216f3c, 4(%esp)\n" /* "main" */
        "movl %eax, (%esp)\n"
        "calll FS_iwIwd\n"
        "testl %eax, %eax\n"
        "je .Lf159918_00159b63\n"
        "addl $1, %ebx\n" /* line 538 | cl */
        "cmpl %ebx, %esi\n" /* cl, count */
        "jne .Lf159918_00159ce7\n"
        "xorl %eax, %eax\n"
        "jmp .Lf159918_00159b68\n"
        "movl %eax, %ebx\n" /* cl */
        "leal -0x1c(%ebp), %edx\n" /* line 552 | status_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll __Unwind_Resume\n"
    );
}

/* line 564 */
__attribute__((naked))
long int SVC_GameCompleteStatus(netadr_t from)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 564 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc5c, %esp\n"
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0xc2e(%ebp)\n"
        "movzbl 0xf(%ebp), %edx\n"
        "movb %dl, -0xc2f(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0xc30(%ebp)\n"
        "movzbl 0xd(%ebp), %edx\n"
        "movb %dl, -0xc31(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0xc32(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* from */
        "movl %edx, -0xc38(%ebp)\n"
        /* { scope 1: keywords */
        "movl $0x4000, 4(%esp)\n" /* line 567 */
        "leal -0x1c(%ebp), %eax\n" /* status_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* status_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0xc44(%ebp)\n" /* status */
        "movl $0x404, (%esp)\n" /* line 575 */
        "calll Dvar_InfoString\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x828(%ebp), %eax\n" /* infostring */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl $1, (%esp)\n" /* line 579 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9338, 4(%esp)\n" /* "challenge" */
        "leal -0x828(%ebp), %edx\n" /* infostring */
        "movl %edx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl $str_00216d6c, (%esp)\n" /* line 582 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "jne .Lf159d2a_00159f91\n"
        ".Lf159d2a_00159ded:\n"
        "movl -0xc44(%ebp), %eax\n" /* line 590 | status */
        "movb $0, (%eax)\n"
        "movl sv_maxclients, %eax\n" /* line 593 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf159d2a_00159efd\n"
        "movl $0, -0xc3c(%ebp)\n" /* statusLength */
        "movl $0, -0xc40(%ebp)\n" /* i */
        "movl $0, -0xc2c(%ebp)\n"
        ".Lf159d2a_00159e24:\n"
        "movl -0xc2c(%ebp), %ebx\n" /* line 595 | cl */
        "addl svs+12, %ebx\n" /* cl */
        "cmpl $1, (%ebx)\n" /* line 596 | cl */
        "jle .Lf159d2a_00159edd\n"
        "movl -0xc40(%ebp), %edx\n" /* line 598 | i */
        "movl %edx, (%esp)\n"
        "calll SV_GameClientNum\n"
        "leal 0x20c48(%ebx), %esi\n" /* line 599 | cl */
        "movl 0x6e5a4(%ebx), %edi\n" /* cl */
        "subl svs+12, %ebx\n" /* cl */
        "sarl $2, %ebx\n" /* cl */
        "imull $0x3789a4eb, %ebx, %eax\n" /* cl */
        "movl %eax, (%esp)\n"
        "calll G_GetClientScore\n"
        "movl %esi, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002ab484, 8(%esp)\n" /* "%i %i "%s"
" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x428(%ebp), %eax\n" /* player */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "cld\n" /* line 600 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x428(%ebp), %edi\n" /* player */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0xc3c(%ebp), %edx\n" /* statusLength */
        "leal -1(%ecx, %edx), %ebx\n" /* cl */
        "cmpl $0x3fff, %ebx\n" /* line 601 | cl */
        "ja .Lf159d2a_00159efd\n"
        "leal -0x428(%ebp), %eax\n" /* line 605 | player */
        "movl %eax, 4(%esp)\n"
        "movl -0xc44(%ebp), %eax\n" /* status */
        "addl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl %ebx, -0xc3c(%ebp)\n" /* cl, statusLength */
        "movl sv_maxclients, %eax\n"
        ".Lf159d2a_00159edd:\n"
        "addl $1, -0xc40(%ebp)\n" /* line 593 | i */
        "addl $0x78f0c, -0xc2c(%ebp)\n"
        "movl -0xc40(%ebp), %edx\n" /* i */
        "cmpl 8(%eax), %edx\n"
        "jl .Lf159d2a_00159e24\n"
        ".Lf159d2a_00159efd:\n"
        "movl -0xc44(%ebp), %eax\n" /* line 610 | status */
        "movl %eax, 8(%esp)\n"
        "leal -0x828(%ebp), %edx\n" /* infostring */
        "movl %edx, 4(%esp)\n"
        "movl $str_002ab4b4, (%esp)\n" /* "gameCompleteStatus
%s
%s" */
        "calll va\n"
        "movzwl -0xc2e(%ebp), %edx\n"
        "movw %dx, -0x20(%ebp)\n"
        "movzbl -0xc2f(%ebp), %edx\n"
        "movb %dl, -0x21(%ebp)\n"
        "movzbl -0xc30(%ebp), %edx\n"
        "movb %dl, -0x22(%ebp)\n"
        "movzbl -0xc31(%ebp), %edx\n"
        "movb %dl, -0x23(%ebp)\n"
        "movzbl -0xc32(%ebp), %edx\n"
        "movb %dl, -0x24(%ebp)\n"
        "movl -0xc38(%ebp), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "leal -0x1c(%ebp), %edx\n" /* status_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0xc5c, %esp\n" /* line 611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keywords */
        /* { scope 2 */
        ".Lf159d2a_00159f91:\n"
        "movl $str_002a710c, 4(%esp)\n" /* line 586 */
        "leal -0x828(%ebp), %eax\n" /* infostring */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002ab47c, 8(%esp)\n" /* "demo %s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0xc28(%ebp), %ebx\n" /* keywords, cl */
        "movl %ebx, (%esp)\n" /* cl */
        "calll Com_sprintf\n"
        "movl %ebx, 8(%esp)\n" /* line 587 | cl */
        "movl $str_002a710c, 4(%esp)\n" /* "sv_keywords" */
        "leal -0x828(%ebp), %edx\n" /* infostring */
        "movl %edx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "jmp .Lf159d2a_00159ded\n"
        "movl %eax, %ebx\n" /* cl */
        /* } scope */
        "leal -0x1c(%ebp), %eax\n" /* line 610 | status_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll __Unwind_Resume\n"
    );
}

/* line 622 */
__attribute__((naked))
long int SVC_Info(netadr_t from)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 622 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x84c, %esp\n"
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x82a(%ebp)\n"
        "movzbl 0xf(%ebp), %eax\n"
        "movb %al, -0x82b(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x82c(%ebp)\n"
        "movzbl 0xd(%ebp), %eax\n"
        "movb %al, -0x82d(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x82e(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* from */
        "movl %eax, -0x834(%ebp)\n"
        /* { scope 1 */
        "movl sv_privateClients, %eax\n" /* line 659 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf159ffe_0015a4af\n"
        "xorl %edi, %edi\n" /* count */
        ".Lf159ffe_0015a057:\n"
        "movl sv_maxclients, %eax\n" /* line 669 */
        "movl 8(%eax), %esi\n"
        "cmpl %esi, %ecx\n"
        "jl .Lf159ffe_0015a472\n"
        "movl %edi, %ebx\n" /* count, gamedir */
        ".Lf159ffe_0015a069:\n"
        "movb $0, -0x424(%ebp)\n" /* line 677 | infostring */
        "movl $1, (%esp)\n" /* line 681 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9338, 4(%esp)\n" /* "challenge" */
        "leal -0x424(%ebp), %esi\n" /* infostring */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl $0x73, 4(%esp)\n" /* line 683 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a7118, 4(%esp)\n" /* "protocol" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_hostname, %eax\n" /* line 684 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002aa89c, 4(%esp)\n" /* "hostname" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_mapname, %eax\n" /* line 685 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a7124, 4(%esp)\n" /* "mapname" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "testl %ebx, %ebx\n" /* line 687 | gamedir */
        "jne .Lf159ffe_0015a542\n"
        ".Lf159ffe_0015a0fe:\n"
        "movl sv_privateClients, %eax\n" /* line 690 */
        "movl 8(%eax), %eax\n"
        "subl %edi, %eax\n" /* count */
        "movl sv_maxclients, %edx\n"
        "movl 8(%edx), %edx\n"
        "subl %eax, %edx\n"
        "testl %edx, %edx\n" /* line 691 */
        "jle .Lf159ffe_0015a13b\n"
        "movl %edx, 4(%esp)\n" /* line 692 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a70dc, 4(%esp)\n" /* "sv_maxclients" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        ".Lf159ffe_0015a13b:\n"
        "movl sv_gametype, %eax\n" /* line 694 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002aa884, 4(%esp)\n" /* "gametype" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_pure, %eax\n" /* line 697 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf159ffe_0015a352\n"
        "movl imp_fs_numServerIwds, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf159ffe_0015a352\n"
        "movl sv_minPing, %eax\n" /* line 701 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf159ffe_0015a37a\n"
        ".Lf159ffe_0015a185:\n"
        "movl sv_maxPing, %eax\n" /* line 704 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf159ffe_0015a3ae\n"
        ".Lf159ffe_0015a195:\n"
        "movl $str_00216d64, (%esp)\n" /* line 707 */
        "calll Dvar_GetString\n"
        "movl %eax, %ebx\n" /* gamedir */
        "cmpb $0, (%eax)\n" /* line 708 */
        "jne .Lf159ffe_0015a3e9\n"
        ".Lf159ffe_0015a1ac:\n"
        "movl sv_allowAnonymous, %eax\n" /* line 711 */
        "movzbl 8(%eax), %eax\n"
        "testb %al, %al\n"
        "jne .Lf159ffe_0015a40e\n"
        ".Lf159ffe_0015a1bd:\n"
        "movl sv_disableClientConsole, %eax\n" /* line 714 */
        "movzbl 8(%eax), %eax\n"
        "testb %al, %al\n"
        "jne .Lf159ffe_0015a446\n"
        ".Lf159ffe_0015a1ce:\n"
        "movl $str_002ab490, (%esp)\n" /* line 717 */
        "calll Dvar_GetString\n"
        "testl %eax, %eax\n" /* line 718 */
        "je .Lf159ffe_0015a1e7\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf159ffe_0015a578\n"
        ".Lf159ffe_0015a1e7:\n"
        "movl $str_002ab4f0, (%esp)\n" /* line 721 */
        "calll Dvar_GetInt\n"
        "testl %eax, %eax\n" /* line 722 */
        "jne .Lf159ffe_0015a519\n"
        ".Lf159ffe_0015a1fb:\n"
        "movl $str_002a9d04, (%esp)\n" /* line 725 */
        "calll Dvar_GetInt\n"
        "testl %eax, %eax\n" /* line 726 */
        "jne .Lf159ffe_0015a4f0\n"
        ".Lf159ffe_0015a20f:\n"
        "movl imp_com_dedicated, %eax\n" /* line 730 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf159ffe_0015a225\n"
        "movl 8(%eax), %edi\n" /* count */
        "testl %edi, %edi\n" /* count */
        "jne .Lf159ffe_0015a56b\n"
        ".Lf159ffe_0015a225:\n"
        "movl $5, 4(%esp)\n" /* line 732 */
        ".Lf159ffe_0015a22d:\n"
        "movl $str_0021785c, (%esp)\n" /* line 736 */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002aa878, 4(%esp)\n" /* "hw" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_pure, %eax\n" /* line 763 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf159ffe_0015a261\n"
        "cmpb $0, (%ebx)\n" /* gamedir */
        "je .Lf159ffe_0015a4d4\n"
        ".Lf159ffe_0015a261:\n"
        "movl $1, %eax\n" /* line 774 */
        ".Lf159ffe_0015a266:\n"
        "movl %eax, 4(%esp)\n" /* line 785 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9cf4, 4(%esp)\n" /* "mod" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_voice, %eax\n" /* line 789 */
        "movzbl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021ec00, 4(%esp)\n" /* "voice" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl $0x400, 8(%esp)\n" /* line 825 */
        "movl $str_002ab504, 4(%esp)\n" /* "infoResponse
" */
        "leal -0x824(%ebp), %ebx\n" /* response, gamedir */
        "movl %ebx, (%esp)\n" /* gamedir */
        "calll I_strncpyz\n"
        "movl %esi, 8(%esp)\n" /* line 826 */
        "movl $0x400, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* gamedir */
        "calll I_strncat\n"
        "movzwl -0x82a(%ebp), %eax\n" /* line 827 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzbl -0x82b(%ebp), %eax\n"
        "movb %al, -0x1d(%ebp)\n"
        "movzbl -0x82c(%ebp), %eax\n"
        "movb %al, -0x1e(%ebp)\n"
        "movzbl -0x82d(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x82e(%ebp), %eax\n"
        "movb %al, -0x20(%ebp)\n"
        "movl -0x834(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %ebx, 0x10(%esp)\n" /* gamedir */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        "addl $0x84c, %esp\n" /* line 828 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf159ffe_0015a352:\n"
        "movl $str_002162ac, 8(%esp)\n" /* line 698 */
        "movl $str_002aa870, 4(%esp)\n" /* "pure" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_minPing, %eax\n" /* line 701 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf159ffe_0015a185\n"
        ".Lf159ffe_0015a37a:\n"
        "movl %eax, 4(%esp)\n" /* line 702 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002ab4d0, 4(%esp)\n" /* "minPing" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_maxPing, %eax\n" /* line 704 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf159ffe_0015a195\n"
        ".Lf159ffe_0015a3ae:\n"
        "movl %eax, 4(%esp)\n" /* line 705 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002ab4d8, 4(%esp)\n" /* "maxPing" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl $str_00216d64, (%esp)\n" /* line 707 */
        "calll Dvar_GetString\n"
        "movl %eax, %ebx\n" /* gamedir */
        "cmpb $0, (%eax)\n" /* line 708 */
        "je .Lf159ffe_0015a1ac\n"
        ".Lf159ffe_0015a3e9:\n"
        "movl %eax, 8(%esp)\n" /* line 709 */
        "movl $str_002aa890, 4(%esp)\n" /* "game" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_allowAnonymous, %eax\n" /* line 711 */
        "movzbl 8(%eax), %eax\n"
        "testb %al, %al\n"
        "je .Lf159ffe_0015a1bd\n"
        ".Lf159ffe_0015a40e:\n"
        "movzbl %al, %eax\n" /* line 712 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a718c, 4(%esp)\n" /* "sv_allowAnonymous" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl sv_disableClientConsole, %eax\n" /* line 714 */
        "movzbl 8(%eax), %eax\n"
        "testb %al, %al\n"
        "je .Lf159ffe_0015a1ce\n"
        ".Lf159ffe_0015a446:\n"
        "movzbl %al, %eax\n" /* line 715 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002ab4e0, 4(%esp)\n" /* "con_disabled" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "jmp .Lf159ffe_0015a1ce\n"
        ".Lf159ffe_0015a472:\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 669 */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl svs+12, %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edi, %ebx\n" /* count, gamedir */
        ".Lf159ffe_0015a494:\n"
        "leal 1(%ebx), %eax\n" /* line 673 | gamedir */
        "cmpl $2, (%edx)\n"
        "cmovgel %eax, %ebx\n" /* gamedir */
        "addl $1, %ecx\n" /* line 669 */
        "addl $0x78f0c, %edx\n"
        "cmpl %ecx, %esi\n"
        "jg .Lf159ffe_0015a494\n"
        "jmp .Lf159ffe_0015a069\n"
        ".Lf159ffe_0015a4af:\n"
        "movl svs+12, %edx\n" /* line 659 */
        "xorl %ebx, %ebx\n" /* gamedir */
        "xorl %edi, %edi\n" /* count */
        ".Lf159ffe_0015a4b9:\n"
        "leal 1(%edi), %eax\n" /* line 663 | count */
        "cmpl $2, (%edx)\n"
        "cmovgel %eax, %edi\n" /* count */
        "addl $1, %ebx\n" /* line 659 | gamedir */
        "addl $0x78f0c, %edx\n"
        "cmpl %ebx, %ecx\n" /* gamedir */
        "jne .Lf159ffe_0015a4b9\n"
        "jmp .Lf159ffe_0015a057\n"
        ".Lf159ffe_0015a4d4:\n"
        "movl $str_002a7220, (%esp)\n" /* line 769 */
        "calll Dvar_GetString\n"
        "cmpb $0, (%eax)\n" /* line 770 */
        "jne .Lf159ffe_0015a595\n"
        ".Lf159ffe_0015a4e9:\n"
        "xorl %eax, %eax\n" /* line 774 */
        "jmp .Lf159ffe_0015a266\n"
        ".Lf159ffe_0015a4f0:\n"
        "movl %eax, 4(%esp)\n" /* line 727 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002aa880, 4(%esp)\n" /* "kc" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "jmp .Lf159ffe_0015a20f\n"
        ".Lf159ffe_0015a519:\n"
        "movl %eax, 4(%esp)\n" /* line 723 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002aa87c, 4(%esp)\n" /* "ff" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "jmp .Lf159ffe_0015a1fb\n"
        ".Lf159ffe_0015a542:\n"
        "movl %ebx, 4(%esp)\n" /* line 688 | gamedir */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a8a54, 4(%esp)\n" /* "clients" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "jmp .Lf159ffe_0015a0fe\n"
        ".Lf159ffe_0015a56b:\n"
        "movl $2, 4(%esp)\n" /* line 736 */
        "jmp .Lf159ffe_0015a22d\n"
        ".Lf159ffe_0015a578:\n"
        "movl $str_002162ac, 8(%esp)\n" /* line 719 */
        "movl $str_002a9af0, 4(%esp)\n" /* "pswrd" */
        "movl %esi, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "jmp .Lf159ffe_0015a1e7\n"
        ".Lf159ffe_0015a595:\n"
        "movl %eax, (%esp)\n" /* line 772 */
        "calll SV_Cmd_TokenizeString\n"
        "calll SV_Cmd_Argc\n" /* line 773 */
        "movl %eax, %edi\n" /* count */
        "testl %eax, %eax\n" /* line 774 */
        "jle .Lf159ffe_0015a4e9\n"
        "xorl %ebx, %ebx\n" /* gamedir */
        ".Lf159ffe_0015a5ae:\n"
        "movl %ebx, (%esp)\n" /* line 776 | gamedir */
        "calll SV_Cmd_Argv\n"
        "movl $str_00216f3c, 4(%esp)\n" /* "main" */
        "movl %eax, (%esp)\n"
        "calll FS_iwIwd\n"
        "testl %eax, %eax\n"
        "je .Lf159ffe_0015a261\n"
        "addl $1, %ebx\n" /* line 774 | gamedir */
        "cmpl %ebx, %edi\n" /* gamedir, count */
        "jne .Lf159ffe_0015a5ae\n"
        "xorl %eax, %eax\n"
        "jmp .Lf159ffe_0015a266\n"
    );
}

/* line 893 */
__attribute__((naked))
long int SV_ConnectionlessPacket(netadr_t from, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 893 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 0x14(%ebp), %esi\n" /* msg */
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x7a(%ebp)\n"
        "movzbl 0xf(%ebp), %eax\n"
        "movb %al, -0x7b(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x7c(%ebp)\n"
        "movzbl 0xd(%ebp), %eax\n"
        "movb %al, -0x7d(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x7e(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* from */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 904 | msg */
        "calll MSG_BeginReading\n"
        "movl %esi, (%esp)\n" /* line 905 | msg */
        "calll MSG_ReadLong\n"
        "movl 0xc(%esi), %eax\n" /* line 908 | msg */
        "movl %eax, (%esp)\n"
        "calll SV_Netchan_AddOOBProfilePacket\n"
        "movl %esi, (%esp)\n" /* line 910 | msg */
        "calll MSG_ReadStringLine\n"
        "movl %eax, (%esp)\n" /* line 912 */
        "calll SV_Cmd_TokenizeString\n"
        "movl $0, (%esp)\n" /* line 914 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, %ebx\n" /* c */
        "movl sv_packet_info, %eax\n" /* line 916 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf15a5dc_0015a783\n"
        ".Lf15a5dc_0015a659:\n"
        "movl $str_002a9440, 4(%esp)\n" /* line 919 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf15a5dc_0015a6b5\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 922 */
        "movw %ax, -0x64(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x65(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x66(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x67(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x68(%ebp)\n"
        "movl %edi, -0x6c(%ebp)\n"
        "movl %esi, 0x14(%ebp)\n" /* msg */
        "movl %edi, 8(%ebp)\n" /* from */
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_VoicePacket\n" /* line 922 */
        ".Lf15a5dc_0015a6b5:\n"
        "movl $str_002ab528, 4(%esp)\n" /* line 928 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf15a5dc_0015a73e\n"
        "movl $str_002ab534, 4(%esp)\n" /* line 932 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf15a5dc_0015a7d9\n"
        "movl $str_002a9328, 4(%esp)\n" /* line 947 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf15a5dc_0015a81e\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 949 */
        "movw %ax, -0x40(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x41(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x42(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x43(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x44(%ebp)\n"
        "movl %edi, -0x48(%ebp)\n"
        "movl %edi, 8(%ebp)\n" /* from */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_GetChallenge\n" /* line 949 */
        ".Lf15a5dc_0015a73e:\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 930 */
        "movw %ax, -0x58(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x59(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x5a(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x5b(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x5c(%ebp)\n"
        "movl %edi, -0x60(%ebp)\n"
        "movl %edi, 8(%ebp)\n" /* from */
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SVC_Status\n" /* line 930 */
        ".Lf15a5dc_0015a783:\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 917 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x1d(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x1e(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x20(%ebp)\n"
        "movl %edi, -0x24(%ebp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %ebx, 8(%esp)\n" /* c */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab514, (%esp)\n" /* "SV packet %s : %s
" */
        "calll Com_Printf\n"
        "jmp .Lf15a5dc_0015a659\n"
        ".Lf15a5dc_0015a7d9:\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 945 */
        "movw %ax, -0x4c(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x4d(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x4e(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x4f(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x50(%ebp)\n"
        "movl %edi, -0x54(%ebp)\n"
        "movl %edi, 8(%ebp)\n" /* from */
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SVC_Info\n" /* line 945 */
        ".Lf15a5dc_0015a81e:\n"
        "movl $str_002a90c0, 4(%esp)\n" /* line 951 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf15a5dc_0015a88f\n"
        "movl $str_002ab53c, 4(%esp)\n" /* line 956 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf15a5dc_0015a8d4\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 958 */
        "movw %ax, -0x28(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x29(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x2a(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movl %edi, -0x30(%ebp)\n"
        "movl %edi, 8(%ebp)\n" /* from */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_AuthorizeIpPacket\n" /* line 958 */
        ".Lf15a5dc_0015a88f:\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 953 */
        "movw %ax, -0x34(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x35(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x36(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x37(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x38(%ebp)\n"
        "movl %edi, -0x3c(%ebp)\n"
        "movl %edi, 8(%ebp)\n" /* from */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_DirectConnect\n" /* line 953 */
        ".Lf15a5dc_0015a8d4:\n"
        "movl $str_002a6fbc, 4(%esp)\n" /* line 962 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf15a5dc_0015a930\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 964 */
        "movw %ax, -0x70(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x71(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x72(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x73(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x74(%ebp)\n"
        "movl %edi, -0x78(%ebp)\n"
        "movl %esi, 0x14(%ebp)\n" /* msg */
        "movl %edi, 8(%ebp)\n" /* from */
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SVC_RemoteCommand\n" /* line 964 */
        ".Lf15a5dc_0015a930:\n"
        "movl $str_00228e90, 4(%esp)\n" /* line 975 */
        "movl %ebx, (%esp)\n" /* c */
        "calll I_stricmp\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 998 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1013 */
__attribute__((naked))
long int SV_PacketEvent(netadr_t from, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1013 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* msg */
        "movl %eax, -0x58(%ebp)\n" /* msg */
        "movzbl 0xf(%ebp), %edx\n"
        "movb %dl, -0x49(%ebp)\n"
        "movzbl 0xe(%ebp), %ecx\n"
        "movb %cl, -0x4a(%ebp)\n"
        "movzbl 0xd(%ebp), %eax\n"
        "movb %al, -0x4b(%ebp)\n"
        "movzbl 0xc(%ebp), %edx\n"
        "movb %dl, -0x4c(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* from */
        "movl 0x10(%ebp), %ecx\n"
        "movw %cx, -0x4e(%ebp)\n"
        /* { scope 1 */
        "movl -0x58(%ebp), %eax\n" /* line 1024 | msg */
        "cmpl $3, 0xc(%eax)\n"
        "jle .Lf15a94c_0015a996\n"
        "movl 4(%eax), %eax\n"
        "cmpl $-1, (%eax)\n"
        "je .Lf15a94c_0015aad9\n"
        ".Lf15a94c_0015a996:\n"
        "calll SV_ResetSkeletonCache\n" /* line 1030 */
        "movl -0x58(%ebp), %ecx\n" /* line 1034 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_BeginReading\n"
        "movl -0x58(%ebp), %eax\n" /* line 1035 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl -0x58(%ebp), %edx\n" /* line 1037 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadShort\n"
        "andl $0xffff, %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* qport */
        "movl svs+12, %ebx\n" /* line 1041 | cl */
        "movl sv_maxclients, %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf15a94c_0015aa84\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf15a94c_0015a9f0\n"
        ".Lf15a94c_0015a9de:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x78f0c, %ebx\n" /* cl */
        "cmpl 8(%eax), %esi\n" /* i */
        "jge .Lf15a94c_0015aa84\n"
        ".Lf15a94c_0015a9f0:\n"
        "movl (%ebx), %edx\n" /* line 1043 | cl */
        "testl %edx, %edx\n"
        "je .Lf15a94c_0015a9de\n"
        "movl 0x6e5c4(%ebx), %ecx\n" /* line 1047 | cl */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 0x6e5c8(%ebx), %edx\n" /* cl */
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* cl */
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, -0x34(%ebp)\n"
        "movzbl -0x49(%ebp), %eax\n"
        "movb %al, -0x29(%ebp)\n"
        "movzbl -0x4a(%ebp), %eax\n"
        "movb %al, -0x2a(%ebp)\n"
        "movzbl -0x4b(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movzbl -0x4c(%ebp), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movl %edi, -0x30(%ebp)\n"
        "movzwl -0x4e(%ebp), %eax\n"
        "movw %ax, -0x28(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "je .Lf15a94c_0015aa6d\n"
        "movl -0x54(%ebp), %edx\n" /* line 1055 | qport */
        "cmpl 0x6e5d0(%ebx), %edx\n" /* cl */
        "je .Lf15a94c_0015ab1e\n"
        ".Lf15a94c_0015aa6d:\n"
        "movl sv_maxclients, %eax\n"
        "addl $1, %esi\n" /* line 1041 | i */
        "addl $0x78f0c, %ebx\n" /* cl */
        "cmpl 8(%eax), %esi\n" /* i */
        "jl .Lf15a94c_0015a9f0\n"
        ".Lf15a94c_0015aa84:\n"
        "movzbl -0x49(%ebp), %edx\n" /* line 1117 */
        "movb %dl, -0x1d(%ebp)\n"
        "movzbl -0x4a(%ebp), %ecx\n"
        "movb %cl, -0x1e(%ebp)\n"
        "movzbl -0x4b(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x4c(%ebp), %edx\n"
        "movb %dl, -0x20(%ebp)\n"
        "movl %edi, -0x24(%ebp)\n"
        "movzwl -0x4e(%ebp), %ecx\n"
        "movw %cx, -0x1c(%ebp)\n"
        "movl $str_00228e90, 0x10(%esp)\n" /* "disconnect" */
        "movl %edi, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        ".Lf15a94c_0015aad1:\n"
        "addl $0x6c, %esp\n" /* line 1118 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15a94c_0015aad9:\n"
        "movzbl -0x49(%ebp), %ecx\n" /* line 1026 */
        "movb %cl, -0x41(%ebp)\n"
        "movzbl -0x4a(%ebp), %eax\n"
        "movb %al, -0x42(%ebp)\n"
        "movzbl -0x4b(%ebp), %edx\n"
        "movb %dl, -0x43(%ebp)\n"
        "movzbl -0x4c(%ebp), %ecx\n"
        "movb %cl, -0x44(%ebp)\n"
        "movl %edi, -0x48(%ebp)\n"
        "movzwl -0x4e(%ebp), %eax\n"
        "movw %ax, -0x40(%ebp)\n"
        "movl -0x58(%ebp), %edx\n" /* msg */
        "movl %edx, 0x14(%ebp)\n" /* msg */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1118 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_ConnectionlessPacket\n" /* line 1026 */
        ".Lf15a94c_0015ab1e:\n"
        "movzwl -0x4e(%ebp), %ecx\n" /* line 1063 */
        "cmpw %cx, 0x6e5cc(%ebx)\n" /* cl */
        "je .Lf15a94c_0015ab42\n"
        "movl $str_002ab44c, (%esp)\n" /* line 1065 */
        "calll Com_Printf\n"
        "movzwl -0x4e(%ebp), %eax\n" /* line 1066 */
        "movw %ax, 0x6e5cc(%ebx)\n" /* cl */
        ".Lf15a94c_0015ab42:\n"
        "movl -0x58(%ebp), %edx\n" /* line 1071 | msg */
        "movl %edx, 4(%esp)\n"
        "leal 0x6e5b4(%ebx), %eax\n" /* cl */
        "movl %eax, (%esp)\n"
        "calll Netchan_Process\n"
        /* DEBUG: save netchan result for diagnostic */
        "movl %eax, -0x50(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf15a94c_0015aad1\n"
        "movl -0x58(%ebp), %ecx\n" /* line 1073 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadByte\n"
        "movl %eax, 0x765f8(%ebx)\n" /* cl */
        "movl -0x58(%ebp), %eax\n" /* line 1074 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, 0x20818(%ebx)\n" /* cl */
        /* DEBUG: print packet info */
        "pushl %eax\n"
        "pushl %ebx\n"
        "pushl %eax\n" /* relAck */
        "pushl 0x765f8(%ebx)\n" /* serverId */
        "pushl (%ebx)\n" /* clState */
        "pushl -0x50(%ebp)\n" /* netchanResult */
        "pushl $.Lsvpkt_fmt\n"
        "calll SV_PktEvtDbg\n"
        "addl $20, %esp\n"
        "popl %ebx\n"
        "popl %eax\n"
        "testl %eax, %eax\n" /* line 1076 */
        "js .Lf15a94c_0015aad1\n"
        "movl -0x58(%ebp), %edx\n" /* line 1084 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, 0x20810(%ebx)\n" /* cl */
        "movl 0x20814(%ebx), %edx\n" /* line 1089 | cl */
        "movl %edx, %ecx\n"
        "subl %eax, %ecx\n"
        "cmpl $0x7f, %ecx\n"
        "jle .Lf15a94c_0015abb4\n"
        "movl %edx, 0x20810(%ebx)\n" /* line 1094 | cl */
        "jmp .Lf15a94c_0015aad1\n"
        ".Lf15a94c_0015abb4:\n"
        "movl -0x58(%ebp), %eax\n" /* line 1099 | msg */
        "movl 0x10(%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movl 0xc(%eax), %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "addl 4(%ecx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_Netchan_Decode\n"
        "cmpl $1, (%ebx)\n" /* line 1105 | cl */
        "je .Lf15a94c_0015aad1\n"
        "movl svs+4, %eax\n" /* line 1107 */
        "movl %eax, 0x20d10(%ebx)\n" /* cl */
        "movl -0x58(%ebp), %eax\n" /* line 1108 | msg */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_ExecuteClientMessage\n"
        "movl imp_bgs, %eax\n" /* line 1109 */
        "movl $0, (%eax)\n"
        "jmp .Lf15a94c_0015aad1\n"
    );
}

/* line 1190 */
long int SV_FreeClientScriptId(client_t *cl)
{
    Scr_FreeValue(*(unsigned short *)((byte *)cl + 0x765f0));
    *(unsigned short *)((byte *)cl + 0x765f0) = 0;
    return 0;
}

/* line 1329 */
long int SV_RunFrame(void)
{
    SV_ResetSkeletonCache();
    G_RunFrame(*(int *)((char *)&svs + 4));
    return 0;
}

/* line 1356 */
__attribute__((naked))
long int SV_BotUserMove(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1356 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cl */
        /* { scope 1 */
        "movl 0x20c44(%ebx), %eax\n" /* line 1360 | cl */
        "testl %eax, %eax\n"
        "je .Lf15ac4a_0015acc9\n"
        "leal -0x34(%ebp), %esi\n" /* line 1363 | nullcmd */
        "cld\n"
        "movl $7, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl %ebx, %eax\n" /* line 1364 | cl */
        "subl svs+12, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameClientNum\n"
        "movl 0xd4(%eax), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movl %ebx, %eax\n" /* line 1367 | cl */
        "subl svs+12, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_GetClientArchiveTime\n"
        "testl %eax, %eax\n"
        "je .Lf15ac4a_0015acd1\n"
        ".Lf15ac4a_0015acae:\n"
        "movl 0x6e5b4(%ebx), %eax\n" /* line 1392 | cl */
        "subl $1, %eax\n"
        "movl %eax, 0x20d08(%ebx)\n" /* cl */
        "movl %esi, 4(%esp)\n" /* line 1394 */
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_ClientThink\n"
        /* } scope */
        ".Lf15ac4a_0015acc9:\n"
        "addl $0x7c, %esp\n" /* line 1395 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15ac4a_0015acd1:\n"
        "calll randomf\n" /* line 1369 */
        "fstps -0x5c(%ebp)\n"
        "movss -0x5c(%ebp), %xmm0\n"
        "ucomiss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "jae .Lf15ac4a_0015aced\n"
        "jp .Lf15ac4a_0015aced\n"
        "orl $1, -0x30(%ebp)\n" /* line 1370 */
        ".Lf15ac4a_0015aced:\n"
        "calll randomf\n" /* line 1371 */
        "fstps -0x58(%ebp)\n"
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "ucomiss -0x58(%ebp), %xmm0\n"
        "ja .Lf15ac4a_0015adbe\n"
        "calll randomf\n" /* line 1374 */
        "fstps -0x54(%ebp)\n"
        "movss -0x54(%ebp), %xmm0\n"
        "ucomiss lit4_002ed8ec, %xmm0\n" /* 0.33000001311302185f */
        "jae .Lf15ac4a_0015addc\n"
        ".Lf15ac4a_0015ad21:\n"
        "jp .Lf15ac4a_0015addc\n"
        "movb $0x7f, -0x1c(%ebp)\n" /* line 1375 */
        ".Lf15ac4a_0015ad2b:\n"
        "calll randomf\n" /* line 1379 */
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "ucomiss lit4_002ed8ec, %xmm0\n" /* 0.33000001311302185f */
        "jae .Lf15ac4a_0015ae4c\n"
        "jp .Lf15ac4a_0015ae4c\n"
        "movb $0x7f, -0x1b(%ebp)\n" /* line 1380 */
        ".Lf15ac4a_0015ad4f:\n"
        "calll randomf\n" /* line 1384 */
        "fstps -0x44(%ebp)\n"
        "movss -0x44(%ebp), %xmm0\n"
        "ucomiss lit4_002ed8ec, %xmm0\n" /* 0.33000001311302185f */
        "jb .Lf15ac4a_0015ae25\n"
        ".Lf15ac4a_0015ad69:\n"
        "calll randomf\n" /* line 1386 */
        "fstps -0x40(%ebp)\n"
        "movss lit4_002ed8ec, %xmm0\n" /* 0.33000001311302185f */
        "ucomiss -0x40(%ebp), %xmm0\n"
        "ja .Lf15ac4a_0015ae04\n"
        ".Lf15ac4a_0015ad83:\n"
        "calll randomf\n" /* line 1388 */
        "fstps -0x3c(%ebp)\n"
        "movss lit4_002ed8ec, %xmm0\n" /* 0.33000001311302185f */
        "ucomiss -0x3c(%ebp), %xmm0\n"
        "jbe .Lf15ac4a_0015acae\n"
        "calll crandom\n" /* line 1389 */
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "mulss lit4_002ed638, %xmm0\n" /* 360.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "jmp .Lf15ac4a_0015acae\n"
        ".Lf15ac4a_0015adbe:\n"
        "orl $0x28, -0x30(%ebp)\n" /* line 1372 */
        "calll randomf\n" /* line 1374 */
        "fstps -0x54(%ebp)\n"
        "movss -0x54(%ebp), %xmm0\n"
        "ucomiss lit4_002ed8ec, %xmm0\n" /* 0.33000001311302185f */
        "jb .Lf15ac4a_0015ad21\n"
        ".Lf15ac4a_0015addc:\n"
        "calll randomf\n" /* line 1376 */
        "fstps -0x50(%ebp)\n"
        "movl $0xffffff81, %eax\n" /* line 1377 */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "ucomiss -0x50(%ebp), %xmm0\n"
        "movzbl -0x1c(%ebp), %edx\n"
        "cmovbel %edx, %eax\n"
        "movb %al, -0x1c(%ebp)\n"
        "jmp .Lf15ac4a_0015ad2b\n"
        ".Lf15ac4a_0015ae04:\n"
        "calll crandom\n" /* line 1387 */
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "mulss lit4_002ed638, %xmm0\n" /* 360.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "jmp .Lf15ac4a_0015ad83\n"
        ".Lf15ac4a_0015ae25:\n"
        "jp .Lf15ac4a_0015ad69\n" /* line 1384 */
        "calll crandom\n" /* line 1385 */
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "mulss lit4_002ed638, %xmm0\n" /* 360.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "jmp .Lf15ac4a_0015ad69\n"
        ".Lf15ac4a_0015ae4c:\n"
        "calll randomf\n" /* line 1381 */
        "fstps -0x48(%ebp)\n"
        "movl $0xffffff81, %edx\n" /* line 1382 */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "ucomiss -0x48(%ebp), %xmm0\n"
        "movzbl -0x1b(%ebp), %eax\n"
        "cmovbel %eax, %edx\n"
        "movb %dl, -0x1b(%ebp)\n"
        "jmp .Lf15ac4a_0015ad4f\n"
    );
}

/* line 344 */
__attribute__((naked))
long int SV_SendServerCommand(client_t *cl, svscmd_type type, const char *fmt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 344 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cl */
        /* { scope 1 */
        "movl $0x4000, 4(%esp)\n" /* line 347 */
        "leal -0x20(%ebp), %eax\n" /* message_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x20(%ebp), %edi\n" /* message_large_local */
        "movl %edi, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x2c(%ebp)\n"
        "leal 0x14(%ebp), %eax\n" /* line 351 */
        "movl %eax, -0x1c(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 352 */
        "movl 0x10(%ebp), %eax\n" /* fmt */
        "movl %eax, 8(%esp)\n"
        "movl $0x4000, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll vsnprintf\n"
        "testl %ebx, %ebx\n" /* line 355 | client */
        "je .Lf15ae74_0015aef2\n"
        "movl -0x2c(%ebp), %edi\n" /* line 357 */
        "movl %edi, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* type */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll SV_AddServerCommand\n"
        "leal -0x20(%ebp), %edi\n" /* line 375 | message_large_local */
        "movl %edi, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 376 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15ae74_0015aef2:\n"
        "movl imp_com_dedicated, %eax\n" /* line 362 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf15ae74_0015af65\n"
        ".Lf15ae74_0015af00:\n"
        "movl svs+12, %ebx\n" /* line 368 | client */
        "movl sv_maxclients, %eax\n"
        "movl 8(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf15ae74_0015af52\n"
        "xorl %esi, %esi\n" /* j */
        "jmp .Lf15ae74_0015af24\n"
        ".Lf15ae74_0015af16:\n"
        "addl $1, %esi\n" /* j */
        "addl $0x78f0c, %ebx\n" /* client */
        "cmpl 8(%eax), %esi\n" /* j */
        "jge .Lf15ae74_0015af52\n"
        ".Lf15ae74_0015af24:\n"
        "cmpl $2, (%ebx)\n" /* line 370 | client */
        "jle .Lf15ae74_0015af16\n"
        "movl -0x2c(%ebp), %eax\n" /* line 374 */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edi\n" /* type */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll SV_AddServerCommand\n"
        "movl sv_maxclients, %eax\n"
        "addl $1, %esi\n" /* line 368 | j */
        "addl $0x78f0c, %ebx\n" /* client */
        "cmpl 8(%eax), %esi\n" /* j */
        "jl .Lf15ae74_0015af24\n"
        ".Lf15ae74_0015af52:\n"
        "leal -0x20(%ebp), %eax\n" /* line 375 | message_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 376 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15ae74_0015af65:\n"
        "movl $str_002a9590, %ebx\n" /* line 362 | client */
        "movl $5, %ecx\n"
        "cld\n"
        "movl -0x2c(%ebp), %esi\n" /* j */
        "movl %ebx, %edi\n" /* client */
        "repe cmpsb %es:(%edi), (%esi)\n" /* j */
        "movl $0, %edx\n"
        "je .Lf15ae74_0015af88\n"
        "movzbl -1(%esi), %edx\n" /* j */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf15ae74_0015af88:\n"
        "testl %edx, %edx\n"
        "jne .Lf15ae74_0015af00\n"
        "movl -0x2c(%ebp), %ecx\n"
        "xorl %ebx, %ebx\n" /* client */
        /* { scope 2 */
        ".Lf15ae74_0015af95:\n"
        "movzbl (%ecx), %edx\n" /* line 137 */
        "testb %dl, %dl\n"
        "je .Lf15ae74_0015afd4\n"
        "cmpl $0x3fc, %ebx\n" /* l */
        "ja .Lf15ae74_0015afd4\n"
        "cmpb $0xa, %dl\n" /* line 139 */
        "je .Lf15ae74_0015afbe\n"
        "leal -0x14(%edx), %eax\n" /* line 147 */
        "cmpb $1, %al\n"
        "jbe .Lf15ae74_0015afb9\n"
        "movb %dl, string(%ebx)\n" /* line 153 | l */
        "addl $1, %ebx\n" /* l */
        ".Lf15ae74_0015afb9:\n"
        "addl $1, %ecx\n" /* line 155 */
        "jmp .Lf15ae74_0015af95\n"
        ".Lf15ae74_0015afbe:\n"
        "movb $0x5c, string(%ebx)\n" /* line 141 | l */
        "movb $0x6e, string+1(%ebx)\n" /* line 142 | l */
        "addl $2, %ebx\n" /* l */
        "addl $1, %ecx\n" /* line 155 */
        "jmp .Lf15ae74_0015af95\n"
        ".Lf15ae74_0015afd4:\n"
        "movb $0, string(%ebx)\n" /* line 157 | l */
        /* } scope */
        "movl $string, 4(%esp)\n" /* line 364 */
        "movl $str_002ab580, (%esp)\n" /* "broadcast: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf15ae74_0015af00\n"
        "movl %eax, %ebx\n" /* client */
        "leal -0x20(%ebp), %eax\n" /* line 375 | message_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll __Unwind_Resume\n"
    );
}

/* line 1437 */
__attribute__((naked))
long int SV_Frame(int msec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1437 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl imp_legacyHacks, %ebx\n" /* line 1446 */
        "movl (%ebx), %eax\n"
        "cmpb $0, 0xdd(%eax)\n"
        "jne .Lf15b00a_0015b20c\n"
        "movl imp_com_sv_running, %eax\n" /* line 1456 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf15b00a_0015b204\n"
        "movl imp_cl_paused, %eax\n" /* line 1289 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf15b00a_0015b097\n"
        "movl svs+12, %edx\n" /* line 1296 */
        "movl sv_maxclients, %eax\n"
        "movl 8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf15b00a_0015b22a\n"
        "xorl %ebx, %ebx\n"
        "xorl %ecx, %ecx\n"
        ".Lf15b00a_0015b061:\n"
        "leal 1(%ecx), %eax\n" /* line 1300 */
        "cmpl $2, (%edx)\n"
        "cmovgel %eax, %ecx\n"
        "addl $1, %ebx\n" /* line 1296 */
        "addl $0x78f0c, %edx\n"
        "cmpl %ebx, %esi\n"
        "jne .Lf15b00a_0015b061\n"
        "subl $1, %ecx\n" /* line 1304 */
        "jle .Lf15b00a_0015b22a\n"
        "movl $0, 4(%esp)\n" /* line 1307 */
        "movl imp_sv_paused, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        ".Lf15b00a_0015b097:\n"
        "movl sv_fps, %ecx\n" /* line 1481 */
        "movl $0x3e8, %ebx\n"
        "movl %ebx, %eax\n"
        "cltd\n"
        "idivl 8(%ecx)\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 1483 | msec */
        "addl sv+16, %eax\n"
        "movl %eax, sv+16\n"
        "cmpl %eax, -0x68(%ebp)\n" /* line 1485 */
        "jg .Lf15b00a_0015b204\n"
        "cmpl $0x70000000, svs+4\n" /* line 1500 */
        "jg .Lf15b00a_0015b1c1\n"
        "movl $0x7ffffffe, %edx\n" /* line 1511 */
        "movl %edx, %eax\n"
        "subl svs+16, %eax\n"
        "cmpl %eax, svs+24\n"
        "jge .Lf15b00a_0015b274\n"
        "cmpl $0x7fffbffd, svs+60\n" /* line 1521 */
        "jg .Lf15b00a_0015b29f\n"
        "cmpl $0x7fffeffd, svs+64\n" /* line 1531 */
        "jg .Lf15b00a_0015b2ca\n"
        "cmpl $0x7ffffb4d, svs+44\n" /* line 1541 */
        "jg .Lf15b00a_0015b249\n"
        "cmpl $0x7dfffffd, svs+56\n" /* line 1551 */
        "jg .Lf15b00a_0015b4d0\n"
        "cmpl $0x7ffffdfd, svs+68\n" /* line 1561 */
        "jg .Lf15b00a_0015b4fb\n"
        "subl svs+20, %edx\n" /* line 1571 */
        "cmpl %edx, svs+28\n"
        "jge .Lf15b00a_0015b526\n"
        "movl imp_dvar_modifiedFlags, %ebx\n" /* line 1581 */
        "movl (%ebx), %eax\n"
        "testl $0x404, %eax\n"
        "jne .Lf15b00a_0015b5a0\n"
        ".Lf15b00a_0015b160:\n"
        "testb $8, %al\n" /* line 1586 */
        "jne .Lf15b00a_0015b578\n"
        ".Lf15b00a_0015b168:\n"
        "testb $1, %ah\n" /* line 1592 */
        "jne .Lf15b00a_0015b551\n"
        ".Lf15b00a_0015b171:\n"
        "calll SV_ResetSkeletonCache\n" /* line 1411 */
        "movl svs+12, %ebx\n" /* line 1413 */
        "movl sv_maxclients, %eax\n"
        "movl 8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf15b00a_0015b2f5\n"
        "xorl %esi, %esi\n"
        "jmp .Lf15b00a_0015b1a2\n"
        ".Lf15b00a_0015b190:\n"
        "addl $1, %esi\n"
        "addl $0x78f0c, %ebx\n"
        "cmpl 8(%eax), %esi\n"
        "jge .Lf15b00a_0015b2f5\n"
        ".Lf15b00a_0015b1a2:\n"
        "movl (%ebx), %ecx\n" /* line 1415 */
        "testl %ecx, %ecx\n"
        "je .Lf15b00a_0015b190\n"
        "movl 0x6e5c4(%ebx), %edx\n" /* line 1419 */
        "testl %edx, %edx\n"
        "jne .Lf15b00a_0015b190\n"
        "movl %ebx, (%esp)\n" /* line 1421 */
        "calll SV_BotUserMove\n"
        "movl sv_maxclients, %eax\n"
        "jmp .Lf15b00a_0015b190\n"
        ".Lf15b00a_0015b1c1:\n"
        "movl $0x40, 8(%esp)\n" /* line 1502 */
        "movl sv_mapname, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab590, (%esp)\n" /* line 1503 */
        ".Lf15b00a_0015b1e7:\n"
        "calll Com_Shutdown\n" /* line 1514 */
        "movl %ebx, 4(%esp)\n" /* line 1516 */
        "movl $str_002ab5ac, (%esp)\n" /* "map %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        /* } scope */
        ".Lf15b00a_0015b204:\n"
        "addl $0x7c, %esp\n" /* line 1651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15b00a_0015b20c:\n"
        "addl $0xde, %eax\n" /* line 1449 */
        "movl %eax, (%esp)\n"
        "calll Com_Shutdown\n"
        "movl (%ebx), %eax\n" /* line 1452 */
        "movb $0, 0xdd(%eax)\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15b00a_0015b22a:\n"
        "movl $1, 4(%esp)\n" /* line 1311 */
        "movl imp_sv_paused, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15b00a_0015b249:\n"
        "movl $0x40, 8(%esp)\n" /* line 1543 */
        "movl sv_mapname, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab644, (%esp)\n" /* line 1544 */
        "jmp .Lf15b00a_0015b1e7\n"
        ".Lf15b00a_0015b274:\n"
        "movl $0x40, 8(%esp)\n" /* line 1513 */
        "movl sv_mapname, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab5b4, (%esp)\n" /* line 1514 */
        "jmp .Lf15b00a_0015b1e7\n"
        ".Lf15b00a_0015b29f:\n"
        "movl $0x40, 8(%esp)\n" /* line 1523 */
        "movl sv_mapname, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab5e0, (%esp)\n" /* line 1524 */
        "jmp .Lf15b00a_0015b1e7\n"
        ".Lf15b00a_0015b2ca:\n"
        "movl $0x40, 8(%esp)\n" /* line 1533 */
        "movl sv_mapname, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab614, (%esp)\n" /* line 1534 */
        "jmp .Lf15b00a_0015b1e7\n"
        ".Lf15b00a_0015b2f5:\n"
        "movl 8(%eax), %eax\n" /* line 1135 */
        "testl %eax, %eax\n"
        "jle .Lf15b00a_0015b3af\n"
        "movl $0, -0x64(%ebp)\n"
        "movl $0, -0x5c(%ebp)\n"
        "jmp .Lf15b00a_0015b332\n"
        ".Lf15b00a_0015b310:\n"
        "movl $0x3e7, 0x6e5a4(%edi)\n" /* line 1170 */
        ".Lf15b00a_0015b31a:\n"
        "addl $1, -0x64(%ebp)\n" /* line 1135 */
        "addl $0x78f0c, -0x5c(%ebp)\n"
        "movl sv_maxclients, %eax\n"
        "movl -0x64(%ebp), %ecx\n"
        "cmpl 8(%eax), %ecx\n"
        "jge .Lf15b00a_0015b3af\n"
        ".Lf15b00a_0015b332:\n"
        "movl -0x5c(%ebp), %edi\n" /* line 1137 */
        "addl svs+12, %edi\n"
        "cmpl $4, (%edi)\n" /* line 1145 */
        "jne .Lf15b00a_0015b310\n"
        "movl 0x20c44(%edi), %eax\n" /* line 1150 */
        "testl %eax, %eax\n"
        "je .Lf15b00a_0015b310\n"
        "movl %edi, %ebx\n" /* line 1153 */
        "movl $0, -0x70(%ebp)\n"
        "movl $0, -0x6c(%ebp)\n"
        "movl $0x20, %esi\n"
        ".Lf15b00a_0015b35f:\n"
        "movl 0x233e0(%ebx), %ecx\n" /* line 1160 */
        "testl %ecx, %ecx\n"
        "jle .Lf15b00a_0015b376\n"
        "addl $1, -0x6c(%ebp)\n" /* line 1165 */
        "subl 0x233dc(%ebx), %ecx\n" /* line 1166 */
        "addl %ecx, -0x70(%ebp)\n"
        ".Lf15b00a_0015b376:\n"
        "addl $0x26c4, %ebx\n"
        "subl $1, %esi\n" /* line 1158 */
        "jne .Lf15b00a_0015b35f\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1168 */
        "testl %eax, %eax\n"
        "je .Lf15b00a_0015b310\n"
        "movl -0x70(%ebp), %eax\n" /* line 1174 */
        "cltd\n"
        "idivl -0x6c(%ebp)\n"
        "movl %eax, %ecx\n"
        "movl $0x3e7, %eax\n" /* line 1177 */
        "cmpl $0x3e8, %ecx\n"
        "cmovll %ecx, %eax\n"
        "movl %eax, 0x6e5a4(%edi)\n"
        "jmp .Lf15b00a_0015b31a\n"
        ".Lf15b00a_0015b3aa:\n"
        "calll SV_ArchiveSnapshot\n" /* line 1630 */
        ".Lf15b00a_0015b3af:\n"
        "movl -0x68(%ebp), %eax\n" /* line 1608 */
        "subl %eax, sv+16\n"
        "addl %eax, svs+4\n" /* line 1609 */
        "movl $1, (%esp)\n" /* line 1613 */
        "calll CL_FlushDebugData\n"
        "calll SV_ResetSkeletonCache\n" /* line 1333 */
        "movl svs+4, %eax\n" /* line 1335 */
        "movl %eax, (%esp)\n"
        "calll G_RunFrame\n"
        "movl $0, (%esp)\n" /* line 1621 */
        "calll Scr_SetLoading\n"
        "movl -0x68(%ebp), %edx\n" /* line 1627 */
        "cmpl sv+16, %edx\n"
        "jle .Lf15b00a_0015b3aa\n"
        "movl svs+4, %edx\n" /* line 1218 */
        "movl sv_timeout, %eax\n"
        "movl 8(%eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %edx, %edi\n"
        "subl %eax, %edi\n"
        "movl sv_zombietime, %eax\n" /* line 1219 */
        "movl 8(%eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %edx, %ecx\n"
        "subl %eax, %ecx\n"
        "movl %ecx, -0x60(%ebp)\n"
        "movl svs+12, %ebx\n" /* line 1221 */
        "movl sv_maxclients, %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf15b00a_0015b4b5\n"
        "xorl %esi, %esi\n"
        "jmp .Lf15b00a_0015b47d\n"
        ".Lf15b00a_0015b442:\n"
        "jle .Lf15b00a_0015b4a9\n" /* line 1249 */
        "cmpl 0x20d10(%ebx), %edi\n"
        "jle .Lf15b00a_0015b4a9\n"
        "movl 0x20d20(%ebx), %eax\n" /* line 1257 */
        "addl $1, %eax\n"
        "movl %eax, 0x20d20(%ebx)\n"
        "cmpl $5, %eax\n"
        "jg .Lf15b00a_0015b5eb\n"
        ".Lf15b00a_0015b464:\n"
        "addl $1, %esi\n" /* line 1221 */
        "addl $0x78f0c, %ebx\n"
        "movl sv_maxclients, %eax\n"
        "cmpl 8(%eax), %esi\n"
        "jge .Lf15b00a_0015b4b5\n"
        "movl svs+4, %edx\n"
        ".Lf15b00a_0015b47d:\n"
        "cmpl %edx, 0x20d10(%ebx)\n" /* line 1224 */
        "jle .Lf15b00a_0015b48b\n"
        "movl %edx, 0x20d10(%ebx)\n" /* line 1226 */
        ".Lf15b00a_0015b48b:\n"
        "movl 0x765f4(%ebx), %eax\n" /* line 1229 */
        "testl %eax, %eax\n"
        "jne .Lf15b00a_0015b464\n"
        "cmpl $1, (%ebx)\n" /* line 1232 */
        "jne .Lf15b00a_0015b442\n"
        "movl -0x60(%ebp), %eax\n"
        "cmpl 0x20d10(%ebx), %eax\n"
        "jg .Lf15b00a_0015b5ca\n"
        ".Lf15b00a_0015b4a9:\n"
        "movl $0, 0x20d20(%ebx)\n" /* line 1272 */
        "jmp .Lf15b00a_0015b464\n"
        ".Lf15b00a_0015b4b5:\n"
        "calll SV_SendClientMessages\n" /* line 1639 */
        "calll SV_ArchiveSnapshot\n" /* line 1640 */
        "movl $str_002ab708, (%esp)\n" /* line 1643 */
        "calll SV_MasterHeartbeat\n"
        "jmp .Lf15b00a_0015b204\n"
        ".Lf15b00a_0015b4d0:\n"
        "movl $0x40, 8(%esp)\n" /* line 1553 */
        "movl sv_mapname, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab678, (%esp)\n" /* line 1554 */
        "jmp .Lf15b00a_0015b1e7\n"
        ".Lf15b00a_0015b4fb:\n"
        "movl $0x40, 8(%esp)\n" /* line 1563 */
        "movl sv_mapname, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab6ac, (%esp)\n" /* line 1564 */
        "jmp .Lf15b00a_0015b1e7\n"
        ".Lf15b00a_0015b526:\n"
        "movl $0x40, 8(%esp)\n" /* line 1573 */
        "movl sv_mapname, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002ab6dc, (%esp)\n" /* line 1574 */
        "jmp .Lf15b00a_0015b1e7\n"
        ".Lf15b00a_0015b551:\n"
        "movl $0x100, 8(%esp)\n" /* line 1594 */
        "movl $0x60, 4(%esp)\n"
        "movl $0x8e, (%esp)\n"
        "calll SV_SetConfig\n"
        "andl $0xfffffeff, (%ebx)\n" /* line 1595 */
        "jmp .Lf15b00a_0015b171\n"
        ".Lf15b00a_0015b578:\n"
        "movl $8, (%esp)\n" /* line 1588 */
        "calll Dvar_InfoString_Big\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl (%ebx), %eax\n" /* line 1589 */
        "andl $0xfffffff7, %eax\n"
        "movl %eax, (%ebx)\n"
        "jmp .Lf15b00a_0015b168\n"
        ".Lf15b00a_0015b5a0:\n"
        "movl $0x404, (%esp)\n" /* line 1583 */
        "calll Dvar_InfoString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl (%ebx), %eax\n" /* line 1584 */
        "andl $0xfffffbfb, %eax\n"
        "movl %eax, (%ebx)\n"
        "jmp .Lf15b00a_0015b160\n"
        ".Lf15b00a_0015b5ca:\n"
        "leal 0x20c48(%ebx), %eax\n" /* line 1238 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab548, (%esp)\n" /* "Going from CS_ZOMBIE to CS_FREE for %s
" */
        "calll Com_DPrintf\n"
        "movl $0, (%ebx)\n" /* line 1239 */
        "jmp .Lf15b00a_0015b464\n"
        ".Lf15b00a_0015b5eb:\n"
        "movl $str_002ab570, 4(%esp)\n" /* line 1259 */
        "movl %ebx, (%esp)\n"
        "calll SV_DropClient\n"
        "movl $0, (%ebx)\n" /* line 1260 */
        "jmp .Lf15b00a_0015b464\n"
    );
}

#else
long int SV_AddServerCommand(client_t *client, svscmd_type type, const char *cmd) { return 0; }
#endif
