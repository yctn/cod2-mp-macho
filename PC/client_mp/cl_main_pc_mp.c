/* ASM dump from: cl_main_pc_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_main_pc_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

/* Per-server status request entry (matches Q3 serverStatus_t for cl_serverStatusList).
 * NOTE: The common_types.h serverStatus_t is the UI server-browser struct, NOT this one. */
typedef struct serverStatusRequest_s {
    char string[0x2000];        /* 0x0000: info string buffer */
    netadr_t address;           /* 0x2000: server address */
    int time;                   /* 0x200C: last response time */
    int startTime;              /* 0x2010: request start time */
    qboolean pending;           /* 0x2014: request pending */
    qboolean print;             /* 0x2018: print to console */
    qboolean retrieved;         /* 0x201C: result retrieved */
} serverStatusRequest_t;

extern serverStatusRequest_t cl_serverStatusList[16]; /* 0x0 */
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
    prot = atoi(Info_ValueForKey(infoString, (const char *)"protocol"));

    protoStr = Dvar_GetString((const char *)"debug_protocol");
    if (*protoStr)
        expectedProt = atoi(protoStr);
    else
        expectedProt = 0x76;

    if (prot != expectedProt)
    {
        Com_DPrintf((const char *)"Different protocol info packet: %s\n", infoString);
        return 0;
    }

    /* search pinglist for matching address */
    pinglist = (byte *)imp_cl_pinglist;
    for (i = 0; i < 16; i++)
    {
        ping_t *ping = (ping_t *)(pinglist + i * sizeof(ping_t));
        /* check port != 0 */
        if (ping->adr.port == 0)
            continue;
        /* check time == 0 (not yet received) */
        if (ping->time != 0)
            continue;
        /* compare addresses */
        {
            if (!NET_CompareAdr(from, ping->adr))
                continue;
        }

        /* found matching ping entry */
        {
            int pingTime = time - ping->start + 1;
            ping->time = pingTime;
        }

        Com_DPrintf((const char *)"ping time %dms from %s\n", ping->time, NET_AdrToString(from));

        /* copy infoString into ping info buffer */
        I_strncpyz(ping->info, infoString, sizeof(ping->info));

        /* set nettype */
        {
            int nettype = (from.type >= 3 && from.type <= 4) ? 1 : 0;
            Info_SetValueForKey(ping->info, (const char *)"nettype", va((const char *)"%d", nettype));
        }

        CL_SetServerInfoByAddress(from, infoString, ping->time);
        return 0;
    }

    /* no matching ping entry found */
    cls = (clientStatic_t *)imp_cls;

    /* if waiting for global server response, return */
    if (cls->waitglobalserverresponse)
        return 0;

    /* find empty slot in localServers */
    for (i = 0; i < 128; i++)
    {
        serverInfo_t *server = &cls->localServers[i];
        /* check if port is non-zero */
        if (server->adr.port != 0)
        {
            /* slot occupied, compare address */
            if (NET_CompareAdr(from, server->adr))
                return 0;
            continue;
        }

        /* found empty slot */
        {
            cls->numlocalservers = i + 1;

            server->adr = from;
            server->dirty = 0;
            server->hostName[0] = '\0';
            server->mapName[0] = '\0';
            server->game[0] = '\0';
            server->minPing = 0;
            server->maxPing = 0;
            server->ping = -1;
            server->gameType[0] = '\0';
            server->requestCount = 0; /* was: *(byte *)(base + 0x1b4) */
            server->netType = (byte)from.type;
            server->clients = 0; /* was: *(byte *)(base + 0x140 + 0xc) */

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

            Com_Printf((const char *)"%s: %s", NET_AdrToString(from), info);
            return 0;
        }
    }

    /* all 128 slots full */
    Com_DPrintf((const char *)"MAX_OTHER_SERVERS hit, dropping infoResponse\n");
    return 0;
}

/* line 390 — CD key validation bypassed for decompilation */
qboolean CL_CDKeyValidate(const char *key, const char *checksum)
{
    (void)key;
    (void)checksum;
    return 1;
}

/* line 432 */
int CL_SortGlobalServers(void)
{
    clientStatic_t *cls = (clientStatic_t *)imp_cls;
    int count = cls->numglobalservers;
    qsort(cls->globalServers, count, sizeof(serverInfo_t), (int (*)(const void *, const void *))CL_CompareAdrSigned);
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
        Com_Printf((const char *)"USAGE: rcon <command> <options...>\n");
        return 0;
    }

    cmd = Cmd_Argv(1);

    /* "login" subcommand */
    if (I_stricmp(cmd, (const char *)"login") == 0)
    {
        if (Cmd_Argc() != 3)
        {
            Com_Printf((const char *)"USAGE: rcon login <password>\n");
            return 0;
        }
        {
            const char *pass = Cmd_Argv(2);
            int passLen = strlen(pass);
            if (passLen > 0x17)
            {
                Com_Printf((const char *)"rcon password must be %i characters or less\n", 0x18);
                return 0;
            }
            memcpy(&rconGlob, pass, passLen + 1);
        }
        return 0;
    }

    /* "logout" subcommand */
    if (I_stricmp(cmd, (const char *)"logout") == 0)
    {
        if (!*(byte *)&rconGlob)
        {
            Com_Printf((const char *)"Not logged in\n");
            return 0;
        }
        *(byte *)&rconGlob = 0;
        return 0;
    }

    /* "address" subcommand */
    if (I_stricmp(cmd, (const char *)"host") == 0)
    {
        if (Cmd_Argc() != 3)
        {
            Com_Printf((const char *)"USAGE: rcon host <address>\n");
            return 0;
        }
        if (!NET_StringToAdr(Cmd_Argv(2), (netadr_t *)((char *)&rconGlob + 24)))
        {
            Com_Printf((const char *)"bad host address\n");
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
        Com_Printf((const char *)"You need to log in with 'rcon login <password>' before using rcon.\n");
        return 0;
    }

    /* build message with 0xFF 0xFF 0xFF 0xFF header */
    message[0] = (char)0xff;
    message[1] = (char)0xff;
    message[2] = (char)0xff;
    message[3] = (char)0xff;
    message[4] = '\0';

    offset = Com_AddToString((const char *)"rcon ", message, 0x400, 4, 0);
    offset = Com_AddToString((char *)&rconGlob, message, 0x400, offset, 0);

    for (i = 1; i < Cmd_Argc(); i++)
    {
        offset = Com_AddToString((const char *)" ", message, 0x400, offset, 0);
        offset = Com_AddToString(Cmd_Argv(i), message, 0x400, offset, 1);
    }

    if (offset == 0x400)
    {
        Com_Printf((const char *)"rcon commands are limited to %i characters\n", 0x3ff);
        return 0;
    }

    message[offset] = '\0';

    /* determine send address */
    {
        clientConnection_t *clcLocal = *(clientConnection_t **)imp_clc;
        if (clcLocal->state > 4)
        {
            /* use server address from connection */
            memcpy(&sendAdr, &clcLocal->netchan.remoteAddress, sizeof(netadr_t));
        }
        else
        {
            int addrType = *(int *)((char *)&rconGlob + 24);
            if (addrType == 1)
            {
                Com_Printf((const char *)"Can't determine rcon target.  You can fix this by either:\n");
                Com_Printf((const char *)"1) Joining the server as a player.\n");
                Com_Printf((const char *)"2) Setting the host server with 'rcon host <address>'.\n");
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

int CL_ServerStatusResponse(netadr_t from, msg_t *msg)
{
    int i;
    serverStatusRequest_t *serverStatus = NULL;
    const char *line;
    char info[1024];
    int infoField;

    /* find matching server status entry */
    for (i = 0; i < 16; i++)
    {
        if (NET_CompareAdr(from, cl_serverStatusList[i].address))
        {
            serverStatus = &cl_serverStatusList[i];
            break;
        }
    }

    if (i >= 16)
        return 0;

    if (!serverStatus)
        return 0;

    /* read server info line */
    line = MSG_ReadStringLine(msg);
    Com_sprintf(serverStatus->string, 0x2000, (const char *)"%s", line);

    /* print server info header if callback is set */
    if (serverStatus->print)
    {
        Com_Printf((const char *)"Server settings:\n");

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
                    Com_Printf((const char *)"%-24s", info);
                else
                    Com_Printf((const char *)"%s\n", info);
            }
            if (!*line)
                break;
        }
    }

    /* append newline to status string */
    {
        int statusLen = strlen(serverStatus->string);
        Com_sprintf(serverStatus->string + statusLen, 0x2000 - statusLen, (const char *)"\\");
    }

    /* print player table header if callback is set */
    if (serverStatus->print)
    {
        Com_Printf((const char *)"\nPlayers:\n");
        Com_Printf((const char *)"num: score: ping: name:\n");
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
                int statusLen = strlen(serverStatus->string);
                Com_sprintf(serverStatus->string + statusLen, 0x2000 - statusLen, (const char *)"\\%s", line);
            }

            if (serverStatus->print)
            {
                int ping = 0, score = 0;
                const char *name;
                sscanf(line, (const char *)"%d %d", &score, &ping);
                name = strchr(line, ' ');
                if (name)
                {
                    name = strchr(name + 1, ' ');
                    if (name)
                        name++;
                    else
                        name = (const char *)"unknown";
                }
                else
                {
                    name = (const char *)"unknown";
                }
                Com_Printf((const char *)"%-2d   %-3d    %-3d   %s\n", playerIdx, score, ping, name);
            }

            playerIdx++;
        }
    }

    /* append final newline */
    {
        int statusLen = strlen(serverStatus->string);
        Com_sprintf(serverStatus->string + statusLen, 0x2000 - statusLen, (const char *)"\\");
    }

    /* update server status metadata */
    serverStatus->time = Sys_Milliseconds();
    serverStatus->address = from;
    serverStatus->pending = 0;

    if (serverStatus->print)
    {
        serverStatus->retrieved = 1;
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
        Com_Printf((const char *)"usage: globalservers <master# 0-1> <protocol> [keywords]\n"); /* "usage: globalservers <master# 0-1> <protocol> [keywords]\n" */
        return 0;
    }

    {
        clientStatic_t *cls = (clientStatic_t *)imp_cls;
        int numglobal = cls->numglobalservers;

        /* saturating increment of requestCount for all existing global servers */
        for (i = 0; i < numglobal; i++)
        {
            byte rc = cls->globalServers[i].requestCount;
            byte rc1 = (byte)(rc + 1);
            if (rc1 == 0)
                cls->globalServers[i].requestCount = 0xFF;
            else
                cls->globalServers[i].requestCount = rc1;
        }
    }

    Com_Printf((const char *)"Requesting servers from the master...\n"); /* "Requesting servers from the master...\n" */

    /* resolve master server address */
    NET_StringToAdr((const char *)"cod2master.activision.com", &to); /* "cod2master.activision.com" */

    {
        clientStatic_t *cls = (clientStatic_t *)imp_cls;
        cls->pingUpdateSource = 1;
        cls->waitglobalserverresponse = 1;
    }

    to.type = 4;            /* NA_IP */
    to.port = (unsigned short)0xe650;  /* 58960 */

    /* build command string */
    sprintf(command, (const char *)"getservers %s", Cmd_Argv(2)); /* "getservers %s" */

    buffptr = command + strlen(command);

    count = Cmd_Argc();
    if (count > 3)
    {
        /* append extra keyword arguments */
        for (i = 3; i != count; i++)
        {
            buffptr += sprintf(buffptr, (const char *)" %s", Cmd_Argv(i)); /* " %s" */
        }
    }

    /* check fs_restrict dvar — if restricted, append " demo" */
    if (Dvar_GetBool((const char *)"fs_restrict")) /* "fs_restrict" */
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

    Com_Printf((const char *)"CL_ServersResponsePacket\n"); /* "CL_ServersResponsePacket\n" */

    cls = (byte *)imp_cls;
    ((clientStatic_t *)cls)->pingUpdateSource = 0;

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

        Com_DPrintf((const char *)"server: %d ip: %d.%d.%d.%d:%d\n", numservers, ip[0], ip[1], ip[2], ip[3], (int)port);
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
    count = ((clientStatic_t *)cls)->numglobalservers;

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
        high = ((clientStatic_t *)cls)->numglobalservers;
        if (high > 0)
        {
            low = 0;
            while (low < high)
            {
                cls = (byte *)imp_cls;
                mid = (low + high) / 2;
                compare = NET_CompareAdrSigned((const int *)&adr, (const int *)&((clientStatic_t *)cls)->globalServers[mid]);
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
                        if (NET_CompareAdrSigned((const int *)&adr, (const int *)&((clientStatic_t *)imp_cls)->globalServers[j - 1]) != 0)
                            break;
                        j--;
                    }
                    /* overwrite all matching entries starting at j */
                    {
                        clientStatic_t *clsStatic;
                        cls = (byte *)imp_cls;
                        clsStatic = (clientStatic_t *)cls;
                        while (1)
                        {
                            serverInfo_t *srv = &clsStatic->globalServers[j];
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
                            if (j >= ((clientStatic_t *)imp_cls)->numglobalservers)
                                break;
                            if (NET_CompareAdrSigned((const int *)&adr, (const int *)&clsStatic->globalServers[j]) != 0)
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
            serverInfo_t *srv = &((clientStatic_t *)cls)->globalServers[count];
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
    ((clientStatic_t *)cls)->numglobalservers = count;
    qsort(((clientStatic_t *)cls)->globalServers, count, sizeof(serverInfo_t), (int (*)(const void *, const void *))CL_CompareAdrSigned);

    Com_Printf((const char *)"%d servers parsed (total %d)\n", numservers, count);
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
        Com_Printf((const char *)"usage: ping [server]\n"); /* "usage: ping [server]\n" */
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
    endEntry = pinglist + 16 * sizeof(ping_t);

    while (entry != endEntry)
    {
        ping_t *ping = (ping_t *)entry;
        /* check if port is zero (empty slot) */
        if (ping->adr.port == 0)
            goto found_slot;

        /* check if ping time was received */
        {
            if (ping->time == 0)
            {
                /* not yet received — check if timed out (> 499ms) */
                int elapsed = now - ping->start;
                if (elapsed > 0x1f3)
                    goto found_slot;
            }
            else if (ping->time > 0x1f3)
            {
                /* ping was received but > 499ms — slot can be reused */
                goto found_slot;
            }
        }

        entry += sizeof(ping_t);
    }

    /* no free slot found — find oldest entry to reuse */
    {
        byte *scan = pinglist;
        int oldest = (int)0x80000000;
        bestEntry = pinglist;

        while (scan != endEntry)
        {
            int age = now - ((ping_t *)scan)->start;
            if (age > oldest)
            {
                bestEntry = scan;
                oldest = age;
            }
            scan += sizeof(ping_t);
        }
        entry = bestEntry;
        goto fill_slot;
    }

found_slot:
    ((ping_t *)entry)->adr.port = 0; /* clear port */

fill_slot:
    /* store the address in the ping entry */
    ((ping_t *)entry)->adr = to;

    /* record start time */
    ((ping_t *)entry)->start = Sys_Milliseconds();
    ((ping_t *)entry)->time = 0; /* no response yet */

    /* update server info */
    {
        CL_SetServerInfoByAddress(((ping_t *)entry)->adr, NULL, 0);
    }

    /* send getinfo request */
    NET_OutOfBandPrint(0, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), (const char *)"getinfo xxx");
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
        Com_Printf((const char *)"usage: connect [server]\n"); /* "usage: connect [server]\n" */
        return 0;
    }

    SND_StopSounds(0);

    /* clear server message */
    clc = *(byte **)imp_clc;
    ((clientConnection_t *)clc)->serverMessage[0] = 0;

    server = Cmd_Argv(1);

    /* check if local server is running */
    {
        byte *sv_running = *(byte **)imp_com_sv_running;
        if (*(byte *)(sv_running + 8) != 0)
        {
            /* compare server arg with "localhost" (10 chars including null) */
            if (memcmp(server, (const char *)"localhost", 10) == 0) /* "localhost" */
            {
                /* connecting to localhost while server is running */
                LegacyHacks *legacyHacks = *(LegacyHacks **)imp_legacyHacks;
                legacyHacks->sv_killserver = 1; /* localConnect flag */
            }
        }
    }

    {
        LegacyHacks *legacyHacks = *(LegacyHacks **)imp_legacyHacks;
        legacyHacks->cl_serverloadmap[0] = '\0';
        legacyHacks = *(LegacyHacks **)imp_legacyHacks;
        legacyHacks->cl_serverloadgametype[0] = '\0';
    }

    SV_Frame(0);
    CL_Disconnect();
    Con_Close();

    /* copy server name to cls->servername */
    cls_servername = (byte *)((clientStatic_t *)imp_cls)->servername;
    I_strncpyz((char *)cls_servername, server, sizeof(((clientStatic_t *)0)->servername));

    /* resolve server address into clc->serverAddress */
    clc = *(byte **)imp_clc;
    {
        clientConnection_t *clcConn = (clientConnection_t *)clc;
        if (!NET_StringToAdr((const char *)cls_servername, &clcConn->serverAddress))
        {
            Com_Printf((const char *)"Bad server address\n"); /* "Bad server address\n" */
            clcConn->state = 0; /* state = 0 */
            return 0;
        }

        /* set default port if not specified */
        if (clcConn->serverAddress.port == 0)
        {
            clcConn->serverAddress.port = 0x2071; /* 28817 (network byte order) */
        }

        /* print resolved address */
        {
            unsigned short netPort = clcConn->serverAddress.port;
            /* byte swap port for display */
            short displayPort = (short)((netPort >> 8) | (netPort << 8));
            Com_Printf((const char *)"%s resolved to %i.%i.%i.%i:%i\n", /* "%s resolved to %i.%i.%i.%i:%i\n" */
                cls_servername,
                (int)clcConn->serverAddress.ip[0],
                (int)clcConn->serverAddress.ip[1],
                (int)clcConn->serverAddress.ip[2],
                (int)clcConn->serverAddress.ip[3],
                (int)displayPort);
        }
    }

    /* CD key validation (unless connecting to local address) */
    if (!NET_IsLocalAddress(*(int *)&((clientConnection_t *)clc)->serverAddress, *(int *)((byte *)&((clientConnection_t *)clc)->serverAddress + 4), *(int *)((byte *)&((clientConnection_t *)clc)->serverAddress + 8)))
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

        sprintf(chs, (const char *)"%04x", crc); /* "%04x" */

        if (I_strnicmp(chs, (const char *)imp_cl_cdkeychecksum, 4) != 0)
        {
            Com_Error(1, (const char *)"EXE_ERR_INVALID_CD_KEY"); /* "EXE_ERR_INVALID_CD_KEY" */
            return 0;
        }
    }

    /* set connection state */
    {
        clientConnection_t *clcConn;
        clc = *(byte **)imp_clc;
        clcConn = (clientConnection_t *)clc;

        if (NET_IsLocalAddress(*(int *)&clcConn->serverAddress, *(int *)((byte *)&clcConn->serverAddress + 4), *(int *)((byte *)&clcConn->serverAddress + 8)))
        {
            clcConn->state = 4; /* CA_CHALLENGING (local) */
        }
        else
        {
            clcConn = *(clientConnection_t **)imp_clc;
            clcConn->state = 3; /* CA_CONNECTING */
            clc = (byte *)clcConn;
        }
    }

    /* initialize client state */
    {
        clientActive_t *clActive = *(clientActive_t **)imp_cl;
        clActive->keyCatchers = 0;
        clActive->displayHUDWithKeycatchUI = 0;
    }

    /* set connect time and packet count */
    {
        clientConnection_t *clcConn = (clientConnection_t *)clc;
        clcConn->connectTime = (int)0xfffe7961; /* connectTime = large negative (forces immediate connect) */
        clcConn->connectPacketCount = 0;

        /* set qport */
        clcConn->qport = *(int *)imp_g_qport;
    }

    UI_CloseAll();
    SCR_UpdateScreen();

    return 0;
}

/* line 980 */
int CL_ServerStatus(char *serverAddress, char *serverStatusString, int maxLen)
{
    netadr_t to;
    serverStatusRequest_t *serverStatus;
    int i;

    /* if serverAddress is NULL, reset all server status entries */
    if (serverAddress == NULL)
    {
        for (i = 0; i < 16; i++)
        {
            cl_serverStatusList[i].address.port = 0;
            cl_serverStatusList[i].retrieved = 1;
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
        if (NET_CompareAdr(to, cl_serverStatusList[i].address))
        {
            serverStatus = &cl_serverStatusList[i];
            goto found_entry;
        }
    }

    /* no match found — search for a free (retrieved) entry */
    {
        int idx;
        for (idx = 0; idx < 16; idx++)
        {
            if (cl_serverStatusList[idx].retrieved != 0)
            {
                serverStatus = &cl_serverStatusList[idx];
                goto found_entry;
            }
        }
    }

    /* no free entry — find oldest entry to reuse */
    {
        int bestIdx = 0;
        int oldestTime = cl_serverStatusList[0].startTime;
        int j;

        for (j = 1; j <= 15; j++)
        {
            int entryTime = cl_serverStatusList[j].startTime;
            if (oldestTime > entryTime)
            {
                bestIdx = j;
                oldestTime = cl_serverStatusList[bestIdx].startTime;
            }
        }

        serverStatus = &cl_serverStatusList[bestIdx];
    }

found_entry:

    /* handle request based on serverStatusString */
    if (serverStatusString == NULL)
    {
        /* no output string requested — just mark entry as retrieved */
        serverStatus->retrieved = 1;
        return 0;
    }

    /* check if the entry address matches our target */
    {
        if (NET_CompareAdr(to, serverStatus->address))
        {
            /* address matches — check if pending */
            if (serverStatus->pending == 0)
            {
                /* not pending — data is ready, copy it out */
                I_strncpyz(serverStatusString, serverStatus->string, maxLen);
                serverStatus->retrieved = 1;
                serverStatus->startTime = 0;
                return 1;
            }

            /* pending — check if resend timer expired */
            {
                int startTime = serverStatus->startTime;
                int now = Sys_Milliseconds();
                const dvar_t *resendDvar = *(const dvar_t **)imp_cl_serverStatusResendTime;
                int resendTime = resendDvar->current.integer;
                if (startTime >= now - resendTime)
                    return 0; /* still waiting */
            }

            /* resend timer expired — re-request */
            serverStatus->print = 0;
            serverStatus->pending = 1;
            serverStatus->retrieved = 0;
            serverStatus->time = 0;
            serverStatus->startTime = Sys_Milliseconds();

            /* send getstatus */
            NET_OutOfBandPrint(0, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), (const char *)"getstatus");
            return 0;
        }
    }

    /* address doesn't match — check if entry has been retrieved */
    if (serverStatus->retrieved == 0)
        return 0;

    /* re-initialize entry for new address */
    serverStatus->address = to;
    serverStatus->print = 0;
    serverStatus->pending = 1;
    serverStatus->retrieved = 0;
    serverStatus->startTime = Sys_Milliseconds();
    serverStatus->time = 0;

    /* send getstatus */
    NET_OutOfBandPrint(0, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), (const char *)"getstatus");
    return 0;
}

/* line 1053 */
int CL_ServerStatus_f(void)
{
    netadr_t to;
    const char *serverAddr;
    serverStatusRequest_t *statusEntry;
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
        clientConnection_t *clcConn = *(clientConnection_t **)imp_clc;
        if (clcConn->state != 8) /* state != CA_ACTIVE */
            goto not_connected;
        if (clcConn->demoplaying != 0)
            goto not_connected;

        serverAddr = ((clientStatic_t *)imp_cls)->servername;
    }

    /* resolve address */
    if (!NET_StringToAdr(serverAddr, &to))
        return 0;

    /* send getstatus request */
    NET_OutOfBandPrint(0, to.type, *(int *)((byte *)&to + 4), *(int *)((byte *)&to + 8), (const char *)"getstatus");
        /* "getstatus" */

    /* CL_GetServerStatusList — find or allocate entry for this address */
    /* search for matching address */
    {
        for (i = 0; i < 16; i++)
        {
            if (NET_CompareAdr(to, cl_serverStatusList[i].address))
            {
                statusEntry = &cl_serverStatusList[i];
                goto store_entry;
            }
        }
    }

    /* no match — search for free (retrieved) entry */
    {
        int idx;
        for (idx = 0; idx < 16; idx++)
        {
            if (cl_serverStatusList[idx].retrieved != 0)
            {
                statusEntry = &cl_serverStatusList[idx];
                goto store_entry;
            }
        }
    }

    /* no free entry — find oldest to reuse */
    {
        int bestIdx = 0;
        int oldestTime = cl_serverStatusList[0].startTime;
        int j;

        for (j = 1; j <= 15; j++)
        {
            int entryTime = cl_serverStatusList[j].startTime;
            if (oldestTime > entryTime)
            {
                bestIdx = j;
                oldestTime = cl_serverStatusList[bestIdx].startTime;
            }
        }

        statusEntry = &cl_serverStatusList[bestIdx];
    }

store_entry:
    /* store address and mark for printing */
    statusEntry->address = to;
    statusEntry->print = 1;
    statusEntry->pending = 1;

    return 0;

not_connected:
    Com_Printf((const char *)"Not connected to a server.\n"); /* "Not connected to a server.\n" */
    Com_Printf((const char *)"Usage: serverstatus [server]\n"); /* "Usage: serverstatus [server]\n" */
    return 0;
}
