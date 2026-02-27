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

extern byte *sv_ptr;               /* 0x195ee80 - server_t */
extern byte *svs_ptr;              /* 0x195f284 - serverStatic_t */
extern byte *sv_maxclients_dvar;   /* 0x195f290 */
extern byte *sv_gametype_dvar;     /* 0x195f29c */
extern byte *sv_dedicated_dvar;    /* 0x195ec98 */
extern byte *sv_running_dvar;      /* 0x195ecbc */
extern byte *sv_serverid_dvar;     /* 0x195f294 */
extern byte *sv_expectedHunkUsage_dvar; /* 0x195f2fc */
extern byte *sv_mapname_dvar;      /* 0x195f300 */
extern byte *sv_privateClients_dvar;/* 0x195f2c0 */
extern byte *sv_hostname_dvar;     /* 0x195f2b8 */
extern byte *sv_maxRate_dvar;      /* 0x195f268 */
extern byte *sv_minPing_dvar;      /* 0x195f2e8 */
extern byte *sv_maxPing_dvar;      /* 0x195f298 */
extern byte *sv_floodProtect_dvar; /* 0x195f2dc */
extern byte *sv_allowAnonymous_dvar;/* 0x195f26c */
extern byte *sv_showCommands_dvar; /* 0x195f2cc */
extern byte *sv_disableClientConsole_dvar; /* 0x195f264 */
extern byte *sv_voice_dvar;        /* 0x195f2a4 */
extern byte *sv_voiceQuality_dvar; /* 0x195f2d0 */
extern byte *sv_cheats_dvar;       /* 0x195ef54 */
extern byte *sv_pure_dvar;         /* 0x195f2e0 */
extern byte *sv_iwds_dvar;         /* 0x195f28c */
extern byte *sv_iwdNames_dvar;     /* 0x195f270 */
extern byte *sv_referencedIwds_dvar;/* 0x195f2d4 */
extern byte *sv_referencedIwdNames_dvar; /* 0x195f2c4 */
extern byte *rcon_password_dvar;   /* 0x195f2f4 */
extern byte *sv_privatePassword_dvar; /* 0x195f280 */
extern byte *sv_fps_dvar;          /* 0x195f2f8 */
extern byte *sv_timeout_dvar;      /* 0x195f2e4 */
extern byte *sv_zombietime_dvar;   /* 0x195f2c8 */
extern byte *sv_allowDownload_dvar;/* 0x195f2b4 */
extern byte *sv_reconnectlimit_dvar; /* 0x195f2a0 */
extern byte *sv_padPackets_dvar;   /* 0x195f2b0 */
extern byte *sv_allowedClan1_dvar; /* 0x195f27c */
extern byte *sv_allowedClan2_dvar; /* 0x195f274 */
extern byte *sv_packet_info_dvar;  /* 0x195f2a8 */
extern byte *sv_showAverageBPS_dvar; /* 0x195f288 */
extern byte *sv_kickBanTime_dvar;  /* 0x195f2f0 */
extern byte *sv_mapRotation_dvar;  /* 0x195f2ec */
extern byte *sv_mapRotationCurrent_dvar; /* 0x195f2ac */
extern byte *sv_debugRate_dvar;    /* 0x195f2bc */
extern byte *sv_debugReliableCmds_dvar; /* 0x195f278 */
extern byte *nextmap_dvar;         /* 0x195ee88 */
extern byte *com_dvarflags_ptr;    /* 0x195ec9c */
extern byte *com_checksumFeed_dvar; /* 0x195f2d8 */
extern byte *com_errorEntered_ptr; /* 0x195edb4 */
extern byte *sv_dedicated_dvar2;   /* 0x195ec98 */
extern byte *sv_com_dvarDump_ptr;  /* 0x195ed18 */

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
    byte *sv = *(byte **)&sv_ptr;
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

    sv = *(byte **)&sv_ptr;
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

    sv = *(byte **)&sv_ptr;
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

    if (index < 0 || index >= *(int *)(*(byte **)&sv_maxclients_dvar + 8)) {
        Com_Error(1, "SV_SetUserinfo: bad index %i\n", index);
    }

    if (!val)
        val = "";

    svs = *(byte **)&svs_ptr;
    client = *(byte **)(svs + SVS_CLIENTS_OFF) + index * CLIENT_SIZE;

    I_strncpyz((char *)(client + CLIENT_USERINFO_OFF), val, 0x400);
    name = (const char *)Info_ValueForKey(val, "name");
    I_strncpyz((char *)(client + CLIENT_NAME_OFF), name, 0x20);
}

/* line 263 */
void SV_GetUserinfo(int index, char *buffer, int bufferSize)
{
    byte *svs;
    byte *client;

    if (bufferSize <= 0) {
        Com_Error(1, "SV_GetUserinfo: bufferSize == %i", bufferSize);
    }
    if (index < 0 || index >= *(int *)(*(byte **)&sv_maxclients_dvar + 8)) {
        Com_Error(1, "SV_GetUserinfo: bad index %i\n", index);
    }

    svs = *(byte **)&svs_ptr;
    client = *(byte **)(svs + SVS_CLIENTS_OFF) + index * CLIENT_SIZE;

    I_strncpyz(buffer, (const char *)(client + CLIENT_USERINFO_OFF), bufferSize);
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
            Dvar_SetInt(*(dvar_t **)&sv_expectedHunkUsage_dvar, atoi(token));
            Z_FreeInternal(buf);
            return;
        }
    }
}

/* line 564 */
void SV_EnableArchivedSnapshot(qboolean bEnable)
{
    byte *svs;

    svs = *(byte **)&svs_ptr;
    *(int *)(svs + SVS_ARCHSNAP_ENABLED_OFF) = bEnable;

    if (!bEnable)
        return;
    if (*(int *)(svs + SVS_ARCHSNAP_FRAMES_OFF))
        return;

    *(void **)(svs + SVS_ARCHSNAP_48_OFF) = Z_MallocInternal(0x450000);
    *(void **)(svs + SVS_ARCHSNAP_4C_OFF) = Z_MallocInternal(0x2708000);
    *(void **)(svs + SVS_ARCHSNAP_FRAMES_OFF) = Z_MallocInternal(0x2580);
    *(void **)(svs + SVS_ARCHSNAP_BUFFER_OFF) = Z_MallocInternal(0x2000000);
    *(void **)(svs + SVS_ARCHSNAP_50_OFF) = Z_MallocInternal(0x3800);
}

/* line 599 */
void SV_InitArchivedSnapshot(void)
{
    byte *svs;

    svs = *(byte **)&svs_ptr;
    *(int *)(svs + SVS_ARCHSNAP_ENABLED_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_2C_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_38_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_3C_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_40_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_44_OFF) = 0;
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

    *(dvar_t **)&sv_gametype_dvar = Dvar_RegisterString("g_gametype", "dm", 0x1024);
    Dvar_RegisterString("sv_keywords", "", 0x1004);
    Dvar_RegisterInt("protocol", 0x73, 0x73, 0x73, 0x1044);
    *(dvar_t **)&sv_mapname_dvar = Dvar_RegisterString("mapname", "", 0x1044);
    *(dvar_t **)&sv_privateClients_dvar = Dvar_RegisterInt("sv_privateClients", 0, 0, 0x40, 0x1004);
    *(dvar_t **)&sv_maxclients_dvar = Dvar_RegisterInt("sv_maxclients", 20, 1, 0x40, 0x1025);
    *(dvar_t **)&sv_hostname_dvar = Dvar_RegisterString("sv_hostname", "CoD2Host", 0x1005);
    *(dvar_t **)&sv_maxRate_dvar = Dvar_RegisterInt("sv_maxRate", 0, 0, 25000, 0x1005);
    *(dvar_t **)&sv_minPing_dvar = Dvar_RegisterInt("sv_minPing", 0, 0, 999, 0x1005);
    *(dvar_t **)&sv_maxPing_dvar = Dvar_RegisterInt("sv_maxPing", 0, 0, 999, 0x1005);
    *(dvar_t **)&sv_floodProtect_dvar = Dvar_RegisterBool("sv_floodProtect", 1, 0x1005);
    *(dvar_t **)&sv_allowAnonymous_dvar = Dvar_RegisterBool("sv_allowAnonymous", 0, 0x1004);
    *(dvar_t **)&sv_showCommands_dvar = Dvar_RegisterBool("sv_showCommands", 0, (int)&__mh_execute_header);
    *(dvar_t **)&sv_disableClientConsole_dvar = Dvar_RegisterBool("sv_disableClientConsole", 0, 0x1008);
    *(dvar_t **)&sv_voice_dvar = Dvar_RegisterBool("sv_voice", 0, 0x100d);
    *(dvar_t **)&sv_voiceQuality_dvar = Dvar_RegisterInt("sv_voiceQuality", 1, 0, 9, 0x1008);
    *(dvar_t **)&sv_cheats_dvar = Dvar_RegisterBool("sv_cheats", 0, 0x1018);
    *(dvar_t **)&sv_serverid_dvar = Dvar_RegisterInt("sv_serverid", 0, (int)0x80000000, 0x7fffffff, 0x1048);
    *(dvar_t **)&sv_pure_dvar = Dvar_RegisterBool("sv_pure", 1, 0x100c);
    *(dvar_t **)&sv_iwds_dvar = Dvar_RegisterString("sv_iwds", "", 0x1048);
    *(dvar_t **)&sv_iwdNames_dvar = Dvar_RegisterString("sv_iwdNames", "", 0x1048);
    *(dvar_t **)&sv_referencedIwds_dvar = Dvar_RegisterString("sv_referencedIwds", "", 0x1048);
    *(dvar_t **)&sv_referencedIwdNames_dvar = Dvar_RegisterString("sv_referencedIwdNames", "", 0x1048);
    *(dvar_t **)&rcon_password_dvar = Dvar_RegisterString("rcon_password", "", (int)&__mh_execute_header);
    *(dvar_t **)&sv_privatePassword_dvar = Dvar_RegisterString("sv_privatePassword", "", (int)&__mh_execute_header);
    *(dvar_t **)&sv_fps_dvar = Dvar_RegisterInt("sv_fps", 20, 10, 1000, (int)&__mh_execute_header);
    *(dvar_t **)&sv_timeout_dvar = Dvar_RegisterInt("sv_timeout", 240, 0, 1800, (int)&__mh_execute_header);
    *(dvar_t **)&sv_zombietime_dvar = Dvar_RegisterInt("sv_zombietime", 2, 0, 1800, (int)&__mh_execute_header);
    *(dvar_t **)&sv_allowDownload_dvar = Dvar_RegisterBool("sv_allowDownload", 1, 0x1001);
    *(dvar_t **)&sv_reconnectlimit_dvar = Dvar_RegisterInt("sv_reconnectlimit", 3, 0, 1800, 0x1001);
    *(dvar_t **)&sv_padPackets_dvar = Dvar_RegisterInt("sv_padPackets", 0, 0, 0x7fffffff, (int)&__mh_execute_header);

    /* line 1273 */
    {
        byte *svDedicated = *(byte **)&sv_dedicated_dvar2;
        byte *dvar = *(byte **)svDedicated;
        *(char *)(dvar + 0xdd) = 0;
    }

    *(dvar_t **)&sv_allowedClan1_dvar = Dvar_RegisterString("sv_allowedClan1", "", (int)&__mh_execute_header);
    *(dvar_t **)&sv_allowedClan2_dvar = Dvar_RegisterString("sv_allowedClan2", "", (int)&__mh_execute_header);
    *(dvar_t **)&sv_packet_info_dvar = Dvar_RegisterBool("sv_packet_info", 0, (int)&__mh_execute_header);
    *(dvar_t **)&sv_showAverageBPS_dvar = Dvar_RegisterBool("sv_showAverageBPS", 0, (int)&__mh_execute_header);
    *(dvar_t **)&sv_kickBanTime_dvar = Dvar_RegisterFloat("sv_kickBanTime", 300.0f, 0.0f, 3600.0f, (int)&__mh_execute_header);
    *(dvar_t **)&sv_mapRotation_dvar = Dvar_RegisterString("sv_mapRotation", "", (int)&__mh_execute_header);
    *(dvar_t **)&sv_mapRotationCurrent_dvar = Dvar_RegisterString("sv_mapRotationCurrent", "", (int)&__mh_execute_header);
    *(dvar_t **)&sv_debugRate_dvar = Dvar_RegisterBool("sv_debugRate", 0, (int)&__mh_execute_header);
    *(dvar_t **)&sv_debugReliableCmds_dvar = Dvar_RegisterBool("sv_debugReliableCmds", 0, (int)&__mh_execute_header);
    *(dvar_t **)&nextmap_dvar = Dvar_RegisterString("nextmap", "", (int)&__mh_execute_header);
    *(dvar_t **)&sv_expectedHunkUsage_dvar = Dvar_RegisterInt("com_expectedHunkUsage", 0, 0, 0x7fffffff, 0x1040);
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

    sv = *(byte **)&sv_ptr;
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

    client = *(byte **)(*(byte **)&svs_ptr + SVS_CLIENTS_OFF);
    for (i = 0; i < *(int *)(*(byte **)&sv_maxclients_dvar + 8); i++) {
        if (*(int *)(client + CLIENT_STATE_OFF) <= 2)
            goto next;

        if (len <= maxChunk) {
            SV_SendServerCommand(client, 1, "%c %i %s", 'd', index, val);
        } else {
            remaining = len;
            sent = 0;
            cmd = 'x';
            while (remaining > 0) {
                I_strncpyz(buf, val + sent, maxChunk + 1);
                SV_SendServerCommand(client, 1, "%c %i %s", cmd, index, buf);
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
        client += CLIENT_SIZE;
    }
}

/* line 208 */
void SV_SetConfigValueForKey(int start, int max, const char *key, const char *value)
{
    byte *sv;
    int i;
    char *cs;

    sv = *(byte **)&sv_ptr;
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
    byte *svs;
    byte *client;
    int i, j;
    int maxclients;

    {
        byte *dvar = *(byte **)&sv_running_dvar;
        byte *dvarVal = *(byte **)dvar;
        if (!dvarVal || *(char *)(dvarVal + 8) == 0)
            return;
    }

    Com_Printf("----- Server Shutdown -----\n");

    savedState = *(int *)*(byte **)&sv_ptr;

    svs = *(byte **)&svs_ptr;
    if (*(byte **)(svs + SVS_CLIENTS_OFF)) {
        for (j = 0; j < 2; j++) {
            client = *(byte **)(svs + SVS_CLIENTS_OFF);
            maxclients = *(int *)(*(byte **)&sv_maxclients_dvar + 8);
            for (i = 0; i < maxclients; i++) {
                if (*(int *)(client + CLIENT_STATE_OFF) <= 1)
                    goto next_client1;

                if (*(int *)(client + CLIENT_NETCHAN_STATE_OFF) != 2) {
                    SV_SendServerCommand(client, 0, "%c \"%s\"", 'e', finalmsg);
                    SV_SendServerCommand(client, 1, "%c \"%s\"", 'w', finalmsg);
                }

                *(int *)(client + 0x20d18) = -1;
                SV_SendClientSnapshot(client);
next_client1:
                client += CLIENT_SIZE;
            }
        }
    }

    SV_RemoveOperatorCommands();
    SV_MasterShutdown();
    SV_ShutdownGameProgs();

    /* SV_DropAllClients - line 1373 */
    client = *(byte **)(*(byte **)&svs_ptr + SVS_CLIENTS_OFF);
    maxclients = *(int *)(*(byte **)&sv_maxclients_dvar + 8);
    for (i = 0; i < maxclients; i++) {
        if (*(int *)(client + CLIENT_STATE_OFF) > 1) {
            SV_DropClient(client, "EXE_DISCONNECTED");
        }
        client += CLIENT_SIZE;
    }

    /* SV_ClearServer - line 543 */
    {
        byte *svLocal = *(byte **)&sv_ptr;
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
    svs = *(byte **)&svs_ptr;
    if (*(byte **)(svs + SVS_CLIENTS_OFF)) {
        SV_FreeClients();
    }

    /* SV_FreeArchivedSnapshotBuffers - line 618 */
    if (*(void **)(svs + SVS_ARCHSNAP_48_OFF)) {
        Z_FreeInternal(*(void **)(svs + SVS_ARCHSNAP_48_OFF));
        *(void **)(svs + SVS_ARCHSNAP_48_OFF) = 0;
    }
    if (*(void **)(svs + SVS_ARCHSNAP_4C_OFF)) {
        Z_FreeInternal(*(void **)(svs + SVS_ARCHSNAP_4C_OFF));
        *(void **)(svs + SVS_ARCHSNAP_4C_OFF) = 0;
    }
    if (*(void **)(svs + SVS_ARCHSNAP_FRAMES_OFF)) {
        Z_FreeInternal(*(void **)(svs + SVS_ARCHSNAP_FRAMES_OFF));
        *(void **)(svs + SVS_ARCHSNAP_FRAMES_OFF) = 0;
    }
    if (*(void **)(svs + SVS_ARCHSNAP_BUFFER_OFF)) {
        Z_FreeInternal(*(void **)(svs + SVS_ARCHSNAP_BUFFER_OFF));
        *(void **)(svs + SVS_ARCHSNAP_BUFFER_OFF) = 0;
    }
    if (*(void **)(svs + SVS_ARCHSNAP_50_OFF)) {
        Z_FreeInternal(*(void **)(svs + SVS_ARCHSNAP_50_OFF));
        *(void **)(svs + SVS_ARCHSNAP_50_OFF) = 0;
    }

    /* SV_FreeServerStructure */
    memset(svs, 0, 0xa0f8);

    /* If FX system exists, free it */
    {
        byte *dedicated = *(byte **)&sv_dedicated_dvar2;
        if (*(int *)(*(byte **)dedicated + 8)) {
            FX_FreeSystem();
        }
    }

    Dvar_SetBool(*(dvar_t **)&sv_running_dvar, 0);
    Com_Printf("---------------------------\n");

    if (CL_GetLocalClientActive(0)) {
        CL_Disconnect();
    }

    if (savedState == 1) {
        Com_AbortDObj();
        DObjAbort();
        XAnimAbort();
        Scr_Abort();
        *(int *)*(byte **)&com_errorEntered_ptr = 0;
    }
}

/* line 365 */
void SV_Startup(void)
{
    byte *svs;
    dvar_t *maxclients;
    int numClients;
    int isDedicated;

    svs = *(byte **)&svs_ptr;
    if (*(int *)(svs + SVS_INITIALIZED_OFF)) {
        Com_Error(0, "SV_Startup: svs.initialized");
    }

    /* SV_InitMaxClients - line 325 */
    maxclients = Dvar_RegisterInt("sv_maxclients", 20, 1, 0x40, 0x1025);
    *(dvar_t **)&sv_maxclients_dvar = maxclients;
    Dvar_ClearModified(maxclients);

    maxclients = *(dvar_t **)&sv_maxclients_dvar;
    if (*(int *)((byte *)maxclients + 8) <= 0) {
        Dvar_SetInt(maxclients, 1);
        maxclients = *(dvar_t **)&sv_maxclients_dvar;
    }

    /* Allocate clients */
    numClients = *(int *)((byte *)maxclients + 8);
    *(void **)(svs + SVS_CLIENTS_OFF) = Z_VirtualAllocInternal(numClients * CLIENT_SIZE);
    if (!*(void **)(svs + SVS_CLIENTS_OFF)) {
        Com_Error(0, "SV_Startup: unable to allocate svs.clients");
    }

    /* Allocate snapshot entities */
    isDedicated = *(int *)(*(byte **)&sv_dedicated_dvar2 + 8);
    maxclients = *(dvar_t **)&sv_maxclients_dvar;
    numClients = *(int *)((byte *)maxclients + 8);
    if (isDedicated) {
        *(int *)(svs + SVS_NUMSNAPENTS_OFF) = numClients << 11;
        *(int *)(svs + SVS_NUMSNAPCLIENTS_OFF) = numClients * numClients * 32;
    } else {
        *(int *)(svs + SVS_NUMSNAPENTS_OFF) = numClients << 8;
        *(int *)(svs + SVS_NUMSNAPCLIENTS_OFF) = numClients * numClients * 4;
    }

    *(int *)(svs + SVS_INITIALIZED_OFF) = 1;
    Dvar_SetBool(*(dvar_t **)&sv_running_dvar, 1);
}

/* line 402 */
void SV_ChangeMaxClients(void)
{
    byte *svs;
    int oldMaxClients;
    int minClients;
    byte *oldClients;
    byte *client;
    int i;
    dvar_t *maxclients;
    int numClients;
    int isDedicated;

    oldMaxClients = *(int *)(*(byte **)&sv_maxclients_dvar + 8);

    /* Find minimum required client count */
    if (oldMaxClients > 0) {
        svs = *(byte **)&svs_ptr;
        client = *(byte **)(svs + SVS_CLIENTS_OFF);
        minClients = 0;
        for (i = 0; i < oldMaxClients; i++) {
            if (*(int *)(client + CLIENT_STATE_OFF) > 1) {
                if (i > minClients)
                    minClients = i;
            }
            client += CLIENT_SIZE;
        }
        minClients++;
    } else {
        minClients = 1;
    }

    /* Re-register sv_maxclients */
    maxclients = Dvar_RegisterInt("sv_maxclients", 20, 1, 0x40, 0x1025);
    *(dvar_t **)&sv_maxclients_dvar = maxclients;
    Dvar_ClearModified(maxclients);
    maxclients = *(dvar_t **)&sv_maxclients_dvar;
    if (*(int *)((byte *)maxclients + 8) < minClients) {
        Dvar_SetInt(maxclients, minClients);
        maxclients = *(dvar_t **)&sv_maxclients_dvar;
    }

    if (*(int *)((byte *)maxclients + 8) == oldMaxClients)
        return;

    /* Save old client data */
    oldClients = (byte *)Hunk_AllocateTempMemoryInternal(minClients * CLIENT_SIZE);
    for (i = 0; i < minClients; i++) {
        svs = *(byte **)&svs_ptr;
        client = *(byte **)(svs + SVS_CLIENTS_OFF) + i * CLIENT_SIZE;
        if (*(int *)(client + CLIENT_STATE_OFF) > 1) {
            memcpy(oldClients + i * CLIENT_SIZE, client, CLIENT_SIZE);
        } else {
            Com_Memset(oldClients + i * CLIENT_SIZE, 0, CLIENT_SIZE);
        }
    }

    /* Free old clients, allocate new */
    svs = *(byte **)&svs_ptr;
    Z_VirtualFreeInternal(*(void **)(svs + SVS_CLIENTS_OFF));

    numClients = *(int *)(*(byte **)&sv_maxclients_dvar + 8);
    *(void **)(svs + SVS_CLIENTS_OFF) = Z_VirtualAllocInternal(numClients * CLIENT_SIZE);
    if (!*(void **)(svs + SVS_CLIENTS_OFF)) {
        Com_Error(0, "SV_Startup: unable to allocate svs.clients");
    }

    /* Clear new clients */
    numClients = *(int *)(*(byte **)&sv_maxclients_dvar + 8);
    Com_Memset(*(void **)(*(byte **)&svs_ptr + SVS_CLIENTS_OFF), 0, numClients * CLIENT_SIZE);

    /* Copy old client data to new */
    for (i = 0; i < minClients; i++) {
        if (*(int *)(oldClients + i * CLIENT_SIZE) > 1) {
            svs = *(byte **)&svs_ptr;
            memcpy(*(byte **)(svs + SVS_CLIENTS_OFF) + i * CLIENT_SIZE,
                   oldClients + i * CLIENT_SIZE, CLIENT_SIZE);
        }
    }

    Hunk_FreeTempMemory(oldClients);

    /* Update snapshot entity counts */
    isDedicated = *(int *)(*(byte **)&sv_dedicated_dvar2 + 8);
    numClients = *(int *)(*(byte **)&sv_maxclients_dvar + 8);
    svs = *(byte **)&svs_ptr;
    if (isDedicated) {
        *(int *)(svs + SVS_NUMSNAPENTS_OFF) = numClients << 11;
        *(int *)(svs + SVS_NUMSNAPCLIENTS_OFF) = numClients * numClients * 32;
    } else {
        *(int *)(svs + SVS_NUMSNAPENTS_OFF) = numClients << 8;
        *(int *)(svs + SVS_NUMSNAPCLIENTS_OFF) = numClients * numClients * 4;
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

    CL_InitLoad(server, (const char *)*(int *)(*(byte **)&sv_gametype_dvar + 8));

    /* Check if server is running - save/notify clients */
    if (*(char *)(*(byte **)*(byte **)&sv_running_dvar + 8)) {
        savepersist = (int)G_GetSavePersist();

        /* Notify connected clients about map change */
        svs = *(byte **)&svs_ptr;
        client = *(byte **)(svs + SVS_CLIENTS_OFF);
        maxclients = *(int *)(*(byte **)&sv_maxclients_dvar + 8);
        for (i = 0; i < maxclients; i++) {
            if (*(int *)(client + CLIENT_STATE_OFF) > 2) {
                Com_sprintf(filename, 64, "loadingnewmap\n%s\n%s",
                    server, (const char *)*(int *)(*(byte **)&sv_gametype_dvar + 8));
                addr = *(netadr_t *)(client + CLIENT_NETCHAN_STATE_OFF);
                NET_OutOfBandPrint(1, addr, filename);
            }
            client += CLIENT_SIZE;
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
    sv = *(byte **)&sv_ptr;
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
    isDedicated = *(int *)(*(byte **)&sv_dedicated_dvar2 + 8);
    if (isDedicated) {
        FX_FreeSystem();
    }

    FS_Shutdown(1);
    FS_ClearIwdReferences();
    Com_Restart();

    if (*(char *)(*(byte **)*(byte **)&sv_running_dvar + 8)) {
        SV_ChangeMaxClients();
    } else {
        SV_Startup();
    }

    /* Set gametype configstring */
    I_strncpyz((char *)(*(byte **)&sv_ptr + SV_GAMETYPE_OFF),
        (const char *)*(int *)(*(byte **)&sv_gametype_dvar + 8), 64);

    /* Generate checksumFeed */
    srand(Sys_MillisecondsRaw());
    {
        int r1 = rand();
        int r2 = rand();
        int ms = Sys_Milliseconds();
        int checksumFeed = (r1 << 16) ^ r2 ^ ms;
        sv = *(byte **)&sv_ptr;
        *(int *)(sv + SV_SERVERID_OFF) = checksumFeed;
        FS_Restart(checksumFeed);
    }

    /* Load BSP */
    {
        const char *ext = GetBspExtension();
        Com_sprintf(filename, 64, "maps/mp/%s.%s", server, ext);
    }
    SV_SetExpectedHunkUsage(filename);
    CL_StartLoading(server, (char *)(*(byte **)&sv_ptr + SV_GAMETYPE_OFF));

    UI_LoadIngameMenus();

    /* Initialize configstrings */
    sv = *(byte **)&sv_ptr;
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
    svs = *(byte **)&svs_ptr;
    {
        int numSnapEnts = *(int *)(svs + SVS_NUMSNAPENTS_OFF);
        *(void **)(svs + SVS_SNAPENTS_OFF) = Hunk_AllocInternal((numSnapEnts * 256) - (numSnapEnts * 16));
    }
    *(int *)(svs + SVS_NEXTSNAPENTS_OFF) = 0;
    {
        int numSnapClients = *(int *)(svs + SVS_NUMSNAPCLIENTS_OFF);
        *(void **)(svs + SVS_SNAPCLIENTS_OFF) = Hunk_AllocInternal(numSnapClients * 92);
    }
    *(int *)(svs + SVS_NEXTSNAPCLIENTS_OFF) = 0;

    /* SV_InitArchivedSnapshot */
    *(int *)(svs + SVS_ARCHSNAP_ENABLED_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_2C_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_38_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_3C_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_40_OFF) = 0;
    *(int *)(svs + SVS_ARCHSNAP_44_OFF) = 0;

    /* Toggle snap flag bit */
    *(int *)(svs + SVS_SNAPFLAGBIT_OFF) ^= 4;

    /* Set "nextmap" dvar */
    Dvar_SetString(*(dvar_t **)&nextmap_dvar, "map_restart");

    /* Clear a dvar */
    Dvar_SetInt(*(dvar_t **)&sv_com_dvarDump_ptr, 0);

    /* Load map */
    {
        const char *ext = GetBspExtension();
        Com_sprintf(filename, 64, "maps/mp/%s.%s", server, ext);
    }
    Com_LoadBsp(filename);
    CM_LoadMap(filename, &checksum);
    Com_UnloadBsp();
    CM_LinkWorld();

    /* Update serverId */
    sv_serverId_value = (sv_serverId_value + 16) & 0xff;
    if (!(sv_serverId_value & 0xf0))
        sv_serverId_value += 16;
    Dvar_SetInt(*(dvar_t **)&sv_serverid_dvar, sv_serverId_value);

    /* Set server state and checksumFeed */
    sv = *(byte **)&sv_ptr;
    *(int *)(sv + SV_CHECKSUM_OFF) = *(int *)(*(byte **)&com_checksumFeed_dvar + 8);
    *(int *)(sv + SV_STATE_OFF) = 1;

    /* Load sound aliases */
    {
        const char *ext = GetBspExtension();
        Com_sprintf(filename, 64, "maps/mp/%s.%s", server, ext);
    }
    Com_LoadSoundAliases(filename, "all_mp", 2);

    /* Init game progs */
    SV_InitGameProgs(savepersist);

    /* Init FX system */
    isDedicated = *(int *)(*(byte **)&sv_dedicated_dvar2 + 8);
    if (isDedicated) {
        FX_InitSystem(0);
        FX_CreateDefaultEffect();
    }

    /* Run a few frames */
    for (i = 0; i < 3; i++) {
        *(int *)(*(byte **)&svs_ptr + SVS_TIME_OFF) += 100;
        SV_RunFrame();
    }

    /* SV_SetEntsBaselines - line 291 */
    sv = *(byte **)&sv_ptr;
    if (*(int *)(sv + SV_NUMENTITIES_OFF) > 1) {
        byte *basePtr = sv;
        for (i = 1; i < *(int *)(*(byte **)&sv_ptr + SV_NUMENTITIES_OFF); i++) {
            int entOff;
            byte *dest;

            ent = (byte *)SV_GentityNum(i);
            if (*(char *)(ent + 0xf0) == 0) {
                sv = *(byte **)&sv_ptr;
                goto next_baseline;
            }

            /* Set entity number */
            *(int *)ent = i;

            /* Copy entity state to baseline */
            memcpy(basePtr + 0x2590, ent, 0xf0);
            *(int *)(basePtr + 0x2680) = (unsigned char)*(ent + 0xf2);
            *(int *)(basePtr + 0x2684) = *(int *)(ent + 0xf4);
            *(int *)(basePtr + 0x2688) = *(int *)(ent + 0xf8);

            /* Copy origin */
            entOff = i * 0x174;
            sv = *(byte **)&sv_ptr;
            dest = sv + entOff + 0x2500 + 0x18;
            *(float *)dest = *(float *)(ent + 0x120);
            *(int *)(dest + 4) = *(int *)(ent + 0x124);
            *(int *)(dest + 8) = *(int *)(ent + 0x128);

            /* Copy angles */
            dest = sv + entOff + 0x2510 + 0x14;
            *(int *)dest = *(int *)(ent + 0x12c);
            *(int *)(dest + 4) = *(int *)(ent + 0x130);
            *(int *)(dest + 8) = *(int *)(ent + 0x134);
next_baseline:
            basePtr += 0x174;
        }
    }

    /* Reconnect clients - line 980 */
    svs = *(byte **)&svs_ptr;
    maxclients = *(int *)(*(byte **)&sv_maxclients_dvar + 8);
    for (i = 0; i < maxclients; i++) {
        client = *(byte **)(svs + SVS_CLIENTS_OFF) + i * CLIENT_SIZE;
        if (*(int *)(client + CLIENT_STATE_OFF) <= 1)
            continue;

        s = ClientConnect(i, *(unsigned short *)(client + 0x765f0));
        if (s) {
            SV_DropClient(client, s);
        } else {
            *(int *)(*(byte **)(svs + SVS_CLIENTS_OFF) + i * CLIENT_SIZE) = 2;
        }
    }

    /* Set IWD references */
    if (*(char *)(*(byte **)&sv_pure_dvar + 8)) {
        s = FS_LoadedIwdChecksums();
        Dvar_SetString(*(dvar_t **)&sv_iwds_dvar, s);
        if (*s == '\0') {
            Com_Printf("WARNING: sv_pure set but no IWD files loaded\n");
        }
        s = FS_LoadedIwdNames();
        Dvar_SetString(*(dvar_t **)&sv_iwdNames_dvar, s);
    } else {
        Dvar_SetString(*(dvar_t **)&sv_iwds_dvar, "");
        Dvar_SetString(*(dvar_t **)&sv_iwdNames_dvar, "");
    }

    s = FS_ReferencedIwdChecksums();
    Dvar_SetString(*(dvar_t **)&sv_referencedIwds_dvar, s);
    s = FS_ReferencedIwdNames();
    Dvar_SetString(*(dvar_t **)&sv_referencedIwdNames_dvar, s);

    /* SV_SetConfigValuesForServerInfo */
    {
        char *info = Dvar_InfoString_Big(8);
        I_strncpyz(systemInfo, info, 0x2000);
        *(int *)&com_dvarflags_ptr &= ~8;
        SV_SetConfigstring(1, systemInfo);
        info = Dvar_InfoString(0x404);
        SV_SetConfigstring(0, info);
        *(int *)&com_dvarflags_ptr &= ~0x404;
        SV_SetConfig(0x8e, 0x60, 0x100);
        *(int *)&com_dvarflags_ptr &= ~0x100;
    }

    /* Server is ready */
    *(int *)(*(byte **)&sv_ptr + SV_STATE_OFF) = 2;
    SV_Heartbeat_f();
    Com_Printf("-----------------------------------\n");
}
