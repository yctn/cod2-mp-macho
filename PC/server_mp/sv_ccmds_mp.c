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
        Com_Printf((const char *)str_002ac3e4);
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

    Com_Printf((const char *)str_002ac3fc, s);
    return 0;
}
