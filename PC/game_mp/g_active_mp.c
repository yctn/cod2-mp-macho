/* ASM dump from: g_active_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_active_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stddef.h>
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static vec3_t range; /* range */

/* Extern functions */
extern void Scr_IsSystemActive(int);
extern void Scr_AddEntity(gentity_t *ent);
extern void Scr_Notify(gentity_t *ent, int stringValue, unsigned int paramcount);
extern void BG_WeaponFireRecoil(playerState_t *ps, float *kickAVel, float *kickAVel_out);
extern void BG_Player_DoControllers(void *obj, gentity_t *self, int *partBits, clientInfo_t *ci, int serverTime);
extern void *Com_GetServerDObj(int entityNum);
extern void SV_GetUsercmd(int clientNum, usercmd_t *ucmd);
extern void ClientThink_real(gentity_t *ent, usercmd_t *ucmd);
extern void G_SetFixedLink(gentity_t *ent, int mode);
extern void G_SetOrigin(gentity_t *ent, const vec_t *origin);
extern void G_SetAngle(gentity_t *ent, const vec_t *angles);
extern void SV_LinkEntity(gentity_t *ent);
extern void SV_UnlinkEntity(gentity_t *ent);

/* External globals */
extern gentity_t g_entities[];
extern entityHandler_t entityHandlers[20];
extern struct level_locals_t level;
extern const dvar_t *g_synchronousClients;

/*
 * gclient_t field offsets (from binary):
 *   0x0000  ps (playerState_t, 0x26A8 bytes)
 *   0x26A8  sess.sessionState
 *   0x26AC  sess.forceSpectatorClient
 *   0x26C8  sess.cmd (usercmd_t, 28 bytes)
 *   0x26CC  sess.cmd.buttons
 *   0x26E0  sess.cmd.forwardmove (byte)
 *   0x26E4  sess.oldcmd
 *   0x2700  sess.localClient
 *   0x2740  sess.noSpectate
 *   0x27A8  spectatorClient
 *   0x27AC  noclip
 *   0x27B0  ufo
 *   0x27B4  bFrozen
 *   0x27B8  buttons
 *   0x27BC  oldbuttons
 *   0x27C0  latched_buttons
 *   0x27C4  buttonsSinceLastFrame
 *   0x27CC  oldOrigin (vec3)
 *   0x288C  vGunSpeed (vec3)
 *   0x289C  lastServerTime
 */

/* gclient_t field access macros */
#define _GC(c)                      ((gclient_t *)(c))
#define GACTIVE_PMFLAGS_BYTE2_0X80  0x00800000
#define CLIENT_SESS_STATE(c)        (_GC(c)->sess.sessionState)
#define CLIENT_SESS_NOSPECTATE(c)   (_GC(c)->sess.noSpectate)
#define CLIENT_SESS_CMD(c)          (&_GC(c)->sess.cmd)
#define CLIENT_UFO(c)               (_GC(c)->ufo)
#define CLIENT_BFROZEN(c)           (_GC(c)->bFrozen)
#define CLIENT_LASTSERVERTIME(c)    (_GC(c)->lastServerTime)
#define CLIENT_PS_FLAGS(c)          (_GC(c)->ps.pm_flags)
#define CLIENT_PS_PM_TYPE(c)        (_GC(c)->ps.pm_type)
#define CLIENT_VGUNSPEED(c)         (_GC(c)->vGunSpeed)

void ClientImpacts(gentity_t *ent, pmove_t *pm);
qboolean G_ClientCanSpectateTeam(gclient_t *client, team_t team);
qboolean ClientInactivityTimer(gclient_t *client);
void G_SetLastServerTime(int clientNum, int lastServerTime);
void G_SetClientContents(gentity_t *pEnt);
qboolean GetFollowPlayerState(int clientNum, playerState_t *ps);
void G_PlayerController(gentity_t *self, int *partBits);
void G_PlayerEvent(int clientNum, int event);
void SpectatorThink(gentity_t *ent, usercmd_t *ucmd);
void SpectatorClientEndFrame(gentity_t *ent);
void G_TouchTriggers(gentity_t *ent);
void ClientEvents(gentity_t *ent, int oldEventSequence);
void P_DamageFeedback(gentity_t *player);
qboolean StuckInClient(gentity_t *self);
static void G_PlayerStateToEntityStateExtrapolate(qboolean snap);
void G_RunClient(gentity_t *ent);
void ClientThink(int clientNum);
void ClientEndFrame(gentity_t *ent);

/* line 119 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ClientImpacts(gentity_t *ent, pmove_t *pm)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 119 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 126 | ent */
        "movzbl 0x166(%edx), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl imp_entityHandlers, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* entTouch */
        "movl 0xc(%ebp), %eax\n" /* line 128 | pm */
        "movl 0x40(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1a01f2_001a02e7\n"
        "movl %eax, -0x1c(%ebp)\n"
        "xorl %edi, %edi\n" /* i */
        "movl 0x44(%eax), %ebx\n"
        ".Lf1a01f2_001a022d:\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* line 141 */
        "leal (, %eax, 8), %esi\n" /* other */
        "subl %eax, %esi\n" /* other */
        "shll $4, %esi\n" /* other */
        "addl imp_g_entities, %esi\n" /* other */
        "movl $1, (%esp)\n" /* line 143 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "jne .Lf1a01f2_001a02fc\n"
        ".Lf1a01f2_001a0256:\n"
        "movzbl 0x166(%esi), %eax\n" /* line 153 | other */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl imp_entityHandlers, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 154 */
        "je .Lf1a01f2_001a0284\n"
        "movl $1, 8(%esp)\n" /* line 155 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* other */
        "calll *%eax\n"
        ".Lf1a01f2_001a0284:\n"
        "movl -0x20(%ebp), %eax\n" /* line 157 | entTouch */
        "testl %eax, %eax\n"
        "je .Lf1a01f2_001a02a0\n"
        "movl $1, 8(%esp)\n" /* line 158 */
        "movl %esi, 4(%esp)\n" /* other */
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll *-0x20(%ebp)\n" /* entTouch */
        ".Lf1a01f2_001a02a0:\n"
        "addl $1, %edi\n" /* line 128 | i */
        "addl $4, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* pm */
        "cmpl 0x40(%edx), %edi\n" /* i */
        "jge .Lf1a01f2_001a02e7\n"
        ".Lf1a01f2_001a02af:\n"
        "cmpl $0, %edi\n" /* line 130 | i */
        "jle .Lf1a01f2_001a02ef\n"
        "movl -0x1c(%ebp), %eax\n" /* line 132 */
        "movl 0x44(%eax), %ebx\n"
        "cmpl %ebx, 0x44(%edx)\n"
        "je .Lf1a01f2_001a02a0\n"
        "movl %edx, %ecx\n" /* line 134 */
        "xorl %edx, %edx\n"
        ".Lf1a01f2_001a02c3:\n"
        "addl $1, %edx\n" /* line 130 */
        "cmpl %edi, %edx\n" /* i */
        "je .Lf1a01f2_001a022d\n"
        "movl 0x48(%ecx), %eax\n" /* line 132 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "jne .Lf1a01f2_001a02c3\n"
        "addl $1, %edi\n" /* line 128 | i */
        "addl $4, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* pm */
        "cmpl 0x40(%edx), %edi\n" /* i */
        "jl .Lf1a01f2_001a02af\n"
        /* } scope */
        ".Lf1a01f2_001a02e7:\n"
        "addl $0x2c, %esp\n" /* line 161 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a01f2_001a02ef:\n"
        "jne .Lf1a01f2_001a02a0\n" /* line 137 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 0x44(%edx), %ebx\n"
        "jmp .Lf1a01f2_001a022d\n"
        ".Lf1a01f2_001a02fc:\n"
        "movl %esi, (%esp)\n" /* line 146 | other */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 147 */
        "movl imp_scr_const, %ebx\n"
        "movzwl 0x52(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll Scr_Notify\n"
        "movl 8(%ebp), %edx\n" /* line 149 | ent */
        "movl %edx, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 150 */
        "movzwl 0x52(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* other */
        "calll Scr_Notify\n"
        "jmp .Lf1a01f2_001a0256\n"
    );
}

/* line 1191 */
qboolean G_ClientCanSpectateTeam(gclient_t *client, team_t team)
{
    return !((CLIENT_SESS_NOSPECTATE(client) >> team) & 1);
}

/* line 312 */
__attribute__((naked))
qboolean ClientInactivityTimer(gclient_t *client)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 312 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* client */
        "movl imp_g_inactivity, %eax\n" /* line 314 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1a0368_001a03ad\n"
        "movl imp_level, %eax\n" /* line 318 */
        "movl 0x1ec(%eax), %eax\n"
        "addl $0xea60, %eax\n"
        "movl %eax, 0x2800(%ebx)\n" /* client */
        "movl $0, 0x2804(%ebx)\n" /* line 319 | client */
        "movl $1, %eax\n"
        ".Lf1a0368_001a03a6:\n"
        "addl $0x10, %esp\n" /* line 340 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1a0368_001a03ad:\n"
        "cmpw $0, 0x26e0(%ebx)\n" /* line 321 | client */
        "je .Lf1a0368_001a03eb\n"
        ".Lf1a0368_001a03b7:\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 323 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl imp_level, %edx\n"
        "movl 0x1ec(%edx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, 0x2800(%ebx)\n" /* client */
        "movl $0, 0x2804(%ebx)\n" /* line 324 | client */
        "movl $1, %eax\n"
        "addl $0x10, %esp\n" /* line 340 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1a0368_001a03eb:\n"
        "testl $0x401, 0x26cc(%ebx)\n" /* line 321 | client */
        "jne .Lf1a0368_001a03b7\n"
        "movl 0x2700(%ebx), %esi\n" /* line 326 | client */
        "testl %esi, %esi\n"
        "jne .Lf1a0368_001a048b\n"
        "movl imp_level, %esi\n" /* line 328 */
        "movl 0x1ec(%esi), %edx\n"
        "movl 0x2800(%ebx), %eax\n" /* client */
        "cmpl %eax, %edx\n"
        "jg .Lf1a0368_001a0495\n"
        "subl $0x2710, %eax\n" /* line 333 */
        "cmpl %eax, %edx\n"
        "jle .Lf1a0368_001a048b\n"
        "movl 0x2804(%ebx), %ecx\n" /* client */
        "testl %ecx, %ecx\n"
        "jne .Lf1a0368_001a048b\n"
        "movl $1, 0x2804(%ebx)\n" /* line 335 | client */
        "movl $0x63, 4(%esp)\n" /* line 336 */
        "movl $str_002b3544, (%esp)\n" /* "%c "GAME_INACTIVEDROPWARNING"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, %edx\n" /* client */
        "subl (%esi), %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $9, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $7, %eax\n"
        "addl %edx, %eax\n"
        "shll $9, %eax\n"
        "addl %edx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl $1, %eax\n"
        "jmp .Lf1a0368_001a03a6\n"
        ".Lf1a0368_001a048b:\n"
        "movl $1, %eax\n"
        "jmp .Lf1a0368_001a03a6\n"
        ".Lf1a0368_001a0495:\n"
        "movl $str_002b3528, 4(%esp)\n" /* line 330 */
        "movl %ebx, %edx\n" /* client */
        "subl (%esi), %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $9, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $7, %eax\n"
        "addl %edx, %eax\n"
        "shll $9, %eax\n"
        "addl %edx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameDropClient\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1a0368_001a03a6\n"
    );
}

/* line 479 */
void G_SetLastServerTime(int clientNum, int lastServerTime)
{
    gentity_t *ent = &g_entities[clientNum];
    gclient_t *client;
    int levelTime = level.time;

    /* Clamp lastServerTime to within 1000ms of level.time */
    if (levelTime - lastServerTime >= 1001)
        lastServerTime = levelTime - 1000;

    client = ent->client;

    /* Only update if lastServerTime moves forward or is at/past level.time */
    if (lastServerTime >= CLIENT_LASTSERVERTIME(client) || lastServerTime >= levelTime)
        CLIENT_LASTSERVERTIME(client) = lastServerTime;
}

/* line 504 */
void G_SetClientContents(gentity_t *pEnt)
{
    gclient_t *client = pEnt->client;

    if (CLIENT_UFO(client) || CLIENT_BFROZEN(client)) {
        pEnt->r.contents = 0;
        return;
    }

    /* SESS_STATE_DEAD = 1 -> contents = 0, else CONTENTS_BODY (0x2000000) */
    if (CLIENT_SESS_STATE(client) == SESS_STATE_DEAD)
        pEnt->r.contents = 0;
    else
        pEnt->r.contents = 0x2000000;
}

/* line 1203 */
qboolean GetFollowPlayerState(int clientNum, playerState_t *ps)
{
    gentity_t *ent = &g_entities[clientNum];
    gclient_t *client = ent->client;

    /* The binary checks byte 2 bit 0x80, which maps to pm_flags bit 0x00800000. */
    if (!(CLIENT_PS_FLAGS(client) & GACTIVE_PMFLAGS_BYTE2_0X80))
        return 0;

    memcpy(ps, &client->ps, sizeof(client->ps));

    /* Zero everything from ps.hud onward. */
    memset(&ps->hud, 0, sizeof(*ps) - offsetof(playerState_t, hud));

    return 1;
}

/* line 1317 */
__attribute__((naked))
void G_PlayerController(gentity_t *self, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1317 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* self */
        /* { scope 1 */
        "movl 0x90(%esi), %eax\n" /* line 1323 | self */
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %ebx\n" /* ci */
        "shll $4, %ebx\n" /* ci */
        "subl %edx, %ebx\n" /* ci */
        "leal (%eax, %ebx, 2), %ebx\n" /* ci */
        "movl imp_level_bgs, %edx\n"
        "leal 0xb3bfc(%edx, %ebx, 8), %ebx\n" /* ci */
        "movl imp_bgs, %eax\n" /* line 1326 */
        "movl %edx, (%eax)\n"
        "movl imp_level, %eax\n" /* line 1327 */
        "movl 0x1f4(%eax), %edi\n"
        "movl (%esi), %eax\n" /* self */
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %edi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* ci */
        "movl 0xc(%ebp), %edx\n" /* partBits */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* self */
        "movl %eax, (%esp)\n"
        "calll BG_Player_DoControllers\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1328 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1600 */
void G_PlayerEvent(int clientNum, int event)
{
    gentity_t *ent = &g_entities[clientNum];
    gclient_t *client = ent->client;
    vec3_t kickAVel;
    int idx;

    /* Check if event is a weapon fire event (0x9E..0xAF range, specific bits) */
    idx = event - 0x9E;
    if ((unsigned)idx > 0x11)
        return;
    if (!((1 << idx) & 0x20007))
        return;

    /* Call BG_WeaponFireRecoil(ps, kickAVel_in, kickAVel_out). */
    BG_WeaponFireRecoil(&client->ps, CLIENT_VGUNSPEED(client), kickAVel);
}

/* line 249 */
__attribute__((naked))
void SpectatorThink(gentity_t *ent, usercmd_t *ucmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* ucmd */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 254 | ent */
        "movl 0x158(%eax), %esi\n" /* client */
        "movl 0x27bc(%esi), %edx\n" /* line 256 | client */
        "movl %edx, %ecx\n"
        "movl %edx, 0x27c0(%esi)\n" /* client */
        "movl 0x26cc(%esi), %edx\n" /* line 257 | client */
        "movl %edx, 0x27bc(%esi)\n" /* client */
        "movl %ecx, %eax\n" /* line 258 */
        "notl %eax\n"
        "andl %edx, %eax\n"
        "orl %eax, 0x27c8(%esi)\n" /* client */
        "movl 0x26ac(%esi), %eax\n" /* line 260 | client */
        "testl %eax, %eax\n"
        "js .Lf1a06a4_001a0809\n"
        ".Lf1a06a4_001a06f0:\n"
        "testb $1, %dl\n" /* line 269 */
        "je .Lf1a06a4_001a0702\n"
        "testb $1, 0x27c0(%esi)\n" /* client */
        "je .Lf1a06a4_001a084a\n"
        ".Lf1a06a4_001a0702:\n"
        "andb $0x10, %dh\n" /* line 272 */
        "jne .Lf1a06a4_001a07e4\n"
        ".Lf1a06a4_001a070b:\n"
        "testb $0x40, 0xe(%esi)\n" /* line 275 | client */
        "jne .Lf1a06a4_001a07d9\n"
        "movl $4, 4(%esi)\n" /* line 278 | client */
        "movl 0x2740(%esi), %eax\n" /* line 280 | client */
        "sarl $4, %eax\n"
        "xorl $1, %eax\n"
        "andl $1, %eax\n"
        "negl %eax\n" /* line 282 */
        "andl $0x190, %eax\n"
        "movl %eax, 0x50(%esi)\n" /* client */
        "leal -0x110(%ebp), %ebx\n" /* line 290 | pm */
        "movl $0xf8, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        "movl %esi, -0x110(%ebp)\n" /* line 291 | client, pm */
        "movl (%edi), %eax\n" /* line 292 | ucmd */
        "movl %eax, -0x10c(%ebp)\n"
        "movl 4(%edi), %eax\n" /* ucmd */
        "movl %eax, -0x108(%ebp)\n"
        "movl 8(%edi), %eax\n" /* ucmd */
        "movl %eax, -0x104(%ebp)\n"
        "movl 0xc(%edi), %eax\n" /* ucmd */
        "movl %eax, -0x100(%ebp)\n"
        "movl 0x10(%edi), %eax\n" /* ucmd */
        "movl %eax, -0xfc(%ebp)\n"
        "movl 0x14(%edi), %eax\n" /* ucmd */
        "movl %eax, -0xf8(%ebp)\n"
        "movl 0x18(%edi), %eax\n" /* ucmd */
        "movl %eax, -0xf4(%ebp)\n"
        "movl $0x00800811, -0xd4(%ebp)\n" /* line 293 */
        "movb $1, -0x2c(%ebp)\n" /* line 294 */
        "movl %ebx, (%esp)\n" /* line 296 */
        "calll Pmove\n"
        "movl 8(%ebp), %ecx\n" /* line 299 | ent, to */
        "addl $0x138, %ecx\n" /* to */
        "leal 0x14(%esi), %edx\n" /* client, from */
        /* { scope 2 */
        "movl 0x14(%esi), %eax\n" /* line 199 */
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl %eax, 0x138(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 301 */
        "calll SV_UnlinkEntity\n"
        /* } scope */
        ".Lf1a06a4_001a07d9:\n"
        "addl $0x11c, %esp\n" /* line 302 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a06a4_001a07e4:\n"
        "testb $0x10, 0x27c1(%esi)\n" /* line 272 | client */
        "jne .Lf1a06a4_001a070b\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 273 */
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl %ebx, (%esp)\n"
        "calll Cmd_FollowCycle_f\n"
        "jmp .Lf1a06a4_001a070b\n"
        ".Lf1a06a4_001a0809:\n"
        "testb $0x10, 0x2740(%esi)\n" /* line 260 | client */
        "jne .Lf1a06a4_001a06f0\n"
        "movl 0x27a8(%esi), %eax\n" /* line 263 | client */
        "testl %eax, %eax\n"
        "js .Lf1a06a4_001a06f0\n"
        "movl %edx, %eax\n"
        "andl $4, %eax\n"
        "andl $4, %ecx\n"
        "cmpl %ecx, %eax\n"
        "je .Lf1a06a4_001a06f0\n"
        "movl 8(%ebp), %ebx\n" /* line 264 | ent */
        "movl %ebx, (%esp)\n"
        "calll StopFollowing\n"
        "movl 0x27bc(%esi), %edx\n" /* client */
        "jmp .Lf1a06a4_001a06f0\n"
        ".Lf1a06a4_001a084a:\n"
        "movl $1, 4(%esp)\n" /* line 270 */
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll Cmd_FollowCycle_f\n"
        "jmp .Lf1a06a4_001a070b\n"
    );
}

/* line 1068 */
__attribute__((naked))
void SpectatorClientEndFrame(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1068 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x272c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1078 | ent */
        "movl 0x158(%eax), %esi\n" /* client */
        "movl %eax, %edx\n" /* line 1080 */
        "movzbl 0xf2(%eax), %eax\n"
        "andb $0xfd, %al\n"
        "orb $1, %al\n" /* line 1081 */
        "movb %al, 0xf2(%edx)\n"
        "movb $0, 0x161(%edx)\n" /* line 1082 */
        "movl $0, 0x11c(%edx)\n" /* line 1083 */
        "andl $0xff7fffff, 0xc(%esi)\n" /* line 1084 | client */
        "movl $5, 4(%edx)\n" /* line 1085 */
        "movl $0, 0xe4(%esi)\n" /* line 1087 | client */
        "xorl %eax, %eax\n" /* line 1089 */
        "movl %eax, 0x27d8(%esi)\n" /* client */
        "movl %eax, 0x27dc(%esi)\n" /* line 1090 | client */
        "movl 0x26ac(%esi), %eax\n" /* line 1092 | client */
        "testl %eax, %eax\n"
        "js .Lf1a0862_001a0960\n"
        "movl %eax, 0x27a8(%esi)\n" /* line 1095 | client */
        "leal -0x78(%ebp), %edi\n" /* cs */
        "leal -0x1c(%ebp), %ebx\n" /* psTime, flags */
        "jmp .Lf1a0862_001a0936\n"
        ".Lf1a0862_001a08dd:\n"
        "movl 0x26b4(%esi), %eax\n" /* line 1101 | client */
        "subl 0x27a4(%esi), %eax\n" /* client */
        "movl %eax, -0x1c(%ebp)\n" /* psTime */
        "movl %edi, 0xc(%esp)\n" /* line 1102 */
        "leal -0x2720(%ebp), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* flags */
        "movl 0x26ac(%esi), %eax\n" /* client */
        "movl %eax, (%esp)\n"
        "calll SV_GetArchivedClientInfo\n"
        "testl %eax, %eax\n"
        "je .Lf1a0862_001a0923\n"
        "movl -0x74(%ebp), %ecx\n" /* line 1105 */
        "movl 0x2740(%esi), %eax\n" /* client */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1a0862_001a0a04\n"
        ".Lf1a0862_001a0923:\n"
        "movl 0x26b4(%esi), %eax\n" /* line 1108 | client */
        "testl %eax, %eax\n"
        "je .Lf1a0862_001a094c\n"
        "subl $0x32, %eax\n" /* line 1114 */
        "movl %eax, 0x26b4(%esi)\n" /* client */
        ".Lf1a0862_001a0936:\n"
        "movl 0x26b4(%esi), %eax\n" /* line 1099 | client */
        "testl %eax, %eax\n"
        "jns .Lf1a0862_001a08dd\n"
        "movl $0, 0x26b4(%esi)\n" /* line 1100 | client */
        "jmp .Lf1a0862_001a08dd\n"
        ".Lf1a0862_001a094c:\n"
        "movl $0xffffffff, 0x26ac(%esi)\n" /* line 1110 | client */
        "movl $0xffffffff, 0x27a8(%esi)\n" /* line 1111 | client */
        ".Lf1a0862_001a0960:\n"
        "movl 0x27a8(%esi), %ebx\n" /* line 1118 | client, flags */
        "testl %ebx, %ebx\n" /* flags */
        "js .Lf1a0862_001a0a86\n"
        ".Lf1a0862_001a096e:\n"
        "movl 0x27a8(%esi), %edx\n" /* line 1121 | client */
        "testl %edx, %edx\n" /* line 1124 */
        "js .Lf1a0862_001a09ab\n"
        "movl 0x26b4(%esi), %eax\n" /* line 1126 | client */
        "addl 0x27a4(%esi), %eax\n" /* client */
        "movl %eax, -0x1c(%ebp)\n" /* psTime */
        "leal -0x78(%ebp), %eax\n" /* line 1127 | cs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x2720(%ebp), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* psTime */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SV_GetArchivedClientInfo\n"
        "testl %eax, %eax\n"
        "jne .Lf1a0862_001a09f5\n"
        ".Lf1a0862_001a09ab:\n"
        "movl 8(%ebp), %eax\n" /* line 1169 | ent */
        "movl %eax, (%esp)\n"
        "calll StopFollowing\n"
        "movl 0xc(%esi), %ecx\n" /* line 1176 | client */
        "movl %ecx, %edx\n"
        "andl $0xfdffffff, %edx\n"
        "movl %edx, 0xc(%esi)\n" /* client */
        "movl 0x2740(%esi), %eax\n" /* line 1193 | client */
        "testb $4, %al\n" /* line 1178 */
        "jne .Lf1a0862_001a09e2\n"
        ".Lf1a0862_001a09ce:\n"
        "orl $0x01000000, %edx\n" /* line 1179 */
        "movl %edx, 0xc(%esi)\n" /* client */
        /* } scope */
        ".Lf1a0862_001a09d7:\n"
        "addl $0x272c, %esp\n" /* line 1182 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a0862_001a09e2:\n"
        "testb $2, %al\n" /* line 1178 */
        "je .Lf1a0862_001a09ce\n"
        "testb $1, %al\n"
        "je .Lf1a0862_001a09ce\n"
        "andl $0xfcffffff, %ecx\n" /* line 1181 */
        "movl %ecx, 0xc(%esi)\n" /* client */
        "jmp .Lf1a0862_001a09d7\n"
        ".Lf1a0862_001a09f5:\n"
        "movl -0x74(%ebp), %ecx\n" /* line 1130 */
        "movl 0x2740(%esi), %eax\n" /* client */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1a0862_001a09ab\n"
        ".Lf1a0862_001a0a04:\n"
        "movl -0x2680(%ebp), %ebx\n" /* line 1134 | flags */
        "andl $0xffefffff, %ebx\n" /* flags */
        "movl 0xa0(%esi), %eax\n" /* client */
        "andl $0x100000, %eax\n"
        "orl %eax, %ebx\n" /* flags */
        "movl $0x26a8, 8(%esp)\n" /* line 1136 */
        "leal -0x2720(%ebp), %edx\n" /* ps */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* client */
        "calll memcpy\n"
        "movl $2, 8(%esp)\n" /* line 1137 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* client */
        "calll HudElem_UpdateClient\n"
        "movl %ebx, 0xa0(%esi)\n" /* line 1140 | flags, client */
        "movl 0xc(%esi), %edx\n" /* line 1142 | client */
        "andl $0xff7fffff, %edx\n"
        "movl %edx, %eax\n" /* line 1143 */
        "orl $0x00400000, %eax\n"
        "movl %eax, 0xc(%esi)\n" /* client */
        "movl 0x26ac(%esi), %ecx\n" /* line 1145 | client */
        "testl %ecx, %ecx\n"
        "js .Lf1a0862_001a0aab\n"
        "andl $0xfcffffff, %eax\n" /* line 1148 */
        "movl %eax, 0xc(%esi)\n" /* client */
        /* } scope */
        "addl $0x272c, %esp\n" /* line 1182 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a0862_001a0a86:\n"
        "testb $0x10, 0x2740(%esi)\n" /* line 1118 | client */
        "je .Lf1a0862_001a096e\n"
        "movl $1, 4(%esp)\n" /* line 1119 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll Cmd_FollowCycle_f\n"
        "jmp .Lf1a0862_001a096e\n"
        ".Lf1a0862_001a0aab:\n"
        "movl %edx, %eax\n" /* line 1156 */
        "orl $0x1400000, %eax\n"
        "movl %eax, 0xc(%esi)\n" /* client */
        "testb $0x10, 0x2740(%esi)\n" /* line 1158 | client */
        "je .Lf1a0862_001a0acb\n"
        "andl $0xfdffffff, %eax\n" /* line 1161 */
        "movl %eax, 0xc(%esi)\n" /* client */
        "jmp .Lf1a0862_001a09d7\n"
        ".Lf1a0862_001a0acb:\n"
        "orl $0x3400000, %edx\n" /* line 1159 */
        "movl %edx, 0xc(%esi)\n" /* client */
        "jmp .Lf1a0862_001a09d7\n"
    );
}

/* line 172 */
__attribute__((naked))
void G_TouchTriggers(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 172 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x105c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 186 | ent */
        "movl 0x158(%eax), %edx\n"
        "cmpl $1, 4(%edx)\n"
        "jle .Lf1a0ada_001a0b00\n"
        /* } scope */
        ".Lf1a0ada_001a0af5:\n"
        "addl $0x105c, %esp\n" /* line 241 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a0ada_001a0b00:\n"
        "leal 0x14(%edx), %eax\n" /* line 189 */
        /* { scope 2 */
        "movss range, %xmm3\n" /* line 248 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* mins */
        "movss range+4, %xmm2\n" /* line 249 */
        "movss 4(%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss range+8, %xmm1\n" /* line 250 */
        "movss 8(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "addss 0x14(%edx), %xmm3\n" /* line 240 */
        "movss %xmm3, -0x30(%ebp)\n" /* maxs */
        "addss 4(%eax), %xmm2\n" /* line 241 */
        "movss %xmm2, -0x2c(%ebp)\n"
        "addss 8(%eax), %xmm1\n" /* line 242 */
        "movss %xmm1, -0x28(%ebp)\n"
        "movl $0x405c0008, 0x10(%esp)\n" /* line 195 */
        "movl $0x400, 0xc(%esp)\n"
        "leal -0x1030(%ebp), %eax\n" /* touch */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* maxs */
        "movl %edx, 4(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* mins */
        "movl %ecx, (%esp)\n"
        "calll CM_AreaEntities\n"
        "movl %eax, -0x1040(%ebp)\n" /* num */
        "movl 8(%ebp), %ebx\n" /* ent, i */
        "movl 0x158(%ebx), %eax\n" /* i */
        "leal 0x14(%eax), %edx\n"
        "movl %ebx, %ecx\n" /* i */
        "addl $0x104, %ecx\n"
        /* { scope 2 */
        "movss 0x14(%eax), %xmm0\n" /* line 240 */
        "addss 0x104(%ebx), %xmm0\n" /* i */
        "movss %xmm0, -0x24(%ebp)\n" /* mins */
        "movss 4(%edx), %xmm0\n" /* line 241 */
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 242 */
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "addl $0xc, %ecx\n"
        /* } scope */
        /* { scope 2 */
        "movss 0x14(%eax), %xmm0\n" /* line 240 */
        "addss 0x110(%ebx), %xmm0\n" /* i */
        "movss %xmm0, -0x30(%ebp)\n" /* maxs */
        "movss 4(%edx), %xmm0\n" /* line 241 */
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 242 */
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "leal -0x30(%ebp), %eax\n" /* line 201 | maxs */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* mins */
        "movl %edx, (%esp)\n"
        "calll ShrinkBoundsToHeight\n"
        "movl imp_entityHandlers, %edx\n" /* line 203 */
        "movzbl 0x166(%ebx), %eax\n" /* i */
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0xc(%edx, %eax, 8), %eax\n"
        "movl %eax, -0x103c(%ebp)\n" /* entTouch */
        "movl -0x1040(%ebp), %eax\n" /* line 205 | num */
        "testl %eax, %eax\n"
        "jle .Lf1a0ada_001a0af5\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf1a0ada_001a0ca5\n"
        ".Lf1a0ada_001a0c4a:\n"
        "movl %esi, 8(%esp)\n" /* line 223 | hit */
        "leal -0x30(%ebp), %eax\n" /* maxs */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* mins */
        "movl %edx, (%esp)\n"
        "calll SV_EntityContact\n"
        "testl %eax, %eax\n"
        "je .Lf1a0ada_001a0c90\n"
        "movl $1, (%esp)\n" /* line 227 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "jne .Lf1a0ada_001a0d1d\n"
        ".Lf1a0ada_001a0c78:\n"
        "testl %edi, %edi\n" /* line 236 | hitTouch */
        "je .Lf1a0ada_001a0c90\n"
        "movl $1, 8(%esp)\n" /* line 237 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* hit */
        "calll *%edi\n" /* hitTouch */
        ".Lf1a0ada_001a0c90:\n"
        "addl $1, %ebx\n" /* line 205 | i */
        "cmpl %ebx, -0x1040(%ebp)\n" /* i, num */
        "je .Lf1a0ada_001a0af5\n"
        "movl imp_entityHandlers, %edx\n"
        ".Lf1a0ada_001a0ca5:\n"
        "movl -0x1030(%ebp, %ebx, 4), %eax\n" /* line 207 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n" /* hit */
        "subl %eax, %esi\n" /* hit */
        "shll $4, %esi\n" /* hit */
        "addl imp_g_entities, %esi\n" /* hit */
        "movzbl 0x166(%esi), %eax\n" /* line 210 | hit */
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0xc(%edx, %eax, 8), %edi\n" /* hitTouch */
        "testl %edi, %edi\n" /* line 211 | hitTouch */
        "je .Lf1a0ada_001a0d74\n"
        ".Lf1a0ada_001a0cd7:\n"
        "cmpl $3, 4(%esi)\n" /* line 216 | hit */
        "jne .Lf1a0ada_001a0c4a\n"
        "movl imp_level, %eax\n" /* line 218 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* hit */
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl 0x158(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_PlayerTouchesItem\n"
        "testl %eax, %eax\n"
        "je .Lf1a0ada_001a0c90\n"
        "movl $1, (%esp)\n" /* line 227 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf1a0ada_001a0c78\n"
        ".Lf1a0ada_001a0d1d:\n"
        "movl 8(%ebp), %ecx\n" /* line 230 | ent */
        "movl %ecx, (%esp)\n"
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 231 */
        "movl imp_scr_const, %edx\n"
        "movzwl 0x52(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* hit */
        "calll Scr_Notify\n"
        "movl %esi, (%esp)\n" /* line 232 | hit */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 233 */
        "movl imp_scr_const, %ecx\n"
        "movzwl 0x52(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll Scr_Notify\n"
        "jmp .Lf1a0ada_001a0c78\n"
        ".Lf1a0ada_001a0d74:\n"
        "movl -0x103c(%ebp), %eax\n" /* line 211 | entTouch */
        "testl %eax, %eax\n"
        "jne .Lf1a0ada_001a0cd7\n"
        "jmp .Lf1a0ada_001a0c90\n"
    );
}

/* line 369 */
__attribute__((naked))
void ClientEvents(gentity_t *ent, int oldEventSequence)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 369 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        "movl 0xc(%ebp), %edx\n" /* oldEventSequence */
        /* { scope 1 */
        "movl 0x158(%edi), %esi\n" /* line 378 | ent, client */
        "movl 0xa4(%esi), %eax\n" /* line 380 | client */
        "leal -4(%eax), %ecx\n"
        "cmpl %edx, %ecx\n"
        "cmovlel %edx, %ecx\n"
        "cmpl %eax, %ecx\n" /* line 383 */
        "jge .Lf1a0d88_001a0e7c\n"
        "movl %ecx, %ebx\n" /* i */
        "jmp .Lf1a0d88_001a0e4b\n"
        ".Lf1a0d88_001a0dba:\n"
        "cmpl $1, 4(%edi)\n" /* line 390 | ent */
        "jne .Lf1a0d88_001a0e7c\n"
        "cmpl $0x63, %ecx\n" /* line 393 */
        "jg .Lf1a0d88_001a0e84\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 396 */
        "mulss lit4_002ed738, %xmm1\n" /* 0.009999999776482582f */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 398 | 0.0f */
        "jp .Lf1a0d88_001a0de4\n"
        "je .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0de4:\n"
        "movl $0, 0x24(%esp)\n" /* line 403 */
        "movl $0, 0x20(%esp)\n"
        "movl $0xb, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "cvtsi2ssl 0x134(%esi), %xmm0\n" /* client */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_Damage\n"
        ".Lf1a0d88_001a0e40:\n"
        "addl $1, %ebx\n" /* line 383 | i */
        "cmpl 0xa4(%esi), %ebx\n" /* client, i */
        "jge .Lf1a0d88_001a0e7c\n"
        ".Lf1a0d88_001a0e4b:\n"
        "movl %ebx, %eax\n" /* line 385 | i */
        "andl $3, %eax\n"
        "movl 0xa8(%esi, %eax, 4), %edx\n" /* client */
        "movl 0xb8(%esi, %eax, 4), %ecx\n" /* line 386 | client */
        "leal -0x74(%edx), %eax\n" /* line 388 */
        "cmpl $0x16, %eax\n"
        "jbe .Lf1a0d88_001a0dba\n"
        "leal -0x9e(%edx), %eax\n" /* line 409 */
        "cmpl $0x27, %eax\n"
        "ja .Lf1a0d88_001a0e40\n"
        "jmpl *.Ljt_1a0d88_0(, %eax, 4)\n"
        /* } scope */
        ".Lf1a0d88_001a0e7c:\n"
        "addl $0x3c, %esp\n" /* line 477 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a0d88_001a0e84:\n"
        "movss lit4_002ed808, %xmm1\n" /* line 393 | 1.100000023841858f */
        "jmp .Lf1a0d88_001a0de4\n"
        ".Lf1a0d88_001a0e91:\n"
        "movl %edi, (%esp)\n" /* line 426 | ent */
        "calll FireWeaponMelee\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0e9b:\n"
        "movl 0x158(%edi), %eax\n" /* line 465 | ent */
        "testl %eax, %eax\n"
        "je .Lf1a0d88_001a0e40\n"
        "testb $3, 0x174(%edi)\n" /* line 468 | ent */
        "jne .Lf1a0d88_001a0e40\n"
        "movl $0, 0x194(%edi)\n" /* line 471 | ent */
        "movl $0, 0x12c(%eax)\n"
        "movl $0, 0x20(%esp)\n" /* line 472 */
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0xc, 0x10(%esp)\n"
        "movl $0x186a0, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* ent */
        "movl %edi, 4(%esp)\n" /* ent */
        "movl %edi, (%esp)\n" /* ent */
        "calll player_die\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0f07:\n"
        "movl imp_g_antilag, %eax\n" /* line 415 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1a0d88_001a0feb\n"
        "movl imp_level, %eax\n" /* line 421 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll FireWeaponAntiLag\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0f34:\n"
        "movl $0, 8(%esp)\n" /* line 461 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x6a(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll Scr_Notify\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0f56:\n"
        "movl $0, 8(%esp)\n" /* line 456 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x68(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll Scr_Notify\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0f78:\n"
        "movl $0, 8(%esp)\n" /* line 451 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x66(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll Scr_Notify\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0f9a:\n"
        "movl $0, 8(%esp)\n" /* line 446 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x64(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll Scr_Notify\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0fbc:\n"
        "movl $0, 8(%esp)\n" /* line 441 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x62(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll Scr_Notify\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0fde:\n"
        "movl %edi, (%esp)\n" /* line 433 | ent */
        "calll G_UseOffHand\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".Lf1a0d88_001a0feb:\n"
        "movl 0x289c(%esi), %eax\n" /* line 417 | client */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll FireWeaponAntiLag\n"
        "jmp .Lf1a0d88_001a0e40\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_1a0d88_0:\n"
        ".long .Lf1a0d88_001a0f07\n"
        ".long .Lf1a0d88_001a0f07\n"
        ".long .Lf1a0d88_001a0f07\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e91\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0fde\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0fbc\n"
        ".long .Lf1a0d88_001a0f9a\n"
        ".long .Lf1a0d88_001a0f78\n"
        ".long .Lf1a0d88_001a0f56\n"
        ".long .Lf1a0d88_001a0f34\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0f07\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e40\n"
        ".long .Lf1a0d88_001a0e9b\n"
        ".text\n"
    );
}

/* line 26 */
__attribute__((naked))
void P_DamageFeedback(gentity_t *player)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 26 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 34 | player */
        "movl 0x158(%eax), %ebx\n" /* client */
        "cmpl $5, 4(%ebx)\n" /* line 36 | client */
        "jg .Lf1a1002_001a113e\n"
        "movl $0, 0x128(%ebx)\n" /* line 39 | client */
        "movl 0x27e0(%ebx), %eax\n" /* line 42 | client */
        "testl %eax, %eax\n" /* line 43 */
        "jle .Lf1a1002_001a113e\n"
        "movl 0x2728(%ebx), %edx\n" /* client */
        "testl %edx, %edx\n"
        "jle .Lf1a1002_001a113e\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 46 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "movl %edx, %edi\n"
        "cltd\n"
        "idivl %edi\n"
        "movl %eax, %esi\n" /* damage */
        "cmpl $0x7f, %eax\n" /* line 47 */
        "jle .Lf1a1002_001a1146\n"
        "movl $0x7f, %esi\n" /* damage */
        "movss lit4_002ed718, %xmm1\n" /* 127.0f */
        ".Lf1a1002_001a1070:\n"
        "movaps %xmm1, %xmm0\n" /* line 51 */
        "addss 0x5d4(%ebx), %xmm0\n" /* client */
        "movss %xmm0, 0x5d4(%ebx)\n" /* client */
        "ucomiss lit4_002ed5d4, %xmm0\n" /* line 52 | 255.0f */
        "jbe .Lf1a1002_001a1096\n"
        "movl $0x437f0000, 0x5d4(%ebx)\n" /* line 53 | client */
        ".Lf1a1002_001a1096:\n"
        "mulss lit4_002ed724, %xmm1\n" /* line 57 | 0.20000000298023224f */
        "movss %xmm1, -0x50(%ebp)\n" /* kick */
        "ucomiss lit4_002ed6d4, %xmm1\n" /* line 59 | 5.0f */
        "jae .Lf1a1002_001a114f\n"
        "jp .Lf1a1002_001a114f\n"
        "movss lit4_002ed6d4, %xmm0\n" /* 5.0f */
        "movss %xmm0, -0x50(%ebp)\n" /* kick */
        "movss lit4_002ed920, %xmm0\n" /* -5.0f */
        "movss %xmm0, -0x4c(%ebp)\n"
        ".Lf1a1002_001a10d0:\n"
        "movl 0x27f0(%ebx), %eax\n" /* line 66 | client */
        "testl %eax, %eax\n"
        "je .Lf1a1002_001a1179\n"
        ".Lf1a1002_001a10de:\n"
        "movl $0, 0x2844(%ebx)\n" /* line 68 | client */
        "movss -0x4c(%ebp), %xmm0\n" /* line 69 */
        "movss %xmm0, 0x2848(%ebx)\n" /* client */
        "movl $0xff, 0x124(%ebx)\n" /* line 71 | client */
        "movl $0xff, 0x120(%ebx)\n" /* line 72 | client */
        "movl $0, 0x27f0(%ebx)\n" /* line 74 | client */
        ".Lf1a1002_001a1113:\n"
        "addl $1, 0x11c(%ebx)\n" /* line 89 | client */
        "movl imp_level, %eax\n" /* line 90 */
        "movl 0x1ec(%eax), %eax\n"
        "subl $0x14, %eax\n"
        "movl %eax, 0x2840(%ebx)\n" /* client */
        "movl %esi, 0x128(%ebx)\n" /* line 92 | damage, client */
        "movl $0, 0x27e0(%ebx)\n" /* line 97 | client */
        /* } scope */
        ".Lf1a1002_001a113e:\n"
        "addl $0x5c, %esp\n" /* line 98 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a1002_001a1146:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 47 */
        "jmp .Lf1a1002_001a1070\n"
        ".Lf1a1002_001a114f:\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss lit4_002ed5f8, %xmm1\n" /* line 61 | 90.0f */
        "ja .Lf1a1002_001a124f\n"
        "xorps sign+192, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movl 0x27f0(%ebx), %eax\n" /* line 66 | client */
        "testl %eax, %eax\n"
        "jne .Lf1a1002_001a10de\n"
        ".Lf1a1002_001a1179:\n"
        "leal 0x27e4(%ebx), %edx\n" /* line 78 | client */
        "leal -0x24(%ebp), %eax\n" /* angles */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll vectoangles\n"
        "leal -0x48(%ebp), %eax\n" /* line 80 | viewaxis */
        "movl %eax, 4(%esp)\n"
        "leal 0xe8(%ebx), %eax\n" /* client */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movss 0x27e4(%ebx), %xmm1\n" /* line 82 | client */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x3c(%ebp), %xmm0\n"
        "movss 0x27e8(%ebx), %xmm4\n" /* client */
        "movaps %xmm4, %xmm2\n"
        "mulss -0x38(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss 0x27ec(%ebx), %xmm3\n" /* client */
        "movaps %xmm3, %xmm2\n"
        "mulss -0x34(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, 0x2844(%ebx)\n" /* client */
        "mulss -0x48(%ebp), %xmm1\n" /* line 83 | viewaxis */
        "mulss -0x44(%ebp), %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "mulss -0x40(%ebp), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss -0x50(%ebp), %xmm1\n" /* kick */
        "movss %xmm1, 0x2848(%ebx)\n" /* client */
        "movss -0x24(%ebp), %xmm0\n" /* line 85 | angles */
        "movss lit4_002ed638, %xmm2\n" /* 360.0f */
        "divss %xmm2, %xmm0\n"
        "movss lit4_002ed8b0, %xmm1\n" /* 256.0f */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x124(%ebx)\n" /* client */
        "movss -0x20(%ebp), %xmm0\n" /* line 86 */
        "divss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x120(%ebx)\n" /* client */
        "jmp .Lf1a1002_001a1113\n"
        ".Lf1a1002_001a124f:\n"
        "movss lit4_002ed5f8, %xmm0\n" /* line 61 | 90.0f */
        "movss %xmm0, -0x50(%ebp)\n" /* kick */
        "movss lit4_002ed660, %xmm0\n" /* -90.0f */
        "movss %xmm0, -0x4c(%ebp)\n"
        "jmp .Lf1a1002_001a10d0\n"
    );
}

/* line 1225 */
__attribute__((naked))
qboolean StuckInClient(gentity_t *self)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1225 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* self */
        /* { scope 1 */
        "movl 0x158(%ebx), %eax\n" /* line 1236 | self */
        "testb $0x80, 0xe(%eax)\n"
        "je .Lf1a126e_001a12a4\n"
        "movl 0x26a8(%eax), %edx\n" /* line 1238 */
        "testl %edx, %edx\n"
        "jne .Lf1a126e_001a12a4\n"
        "movl 0x11c(%ebx), %eax\n" /* line 1240 | self */
        "cmpl $0x2000000, %eax\n"
        "je .Lf1a126e_001a12ae\n"
        "cmpl $0x4000000, %eax\n"
        "je .Lf1a126e_001a12ae\n"
        ".Lf1a126e_001a12a4:\n"
        "xorl %eax, %eax\n" /* line 1244 */
        /* } scope */
        ".Lf1a126e_001a12a6:\n"
        "addl $0x4c, %esp\n" /* line 1308 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a126e_001a12ae:\n"
        "movl imp_level, %eax\n" /* line 1244 */
        "movl 0x1e4(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf1a126e_001a12a4\n"
        "xorl %ecx, %ecx\n" /* line 1240 */
        "movl imp_g_entities, %edx\n"
        "movl %edx, %esi\n"
        "addl $0xfc, %edx\n"
        ".Lf1a126e_001a12cd:\n"
        "cmpb $0, (%edx)\n" /* line 1246 */
        "je .Lf1a126e_001a1304\n"
        "movl 0x5c(%edx), %eax\n" /* line 1248 */
        "testb $0x80, 0xe(%eax)\n"
        "je .Lf1a126e_001a1304\n"
        "movl 0x26a8(%eax), %eax\n" /* line 1250 */
        "testl %eax, %eax\n"
        "jne .Lf1a126e_001a1304\n"
        "cmpl %esi, %ebx\n" /* line 1252 | self */
        "je .Lf1a126e_001a1304\n"
        "movl 0x98(%edx), %eax\n" /* line 1256 */
        "testl %eax, %eax\n"
        "jle .Lf1a126e_001a1304\n"
        "movl 0x20(%edx), %eax\n" /* line 1258 */
        "cmpl $0x2000000, %eax\n"
        "je .Lf1a126e_001a1319\n"
        "cmpl $0x4000000, %eax\n"
        "je .Lf1a126e_001a1319\n"
        ".Lf1a126e_001a1304:\n"
        "addl $1, %ecx\n" /* line 1244 */
        "addl $0x230, %esi\n"
        "addl $0x230, %edx\n"
        "cmpl %edi, %ecx\n"
        "jne .Lf1a126e_001a12cd\n"
        "jmp .Lf1a126e_001a12a4\n"
        ".Lf1a126e_001a1319:\n"
        "movss 0x24(%edx), %xmm0\n" /* line 1262 */
        "ucomiss 0x12c(%ebx), %xmm0\n" /* self */
        "ja .Lf1a126e_001a1304\n"
        "movss 0x120(%ebx), %xmm0\n" /* line 1264 | self */
        "ucomiss 0x30(%edx), %xmm0\n"
        "ja .Lf1a126e_001a1304\n"
        "movss 0x28(%edx), %xmm0\n" /* line 1266 */
        "ucomiss 0x130(%ebx), %xmm0\n" /* self */
        "ja .Lf1a126e_001a1304\n"
        "movss 0x124(%ebx), %xmm0\n" /* line 1268 | self */
        "ucomiss 0x34(%edx), %xmm0\n"
        "ja .Lf1a126e_001a1304\n"
        "movss 0x2c(%edx), %xmm0\n" /* line 1270 */
        "ucomiss 0x134(%ebx), %xmm0\n" /* self */
        "ja .Lf1a126e_001a1304\n"
        "movss 0x128(%ebx), %xmm0\n" /* line 1272 | self */
        "ucomiss 0x38(%edx), %xmm0\n"
        "ja .Lf1a126e_001a1304\n"
        "movss 0x138(%esi), %xmm0\n" /* line 65 */
        "subss 0x138(%ebx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* vDelta */
        "movss 0x13c(%esi), %xmm1\n" /* line 66 */
        "subss 0x13c(%ebx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movss 0x110(%ebx), %xmm2\n" /* line 1277 | self */
        "addss 0x14(%edx), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 1278 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf1a126e_001a1304\n"
        "movss 0x138(%esi), %xmm1\n" /* line 65 */
        "subss 0x138(%ebx), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* vDelta */
        "movss 0x13c(%esi), %xmm0\n" /* line 66 */
        "subss 0x13c(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss %xmm1, -0x48(%ebp)\n" /* line 1283 */
        "calll crandom\n"
        "fstps -0x34(%ebp)\n"
        "movss -0x48(%ebp), %xmm1\n"
        "addss -0x34(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* vDelta */
        "movss -0x1c(%ebp), %xmm0\n" /* line 1284 */
        "movss %xmm0, -0x30(%ebp)\n"
        "calll crandom\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x30(%ebp), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 1285 | vDelta */
        "movl %eax, (%esp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "movl 0x158(%esi), %ecx\n" /* line 1287 */
        "leal 0x20(%ecx), %edi\n"
        "movss 0x20(%ecx), %xmm0\n" /* line 134 */
        "movss 4(%edi), %xmm1\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf1a126e_001a1547\n"
        "movl imp_g_playerCollisionEjectSpeed, %eax\n" /* line 1287 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 8(%eax), %xmm2\n"
        ".Lf1a126e_001a146d:\n"
        "movl 0x158(%ebx), %edx\n" /* line 1288 | self */
        "movss 0x20(%edx), %xmm0\n" /* line 134 */
        "movss 0x24(%edx), %xmm1\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf1a126e_001a153f\n"
        "movl imp_g_playerCollisionEjectSpeed, %eax\n" /* line 1288 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 8(%eax), %xmm1\n"
        ".Lf1a126e_001a14a2:\n"
        "ucomiss lit4_002ed5f0, %xmm2\n" /* line 1291 | 9.999999747378752e-05f */
        "jae .Lf1a126e_001a14c4\n"
        "jp .Lf1a126e_001a14c4\n"
        "movss lit4_002ed5f0, %xmm0\n" /* 9.999999747378752e-05f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1a126e_001a14c4\n"
        "cvtsi2ssl 0x50(%ecx), %xmm2\n" /* line 1293 */
        "cvtsi2ssl 0x50(%edx), %xmm1\n" /* line 1294 */
        ".Lf1a126e_001a14c4:\n"
        "movaps %xmm2, %xmm0\n" /* line 86 */
        "mulss -0x20(%ebp), %xmm0\n" /* vDelta */
        "movss %xmm0, (%edi)\n"
        "mulss -0x1c(%ebp), %xmm2\n" /* line 87 */
        "movss %xmm2, 4(%edi)\n"
        "movl 0x158(%esi), %eax\n" /* line 1298 */
        "movl $0x12c, 0x10(%eax)\n"
        "movl 0x158(%esi), %eax\n" /* line 1299 */
        "orl $0x200, 0xc(%eax)\n"
        "movl 0x158(%ebx), %eax\n" /* line 1301 | self */
        "movaps %xmm1, %xmm0\n" /* scale */
        "xorps sign+208, %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 86 */
        "mulss -0x20(%ebp), %xmm1\n" /* vDelta */
        "movss %xmm1, 0x20(%eax)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 87 */
        "movss %xmm0, 0x24(%eax)\n"
        /* } scope */
        "movl 0x158(%ebx), %eax\n" /* line 1302 | self */
        "movl $0x12c, 0x10(%eax)\n"
        "movl 0x158(%ebx), %eax\n" /* line 1303 | self */
        "orl $0x200, 0xc(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a126e_001a12a6\n"
        ".Lf1a126e_001a153f:\n"
        "movaps %xmm3, %xmm1\n" /* line 81 */
        "jmp .Lf1a126e_001a14a2\n"
        ".Lf1a126e_001a1547:\n"
        "movaps %xmm3, %xmm2\n"
        "jmp .Lf1a126e_001a146d\n"
    );
}

/* line 527 */
static __attribute__((naked))
void G_PlayerStateToEntityStateExtrapolate(qboolean snap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 527 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* ps */
        "movl %edx, %esi\n" /* s */
        /* { scope 1 */
        "movl $3, 0xc(%edx)\n" /* line 531 */
        "leal 0x18(%edx), %ebx\n" /* line 532 | to */
        "leal 0x14(%eax), %edx\n" /* from */
        /* { scope 2 */
        "movl 0x14(%eax), %eax\n" /* line 199 */
        "movl %eax, 0x18(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "leal 0x24(%esi), %ebx\n" /* line 535 | s, to */
        "leal 0x20(%edi), %edx\n" /* ps, from */
        /* { scope 2 */
        "movl 0x20(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x24(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movl %ecx, 0x10(%esi)\n" /* line 538 | time, s */
        "movl $0x32, 0x14(%esi)\n" /* line 540 | s */
        "movl $1, 0x30(%esi)\n" /* line 542 | s */
        "leal 0x3c(%esi), %ecx\n" /* line 543 | s, to */
        "leal 0xe8(%edi), %edx\n" /* ps, from */
        /* { scope 2 */
        "movl 0xe8(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x3c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "cvtsi2ssl 0x9c(%edi), %xmm0\n" /* line 545 | ps */
        "movss %xmm0, 0x6c(%esi)\n" /* s */
        "movl 0xa0(%edi), %eax\n" /* line 546 | ps */
        "movl %eax, 8(%esi)\n" /* s */
        "movl 0x5cc(%edi), %edx\n" /* line 548 | ps */
        "movl 0xa4(%edi), %ecx\n" /* ps */
        "cmpl %ecx, %edx\n"
        "js .Lf1a1550_001a1940\n"
        "movl $0, 0xa0(%esi)\n" /* line 561 | s */
        ".Lf1a1550_001a15f7:\n"
        "movl 0xa4(%edi), %ecx\n" /* line 568 | ps */
        "movl 0xc8(%edi), %edx\n" /* ps */
        "movl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1a1550_001a1613\n"
        "movl %ecx, %edx\n" /* line 569 */
        "movl %ecx, 0xc8(%edi)\n" /* ps */
        ".Lf1a1550_001a1613:\n"
        "movl %edx, -0x2c(%ebp)\n" /* line 571 | i */
        "cmpl 0xa4(%edi), %edx\n" /* ps */
        "je .Lf1a1550_001a16ca\n"
        "movl -0x2c(%ebp), %eax\n" /* i */
        /* { scope 2 */
        ".Lf1a1550_001a1625:\n"
        "andl $3, %eax\n" /* line 577 */
        "movl %eax, -0x34(%ebp)\n"
        "movzbl 0xa8(%edi, %eax, 4), %ecx\n" /* ps */
        "movzbl %cl, %ebx\n" /* line 579 | event */
        /* { scope 3: kickAVel */
        /* { scope 4 */
        "movl (%esi), %edx\n" /* line 1605 | s */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl imp_g_entities, %eax\n"
        "movl 0x158(%eax), %edx\n"
        "leal 0x62(%ecx), %eax\n" /* line 1608 */
        "cmpb $0x11, %al\n"
        "ja .Lf1a1550_001a1684\n"
        "movsbl %al, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x20007, %eax\n"
        "je .Lf1a1550_001a1684\n"
        "leal -0x24(%ebp), %eax\n" /* line 1614 | kickAVel */
        "movl %eax, 8(%esp)\n"
        "leal 0x288c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll BG_WeaponFireRecoil\n"
        /* } scope */
        /* } scope */
        ".Lf1a1550_001a1684:\n"
        "movl imp_singleClientEvents, %edx\n" /* line 581 */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1a1550_001a17e8\n"
        "cmpl %eax, %ebx\n" /* line 583 | event */
        "je .Lf1a1550_001a16b5\n"
        "xorl %ecx, %ecx\n" /* line 584 */
        "movl imp_singleClientEvents, %edx\n"
        ".Lf1a1550_001a16a0:\n"
        "addl $1, %ecx\n" /* line 581 */
        "movl 4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1a1550_001a17ea\n"
        "addl $4, %edx\n"
        "cmpl %eax, %ebx\n" /* line 583 | event */
        "jne .Lf1a1550_001a16a0\n"
        /* } scope */
        ".Lf1a1550_001a16b5:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 571 | i */
        "movl -0x2c(%ebp), %eax\n" /* i */
        "cmpl 0xa4(%edi), %eax\n" /* ps */
        "jne .Lf1a1550_001a1625\n"
        ".Lf1a1550_001a16c8:\n"
        "movl %eax, %edx\n"
        ".Lf1a1550_001a16ca:\n"
        "movl %edx, 0xc8(%edi)\n" /* line 593 | ps */
        "movzbl 0xd4(%edi), %eax\n" /* line 595 | ps */
        "movl %eax, 0xc8(%esi)\n" /* s */
        "movzwl 0x60(%edi), %eax\n" /* line 596 | ps */
        "movl %eax, 0x7c(%esi)\n" /* s */
        "movl 0xc(%edi), %eax\n" /* line 598 | ps */
        "andl $0xc00000, %eax\n"
        "cmpl $1, %eax\n" /* line 599 */
        "sbbl %eax, %eax\n"
        "andl $4, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%esi)\n" /* s */
        "movl 8(%ebp), %ebx\n" /* line 603 | snap, event */
        "testl %ebx, %ebx\n" /* event */
        "je .Lf1a1550_001a1755\n"
        "cvttss2si 0x18(%esi), %eax\n" /* line 605 | s */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x18(%esi)\n" /* s */
        "cvttss2si 0x1c(%esi), %eax\n" /* s */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x1c(%esi)\n" /* s */
        "cvttss2si 0x20(%esi), %eax\n" /* s */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x20(%esi)\n" /* s */
        "cvttss2si 0x3c(%esi), %eax\n" /* line 606 | s */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x3c(%esi)\n" /* s */
        "cvttss2si 0x40(%esi), %eax\n" /* s */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x40(%esi)\n" /* s */
        "cvttss2si 0x44(%esi), %eax\n" /* s */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x44(%esi)\n" /* s */
        ".Lf1a1550_001a1755:\n"
        "movl 0x7c(%edi), %eax\n" /* line 609 | ps */
        "movl %eax, 0xcc(%esi)\n" /* s */
        "movl 0x84(%edi), %eax\n" /* line 610 | ps */
        "movl %eax, 0xd0(%esi)\n" /* s */
        "movl 0xcc(%edi), %eax\n" /* line 612 | ps */
        "movl %eax, 0x90(%esi)\n" /* s */
        "testl $0x300, 0xa0(%edi)\n" /* line 616 | ps */
        "je .Lf1a1550_001a178b\n"
        "movl 0x594(%edi), %eax\n" /* line 617 | ps */
        "movl %eax, 0x74(%esi)\n" /* s */
        ".Lf1a1550_001a178b:\n"
        "cmpl $5, 4(%edi)\n" /* line 619 | ps */
        "jle .Lf1a1550_001a1930\n"
        "movl 8(%esi), %eax\n" /* line 620 | s */
        "orl $0x20000, %eax\n"
        "movl %eax, 8(%esi)\n" /* s */
        ".Lf1a1550_001a17a0:\n"
        "testb $0x40, 0xc(%edi)\n" /* line 625 | ps */
        "je .Lf1a1550_001a183f\n"
        "orl $0x40000, %eax\n" /* line 626 */
        "movl %eax, 8(%esi)\n" /* s */
        "movl 0x4c(%edi), %eax\n" /* line 631 | ps */
        "movl %eax, 0xd4(%esi)\n" /* s */
        "movl %edi, (%esp)\n" /* line 634 | ps */
        "calll PM_GetEffectiveStance\n"
        "subl $1, %eax\n"
        "je .Lf1a1550_001a1861\n"
        ".Lf1a1550_001a17cc:\n"
        "xorl %eax, %eax\n" /* line 654 */
        "movl %eax, 0xe4(%esi)\n" /* s */
        "movl %eax, 0xe8(%esi)\n" /* line 655 | s */
        "movl %eax, 0xec(%esi)\n" /* line 656 | s */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 658 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1a1550_001a17e8:\n"
        "xorl %ecx, %ecx\n" /* line 581 */
        ".Lf1a1550_001a17ea:\n"
        "movl imp_singleClientEvents, %eax\n" /* line 586 */
        "movl (%eax, %ecx, 4), %eax\n"
        "testl %eax, %eax\n"
        "jns .Lf1a1550_001a16b5\n"
        "movl 0xa4(%esi), %eax\n" /* line 589 | s */
        "movl %eax, %ecx\n"
        "andl $3, %ecx\n"
        "movl %ebx, 0xa8(%esi, %ecx, 4)\n" /* event, s */
        "movl -0x34(%ebp), %ebx\n" /* line 590 | event */
        "movzbl 0xb8(%edi, %ebx, 4), %edx\n" /* ps */
        "movl %edx, 0xb8(%esi, %ecx, 4)\n" /* s */
        "addl $1, %eax\n" /* line 591 */
        "movl %eax, 0xa4(%esi)\n" /* s */
        /* } scope */
        "addl $1, -0x2c(%ebp)\n" /* line 571 | i */
        "movl -0x2c(%ebp), %eax\n" /* i */
        "cmpl 0xa4(%edi), %eax\n" /* ps */
        "jne .Lf1a1550_001a1625\n"
        "jmp .Lf1a1550_001a16c8\n"
        ".Lf1a1550_001a183f:\n"
        "andl $0xfffbffff, %eax\n" /* line 628 */
        "movl %eax, 8(%esi)\n" /* line 626 | s */
        "movl 0x4c(%edi), %eax\n" /* line 631 | ps */
        "movl %eax, 0xd4(%esi)\n" /* s */
        "movl %edi, (%esp)\n" /* line 634 | ps */
        "calll PM_GetEffectiveStance\n"
        "subl $1, %eax\n"
        "jne .Lf1a1550_001a17cc\n"
        /* { scope 2 */
        ".Lf1a1550_001a1861:\n"
        "movl 0x104(%edi), %eax\n" /* line 639 | ps */
        "movl %eax, 8(%esp)\n"
        "movl 0x100(%edi), %eax\n" /* ps */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll PM_GetViewHeightLerpTime\n"
        "movl (%edi), %edx\n" /* line 640 | ps */
        "subl 0xfc(%edi), %edx\n" /* ps */
        "cvtsi2ssl %edx, %xmm1\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 641 | 0.0f */
        "jb .Lf1a1550_001a198c\n"
        ".Lf1a1550_001a189e:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 643 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1a1550_001a18ad:\n"
        "movl 0x104(%edi), %ecx\n" /* line 645 | ps */
        "testl %ecx, %ecx\n"
        "jne .Lf1a1550_001a18c6\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 646 | 1.0f */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1a1550_001a18c6:\n"
        "movaps %xmm1, %xmm0\n" /* line 648 */
        "mulss 0x5a8(%edi), %xmm0\n" /* ps */
        "movss %xmm0, 0xe4(%esi)\n" /* s */
        "movl 0x5ac(%edi), %eax\n" /* line 649 | ps */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss -0x48(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0xe8(%esi)\n" /* s */
        "movl 0x5b0(%edi), %eax\n" /* line 650 | ps */
        "movl %eax, (%esp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x30(%ebp)\n"
        "movss -0x48(%ebp), %xmm1\n"
        "mulss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, 0xec(%esi)\n" /* s */
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 658 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a1550_001a1930:\n"
        "movl 8(%esi), %eax\n" /* line 622 | s */
        "andl $0xfffdffff, %eax\n"
        "movl %eax, 8(%esi)\n" /* s */
        "jmp .Lf1a1550_001a17a0\n"
        ".Lf1a1550_001a1940:\n"
        "movl %ecx, %eax\n" /* line 552 */
        "subl %edx, %eax\n"
        "cmpl $4, %eax\n"
        "jg .Lf1a1550_001a1966\n"
        "andl $3, %edx\n" /* line 556 */
        "movzbl 0xb8(%edi, %edx, 4), %eax\n" /* ps */
        "movl %eax, 0xa0(%esi)\n" /* s */
        "addl $1, 0x5cc(%edi)\n" /* line 557 | ps */
        "jmp .Lf1a1550_001a15f7\n"
        ".Lf1a1550_001a1966:\n"
        "leal -4(%ecx), %edx\n" /* line 553 */
        "movl %edx, 0x5cc(%edi)\n" /* ps */
        "andl $3, %edx\n" /* line 556 */
        "movzbl 0xb8(%edi, %edx, 4), %eax\n" /* ps */
        "movl %eax, 0xa0(%esi)\n" /* s */
        "addl $1, 0x5cc(%edi)\n" /* line 557 | ps */
        "jmp .Lf1a1550_001a15f7\n"
        /* { scope 2 */
        ".Lf1a1550_001a198c:\n"
        "jp .Lf1a1550_001a189e\n" /* line 641 */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf1a1550_001a18ad\n"
    );
}

/* line 705 */
__attribute__((naked))
void ClientThink_real(gentity_t *ent, usercmd_t *ucmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 705 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x25c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* ucmd */
        /* { scope 1: duration */
        "movl 8(%ebp), %eax\n" /* line 723 | ent */
        "movl 0x158(%eax), %edi\n" /* client */
        "cmpl $2, 0x26c4(%edi)\n" /* line 726 | client */
        "je .Lf1a199c_001a19c8\n"
        /* } scope */
        ".Lf1a199c_001a19bd:\n"
        "addl $0x25c, %esp\n" /* line 953 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: duration */
        ".Lf1a199c_001a19c8:\n"
        "movl imp_level, %ecx\n" /* line 732 */
        "movl 0x1ec(%ecx), %eax\n"
        "leal 0xc8(%eax), %edx\n"
        "cmpl %edx, (%ebx)\n" /* ucmd */
        "jle .Lf1a199c_001a19e6\n"
        "movl %edx, (%ebx)\n" /* line 734 | ucmd */
        "movl 0x1ec(%ecx), %eax\n"
        ".Lf1a199c_001a19e6:\n"
        "subl $0x3e8, %eax\n" /* line 737 */
        "cmpl %eax, (%ebx)\n" /* ucmd */
        "jge .Lf1a199c_001a1ffb\n"
        "movl %eax, (%ebx)\n" /* line 739 | ucmd */
        "movl %eax, %esi\n" /* msec */
        ".Lf1a199c_001a19f7:\n"
        "subl (%edi), %esi\n" /* line 743 | client, msec */
        "testl %esi, %esi\n" /* line 746 | msec */
        "jle .Lf1a199c_001a204e\n"
        "cmpl $0xc9, %esi\n" /* line 750 | msec */
        "movl $0xc8, %eax\n"
        "cmovgel %eax, %esi\n" /* msec */
        ".Lf1a199c_001a1a0f:\n"
        "movl 0x27b4(%edi), %eax\n" /* line 755 | client */
        "testl %eax, %eax\n"
        "je .Lf1a199c_001a2002\n"
        "orl $0x8000, 0xc(%edi)\n" /* line 756 | client */
        "movl 0x26a8(%edi), %eax\n" /* line 763 | client */
        "cmpl $3, %eax\n"
        "je .Lf1a199c_001a2018\n"
        ".Lf1a199c_001a1a33:\n"
        "cmpl $2, %eax\n" /* line 772 */
        "je .Lf1a199c_001a2071\n"
        "movl %edi, (%esp)\n" /* line 781 | client */
        "calll ClientInactivityTimer\n"
        "testl %eax, %eax\n"
        "je .Lf1a199c_001a19bd\n"
        "movl 0xa4(%edi), %eax\n" /* line 787 | client */
        "movl %eax, -0x228(%ebp)\n" /* oldEventSequence */
        "movl $0xf8, 8(%esp)\n" /* line 789 */
        "movl $0, 4(%esp)\n"
        "leal -0x20c(%ebp), %edx\n" /* pm */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl %edi, -0x20c(%ebp)\n" /* line 791 | client, pm */
        "movl (%ebx), %eax\n" /* line 792 | ucmd */
        "movl %eax, -0x208(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* ucmd */
        "movl %eax, -0x204(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* ucmd */
        "movl %eax, -0x200(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* ucmd */
        "movl %eax, -0x1fc(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* ucmd */
        "movl %eax, -0x1f8(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* ucmd */
        "movl %eax, -0x1f4(%ebp)\n"
        "movl 0x18(%ebx), %eax\n" /* ucmd */
        "movl %eax, -0x1f0(%ebp)\n"
        "movl 0x26e4(%edi), %eax\n" /* line 793 | client */
        "movl %eax, -0x1ec(%ebp)\n"
        "movl 0x26e8(%edi), %eax\n" /* client */
        "movl %eax, -0x1e8(%ebp)\n"
        "movl 0x26ec(%edi), %eax\n" /* client */
        "movl %eax, -0x1e4(%ebp)\n"
        "movl 0x26f0(%edi), %eax\n" /* client */
        "movl %eax, -0x1e0(%ebp)\n"
        "movl 0x26f4(%edi), %eax\n" /* client */
        "movl %eax, -0x1dc(%ebp)\n"
        "movl 0x26f8(%edi), %eax\n" /* client */
        "movl %eax, -0x1d8(%ebp)\n"
        "movl 0x26fc(%edi), %eax\n" /* client */
        "movl %eax, -0x1d4(%ebp)\n"
        "movl $0x00810011, %eax\n" /* line 796 */
        "cmpl $6, 4(%edi)\n" /* client */
        "movl $0x2810011, %edx\n"
        "cmovll %edx, %eax\n"
        "movl %eax, -0x1d0(%ebp)\n"
        "movb $1, -0x128(%ebp)\n" /* line 803 */
        "leal 0x27cc(%edi), %ecx\n" /* line 805 | client, to */
        "leal 0x14(%edi), %edx\n" /* client, from */
        /* { scope 2: ent */
        "movl 0x14(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x27cc(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl 0x27bc(%edi), %eax\n" /* line 808 | client */
        "movl %eax, 0x27c0(%edi)\n" /* client */
        "movl 0x26cc(%edi), %edx\n" /* line 809 | client */
        "movl %edx, 0x27bc(%edi)\n" /* client */
        "notl %eax\n" /* line 810 */
        "andl %edx, %eax\n"
        "movl %eax, 0x27c4(%edi)\n" /* client */
        "orl %eax, 0x27c8(%edi)\n" /* line 811 | client */
        "movl %edi, -0x78(%ebp)\n" /* line 813 | client, vs */
        "movl 0x2840(%edi), %eax\n" /* line 814 | client */
        "movl %eax, -0x74(%ebp)\n"
        "movl imp_level, %eax\n" /* line 815 */
        "movl 0x1ec(%eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movl 0x2848(%edi), %eax\n" /* line 816 | client */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 0x2844(%edi), %eax\n" /* line 817 | client */
        "movl %eax, -0x68(%ebp)\n"
        "movl %edx, 4(%esp)\n" /* line 818 */
        "movl %edi, (%esp)\n" /* client */
        "calll BG_GetSpeed\n"
        "fstps -0x64(%ebp)\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 819 | msec */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x23c(%ebp)\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movl 0x287c(%edi), %eax\n" /* line 820 | client */
        "movl %eax, -0x5c(%ebp)\n"
        "leal 0x2898(%edi), %eax\n" /* line 821 | client */
        "movl %eax, -0x238(%ebp)\n"
        "movl %eax, -0x58(%ebp)\n"
        "leal -0x24(%ebp), %edx\n" /* line 823 | angles */
        "movl %edx, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* vs */
        "movl %eax, (%esp)\n"
        "calll BG_CalculateViewAngles\n"
        "leal 0xe8(%edi), %eax\n" /* client */
        /* { scope 2: ent */
        "movss 0xe8(%edi), %xmm0\n" /* line 240 */
        "addss -0x24(%ebp), %xmm0\n" /* angles */
        "movss %xmm0, -0x30(%ebp)\n" /* viewangles */
        "movss 4(%eax), %xmm0\n" /* line 241 */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "movl 0xd4(%edi), %eax\n" /* line 827 | client */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x224(%ebp)\n" /* weapDef */
        "leal 0x2864(%edi), %ebx\n" /* line 847 | client, ucmd */
        "movl %esi, 0x14(%esp)\n" /* msec */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* ucmd */
        "leal 0x2858(%edi), %eax\n" /* client */
        "movl %eax, 8(%esp)\n"
        "leal 0x284c(%edi), %eax\n" /* client */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* client */
        "calll BG_CalculateWeaponPosition_Sway\n"
        "movl -0x78(%ebp), %eax\n" /* line 849 | vs */
        "movl %eax, -0x114(%ebp)\n" /* ws */
        "movl -0x64(%ebp), %eax\n" /* line 850 */
        "movl %eax, -0x110(%ebp)\n"
        "movss -0x23c(%ebp), %xmm0\n" /* line 851 */
        "movss %xmm0, -0x10c(%ebp)\n"
        "leal 0x2870(%edi), %eax\n" /* line 853 | client */
        "movl %eax, -0x234(%ebp)\n"
        "movl 0x2870(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x108(%ebp)\n"
        "movl -0x234(%ebp), %edx\n" /* line 200 */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x104(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x100(%ebp)\n"
        "movl 0x287c(%edi), %eax\n" /* line 854 | client */
        "movl %eax, -0xfc(%ebp)\n"
        "movl -0x70(%ebp), %eax\n" /* line 855 */
        "movl %eax, -0xf8(%ebp)\n"
        "movl 0x2840(%edi), %eax\n" /* line 856 | client */
        "movl %eax, -0xf4(%ebp)\n"
        "movl 0x2848(%edi), %eax\n" /* line 857 | client */
        "movl %eax, -0xf0(%ebp)\n"
        "movl 0x2844(%edi), %eax\n" /* line 858 | client */
        "movl %eax, -0xec(%ebp)\n"
        "leal 0x2880(%edi), %ecx\n" /* line 859 | client */
        "movl %ecx, -0x230(%ebp)\n"
        "movl 0x2880(%edi), %eax\n" /* line 199 */
        "movl %eax, -0xe8(%ebp)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0xe4(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0xe0(%ebp)\n"
        "leal 0x288c(%edi), %esi\n" /* line 860 | client, msec */
        "movl %esi, -0x22c(%ebp)\n" /* msec */
        "movl 0x288c(%edi), %eax\n" /* line 199 */
        "movl %eax, -0xdc(%ebp)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, -0xd8(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, -0xd4(%ebp)\n"
        "movl 0x2864(%edi), %eax\n" /* line 199 */
        "movl %eax, -0xd0(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0xcc(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, -0xc8(%ebp)\n"
        "movl -0x238(%ebp), %eax\n" /* line 862 */
        "movl %eax, -0xc4(%ebp)\n"
        "leal -0x24(%ebp), %edx\n" /* line 864 | angles */
        "movl %edx, 4(%esp)\n"
        "leal -0x114(%ebp), %eax\n" /* ws */
        "movl %eax, (%esp)\n"
        "calll BG_CalculateWeaponAngles\n"
        "movl -0x114(%ebp), %eax\n" /* line 867 | ws */
        "movl 0xd4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_IsAimDownSightWeapon\n"
        "testl %eax, %eax\n"
        "je .Lf1a199c_001a1dbf\n"
        "pxor %xmm0, %xmm0\n"
        "movl -0x114(%ebp), %eax\n" /* ws */
        "ucomiss 0xdc(%eax), %xmm0\n"
        "jp .Lf1a199c_001a20a9\n"
        "jne .Lf1a199c_001a20a9\n"
        ".Lf1a199c_001a1dbf:\n"
        "movl -0x108(%ebp), %eax\n" /* line 199 */
        "movl -0x234(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl -0x104(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x100(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl -0xfc(%ebp), %eax\n" /* line 876 */
        "movl %eax, 0x287c(%edi)\n" /* client */
        "movl -0xe8(%ebp), %eax\n" /* line 199 */
        "movl -0x230(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl -0xe4(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl -0xdc(%ebp), %eax\n" /* line 199 */
        "movl -0x22c(%ebp), %ebx\n"
        "movl %eax, (%ebx)\n"
        "movl -0xd8(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl -0xd4(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        "movl -0x30(%ebp), %eax\n" /* line 881 | viewangles */
        "movl %eax, 0x27d8(%edi)\n" /* client */
        "movl -0x2c(%ebp), %eax\n" /* line 882 */
        "movl %eax, 0x27dc(%edi)\n" /* client */
        "leal -0x20c(%ebp), %esi\n" /* line 889 | pm, msec */
        "movl %esi, (%esp)\n" /* msec */
        "calll Pmove\n"
        "cmpb $0, -0x127(%ebp)\n" /* line 893 */
        "jne .Lf1a199c_001a212d\n"
        ".Lf1a199c_001a1e58:\n"
        "movl 8(%ebp), %edx\n" /* line 901 | ent */
        "movl 0x158(%edx), %ebx\n" /* ucmd */
        "xorl %eax, %eax\n" /* line 902 */
        "testb $2, 0xc(%ebx)\n" /* ucmd */
        "setne %al\n"
        "movl %eax, 0xe0(%edx)\n"
        "movl -0x228(%ebp), %ecx\n" /* line 907 | oldEventSequence */
        "cmpl 0xa4(%ebx), %ecx\n" /* ucmd */
        "je .Lf1a199c_001a1e9e\n"
        "movl imp_level, %eax\n" /* line 909 */
        "movl 0x1ec(%eax), %edx\n"
        "movl 8(%ebp), %esi\n" /* ent, msec */
        "movl %edx, 0x178(%esi)\n" /* msec */
        "movl 0x1ec(%eax), %eax\n" /* line 910 */
        "movl %eax, 0x154(%esi)\n" /* msec */
        ".Lf1a199c_001a1e9e:\n"
        "movl imp_g_smoothClients, %eax\n" /* line 913 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1a199c_001a2085\n"
        "movl $1, (%esp)\n" /* line 915 */
        "movl (%ebx), %ecx\n" /* ucmd */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %ebx, %eax\n" /* ucmd */
        "calll G_PlayerStateToEntityStateExtrapolate\n"
        ".Lf1a199c_001a1ec2:\n"
        "movl 8(%ebp), %edx\n" /* line 923 | ent, from */
        "addl $0x18, %edx\n" /* from */
        /* { scope 2: ent */
        "movl 8(%ebp), %ecx\n" /* line 199 | ent */
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, 0x138(%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x13c(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x140(%ecx)\n"
        /* } scope */
        "movl %ecx, %edx\n" /* line 925 | to */
        "addl $0x104, %edx\n" /* to */
        /* { scope 2: ent */
        "movl -0x148(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x104(%ecx)\n"
        "movl -0x144(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x140(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0xc, %edx\n" /* line 926 | to */
        /* { scope 2: ent */
        "movl -0x13c(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x110(%ecx)\n"
        "movl -0x138(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x134(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0x228(%ebp), %ebx\n" /* line 930 | oldEventSequence, ucmd */
        "movl %ebx, 4(%esp)\n" /* ucmd */
        "movl %ecx, (%esp)\n"
        "calll ClientEvents\n"
        "movl 8(%ebp), %esi\n" /* line 934 | ent, msec */
        "movl %esi, (%esp)\n" /* msec */
        "calll SV_LinkEntity\n"
        "movl 0x158(%esi), %ebx\n" /* line 935 | msec, ucmd */
        "movl 0x27ac(%ebx), %eax\n" /* ucmd */
        "testl %eax, %eax\n"
        "je .Lf1a199c_001a211a\n"
        ".Lf1a199c_001a1f5e:\n"
        "leal 0x14(%ebx), %edx\n" /* line 936 | ucmd */
        /* { scope 2: ent */
        "movl 0x14(%ebx), %eax\n" /* line 199 */
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl %eax, 0x138(%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x13c(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x140(%ecx)\n"
        /* } scope */
        "movl %ecx, %edx\n" /* line 940 | v */
        "addl $0x144, %edx\n" /* v */
        /* { scope 2: ent */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x144(%ecx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "movl 0x158(%ecx), %eax\n" /* line 941 */
        "movl 0xec(%eax), %eax\n"
        "movl %eax, 0x148(%ecx)\n"
        "leal -0x20c(%ebp), %ebx\n" /* line 945 | pm, ucmd */
        "movl %ebx, 4(%esp)\n" /* ucmd */
        "movl %ecx, (%esp)\n"
        "calll ClientImpacts\n"
        "movl 8(%ebp), %esi\n" /* line 949 | ent, msec */
        "movl 0x158(%esi), %eax\n" /* msec */
        "movl -0x228(%ebp), %edx\n" /* oldEventSequence */
        "cmpl 0xa4(%eax), %edx\n"
        "je .Lf1a199c_001a224a\n"
        "movl imp_level, %eax\n" /* line 950 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x178(%esi)\n" /* msec */
        "movl 8(%ebp), %ecx\n" /* ent */
        ".Lf1a199c_001a1fe8:\n"
        "movl %ecx, (%esp)\n" /* line 952 */
        "calll Player_UpdateActivate\n"
        /* } scope */
        "addl $0x25c, %esp\n" /* line 953 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1a199c_001a1ffb:\n"
        "movl (%ebx), %esi\n" /* ucmd, msec */
        "jmp .Lf1a199c_001a19f7\n"
        /* { scope 1: duration */
        ".Lf1a199c_001a2002:\n"
        "andl $0xffff7fff, 0xc(%edi)\n" /* line 758 | client */
        "movl 0x26a8(%edi), %eax\n" /* line 763 | client */
        "cmpl $3, %eax\n"
        "jne .Lf1a199c_001a1a33\n"
        /* { scope 2: ent */
        ".Lf1a199c_001a2018:\n"
        "movl 8(%ebp), %edx\n" /* line 352 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl 0x27bc(%eax), %ecx\n" /* line 355 */
        "movl %ecx, 0x27c0(%eax)\n"
        "movl 0x26cc(%eax), %edx\n" /* line 356 */
        "movl %edx, 0x27bc(%eax)\n"
        "notl %ecx\n" /* line 357 */
        "andl %ecx, %edx\n"
        "orl %edx, 0x27c8(%eax)\n"
        /* } scope */
        /* } scope */
        "addl $0x25c, %esp\n" /* line 953 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: duration */
        ".Lf1a199c_001a204e:\n"
        "movl 8(%ebp), %eax\n" /* line 746 | ent */
        "subl imp_g_entities, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "cmpl %eax, 0xcc(%edi)\n" /* client */
        "jne .Lf1a199c_001a1a0f\n"
        "jmp .Lf1a199c_001a19bd\n"
        ".Lf1a199c_001a2071:\n"
        "movl %ebx, 4(%esp)\n" /* line 775 | ucmd */
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl %ecx, (%esp)\n"
        "calll SpectatorThink\n"
        "jmp .Lf1a199c_001a19bd\n"
        ".Lf1a199c_001a2085:\n"
        "movl $1, 0xc(%esp)\n" /* line 919 */
        "movl $1, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ucmd */
        "calll BG_PlayerStateToEntityState\n"
        "jmp .Lf1a199c_001a1ec2\n"
        ".Lf1a199c_001a20a9:\n"
        "movl -0x224(%ebp), %ecx\n" /* line 867 | weapDef */
        "movl 0x278(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1a199c_001a1dbf\n"
        "leal -0x9c(%ebp), %ebx\n" /* line 869 | vAxis, ucmd */
        "movl %ebx, 4(%esp)\n" /* ucmd */
        "leal -0x24(%ebp), %esi\n" /* angles, msec */
        "movl %esi, (%esp)\n" /* msec */
        "calll AnglesToAxis\n"
        "leal -0xc0(%ebp), %eax\n" /* line 870 | vAxis2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* viewangles */
        "movl %edx, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal -0x54(%ebp), %ebx\n" /* line 871 | vAxis3, ucmd */
        "movl %ebx, 8(%esp)\n" /* ucmd */
        "leal -0xc0(%ebp), %ecx\n" /* vAxis2 */
        "movl %ecx, 4(%esp)\n"
        "leal -0x9c(%ebp), %esi\n" /* vAxis, msec */
        "movl %esi, (%esp)\n" /* msec */
        "calll MatrixMultiply\n"
        "leal -0x30(%ebp), %eax\n" /* line 872 | viewangles */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ucmd */
        "calll AxisToAngles\n"
        "jmp .Lf1a199c_001a1dbf\n"
        ".Lf1a199c_001a211a:\n"
        "movl %esi, (%esp)\n" /* line 936 | msec */
        "calll G_TouchTriggers\n"
        "movl 0x158(%esi), %ebx\n" /* msec, ucmd */
        "jmp .Lf1a199c_001a1f5e\n"
        ".Lf1a199c_001a212d:\n"
        "movl -0x118(%ebp), %eax\n" /* line 896 */
        "movl %eax, -0x220(%ebp)\n" /* duration */
        /* { scope 2: ent */
        /* { scope 3 */
        "movl -0x20c(%ebp), %eax\n" /* line 670 | pm */
        "movl 0xcc(%eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* owner */
        "subl %eax, %ebx\n" /* owner */
        "shll $4, %ebx\n" /* owner */
        "addl imp_g_entities, %ebx\n" /* owner */
        "calll G_Spawn\n" /* line 671 */
        "movl %eax, -0x21c(%ebp)\n" /* ent */
        "movl %ebx, 0x18c(%eax)\n" /* line 672 | owner */
        "movl -0x20c(%ebp), %eax\n" /* line 673 | pm */
        "movl 0xcc(%eax), %eax\n"
        "movl -0x21c(%ebp), %edx\n" /* ent */
        "movl %eax, 0x150(%edx)\n"
        "movl $0x10000, 0x11c(%edx)\n" /* line 674 */
        "movl $0x10000, 0x184(%edx)\n" /* line 675 */
        "movb $0x21, 0xf2(%edx)\n" /* line 676 */
        "movl $5, 4(%edx)\n" /* line 677 */
        "movb $0x13, 0x166(%edx)\n" /* line 678 */
        "movl %edx, %ecx\n" /* line 680 | from, to */
        "addl $0x104, %ecx\n" /* to */
        "leal 0x104(%ebx), %edx\n" /* owner, from */
        /* { scope 4 */
        "movl 0x104(%ebx), %eax\n" /* line 199 */
        "movl -0x21c(%ebp), %esi\n" /* ent */
        "movl %eax, 0x104(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl %esi, %ecx\n" /* line 681 | to */
        "addl $0x110, %ecx\n" /* to */
        "leal 0x110(%ebx), %edx\n" /* owner, from */
        /* { scope 4 */
        "movl 0x110(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x110(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal -0x124(%ebp), %eax\n" /* line 683 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_SetOrigin\n"
        "movl %esi, (%esp)\n" /* line 684 */
        "calll SV_LinkEntity\n"
        "movl imp_g_mantleBlockTimeBuffer, %eax\n" /* line 689 */
        "movl (%eax), %edx\n"
        "movl imp_level, %eax\n"
        "movl 0x1ec(%eax), %ecx\n"
        "addl %ecx, -0x220(%ebp)\n" /* duration */
        "movl 8(%edx), %ebx\n" /* owner */
        "addl %ebx, -0x220(%ebp)\n" /* owner, duration */
        "movl -0x220(%ebp), %eax\n" /* duration */
        "movl %eax, 0x190(%esi)\n"
        "jmp .Lf1a199c_001a1e58\n"
        ".Lf1a199c_001a224a:\n"
        "movl %esi, %ecx\n"
        "jmp .Lf1a199c_001a1fe8\n"
    );
}

/* line 990 */
void G_RunClient(gentity_t *ent)
{
    gclient_t *client;
    int pm_type;

    /* If synchronous clients, set cmd.serverTime = level.time and run think */
    if (g_synchronousClients->current.enabled) {
        client = ent->client;
        client->sess.cmd.serverTime = level.time;
        ClientThink_real(ent, CLIENT_SESS_CMD(client));
    }

    client = ent->client;

    /* If ufo mode, skip linked entity updates */
    if (CLIENT_UFO(client))
        return;

    if (ent->tagInfo) {
        /* Entity is linked to a tag - set pm_type based on session state */
        pm_type = (CLIENT_SESS_STATE(client) == SESS_STATE_DEAD) ? 7 : 1;
        CLIENT_PS_PM_TYPE(client) = pm_type;
        G_SetFixedLink(ent, 2);
        G_SetOrigin(ent, ent->r.currentOrigin);
        G_SetAngle(ent, ent->r.currentAngles);
        ent->s.pos.trType = TR_INTERPOLATE;
        ent->s.apos.trType = TR_INTERPOLATE;
        SV_LinkEntity(ent);
        /* Copy currentOrigin to ps.origin */
        ((gclient_t *)client)->ps.origin[0] = ent->r.currentOrigin[0];
        ((gclient_t *)client)->ps.origin[1] = ent->r.currentOrigin[1];
        ((gclient_t *)client)->ps.origin[2] = ent->r.currentOrigin[2];
    } else {
        /* No tag - if pm_type is 1 or 7, decrement it */
        pm_type = CLIENT_PS_PM_TYPE(client);
        if (pm_type == 1 || pm_type == 7)
            CLIENT_PS_PM_TYPE(client) = pm_type - 1;
    }
}

/* line 963 */
__attribute__((naked))
void ClientThink(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 963 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* clientNum */
        /* { scope 1 */
        "leal (%ecx, %ecx, 4), %eax\n" /* line 969 */
        "leal (, %eax, 8), %ebx\n" /* ent */
        "subl %eax, %ebx\n" /* ent */
        "shll $4, %ebx\n" /* ent */
        "addl imp_g_entities, %ebx\n" /* ent */
        "movl imp_bgs, %esi\n" /* line 972 */
        "movl imp_level_bgs, %eax\n"
        "movl %eax, (%esi)\n"
        "movl 0x158(%ebx), %eax\n" /* line 974 | ent */
        "movl 0x26c8(%eax), %edx\n"
        "movl %edx, 0x26e4(%eax)\n"
        "movl 0x26cc(%eax), %edx\n"
        "movl %edx, 0x26e8(%eax)\n"
        "movl 0x26d0(%eax), %edx\n"
        "movl %edx, 0x26ec(%eax)\n"
        "movl 0x26d4(%eax), %edx\n"
        "movl %edx, 0x26f0(%eax)\n"
        "movl 0x26d8(%eax), %edx\n"
        "movl %edx, 0x26f4(%eax)\n"
        "movl 0x26dc(%eax), %edx\n"
        "movl %edx, 0x26f8(%eax)\n"
        "movl 0x26e0(%eax), %edx\n"
        "movl %edx, 0x26fc(%eax)\n"
        "movl 0x158(%ebx), %eax\n" /* line 975 | ent */
        "addl $0x26c8, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll SV_GetUsercmd\n"
        "movl 0x158(%ebx), %edx\n" /* line 979 | ent */
        "movl imp_level, %eax\n"
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x27b8(%edx)\n"
        "movl imp_g_synchronousClients, %eax\n" /* line 981 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1a235e_001a2437\n"
        "movl 0x158(%ebx), %eax\n" /* line 983 | ent */
        "addl $0x26c8, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll ClientThink_real\n"
        ".Lf1a235e_001a2437:\n"
        "movl $0, (%esi)\n" /* line 986 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 987 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1410 */
__attribute__((naked))
void ClientEndFrame(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1410 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: ci, i, client */
        "movl 8(%ebp), %eax\n" /* line 1421 | ent */
        "movl 0x158(%eax), %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* client */
        "movl 8(%ebp), %edx\n" /* line 1426 | ent */
        "movb $0xa, 0x166(%edx)\n"
        "movl $0, 0x7a4(%eax)\n" /* line 1427 */
        /* { scope 2 */
        "movl 0x158(%edx), %ecx\n" /* line 1347 */
        "movl %ecx, -0x54(%ebp)\n" /* client */
        "movl 0x90(%edx), %eax\n" /* line 1353 */
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %ebx\n" /* tagName */
        "shll $4, %ebx\n" /* tagName */
        "subl %edx, %ebx\n" /* tagName */
        "leal (%eax, %ebx, 2), %ebx\n" /* tagName */
        "movl imp_level_bgs, %eax\n"
        "leal 0xb3bf0(%eax, %ebx, 8), %ebx\n" /* tagName */
        "leal 0xc(%ebx), %edi\n" /* tagName */
        "movl %edi, -0x5c(%ebp)\n" /* ci */
        "movl 8(%ebp), %edx\n" /* line 1358 | ent */
        "movzbl 0x164(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, %esi\n" /* modelName */
        "movl 8(%ebp), %ecx\n" /* line 1359 | ent */
        "movzbl 0x164(%ecx), %eax\n"
        "movl -0x54(%ebp), %edi\n" /* client */
        "movl %eax, 0x2750(%edi)\n"
        "addl $0x4c, %ebx\n" /* line 1360 | tagName */
        "movl %esi, 4(%esp)\n" /* modelName */
        "movl %ebx, (%esp)\n" /* tagName */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a2444_001a26c9\n"
        "movl $0, -0x68(%ebp)\n" /* bChanged */
        ".Lf1a2444_001a24e0:\n"
        "movl 8(%ebp), %eax\n" /* line 1363 | ent */
        "movl %eax, -0x50(%ebp)\n"
        "movl -0x5c(%ebp), %edi\n" /* ci */
        "movl -0x54(%ebp), %esi\n" /* client, modelName */
        "movl %eax, -0x4c(%ebp)\n"
        "movl $0, -0x58(%ebp)\n" /* i */
        "leal 0x80(%edi), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1a2444_001a2548\n"
        ".Lf1a2444_001a2503:\n"
        "movb $0, 0x80(%edi)\n" /* line 1370 */
        "movb $0, 0x200(%edi)\n" /* line 1371 */
        "movl $0, 0x2754(%esi)\n" /* line 1372 | modelName */
        "movl $0, 0x276c(%esi)\n" /* line 1373 | modelName */
        ".Lf1a2444_001a2525:\n"
        "addl $1, -0x58(%ebp)\n" /* line 1366 | i */
        "addl $0x40, -0x70(%ebp)\n"
        "addl $1, -0x50(%ebp)\n"
        "addl $0x40, %edi\n"
        "addl $4, %esi\n" /* modelName */
        "addl $2, -0x4c(%ebp)\n"
        "cmpl $6, -0x58(%ebp)\n" /* i */
        "je .Lf1a2444_001a2614\n"
        ".Lf1a2444_001a2545:\n"
        "movl -0x50(%ebp), %ecx\n"
        ".Lf1a2444_001a2548:\n"
        "movzbl 0x210(%ecx), %eax\n" /* line 1368 */
        "testb %al, %al\n"
        "je .Lf1a2444_001a2503\n"
        "movzbl %al, %eax\n" /* line 1377 */
        "movl %eax, (%esp)\n"
        "calll G_ModelName\n"
        "movl %eax, %ebx\n" /* tagName */
        "movl -0x50(%ebp), %edx\n" /* line 1378 */
        "movzbl 0x210(%edx), %eax\n"
        "movl %eax, 0x2754(%esi)\n" /* modelName */
        "movl -0x58(%ebp), %ecx\n" /* line 1379 | i */
        "shll $6, %ecx\n"
        "movl %ecx, -0x6c(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* tagName */
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a2444_001a263b\n"
        ".Lf1a2444_001a2590:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 1386 */
        "movzwl 0x218(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n" /* tagName */
        "movl %eax, (%esp)\n" /* line 1387 */
        "calll G_TagIndex\n"
        "movl %eax, 0x276c(%esi)\n" /* modelName */
        "movl -0x6c(%ebp), %eax\n" /* line 1388 */
        "movl -0x5c(%ebp), %edx\n" /* ci */
        "leal 0x200(%eax, %edx), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* tagName */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a2444_001a2525\n"
        "movl $0x40, 8(%esp)\n" /* line 1391 */
        "movl %ebx, 4(%esp)\n" /* tagName */
        "movl -0x60(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $1, -0x68(%ebp)\n" /* bChanged */
        "addl $1, -0x58(%ebp)\n" /* line 1366 | i */
        "addl $0x40, -0x70(%ebp)\n"
        "addl $1, -0x50(%ebp)\n"
        "addl $0x40, %edi\n"
        "addl $4, %esi\n" /* modelName */
        "addl $2, -0x4c(%ebp)\n"
        "cmpl $6, -0x58(%ebp)\n" /* i */
        "jne .Lf1a2444_001a2545\n"
        /* } scope */
        ".Lf1a2444_001a2614:\n"
        "movl -0x64(%ebp), %ecx\n" /* line 1432 | client */
        "cmpl $2, 0x26c4(%ecx)\n"
        "je .Lf1a2444_001a265e\n"
        ".Lf1a2444_001a2620:\n"
        "movl 8(%ebp), %edi\n" /* line 1441 | ent */
        ".Lf1a2444_001a2623:\n"
        "movl 0x158(%edi), %eax\n" /* line 1458 */
        "movl $0, 0x27c8(%eax)\n"
        /* } scope */
        ".Lf1a2444_001a2633:\n"
        "addl $0x7c, %esp\n" /* line 1592 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ci, i, client */
        /* { scope 2 */
        ".Lf1a2444_001a263b:\n"
        "movl $0x40, 8(%esp)\n" /* line 1382 */
        "movl %ebx, 4(%esp)\n" /* tagName */
        "movl -0x70(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $1, -0x68(%ebp)\n" /* bChanged */
        "jmp .Lf1a2444_001a2590\n"
        /* } scope */
        ".Lf1a2444_001a265e:\n"
        "movl 0x26a8(%ecx), %eax\n" /* line 1438 */
        "cmpl $3, %eax\n"
        "je .Lf1a2444_001a2ab9\n"
        "cmpl $2, %eax\n" /* line 1445 */
        "je .Lf1a2444_001a2b6b\n"
        "movl -0x64(%ebp), %ecx\n" /* line 1452 | client */
        "movl 0xcc(%ecx), %eax\n"
        "movl 8(%ebp), %edi\n" /* ent */
        "cmpl (%edi), %eax\n"
        "je .Lf1a2444_001a26e9\n"
        "movl %ecx, %edx\n"
        "addl $0x14, %edx\n"
        /* { scope 2 */
        "movl 0x14(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* spawn_origin */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        /* } scope */
        "movl 0xec(%ecx), %edx\n" /* line 1455 | y */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, -0x3c(%ebp)\n" /* spawn_angles */
        "movl %edx, -0x38(%ebp)\n" /* line 192 */
        "movl %eax, -0x34(%ebp)\n" /* line 193 */
        /* } scope */
        "leal -0x3c(%ebp), %eax\n" /* line 1456 | spawn_angles */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* spawn_origin */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll ClientSpawn\n"
        "jmp .Lf1a2444_001a2623\n"
        /* { scope 2 */
        ".Lf1a2444_001a26c9:\n"
        "movl $0x40, 8(%esp)\n" /* line 1363 */
        "movl %esi, 4(%esp)\n" /* modelName */
        "movl %ebx, (%esp)\n" /* tagName */
        "calll I_strncpyz\n"
        "movl $1, -0x68(%ebp)\n" /* bChanged */
        "jmp .Lf1a2444_001a24e0\n"
        /* } scope */
        ".Lf1a2444_001a26e9:\n"
        "movzbl 0xf2(%edi), %eax\n" /* line 1463 */
        "orb $2, %al\n"
        "andb $0xfe, %al\n"
        "movb %al, 0xf2(%edi)\n"
        "movb $1, 0x161(%edi)\n" /* line 1464 */
        "movl -0x64(%ebp), %ecx\n" /* line 1466 | client */
        "movl 0xc(%ecx), %eax\n"
        "orl $0x00800000, %eax\n"
        "andl $0xfcffffff, %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x273c(%ecx), %eax\n" /* line 1468 */
        "movl %eax, 0xe4(%ecx)\n"
        "movl 8(%ebp), %edi\n" /* line 508 | ent */
        "movl 0x158(%edi), %edx\n"
        "movl 0x27ac(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1a2444_001a29ee\n"
        "movl $0, 0x11c(%edi)\n" /* line 509 */
        ".Lf1a2444_001a2741:\n"
        "movl -0x64(%ebp), %ecx\n" /* line 1472 | client */
        "movl $0, 0x281c(%ecx)\n"
        "movl 0x283c(%ecx), %edx\n" /* line 1474 */
        "movl imp_level, %eax\n"
        "cmpl 0x1ec(%eax), %edx\n"
        "jg .Lf1a2444_001a276b\n"
        "andl $0xffbfffff, 0xa0(%ecx)\n" /* line 1475 */
        ".Lf1a2444_001a276b:\n"
        "movl -0x64(%ebp), %edi\n" /* line 1477 | client */
        "movl 0x27ac(%edi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1a2444_001a2a51\n"
        "movl $2, 4(%edi)\n" /* line 1479 */
        ".Lf1a2444_001a2783:\n"
        "movl imp_g_gravity, %eax\n" /* line 1497 */
        "movl (%eax), %eax\n"
        "cvttss2si 8(%eax), %eax\n"
        "movl -0x64(%ebp), %ecx\n" /* client */
        "movl %eax, 0x48(%ecx)\n"
        "movl imp_g_speed, %eax\n" /* line 1500 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x50(%ecx)\n"
        "movss 0x5d4(%ecx), %xmm0\n" /* line 1502 */
        "divss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "movss %xmm0, 0x2810(%ecx)\n"
        "movl 8(%ebp), %edi\n" /* line 1504 | ent */
        "movl %edi, (%esp)\n"
        "calll Player_UpdateLookAtEntity\n"
        "movl %edi, (%esp)\n" /* line 1505 */
        "calll Player_UpdateCursorHints\n"
        "movl %edi, (%esp)\n" /* line 1508 */
        "calll P_DamageFeedback\n"
        "movl imp_level, %eax\n" /* line 1511 */
        "movl 0x1ec(%eax), %eax\n"
        "movl -0x64(%ebp), %edx\n" /* client */
        "subl 0x27b8(%edx), %eax\n"
        "cmpl $0x3e8, %eax\n"
        "jle .Lf1a2444_001a2a42\n"
        "orl $0x80, 8(%edi)\n" /* line 1513 */
        ".Lf1a2444_001a27fb:\n"
        "movl 8(%ebp), %edi\n" /* line 1520 | ent */
        "movl 0x194(%edi), %eax\n"
        "movl -0x64(%ebp), %edx\n" /* client */
        "movl %eax, 0x12c(%edx)\n"
        "movl $0, 0x84(%edi)\n" /* line 108 */
        "movl imp_g_smoothClients, %eax\n" /* line 1526 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1a2444_001a2a1b\n"
        "movl $1, (%esp)\n" /* line 1528 */
        "movl (%edx), %ecx\n"
        "movl %edi, %edx\n"
        "movl -0x64(%ebp), %eax\n" /* client */
        "calll G_PlayerStateToEntityStateExtrapolate\n"
        ".Lf1a2444_001a283b:\n"
        "movl 8(%ebp), %eax\n" /* line 1535 | ent */
        "movl 0x194(%eax), %ebx\n" /* obj */
        "testl %ebx, %ebx\n" /* obj */
        "jle .Lf1a2444_001a2b64\n"
        "movl %eax, (%esp)\n"
        "calll StuckInClient\n"
        "testl %eax, %eax\n"
        "je .Lf1a2444_001a2a81\n"
        "movl 8(%ebp), %edx\n" /* line 1536 | ent */
        "movl $0x4000000, 0x11c(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        ".Lf1a2444_001a286c:\n"
        "leal -0x24(%ebp), %ebx\n" /* line 1539 | vViewPos, obj */
        "movl %ebx, 4(%esp)\n" /* obj */
        "movl %ecx, (%esp)\n"
        "calll G_GetPlayerViewOrigin\n"
        "movl -0x64(%ebp), %edi\n" /* line 1541 | client */
        "movl 0x2838(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* obj */
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll G_GetNonPVSFriendlyInfo\n"
        "movl %eax, 0x5a4(%edi)\n"
        "testl %eax, %eax\n" /* line 1542 */
        "je .Lf1a2444_001a2aa7\n"
        "andl $0x3f, %eax\n" /* line 1544 */
        "movl %eax, 0x2838(%edi)\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 1546 */
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_g_entities, %eax\n"
        "testb $0x40, 0xa(%edx, %eax)\n"
        "je .Lf1a2444_001a2b8e\n"
        "orl $0x00800000, 0xa0(%edi)\n" /* line 1547 */
        ".Lf1a2444_001a28d7:\n"
        "movl 8(%ebp), %edi\n" /* line 1554 | ent */
        "cmpl $1, 4(%edi)\n"
        "jne .Lf1a2444_001a2623\n"
        "movl 0x194(%edi), %ecx\n" /* line 1560 */
        "testl %ecx, %ecx\n"
        "setle %al\n"
        "leal 9(%eax, %eax), %eax\n"
        "movb %al, 0x166(%edi)\n"
        "movl 8(%ebp), %ecx\n" /* line 1563 | ent */
        "movl 0x90(%ecx), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl imp_level_bgs, %edx\n"
        "leal 0xb3bf0(%edx, %eax, 8), %eax\n"
        "leal 0xc(%eax), %esi\n" /* ci */
        "movl 8(%ebp), %edi\n" /* line 1566 | ent */
        "movl 0x6c(%edi), %edx\n"
        "movl %edx, 0x3e0(%esi)\n" /* ci */
        "movl 0xd4(%edi), %edx\n" /* line 1567 */
        "movl %edx, 0x3e4(%esi)\n" /* ci */
        "leal 0x3f4(%eax), %ebx\n" /* line 1568 | to */
        "movl -0x64(%ebp), %ecx\n" /* client, from */
        "addl $0xe8, %ecx\n" /* from */
        /* { scope 2 */
        "movl -0x64(%ebp), %edi\n" /* line 199 | client */
        "movl 0xe8(%edi), %edx\n"
        "movl %edx, 0x3f4(%eax)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movl -0x68(%ebp), %edx\n" /* line 1570 | bChanged */
        "testl %edx, %edx\n"
        "jne .Lf1a2444_001a2bcb\n"
        ".Lf1a2444_001a296c:\n"
        "movl 8(%ebp), %edx\n" /* line 1572 | ent */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %eax, %ebx\n" /* to */
        "movl 8(%ebp), %ecx\n" /* line 1573 | ent */
        "movzbl 0x165(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* ci */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* to */
        "calll BG_UpdatePlayerDObj\n"
        "movl %esi, 8(%esp)\n" /* line 1574 | ci */
        "movl 8(%ebp), %edi\n" /* ent */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* to */
        "calll BG_PlayerAnimation\n"
        "movl -0x64(%ebp), %eax\n" /* line 1576 | client */
        "testb $0x80, 0xe(%eax)\n"
        "je .Lf1a2444_001a29c5\n"
        "testl $0x300, 0xa0(%eax)\n"
        "jne .Lf1a2444_001a2c0a\n"
        ".Lf1a2444_001a29c5:\n"
        "movl imp_g_debugLocDamage, %eax\n" /* line 1584 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1a2444_001a2ba0\n"
        ".Lf1a2444_001a29d6:\n"
        "movl 8(%ebp), %edx\n" /* line 1591 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl $0, 0x27c8(%eax)\n"
        "jmp .Lf1a2444_001a2633\n"
        ".Lf1a2444_001a29ee:\n"
        "movl 0x27b0(%edx), %eax\n" /* line 510 */
        "testl %eax, %eax\n"
        "jne .Lf1a2444_001a2a95\n"
        "xorl %eax, %eax\n" /* line 513 */
        "cmpl $1, 0x26a8(%edx)\n"
        "movl $0x2000000, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %eax, 0x11c(%edx)\n"
        "jmp .Lf1a2444_001a2741\n"
        ".Lf1a2444_001a2a1b:\n"
        "movl $1, 0xc(%esp)\n" /* line 1532 */
        "movl $1, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl %ecx, 4(%esp)\n"
        "movl -0x64(%ebp), %edi\n" /* client */
        "movl %edi, (%esp)\n"
        "calll BG_PlayerStateToEntityState\n"
        "jmp .Lf1a2444_001a283b\n"
        ".Lf1a2444_001a2a42:\n"
        "movl 8(%ebp), %ecx\n" /* line 1517 | ent */
        "andl $0xffffff7f, 8(%ecx)\n"
        "jmp .Lf1a2444_001a27fb\n"
        ".Lf1a2444_001a2a51:\n"
        "movl 0x27b0(%edi), %esi\n" /* line 1481 | ci */
        "testl %esi, %esi\n" /* ci */
        "jne .Lf1a2444_001a2a89\n"
        "movl %edi, %edx\n"
        "cmpl $1, 0x26a8(%edi)\n" /* line 1485 */
        "je .Lf1a2444_001a2bdb\n"
        "movl 8(%ebp), %edi\n" /* line 1494 | ent */
        "xorl %eax, %eax\n"
        "cmpl $0, 0x208(%edi)\n"
        "setne %al\n"
        "movl %eax, 4(%edx)\n"
        "jmp .Lf1a2444_001a2783\n"
        ".Lf1a2444_001a2a81:\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "jmp .Lf1a2444_001a286c\n"
        ".Lf1a2444_001a2a89:\n"
        "movl $3, 4(%edi)\n" /* line 1483 */
        "jmp .Lf1a2444_001a2783\n"
        ".Lf1a2444_001a2a95:\n"
        "movl 8(%ebp), %eax\n" /* line 511 | ent */
        "movl $0, 0x11c(%eax)\n"
        "jmp .Lf1a2444_001a2741\n"
        ".Lf1a2444_001a2aa7:\n"
        "movl -0x64(%ebp), %ecx\n" /* line 1552 | client */
        "movl $0x3ff, 0x2838(%ecx)\n"
        "jmp .Lf1a2444_001a28d7\n"
        /* { scope 2 */
        ".Lf1a2444_001a2ab9:\n"
        "movl 8(%ebp), %ecx\n" /* line 1038 | ent */
        "movl 0x158(%ecx), %edx\n"
        "movzbl 0xf2(%ecx), %eax\n" /* line 1041 */
        "andb $0xfd, %al\n"
        "orb $1, %al\n"
        "movb %al, 0xf2(%ecx)\n"
        "movb $0, 0x161(%ecx)\n" /* line 1042 */
        "movl $0, 0x11c(%ecx)\n" /* line 1043 */
        "andl $0xfc7fffff, 0xc(%edx)\n" /* line 1044 */
        "movl $5, 4(%edx)\n" /* line 1046 */
        "andl $0xffdfffbf, 0xa0(%edx)\n" /* line 1049 */
        "movl $0, 0xe4(%edx)\n" /* line 1051 */
        "movl $5, 4(%ecx)\n" /* line 1053 */
        "movl imp_level, %ebx\n" /* line 1057 */
        "movl 0x200(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $5, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0x204(%ebx), %eax\n" /* line 1058 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $6, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf1a2444_001a2620\n"
        ".Lf1a2444_001a2b64:\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1a2444_001a286c\n"
        /* } scope */
        ".Lf1a2444_001a2b6b:\n"
        "movl 8(%ebp), %eax\n" /* line 1447 | ent */
        "movl %eax, (%esp)\n"
        "calll SpectatorClientEndFrame\n"
        "movl 8(%ebp), %edx\n" /* line 1448 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl $0, 0x27c8(%eax)\n"
        "jmp .Lf1a2444_001a2633\n"
        ".Lf1a2444_001a2b8e:\n"
        "movl -0x64(%ebp), %edx\n" /* line 1549 | client */
        "andl $0xff7fffff, 0xa0(%edx)\n"
        "jmp .Lf1a2444_001a28d7\n"
        ".Lf1a2444_001a2ba0:\n"
        "movl 8(%ebp), %ecx\n" /* line 1584 | ent */
        "movl %ecx, (%esp)\n"
        "calll SV_DObjExists\n"
        "testl %eax, %eax\n"
        "je .Lf1a2444_001a29d6\n"
        "movl 8(%ebp), %edi\n" /* line 1586 | ent */
        "movl %edi, (%esp)\n"
        "calll G_DObjCalcPose\n"
        "movl %edi, (%esp)\n" /* line 1587 */
        "calll SV_XModelDebugBoxes\n"
        "jmp .Lf1a2444_001a29d6\n"
        ".Lf1a2444_001a2bcb:\n"
        "movl 8(%ebp), %eax\n" /* line 1571 | ent */
        "movl %eax, (%esp)\n"
        "calll G_SafeDObjFree\n"
        "jmp .Lf1a2444_001a296c\n"
        ".Lf1a2444_001a2bdb:\n"
        "movl 8(%ebp), %ecx\n" /* line 1487 | ent */
        "cmpl $1, 0x208(%ecx)\n"
        "sbbl %eax, %eax\n"
        "addl $7, %eax\n"
        "movl %eax, 4(%edi)\n"
        "movzbl 0xf2(%ecx), %eax\n" /* line 1489 */
        "orb $1, %al\n"
        "andb $0xfd, %al\n"
        "movb %al, 0xf2(%ecx)\n"
        "movb $0, 0x161(%ecx)\n" /* line 1490 */
        "jmp .Lf1a2444_001a2783\n"
        ".Lf1a2444_001a2c0a:\n"
        "movl 0x594(%eax), %eax\n" /* line 1581 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl imp_level, %eax\n"
        "addl 4(%eax), %edx\n"
        "movl %edx, (%esp)\n"
        "calll turret_think_client\n"
        "jmp .Lf1a2444_001a29c5\n"
    );
}

#else

void ClientImpacts(gentity_t *ent, pmove_t *pm) {
    int i, j;
    gentity_t *other;
    void (*entTouch)(gentity_t *, gentity_t *, int);
    void (*otherTouch)(gentity_t *, gentity_t *, int);
    const scr_const_t *scr = (const scr_const_t *)imp_scr_const;
    int numtouch;
    int *touchents;
    int entityNum;
    int duplicate;

    entTouch = entityHandlers[ent->handler].touch;

    numtouch = pm->numtouch;
    if (numtouch <= 0)
        return;

    touchents = pm->touchents;
    entityNum = touchents[0];

    for (i = 0; ; ) {
        other = &g_entities[entityNum];

        /* Notify scripts about the touch event */
        if (((int (*)(int))Scr_IsSystemActive)(1)) {
            Scr_AddEntity(other);
            Scr_Notify(ent, scr->touch, 1);
            Scr_AddEntity(ent);
            Scr_Notify(other, scr->touch, 1);
        }

        otherTouch = entityHandlers[other->handler].touch;
        if (otherTouch) {
            otherTouch(other, ent, 1);
        }

        /* Call this entity's touch handler */
        if (entTouch) {
            entTouch(ent, other, 1);
        }

next_iteration:
        i++;
        if (i >= pm->numtouch)
            break;

        /* Duplicate check: scan previous entries */
        entityNum = touchents[i];

        if (i > 0) {
            /* Check against all previous entries */
            duplicate = 0;
            for (j = 0; j < i; j++) {
                if (touchents[j] == entityNum) {
                    duplicate = 1;
                    break;
                }
            }
            if (duplicate)
                goto next_iteration;
        }
    }
}
#endif
