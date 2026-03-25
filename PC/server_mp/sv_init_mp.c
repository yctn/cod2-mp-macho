/* Converted to C from ASM: sv_init_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_init_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
#include <stdlib.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern int sv_serverId_value; /* 0x0 */

extern byte sv_ptr[];               /* imp_sv - server_t */
extern byte svs_ptr[];              /* imp_svs - serverStatic_t */
extern byte *sv_maxclients_dvar;   /* imp_sv_maxclients */
extern byte *sv_gametype_dvar;     /* imp_sv_gametype */
extern byte *sv_dedicated_dvar;    /* imp_com_dedicated */
extern byte *sv_running_dvar;      /* imp_com_sv_running */
extern byte *sv_serverid_dvar;     /* imp_sv_serverid */
extern byte *sv_expectedHunkUsage_dvar; /* imp_com_expectedHunkUsage */
extern byte *sv_mapname_dvar;      /* imp_sv_mapname */
extern byte *sv_privateClients_dvar;/* imp_sv_privateClients */
extern byte *sv_hostname_dvar;     /* imp_sv_hostname */
extern byte *sv_maxRate_dvar;      /* imp_sv_maxRate */
extern byte *sv_minPing_dvar;      /* imp_sv_minPing */
extern byte *sv_maxPing_dvar;      /* imp_sv_maxPing */
extern byte *sv_floodProtect_dvar; /* imp_sv_floodProtect */
extern byte *sv_allowAnonymous_dvar;/* imp_sv_allowAnonymous */
extern byte *sv_showCommands_dvar; /* imp_sv_showCommands */
extern byte *sv_disableClientConsole_dvar; /* imp_sv_disableClientConsole */
extern byte *sv_voice_dvar;        /* imp_sv_voice */
extern byte *sv_voiceQuality_dvar; /* imp_sv_voiceQuality */
extern byte *sv_cheats_dvar;       /* imp_sv_cheats */
extern byte *sv_pure_dvar;         /* imp_sv_pure */
extern byte *sv_iwds_dvar;         /* imp_sv_iwds */
extern byte *sv_iwdNames_dvar;     /* imp_sv_iwdNames */
extern byte *sv_referencedIwds_dvar;/* imp_sv_referencedIwds */
extern byte *sv_referencedIwdNames_dvar; /* imp_sv_referencedIwdNames */
extern byte *rcon_password_dvar;   /* imp_rcon_password */
extern byte *sv_privatePassword_dvar; /* imp_sv_privatePassword */
extern byte *sv_fps_dvar;          /* imp_sv_fps */
extern byte *sv_timeout_dvar;      /* imp_sv_timeout */
extern byte *sv_zombietime_dvar;   /* imp_sv_zombietime */
extern byte *sv_allowDownload_dvar;/* imp_sv_allowDownload */
extern byte *sv_reconnectlimit_dvar; /* imp_sv_reconnectlimit */
extern byte *sv_padPackets_dvar;   /* imp_sv_padPackets */
extern byte *sv_allowedClan1_dvar; /* imp_sv_allowedClan1 */
extern byte *sv_allowedClan2_dvar; /* imp_sv_allowedClan2 */
extern byte *sv_packet_info_dvar;  /* imp_sv_packet_info */
extern byte *sv_showAverageBPS_dvar; /* imp_sv_showAverageBPS */
extern byte *sv_kickBanTime_dvar;  /* imp_sv_kickBanTime */
extern byte *sv_mapRotation_dvar;  /* imp_sv_mapRotation */
extern byte *sv_mapRotationCurrent_dvar; /* imp_sv_mapRotationCurrent */
extern byte *sv_debugRate_dvar;    /* imp_sv_debugRate */
extern byte *sv_debugReliableCmds_dvar; /* imp_sv_debugReliableCmds */
extern int nextmap;                /* imp_nextmap — BSS dvar pointer */
extern byte *com_dvarflags_ptr;    /* imp_dvar_modifiedFlags */
extern byte *com_checksumFeed_dvar; /* imp_com_frameTime */
extern void *imp_com_errorEntered;
/* sv_dedicated_dvar2 removed - use imp_com_dedicated directly */
extern byte *sv_com_dvarDump_ptr;  /* imp_cl_paused */

extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int I_stricmp(const char *s1, const char *s2);
extern int stricmp(const char *s1, const char *s2);
extern void *Z_MallocInternal(int size);
extern void Z_FreeInternal(void *ptr);
extern void *Z_VirtualAllocInternal(int size);
extern void Z_VirtualFreeInternal(void *ptr);
extern void *Hunk_AllocInternal(int size);
extern void *Hunk_AllocateTempMemoryInternal(int size);
extern void Hunk_FreeTempMemory(void *buf);
extern int FS_FOpenFileByMode(const char *qpath, fileHandle_t *f, int mode);
extern void FS_Read(void *buffer, int len, fileHandle_t f);
extern void FS_FCloseFile(fileHandle_t f);
extern char *Com_Parse(const char **data_p);
extern void ReplaceStringInternal(const char **dest, const char *src);
extern char *CopyStringInternal(const char *in);
extern void SV_SendServerCommand(void *client, int reliable, const char *fmt, ...);
extern dvar_t *Dvar_RegisterString(const char *dvarName, const char *defaultValue, int flags);
extern dvar_t *Dvar_RegisterInt(const char *dvarName, int defaultValue, int min, int max, int flags);
extern dvar_t *Dvar_RegisterBool(const char *dvarName, qboolean defaultValue, int flags);
extern dvar_t *Dvar_RegisterFloat(const char *dvarName, float defaultValue, float min, float max, int flags);
extern void Dvar_SetInt(dvar_t *dvar, int value);
extern void Dvar_SetBool(dvar_t *dvar, int value);
extern void Dvar_SetString(dvar_t *dvar, const char *value);
extern void Dvar_SetStringByName(const char *dvarName, const char *value);
extern void Dvar_ClearModified(dvar_t *dvar);
extern void Dvar_ResetScriptInfo(void);
extern char *Dvar_InfoString(int bit);
extern char *Dvar_InfoString_Big(int bit);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern void Com_Memset(void *dest, int val, int count);
extern void SV_AddOperatorCommands(void);
extern void SV_RemoveOperatorCommands(void);
extern void SV_MasterShutdown(void);
extern void SV_ShutdownGameProgs(void);
extern void SV_FreeClients(void);
extern void SV_DropClient(void *client, const char *reason);
extern void SV_SendClientSnapshot(void *client);
extern void SV_RunFrame(void);
extern void SV_Heartbeat_f(void);
extern void SV_MasterGameCompleteStatus(void);
extern void SV_SetConfig(int start, int max, int count);
extern void SV_SetGametype(void);
extern void SV_InitGameProgs(int savepersist);
extern void *SV_GentityNum(int num);
extern void CL_InitLoad(const char *server, const char *gametype);
extern void CL_MapLoading(const char *server);
extern void CL_ShutdownAll(void);
extern void CL_StartLoading(const char *server, const char *gametype);
extern void CL_Disconnect(void);
extern int CL_GetLocalClientActive(int localClientNum);
extern void UI_LoadIngameMenus(void);
extern void Com_Restart(void);
extern void Material_PreLoadAllShaderText(void);
extern void Com_LoadBsp(const char *filename);
extern void CM_LoadMap(const char *name, int *checksum);
extern void Com_UnloadBsp(void);
extern void CM_LinkWorld(void);
extern void Com_LoadSoundAliases(const char *filename, const char *name, int type);
extern void Com_AbortDObj(void);
extern void DObjAbort(void);
extern void XAnimAbort(void);
extern void Scr_Abort(void);
extern void Scr_ParseGameTypeList(void);
extern void FX_FreeSystem(void);
extern void FX_InitSystem(int dummy);
extern void FX_CreateDefaultEffect(void);
extern void FS_Shutdown(int closemfp);
extern void FS_ClearIwdReferences(void);
extern void FS_Restart(int checksumFeed);
extern const char *FS_LoadedIwdChecksums(void);
extern const char *FS_LoadedIwdNames(void);
extern const char *FS_ReferencedIwdChecksums(void);
extern const char *FS_ReferencedIwdNames(void);
extern const char *GetBspExtension(void);
extern int Sys_Milliseconds(void);
extern int Sys_MillisecondsRaw(void);
extern void NET_Sleep(int msec);
extern Bool NET_OutOfBandPrint(int sock, netadr_t adr, const char *data);
extern int *G_GetSavePersist(void);
extern const char *ClientConnect(int clientNum, unsigned short scriptId);
extern int __mh_execute_header;

#define CLIENT_SIZE 0x78F0C
#define SV_STATE_OFF       0x0
#define SV_SNAPFLAG_OFF    0x4
#define SV_CHECKSUM_OFF    0x8
#define SV_SERVERID_OFF    0xC
#define SV_CONFIGSTRINGS_OFF 0x418
#define SV_NUMENTITIES_OFF 0x5F424
#define SV_GAMETYPE_OFF    0x5F4F4

#define SVS_INITIALIZED_OFF 0x0
#define SVS_TIME_OFF        0x4
#define SVS_SNAPFLAGBIT_OFF 0x8
#define SVS_CLIENTS_OFF     0xC
#define SVS_NUMSNAPENTS_OFF 0x10
#define SVS_NUMSNAPCLIENTS_OFF 0x14
#define SVS_NEXTSNAPENTS_OFF 0x18
#define SVS_NEXTSNAPCLIENTS_OFF 0x1C
#define SVS_SNAPENTS_OFF    0x20
#define SVS_SNAPCLIENTS_OFF 0x24
#define SVS_ARCHSNAP_ENABLED_OFF 0x28
#define SVS_ARCHSNAP_2C_OFF 0x2C
#define SVS_ARCHSNAP_FRAMES_OFF 0x30
#define SVS_ARCHSNAP_BUFFER_OFF 0x34
#define SVS_ARCHSNAP_38_OFF 0x38
#define SVS_ARCHSNAP_3C_OFF 0x3C
#define SVS_ARCHSNAP_40_OFF 0x40
#define SVS_ARCHSNAP_44_OFF 0x44
#define SVS_ARCHSNAP_48_OFF 0x48
#define SVS_ARCHSNAP_4C_OFF 0x4C
#define SVS_ARCHSNAP_50_OFF 0x50

#define CLIENT_STATE_OFF    0x0
#define CLIENT_USERINFO_OFF 0xC
#define CLIENT_NAME_OFF     0x20C48
#define CLIENT_NETCHAN_STATE_OFF 0x6E5C4

Bool SV_Loaded(void);
void SV_GetConfigstring(int index, char *buffer, int bufferSize);
const char *SV_GetConfigstringConst(int index);
void SV_SetUserinfo(int index, const char *val);
void SV_GetUserinfo(int index, char *buffer, int bufferSize);
void SV_SetExpectedHunkUsage(char *mapname);
void SV_EnableArchivedSnapshot(qboolean bEnable);
void SV_InitArchivedSnapshot(void);
void SV_InitDvar(void);
void SV_Init(void);
void SV_SetConfigstring(const int index, const char *val);
void SV_SetConfigValueForKey(int start, int max, const char *key, const char *value);
void SV_Shutdown(char *finalmsg);
void SV_Startup(void);
void SV_ChangeMaxClients(void);
void SV_SpawnServer(const char *server);

static void SV_ClearServer(void);
static void SV_FreeArchivedSnapshotBuffers(void);
static void SV_FreeServerStructure(void);
static void SV_TouchMemory(void);
static void SV_DropAllClients(void);
static void SV_InitMaxClients(void);
static void SV_SendMapChange(void);

/* line 1074 */
Bool SV_Loaded(void)
{
    byte *sv = (byte *)imp_sv;
    return *(int *)(sv + SV_STATE_OFF) == 2;
}

/* line 140 */
void SV_GetConfigstring(int index, char *buffer, int bufferSize)
{
    byte *sv;
    const char *s;

    if (bufferSize <= 0) {
        Com_Error(1, "SV_GetConfigstring: bufferSize == %i", bufferSize);
    }
    if (index > 0x7ff) {
        Com_Error(1, "SV_GetConfigstring: bad index %i\n", index);
    }

    sv = (byte *)imp_sv;
    s = *(const char **)(sv + SV_CONFIGSTRINGS_OFF + index * 4);
    if (!s) {
        *buffer = '\0';
        return;
    }

    I_strncpyz(buffer, s, bufferSize);
}

/* line 166 */
const char *SV_GetConfigstringConst(int index)
{
    byte *sv;
    const char *s;

    sv = (byte *)imp_sv;
    s = *(const char **)(sv + SV_CONFIGSTRINGS_OFF + index * 4);
    if (!s)
        return "";
    return s;
}

/* line 240 */
void SV_SetUserinfo(int index, const char *val)
{
    byte *svs;
    byte *client;
    const char *name;

    if (index < 0 || index >= *(int *)(*(byte **)imp_sv_maxclients + 8)) {
        Com_Error(1, "SV_SetUserinfo: bad index %i\n", index);
    }

    if (!val)
        val = "";

    {
        serverStatic_t *svsPtr = (serverStatic_t *)imp_svs;
        client_t *cl = &svsPtr->clients[index];

        I_strncpyz(cl->userinfo, val, 0x400);
        name = (const char *)Info_ValueForKey(val, "name");
        I_strncpyz(cl->name, name, 0x20);
    }
}

/* line 263 */
void SV_GetUserinfo(int index, char *buffer, int bufferSize)
{
    byte *svs;
    byte *client;

    if (bufferSize <= 0) {
        Com_Error(1, "SV_GetUserinfo: bufferSize == %i", bufferSize);
    }
    if (index < 0 || index >= *(int *)(*(byte **)imp_sv_maxclients + 8)) {
        Com_Error(1, "SV_GetUserinfo: bad index %i\n", index);
    }

    {
        serverStatic_t *svsPtr = (serverStatic_t *)imp_svs;
        client_t *cl = &svsPtr->clients[index];

        I_strncpyz(buffer, cl->userinfo, bufferSize);
    }
}

/* line 491 */
void SV_SetExpectedHunkUsage(char *mapname)
{
    fileHandle_t handle;
    int len;
    char *buf;
    char *buftrav;
    char *token;

    len = FS_FOpenFileByMode("hunkusage.dat", &handle, 0);
    if (len < 0)
        return;

    buf = (char *)Z_MallocInternal(len + 1);
    memset(buf, 0, len + 1);
    FS_Read(buf, len, handle);
    FS_FCloseFile(handle);
    buftrav = buf;

    while (1) {
        token = Com_Parse((const char **)&buftrav);
        if (!token || *token == '\0') {
            Z_FreeInternal(buf);
            return;
        }
        if (I_stricmp(token, mapname) == 0) {
            token = Com_Parse((const char **)&buftrav);
            if (!token || *token == '\0')
                continue;
            Dvar_SetInt(*(dvar_t **)imp_com_expectedHunkUsage, atoi(token));
            Z_FreeInternal(buf);
            return;
        }
    }
}

/* line 564 */
void SV_EnableArchivedSnapshot(qboolean bEnable)
{
    serverStatic_t *svs;

    svs = (serverStatic_t *)imp_svs;
    svs->archiveEnabled = bEnable;

    if (!bEnable)
        return;
    if (svs->archivedSnapshotFrames)
        return;

    *(void **)&svs->cachedSnapshotEntities = Z_MallocInternal(0x450000);
    *(void **)&svs->cachedSnapshotClients = Z_MallocInternal(0x2708000);
    *(void **)&svs->archivedSnapshotFrames = Z_MallocInternal(0x2580);
    svs->archivedSnapshotBuffer = Z_MallocInternal(0x2000000);
    svs->cachedSnapshotFrames = Z_MallocInternal(0x3800);
}

/* line 599 */
void SV_InitArchivedSnapshot(void)
{
    serverStatic_t *svs;

    svs = (serverStatic_t *)imp_svs;
    svs->archiveEnabled = 0;
    svs->nextArchivedSnapshotFrames = 0;
    svs->nextArchivedSnapshotBuffer = 0;
    svs->nextCachedSnapshotEntities = 0;
    svs->nextCachedSnapshotClients = 0;
    svs->nextCachedSnapshotFrames = 0;
}

/* line 655 */
void SV_InitDvar(void)
{
    Dvar_ResetScriptInfo();
}

/* line 1198 */
void SV_Init(void)
{
    SV_AddOperatorCommands();

    *(dvar_t **)imp_sv_gametype = Dvar_RegisterString("g_gametype", "dm", 0x1024);
    Dvar_RegisterString("sv_keywords", "", 0x1004);
    Dvar_RegisterInt("protocol", 0x76, 0x76, 0x76, 0x1044);
    *(dvar_t **)imp_sv_mapname = Dvar_RegisterString("mapname", "", 0x1044);
    *(dvar_t **)imp_sv_privateClients = Dvar_RegisterInt("sv_privateClients", 0, 0, 0x40, 0x1004);
    *(dvar_t **)imp_sv_maxclients = Dvar_RegisterInt("sv_maxclients", 20, 1, 0x40, 0x1025);
    *(dvar_t **)imp_sv_hostname = Dvar_RegisterString("sv_hostname", "CoD2Host", 0x1005);
    *(dvar_t **)imp_sv_maxRate = Dvar_RegisterInt("sv_maxRate", 0, 0, 25000, 0x1005);
    *(dvar_t **)imp_sv_minPing = Dvar_RegisterInt("sv_minPing", 0, 0, 999, 0x1005);
    *(dvar_t **)imp_sv_maxPing = Dvar_RegisterInt("sv_maxPing", 0, 0, 999, 0x1005);
    *(dvar_t **)imp_sv_floodProtect = Dvar_RegisterBool("sv_floodProtect", 1, 0x1005);
    *(dvar_t **)imp_sv_allowAnonymous = Dvar_RegisterBool("sv_allowAnonymous", 0, 0x1004);
    *(dvar_t **)imp_sv_showCommands = Dvar_RegisterBool("sv_showCommands", 0, (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_disableClientConsole = Dvar_RegisterBool("sv_disableClientConsole", 0, 0x1008);
    *(dvar_t **)imp_sv_voice = Dvar_RegisterBool("sv_voice", 0, 0x100d);
    *(dvar_t **)imp_sv_voiceQuality = Dvar_RegisterInt("sv_voiceQuality", 1, 0, 9, 0x1008);
    *(dvar_t **)imp_sv_cheats = Dvar_RegisterBool("sv_cheats", 0, 0x1018);
    *(dvar_t **)imp_sv_serverid = Dvar_RegisterInt("sv_serverid", 0, (int)0x80000000, 0x7fffffff, 0x1048);
    *(dvar_t **)imp_sv_pure = Dvar_RegisterBool("sv_pure", 1, 0x100c);
    *(dvar_t **)imp_sv_iwds = Dvar_RegisterString("sv_iwds", "", 0x1048);
    *(dvar_t **)imp_sv_iwdNames = Dvar_RegisterString("sv_iwdNames", "", 0x1048);
    *(dvar_t **)imp_sv_referencedIwds = Dvar_RegisterString("sv_referencedIwds", "", 0x1048);
    *(dvar_t **)imp_sv_referencedIwdNames = Dvar_RegisterString("sv_referencedIwdNames", "", 0x1048);
    *(dvar_t **)imp_rcon_password = Dvar_RegisterString("rcon_password", "", (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_privatePassword = Dvar_RegisterString("sv_privatePassword", "", (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_fps = Dvar_RegisterInt("sv_fps", 20, 10, 1000, (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_timeout = Dvar_RegisterInt("sv_timeout", 240, 0, 1800, (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_zombietime = Dvar_RegisterInt("sv_zombietime", 2, 0, 1800, (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_allowDownload = Dvar_RegisterBool("sv_allowDownload", 1, 0x1001);
    *(dvar_t **)imp_sv_reconnectlimit = Dvar_RegisterInt("sv_reconnectlimit", 3, 0, 1800, 0x1001);
    *(dvar_t **)imp_sv_padPackets = Dvar_RegisterInt("sv_padPackets", 0, 0, 0x7fffffff, (int)&__mh_execute_header);

    /* line 1273 */
    {
        byte *svDedicated = (byte *)imp_com_dedicated;
        byte *dvar = *(byte **)svDedicated;
        *(char *)(dvar + 0xdd) = 0; /* dvar_t internal flag at 0xdd */
    }

    *(dvar_t **)imp_sv_allowedClan1 = Dvar_RegisterString("sv_allowedClan1", "", (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_allowedClan2 = Dvar_RegisterString("sv_allowedClan2", "", (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_packet_info = Dvar_RegisterBool("sv_packet_info", 0, (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_showAverageBPS = Dvar_RegisterBool("sv_showAverageBPS", 0, (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_kickBanTime = Dvar_RegisterFloat("sv_kickBanTime", 300.0f, 0.0f, 3600.0f, (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_mapRotation = Dvar_RegisterString("sv_mapRotation", "", (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_mapRotationCurrent = Dvar_RegisterString("sv_mapRotationCurrent", "", (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_debugRate = Dvar_RegisterBool("sv_debugRate", 0, (int)&__mh_execute_header);
    *(dvar_t **)imp_sv_debugReliableCmds = Dvar_RegisterBool("sv_debugReliableCmds", 0, (int)&__mh_execute_header);
    *(dvar_t **)&nextmap = Dvar_RegisterString("nextmap", "", (int)&__mh_execute_header);
    *(dvar_t **)imp_com_expectedHunkUsage = Dvar_RegisterInt("com_expectedHunkUsage", 0, 0, 0x7fffffff, 0x1040);
}

/* line 49 */
void SV_SetConfigstring(const int index, const char *val)
{
    byte *sv;
    const char *old;
    int len;
    int maxChunk;
    char buf[0x400];
    int i;
    int sent;
    int remaining;
    byte *client;
    char cmd;

    if (index > 0x7ff) {
        Com_Error(1, "SV_SetConfigstring: bad index %i\n", index);
    }

    if (!val)
        val = "";

    sv = (byte *)imp_sv;
    old = *(const char **)(sv + SV_CONFIGSTRINGS_OFF + index * 4);
    if (!old)
        return;
    if (strcmp(val, old) == 0)
        return;

    ReplaceStringInternal((const char **)(sv + SV_CONFIGSTRINGS_OFF + index * 4), val);

    if (*(int *)(sv + SV_STATE_OFF) != 2) {
        if (*(int *)(sv + SV_SNAPFLAG_OFF) == 0)
            return;
    }

    len = strlen(val);
    sprintf(buf, "%i", index);
    maxChunk = 0x3fd - strlen(buf);

    {
    serverStatic_t *svsPtr = (serverStatic_t *)imp_svs;
    for (i = 0; i < *(int *)(*(byte **)imp_sv_maxclients + 8); i++) {
        if (svsPtr->clients[i].state <= 2)
            goto next;

        if (len <= maxChunk) {
            SV_SendServerCommand(&svsPtr->clients[i], 1, "%c %i %s", 'd', index, val);
        } else {
            remaining = len;
            sent = 0;
            cmd = 'x';
            while (remaining > 0) {
                I_strncpyz(buf, val + sent, maxChunk + 1);
                SV_SendServerCommand(&svsPtr->clients[i], 1, "%c %i %s", cmd, index, buf);
                sent += maxChunk;
                remaining -= maxChunk;
                if (remaining <= 0)
                    break;
                if (sent != 0) {
                    cmd = (maxChunk >= remaining) ? 'z' : 'y';
                }
            }
        }
next:
        ;
    }
    }
}

/* line 208 */
void SV_SetConfigValueForKey(int start, int max, const char *key, const char *value)
{
    byte *sv;
    int i;
    char *cs;

    sv = (byte *)imp_sv;
    for (i = 0; i < max; i++) {
        cs = *(char **)(sv + SV_CONFIGSTRINGS_OFF + (start + i) * 4);
        if (*cs == '\0') {
            SV_SetConfigstring(start + i, key);
            break;
        }
        if (stricmp(key, cs) == 0)
            break;
    }
    if (i == max) {
        Com_Error(1, "SV_SetConfigValueForKey: overflow");
    }
    SV_SetConfigstring(start + max + i, value);
}

/* line 1390 */
void SV_Shutdown(char *finalmsg)
{
    int savedState;
    serverStatic_t *svs;
    int i, j;
    int maxclients;

    {
        byte *dvar = *(byte **)imp_com_sv_running;
        byte *dvarVal = *(byte **)dvar;
        if (!dvarVal || *(char *)(dvarVal + 8) == 0)
            return;
    }

    Com_Printf("----- Server Shutdown -----\n");

    savedState = *(int *)(byte *)imp_sv;

    svs = (serverStatic_t *)imp_svs;
    if (svs->clients) {
        for (j = 0; j < 2; j++) {
            maxclients = *(int *)(*(byte **)imp_sv_maxclients + 8);
            for (i = 0; i < maxclients; i++) {
                if (svs->clients[i].state <= 1)
                    goto next_client1;

                if (svs->clients[i].netchan.remoteAddress.type != 2) {
                    SV_SendServerCommand(&svs->clients[i], 0, "%c \"%s\"", 'e', finalmsg);
                    SV_SendServerCommand(&svs->clients[i], 1, "%c \"%s\"", 'w', finalmsg);
                }

                svs->clients[i].nextSnapshotTime = -1;
                SV_SendClientSnapshot(&svs->clients[i]);
next_client1:
                ;
            }
        }
    }

    SV_RemoveOperatorCommands();
    SV_MasterShutdown();
    SV_ShutdownGameProgs();

    /* SV_DropAllClients - line 1373 */
    svs = (serverStatic_t *)imp_svs;
    if (svs->clients != NULL && *(byte **)imp_sv_maxclients != NULL) {
        maxclients = *(int *)(*(byte **)imp_sv_maxclients + 8);
        for (i = 0; i < maxclients; i++) {
            if (svs->clients[i].state > 1) {
                SV_DropClient(&svs->clients[i], "EXE_DISCONNECTED");
            }
        }
    }

    /* SV_ClearServer - line 543 */
    {
        byte *svLocal = (byte *)imp_sv;
        byte *p = svLocal;
        byte *end = svLocal + 0x2000;
        while (p < end) {
            char *cs = *(char **)(p + SV_CONFIGSTRINGS_OFF);
            if (cs) {
                Z_FreeInternal(cs);
            }
            p += 4;
        }
        Com_Memset(svLocal, 0, 0x5f534);
    }

    /* Free clients */
    svs = (serverStatic_t *)imp_svs;
    if (svs->clients) {
        SV_FreeClients();
    }

    /* SV_FreeArchivedSnapshotBuffers - line 618 */
    if (svs->cachedSnapshotEntities) {
        Z_FreeInternal(svs->cachedSnapshotEntities);
        *(void **)&svs->cachedSnapshotEntities = 0;
    }
    if (svs->cachedSnapshotClients) {
        Z_FreeInternal(svs->cachedSnapshotClients);
        *(void **)&svs->cachedSnapshotClients = 0;
    }
    if (svs->archivedSnapshotFrames) {
        Z_FreeInternal(svs->archivedSnapshotFrames);
        *(void **)&svs->archivedSnapshotFrames = 0;
    }
    if (svs->archivedSnapshotBuffer) {
        Z_FreeInternal(svs->archivedSnapshotBuffer);
        svs->archivedSnapshotBuffer = 0;
    }
    if (svs->cachedSnapshotFrames) {
        Z_FreeInternal(svs->cachedSnapshotFrames);
        svs->cachedSnapshotFrames = 0;
    }

    /* SV_FreeServerStructure */
    memset(svs, 0, sizeof(serverStatic_t));

    /* If FX system exists, free it */
    {
        byte *dedicated = (byte *)imp_com_dedicated;
        if (*(int *)(*(byte **)dedicated + 8)) {
            FX_FreeSystem();
        }
    }

    Dvar_SetBool(*(dvar_t **)imp_com_sv_running, 0);
    Com_Printf("---------------------------\n");

    if (CL_GetLocalClientActive(0)) {
        CL_Disconnect();
    }

    if (savedState == 1) {
        Com_AbortDObj();
        DObjAbort();
        XAnimAbort();
        Scr_Abort();
        *(int *)imp_com_errorEntered = 0;
    }
}

/* line 365 */
void SV_Startup(void)
{
    serverStatic_t *svs;
    dvar_t *maxclients;
    int numClients;
    int isDedicated;

    svs = (serverStatic_t *)imp_svs;
    if (svs->initialized) {
        Com_Error(0, "SV_Startup: svs.initialized");
    }

    /* SV_InitMaxClients - line 325 */
    maxclients = Dvar_RegisterInt("sv_maxclients", 20, 1, 0x40, 0x1025);
    *(dvar_t **)imp_sv_maxclients = maxclients;
    Dvar_ClearModified(maxclients);

    maxclients = *(dvar_t **)imp_sv_maxclients;
    if (*(int *)((byte *)maxclients + 8) <= 0) {
        Dvar_SetInt(maxclients, 1);
        maxclients = *(dvar_t **)imp_sv_maxclients;
    }

    /* Allocate clients */
    numClients = *(int *)((byte *)maxclients + 8);
    svs->clients = Z_VirtualAllocInternal(numClients * sizeof(client_t));
    if (!svs->clients) {
        Com_Error(0, "SV_Startup: unable to allocate svs.clients");
    }

    /* Allocate snapshot entities */
    isDedicated = *(int *)((byte *)(void *)imp_com_dedicated + 8);
    maxclients = *(dvar_t **)imp_sv_maxclients;
    numClients = *(int *)((byte *)maxclients + 8);
    if (isDedicated) {
        svs->numSnapshotEntities = numClients << 11;
        svs->numSnapshotClients = numClients * numClients * 32;
    } else {
        svs->numSnapshotEntities = numClients << 8;
        svs->numSnapshotClients = numClients * numClients * 4;
    }

    svs->initialized = 1;
    Dvar_SetBool(*(dvar_t **)imp_com_sv_running, 1);
}

/* line 402 */
void SV_ChangeMaxClients(void)
{
    serverStatic_t *svs;
    int oldMaxClients;
    int minClients;
    client_t *oldClients;
    int i;
    dvar_t *maxclients;
    int numClients;
    int isDedicated;

    oldMaxClients = *(int *)(*(byte **)imp_sv_maxclients + 8);

    /* Find minimum required client count */
    if (oldMaxClients > 0) {
        svs = (serverStatic_t *)imp_svs;
        minClients = 0;
        for (i = 0; i < oldMaxClients; i++) {
            if (svs->clients[i].state > 1) {
                if (i > minClients)
                    minClients = i;
            }
        }
        minClients++;
    } else {
        minClients = 1;
    }

    /* Re-register sv_maxclients */
    maxclients = Dvar_RegisterInt("sv_maxclients", 20, 1, 0x40, 0x1025);
    *(dvar_t **)imp_sv_maxclients = maxclients;
    Dvar_ClearModified(maxclients);
    maxclients = *(dvar_t **)imp_sv_maxclients;
    if (*(int *)((byte *)maxclients + 8) < minClients) {
        Dvar_SetInt(maxclients, minClients);
        maxclients = *(dvar_t **)imp_sv_maxclients;
    }

    if (*(int *)((byte *)maxclients + 8) == oldMaxClients)
        return;

    /* Save old client data */
    oldClients = (client_t *)Hunk_AllocateTempMemoryInternal(minClients * sizeof(client_t));
    for (i = 0; i < minClients; i++) {
        svs = (serverStatic_t *)imp_svs;
        if (svs->clients[i].state > 1) {
            memcpy(&oldClients[i], &svs->clients[i], sizeof(client_t));
        } else {
            Com_Memset(&oldClients[i], 0, sizeof(client_t));
        }
    }

    /* Free old clients, allocate new */
    svs = (serverStatic_t *)imp_svs;
    Z_VirtualFreeInternal(svs->clients);

    numClients = *(int *)(*(byte **)imp_sv_maxclients + 8);
    svs->clients = Z_VirtualAllocInternal(numClients * sizeof(client_t));
    if (!svs->clients) {
        Com_Error(0, "SV_Startup: unable to allocate svs.clients");
    }

    /* Clear new clients */
    numClients = *(int *)(*(byte **)imp_sv_maxclients + 8);
    Com_Memset(svs->clients, 0, numClients * sizeof(client_t));

    /* Copy old client data to new */
    for (i = 0; i < minClients; i++) {
        if (oldClients[i].state > 1) {
            svs = (serverStatic_t *)imp_svs;
            memcpy(&svs->clients[i], &oldClients[i], sizeof(client_t));
        }
    }

    Hunk_FreeTempMemory(oldClients);

    /* Update snapshot entity counts */
    isDedicated = *(int *)((byte *)(void *)imp_com_dedicated + 8);
    numClients = *(int *)(*(byte **)imp_sv_maxclients + 8);
    svs = (serverStatic_t *)imp_svs;
    if (isDedicated) {
        svs->numSnapshotEntities = numClients << 11;
        svs->numSnapshotClients = numClients * numClients * 32;
    } else {
        svs->numSnapshotEntities = numClients << 8;
        svs->numSnapshotClients = numClients * numClients * 4;
    }
}

/* line 693 */
void SV_SpawnServer(const char *server)
{
    byte *sv;
    byte *svs;
    byte *client;
    int i;
    int maxclients;
    int checksum;
    char filename[64];
    int savepersist;
    char systemInfo[0x2000];
    int isDedicated;
    const char *s;
    byte *ent;
    netadr_t addr;

    Scr_ParseGameTypeList();
    SV_SetGametype();

    CL_InitLoad(server, (const char *)*(int *)(*(byte **)imp_sv_gametype + 8));

    /* Check if server is running - save/notify clients */
    if (*(char *)(*(byte **)imp_com_sv_running + 8)) {
        savepersist = (int)G_GetSavePersist();

        /* Notify connected clients about map change */
        {
        serverStatic_t *svsPtr = (serverStatic_t *)imp_svs;
        maxclients = *(int *)(*(byte **)imp_sv_maxclients + 8);
        for (i = 0; i < maxclients; i++) {
            if (svsPtr->clients[i].state > 2) {
                Com_sprintf(filename, 64, "loadingnewmap\n%s\n%s",
                    server, (const char *)*(int *)(*(byte **)imp_sv_gametype + 8));
                addr = svsPtr->clients[i].netchan.remoteAddress;
                NET_OutOfBandPrint(1, addr, filename);
            }
        }
        }
        NET_Sleep(250);
    } else {
        savepersist = 0;
    }

    Dvar_SetStringByName("mapname", server);
    CL_MapLoading(server);
    CL_ShutdownAll();
    SV_ShutdownGameProgs();

    Com_Printf("------ Server Initialization ------\n");
    Com_Printf("Server: %s\n", server);

    /* SV_ClearServer */
    sv = (byte *)imp_sv;
    {
        byte *p = sv;
        byte *end = sv + 0x2000;
        while (p < end) {
            char *cs = *(char **)(p + SV_CONFIGSTRINGS_OFF);
            if (cs) {
                Z_FreeInternal(cs);
            }
            p += 4;
        }
        Com_Memset(sv, 0, 0x5f534);
    }

    /* Free FX system if dedicated */
    isDedicated = *(int *)((byte *)(void *)imp_com_dedicated + 8);
    if (isDedicated) {
        FX_FreeSystem();
    }

    FS_Shutdown(1);
    FS_ClearIwdReferences();
    Com_Restart();

    if (*(char *)(*(byte **)imp_com_sv_running + 8)) {
        SV_ChangeMaxClients();
    } else {
        SV_Startup();
    }

    /* Set gametype configstring */
    I_strncpyz((char *)((byte *)imp_sv + SV_GAMETYPE_OFF),
        (const char *)*(int *)(*(byte **)imp_sv_gametype + 8), 64);

    /* Generate checksumFeed */
    srand(Sys_MillisecondsRaw());
    {
        int r1 = rand();
        int r2 = rand();
        int ms = Sys_Milliseconds();
        int checksumFeed = (r1 << 16) ^ r2 ^ ms;
        sv = (byte *)imp_sv;
        *(int *)(sv + SV_SERVERID_OFF) = checksumFeed;
        FS_Restart(checksumFeed);
    }

    /* Load BSP */
    {
        const char *ext = GetBspExtension();
        Com_sprintf(filename, 64, "maps/mp/%s.%s", server, ext);
    }
    SV_SetExpectedHunkUsage(filename);
    CL_StartLoading(server, (char *)((byte *)imp_sv + SV_GAMETYPE_OFF));

    /* Re-preload shader text: CL_ShutdownAll → R_Shutdown → Material_Shutdown
       clears the shader hash table, and Hunk_Clear frees the shader text cache.
       CL_StartLoading → CL_StartHunkUsers re-inits the renderer, but the
       shader text cache may not be reloaded by that path. Ensure it is
       available before any material loading. */
    {
        extern unsigned char mtlLoadGlob[];
        if (*(int *)mtlLoadGlob == 0)
            Material_PreLoadAllShaderText();
    }

    /* Initialize configstrings */
    sv = (byte *)imp_sv;
    {
        byte *p = sv;
        byte *end = sv + 0x2000;
        while (p < end) {
            *(char **)(p + SV_CONFIGSTRINGS_OFF) = CopyStringInternal("");
            p += 4;
        }
    }

    /* SV_InitDvar */
    Dvar_ResetScriptInfo();

    /* Allocate snapshot buffers */
    {
        serverStatic_t *svsPtr = (serverStatic_t *)imp_svs;
        int numSnapEnts = svsPtr->numSnapshotEntities;
        svsPtr->snapshotEntities = Hunk_AllocInternal((numSnapEnts * 256) - (numSnapEnts * 16));
        svsPtr->nextSnapshotEntities = 0;
        {
            int numSnapClients = svsPtr->numSnapshotClients;
            *(void **)&svsPtr->snapshotClients = Hunk_AllocInternal(numSnapClients * 92);
        }
        svsPtr->nextSnapshotClients = 0;

        /* SV_InitArchivedSnapshot */
        svsPtr->archiveEnabled = 0;
        svsPtr->nextArchivedSnapshotFrames = 0;
        svsPtr->nextArchivedSnapshotBuffer = 0;
        svsPtr->nextCachedSnapshotEntities = 0;
        svsPtr->nextCachedSnapshotClients = 0;
        svsPtr->nextCachedSnapshotFrames = 0;

        /* Toggle snap flag bit */
        svsPtr->snapFlagServerBit ^= 4;
    }

    /* Set "nextmap" dvar */
    Dvar_SetString(*(dvar_t **)&nextmap, "map_restart");

    /* Clear a dvar */
    Dvar_SetInt(*(dvar_t **)imp_cl_paused, 0);

    /* Load map */
    {
        const char *ext = GetBspExtension();
        Com_sprintf(filename, 64, "maps/mp/%s.%s", server, ext);
    }
    { extern void DBG_Hunk_PrintUsage(const char *); DBG_Hunk_PrintUsage("SV: before CM_LoadMap"); }
    Com_LoadBsp(filename);
    CM_LoadMap(filename, &checksum);
    Com_UnloadBsp();
    CM_LinkWorld();
    { extern void DBG_Hunk_PrintUsage(const char *); DBG_Hunk_PrintUsage("SV: after CM_LoadMap"); }

    /* Update serverId */
    sv_serverId_value = (sv_serverId_value + 16) & 0xff;
    if (!(sv_serverId_value & 0xf0))
        sv_serverId_value += 16;
    Dvar_SetInt(*(dvar_t **)imp_sv_serverid, sv_serverId_value);

    /* Set server state and checksumFeed */
    sv = (byte *)imp_sv;
    *(int *)(sv + SV_CHECKSUM_OFF) = *(int *)((byte *)imp_com_frameTime + 8);
    *(int *)(sv + SV_STATE_OFF) = 1;

    /* Load sound aliases */
    {
        const char *ext = GetBspExtension();
        Com_sprintf(filename, 64, "maps/mp/%s.%s", server, ext);
    }
    Com_LoadSoundAliases(filename, "all_mp", 2);

    /* Init game progs */
    { extern void DBG_Hunk_PrintUsage(const char *); DBG_Hunk_PrintUsage("SV: before SV_InitGameProgs"); }
    SV_InitGameProgs(savepersist);

    /* Init FX system */
    isDedicated = *(int *)((byte *)(void *)imp_com_dedicated + 8);
    if (isDedicated) {
        FX_InitSystem(0);
        FX_CreateDefaultEffect();
    }

    /* Run a few frames */
    for (i = 0; i < 3; i++) {
        ((serverStatic_t *)imp_svs)->time += 100;
        SV_RunFrame();
    }

    /* SV_SetEntsBaselines - line 291 */
    sv = (byte *)imp_sv;
    if (*(int *)(sv + SV_NUMENTITIES_OFF) > 1) {
        byte *basePtr = sv;
        for (i = 1; i < *(int *)((byte *)imp_sv + SV_NUMENTITIES_OFF); i++) {
            int entOff;
            byte *dest;

            {
            gentity_t *gent = (gentity_t *)SV_GentityNum(i);
            if (gent->r.linked == 0) {
                sv = (byte *)imp_sv;
                goto next_baseline;
            }

            /* Set entity number */
            gent->s.number = i;

            /* Copy entity state to baseline */
            memcpy(basePtr + 0x2590, &gent->s, sizeof(entityState_t));
            *(int *)(basePtr + 0x2680) = (unsigned char)gent->r.svFlags; /* svFlags at offset 0x2680 in svEntity-like baseline buffer */
            *(int *)(basePtr + 0x2684) = gent->r.clientMask[0]; /* clientMask[0] at offset 0x2684 */
            *(int *)(basePtr + 0x2688) = gent->r.clientMask[1]; /* clientMask[1] at offset 0x2688 */

            /* Copy origin (absmin) */
            entOff = i * 0x174;
            sv = (byte *)imp_sv;
            dest = sv + entOff + 0x2500 + 0x18;
            *(float *)dest = gent->r.absmin[0];
            *(int *)(dest + 4) = *(int *)&gent->r.absmin[1];
            *(int *)(dest + 8) = *(int *)&gent->r.absmin[2];

            /* Copy angles (absmax) */
            dest = sv + entOff + 0x2510 + 0x14;
            *(int *)dest = *(int *)&gent->r.absmax[0];
            *(int *)(dest + 4) = *(int *)&gent->r.absmax[1];
            *(int *)(dest + 8) = *(int *)&gent->r.absmax[2];
            }
next_baseline:
            basePtr += 0x174;
        }
    }

    /* Reconnect clients - line 980 */
    {
    serverStatic_t *svsPtr = (serverStatic_t *)imp_svs;
    maxclients = *(int *)(*(byte **)imp_sv_maxclients + 8);
    for (i = 0; i < maxclients; i++) {
        if (svsPtr->clients[i].state <= 1)
            continue;

        s = ClientConnect(i, svsPtr->clients[i].scriptId);
        if (s) {
            SV_DropClient(&svsPtr->clients[i], s);
        } else {
            svsPtr->clients[i].state = 2;
        }
    }
    }

    /* Set IWD references */
    if (*(char *)(*(byte **)imp_sv_pure + 8)) {
        s = FS_LoadedIwdChecksums();
        Dvar_SetString(*(dvar_t **)imp_sv_iwds, s);
        if (*s == '\0') {
            Com_Printf("WARNING: sv_pure set but no IWD files loaded\n");
        }
        s = FS_LoadedIwdNames();
        Dvar_SetString(*(dvar_t **)imp_sv_iwdNames, s);
    } else {
        Dvar_SetString(*(dvar_t **)imp_sv_iwds, "");
        Dvar_SetString(*(dvar_t **)imp_sv_iwdNames, "");
    }

    s = FS_ReferencedIwdChecksums();
    Dvar_SetString(*(dvar_t **)imp_sv_referencedIwds, s);
    s = FS_ReferencedIwdNames();
    Dvar_SetString(*(dvar_t **)imp_sv_referencedIwdNames, s);

    /* SV_SetConfigValuesForServerInfo */
    {
        char *info = Dvar_InfoString_Big(8);
        I_strncpyz(systemInfo, info, 0x2000);
        *(int *)imp_dvar_modifiedFlags &= ~8;
        SV_SetConfigstring(1, systemInfo);
        info = Dvar_InfoString(0x404);
        SV_SetConfigstring(0, info);
        *(int *)imp_dvar_modifiedFlags &= ~0x404;
        SV_SetConfig(0x8e, 0x60, 0x100);
        *(int *)imp_dvar_modifiedFlags &= ~0x100;
    }

    /* Server is ready */
    *(int *)((byte *)imp_sv + SV_STATE_OFF) = 2;
    SV_Heartbeat_f();

    Com_Printf("-----------------------------------\n");
}
