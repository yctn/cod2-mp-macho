/* ASM dump from: bg_animation_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_animation_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 */

extern bgs_t *bgs; /* 0x0 */
static animScriptData_t *globalScriptData; /* globalScriptData */
static int numDefines[9]; /* numDefines */
static char defineStrings[10000]; /* defineStrings */
static int defineStringsOffset; /* defineStringsOffset */
static animStringItem_t defineStr[9][16]; /* defineStr */
static int defineBits[9][16][2]; /* defineBits */
static scriptAnimMoveTypes_t parseMovetype; /* parseMovetype */
static int parseEvent; /* parseEvent */
static loadAnim_t *g_pLoadAnims; /* g_pLoadAnims */
static int *g_piNumLoadAnims; /* g_piNumLoadAnims */
static char input[100000]; /* input */
static qboolean bScriptFileLoaded; /* bScriptFileLoaded */
extern animStringItem_t weaponStrings[]; /* weaponStrings — bss.c (NOT static, animConditionsTable points to global) */
extern scr_const_t scr_const;
extern const char "MG42"[], "PAIN"[], "DEATH"[], "FIREWEAPON"[], "JUMP"[], "JUMPBK"[];
extern const char "LAND"[], "DROPWEAPON"[], "RAISEWEAPON"[], "CLIMBMOUNT"[], "CLIMBDISMOUNT"[], "RELOAD"[];
extern const char "CROUCH_TO_PRONE"[], "PRONE_TO_CROUCH"[], "STAND_TO_CROUCH"[], "CROUCH_TO_STAND"[], "STAND_TO_PRONE"[], "PRONE_TO_STAND"[];
extern const char "MELEEATTACK"[], "SHELLSHOCK"[], "** UNUSED **"[], "IDLE"[], "IDLECR"[], "IDLEPRONE"[];
extern const char "WALK"[], "WALKBK"[], "WALKCR"[], "WALKCRBK"[], "WALKPRONE"[], "WALKPRONEBK"[];
extern const char "RUN"[], "RUNBK"[], "RUNCR"[], "RUNCRBK"[], "TURNRIGHT"[], "TURNLEFT"[];
extern const char "TURNRIGHTCR"[], "TURNLEFTCR"[], "CLIMBUP"[], "CLIMBDOWN"[], "MANTLE_ROOT"[], "MANTLE_UP_57"[];
extern const char "MANTLE_UP_51"[], "MANTLE_UP_45"[], "MANTLE_UP_39"[], "MANTLE_UP_33"[], "MANTLE_UP_27"[], "MANTLE_UP_21"[];
extern const char "MANTLE_OVER_HIGH"[], "MANTLE_OVER_MID"[], "MANTLE_OVER_LOW"[], "FLINCH_FORWARD"[], "FLINCH_BACKWARD"[], "FLINCH_LEFT"[];
extern const char "FLINCH_RIGHT"[], "STUMBLE_FORWARD"[], "STUMBLE_BACKWARD"[], "STUMBLE_WALK_FORWARD"[], "STUMBLE_WALK_BACKWARD"[], "STUMBLE_CROUCH_FORWARD"[];
extern const char "STUMBLE_CROUCH_BACKWARD"[], "RELAXED"[], "QUERY"[], "ALERT"[], "COMBAT"[], "NOT"[];
extern const char "LEFT"[], "RIGHT"[], "HIP"[], "ADS"[], "RIFLE"[], "MG"[];
extern const char "SMG"[], "SPREAD"[], "PISTOL"[], "GRENADE"[], "ROCKETLAUNCHER"[], "TURRET"[];
extern const char "NON-PLAYER"[], "ITEM"[], "PLAYERANIMTYPE"[], "WEAPONCLASS"[], "MOUNTED"[], "MOVETYPE"[];
extern const char "UNDERHAND"[], "CROUCHING"[], "FIRING"[], "WEAPON_POSITION"[], "STRAFING"[], "defines"[];
extern const char "animations"[], "canned_animations"[], "statechanges"[], "events"[], "mp/playeranim.script"[], "LEGS"[];
extern const char "TORSO"[], "BOTH"[];

typedef struct {
    UInt32 string;
    int hash;
} animStringItemRaw_t;

typedef struct {
    int type;
    UInt32 values;
} animConditionTableRaw_t;

__attribute__((used, aligned(4)))
animStringItemRaw_t animStateStr[8] = {
    {"RELAXED", 0xffffffff}, {"QUERY", 0xffffffff},
    {"ALERT", 0xffffffff}, {"COMBAT", 0xffffffff},
    {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x312f20 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animMoveTypesStr[44] = {
    {"** UNUSED **", 0xffffffff}, {"IDLE", 0xffffffff}, {"IDLECR", 0xffffffff}, {"IDLEPRONE", 0xffffffff},
    {"WALK", 0xffffffff}, {"WALKBK", 0xffffffff}, {"WALKCR", 0xffffffff}, {"WALKCRBK", 0xffffffff},
    {"WALKPRONE", 0xffffffff}, {"WALKPRONEBK", 0xffffffff}, {"RUN", 0xffffffff}, {"RUNBK", 0xffffffff},
    {"RUNCR", 0xffffffff}, {"RUNCRBK", 0xffffffff}, {"TURNRIGHT", 0xffffffff}, {"TURNLEFT", 0xffffffff},
    {"TURNRIGHTCR", 0xffffffff}, {"TURNLEFTCR", 0xffffffff}, {"CLIMBUP", 0xffffffff}, {"CLIMBDOWN", 0xffffffff},
    {"MANTLE_ROOT", 0xffffffff}, {"MANTLE_UP_57", 0xffffffff}, {"MANTLE_UP_51", 0xffffffff}, {"MANTLE_UP_45", 0xffffffff},
    {"MANTLE_UP_39", 0xffffffff}, {"MANTLE_UP_33", 0xffffffff}, {"MANTLE_UP_27", 0xffffffff}, {"MANTLE_UP_21", 0xffffffff},
    {"MANTLE_OVER_HIGH", 0xffffffff}, {"MANTLE_OVER_MID", 0xffffffff}, {"MANTLE_OVER_LOW", 0xffffffff}, {"FLINCH_FORWARD", 0xffffffff},
    {"FLINCH_BACKWARD", 0xffffffff}, {"FLINCH_LEFT", 0xffffffff}, {"FLINCH_RIGHT", 0xffffffff}, {"STUMBLE_FORWARD", 0xffffffff},
    {"STUMBLE_BACKWARD", 0xffffffff}, {"STUMBLE_WALK_FORWARD", 0xffffffff}, {"STUMBLE_WALK_BACKWARD", 0xffffffff}, {"STUMBLE_CROUCH_FORWARD", 0xffffffff},
    {"STUMBLE_CROUCH_BACKWARD", 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x312dc0 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animEventTypesStr[20] = {
    {"PAIN", 0xffffffff}, {"DEATH", 0xffffffff}, {"FIREWEAPON", 0xffffffff}, {"JUMP", 0xffffffff},
    {"JUMPBK", 0xffffffff}, {"LAND", 0xffffffff}, {"DROPWEAPON", 0xffffffff}, {"RAISEWEAPON", 0xffffffff},
    {"CLIMBMOUNT", 0xffffffff}, {"CLIMBDISMOUNT", 0xffffffff}, {"RELOAD", 0xffffffff}, {"CROUCH_TO_PRONE", 0xffffffff},
    {"PRONE_TO_CROUCH", 0xffffffff}, {"STAND_TO_CROUCH", 0xffffffff}, {"CROUCH_TO_STAND", 0xffffffff}, {"STAND_TO_PRONE", 0xffffffff},
    {"PRONE_TO_STAND", 0xffffffff}, {"MELEEATTACK", 0xffffffff}, {"SHELLSHOCK", 0xffffffff}, {0, 0xffffffff},
}; /* 0x312d20 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animBodyPartsStr[8] = {
    {"** UNUSED **", 0xffffffff}, {"LEGS", 0xffffffff}, {"TORSO", 0xffffffff}, {"BOTH", 0xffffffff},
    {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x313140 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animConditionMountedStr[5] = {
    {"** UNUSED **", 0xffffffff}, {"MG42", 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000},
    {0, 0x00000000},
}; /* 0x312ff8 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animWeaponClassStr[12] = {
    {"RIFLE", 0xffffffff}, {"MG", 0xffffffff}, {"SMG", 0xffffffff}, {"SPREAD", 0xffffffff},
    {"PISTOL", 0xffffffff}, {"GRENADE", 0xffffffff}, {"ROCKETLAUNCHER", 0xffffffff}, {"TURRET", 0xffffffff},
    {"NON-PLAYER", 0xffffffff}, {"ITEM", 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000},
}; /* 0x313020 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animWeaponPositionStr[3] = {
    {"HIP", 0xffffffff}, {"ADS", 0xffffffff}, {0, 0xffffffff},
}; /* 0x312fe0 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animStrafeStateStr[4] = {
    {"NOT", 0xffffffff}, {"LEFT", 0xffffffff}, {"RIGHT", 0xffffffff}, {0, 0xffffffff},
}; /* 0x312fc0 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animConditionsStr[12] = {
    {"PLAYERANIMTYPE", 0xffffffff}, {"WEAPONCLASS", 0xffffffff}, {"MOUNTED", 0xffffffff}, {"MOVETYPE", 0xffffffff},
    {"UNDERHAND", 0xffffffff}, {"CROUCHING", 0xffffffff}, {"FIRING", 0xffffffff}, {"WEAPON_POSITION", 0xffffffff},
    {"STRAFING", 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x313080 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animParseModesStr[6] = {
    {"defines", 0xffffffff}, {"animations", 0xffffffff}, {"canned_animations", 0xffffffff}, {"statechanges", 0xffffffff},
    {"events", 0xffffffff}, {0, 0xffffffff},
}; /* 0x3130e0 */
__attribute__((used, aligned(4)))
animConditionTableRaw_t animConditionsTable[12] = {
    {0, (UInt32)weaponStrings},
    {0, (UInt32)animWeaponClassStr},
    {1, (UInt32)animConditionMountedStr},
    {0, (UInt32)animMoveTypesStr},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, (UInt32)animWeaponPositionStr},
    {1, (UInt32)animStrafeStateStr},
    {0, 0},
    {0, 0},
    {0, 0},
}; /* 0x312f60 */
__attribute__((used)) char *globalFilename = (char *)"mp/playeranim.script"; /* 0x313110 */
__attribute__((used, aligned(4)))
UInt32 controller_names[11] = {
    (UInt32)&scr_const.back_low,
    (UInt32)&scr_const.back_mid,
    (UInt32)&scr_const.back_up,
    (UInt32)&scr_const.neck,
    (UInt32)&scr_const.head,
    (UInt32)&scr_const.pelvis,
    0, 0, 0, 0, 0,
}; /* 0x313114 */

#define animStateStr ((animStringItem_t *)animStateStr)
#define animMoveTypesStr ((animStringItem_t *)animMoveTypesStr)
#define animEventTypesStr ((animStringItem_t *)animEventTypesStr)
#define animBodyPartsStr ((animStringItem_t *)animBodyPartsStr)
#define animConditionMountedStr ((animStringItem_t *)animConditionMountedStr)
#define animWeaponClassStr ((animStringItem_t *)animWeaponClassStr)
#define animWeaponPositionStr ((animStringItem_t *)animWeaponPositionStr)
#define animStrafeStateStr ((animStringItem_t *)animStrafeStateStr)
#define animConditionsStr ((animStringItem_t *)animConditionsStr)
#define animConditionsTable ((animConditionTable_t *)animConditionsTable)
#define animParseModesStr ((animStringItem_t *)animParseModesStr)

extern void Com_Error(int code, const char *fmt, ...);
extern int Com_GetCurrentParseLine(void);
void BG_AnimParseError(const char *msg);
void BG_InitWeaponStrings(void);
int BG_PlayAnim(playerState_t *ps, int animNum, animBodyPart_t bodyPart, int forceDuration, qboolean setTimer, qboolean isContinue, qboolean force, playerState_t *ps_7, scriptAnimEventTypes_t event);
static void BG_SwingAngles(float destination, float clampTolerance, float speed);
void BG_UpdatePlayerDObj(struct DObj_s *pDObj, entityState_t *es, clientInfo_t *ci, int attachIgnoreCollision);
void BG_LerpOffset(vec_t *offset_goal, float maxOffsetChange, vec_t *offset);
void BG_UpdateConditionValue(int client, int condition, int value, qboolean checkConversion);
void BG_AnimUpdatePlayerStateConditions(pmove_t *pmove);
void BG_Player_DoControllers(const struct DObj_s *pDObj, const entityState_t *es, int *partBits, clientInfo_t *ci, int frametime);
static void BG_RunLerpFrameRate(clientInfo_t *ci, entityState_t *es);
void BG_PlayerAnimation(const struct DObj_s *pDObj, entityState_t *es, clientInfo_t *ci);
int BG_AnimationIndexForString(const char *string, const char *string_1);
int BG_IndexForString(const char *token, animStringItem_t *strings, qboolean allowFail);
static void BG_ParseConditionBits(const char * *text_pp, animStringItem_t *stringTable, int condIndex, int *result);
static qboolean BG_ParseConditions(const char * *text_pp);
void BG_ParseCommands(const char * *input, animScriptItem_t *scriptItem, animScriptData_t *scriptData);
static void BG_AnimParseAnimScript(animScriptData_t *scriptData);
void BG_InitWeaponString(int index, const char *name);
void BG_LoadAnim(playerState_t *ps, char *animName, animBodyPart_t bodyPart, qboolean setTimer, qboolean isContinue, qboolean force);
int BG_ExecuteCommand(playerState_t *ps, animScriptCommand_t *scriptCommand, qboolean setTimer, qboolean isContinue, qboolean force);
int BG_AnimScriptEvent(playerState_t *ps, scriptAnimEventTypes_t event, qboolean isContinue, qboolean force);
int BG_AnimScriptAnimation(playerState_t *ps, aistateEnum_t state, scriptAnimMoveTypes_t movetype, qboolean isContinue);

/* line 382 */
void BG_AnimParseError(const char *msg) {
    /* The native build treats msg as a printf format string with variadic args.
       Under Emscripten, callers are also stubbed, so just pass msg directly. */
    if (globalFilename) {
        Com_Error(1, "%s: (%s, line %i)", msg, globalFilename, Com_GetCurrentParseLine() + 1);
    } else {
        Com_Error(1, "%s", msg);
    }
}

void BG_LoadWeaponStrings(void);

/* line 568 */
void BG_InitWeaponStrings(void)
{
    memset(weaponStrings, 0, 0x400);
    BG_LoadWeaponStrings();
}

/* line 1827 */
int BG_PlayAnim(playerState_t *ps, int animNum, animBodyPart_t bodyPart, int forceDuration, qboolean setTimer, qboolean isContinue, qboolean force, playerState_t *ps_7, scriptAnimEventTypes_t event) {
    int duration;
    int wasSet = 0;
    int oldAnim, toggleBit;

    /* Compute duration: use forceDuration if nonzero, otherwise look up from script data */
    if (forceDuration) {
        duration = forceDuration;
    } else {
        /* animNum * sizeof(animation_t) + offsetof(duration) = animation_t[animNum].duration */
        duration = globalScriptData->animations[animNum].duration + 0x32;
    }

    /* Handle legs animation (bodyPart == 1 LEGS or bodyPart == 3 BOTH) */
    if (bodyPart == 3 || bodyPart == 1) {
        int legsTimer = ps->legsTimer;
        if (legsTimer <= 0x31 || force) {
            /* Timer allows setting or force override */
            oldAnim = ps->legsAnim;
            if (!isContinue || (oldAnim & ~0x200) != animNum) {
                /* Toggle bit 9 from old anim, combine with new animNum */
                toggleBit = (oldAnim & 0x200) ^ 0x200;
                ps->legsAnimDuration = duration;
                ps->legsAnim = animNum | toggleBit;
                if (setTimer)
                    ps->legsTimer = duration;
                wasSet = 1;
            }
        }
        /* If bodyPart == 3, fall through to torso with animNum = 0 */
        if (bodyPart == 3)
            animNum = 0;
    }

    /* Handle torso animation (bodyPart == 2 TORSO or bodyPart == 3 BOTH) */
    if (bodyPart == 2 || bodyPart == 3) {
        int torsoTimer = ps->torsoTimer;
        if (torsoTimer <= 0x31 || force) {
            oldAnim = ps->torsoAnim;
            if (!isContinue || (oldAnim & ~0x200) != animNum) {
                toggleBit = (oldAnim & 0x200) ^ 0x200;
                ps->torsoAnim = animNum | toggleBit;
                if (setTimer)
                    ps->torsoTimer = duration;
                ps->torsoAnimDuration = duration;
                wasSet = 1;
            }
        }
    }

    if (!wasSet)
        return -1;
    return duration;
}

int BG_AnimScriptEvent(playerState_t *ps, scriptAnimEventTypes_t event, qboolean isContinue, qboolean force) {
    int client;
    int numItems;
    clientInfo_t *ci;
    int i;
    animScriptItem_t **ppScriptItem;

    /* line 2120: if event != 1 (not JUMP), check weapon state */
    if ((int)event != 1) {
        if (ps->pm_type > 5)
            return -1;
    }

    /* line 2123: look up event script table, line 2124: numItems */
    numItems = globalScriptData->scriptEvents[event].numItems;
    if (numItems == 0)
        return -1;

    /* line 2129: client index from ps->clientNum */
    client = ps->clientNum;

    /* Compute ci pointer: &bgs->clientinfo[client] */
    ci = &bgs->clientinfo[client];

    /* line 1796: ppScriptItem = scriptEvents[event].items array */
    ppScriptItem = globalScriptData->scriptEvents[event].items;

    /* Iterate over script items */
    for (i = 0; i < numItems; i++) {
        animScriptItem_t *scriptItem = ppScriptItem[i];
        int numConds = scriptItem->numConditions;
        animScriptCondition_t *cond = scriptItem->conditions;
        int j;
        int allMatch = 1;

        /* Check all conditions for this script item */
        for (j = 0; j < numConds; j++) {
            animScriptCondition_t *condition = &cond[j];
            int condType = condition->index;
            int testType = animConditionsTable[condType].type;

            if (testType == 0) {
                /* Mask check: condition passes if either mask pair has matching bits */
                int mask1 = ci->clientConditions[condType][0];
                if (mask1 & condition->value[0])
                    continue; /* condition matched */
                {
                    int mask2 = ci->clientConditions[condType][1];
                    if (mask2 & condition->value[1])
                        continue; /* condition matched */
                }
                /* Neither mask matched — condition failed */
                allMatch = 0;
                break;
            } else if (testType == 1) {
                /* Exact match: condition passes if values are equal */
                int val = ci->clientConditions[condType][0];
                if (val == condition->value[0])
                    continue; /* condition matched */
                /* Not equal — condition failed */
                allMatch = 0;
                break;
            }
            /* testType > 1: condition is skipped (auto-pass) */
        }

        if (!allMatch)
            continue; /* try next script item */

        /* All conditions passed — execute a random command from this item */
        {
            int numCommands = scriptItem->numCommands;
            int randIdx;

            if (numCommands == 0)
                return -1;

            randIdx = rand() % numCommands;

            return BG_ExecuteCommand(ps, &scriptItem->commands[randIdx], 1, isContinue, force);
        }
    }

    return -1;
}
