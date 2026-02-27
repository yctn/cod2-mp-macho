/* ASM dump from: cl_ui_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_ui_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern qboolean CL_UpdateDirtyPings_f(int source);
extern int CL_ServerStatus(char *serverAddress, char *serverStatus, int maxLen);
extern int SND_PlayLocalSoundAlias(snd_alias_list_t *aliasList, int channel);
extern int SND_PlayLocalSoundAliasByName(const char *aliasname, int channel);
extern void Com_LoadSoundAliases(const char *zone, const char *spec, int flags);

void GetClientState(uiClientState_t *state);
void LAN_ResetPings(int source);
int LAN_GetServerCount(int source);
qboolean LAN_WaitServerResponse(int source);
void LAN_GetServerInfo(int source, int n, char *buf, int buflen);
int LAN_GetServerPing(int source, int n);
void LAN_MarkServerDirty(int source, int n, qboolean dirty);
int LAN_ServerIsDirty(int source, int n);
qboolean LAN_UpdateDirtyPings(int source);
int LAN_GetServerStatus(char *serverAddress, char *serverStatus, int maxLen);
void Key_KeynumToStringBuf(int keynum, char *buf, int buflen);
void Key_GetBindingBuf(int keynum, char *buf, int buflen);
int Key_GetCatcher(void);
void Key_SetCatcher(int catcher);
void CLUI_GetCDKey(char *buf, int buflen, char *buf2, int buf2len);
void CLUI_SetCDKey(char *buf, char *buf2);
qboolean GetClientname(int index, char *buf, int size);
int UI_PlayLocalSoundAlias(snd_alias_list_t *aliasList);
int UI_PlayLocalSoundAliasByName(const char *aliasname);
qboolean UI_ClientIsInGame(void);
qboolean CL_ShutdownUI(void);
void CL_InitUI(void);
qboolean UI_checkKeyExec(int key);
void UI_LoadSoundAliases(void);
int LAN_CompareHostname(const char *hostName1, const char *hostName2);
int LAN_CompareServers(int source, int sortKey, int sortDir, int s1, int s2);

/* line 23 */
__attribute__((naked))
void GetClientState(uiClientState_t *state)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 23 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* state */
        "movl 0x195ee8c, %eax\n" /* line 25 */
        "movl (%eax), %ebx\n"
        "movl 0x24(%ebx), %eax\n"
        "movl %eax, 4(%esi)\n" /* state */
        "movl (%ebx), %eax\n" /* line 26 */
        "movl %eax, (%esi)\n" /* state */
        "movl $0x400, 8(%esp)\n" /* line 27 */
        "movl 0x195ecac, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x400, 8(%esp)\n" /* line 31 */
        "addl $0x28, %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x40c(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl 0x195ee78, %eax\n" /* line 32 */
        "movl (%eax), %eax\n"
        "movl 0x100(%eax), %eax\n"
        "movl %eax, 8(%esi)\n" /* state */
        "addl $0x10, %esp\n" /* line 33 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 41 */
__attribute__((naked))
void LAN_ResetPings(int source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 41 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* source */
        /* { scope 1 */
        "cmpl $1, %eax\n" /* line 48 */
        "je .Lf17f084_0017f0bf\n"
        "cmpl $2, %eax\n"
        "je .Lf17f084_0017f0d5\n"
        "testl %eax, %eax\n"
        "je .Lf17f084_0017f09a\n"
        /* } scope */
        "popl %ebp\n" /* line 74 */
        "retl\n"
        /* { scope 1 */
        ".Lf17f084_0017f09a:\n"
        "movl $0x80, %ecx\n" /* line 48 */
        "movl 0x195ecac, %eax\n"
        "addl $0x13c, %eax\n"
        ".Lf17f084_0017f0a9:\n"
        "xorl %edx, %edx\n" /* line 69 */
        ".Lf17f084_0017f0ab:\n"
        "movw $0xffff, 0x1e(%eax)\n" /* line 71 */
        "addl $1, %edx\n" /* line 69 */
        "addl $0x88, %eax\n"
        "cmpl %ecx, %edx\n"
        "jne .Lf17f084_0017f0ab\n"
        /* } scope */
        "popl %ebp\n" /* line 74 */
        "retl\n"
        /* { scope 1 */
        ".Lf17f084_0017f0bf:\n"
        "movl 0x195ecac, %eax\n" /* line 57 */
        "movl 0x4540(%eax), %ecx\n"
        "addl $0x4544, %eax\n"
        "testl %ecx, %ecx\n" /* line 69 */
        "jg .Lf17f084_0017f0a9\n"
        /* } scope */
        "popl %ebp\n" /* line 74 */
        "retl\n"
        /* { scope 1 */
        ".Lf17f084_0017f0d5:\n"
        "movl 0x195ecac, %eax\n"
        "addl $0x29c648, %eax\n" /* "1.xyz, r0, c0.x;
MUL    r0, r1, v0;
MAD r1.xyz, v0, -r1, c23" */
        "movl $0x80, %ecx\n"
        "jmp .Lf17f084_0017f0a9\n"
    );
}

/* line 82 */
__attribute__((naked))
int LAN_GetServerCount(int source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 82 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* source */
        "cmpl $1, %eax\n" /* line 84 */
        "je .Lf17f0e6_0017f10b\n"
        "cmpl $2, %eax\n"
        "je .Lf17f0e6_0017f118\n"
        "testl %eax, %eax\n"
        "jne .Lf17f0e6_0017f107\n"
        "movl 0x195ecac, %eax\n" /* line 87 */
        "movl 0x138(%eax), %eax\n"
        "popl %ebp\n" /* line 98 */
        "retl\n"
        ".Lf17f0e6_0017f107:\n"
        "xorl %eax, %eax\n" /* line 84 */
        "popl %ebp\n" /* line 98 */
        "retl\n"
        ".Lf17f0e6_0017f10b:\n"
        "movl 0x195ecac, %eax\n" /* line 90 */
        "movl 0x4540(%eax), %eax\n"
        "popl %ebp\n" /* line 98 */
        "retl\n"
        ".Lf17f0e6_0017f118:\n"
        "movl 0x195ecac, %eax\n" /* line 94 */
        "movl 0x29c644(%eax), %eax\n"
        "popl %ebp\n" /* line 98 */
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
qboolean LAN_WaitServerResponse(int source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "cmpl $1, 8(%ebp)\n" /* line 109 | source */
        "je .Lf17f126_0017f133\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 116 */
        "retl\n"
        ".Lf17f126_0017f133:\n"
        "movl 0x195ecac, %eax\n" /* line 112 */
        "movl 0x453c(%eax), %eax\n"
        "popl %ebp\n" /* line 116 */
        "retl\n"
    );
}

/* line 124 */
__attribute__((naked))
void LAN_GetServerInfo(int source, int n, char *buf, int buflen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 124 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl 0xc(%ebp), %edx\n" /* n */
        "movl 0x10(%ebp), %edi\n" /* buf */
        /* { scope 1 */
        "movb $0, -0x424(%ebp)\n" /* line 129 | info */
        "cmpl $1, %eax\n" /* line 131 */
        "je .Lf17f140_0017f4b6\n"
        "cmpl $2, %eax\n"
        "je .Lf17f140_0017f4e5\n"
        "testl %eax, %eax\n"
        "je .Lf17f140_0017f184\n"
        ".Lf17f140_0017f172:\n"
        "testl %edi, %edi\n" /* line 187 | buf */
        "je .Lf17f140_0017f179\n"
        "movb $0, (%edi)\n" /* line 189 | buf */
        /* } scope */
        ".Lf17f140_0017f179:\n"
        "addl $0x42c, %esp\n" /* line 192 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17f140_0017f184:\n"
        "cmpl $0x7f, %edx\n" /* line 134 */
        "ja .Lf17f140_0017f172\n"
        "movl %edx, %eax\n" /* line 136 */
        "shll $7, %eax\n"
        "leal 0x130(%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "leal 0xc(%eax), %esi\n" /* server */
        ".Lf17f140_0017f19e:\n"
        "testl %esi, %esi\n" /* line 156 | server */
        "je .Lf17f140_0017f172\n"
        "testl %edi, %edi\n" /* buf */
        "je .Lf17f140_0017f179\n"
        "movb $0, (%edi)\n" /* line 158 | buf */
        "leal 0x20(%esi), %eax\n" /* line 159 | server */
        "movl %eax, 8(%esp)\n"
        "movl $0x2aa89c, 4(%esp)\n" /* "hostname" */
        "leal -0x424(%ebp), %ebx\n" /* info */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "leal 0x40(%esi), %eax\n" /* line 160 | server */
        "movl %eax, 8(%esp)\n"
        "movl $0x2a7124, 4(%esp)\n" /* "mapname" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0xd(%esi), %eax\n" /* line 161 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a8a54, 4(%esp)\n" /* "clients" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0xe(%esi), %eax\n" /* line 162 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a70dc, 4(%esp)\n" /* "sv_maxclients" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movswl 0x1e(%esi), %eax\n" /* line 163 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a90f4, 4(%esp)\n" /* "ping" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movswl 0x1a(%esi), %eax\n" /* line 164 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2ab8c8, 4(%esp)\n" /* "minping" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movswl 0x1c(%esi), %eax\n" /* line 165 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2ab8d0, 4(%esp)\n" /* "maxping" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "leal 0x60(%esi), %eax\n" /* line 166 | server */
        "movl %eax, 8(%esp)\n"
        "movl $0x2aa890, 4(%esp)\n" /* "game" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "leal 0x78(%esi), %eax\n" /* line 167 | server */
        "movl %eax, 8(%esp)\n"
        "movl $0x2aa884, 4(%esp)\n" /* "gametype" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0xc(%esi), %eax\n" /* line 168 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2ab8c0, 4(%esp)\n" /* "nettype" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl (%esi), %ecx\n" /* line 170 | server */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 4(%esi), %edx\n" /* server */
        "movl %edx, -0x20(%ebp)\n"
        "movl 8(%esi), %eax\n" /* server */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2aa858, 4(%esp)\n" /* "addr" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0x10(%esi), %eax\n" /* line 172 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a718c, 4(%esp)\n" /* "sv_allowAnonymous" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movsbl 0x15(%esi), %eax\n" /* line 173 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2ab4e0, 4(%esp)\n" /* "con_disabled" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0x11(%esi), %eax\n" /* line 174 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a9af0, 4(%esp)\n" /* "pswrd" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0x12(%esi), %eax\n" /* line 175 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2aa870, 4(%esp)\n" /* "pure" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movsbl 0x13(%esi), %eax\n" /* line 176 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2aa87c, 4(%esp)\n" /* "ff" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movsbl 0x14(%esi), %eax\n" /* line 177 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2aa880, 4(%esp)\n" /* "kc" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0x16(%esi), %eax\n" /* line 178 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2aa878, 4(%esp)\n" /* "hw" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0x17(%esi), %eax\n" /* line 179 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2a9cf4, 4(%esp)\n" /* "mod" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movzbl 0x18(%esi), %eax\n" /* line 181 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21ec00, 4(%esp)\n" /* "voice" */
        "movl %ebx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl 0x14(%ebp), %eax\n" /* line 183 | buflen */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* buf */
        "calll I_strncpyz\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 192 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17f140_0017f4b6:\n"
        "testl %edx, %edx\n" /* line 141 */
        "js .Lf17f140_0017f172\n"
        "movl 0x195ecac, %ecx\n"
        "cmpl 0x4540(%ecx), %edx\n"
        "jge .Lf17f140_0017f172\n"
        "movl %edx, %eax\n" /* line 143 */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %edx, 8), %eax\n"
        "leal 4(%eax, %ecx), %esi\n" /* server */
        "jmp .Lf17f140_0017f19e\n"
        ".Lf17f140_0017f4e5:\n"
        "cmpl $0x7f, %edx\n" /* line 149 */
        "ja .Lf17f140_0017f172\n"
        "movl %edx, %eax\n" /* line 151 */
        "shll $7, %eax\n"
        "leal 0x29c640(%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "leal 8(%eax), %esi\n" /* server */
        "jmp .Lf17f140_0017f19e\n"
    );
}

/* line 200 */
__attribute__((naked))
int LAN_GetServerPing(int source, int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 200 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl 0xc(%ebp), %edx\n" /* n */
        /* { scope 1 */
        "cmpl $1, %eax\n" /* line 204 */
        "je .Lf17f508_0017f543\n"
        "cmpl $2, %eax\n"
        "je .Lf17f508_0017f54e\n"
        "testl %eax, %eax\n"
        "jne .Lf17f508_0017f547\n"
        "cmpl $0x7f, %edx\n" /* line 207 */
        "ja .Lf17f508_0017f547\n"
        "movl %edx, %eax\n" /* line 209 */
        "shll $7, %eax\n"
        "leal 0x130(%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "addl $0xc, %eax\n"
        ".Lf17f508_0017f539:\n"
        "testl %eax, %eax\n" /* line 229 */
        "je .Lf17f508_0017f547\n"
        "movswl 0x1e(%eax), %eax\n" /* line 231 */
        /* } scope */
        "popl %ebp\n" /* line 234 */
        "retl\n"
        /* { scope 1 */
        ".Lf17f508_0017f543:\n"
        "testl %edx, %edx\n" /* line 214 */
        "jns .Lf17f508_0017f56a\n"
        ".Lf17f508_0017f547:\n"
        "movl $0xffffffff, %eax\n" /* line 231 */
        /* } scope */
        "popl %ebp\n" /* line 234 */
        "retl\n"
        /* { scope 1 */
        ".Lf17f508_0017f54e:\n"
        "cmpl $0x7f, %edx\n" /* line 222 */
        "ja .Lf17f508_0017f547\n"
        "movl %edx, %eax\n" /* line 224 */
        "shll $7, %eax\n"
        "leal 0x29c640(%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "addl $8, %eax\n"
        "jmp .Lf17f508_0017f539\n"
        ".Lf17f508_0017f56a:\n"
        "movl 0x195ecac, %ecx\n" /* line 214 */
        "cmpl 0x4540(%ecx), %edx\n"
        "jge .Lf17f508_0017f547\n"
        "movl %edx, %eax\n" /* line 216 */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %edx, 8), %eax\n"
        "leal 4(%eax, %ecx), %eax\n"
        "jmp .Lf17f508_0017f539\n"
    );
}

/* line 419 */
__attribute__((naked))
void LAN_MarkServerDirty(int source, int n, qboolean dirty)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 419 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* source */
        "movl 0xc(%ebp), %esi\n" /* n */
        "calll Com_PumpMessageLoop\n" /* line 421 */
        "cmpl $-1, %esi\n" /* line 423 | n */
        "je .Lf17f58a_0017f5d2\n"
        "cmpl $1, %ebx\n" /* line 456 | count */
        "je .Lf17f58a_0017f609\n"
        "cmpl $2, %ebx\n" /* count */
        "je .Lf17f58a_0017f632\n"
        "testl %ebx, %ebx\n" /* count */
        "jne .Lf17f58a_0017f5ce\n"
        "cmpl $0x7f, %esi\n" /* line 459 | n */
        "ja .Lf17f58a_0017f5ce\n"
        "movl %esi, %eax\n" /* line 461 | n */
        "shll $7, %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "movzbl 0x10(%ebp), %edx\n" /* dirty */
        "movb %dl, 0x14b(%eax)\n"
        ".Lf17f58a_0017f5ce:\n"
        "popl %ebx\n" /* line 482 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17f58a_0017f5d2:\n"
        "cmpl $1, %ebx\n" /* line 428 | count */
        "je .Lf17f58a_0017f664\n"
        "cmpl $2, %ebx\n" /* count */
        "je .Lf17f58a_0017f653\n"
        "testl %ebx, %ebx\n" /* count */
        "jne .Lf17f58a_0017f5ce\n"
        "movl 0x195ecac, %eax\n"
        "addl $0x13c, %eax\n"
        "movb $0x80, %bl\n" /* count */
        ".Lf17f58a_0017f5f0:\n"
        "movzbl 0x10(%ebp), %ecx\n" /* line 447 | dirty */
        "xorl %edx, %edx\n"
        ".Lf17f58a_0017f5f6:\n"
        "movb %cl, 0xf(%eax)\n" /* line 449 */
        "addl $1, %edx\n" /* line 447 */
        "addl $0x88, %eax\n"
        "cmpl %ebx, %edx\n" /* count */
        "jne .Lf17f58a_0017f5f6\n"
        /* } scope */
        "popl %ebx\n" /* line 482 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17f58a_0017f609:\n"
        "testl %esi, %esi\n" /* line 466 | n */
        "js .Lf17f58a_0017f5ce\n"
        "movl 0x195ecac, %edx\n"
        "cmpl 0x4540(%edx), %esi\n" /* n */
        "jge .Lf17f58a_0017f5ce\n"
        "movl %esi, %eax\n" /* line 468 | n */
        "shll $7, %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "movzbl 0x10(%ebp), %ecx\n" /* dirty */
        "movb %cl, 0x4553(%eax, %edx)\n"
        "popl %ebx\n" /* line 482 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17f58a_0017f632:\n"
        "cmpl $0x7f, %esi\n" /* line 474 | n */
        "ja .Lf17f58a_0017f5ce\n"
        "movl %esi, %eax\n" /* line 476 | n */
        "shll $7, %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "movzbl 0x10(%ebp), %edx\n" /* dirty */
        "movb %dl, 0x29c657(%eax)\n"
        "popl %ebx\n" /* line 482 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17f58a_0017f653:\n"
        "movl $0x80, %ebx\n" /* count */
        "movl 0x195ecac, %eax\n"
        "addl $0x29c648, %eax\n" /* "1.xyz, r0, c0.x;
MUL    r0, r1, v0;
MAD r1.xyz, v0, -r1, c23" */
        "jmp .Lf17f58a_0017f5f0\n"
        /* { scope 1 */
        ".Lf17f58a_0017f664:\n"
        "movl 0x195ecac, %eax\n" /* line 436 */
        "movl 0x4540(%eax), %ebx\n" /* count */
        "addl $0x4544, %eax\n"
        "testl %ebx, %ebx\n" /* line 447 | count */
        "jg .Lf17f58a_0017f5f0\n"
        /* } scope */
        "popl %ebx\n" /* line 482 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 490 */
__attribute__((naked))
int LAN_ServerIsDirty(int source, int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 490 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl 0xc(%ebp), %edx\n" /* n */
        "cmpl $1, %eax\n" /* line 492 */
        "je .Lf17f680_0017f6b7\n"
        "cmpl $2, %eax\n"
        "je .Lf17f680_0017f6db\n"
        "testl %eax, %eax\n"
        "je .Lf17f680_0017f69b\n"
        ".Lf17f680_0017f697:\n"
        "xorl %eax, %eax\n" /* line 512 */
        "popl %ebp\n" /* line 518 */
        "retl\n"
        ".Lf17f680_0017f69b:\n"
        "cmpl $0x7f, %edx\n" /* line 495 */
        "ja .Lf17f680_0017f697\n"
        "movl %edx, %eax\n" /* line 497 */
        "shll $7, %eax\n"
        "leal (%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "movzbl 0x14b(%eax), %eax\n"
        "popl %ebp\n" /* line 518 */
        "retl\n"
        ".Lf17f680_0017f6b7:\n"
        "testl %edx, %edx\n" /* line 502 */
        "js .Lf17f680_0017f697\n"
        "movl 0x195ecac, %ecx\n"
        "cmpl 0x4540(%ecx), %edx\n"
        "jge .Lf17f680_0017f697\n"
        "movl %edx, %eax\n" /* line 504 */
        "shll $7, %eax\n"
        "leal (%eax, %edx, 8), %eax\n"
        "movzbl 0x4553(%eax, %ecx), %eax\n"
        "popl %ebp\n" /* line 518 */
        "retl\n"
        ".Lf17f680_0017f6db:\n"
        "cmpl $0x7f, %edx\n" /* line 510 */
        "ja .Lf17f680_0017f697\n"
        "movl %edx, %eax\n" /* line 512 */
        "shll $7, %eax\n"
        "leal (%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "movzbl 0x29c657(%eax), %eax\n"
        "popl %ebp\n" /* line 518 */
        "retl\n"
    );
}

/* line 526 */
qboolean LAN_UpdateDirtyPings(int source)
{
    return CL_UpdateDirtyPings_f(source);
}

/* line 538 */
int LAN_GetServerStatus(char *serverAddress, char *serverStatus, int maxLen)
{
    return CL_ServerStatus(serverAddress, serverStatus, maxLen);
}

/* line 550 */
__attribute__((naked))
void Key_KeynumToStringBuf(int keynum, char *buf, int buflen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 550 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* buf */
        "movl 0x10(%ebp), %ebx\n" /* buflen */
        "movl $1, 4(%esp)\n" /* line 552 */
        "movl 8(%ebp), %eax\n" /* keynum */
        "movl %eax, (%esp)\n"
        "calll Key_KeynumToString\n"
        "movl %ebx, 0x10(%ebp)\n" /* buflen */
        "movl %eax, 0xc(%ebp)\n" /* buf */
        "movl %esi, 8(%ebp)\n" /* buf, keynum */
        "addl $0x10, %esp\n" /* line 553 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp I_strncpyz\n" /* line 552 */
    );
}

/* line 561 */
__attribute__((naked))
void Key_GetBindingBuf(int keynum, char *buf, int buflen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 561 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* buf */
        "movl 0x10(%ebp), %ebx\n" /* buflen */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 565 | keynum */
        "movl %eax, (%esp)\n"
        "calll Key_GetBinding\n"
        "testl %eax, %eax\n" /* line 566 */
        "je .Lf17f742_0017f773\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 568 | buflen */
        "movl %eax, 0xc(%ebp)\n" /* buf */
        "movl %esi, 8(%ebp)\n" /* buf, keynum */
        /* } scope */
        "addl $0x10, %esp\n" /* line 574 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp I_strncpyz\n" /* line 568 */
        ".Lf17f742_0017f773:\n"
        "movb $0, (%esi)\n" /* line 572 | buf */
        /* } scope */
        "addl $0x10, %esp\n" /* line 574 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 582 */
int Key_GetCatcher(void)
{
    return *(int *)(*(int *)(*(int *)0x195ee78) + 4);
}

/* line 593 */
__attribute__((naked))
void Key_SetCatcher(int catcher)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 593 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* catcher */
        "movl 0x195ee78, %ecx\n" /* line 596 */
        "movl (%ecx), %eax\n"
        "testb $1, 4(%eax)\n"
        "je .Lf17f78e_0017f7b6\n"
        "orl $1, %edx\n" /* line 597 */
        "movl %edx, 4(%eax)\n"
        ".Lf17f78e_0017f7a8:\n"
        "movl (%ecx), %eax\n" /* line 601 */
        "testb $8, 4(%eax)\n"
        "jne .Lf17f78e_0017f7b4\n"
        "movb $0, 8(%eax)\n" /* line 602 */
        ".Lf17f78e_0017f7b4:\n"
        "popl %ebp\n" /* line 603 */
        "retl\n"
        ".Lf17f78e_0017f7b6:\n"
        "movl %edx, 4(%eax)\n" /* line 599 */
        "jmp .Lf17f78e_0017f7a8\n"
    );
}

/* line 611 */
__attribute__((naked))
void CLUI_GetCDKey(char *buf, int buflen, char *buf2, int buf2len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 611 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* buf */
        "movl 0x10(%ebp), %esi\n" /* buf2 */
        "movl $0x101c, 8(%esp)\n" /* line 616 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x216d64, (%esp)\n" /* "fs_game" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f4e4, %edx\n" /* line 618 */
        "movl (%edx), %eax\n"
        "movl %eax, (%ebx)\n" /* buf */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ebx)\n" /* buf */
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ebx)\n" /* buf */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* buf */
        "movb $0, 0x10(%ebx)\n" /* line 619 | buf */
        "movl 0x195f314, %eax\n" /* line 621 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esi)\n" /* buf2 */
        "movb $0, 4(%esi)\n" /* line 622 | buf2 */
        "addl $0x10, %esp\n" /* line 623 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 631 */
__attribute__((naked))
void CLUI_SetCDKey(char *buf, char *buf2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 631 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* buf */
        "movl 0x195f4e4, %edx\n" /* line 633 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movb $0, 0x10(%edx)\n" /* line 634 */
        "movl 0x195f314, %edx\n" /* line 635 */
        "movl 0xc(%ebp), %eax\n" /* buf2 */
        "movl (%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $0, 4(%edx)\n" /* line 636 */
        "popl %ebp\n" /* line 639 */
        "jmp Com_WriteCDKey\n" /* line 638 */
    );
}

/* line 647 */
__attribute__((naked))
qboolean GetClientname(int index, char *buf, int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 647 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 652 | buf */
        "movb $0, (%eax)\n"
        "movl 0x195ee78, %eax\n" /* line 654 */
        "movl (%eax), %ebx\n"
        "movl 0x18(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf17f858_0017f8f1\n"
        "movl 0x26e0(%ebx), %esi\n" /* line 657 */
        "testl %esi, %esi\n"
        "jle .Lf17f858_0017f8f1\n"
        "movl 0x26e8(%ebx), %edi\n" /* line 659 */
        "movl %edi, %edx\n"
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ebx, %eax, 4), %eax\n"
        "movl 8(%ebp), %edx\n" /* line 661 | index */
        "cmpl (%eax), %edx\n"
        "je .Lf17f858_0017f8cb\n"
        "xorl %ecx, %ecx\n" /* line 664 */
        ".Lf17f858_0017f8a5:\n"
        "addl $1, %ecx\n" /* line 657 */
        "cmpl %esi, %ecx\n"
        "je .Lf17f858_0017f8f1\n"
        "leal (%edi, %ecx), %edx\n" /* line 659 */
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ebx, %eax, 4), %eax\n"
        "movl 8(%ebp), %edx\n" /* line 661 | index */
        "cmpl (%eax), %edx\n"
        "jne .Lf17f858_0017f8a5\n"
        ".Lf17f858_0017f8cb:\n"
        "movl 0x10(%ebp), %edx\n" /* line 663 | size */
        "movl %edx, 8(%esp)\n"
        "addl $0x3c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 669 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17f858_0017f8f1:\n"
        "xorl %eax, %eax\n" /* line 657 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 669 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 851 */
int UI_PlayLocalSoundAlias(snd_alias_list_t *aliasList)
{
    return SND_PlayLocalSoundAlias(aliasList, 0);
}

/* line 863 */
int UI_PlayLocalSoundAliasByName(const char *aliasname)
{
    return SND_PlayLocalSoundAliasByName(aliasname, 0);
}

/* line 884 */
qboolean UI_ClientIsInGame(void)
{
    return *(int *)(*(int *)(*(int *)0x195ee8c)) == 8;
}

/* line 899 */
__attribute__((naked))
qboolean CL_ShutdownUI(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 899 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195ecac, %ebx\n" /* line 903 */
        "movl 0x110(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf17f94a_0017f969\n"
        "xorl %eax, %eax\n"
        "addl $0x14, %esp\n" /* line 926 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17f94a_0017f969:\n"
        "movl $0, (%esp)\n" /* line 907 */
        "calll Com_UnloadSoundAliases\n"
        "movl 0x195ee78, %eax\n" /* line 910 */
        "movl (%eax), %eax\n"
        "andl $0xfffffff7, 4(%eax)\n"
        "movb $0, 8(%eax)\n" /* line 911 */
        "movl $0, (%esp)\n" /* line 917 */
        "calll CL_SwitchToLocalClient\n"
        "calll UI_Shutdown\n" /* line 919 */
        "movl $0, (%esp)\n" /* line 922 */
        "calll CL_SwitchToLocalClient\n"
        "movl $0, 0x110(%ebx)\n" /* line 924 */
        "movl $1, %eax\n"
        "addl $0x14, %esp\n" /* line 926 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 935 */
__attribute__((naked))
void CL_InitUI(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 935 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195ecac, %eax\n" /* line 939 */
        "movl $1, 0x110(%eax)\n"
        "movl $0, (%esp)\n" /* line 945 */
        "calll CL_SwitchToLocalClient\n"
        "calll UI_Init\n" /* line 948 */
        "movl $0, (%esp)\n" /* line 951 */
        "calll CL_SwitchToLocalClient\n"
        "leave\n" /* line 954 */
        "jmp UI_Component_Init\n" /* line 953 */
    );
}

/* line 963 */
__attribute__((naked))
qboolean UI_checkKeyExec(int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 963 */
        "movl %esp, %ebp\n"
        "movl 0x195ecac, %eax\n" /* line 965 */
        "movl 0x110(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf17f9ee_0017fa04\n"
        "xorl %eax, %eax\n" /* line 969 */
        "popl %ebp\n"
        "retl\n"
        ".Lf17f9ee_0017fa04:\n"
        "popl %ebp\n"
        "jmp UI_CheckExecKey\n" /* line 966 */
    );
}

/* line 979 */
void UI_LoadSoundAliases(void)
{
    Com_LoadSoundAliases("menu", "all_mp", 0);
}

/* line 301 */
__attribute__((naked))
int LAN_CompareHostname(const char *hostName1, const char *hostName2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 301 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 284 | hostName1 */
        "movzbl (%eax), %ebx\n" /* c */
        "testb %bl, %bl\n" /* line 285 | c */
        "je .Lf17fa2e_0017fa8f\n"
        "movl %eax, %esi\n" /* line 286 */
        "leal -0x38(%ebp), %edi\n" /* cleanHostName1 */
        "jmp .Lf17fa2e_0017fa6e\n"
        /* { scope 4 */
        ".Lf17fa2e_0017fa48:\n"
        "movl __DefaultRuneLocale, %edx\n" /* line 220 */
        "movl 0x34(%edx, %eax, 4), %eax\n"
        "shrl $8, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        ".Lf17fa2e_0017fa58:\n"
        "testl %eax, %eax\n" /* line 287 | _c */
        "je .Lf17fa2e_0017fa61\n"
        "movb %bl, (%edi)\n" /* line 289 | c */
        "addl $1, %edi\n" /* line 290 */
        ".Lf17fa2e_0017fa61:\n"
        "movzbl 1(%esi), %eax\n" /* line 284 */
        "movl %eax, %ebx\n" /* c */
        "addl $1, %esi\n"
        "testb %al, %al\n" /* line 285 */
        "je .Lf17fa2e_0017fa92\n"
        ".Lf17fa2e_0017fa6e:\n"
        "movzbl %bl, %eax\n" /* line 287 | c, _c */
        /* { scope 4 */
        "testb $0x80, %al\n" /* line 220 */
        "je .Lf17fa2e_0017fa48\n"
        "movl $0x100, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf17fa2e_0017fa58\n"
        /* } scope */
        ".Lf17fa2e_0017fa8f:\n"
        "leal -0x38(%ebp), %edi\n" /* line 286 | cleanHostName1 */
        ".Lf17fa2e_0017fa92:\n"
        "movb $0, (%edi)\n" /* line 292 */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%ebp), %eax\n" /* line 284 | hostName2 */
        "movzbl (%eax), %ebx\n" /* c */
        "testb %bl, %bl\n" /* line 285 | c */
        "je .Lf17fa2e_0017faed\n"
        "movl %eax, %esi\n" /* line 286 */
        "leal -0x58(%ebp), %edi\n" /* cleanHostName2 */
        "jmp .Lf17fa2e_0017facc\n"
        /* { scope 4 */
        ".Lf17fa2e_0017faa6:\n"
        "movl __DefaultRuneLocale, %edx\n" /* line 220 */
        "movl 0x34(%edx, %eax, 4), %eax\n"
        "shrl $8, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        ".Lf17fa2e_0017fab6:\n"
        "testl %eax, %eax\n" /* line 287 | _c */
        "je .Lf17fa2e_0017fabf\n"
        "movb %bl, (%edi)\n" /* line 289 | c */
        "addl $1, %edi\n" /* line 290 */
        ".Lf17fa2e_0017fabf:\n"
        "movzbl 1(%esi), %eax\n" /* line 284 */
        "movl %eax, %ebx\n" /* c */
        "addl $1, %esi\n"
        "testb %al, %al\n" /* line 285 */
        "je .Lf17fa2e_0017faf0\n"
        ".Lf17fa2e_0017facc:\n"
        "movzbl %bl, %eax\n" /* line 287 | c, _c */
        /* { scope 4 */
        "testb $0x80, %al\n" /* line 220 */
        "je .Lf17fa2e_0017faa6\n"
        "movl $0x100, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf17fa2e_0017fab6\n"
        /* } scope */
        ".Lf17fa2e_0017faed:\n"
        "leal -0x58(%ebp), %edi\n" /* line 286 | cleanHostName2 */
        ".Lf17fa2e_0017faf0:\n"
        "movb $0, (%edi)\n" /* line 292 */
        /* } scope */
        /* } scope */
        "leal -0x58(%ebp), %eax\n" /* line 310 | cleanHostName2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* cleanHostName1 */
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n" /* line 311 */
        "jne .Lf17fa2e_0017fb1b\n"
        "movl 0xc(%ebp), %eax\n" /* hostName2 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* hostName1 */
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        /* } scope */
        ".Lf17fa2e_0017fb1b:\n"
        "addl $0x5c, %esp\n" /* line 312 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 320 */
__attribute__((naked))
int LAN_CompareServers(int source, int sortKey, int sortDir, int s1, int s2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 320 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl 0x14(%ebp), %edx\n" /* s1 */
        "movl 0x18(%ebp), %ecx\n" /* s2 */
        /* { scope 1 */
        "cmpl $1, %eax\n" /* line 244 */
        "je .Lf17fb24_0017fbc5\n"
        "cmpl $2, %eax\n"
        "je .Lf17fb24_0017fc43\n"
        "testl %eax, %eax\n"
        "je .Lf17fb24_0017fb84\n"
        "cmpl $1, %eax\n"
        "je .Lf17fb24_0017fbdb\n"
        "cmpl $2, %eax\n"
        "je .Lf17fb24_0017fc48\n"
        "testl %eax, %eax\n"
        "jne .Lf17fb24_0017fc37\n"
        ".Lf17fb24_0017fb66:\n"
        "xorl %esi, %esi\n"
        "cmpl $0x7f, %ecx\n" /* line 247 */
        "ja .Lf17fb24_0017fba3\n"
        ".Lf17fb24_0017fb6d:\n"
        "movl %ecx, %eax\n" /* line 249 */
        "shll $7, %eax\n"
        "leal 0x130(%eax, %ecx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "leal 0xc(%eax), %ebx\n"
        "jmp .Lf17fb24_0017fba5\n"
        ".Lf17fb24_0017fb84:\n"
        "cmpl $0x7f, %edx\n" /* line 247 */
        "ja .Lf17fb24_0017fb66\n"
        "movl %edx, %eax\n" /* line 249 */
        "shll $7, %eax\n"
        "leal 0x130(%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "leal 0xc(%eax), %esi\n"
        "cmpl $0x7f, %ecx\n" /* line 247 */
        "jbe .Lf17fb24_0017fb6d\n"
        ".Lf17fb24_0017fba3:\n"
        "xorl %ebx, %ebx\n" /* line 264 */
        ".Lf17fb24_0017fba5:\n"
        "testl %esi, %esi\n" /* line 327 | server1 */
        "je .Lf17fb24_0017fc37\n"
        "testl %ebx, %ebx\n" /* server2 */
        "je .Lf17fb24_0017fc37\n"
        "cmpl $9, 0xc(%ebp)\n" /* line 333 | sortKey */
        "ja .Lf17fb24_0017fc33\n"
        "movl 0xc(%ebp), %eax\n" /* sortKey */
        "jmpl *0x302ca0(, %eax, 4)\n"
        ".Lf17fb24_0017fbc5:\n"
        "testl %edx, %edx\n" /* line 254 */
        "js .Lf17fb24_0017fbdb\n"
        "movl 0x195ecac, %ebx\n"
        "cmpl 0x4540(%ebx), %edx\n"
        "jl .Lf17fb24_0017fc6d\n"
        ".Lf17fb24_0017fbdb:\n"
        "xorl %esi, %esi\n" /* line 249 */
        ".Lf17fb24_0017fbdd:\n"
        "testl %ecx, %ecx\n" /* line 254 */
        "js .Lf17fb24_0017fba3\n"
        "movl 0x195ecac, %edx\n"
        "cmpl 0x4540(%edx), %ecx\n"
        "jge .Lf17fb24_0017fba3\n"
        "movl %ecx, %eax\n" /* line 256 */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %ecx, 8), %eax\n"
        "leal 4(%eax, %edx), %ebx\n"
        "jmp .Lf17fb24_0017fba5\n"
        "movzbl 0x17(%esi), %edx\n" /* line 359 | server1 */
        "movzbl 0x17(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 360 */
        "jne .Lf17fb24_0017fc20\n"
        ".Lf17fb24_0017fc0d:\n"
        "movl $0, 0x10(%ebp)\n" /* line 391 | sortDir */
        "movswl 0x1e(%esi), %edx\n" /* line 400 | server1 */
        "movswl 0x1e(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 401 */
        "je .Lf17fb24_0017fc99\n"
        ".Lf17fb24_0017fc20:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 410 | sortDir, server2 */
        "testl %ebx, %ebx\n" /* server2 */
        "je .Lf17fb24_0017fc29\n"
        "negl %edx\n"
        /* } scope */
        ".Lf17fb24_0017fc29:\n"
        "movl %edx, %eax\n" /* line 411 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17fb24_0017fc33:\n"
        "xorl %edx, %edx\n" /* line 333 */
        "jmp .Lf17fb24_0017fc20\n"
        ".Lf17fb24_0017fc37:\n"
        "xorl %edx, %edx\n" /* line 410 */
        /* } scope */
        "movl %edx, %eax\n" /* line 411 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17fb24_0017fc43:\n"
        "cmpl $0x7f, %edx\n" /* line 262 */
        "jbe .Lf17fb24_0017fc82\n"
        ".Lf17fb24_0017fc48:\n"
        "xorl %esi, %esi\n" /* line 256 */
        ".Lf17fb24_0017fc4a:\n"
        "cmpl $0x7f, %ecx\n" /* line 262 */
        "ja .Lf17fb24_0017fba3\n"
        "movl %ecx, %eax\n" /* line 264 */
        "shll $7, %eax\n"
        "leal 0x29c640(%eax, %ecx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "leal 8(%eax), %ebx\n"
        "jmp .Lf17fb24_0017fba5\n"
        ".Lf17fb24_0017fc6d:\n"
        "movl %edx, %eax\n" /* line 256 */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %edx, 8), %eax\n"
        "leal 4(%eax, %ebx), %esi\n"
        "jmp .Lf17fb24_0017fbdd\n"
        ".Lf17fb24_0017fc82:\n"
        "movl %edx, %eax\n" /* line 264 */
        "shll $7, %eax\n"
        "leal 0x29c640(%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "leal 8(%eax), %esi\n"
        "jmp .Lf17fb24_0017fc4a\n"
        ".Lf17fb24_0017fc99:\n"
        "leal 0x78(%ebx), %eax\n" /* line 403 | server2 */
        "movl %eax, 4(%esp)\n"
        "leal 0x78(%esi), %eax\n" /* server1 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 404 */
        "jne .Lf17fb24_0017fc20\n"
        "leal 0x20(%ebx), %eax\n" /* line 405 | server2 */
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%esi), %eax\n" /* server1 */
        "movl %eax, (%esp)\n"
        "calll LAN_CompareHostname\n"
        "movl %eax, %edx\n"
        "jmp .Lf17fb24_0017fc20\n"
        "leal 0x78(%ebx), %eax\n" /* line 390 | server2 */
        "movl %eax, 4(%esp)\n"
        "leal 0x78(%esi), %eax\n" /* server1 */
        ".Lf17fb24_0017fcd8:\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 391 */
        "jne .Lf17fb24_0017fc20\n"
        "jmp .Lf17fb24_0017fc0d\n"
        "movzbl 0xd(%esi), %edx\n" /* line 385 | server1 */
        "movzbl 0xd(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 386 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        "leal 0x40(%ebx), %eax\n" /* line 380 | server2 */
        "movl %eax, 4(%esp)\n"
        "leal 0x40(%esi), %eax\n" /* server1 */
        "jmp .Lf17fb24_0017fcd8\n"
        "leal 0x20(%ebx), %eax\n" /* line 375 | server2 */
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%esi), %eax\n" /* server1 */
        "movl %eax, (%esp)\n"
        "calll LAN_CompareHostname\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 376 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        "movzbl 0x16(%esi), %edi\n" /* line 344 | server1 */
        "movzbl 0x16(%ebx), %ecx\n" /* server2 */
        "movl %edi, %eax\n"
        "movzbl %al, %edx\n"
        "movzbl %cl, %eax\n"
        "subl %eax, %edx\n"
        "cmpl $0, %edx\n" /* line 345 */
        "je .Lf17fb24_0017fc0d\n"
        "jl .Lf17fb24_0017fd9f\n" /* line 347 */
        "testb %cl, %cl\n" /* line 354 */
        "jne .Lf17fb24_0017fc20\n"
        "movl $0xffffffff, %edx\n"
        "jmp .Lf17fb24_0017fc20\n"
        "movzbl 0x11(%esi), %edx\n" /* line 337 | server1 */
        "movzbl 0x11(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 338 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        "movzbl 0x12(%esi), %edx\n" /* line 369 | server1 */
        "movzbl 0x12(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 370 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        "movzbl 0x18(%esi), %edx\n" /* line 364 | server1 */
        "movzbl 0x18(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 365 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        ".Lf17fb24_0017fd9f:\n"
        "movl %edi, %eax\n" /* line 349 */
        "testb %al, %al\n"
        "jne .Lf17fb24_0017fc20\n"
        "movl $1, %edx\n"
        "jmp .Lf17fb24_0017fc20\n"
    );
}

