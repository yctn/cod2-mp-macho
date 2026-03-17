/* ASM dump from: cl_main_pc_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_main_pc_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern serverStatus_t cl_serverStatusList[16]; /* 0x0 */
static Bool s_playerMute[64]; /* s_playerMute */
extern int NET_CompareAdrSigned(const int *a, const int *b);
extern qboolean NET_CompareAdr(netadr_t a, netadr_t b);
extern void qsort(void *base, unsigned int nmemb, unsigned int size, int (*compar)(const void *, const void *));
extern int atoi(const char *nptr);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern const char *va(const char *format, ...);
extern void Cbuf_ExecuteText(int exec_when, const char *text);
extern void Com_PumpMessageLoop(void);
extern const char *MSG_ReadString(msg_t *msg);
extern const char *MSG_ReadStringLine(msg_t *msg);
extern void Com_DPrintf(const char *fmt, ...);
extern const char *Dvar_GetString(const char *name);
extern const char *NET_AdrToString(netadr_t adr);
extern void Info_SetValueForKey(const char *s, const char *key, const char *value);
extern int Cmd_Argc(void);
extern const char *Cmd_Argv(int arg);
extern void Com_Printf(const char *fmt, ...);
extern int I_stricmp(const char *s0, const char *s1);
extern int I_strnicmp(const char *s0, const char *s1, int n);
extern int Com_AddToString(const char *src, char *buf, int bufSize, int offset, int addQuotes);
extern void CL_Netchan_SendOOBPacket(int len, const char *data, int type, int addr0, int addr1);
extern int NET_StringToAdr(const char *s, netadr_t *a);
extern int NET_OutOfBandPrint(int type, int addr0, int addr1, int addr2, const char *data);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern int Sys_Milliseconds(void);
extern int sscanf(const char *str, const char *format, ...);
extern char *strchr(const char *s, int c);
extern qboolean Dvar_GetBool(const char *name);
extern int sprintf(char *str, const char *format, ...);
extern void SND_StopSounds(int a);
extern void SV_Frame(int a);
extern void CL_Disconnect(void);
extern void Con_Close(void);
extern qboolean NET_IsLocalAddress(int addr0, int addr1, int addr2);
extern void UI_CloseAll(void);
extern void SCR_UpdateScreen(void);
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_Memset(void *dest, int value, int count);
extern void Dvar_SetString(const dvar_t *dvar, const char *value);

static int rconGlob; /* rconGlob */

static int CL_CompareAdrSigned(const int *a, const int *b);
int CL_SetServerInfo(serverInfo_t *server, const char *info, int ping);
int CL_SetServerInfoByAddress(netadr_t from, const char *info, int ping);
int CL_ServerInfoPacket(netadr_t from, msg_t *msg, int time);
qboolean CL_CDKeyValidate(const char *key, const char *checksum);
int CL_SortGlobalServers(void);
int CL_RconInit(void);
int CL_Rcon_f(void);
int CL_ServerStatusResponse(netadr_t from, msg_t *msg);
int CL_ResetPlayerMuting(int clientIndex);
int CL_MutePlayer(int clientIndex);
Bool CL_IsPlayerMuted(int clientIndex);
int CL_ClearMutedList(void);
int CL_GlobalServers_f(void);
int CL_ServersResponsePacket(netadr_t from, msg_t *msg);
int CL_Ping_f(void);
int CL_Connect_f(void);
int CL_ServerStatus(char *serverAddress, char *serverStatusString, int maxLen);
int CL_ServerStatus_f(void);

/* line 89 */
static int CL_CompareAdrSigned(const int *a, const int *b)
{
    return NET_CompareAdrSigned(a, b);
}

/* line 156 */
int CL_SetServerInfo(serverInfo_t *server, const char *info, int ping)
{
    if (server == NULL) {
        return 0;
    }

    if (info != NULL) {
        server->clients = (byte)atoi(Info_ValueForKey(info, "clients"));
        I_strncpyz(server->hostName, Info_ValueForKey(info, "hostname"), 0x20);
        I_strncpyz(server->mapName, Info_ValueForKey(info, "mapname"), 0x20);
        server->maxClients = (byte)atoi(Info_ValueForKey(info, "sv_maxclients"));
        I_strncpyz(server->game, Info_ValueForKey(info, "game"), 0x18);
        I_strncpyz(server->gameType, Info_ValueForKey(info, "gametype"), 0x10);
        server->netType = (byte)atoi(Info_ValueForKey(info, "nettype"));
        server->minPing = (short)atoi(Info_ValueForKey(info, "minping"));
        server->maxPing = (short)atoi(Info_ValueForKey(info, "maxping"));
        server->allowAnonymous = (byte)atoi(Info_ValueForKey(info, "sv_allowAnonymous"));
        server->consoleDisabled = (char)atoi(Info_ValueForKey(info, "con_disabled"));
        server->bPassword = (byte)atoi(Info_ValueForKey(info, "pswrd"));
        server->pure = (byte)atoi(Info_ValueForKey(info, "pure"));
        server->friendlyfire = (char)atoi(Info_ValueForKey(info, "ff"));
        server->killcam = (char)atoi(Info_ValueForKey(info, "kc"));
        server->hardware = (byte)atoi(Info_ValueForKey(info, "hw"));
        server->mod = (byte)atoi(Info_ValueForKey(info, "mod"));
        server->voice = (byte)atoi(Info_ValueForKey(info, "voice"));
    }

    server->ping = (short)ping;
    return 0;
}

/* line 94 */
int CL_SetServerInfoByAddress(netadr_t from, const char *info, int ping)
{
    clientStatic_t *cls;
    int i;
    int low;
    int high;
    int mid;
    int compare;

    Com_PumpMessageLoop();
    cls = (clientStatic_t *)imp_cls;

    for (i = 0; i < 128; ++i)
    {
        if (NET_CompareAdr(from, cls->localServers[i].adr))
        {
            CL_SetServerInfo(&cls->localServers[i], info, ping);
        }
    }

    high = cls->numglobalservers;
    if (high > 0)
    {
        low = 0;
        while (low < high)
        {
            mid = (low + high) / 2;
            compare = NET_CompareAdrSigned((const int *)&from, (const int *)&cls->globalServers[mid].adr);
            if (compare < 0)
            {
                high = mid;
                continue;
            }

            if (compare > 0)
            {
                low = mid + 1;
                continue;
            }

            while (mid > 0 && NET_CompareAdrSigned((const int *)&from, (const int *)&cls->globalServers[mid - 1].adr) == 0)
            {
                --mid;
            }

            for (i = mid; i < cls->numglobalservers; ++i)
            {
                if (NET_CompareAdrSigned((const int *)&from, (const int *)&cls->globalServers[i].adr) != 0)
                {
                    break;
                }

                CL_SetServerInfo(&cls->globalServers[i], info, ping);
            }
            break;
        }
    }

    for (i = 0; i < 128; ++i)
    {
        if (NET_CompareAdr(from, cls->favoriteServers[i].adr))
        {
            CL_SetServerInfo(&cls->favoriteServers[i], info, ping);
        }
    }

    return 0;
}

/* line 192 */
int CL_ServerInfoPacket(netadr_t from, msg_t *msg, int time)
{
    const char *infoString;
    int prot;
    int expectedProt;
    const char *protoStr;
    int i;
    byte *pinglist;
    byte *entry;
    char info[1024];
    int len;
    clientStatic_t *cls;

    infoString = MSG_ReadString(msg);
    prot = atoi(Info_ValueForKey(infoString, (const char *)str_002a7118));

    protoStr = Dvar_GetString((const char *)str_002aa7ec);
    if (*protoStr)
        expectedProt = atoi(protoStr);
    else
        expectedProt = 0x76;

    if (prot != expectedProt)
    {
        Com_DPrintf((const char *)str_002ab8d8, infoString);
        return 0;
    }

    /* search pinglist for matching address */
    pinglist = (byte *)imp_cl_pinglist;
    for (i = 0; i < 16; i++)
    {
        entry = pinglist + i * 0x414;
        /* check port != 0 */
        if (*(unsigned short *)(entry + 8) == 0)
            continue;
        /* check time == 0 (not yet received) */
        if (*(int *)(entry + 16) != 0)
            continue;
        /* compare addresses */
        {
            netadr_t pingAdr;
            memcpy(&pingAdr, entry, sizeof(netadr_t));
            if (!NET_CompareAdr(from, pingAdr))
                continue;
        }

        /* found matching ping entry */
        {
            int pingTime = time - *(int *)(entry + 0xc) + 1;
            *(int *)(entry + 0x10) = pingTime;
        }

        Com_DPrintf((const char *)str_002ab8fc, *(int *)(entry + 0x10), NET_AdrToString(from));

        /* copy infoString into ping info buffer */
        I_strncpyz((char *)(entry + 0x14), infoString, 0x400);

        /* set nettype */
        {
            int nettype = (from.type >= 3 && from.type <= 4) ? 1 : 0;
            Info_SetValueForKey((char *)(entry + 0x14), (const char *)str_002ab8c0, va((const char *)str_00215a64, nettype));
        }

        CL_SetServerInfoByAddress(from, infoString, *(int *)(entry + 0x10));
        return 0;
    }

    /* no matching ping entry found */
    cls = (clientStatic_t *)imp_cls;

    /* if waiting for global server response, return */
    if (*(int *)((byte *)cls + 0x2a0a48))
        return 0;

    /* find empty slot in localServers */
    for (i = 0; i < 128; i++)
    {
        byte *srv = (byte *)cls + i * 0x88;
        /* check if port is non-zero */
        if (*(unsigned short *)(srv + 0x144) != 0)
        {
            /* slot occupied, compare address */
            netadr_t srvAdr;
            memcpy(&srvAdr, srv + 0x13c, sizeof(netadr_t));
            if (NET_CompareAdr(from, srvAdr))
                return 0;
            continue;
        }

        /* found empty slot */
        {
            byte *base;
            serverInfo_t *server;

            *(int *)((byte *)cls + 0x138) = i + 1;

            base = (byte *)cls + i * 0x88;
            server = (serverInfo_t *)(base + 0x130);

            server->adr = from;
            server->dirty = 0;
            server->hostName[0] = '\0';
            server->mapName[0] = '\0';
            server->game[0] = '\0';
            server->minPing = 0;
            server->maxPing = 0;
            server->ping = -1;
            server->gameType[0] = '\0';
            *(byte *)(base + 0x1b4) = 0;
            server->netType = (byte)from.type;
            *(byte *)(base + 0x140 + 0xc) = 0;

            /* read second infoString (the server info line) */
            I_strncpyz(info, MSG_ReadString(msg), 0x400);
            if (!info[0])
                return 0;

            /* ensure info ends with newline */
            len = strlen(info);
            if (info[len - 2] != '\n')
            {
                info[len] = '\n';
                info[len + 1] = '\0';
            }

            Com_Printf((const char *)str_002ab944, NET_AdrToString(from), info);
            return 0;
        }
    }

    /* all 128 slots full */
    Com_DPrintf((const char *)str_002ab914);
    return 0;
}

/* line 390 — CD key validation bypassed for decompilation */
qboolean CL_CDKeyValidate(const char *key, const char *checksum)
{
    (void)key;
    (void)checksum;
    return 1;
}

#if 0 /* original naked asm */
__attribute__((naked))
qboolean CL_CDKeyValidate_orig(const char *key, const char *checksum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 390 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* key */
        "movl 0xc(%ebp), %esi\n" /* checksum */
        "xorl %edx, %edx\n"
        "movl $1, %ecx\n"
        /* { scope 1 */
        ".Lf1600ac_001600c1:\n"
        "movsbl -1(%ecx, %ebx), %eax\n" /* line 405 */
        "xorl %eax, %edx\n"
        "movl $8, %eax\n"
        "jmp .Lf1600ac_001600dc\n"
        ".Lf1600ac_001600cf:\n"
        "shrl $1, %edx\n" /* line 410 */
        "xorl $0xa001, %edx\n"
        "subl $1, %eax\n" /* line 407 */
        "je .Lf1600ac_001600e8\n"
        ".Lf1600ac_001600dc:\n"
        "testb $1, %dl\n" /* line 409 */
        "jne .Lf1600ac_001600cf\n"
        "shrl $1, %edx\n" /* line 412 */
        "subl $1, %eax\n" /* line 407 */
        "jne .Lf1600ac_001600dc\n"
        ".Lf1600ac_001600e8:\n"
        "addl $1, %ecx\n"
        "cmpl $0x11, %ecx\n" /* line 403 */
        "jne .Lf1600ac_001600c1\n"
        "movl %edx, 8(%esp)\n" /* line 416 */
        "movl $str_00228f18, 4(%esp)\n" /* "%04x" */
        "leal -0xd(%ebp), %ebx\n" /* chs, key */
        "movl %ebx, (%esp)\n" /* key */
        "calll sprintf\n"
        "testl %esi, %esi\n" /* line 418 | checksum */
        "je .Lf1600ac_0016012c\n"
        "movl $4, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* checksum */
        "movl %ebx, (%esp)\n" /* key */
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf1600ac_0016012c\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 425 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1600ac_0016012c:\n"
        "movl $1, %eax\n" /* line 418 */
        /* } scope */
        "addl $0x20, %esp\n" /* line 425 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif /* original naked asm */

/* line 432 */
int CL_SortGlobalServers(void)
{
    byte *base = (byte *)imp_cls;
    int count = *(int *)(base + 0x4540);
    qsort(base + 0x4544, count, 0x88, (int (*)(const void *, const void *))CL_CompareAdrSigned);
    return 0;
}

/* line 677 */
int CL_RconInit(void)
{
    *(byte *)&rconGlob = 0;
    *(int *)((char *)&rconGlob + 24) = 1;
}

/* line 750 */
int CL_Rcon_f(void)
{
    const char *cmd;
    char message[0x400];
    int offset;
    int i;
    netadr_t sendAdr;

    if (Cmd_Argc() <= 1)
    {
        Com_Printf((const char *)str_002ab94c);
        return 0;
    }

    cmd = Cmd_Argv(1);

    /* "login" subcommand */
    if (I_stricmp(cmd, (const char *)str_002ab970) == 0)
    {
        if (Cmd_Argc() != 3)
        {
            Com_Printf((const char *)str_002ab978);
            return 0;
        }
        {
            const char *pass = Cmd_Argv(2);
            int passLen = strlen(pass);
            if (passLen > 0x17)
            {
                Com_Printf((const char *)str_002ab998, 0x18);
                return 0;
            }
            memcpy(&rconGlob, pass, passLen + 1);
        }
        return 0;
    }

    /* "logout" subcommand */
    if (I_stricmp(cmd, (const char *)str_002ab9c8) == 0)
    {
        if (!*(byte *)&rconGlob)
        {
            Com_Printf((const char *)str_002ab9d0);
            return 0;
        }
        *(byte *)&rconGlob = 0;
        return 0;
    }

    /* "address" subcommand */
    if (I_stricmp(cmd, (const char *)str_002ab9e0) == 0)
    {
        if (Cmd_Argc() != 3)
        {
            Com_Printf((const char *)str_002ab9e8);
            return 0;
        }
        if (!NET_StringToAdr(Cmd_Argv(2), (netadr_t *)((char *)&rconGlob + 24)))
        {
            Com_Printf((const char *)str_002aba04);
            return 0;
        }
        if (*(unsigned short *)((char *)&rconGlob + 32) == 0)
        {
            *(unsigned short *)((char *)&rconGlob + 32) = 0x2071;
        }
        return 0;
    }

    /* send rcon command */
    if (!*(byte *)&rconGlob)
    {
        Com_Printf((const char *)str_002aba18);
        return 0;
    }

    /* build message with 0xFF 0xFF 0xFF 0xFF header */
    message[0] = (char)0xff;
    message[1] = (char)0xff;
    message[2] = (char)0xff;
    message[3] = (char)0xff;
    message[4] = '\0';

    offset = Com_AddToString((const char *)str_002aba5c, message, 0x400, 4, 0);
    offset = Com_AddToString((char *)&rconGlob, message, 0x400, offset, 0);

    for (i = 1; i < Cmd_Argc(); i++)
    {
        offset = Com_AddToString((const char *)str_00217914, message, 0x400, offset, 0);
        offset = Com_AddToString(Cmd_Argv(i), message, 0x400, offset, 1);
    }

    if (offset == 0x400)
    {
        Com_Printf((const char *)str_002aba64, 0x3ff);
        return 0;
    }

    message[offset] = '\0';

    /* determine send address */
    {
        byte *clc_ptr = *(byte **)imp_clc;
        if (*(int *)clc_ptr > 4)
        {
            /* use server address from connection */
            memcpy(&sendAdr, clc_ptr + 0x407d8, sizeof(netadr_t));
        }
        else
        {
            int addrType = *(int *)((char *)&rconGlob + 24);
            if (addrType == 1)
            {
                Com_Printf((const char *)str_002aba90);
                Com_Printf((const char *)str_002abacc);
                Com_Printf((const char *)str_002abaf0);
                return 0;
            }
            memcpy(&sendAdr, (char *)&rconGlob + 24, sizeof(netadr_t));
        }
    }

    {
        int msgLen = strlen(message);
        CL_Netchan_SendOOBPacket(msgLen, message, sendAdr.type, *(int *)((byte *)&sendAdr + 4), *(int *)((byte *)&sendAdr + 8));
    }

    return 0;
}

/* line 1095 */
int CL_ServerStatusResponse(netadr_t from, msg_t *msg);

/* original ASM preserved */
#if 0
__attribute__((naked))
int CL_ServerStatusResponse_asm(netadr_t from, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1095 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        "movl 0x10(%ebp), %eax\n"
        "movw %ax, -0x43e(%ebp)\n"
        "movzbl 0xf(%ebp), %ebx\n"
        "movb %bl, -0x43f(%ebp)\n"
        "movzbl 0xe(%ebp), %eax\n"
        "movb %al, -0x440(%ebp)\n"
        "movzbl 0xd(%ebp), %ebx\n"
        "movb %bl, -0x441(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x442(%ebp)\n"
        "movl 8(%ebp), %ebx\n" /* from */
        "movl %ebx, -0x448(%ebp)\n"
        "movl $0, -0x45c(%ebp)\n"
        "movl $cl_serverStatusList, %edi\n"
        "movl $cl_serverStatusList, %esi\n"
        /* { scope 1 */
        ".Lf160536_00160591:\n"
        "movl 0x2000(%edi), %ecx\n" /* line 1106 */
        "movl %ecx, -0x38(%ebp)\n"
        "movl 0x2004(%edi), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x2008(%edi), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movzwl -0x43e(%ebp), %ebx\n"
        "movw %bx, -0x24(%ebp)\n"
        "movzbl -0x43f(%ebp), %ebx\n"
        "movb %bl, -0x25(%ebp)\n"
        "movzbl -0x440(%ebp), %ebx\n"
        "movb %bl, -0x26(%ebp)\n"
        "movzbl -0x441(%ebp), %ebx\n"
        "movb %bl, -0x27(%ebp)\n"
        "movzbl -0x442(%ebp), %ebx\n"
        "movb %bl, -0x28(%ebp)\n"
        "movl -0x448(%ebp), %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf160536_00160639\n"
        "addl $1, -0x45c(%ebp)\n" /* line 1104 */
        "addl $0x2020, %esi\n"
        "addl $0x2020, %edi\n"
        "cmpl $0x10, -0x45c(%ebp)\n"
        "jne .Lf160536_00160591\n"
        /* } scope */
        ".Lf160536_0016062e:\n"
        "addl $0x47c, %esp\n" /* line 1196 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf160536_00160639:\n"
        "testl %esi, %esi\n" /* line 1113 */
        "je .Lf160536_0016062e\n"
        "movl 0x14(%ebp), %eax\n" /* line 1118 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadStringLine\n"
        "movl %eax, %edi\n"
        "movl %eax, 0xc(%esp)\n" /* line 1121 */
        "movl $str_00216058, 8(%esp)\n" /* "%s" */
        "movl $0x2000, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x2018(%esi), %eax\n" /* line 1123 */
        "testl %eax, %eax\n"
        "jne .Lf160536_0016077c\n"
        ".Lf160536_00160674:\n"
        "cld\n" /* line 1158 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl $str_00222630, 8(%esp)\n" /* line 1159 */
        "movl $0x2000, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %ecx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x2018(%esi), %eax\n" /* line 1161 */
        "testl %eax, %eax\n"
        "jne .Lf160536_0016091f\n"
        ".Lf160536_001606b1:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1166 | msg */
        "movl %ebx, (%esp)\n"
        "calll MSG_ReadStringLine\n"
        "movl %eax, %ebx\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf160536_0016082b\n"
        ".Lf160536_001606c7:\n"
        "cld\n" /* line 1186 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl $str_00222630, 8(%esp)\n" /* line 1187 */
        "movl $0x2000, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %ecx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "calll Sys_Milliseconds\n" /* line 1189 */
        "movl %eax, 0x200c(%esi)\n"
        "movzwl -0x43e(%ebp), %ebx\n" /* line 1190 */
        "movw %bx, 0x2008(%esi)\n"
        "movzbl -0x43f(%ebp), %eax\n"
        "movb %al, 0x2007(%esi)\n"
        "movzbl -0x440(%ebp), %ebx\n"
        "movb %bl, 0x2006(%esi)\n"
        "movzbl -0x441(%ebp), %eax\n"
        "movb %al, 0x2005(%esi)\n"
        "movzbl -0x442(%ebp), %ebx\n"
        "movb %bl, 0x2004(%esi)\n"
        "movl -0x448(%ebp), %eax\n"
        "movl %eax, 0x2000(%esi)\n"
        "movl $0, 0x2014(%esi)\n" /* line 1191 */
        "movl 0x2018(%esi), %edi\n" /* line 1192 */
        "testl %edi, %edi\n"
        "je .Lf160536_0016062e\n"
        "movl $1, 0x201c(%esi)\n" /* line 1194 */
        /* } scope */
        "addl $0x47c, %esp\n" /* line 1196 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf160536_0016077c:\n"
        "movl $str_002abb28, (%esp)\n" /* line 1125 */
        "calll Com_Printf\n"
        "movzbl (%edi), %eax\n"
        ".Lf160536_0016078b:\n"
        "testb %al, %al\n" /* line 1127 */
        "je .Lf160536_00160674\n"
        "movl $0, -0x43c(%ebp)\n"
        "leal -0x438(%ebp), %ebx\n" /* info */
        "cmpb $0x5c, %al\n" /* line 1131 */
        "je .Lf160536_00160809\n"
        ".Lf160536_001607a7:\n"
        "xorl %edx, %edx\n" /* line 1132 */
        "jmp .Lf160536_001607ae\n"
        ".Lf160536_001607ab:\n"
        "movzbl (%edi), %eax\n"
        ".Lf160536_001607ae:\n"
        "testb %al, %al\n" /* line 1134 */
        "je .Lf160536_001607c8\n"
        "movb %al, (%edx, %ebx)\n" /* line 1136 */
        "addl $1, %edx\n"
        "cmpl $0x3ff, %edx\n" /* line 1137 */
        "je .Lf160536_001607c8\n"
        "addl $1, %edi\n" /* line 1139 */
        "cmpb $0x5c, (%edi)\n" /* line 1140 */
        "jne .Lf160536_001607ab\n"
        ".Lf160536_001607c8:\n"
        "movb $0, -0x438(%ebp, %edx)\n" /* line 1145 */
        "movl -0x43c(%ebp), %eax\n" /* line 1146 */
        "testl %eax, %eax\n"
        "je .Lf160536_00160819\n"
        "movl %ebx, 4(%esp)\n" /* line 1148 */
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf160536_001607ea:\n"
        "addl $1, -0x43c(%ebp)\n" /* line 1129 */
        "cmpl $2, -0x43c(%ebp)\n"
        "je .Lf160536_00160811\n"
        "movzbl (%edi), %eax\n"
        "testb %al, %al\n"
        "je .Lf160536_00160674\n"
        "cmpb $0x5c, %al\n" /* line 1131 */
        "jne .Lf160536_001607a7\n"
        ".Lf160536_00160809:\n"
        "addl $1, %edi\n" /* line 1132 */
        "movzbl (%edi), %eax\n"
        "jmp .Lf160536_001607a7\n"
        ".Lf160536_00160811:\n"
        "movzbl (%edi), %eax\n"
        "jmp .Lf160536_0016078b\n"
        ".Lf160536_00160819:\n"
        "movl %ebx, 4(%esp)\n" /* line 1152 */
        "movl $str_002abb3c, (%esp)\n" /* "%-24s" */
        "calll Com_Printf\n"
        "jmp .Lf160536_001607ea\n"
        ".Lf160536_0016082b:\n"
        "movl $0, -0x44c(%ebp)\n" /* line 1166 | i */
        "jmp .Lf160536_00160854\n"
        ".Lf160536_00160837:\n"
        "movl 0x14(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadStringLine\n"
        "movl %eax, %ebx\n"
        "addl $1, -0x44c(%ebp)\n" /* i */
        "cmpb $0, (%eax)\n"
        "je .Lf160536_001606c7\n"
        ".Lf160536_00160854:\n"
        "cld\n" /* line 1169 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1170 */
        "movl $str_002a6fb8, 8(%esp)\n" /* "\%s" */
        "movl $0x2000, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %ecx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x2018(%esi), %eax\n" /* line 1172 */
        "testl %eax, %eax\n"
        "je .Lf160536_00160837\n"
        "movl $0, -0x20(%ebp)\n" /* line 1174 | ping */
        "movl $0, -0x1c(%ebp)\n" /* score */
        "leal -0x20(%ebp), %eax\n" /* line 1175 | ping */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* score */
        "movl %eax, 8(%esp)\n"
        "movl $str_002abb6c, 4(%esp)\n" /* "%d %d" */
        "movl %ebx, (%esp)\n"
        "calll sscanf\n"
        "movl $0x20, 4(%esp)\n" /* line 1176 */
        "movl %ebx, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 1177 */
        "je .Lf160536_00160918\n"
        "addl $1, %eax\n" /* line 1178 */
        "movl $0x20, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 1179 */
        "je .Lf160536_00160918\n"
        "addl $1, %eax\n" /* line 1180 */
        ".Lf160536_001608eb:\n"
        "movl %eax, 0x10(%esp)\n" /* line 1183 */
        "movl -0x20(%ebp), %eax\n" /* ping */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* score */
        "movl %eax, 8(%esp)\n"
        "movl -0x44c(%ebp), %ebx\n" /* i */
        "movl %ebx, 4(%esp)\n"
        "movl $str_002abb7c, (%esp)\n" /* "%-2d   %-3d    %-3d   %s
" */
        "calll Com_Printf\n"
        "jmp .Lf160536_00160837\n"
        ".Lf160536_00160918:\n"
        "movl $str_002abb74, %eax\n" /* line 1180 */
        "jmp .Lf160536_001608eb\n"
        ".Lf160536_0016091f:\n"
        "movl $str_002abb44, (%esp)\n" /* line 1163 */
        "calll Com_Printf\n"
        "movl $str_002abb50, (%esp)\n" /* line 1164 */
        "calll Com_Printf\n"
        "jmp .Lf160536_001606b1\n"
    );
}
#endif /* original ASM CL_ServerStatusResponse */

int CL_ServerStatusResponse(netadr_t from, msg_t *msg)
{
    int i;
    byte *serverStatus = NULL;
    const char *line;
    char info[1024];
    int infoField;

    /* find matching server status entry */
    for (i = 0; i < 16; i++)
    {
        byte *entry = (byte *)&cl_serverStatusList[0] + i * 0x2020;
        netadr_t entryAdr;
        memcpy(&entryAdr, entry + 0x2000, sizeof(netadr_t));
        if (NET_CompareAdr(from, entryAdr))
        {
            serverStatus = entry;
            break;
        }
    }

    if (i >= 16)
        return 0;

    if (!serverStatus)
        return 0;

    /* read server info line */
    line = MSG_ReadStringLine(msg);
    Com_sprintf((char *)serverStatus, 0x2000, (const char *)str_00216058, line);

    /* print server info header if callback is set */
    if (*(int *)(serverStatus + 0x2018))
    {
        Com_Printf((const char *)str_002abb28);

        /* parse key-value pairs from info line */
        while (*line)
        {
            for (infoField = 0; infoField < 2; infoField++)
            {
                int j = 0;
                if (*line == '\\')
                    line++;
                while (*line && *line != '\\' && j < 0x3ff)
                {
                    info[j++] = *line++;
                }
                info[j] = '\0';

                if (infoField == 0)
                    Com_Printf((const char *)str_002abb3c, info);
                else
                    Com_Printf((const char *)str_00215bbc, info);
            }
            if (!*line)
                break;
        }
    }

    /* append newline to status string */
    {
        int statusLen = strlen((char *)serverStatus);
        Com_sprintf((char *)serverStatus + statusLen, 0x2000 - statusLen, (const char *)str_00222630);
    }

    /* print player table header if callback is set */
    if (*(int *)(serverStatus + 0x2018))
    {
        Com_Printf((const char *)str_002abb44);
        Com_Printf((const char *)str_002abb50);
    }

    /* read player lines */
    {
        int playerIdx = 0;
        while (1)
        {
            line = MSG_ReadStringLine(msg);
            if (!*line)
                break;

            /* append player line to status string */
            {
                int statusLen = strlen((char *)serverStatus);
                Com_sprintf((char *)serverStatus + statusLen, 0x2000 - statusLen, (const char *)str_002a6fb8, line);
            }

            if (*(int *)(serverStatus + 0x2018))
            {
                int ping = 0, score = 0;
                const char *name;
                sscanf(line, (const char *)str_002abb6c, &score, &ping);
                name = strchr(line, ' ');
                if (name)
                {
                    name = strchr(name + 1, ' ');
                    if (name)
                        name++;
                    else
                        name = (const char *)str_002abb74;
                }
                else
                {
                    name = (const char *)str_002abb74;
                }
                Com_Printf((const char *)str_002abb7c, playerIdx, score, ping, name);
            }

            playerIdx++;
        }
    }

    /* append final newline */
    {
        int statusLen = strlen((char *)serverStatus);
        Com_sprintf((char *)serverStatus + statusLen, 0x2000 - statusLen, (const char *)str_00222630);
    }

    /* update server status metadata */
    *(int *)(serverStatus + 0x200c) = Sys_Milliseconds();
    memcpy(serverStatus + 0x2000, &from, sizeof(netadr_t));
    *(int *)(serverStatus + 0x2014) = 0;

    if (*(int *)(serverStatus + 0x2018))
    {
        *(int *)(serverStatus + 0x201c) = 1;
    }

    return 0;
}

/* line 1328 */
int CL_ResetPlayerMuting(int clientIndex)
{
    s_playerMute[clientIndex] = 0;
    return 0;
}

/* line 1335 */
int CL_MutePlayer(int clientIndex)
{
    s_playerMute[clientIndex] = !s_playerMute[clientIndex];
    if (s_playerMute[clientIndex]) {
        Cbuf_ExecuteText(2, va("muteplayer %i", clientIndex));
    } else {
        Cbuf_ExecuteText(2, va("unmuteplayer %i", clientIndex));
    }
    return 0;
}

/* line 1346 */
Bool CL_IsPlayerMuted(int clientIndex)
{
    return s_playerMute[clientIndex];
}

/* line 1353 */
int CL_ClearMutedList(void)
{
    memset(s_playerMute, 0, 0x40);
    return 0;
}

/* line 622 */
int CL_GlobalServers_f(void)
{
    netadr_t to;
    char command[1024];
    char *buffptr;
    int i;
    int count;

    if (Cmd_Argc() <= 2)
    {
        Com_Printf((const char *)str_002abbb8); /* "usage: globalservers <master# 0-1> <protocol> [keywords]\n" */
        return 0;
    }

    {
        byte *cls = (byte *)imp_cls;
        int numglobal = *(int *)(cls + 0x4540);

        /* saturating increment of requestCount for all existing global servers */
        for (i = 0; i < numglobal; i++)
        {
            byte *server = cls + 0x4544 + i * 0x88;
            byte rc = server[0x19];
            byte rc1 = (byte)(rc + 1);
            if (rc1 == 0)
                server[0x19] = 0xFF;
            else
                server[0x19] = rc1;
        }
    }

    Com_Printf((const char *)str_002abbf4); /* "Requesting servers from the master...\n" */

    /* resolve master server address */
    NET_StringToAdr((const char *)str_002a9298, &to); /* "cod2master.activision.com" */

    {
        byte *cls = (byte *)imp_cls;
        *(int *)(cls + 0x453c) = 1;    /* pingUpdateSource = 1 */
        *(int *)(cls + 0x2a0a48) = 1;  /* waitglobalserverresponse = 1 */
    }

    to.type = 4;            /* NA_IP */
    to.port = (unsigned short)0xe650;  /* 58960 */

    /* build command string */
    sprintf(command, (const char *)str_002abc1c, Cmd_Argv(2)); /* "getservers %s" */

    buffptr = command + strlen(command);

    count = Cmd_Argc();
    if (count > 3)
    {
        /* append extra keyword arguments */
        for (i = 3; i != count; i++)
        {
            buffptr += sprintf(buffptr, (const char *)str_002abc2c, Cmd_Argv(i)); /* " %s" */
        }
    }

    /* check fs_restrict dvar — if restricted, append " demo" */
    if (Dvar_GetBool((const char *)str_00216d6c)) /* "fs_restrict" */
    {
        *(int *)buffptr = 0x6d656420;         /* " dem" */
        *(short *)(buffptr + 4) = 0x6f;       /* "o\0" */
    }

    /* send the request */
    NET_OutOfBandPrint(1, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), command);

    return 0;
}

/* line 518 */
int CL_ServersResponsePacket(netadr_t from, msg_t *msg)
{
    byte *buffptr;
    byte *buffend;
    int numservers;
    byte servers[256][6]; /* ip[4] + port[2] per entry */
    byte ip[4];
    unsigned short port;
    netadr_t adr;
    int i;
    int count;
    byte *cls;
    int low, high, mid;
    int compare;

    Com_PumpMessageLoop();

    Com_Printf((const char *)str_002abc30); /* "CL_ServersResponsePacket\n" */

    cls = (byte *)imp_cls;
    *(int *)(cls + 0x453c) = 0; /* pingUpdateSource = 0 */

    buffptr = msg->data;
    buffend = msg->data + msg->cursize;

    numservers = 0;

    /* scan forward past prefix to find first backslash separator */
    while ((unsigned int)(buffptr + 1) < (unsigned int)buffend)
    {
        if (*buffptr == '\\')
            break;
        buffptr++;
    }

    /* parse server entries from binary packet */
    while ((unsigned int)(buffptr + 1) < (unsigned int)(buffend - 6))
    {
        /* read 4 IP bytes (offset 1..4 from buffptr) */
        ip[0] = buffptr[1];
        ip[1] = buffptr[2];
        ip[2] = buffptr[3];
        ip[3] = buffptr[4];

        /* read 2 port bytes (offset 5..6 from buffptr) and byte-swap for storage */
        {
            unsigned short portVal;
            portVal = ((unsigned short)buffptr[5] << 8) | (unsigned short)buffptr[6];
            /* byte-swap: the asm does rolw $8 to convert to network byte order for netadr_t.port */
            port = (unsigned short)((portVal >> 8) | (portVal << 8));
        }

        buffptr += 7;

        /* store in servers array */
        servers[numservers][0] = ip[0];
        servers[numservers][1] = ip[1];
        servers[numservers][2] = ip[2];
        servers[numservers][3] = ip[3];
        *(unsigned short *)&servers[numservers][4] = port;

        /* verify next entry starts with backslash */
        if (*buffptr != '\\')
            break;

        Com_DPrintf((const char *)str_002abc4c, numservers, ip[0], ip[1], ip[2], ip[3], (int)port);
            /* "server: %d ip: %d.%d.%d.%d:%d\n" */

        numservers++;
        if (numservers == 256)
            break;

        /* check for "EOT" end-of-transmission marker */
        if (buffptr[1] == 0x45 && buffptr[2] == 0x4f && buffptr[3] == 0x54)
            break;

        /* advance scan pointer */
        /* continue to next entry — scan past separator */
        continue;
    }

    /* add parsed servers to global server list */
    cls = (byte *)imp_cls;
    count = *(int *)(cls + 0x4540); /* numglobalservers */

    for (i = 0; i < numservers && count <= 0x4e1f; i++)
    {
        /* extract address from parsed entry */
        ip[0] = servers[i][0];
        ip[1] = servers[i][1];
        ip[2] = servers[i][2];
        ip[3] = servers[i][3];
        port = *(unsigned short *)&servers[i][4];

        /* build netadr_t for this server */
        adr.type = 4; /* NA_IP */
        adr.ip[0] = ip[0];
        adr.ip[1] = ip[1];
        adr.ip[2] = ip[2];
        adr.ip[3] = ip[3];
        adr.port = port;

        /* binary search for duplicate in existing globalServers */
        cls = (byte *)imp_cls;
        high = *(int *)(cls + 0x4540);
        if (high > 0)
        {
            low = 0;
            while (low < high)
            {
                cls = (byte *)imp_cls;
                mid = (low + high) / 2;
                compare = NET_CompareAdrSigned((const int *)&adr, (const int *)(cls + 0x4544 + mid * 0x88));
                if (compare < 0)
                {
                    high = mid;
                }
                else if (compare > 0)
                {
                    low = mid + 1;
                }
                else
                {
                    /* found match — walk back to first matching entry */
                    int j = mid;
                    while (j - 1 >= 0)
                    {
                        if (NET_CompareAdrSigned((const int *)&adr, (const int *)((byte *)imp_cls + 0x4544 + (j - 1) * 0x88)) != 0)
                            break;
                        j--;
                    }
                    /* overwrite all matching entries starting at j */
                    {
                        byte *srvBase;
                        cls = (byte *)imp_cls;
                        srvBase = cls + 0x4540 + j * 0x88;
                        while (1)
                        {
                            serverInfo_t *srv = (serverInfo_t *)(srvBase + 4);
                            srv->adr.type = adr.type;
                            srv->adr.ip[0] = adr.ip[0];
                            srv->adr.ip[1] = adr.ip[1];
                            srv->adr.ip[2] = adr.ip[2];
                            srv->adr.ip[3] = adr.ip[3];
                            srv->adr.port = adr.port;
                            srv->clients = 0;
                            srv->hostName[0] = '\0';
                            srv->mapName[0] = '\0';
                            srv->maxClients = 0;
                            srv->minPing = 0;
                            srv->maxPing = 0;
                            srv->ping = -1;
                            srv->game[0] = '\0';
                            srv->gameType[0] = '\0';
                            srv->netType = 0;
                            srv->allowAnonymous = 0;
                            srv->dirty = 1;
                            srv->requestCount = 0;

                            j++;
                            srvBase += 0x88;
                            if (j >= *(int *)((byte *)imp_cls + 0x4540))
                                break;
                            if (NET_CompareAdrSigned((const int *)&adr, (const int *)(srvBase + 4)) != 0)
                            {
                                cls = (byte *)imp_cls;
                                break;
                            }
                        }
                    }
                    goto next_server;
                }
            }
            cls = (byte *)imp_cls;
        }

        /* no duplicate found — append new server at position count */
        {
            serverInfo_t *srv = (serverInfo_t *)(cls + 0x4544 + count * 0x88);
            srv->adr.type = 4; /* NA_IP */
            srv->adr.ip[0] = ip[0];
            srv->adr.ip[1] = ip[1];
            srv->adr.ip[2] = ip[2];
            srv->adr.ip[3] = ip[3];
            srv->adr.port = port;
            srv->clients = 0;
            srv->hostName[0] = '\0';
            srv->mapName[0] = '\0';
            srv->maxClients = 0;
            srv->minPing = 0;
            srv->maxPing = 0;
            srv->ping = -1;
            srv->game[0] = '\0';
            srv->gameType[0] = '\0';
            srv->netType = 0;
            srv->allowAnonymous = 0;
            srv->dirty = 1;
            srv->requestCount = 0;
            count++;
        }

next_server:
        ;
    }

    /* update numglobalservers and sort */
    *(int *)(cls + 0x4540) = count;
    qsort(cls + 0x4544, count, 0x88, (int (*)(const void *, const void *))CL_CompareAdrSigned);

    Com_Printf((const char *)str_002abc6c, numservers, count);
        /* "%d servers parsed (total %d)\n" */

    return 0;
}

/* line 898 */
int CL_Ping_f(void)
{
    netadr_t to;
    int now;
    byte *pinglist;
    byte *entry;
    byte *endEntry;
    byte *bestEntry;

    if (Cmd_Argc() != 2)
    {
        Com_Printf((const char *)str_002abc8c); /* "usage: ping [server]\n" */
        return 0;
    }

    /* zero out the address */
    memset(&to, 0, sizeof(netadr_t));

    /* resolve server address */
    if (!NET_StringToAdr(Cmd_Argv(1), &to))
        return 0;

    /* CL_GetFreePing — find a free or expired ping slot */
    now = Sys_Milliseconds();
    pinglist = (byte *)imp_cl_pinglist;
    entry = pinglist;
    endEntry = pinglist + 16 * 0x414;

    while (entry != endEntry)
    {
        /* check if port is zero (empty slot) */
        if (*(unsigned short *)(entry + 8) == 0)
            goto found_slot;

        /* check if ping time was received */
        {
            int pingTime = *(int *)(entry + 0x10);
            if (pingTime == 0)
            {
                /* not yet received — check if timed out (> 499ms) */
                int elapsed = now - *(int *)(entry + 0xc);
                if (elapsed > 0x1f3)
                    goto found_slot;
            }
            else if (pingTime > 0x1f3)
            {
                /* ping was received but > 499ms — slot can be reused */
                goto found_slot;
            }
        }

        entry += 0x414;
    }

    /* no free slot found — find oldest entry to reuse */
    {
        byte *scan = pinglist;
        int oldest = (int)0x80000000;
        bestEntry = pinglist;

        while (scan != endEntry)
        {
            int age = now - *(int *)(scan + 0xc);
            if (age > oldest)
            {
                bestEntry = scan;
                oldest = age;
            }
            scan += 0x414;
        }
        entry = bestEntry;
        goto fill_slot;
    }

found_slot:
    *(unsigned short *)(entry + 8) = 0; /* clear port */

fill_slot:
    /* store the address in the ping entry */
    memcpy(entry, &to, sizeof(netadr_t));

    /* record start time */
    *(int *)(entry + 0xc) = Sys_Milliseconds();
    *(int *)(entry + 0x10) = 0; /* no response yet */

    /* update server info */
    {
        netadr_t entryAdr;
        memcpy(&entryAdr, entry, sizeof(netadr_t));
        CL_SetServerInfoByAddress(entryAdr, NULL, 0);
    }

    /* send getinfo request */
    NET_OutOfBandPrint(0, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), (const char *)str_002a9420);
        /* "getinfo xxx" */

    return 0;
}

/* line 313 */
int CL_Connect_f(void)
{
    const char *server;
    byte *clc;
    byte *cls_servername;

    if (Cmd_Argc() != 2)
    {
        Com_Printf((const char *)str_002abca4); /* "usage: connect [server]\n" */
        return 0;
    }

    SND_StopSounds(0);

    /* clear server message */
    clc = *(byte **)imp_clc;
    *(byte *)(clc + 0x28) = 0; /* serverMessage[0] = 0 */

    server = Cmd_Argv(1);

    /* check if local server is running */
    {
        byte *sv_running = *(byte **)imp_com_sv_running;
        if (*(byte *)(sv_running + 8) != 0)
        {
            /* compare server arg with "localhost" (10 chars including null) */
            if (memcmp(server, (const char *)str_002a8ab8, 10) == 0) /* "localhost" */
            {
                /* connecting to localhost while server is running */
                byte *legacyHacks = *(byte **)imp_legacyHacks;
                *(byte *)(legacyHacks + 0xdd) = 1;
            }
        }
    }

    {
        byte *legacyHacks = *(byte **)imp_legacyHacks;
        *(byte *)(legacyHacks + 0x5c) = 0;
        legacyHacks = *(byte **)imp_legacyHacks;
        *(byte *)(legacyHacks + 0x9c) = 0;
    }

    SV_Frame(0);
    CL_Disconnect();
    Con_Close();

    /* copy server name to cls->servername */
    cls_servername = (byte *)imp_cls + 8;
    I_strncpyz((char *)cls_servername, server, 0x100);

    /* resolve server address into clc->serverAddress */
    clc = *(byte **)imp_clc;
    if (!NET_StringToAdr((const char *)cls_servername, (netadr_t *)(clc + 0x14)))
    {
        Com_Printf((const char *)str_002abcc0); /* "Bad server address\n" */
        *(int *)clc = 0; /* state = 0 */
        return 0;
    }

    /* set default port if not specified */
    if (*(unsigned short *)(clc + 0x1c) == 0)
    {
        *(unsigned short *)(clc + 0x1c) = 0x2071; /* 28817 (network byte order) */
    }

    /* print resolved address */
    {
        unsigned short netPort = *(unsigned short *)(clc + 0x1c);
        /* byte swap port for display */
        short displayPort = (short)((netPort >> 8) | (netPort << 8));
        Com_Printf((const char *)str_002a92e0, /* "%s resolved to %i.%i.%i.%i:%i\n" */
            cls_servername,
            (int)*(byte *)(clc + 0x18),
            (int)*(byte *)(clc + 0x19),
            (int)*(byte *)(clc + 0x1a),
            (int)*(byte *)(clc + 0x1b),
            (int)displayPort);
    }

    /* CD key validation (unless connecting to local address) */
    if (!NET_IsLocalAddress(*(int *)(clc + 0x14), *(int *)(clc + 0x18), *(int *)(clc + 0x1c)))
    {
        /* CRC16 CD key checksum */
        unsigned int crc = 0;
        byte *cdkey = (byte *)imp_cl_cdkey;
        byte *cdkeyEnd = cdkey + 16;
        char chs[8];

        while (cdkey != cdkeyEnd)
        {
            int ch = (signed char)*cdkey;
            int j;
            crc ^= (unsigned int)ch;
            for (j = 8; j != 0; j--)
            {
                if (crc & 1)
                {
                    crc >>= 1;
                    crc ^= 0xa001;
                }
                else
                {
                    crc >>= 1;
                }
            }
            cdkey++;
        }

        sprintf(chs, (const char *)str_00228f18, crc); /* "%04x" */

        if (I_strnicmp(chs, (const char *)imp_cl_cdkeychecksum, 4) != 0)
        {
            Com_Error(1, (const char *)str_002a9280); /* "EXE_ERR_INVALID_CD_KEY" */
            return 0;
        }
    }

    /* set connection state */
    {
        byte *clcPtr;
        clc = *(byte **)imp_clc;

        if (NET_IsLocalAddress(*(int *)(clc + 0x14), *(int *)(clc + 0x18), *(int *)(clc + 0x1c)))
        {
            *(int *)clc = 4; /* CA_CHALLENGING (local) */
        }
        else
        {
            clcPtr = *(byte **)imp_clc;
            *(int *)clcPtr = 3; /* CA_CONNECTING */
            clc = clcPtr;
        }
    }

    /* initialize client state */
    {
        byte *cl = *(byte **)imp_cl;
        *(int *)(cl + 4) = 0;
        *(byte *)(cl + 8) = 0;
    }

    /* set connect time and packet count */
    *(int *)(clc + 0x20) = (int)0xfffe7961; /* connectTime = large negative (forces immediate connect) */
    *(int *)(clc + 0x24) = 0;              /* connectPacketCount = 0 */

    /* set qport */
    *(int *)(clc + 0x04) = *(int *)imp_g_qport; /* clc->qport */

    UI_CloseAll();
    SCR_UpdateScreen();

    return 0;
}

/* line 980 */
int CL_ServerStatus(char *serverAddress, char *serverStatusString, int maxLen)
{
    netadr_t to;
    byte *serverStatus;
    int i;

    /* if serverAddress is NULL, reset all server status entries */
    if (serverAddress == NULL)
    {
        byte *entry = (byte *)&cl_serverStatusList[0];
        byte *end = entry + 16 * 0x2020;
        while (entry != end)
        {
            *(unsigned short *)(entry + 0x2008) = 0; /* clear port */
            *(int *)(entry + 0x201c) = 1;            /* mark as retrieved */
            entry += 0x2020;
        }
        return 0;
    }

    /* resolve server address */
    if (!NET_StringToAdr(serverAddress, &to))
        return 0;

    /* CL_GetServerStatusList — find matching or free entry */
    /* first, search for existing entry with matching address */
    serverStatus = NULL;
    for (i = 0; i < 16; i++)
    {
        byte *entry = (byte *)&cl_serverStatusList[0] + i * 0x2020;
        netadr_t entryAdr;
        memcpy(&entryAdr, entry + 0x2000, sizeof(netadr_t));
        if (NET_CompareAdr(to, entryAdr))
        {
            serverStatus = entry;
            goto found_entry;
        }
    }

    /* no match found — search for a free (retrieved) entry */
    {
        int idx;
        byte *entry = (byte *)&cl_serverStatusList[0];
        for (idx = 0; idx < 16; idx++)
        {
            if (*(int *)(entry + 0x201c) != 0) /* retrieved? */
            {
                serverStatus = entry;
                goto found_entry;
            }
            entry += 0x2020;
        }
    }

    /* no free entry — find oldest entry to reuse */
    {
        int bestIdx = 0;
        int oldestTime = *(int *)((byte *)&cl_serverStatusList[0] + 0x2010);
        int j;

        for (j = 1; j <= 15; j++)
        {
            int entryTime = *(int *)((byte *)&cl_serverStatusList[0] + j * 0x2020 + 0x2010);
            if (oldestTime > entryTime)
            {
                bestIdx = j;
                oldestTime = *(int *)((byte *)&cl_serverStatusList[0] + bestIdx * 0x2020 + 0x2010);
            }
        }

        serverStatus = (byte *)&cl_serverStatusList[0] + bestIdx * 0x2020;
    }

found_entry:

    /* handle request based on serverStatusString */
    if (serverStatusString == NULL)
    {
        /* no output string requested — just mark entry as retrieved */
        *(int *)(serverStatus + 0x201c) = 1;
        return 0;
    }

    /* check if the entry address matches our target */
    {
        netadr_t entryAdr;
        memcpy(&entryAdr, serverStatus + 0x2000, sizeof(netadr_t));
        if (NET_CompareAdr(to, entryAdr))
        {
            /* address matches — check if pending */
            if (*(int *)(serverStatus + 0x2014) == 0)
            {
                /* not pending — data is ready, copy it out */
                I_strncpyz(serverStatusString, (char *)serverStatus, maxLen);
                *(int *)(serverStatus + 0x201c) = 1; /* mark as retrieved */
                *(int *)(serverStatus + 0x2010) = 0; /* clear start time */
                return 1;
            }

            /* pending — check if resend timer expired */
            {
                int startTime = *(int *)(serverStatus + 0x2010);
                int now = Sys_Milliseconds();
                byte *resendDvar = *(byte **)imp_cl_serverStatusResendTime;
                int resendTime = *(int *)(resendDvar + 8);
                if (startTime >= now - resendTime)
                    return 0; /* still waiting */
            }

            /* resend timer expired — re-request */
            *(int *)(serverStatus + 0x2018) = 0; /* print = 0 */
            *(int *)(serverStatus + 0x2014) = 1; /* pending = 1 */
            *(int *)(serverStatus + 0x201c) = 0; /* retrieved = 0 */
            *(int *)(serverStatus + 0x200c) = 0; /* time = 0 */
            *(int *)(serverStatus + 0x2010) = Sys_Milliseconds();

            /* send getstatus */
            NET_OutOfBandPrint(0, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), (const char *)str_002ab528);
            return 0;
        }
    }

    /* address doesn't match — check if entry has been retrieved */
    if (*(int *)(serverStatus + 0x201c) == 0)
        return 0;

    /* re-initialize entry for new address */
    memcpy(serverStatus + 0x2000, &to, sizeof(netadr_t));
    *(int *)(serverStatus + 0x2018) = 0; /* print = 0 */
    *(int *)(serverStatus + 0x2014) = 1; /* pending = 1 */
    *(int *)(serverStatus + 0x201c) = 0; /* retrieved = 0 */
    *(int *)(serverStatus + 0x2010) = Sys_Milliseconds();
    *(int *)(serverStatus + 0x200c) = 0; /* time = 0 */

    /* send getstatus */
    NET_OutOfBandPrint(0, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), (const char *)str_002ab528);
    return 0;
}

/* line 1053 */
int CL_ServerStatus_f(void)
{
    netadr_t to;
    const char *serverAddr;
    byte *statusEntry;
    int i;

    Com_Memset(&to, 0, sizeof(netadr_t));

    if (Cmd_Argc() == 2)
    {
        /* explicit server address argument */
        serverAddr = Cmd_Argv(1);
    }
    else
    {
        /* use current connection */
        byte *clc = *(byte **)imp_clc;
        if (*(int *)clc != 8) /* state != CA_ACTIVE */
            goto not_connected;
        if (*(int *)(clc + 0x407a0) != 0)
            goto not_connected;

        serverAddr = (const char *)((byte *)imp_cls + 8); /* cls->servername */
    }

    /* resolve address */
    if (!NET_StringToAdr(serverAddr, &to))
        return 0;

    /* send getstatus request */
    NET_OutOfBandPrint(0, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), (const char *)str_002ab528);
        /* "getstatus" */

    /* CL_GetServerStatusList — find or allocate entry for this address */
    /* search for matching address */
    {
        byte *entry = (byte *)&cl_serverStatusList[0];
        for (i = 0; i < 16; i++)
        {
            netadr_t entryAdr;
            memcpy(&entryAdr, entry + 0x2000, sizeof(netadr_t));
            if (NET_CompareAdr(to, entryAdr))
            {
                statusEntry = entry;
                goto store_entry;
            }
            entry += 0x2020;
        }
    }

    /* no match — search for free (retrieved) entry */
    {
        int idx;
        byte *entry = (byte *)&cl_serverStatusList[0];
        for (idx = 0; idx < 16; idx++)
        {
            if (*(int *)(entry + 0x201c) != 0)
            {
                statusEntry = entry;
                goto store_entry;
            }
            entry += 0x2020;
        }
    }

    /* no free entry — find oldest to reuse */
    {
        int bestIdx = 0;
        int oldestTime = *(int *)((byte *)&cl_serverStatusList[0] + 0x2010);
        int j;

        for (j = 1; j <= 15; j++)
        {
            int entryTime = *(int *)((byte *)&cl_serverStatusList[0] + j * 0x2020 + 0x2010);
            if (oldestTime > entryTime)
            {
                bestIdx = j;
                oldestTime = *(int *)((byte *)&cl_serverStatusList[0] + bestIdx * 0x2020 + 0x2010);
            }
        }

        statusEntry = (byte *)&cl_serverStatusList[0] + bestIdx * 0x2020;
    }

store_entry:
    /* store address and mark for printing */
    memcpy(statusEntry + 0x2000, &to, sizeof(netadr_t));
    *(int *)(statusEntry + 0x2018) = 1; /* print = 1 */
    *(int *)(statusEntry + 0x2014) = 1; /* pending = 1 */

    return 0;

not_connected:
    Com_Printf((const char *)str_002a8b24); /* "Not connected to a server.\n" */
    Com_Printf((const char *)str_002abcd4); /* "Usage: serverstatus [server]\n" */
    return 0;
}
