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

__asm__(".Lginit_fmt: .asciz \"[G_InitGame] level.clients=%p\\n\"\n");
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

    if (*(int *)((char *)&level + 24) <= 0)
        return 0;

    va_start(argptr, fmt);
    vsnprintf(string2, 1024, fmt, argptr);
    va_end(argptr);

    sec = *(int *)((char *)&level + 492) / 1000;
    min = sec / 60;
    sec %= 60;
    tens = sec / 10;
    ones = sec % 10;

    Com_sprintf(string, 1024, "%3i:%i%i %s", min, tens, ones, string2);
    FS_Write(string, strlen(string), *(int *)((char *)&level + 24));

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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int G_InitGame(int levelTime, int randomSeed, qboolean restart, qboolean savepersist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 763 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x82c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* levelTime */
        "movl 0xc(%ebp), %esi\n" /* randomSeed */
        /* { scope 1: serverinfo */
        "movl $str_002b449c, (%esp)\n" /* line 770 */
        "calll Com_Printf\n"
        "movl $str_002b44c4, 4(%esp)\n" /* line 771 */
        "movl $str_002b44d4, (%esp)\n" /* "gamename: %s\n" */
        "calll Com_Printf\n"
        "movl $str_002b44e4, 4(%esp)\n" /* line 772 */
        "movl $str_002b44f0, (%esp)\n" /* "gamedate: %s\n" */
        "calll Com_Printf\n"
        "calll Swap_Init\n" /* line 774 */
        "movl $0x3624, 8(%esp)\n" /* line 776 */
        "movl $0, 4(%esp)\n"
        "movl $level, (%esp)\n"
        "calll memset\n"
        "movl $1, level+28\n" /* line 778 */
        "movl %ebx, level+492\n" /* line 779 | i */
        "movl %ebx, level+504\n" /* line 780 | i */
        "movl $0xffffffff, level+13828\n" /* line 781 */
        "movl $g_entities, level+4\n" /* level.gentities = g_entities (decompiler missed) */
        "movl $g_clients, level\n" /* level.clients = g_clients (decompiler missed) */
        /* DEBUG: verify level.clients was set */
        "pushl %esi\n"
        "pushl level\n"
        "pushl $.Lginit_fmt\n"
        "calll G_InitDbgPrint\n"
        "addl $8, %esp\n"
        "popl %esi\n"
        "movl %esi, (%esp)\n" /* line 783 | randomSeed */
        "calll srand\n"
        "movl %esi, (%esp)\n" /* line 784 | randomSeed */
        "calll Rand_Init\n"
        "calll G_SetupWeaponDef\n" /* line 786 */
        "calll G_RegisterDvars\n" /* early call to ensure g_gametype is set before gametype check */
        "calll BG_RegisterDvars\n" /* register bgame dvars (bg_bobMax etc.) on server side */
        "movl $level+520, %edi\n" /* edi = &level.teamFlags for gametype check */
        "movl 0x10(%ebp), %edx\n" /* line 788 | restart */
        "testl %edx, %edx\n"
        "je .Lf1abbfa_001abf7c\n"
        "movl 0x14(%ebp), %eax\n" /* savepersist */
        "testl %eax, %eax\n"
        "je .Lf1abbfa_001abf7c\n"
        ".Lf1abbfa_001abcac:\n"
        "calll G_ProcessIPBans\n" /* line 791 */
        "movl imp_SV_XModelGet, %eax\n" /* line 793 */
        "movl %eax, level_bgs+736236\n"
        "movl $G_CreateDObj, level_bgs+736240\n" /* line 794 */
        "movl imp_Com_SafeServerDObjFree, %eax\n" /* line 795 */
        "movl %eax, level_bgs+736244\n"
        "movl $Hunk_AllocXAnimServer, level_bgs+736248\n" /* line 796 */
        "movl $1, level_bgs+736232\n" /* line 797 */
        "movl g_log, %eax\n" /* line 799 */
        "movl 8(%eax), %edx\n"
        "cmpb $0, (%edx)\n"
        "je .Lf1abbfa_001ac918\n"
        "movl g_logSync, %eax\n" /* line 801 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1abbfa_001ac810\n"
        "movl $3, 8(%esp)\n" /* line 802 */
        "movl $level+24, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        ".Lf1abbfa_001abd05:\n"
        "movl $str_002b4500, (%esp)\n" /* line 808 */
        "calll G_LogPrintf\n"
        "movl $str_002b4898, (%esp)\n" /* line 809 */
        "calll G_LogPrintf\n"
        "movl $level_bgs+813548, 8(%esp)\n" /* line 812 */
        "movl $0x400, 4(%esp)\n"
        "movl $str_002b450c, (%esp)\n" /* "sv_mapname" */
        "calll SV_GetServerinfo\n"
        "movl $level_bgs+813548, 4(%esp)\n" /* line 813 */
        "movl $str_002b451c, (%esp)\n"
        "calll G_LogPrintf\n"
        ".Lf1abbfa_001abd40:\n"
        /* Initialize scrVarPub field buffer before entity spawning */
        /* Scr_FindField dereferences scrVarPub[0] which is NULL until Scr_AddFields runs */
        "movl $0, (%esp)\n"
        "calll Hunk_AllocLowInternal\n"
        "movl %eax, scrVarPub\n"
        "movb $0, (%eax)\n"
        "movl $g_entities, 0xc(%esp)\n" /* line 815 */
        "movl $0xa04, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl $g_clients, (%esp)\n"
        "calll SV_LocateGameData\n"
        "movl $0x230, 8(%esp)\n" /* line 817 */
        "movl $0x400, 4(%esp)\n"
        "movl $g_entities, (%esp)\n"
        "calll G_SpawnEntitiesFromString\n"
        "pushl %ebx\n" "pushl %esi\n" "pushl %edi\n"
        "movl $str_dbg_spawn, (%esp)\n" "calll DBG_PrintFreeVars\n"
        "popl %edi\n" "popl %esi\n" "popl %ebx\n"
        "movl $0, level+28\n" /* line 818 */
        "movl level+12, %eax\n" /* line 820 */
        "movl %eax, 0xc(%esp)\n"
        "movl level+16, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $str_002b452c, 4(%esp)\n" /* "%i+%i entity slots, %i+%i client slots\n" */
        "movl level+484, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $str_002acda0, (%esp)\n" /* line 820 */
        "calll Com_Printf\n"
        ".Lf1abbfa_001abda0:\n"
        "movl g_gametype, %ebx\n" /* line 822 */
        "movl 8(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b4580, (%esp)\n" /* "gametype: %s\n" */
        "calll G_LogPrintf\n"
        "calll G_InitTurrets\n" /* line 824 */
        "calll SV_GetBrushModelCount\n" /* line 825 */
        "addl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SpawnTriggerHurt\n"
        "calll GScr_PostResetTimeout\n" /* line 826 */
        "calll G_SetupWeaponDef\n" /* line 828 */
        "calll Scr_BeginLoadScripts\n" /* line 829 */
        "movl $1, (%esp)\n" /* line 830 */
        "calll GScr_LoadScripts\n"
        "pushl %ebx\n" "pushl %esi\n" "pushl %edi\n"
        "movl $str_dbg_load, (%esp)\n" "calll DBG_PrintFreeVars\n"
        "popl %edi\n" "popl %esi\n" "popl %ebx\n"
        /* Scr_EndLoadScripts already called inside GScr_LoadScripts — removed duplicate */
        "calll GScr_LoadConsts\n" /* line 833: was NOP'd raw Mac addr, restored */
        "movl $1, (%esp)\n" /* line 834 */
        "calll Scr_FreeScripts\n"
        "calll Scr_BeginLoadAnimScripts\n" /* line 835 */
        "calll GScr_LoadAnimScripts\n" /* line 836 */
        "calll Scr_EndLoadAnimScripts\n" /* line 837 */
        "calll G_RegisterDvars\n" /* line 839 */
        /* Fix #154: Missing init calls — were raw Mac addresses that got NOP'd */
        "pushl scrVmPub+16\n"
        "pushl $str_dbg_vmtop_fmt\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        "calll Scr_FreeEntityList\n"
        "calll Scr_InitSystem\n"          /* sets scrVarPub.levelId, timeArrayId, etc */
        "pushl scrVmPub+12\n"
        "pushl $str_dbg_ff_trace\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        "movl $1, (%esp)\n"
        "calll Scr_SetLoading\n"          /* scrVmPub.loading = true */
        "calll Scr_AllocGameVariable\n"   /* alloc game-level script vars */
        "pushl scrVmPub+12\n"
        "pushl $str_dbg_ff_agv\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        "calll G_LoadStructs\n" /* load script_struct entities */
        "pushl scrVmPub+12\n"
        "pushl $str_dbg_ff_gls\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        /* Script init — originally dispatched through game module export table.
           Scr_LoadLevel runs mp_toujane::main() to set game["allies"]/game["axis"].
           Scr_LoadGameType runs dm::main(). Scr_StartupGameType runs Callback_StartGameType.
           Must run with level.initializing=1 so PrecacheString/PrecacheModel work. */
        "movl $1, level+28\n" /* re-enable precache for gametype script init */
        "pushl %ebx\n" "pushl %esi\n" "pushl %edi\n"
        "calll Scr_LoadLevel\n" /* Fix #155: run map script first to set team vars */
        "pushl scrVmPub+12\n"
        "pushl $str_dbg_ff_before\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        "calll Scr_LoadGameType\n"
        "pushl scrVmPub+12\n"
        "pushl $str_dbg_ff_after_load\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        "calll Scr_StartupGameType\n"
        "pushl scrVmPub+12\n"
        "pushl $str_dbg_ff_after_startup\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        "popl %edi\n" "popl %esi\n" "popl %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* line 842 | restart */
        "testl %eax, %eax\n"
        "je .Lf1abbfa_001ac0a1\n"
        "movl 0x14(%ebp), %edx\n" /* line 843 | savepersist */
        "testl %edx, %edx\n"
        "jne .Lf1abbfa_001ac0a1\n"
        "calll RestoreBody\n" /* line 844 */
        ".Lf1abbfa_001ac0a1:\n"
        "movl g_maxclients, %esi\n" /* line 848 */
        "movl 8(%esi), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf1abbfa_001ac7c8\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf1abbfa_001ac0d0\n"
        ".Lf1abbfa_001ac0bd:\n"
        "addl $1, %ebx\n"
        "cmpl 8(%esi), %ebx\n"
        "jge .Lf1abbfa_001ac7c8\n"
        ".Lf1abbfa_001ac0d0:\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* line 850 */
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%ebx, %eax, 8), %eax\n"
        "movl level, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "cmpl $2, 0x26c4(%eax)\n"
        "jne .Lf1abbfa_001ac0bd\n"
        "movl %eax, 8(%esp)\n" /* line 851 */
        "leal (%ebx, %ebx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl $g_entities, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ClientUserinfoChanged\n"
        "movl g_maxclients, %esi\n"
        "addl $1, %ebx\n" /* line 848 */
        "cmpl 8(%esi), %ebx\n"
        "jl .Lf1abbfa_001ac0d0\n"
        ".Lf1abbfa_001ac7c8:\n"
        "movl $level+520, %edi\n" /* line 855 */
        "movl $0, level+520\n"
        "movl g_dedicated, %edx\n"
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1abbfa_001ac7f1\n"
        "movl g_password, %eax\n" /* line 861 */
        "movl 8(%eax), %edx\n"
        "cmpb $0, (%edx)\n"
        "je .Lf1abbfa_001ac7f1\n"
        "movl %edx, 8(%esp)\n" /* line 863 */
        "movl $str_002b458c, 4(%esp)\n" /* "password: %s\n" */
        "leal -0x818(%ebp), %eax\n" /* info */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf1abbfa_001ac7f1:\n"
        "calll CalculateRanks\n" /* line 865 */
        "movl $0, level+28\n" /* line 866 */
        /* } scope */
        "addl $0x82c, %esp\n" /* line 867 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1abbfa_001ac810:\n"
        "movl $1, 8(%esp)\n" /* line 804 */
        "movl $level+24, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "jmp .Lf1abbfa_001abd05\n"
        ".Lf1abbfa_001abf7c:\n"
        "movl g_gametype, %eax\n" /* line 831 */
        "movl 8(%eax), %esi\n"
        "movl $str_002b45a4, 4(%esp)\n" /* line 170 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1abbfa_001abfb0\n"
        "movl $1, 0xc(%edi)\n" /* line 171 */
        "movl $1, 8(%edi)\n"
        ".Lf1abbfa_001abfa8:\n"
        "movl $0, (%edi)\n" /* line 191 */
        "jmp .Lf1abbfa_001abcac\n"
        ".Lf1abbfa_001abfb0:\n"
        "movl $str_002b45a8, 4(%esp)\n" /* line 174 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1abbfa_001abfe0\n"
        "movl $1, 0xc(%edi)\n" /* line 175 */
        "movl $1, 8(%edi)\n"
        "jmp .Lf1abbfa_001abfa8\n"
        ".Lf1abbfa_001abfe0:\n"
        "movl $str_002a67e8, 4(%esp)\n" /* line 178 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1abbfa_001ac010\n"
        "movl $1, 0xc(%edi)\n" /* line 179 */
        "movl $1, 8(%edi)\n"
        "jmp .Lf1abbfa_001abfa8\n"
        ".Lf1abbfa_001ac010:\n"
        "movl $str_002b45b0, 4(%esp)\n" /* line 182 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1abbfa_001ac040\n"
        "movl $1, 0xc(%edi)\n" /* line 183 */
        "movl $1, 8(%edi)\n"
        "jmp .Lf1abbfa_001abfa8\n"
        ".Lf1abbfa_001ac040:\n"
        "movl $str_002b45b4, 4(%esp)\n" /* line 186 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1abbfa_001abfa8\n"
        "movl $1, 0xc(%edi)\n" /* line 187 */
        "movl $1, 8(%edi)\n"
        "jmp .Lf1abbfa_001abfa8\n"
        ".globl G_RegisterDvars\n"
        "G_RegisterDvars:\n"
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "subl $0x20, %esp\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 112 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002a7100, (%esp)\n" /* "g_gametype" */
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_gametype\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 113 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_0021675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_RegisterInt\n"
        ".Lf1abbfa_001ac124:\n"
        "movl %eax, g_dedicated\n"
        "movl $0, 0x10(%esp)\n" /* line 114 */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002198ac, (%esp)\n" /* "sv_cheats" */
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_cheats\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 115 */
        "movl $0x40, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002a70dc, (%esp)\n" /* "sv_maxclients" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_maxclients\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 118 */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002ab490, (%esp)\n" /* "g_password" */
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_password\n"
        "movl $0x800, 0x10(%esp)\n" /* line 119 */
        "movl $0x320, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x320, 4(%esp)\n"
        "movl $str_002b4550, (%esp)\n" /* "g_gravity" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_gravity\n"
        "movl $0x800, 0x10(%esp)\n" /* line 120 */
        "movl $0xc8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0xbe, 4(%esp)\n"
        "movl $str_002b45f8, (%esp)\n" /* "g_speed" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_speed\n"
        "movl $0x800, 0x10(%esp)\n" /* line 121 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3e8, 4(%esp)\n"
        "movl $str_002b455c, (%esp)\n" /* "g_knockback" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_knockback\n"
        "movl $0, 0x10(%esp)\n" /* line 122 */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b460c, (%esp)\n" /* "g_useholdtime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_useholdtime\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b461c, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_useholdspawndelay\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_00218eb4, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_inactivity\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4640, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_debugDamage\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4650, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_debugBullets\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4660, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_weaponAmmoPools\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0x10, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl $str_002b4674, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_maxDroppedWeapons\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b468c, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_synchronousClients\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b46a4, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_motd\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_00219528, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_allowVote\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b46b8, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_dropForwardSpeed\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b46d0, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_dropUpSpeedBase\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002a67e4, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_dropUpSpeedRand\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b46f8, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_clonePlayerMaxVelocity\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4714, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, voice_localEcho\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4724, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, voice_global\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4730, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, voice_deadChat\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b473c, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_voiceChatTalkingDuration\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b46d0, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_deadChat\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4764, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_banIPs\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_002b4770, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_smoothClients\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4780, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_NoScriptSpam\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4790, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_debugLocDamage\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b47a4, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_friendlyfireDist\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b47bc, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_friendlyNameDist\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b47d4, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, player_meleeRange\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b47e4, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_meleeWidth\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b47f4, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_meleeHeight\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_002b4808, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_antilag\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $str_002b4814, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_oldVoting\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4820, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_playerCollisionEjectSpeed\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4840, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_mantleBlockTimeBuffer\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b485c, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_log\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4864, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_logSync\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4870, (%esp)\n"
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, g_listEntity\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b487c, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_ScoresBanner_Allies\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4858, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_ScoresBanner_Axis\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b488c, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_ScoresBanner_None\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b48a0, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_ScoresBanner_Spectators\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b48b8, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_TeamName_Allies\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b48c8, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_TeamName_Axis\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002160e8, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_TeamColor_Allies\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b48e0, (%esp)\n"
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, g_TeamColor_Axis\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b48ec, (%esp)\n"
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_voteAbstainWeight\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl $str_002b482c, (%esp)\n" /* "g_dumpAnims" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_dumpAnims\n"
        "movl $0x800, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002b4908, (%esp)\n"
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_ScoresBanner_Allies\n"
        "leave\n"
        "retl\n"
        ".Lf1abbfa_001ac918:\n"
        "movl $0xffffffff, level+24\n" /* line 807 */
        "movl $str_002b48e8, (%esp)\n" /* line 820 */
        "calll Com_Printf\n"
        "jmp .Lf1abbfa_001abd40\n"
        ".Lf1abbfa_001ac929:\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 123 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_0021675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_RegisterInt\n"
        "jmp .Lf1abbfa_001ac124\n"
    );
}
#else
int G_InitGame(int levelTime, int randomSeed, qboolean restart, qboolean savepersist) { return 0; }
#endif

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
    char *ptr;

    Com_Printf((const char *)str_002b4950);

    if (*(int *)((char *)&level + 24) > 0) {
        G_LogPrintf((const char *)str_002b4968);
        G_LogPrintf((const char *)str_002b4898);
        FS_FCloseFile(*(int *)((char *)&level + 24));
    }

    *(int *)imp_bgs = 0;

    for (i = 0; i < *(int *)((char *)&level + 12); i++) {
        if (*(char *)((char *)&g_entities[i] + 0xfc))
            G_FreeEntity(&g_entities[i]);
    }

    if (*(char *)((char *)&g_entities + 572572))
        G_FreeEntity((gentity_t *)((char *)&g_entities + 572320));

    *(int *)((char *)&level + 12) = 0;
    *(int *)((char *)&level + 16) = 0;
    *(int *)((char *)&level + 20) = 0;

    HudElem_DestroyAll();

    if (Scr_IsSystemActive(1)) {
        if (!*(int *)((char *)&level + 7508))
            SV_FreeClientScriptPers();
    }

    Scr_ShutdownSystem(1, *(int *)((char *)&level + 7508) == 0);

    if (freeScripts) {
        Mantle_ShutdownAnims();
        GScr_FreeScripts();
        Scr_FreeScripts(0); /* full shutdown — zero code base */

        /* Free XAnimTrees in level_bgs (stride 0x4b8) */
        for (ptr = (char *)&level_bgs; ptr != (char *)((char *)&level_bgs + 77312); ptr += 0x4b8) {
            struct XAnimTree_s *tree = *(struct XAnimTree_s **)(ptr + 0xb40a0);
            if (tree) {
                XAnimFreeTree(tree, 0);
                *(struct XAnimTree_s **)(ptr + 0xb40a0) = NULL;
            }
        }

        /* Free XAnimTrees in clients (stride 0x4c8) */
        {
            char *clients_base = (char *)imp_g_scr_data;
            char *clients_end = clients_base + 0x2640;
            for (ptr = clients_base; ptr != clients_end; ptr += 0x4c8) {
                struct XAnimTree_s *tree = *(struct XAnimTree_s **)(ptr + 0x10b8);
                if (tree) {
                    XAnimFreeTree(tree, 0);
                    *(struct XAnimTree_s **)(ptr + 0x10b8) = NULL;
                }
            }
        }

        Hunk_ClearToMarkLow(0);
    }

    if (*(void * *)((char *)&level + 13836)) {
        Z_FreeInternal(*(void * *)((char *)&level + 13836));
    }
    *(int *)((char *)&level + 13836) = 0;

    if (*(int *)((char *)&level + 13832) >= 0) {
        FS_FCloseFile(*(int *)((char *)&level + 13832));
    }
    *(int *)((char *)&level + 13832) = -1;

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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int G_RunFrame(int levelTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1503 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        "movl 8(%ebp), %eax\n" /* levelTime */
        /* { scope 1 */
        "addl $1, level+488\n" /* line 1518 */
        "movl level+492, %edx\n" /* line 1519 */
        "movl %edx, level+496\n"
        "movl %eax, level+492\n" /* line 1520 */
        "movl %eax, %ecx\n" /* line 1521 */
        "subl %edx, %ecx\n"
        "movl %ecx, level+500\n"
        "movl %eax, level_bgs+736220\n" /* line 1523 */
        "movl %eax, level_bgs+736224\n" /* line 1524 */
        "movl %ecx, level_bgs+736228\n" /* line 1525 */
        "movl imp_bgs, %eax\n" /* line 1528 */
        "movl $level_bgs, (%eax)\n"
        "movl level+12, %eax\n" /* line 1535 */
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad15b\n"
        "movl $g_entities, %ebx\n" /* trigger_info */
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf1ad0b4_001ad123\n"
        ".Lf1ad0b4_001ad112:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl level+12, %esi\n" /* i */
        "jge .Lf1ad0b4_001ad15b\n"
        ".Lf1ad0b4_001ad123:\n"
        "cmpb $0, 0xfc(%ebx)\n" /* line 1537 | trigger_info */
        "je .Lf1ad0b4_001ad112\n"
        "cvtsi2ssl level+500, %xmm0\n" /* line 1538 */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* trigger_info */
        "calll SV_DObjInitServerTime\n"
        "addl $1, %esi\n" /* line 1535 | i */
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl level+12, %esi\n" /* i */
        "jl .Lf1ad0b4_001ad123\n"
        ".Lf1ad0b4_001ad15b:\n"
        "leal -0x418(%ebp), %eax\n" /* line 1543 | entIndex */
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl level+13800, %eax\n" /* line 1550 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $level+7656, 4(%esp)\n"
        "movl $level+10728, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl level+13800, %eax\n" /* line 1551 */
        "movl %eax, level+13804\n"
        "movl $0, level+13800\n" /* line 1552 */
        "movb $0, -0x429(%ebp)\n" /* index */
        ".Lf1ad0b4_001ad1b7:\n"
        "addb $1, -0x429(%ebp)\n" /* line 1557 | index */
        "movl level+13804, %eax\n" /* line 1558 */
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad602\n"
        "xorl %edi, %edi\n"
        "movl $0, -0x430(%ebp)\n" /* bMoreTriggered */
        "movl $level+10720, %esi\n" /* i */
        "jmp .Lf1ad0b4_001ad223\n"
        ".Lf1ad0b4_001ad1de:\n"
        "movl level+13804, %eax\n" /* line 1580 */
        "subl $1, %eax\n"
        "movl %eax, level+13804\n"
        "subl $1, %edi\n" /* line 1581 */
        "subl $0xc, %esi\n" /* i */
        "leal (%eax, %eax, 2), %eax\n" /* line 1582 */
        "shll $2, %eax\n"
        "movl level+10728(%eax), %edx\n"
        "movl %edx, (%ebx)\n" /* trigger_info */
        "movl level+10732(%eax), %edx\n"
        "movl %edx, 4(%ebx)\n" /* trigger_info */
        "movl level+10736(%eax), %eax\n"
        "movl %eax, 8(%ebx)\n" /* trigger_info */
        "addl $1, %edi\n" /* line 1558 */
        "addl $0xc, %esi\n" /* i */
        "cmpl level+13804, %edi\n"
        "jge .Lf1ad0b4_001ad2a8\n"
        ".Lf1ad0b4_001ad223:\n"
        "leal 8(%esi), %ebx\n" /* line 1560 | i, trigger_info */
        "movzwl 8(%esi), %ecx\n" /* line 1561 | i */
        "leal (%ecx, %ecx, 4), %eax\n" /* line 1562 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl $g_entities, %edx\n"
        "movl %edx, -0x41c(%ebp)\n"
        "movl 0x228(%edx), %eax\n" /* line 1563 */
        "cmpl 0xc(%esi), %eax\n" /* i */
        "jne .Lf1ad0b4_001ad1de\n"
        "movzwl 2(%ebx), %eax\n" /* line 1566 | trigger_info */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl $g_entities, %edx\n"
        "movl 0x228(%edx), %eax\n" /* line 1567 */
        "cmpl 8(%ebx), %eax\n" /* trigger_info */
        "jne .Lf1ad0b4_001ad1de\n"
        "movzbl -0x429(%ebp), %eax\n" /* line 1570 | index */
        "cmpb -0x418(%ebp, %ecx), %al\n"
        "jne .Lf1ad0b4_001ad624\n"
        "movl $1, -0x430(%ebp)\n" /* bMoreTriggered */
        "addl $1, %edi\n" /* line 1558 */
        "addl $0xc, %esi\n" /* i */
        "cmpl level+13804, %edi\n"
        "jl .Lf1ad0b4_001ad223\n"
        ".Lf1ad0b4_001ad2a8:\n"
        "calll Scr_RunCurrentThreads\n" /* line 1585 */
        "movl -0x430(%ebp), %eax\n" /* line 1554 | bMoreTriggered */
        "testl %eax, %eax\n"
        "jne .Lf1ad0b4_001ad1b7\n"
        ".Lf1ad0b4_001ad2bb:\n"
        "movl level+12, %eax\n" /* line 1593 */
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad33e\n"
        "movl $g_entities, %edi\n"
        "xorl %esi, %esi\n" /* i */
        "movl $g_entities+252, %ebx\n" /* trigger_info */
        "jmp .Lf1ad0b4_001ad2e9\n"
        ".Lf1ad0b4_001ad2d2:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x230, %edi\n"
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl level+12, %esi\n" /* i */
        "jge .Lf1ad0b4_001ad33e\n"
        ".Lf1ad0b4_001ad2e9:\n"
        "cmpb $0, (%ebx)\n" /* line 1373 */
        "je .Lf1ad0b4_001ad2d2\n"
        "leal 0x78(%ebx), %edx\n" /* line 1503 */
        "movl %edx, -0x420(%ebp)\n"
        "testb $0x20, 0x79(%ebx)\n" /* line 1373 */
        "jne .Lf1ad0b4_001ad2d2\n"
        ".Lf1ad0b4_001ad2fd:\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll G_DObjUpdateServerTime\n"
        "testl %eax, %eax\n"
        "je .Lf1ad0b4_001ad2d2\n"
        "calll Scr_RunCurrentThreads\n" /* line 1374 */
        "cmpb $0, (%ebx)\n" /* line 1373 */
        "je .Lf1ad0b4_001ad2d2\n"
        "movl -0x420(%ebp), %ecx\n"
        "testb $0x20, 1(%ecx)\n"
        "je .Lf1ad0b4_001ad2fd\n"
        "addl $1, %esi\n" /* line 1593 | i */
        "addl $0x230, %edi\n"
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl level+12, %esi\n" /* i */
        "jl .Lf1ad0b4_001ad2e9\n"
        ".Lf1ad0b4_001ad33e:\n"
        "calll Scr_IncTime\n" /* line 1598 */
        "movl $0, level+13828\n" /* line 1607 */
        "movl level+12, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad39e\n"
        "movl $g_entities, %esi\n" /* i */
        "movl $g_entities+252, %ebx\n" /* trigger_info */
        ".Lf1ad0b4_001ad360:\n"
        "cmpb $0, (%ebx)\n" /* line 1609 | trigger_info */
        "je .Lf1ad0b4_001ad37d\n"
        "movl 0x10c(%ebx), %eax\n" /* line 1615 | trigger_info */
        "testl %eax, %eax\n"
        "je .Lf1ad0b4_001ad376\n"
        "movl (%eax), %eax\n" /* line 1618 */
        "calll G_RunFrameForEntity\n"
        ".Lf1ad0b4_001ad376:\n"
        "movl %esi, %eax\n" /* line 1621 | i */
        "calll G_RunFrameForEntity\n"
        ".Lf1ad0b4_001ad37d:\n"
        "movl level+13828, %eax\n" /* line 1607 */
        "addl $1, %eax\n"
        "movl %eax, level+13828\n"
        "addl $0x230, %esi\n" /* i */
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl level+12, %eax\n"
        "jl .Lf1ad0b4_001ad360\n"
        ".Lf1ad0b4_001ad39e:\n"
        "movl $0xffffffff, level+13828\n" /* line 1623 */
        "movl level+484, %eax\n" /* line 1275 */
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad4aa\n"
        "movl $0, -0x428(%ebp)\n"
        "movl $0, -0x424(%ebp)\n"
        ".Lf1ad0b4_001ad3c9:\n"
        "movl -0x424(%ebp), %eax\n" /* line 1277 */
        "addl level+4, %eax\n"
        "cmpb $0, 0xfc(%eax)\n" /* line 1278 */
        "je .Lf1ad0b4_001ad487\n"
        "movl 0x158(%eax), %eax\n" /* line 1281 */
        "movl 0x274c(%eax), %edi\n" /* line 1282 */
        "movl %eax, %ecx\n"
        "movl $level+36, %ebx\n"
        "movl $level+484, %esi\n"
        "jmp .Lf1ad0b4_001ad414\n"
        ".Lf1ad0b4_001ad3fc:\n"
        "cmpl %eax, %edi\n" /* line 1287 */
        "je .Lf1ad0b4_001ad421\n"
        ".Lf1ad0b4_001ad400:\n"
        "movl $0, 0x5e4(%ecx)\n" /* line 1288 */
        "addl $0x1c, %ebx\n" /* line 1290 */
        "addl $0x1c, %ecx\n"
        "cmpl %ebx, %esi\n" /* line 1284 */
        "je .Lf1ad0b4_001ad487\n"
        ".Lf1ad0b4_001ad414:\n"
        "movl (%ebx), %eax\n" /* line 1287 */
        "testl %eax, %eax\n"
        "je .Lf1ad0b4_001ad400\n"
        "movl 0x14(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1ad0b4_001ad3fc\n"
        ".Lf1ad0b4_001ad421:\n"
        "movl %ebx, %edx\n" /* line 1290 */
        "subl $level+36, %edx\n"
        "movl level+36(%edx), %eax\n"
        "movl %eax, 0x5e4(%ecx)\n"
        "movl level+40(%edx), %eax\n"
        "movl %eax, 0x5e8(%ecx)\n"
        "movl level+44(%edx), %eax\n"
        "movl %eax, 0x5ec(%ecx)\n"
        "movl level+48(%edx), %eax\n"
        "movl %eax, 0x5f0(%ecx)\n"
        "movl level+52(%edx), %eax\n"
        "movl %eax, 0x5f4(%ecx)\n"
        "movl level+56(%edx), %eax\n"
        "movl %eax, 0x5f8(%ecx)\n"
        "movl level+60(%edx), %eax\n"
        "movl %eax, 0x5fc(%ecx)\n"
        "addl $0x1c, %ebx\n"
        "addl $0x1c, %ecx\n"
        "cmpl %ebx, %esi\n" /* line 1284 */
        "jne .Lf1ad0b4_001ad414\n"
        ".Lf1ad0b4_001ad487:\n"
        "addl $1, -0x428(%ebp)\n" /* line 1275 */
        "addl $0x230, -0x424(%ebp)\n"
        "movl -0x428(%ebp), %eax\n"
        "cmpl level+484, %eax\n"
        "jl .Lf1ad0b4_001ad3c9\n"
        ".Lf1ad0b4_001ad4aa:\n"
        "movl level+484, %edi\n" /* line 1306 */
        "testl %edi, %edi\n"
        "jle .Lf1ad0b4_001ad509\n"
        "xorl %esi, %esi\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf1ad0b4_001ad4cb\n"
        ".Lf1ad0b4_001ad4ba:\n"
        "addl $1, %esi\n"
        "addl $0x230, %ebx\n"
        "cmpl level+484, %esi\n"
        "jge .Lf1ad0b4_001ad509\n"
        ".Lf1ad0b4_001ad4cb:\n"
        "movl %ebx, %edx\n" /* line 1308 */
        "addl level+4, %edx\n"
        "cmpb $0, 0xfc(%edx)\n" /* line 1309 */
        "je .Lf1ad0b4_001ad4ba\n"
        "movl $3, 8(%esp)\n" /* line 1312 */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll HudElem_UpdateClient\n"
        "addl $1, %esi\n" /* line 1306 */
        "addl $0x230, %ebx\n"
        "cmpl level+484, %esi\n"
        "jl .Lf1ad0b4_001ad4cb\n"
        ".Lf1ad0b4_001ad509:\n"
        "movl level+484, %esi\n" /* line 1638 | i */
        "testl %esi, %esi\n" /* i */
        "jle .Lf1ad0b4_001ad54f\n"
        "movl $g_entities, %esi\n" /* i */
        "xorl %ebx, %ebx\n" /* trigger_info */
        "jmp .Lf1ad0b4_001ad52d\n"
        ".Lf1ad0b4_001ad51c:\n"
        "addl $1, %ebx\n" /* trigger_info */
        "addl $0x230, %esi\n" /* i */
        "cmpl level+484, %ebx\n" /* trigger_info */
        "jge .Lf1ad0b4_001ad54f\n"
        ".Lf1ad0b4_001ad52d:\n"
        "cmpb $0, 0xfc(%esi)\n" /* line 1640 | i */
        "je .Lf1ad0b4_001ad51c\n"
        "movl %esi, (%esp)\n" /* line 1642 | i */
        "calll ClientEndFrame\n"
        "addl $1, %ebx\n" /* line 1638 | trigger_info */
        "addl $0x230, %esi\n" /* i */
        "cmpl level+484, %ebx\n" /* trigger_info */
        "jl .Lf1ad0b4_001ad52d\n"
        ".Lf1ad0b4_001ad54f:\n"
        "calll CheckTeamStatus\n" /* line 1648 */
        "movl g_oldVoting, %eax\n" /* line 1650 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1ad0b4_001ad6a2\n"
        ".Lf1ad0b4_001ad563:\n"
        "movl level+528, %ebx\n" /* line 995 */
        "testl %ebx, %ebx\n"
        "je .Lf1ad0b4_001ad584\n"
        "movl level+484, %eax\n" /* line 1000 */
        "testl %eax, %eax\n"
        "jg .Lf1ad0b4_001ad65b\n"
        ".Lf1ad0b4_001ad57a:\n"
        "movl $0, level+528\n" /* line 1010 */
        ".Lf1ad0b4_001ad584:\n"
        "movl g_listEntity, %eax\n" /* line 1655 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1ad0b4_001ad6c0\n"
        ".Lf1ad0b4_001ad593:\n"
        "movl level+13820, %ecx\n" /* line 1662 */
        "testl %ecx, %ecx\n"
        "jne .Lf1ad0b4_001ad6b6\n"
        ".Lf1ad0b4_001ad5a1:\n"
        "movl level+13824, %edx\n" /* line 1665 */
        "testl %edx, %edx\n"
        "jne .Lf1ad0b4_001ad6ac\n"
        ".Lf1ad0b4_001ad5af:\n"
        "movl g_dumpAnims, %eax\n" /* line 1356 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf1ad0b4_001ad5ec\n"
        "movl $str_002b4944, (%esp)\n" /* line 1359 */
        "calll Com_Printf\n"
        "movl g_dumpAnims, %eax\n" /* line 1360 */
        "movl 8(%eax), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl level+4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_DObjDisplayAnim\n"
        ".Lf1ad0b4_001ad5ec:\n"
        "movl imp_bgs, %eax\n" /* line 1670 */
        "movl $0, (%eax)\n"
        /* } scope */
        "addl $0x43c, %esp\n" /* line 1673 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ad0b4_001ad602:\n"
        "movl $0, -0x430(%ebp)\n" /* line 1558 | bMoreTriggered */
        "calll Scr_RunCurrentThreads\n" /* line 1585 */
        "movl -0x430(%ebp), %eax\n" /* line 1554 | bMoreTriggered */
        "testl %eax, %eax\n"
        "jne .Lf1ad0b4_001ad1b7\n"
        "jmp .Lf1ad0b4_001ad2bb\n"
        ".Lf1ad0b4_001ad624:\n"
        "movb %al, -0x418(%ebp, %ecx)\n" /* line 1575 */
        "movl %edx, (%esp)\n" /* line 1576 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 1577 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x41c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Scr_Notify\n"
        "jmp .Lf1ad0b4_001ad1de\n"
        ".Lf1ad0b4_001ad65b:\n"
        "xorl %esi, %esi\n" /* line 1000 */
        "xorl %ebx, %ebx\n"
        "movl $g_entities, %edi\n"
        "jmp .Lf1ad0b4_001ad681\n"
        ".Lf1ad0b4_001ad666:\n"
        "addl $1, %esi\n"
        "addl $0x28a4, %ebx\n"
        "addl $0x230, %edi\n"
        "cmpl level+484, %esi\n"
        "jge .Lf1ad0b4_001ad57a\n"
        ".Lf1ad0b4_001ad681:\n"
        "movl %ebx, %eax\n" /* line 1002 */
        "addl level, %eax\n"
        "cmpl $2, 0x26c4(%eax)\n" /* line 1003 */
        "jne .Lf1ad0b4_001ad666\n"
        "cmpl $5, 4(%eax)\n" /* line 1005 */
        "jne .Lf1ad0b4_001ad666\n"
        "movl %edi, (%esp)\n" /* line 1007 */
        "calll DeathmatchScoreboardMessage\n"
        "jmp .Lf1ad0b4_001ad666\n"
        ".Lf1ad0b4_001ad6a2:\n"
        "calll CheckVote\n" /* line 1651 */
        "jmp .Lf1ad0b4_001ad563\n"
        ".Lf1ad0b4_001ad6ac:\n"
        "calll SaveRegisteredItems\n" /* line 1666 */
        "jmp .Lf1ad0b4_001ad5af\n"
        ".Lf1ad0b4_001ad6b6:\n"
        "calll SaveRegisteredWeapons\n" /* line 1663 */
        "jmp .Lf1ad0b4_001ad5a1\n"
        ".Lf1ad0b4_001ad6c0:\n"
        "xorl %ebx, %ebx\n" /* line 1655 | trigger_info */
        "movl $g_entities, %esi\n" /* i */
        ".Lf1ad0b4_001ad6c7:\n"
        "movzwl 0x168(%esi), %eax\n" /* line 1658 | i */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* trigger_info */
        "movl $str_002a8b40, (%esp)\n" /* "%4i: %s\n" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 1657 | trigger_info */
        "addl $0x230, %esi\n" /* i */
        "cmpl $0x400, %ebx\n" /* trigger_info */
        "jne .Lf1ad0b4_001ad6c7\n"
        "movl $0, 4(%esp)\n" /* line 1659 */
        "movl g_listEntity, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "jmp .Lf1ad0b4_001ad593\n"
    );
}
#else
int G_RunFrame(int levelTime) { return 0; }
#endif
