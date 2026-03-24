/* ASM dump from: sv_ccmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_ccmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern const char * FS_GetMapBaseName(const char *mapname);
extern void Com_Printf(const char *fmt, ...);
extern char * Dvar_InfoString(int bit);
extern void Info_Print(const char *s);
extern void Com_Shutdown(const char *finalmsg);
extern void SV_MasterGameCompleteStatus(void);
extern void Scr_DumpScriptThreads(void);
extern void MT_DumpTree(void);
extern void Cmd_AddCommand(const char *cmd_name, void (*function)(void));
extern void Cmd_SetAutoComplete(const char *cmd_name, const char *dir, const char *ext);
extern int SV_Cmd_Argc(void);
extern const char *SV_Cmd_Argv(int arg);
extern void SV_BanClient(void *cl);
extern void SV_UnbanClient(const char *name);
extern int I_stricmp(const char *s0, const char *s1);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern char *I_CleanStr(char *string);

static qboolean initialized; /* initialized */

static client_t * SV_GetPlayerByName(void);
static client_t * SV_GetPlayerByNum(void);
const char * SV_GetMapBaseName(const char *mapname);
static short int SV_MapRestart(void);
static short int SV_MapRestart_f(void);
static short int SV_FastRestart_f(void);
static int SV_KickClient_f(void);
static short int SV_Ban_f(void);
static short int SV_BanNum_f(void);
static short int SV_Unban_f(void);
static short int SV_DropNum_f(void);
static short int SV_TempBanNum_f(void);
static short int SV_Status_f(void);
static short int SV_ConSay_f(void);
static short int SV_ConTell_f(void);
short int SV_Heartbeat_f(void);
static short int SV_Serverinfo_f(void);
static short int SV_Systeminfo_f(void);
static short int SV_DumpUser_f(void);
static short int SV_KillServer_f(void);
short int SV_GameCompleteStatus_f(void);
static short int SV_ScriptUsage_f(void);
static short int SV_StringUsage_f(void);
short int SV_AddDedicatedCommands(void);
short int SV_RemoveOperatorCommands(void);
static short int SV_Map_f(void);
short int SV_AddOperatorCommands(void);
static int SV_KickUser_f(void);
static short int SV_TempBan_f(void);
static short int SV_Drop_f(void);
static short int SV_MapRotate_f(void);

/* line 34 */
static client_t * SV_GetPlayerByName(void) {
    const char *s;
    client_t *cl;
    int i, maxclients;
    char cleanName[64];

    if (!*(unsigned char *)(*(byte **)imp_com_sv_running + 8))
        return 0;

    if (SV_Cmd_Argc() - 1 <= 0) {
        Com_Printf((const char *)"No player specified.\n");
        return 0;
    }

    s = SV_Cmd_Argv(1);
    cl = ((serverStatic_t *)imp_svs)->clients;
    maxclients = *(int *)(*(byte **)imp_sv_maxclients + 8);

    for (i = 0; i < maxclients; i++) {
        if (!cl->state)
            goto next;

        if (I_stricmp(cl->name, s) == 0)
            return cl;

        I_strncpyz(cleanName, cl->name, 64);
        I_CleanStr(cleanName);
        if (I_stricmp(cleanName, s) == 0)
            return cl;
next:
        cl++;
    }

    Com_Printf((const char *)"Player %s is not on the server\n", s);
    return 0;
}

const char * SV_GetMapBaseName(const char *mapname)
{
    return FS_GetMapBaseName(mapname);
}

static short int SV_Map_f(void)
{
    extern void I_strlwr(char *s);
    extern char *va(const char *fmt, ...);
    extern const char *GetBspExtension(void);
    extern int FS_ReadFile(const char *qpath, void **buffer);
    extern void FS_ConvertPath(char *s);
    extern void SV_SpawnServer(const char *server);
    extern void Dvar_SetBool(const dvar_t *dvar, int value);
    extern const dvar_t *sv_cheats;

    char mapname[64];
    char *expanded;
    const char *map;

    map = SV_Cmd_Argv(1);
    if (!map || !map[0])
        return 0;

    I_strncpyz(mapname, SV_GetMapBaseName(map), sizeof(mapname));
    I_strlwr(mapname);

    expanded = va("maps/mp/%s.%s", mapname, GetBspExtension());
    if (FS_ReadFile(expanded, NULL) == -1) {
        Com_Printf("Can't find map %s\n", expanded);
        return 0;
    }

    FS_ConvertPath(mapname);
    SV_SpawnServer(mapname);

    Dvar_SetBool(sv_cheats, I_stricmp(SV_Cmd_Argv(0), "devmap") == 0);
    return 0;
}

short int SV_AddOperatorCommands(void)
{
    extern void *imp_com_dedicated;

    if (initialized)
        return 0;
    initialized = 1;
    Cmd_AddCommand("heartbeat", (void (*)(void))SV_Heartbeat_f);
    Cmd_AddCommand("onlykick", (void (*)(void))SV_Drop_f);
    Cmd_AddCommand("banUser", (void (*)(void))SV_Ban_f);
    Cmd_AddCommand("banClient", (void (*)(void))SV_BanNum_f);
    Cmd_AddCommand("kick", (void (*)(void))SV_TempBan_f);
    Cmd_AddCommand("tempBanUser", (void (*)(void))SV_TempBan_f);
    Cmd_AddCommand("tempBanClient", (void (*)(void))SV_TempBanNum_f);
    Cmd_AddCommand("unbanUser", (void (*)(void))SV_Unban_f);
    Cmd_AddCommand("clientkick", (void (*)(void))SV_DropNum_f);
    Cmd_AddCommand("status", (void (*)(void))SV_Status_f);
    Cmd_AddCommand("serverinfo", (void (*)(void))SV_Serverinfo_f);
    Cmd_AddCommand("systeminfo", (void (*)(void))SV_Systeminfo_f);
    Cmd_AddCommand("dumpuser", (void (*)(void))SV_DumpUser_f);
    Cmd_AddCommand("map_restart", (void (*)(void))SV_MapRestart_f);
    Cmd_AddCommand("fast_restart", (void (*)(void))SV_FastRestart_f);
    Cmd_AddCommand("map", (void (*)(void))SV_Map_f);
    Cmd_SetAutoComplete("map", "maps/mp", "d3dbsp");
    Cmd_AddCommand("map_rotate", (void (*)(void))SV_MapRotate_f);
    Cmd_AddCommand("gameCompleteStatus", (void (*)(void))SV_GameCompleteStatus_f);
    Cmd_AddCommand("devmap", (void (*)(void))SV_Map_f);
    Cmd_SetAutoComplete("devmap", "maps/mp", "d3dbsp");
    Cmd_AddCommand("killserver", (void (*)(void))SV_KillServer_f);
    if (*(int *)((byte *)(*(void **)imp_com_dedicated) + 8)) {
        Cmd_AddCommand("say", (void (*)(void))SV_ConSay_f);
        Cmd_AddCommand("tell", (void (*)(void))SV_ConTell_f);
    }
    Cmd_AddCommand("scriptUsage", (void (*)(void))SV_ScriptUsage_f);
    Cmd_AddCommand("stringUsage", (void (*)(void))SV_StringUsage_f);
    return 0;
}
