/* Decompiled from: g_mover_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_mover_mp.cpp */

#include "common_types.h"
#include "imports.h"

#ifndef qtrue
#define qtrue 1
#define qfalse 0
#endif

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

/*
 * Binary gentity_s layout uses byte pointer arithmetic.
 *
 * Key offsets (binary):
 *   0x00  s.number           0x04  s.eType            0x08  s.eFlags
 *   0x0C  s.pos (trajectory) 0x18  s.pos.trBase       0x30  s.apos
 *   0x54  s.time             0x58  s.time2
 *   0x7C  s.groundEntityNum  0xD8  s.dmgFlags         0xDC  s.animMovetype
 *   0xF0  r.linked           0xF1  r.bmodel           0xF2  r.svFlags
 *   0x104 r.mins             0x110 r.maxs             0x11C r.contents
 *   0x120 r.absmin           0x12C r.absmax
 *   0x138 r.currentOrigin    0x144 r.currentAngles
 *   0x150 r.ownerNum         0x158 client
 *   0x160 physicsObject      0x161 takedamage
 *   0x166 handler            0x168 classname
 *   0x174 flags              0x184 clipmask
 *   0x190 nextthink          0x194 health
 *   0x1A8 (chain)            0x1AC (tagInfo)
 *   0x208 tagInfo(binary)    0x1B4 (useCount area)
 */

/* gentity_s field access macros (using struct fields from common_types.h) */
#define _ENT(e)               ((gentity_t *)(e))
#define ENT_NUMBER(e)         (_ENT(e)->s.number)
#define ENT_ETYPE(e)          (_ENT(e)->s.eType)
#define ENT_POS(e)            (&_ENT(e)->s.pos)
#define ENT_POS_TRTYPE(e)     (_ENT(e)->s.pos.trType)
#define ENT_POS_TRTIME(e)     (_ENT(e)->s.pos.trTime)
#define ENT_POS_TRDURATION(e) (_ENT(e)->s.pos.trDuration)
#define ENT_POS_TRBASE(e)     (_ENT(e)->s.pos.trBase)
#define ENT_APOS(e)           (&_ENT(e)->s.apos)
#define ENT_APOS_TRTYPE(e)    (_ENT(e)->s.apos.trType)
#define ENT_APOS_TRTIME(e)    (_ENT(e)->s.apos.trTime)
#define ENT_APOS_TRDURATION(e)(_ENT(e)->s.apos.trDuration)
#define ENT_TIME(e)           (_ENT(e)->s.time)
#define ENT_GROUNDENTNUM(e)   (_ENT(e)->s.groundEntityNum)
#define ENT_DMGFLAGS(e)       (_ENT(e)->s.dmgFlags)
#define ENT_ANIMMOVETYPE(e)   (_ENT(e)->s.animMovetype)
#define ENT_LINKED(e)         (_ENT(e)->r.linked)
#define ENT_BMODEL(e)         (_ENT(e)->r.bmodel)
#define ENT_SVFLAGS(e)        (_ENT(e)->r.svFlags)
#define ENT_MINS(e)           (_ENT(e)->r.mins)
#define ENT_MAXS(e)           (_ENT(e)->r.maxs)
#define ENT_CONTENTS(e)       (_ENT(e)->r.contents)
#define ENT_CONTENTS_BYTE3(e) (*(byte *)((byte *)&_ENT(e)->r.contents + 3))
#define ENT_ABSMIN(e)         (_ENT(e)->r.absmin)
#define ENT_ABSMAX(e)         (_ENT(e)->r.absmax)
#define ENT_CURRENTORIGIN(e)  (_ENT(e)->r.currentOrigin)
#define ENT_CURRENTANGLES(e)  (_ENT(e)->r.currentAngles)
#define ENT_OWNERNUM(e)       (_ENT(e)->r.ownerNum)
#define ENT_CLIENT(e)         ((byte *)(_ENT(e)->client))
#define ENT_PHYSICSOBJECT(e)  (_ENT(e)->physicsObject)
#define ENT_TAKEDAMAGE(e)     (_ENT(e)->takedamage)
#define ENT_HANDLER(e)        (_ENT(e)->handler)
#define ENT_CLIPMASK(e)       (_ENT(e)->clipmask)
#define ENT_TAGINFO(e)        (_ENT(e)->tagInfo)

#define ENTITY_STRIDE sizeof(gentity_s)

/* External globals (BSS/data pointers) */
extern byte level_ptr[];         /* imp_level */
extern byte g_entities_ptr[];    /* imp_g_entities */
extern byte *entityHandlers_ptr; /* imp_entityHandlers */

/* level_ptr field access */
#define LEVEL_TIME          (((level_locals_t *)level_ptr)->time)
#define LEVEL_PREVIOUSTIME  (((level_locals_t *)level_ptr)->previousTime)

/* Handler table access: each entry is 40 bytes */
#define HANDLER_ENTRY(h)    (entityHandlers_ptr + (h) * 40)
#define HANDLER_REACHED(h)  (*(void (**)())(HANDLER_ENTRY(h) + 4))
#define HANDLER_BLOCKED(h)  (*(void (**)(gentity_t *, gentity_t *))(HANDLER_ENTRY(h) + 8))

/* g_entities_ptr entity access by number */
#define G_ENTITY(num) ((gentity_t *)(g_entities_ptr + (num) * ENTITY_STRIDE))

/* VectorCopy inline */
#define VectorCopy(a, b) ((b)[0]=(a)[0], (b)[1]=(a)[1], (b)[2]=(a)[2])

extern char * hintStrings[6]; /* 0x0 */
static pushed_t pushed[1024]; /* pushed */
static pushed_t *pushed_p; /* pushed_p */

/* Forward declarations for extern functions */
extern void SV_SetBrushModel(gentity_t *ent);
extern void SV_LinkEntity(gentity_t *ent);
extern void SV_UnlinkEntity(gentity_t *ent);
extern qboolean G_SpawnString(const char *key, const char *defaultString, const char **out);
extern int I_stricmp(const char *s1, const char *s2);
extern void SV_GetConfigstring(int index, char *buffer, int bufferSize);
extern void SV_SetConfigstring(int index, const char *val);
extern void Com_Error(int code, const char *fmt, ...);
extern void AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern void G_TraceCapsule(trace_t *result, vec_t *start, vec_t *mins, vec_t *maxs, vec_t *end, int skipNumber, int mask);
extern float RadiusFromBounds(vec_t *mins, vec_t *maxs);
extern int CM_AreaEntities(vec_t *mins, vec_t *maxs, int *entityList, int maxcount, int contentmask);
extern void BG_EvaluateTrajectory(trajectory_t *tr, int atTime, vec_t *result);
extern void G_Damage(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec_t *dir, const vec_t *point, int damage, int dflags, int mod, int hitLoc, int timeOffset);
extern unsigned char G_GeneralLink(gentity_t *ent);
extern int G_RunThink(gentity_t *ent);

/* Function prototypes */
void use_trigger_use(gentity_t *ent, gentity_t *other, gentity_t *activator);
static void trigger_use_shared(gentity_t *ent);
void trigger_use(gentity_t *ent);
void trigger_use_touch(gentity_t *ent);
qboolean G_TryPushingEntity(gentity_t *check, gentity_t *pusher, vec_t *move, vec_t *amove);
void G_MoverTeam(gentity_t *ent);
void G_RunMover(gentity_t *ent);

/*
 * Helper: G_TraceCapsuleForEntity
 * Wraps G_TraceCapsule with entity-specific clipmask/ownerNum logic.
 * Based on repeated pattern at "line 65" / "line 67" / "line 81-84"
 */
static void G_TraceCapsuleForEntity(trace_t *tr, gentity_t *check, vec_t *origin, vec_t *mins, vec_t *maxs)
{
    int mask;
    int passEntityNum;

    mask = ENT_CLIPMASK(check);
    if (mask != 0) {
        if (ENT_CONTENTS_BYTE3(check) & 4) {
            /* Use entity's ownerNum as passEntityNum */
            if (ENT_ETYPE(check) == 4) {
                passEntityNum = ENT_OWNERNUM(check);
            } else {
                passEntityNum = ENT_NUMBER(check);
            }
            G_TraceCapsule(tr, origin, mins, maxs, origin, passEntityNum, mask);
            return;
        }
    } else {
        mask = 0x811; /* default mask */
    }

    if (ENT_ETYPE(check) == 4) {
        passEntityNum = ENT_OWNERNUM(check);
    } else {
        passEntityNum = ENT_NUMBER(check);
    }
    G_TraceCapsule(tr, origin, mins, maxs, origin, passEntityNum, mask);
}

/*
 * Helper: trace_is_stuck
 * Returns non-zero if the trace indicates the entity is stuck (allsolid or startsolid).
 * Checks the 16-bit word covering both allsolid and startsolid bytes.
 */
#define TRACE_IS_STUCK(tr) (*(unsigned short *)&(tr)->allsolid)

/* line 522 */
void use_trigger_use(gentity_t *ent, gentity_t *other, gentity_t *activator)
{
    /* Empty function - just returns */
    (void)ent;
    (void)other;
    (void)activator;
}

/* line 527 */
static void trigger_use_shared(gentity_t *ent)
{
    const char *cursorhint;
    char szConfigString[1024];
    int i;

    /* line 535 */
    SV_SetBrushModel(ent);
    /* line 536 */
    SV_LinkEntity(ent);
    /* line 538 - set spawnflags area to ENTITYNUM_NONE */
    ent->tagInfo = 0x3ff;
    /* line 539 */
    ENT_POS_TRTYPE(ent) = 0;
    /* line 540 - VectorCopy(currentOrigin, pos.trBase) */
    VectorCopy(ENT_CURRENTORIGIN(ent), ENT_POS_TRBASE(ent));
    /* line 542 - set contents */
    ENT_CONTENTS(ent) = 0x200000;
    /* line 544 - set bmodel flag */
    ENT_BMODEL(ent) = 1;
    /* line 546 - set handler */
    ENT_HANDLER(ent) = 0x12;
    /* line 549 - set animMovetype */
    ENT_ANIMMOVETYPE(ent) = 2;

    /* line 552 - G_SpawnString for "cursorhint" */
    if (G_SpawnString("cursorhint", "", &cursorhint)) {
        /* line 554 */
        if (I_stricmp(cursorhint, "HINT_NOICON") == 0) {
            /* line 555 */
            ENT_ANIMMOVETYPE(ent) = -1;
        } else {
            for (i = 1; i < 6; i++) {
                /* line 560 */
                if (I_stricmp(cursorhint, hintStrings[i]) == 0) {
                    /* line 562 */
                    ENT_ANIMMOVETYPE(ent) = i;
                    break;
                }
            }
        }
    }

    /* line 570 - set dmgFlags to default 0xff */
    ENT_DMGFLAGS(ent) = 0xff;

    /* line 571 - G_SpawnString for "hintstring" */
    if (G_SpawnString("hintstring", "", &cursorhint)) {
        /* Search through configstrings 0x4fe..0x51d (32 entries) */
        for (i = 0; i < 32; i++) {
            /* line 576 */
            SV_GetConfigstring(0x4fe + i, szConfigString, 1024);
            /* line 577 */
            if (szConfigString[0] == '\0') {
                /* line 579 - empty slot, set the configstring */
                SV_SetConfigstring(0x4fe + i, cursorhint);
                /* line 580 */
                ENT_DMGFLAGS(ent) = (unsigned char)i;
                return;
            }
            /* line 583 - check if already exists */
            if (strcmp(cursorhint, szConfigString) == 0) {
                /* line 585 */
                ENT_DMGFLAGS(ent) = (unsigned char)i;
                return;
            }
        }
        /* line 591 - too many different hintstrings */
        Com_Error(1, "Too many different hintstring key values on trigger_use ent", 32);
    }
}

/* line 596 */
void trigger_use(gentity_t *ent)
{
    /* line 598 */
    trigger_use_shared(ent);
}

/* line 602 */
void trigger_use_touch(gentity_t *ent)
{
    /* line 604 */
    trigger_use_shared(ent);
}

/* line 154 */
qboolean G_TryPushingEntity(gentity_t *check, gentity_t *pusher, vec_t *move, vec_t *amove)
{
    trace_t tr;
    vec3_t vOrigin;
    vec3_t org2;
    vec3_t forward, right, up;
    float matrix[9]; /* 3x3 transpose matrix */
    vec3_t org, org2_rel;
    int i, j;
    float fx, fy, fz;
    float halfSize;
    gentity_t *hitEnt;
    byte *client;
    vec_t *savedOrigin;

    savedOrigin = ENT_CURRENTORIGIN(check);

    /* line 240-242: vOrigin = currentOrigin + move */
    vOrigin[0] = ENT_CURRENTORIGIN(check)[0] + move[0];
    vOrigin[1] = ENT_CURRENTORIGIN(check)[1] + move[1];
    vOrigin[2] = ENT_CURRENTORIGIN(check)[2] + move[2];

    /* line 100: AngleVectors for rotation */
    AngleVectors(amove, forward, right, up);

    /* line 224-226: negate right vector */
    right[0] = -right[0];
    right[1] = -right[1];
    right[2] = -right[2];

    /* Build transpose matrix from forward/right/up (3x3) */
    /* matrix[col][row] = vectors transposed */
    for (i = 0; i < 3; i++) {
        vec_t *src;
        if (i == 0) src = forward;
        else if (i == 1) src = right;
        else src = up;
        for (j = 0; j < 3; j++) {
            matrix[j * 3 + i] = src[j];
        }
    }

    /* line 248-250: org = vOrigin - pusher->currentOrigin */
    org[0] = vOrigin[0] - ENT_CURRENTORIGIN(pusher)[0];
    org[1] = vOrigin[1] - ENT_CURRENTORIGIN(pusher)[1];
    org[2] = vOrigin[2] - ENT_CURRENTORIGIN(pusher)[2];

    /* line 138-140: org2 = matrix * org (3x3 matrix multiply) */
    org2[0] = org[0] * matrix[0] + org[1] * matrix[1] + org[2] * matrix[2];
    org2[1] = org[0] * matrix[3] + org[1] * matrix[4] + org[2] * matrix[5];
    org2[2] = org[0] * matrix[6] + org[1] * matrix[7] + org[2] * matrix[8];

    /* Update vOrigin with rotation delta */
    vOrigin[0] += org2[0] - org[0];
    vOrigin[1] += org2[1] - org[1];
    vOrigin[2] += org2[2] - org[2];

    /* First trace with vOrigin */
    G_TraceCapsuleForEntity(&tr, check, vOrigin, ENT_MINS(check), ENT_MAXS(check));

    /* line 86: check if entity is stuck at new position */
    if (TRACE_IS_STUCK(&tr)) {
        /* line 175: check if hit entity is valid */
        hitEnt = G_ENTITY((int)tr.entityNum);
        if (hitEnt != NULL) {
            /* line 193: try multiple positions if entity is large enough */
            halfSize = (double)ENT_MAXS(check)[0] * 0.5;
            if (halfSize > 4.0 && halfSize > 0.0) {
                /* Try different offsets to find a clear position */
                for (fz = 0.0f; (double)fz < (double)ENT_MAXS(check)[0] * 0.5; fz += 4.0f) {
                    float neg_fz = -fz;
                    float fz_step = fz + fz;
                    for (fx = 4.0f; (double)fx < (double)ENT_MAXS(check)[0] * 0.5; fx += 4.0f) {
                        float neg_fx = -fx;
                        float fx_step = fx + fx;
                        for (fy = 4.0f; (double)fy < (double)ENT_MAXS(check)[0] * 0.5; fy += 4.0f) {
                            float neg_fy = -fy;
                            float fy_step = fy + fy;
                            float saved_z;
                            /* line 206-208: try origin with offsets */
                            org2[0] = neg_fx + vOrigin[0];
                            saved_z = neg_fz + vOrigin[2];
                            while (1) {
                                org2[1] = neg_fy + vOrigin[1];
                                org2[2] = saved_z;
                                G_TraceCapsuleForEntity(&tr, check, org2, ENT_MINS(check), ENT_MAXS(check));

                                /* line 86: check if stuck */
                                if (TRACE_IS_STUCK(&tr)) {
                                    hitEnt = G_ENTITY((int)tr.entityNum);
                                    if (hitEnt != NULL) {
                                        /* Advance fy */
                                        neg_fy += fy_step;
                                        if (neg_fy < fy) {
                                            continue;
                                        }
                                        /* Reload constants after function call may have clobbered them */
                                        goto advance_fy_done;
                                    }
                                }
                                /* Found clear position */
                                goto try_push_success;
                            }
advance_fy_done:
                            ; /* fy loop continues */
                        }
                        /* fy exhausted */
                    }
                    /* fx exhausted */
                }
            }

            /* All offset attempts failed, try original origin */
            G_TraceCapsuleForEntity(&tr, check, ENT_CURRENTORIGIN(check), ENT_MINS(check), ENT_MAXS(check));

            if (TRACE_IS_STUCK(&tr)) {
                hitEnt = G_ENTITY((int)tr.entityNum);
                if (hitEnt != NULL) {
                    /* Can't push - blocked */
                    /* line 247 */
                    ENT_GROUNDENTNUM(check) = 0x3ff;
                    return qtrue;
                }
            }

            /* Blocked but entity is not solid */
            ENT_GROUNDENTNUM(check) = 0x3ff;
            return qtrue;
        }
    }

    /* line 178: first trace passed, update groundEntityNum */
    if (ENT_GROUNDENTNUM(check) != ENT_NUMBER(pusher)) {
        ENT_GROUNDENTNUM(check) = 0x3ff;
    }

    /* Copy vOrigin to currentOrigin and pos.trBase */
    VectorCopy(vOrigin, ENT_CURRENTORIGIN(check));
    VectorCopy(vOrigin, ENT_POS_TRBASE(check));

    /* line 183: update client if present */
    client = ENT_CLIENT(check);
    if (client != NULL) {
        /* line 185: add amove[1] * 182.044... to client delta yaw */
        int deltaYaw = (int)(amove[1] * 182.04444885253906f);
        deltaYaw &= 0xffff;
        ((gclient_t *)client)->ps.delta_angles[1] += deltaYaw;

        /* line 186: copy origin to client origin */
        client = ENT_CLIENT(check);
        VectorCopy(vOrigin, (vec_t *)(client + 0x14));
    }

    /* line 227: advance pushed_p */
    pushed_p++;
    return qtrue;

try_push_success:
    /* line 217: successful push with adjusted org2 */
    if (ENT_GROUNDENTNUM(check) != ENT_NUMBER(pusher)) {
        ENT_GROUNDENTNUM(check) = 0x3ff;
    }

    /* Copy org2 to currentOrigin and pos.trBase */
    VectorCopy(org2, ENT_CURRENTORIGIN(check));
    VectorCopy(org2, ENT_POS_TRBASE(check));

    /* line 222: update client if present */
    client = ENT_CLIENT(check);
    if (client != NULL) {
        int deltaYaw = (int)(amove[1] * 182.04444885253906f);
        deltaYaw &= 0xffff;
        ((gclient_t *)client)->ps.delta_angles[1] += deltaYaw;

        client = ENT_CLIENT(check);
        VectorCopy(org2, (vec_t *)(client + 0x14));
    }

    pushed_p++;
    return qtrue;
}

/* line 417 */
void G_MoverTeam(gentity_t *ent)
{
    vec3_t origin, angles;
    vec3_t move, amove;
    vec3_t mins, maxs;
    vec3_t totalMins, totalMaxs;
    int entityList[1024];
    int listedEntities;
    int moveEntities;
    int moveEntityList[1024];
    int e;
    gentity_t *check;
    pushed_t *p;
    qboolean success;
    gentity_t *obstacle;
    int i;
    float radius;
    byte *client;

    /* line 434: reset pushed_p to beginning of pushed array */
    pushed_p = pushed;

    /* line 437-438: evaluate pos and apos trajectories */
    BG_EvaluateTrajectory(ENT_POS(ent), LEVEL_TIME, origin);
    BG_EvaluateTrajectory(ENT_APOS(ent), LEVEL_TIME, angles);

    /* line 439: compute move = origin - currentOrigin */
    move[0] = origin[0] - ENT_CURRENTORIGIN(ent)[0];
    move[1] = origin[1] - ENT_CURRENTORIGIN(ent)[1];
    move[2] = origin[2] - ENT_CURRENTORIGIN(ent)[2];

    /* line 440: compute amove = angles - currentAngles */
    amove[0] = angles[0] - ENT_CURRENTANGLES(ent)[0];
    amove[1] = angles[1] - ENT_CURRENTANGLES(ent)[1];
    amove[2] = angles[2] - ENT_CURRENTANGLES(ent)[2];

    /* line 285: check if there is any angular movement */
    if (ENT_CURRENTANGLES(ent)[0] != 0.0f || ENT_CURRENTANGLES(ent)[1] != 0.0f ||
        ENT_CURRENTANGLES(ent)[2] != 0.0f || amove[0] != 0.0f || amove[1] != 0.0f || amove[2] != 0.0f) {
        /* Angular movement present - use radius-based bounds */
        /* line 287 */
        radius = RadiusFromBounds(ENT_MINS(ent), ENT_MAXS(ent));

        /* line 288-293: compute expanded bounds */
        for (i = 0; i < 3; i++) {
            float curOrigin = ENT_CURRENTORIGIN(ent)[i];
            float moveI = move[i];
            mins[i] = curOrigin - radius + moveI;
            maxs[i] = curOrigin + radius + moveI;
            totalMins[i] = curOrigin - radius;
            totalMaxs[i] = curOrigin + radius;
        }
    } else {
        /* No angular movement - use linear bounds */
        /* line 298-301 */
        for (i = 0; i < 3; i++) {
            float moveI = move[i];
            mins[i] = moveI + ENT_ABSMIN(ent)[i];
            maxs[i] = moveI + ENT_ABSMAX(ent)[i];
        }
        VectorCopy(ENT_ABSMIN(ent), totalMins);
        VectorCopy(ENT_ABSMAX(ent), totalMaxs);
    }

    /* line 306-311: extend totalMins/totalMaxs by move */
    for (i = 0; i < 3; i++) {
        if (move[i] > 0.0f) {
            totalMaxs[i] += move[i];
        } else {
            totalMins[i] += move[i];
        }
    }

    /* line 315 */
    SV_UnlinkEntity(ent);

    /* line 317 */
    listedEntities = CM_AreaEntities(totalMins, totalMaxs, entityList, 1024, 0x2000180);

    /* Update currentOrigin += move */
    ENT_CURRENTORIGIN(ent)[0] += move[0];
    ENT_CURRENTORIGIN(ent)[1] += move[1];
    ENT_CURRENTORIGIN(ent)[2] += move[2];

    /* Update currentAngles += amove */
    ENT_CURRENTANGLES(ent)[0] += amove[0];
    ENT_CURRENTANGLES(ent)[1] += amove[1];
    ENT_CURRENTANGLES(ent)[2] += amove[2];

    /* line 322 */
    SV_LinkEntity(ent);

    /* line 326: process listed entities */
    if (listedEntities <= 0) {
        obstacle = NULL;
        success = qtrue;
    } else {
        moveEntities = 0;

        for (e = 0; e < listedEntities; e++) {
            int entNum = entityList[e];
            check = G_ENTITY(entNum);

            /* line 331: check entity type - include movers (3,4), players (1), physics objects */
            {
                int eType = ENT_ETYPE(check);
                if (!((unsigned)(eType - 3) <= 1 || eType == 1 || ENT_PHYSICSOBJECT(check) != 0)) {
                    goto skip_entity;
                }
            }

            /* line 337: skip if already pushed by this mover */
            if (ENT_GROUNDENTNUM(check) == ENT_NUMBER(ent)) {
                goto add_to_move_list;
            }

            /* line 340: AABB overlap check */
            if (ENT_ABSMIN(check)[0] >= maxs[0]) goto skip_entity;
            if (ENT_ABSMIN(check)[1] >= maxs[1]) goto skip_entity;
            if (ENT_ABSMIN(check)[2] >= maxs[2]) goto skip_entity;
            if (mins[0] >= ENT_ABSMAX(check)[0]) goto skip_entity;
            if (mins[1] >= ENT_ABSMAX(check)[1]) goto skip_entity;
            if (mins[2] >= ENT_ABSMAX(check)[2]) goto skip_entity;

            /* line 347: trace to see if entity touches mover */
            {
                trace_t tr2;
                vec_t *checkOrigin = ENT_CURRENTORIGIN(check);

                G_TraceCapsuleForEntity(&tr2, check, checkOrigin, ENT_MINS(check), ENT_MAXS(check));

                if (TRACE_IS_STUCK(&tr2)) {
                    int hitNum = (int)tr2.entityNum;
                    check = G_ENTITY(hitNum);
                } else {
                    check = NULL;
                }

                if (check != ent) {
                    goto skip_entity;
                }
                /* Restore entityList entry */
                entNum = entityList[e];
            }

add_to_move_list:
            /* line 351 */
            moveEntityList[moveEntities] = entNum;
            moveEntities++;
            continue;

skip_entity:
            continue;
        }

        /* line 355: process move entities */
        if (moveEntities <= 0) {
            obstacle = NULL;
            success = qtrue;
        } else {
            /* Unlink all move entities first */
            for (i = 0; i < moveEntities; i++) {
                int num = moveEntityList[i];
                gentity_t *moveEnt = G_ENTITY(num);
                SV_UnlinkEntity(moveEnt);
            }

            obstacle = NULL;
            success = qtrue;

            /* Try pushing each entity */
            for (i = 0; i < moveEntities; i++) {
                int num = moveEntityList[i];
                gentity_t *pushEnt = G_ENTITY(num);

                /* line 366-367: save entity state to pushed list */
                pushed_p->ent = pushEnt;
                VectorCopy(ENT_CURRENTORIGIN(pushEnt), pushed_p->origin);
                /* line 368: save deltayaw */
                pushed_p->deltayaw = amove[1];

                /* line 371: try pushing */
                if (!G_TryPushingEntity(pushEnt, ent, move, amove)) {
                    /* line 382: check if entity is a mover (eType 3) */
                    if (ENT_ETYPE(pushEnt) == 3) {
                        /* line 384 */
                        SV_LinkEntity(pushEnt);
                    } else {
                        /* line 389: check if mover has pos or apos trType == 4 */
                        if (ENT_POS_TRTYPE(ent) == 4 || ENT_APOS_TRTYPE(ent) == 4) {
                            /* line 391: damage the entity */
                            G_Damage(pushEnt, ent, ent, NULL, NULL, 99999, 0, 9, 0, 0);
                        } else {
                            obstacle = pushEnt;
                            success = qfalse;
                        }
                    }
                } else {
                    /* line 384 */
                    SV_LinkEntity(pushEnt);
                }
            }

            /* line 402-405: relink all move entities */
            for (i = 0; i < moveEntities; i++) {
                int num = moveEntityList[i];
                gentity_t *moveEnt = G_ENTITY(num);
                SV_LinkEntity(moveEnt);
            }
        }
    }

    /* line 442: check success */
    if (!success) {
        /* line 447: undo all pushes */
        for (p = pushed_p - 1; p >= pushed; p--) {
            gentity_t *checkEnt = p->ent;

            /* line 451: restore currentOrigin */
            VectorCopy(p->origin, ENT_CURRENTORIGIN(checkEnt));
            /* line 452: restore pos.trBase */
            VectorCopy(p->origin, ENT_POS_TRBASE(checkEnt));

            /* line 453: restore client if present */
            client = ENT_CLIENT(checkEnt);
            if (client != NULL) {
                /* line 455: undo deltayaw */
                int deltaYaw = (int)(p->deltayaw * 182.04444885253906f);
                deltaYaw &= 0xffff;
                ((gclient_t *)client)->ps.delta_angles[1] -= deltaYaw;

                /* line 456: restore client origin */
                client = ENT_CLIENT(checkEnt);
                VectorCopy(p->origin, (vec_t *)(client + 0x14));
            }

            /* line 459 */
            SV_LinkEntity(checkEnt);
        }

        /* line 463: revert mover position */
        {
            int timeDelta = LEVEL_TIME - LEVEL_PREVIOUSTIME;
            ENT_POS_TRTIME(ent) += timeDelta;
            ENT_APOS_TRTIME(ent) += timeDelta;
        }

        /* line 465-466: re-evaluate trajectories */
        BG_EvaluateTrajectory(ENT_POS(ent), LEVEL_TIME, ENT_CURRENTORIGIN(ent));
        BG_EvaluateTrajectory(ENT_APOS(ent), LEVEL_TIME, ENT_CURRENTANGLES(ent));

        /* line 467 */
        SV_LinkEntity(ent);

        /* line 470: call blocked handler */
        {
            byte handlerIdx = ENT_HANDLER(ent);
            void (*blocked)(gentity_t *, gentity_t *) = *(void (**)(gentity_t *, gentity_t *))(HANDLER_ENTRY(handlerIdx) + 8);
            if (blocked != NULL) {
                blocked(ent, obstacle);
            }
        }
    } else {
        /* line 481: check pos trType for reached callback */
        if (ENT_POS_TRTYPE(ent) != 0) {
            /* line 483 */
            if (ENT_POS_TRTIME(ent) + ENT_POS_TRDURATION(ent) <= LEVEL_TIME) {
                /* line 485-487: call reached handler for pos */
                byte handlerIdx = ENT_HANDLER(ent);
                void (*reached)(gentity_t *) = *(void (**)(gentity_t *))(HANDLER_ENTRY(handlerIdx) + 4);
                if (reached != NULL) {
                    reached(ent);
                }
            }
        }

        /* line 492: check apos trType for reached callback */
        if (ENT_APOS_TRTYPE(ent) != 0) {
            /* line 494 */
            if (ENT_APOS_TRTIME(ent) + ENT_APOS_TRDURATION(ent) <= LEVEL_TIME) {
                /* line 496-497: call reached handler for apos */
                byte handlerIdx = ENT_HANDLER(ent);
                void (*reached)(gentity_t *) = *(void (**)(gentity_t *))(HANDLER_ENTRY(handlerIdx) + 4);
                if (reached != NULL) {
                    reached(ent);
                }
            }
        }
    }
}

/* line 510 */
void G_RunMover(gentity_t *ent)
{
    /* line 512: check tagInfo */
    if (ENT_TAGINFO(ent) != 0) {
        /* line 513 */
        G_GeneralLink(ent);
    } else {
        /* line 514: check if pos or apos trType is non-zero */
        if (ENT_POS_TRTYPE(ent) != 0 || ENT_APOS_TRTYPE(ent) != 0) {
            /* line 515 */
            G_MoverTeam(ent);
        }
    }
    /* line 518 */
    G_RunThink(ent);
}
