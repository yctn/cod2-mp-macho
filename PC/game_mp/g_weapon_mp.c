/* ASM dump from: g_weapon_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_weapon_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 */

static vec2_t traceOffsets[5]; /* traceOffsets */

/* Math functions */
extern float floorf(float x);
extern float ceilf(float x);

/* Extern functions */
extern char * va(const char *format, ...);
extern void SV_GameSendServerCommand(int clientNum, int svscmd_type, const char *text);
extern int BG_FindWeaponIndexForName(const char *name);
extern int BG_GetWeaponIndexForName(const char *name, void *weaponInfoMem);
extern qboolean OnSameTeam(gentity_t *ent1, gentity_t *ent2);

/* External globals */
extern struct level_locals_t level;
extern void *bg_weaponInfoMem; /* imp_G_RegisterWeapon - weapon info memory ptr */

/* Entity/client field access macros */
#define ENT_TAKEDAMAGE(e)    ((e)->takedamage)
#define ENT_CLIENT(e)        ((e)->client)
#define CLIENT_PS_PM_TYPE(c) ((c)->ps.pm_type)

void SnapVectorTowards(vec_t *v, vec_t *to);
qboolean LogAccuracyHit(gentity_t *target, gentity_t *attacker);
int G_GetWeaponIndexForName(const char *name);
void G_SetEquippedOffHand(int clientNum, int offHandIndex);
void G_SelectWeaponIndex(int clientNum, int iWeaponIndex);
void Weapon_RocketLauncher_Fire(gentity_s (*ent)[16], float spread, weaponParms *wp);
int weapon_grenadelauncher_fire(gentity_s (*ent)[16], int grenType, weaponParms *wp);
void G_UseOffHand(gentity_s (*ent)[16]);
static Bool Melee_Trace(gentity_s (*ent)[16], weaponParms *wp, int damage, float range, float width, float height, trace_t *trace, vec_t *endPos);
void Weapon_Melee(gentity_s (*ent)[16], weaponParms *wp, float range, float width, float height);
void FireWeaponMelee(gentity_s (*ent)[16]);
static void Bullet_Fire_Extended(const gentity_t *source, gentity_s (*attacker)[16], vec_t *end, float damageMultiplier, int recursion, const weaponParms *wp, const gentity_t *weaponEnt, const int gametime);
void G_SetupWeaponDef(void);
void Bullet_Endpos(float spread, vec_t *end, const weaponParms *wp, float maxRange);
void Bullet_Fire(gentity_s (*attacker)[16], float spread, weaponParms *wp, gentity_s (*weaponEnt)[16], int gametime);
void FireWeaponAntiLag(gentity_s (*ent)[16], int gametime);
qboolean G_GivePlayerWeapon(playerState_t *pPS, int iWeaponIndex);

/* line 172 */
void SnapVectorTowards(vec_t *v, vec_t *to)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (v[i] >= to[i])
            v[i] = floorf(v[i]);
        else
            v[i] = ceilf(v[i]);
    }
}

/* line 679 */
qboolean LogAccuracyHit(gentity_t *target, gentity_t *attacker)
{
    if (!ENT_TAKEDAMAGE(target))
        return 0;
    if (target == attacker)
        return 0;
    if (!ENT_CLIENT(target))
        return 0;
    if (!ENT_CLIENT(attacker))
        return 0;
    if (CLIENT_PS_PM_TYPE(ENT_CLIENT(target)) > 5)
        return 0;
    if (OnSameTeam(target, attacker))
        return 0;
    return 1;
}

/* line 963 */
int G_GetWeaponIndexForName(const char *name)
{
    if (!level.initializing)
        return BG_FindWeaponIndexForName(name);
    return BG_GetWeaponIndexForName(name, bg_weaponInfoMem);
}

/* line 985 */
void G_SetEquippedOffHand(int clientNum, int offHandIndex)
{
    SV_GameSendServerCommand(clientNum, 1, va("%c %i", 0x43, offHandIndex));
}

/* line 974 */
void G_SelectWeaponIndex(int clientNum, int iWeaponIndex)
{
    SV_GameSendServerCommand(clientNum, 1, va("%c %i", 0x61, iWeaponIndex));
}

/* line 644 */
#include <math.h>
extern float randomf(void);
extern float Vec3Normalize(vec3_t v);
extern void *fire_rocket(gentity_t *ent, vec_t *start, vec_t *dir);
extern void *fire_grenade(gentity_t *ent, vec_t *start, vec_t *vel, int grenType, int fuseTime);
extern void AngleVectors(vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern void G_GetPlayerViewOrigin(gentity_t *ent, vec_t *origin);
extern void G_LocationalTrace(void *results, const vec_t *start, const vec_t *end, int passEntityNum, int contentmask, unsigned char *priorityMap);
extern void G_CheckHitTriggerDamage(gentity_t *attacker, vec_t *start, vec_t *end, int damage, int mod);
extern void *G_TempEntity(vec_t *origin, int event);
extern int DirToByte(vec_t *dir);
extern void G_Damage(gentity_t *target, gentity_t *inflictor, gentity_t *attacker, void *dir, vec_t *point, int damage, int dflags, int mod, int hitLoc, int timeOffset);
extern void G_GetPlayerViewDirection(gentity_t *ent, vec_t *forward, vec_t *right, vec_t *up);
extern void *BG_GetWeaponDef(int weaponIndex);
extern int rand(void);

void Weapon_RocketLauncher_Fire(gentity_s (*ent)[16], float spread, weaponParms *wp) {
    float fAimOffset;
    float r1, r2;
    float angle;
    float cosVal, sinVal;
    float rightScale, upScale;
    vec3_t dir;
    vec3_t launchpos;
    gentity_t *missile;
    gclient_t *client;
    double angRad;

    /* Convert spread to aim offset */
    angRad = (double)spread * 0.017453292519943295;
    fAimOffset = (float)tan(angRad);
    fAimOffset *= 16.0f;

    /* Random angle and radius */
    r1 = (float)randomf(); /* random [0,1] */
    r2 = (float)randomf(); /* random [0,1] */
    angle = r1 * 360.0f;
    angle = (float)((double)angle * 0.017453292519943295);

    cosVal = cosf(angle);
    rightScale = r2 * cosVal * fAimOffset;
    sinVal = sinf(angle);
    upScale = r2 * sinVal * fAimOffset;

    /* dir = forward * 16 */
    dir[0] = wp->forward[0] * 16.0f;
    dir[1] = wp->forward[1] * 16.0f;
    dir[2] = wp->forward[2] * 16.0f;

    /* dir += right * rightScale */
    dir[0] += rightScale * wp->right[0];
    dir[1] += rightScale * wp->right[1];
    dir[2] += rightScale * wp->right[2];

    /* dir += up * upScale */
    dir[0] += upScale * wp->up[0];
    dir[1] += upScale * wp->up[1];
    dir[2] += upScale * wp->up[2];

    Vec3Normalize(dir);

    /* Copy launch position */
    launchpos[0] = wp->muzzleTrace[0];
    launchpos[1] = wp->muzzleTrace[1];
    launchpos[2] = wp->muzzleTrace[2];

    missile = (gentity_t *)fire_rocket((gentity_t *)ent, launchpos, dir);

    /* Kick back */
    client = ((gentity_t *)ent)->client;
    if (client) {
        client->ps.velocity[0] += wp->forward[0] * -64.0f;
        client->ps.velocity[1] += wp->forward[1] * -64.0f;
        client->ps.velocity[2] += wp->forward[2] * -64.0f;
    }
}

/* line 615 */
int weapon_grenadelauncher_fire(gentity_s (*ent)[16], int grenType, weaponParms *wp) {
    vec3_t vTossVel;
    float scale;
    int fuseTime;
    gentity_t *m;
    gclient_t *client;
    float dot;
    float *forward;
    void *weapDef;

    /* Get weapon def for projectile speed/up-velocity */
    weapDef = (void *)wp->weapDef;
    scale = (float)((WeaponDef *)weapDef)->iProjectileSpeed;
    /* vTossVel = forward * scale */
    vTossVel[0] = wp->forward[0] * scale;
    vTossVel[1] = wp->forward[1] * scale;
    vTossVel[2] = wp->forward[2] * scale;

    /* Add upward velocity component */
    vTossVel[2] += (float)((WeaponDef *)weapDef)->iProjectileSpeedUp;

    /* Get fuse time */
    fuseTime = ((WeaponDef *)weapDef)->iFuseTime;

    /* Fire the grenade */
    m = (gentity_t *)fire_grenade((gentity_t *)ent, wp->muzzleTrace, vTossVel, grenType, fuseTime);

    /* Normalize toss velocity */
    Vec3Normalize(vTossVel);

    /* Add velocity dot product to missile origin */
    client = ((gentity_t *)ent)->client;
    forward = client->ps.velocity;
    dot = vTossVel[0] * forward[0] + vTossVel[1] * forward[1] + vTossVel[2] * forward[2];

    m->s.pos.trDelta[0] += vTossVel[0] * dot;
    m->s.pos.trDelta[1] += vTossVel[1] * dot;
    m->s.pos.trDelta[2] += vTossVel[2] * dot;

    return (int)m;
}

/* line 797 */
void G_UseOffHand(gentity_s (*ent)[16]) {
    vec3_t viewang;
    vec3_t forward, right, up;
    vec3_t muzzlePoint;
    weaponParms wp;
    gclient_t *client;
    int weaponIndex;
    void *weapDef;

    client = ((gentity_t *)ent)->client;

    /* Get current off-hand weapon index */
    weaponIndex = client->ps.offHandIndex;
    weapDef = BG_GetWeaponDef(weaponIndex);

    /* Get view angles from client */
    viewang[0] = client->ps.viewangles[0];
    viewang[1] = client->ps.viewangles[1];
    viewang[2] = client->ps.viewangles[2];

    /* Override pitch/yaw with view command angles */
    viewang[0] = client->fGunPitch;
    viewang[1] = client->fGunYaw;

    /* Build direction vectors */
    AngleVectors(viewang, (float *)&wp, right, up);

    /* Get muzzle origin */
    G_GetPlayerViewOrigin((gentity_t *)ent, muzzlePoint);

    /* Fire grenade launcher with off-hand weapon */
    weapon_grenadelauncher_fire(ent, client->ps.offHandIndex, &wp);
}

/* line 41 */
static Bool Melee_Trace(gentity_s (*ent)[16], weaponParms *wp, int damage, float range, float width, float height, trace_t *trace, vec_t *endPos) {
    int numTraces;
    int traceIndex;
    vec3_t end;
    float widthScale, heightScale;
    float fraction;
    float *origin;
    float *forward;
    float *right;
    float *up;

    if (width > 0.0f || height > 0.0f) {
        numTraces = 5;
    } else {
        numTraces = 1;
    }

    origin = wp->muzzleTrace;
    forward = wp->forward;
    right = wp->right;
    up = wp->up;

    for (traceIndex = 0; traceIndex < numTraces; traceIndex++) {
        /* end = origin + forward * range */
        end[0] = forward[0] * range + origin[0];
        end[1] = forward[1] * range + origin[1];
        end[2] = forward[2] * range + origin[2];

        /* Add right offset */
        widthScale = width * ((float *)&traceOffsets)[traceIndex * 2];
        end[0] += right[0] * widthScale;
        end[1] += right[1] * widthScale;
        end[2] += right[2] * widthScale;

        /* Add up offset */
        heightScale = height * ((float *)&traceOffsets)[traceIndex * 2 + 1];
        end[0] += up[0] * heightScale;
        end[1] += up[1] * heightScale;
        end[2] += up[2] * heightScale;

        /* Do the trace */
        G_LocationalTrace(trace, origin, end, ((gentity_t *)ent)->s.number, 0x2802831, (unsigned char *)imp_bulletPriorityMap);

        /* Compute hit position via interpolation */
        fraction = trace->fraction;
        endPos[0] = origin[0] + (end[0] - origin[0]) * fraction;
        endPos[1] = origin[1] + (end[1] - origin[1]) * fraction;
        endPos[2] = origin[2] + (end[2] - origin[2]) * fraction;

        /* First trace also checks trigger damage */
        if (traceIndex == 0) {
            G_CheckHitTriggerDamage((gentity_t *)ent, origin, endPos, damage, 7);
        }

        /* Check for entity hit (not pass-through and fraction < 1.0) */
        if (trace->surfaceFlags & 0x10) {
            /* startsolid - skip */
        } else if (trace->fraction == 1.0f) {
            /* Complete miss - skip */
        } else {
            return 1;
        }
    }

    return 0;
}

/* line 102 */
void Weapon_Melee(gentity_s (*ent)[16], weaponParms *wp, float range, float width, float height) {
    int damage;
    trace_t tr;
    vec3_t endpos;
    gentity_t *traceEnt;
    gentity_t *tent;
    int traceEntNum;
    int weaponIndex;

    /* Get melee damage from weapon def */
    weaponIndex = ((gentity_t *)ent)->s.weapon;
    damage = ((WeaponDef *)BG_GetWeaponDef(weaponIndex))->iMeleeDamage;

    if (!Melee_Trace(ent, wp, damage, range, width, height, &tr, endpos))
        return;

    /* Get trace entity */
    traceEntNum = tr.entityNum;
    traceEnt = &((gentity_t *)imp_g_entities)[traceEntNum];

    /* Create temp entity for melee effect */
    if (traceEnt->client != NULL) {
        /* Hit a player - blood effect */
        tent = (gentity_t *)G_TempEntity(endpos, 0xad);
    } else {
        /* Hit world/object - impact effect */
        tent = (gentity_t *)G_TempEntity(endpos, 0xae);
    }

    /* Set tent fields */
    tent->s.otherEntityNum = traceEntNum;

    /* DirToByte from trace normal */
    {
        int dirByte = DirToByte(tr.normal);
        tent->s.eventParm = (unsigned char)dirByte;
    }

    /* Copy weapon index */
    tent->s.weapon = ((gentity_t *)ent)->s.weapon;

    /* Check if hit world entity */
    if (traceEntNum == 0x3fe)
        return;

    /* Check if trace entity takes damage */
    if (!traceEnt->takedamage)
        return;

    /* Apply damage */
    {
        int locBits = tr.partGroup;
        int randVal = rand();
        int dmg = damage + (randVal % 5);
        G_Damage(traceEnt, (gentity_t *)ent, (gentity_t *)ent, wp, endpos, dmg, 7, 0, locBits, 0);
    }
}
