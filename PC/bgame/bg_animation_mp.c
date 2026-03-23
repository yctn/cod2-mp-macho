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
extern const char str_002abcf4[], str_002ae9fc[], str_002aea04[], str_002aea0c[], str_002aea18[], str_002aea20[];
extern const char str_002aea28[], str_002aea30[], str_002aea3c[], str_002aea48[], str_002aea54[], str_002aea64[];
extern const char str_002aea6c[], str_002aea7c[], str_002aea8c[], str_002aea9c[], str_002aeaac[], str_002aeabc[];
extern const char str_002aeacc[], str_002aead8[], str_002aeae4[], str_002aeaf4[], str_002aeafc[], str_002aeb04[];
extern const char str_002aeb10[], str_002aeb18[], str_002aeb20[], str_002aeb28[], str_002aeb34[], str_002aeb40[];
extern const char str_002aeb4c[], str_002aeb50[], str_002aeb58[], str_002aeb60[], str_002aeb68[], str_002aeb74[];
extern const char str_002aeb80[], str_002aeb8c[], str_002aeb98[], str_002aeba0[], str_002aebac[], str_002aebb8[];
extern const char str_002aebc8[], str_002aebd8[], str_002aebe8[], str_002aebf8[], str_002aec08[], str_002aec18[];
extern const char str_002aec28[], str_002aec3c[], str_002aec4c[], str_002aec5c[], str_002aec6c[], str_002aec7c[];
extern const char str_002aec88[], str_002aec98[], str_002aeca8[], str_002aecbc[], str_002aecd4[], str_002aecec[];
extern const char str_002aed04[], str_002aed1c[], str_002aed24[], str_002aed2c[], str_002aed34[], str_002aed3c[];
extern const char str_002aed40[], str_002aed48[], str_002aed50[], str_002aed54[], str_002aed58[], str_002aed60[];
extern const char str_002aed64[], str_002aed68[], str_002aed70[], str_002aed78[], str_002aed80[], str_002aed90[];
extern const char str_002aed98[], str_002aeda4[], str_002aedac[], str_002aedbc[], str_002aedc8[], str_002aedd0[];
extern const char str_002aeddc[], str_002aede8[], str_002aedf4[], str_002aedfc[], str_002aee0c[], str_002aee18[];
extern const char str_002aee20[], str_002aee2c[], str_002aee40[], str_002aee50[], str_002aee58[], str_002aee70[];
extern const char str_002aee78[], str_002aee80[];

typedef struct {
    UInt32 string;
    int hash;
} animStringItemRaw_t;

typedef struct {
    int type;
    UInt32 values;
} animConditionTableRaw_t;

__attribute__((used, aligned(4)))
animStringItemRaw_t animStateStr_storage[8] = {
    {(UInt32)str_002aed1c, 0xffffffff}, {(UInt32)str_002aed24, 0xffffffff},
    {(UInt32)str_002aed2c, 0xffffffff}, {(UInt32)str_002aed34, 0xffffffff},
    {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x312f20 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animMoveTypesStr_storage[44] = {
    {(UInt32)str_002aeae4, 0xffffffff}, {(UInt32)str_002aeaf4, 0xffffffff}, {(UInt32)str_002aeafc, 0xffffffff}, {(UInt32)str_002aeb04, 0xffffffff},
    {(UInt32)str_002aeb10, 0xffffffff}, {(UInt32)str_002aeb18, 0xffffffff}, {(UInt32)str_002aeb20, 0xffffffff}, {(UInt32)str_002aeb28, 0xffffffff},
    {(UInt32)str_002aeb34, 0xffffffff}, {(UInt32)str_002aeb40, 0xffffffff}, {(UInt32)str_002aeb4c, 0xffffffff}, {(UInt32)str_002aeb50, 0xffffffff},
    {(UInt32)str_002aeb58, 0xffffffff}, {(UInt32)str_002aeb60, 0xffffffff}, {(UInt32)str_002aeb68, 0xffffffff}, {(UInt32)str_002aeb74, 0xffffffff},
    {(UInt32)str_002aeb80, 0xffffffff}, {(UInt32)str_002aeb8c, 0xffffffff}, {(UInt32)str_002aeb98, 0xffffffff}, {(UInt32)str_002aeba0, 0xffffffff},
    {(UInt32)str_002aebac, 0xffffffff}, {(UInt32)str_002aebb8, 0xffffffff}, {(UInt32)str_002aebc8, 0xffffffff}, {(UInt32)str_002aebd8, 0xffffffff},
    {(UInt32)str_002aebe8, 0xffffffff}, {(UInt32)str_002aebf8, 0xffffffff}, {(UInt32)str_002aec08, 0xffffffff}, {(UInt32)str_002aec18, 0xffffffff},
    {(UInt32)str_002aec28, 0xffffffff}, {(UInt32)str_002aec3c, 0xffffffff}, {(UInt32)str_002aec4c, 0xffffffff}, {(UInt32)str_002aec5c, 0xffffffff},
    {(UInt32)str_002aec6c, 0xffffffff}, {(UInt32)str_002aec7c, 0xffffffff}, {(UInt32)str_002aec88, 0xffffffff}, {(UInt32)str_002aec98, 0xffffffff},
    {(UInt32)str_002aeca8, 0xffffffff}, {(UInt32)str_002aecbc, 0xffffffff}, {(UInt32)str_002aecd4, 0xffffffff}, {(UInt32)str_002aecec, 0xffffffff},
    {(UInt32)str_002aed04, 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x312dc0 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animEventTypesStr_storage[20] = {
    {(UInt32)str_002ae9fc, 0xffffffff}, {(UInt32)str_002aea04, 0xffffffff}, {(UInt32)str_002aea0c, 0xffffffff}, {(UInt32)str_002aea18, 0xffffffff},
    {(UInt32)str_002aea20, 0xffffffff}, {(UInt32)str_002aea28, 0xffffffff}, {(UInt32)str_002aea30, 0xffffffff}, {(UInt32)str_002aea3c, 0xffffffff},
    {(UInt32)str_002aea48, 0xffffffff}, {(UInt32)str_002aea54, 0xffffffff}, {(UInt32)str_002aea64, 0xffffffff}, {(UInt32)str_002aea6c, 0xffffffff},
    {(UInt32)str_002aea7c, 0xffffffff}, {(UInt32)str_002aea8c, 0xffffffff}, {(UInt32)str_002aea9c, 0xffffffff}, {(UInt32)str_002aeaac, 0xffffffff},
    {(UInt32)str_002aeabc, 0xffffffff}, {(UInt32)str_002aeacc, 0xffffffff}, {(UInt32)str_002aead8, 0xffffffff}, {0, 0xffffffff},
}; /* 0x312d20 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animBodyPartsStr_storage[8] = {
    {(UInt32)str_002aeae4, 0xffffffff}, {(UInt32)str_002aee70, 0xffffffff}, {(UInt32)str_002aee78, 0xffffffff}, {(UInt32)str_002aee80, 0xffffffff},
    {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x313140 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animConditionMountedStr_storage[5] = {
    {(UInt32)str_002aeae4, 0xffffffff}, {(UInt32)str_002abcf4, 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000},
    {0, 0x00000000},
}; /* 0x312ff8 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animWeaponClassStr_storage[12] = {
    {(UInt32)str_002aed58, 0xffffffff}, {(UInt32)str_002aed60, 0xffffffff}, {(UInt32)str_002aed64, 0xffffffff}, {(UInt32)str_002aed68, 0xffffffff},
    {(UInt32)str_002aed70, 0xffffffff}, {(UInt32)str_002aed78, 0xffffffff}, {(UInt32)str_002aed80, 0xffffffff}, {(UInt32)str_002aed90, 0xffffffff},
    {(UInt32)str_002aed98, 0xffffffff}, {(UInt32)str_002aeda4, 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000},
}; /* 0x313020 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animWeaponPositionStr_storage[3] = {
    {(UInt32)str_002aed50, 0xffffffff}, {(UInt32)str_002aed54, 0xffffffff}, {0, 0xffffffff},
}; /* 0x312fe0 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animStrafeStateStr_storage[4] = {
    {(UInt32)str_002aed3c, 0xffffffff}, {(UInt32)str_002aed40, 0xffffffff}, {(UInt32)str_002aed48, 0xffffffff}, {0, 0xffffffff},
}; /* 0x312fc0 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animConditionsStr_storage[12] = {
    {(UInt32)str_002aedac, 0xffffffff}, {(UInt32)str_002aedbc, 0xffffffff}, {(UInt32)str_002aedc8, 0xffffffff}, {(UInt32)str_002aedd0, 0xffffffff},
    {(UInt32)str_002aeddc, 0xffffffff}, {(UInt32)str_002aede8, 0xffffffff}, {(UInt32)str_002aedf4, 0xffffffff}, {(UInt32)str_002aedfc, 0xffffffff},
    {(UInt32)str_002aee0c, 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x313080 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animParseModesStr_storage[6] = {
    {(UInt32)str_002aee18, 0xffffffff}, {(UInt32)str_002aee20, 0xffffffff}, {(UInt32)str_002aee2c, 0xffffffff}, {(UInt32)str_002aee40, 0xffffffff},
    {(UInt32)str_002aee50, 0xffffffff}, {0, 0xffffffff},
}; /* 0x3130e0 */
__attribute__((used, aligned(4)))
animConditionTableRaw_t animConditionsTable_storage[12] = {
    {0, (UInt32)weaponStrings},
    {0, (UInt32)animWeaponClassStr_storage},
    {1, (UInt32)animConditionMountedStr_storage},
    {0, (UInt32)animMoveTypesStr_storage},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, (UInt32)animWeaponPositionStr_storage},
    {1, (UInt32)animStrafeStateStr_storage},
    {0, 0},
    {0, 0},
    {0, 0},
}; /* 0x312f60 */
__attribute__((used)) char *globalFilename = (char *)str_002aee58; /* 0x313110 */
__attribute__((used, aligned(4)))
UInt32 controller_names_storage[11] = {
    (UInt32)&scr_const.back_low,
    (UInt32)&scr_const.back_mid,
    (UInt32)&scr_const.back_up,
    (UInt32)&scr_const.neck,
    (UInt32)&scr_const.head,
    (UInt32)&scr_const.pelvis,
    0, 0, 0, 0, 0,
}; /* 0x313114 */

#define animStateStr ((animStringItem_t *)animStateStr_storage)
#define animMoveTypesStr ((animStringItem_t *)animMoveTypesStr_storage)
#define animEventTypesStr ((animStringItem_t *)animEventTypesStr_storage)
#define animBodyPartsStr ((animStringItem_t *)animBodyPartsStr_storage)
#define animConditionMountedStr ((animStringItem_t *)animConditionMountedStr_storage)
#define animWeaponClassStr ((animStringItem_t *)animWeaponClassStr_storage)
#define animWeaponPositionStr ((animStringItem_t *)animWeaponPositionStr_storage)
#define animStrafeStateStr ((animStringItem_t *)animStrafeStateStr_storage)
#define animConditionsStr ((animStringItem_t *)animConditionsStr_storage)
#define animConditionsTable ((animConditionTable_t *)animConditionsTable_storage)
#define animParseModesStr ((animStringItem_t *)animParseModesStr_storage)

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
