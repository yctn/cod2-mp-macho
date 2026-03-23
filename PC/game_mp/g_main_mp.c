/* ASM dump from: g_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_main_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <stdarg.h>

static const char str_dbg_spawn[] = "after G_SpawnEntities";
static const char str_dbg_load[] = "after GScr_LoadScripts";
static const char str_dbg_vmtop_fmt[] = "DBG vmtop before init: %p\n";
static const char str_dbg_vmtop2_fmt[] = "DBG vmtop after init: %p\n";
static const char str_dbg_ff_before[] = "DBG function_frame before Scr_LoadGameType: %p\n";
static const char str_dbg_ff_after_load[] = "DBG function_frame after Scr_LoadGameType: %p\n";
static const char str_dbg_ff_after_startup[] = "DBG function_frame after Scr_StartupGameType: %p\n";
static const char str_dbg_ff_trace[] = "DBG function_frame after Scr_InitSystem: %p\n";
static const char str_dbg_ff_agv[] = "DBG function_frame after Scr_AllocGameVariable: %p\n";
static const char str_dbg_ff_gls[] = "DBG function_frame after G_LoadStructs: %p\n";
static const char str_dbg_endload[] = "after Scr_EndLoadScripts";

void G_InitDbgPrint(const char *fmt, void *ptr) {
    fprintf(stderr, fmt, ptr);
}

extern entityHandler_t entityHandlers[20]; /* 0x0 */
extern struct bgs_t level_bgs; /* 0x0 */
extern struct level_locals_t level; /* 0x0 */
extern gentity_t g_entities[1024]; /* 0x0 */
extern const dvar_t *g_gametype; /* 0x0 */
extern const dvar_t *g_dedicated; /* 0x0 */
extern const dvar_t *g_cheats; /* 0x0 */
extern const dvar_t *g_maxclients; /* 0x0 */
extern const dvar_t *g_password; /* 0x0 */
extern const dvar_t *g_gravity; /* 0x0 */
extern const dvar_t *g_speed; /* 0x0 */
extern const dvar_t *g_knockback; /* 0x0 */
extern const dvar_t *g_useholdtime; /* 0x0 */
extern const dvar_t *g_useholdspawndelay; /* 0x0 */
extern const dvar_t *g_inactivity; /* 0x0 */
extern const dvar_t *g_debugDamage; /* 0x0 */
extern const dvar_t *g_debugBullets; /* 0x0 */
extern const dvar_t *g_weaponAmmoPools; /* 0x0 */
extern const dvar_t *g_maxDroppedWeapons; /* 0x0 */
extern const dvar_t *g_synchronousClients; /* 0x0 */
extern const dvar_t *g_motd; /* 0x0 */
extern const dvar_t *g_allowVote; /* 0x0 */
extern const dvar_t *g_dropForwardSpeed; /* 0x0 */
extern const dvar_t *g_dropUpSpeedBase; /* 0x0 */
extern const dvar_t *g_dropUpSpeedRand; /* 0x0 */
extern const dvar_t *g_clonePlayerMaxVelocity; /* 0x0 */
extern const dvar_t *voice_localEcho; /* 0x0 */
extern const dvar_t *voice_global; /* 0x0 */
extern const dvar_t *voice_deadChat; /* 0x0 */
extern const dvar_t *g_voiceChatTalkingDuration; /* 0x0 */
extern const dvar_t *g_deadChat; /* 0x0 */
extern const dvar_t *g_banIPs; /* 0x0 */
extern const dvar_t *g_smoothClients; /* 0x0 */
extern const dvar_t *g_NoScriptSpam; /* 0x0 */
extern const dvar_t *g_debugLocDamage; /* 0x0 */
extern const dvar_t *g_friendlyfireDist; /* 0x0 */
extern const dvar_t *g_friendlyNameDist; /* 0x0 */
extern const dvar_t *player_meleeRange; /* 0x0 */
extern const dvar_t *player_meleeWidth; /* 0x0 */
extern const dvar_t *player_meleeHeight; /* 0x0 */
extern const dvar_t *g_antilag; /* 0x0 */
extern const dvar_t *g_oldVoting; /* 0x0 */
extern const dvar_t *g_playerCollisionEjectSpeed; /* 0x0 */
extern const dvar_t *g_mantleBlockTimeBuffer; /* 0x0 */
extern const dvar_t *g_log; /* 0x0 */
extern const dvar_t *g_logSync; /* 0x0 */
extern const dvar_t *g_listEntity; /* 0x0 */
extern const dvar_t *g_ScoresBanner_Allies; /* 0x0 */
extern const dvar_t *g_ScoresBanner_Axis; /* 0x0 */
extern const dvar_t *g_ScoresBanner_None; /* 0x0 */
extern const dvar_t *g_ScoresBanner_Spectators; /* 0x0 */
extern const dvar_t *g_TeamName_Allies; /* 0x0 */
extern const dvar_t *g_TeamName_Axis; /* 0x0 */
extern const dvar_t *g_TeamColor_Allies; /* 0x0 */
extern const dvar_t *g_TeamColor_Axis; /* 0x0 */
extern const dvar_t *g_voteAbstainWeight; /* 0x0 */
extern const dvar_t *g_dumpAnims; /* 0x0 */
extern unsigned char g_clients[]; /* BSS g_clients array (665856 bytes = 64 * gclient_s) */
extern struct scr_data_t g_scr_data; /* 0x0 */

/* Extern functions needed for C conversions */
extern float ceilf(float x);
extern void Com_ServerDObjCreate(DObjModel_s *models, int numModels, struct XAnimTree_s *tree, int handle, clientInfo_t *ci);
extern int * Hunk_AllocLowInternal(int size);
extern void SV_Trace(trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask, int locational, unsigned char *priorityMap, int staticmodels);
extern qboolean SV_TracePassed(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int passOwnerNum, int contentmask, int locational, int staticmodels);
extern int SV_SightTrace(int *hitNum, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int passOwnerNum, int contentmask);
extern void CL_AddDebugString(const vec_t *xyz, const vec_t *color, float scale, const char *pszText, int fromServer);
extern void Cbuf_ExecuteText(int exec_when, const char *text);
extern void SV_GameSendServerCommand(int clientNum, int svscmd_type, const char *text);
extern void SV_SetConfigstring(int index, const char *val);
extern char * va(const char *format, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void FS_Write(const void *buffer, int len, fileHandle_t h);
extern void FS_FCloseFile(fileHandle_t f);
extern void G_FreeEntity(gentity_t *ent);
extern void SV_UnlinkEntity(gentity_t *ent);
extern void HudElem_DestroyAll(void);
extern qboolean Scr_IsSystemActive(int inst);
extern void Scr_ShutdownSystem(int inst, qboolean freeScripts);
extern void SV_FreeClientScriptPers(void);
extern void Z_FreeInternal(void *ptr);
extern void Mantle_ShutdownAnims(void);
extern void GScr_FreeScripts(void);
extern void Scr_FreeScripts(int inst);
extern void XAnimFreeTree(struct XAnimTree_s *tree, int inst);
extern void Hunk_ClearToMarkLow(int mark);
extern void G_RunMissile(gentity_t *ent);
extern void G_RunItem(gentity_t *ent);
extern void G_RunCorpse(gentity_t *ent);
extern void G_RunMover(gentity_t *ent);
extern void G_RunClient(gentity_t *ent);
extern unsigned char G_GeneralLink(gentity_t *ent);

/* Zero vector for locational trace functions */
static vec3_t vec3_zero = {0.0f, 0.0f, 0.0f};

enum {
    GMAIN_CS_VOTE_TIME = 15,
    GMAIN_ET_GENERAL = 0,
    GMAIN_ET_PLAYER_CORPSE = 2,
    GMAIN_ET_ITEM = 3,
    GMAIN_ET_MISSILE = 4,
    GMAIN_ET_SCRIPTMOVER = 6,
    GMAIN_FL_NODRAW = 8,
    GMAIN_EF_NODRAW = 0x20,
    GMAIN_EFLAGS_UNKNOWN = 0x10000
};

int G_GetSavePersist(void);
int G_SetSavePersist(qboolean savepersist);
float G_GetFogOpaqueDistSqrd(void);
int G_GetClientScore(int clientNum);
int G_GetClientArchiveTime(int clientNum);
int G_SetClientArchiveTime(int clientNum, int time);
clientState_t * G_GetClientState(int clientNum);
static int G_CreateDObj(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle, clientInfo_t *ci);
int * Hunk_AllocXAnimServer(int size);
static int SortRanks(const int *a, const int *b);
int CalculateRanks(void);
int G_LogPrintf(const char *fmt, ...);
int ExitLevel(void);
int G_InitGame(int levelTime, int randomSeed, qboolean restart, qboolean savepersist);
int CheckVote(void);
int G_RunThink(gentity_t *ent);
int G_TraceCapsule(trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask);
qboolean G_TraceCapsuleComplete(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask);
int G_LocationalTrace(trace_t *results, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask, unsigned char *priorityMap);
qboolean G_LocationalTracePassed(const vec_t *start, const vec_t *end, int passEntityNum, int contentmask);
int G_SightTrace(int *hitNum, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask);
int G_AddDebugString(const vec_t *xyz, const vec_t *color, float scale, const char *pszText);
int G_ShutdownGame(qboolean freeScripts);
static int __attribute_regparm__(1) G_RunFrameForEntity(gentity_t *ent);
int G_RunFrame(int levelTime);

/* line 510 */
int G_GetSavePersist(void)
{
    return level.savepersist;
}

/* line 521 */
int G_SetSavePersist(qboolean savepersist)
{
    level.savepersist = savepersist;
    return 0;
}

/* line 532 */
float G_GetFogOpaqueDistSqrd(void)
{
    return level.fFogOpaqueDistSqrd;
}

/* line 544 */
int G_GetClientScore(int clientNum)
{
    return level.clients[clientNum].sess.score;
}

/* line 556 */
int G_GetClientArchiveTime(int clientNum)
{
    if (!level.clients) {
        fprintf(stderr, "[G_GetClientArchiveTime] level.clients is NULL! clientNum=%d\n", clientNum);
        return 0;
    }
    return level.clients[clientNum].sess.archiveTime;
}

/* line 568 */
int G_SetClientArchiveTime(int clientNum, int time)
{
    level.clients[clientNum].sess.archiveTime = time;
    return 0;
}

/* line 580 */
clientState_t * G_GetClientState(int clientNum)
{
    return &level.clients[clientNum].sess.cs;
}

/* line 684 */
static int G_CreateDObj(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle, clientInfo_t *ci)
{
    numModels = (unsigned short)numModels;
    Com_ServerDObjCreate(dobjModels, numModels, tree, handle, ci);
    return 0;
}

/* line 751 */
int * Hunk_AllocXAnimServer(int size)
{
    return Hunk_AllocLowInternal(size);
}

/* line 1021 */
static int SortRanks(const int *a, const int *b)
{
    gclient_t *ca = &level.clients[*a];
    gclient_t *cb = &level.clients[*b];

    if (ca->sess.connected == CON_CONNECTING) {
        return 1;
    }
    if (cb->sess.connected == CON_CONNECTING) {
        return -1;
    }

    if (ca->sess.cs.team == TEAM_SPECTATOR) {
        if (cb->sess.cs.team != TEAM_SPECTATOR) {
            return 1;
        }
        if ((byte *)ca < (byte *)cb) {
            return -1;
        }
        if ((byte *)ca == (byte *)cb) {
            return 0;
        }
        return 1;
    }

    if (cb->sess.cs.team == TEAM_SPECTATOR) {
        return -1;
    }

    if (ca->sess.score > cb->sess.score) {
        return -1;
    }
    if (ca->sess.score < cb->sess.score) {
        return 1;
    }

    if (ca->sess.deaths < cb->sess.deaths) {
        return -1;
    }
    if (ca->sess.deaths > cb->sess.deaths) {
        return 1;
    }

    return 0;
}

/* line 1073 */
int CalculateRanks(void)
{
    int i;
    int numranked = 0;

    level.numConnectedClients = 0;
    level.numVotingClients = 0;

    for (i = 0; i < level.maxclients; i++) {
        if (level.clients[i].sess.connected != CON_DISCONNECTED) {
            level.sortedClients[level.numConnectedClients] = i;
            level.numConnectedClients++;

            if (level.clients[i].sess.cs.team != TEAM_SPECTATOR) {
                if (level.clients[i].sess.connected == CON_CONNECTED) {
                    level.numVotingClients++;
                }
            }
        }
    }

    qsort(level.sortedClients, level.numConnectedClients, sizeof(int), (int (*)(const void *, const void *))SortRanks);
    level.bUpdateScoresForIntermission = 1;

    return 0;
}

/* line 1159 */
int G_LogPrintf(const char *fmt, ...)
{
    char string[1024];
    char string2[1024];
    va_list argptr;
    int min, sec, tens, ones;

    if (level.logFile <= 0)
        return 0;

    va_start(argptr, fmt);
    vsnprintf(string2, 1024, fmt, argptr);
    va_end(argptr);

    sec = level.time / 1000;
    min = sec / 60;
    sec %= 60;
    tens = sec / 10;
    ones = sec % 10;

    Com_sprintf(string, 1024, "%3i:%i%i %s", min, tens, ones, string2);
    FS_Write(string, strlen(string), level.logFile);

    return 0;
}

/* line 1118 */
int ExitLevel(void)
{
    int i;

    Cbuf_ExecuteText(2, "map_rotate\n");

    level.teamScores[TEAM_AXIS] = 0;
    level.teamScores[TEAM_ALLIES] = 0;

    for (i = 0; i < g_maxclients->current.integer; i++) {
        if (level.clients[i].sess.connected == CON_CONNECTED) {
            level.clients[i].sess.score = 0;
        }
    }

    for (i = 0; i < g_maxclients->current.integer; i++) {
        if (level.clients[i].sess.connected == CON_CONNECTED) {
            level.clients[i].sess.connected = CON_CONNECTING;
        }
    }

    G_LogPrintf("ExitLevel: executed\n");
    return 0;
}

/* DBG: count and print free script variables */
void DBG_PrintFreeVars(const char *label)
{
    extern unsigned char scrVarGlob[];
    /* Count used variables by scanning all 65535 entries for non-zero type */
    int usedCount = 0;
    for (int i = 1; i <= 65535; i++) {
        unsigned int type_flags = *(unsigned int *)(scrVarGlob + i * 16 + 8);
        if (type_flags & 0x1f) { /* has a type set */
            usedCount++;
        }
    }
    /* Walk free list to count actual free entries */
    unsigned short freeHead = *(unsigned short *)(scrVarGlob + 4);
    int freeListLen = 0;
    unsigned short idx = freeHead;
    while (idx != 0 && freeListLen < 70000) {
        freeListLen++;
        /* Free list links: entry[idx].hash.id gives the entryValue index,
           then entryValue.u.next (offset 4) gives the next free entry */
        unsigned short entryValueIdx = *(unsigned short *)(scrVarGlob + (unsigned int)idx * 16);
        unsigned short next = *(unsigned short *)(scrVarGlob + (unsigned int)entryValueIdx * 16 + 4);
        idx = next;
    }
    Com_Printf("DBG %s: %d used vars, freeHead=%u, freeListLen=%d\n", label, usedCount, freeHead, freeListLen);
}

/* line 763 */
extern const dvar_t *Dvar_RegisterString_mac(const char *name, int def, int min, int max, int flags);
extern const dvar_t *Dvar_RegisterInt(const char *name, int def, int min, int max, int flags);
extern const dvar_t *Dvar_RegisterBool_mac(const char *name, int def, int min, int max, int flags);
extern const dvar_t *Dvar_RegisterFloat(const char *name, float def, float min, float max, int flags);
extern void Swap_Init(void);
extern void G_ProcessIPBans(void);
extern void G_SetupWeaponDef(void);
extern void BG_RegisterDvars(void);
extern void Rand_Init(int seed);
extern int FS_FOpenFileByMode(const char *filename, int *handle, int mode);
extern void SV_GetServerinfo(const char *key, char *value, int size);
extern void SV_LocateGameData(void *clients, int numClients, int clientSize, void *entities);
extern void G_SpawnEntitiesFromString(void *entities, int maxEntities, int entitySize);
extern void Scr_BeginLoadScripts(void);
extern void GScr_LoadScripts(int inst);
extern void GScr_LoadConsts(void);
extern void Scr_BeginLoadAnimScripts(void);
extern void GScr_LoadAnimScripts(void);
extern void Scr_EndLoadAnimScripts(void);
extern void Scr_FreeEntityList(void);
extern void Scr_InitSystem(void);
extern void Scr_SetLoading(int loading);
extern void Scr_AllocGameVariable(void);
extern void G_LoadStructs(void);
extern void Scr_LoadLevel(void);
extern void Scr_LoadGameType(void);
extern void Scr_StartupGameType(void);
extern void RestoreBody(void);
extern void ClientUserinfoChanged(int clientNum, gentity_t *ent, gclient_t *client);
extern void G_InitTurrets(void);
extern int SV_GetBrushModelCount(void);
extern void G_SpawnTriggerHurt(int numBrushModels);
extern void GScr_PostResetTimeout(void);
extern void CheckTeamStatus(void);
extern void DeathmatchScoreboardMessage(gentity_t *ent);
extern const char *SL_ConvertToString(unsigned short index);
extern void Dvar_SetBool(const dvar_t *dvar, int value);
extern void SaveRegisteredWeapons(void);
extern void SaveRegisteredItems(void);
extern void SV_DObjDisplayAnim(gentity_t *ent);
extern void SV_DObjInitServerTime(gentity_t *ent, float dt);
extern int G_DObjUpdateServerTime(gentity_t *ent, int bNotify);
extern void Scr_RunCurrentThreads(void);
extern void Scr_IncTime(void);
extern void Com_Memcpy(void *dst, const void *src, int size);
extern int stricmp(const char *s1, const char *s2);
extern void ClientEndFrame(gentity_t *ent);
extern void HudElem_UpdateClient(gclient_t *client, int clientNum, int which);
extern unsigned char scrVarPub[];
extern unsigned char scrVmPub[];
extern void Scr_AddEntity(void *ent);
extern void Scr_Notify(void *ent, int stringValue, unsigned int paramcount);

#define SCR_CONST() ((const scr_const_t *)imp_scr_const)

static scrVarPub_t *G_ScrVarPubRef(void)
{
    return (scrVarPub_t *)scrVarPub;
}

static scrVmPub_t *G_ScrVmPubRef(void)
{
    return (scrVmPub_t *)scrVmPub;
}

static void G_RegisterDvars_impl(void) {
    g_gametype = Dvar_RegisterString_mac("g_gametype", 0, 0, 2, 0x1040);
    g_dedicated = Dvar_RegisterInt("dedicated", 0, 0, 2, 0x1040);
    g_cheats = Dvar_RegisterBool_mac("sv_cheats", 0, 0, 0, 0);
    g_maxclients = Dvar_RegisterInt("sv_maxclients", 0, 0, 0x40, 0x1040);
    g_password = Dvar_RegisterString_mac("g_password", 0, 0, 0, 0x1040);
    g_gravity = Dvar_RegisterFloat("g_gravity", 800.0f, 1.0f, 3.402823466e38f, 0x800);
    g_speed = Dvar_RegisterInt("g_speed", 0xbe, 0, 0xc8, 0x800);
    g_knockback = Dvar_RegisterFloat("g_knockback", 1000.0f, -3.402823466e38f, 3.402823466e38f, 0x800);
    g_useholdtime = Dvar_RegisterInt("g_useholdtime", 0, 0, 0, 0);
    g_useholdspawndelay = Dvar_RegisterInt("g_useholdspawndelay", 0, 0, 0, 0);
    g_inactivity = Dvar_RegisterInt("g_inactivity", 0, 0, 0, 0x800);
    g_debugDamage = Dvar_RegisterBool_mac("g_debugDamage", 0, 0, 0, 0x800);
    g_debugBullets = Dvar_RegisterInt("g_debugBullets", 0, -3, 6, 0x800);
    g_weaponAmmoPools = Dvar_RegisterBool_mac("g_weaponAmmoPools", 0, 0, 0, 0x800);
    g_maxDroppedWeapons = Dvar_RegisterInt("g_maxDroppedWeapons", 0x10, 1, 0x20, 0x800);
    g_synchronousClients = Dvar_RegisterBool_mac("g_synchronousClients", 0, 0, 0, 0x800);
    g_motd = Dvar_RegisterString_mac("g_motd", 0, 0, 0, 0x800);
    g_allowVote = Dvar_RegisterBool_mac("g_allowVote", 1, 0, 0, 0);
    g_dropForwardSpeed = Dvar_RegisterFloat("g_dropForwardSpeed", 10.0f, 0.0f, 1000.0f, 0x800);
    g_dropUpSpeedBase = Dvar_RegisterFloat("g_dropUpSpeedBase", 10.0f, 0.0f, 1000.0f, 0x800);
    g_dropUpSpeedRand = Dvar_RegisterFloat("g_dropUpSpeedRand", 5.0f, 0.0f, 1000.0f, 0x800);
    g_clonePlayerMaxVelocity = Dvar_RegisterFloat("g_clonePlayerMaxVelocity", 80.0f, 0.0f, 3.402823466e38f, 0x800);
    voice_localEcho = Dvar_RegisterBool_mac("voice_localEcho", 0, 0, 0, 0x800);
    voice_global = Dvar_RegisterBool_mac("voice_global", 0, 0, 0, 0);
    voice_deadChat = Dvar_RegisterBool_mac("voice_deadChat", 0, 0, 0, 0);
    g_voiceChatTalkingDuration = Dvar_RegisterInt("g_voiceChatTalkingDuration", 500, 0, 10000, 0);
    g_deadChat = Dvar_RegisterBool_mac("g_deadChat", 0, 0, 0, 0);
    g_banIPs = Dvar_RegisterString_mac("g_banIPs", 0, 0, 0, 0);
    g_smoothClients = Dvar_RegisterBool_mac("g_smoothClients", 1, 0, 0, 0);
    g_NoScriptSpam = Dvar_RegisterBool_mac("g_NoScriptSpam", 0, 0, 0, 0);
    g_debugLocDamage = Dvar_RegisterBool_mac("g_debugLocDamage", 0, 0, 0, 0x800);
    g_friendlyfireDist = Dvar_RegisterFloat("g_friendlyfireDist", 256.0f, 0.0f, 15000.0f, 0x800);
    g_friendlyNameDist = Dvar_RegisterFloat("g_friendlyNameDist", 15000.0f, 0.0f, 15000.0f, 0x800);
    player_meleeRange = Dvar_RegisterFloat("player_meleeRange", 64.0f, 0.0f, 1000.0f, 0);
    player_meleeWidth = Dvar_RegisterFloat("player_meleeWidth", 10.0f, 0.0f, 1000.0f, 0);
    player_meleeHeight = Dvar_RegisterFloat("player_meleeHeight", 10.0f, 0.0f, 1000.0f, 0);
    g_antilag = Dvar_RegisterBool_mac("g_antilag", 1, 0, 0, 0);
    g_oldVoting = Dvar_RegisterBool_mac("g_oldVoting", 1, 0, 0, 0);
    g_playerCollisionEjectSpeed = Dvar_RegisterInt("g_playerCollisionEjectSpeed", 25, 0, 32000, 0x800);
    g_mantleBlockTimeBuffer = Dvar_RegisterInt("g_mantleBlockTimeBuffer", 500, 0, 60000, 0x800);
    g_log = Dvar_RegisterString_mac("g_log", 0, 0, 0, 0);
    g_logSync = Dvar_RegisterBool_mac("g_logSync", 0, 0, 0, 0);
    g_listEntity = Dvar_RegisterBool_mac("g_listEntity", 0, 0, 0, 0);
    g_ScoresBanner_Allies = Dvar_RegisterString_mac("g_ScoresBanner_Allies", 0, 0, 0, 0);
    g_ScoresBanner_Axis = Dvar_RegisterString_mac("g_ScoresBanner_Axis", 0, 0, 0, 0);
    g_ScoresBanner_None = Dvar_RegisterString_mac("g_ScoresBanner_None", 0, 0, 0, 0);
    g_ScoresBanner_Spectators = Dvar_RegisterString_mac("g_ScoresBanner_Spectators", 0, 0, 0, 0);
    g_TeamName_Allies = Dvar_RegisterString_mac("g_TeamName_Allies", 0, 0, 0, 0);
    g_TeamName_Axis = Dvar_RegisterString_mac("g_TeamName_Axis", 0, 0, 0, 0);
    g_TeamColor_Allies = Dvar_RegisterString_mac("g_TeamColor_Allies", 0, 0, 0, 0);
    g_TeamColor_Axis = Dvar_RegisterString_mac("g_TeamColor_Axis", 0, 0, 0, 0);
    g_voteAbstainWeight = Dvar_RegisterFloat("g_voteAbstainWeight", 0.5f, 0.0f, 1.0f, 0);
    g_dumpAnims = Dvar_RegisterInt("g_dumpAnims", -1, 0, 0, 0x800);
}

static void G_SetGametypeTeamFlags(int *teamFlags, const char *gametype) {
    /* Check gametype and set team flags */
    if (stricmp(gametype, "dm") == 0) {
        teamFlags[3] = 1;
        teamFlags[2] = 1;
    } else if (stricmp(gametype, "tdm") == 0) {
        teamFlags[3] = 1;
        teamFlags[2] = 1;
    } else if (stricmp(gametype, "sd") == 0) {
        teamFlags[3] = 1;
        teamFlags[2] = 1;
    } else if (stricmp(gametype, "ctf") == 0) {
        teamFlags[3] = 1;
        teamFlags[2] = 1;
    } else if (stricmp(gametype, "hq") == 0) {
        teamFlags[3] = 1;
        teamFlags[2] = 1;
    }
    teamFlags[0] = 0;
}

int G_InitGame(int levelTime, int randomSeed, qboolean restart, qboolean savepersist) {
    char info[0x800];
    int i;
    int *teamFlags;
    const char *logFile;
    gclient_t *cl;

    Com_Printf("------- Game Initialization -------\n");
    Com_Printf("gamename: %s\n", "Call of Duty 2");
    Com_Printf("gamedate: %s\n", __DATE__);

    Swap_Init();

    memset(&level, 0, 0x3624);
    level.initializing = 1;
    level.time = levelTime;
    level.startTime = levelTime;
    level.currentEntityThink = -1;
    level.gentities = (gentity_s *)g_entities;
    level.clients = (gclient_s *)g_clients;

    G_InitDbgPrint("[G_InitGame] level.clients=%p\n", (void *)level.clients);

    srand(randomSeed);
    Rand_Init(randomSeed);
    G_SetupWeaponDef();
    G_RegisterDvars_impl();
    BG_RegisterDvars();

    teamFlags = (int *)&level.teamScores[3]; /* offset 520 = teamScores[3] used as teamFlags base */

    if (!restart || !savepersist) {
        /* Set gametype team flags */
        G_SetGametypeTeamFlags(teamFlags, g_gametype->current.string);
    }

    G_ProcessIPBans();

    /* Setup bgs function pointers */
    level_bgs.GetXModel = (struct XModel *(*)())imp_SV_XModelGet;
    level_bgs.CreateDObj = (void (*)())G_CreateDObj;
    level_bgs.SafeDObjFree = (void (*)())imp_Com_SafeServerDObjFree;
    level_bgs.AllocXAnim = (void *(*)())Hunk_AllocXAnimServer;
    level_bgs.anim_user = 1;

    /* Log file setup */
    logFile = g_log->current.string;
    if (*logFile != '\0') {
        if (g_logSync->current.integer) {
            FS_FOpenFileByMode(logFile, &level.logFile, 3);
        } else {
            FS_FOpenFileByMode(logFile, &level.logFile, 1);
        }
        G_LogPrintf("------------------------------------------------------------\n");
        G_LogPrintf("------------------------------------------------------------\n");
        SV_GetServerinfo("sv_mapname", (char *)((byte *)&level_bgs + 813548), 0x400);
        G_LogPrintf("InitGame: %s\n", (char *)((byte *)&level_bgs + 813548));
    } else {
        level.logFile = -1;
        Com_Printf("Not logging to disk.\n");
    }

    /* Initialize scrVarPub */
    {
        char *p = (char *)Hunk_AllocLowInternal(0);
        G_ScrVarPubRef()->fieldBuffer = p;
        p[0] = '\0';
    }

    SV_LocateGameData((void *)g_clients, 0x400, 0xa04, (void *)g_entities);
    G_SpawnEntitiesFromString((void *)g_entities, 0x400, 0x230);
    DBG_PrintFreeVars(str_dbg_spawn);
    level.initializing = 0;

    Com_Printf("%i+%i entity slots, %i+%i client slots\n",
        level.num_entities, (int)level.firstFreeEnt,
        level.maxclients, 0);

    /* Log gametype */
    G_LogPrintf("gametype: %s\n", g_gametype->current.string);

    G_InitTurrets();
    G_SpawnTriggerHurt(SV_GetBrushModelCount() + 1);
    GScr_PostResetTimeout();
    G_SetupWeaponDef();
    Scr_BeginLoadScripts();
    GScr_LoadScripts(1);
    DBG_PrintFreeVars(str_dbg_load);
    GScr_LoadConsts();
    Scr_FreeScripts(1);
    Scr_BeginLoadAnimScripts();
    GScr_LoadAnimScripts();
    Scr_EndLoadAnimScripts();
    G_RegisterDvars_impl();

    Com_Printf(str_dbg_vmtop_fmt, G_ScrVmPubRef()->top);
    Scr_FreeEntityList();
    Scr_InitSystem();
    Com_Printf(str_dbg_ff_trace, G_ScrVmPubRef()->function_frame);
    Scr_SetLoading(1);
    Scr_AllocGameVariable();
    Com_Printf(str_dbg_ff_agv, G_ScrVmPubRef()->function_frame);
    G_LoadStructs();
    Com_Printf(str_dbg_ff_gls, G_ScrVmPubRef()->function_frame);

    /* Script init */
    level.initializing = 1;
    Scr_LoadLevel();
    Com_Printf(str_dbg_ff_before, G_ScrVmPubRef()->function_frame);
    Scr_LoadGameType();
    Com_Printf(str_dbg_ff_after_load, G_ScrVmPubRef()->function_frame);
    Scr_StartupGameType();
    Com_Printf(str_dbg_ff_after_startup, G_ScrVmPubRef()->function_frame);

    if (restart && !savepersist) {
        RestoreBody();
    }

    /* Update connected clients' userinfo */
    for (i = 0; i < g_maxclients->current.integer; i++) {
        cl = &level.clients[i];
        if (cl->sess.connected == CON_CONNECTED) {
            /* ClientUserinfoChanged(clientNum, ent, client) */
            ClientUserinfoChanged(i,
                &g_entities[i],
                cl);
        }
    }

    /* Reset team flags */
    level.teamScores[3] = 0; /* reset teamFlags */

    /* Password notice for dedicated servers */
    if (g_dedicated->current.integer > 0) {
        const char *pw = g_password->current.string;
        if (*pw != '\0') {
            Com_sprintf(info, sizeof(info), "password: %s\n", pw);
        }
    }

    CalculateRanks();
    level.initializing = 0;

    return 0;
}

/* line 1202 */
int CheckVote(void)
{
    if (level.voteExecuteTime && level.voteExecuteTime < level.time) {
        level.voteExecuteTime = 0;
        Cbuf_ExecuteText(2, va("%s\n", level.voteString));
    }

    if (!level.voteTime) {
        return 0;
    }

    if (level.time >= level.voteTime) {
        SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, va("%c \"GAME_VOTEFAILED\"", 101));
    } else {
        int passCount;

        passCount = level.numVotingClients / 2 + 1;
        if (level.voteYes >= passCount) {
            SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, va("%c \"GAME_VOTEPASSED\"", 101));
            level.voteExecuteTime = level.time + 3000;
        } else if (level.voteNo > level.numVotingClients - passCount) {
            SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, va("%c \"GAME_VOTEFAILED\"", 101));
        } else if (level.voteYes > (int)ceilf((float)(level.numVotingClients - (level.voteYes + level.voteNo)) * g_voteAbstainWeight->current.value) + level.voteNo) {
            SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, va("%c \"GAME_VOTEPASSED\"", 101));
            level.voteExecuteTime = level.time + 3000;
        } else {
            return 0;
        }
    }

    level.voteTime = 0;
    SV_SetConfigstring(GMAIN_CS_VOTE_TIME, "");
    return 0;
}

/* line 1324 */
int G_RunThink(gentity_t *ent)
{
    int thinktime;
    fn_think think;

    thinktime = ent->nextthink;
    if (thinktime <= 0) {
        return 0;
    }
    if (thinktime > level.time) {
        return 0;
    }

    ent->nextthink = 0;
    think = entityHandlers[ent->handler].think;
    if (!think) {
        Com_Error(1, "NULL ent->think");
    }
    ((void (*)(gentity_t *))think)(ent);
    return 0;
}

/* line 1682 */
int G_TraceCapsule(trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask)
{
    SV_Trace(results, start, mins, maxs, end, passEntityNum, contentmask, 0, 0, 0);
    return 0;
}

/* line 1694 */
qboolean G_TraceCapsuleComplete(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask)
{
    return SV_TracePassed(start, mins, maxs, end, passEntityNum, 0x3ff, contentmask, 0, 0);
}

/* line 1706 */
int G_LocationalTrace(trace_t *results, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask, unsigned char *priorityMap)
{
    SV_Trace(results, start, vec3_zero, vec3_zero, end, passEntityNum, contentmask, 1, priorityMap, 1);
    return 0;
}

/* line 1718 */
qboolean G_LocationalTracePassed(const vec_t *start, const vec_t *end, int passEntityNum, int contentmask)
{
    return SV_TracePassed(start, vec3_zero, vec3_zero, end, passEntityNum, 0x3ff, contentmask, 1, 1);
}

/* line 1730 */
int G_SightTrace(int *hitNum, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask)
{
    return SV_SightTrace(hitNum, start, vec3_zero, vec3_zero, end, passEntityNum, 0x3ff, contentmask);
}

/* line 1742 */
int G_AddDebugString(const vec_t *xyz, const vec_t *color, float scale, const char *pszText)
{
    CL_AddDebugString(xyz, color, scale, pszText, 1);
    return 0;
}

/* line 923 */
int G_ShutdownGame(qboolean freeScripts)
{
    int i;

    Com_Printf((const char *)"==== ShutdownGame ====\n");

    if (level.logFile > 0) {
        G_LogPrintf((const char *)"ShutdownGame:\n");
        G_LogPrintf((const char *)"------------------------------------------------------------\n");
        FS_FCloseFile(level.logFile);
    }

    *(void **)imp_bgs = NULL;

    for (i = 0; i < level.num_entities; i++) {
        if (g_entities[i].r.inuse)
            G_FreeEntity(&g_entities[i]);
    }

    if (g_entities[1022].r.inuse)
        G_FreeEntity(&g_entities[1022]);

    level.num_entities = 0;
    level.firstFreeEnt = NULL;
    level.lastFreeEnt = NULL;

    HudElem_DestroyAll();

    if (Scr_IsSystemActive(1)) {
        if (!level.savepersist)
            SV_FreeClientScriptPers();
    }

    Scr_ShutdownSystem(1, level.savepersist == 0);

    if (freeScripts) {
        Mantle_ShutdownAnims();
        GScr_FreeScripts();
        Scr_FreeScripts(0); /* full shutdown — zero code base */

        for (i = 0; i < 64; i++) {
            struct XAnimTree_s *tree = level_bgs.clientinfo[i].pXAnimTree;
            if (tree) {
                XAnimFreeTree(tree, 0);
                level_bgs.clientinfo[i].pXAnimTree = NULL;
            }
        }

        for (i = 0; i < 8; i++) {
            struct XAnimTree_s *tree = g_scr_data.playerCorpseInfo[i].tree;
            if (tree) {
                XAnimFreeTree(tree, 0);
                g_scr_data.playerCorpseInfo[i].tree = NULL;
            }
        }

        Hunk_ClearToMarkLow(0);
    }

    if (level.openScriptIOFileBuffers[0]) {
        Z_FreeInternal(level.openScriptIOFileBuffers[0]);
    }
    level.openScriptIOFileBuffers[0] = NULL;

    if (level.openScriptIOFileHandles[0] >= 0) {
        FS_FCloseFile(level.openScriptIOFileHandles[0]);
    }
    level.openScriptIOFileHandles[0] = -1;

    return 0;
}

/* line 1384 */
static int __attribute_regparm__(1) G_RunFrameForEntity(gentity_t *ent)
{
    if (ent->processedFrame == level.framenum) {
        return 0;
    }

    ent->processedFrame = level.framenum;

    if (!ent->client) {
        if (ent->flags & GMAIN_FL_NODRAW) {
            ent->s.eFlags |= GMAIN_EF_NODRAW;
        } else {
            ent->s.eFlags &= ~GMAIN_EF_NODRAW;
        }
    }

    if (ent->s.eFlags == GMAIN_EFLAGS_UNKNOWN && level.time > ent->s.time2) {
        G_FreeEntity(ent);
        return 0;
    }

    if (level.time - ent->eventTime > 300) {
        if (ent->freeAfterEvent) {
            G_FreeEntity(ent);
            return 0;
        }

        if (ent->unlinkAfterEvent) {
            ent->unlinkAfterEvent = 0;
            SV_UnlinkEntity(ent);
        }
    }

    if (ent->freeAfterEvent) {
        return 0;
    }

    if (ent->s.eType == GMAIN_ET_MISSILE) {
        G_RunMissile(ent);
        return 0;
    }

    if (ent->s.eType == GMAIN_ET_ITEM) {
        if (ent->tagInfo) {
            G_GeneralLink(ent);
            G_RunThink(ent);
            return 0;
        }

        G_RunItem(ent);
        return 0;
    }

    if (ent->s.eType == GMAIN_ET_PLAYER_CORPSE) {
        G_RunCorpse(ent);
        return 0;
    }

    if (ent->physicsObject) {
        G_RunItem(ent);
        return 0;
    }

    if (ent->s.eType == GMAIN_ET_SCRIPTMOVER) {
        G_RunMover(ent);
        return 0;
    }

    if (ent->client) {
        G_RunClient(ent);
        return 0;
    }

    if (ent->s.eType == GMAIN_ET_GENERAL && ent->tagInfo) {
        G_GeneralLink(ent);
    }

    G_RunThink(ent);
    return 0;
}

/* line 1503 */
int G_RunFrame(int levelTime) {
    int i, j;
    unsigned char entIndex[0x400];
    unsigned char index;
    int bMoreTriggered;
    int triggerCount;
    gentity_t *entPtr;
    trigger_info_t *triggerInfo;
    unsigned short entNum, otherNum;
    int savedTriggerCount;
    const scr_const_t *scr = SCR_CONST();

    /* Update level timing */
    level.framenum += 1;
    level.previousTime = level.time;
    level.time = levelTime;
    level.frametime = levelTime - level.previousTime;

    level_bgs.time = levelTime;
    level_bgs.latestSnapshotTime = levelTime;
    level_bgs.frametime = level.frametime;

    *(bgs_t **)imp_bgs = &level_bgs;

    /* SV_DObjInitServerTime for active entities */
    for (i = 0; i < level.num_entities; i++) {
        entPtr = &g_entities[i];
        if (entPtr->r.inuse) {
            float dt = (float)level.frametime * 0.001f;
            SV_DObjInitServerTime(entPtr, dt);
        }
    }

    /* Clear entIndex */
    memset(entIndex, 0, 0x400);

    /* Copy trigger info to backup */
    triggerCount = level.pendingTriggerListSize;
    Com_Memcpy(level.currentTriggerList, level.pendingTriggerList, triggerCount * sizeof(level.currentTriggerList[0]));
    level.currentTriggerListSize = triggerCount;
    level.pendingTriggerListSize = 0;

    index = 0;

    /* Process triggers repeatedly until no more are fired */
    do {
        index += 1;
        savedTriggerCount = level.currentTriggerListSize;
        bMoreTriggered = 0;

        if (savedTriggerCount <= 0) {
            /* No triggers pending */
        } else {
            j = 0;
            triggerInfo = level.currentTriggerList;
            while (j < level.currentTriggerListSize) {
                trigger_info_t *info = &triggerInfo[j];
                entNum = info->entnum;
                entPtr = &g_entities[entNum];
                /* Check generation counts match */
                if (entPtr->useCount != info->useCount) {
                    /* Generation mismatch - remove this trigger */
                    int last = level.currentTriggerListSize - 1;
                    level.currentTriggerListSize = last;
                    triggerInfo[j] = triggerInfo[last];
                    continue;
                } else {
                    /* Check other entity generation */
                    gentity_t *otherEnt;

                    otherNum = info->otherEntnum;
                    otherEnt = &g_entities[otherNum];
                    if (otherEnt->useCount != info->otherUseCount) {
                        /* Other entity generation mismatch - remove */
                        int last = level.currentTriggerListSize - 1;
                        level.currentTriggerListSize = last;
                        triggerInfo[j] = triggerInfo[last];
                        continue;
                    } else {
                        /* Check if already processed this frame */
                        if (entIndex[entNum] != index) {
                            /* Fire trigger */
                            entIndex[entNum] = index;
                            Scr_AddEntity(otherEnt);
                            Scr_Notify(entPtr, (int)scr->trigger, 1);
                            /* Remove this trigger entry */
                            {
                                int last = level.currentTriggerListSize - 1;
                                level.currentTriggerListSize = last;
                                triggerInfo[j] = triggerInfo[last];
                            }
                            continue;
                        } else {
                            bMoreTriggered = 1;
                        }
                    }
                }
                j++;
            }
        }

        Scr_RunCurrentThreads();
    } while (bMoreTriggered);

    /* G_DObjUpdateServerTime loop */
    for (i = 0; i < level.num_entities; i++) {
        entPtr = &g_entities[i];
        if (!entPtr->r.inuse)
            continue;
        if (entPtr->flags & 0x2000) /* NODRAW-related flag, tested as byte[1] & 0x20 */
            continue;
        while (1) {
            if (!G_DObjUpdateServerTime(entPtr, 1))
                break;
            Scr_RunCurrentThreads();
            if (!entPtr->r.inuse)
                break;
            if (entPtr->flags & 0x2000)
                break;
        }
    }

    Scr_IncTime();

    /* Run frame for entities */
    level.currentEntityThink = 0;
    for (i = 0; i < level.num_entities; i++) {
        entPtr = &g_entities[i];
        if (entPtr->r.inuse) {
            /* If entity has a parent (tagInfo->parent), run parent first */
            tagInfo_t *tagInfo = (tagInfo_t *)entPtr->tagInfo;
            if (tagInfo) {
                gentity_t *parent = tagInfo->parent;
                G_RunFrameForEntity(parent);
            }
            G_RunFrameForEntity(entPtr);
        }
        level.currentEntityThink = i + 1;
    }
    level.currentEntityThink = -1;

    /* Update objective data for connected clients */
    {
        int numClients = level.maxclients;
        for (i = 0; i < numClients; i++) {
            gentity_t *ent2 = &level.gentities[i];
            if (!ent2->r.inuse)
                continue;
            gclient_t *cli = ent2->client;
            int lastObjId = cli->sess.cs.team;

            for (j = 0; j < 16; j++) {
                objective_t *srcObj = &level.objectives[j];
                objective_t *dstObj = &cli->ps.objective[j];

                if (srcObj->state == 0 || srcObj->teamNum == 0) {
                    if (srcObj->state != 0 && srcObj->teamNum == lastObjId) {
                        *dstObj = *srcObj;
                    } else {
                        dstObj->state = 0;
                    }
                } else {
                    *dstObj = *srcObj;
                }
            }
        }
    }

    /* HudElem updates */
    {
        int numClients = level.maxclients;
        for (i = 0; i < numClients; i++) {
            gentity_t *ent2 = &level.gentities[i];
            if (!ent2->r.inuse)
                continue;
            HudElem_UpdateClient(ent2->client,
                                 ent2->s.number, 3);
        }
    }

    /* ClientEndFrame for active clients */
    {
        int numClients = level.maxclients;
        for (i = 0; i < numClients; i++) {
            entPtr = &g_entities[i];
            if (entPtr->r.inuse) {
                ClientEndFrame(entPtr);
            }
        }
    }

    CheckTeamStatus();

    /* Vote checking */
    if (g_oldVoting->current.integer) {
        CheckVote();
    }

    /* DeathmatchScoreboardMessage for spectators */
    if (level.bUpdateScoresForIntermission) {
        int numClients = level.maxclients;
        int foundAny = 0;
        for (i = 0; i < numClients; i++) {
            gclient_t *cl2 = &level.clients[i];
            if (cl2->sess.connected != CON_CONNECTED)
                continue;
            if (cl2->ps.pm_type != 5)
                continue;
            DeathmatchScoreboardMessage(&g_entities[i]);
            foundAny = 1;
        }
        if (!foundAny || numClients <= 0) {
            level.bUpdateScoresForIntermission = 0;
        }
    }

    /* List entities debug */
    if (g_listEntity->current.integer) {
        for (i = 0; i < 0x400; i++) {
            entPtr = &g_entities[i];
            Com_Printf("%4i: %s\n", i,
                (const char *)SL_ConvertToString(entPtr->classname));
        }
        Dvar_SetBool(g_listEntity, 0);
    }

    /* Save weapons/items if flagged */
    if (level.registerWeapons) {
        SaveRegisteredWeapons();
    }
    if (level.bRegisterItems) {
        SaveRegisteredItems();
    }

    /* Dump anims */
    if (g_dumpAnims->current.integer >= 0) {
        Com_Printf("---------- Animtree dump ----------\n");
        {
            int animIdx = g_dumpAnims->current.integer;
            entPtr = &level.gentities[animIdx];
            SV_DObjDisplayAnim(entPtr);
        }
    }

    *(void **)imp_bgs = NULL;
    return 0;
}
