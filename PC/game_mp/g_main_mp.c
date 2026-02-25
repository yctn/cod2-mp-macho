/* ASM dump from: g_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_main_mp.cpp */

#include "common_types.h"
#include "imports.h"

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
static gclient_t g_clients[64]; /* 0xf3ca00 */

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
int G_LogPrintf(const char *fmt);
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
static int G_RunFrameForEntity(void);
int G_RunFrame(int levelTime);

/* line 510 */
__attribute__((naked))
int G_GetSavePersist(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 510 */
        "movl %esp, %ebp\n"
        "movl 0x19361d4, %eax\n"
        "popl %ebp\n" /* line 513 */
        "retl\n"
    );
}

/* line 521 */
__attribute__((naked))
int G_SetSavePersist(qboolean savepersist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 521 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 523 | savepersist */
        "movl %eax, 0x19361d4\n"
        "popl %ebp\n" /* line 524 */
        "retl\n"
    );
}

/* line 532 */
__attribute__((naked))
float G_GetFogOpaqueDistSqrd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 532 */
        "movl %esp, %ebp\n"
        "flds 0x193625c\n"
        "popl %ebp\n" /* line 535 */
        "retl\n"
    );
}

/* line 544 */
__attribute__((naked))
int G_GetClientScore(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 544 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* clientNum */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl level, %edx\n" /* clientNum */
        "movl 0x26b8(%edx, %eax, 4), %eax\n"
        "popl %ebp\n" /* line 547 */
        "retl\n"
    );
}

/* line 556 */
__attribute__((naked))
int G_GetClientArchiveTime(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 556 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* clientNum */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl level, %edx\n" /* clientNum */
        "movl 0x26b4(%edx, %eax, 4), %eax\n"
        "popl %ebp\n" /* line 559 */
        "retl\n"
    );
}

/* line 568 */
__attribute__((naked))
int G_SetClientArchiveTime(int clientNum, int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 568 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* clientNum, time */
        "leal (%edx, %edx, 4), %eax\n" /* line 570 */
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl level, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* time */
        "movl %edx, 0x26b4(%ecx, %eax, 4)\n"
        "popl %ebp\n" /* line 571 */
        "retl\n"
    );
}

/* line 580 */
__attribute__((naked))
clientState_t * G_GetClientState(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 580 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* clientNum */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl level, %edx\n" /* clientNum */
        "leal 0x2748(%edx, %eax, 4), %eax\n"
        "popl %ebp\n" /* line 583 */
        "retl\n"
    );
}

/* line 684 */
static __attribute__((naked))
int G_CreateDObj(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle, clientInfo_t *ci)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 684 */
        "movl %esp, %ebp\n"
        "movzwl 0xc(%ebp), %eax\n" /* numModels */
        "movl %eax, 0xc(%ebp)\n" /* line 686 | numModels */
        "popl %ebp\n" /* line 687 */
        "jmp Com_ServerDObjCreate\n" /* line 686 */
    );
}

/* line 751 */
__attribute__((naked))
int * Hunk_AllocXAnimServer(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 751 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 754 */
        "jmp Hunk_AllocLowInternal\n" /* line 753 */
    );
}

/* line 1021 */
static __attribute__((naked))
int SortRanks(const int *a, const int *b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1021 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl level, %ebx\n" /* line 1025 */
        "movl 8(%ebp), %eax\n" /* a */
        "movl (%eax), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %esi\n" /* ca */
        "movl 0xc(%ebp), %eax\n" /* line 1026 | b */
        "movl (%eax), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %edx\n"
        "cmpl $1, 0x26c4(%esi)\n" /* line 1029 | ca */
        "jne .Lf1ab8ca_001ab911\n"
        ".Lf1ab8ca_001ab908:\n"
        "movl $1, %eax\n" /* line 1057 */
        /* } scope */
        ".Lf1ab8ca_001ab90d:\n"
        "popl %ebx\n" /* line 1061 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ab8ca_001ab911:\n"
        "cmpl $1, 0x26c4(%edx)\n" /* line 1031 */
        "je .Lf1ab8ca_001ab92c\n"
        "cmpl $3, 0x274c(%esi)\n" /* line 1035 | ca */
        "je .Lf1ab8ca_001ab95b\n"
        "cmpl $3, 0x274c(%edx)\n" /* line 1045 */
        "jne .Lf1ab8ca_001ab935\n"
        ".Lf1ab8ca_001ab92c:\n"
        "movl $0xffffffff, %eax\n" /* line 1055 */
        /* } scope */
        "popl %ebx\n" /* line 1061 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ab8ca_001ab935:\n"
        "movl 0x26b8(%edx), %eax\n" /* line 1049 */
        "cmpl %eax, 0x26b8(%esi)\n" /* ca */
        "jg .Lf1ab8ca_001ab92c\n"
        "jl .Lf1ab8ca_001ab908\n" /* line 1051 */
        "movl 0x26bc(%edx), %eax\n" /* line 1055 */
        "cmpl %eax, 0x26bc(%esi)\n" /* ca */
        "jl .Lf1ab8ca_001ab92c\n"
        "jg .Lf1ab8ca_001ab908\n" /* line 1057 */
        ".Lf1ab8ca_001ab955:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 1061 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ab8ca_001ab95b:\n"
        "cmpl $3, 0x274c(%edx)\n" /* line 1035 */
        "jne .Lf1ab8ca_001ab908\n"
        "cmpl %edx, %esi\n" /* line 1037 | ca */
        "jb .Lf1ab8ca_001ab92c\n"
        "jbe .Lf1ab8ca_001ab955\n" /* line 1039 */
        "movl $1, %eax\n" /* line 1057 */
        "jmp .Lf1ab8ca_001ab90d\n"
    );
}

/* line 1073 */
__attribute__((naked))
int CalculateRanks(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1073 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "xorl %ecx, %ecx\n" /* line 1077 */
        "movl $0, 0x1934698\n"
        "movl $0, 0x1934fac\n" /* line 1078 */
        "movl 0x1934664, %eax\n" /* line 1080 */
        "testl %eax, %eax\n"
        "jle .Lf1ab972_001aba0c\n"
        "xorl %edx, %edx\n"
        "movl $0x1934690, %ebx\n"
        "movl level, %eax\n"
        ".Lf1ab972_001ab9a4:\n"
        "cmpl $0, 0x26c4(%eax)\n" /* line 1082 */
        "je .Lf1ab972_001ab9cc\n"
        "movl %edx, 0xc(%ebx, %ecx, 4)\n" /* line 1085 */
        "addl $1, %ecx\n" /* line 1086 */
        "movl %ecx, 0x1934698\n"
        "cmpl $3, 0x274c(%eax)\n" /* line 1088 */
        "je .Lf1ab972_001ab9cc\n"
        "cmpl $2, 0x26c4(%eax)\n" /* line 1090 */
        "je .Lf1ab972_001aba14\n"
        ".Lf1ab972_001ab9cc:\n"
        "addl $1, %edx\n" /* line 1080 */
        "addl $0x28a4, %eax\n"
        "cmpl 0x1934664, %edx\n"
        "jl .Lf1ab972_001ab9a4\n"
        ".Lf1ab972_001ab9dc:\n"
        "movl $SortRanks, 0xc(%esp)\n" /* line 1095 */
        "movl $4, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x193469c, (%esp)\n"
        "calll qsort\n"
        "movl $1, 0x1934690\n" /* line 1097 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1098 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1ab972_001aba0c:\n"
        "movl 0x1934698, %ecx\n"
        "jmp .Lf1ab972_001ab9dc\n"
        /* { scope 1 */
        ".Lf1ab972_001aba14:\n"
        "addl $1, 0x1934fac\n" /* line 1091 */
        "jmp .Lf1ab972_001ab9cc\n"
    );
}

/* line 1159 */
__attribute__((naked))
int G_LogPrintf(const char *fmt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1159 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x83c, %esp\n"
        /* { scope 1 */
        "movl 0x1934498, %edx\n" /* line 1167 */
        "testl %edx, %edx\n"
        "je .Lf1aba1e_001abb0e\n"
        "leal 0xc(%ebp), %eax\n" /* line 1172 */
        "movl %eax, -0x1c(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 1173 */
        "movl 8(%ebp), %eax\n" /* fmt */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x81c(%ebp), %ebx\n" /* string2 */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movl 0x193466c, %ecx\n" /* line 1176 */
        "movl $0x10624dd3, %esi\n" /* sec */
        "movl %ecx, %eax\n"
        "imull %esi\n" /* sec */
        "movl %edx, %esi\n" /* sec */
        "sarl $6, %esi\n" /* sec */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %esi\n" /* sec */
        "movl $0x88888889, %ecx\n" /* line 1178 */
        "movl %ecx, %eax\n"
        "imull %esi\n" /* sec */
        "leal (%edx, %esi), %edi\n" /* min */
        "sarl $5, %edi\n" /* min */
        "movl %esi, %eax\n" /* sec */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edi\n" /* min */
        "leal (, %edi, 4), %ecx\n" /* line 1179 */
        "movl %edi, %eax\n" /* min */
        "shll $6, %eax\n"
        "subl %ecx, %eax\n"
        "subl %eax, %esi\n" /* sec */
        "movl $0x66666667, %eax\n" /* line 1180 */
        "imull %esi\n" /* sec */
        "movl %edx, %ecx\n"
        "sarl $2, %ecx\n"
        "movl %esi, %eax\n" /* sec */
        "sarl $0x1f, %eax\n"
        "subl %eax, %ecx\n"
        "movl %ebx, 0x18(%esp)\n" /* line 1183 */
        "leal (%ecx, %ecx, 4), %eax\n"
        "addl %eax, %eax\n"
        "subl %eax, %esi\n" /* sec */
        "movl %esi, 0x14(%esp)\n" /* sec */
        "movl %ecx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* min */
        "movl $0x2b446c, 8(%esp)\n" /* "%3i:%i%i %s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x41c(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x1934498, %eax\n" /* line 1184 */
        "movl %eax, 8(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* min */
        "repne scasb %es:(%edi), %al\n" /* min */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_Write\n"
        /* } scope */
        ".Lf1aba1e_001abb0e:\n"
        "addl $0x83c, %esp\n" /* line 1186 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1118 */
__attribute__((naked))
int ExitLevel(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1118 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $0x2b4478, 4(%esp)\n" /* line 1123 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl $0, 0x1934680\n" /* line 1126 */
        "movl $0, 0x1934684\n" /* line 1127 */
        "movl g_maxclients, %ebx\n" /* line 1128 */
        "movl 8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1abb1a_001abbe7\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "jmp .Lf1abb1a_001abb6e\n"
        ".Lf1abb1a_001abb60:\n"
        "addl $1, %ecx\n"
        "addl $0x28a4, %edx\n"
        "cmpl 8(%ebx), %ecx\n"
        "jge .Lf1abb1a_001abb9d\n"
        ".Lf1abb1a_001abb6e:\n"
        "movl %edx, %eax\n" /* line 1130 */
        "addl level, %eax\n"
        "cmpl $2, 0x26c4(%eax)\n" /* line 1131 */
        "jne .Lf1abb1a_001abb60\n"
        "movl $0, 0x26b8(%eax)\n" /* line 1135 */
        "movl g_maxclients, %ebx\n"
        "addl $1, %ecx\n" /* line 1128 */
        "addl $0x28a4, %edx\n"
        "cmpl 8(%ebx), %ecx\n"
        "jl .Lf1abb1a_001abb6e\n"
        ".Lf1abb1a_001abb9d:\n"
        "movl 8(%ebx), %ecx\n" /* line 1140 */
        "testl %ecx, %ecx\n"
        "jle .Lf1abb1a_001abbe7\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "jmp .Lf1abb1a_001abbb8\n"
        ".Lf1abb1a_001abbaa:\n"
        "addl $1, %ecx\n"
        "addl $0x28a4, %edx\n"
        "cmpl 8(%ebx), %ecx\n"
        "jge .Lf1abb1a_001abbe7\n"
        ".Lf1abb1a_001abbb8:\n"
        "movl %edx, %eax\n" /* line 1142 */
        "addl level, %eax\n"
        "cmpl $2, 0x26c4(%eax)\n"
        "jne .Lf1abb1a_001abbaa\n"
        "movl $1, 0x26c4(%eax)\n" /* line 1144 */
        "movl g_maxclients, %ebx\n"
        "addl $1, %ecx\n" /* line 1140 */
        "addl $0x28a4, %edx\n"
        "cmpl 8(%ebx), %ecx\n"
        "jl .Lf1abb1a_001abbb8\n"
        ".Lf1abb1a_001abbe7:\n"
        "movl $0x2b4484, (%esp)\n" /* line 1148 */
        "calll G_LogPrintf\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1149 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 763 */
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
        "movl $0x2b449c, (%esp)\n" /* line 770 */
        "calll Com_Printf\n"
        "movl $0x2b44c4, 4(%esp)\n" /* line 771 */
        "movl $0x2b44d4, (%esp)\n" /* "gamename: %s
" */
        "calll Com_Printf\n"
        "movl $0x2b44e4, 4(%esp)\n" /* line 772 */
        "movl $0x2b44f0, (%esp)\n" /* "gamedate: %s
" */
        "calll Com_Printf\n"
        "calll Swap_Init\n" /* line 774 */
        "movl $0x3624, 8(%esp)\n" /* line 776 */
        "movl $0, 4(%esp)\n"
        "movl $level, (%esp)\n"
        "calll memset\n"
        "movl $1, 0x193449c\n" /* line 778 */
        "movl %ebx, 0x193466c\n" /* line 779 | i */
        "movl %ebx, 0x1934678\n" /* line 780 | i */
        "movl $0xffffffff, 0x1937a84\n" /* line 781 */
        "movl %esi, (%esp)\n" /* line 783 | randomSeed */
        "calll srand\n"
        "movl %esi, (%esp)\n" /* line 784 | randomSeed */
        "calll Rand_Init\n"
        "calll G_SetupWeaponDef\n" /* line 786 */
        "movl 0x10(%ebp), %edx\n" /* line 788 | restart */
        "testl %edx, %edx\n"
        "je .Lf1abbfa_001abf7c\n"
        "movl 0x14(%ebp), %eax\n" /* savepersist */
        "testl %eax, %eax\n"
        "je .Lf1abbfa_001abf7c\n"
        ".Lf1abbfa_001abcac:\n"
        "calll G_ProcessIPBans\n" /* line 791 */
        "movl 0x195f718, %eax\n" /* line 793 */
        "movl %eax, 0x192166c\n"
        "movl $G_CreateDObj, 0x1921670\n" /* line 794 */
        "movl 0x195f710, %eax\n" /* line 795 */
        "movl %eax, 0x1921674\n"
        "movl $Hunk_AllocXAnimServer, 0x1921678\n" /* line 796 */
        "movl $1, 0x1921668\n" /* line 797 */
        "movl g_log, %eax\n" /* line 799 */
        "movl 8(%eax), %edx\n"
        "cmpb $0, (%edx)\n"
        "je .Lf1abbfa_001ac918\n"
        "movl g_logSync, %eax\n" /* line 801 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1abbfa_001ac810\n"
        "movl $3, 8(%esp)\n" /* line 802 */
        "movl $0x1934498, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl 0x1934498, %eax\n" /* line 806 */
        "testl %eax, %eax\n"
        "jne .Lf1abbfa_001ac835\n"
        ".Lf1abbfa_001abd28:\n"
        "movl g_log, %eax\n" /* line 807 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b4874, (%esp)\n" /* "WARNING: Couldn't open logfile: %s
" */
        "calll Com_Printf\n"
        ".Lf1abbfa_001abd40:\n"
        "movl $0xffffffff, 0x1937a88\n" /* line 826 */
        "movl $0, 0x1937a8c\n" /* line 827 */
        "movl $0, 0x1937a90\n" /* line 828 */
        "movl $0, 0x1937a94\n"
        "movl $0, 0x1937a98\n"
        "movl $0, 0x1937a9c\n"
        "movl $0, 0x1937aa0\n"
        "movl $Hunk_AllocXAnimServer, (%esp)\n" /* line 831 */
        "calll Mantle_CreateAnims\n"
        "movl 0x195edb4, %ebx\n" /* line 834 | i */
        "movl $level_bgs, (%ebx)\n" /* i */
        "movl 0x10(%ebp), %eax\n" /* line 836 | restart */
        "testl %eax, %eax\n"
        "je .Lf1abbfa_001ac877\n"
        ".Lf1abbfa_001abda9:\n"
        "calll GScr_LoadConsts\n" /* line 848 */
        "movl $0x400, 8(%esp)\n" /* line 851 */
        "leal -0x418(%ebp), %ebx\n" /* cs, i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $0x16, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl $0x21952c, 8(%esp)\n" /* line 852 */
        "movl $0x2b1cfc, 4(%esp)\n" /* "winner" */
        "movl %ebx, (%esp)\n" /* i */
        "calll Info_SetValueForKey\n"
        "movl %ebx, 4(%esp)\n" /* line 853 | i */
        "movl $0x16, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl $0x8c000, 8(%esp)\n" /* line 856 */
        "movl $0, 4(%esp)\n"
        "movl $g_entities, (%esp)\n"
        "calll memset\n"
        "movl $g_entities, 0x1934484\n" /* line 857 */
        "movl g_maxclients, %eax\n" /* line 860 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x1934664\n"
        "movl $0xa2900, 8(%esp)\n" /* line 861 */
        "movl $0, 4(%esp)\n"
        "movl $g_clients, (%esp)\n"
        "calll memset\n"
        "movl $g_clients, %esi\n" /* line 862 | randomSeed */
        "movl $0xf3ca00, level\n"
        "movl 0x1934664, %eax\n" /* line 865 */
        "testl %eax, %eax\n"
        "jle .Lf1abbfa_001ac86c\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %ecx, %ecx\n"
        "movl $g_entities, %edx\n"
        ".Lf1abbfa_001abe68:\n"
        "leal g_clients(%ecx), %eax\n" /* line 866 */
        "movl %eax, 0x158(%edx)\n"
        "addl $1, %ebx\n" /* line 865 | i */
        "addl $0x28a4, %ecx\n"
        "addl $0x230, %edx\n"
        "cmpl 0x1934664, %ebx\n" /* i */
        "jl .Lf1abbfa_001abe68\n"
        ".Lf1abbfa_001abe8b:\n"
        "movl $0x48, 0x193448c\n" /* line 871 */
        "movl $0, 0x1934490\n" /* line 872 */
        "movl $0, 0x1934494\n" /* line 873 */
        "movl $0x28a4, 0x10(%esp)\n" /* line 876 */
        "movl %esi, 0xc(%esp)\n" /* randomSeed */
        "movl $0x230, 8(%esp)\n"
        "movl $0x48, 4(%esp)\n"
        "movl 0x1934484, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_LocateGameData\n"
        "calll G_ParseHitLocDmgTable\n" /* line 879 */
        "calll G_InitTurrets\n" /* line 881 */
        "calll G_SpawnEntitiesFromString\n" /* line 884 */
        "movl $0x21952c, (%esp)\n" /* line 886 */
        "calll G_setfog\n"
        "calll G_InitObjectives\n" /* line 889 */
        "calll Scr_FreeEntityList\n" /* line 891 */
        "movl $0x2a74f8, (%esp)\n" /* line 893 */
        "calll Com_Printf\n"
        "movl $1, (%esp)\n" /* line 896 */
        "calll Scr_InitSystem\n"
        "movl $1, (%esp)\n" /* line 897 */
        "calll Scr_SetLoading\n"
        "calll Scr_AllocGameVariable\n" /* line 898 */
        "calll G_LoadStructs\n" /* line 899 */
        "calll Scr_LoadGameType\n" /* line 900 */
        "calll Scr_LoadLevel\n" /* line 901 */
        "calll Scr_StartupGameType\n" /* line 902 */
        "movl 0x195f6d0, %eax\n"
        "leal 0x2640(%eax), %edx\n"
        ".Lf1abbfa_001abf3f:\n"
        "movl $0xffffffff, 0x10bc(%eax)\n" /* line 906 */
        "addl $0x4c8, %eax\n"
        "cmpl %edx, %eax\n" /* line 905 */
        "jne .Lf1abbfa_001abf3f\n"
        "movl 0x195edb4, %eax\n" /* line 909 */
        "movl $0, (%eax)\n"
        "movl $0, 0x193449c\n" /* line 911 */
        "calll SaveRegisteredWeapons\n" /* line 913 */
        "calll SaveRegisteredItems\n" /* line 914 */
        /* } scope */
        "addl $0x82c, %esp\n" /* line 915 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: serverinfo */
        ".Lf1abbfa_001abf7c:\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 96 */
        "movl $0, 4(%esp)\n"
        "movl $0x2198ac, (%esp)\n" /* "sv_cheats" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_cheats\n"
        "movl $0x1044, 8(%esp)\n" /* line 99 */
        "movl $0x2b44c4, 4(%esp)\n" /* "Call of Duty 2" */
        "movl $0x2a9b10, (%esp)\n" /* "gamename" */
        "calll Dvar_RegisterString\n"
        "movl $0x1040, 8(%esp)\n" /* line 100 */
        "movl $0x2b44e4, 4(%esp)\n" /* "Apr 13 2006" */
        "movl $0x2b4500, (%esp)\n" /* "gamedate" */
        "calll Dvar_RegisterString\n"
        "movl $0x1044, 8(%esp)\n" /* line 101 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2b450c, (%esp)\n" /* "sv_mapname" */
        "calll Dvar_RegisterString\n"
        "movl $0x1024, 8(%esp)\n" /* line 104 */
        "movl $0x2a70fc, 4(%esp)\n" /* "dm" */
        "movl $0x2a7100, (%esp)\n" /* "g_gametype" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_gametype\n"
        "movl $0x1025, 0x10(%esp)\n" /* line 109 */
        "movl $0x40, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x14, 4(%esp)\n"
        "movl $0x2a70dc, (%esp)\n" /* "sv_maxclients" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_maxclients\n"
        "movl $0x1008, 8(%esp)\n" /* line 113 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a8454, (%esp)\n" /* "g_synchronousClients" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_synchronousClients\n"
        "movl $0x1001, 8(%esp)\n" /* line 115 */
        "movl $0x2b4518, 4(%esp)\n" /* "games_mp.log" */
        "movl $0x2b4528, (%esp)\n" /* "g_log" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_log\n"
        "movl $0x1001, 8(%esp)\n" /* line 116 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b4530, (%esp)\n" /* "g_logSync" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_logSync\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 118 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2ab490, (%esp)\n" /* "g_password" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_password\n"
        "movl $0x1001, 8(%esp)\n" /* line 119 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2b453c, (%esp)\n" /* "g_banIPs" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_banIPs\n"
        "movl $0x1020, 0x10(%esp)\n" /* line 121 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_dedicated\n"
        "movl 8(%eax), %eax\n" /* line 122 */
        "testl %eax, %eax\n"
        "jne .Lf1abbfa_001ac929\n"
        ".Lf1abbfa_001ac124:\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 125 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0xbe, 4(%esp)\n"
        "movl $0x2b4548, (%esp)\n" /* "g_speed" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_speed\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 126 */
        "movl $0x7f7fffff, %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x44480000, 4(%esp)\n"
        "movl $0x2b4550, (%esp)\n" /* "g_gravity" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_gravity\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 127 */
        "movl %ebx, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl $0x447a0000, %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2b455c, (%esp)\n" /* "g_knockback" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_knockback\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 128 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b4568, (%esp)\n" /* "g_weaponAmmoPools" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_weaponAmmoPools\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 129 */
        "movl $0x20, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl $0x2b457c, (%esp)\n" /* "g_maxDroppedWeapons" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_maxDroppedWeapons\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 130 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2b4590, (%esp)\n" /* "g_inactivity" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_inactivity\n"
        "movl $0x1080, 8(%esp)\n" /* line 131 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b45a0, (%esp)\n" /* "g_debugDamage" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_debugDamage\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 132 */
        "movl $6, 0xc(%esp)\n"
        "movl $0xfffffffd, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2b45b0, (%esp)\n" /* "g_debugBullets" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_debugBullets\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 133 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2b45c0, (%esp)\n" /* "g_motd" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_motd\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 135 */
        "movl $0x7d00, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x19, 4(%esp)\n"
        "movl $0x2b45c8, (%esp)\n" /* "g_playerCollisionEjectSpeed" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_playerCollisionEjectSpeed\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 136 */
        "movl %edi, 0xc(%esp)\n"
        "xorl %esi, %esi\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x41200000, 4(%esp)\n"
        "movl $0x2b45e4, (%esp)\n" /* "g_dropForwardSpeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_dropForwardSpeed\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 137 */
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x41200000, 4(%esp)\n"
        "movl $0x2b45f8, (%esp)\n" /* "g_dropUpSpeedBase" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_dropUpSpeedBase\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 138 */
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $0x2b460c, (%esp)\n" /* "g_dropUpSpeedRand" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_dropUpSpeedRand\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 140 */
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x42a00000, 4(%esp)\n"
        "movl $0x2b4620, (%esp)\n" /* "g_clonePlayerMaxVelocity" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_clonePlayerMaxVelocity\n"
        "movl $0x1001, 8(%esp)\n" /* line 143 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b463c, (%esp)\n" /* "voice_global" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, voice_global\n"
        "movl $0x1001, 8(%esp)\n" /* line 144 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b464c, (%esp)\n" /* "voice_localEcho" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, voice_localEcho\n"
        "movl $0x1001, 8(%esp)\n" /* line 145 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b465c, (%esp)\n" /* "voice_deadChat" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, voice_deadChat\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 148 */
        "movl $1, 4(%esp)\n"
        "movl $0x2b466c, (%esp)\n" /* "g_allowVote" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_allowVote\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 149 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b4678, (%esp)\n" /* "g_listEntity" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_listEntity\n"
        "movl $0x1001, 8(%esp)\n" /* line 151 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b4688, (%esp)\n" /* "g_deadChat" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_deadChat\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 152 */
        "movl $0x2710, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1f4, 4(%esp)\n"
        "movl $0x2b4694, (%esp)\n" /* "g_voiceChatTalkingDuration" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_voiceChatTalkingDuration\n"
        "movl $0x1100, 8(%esp)\n" /* line 154 */
        "movl $0x2b46b0, 4(%esp)\n" /* "mpflag_american" */
        "movl $0x2b46c0, (%esp)\n" /* "g_ScoresBanner_Allies" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_ScoresBanner_Allies\n"
        "movl $0x1100, 8(%esp)\n" /* line 155 */
        "movl $0x2b46d8, 4(%esp)\n" /* "mpflag_german" */
        "movl $0x2b46e8, (%esp)\n" /* "g_ScoresBanner_Axis" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_ScoresBanner_Axis\n"
        "movl $0x1100, 8(%esp)\n" /* line 156 */
        "movl $0x2b46fc, 4(%esp)\n" /* "mpflag_none" */
        "movl $0x2b4708, (%esp)\n" /* "g_ScoresBanner_None" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_ScoresBanner_None\n"
        "movl $0x1100, 8(%esp)\n" /* line 157 */
        "movl $0x2b471c, 4(%esp)\n" /* "mpflag_spectator" */
        "movl $0x2b4730, (%esp)\n" /* "g_ScoresBanner_Spectators" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_ScoresBanner_Spectators\n"
        "movl $0x1100, 8(%esp)\n" /* line 158 */
        "movl $0x2b3b64, 4(%esp)\n" /* "GAME_ALLIES" */
        "movl $0x2b474c, (%esp)\n" /* "g_TeamName_Allies" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_TeamName_Allies\n"
        "movl $0x1100, 8(%esp)\n" /* line 159 */
        "movl $0x2b3b58, 4(%esp)\n" /* "GAME_AXIS" */
        "movl $0x2b4760, (%esp)\n" /* "g_TeamName_Axis" */
        "calll Dvar_RegisterString\n"
        "movl %eax, g_TeamName_Axis\n"
        "movl $0x1100, 0x14(%esp)\n" /* line 160 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0x3f000000, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2addc0, (%esp)\n" /* "g_TeamColor_Allies" */
        "calll Dvar_RegisterColor\n"
        "movl %eax, g_TeamColor_Allies\n"
        "movl $0x1100, 0x14(%esp)\n" /* line 161 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x2addd4, (%esp)\n" /* "g_TeamColor_Axis" */
        "calll Dvar_RegisterColor\n"
        "movl %eax, g_TeamColor_Axis\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 163 */
        "movl $1, 4(%esp)\n"
        "movl $0x2b4770, (%esp)\n" /* "g_smoothClients" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_smoothClients\n"
        "movl $0x1005, 8(%esp)\n" /* line 164 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a9d28, (%esp)\n" /* "g_antilag" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_antilag\n"
        "movl $0x1001, 8(%esp)\n" /* line 165 */
        "movl $1, 4(%esp)\n"
        "movl $0x2b4780, (%esp)\n" /* "g_oldVoting" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_oldVoting\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 166 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2b478c, (%esp)\n" /* "g_voteAbstainWeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_voteAbstainWeight\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 168 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b47a0, (%esp)\n" /* "g_no_script_spam" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_NoScriptSpam\n"
        "movl $0x1080, 8(%esp)\n" /* line 170 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b47b4, (%esp)\n" /* "g_debugLocDamage" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, g_debugLocDamage\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 172 */
        "movl $0x466a6000, %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x43800000, 4(%esp)\n"
        "movl $0x2b47c8, (%esp)\n" /* "g_friendlyfireDist" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_friendlyfireDist\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 173 */
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2b47dc, (%esp)\n" /* "g_friendlyNameDist" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, g_friendlyNameDist\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 175 */
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x42800000, 4(%esp)\n"
        "movl $0x2b47f0, (%esp)\n" /* "player_meleeRange" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_meleeRange\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 176 */
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x41200000, 4(%esp)\n"
        "movl $0x2b4804, (%esp)\n" /* "player_meleeWidth" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_meleeWidth\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 177 */
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x41200000, 4(%esp)\n"
        "movl $0x2b4818, (%esp)\n" /* "player_meleeHeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_meleeHeight\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 179 */
        "movl $0x3ff, 0xc(%esp)\n"
        "movl $0xffffffff, 8(%esp)\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl $0x2b482c, (%esp)\n" /* "g_dumpAnims" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_dumpAnims\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 183 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2b4838, (%esp)\n" /* "g_useholdtime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_useholdtime\n"
        "movl $0x1081, 0x10(%esp)\n" /* line 185 */
        "movl $0xa, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0x2b4848, (%esp)\n" /* "g_useholdspawndelay" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_useholdspawndelay\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 188 */
        "movl $0xea60, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1f4, 4(%esp)\n"
        "movl $0x2b485c, (%esp)\n" /* "g_mantleBlockTimeBuffer" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, g_mantleBlockTimeBuffer\n"
        "calll BG_RegisterDvars\n" /* line 195 */
        "jmp .Lf1abbfa_001abcac\n"
        ".Lf1abbfa_001ac810:\n"
        "movl $2, 8(%esp)\n" /* line 804 */
        "movl $0x1934498, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl 0x1934498, %eax\n" /* line 806 */
        "testl %eax, %eax\n"
        "je .Lf1abbfa_001abd28\n"
        /* { scope 2 */
        ".Lf1abbfa_001ac835:\n"
        "movl $0x400, 4(%esp)\n" /* line 812 */
        "leal -0x818(%ebp), %ebx\n" /* serverinfo, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll SV_GetServerinfo\n"
        "movl $0x2b4898, (%esp)\n" /* line 814 */
        "calll G_LogPrintf\n"
        "movl %ebx, 4(%esp)\n" /* line 815 | i */
        "movl $0x2b48d8, (%esp)\n" /* "InitGame: %s
" */
        "calll G_LogPrintf\n"
        "jmp .Lf1abbfa_001abd40\n"
        ".Lf1abbfa_001ac86c:\n"
        "movl level, %esi\n" /* randomSeed */
        "jmp .Lf1abbfa_001abe8b\n"
        /* } scope */
        ".Lf1abbfa_001ac877:\n"
        "movl $0xb3bc8, 8(%esp)\n" /* line 838 */
        "movl $0, 4(%esp)\n"
        "movl $level_bgs, (%esp)\n"
        "calll memset\n"
        "movl (%ebx), %edx\n" /* line 840 | i */
        "movl 0x195f304, %eax\n"
        "movl %eax, 0xb3bc0(%edx)\n"
        "movl (%ebx), %edx\n" /* line 841 | i */
        "movl 0x195f714, %eax\n"
        "movl %eax, 0xb3bc4(%edx)\n"
        "calll GScr_LoadScripts\n" /* line 843 */
        "calll BG_LoadAnim\n" /* line 844 */
        "movl 0x1921648, %edi\n" /* line 701 */
        "movl $level_bgs, %ebx\n"
        "movl $0x1880880, %esi\n"
        ".Lf1abbfa_001ac8c7:\n"
        "movl $Hunk_AllocXAnimServer, 4(%esp)\n" /* line 704 */
        "movl %edi, (%esp)\n"
        "calll XAnimCreateTree\n"
        "movl %eax, 0xb40a0(%ebx)\n"
        "addl $0x4b8, %ebx\n"
        "cmpl %ebx, %esi\n" /* line 703 */
        "jne .Lf1abbfa_001ac8c7\n"
        "movl 0x195f6d0, %ebx\n"
        "leal 0x2640(%ebx), %esi\n"
        ".Lf1abbfa_001ac8f3:\n"
        "movl $Hunk_AllocXAnimServer, 4(%esp)\n" /* line 708 */
        "movl %edi, (%esp)\n"
        "calll XAnimCreateTree\n"
        "movl %eax, 0x10b8(%ebx)\n"
        "addl $0x4c8, %ebx\n"
        "cmpl %ebx, %esi\n" /* line 707 */
        "jne .Lf1abbfa_001ac8f3\n"
        "jmp .Lf1abbfa_001abda9\n"
        ".Lf1abbfa_001ac918:\n"
        "movl $0x2b48e8, (%esp)\n" /* line 820 */
        "calll Com_Printf\n"
        "jmp .Lf1abbfa_001abd40\n"
        ".Lf1abbfa_001ac929:\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 123 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_RegisterInt\n"
        "jmp .Lf1abbfa_001ac124\n"
    );
}

/* line 1202 */
__attribute__((naked))
int CheckVote(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1202 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "movl 0x1934fa0, %eax\n" /* line 1209 */
        "testl %eax, %eax\n"
        "je .Lf1ac95a_001ac976\n"
        "cmpl 0x193466c, %eax\n"
        "jl .Lf1ac95a_001aca91\n"
        ".Lf1ac95a_001ac976:\n"
        "movl 0x1934f9c, %eax\n" /* line 1214 */
        "testl %eax, %eax\n"
        "je .Lf1ac95a_001aca25\n"
        "cmpl %eax, 0x193466c\n" /* line 1218 */
        "js .Lf1ac95a_001aca2b\n"
        "movl 0x1934fa4, %ebx\n" /* line 1220 */
        "movl 0x1934fa8, %edx\n"
        "cvtsi2sdl %edx, %xmm0\n" /* line 1224 */
        "movsd %xmm0, -0x10(%ebp)\n"
        "leal (%ebx, %edx), %edx\n" /* line 1222 */
        "movl 0x1934fac, %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movl g_voteAbstainWeight, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fstps -0x14(%ebp)\n"
        "cvtss2sd -0x14(%ebp), %xmm0\n"
        "addsd -0x10(%ebp), %xmm0\n"
        "cvttsd2si %xmm0, %eax\n"
        "cmpl %eax, %ebx\n"
        "jg .Lf1ac95a_001aca51\n"
        ".Lf1ac95a_001ac9db:\n"
        "movl $0x65, 4(%esp)\n" /* line 1248 */
        "movl $0x2b4918, (%esp)\n" /* "%c "GAME_VOTEFAILED"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        ".Lf1ac95a_001aca07:\n"
        "movl $0, 0x1934f9c\n" /* line 1256 */
        "movl $0x2157b8, 4(%esp)\n" /* line 1257 */
        "movl $0xf, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        ".Lf1ac95a_001aca25:\n"
        "addl $0x24, %esp\n" /* line 1258 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ac95a_001aca2b:\n"
        "movl 0x1934fac, %edx\n" /* line 1238 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "addl $1, %eax\n"
        "cmpl 0x1934fa4, %eax\n" /* line 1239 */
        "jle .Lf1ac95a_001aca51\n"
        "subl %eax, %edx\n" /* line 1245 */
        "cmpl %edx, 0x1934fa8\n"
        "jle .Lf1ac95a_001aca25\n"
        "jmp .Lf1ac95a_001ac9db\n"
        ".Lf1ac95a_001aca51:\n"
        "movl $0x65, 4(%esp)\n" /* line 1242 */
        "movl $0x2b4900, (%esp)\n" /* "%c "GAME_VOTEPASSED"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl 0x193466c, %eax\n" /* line 1243 */
        "addl $0xbb8, %eax\n"
        "movl %eax, 0x1934fa0\n"
        "jmp .Lf1ac95a_001aca07\n"
        ".Lf1ac95a_001aca91:\n"
        "movl $0, 0x1934fa0\n" /* line 1211 */
        "movl $0x193479c, 4(%esp)\n" /* line 1212 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf1ac95a_001ac976\n"
    );
}

/* line 1324 */
__attribute__((naked))
int G_RunThink(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1324 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1 */
        "movl 0x190(%ebx), %eax\n" /* line 1329 | ent */
        "testl %eax, %eax\n" /* line 1330 */
        "jle .Lf1acac4_001acb0d\n"
        "cmpl 0x193466c, %eax\n" /* line 1334 */
        "jg .Lf1acac4_001acb0d\n"
        "movl $0, 0x190(%ebx)\n" /* line 1339 | ent */
        "movzbl 0x166(%ebx), %eax\n" /* line 1340 | ent */
        "leal (%eax, %eax, 4), %eax\n"
        "movl entityHandlers(, %eax, 8), %esi\n" /* think */
        "testl %esi, %esi\n" /* line 1341 | think */
        "je .Lf1acac4_001acb14\n"
        ".Lf1acac4_001acb00:\n"
        "movl %ebx, 8(%ebp)\n" /* line 1345 | ent */
        "movl %esi, %ecx\n" /* think */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1346 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 1345 */
        /* } scope */
        ".Lf1acac4_001acb0d:\n"
        "addl $0x10, %esp\n" /* line 1346 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1acac4_001acb14:\n"
        "movl $0x2b4930, 4(%esp)\n" /* line 1343 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1acac4_001acb00\n"
    );
}

/* line 1682 */
__attribute__((naked))
int G_TraceCapsule(trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1682 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl $0, 0x24(%esp)\n" /* line 1684 */
        "movl $0, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* contentmask */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* end */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* maxs */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* mins */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* results */
        "movl %eax, (%esp)\n"
        "calll SV_Trace\n"
        "leave\n" /* line 1685 */
        "retl\n"
    );
}

/* line 1694 */
__attribute__((naked))
qboolean G_TraceCapsuleComplete(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1694 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl $0, 0x20(%esp)\n" /* line 1696 */
        "movl $0, 0x1c(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* contentmask */
        "movl %eax, 0x18(%esp)\n"
        "movl $0x3ff, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* end */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* maxs */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* mins */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* start */
        "movl %eax, (%esp)\n"
        "calll SV_TracePassed\n"
        "leave\n" /* line 1697 */
        "retl\n"
    );
}

/* line 1706 */
__attribute__((naked))
int G_LocationalTrace(trace_t *results, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask, unsigned char *priorityMap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1706 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl $1, 0x24(%esp)\n" /* line 1708 */
        "movl 0x1c(%ebp), %eax\n" /* priorityMap */
        "movl %eax, 0x20(%esp)\n"
        "movl $1, 0x1c(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* contentmask */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* end */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* results */
        "movl %eax, (%esp)\n"
        "calll SV_Trace\n"
        "leave\n" /* line 1709 */
        "retl\n"
    );
}

/* line 1718 */
__attribute__((naked))
qboolean G_LocationalTracePassed(const vec_t *start, const vec_t *end, int passEntityNum, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1718 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl $1, 0x20(%esp)\n" /* line 1720 */
        "movl $1, 0x1c(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* contentmask */
        "movl %eax, 0x18(%esp)\n"
        "movl $0x3ff, 0x14(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* end */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* start */
        "movl %eax, (%esp)\n"
        "calll SV_TracePassed\n"
        "leave\n" /* line 1721 */
        "retl\n"
    );
}

/* line 1730 */
__attribute__((naked))
int G_SightTrace(int *hitNum, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1730 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0x18(%ebp), %eax\n" /* line 1732 | contentmask */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0x3ff, 0x18(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* end */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* hitNum */
        "movl %eax, (%esp)\n"
        "calll SV_SightTrace\n"
        "leave\n" /* line 1733 */
        "retl\n"
    );
}

/* line 1742 */
__attribute__((naked))
int G_AddDebugString(const vec_t *xyz, const vec_t *color, float scale, const char *pszText)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1742 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $1, 0x10(%esp)\n" /* line 1746 */
        "movl 0x14(%ebp), %eax\n" /* pszText */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* scale */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* xyz */
        "movl %eax, (%esp)\n"
        "calll CL_AddDebugString\n"
        "leave\n" /* line 1749 */
        "retl\n"
    );
}

/* line 923 */
__attribute__((naked))
int G_ShutdownGame(qboolean freeScripts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 923 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl $0x2b4950, (%esp)\n" /* line 927 */
        "calll Com_Printf\n"
        "movl 0x1934498, %ecx\n" /* line 929 */
        "testl %ecx, %ecx\n"
        "jne .Lf1acce6_001ace17\n"
        ".Lf1acce6_001acd08:\n"
        "movl 0x195edb4, %eax\n" /* line 936 */
        "movl $0, (%eax)\n"
        "movl 0x193448c, %edx\n" /* line 659 */
        "testl %edx, %edx\n"
        "jle .Lf1acce6_001acd59\n"
        "movl $g_entities, %esi\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf1acce6_001acd37\n"
        ".Lf1acce6_001acd26:\n"
        "addl $1, %ebx\n"
        "addl $0x230, %esi\n"
        "cmpl 0x193448c, %ebx\n"
        "jge .Lf1acce6_001acd59\n"
        ".Lf1acce6_001acd37:\n"
        "cmpb $0, 0xfc(%esi)\n" /* line 661 */
        "je .Lf1acce6_001acd26\n"
        "movl %esi, (%esp)\n" /* line 664 */
        "calll G_FreeEntity\n"
        "addl $1, %ebx\n" /* line 659 */
        "addl $0x230, %esi\n"
        "cmpl 0x193448c, %ebx\n"
        "jl .Lf1acce6_001acd37\n"
        ".Lf1acce6_001acd59:\n"
        "cmpb $0, 0x186d71c\n" /* line 667 */
        "jne .Lf1acce6_001ace06\n"
        ".Lf1acce6_001acd66:\n"
        "movl $0, 0x193448c\n" /* line 672 */
        "movl $0, 0x1934490\n" /* line 673 */
        "movl $0, 0x1934494\n" /* line 674 */
        "calll HudElem_DestroyAll\n" /* line 939 */
        "movl $1, (%esp)\n" /* line 941 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf1acce6_001acda6\n"
        "movl 0x19361d4, %eax\n" /* line 943 */
        "testl %eax, %eax\n"
        "je .Lf1acce6_001acedf\n"
        ".Lf1acce6_001acda6:\n"
        "xorl %eax, %eax\n" /* line 947 */
        "cmpl $0, 0x19361d4\n"
        "sete %al\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ShutdownSystem\n"
        "movl 8(%ebp), %eax\n" /* line 949 | freeScripts */
        "testl %eax, %eax\n"
        "jne .Lf1acce6_001ace41\n"
        ".Lf1acce6_001acdc9:\n"
        "movl 0x1937a8c, %eax\n" /* line 962 */
        "testl %eax, %eax\n"
        "je .Lf1acce6_001acdda\n"
        "movl %eax, (%esp)\n" /* line 963 */
        "calll Z_FreeInternal\n"
        ".Lf1acce6_001acdda:\n"
        "movl $0, 0x1937a8c\n" /* line 964 */
        "movl 0x1937a88, %eax\n" /* line 966 */
        "testl %eax, %eax\n"
        "js .Lf1acce6_001acdf5\n"
        "movl %eax, (%esp)\n" /* line 967 */
        "calll FS_FCloseFile\n"
        ".Lf1acce6_001acdf5:\n"
        "movl $0xffffffff, 0x1937a88\n" /* line 969 */
        "addl $0x10, %esp\n" /* line 975 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1acce6_001ace06:\n"
        "movl $0x186d620, (%esp)\n" /* line 668 */
        "calll G_FreeEntity\n"
        "jmp .Lf1acce6_001acd66\n"
        ".Lf1acce6_001ace17:\n"
        "movl $0x2b4968, (%esp)\n" /* line 931 */
        "calll G_LogPrintf\n"
        "movl $0x2b4898, (%esp)\n" /* line 932 */
        "calll G_LogPrintf\n"
        "movl 0x1934498, %eax\n" /* line 933 */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "jmp .Lf1acce6_001acd08\n"
        ".Lf1acce6_001ace41:\n"
        "calll Mantle_ShutdownAnims\n" /* line 951 */
        "calll GScr_FreeScripts\n" /* line 953 */
        "movl $1, (%esp)\n" /* line 954 */
        "calll Scr_FreeScripts\n"
        "movl $level_bgs, %ebx\n"
        ".Lf1acce6_001ace5c:\n"
        "movl 0xb40a0(%ebx), %eax\n" /* line 725 */
        "testl %eax, %eax\n"
        "je .Lf1acce6_001ace80\n"
        "movl $0, 4(%esp)\n" /* line 727 */
        "movl %eax, (%esp)\n"
        "calll XAnimFreeTree\n"
        "movl $0, 0xb40a0(%ebx)\n" /* line 728 */
        ".Lf1acce6_001ace80:\n"
        "addl $0x4b8, %ebx\n"
        "cmpl $0x1880880, %ebx\n" /* line 723 */
        "jne .Lf1acce6_001ace5c\n"
        "movl 0x195f6d0, %ebx\n"
        "movl %ebx, %edx\n"
        "movl %ebx, %esi\n"
        ".Lf1acce6_001ace98:\n"
        "movl 0x10b8(%ebx), %eax\n" /* line 735 */
        "testl %eax, %eax\n"
        "je .Lf1acce6_001acebe\n"
        "movl $0, 4(%esp)\n" /* line 737 */
        "movl %eax, (%esp)\n"
        "calll XAnimFreeTree\n"
        "movl $0, 0x10b8(%ebx)\n" /* line 738 */
        "movl %esi, %edx\n"
        ".Lf1acce6_001acebe:\n"
        "addl $0x4c8, %ebx\n"
        "leal 0x2640(%edx), %eax\n" /* line 923 */
        "cmpl %ebx, %eax\n" /* line 733 */
        "jne .Lf1acce6_001ace98\n"
        "movl $0, (%esp)\n" /* line 957 */
        "calll Hunk_ClearToMarkLow\n"
        "jmp .Lf1acce6_001acdc9\n"
        ".Lf1acce6_001acedf:\n"
        "calll SV_FreeClientScriptPers\n" /* line 944 */
        "jmp .Lf1acce6_001acda6\n"
    );
}

/* line 1384 */
static __attribute__((naked))
int G_RunFrameForEntity(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1384 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %ebx\n" /* ent */
        "movl 0x1934668, %eax\n" /* line 1388 */
        "cmpl %eax, 0x188(%ebx)\n" /* ent */
        "je .Lf1aceea_001acf98\n"
        "movl %eax, 0x188(%ebx)\n" /* line 1390 | ent */
        "movl 0x158(%ebx), %eax\n" /* line 1399 | ent */
        "testl %eax, %eax\n"
        "je .Lf1aceea_001acfdd\n"
        ".Lf1aceea_001acf19:\n"
        "cmpl $0x10000, 8(%ebx)\n" /* line 1411 | ent */
        "je .Lf1aceea_001acf9f\n"
        "movl 0x193466c, %eax\n"
        ".Lf1aceea_001acf27:\n"
        "subl 0x178(%ebx), %eax\n" /* line 1421 | ent */
        "cmpl $0x12c, %eax\n"
        "jle .Lf1aceea_001acf48\n"
        "movl 0x17c(%ebx), %eax\n" /* line 1423 | ent */
        "testl %eax, %eax\n"
        "jne .Lf1aceea_001acfad\n"
        "movl 0x180(%ebx), %eax\n" /* line 1429 | ent */
        "testl %eax, %eax\n"
        "jne .Lf1aceea_001acfbc\n"
        ".Lf1aceea_001acf48:\n"
        "movl 0x17c(%ebx), %esi\n" /* line 1438 | ent, think */
        "testl %esi, %esi\n" /* think */
        "jne .Lf1aceea_001acf98\n"
        "movl 4(%ebx), %eax\n" /* line 1443 | ent */
        "cmpl $4, %eax\n"
        "je .Lf1aceea_001ad045\n"
        "cmpl $3, %eax\n" /* line 1449 */
        "je .Lf1aceea_001acfef\n"
        "cmpl $2, %eax\n" /* line 1462 */
        "je .Lf1aceea_001ad099\n"
        "cmpb $0, 0x160(%ebx)\n" /* line 1468 | ent */
        "jne .Lf1aceea_001acfd3\n"
        "cmpl $6, %eax\n" /* line 1474 */
        "je .Lf1aceea_001ad0a6\n"
        "movl 0x158(%ebx), %edx\n" /* line 1480 | ent */
        "testl %edx, %edx\n"
        "je .Lf1aceea_001ad070\n"
        "movl %ebx, (%esp)\n" /* line 1482 | ent */
        "calll G_RunClient\n"
        ".Lf1aceea_001acf98:\n"
        "addl $0x10, %esp\n" /* line 1493 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1aceea_001acf9f:\n"
        "movl 0x193466c, %eax\n" /* line 1413 */
        "cmpl 0x58(%ebx), %eax\n" /* ent */
        "jle .Lf1aceea_001acf27\n"
        ".Lf1aceea_001acfad:\n"
        "movl %ebx, (%esp)\n" /* line 1426 | ent */
        "calll G_FreeEntity\n"
        "addl $0x10, %esp\n" /* line 1493 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1aceea_001acfbc:\n"
        "movl $0, 0x180(%ebx)\n" /* line 1432 | ent */
        "movl %ebx, (%esp)\n" /* line 1433 | ent */
        "calll SV_UnlinkEntity\n"
        "jmp .Lf1aceea_001acf48\n"
        ".Lf1aceea_001acfd3:\n"
        "movl %ebx, (%esp)\n" /* line 1470 | ent */
        "calll G_RunItem\n"
        "jmp .Lf1aceea_001acf98\n"
        ".Lf1aceea_001acfdd:\n"
        "testb $8, 0x175(%ebx)\n" /* line 1401 | ent */
        "je .Lf1aceea_001ad03c\n"
        "orl $0x20, 8(%ebx)\n" /* line 1403 | ent */
        "jmp .Lf1aceea_001acf19\n"
        ".Lf1aceea_001acfef:\n"
        "movl 0x208(%ebx), %ecx\n" /* line 1451 | ent */
        "testl %ecx, %ecx\n"
        "je .Lf1aceea_001acfd3\n"
        "movl %ebx, (%esp)\n" /* line 1453 | ent */
        "calll G_GeneralLink\n"
        /* { scope 1 */
        "movl 0x190(%ebx), %eax\n" /* line 1329 */
        "testl %eax, %eax\n" /* line 1330 */
        "jle .Lf1aceea_001acf98\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1aceea_001ad00b:\n"
        "cmpl 0x193466c, %eax\n" /* line 1334 */
        "jg .Lf1aceea_001acf98\n"
        "movl $0, 0x190(%ebx)\n" /* line 1339 */
        "movzbl 0x166(%ebx), %eax\n" /* line 1340 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl entityHandlers(, %eax, 8), %esi\n" /* think */
        "testl %esi, %esi\n" /* line 1341 | think */
        "je .Lf1aceea_001ad052\n"
        "movl %ebx, (%esp)\n" /* line 1345 */
        "calll *%esi\n" /* think */
        "jmp .Lf1aceea_001acf98\n"
        /* } scope */
        ".Lf1aceea_001ad03c:\n"
        "andl $0xffffffdf, 8(%ebx)\n" /* line 1407 | ent */
        "jmp .Lf1aceea_001acf19\n"
        ".Lf1aceea_001ad045:\n"
        "movl %ebx, (%esp)\n" /* line 1445 | ent */
        "calll G_RunMissile\n"
        "jmp .Lf1aceea_001acf98\n"
        /* { scope 1 */
        ".Lf1aceea_001ad052:\n"
        "movl $0x2b4930, 4(%esp)\n" /* line 1343 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl %ebx, (%esp)\n" /* line 1345 */
        "calll *%esi\n" /* think */
        "jmp .Lf1aceea_001acf98\n"
        /* } scope */
        ".Lf1aceea_001ad070:\n"
        "testl %eax, %eax\n" /* line 1486 */
        "jne .Lf1aceea_001ad086\n"
        "movl 0x208(%ebx), %esi\n" /* line 1488 | ent, think */
        "testl %esi, %esi\n" /* think */
        "je .Lf1aceea_001ad086\n"
        "movl %ebx, (%esp)\n" /* line 1489 | ent */
        "calll G_GeneralLink\n"
        /* { scope 1 */
        ".Lf1aceea_001ad086:\n"
        "movl 0x190(%ebx), %eax\n" /* line 1329 */
        "testl %eax, %eax\n" /* line 1330 */
        "jg .Lf1aceea_001ad00b\n"
        "jmp .Lf1aceea_001acf98\n"
        /* } scope */
        ".Lf1aceea_001ad099:\n"
        "movl %ebx, (%esp)\n" /* line 1464 | ent */
        "calll G_RunCorpse\n"
        "jmp .Lf1aceea_001acf98\n"
        ".Lf1aceea_001ad0a6:\n"
        "movl %ebx, (%esp)\n" /* line 1476 | ent */
        "calll G_RunMover\n"
        "jmp .Lf1aceea_001acf98\n"
    );
}

/* line 1503 */
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
        "addl $1, 0x1934668\n" /* line 1518 */
        "movl 0x193466c, %edx\n" /* line 1519 */
        "movl %edx, 0x1934670\n"
        "movl %eax, 0x193466c\n" /* line 1520 */
        "movl %eax, %ecx\n" /* line 1521 */
        "subl %edx, %ecx\n"
        "movl %ecx, 0x1934674\n"
        "movl %eax, 0x192165c\n" /* line 1523 */
        "movl %eax, 0x1921660\n" /* line 1524 */
        "movl %ecx, 0x1921664\n" /* line 1525 */
        "movl 0x195edb4, %eax\n" /* line 1528 */
        "movl $level_bgs, (%eax)\n"
        "movl 0x193448c, %eax\n" /* line 1535 */
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad15b\n"
        "movl $g_entities, %ebx\n" /* trigger_info */
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf1ad0b4_001ad123\n"
        ".Lf1ad0b4_001ad112:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl 0x193448c, %esi\n" /* i */
        "jge .Lf1ad0b4_001ad15b\n"
        ".Lf1ad0b4_001ad123:\n"
        "cmpb $0, 0xfc(%ebx)\n" /* line 1537 | trigger_info */
        "je .Lf1ad0b4_001ad112\n"
        "cvtsi2ssl 0x1934674, %xmm0\n" /* line 1538 */
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* trigger_info */
        "calll SV_DObjInitServerTime\n"
        "addl $1, %esi\n" /* line 1535 | i */
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl 0x193448c, %esi\n" /* i */
        "jl .Lf1ad0b4_001ad123\n"
        ".Lf1ad0b4_001ad15b:\n"
        "leal -0x418(%ebp), %eax\n" /* line 1543 | entIndex */
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0x1937a68, %eax\n" /* line 1550 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x1936268, 4(%esp)\n"
        "movl $0x1936e68, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl 0x1937a68, %eax\n" /* line 1551 */
        "movl %eax, 0x1937a6c\n"
        "movl $0, 0x1937a68\n" /* line 1552 */
        "movb $0, -0x429(%ebp)\n" /* index */
        ".Lf1ad0b4_001ad1b7:\n"
        "addb $1, -0x429(%ebp)\n" /* line 1557 | index */
        "movl 0x1937a6c, %eax\n" /* line 1558 */
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad602\n"
        "xorl %edi, %edi\n"
        "movl $0, -0x430(%ebp)\n" /* bMoreTriggered */
        "movl $0x1936e60, %esi\n" /* i */
        "jmp .Lf1ad0b4_001ad223\n"
        ".Lf1ad0b4_001ad1de:\n"
        "movl 0x1937a6c, %eax\n" /* line 1580 */
        "subl $1, %eax\n"
        "movl %eax, 0x1937a6c\n"
        "subl $1, %edi\n" /* line 1581 */
        "subl $0xc, %esi\n" /* i */
        "leal (%eax, %eax, 2), %eax\n" /* line 1582 */
        "shll $2, %eax\n"
        "movl 0x1936e68(%eax), %edx\n"
        "movl %edx, (%ebx)\n" /* trigger_info */
        "movl 0x1936e6c(%eax), %edx\n"
        "movl %edx, 4(%ebx)\n" /* trigger_info */
        "movl 0x1936e70(%eax), %eax\n"
        "movl %eax, 8(%ebx)\n" /* trigger_info */
        "addl $1, %edi\n" /* line 1558 */
        "addl $0xc, %esi\n" /* i */
        "cmpl 0x1937a6c, %edi\n"
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
        "cmpl 0x1937a6c, %edi\n"
        "jl .Lf1ad0b4_001ad223\n"
        ".Lf1ad0b4_001ad2a8:\n"
        "calll Scr_RunCurrentThreads\n" /* line 1585 */
        "movl -0x430(%ebp), %eax\n" /* line 1554 | bMoreTriggered */
        "testl %eax, %eax\n"
        "jne .Lf1ad0b4_001ad1b7\n"
        ".Lf1ad0b4_001ad2bb:\n"
        "movl 0x193448c, %eax\n" /* line 1593 */
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad33e\n"
        "movl $g_entities, %edi\n"
        "xorl %esi, %esi\n" /* i */
        "movl $0x17e1b7c, %ebx\n" /* trigger_info */
        "jmp .Lf1ad0b4_001ad2e9\n"
        ".Lf1ad0b4_001ad2d2:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x230, %edi\n"
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl 0x193448c, %esi\n" /* i */
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
        "cmpl 0x193448c, %esi\n" /* i */
        "jl .Lf1ad0b4_001ad2e9\n"
        ".Lf1ad0b4_001ad33e:\n"
        "calll Scr_IncTime\n" /* line 1598 */
        "movl $0, 0x1937a84\n" /* line 1607 */
        "movl 0x193448c, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad39e\n"
        "movl $g_entities, %esi\n" /* i */
        "movl $0x17e1b7c, %ebx\n" /* trigger_info */
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
        "movl 0x1937a84, %eax\n" /* line 1607 */
        "addl $1, %eax\n"
        "movl %eax, 0x1937a84\n"
        "addl $0x230, %esi\n" /* i */
        "addl $0x230, %ebx\n" /* trigger_info */
        "cmpl 0x193448c, %eax\n"
        "jl .Lf1ad0b4_001ad360\n"
        ".Lf1ad0b4_001ad39e:\n"
        "movl $0xffffffff, 0x1937a84\n" /* line 1623 */
        "movl 0x1934664, %eax\n" /* line 1275 */
        "testl %eax, %eax\n"
        "jle .Lf1ad0b4_001ad4aa\n"
        "movl $0, -0x428(%ebp)\n"
        "movl $0, -0x424(%ebp)\n"
        ".Lf1ad0b4_001ad3c9:\n"
        "movl -0x424(%ebp), %eax\n" /* line 1277 */
        "addl 0x1934484, %eax\n"
        "cmpb $0, 0xfc(%eax)\n" /* line 1278 */
        "je .Lf1ad0b4_001ad487\n"
        "movl 0x158(%eax), %eax\n" /* line 1281 */
        "movl 0x274c(%eax), %edi\n" /* line 1282 */
        "movl %eax, %ecx\n"
        "movl $0x19344a4, %ebx\n"
        "movl $0x1934664, %esi\n"
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
        "subl $0x19344a4, %edx\n"
        "movl 0x19344a4(%edx), %eax\n"
        "movl %eax, 0x5e4(%ecx)\n"
        "movl 0x19344a8(%edx), %eax\n"
        "movl %eax, 0x5e8(%ecx)\n"
        "movl 0x19344ac(%edx), %eax\n"
        "movl %eax, 0x5ec(%ecx)\n"
        "movl 0x19344b0(%edx), %eax\n"
        "movl %eax, 0x5f0(%ecx)\n"
        "movl 0x19344b4(%edx), %eax\n"
        "movl %eax, 0x5f4(%ecx)\n"
        "movl 0x19344b8(%edx), %eax\n"
        "movl %eax, 0x5f8(%ecx)\n"
        "movl 0x19344bc(%edx), %eax\n"
        "movl %eax, 0x5fc(%ecx)\n"
        "addl $0x1c, %ebx\n"
        "addl $0x1c, %ecx\n"
        "cmpl %ebx, %esi\n" /* line 1284 */
        "jne .Lf1ad0b4_001ad414\n"
        ".Lf1ad0b4_001ad487:\n"
        "addl $1, -0x428(%ebp)\n" /* line 1275 */
        "addl $0x230, -0x424(%ebp)\n"
        "movl -0x428(%ebp), %eax\n"
        "cmpl 0x1934664, %eax\n"
        "jl .Lf1ad0b4_001ad3c9\n"
        ".Lf1ad0b4_001ad4aa:\n"
        "movl 0x1934664, %edi\n" /* line 1306 */
        "testl %edi, %edi\n"
        "jle .Lf1ad0b4_001ad509\n"
        "xorl %esi, %esi\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf1ad0b4_001ad4cb\n"
        ".Lf1ad0b4_001ad4ba:\n"
        "addl $1, %esi\n"
        "addl $0x230, %ebx\n"
        "cmpl 0x1934664, %esi\n"
        "jge .Lf1ad0b4_001ad509\n"
        ".Lf1ad0b4_001ad4cb:\n"
        "movl %ebx, %edx\n" /* line 1308 */
        "addl 0x1934484, %edx\n"
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
        "cmpl 0x1934664, %esi\n"
        "jl .Lf1ad0b4_001ad4cb\n"
        ".Lf1ad0b4_001ad509:\n"
        "movl 0x1934664, %esi\n" /* line 1638 | i */
        "testl %esi, %esi\n" /* i */
        "jle .Lf1ad0b4_001ad54f\n"
        "movl $g_entities, %esi\n" /* i */
        "xorl %ebx, %ebx\n" /* trigger_info */
        "jmp .Lf1ad0b4_001ad52d\n"
        ".Lf1ad0b4_001ad51c:\n"
        "addl $1, %ebx\n" /* trigger_info */
        "addl $0x230, %esi\n" /* i */
        "cmpl 0x1934664, %ebx\n" /* trigger_info */
        "jge .Lf1ad0b4_001ad54f\n"
        ".Lf1ad0b4_001ad52d:\n"
        "cmpb $0, 0xfc(%esi)\n" /* line 1640 | i */
        "je .Lf1ad0b4_001ad51c\n"
        "movl %esi, (%esp)\n" /* line 1642 | i */
        "calll ClientEndFrame\n"
        "addl $1, %ebx\n" /* line 1638 | trigger_info */
        "addl $0x230, %esi\n" /* i */
        "cmpl 0x1934664, %ebx\n" /* trigger_info */
        "jl .Lf1ad0b4_001ad52d\n"
        ".Lf1ad0b4_001ad54f:\n"
        "calll CheckTeamStatus\n" /* line 1648 */
        "movl g_oldVoting, %eax\n" /* line 1650 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1ad0b4_001ad6a2\n"
        ".Lf1ad0b4_001ad563:\n"
        "movl 0x1934690, %ebx\n" /* line 995 */
        "testl %ebx, %ebx\n"
        "je .Lf1ad0b4_001ad584\n"
        "movl 0x1934664, %eax\n" /* line 1000 */
        "testl %eax, %eax\n"
        "jg .Lf1ad0b4_001ad65b\n"
        ".Lf1ad0b4_001ad57a:\n"
        "movl $0, 0x1934690\n" /* line 1010 */
        ".Lf1ad0b4_001ad584:\n"
        "movl g_listEntity, %eax\n" /* line 1655 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1ad0b4_001ad6c0\n"
        ".Lf1ad0b4_001ad593:\n"
        "movl 0x1937a7c, %ecx\n" /* line 1662 */
        "testl %ecx, %ecx\n"
        "jne .Lf1ad0b4_001ad6b6\n"
        ".Lf1ad0b4_001ad5a1:\n"
        "movl 0x1937a80, %edx\n" /* line 1665 */
        "testl %edx, %edx\n"
        "jne .Lf1ad0b4_001ad6ac\n"
        ".Lf1ad0b4_001ad5af:\n"
        "movl g_dumpAnims, %eax\n" /* line 1356 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf1ad0b4_001ad5ec\n"
        "movl $0x2b4944, (%esp)\n" /* line 1359 */
        "calll Com_Printf\n"
        "movl g_dumpAnims, %eax\n" /* line 1360 */
        "movl 8(%eax), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x1934484, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_DObjDisplayAnim\n"
        ".Lf1ad0b4_001ad5ec:\n"
        "movl 0x195edb4, %eax\n" /* line 1670 */
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
        "movl 0x195f5bc, %eax\n"
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
        "cmpl 0x1934664, %esi\n"
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
        "movl $0x2a8b40, (%esp)\n" /* "%4i: %s
" */
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

