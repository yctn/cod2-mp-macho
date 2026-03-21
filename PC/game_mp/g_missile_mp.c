/* Decompiled from: g_missile_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_missile_mp.cpp */

#include "common_types.h"
#include "imports.h"
/* math.h/stdlib.h conflict with imports/libc.h, declare needed functions directly */
extern float sqrtf(float x);
extern float tanf(float x);
extern int rand(void);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/q_shared.h"
 */

/*
 * Binary gentity_s layout differs from common_types.h by +4 bytes starting at 'r'.
 * All field access uses byte pointer arithmetic with binary offsets.
 *
 * Key offsets (binary):
 *   0x00  s.number           0x08  s.eFlags           0x0C  s.pos
 *   0x04  s.eType            0x30  s.apos             0x54  s.time
 *   0x7C  s.groundEntityNum  0x88  s.surfType         0xC8  s.weapon
 *   0xF0  r (entityShared_t) 0xF2  r.svFlags          0x138 r.currentOrigin
 *   0x144 r.currentAngles    0x150 r.ownerNum         0x158 client
 *   0x161 takedamage         0x166 handler            0x168 classname
 *   0x174 flags              0x17C freeAfterEvent     0x184 clipmask
 *   0x18C parent             0x190 nextthink          0x194 health
 *   0x19C count              0x1A8 (missile speed)
 */

/* gentity_s field access macros (using struct fields from common_types.h) */
#define _ENT(e)                 ((gentity_t *)(e))
#define ENT_NUMBER(e)           (_ENT(e)->s.number)
#define ENT_ETYPE(e)            (_ENT(e)->s.eType)
#define ENT_EFLAGS(e)           (_ENT(e)->s.eFlags)
#define ENT_POS(e)              (&_ENT(e)->s.pos)
#define ENT_APOS(e)             (&_ENT(e)->s.apos)
#define ENT_TIME(e)             (_ENT(e)->s.time)
#define ENT_TIME2(e)            (_ENT(e)->s.time2)
#define ENT_ORIGIN2(e)          (_ENT(e)->s.origin2)
#define ENT_ANGLES2(e)          (_ENT(e)->s.angles2)
#define ENT_OTHERENTNUM(e)      (_ENT(e)->s.otherEntityNum)
#define ENT_ATTACKERENTNUM(e)   (_ENT(e)->s.attackerEntityNum)
#define ENT_GROUNDENTNUM(e)     (_ENT(e)->s.groundEntityNum)
#define ENT_SURFTYPE(e)         (_ENT(e)->s.surfType)
#define ENT_WEAPON(e)           (_ENT(e)->s.weapon)
#define ENT_SVFLAGS(e)          (_ENT(e)->r.svFlags)
#define ENT_LINKED(e)           (_ENT(e)->r.linked)
#define ENT_BMODEL(e)           (_ENT(e)->r.bmodel)
#define ENT_CURRENTORIGIN(e)    (_ENT(e)->r.currentOrigin)
#define ENT_CURRENTANGLES(e)    (_ENT(e)->r.currentAngles)
#define ENT_OWNERNUM(e)         (_ENT(e)->r.ownerNum)
#define ENT_CLIENT(e)           (_ENT(e)->client)
#define ENT_PHYSICSOBJECT(e)    (_ENT(e)->physicsObject)
#define ENT_TAKEDAMAGE(e)       (_ENT(e)->takedamage)
#define ENT_HANDLER(e)          (_ENT(e)->handler)
#define ENT_TEAM(e)             (_ENT(e)->nopickup) /* 0x163: nopickup in STABS, used as team in game code */
#define ENT_CLASSNAME(e)        (_ENT(e)->classname)
#define ENT_FLAGS(e)            (_ENT(e)->flags)
#define ENT_FLAGS_BYTE2(e)      (*(byte *)((byte *)&_ENT(e)->flags + 2))
#define ENT_FREEAFTEREVENT(e)   (_ENT(e)->freeAfterEvent)
#define ENT_CLIPMASK(e)         (_ENT(e)->clipmask)
#define ENT_PARENT(e)           (_ENT(e)->parent)
#define ENT_NEXTTHINK(e)        (_ENT(e)->nextthink)
#define ENT_HEALTH(e)           (_ENT(e)->health)
#define ENT_MAXHEALTH(e)        (_ENT(e)->maxHealth)
#define ENT_COUNT(e)            (_ENT(e)->count)
#define ENT_MISSILESPEED(e)     (_ENT(e)->grenade.time) /* missile speed stored in grenade union member */

#define ENTITY_STRIDE sizeof(gentity_s)

/* External globals (BSS/data pointers) */
extern byte level_ptr[];         /* imp_level */
extern byte scr_const_ptr[];     /* imp_scr_const */
extern byte g_entities_ptr[];    /* imp_g_entities */
extern byte *entityHandlers_ptr; /* imp_entityHandlers */
extern byte *vec3_origin_ptr;   /* imp_vec3_origin */
extern byte *pPriorityMap;      /* imp_bulletPriorityMap */

/* level_ptr field access */
#define LEVEL_TIME          (((level_locals_t *)level_ptr)->time)
#define LEVEL_PREVIOUSTIME  (((level_locals_t *)level_ptr)->previousTime)

/* Handler table access: entityHandlers_ptr[handler * 40 + offset] */
#define HANDLER_ENTRY(h)    (entityHandlers_ptr + (h) * 40)
#define HANDLER_MOD(h)      (*(int *)(HANDLER_ENTRY(h) + 0x20))
#define HANDLER_SPLASHMOD(h) (*(int *)(HANDLER_ENTRY(h) + 0x24))

/* g_entities_ptr entity access by number */
#define G_ENTITY(num) ((gentity_t *)(g_entities_ptr + (num) * ENTITY_STRIDE))

/* Forward declarations */
void G_ExplodeMissile(gentity_t *ent);
gentity_t *fire_grenade(gentity_t *self, vec_t *start, vec_t *dir, int grenadeWPID, int time);
gentity_t *fire_rocket(gentity_t *self, vec_t *start, vec_t *dir);
static void G_MissileLandAngles(gentity_t *ent, trace_t *trace, vec_t *vAngles, qboolean bForceAlign);
static qboolean G_BounceMissile(gentity_t *ent, trace_t *trace);
void G_RunMissile(gentity_t *ent);

/* External function declarations */
extern WeaponDef *BG_GetWeaponDef(int weaponIndex);
extern void BG_EvaluateTrajectory(trajectory_t *tr, int atTime, vec_t *result);
extern void BG_EvaluateTrajectoryDelta(trajectory_t *tr, int atTime, vec_t *result);
extern void G_SetOrigin(gentity_t *ent, vec_t *origin);
extern void G_SetAngle(gentity_t *ent, vec_t *angles);
extern void G_TraceCapsule(trace_t *result, vec_t *start, vec_t *mins, vec_t *maxs, vec_t *end, int skipNumber, int mask);
extern int DirToByte(vec_t *dir);
extern void G_AddEvent(gentity_t *ent, int event, int eventParm);
extern int SV_PointContents(vec_t *point, int passEntityNum, int contentMask);
extern void SV_LinkEntity(gentity_t *ent);
extern void G_RadiusDamage(vec_t *origin, gentity_t *ent, gentity_t *attacker, float radius, float outerDamage, float innerDamage, gentity_t *inflictor, int splashMod);
extern void Server_SwitchToValidFxScheduler(void);
extern int FX_RegisterEffect(const char *name);
extern float FX_GetEffectLength(int handle);
extern gentity_t *G_Spawn(void);
extern void Scr_SetString(scr_string_t *dst, unsigned short str);
extern void vectoangles(vec_t *dir, vec_t *angles);
extern float AngleNormalize360(float angle);
extern float AngleNormalize180(float angle);
extern float AngleSubtract(float a, float b);
extern float PitchForYawOnNormal(float yaw, vec_t *normal);
extern float flrand(float min, float max);
extern float randomf(void);
extern float Vec3Normalize(vec_t *v);
extern float Vec3NormalizeTo(vec_t *v, vec_t *out);
extern void G_LocationalTrace(trace_t *result, vec_t *start, vec_t *end, int skipNumber, int mask, byte *priorityMap);
extern gentity_t *G_TempEntity(vec_t *origin, int event);
extern void G_FreeEntity(gentity_t *ent);
extern void G_RunThink(gentity_t *ent);
extern int LogAccuracyHit(gentity_t *target, gentity_t *attacker);
extern void G_Damage(gentity_t *target, gentity_t *inflictor, gentity_t *attacker, vec_t *dir, vec_t *point, int damage, int dflags, int mod, int hitClient, int hitLoc);
extern void G_CheckHitTriggerDamage(gentity_t *attacker, vec_t *start, vec_t *end, int damage, int mod);
extern void G_GrenadeTouchTriggerDamage(gentity_t *ent, vec_t *oldOrigin, vec_t *origin, int radius, int mod);
extern void SnapVectorTowards(vec_t *v, vec_t *to);

/* VectorCopy inline */
static inline void VectorCopy(const vec_t *src, vec_t *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

/* VectorSubtract inline */
static inline void VectorSubtract(const vec_t *a, const vec_t *b, vec_t *out) {
    out[0] = a[0] - b[0];
    out[1] = a[1] - b[1];
    out[2] = a[2] - b[2];
}

/* VectorAdd inline */
static inline void VectorAdd(const vec_t *a, const vec_t *b, vec_t *out) {
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
    out[2] = a[2] + b[2];
}

/* VectorScale inline */
static inline void VectorScale(const vec_t *v, float scale, vec_t *out) {
    out[0] = v[0] * scale;
    out[1] = v[1] * scale;
    out[2] = v[2] * scale;
}

/* VectorClear inline */
static inline void VectorClear(vec_t *v) {
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
}

/* VectorLength inline */
static inline float VectorLength(const vec_t *v) {
    return sqrtf(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

/* DotProduct inline */
static inline float DotProduct(const vec_t *a, const vec_t *b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

/* VectorMA inline: out = a + scale * b */
static inline void VectorMA(const vec_t *a, float scale, const vec_t *b, vec_t *out) {
    out[0] = a[0] + scale * b[0];
    out[1] = a[1] + scale * b[1];
    out[2] = a[2] + scale * b[2];
}

/* Snap float to integer (truncate) */
static inline float SnapFloat(float f) {
    return (float)(int)f;
}

/* SnapVector: snap each component to integer */
static inline void SnapVector(vec_t *v) {
    v[0] = SnapFloat(v[0]);
    v[1] = SnapFloat(v[1]);
    v[2] = SnapFloat(v[2]);
}

/* LerpPosition: lerp between start and end by fraction */
static inline void LerpPosition(const vec_t *start, const vec_t *end, float fraction, vec_t *out) {
    out[0] = start[0] + (end[0] - start[0]) * fraction;
    out[1] = start[1] + (end[1] - start[1]) * fraction;
    out[2] = start[2] + (end[2] - start[2]) * fraction;
}

/* line 274 */
void G_ExplodeMissile(gentity_t *ent)
{
    WeaponDef *weapDef;
    vec3_t origin;
    vec3_t end;
    trace_t trace;

    weapDef = BG_GetWeaponDef(ENT_WEAPON(ent));

    /* If projectile type is 2 (grenade) and groundEntityNum == 0x3ff (none), just set nextthink */
    if (weapDef->projExplosion == 2 && ENT_GROUNDENTNUM(ent) == 0x3FF) {
        ENT_NEXTTHINK(ent) = 50;
        return;
    }

    /* Evaluate trajectory to get current origin */
    BG_EvaluateTrajectory(ENT_POS(ent), LEVEL_TIME, origin);

    /* Snap origin to integer */
    SnapVector(origin);

    /* Set origin on entity */
    G_SetOrigin(ent, origin);

    /* Set eType to 0 (general) */
    ENT_ETYPE(ent) = 0;

    /* Add EF_NODRAW flag */
    ENT_EFLAGS(ent) |= 0x20;

    /* Set FL_NO_KNOCKBACK flag */
    ENT_FLAGS(ent) |= 0x800;

    /* Set svFlags |= 8 */
    ENT_SVFLAGS(ent) |= 8;

    /* Copy currentOrigin to end, subtract 16 from Z */
    VectorCopy(ENT_CURRENTORIGIN(ent), end);
    end[2] -= 16.0f;

    /* Trace from currentOrigin to end */
    G_TraceCapsule(&trace, ENT_CURRENTORIGIN(ent), (vec_t *)vec3_origin_ptr, (vec_t *)vec3_origin_ptr, end,
                   ENT_NUMBER(ent), 0x811);

    /* Add explosion event based on projExplosion type */
    if (weapDef->projExplosion == 2) {
        G_AddEvent(ent, 0xBF, DirToByte(trace.normal));
    } else {
        G_AddEvent(ent, 0xBC, DirToByte(trace.normal));
    }

    /* Check if in water */
    if (SV_PointContents(ENT_CURRENTORIGIN(ent), -1, 0x20)) {
        /* In water: set surfType to MOD_WATER (0x14) */
        ENT_SURFTYPE(ent) = 0x14;
    } else {
        /* Not in water: extract surface type from trace */
        ENT_SURFTYPE(ent) = (trace.surfaceFlags & 0x1F00000) >> 20;
    }

    /* Check for explosion effect */
    if (weapDef->szProjExplosionEffect && *weapDef->szProjExplosionEffect) {
        /* Has explosion effect string */
        ENT_EFLAGS(ent) |= 0x10000;
        Server_SwitchToValidFxScheduler();
        int fxHandle = FX_RegisterEffect(weapDef->szProjExplosionEffect);
        ENT_TIME(ent) = LEVEL_TIME;
        float fxLength = FX_GetEffectLength(fxHandle);
        ENT_TIME2(ent) = LEVEL_TIME + (int)(fxLength + 1.0f);
    } else {
        /* No effect: set freeAfterEvent */
        ENT_FREEAFTEREVENT(ent) = 1;
    }

    /* Apply radius damage if explosionRadius > 0 */
    if (weapDef->iExplosionRadius > 0) {
        int splashMod = HANDLER_SPLASHMOD(ENT_HANDLER(ent));
        G_RadiusDamage(ENT_CURRENTORIGIN(ent), ent, (gentity_t *)ENT_PARENT(ent),
                       (float)weapDef->iExplosionRadius,
                       (float)weapDef->iExplosionOuterDamage,
                       (float)weapDef->iExplosionInnerDamage,
                       ent, splashMod);
    }

    /* Link the entity */
    SV_LinkEntity(ent);
}

/* line 622 */
gentity_t *fire_grenade(gentity_t *self, vec_t *start, vec_t *dir, int grenadeWPID, int time)
{
    gentity_t *bolt;
    WeaponDef *weapDef;
    gclient_t *cl;
    vec3_t angles;

    bolt = G_Spawn();

    cl = ENT_CLIENT(self);

    if (cl && ((gclient_t *)cl)->ps.grenadeTimeLeft != 0) {
        /* Client has a fuse time override */
        ENT_NEXTTHINK(bolt) = LEVEL_TIME + ((gclient_t *)cl)->ps.grenadeTimeLeft;
        ((gclient_t *)cl)->ps.grenadeTimeLeft = 0;
        cl = ENT_CLIENT(self);
    } else {
        /* Default: level time + time parameter */
        ENT_NEXTTHINK(bolt) = LEVEL_TIME + time;
    }

    if (cl) {
        ((gclient_t *)cl)->ps.grenadeTimeLeft = 0;
    }

    /* Set entity type to grenade (7) */
    ENT_HANDLER(bolt) = 7;

    /* Set eType to missile (4) */
    ENT_ETYPE(bolt) = 4;

    /* Set svFlags to 8 */
    ENT_SVFLAGS(bolt) = 8;

    /* Set weapon */
    ENT_WEAPON(bolt) = grenadeWPID;

    /* Set owner number */
    ENT_OWNERNUM(bolt) = ENT_NUMBER(self);

    /* Set parent entity */
    ENT_PARENT(bolt) = (int)self;

    /* Get weapon def */
    weapDef = BG_GetWeaponDef(grenadeWPID);

    /* Set classname to grenade string */
    Scr_SetString(&ENT_CLASSNAME(bolt), ((scr_const_t *)scr_const_ptr)->grenade);

    /* Set damage from weapon def */
    ENT_COUNT(bolt) = weapDef->damage;

    /* Set eFlags */
    ENT_EFLAGS(bolt) = 0x1000000;

    /* Set clipmask */
    ENT_CLIPMASK(bolt) = 0x2802891;

    /* Set time2 = level time + 50 */
    ENT_TIME2(bolt) = LEVEL_TIME + 50;

    /* Set pos trajectory type to TR_GRAVITY (5) */
    ENT_POS(bolt)->trType = 5;

    /* Set pos trTime to level time */
    ENT_POS(bolt)->trTime = LEVEL_TIME;

    /* Copy start to trBase */
    VectorCopy(start, ENT_POS(bolt)->trBase);

    /* Copy dir to trDelta */
    VectorCopy(dir, ENT_POS(bolt)->trDelta);

    /* Snap the velocity to integers */
    SnapVector(ENT_POS(bolt)->trDelta);

    /* Set apos trajectory type = 2 (TR_LINEAR) */
    ENT_APOS(bolt)->trType = 2;

    /* Set apos trTime to level time */
    ENT_APOS(bolt)->trTime = LEVEL_TIME;

    /* Calculate angles from direction, store in apos.trBase */
    vectoangles(dir, ENT_APOS(bolt)->trBase);

    /* Normalize pitch by subtracting 120 */
    ENT_APOS(bolt)->trBase[0] = AngleNormalize360(ENT_APOS(bolt)->trBase[0] - 120.0f);

    /* Set angular velocity: random roll speed around 720 deg/s */
    ENT_APOS(bolt)->trDelta[0] = flrand(-45.0f, 45.0f) + 720.0f;
    ENT_APOS(bolt)->trDelta[1] = 0.0f;
    ENT_APOS(bolt)->trDelta[2] = flrand(-45.0f, 45.0f) + 360.0f;

    /* Set currentOrigin to start */
    VectorCopy(start, ENT_CURRENTORIGIN(bolt));

    /* Set currentAngles to apos.trBase */
    VectorCopy(ENT_APOS(bolt)->trBase, ENT_CURRENTANGLES(bolt));

    return bolt;
}

/* line 688 */
gentity_t *fire_rocket(gentity_t *self, vec_t *start, vec_t *dir)
{
    gentity_t *bolt;
    WeaponDef *weapDef;

    /* Normalize direction */
    Vec3Normalize(dir);

    /* Get weapon def from self's weapon */
    weapDef = BG_GetWeaponDef(ENT_WEAPON(self));

    /* Spawn the missile entity */
    bolt = G_Spawn();

    /* Set classname to rocket */
    Scr_SetString(&ENT_CLASSNAME(bolt), ((scr_const_t *)scr_const_ptr)->rocket);

    /* Set nextthink to level time + 30000 */
    ENT_NEXTTHINK(bolt) = LEVEL_TIME + 30000;

    /* Set handler to 8 (rocket) */
    ENT_HANDLER(bolt) = 8;

    /* Set eType to missile (4) */
    ENT_ETYPE(bolt) = 4;

    /* Set EF_SMOKINGTRAIL flag */
    ENT_EFLAGS(bolt) |= 0x400;

    /* Set svFlags to 8 */
    ENT_SVFLAGS(bolt) = 8;

    /* Set weapon from self */
    ENT_WEAPON(bolt) = ENT_WEAPON(self);

    /* Set ownerNum */
    ENT_OWNERNUM(bolt) = ENT_NUMBER(self);

    /* Set parent */
    ENT_PARENT(bolt) = (int)self;

    /* Set damage from weapon def */
    ENT_COUNT(bolt) = weapDef->damage;

    /* Set clipmask */
    ENT_CLIPMASK(bolt) = 0x2802891;

    /* Set time2 = level time + 50 */
    ENT_TIME2(bolt) = LEVEL_TIME + 50;

    /* Set pos trajectory type to TR_LINEAR (2) */
    ENT_POS(bolt)->trType = 2;

    /* Set pos trTime to level time - 50 */
    ENT_POS(bolt)->trTime = LEVEL_TIME - 50;

    /* Copy start to trBase */
    VectorCopy(start, ENT_POS(bolt)->trBase);

    /* Scale direction by projectile speed for trDelta */
    VectorScale(dir, (float)weapDef->iProjectileSpeed, ENT_POS(bolt)->trDelta);

    /* Snap the velocity to integers */
    SnapVector(ENT_POS(bolt)->trDelta);

    /* Set currentOrigin to start */
    VectorCopy(start, ENT_CURRENTORIGIN(bolt));

    /* Calculate angles from direction and set on entity */
    vectoangles(dir, ENT_CURRENTANGLES(bolt));
    G_SetAngle(bolt, ENT_CURRENTANGLES(bolt));

    /* Set missile speed = (speedUp / speed) * 1000.0 */
    ENT_MISSILESPEED(bolt) = (float)weapDef->iProjectileSpeedUp / (float)weapDef->iProjectileSpeed * 1000.0f;

    /* Copy FL_TURRET flag from self */
    ENT_FLAGS(bolt) |= (ENT_FLAGS(self) & 0x20000);

    return bolt;
}

/* line 20 */
static void G_MissileLandAngles(gentity_t *ent, trace_t *trace, vec_t *vAngles, qboolean bForceAlign)
{
    int hitTime;
    float fSurfacePitch;
    float fAngleDelta;
    float fAbsAngDelta;

    /* Calculate hit time from trace fraction */
    hitTime = LEVEL_PREVIOUSTIME + (int)((float)(LEVEL_TIME - LEVEL_PREVIOUSTIME) * trace->fraction);

    /* Evaluate angular trajectory at hit time */
    BG_EvaluateTrajectory(ENT_APOS(ent), hitTime, vAngles);

    /* Check if surface normal Z > 0.1 (non-floor) */
    if (trace->normal[2] > 0.1f) {
        /* Surface has significant Z normal */
        fSurfacePitch = PitchForYawOnNormal(vAngles[1], trace->normal);
        fAngleDelta = AngleSubtract(fSurfacePitch, vAngles[0]);
        fAbsAngDelta = fAngleDelta < 0 ? -fAngleDelta : fAngleDelta;

        if (!bForceAlign) {
            /* Copy vAngles to apos.trBase and set trTime */
            VectorCopy(vAngles, ENT_APOS(ent)->trBase);
            ENT_APOS(ent)->trTime = hitTime;

            if (fAbsAngDelta < 80.0f) {
                /* Small angle delta: apply damped angular velocity */
                float rnd = randomf();
                ENT_APOS(ent)->trDelta[0] = -(ENT_APOS(ent)->trDelta[0] * (rnd * 0.3f + 0.85f));
            }
            /* else: fAbsAngDelta >= 80, damped angular velocity */
        } else {
            /* fAbsAngDelta >= 80: just damp angular velocity */
            float rnd = randomf();
            ENT_APOS(ent)->trDelta[0] = ENT_APOS(ent)->trDelta[0] * (rnd * 0.3f + 0.85f);
        }

        /* Normalize pitch to [-180, 180] */
        vAngles[0] = AngleNormalize180(vAngles[0]);

        if (bForceAlign) {
            /* Force align: set pitch to surface pitch (flipped if needed) */
            float absYaw = vAngles[0] < 0 ? -vAngles[0] : vAngles[0];
            if (absYaw > 90.0f) {
                vAngles[0] = AngleNormalize360(fSurfacePitch + 180.0f);
            } else {
                vAngles[0] = AngleNormalize360(fSurfacePitch);
            }
            return;
        }

        if (fAbsAngDelta < 45.0f) {
            /* Very small delta: nothing more to do */
            return;
        }

        if (fAbsAngDelta < 80.0f) {
            /* Medium delta: blend toward surface pitch */
            vAngles[0] = AngleNormalize360(vAngles[0] + fAngleDelta * 0.25f);
            return;
        }

        /* Large delta: just normalize and return */
        vAngles[0] = AngleNormalize360(vAngles[0]);
        return;
    }

    /* Surface normal Z <= 0.1: near-vertical surface or no significant slope */
    if (bForceAlign) {
        return;
    }

    /* Randomize roll (trDelta[0] = yaw) */
    ENT_APOS(ent)->trDelta[0] = AngleNormalize360(ENT_APOS(ent)->trDelta[0] + (float)((rand() & 0x7F) - 0x3F));
}

/* line 86 */
static qboolean G_BounceMissile(gentity_t *ent, trace_t *trace)
{
    WeaponDef *weapDef;
    int contents;
    int surfType;
    vec3_t velocity;
    vec3_t vAngles;
    float dot;
    float speed;

    weapDef = BG_GetWeaponDef(ENT_WEAPON(ent));

    /* Check contents at current origin */
    contents = SV_PointContents(ENT_CURRENTORIGIN(ent), -1, 0x20);

    /* Extract surface type from trace */
    surfType = (trace->surfaceFlags & 0x1F00000) >> 20;

    /* Calculate hit time and get velocity at that time */
    int hitTime = LEVEL_PREVIOUSTIME + (int)((float)(LEVEL_TIME - LEVEL_PREVIOUSTIME) * trace->fraction);
    BG_EvaluateTrajectoryDelta(ENT_POS(ent), hitTime, velocity);

    /* Calculate dot product of velocity with surface normal */
    dot = DotProduct(velocity, trace->normal);

    /* Reflect velocity: result = velocity - 2 * dot * normal */
    VectorMA(velocity, -2.0f * dot, trace->normal, ENT_POS(ent)->trDelta);

    /* Check if surface normal Z > 0.7 (mostly upward-facing) */
    if ((double)trace->normal[2] > 0.7) {
        ENT_GROUNDENTNUM(ent) = trace->entityNum;
    }

    /* Check if grenade is marked as bouncing (bit 0 of eFlags byte at 0x0B) */
    if (ENT_EFLAGS(ent) & 0x10000) {
        /* Has the FL_BOUNCE_ONCE flag */
        speed = VectorLength(velocity);

        if (speed > 0.0f && dot < 0.0f) {
            /* Apply parallel/perpendicular bounce factors */
            float parallelBounce = weapDef->parallelBounce[surfType];
            float perpBounce = weapDef->perpendicularBounce[surfType];

            /* Interpolate between parallel and perpendicular bounce based on angle */
            float bounceFactor = parallelBounce + (perpBounce - parallelBounce) * (dot / -speed);

            /* Scale the reflected velocity */
            VectorScale(ENT_POS(ent)->trDelta, bounceFactor, ENT_POS(ent)->trDelta);
        }

        /* Check if speed is slow enough to stop */
        if ((double)trace->normal[2] > 0.7) {
            /* Check if velocity after bounce is very small */
            float newSpeed = VectorLength(ENT_POS(ent)->trDelta);
            if (newSpeed < 20.0f) {
                /* Velocity is very small, stop the grenade */
                G_SetOrigin(ent, ENT_CURRENTORIGIN(ent));

                /* Set landing angles with force align */
                G_MissileLandAngles(ent, trace, vAngles, 1);
                G_SetAngle(ent, vAngles);
                return 0;
            }
        }
    }

    /* Nudge origin slightly along normal and min Z */
    {
        float nudge_z = trace->normal[2] * 0.1f;
        if (nudge_z > 0.0f) nudge_z = 0.0f;

        ENT_CURRENTORIGIN(ent)[0] += trace->normal[0] * 0.1f;
        ENT_CURRENTORIGIN(ent)[1] += trace->normal[1] * 0.1f;
        ENT_CURRENTORIGIN(ent)[2] += nudge_z;
    }

    /* Copy currentOrigin to trBase */
    VectorCopy(ENT_CURRENTORIGIN(ent), ENT_POS(ent)->trBase);

    /* Set trTime to current level time */
    ENT_POS(ent)->trTime = LEVEL_TIME;

    /* Calculate land angles */
    G_MissileLandAngles(ent, trace, vAngles, 0);

    /* Copy angles to apos.trBase */
    VectorCopy(vAngles, ENT_APOS(ent)->trBase);

    /* Set apos trTime */
    ENT_APOS(ent)->trTime = LEVEL_TIME;

    /* Check if there was a significant velocity change */
    if (contents) {
        return 0;
    }

    /* Calculate velocity change */
    {
        vec3_t velChange;
        VectorSubtract(ENT_POS(ent)->trDelta, velocity, velChange);
        float changeSpeed = VectorLength(velChange);
        if (changeSpeed <= 100.0f) {
            return 0;
        }
        return 1;
    }
}

/* line 490 */
void G_RunMissile(gentity_t *ent)
{
    vec3_t origin;
    vec3_t vOldOrigin;
    vec3_t dir;
    vec3_t endpos;
    vec3_t trNormal;
    trace_t tr;
    trace_t trDown;
    float fraction;
    int methodOfDeath;
    int hitClient;
    WeaponDef *weapDef;

    /* If pos.trType is 0 (stationary) and groundEntityNum != 0x3FE */
    if (ENT_POS(ent)->trType == 0 && ENT_GROUNDENTNUM(ent) != 0x3FE) {
        /* Missile is on the ground: trace downward to check position */
        VectorCopy(ENT_CURRENTORIGIN(ent), origin);
        origin[2] -= 1.5f;

        /* Initial locational trace */
        G_LocationalTrace(&tr, ENT_CURRENTORIGIN(ent), origin,
                          ENT_OWNERNUM(ent), ENT_CLIPMASK(ent), pPriorityMap);
        if (tr.startsolid) {
            /* Start solid: set fraction to 0 and compute reversed direction */
            tr.fraction = 0.0f;
            VectorSubtract(ENT_CURRENTORIGIN(ent), origin, dir);
            Vec3NormalizeTo(dir, tr.normal);
        }

        if (tr.fraction == 1.0f) {
            /* Didn't hit anything: set pos to linear, copy current pos */
            ENT_POS(ent)->trType = 5;
            ENT_POS(ent)->trTime = LEVEL_TIME;
            ENT_POS(ent)->trDuration = 0;
            VectorCopy(ENT_CURRENTORIGIN(ent), ENT_POS(ent)->trBase);
            VectorClear(ENT_POS(ent)->trDelta);
        }
    }

    /* Save old origin */
    VectorCopy(ENT_CURRENTORIGIN(ent), vOldOrigin);

    /* Evaluate trajectory to get new origin */
    BG_EvaluateTrajectory(ENT_POS(ent), LEVEL_TIME, origin);

    /* Calculate movement direction */
    VectorSubtract(origin, ENT_CURRENTORIGIN(ent), dir);

    /* Normalize the direction */
    float dirLen = Vec3Normalize(dir);
    if (dirLen == 0.0f) {
        goto run_think_check;
    }

    /* Check if vertical velocity is high enough to do a water check */
    {
        float absVelZ = ENT_POS(ent)->trDelta[2];
        if (absVelZ < 0) absVelZ = -absVelZ;

        if (absVelZ > 30.0f) {
            /* Check water contents at currentOrigin */
            if (!SV_PointContents(ENT_CURRENTORIGIN(ent), -1, 0x20)) {
                /* Not in water: trace with water mask too */
                G_LocationalTrace(&tr, ENT_CURRENTORIGIN(ent), origin,
                                  ENT_OWNERNUM(ent), ENT_CLIPMASK(ent) | 0x20, pPriorityMap);

                if (tr.startsolid) {
                    tr.fraction = 0.0f;
                    VectorSubtract(ENT_CURRENTORIGIN(ent), origin, dir);
                    Vec3NormalizeTo(dir, tr.normal);
                }

                goto after_trace;
            }
        }
    }

    /* Normal trace */
    G_LocationalTrace(&tr, ENT_CURRENTORIGIN(ent), origin,
                      ENT_OWNERNUM(ent), ENT_CLIPMASK(ent), pPriorityMap);
    if (tr.startsolid) {
        tr.fraction = 0.0f;
        VectorSubtract(ENT_CURRENTORIGIN(ent), origin, dir);
        Vec3NormalizeTo(dir, tr.normal);
    }

after_trace:
    /* Check for water splash (surfType == 0x14) */
    if ((tr.surfaceFlags & 0x1F00000) == 0x1400000) {
        /* Water surface hit */
        vec3_t splashDir;
        Vec3NormalizeTo(ENT_POS(ent)->trDelta, splashDir);

        /* Ensure Z component of splash direction is non-negative */
        if (splashDir[2] < 0.0f) {
            splashDir[2] = -splashDir[2];
        }

        /* Create splash temp entity */
        gentity_t *tent = G_TempEntity(ENT_CURRENTORIGIN(ent), 0xB6);

        /* Set direction and splash direction on temp entity */
        ((gentity_t *)tent)->s.eventParm = DirToByte(tr.normal);
        ((tent)->s.scale) = DirToByte(splashDir);

        /* Set surface type on temp entity */
        ((tent)->s.surfType) = (tr.surfaceFlags & 0x1F00000) >> 20;

        /* Set source entity number */
        ((gentity_t *)tent)->s.otherEntityNum = ENT_NUMBER(ent);

        /* Re-trace without water mask */
        G_LocationalTrace(&tr, ENT_CURRENTORIGIN(ent), origin,
                          ENT_OWNERNUM(ent), ENT_CLIPMASK(ent), pPriorityMap);
        if (tr.startsolid) {
            tr.fraction = 0.0f;
            VectorSubtract(ENT_CURRENTORIGIN(ent), origin, dir);
            Vec3NormalizeTo(dir, tr.normal);
        }
    }

    /* Get method of death from handler table */
    methodOfDeath = HANDLER_MOD(ENT_HANDLER(ent));

    /* Check if MOD is melee (3) for grenade-specific handling */
    if (methodOfDeath == 3) {
        /* Get the other entity (hit entity) */
        gentity_t *other = G_ENTITY(tr.entityNum);

        /* Check if entity is a player (health < 0 => dead) */
        if (((other)->flags) < 0) {
            /* Save and zero health of other entity for re-trace */
            int savedHealth = ((other)->r.contents);
            ((other)->r.contents) = 0;

            /* Re-trace to pass through dead bodies */
            G_LocationalTrace(&tr, ENT_CURRENTORIGIN(ent), origin,
                              ENT_OWNERNUM(ent), ENT_CLIPMASK(ent), pPriorityMap);
            if (tr.startsolid) {
                tr.fraction = 0.0f;
                VectorSubtract(ENT_CURRENTORIGIN(ent), origin, dir);
                Vec3NormalizeTo(dir, tr.normal);
            }

            /* Restore health */
            ((other)->r.contents) = savedHealth;
        }
    }

    /* Compute endpos by lerping between currentOrigin and origin */
    fraction = tr.fraction;
    LerpPosition(ENT_CURRENTORIGIN(ent), origin, fraction, endpos);

    /* Update currentOrigin with endpos */
    VectorCopy(endpos, ENT_CURRENTORIGIN(ent));

    /* Check grenade bounce behavior */
    if (ENT_EFLAGS(ent) & 0x10000) {
        /* Grenade with bounce flag */
        if (fraction != 1.0f || (fraction == 1.0f && tr.normal[2] > 0.7f)) {
            /* Special grenade ground check: trace downward */
            VectorCopy(endpos, origin);
            origin[0] = ENT_CURRENTORIGIN(ent)[0];
            origin[1] = ((ent)->r.currentOrigin[1]);
            origin[2] = ((ent)->r.currentOrigin[2]) - 1.5f;

            G_LocationalTrace(&trDown, ENT_CURRENTORIGIN(ent), origin,
                              ENT_OWNERNUM(ent), ENT_CLIPMASK(ent), pPriorityMap);
            if (trDown.startsolid) {
                trDown.fraction = 0.0f;
                VectorSubtract(ENT_CURRENTORIGIN(ent), origin, dir);
                Vec3NormalizeTo(dir, trDown.normal);
            }

            if (trDown.fraction != 1.0f && trDown.entityNum == 0x3FE) {
                /* Hit world in downward trace: use that trace instead */
                tr = trDown;
                fraction = tr.fraction;

                LerpPosition(ENT_CURRENTORIGIN(ent), origin, fraction, endpos);

                /* Adjust vertical position */
                ((ent)->s.origin2[0]) += endpos[2] + 1.5f - ((ent)->r.currentOrigin[2]);

                /* Update current origin */
                VectorCopy(endpos, ENT_CURRENTORIGIN(ent));

                /* Add 1.5 back to Z */
                ((ent)->r.currentOrigin[2]) += 1.5f;
            }
        }
    }

    /* Link entity */
    SV_LinkEntity(ent);

    /* Get weapon def for further checks */
    weapDef = BG_GetWeaponDef(ENT_WEAPON(ent));

    /* Check for melee method of death (grenade) */
    if (methodOfDeath == 3) {
        G_GrenadeTouchTriggerDamage(ent, vOldOrigin, ENT_CURRENTORIGIN(ent),
                                    weapDef->iExplosionRadius, 3);
    }

    /* Check if we hit something (fraction != 1.0) */
    if (tr.fraction == 1.0f) {
        /* Didn't hit anything: check if velocity is zero (stopped rocket) */
        float speed = VectorLength(ENT_POS(ent)->trDelta);
        if (speed == 0.0f) {
            goto run_think;
        }

        /* Missile is still moving: check for re-guidance */
        ENT_GROUNDENTNUM(ent) = 0x3FF;

        /* Check if weapon class allows guidance (weapClass == 2) and not already guided */
        if (weapDef->weapClass == 2 && !(ENT_FLAGS_BYTE2(ent) & 2)) {
            /* Check if total flight time hasn't expired */
            int totalTime = (int)ENT_MISSILESPEED(ent) + ENT_POS(ent)->trTime;
            if (totalTime < LEVEL_TIME) {
                goto run_think;
            }

            /* Re-guide the missile */
            WeaponDef *weaponDef = BG_GetWeaponDef(ENT_WEAPON(ent));

            /* Copy current velocity as direction */
            VectorCopy(ENT_POS(ent)->trDelta, dir);
            Vec3Normalize(dir);

            /* Calculate perturbation based on weapon accuracy */
            float scale = tanf((float)weaponDef->fAdsAimPitch * 0.017453292519943295f);

            vec3_t perturbation;
            int i;
            for (i = 0; i < 3; i++) {
                perturbation[i] = flrand(-1.0f, 1.0f);
            }

            VectorScale(perturbation, scale, perturbation);
            VectorAdd(dir, perturbation, dir);
            Vec3Normalize(dir);

            /* Set new velocity: speed * dir */
            VectorScale(dir, (float)weaponDef->iProjectileSpeed, ENT_POS(ent)->trDelta);

            /* Copy currentOrigin to trBase */
            VectorCopy(ENT_CURRENTORIGIN(ent), ENT_POS(ent)->trBase);

            /* Update angles */
            vectoangles(dir, ENT_CURRENTANGLES(ent));
            G_SetAngle(ent, ENT_CURRENTANGLES(ent));

            /* Update trTime */
            ENT_POS(ent)->trTime = LEVEL_TIME;

            /* Update missile speed */
            if (ENT_FLAGS(ent) & 0x10000) {
                /* Already guided: apply decay factor */
                ENT_MISSILESPEED(ent) *= ((WeaponDef *)weaponDef)->destabilizationTimeReductionRatio;
            } else {
                /* First guidance: set initial speed */
                ENT_MISSILESPEED(ent) = 1000.0f * ((WeaponDef *)weaponDef)->destabilizationBaseTime;
            }

            /* Set guided flag */
            ENT_FLAGS(ent) |= 0x10000;
        }

        goto run_think;
    }

    /* Hit something: check if it's a trigger (surface flag 0x10) */
    if (tr.surfaceFlags & 0x10) {
        G_FreeEntity(ent);
        return;
    }

    /* Get the other entity that was hit */
    {
        gentity_t *other = G_ENTITY(tr.entityNum);

        /* Set surface type */
        ENT_SURFTYPE(ent) = (tr.surfaceFlags & 0x1F00000) >> 20;

        /* Check if other entity has takedamage */
        if (ENT_TAKEDAMAGE(other) || (ENT_EFLAGS(ent) & 0x10000)) {
            /* Entity takes damage or is a bounce grenade */
            if (!ENT_TAKEDAMAGE(other)) {
                /* No damage but has bounce: check for dead body pass-through */
                gclient_t *otherClient = ENT_CLIENT(other);
                if (otherClient) {
                    /* Has a client: fix trace surfaceFlags if needed */
                    if (tr.surfaceFlags == 0) {
                        tr.surfaceFlags = 0x700000;
                    }
                }

                /* Bounce the missile */
                qboolean bounceResult = G_BounceMissile(ent, &tr);
                if (bounceResult && !tr.startsolid) {
                    /* Bounced and produced a sound */
                    G_AddEvent(ent, 0xBB, (tr.surfaceFlags & 0x1F00000) >> 20);
                }

                /* Check if still a missile */
                if (ENT_ETYPE(ent) != 4) {
                    goto done;
                }
                goto run_think;
            }

            /* Other entity takes damage: get weapon def for damage params */
            WeaponDef *hitWeapDef = BG_GetWeaponDef(ENT_WEAPON(ent));
            int hitMOD = HANDLER_MOD(ENT_HANDLER(ent));

            hitClient = 0;

            /* Check if count (damage) is non-zero */
            if (ENT_COUNT(ent)) {
                /* Log accuracy and apply damage */
                gentity_t *attacker;
                if (ENT_OWNERNUM(ent) == 0x3FF) {
                    attacker = NULL;
                } else {
                    attacker = G_ENTITY(ENT_OWNERNUM(ent));
                }

                hitClient = LogAccuracyHit(other, attacker) ? 1 : 0;

                /* Get velocity direction for damage */
                BG_EvaluateTrajectoryDelta(ENT_POS(ent), LEVEL_TIME, dir);

                float speed = VectorLength(dir);
                /* If speed is 0, use (0, 0, 1) as dir z component */
                if (speed != 0.0f) {
                    /* Keep dir[2] as is */
                } else {
                    dir[2] = 1.0f;
                }

                /* Apply damage */
                gentity_t *damageAttacker;
                if (ENT_OWNERNUM(ent) == 0x3FF) {
                    damageAttacker = NULL;
                } else {
                    damageAttacker = G_ENTITY(ENT_OWNERNUM(ent));
                }

                G_Damage(other, ent, damageAttacker, dir, ENT_CURRENTORIGIN(ent),
                         ENT_COUNT(ent), 0, hitMOD, 0, 0);
            }

            /* Check hit triggers */
            if (ENT_COUNT(ent)) {
                gentity_t *trigAttacker;
                if (ENT_OWNERNUM(ent) == 0x3FF) {
                    trigAttacker = (gentity_t *)(g_entities_ptr + 0x8BBA0);
                } else {
                    trigAttacker = G_ENTITY(ENT_OWNERNUM(ent));
                }
                G_CheckHitTriggerDamage(trigAttacker, ENT_CURRENTORIGIN(ent), endpos,
                                        ENT_COUNT(ent), hitMOD);
            }

            /* Determine if we hit a client */
            {
                int didHitClient = hitClient;
                if (!didHitClient && tr.entityNum == 0) {
                    didHitClient = 0;
                }
                if (didHitClient || tr.partName != 0) {
                    didHitClient = 1;
                }

                /* Add impact event */
                int impactEvent = didHitClient ? 0xBD : 0xBE;
                G_AddEvent(ent, impactEvent, DirToByte(tr.normal));
            }

            /* Set surface type from trace */
            ENT_SURFTYPE(ent) = (tr.surfaceFlags & 0x1F00000) >> 20;

            /* Set freeAfterEvent */
            ENT_FREEAFTEREVENT(ent) = 1;

            /* Set eType to 0, add nodraw */
            ENT_ETYPE(ent) = 0;
            ENT_EFLAGS(ent) = (ENT_EFLAGS(ent) ^ 2) | 0x20;

            /* Set FL_NO_KNOCKBACK */
            ENT_FLAGS(ent) |= 0x800;

            /* Snap endpos towards old origin */
            SnapVectorTowards(endpos, ENT_POS(ent)->trBase);

            /* Set final origin */
            G_SetOrigin(ent, endpos);

            /* Apply radius damage if applicable */
            if (hitWeapDef->iExplosionRadius > 0) {
                int splashMod = HANDLER_SPLASHMOD(ENT_HANDLER(ent));
                G_RadiusDamage(endpos, ent, (gentity_t *)ENT_PARENT(ent),
                               (float)hitWeapDef->iExplosionRadius,
                               (float)hitWeapDef->iExplosionOuterDamage,
                               (float)hitWeapDef->iExplosionInnerDamage,
                               ent, splashMod);
            }

            /* Link entity */
            SV_LinkEntity(ent);
        }
    }

    /* Check if still a missile */
    if (ENT_ETYPE(ent) == 4) {
        goto run_think;
    }

done:
    return;

run_think_check:
    if (dirLen != 0.0f || ENT_ETYPE(ent) != 4) {
        goto done;
    }

run_think:
    G_RunThink(ent);
}
