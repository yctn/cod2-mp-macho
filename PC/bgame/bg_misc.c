/* ASM dump from: bg_misc.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_misc.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 */

extern const dvar_t *player_view_pitch_up; /* 0x0 */
extern const dvar_t *player_view_pitch_down; /* 0x0 */
extern const dvar_t *bg_ladder_yawcap; /* 0x0 */
extern const dvar_t *bg_prone_yawcap; /* 0x0 */
extern const dvar_t *bg_foliagesnd_minspeed; /* 0x0 */
extern const dvar_t *bg_foliagesnd_maxspeed; /* 0x0 */
extern const dvar_t *bg_foliagesnd_slowinterval; /* 0x0 */
extern const dvar_t *bg_foliagesnd_fastinterval; /* 0x0 */
extern const dvar_t *bg_foliagesnd_resetinterval; /* 0x0 */
extern const dvar_t *bg_fallDamageMinHeight; /* 0x0 */
extern const dvar_t *bg_fallDamageMaxHeight; /* 0x0 */
extern const dvar_t *inertiaMax; /* 0x0 */
extern const dvar_t *inertiaDebug; /* 0x0 */
extern const dvar_t *inertiaAngle; /* 0x0 */
extern const dvar_t *friction; /* 0x0 */
extern const dvar_t *stopspeed; /* 0x0 */
extern const dvar_t *bg_swingSpeed; /* 0x0 */
extern const dvar_t *bg_bobAmplitudeStanding; /* 0x0 */
extern const dvar_t *bg_bobAmplitudeDucked; /* 0x0 */
extern const dvar_t *bg_bobAmplitudeProne; /* 0x0 */
extern const dvar_t *bg_bobMax; /* 0x0 */
extern const dvar_t *bg_aimSpreadMoveSpeedThreshold; /* 0x0 */
extern const dvar_t *player_breath_hold_time; /* 0x0 */
extern const dvar_t *player_breath_gasp_time; /* 0x0 */
extern const dvar_t *player_breath_fire_delay; /* 0x0 */
extern const dvar_t *player_breath_gasp_scale; /* 0x0 */
extern const dvar_t *player_breath_hold_lerp; /* 0x0 */
extern const dvar_t *player_breath_gasp_lerp; /* 0x0 */
extern const dvar_t *player_breath_snd_lerp; /* 0x0 */
extern const dvar_t *player_breath_snd_delay; /* 0x0 */
extern const dvar_t *player_toggleBinoculars; /* 0x0 */
extern const dvar_t *player_scopeExitOnDamage; /* 0x0 */
extern const dvar_t *player_adsExitDelay; /* 0x0 */
extern const dvar_t *player_dmgtimer_timePerPoint; /* 0x0 */
extern const dvar_t *player_dmgtimer_maxTime; /* 0x0 */
extern const dvar_t *player_dmgtimer_minScale; /* 0x0 */
extern const dvar_t *player_dmgtimer_stumbleTime; /* 0x0 */
extern const dvar_t *player_dmgtimer_flinchTime; /* 0x0 */
extern char * eventnames[199]; /* 0x0 */
extern const int singleClientEvents[7]; /* 0x0 */
extern const dvar_t *player_moveThreshhold; /* 0x0 */
extern const dvar_t *player_footstepsThreshhold; /* 0x0 */
extern const dvar_t *player_strafeSpeedScale; /* 0x0 */
extern const dvar_t *player_backSpeedScale; /* 0x0 */
extern const dvar_t *player_spectateSpeedScale; /* 0x0 */
extern const dvar_t *player_turnAnims; /* 0x0 */

/* Extern declarations for called functions */
extern int I_stricmp(const char *s1, const char *s2);
extern int G_GetWeaponIndexForName(const char *name);
extern qboolean BG_DoesWeaponNeedSlot(int weapon);
extern int BG_GetMaxPickupableAmmo(const playerState_t *ps, int weapon);
extern qboolean BG_WeaponIsClipOnly(int weapon);
extern void Com_Error(errorParm_t code, const char *fmt, ...);
extern const char *va(const char *format, ...);
extern const dvar_t *Dvar_RegisterFloat(const char *dvarName, float value, float min, float max, unsigned int flags);
extern const dvar_t *Dvar_RegisterInt(const char *dvarName, int value, int min, int max, unsigned int flags);
extern const dvar_t *Dvar_RegisterBool(const char *dvarName, qboolean value, unsigned int flags);
extern void Jump_RegisterDvars(void);
extern void Mantle_RegisterDvars(void);

void BG_RegisterDvars(void);
const gitem_t * BG_FindItemForWeapon(int weapon);
const gitem_t * G_FindItem(const char *pickupName);
void BG_AddPredictableEventToPlayerstate(int newEvent, int eventParm, playerState_t *ps);
extern int PM_GetEffectiveStance(void *ps);
extern int PM_GetViewHeightLerpTime(void *ps, int current, int target);
extern float AngleNormalize180(float angle);
void BG_PlayerStateToEntityState(playerState_t *ps, entityState_t *s, qboolean snap, int handler);
void BG_EvaluateTrajectoryDelta(const trajectory_t *tr, int atTime, vec_t *result);
qboolean BG_CanItemBeGrabbed(const entityState_t *ent, const playerState_t *ps, qboolean bTouched);
qboolean BG_CheckProneValid(int passEntityNum, const vec_t *vPos, const float fSize, const float fHeight, const float fYaw, float *pfTorsoHeight, float *pfTorsoPitch, float *pfWaistPitch, const qboolean bAlreadyProne, const qboolean bOnGround, vec_t *vGroundNormal, int handler, proneCheckType_t proneCheckType, float prone_feet_dist);
qboolean BG_CheckProne(int passEntityNum, const vec_t *vPos, const float fSize, const float fHeight, const float fYaw, float *pfTorsoHeight, float *pfTorsoPitch, float *pfWaistPitch, const qboolean bAlreadyProne, const qboolean bOnGround, vec_t *vGroundNormal, int handler, proneCheckType_t proneCheckType, float prone_feet_dist);
void BG_EvaluateTrajectory(const trajectory_t *tr, int atTime, vec_t *result);
qboolean BG_PlayerTouchesItem(playerState_t *ps, entityState_t *item, int atTime);

/* line 341 */
void BG_RegisterDvars(void)
{
    player_view_pitch_up = Dvar_RegisterFloat("player_view_pitch_up", 85.0f, 0.0f, 90.0f, 0x1180);
    player_view_pitch_down = Dvar_RegisterFloat("player_view_pitch_down", 85.0f, 0.0f, 90.0f, 0x1180);
    bg_ladder_yawcap = Dvar_RegisterFloat("bg_ladder_yawcap", 100.0f, 0.0f, 360.0f, 0x1180);
    bg_prone_yawcap = Dvar_RegisterFloat("bg_prone_yawcap", 85.0f, 0.0f, 360.0f, 0x1180);
    bg_foliagesnd_minspeed = Dvar_RegisterFloat("bg_foliagesnd_minspeed", 40.0f, 0.0f, 3.4028235e+38f, 0x1180);
    bg_foliagesnd_maxspeed = Dvar_RegisterFloat("bg_foliagesnd_maxspeed", 180.0f, 0.0f, 3.4028235e+38f, 0x1180);
    bg_foliagesnd_slowinterval = Dvar_RegisterInt("bg_foliagesnd_slowinterval", 1500, 0, 0x7fffffff, 0x1180);
    bg_foliagesnd_fastinterval = Dvar_RegisterInt("bg_foliagesnd_fastinterval", 500, 0, 0x7fffffff, 0x1180);
    bg_foliagesnd_resetinterval = Dvar_RegisterInt("bg_foliagesnd_resetinterval", 500, 0, 0x7fffffff, 0x1180);
    bg_fallDamageMinHeight = Dvar_RegisterFloat("bg_fallDamageMinHeight", 256.0f, 1.0f, 3.4028235e+38f, 0x1188);
    bg_fallDamageMaxHeight = Dvar_RegisterFloat("bg_fallDamageMaxHeight", 480.0f, 1.0f, 3.4028235e+38f, 0x1188);
    inertiaMax = Dvar_RegisterFloat("inertiaMax", 50.0f, 0.0f, 1000.0f, 0x1180);
    inertiaDebug = Dvar_RegisterBool("inertiaDebug", 0, 0x1180);
    inertiaAngle = Dvar_RegisterFloat("inertiaAngle", 0.0f, -1.0f, 1.0f, 0x1180);
    friction = Dvar_RegisterFloat("friction", 5.5f, 0.0f, 100.0f, 0x1180);
    stopspeed = Dvar_RegisterFloat("stopspeed", 100.0f, 0.0f, 1000.0f, 0x1180);
    bg_swingSpeed = Dvar_RegisterFloat("bg_swingSpeed", 0.2f, 0.0f, 1.0f, 0x1080);
    bg_bobAmplitudeStanding = Dvar_RegisterFloat("bg_bobAmplitudeStanding", 0.007f, 0.0f, 1.0f, 0x1180);
    bg_bobAmplitudeDucked = Dvar_RegisterFloat("bg_bobAmplitudeDucked", 0.0075f, 0.0f, 1.0f, 0x1180);
    bg_bobAmplitudeProne = Dvar_RegisterFloat("bg_bobAmplitudeProne", 0.03f, 0.0f, 1.0f, 0x1180);
    bg_bobMax = Dvar_RegisterFloat("bg_bobMax", 8.0f, 0.0f, 36.0f, 0x1180);
    bg_aimSpreadMoveSpeedThreshold = Dvar_RegisterFloat("bg_aimSpreadMoveSpeedThreshold", 11.0f, 0.0f, 300.0f, 0x1180);
    player_breath_hold_time = Dvar_RegisterFloat("player_breath_hold_time", 4.5f, 0.0f, 30.0f, 0x1180);
    player_breath_gasp_time = Dvar_RegisterFloat("player_breath_gasp_time", 1.0f, 0.0f, 30.0f, 0x1180);
    player_breath_fire_delay = Dvar_RegisterFloat("player_breath_fire_delay", 0.0f, 0.0f, 30.0f, 0x1180);
    player_breath_gasp_scale = Dvar_RegisterFloat("player_breath_gasp_scale", 4.5f, 0.0f, 50.0f, 0x1180);
    player_breath_hold_lerp = Dvar_RegisterFloat("player_breath_hold_lerp", 4.0f, 0.0f, 50.0f, 0x1180);
    player_breath_gasp_lerp = Dvar_RegisterFloat("player_breath_gasp_lerp", 6.0f, 0.0f, 50.0f, 0x1180);
    player_breath_snd_lerp = Dvar_RegisterFloat("player_breath_snd_lerp", 2.0f, 0.0f, 100.0f, 0x1180);
    player_breath_snd_delay = Dvar_RegisterFloat("player_breath_snd_delay", 1.0f, 0.0f, 2.0f, 0x1180);
    player_toggleBinoculars = Dvar_RegisterBool("player_toggleBinoculars", 1, 0x1100);
    player_scopeExitOnDamage = Dvar_RegisterBool("player_scopeExitOnDamage", 0, 0x1180);
    player_adsExitDelay = Dvar_RegisterInt("player_adsExitDelay", 0, 0, 1000, 0x1180);
    player_moveThreshhold = Dvar_RegisterFloat("player_moveThreshhold", 10.0f, 1.0e-8f, 20.0f, 0x11c0);
    player_footstepsThreshhold = Dvar_RegisterFloat("player_footstepsThreshhold", 0.0f, 0.0f, 50000.0f, 0x11c0);
    player_strafeSpeedScale = Dvar_RegisterFloat("player_strafeSpeedScale", 0.8f, 0.0f, 20.0f, 0x1180);
    player_backSpeedScale = Dvar_RegisterFloat("player_backSpeedScale", 0.7f, 0.0f, 20.0f, 0x1180);
    player_spectateSpeedScale = Dvar_RegisterFloat("player_spectateSpeedScale", 2.0f, 0.0f, 20.0f, 0x1180);
    player_turnAnims = Dvar_RegisterBool("player_turnAnims", 0, 0x1180);
    player_dmgtimer_timePerPoint = Dvar_RegisterFloat("player_dmgtimer_timePerPoint", 100.0f, 0.0f, 3.4028235e+38f, 0x1180);
    player_dmgtimer_maxTime = Dvar_RegisterFloat("player_dmgtimer_maxTime", 750.0f, 0.0f, 3.4028235e+38f, 0x1180);
    player_dmgtimer_minScale = Dvar_RegisterFloat("player_dmgtimer_minScale", 0.0f, 0.0f, 1.0f, 0x1180);
    player_dmgtimer_stumbleTime = Dvar_RegisterInt("player_dmgtimer_stumbleTime", 500, 0, 2000, 0x1180);
    player_dmgtimer_flinchTime = Dvar_RegisterInt("player_dmgtimer_flinchTime", 500, 0, 2000, 0x1180);
    Jump_RegisterDvars();
    Mantle_RegisterDvars();
}

/* line 463 */
const gitem_t *BG_FindItemForWeapon(int weapon)
{
    char *base = *(char **)imp_bg_itemlist;
    return (const gitem_t *)(base + weapon * 44);
}

/* line 476 */
const gitem_t *G_FindItem(const char *pickupName)
{
    int iIndex;
    int count;
    char *base;
    int weaponIndex;

    count = **(int **)imp_bg_numItems;
    base = *(char **)imp_bg_itemlist;

    for (iIndex = 0x81; iIndex < count; iIndex++) {
        char *it = base + iIndex * 44;
        if (I_stricmp(((gitem_t *)it)->pickup_name, pickupName) == 0) {
            return (const gitem_t *)it;
        }
        if (I_stricmp(*(const char **)it, pickupName) == 0) {
            return (const gitem_t *)it;
        }
    }

    weaponIndex = G_GetWeaponIndexForName(pickupName);
    if (weaponIndex == 0) {
        return NULL;
    }
    return (const gitem_t *)(base + weaponIndex * 44);
}

/* line 793 */
void BG_AddPredictableEventToPlayerstate(int newEvent, int eventParm, playerState_t *ps)
{
    int seq;
    int index;

    if (newEvent == 0)
        return;

    seq = ps->eventSequence;
    index = seq & 3;
    ps->events[index] = (unsigned char)newEvent;
    ps->eventParms[index] = (unsigned char)eventParm;
    ps->eventSequence = seq + 1;
}

/* line 819 */
void BG_PlayerStateToEntityState(playerState_t *ps, entityState_t *s, qboolean snap, int handler)
{
    int eFlags;
    int i;
    int stance;
    int eventSequence;
    int eventOld;
    int event;
    float lerpFrac;
    int lerpTime;
    int elapsed;

    /* line 828-829: s->eType from ps->pm_flags */
    {
        int val = ps->pm_flags & 0xc00000;
        int eType;
        if (val != 0) {
            eType = 1;
        } else {
            eType = 5;
        }
        s->eType = eType;
    }

    /* line 836 */
    s->pos.trType = 1;

    /* line 837: VectorCopy(ps->origin, s->pos.trBase) */
    s->pos.trBase[0] = ps->origin[0];
    s->pos.trBase[1] = ps->origin[1];
    s->pos.trBase[2] = ps->origin[2];

    /* line 840: snap */
    if (snap) {
        /* line 841: truncate to int and back to float */
        s->pos.trBase[0] = (float)(int)s->pos.trBase[0];
        s->pos.trBase[1] = (float)(int)s->pos.trBase[1];
        s->pos.trBase[2] = (float)(int)s->pos.trBase[2];
    }

    /* line 844 */
    s->apos.trType = 1;

    /* line 845: VectorCopy(ps->viewangles, s->apos.trBase) */
    s->apos.trBase[0] = ps->viewangles[0];
    s->apos.trBase[1] = ps->viewangles[1];
    s->apos.trBase[2] = ps->viewangles[2];

    /* line 848: snap angles */
    if (snap) {
        s->apos.trBase[0] = (float)(int)s->apos.trBase[0];
        s->apos.trBase[1] = (float)(int)s->apos.trBase[1];
        s->apos.trBase[2] = (float)(int)s->apos.trBase[2];
    }

    /* line 853: s->angles2[1] = (float)ps->movementDir */
    s->angles2[1] = (float)ps->movementDir;

    /* line 856 */
    s->legsAnim = ps->legsAnim;
    /* line 857 */
    s->torsoAnim = ps->torsoAnim;

    /* line 859 */
    s->groundEntityNum = ps->clientNum;

    /* line 863 */
    eFlags = ps->eFlags;
    s->eFlags = eFlags;

    /* line 867: check for melee */
    if (eFlags & 0x300) {
        /* line 868 */
        s->otherEntityNum = ps->cursorHintEntIndex;
    }

    /* line 870 */
    if (ps->pm_type > 5) {
        /* line 871 */
        eFlags = s->eFlags;
        eFlags |= 0x20000;
        s->eFlags = eFlags;
    } else {
        /* line 873 */
        eFlags = s->eFlags;
        eFlags &= ~0x20000;
        s->eFlags = eFlags;
    }

    /* line 876: check pm_flags crouch bit */
    if (ps->pm_flags & 0x40) {
        /* line 877 */
        eFlags |= 0x40000;
        s->eFlags = eFlags;
    } else {
        /* line 879 */
        eFlags &= ~0x40000;
        s->eFlags = eFlags;
    }

    /* line 882 */
    s->leanf = ps->leanf;

    /* line 885 */
    stance = PM_GetEffectiveStance(ps);

    if (stance == 1) {
        /* line 890: view height lerp */
        int viewHeightLerpTarget = ps->viewHeightLerpTime;
        if (viewHeightLerpTarget != 0) {
            /* line 892 */
            lerpTime = PM_GetViewHeightLerpTime(ps, ps->viewHeightLerpDown, ps->viewHeightLerpTarget);
            /* line 893 */
            elapsed = ps->commandTime - ps->viewHeightLerpTime;
            lerpFrac = (float)elapsed / (float)lerpTime;

            /* line 894 */
            if (lerpFrac < 0.0f) {
                lerpFrac = 0.0f;
            } else {
                /* line 896 */
                if (1.0f < lerpFrac) {
                    lerpFrac = 1.0f;
                }
            }

            /* line 898 */
            if (ps->viewHeightLerpDown != 0) {
                /* going down: lerpFrac stays */
            } else {
                /* line 899: going up: invert */
                lerpFrac = 1.0f - lerpFrac;
            }
        } else {
            lerpFrac = 1.0f;
        }

        /* line 906 */
        s->fTorsoHeight = lerpFrac * ps->fTorsoHeight;
        /* line 907 */
        s->fTorsoPitch = AngleNormalize180(ps->fTorsoPitch) * lerpFrac;
        /* line 908 */
        s->fWaistPitch = AngleNormalize180(ps->fWaistPitch) * lerpFrac;
    } else {
        /* line 912-914 */
        s->fTorsoHeight = 0;
        s->fTorsoPitch = 0;
        s->fWaistPitch = 0;
    }

    /* line 918: event handling */
    eventOld = ps->entityEventSequence;
    eventSequence = ps->eventSequence;

    if (eventOld < eventSequence) {
        /* line 922 */
        if (eventSequence - eventOld > 4) {
            /* line 923: too many events, skip */
            eventOld = eventSequence - 4;
            ps->entityEventSequence = eventOld;
        }

        /* line 927: copy first old event */
        {
            int idx = eventOld & 3;
            s->eventParm = (unsigned char)ps->eventParms[idx];
            ps->entityEventSequence = eventOld + 1;
        }
    } else {
        /* line 932 */
        s->eventParm = 0;
    }

    /* line 939: copy events to entityState */
    i = ps->oldEventSequence;
    if (i != ps->eventSequence) {
        byte handlerIdx = (unsigned char)handler;
        byte *handlerTable = *(byte **)imp_pmoveHandlers + handlerIdx * 12;

        while (i != ps->eventSequence) {
            int slot = i & 3;
            event = (unsigned char)ps->events[slot];

            /* line 947-949: call pmoveHandler event callback if present */
            {
                void (*eventCallback)(int, int) = *(void (**)(int, int))(handlerTable + 8);
                if (eventCallback) {
                    eventCallback(s->number, event & 0xff);
                }
            }

            /* line 955: check if this is a single-client event (0x8c) or in list */
            if ((event & 0xff) == 0x8c) {
                /* single client event, skip copy */
            } else {
                /* line 953-956: search singleClientEvents list */
                int j = 0;
                int found = 0;
                while (singleClientEvents[j + 1] > 0) {
                    j++;
                    if (singleClientEvents[j] == (event & 0xff)) {
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    /* line 958: check flag */
                    if (singleClientEvents[j] < 0) {
                        /* line 961: copy event to entityState */
                        int seqOut = s->eventSequence;
                        int outSlot = seqOut & 3;
                        s->events[outSlot] = event & 0xff;
                        /* line 962: copy event parm */
                        s->eventParms[outSlot] = (unsigned char)ps->eventParms[slot];
                        /* line 963 */
                        s->eventSequence = seqOut + 1;
                    }
                }
            }

            i++;
        }
    }

    /* line 965: sync event sequence */
    ps->oldEventSequence = i;

    /* line 967 */
    s->weapon = (unsigned char)ps->weapon;
    /* line 968 */
    s->groundEntityNum = (unsigned short)ps->groundEntityNum;
}
