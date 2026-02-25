/* ASM dump from: sv_game_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_game_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 */

extern qboolean gameInitialized; /* 0x0 */
static int warnCount; /* 0xec7000 */
static int boxVerts[24][3]; /* 0x311c40 */
static char g_sv_skel_memory[262144]; /* 0xe87000 */
static char *g_sv_skel_memory_start; /* 0xe86f80 */

gentity_t * SV_GentityNum(int num);
playerState_t * SV_GameClientNum(int num);
int SV_SvEntityForGentity(const gentity_t *gEnt);
long unsigned int SV_GameSendServerCommand(int clientNum, svscmd_type type, const char *text);
long unsigned int SV_GameDropClient(int clientNum, const char *reason);
long unsigned int SV_GetServerinfo(char *buffer, int bufferSize);
long unsigned int SV_LocateGameData(gentity_t *gEnts, int numGEntities, int sizeofGEntity_t, playerState_t *clients, int sizeofGameClient);
long unsigned int SV_GetUsercmd(int clientNum, usercmd_t *cmd);
static long unsigned int * SV_AllocXModelPrecache(int size);
static long unsigned int * SV_AllocXModelPrecacheColl(int size);
struct XModel * SV_XModelGet(const char *name);
long unsigned int SV_DObjDumpInfo(gentity_t *ent);
long unsigned int SV_ResetSkeletonCache(void);
qboolean SV_DObjUpdateServerTime(gentity_t *ent, float dtime, qboolean bNotify);
long unsigned int SV_DObjInitServerTime(gentity_t *ent, float dtime);
long unsigned int SV_DObjGetHierarchyBits(gentity_t *ent, int boneIndex, int *partBits);
long unsigned int SV_DObjCalcAnim(gentity_t *ent, int *partBits);
long unsigned int SV_DObjCalcSkel(gentity_t *ent, int *partBits);
int SV_DObjGetBoneIndex(gentity_t *ent, unsigned int boneName);
DObjAnimMat_s * SV_DObjGetMatrixArray(gentity_t *ent);
long unsigned int SV_DObjDisplayAnim(gentity_t *ent);
struct XAnimTree_s * SV_DObjGetTree(gentity_t *ent);
qboolean SV_MapExists(const char *name);
long unsigned int SV_ResetEntityParsePoint(void);
qboolean SV_DObjExists(gentity_t *ent);
long unsigned int SV_SetWeaponInfoMemory(void);
qboolean SV_GetEntityToken(char *buffer, int bufferSize);
int SV_GetGuid(int clientNum);
int SV_GetClientPing(int clientNum);
qboolean SV_IsLocalClient(int clientNum);
long unsigned int SV_SetGametype(void);
static long unsigned int SV_InitGameVM(void);
long unsigned int SV_RestartGameProgs(qboolean savepersist);
long unsigned int SV_InitGameProgs(qboolean savepersist);
qboolean SV_GameCommand(void);
long unsigned int SV_SetBrushModel(gentity_t *ent);
qboolean SV_EntityContact(const vec_t *mins, const vec_t *maxs, const gentity_t *gEnt);
gentity_t * SV_GEntityForSvEntity(gentity_s (*svEnt)[4]);
long unsigned int SV_XModelDebugBoxes(gentity_t *ent);
long unsigned int SV_ShutdownGameProgs(void);
qboolean SV_inSnapshot(const vec_t *origin, int iEntityNum);
qboolean SV_DObjCreateSkelForBone(gentity_t *ent, int boneIndex);
qboolean SV_DObjCreateSkelForBones(gentity_t *ent, int *partBits);

/* line 76 */
__attribute__((naked))
gentity_t * SV_GentityNum(int num)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 76 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* num */
        "movl 0x195ee80, %edx\n"
        "imull 0x5f420(%edx), %eax\n" /* num */
        "addl 0x5f41c(%edx), %eax\n" /* num */
        "popl %ebp\n" /* line 83 */
        "retl\n"
    );
}

/* line 86 */
__attribute__((naked))
playerState_t * SV_GameClientNum(int num)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 86 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* num */
        "movl 0x195ee80, %edx\n"
        "imull 0x5f42c(%edx), %eax\n" /* num */
        "addl 0x5f428(%edx), %eax\n" /* num */
        "popl %ebp\n" /* line 93 */
        "retl\n"
    );
}

/* line 96 */
__attribute__((naked))
int SV_SvEntityForGentity(const gentity_t *gEnt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* gEnt */
        "testl %ebx, %ebx\n" /* line 98 | gEnt */
        "je .Lf14d670_0014d68b\n"
        "movl (%ebx), %eax\n" /* gEnt */
        "testl %eax, %eax\n"
        "js .Lf14d670_0014d68b\n"
        "cmpl $0x3ff, %eax\n"
        "jle .Lf14d670_0014d6a1\n"
        ".Lf14d670_0014d68b:\n"
        "movl $0x2a99e4, 4(%esp)\n" /* line 100 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl (%ebx), %eax\n" /* gEnt */
        ".Lf14d670_0014d6a1:\n"
        "leal (%eax, %eax, 2), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x195ee80, %edx\n"
        "leal 0x2418(%edx, %eax, 4), %eax\n"
        "addl $0x14, %esp\n" /* line 103 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 122 */
__attribute__((naked))
long unsigned int SV_GameSendServerCommand(int clientNum, svscmd_type type, const char *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* clientNum */
        "cmpl $-1, %ecx\n" /* line 124 */
        "je .Lf14d6be_0014d721\n"
        "testl %ecx, %ecx\n" /* line 131 */
        "js .Lf14d6be_0014d6dc\n"
        "movl 0x195f290, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf14d6be_0014d6de\n"
        ".Lf14d6be_0014d6dc:\n"
        "leave\n" /* line 137 */
        "retl\n"
        ".Lf14d6be_0014d6de:\n"
        "movl 0x10(%ebp), %eax\n" /* line 135 | text */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x216058, 8(%esp)\n" /* "%s" */
        "movl 0xc(%ebp), %eax\n" /* type */
        "movl %eax, 4(%esp)\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195f284, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SV_SendServerCommand\n"
        "leave\n" /* line 137 */
        "retl\n"
        ".Lf14d6be_0014d721:\n"
        "movl 0x10(%ebp), %eax\n" /* line 126 | text */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x216058, 8(%esp)\n" /* "%s" */
        "movl 0xc(%ebp), %eax\n" /* type */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SendServerCommand\n"
        "leave\n" /* line 137 */
        "retl\n"
    );
}

/* line 147 */
__attribute__((naked))
long unsigned int SV_GameDropClient(int clientNum, const char *reason)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 147 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* clientNum */
        "testl %ecx, %ecx\n" /* line 150 */
        "js .Lf14d746_0014d75c\n"
        "movl 0x195f290, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf14d746_0014d75e\n"
        ".Lf14d746_0014d75c:\n"
        "popl %ebp\n" /* line 155 */
        "retl\n"
        ".Lf14d746_0014d75e:\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 154 */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195f284, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, 8(%ebp)\n" /* clientNum */
        "popl %ebp\n" /* line 155 */
        "jmp SV_DropClient\n" /* line 154 */
    );
}

/* line 316 */
__attribute__((naked))
long unsigned int SV_GetServerinfo(char *buffer, int bufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 316 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* bufferSize */
        "testl %ebx, %ebx\n" /* line 318 | bufferSize */
        "jle .Lf14d78a_0014d7bd\n"
        "movl $0x404, (%esp)\n" /* line 322 */
        "calll Dvar_InfoString\n"
        "movl %ebx, 8(%esp)\n" /* bufferSize */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x14, %esp\n" /* line 323 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14d78a_0014d7bd:\n"
        "movl %ebx, 8(%esp)\n" /* line 320 | bufferSize */
        "movl $0x2a9a08, 4(%esp)\n" /* "SV_GetServerinfo: bufferSize == %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0x404, (%esp)\n" /* line 322 */
        "calll Dvar_InfoString\n"
        "movl %ebx, 8(%esp)\n" /* bufferSize */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x14, %esp\n" /* line 323 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 424 */
__attribute__((naked))
long unsigned int SV_LocateGameData(gentity_t *gEnts, int numGEntities, int sizeofGEntity_t, playerState_t *clients, int sizeofGameClient)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 424 */
        "movl %esp, %ebp\n"
        "movl 0x195ee80, %edx\n" /* line 426 */
        "movl 8(%ebp), %eax\n" /* gEnts */
        "movl %eax, 0x5f41c(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 427 | sizeofGEntity_t */
        "movl %eax, 0x5f420(%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 428 | numGEntities */
        "movl %eax, 0x5f424(%edx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 430 | clients */
        "movl %eax, 0x5f428(%edx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 431 | sizeofGameClient */
        "movl %eax, 0x5f42c(%edx)\n"
        "popl %ebp\n" /* line 432 */
        "retl\n"
    );
}

/* line 441 */
__attribute__((naked))
long unsigned int SV_GetUsercmd(int clientNum, usercmd_t *cmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 441 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* clientNum */
        "movl 0xc(%ebp), %esi\n" /* cmd */
        "movl 0x195f284, %eax\n" /* line 447 */
        "movl 0xc(%eax), %ecx\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* clientNum */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ebx, %eax\n" /* clientNum */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl 0x20824(%edx, %ecx), %eax\n"
        "movl %eax, (%esi)\n" /* cmd */
        "movl 0x20828(%edx, %ecx), %eax\n"
        "movl %eax, 4(%esi)\n" /* cmd */
        "movl 0x2082c(%edx, %ecx), %eax\n"
        "movl %eax, 8(%esi)\n" /* cmd */
        "movl 0x20830(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* cmd */
        "movl 0x20834(%edx, %ecx), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* cmd */
        "movl 0x20838(%edx, %ecx), %eax\n"
        "movl %eax, 0x14(%esi)\n" /* cmd */
        "movl 0x2083c(%edx, %ecx), %eax\n"
        "movl %eax, 0x18(%esi)\n" /* cmd */
        "popl %ebx\n" /* line 448 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 453 */
static __attribute__((naked))
long unsigned int * SV_AllocXModelPrecache(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 453 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 456 */
        "jmp Hunk_AllocInternal\n" /* line 455 */
    );
}

/* line 459 */
static __attribute__((naked))
long unsigned int * SV_AllocXModelPrecacheColl(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 459 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 462 */
        "jmp Hunk_AllocInternal\n" /* line 461 */
    );
}

/* line 471 */
__attribute__((naked))
struct XModel * SV_XModelGet(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 471 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        "movl %ebx, (%esp)\n" /* line 473 | name */
        "calll Com_ValidXModelName\n"
        "testb %al, %al\n"
        "jne .Lf14d8be_0014d8ec\n"
        "movl %ebx, 8(%esp)\n" /* line 474 | name */
        "movl $0x2a9a2c, 4(%esp)\n" /* "bad model name '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf14d8be_0014d8ec:\n"
        "movl $SV_AllocXModelPrecacheColl, 8(%esp)\n" /* line 476 */
        "movl $SV_AllocXModelPrecache, 4(%esp)\n"
        "leal 7(%ebx), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll XModelPrecache\n"
        "addl $0x14, %esp\n" /* line 477 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 486 */
__attribute__((naked))
long unsigned int SV_DObjDumpInfo(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 486 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* ent */
        /* { scope 1 */
        "movl 0x195ecc0, %eax\n" /* line 491 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf14d90e_0014d927\n"
        /* } scope */
        "leave\n" /* line 503 */
        "retl\n"
        /* { scope 1 */
        ".Lf14d90e_0014d927:\n"
        "movl (%edx), %eax\n" /* line 495 */
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n" /* line 496 */
        "je .Lf14d90e_0014d93e\n"
        "movl %eax, 8(%ebp)\n" /* line 502 | ent */
        /* } scope */
        "leave\n" /* line 503 */
        /* { scope 1 */
        "jmp DObjDumpInfo\n" /* line 502 */
        ".Lf14d90e_0014d93e:\n"
        "movl $0x2a9a44, 8(%ebp)\n" /* line 498 | ent */
        /* } scope */
        "leave\n" /* line 503 */
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 498 */
    );
}

/* line 512 */
__attribute__((naked))
long unsigned int SV_ResetSkeletonCache(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 512 */
        "movl %esp, %ebp\n"
        "movl 0x195ee80, %ecx\n" /* line 514 */
        "movl $1, %eax\n" /* line 516 */
        "movl 0x5f430(%ecx), %edx\n"
        "addl $1, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, 0x5f430(%ecx)\n"
        "movl $0xe8700f, %eax\n" /* line 518 */
        "andl $0xfffffff0, %eax\n"
        "movl %eax, g_sv_skel_memory_start\n"
        "movl $0, 0x5f434(%ecx)\n" /* line 519 */
        "popl %ebp\n" /* line 520 */
        "retl\n"
    );
}

/* line 622 */
__attribute__((naked))
qboolean SV_DObjUpdateServerTime(gentity_t *ent, float dtime, qboolean bNotify)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 622 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* dtime */
        "movl 0x10(%ebp), %ebx\n" /* bNotify */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 626 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n" /* line 627 */
        "je .Lf14d986_0014d9b9\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 630 | bNotify */
        "movl %esi, 0xc(%ebp)\n" /* dtime */
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "addl $0x10, %esp\n" /* line 631 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjUpdateServerInfo\n" /* line 630 */
        /* } scope */
        ".Lf14d986_0014d9b9:\n"
        "xorl %eax, %eax\n" /* line 631 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 640 */
__attribute__((naked))
long unsigned int SV_DObjInitServerTime(gentity_t *ent, float dtime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 640 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* dtime */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 644 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n" /* line 645 */
        "je .Lf14d9c2_0014d9ed\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 648 | dtime */
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 649 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjInitServerTime\n" /* line 648 */
        /* } scope */
        ".Lf14d9c2_0014d9ed:\n"
        "addl $0x14, %esp\n" /* line 649 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 658 */
__attribute__((naked))
long unsigned int SV_DObjGetHierarchyBits(gentity_t *ent, int boneIndex, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 658 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* boneIndex */
        "movl 0x10(%ebp), %ebx\n" /* partBits */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 662 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 665 | partBits */
        "movl %esi, 0xc(%ebp)\n" /* boneIndex */
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "addl $0x10, %esp\n" /* line 666 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjGetHierarchyBits\n" /* line 665 */
    );
}

/* line 675 */
__attribute__((naked))
long unsigned int SV_DObjCalcAnim(gentity_t *ent, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 675 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* partBits */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 679 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 683 | partBits */
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 684 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjCalcAnim\n" /* line 683 */
    );
}

/* line 693 */
__attribute__((naked))
long unsigned int SV_DObjCalcSkel(gentity_t *ent, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 693 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* partBits */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 697 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 701 | partBits */
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 702 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjCalcSkel\n" /* line 701 */
    );
}

/* line 728 */
__attribute__((naked))
int SV_DObjGetBoneIndex(gentity_t *ent, unsigned int boneName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 728 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* boneName */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 732 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n" /* line 733 */
        "je .Lf14da74_0014da9f\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 736 | boneName */
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 737 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjGetBoneIndex\n" /* line 736 */
        /* } scope */
        ".Lf14da74_0014da9f:\n"
        "movl $0xffffffff, %eax\n" /* line 737 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 746 */
__attribute__((naked))
DObjAnimMat_s * SV_DObjGetMatrixArray(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 746 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 750 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %eax, 8(%ebp)\n" /* line 753 | ent */
        /* } scope */
        "leave\n" /* line 754 */
        /* { scope 1 */
        "jmp DObjGetRotTransArray\n" /* line 753 */
    );
}

/* line 763 */
__attribute__((naked))
long unsigned int SV_DObjDisplayAnim(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 763 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 767 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n" /* line 768 */
        "je .Lf14dac6_0014dae6\n"
        "movl %eax, 8(%ebp)\n" /* line 771 | ent */
        /* } scope */
        "leave\n" /* line 772 */
        /* { scope 1 */
        "jmp DObjDisplayAnim\n" /* line 771 */
        /* } scope */
        ".Lf14dac6_0014dae6:\n"
        "leave\n" /* line 772 */
        "retl\n"
    );
}

/* line 831 */
__attribute__((naked))
struct XAnimTree_s * SV_DObjGetTree(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 831 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 835 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n" /* line 836 */
        "je .Lf14dae8_0014db08\n"
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "leave\n" /* line 837 */
        /* { scope 1 */
        "jmp DObjGetTree\n" /* line 836 */
        /* } scope */
        ".Lf14dae8_0014db08:\n"
        "xorl %eax, %eax\n" /* line 837 */
        "leave\n"
        "retl\n"
    );
}

/* line 923 */
__attribute__((naked))
qboolean SV_MapExists(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 923 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 929 | name */
        "movl %eax, (%esp)\n"
        "calll SV_GetMapBaseName\n"
        "movl %eax, %ebx\n" /* basename */
        "calll GetBspExtension\n" /* line 930 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* basename */
        "movl $0x2a74ac, (%esp)\n" /* "maps/mp/%s.%s" */
        "calll va\n"
        "movl $0, 4(%esp)\n" /* line 931 */
        "movl %eax, (%esp)\n"
        "calll FS_ReadFile\n"
        "notl %eax\n"
        "shrl $0x1f, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 936 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 946 */
__attribute__((naked))
long unsigned int SV_ResetEntityParsePoint(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 946 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll CM_EntityString\n" /* line 948 */
        "movl 0x195ee80, %edx\n"
        "movl %eax, 0x5f418(%edx)\n"
        "leave\n" /* line 949 */
        "retl\n"
    );
}

/* line 957 */
__attribute__((naked))
qboolean SV_DObjExists(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 957 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 959 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 960 */
        "retl\n"
    );
}

/* line 969 */
__attribute__((naked))
long unsigned int SV_SetWeaponInfoMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 969 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, (%esp)\n" /* line 971 */
        "calll Com_SetWeaponInfoMemory\n"
        "leave\n" /* line 972 */
        "retl\n"
    );
}

/* line 993 */
__attribute__((naked))
qboolean SV_GetEntityToken(char *buffer, int bufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 993 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 0x195ee80, %ebx\n" /* line 997 */
        "leal 0x5f418(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* s */
        "movl 0xc(%ebp), %eax\n" /* line 998 | bufferSize */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* s */
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl 0x5f418(%ebx), %edx\n" /* line 999 */
        "testl %edx, %edx\n"
        "je .Lf14dba0_0014dbea\n"
        ".Lf14dba0_0014dbde:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf14dba0_0014dbe3:\n"
        "addl $0x10, %esp\n" /* line 1000 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14dba0_0014dbea:\n"
        "cmpb $0, (%esi)\n" /* line 999 | s */
        "jne .Lf14dba0_0014dbde\n"
        "xorl %eax, %eax\n"
        "jmp .Lf14dba0_0014dbe3\n"
    );
}

/* line 1037 */
__attribute__((naked))
int SV_GetGuid(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1037 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* clientNum */
        "testl %ebx, %ebx\n" /* line 1040 | clientNum */
        "js .Lf14dbf4_0014dc35\n"
        "movl 0x195f290, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n" /* clientNum */
        "jge .Lf14dbf4_0014dc35\n"
        "movl 0x195f284, %eax\n" /* line 1042 */
        "movl 0xc(%eax), %ecx\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* clientNum */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ebx, %eax\n" /* clientNum */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl 0x765ec(%ecx, %edx, 4), %eax\n"
        "popl %ebx\n" /* line 1043 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14dbf4_0014dc35:\n"
        "xorl %eax, %eax\n" /* line 1042 */
        "popl %ebx\n" /* line 1043 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1052 */
__attribute__((naked))
int SV_GetClientPing(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1052 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* clientNum */
        "movl 0x195f284, %eax\n"
        "movl 0xc(%eax), %ebx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n" /* clientNum */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl 0x6e5a4(%ebx, %edx, 4), %eax\n"
        "popl %ebx\n" /* line 1055 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1064 */
__attribute__((naked))
qboolean SV_IsLocalClient(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1064 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ecx\n" /* clientNum */
        "movl 0x195f284, %eax\n" /* line 1066 */
        "movl 0xc(%eax), %ebx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl 0x6e5c4(%edx, %ebx), %esi\n"
        "movl %esi, -0x14(%ebp)\n"
        "movl 0x6e5c8(%edx, %ebx), %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl 0x6e5cc(%edx, %ebx), %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "movl %esi, (%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_IsLocalAddress\n"
        "addl $0x20, %esp\n" /* line 1067 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1106 */
__attribute__((naked))
long unsigned int SV_SetGametype(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1106 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "movl $0x1024, 8(%esp)\n" /* line 1111 */
        "movl $0x2a70fc, 4(%esp)\n" /* "dm" */
        "movl $0x2a7100, (%esp)\n" /* "g_gametype" */
        "calll Dvar_RegisterString\n"
        "movl 0x195ecbc, %eax\n" /* line 1113 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14dcd0_0014dd0e\n"
        "calll G_GetSavePersist\n"
        "testl %eax, %eax\n"
        "jne .Lf14dcd0_0014dd92\n"
        ".Lf14dcd0_0014dd0e:\n"
        "movl $0x40, 8(%esp)\n" /* line 1116 */
        "movl 0x195f29c, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %esi\n" /* gametype */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        ".Lf14dcd0_0014dd2f:\n"
        "movzbl -0x48(%ebp), %eax\n" /* line 1132 | gametype */
        "testb %al, %al\n"
        "jne .Lf14dcd0_0014dd77\n"
        ".Lf14dcd0_0014dd37:\n"
        "movl %esi, (%esp)\n" /* line 1135 */
        "calll Scr_IsValidGameType\n"
        "testl %eax, %eax\n"
        "jne .Lf14dcd0_0014dd5d\n"
        "movl %esi, 4(%esp)\n" /* line 1137 */
        "movl $0x2a9a50, (%esp)\n" /* "g_gametype %s is not a valid gametype, defaulting to dm
" */
        "calll Com_Printf\n"
        "movw $0x6d64, -0x48(%ebp)\n" /* line 1138 | gametype */
        "movb $0, -0x46(%ebp)\n"
        ".Lf14dcd0_0014dd5d:\n"
        "movl %esi, 4(%esp)\n" /* line 1141 */
        "movl 0x195f29c, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 1142 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14dcd0_0014dd77:\n"
        "movl %esi, %ebx\n" /* line 1132 | s */
        ".Lf14dcd0_0014dd79:\n"
        "movsbl %al, %eax\n" /* line 1133 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, (%ebx)\n" /* s */
        "addl $1, %ebx\n" /* line 1132 | s */
        "movzbl (%ebx), %eax\n" /* s */
        "testb %al, %al\n"
        "jne .Lf14dcd0_0014dd79\n"
        "jmp .Lf14dcd0_0014dd37\n"
        ".Lf14dcd0_0014dd92:\n"
        "movl $0x40, 8(%esp)\n" /* line 1114 */
        "movl 0x195ee80, %eax\n"
        "addl $0x5f4f4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %esi\n" /* gametype */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf14dcd0_0014dd2f\n"
    );
}

/* line 1152 */
static __attribute__((naked))
long unsigned int SV_InitGameVM(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1152 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %esi\n" /* restart */
        "movl %edx, %ebx\n" /* savepersist */
        /* { scope 1 */
        "calll FX_InitServer\n" /* line 1156 */
        "calll CM_EntityString\n" /* line 1159 */
        "movl 0x195ee80, %edx\n"
        "movl %eax, 0x5f418(%edx)\n"
        "calll Sys_LoadingKeepAlive\n" /* line 1163 */
        "calll Sys_MillisecondsRaw\n" /* line 1164 */
        "movl %ebx, 0xc(%esp)\n" /* savepersist */
        "movl %esi, 8(%esp)\n" /* restart */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f284, %esi\n" /* restart */
        "movl 4(%esi), %eax\n" /* restart */
        "movl %eax, (%esp)\n"
        "calll G_InitGame\n"
        "calll Sys_LoadingKeepAlive\n" /* line 1165 */
        "movl 0x195f290, %ebx\n" /* line 1170 | savepersist */
        "movl (%ebx), %eax\n" /* savepersist */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf14ddb8_0014de37\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf14ddb8_0014de19:\n"
        "movl 0xc(%esi), %eax\n" /* line 1172 | restart */
        "movl $0, 0x20c44(%eax, %edx)\n"
        "addl $1, %ecx\n" /* line 1170 */
        "addl $0x78f0c, %edx\n"
        "movl (%ebx), %eax\n" /* savepersist */
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf14ddb8_0014de19\n"
        ".Lf14ddb8_0014de37:\n"
        "movl 0x195ec98, %eax\n" /* line 1175 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf14ddb8_0014de51\n"
        "movl $4, (%esp)\n" /* line 1176 */
        "calll Com_DvarDump\n"
        /* } scope */
        ".Lf14ddb8_0014de51:\n"
        "addl $0x10, %esp\n" /* line 1177 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1187 */
__attribute__((naked))
long unsigned int SV_RestartGameProgs(qboolean savepersist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1187 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* savepersist */
        "movl $0, (%esp)\n" /* line 1193 */
        "calll G_ShutdownGame\n"
        "movl 0x195f56c, %eax\n" /* line 1195 */
        "movl $0, (%eax)\n"
        "movl %ebx, %edx\n" /* line 1197 | savepersist */
        "movl $1, %eax\n"
        "addl $0x14, %esp\n" /* line 1198 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SV_InitGameVM\n" /* line 1197 */
    );
}

/* line 1208 */
__attribute__((naked))
long unsigned int SV_InitGameProgs(qboolean savepersist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1208 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* savepersist */
        "movl $1, gameInitialized\n" /* line 1210 */
        "xorl %eax, %eax\n" /* line 1212 */
        "popl %ebp\n" /* line 1213 */
        "jmp SV_InitGameVM\n" /* line 1212 */
    );
}

/* line 1223 */
__attribute__((naked))
qboolean SV_GameCommand(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1223 */
        "movl %esp, %ebp\n"
        "movl 0x195ee80, %eax\n" /* line 1225 */
        "cmpl $2, (%eax)\n"
        "je .Lf14dea2_0014deb3\n"
        "xorl %eax, %eax\n" /* line 1231 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14dea2_0014deb3:\n"
        "popl %ebp\n"
        "jmp ConsoleCommand\n" /* line 1230 */
    );
}

/* line 165 */
__attribute__((naked))
long unsigned int SV_SetBrushModel(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 165 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1 */
        "leal -0x20(%ebp), %eax\n" /* line 171 | maxs */
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* mins */
        "movl %eax, 4(%esp)\n"
        "movl 0x8c(%ebx), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll CM_ModelBounds\n"
        "leal 0x104(%ebx), %edx\n" /* line 172 | ent, to */
        /* { scope 2 */
        "movl -0x14(%ebp), %eax\n" /* line 199 | mins */
        "movl %eax, 0x104(%ebx)\n" /* ent */
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x110(%ebx), %edx\n" /* line 173 | ent, to */
        /* { scope 2 */
        "movl -0x20(%ebp), %eax\n" /* line 199 | maxs */
        "movl %eax, 0x110(%ebx)\n" /* ent */
        "movl -0x1c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x18(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movb $1, 0xf1(%ebx)\n" /* line 174 | ent */
        "movl $0xffffffff, 0x11c(%ebx)\n" /* line 176 | ent */
        "movl %ebx, (%esp)\n" /* line 178 | ent */
        "calll SV_LinkEntity\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 179 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 268 */
__attribute__((naked))
qboolean SV_EntityContact(const vec_t *mins, const vec_t *maxs, const gentity_t *gEnt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 268 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %edi\n" /* mins */
        "movl 0xc(%ebp), %esi\n" /* maxs */
        "movl 0x10(%ebp), %ebx\n" /* gEnt */
        /* { scope 1 */
        "movzbl 0xf2(%ebx), %eax\n" /* line 276 | gEnt */
        "testb $0x60, %al\n"
        "je .Lf14df36_0014e012\n"
        "testb $0x20, %al\n" /* line 278 */
        "je .Lf14df36_0014df8f\n"
        "movss 0x140(%ebx), %xmm1\n" /* line 281 | gEnt */
        "ucomiss 8(%esi), %xmm1\n" /* maxs */
        "jae .Lf14df36_0014df82\n"
        "addss 0x118(%ebx), %xmm1\n" /* line 283 | gEnt */
        "movss 8(%edi), %xmm0\n" /* mins */
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf14df36_0014e069\n"
        ".Lf14df36_0014df82:\n"
        "xorl %eax, %eax\n" /* line 306 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 307 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14df36_0014df8f:\n"
        "movss (%edi), %xmm0\n" /* line 58 */
        "addss (%esi), %xmm0\n"
        "movss 4(%edi), %xmm1\n" /* line 59 */
        "addss 4(%esi), %xmm1\n"
        "movss 0x2ed5d8, %xmm2\n" /* line 86 | 0.5f */
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* center */
        "mulss %xmm2, %xmm1\n" /* line 87 */
        "movss %xmm1, -0x1c(%ebp)\n"
        "movss (%esi), %xmm0\n" /* line 296 | maxs */
        "subss -0x20(%ebp), %xmm0\n" /* center */
        "addss 0x110(%ebx), %xmm0\n" /* gEnt */
        "subss 0x2ed78c, %xmm0\n" /* 64.0f */
        "leal -0x20(%ebp), %eax\n" /* line 298 | center */
        "movl %eax, 4(%esp)\n"
        "leal 0x138(%ebx), %eax\n" /* gEnt */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "calll Vec2DistanceSq\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x68(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm0, %xmm1\n"
        "setae %al\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 307 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14df36_0014e012:\n"
        "movl %ebx, (%esp)\n" /* line 303 | gEnt */
        "calll SV_ClipHandleForEntity\n"
        "leal 0x144(%ebx), %edx\n" /* line 304 | gEnt */
        "movl %edx, 0x20(%esp)\n"
        "leal 0x138(%ebx), %edx\n" /* gEnt */
        "movl %edx, 0x1c(%esp)\n"
        "movl $0xffffffff, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* maxs */
        "movl %edi, 0xc(%esp)\n" /* mins */
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x44(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll CM_TransformedBoxTraceExternal\n"
        "movzbl -0x21(%ebp), %eax\n" /* line 306 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 307 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14df36_0014e069:\n"
        "movss (%edi), %xmm0\n" /* line 58 */
        "addss (%esi), %xmm0\n"
        "movss 4(%edi), %xmm1\n" /* line 59 */
        "addss 4(%esi), %xmm1\n"
        "movss 0x2ed5d8, %xmm2\n" /* line 86 | 0.5f */
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* center */
        "mulss %xmm2, %xmm1\n" /* line 87 */
        "movss %xmm1, -0x1c(%ebp)\n"
        "movss (%esi), %xmm0\n" /* line 287 | maxs */
        "subss -0x20(%ebp), %xmm0\n" /* center */
        "addss 0x110(%ebx), %xmm0\n" /* gEnt */
        "leal -0x20(%ebp), %eax\n" /* line 289 | center */
        "movl %eax, 4(%esp)\n"
        "leal 0x138(%ebx), %eax\n" /* gEnt */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "calll Vec2DistanceSq\n"
        "fstps -0x50(%ebp)\n"
        "movss -0x68(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "xorl %eax, %eax\n"
        "ucomiss -0x50(%ebp), %xmm0\n"
        "seta %al\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 307 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
gentity_t * SV_GEntityForSvEntity(gentity_s (*svEnt)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* svEnt */
        "movl 0x195ee80, %eax\n" /* line 110 */
        "addl $0x2418, %eax\n"
        "movl 0x195ee80, %ebx\n"
        "subl %eax, %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0xa, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "imull 0x5f420(%ebx), %eax\n"
        "addl 0x5f41c(%ebx), %eax\n"
        "popl %ebx\n" /* line 112 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 845 */
__attribute__((naked))
long unsigned int SV_XModelDebugBoxes(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 845 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30c, %esp\n"
        /* { scope 1: xx, yy, zw */
        "movl 8(%ebp), %edx\n" /* line 867 | ent */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %eax, -0x2d4(%ebp)\n" /* obj */
        "movl %eax, (%esp)\n" /* line 870 */
        "calll DObjNumBones\n"
        "leal -0x2ac(%ebp), %eax\n" /* line 872 | boneInfoArray */
        "movl %eax, 4(%esp)\n"
        "movl -0x2d4(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjGetBoneInfo\n"
        "movl -0x2d4(%ebp), %edx\n" /* line 873 | obj */
        "movl %edx, (%esp)\n"
        "calll DObjGetRotTransArray\n"
        "movl %eax, -0x2d8(%ebp)\n" /* boneMatrix */
        "movl $0x3f800000, %ebx\n" /* line 875 | boneInfo */
        "movl %ebx, -0x58(%ebp)\n" /* boneInfo, color */
        "movl %ebx, -0x54(%ebp)\n" /* line 876 | boneInfo */
        "movl %ebx, -0x50(%ebp)\n" /* line 877 | boneInfo */
        "movl $0, -0x4c(%ebp)\n" /* line 878 */
        "leal -0x7c(%ebp), %eax\n" /* line 880 | axis */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "addl $0x144, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl -0x2d4(%ebp), %edx\n" /* line 882 | obj */
        "movl %edx, (%esp)\n"
        "calll DObjGetNumModels\n"
        "movl %eax, -0x2d0(%ebp)\n" /* modelCount */
        "testl %eax, %eax\n" /* line 884 */
        "jg .Lf14e12c_0014e1ce\n"
        /* } scope */
        ".Lf14e12c_0014e1c3:\n"
        "addl $0x30c, %esp\n" /* line 920 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xx, yy, zw */
        ".Lf14e12c_0014e1ce:\n"
        "movl $0, -0x2cc(%ebp)\n" /* line 884 | modelIndex */
        "movl -0x2cc(%ebp), %eax\n" /* modelIndex */
        "jmp .Lf14e12c_0014e1f5\n"
        ".Lf14e12c_0014e1e0:\n"
        "addl $1, -0x2cc(%ebp)\n" /* modelIndex */
        "movl -0x2cc(%ebp), %eax\n" /* modelIndex */
        "cmpl %eax, -0x2d0(%ebp)\n" /* modelCount */
        "je .Lf14e12c_0014e1c3\n"
        ".Lf14e12c_0014e1f5:\n"
        "movl %eax, 4(%esp)\n" /* line 886 */
        "movl -0x2d4(%ebp), %edx\n" /* obj */
        "movl %edx, (%esp)\n"
        "calll DObjIgnoreCollision\n"
        "testb %al, %al\n"
        "jne .Lf14e12c_0014e1e0\n"
        "movl -0x2cc(%ebp), %eax\n" /* line 888 | modelIndex */
        "movl %eax, 4(%esp)\n"
        "movl -0x2d4(%ebp), %edx\n" /* obj */
        "movl %edx, (%esp)\n"
        "calll DObjGetModel\n"
        "movl %eax, (%esp)\n"
        "calll XModelNumBones\n"
        "movl %eax, -0x2c8(%ebp)\n" /* size */
        "testl %eax, %eax\n" /* line 889 */
        "jle .Lf14e12c_0014e1e0\n"
        "movl $0, -0x2c4(%ebp)\n" /* localBoneIndex */
        "movl -0x2d8(%ebp), %eax\n" /* boneMatrix */
        "addl $0x10, %eax\n"
        "movl %eax, -0x2dc(%ebp)\n"
        "movl -0x2c4(%ebp), %edx\n" /* localBoneIndex */
        ".Lf14e12c_0014e254:\n"
        "movl -0x2ac(%ebp, %edx, 4), %ebx\n" /* line 891 | boneInfo */
        /* { scope 2 */
        "movss 0xc(%eax), %xmm1\n" /* line 306 | scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "mulss -0x10(%eax), %xmm3\n"
        "movaps %xmm1, %xmm5\n" /* line 273 */
        "mulss -0xc(%eax), %xmm5\n"
        "mulss -8(%eax), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 308 */
        "mulss -0x10(%eax), %xmm0\n"
        "movss %xmm0, -0x2c0(%ebp)\n" /* xx */
        "movss -0xc(%eax), %xmm6\n" /* line 309 */
        "movaps %xmm3, %xmm4\n"
        "mulss %xmm6, %xmm4\n"
        "movss -8(%eax), %xmm2\n" /* line 310 */
        "movaps %xmm3, %xmm7\n"
        "mulss %xmm2, %xmm7\n"
        "movss -4(%eax), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm5, %xmm6\n" /* line 313 */
        "movss %xmm6, -0x2bc(%ebp)\n" /* yy */
        "movaps %xmm5, %xmm6\n" /* line 314 */
        "mulss %xmm2, %xmm6\n"
        "mulss %xmm0, %xmm5\n" /* line 315 */
        "mulss %xmm1, %xmm2\n" /* line 317 */
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss %xmm1, -0x2ec(%ebp)\n" /* zw */
        "movss -0x2bc(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0xac(%ebp)\n" /* boneAxis */
        "movss -0x2ec(%ebp), %xmm0\n" /* line 321 | zw */
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n"
        "movaps %xmm7, %xmm0\n" /* line 322 */
        "subss %xmm5, %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n"
        "subss -0x2ec(%ebp), %xmm4\n" /* line 324 | zw */
        "movss %xmm4, -0xa0(%ebp)\n"
        "addss -0x2c0(%ebp), %xmm2\n" /* line 325 | xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 326 */
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "addss %xmm5, %xmm7\n" /* line 328 */
        "movss %xmm7, -0x94(%ebp)\n"
        "subss %xmm3, %xmm6\n" /* line 329 */
        "movss %xmm6, -0x90(%ebp)\n"
        "movss -0x2c0(%ebp), %xmm0\n" /* line 330 | xx */
        "addss -0x2bc(%ebp), %xmm0\n" /* yy */
        "movss %xmm0, -0x2c0(%ebp)\n" /* xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x2c0(%ebp), %xmm0\n" /* xx */
        "movss %xmm0, -0x8c(%ebp)\n"
        /* } scope */
        "movl %eax, %edx\n" /* line 199 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x88(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x84(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x80(%ebp)\n"
        "movl $0x311c4c, %edi\n" /* line 845 */
        "movl $boxVerts, %esi\n"
        ".Lf14e12c_0014e3b6:\n"
        "movl (%esi), %eax\n" /* line 899 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl (%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x24(%ebp)\n" /* org */
        "movl 4(%esi), %eax\n" /* line 900 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 4(%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 901 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 8(%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 902 | vec */
        "movl %eax, 8(%esp)\n"
        "leal -0xac(%ebp), %edx\n" /* boneAxis */
        "movl %edx, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "leal -0x3c(%ebp), %edx\n" /* line 903 | start */
        "movl %edx, 8(%esp)\n"
        "leal -0x7c(%ebp), %eax\n" /* axis */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* vec */
        "movl %edx, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 240 | start */
        "movl 8(%ebp), %eax\n" /* ent */
        "addss 0x138(%eax), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* start */
        "movss -0x38(%ebp), %xmm0\n" /* line 241 */
        "addss 0x13c(%eax), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 242 */
        "addss 0x140(%eax), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl (%edi), %eax\n" /* line 907 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl (%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x24(%ebp)\n" /* org */
        "movl 4(%edi), %eax\n" /* line 908 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 4(%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 909 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 8(%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x30(%ebp), %edx\n" /* line 910 | vec */
        "movl %edx, 8(%esp)\n"
        "leal -0xac(%ebp), %eax\n" /* boneAxis */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* org */
        "movl %edx, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "leal -0x48(%ebp), %eax\n" /* line 911 | end */
        "movl %eax, 8(%esp)\n"
        "leal -0x7c(%ebp), %edx\n" /* axis */
        "movl %edx, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vec */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movss -0x48(%ebp), %xmm0\n" /* line 240 | end */
        "movl 8(%ebp), %edx\n" /* ent */
        "addss 0x138(%edx), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* end */
        "movss -0x44(%ebp), %xmm0\n" /* line 241 */
        "addss 0x13c(%edx), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 242 */
        "addss 0x140(%edx), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movl $1, 0x14(%esp)\n" /* line 915 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* color */
        "movl %eax, 8(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* end */
        "movl %edx, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* start */
        "movl %eax, (%esp)\n"
        "calll CL_AddDebugLine\n"
        "addl $0x18, %esi\n"
        "addl $0x18, %edi\n"
        "cmpl $serverStatusDvars, %esi\n" /* line 897 */
        "jne .Lf14e12c_0014e3b6\n"
        "addl $1, -0x2c4(%ebp)\n" /* line 889 | localBoneIndex */
        "addl $0x20, -0x2d8(%ebp)\n" /* boneMatrix */
        "addl $0x20, -0x2dc(%ebp)\n"
        "movl -0x2c4(%ebp), %edx\n" /* localBoneIndex */
        "cmpl %edx, -0x2c8(%ebp)\n" /* size */
        "je .Lf14e12c_0014e1e0\n"
        "movl -0x2dc(%ebp), %eax\n"
        "jmp .Lf14e12c_0014e254\n"
    );
}

/* line 1077 */
__attribute__((naked))
long unsigned int SV_ShutdownGameProgs(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1077 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195ee80, %eax\n" /* line 1083 */
        "movl $0, (%eax)\n"
        "movl $2, (%esp)\n" /* line 1086 */
        "calll Com_UnloadSoundAliases\n"
        "movl gameInitialized, %eax\n" /* line 1089 */
        "testl %eax, %eax\n"
        "jne .Lf14e554_0014e57c\n"
        "leave\n" /* line 1097 */
        "retl\n"
        ".Lf14e554_0014e57c:\n"
        "movl $1, (%esp)\n" /* line 1092 */
        "calll G_ShutdownGame\n"
        "movl $1, (%esp)\n" /* line 983 */
        "calll Com_FreeWeaponInfoMemory\n"
        "movl $0, gameInitialized\n" /* line 1096 */
        "leave\n" /* line 1097 */
        "retl\n"
    );
}

/* line 189 */
__attribute__((naked))
qboolean SV_inSnapshot(const vec_t *origin, int iEntityNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* iEntityNum */
        /* { scope 1 */
        "movl 0x195ee80, %ecx\n" /* line 80 */
        "imull 0x5f420(%ecx), %ebx\n"
        "addl 0x5f41c(%ecx), %ebx\n"
        "cmpb $0, 0xf0(%ebx)\n" /* line 202 | ent */
        "je .Lf14e5a0_0014e6f8\n"
        "movl 0x100(%ebx), %esi\n" /* line 205 | ent, i */
        "testl %esi, %esi\n" /* i */
        "jne .Lf14e5a0_0014e702\n"
        "movzbl 0xf2(%ebx), %eax\n" /* line 208 | ent */
        "testb $1, %al\n"
        "jne .Lf14e5a0_0014e6f8\n"
        "testb $0x18, %al\n" /* line 211 */
        "jne .Lf14e5a0_0014e702\n"
        "testl %ebx, %ebx\n" /* line 98 */
        "je .Lf14e5a0_0014e602\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf14e5a0_0014e602\n"
        "cmpl $0x3ff, %eax\n"
        "jle .Lf14e5a0_0014e61e\n"
        ".Lf14e5a0_0014e602:\n"
        "movl $0x2a99e4, 4(%esp)\n" /* line 100 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x195ee80, %ecx\n"
        "movl (%ebx), %eax\n"
        ".Lf14e5a0_0014e61e:\n"
        "leal (%eax, %eax, 2), %edx\n" /* line 102 */
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x2418(%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* svEnt */
        "movl 8(%ebp), %eax\n" /* line 216 | origin */
        "movl %eax, (%esp)\n"
        "calll CM_PointLeafnum\n"
        "movl -0x28(%ebp), %edx\n" /* line 218 | svEnt */
        "movl 0x118(%edx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf14e5a0_0014e6f8\n"
        "movl %eax, (%esp)\n" /* line 221 */
        "calll CM_LeafCluster\n"
        "movl %eax, (%esp)\n" /* line 222 */
        "calll CM_ClusterPVS\n"
        "movl %eax, -0x24(%ebp)\n" /* clientpvs */
        "movl -0x28(%ebp), %ecx\n" /* line 228 | svEnt */
        "movl 0x118(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "testl %ecx, %ecx\n"
        "jg .Lf14e5a0_0014e70f\n"
        "movl -0x1c(%ebp), %eax\n" /* line 237 */
        "testl %eax, %eax\n"
        "jne .Lf14e5a0_0014e6b1\n"
        "xorl %edx, %edx\n"
        ".Lf14e5a0_0014e67e:\n"
        "movl -0x28(%ebp), %eax\n" /* line 239 | svEnt */
        "movl 0x15c(%eax), %esi\n" /* i */
        "testl %esi, %esi\n" /* i */
        "je .Lf14e5a0_0014e6f8\n"
        "cmpl %edx, %esi\n" /* line 241 | i */
        "jl .Lf14e5a0_0014e6ad\n"
        ".Lf14e5a0_0014e68f:\n"
        "movl %edx, %eax\n" /* line 243 */
        "sarl $3, %eax\n"
        "movl -0x24(%ebp), %ecx\n" /* clientpvs */
        "movzbl (%ecx, %eax), %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf14e5a0_0014e6ad\n"
        "addl $1, %edx\n" /* line 241 */
        "cmpl %edx, %esi\n" /* i */
        "jge .Lf14e5a0_0014e68f\n"
        ".Lf14e5a0_0014e6ad:\n"
        "cmpl %edx, %esi\n" /* line 246 | i */
        "je .Lf14e5a0_0014e6f8\n"
        ".Lf14e5a0_0014e6b1:\n"
        "calll G_GetFogOpaqueDistSqrd\n" /* line 255 */
        "fstps -0x20(%ebp)\n" /* fogOpaqueDistSqrd */
        "movss -0x20(%ebp), %xmm0\n" /* line 256 | fogOpaqueDistSqrd */
        "ucomiss 0x2ed684, %xmm0\n" /* 3.4028234663852886e+38f */
        "jp .Lf14e5a0_0014e6c9\n"
        "je .Lf14e5a0_0014e702\n"
        ".Lf14e5a0_0014e6c9:\n"
        "movss %xmm0, 0xc(%esp)\n" /* line 259 */
        "movl 8(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "leal 0x12c(%ebx), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "leal 0x120(%ebx), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BoxDistSqrdExceeds\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf14e5a0_0014e6fa\n"
        ".Lf14e5a0_0014e6f8:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf14e5a0_0014e6fa:\n"
        "addl $0x2c, %esp\n" /* line 260 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14e5a0_0014e702:\n"
        "movl $1, %eax\n" /* line 259 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 260 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14e5a0_0014e70f:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 230 | svEnt */
        "movl 0x11c(%ecx), %edx\n"
        "movl %edx, %eax\n" /* line 231 */
        "sarl $3, %eax\n"
        "movl -0x24(%ebp), %ecx\n" /* clientpvs */
        "movzbl (%ecx, %eax), %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf14e5a0_0014e6b1\n"
        "movl -0x28(%ebp), %edi\n" /* line 232 | svEnt */
        "xorl %esi, %esi\n" /* i */
        ".Lf14e5a0_0014e734:\n"
        "addl $1, %esi\n" /* line 228 | i */
        "cmpl -0x1c(%ebp), %esi\n" /* i */
        "je .Lf14e5a0_0014e67e\n"
        "movl 0x120(%edi), %edx\n" /* line 230 */
        "addl $4, %edi\n"
        "movl %edx, %eax\n" /* line 231 */
        "sarl $3, %eax\n"
        "movl -0x24(%ebp), %ecx\n" /* clientpvs */
        "movzbl (%ecx, %eax), %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf14e5a0_0014e734\n"
        "jmp .Lf14e5a0_0014e6b1\n"
    );
}

/* line 569 */
__attribute__((naked))
qboolean SV_DObjCreateSkelForBone(gentity_t *ent, int boneIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 569 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* boneIndex */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 575 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %eax, -0x1c(%ebp)\n" /* obj */
        "movl 0x195ee80, %edi\n" /* line 578 */
        "movl 0x5f430(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjSkelExists\n"
        "testl %eax, %eax\n"
        "je .Lf14e766_0014e7b6\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 579 | boneIndex */
        "movl -0x1c(%ebp), %eax\n" /* obj */
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 586 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjSkelIsBoneUpToDate\n" /* line 579 */
        ".Lf14e766_0014e7b6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 581 | obj */
        "movl %eax, (%esp)\n"
        "calll DObjGetAllocSkelSize\n"
        "leal 0xf(%eax), %ebx\n" /* line 536 */
        "andl $0xfffffff0, %ebx\n"
        "movl 0x5f434(%edi), %eax\n" /* line 543 */
        "movl %eax, %esi\n"
        "addl g_sv_skel_memory_start, %esi\n"
        "leal (%ebx, %eax), %eax\n" /* line 544 */
        "movl %eax, 0x5f434(%edi)\n"
        "cmpl $0x3fff0, %eax\n" /* line 545 */
        "jbe .Lf14e766_0014e88c\n"
        "movl $0xe8700f, %esi\n" /* line 585 | buf */
        "andl $0xfffffff0, %esi\n" /* buf */
        "cmpl $0x3fff0, %ebx\n" /* boneIndex */
        "jbe .Lf14e766_0014e847\n"
        "movl %edi, %edx\n"
        ".Lf14e766_0014e7fb:\n"
        "movl 0x5f430(%edx), %eax\n" /* line 551 */
        "cmpl warnCount, %eax\n"
        "je .Lf14e766_0014e81c\n"
        "movl %eax, warnCount\n" /* line 553 */
        "movl $0x2a9a8c, (%esp)\n" /* line 554 */
        "calll Com_Printf\n"
        "movl %edi, %edx\n"
        ".Lf14e766_0014e81c:\n"
        "movl 0x5f430(%edx), %eax\n" /* line 514 */
        "addl $1, %eax\n"
        "movl %eax, 0x5f430(%edx)\n"
        "testl %eax, %eax\n" /* line 515 */
        "jne .Lf14e766_0014e839\n"
        "movl $1, 0x5f430(%edx)\n" /* line 516 */
        ".Lf14e766_0014e839:\n"
        "movl %esi, g_sv_skel_memory_start\n" /* line 518 */
        "movl %ebx, 0x5f434(%edx)\n" /* line 544 */
        "jmp .Lf14e766_0014e7fb\n"
        ".Lf14e766_0014e847:\n"
        "movl 0x5f430(%edi), %edx\n" /* line 551 */
        "cmpl warnCount, %edx\n"
        "je .Lf14e766_0014e86d\n"
        "movl %edx, warnCount\n" /* line 553 */
        "movl $0x2a9a8c, (%esp)\n" /* line 554 */
        "calll Com_Printf\n"
        "movl 0x5f430(%edi), %edx\n"
        ".Lf14e766_0014e86d:\n"
        "addl $1, %edx\n" /* line 514 */
        "movl $1, %eax\n" /* line 516 */
        "testl %edx, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, 0x5f430(%edi)\n"
        "movl %esi, g_sv_skel_memory_start\n" /* line 518 */
        "movl %ebx, 0x5f434(%edi)\n" /* line 544 */
        ".Lf14e766_0014e88c:\n"
        "movl 0x195ee80, %eax\n" /* line 584 */
        "movl 0x5f430(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* buf */
        "movl -0x1c(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjCreateSkel\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 586 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 596 */
__attribute__((naked))
qboolean SV_DObjCreateSkelForBones(gentity_t *ent, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 596 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* partBits */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 602 | ent */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %eax, -0x1c(%ebp)\n" /* obj */
        "movl 0x195ee80, %edi\n" /* line 605 */
        "movl 0x5f430(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjSkelExists\n"
        "testl %eax, %eax\n"
        "je .Lf14e8b4_0014e904\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 606 | partBits */
        "movl -0x1c(%ebp), %eax\n" /* obj */
        "movl %eax, 8(%ebp)\n" /* ent */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 613 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjSkelAreBonesUpToDate\n" /* line 606 */
        ".Lf14e8b4_0014e904:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 608 | obj */
        "movl %eax, (%esp)\n"
        "calll DObjGetAllocSkelSize\n"
        "leal 0xf(%eax), %ebx\n" /* line 536 */
        "andl $0xfffffff0, %ebx\n"
        "movl 0x5f434(%edi), %eax\n" /* line 543 */
        "movl %eax, %esi\n"
        "addl g_sv_skel_memory_start, %esi\n"
        "leal (%ebx, %eax), %eax\n" /* line 544 */
        "movl %eax, 0x5f434(%edi)\n"
        "cmpl $0x3fff0, %eax\n" /* line 545 */
        "jbe .Lf14e8b4_0014e9da\n"
        "movl $0xe8700f, %esi\n" /* line 612 | buf */
        "andl $0xfffffff0, %esi\n" /* buf */
        "cmpl $0x3fff0, %ebx\n" /* partBits */
        "jbe .Lf14e8b4_0014e995\n"
        "movl %edi, %edx\n"
        ".Lf14e8b4_0014e949:\n"
        "movl 0x5f430(%edx), %eax\n" /* line 551 */
        "cmpl warnCount, %eax\n"
        "je .Lf14e8b4_0014e96a\n"
        "movl %eax, warnCount\n" /* line 553 */
        "movl $0x2a9a8c, (%esp)\n" /* line 554 */
        "calll Com_Printf\n"
        "movl %edi, %edx\n"
        ".Lf14e8b4_0014e96a:\n"
        "movl 0x5f430(%edx), %eax\n" /* line 514 */
        "addl $1, %eax\n"
        "movl %eax, 0x5f430(%edx)\n"
        "testl %eax, %eax\n" /* line 515 */
        "jne .Lf14e8b4_0014e987\n"
        "movl $1, 0x5f430(%edx)\n" /* line 516 */
        ".Lf14e8b4_0014e987:\n"
        "movl %esi, g_sv_skel_memory_start\n" /* line 518 */
        "movl %ebx, 0x5f434(%edx)\n" /* line 544 */
        "jmp .Lf14e8b4_0014e949\n"
        ".Lf14e8b4_0014e995:\n"
        "movl 0x5f430(%edi), %edx\n" /* line 551 */
        "cmpl warnCount, %edx\n"
        "je .Lf14e8b4_0014e9bb\n"
        "movl %edx, warnCount\n" /* line 553 */
        "movl $0x2a9a8c, (%esp)\n" /* line 554 */
        "calll Com_Printf\n"
        "movl 0x5f430(%edi), %edx\n"
        ".Lf14e8b4_0014e9bb:\n"
        "addl $1, %edx\n" /* line 514 */
        "movl $1, %eax\n" /* line 516 */
        "testl %edx, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, 0x5f430(%edi)\n"
        "movl %esi, g_sv_skel_memory_start\n" /* line 518 */
        "movl %ebx, 0x5f434(%edi)\n" /* line 544 */
        ".Lf14e8b4_0014e9da:\n"
        "movl 0x195ee80, %eax\n" /* line 611 */
        "movl 0x5f430(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* buf */
        "movl -0x1c(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjCreateSkel\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 613 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

