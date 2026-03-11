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
extern qboolean G_SpawnFloat(const char *key, const char *defaultString, float *out);
extern qboolean G_SpawnInt(const char *key, const char *defaultString, int *out);
extern void Com_Error(int code, const char *fmt, ...);
extern DObj_s * Com_GetServerDObj(int entNum);
extern void DObjSetControlTagAngles(DObj_s *obj, int *partBits, unsigned short tag, vec_t *angles);
extern void SV_UnlinkEntity(gentity_t *ent);
extern void SV_LinkEntity(gentity_t *ent);
extern void SetClientViewAngle(gentity_t *ent, vec_t *angles);
extern void BG_PlayerStateToEntityState(playerState_t *ps, gentity_t *ent, qboolean snap, qboolean forceSnap);
extern void G_AddEvent(gentity_t *ent, int event, int eventParm);
extern WeaponDef *BG_GetWeaponDef(int iWeapon);
extern float AngleSubtract(float a, float b);
extern unsigned char G_PlaySoundAlias(gentity_t *ent, int index);
extern float AngleNormalize180(float angle);
extern void YawVectors(const vec_t yaw, vec_t *forward, vec_t *right);
extern float Vec3Normalize(vec_t *v);
extern float Q_acos(float x);
extern unsigned char G_GeneralLink(gentity_t *ent);
extern DObjAnimMat_s *G_DObjGetLocalTagMatrix(gentity_t *ent, unsigned int tagName);
extern void AnglesToAxis(const vec_t *angles, vec_t *axis);
extern void MatrixTransformVector(const vec_t *in1, const vec_t *in2, vec_t *out);
extern void MatrixTransformVector43(const vec_t *in, const vec_t *mat, vec_t *out);
extern int G_LocationalTrace(trace_t *results, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask, unsigned char *priorityMap);
extern unsigned char bulletPriorityMap[19];
extern float AngleNormalize360Accurate(float angle);
extern int G_GetWeaponIndexForName(const char *name);
extern void Scr_Error(const char *msg);
extern const char *va(const char *fmt, ...);
extern qboolean IsItemRegistered(unsigned int item);
extern SoundAlias G_SoundAliasIndex(const char *name);
extern void G_DObjUpdate(gentity_t *ent);
extern void G_SetAngle(gentity_t *ent, const vec_t *angles);

extern unsigned char turretInfo[]; /* turretInfo - bss.c */

enum {
    GMISC_TURRET_STANCE_INVALID = -1,
    GMISC_TURRET_STANCE_CROUCH = 1,
    GMISC_TURRET_STANCE_PRONE = 2,
    GMISC_EV_STANCE_FORCE_STAND = 0x8c,
    GMISC_EV_STANCE_FORCE_CROUCH = 0x8d,
    GMISC_EV_STANCE_FORCE_PRONE = 0x8e,
    GMISC_ENTITYNUM_NONE = 0x3ff,
    GMISC_EF_FIRING = 0x40,
    GMISC_PMF_PRONE = 0x1,
    GMISC_PMF_DUCKED = 0x2,
    GMISC_EF_TURRET_PRONE = 0x100,
    GMISC_EF_TURRET_DUCK = 0x200,
    GMISC_EF_TURRET_ACTIVE = 0x300,
    GMISC_ENT_HANDLER_TURRET_INIT = 13,
    GMISC_ENT_HANDLER_TURRET = 14,
    GMISC_ET_TURRET = 9,
    GMISC_CONTENTS_SOLID = 0x1,
    GMISC_CONTENTS_NONCOLLIDING = 0x4,
    GMISC_CONTENTS_DONOTENTER = 0x200000,
    GMISC_TURRET_TRACE_MASK = 0x811
};

/* `pitchCap` is the generated name for the reference field `triggerDown`. */
#define GMISC_TRIGGER_DOWN(info) ((info)->pitchCap)

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

static qboolean turret_UpdateTargetAngles(gentity_t *self, const float *desiredAngles, qboolean bManned)
{
    vec2_t downAngles;
    vec2_t speed;
    turretInfo_s *info;
    qboolean complete;
    float delta;
    int i;

    info = self->pTurretInfo;
    complete = 1;

    downAngles[1] = self->s.angles2[0];
    self->s.angles2[0] = downAngles[1] + self->s.angles2[2];

    if (bManned) {
        WeaponDef *weapDef = BG_GetWeaponDef(self->s.weapon);
        speed[0] = weapDef->maxTurnSpeed[0];
        speed[1] = weapDef->maxTurnSpeed[1];
    } else {
        speed[0] = 200.0f;
        speed[1] = 200.0f;
    }

    if ((info->flags & 0x200) && (info->flags & 0x100) && speed[0] < 360.0f) {
        speed[0] = 360.0f;
    }

    for (i = 0; i < 2; ++i) {
        speed[i] = speed[i] * 0.050000001f;
        delta = AngleSubtract(desiredAngles[i], self->s.angles2[i]);

        if (delta > speed[i]) {
            complete = 0;
            delta = speed[i];
        } else if (-speed[i] > delta) {
            complete = 0;
            delta = -speed[i];
        }

        self->s.angles2[i] += delta;
    }

    downAngles[0] = self->s.angles2[0];
    self->s.angles2[2] = downAngles[0];

    if (info->flags & 0x200) {
        if (info->flags & 0x400) {
            if (GMISC_TRIGGER_DOWN(info) > self->s.angles2[0]) {
                downAngles[0] = GMISC_TRIGGER_DOWN(info);
            } else {
                info->flags &= ~0x100u;
            }
        } else if (self->s.angles2[0] > GMISC_TRIGGER_DOWN(info)) {
            downAngles[0] = GMISC_TRIGGER_DOWN(info);
        } else {
            info->flags &= ~0x100u;
        }
    }

    delta = AngleSubtract(downAngles[0], downAngles[1]);
    if (delta > speed[0]) {
        complete = 0;
        delta = speed[0];
    } else if (-speed[0] > delta) {
        complete = 0;
        delta = -speed[0];
    }

    self->s.angles2[0] = downAngles[1] + delta;
    self->s.angles2[2] = self->s.angles2[2] - self->s.angles2[0];
    return complete;
}

static void turret_UpdateSound(gentity_t *self)
{
    turretInfo_s *info;

    info = self->pTurretInfo;
    self->s.loopSound = 0;

    if (info->fireSndDelay <= 0) {
        return;
    }

    self->s.loopSound = (unsigned char)info->fireSnd;
    info->fireSndDelay -= 50;
    if (info->fireSndDelay > 0 || !info->stopSnd) {
        return;
    }

    self->s.loopSound = 0;
    G_PlaySoundAlias(self, info->stopSnd);
}

static qboolean turret_ReturnToDefaultPos(gentity_t *self, qboolean bManned)
{
    vec2_t desiredAngles;
    turretInfo_s *info;

    info = self->pTurretInfo;
    desiredAngles[0] = bManned ? 0.0f : info->dropPitch;
    desiredAngles[1] = 0.0f;
    return turret_UpdateTargetAngles(self, desiredAngles, bManned);
}

static qboolean turret_behind(gentity_t *self, gentity_t *other)
{
    vec3_t dir;
    vec3_t forward;
    turretInfo_s *info;
    float angle;
    float centerYaw;
    float dot;
    float minYaw;
    float yawSpan;

    info = self->pTurretInfo;
    minYaw = self->r.currentAngles[1] + info->arcmin[1];
    yawSpan = ((info->arcmax[1] < 0.0f ? -info->arcmax[1] : info->arcmax[1]) +
        (info->arcmin[1] < 0.0f ? -info->arcmin[1] : info->arcmin[1])) * 0.5f;
    centerYaw = AngleNormalize180(minYaw + yawSpan);

    YawVectors(centerYaw, forward, 0);
    Vec3Normalize(forward);

    dir[0] = self->r.currentOrigin[0] - other->r.currentOrigin[0];
    dir[1] = self->r.currentOrigin[1] - other->r.currentOrigin[1];
    dir[2] = 0.0f;
    Vec3Normalize(dir);

    dot = forward[0] * dir[0] + forward[1] * dir[1] + forward[2] * dir[2];
    if (dot < -1.0f) {
        dot = -1.0f;
    } else if (dot > 1.0f) {
        dot = 1.0f;
    }

    angle = Q_acos(dot) * 57.29577951308232f;
    return yawSpan >= angle;
}

/* line 724 */
void turret_think(gentity_t *self)
{
    self->nextthink = ((level_locals_t *)imp_level)->time + 50;

    if (self->tagInfo) {
        G_GeneralLink(self);
    }

    if (!((gentity_t *)imp_g_entities)[self->r.ownerNum].client) {
        turret_UpdateSound(self);
        self->s.eFlags &= ~GMISC_EF_FIRING;
        turret_ReturnToDefaultPos(self, 0);
    }
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
void G_ClientStopUsingTurret(gentity_t *self)
{
    turretInfo_s *pTurretInfo;
    gentity_t *owner;

    pTurretInfo = self->pTurretInfo;
    owner = &((gentity_t *)imp_g_entities)[self->r.ownerNum];

    pTurretInfo->fireSndDelay = 0;
    self->s.loopSound = 0;

    if (pTurretInfo->prevStance != GMISC_TURRET_STANCE_INVALID) {
        if (pTurretInfo->prevStance == GMISC_TURRET_STANCE_PRONE) {
            G_AddEvent(owner, GMISC_EV_STANCE_FORCE_PRONE, 0);
        } else if (pTurretInfo->prevStance == GMISC_TURRET_STANCE_CROUCH) {
            G_AddEvent(owner, GMISC_EV_STANCE_FORCE_CROUCH, 0);
        } else {
            G_AddEvent(owner, GMISC_EV_STANCE_FORCE_STAND, 0);
        }

        pTurretInfo->prevStance = GMISC_TURRET_STANCE_INVALID;
    }

    TeleportPlayer(owner, pTurretInfo->userOrigin, owner->r.currentAngles);

    owner->client->ps.eFlags &= ~0x300;
    owner->client->ps.viewlocked = 0;
    owner->client->ps.viewlocked_entNum = GMISC_ENTITYNUM_NONE;
    owner->active = 0;
    owner->s.otherEntityNum = 0;

    self->active = 0;
    self->r.ownerNum = GMISC_ENTITYNUM_NONE;
    pTurretInfo->flags &= ~0x800u;
}

/* line 861 */
void G_FreeTurret(gentity_t *self)
{
    if (((gentity_t *)imp_g_entities)[self->r.ownerNum].client) {
        G_ClientStopUsingTurret(self);
    }

    self->active = 0;
    self->pTurretInfo->inuse = 0;
    self->pTurretInfo = 0;
}

/* line 756 */
void turret_think_init(gentity_t *self)
{
    float baseMtx[4][3];
    float mtx[3][3];
    vec3_t dir;
    vec3_t start;
    vec3_t end;
    vec3_t transDir;
    vec3_t angles;
    trace_t trace;
    DObjAnimMat_s *aimMtx;
    DObjAnimMat_s *weaponMtx;
    turretInfo_s *info;
    int i;

    info = self->pTurretInfo;
    self->handler = GMISC_ENT_HANDLER_TURRET;
    self->nextthink = ((level_locals_t *)imp_level)->time + 50;

    aimMtx = G_DObjGetLocalTagMatrix(self, ((scr_const_t *)imp_scr_const)->tag_aim);
    if (!aimMtx) {
        return;
    }

    weaponMtx = G_DObjGetLocalTagMatrix(self, ((scr_const_t *)imp_scr_const)->tag_butt);
    if (!weaponMtx) {
        return;
    }

    AnglesToAxis(self->r.currentAngles, (vec_t *)baseMtx);
    baseMtx[3][0] = self->r.currentOrigin[0];
    baseMtx[3][1] = self->r.currentOrigin[1];
    baseMtx[3][2] = self->r.currentOrigin[2];

    dir[0] = weaponMtx->trans[0] - aimMtx->trans[0];
    dir[1] = weaponMtx->trans[1] - aimMtx->trans[1];
    dir[2] = weaponMtx->trans[2] - aimMtx->trans[2];

    MatrixTransformVector43(aimMtx->trans, (vec_t *)baseMtx, start);

    for (i = 0; i <= 30; ++i) {
        angles[0] = -3.0f * (float)i;
        angles[1] = 0.0f;
        angles[2] = 0.0f;

        AnglesToAxis(angles, (vec_t *)mtx);
        MatrixTransformVector(dir, (vec_t *)mtx, transDir);

        transDir[0] += aimMtx->trans[0];
        transDir[1] += aimMtx->trans[1];
        transDir[2] += aimMtx->trans[2];

        MatrixTransformVector43(transDir, (vec_t *)baseMtx, end);
        G_LocationalTrace(&trace, start, end, self->s.number, GMISC_TURRET_TRACE_MASK, bulletPriorityMap);

        if (trace.fraction < 1.0f) {
            info->dropPitch = angles[0];
            return;
        }
    }
}

/* line 878 */
qboolean G_IsTurretUsable(gentity_t *self, gentity_t *owner)
{
    if (self->active || !self->pTurretInfo) {
        return 0;
    }

    if (!turret_behind(self, owner)) {
        return 0;
    }

    if (owner->client->ps.grenadeTimeLeft) {
        return 0;
    }

    if (owner->client->ps.groundEntityNum == GMISC_ENTITYNUM_NONE) {
        return 0;
    }

    return 1;
}

/* line 896 */
void turret_use(gentity_t *self, gentity_t *owner, gentity_t *activator)
{
    playerState_t *ps;
    turretInfo_s *info;
    float pitch;
    float yaw;

    (void)activator;

    info = self->pTurretInfo;
    ps = &owner->client->ps;

    owner->active = 1;
    self->active = 1;
    self->r.ownerNum = owner->s.number;

    ps->viewlocked = 1;
    ps->viewlocked_entNum = self->s.number;

    info->flags |= 0x800u;

    info->userOrigin[0] = owner->r.currentOrigin[0];
    info->userOrigin[1] = owner->r.currentOrigin[1];
    info->userOrigin[2] = owner->r.currentOrigin[2];

    owner->s.otherEntityNum = self->s.number;
    self->s.otherEntityNum = owner->s.number;

    if (ps->pm_flags & GMISC_PMF_PRONE) {
        info->prevStance = GMISC_TURRET_STANCE_PRONE;
    } else {
        info->prevStance = (ps->pm_flags & GMISC_PMF_DUCKED) ? GMISC_TURRET_STANCE_CROUCH : 0;
    }

    if (info->stance == GMISC_TURRET_STANCE_PRONE) {
        ps->eFlags |= GMISC_EF_TURRET_PRONE;
        ps->eFlags &= ~GMISC_EF_TURRET_DUCK;
    } else if (info->stance == GMISC_TURRET_STANCE_CROUCH) {
        ps->eFlags |= GMISC_EF_TURRET_DUCK;
        ps->eFlags &= ~GMISC_EF_TURRET_PRONE;
    } else {
        ps->eFlags |= GMISC_EF_TURRET_ACTIVE;
    }

    pitch = AngleSubtract(ps->viewangles[0], self->r.currentAngles[0]);
    if (pitch < info->arcmin[0]) {
        pitch = info->arcmin[0];
    } else if (pitch > info->arcmax[0]) {
        pitch = info->arcmax[0];
    }
    self->s.angles2[0] = pitch;

    yaw = AngleSubtract(ps->viewangles[1], self->r.currentAngles[1]);
    if (yaw < info->arcmin[1]) {
        yaw = info->arcmin[1];
    } else if (yaw > info->arcmax[1]) {
        yaw = info->arcmax[1];
    }
    self->s.angles2[1] = yaw;
    self->s.angles2[2] = 0.0f;

    ps->viewAngleClampRange[0] = AngleSubtract(info->arcmax[0], info->arcmin[0]) * 0.5f;
    ps->viewAngleClampBase[0] = self->r.currentAngles[0] + info->arcmax[0];
    ps->viewAngleClampBase[0] = AngleNormalize360Accurate(ps->viewAngleClampBase[0] - ps->viewAngleClampRange[0]);

    ps->viewAngleClampRange[1] = AngleSubtract(info->arcmax[1], info->arcmin[1]) * 0.5f;
    ps->viewAngleClampBase[1] = self->r.currentAngles[1] + info->arcmax[1];
    ps->viewAngleClampBase[1] = AngleNormalize360Accurate(ps->viewAngleClampBase[1] - ps->viewAngleClampRange[1]);
}

/* line 971 */
void G_SpawnTurret(gentity_t *self, const char *weaponinfoname)
{
    turretInfo_s *info;
    WeaponDef *weapDef;
    int i;

    info = 0;
    for (i = 0; i < 32; ++i) {
        info = (turretInfo_s *)&turretInfo[i * (int)sizeof(turretInfo_s)];
        if (!info->inuse) {
            break;
        }
    }

    if (i == 32) {
        Com_Error(1, "G_SpawnTurret: max number of turrets (%d) exceeded", 32);
    }

    memset(info, 0, sizeof(*info));
    self->pTurretInfo = info;
    info->inuse = 1;

    self->s.weapon = G_GetWeaponIndexForName(weaponinfoname);
    if (!self->s.weapon) {
        Com_Error(1, "bad weaponinfo '%s' specified for turret", weaponinfoname);
    }

    weapDef = BG_GetWeaponDef(self->s.weapon);
    if (weapDef->weapClass != WEAPCLASS_TURRET) {
        Scr_Error(va("G_SpawnTurret: weapon '%s' isn't a turret. This usually indicates that the weapon failed to load.", weaponinfoname));
    }

    if (!((level_locals_t *)imp_level)->initializing && !IsItemRegistered((unsigned int)self->s.weapon)) {
        Scr_Error(va("turret '%s' not precached", weaponinfoname));
    }

    info->fireTime = 0;
    info->stance = weapDef->stance;
    info->prevStance = GMISC_TURRET_STANCE_INVALID;
    info->fireSndDelay = 0;

    if (weapDef->szFireLoopSound && *weapDef->szFireLoopSound) {
        info->fireSnd = G_SoundAliasIndex(weapDef->szFireLoopSound);
    }
    if (weapDef->szFireLoopSoundPlayer && *weapDef->szFireLoopSoundPlayer) {
        info->fireSndPlayer = G_SoundAliasIndex(weapDef->szFireLoopSoundPlayer);
    }
    if (weapDef->szFireStopSound && *weapDef->szFireStopSound) {
        info->stopSnd = G_SoundAliasIndex(weapDef->szFireStopSound);
    }
    if (weapDef->szFireStopSoundPlayer && *weapDef->szFireStopSoundPlayer) {
        info->stopSndPlayer = G_SoundAliasIndex(weapDef->szFireStopSoundPlayer);
    }

    if (!((level_locals_t *)imp_level)->spawnVar.spawnVarsValid || !G_SpawnFloat("rightarc", "", &info->arcmin[1])) {
        info->arcmin[1] = weapDef->rightArc;
    }
    info->arcmin[1] = -info->arcmin[1];
    if (info->arcmin[1] > 0.0f) {
        info->arcmin[1] = 0.0f;
    }

    if (!((level_locals_t *)imp_level)->spawnVar.spawnVarsValid || !G_SpawnFloat("leftarc", "", &info->arcmax[1])) {
        info->arcmax[1] = weapDef->leftArc;
    }
    if (info->arcmax[1] < 0.0f) {
        info->arcmax[1] = 0.0f;
    }

    if (!((level_locals_t *)imp_level)->spawnVar.spawnVarsValid || !G_SpawnFloat("toparc", "", &info->arcmin[0])) {
        info->arcmin[0] = weapDef->topArc;
    }
    info->arcmin[0] = -info->arcmin[0];
    if (info->arcmin[0] > 0.0f) {
        info->arcmin[0] = 0.0f;
    }

    if (!((level_locals_t *)imp_level)->spawnVar.spawnVarsValid || !G_SpawnFloat("bottomarc", "", &info->arcmax[0])) {
        info->arcmax[0] = weapDef->bottomArc;
    }
    if (info->arcmax[0] < 0.0f) {
        info->arcmax[0] = 0.0f;
    }

    info->dropPitch = -90.0f;

    if (!self->health) {
        self->health = 100;
    }

    if (!((level_locals_t *)imp_level)->spawnVar.spawnVarsValid || !G_SpawnInt("damage", "0", &self->damage)) {
        self->damage = weapDef->damage;
    }
    if (self->damage < 0) {
        self->damage = 0;
    }

    if (!((level_locals_t *)imp_level)->spawnVar.spawnVarsValid || !G_SpawnFloat("playerSpread", "1", &info->playerSpread)) {
        info->playerSpread = weapDef->playerSpread;
    }
    if (info->playerSpread < 0.0f) {
        info->playerSpread = 0.0f;
    }

    info->flags = 3;

    self->clipmask = GMISC_CONTENTS_SOLID;
    self->r.contents = GMISC_CONTENTS_NONCOLLIDING | GMISC_CONTENTS_DONOTENTER;
    self->r.svFlags = 0;
    self->s.eType = GMISC_ET_TURRET;
    self->flags |= 0x1000u;

    G_DObjUpdate(self);

    self->r.mins[0] = -32.0f;
    self->r.mins[1] = -32.0f;
    self->r.mins[2] = 0.0f;
    self->r.maxs[0] = 32.0f;
    self->r.maxs[1] = 32.0f;
    self->r.maxs[2] = 56.0f;

    G_SetOrigin(self, self->r.currentOrigin);
    G_SetAngle(self, self->r.currentAngles);

    self->s.angles2[0] = 0.0f;
    self->s.angles2[1] = 0.0f;
    self->s.angles2[2] = 0.0f;

    self->handler = GMISC_ENT_HANDLER_TURRET_INIT;
    self->nextthink = ((level_locals_t *)imp_level)->time + 50;

    self->s.apos.trType = TR_LINEAR_STOP;
    self->takedamage = 0;

    SV_LinkEntity(self);
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
