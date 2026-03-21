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
extern byte *entityHandlers_ptr; /* imp_entityHandlers */
extern byte *vec3_origin_ptr;   /* imp_vec3_origin */
extern byte *bg_itemlist_ptr;   /* imp_bg_itemlist */
extern byte *g_useActivateHoldTime; /* imp_g_useholdspawndelay */
extern byte *g_useActivateReuseTime; /* imp_g_useholdtime */
extern byte *pPriorityMap;      /* imp_bulletPriorityMap */
extern byte *pPriorityMapAlt;   /* imp_riflePriorityMap */
extern byte *g_friendlylookDist; /* imp_g_friendlyNameDist */
extern byte *g_enemylookDist;   /* imp_g_friendlyfireDist */

/* Function declarations */
void Player_UpdateActivate(gentity_t *ent);
static int compare_use(const void *pe1, const void *pe2);
static int Player_GetUseList(gentity_t *ent, useList_t *useList);
void Player_UpdateCursorHints(gentity_t *ent);
void Player_UpdateLookAtEntity(gentity_t *ent);

/* Entity stride in binary */
#define GENTITY_SIZE 0x230

/* Entity byte pointer offsets (binary layout) */
#define ENT_S_NUMBER     0x00
#define ENT_S_ETYPE      0x04
#define ENT_S_WEAPON     0xC8
#define ENT_S_DMGFLAGS   0xD8
#define ENT_S_ANIMMOVETYPE 0xDC
#define ENT_S_INDEX      0x8C
#define ENT_R_SVFLAGS    0x11E
#define ENT_R_ABSMIN     0x120
#define ENT_R_ABSMAX     0x12C
#define ENT_R_CURORIGIN  0x138
#define ENT_CLIENT       0x158
#define ENT_ACTIVE       0x162
#define ENT_HANDLER      0x166
#define ENT_TEAM         0x167
#define ENT_CLASSNAME    0x168
#define ENT_HEALTH       0x194
#define ENT_ATTACHMODELS 0x1AC
#define ENT_ATTACHTAGS   0x1B4

/* Client/playerState byte pointer offsets (binary layout) */
#define PS_PM_FLAGS      0x0C
#define PS_ORIGIN        0x14
#define PS_EFLAGS        0xA0
#define PS_CLIENTNUM     0xCC
#define PS_WEAPON        0xD4
#define PS_WEAPONSTATE   0xD8
#define PS_WEAPONS       0x544
#define PS_MINS          0x56C
#define PS_MAXS          0x578
#define PS_VIEWLOCKED_ENTNUM 0x594
#define PS_CURSORHINT    0x598
#define PS_CURSORHINTSTRING 0x59C
#define PS_CURSORHINTENTINDEX 0x5A0

/* scr_const offsets */
#define SCR_TOUCH              0x52
#define SCR_TRIGGER            0x54
#define SCR_TRIGGER_USE        0x56
#define SCR_TRIGGER_USE_TOUCH  0x58
#define SCR_TRIGGER_LOOKAT     0x5C
#define SCR_TAG_AIM            0x9E

/* Deep client offsets */
#define CLIENT_TEAM           0x274C
#define CLIENT_USE_ENTNUM     0x2830
#define CLIENT_USE_TIME       0x2834
#define CLIENT_BUTTONS        0x27BC
#define CLIENT_OLDBUTTONS     0x27C0
#define CLIENT_LATCHED_BUTTONS 0x27C4
#define CLIENT_USE_HOLD_TIME  0x28A0
#define CLIENT_LOOKAT_ENT     0x282C

/* line 150 */
void Player_UpdateActivate(gentity_t *ent)
{
    byte *client;
    byte *useEnt;
    entityHandler_t *handlers;
    fn_use useFn;
    fn_touch touchFn;
    int useEntNum;
    int levelTime;
    int pm_type;
    int eType;
    int activated;

    client = (byte *)ent->client;

    /* Clear the +use flag from pm_flags */
    *(int *)(client + PS_PM_FLAGS) &= ~0x8;

    /* Check if player is in a special movement state (mantling, etc) */
    pm_type = *(int *)(client + PS_WEAPONSTATE);
    if ((unsigned)(pm_type - 0x11) <= 5)
        return;

    /* Check if use button was just pressed */
    if (*(int *)(client + CLIENT_USE_ENTNUM) != 0x3FF) {
        /* Already using something */
        if (!(*(byte *)(client + CLIENT_OLDBUTTONS) & 0x20))
            goto check_activate;
        if (!(*(byte *)(client + CLIENT_BUTTONS) & 0x20)) {
            /* Use button released - set flag */
            *(int *)(client + PS_PM_FLAGS) |= 0x8;
            return;
        }
    }

check_activate:
    /* Check for activate (use+attack) buttons */
    if (*(byte *)(client + CLIENT_LATCHED_BUTTONS) & 0x28) {
        /* Activate button pressed */
        if (!Scr_IsSystemActive(1)) {
            client = (byte *)ent->client;
            activated = 0;
            goto check_use_hold;
        }

        /* Clear use entity */
        *(int *)((byte *)ent->client + CLIENT_USE_ENTNUM) = 0x3FF;

        /* Check if entity has active hold state */
        if (*(byte *)((byte *)ent + ENT_ACTIVE) != 0) {
            client = (byte *)ent->client;
            if (*(int *)(client + PS_EFLAGS) & 0x300) {
                /* In vehicle/turret - set active to 2 */
                *(byte *)((byte *)ent + ENT_ACTIVE) = 2;
                activated = 1;
                goto check_use_hold;
            }
            /* Clear active flag */
            *(byte *)((byte *)ent + ENT_ACTIVE) = 0;
            activated = 1;
            client = (byte *)ent->client;
            goto check_use_hold;
        }

        /* Check if pm_flags has the flag indicating entity in use */
        client = (byte *)ent->client;
        if (!(*(int *)(client + PS_PM_FLAGS) & 0x4)) {
            /* Check viewlocked entity */
            if (*(int *)(client + PS_CURSORHINTENTINDEX) == 0x3FF) {
                activated = 0;
                goto check_use_hold;
            }
            /* Set use entity and time */
            *(int *)(client + CLIENT_USE_ENTNUM) = *(int *)(client + PS_CURSORHINTENTINDEX);
            client = (byte *)ent->client;
            levelTime = ((level_locals_t *)level_ptr)->time;
            *(int *)(client + CLIENT_USE_TIME) = levelTime;
            activated = 1;
            client = (byte *)ent->client;
            goto check_use_hold;
        }
        activated = 1;
        goto check_use_hold;
    }

    activated = 0;

check_use_hold:
    /* Check if use entity is still valid */
    if (*(int *)(client + CLIENT_USE_ENTNUM) == 0x3FF) {
        if (!activated) {
            if (*(byte *)(client + CLIENT_LATCHED_BUTTONS) & 0x20) {
                /* Only the use button is latched */
                *(int *)(client + PS_PM_FLAGS) |= 0x8;
            }
            return;
        }
        /* activated but no use entity */
        goto check_held_use;
    }

check_held_use:
    /* Check held use button */
    if (!(*(byte *)(client + CLIENT_BUTTONS) & 0x28))
        return;

    /* Check if scripting system is active */
    if (!Scr_IsSystemActive(1))
        return;

    client = (byte *)ent->client;
    useEntNum = *(int *)(client + CLIENT_USE_ENTNUM);
    if (useEntNum == 0x3FF)
        return;

    /* Check hold time */
    levelTime = ((level_locals_t *)level_ptr)->time;
    if (levelTime - *(int *)(client + CLIENT_USE_HOLD_TIME) < *(int *)(*(byte **)&g_useActivateHoldTime + 8))
        return;

    /* Check reuse time */
    if (levelTime - *(int *)(client + CLIENT_USE_TIME) < *(int *)(*(byte **)&g_useActivateReuseTime + 8))
        return;

    /* Get entity pointer for use entity */
    useEnt = g_entities_ptr + useEntNum * GENTITY_SIZE;

    /* Get entity handlers */
    handlers = (entityHandler_t *)(entityHandlers_ptr + *(byte *)(useEnt + ENT_HANDLER) * sizeof(entityHandler_t));
    useFn = handlers->use;
    touchFn = handlers->touch;

    /* Check entity type */
    eType = *(int *)(useEnt + ENT_S_ETYPE);
    if (eType == 3) {
        /* ET_ITEM - touch notification */
        Scr_AddEntity(ent);
        Scr_Notify((gentity_t *)useEnt, *(unsigned short *)(scr_const_ptr + SCR_TOUCH), 1);
        *(byte *)(useEnt + ENT_ACTIVE) = 1;
        if (touchFn) {
            touchFn((gentity_t *)useEnt, ent, 0);
        }
    } else if (eType == 9) {
        /* ET_TURRET */
        if (!G_IsTurretUsable((gentity_t *)useEnt, ent))
            goto finish_use;
        /* Fall through to trigger notification */
        goto send_trigger;
    } else {
send_trigger:
        /* Send trigger notification */
        Scr_AddEntity(ent);
        Scr_Notify((gentity_t *)useEnt, *(unsigned short *)(scr_const_ptr + SCR_TRIGGER), 1);
        if (useFn) {
            useFn((gentity_t *)useEnt, ent, ent);
        }
    }

finish_use:
    /* Clear use entity */
    *(int *)((byte *)ent->client + CLIENT_USE_ENTNUM) = 0x3FF;
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
    byte *ps;
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
    byte *hitEnt;
    byte *traceEnt;
    useList_t *curUse;

    ps = (byte *)ent->client;

    /* Get player view origin and direction */
    G_GetPlayerViewOrigin(ent, origin);
    G_GetPlayerViewDirection(ent, forward, NULL, NULL);

    /* Compute player bounding box in world space */
    playerMin[0] = *(float *)(ps + PS_ORIGIN) + *(float *)(ps + PS_MINS);
    playerMin[1] = *(float *)(ps + PS_ORIGIN + 4) + *(float *)(ps + PS_MINS + 4);
    playerMin[2] = *(float *)(ps + PS_ORIGIN + 8) + *(float *)(ps + PS_MINS + 8);

    playerMax[0] = *(float *)(ps + PS_ORIGIN) + *(float *)(ps + PS_MAXS);
    playerMax[1] = *(float *)(ps + PS_ORIGIN + 4) + *(float *)(ps + PS_MAXS + 4);
    playerMax[2] = *(float *)(ps + PS_ORIGIN + 8) + *(float *)(ps + PS_MAXS + 8);

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
        hitEnt = g_entities_ptr + touchEnts[i] * GENTITY_SIZE;

        /* Skip self */
        if ((gentity_t *)hitEnt == ent)
            continue;

        /* Check if entity is usable: must be ET_ITEM or have SVF_USE flag */
        if (*(int *)(hitEnt + ENT_S_ETYPE) != 3) {
            if (!(*(byte *)(hitEnt + ENT_R_SVFLAGS) & 0x20))
                continue;
        }

        /* Check classname against trigger_use_touch */
        if (*(unsigned short *)(hitEnt + ENT_CLASSNAME) == *(unsigned short *)(scr_const_ptr + SCR_TRIGGER_USE_TOUCH)) {
            /* Touch trigger - check AABB overlap */
            if (*(float *)(hitEnt + ENT_R_ABSMIN) > playerMax[0])
                continue;
            if (playerMin[0] > *(float *)(hitEnt + ENT_R_ABSMAX))
                continue;
            if (*(float *)(hitEnt + ENT_R_ABSMIN + 4) > playerMax[1])
                continue;
            if (playerMin[1] > *(float *)(hitEnt + ENT_R_ABSMAX + 4))
                continue;
            if (*(float *)(hitEnt + ENT_R_ABSMIN + 8) > playerMax[2])
                continue;
            if (playerMin[2] > *(float *)(hitEnt + ENT_R_ABSMAX + 8))
                continue;

            /* Full AABB contact test */
            if (!SV_EntityContact(playerMin, playerMax, (gentity_t *)hitEnt))
                continue;

            /* Add with very negative score (high priority) */
            curUse->score = -256.0f;
            curUse->ent = (gentity_t *)hitEnt;
            useCount++;
            curUse++;
            continue;
        }

        /* Non-touch trigger: compute center of entity */
        usePos[0] = (*(float *)(hitEnt + ENT_R_ABSMIN) + *(float *)(hitEnt + ENT_R_ABSMAX)) * 0.5f;
        usePos[1] = (*(float *)(hitEnt + ENT_R_ABSMIN + 4) + *(float *)(hitEnt + ENT_R_ABSMAX + 4)) * 0.5f;
        usePos[2] = (*(float *)(hitEnt + ENT_R_ABSMIN + 8) + *(float *)(hitEnt + ENT_R_ABSMAX + 8)) * 0.5f;

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
        if (*(unsigned short *)(hitEnt + ENT_CLASSNAME) == *(unsigned short *)(scr_const_ptr + SCR_TRIGGER_USE)) {
            curUse->score -= 256.0f;
        }

        /* Check if item can be grabbed */
        if (*(int *)(hitEnt + ENT_S_ETYPE) == 3) {
            if (!BG_CanItemBeGrabbed((entityState_t *)hitEnt, (playerState_t *)ps, 0)) {
                curUse->score += 10000.0f;
                ignoredFullItems++;
            }
        }

        /* Add to use list */
        curUse->ent = (gentity_t *)hitEnt;
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
            traceEnt = (byte *)useList[i].ent;

            /* Skip trigger_use_touch entities */
            if (*(unsigned short *)(traceEnt + ENT_CLASSNAME) == *(unsigned short *)(scr_const_ptr + SCR_TRIGGER_USE_TOUCH))
                continue;

            /* Compute entity center for trace */
            usePos[0] = (*(float *)(traceEnt + ENT_R_ABSMIN) + *(float *)(traceEnt + ENT_R_ABSMAX)) * 0.5f;
            usePos[1] = (*(float *)(traceEnt + ENT_R_ABSMIN + 4) + *(float *)(traceEnt + ENT_R_ABSMAX + 4)) * 0.5f;
            usePos[2] = (*(float *)(traceEnt + ENT_R_ABSMIN + 8) + *(float *)(traceEnt + ENT_R_ABSMAX + 8)) * 0.5f;

            /* For turrets, use tag_aim position */
            if (*(int *)(traceEnt + ENT_S_ETYPE) == 9) {
                G_DObjGetWorldTagPos((gentity_t *)traceEnt, *(unsigned short *)(scr_const_ptr + SCR_TAG_AIM), usePos);
            }

            /* Trace from origin to entity center */
            if (!G_TraceCapsuleComplete(origin, (vec_t *)vec3_origin_ptr, (vec_t *)vec3_origin_ptr, usePos, *(int *)(ps + PS_CLIENTNUM), 0x11)) {
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
    byte *ps;
    byte *client;
    byte *traceEnt;
    byte *turretEnt;
    byte *itemEntry;
    useList_t useList[1024];
    int numUsable;
    int i;
    int hintType;
    int hintString;
    int weaponIndex;
    int team;
    WeaponDef *weapDef;

    ps = (byte *)ent->client;

    /* Reset cursor hints */
    *(int *)(ps + PS_CURSORHINT) = 0;
    *(int *)(ps + PS_CURSORHINTSTRING) = -1;
    *(int *)(ps + PS_CURSORHINTENTINDEX) = 0x3FF;

    /* Check if entity is alive */
    if (*(int *)((byte *)ent + ENT_HEALTH) <= 0)
        return;

    /* Check movement state */
    client = (byte *)ent->client;
    if ((unsigned)(*(int *)(client + PS_WEAPONSTATE) - 0x11) <= 5)
        return;

    /* Check if entity has active hold state */
    if (*(byte *)((byte *)ent + ENT_ACTIVE) != 0) {
        /* Active hold - check if in vehicle/turret */
        if (!(*(int *)(ps + PS_EFLAGS) & 0x300))
            return;

        /* Show turret weapon hint */
        turretEnt = g_entities_ptr + *(int *)(client + PS_VIEWLOCKED_ENTNUM) * GENTITY_SIZE;
        weaponIndex = *(int *)(turretEnt + ENT_S_WEAPON);
        weapDef = (WeaponDef *)BG_GetWeaponDef(weaponIndex);
        if (*(char *)weapDef->dropHintString == '\0')
            return;

        *(int *)(client + PS_CURSORHINTENTINDEX) = 0x3FF;
        *(int *)(client + PS_CURSORHINT) = weaponIndex + 4;
        weapDef = (WeaponDef *)BG_GetWeaponDef(weaponIndex);
        *(int *)(client + PS_CURSORHINTSTRING) = weapDef->dropHintStringIndex;
        return;
    }

    /* Check if pm_flags indicate entity use */
    if (*(int *)(client + PS_PM_FLAGS) & 0x4)
        return;

    /* Get usable entities */
    numUsable = Player_GetUseList(ent, useList);
    if (numUsable <= 0)
        return;

    /* Iterate through usable entities */
    for (i = 0; i < numUsable; i++) {
        traceEnt = (byte *)useList[i].ent;

        /* Check entity type */
        if (*(int *)(traceEnt + ENT_S_ETYPE) == 3) {
            /* ET_ITEM */
            client = (byte *)ent->client;

            /* Check if player can pick up this item */
            weaponIndex = *(unsigned short *)(traceEnt + ENT_ATTACHMODELS);

            /* Compute item entry: index * 44 (sizeof gitem_s) + bg_itemlist base */
            itemEntry = bg_itemlist_ptr + weaponIndex * 44;

            /* Check giType == 1 (IT_WEAPON) */
            if (((gitem_t *)itemEntry)->giType != 1)
                continue;

            /* Check weapon class */
            weapDef = (WeaponDef *)BG_GetWeaponDef(((gitem_t *)itemEntry)->giTag);
            if (weapDef->weapType == 1)
                continue;

            /* Check if player already has this weapon */
            weaponIndex = ((gitem_t *)itemEntry)->giTag;
            if ((*(int *)(client + PS_WEAPONS + (weaponIndex >> 5) * 4) >> (weaponIndex & 0x1F)) & 1)
                continue;

            /* Valid weapon pickup */
            hintType = weaponIndex + 4;
            if (hintType == 0)
                continue;
            hintString = -1;
        } else if (*(int *)(traceEnt + ENT_S_ETYPE) == 9) {
            /* ET_TURRET */
            if (!G_IsTurretUsable((gentity_t *)traceEnt, ent))
                continue;

            weaponIndex = *(int *)(traceEnt + ENT_S_WEAPON);
            hintType = weaponIndex + 4;

            weapDef = (WeaponDef *)BG_GetWeaponDef(weaponIndex);
            if (*(char *)weapDef->szUseHintString != '\0') {
                weapDef = (WeaponDef *)BG_GetWeaponDef(*(int *)(traceEnt + ENT_S_WEAPON));
                hintString = weapDef->iUseHintStringIndex;
            } else {
                hintString = -1;
            }
        } else if (*(int *)(traceEnt + ENT_S_ETYPE) == 0) {
            /* ET_GENERAL - check classname */
            if (*(unsigned short *)(traceEnt + ENT_CLASSNAME) != *(unsigned short *)(scr_const_ptr + SCR_TRIGGER_USE) &&
                *(unsigned short *)(traceEnt + ENT_CLASSNAME) != *(unsigned short *)(scr_const_ptr + SCR_TRIGGER_USE_TOUCH)) {
                /* Not a trigger_use or trigger_use_touch */
                hintType = 0;
                hintString = -1;
            } else {
                /* Check team hint */
                if (*(byte *)(traceEnt + ENT_TEAM) == 0) {
                    /* No team restriction - check target entity */
                    if (*(int *)(traceEnt + ENT_ATTACHTAGS) == 0x3FF) {
                        /* No target entity - use traceEnt directly */
                        traceEnt = traceEnt;
                    } else {
                        /* Has target entity - check clientNum matches */
                        if (*(int *)(traceEnt + ENT_ATTACHTAGS) != *(int *)((byte *)ent->client + PS_CLIENTNUM))
                            continue;
                    }

                    hintType = *(int *)(traceEnt + ENT_S_ANIMMOVETYPE);
                    if (hintType == 0) {
                        hintString = -1;
                    } else {
                        hintString = *(int *)(traceEnt + ENT_S_DMGFLAGS);
                        if (hintString == 0xFF)
                            hintString = -1;
                    }
                } else {
                    /* Has team restriction */
                    team = *(byte *)(traceEnt + ENT_TEAM);
                    if (team != *(int *)((byte *)ent->client + CLIENT_TEAM)) {
                        /* Wrong team - check through target chain */
                        if (*(int *)(traceEnt + ENT_ATTACHTAGS) == 0x3FF) {
                            traceEnt = traceEnt;
                        } else {
                            if (*(int *)(traceEnt + ENT_ATTACHTAGS) != *(int *)((byte *)ent->client + PS_CLIENTNUM))
                                continue;
                        }

                        hintType = *(int *)(traceEnt + ENT_S_ANIMMOVETYPE);
                        if (hintType == 0) {
                            hintString = -1;
                        } else {
                            hintString = *(int *)(traceEnt + ENT_S_DMGFLAGS);
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
        *(int *)(ps + PS_CURSORHINTENTINDEX) = *(int *)(traceEnt + ENT_S_NUMBER);
        *(int *)(ps + PS_CURSORHINT) = hintType;
        *(int *)(ps + PS_CURSORHINTSTRING) = hintString;

        if (hintType == 0) {
            *(int *)(ps + PS_CURSORHINTENTINDEX) = 0x3FF;
        }
        return;
    }
}

/* line 562 */
void Player_UpdateLookAtEntity(gentity_t *ent)
{
    byte *ps;
    byte *hitEnt;
    byte *hitClient;
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

    ps = (byte *)ent->client;

    /* Clear look-at flags */
    *(int *)(ps + PS_PM_FLAGS) &= ~0x300000;

    /* Clear look-at entity */
    *(int *)((byte *)ent->client + CLIENT_LOOKAT_ENT) = 0;

    /* Get view origin and direction */
    G_GetPlayerViewOrigin(ent, start);
    G_GetPlayerViewDirection(ent, forward, NULL, NULL);

    /* Get weapon definition */
    if (*(int *)(ps + PS_EFLAGS) & 0x300) {
        /* In vehicle/turret */
        hitEnt = g_entities_ptr + *(int *)(ps + PS_VIEWLOCKED_ENTNUM) * GENTITY_SIZE;
        weapDef = (WeaponDef *)BG_GetWeaponDef(*(int *)(hitEnt + ENT_S_WEAPON));
    } else {
        weapDef = (WeaponDef *)BG_GetWeaponDef(*(int *)((byte *)ent->client + PS_WEAPON));
    }

    /* Check weapon and determine priority map */
    if (*(int *)((byte *)ent->client + PS_WEAPON) == 0 || !weapDef->bRifleBullet) {
        priorityMap = (unsigned char *)pPriorityMap;
    } else {
        priorityMap = (unsigned char *)pPriorityMapAlt;
    }

    /* Compute end point */
    end[0] = start[0] + forward[0] * 15000.0f;
    end[1] = start[1] + forward[1] * 15000.0f;
    end[2] = start[2] + forward[2] * 15000.0f;

    /* First trace */
    G_LocationalTrace(&trace, start, end, *(int *)((byte *)ent), 0x22802801, priorityMap);
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
    hitEnt = g_entities_ptr + traceEntNum * GENTITY_SIZE;
    if (hitEnt == NULL)
        return;

    /* Check if it's a trigger_lookat entity */
    if (*(unsigned short *)(hitEnt + ENT_CLASSNAME) == *(unsigned short *)(scr_const_ptr + SCR_TRIGGER_LOOKAT)) {
        /* Store look-at entity */
        *(int *)((byte *)ent->client + CLIENT_LOOKAT_ENT) = (int)(hitEnt);

        /* Trigger the entity */
        G_Trigger((gentity_t *)hitEnt, ent);

        /* Second trace (past the trigger) */
        G_LocationalTrace(&trace, start, end, *(int *)((byte *)ent), 0x2802801, priorityMap);
        if (trace.entityNum > 0x3FD)
            return;

        scale = 15000.0f * trace.fraction;
        contactEnd[0] = start[0] + forward[0] * scale;
        contactEnd[1] = start[1] + forward[1] * scale;
        contactEnd[2] = start[2] + forward[2] * scale;

        vis = SV_FX_GetVisibility(start, contactEnd);
        if (vis < 0.2f)
            return;

        hitEnt = g_entities_ptr + trace.entityNum * GENTITY_SIZE;
        if (hitEnt == NULL)
            return;
    }

    /* Must be ET_PLAYER (eType == 1) */
    if (*(int *)(hitEnt + ENT_S_ETYPE) != 1)
        return;

    /* Check trace surface flags (not through glass/etc) */
    if (trace.surfaceFlags & 0x10)
        return;

    /* Compute direction to entity */
    dx = *(float *)(hitEnt + ENT_R_CURORIGIN) - start[0];
    dy = *(float *)(hitEnt + ENT_R_CURORIGIN + 4) - start[1];
    dz = *(float *)(hitEnt + ENT_R_CURORIGIN + 8) - start[2];

    /* Check if same team */
    hitClient = *(byte **)(hitEnt + ENT_CLIENT);
    if (*(int *)(hitClient + CLIENT_TEAM) == *(int *)((byte *)ent->client + CLIENT_TEAM) && *(int *)(hitClient + CLIENT_TEAM) != 0) {
        /* Same team - friendly */
        distSq = dx * dx + dy * dy + dz * dz;

        /* Check friendly look distance */
        rangeSq = *(float *)(*(byte **)&g_friendlylookDist + 8);
        rangeSq *= rangeSq;
        if (rangeSq > distSq) {
            if (*(int *)((byte *)ent->client + CLIENT_LOOKAT_ENT) == 0) {
                *(int *)((byte *)ent->client + CLIENT_LOOKAT_ENT) = (int)hitEnt;
            }
        }

        /* Check enemy look distance (for cross-hair) */
        rangeSq = *(float *)(*(byte **)&g_enemylookDist + 8);
        rangeSq *= rangeSq;
        if (rangeSq > distSq) {
            *(int *)(ps + PS_PM_FLAGS) |= 0x100000;
        }
        return;
    }

    /* Different team - enemy */
    distSq = dx * dx + dy * dy + dz * dz;
    rangeSq = weapDef->enemyCrosshairRange;
    rangeSq *= rangeSq;
    if (rangeSq <= distSq)
        return;

    if (*(int *)((byte *)ent->client + CLIENT_LOOKAT_ENT) == 0) {
        *(int *)((byte *)ent->client + CLIENT_LOOKAT_ENT) = (int)hitEnt;
    }
    *(int *)(ps + PS_PM_FLAGS) |= 0x200000;
}
