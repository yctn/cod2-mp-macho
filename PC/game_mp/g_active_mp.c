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
#define SCR_CONST()                 ((const scr_const_t *)imp_scr_const)

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

void ClientImpacts(gentity_t *ent, pmove_t *pm) {
    int i, j;
    gentity_t *other;
    void (*entTouch)(gentity_t *, gentity_t *, int);
    void (*otherTouch)(gentity_t *, gentity_t *, int);
    const scr_const_t *scr = SCR_CONST();
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
