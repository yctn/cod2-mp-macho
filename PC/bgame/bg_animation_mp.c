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
animStringItemRaw_t animStateStr_storage[8] __asm__("animStateStr") = {
    {(UInt32)str_002aed1c, 0xffffffff}, {(UInt32)str_002aed24, 0xffffffff},
    {(UInt32)str_002aed2c, 0xffffffff}, {(UInt32)str_002aed34, 0xffffffff},
    {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x312f20 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animMoveTypesStr_storage[44] __asm__("animMoveTypesStr") = {
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
animStringItemRaw_t animEventTypesStr_storage[20] __asm__("animEventTypesStr") = {
    {(UInt32)str_002ae9fc, 0xffffffff}, {(UInt32)str_002aea04, 0xffffffff}, {(UInt32)str_002aea0c, 0xffffffff}, {(UInt32)str_002aea18, 0xffffffff},
    {(UInt32)str_002aea20, 0xffffffff}, {(UInt32)str_002aea28, 0xffffffff}, {(UInt32)str_002aea30, 0xffffffff}, {(UInt32)str_002aea3c, 0xffffffff},
    {(UInt32)str_002aea48, 0xffffffff}, {(UInt32)str_002aea54, 0xffffffff}, {(UInt32)str_002aea64, 0xffffffff}, {(UInt32)str_002aea6c, 0xffffffff},
    {(UInt32)str_002aea7c, 0xffffffff}, {(UInt32)str_002aea8c, 0xffffffff}, {(UInt32)str_002aea9c, 0xffffffff}, {(UInt32)str_002aeaac, 0xffffffff},
    {(UInt32)str_002aeabc, 0xffffffff}, {(UInt32)str_002aeacc, 0xffffffff}, {(UInt32)str_002aead8, 0xffffffff}, {0, 0xffffffff},
}; /* 0x312d20 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animBodyPartsStr_storage[8] __asm__("animBodyPartsStr") = {
    {(UInt32)str_002aeae4, 0xffffffff}, {(UInt32)str_002aee70, 0xffffffff}, {(UInt32)str_002aee78, 0xffffffff}, {(UInt32)str_002aee80, 0xffffffff},
    {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x313140 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animConditionMountedStr_storage[5] __asm__("animConditionMountedStr") = {
    {(UInt32)str_002aeae4, 0xffffffff}, {(UInt32)str_002abcf4, 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000},
    {0, 0x00000000},
}; /* 0x312ff8 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animWeaponClassStr_storage[12] __asm__("animWeaponClassStr") = {
    {(UInt32)str_002aed58, 0xffffffff}, {(UInt32)str_002aed60, 0xffffffff}, {(UInt32)str_002aed64, 0xffffffff}, {(UInt32)str_002aed68, 0xffffffff},
    {(UInt32)str_002aed70, 0xffffffff}, {(UInt32)str_002aed78, 0xffffffff}, {(UInt32)str_002aed80, 0xffffffff}, {(UInt32)str_002aed90, 0xffffffff},
    {(UInt32)str_002aed98, 0xffffffff}, {(UInt32)str_002aeda4, 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000},
}; /* 0x313020 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animWeaponPositionStr_storage[3] __asm__("animWeaponPositionStr") = {
    {(UInt32)str_002aed50, 0xffffffff}, {(UInt32)str_002aed54, 0xffffffff}, {0, 0xffffffff},
}; /* 0x312fe0 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animStrafeStateStr_storage[4] __asm__("animStrafeStateStr") = {
    {(UInt32)str_002aed3c, 0xffffffff}, {(UInt32)str_002aed40, 0xffffffff}, {(UInt32)str_002aed48, 0xffffffff}, {0, 0xffffffff},
}; /* 0x312fc0 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animConditionsStr_storage[12] __asm__("animConditionsStr") = {
    {(UInt32)str_002aedac, 0xffffffff}, {(UInt32)str_002aedbc, 0xffffffff}, {(UInt32)str_002aedc8, 0xffffffff}, {(UInt32)str_002aedd0, 0xffffffff},
    {(UInt32)str_002aeddc, 0xffffffff}, {(UInt32)str_002aede8, 0xffffffff}, {(UInt32)str_002aedf4, 0xffffffff}, {(UInt32)str_002aedfc, 0xffffffff},
    {(UInt32)str_002aee0c, 0xffffffff}, {0, 0xffffffff}, {0, 0x00000000}, {0, 0x00000000},
}; /* 0x313080 */
__attribute__((used, aligned(4)))
animStringItemRaw_t animParseModesStr_storage[6] __asm__("animParseModesStr") = {
    {(UInt32)str_002aee18, 0xffffffff}, {(UInt32)str_002aee20, 0xffffffff}, {(UInt32)str_002aee2c, 0xffffffff}, {(UInt32)str_002aee40, 0xffffffff},
    {(UInt32)str_002aee50, 0xffffffff}, {0, 0xffffffff},
}; /* 0x3130e0 */
__attribute__((used, aligned(4)))
animConditionTableRaw_t animConditionsTable_storage[12] __asm__("animConditionsTable") = {
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
UInt32 controller_names_storage[11] __asm__("controller_names") = {
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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void BG_AnimParseError(const char *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 382 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x434, %esp\n"
        /* { scope 1 */
        "leal 0xc(%ebp), %eax\n" /* line 387 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 388 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x40c(%ebp), %ebx\n" /* text */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movl globalFilename, %eax\n" /* line 391 */
        "testl %eax, %eax\n"
        "je .Lf17fde8_0017fe58\n"
        "calll Com_GetCurrentParseLine\n" /* line 392 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl globalFilename, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $str_002aee88, 4(%esp)\n" /* "%s: (%s, line %i)" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x434, %esp\n" /* line 395 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17fde8_0017fe58:\n"
        "movl %ebx, 8(%esp)\n" /* line 394 */
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x434, %esp\n" /* line 395 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void BG_AnimParseError(const char *msg) {
    /* The native build treats msg as a printf format string with variadic args.
       Under Emscripten, callers are also stubbed, so just pass msg directly. */
    if (globalFilename) {
        Com_Error(1, "%s: (%s, line %i)", msg, globalFilename, Com_GetCurrentParseLine() + 1);
    } else {
        Com_Error(1, "%s", msg);
    }
}
#endif

void BG_LoadWeaponStrings(void);

/* line 568 */
void BG_InitWeaponStrings(void)
{
    memset(weaponStrings, 0, 0x400);
    BG_LoadWeaponStrings();
}

/* line 1827 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int BG_PlayAnim(playerState_t *ps, int animNum, animBodyPart_t bodyPart, int forceDuration, qboolean setTimer, qboolean isContinue, qboolean force, playerState_t *ps_7, scriptAnimEventTypes_t event)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1827 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edi\n" /* ps */
        "movl 0xc(%ebp), %ecx\n" /* animNum */
        "movl 0x10(%ebp), %esi\n" /* bodyPart */
        "movl 0x14(%ebp), %eax\n" /* forceDuration */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 1832 */
        "je .Lf17fea4_0017fedd\n"
        "movl %eax, %ebx\n" /* duration */
        "cmpl $2, %esi\n" /* line 1837 | bodyPart */
        "je .Lf17fea4_0017fef4\n"
        ".Lf17fea4_0017fec4:\n"
        "cmpl $3, %esi\n" /* bodyPart */
        "je .Lf17fea4_0017ff1c\n"
        "cmpl $1, %esi\n" /* bodyPart */
        "je .Lf17fea4_0017ff1c\n"
        ".Lf17fea4_0017fece:\n"
        "movl $0xffffffff, %ebx\n" /* line 1928 | duration */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1932 | duration */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17fea4_0017fedd:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1835 */
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "movl 0x48(%eax), %ebx\n" /* duration */
        "addl $0x32, %ebx\n" /* duration */
        "cmpl $2, %esi\n" /* line 1837 | bodyPart */
        "jne .Lf17fea4_0017fec4\n"
        ".Lf17fea4_0017fef4:\n"
        "movl $0, -0x10(%ebp)\n" /* wasSet */
        "cmpl $0x31, 0x80(%edi)\n" /* line 1903 | ps */
        "jle .Lf17fea4_0017ff40\n"
        ".Lf17fea4_0017ff04:\n"
        "movl 0x20(%ebp), %eax\n" /* force */
        "testl %eax, %eax\n"
        "jne .Lf17fea4_0017ff40\n"
        ".Lf17fea4_0017ff0b:\n"
        "movl -0x10(%ebp), %edx\n" /* line 1928 | wasSet */
        "testl %edx, %edx\n"
        "je .Lf17fea4_0017fece\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1932 | duration */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17fea4_0017ff1c:\n"
        "cmpl $0x31, 0x78(%edi)\n" /* line 1842 | ps */
        "jle .Lf17fea4_0017ff7c\n"
        "movl 0x20(%ebp), %edx\n" /* force */
        "testl %edx, %edx\n"
        "jne .Lf17fea4_0017ff7c\n"
        "movl $0, -0x10(%ebp)\n" /* line 1859 | wasSet */
        "cmpl $3, %esi\n" /* line 1896 | bodyPart */
        "jne .Lf17fea4_0017ff0b\n"
        "xorl %ecx, %ecx\n" /* line 1899 */
        "cmpl $0x31, 0x80(%edi)\n" /* line 1903 | ps */
        "jg .Lf17fea4_0017ff04\n"
        ".Lf17fea4_0017ff40:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1905 | isContinue */
        "testl %eax, %eax\n"
        "je 0x17ffb9\n"
        "movl 0x84(%edi), %edx\n" /* ps */
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ecx\n"
        "je 0x17ffc6\n"
        "andl $0x200, %edx\n" /* line 1907 */
        "xorb $2, %dh\n"
        "orl %edx, %ecx\n"
        "movl %ecx, 0x84(%edi)\n" /* ps */
        "movl 0x18(%ebp), %eax\n" /* line 1908 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf17fea4_0017ff74\n"
        "movl %ebx, 0x80(%edi)\n" /* line 1909 | duration, ps */
        ".Lf17fea4_0017ff74:\n"
        "movl %ebx, 0x8c(%edi)\n" /* line 1910 | duration, ps */
        "jmp .Lf17fea4_0017ff0b\n"
        ".Lf17fea4_0017ff7c:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1844 | isContinue */
        "testl %eax, %eax\n"
        "je 0x17ffc1\n"
        "movl 0x7c(%edi), %edx\n" /* ps */
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ecx\n"
        "je 0x17fff2\n"
        "movl %ebx, 0x88(%edi)\n" /* line 1847 | duration, ps */
        "andl $0x200, %edx\n" /* line 1848 */
        "xorb $2, %dh\n"
        "orl %edx, %ecx\n"
        "movl %ecx, 0x7c(%edi)\n" /* ps */
        "movl 0x18(%ebp), %eax\n" /* line 1849 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf17fea4_0017ffad\n"
        "movl %ebx, 0x78(%edi)\n" /* line 1850 | duration, ps */
    );
}

/* line 2735 */
static __attribute__((naked))
void BG_SwingAngles(float destination, float clampTolerance, float speed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2735 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movss %xmm0, -0x14(%ebp)\n" /* swingTolerance */
        "movaps %xmm1, %xmm0\n" /* swingTolerance */
        "movss %xmm2, -0x18(%ebp)\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        "movl %eax, %esi\n" /* angle */
        "movl %edx, %ebx\n" /* swinging */
        /* { scope 1 */
        "movl (%edx), %eax\n" /* line 2744 */
        "testl %eax, %eax\n"
        "jne .Lf180024_00180088\n"
        "movss -0x14(%ebp), %xmm1\n" /* line 2747 */
        "movss %xmm1, 4(%esp)\n"
        "movl (%esi), %eax\n" /* angle */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "calll AngleSubtract\n"
        "fstps -0xc(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 2748 */
        "movss -0xc(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf180024_00180193\n"
        ".Lf180024_00180078:\n"
        "movl $1, (%ebx)\n" /* line 2750 | swinging */
        ".Lf180024_0018007e:\n"
        "movl (%ebx), %eax\n" /* line 2754 | swinging */
        "testl %eax, %eax\n"
        "je .Lf180024_00180156\n"
        ".Lf180024_00180088:\n"
        "movl (%esi), %eax\n" /* line 2761 | angle */
        "movl %eax, 4(%esp)\n"
        "movss -0x14(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n" /* line 54 */
        "andps g_color_table+464, %xmm1\n"
        "mulss lit4_002ed72c, %xmm1\n" /* line 2763 | 0.05000000074505806f */
        "movss lit4_002ed5d8, %xmm0\n" /* line 2764 | 0.5f */
        "maxss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 2768 */
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf180024_0018015d\n"
        "movl bgs, %eax\n" /* line 2770 */
        "cvtsi2ssl 0xb3be4(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n" /* line 2771 */
        "jb .Lf180024_00180188\n"
        ".Lf180024_001800f2:\n"
        "movl $0, (%ebx)\n" /* line 2788 | swinging */
        "movaps %xmm2, %xmm0\n"
        ".Lf180024_001800fb:\n"
        "addss (%esi), %xmm0\n" /* line 2794 | angle */
        "movss %xmm0, (%esp)\n"
        "calll AngleMod\n"
        "fstps (%esi)\n" /* angle */
        ".Lf180024_0018010b:\n"
        "movl (%esi), %eax\n" /* line 2798 | angle */
        "movl %eax, 4(%esp)\n"
        "movss -0x14(%ebp), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x10(%ebp)\n"
        "movss -0x10(%ebp), %xmm0\n" /* line 2799 */
        "ucomiss -0x18(%ebp), %xmm0\n"
        "ja .Lf180024_001801a8\n"
        "movss -0x18(%ebp), %xmm0\n" /* line 2803 */
        "xorps g_color_table+448, %xmm0\n"
        "ucomiss -0x10(%ebp), %xmm0\n"
        "jbe .Lf180024_00180156\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 2805 */
        "addss -0x18(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleMod\n"
        "fstps (%esi)\n" /* angle */
        /* } scope */
        ".Lf180024_00180156:\n"
        "addl $0x50, %esp\n" /* line 2807 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf180024_0018015d:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 2782 */
        "jbe .Lf180024_0018010b\n"
        "movl bgs, %eax\n" /* line 2784 */
        "cvtsi2ssl 0xb3be4(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "xorl $0x80000000, -0x1c(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "ucomiss %xmm0, %xmm2\n" /* line 2785 */
        "jae .Lf180024_001800f2\n"
        ".Lf180024_00180188:\n"
        "movl $1, (%ebx)\n" /* line 2792 | swinging */
        "jmp .Lf180024_001800fb\n"
        ".Lf180024_00180193:\n"
        "xorps g_color_table+448, %xmm0\n" /* line 2748 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf180024_0018007e\n"
        "jmp .Lf180024_00180078\n"
        ".Lf180024_001801a8:\n"
        "movss -0x14(%ebp), %xmm1\n" /* line 2801 */
        "subss -0x18(%ebp), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll AngleMod\n"
        "fstps (%esi)\n" /* angle */
        /* } scope */
        "addl $0x50, %esp\n" /* line 2807 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3416 */
__attribute__((naked))
void BG_UpdatePlayerDObj(struct DObj_s *pDObj, entityState_t *es, clientInfo_t *ci, int attachIgnoreCollision)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3416 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        /* { scope 1 */
        "movl $0, -0x88(%ebp)\n" /* line 3431 | iClientWeapon */
        "movl 0xc(%ebp), %eax\n" /* es */
        "testl $0x300, 8(%eax)\n"
        "movl $0, %edx\n"
        "cmovel 0xc8(%eax), %edx\n"
        "movl %edx, -0x88(%ebp)\n" /* iClientWeapon */
        "movl 0x10(%ebp), %ecx\n" /* line 3434 | ci */
        "movl 0x4a4(%ecx), %ecx\n"
        "movl %ecx, -0x80(%ebp)\n" /* pAnimTree */
        "movl 0x10(%ebp), %eax\n" /* line 3438 | ci */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1801c6_00180388\n"
        "cmpb $0, 0x40(%eax)\n"
        "jne .Lf1801c6_00180240\n"
        "movl -0x80(%ebp), %edx\n" /* pAnimTree */
        ".Lf1801c6_0018021a:\n"
        "movl %edx, (%esp)\n" /* line 3440 */
        "calll XAnimClearTree\n"
        "movl 0xc(%ebp), %ecx\n" /* line 3441 | es */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "movl bgs, %eax\n"
        "calll *0xb3bf4(%eax)\n"
        /* } scope */
        ".Lf1801c6_00180235:\n"
        "addl $0xac, %esp\n" /* line 3481 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1801c6_00180240:\n"
        "movl 8(%ebp), %eax\n" /* line 3445 | pDObj */
        "testl %eax, %eax\n"
        "je .Lf1801c6_0018026f\n"
        "movl -0x88(%ebp), %edx\n" /* line 3447 | iClientWeapon */
        "movl 0x10(%ebp), %eax\n" /* ci */
        "cmpl 0x4a8(%eax), %edx\n"
        "je .Lf1801c6_0018038f\n"
        ".Lf1801c6_0018025c:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 3451 | es */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "movl bgs, %eax\n"
        "calll *0xb3bf4(%eax)\n"
        ".Lf1801c6_0018026f:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3456 | ci */
        "addl $0x40, %eax\n"
        "movl %eax, (%esp)\n"
        "movl bgs, %eax\n"
        "calll *0xb3bec(%eax)\n"
        "movl %eax, -0x78(%ebp)\n" /* dobjModels */
        "movl $0, -0x74(%ebp)\n" /* line 3458 */
        "movl $0, -0x70(%ebp)\n" /* line 3459 */
        "movl 0x10(%ebp), %ebx\n" /* ci */
        "movl $1, -0x7c(%ebp)\n" /* iNumModels */
        "movl $0, -0x84(%ebp)\n" /* i */
        "movl %ebx, %edi\n"
        "addl $0x200, %edi\n"
        "movl %ebx, %esi\n"
        "subl $-0x80, %esi\n"
        "leal -0xc(%ebp), %eax\n"
        "movl %eax, -0x8c(%ebp)\n"
        "jmp .Lf1801c6_001802d9\n"
        ".Lf1801c6_001802c0:\n"
        "addl $1, -0x84(%ebp)\n" /* line 3463 | i */
        "addl $0x40, %esi\n"
        "addl $0x40, %edi\n"
        "addl $0x40, %ebx\n"
        "cmpl $6, -0x84(%ebp)\n" /* i */
        "je .Lf1801c6_00180334\n"
        ".Lf1801c6_001802d9:\n"
        "cmpb $0, 0x80(%ebx)\n" /* line 3465 */
        "je .Lf1801c6_001802c0\n"
        "movl %esi, (%esp)\n" /* line 3469 */
        "movl bgs, %eax\n"
        "calll *0xb3bec(%eax)\n"
        "movl -0x8c(%ebp), %edx\n"
        "movl %eax, -0x60(%edx)\n"
        "movl %edi, -0x5c(%edx)\n" /* line 3471 */
        "movl 0x14(%ebp), %eax\n" /* line 3472 | attachIgnoreCollision */
        "movzbl -0x84(%ebp), %ecx\n" /* i */
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, -0x58(%edx)\n"
        "addl $1, -0x7c(%ebp)\n" /* line 3473 | iNumModels */
        "addl $0xc, %edx\n"
        "movl %edx, -0x8c(%ebp)\n"
        "addl $1, -0x84(%ebp)\n" /* line 3463 | i */
        "addl $0x40, %esi\n"
        "addl $0x40, %edi\n"
        "addl $0x40, %ebx\n"
        "cmpl $6, -0x84(%ebp)\n" /* i */
        "jne .Lf1801c6_001802d9\n"
        ".Lf1801c6_00180334:\n"
        "movl -0x88(%ebp), %edx\n" /* line 3476 | iClientWeapon */
        "movl 0x10(%ebp), %eax\n" /* ci */
        "movl %edx, 0x4a8(%eax)\n"
        "movl %eax, 0x10(%esp)\n" /* line 3479 */
        "movl 0xc(%ebp), %ecx\n" /* es */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x80(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, 8(%esp)\n"
        "movzwl -0x7c(%ebp), %eax\n" /* iNumModels */
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* dobjModels */
        "movl %eax, (%esp)\n"
        "movl bgs, %eax\n"
        "calll *0xb3bf0(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 3480 | ci */
        "movl $0, 0x3f8(%edx)\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 3481 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1801c6_00180388:\n"
        "movl %ecx, %edx\n"
        "jmp .Lf1801c6_0018021a\n"
        /* { scope 1 */
        ".Lf1801c6_0018038f:\n"
        "movl 0x3f8(%eax), %eax\n" /* line 3447 */
        "testl %eax, %eax\n"
        "jne .Lf1801c6_0018025c\n"
        "jmp .Lf1801c6_00180235\n"
    );
}

/* line 3327 */
__attribute__((naked))
void BG_LerpOffset(vec_t *offset_goal, float maxOffsetChange, vec_t *offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3327 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* offset_goal */
        "movl 0x10(%ebp), %ecx\n" /* offset */
        /* { scope 1: i, y */
        "movss (%ebx), %xmm6\n" /* line 248 */
        "movaps %xmm6, %xmm5\n"
        "subss (%ecx), %xmm5\n"
        "movss 4(%ebx), %xmm3\n" /* line 249 */
        "subss 4(%ecx), %xmm3\n"
        "movss 8(%ebx), %xmm4\n" /* line 250 */
        "subss 8(%ecx), %xmm4\n"
        "movaps %xmm5, %xmm2\n" /* line 316 */
        "mulss %xmm5, %xmm2\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "ucomiss lit4_002ed5e8, %xmm2\n" /* line 3334 | 0.0f */
        "jp .Lf1803a2_001803f6\n"
        "je .Lf1803a2_00180452\n"
        /* { scope 2 */
        ".Lf1803a2_001803f6:\n"
        "movss %xmm2, -0x10(%ebp)\n" /* line 69 | y */
        "movl -0x10(%ebp), %edx\n" /* line 71 | y */
        "sarl $1, %edx\n"
        "movl $0x5f3759df, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, -0xc(%ebp)\n" /* i */
        "movss -0xc(%ebp), %xmm1\n" /* line 72 | i */
        "mulss lit4_002ed5d8, %xmm2\n" /* line 73 | 0.5f */
        "mulss %xmm1, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "movss lit4_002ed600, %xmm0\n" /* 1.5f */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n" /* y */
        /* } scope */
        "mulss 0xc(%ebp), %xmm0\n" /* line 3337 | maxOffsetChange */
        "ucomiss lit4_002ed5d0, %xmm0\n" /* line 3338 | 1.0f */
        "jb .Lf1803a2_00180458\n"
        ".Lf1803a2_00180442:\n"
        "movss %xmm6, (%ecx)\n" /* line 199 */
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lf1803a2_00180452:\n"
        "addl $0x14, %esp\n" /* line 3346 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i, y */
        ".Lf1803a2_00180458:\n"
        "jp .Lf1803a2_00180442\n" /* line 3338 */
        "mulss %xmm0, %xmm5\n" /* line 288 */
        "addss (%ecx), %xmm5\n"
        "movss %xmm5, (%ecx)\n"
        "mulss %xmm0, %xmm3\n" /* line 289 */
        "addss 4(%ecx), %xmm3\n"
        "movss %xmm3, 4(%ecx)\n"
        "mulss %xmm0, %xmm4\n" /* line 290 */
        "addss 8(%ecx), %xmm4\n"
        "movss %xmm4, 8(%ecx)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 3346 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2164 */
__attribute__((naked))
void BG_UpdateConditionValue(int client, int condition, int value, qboolean checkConversion)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2164 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* client */
        "movl 0xc(%ebp), %esi\n" /* condition */
        "movl 0x10(%ebp), %ebx\n" /* value */
        "movl 0x14(%ebp), %eax\n" /* line 2169 | checkConversion */
        "testl %eax, %eax\n"
        "je .Lf180488_001804a8\n"
        "movl animConditionsTable(, %esi, 8), %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "je .Lf180488_001804c7\n"
        ".Lf180488_001804a8:\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2187 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "addl %esi, %edx\n" /* condition */
        "movl bgs, %eax\n"
        "movl %ebx, 0xb4058(%eax, %edx, 8)\n" /* value */
        "popl %ebx\n" /* line 2188 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf180488_001804c7:\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2179 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "addl %esi, %edx\n" /* condition */
        "movl bgs, %eax\n"
        "movl $0, 0xb4058(%eax, %edx, 8)\n"
        "movl bgs, %eax\n" /* line 2180 */
        "movl $0, 0xb405c(%eax, %edx, 8)\n"
        "movl bgs, %eax\n" /* line 812 */
        "leal 0xb4058(%eax, %edx, 8), %edx\n"
        "movl %ebx, %esi\n"
        "sarl $5, %esi\n"
        "andl $0x1f, %ebx\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, (%edx, %esi, 4)\n"
        "popl %ebx\n" /* line 2188 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2279 */
__attribute__((naked))
void BG_AnimUpdatePlayerStateConditions(pmove_t *pmove)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2279 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 2284 | pmove */
        "movl (%eax), %esi\n" /* ps */
        "movl %esi, (%esp)\n" /* line 2285 | ps */
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edi\n" /* weaponDef */
        "movl 0x74(%eax), %ebx\n" /* line 2289 | bitNum */
        "movl 0xcc(%esi), %ecx\n" /* ps, client */
        /* { scope 2 */
        "movl animConditionsTable, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf18051a_001806bf\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2179 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4058(%eax)\n"
        "movl %edx, %eax\n" /* line 2180 */
        "addl bgs, %eax\n"
        "movl $0, 0xb405c(%eax)\n"
        /* { scope 3 */
        "movl bgs, %eax\n" /* line 812 */
        "leal 0xb4058(%edx, %eax), %edx\n"
        "movl %ebx, %ecx\n"
        "sarl $5, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "andl $0x1f, %ebx\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x1c(%ebp), %ecx\n"
        "orl %eax, (%edx, %ecx, 4)\n"
        /* } scope */
        /* } scope */
        "movl 0x7c(%edi), %ebx\n" /* line 2291 | weaponDef, bitNum */
        "movl 0xcc(%esi), %ecx\n" /* ps, client */
        /* { scope 2 */
        "movl animConditionsTable+8, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf18051a_001806f1\n"
        ".Lf18051a_001805c0:\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2179 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4060(%eax)\n"
        "movl %edx, %eax\n" /* line 2180 */
        "addl bgs, %eax\n"
        "movl $0, 0xb4064(%eax)\n"
        /* { scope 3 */
        "movl bgs, %eax\n" /* line 812 */
        "leal 0xb4060(%edx, %eax), %edx\n"
        "movl %ebx, %edi\n"
        "sarl $5, %edi\n"
        "andl $0x1f, %ebx\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, (%edx, %edi, 4)\n"
        /* } scope */
        /* } scope */
        "testb $4, 0xa2(%esi)\n" /* line 2293 | ps */
        "je .Lf18051a_0018071a\n"
        ".Lf18051a_00180621:\n"
        "movl 0xcc(%esi), %ecx\n" /* line 2294 | ps, client */
        /* { scope 2 */
        "movl animConditionsTable+56, %edi\n" /* line 2172 */
        "testl %edi, %edi\n"
        "je .Lf18051a_001808d6\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $1, 0xb4090(%eax)\n"
        /* } scope */
        "testl $0x300, 0xa0(%esi)\n" /* line 2299 | ps */
        "jne .Lf18051a_00180780\n"
        ".Lf18051a_00180665:\n"
        "movl 0xcc(%esi), %ecx\n" /* line 2302 | ps, client */
        /* { scope 2 */
        "movl animConditionsTable+16, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf18051a_001809c0\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4068(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb406c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $1, 0xb4068(%eax, %edx)\n" /* line 812 */
        "jmp .Lf18051a_001807d6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18051a_001806bf:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl %ebx, 0xb4058(%eax)\n" /* bitNum */
        /* } scope */
        "movl 0x7c(%edi), %ebx\n" /* line 2291 | weaponDef, bitNum */
        "movl 0xcc(%esi), %ecx\n" /* ps, client */
        /* { scope 2 */
        "movl animConditionsTable+8, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "je .Lf18051a_001805c0\n"
        ".Lf18051a_001806f1:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl %ebx, 0xb4060(%eax)\n" /* bitNum */
        /* } scope */
        "testb $4, 0xa2(%esi)\n" /* line 2293 | ps */
        "jne .Lf18051a_00180621\n"
        ".Lf18051a_0018071a:\n"
        "movl 0xcc(%esi), %ecx\n" /* line 2296 | ps, client */
        /* { scope 2 */
        "movl animConditionsTable+56, %ebx\n" /* line 2172 */
        "testl %ebx, %ebx\n"
        "jne .Lf18051a_001808b1\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4090(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb4094(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $1, 0xb4090(%eax, %edx)\n" /* line 812 */
        /* } scope */
        ".Lf18051a_00180770:\n"
        "testl $0x300, 0xa0(%esi)\n" /* line 2299 | ps */
        "je .Lf18051a_00180665\n"
        ".Lf18051a_00180780:\n"
        "movl 0xcc(%esi), %ecx\n" /* line 2300 | ps, client */
        /* { scope 2 */
        "movl animConditionsTable+16, %edx\n" /* line 2172 */
        "testl %edx, %edx\n"
        "jne .Lf18051a_0018099b\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4068(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb406c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $2, 0xb4068(%eax, %edx)\n" /* line 812 */
        /* } scope */
        ".Lf18051a_001807d6:\n"
        "movss 0xe8(%esi), %xmm0\n" /* line 2305 | ps */
        "xorl %ebx, %ebx\n" /* bitNum */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "seta %bl\n" /* bitNum */
        "movl 0xcc(%esi), %ecx\n" /* ps, client */
        /* { scope 2 */
        "movl animConditionsTable+32, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf18051a_0018097a\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2179 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4078(%eax)\n"
        "movl %edx, %eax\n" /* line 2180 */
        "addl bgs, %eax\n"
        "movl $0, 0xb407c(%eax)\n"
        /* { scope 3 */
        "movl bgs, %edi\n" /* line 812 */
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, 0xb4078(%edx, %edi)\n"
        /* } scope */
        /* } scope */
        ".Lf18051a_00180847:\n"
        "movl 8(%ebp), %eax\n" /* line 2307 | pmove */
        "testb $1, 8(%eax)\n"
        "je .Lf18051a_0018091d\n"
        "movl 0xcc(%esi), %ecx\n" /* line 2308 | ps, client */
        /* { scope 2 */
        "movl animConditionsTable+48, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf18051a_001809e5\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4088(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb408c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $2, 0xb4088(%eax, %edx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2311 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf18051a_001808b1:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4090(%eax)\n"
        "jmp .Lf18051a_00180770\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18051a_001808d6:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4090(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb4094(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $2, 0xb4090(%eax, %edx)\n" /* line 812 */
        "jmp .Lf18051a_00180770\n"
        /* } scope */
        ".Lf18051a_0018091d:\n"
        "movl 0xcc(%esi), %ecx\n" /* line 2310 | ps, client */
        /* { scope 2 */
        "movl animConditionsTable+48, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf18051a_00180a0d\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4088(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb408c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $1, 0xb4088(%eax, %edx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2311 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf18051a_0018097a:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl %ebx, 0xb4078(%eax)\n" /* bitNum */
        "jmp .Lf18051a_00180847\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18051a_0018099b:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $1, 0xb4068(%eax)\n"
        "jmp .Lf18051a_001807d6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18051a_001809c0:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4068(%eax)\n"
        "jmp .Lf18051a_001807d6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf18051a_001809e5:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $1, 0xb4088(%eax)\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2311 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf18051a_00180a0d:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4088(%eax)\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2311 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3357 */
__attribute__((naked))
void BG_Player_DoControllers(const struct DObj_s *pDObj, const entityState_t *es, int *partBits, clientInfo_t *ci, int frametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3357 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* es */
        /* { scope 1: angles, tag_origin_angles, vTorsoAngles, vHeadAngles */
        /* { scope 2: radians */
        "movl 8(%esi), %ecx\n" /* line 3118 */
        "testb $3, %ch\n"
        "jne .Lf180a36_00181279\n"
        "pxor %xmm0, %xmm0\n" /* line 183 */
        "movss %xmm0, -0x24(%ebp)\n" /* tag_origin_angles */
        "movss %xmm0, -0x1c(%ebp)\n" /* line 185 */
        "movss %xmm0, -0x30(%ebp)\n" /* line 183 | vTorsoAngles */
        "movss %xmm0, -0x28(%ebp)\n" /* line 185 */
        "movl 0x14(%ebp), %edx\n" /* ci */
        "addl $0x3e8, %edx\n"
        /* { scope 3 */
        "movl 0x14(%ebp), %ebx\n" /* line 199 | ci */
        "movl 0x3e8(%ebx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* vHeadAngles */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x34(%ebp)\n"
        /* } scope */
        "movl 0x380(%ebx), %eax\n" /* line 3131 | i */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x3b0(%ebx), %eax\n" /* line 3132 | i */
        "movl %eax, -0x2c(%ebp)\n"
        "testl $0xc0000, 0x474(%ebx)\n" /* line 3138 | i */
        "je .Lf180a36_00181117\n"
        ".Lf180a36_00180aac:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 3154 | vHeadAngles */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %ebx\n" /* vTorsoAngles, i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %eax, (%esp)\n"
        "calll AnglesSubtract\n"
        "movl %ebx, 8(%esp)\n" /* line 3155 | i */
        "leal -0x24(%ebp), %eax\n" /* tag_origin_angles */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll AnglesSubtract\n"
        "movl 0xe4(%esi), %edi\n" /* line 3157 */
        "movl 0x14(%ebp), %edx\n" /* line 3159 | ci */
        "movl 0x3e4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetLeanFraction\n"
        "fstps -0x16c(%ebp)\n"
        "movss -0x16c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm3\n" /* line 3160 */
        "mulss lit4_002ed910, %xmm3\n" /* 50.0f */
        "movaps %xmm3, %xmm0\n"
        "mulss lit4_002ed914, %xmm0\n" /* 0.925000011920929f */
        "movss %xmm0, -0x28(%ebp)\n"
        "movss %xmm0, -0x34(%ebp)\n" /* line 3161 */
        "pxor %xmm0, %xmm0\n" /* line 3163 */
        "ucomiss %xmm0, %xmm2\n"
        "jne .Lf180a36_00180edc\n"
        "jp .Lf180a36_00180edc\n"
        "movl $0, -0xf4(%ebp)\n"
        "movl 8(%esi), %eax\n"
        ".Lf180a36_00180b3a:\n"
        "testl $0x20000, %eax\n" /* line 3182 */
        "je .Lf180a36_00180f16\n"
        ".Lf180a36_00180b45:\n"
        "testb $8, %al\n" /* line 3185 */
        "jne .Lf180a36_00180f5c\n"
        ".Lf180a36_00180b4d:\n"
        "pxor %xmm0, %xmm0\n" /* line 3218 */
        "ucomiss %xmm0, %xmm2\n"
        "jp .Lf180a36_001812e0\n"
        "jne .Lf180a36_001812e0\n"
        ".Lf180a36_00180b60:\n"
        "mulss lit4_002ed934, %xmm3\n" /* line 3250 | 0.07500000298023224f */
        "addss -0x1c(%ebp), %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 3252 | vTorsoAngles */
        "movss lit4_002ed724, %xmm7\n" /* 0.20000000298023224f */
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n" /* angles */
        "movss -0x2c(%ebp), %xmm2\n" /* line 3253 */
        "movss lit4_002ed71c, %xmm4\n" /* 0.4000000059604645f */
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "movss -0x28(%ebp), %xmm3\n" /* line 3254 */
        "movss lit4_002ed5d8, %xmm5\n" /* 0.5f */
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "movss 0xe8(%esi), %xmm0\n" /* line 3256 */
        "pxor %xmm6, %xmm6\n"
        "ucomiss %xmm6, %xmm0\n"
        "jne .Lf180a36_00181175\n"
        "jp .Lf180a36_00181175\n"
        "ucomiss 0xec(%esi), %xmm6\n"
        "jp .Lf180a36_00181175\n"
        "jne .Lf180a36_00181175\n"
        ".Lf180a36_00180bee:\n"
        "movss lit4_002ed6f4, %xmm6\n" /* line 3259 | 0.30000001192092896f */
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movss %xmm0, -0x78(%ebp)\n"
        "mulss %xmm2, %xmm4\n" /* line 3260 */
        "movss %xmm4, -0x74(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 3261 */
        "mulss %xmm5, %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "mulss %xmm1, %xmm5\n" /* line 3263 */
        "movss %xmm5, -0x6c(%ebp)\n"
        "mulss %xmm7, %xmm2\n" /* line 3264 */
        "movss %xmm2, -0x68(%ebp)\n"
        "mulss lit4_002ed938, %xmm3\n" /* line 3265 | -0.6000000238418579f */
        "movss %xmm3, -0x64(%ebp)\n"
        "movl $0, -0xf0(%ebp)\n"
        ".Lf180a36_00180c40:\n"
        "movss -0x3c(%ebp), %xmm1\n" /* line 3268 | vHeadAngles */
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 3269 */
        "mulss %xmm0, %xmm6\n"
        "movss %xmm6, -0x5c(%ebp)\n"
        "movl $0, -0x58(%ebp)\n" /* line 3270 */
        "movss lit4_002ed6ac, %xmm2\n" /* line 3272 | 0.699999988079071f */
        "mulss %xmm2, %xmm1\n"
        "movss %xmm1, -0x54(%ebp)\n"
        "mulss %xmm2, %xmm0\n" /* line 3273 */
        "movss %xmm0, -0x50(%ebp)\n"
        "movss lit4_002ed61c, %xmm0\n" /* line 3274 | -0.30000001192092896f */
        "mulss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movl $0, -0x48(%ebp)\n" /* line 183 */
        "movl $0, -0x44(%ebp)\n" /* line 184 */
        "movl $0, -0x40(%ebp)\n" /* line 185 */
        "movss 0xec(%esi), %xmm0\n" /* line 3279 */
        "pxor %xmm6, %xmm6\n"
        "ucomiss %xmm6, %xmm0\n"
        "jne .Lf180a36_00180cc5\n"
        "jp .Lf180a36_00180cc5\n"
        "ucomiss 0xe8(%esi), %xmm6\n"
        "jp .Lf180a36_00180cc5\n"
        "je .Lf180a36_00180cdc\n"
        ".Lf180a36_00180cc5:\n"
        "movl 0xe8(%esi), %eax\n" /* line 3280 */
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x48(%ebp)\n"
        ".Lf180a36_00180cdc:\n"
        "xorl %ebx, %ebx\n" /* i */
        "leal -0x84(%ebp), %ecx\n" /* angles */
        "xorl %edx, %edx\n"
        ".Lf180a36_00180ce6:\n"
        "movl (%edx, %ecx), %eax\n" /* line 199 */
        "movl %eax, -0xe4(%edx, %ebp)\n"
        "movl 4(%edx, %ecx), %eax\n" /* line 200 */
        "movl %eax, -0xe0(%edx, %ebp)\n"
        "movl 8(%edx, %ecx), %eax\n" /* line 201 */
        "movl %eax, -0xdc(%edx, %ebp)\n"
        "addl $1, %ebx\n" /* line 3282 | i */
        "addl $0xc, %edx\n"
        "cmpl $6, %ebx\n" /* i */
        "jne .Lf180a36_00180ce6\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | tag_origin_angles */
        "movl %eax, -0x9c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x98(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x94(%ebp)\n"
        "movss -0xf0(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x90(%ebp)\n"
        "movss -0xf4(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, -0x8c(%ebp)\n"
        "movl %edi, -0x88(%ebp)\n" /* line 201 */
        /* } scope */
        ".Lf180a36_00180d52:\n"
        "cvtsi2ssl 0x18(%ebp), %xmm4\n" /* line 3365 | frametime */
        "movaps %xmm4, %xmm3\n"
        "mulss lit4_002ed77c, %xmm3\n" /* 0.36000001430511475f */
        "movl $0, -0x108(%ebp)\n" /* i */
        "movl $controller_names, %edi\n"
        "movaps %xmm3, %xmm5\n"
        "xorps g_color_table+480, %xmm5\n"
        "movss %xmm5, -0x110(%ebp)\n"
        "movl 0x14(%ebp), %ebx\n" /* ci, i */
        "addl $0x3fc, %ebx\n" /* i */
        "xorl %esi, %esi\n" /* es */
        ".Lf180a36_00180d8e:\n"
        "leal -0xe4(%ebp), %ecx\n" /* line 3368 | info, angles_goal */
        "addl %esi, %ecx\n" /* es, angles_goal */
        "movl $1, %edx\n"
        ".Lf180a36_00180d9b:\n"
        "leal (, %edx, 4), %eax\n" /* line 3357 */
        /* { scope 2: radians */
        /* { scope 3 */
        "movss -4(%ecx, %eax), %xmm2\n" /* line 3304 */
        "leal (%ebx, %eax), %eax\n" /* line 3357 | i */
        "movss -4(%eax), %xmm0\n" /* line 3304 */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "ucomiss %xmm3, %xmm1\n" /* line 3305 */
        "jbe .Lf180a36_001811e3\n"
        "addss %xmm3, %xmm0\n" /* line 3307 */
        "movss %xmm0, -4(%eax)\n"
        ".Lf180a36_00180dc9:\n"
        "addl $1, %edx\n" /* line 3315 */
        "cmpl $4, %edx\n" /* line 3302 */
        "jne .Lf180a36_00180d9b\n"
        /* } scope */
        /* } scope */
        "movl %ebx, 0xc(%esp)\n" /* line 3369 | i */
        "movl (%edi), %eax\n"
        "movzwl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* partBits */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* pDObj */
        "movl %edx, (%esp)\n"
        "movss %xmm3, -0x158(%ebp)\n"
        "movss %xmm4, -0x168(%ebp)\n"
        "calll DObjSetControlTagAngles\n"
        "addl $1, -0x108(%ebp)\n" /* line 3366 | i */
        "addl $0xc, %esi\n" /* es */
        "addl $0xc, %ebx\n" /* i */
        "addl $4, %edi\n"
        "cmpl $6, -0x108(%ebp)\n" /* i */
        "movss -0x158(%ebp), %xmm3\n"
        "movss -0x168(%ebp), %xmm4\n"
        "jne .Lf180a36_00180d8e\n"
        "movl 0x14(%ebp), %esi\n" /* line 3372 | ci, angles */
        "addl $0x444, %esi\n" /* angles */
        "movl $1, %edx\n"
        "movaps %xmm3, %xmm5\n"
        "xorps g_color_table+480, %xmm5\n"
        /* { scope 2: radians */
        /* { scope 3 */
        ".Lf180a36_00180e45:\n"
        "leal (, %edx, 4), %eax\n" /* line 3304 */
        "movss -0xa0(%eax, %ebp), %xmm2\n"
        "leal (%esi, %eax), %eax\n" /* line 3357 | es */
        "movss -4(%eax), %xmm0\n" /* line 3304 */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "ucomiss %xmm3, %xmm1\n" /* line 3305 */
        "jbe .Lf180a36_00181208\n"
        "addss %xmm3, %xmm0\n" /* line 3307 */
        "movss %xmm0, -4(%eax)\n"
        ".Lf180a36_00180e76:\n"
        "addl $1, %edx\n" /* line 3315 */
        "cmpl $4, %edx\n" /* line 3302 */
        "jne .Lf180a36_00180e45\n"
        /* } scope */
        /* } scope */
        "movl 0x14(%ebp), %ebx\n" /* line 3373 | ci, i */
        "addl $0x450, %ebx\n" /* i */
        "movl %ebx, 8(%esp)\n" /* i */
        "mulss lit4_002ed7d0, %xmm4\n" /* 0.10000000149011612f */
        "movss %xmm4, 4(%esp)\n"
        "leal -0x90(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_LerpOffset\n"
        "movl %esi, 0x10(%esp)\n" /* line 3374 | angles */
        "movl %ebx, 0xc(%esp)\n" /* i */
        "movl imp_scr_const, %eax\n"
        "movzwl 0xa2(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %ebx\n" /* partBits, i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 8(%ebp), %eax\n" /* pDObj */
        "movl %eax, (%esp)\n"
        "calll DObjSetLocalTag\n"
        /* } scope */
        "addl $0x18c, %esp\n" /* line 3375 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: angles, tag_origin_angles, vTorsoAngles, vHeadAngles */
        /* { scope 2: radians */
        ".Lf180a36_00180edc:\n"
        "movl 8(%esi), %eax\n" /* line 3165 */
        "testb $4, %al\n"
        "je .Lf180a36_001812b3\n"
        "pxor %xmm1, %xmm1\n" /* line 3167 */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf180a36_00181312\n"
        ".Lf180a36_00180ef4:\n"
        "movaps %xmm2, %xmm5\n" /* line 3175 */
        "mulss lit4_002ed918, %xmm5\n" /* -2.5f */
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0xf4(%ebp)\n"
        "testl $0x20000, %eax\n" /* line 3182 */
        "jne .Lf180a36_00180b45\n"
        ".Lf180a36_00180f16:\n"
        "movl 0x14(%ebp), %edx\n" /* line 3183 | ci */
        "movl 0x3ec(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x148(%ebp)\n"
        "movss %xmm3, -0x158(%ebp)\n"
        "calll AngleSubtract\n"
        "fstps -0x20(%ebp)\n"
        "movl 8(%esi), %eax\n"
        "movss -0x158(%ebp), %xmm3\n"
        "movss -0x148(%ebp), %xmm2\n"
        "testb $8, %al\n" /* line 3185 */
        "je .Lf180a36_00180b4d\n"
        ".Lf180a36_00180f5c:\n"
        "pxor %xmm0, %xmm0\n" /* line 3188 */
        "ucomiss %xmm0, %xmm2\n"
        "jp .Lf180a36_0018129c\n"
        "jne .Lf180a36_0018129c\n"
        ".Lf180a36_00180f6f:\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 3192 | tag_origin_angles */
        "addss 0xe8(%esi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* tag_origin_angles */
        "cvtss2sd -0x2c(%ebp), %xmm0\n" /* line 3194 */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xf8(%ebp)\n" /* radians */
        /* { scope 3 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "movss %xmm2, -0x148(%ebp)\n"
        "calll sinf\n"
        "fstps -0x16c(%ebp)\n"
        "movss -0x16c(%ebp), %xmm1\n"
        /* } scope */
        "movss -0xf8(%ebp), %xmm5\n" /* line 486 | radians */
        "movss %xmm5, (%esp)\n"
        "movss %xmm1, -0x138(%ebp)\n"
        "calll cosf\n"
        "fstps -0x10c(%ebp)\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "subss -0x10c(%ebp), %xmm3\n"
        "movaps %xmm3, %xmm6\n" /* line 3195 */
        "mulss lit4_002ed924, %xmm6\n" /* -24.0f */
        "pxor %xmm0, %xmm0\n"
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0xf0(%ebp)\n"
        "movss -0x138(%ebp), %xmm1\n" /* line 3196 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed928, %xmm0\n" /* -12.0f */
        "addss -0xf4(%ebp), %xmm0\n"
        "movss %xmm0, -0xf4(%ebp)\n"
        "movss -0x148(%ebp), %xmm2\n" /* line 3198 */
        "mulss %xmm2, %xmm1\n"
        "pxor %xmm5, %xmm5\n"
        "ucomiss %xmm5, %xmm1\n"
        "jbe .Lf180a36_0018105c\n"
        "xorps g_color_table+480, %xmm2\n" /* line 3199 */
        "mulss %xmm2, %xmm3\n"
        "mulss lit4_002ed6a8, %xmm3\n" /* 16.0f */
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0xf4(%ebp)\n"
        ".Lf180a36_0018105c:\n"
        "movl $0, -0x84(%ebp)\n" /* line 3201 | angles */
        "movss -0x28(%ebp), %xmm3\n" /* line 3202 */
        "movaps %xmm3, %xmm0\n"
        "mulss lit4_002ed92c, %xmm0\n" /* -1.2000000476837158f */
        "movss %xmm0, -0x80(%ebp)\n"
        "movss lit4_002ed6f4, %xmm6\n" /* line 3203 | 0.30000001192092896f */
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "movss 0xe8(%esi), %xmm0\n" /* line 3205 */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf180a36_00181225\n"
        "jp .Lf180a36_00181225\n"
        "ucomiss 0xec(%esi), %xmm1\n"
        "jp .Lf180a36_00181225\n"
        "jne .Lf180a36_00181225\n"
        ".Lf180a36_001810bd:\n"
        "movl $0, -0x78(%ebp)\n" /* line 3208 */
        "movss -0x2c(%ebp), %xmm1\n" /* line 3209 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "movaps %xmm3, %xmm2\n"
        "mulss lit4_002ed930, %xmm2\n" /* -0.20000000298023224f */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "mulss lit4_002ed724, %xmm3\n" /* line 3210 | 0.20000000298023224f */
        "movss %xmm3, -0x70(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 3212 | vTorsoAngles */
        "movl %eax, -0x6c(%ebp)\n"
        "mulss lit4_002ed7f0, %xmm1\n" /* line 3213 | 0.800000011920929f */
        "addss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "movss %xmm2, -0x64(%ebp)\n" /* line 3214 */
        "jmp .Lf180a36_00180c40\n"
        ".Lf180a36_00181117:\n"
        "movss 0x3b8(%ebx), %xmm1\n" /* line 3140 | i */
        "movss %xmm1, -0x30(%ebp)\n" /* vTorsoAngles */
        "andb $8, %cl\n" /* line 3143 */
        "je .Lf180a36_00180aac\n"
        "movss %xmm1, (%esp)\n" /* line 3145 */
        "movss %xmm0, -0x128(%ebp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x16c(%ebp)\n"
        "movss -0x16c(%ebp), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* vTorsoAngles */
        "movss -0x128(%ebp), %xmm0\n" /* line 3146 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf180a36_00181332\n"
        "mulss lit4_002ed5d8, %xmm1\n" /* line 3147 | 0.5f */
        "movss %xmm1, -0x30(%ebp)\n" /* vTorsoAngles */
        "jmp .Lf180a36_00180aac\n"
        ".Lf180a36_00181175:\n"
        "movss -0x84(%ebp), %xmm1\n" /* line 3257 | angles */
        "movss %xmm1, -0x104(%ebp)\n"
        "movl 0xec(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0x104(%ebp), %xmm5\n"
        "addss -0xfc(%ebp), %xmm5\n"
        "movss %xmm5, -0x84(%ebp)\n" /* angles */
        "movss lit4_002ed5d8, %xmm5\n" /* 0.5f */
        "movss -0x28(%ebp), %xmm3\n"
        "movss -0x2c(%ebp), %xmm2\n"
        "movss lit4_002ed724, %xmm7\n" /* 0.20000000298023224f */
        "movss -0x30(%ebp), %xmm1\n" /* vTorsoAngles */
        "movss lit4_002ed71c, %xmm4\n" /* 0.4000000059604645f */
        "jmp .Lf180a36_00180bee\n"
        /* } scope */
        /* { scope 2: radians */
        /* { scope 3 */
        ".Lf180a36_001811e3:\n"
        "movss -0x110(%ebp), %xmm6\n" /* line 3309 */
        "ucomiss %xmm1, %xmm6\n"
        "jbe .Lf180a36_001811fe\n"
        "subss %xmm3, %xmm0\n" /* line 3311 */
        "movss %xmm0, -4(%eax)\n"
        "jmp .Lf180a36_00180dc9\n"
        ".Lf180a36_001811fe:\n"
        "movss %xmm2, -4(%eax)\n" /* line 3315 */
        "jmp .Lf180a36_00180dc9\n"
        /* } scope */
        /* } scope */
        /* { scope 2: radians */
        /* { scope 3 */
        ".Lf180a36_00181208:\n"
        "ucomiss %xmm1, %xmm5\n" /* line 3309 */
        "jbe .Lf180a36_0018121b\n"
        "subss %xmm3, %xmm0\n" /* line 3311 */
        "movss %xmm0, -4(%eax)\n"
        "jmp .Lf180a36_00180e76\n"
        ".Lf180a36_0018121b:\n"
        "movss %xmm2, -4(%eax)\n" /* line 3315 */
        "jmp .Lf180a36_00180e76\n"
        /* } scope */
        /* } scope */
        /* { scope 2: radians */
        ".Lf180a36_00181225:\n"
        "movss -0x84(%ebp), %xmm5\n" /* line 3206 | angles */
        "movss %xmm5, -0xec(%ebp)\n"
        "movl 0xec(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x100(%ebp)\n"
        "movss -0xec(%ebp), %xmm6\n"
        "addss -0x100(%ebp), %xmm6\n"
        "movss %xmm6, -0x84(%ebp)\n" /* angles */
        "movss -0x28(%ebp), %xmm3\n"
        "movss lit4_002ed6f4, %xmm6\n" /* 0.30000001192092896f */
        "jmp .Lf180a36_001810bd\n"
        ".Lf180a36_00181279:\n"
        "movl $0x60, 8(%esp)\n" /* line 3120 */
        "movl $0, 4(%esp)\n"
        "leal -0xe4(%ebp), %eax\n" /* info */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "jmp .Lf180a36_00180d52\n"
        ".Lf180a36_0018129c:\n"
        "movss lit4_002ed5d8, %xmm0\n" /* line 3189 | 0.5f */
        "mulss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "jmp .Lf180a36_00180f6f\n"
        ".Lf180a36_001812b3:\n"
        "pxor %xmm1, %xmm1\n" /* line 3174 */
        "ucomiss %xmm1, %xmm2\n"
        "ja .Lf180a36_00180ef4\n"
        "movaps %xmm2, %xmm6\n" /* line 3177 */
        "mulss lit4_002ed920, %xmm6\n" /* -5.0f */
        "pxor %xmm0, %xmm0\n"
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0xf4(%ebp)\n"
        "jmp .Lf180a36_00180b3a\n"
        ".Lf180a36_001812e0:\n"
        "testb $4, %al\n" /* line 3220 */
        "je .Lf180a36_001812ed\n"
        "ucomiss %xmm0, %xmm2\n" /* line 3222 */
        "ja .Lf180a36_00180b60\n"
        ".Lf180a36_001812ed:\n"
        "movss lit4_002ed7f8, %xmm0\n" /* line 3242 | 1.25f */
        "movss -0x28(%ebp), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "mulss -0x34(%ebp), %xmm0\n" /* line 3243 */
        "movss %xmm0, -0x34(%ebp)\n"
        "jmp .Lf180a36_00180b60\n"
        ".Lf180a36_00181312:\n"
        "movaps %xmm2, %xmm6\n" /* line 3170 */
        "mulss lit4_002ed91c, %xmm6\n" /* -12.5f */
        "pxor %xmm0, %xmm0\n"
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0xf4(%ebp)\n"
        "jmp .Lf180a36_00180b3a\n"
        ".Lf180a36_00181332:\n"
        "mulss lit4_002ed604, %xmm1\n" /* line 3149 | 0.25f */
        "movss %xmm1, -0x30(%ebp)\n" /* vTorsoAngles */
        "jmp .Lf180a36_00180aac\n"
    );
}

/* line 2579 */
static __attribute__((naked))
void BG_RunLerpFrameRate(clientInfo_t *ci, entityState_t *es)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2579 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl %edx, %esi\n" /* lf */
        /* { scope 1: anim, fStartTime, bLegsAnim, pAnimTree, ... */
        "movl 0x14(%edx), %eax\n" /* line 2592 */
        "movl %eax, -0x48(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf181346_0018136b\n"
        "testb $2, 0x50(%eax)\n"
        "jne .Lf181346_00181621\n"
        ".Lf181346_0018136b:\n"
        "movb $0, -0x49(%ebp)\n"
        "movl -0x50(%ebp), %edx\n" /* line 2596 */
        "movl 0x4a4(%edx), %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* pAnimTree */
        "movl 0x10(%esi), %ebx\n" /* line 2600 | lf, anim */
        "movl %ebx, -0x44(%ebp)\n" /* anim */
        "cmpl %ecx, %ebx\n" /* newAnimation, anim */
        "je .Lf181346_0018163f\n"
        ".Lf181346_00181389:\n"
        "movl 8(%ebp), %edi\n" /* line 2602 | es */
        "movl 8(%edi), %edi\n"
        "shrl $0x13, %edi\n"
        "andl $1, %edi\n"
        "movl %edi, -0x40(%ebp)\n"
        /* { scope 2: index, animNum */
        "movl -0x50(%ebp), %eax\n" /* line 2422 */
        "addl $0x380, %eax\n"
        "cmpl %eax, %esi\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* bLegsAnim */
        "movl -0x48(%ebp), %ebx\n" /* animIndex */
        "testl %ebx, %ebx\n" /* animIndex */
        "sete -0x19(%ebp)\n"
        "movl %ecx, 0x10(%esi)\n" /* line 2427 */
        "andb $0xfd, %ch\n" /* line 2428 */
        "movl %ecx, -0x20(%ebp)\n" /* animNum */
        "movl bgs, %eax\n" /* line 2430 */
        "movl 0xc000(%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf181346_001818ad\n"
        ".Lf181346_001813d0:\n"
        "movl -0x50(%ebp), %edx\n" /* line 2433 */
        "movl 0x4a4(%edx), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* pAnimTree */
        "movl 0xb3bb4(%eax), %ecx\n" /* line 2434 */
        "movl %ecx, -0x24(%ebp)\n" /* pXAnims */
        "movl -0x20(%ebp), %ecx\n" /* line 2436 | animNum */
        "testl %ecx, %ecx\n"
        "jne .Lf181346_00181666\n"
        "movl $0, 0x14(%esi)\n" /* line 2453 */
        "movl $0xc8, 0x18(%esi)\n" /* line 2454 */
        "movl $0, -0x34(%ebp)\n" /* anim */
        ".Lf181346_00181405:\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 2458 */
        "jne .Lf181346_00181775\n"
        ".Lf181346_0018140f:\n"
        "movl -0x34(%ebp), %eax\n" /* line 2464 | anim */
        "testl %eax, %eax\n"
        "je .Lf181346_00181b9a\n"
        "movl 0x18(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf181346_00181bc3\n"
        "movl $0xffffffff, %ecx\n"
        "pxor %xmm0, %xmm0\n"
        ".Lf181346_0018142e:\n"
        "movl -0x50(%ebp), %eax\n" /* line 2475 */
        "movl 0x4ac(%eax), %edx\n"
        "movl bgs, %eax\n"
        "subl 0xb3bdc(%eax), %edx\n"
        "cmpl %edx, %ecx\n" /* line 2476 */
        "cmovgel %ecx, %edx\n"
        "cmpl 0x18(%esi), %edx\n" /* line 2479 */
        "jle .Lf181346_0018144f\n"
        "movl %edx, 0x18(%esi)\n" /* line 2480 */
        ".Lf181346_0018144f:\n"
        "movl -0x34(%ebp), %edi\n" /* line 2484 | anim */
        "testl %edi, %edi\n"
        "je .Lf181346_00181469\n"
        "movl -0x34(%ebp), %edx\n" /* anim */
        "ucomiss 0x44(%edx), %xmm0\n"
        "jp .Lf181346_0018196b\n"
        "jne .Lf181346_0018196b\n"
        ".Lf181346_00181469:\n"
        "movss %xmm0, -0x30(%ebp)\n" /* line 2506 | fStartTime */
        ".Lf181346_0018146e:\n"
        "movl -0x48(%ebp), %ebx\n" /* line 2512 | animIndex */
        "testl %ebx, %ebx\n" /* animIndex */
        "je .Lf181346_0018149d\n"
        "movl -0x44(%ebp), %ebx\n" /* animIndex */
        "andb $0xfd, %bh\n" /* animIndex */
        ".Lf181346_0018147b:\n"
        "cvtsi2ssl 0x18(%esi), %xmm0\n" /* line 2513 */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* animIndex */
        "movl -0x28(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimClearGoalWeight\n"
        ".Lf181346_0018149d:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 2516 | animNum */
        "testl %ecx, %ecx\n"
        "je .Lf181346_001817f2\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2519 | bLegsAnim */
        "testl %edx, %edx\n"
        "je .Lf181346_001818d3\n"
        "movl -0x34(%ebp), %ebx\n" /* line 2526 | anim, animIndex */
        "testb $0x40, 0x50(%ebx)\n" /* animIndex */
        "jne .Lf181346_001818f7\n"
        ".Lf181346_001814c0:\n"
        "pxor %xmm0, %xmm0\n" /* line 2543 */
        "ucomiss 0x44(%ebx), %xmm0\n" /* animIndex */
        "jp .Lf181346_00181a33\n"
        "jne .Lf181346_00181a33\n"
        ".Lf181346_001814d4:\n"
        "xorl %ebx, %ebx\n" /* animIndex */
        ".Lf181346_001814d6:\n"
        "xorl %eax, %eax\n" /* line 2544 */
        "cmpl $0, -0x2c(%ebp)\n" /* bLegsAnim */
        "sete %al\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x34(%ebp), %edx\n" /* anim */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "cvtsi2ssl 0x18(%esi), %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %ecx\n" /* animNum */
        "movl %ecx, 4(%esp)\n"
        "movl -0x28(%ebp), %edi\n" /* pAnimTree */
        "movl %edi, (%esp)\n"
        "calll XAnimSetCompleteGoalWeight\n"
        "testb %bl, %bl\n" /* line 2547 | animIndex */
        "jne .Lf181346_00181a14\n"
        ".Lf181346_0018152f:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2551 | bLegsAnim */
        "testl %eax, %eax\n"
        "je .Lf181346_00181a6a\n"
        /* } scope */
        ".Lf181346_0018153a:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2607 | animNum */
        "testl %eax, %eax\n"
        "je .Lf181346_0018165b\n"
        ".Lf181346_00181545:\n"
        "movl 0x14(%esi), %ebx\n" /* line 2611 | lf, anim */
        "pxor %xmm0, %xmm0\n" /* line 2612 */
        "ucomiss 0x44(%ebx), %xmm0\n" /* anim */
        "jp .Lf181346_00181558\n"
        "je .Lf181346_00181790\n"
        ".Lf181346_00181558:\n"
        "movl 0x2c(%esi), %edx\n" /* lf */
        "testl %edx, %edx\n"
        "je .Lf181346_00181790\n"
        "movl bgs, %eax\n" /* line 2615 */
        "cmpl 0xb3be0(%eax), %edx\n"
        "je .Lf181346_001817c3\n"
        "cmpb $0, -0x49(%ebp)\n" /* line 2617 */
        "je .Lf181346_00181d0e\n"
        "movss 0x24(%esi), %xmm1\n" /* line 54 */
        "movl 8(%ebp), %edi\n" /* es */
        "subss 0x20(%edi), %xmm1\n"
        "andps g_color_table+496, %xmm1\n"
        "leal 0x18(%edi), %ecx\n"
        "movl %ecx, -0x64(%ebp)\n"
        "leal 0x1c(%esi), %edi\n"
        ".Lf181346_0018159b:\n"
        "movl 0xb3be0(%eax), %eax\n" /* line 2627 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "divss %xmm0, %xmm1\n"
        "divss 0x44(%ebx), %xmm1\n" /* anim */
        "movss %xmm1, 0x28(%esi)\n" /* lf */
        "movl bgs, %eax\n" /* line 2628 */
        "movl 0xb3be0(%eax), %edx\n"
        "movl %edx, 0x2c(%esi)\n" /* lf */
        "movl 8(%ebp), %edx\n" /* line 199 | es */
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 0x1c(%esi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edi)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edi)\n"
        "movss 0x28(%esi), %xmm0\n" /* line 2634 | lf */
        "ucomiss lit4_002ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "jae .Lf181346_00181c64\n"
        "jp .Lf181346_00181c64\n"
        "ucomiss lit4_002ed738, %xmm0\n" /* line 2637 | 0.009999999776482582f */
        "jae .Lf181346_00181cb6\n"
        "jp .Lf181346_00181cb6\n"
        "cmpb $0, -0x49(%ebp)\n"
        "je .Lf181346_00181cb6\n"
        "movl $0, 0x28(%esi)\n" /* line 2638 | lf */
        "jmp .Lf181346_001817c3\n"
        ".Lf181346_00181621:\n"
        "movb $1, -0x49(%ebp)\n" /* line 2592 */
        "movl -0x50(%ebp), %edx\n" /* line 2596 */
        "movl 0x4a4(%edx), %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* pAnimTree */
        "movl 0x10(%esi), %ebx\n" /* line 2600 | lf, anim */
        "movl %ebx, -0x44(%ebp)\n" /* anim */
        "cmpl %ecx, %ebx\n" /* newAnimation, anim */
        "jne .Lf181346_00181389\n"
        ".Lf181346_0018163f:\n"
        "movl -0x48(%ebp), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf181346_00181c44\n"
        "andb $0xfd, %bh\n" /* anim */
        "movl %ebx, -0x20(%ebp)\n" /* anim, animNum */
        "movl -0x20(%ebp), %eax\n" /* line 2607 | animNum */
        "testl %eax, %eax\n"
        "jne .Lf181346_00181545\n"
        /* } scope */
        ".Lf181346_0018165b:\n"
        "addl $0x9c, %esp\n" /* line 2686 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim, fStartTime, bLegsAnim, pAnimTree, ... */
        /* { scope 2: index, animNum */
        ".Lf181346_00181666:\n"
        "movl -0x20(%ebp), %ebx\n" /* line 2438 | animNum, animIndex */
        "leal (%ebx, %ebx, 2), %ebx\n" /* animIndex */
        "shll $5, %ebx\n" /* animIndex */
        "movl %ebx, -0x54(%ebp)\n" /* animIndex */
        "addl %ebx, %eax\n" /* animIndex */
        "movl %eax, -0x34(%ebp)\n" /* anim */
        "movl %eax, 0x14(%esi)\n" /* line 2440 */
        "movl 0x40(%eax), %eax\n" /* line 2441 */
        "movl %eax, 0x18(%esi)\n"
        "movl globalScriptData, %ecx\n" /* line 2267 */
        "movl -0x20(%ebp), %eax\n" /* animNum */
        "cmpl 0xc000(%ecx), %eax\n"
        "jae .Lf181346_00181b78\n"
        ".Lf181346_00181695:\n"
        "movl 0x54(%ecx, %ebx), %eax\n" /* line 2270 */
        "andl $0xc4, %eax\n"
        "movl 0x58(%ecx, %ebx), %edx\n"
        "andl $0x180, %edx\n"
        "orl %edx, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl -0x44(%ebp), %edi\n" /* line 2323 */
        "andl $0xfffffdff, %edi\n"
        "movl %edi, -0x80(%ebp)\n" /* index */
        /* { scope 3 */
        "cmpl 0xc000(%ecx), %edi\n" /* line 2267 */
        "jae .Lf181346_00181b56\n"
        "movl %edi, %eax\n"
        ".Lf181346_001816cd:\n"
        "leal (%eax, %eax, 2), %ebx\n" /* line 2270 */
        "shll $5, %ebx\n"
        "movl 0x54(%ecx, %ebx), %eax\n"
        "andl $0xc4, %eax\n"
        "movl 0x58(%ecx, %ebx), %edx\n"
        "andl $0x180, %edx\n"
        "orl %edx, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x20(%ebp), %edx\n" /* line 2267 | animNum */
        "cmpl 0xc000(%ecx), %edx\n"
        "jae .Lf181346_00181b37\n"
        ".Lf181346_00181700:\n"
        "movl -0x54(%ebp), %edi\n" /* line 2270 */
        "movl 0x54(%ecx, %edi), %eax\n"
        "andl $0x308, %eax\n"
        "xorl %edx, %edx\n"
        "orl %edx, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        /* } scope */
        "movl -0x80(%ebp), %eax\n" /* line 2267 | index */
        "cmpl 0xc000(%ecx), %eax\n"
        "jae .Lf181346_00181b18\n"
        ".Lf181346_00181728:\n"
        "movl 0x54(%ecx, %ebx), %eax\n" /* line 2268 */
        "andl $0x308, %eax\n"
        "xorl %edx, %edx\n"
        "orl %edx, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2447 | bLegsAnim */
        "testl %edx, %edx\n"
        "je .Lf181346_00181405\n"
        "movl -0x5c(%ebp), %edx\n"
        "cmpl %edx, -0x58(%ebp)\n"
        "je .Lf181346_00181c56\n"
        ".Lf181346_00181752:\n"
        "movl bgs, %eax\n" /* line 2448 */
        "movl 0xb3bdc(%eax), %eax\n"
        "addl $0x190, %eax\n"
        "movl -0x50(%ebp), %ecx\n"
        "movl %eax, 0x4ac(%ecx)\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 2458 */
        "je .Lf181346_0018140f\n"
        ".Lf181346_00181775:\n"
        "movl -0x2c(%ebp), %eax\n" /* bLegsAnim */
        "testl %eax, %eax\n"
        "je .Lf181346_0018140f\n"
        "movl $0, 0x18(%esi)\n" /* line 2460 */
        "pxor %xmm0, %xmm0\n"
        "jmp .Lf181346_0018144f\n"
        /* } scope */
        ".Lf181346_00181790:\n"
        "movl $0x3f800000, 0x28(%esi)\n" /* line 2675 | lf */
        "movl bgs, %eax\n" /* line 2677 */
        "movl 0xb3be0(%eax), %eax\n"
        "movl %eax, 0x2c(%esi)\n" /* lf */
        "leal 0x1c(%esi), %ecx\n" /* line 2680 | lf, to */
        "movl 8(%ebp), %edx\n" /* es, from */
        "addl $0x18, %edx\n" /* from */
        /* { scope 2: index, animNum */
        "movl 8(%ebp), %ebx\n" /* line 199 | es */
        "movl 0x18(%ebx), %eax\n"
        "movl %eax, 0x1c(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lf181346_001817c3:\n"
        "movl 0x10(%esi), %ebx\n" /* line 2684 | lf, anim */
        "testl %ebx, %ebx\n" /* anim */
        "je .Lf181346_0018165b\n"
        "movl 0x28(%esi), %eax\n" /* line 2685 | lf */
        "movl %eax, 8(%esp)\n"
        "andb $0xfd, %bh\n" /* anim */
        "movl %ebx, 4(%esp)\n" /* anim */
        "movl -0x3c(%ebp), %edi\n" /* pAnimTree */
        "movl %edi, (%esp)\n"
        "calll XAnimSetAnimRate\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 2686 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim, fStartTime, bLegsAnim, pAnimTree, ... */
        /* { scope 2: index, animNum */
        ".Lf181346_001817f2:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2557 | bLegsAnim */
        "testl %eax, %eax\n"
        "jne .Lf181346_0018165b\n"
        "movl $0, 0x1c(%esp)\n" /* line 2559 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, %ebx\n" /* animIndex */
        "movl %ebx, 0x10(%esp)\n" /* animIndex */
        "cvtsi2ssl 0x18(%esi), %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl bgs, %eax\n"
        "movzwl 0xb3bb8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetCompleteGoalWeight\n"
        "movl $0, 0x1c(%esp)\n" /* line 2560 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* animIndex */
        "cvtsi2ssl 0x18(%esi), %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* animIndex */
        "movl bgs, %eax\n"
        "movzwl 0xb3bba(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimSetCompleteGoalWeight\n"
        /* } scope */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 2686 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim, fStartTime, bLegsAnim, pAnimTree, ... */
        /* { scope 2: index, animNum */
        ".Lf181346_001818ad:\n"
        "movl %ecx, 0xc(%esp)\n" /* line 2431 */
        "movl %edx, 8(%esp)\n"
        "movl $str_002aeefc, 4(%esp)\n" /* "Player animation index out of range (%i): %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl bgs, %eax\n"
        "jmp .Lf181346_001813d0\n"
        ".Lf181346_001818d3:\n"
        "movl -0x50(%ebp), %ecx\n" /* line 2521 */
        "movl $0, 0x3f4(%ecx)\n"
        "movl $1, 0x3f8(%ecx)\n" /* line 2522 */
        "movl -0x34(%ebp), %ebx\n" /* line 2526 | anim, animIndex */
        "testb $0x40, 0x50(%ebx)\n" /* animIndex */
        "je .Lf181346_001814c0\n"
        ".Lf181346_001818f7:\n"
        "movl -0x20(%ebp), %edi\n" /* line 2528 | animNum */
        "movl %edi, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimIsLooped\n"
        "testb %al, %al\n"
        "jne .Lf181346_00181c99\n"
        ".Lf181346_00181911:\n"
        "movl -0x40(%ebp), %eax\n" /* line 2531 */
        "testl %eax, %eax\n"
        "je .Lf181346_00181be5\n"
        "movl $0, 0x1c(%esp)\n" /* line 2533 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "cvtsi2ssl 0x18(%esi), %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %edx\n" /* animNum */
        "movl %edx, 4(%esp)\n"
        "movl -0x28(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimSetCompleteGoalWeight\n"
        "jmp .Lf181346_0018152f\n"
        ".Lf181346_0018196b:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 2486 | animNum */
        "movl %ecx, 4(%esp)\n"
        "movl -0x24(%ebp), %ebx\n" /* pXAnims, animIndex */
        "movl %ebx, (%esp)\n" /* animIndex */
        "movss %xmm0, -0x78(%ebp)\n"
        "calll XAnimIsLooped\n"
        "testb %al, %al\n"
        "movss -0x78(%ebp), %xmm0\n"
        "je .Lf181346_00181bdc\n"
        "movl -0x44(%ebp), %ebx\n" /* line 2488 | animIndex */
        "andb $0xfd, %bh\n" /* animIndex */
        "cmpb $0, -0x19(%ebp)\n" /* line 2491 */
        "jne .Lf181346_001819ae\n"
        "movl -0x48(%ebp), %edi\n"
        "ucomiss 0x44(%edi), %xmm0\n"
        "jp .Lf181346_00181ce0\n"
        "jne .Lf181346_00181ce0\n"
        ".Lf181346_001819ae:\n"
        "movl %ebx, 4(%esp)\n" /* line 2497 | animIndex */
        "movl -0x24(%ebp), %edx\n" /* pXAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimIsPrimitive\n"
        "testb %al, %al\n"
        "jne .Lf181346_00181cc2\n"
        "movl $0x3e8, %edx\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        ".Lf181346_001819d2:\n"
        "movl bgs, %eax\n" /* line 2505 */
        "movl 0xb3bdc(%eax), %eax\n"
        "movl %edx, %edi\n"
        "cltd\n"
        "idivl %edi\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movl -0x50(%ebp), %eax\n"
        "cvtsi2ssl 8(%eax), %xmm0\n"
        "mulss lit4_002ed77c, %xmm0\n" /* 0.36000001430511475f */
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n" /* line 2506 */
        "cvtsi2ssl %eax, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* fStartTime */
        "jmp .Lf181346_0018146e\n"
        ".Lf181346_00181a14:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 2548 | fStartTime */
        "movss %xmm0, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* animNum */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll XAnimSetTime\n"
        "jmp .Lf181346_0018152f\n"
        ".Lf181346_00181a33:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2543 | animNum */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x38(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf181346_001814d4\n"
        "jp .Lf181346_001814d4\n"
        "movl $1, %ebx\n" /* animIndex */
        "jmp .Lf181346_001814d6\n"
        ".Lf181346_00181a6a:\n"
        "movl $0, 0x1c(%esp)\n" /* line 2553 */
        "movl -0x34(%ebp), %edx\n" /* anim */
        "movl 0x5c(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, %ebx\n" /* animIndex */
        "movl %ebx, 0x10(%esp)\n" /* animIndex */
        "cvtsi2ssl 0x18(%esi), %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* animIndex */
        "movl bgs, %eax\n"
        "movzwl 0xb3bb8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimSetCompleteGoalWeight\n"
        "movl $0, 0x1c(%esp)\n" /* line 2554 */
        "movl -0x34(%ebp), %edi\n" /* anim */
        "movl 0x5c(%edi), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* animIndex */
        "cvtsi2ssl 0x18(%esi), %xmm0\n"
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3c23d70a, 8(%esp)\n"
        "movl bgs, %eax\n"
        "movzwl 0xb3bba(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetCompleteGoalWeight\n"
        "jmp .Lf181346_0018153a\n"
        ".Lf181346_00181b18:\n"
        "movl $str_002aeecc, 4(%esp)\n" /* line 2268 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl globalScriptData, %ecx\n"
        "jmp .Lf181346_00181728\n"
        /* { scope 3 */
        ".Lf181346_00181b37:\n"
        "movl $str_002aeecc, 4(%esp)\n" /* "BG_GetAnimationForIndex: index out of bounds" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl globalScriptData, %ecx\n"
        "jmp .Lf181346_00181700\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181346_00181b56:\n"
        "movl $str_002aeecc, 4(%esp)\n" /* "BG_GetAnimationForIndex: index out of bounds" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl globalScriptData, %ecx\n"
        "movl -0x80(%ebp), %eax\n" /* index */
        "jmp .Lf181346_001816cd\n"
        /* } scope */
        ".Lf181346_00181b78:\n"
        "movl $str_002aeecc, 4(%esp)\n" /* "BG_GetAnimationForIndex: index out of bounds" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl globalScriptData, %ecx\n"
        "movl -0x54(%ebp), %ebx\n"
        "jmp .Lf181346_00181695\n"
        ".Lf181346_00181b9a:\n"
        "pxor %xmm0, %xmm0\n"
        ".Lf181346_00181b9e:\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 2468 */
        "jne .Lf181346_00181baf\n"
        "movl -0x48(%ebp), %edi\n"
        "ucomiss 0x44(%edi), %xmm0\n"
        "jp .Lf181346_00181bb9\n"
        "jne .Lf181346_00181bb9\n"
        ".Lf181346_00181baf:\n"
        "movl $0xaa, %ecx\n"
        "jmp .Lf181346_0018142e\n"
        ".Lf181346_00181bb9:\n"
        "movl $0xfa, %ecx\n"
        "jmp .Lf181346_0018142e\n"
        ".Lf181346_00181bc3:\n"
        "pxor %xmm0, %xmm0\n" /* line 2466 */
        "movl -0x34(%ebp), %ebx\n" /* anim, animIndex */
        "ucomiss 0x44(%ebx), %xmm0\n" /* animIndex */
        "jp .Lf181346_00181bd2\n"
        "je .Lf181346_00181b9e\n"
        ".Lf181346_00181bd2:\n"
        "movl $0x78, %ecx\n"
        "jmp .Lf181346_0018142e\n"
        ".Lf181346_00181bdc:\n"
        "pxor %xmm0, %xmm0\n"
        "jmp .Lf181346_00181469\n"
        ".Lf181346_00181be5:\n"
        "movl $0, 0x1c(%esp)\n" /* line 2537 */
        "movl $0, 0x18(%esp)\n"
        "movl $0x3f800000, %ebx\n" /* animIndex */
        "movl %ebx, 0x14(%esp)\n" /* animIndex */
        "movl $0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* animIndex */
        "movl bgs, %eax\n"
        "movzwl 0xb3bcc(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %edi\n" /* animNum */
        "movl %edi, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetCompleteGoalWeightKnobAll\n"
        "movl %ebx, 8(%esp)\n" /* line 2538 | animIndex */
        "movl %edi, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetTime\n"
        "jmp .Lf181346_0018152f\n"
        /* } scope */
        ".Lf181346_00181c44:\n"
        "testl $0xfffffdff, -0x44(%ebp)\n" /* line 2600 */
        "jne .Lf181346_00181389\n"
        "jmp .Lf181346_0018165b\n"
        /* { scope 2: index, animNum */
        ".Lf181346_00181c56:\n"
        "cmpl %eax, -0x60(%ebp)\n" /* line 2447 */
        "jne .Lf181346_00181752\n"
        "jmp .Lf181346_00181405\n"
        /* } scope */
        ".Lf181346_00181c64:\n"
        "ucomiss lit4_002ed62c, %xmm0\n" /* line 2642 | 2.0f */
        "jbe .Lf181346_001817c3\n"
        "testb $2, 0x50(%ebx)\n" /* line 2644 | anim */
        "jne .Lf181346_00181d3e\n"
        "movss 0x44(%ebx), %xmm1\n" /* line 2647 | anim */
        "ucomiss lit4_002ed93c, %xmm1\n" /* 150.0f */
        "jbe .Lf181346_00181d57\n"
        "movl $0x40000000, 0x28(%esi)\n" /* line 2649 | lf */
        "jmp .Lf181346_001817c3\n"
        /* { scope 2: index, animNum */
        ".Lf181346_00181c99:\n"
        "movl %ebx, 8(%esp)\n" /* line 2529 | animIndex */
        "movl $str_002aef2c, 4(%esp)\n" /* "death animation '%s' is looping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf181346_00181911\n"
        /* } scope */
        ".Lf181346_00181cb6:\n"
        "movl $0x3dcccccd, 0x28(%esi)\n" /* line 2640 | lf */
        "jmp .Lf181346_001817c3\n"
        /* { scope 2: index, animNum */
        ".Lf181346_00181cc2:\n"
        "movl %ebx, 4(%esp)\n" /* line 2499 | animIndex */
        "movl -0x24(%ebp), %ebx\n" /* pXAnims, animIndex */
        "movl %ebx, (%esp)\n" /* animIndex */
        "calll XAnimGetLengthMsec\n"
        "leal 0xc8(%eax), %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "jmp .Lf181346_001819d2\n"
        ".Lf181346_00181ce0:\n"
        "movl %ebx, 4(%esp)\n" /* line 2491 | animIndex */
        "movl -0x24(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimIsLooped\n"
        "testb %al, %al\n"
        "je .Lf181346_001819ae\n"
        "movl %ebx, 4(%esp)\n" /* line 2493 | animIndex */
        "movl -0x28(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetTime\n"
        "fstps -0x30(%ebp)\n" /* fStartTime */
        "jmp .Lf181346_0018147b\n"
        /* } scope */
        ".Lf181346_00181d0e:\n"
        "movl 8(%ebp), %edi\n" /* line 2620 | es */
        "addl $0x18, %edi\n"
        "movl %edi, -0x64(%ebp)\n"
        "movl %edi, 4(%esp)\n"
        "leal 0x1c(%esi), %edi\n" /* lf */
        "movl %edi, (%esp)\n"
        "calll Vec3Distance\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm1\n"
        "movl bgs, %eax\n"
        "movl 0x2c(%esi), %edx\n" /* lf */
        "movl -0x64(%ebp), %ecx\n" /* newAnimation */
        "jmp .Lf181346_0018159b\n"
        ".Lf181346_00181d3e:\n"
        "ucomiss lit4_002ed608, %xmm0\n" /* line 2664 | 4.0f */
        "jbe .Lf181346_001817c3\n"
        "movl $0x40800000, 0x28(%esi)\n" /* line 2666 | lf */
        "jmp .Lf181346_001817c3\n"
        ".Lf181346_00181d57:\n"
        "ucomiss lit4_002ed694, %xmm1\n" /* line 2651 | 20.0f */
        "jae .Lf181346_00181d7b\n"
        "jp .Lf181346_00181d7b\n"
        "ucomiss lit4_002ed720, %xmm0\n" /* line 2653 | 3.0f */
        "jbe .Lf181346_001817c3\n"
        "movl $0x40400000, 0x28(%esi)\n" /* line 2654 | lf */
        "jmp .Lf181346_001817c3\n"
        /* { scope 2: index, animNum */
        ".Lf181346_00181d7b:\n"
        "subss lit4_002ed694, %xmm1\n" /* line 2658 | 20.0f, fScaleMax */
        "divss lit4_002ed940, %xmm1\n" /* -130.0f, fScaleMax */
        "addss lit4_002ed720, %xmm1\n" /* 3.0f, fScaleMax */
        "ucomiss %xmm1, %xmm0\n" /* line 2660 */
        "jbe .Lf181346_001817c3\n"
        "movss %xmm1, 0x28(%esi)\n" /* line 2661 | lf */
        "jmp .Lf181346_001817c3\n"
    );
}

/* line 3383 */
__attribute__((naked))
void BG_PlayerAnimation(const struct DObj_s *pDObj, entityState_t *es, clientInfo_t *ci)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3383 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* es */
        "movl %eax, -0x34(%ebp)\n" /* es */
        "movl 0x10(%ebp), %edx\n" /* ci */
        "movl %edx, -0x38(%ebp)\n" /* ci */
        /* { scope 1: moveDir */
        /* { scope 2 */
        "movl 0x3e4(%edx), %eax\n" /* line 2839 */
        "movl %eax, (%esp)\n"
        "calll GetLeanFraction\n"
        "fstp %st(0)\n"
        "movl -0x38(%ebp), %ecx\n" /* line 2840 | ci */
        "movss 0x3e0(%ecx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* moveDir */
        "movss 0x3e8(%ecx), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x24(%ebp)\n"
        "movl 0x3ec(%ecx), %eax\n" /* line 200 */
        "movl %eax, (%esp)\n" /* line 2843 */
        "calll AngleMod\n"
        "fstps -0x1c(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* line 2858 | es */
        "movl 8(%eax), %edx\n"
        "testb $3, %dh\n"
        "je .Lf181da6_001823b7\n"
        "movl -0x38(%ebp), %edx\n" /* line 2860 | ci */
        "movl $1, 0x3b4(%edx)\n"
        "movl $1, 0x3bc(%edx)\n" /* line 2861 */
        "movl $1, 0x384(%edx)\n" /* line 2862 */
        "movl 8(%eax), %edx\n"
        ".Lf181da6_00181e2c:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 2897 | moveDir */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "testl $0x20000, %edx\n" /* line 2900 */
        "jne .Lf181da6_00181e5f\n"
        "movl -0x38(%ebp), %eax\n" /* line 2907 | ci */
        "testl $0xc0000, 0x474(%eax)\n"
        "jne .Lf181da6_0018249f\n"
        "testb $0x40, %dh\n" /* line 2914 */
        "je .Lf181da6_001829bd\n"
        ".Lf181da6_00181e5f:\n"
        "movss -0x1c(%ebp), %xmm4\n"
        "movaps %xmm4, %xmm0\n"
        "movss lit4_002ed5f8, %xmm2\n" /* 90.0f */
        "pxor %xmm1, %xmm1\n"
        ".Lf181da6_00181e73:\n"
        "movl -0x38(%ebp), %edx\n" /* line 2942 | ci */
        "addl $0x3b4, %edx\n"
        "movl -0x38(%ebp), %ecx\n" /* ci */
        "addl $0x3b0, %ecx\n"
        "movl %ecx, -0x44(%ebp)\n"
        "movl imp_bg_swingSpeed, %ebx\n" /* bitNum */
        "movl (%ebx), %ecx\n" /* bitNum */
        "movl -0x44(%ebp), %eax\n"
        "movss 8(%ecx), %xmm3\n"
        "movss %xmm4, -0x58(%ebp)\n"
        "calll BG_SwingAngles\n"
        "movl -0x34(%ebp), %edx\n" /* line 2950 | es */
        "movl 8(%edx), %eax\n"
        "testl $0x20000, %eax\n"
        "movss -0x58(%ebp), %xmm4\n"
        "jne .Lf181da6_00182798\n"
        "testb $8, %al\n" /* line 2955 */
        "je .Lf181da6_00182408\n"
        "movl -0x38(%ebp), %eax\n" /* line 2957 | ci */
        "movl $0, 0x384(%eax)\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 2958 */
        "movss %xmm0, 0x380(%eax)\n"
        "addl $0x380, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        ".Lf181da6_00181ee2:\n"
        "movl -0x34(%ebp), %eax\n" /* line 2977 | es */
        "movl 8(%eax), %edx\n"
        "testb $3, %dh\n"
        "jne .Lf181da6_0018247f\n"
        ".Lf181da6_00181ef1:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2983 | ci */
        "testl $0xc0000, 0x474(%eax)\n"
        "je .Lf181da6_00181f1b\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 2985 */
        "movss %xmm0, 0x3b0(%eax)\n"
        "movss %xmm0, 0x380(%eax)\n" /* line 2986 */
        "movl -0x34(%ebp), %eax\n" /* es */
        "movl 8(%eax), %edx\n"
        ".Lf181da6_00181f1b:\n"
        "testl $0x20000, %edx\n" /* line 2994 */
        "jne .Lf181da6_00181f3b\n"
        "testb $3, %dh\n" /* line 2997 */
        "jne .Lf181da6_00181f3b\n"
        "movl -0x38(%ebp), %ecx\n" /* line 3000 | ci */
        "testl $0xc0000, 0x474(%ecx)\n"
        "je .Lf181da6_00182a03\n"
        ".Lf181da6_00181f3b:\n"
        "pxor %xmm0, %xmm0\n" /* line 3003 */
        "movaps %xmm0, %xmm1\n"
        ".Lf181da6_00181f42:\n"
        "movl -0x38(%ebp), %edx\n" /* line 3011 | ci */
        "addl $0x3bc, %edx\n"
        "movl -0x38(%ebp), %eax\n" /* ci */
        "addl $0x3b8, %eax\n"
        "movss lit4_002ed764, %xmm3\n" /* 0.15000000596046448f */
        "movss lit4_002ed6ec, %xmm2\n" /* 45.0f */
        "calll BG_SwingAngles\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x34(%ebp), %edx\n" /* line 3029 | es */
        "movl 0xc8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %esi\n" /* weaponDef */
        "movl 0x74(%eax), %ebx\n" /* line 3035 | bitNum */
        "movl -0x34(%ebp), %eax\n" /* es */
        "movl 0x90(%eax), %ecx\n" /* client */
        /* { scope 3 */
        "movl animConditionsTable, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf181da6_00182777\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2179 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4058(%eax)\n"
        "movl %edx, %eax\n" /* line 2180 */
        "addl bgs, %eax\n"
        "movl $0, 0xb405c(%eax)\n"
        /* { scope 4 */
        "movl bgs, %eax\n" /* line 812 */
        "leal 0xb4058(%edx, %eax), %edx\n"
        "movl %ebx, %edi\n"
        "sarl $5, %edi\n"
        "andl $0x1f, %ebx\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, (%edx, %edi, 4)\n"
        /* } scope */
        /* } scope */
        ".Lf181da6_00181fe8:\n"
        "movl 0x7c(%esi), %ebx\n" /* line 3037 | weaponDef, bitNum */
        "movl -0x34(%ebp), %eax\n" /* es */
        "movl 0x90(%eax), %ecx\n" /* client */
        /* { scope 3 */
        "movl animConditionsTable+8, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf181da6_001826d3\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2179 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4060(%eax)\n"
        "movl %edx, %eax\n" /* line 2180 */
        "addl bgs, %eax\n"
        "movl $0, 0xb4064(%eax)\n"
        /* { scope 4 */
        "movl bgs, %eax\n" /* line 812 */
        "leal 0xb4060(%edx, %eax), %edx\n"
        "movl %ebx, %esi\n"
        "sarl $5, %esi\n"
        "andl $0x1f, %ebx\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, (%edx, %esi, 4)\n"
        /* } scope */
        /* } scope */
        "movl -0x34(%ebp), %eax\n" /* line 3039 | es */
        "testb $4, 0xa(%eax)\n"
        "je .Lf181da6_001826fc\n"
        ".Lf181da6_00182062:\n"
        "movl 0x90(%eax), %ecx\n" /* line 3040 | client */
        /* { scope 3 */
        "movl animConditionsTable+56, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf181da6_001828df\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4090(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb4094(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $2, 0xb4090(%eax, %edx)\n" /* line 812 */
        /* } scope */
        ".Lf181da6_001820b7:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 3045 | es */
        "testl $0x300, 8(%ecx)\n"
        "je .Lf181da6_0018261d\n"
        "movl 0x90(%ecx), %ecx\n" /* line 3046 | client */
        /* { scope 3 */
        "movl animConditionsTable+16, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf181da6_00182904\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4068(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb406c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $2, 0xb4068(%eax, %edx)\n" /* line 812 */
        /* } scope */
        ".Lf181da6_0018211c:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 3051 | ci, client */
        "movss 0x3e8(%ecx), %xmm0\n"
        "xorl %ebx, %ebx\n" /* bitNum */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "seta %bl\n" /* bitNum */
        "movl -0x34(%ebp), %eax\n" /* es */
        "movl 0x90(%eax), %ecx\n" /* client */
        /* { scope 3 */
        "movl animConditionsTable+32, %esi\n" /* line 2172 */
        "testl %esi, %esi\n"
        "jne .Lf181da6_00182756\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2179 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4078(%eax)\n"
        "movl %edx, %eax\n" /* line 2180 */
        "addl bgs, %eax\n"
        "movl $0, 0xb407c(%eax)\n"
        /* { scope 4 */
        "movl bgs, %esi\n" /* line 812 */
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, 0xb4078(%edx, %esi)\n"
        /* } scope */
        /* } scope */
        ".Lf181da6_00182194:\n"
        "movl -0x34(%ebp), %eax\n" /* line 3053 | es */
        "testb $4, 8(%eax)\n"
        "je .Lf181da6_00182678\n"
        "movl 0x90(%eax), %ecx\n" /* line 3054 | client */
        /* { scope 3 */
        "movl animConditionsTable+40, %ebx\n" /* line 2172 */
        "testl %ebx, %ebx\n"
        "jne .Lf181da6_0018285f\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4080(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb4084(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $2, 0xb4080(%eax, %edx)\n" /* line 812 */
        /* } scope */
        ".Lf181da6_001821f7:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 3058 | es */
        "testb $0x40, 8(%ecx)\n"
        "je .Lf181da6_001825c3\n"
        "movl 0x90(%ecx), %ecx\n" /* line 3059 | client */
        /* { scope 3 */
        "movl animConditionsTable+48, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf181da6_001827f5\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4088(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb408c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $2, 0xb4088(%eax, %edx)\n" /* line 812 */
        /* } scope */
        ".Lf181da6_00182259:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 3064 | es */
        "movl 0xcc(%ecx), %edi\n" /* legsAnim */
        "andl $0xfffffdff, %edi\n" /* legsAnim */
        "movl bgs, %eax\n" /* line 3065 */
        "movl %eax, -0x3c(%ebp)\n"
        "leal (%edi, %edi, 2), %eax\n" /* legsAnim */
        "shll $5, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl 0x54(%eax, %edx), %ebx\n" /* bitNum */
        "movl 0x58(%eax, %edx), %esi\n" /* weaponDef */
        "movl %esi, %ecx\n" /* weaponDef */
        "orl %ebx, %ecx\n" /* bitNum */
        "je .Lf181da6_001822c8\n"
        "movl -0x38(%ebp), %edx\n" /* line 3067 | ci */
        "movl 0x474(%edx), %eax\n"
        "cltd\n"
        "movl %esi, %ecx\n" /* weaponDef */
        "xorl %edx, %ecx\n"
        "xorl %ebx, %eax\n" /* bitNum */
        "orl %eax, %ecx\n"
        "je .Lf181da6_00182a8c\n"
        "movl -0x34(%ebp), %ecx\n" /* line 2187 | es */
        "movl 0x90(%ecx), %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %ebx, 0xb4070(%eax, %edx, 8)\n" /* bitNum */
        "movl bgs, %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        ".Lf181da6_001822c8:\n"
        "movl %edx, %ecx\n"
        ".Lf181da6_001822ca:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 3078 | legsAnim */
        "shll $5, %eax\n"
        "movl 0x50(%eax, %ecx), %eax\n"
        "testb $0x10, %al\n"
        "je .Lf181da6_001824dc\n"
        "movl -0x34(%ebp), %eax\n" /* line 3079 | es */
        "movl 0x90(%eax), %ecx\n" /* client */
        /* { scope 3 */
        "movl animConditionsTable+64, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf181da6_0018281a\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl $0, 0xb4098(%eax, %edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb409c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $2, 0xb4098(%eax, %edx)\n" /* line 812 */
        /* } scope */
        /* } scope */
        ".Lf181da6_00182330:\n"
        "movl -0x38(%ebp), %eax\n" /* line 3393 | ci */
        "movl 0x4a4(%eax), %ebx\n" /* pAnimTree */
        "movl -0x40(%ebp), %edx\n" /* line 2705 */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf181da6_0018252c\n"
        ".Lf181da6_00182347:\n"
        "movl -0x44(%ebp), %edx\n"
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf181da6_0018257c\n"
        ".Lf181da6_00182355:\n"
        "movl -0x38(%ebp), %edx\n" /* line 3400 | ci */
        "movl 0x3f4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf181da6_00182382\n"
        "testl $0xfffffdff, 0x3c0(%edx)\n"
        "jne .Lf181da6_00182382\n"
        "movl $0, 0x3f4(%edx)\n" /* line 3402 */
        "movl $1, 0x3f8(%edx)\n" /* line 3403 */
        ".Lf181da6_00182382:\n"
        "movl -0x34(%ebp), %eax\n" /* line 3406 | es */
        "movl 0xcc(%eax), %ecx\n"
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl -0x38(%ebp), %eax\n" /* ci */
        "calll BG_RunLerpFrameRate\n"
        "movl -0x34(%ebp), %edx\n" /* line 3407 | es */
        "movl 0xd0(%edx), %ecx\n"
        "movl %edx, 8(%ebp)\n" /* pDObj */
        "movl -0x44(%ebp), %edx\n"
        "movl -0x38(%ebp), %eax\n" /* ci */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 3408 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: moveDir */
        "jmp BG_RunLerpFrameRate\n" /* line 3407 */
        /* { scope 2 */
        ".Lf181da6_001823b7:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 2200 | ci */
        "movl 0x474(%ecx), %eax\n"
        "testl $0xc0000, %eax\n" /* line 2865 */
        "jne .Lf181da6_001824b3\n"
        "testb $0x40, %dh\n" /* line 2873 */
        "jne .Lf181da6_00182991\n"
        "testb $6, %al\n" /* line 2881 */
        "jne .Lf181da6_00182af2\n"
        "movl -0x38(%ebp), %eax\n" /* line 2883 | ci */
        "movl $1, 0x3b4(%eax)\n"
        "movl $1, 0x3bc(%eax)\n" /* line 2884 */
        "movl $1, 0x384(%eax)\n" /* line 2885 */
        "movl -0x34(%ebp), %ecx\n" /* es */
        "movl 8(%ecx), %edx\n"
        "jmp .Lf181da6_00181e2c\n"
        ".Lf181da6_00182408:\n"
        "movl -0x34(%ebp), %edx\n" /* line 2961 | es */
        "movl 0xcc(%edx), %eax\n"
        "andb $0xfd, %ah\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "addl bgs, %eax\n"
        "testb $0x30, 0x50(%eax)\n"
        "jne .Lf181da6_00182a94\n"
        "movl -0x38(%ebp), %eax\n" /* line 2967 | ci */
        "movl 0x384(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf181da6_00182a75\n"
        "movl %eax, %edx\n"
        "movl %eax, %ecx\n"
        "addl $0x384, %edx\n" /* line 2973 */
        "addl $0x380, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl (%ebx), %ecx\n" /* bitNum */
        "movl -0x40(%ebp), %eax\n"
        "movss 8(%ecx), %xmm3\n"
        "movss lit4_002ed93c, %xmm2\n" /* 150.0f */
        "movss lit4_002ed73c, %xmm1\n" /* 40.0f */
        "movaps %xmm4, %xmm0\n"
        "calll BG_SwingAngles\n"
        "movl -0x34(%ebp), %eax\n" /* line 2977 | es */
        "movl 8(%eax), %edx\n"
        "testb $3, %dh\n"
        "je .Lf181da6_00181ef1\n"
        ".Lf181da6_0018247f:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 2979 */
        "movl -0x38(%ebp), %edx\n" /* ci */
        "movss %xmm0, 0x3b0(%edx)\n"
        "movss %xmm0, 0x380(%edx)\n" /* line 2980 */
        "movl 8(%eax), %edx\n"
        "jmp .Lf181da6_00181f1b\n"
        ".Lf181da6_0018249f:\n"
        "movss -0x20(%ebp), %xmm4\n" /* line 2907 */
        "movaps %xmm4, %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "jmp .Lf181da6_00181e73\n"
        ".Lf181da6_001824b3:\n"
        "movl $1, 0x3b4(%ecx)\n" /* line 2867 */
        "movl $1, 0x3bc(%ecx)\n" /* line 2868 */
        "movl $1, 0x384(%ecx)\n" /* line 2869 */
        "movl -0x34(%ebp), %eax\n" /* es */
        "movl 8(%eax), %edx\n"
        "jmp .Lf181da6_00181e2c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf181da6_001824dc:\n"
        "testb $0x20, %al\n" /* line 3080 */
        "je .Lf181da6_00182884\n"
        "movl -0x34(%ebp), %eax\n" /* line 3081 | es */
        "movl 0x90(%eax), %ecx\n" /* client */
        /* { scope 3 */
        "movl animConditionsTable+64, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "je .Lf181da6_0018294e\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl $2, 0xb4098(%ecx, %eax, 8)\n"
        /* } scope */
        /* } scope */
        "movl -0x38(%ebp), %eax\n" /* line 3393 | ci */
        "movl 0x4a4(%eax), %ebx\n" /* pAnimTree */
        "movl -0x40(%ebp), %edx\n" /* line 2705 */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf181da6_00182347\n"
        ".Lf181da6_0018252c:\n"
        "andb $0xfd, %ah\n" /* line 2707 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* bitNum */
        "calll XAnimGetWeight\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf181da6_00182347\n"
        "jp .Lf181da6_00182347\n"
        "movl -0x40(%ebp), %eax\n" /* line 2709 */
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n" /* line 2710 */
        "movl $0x96, 0x18(%eax)\n" /* line 2711 */
        "movl -0x44(%ebp), %edx\n" /* line 2705 */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf181da6_00182355\n"
        ".Lf181da6_0018257c:\n"
        "andb $0xfd, %ah\n" /* line 2707 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* bitNum */
        "calll XAnimGetWeight\n"
        "fstps -0x28(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf181da6_00182355\n"
        "jp .Lf181da6_00182355\n"
        "movl -0x44(%ebp), %eax\n" /* line 2709 */
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n" /* line 2710 */
        "movl $0x96, 0x18(%eax)\n" /* line 2711 */
        "jmp .Lf181da6_00182355\n"
        /* { scope 2 */
        ".Lf181da6_001825c3:\n"
        "movl 0x90(%ecx), %ecx\n" /* line 3061 | client */
        /* { scope 3 */
        "movl animConditionsTable+48, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf181da6_00182929\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4088(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb408c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $1, 0xb4088(%eax, %edx)\n" /* line 812 */
        "jmp .Lf181da6_00182259\n"
        /* } scope */
        ".Lf181da6_0018261d:\n"
        "movl 0x90(%ecx), %ecx\n" /* line 3048 | client */
        /* { scope 3 */
        "movl animConditionsTable+16, %edi\n" /* line 2172 */
        "testl %edi, %edi\n"
        "jne .Lf181da6_001828ba\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4068(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb406c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $1, 0xb4068(%eax, %edx)\n" /* line 812 */
        "jmp .Lf181da6_0018211c\n"
        /* } scope */
        ".Lf181da6_00182678:\n"
        "movl 0x90(%eax), %ecx\n" /* line 3056 | client */
        /* { scope 3 */
        "movl animConditionsTable+40, %edx\n" /* line 2172 */
        "testl %edx, %edx\n"
        "jne .Lf181da6_001827d0\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4080(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb4084(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $1, 0xb4080(%eax, %edx)\n" /* line 812 */
        "jmp .Lf181da6_001821f7\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_001826d3:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl %ebx, 0xb4060(%eax)\n" /* bitNum */
        /* } scope */
        "movl -0x34(%ebp), %eax\n" /* line 3039 | es */
        "testb $4, 0xa(%eax)\n"
        "jne .Lf181da6_00182062\n"
        ".Lf181da6_001826fc:\n"
        "movl 0x90(%eax), %ecx\n" /* line 3042 | client */
        /* { scope 3 */
        "movl animConditionsTable+56, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf181da6_0018283a\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, %edx\n"
        "addl bgs, %edx\n"
        "movl $0, 0xb4090(%edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb4094(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $1, 0xb4090(%eax, %edx)\n" /* line 812 */
        "jmp .Lf181da6_001820b7\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_00182756:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl %ebx, 0xb4078(%eax)\n" /* bitNum */
        "jmp .Lf181da6_00182194\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_00182777:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl %ebx, 0xb4058(%eax)\n" /* bitNum */
        "jmp .Lf181da6_00181fe8\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf181da6_00182798:\n"
        "movl -0x38(%ebp), %edx\n" /* line 2952 | ci */
        "addl $0x384, %edx\n"
        "movl -0x38(%ebp), %ecx\n" /* ci */
        "addl $0x380, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl (%ebx), %ecx\n" /* bitNum */
        "movl -0x40(%ebp), %eax\n"
        ".Lf181da6_001827b2:\n"
        "movss 8(%ecx), %xmm3\n" /* line 2969 */
        "movss lit4_002ed93c, %xmm2\n" /* 150.0f */
        "pxor %xmm1, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "calll BG_SwingAngles\n"
        "jmp .Lf181da6_00181ee2\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf181da6_001827d0:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4080(%eax)\n"
        "jmp .Lf181da6_001821f7\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_001827f5:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $1, 0xb4088(%eax)\n"
        "jmp .Lf181da6_00182259\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_0018281a:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl $1, 0xb4098(%ecx, %eax, 8)\n"
        "jmp .Lf181da6_00182330\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_0018283a:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4090(%eax)\n"
        "jmp .Lf181da6_001820b7\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_0018285f:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $1, 0xb4080(%eax)\n"
        "jmp .Lf181da6_001821f7\n"
        /* } scope */
        ".Lf181da6_00182884:\n"
        "movl -0x34(%ebp), %eax\n" /* line 3083 | es */
        "movl 0x90(%eax), %ecx\n" /* client */
        /* { scope 3 */
        "movl animConditionsTable+64, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "je .Lf181da6_00182a32\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2187 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl $0, 0xb4098(%ecx, %eax, 8)\n"
        "jmp .Lf181da6_00182330\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_001828ba:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4068(%eax)\n"
        "jmp .Lf181da6_0018211c\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_001828df:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $1, 0xb4090(%eax)\n"
        "jmp .Lf181da6_001820b7\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_00182904:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $1, 0xb4068(%eax)\n"
        "jmp .Lf181da6_0018211c\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_00182929:\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "addl bgs, %eax\n"
        "movl $0, 0xb4088(%eax)\n"
        "jmp .Lf181da6_00182259\n"
        /* } scope */
        /* { scope 3 */
        ".Lf181da6_0018294e:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl $0, 0xb4098(%eax, %edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb409c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $4, 0xb4098(%eax, %edx)\n" /* line 812 */
        "jmp .Lf181da6_00182330\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf181da6_00182991:\n"
        "movl -0x38(%ebp), %edx\n" /* line 2875 | ci */
        "movl $1, 0x3b4(%edx)\n"
        "movl $1, 0x3bc(%edx)\n" /* line 2876 */
        "movl $1, 0x384(%edx)\n" /* line 2877 */
        "movl -0x34(%ebp), %ecx\n" /* es */
        "movl 8(%ecx), %edx\n"
        "jmp .Lf181da6_00181e2c\n"
        ".Lf181da6_001829bd:\n"
        "testb $8, %dl\n" /* line 2921 */
        "jne .Lf181da6_00182ad7\n"
        "testb $0x40, %dl\n" /* line 2926 */
        "jne .Lf181da6_00182b6e\n"
        "andl $0x40000, %edx\n" /* line 2929 */
        "jne .Lf181da6_00182ad7\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 2932 | moveDir */
        "mulss lit4_002ed6f4, %xmm0\n" /* 0.30000001192092896f */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm4\n"
        "movss lit4_002ed5f8, %xmm2\n" /* 90.0f */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf181da6_00181e73\n"
        ".Lf181da6_00182a03:\n"
        "cmpl $0x4000, %edx\n" /* line 3003 */
        "je .Lf181da6_00181f3b\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 3007 */
        "ucomiss lit4_002ed64c, %xmm0\n" /* 180.0f */
        "ja .Lf181da6_00182b61\n"
        ".Lf181da6_00182a21:\n"
        "mulss lit4_002ed944, %xmm0\n" /* line 3008 | 0.6000000238418579f */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf181da6_00181f42\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf181da6_00182a32:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2179 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl $0, 0xb4098(%eax, %edx)\n"
        "movl %eax, %edx\n" /* line 2180 */
        "addl bgs, %edx\n"
        "movl $0, 0xb409c(%edx)\n"
        "movl bgs, %edx\n" /* line 2183 */
        "orl $1, 0xb4098(%eax, %edx)\n" /* line 812 */
        "jmp .Lf181da6_00182330\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf181da6_00182a75:\n"
        "movl %eax, %edx\n" /* line 2969 */
        "addl $0x384, %edx\n"
        "addl $0x380, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl (%ebx), %ecx\n" /* bitNum */
        "jmp .Lf181da6_001827b2\n"
        ".Lf181da6_00182a8c:\n"
        "movl -0x3c(%ebp), %ecx\n"
        "jmp .Lf181da6_001822ca\n"
        ".Lf181da6_00182a94:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 2963 | ci */
        "movl $0, 0x384(%ecx)\n"
        "movl %ecx, %edx\n" /* line 2965 */
        "addl $0x384, %edx\n"
        "addl $0x380, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl (%ebx), %ecx\n" /* bitNum */
        "movl -0x40(%ebp), %eax\n"
        "movss 8(%ecx), %xmm3\n"
        "movss lit4_002ed93c, %xmm2\n" /* 150.0f */
        "pxor %xmm1, %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "calll BG_SwingAngles\n"
        "jmp .Lf181da6_00181ee2\n"
        ".Lf181da6_00182ad7:\n"
        "movss -0x20(%ebp), %xmm4\n" /* line 2929 */
        "movss -0x1c(%ebp), %xmm0\n"
        "movss lit4_002ed5f8, %xmm2\n" /* 90.0f */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf181da6_00181e73\n"
        ".Lf181da6_00182af2:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2200 | ci */
        "movl 0x48c(%eax), %ebx\n" /* bitNum */
        "movl animConditionsTable+48, %ecx\n" /* line 2203 */
        "testl %ecx, %ecx\n"
        "jne .Lf181da6_00182b37\n"
        "movl %eax, %esi\n"
        "addl $0x48c, %esi\n" /* line 2207 */
        "andb $1, %bl\n" /* bitNum */
        "jne .Lf181da6_00181e2c\n"
        "xorl %ebx, %ebx\n" /* bitNum */
        ".Lf181da6_00182b18:\n"
        "addl $1, %ebx\n" /* line 2205 | bitNum */
        "cmpl $0x40, %ebx\n" /* bitNum */
        "je .Lf181da6_00181e2c\n"
        "movl %ebx, %eax\n" /* line 2207 | bitNum */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n" /* bitNum */
        "andl $0x1f, %ecx\n"
        "movl (%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf181da6_00182b18\n"
        ".Lf181da6_00182b37:\n"
        "testl %ebx, %ebx\n" /* line 2888 | bitNum */
        "je .Lf181da6_00181e2c\n"
        "movl -0x38(%ebp), %edx\n" /* line 2890 | ci */
        "movl $1, 0x3b4(%edx)\n"
        "movl $1, 0x3bc(%edx)\n" /* line 2891 */
        "movl -0x34(%ebp), %ecx\n" /* es */
        "movl 8(%ecx), %edx\n"
        "jmp .Lf181da6_00181e2c\n"
        ".Lf181da6_00182b61:\n"
        "subss lit4_002ed638, %xmm0\n" /* line 3008 | 360.0f */
        "jmp .Lf181da6_00182a21\n"
        ".Lf181da6_00182b6e:\n"
        "movss -0x20(%ebp), %xmm4\n" /* line 2926 */
        "movss -0x1c(%ebp), %xmm0\n"
        "movss lit4_002ed6ec, %xmm2\n" /* 45.0f */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf181da6_00181e73\n"
    );
}

/* line 405 */
__attribute__((naked))
int BG_AnimationIndexForString(const char *string, const char *string_1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 405 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl g_pLoadAnims, %ecx\n" /* line 411 */
        "testl %ecx, %ecx\n"
        "je .Lf182b8a_error_null\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 363 | string */
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "jne .Lf182b8a_hash_compute\n"
        ".Lf182b8a_hash_zero:\n"
        "xorl %edi, %edi\n" /* line 369 | hash */
        /* } scope */
        ".Lf182b8a_after_hash:\n"
        "movl g_pLoadAnims, %edx\n" /* line 438 */
        "movl %edx, %ebx\n" /* pAnim */
        "movl g_piNumLoadAnims, %eax\n"
        "movl (%eax), %esi\n" /* i */
        "testl %esi, %esi\n" /* i */
        "jle .Lf182b8a_00182c02\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf182b8a_00182bd2\n"
        ".Lf182b8a_00182bc8:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x48, %ebx\n" /* pAnim */
        "cmpl (%eax), %esi\n" /* i */
        "jge .Lf182b8a_00182bfc\n"
        ".Lf182b8a_00182bd2:\n"
        "cmpl 4(%ebx), %edi\n" /* line 440 | pAnim, hash */
        "jne .Lf182b8a_00182bc8\n"
        "leal 8(%ebx), %eax\n" /* pAnim */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf182b8a_match_found\n"
        "movl g_piNumLoadAnims, %eax\n"
        "addl $1, %esi\n" /* line 438 | i */
        "addl $0x48, %ebx\n" /* pAnim */
        "cmpl (%eax), %esi\n" /* i */
        "jl .Lf182b8a_00182bd2\n"
        ".Lf182b8a_00182bfc:\n"
        "movl g_pLoadAnims, %edx\n"
        ".Lf182b8a_00182c02:\n"
        "movl (%eax), %ebx\n" /* line 445 | pAnim */
        "leal (%ebx, %ebx, 8), %ebx\n" /* pAnim */
        "leal (%edx, %ebx, 8), %ebx\n" /* pAnim */
        "movl bgs, %eax\n" /* line 446 */
        "movl 0xb3be8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* pAnim */
        "movl 8(%ebp), %edx\n" /* string */
        "movl %edx, 4(%esp)\n"
        "movl $str_002aef88, (%esp)\n" /* "multiplayer" */
        "calll Scr_FindAnim\n"
        "movl 8(%ebp), %eax\n" /* line 448 | string */
        "movl %eax, 4(%esp)\n"
        "leal 8(%ebx), %eax\n" /* pAnim */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl %edi, 4(%ebx)\n" /* line 449 | hash, pAnim */
        "movl g_piNumLoadAnims, %edx\n" /* line 450 */
        "addl $1, (%edx)\n"
        /* match found — return index in %esi */
        ".Lf182b8a_match_found:\n"
        "movl %esi, %eax\n"
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* hash computation for input string */
        ".Lf182b8a_hash_compute:\n"
        "xorl %edi, %edi\n" /* hash = 0 */
        "movl $0x77, %ebx\n"
        ".Lf182b8a_hash_loop:\n"
        "movsbl %al, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movsbl %al, %eax\n"
        "imull %ebx, %eax\n"
        "addl %eax, %edi\n"
        "movl 8(%ebp), %edx\n"
        "movzbl -0x76(%edx, %ebx), %eax\n"
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf182b8a_hash_loop\n"
        "cmpl $-1, %edi\n"
        "je .Lf182b8a_hash_zero\n"
        "jmp .Lf182b8a_after_hash\n"
        /* error: g_pLoadAnims is NULL */
        ".Lf182b8a_error_null:\n"
        "movl 8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aef4c, (%esp)\n" /* "BG_AnimationIndexForString: unknown player animation '%s'" */
        "calll BG_AnimParseError\n"
        "movl $-1, %eax\n"
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 492 */
__attribute__((naked))
int BG_IndexForString(const char *token, animStringItem_t *strings, qboolean allowFail)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 492 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* strings */
        /* { scope 1: hash, hash */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 363 | token */
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "jne .Lf182d4e_00182e47\n"
        ".Lf182d4e_00182d68:\n"
        "movl $0, -0x28(%ebp)\n" /* line 369 | hash */
        /* } scope */
        ".Lf182d4e_00182d6f:\n"
        "movl (%edi), %esi\n" /* line 499 | strav */
        "testl %esi, %esi\n"
        "je .Lf182d4e_00182def\n"
        "leal 8(%edi), %eax\n" /* strav */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* i */
        "jmp .Lf182d4e_00182da3\n"
        ".Lf182d4e_00182d84:\n"
        "movl %edx, %eax\n"
        "movl -0x28(%ebp), %edx\n" /* line 505 | hash */
        "cmpl (%eax), %edx\n"
        "je .Lf182d4e_00182dcf\n"
        ".Lf182d4e_00182d8d:\n"
        "addl $8, %edi\n" /* line 499 | strav */
        "addl $1, -0x2c(%ebp)\n" /* i */
        "movl -0x20(%ebp), %edx\n"
        "movl (%edx), %esi\n"
        "addl $8, %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "testl %esi, %esi\n"
        "je .Lf182d4e_00182def\n"
        ".Lf182d4e_00182da3:\n"
        "leal 4(%edi), %edx\n" /* line 492 | strings */
        "movl %edx, -0x1c(%ebp)\n"
        "cmpl $-1, 4(%edi)\n" /* line 501 | strav */
        "jne .Lf182d4e_00182d84\n"
        /* { scope 2 */
        "movzbl (%esi), %eax\n" /* line 363 */
        "testb %al, %al\n"
        "jne .Lf182d4e_00182e0c\n"
        ".Lf182d4e_00182db6:\n"
        "movl $0, -0x24(%ebp)\n" /* line 369 | hash */
        /* } scope */
        ".Lf182d4e_00182dbd:\n"
        "movl -0x24(%ebp), %edx\n" /* line 503 | hash */
        "movl -0x1c(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl -0x28(%ebp), %edx\n" /* line 505 | hash */
        "cmpl (%eax), %edx\n"
        "jne .Lf182d4e_00182d8d\n"
        ".Lf182d4e_00182dcf:\n"
        "movl (%edi), %eax\n" /* strav */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf182d4e_00182d8d\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 518 | i */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: hash, hash */
        ".Lf182d4e_00182def:\n"
        "movl 0x10(%ebp), %edi\n" /* line 512 | allowFail, strav */
        "testl %edi, %edi\n" /* strav */
        "je .Lf182d4e_00182e85\n"
        ".Lf182d4e_00182dfa:\n"
        "movl $0xffffffff, -0x2c(%ebp)\n" /* line 514 | i */
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 518 | i */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: hash, hash */
        /* { scope 2 */
        ".Lf182d4e_00182e0c:\n"
        "movl $0, -0x24(%ebp)\n" /* line 363 | hash */
        "movl $0x77, %ebx\n"
        ".Lf182d4e_00182e18:\n"
        "movsbl %al, %eax\n" /* line 365 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movsbl %al, %eax\n" /* line 366 */
        "imull %ebx, %eax\n"
        "addl %eax, -0x24(%ebp)\n" /* hash */
        "movzbl -0x76(%esi, %ebx), %eax\n" /* line 363 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf182d4e_00182e18\n"
        "cmpl $-1, -0x24(%ebp)\n" /* line 369 | hash */
        "je .Lf182d4e_00182db6\n"
        "jmp .Lf182d4e_00182dbd\n"
        /* } scope */
        /* { scope 2 */
        ".Lf182d4e_00182e47:\n"
        "movl $0, -0x28(%ebp)\n" /* line 363 | hash */
        "movl $0x77, %ebx\n"
        ".Lf182d4e_00182e53:\n"
        "movsbl %al, %eax\n" /* line 365 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movsbl %al, %eax\n" /* line 366 */
        "imull %ebx, %eax\n"
        "addl %eax, -0x28(%ebp)\n" /* hash */
        "movl 8(%ebp), %edx\n" /* line 363 | token */
        "movzbl -0x76(%edx, %ebx), %eax\n"
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf182d4e_00182e53\n"
        "cmpl $-1, -0x28(%ebp)\n" /* line 369 | hash */
        "je .Lf182d4e_00182d68\n"
        "jmp .Lf182d4e_00182d6f\n"
        /* } scope */
        ".Lf182d4e_00182e85:\n"
        "movl 8(%ebp), %eax\n" /* line 514 | token */
        "movl %eax, 4(%esp)\n"
        "movl $str_002aef94, (%esp)\n" /* "BG_IndexForString: unknown token '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf182d4e_00182dfa\n"
    );
}

/* line 760 */
static __attribute__((naked))
void BG_ParseConditionBits(const char * *text_pp, animStringItem_t *stringTable, int condIndex, int *result)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 760 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl %edx, -0x74(%ebp)\n"
        "movl %ecx, -0x78(%ebp)\n"
        /* { scope 1 */
        "movb $0, -0x60(%ebp)\n" /* line 770 | currentString */
        "movl 8(%ebp), %eax\n" /* line 771 | result */
        "movl $0, (%eax)\n"
        "movl $0, -0x20(%ebp)\n" /* line 772 | tempBits */
        "movl $0, -0x1c(%ebp)\n"
        "movl $0, -0x6c(%ebp)\n" /* minus */
        ".Lf182e9e_00182ed2:\n"
        "movl -0x70(%ebp), %edx\n" /* line 777 */
        "movl %edx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 778 */
        "je .Lf182e9e_00182f33\n"
        ".Lf182e9e_00182ee3:\n"
        "cmpb $0, (%eax)\n"
        "je .Lf182e9e_00182f33\n"
        "xorl %esi, %esi\n" /* endFlag */
        ".Lf182e9e_00182eea:\n"
        "movl $str_0021f88c, 4(%esp)\n" /* line 788 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "movl $1, %eax\n"
        "cmovel %eax, %esi\n" /* endFlag */
        "movl $str_00218298, 4(%esp)\n" /* line 793 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf182e9e_00182f45\n"
        "movl 8(%ebp), %edi\n" /* line 812 | result */
        "orl $1, (%edi)\n"
        ".Lf182e9e_00182f1e:\n"
        "testl %esi, %esi\n" /* line 774 | endFlag */
        "jne .Lf182e9e_00182f5f\n"
        "movl -0x70(%ebp), %edx\n" /* line 777 */
        "movl %edx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 778 */
        "jne .Lf182e9e_00182ee3\n"
        ".Lf182e9e_00182f33:\n"
        "calll Com_UngetToken\n" /* line 780 */
        "cmpb $0, -0x60(%ebp)\n" /* line 782 | currentString */
        "je .Lf182e9e_00182f5f\n"
        "movl $1, %esi\n" /* line 784 | endFlag */
        "jmp .Lf182e9e_00182eea\n"
        ".Lf182e9e_00182f45:\n"
        "movl $str_002aefbc, 4(%esp)\n" /* line 799 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf182e9e_00182f67\n"
        "movl 8(%ebp), %eax\n" /* line 812 | result */
        "orl $1, (%eax)\n"
        /* } scope */
        ".Lf182e9e_00182f5f:\n"
        "addl $0x7c, %esp\n" /* line 898 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf182e9e_00182f67:\n"
        "movl $str_002aed3c, 4(%esp)\n" /* line 806 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "movl $str_002aefc4, %eax\n" /* "MINUS" */
        "cmovel %eax, %ebx\n" /* token */
        "testl %esi, %esi\n" /* line 811 | endFlag */
        "je .Lf182e9e_001830f5\n"
        ".Lf182e9e_00182f89:\n"
        "movl $str_002aefcc, 4(%esp)\n" /* line 827 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf182e9e_001830d0\n"
        ".Lf182e9e_00182fa1:\n"
        "cmpb $0, -0x60(%ebp)\n" /* line 830 | currentString */
        "jne .Lf182e9e_00182fdf\n"
        "testl %esi, %esi\n" /* line 832 | endFlag */
        "jne .Lf182e9e_00183048\n"
        "movl $str_002aefc4, 4(%esp)\n" /* line 839 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf182e9e_00182fcf\n"
        "movl $1, -0x6c(%ebp)\n" /* line 898 | minus */
        "jmp .Lf182e9e_00182ed2\n"
        ".Lf182e9e_00182fcf:\n"
        "movl %ebx, 4(%esp)\n" /* line 844 | token */
        "movl $str_002af004, (%esp)\n" /* "BG_ParseConditionBits: unexpected '%s'" */
        "calll BG_AnimParseError\n"
        ".Lf182e9e_00182fdf:\n"
        "movl $str_0022540c, 4(%esp)\n" /* line 847 */
        "leal -0x60(%ebp), %edi\n" /* currentString */
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf182e9e_0018306b\n"
        ".Lf182e9e_00182ff6:\n"
        "movl $0xffffffff, -0x20(%ebp)\n" /* line 851 | tempBits */
        "movl $0xffffffff, -0x1c(%ebp)\n" /* line 852 */
        ".Lf182e9e_00183004:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 878 | minus */
        "testl %eax, %eax\n"
        "je .Lf182e9e_001830b8\n"
        "movl -0x20(%ebp), %eax\n" /* line 880 | tempBits */
        "notl %eax\n"
        "movl 8(%ebp), %edx\n" /* result */
        "andl %eax, (%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 881 */
        "notl %eax\n"
        "andl %eax, 4(%edx)\n"
        ".Lf182e9e_00183021:\n"
        "movb $0, -0x60(%ebp)\n" /* line 889 | currentString */
        "movl $str_002aefc4, 4(%esp)\n" /* line 891 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "movl $1, %eax\n"
        "cmovnel -0x6c(%ebp), %eax\n" /* minus */
        "movl %eax, -0x6c(%ebp)\n" /* minus */
        "jmp .Lf182e9e_00182f1e\n"
        ".Lf182e9e_00183048:\n"
        "movl $str_002aefd0, (%esp)\n" /* line 834 */
        "calll BG_AnimParseError\n"
        "movl $str_0022540c, 4(%esp)\n" /* line 847 */
        "leal -0x60(%ebp), %edi\n" /* currentString */
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf182e9e_00182ff6\n"
        ".Lf182e9e_0018306b:\n"
        "movl $1, 8(%esp)\n" /* line 857 */
        "movl -0x78(%ebp), %eax\n"
        "shll $7, %eax\n"
        "addl $defineStr, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* currentString */
        "movl %eax, (%esp)\n"
        "calll BG_IndexForString\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 858 */
        "js .Lf182e9e_0018315e\n"
        "movl -0x78(%ebp), %eax\n" /* line 863 */
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl defineBits(, %eax, 8), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* tempBits */
        "movl defineBits+4(, %eax, 8), %eax\n" /* line 864 */
        "movl %eax, -0x1c(%ebp)\n"
        "jmp .Lf182e9e_00183004\n"
        ".Lf182e9e_001830b8:\n"
        "movl 8(%ebp), %edi\n" /* line 885 | result */
        "movl (%edi), %eax\n"
        "orl -0x20(%ebp), %eax\n" /* tempBits */
        "movl %eax, (%edi)\n"
        "movl 4(%edi), %eax\n" /* line 886 */
        "orl -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%edi)\n"
        "jmp .Lf182e9e_00183021\n"
        ".Lf182e9e_001830d0:\n"
        "movl $str_002aefc4, 4(%esp)\n" /* line 827 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf182e9e_00182fa1\n"
        "testl %esi, %esi\n" /* endFlag */
        "je .Lf182e9e_00182ed2\n"
        "jmp .Lf182e9e_00182fa1\n"
        ".Lf182e9e_001830f5:\n"
        "movl $str_002aefcc, 4(%esp)\n" /* line 811 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf182e9e_00183110\n"
        ".Lf182e9e_00183109:\n"
        "xorl %esi, %esi\n" /* line 824 | endFlag */
        "jmp .Lf182e9e_00182f89\n"
        ".Lf182e9e_00183110:\n"
        "movl $str_002aefc4, 4(%esp)\n" /* line 811 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf182e9e_00183109\n"
        "cld\n" /* line 814 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "cmpb $0x2c, -1(%ebx, %eax)\n" /* token */
        "je .Lf182e9e_001831af\n"
        ".Lf182e9e_0018313c:\n"
        "cmpb $0, -0x60(%ebp)\n" /* line 820 | currentString */
        "jne .Lf182e9e_00183192\n"
        ".Lf182e9e_00183142:\n"
        "movl %ebx, 8(%esp)\n" /* line 824 | token */
        "movl $0x40, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* currentString */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "jmp .Lf182e9e_00182f89\n"
        ".Lf182e9e_0018315e:\n"
        "movl $0, 8(%esp)\n" /* line 869 */
        "movl -0x74(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %edi\n" /* currentString */
        "movl %edi, (%esp)\n"
        "calll BG_IndexForString\n"
        "movl %eax, %ecx\n"
        "movl %eax, %edx\n" /* line 812 */
        "sarl $5, %edx\n"
        "andl $0x1f, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x20(%ebp, %edx, 4)\n"
        "jmp .Lf182e9e_00183004\n"
        ".Lf182e9e_00183192:\n"
        "movl $str_00217914, 8(%esp)\n" /* line 822 */
        "movl $0x40, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* currentString */
        "movl %eax, (%esp)\n"
        "calll I_strncat\n"
        "jmp .Lf182e9e_00183142\n"
        ".Lf182e9e_001831af:\n"
        "movb $0, -1(%ebx, %eax)\n" /* line 817 | token */
        "movw $1, %si\n" /* endFlag */
        "jmp .Lf182e9e_0018313c\n"
    );
}

/* line 908 */
static __attribute__((naked))
qboolean BG_ParseConditions(const char * *text_pp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 908 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %edx, %ebx\n" /* scriptItem */
        /* { scope 1 */
        "movl $0, -0x20(%ebp)\n" /* line 914 | conditionValue */
        "movl $0, -0x1c(%ebp)\n"
        "jmp .Lf1831ba_00183208\n"
        ".Lf1831ba_001831d8:\n"
        "subl $1, %eax\n" /* line 928 */
        "je .Lf1831ba_00183280\n"
        ".Lf1831ba_001831e1:\n"
        "movl (%ebx), %eax\n" /* line 960 | scriptItem */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %esi, 4(%ebx, %eax, 4)\n" /* conditionIndex, scriptItem */
        "movl (%ebx), %eax\n" /* line 965 | scriptItem */
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x20(%ebp), %edx\n" /* conditionValue */
        "movl %edx, 8(%ebx, %eax, 4)\n" /* scriptItem */
        "movl (%ebx), %eax\n" /* line 966 | scriptItem */
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0xc(%ebx, %eax, 4)\n" /* scriptItem */
        "addl $1, (%ebx)\n" /* line 967 | scriptItem */
        "movl -0x30(%ebp), %eax\n"
        ".Lf1831ba_00183208:\n"
        "movl %eax, (%esp)\n" /* line 918 */
        "calll Com_ParseOnLine\n"
        "movl %eax, %edi\n" /* token */
        "testl %eax, %eax\n" /* line 919 */
        "je .Lf1831ba_001832e8\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1831ba_001832e8\n"
        "movl $str_00220284, 4(%esp)\n" /* line 923 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1831ba_001832fa\n"
        "movl $0, 8(%esp)\n" /* line 926 */
        "movl $animConditionsStr, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* token */
        "calll BG_IndexForString\n"
        "movl %eax, %esi\n" /* conditionIndex */
        "movl animConditionsTable(, %eax, 8), %eax\n" /* line 928 */
        "testl %eax, %eax\n"
        "jne .Lf1831ba_001831d8\n"
        "movl animConditionsTable+4(, %esi, 8), %edx\n" /* line 931 */
        "leal -0x20(%ebp), %eax\n" /* conditionValue */
        "movl %eax, (%esp)\n"
        "movl %esi, %ecx\n" /* conditionIndex */
        "movl -0x30(%ebp), %eax\n"
        "calll BG_ParseConditionBits\n"
        "jmp .Lf1831ba_001831e1\n"
        ".Lf1831ba_00183280:\n"
        "movl animConditionsTable+4(, %esi, 8), %eax\n" /* line 935 */
        "testl %eax, %eax\n"
        "je .Lf1831ba_00183336\n"
        "movl -0x30(%ebp), %edx\n" /* line 937 */
        "movl %edx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, -0x2c(%ebp)\n"
        "testl %eax, %eax\n" /* line 938 */
        "je .Lf1831ba_00183307\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1831ba_00183307\n"
        "cld\n" /* line 943 */
        "xorl %eax, %eax\n"
        "movl $0xffffffff, %ecx\n"
        "movl -0x2c(%ebp), %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n" /* token */
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "cmpb $0x2c, -1(%edx, %eax)\n"
        "je .Lf1831ba_0018332f\n"
        ".Lf1831ba_001832c2:\n"
        "movl $0, 8(%esp)\n" /* line 947 */
        "movl animConditionsTable+4(, %esi, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_IndexForString\n"
        "movl %eax, -0x20(%ebp)\n" /* conditionValue */
        "jmp .Lf1831ba_001831e1\n"
        ".Lf1831ba_001832e8:\n"
        "movl (%ebx), %eax\n" /* line 970 | scriptItem */
        "testl %eax, %eax\n"
        "jne .Lf1831ba_001832fa\n"
        "movl $str_002af06c, (%esp)\n" /* line 972 */
        "calll BG_AnimParseError\n"
        /* } scope */
        ".Lf1831ba_001832fa:\n"
        "movl $1, %eax\n" /* line 976 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1831ba_00183307:\n"
        "movl $str_002af02c, (%esp)\n" /* line 940 */
        "calll BG_AnimParseError\n"
        "cld\n" /* line 943 */
        "xorl %eax, %eax\n"
        "movl $0xffffffff, %ecx\n"
        "movl -0x2c(%ebp), %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n" /* token */
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "cmpb $0x2c, -1(%edx, %eax)\n"
        "jne .Lf1831ba_001832c2\n"
        ".Lf1831ba_0018332f:\n"
        "movb $0, -1(%edx, %eax)\n" /* line 945 */
        "jmp .Lf1831ba_001832c2\n"
        ".Lf1831ba_00183336:\n"
        "movl $1, -0x20(%ebp)\n" /* line 951 | conditionValue */
        "jmp .Lf1831ba_001831e1\n"
    );
}

/* line 984 */
__attribute__((naked))
void BG_ParseCommands(const char * *input, animScriptItem_t *scriptItem, animScriptData_t *scriptData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 984 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* input */
        "movl $0, -0x20(%ebp)\n" /* command */
        "movl $0, -0x1c(%ebp)\n"
        /* { scope 1 */
        ".Lf183342_0018335c:\n"
        "movl %esi, (%esp)\n" /* line 997 | input */
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 998 */
        "je .Lf183342_0018357f\n"
        ".Lf183342_0018336e:\n"
        "cmpb $0, (%ebx)\n" /* token */
        "je .Lf183342_0018357f\n"
        "movl $str_0021e508, 4(%esp)\n" /* line 1000 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf183342_00183813\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1008 */
        "testl %edx, %edx\n"
        "jne .Lf183342_001833c9\n"
        "movl 0xc(%ebp), %eax\n" /* line 1011 | scriptItem */
        "cmpl $7, 0x70(%eax)\n"
        "jg .Lf183342_0018367e\n"
        "movl %eax, %edx\n"
        "movl %eax, %ecx\n"
        ".Lf183342_001833a7:\n"
        "movl 0x70(%edx), %eax\n" /* line 1013 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "leal 0x70(%edx, %ecx), %edx\n"
        "leal 4(%edx), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* command */
        "addl $1, %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* scriptItem */
        "movl %eax, 0x70(%ecx)\n"
        "movl $0, 4(%edx)\n" /* line 1014 */
        ".Lf183342_001833c9:\n"
        "movl $1, 8(%esp)\n" /* line 1017 */
        "movl $animBodyPartsStr, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* token */
        "calll BG_IndexForString\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl -0x20(%ebp), %ecx\n" /* command */
        "movw %ax, (%ecx, %edx, 2)\n"
        "testw %ax, %ax\n" /* line 1018 */
        "jle .Lf183342_00183666\n"
        "movl %esi, (%esp)\n" /* line 1021 | input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 1022 */
        "je .Lf183342_00183407\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf183342_00183413\n"
        ".Lf183342_00183407:\n"
        "movl $str_002af0d4, (%esp)\n" /* line 1023 */
        "calll BG_AnimParseError\n"
        ".Lf183342_00183413:\n"
        "movl %ebx, (%esp)\n" /* line 1024 | token */
        "calll BG_AnimationIndexForString\n"
        "movl -0x1c(%ebp), %ebx\n" /* token */
        "movl -0x20(%ebp), %edx\n" /* command */
        "movw %ax, 4(%edx, %ebx, 2)\n"
        "cwtl\n" /* line 1025 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* scriptData */
        "leal (%eax, %ecx), %edx\n"
        "movl 0x48(%edx), %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* command */
        "movw %ax, 8(%ecx, %ebx, 2)\n"
        "movl g_pLoadAnims, %eax\n" /* line 1026 */
        "testl %eax, %eax\n"
        "je .Lf183342_0018369d\n"
        ".Lf183342_0018344b:\n"
        "movl %esi, (%esp)\n" /* line 1087 | input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 1088 */
        "je .Lf183342_001834b6\n"
        ".Lf183342_00183459:\n"
        "cmpb $0, (%eax)\n"
        "je .Lf183342_001834b6\n"
        "movl $str_002acec8, 4(%esp)\n" /* line 1091 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183342_00183587\n"
        "movl %esi, (%esp)\n" /* line 1096 | input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 1097 */
        "je .Lf183342_00183489\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf183342_00183495\n"
        ".Lf183342_00183489:\n"
        "movl $str_002af0fc, (%esp)\n" /* line 1098 */
        "calll BG_AnimParseError\n"
        ".Lf183342_00183495:\n"
        "movl %ebx, (%esp)\n" /* line 1099 | token */
        "calll atoi\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl -0x20(%ebp), %ebx\n" /* command, token */
        "movw %ax, 8(%ebx, %ecx, 2)\n" /* token */
        "movl %esi, (%esp)\n" /* line 1087 | input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 1088 */
        "jne .Lf183342_00183459\n"
        ".Lf183342_001834b6:\n"
        "calll Com_UngetToken\n" /* line 1131 */
        "movl -0x1c(%ebp), %ebx\n" /* line 1135 | token */
        "movl -0x20(%ebp), %eax\n" /* command */
        "cmpw $3, (%eax, %ebx, 2)\n"
        "je .Lf183342_001834da\n"
        "addl $1, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "subl $1, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf183342_0018378f\n"
        ".Lf183342_001834da:\n"
        "movl %esi, (%esp)\n" /* line 1147 | input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 1148 */
        "je .Lf183342_00183566\n"
        ".Lf183342_001834e8:\n"
        "cmpb $0, (%eax)\n"
        "je .Lf183342_00183566\n"
        "movl $str_002af1bc, 4(%esp)\n" /* line 1151 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183342_001835ca\n"
        "movl %esi, (%esp)\n" /* line 1153 | input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 1154 */
        "je .Lf183342_00183518\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf183342_00183524\n"
        ".Lf183342_00183518:\n"
        "movl $str_002af1c4, (%esp)\n" /* line 1155 */
        "calll BG_AnimParseError\n"
        ".Lf183342_00183524:\n"
        "movl $str_00228dec, 4(%esp)\n" /* line 1157 */
        "movl %ebx, (%esp)\n" /* token */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf183342_00183544\n"
        "movl $str_002af1e8, (%esp)\n" /* line 1158 */
        "calll BG_AnimParseError\n"
        ".Lf183342_00183544:\n"
        "movl %ebx, (%esp)\n" /* line 1159 | token */
        "movl globalScriptData, %eax\n"
        "calll *0xb3bc0(%eax)\n"
        "movl -0x20(%ebp), %ecx\n" /* command */
        "movl %eax, 0xc(%ecx)\n"
        "movl %esi, (%esp)\n" /* line 1147 | input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 1148 */
        "jne .Lf183342_001834e8\n"
        ".Lf183342_00183566:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 997 */
        "movl %esi, (%esp)\n" /* input */
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 998 */
        "jne .Lf183342_0018336e\n"
        /* } scope */
        ".Lf183342_0018357f:\n"
        "addl $0x3c, %esp\n" /* line 1170 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf183342_00183587:\n"
        "movl $str_002af128, 4(%esp)\n" /* line 1101 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183342_001835df\n"
        "movl g_pLoadAnims, %eax\n" /* line 1105 */
        "testl %eax, %eax\n"
        "je .Lf183342_00183648\n"
        ".Lf183342_001835a8:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1109 */
        "movl -0x20(%ebp), %edx\n" /* command */
        "cmpw $3, (%edx, %eax, 2)\n"
        "je .Lf183342_0018344b\n"
        "movl $str_002af134, (%esp)\n" /* line 1110 */
        "calll BG_AnimParseError\n"
        "jmp .Lf183342_0018344b\n"
        ".Lf183342_001835ca:\n"
        "movl %ebx, 4(%esp)\n" /* line 1164 | token */
        "movl $str_002af228, (%esp)\n" /* "BG_ParseCommands: unknown parameter '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183342_001834da\n"
        ".Lf183342_001835df:\n"
        "movl $str_002af184, 4(%esp)\n" /* line 1112 */
        "movl %ebx, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183342_001834b6\n"
        "movl %esi, (%esp)\n" /* line 1117 | input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 1118 */
        "je .Lf183342_0018360a\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf183342_00183616\n"
        ".Lf183342_0018360a:\n"
        "movl $str_002af190, (%esp)\n" /* line 1119 */
        "calll BG_AnimParseError\n"
        ".Lf183342_00183616:\n"
        "movl g_pLoadAnims, %eax\n" /* line 1121 */
        "testl %eax, %eax\n"
        "jne .Lf183342_0018344b\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1122 */
        "movl -0x20(%ebp), %eax\n" /* command */
        "movswl 4(%eax, %ecx, 2), %ebx\n" /* token */
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "leal (%ebx, %ebx, 2), %ebx\n" /* token */
        "shll $5, %ebx\n" /* token */
        "movl 0x10(%ebp), %edx\n" /* scriptData */
        "movl %eax, 0x40(%ebx, %edx)\n" /* token */
        "jmp .Lf183342_0018344b\n"
        ".Lf183342_00183648:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1106 */
        "movl -0x20(%ebp), %ecx\n" /* command */
        "movswl 4(%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl 0x10(%ebp), %ebx\n" /* scriptData, token */
        "orl $4, 0x50(%eax, %ebx)\n"
        "jmp .Lf183342_001835a8\n"
        ".Lf183342_00183666:\n"
        "cld\n" /* line 1141 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "subl %ecx, (%esi)\n" /* input */
        "jmp .Lf183342_001834da\n"
        ".Lf183342_0018367e:\n"
        "movl $8, 4(%esp)\n" /* line 1012 */
        "movl $str_002af094, (%esp)\n" /* "BG_ParseCommands: exceeded maximum number of animations (%i)" */
        "calll BG_AnimParseError\n"
        "movl 0xc(%ebp), %edx\n" /* scriptItem */
        "movl 0xc(%ebp), %ecx\n" /* scriptItem */
        "jmp .Lf183342_001833a7\n"
        ".Lf183342_0018369d:\n"
        "movl parseMovetype, %edi\n" /* line 1029 */
        "testl %edi, %edi\n"
        "je .Lf183342_0018374a\n"
        "cmpw $2, (%ecx, %ebx, 2)\n"
        "je .Lf183342_0018374a\n"
        "leal 0x50(%edx), %ebx\n" /* line 1031 | token */
        "movl %edi, %ecx\n"
        "xorl %eax, %eax\n"
        "xorl %edx, %edx\n"
        "testb $0x20, %cl\n"
        "sete %al\n"
        "setne %dl\n"
        "shll %cl, %eax\n"
        "shll %cl, %edx\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl -0x30(%ebp), %edx\n"
        "orl 4(%ebx), %edx\n" /* token */
        "movl -0x2c(%ebp), %ecx\n"
        "orl 8(%ebx), %ecx\n" /* token */
        "movl %edx, 4(%ebx)\n" /* token */
        "movl %ecx, 8(%ebx)\n" /* token */
        "leal -0x12(%edi), %eax\n" /* line 1034 */
        "cmpl $1, %eax\n"
        "jbe .Lf183342_0018384c\n"
        ".Lf183342_001836f0:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1040 | scriptItem */
        "movl (%eax), %ebx\n" /* token */
        "testl %ebx, %ebx\n" /* token */
        "jle .Lf183342_0018374a\n"
        "movl %eax, %edx\n"
        "cmpl $8, 4(%eax)\n" /* line 1042 */
        "je .Lf183342_00183879\n"
        "xorl %ecx, %ecx\n"
        ".Lf183342_00183707:\n"
        "addl $1, %ecx\n" /* line 1040 */
        "cmpl %ebx, %ecx\n" /* token */
        "je .Lf183342_0018374a\n"
        "movl 0x10(%edx), %eax\n" /* line 1042 */
        "addl $0xc, %edx\n"
        "cmpl $8, %eax\n"
        "jne .Lf183342_00183707\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1045 */
        "movl 0xc(%ebp), %edx\n" /* scriptItem */
        "movl 8(%edx, %eax, 4), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf183342_0018382e\n"
        ".Lf183342_0018372c:\n"
        "cmpl $2, %eax\n" /* line 1047 */
        "jne .Lf183342_0018374a\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1048 */
        "movl -0x20(%ebp), %ebx\n" /* command, token */
        "movswl 4(%ebx, %ecx, 2), %eax\n" /* token */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* scriptData */
        "orl $0x20, 0x50(%eax, %edx)\n"
        ".Lf183342_0018374a:\n"
        "movl parseEvent, %eax\n" /* line 1055 */
        "cmpl $2, %eax\n"
        "je .Lf183342_001837b1\n"
        "cmpl $1, %eax\n" /* line 1061 */
        "je .Lf183342_001837e2\n"
        "cmpl $0xa, %eax\n" /* line 1067 */
        "je .Lf183342_0018376e\n"
        "leal -0x15(%edi), %eax\n" /* line 1075 */
        "cmpl $9, %eax\n"
        "ja .Lf183342_0018344b\n"
        ".Lf183342_0018376e:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1077 */
        "movl -0x20(%ebp), %ebx\n" /* command, token */
        "movswl 4(%ebx, %ecx, 2), %eax\n" /* token */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* scriptData */
        "movl $0, 0x44(%eax, %edx)\n"
        "jmp .Lf183342_0018344b\n"
        ".Lf183342_0018378f:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 997 */
        "testl %ecx, %ecx\n"
        "jle .Lf183342_0018335c\n"
        "movl %esi, (%esp)\n" /* input */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "testl %eax, %eax\n" /* line 998 */
        "jne .Lf183342_0018336e\n"
        "jmp .Lf183342_0018357f\n"
        ".Lf183342_001837b1:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1057 */
        "movl -0x20(%ebp), %ebx\n" /* command, token */
        "movswl 4(%ebx, %ecx, 2), %eax\n" /* token */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* scriptData */
        "orl $8, 0x50(%eax, %edx)\n"
        "movswl 4(%ebx, %ecx, 2), %eax\n" /* line 1058 | token */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl $0x1e, 0x40(%eax, %edx)\n"
        "jmp .Lf183342_0018344b\n"
        ".Lf183342_001837e2:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1063 */
        "movl -0x20(%ebp), %ebx\n" /* command, token */
        "movswl 4(%ebx, %ecx, 2), %eax\n" /* token */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* scriptData */
        "movl $0, 0x44(%eax, %edx)\n"
        "movswl 4(%ebx, %ecx, 2), %eax\n" /* line 1064 | token */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "orl $0x40, 0x50(%eax, %edx)\n"
        "jmp .Lf183342_0018344b\n"
        ".Lf183342_00183813:\n"
        "cld\n" /* line 1003 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "subl %ecx, (%esi)\n" /* input */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1170 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf183342_0018382e:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1046 */
        "movl -0x20(%ebp), %ecx\n" /* command */
        "movswl 4(%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl 0x10(%ebp), %ebx\n" /* scriptData, token */
        "orl $0x10, 0x50(%eax, %ebx)\n"
        "jmp .Lf183342_0018374a\n"
        ".Lf183342_0018384c:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1034 */
        "movl -0x20(%ebp), %ecx\n" /* command */
        "movswl 4(%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "addl 0x10(%ebp), %eax\n" /* scriptData */
        "pxor %xmm0, %xmm0\n"
        "ucomiss 0x44(%eax), %xmm0\n"
        "jp .Lf183342_00183870\n"
        "je .Lf183342_001836f0\n"
        ".Lf183342_00183870:\n"
        "orl $2, 0x50(%eax)\n" /* line 1036 */
        "jmp .Lf183342_001836f0\n"
        ".Lf183342_00183879:\n"
        "xorl %ecx, %ecx\n" /* line 1042 */
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1045 */
        "movl 0xc(%ebp), %edx\n" /* scriptItem */
        "movl 8(%edx, %eax, 4), %eax\n"
        "cmpl $1, %eax\n"
        "jne .Lf183342_0018372c\n"
        "jmp .Lf183342_0018382e\n"
    );
}

/* line 1210 */
static __attribute__((naked))
void BG_AnimParseAnimScript(animScriptData_t *scriptData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1210 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x15c, %esp\n"
        "movl %eax, -0x148(%ebp)\n"
        "movl %edx, %esi\n" /* pLoadAnims */
        "movl %ecx, %edi\n" /* piNumAnims */
        /* { scope 1 */
        "movl bScriptFileLoaded, %edx\n" /* line 1232 */
        "testl %edx, %edx\n"
        "je .Lf183890_00183c6e\n"
        ".Lf183890_001838b4:\n"
        "movl %eax, globalScriptData\n" /* line 1257 */
        "movl %esi, g_pLoadAnims\n" /* line 1259 | token */
        "movl %edi, g_piNumLoadAnims\n" /* line 1260 | piNumAnims */
        "movl $0x400, 8(%esp)\n" /* line 570 */
        "movl $0, 4(%esp)\n"
        "movl $weaponStrings, (%esp)\n"
        "calll memset\n"
        "calll BG_LoadWeaponStrings\n" /* line 571 */
        "movl $0x480, 8(%esp)\n" /* line 1270 */
        "movl $0, 4(%esp)\n"
        "movl $defineStr, (%esp)\n"
        "calll memset\n"
        "movl $0x2710, 8(%esp)\n" /* line 1271 */
        "movl $0, 4(%esp)\n"
        "movl $defineStrings, (%esp)\n"
        "calll memset\n"
        "movl $numDefines, %edi\n" /* line 1272 | piNumAnims */
        "cld\n"
        "movl $9, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* piNumAnims */
        "movl $0, defineStringsOffset\n" /* line 1273 */
        "movb $1, %al\n"
        "leal -0x2c(%ebp), %edx\n" /* indexes */
        ".Lf183890_0018393c:\n"
        "movl $0xffffffff, -4(%edx, %eax, 4)\n" /* line 1276 */
        "addl $1, %eax\n"
        "cmpl $4, %eax\n" /* line 1275 */
        "jne .Lf183890_0018393c\n"
        "movl $input, -0x1c(%ebp)\n" /* line 1280 | text_p */
        "movl $str_00221c74, (%esp)\n" /* line 1281 */
        "calll Com_BeginParseSession\n"
        "movl $0, -0x138(%ebp)\n" /* currentScriptItem */
        "movl $0, -0x140(%ebp)\n" /* parseMode */
        "movl $0, -0x134(%ebp)\n" /* indentLevel */
        "movl $0, -0x13c(%ebp)\n" /* currentScript */
        ".Lf183890_00183987:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 1286 | text_p */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* token */
        "testl %eax, %eax\n" /* line 1287 */
        "je .Lf183890_001839f0\n"
        ".Lf183890_00183998:\n"
        "cmpb $0, (%eax)\n"
        "je .Lf183890_001839f0\n"
        "movl $1, 8(%esp)\n" /* line 1295 */
        "movl $animParseModesStr, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll BG_IndexForString\n"
        "movl %eax, %ebx\n" /* iLen */
        "testl %eax, %eax\n" /* line 1296 */
        "js .Lf183890_00183a32\n"
        "movl -0x134(%ebp), %edi\n" /* line 1298 | indentLevel, piNumAnims */
        "testl %edi, %edi\n" /* piNumAnims */
        "jne .Lf183890_00183a20\n"
        ".Lf183890_001839c5:\n"
        "movl %ebx, -0x140(%ebp)\n" /* line 1301 | iLen, parseMode */
        "movl $0, parseMovetype\n" /* line 1302 */
        "movl $0xffffffff, parseEvent\n" /* line 1303 */
        "leal -0x1c(%ebp), %edx\n" /* line 1286 | text_p */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* token */
        "testl %eax, %eax\n" /* line 1287 */
        "jne .Lf183890_00183998\n"
        ".Lf183890_001839f0:\n"
        "movl -0x134(%ebp), %eax\n" /* line 1289 | indentLevel */
        "testl %eax, %eax\n"
        "je .Lf183890_00183a06\n"
        "movl $str_002af280, (%esp)\n" /* line 1290 */
        "calll BG_AnimParseError\n"
        ".Lf183890_00183a06:\n"
        "movl $0, globalFilename\n" /* line 1553 */
        "calll Com_EndParseSession\n" /* line 1555 */
        /* } scope */
        "addl $0x15c, %esp\n" /* line 1556 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf183890_00183a20:\n"
        "movl %esi, 4(%esp)\n" /* line 1299 | token */
        "movl $str_002af2b4, (%esp)\n" /* "BG_AnimParseAnimScript: unexpected '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_001839c5\n"
        ".Lf183890_00183a32:\n"
        "cmpl $4, -0x140(%ebp)\n" /* line 1307 | parseMode */
        "ja .Lf183890_00183987\n"
        "movl -0x140(%ebp), %ecx\n" /* parseMode */
        "jmpl *.Lparsemode_jmptable(, %ecx, 4)\n"
        ".Lparsemode_case0:\n"
        "movl $str_002160dc, 4(%esp)\n" /* line 1311 */
        "movl %esi, (%esp)\n" /* token */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183890_00183987\n"
        "leal -0x1c(%ebp), %esi\n" /* line 1314 | text_p, token */
        "movl %esi, (%esp)\n" /* token */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* iLen */
        "testl %eax, %eax\n" /* line 1315 */
        "je .Lf183890_00183d19\n"
        "cmpb $0, (%eax)\n"
        "je .Lf183890_00183d19\n"
        ".Lf183890_00183a82:\n"
        "movl $0, 8(%esp)\n" /* line 1317 */
        "movl $animConditionsStr, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iLen */
        "calll BG_IndexForString\n"
        "movl %eax, -0x130(%ebp)\n" /* defineType */
        "movl animConditionsTable(, %eax, 8), %ecx\n" /* line 1320 */
        "testl %ecx, %ecx\n"
        "jne .Lf183890_00183f3e\n"
        ".Lf183890_00183aaf:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1324 | text_p */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %esi\n" /* token */
        "testl %eax, %eax\n" /* line 1325 */
        "je .Lf183890_00183d08\n"
        "cmpb $0, (%eax)\n"
        "je .Lf183890_00183d08\n"
        ".Lf183890_00183acd:\n"
        "movl -0x130(%ebp), %edx\n" /* line 1329 | defineType */
        "movl numDefines(, %edx, 4), %edx\n"
        "movl %edx, -0x144(%ebp)\n"
        /* { scope 2 */
        "cld\n" /* line 531 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* hash */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* hash */
        "notl %ecx\n"
        "movl defineStringsOffset, %eax\n"
        "addl %eax, %ecx\n"
        "cmpl $0x270f, %ecx\n"
        "ja .Lf183890_00183f28\n"
        ".Lf183890_00183b01:\n"
        "leal defineStrings(%eax), %ebx\n" /* line 536 | pch */
        "movl %esi, 4(%esp)\n" /* line 539 */
        "movl %ebx, (%esp)\n" /* pch */
        "calll strcpy\n"
        "cld\n" /* line 542 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* hash */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* hash */
        "notl %ecx\n"
        "addl %ecx, defineStringsOffset\n"
        /* } scope */
        "movl -0x130(%ebp), %eax\n" /* line 1329 | defineType */
        "shll $4, %eax\n"
        "movl -0x144(%ebp), %ecx\n"
        "leal (%eax, %ecx), %edx\n"
        "movl %ebx, defineStr(, %edx, 8)\n" /* iLen */
        "movl -0x130(%ebp), %esi\n" /* line 1330 | defineType, fname */
        "movl numDefines(, %esi, 4), %esi\n" /* fname */
        "movl %esi, -0x12c(%ebp)\n" /* fname */
        "addl %esi, %eax\n" /* fname */
        "movl defineStr(, %eax, 8), %esi\n" /* fname */
        /* { scope 2 */
        /* { scope 3 */
        "movzbl (%esi), %eax\n" /* line 363 */
        "testb %al, %al\n"
        "jne .Lf183890_00183de4\n"
        ".Lf183890_00183b67:\n"
        "xorl %edi, %edi\n" /* line 369 | hash */
        /* } scope */
        /* } scope */
        ".Lf183890_00183b69:\n"
        "movl -0x130(%ebp), %esi\n" /* line 1330 | defineType, fname */
        "shll $4, %esi\n" /* fname */
        "movl -0x12c(%ebp), %eax\n"
        "leal (%esi, %eax), %edx\n" /* fname */
        "movl $defineStr, %eax\n"
        "movl %edi, 4(%eax, %edx, 8)\n" /* piNumAnims */
        "leal -0x1c(%ebp), %edx\n" /* line 1333 | text_p */
        "movl %edx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* iLen */
        "testl %eax, %eax\n" /* line 1334 */
        "je .Lf183890_00184013\n"
        ".Lf183890_00183b99:\n"
        "movl $str_00222904, 4(%esp)\n" /* line 1336 */
        "movl %ebx, (%esp)\n" /* iLen */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183890_00183f13\n"
        ".Lf183890_00183bb1:\n"
        "movl -0x130(%ebp), %ecx\n" /* line 1340 | defineType */
        "movl animConditionsTable+4(, %ecx, 8), %edx\n"
        "addl numDefines(, %ecx, 4), %esi\n" /* fname */
        "leal defineBits(, %esi, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* text_p */
        "calll BG_ParseConditionBits\n"
        "movl -0x130(%ebp), %esi\n" /* line 1341 | defineType, fname */
        "addl $1, numDefines(, %esi, 4)\n"
        "jmp .Lf183890_00183987\n"
        ".Lparsemode_case1:\n"
        "movl $str_0021e50c, 4(%esp)\n" /* line 1348 */
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183890_00183d2a\n"
        "cmpl $2, -0x134(%ebp)\n" /* line 1351 | indentLevel */
        "jg .Lf183890_00183cf3\n"
        ".Lf183890_00183c0f:\n"
        "movl -0x134(%ebp), %eax\n" /* line 1353 | indentLevel */
        "movl -0x2c(%ebp, %eax, 4), %edx\n"
        "testl %edx, %edx\n"
        "jns .Lf183890_00183c62\n"
        ".Lf183890_00183c1d:\n"
        "movl %esi, 4(%esp)\n" /* line 1455 | fname */
        "movl $str_002af2b4, (%esp)\n" /* "BG_AnimParseAnimScript: unexpected '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183c62\n"
        ".Lparsemode_case3:\n"
        "movl $str_0021e50c, 4(%esp)\n" /* line 1449 */
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183890_00183d76\n"
        "cmpl $2, -0x134(%ebp)\n" /* line 1452 | indentLevel */
        "jg .Lf183890_00183cde\n"
        ".Lf183890_00183c54:\n"
        "movl -0x134(%ebp), %edx\n" /* line 1454 | indentLevel */
        "movl -0x2c(%ebp, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf183890_00183c1d\n"
        ".Lf183890_00183c62:\n"
        "addl $1, -0x134(%ebp)\n" /* line 1457 | indentLevel */
        "jmp .Lf183890_00183987\n"
        ".Lf183890_00183c6e:\n"
        "movl $0, 8(%esp)\n" /* line 1236 */
        "leal -0x20(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl globalFilename, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %ebx\n" /* iLen */
        "testl %eax, %eax\n" /* line 1237 */
        "js .Lf183890_00183ef1\n"
        ".Lf183890_00183c94:\n"
        "cmpl $0x1869e, %ebx\n" /* line 1239 | iLen */
        "ja .Lf183890_00183dc2\n"
        ".Lf183890_00183ca0:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1241 | f */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* iLen */
        "movl $input, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, input(%ebx)\n" /* line 1242 | iLen */
        "movl -0x20(%ebp), %eax\n" /* line 1243 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $1, bScriptFileLoaded\n" /* line 1253 */
        "movl -0x148(%ebp), %eax\n"
        "jmp .Lf183890_001838b4\n"
        ".Lf183890_00183cde:\n"
        "movl %esi, 4(%esp)\n" /* line 1453 | fname */
        "movl $str_002af2b4, (%esp)\n" /* "BG_AnimParseAnimScript: unexpected '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183c54\n"
        ".Lf183890_00183cf3:\n"
        "movl %esi, 4(%esp)\n" /* line 1352 | fname */
        "movl $str_002af2b4, (%esp)\n" /* "BG_AnimParseAnimScript: unexpected '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183c0f\n"
        ".Lf183890_00183d08:\n"
        "movl $str_002af350, (%esp)\n" /* line 1326 */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183acd\n"
        ".Lf183890_00183d19:\n"
        "movl $str_002af2dc, (%esp)\n" /* line 1316 */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183a82\n"
        ".Lf183890_00183d2a:\n"
        "movl $str_0021e508, 4(%esp)\n" /* line 1358 */
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183890_00183e42\n"
        "subl $1, -0x134(%ebp)\n" /* line 1362 | indentLevel */
        "js .Lf183890_00183e18\n"
        "cmpl $1, -0x134(%ebp)\n" /* line 1364 | indentLevel */
        "cmovnel -0x13c(%ebp), %eax\n" /* currentScript */
        "movl %eax, -0x13c(%ebp)\n" /* currentScript */
        ".Lf183890_00183d63:\n"
        "movl -0x134(%ebp), %edx\n" /* line 1367 | indentLevel */
        "movl $0xffffffff, -0x2c(%ebp, %edx, 4)\n"
        "jmp .Lf183890_00183987\n"
        ".Lf183890_00183d76:\n"
        "movl $str_0021e508, 4(%esp)\n" /* line 1459 */
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183890_00183e70\n"
        "subl $1, -0x134(%ebp)\n" /* line 1462 | indentLevel */
        "cmpl $0, -0x134(%ebp)\n" /* line 1463 | indentLevel */
        "jl .Lf183890_00183e2d\n"
        "cmovnel -0x13c(%ebp), %eax\n" /* line 1465 | currentScript */
        "movl %eax, -0x13c(%ebp)\n" /* currentScript */
        ".Lf183890_00183daf:\n"
        "movl -0x134(%ebp), %ecx\n" /* line 1468 | indentLevel */
        "movl $0xffffffff, -0x2c(%ebp, %ecx, 4)\n"
        "jmp .Lf183890_00183987\n"
        ".Lf183890_00183dc2:\n"
        "movl globalFilename, %eax\n" /* line 1240 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002af254, 4(%esp)\n" /* "Couldn't load player animation script %s
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf183890_00183ca0\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf183890_00183de4:\n"
        "xorl %edi, %edi\n" /* line 363 | hash */
        "movl $0x77, %ebx\n"
        ".Lf183890_00183deb:\n"
        "movsbl %al, %eax\n" /* line 365 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movsbl %al, %eax\n" /* line 366 */
        "imull %ebx, %eax\n"
        "addl %eax, %edi\n" /* hash */
        "movzbl -0x76(%esi, %ebx), %eax\n" /* line 363 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf183890_00183deb\n"
        "cmpl $-1, %edi\n" /* line 369 | hash */
        "je .Lf183890_00183b67\n"
        "jmp .Lf183890_00183b69\n"
        /* } scope */
        /* } scope */
        ".Lf183890_00183e18:\n"
        "movl %esi, 4(%esp)\n" /* line 1363 | fname */
        "movl $str_002af2b4, (%esp)\n" /* "BG_AnimParseAnimScript: unexpected '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183d63\n"
        ".Lf183890_00183e2d:\n"
        "movl %esi, 4(%esp)\n" /* line 1464 | fname */
        "movl $str_002af2b4, (%esp)\n" /* "BG_AnimParseAnimScript: unexpected '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183daf\n"
        ".Lf183890_00183e42:\n"
        "movl -0x134(%ebp), %eax\n" /* line 1369 | indentLevel */
        "testl %eax, %eax\n"
        "jne .Lf183890_00183fe7\n"
        "movl -0x2c(%ebp), %eax\n" /* indexes */
        "testl %eax, %eax\n"
        "js .Lf183890_00184287\n"
        ".Lf183890_00183e5b:\n"
        "movl %esi, 4(%esp)\n" /* line 1548 | fname */
        "movl $str_002af2b4, (%esp)\n" /* "BG_AnimParseAnimScript: unexpected '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183987\n"
        ".Lf183890_00183e70:\n"
        "movl -0x134(%ebp), %eax\n" /* line 1470 | indentLevel */
        "testl %eax, %eax\n"
        "jne .Lf183890_00183f53\n"
        "movl -0x2c(%ebp), %edi\n" /* indexes, piNumAnims */
        "testl %edi, %edi\n" /* piNumAnims */
        "jns .Lf183890_00183e5b\n"
        "cmpl $3, -0x140(%ebp)\n" /* line 1472 | parseMode */
        "je .Lf183890_00184324\n"
        "movl $0, 8(%esp)\n" /* line 1500 */
        "movl $animEventTypesStr, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fname */
        "calll BG_IndexForString\n"
        "movl %eax, -0x2c(%ebp)\n" /* indexes */
        "movl %eax, %edx\n" /* line 1501 */
        "shll $9, %edx\n"
        "leal 0x37560(%edx, %eax, 4), %edx\n"
        "movl -0x148(%ebp), %esi\n" /* fname */
        "leal 4(%esi, %edx), %edx\n" /* fname */
        "movl %edx, -0x13c(%ebp)\n" /* currentScript */
        "movl %eax, parseEvent\n" /* line 1503 */
        ".Lf183890_00183ece:\n"
        "movl $0x204, 8(%esp)\n" /* line 1506 */
        "movl $0, 4(%esp)\n"
        "movl -0x13c(%ebp), %eax\n" /* currentScript */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "jmp .Lf183890_00183987\n"
        ".Lf183890_00183ef1:\n"
        "movl globalFilename, %eax\n" /* line 1238 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002af254, 4(%esp)\n" /* "Couldn't load player animation script %s
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf183890_00183c94\n"
        ".Lf183890_00183f13:\n"
        "movl %ebx, 4(%esp)\n" /* line 1337 | iLen */
        "movl $str_002af3c4, (%esp)\n" /* "BG_AnimParseAnimScript: expected '=', found '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183bb1\n"
        /* { scope 2 */
        ".Lf183890_00183f28:\n"
        "movl $str_002aee9c, (%esp)\n" /* line 533 */
        "calll BG_AnimParseError\n"
        "movl defineStringsOffset, %eax\n"
        "jmp .Lf183890_00183b01\n"
        /* } scope */
        ".Lf183890_00183f3e:\n"
        "movl %ebx, 4(%esp)\n" /* line 1321 | iLen */
        "movl $str_002af314, (%esp)\n" /* "BG_AnimParseAnimScript: can not make a define of type '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183aaf\n"
        ".Lf183890_00183f53:\n"
        "cmpl $1, -0x134(%ebp)\n" /* line 1508 | indentLevel */
        "je .Lf183890_00184024\n"
        "cmpl $2, -0x134(%ebp)\n" /* line 1533 | indentLevel */
        "jne .Lf183890_00183e5b\n"
        ".Lf183890_00183f6d:\n"
        "movl $0xffffffff, %edx\n" /* line 1537 */
        "xorl %ebx, %ebx\n" /* iLen */
        "cld\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n" /* fname, piNumAnims */
        "movl %ebx, %eax\n" /* iLen */
        "repne scasb %es:(%edi), %al\n" /* piNumAnims */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl -0x1c(%ebp), %eax\n" /* text_p */
        "subl %ecx, %eax\n"
        "movl %eax, -0x14c(%ebp)\n"
        "movl %eax, -0x1c(%ebp)\n" /* text_p */
        "movl %edx, %ecx\n" /* line 1540 */
        "movl %esi, %edi\n" /* fname, piNumAnims */
        "movl %ebx, %eax\n" /* iLen */
        "repne scasb %es:(%edi), %al\n" /* piNumAnims */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* fname */
        "movl -0x14c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "je .Lf183890_00183fc3\n"
        "movl $str_002af480, (%esp)\n" /* line 1541 */
        "calll BG_AnimParseError\n"
        ".Lf183890_00183fc3:\n"
        "movl -0x148(%ebp), %ecx\n" /* line 1543 */
        "movl %ecx, 8(%esp)\n"
        "movl -0x138(%ebp), %esi\n" /* currentScriptItem, fname */
        "movl %esi, 4(%esp)\n" /* fname */
        "leal -0x1c(%ebp), %eax\n" /* text_p */
        "movl %eax, (%esp)\n"
        "calll BG_ParseCommands\n"
        "jmp .Lf183890_00183987\n"
        ".Lf183890_00183fe7:\n"
        "cmpl $1, -0x134(%ebp)\n" /* line 1386 | indentLevel */
        "je .Lf183890_0018413b\n"
        "cmpl $2, -0x134(%ebp)\n" /* line 1402 | indentLevel */
        "je .Lf183890_001841d3\n"
        "cmpl $3, -0x134(%ebp)\n" /* line 1427 | indentLevel */
        "jne .Lf183890_00183e5b\n"
        "jmp .Lf183890_00183f6d\n"
        ".Lf183890_00184013:\n"
        "movl $str_002af38c, (%esp)\n" /* line 1335 */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00183b99\n"
        ".Lf183890_00184024:\n"
        "movl -0x28(%ebp), %ebx\n" /* line 1508 | iLen */
        "testl %ebx, %ebx\n" /* iLen */
        "jns .Lf183890_00183e5b\n"
        "movl $0xffffffff, %edx\n" /* line 1512 */
        "xorl %ebx, %ebx\n" /* iLen */
        "cld\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n" /* fname, piNumAnims */
        "movl %ebx, %eax\n" /* iLen */
        "repne scasb %es:(%edi), %al\n" /* piNumAnims */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl -0x1c(%ebp), %eax\n" /* text_p */
        "subl %ecx, %eax\n"
        "movl %eax, -0x14c(%ebp)\n"
        "movl %eax, -0x1c(%ebp)\n" /* text_p */
        "movl %edx, %ecx\n" /* line 1515 */
        "movl %esi, %edi\n" /* fname, piNumAnims */
        "movl %ebx, %eax\n" /* iLen */
        "repne scasb %es:(%edi), %al\n" /* piNumAnims */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* fname */
        "movl -0x14c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183890_0018444a\n"
        ".Lf183890_0018407d:\n"
        "leal -0x120(%ebp), %ebx\n" /* line 1518 | tempScriptItem, iLen */
        "movl $0xf4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iLen */
        "calll memset\n"
        "movl %ebx, %edx\n" /* line 1519 | iLen */
        "leal -0x1c(%ebp), %eax\n" /* text_p */
        "calll BG_ParseConditions\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x13c(%ebp), %ecx\n" /* line 1521 | currentScript */
        "cmpl $0x7f, (%ecx)\n"
        "jg .Lf183890_0018426e\n"
        ".Lf183890_001840b7:\n"
        "movl -0x148(%ebp), %esi\n" /* line 1524 | fname */
        "cmpl $0x7ff, 0xb3bb0(%esi)\n" /* fname */
        "jg .Lf183890_00184493\n"
        ".Lf183890_001840cd:\n"
        "movl -0x148(%ebp), %eax\n" /* line 1527 */
        "movl 0xb3bb0(%eax), %edx\n"
        "movl -0x13c(%ebp), %esi\n" /* currentScript, fname */
        "movl (%esi), %ecx\n" /* fname */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl -0x148(%ebp), %esi\n" /* fname */
        "leal 0x39bb0(%esi, %eax, 4), %eax\n" /* fname */
        "movl -0x13c(%ebp), %esi\n" /* currentScript, fname */
        "movl %eax, 4(%esi, %ecx, 4)\n" /* fname */
        "addl $1, %edx\n"
        "movl -0x148(%ebp), %eax\n"
        "movl %edx, 0xb3bb0(%eax)\n"
        "movl (%esi), %eax\n" /* line 1528 | fname */
        "movl 4(%esi, %eax, 4), %edx\n" /* fname */
        "movl %edx, -0x138(%ebp)\n" /* currentScriptItem */
        "addl $1, %eax\n" /* line 1529 */
        "movl %eax, (%esi)\n" /* fname */
        "movl $0xf4, 8(%esp)\n" /* line 1531 */
        "movl %ebx, 4(%esp)\n" /* iLen */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf183890_00183987\n"
        ".Lf183890_0018413b:\n"
        "movl -0x28(%ebp), %eax\n" /* line 1386 */
        "testl %eax, %eax\n"
        "jns .Lf183890_00183e5b\n"
        "movl $0, 8(%esp)\n" /* line 1389 */
        "movl $animMoveTypesStr, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fname */
        "calll BG_IndexForString\n"
        "movl %eax, %ebx\n" /* iLen */
        "movl %eax, -0x28(%ebp)\n"
        "cmpl $1, -0x140(%ebp)\n" /* line 1390 | parseMode */
        "je .Lf183890_0018445b\n"
        "cmpl $2, -0x140(%ebp)\n" /* line 1395 | parseMode */
        "jne .Lf183890_001841a6\n"
        "shll $9, %eax\n" /* line 1397 */
        "leal (%eax, %ebx, 4), %ecx\n"
        "movl -0x2c(%ebp), %edx\n" /* indexes */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "leal 0x20a90(%ecx, %eax, 4), %eax\n"
        "movl -0x148(%ebp), %ecx\n"
        "leal 4(%ecx, %eax), %eax\n"
        "movl %eax, -0x13c(%ebp)\n" /* currentScript */
        ".Lf183890_001841a6:\n"
        "movl $0x204, 8(%esp)\n" /* line 1399 */
        "movl $0, 4(%esp)\n"
        "movl -0x13c(%ebp), %esi\n" /* currentScript, fname */
        "movl %esi, (%esp)\n" /* fname */
        "calll memset\n"
        "movl $1, -0x134(%ebp)\n" /* indentLevel */
        "jmp .Lf183890_00183987\n"
        ".Lf183890_001841d3:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1402 */
        "testl %eax, %eax\n"
        "jns .Lf183890_00183e5b\n"
        "movl $0xffffffff, %edx\n" /* line 1406 */
        "xorl %ebx, %ebx\n" /* iLen */
        "cld\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n" /* fname, piNumAnims */
        "movl %ebx, %eax\n" /* iLen */
        "repne scasb %es:(%edi), %al\n" /* piNumAnims */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl -0x1c(%ebp), %eax\n" /* text_p */
        "subl %ecx, %eax\n"
        "movl %eax, -0x14c(%ebp)\n"
        "movl %eax, -0x1c(%ebp)\n" /* text_p */
        "movl %edx, %ecx\n" /* line 1409 */
        "movl %esi, %edi\n" /* fname, piNumAnims */
        "movl %ebx, %eax\n" /* iLen */
        "repne scasb %es:(%edi), %al\n" /* piNumAnims */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* fname */
        "movl -0x14c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "je .Lf183890_00184234\n"
        "movl $str_002af480, (%esp)\n" /* line 1410 */
        "calll BG_AnimParseError\n"
        ".Lf183890_00184234:\n"
        "leal -0x120(%ebp), %ebx\n" /* line 1412 | tempScriptItem, iLen */
        "movl $0xf4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iLen */
        "calll memset\n"
        "movl %ebx, %edx\n" /* line 1413 | iLen */
        "leal -0x1c(%ebp), %eax\n" /* text_p */
        "calll BG_ParseConditions\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x13c(%ebp), %ecx\n" /* line 1415 | currentScript */
        "cmpl $0x7f, (%ecx)\n"
        "jle .Lf183890_001840b7\n"
        ".Lf183890_0018426e:\n"
        "movl $0x80, 4(%esp)\n" /* line 1522 */
        "movl $str_002af4a8, (%esp)\n" /* "BG_AnimParseAnimScript: exceeded maximum items per script (%" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_001840b7\n"
        ".Lf183890_00184287:\n"
        "movl $str_002af3f8, 4(%esp)\n" /* line 1371 */
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf183890_001842a7\n"
        "movl $str_002af400, (%esp)\n" /* line 1372 */
        "calll BG_AnimParseError\n"
        ".Lf183890_001842a7:\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 1375 | text_p */
        "movl %ecx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* iLen */
        "testl %eax, %eax\n" /* line 1376 */
        "je .Lf183890_00184439\n"
        ".Lf183890_001842bc:\n"
        "movl $0, 8(%esp)\n" /* line 1378 */
        "movl $animStateStr, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iLen */
        "calll BG_IndexForString\n"
        "movl %eax, -0x2c(%ebp)\n" /* indexes */
        "leal -0x1c(%ebp), %esi\n" /* line 1381 | text_p, fname */
        "movl %esi, (%esp)\n" /* fname */
        "calll Com_Parse\n"
        "testl %eax, %eax\n" /* line 1382 */
        "je .Lf183890_001842fa\n"
        "movl $str_0021e50c, 4(%esp)\n" /* "{" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf183890_00184315\n"
        ".Lf183890_001842fa:\n"
        "movl $str_002af458, (%esp)\n" /* line 1383 */
        "calll BG_AnimParseError\n"
        "movl $1, -0x134(%ebp)\n" /* indentLevel */
        "jmp .Lf183890_00183987\n"
        ".Lf183890_00184315:\n"
        "movl $1, -0x134(%ebp)\n" /* line 1281 | indentLevel */
        "jmp .Lf183890_00183987\n"
        ".Lf183890_00184324:\n"
        "movl $str_002af524, 4(%esp)\n" /* line 1474 */
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf183890_00184402\n"
        ".Lf183890_0018433c:\n"
        "leal -0x1c(%ebp), %esi\n" /* line 1478 | text_p, fname */
        "movl %esi, (%esp)\n" /* fname */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* iLen */
        "testl %eax, %eax\n" /* line 1479 */
        "je .Lf183890_00184428\n"
        ".Lf183890_00184351:\n"
        "movl $0, 8(%esp)\n" /* line 1481 */
        "movl $animStateStr, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iLen */
        "calll BG_IndexForString\n"
        "movl %eax, %ebx\n" /* iLen */
        "leal -0x1c(%ebp), %eax\n" /* line 1484 | text_p */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %esi\n" /* fname */
        "testl %eax, %eax\n" /* line 1485 */
        "je .Lf183890_00184417\n"
        ".Lf183890_00184380:\n"
        "movl $0, 8(%esp)\n" /* line 1487 */
        "movl $animStateStr, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fname */
        "calll BG_IndexForString\n"
        "movl %eax, -0x2c(%ebp)\n" /* indexes */
        "movl %eax, %edx\n" /* line 1489 */
        "shll $9, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %ebx, %edx\n" /* iLen */
        "shll $4, %edx\n"
        "shll $0xb, %ebx\n" /* iLen */
        "addl %ebx, %edx\n" /* iLen */
        "leal 0x35520(%eax, %edx), %eax\n"
        "movl -0x148(%ebp), %edx\n"
        "leal 4(%edx, %eax), %eax\n"
        "movl %eax, -0x13c(%ebp)\n" /* currentScript */
        "leal -0x1c(%ebp), %ecx\n" /* line 1492 | text_p */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "testl %eax, %eax\n" /* line 1493 */
        "je .Lf183890_001843e7\n"
        "movl $str_0021e50c, 4(%esp)\n" /* "{" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf183890_001843f3\n"
        ".Lf183890_001843e7:\n"
        "movl $str_002af458, (%esp)\n" /* line 1494 */
        "calll BG_AnimParseError\n"
        ".Lf183890_001843f3:\n"
        "movl $1, -0x134(%ebp)\n" /* indentLevel */
        "jmp .Lf183890_00183ece\n"
        ".Lf183890_00184402:\n"
        "movl %esi, 4(%esp)\n" /* line 1475 | fname */
        "movl $str_002af530, (%esp)\n" /* "BG_AnimParseAnimScript: expected 'statechange', got '%s'" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_0018433c\n"
        ".Lf183890_00184417:\n"
        "movl $str_002af56c, (%esp)\n" /* line 1486 */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00184380\n"
        ".Lf183890_00184428:\n"
        "movl $str_002af56c, (%esp)\n" /* line 1480 */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_00184351\n"
        ".Lf183890_00184439:\n"
        "movl $str_002af42c, (%esp)\n" /* line 1377 */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_001842bc\n"
        ".Lf183890_0018444a:\n"
        "movl $str_002af480, (%esp)\n" /* line 1516 */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_0018407d\n"
        ".Lf183890_0018445b:\n"
        "shll $9, %eax\n" /* line 1392 */
        "leal (%eax, %ebx, 4), %ecx\n"
        "movl -0x2c(%ebp), %edx\n" /* indexes */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "leal 0xc000(%ecx, %eax, 4), %eax\n"
        "movl -0x148(%ebp), %edx\n"
        "leal 4(%edx, %eax), %eax\n"
        "movl %eax, -0x13c(%ebp)\n" /* currentScript */
        "movl %ebx, parseMovetype\n" /* line 1393 | iLen */
        "jmp .Lf183890_001841a6\n"
        ".Lf183890_00184493:\n"
        "movl $0x800, 4(%esp)\n" /* line 1525 */
        "movl $str_002af4e8, (%esp)\n" /* "BG_AnimParseAnimScript: exceeded maximum global items (%i)" */
        "calll BG_AnimParseError\n"
        "jmp .Lf183890_001840cd\n"
        ".section .rodata\n"
        ".align 4\n"
        ".Lparsemode_jmptable:\n"
        ".long .Lparsemode_case0\n"
        ".long .Lparsemode_case1\n"
        ".long .Lparsemode_case1\n"
        ".long .Lparsemode_case3\n"
        ".long .Lparsemode_case3\n"
        ".section .text\n"
    );
}

/* line 554 */
__attribute__((naked))
void BG_InitWeaponString(int index, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 554 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* name */
        "movl 8(%ebp), %eax\n" /* line 556 | index */
        "movl %edi, weaponStrings(, %eax, 8)\n" /* name */
        /* { scope 1 */
        "movzbl (%edi), %eax\n" /* line 363 */
        "testb %al, %al\n"
        "jne .Lf1844ac_001844df\n"
        ".Lf1844ac_001844c9:\n"
        "xorl %esi, %esi\n" /* line 369 | hash */
        /* } scope */
        ".Lf1844ac_001844cb:\n"
        "movl $weaponStrings, %eax\n" /* line 557 */
        "movl 8(%ebp), %edx\n" /* index */
        "movl %esi, 4(%eax, %edx, 8)\n" /* hash */
        "addl $0x1c, %esp\n" /* line 558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1844ac_001844df:\n"
        "xorl %esi, %esi\n" /* line 363 | hash */
        "movl $0x77, %ebx\n"
        ".Lf1844ac_001844e6:\n"
        "movsbl %al, %eax\n" /* line 365 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movsbl %al, %eax\n" /* line 366 */
        "imull %ebx, %eax\n"
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 363 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf1844ac_001844e6\n"
        "cmpl $-1, %esi\n" /* line 369 | hash */
        "je .Lf1844ac_001844c9\n"
        "jmp .Lf1844ac_001844cb\n"
    );
}

/* line 3546 */
__attribute__((naked))
void BG_LoadAnim(playerState_t *ps, char *animName, animBodyPart_t bodyPart, qboolean setTimer, qboolean isContinue, qboolean force)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3546 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl $0x9000, 4(%esp)\n" /* line 3549 */
        "leal -0x20(%ebp), %eax\n" /* playerAnims_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x20(%ebp), %edx\n" /* playerAnims_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %ebx\n" /* duration */
        "movl $0, -0x1c(%ebp)\n" /* line 3554 | iNumPlayerAnims */
        "movl bgs, %eax\n" /* line 3494 */
        "movl 0xb3be8(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "addl $0xb3bcc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021df18, 4(%esp)\n" /* "root" */
        "movl $str_002aef88, (%esp)\n" /* "multiplayer" */
        "calll Scr_FindAnim\n"
        "movl bgs, %eax\n" /* line 3495 */
        "movl 0xb3be8(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "addl $0xb3bd0, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002af59c, 4(%esp)\n" /* "torso" */
        "movl $str_002aef88, (%esp)\n" /* "multiplayer" */
        "calll Scr_FindAnim\n"
        "movl bgs, %eax\n" /* line 3496 */
        "movl 0xb3be8(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "addl $0xb3bd4, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002af5a4, 4(%esp)\n" /* "legs" */
        "movl $str_002aef88, (%esp)\n" /* "multiplayer" */
        "calll Scr_FindAnim\n"
        "movl bgs, %eax\n" /* line 3497 */
        "movl 0xb3be8(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "addl $0xb3bd8, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002af5ac, 4(%esp)\n" /* "turning" */
        "movl $str_002aef88, (%esp)\n" /* "multiplayer" */
        "calll Scr_FindAnim\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 3559 | iNumPlayerAnims */
        "movl %ebx, %edx\n" /* duration */
        "movl bgs, %eax\n"
        "calll BG_AnimParseAnimScript\n"
        "jmp .Ldbg_bganim_skip\n"
        ".Ldbg_bganim_str: .asciz \"DBG: BG_LoadAnim before Scr_PrecacheAnimTrees, memtree alloc=%d bytes=%d\\n\"\n"
        ".Ldbg_bganim_skip:\n"
        "movl scrMemTreeGlob+525096, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl scrMemTreeGlob+525092, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $.Ldbg_bganim_str, (%esp)\n"
        "calll Com_Printf\n"
        "movl bgs, %eax\n" /* line 3561 */
        "movl 0xb3be8(%eax), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xb3bf8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_PrecacheAnimTrees\n"
        "movl bgs, %esi\n" /* line 3529 | bodyPart */
        "movl $str_002aef88, (%esp)\n" /* line 3510 | "multiplayer" */
        "calll Scr_FindAnimTree_asm\n" /* wrapper returns in eax, not hidden ptr */
        "movl %eax, %ebx\n" /* duration */
        "testl %eax, %eax\n" /* line 3511 */
        "je 0x184a28\n"
        "movl %ebx, 0xb3bc8(%esi)\n" /* line 3529 | duration, bodyPart */
        "movl bgs, %edx\n" /* line 3530 */
        "movl 0xb3bc8(%edx), %eax\n"
        "movl %eax, 0xb3bb4(%edx)\n"
        "movl bgs, %edx\n" /* line 3531 */
        "movzwl 0xb3bd0(%edx), %eax\n"
        "movw %ax, 0xb3bb8(%edx)\n"
        "movl bgs, %edx\n" /* line 3532 */
        "movzwl 0xb3bd4(%edx), %eax\n"
        "movw %ax, 0xb3bba(%edx)\n"
        "movl bgs, %edx\n" /* line 3533 */
        "movzwl 0xb3bd8(%edx), %eax\n"
        "movw %ax, 0xb3bbc(%edx)\n"
        "calll Scr_EndLoadAnimTrees\n" /* line 3565 */
        "movl globalScriptData, %ebx\n" /* line 668 */
        "movl 0xb3bb4(%ebx), %eax\n" /* line 669 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl %eax, (%esp)\n" /* line 670 */
        "calll XAnimGetAnimTreeSize\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl globalScriptData, %eax\n" /* line 672 */
        "movl -0x50(%ebp), %edx\n"
        /* TRUNCATED: remaining BG_LoadAnim logic not yet decompiled.
         * Original continues with animation index setup using treeSize.
         * For now, clean up and return safely. */
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1953 */
__attribute__((naked))
int BG_ExecuteCommand(playerState_t *ps, animScriptCommand_t *scriptCommand, qboolean setTimer, qboolean isContinue, qboolean force)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1953 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ps */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 1958 | scriptCommand */
        "movzwl (%eax), %ecx\n"
        "testw %cx, %cx\n"
        "jne .Lf184a5e_00184b1d\n"
        "movl $0xffffffff, -0x28(%ebp)\n" /* duration */
        "xorl %esi, %esi\n" /* playedLegsAnim */
        ".Lf184a5e_00184a82:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1967 | scriptCommand */
        "movzwl 2(%edx), %ebx\n" /* animNum */
        "testw %bx, %bx\n" /* animNum */
        "je .Lf184a5e_00184ae8\n"
        "movswl 8(%edx), %eax\n" /* line 1969 */
        "addl $0x32, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* duration */
        "movzwl (%edx), %eax\n" /* line 1971 */
        "cmpw $1, %ax\n"
        "je .Lf184a5e_00184b86\n"
        "cmpw $3, %ax\n"
        "je .Lf184a5e_00184b86\n"
        "movswl %bx, %edx\n" /* line 1974 | animNum, bodyPart */
        "movl 0xc(%ebp), %eax\n" /* scriptCommand */
        "movswl 6(%eax), %ecx\n" /* animNum */
        /* { scope 2: wasSet, wasSet */
        "movl -0x28(%ebp), %eax\n" /* line 1832 | duration */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184c0c\n"
        "movl -0x28(%ebp), %eax\n" /* duration */
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf184a5e_00184aca:\n"
        "cmpl $2, %edx\n" /* line 1837 */
        "je .Lf184a5e_00184c5e\n"
        "cmpl $3, %edx\n"
        "je .Lf184a5e_00184c45\n"
        "subl $1, %edx\n"
        "je .Lf184a5e_00184c45\n"
        ".Lf184a5e_00184ae5:\n"
        "movl 0xc(%ebp), %edx\n" /* scriptCommand */
        /* } scope */
        ".Lf184a5e_00184ae8:\n"
        "movl 0xc(%edx), %eax\n" /* line 1977 */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184b07\n"
        "movl %eax, 4(%esp)\n" /* line 1979 */
        "movl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "movl globalScriptData, %eax\n"
        "calll *0xb3bc4(%eax)\n"
        ".Lf184a5e_00184b07:\n"
        "testl %esi, %esi\n" /* line 1982 | playedLegsAnim */
        "movl $0xffffffff, %eax\n"
        "cmovnel -0x28(%ebp), %eax\n" /* duration */
        "movl %eax, -0x28(%ebp)\n" /* duration */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1988 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf184a5e_00184b1d:\n"
        "movl %eax, %edx\n"
        /* { scope 1 */
        "movswl 8(%eax), %eax\n" /* line 1960 */
        "addl $0x32, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* duration */
        "cmpw $1, %cx\n" /* line 1962 */
        "je .Lf184a5e_00184bcb\n"
        "cmpw $3, %cx\n"
        "je .Lf184a5e_00184e35\n"
        "movswl %cx, %edx\n" /* line 1965 | animNum, bodyPart */
        "movl 0xc(%ebp), %eax\n" /* scriptCommand */
        "movswl 4(%eax), %ecx\n" /* animNum */
        /* { scope 2: wasSet, wasSet */
        "movl -0x28(%ebp), %eax\n" /* line 1832 | duration */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184c26\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1835 */
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "movl 0x48(%eax), %ebx\n"
        "addl $0x32, %ebx\n"
        ".Lf184a5e_00184b64:\n"
        "cmpl $2, %edx\n" /* line 1837 */
        "je .Lf184a5e_00184e3d\n"
        "cmpl $3, %edx\n"
        "je .Lf184a5e_00184d00\n"
        "subl $1, %edx\n"
        "je .Lf184a5e_00184d00\n"
        ".Lf184a5e_00184b7f:\n"
        "xorl %esi, %esi\n" /* line 1919 */
        "jmp .Lf184a5e_00184a82\n"
        /* } scope */
        ".Lf184a5e_00184b86:\n"
        "movswl %bx, %edx\n" /* line 1972 | animNum, bodyPart */
        "movl 0xc(%ebp), %eax\n" /* scriptCommand */
        "movswl 6(%eax), %ecx\n" /* animNum */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        "movl -0x28(%ebp), %eax\n" /* line 1832 | duration */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184c2e\n"
        "movl -0x28(%ebp), %esi\n" /* duration */
        ".Lf184a5e_00184b9e:\n"
        "cmpl $2, %edx\n" /* line 1837 */
        "je .Lf184a5e_00184ef6\n"
        "cmpl $3, %edx\n"
        "je .Lf184a5e_00184d50\n"
        "subl $1, %edx\n"
        "je .Lf184a5e_00184d50\n"
        ".Lf184a5e_00184bb9:\n"
        "movl $0xffffffff, %esi\n" /* line 1928 */
        /* } scope */
        /* } scope */
        ".Lf184a5e_00184bbe:\n"
        "notl %esi\n" /* line 1972 | playedLegsAnim */
        "shrl $0x1f, %esi\n" /* playedLegsAnim */
        "movl 0xc(%ebp), %edx\n" /* scriptCommand, bodyPart */
        "jmp .Lf184a5e_00184ae8\n"
        ".Lf184a5e_00184bcb:\n"
        "movl %edx, %eax\n" /* bodyPart */
        ".Lf184a5e_00184bcd:\n"
        "movswl %cx, %edx\n" /* line 1963 | bodyPart */
        "movswl 4(%eax), %ebx\n" /* animNum */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        "movl -0x28(%ebp), %esi\n" /* line 1832 | duration */
        "testl %esi, %esi\n"
        "je .Lf184a5e_00184e1e\n"
        "movl -0x28(%ebp), %esi\n" /* duration */
        ".Lf184a5e_00184be2:\n"
        "cmpl $2, %edx\n" /* line 1837 */
        "je .Lf184a5e_00184e86\n"
        "cmpl $3, %edx\n"
        "je .Lf184a5e_00184db7\n"
        "subl $1, %edx\n"
        "je .Lf184a5e_00184db7\n"
        ".Lf184a5e_00184bfd:\n"
        "movl $0xffffffff, %esi\n" /* line 1928 */
        /* } scope */
        /* } scope */
        "notl %esi\n" /* line 1963 | playedLegsAnim */
        "shrl $0x1f, %esi\n" /* playedLegsAnim */
        "jmp .Lf184a5e_00184a82\n"
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_00184c0c:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1835 */
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "movl 0x48(%eax), %eax\n"
        "addl $0x32, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "jmp .Lf184a5e_00184aca\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_00184c26:\n"
        "movl -0x28(%ebp), %ebx\n" /* line 1832 | duration */
        "jmp .Lf184a5e_00184b64\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_00184c2e:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1835 */
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "movl 0x48(%eax), %esi\n"
        "addl $0x32, %esi\n"
        "jmp .Lf184a5e_00184b9e\n"
        /* } scope */
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_00184c45:\n"
        "cmpl $0x31, 0x78(%edi)\n" /* line 1842 */
        "jle .Lf184a5e_00184cbb\n"
        "movl 0x18(%ebp), %eax\n" /* force */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184cbb\n"
        ".Lf184a5e_00184c52:\n"
        "cmpw $3, %bx\n" /* line 1896 */
        "jne .Lf184a5e_00184ae5\n"
        "xorl %ecx, %ecx\n" /* line 1899 */
        ".Lf184a5e_00184c5e:\n"
        "cmpl $0x31, 0x80(%edi)\n" /* line 1903 */
        "jg .Lf184a5e_00184f61\n"
        ".Lf184a5e_00184c6b:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1905 | isContinue */
        "testl %ebx, %ebx\n"
        "je .Lf184a5e_00184f86\n"
        "movl 0x84(%edi), %edx\n"
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ecx\n"
        "je .Lf184a5e_00185038\n"
        ".Lf184a5e_00184c89:\n"
        "andl $0x200, %edx\n" /* line 1907 */
        "xorb $2, %dh\n"
        "orl %edx, %ecx\n"
        "movl %ecx, 0x84(%edi)\n"
        "movl 0x10(%ebp), %edx\n" /* line 1908 | setTimer */
        "testl %edx, %edx\n"
        "je .Lf184a5e_00184caa\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1909 */
        "movl %eax, 0x80(%edi)\n"
        ".Lf184a5e_00184caa:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1910 */
        "movl %edx, 0x8c(%edi)\n"
        "movl 0xc(%ebp), %edx\n" /* scriptCommand */
        "jmp .Lf184a5e_00184ae8\n"
        ".Lf184a5e_00184cbb:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1844 | isContinue */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184fb6\n"
        "movl 0x7c(%edi), %edx\n"
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ecx\n"
        "je .Lf184a5e_001850c2\n"
        ".Lf184a5e_00184cd6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1847 */
        "movl %eax, 0x88(%edi)\n"
        "andl $0x200, %edx\n" /* line 1848 */
        "xorb $2, %dh\n"
        "orl %edx, %ecx\n"
        "movl %ecx, 0x7c(%edi)\n"
        "movl 0x10(%ebp), %edx\n" /* line 1849 | setTimer */
        "testl %edx, %edx\n"
        "je .Lf184a5e_00184c52\n"
        "movl %eax, 0x78(%edi)\n" /* line 1850 */
        "jmp .Lf184a5e_00184c52\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_00184d00:\n"
        "cmpl $0x31, 0x78(%edi)\n" /* line 1842 */
        "jg .Lf184a5e_00184f74\n"
        ".Lf184a5e_00184d0a:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1844 | isContinue */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184fbe\n"
        "movl 0x7c(%edi), %edx\n"
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf184a5e_00184fc1\n"
        "movl 0x10(%ebp), %eax\n" /* line 1857 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184b7f\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "cmpb $0, 0x50(%eax)\n"
        "jns .Lf184a5e_00184b7f\n"
        ".Lf184a5e_00184d46:\n"
        "movl %ebx, 0x78(%edi)\n" /* line 1859 */
        "xorl %esi, %esi\n"
        "jmp .Lf184a5e_00184a82\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_00184d50:\n"
        "cmpl $0x31, 0x78(%edi)\n" /* line 1842 */
        "jle .Lf184a5e_00184d75\n"
        "movl 0x18(%ebp), %eax\n" /* force */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184d75\n"
        ".Lf184a5e_00184d5d:\n"
        "movl $0, -0x20(%ebp)\n" /* line 1859 | wasSet */
        ".Lf184a5e_00184d64:\n"
        "cmpw $3, %bx\n" /* line 1896 */
        "jne .Lf184a5e_00184f0d\n"
        "xorl %ecx, %ecx\n" /* line 1899 */
        "jmp .Lf184a5e_00184efd\n"
        ".Lf184a5e_00184d75:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1844 | isContinue */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184fe7\n"
        "movl 0x7c(%edi), %edx\n"
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ecx\n"
        "je .Lf184a5e_001850ee\n"
        ".Lf184a5e_00184d90:\n"
        "movl %esi, 0x88(%edi)\n" /* line 1847 */
        "andl $0x200, %edx\n" /* line 1848 */
        "xorb $2, %dh\n"
        "orl %edx, %ecx\n"
        "movl %ecx, 0x7c(%edi)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1849 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184dae\n"
        "movl %esi, 0x78(%edi)\n" /* line 1850 */
        ".Lf184a5e_00184dae:\n"
        "movl $1, -0x20(%ebp)\n" /* wasSet */
        "jmp .Lf184a5e_00184d64\n"
        /* } scope */
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_00184db7:\n"
        "cmpl $0x31, 0x78(%edi)\n" /* line 1842 */
        "jle .Lf184a5e_00184ddc\n"
        "movl 0x18(%ebp), %eax\n" /* force */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184ddc\n"
        ".Lf184a5e_00184dc4:\n"
        "movl $0, -0x24(%ebp)\n" /* line 1859 | wasSet */
        ".Lf184a5e_00184dcb:\n"
        "cmpw $3, %cx\n" /* line 1896 */
        "jne .Lf184a5e_00184e9d\n"
        "xorl %ebx, %ebx\n" /* line 1899 */
        "jmp .Lf184a5e_00184e8d\n"
        ".Lf184a5e_00184ddc:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1844 | isContinue */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184fef\n"
        "movl 0x7c(%edi), %edx\n"
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ebx\n"
        "je .Lf184a5e_0018511e\n"
        ".Lf184a5e_00184df7:\n"
        "movl %esi, 0x88(%edi)\n" /* line 1847 */
        "andl $0x200, %edx\n" /* line 1848 */
        "xorb $2, %dh\n"
        "orl %edx, %ebx\n"
        "movl %ebx, 0x7c(%edi)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1849 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184e15\n"
        "movl %esi, 0x78(%edi)\n" /* line 1850 */
        ".Lf184a5e_00184e15:\n"
        "movl $1, -0x24(%ebp)\n" /* wasSet */
        "jmp .Lf184a5e_00184dcb\n"
        ".Lf184a5e_00184e1e:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1835 */
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "movl 0x48(%eax), %esi\n"
        "addl $0x32, %esi\n"
        "jmp .Lf184a5e_00184be2\n"
        ".Lf184a5e_00184e35:\n"
        "movl 0xc(%ebp), %eax\n" /* scriptCommand */
        "jmp .Lf184a5e_00184bcd\n"
        /* } scope */
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_00184e3d:\n"
        "cmpl $0x31, 0x80(%edi)\n" /* line 1903 */
        "jg .Lf184a5e_00184f91\n"
        ".Lf184a5e_00184e4a:\n"
        "movl 0x14(%ebp), %esi\n" /* line 1905 | isContinue */
        "testl %esi, %esi\n"
        "jne .Lf184a5e_00184ff7\n"
        "movl 0x84(%edi), %edx\n"
        ".Lf184a5e_00184e5b:\n"
        "andl $0x200, %edx\n" /* line 1907 */
        "xorb $2, %dh\n"
        "orl %edx, %ecx\n"
        "movl %ecx, 0x84(%edi)\n"
        "movl 0x10(%ebp), %edx\n" /* line 1908 | setTimer */
        "testl %edx, %edx\n"
        "je .Lf184a5e_00184e79\n"
        "movl %ebx, 0x80(%edi)\n" /* line 1909 */
        ".Lf184a5e_00184e79:\n"
        "movl %ebx, 0x8c(%edi)\n" /* line 1910 */
        "xorl %esi, %esi\n"
        "jmp .Lf184a5e_00184a82\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_00184e86:\n"
        "movl $0, -0x24(%ebp)\n" /* line 1837 | wasSet */
        ".Lf184a5e_00184e8d:\n"
        "cmpl $0x31, 0x80(%edi)\n" /* line 1903 */
        "jle .Lf184a5e_00184eb2\n"
        "movl 0x18(%ebp), %eax\n" /* force */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184eb2\n"
        ".Lf184a5e_00184e9d:\n"
        "movl -0x24(%ebp), %edx\n" /* line 1928 | wasSet */
        "testl %edx, %edx\n"
        "je .Lf184a5e_00184bfd\n"
        /* } scope */
        /* } scope */
        "notl %esi\n" /* line 1963 | playedLegsAnim */
        "shrl $0x1f, %esi\n" /* playedLegsAnim */
        "jmp .Lf184a5e_00184a82\n"
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_00184eb2:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1905 | isContinue */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184fa3\n"
        "movl 0x84(%edi), %edx\n"
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ebx\n"
        "je .Lf184a5e_0018506a\n"
        ".Lf184a5e_00184ed0:\n"
        "andl $0x200, %edx\n" /* line 1907 */
        "xorb $2, %dh\n"
        "orl %edx, %ebx\n"
        "movl %ebx, 0x84(%edi)\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1908 | setTimer */
        "testl %ebx, %ebx\n"
        "je .Lf184a5e_00184eee\n"
        "movl %esi, 0x80(%edi)\n" /* line 1909 */
        ".Lf184a5e_00184eee:\n"
        "movl %esi, 0x8c(%edi)\n" /* line 1910 */
        "jmp .Lf184a5e_00184e9d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_00184ef6:\n"
        "movl $0, -0x20(%ebp)\n" /* line 1837 | wasSet */
        ".Lf184a5e_00184efd:\n"
        "cmpl $0x31, 0x80(%edi)\n" /* line 1903 */
        "jle .Lf184a5e_00184f1d\n"
        "movl 0x18(%ebp), %ebx\n" /* force */
        "testl %ebx, %ebx\n"
        "jne .Lf184a5e_00184f1d\n"
        ".Lf184a5e_00184f0d:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1928 | wasSet */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184bbe\n"
        "jmp .Lf184a5e_00184bb9\n"
        ".Lf184a5e_00184f1d:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1905 | isContinue */
        "testl %edx, %edx\n"
        "je .Lf184a5e_00184fae\n"
        "movl 0x84(%edi), %edx\n"
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ecx\n"
        "je .Lf184a5e_00185096\n"
        ".Lf184a5e_00184f3b:\n"
        "andl $0x200, %edx\n" /* line 1907 */
        "xorb $2, %dh\n"
        "orl %edx, %ecx\n"
        "movl %ecx, 0x84(%edi)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1908 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184f59\n"
        "movl %esi, 0x80(%edi)\n" /* line 1909 */
        ".Lf184a5e_00184f59:\n"
        "movl %esi, 0x8c(%edi)\n" /* line 1910 */
        "jmp .Lf184a5e_00184f0d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_00184f61:\n"
        "movl 0x18(%ebp), %eax\n" /* line 1903 | force */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184c6b\n"
        "movl 0xc(%ebp), %edx\n" /* scriptCommand */
        "jmp .Lf184a5e_00184ae8\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_00184f74:\n"
        "movl 0x18(%ebp), %eax\n" /* line 1842 | force */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184d0a\n"
        "xorl %esi, %esi\n" /* line 1919 */
        "jmp .Lf184a5e_00184a82\n"
        ".Lf184a5e_00184f86:\n"
        "movl 0x84(%edi), %edx\n"
        "jmp .Lf184a5e_00184c89\n"
        ".Lf184a5e_00184f91:\n"
        "movl 0x18(%ebp), %eax\n" /* line 1903 | force */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184e4a\n"
        "xorl %esi, %esi\n" /* line 1919 */
        "jmp .Lf184a5e_00184a82\n"
        ".Lf184a5e_00184fa3:\n"
        "movl 0x84(%edi), %edx\n"
        "jmp .Lf184a5e_00184ed0\n"
        ".Lf184a5e_00184fae:\n"
        "movl 0x84(%edi), %edx\n"
        "jmp .Lf184a5e_00184f3b\n"
        ".Lf184a5e_00184fb6:\n"
        "movl 0x7c(%edi), %edx\n"
        "jmp .Lf184a5e_00184cd6\n"
        ".Lf184a5e_00184fbe:\n"
        "movl 0x7c(%edi), %edx\n"
        ".Lf184a5e_00184fc1:\n"
        "movl %ebx, 0x88(%edi)\n" /* line 1847 */
        "andl $0x200, %edx\n" /* line 1848 */
        "xorb $2, %dh\n"
        "orl %edx, %ecx\n"
        "movl %ecx, 0x7c(%edi)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1849 | setTimer */
        "testl %eax, %eax\n"
        "jne .Lf184a5e_00184d46\n"
        "xorl %esi, %esi\n" /* line 1919 */
        "jmp .Lf184a5e_00184a82\n"
        ".Lf184a5e_00184fe7:\n"
        "movl 0x7c(%edi), %edx\n"
        "jmp .Lf184a5e_00184d90\n"
        ".Lf184a5e_00184fef:\n"
        "movl 0x7c(%edi), %edx\n"
        "jmp .Lf184a5e_00184df7\n"
        ".Lf184a5e_00184ff7:\n"
        "movl 0x84(%edi), %edx\n" /* line 1905 */
        "movl %edx, %eax\n"
        "andb $0xfd, %ah\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf184a5e_00184e5b\n"
        "movl 0x10(%ebp), %eax\n" /* line 1917 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184b7f\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "cmpb $0, 0x50(%eax)\n"
        "jns .Lf184a5e_00184b7f\n"
        "movl %ebx, 0x80(%edi)\n" /* line 1919 */
        "xorl %esi, %esi\n"
        "jmp .Lf184a5e_00184a82\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_00185038:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1917 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184ae5\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "cmpb $0, 0x50(%eax)\n"
        "jns .Lf184a5e_00184ae5\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1919 */
        "movl %eax, 0x80(%edi)\n"
        "movl 0xc(%ebp), %edx\n" /* scriptCommand */
        "jmp .Lf184a5e_00184ae8\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_0018506a:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1917 | setTimer */
        "testl %ecx, %ecx\n"
        "je .Lf184a5e_00184e9d\n"
        "leal (%ebx, %ebx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "cmpb $0, 0x50(%eax)\n"
        "jns .Lf184a5e_00184e9d\n"
        "movl %esi, 0x80(%edi)\n" /* line 1919 */
        "jmp .Lf184a5e_00184e9d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_00185096:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1917 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184f0d\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "cmpb $0, 0x50(%eax)\n"
        "jns .Lf184a5e_00184f0d\n"
        "movl %esi, 0x80(%edi)\n" /* line 1919 */
        "jmp .Lf184a5e_00184f0d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        ".Lf184a5e_001850c2:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1857 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184c52\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "cmpb $0, 0x50(%eax)\n"
        "jns .Lf184a5e_00184c52\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1859 */
        "movl %edx, 0x78(%edi)\n"
        "jmp .Lf184a5e_00184c52\n"
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_001850ee:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1857 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184d5d\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "cmpb $0, 0x50(%eax)\n"
        "jns .Lf184a5e_00184d5d\n"
        "movl %esi, 0x78(%edi)\n" /* line 1859 */
        "movl $0, -0x20(%ebp)\n" /* wasSet */
        "jmp .Lf184a5e_00184d64\n"
        /* } scope */
        /* } scope */
        /* { scope 2: wasSet, wasSet */
        /* { scope 3 */
        ".Lf184a5e_0018511e:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1857 | setTimer */
        "testl %eax, %eax\n"
        "je .Lf184a5e_00184dc4\n"
        "leal (%ebx, %ebx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl globalScriptData, %eax\n"
        "cmpb $0, 0x50(%eax)\n"
        "jns .Lf184a5e_00184dc4\n"
        "movl %esi, 0x78(%edi)\n" /* line 1859 */
        "movl $0, -0x24(%ebp)\n" /* wasSet */
        "jmp .Lf184a5e_00184dcb\n"
    );
}

/* line 2114 */
__attribute__((naked))
int BG_AnimScriptEvent(playerState_t *ps, scriptAnimEventTypes_t event, qboolean isContinue, qboolean force)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2114 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* event */
        "cmpl $1, %edx\n" /* line 2120 */
        "je .Lf18514e_00185168\n"
        "movl 8(%ebp), %eax\n" /* ps */
        "cmpl $5, 4(%eax)\n"
        "jg .Lf18514e_00185181\n"
        ".Lf18514e_00185168:\n"
        "movl %edx, %eax\n" /* line 2123 */
        "shll $9, %eax\n"
        "leal 0x37560(%eax, %edx, 4), %eax\n"
        "addl globalScriptData, %eax\n"
        "movl 4(%eax), %ecx\n" /* line 2124 */
        "testl %ecx, %ecx\n"
        "jne .Lf18514e_0018518e\n"
        ".Lf18514e_00185181:\n"
        "movl $0xffffffff, %eax\n" /* line 2141 */
        ".Lf18514e_00185186:\n"
        "addl $0x4c, %esp\n" /* line 2142 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18514e_0018518e:\n"
        "movl 8(%ebp), %edx\n" /* line 2129 | ps */
        "movl 0xcc(%edx), %ebx\n" /* client */
        /* { scope 1: ppScriptItem, i */
        /* { scope 2: ci */
        "addl $8, %eax\n" /* line 1796 */
        "movl %eax, -0x28(%ebp)\n" /* ppScriptItem */
        "testl %ecx, %ecx\n"
        "jle .Lf18514e_00185181\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* line 1812 | cond */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ebx, %edx, 2), %edx\n" /* cond */
        "movl bgs, %eax\n"
        "leal 0xb3bfc(%eax, %edx, 8), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* ci */
        "movl $0, -0x24(%ebp)\n" /* i */
        ".Lf18514e_001851c4:\n"
        "movl -0x28(%ebp), %eax\n" /* ppScriptItem */
        "movl (%eax), %edi\n" /* scriptItem */
        /* { scope 3 */
        /* { scope 4 */
        "leal 4(%edi), %ebx\n" /* line 1678 | cond */
        "movl (%edi), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "testl %edx, %edx\n"
        "jle .Lf18514e_0018522a\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf18514e_001851ed\n"
        ".Lf18514e_001851d9:\n"
        "subl $1, %eax\n" /* line 1717 */
        "je .Lf18514e_0018526f\n"
        ".Lf18514e_001851e2:\n"
        "addl $1, %esi\n" /* line 1678 | i */
        "addl $0xc, %ebx\n" /* cond */
        "cmpl %esi, -0x1c(%ebp)\n" /* i */
        "je .Lf18514e_0018522a\n"
        ".Lf18514e_001851ed:\n"
        "movl (%ebx), %edx\n" /* line 1717 | cond */
        "movl animConditionsTable(, %edx, 8), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf18514e_001851d9\n"
        "movl -0x20(%ebp), %eax\n" /* line 1722 | ci */
        "movl 0x45c(%eax, %edx, 8), %eax\n"
        "testl %eax, 4(%ebx)\n" /* cond */
        "jne .Lf18514e_001851e2\n"
        "movl -0x20(%ebp), %eax\n" /* ci */
        "movl 0x460(%eax, %edx, 8), %edx\n"
        "testl %edx, 8(%ebx)\n" /* cond */
        "jne .Lf18514e_001851e2\n"
        /* } scope */
        /* } scope */
        ".Lf18514e_00185218:\n"
        "addl $1, -0x24(%ebp)\n" /* line 1796 | i */
        "addl $4, -0x28(%ebp)\n" /* ppScriptItem */
        "cmpl -0x24(%ebp), %ecx\n" /* i */
        "jne .Lf18514e_001851c4\n"
        "jmp .Lf18514e_00185181\n"
        /* } scope */
        /* } scope */
        ".Lf18514e_0018522a:\n"
        "movl 0x70(%edi), %eax\n" /* line 2134 | scriptItem */
        "testl %eax, %eax\n"
        "je .Lf18514e_00185181\n"
        "calll rand\n" /* line 2138 */
        "movl 0x14(%ebp), %edx\n" /* line 2141 | force */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* isContinue */
        "movl %edx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "cltd\n"
        "idivl 0x70(%edi)\n" /* scriptItem */
        "shll $4, %edx\n"
        "leal 0x74(%edx, %edi), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_ExecuteCommand\n"
        "jmp .Lf18514e_00185186\n"
        /* { scope 1: ppScriptItem, i */
        /* { scope 2: ci */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18514e_0018526f:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1733 | ci */
        "movl 0x45c(%eax, %edx, 8), %edx\n"
        "cmpl 4(%ebx), %edx\n" /* cond */
        "je .Lf18514e_001851e2\n"
        "jmp .Lf18514e_00185218\n"
    );
}

/* line 2000 */
__attribute__((naked))
int BG_AnimScriptAnimation(playerState_t *ps, aistateEnum_t state, scriptAnimMoveTypes_t movetype, qboolean isContinue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2000 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ps */
        /* { scope 1: client */
        "cmpl $5, 4(%ebx)\n" /* line 2015 | ps */
        "jle .Lf185286_001852a5\n"
        ".Lf185286_00185298:\n"
        "movl $0xffffffff, %eax\n" /* line 2066 */
        /* } scope */
        ".Lf185286_0018529d:\n"
        "addl $0x5c, %esp\n" /* line 2067 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: client */
        ".Lf185286_001852a5:\n"
        "movl 0xc(%ebp), %eax\n" /* line 2019 | state */
        "testl %eax, %eax\n"
        "js .Lf185286_00185298\n"
        "movl globalScriptData, %eax\n" /* line 2021 */
        "movl %eax, -0x38(%ebp)\n"
        /* { scope 2: ppScriptItem, i */
        /* { scope 3: ci */
        "movl bgs, %edx\n" /* line 1812 */
        "movl %edx, -0x2c(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf185286_001852bd:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2021 | movetype */
        "shll $9, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* movetype */
        "leal (%eax, %edx, 4), %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* state */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "leal 0xc000(%ecx, %eax, 4), %eax\n"
        "addl -0x38(%ebp), %eax\n"
        "movl 4(%eax), %edi\n" /* line 2022 */
        "testl %edi, %edi\n"
        "je .Lf185286_0018538d\n"
        "movl 0xcc(%ebx), %ecx\n" /* line 2028 | ps */
        "movl %ecx, -0x30(%ebp)\n" /* client */
        /* { scope 2: ppScriptItem, i */
        /* { scope 3: ci */
        "addl $8, %eax\n" /* line 1796 */
        "movl %eax, -0x28(%ebp)\n" /* ppScriptItem */
        "testl %edi, %edi\n"
        "jle .Lf185286_0018538d\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 1812 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "leal 0xb3bfc(%edx, %eax, 8), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* ci */
        "movl $0, -0x24(%ebp)\n" /* i */
        ".Lf185286_00185326:\n"
        "movl -0x28(%ebp), %ecx\n" /* ppScriptItem */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* scriptItem */
        /* { scope 4 */
        /* { scope 5 */
        "addl $4, %ecx\n" /* line 1678 */
        "movl -0x34(%ebp), %eax\n" /* scriptItem */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf185286_001853a1\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf185286_00185355\n"
        ".Lf185286_00185341:\n"
        "subl $1, %eax\n" /* line 1717 */
        "je .Lf185286_00185458\n"
        ".Lf185286_0018534a:\n"
        "addl $1, %esi\n" /* line 1678 | i */
        "addl $0xc, %ecx\n"
        "cmpl %esi, -0x1c(%ebp)\n" /* i */
        "je .Lf185286_001853a1\n"
        ".Lf185286_00185355:\n"
        "movl (%ecx), %edx\n" /* line 1717 */
        "movl animConditionsTable(, %edx, 8), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf185286_00185341\n"
        "movl -0x20(%ebp), %eax\n" /* line 1722 | ci */
        "movl 0x45c(%eax, %edx, 8), %eax\n"
        "testl %eax, 4(%ecx)\n"
        "jne .Lf185286_0018534a\n"
        "movl -0x20(%ebp), %eax\n" /* ci */
        "movl 0x460(%eax, %edx, 8), %edx\n"
        "testl %edx, 8(%ecx)\n"
        "jne .Lf185286_0018534a\n"
        /* } scope */
        /* } scope */
        ".Lf185286_00185380:\n"
        "addl $1, -0x24(%ebp)\n" /* line 1796 | i */
        "addl $4, -0x28(%ebp)\n" /* ppScriptItem */
        "cmpl -0x24(%ebp), %edi\n" /* i */
        "jne .Lf185286_00185326\n"
        /* } scope */
        /* } scope */
        ".Lf185286_0018538d:\n"
        "subl $1, 0xc(%ebp)\n" /* line 2031 | state */
        "movl 0xc(%ebp), %eax\n" /* line 2019 | state */
        "testl %eax, %eax\n"
        "jns .Lf185286_001852bd\n"
        "jmp .Lf185286_00185298\n"
        ".Lf185286_001853a1:\n"
        "movl -0x34(%ebp), %edx\n" /* line 2044 | scriptItem */
        "movl 0x70(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf185286_00185298\n"
        "movl animConditionsTable+24, %eax\n" /* line 2172 */
        "testl %eax, %eax\n"
        "jne .Lf185286_00185470\n"
        "movl -0x30(%ebp), %ecx\n" /* line 2179 | client */
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "shll $3, %edx\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl $0, 0xb4070(%edx, %eax)\n"
        "movl %edx, %eax\n" /* line 2180 */
        "addl bgs, %eax\n"
        "movl $0, 0xb4074(%eax)\n"
        "movl bgs, %eax\n" /* line 812 */
        "leal 0xb4070(%edx, %eax), %edx\n"
        "movl 0x10(%ebp), %esi\n" /* movetype */
        "sarl $5, %esi\n"
        "andl $0x1f, 0x10(%ebp)\n" /* movetype */
        "movl $1, %eax\n"
        "movzbl 0x10(%ebp), %ecx\n" /* movetype */
        "shll %cl, %eax\n"
        "orl %eax, (%edx, %esi, 4)\n"
        ".Lf185286_00185413:\n"
        "movl $0, 0x10(%esp)\n" /* line 2066 */
        "movl 0x14(%ebp), %ecx\n" /* isContinue */
        "movl %ecx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl -0x34(%ebp), %ecx\n" /* scriptItem */
        "cltd\n"
        "idivl 0x70(%ecx)\n"
        "shll $4, %edx\n"
        "leal 0x74(%edx, %ecx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_ExecuteCommand\n"
        "addl $1, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf185286_0018529d\n"
        /* { scope 2: ppScriptItem, i */
        /* { scope 3: ci */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf185286_00185458:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1733 | ci */
        "movl 0x45c(%eax, %edx, 8), %edx\n"
        "cmpl 4(%ecx), %edx\n"
        "je .Lf185286_0018534a\n"
        "jmp .Lf185286_00185380\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf185286_00185470:\n"
        "movl -0x30(%ebp), %eax\n" /* line 2187 | client */
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl -0x30(%ebp), %edx\n" /* client */
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* movetype */
        "movl -0x2c(%ebp), %ecx\n"
        "movl %edx, 0xb4070(%ecx, %eax, 8)\n"
        "jmp .Lf185286_00185413\n"
    );
}

#else
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
    byte *ci;
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
    ci = (byte *)&bgs->clientinfo[client];

    /* line 1796: ppScriptItem = scriptEvents[event].items array */
    ppScriptItem = globalScriptData->scriptEvents[event].items;

    /* Iterate over script items */
    for (i = 0; i < numItems; i++) {
        animScriptItem_t *scriptItem = ppScriptItem[i];
        int numConds = scriptItem->numConditions;
        byte *cond = (byte *)scriptItem->conditions;
        int j;
        int allMatch = 1;

        /* Check all conditions for this script item */
        for (j = 0; j < numConds; j++, cond += 12) {
            int condType = *(int *)cond;
            int testType = *(int *)((byte *)animConditionsTable + condType * 8);

            if (testType == 0) {
                /* Mask check: condition passes if either mask pair has matching bits */
                int mask1 = ((clientInfo_t *)ci)->clientConditions[condType][0];
                if (mask1 & *(int *)(cond + 4))
                    continue; /* condition matched */
                {
                    int mask2 = ((clientInfo_t *)ci)->clientConditions[condType][1];
                    if (mask2 & *(int *)(cond + 8))
                        continue; /* condition matched */
                }
                /* Neither mask matched — condition failed */
                allMatch = 0;
                break;
            } else if (testType == 1) {
                /* Exact match: condition passes if values are equal */
                int val = ((clientInfo_t *)ci)->clientConditions[condType][0];
                if (val == *(int *)(cond + 4))
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
#endif
