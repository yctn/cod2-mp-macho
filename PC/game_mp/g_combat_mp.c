/* Converted to C from ASM: g_combat_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_combat_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern float sqrtf(float x);

extern int I_stricmp(const char *s1, const char *s2);
extern short Scr_AllocString(const char *str, int flag);
extern int FS_FOpenFileByMode(const char *filename, int *f, int mode);
extern int FS_Read(void *buffer, int len, int f);
extern void FS_FCloseFile(int f);
extern int Info_Validate(const char *s);
extern int ParseConfigStringToStruct(float *dest, void *fields, int numFields, const char *buffer, int unused1, int unused2, void (*callback)(byte *, const char *));
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void *BG_GetWeaponDef(int weapon);
extern void G_GetPlayerViewOrigin(gentity_t *ent, vec_t *origin);
extern float Vec3Normalize(vec_t *v);
extern float Vec3NormalizeTo(const vec_t *v, vec_t *out);
extern int G_LocationalTracePassed(const vec_t *start, const vec_t *end, int entityNum, int contentmask);
extern void Scr_AddEntity(gentity_t *ent);
extern void Scr_AddInt(int value);
extern void Scr_Notify(gentity_t *ent, int name, int numArgs);
extern int LogAccuracyHit(gentity_t *target, gentity_t *attacker);
extern int CM_AreaEntities(const vec_t *mins, const vec_t *maxs, int *entityList, int maxcount, int areatype);
extern void G_TraceCapsule(void *results, const vec_t *start, const vec_t *end, const vec_t *end2, const vec_t *mins, int passEntityNum, int contentmask);
extern void Scr_PlayerDamage(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, int damage, int dflags, int mod, int weapon, const vec_t *dir, const vec_t *point, hitLocation_t hitLoc, int timeOffset);
extern int Com_GetServerDObj(int clientNum);
extern int BG_AnimScriptEvent(void *ps, int event, int isContinue, int force);
extern void Scr_PlayerKilled(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int meansOfDeath, int iWeapon, const vec_t *vDir, hitLocation_t hitLoc, int psTimeOffset);
extern gentity_t *fire_grenade(gentity_t *self, vec_t *start, vec_t *dir, int grenadeWPID, int clientNum);
extern void Cmd_Score_f(gentity_t *ent);
extern void SV_UnlinkEntity(gentity_t *ent);
extern void SV_LinkEntity(gentity_t *ent);
extern float vectoyaw(const vec_t *vec);
extern float crandom(void);
extern float randomf(void);

extern unsigned char bulletPriorityMap[19]; /* 0x0 */
extern unsigned char riflePriorityMap[19]; /* 0x0 */
extern char * modNames[15]; /* 0x0 */
extern float g_fHitLocDamageMult[19]; /* 0x0 */
extern const char * g_HitLocNames[19]; /* g_HitLocNames */
static scr_string_t g_HitLocConstNames[19]; /* g_HitLocConstNames */

extern byte g_entities_ptr[]; /* imp_g_entities - g_entities base */
extern byte level_ptr[]; /* imp_level */
extern byte *g_clients_ptr; /* imp_entityHandlers */
extern byte *g_debug_damage_ptr; /* imp_g_debugDamage */
extern byte *g_scr_data_ptr; /* imp_scr_const */
extern int g_sNextDmgTableId; /* 0x195b048 */
extern int g_time; /* imp_level_bgs */
extern byte g_time_ptr[]; /* imp_bgs */
extern int g_phys_world; /* imp_vec3_origin */

/* line 99 */
static void G_HitLocStrcpy(byte *pMember, const char *pszKeyValue)
{
    strcpy((char *)pMember, pszKeyValue);
}

/* line 110 */
void G_ParseHitLocDmgTable(void)
{
    struct {
        const char *name;
        int offset;
        int type;
    } hitLocDmgFields[19];
    char buffer[0x2000];
    int hFile;
    int iFileLength;
    int i;

    /* Initialize hit location fields and damage multipliers */
    for (i = 0; i < 19; i++) {
        g_fHitLocDamageMult[i] = 1.0f;
        hitLocDmgFields[i].name = g_HitLocNames[i];
        hitLocDmgFields[i].offset = i * 4;
        hitLocDmgFields[i].type = 6;
        g_HitLocConstNames[i] = Scr_AllocString(g_HitLocNames[i], 1);
    }

    g_sNextDmgTableId = 0;

    iFileLength = FS_FOpenFileByMode("info/mp_lochit_dmgtable", &hFile, 0);
    if (iFileLength <= 0) {
        Com_Error(1, "Could not load hitloc damage table %s\n", "info/mp_lochit_dmgtable");
    }

    /* Read header */
    FS_Read(buffer, 11, hFile);
    buffer[11] = '\0';

    /* Check magic header "LOCDMGTABLE" */
    if (memcmp(buffer, "LOCDMGTABLE", 11) != 0) {
        Com_Error(1, "\"%s\" does not appear to be a hitloc damage table\n", "info/mp_lochit_dmgtable");
    }

    iFileLength -= 11;
    if (iFileLength > 0x1fff) {
        Com_Error(1, "\"%s\" Is too long of a hitloc damage table to parse\n", "info/mp_lochit_dmgtable");
    }

    /* Read remaining data */
    FS_Read(buffer, iFileLength, hFile);
    buffer[iFileLength] = '\0';
    FS_FCloseFile(hFile);

    if (!Info_Validate(buffer)) {
        Com_Error(1, "\"%s\" is not a valid hitloc damage table\n", "info/mp_lochit_dmgtable");
    }

    if (!ParseConfigStringToStruct(g_fHitLocDamageMult, hitLocDmgFields, 19, buffer, 0, 0, G_HitLocStrcpy)) {
        Com_Error(1, "Error parsing hitloc damage table %s\n", "info/mp_lochit_dmgtable");
    }
}

/* line 261 */
int G_IndexForMeansOfDeath(const char *pszMOD)
{
    int i;

    for (i = 0; i < 15; i++) {
        if (I_stricmp(pszMOD, modNames[i]) == 0) {
            return i;
        }
    }

    Com_Printf("Unknown means of death string '%s'\n", pszMOD);
    return 0;
}

/* line 766 */
scr_string_t G_GetHitLocationString(hitLocation_t hitLoc)
{
    return g_HitLocConstNames[hitLoc];
}

/* line 781 */
hitLocation_t G_GetHitLocationIndexFromString(int sString)
{
    int i;

    for (i = 0; i < 19; i++) {
        if (g_HitLocConstNames[i] == (scr_string_t)sString) {
            return (hitLocation_t)i;
        }
    }

    return (hitLocation_t)0;
}

/* line 547 */
float CanDamage(gentity_t *targ, const vec_t *origin)
{
    byte *t = (byte *)targ;
    vec3_t dest;
    vec3_t endpoints[5];
    vec3_t forward;
    vec3_t eyeOrigin;
    int hits;
    int i;

    if (*(int *)(t + 0x158) != 0) {
        /* Player path: use eye origin */
        G_GetPlayerViewOrigin(targ, eyeOrigin);

        float halfHeight = (eyeOrigin[2] - *(float *)(t + 0x140)) * 0.5f;

        /* VectorSubtract: forward = origin - targ->origin */
        forward[0] = *(float *)(origin) - *(float *)(t + 0x138);
        forward[1] = *(float *)(origin + 1) - *(float *)(t + 0x13c);
        forward[2] = 0.0f;
        Vec3Normalize(forward);

        float right_x = -forward[1];
        float right_y = forward[0];
        float right_z = forward[2];

        /* midpoint = (eyeOrigin + targ->origin) * 0.5 */
        float mid_x = (eyeOrigin[0] + *(float *)(t + 0x138)) * 0.5f;
        float mid_y = (eyeOrigin[1] + *(float *)(t + 0x13c)) * 0.5f;
        float mid_z = (eyeOrigin[2] + *(float *)(t + 0x140)) * 0.5f;

        /* endpoint 0: midpoint (center) */
        dest[0] = mid_x;
        dest[1] = mid_y;
        dest[2] = mid_z;

        /* endpoint 1: midpoint + right*15, z + halfHeight */
        endpoints[0][0] = mid_x + right_x * 15.0f;
        endpoints[0][1] = mid_y + right_y * 15.0f;
        float z_plus = mid_z + right_z * 15.0f;
        endpoints[0][2] = z_plus + halfHeight;

        /* endpoint 2: same xy as ep1, z - halfHeight */
        endpoints[1][0] = endpoints[0][0];
        endpoints[1][1] = endpoints[0][1];
        endpoints[1][2] = z_plus - halfHeight;

        /* endpoint 3: midpoint - right*15, z + halfHeight */
        endpoints[2][0] = mid_x + right_x * -15.0f;
        endpoints[2][1] = mid_y + right_y * -15.0f;
        float z_minus = mid_z + right_z * -15.0f;
        endpoints[2][2] = z_minus + halfHeight;

        /* endpoint 4: same xy as ep3, z - halfHeight */
        endpoints[3][0] = endpoints[2][0];
        endpoints[3][1] = endpoints[2][1];
        endpoints[3][2] = z_minus - halfHeight;

        hits = 0;
        for (i = 0; i < 5; i++) {
            vec_t *ep = (i == 0) ? dest : endpoints[i - 1];
            if (G_LocationalTracePassed(origin, ep, *(int *)t, 0x802891) >= 1) {
                hits++;
            }
        }

        if (hits == 0) {
            return 0.0f;
        }
        if (hits > 3) {
            return 1.0f;
        }
        return (float)hits / 3.0f;
    } else {
        /* Entity path: use absmin/absmax center */
        float mid_x = (*(float *)(t + 0x120) + *(float *)(t + 0x12c)) * 0.5f;
        float mid_y = (*(float *)(t + 0x124) + *(float *)(t + 0x130)) * 0.5f;
        float mid_z = (*(float *)(t + 0x128) + *(float *)(t + 0x134)) * 0.5f;

        dest[0] = mid_x;
        dest[1] = mid_y;
        dest[2] = mid_z;

        /* endpoint 1: +15x, +15y, same z */
        endpoints[0][0] = mid_x + 15.0f;
        endpoints[0][1] = mid_y + 15.0f;
        endpoints[0][2] = mid_z;

        /* endpoint 2: +15x, -15y, same z */
        endpoints[1][0] = endpoints[0][0];
        endpoints[1][1] = mid_y - 15.0f;
        endpoints[1][2] = mid_z;

        /* endpoint 3: -15x, +15y, same z */
        endpoints[2][0] = mid_x - 15.0f;
        endpoints[2][1] = endpoints[0][1];
        endpoints[2][2] = mid_z;

        /* endpoint 4: -15x, -15y, same z */
        endpoints[3][0] = endpoints[2][0];
        endpoints[3][1] = endpoints[1][1];
        endpoints[3][2] = mid_z;

        for (i = 0; i < 5; i++) {
            vec_t *ep = (i == 0) ? dest : endpoints[i - 1];
            if (G_LocationalTracePassed(ep, origin, *(int *)t, 0x802891)) {
                return 1.0f;
            }
        }
        return 0.0f;
    }
}

/* Helper: get hit location damage multiplier */
static float G_GetHitLocDamageMult(int weapon, hitLocation_t hitLoc)
{
    void *weapDef;

    if (weapon == 0) {
        return g_fHitLocDamageMult[hitLoc];
    }

    weapDef = BG_GetWeaponDef(weapon);
    if (weapDef == NULL || *(int *)((byte *)weapDef + 0x78) == 0) {
        return g_fHitLocDamageMult[hitLoc];
    }

    return *(float *)((byte *)weapDef + 0x5b0 + hitLoc * 4);
}

/* Helper: check if player can take damage */
static int G_IsPlayerDamageable(byte *ps)
{
    if (*(byte *)(ps + 0xe) != 0) {
        if (*(int *)(ps + 0x27ac) == 0 && *(int *)(ps + 0x27b0) == 0) {
            if (*(int *)(ps + 0x26c4) == 2) {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

/* line 462 */
void G_Damage(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec_t *dir, const vec_t *point, int damage, int dflags, int mod, hitLocation_t hitLoc, int timeOffset)
{
    byte *t = (byte *)targ;
    byte *ps;
    int weapon;
    float fDamage;
    int iDamage;
    vec3_t localdir;
    int health;

    ps = *(byte **)(t + 0x158);

    if (ps != NULL) {
        /* Player target */
        if (!G_IsPlayerDamageable(ps)) {
            return;
        }

        /* Get weapon from inflictor or attacker */
        if (inflictor != NULL) {
            weapon = *(int *)((byte *)inflictor + 0xc8);
        } else if (attacker != NULL) {
            weapon = *(int *)((byte *)attacker + 0xc8);
        } else {
            weapon = 0;
        }

        fDamage = (float)damage;
        fDamage *= G_GetHitLocDamageMult(weapon, hitLoc);
        iDamage = (int)fDamage;

        if (iDamage <= 0) {
            return;
        }

        Scr_PlayerDamage(targ, inflictor, attacker, iDamage, dflags, mod, weapon, dir, point, hitLoc, timeOffset);
        return;
    }

    /* Entity (non-player) target */
    if (*(byte *)(t + 0x161) == 0) {
        return;
    }

    if (inflictor == NULL) {
        byte *ents = (byte *)g_entities_ptr;
        inflictor = (gentity_t *)(ents + 0x8bba0);
    }

    if (attacker == NULL) {
        byte *ents = (byte *)g_entities_ptr;
        attacker = (gentity_t *)(ents + 0x8bba0);
    }

    Vec3NormalizeTo(dir, localdir);

    /* Check FL_GODMODE */
    if (*(int *)(t + 0x174) & 1) {
        return;
    }

    /* Ensure minimum 1 damage */
    if (damage <= 0) {
        damage = 1;
    }

    /* Check FL_NO_KNOCKBACK (flag 2) */
    health = *(int *)(t + 0x194);
    if (*(int *)(t + 0x174) & 2) {
        /* Has shield/armor */
        if (health - damage <= 0) {
            damage = health - 1;
        }
    }

    /* Debug damage print */
    {
        byte *dvar = *(byte **)g_debug_damage_ptr;
        dvar = *(byte **)dvar;
        if (*(byte *)(dvar + 8) != 0) {
            Com_Printf("target:%i health:%i damage:%i\n", *(int *)t, health, damage);
        }
    }

    health = *(int *)(t + 0x194);
    health -= damage;
    *(int *)(t + 0x194) = health;

    /* Notify "damage" */
    Scr_AddEntity(attacker);
    Scr_AddInt(damage);
    {
        byte *scr_data = *(byte **)g_scr_data_ptr;
        Scr_Notify(targ, *(unsigned short *)(scr_data + 8), 2);
    }

    if (health > 0) {
        /* Still alive - call pain callback */
        int entType = *(unsigned char *)(t + 0x166);
        byte *client = *(byte **)g_clients_ptr + entType * 40;
        void (*pain)(gentity_t *, gentity_t *, int, const vec_t *, int, hitLocation_t) =
            *(void (**)())(client + 0x14);
        if (pain != NULL) {
            pain(targ, attacker, damage, point, mod, hitLoc);
        }
    } else {
        /* Dead */
        if (health < -999) {
            *(int *)(t + 0x194) = -999;
        }

        /* Notify "death" */
        Scr_AddEntity(attacker);
        {
            byte *scr_data = *(byte **)g_scr_data_ptr;
            Scr_Notify(targ, *(unsigned short *)(scr_data + 0xa), 1);
        }

        /* Call die callback */
        int entType = *(unsigned char *)(t + 0x166);
        byte *client = *(byte **)g_clients_ptr + entType * 40;
        void (*die)(gentity_t *, gentity_t *, gentity_t *, int, int, int, const vec_t *, hitLocation_t, int) =
            *(void (**)())(client + 0x18);
        if (die != NULL) {
            int iWeapon = *(int *)((byte *)inflictor + 0xc8);
            die(targ, inflictor, attacker, damage, mod, iWeapon, localdir, hitLoc, timeOffset);
        }
    }
}

/* line 641 */
qboolean G_RadiusDamage(const vec_t *origin, gentity_t *inflictor, gentity_t *attacker, float fInnerDamage, float fOuterDamage, float radius, gentity_t *ignore, int mod)
{
    vec3_t mins, maxs;
    int entityList[1024];
    int numListedEntities;
    int e;
    int i;
    vec3_t v;
    vec3_t dir;
    vec3_t dest;
    float dist;
    float points;
    float damageScale;
    int hitClient;
    byte *ent;
    float radiusTweak;
    void *tr_buf[7]; /* trace_t */

    if (attacker == NULL) {
        hitClient = 0;
        goto done;
    }

    if (radius < 1.0f) {
        radius = 1.0f;
    }

    float searchRadius = radius * 1.4142135f;

    /* Build search box */
    for (i = 0; i < 3; i++) {
        mins[i] = origin[i] - searchRadius;
        maxs[i] = origin[i] + searchRadius;
    }

    numListedEntities = CM_AreaEntities(mins, maxs, entityList, 1024, -1);
    if (numListedEntities <= 0) {
        hitClient = 0;
        goto done;
    }

    radiusTweak = radius * 0.2f;
    hitClient = 0;

    for (e = 0; e < numListedEntities; e++) {
        int entIdx = entityList[e];
        ent = (byte *)g_entities_ptr + entIdx * 560;

        if ((gentity_t *)ent == ignore) {
            continue;
        }

        if (*(byte *)(ent + 0x161) == 0) {
            continue;
        }

        if (*(byte *)(ent + 0xf1) == 0) {
            /* Use currentOrigin */
            v[0] = *(float *)(ent + 0x138) - origin[0];
            v[1] = *(float *)(ent + 0x13c) - origin[1];
            v[2] = *(float *)(ent + 0x140) - origin[2];
        } else {
            /* Use absmin/absmax clamp */
            for (i = 0; i < 3; i++) {
                float emin = *(float *)(ent + 0x120 + i * 4);
                float emax = *(float *)(ent + 0x12c + i * 4);
                if (emin > origin[i]) {
                    v[i] = emin - origin[i];
                } else if (emax < origin[i]) {
                    v[i] = origin[i] - emax;
                } else {
                    v[i] = 0.0f;
                }
            }
        }

        /* VectorLength */
        dist = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

        if (dist >= radius) {
            continue;
        }

        /* Check player intermission */
        if (*(int *)(ent + 0x158) != 0) {
            byte *lev = (byte *)level_ptr;
            if (*(int *)(lev + 0x35f4) != 0) {
                continue;
            }
        }

        /* Calculate damage based on distance */
        points = fInnerDamage - fOuterDamage;
        points = (1.0f - dist / radius) * points + fOuterDamage;

        damageScale = CanDamage((gentity_t *)ent, origin);
        if (damageScale > 0.0f) {
            if (LogAccuracyHit((gentity_t *)ent, attacker)) {
                hitClient = 1;
            }

            /* dir = ent->origin - origin */
            dir[0] = *(float *)(ent + 0x138) - origin[0];
            dir[1] = *(float *)(ent + 0x13c) - origin[1];
            dir[2] = *(float *)(ent + 0x140) - origin[2] + 24.0f;

            G_Damage((gentity_t *)ent, inflictor, attacker, dir, origin,
                     (int)(points * damageScale), 1, mod, 0, 0);
        } else {
            /* CanDamage returned 0 - try trace to bounds center */
            dest[0] = (*(float *)(ent + 0x120) + *(float *)(ent + 0x12c)) * 0.5f;
            dest[1] = (*(float *)(ent + 0x124) + *(float *)(ent + 0x130)) * 0.5f;
            dest[2] = (*(float *)(ent + 0x128) + *(float *)(ent + 0x134)) * 0.5f;

            {
                byte *pw = *(byte **)&g_phys_world;
                G_TraceCapsule(tr_buf, origin, (const vec_t *)pw, (const vec_t *)pw, dest, 0x3ff, 0x811);
            }

            if (*(float *)tr_buf >= 1.0f) {
                continue;
            }

            /* Check if close enough */
            dest[0] -= origin[0];
            dest[1] -= origin[1];
            dest[2] -= origin[2];
            float traceDist = sqrtf(dest[0] * dest[0] + dest[1] * dest[1] + dest[2] * dest[2]);
            if (radiusTweak <= traceDist) {
                continue;
            }

            if (LogAccuracyHit((gentity_t *)ent, attacker)) {
                hitClient = 1;
            }

            dir[0] = *(float *)(ent + 0x138) - origin[0];
            dir[1] = *(float *)(ent + 0x13c) - origin[1];
            dir[2] = *(float *)(ent + 0x140) - origin[2] + 24.0f;

            G_Damage((gentity_t *)ent, inflictor, attacker, dir, origin,
                     (int)(points * 0.1f), 1, mod, 0, 0);
        }
    }

done:
    return hitClient;
}

/* line 282 */
void player_die(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int meansOfDeath, int iWeapon, const vec_t *vDir, const hitLocation_t hitLoc, int psTimeOffset)
{
    byte *s = (byte *)self;
    byte *ps;
    int dobj;
    vec3_t dir;
    vec3_t launchvel;
    vec3_t launchspot;
    int animResult;
    int i;
    float yaw;

    /* Check DObj exists */
    ps = *(byte **)(s + 0x158);
    dobj = Com_GetServerDObj(*(int *)(ps + 0xcc));
    if (!dobj) {
        return;
    }

    /* Check session state and flags */
    ps = *(byte **)(s + 0x158);
    if (*(int *)(ps + 4) > 1) {
        return;
    }
    if (*(byte *)(ps + 0xe) & 0x40) {
        return;
    }

    /* Update level time */
    {
        int levelTime = *(int *)&g_time;
        byte *timePtr = *(byte **)g_time_ptr;
        *(int *)timePtr = levelTime;
    }

    /* Check attacker type - if turret, resolve to user */
    if (*(int *)((byte *)attacker + 4) == 9) {
        int ownerNum = *(int *)((byte *)attacker + 0x150);
        if (ownerNum != 0x3ff) {
            byte *ents = (byte *)g_entities_ptr;
            gentity_t *owner = (gentity_t *)(ents + ownerNum * 560);
            attacker = owner;
        }
    }

    /* Notify "death" to attacker */
    Scr_AddEntity(attacker);
    {
        byte *scr_data = *(byte **)g_scr_data_ptr;
        Scr_Notify(self, *(unsigned short *)(scr_data + 0xa), 1);
    }

    /* Check if attacker is player on turret - get turret weapon */
    if (iWeapon != 0) {
        byte *att = (byte *)attacker;
        byte *att_ps = *(byte **)(att + 0x158);
        if (att_ps != NULL && (*(int *)(att_ps + 0xa0) & 0x300) != 0) {
            /* Resolve turret entity weapon */
            int ownerIdx = *(int *)((byte *)attacker + 0x74);
            byte *ents = (byte *)g_entities_ptr;
            byte *mg42Ent = ents + ownerIdx * 560;
            if (*(int *)(mg42Ent + 4) == 9) {
                iWeapon = *(int *)(mg42Ent + 0xc8);
            }
        }
    }

    /* Check for grenade drop */
    ps = *(byte **)(s + 0x158);
    if (*(int *)(ps + 0x3c) != 0) {
        /* Has a grenade to drop */
        float lv_x, lv_y, lv_z;

        lv_x = crandom();
        lv_y = crandom();
        lv_z = randomf();

        launchvel[0] = lv_x * 160.0f;
        launchvel[1] = lv_y * 160.0f;
        launchvel[2] = lv_z * 160.0f;

        /* Copy origin */
        *(int *)&launchspot[0] = *(int *)(s + 0x138);
        *(int *)&launchspot[1] = *(int *)(s + 0x13c);
        launchspot[2] = *(float *)(s + 0x140) + 40.0f;

        fire_grenade(self, launchspot, launchvel,
                     *(int *)(ps + 0x3c), *(int *)(ps + 0xd0));
        ps = *(byte **)(s + 0x158);
    }

    /* Set death animation */
    {
        int state = 0;
        if (*(int *)(ps + 4) == 1) {
            state = 1;
        }
        *(int *)(ps + 4) = state + 6;
    }

    animResult = BG_AnimScriptEvent(ps, 1, 0, 1);

    /* Call script killed callback */
    Scr_PlayerKilled(self, inflictor, attacker, damage, meansOfDeath,
                     iWeapon, vDir, hitLoc, psTimeOffset);

    /* Update score for connected players watching this entity */
    {
        byte *lev = (byte *)level_ptr;
        int maxClients = *(int *)(lev + 0x1e4);

        if (maxClients > 0) {
            byte *ents = (byte *)g_entities_ptr;
            int offset = 0;
            byte *entPtr = ents;

            for (i = 0; i < maxClients; i++) {
                byte *cl = *(byte **)lev + offset;
                if (*(int *)(cl + 0x26c4) == 2 && *(int *)(cl + 0x26a8) == 2) {
                    if (*(int *)(cl + 0x27a8) == *(int *)s) {
                        Cmd_Score_f((gentity_t *)entPtr);
                    }
                }
                offset += 0x28a4;
                entPtr += 0x230;
            }
        }
    }

    /* Set entity state */
    *(byte *)(s + 0x161) = 1;
    *(int *)(s + 0x11c) = 0x4000000;
    *(int *)(s + 0x14c) = 0;

    /* Calculate death direction */
    if (attacker != NULL && attacker != self) {
        /* Direction from attacker to self */
        dir[0] = *(float *)((byte *)attacker + 0x138) - *(float *)(s + 0x138);
        dir[1] = *(float *)((byte *)attacker + 0x13c) - *(float *)(s + 0x13c);
        dir[2] = *(float *)((byte *)attacker + 0x140) - *(float *)(s + 0x140);
    } else if (inflictor != NULL && inflictor != self) {
        /* Direction from inflictor to self */
        dir[0] = *(float *)((byte *)inflictor + 0x138) - *(float *)(s + 0x138);
        dir[1] = *(float *)((byte *)inflictor + 0x13c) - *(float *)(s + 0x13c);
        dir[2] = *(float *)((byte *)inflictor + 0x140) - *(float *)(s + 0x140);
    } else {
        /* Self-kill: use current angles yaw */
        ps = *(byte **)(s + 0x158);
        *(int *)(ps + 0x130) = (int)*(float *)(s + 0x148);
        goto after_yaw;
    }

    ps = *(byte **)(s + 0x158);
    yaw = vectoyaw(dir);
    *(int *)(ps + 0x130) = (int)yaw;
    vectoyaw(dir); /* called twice in original */

after_yaw:
    /* Copy viewangles to delta_angles */
    ps = *(byte **)(s + 0x158);
    {
        byte *to = ps + 0xe8;
        byte *from = s + 0x144;
        *(int *)(to) = *(int *)(from);
        *(int *)(to + 4) = *(int *)(from + 4);
        *(int *)(to + 8) = *(int *)(from + 8);
    }

    *(int *)(s + 0x84) = 0;
    SV_UnlinkEntity(self);
    *(int *)(s + 0x118) = 0x41f00000; /* 30.0f as int */
    SV_LinkEntity(self);
    *(int *)(s + 0x194) = 0;
    *(byte *)(s + 0x166) = 11;
}
