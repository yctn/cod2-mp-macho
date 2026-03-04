/* ASM dump from: cl_ui_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_ui_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern qboolean CL_UpdateDirtyPings_f(int source);
extern int CL_ServerStatus(char *serverAddress, char *serverStatus, int maxLen);
extern int SND_PlayLocalSoundAlias(snd_alias_list_t *aliasList, int channel);
extern int SND_PlayLocalSoundAliasByName(const char *aliasname, int channel);
extern void Com_LoadSoundAliases(const char *zone, const char *spec, int flags);
extern qboolean UI_CheckExecKey(int key);
extern void CL_SwitchToLocalClient(int localClientNum);
extern void UI_Init(void);
extern void UI_Component_Init(void);
extern const char *Key_KeynumToString(int keynum, int translate);
extern const char *Key_GetBinding(int keynum);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern const dvar_t * Dvar_RegisterString(const char *dvarName, const char *value, unsigned int flags);
extern void Com_WriteCDKey(void);
extern void Com_PumpMessageLoop(void);
extern void Info_SetValueForKey(char *s, const char *key, const char *value);
extern char * va(const char *format, ...);
extern const char * NET_AdrToString(netadr_t adr);
extern void Com_UnloadSoundAliases(int zone);
extern void UI_Shutdown(void);

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
void GetClientState(uiClientState_t *state)
{
    byte *cls = *(byte **)imp_clc;
    byte *clc = (byte *)imp_cls;
    byte *cl = *(byte **)imp_cl;

    *(int *)((byte *)state + 4) = *(int *)(cls + 0x24);
    *(int *)state = *(int *)cls;
    I_strncpyz((char *)state + 0xc, (const char *)(clc + 8), 0x400);
    I_strncpyz((char *)state + 0x40c, (const char *)(cls + 0x28), 0x400);
    *(int *)((byte *)state + 8) = *(int *)(cl + 0x100);
}

/* line 41 */
void LAN_ResetPings(int source)
{
    byte *base = (byte *)imp_cls;
    byte *server;
    int count;

    if (source == 0) {
        count = 128;
        server = base + 0x13c;
    } else if (source == 1) {
        count = *(int *)(base + 0x4540);
        server = base + 0x4544;
        if (count <= 0)
            return;
    } else if (source == 2) {
        count = 128;
        server = base + 0x29c648;
    } else {
        return;
    }

    for (int i = 0; i < count; i++) {
        *(short *)(server + 0x1e) = -1;
        server += 0x88;
    }
}

/* line 82 */
int LAN_GetServerCount(int source)
{
    byte *base = (byte *)imp_cls;
    if (source == 0)
        return *(int *)(base + 0x138);
    if (source == 1)
        return *(int *)(base + 0x4540);
    if (source == 2)
        return *(int *)(base + 0x29c644);
    return 0;
}

/* line 106 */
qboolean LAN_WaitServerResponse(int source)
{
    if (source != 1)
        return 0;
    return *(int *)((byte *)imp_cls + 0x453c);
}

/* line 124 */
void LAN_GetServerInfo(int source, int n, char *buf, int buflen)
{
    char info[1024];
    byte *base = (byte *)imp_cls;
    byte *server = NULL;

    info[0] = '\0';

    if (source == 0) {
        if ((unsigned)n > 0x7f) goto fail;
        server = base + n * 0x88 + 0x13c;
    } else if (source == 1) {
        if (n < 0 || n >= *(int *)(base + 0x4540)) goto fail;
        server = base + n * 0x88 + 0x4544;
    } else if (source == 2) {
        if ((unsigned)n > 0x7f) goto fail;
        server = base + n * 0x88 + 0x29c648;
    } else {
        goto fail;
    }

    if (!server) goto fail;
    if (!buf) return;

    *buf = '\0';
    Info_SetValueForKey(info, "hostname", (char *)(server + 0x20));
    Info_SetValueForKey(info, "mapname", (char *)(server + 0x40));
    Info_SetValueForKey(info, "clients", va("%i", (int)*(byte *)(server + 0xd)));
    Info_SetValueForKey(info, "sv_maxclients", va("%i", (int)*(byte *)(server + 0xe)));
    Info_SetValueForKey(info, "ping", va("%i", (int)*(short *)(server + 0x1e)));
    Info_SetValueForKey(info, "minping", va("%i", (int)*(short *)(server + 0x1a)));
    Info_SetValueForKey(info, "maxping", va("%i", (int)*(short *)(server + 0x1c)));
    Info_SetValueForKey(info, "game", (char *)(server + 0x60));
    Info_SetValueForKey(info, "gametype", (char *)(server + 0x78));
    Info_SetValueForKey(info, "nettype", va("%i", (int)*(byte *)(server + 0xc)));
    {
        netadr_t adr;
        memcpy(&adr, server, 12);
        Info_SetValueForKey(info, "addr", NET_AdrToString(adr));
    }
    Info_SetValueForKey(info, "sv_allowAnonymous", va("%i", (int)*(byte *)(server + 0x10)));
    Info_SetValueForKey(info, "con_disabled", va("%i", (int)*(signed char *)(server + 0x15)));
    Info_SetValueForKey(info, "pswrd", va("%i", (int)*(byte *)(server + 0x11)));
    Info_SetValueForKey(info, "pure", va("%i", (int)*(byte *)(server + 0x12)));
    Info_SetValueForKey(info, "ff", va("%i", (int)*(signed char *)(server + 0x13)));
    Info_SetValueForKey(info, "kc", va("%i", (int)*(signed char *)(server + 0x14)));
    Info_SetValueForKey(info, "hw", va("%i", (int)*(byte *)(server + 0x16)));
    Info_SetValueForKey(info, "mod", va("%i", (int)*(byte *)(server + 0x17)));
    Info_SetValueForKey(info, "voice", va("%i", (int)*(byte *)(server + 0x18)));
    I_strncpyz(buf, info, buflen);
    return;

fail:
    if (buf)
        *buf = '\0';
}

/* line 200 */
int LAN_GetServerPing(int source, int n)
{
    byte *base = (byte *)imp_cls;
    byte *server;

    if (source == 0) {
        if ((unsigned)n > 0x7f)
            return -1;
        server = base + n * 0x88 + 0x13c;
    } else if (source == 1) {
        if (n < 0 || n >= *(int *)(base + 0x4540))
            return -1;
        server = base + n * 0x88 + 0x4544;
    } else if (source == 2) {
        if ((unsigned)n > 0x7f)
            return -1;
        server = base + n * 0x88 + 0x29c648;
    } else {
        return -1;
    }

    if (!server)
        return -1;
    return *(short *)(server + 0x1e);
}

/* line 419 */
void LAN_MarkServerDirty(int source, int n, qboolean dirty)
{
    byte *base = (byte *)imp_cls;
    int count;
    byte *ptr;
    int i;

    Com_PumpMessageLoop();

    if (n == -1) {
        /* Mark all servers dirty */
        if (source == 0) {
            count = 0x80;
            ptr = base + 0x13c;
        } else if (source == 1) {
            count = *(int *)(base + 0x4540);
            ptr = base + 0x4544;
            if (count <= 0) return;
        } else if (source == 2) {
            count = 0x80;
            ptr = base + 0x29c648;
        } else {
            return;
        }
        for (i = 0; i < count; i++) {
            *(byte *)(ptr + 0xf) = (byte)dirty;
            ptr += 0x88;
        }
    } else {
        if (source == 0) {
            if ((unsigned)n > 0x7f) return;
            *(byte *)(base + n * 0x88 + 0x14b) = (byte)dirty;
        } else if (source == 1) {
            if (n < 0 || n >= *(int *)(base + 0x4540)) return;
            *(byte *)(base + n * 0x88 + 0x4553) = (byte)dirty;
        } else if (source == 2) {
            if ((unsigned)n > 0x7f) return;
            *(byte *)(base + n * 0x88 + 0x29c657) = (byte)dirty;
        }
    }
}

/* line 490 */
int LAN_ServerIsDirty(int source, int n)
{
    byte *base = (byte *)imp_cls;

    if (source == 0) {
        if ((unsigned)n > 0x7f)
            return 0;
        return *(byte *)(base + n * 0x88 + 0x14b);
    } else if (source == 1) {
        if (n < 0 || n >= *(int *)(base + 0x4540))
            return 0;
        return *(byte *)(base + n * 0x88 + 0x4553);
    } else if (source == 2) {
        if ((unsigned)n > 0x7f)
            return 0;
        return *(byte *)(base + n * 0x88 + 0x29c657);
    }
    return 0;
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
void Key_KeynumToStringBuf(int keynum, char *buf, int buflen)
{
    I_strncpyz(buf, Key_KeynumToString(keynum, 1), buflen);
}

/* line 561 */
void Key_GetBindingBuf(int keynum, char *buf, int buflen)
{
    const char *binding = Key_GetBinding(keynum);
    if (binding)
    {
        I_strncpyz(buf, binding, buflen);
        return;
    }
    *buf = 0;
}

/* line 582 */
int Key_GetCatcher(void)
{
    return *(int *)((char *)*(void **)imp_cl + 4);
}

/* line 593 */
void Key_SetCatcher(int catcher)
{
    byte *ptr = (byte *)*(void **)imp_cl;
    if (*(int *)(ptr + 4) & 1)
        *(int *)(ptr + 4) = catcher | 1;
    else
        *(int *)(ptr + 4) = catcher;
    ptr = (byte *)*(void **)imp_cl;
    if (!(*(int *)(ptr + 4) & 8))
        *(byte *)(ptr + 8) = 0;
}

/* line 611 */
void CLUI_GetCDKey(char *buf, int buflen, char *buf2, int buf2len)
{
    char *cdkey;
    char *cdkey2;

    Dvar_RegisterString((const char *)str_00216d64, (const char *)str_002157b8, 0x101c); /* "fs_game" */

    cdkey = *(char **)imp_cl_cdkey;
    memcpy(buf, cdkey, 16);
    buf[16] = '\0';

    cdkey2 = *(char **)imp_cl_cdkeychecksum;
    memcpy(buf2, cdkey2, 4);
    buf2[4] = '\0';
}

/* line 631 */
void CLUI_SetCDKey(char *buf, char *buf2)
{
    char *cdkey = *(char **)imp_cl_cdkey;
    char *cdkey2 = *(char **)imp_cl_cdkeychecksum;

    memcpy(cdkey, buf, 16);
    cdkey[16] = '\0';

    memcpy(cdkey2, buf2, 4);
    cdkey2[4] = '\0';

    Com_WriteCDKey();
}

/* line 647 */
qboolean GetClientname(int index, char *buf, int size)
{
    byte *cl;
    int count;
    int start;
    int i;

    *buf = '\0';

    cl = (byte *)*(void **)imp_cl;
    if (!*(int *)(cl + 0x18))
        return 0;

    count = *(int *)(cl + 0x26e0);
    if (count <= 0)
        return 0;

    start = *(int *)(cl + 0x26e8);

    for (i = 0; i < count; i++) {
        int slot = (start + i) & 0x7ff;
        int entryOffset = (slot * 24 - slot) * 4;
        byte *entry = cl + 0x14b0e0 + entryOffset;

        if (*(int *)entry == index) {
            strncpy(buf, (char *)(entry + 0x3c), size);
            return 1;
        }
    }

    return 0;
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
    return *(int *)*(void **)imp_clc == 8;
}

/* line 899 */
qboolean CL_ShutdownUI(void)
{
    byte *clc = (byte *)imp_cls;
    byte *cl;

    if (!*(int *)(clc + 0x110))
        return 0;

    Com_UnloadSoundAliases(0);

    cl = (byte *)*(void **)imp_cl;
    *(int *)(cl + 4) &= ~8;
    *(byte *)(cl + 8) = 0;

    CL_SwitchToLocalClient(0);
    UI_Shutdown();
    CL_SwitchToLocalClient(0);

    *(int *)(clc + 0x110) = 0;
    return 1;
}

/* line 935 */
void CL_InitUI(void)
{
    *(int *)((byte *)imp_cls + 0x110) = 1;
    CL_SwitchToLocalClient(0);
    UI_Init();
    CL_SwitchToLocalClient(0);
    UI_Component_Init();
}

/* line 963 */
qboolean UI_checkKeyExec(int key)
{
    if (!*(int *)((byte *)imp_cls + 0x110))
        return 0;
    return UI_CheckExecKey(key);
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
        "addl imp_cls, %eax\n"
        "leal 0xc(%eax), %ebx\n"
        "jmp .Lf17fb24_0017fba5\n"
        ".Lf17fb24_0017fb84:\n"
        "cmpl $0x7f, %edx\n" /* line 247 */
        "ja .Lf17fb24_0017fb66\n"
        "movl %edx, %eax\n" /* line 249 */
        "shll $7, %eax\n"
        "leal 0x130(%eax, %edx, 8), %eax\n"
        "addl imp_cls, %eax\n"
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
        "jmpl *.Ljt_17fb24_0(, %eax, 4)\n"
        ".Lf17fb24_0017fbc5:\n"
        "testl %edx, %edx\n" /* line 254 */
        "js .Lf17fb24_0017fbdb\n"
        "movl imp_cls, %ebx\n"
        "cmpl 0x4540(%ebx), %edx\n"
        "jl .Lf17fb24_0017fc6d\n"
        ".Lf17fb24_0017fbdb:\n"
        "xorl %esi, %esi\n" /* line 249 */
        ".Lf17fb24_0017fbdd:\n"
        "testl %ecx, %ecx\n" /* line 254 */
        "js .Lf17fb24_0017fba3\n"
        "movl imp_cls, %edx\n"
        "cmpl 0x4540(%edx), %ecx\n"
        "jge .Lf17fb24_0017fba3\n"
        "movl %ecx, %eax\n" /* line 256 */
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %ecx, 8), %eax\n"
        "leal 4(%eax, %edx), %ebx\n"
        "jmp .Lf17fb24_0017fba5\n"
        ".Lf17fb24_0017fc01:\n"
        "movzbl 0x17(%esi), %edx\n" /* line 359 | server1 */
        "movzbl 0x17(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 360 */
        "jne .Lf17fb24_0017fc20\n"
        ".Lf17fb24_0017fc0d:\n"
        "movl $0, 0x10(%ebp)\n" /* line 391 | sortDir */
        ".Lf17fb24_0017fc14:\n"
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
        "leal str_0029c494+428(%eax, %ecx, 8), %eax\n"
        "addl imp_cls, %eax\n"
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
        "leal str_0029c494+428(%eax, %edx, 8), %eax\n"
        "addl imp_cls, %eax\n"
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
        ".Lf17fb24_0017fcce:\n"
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
        ".Lf17fb24_0017fcef:\n"
        "movzbl 0xd(%esi), %edx\n" /* line 385 | server1 */
        "movzbl 0xd(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 386 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        ".Lf17fb24_0017fd04:\n"
        "leal 0x40(%ebx), %eax\n" /* line 380 | server2 */
        "movl %eax, 4(%esp)\n"
        "leal 0x40(%esi), %eax\n" /* server1 */
        "jmp .Lf17fb24_0017fcd8\n"
        ".Lf17fb24_0017fd10:\n"
        "leal 0x20(%ebx), %eax\n" /* line 375 | server2 */
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%esi), %eax\n" /* server1 */
        "movl %eax, (%esp)\n"
        "calll LAN_CompareHostname\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 376 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        ".Lf17fb24_0017fd31:\n"
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
        ".Lf17fb24_0017fd60:\n"
        "movzbl 0x11(%esi), %edx\n" /* line 337 | server1 */
        "movzbl 0x11(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 338 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        ".Lf17fb24_0017fd75:\n"
        "movzbl 0x12(%esi), %edx\n" /* line 369 | server1 */
        "movzbl 0x12(%ebx), %eax\n" /* server2 */
        "subl %eax, %edx\n" /* line 370 */
        "je .Lf17fb24_0017fc0d\n"
        "jmp .Lf17fb24_0017fc20\n"
        ".Lf17fb24_0017fd8a:\n"
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
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_17fb24_0:\n"
        ".long .Lf17fb24_0017fd60\n"
        ".long .Lf17fb24_0017fd31\n"
        ".long .Lf17fb24_0017fd10\n"
        ".long .Lf17fb24_0017fd04\n"
        ".long .Lf17fb24_0017fcef\n"
        ".long .Lf17fb24_0017fcce\n"
        ".long .Lf17fb24_0017fd8a\n"
        ".long .Lf17fb24_0017fd75\n"
        ".long .Lf17fb24_0017fc01\n"
        ".long .Lf17fb24_0017fc14\n"
        ".text\n"
    );
}

