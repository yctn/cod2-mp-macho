/* ASM dump from: sv_client_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_client_mp.cpp */

#include "common_types.h"
#include "imports.h"

static int botport; /* botport */
extern const char str_00228e90[];
extern const char str_002a96d4[];
extern const char str_002a98b0[];
extern const char str_002adea0[];
extern const char str_002adeac[];
extern const char str_002adeb0[];
extern const char str_002adebc[];
extern const char str_002adec4[];
extern const char str_002adecc[];
extern const char str_002aded8[];
extern const char str_002adee4[];

extern float FX_GetServerVisibility(const vec_t *start, const vec_t *end);
extern void Com_DPrintf(const char *fmt, ...);
extern const char *SV_Cmd_Argv(int arg);
extern int atoi(const char *s);

#ifndef __EMSCRIPTEN__
__asm__(".Lsvexec_fmt: .asciz \"[SV_ExecMsg] clServerId=%d svServerId=%d clState=%d\\n\"\n");
#endif
#ifndef __EMSCRIPTEN__
__asm__(".Lsvexec_msgtype_fmt: .asciz \"[SV_ExecMsg] msgType=%d clState=%d\\n\"\n");
#endif
#ifndef __EMSCRIPTEN__
__asm__(".Lsvexec_clicmd_fmt: .asciz \"[SV_ExecMsg] clientCmd seq=%d lastCmd=%d s='%s'\\n\"\n");
#endif
#ifndef __EMSCRIPTEN__
__asm__(".Lsvexec_drop_fmt: .asciz \"[SV_ExecMsg] DROP seq=%d lastCmd=%d\\n\"\n");
#endif
static int sv_exec_dbg_count = 0;
void SV_ExecDbg(const char *fmt, int clSid, int svSid, int clState) {
    if (sv_exec_dbg_count < 20 || (sv_exec_dbg_count % 500 == 0)) {
        fprintf(stderr, fmt, clSid, svSid, clState);
    }
    sv_exec_dbg_count++;
}

void SV_AuthorizeRequest(struct netadr_t from, int challenge);
static qboolean SV_IsBannedGuid(void);
void SV_BanGuidBriefly(int guid);
void SV_UnbanClient(const char *name);
void SV_AuthorizeIpPacket(netadr_t from);
void SV_UserinfoChanged(client_t *cl);
void SV_FreeClientScriptPers(void);
void SV_DelayDropClient(client_t *drop, const char *reason);
void SV_SendClientGameState(client_t *client);
void SV_ClientEnterWorld(client_t *client, const dvar_t * (*cmd)[4]);
void SV_DoneDownload_f(client_t *cl);
void SV_RetransmitDownload_f(client_t *cl);
void SV_WriteDownloadToClient(client_t *cl, msg_t *msg);
void SV_VerifyIwds_f(client_t *cl);
void SV_ResetPureClient_f(client_t *cl);
void SV_UpdateUserinfo_f(client_t *cl);
void SV_MutePlayer_f(client_t *cl);
void SV_UnmutePlayer_f(client_t *cl);
float SV_FX_GetVisibility(const vec_t *start, const vec_t *end);
void SV_ExecuteClientCommand(client_t *cl, const char *s, qboolean clientOK);
void SV_ClientThink(client_t *cl, const dvar_t * (*cmd)[4]);
void SV_GetChallenge(netadr_t from);
void SV_FreeClient(client_t *cl);
void SV_DropClient(client_t *drop, const char *reason);
void SV_Disconnect_f(client_t *cl);
void SV_BanClient(client_t *cl);
void SV_DirectConnect(netadr_t from);
void SV_FreeClients(void);
void SV_StopDownload_f(client_t *cl);
void SV_NextDownload_f(client_t *cl);
void SV_BeginDownload_f(client_t *cl);
void SV_UserMove(client_t *cl, msg_t *msg, qboolean delta);
void SV_ExecuteClientMessage(client_t *cl, msg_t *msg);
gentity_t * SV_AddTestClient(void);

__attribute__((used)) ucmd_t ucmds[12] = {
    { (char *)str_002adea0, (void (*)())SV_UpdateUserinfo_f },
    { (char *)str_00228e90, (void (*)())SV_Disconnect_f },
    { (char *)str_002adeac, (void (*)())SV_VerifyIwds_f },
    { (char *)str_002a96d4, (void (*)())SV_ResetPureClient_f },
    { (char *)str_002adeb0, (void (*)())SV_BeginDownload_f },
    { (char *)str_002adebc, (void (*)())SV_NextDownload_f },
    { (char *)str_002adec4, (void (*)())SV_StopDownload_f },
    { (char *)str_002a98b0, (void (*)())SV_DoneDownload_f },
    { (char *)str_002adecc, (void (*)())SV_RetransmitDownload_f },
    { (char *)str_002aded8, (void (*)())SV_MutePlayer_f },
    { (char *)str_002adee4, (void (*)())SV_UnmutePlayer_f },
    { 0, 0 },
}; /* 0x312ca0 */

/* line 138 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void SV_AuthorizeRequest(struct netadr_t from, int challenge)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        "movl 0x10(%ebp), %esi\n"
        "movl 8(%ebp), %ebx\n" /* from */
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x43b(%ebp)\n"
        "movzbl 0xd(%ebp), %edx\n"
        "movb %dl, -0x43a(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x439(%ebp)\n"
        "movzbl 0xf(%ebp), %edi\n"
        /* { scope 1 */
        "movl imp_svs, %eax\n" /* line 146 */
        "cmpl $1, 0xa068(%eax)\n"
        "je .Lf17ad28_0017ae88\n"
        "movb $0, -0x430(%ebp)\n" /* line 149 | game */
        "movl $0x101c, 8(%esp)\n" /* line 150 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_00216d64, (%esp)\n" /* "fs_game" */
        "calll Dvar_RegisterString_mac\n"
        "testl %eax, %eax\n" /* line 151 */
        "je .Lf17ad28_0017ada1\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf17ad28_0017ae93\n"
        ".Lf17ad28_0017ada1:\n"
        "movw %si, -0x28(%ebp)\n" /* line 154 */
        "movl %ebx, -0x30(%ebp)\n"
        "movzbl -0x43b(%ebp), %eax\n"
        "movb %al, -0x2c(%ebp)\n"
        "movzbl -0x43a(%ebp), %edx\n"
        "movb %dl, -0x2b(%ebp)\n"
        "movzbl -0x439(%ebp), %eax\n"
        "movb %al, -0x2a(%ebp)\n"
        "movl %edi, %edx\n"
        "movb %dl, -0x29(%ebp)\n"
        "movl %ebx, (%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002adef4, (%esp)\n" /* "sending getIpAuthorize for %s
" */
        "calll Com_DPrintf\n"
        "movl $str_002a718c, (%esp)\n" /* line 155 */
        "calll Dvar_GetBool\n"
        "movzbl %al, %eax\n" /* line 158 */
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x430(%ebp), %eax\n" /* game */
        "movl %eax, 0x18(%esp)\n"
        "movl %edi, %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl -0x439(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x43a(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x43b(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* challenge */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adf14, (%esp)\n" /* "getIpAuthorize %i %i.%i.%i.%i %s %i" */
        "calll va\n"
        "movl imp_svs, %edx\n"
        "movl 0xa068(%edx), %ebx\n"
        "movl %ebx, -0x24(%ebp)\n"
        "movl 0xa06c(%edx), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0xa070(%edx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        ".Lf17ad28_0017ae88:\n"
        "addl $0x45c, %esp\n" /* line 159 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17ad28_0017ae93:\n"
        "movl %eax, 4(%esp)\n" /* line 152 */
        "leal -0x430(%ebp), %edx\n" /* game */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lf17ad28_0017ada1\n"
    );
}

/* line 182 */
__attribute__((naked))
qboolean SV_IsBannedGuid(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 182 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl %eax, %esi\n" /* guid */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 190 */
        "jne .Lf17aeaa_0017aec3\n"
        ".Lf17aeaa_0017aeb8:\n"
        "xorl %ebx, %ebx\n" /* line 213 | banned */
        /* } scope */
        "movl %ebx, %eax\n" /* line 214 | banned */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17aeaa_0017aec3:\n"
        "leal -0xc(%ebp), %eax\n" /* line 193 | file */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adf38, (%esp)\n" /* "ban.txt" */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 194 */
        "js .Lf17aeaa_0017aeb8\n"
        "movl -0xc(%ebp), %eax\n" /* line 197 | file */
        "movl %eax, -0x10(%ebp)\n" /* text */
        "leal -0x10(%ebp), %ebx\n" /* text, banned */
        "jmp .Lf17aeaa_0017aef9\n"
        ".Lf17aeaa_0017aee5:\n"
        "movl %eax, (%esp)\n" /* line 205 */
        "calll atoi\n"
        "cmpl %eax, %esi\n" /* guid */
        "je .Lf17aeaa_0017af1c\n"
        "movl %ebx, (%esp)\n" /* line 210 | banned */
        "calll Com_SkipRestOfLine\n"
        ".Lf17aeaa_0017aef9:\n"
        "movl %ebx, (%esp)\n" /* line 201 | banned */
        "calll Com_Parse\n"
        "cmpb $0, (%eax)\n" /* line 202 */
        "jne .Lf17aeaa_0017aee5\n"
        "xorl %ebx, %ebx\n" /* line 199 | banned */
        ".Lf17aeaa_0017af08:\n"
        "movl -0xc(%ebp), %eax\n" /* line 212 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 214 | banned */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17aeaa_0017af1c:\n"
        "movl $1, %ebx\n" /* line 205 | banned */
        "jmp .Lf17aeaa_0017af08\n"
    );
}

/* line 234 */
__attribute__((naked))
void SV_BanGuidBriefly(int guid)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 234 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl imp_svs, %edi\n" /* line 225 */
        "movl 0xa078(%edi), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf17af24_0017af57\n"
        "xorl %esi, %esi\n"
        ".Lf17af24_0017af3c:\n"
        "movl %esi, %ecx\n"
        ".Lf17af24_0017af3e:\n"
        "movl 8(%ebp), %eax\n" /* line 239 | guid */
        "movl %eax, 0xa078(%edi, %ecx, 8)\n"
        "movl 4(%edi), %eax\n" /* line 240 */
        "movl %eax, 0xa07c(%edi, %ecx, 8)\n"
        /* } scope */
        "popl %ebx\n" /* line 241 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17af24_0017af57:\n"
        "xorl %ecx, %ecx\n" /* line 225 */
        "xorl %esi, %esi\n"
        "movl %edi, %edx\n"
        ".Lf17af24_0017af5d:\n"
        "movl %edx, %ebx\n" /* line 234 */
        "movl 0xa07c(%edx), %eax\n" /* line 227 */
        "cmpl 0xa07c(%edi, %ecx, 8), %eax\n"
        "cmovll %esi, %ecx\n"
        "addl $1, %esi\n" /* line 223 */
        "cmpl $0x10, %esi\n"
        "je .Lf17af24_0017af3e\n"
        "addl $8, %edx\n" /* line 225 */
        "movl 0xa080(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf17af24_0017af5d\n"
        "jmp .Lf17af24_0017af3c\n"
    );
}

/* line 281 */
__attribute__((naked))
void SV_UnbanClient(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 281 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "leal -0x1c(%ebp), %eax\n" /* line 293 | file */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adf38, (%esp)\n" /* "ban.txt" */
        "calll FS_ReadFile\n"
        "movl %eax, %esi\n" /* fileSize */
        "testl %eax, %eax\n" /* line 294 */
        "js .Lf17af86_0017b0ae\n"
        "movl $0x40, 8(%esp)\n" /* line 297 */
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* cleanName */
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0x60(%ebp), %ecx\n" /* line 298 | cleanName */
        "movl %ecx, (%esp)\n"
        "calll I_CleanStr\n"
        "cld\n" /* line 299 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x60(%ebp), %edi\n" /* cleanName, line */
        "repne scasb %es:(%edi), %al\n" /* line */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x70(%ebp)\n" /* nameLen */
        "movl -0x1c(%ebp), %eax\n" /* line 302 | file */
        "movl %eax, -0x20(%ebp)\n" /* text */
        "movl $0, -0x6c(%ebp)\n" /* found */
        ".Lf17af86_0017aff3:\n"
        "movl %eax, %edi\n" /* line 305 | line */
        "leal -0x20(%ebp), %eax\n" /* line 306 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "cmpb $0, (%eax)\n" /* line 307 */
        "je .Lf17af86_0017b072\n"
        ".Lf17af86_0017b005:\n"
        "movl -0x20(%ebp), %edx\n" /* line 310 | text */
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf17af86_0017b020\n"
        ".Lf17af86_0017b00f:\n"
        "cmpb $0x20, %al\n"
        "jg .Lf17af86_0017b020\n"
        "addl $1, %edx\n" /* line 311 */
        "movl %edx, -0x20(%ebp)\n" /* text */
        "movzbl (%edx), %eax\n" /* line 310 */
        "testb %al, %al\n"
        "jne .Lf17af86_0017b00f\n"
        ".Lf17af86_0017b020:\n"
        "movl -0x70(%ebp), %ecx\n" /* line 312 | nameLen */
        "movl %ecx, 8(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* cleanName */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17af86_0017b04c\n"
        "movl -0x20(%ebp), %eax\n" /* text */
        "movl -0x70(%ebp), %edx\n" /* nameLen */
        "movzbl (%eax, %edx), %eax\n"
        "cmpb $0xd, %al\n"
        "je .Lf17af86_0017b0b6\n"
        "cmpb $0xa, %al\n"
        "je .Lf17af86_0017b0b6\n"
        ".Lf17af86_0017b04c:\n"
        "xorl %ebx, %ebx\n"
        "leal -0x20(%ebp), %ecx\n" /* line 313 | text */
        "movl %ecx, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "testb %bl, %bl\n" /* line 314 */
        "jne .Lf17af86_0017b0ca\n"
        ".Lf17af86_0017b05d:\n"
        "movl -0x20(%ebp), %eax\n" /* text */
        "movl %eax, %edi\n" /* line 305 | line */
        "leal -0x20(%ebp), %eax\n" /* line 306 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "cmpb $0, (%eax)\n" /* line 307 */
        "jne .Lf17af86_0017b005\n"
        ".Lf17af86_0017b072:\n"
        "movl %esi, 8(%esp)\n" /* line 323 | fileSize */
        "movl -0x1c(%ebp), %eax\n" /* file */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adf38, (%esp)\n" /* "ban.txt" */
        "calll FS_WriteFile\n"
        "movl -0x1c(%ebp), %eax\n" /* line 324 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl -0x6c(%ebp), %ecx\n" /* line 326 | found */
        "testl %ecx, %ecx\n"
        "jne .Lf17af86_0017b100\n"
        "leal -0x60(%ebp), %ecx\n" /* line 329 | cleanName */
        "movl %ecx, 4(%esp)\n"
        "movl $str_002adf60, (%esp)\n" /* "no banned user has name %s
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf17af86_0017b0ae:\n"
        "addl $0x7c, %esp\n" /* line 330 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17af86_0017b0b6:\n"
        "movl $1, %ebx\n" /* line 312 */
        "leal -0x20(%ebp), %ecx\n" /* line 313 | text */
        "movl %ecx, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "testb %bl, %bl\n" /* line 314 */
        "je .Lf17af86_0017b05d\n"
        ".Lf17af86_0017b0ca:\n"
        "addl $1, -0x6c(%ebp)\n" /* line 316 | found */
        "movl -0x20(%ebp), %edx\n" /* line 317 | text */
        "movl %edx, %eax\n"
        "subl -0x1c(%ebp), %eax\n" /* file */
        "movl %esi, %ecx\n" /* fileSize */
        "subl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* line */
        "calll memmove\n"
        "movl -0x20(%ebp), %eax\n" /* line 318 | text */
        "subl %edi, %eax\n" /* line */
        "subl %eax, %esi\n" /* fileSize */
        "movl %edi, %eax\n" /* line 319 | line */
        "movl %edi, -0x20(%ebp)\n" /* line, text */
        "jmp .Lf17af86_0017aff3\n"
        ".Lf17af86_0017b100:\n"
        "leal -0x60(%ebp), %eax\n" /* line 327 | cleanName */
        "movl %eax, 8(%esp)\n"
        "movl -0x6c(%ebp), %edx\n" /* found */
        "movl %edx, 4(%esp)\n"
        "movl $str_002adf40, (%esp)\n" /* "unbanned %i user(s) named %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 330 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 342 */
__attribute__((naked))
void SV_AuthorizeIpPacket(netadr_t from)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 342 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50c, %esp\n"
        "movl 8(%ebp), %esi\n" /* from */
        /* { scope 1 */
        "movl imp_svs, %edi\n" /* line 350 | r */
        "movl 0xa068(%edi), %ebx\n" /* r, s */
        "movl %ebx, -0xcc(%ebp)\n" /* s */
        "movl 0xa06c(%edi), %ecx\n" /* r */
        "movl %ecx, -0xc8(%ebp)\n"
        "movl 0xa070(%edi), %edx\n" /* r */
        "movl %edx, -0xc4(%ebp)\n"
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0xb8(%ebp)\n"
        "movzbl 0xf(%ebp), %eax\n"
        "movb %al, -0xb9(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0xba(%ebp)\n"
        "movzbl 0xd(%ebp), %eax\n"
        "movb %al, -0xbb(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0xbc(%ebp)\n"
        "movl %esi, -0xc0(%ebp)\n" /* i */
        "movl %ebx, 0xc(%esp)\n" /* s */
        "movl %ecx, 0x10(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "movl -0xbc(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xb8(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf17b122_0017b1d6\n"
        "movl $str_002adf7c, (%esp)\n" /* line 352 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf17b122_0017b1cb:\n"
        "addl $0x50c, %esp\n" /* line 460 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17b122_0017b1d6:\n"
        "movl $1, (%esp)\n" /* line 356 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "xorl %esi, %esi\n" /* i */
        "movl %edi, %edx\n" /* r */
        "jmp .Lf17b122_0017b202\n"
        ".Lf17b122_0017b1f0:\n"
        "addl $1, %esi\n" /* line 358 | i */
        "addl $0x28, %edx\n"
        "cmpl $0x400, %esi\n" /* i */
        "je .Lf17b122_0017b67c\n"
        ".Lf17b122_0017b202:\n"
        "cmpl 0x68(%edx), %eax\n" /* line 360 */
        "jne .Lf17b122_0017b1f0\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 370 | i */
        "shll $3, %eax\n"
        "movl %eax, -0x4ec(%ebp)\n"
        "addl imp_svs, %eax\n"
        "movl %eax, -0x4f0(%ebp)\n"
        "movl imp_svs, %edx\n"
        "movl 4(%edx), %eax\n"
        "movl -0x4f0(%ebp), %edx\n"
        "movl %eax, 0x70(%edx)\n"
        "movl $2, (%esp)\n" /* line 371 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, %ebx\n" /* s */
        "movl $3, (%esp)\n" /* line 372 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, %edi\n" /* r */
        "movl $str_002a9080, 4(%esp)\n" /* line 374 */
        "movl %ebx, (%esp)\n" /* s */
        "calll I_stricmp\n"
        "movl %eax, -0x4e8(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lf17b122_0017b2d9\n"
        "movl $str_00216d6c, (%esp)\n" /* line 376 */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "je .Lf17b122_0017b3bf\n"
        "movl -0x4f0(%ebp), %ebx\n" /* line 379 | s */
        "addl $0x50, %ebx\n" /* s */
        "movl 0x18(%ebx), %eax\n" /* s */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adfdc, (%esp)\n" /* "challengeResponse %i" */
        "calll va\n"
        "movl 0xc(%ebx), %esi\n" /* s, i */
        "movl %esi, -0xb4(%ebp)\n" /* i */
        "movl 0x10(%ebx), %ecx\n" /* s */
        "movl %ecx, -0xb0(%ebp)\n"
        "movl 0x14(%ebx), %edx\n" /* s */
        "movl %edx, -0xac(%ebp)\n"
        ".Lf17b122_0017b2b2:\n"
        "movl %eax, 0x10(%esp)\n" /* line 407 */
        "movl %esi, 4(%esp)\n" /* i */
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        "addl $0x50c, %esp\n" /* line 460 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17b122_0017b2d9:\n"
        "movl $str_002ae014, 4(%esp)\n" /* line 389 */
        "movl %ebx, (%esp)\n" /* s */
        "calll I_stricmp\n"
        "movl %eax, -0x4e4(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf17b122_0017b340\n"
        "movl $str_002ae088, 4(%esp)\n" /* line 413 */
        "movl %ebx, (%esp)\n" /* guid */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17b122_0017b42c\n"
        "testl %edi, %edi\n" /* line 415 | r */
        "je .Lf17b122_0017b318\n"
        "cmpb $0, (%edi)\n" /* r */
        "jne .Lf17b122_0017b5c6\n"
        ".Lf17b122_0017b318:\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 417 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %ecx\n"
        "movl %ecx, -0x78(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x74(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl $str_002ae090, 0x10(%esp)\n" /* "error
EXE_ERR_CDKEY_IN_USE" */
        "jmp .Lf17b122_0017b45c\n"
        ".Lf17b122_0017b340:\n"
        "movl $4, (%esp)\n" /* line 391 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl -0x4f0(%ebp), %ebx\n" /* s */
        "addl $0x70, %ebx\n" /* s */
        "movl %eax, 0x10(%ebx)\n" /* s */
        "calll SV_IsBannedGuid\n" /* line 392 */
        "testl %eax, %eax\n"
        "jne .Lf17b122_0017b603\n"
        "movl 0x10(%ebx), %ebx\n" /* line 398 | guid */
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 165 */
        "jne .Lf17b122_0017b495\n"
        "movl imp_svs, %edx\n"
        /* } scope */
        ".Lf17b122_0017b37e:\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 404 | i */
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0x7c(%eax), %ebx\n" /* guid */
        "testl %ebx, %ebx\n" /* guid */
        "jne .Lf17b122_0017b1cb\n"
        "leal 0x50(%eax), %ebx\n" /* line 407 | guid */
        "movl 0x18(%ebx), %eax\n" /* guid */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adfdc, (%esp)\n" /* "challengeResponse %i" */
        "calll va\n"
        "movl 0xc(%ebx), %esi\n" /* guid, i */
        "movl %esi, -0x84(%ebp)\n" /* i */
        "movl 0x10(%ebx), %ecx\n" /* guid */
        "movl %ecx, -0x80(%ebp)\n"
        "movl 0x14(%ebx), %edx\n" /* guid */
        "movl %edx, -0x7c(%ebp)\n"
        "jmp .Lf17b122_0017b2b2\n"
        ".Lf17b122_0017b3bf:\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 383 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %ecx\n"
        "movl %ecx, -0xa8(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0xa4(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0xa0(%ebp)\n"
        "movl $str_002adff4, 0x10(%esp)\n" /* "error
EXE_ERR_NOT_A_DEMO_SERVER" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl -0x4ec(%ebp), %eax\n" /* line 385 */
        "movl imp_svs, %edx\n"
        "leal 0x5c(%eax, %edx), %edi\n" /* r */
        "cld\n"
        "movl $0xa, %ecx\n"
        "movl -0x4e8(%ebp), %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* r */
        /* } scope */
        "addl $0x50c, %esp\n" /* line 460 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17b122_0017b42c:\n"
        "testl %edi, %edi\n" /* line 449 | r */
        "je .Lf17b122_0017b439\n"
        "cmpb $0, (%edi)\n" /* r */
        "jne .Lf17b122_0017b570\n"
        ".Lf17b122_0017b439:\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 451 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl $str_002ae0f0, 0x10(%esp)\n" /* "error
EXE_ERR_BAD_CDKEY" */
        ".Lf17b122_0017b45c:\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        ".Lf17b122_0017b474:\n"
        "leal (%esi, %esi, 4), %edi\n" /* line 459 | i, r */
        "movl imp_svs, %eax\n"
        "leal 0x5c(%eax, %edi, 8), %edi\n" /* r */
        "cld\n"
        "movl $0xa, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* r */
        /* } scope */
        "addl $0x50c, %esp\n" /* line 460 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf17b122_0017b495:\n"
        "movl imp_svs, %edx\n" /* line 172 */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x4e0(%ebp)\n"
        "movl imp_sv_kickBanTime, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x4dc(%ebp)\n"
        "movl imp_svs, %ecx\n"
        "movss lit4_002ed5c8, %xmm2\n" /* 1000.0f */
        "movl %ecx, %edi\n"
        "jmp .Lf17b122_0017b4d6\n"
        ".Lf17b122_0017b4c3:\n"
        "addl $8, %ecx\n"
        "movl %edi, %edx\n" /* line 342 */
        "leal 0x80(%edi), %eax\n"
        "cmpl %eax, %ecx\n" /* line 168 */
        "je .Lf17b122_0017b37e\n"
        ".Lf17b122_0017b4d6:\n"
        "cmpl 0xa078(%ecx), %ebx\n" /* line 170 */
        "jne .Lf17b122_0017b4c3\n"
        "movl -0x4e0(%ebp), %eax\n" /* line 172 */
        "subl 0xa07c(%ecx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movl -0x4dc(%ebp), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf17b122_0017b4c3\n"
        /* } scope */
        "movl %ebx, 4(%esp)\n" /* line 400 | guid */
        "movl $str_002ae114, (%esp)\n" /* "rejected connection from temporarily banned GUID %i
" */
        "calll Com_Printf\n"
        "movl imp_svs, %ebx\n" /* line 401 | guid */
        "leal (%esi, %esi, 4), %edi\n" /* i, r */
        "shll $3, %edi\n" /* r */
        "leal 0x50(%edi, %ebx), %eax\n" /* r */
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x90(%ebp)\n"
        "movl 0x10(%eax), %ecx\n"
        "movl %ecx, -0x8c(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x88(%ebp)\n"
        "movl $str_002ae14c, 0x10(%esp)\n" /* "error
You are temporarily banned from this server" */
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "leal 0x5c(%edi, %ebx), %edi\n" /* line 402 | r */
        "cld\n"
        "movl $0xa, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* r */
        "jmp .Lf17b122_0017b1cb\n"
        ".Lf17b122_0017b570:\n"
        "movl %edi, 8(%esp)\n" /* line 455 | r */
        "movl $str_002ae108, 4(%esp)\n" /* "error
%s" */
        "leal -0x4cc(%ebp), %ebx\n" /* ret, guid */
        "movl %ebx, (%esp)\n" /* guid */
        "calll sprintf\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 456 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x10(%eax), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, 0x10(%esp)\n" /* guid */
        ".Lf17b122_0017b5a9:\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "jmp .Lf17b122_0017b474\n"
        ".Lf17b122_0017b5c6:\n"
        "movl $str_002ae0ac, 4(%esp)\n" /* line 419 */
        "movl %edi, (%esp)\n" /* r */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17b122_0017b68d\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 421 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "movl 0x10(%eax), %ecx\n"
        "movl %ecx, -0x68(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl $str_002a95ac, 0x10(%esp)\n" /* "needcdkey" */
        "jmp .Lf17b122_0017b5a9\n"
        ".Lf17b122_0017b603:\n"
        "movl 0x10(%ebx), %eax\n" /* line 394 | s */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae01c, (%esp)\n" /* "rejected connection from permanently banned GUID %i
" */
        "calll Com_Printf\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 395 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %ecx\n"
        "movl %ecx, -0x9c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x98(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x94(%ebp)\n"
        "movl $str_002ae054, 0x10(%esp)\n" /* "error
You are permanently banned from this server" */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl -0x4ec(%ebp), %edx\n" /* line 396 */
        "movl imp_svs, %eax\n"
        "leal 0x5c(%edx, %eax), %edi\n" /* r */
        "cld\n"
        "movl $0xa, %ecx\n"
        "movl -0x4e4(%ebp), %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* r */
        "jmp .Lf17b122_0017b1cb\n"
        ".Lf17b122_0017b67c:\n"
        "movl $str_002adfb0, (%esp)\n" /* line 365 */
        "calll Com_Printf\n"
        "jmp .Lf17b122_0017b1cb\n"
        ".Lf17b122_0017b68d:\n"
        "movl $str_002ae0c4, 4(%esp)\n" /* line 423 */
        "movl %edi, (%esp)\n" /* r */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17b122_0017b6c9\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 425 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl 0x10(%eax), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl $str_002a95ac, 0x10(%esp)\n" /* "needcdkey" */
        "jmp .Lf17b122_0017b5a9\n"
        ".Lf17b122_0017b6c9:\n"
        "movl $str_002ae0d0, 4(%esp)\n" /* line 427 */
        "movl %edi, (%esp)\n" /* r */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17b122_0017b705\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 431 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl 0x10(%eax), %ecx\n"
        "movl %ecx, -0x50(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl $str_002ae090, 0x10(%esp)\n" /* "error
EXE_ERR_CDKEY_IN_USE" */
        "jmp .Lf17b122_0017b5a9\n"
        ".Lf17b122_0017b705:\n"
        "movl $str_002ae0e0, 4(%esp)\n" /* line 433 */
        "movl %edi, (%esp)\n" /* r */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17b122_0017b741\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 436 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl 0x10(%eax), %ecx\n"
        "movl %ecx, -0x44(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl $str_002ae0f0, 0x10(%esp)\n" /* "error
EXE_ERR_BAD_CDKEY" */
        "jmp .Lf17b122_0017b5a9\n"
        ".Lf17b122_0017b741:\n"
        "movl -0x4f0(%ebp), %eax\n" /* line 440 */
        "addl $0x50, %eax\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0x10(%eax), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl $str_002ae0f0, 0x10(%esp)\n" /* "error
EXE_ERR_BAD_CDKEY" */
        "jmp .Lf17b122_0017b5a9\n"
    );
}

/* line 1569 */
__attribute__((naked))
void SV_UserinfoChanged(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1569 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cl */
        /* { scope 1 */
        "leal 0xc(%ebx), %esi\n" /* line 1579 | cl */
        "movl $str_002194b4, 4(%esp)\n" /* "name" */
        "movl %esi, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x20c48(%ebx), %eax\n" /* cl */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl 0x6e5c4(%ebx), %ecx\n" /* line 1585 | cl */
        "movl %ecx, -0x14(%ebp)\n"
        "movl 0x6e5c8(%ebx), %edx\n" /* cl */
        "movl %edx, -0x10(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* cl */
        "movl %eax, -0xc(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll Sys_IsLANAddress\n"
        "testl %eax, %eax\n"
        "je .Lf17b76a_0017b842\n"
        "movl imp_com_dedicated, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf17b76a_0017b842\n"
        "movl $0x1869f, 0x6e5a8(%ebx)\n" /* line 1587 | cl */
        ".Lf17b76a_0017b7e8:\n"
        "movl $str_002a8f98, 4(%esp)\n" /* line 1615 */
        "movl %esi, (%esp)\n"
        "calll Info_ValueForKey\n"
        "cmpb $0, (%eax)\n" /* line 1616 */
        "jne .Lf17b76a_0017b876\n"
        ".Lf17b76a_0017b7fd:\n"
        "movl $0x32, 0x6e5ac(%ebx)\n" /* line 1631 | cl */
        ".Lf17b76a_0017b807:\n"
        "movl $str_002a8d5c, 4(%esp)\n" /* line 1635 */
        "movl %esi, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n" /* line 1636 */
        "calll atoi\n"
        "testl %eax, %eax\n"
        "setg 0x78f08(%ebx)\n" /* cl */
        "cmpl $0x1387, 0x6e5a8(%ebx)\n" /* line 1637 | cl */
        "jg .Lf17b76a_0017b83b\n"
        "movb $0, 0x78f08(%ebx)\n" /* line 1638 | cl */
        /* } scope */
        ".Lf17b76a_0017b83b:\n"
        "addl $0x20, %esp\n" /* line 1686 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17b76a_0017b842:\n"
        "movl $str_002a8c54, 4(%esp)\n" /* line 1591 */
        "movl %esi, (%esp)\n"
        "calll Info_ValueForKey\n"
        "cmpb $0, (%eax)\n" /* line 1592 */
        "jne .Lf17b76a_0017b899\n"
        "movl $0x1388, 0x6e5a8(%ebx)\n" /* line 1607 | cl */
        "movl $str_002a8f98, 4(%esp)\n" /* line 1615 */
        "movl %esi, (%esp)\n"
        "calll Info_ValueForKey\n"
        "cmpb $0, (%eax)\n" /* line 1616 */
        "je .Lf17b76a_0017b7fd\n"
        ".Lf17b76a_0017b876:\n"
        "movl %eax, (%esp)\n" /* line 1618 */
        "calll atoi\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 1619 */
        "jle .Lf17b76a_0017b8e3\n"
        "cmpl $0x1e, %eax\n" /* line 1623 */
        "jle .Lf17b76a_0017b8bd\n"
        "movl $0x21, %eax\n"
        ".Lf17b76a_0017b88e:\n"
        "movl %eax, 0x6e5ac(%ebx)\n" /* line 1627 | cl */
        "jmp .Lf17b76a_0017b807\n"
        ".Lf17b76a_0017b899:\n"
        "movl %eax, (%esp)\n" /* line 1594 */
        "calll atoi\n"
        "movl %eax, 0x6e5a8(%ebx)\n" /* line 1595 | cl */
        "cmpl $0x3e7, %eax\n" /* line 1596 */
        "jg .Lf17b76a_0017b8c9\n"
        "movl $0x3e8, 0x6e5a8(%ebx)\n" /* line 1598 | cl */
        "jmp .Lf17b76a_0017b7e8\n"
        ".Lf17b76a_0017b8bd:\n"
        "movl $0x3e8, %eax\n" /* line 1623 */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "jmp .Lf17b76a_0017b88e\n"
        ".Lf17b76a_0017b8c9:\n"
        "cmpl $0x15f90, %eax\n" /* line 1600 */
        "jle .Lf17b76a_0017b7e8\n"
        "movl $0x15f90, 0x6e5a8(%ebx)\n" /* line 1602 | cl */
        "jmp .Lf17b76a_0017b7e8\n"
        ".Lf17b76a_0017b8e3:\n"
        "movl $0x3e8, %eax\n" /* line 1619 */
        "jmp .Lf17b76a_0017b88e\n"
    );
}

/* line 798 */
__attribute__((naked))
void SV_FreeClientScriptPers(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 798 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl imp_svs, %eax\n" /* line 803 */
        "movl 0xc(%eax), %ebx\n" /* cl */
        "movl imp_sv_maxclients, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %esi\n" /* i */
        "testl %esi, %esi\n" /* i */
        "jle .Lf17b8ea_0017b939\n"
        "xorl %esi, %esi\n" /* i */
        "movl %edx, %edi\n"
        ".Lf17b8ea_0017b90e:\n"
        "cmpl $1, (%ebx)\n" /* line 805 | cl */
        "jle .Lf17b8ea_0017b929\n"
        "movl %ebx, (%esp)\n" /* line 809 | cl */
        "calll SV_FreeClientScriptId\n"
        "calll Scr_AllocArray\n" /* line 810 */
        "movw %ax, 0x765f0(%ebx)\n" /* cl */
        "movl %edi, %edx\n"
        ".Lf17b8ea_0017b929:\n"
        "addl $1, %esi\n" /* line 803 | i */
        "addl $0x78f0c, %ebx\n" /* cl */
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jl .Lf17b8ea_0017b90e\n"
        /* } scope */
        ".Lf17b8ea_0017b939:\n"
        "addl $0x1c, %esp\n" /* line 812 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 898 */
void SV_DelayDropClient(client_t *drop, const char *reason)
{
    if (*(int *)drop == 1)
        return;
    if (*(int *)((byte *)drop + 8))
        return;
    *(const char **)((byte *)drop + 8) = reason;
}

/* line 927 */
__attribute__((naked))
void SV_SendClientGameState(client_t *client)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 927 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        /* { scope 1 */
        "movl $0x20000, 4(%esp)\n" /* line 932 — increased from 0x4000 for larger gamestates */
        "leal -0x1c(%ebp), %eax\n" /* msgBuffer_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* msgBuffer_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %esi\n" /* msgBuffer */
        "movl 8(%ebp), %ebx\n" /* client */
        "addl $0x6e5b4, %ebx\n"
        "jmp .Lf17b95e_0017b9a7\n"
        ".Lf17b95e_0017b995:\n"
        "movl 0x725dc(%eax), %edi\n" /* line 934 | start */
        "testl %edi, %edi\n" /* start */
        "je .Lf17b95e_0017b9b0\n"
        "movl %ebx, (%esp)\n" /* line 938 */
        "calll SV_Netchan_TransmitNextFragment\n"
        ".Lf17b95e_0017b9a7:\n"
        "movl 8(%ebp), %eax\n" /* line 934 | client */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf17b95e_0017b995\n"
        ".Lf17b95e_0017b9b0:\n"
        "movl 8(%ebp), %ebx\n" /* line 946 | client */
        "addl $0x20c48, %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002ae180, (%esp)\n" /* "SV_SendClientGameState() for %s
" */
        "calll Com_DPrintf\n"
        "movl %ebx, 4(%esp)\n" /* line 947 */
        "movl $str_002ae1a4, (%esp)\n" /* "Going from CS_CONNECTED to CS_PRIMED for %s
" */
        "calll Com_DPrintf\n"
        "movl 8(%ebp), %edx\n" /* line 948 | client */
        "movl $3, (%edx)\n"
        "movl $0, 0x6e5b0(%edx)\n" /* line 949 */
        "movl 0x6e5b4(%edx), %eax\n" /* line 954 */
        "movl %eax, 0x2081c(%edx)\n"
        "movl $0x20000, 8(%esp)\n" /* line 956 — increased from 0x4000 for larger gamestates */
        "movl %esi, 4(%esp)\n" /* msgBuffer */
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_Init\n"
        "movl 8(%ebp), %edx\n" /* line 960 | client */
        "movl 0x20840(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "leal -0x34(%ebp), %edx\n" /* line 966 | msg */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* client */
        "movl %eax, (%esp)\n"
        "calll SV_UpdateServerCommandsToClient\n"
        "movl $1, 4(%esp)\n" /* line 969 */
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 8(%ebp), %edx\n" /* line 970 | client */
        "movl 0x20814(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "xorl %esi, %esi\n" /* msgBuffer */
        "movl imp_sv, %ebx\n"
        "jmp .Lf17b95e_0017ba7c\n"
        ".Lf17b95e_0017ba6e:\n"
        "addl $1, %esi\n" /* line 973 | msgBuffer */
        "addl $4, %ebx\n"
        "cmpl $0x800, %esi\n" /* msgBuffer */
        "je .Lf17b95e_0017bacc\n"
        ".Lf17b95e_0017ba7c:\n"
        "movl 0x418(%ebx), %eax\n" /* line 975 */
        "cmpb $0, (%eax)\n"
        "je .Lf17b95e_0017ba6e\n"
        "movl $2, 4(%esp)\n" /* line 977 */
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl %esi, 4(%esp)\n" /* line 978 | msgBuffer */
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteShort\n"
        "movl 0x418(%ebx), %eax\n" /* line 979 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteBigString\n"
        "addl $1, %esi\n" /* line 973 | msgBuffer */
        "addl $4, %ebx\n"
        "cmpl $0x800, %esi\n" /* msgBuffer */
        "jne .Lf17b95e_0017ba7c\n"
        ".Lf17b95e_0017bacc:\n"
        "movl $0xf0, 8(%esp)\n" /* line 984 */
        "movl $0, 4(%esp)\n"
        "leal -0x124(%ebp), %eax\n" /* nullstate */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "xorl %edi, %edi\n" /* start */
        "movl imp_sv, %edx\n"
        "movl %edx, -0x12c(%ebp)\n"
        "movl %edx, %ebx\n"
        "addl $0x2410, %ebx\n"
        "jmp .Lf17b95e_0017bb13\n"
        ".Lf17b95e_0017bb02:\n"
        "addl $1, %edi\n" /* line 985 | start */
        "addl $0x174, %ebx\n"
        "cmpl $0x400, %edi\n" /* start */
        "je .Lf17b95e_0017bb62\n"
        ".Lf17b95e_0017bb13:\n"
        "leal 0xc(%ebx), %esi\n" /* line 987 | msgBuffer */
        "movl 0xc(%ebx), %ecx\n" /* line 988 */
        "testl %ecx, %ecx\n"
        "je .Lf17b95e_0017bb02\n"
        "movl $3, 4(%esp)\n" /* line 992 */
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl $1, 0xc(%esp)\n" /* line 993 */
        "movl %esi, 8(%esp)\n" /* msgBuffer */
        "leal -0x124(%ebp), %edx\n" /* nullstate */
        "movl %edx, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteDeltaEntity\n"
        "addl $1, %edi\n" /* line 985 | start */
        "addl $0x174, %ebx\n"
        "cmpl $0x400, %edi\n" /* start */
        "jne .Lf17b95e_0017bb13\n"
        ".Lf17b95e_0017bb62:\n"
        "movl $7, 4(%esp)\n" /* line 996 */
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl imp_svs, %ebx\n" /* line 998 */
        "movl 8(%ebp), %eax\n" /* client */
        "subl 0xc(%ebx), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl -0x12c(%ebp), %edx\n" /* line 1001 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl $7, 4(%esp)\n" /* line 1003 */
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 8(%ebp), %eax\n" /* line 1006 | client */
        "subl 0xc(%ebx), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae1d4, (%esp)\n" /* "Sending %i bytes in gamestate to client: %i
" */
        "calll Com_DPrintf\n"
        "movl 8(%ebp), %eax\n" /* line 1009 | client */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll SV_SendMessageToClient\n"
        "leal -0x1c(%ebp), %edx\n" /* msgBuffer_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x13c, %esp\n" /* line 1010 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        /* { scope 1 */
        "leal -0x1c(%ebp), %eax\n" /* line 1009 | msgBuffer_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 1018 */
__attribute__((naked))
void SV_ClientEnterWorld(client_t *client, const dvar_t * (*cmd)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1018 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* client */
        "movl 0xc(%ebp), %edi\n" /* cmd */
        /* { scope 1 */
        "leal 0x20c48(%ebx), %eax\n" /* line 1023 | client */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae204, (%esp)\n" /* "Going from CS_PRIMED to CS_ACTIVE for %s
" */
        "calll Com_DPrintf\n"
        "movl $4, (%ebx)\n" /* line 1024 | client */
        "movl %ebx, %esi\n" /* line 1027 | client */
        "movl imp_svs, %eax\n"
        "subl 0xc(%eax), %esi\n"
        "sarl $2, %esi\n"
        "imull $0x3789a4eb, %esi, %esi\n"
        "movl %esi, (%esp)\n" /* line 1028 */
        "calll SV_GentityNum\n"
        "movl %esi, (%eax)\n" /* line 1029 */
        "movl %eax, 0x20c44(%ebx)\n" /* line 1030 | client */
        "movl $0xffffffff, 0x20d08(%ebx)\n" /* line 1032 | client */
        "movl imp_svs, %edx\n" /* line 1033 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x20d18(%ebx)\n" /* client */
        "movl (%edi), %eax\n" /* line 1034 | cmd */
        "movl %eax, 0x20824(%ebx)\n" /* client */
        "movl 4(%edi), %eax\n" /* cmd */
        "movl %eax, 0x20828(%ebx)\n" /* client */
        "movl 8(%edi), %eax\n" /* cmd */
        "movl %eax, 0x2082c(%ebx)\n" /* client */
        "movl 0xc(%edi), %eax\n" /* cmd */
        "movl %eax, 0x20830(%ebx)\n" /* client */
        "movl 0x10(%edi), %eax\n" /* cmd */
        "movl %eax, 0x20834(%ebx)\n" /* client */
        "movl 0x14(%edi), %eax\n" /* cmd */
        "movl %eax, 0x20838(%ebx)\n" /* client */
        "movl 0x18(%edi), %eax\n" /* cmd */
        "movl %eax, 0x2083c(%ebx)\n" /* client */
        "subl 0xc(%edx), %ebx\n" /* line 1037 | client */
        "sarl $2, %ebx\n" /* client */
        "imull $0x3789a4eb, %ebx, %ebx\n" /* client */
        "movl %ebx, 8(%ebp)\n" /* client */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1038 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp ClientBegin\n" /* line 1037 */
    );
}

/* line 1106 */
void SV_DoneDownload_f(client_t *cl)
{
    Com_DPrintf("clientDownload: %s Done\n", cl->name);
    SV_SendClientGameState(cl);
}

/* line 1122 */
void SV_RetransmitDownload_f(client_t *cl)
{
    int block = atoi(SV_Cmd_Argv(1));
    if (block == cl->downloadClientBlock)
        cl->downloadXmitBlock = block;
}

/* line 1196 */
__attribute__((naked))
void SV_WriteDownloadToClient(client_t *cl, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1196 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %esi\n" /* cl */
        /* { scope 1 */
        "cmpb $0, 0x20c68(%esi)\n" /* line 1209 | cl */
        "je .Lf17bd48_0017c028\n"
        "movl 0x20ca8(%esi), %eax\n" /* line 1212 | cl */
        "testl %eax, %eax\n"
        "je .Lf17bd48_0017bf33\n"
        ".Lf17bd48_0017bd72:\n"
        "movl 0x20cb8(%esi), %edx\n" /* line 1287 | cl */
        "movl %edx, %eax\n"
        "subl 0x20cb4(%esi), %eax\n" /* cl */
        "cmpl $7, %eax\n"
        "jle .Lf17bd48_0017c06c\n"
        "movl 0x20cb0(%esi), %eax\n" /* cl */
        ".Lf17bd48_0017bd8f:\n"
        "cmpl 0x20cac(%esi), %eax\n" /* line 1310 | cl */
        "je .Lf17bd48_0017c07e\n"
        ".Lf17bd48_0017bd9b:\n"
        "movl 0x6e5a8(%esi), %ebx\n" /* line 1323 | cl, rate */
        "movl imp_sv_maxRate, %edi\n" /* line 1324 */
        "movl (%edi), %edx\n"
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf17bd48_0017bdc3\n"
        "cmpl $0x3e7, %eax\n" /* line 1326 */
        "jle .Lf17bd48_0017c1dd\n"
        ".Lf17bd48_0017bdbb:\n"
        "movl 8(%edx), %eax\n" /* line 1329 */
        "cmpl %eax, %ebx\n" /* rate */
        "cmovgl %eax, %ebx\n" /* rate */
        ".Lf17bd48_0017bdc3:\n"
        "testl %ebx, %ebx\n" /* line 1333 | rate */
        "je .Lf17bd48_0017bdf9\n"
        "movl %ebx, %ecx\n" /* line 1339 | rate */
        "imull 0x6e5ac(%esi), %ecx\n" /* cl */
        "movl $0x10624dd3, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "addl $0x800, %eax\n"
        "js .Lf17bd48_0017c1f4\n"
        ".Lf17bd48_0017bdf0:\n"
        "sarl $0xb, %eax\n" /* line 1342 */
        "jns .Lf17bd48_0017c312\n"
        ".Lf17bd48_0017bdf9:\n"
        "movl $0, -0x41c(%ebp)\n"
        ".Lf17bd48_0017be03:\n"
        "movl 0x20cb4(%esi), %edx\n" /* line 1350 | cl */
        "movl 0x20cb8(%esi), %eax\n" /* cl */
        "cmpl %edx, %eax\n"
        "je .Lf17bd48_0017c028\n"
        "xorl %edi, %edi\n" /* line 1351 */
        "jmp .Lf17bd48_0017bf07\n"
        ".Lf17bd48_0017be1e:\n"
        "movl imp_svs, %eax\n" /* line 1359 */
        "movl 4(%eax), %eax\n"
        "subl 0x20d04(%esi), %eax\n" /* cl */
        "cmpl $0x3e8, %eax\n"
        "jle .Lf17bd48_0017c028\n"
        "movl %edx, 0x20cbc(%esi)\n" /* line 1360 | cl */
        "movl %edx, %ebx\n" /* rate */
        "andl $0x80000007, %ebx\n" /* line 1366 | rate */
        "js .Lf17bd48_0017bf25\n"
        ".Lf17bd48_0017be4b:\n"
        "movl $5, 4(%esp)\n" /* line 1368 */
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl 0x20cbc(%esi), %eax\n" /* line 1369 | cl */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteShort\n"
        "movl 0x20cbc(%esi), %ecx\n" /* line 1372 | cl */
        "testl %ecx, %ecx\n"
        "je .Lf17bd48_0017c052\n"
        ".Lf17bd48_0017be81:\n"
        "movl 0x20ce0(%esi, %ebx, 4), %eax\n" /* line 1375 | cl */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteShort\n"
        "movl 0x20ce0(%esi, %ebx, 4), %eax\n" /* line 1378 | cl */
        "testl %eax, %eax\n"
        "jne .Lf17bd48_0017c033\n"
        ".Lf17bd48_0017bea6:\n"
        "movl 0x20cbc(%esi), %eax\n" /* line 1381 | cl */
        "movl %eax, 8(%esp)\n"
        "movl imp_svs, %ebx\n" /* rate */
        "movl %esi, %eax\n" /* cl */
        "subl 0xc(%ebx), %eax\n" /* rate */
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae388, (%esp)\n" /* "clientDownload: %d : writing block %d
" */
        "calll Com_DPrintf\n"
        "addl $1, 0x20cbc(%esi)\n" /* line 1385 | cl */
        "movl 4(%ebx), %eax\n" /* line 1387 | rate */
        "movl %eax, 0x20d04(%esi)\n" /* cl */
        "cmpl %edi, -0x41c(%ebp)\n" /* line 1345 */
        "je .Lf17bd48_0017c028\n"
        "movl 0x20cb4(%esi), %edx\n" /* line 1350 | cl */
        "movl 0x20cb8(%esi), %eax\n" /* cl */
        "addl $1, %edi\n"
        "cmpl %eax, %edx\n"
        "je .Lf17bd48_0017c028\n"
        ".Lf17bd48_0017bf07:\n"
        "cmpl 0x20cbc(%esi), %eax\n" /* line 1353 | cl */
        "je .Lf17bd48_0017be1e\n"
        "movl 0x20cbc(%esi), %ebx\n" /* cl, rate */
        "andl $0x80000007, %ebx\n" /* line 1366 | rate */
        "jns .Lf17bd48_0017be4b\n"
        ".Lf17bd48_0017bf25:\n"
        "subl $1, %ebx\n" /* rate */
        "orl $0xfffffff8, %ebx\n" /* rate */
        "addl $1, %ebx\n" /* rate */
        "jmp .Lf17bd48_0017be4b\n"
        ".Lf17bd48_0017bf33:\n"
        "leal 0x20c68(%esi), %ebx\n" /* line 1216 | cl, rate */
        "movl %ebx, 8(%esp)\n" /* rate */
        "movl imp_svs, %eax\n"
        "movl %esi, %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae24c, (%esp)\n" /* "clientDownload: %d : begining "%s"
" */
        "calll Com_Printf\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 1218 */
        "movl %ebx, (%esp)\n" /* rate */
        "calll FS_iwIwd\n"
        "movl %eax, %edx\n"
        "movl imp_sv_allowDownload, %ecx\n" /* line 1248 */
        "movl (%ecx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17bd48_0017c168\n"
        "testl %edx, %edx\n"
        "je .Lf17bd48_0017c27f\n"
        ".Lf17bd48_0017bf8e:\n"
        "movl %ebx, 8(%esp)\n" /* line 1253 | rate */
        "movl imp_svs, %eax\n"
        "movl %esi, %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae270, (%esp)\n" /* "clientDownload: %d : "%s" cannot download iwd files
" */
        "calll Com_Printf\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1254 | rate */
        "movl $str_002ae2a8, 8(%esp)\n" /* "EXE_CANTAUTODLGAMEIWD%s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* errorMessage, rate */
        "movl %ebx, (%esp)\n" /* rate */
        "calll Com_sprintf\n"
        ".Lf17bd48_0017bfd9:\n"
        "movl $5, 4(%esp)\n" /* line 1271 */
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteByte\n"
        "movl $0, 4(%esp)\n" /* line 1272 */
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteShort\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 1273 */
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_WriteLong\n"
        "movl %ebx, 4(%esp)\n" /* line 1274 | rate */
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteString\n"
        "movb $0, 0x20c68(%esi)\n" /* line 1276 | cl */
        /* } scope */
        ".Lf17bd48_0017c028:\n"
        "addl $0x42c, %esp\n" /* line 1389 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17bd48_0017c033:\n"
        "movl %eax, 8(%esp)\n" /* line 1379 */
        "movl 0x20cc0(%esi, %ebx, 4), %eax\n" /* cl */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteData\n"
        "jmp .Lf17bd48_0017bea6\n"
        ".Lf17bd48_0017c052:\n"
        "movl 0x20cac(%esi), %eax\n" /* line 1373 | cl */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_WriteLong\n"
        "jmp .Lf17bd48_0017be81\n"
        ".Lf17bd48_0017c06c:\n"
        "movl 0x20cac(%esi), %eax\n" /* line 1287 | cl */
        "cmpl 0x20cb0(%esi), %eax\n" /* cl */
        "jne .Lf17bd48_0017c155\n"
        ".Lf17bd48_0017c07e:\n"
        "movl 0x20d00(%esi), %ebx\n" /* line 1310 | cl, rate */
        "testl %ebx, %ebx\n" /* rate */
        "jne .Lf17bd48_0017bd9b\n"
        "movl 0x20cb8(%esi), %edx\n" /* cl */
        "movl %edx, %eax\n"
        "subl 0x20cb4(%esi), %eax\n" /* cl */
        "cmpl $7, %eax\n"
        "jg .Lf17bd48_0017bd9b\n"
        "movl %edx, %eax\n" /* line 1312 */
        "andl $0x80000007, %eax\n"
        "js .Lf17bd48_0017c2f9\n"
        ".Lf17bd48_0017c0b0:\n"
        "movl $0, 0x20ce0(%esi, %eax, 4)\n" /* cl */
        "leal 1(%edx), %eax\n" /* line 1313 */
        "movl %eax, 0x20cb8(%esi)\n" /* cl */
        "movl $1, 0x20d00(%esi)\n" /* line 1315 | cl */
        "jmp .Lf17bd48_0017bd9b\n"
        ".Lf17bd48_0017c0d3:\n"
        "subl $1, %ebx\n" /* line 1289 | rate */
        "orl $0xfffffff8, %ebx\n" /* rate */
        "addl $1, %ebx\n" /* rate */
        ".Lf17bd48_0017c0dc:\n"
        "movl 0x20cc0(%esi, %ebx, 4), %edi\n" /* line 1291 | cl */
        "testl %edi, %edi\n"
        "je .Lf17bd48_0017c1ff\n"
        ".Lf17bd48_0017c0eb:\n"
        "movl 0x20ca8(%esi), %eax\n" /* line 1294 | cl */
        "movl %eax, 8(%esp)\n"
        "movl $0x800, 4(%esp)\n"
        "movl 0x20cc0(%esi, %ebx, 4), %eax\n" /* cl */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movl %eax, 0x20ce0(%esi, %ebx, 4)\n" /* cl */
        "testl %eax, %eax\n" /* line 1296 */
        "js .Lf17bd48_0017c267\n"
        "movl %eax, %ecx\n" /* line 1303 */
        "addl 0x20cb0(%esi), %ecx\n" /* cl */
        "movl %ecx, 0x20cb0(%esi)\n" /* cl */
        "movl 0x20cb8(%esi), %edx\n" /* line 1306 | cl */
        "addl $1, %edx\n"
        "movl %edx, 0x20cb8(%esi)\n" /* cl */
        "movl %edx, %eax\n" /* line 1287 */
        "subl 0x20cb4(%esi), %eax\n" /* cl */
        "cmpl $7, %eax\n"
        "jg .Lf17bd48_0017c278\n"
        "cmpl 0x20cac(%esi), %ecx\n" /* cl */
        "je .Lf17bd48_0017c07e\n"
        ".Lf17bd48_0017c155:\n"
        "movl %edx, %ebx\n" /* line 1289 | rate */
        "andl $0x80000007, %ebx\n" /* rate */
        "jns .Lf17bd48_0017c0dc\n"
        "jmp .Lf17bd48_0017c0d3\n"
        ".Lf17bd48_0017c168:\n"
        "testl %edx, %edx\n" /* line 1251 */
        "jne .Lf17bd48_0017bf8e\n"
        ".Lf17bd48_0017c170:\n"
        "movl (%ecx), %eax\n" /* line 1256 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf17bd48_0017c217\n"
        "movl %ebx, 8(%esp)\n" /* line 1258 | rate */
        "movl imp_svs, %eax\n"
        "movl %esi, %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae2c4, (%esp)\n" /* "clientDownload: %d : "%s" download disabled" */
        "calll Com_Printf\n"
        "movl imp_sv_pure, %eax\n" /* line 1260 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17bd48_0017c2d2\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1261 | rate */
        "movl $str_002ae2f0, 8(%esp)\n" /* "EXE_AUTODL_SERVERDISABLED_PURE%s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* errorMessage, rate */
        "movl %ebx, (%esp)\n" /* rate */
        "calll Com_sprintf\n"
        "jmp .Lf17bd48_0017bfd9\n"
        ".Lf17bd48_0017c1dd:\n"
        "movl $0x3e8, 4(%esp)\n" /* line 1327 */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl (%edi), %edx\n"
        "jmp .Lf17bd48_0017bdbb\n"
        ".Lf17bd48_0017c1f4:\n"
        "leal 0xfff(%edx), %eax\n" /* line 1339 */
        "jmp .Lf17bd48_0017bdf0\n"
        ".Lf17bd48_0017c1ff:\n"
        "movl $0x800, (%esp)\n" /* line 1292 */
        "calll Z_MallocInternal\n"
        "movl %eax, 0x20cc0(%esi, %ebx, 4)\n" /* cl */
        "jmp .Lf17bd48_0017c0eb\n"
        ".Lf17bd48_0017c217:\n"
        "movl %ebx, 8(%esp)\n" /* line 1268 | rate */
        "movl imp_svs, %eax\n"
        "movl %esi, %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae334, (%esp)\n" /* "clientDownload: %d : "%s" file not found on server
" */
        "calll Com_Printf\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1269 | rate */
        "movl $str_002ae368, 8(%esp)\n" /* "EXE_AUTODL_FILENOTONSERVER%s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* errorMessage, rate */
        "movl %ebx, (%esp)\n" /* rate */
        "calll Com_sprintf\n"
        "jmp .Lf17bd48_0017bfd9\n"
        ".Lf17bd48_0017c267:\n"
        "movl 0x20cac(%esi), %eax\n" /* line 1299 | cl */
        "movl %eax, 0x20cb0(%esi)\n" /* cl */
        "jmp .Lf17bd48_0017bd8f\n"
        ".Lf17bd48_0017c278:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf17bd48_0017bd8f\n"
        ".Lf17bd48_0017c27f:\n"
        "leal 0x20ca8(%esi), %eax\n" /* line 1248 | cl */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* rate */
        "calll FS_SV_FOpenFileRead\n"
        "movl %eax, 0x20cac(%esi)\n" /* cl */
        "testl %eax, %eax\n"
        "jle .Lf17bd48_0017c307\n"
        "movl $0, 0x20cbc(%esi)\n" /* line 1281 | cl */
        "movl $0, 0x20cb4(%esi)\n" /* cl */
        "movl $0, 0x20cb8(%esi)\n" /* cl */
        "movl $0, 0x20cb0(%esi)\n" /* line 1282 | cl */
        "movl $0, 0x20d00(%esi)\n" /* line 1283 | cl */
        "jmp .Lf17bd48_0017bd72\n"
        ".Lf17bd48_0017c2d2:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1264 | rate */
        "movl $str_002ae314, 8(%esp)\n" /* "EXE_AUTODL_SERVERDISABLED%s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* errorMessage, rate */
        "movl %ebx, (%esp)\n" /* rate */
        "calll Com_sprintf\n"
        "jmp .Lf17bd48_0017bfd9\n"
        ".Lf17bd48_0017c2f9:\n"
        "subl $1, %eax\n" /* line 1312 */
        "orl $0xfffffff8, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf17bd48_0017c0b0\n"
        ".Lf17bd48_0017c307:\n"
        "movl imp_sv_allowDownload, %ecx\n"
        "jmp .Lf17bd48_0017c170\n"
        ".Lf17bd48_0017c312:\n"
        "subl $1, %eax\n" /* line 1342 */
        "movl %eax, -0x41c(%ebp)\n"
        "addl $1, %eax\n" /* line 1345 */
        "jne .Lf17bd48_0017be03\n"
        "jmp .Lf17bd48_0017c028\n"
    );
}

/* line 1426 */
__attribute__((naked))
void SV_VerifyIwds_f(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1426 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x201c, %esp\n"
        /* { scope 1 */
        "calll SV_Cmd_Argc\n" /* line 1440 */
        "movl %eax, %esi\n" /* nServerIwds */
        "cmpl $1, %eax\n" /* line 1450 */
        "jle .Lf17c32a_0017c353\n"
        "movl $1, (%esp)\n" /* line 1456 */
        "calll SV_Cmd_Argv\n"
        "cmpb $0x40, (%eax)\n" /* line 1457 */
        "je .Lf17c32a_0017c36b\n"
        ".Lf17c32a_0017c353:\n"
        "movl 8(%ebp), %eax\n" /* line 1544 | cl */
        "movl $1, 0x6e5b0(%eax)\n" /* fix #155: always pass IWD verification (decompiled binary can't do proper checksums) */
        /* } scope */
        ".Lf17c32a_0017c360:\n"
        "addl $0x201c, %esp\n" /* line 1545 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17c32a_0017c36b:\n"
        "cmpl $2, %esi\n" /* line 1463 | nServerIwds */
        "jg .Lf17c32a_0017c43b\n"
        "movl $0xffffffff, %edi\n"
        ".Lf17c32a_0017c379:\n"
        "calll FS_LoadedIwdPureChecksums\n" /* line 1492 */
        "movl %eax, (%esp)\n" /* line 1493 */
        "calll SV_Cmd_TokenizeString\n"
        "calll SV_Cmd_Argc\n" /* line 1494 */
        "movl %eax, %esi\n" /* nServerIwds */
        "cmpl $0x400, %eax\n" /* line 1495 */
        "jle .Lf17c32a_0017c432\n"
        "movl $0x400, %esi\n" /* nServerIwds */
        ".Lf17c32a_0017c39d:\n"
        "xorl %ebx, %ebx\n" /* line 1498 */
        ".Lf17c32a_0017c39f:\n"
        "movl %ebx, (%esp)\n" /* line 1500 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0x2018(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 1498 */
        "cmpl %ebx, %esi\n" /* nServerIwds */
        "jne .Lf17c32a_0017c39f\n"
        ".Lf17c32a_0017c3bd:\n"
        "testl %edi, %edi\n" /* line 1504 */
        "jle .Lf17c32a_0017c3f5\n"
        "movl -0x2018(%ebp), %ebx\n" /* line 1508 | nServerChkSum */
        "testl %esi, %esi\n" /* line 1506 | nServerIwds */
        "jle .Lf17c32a_0017c353\n"
        "xorl %ecx, %ecx\n" /* line 1463 */
        ".Lf17c32a_0017c3cd:\n"
        "movl -0x1018(%ebp, %ecx, 4), %edx\n" /* line 1508 */
        "cmpl %edx, %ebx\n"
        "je .Lf17c32a_0017c3ee\n"
        "xorl %eax, %eax\n" /* line 1510 */
        ".Lf17c32a_0017c3da:\n"
        "addl $1, %eax\n" /* line 1506 */
        "cmpl %eax, %esi\n" /* nServerIwds */
        "je .Lf17c32a_0017c353\n"
        "cmpl -0x2018(%ebp, %eax, 4), %edx\n" /* line 1508 */
        "jne .Lf17c32a_0017c3da\n"
        ".Lf17c32a_0017c3ee:\n"
        "addl $1, %ecx\n" /* line 1504 */
        "cmpl %edi, %ecx\n"
        "jne .Lf17c32a_0017c3cd\n"
        ".Lf17c32a_0017c3f5:\n"
        "movl imp_sv, %eax\n" /* line 1525 */
        "movl 0xc(%eax), %edx\n"
        "testl %edi, %edi\n" /* line 1526 */
        "jle .Lf17c32a_0017c411\n"
        "xorl %eax, %eax\n" /* line 1504 */
        ".Lf17c32a_0017c403:\n"
        "xorl -0x1018(%ebp, %eax, 4), %edx\n" /* line 1528 */
        "addl $1, %eax\n" /* line 1526 */
        "cmpl %edi, %eax\n"
        "jne .Lf17c32a_0017c403\n"
        ".Lf17c32a_0017c411:\n"
        "xorl %edi, %edx\n" /* line 1531 */
        "cmpl -0x1018(%ebp, %edi, 4), %edx\n"
        "jne .Lf17c32a_0017c353\n"
        "movl 8(%ebp), %eax\n" /* line 1542 | cl */
        "movl $1, 0x6e5b0(%eax)\n"
        "jmp .Lf17c32a_0017c360\n"
        ".Lf17c32a_0017c432:\n"
        "testl %eax, %eax\n" /* line 1498 */
        "jle .Lf17c32a_0017c3bd\n"
        "jmp .Lf17c32a_0017c39d\n"
        ".Lf17c32a_0017c43b:\n"
        "movl $2, %eax\n" /* line 1457 */
        "leal -0x1018(%ebp), %edi\n" /* nClientChkSum */
        "jmp .Lf17c32a_0017c44a\n"
        ".Lf17c32a_0017c448:\n"
        "movl %ebx, %eax\n" /* line 1463 */
        ".Lf17c32a_0017c44a:\n"
        "leal 1(%eax), %ebx\n" /* line 1465 */
        "movl %eax, (%esp)\n"
        "calll SV_Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0xc(%edi, %ebx, 4)\n"
        "cmpl %ebx, %esi\n" /* line 1463 | nServerIwds */
        "jne .Lf17c32a_0017c448\n"
        "leal -3(%ebx), %edi\n"
        "testl %edi, %edi\n" /* line 1473 */
        "jle .Lf17c32a_0017c379\n"
        "xorl %ecx, %ecx\n"
        ".Lf17c32a_0017c472:\n"
        "xorl %edx, %edx\n"
        ".Lf17c32a_0017c474:\n"
        "cmpl %edx, %ecx\n" /* line 1477 */
        "je .Lf17c32a_0017c48c\n"
        "movl -0x1018(%ebp, %ecx, 4), %eax\n" /* line 1479 */
        "cmpl -0x1018(%ebp, %edx, 4), %eax\n"
        "je .Lf17c32a_0017c353\n"
        ".Lf17c32a_0017c48c:\n"
        "addl $1, %edx\n" /* line 1475 */
        "cmpl %edi, %edx\n"
        "jne .Lf17c32a_0017c474\n"
        "addl $1, %ecx\n" /* line 1473 */
        "cmpl %edi, %ecx\n"
        "jne .Lf17c32a_0017c472\n"
        "jmp .Lf17c32a_0017c379\n"
    );
}

/* line 1553 */
void SV_ResetPureClient_f(client_t *cl)
{
    cl->pureAuthentic = 0;
}

/* line 1694 */
__attribute__((naked))
void SV_UpdateUserinfo_f(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1694 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cl */
        "movl $1, (%esp)\n" /* line 1696 */
        "calll SV_Cmd_Argv\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%ebx), %eax\n" /* cl */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %ebx, (%esp)\n" /* line 1698 | cl */
        "calll SV_UserinfoChanged\n"
        "movl imp_svs, %eax\n" /* line 1700 */
        "subl 0xc(%eax), %ebx\n" /* cl */
        "sarl $2, %ebx\n" /* cl */
        "imull $0x3789a4eb, %ebx, %ebx\n" /* cl */
        "movl %ebx, 8(%ebp)\n" /* cl */
        "addl $0x14, %esp\n" /* line 1701 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp ClientUserinfoChanged\n" /* line 1700 */
    );
}

/* line 1710 */
__attribute__((naked))
void SV_MutePlayer_f(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1710 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 1714 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "cmpl $0x40, %eax\n" /* line 1715 */
        "ja .Lf17c506_0017c532\n"
        "movl 8(%ebp), %edx\n" /* line 1720 | cl */
        "movb $1, 0x78ec8(%eax, %edx)\n"
        /* } scope */
        "leave\n" /* line 1721 */
        "retl\n"
        /* { scope 1 */
        ".Lf17c506_0017c532:\n"
        "movl %eax, 4(%esp)\n" /* line 1717 */
        "movl $str_002ae3b0, (%esp)\n" /* "Invalid mute client %i
" */
        "calll Com_Printf\n"
        /* } scope */
        "leave\n" /* line 1721 */
        "retl\n"
    );
}

/* line 1728 */
__attribute__((naked))
void SV_UnmutePlayer_f(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1728 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 1732 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "cmpl $0x40, %eax\n" /* line 1733 */
        "ja .Lf17c544_0017c570\n"
        "movl 8(%ebp), %edx\n" /* line 1738 | cl */
        "movb $0, 0x78ec8(%eax, %edx)\n"
        /* } scope */
        "leave\n" /* line 1739 */
        "retl\n"
        /* { scope 1 */
        ".Lf17c544_0017c570:\n"
        "movl %eax, 4(%esp)\n" /* line 1735 */
        "movl $str_002ae3c8, (%esp)\n" /* "Invalid unmute client %i
" */
        "calll Com_Printf\n"
        /* } scope */
        "leave\n" /* line 1739 */
        "retl\n"
    );
}

/* line 1779 */
float SV_FX_GetVisibility(const vec_t *start, const vec_t *end)
{
    return FX_GetServerVisibility(start, end);
}

/* line 1795 */
__attribute__((naked))
void SV_ExecuteClientCommand(client_t *cl, const char *s, qboolean clientOK)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1795 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* cl, s */
        "movl %eax, -0x1c(%ebp)\n" /* s, cl */
        "movl 0x10(%ebp), %edi\n" /* clientOK */
        "movl 0xc(%ebp), %eax\n" /* line 1799 | s */
        "movl %eax, (%esp)\n"
        "calll SV_Cmd_TokenizeString\n"
        "movl ucmds, %ebx\n" /* line 1802 */
        "testl %ebx, %ebx\n"
        "je .Lf17c58c_0017c5ef\n"
        "movl $ucmds, %esi\n"
        ".Lf17c58c_0017c5b8:\n"
        "movl $0, (%esp)\n" /* line 1804 */
        "calll SV_Cmd_Argv\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf17c58c_0017c5f6\n"
        "addl $8, %esi\n" /* line 1802 */
        "movl (%esi), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf17c58c_0017c5b8\n"
        ".Lf17c58c_0017c5dd:\n"
        "testl %edi, %edi\n" /* line 1811 | clientOK */
        "je .Lf17c58c_0017c5e7\n"
        "movl (%esi), %eax\n" /* line 1814 */
        "testl %eax, %eax\n"
        "je .Lf17c58c_0017c601\n"
        ".Lf17c58c_0017c5e7:\n"
        "addl $0x2c, %esp\n" /* line 1817 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17c58c_0017c5ef:\n"
        "movl $ucmds, %esi\n" /* line 1802 */
        "jmp .Lf17c58c_0017c5dd\n"
        ".Lf17c58c_0017c5f6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1806 | cl */
        "movl %eax, (%esp)\n"
        "calll *4(%esi)\n"
        "jmp .Lf17c58c_0017c5dd\n"
        ".Lf17c58c_0017c601:\n"
        "calll SV_Loaded\n" /* line 1814 */
        "testb %al, %al\n"
        "je .Lf17c58c_0017c5e7\n"
        "movl imp_svs, %eax\n" /* line 1815 */
        "movl 0xc(%eax), %edx\n"
        "subl %edx, -0x1c(%ebp)\n" /* cl */
        "sarl $2, -0x1c(%ebp)\n" /* cl */
        "imull $0x3789a4eb, -0x1c(%ebp), %eax\n" /* cl */
        "movl %eax, 8(%ebp)\n" /* cl */
        "addl $0x2c, %esp\n" /* line 1817 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp ClientCommand\n" /* line 1815 */
    );
}

/* line 1896 */
__attribute__((naked))
void SV_ClientThink(client_t *cl, const dvar_t * (*cmd)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1896 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* cl */
        "movl 0xc(%ebp), %edx\n" /* cmd */
        "movl (%edx), %eax\n" /* line 1898 */
        "movl %eax, 0x20824(%esi)\n" /* cl */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x20828(%esi)\n" /* cl */
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x2082c(%esi)\n" /* cl */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0x20830(%esi)\n" /* cl */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x20834(%esi)\n" /* cl */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x20838(%esi)\n" /* cl */
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 0x2083c(%esi)\n" /* cl */
        "cmpl $4, (%esi)\n" /* line 1900 | cl */
        "je .Lf17c630_0017c688\n"
        "addl $0x10, %esp\n" /* line 1909 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17c630_0017c688:\n"
        "movl (%edx), %eax\n" /* line 1906 */
        "movl %eax, 4(%esp)\n"
        "movl imp_svs, %ebx\n"
        "movl %esi, %eax\n" /* cl */
        "subl 0xc(%ebx), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SetLastServerTime\n"
        "subl 0xc(%ebx), %esi\n" /* line 1908 | cl */
        "sarl $2, %esi\n" /* cl */
        "imull $0x3789a4eb, %esi, %eax\n" /* cl */
        "movl %eax, 8(%ebp)\n" /* cl */
        "addl $0x10, %esp\n" /* line 1909 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp ClientThink\n" /* line 1908 */
    );
}

/* line 48 */
__attribute__((naked))
void SV_GetChallenge(netadr_t from)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x7a(%ebp)\n"
        "movzbl 0xf(%ebp), %edx\n"
        "movb %dl, -0x7b(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x7c(%ebp)\n"
        "movzbl 0xd(%ebp), %edx\n"
        "movb %dl, -0x7d(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x7e(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* from */
        "movl %edx, -0x84(%ebp)\n"
        "movl $0, -0x8c(%ebp)\n" /* oldest */
        "movl $0x7fffffff, -0x88(%ebp)\n" /* oldestTime */
        "movl imp_svs, %edi\n"
        "addl $0x5c, %edi\n"
        "xorl %esi, %esi\n"
        "movl imp_svs, %ebx\n"
        "addl $0x7c, %ebx\n"
        "jmp .Lf17c6c4_0017c752\n"
        /* { scope 1 */
        ".Lf17c6c4_0017c726:\n"
        "movl -0x10(%ebx), %eax\n" /* line 66 */
        "cmpl -0x88(%ebp), %eax\n" /* oldestTime */
        "jge .Lf17c6c4_0017c73d\n"
        "movl %esi, -0x8c(%ebp)\n" /* i, oldest */
        "movl %eax, -0x88(%ebp)\n" /* oldestTime */
        ".Lf17c6c4_0017c73d:\n"
        "addl $1, %esi\n" /* line 60 | i */
        "addl $0x28, %edi\n" /* challenge */
        "addl $0x28, %ebx\n"
        "cmpl $0x400, %esi\n" /* i */
        "je .Lf17c6c4_0017ca78\n"
        ".Lf17c6c4_0017c752:\n"
        "movl (%ebx), %eax\n" /* line 62 */
        "testl %eax, %eax\n"
        "jne .Lf17c6c4_0017c726\n"
        "movl -0x20(%ebx), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl -0x1c(%ebx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x18(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movzwl -0x7a(%ebp), %eax\n"
        "movw %ax, -0x64(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x65(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x66(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x67(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x68(%ebp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf17c6c4_0017c726\n"
        ".Lf17c6c4_0017c7c1:\n"
        "movl imp_net_lanauthorize, %eax\n" /* line 90 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17c6c4_0017c9a5\n"
        ".Lf17c6c4_0017c7d2:\n"
        "movl imp_svs, %ebx\n" /* line 99 */
        "cmpb $0, 0xa06c(%ebx)\n"
        "jne .Lf17c6c4_0017c875\n"
        "cmpl $1, 0xa068(%ebx)\n"
        "je .Lf17c6c4_0017c875\n"
        "movl $str_002a9298, 4(%esp)\n" /* line 101 */
        "movl $str_002a92b4, (%esp)\n" /* "Resolving %s
" */
        "calll Com_Printf\n"
        "leal 0xa068(%ebx), %eax\n" /* line 102 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002a9298, (%esp)\n" /* "cod2master.activision.com" */
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf17c6c4_0017ca62\n"
        "movw $0xdc50, 0xa070(%ebx)\n" /* line 107 */
        "movl $0x50dc, 0x18(%esp)\n" /* line 108 */
        "movzbl 0xa06f(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl 0xa06e(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl 0xa06d(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzbl 0xa06c(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002a9298, 4(%esp)\n" /* "cod2master.activision.com" */
        "movl $str_002a92e0, (%esp)\n" /* "%s resolved to %i.%i.%i.%i:%i
" */
        "calll Com_Printf\n"
        ".Lf17c6c4_0017c875:\n"
        "movl 4(%ebx), %eax\n" /* line 116 */
        "subl 0x18(%edi), %eax\n" /* challenge */
        "cmpl $0x1388, %eax\n"
        "jg .Lf17c6c4_0017c8db\n"
        ".Lf17c6c4_0017c882:\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 126 | i */
        "movl 0x68(%ebx, %eax, 8), %eax\n"
        "movzwl -0x7a(%ebp), %edx\n"
        "movw %dx, -0x70(%ebp)\n"
        "movzbl -0x7b(%ebp), %edx\n"
        "movb %dl, -0x71(%ebp)\n"
        "movzbl -0x7c(%ebp), %edx\n"
        "movb %dl, -0x72(%ebp)\n"
        "movzbl -0x7d(%ebp), %edx\n"
        "movb %dl, -0x73(%ebp)\n"
        "movzbl -0x7e(%ebp), %edx\n"
        "movb %dl, -0x74(%ebp)\n"
        "movl -0x84(%ebp), %edx\n"
        "movl %edx, -0x78(%ebp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll SV_AuthorizeRequest\n"
        /* } scope */
        ".Lf17c6c4_0017c8d0:\n"
        "addl $0xac, %esp\n" /* line 135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17c6c4_0017c8db:\n"
        "calll SV_MasterAddress\n" /* line 116 */
        "movl (%eax), %ecx\n"
        "movl %ecx, -0x48(%ebp)\n"
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, -0x40(%ebp)\n"
        "movzwl -0x7a(%ebp), %eax\n"
        "movw %ax, -0x34(%ebp)\n"
        "movzbl -0x7b(%ebp), %eax\n"
        "movb %al, -0x35(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x36(%ebp)\n"
        "movzbl -0x7d(%ebp), %eax\n"
        "movb %al, -0x37(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x38(%ebp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf17c6c4_0017c882\n"
        "movl $str_002ae3e4, (%esp)\n" /* line 118 */
        "calll Com_DPrintf\n"
        "movl 4(%ebx), %eax\n" /* line 120 */
        "movl %eax, 0x14(%edi)\n" /* challenge */
        "movl 0xc(%edi), %eax\n" /* line 121 | challenge */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adfdc, (%esp)\n" /* "challengeResponse %i" */
        "calll va\n"
        "movl (%edi), %ecx\n" /* challenge */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 4(%edi), %ebx\n" /* challenge */
        "movl %ebx, -0x2c(%ebp)\n"
        "movl 8(%edi), %edx\n" /* challenge */
        "movl %edx, -0x28(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17c6c4_0017c9a5:\n"
        "movzwl -0x7a(%ebp), %eax\n" /* line 90 */
        "movw %ax, -0x58(%ebp)\n"
        "movzbl -0x7b(%ebp), %edx\n"
        "movb %dl, -0x59(%ebp)\n"
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, -0x5a(%ebp)\n"
        "movzbl -0x7d(%ebp), %edx\n"
        "movb %dl, -0x5b(%ebp)\n"
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, -0x5c(%ebp)\n"
        "movl -0x84(%ebp), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl %edx, (%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll Sys_IsLANAddress\n"
        "testl %eax, %eax\n"
        "je .Lf17c6c4_0017c7d2\n"
        "movl imp_svs, %eax\n" /* line 92 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x14(%edi)\n" /* challenge */
        "movl 0xc(%edi), %eax\n" /* line 93 | challenge */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adfdc, (%esp)\n" /* "challengeResponse %i" */
        "calll va\n"
        "movzwl -0x7a(%ebp), %edx\n"
        "movw %dx, -0x4c(%ebp)\n"
        "movzbl -0x7b(%ebp), %edx\n"
        "movb %dl, -0x4d(%ebp)\n"
        "movzbl -0x7c(%ebp), %edx\n"
        "movb %dl, -0x4e(%ebp)\n"
        "movzbl -0x7d(%ebp), %edx\n"
        "movb %dl, -0x4f(%ebp)\n"
        "movzbl -0x7e(%ebp), %edx\n"
        "movb %dl, -0x50(%ebp)\n"
        "movl -0x84(%ebp), %edx\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "jmp .Lf17c6c4_0017c8d0\n"
        ".Lf17c6c4_0017ca62:\n"
        "movl $str_002a92c4, 8(%ebp)\n" /* line 104 | from */
        /* } scope */
        "addl $0xac, %esp\n" /* line 135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 104 */
        ".Lf17c6c4_0017ca78:\n"
        "movl -0x8c(%ebp), %edx\n" /* line 76 | oldest */
        "leal (%edx, %edx, 4), %esi\n" /* i */
        "movl imp_svs, %eax\n"
        "movl %eax, -0x90(%ebp)\n"
        "leal 0x50(%eax, %esi, 8), %esi\n" /* i */
        "leal 0xc(%esi), %edi\n" /* i, challenge */
        "calll rand\n" /* line 78 */
        "movl %eax, %ebx\n"
        "calll rand\n"
        "shll $0x10, %ebx\n"
        "xorl %eax, %ebx\n"
        "movl -0x90(%ebp), %edx\n"
        "xorl 4(%edx), %ebx\n"
        "movl %ebx, 0xc(%edi)\n" /* challenge */
        "movzwl -0x7a(%ebp), %eax\n" /* line 79 */
        "movw %ax, 8(%edi)\n" /* challenge */
        "movzbl -0x7b(%ebp), %edx\n"
        "movb %dl, 7(%edi)\n" /* challenge */
        "movzbl -0x7c(%ebp), %eax\n"
        "movb %al, 6(%edi)\n" /* challenge */
        "movzbl -0x7d(%ebp), %edx\n"
        "movb %dl, 5(%edi)\n" /* challenge */
        "movzbl -0x7e(%ebp), %eax\n"
        "movb %al, 4(%edi)\n" /* challenge */
        "movl -0x84(%ebp), %edx\n"
        "movl %edx, 0xc(%esi)\n" /* i */
        "movl -0x90(%ebp), %edx\n" /* line 80 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x18(%edi)\n" /* challenge */
        "movl $0, 0x1c(%edi)\n" /* line 81 | challenge */
        "movl 4(%edx), %eax\n" /* line 82 */
        "movl %eax, 0x10(%edi)\n" /* challenge */
        "movl $0, 0x20(%edi)\n" /* line 83 | challenge */
        "movl -0x8c(%ebp), %esi\n" /* oldest, i */
        "jmp .Lf17c6c4_0017c7c1\n"
    );
}

/* line 470 */
__attribute__((naked))
void SV_FreeClient(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 470 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* cl */
        "movl 0x20ca8(%edi), %eax\n" /* line 1063 | cl */
        "testl %eax, %eax\n"
        "jne .Lf17cb08_0017cbb8\n"
        ".Lf17cb08_0017cb22:\n"
        "movl $0, 0x20ca8(%edi)\n" /* line 1067 | cl */
        "movb $0, 0x20c68(%edi)\n" /* line 1068 | cl */
        "movl %edi, %ebx\n" /* cl */
        "movl $8, %esi\n"
        ".Lf17cb08_0017cb3a:\n"
        "movl 0x20cc0(%ebx), %eax\n" /* line 1073 */
        "testl %eax, %eax\n"
        "je .Lf17cb08_0017cb56\n"
        "movl %eax, (%esp)\n" /* line 1075 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x20cc0(%ebx)\n" /* line 1076 */
        ".Lf17cb08_0017cb56:\n"
        "addl $4, %ebx\n"
        "subl $1, %esi\n" /* line 1071 */
        "jne .Lf17cb08_0017cb3a\n"
        "calll SV_Loaded\n" /* line 479 */
        "testb %al, %al\n"
        "je .Lf17cb08_0017cb84\n"
        "movl imp_svs, %eax\n" /* line 483 */
        "movl %edi, %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ClientDisconnect\n"
        ".Lf17cb08_0017cb84:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 487 */
        "movl imp_svs, %eax\n"
        "movl %edi, %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_SetUserinfo\n"
        "movl %edi, 8(%ebp)\n" /* line 489 | cl */
        "addl $0x1c, %esp\n" /* line 490 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp SV_FreeClientScriptId\n" /* line 489 */
        ".Lf17cb08_0017cbb8:\n"
        "movl %eax, (%esp)\n" /* line 1065 */
        "calll FS_FCloseFile\n"
        "jmp .Lf17cb08_0017cb22\n"
    );
}

/* line 824 */
__attribute__((naked))
void SV_DropClient(client_t *drop, const char *reason)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 824 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %eax\n" /* drop */
        "movl %eax, -0x44(%ebp)\n" /* drop */
        "movl 0xc(%ebp), %ecx\n" /* reason */
        "movl %ecx, -0x48(%ebp)\n" /* reason */
        /* { scope 1 */
        "cmpl $1, (%eax)\n" /* line 830 */
        "je .Lf17cbc6_0017ccfa\n"
        "movl $0, 8(%eax)\n" /* line 835 */
        "movl %eax, (%esp)\n" /* line 841 */
        "calll SV_FreeClient\n"
        "movl -0x44(%ebp), %eax\n" /* line 843 | drop */
        "addl $0x20c48, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae400, (%esp)\n" /* "Going to CS_ZOMBIE for %s
" */
        "calll Com_DPrintf\n"
        "movl -0x44(%ebp), %ecx\n" /* line 844 | drop */
        "movl $1, (%ecx)\n"
        "movl 0x20c44(%ecx), %eax\n" /* line 846 */
        "testl %eax, %eax\n"
        "je .Lf17cbc6_0017cd57\n"
        ".Lf17cbc6_0017cc25:\n"
        "movl $str_00215fa4, 4(%esp)\n" /* line 862 */
        "movl -0x48(%ebp), %eax\n" /* reason */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17cbc6_0017cd02\n"
        ".Lf17cbc6_0017cc40:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 864 | reason */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl imp_svs, %esi\n"
        "movl -0x44(%ebp), %eax\n" /* drop */
        "subl 0xc(%esi), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae42c, (%esp)\n" /* "%i:%s %s
" */
        "calll Com_Printf\n"
        "movl -0x44(%ebp), %eax\n" /* line 867 | drop */
        "subl 0xc(%esi), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x4a, 0xc(%esp)\n"
        "movl $str_002ae438, 8(%esp)\n" /* "%c %d" */
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SendServerCommand\n"
        "movl -0x48(%ebp), %ecx\n" /* line 871 | reason */
        "movl %ecx, 0x10(%esp)\n"
        "movl $0x77, 0xc(%esp)\n"
        "movl $str_002a737c, 8(%esp)\n" /* "%c "%s"" */
        "movl $1, 4(%esp)\n"
        "movl -0x44(%ebp), %eax\n" /* drop */
        "movl %eax, (%esp)\n"
        "calll SV_SendServerCommand\n"
        "movl imp_sv_maxclients, %eax\n" /* line 877 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jg .Lf17cbc6_0017ccf2\n"
        "testl %ebx, %ebx\n" /* line 884 */
        "jne .Lf17cbc6_0017ccfa\n"
        /* } scope */
        ".Lf17cbc6_0017cce6:\n"
        "addl $0x7c, %esp\n" /* line 888 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_Heartbeat_f\n" /* line 886 */
        ".Lf17cbc6_0017ccf2:\n"
        "movl 0xc(%esi), %eax\n" /* line 879 */
        "cmpl $1, (%eax)\n"
        "jle .Lf17cbc6_0017cd39\n"
        /* } scope */
        ".Lf17cbc6_0017ccfa:\n"
        "addl $0x7c, %esp\n" /* line 888 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17cbc6_0017cd02:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 863 | reason */
        "movl %ecx, 0x14(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x65, 0xc(%esp)\n"
        "movl $str_002ae41c, 8(%esp)\n" /* "%c "%s^7 %s"" */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SendServerCommand\n"
        "jmp .Lf17cbc6_0017cc40\n"
        ".Lf17cbc6_0017cd39:\n"
        "leal 0x78f0c(%eax), %ecx\n" /* line 881 */
        "xorl %edx, %edx\n"
        ".Lf17cbc6_0017cd41:\n"
        "addl $1, %edx\n" /* line 877 */
        "cmpl %edx, %ebx\n"
        "je .Lf17cbc6_0017cce6\n"
        "movl (%ecx), %eax\n" /* line 879 */
        "addl $0x78f0c, %ecx\n"
        "subl $1, %eax\n"
        "jle .Lf17cbc6_0017cd41\n"
        "jmp .Lf17cbc6_0017ccfa\n"
        ".Lf17cbc6_0017cd57:\n"
        "movl imp_svs, %eax\n" /* line 846 */
        "movl %eax, %edx\n"
        "addl $0x5c, %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* challenge */
        "movl %edx, -0x4c(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf17cbc6_0017cd84\n"
        ".Lf17cbc6_0017cd6b:\n"
        "addl $0x28, -0x3c(%ebp)\n" /* line 851 | challenge */
        "movl -0x4c(%ebp), %edx\n" /* line 824 */
        "leal 0xa05c(%edx), %eax\n"
        "cmpl %eax, -0x3c(%ebp)\n" /* line 851 | challenge */
        "je .Lf17cbc6_0017cc25\n"
        "movl -0x3c(%ebp), %ecx\n" /* challenge */
        ".Lf17cbc6_0017cd84:\n"
        "leal 0x5c(%edx), %eax\n" /* line 853 */
        "movl -0x3c(%ebp), %edx\n" /* challenge */
        "subl %eax, %edx\n"
        "movl (%ecx), %edi\n"
        "movl %edi, -0x30(%ebp)\n"
        "movl 4(%edx, %eax), %esi\n"
        "movl %esi, -0x2c(%ebp)\n"
        "movl 8(%edx, %eax), %ebx\n"
        "movl %ebx, -0x28(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* drop */
        "movl 0x6e5c4(%eax), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x6e5c8(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x6e5cc(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf17cbc6_0017cd6b\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 855 | challenge */
        "movl $0, 0x20(%ecx)\n"
        "jmp .Lf17cbc6_0017cc25\n"
    );
}

/* line 1402 */
void SV_Disconnect_f(client_t *cl)
{
    SV_DropClient(cl, "EXE_DISCONNECTED");
}

/* line 244 */
__attribute__((naked))
void SV_BanClient(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 244 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 8(%ebp), %esi\n" /* cl */
        /* { scope 1 */
        "cmpl $2, 0x6e5c4(%esi)\n" /* line 251 | cl */
        "je .Lf17ce08_0017cef8\n"
        "movl 0x765ec(%esi), %eax\n" /* line 257 | cl */
        "testl %eax, %eax\n"
        "je .Lf17ce08_0017ce50\n"
        "calll SV_IsBannedGuid\n" /* line 263 */
        "testl %eax, %eax\n"
        "je .Lf17ce08_0017ce63\n"
        "movl 0x765ec(%esi), %eax\n" /* line 265 | cl */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae45c, (%esp)\n" /* "This GUID (%i) is already banned
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17ce08_0017ce50:\n"
        "movl $str_002ae440, (%esp)\n" /* line 259 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf17ce08_0017ce5c:\n"
        "addl $0x60, %esp\n" /* line 278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17ce08_0017ce63:\n"
        "movl $2, 8(%esp)\n" /* line 269 */
        "leal -0xc(%ebp), %eax\n" /* file */
        "movl %eax, 4(%esp)\n"
        "movl $str_002adf38, (%esp)\n" /* "ban.txt" */
        "calll FS_FOpenFileByMode\n"
        "testl %eax, %eax\n"
        "js .Lf17ce08_0017ce5c\n"
        "movl $0x40, 8(%esp)\n" /* line 271 */
        "leal 0x20c48(%esi), %eax\n" /* cl */
        "movl %eax, 4(%esp)\n"
        "leal -0x4c(%ebp), %ebx\n" /* cleanName */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %ebx, (%esp)\n" /* line 272 */
        "calll I_CleanStr\n"
        "movl %ebx, 0xc(%esp)\n" /* line 273 */
        "movl 0x765ec(%esi), %eax\n" /* cl */
        "movl %eax, 8(%esp)\n"
        "movl $str_002ae480, 4(%esp)\n" /* "%i %s
" */
        "movl -0xc(%ebp), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "movl -0xc(%ebp), %eax\n" /* line 274 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $str_002ac4ec, 4(%esp)\n" /* line 276 */
        "movl %esi, (%esp)\n" /* cl */
        "calll SV_DropClient\n"
        "movl imp_svs, %eax\n" /* line 277 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x20d10(%esi)\n" /* cl */
        /* } scope */
        "addl $0x60, %esp\n" /* line 278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17ce08_0017cef8:\n"
        "movl $0x65, 0xc(%esp)\n" /* line 253 */
        "movl $str_002ac4cc, 8(%esp)\n" /* "%c "EXE_CANNOTKICKHOSTPLAYER"" */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SendServerCommand\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 521 */
__attribute__((naked))
void SV_DirectConnect(netadr_t from)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 521 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x54c, %esp\n"
        "movzbl 0xf(%ebp), %eax\n"
        "movb %al, -0x511(%ebp)\n"
        "movzbl 0xe(%ebp), %edx\n"
        "movb %dl, -0x512(%ebp)\n"
        "movzbl 0xd(%ebp), %eax\n"
        "movb %al, -0x513(%ebp)\n"
        "movzbl 0xc(%ebp), %edx\n"
        "movb %dl, -0x514(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* from */
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x516(%ebp)\n"
        /* { scope 1 */
        "movl $str_002ae488, (%esp)\n" /* line 540 */
        "calll Com_DPrintf\n"
        "movl $1, (%esp)\n" /* line 542 */
        "calll SV_Cmd_Argv\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x4fc(%ebp), %edx\n" /* userinfo */
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002a7118, 4(%esp)\n" /* line 546 */
        "leal -0x4fc(%ebp), %eax\n" /* userinfo */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* version */
        "cmpl $0x76, %eax\n" /* line 547 */
        "je .Lf17cf24_0017d067\n"
        "movl $str_002167d8, 4(%esp)\n" /* line 551 */
        "movl $str_002ae49c, (%esp)\n" /* "error
EXE_SERVER_IS_DIFFERENT_VER%s
" */
        "calll va\n"
        "movzbl -0x511(%ebp), %edx\n"
        "movb %dl, -0xf5(%ebp)\n"
        "movzbl -0x512(%ebp), %edx\n"
        "movb %dl, -0xf6(%ebp)\n"
        "movzbl -0x513(%ebp), %edx\n"
        "movb %dl, -0xf7(%ebp)\n"
        "movzbl -0x514(%ebp), %edx\n"
        "movb %dl, -0xf8(%ebp)\n"
        "movl %edi, -0xfc(%ebp)\n"
        "movzwl -0x516(%ebp), %edx\n"
        "movw %dx, -0xf4(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl -0xf8(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xf4(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl $0x73, 8(%esp)\n" /* line 552 */
        "movl %ebx, 4(%esp)\n" /* version */
        "movl $str_002ae4c4, (%esp)\n" /* "    rejected connect from protocol version %i (should be %i)" */
        "calll Com_DPrintf\n"
        /* } scope */
        ".Lf17cf24_0017d05c:\n"
        "addl $0x54c, %esp\n" /* line 789 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17cf24_0017d067:\n"
        "movl $str_002a9338, 4(%esp)\n" /* line 557 */
        "leal -0x4fc(%ebp), %eax\n" /* userinfo */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0x524(%ebp)\n" /* challenge */
        "movl $str_002a9344, 4(%esp)\n" /* line 559 */
        "leal -0x4fc(%ebp), %edx\n" /* userinfo */
        "movl %edx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0x528(%ebp)\n" /* qport */
        "movl imp_svs, %eax\n" /* line 565 */
        "movl 0xc(%eax), %ebx\n" /* version */
        "movl imp_sv_maxclients, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %esi\n" /* count */
        "testl %esi, %esi\n" /* count */
        "jle .Lf17cf24_0017d1a2\n"
        "xorl %esi, %esi\n" /* count */
        ".Lf17cf24_0017d0cb:\n"
        "movl 0x6e5c4(%ebx), %ecx\n" /* line 572 | version */
        "movl %ecx, -0xf0(%ebp)\n"
        "movl 0x6e5c8(%ebx), %edx\n" /* version */
        "movl %edx, -0xec(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* version */
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, -0xe8(%ebp)\n"
        "movzbl -0x511(%ebp), %eax\n"
        "movb %al, -0xdd(%ebp)\n"
        "movzbl -0x512(%ebp), %eax\n"
        "movb %al, -0xde(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0xdf(%ebp)\n"
        "movzbl -0x514(%ebp), %eax\n"
        "movb %al, -0xe0(%ebp)\n"
        "movl %edi, -0xe4(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0xdc(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0xe0(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xdc(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "je .Lf17cf24_0017d189\n"
        "movl -0x528(%ebp), %edx\n" /* qport */
        "cmpl 0x6e5d0(%ebx), %edx\n" /* version */
        "je .Lf17cf24_0017d8de\n"
        "movzwl -0x516(%ebp), %eax\n"
        "cmpw %ax, 0x6e5cc(%ebx)\n" /* version */
        "je .Lf17cf24_0017d8de\n"
        ".Lf17cf24_0017d189:\n"
        "addl $1, %esi\n" /* line 565 | count */
        "addl $0x78f0c, %ebx\n" /* version */
        "movl imp_sv_maxclients, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %esi\n" /* count */
        "jl .Lf17cf24_0017d0cb\n"
        ".Lf17cf24_0017d1a2:\n"
        "movzbl -0x511(%ebp), %edx\n" /* line 588 */
        "movb %dl, -0xc5(%ebp)\n"
        "movzbl -0x512(%ebp), %eax\n"
        "movb %al, -0xc6(%ebp)\n"
        "movzbl -0x513(%ebp), %edx\n"
        "movb %dl, -0xc7(%ebp)\n"
        "movzbl -0x514(%ebp), %eax\n"
        "movb %al, -0xc8(%ebp)\n"
        "movl %edi, -0xcc(%ebp)\n"
        "movzwl -0x516(%ebp), %edx\n"
        "movw %dx, -0xc4(%ebp)\n"
        "movl %edi, (%esp)\n"
        "movl -0xc8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xc4(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_IsLocalAddress\n"
        "testl %eax, %eax\n"
        "je .Lf17cf24_0017d58f\n"
        /* { scope 2 */
        "movl $0, -0x52c(%ebp)\n" /* line 636 | guid */
        /* } scope */
        ".Lf17cf24_0017d218:\n"
        "movl imp_svs, %eax\n" /* line 642 */
        "movl 0xc(%eax), %ebx\n" /* ping */
        "movl imp_sv_maxclients, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf17cf24_0017d308\n"
        "xorl %esi, %esi\n" /* count */
        "jmp .Lf17cf24_0017d24b\n"
        ".Lf17cf24_0017d237:\n"
        "addl $1, %esi\n" /* count */
        "addl $0x78f0c, %ebx\n" /* ping */
        "movl (%edx), %eax\n"
        "cmpl %esi, 8(%eax)\n" /* count */
        "jle .Lf17cf24_0017d308\n"
        ".Lf17cf24_0017d24b:\n"
        "movl (%ebx), %eax\n" /* line 644 | ping */
        "testl %eax, %eax\n"
        "je .Lf17cf24_0017d237\n"
        "movl 0x6e5c4(%ebx), %ecx\n" /* line 649 | ping */
        "movl %ecx, -0x6c(%ebp)\n"
        "movl 0x6e5c8(%ebx), %edx\n" /* ping */
        "movl %edx, -0x68(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* ping */
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, -0x64(%ebp)\n"
        "movzbl -0x511(%ebp), %eax\n"
        "movb %al, -0x59(%ebp)\n"
        "movzbl -0x512(%ebp), %eax\n"
        "movb %al, -0x5a(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0x5b(%ebp)\n"
        "movzbl -0x514(%ebp), %eax\n"
        "movb %al, -0x5c(%ebp)\n"
        "movl %edi, -0x60(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0x58(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "je .Lf17cf24_0017d2ee\n"
        "movl -0x528(%ebp), %edx\n" /* qport */
        "cmpl 0x6e5d0(%ebx), %edx\n" /* ping */
        "je .Lf17cf24_0017daa6\n"
        "movzwl -0x516(%ebp), %eax\n"
        "cmpw %ax, 0x6e5cc(%ebx)\n" /* ping */
        "je .Lf17cf24_0017daa6\n"
        ".Lf17cf24_0017d2ee:\n"
        "movl imp_sv_maxclients, %edx\n"
        "addl $1, %esi\n" /* line 642 | count */
        "addl $0x78f0c, %ebx\n" /* ping */
        "movl (%edx), %eax\n"
        "cmpl %esi, 8(%eax)\n" /* count */
        "jg .Lf17cf24_0017d24b\n"
        ".Lf17cf24_0017d308:\n"
        "movl $str_002a8fa0, 4(%esp)\n" /* line 675 */
        "leal -0x4fc(%ebp), %eax\n" /* userinfo */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl imp_sv_privatePassword, %edx\n" /* line 676 */
        "movl (%edx), %edx\n"
        "movl 8(%edx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17cf24_0017d849\n"
        "movl $0, -0x520(%ebp)\n" /* startIndex */
        "movl -0x520(%ebp), %edx\n" /* startIndex */
        ".Lf17cf24_0017d34d:\n"
        "movl imp_sv_maxclients, %eax\n" /* line 687 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x510(%ebp)\n"
        "cmpl %edx, %eax\n"
        "jle .Lf17cf24_0017d860\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 689 */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl -0x520(%ebp), %eax\n" /* startIndex */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl imp_svs, %eax\n"
        "addl 0xc(%eax), %edx\n"
        "movl (%edx), %eax\n" /* line 690 */
        "testl %eax, %eax\n"
        "je .Lf17cf24_0017d8d3\n"
        "leal 0x78f0c(%edx), %ebx\n" /* line 521 */
        "movl %ebx, %ecx\n"
        "movl -0x520(%ebp), %esi\n" /* startIndex */
        ".Lf17cf24_0017d3a4:\n"
        "addl $1, %esi\n" /* line 687 | count */
        "cmpl %esi, -0x510(%ebp)\n" /* count */
        "je .Lf17cf24_0017d860\n"
        "movl %ebx, %edx\n" /* ping */
        "movl (%ecx), %eax\n" /* line 690 */
        "addl $0x78f0c, %ebx\n" /* ping */
        "addl $0x78f0c, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf17cf24_0017d3a4\n"
        ".Lf17cf24_0017d3c7:\n"
        "movl $0, 0x20810(%edx)\n" /* line 708 */
        "movl $0, 0x20814(%edx)\n" /* line 709 */
        "movl %edx, %ebx\n" /* ping */
        ".Lf17cf24_0017d3dd:\n"
        "movl $0x78f0c, 8(%esp)\n" /* line 715 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ping */
        "calll memset\n"
        "movl %ebx, %eax\n" /* line 716 | ping */
        "movl imp_svs, %edx\n"
        "subl 0xc(%edx), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, -0x530(%ebp)\n"
        "movl %eax, (%esp)\n" /* line 717 */
        "calll SV_GentityNum\n"
        "movl %eax, 0x20c44(%ebx)\n" /* line 718 | ping */
        "calll Scr_AllocArray\n" /* line 720 */
        "movw %ax, 0x765f0(%ebx)\n" /* ping */
        "movl -0x524(%ebp), %eax\n" /* line 723 | challenge */
        "movl %eax, 0x765e8(%ebx)\n" /* ping */
        "movl -0x52c(%ebp), %edx\n" /* line 726 | guid */
        "movl %edx, 0x765ec(%ebx)\n" /* ping */
        "movzbl -0x511(%ebp), %eax\n" /* line 729 */
        "movb %al, -0x35(%ebp)\n"
        "movzbl -0x512(%ebp), %edx\n"
        "movb %dl, -0x36(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0x37(%ebp)\n"
        "movzbl -0x514(%ebp), %edx\n"
        "movb %dl, -0x38(%ebp)\n"
        "movl %edi, -0x3c(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0x34(%ebp)\n"
        "movl -0x528(%ebp), %edx\n" /* qport */
        "movl %edx, 0x14(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal 0x6e5b4(%ebx), %eax\n" /* ping */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Netchan_Setup\n"
        "movl $0, 0x78ec4(%ebx)\n" /* line 736 | ping */
        "movb $1, 0x78f08(%ebx)\n" /* line 738 | ping */
        "movl $0x400, 8(%esp)\n" /* line 743 */
        "leal -0x4fc(%ebp), %eax\n" /* userinfo */
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%ebx), %eax\n" /* ping */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movzwl 0x765f0(%ebx), %eax\n" /* line 746 | ping */
        "movl %eax, 4(%esp)\n"
        "movl -0x530(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll ClientConnect\n"
        "movl %eax, -0x51c(%ebp)\n" /* denied */
        "testl %eax, %eax\n" /* line 747 */
        "je .Lf17cf24_0017d983\n"
        "movl %eax, 4(%esp)\n" /* line 749 */
        "movl $str_002ae108, (%esp)\n" /* "error
%s" */
        "calll va\n"
        "movzbl -0x511(%ebp), %edx\n"
        "movb %dl, -0x29(%ebp)\n"
        "movzbl -0x512(%ebp), %edx\n"
        "movb %dl, -0x2a(%ebp)\n"
        "movzbl -0x513(%ebp), %edx\n"
        "movb %dl, -0x2b(%ebp)\n"
        "movzbl -0x514(%ebp), %edx\n"
        "movb %dl, -0x2c(%ebp)\n"
        "movl %edi, -0x30(%ebp)\n"
        "movzwl -0x516(%ebp), %edx\n"
        "movw %dx, -0x28(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl -0x51c(%ebp), %eax\n" /* line 750 | denied */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae618, (%esp)\n" /* "Game rejected a connection: %s.
" */
        "calll Com_DPrintf\n"
        "movl %ebx, (%esp)\n" /* line 751 | ping */
        "calll SV_FreeClientScriptId\n"
        /* } scope */
        "addl $0x54c, %esp\n" /* line 789 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17cf24_0017d58f:\n"
        "movl $0, -0x50c(%ebp)\n" /* line 588 */
        "movl imp_svs, %eax\n"
        "movl %eax, -0x534(%ebp)\n"
        "movl %eax, %ebx\n" /* version */
        "xorl %esi, %esi\n" /* count */
        "jmp .Lf17cf24_0017d5c7\n"
        /* { scope 2 */
        ".Lf17cf24_0017d5aa:\n"
        "addl $1, -0x50c(%ebp)\n" /* line 592 */
        "addl $0x28, %esi\n" /* count */
        "addl $0x28, %ebx\n" /* ping */
        "cmpl $0x400, -0x50c(%ebp)\n"
        "je .Lf17cf24_0017db92\n"
        ".Lf17cf24_0017d5c7:\n"
        "movl 0x5c(%ebx), %ecx\n" /* line 594 | ping */
        "movl %ecx, -0xc0(%ebp)\n"
        "movl 0x60(%ebx), %edx\n" /* ping */
        "movl %edx, -0xbc(%ebp)\n"
        "movl 0x64(%ebx), %eax\n" /* ping */
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, -0xb8(%ebp)\n"
        "movzbl -0x511(%ebp), %eax\n"
        "movb %al, -0xad(%ebp)\n"
        "movzbl -0x512(%ebp), %eax\n"
        "movb %al, -0xae(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0xaf(%ebp)\n"
        "movzbl -0x514(%ebp), %eax\n"
        "movb %al, -0xb0(%ebp)\n"
        "movl %edi, -0xb4(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0xac(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0xb0(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xac(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf17cf24_0017d5aa\n"
        "movl -0x524(%ebp), %edx\n" /* line 596 | challenge */
        "cmpl 0x68(%ebx), %edx\n" /* ping */
        "jne .Lf17cf24_0017d5aa\n"
        "movl -0x534(%ebp), %edx\n" /* line 598 */
        "leal (%esi, %edx), %eax\n" /* count */
        "movl 0x80(%eax), %edx\n"
        "movl %edx, -0x52c(%ebp)\n" /* guid */
        "addl $0x60, %eax\n" /* line 609 */
        "movl 0x18(%eax), %ebx\n" /* ping */
        "testl %ebx, %ebx\n" /* ping */
        "jne .Lf17cf24_0017d697\n"
        "movl -0x534(%ebp), %edx\n" /* line 611 */
        "movl 4(%edx), %ebx\n" /* ping */
        "subl 0x10(%eax), %ebx\n" /* ping */
        "movl %ebx, 0x18(%eax)\n" /* line 612 | ping */
        ".Lf17cf24_0017d697:\n"
        "movzbl -0x511(%ebp), %eax\n" /* line 619 */
        "movb %al, -0x95(%ebp)\n"
        "movzbl -0x512(%ebp), %edx\n"
        "movb %dl, -0x96(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0x97(%ebp)\n"
        "movzbl -0x514(%ebp), %edx\n"
        "movb %dl, -0x98(%ebp)\n"
        "movl %edi, -0x9c(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0x94(%ebp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x98(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* ping */
        "movl -0x50c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_002ae540, (%esp)\n" /* "Client %i connecting with %i challenge ping from %s
" */
        "calll Com_Printf\n"
        "movl -0x50c(%ebp), %edx\n" /* line 621 */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $3, %eax\n"
        "addl imp_svs, %eax\n"
        "movl $1, 0x7c(%eax)\n"
        "movzbl -0x511(%ebp), %eax\n" /* line 624 */
        "movb %al, -0x89(%ebp)\n"
        "movzbl -0x512(%ebp), %edx\n"
        "movb %dl, -0x8a(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0x8b(%ebp)\n"
        "movzbl -0x514(%ebp), %edx\n"
        "movb %dl, -0x8c(%ebp)\n"
        "movl %edi, -0x90(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0x88(%ebp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll Sys_IsLANAddress\n"
        "testl %eax, %eax\n"
        "jne .Lf17cf24_0017d218\n"
        "movl imp_sv_minPing, %eax\n" /* line 626 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf17cf24_0017d7b4\n"
        "cmpl %eax, %ebx\n" /* ping */
        "jl .Lf17cf24_0017db18\n"
        ".Lf17cf24_0017d7b4:\n"
        "movl imp_sv_maxPing, %eax\n" /* line 632 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf17cf24_0017d218\n"
        "cmpl %eax, %ebx\n" /* ping */
        "jle .Lf17cf24_0017d218\n"
        "movzbl -0x511(%ebp), %edx\n" /* line 634 */
        "movb %dl, -0x71(%ebp)\n"
        "movzbl -0x512(%ebp), %eax\n"
        "movb %al, -0x72(%ebp)\n"
        "movzbl -0x513(%ebp), %edx\n"
        "movb %dl, -0x73(%ebp)\n"
        "movzbl -0x514(%ebp), %eax\n"
        "movb %al, -0x74(%ebp)\n"
        "movl %edi, -0x78(%ebp)\n"
        "movzwl -0x516(%ebp), %edx\n"
        "movw %dx, -0x70(%ebp)\n"
        "movl $str_002ae5c0, 0x10(%esp)\n" /* "error
EXE_ERR_LOW_PING_ONLY" */
        "movl %edi, 4(%esp)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl %ebx, 8(%esp)\n" /* line 635 | ping */
        "movl -0x50c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae5dc, (%esp)\n" /* "Client %i rejected on a too high ping: %i
" */
        "calll Com_DPrintf\n"
        "jmp .Lf17cf24_0017d05c\n"
        /* } scope */
        ".Lf17cf24_0017d849:\n"
        "movl imp_sv_privateClients, %eax\n" /* line 683 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x520(%ebp)\n" /* startIndex */
        "movl %eax, %edx\n"
        "jmp .Lf17cf24_0017d34d\n"
        ".Lf17cf24_0017d860:\n"
        "movzbl -0x511(%ebp), %edx\n" /* line 702 */
        "movb %dl, -0x41(%ebp)\n"
        "movzbl -0x512(%ebp), %eax\n"
        "movb %al, -0x42(%ebp)\n"
        "movzbl -0x513(%ebp), %edx\n"
        "movb %dl, -0x43(%ebp)\n"
        "movzbl -0x514(%ebp), %eax\n"
        "movb %al, -0x44(%ebp)\n"
        "movl %edi, -0x48(%ebp)\n"
        "movzwl -0x516(%ebp), %edx\n"
        "movw %dx, -0x40(%ebp)\n"
        "movl $str_002ae678, 0x10(%esp)\n" /* "error
EXE_SERVERISFULL" */
        "movl %edi, 4(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl $str_002ae690, (%esp)\n" /* line 703 */
        "calll Com_DPrintf\n"
        /* } scope */
        "addl $0x54c, %esp\n" /* line 789 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17cf24_0017d8d3:\n"
        "movl -0x520(%ebp), %esi\n" /* line 687 | startIndex, count */
        "jmp .Lf17cf24_0017d3c7\n"
        ".Lf17cf24_0017d8de:\n"
        "movl imp_svs, %eax\n" /* line 577 */
        "movl 4(%eax), %edx\n"
        "subl 0x20d14(%ebx), %edx\n" /* version */
        "movl imp_sv_reconnectlimit, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "cmpl %eax, %edx\n"
        "jge .Lf17cf24_0017d1a2\n"
        "movzbl -0x511(%ebp), %edx\n" /* line 579 */
        "movb %dl, -0xd1(%ebp)\n"
        "movzbl -0x512(%ebp), %eax\n"
        "movb %al, -0xd2(%ebp)\n"
        "movzbl -0x513(%ebp), %edx\n"
        "movb %dl, -0xd3(%ebp)\n"
        "movzbl -0x514(%ebp), %eax\n"
        "movb %al, -0xd4(%ebp)\n"
        "movl %edi, -0xd8(%ebp)\n"
        "movzwl -0x516(%ebp), %edx\n"
        "movw %dx, -0xd0(%ebp)\n"
        "movl %edi, (%esp)\n"
        "movl -0xd4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xd0(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae504, (%esp)\n" /* "%s:reconnect rejected : too soon
" */
        "calll Com_DPrintf\n"
        "jmp .Lf17cf24_0017d05c\n"
        ".Lf17cf24_0017d983:\n"
        "movl 0x765ec(%ebx), %eax\n" /* line 755 | ping */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x530(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x20c48(%ebx), %eax\n" /* ping */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae63c, (%esp)\n" /* "Going from CS_FREE to CS_CONNECTED for %s (num %i guid %i)
" */
        "calll Com_Printf\n"
        "movl $2, (%ebx)\n" /* line 757 | ping */
        "movl imp_svs, %edx\n" /* line 758 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x20d18(%ebx)\n" /* ping */
        "movl 4(%edx), %eax\n" /* line 759 */
        "movl %eax, 0x20d10(%ebx)\n" /* ping */
        "movl 4(%edx), %eax\n" /* line 760 */
        "movl %eax, 0x20d14(%ebx)\n" /* ping */
        "movl %ebx, (%esp)\n" /* line 762 | ping */
        "calll SV_UserinfoChanged\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 765 | count */
        "movl imp_svs, %edx\n"
        "movl $0, 0x78(%edx, %eax, 8)\n"
        "movzbl -0x511(%ebp), %eax\n" /* line 768 */
        "movb %al, -0x1d(%ebp)\n"
        "movzbl -0x512(%ebp), %edx\n"
        "movb %dl, -0x1e(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x514(%ebp), %edx\n"
        "movb %dl, -0x20(%ebp)\n"
        "movl %edi, -0x24(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0x1c(%ebp)\n"
        "movl $str_002a949c, 0x10(%esp)\n" /* "connectResponse" */
        "movl %edi, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl $0xffffffff, 0x2081c(%ebx)\n" /* line 773 | ping */
        "movl imp_sv_maxclients, %eax\n" /* line 778 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* ping */
        "testl %ebx, %ebx\n" /* ping */
        "jg .Lf17cf24_0017da75\n"
        "xorl %esi, %esi\n" /* count */
        ".Lf17cf24_0017da63:\n"
        "cmpl %ebx, %esi\n" /* line 785 | ping, count */
        "jne .Lf17cf24_0017d05c\n"
        "calll SV_Heartbeat_f\n" /* line 787 */
        "jmp .Lf17cf24_0017d05c\n"
        ".Lf17cf24_0017da75:\n"
        "movl imp_svs, %eax\n" /* line 778 */
        "movl 0xc(%eax), %edx\n"
        "xorl %ecx, %ecx\n"
        "xorl %esi, %esi\n" /* count */
        ".Lf17cf24_0017da81:\n"
        "leal 1(%esi), %eax\n" /* line 782 | count */
        "cmpl $2, (%edx)\n"
        "cmovgel %eax, %esi\n" /* count */
        "addl $1, %ecx\n" /* line 778 */
        "addl $0x78f0c, %edx\n"
        "cmpl %ebx, %ecx\n" /* ping */
        "jne .Lf17cf24_0017da81\n"
        "cmpl $1, %esi\n" /* line 785 | count */
        "jne .Lf17cf24_0017da63\n"
        "calll SV_Heartbeat_f\n" /* line 787 */
        "jmp .Lf17cf24_0017d05c\n"
        ".Lf17cf24_0017daa6:\n"
        "movzbl -0x511(%ebp), %edx\n" /* line 654 */
        "movb %dl, -0x4d(%ebp)\n"
        "movzbl -0x512(%ebp), %eax\n"
        "movb %al, -0x4e(%ebp)\n"
        "movzbl -0x513(%ebp), %edx\n"
        "movb %dl, -0x4f(%ebp)\n"
        "movzbl -0x514(%ebp), %eax\n"
        "movb %al, -0x50(%ebp)\n"
        "movl %edi, -0x54(%ebp)\n"
        "movzwl -0x516(%ebp), %edx\n"
        "movw %dx, -0x4c(%ebp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae608, (%esp)\n" /* "%s:reconnect
" */
        "calll Com_Printf\n"
        "cmpl $1, (%ebx)\n" /* line 655 | ping */
        "jle .Lf17cf24_0017d3dd\n"
        "movl %ebx, (%esp)\n" /* line 656 | ping */
        "calll SV_FreeClient\n"
        "jmp .Lf17cf24_0017d3dd\n"
        /* { scope 2 */
        ".Lf17cf24_0017db18:\n"
        "movzbl -0x511(%ebp), %eax\n" /* line 628 */
        "movb %al, -0x7d(%ebp)\n"
        "movzbl -0x512(%ebp), %edx\n"
        "movb %dl, -0x7e(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0x7f(%ebp)\n"
        "movzbl -0x514(%ebp), %edx\n"
        "movb %dl, -0x80(%ebp)\n"
        "movl %edi, -0x84(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0x7c(%ebp)\n"
        "movl $str_002ae578, 0x10(%esp)\n" /* "error
EXE_ERR_HIGH_PING_ONLY" */
        "movl %edi, 4(%esp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl -0x50c(%ebp), %edx\n" /* line 629 */
        "movl %edx, 4(%esp)\n"
        "movl $str_002ae598, (%esp)\n" /* "Client %i rejected on a too low ping
" */
        "calll Com_DPrintf\n"
        "jmp .Lf17cf24_0017d05c\n"
        ".Lf17cf24_0017db92:\n"
        "movzbl -0x511(%ebp), %eax\n" /* line 605 */
        "movb %al, -0xa1(%ebp)\n"
        "movzbl -0x512(%ebp), %edx\n"
        "movb %dl, -0xa2(%ebp)\n"
        "movzbl -0x513(%ebp), %eax\n"
        "movb %al, -0xa3(%ebp)\n"
        "movzbl -0x514(%ebp), %edx\n"
        "movb %dl, -0xa4(%ebp)\n"
        "movl %edi, -0xa8(%ebp)\n"
        "movzwl -0x516(%ebp), %eax\n"
        "movw %ax, -0xa0(%ebp)\n"
        "movl $str_002ae528, 0x10(%esp)\n" /* "error
EXE_BAD_CHALLENGE" */
        "movl %edi, 4(%esp)\n"
        "movl -0xa4(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xa0(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "jmp .Lf17cf24_0017d05c\n"
    );
}

/* line 499 */
__attribute__((naked))
void SV_FreeClients(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 499 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl imp_svs, %ecx\n" /* line 504 */
        "movl 0xc(%ecx), %ebx\n" /* cl */
        "movl imp_sv_maxclients, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf17dc0c_0017dc69\n"
        "xorl %esi, %esi\n" /* i */
        "movl %edx, %edi\n"
        ".Lf17dc0c_0017dc31:\n"
        "cmpl $1, (%ebx)\n" /* line 506 | cl */
        "jle .Lf17dc0c_0017dc40\n"
        "movl %ebx, (%esp)\n" /* line 507 | cl */
        "calll SV_FreeClient\n"
        "movl %edi, %edx\n"
        ".Lf17dc0c_0017dc40:\n"
        "addl $1, %esi\n" /* line 504 | i */
        "addl $0x78f0c, %ebx\n" /* cl */
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jl .Lf17dc0c_0017dc31\n"
        "movl imp_svs, %ecx\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, (%esp)\n" /* line 510 */
        "calll Z_VirtualFreeInternal\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 511 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17dc0c_0017dc69:\n"
        "movl %ebx, %eax\n" /* cl */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 510 */
        "calll Z_VirtualFreeInternal\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 511 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1090 */
__attribute__((naked))
void SV_StopDownload_f(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1090 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cl */
        "cmpb $0, 0x20c68(%ebx)\n" /* line 1092 | cl */
        "jne .Lf17dc7c_0017dcdb\n"
        "movl 0x20ca8(%ebx), %eax\n" /* line 1063 */
        "testl %eax, %eax\n"
        "jne .Lf17dc7c_0017dd14\n"
        ".Lf17dc7c_0017dc9a:\n"
        "movl $0, 0x20ca8(%ebx)\n" /* line 1067 */
        "movb $0, 0x20c68(%ebx)\n" /* line 1068 */
        "movl $8, %esi\n"
        ".Lf17dc7c_0017dcb0:\n"
        "movl 0x20cc0(%ebx), %eax\n" /* line 1073 */
        "testl %eax, %eax\n"
        "je .Lf17dc7c_0017dccc\n"
        "movl %eax, (%esp)\n" /* line 1075 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x20cc0(%ebx)\n" /* line 1076 */
        ".Lf17dc7c_0017dccc:\n"
        "addl $4, %ebx\n"
        "subl $1, %esi\n" /* line 1071 */
        "jne .Lf17dc7c_0017dcb0\n"
        "addl $0x10, %esp\n" /* line 1096 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17dc7c_0017dcdb:\n"
        "leal 0x20c68(%ebx), %eax\n" /* line 1093 | cl */
        "movl %eax, 8(%esp)\n"
        "movl imp_svs, %eax\n"
        "movl %ebx, %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae6a8, (%esp)\n" /* "clientDownload: %d : file "%s" aborted
" */
        "calll Com_DPrintf\n"
        "movl 0x20ca8(%ebx), %eax\n" /* line 1063 */
        "testl %eax, %eax\n"
        "je .Lf17dc7c_0017dc9a\n"
        ".Lf17dc7c_0017dd14:\n"
        "movl %eax, (%esp)\n" /* line 1065 */
        "calll FS_FCloseFile\n"
        "jmp .Lf17dc7c_0017dc9a\n"
    );
}

/* line 1142 */
__attribute__((naked))
void SV_NextDownload_f(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1142 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cl */
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 1144 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, (%esp)\n" /* block */
        "calll atoi\n"
        "cmpl 0x20cb4(%ebx), %eax\n" /* line 1146 | cl */
        "je .Lf17dd22_0017dd60\n"
        "movl $str_002ae734, 4(%esp)\n" /* line 1166 */
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_DropClient\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1167 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17dd22_0017dd60:\n"
        "movl %eax, 8(%esp)\n" /* line 1148 */
        "movl imp_svs, %esi\n"
        "movl %ebx, %eax\n" /* cl */
        "subl 0xc(%esi), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae6d0, (%esp)\n" /* "clientDownload: %d : client acknowledge of block %d
" */
        "calll Com_DPrintf\n"
        "movl 0x20cb4(%ebx), %edx\n" /* line 1151 | cl */
        "movl %edx, %eax\n"
        "andl $0x80000007, %eax\n"
        "js .Lf17dd22_0017de32\n"
        ".Lf17dd22_0017dd9b:\n"
        "movl 0x20ce0(%ebx, %eax, 4), %eax\n" /* cl */
        "testl %eax, %eax\n"
        "jne .Lf17dd22_0017de19\n"
        "leal 0x20c68(%ebx), %eax\n" /* line 1153 | cl */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, %eax\n" /* cl */
        "subl 0xc(%esi), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae708, (%esp)\n" /* "clientDownload: %d : file "%s" completed
" */
        "calll Com_Printf\n"
        "movl 0x20ca8(%ebx), %eax\n" /* line 1063 */
        "testl %eax, %eax\n"
        "jne .Lf17dd22_0017de40\n"
        ".Lf17dd22_0017ddd8:\n"
        "movl $0, 0x20ca8(%ebx)\n" /* line 1067 */
        "movb $0, 0x20c68(%ebx)\n" /* line 1068 */
        "movl $8, %esi\n"
        ".Lf17dd22_0017ddee:\n"
        "movl 0x20cc0(%ebx), %eax\n" /* line 1073 */
        "testl %eax, %eax\n"
        "je .Lf17dd22_0017de0a\n"
        "movl %eax, (%esp)\n" /* line 1075 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x20cc0(%ebx)\n" /* line 1076 */
        ".Lf17dd22_0017de0a:\n"
        "addl $4, %ebx\n"
        "subl $1, %esi\n" /* line 1071 */
        "jne .Lf17dd22_0017ddee\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1167 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17dd22_0017de19:\n"
        "movl 4(%esi), %eax\n" /* line 1158 */
        "movl %eax, 0x20d04(%ebx)\n" /* cl */
        "leal 1(%edx), %eax\n" /* line 1159 */
        "movl %eax, 0x20cb4(%ebx)\n" /* cl */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1167 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17dd22_0017de32:\n"
        "subl $1, %eax\n" /* line 1151 */
        "orl $0xfffffff8, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf17dd22_0017dd9b\n"
        ".Lf17dd22_0017de40:\n"
        "movl %eax, (%esp)\n" /* line 1065 */
        "calll FS_FCloseFile\n"
        "jmp .Lf17dd22_0017ddd8\n"
    );
}

/* line 1175 */
__attribute__((naked))
void SV_BeginDownload_f(client_t *cl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1175 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* cl */
        "movl 0x20ca8(%edi), %eax\n" /* line 1063 */
        "testl %eax, %eax\n"
        "jne .Lf17de4a_0017deca\n"
        ".Lf17de4a_0017de60:\n"
        "movl $0, 0x20ca8(%edi)\n" /* line 1067 */
        "movb $0, 0x20c68(%edi)\n" /* line 1068 */
        "movl %edi, %ebx\n"
        "movl $8, %esi\n"
        ".Lf17de4a_0017de78:\n"
        "movl 0x20cc0(%ebx), %eax\n" /* line 1073 */
        "testl %eax, %eax\n"
        "je .Lf17de4a_0017de94\n"
        "movl %eax, (%esp)\n" /* line 1075 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x20cc0(%ebx)\n" /* line 1076 */
        ".Lf17de4a_0017de94:\n"
        "addl $4, %ebx\n"
        "subl $1, %esi\n" /* line 1071 */
        "jne .Lf17de4a_0017de78\n"
        "movl $1, (%esp)\n" /* line 1183 */
        "calll SV_Cmd_Argv\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x20c68(%edi), %eax\n" /* cl */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x1c, %esp\n" /* line 1184 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17de4a_0017deca:\n"
        "movl %eax, (%esp)\n" /* line 1065 */
        "calll FS_FCloseFile\n"
        "jmp .Lf17de4a_0017de60\n"
    );
}

/* line 1923 */
__attribute__((naked))
void SV_UserMove(client_t *cl, msg_t *msg, qboolean delta)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1923 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3cc, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1932 | delta */
        "testl %eax, %eax\n"
        "je .Lf17ded4_0017df15\n"
        "movl 8(%ebp), %edx\n" /* line 1934 | cl */
        "movl 0x20818(%edx), %eax\n"
        "movl %eax, 0x20d08(%edx)\n"
        "movl 8(%ebp), %edx\n" /* line 1941 | cl */
        "movl 0x20814(%edx), %eax\n"
        "subl 0x20810(%edx), %eax\n"
        "cmpl $0x7f, %eax\n"
        "jle .Lf17ded4_0017df36\n"
        /* } scope */
        ".Lf17ded4_0017df0a:\n"
        "addl $0x3cc, %esp\n" /* line 2142 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17ded4_0017df15:\n"
        "movl 8(%ebp), %ecx\n" /* line 1938 | cl */
        "movl $0xffffffff, 0x20d08(%ecx)\n"
        "movl 8(%ebp), %edx\n" /* line 1941 | cl */
        "movl 0x20814(%edx), %eax\n"
        "subl 0x20810(%edx), %eax\n"
        "cmpl $0x7f, %eax\n"
        "jg .Lf17ded4_0017df0a\n"
        ".Lf17ded4_0017df36:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1944 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadByte\n"
        "movl %eax, -0x3c0(%ebp)\n" /* cmdCount */
        "testl %eax, %eax\n" /* line 1946 */
        "jle .Lf17ded4_0017e288\n"
        "cmpl $0x20, -0x3c0(%ebp)\n" /* line 1953 | cmdCount */
        "jle .Lf17ded4_0017df6f\n"
        "movl $str_002ae754, (%esp)\n" /* line 1956 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x3cc, %esp\n" /* line 2142 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17ded4_0017df6f:\n"
        "movl 8(%ebp), %eax\n" /* line 1963 | cl */
        "movl 0x20818(%eax), %eax\n"
        "movl %eax, -0x3bc(%ebp)\n"
        "movl imp_sv, %eax\n"
        "movl 0xc(%eax), %edx\n"
        "xorl %edx, -0x3bc(%ebp)\n"
        "movl $0x20, 4(%esp)\n" /* line 1965 */
        "movl 8(%ebp), %ecx\n" /* cl */
        "movl 0x20810(%ecx), %eax\n"
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal 0x400(%edx, %eax, 8), %eax\n"
        "leal 0xc(%ecx, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_HashKey\n"
        "xorl %eax, -0x3bc(%ebp)\n"
        "movl imp_svs, %eax\n" /* line 1975 */
        "movl 8(%ebp), %edx\n" /* cl */
        "subl 0xc(%eax), %edx\n"
        "movl %edx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameClientNum\n"
        "movl %eax, %esi\n" /* ps */
        "leal -0x34(%ebp), %ebx\n" /* line 1979 | nullcmd, cmd */
        "movl %ebx, 4(%esp)\n" /* cmd */
        "movl %eax, (%esp)\n"
        "calll MSG_SetDefaultUserCmd\n"
        "movl %ebx, %eax\n" /* cmd */
        "movl $0, -0x3c4(%ebp)\n" /* i */
        "leal -0x3b4(%ebp), %edi\n" /* cmds */
        ".Lf17ded4_0017dfff:\n"
        "movl %edi, %ebx\n" /* line 1984 | cmd */
        "movl %edi, 0xc(%esp)\n" /* line 1985 */
        "movl %eax, 8(%esp)\n"
        "movl -0x3bc(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadDeltaUsercmdKey\n"
        "movzbl 8(%edi), %eax\n" /* line 1988 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ps */
        "calll BG_IsWeaponValid\n"
        "testb %al, %al\n"
        "jne .Lf17ded4_0017e03b\n"
        "movl 0xd4(%esi), %eax\n" /* line 1989 | ps */
        "movb %al, 8(%edi)\n"
        ".Lf17ded4_0017e03b:\n"
        "movzbl 9(%ebx), %eax\n" /* line 1992 | cmd */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ps */
        "calll BG_IsWeaponValid\n"
        "testb %al, %al\n"
        "jne .Lf17ded4_0017e058\n"
        "movl 0xd0(%esi), %eax\n" /* line 1993 | ps */
        "movb %al, 9(%ebx)\n" /* cmd */
        ".Lf17ded4_0017e058:\n"
        "addl $1, -0x3c4(%ebp)\n" /* line 1982 | i */
        "addl $0x1c, %edi\n"
        "movl %ebx, %eax\n" /* cmd */
        "movl -0x3c4(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x3c0(%ebp)\n" /* cmdCount */
        "jne .Lf17ded4_0017dfff\n"
        "movl 8(%ebp), %ecx\n" /* line 2090 | cl */
        "movl 0x20818(%ecx), %edx\n"
        "andl $0x1f, %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl imp_svs, %esi\n" /* ps */
        "movl 4(%esi), %edx\n" /* ps */
        "movl 8(%ebp), %ecx\n" /* cl */
        "movl %edx, 0x233e0(%ecx, %eax, 4)\n"
        "cmpl $3, (%ecx)\n" /* line 2094 */
        "je .Lf17ded4_0017e1c5\n"
        ".Lf17ded4_0017e0a9:\n"
        "movl imp_sv_pure, %eax\n" /* line 2104 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17ded4_0017e0e3\n"
        "movl 8(%ebp), %ecx\n" /* cl */
        "movl 0x6e5b0(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf17ded4_0017e299\n"
        "movl %ecx, %eax\n"
        ".Lf17ded4_0017e0c9:\n"
        "cmpl $4, (%eax)\n" /* line 2111 */
        "je .Lf17ded4_0017e0e8\n"
        "movl $0xffffffff, 0x20d08(%eax)\n" /* line 2113 */
        /* } scope */
        "addl $0x3cc, %esp\n" /* line 2142 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17ded4_0017e0e3:\n"
        "movl 8(%ebp), %eax\n" /* cl */
        "jmp .Lf17ded4_0017e0c9\n"
        /* { scope 1 */
        ".Lf17ded4_0017e0e8:\n"
        "movl -0x3c0(%ebp), %edx\n" /* line 2114 | cmdCount */
        "subl $1, %edx\n"
        "xorl %edi, %edi\n"
        "leal -0x3b4(%ebp), %esi\n" /* cmds, ps */
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x3c8(%ebp)\n"
        "movl %esi, %ebx\n" /* ps, cmd */
        "jmp .Lf17ded4_0017e12a\n"
        ".Lf17ded4_0017e10f:\n"
        "addl $1, %edi\n" /* line 2120 */
        "addl $0x1c, %ebx\n" /* cmd */
        "addl $0x1c, %esi\n" /* ps */
        "cmpl %edi, -0x3c0(%ebp)\n" /* cmdCount */
        "je .Lf17ded4_0017df0a\n"
        "movl -0x3c8(%ebp), %edx\n"
        ".Lf17ded4_0017e12a:\n"
        "movl (%esi), %eax\n" /* line 2123 | ps */
        "cmpl -0x3b4(%edx, %ebp), %eax\n"
        "jg .Lf17ded4_0017e10f\n"
        "movl 8(%ebp), %ecx\n" /* line 2134 | cl */
        "cmpl 0x20824(%ecx), %eax\n"
        "jle .Lf17ded4_0017e10f\n"
        "movl (%ebx), %edx\n" /* line 1898 */
        "movl %edx, 0x20824(%ecx)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 0x20828(%ecx)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x2082c(%ecx)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0x20830(%ecx)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x20834(%ecx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 0x20838(%ecx)\n"
        "movl 0x18(%ebx), %eax\n"
        "movl %eax, 0x2083c(%ecx)\n"
        "cmpl $4, (%ecx)\n" /* line 1900 */
        "jne .Lf17ded4_0017e10f\n"
        "movl %edx, 4(%esp)\n" /* line 1906 */
        "movl %ecx, %eax\n"
        "movl imp_svs, %edx\n"
        "subl 0xc(%edx), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SetLastServerTime\n"
        "movl 8(%ebp), %eax\n" /* line 1908 | cl */
        "movl imp_svs, %ecx\n"
        "subl 0xc(%ecx), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ClientThink\n"
        "jmp .Lf17ded4_0017e10f\n"
        /* { scope 2 */
        ".Lf17ded4_0017e1c5:\n"
        "movl %ecx, %eax\n" /* line 1023 */
        "addl $0x20c48, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae204, (%esp)\n" /* "Going from CS_PRIMED to CS_ACTIVE for %s
" */
        "calll Com_DPrintf\n"
        "movl 8(%ebp), %eax\n" /* line 1024 | cl */
        "movl $4, (%eax)\n"
        "movl %eax, %ebx\n" /* line 1027 */
        "subl 0xc(%esi), %ebx\n"
        "sarl $2, %ebx\n"
        "imull $0x3789a4eb, %ebx, %ebx\n"
        "movl %ebx, (%esp)\n" /* line 1028 */
        "calll SV_GentityNum\n"
        "movl %ebx, (%eax)\n" /* line 1029 */
        "movl 8(%ebp), %edx\n" /* line 1030 | cl */
        "movl %eax, 0x20c44(%edx)\n"
        "movl $0xffffffff, 0x20d08(%edx)\n" /* line 1032 */
        "movl 4(%esi), %eax\n" /* line 1033 */
        "movl %eax, 0x20d18(%edx)\n"
        "movl -0x3b4(%ebp), %eax\n" /* line 1034 | cmds */
        "movl %eax, 0x20824(%edx)\n"
        "movl -0x3b0(%ebp), %eax\n"
        "movl %eax, 0x20828(%edx)\n"
        "movl -0x3ac(%ebp), %eax\n"
        "movl %eax, 0x2082c(%edx)\n"
        "movl -0x3a8(%ebp), %eax\n"
        "movl %eax, 0x20830(%edx)\n"
        "movl -0x3a4(%ebp), %eax\n"
        "movl %eax, 0x20834(%edx)\n"
        "movl -0x3a0(%ebp), %eax\n"
        "movl %eax, 0x20838(%edx)\n"
        "movl -0x39c(%ebp), %eax\n"
        "movl %eax, 0x2083c(%edx)\n"
        "movl %edx, %eax\n" /* line 1037 */
        "subl 0xc(%esi), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ClientBegin\n"
        "jmp .Lf17ded4_0017e0a9\n"
        /* } scope */
        ".Lf17ded4_0017e288:\n"
        "movl $str_002ae744, (%esp)\n" /* line 1949 */
        "calll Com_Printf\n"
        "jmp .Lf17ded4_0017df0a\n"
        ".Lf17ded4_0017e299:\n"
        "movl $str_002ae774, 4(%esp)\n" /* line 2106 */
        "movl %ecx, (%esp)\n"
        "calll SV_DropClient\n"
        "jmp .Lf17ded4_0017df0a\n"
    );
}

/* line 2167 */
__attribute__((naked))
void SV_ExecuteClientMessage(client_t *cl, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2167 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x404c, %esp\n"
        "movl 8(%ebp), %edi\n" /* cl */
        "movl 0xc(%ebp), %ebx\n" /* msg */
        /* { scope 1 */
        "movl $0x4000, 8(%esp)\n" /* line 2173 */
        "leal -0x4048(%ebp), %esi\n" /* msgCompressed_buf, c */
        "movl %esi, 4(%esp)\n" /* c */
        "leal -0x48(%ebp), %eax\n" /* msgCompressed */
        "movl %eax, (%esp)\n"
        "calll MSG_Init\n"
        "movl 0x10(%ebx), %edx\n" /* line 2174 | msg */
        "movl 0xc(%ebx), %eax\n" /* msg */
        "subl %edx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* c */
        "addl 4(%ebx), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadBitsCompress\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x765f8(%edi), %edx\n" /* line 2183 | cl */
        "movl imp_sv_serverId_value, %eax\n"
        "movl (%eax), %eax\n"
        /* DEBUG: print serverId comparison */
        "pushl %eax\n"
        "pushl %edx\n"
        "pushl (%edi)\n"
        "pushl %eax\n"
        "pushl %edx\n"
        "pushl $.Lsvexec_fmt\n"
        "calll SV_ExecDbg\n"
        "addl $16, %esp\n"
        "popl %edx\n"
        "popl %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf17e2ae_0017e319\n"
        "cmpb $0, 0x20c68(%edi)\n" /* cl */
        "je .Lf17e2ae_0017e44b\n"
        ".Lf17e2ae_0017e319:\n"
        "movl $3, 4(%esp)\n" /* line 2211 */
        "leal -0x48(%ebp), %eax\n" /* msgCompressed */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadBits\n"
        "movl %eax, %esi\n" /* c */
        /* DBG: print message type */
        "pushl %eax\n"
        "pushl (%edi)\n"
        "pushl %eax\n"
        "pushl $.Lsvexec_msgtype_fmt\n"
        "calll Com_Printf\n"
        "addl $12, %esp\n"
        "popl %eax\n"
        "movl %eax, %esi\n"
        "cmpl $3, %eax\n" /* line 2212 */
        "je .Lf17e2ae_0017e663\n"
        "cmpl $2, %eax\n" /* line 2214 */
        "jne .Lf17e2ae_0017e663\n"
        /* { scope 2 */
        "leal -0x48(%ebp), %eax\n" /* line 1832 | msgCompressed */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, %ebx\n" /* seq */
        "leal -0x48(%ebp), %eax\n" /* line 1833 | msgCompressed */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadString\n"
        "movl %eax, %esi\n" /* s */
        /* DBG: print client command info */
        "pushl %ebx\n"
        "pushl %esi\n"
        "pushl %esi\n"
        "pushl 0x20840(%edi)\n"
        "pushl %ebx\n"
        "pushl $.Lsvexec_clicmd_fmt\n"
        "calll Com_Printf\n"
        "addl $16, %esp\n"
        "popl %esi\n"
        "popl %ebx\n"
        "cmpl 0x20840(%edi), %ebx\n" /* line 1836 | seq */
        "jle .Lf17e2ae_0017e437\n"
        "movl imp_sv_showCommands, %eax\n" /* line 1841 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf17e2ae_0017e50e\n"
        ".Lf17e2ae_0017e377:\n"
        "movl 0x20840(%edi), %edx\n" /* line 1845 */
        "leal 1(%edx), %eax\n"
        "cmpl %eax, %ebx\n" /* seq */
        "jle .Lf17e2ae_0017e3be\n"
        /* DBG: about to drop client */
        "pushl %ebx\n"
        "pushl %edx\n"
        "pushl %edx\n"
        "pushl %ebx\n"
        "pushl $.Lsvexec_drop_fmt\n"
        "calll Com_Printf\n"
        "addl $12, %esp\n"
        "popl %edx\n"
        "popl %ebx\n"
        "subl %edx, %ebx\n" /* line 1847 | seq */
        "leal 1(%ebx), %eax\n" /* seq */
        "movl %eax, 8(%esp)\n"
        "leal 0x20c48(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae7d0, (%esp)\n" /* "Client %s lost %i clientCommands
" */
        "calll Com_Printf\n"
        "movl $str_002ae7f4, 4(%esp)\n" /* line 1848 */
        "movl %edi, (%esp)\n"
        "calll SV_DropClient\n"
        /* } scope */
        /* } scope */
        ".Lf17e2ae_0017e3b3:\n"
        "addl $0x404c, %esp\n" /* line 2241 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf17e2ae_0017e3be:\n"
        "movl $5, 8(%esp)\n" /* line 1853 */
        "movl %esi, 4(%esp)\n" /* s */
        "movl $str_002ae810, (%esp)\n" /* "team " */
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17e2ae_0017e5a4\n"
        ".Lf17e2ae_0017e3de:\n"
        "xorl %edx, %edx\n"
        ".Lf17e2ae_0017e3e0:\n"
        "movl imp_legacyHacks, %eax\n" /* line 1866 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf17e2ae_0017e527\n"
        ".Lf17e2ae_0017e3f2:\n"
        "testl %edx, %edx\n" /* line 1875 */
        "jne .Lf17e2ae_0017e587\n"
        ".Lf17e2ae_0017e3fa:\n"
        "movl $1, %edx\n" /* line 1876 */
        ".Lf17e2ae_0017e3ff:\n"
        "movl %edx, 8(%esp)\n" /* line 1878 */
        "movl %esi, 4(%esp)\n" /* s */
        "movl %edi, (%esp)\n"
        "calll SV_ExecuteClientCommand\n"
        "movl %ebx, 0x20840(%edi)\n" /* line 1880 | seq */
        "movl %esi, 0xc(%esp)\n" /* line 1881 | s */
        "movl $str_00216058, 8(%esp)\n" /* "%s" */
        "movl $0x400, 4(%esp)\n"
        "leal 0x20844(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        /* } scope */
        ".Lf17e2ae_0017e437:\n"
        "cmpl $1, (%edi)\n" /* line 2218 | cl */
        "jne .Lf17e2ae_0017e319\n"
        /* } scope */
        "addl $0x404c, %esp\n" /* line 2241 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17e2ae_0017e44b:\n"
        "andl $0xf0, %edx\n" /* line 2185 */
        "andl $0xf0, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf17e2ae_0017e5ee\n"
        "movl 0x20818(%edi), %eax\n" /* line 2196 | cl */
        "cmpl 0x2081c(%edi), %eax\n" /* cl */
        "jle .Lf17e2ae_0017e3b3\n"
        /* Skip gamestate resend if either:
           1. Unsent fragments are pending (let current delivery complete)
           2. Client is still CS_PRIMED (3) — hasn't processed the
              current gamestate yet; old packets with stale serverId
              will arrive until the client catches up. */
        "cmpl $0, 0x725dc(%edi)\n" /* client->netchan.unsentFragments */
        "jne .Lf17e2ae_0017e3b3\n" /* skip if fragments pending */
        "cmpl $3, (%edi)\n"        /* client->state == CS_PRIMED? */
        "je .Lf17e2ae_0017e3b3\n"  /* skip if still primed */
        "leal 0x20c48(%edi), %eax\n" /* line 2198 | cl */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae794, (%esp)\n" /* "%s : dropped gamestate, resending
" */
        "calll Com_DPrintf\n"
        "movl %edi, (%esp)\n" /* line 2199 | cl */
        "calll SV_SendClientGameState\n"
        "movl imp_net_lanauthorize, %eax\n" /* line 2201 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf17e2ae_0017e4ce\n"
        "movl 0x6e5c4(%edi), %ecx\n" /* cl */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 0x6e5c8(%edi), %edx\n" /* cl */
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x6e5cc(%edi), %eax\n" /* cl */
        "movl %eax, -0x28(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll Sys_IsLANAddress\n"
        "testl %eax, %eax\n"
        "jne .Lf17e2ae_0017e3b3\n"
        ".Lf17e2ae_0017e4ce:\n"
        "movl 0x765e8(%edi), %ebx\n" /* line 2202 | cl, msg */
        "movl 0x6e5c4(%edi), %ecx\n" /* cl */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x6e5c8(%edi), %edx\n" /* cl */
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x6e5cc(%edi), %eax\n" /* cl */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, 0xc(%esp)\n" /* msg */
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll SV_AuthorizeRequest\n"
        /* } scope */
        "addl $0x404c, %esp\n" /* line 2241 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf17e2ae_0017e50e:\n"
        "movl %esi, 8(%esp)\n" /* line 1842 | s */
        "movl %ebx, 4(%esp)\n" /* seq */
        "movl $str_002ae7b8, (%esp)\n" /* "clientCommand: %i : %s
" */
        "calll Com_Printf\n"
        "jmp .Lf17e2ae_0017e377\n"
        ".Lf17e2ae_0017e527:\n"
        "cmpl $3, (%edi)\n" /* line 1866 */
        "jle .Lf17e2ae_0017e3f2\n"
        "movl imp_sv_floodProtect, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17e2ae_0017e3f2\n"
        "movl imp_svs, %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl 0x20d0c(%edi), %eax\n"
        "jge .Lf17e2ae_0017e3f2\n"
        "testl %edx, %edx\n"
        "je .Lf17e2ae_0017e3fa\n"
        "movl $0, (%esp)\n" /* line 1870 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x20c48(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae824, (%esp)\n" /* "client text ignored for %s: %s
" */
        "calll Com_DPrintf\n"
        "xorl %edx, %edx\n"
        "jmp .Lf17e2ae_0017e58c\n"
        ".Lf17e2ae_0017e587:\n"
        "movl $1, %edx\n" /* line 1875 */
        ".Lf17e2ae_0017e58c:\n"
        "movl imp_svs, %eax\n" /* line 1876 */
        "movl 4(%eax), %eax\n"
        "addl $0x320, %eax\n"
        "movl %eax, 0x20d0c(%edi)\n"
        "jmp .Lf17e2ae_0017e3ff\n"
        ".Lf17e2ae_0017e5a4:\n"
        "movl $6, 8(%esp)\n" /* line 1853 */
        "movl %esi, 4(%esp)\n" /* s */
        "movl $str_002ae818, (%esp)\n" /* "score " */
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "je .Lf17e2ae_0017e3de\n"
        "movl $3, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* s */
        "movl $str_002ae820, (%esp)\n" /* "mr " */
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "je .Lf17e2ae_0017e3de\n"
        "movl $1, %edx\n"
        "jmp .Lf17e2ae_0017e3e0\n"
        /* } scope */
        ".Lf17e2ae_0017e5ee:\n"
        "cmpl $3, (%edi)\n" /* line 2189 | cl */
        "jne .Lf17e2ae_0017e3b3\n"
        /* { scope 2 */
        "leal 0x20c48(%edi), %eax\n" /* line 1023 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae204, (%esp)\n" /* "Going from CS_PRIMED to CS_ACTIVE for %s
" */
        "calll Com_DPrintf\n"
        "movl $4, (%edi)\n" /* line 1024 */
        "movl imp_svs, %esi\n" /* line 1027 */
        "movl %edi, %ebx\n"
        "subl 0xc(%esi), %ebx\n"
        "sarl $2, %ebx\n"
        "imull $0x3789a4eb, %ebx, %ebx\n"
        "movl %ebx, (%esp)\n" /* line 1028 */
        "calll SV_GentityNum\n"
        "movl %ebx, (%eax)\n" /* line 1029 */
        "movl %eax, 0x20c44(%edi)\n" /* line 1030 */
        "movl $0xffffffff, 0x20d08(%edi)\n" /* line 1032 */
        "movl 4(%esi), %eax\n" /* line 1033 */
        "movl %eax, 0x20d18(%edi)\n"
        "subl 0xc(%esi), %edi\n" /* line 1037 */
        "sarl $2, %edi\n"
        "imull $0x3789a4eb, %edi, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ClientBegin\n"
        "jmp .Lf17e2ae_0017e3b3\n"
        /* } scope */
        ".Lf17e2ae_0017e663:\n"
        "movl imp_sv_pure, %eax\n" /* line 2224 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf17e2ae_0017e6b0\n"
        ".Lf17e2ae_0017e670:\n"
        "testl %esi, %esi\n" /* line 2235 | c */
        "je .Lf17e2ae_0017e705\n"
        "cmpl $1, %esi\n" /* line 2237 | c */
        "je .Lf17e2ae_0017e6e9\n"
        "cmpl $3, %esi\n" /* line 2239 | c */
        "je .Lf17e2ae_0017e3b3\n"
        "movl imp_svs, %eax\n" /* line 2240 */
        "subl 0xc(%eax), %edi\n" /* cl */
        "sarl $2, %edi\n" /* cl */
        "imull $0x3789a4eb, %edi, %eax\n" /* cl */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* c */
        "movl $str_002ae860, (%esp)\n" /* "WARNING: bad command byte %i for client %i
" */
        "calll Com_Printf\n"
        "jmp .Lf17e2ae_0017e3b3\n"
        ".Lf17e2ae_0017e6b0:\n"
        "cmpl $2, 0x6e5b0(%edi)\n" /* line 2224 | cl */
        "jne .Lf17e2ae_0017e670\n"
        "movl $0xffffffff, 0x20d18(%edi)\n" /* line 2226 | cl */
        "movl $str_002ae844, 4(%esp)\n" /* line 2227 */
        "movl %edi, (%esp)\n" /* cl */
        "calll SV_DropClient\n"
        "movl $4, (%edi)\n" /* line 2228 | cl */
        "movl %edi, (%esp)\n" /* line 2229 | cl */
        "calll SV_SendClientSnapshot\n"
        "movl $1, (%edi)\n" /* line 2230 | cl */
        "jmp .Lf17e2ae_0017e670\n"
        ".Lf17e2ae_0017e6e9:\n"
        "movl $0, 8(%esp)\n" /* line 2238 */
        "leal -0x48(%ebp), %eax\n" /* msgCompressed */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cl */
        "calll SV_UserMove\n"
        "jmp .Lf17e2ae_0017e3b3\n"
        ".Lf17e2ae_0017e705:\n"
        "movl $1, 8(%esp)\n" /* line 2236 */
        "leal -0x48(%ebp), %eax\n" /* msgCompressed */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cl */
        "calll SV_UserMove\n"
        "jmp .Lf17e2ae_0017e3b3\n"
    );
}

/* line 2249 */
__attribute__((naked))
gentity_t * SV_AddTestClient(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x48c, %esp\n"
        /* { scope 1 */
        "movl imp_svs, %eax\n" /* line 2260 */
        "movl 0xc(%eax), %edx\n"
        "movl imp_sv_maxclients, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf17e722_0017e927\n"
        "movl (%edx), %eax\n" /* line 2262 */
        "testl %eax, %eax\n"
        "je .Lf17e722_0017e76d\n"
        "leal 0x78f0c(%edx), %ecx\n" /* line 2264 */
        "xorl %edx, %edx\n"
        ".Lf17e722_0017e756:\n"
        "addl $1, %edx\n" /* line 2260 */
        "cmpl %ebx, %edx\n"
        "je .Lf17e722_0017e92f\n"
        "movl (%ecx), %eax\n" /* line 2262 */
        "addl $0x78f0c, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf17e722_0017e756\n"
        ".Lf17e722_0017e76d:\n"
        "movl $0x73, 0xc(%esp)\n" /* line 2271 */
        "movl botport, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002ae88c, 4(%esp)\n" /* "connect "\cg_predictItems\1\cl_anonymous\0\color\4\head\defa" */
        "leal -0x464(%ebp), %ebx\n" /* file */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "movl %ebx, (%esp)\n" /* line 2273 */
        "calll SV_Cmd_TokenizeString\n"
        "movl $0, -0x44(%ebp)\n" /* line 2275 */
        "movl $0, -0x40(%ebp)\n"
        "movl $0, -0x48(%ebp)\n" /* line 2276 | a */
        "movl botport, %eax\n" /* line 2277 */
        "movw %ax, -0x40(%ebp)\n"
        "addl $1, %eax\n" /* line 2278 */
        "movl %eax, botport\n"
        "movl $0, -0x3c(%ebp)\n" /* line 2279 */
        "movl $0, -0x38(%ebp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl $0, (%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll SV_DirectConnect\n"
        "movl imp_svs, %eax\n" /* line 2281 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x470(%ebp)\n"
        "movl imp_sv_maxclients, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jg .Lf17e722_0017e93c\n"
        "movl $0, -0x46c(%ebp)\n"
        "movl (%edx), %eax\n"
        "movl -0x46c(%ebp), %edx\n"
        ".Lf17e722_0017e821:\n"
        "cmpl %edx, 8(%eax)\n" /* line 2293 */
        "je .Lf17e722_0017e92f\n"
        "movl -0x470(%ebp), %ecx\n" /* line 2296 */
        "movl $1, 0x765f4(%ecx)\n"
        "movl %ecx, (%esp)\n" /* line 2298 */
        "calll SV_SendClientGameState\n"
        "leal -0x64(%ebp), %edi\n" /* line 2300 | nullcmd */
        "cld\n"
        "movl $7, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        /* { scope 2 */
        "movl -0x470(%ebp), %eax\n" /* line 1023 */
        "addl $0x20c48, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ae204, (%esp)\n" /* "Going from CS_PRIMED to CS_ACTIVE for %s
" */
        "calll Com_DPrintf\n"
        "movl -0x470(%ebp), %eax\n" /* line 1024 */
        "movl $4, (%eax)\n"
        "movl imp_svs, %esi\n" /* line 1027 */
        "movl %eax, %ebx\n"
        "subl 0xc(%esi), %ebx\n"
        "sarl $2, %ebx\n"
        "imull $0x3789a4eb, %ebx, %ebx\n"
        "movl %ebx, (%esp)\n" /* line 1028 */
        "calll SV_GentityNum\n"
        "movl %ebx, (%eax)\n" /* line 1029 */
        "movl -0x470(%ebp), %edx\n" /* line 1030 */
        "movl %eax, 0x20c44(%edx)\n"
        "movl $0xffffffff, 0x20d08(%edx)\n" /* line 1032 */
        "movl 4(%esi), %eax\n" /* line 1033 */
        "movl %eax, 0x20d18(%edx)\n"
        "movl -0x64(%ebp), %eax\n" /* line 1034 | nullcmd */
        "movl %eax, 0x20824(%edx)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x20828(%edx)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x2082c(%edx)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x20830(%edx)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x20834(%edx)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x20838(%edx)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x2083c(%edx)\n"
        "movl 0xc(%esi), %ecx\n" /* line 1037 */
        "subl %ecx, %edx\n"
        "movl %edx, -0x470(%ebp)\n"
        "sarl $2, %edx\n"
        "imull $0x3789a4eb, %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ClientBegin\n"
        /* } scope */
        "movl -0x46c(%ebp), %eax\n" /* line 2302 */
        "movl %eax, (%esp)\n"
        "calll SV_GentityNum\n"
        /* } scope */
        "addl $0x48c, %esp\n" /* line 2303 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17e722_0017e927:\n"
        "testl %ebx, %ebx\n" /* line 2268 */
        "jne .Lf17e722_0017e76d\n"
        ".Lf17e722_0017e92f:\n"
        "xorl %eax, %eax\n" /* line 2302 */
        /* } scope */
        "addl $0x48c, %esp\n" /* line 2303 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17e722_0017e93c:\n"
        "movl $0, -0x46c(%ebp)\n" /* line 2281 */
        "movl %edx, -0x474(%ebp)\n"
        "jmp .Lf17e722_0017e96c\n"
        ".Lf17e722_0017e94e:\n"
        "addl $1, -0x46c(%ebp)\n"
        "addl $0x78f0c, -0x470(%ebp)\n"
        "movl (%edx), %eax\n"
        "movl -0x46c(%ebp), %ecx\n"
        "cmpl 8(%eax), %ecx\n"
        "jge .Lf17e722_0017e9e9\n"
        ".Lf17e722_0017e96c:\n"
        "movl -0x470(%ebp), %eax\n" /* line 2283 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf17e722_0017e94e\n"
        "movl 0x6e5c4(%eax), %edi\n" /* line 2287 */
        "movl %edi, -0x30(%ebp)\n"
        "movl 0x6e5c8(%eax), %esi\n"
        "movl %esi, -0x2c(%ebp)\n"
        "movl 0x6e5cc(%eax), %ebx\n"
        "movl %ebx, -0x28(%ebp)\n"
        "movl -0x48(%ebp), %ecx\n" /* a */
        "movl %ecx, -0x24(%ebp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareBaseAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf17e722_0017e9f0\n"
        "movl -0x474(%ebp), %edx\n"
        "addl $1, -0x46c(%ebp)\n" /* line 2281 */
        "addl $0x78f0c, -0x470(%ebp)\n"
        "movl (%edx), %eax\n"
        "movl -0x46c(%ebp), %ecx\n"
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf17e722_0017e96c\n"
        ".Lf17e722_0017e9e9:\n"
        "movl %ecx, %edx\n"
        "jmp .Lf17e722_0017e821\n"
        ".Lf17e722_0017e9f0:\n"
        "movl imp_sv_maxclients, %edx\n"
        "movl (%edx), %eax\n"
        "movl -0x46c(%ebp), %edx\n"
        "jmp .Lf17e722_0017e821\n"
    );
}

#else
extern const dvar_t * Dvar_RegisterString(const char *dvarName, const char *value, int flags);
extern const char *NET_AdrToString(netadr_t adr);
extern char *va(const char *fmt, ...);
extern Bool Dvar_GetBool(const char *dvarName);
extern void NET_OutOfBandPrint(int sock, netadr_t adr, const char *data);

static const dvar_t * Dvar_RegisterString_mac_sv(const char *name, const char *value, int flags) {
    return Dvar_RegisterString(name, value ? value : "", flags);
}

/* line 138 */
void SV_AuthorizeRequest(struct netadr_t from, int challenge)
{
    char game[0x400];
    extern void *imp_svs;
    serverStatic_t *svsPtr = (serverStatic_t *)imp_svs;

    /* line 146 */
    if (svsPtr->authorizeAddress.type == 1) {
        return;
    }

    /* line 149 */
    game[0] = '\0';

    /* line 150 */
    const dvar_t *fs_game = Dvar_RegisterString_mac_sv((const char *)str_00216d64, (const char *)str_002157b8, 0x101c);

    /* line 151 */
    if (fs_game) {
        const char *val = *(const char **)((char *)fs_game + 8);
        if (val[0] != '\0') {
            /* line 152 */
            strcpy(game, val);
        }
    }

    /* line 154 */
    Com_DPrintf((const char *)str_002adef4, NET_AdrToString(from));

    /* line 155 */
    Bool allowAnon = Dvar_GetBool((const char *)str_002a718c);

    /* line 158 */
    const char *s = va((const char *)str_002adf14, challenge,
        (unsigned int)from.ip[0], (unsigned int)from.ip[1],
        (unsigned int)from.ip[2], (unsigned int)from.ip[3],
        game, (int)(unsigned char)allowAnon);

    /* line 159 */
    NET_OutOfBandPrint(1, svsPtr->authorizeAddress, s);
}
#endif
