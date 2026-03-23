/* ASM dump from: cl_ui_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_ui_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

extern int I_stricmp(const char *s1, const char *s2);

extern qboolean CL_UpdateDirtyPings_f(int source);
extern int CL_ServerStatus(char *serverAddress, char *serverStatus, int maxLen);
extern int SND_PlayLocalSoundAlias(snd_alias_list_t *aliasList, int channel);
extern int SND_PlayLocalSoundAliasByName(const char *aliasname, int channel);
extern void Com_LoadSoundAliases(const char *zone, const char *spec, int flags);
extern qboolean UI_CheckExecKey(int key);
extern void CL_SwitchToLocalClient(int localClientNum);
extern void UI_Init(void);
extern void UI_Component_Init(void);
extern qboolean UI_IsFullscreen(void);
extern qboolean UI_SetActiveMenu(int menu);
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
    clientConnection_t *clc_local = *(clientConnection_t **)imp_clc;
    clientStatic_t *cls_local = (clientStatic_t *)imp_cls;
    clientActive_t *cl = *(clientActive_t **)imp_cl;

    state->connectPacketCount = clc_local->connectPacketCount;
    state->connState = clc_local->state;
    I_strncpyz(state->servername, cls_local->servername, 0x400);
    I_strncpyz(state->messageString, clc_local->serverMessage, 0x400);
    state->clientNum = cl->snap.ps.clientNum;
}

/* line 41 */
void LAN_ResetPings(int source)
{
    clientStatic_t *base = (clientStatic_t *)imp_cls;
    serverInfo_t *servers;
    int count;

    if (source == 0) {
        count = 128;
        servers = base->localServers;
    } else if (source == 1) {
        count = base->numglobalservers;
        servers = base->globalServers;
        if (count <= 0)
            return;
    } else if (source == 2) {
        count = 128;
        servers = base->favoriteServers;
    } else {
        return;
    }

    for (int i = 0; i < count; i++) {
        servers[i].ping = -1;
    }
}

/* line 82 */
int LAN_GetServerCount(int source)
{
    clientStatic_t *base = (clientStatic_t *)imp_cls;
    if (source == 0)
        return base->numlocalservers;
    if (source == 1)
        return base->numglobalservers;
    if (source == 2)
        return base->numfavoriteservers;
    return 0;
}

/* line 106 */
qboolean LAN_WaitServerResponse(int source)
{
    if (source != 1)
        return 0;
    return ((clientStatic_t *)imp_cls)->waitglobalserverresponse;
}

/* line 124 */
void LAN_GetServerInfo(int source, int n, char *buf, int buflen)
{
    char info[1024];
    clientStatic_t *cls_base = (clientStatic_t *)imp_cls;
    serverInfo_t *server = NULL;

    info[0] = '\0';

    if (source == 0) {
        if ((unsigned)n > 0x7f) goto fail;
        server = &cls_base->localServers[n];
    } else if (source == 1) {
        if (n < 0 || n >= cls_base->numglobalservers) goto fail;
        server = &cls_base->globalServers[n];
    } else if (source == 2) {
        if ((unsigned)n > 0x7f) goto fail;
        server = &cls_base->favoriteServers[n];
    } else {
        goto fail;
    }

    if (!server) goto fail;
    if (!buf) return;

    *buf = '\0';
    Info_SetValueForKey(info, "hostname", server->hostName);
    Info_SetValueForKey(info, "mapname", server->mapName);
    Info_SetValueForKey(info, "clients", va("%i", (int)server->clients));
    Info_SetValueForKey(info, "sv_maxclients", va("%i", (int)server->maxClients));
    Info_SetValueForKey(info, "ping", va("%i", (int)server->ping));
    Info_SetValueForKey(info, "minping", va("%i", (int)server->minPing));
    Info_SetValueForKey(info, "maxping", va("%i", (int)server->maxPing));
    Info_SetValueForKey(info, "game", server->game);
    Info_SetValueForKey(info, "gametype", server->gameType);
    Info_SetValueForKey(info, "nettype", va("%i", (int)server->netType));
    {
        netadr_t adr;
        memcpy(&adr, &server->adr, sizeof(netadr_t));
        Info_SetValueForKey(info, "addr", NET_AdrToString(adr));
    }
    Info_SetValueForKey(info, "sv_allowAnonymous", va("%i", (int)server->allowAnonymous));
    Info_SetValueForKey(info, "con_disabled", va("%i", (int)server->consoleDisabled));
    Info_SetValueForKey(info, "pswrd", va("%i", (int)server->bPassword));
    Info_SetValueForKey(info, "pure", va("%i", (int)server->pure));
    Info_SetValueForKey(info, "ff", va("%i", (int)server->friendlyfire));
    Info_SetValueForKey(info, "kc", va("%i", (int)server->killcam));
    Info_SetValueForKey(info, "hw", va("%i", (int)server->hardware));
    Info_SetValueForKey(info, "mod", va("%i", (int)server->mod));
    Info_SetValueForKey(info, "voice", va("%i", (int)server->voice));
    I_strncpyz(buf, info, buflen);
    return;

fail:
    if (buf)
        *buf = '\0';
}

/* line 200 */
int LAN_GetServerPing(int source, int n)
{
    clientStatic_t *base = (clientStatic_t *)imp_cls;
    serverInfo_t *server;

    if (source == 0) {
        if ((unsigned)n > 0x7f)
            return -1;
        server = &base->localServers[n];
    } else if (source == 1) {
        if (n < 0 || n >= base->numglobalservers)
            return -1;
        server = &base->globalServers[n];
    } else if (source == 2) {
        if ((unsigned)n > 0x7f)
            return -1;
        server = &base->favoriteServers[n];
    } else {
        return -1;
    }

    if (!server)
        return -1;
    return server->ping;
}

/* line 419 */
void LAN_MarkServerDirty(int source, int n, qboolean dirty)
{
    clientStatic_t *cls_base = (clientStatic_t *)imp_cls;
    serverInfo_t *servers;
    int count;
    int i;

    Com_PumpMessageLoop();

    if (n == -1) {
        /* Mark all servers dirty */
        if (source == 0) {
            count = 0x80;
            servers = cls_base->localServers;
        } else if (source == 1) {
            count = cls_base->numglobalservers;
            servers = cls_base->globalServers;
            if (count <= 0) return;
        } else if (source == 2) {
            count = 0x80;
            servers = cls_base->favoriteServers;
        } else {
            return;
        }
        for (i = 0; i < count; i++) {
            servers[i].dirty = (byte)dirty;
        }
    } else {
        if (source == 0) {
            if ((unsigned)n > 0x7f) return;
            cls_base->localServers[n].dirty = (byte)dirty;
        } else if (source == 1) {
            if (n < 0 || n >= cls_base->numglobalservers) return;
            cls_base->globalServers[n].dirty = (byte)dirty;
        } else if (source == 2) {
            if ((unsigned)n > 0x7f) return;
            cls_base->favoriteServers[n].dirty = (byte)dirty;
        }
    }
}

/* line 490 */
int LAN_ServerIsDirty(int source, int n)
{
    clientStatic_t *cls_base = (clientStatic_t *)imp_cls;

    if (source == 0) {
        if ((unsigned)n > 0x7f)
            return 0;
        return cls_base->localServers[n].dirty;
    } else if (source == 1) {
        if (n < 0 || n >= cls_base->numglobalservers)
            return 0;
        return cls_base->globalServers[n].dirty;
    } else if (source == 2) {
        if ((unsigned)n > 0x7f)
            return 0;
        return cls_base->favoriteServers[n].dirty;
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
    return (*(clientActive_t **)imp_cl)->keyCatchers;
}

/* line 593 */
void Key_SetCatcher(int catcher)
{
    clientActive_t *ptr = *(clientActive_t **)imp_cl;
    if (ptr->keyCatchers & 1)
        ptr->keyCatchers = catcher | 1;
    else
        ptr->keyCatchers = catcher;
    ptr = *(clientActive_t **)imp_cl;
    if (!(ptr->keyCatchers & 8))
        ptr->displayHUDWithKeycatchUI = 0;
}

/* line 611 */
void CLUI_GetCDKey(char *buf, int buflen, char *buf2, int buf2len)
{
    char *cdkey;
    char *cdkey2;

    Dvar_RegisterString((const char *)"fs_game", (const char *)"", 0x101c); /* "fs_game" */

    cdkey = (char *)imp_cl_cdkey;
    memcpy(buf, cdkey, 16);
    buf[16] = '\0';

    cdkey2 = (char *)imp_cl_cdkeychecksum;
    memcpy(buf2, cdkey2, 4);
    buf2[4] = '\0';
}

/* Compute CRC-16/ARC checksum over cdkey, matching the check in CL_CheckForResend */
void CL_ComputeCDKeyChecksum(const char *key, char *checksumOut)
{
    unsigned int crc = 0;
    int i, j;

    for (i = 0; i < 16; i++) {
        crc ^= (unsigned char)key[i];
        for (j = 0; j < 8; j++) {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xa001;
            else
                crc >>= 1;
        }
    }
    sprintf(checksumOut, "%04X", crc);
}

/* line 631 */
void CLUI_SetCDKey(char *buf, char *buf2)
{
    char *cdkey = (char *)imp_cl_cdkey;
    char *cdkey2 = (char *)imp_cl_cdkeychecksum;

    memcpy(cdkey, buf, 16);
    cdkey[16] = '\0';

    /* Compute the correct checksum to match the connection handshake verification */
    CL_ComputeCDKeyChecksum(cdkey, cdkey2);

    Com_WriteCDKey();
}

/* line 647 */
qboolean GetClientname(int index, char *buf, int size)
{
    clientActive_t *cl;
    int count;
    int start;
    int i;

    *buf = '\0';

    cl = *(clientActive_t **)imp_cl;
    if (!cl->snap.valid)
        return 0;

    count = cl->snap.numEntities;
    if (count <= 0)
        return 0;

    start = cl->snap.parseEntitiesNum;

    for (i = 0; i < count; i++) {
        int slot = (start + i) & 0x7ff;
        clientState_t *entry = &cl->parseClients[slot];

        if (entry->clientIndex == index) {
            strncpy(buf, entry->name, size);
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
    clientConnection_t *clc_local = *(clientConnection_t **)imp_clc;
    if (!clc_local) return 0;
    return clc_local->state == 8;
}

/* line 899 */
qboolean CL_ShutdownUI(void)
{
    clientStatic_t *cls_local = (clientStatic_t *)imp_cls;
    clientActive_t *cl;

    if (!cls_local->uiStarted)
        return 0;

    Com_UnloadSoundAliases(0);

    cl = *(clientActive_t **)imp_cl;
    cl->keyCatchers &= ~8;
    cl->displayHUDWithKeycatchUI = 0;

    CL_SwitchToLocalClient(0);
    UI_Shutdown();
    CL_SwitchToLocalClient(0);

    cls_local->uiStarted = 0;
    return 1;
}

/* line 935 */
void CL_InitUI(void)
{
    ((clientStatic_t *)imp_cls)->uiStarted = 1;
    CL_SwitchToLocalClient(0);
    UI_Init();
    CL_SwitchToLocalClient(0);
    UI_Component_Init();

    if (!UI_ClientIsInGame() && !UI_IsFullscreen())
        UI_SetActiveMenu(1);
}

/* line 963 */
qboolean UI_checkKeyExec(int key)
{
    if (!((clientStatic_t *)imp_cls)->uiStarted)
        return 0;
    return UI_CheckExecKey(key);
}

/* line 979 */
void UI_LoadSoundAliases(void)
{
    Com_LoadSoundAliases("menu", "all_mp", 0);
}

/* line 301 */
int LAN_CompareHostname(const char *hostName1, const char *hostName2)
{
    /* Strip non-alpha characters, then compare cleaned versions;
       if equal, fall back to raw comparison. */
    char cleanHostName1[40];
    char cleanHostName2[40];
    char *dst;
    const char *src;
    int c, result;

    /* Build cleanHostName1 */
    dst = cleanHostName1;
    src = hostName1;
    while ((c = (unsigned char)*src) != 0) {
        if (isalpha(c))
            *dst++ = (char)c;
        src++;
    }
    *dst = '\0';

    /* Build cleanHostName2 */
    dst = cleanHostName2;
    src = hostName2;
    while ((c = (unsigned char)*src) != 0) {
        if (isalpha(c))
            *dst++ = (char)c;
        src++;
    }
    *dst = '\0';

    result = I_stricmp(cleanHostName1, cleanHostName2);
    if (result != 0)
        return result;
    return I_stricmp(hostName1, hostName2);
}

/* line 320 */
int LAN_CompareServers(int source, int sortKey, int sortDir, int s1, int s2)
{
    /* Get pointer to clientStatic_t from import */
    clientStatic_t *cls_ptr = (clientStatic_t *)imp_cls;
    serverInfo_t *server1 = (serverInfo_t *)0;
    serverInfo_t *server2 = (serverInfo_t *)0;
    int diff;

    /* Resolve server1 pointer */
    if (source == 1) {
        /* global servers */
        if (s1 >= 0 && s1 < cls_ptr->numglobalservers)
            server1 = &cls_ptr->globalServers[s1];
    } else if (source == 2) {
        /* favorite servers */
        if ((unsigned int)s1 <= 0x7f)
            server1 = &cls_ptr->favoriteServers[s1];
    } else {
        /* local servers (source == 0) */
        if ((unsigned int)s1 <= 0x7f)
            server1 = &cls_ptr->localServers[s1];
    }

    /* Resolve server2 pointer */
    if (source == 1) {
        if (s2 >= 0 && s2 < cls_ptr->numglobalservers)
            server2 = &cls_ptr->globalServers[s2];
    } else if (source == 2) {
        if ((unsigned int)s2 <= 0x7f)
            server2 = &cls_ptr->favoriteServers[s2];
    } else {
        if ((unsigned int)s2 <= 0x7f)
            server2 = &cls_ptr->localServers[s2];
    }

    if (!server1 || !server2)
        return 0;

    /* Switch on sortKey (0-9), unknown key returns 0 */
    diff = 0;
    switch (sortKey) {
    case 0: /* bPassword */
        diff = (int)(unsigned char)server1->bPassword - (int)(unsigned char)server2->bPassword;
        if (diff == 0) goto compare_ping_nosortdir;
        break;
    case 1: /* hardware presence sort */
        {
            unsigned char hw1 = server1->hardware;
            unsigned char hw2 = server2->hardware;
            diff = (int)hw1 - (int)hw2;
            if (diff == 0) goto compare_ping_nosortdir;
            if (diff < 0) {
                /* hw1 < hw2: if hw1 == 0 then diff=1, else keep diff */
                if (!hw1) diff = 1;
            } else {
                /* hw1 > hw2: if hw2 == 0 then diff=-1, else keep diff */
                if (!hw2) diff = -1;
            }
        }
        break;
    case 2: /* hostname */
        diff = LAN_CompareHostname(server1->hostName, server2->hostName);
        if (diff == 0) goto compare_ping_nosortdir;
        break;
    case 3: /* mapName */
        diff = I_stricmp(server1->mapName, server2->mapName);
        if (diff == 0) goto compare_ping_nosortdir;
        break;
    case 4: /* clients */
        diff = (int)(unsigned char)server1->clients - (int)(unsigned char)server2->clients;
        if (diff == 0) goto compare_ping_nosortdir;
        break;
    case 5: /* gameType */
        diff = I_stricmp(server1->gameType, server2->gameType);
        if (diff != 0) break;
        goto compare_ping_nosortdir;
    case 6: /* voice */
        diff = (int)(unsigned char)server1->voice - (int)(unsigned char)server2->voice;
        if (diff == 0) goto compare_ping_nosortdir;
        break;
    case 7: /* pure */
        diff = (int)(unsigned char)server1->pure - (int)(unsigned char)server2->pure;
        if (diff == 0) goto compare_ping_nosortdir;
        break;
    case 8: /* mod */
        diff = (int)(unsigned char)server1->mod - (int)(unsigned char)server2->mod;
        if (diff == 0) {
            /* fallthrough to ping compare with sortDir cleared */
            goto compare_ping_nosortdir;
        }
        break;
    case 9: /* ping */
        goto compare_ping;
    default:
        diff = 0;
        break;
    }
    goto apply_sortdir;

compare_ping_nosortdir:
    sortDir = 0;
compare_ping:
    diff = (int)(short)server1->ping - (int)(short)server2->ping;
    if (diff == 0) {
        /* tie-break: compare gameType then hostname */
        diff = I_stricmp(server1->gameType, server2->gameType);
        if (diff == 0)
            diff = LAN_CompareHostname(server1->hostName, server2->hostName);
    }

apply_sortdir:
    if (sortDir)
        diff = -diff;
    return diff;
}
