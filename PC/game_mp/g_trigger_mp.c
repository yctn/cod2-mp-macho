/* Converted to C from ASM: g_trigger_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_trigger_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern int Scr_IsSystemActive(int flag);
extern void Scr_AddEntity(gentity_t *ent);
extern void Scr_Notify(gentity_t *ent, unsigned int stringId, int numArgs);
extern void Scr_AddInt(int value);
extern int Scr_GetNumParam(void);
extern float Scr_GetFloat(int param);
extern void Scr_Error(const char *msg);

extern void SV_SetBrushModel(gentity_t *ent);
extern void SV_LinkEntity(gentity_t *ent);
extern int SV_SightTraceToEntity(vec_t *start, vec_t *mins, vec_t *maxs, vec_t *end, int entityNum, int contentMask);

extern int G_SpawnString(const char *key, const char *defaultValue, const char **out);
extern int G_SpawnFloat(const char *key, const char *defaultValue, float *out);
extern void G_SpawnInt(const char *key, const char *defaultValue, int *out);
extern void G_Damage(gentity_t *target, gentity_t *inflictor, gentity_t *attacker,
                     const vec_t *dir, const vec_t *point, int damage, int dflags,
                     int mod, int hitLoc, int timeOffset);
extern void G_FreeEntityDelay(gentity_t *ent);

extern const char *va(const char *fmt, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void AddPointToBounds(vec_t *point, vec_t *mins, vec_t *maxs);
extern int CM_AreaEntities(vec_t *mins, vec_t *maxs, int *list, int maxCount, int mask);

extern byte level_ptr[];         /* imp_level */
/* imp_scr_const declared in generated_syms.h as void* */
extern byte g_entities_ptr[];    /* imp_g_entities */
extern byte *g_trace_zero_ptr;  /* imp_vec3_origin */

#define ENTITY_STRIDE 560

void G_Trigger(gentity_t *self, gentity_t *other);
void hurt_use(gentity_t *self, gentity_t *other, gentity_t *activator);
void SP_trigger_lookat(gentity_t *self);
void SP_trigger_hurt(gentity_t *self);
void SP_trigger_damage(gentity_t *pSelf);
void SP_trigger_multiple(gentity_t *ent);
void SP_trigger_radius(gentity_t *ent);
void SP_trigger_disk(gentity_t *ent);
void SP_trigger_once(gentity_t *ent);
void Touch_Multi(gentity_t *self, gentity_t *other, qboolean bTouched);
void hurt_touch(gentity_t *self, gentity_t *other, qboolean bTouched);
void Activate_trigger_damage(gentity_t *pEnt, gentity_t *pOther, int iDamage, int iMOD);
void G_GrenadeTouchTriggerDamage(gentity_t *pActivator, vec_t *vStart, vec_t *vEnd, int iDamage, int iMOD);
void G_CheckHitTriggerDamage(gentity_t *pActivator, vec_t *vStart, vec_t *vEnd, int iDamage, int iMOD);
void Die_trigger_damage(gentity_t *pSelf, gentity_t *pInflictor, gentity_t *pAttacker, int iDamage, int iMod, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int timeOffset);
void Pain_trigger_damage(gentity_t *pSelf, gentity_t *pAttacker, int iDamage, const vec_t *vPoint, const int iMod, const vec_t *vDir, const hitLocation_t hitLoc);
void Use_trigger_damage(gentity_t *pEnt, gentity_t *pOther, gentity_t *pActivator);

/* line 3 */
void G_Trigger(gentity_t *self, gentity_t *other)
{
    byte *s = (byte *)self;
    byte *o = (byte *)other;
    byte *level;
    int triggerCount;
    byte *entry;

    if (!Scr_IsSystemActive(1))
        return;

    level = level_ptr;
    triggerCount = *(int *)(level + 0x35e8);

    if (triggerCount == 0x100) {
        Scr_AddEntity(other);
        Scr_Notify(self, *(unsigned short *)(imp_scr_const + 0x54), 1);
        return;
    }

    entry = level + 0x1de0 + triggerCount * 12;
    *(int *)(level + 0x35e8) = triggerCount + 1;
    *(short *)(entry + 8) = *(short *)s;
    *(short *)(entry + 10) = *(short *)o;
    *(int *)(entry + 12) = *(int *)(s + 0x228);
    *(int *)(entry + 16) = *(int *)(o + 0x228);
}

/* line 235 */
void hurt_use(gentity_t *self, gentity_t *other, gentity_t *activator)
{
    byte *s = (byte *)self;
    byte state = *(byte *)(s + 0x166);

    *(byte *)(s + 0x166) = (state != 3) ? 3 : 2;
}

/* line 596 */
void SP_trigger_lookat(gentity_t *self)
{
    byte *s = (byte *)self;

    SV_SetBrushModel(self);
    *(int *)(s + 0x11c) = 0x20000000;
    *(byte *)(s + 0xf2) = 1;
    *(int *)(s + 8) |= 1;
    SV_LinkEntity(self);
}

/* line 254 */
void SP_trigger_hurt(gentity_t *self)
{
    byte *s = (byte *)self;
    const char *sound;
    int spawnflags;

    SV_SetBrushModel(self);
    *(int *)(s + 0x11c) = 0x405c0008;
    *(byte *)(s + 0xf2) = 1;
    *(int *)(s + 8) |= 1;

    G_SpawnString("sound", "world_hurt_me", &sound);

    if (*(int *)(s + 0x19c) == 0)
        *(int *)(s + 0x19c) = 5;

    *(int *)(s + 0x11c) = 0x405c0008;

    spawnflags = *(int *)(s + 0x170) & 1;
    *(byte *)(s + 0x166) = (byte)(-spawnflags + 3);
}

/* line 464 */
void SP_trigger_damage(gentity_t *pSelf)
{
    byte *s = (byte *)pSelf;
    byte *level;
    float wait;

    G_SpawnInt("accumulate", "0", (int *)(s + 0x1ac));
    G_SpawnInt("threshold", "0", (int *)(s + 0x1a8));

    *(int *)(s + 0x194) = 0x7d00;
    *(byte *)(s + 0x161) = 1;
    *(byte *)(s + 0x166) = 4;

    level = level_ptr;
    if (*(byte *)(level + 0x1348) != 0) {
        if (G_SpawnFloat("wait", "", &wait) && !(0.0f < wait))
            *(int *)(s + 0x170) |= 0x200;
    }

    SV_SetBrushModel(pSelf);
    *(int *)(s + 0x11c) = 0x405c0008;
    *(byte *)(s + 0xf2) = 1;
    *(int *)(s + 8) |= 1;
    SV_LinkEntity(pSelf);
}

/* line 96 */
void SP_trigger_multiple(gentity_t *ent)
{
    byte *e = (byte *)ent;
    byte *level;
    float wait;
    int spawnflags;

    *(byte *)(e + 0x166) = 1;

    level = level_ptr;
    if (*(byte *)(level + 0x1348) != 0) {
        if (G_SpawnFloat("wait", "", &wait) && !(0.0f < wait))
            *(int *)(e + 0x170) |= 0x10;
    }

    SV_SetBrushModel(ent);
    *(byte *)(e + 0xf2) = 1;
    *(int *)(e + 8) |= 1;

    *(int *)(e + 0x11c) = 0;
    spawnflags = *(int *)(e + 0x170);
    if (!(spawnflags & 8))
        *(int *)(e + 0x11c) = 0x40000000;
    if (spawnflags & 1)
        *(int *)(e + 0x11c) |= 0x40000;
    if (spawnflags & 2)
        *(int *)(e + 0x11c) |= 0x80000;
    if (spawnflags & 4)
        *(int *)(e + 0x11c) |= 0x100000;

    SV_LinkEntity(ent);
}

/* line 114 */
void SP_trigger_radius(gentity_t *ent)
{
    byte *e = (byte *)ent;
    byte *level;
    float radius;
    float height;
    float wait;
    float neg_radius;
    int spawnflags;

    level = level_ptr;
    if (*(byte *)(level + 0x1348) == 0) {
        /* Script path */
        if (Scr_GetNumParam() <= 4)
            Scr_Error("USAGE: spawn( \"trigger_radius\", <origin>, <spawnflags>, <radius>, <height> )");
        radius = Scr_GetFloat(3);
        height = Scr_GetFloat(4);
    } else {
        /* Map spawn path */
        if (!G_SpawnFloat("radius", "", &radius)) {
            Com_Error(1, va("radius not specified for trigger_radius at (%g %g %g)",
                *(float *)(e + 0x138), *(float *)(e + 0x13c), *(float *)(e + 0x140)));
        }
        if (!G_SpawnFloat("height", "", &height)) {
            Com_Error(1, va("height not specified for trigger_radius at (%g %g %g)",
                *(float *)(e + 0x138), *(float *)(e + 0x13c), *(float *)(e + 0x140)));
        }
    }

    *(byte *)(e + 0x166) = 1;

    neg_radius = -radius;
    *(float *)(e + 0x104) = neg_radius;
    *(float *)(e + 0x108) = neg_radius;
    *(float *)(e + 0x10c) = 0.0f;
    *(float *)(e + 0x110) = radius;
    *(float *)(e + 0x114) = radius;
    *(float *)(e + 0x118) = height;

    *(byte *)(e + 0xf2) = 0x21;

    if (*(byte *)(level + 0x1348) != 0) {
        if (G_SpawnFloat("wait", "", &wait) && !(0.0f < wait)) {
            *(int *)(e + 0x170) |= 0x10;
        }
    }

    spawnflags = *(int *)(e + 0x170);
    *(int *)(e + 0x11c) = 0;
    if (!(spawnflags & 8))
        *(int *)(e + 0x11c) = 0x40000000;
    if (spawnflags & 1)
        *(int *)(e + 0x11c) |= 0x40000;
    if (spawnflags & 2)
        *(int *)(e + 0x11c) |= 0x80000;
    if (spawnflags & 4)
        *(int *)(e + 0x11c) |= 0x100000;

    SV_LinkEntity(ent);
}

/* line 160 */
void SP_trigger_disk(gentity_t *ent)
{
    byte *e = (byte *)ent;
    byte *level;
    float radius;
    float wait;
    int spawnflags;

    if (!G_SpawnFloat("radius", "", &radius)) {
        Com_Error(1, va("radius not specified for trigger_radius at (%g %g %g)",
            *(float *)(e + 0x138), *(float *)(e + 0x13c), *(float *)(e + 0x140)));
    }

    *(byte *)(e + 0x166) = 1;

    radius += 64.0f;
    *(float *)(e + 0x104) = -radius;
    *(float *)(e + 0x108) = -radius;
    *(float *)(e + 0x10c) = -100000.0f;
    *(float *)(e + 0x110) = radius;
    *(float *)(e + 0x114) = radius;
    *(float *)(e + 0x118) = 100000.0f;

    *(byte *)(e + 0xf2) = 0x41;

    level = level_ptr;
    if (*(byte *)(level + 0x1348) != 0) {
        if (G_SpawnFloat("wait", "", &wait) && !(0.0f < wait)) {
            *(int *)(e + 0x170) |= 0x10;
        }
    }

    spawnflags = *(int *)(e + 0x170);
    *(int *)(e + 0x11c) = 0;
    if (!(spawnflags & 8))
        *(int *)(e + 0x11c) = 0x40000000;
    if (spawnflags & 1)
        *(int *)(e + 0x11c) |= 0x40000;
    if (spawnflags & 2)
        *(int *)(e + 0x11c) |= 0x80000;
    if (spawnflags & 4)
        *(int *)(e + 0x11c) |= 0x100000;

    SV_LinkEntity(ent);
}

/* line 282 */
void SP_trigger_once(gentity_t *ent)
{
    byte *e = (byte *)ent;
    int spawnflags;

    *(byte *)(e + 0x166) = 1;
    *(int *)(e + 0x170) |= 0x10;

    SV_SetBrushModel(ent);
    *(byte *)(e + 0xf2) = 1;
    *(int *)(e + 8) |= 1;

    *(int *)(e + 0x11c) = 0;
    spawnflags = *(int *)(e + 0x170);
    if (!(spawnflags & 8))
        *(int *)(e + 0x11c) = 0x40000000;
    if (spawnflags & 1)
        *(int *)(e + 0x11c) |= 0x40000;
    if (spawnflags & 2)
        *(int *)(e + 0x11c) |= 0x80000;
    if (spawnflags & 4)
        *(int *)(e + 0x11c) |= 0x100000;

    SV_LinkEntity(ent);
}

/* line 89 */
void Touch_Multi(gentity_t *self, gentity_t *other, qboolean bTouched)
{
    byte *s = (byte *)self;

    G_Trigger(self, other);

    if (*(int *)(s + 0x170) & 0x10)
        G_FreeEntityDelay(self);
}

/* line 195 */
void hurt_touch(gentity_t *self, gentity_t *other, qboolean bTouched)
{
    byte *s = (byte *)self;
    byte *o = (byte *)other;
    byte *level;
    int spawnflags;
    int dflags;

    if (*(byte *)(o + 0x161) == 0)
        return;

    level = level_ptr;
    if (*(int *)(s + 0x1b0) > *(int *)(level + 0x1ec))
        return;

    G_Trigger(self, other);

    spawnflags = *(int *)(s + 0x170);

    if (spawnflags & 0x10) {
        *(int *)(s + 0x1b0) = *(int *)(level_ptr + 0x1ec) + 1000;
    } else {
        *(int *)(s + 0x1b0) = *(int *)(level_ptr + 0x1ec) + 50;
    }

    dflags = (spawnflags & 8) ? 0x10 : 0;

    G_Damage(other, self, self, NULL, NULL, *(int *)(s + 0x19c), dflags, 0xd, 0, 0);

    if (*(int *)(s + 0x170) & 0x20)
        *(byte *)(s + 0x166) = 2;
}

/* line 388 */
void Activate_trigger_damage(gentity_t *pEnt, gentity_t *pOther, int iDamage, int iMOD)
{
    byte *e = (byte *)pEnt;
    byte *o = (byte *)pOther;
    int threshold;
    int spawnflags;
    int accumulate;

    threshold = *(int *)(e + 0x1a8);
    if (threshold > 0 && threshold > iDamage)
        return;

    spawnflags = *(int *)(e + 0x170);

    /* Check damage type filters */
    if (spawnflags & 1) {
        if (iMOD == 1) return;
    }
    if (spawnflags & 2) {
        if (iMOD == 2) return;
    }
    if (spawnflags & 4) {
        if ((unsigned)(iMOD - 3) <= 3) return;
    }
    if (spawnflags & 8) {
        if (iMOD <= 14 && ((1 << iMOD) & 0x4078))
            return;
    }
    if (spawnflags & 0x10) {
        if (iMOD == 4 || iMOD == 6) return;
    }
    if (spawnflags & 0x20) {
        if (iMOD == 7) return;
    }
    if (spawnflags & 0x100) {
        if (iMOD <= 13 && ((1 << iMOD) & 0x3e01))
            return;
    }

    /* Check accumulate */
    accumulate = *(int *)(e + 0x1ac);
    if (accumulate != 0) {
        if (accumulate > 0x7d00 - *(int *)(e + 0x194))
            return;
    }

    if (iMOD != -1)
        G_Trigger(pEnt, pOther);

    spawnflags = *(int *)(e + 0x170);
    *(int *)(e + 0x194) = 0x7d00;

    if (spawnflags & 0x200)
        G_FreeEntityDelay(pEnt);
}

/* line 540 */
void G_GrenadeTouchTriggerDamage(gentity_t *pActivator, vec_t *vStart, vec_t *vEnd, int iDamage, int iMOD)
{
    vec_t vMins[3], vMaxs[3];
    int iTouch[1024];
    int iNum;
    int i;
    byte *pHit;
    byte *g_entities;
    byte *g_scr_data;

    vMins[0] = vStart[0]; vMins[1] = vStart[1]; vMins[2] = vStart[2];
    vMaxs[0] = vStart[0]; vMaxs[1] = vStart[1]; vMaxs[2] = vStart[2];

    AddPointToBounds(vEnd, vMins, vMaxs);

    iNum = CM_AreaEntities(vMins, vMaxs, iTouch, 1024, 0x400000);
    if (iNum <= 0)
        return;

    g_entities = g_entities_ptr;

    for (i = 0; i < iNum; i++) {
        pHit = g_entities + iTouch[i] * ENTITY_STRIDE;

        if (*(unsigned short *)(pHit + 0x168) != *(unsigned short *)(imp_scr_const + 0x5a))
            continue;

        if (!(*(byte *)(pHit + 0x175) & 0x40))
            continue;

        if (!SV_SightTraceToEntity(vStart, (vec_t *)g_trace_zero_ptr, (vec_t *)g_trace_zero_ptr,
                                   vEnd, *(int *)pHit, -1))
            continue;

        Scr_AddEntity(pActivator);
        Scr_AddInt(iDamage);
        Scr_Notify((gentity_t *)pHit, *(unsigned short *)(imp_scr_const + 8), 2);

        Activate_trigger_damage((gentity_t *)pHit, pActivator, iDamage, iMOD);

        if (*(int *)(pHit + 0x1ac) == 0)
            *(int *)(pHit + 0x194) = 0x7d00;
    }
}

/* line 485 */
void G_CheckHitTriggerDamage(gentity_t *pActivator, vec_t *vStart, vec_t *vEnd, int iDamage, int iMOD)
{
    vec_t vMins[3], vMaxs[3];
    int iTouch[1024];
    int iNum;
    int i;
    byte *pHit;
    byte *g_entities;

    vMins[0] = vStart[0]; vMins[1] = vStart[1]; vMins[2] = vStart[2];
    vMaxs[0] = vStart[0]; vMaxs[1] = vStart[1]; vMaxs[2] = vStart[2];

    AddPointToBounds(vEnd, vMins, vMaxs);

    iNum = CM_AreaEntities(vMins, vMaxs, iTouch, 1024, 0x400000);
    if (iNum <= 0)
        return;

    g_entities = g_entities_ptr;

    for (i = 0; i < iNum; i++) {
        pHit = g_entities + iTouch[i] * ENTITY_STRIDE;

        if (*(unsigned short *)(pHit + 0x168) != *(unsigned short *)(imp_scr_const + 0x5a))
            continue;

        if (!SV_SightTraceToEntity(vStart, (vec_t *)g_trace_zero_ptr, (vec_t *)g_trace_zero_ptr,
                                   vEnd, *(int *)pHit, -1))
            continue;

        Scr_AddEntity(pActivator);
        Scr_AddInt(iDamage);
        Scr_Notify((gentity_t *)pHit, *(unsigned short *)(imp_scr_const + 8), 2);

        Activate_trigger_damage((gentity_t *)pHit, pActivator, iDamage, iMOD);

        if (*(int *)(pHit + 0x1ac) == 0) {
            *(int *)(pHit + 0x194) = 0x7d00;
        }
    }
}

/* line 449 */
void Die_trigger_damage(gentity_t *pSelf, gentity_t *pInflictor, gentity_t *pAttacker, int iDamage, int iMod, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int timeOffset)
{
    byte *s = (byte *)pSelf;

    Activate_trigger_damage(pSelf, pAttacker, iDamage, iMod);

    if (*(int *)(s + 0x1ac) == 0)
        *(int *)(s + 0x194) = 0x7d00;
}

/* line 434 */
void Pain_trigger_damage(gentity_t *pSelf, gentity_t *pAttacker, int iDamage, const vec_t *vPoint, const int iMod, const vec_t *vDir, const hitLocation_t hitLoc)
{
    byte *s = (byte *)pSelf;

    Activate_trigger_damage(pSelf, pAttacker, iDamage, iMod);

    if (*(int *)(s + 0x1ac) == 0)
        *(int *)(s + 0x194) = 0x7d00;
}

/* line 423 */
void Use_trigger_damage(gentity_t *pEnt, gentity_t *pOther, gentity_t *pActivator)
{
    byte *e = (byte *)pEnt;

    Activate_trigger_damage(pEnt, pOther, *(int *)(e + 0x1ac) + 1, -1);
}
