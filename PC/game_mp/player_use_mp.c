/* Decompiled from: player_use_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/player_use_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

/* Extern function declarations */
extern qboolean Scr_IsSystemActive(int localClientNum);
extern void Scr_AddEntity(gentity_t *ent);
extern void Scr_Notify(gentity_t *ent, int stringValue, unsigned int paramcount);
extern void G_GetPlayerViewOrigin(gentity_t *ent, vec3_t origin);
extern void G_GetPlayerViewDirection(gentity_t *ent, vec3_t forward, vec3_t right, vec3_t up);
extern int CM_AreaEntities(vec3_t mins, vec3_t maxs, int *entityList, int maxcount, int contentmask);
extern float Vec3Normalize(vec_t *v);
extern qboolean SV_EntityContact(vec3_t mins, vec3_t maxs, gentity_t *ent);
extern qboolean G_IsTurretUsable(gentity_t *turret, gentity_t *player);
extern qboolean BG_CanItemBeGrabbed(const entityState_t *ent, const playerState_t *ps, qboolean bTouched);
extern int G_TraceCapsuleComplete(vec3_t start, vec3_t mins, vec3_t maxs, vec3_t end, int passEntityNum, int contentMask);
extern qboolean G_DObjGetWorldTagPos(gentity_t *ent, unsigned int tagName, vec_t *pos);
extern void G_LocationalTrace(trace_t *trace, vec3_t start, vec3_t end, int passEntityNum, int contentMask, unsigned char *priorityMap);
extern float SV_FX_GetVisibility(vec3_t start, vec3_t end);
extern void G_Trigger(gentity_t *self, gentity_t *other);
extern void *BG_GetWeaponDef(int weapon);

/* Extern global pointers (binary addresses) */
extern byte g_entities_ptr[];    /* imp_g_entities */
extern byte level_ptr[];         /* imp_level */
extern byte scr_const_ptr[];     /* imp_scr_const */
extern entityHandler_t entityHandlers[20];
extern byte *vec3_origin_ptr;   /* imp_vec3_origin */
extern byte *bg_itemlist_ptr;   /* imp_bg_itemlist */
extern const dvar_t *g_useholdspawndelay;
extern const dvar_t *g_useholdtime;
extern byte *pPriorityMap;      /* imp_bulletPriorityMap */
extern byte *pPriorityMapAlt;   /* imp_riflePriorityMap */
extern const dvar_t *g_friendlyNameDist;
extern const dvar_t *g_friendlyfireDist;

/* Function declarations */
void Player_UpdateActivate(gentity_t *ent);
static int compare_use(const void *pe1, const void *pe2);
static int Player_GetUseList(gentity_t *ent, useList_t *useList);
void Player_UpdateCursorHints(gentity_t *ent);
void Player_UpdateLookAtEntity(gentity_t *ent);

/* Entity stride in binary */
#define GENTITY_SIZE 0x230

#define GENTITY(num)            ((gentity_t *)(g_entities_ptr + (num) * GENTITY_SIZE))

/* Typed binary-backed entity accessors. */
#define ENT_S_NUMBER(e)         (((gentity_t *)(e))->s.number)
#define ENT_S_ETYPE(e)          (((gentity_t *)(e))->s.eType)
#define ENT_S_WEAPON(e)         (((gentity_t *)(e))->s.weapon)
#define ENT_S_DMGFLAGS(e)       (((gentity_t *)(e))->s.dmgFlags)
#define ENT_S_ANIMMOVETYPE(e)   (((gentity_t *)(e))->s.animMovetype)
#define ENT_S_INDEX(e)          (((gentity_t *)(e))->s.index)
#define ENT_R_SVFLAGS(e)        (((gentity_t *)(e))->r.svFlags)
#define ENT_R_ABSMIN(e)         (((gentity_t *)(e))->r.absmin)
#define ENT_R_ABSMAX(e)         (((gentity_t *)(e))->r.absmax)
#define ENT_R_CURORIGIN(e)      (((gentity_t *)(e))->r.currentOrigin)
#define ENT_CLIENT(e)           (((gentity_t *)(e))->client)
#define ENT_ACTIVE(e)           (((gentity_t *)(e))->active)
#define ENT_HANDLER(e)          (((gentity_t *)(e))->handler)
#define ENT_TEAM(e)             (((gentity_t *)(e))->team)
#define ENT_CLASSNAME(e)        (((gentity_t *)(e))->classname)
#define ENT_HEALTH(e)           (((gentity_t *)(e))->health)
#define ENT_ITEM_INDEX(e)       (((gentity_t *)(e))->item.index)
#define ENT_TRIGGER_SINGLEUSER(e) (((gentity_t *)(e))->trigger.singleUserEntIndex)

/* Typed playerState_t accessors. */
#define PS_PM_FLAGS(ps)         (((playerState_t *)(ps))->pm_flags)
#define PS_ORIGIN(ps)           (((playerState_t *)(ps))->origin)
#define PS_EFLAGS(ps)           (((playerState_t *)(ps))->eFlags)
#define PS_CLIENTNUM(ps)        (((playerState_t *)(ps))->clientNum)
#define PS_WEAPON(ps)           (((playerState_t *)(ps))->weapon)
#define PS_WEAPONSTATE(ps)      (((playerState_t *)(ps))->weaponstate)
#define PS_WEAPONS(ps)          (((playerState_t *)(ps))->weapons)
#define PS_MINS(ps)             (((playerState_t *)(ps))->mins)
#define PS_MAXS(ps)             (((playerState_t *)(ps))->maxs)
#define PS_VIEWLOCKED_ENTNUM(ps) (((playerState_t *)(ps))->viewlocked_entNum)
#define PS_CURSORHINT(ps)       (((playerState_t *)(ps))->cursorHint)
#define PS_CURSORHINTSTRING(ps) (((playerState_t *)(ps))->cursorHintString)
#define PS_CURSORHINTENTINDEX(ps) (((playerState_t *)(ps))->cursorHintEntIndex)

#define SCR_CONST()             ((const scr_const_t *)scr_const_ptr)

/* Typed gclient_t accessors. */
#define CLIENT_TEAM(c)          (((gclient_t *)(c))->sess.cs.team)
#define CLIENT_USE_ENTNUM(c)    (((gclient_t *)(c))->useHoldEntity)
#define CLIENT_USE_TIME(c)      (((gclient_t *)(c))->useHoldTime)
#define CLIENT_BUTTONS(c)       (((gclient_t *)(c))->buttons)
#define CLIENT_OLDBUTTONS(c)    (((gclient_t *)(c))->oldbuttons)
#define CLIENT_LATCHED_BUTTONS(c) (((gclient_t *)(c))->latched_buttons)
#define CLIENT_USE_HOLD_TIME(c) (((gclient_t *)(c))->lastSpawnTime) /* 0x28A0 in the binary */
#define CLIENT_LOOKAT_ENT(c)    (((gclient_t *)(c))->pLookatEnt)

/* line 150 */
void Player_UpdateActivate(gentity_t *ent)
{
    gclient_t *client;
    gentity_t *useEnt;
    entityHandler_t *handlers;
    fn_use useFn;
    fn_touch touchFn;
    int useEntNum;
    int levelTime;
    int pm_type;
    int eType;
    int activated;

    client = ent->client;

    /* Clear the +use flag from pm_flags */
    client->ps.pm_flags &= ~0x8;

    /* Check if player is in a special movement state (mantling, etc) */
    pm_type = client->ps.weaponstate;
    if ((unsigned)(pm_type - 0x11) <= 5)
        return;

    /* Check if use button was just pressed */
    if (CLIENT_USE_ENTNUM(client) != 0x3FF) {
        /* Already using something */
        if (!(CLIENT_OLDBUTTONS(client) & 0x20))
            goto check_activate;
        if (!(CLIENT_BUTTONS(client) & 0x20)) {
            /* Use button released - set flag */
            client->ps.pm_flags |= 0x8;
            return;
        }
    }

check_activate:
    /* Check for activate (use+attack) buttons */
    if (CLIENT_LATCHED_BUTTONS(client) & 0x28) {
        /* Activate button pressed */
        if (!Scr_IsSystemActive(1)) {
            client = ent->client;
            activated = 0;
            goto check_use_hold;
        }

        /* Clear use entity */
        CLIENT_USE_ENTNUM(ent->client) = 0x3FF;

        /* Check if entity has active hold state */
        if (ENT_ACTIVE(ent) != 0) {
            client = ent->client;
            if (client->ps.eFlags & 0x300) {
                /* In vehicle/turret - set active to 2 */
                ENT_ACTIVE(ent) = 2;
                activated = 1;
                goto check_use_hold;
            }
            /* Clear active flag */
            ENT_ACTIVE(ent) = 0;
            activated = 1;
            client = ent->client;
            goto check_use_hold;
        }

        /* Check if pm_flags has the flag indicating entity in use */
        client = ent->client;
        if (!(client->ps.pm_flags & 0x4)) {
            /* Check viewlocked entity */
            if (client->ps.cursorHintEntIndex == 0x3FF) {
                activated = 0;
                goto check_use_hold;
            }
            /* Set use entity and time */
            CLIENT_USE_ENTNUM(client) = client->ps.cursorHintEntIndex;
            client = ent->client;
            levelTime = ((level_locals_t *)level_ptr)->time;
            CLIENT_USE_TIME(client) = levelTime;
            activated = 1;
            client = ent->client;
            goto check_use_hold;
        }
        activated = 1;
        goto check_use_hold;
    }

    activated = 0;

check_use_hold:
    /* Check if use entity is still valid */
    if (CLIENT_USE_ENTNUM(client) == 0x3FF) {
        if (!activated) {
            if (CLIENT_LATCHED_BUTTONS(client) & 0x20) {
                /* Only the use button is latched */
                client->ps.pm_flags |= 0x8;
            }
            return;
        }
        /* activated but no use entity */
        goto check_held_use;
    }

check_held_use:
    /* Check held use button */
    if (!(CLIENT_BUTTONS(client) & 0x28))
        return;

    /* Check if scripting system is active */
    if (!Scr_IsSystemActive(1))
        return;

    client = ent->client;
    useEntNum = CLIENT_USE_ENTNUM(client);
    if (useEntNum == 0x3FF)
        return;

    /* Check hold time */
    levelTime = ((level_locals_t *)level_ptr)->time;
    if (levelTime - CLIENT_USE_HOLD_TIME(client) < g_useholdspawndelay->current.integer)
        return;

    /* Check reuse time */
    if (levelTime - CLIENT_USE_TIME(client) < g_useholdtime->current.integer)
        return;

    /* Get entity pointer for use entity */
    useEnt = GENTITY(useEntNum);

    /* Get entity handlers. */
    handlers = &entityHandlers[ENT_HANDLER(useEnt)];
    useFn = handlers->use;
    touchFn = handlers->touch;

    /* Check entity type */
    eType = ENT_S_ETYPE(useEnt);
    if (eType == 3) {
        /* ET_ITEM - touch notification */
        Scr_AddEntity(ent);
        Scr_Notify(useEnt, SCR_CONST()->touch, 1);
        ENT_ACTIVE(useEnt) = 1;
        if (touchFn) {
            touchFn(useEnt, ent, 0);
        }
    } else if (eType == 9) {
        /* ET_TURRET */
        if (!G_IsTurretUsable(useEnt, ent))
            goto finish_use;
        /* Fall through to trigger notification */
        goto send_trigger;
    } else {
send_trigger:
        /* Send trigger notification */
        Scr_AddEntity(ent);
        Scr_Notify(useEnt, SCR_CONST()->trigger, 1);
        if (useFn) {
            useFn(useEnt, ent, ent);
        }
    }

finish_use:
    /* Clear use entity */
    CLIENT_USE_ENTNUM(ent->client) = 0x3FF;
}

/* line 194 */
static int compare_use(const void *pe1, const void *pe2)
{
    const useList_t *a = (const useList_t *)pe1;
    const useList_t *b = (const useList_t *)pe2;
    return (int)(a->score - b->score);
}

/* line 206 */
static int Player_GetUseList(gentity_t *ent, useList_t *useList)
{
    playerState_t *ps;
    vec3_t origin;
    vec3_t forward;
    vec3_t playerMin, playerMax;
    vec3_t mins, maxs;
    vec3_t usePos, useDir;
    int touchEnts[1024];
    int num;
    int i;
    int useCount;
    int ignoredFullItems;
    int invalidUseCount;
    float dist;
    float dot;
    gentity_t *hitEnt;
    gentity_t *traceEnt;
    useList_t *curUse;

    ps = &ent->client->ps;

    /* Get player view origin and direction */
    G_GetPlayerViewOrigin(ent, origin);
    G_GetPlayerViewDirection(ent, forward, NULL, NULL);

    /* Compute player bounding box in world space */
    playerMin[0] = ps->origin[0] + ps->mins[0];
    playerMin[1] = ps->origin[1] + ps->mins[1];
    playerMin[2] = ps->origin[2] + ps->mins[2];

    playerMax[0] = ps->origin[0] + ps->maxs[0];
    playerMax[1] = ps->origin[1] + ps->maxs[1];
    playerMax[2] = ps->origin[2] + ps->maxs[2];

    /* Compute search area */
    mins[0] = origin[0] - 192.0f;
    mins[1] = origin[1] - 192.0f;
    mins[2] = origin[2] - 96.0f;
    maxs[0] = origin[0] + 192.0f;
    maxs[1] = origin[1] + 192.0f;
    maxs[2] = origin[2] + 96.0f;

    /* Find nearby entities */
    num = CM_AreaEntities(mins, maxs, touchEnts, 0x400, 0x200000);

    useCount = 0;
    ignoredFullItems = 0;

    if (num <= 0)
        goto sort_and_validate;

    curUse = useList;
    for (i = 0; i < num; i++) {
        hitEnt = GENTITY(touchEnts[i]);

        /* Skip self */
        if (hitEnt == ent)
            continue;

        /* Check if entity is usable: must be ET_ITEM or have SVF_USE flag */
        if (ENT_S_ETYPE(hitEnt) != 3) {
            if (!(ENT_R_SVFLAGS(hitEnt) & 0x20))
                continue;
        }

        /* Check classname against trigger_use_touch */
        if (ENT_CLASSNAME(hitEnt) == SCR_CONST()->trigger_use_touch) {
            /* Touch trigger - check AABB overlap */
            if (ENT_R_ABSMIN(hitEnt)[0] > playerMax[0])
                continue;
            if (playerMin[0] > ENT_R_ABSMAX(hitEnt)[0])
                continue;
            if (ENT_R_ABSMIN(hitEnt)[1] > playerMax[1])
                continue;
            if (playerMin[1] > ENT_R_ABSMAX(hitEnt)[1])
                continue;
            if (ENT_R_ABSMIN(hitEnt)[2] > playerMax[2])
                continue;
            if (playerMin[2] > ENT_R_ABSMAX(hitEnt)[2])
                continue;

            /* Full AABB contact test */
            if (!SV_EntityContact(playerMin, playerMax, hitEnt))
                continue;

            /* Add with very negative score (high priority) */
            curUse->score = -256.0f;
            curUse->ent = hitEnt;
            useCount++;
            curUse++;
            continue;
        }

        /* Non-touch trigger: compute center of entity */
        usePos[0] = (ENT_R_ABSMIN(hitEnt)[0] + ENT_R_ABSMAX(hitEnt)[0]) * 0.5f;
        usePos[1] = (ENT_R_ABSMIN(hitEnt)[1] + ENT_R_ABSMAX(hitEnt)[1]) * 0.5f;
        usePos[2] = (ENT_R_ABSMIN(hitEnt)[2] + ENT_R_ABSMAX(hitEnt)[2]) * 0.5f;

        /* Direction from player to entity center */
        useDir[0] = usePos[0] - origin[0];
        useDir[1] = usePos[1] - origin[1];
        useDir[2] = usePos[2] - origin[2];

        /* Normalize and get distance */
        dist = Vec3Normalize(useDir);
        if (dist > 128.0f)
            continue;

        /* Compute dot product with forward direction */
        dot = useDir[0] * forward[0] + useDir[1] * forward[1] + useDir[2] * forward[2];

        /* Score: weighted by angle to entity (lower = better) */
        /* (1.0 + dot) * -0.5 + 1.0 then * 256.0 */
        curUse->score = ((1.0f + dot) * -0.5f + 1.0f) * 256.0f;

        /* Check if it's a trigger_use (prefer over trigger_use_touch) */
        if (ENT_CLASSNAME(hitEnt) == SCR_CONST()->trigger_use) {
            curUse->score -= 256.0f;
        }

        /* Check if item can be grabbed */
        if (ENT_S_ETYPE(hitEnt) == 3) {
            if (!BG_CanItemBeGrabbed(&hitEnt->s, ps, 0)) {
                curUse->score += 10000.0f;
                ignoredFullItems++;
            }
        }

        /* Add to use list */
        curUse->ent = hitEnt;
        curUse->score += dist;
        useCount++;
        curUse++;
    }

sort_and_validate:
    /* Sort by score (primary sort) */
    qsort(useList, useCount - ignoredFullItems, sizeof(useList_t), compare_use);

    /* Validate entries with traces */
    if (useCount - ignoredFullItems > 0) {
        invalidUseCount = 0;
        for (i = 0; i < useCount - ignoredFullItems; i++) {
            traceEnt = useList[i].ent;

            /* Skip trigger_use_touch entities */
            if (ENT_CLASSNAME(traceEnt) == SCR_CONST()->trigger_use_touch)
                continue;

            /* Compute entity center for trace */
            usePos[0] = (ENT_R_ABSMIN(traceEnt)[0] + ENT_R_ABSMAX(traceEnt)[0]) * 0.5f;
            usePos[1] = (ENT_R_ABSMIN(traceEnt)[1] + ENT_R_ABSMAX(traceEnt)[1]) * 0.5f;
            usePos[2] = (ENT_R_ABSMIN(traceEnt)[2] + ENT_R_ABSMAX(traceEnt)[2]) * 0.5f;

            /* For turrets, use tag_aim position */
            if (ENT_S_ETYPE(traceEnt) == 9) {
                G_DObjGetWorldTagPos(traceEnt, SCR_CONST()->tag_aim, usePos);
            }

            /* Trace from origin to entity center */
            if (!G_TraceCapsuleComplete(origin, (vec_t *)vec3_origin_ptr, (vec_t *)vec3_origin_ptr, usePos, ps->clientNum, 0x11)) {
                /* Trace blocked - penalize score */
                useList[i].score += 10000.0f;
                invalidUseCount++;
            }
        }

        /* Re-sort after validation */
        qsort(useList, useCount - ignoredFullItems, sizeof(useList_t), compare_use);
        useCount -= ignoredFullItems;
        useCount -= invalidUseCount;
    } else {
        useCount -= ignoredFullItems;
    }

    return useCount;
}

/* line 428 */
void Player_UpdateCursorHints(gentity_t *ent)
{
    playerState_t *ps;
    gclient_t *client;
    gentity_t *traceEnt;
    gentity_t *turretEnt;
    gitem_t *itemEntry;
    useList_t useList[1024];
    int numUsable;
    int i;
    int hintType;
    int hintString;
    int weaponIndex;
    int team;
    WeaponDef *weapDef;

    ps = &ent->client->ps;

    /* Reset cursor hints */
    ps->cursorHint = 0;
    ps->cursorHintString = -1;
    ps->cursorHintEntIndex = 0x3FF;

    /* Check if entity is alive */
    if (ENT_HEALTH(ent) <= 0)
        return;

    /* Check movement state */
    client = ent->client;
    if ((unsigned)(client->ps.weaponstate - 0x11) <= 5)
        return;

    /* Check if entity has active hold state */
    if (ENT_ACTIVE(ent) != 0) {
        /* Active hold - check if in vehicle/turret */
        if (!(ps->eFlags & 0x300))
            return;

        /* Show turret weapon hint */
        turretEnt = GENTITY(ps->viewlocked_entNum);
        weaponIndex = ENT_S_WEAPON(turretEnt);
        weapDef = (WeaponDef *)BG_GetWeaponDef(weaponIndex);
        if (*(char *)weapDef->dropHintString == '\0')
            return;

        ps->cursorHintEntIndex = 0x3FF;
        ps->cursorHint = weaponIndex + 4;
        weapDef = (WeaponDef *)BG_GetWeaponDef(weaponIndex);
        ps->cursorHintString = weapDef->dropHintStringIndex;
        return;
    }

    /* Check if pm_flags indicate entity use */
    if (client->ps.pm_flags & 0x4)
        return;

    /* Get usable entities */
    numUsable = Player_GetUseList(ent, useList);
    if (numUsable <= 0)
        return;

    /* Iterate through usable entities */
    for (i = 0; i < numUsable; i++) {
        traceEnt = useList[i].ent;

        /* Check entity type */
        if (ENT_S_ETYPE(traceEnt) == 3) {
            /* ET_ITEM */
            client = ent->client;

            /* Check if player can pick up this item */
            weaponIndex = ENT_ITEM_INDEX(traceEnt);

            /* Compute item entry: index * 44 (sizeof gitem_s) + bg_itemlist base */
            itemEntry = (gitem_t *)(bg_itemlist_ptr + weaponIndex * 44);

            /* Check giType == 1 (IT_WEAPON) */
            if (itemEntry->giType != 1)
                continue;

            /* Check weapon class */
            weapDef = (WeaponDef *)BG_GetWeaponDef(itemEntry->giTag);
            if (weapDef->weapType == 1)
                continue;

            /* Check if player already has this weapon */
            weaponIndex = itemEntry->giTag;
            if ((client->ps.weapons[weaponIndex >> 5] >> (weaponIndex & 0x1F)) & 1)
                continue;

            /* Valid weapon pickup */
            hintType = weaponIndex + 4;
            if (hintType == 0)
                continue;
            hintString = -1;
        } else if (ENT_S_ETYPE(traceEnt) == 9) {
            /* ET_TURRET */
            if (!G_IsTurretUsable(traceEnt, ent))
                continue;

            weaponIndex = ENT_S_WEAPON(traceEnt);
            hintType = weaponIndex + 4;

            weapDef = (WeaponDef *)BG_GetWeaponDef(weaponIndex);
            if (*(char *)weapDef->szUseHintString != '\0') {
                weapDef = (WeaponDef *)BG_GetWeaponDef(ENT_S_WEAPON(traceEnt));
                hintString = weapDef->iUseHintStringIndex;
            } else {
                hintString = -1;
            }
        } else if (ENT_S_ETYPE(traceEnt) == 0) {
            /* ET_GENERAL - check classname */
            if (ENT_CLASSNAME(traceEnt) != SCR_CONST()->trigger_use &&
                ENT_CLASSNAME(traceEnt) != SCR_CONST()->trigger_use_touch) {
                /* Not a trigger_use or trigger_use_touch */
                hintType = 0;
                hintString = -1;
            } else {
                /* Check team hint */
                if (ENT_TEAM(traceEnt) == 0) {
                    /* No team restriction - check target entity */
                    if (ENT_TRIGGER_SINGLEUSER(traceEnt) == 0x3FF) {
                        /* No target entity - use traceEnt directly */
                    } else {
                        /* Has target entity - check clientNum matches */
                        if (ENT_TRIGGER_SINGLEUSER(traceEnt) != ent->client->ps.clientNum)
                            continue;
                    }

                    hintType = ENT_S_ANIMMOVETYPE(traceEnt);
                    if (hintType == 0) {
                        hintString = -1;
                    } else {
                        hintString = ENT_S_DMGFLAGS(traceEnt);
                        if (hintString == 0xFF)
                            hintString = -1;
                    }
                } else {
                    /* Has team restriction */
                    team = ENT_TEAM(traceEnt);
                    if (team != CLIENT_TEAM(ent->client)) {
                        /* Wrong team - check through target chain */
                        if (ENT_TRIGGER_SINGLEUSER(traceEnt) != 0x3FF &&
                            ENT_TRIGGER_SINGLEUSER(traceEnt) != ent->client->ps.clientNum)
                            continue;

                        hintType = ENT_S_ANIMMOVETYPE(traceEnt);
                        if (hintType == 0) {
                            hintString = -1;
                        } else {
                            hintString = ENT_S_DMGFLAGS(traceEnt);
                            if (hintString == 0xFF)
                                hintString = -1;
                        }
                    } else {
                        continue;
                    }
                }
            }
        } else {
            continue;
        }

        /* Set cursor hint */
        ps->cursorHintEntIndex = ENT_S_NUMBER(traceEnt);
        ps->cursorHint = hintType;
        ps->cursorHintString = hintString;

        if (hintType == 0) {
            ps->cursorHintEntIndex = 0x3FF;
        }
        return;
    }
}

/* line 562 */
void Player_UpdateLookAtEntity(gentity_t *ent)
{
    playerState_t *ps;
    gentity_t *hitEnt;
    gclient_t *hitClient;
    vec3_t start, end, forward;
    vec3_t contactEnd;
    trace_t trace;
    float vis;
    float scale;
    float distSq;
    float rangeSq;
    float dx, dy, dz;
    WeaponDef *weapDef;
    unsigned char *priorityMap;
    int traceEntNum;

    ps = &ent->client->ps;

    /* Clear look-at flags */
    ps->pm_flags &= ~0x300000;

    /* Clear look-at entity */
    CLIENT_LOOKAT_ENT(ent->client) = NULL;

    /* Get view origin and direction */
    G_GetPlayerViewOrigin(ent, start);
    G_GetPlayerViewDirection(ent, forward, NULL, NULL);

    /* Get weapon definition */
    if (ps->eFlags & 0x300) {
        /* In vehicle/turret */
        hitEnt = GENTITY(ps->viewlocked_entNum);
        weapDef = (WeaponDef *)BG_GetWeaponDef(ENT_S_WEAPON(hitEnt));
    } else {
        weapDef = (WeaponDef *)BG_GetWeaponDef(ps->weapon);
    }

    /* Check weapon and determine priority map */
    if (ps->weapon == 0 || !weapDef->bRifleBullet) {
        priorityMap = (unsigned char *)pPriorityMap;
    } else {
        priorityMap = (unsigned char *)pPriorityMapAlt;
    }

    /* Compute end point */
    end[0] = start[0] + forward[0] * 15000.0f;
    end[1] = start[1] + forward[1] * 15000.0f;
    end[2] = start[2] + forward[2] * 15000.0f;

    /* First trace */
    G_LocationalTrace(&trace, start, end, ent->s.number, 0x22802801, priorityMap);
    if (trace.entityNum > 0x3FD)
        return;

    /* Compute contact end point */
    scale = trace.fraction * 15000.0f;
    contactEnd[0] = start[0] + forward[0] * scale;
    contactEnd[1] = start[1] + forward[1] * scale;
    contactEnd[2] = start[2] + forward[2] * scale;

    /* Check visibility */
    vis = SV_FX_GetVisibility(start, contactEnd);
    if (!(vis >= 0.2f))
        return;

    /* Get trace entity */
    traceEntNum = trace.entityNum;
    hitEnt = GENTITY(traceEntNum);
    if (hitEnt == NULL)
        return;

    /* Check if it's a trigger_lookat entity */
    if (ENT_CLASSNAME(hitEnt) == SCR_CONST()->trigger_lookat) {
        /* Store look-at entity */
        CLIENT_LOOKAT_ENT(ent->client) = hitEnt;

        /* Trigger the entity */
        G_Trigger(hitEnt, ent);

        /* Second trace (past the trigger) */
        G_LocationalTrace(&trace, start, end, ent->s.number, 0x2802801, priorityMap);
        if (trace.entityNum > 0x3FD)
            return;

        scale = 15000.0f * trace.fraction;
        contactEnd[0] = start[0] + forward[0] * scale;
        contactEnd[1] = start[1] + forward[1] * scale;
        contactEnd[2] = start[2] + forward[2] * scale;

        vis = SV_FX_GetVisibility(start, contactEnd);
        if (vis < 0.2f)
            return;

        hitEnt = GENTITY(trace.entityNum);
        if (hitEnt == NULL)
            return;
    }

    /* Must be ET_PLAYER (eType == 1) */
    if (ENT_S_ETYPE(hitEnt) != 1)
        return;

    /* Check trace surface flags (not through glass/etc) */
    if (trace.surfaceFlags & 0x10)
        return;

    /* Compute direction to entity */
    dx = ENT_R_CURORIGIN(hitEnt)[0] - start[0];
    dy = ENT_R_CURORIGIN(hitEnt)[1] - start[1];
    dz = ENT_R_CURORIGIN(hitEnt)[2] - start[2];

    /* Check if same team */
    hitClient = ENT_CLIENT(hitEnt);
    if (CLIENT_TEAM(hitClient) == CLIENT_TEAM(ent->client) && CLIENT_TEAM(hitClient) != 0) {
        /* Same team - friendly */
        distSq = dx * dx + dy * dy + dz * dz;

        /* Check friendly look distance */
        rangeSq = g_friendlyNameDist->current.value;
        rangeSq *= rangeSq;
        if (rangeSq > distSq) {
            if (CLIENT_LOOKAT_ENT(ent->client) == NULL) {
                CLIENT_LOOKAT_ENT(ent->client) = hitEnt;
            }
        }

        /* Check enemy look distance (for cross-hair) */
        rangeSq = g_friendlyfireDist->current.value;
        rangeSq *= rangeSq;
        if (rangeSq > distSq) {
            ps->pm_flags |= 0x100000;
        }
        return;
    }

    /* Different team - enemy */
    distSq = dx * dx + dy * dy + dz * dz;
    rangeSq = weapDef->enemyCrosshairRange;
    rangeSq *= rangeSq;
    if (rangeSq <= distSq)
        return;

    if (CLIENT_LOOKAT_ENT(ent->client) == NULL) {
        CLIENT_LOOKAT_ENT(ent->client) = hitEnt;
    }
    ps->pm_flags |= 0x200000;
}
