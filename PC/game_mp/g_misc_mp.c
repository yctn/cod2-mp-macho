/* ASM dump from: g_misc_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_misc_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/universal/q_shared.h"
 */

extern void G_FreeEntity(gentity_t *ent);
extern void G_SetOrigin(gentity_t *ent, const vec_t *origin);
extern qboolean G_SpawnString(const char *key, const char *defaultString, const char **out);
extern void Com_Error(int code, const char *fmt, ...);
extern DObj_s * Com_GetServerDObj(int entNum);
extern void DObjSetControlTagAngles(DObj_s *obj, int *partBits, unsigned short tag, vec_t *angles);
extern void SV_UnlinkEntity(gentity_t *ent);
extern void SV_LinkEntity(gentity_t *ent);
extern void SetClientViewAngle(gentity_t *ent, vec_t *angles);
extern void BG_PlayerStateToEntityState(playerState_t *ps, gentity_t *ent, qboolean snap, qboolean forceSnap);
extern void G_AddEvent(gentity_t *ent, int event, int eventParm);

static turretInfo_t turretInfo[32]; /* turretInfo */

void SP_info_null(gentity_t *self);
void SP_info_notnull(gentity_t *self);
void SP_light(gentity_t *self);
void SP_misc_model(gentity_t *ent);
void SP_corona(gentity_t *ent);
void G_InitTurrets(void);
void turret_think(gentity_t *self);
void turret_controller(gentity_t *self, int *partBits);
void TeleportPlayer(gentity_t *player, vec_t *origin, vec_t *angles);
void G_ClientStopUsingTurret(gentity_t *self);
void G_FreeTurret(gentity_t *self);
void turret_think_init(gentity_t *self);
qboolean G_IsTurretUsable(gentity_t *self, gentity_t *owner);
void turret_use(gentity_t *self, gentity_t *owner, gentity_t *activator);
void G_SpawnTurret(gentity_t *self, const char *weaponinfoname);
void SP_turret(gentity_t *self);
void turret_think_client(gentity_t *self);

/* line 17 */
void SP_info_null(gentity_t *self)
{
    G_FreeEntity(self);
}

/* line 23 */
void SP_info_notnull(gentity_t *self)
{
    G_SetOrigin(self, (vec_t *)((byte *)self + 0x138));
}

/* line 29 */
void SP_light(gentity_t *self)
{
    G_FreeEntity(self);
}

/* line 77 */
void SP_misc_model(gentity_t *ent)
{
    G_FreeEntity(ent);
}

/* line 108 */
void SP_corona(gentity_t *ent)
{
    G_FreeEntity(ent);
}

/* line 119 */
void G_InitTurrets(void)
{
    int i;
    for (i = 0; i < 32; i++)
        *(int *)&turretInfo[i] = 0;
}

/* line 724 */
__attribute__((naked))
void turret_think(gentity_t *self)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 724 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* self */
        "movl imp_level, %eax\n" /* line 732 */
        "movl 0x1ec(%eax), %eax\n"
        "addl $0x32, %eax\n"
        "movl %eax, 0x190(%esi)\n" /* self */
        "movl 0x208(%esi), %ecx\n" /* line 734 | self */
        "testl %ecx, %ecx\n"
        "je .Lf1b9b0a_001b9b3c\n"
        "movl %esi, (%esp)\n" /* line 735 | self */
        "calll G_GeneralLink\n"
        ".Lf1b9b0a_001b9b3c:\n"
        "movl 0x150(%esi), %eax\n" /* line 739 | self */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "movl 0x158(%eax, %edx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1b9b0a_001b9b69\n"
        "addl $0x5c, %esp\n" /* line 747 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b9b0a_001b9b69:\n"
        "movl 0x15c(%esi), %edi\n" /* line 503 */
        "movl $0, 0x84(%esi)\n" /* line 506 */
        "movl 0x28(%edi), %eax\n" /* line 507 */
        "testl %eax, %eax\n"
        "jle .Lf1b9b0a_001b9ba1\n"
        "movzbl 0x40(%edi), %eax\n" /* line 509 */
        "movl %eax, 0x84(%esi)\n"
        "movl 0x28(%edi), %eax\n" /* line 511 */
        "subl $0x32, %eax\n"
        "movl %eax, 0x28(%edi)\n"
        "testl %eax, %eax\n" /* line 513 */
        "jle .Lf1b9b0a_001b9cf0\n"
        ".Lf1b9b0a_001b9b9b:\n"
        "movl 0x15c(%esi), %edi\n"
        ".Lf1b9b0a_001b9ba1:\n"
        "andl $0xffffffbf, 8(%esi)\n" /* line 744 | self */
        /* { scope 1: fSpeed, pitch */
        "movl 0x1c(%edi), %eax\n" /* line 711 */
        "movl %eax, -0x20(%ebp)\n" /* desiredAngles */
        "movl $0, -0x1c(%ebp)\n" /* line 712 */
        /* { scope 2 */
        "movss 0x68(%esi), %xmm0\n" /* line 621 */
        "movss %xmm0, -0x34(%ebp)\n" /* pitch */
        "addss 0x70(%esi), %xmm0\n" /* line 622 */
        "movss %xmm0, 0x68(%esi)\n"
        "movl $0x43480000, %eax\n" /* line 631 */
        "movl %eax, -0x28(%ebp)\n" /* fSpeed */
        "movl %eax, -0x24(%ebp)\n" /* line 632 */
        "movl 4(%edi), %eax\n" /* line 635 */
        "testb $2, %ah\n"
        "jne .Lf1b9b0a_001b9ccb\n"
        ".Lf1b9b0a_001b9bdd:\n"
        "movl %esi, %ebx\n" /* line 636 */
        "movl $1, -0x30(%ebp)\n"
        ".Lf1b9b0a_001b9be6:\n"
        "movl -0x30(%ebp), %edx\n" /* line 724 */
        "shll $2, %edx\n"
        "leal -0x28(%ebp), %eax\n" /* fSpeed */
        "addl %edx, %eax\n"
        "movss -4(%eax), %xmm0\n" /* line 640 */
        "mulss lit4_002ed72c, %xmm0\n" /* 0.05000000074505806f */
        "movss %xmm0, -4(%eax)\n"
        "movl 0x68(%ebx), %eax\n" /* line 642 */
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "calll AngleSubtract\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x48(%ebp), %xmm0\n" /* line 643 */
        "movss -0x2c(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1b9b0a_001b9c38\n"
        "xorps sign+320, %xmm0\n" /* line 648 */
        "maxss %xmm1, %xmm0\n"
        ".Lf1b9b0a_001b9c38:\n"
        "addss 0x68(%ebx), %xmm0\n" /* line 653 */
        "movss %xmm0, 0x68(%ebx)\n"
        "addl $1, -0x30(%ebp)\n"
        "addl $4, %ebx\n"
        "cmpl $3, -0x30(%ebp)\n" /* line 638 */
        "jne .Lf1b9b0a_001b9be6\n"
        "movss 0x68(%esi), %xmm0\n" /* line 656 */
        "movss %xmm0, 0x70(%esi)\n" /* line 657 */
        "movl 4(%edi), %eax\n" /* line 659 */
        "testb $2, %ah\n"
        "je .Lf1b9b0a_001b9c76\n"
        "testb $4, %ah\n" /* line 661 */
        "jne .Lf1b9b0a_001b9ce0\n"
        "movss 0x3c(%edi), %xmm1\n" /* line 663 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1b9b0a_001b9ceb\n"
        ".Lf1b9b0a_001b9c70:\n"
        "andb $0xfe, %ah\n" /* line 673 */
        "movl %eax, 4(%edi)\n"
        ".Lf1b9b0a_001b9c76:\n"
        "movss -0x34(%ebp), %xmm1\n" /* line 677 | pitch */
        "movss %xmm1, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 678 | fSpeed */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1b9b0a_001b9ca8\n"
        "xorps sign+320, %xmm0\n" /* line 683 */
        "maxss %xmm1, %xmm0\n"
        ".Lf1b9b0a_001b9ca8:\n"
        "movaps %xmm0, %xmm1\n"
        "addss -0x34(%ebp), %xmm1\n" /* line 689 | pitch */
        "movss %xmm1, 0x68(%esi)\n"
        "movss 0x70(%esi), %xmm0\n" /* line 690 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x70(%esi)\n"
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 747 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fSpeed, pitch */
        /* { scope 2 */
        ".Lf1b9b0a_001b9ccb:\n"
        "testb $1, %ah\n" /* line 635 */
        "je .Lf1b9b0a_001b9bdd\n"
        "movl $0x43b40000, -0x28(%ebp)\n" /* line 636 | fSpeed */
        "jmp .Lf1b9b0a_001b9bdd\n"
        ".Lf1b9b0a_001b9ce0:\n"
        "movss 0x3c(%edi), %xmm1\n" /* line 670 */
        "ucomiss 0x68(%esi), %xmm1\n"
        "jbe .Lf1b9b0a_001b9c70\n"
        ".Lf1b9b0a_001b9ceb:\n"
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf1b9b0a_001b9c76\n"
        /* } scope */
        /* } scope */
        ".Lf1b9b0a_001b9cf0:\n"
        "cmpb $0, 0x42(%edi)\n" /* line 513 */
        "je .Lf1b9b0a_001b9b9b\n"
        "movl $0, 0x84(%esi)\n" /* line 515 */
        "movzbl 0x42(%edi), %eax\n" /* line 516 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_PlaySoundAlias\n"
        "movl 0x15c(%esi), %edi\n"
        "jmp .Lf1b9b0a_001b9ba1\n"
    );
}

/* line 809 */
void turret_controller(gentity_t *self, int *partBits)
{
    vec3_t angles;
    DObj_s *obj;
    unsigned short *tagNames = (unsigned short *)*(int *)imp_scr_const;

    angles[0] = *(float *)((byte *)self + 0x68);
    angles[1] = *(float *)((byte *)self + 0x6c);
    angles[2] = 0;

    obj = Com_GetServerDObj(*(int *)self);

    DObjSetControlTagAngles(obj, partBits, tagNames[0x9e / 2], angles);
    DObjSetControlTagAngles(obj, partBits, tagNames[0xa0 / 2], angles);

    angles[0] = *(float *)((byte *)self + 0x70);
    angles[1] = 0;

    DObjSetControlTagAngles(obj, partBits, tagNames[0x8c / 2], angles);
}

/* line 42 */
void TeleportPlayer(gentity_t *player, vec_t *origin, vec_t *angles)
{
    unsigned char linked;
    playerState_t *ps;

    linked = *(unsigned char *)((byte *)player + 0xf0);

    SV_UnlinkEntity(player);

    /* VectorCopy origin to ps->origin */
    ps = *(playerState_t **)((byte *)player + 0x158);
    *(float *)((byte *)ps + 0x14) = origin[0];
    *(float *)((byte *)ps + 0x18) = origin[1];
    *(float *)((byte *)ps + 0x1c) = origin[2];

    /* Increment origin[2] by 1.0 */
    ps = *(playerState_t **)((byte *)player + 0x158);
    *(float *)((byte *)ps + 0x1c) += 1.0f;

    /* Toggle EF_TELEPORT_BIT */
    ps = *(playerState_t **)((byte *)player + 0x158);
    *(int *)((byte *)ps + 0xa0) ^= 2;

    SetClientViewAngle(player, angles);

    BG_PlayerStateToEntityState(*(playerState_t **)((byte *)player + 0x158), player, 1, 1);

    /* VectorCopy ps->origin to currentOrigin */
    ps = *(playerState_t **)((byte *)player + 0x158);
    *(float *)((byte *)player + 0x138) = *(float *)((byte *)ps + 0x14);
    *(float *)((byte *)player + 0x13c) = *(float *)((byte *)ps + 0x18);
    *(float *)((byte *)player + 0x140) = *(float *)((byte *)ps + 0x1c);

    if (linked)
        SV_LinkEntity(player);
}

/* line 528 */
__attribute__((naked))
void G_ClientStopUsingTurret(gentity_t *self)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 528 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* self */
        /* { scope 1 */
        "movl 0x15c(%edi), %esi\n" /* line 533 | self, pTurretInfo */
        "movl 0x150(%edi), %eax\n" /* line 536 | self */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* owner */
        "subl %eax, %ebx\n" /* owner */
        "shll $4, %ebx\n" /* owner */
        "addl imp_g_entities, %ebx\n" /* owner */
        "movl $0, 0x28(%esi)\n" /* line 539 | pTurretInfo */
        "movl $0, 0x84(%edi)\n" /* line 540 | self */
        "movl 0x24(%esi), %eax\n" /* line 542 | pTurretInfo */
        "cmpl $-1, %eax\n"
        "je .Lf1b9e98_001b9f0f\n"
        "cmpl $2, %eax\n" /* line 544 */
        "je .Lf1b9e98_001b9fa3\n"
        "subl $1, %eax\n" /* line 546 */
        "je .Lf1b9e98_001b9f86\n"
        "movl $0, 8(%esp)\n" /* line 549 */
        "movl $0x8c, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* owner */
        "calll G_AddEvent\n"
        ".Lf1b9e98_001b9f08:\n"
        "movl $0xffffffff, 0x24(%esi)\n" /* line 551 | pTurretInfo */
        ".Lf1b9e98_001b9f0f:\n"
        "leal 0x144(%ebx), %eax\n" /* line 555 | owner */
        "movl %eax, 8(%esp)\n"
        "leal 0x2c(%esi), %eax\n" /* pTurretInfo */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* owner */
        "calll TeleportPlayer\n"
        "movl 0x158(%ebx), %eax\n" /* line 557 | owner */
        "andl $0xfffffcff, 0xa0(%eax)\n"
        "movl 0x158(%ebx), %eax\n" /* line 558 | owner */
        "movl $0, 0x590(%eax)\n"
        "movl 0x158(%ebx), %eax\n" /* line 559 | owner */
        "movl $0x3ff, 0x594(%eax)\n"
        "movb $0, 0x162(%ebx)\n" /* line 561 | owner */
        "movl $0, 0x74(%ebx)\n" /* line 563 | owner */
        "movb $0, 0x162(%edi)\n" /* line 565 | self */
        "movl $0x3ff, 0x150(%edi)\n" /* line 566 | self */
        "andl $0xfffff7ff, 4(%esi)\n" /* line 567 | pTurretInfo */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 568 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b9e98_001b9f86:\n"
        "movl $0, 8(%esp)\n" /* line 547 */
        "movl $0x8d, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* owner */
        "calll G_AddEvent\n"
        "jmp .Lf1b9e98_001b9f08\n"
        ".Lf1b9e98_001b9fa3:\n"
        "movl $0, 8(%esp)\n" /* line 545 */
        "movl $0x8e, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* owner */
        "calll G_AddEvent\n"
        "jmp .Lf1b9e98_001b9f08\n"
    );
}

/* line 861 */
void G_FreeTurret(gentity_t *self)
{
    int ownerNum;
    gentity_t *g_ents;

    /* Check if owner entity has a client (entity stride 560 = 0x230, field 0x158 = client) */
    ownerNum = *(int *)((byte *)self + 0x150);
    g_ents = *(gentity_t **)imp_g_entities;
    if (*(int *)((byte *)g_ents + ownerNum * 560 + 0x158))
        G_ClientStopUsingTurret(self);

    *(unsigned char *)((byte *)self + 0x162) = 0;
    **(int **)((byte *)self + 0x15c) = 0;
    *(int *)((byte *)self + 0x15c) = 0;
}

/* line 756 */
__attribute__((naked))
void turret_think_init(gentity_t *self)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 756 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10c, %esp\n"
        "movl 8(%ebp), %edi\n" /* self */
        /* { scope 1 */
        "movl 0x15c(%edi), %eax\n" /* line 759 | self */
        "movl %eax, -0xe8(%ebp)\n" /* pTurretInfo */
        "movb $0xe, 0x166(%edi)\n" /* line 769 | self */
        "movl imp_level, %eax\n" /* line 770 */
        "movl 0x1ec(%eax), %eax\n"
        "addl $0x32, %eax\n"
        "movl %eax, 0x190(%edi)\n" /* self */
        "movl imp_scr_const, %esi\n" /* line 773 | weaponMtx */
        "movzwl 0x9e(%esi), %eax\n" /* weaponMtx */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* self */
        "calll G_DObjGetLocalTagMatrix\n"
        "movl %eax, %ebx\n" /* i */
        "testl %eax, %eax\n" /* line 774 */
        "je .Lf1ba01a_001ba246\n"
        "movzwl 0xa4(%esi), %eax\n" /* line 777 | weaponMtx */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* self */
        "calll G_DObjGetLocalTagMatrix\n"
        "movl %eax, %esi\n" /* weaponMtx */
        "testl %eax, %eax\n" /* line 778 */
        "je .Lf1ba01a_001ba246\n"
        "leal -0xcc(%ebp), %edx\n" /* line 781 | baseMtx */
        "movl %edx, 4(%esp)\n"
        "leal 0x144(%edi), %eax\n" /* self */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x138(%edi), %edx\n" /* self */
        /* { scope 2 */
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, -0xa8(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xa4(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xa0(%ebp)\n"
        /* } scope */
        "leal 0x10(%ebx), %eax\n" /* line 784 | i, a */
        "movl %eax, -0xec(%ebp)\n" /* a */
        "leal 0x10(%esi), %eax\n" /* weaponMtx, a */
        /* { scope 2 */
        "movss 0x10(%esi), %xmm0\n" /* line 248 */
        "subss 0x10(%ebx), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* dir */
        "leal 0x14(%ebx), %edx\n" /* line 249 */
        "movl %edx, -0xe4(%ebp)\n"
        "movss 4(%eax), %xmm0\n"
        "subss 0x14(%ebx), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "leal 0x18(%ebx), %edx\n" /* line 250 */
        "movl %edx, -0xe0(%ebp)\n"
        "movss 8(%eax), %xmm0\n"
        "subss 0x18(%ebx), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        "leal -0x24(%ebp), %eax\n" /* line 785 | start */
        "movl %eax, 8(%esp)\n"
        "leal -0xcc(%ebp), %edx\n" /* baseMtx */
        "movl %edx, 4(%esp)\n"
        "movl -0xec(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "movl imp_bulletPriorityMap, %edx\n"
        "movl %edx, -0xdc(%ebp)\n"
        "xorl %ebx, %ebx\n" /* i */
        "leal -0x30(%ebp), %esi\n" /* end, weaponMtx */
        "jmp .Lf1ba01a_001ba155\n"
        ".Lf1ba01a_001ba149:\n"
        "addl $1, %ebx\n" /* line 787 | i */
        "cmpl $0x1f, %ebx\n" /* i */
        "je .Lf1ba01a_001ba246\n"
        ".Lf1ba01a_001ba155:\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 789 | i */
        "mulss lit4_002ed9a8, %xmm0\n" /* -3.0f */
        "movss %xmm0, -0x3c(%ebp)\n" /* angles */
        "movl $0, -0x38(%ebp)\n" /* line 790 */
        "movl $0, -0x34(%ebp)\n" /* line 791 */
        "leal -0x9c(%ebp), %eax\n" /* line 793 | mtx */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* angles */
        "movl %edx, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal -0x54(%ebp), %eax\n" /* line 794 | transDir */
        "movl %eax, 8(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* mtx */
        "movl %edx, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* dir */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movl -0xec(%ebp), %edx\n" /* line 240 */
        "movss (%edx), %xmm0\n"
        "addss -0x54(%ebp), %xmm0\n" /* transDir */
        "movss %xmm0, -0x54(%ebp)\n" /* transDir */
        "movl -0xe4(%ebp), %eax\n" /* line 241 */
        "movss (%eax), %xmm0\n"
        "addss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movl -0xe0(%ebp), %edx\n" /* line 242 */
        "movss (%edx), %xmm0\n"
        "addss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movl %esi, 8(%esp)\n" /* line 797 | weaponMtx */
        "leal -0xcc(%ebp), %eax\n" /* baseMtx */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %edx\n" /* transDir */
        "movl %edx, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "movl -0xdc(%ebp), %eax\n" /* line 799 */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x811, 0x10(%esp)\n"
        "movl (%edi), %eax\n" /* self */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* weaponMtx */
        "leal -0x24(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 800 | 1.0f */
        "ucomiss -0x78(%ebp), %xmm0\n" /* trace */
        "jbe .Lf1ba01a_001ba149\n"
        "movl -0x3c(%ebp), %eax\n" /* line 802 | angles */
        "movl -0xe8(%ebp), %edx\n" /* pTurretInfo */
        "movl %eax, 0x1c(%edx)\n"
        /* } scope */
        ".Lf1ba01a_001ba246:\n"
        "addl $0x10c, %esp\n" /* line 806 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 878 */
__attribute__((naked))
qboolean G_IsTurretUsable(gentity_t *self, gentity_t *owner)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 878 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* self */
        "movl 0xc(%ebp), %edi\n" /* owner */
        "cmpb $0, 0x162(%esi)\n" /* line 880 | self */
        "jne .Lf1ba252_001ba3d4\n"
        "movl 0x15c(%esi), %eax\n" /* self */
        "testl %eax, %eax\n"
        "je .Lf1ba252_001ba3d4\n"
        /* { scope 1 */
        "movss 0x10(%eax), %xmm2\n" /* line 840 */
        "movss sign+336, %xmm0\n" /* line 841 */
        "movaps %xmm2, %xmm1\n"
        "andps %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* yawSpan */
        "movss 0x18(%eax), %xmm1\n"
        "andps %xmm0, %xmm1\n"
        "addss -0x3c(%ebp), %xmm1\n" /* yawSpan */
        "mulss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, -0x3c(%ebp)\n" /* yawSpan */
        "addss 0x148(%esi), %xmm2\n" /* line 842 */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "calll AngleNormalize180\n"
        "movl $0, 8(%esp)\n" /* line 844 */
        "leal -0x30(%ebp), %ebx\n" /* forward */
        "movl %ebx, 4(%esp)\n"
        "fstps (%esp)\n"
        "calll YawVectors\n"
        "movl %ebx, (%esp)\n" /* line 845 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss 0x138(%esi), %xmm0\n" /* line 248 */
        "subss 0x138(%edi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movss 0x13c(%esi), %xmm0\n" /* line 249 */
        "subss 0x13c(%edi), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 848 */
        "leal -0x24(%ebp), %eax\n" /* line 849 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 304 | forward */
        "mulss -0x24(%ebp), %xmm1\n" /* dir */
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 45 | 1.0f */
        "movaps %xmm1, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm0, %xmm3\n"
        "cmpnltss %xmm4, %xmm2\n"
        "andps %xmm2, %xmm3\n"
        "andnps %xmm1, %xmm2\n"
        "orps %xmm3, %xmm2\n"
        "movss lit4_002ed5dc, %xmm3\n" /* -1.0f */
        "movaps %xmm3, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "cmpltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n" /* line 852 */
        "calll Q_acos\n"
        "fstps -0x40(%ebp)\n"
        /* } scope */
        "cvtss2sd -0x40(%ebp), %xmm0\n" /* line 883 */
        "mulsd lit8_00307c40, %xmm0\n" /* 57.29577951308232 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "ucomiss -0x3c(%ebp), %xmm0\n" /* yawSpan */
        "ja .Lf1ba252_001ba3d4\n"
        "movl 0x158(%edi), %eax\n" /* line 886 | owner */
        "movl 0x3c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1ba252_001ba3d4\n"
        "cmpl $0x3ff, 0x60(%eax)\n" /* line 889 */
        "je .Lf1ba252_001ba3d4\n"
        "movl $1, %eax\n"
        "addl $0x4c, %esp\n" /* line 893 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1ba252_001ba3d4:\n"
        "xorl %eax, %eax\n" /* line 889 */
        "addl $0x4c, %esp\n" /* line 893 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 896 */
__attribute__((naked))
void turret_use(gentity_t *self, gentity_t *owner, gentity_t *activator)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 896 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* owner */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 903 | self */
        "movl 0x15c(%eax), %esi\n" /* pTurretInfo */
        "movl 0x158(%edx), %edi\n" /* line 911 | ps */
        "movb $1, 0x162(%edx)\n" /* line 913 */
        "movb $1, 0x162(%eax)\n" /* line 915 */
        "movl (%edx), %eax\n" /* line 916 */
        "movl 8(%ebp), %ecx\n" /* self */
        "movl %eax, 0x150(%ecx)\n"
        "movl $1, 0x590(%edi)\n" /* line 918 | ps */
        "movl (%ecx), %eax\n" /* line 919 */
        "movl %eax, 0x594(%edi)\n" /* ps */
        "orl $0x800, 4(%esi)\n" /* line 921 | pTurretInfo */
        "leal 0x2c(%esi), %ebx\n" /* line 924 | pTurretInfo, to */
        "leal 0x138(%edx), %ecx\n" /* from */
        /* { scope 2 */
        "movl 0x138(%edx), %eax\n" /* line 199 */
        "movl %eax, 0x2c(%esi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 927 | self */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x74(%edx)\n"
        "movl (%edx), %eax\n" /* line 929 */
        "movl %eax, 0x74(%ecx)\n"
        "movl 0xc(%edi), %eax\n" /* line 932 | ps */
        "testb $1, %al\n"
        "je .Lf1ba3de_001ba62d\n"
        "movl $2, 0x24(%esi)\n" /* line 933 | pTurretInfo */
        "movl 0x20(%esi), %eax\n" /* line 940 | pTurretInfo */
        "cmpl $2, %eax\n"
        "je .Lf1ba3de_001ba644\n"
        ".Lf1ba3de_001ba474:\n"
        "subl $1, %eax\n" /* line 945 */
        "je .Lf1ba3de_001ba65b\n"
        "orl $0x300, 0xa0(%edi)\n" /* line 951 | ps */
        ".Lf1ba3de_001ba487:\n"
        "movl 8(%ebp), %edx\n" /* line 953 | self */
        "movl 0x144(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xe8(%edi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movl 8(%ebp), %ecx\n" /* self */
        "movss %xmm0, 0x68(%ecx)\n"
        "movss 0x14(%esi), %xmm2\n" /* line 954 | pTurretInfo */
        "movss 0xc(%esi), %xmm3\n" /* pTurretInfo */
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm2, %xmm5\n"
        "cmpnltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm5\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm5, %xmm1\n"
        /* { scope 2 */
        "movaps %xmm3, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm3, %xmm5\n"
        "cmpnltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x68(%ecx)\n" /* line 954 */
        "movl 0x148(%ecx), %eax\n" /* line 956 */
        "movl %eax, 4(%esp)\n"
        "movl 0xec(%edi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "movss %xmm4, -0x28(%ebp)\n"
        "calll AngleSubtract\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movl 8(%ebp), %eax\n" /* self */
        "movss %xmm0, 0x6c(%eax)\n"
        "movss 0x18(%esi), %xmm2\n" /* line 957 | pTurretInfo */
        "movss 0x10(%esi), %xmm3\n" /* pTurretInfo */
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "movss -0x28(%ebp), %xmm4\n"
        "movaps %xmm2, %xmm5\n"
        "cmpnltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm5\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm5, %xmm1\n"
        /* { scope 2 */
        "movaps %xmm3, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm5\n"
        "cmpltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x6c(%eax)\n" /* line 957 */
        "movss %xmm4, 0x70(%eax)\n" /* line 959 */
        "movl 0xc(%esi), %eax\n" /* line 961 | pTurretInfo */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* pTurretInfo */
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0x114(%edi)\n" /* ps */
        "movl 8(%ebp), %eax\n" /* line 962 | self */
        "movss 0x144(%eax), %xmm0\n"
        "addss 0x14(%esi), %xmm0\n" /* pTurretInfo */
        "movss %xmm0, 0x10c(%edi)\n" /* ps */
        "subss 0x114(%edi), %xmm0\n" /* line 963 | ps */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps 0x10c(%edi)\n" /* ps */
        "movl 0x10(%esi), %eax\n" /* line 965 | pTurretInfo */
        "movl %eax, 4(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* pTurretInfo */
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0x118(%edi)\n" /* ps */
        "movl 8(%ebp), %edx\n" /* line 966 | self */
        "movss 0x148(%edx), %xmm0\n"
        "addss 0x18(%esi), %xmm0\n" /* pTurretInfo */
        "movss %xmm0, 0x110(%edi)\n" /* ps */
        "subss 0x118(%edi), %xmm0\n" /* line 967 | ps */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps 0x110(%edi)\n" /* ps */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 968 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ba3de_001ba62d:\n"
        "testb $2, %al\n" /* line 935 */
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0x24(%esi)\n" /* pTurretInfo */
        "movl 0x20(%esi), %eax\n" /* line 940 | pTurretInfo */
        "cmpl $2, %eax\n"
        "jne .Lf1ba3de_001ba474\n"
        ".Lf1ba3de_001ba644:\n"
        "movl 0xa0(%edi), %eax\n" /* line 943 | ps */
        "orb $1, %ah\n"
        "andb $0xfd, %ah\n"
        "movl %eax, 0xa0(%edi)\n" /* ps */
        "jmp .Lf1ba3de_001ba487\n"
        ".Lf1ba3de_001ba65b:\n"
        "movl 0xa0(%edi), %eax\n" /* line 948 | ps */
        "orb $2, %ah\n"
        "andb $0xfe, %ah\n"
        "movl %eax, 0xa0(%edi)\n" /* ps */
        "jmp .Lf1ba3de_001ba487\n"
    );
}

/* line 971 */
__attribute__((naked))
void G_SpawnTurret(gentity_t *self, const char *weaponinfoname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 971 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* self */
        "movl 0xc(%ebp), %eax\n" /* weaponinfoname */
        "movl %eax, -0x1c(%ebp)\n" /* weaponinfoname */
        "xorl %eax, %eax\n"
        "xorl %edx, %edx\n"
        "jmp .Lf1ba672_001ba699\n"
        /* { scope 1 */
        ".Lf1ba672_001ba68a:\n"
        "addl $1, %eax\n" /* line 978 */
        "leal 0x44(%ebx), %edx\n" /* weapDef */
        "cmpl $0x20, %eax\n"
        "je .Lf1ba672_001baa2c\n"
        ".Lf1ba672_001ba699:\n"
        "movl %edx, %ebx\n" /* line 980 | weapDef */
        "leal turretInfo(%edx), %esi\n" /* pTurretInfo */
        "movl turretInfo(%edx), %edx\n" /* line 981 */
        "testl %edx, %edx\n"
        "jne .Lf1ba672_001ba68a\n"
        ".Lf1ba672_001ba6ab:\n"
        "movl $0x44, 8(%esp)\n" /* line 988 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pTurretInfo */
        "calll memset\n"
        "movl %esi, 0x15c(%edi)\n" /* line 989 | pTurretInfo, self */
        "movl $1, turretInfo(%ebx)\n" /* line 990 | weapDef */
        "movl -0x1c(%ebp), %eax\n" /* line 992 | weaponinfoname */
        "movl %eax, (%esp)\n"
        "calll G_GetWeaponIndexForName\n"
        "movl %eax, 0xc8(%edi)\n" /* self */
        "testl %eax, %eax\n" /* line 993 */
        "je .Lf1ba672_001baa4d\n"
        ".Lf1ba672_001ba6ec:\n"
        "movl %eax, (%esp)\n" /* line 995 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ebx\n" /* weapDef */
        "cmpl $7, 0x7c(%eax)\n" /* line 997 */
        "je .Lf1ba672_001ba717\n"
        "movl -0x1c(%ebp), %eax\n" /* line 998 | weaponinfoname */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b58d0, (%esp)\n" /* "G_SpawnTurret: weapon '%s' isn't a turret. This usually indi" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf1ba672_001ba717:\n"
        "movl imp_level, %eax\n" /* line 1001 */
        "movl 0x1c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1ba672_001baa73\n"
        ".Lf1ba672_001ba727:\n"
        "movl $0, 8(%esi)\n" /* line 1004 | pTurretInfo */
        "movl 0x8c(%ebx), %eax\n" /* line 1006 | weapDef */
        "movl %eax, 0x20(%esi)\n" /* pTurretInfo */
        "movl $0xffffffff, 0x24(%esi)\n" /* line 1007 | pTurretInfo */
        "movl $0, 0x28(%esi)\n" /* line 1009 | pTurretInfo */
        "movl 0xb0(%ebx), %eax\n" /* line 1011 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1ba672_001ba758\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1ba672_001baa1c\n"
        ".Lf1ba672_001ba758:\n"
        "movb $0, 0x40(%esi)\n" /* line 1014 | pTurretInfo */
        ".Lf1ba672_001ba75c:\n"
        "movl 0xb4(%ebx), %eax\n" /* line 1016 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1ba672_001ba76f\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1ba672_001baa0c\n"
        ".Lf1ba672_001ba76f:\n"
        "movb $0, 0x41(%esi)\n" /* line 1019 | pTurretInfo */
        ".Lf1ba672_001ba773:\n"
        "movl 0xb8(%ebx), %eax\n" /* line 1021 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1ba672_001ba786\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1ba672_001ba9fc\n"
        ".Lf1ba672_001ba786:\n"
        "movb $0, 0x42(%esi)\n" /* line 1024 | pTurretInfo */
        ".Lf1ba672_001ba78a:\n"
        "movl 0xbc(%ebx), %eax\n" /* line 1026 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1ba672_001ba79d\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1ba672_001ba9b7\n"
        ".Lf1ba672_001ba79d:\n"
        "movb $0, 0x43(%esi)\n" /* line 1029 | pTurretInfo */
        "movl imp_level, %eax\n" /* line 1031 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1ba672_001ba9d4\n"
        ".Lf1ba672_001ba7b3:\n"
        "movl 0x52c(%ebx), %eax\n" /* line 1032 | weapDef */
        "movl %eax, 0x10(%esi)\n" /* pTurretInfo */
        ".Lf1ba672_001ba7bc:\n"
        "movss 0x10(%esi), %xmm0\n" /* line 1033 | pTurretInfo */
        "xorps sign+352, %xmm0\n"
        "movss %xmm0, 0x10(%esi)\n" /* pTurretInfo */
        "pxor %xmm1, %xmm1\n" /* line 1034 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1ba672_001ba7db\n"
        "movss %xmm1, 0x10(%esi)\n" /* line 1035 | pTurretInfo */
        ".Lf1ba672_001ba7db:\n"
        "movl imp_level, %eax\n" /* line 1037 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1ba672_001bab74\n"
        ".Lf1ba672_001ba7ed:\n"
        "movl 0x528(%ebx), %eax\n" /* line 1038 | weapDef */
        "movl %eax, 0x18(%esi)\n" /* pTurretInfo */
        "ucomiss 0x18(%esi), %xmm1\n" /* line 1039 | pTurretInfo */
        "ja .Lf1ba672_001babab\n"
        ".Lf1ba672_001ba800:\n"
        "movl imp_level, %eax\n" /* line 1042 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1ba672_001bab44\n"
        ".Lf1ba672_001ba812:\n"
        "movl 0x530(%ebx), %eax\n" /* line 1043 | weapDef */
        "movl %eax, 0xc(%esi)\n" /* pTurretInfo */
        ".Lf1ba672_001ba81b:\n"
        "movss 0xc(%esi), %xmm0\n" /* line 1044 | pTurretInfo */
        "xorps sign+352, %xmm0\n"
        "movaps %xmm1, %xmm2\n" /* line 1046 */
        "cmpnltss %xmm0, %xmm2\n"
        "andps %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movss %xmm0, 0xc(%esi)\n" /* pTurretInfo */
        "movl imp_level, %eax\n" /* line 1048 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1ba672_001bab14\n"
        ".Lf1ba672_001ba84c:\n"
        "movl 0x534(%ebx), %eax\n" /* line 1049 | weapDef */
        "movl %eax, 0x14(%esi)\n" /* pTurretInfo */
        ".Lf1ba672_001ba855:\n"
        "ucomiss 0x14(%esi), %xmm1\n" /* line 1050 | pTurretInfo */
        "ja .Lf1ba672_001babb7\n"
        ".Lf1ba672_001ba85f:\n"
        "movl $0xc2b40000, 0x1c(%esi)\n" /* line 1053 | pTurretInfo */
        "movl 0x194(%edi), %eax\n" /* line 1055 | self */
        "testl %eax, %eax\n"
        "jne .Lf1ba672_001ba87a\n"
        "movl $0x64, 0x194(%edi)\n" /* line 1056 | self */
        ".Lf1ba672_001ba87a:\n"
        "movl imp_level, %eax\n" /* line 1058 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1ba672_001baad1\n"
        ".Lf1ba672_001ba88c:\n"
        "movl 0x1ec(%ebx), %eax\n" /* line 1059 | weapDef */
        "movl %eax, 0x19c(%edi)\n" /* self */
        "movl 0x19c(%edi), %ecx\n" /* line 1061 | self */
        "testl %ecx, %ecx\n"
        "js .Lf1ba672_001bab05\n"
        ".Lf1ba672_001ba8a6:\n"
        "movl imp_level, %eax\n" /* line 1064 */
        "cmpb $0, 0x1348(%eax)\n"
        "jne .Lf1ba672_001baaa9\n"
        ".Lf1ba672_001ba8b8:\n"
        "movl 0x540(%ebx), %eax\n" /* line 1065 | weapDef */
        "movl %eax, 0x38(%esi)\n" /* pTurretInfo */
        ".Lf1ba672_001ba8c1:\n"
        "pxor %xmm0, %xmm0\n" /* line 1066 */
        "ucomiss 0x38(%esi), %xmm0\n" /* pTurretInfo */
        "jbe .Lf1ba672_001ba8d2\n"
        "movl $0, 0x38(%esi)\n" /* line 1067 | pTurretInfo */
        ".Lf1ba672_001ba8d2:\n"
        "movl $3, 4(%esi)\n" /* line 1069 | pTurretInfo */
        "movl $1, 0x184(%edi)\n" /* line 1071 | self */
        "movl $0x200004, 0x11c(%edi)\n" /* line 1072 | self */
        "movb $0, 0xf2(%edi)\n" /* line 1073 | self */
        "movl $9, 4(%edi)\n" /* line 1074 | self */
        "orl $__mh_execute_header, 0x174(%edi)\n" /* line 1075 | self */
        "movl %edi, (%esp)\n" /* line 1077 | self */
        "calll G_DObjUpdate\n"
        "leal 0x104(%edi), %edx\n" /* line 1079 | self, v */
        /* { scope 2 */
        "movl $0xc2000000, %eax\n" /* line 191 */
        "movl %eax, 0x104(%edi)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0x110(%edi), %edx\n" /* line 1080 | self, v */
        /* { scope 2 */
        "movl $0x42000000, %eax\n" /* line 191 */
        "movl %eax, 0x110(%edi)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl $0x42600000, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0x138(%edi), %eax\n" /* line 1082 | self */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* self */
        "calll G_SetOrigin\n"
        "leal 0x144(%edi), %eax\n" /* line 1083 | self */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* self */
        "calll G_SetAngle\n"
        "leal 0x68(%edi), %eax\n" /* line 1084 | self, v */
        /* { scope 2 */
        "movl $0, 0x68(%edi)\n" /* line 183 */
        "movl $0, 4(%eax)\n" /* line 184 */
        "movl $0, 8(%eax)\n" /* line 185 */
        /* } scope */
        "movb $0xd, 0x166(%edi)\n" /* line 1086 | self */
        "movl imp_level, %eax\n" /* line 1087 */
        "movl 0x1ec(%eax), %eax\n"
        "addl $0x32, %eax\n"
        "movl %eax, 0x190(%edi)\n" /* self */
        "movl $3, 0x30(%edi)\n" /* line 1089 | self */
        "movb $0, 0x161(%edi)\n" /* line 1090 | self */
        "movl %edi, 8(%ebp)\n" /* line 1094 | self */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1095 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_LinkEntity\n" /* line 1094 */
        ".Lf1ba672_001ba9b7:\n"
        "movl %eax, (%esp)\n" /* line 1027 */
        "calll G_SoundAliasIndex\n"
        "movb %al, 0x43(%esi)\n" /* pTurretInfo */
        "movl imp_level, %eax\n" /* line 1031 */
        "cmpb $0, 0x1348(%eax)\n"
        "je .Lf1ba672_001ba7b3\n"
        ".Lf1ba672_001ba9d4:\n"
        "leal 0x10(%esi), %eax\n" /* pTurretInfo */
        "movl %eax, 8(%esp)\n"
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002b5950, (%esp)\n" /* "rightarc" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "jne .Lf1ba672_001ba7bc\n"
        "jmp .Lf1ba672_001ba7b3\n"
        ".Lf1ba672_001ba9fc:\n"
        "movl %eax, (%esp)\n" /* line 1022 */
        "calll G_SoundAliasIndex\n"
        "movb %al, 0x42(%esi)\n" /* pTurretInfo */
        "jmp .Lf1ba672_001ba78a\n"
        ".Lf1ba672_001baa0c:\n"
        "movl %eax, (%esp)\n" /* line 1017 */
        "calll G_SoundAliasIndex\n"
        "movb %al, 0x41(%esi)\n" /* pTurretInfo */
        "jmp .Lf1ba672_001ba773\n"
        ".Lf1ba672_001baa1c:\n"
        "movl %eax, (%esp)\n" /* line 1012 */
        "calll G_SoundAliasIndex\n"
        "movb %al, 0x40(%esi)\n" /* pTurretInfo */
        "jmp .Lf1ba672_001ba75c\n"
        ".Lf1ba672_001baa2c:\n"
        "movl $0x20, 8(%esp)\n" /* line 986 */
        "movl $str_002b5870, 4(%esp)\n" /* "G_SpawnTurret: max number of turrets (%d) exceeded" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1ba672_001ba6ab\n"
        ".Lf1ba672_001baa4d:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 994 | weaponinfoname */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b58a4, 4(%esp)\n" /* "bad weaponinfo '%s' specified for turret" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc8(%edi), %eax\n" /* self */
        "jmp .Lf1ba672_001ba6ec\n"
        ".Lf1ba672_001baa73:\n"
        "movl 0xc8(%edi), %eax\n" /* line 1001 | self */
        "movl %eax, (%esp)\n"
        "calll IsItemRegistered\n"
        "testl %eax, %eax\n"
        "jne .Lf1ba672_001ba727\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1002 | weaponinfoname */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b5934, (%esp)\n" /* "turret '%s' not precached" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf1ba672_001ba727\n"
        ".Lf1ba672_001baaa9:\n"
        "leal 0x38(%esi), %eax\n" /* line 1064 | pTurretInfo */
        "movl %eax, 8(%esp)\n"
        "movl $str_002162ac, 4(%esp)\n" /* "1" */
        "movl $str_002218bc, (%esp)\n" /* "playerSpread" */
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "jne .Lf1ba672_001ba8c1\n"
        "jmp .Lf1ba672_001ba8b8\n"
        ".Lf1ba672_001baad1:\n"
        "leal 0x19c(%edi), %eax\n" /* line 1058 | self */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021952c, 4(%esp)\n" /* "0" */
        "movl $str_0022096c, (%esp)\n" /* "damage" */
        "calll G_SpawnInt\n"
        "testl %eax, %eax\n"
        "je .Lf1ba672_001ba88c\n"
        "movl 0x19c(%edi), %ecx\n" /* line 1061 | self */
        "testl %ecx, %ecx\n"
        "jns .Lf1ba672_001ba8a6\n"
        ".Lf1ba672_001bab05:\n"
        "movl $0, 0x19c(%edi)\n" /* line 1062 | self */
        "jmp .Lf1ba672_001ba8a6\n"
        ".Lf1ba672_001bab14:\n"
        "leal 0x14(%esi), %eax\n" /* line 1048 | pTurretInfo */
        "movl %eax, 8(%esp)\n"
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002b596c, (%esp)\n" /* "bottomarc" */
        "calll G_SpawnFloat\n"
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jne .Lf1ba672_001ba855\n"
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf1ba672_001ba84c\n"
        ".Lf1ba672_001bab44:\n"
        "leal 0xc(%esi), %eax\n" /* line 1042 | pTurretInfo */
        "movl %eax, 8(%esp)\n"
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002b5964, (%esp)\n" /* "toparc" */
        "calll G_SpawnFloat\n"
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jne .Lf1ba672_001ba81b\n"
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf1ba672_001ba812\n"
        ".Lf1ba672_001bab74:\n"
        "leal 0x18(%esi), %eax\n" /* line 1037 | pTurretInfo */
        "movl %eax, 8(%esp)\n"
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002b595c, (%esp)\n" /* "leftarc" */
        "movss %xmm1, -0x38(%ebp)\n"
        "calll G_SpawnFloat\n"
        "testl %eax, %eax\n"
        "movss -0x38(%ebp), %xmm1\n"
        "je .Lf1ba672_001ba7ed\n"
        "ucomiss 0x18(%esi), %xmm1\n" /* line 1039 | pTurretInfo */
        "jbe .Lf1ba672_001ba800\n"
        ".Lf1ba672_001babab:\n"
        "movl $0, 0x18(%esi)\n" /* line 1040 | pTurretInfo */
        "jmp .Lf1ba672_001ba800\n"
        ".Lf1ba672_001babb7:\n"
        "movl $0, 0x14(%esi)\n" /* line 1051 | pTurretInfo */
        "jmp .Lf1ba672_001ba85f\n"
    );
}

/* line 1098 */
void SP_turret(gentity_t *self)
{
    const char *weaponinfoname;

    if (!G_SpawnString("weaponinfo", "", &weaponinfoname))
    {
        Com_Error(1, "no weaponinfo specified for turret");
    }
    G_SpawnTurret(self, weaponinfoname);
}

/* line 577 */
__attribute__((naked))
void turret_think_client(gentity_t *self)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 577 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1cc, %esp\n"
        "movl 8(%ebp), %edi\n" /* self */
        /* { scope 1: pTurretInfo */
        "movl 0x150(%edi), %eax\n" /* line 581 | self */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n"
        "subl %eax, %esi\n"
        "shll $4, %esi\n"
        "addl imp_g_entities, %esi\n"
        "cmpb $1, 0x162(%esi)\n" /* line 585 */
        "je .Lf1bac12_001bac58\n"
        ".Lf1bac12_001bac45:\n"
        "movl %edi, (%esp)\n" /* line 593 | self */
        "calll G_ClientStopUsingTurret\n"
        /* } scope */
        ".Lf1bac12_001bac4d:\n"
        "addl $0x1cc, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pTurretInfo */
        ".Lf1bac12_001bac58:\n"
        "movl 0x158(%esi), %ebx\n" /* line 585 | owner */
        "movl 0x26a8(%ebx), %eax\n" /* owner */
        "testl %eax, %eax\n"
        "jne .Lf1bac12_001bac45\n"
        /* { scope 2: i, numVertChildren, iPrevBlend, ci, ... */
        "movl 0x15c(%edi), %eax\n" /* line 461 */
        "movl %eax, -0x1a4(%ebp)\n" /* pTurretInfo */
        "movl $1, 0x590(%ebx)\n" /* line 421 | pLerpAnim */
        "movl (%edi), %eax\n" /* line 422 */
        "movl %eax, 0x594(%ebx)\n" /* pLerpAnim */
        "movl 0x144(%edi), %eax\n" /* line 424 */
        "movl %eax, 4(%esp)\n"
        "movl 0xe8(%ebx), %eax\n" /* pLerpAnim */
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm0\n"
        "movss %xmm0, 0x68(%edi)\n"
        "movl -0x1a4(%ebp), %edx\n" /* line 425 | pTurretInfo */
        "movss 0x14(%edx), %xmm2\n"
        "movss 0xc(%edx), %xmm3\n"
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "pxor %xmm5, %xmm5\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm5, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        /* { scope 3: xx, yy, zw, flashTag, ... */
        "movaps %xmm3, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm3, %xmm4\n"
        "cmpnltss %xmm5, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x68(%edi)\n" /* line 425 */
        "movl 0x148(%edi), %eax\n" /* line 427 */
        "movl %eax, 4(%esp)\n"
        "movl 0xec(%ebx), %eax\n" /* pLerpAnim */
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm0\n"
        "movss %xmm0, 0x6c(%edi)\n"
        "movl -0x1a4(%ebp), %eax\n" /* line 428 | pTurretInfo */
        "movss 0x18(%eax), %xmm2\n"
        "movss 0x10(%eax), %xmm3\n"
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "pxor %xmm5, %xmm5\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm5, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        /* { scope 3: xx, yy, zw, flashTag, ... */
        "movaps %xmm3, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm3, %xmm4\n"
        "cmpnltss %xmm5, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x6c(%edi)\n" /* line 428 */
        "movl $0, 0x70(%edi)\n" /* line 430 */
        "movl -0x1a4(%ebp), %edx\n" /* line 432 | pTurretInfo */
        "movl 4(%edx), %eax\n"
        "testb $8, %ah\n"
        "je .Lf1bac12_001bad93\n"
        "andb $0xf7, %ah\n" /* line 434 */
        "movl %eax, 4(%edx)\n"
        "xorl $2, 8(%edi)\n" /* line 435 */
        /* { scope 3: xx, yy, zw, flashTag, ... */
        ".Lf1bac12_001bad93:\n"
        "movl 0x90(%esi), %eax\n" /* line 237 */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl imp_level_bgs, %ecx\n"
        "movl %ecx, -0x1a8(%ebp)\n"
        "leal 0xb3bf0(%ecx, %edx, 8), %edx\n"
        "leal 0xc(%edx), %eax\n"
        "movl %eax, -0x188(%ebp)\n" /* ci */
        "leal 0x38c(%edx), %ebx\n" /* line 241 | pLerpAnim */
        "movl 0x10(%ebx), %eax\n" /* line 242 | pLerpAnim */
        "testl %eax, %eax\n"
        "je .Lf1bac12_001bade0\n"
        "movl 0x14(%ebx), %eax\n" /* pLerpAnim */
        "testl %eax, %eax\n"
        "je .Lf1bac12_001bade0\n"
        "testb $4, 0x50(%eax)\n"
        "jne .Lf1bac12_001bae7a\n"
        /* } scope */
        ".Lf1bac12_001bade0:\n"
        "movl 0xc8(%edi), %eax\n" /* line 472 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edx\n"
        "movl 0x158(%esi), %eax\n" /* line 474 */
        "movl $1, 0x590(%eax)\n"
        "andl $0xffffffbf, 8(%edi)\n" /* line 475 */
        "movl -0x1a4(%ebp), %ecx\n" /* line 477 | pTurretInfo */
        "movl 8(%ecx), %eax\n"
        "subl $0x32, %eax\n"
        "movl %eax, 8(%ecx)\n"
        "testl %eax, %eax\n" /* line 479 */
        "jle .Lf1bac12_001bb355\n"
        /* } scope */
        /* { scope 2: i, numVertChildren, iPrevBlend, ci, ... */
        ".Lf1bac12_001bae1b:\n"
        "movl 0x15c(%edi), %edx\n" /* line 503 */
        "movl $0, 0x84(%edi)\n" /* line 506 */
        "movl 0x28(%edx), %ecx\n" /* line 507 */
        "testl %ecx, %ecx\n"
        "jle .Lf1bac12_001bac4d\n"
        "movzbl 0x40(%edx), %eax\n" /* line 509 */
        "movl %eax, 0x84(%edi)\n"
        "movl 0x28(%edx), %eax\n" /* line 511 */
        "subl $0x32, %eax\n"
        "movl %eax, 0x28(%edx)\n"
        "testl %eax, %eax\n" /* line 513 */
        "jg .Lf1bac12_001bac4d\n"
        "cmpb $0, 0x42(%edx)\n"
        "je .Lf1bac12_001bac4d\n"
        "movl $0, 0x84(%edi)\n" /* line 515 */
        "movzbl 0x42(%edx), %eax\n" /* line 516 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll G_PlaySoundAlias\n"
        "jmp .Lf1bac12_001bac4d\n"
        /* } scope */
        /* { scope 2: i, numVertChildren, iPrevBlend, ci, ... */
        /* { scope 3: xx, yy, zw, flashTag, ... */
        ".Lf1bac12_001bae7a:\n"
        "movl imp_scr_const, %eax\n" /* line 245 */
        "movzwl 0x98(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll G_DObjGetLocalTagMatrix\n"
        "movl %eax, -0x168(%ebp)\n" /* tagMat */
        "testl %eax, %eax\n" /* line 246 */
        "je .Lf1bac12_001bbe74\n"
        "movl 0xc8(%edi), %eax\n" /* line 253 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x184(%ebp)\n" /* weapDef */
        "movl -0x188(%ebp), %eax\n" /* line 257 | ci */
        "movl 0x4a4(%eax), %eax\n"
        "movl %eax, -0x164(%ebp)\n" /* pAnimTree */
        "movl -0x1a8(%ebp), %edx\n" /* line 258 */
        "movl 0xb3bb4(%edx), %edx\n"
        "movl %edx, -0x160(%ebp)\n" /* pXAnims */
        "movl 0x10(%ebx), %ebx\n" /* line 259 | pLerpAnim */
        "andb $0xfd, %bh\n" /* pLerpAnim */
        "movl %ebx, -0x15c(%ebp)\n" /* pLerpAnim, baseAnim */
        /* { scope 4 */
        "movl -0x168(%ebp), %ecx\n" /* line 306 | tagMat */
        "movss 0x1c(%ecx), %xmm1\n" /* scale */
        /* { scope 5 */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "mulss (%ecx), %xmm3\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%ecx), %xmm6\n"
        "mulss 8(%ecx), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 308 */
        "mulss (%ecx), %xmm0\n"
        "movss %xmm0, -0x14c(%ebp)\n" /* xx */
        "movss 4(%ecx), %xmm5\n" /* line 309 */
        "movaps %xmm3, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "movss 8(%ecx), %xmm2\n" /* line 310 */
        "movaps %xmm3, %xmm7\n"
        "mulss %xmm2, %xmm7\n"
        "movss 0xc(%ecx), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm6, %xmm5\n" /* line 313 */
        "movss %xmm5, -0x148(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm5\n" /* line 314 */
        "mulss %xmm2, %xmm5\n"
        "mulss %xmm0, %xmm6\n" /* line 315 */
        "mulss %xmm1, %xmm2\n" /* line 317 */
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss %xmm1, -0x1b0(%ebp)\n" /* zw */
        "movss -0x148(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm2, %xmm0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x8c(%ebp)\n" /* tagAxis */
        "movss -0x1b0(%ebp), %xmm0\n" /* line 321 | zw */
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movaps %xmm7, %xmm0\n" /* line 322 */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n"
        "subss -0x1b0(%ebp), %xmm4\n" /* line 324 | zw */
        "movss %xmm4, -0x80(%ebp)\n"
        "addss -0x14c(%ebp), %xmm2\n" /* line 325 | xx */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 326 */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x78(%ebp)\n"
        "addss %xmm6, %xmm7\n" /* line 328 */
        "movss %xmm7, -0x74(%ebp)\n"
        "subss %xmm3, %xmm5\n" /* line 329 */
        "movss %xmm5, -0x70(%ebp)\n"
        "movss -0x14c(%ebp), %xmm2\n" /* line 330 | xx */
        "addss -0x148(%ebp), %xmm2\n" /* yy */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n"
        /* } scope */
        "leal -0x8c(%ebp), %eax\n" /* line 262 | tagAxis */
        "movl %eax, (%esp)\n"
        "calll vectosignedyaw\n"
        "fstps -0x180(%ebp)\n" /* localYaw */
        "leal -0xbc(%ebp), %eax\n" /* line 264 | turretAxis */
        "movl %eax, 4(%esp)\n"
        "leal 0x144(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x138(%edi), %edx\n"
        /* { scope 4 */
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x98(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x94(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x90(%ebp)\n"
        /* } scope */
        "leal 0x138(%esi), %edx\n" /* line 267 */
        "movl %edx, -0x1a0(%ebp)\n"
        "movss 0x138(%esi), %xmm0\n" /* line 304 */
        "subss -0x98(%ebp), %xmm0\n"
        "mulss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, -0x16c(%ebp)\n" /* tagHeight */
        "movss 4(%edx), %xmm0\n"
        "subss -0x94(%ebp), %xmm0\n"
        "mulss -0xa0(%ebp), %xmm0\n"
        "addss -0x16c(%ebp), %xmm0\n" /* tagHeight */
        "movss %xmm0, -0x16c(%ebp)\n" /* tagHeight */
        "movss 8(%edx), %xmm0\n"
        "subss -0x90(%ebp), %xmm0\n"
        "mulss -0x9c(%ebp), %xmm0\n"
        "addss -0x16c(%ebp), %xmm0\n" /* tagHeight */
        "movss %xmm0, -0x16c(%ebp)\n" /* tagHeight */
        "movl -0x168(%ebp), %eax\n" /* line 269 | tagMat */
        "subss 0x18(%eax), %xmm0\n"
        "movss %xmm0, -0x17c(%ebp)\n" /* fDelta */
        "movl $0, 8(%esp)\n" /* line 271 */
        "movl -0x15c(%ebp), %edx\n" /* baseAnim */
        "movl %edx, 4(%esp)\n"
        "movl -0x164(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimClearTreeGoalWeightsStrict\n"
        "movl -0x15c(%ebp), %eax\n" /* line 273 | baseAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x160(%ebp), %edx\n" /* pXAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetNumChildren\n"
        "movl %eax, -0x190(%ebp)\n" /* numVertChildren */
        "testl %eax, %eax\n" /* line 279 */
        "je .Lf1bac12_001bbd68\n"
        ".Lf1bac12_001bb121:\n"
        "movl $0, -0x174(%ebp)\n" /* line 280 | fPrevBlend */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x140(%ebp)\n"
        "movl $0, -0x18c(%ebp)\n" /* iPrevBlend */
        "movl $0, -0x154(%ebp)\n" /* leafAnim2 */
        "movl $0, -0x194(%ebp)\n" /* i */
        "jmp .Lf1bac12_001bb27a\n"
        ".Lf1bac12_001bb15a:\n"
        "cvttss2si %xmm1, %ebx\n" /* line 296 | pLerpAnim */
        ".Lf1bac12_001bb15e:\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 300 | pLerpAnim */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x13c(%ebp)\n"
        "movl %ebx, 8(%esp)\n" /* line 302 | pLerpAnim */
        "movl -0x150(%ebp), %eax\n" /* heightAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x160(%ebp), %edx\n" /* pXAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, -0x158(%ebp)\n" /* leafAnim1 */
        "movss lit4_002ed5d0, %xmm0\n" /* line 303 | 1.0f */
        "subss -0x13c(%ebp), %xmm0\n"
        "movss %xmm0, -0x19c(%ebp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movss -0x13c(%ebp), %xmm0\n" /* line 305 */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1bac12_001bb553\n"
        "jne .Lf1bac12_001bb553\n"
        ".Lf1bac12_001bb203:\n"
        "leal -0x2c(%ebp), %edx\n" /* line 311 | trans */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* rot */
        "movl %ecx, 8(%esp)\n"
        "movl -0x150(%ebp), %eax\n" /* heightAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimCalcAbsDelta\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 312 */
        "movss %xmm0, -0x178(%ebp)\n" /* fPrevTransZ */
        "ucomiss -0x17c(%ebp), %xmm0\n" /* fDelta */
        "jae .Lf1bac12_001bbd53\n"
        "addl $1, -0x194(%ebp)\n" /* line 319 | i */
        "movl -0x194(%ebp), %eax\n" /* line 283 | i */
        "cmpl %eax, -0x190(%ebp)\n" /* numVertChildren */
        "jle .Lf1bac12_001bb605\n"
        "movss %xmm0, -0x140(%ebp)\n"
        "movss -0x13c(%ebp), %xmm0\n"
        "movss %xmm0, -0x174(%ebp)\n" /* fPrevBlend */
        "movl %ebx, -0x18c(%ebp)\n" /* pLerpAnim, iPrevBlend */
        ".Lf1bac12_001bb27a:\n"
        "movl -0x194(%ebp), %eax\n" /* line 285 | i */
        "movl %eax, 8(%esp)\n"
        "movl -0x15c(%ebp), %edx\n" /* baseAnim */
        "movl %edx, 4(%esp)\n"
        "movl -0x160(%ebp), %ecx\n" /* pXAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, -0x150(%ebp)\n" /* heightAnim */
        "movl $0, 0x1c(%esp)\n" /* line 286 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl -0x150(%ebp), %edx\n" /* line 288 | heightAnim */
        "movl %edx, 4(%esp)\n"
        "movl -0x160(%ebp), %ecx\n" /* pXAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetNumChildren\n"
        "movl %eax, %ebx\n" /* pLerpAnim */
        "testl %eax, %eax\n" /* line 289 */
        "je .Lf1bac12_001bb5c5\n"
        ".Lf1bac12_001bb306:\n"
        "cvtsi2ssl %ebx, %xmm1\n" /* line 292 | pLerpAnim */
        "mulss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "movss -0x180(%ebp), %xmm0\n" /* localYaw */
        "movl -0x184(%ebp), %ecx\n" /* weapDef */
        "divss 0x564(%ecx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 294 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1bac12_001bb5fa\n"
        "leal -1(%ebx), %eax\n" /* line 296 | pLerpAnim */
        "cvtsi2ssl %eax, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf1bac12_001bb15a\n"
        "cvttss2si %xmm0, %ebx\n" /* pLerpAnim */
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf1bac12_001bb15e\n"
        /* } scope */
        ".Lf1bac12_001bb355:\n"
        "movl $0, 8(%ecx)\n" /* line 481 */
        "movl 0x158(%esi), %eax\n" /* line 483 */
        "testb $1, 0x27bc(%eax)\n"
        "je .Lf1bac12_001bae1b\n"
        "movl 0x204(%edx), %eax\n" /* line 485 */
        "movl %eax, 8(%ecx)\n"
        "movl 0x15c(%edi), %ebx\n" /* line 445 | pLerpAnim */
        "movl 0xc8(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x204(%eax), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, 0x28(%ebx)\n" /* pLerpAnim */
        "movl 0x158(%esi), %eax\n" /* line 447 */
        "testl %eax, %eax\n"
        "je .Lf1bac12_001bb54a\n"
        /* { scope 3: xx, yy, zw, flashTag, ... */
        "movl imp_g_entities, %edx\n" /* line 170 */
        "leal 0x8bdd0(%edx), %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf1bac12_001bbeeb\n"
        "movl %esi, %ebx\n"
        /* { scope 4 */
        ".Lf1bac12_001bb3bc:\n"
        "leal -0xbc(%ebp), %eax\n" /* line 140 | turretAxis */
        "movl %eax, 8(%esp)\n"
        "movl imp_scr_const, %eax\n"
        "movzwl 0x8c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll G_DObjGetWorldTagMatrix\n"
        "testl %eax, %eax\n"
        "je .Lf1bac12_001bbeb1\n"
        ".Lf1bac12_001bb3e6:\n"
        "leal -0x44(%ebp), %eax\n" /* line 143 | end */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_GetPlayerViewOrigin\n"
        "leal -0x114(%ebp), %eax\n" /* line 144 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x120(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x12c(%ebp), %eax\n" /* axis */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll G_GetPlayerViewDirection\n"
        "movl -0x12c(%ebp), %eax\n" /* line 199 | axis */
        "movl %eax, -0xfc(%ebp)\n"
        "movl -0x128(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0xf8(%ebp)\n"
        "movl -0x124(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0xf4(%ebp)\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 248 */
        "subss -0x44(%ebp), %xmm0\n" /* end */
        "movss %xmm0, -0x2c(%ebp)\n" /* trans */
        "movss -0x94(%ebp), %xmm0\n" /* line 249 */
        "subss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 250 */
        "subss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "leal -0x2c(%ebp), %eax\n" /* line 149 | trans */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm1\n"
        /* { scope 5 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x12c(%ebp), %xmm0\n" /* axis */
        "addss -0x44(%ebp), %xmm0\n" /* end */
        "movss %xmm0, -0x108(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x128(%ebp), %xmm0\n"
        "addss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x104(%ebp)\n"
        "mulss -0x124(%ebp), %xmm1\n" /* line 290 */
        "addss -0x3c(%ebp), %xmm1\n"
        "movss %xmm1, -0x100(%ebp)\n"
        /* } scope */
        /* } scope */
        "movl 0xc8(%edi), %eax\n" /* line 174 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0xf0(%ebp)\n"
        "movl 0x78(%eax), %eax\n" /* line 176 */
        "testl %eax, %eax\n"
        "jne .Lf1bac12_001bbe55\n"
        "movl imp_level, %eax\n" /* line 179 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "leal -0x12c(%ebp), %edx\n" /* axis */
        "movl %edx, 8(%esp)\n"
        "movl 0x15c(%edi), %eax\n"
        "movl 0x38(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Bullet_Fire\n"
        ".Lf1bac12_001bb524:\n"
        "movl (%ebx), %eax\n" /* line 184 */
        "movl %eax, 8(%esp)\n"
        "movl $0xaf, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll G_AddEvent\n"
        /* } scope */
        "movl 0x158(%esi), %eax\n" /* line 451 */
        "movl $2, 0x590(%eax)\n"
        ".Lf1bac12_001bb54a:\n"
        "orl $0x40, 8(%edi)\n" /* line 487 */
        "jmp .Lf1bac12_001bae1b\n"
        /* { scope 3: xx, yy, zw, flashTag, ... */
        ".Lf1bac12_001bb553:\n"
        "leal 1(%ebx), %eax\n" /* line 307 | pLerpAnim */
        "movl %eax, 8(%esp)\n"
        "movl -0x150(%ebp), %eax\n" /* heightAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x160(%ebp), %edx\n" /* pXAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, -0x154(%ebp)\n" /* leafAnim2 */
        "movl $0, 0x1c(%esp)\n" /* line 308 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movss -0x13c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1bac12_001bb203\n"
        ".Lf1bac12_001bb5c5:\n"
        "movl -0x150(%ebp), %eax\n" /* line 290 | heightAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x160(%ebp), %edx\n" /* pXAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetAnimDebugName\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002b59fc, 4(%esp)\n" /* "Player anim '%s' has no children" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1bac12_001bb306\n"
        ".Lf1bac12_001bb5fa:\n"
        "pxor %xmm1, %xmm1\n" /* line 294 */
        "xorl %ebx, %ebx\n" /* pLerpAnim */
        "jmp .Lf1bac12_001bb15e\n"
        ".Lf1bac12_001bb605:\n"
        "movss -0x13c(%ebp), %xmm0\n" /* line 283 */
        "movss %xmm0, -0x174(%ebp)\n" /* fPrevBlend */
        "movl %ebx, -0x18c(%ebp)\n" /* pLerpAnim, iPrevBlend */
        ".Lf1bac12_001bb61b:\n"
        "movl $0, 8(%esp)\n" /* line 322 */
        "movl -0x15c(%ebp), %eax\n" /* baseAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimClearTreeGoalWeightsStrict\n"
        "movl -0x158(%ebp), %ecx\n" /* line 324 | leafAnim1 */
        "movl %ecx, 4(%esp)\n"
        "movl -0x164(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm2\n"
        "subss -0x19c(%ebp), %xmm2\n"
        "andps sign+368, %xmm2\n"
        "movl imp_level, %eax\n"
        "cvtsi2ssl 0x1f4(%eax), %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 325 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1bac12_001bb6a2\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1bac12_001bb6a2:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x19c(%ebp), %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "movl -0x158(%ebp), %eax\n" /* leafAnim1 */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movss -0x13c(%ebp), %xmm0\n" /* line 327 */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf1bac12_001bbd9d\n"
        "jne .Lf1bac12_001bbd9d\n"
        ".Lf1bac12_001bb709:\n"
        "movl -0x194(%ebp), %eax\n" /* line 333 | i */
        "testl %eax, %eax\n"
        "je .Lf1bac12_001bb725\n"
        "movl -0x190(%ebp), %ecx\n" /* numVertChildren */
        "cmpl %ecx, -0x194(%ebp)\n" /* i */
        "jne .Lf1bac12_001bb9cb\n"
        ".Lf1bac12_001bb725:\n"
        "movl -0x150(%ebp), %eax\n" /* line 336 | heightAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm2\n"
        "subss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "andps sign+368, %xmm2\n"
        "movl imp_level, %eax\n"
        "cvtsi2ssl 0x1f4(%eax), %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 337 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1bac12_001bb78c\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1bac12_001bb78c:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl -0x150(%ebp), %ecx\n" /* heightAnim */
        "movl %ecx, 4(%esp)\n"
        "movl -0x164(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1bac12_001bb7d2:\n"
        "leal -0x2c(%ebp), %edx\n" /* line 365 | trans */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* rot */
        "movl %ecx, 8(%esp)\n"
        "movl -0x15c(%ebp), %eax\n" /* baseAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimCalcAbsDelta\n"
        "movss -0x180(%ebp), %xmm0\n" /* line 366 | localYaw */
        "movss %xmm0, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* trans */
        "movl %eax, (%esp)\n"
        "calll VectorAngleMultiply\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 58 | trans */
        "movl -0x168(%ebp), %edx\n" /* tagMat */
        "addss 0x10(%edx), %xmm0\n"
        "movss %xmm0, -0xc8(%ebp)\n"
        "leal -0xec(%ebp), %ebx\n" /* line 59 | localAxis */
        "movss -0x28(%ebp), %xmm0\n"
        "addss 0x14(%edx), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss -0x16c(%ebp), %xmm0\n" /* line 368 | tagHeight */
        "movss %xmm0, -0xc0(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 370 | rot */
        "movl %eax, (%esp)\n"
        "calll RotationToYaw\n"
        "fstps -0x198(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* line 372 | pLerpAnim */
        "movss -0x180(%ebp), %xmm0\n" /* localYaw */
        "addss -0x198(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll YawToAxis\n"
        "leal -0x12c(%ebp), %eax\n" /* line 374 | axis */
        "movl %eax, 8(%esp)\n"
        "leal -0xbc(%ebp), %edx\n" /* turretAxis */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pLerpAnim */
        "calll MatrixMultiply43\n"
        "movl 0x158(%esi), %edx\n" /* line 376 */
        "leal 0x14(%edx), %ecx\n" /* to */
        /* { scope 4 */
        "movl -0x108(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x104(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x100(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl 0x158(%esi), %eax\n"
        "leal 0x14(%eax), %edx\n"
        /* } scope */
        /* { scope 4 */
        "movl 0x14(%eax), %eax\n" /* line 199 */
        "movl %eax, -0x38(%ebp)\n" /* start */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x34(%ebp)\n"
        "movss 8(%edx), %xmm1\n" /* line 201 */
        "movss %xmm1, -0x30(%ebp)\n"
        "movl 0x158(%esi), %eax\n"
        "leal 0x14(%eax), %edx\n"
        /* } scope */
        /* { scope 4 */
        "movl 0x14(%eax), %eax\n" /* line 199 */
        "movl %eax, -0x44(%ebp)\n" /* end */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x40(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x3c(%ebp)\n"
        /* } scope */
        "movl 0x158(%esi), %eax\n" /* line 382 */
        "addss 0xf8(%eax), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "subss lit4_002ed7c8, %xmm0\n" /* line 383 | 60.0f */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl $0x2810011, 0x18(%esp)\n" /* line 385 */
        "movl (%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x44(%ebp), %eax\n" /* end */
        "movl %eax, 0x10(%esp)\n"
        "movl imp_vec3_origin, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "leal -0x68(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movss -0x68(%ebp), %xmm2\n" /* line 386 | trace */
        "ucomiss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "jb .Lf1bac12_001bbe85\n"
        ".Lf1bac12_001bb964:\n"
        "movl $1, 0xc(%esp)\n" /* line 393 */
        "movl $1, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl 0x158(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_PlayerStateToEntityState\n"
        "movl 0x158(%esi), %eax\n"
        "leal 0x14(%eax), %edx\n"
        /* { scope 4 */
        "movl 0x14(%eax), %eax\n" /* line 199 */
        "movl -0x1a0(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x144(%esi), %eax\n" /* line 397 */
        "movl %eax, 4(%esp)\n"
        "leal -0x12c(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll AxisToAngles\n"
        "movl %esi, (%esp)\n" /* line 399 */
        "calll SV_LinkEntity\n"
        "jmp .Lf1bac12_001bade0\n"
        ".Lf1bac12_001bb9cb:\n"
        "movss -0x17c(%ebp), %xmm0\n" /* line 343 | fDelta */
        "subss -0x178(%ebp), %xmm0\n" /* fPrevTransZ */
        "movss %xmm0, -0x170(%ebp)\n" /* fHeightRatio */
        "movss -0x24(%ebp), %xmm0\n"
        "subss -0x178(%ebp), %xmm0\n" /* fPrevTransZ */
        "movss -0x170(%ebp), %xmm1\n" /* fHeightRatio */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x170(%ebp)\n" /* fHeightRatio */
        "movl -0x150(%ebp), %eax\n" /* line 345 | heightAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm2\n"
        "subss -0x170(%ebp), %xmm2\n" /* fHeightRatio */
        "andps sign+368, %xmm2\n"
        "movl imp_level, %eax\n"
        "cvtsi2ssl 0x1f4(%eax), %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 346 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1bac12_001bba6b\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1bac12_001bba6b:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, %ebx\n" /* pLerpAnim */
        "movl %ebx, 0x10(%esp)\n" /* pLerpAnim */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x170(%ebp), %xmm0\n" /* fHeightRatio */
        "movss %xmm0, 8(%esp)\n"
        "movl -0x150(%ebp), %eax\n" /* heightAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl -0x194(%ebp), %eax\n" /* line 348 | i */
        "subl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x15c(%ebp), %ecx\n" /* baseAnim */
        "movl %ecx, 4(%esp)\n"
        "movl -0x160(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, -0x144(%ebp)\n"
        "movl %eax, 4(%esp)\n" /* line 350 */
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm2\n"
        "movl %ebx, -0x1ac(%ebp)\n" /* pLerpAnim */
        "movss -0x1ac(%ebp), %xmm3\n"
        "subss -0x170(%ebp), %xmm3\n" /* fHeightRatio */
        "subss %xmm3, %xmm2\n"
        "andps sign+368, %xmm2\n"
        "movl imp_level, %eax\n"
        "cvtsi2ssl 0x1f4(%eax), %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 351 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1bac12_001bbb56\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1bac12_001bbb56:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm3, 8(%esp)\n"
        "movl -0x144(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x164(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl -0x18c(%ebp), %edx\n" /* line 353 | iPrevBlend */
        "movl %edx, 8(%esp)\n"
        "movl -0x144(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x160(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, %ebx\n" /* pLerpAnim */
        "movl %eax, 4(%esp)\n" /* line 354 */
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm2\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "subss -0x174(%ebp), %xmm3\n" /* fPrevBlend */
        "subss %xmm3, %xmm2\n"
        "andps sign+368, %xmm2\n"
        "movl imp_level, %eax\n"
        "cvtsi2ssl 0x1f4(%eax), %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 355 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1bac12_001bbc2b\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1bac12_001bbc2b:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm3, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* pLerpAnim */
        "movl -0x164(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 357 | fPrevBlend */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf1bac12_001bbc80\n"
        "je .Lf1bac12_001bb7d2\n"
        ".Lf1bac12_001bbc80:\n"
        "movl -0x18c(%ebp), %eax\n" /* line 359 | iPrevBlend */
        "addl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x144(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x160(%ebp), %edx\n" /* pXAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, %ebx\n" /* pLerpAnim */
        "movl %eax, 4(%esp)\n" /* line 360 */
        "movl -0x164(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm2\n"
        "subss -0x174(%ebp), %xmm2\n" /* fPrevBlend */
        "andps sign+368, %xmm2\n"
        "movl imp_level, %eax\n"
        "cvtsi2ssl 0x1f4(%eax), %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 361 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1bac12_001bbd08\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1bac12_001bbd08:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x174(%ebp), %xmm1\n" /* fPrevBlend */
        "movss %xmm1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* pLerpAnim */
        "movl -0x164(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1bac12_001bb7d2\n"
        ".Lf1bac12_001bbd53:\n"
        "movss -0x140(%ebp), %xmm1\n" /* line 283 */
        "movss %xmm1, -0x178(%ebp)\n" /* fPrevTransZ */
        "jmp .Lf1bac12_001bb61b\n"
        ".Lf1bac12_001bbd68:\n"
        "movl -0x15c(%ebp), %ecx\n" /* line 280 | baseAnim */
        "movl %ecx, 4(%esp)\n"
        "movl -0x160(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetAnimDebugName\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002b59fc, 4(%esp)\n" /* "Player anim '%s' has no children" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1bac12_001bb121\n"
        ".Lf1bac12_001bbd9d:\n"
        "movl -0x154(%ebp), %eax\n" /* line 329 | leafAnim2 */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x1ac(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm2\n"
        "subss -0x13c(%ebp), %xmm2\n"
        "andps sign+368, %xmm2\n"
        "movl imp_level, %eax\n"
        "cvtsi2ssl 0x1f4(%eax), %xmm1\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 330 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1bac12_001bbe04\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1bac12_001bbe04:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x13c(%ebp), %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "movl -0x154(%ebp), %eax\n" /* leafAnim2 */
        "movl %eax, 4(%esp)\n"
        "movl -0x164(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1bac12_001bb709\n"
        /* } scope */
        /* { scope 3: xx, yy, zw, flashTag, ... */
        ".Lf1bac12_001bbe55:\n"
        "leal -0x12c(%ebp), %ecx\n" /* line 182 | axis */
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Weapon_RocketLauncher_Fire\n"
        "jmp .Lf1bac12_001bb524\n"
        /* } scope */
        /* { scope 3: xx, yy, zw, flashTag, ... */
        ".Lf1bac12_001bbe74:\n"
        "movl $str_002b59a8, (%esp)\n" /* line 248 */
        "calll Com_Printf\n"
        "jmp .Lf1bac12_001bade0\n"
        ".Lf1bac12_001bbe85:\n"
        "jp .Lf1bac12_001bb964\n" /* line 386 */
        "movss -0x30(%ebp), %xmm0\n" /* line 1205 */
        "movl 0x158(%esi), %eax\n" /* line 389 */
        "movss -0x3c(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x1c(%eax)\n"
        "jmp .Lf1bac12_001bb964\n"
        /* } scope */
        /* { scope 3: xx, yy, zw, flashTag, ... */
        /* { scope 4 */
        ".Lf1bac12_001bbeb1:\n"
        "movzwl 0x168(%edi), %eax\n" /* line 141 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b5a20, 8(%esp)\n" /* "tag_flash" */
        "movl $str_002b5a2c, 4(%esp)\n" /* "Couldn't find %s on turret (entity %d, classname '%s').
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1bac12_001bb3e6\n"
        /* } scope */
        ".Lf1bac12_001bbeeb:\n"
        "leal 0x8bba0(%edx), %ebx\n" /* line 170 */
        "jmp .Lf1bac12_001bb3bc\n"
    );
}

