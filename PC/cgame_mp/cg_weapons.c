/* ASM dump from: cg_weapons.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_weapons.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern vec3_t ejectBrassCasingOrigin; /* 0x0 */
extern int removeMeWhenMPStopsCrashingInHere; /* 0x0 */
extern void *BG_GetWeaponDef(int weapIndex);
extern void CG_SetWeaponDefToDefaultWeapon(int weaponNum);
extern void SCR_UpdateScreen(void);
extern struct XAnim_s *XAnimCreateAnims(const char *debugName, int size, void *Alloc);
extern void XAnimBlend(struct XAnim_s *anims, unsigned int animIndex, const char *name, unsigned int children, unsigned int num, unsigned int flags);
extern void XAnimPrecache(const char *name, void *Alloc);
extern void XAnimCreate(struct XAnim_s *anims, unsigned int animIndex, const char *name);
extern void *XAnimCreateTree(void *anims, void *Alloc);
extern void XAnimClearTreeGoalWeights(void *tree, int animIndex, int recursive);
extern int XAnimSetGoalWeight(void *tree, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart);
extern void XAnimSetTime(void *tree, int animIndex, float time);
extern int XAnimIsLooped(struct XAnim_s *anims, int animIndex);
extern int XAnimGetLengthMsec(struct XAnim_s *anims, int animIndex);
extern int XModelBad(void *model);
extern void *Com_GetClientDObj(int entityNum, int localClientNum);
extern void DObjUpdateClientInfo(struct DObj_s *obj, float timescale);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern int CL_RegisterMaterial(const char *name, int flags);
extern int CL_RegisterMaterialNoMip(const char *name, int flags);
extern struct XModel *CL_RegisterModel(const char *name);
extern int FX_RegisterEffect(const char *name);
extern void *Com_FindSoundAlias(const char *name);
extern const char *SEH_StringEd_GetString(const char *str);
extern int Com_ClientDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void CL_RegisterHudMsgIconMaterial(const char *name);
static const int iSlotPreferenceOrder[2]; /* iSlotPreferenceOrder */
extern weapSlot_t (*s_barrelTags[4])[64]; /* s_barrelTags */

static void CG_PlayADSAnim(void);
int CG_WeaponDObjHandle(int weaponNum);
void CG_Weapons_SetToDefault(int weaponNum, weaponInfo_s (*dobjModels)[4]);
void CG_HoldBreathInit(void);
void CG_SetupWeaponDef(void);
void CG_SelectWeaponIndex(int weaponIndex);
static qboolean CG_CalcMuzzlePoint(unsigned int flashTag);
void CG_EjectWeaponBrass(entityState_t *ent, int event);
void CG_FireWeapon(centity_t *cent, int event, int barrel);
void CG_RegisterWeapon(int weaponNum);
void CG_RegisterItemVisuals(int itemNum);
void CG_RegisterItems(void);
void CG_UpdateHandViewmodels(const char *handModel);
void CG_SpawnTracer(vec_t *pstart, vec_t *pend);
void CG_WhizbySound(vec_t *vStart, vec_t *vEnd);
void CG_BulletHitClientEvent(int sourceEntityNum, vec_t *position, int surfType, int event);
void CG_AddPlayerWeapon(GfxEntity *parent, weapProjExposion_t (*ps)[8], centity_t *cent, qboolean bDrawGun);
void CG_AddViewWeapon(weapProjExposion_t (*ps)[8]);
void CG_BulletHitEvent(int sourceEntityNum, vec_t *position, vec_t *normal, vec_t *reflected, int surfType, int event);
void CG_DrawTracer(vec_t *start, vec_t *finish);
void CG_WeaponSlot_f(qboolean next, qboolean ignoreEmpty);
qboolean CG_SelectFirstWeaponNotInSlot(qboolean bNext, qboolean bIgnoreEmpty);
void CG_CycleWeap(qboolean bNext, qboolean bIgnoreEmpty);
void CG_OutOfAmmoChange(void);
void CG_PrevWeapon_f(void);
void CG_NextWeapon_f(void);
void CG_WeaponRunXModelAnims(weapProjExposion_t (*ps)[8], weaponInfo_t *weapInfo);
void CG_UpdateViewWeaponAnim(weapProjExposion_t (*ps)[8]);

/* line 63 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void CG_PlayADSAnim(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 63 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %edx, %edi\n" /* pAnimTree */
        "cmpl $0x15, %ecx\n" /* line 67 | animIndex */
        "je .Lf1d54ec_001d55c2\n"
        "movl $0, 0x1c(%esp)\n" /* line 74 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl $0x3f000000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x15, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl $0, 0x1c(%esp)\n" /* line 75 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x16, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pAnimTree */
        "calll XAnimSetGoalWeight\n"
        ".Lf1d54ec_001d5573:\n"
        "movl imp_cg, %eax\n" /* line 78 | weaponNum */
        "movl (%eax), %ebx\n" /* weaponNum */
        "movl 0x25ca0(%ebx), %eax\n" /* weaponNum */
        "movl %eax, 8(%esp)\n" /* weaponNum */
        "movl $0x15, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pAnimTree */
        "calll XAnimSetTime\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 79 | 1.0f */
        "subss 0x25ca0(%ebx), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl $0x16, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pAnimTree */
        "calll XAnimSetTime\n"
        "addl $0x2c, %esp\n" /* line 80 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d54ec_001d55c2:\n"
        "movl $0, 0x1c(%esp)\n" /* line 69 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl $0x3f000000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x15, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl $0, 0x1c(%esp)\n" /* line 70 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x16, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pAnimTree */
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d54ec_001d5573\n"
    );
}
#else
/* Register-convention: edx=pAnimTree, ecx=animIndex.
   In Emscripten, callers use _impl directly. */
static void CG_PlayADSAnim_impl(void *pAnimTree, int animIndex)
{
    cg_t *cgp;
    float adsProgress;

    if (animIndex == 0x15) {
        /* ADS in: set 0x15 to weight 1.0 with notify; clear 0x16 */
        XAnimSetGoalWeight(pAnimTree, 0x15, 1.0f, 0.5f, 0.0f, 0, 1, 0);
        XAnimSetGoalWeight(pAnimTree, 0x16, 0.0f, 0.5f, 0.0f, 0, 0, 0);
    } else {
        /* ADS out: clear 0x15; set 0x16 to weight 1.0 with notify */
        XAnimSetGoalWeight(pAnimTree, 0x15, 0.0f, 0.5f, 0.0f, 0, 0, 0);
        XAnimSetGoalWeight(pAnimTree, 0x16, 1.0f, 0.5f, 0.0f, 0, 1, 0);
    }

    /* Set anim times based on ADS progress */
    cgp = *(cg_t **)imp_cg;
    adsProgress = cgp->predictedPlayerState.fWeaponPosFrac;
    XAnimSetTime(pAnimTree, 0x15, adsProgress);
    XAnimSetTime(pAnimTree, 0x16, 1.0f - adsProgress);
}
#endif

/* line 311 */
int CG_WeaponDObjHandle(int weaponNum)
{
    return weaponNum + 0x400;
}

/* line 363 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void CG_Weapons_SetToDefault(int weaponNum, weaponInfo_s (*dobjModels)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 363 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* weaponNum */
        "movl 0xc(%ebp), %edi\n" /* dobjModels */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 371 | weaponNum */
        "calll CG_SetWeaponDefToDefaultWeapon\n"
        "movl %ebx, (%esp)\n" /* line 372 | weaponNum */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %esi\n" /* weapDef */
        "movl 4(%eax), %eax\n" /* line 374 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b7a74, (%esp)\n" /* "WARNING: gun and/or hand model file for weapon [%s] could no" */
        "calll Com_Printf\n"
        "movl 0xc(%esi), %eax\n" /* line 377 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1d5648_001d5688\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5648_001d56fa\n"
        ".Lf1d5648_001d5688:\n"
        "movl $str_002b7adc, 4(%esp)\n" /* line 378 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x10(%esi), %eax\n" /* weapDef */
        ".Lf1d5648_001d569f:\n"
        "movl %eax, 0xc(%esp)\n" /* line 381 */
        "movl $str_002b7b28, 8(%esp)\n" /* "xmodel/" */
        "movl $str_00215f50, 4(%esp)\n" /* "%s%s" */
        "leal -0x58(%ebp), %ebx\n" /* modelFile, weaponNum */
        "movl %ebx, (%esp)\n" /* weaponNum */
        "calll sprintf\n"
        "movl %ebx, (%esp)\n" /* line 382 | weaponNum */
        "calll CL_RegisterModel\n"
        "movl %eax, (%edi)\n" /* dobjModels */
        "movl 0xc(%esi), %eax\n" /* line 385 | weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b7b28, 8(%esp)\n" /* "xmodel/" */
        "movl $str_00215f50, 4(%esp)\n" /* "%s%s" */
        "movl %ebx, (%esp)\n" /* weaponNum */
        "calll sprintf\n"
        "movl %ebx, (%esp)\n" /* line 386 | weaponNum */
        "calll CL_RegisterModel\n"
        "movl %eax, 0xc(%edi)\n" /* dobjModels */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 387 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d5648_001d56fa:\n"
        "movl 0x10(%esi), %eax\n" /* line 377 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1d5648_001d5688\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1d5648_001d5688\n"
        "jmp .Lf1d5648_001d569f\n"
    );
}

/* line 1246 */
void CG_HoldBreathInit(void)
{
    cg_t *cgp = *(cg_t **)imp_cg;
    cgp->holdBreathTime = -1;
    cgp->holdBreathInTime = 0;
    cgp->holdBreathDelay = 0;
    cgp->holdBreathFrac = 0.0f;
}

/* line 2631 */
__attribute__((naked))
void CG_SetupWeaponDef(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2631 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x221c, %esp\n"
        /* { scope 1 */
        "leal -0x214(%ebp), %eax\n" /* line 2639 | pszFiles */
        "movl $0x1fc, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $7, (%esp)\n" /* line 2643 */
        "calll CL_GetConfigString\n"
        "movl %eax, 4(%esp)\n" /* line 2644 */
        "leal -0x2214(%ebp), %ebx\n" /* szString, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll strcpy\n"
        "movl %ebx, -0x214(%ebp)\n" /* line 2647 | i, pszFiles */
        "movl $1, %edi\n" /* iNumFiles */
        "movl %ebx, %edx\n" /* i */
        "movzbl -0x2214(%ebp), %eax\n" /* szString */
        ".Lf1d573c_001d5798:\n"
        "testb %al, %al\n" /* line 2650 */
        "jne .Lf1d573c_001d57f2\n"
        /* { scope 2 */
        ".Lf1d573c_001d579c:\n"
        "testl %edi, %edi\n" /* line 2614 */
        "jg .Lf1d573c_001d57ab\n"
        /* } scope */
        /* } scope */
        "addl $0x221c, %esp\n" /* line 2670 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d573c_001d57ab:\n"
        "xorl %ebx, %ebx\n" /* line 2650 | i */
        /* { scope 2 */
        ".Lf1d573c_001d57ad:\n"
        "movl -0x214(%ebp, %ebx, 4), %esi\n" /* line 2616 | name */
        "movl $0, 4(%esp)\n" /* line 2617 */
        "movl %esi, (%esp)\n" /* name */
        "calll BG_GetWeaponIndexForName\n"
        "addl $1, %ebx\n" /* i */
        "cmpl %ebx, %eax\n" /* i */
        "je .Lf1d573c_001d57e3\n"
        "movl %esi, 8(%esp)\n" /* line 2619 | name */
        "movl $str_002b7b30, 4(%esp)\n" /* "Weapon index mismatch for '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1d573c_001d57e3:\n"
        "cmpl %edi, %ebx\n" /* line 2614 | i */
        "jne .Lf1d573c_001d57ad\n"
        /* } scope */
        /* } scope */
        "addl $0x221c, %esp\n" /* line 2670 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d573c_001d57f2:\n"
        "cmpb $0x20, %al\n" /* line 2652 */
        "je .Lf1d573c_001d57fe\n"
        "addl $1, %edx\n" /* line 2665 */
        "movzbl (%edx), %eax\n"
        "jmp .Lf1d573c_001d5798\n"
        ".Lf1d573c_001d57fe:\n"
        "movb $0, (%edx)\n" /* line 2654 */
        "addl $1, %edx\n" /* line 2655 */
        "movzbl (%edx), %eax\n" /* line 2657 */
        "testb %al, %al\n"
        "je .Lf1d573c_001d579c\n"
        "cmpb $0x20, %al\n"
        "je .Lf1d573c_001d5798\n"
        "movl %edx, -0x214(%ebp, %edi, 4)\n" /* line 2659 */
        "addl $1, %edi\n" /* line 2660 | iNumFiles */
        "movzbl (%edx), %eax\n"
        "jmp .Lf1d573c_001d5798\n"
    );
}

/* line 2678 */
__attribute__((naked))
void CG_SelectWeaponIndex(int weaponIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2678 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* weaponIndex */
        "movl imp_cg, %edi\n" /* line 2682 */
        "movl (%edi), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "movl %edx, 0x2be54(%eax)\n"
        "movl 0x2be50(%eax), %eax\n" /* line 2684 */
        "cmpl %ebx, %eax\n" /* weaponIndex */
        "je .Lf1d5822_001d586c\n"
        "testl %ebx, %ebx\n" /* line 2687 | weaponIndex */
        "jne .Lf1d5822_001d5887\n"
        ".Lf1d5822_001d5850:\n"
        "xorl %esi, %esi\n"
        ".Lf1d5822_001d5852:\n"
        "movl (%edi), %eax\n" /* line 2689 */
        "movl %ebx, 0x2be50(%eax)\n" /* weaponIndex */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "movl %esi, %eax\n" /* line 2692 */
        "testb %al, %al\n"
        "je .Lf1d5822_001d5874\n"
        ".Lf1d5822_001d586c:\n"
        "addl $0x1c, %esp\n" /* line 2694 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d5822_001d5874:\n"
        "movl $0, 8(%ebp)\n" /* line 2693 | weaponIndex */
        "addl $0x1c, %esp\n" /* line 2694 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CL_SetADS\n" /* line 2693 */
        ".Lf1d5822_001d5887:\n"
        "movl %eax, (%esp)\n" /* line 2687 */
        "calll BG_GetWeaponDef\n"
        "cmpl 0x36c(%eax), %ebx\n" /* weaponIndex */
        "jne .Lf1d5822_001d5850\n"
        "movl $1, %esi\n"
        "jmp .Lf1d5822_001d5852\n"
    );
}

/* line 2452 */
static __attribute__((naked))
qboolean CG_CalcMuzzlePoint(unsigned int flashTag)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2452 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %esi\n" /* entityNum */
        "movl %edx, %edi\n" /* muzzle */
        "movl %ecx, -0x1c(%ebp)\n"
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 2457 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1d589e_001d58c9\n"
        "cmpl 0xd8(%edx), %esi\n" /* entityNum */
        "je .Lf1d589e_001d5941\n"
        ".Lf1d589e_001d58c9:\n"
        "movl %esi, %eax\n" /* line 2463 | entityNum */
        "shll $4, %eax\n"
        "addl %esi, %eax\n" /* entityNum */
        "leal (%esi, %eax, 8), %eax\n" /* entityNum */
        "movl imp_cg_entities, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* cent */
        "movl 0x220(%ebx), %eax\n" /* line 2465 | cent */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%ebx), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "testl %eax, %eax\n" /* line 2466 */
        "je .Lf1d589e_001d5939\n"
        "movl %edi, 0xc(%esp)\n" /* line 2468 | muzzle */
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cent */
        "calll CG_DObjGetWorldTagPos\n"
        "testl %eax, %eax\n"
        "jne .Lf1d589e_001d5934\n"
        "leal 0x108(%ebx), %edx\n" /* cent */
        /* { scope 2 */
        "movl 0x108(%ebx), %eax\n" /* line 199 */
        "movl %eax, (%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%edi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%edi)\n"
        /* } scope */
        "cmpl $0x3f, %esi\n" /* line 2472 | entityNum */
        "jle .Lf1d589e_001d5968\n"
        ".Lf1d589e_001d5934:\n"
        "movl $1, %eax\n" /* line 2480 */
        /* } scope */
        ".Lf1d589e_001d5939:\n"
        "addl $0x2c, %esp\n" /* line 2484 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d589e_001d5941:\n"
        "leal 0x28588(%eax), %edx\n" /* line 2457 */
        /* { scope 2 */
        "movl 0x28588(%eax), %eax\n" /* line 199 */
        "movl %eax, (%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%edi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2484 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d589e_001d5968:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2474 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %esi, 8(%esp)\n" /* entityNum */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b7b50, (%esp)\n" /* "No %s in CG_CalcMuzzlePoint on entity %d.
" */
        "calll Com_DPrintf\n"
        "movl 0xf8(%ebx), %eax\n" /* line 2475 | cent */
        "testb $8, %al\n"
        "je .Lf1d589e_001d59aa\n"
        "movss lit4_002ed7bc, %xmm0\n" /* line 2476 | 11.0f */
        "addss 8(%edi), %xmm0\n" /* muzzle */
        "movss %xmm0, 8(%edi)\n" /* muzzle */
        "movl $1, %eax\n"
        "jmp .Lf1d589e_001d5939\n"
        ".Lf1d589e_001d59aa:\n"
        "testb $4, %al\n" /* line 2477 */
        "jne .Lf1d589e_001d59ca\n"
        "movss lit4_002ed7c8, %xmm0\n" /* line 2480 | 60.0f */
        "addss 8(%edi), %xmm0\n" /* muzzle */
        "movss %xmm0, 8(%edi)\n" /* muzzle */
        "movl $1, %eax\n"
        "jmp .Lf1d589e_001d5939\n"
        ".Lf1d589e_001d59ca:\n"
        "movss lit4_002ed73c, %xmm0\n" /* line 2478 | 40.0f */
        "addss 8(%edi), %xmm0\n" /* muzzle */
        "movss %xmm0, 8(%edi)\n" /* muzzle */
        "movl $1, %eax\n"
        "jmp .Lf1d589e_001d5939\n"
    );
}

/* line 2108 */
__attribute__((naked))
void CG_EjectWeaponBrass(entityState_t *ent, int event)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2108 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "movl imp_cg_brass, %eax\n" /* line 2110 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1d59e6_001d5ac8\n"
        "cmpl $9, 4(%esi)\n" /* ent */
        "jg .Lf1d59e6_001d5ac8\n"
        /* { scope 1: bolt */
        "movl 0xc8(%esi), %ebx\n" /* line 2114 | ent, weapInfo */
        "testl %ebx, %ebx\n" /* weapInfo */
        "je .Lf1d59e6_001d5ac8\n"
        "calll BG_GetNumWeapons\n" /* line 2117 */
        "cmpl %eax, %ebx\n" /* weapInfo */
        "jg .Lf1d59e6_001d5acf\n"
        "movl 0xc8(%esi), %ecx\n" /* line 2122 | ent */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* weapInfo */
        "movl 0x160(%ebx), %edx\n" /* line 2124 | weapInfo */
        "testl %edx, %edx\n"
        "je .Lf1d59e6_001d5a58\n"
        "cmpl $0xa0, 0xc(%ebp)\n" /* event */
        "je .Lf1d59e6_001d5af1\n"
        ".Lf1d59e6_001d5a58:\n"
        "movl 0x15c(%ebx), %eax\n" /* line 2133 | weapInfo */
        "testl %eax, %eax\n"
        "je .Lf1d59e6_001d5ac8\n"
        /* { scope 2 */
        "movl imp_cg, %eax\n" /* line 2137 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1d59e6_001d5ae5\n"
        "movl (%esi), %eax\n" /* ent */
        "cmpl 0xd8(%edx), %eax\n"
        "je .Lf1d59e6_001d5ae9\n"
        ".Lf1d59e6_001d5a7f:\n"
        "movl %eax, %edx\n"
        ".Lf1d59e6_001d5a81:\n"
        "movl %edx, -0x10(%ebp)\n" /* bolt */
        "movl imp_scr_const, %eax\n" /* line 2138 */
        "movzwl 0x94(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FX_GetBoneIndex\n"
        "movl %eax, -0xc(%ebp)\n"
        "testl %eax, %eax\n" /* line 2139 */
        "js .Lf1d59e6_001d5ac8\n"
        "leal -0x10(%ebp), %eax\n" /* line 2140 | bolt */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $ejectBrassCasingOrigin, 4(%esp)\n"
        "movl 0x15c(%ebx), %eax\n" /* weapInfo */
        "movl %eax, (%esp)\n"
        "calll FX_PlayEntityEffect\n"
        /* } scope */
        /* } scope */
        ".Lf1d59e6_001d5ac8:\n"
        "addl $0x20, %esp\n" /* line 2143 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bolt */
        ".Lf1d59e6_001d5acf:\n"
        "movl $str_002b7b7c, 4(%esp)\n" /* line 2119 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d59e6_001d5ac8\n"
        ".Lf1d59e6_001d5ae5:\n"
        "movl (%esi), %eax\n" /* ent */
        "jmp .Lf1d59e6_001d5a7f\n"
        /* { scope 2 */
        ".Lf1d59e6_001d5ae9:\n"
        "leal 0x400(%ecx), %edx\n" /* line 313 */
        "jmp .Lf1d59e6_001d5a81\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d59e6_001d5af1:\n"
        "movl imp_cg, %eax\n" /* line 2128 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1d59e6_001d5b64\n"
        "movl (%esi), %eax\n" /* ent */
        "cmpl 0xd8(%edx), %eax\n"
        "je .Lf1d59e6_001d5b5c\n"
        ".Lf1d59e6_001d5b0e:\n"
        "movl %eax, %edx\n"
        ".Lf1d59e6_001d5b10:\n"
        "movl %edx, -0x10(%ebp)\n" /* bolt */
        "movl imp_scr_const, %eax\n" /* line 2129 */
        "movzwl 0x94(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FX_GetBoneIndex\n"
        "movl %eax, -0xc(%ebp)\n"
        "testl %eax, %eax\n" /* line 2130 */
        "js .Lf1d59e6_001d5ac8\n"
        "leal -0x10(%ebp), %eax\n" /* line 2131 | bolt */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $ejectBrassCasingOrigin, 4(%esp)\n"
        "movl 0x160(%ebx), %eax\n" /* weapInfo */
        "movl %eax, (%esp)\n"
        "calll FX_PlayEntityEffect\n"
        "jmp .Lf1d59e6_001d5ac8\n"
        ".Lf1d59e6_001d5b5c:\n"
        "leal 0x400(%ecx), %edx\n" /* line 313 */
        "jmp .Lf1d59e6_001d5b10\n"
        ".Lf1d59e6_001d5b64:\n"
        "movl (%esi), %eax\n"
        "jmp .Lf1d59e6_001d5b0e\n"
    );
}

/* line 2154 */
__attribute__((naked))
void CG_FireWeapon(centity_t *cent, int event, int barrel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2154 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* cent */
        /* { scope 1: flashTag, origin */
        "leal 0xf0(%edi), %esi\n" /* line 2170 | cent, ent */
        "movl 0xc8(%esi), %ebx\n" /* line 2172 | ent, firesound */
        "testl %ebx, %ebx\n" /* firesound */
        "jne .Lf1d5b68_001d5b8c\n"
        /* } scope */
        ".Lf1d5b68_001d5b84:\n"
        "addl $0x4c, %esp\n" /* line 2258 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: flashTag, origin */
        ".Lf1d5b68_001d5b8c:\n"
        "calll BG_GetNumWeapons\n" /* line 2175 */
        "cmpl %eax, %ebx\n" /* firesound */
        "jle .Lf1d5b68_001d5bb1\n"
        "movl $str_002b7bb4, 4(%esp)\n" /* line 2177 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2258 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: flashTag, origin */
        ".Lf1d5b68_001d5bb1:\n"
        "movl 0xc8(%esi), %ecx\n" /* line 2180 | ent */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* weapInfo */
        "movl %ecx, (%esp)\n" /* line 2182 */
        "calll BG_GetWeaponDef\n"
        "movb $1, 0x1e2(%edi)\n" /* line 2187 | cent */
        "movl imp_cg, %eax\n" /* line 2190 */
        "movl (%eax), %ecx\n"
        "movl 0x24(%ecx), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "jne .Lf1d5b68_001d5d09\n"
        ".Lf1d5b68_001d5bf4:\n"
        "cmpl $9, 4(%esi)\n" /* line 2196 | ent */
        "je .Lf1d5b68_001d5d83\n"
        ".Lf1d5b68_001d5bfe:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 2207 | weapInfo */
        "movl 0xdc(%ecx), %ebx\n" /* weaponNum */
        "movl 0xe0(%ecx), %edx\n" /* line 2208 */
        "testl %edx, %edx\n"
        "je .Lf1d5b68_001d5c2f\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl $0xc00000, 0x18(%eax)\n"
        "je .Lf1d5b68_001d5c2f\n"
        "movl (%esi), %ecx\n" /* ent */
        "cmpl 0xd8(%eax), %ecx\n"
        "cmovel %edx, %ebx\n" /* weaponNum */
        ".Lf1d5b68_001d5c2f:\n"
        "cmpl $0xa0, 0xc(%ebp)\n" /* line 2210 | event */
        "je .Lf1d5b68_001d5d42\n"
        ".Lf1d5b68_001d5c3c:\n"
        "testl %ebx, %ebx\n" /* line 2218 | weaponNum */
        "je .Lf1d5b68_001d5cd6\n"
        "movl %ebx, -0x3c(%ebp)\n" /* weaponNum */
        ".Lf1d5b68_001d5c47:\n"
        "movl imp_cg, %edx\n" /* line 2220 */
        "movl (%edx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl $0xc00000, 0x18(%eax)\n"
        "je .Lf1d5b68_001d5e66\n"
        "movl (%esi), %ecx\n" /* ent */
        ".Lf1d5b68_001d5c61:\n"
        "cmpl 0xd8(%eax), %ecx\n"
        "je .Lf1d5b68_001d5e9c\n"
        ".Lf1d5b68_001d5c6d:\n"
        "movl 0x220(%edi), %eax\n" /* line 2228 | cent */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2229 */
        "je .Lf1d5b68_001d5e3e\n"
        "leal -0x2c(%ebp), %ebx\n" /* origin, weaponNum */
        "movl %ebx, 0xc(%esp)\n" /* weaponNum */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x8c(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cent */
        "calll CG_DObjGetWorldTagPos\n"
        "testl %eax, %eax\n"
        "je .Lf1d5b68_001d5e41\n"
        ".Lf1d5b68_001d5cb4:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 2233 */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* weaponNum */
        "movl (%esi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "cmpl $1, 0xf4(%edi)\n" /* line 2235 | cent */
        "je .Lf1d5b68_001d5edd\n"
        ".Lf1d5b68_001d5cd6:\n"
        "movl 0xc8(%esi), %eax\n" /* line 2239 | ent */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x328(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1d5b68_001d5b84\n"
        "movl 0xc(%ebp), %eax\n" /* line 2240 | event */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll CG_EjectWeaponBrass\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2258 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: flashTag, origin */
        ".Lf1d5b68_001d5d09:\n"
        "movl 0xf0(%edi), %eax\n" /* line 2190 | cent */
        "cmpl 0xd8(%edx), %eax\n"
        "jne .Lf1d5b68_001d5bf4\n"
        "leal 0x2c030(%ecx), %eax\n" /* line 2192 */
        "movl %eax, 8(%esp)\n"
        "leal 0x2c0b0(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_WeaponFireRecoil\n"
        "jmp .Lf1d5b68_001d5bf4\n"
        ".Lf1d5b68_001d5d42:\n"
        "movl -0x48(%ebp), %eax\n" /* line 2212 | weapInfo */
        "movl 0xe8(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf1d5b68_001d5d6a\n"
        "movl imp_cg, %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl $0xc00000, 0x18(%eax)\n"
        "jne .Lf1d5b68_001d5e89\n"
        ".Lf1d5b68_001d5d6a:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 2214 | weapInfo */
        "movl 0xe4(%ecx), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1d5b68_001d5c47\n"
        "jmp .Lf1d5b68_001d5c3c\n"
        ".Lf1d5b68_001d5d83:\n"
        "movl imp_cg, %eax\n" /* line 2196 */
        "movl (%eax), %eax\n"
        "movl 0x25bc0(%eax), %ebx\n" /* firesound */
        "testl %ebx, %ebx\n" /* firesound */
        "jne .Lf1d5b68_001d5db4\n"
        "movl 0x24(%eax), %eax\n" /* line 2198 */
        "testl $0x300, 0xac(%eax)\n"
        "je .Lf1d5b68_001d5db4\n"
        "movl 0x5a0(%eax), %eax\n"
        "cmpl (%esi), %eax\n" /* ent */
        "jne .Lf1d5b68_001d5db4\n"
        "movl $1, %edx\n" /* line 2240 */
        "jmp .Lf1d5b68_001d5db6\n"
        ".Lf1d5b68_001d5db4:\n"
        "xorl %edx, %edx\n"
        ".Lf1d5b68_001d5db6:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2204 | barrel */
        "movl s_barrelTags(, %ecx, 4), %eax\n"
        "movzwl (%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* flashTag */
        "leal 0x1ec(%edi), %eax\n" /* cent */
        "movl %eax, -0x40(%ebp)\n" /* origin */
        "movl 0xc8(%esi), %ebx\n" /* ent, weaponNum */
        "movl (%esi), %ecx\n" /* ent */
        /* { scope 2: bolt */
        /* { scope 3 */
        "testl %edx, %edx\n" /* line 1230 */
        "jne .Lf1d5b68_001d5e6d\n"
        "movl imp_cg_weapons, %eax\n"
        "movl (%eax), %edx\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* fx */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* fx */
        "movl 0xc4(%edx, %eax, 4), %ebx\n" /* fx */
        ".Lf1d5b68_001d5df6:\n"
        "testl %ebx, %ebx\n" /* line 1231 | fx */
        "je .Lf1d5b68_001d5bfe\n"
        "movl %ecx, -0x20(%ebp)\n" /* line 1234 | bolt */
        "movl -0x44(%ebp), %eax\n" /* line 1235 | flashTag */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll FX_GetBoneIndex\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n" /* line 1236 */
        "js .Lf1d5b68_001d5bfe\n"
        "leal -0x20(%ebp), %eax\n" /* line 1239 | bolt */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* origin */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* fx */
        "calll FX_PlayEntityEffect\n"
        "jmp .Lf1d5b68_001d5bfe\n"
        ".Lf1d5b68_001d5e3e:\n"
        "leal -0x2c(%ebp), %ebx\n" /* origin, fx */
        /* } scope */
        /* } scope */
        ".Lf1d5b68_001d5e41:\n"
        "movl %ebx, 8(%esp)\n" /* line 2230 | weaponNum */
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        ".Lf1d5b68_001d5e4c:\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "jmp .Lf1d5b68_001d5cb4\n"
        ".Lf1d5b68_001d5e66:\n"
        "movl (%esi), %ecx\n" /* ent */
        "jmp .Lf1d5b68_001d5c6d\n"
        /* { scope 2: bolt */
        /* { scope 3 */
        ".Lf1d5b68_001d5e6d:\n"
        "movl imp_cg_weapons, %eax\n" /* line 1230 */
        "movl (%eax), %edx\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* fx */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* fx */
        "movl 0xc0(%edx, %eax, 4), %ebx\n" /* fx */
        "jmp .Lf1d5b68_001d5df6\n"
        /* } scope */
        /* } scope */
        ".Lf1d5b68_001d5e89:\n"
        "movl (%esi), %ecx\n" /* line 2212 | ent */
        "cmpl 0xd8(%eax), %ecx\n"
        "jne .Lf1d5b68_001d5d6a\n"
        "jmp .Lf1d5b68_001d5c61\n"
        ".Lf1d5b68_001d5e9c:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 2222 | weapInfo */
        "movl (%ecx), %edx\n"
        "testl %edx, %edx\n" /* line 2223 */
        "je .Lf1d5b68_001d5ef2\n"
        "leal -0x2c(%ebp), %ebx\n" /* origin, weaponNum */
        "movl %ebx, 8(%esp)\n" /* weaponNum */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x8c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_DObjGetViewModelTagPos\n"
        "testl %eax, %eax\n"
        "jne .Lf1d5b68_001d5cb4\n"
        ".Lf1d5b68_001d5ecc:\n"
        "movl %ebx, 8(%esp)\n" /* line 2224 | weaponNum */
        "movl imp_cg, %edx\n"
        "movl (%edx), %eax\n"
        "jmp .Lf1d5b68_001d5e4c\n"
        ".Lf1d5b68_001d5edd:\n"
        "movl %eax, 8(%esp)\n" /* line 2236 */
        "movl %ebx, 4(%esp)\n" /* weaponNum */
        "movl %edi, (%esp)\n" /* cent */
        "calll CG_CompassAddWeaponPingInfo\n"
        "jmp .Lf1d5b68_001d5cd6\n"
        ".Lf1d5b68_001d5ef2:\n"
        "leal -0x2c(%ebp), %ebx\n" /* origin, weaponNum */
        "jmp .Lf1d5b68_001d5ecc\n"
    );
}

/* line 396 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void CG_RegisterWeapon(int weaponNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 396 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 411 | weaponNum */
        "movl %eax, removeMeWhenMPStopsCrashingInHere\n"
        "testl %eax, %eax\n" /* line 414 */
        "jne .Lf1d5ef8_001d5f1b\n"
        /* } scope */
        ".Lf1d5ef8_001d5f10:\n"
        "addl $0x9c, %esp\n" /* line 750 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d5ef8_001d5f1b:\n"
        "movl %eax, %ecx\n"
        /* { scope 1 */
        "leal (%eax, %eax, 2), %eax\n" /* line 424 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x88(%ebp)\n" /* weapInfo */
        "movl %ecx, (%esp)\n" /* line 425 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edi\n" /* weapDef */
        "movl -0x88(%ebp), %eax\n" /* line 427 | weapInfo */
        "movl 0xa8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1d5ef8_001d5f10\n"
        "calll SCR_UpdateScreen\n" /* line 430 */
        "movl $0x1b4, 8(%esp)\n" /* line 432 */
        "movl $0, 4(%esp)\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl -0x88(%ebp), %ecx\n" /* line 433 | weapInfo */
        "movl $1, 0xa8(%ecx)\n"
        "movl 8(%ebp), %edx\n" /* line 436 | weaponNum */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl imp_bg_itemlist, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 0xac(%ecx)\n"
        "movl 8(%ebp), %ecx\n" /* line 438 | weaponNum */
        "leal (%ecx, %ecx, 8), %edx\n"
        "movl imp_cg_items, %eax\n"
        "movl (%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* itemInfo */
        "movl %ecx, (%esp)\n" /* line 440 */
        "calll CG_RegisterItemVisuals\n"
        "movl -0x88(%ebp), %eax\n" /* line 442 | weapInfo */
        "movl $0xffffffff, 0xa0(%eax)\n"
        "movl 0xc(%edi), %eax\n" /* line 444 | weapDef */
        "cmpb $0, (%eax)\n"
        "je .Lf1d5ef8_001d659e\n"
        "movl 0x10(%edi), %eax\n" /* line 447 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1d5ef8_001d6b30\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1d5ef8_001d6b30\n"
        ".Lf1d5ef8_001d5fea:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 450 */
        "movl $0, -0x28(%ebp)\n" /* line 451 */
        "movl $str_002b6e38, -0x20(%ebp)\n" /* line 452 */
        "movl $0, -0x1c(%ebp)\n" /* line 453 */
        "movl 0x10(%edi), %eax\n" /* line 456 | weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b7b28, 8(%esp)\n" /* "xmodel/" */
        "movl $str_00215f50, 4(%esp)\n" /* "%s%s" */
        "leal -0x70(%ebp), %ebx\n" /* szModelFile, dobjHandle */
        "movl %ebx, (%esp)\n" /* dobjHandle */
        "calll sprintf\n"
        "movl %ebx, (%esp)\n" /* line 457 | dobjHandle */
        "calll CL_RegisterModel\n"
        "movl %eax, -0x30(%ebp)\n" /* dobjModels */
        "movl 0xc(%edi), %eax\n" /* line 460 | weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b7b28, 8(%esp)\n" /* "xmodel/" */
        "movl $str_00215f50, 4(%esp)\n" /* "%s%s" */
        "movl %ebx, (%esp)\n" /* dobjHandle */
        "calll sprintf\n"
        "movl %ebx, (%esp)\n" /* line 461 | dobjHandle */
        "calll CL_RegisterModel\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 463 | dobjModels */
        "movl %eax, (%esp)\n"
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "jne .Lf1d5ef8_001d6b70\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "jne .Lf1d5ef8_001d6b70\n"
        ".Lf1d5ef8_001d6083:\n"
        "movl 0x18(%edi), %eax\n" /* line 467 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1d5ef8_001d6b50\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1d5ef8_001d6b50\n"
        ".Lf1d5ef8_001d6097:\n"
        "movl imp_Hunk_AllocXAnimClient, %eax\n" /* line 471 */
        "movl %eax, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl $str_002b7c54, (%esp)\n" /* "VIEWMODEL" */
        "calll XAnimCreateAnims\n"
        "movl %eax, -0x7c(%ebp)\n" /* pAnims */
        "movl $0, 0x14(%esp)\n" /* line 475 */
        "movl $0x16, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $str_0021df18, 8(%esp)\n" /* "root" */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimBlend\n"
        "movl %edi, %ebx\n" /* weapDef, dobjHandle */
        "movl $1, %esi\n" /* i */
        "jmp .Lf1d5ef8_001d6123\n"
        ".Lf1d5ef8_001d60f0:\n"
        "movl imp_Hunk_AllocXAnimPrecache, %edx\n" /* line 484 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimPrecache\n"
        "movl 0x18(%ebx), %eax\n" /* line 486 | dobjHandle */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* i */
        "movl -0x7c(%ebp), %ecx\n" /* pAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimCreate\n"
        "addl $1, %esi\n" /* line 478 | i */
        "addl $4, %ebx\n" /* dobjHandle */
        "cmpl $0x17, %esi\n" /* i */
        "je .Lf1d5ef8_001d6160\n"
        ".Lf1d5ef8_001d6123:\n"
        "movl 0x18(%ebx), %eax\n" /* line 481 | dobjHandle */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d60f0\n"
        "movl imp_Hunk_AllocXAnimPrecache, %eax\n" /* line 492 */
        "movl %eax, 4(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* weapDef */
        "movl %eax, (%esp)\n"
        "calll XAnimPrecache\n"
        "movl 0x18(%edi), %eax\n" /* line 494 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* i */
        "movl -0x7c(%ebp), %edx\n" /* pAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimCreate\n"
        "addl $1, %esi\n" /* line 478 | i */
        "addl $4, %ebx\n" /* dobjHandle */
        "cmpl $0x17, %esi\n" /* i */
        "jne .Lf1d5ef8_001d6123\n"
        ".Lf1d5ef8_001d6160:\n"
        "movl imp_Hunk_AllocXAnimClient, %eax\n" /* line 499 */
        "movl %eax, 4(%esp)\n"
        "movl -0x7c(%ebp), %ecx\n" /* pAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimCreateTree\n"
        "movl %eax, -0x80(%ebp)\n" /* pAnimTree */
        "movl -0x88(%ebp), %edx\n" /* line 503 | weapInfo */
        "movl %eax, 0xa4(%edx)\n"
        "movl %edx, %eax\n"
        "movl $0x17, %edx\n"
        ".Lf1d5ef8_001d618a:\n"
        "movl $0x3f800000, 4(%eax)\n" /* line 507 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 506 */
        "jne .Lf1d5ef8_001d618a\n"
        "movl 0x210(%edi), %eax\n" /* line 510 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jle .Lf1d5ef8_001d61ca\n"
        "movl $4, 4(%esp)\n" /* line 511 */
        "movl -0x7c(%ebp), %ecx\n" /* pAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x210(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d61ca:\n"
        "movl -0x88(%ebp), %eax\n" /* line 512 | weapInfo */
        "movss %xmm1, 0x14(%eax)\n"
        "movl 0x214(%edi), %eax\n" /* line 515 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jle .Lf1d5ef8_001d6206\n"
        "movl $7, 4(%esp)\n" /* line 516 */
        "movl -0x7c(%ebp), %edx\n" /* pAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x214(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d6206:\n"
        "movl -0x88(%ebp), %ecx\n" /* line 517 | weapInfo */
        "movss %xmm1, 0x20(%ecx)\n"
        "movl 0x218(%edi), %esi\n" /* line 520 | weapDef, i */
        "pxor %xmm1, %xmm1\n"
        "testl %esi, %esi\n" /* i */
        "jle .Lf1d5ef8_001d6242\n"
        "movl $8, 4(%esp)\n" /* line 521 */
        "movl -0x7c(%ebp), %eax\n" /* pAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x218(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d6242:\n"
        "movl -0x88(%ebp), %edx\n" /* line 522 | weapInfo */
        "movss %xmm1, 0x24(%edx)\n"
        "movl 0x21c(%edi), %ebx\n" /* line 525 | weapDef, dobjHandle */
        "pxor %xmm1, %xmm1\n"
        "testl %ebx, %ebx\n" /* dobjHandle */
        "jle .Lf1d5ef8_001d627e\n"
        "movl $9, 4(%esp)\n" /* line 526 */
        "movl -0x7c(%ebp), %ecx\n" /* pAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x21c(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d627e:\n"
        "movl -0x88(%ebp), %eax\n" /* line 527 | weapInfo */
        "movss %xmm1, 0x28(%eax)\n"
        "movl 0x224(%edi), %ecx\n" /* line 530 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %ecx, %ecx\n"
        "jle .Lf1d5ef8_001d62ba\n"
        "movl $0xa, 4(%esp)\n" /* line 531 */
        "movl -0x7c(%ebp), %edx\n" /* pAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x224(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d62ba:\n"
        "movl -0x88(%ebp), %ecx\n" /* line 532 | weapInfo */
        "movss %xmm1, 0x2c(%ecx)\n"
        "movl 0x218(%edi), %edx\n" /* line 535 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %edx, %edx\n"
        "jle .Lf1d5ef8_001d62f6\n"
        "movl $0xb, 4(%esp)\n" /* line 536 */
        "movl -0x7c(%ebp), %eax\n" /* pAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x218(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d62f6:\n"
        "movl -0x88(%ebp), %edx\n" /* line 537 | weapInfo */
        "movss %xmm1, 0x30(%edx)\n"
        "movl 0x234(%edi), %eax\n" /* line 540 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jle .Lf1d5ef8_001d6332\n"
        "movl $0xc, 4(%esp)\n" /* line 541 */
        "movl -0x7c(%ebp), %ecx\n" /* pAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x234(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d6332:\n"
        "movl -0x88(%ebp), %eax\n" /* line 542 | weapInfo */
        "movss %xmm1, 0x34(%eax)\n"
        "movl 0x230(%edi), %eax\n" /* line 545 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jle .Lf1d5ef8_001d636e\n"
        "movl $0xd, 4(%esp)\n" /* line 546 */
        "movl -0x7c(%ebp), %edx\n" /* pAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x230(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d636e:\n"
        "movl -0x88(%ebp), %ecx\n" /* line 547 | weapInfo */
        "movss %xmm1, 0x38(%ecx)\n"
        "movl 0x23c(%edi), %eax\n" /* line 550 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jle .Lf1d5ef8_001d63aa\n"
        "movl $0xe, 4(%esp)\n" /* line 551 */
        "movl -0x7c(%ebp), %eax\n" /* pAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x23c(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d63aa:\n"
        "movl -0x88(%ebp), %edx\n" /* line 552 | weapInfo */
        "movss %xmm1, 0x3c(%edx)\n"
        "movl 0x238(%edi), %eax\n" /* line 555 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jle .Lf1d5ef8_001d63e6\n"
        "movl $0xf, 4(%esp)\n" /* line 556 */
        "movl -0x7c(%ebp), %ecx\n" /* pAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x238(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d63e6:\n"
        "movl -0x88(%ebp), %eax\n" /* line 557 | weapInfo */
        "movss %xmm1, 0x40(%eax)\n"
        "movl 0x244(%edi), %eax\n" /* line 560 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jle .Lf1d5ef8_001d6422\n"
        "movl $0x10, 4(%esp)\n" /* line 561 */
        "movl -0x7c(%ebp), %edx\n" /* pAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x244(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d6422:\n"
        "movl -0x88(%ebp), %ecx\n" /* line 562 | weapInfo */
        "movss %xmm1, 0x44(%ecx)\n"
        "movl 0x240(%edi), %eax\n" /* line 565 | weapDef */
        "pxor %xmm1, %xmm1\n"
        "testl %eax, %eax\n"
        "jle .Lf1d5ef8_001d645e\n"
        "movl $0x11, 4(%esp)\n" /* line 566 */
        "movl -0x7c(%ebp), %eax\n" /* pAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetLengthMsec\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl 0x240(%edi), %xmm0\n" /* weapDef */
        "divss %xmm0, %xmm1\n"
        ".Lf1d5ef8_001d645e:\n"
        "movl -0x88(%ebp), %edx\n" /* line 567 | weapInfo */
        "movss %xmm1, 0x48(%edx)\n"
        "movl 0x68(%edi), %eax\n" /* line 570 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6d89\n"
        ".Lf1d5ef8_001d6475:\n"
        "movl 0x6c(%edi), %eax\n" /* line 573 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6e17\n"
        ".Lf1d5ef8_001d6481:\n"
        "movl 8(%ebp), %ebx\n" /* line 313 | weaponNum */
        "addl $0x400, %ebx\n"
        "movl %ebx, 0xc(%esp)\n" /* line 581 | dobjHandle */
        "movl -0x80(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x30(%ebp), %ecx\n" /* dobjModels */
        "movl %ecx, (%esp)\n"
        "calll Com_ClientDObjCreate\n"
        "movl $0, 4(%esp)\n" /* line 582 */
        "movl %ebx, (%esp)\n" /* dobjHandle */
        "calll Com_GetClientDObj\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, (%edx)\n"
        "movl $0x40, 8(%esp)\n" /* line 584 */
        "movl 0x10(%edi), %eax\n" /* weapDef */
        "movl %eax, 4(%esp)\n"
        "movl %edx, %eax\n"
        "addl $0x60, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "xorl %ebx, %ebx\n" /* line 587 | dobjHandle */
        "movl %ebx, 8(%esp)\n" /* dobjHandle */
        "movl $0, 4(%esp)\n"
        "movl -0x80(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimClearTreeGoalWeights\n"
        "movl $0, 0x1c(%esp)\n" /* line 588 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* dobjHandle */
        "movl $0x3f800000, %esi\n" /* i */
        "movl %esi, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "movl -0x80(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl $0, 0x1c(%esp)\n" /* line 589 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* dobjHandle */
        "movl %esi, 8(%esp)\n" /* i */
        "movl $1, 4(%esp)\n"
        "movl -0x80(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl 0x6c(%edi), %eax\n" /* line 591 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6dc4\n"
        ".Lf1d5ef8_001d6586:\n"
        "movl $0x3d4ccccd, 4(%esp)\n" /* line 597 */
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjUpdateClientInfo\n"
        ".Lf1d5ef8_001d659e:\n"
        "movl 0x1b4(%edi), %eax\n" /* line 601 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6a63\n"
        ".Lf1d5ef8_001d65ad:\n"
        "movl 0x118(%edi), %eax\n" /* line 610 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6a42\n"
        ".Lf1d5ef8_001d65bc:\n"
        "movl 0x11c(%edi), %eax\n" /* line 612 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6af6\n"
        ".Lf1d5ef8_001d65cb:\n"
        "movl 0x274(%edi), %eax\n" /* line 614 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6ad5\n"
        ".Lf1d5ef8_001d65da:\n"
        "movl 0x90(%edi), %eax\n" /* line 617 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6abc\n"
        ".Lf1d5ef8_001d65e9:\n"
        "movl 0x94(%edi), %eax\n" /* line 619 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6aa3\n"
        ".Lf1d5ef8_001d65f8:\n"
        "movl 0xa0(%edi), %eax\n" /* line 623 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xd4(%edx)\n"
        "movl 0xa4(%edi), %eax\n" /* line 624 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xd8(%ecx)\n"
        "movl 0xa8(%edi), %eax\n" /* line 625 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xdc(%edx)\n"
        "movl 0xac(%edi), %eax\n" /* line 626 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xe0(%ecx)\n"
        "movl 0xc0(%edi), %eax\n" /* line 627 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xe4(%edx)\n"
        "movl 0xc4(%edi), %eax\n" /* line 628 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xe8(%ecx)\n"
        "movl 0xc8(%edi), %eax\n" /* line 629 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xec(%edx)\n"
        "movl 0xcc(%edi), %eax\n" /* line 630 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xf0(%ecx)\n"
        "movl 0xd0(%edi), %eax\n" /* line 631 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xf4(%edx)\n"
        "movl 0xd4(%edi), %eax\n" /* line 632 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xf8(%ecx)\n"
        "movl 0xd8(%edi), %eax\n" /* line 633 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xfc(%edx)\n"
        "movl 0xdc(%edi), %eax\n" /* line 634 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x100(%ecx)\n"
        "movl 0xe0(%edi), %eax\n" /* line 635 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x104(%edx)\n"
        "movl 0xe4(%edi), %eax\n" /* line 636 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x108(%ecx)\n"
        "movl 0xe8(%edi), %eax\n" /* line 637 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x10c(%edx)\n"
        "movl 0xec(%edi), %eax\n" /* line 638 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x110(%ecx)\n"
        "movl 0xf0(%edi), %eax\n" /* line 639 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x114(%edx)\n"
        "movl 0xf4(%edi), %eax\n" /* line 640 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x118(%ecx)\n"
        "testl %eax, %eax\n" /* line 641 */
        "je .Lf1d5ef8_001d6c75\n"
        ".Lf1d5ef8_001d67d4:\n"
        "movl 0xf8(%edi), %eax\n" /* line 643 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x11c(%ecx)\n"
        "movl 0xfc(%edi), %eax\n" /* line 644 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x120(%edx)\n"
        "testl %eax, %eax\n" /* line 645 */
        "je .Lf1d5ef8_001d6c92\n"
        ".Lf1d5ef8_001d6810:\n"
        "movl 0x100(%edi), %eax\n" /* line 647 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x124(%edx)\n"
        "movl 0x104(%edi), %eax\n" /* line 648 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x128(%ecx)\n"
        "movl 0x108(%edi), %eax\n" /* line 649 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x12c(%edx)\n"
        "movl 0x10c(%edi), %eax\n" /* line 650 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x130(%ecx)\n"
        "movl -0x84(%ebp), %eax\n" /* line 652 | itemInfo */
        "movl 0x1c(%eax), %esi\n" /* i */
        "testl %esi, %esi\n" /* i */
        "je .Lf1d5ef8_001d6caf\n"
        ".Lf1d5ef8_001d6889:\n"
        "movl 0x9c(%edi), %eax\n" /* line 654 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x84(%ebp), %ecx\n" /* itemInfo */
        "movl %eax, 0x20(%ecx)\n"
        "testl %eax, %eax\n" /* line 655 */
        "je .Lf1d5ef8_001d6cc9\n"
        ".Lf1d5ef8_001d68a8:\n"
        "movl 0x110(%edi), %eax\n" /* line 658 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6a29\n"
        ".Lf1d5ef8_001d68b7:\n"
        "movl 0x114(%edi), %eax\n" /* line 661 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6b17\n"
        "movl -0x88(%ebp), %ecx\n" /* line 664 | weapInfo */
        "movl 0x15c(%ecx), %eax\n"
        "movl %eax, 0x160(%ecx)\n"
        ".Lf1d5ef8_001d68d8:\n"
        "movl 0x38c(%edi), %eax\n" /* line 666 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6c30\n"
        ".Lf1d5ef8_001d68e7:\n"
        "movl 0x394(%edi), %eax\n" /* line 673 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6c17\n"
        ".Lf1d5ef8_001d68f6:\n"
        "movl 0x398(%edi), %eax\n" /* line 675 | weapDef */
        "movl %eax, (%esp)\n"
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x168(%edx)\n"
        "movl 0x458(%edi), %eax\n" /* line 676 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6bfe\n"
        ".Lf1d5ef8_001d691f:\n"
        "cvtsi2ssl 0x45c(%edi), %xmm0\n" /* line 678 | weapDef */
        "movl -0x88(%ebp), %eax\n" /* weapInfo */
        "movss %xmm0, 0x148(%eax)\n"
        "movl 0x1b8(%edi), %eax\n" /* line 680 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6bcb\n"
        "movl imp_cgs, %eax\n" /* line 688 */
        "movl (%eax), %edx\n"
        "movl 0xba4c(%edx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* weaponNum */
        "movl %eax, 0xba54(%edx, %ecx, 4)\n"
        ".Lf1d5ef8_001d695b:\n"
        "movl 0x34c(%edi), %eax\n" /* line 691 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6ba8\n"
        ".Lf1d5ef8_001d696a:\n"
        "movl 0x1bc(%edi), %eax\n" /* line 697 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf1d5ef8_001d6b87\n"
        ".Lf1d5ef8_001d6979:\n"
        "movl 4(%edi), %eax\n" /* line 702 | weapDef */
        "movl %eax, (%esp)\n"
        "calll SEH_StringEd_GetString\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xb0(%ecx)\n"
        "testl %eax, %eax\n" /* line 703 */
        "je .Lf1d5ef8_001d6ce3\n"
        ".Lf1d5ef8_001d6998:\n"
        "movl 0x70(%edi), %eax\n" /* line 715 | weapDef */
        "movl %eax, (%esp)\n"
        "calll SEH_StringEd_GetString\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xb4(%ecx)\n"
        "testl %eax, %eax\n" /* line 716 */
        "je .Lf1d5ef8_001d6d36\n"
        ".Lf1d5ef8_001d69b7:\n"
        "movl 8(%edi), %eax\n" /* line 728 | weapDef */
        "movl %eax, (%esp)\n"
        "calll SEH_StringEd_GetString\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xb8(%ecx)\n"
        "testl %eax, %eax\n" /* line 729 */
        "jne .Lf1d5ef8_001d5f10\n"
        "movl imp_loc_warnings, %eax\n" /* line 731 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1d5ef8_001d6a15\n"
        "movl imp_loc_warningsAsErrors, %eax\n" /* line 733 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1d5ef8_001d6e52\n"
        "movl 8(%edi), %eax\n" /* line 734 | weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b7e1c, 4(%esp)\n" /* "Weapon %s: Could not translate AI overlay description "%s"" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1d5ef8_001d6a15:\n"
        "movl 8(%edi), %eax\n" /* line 738 | weapDef */
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xb8(%edx)\n"
        "jmp .Lf1d5ef8_001d5f10\n"
        ".Lf1d5ef8_001d6a29:\n"
        "movl %eax, (%esp)\n" /* line 659 */
        "calll FX_RegisterEffect\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x15c(%ecx)\n"
        "jmp .Lf1d5ef8_001d68b7\n"
        ".Lf1d5ef8_001d6a42:\n"
        "movl $7, 4(%esp)\n" /* line 611 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x178(%ecx)\n"
        "jmp .Lf1d5ef8_001d65bc\n"
        ".Lf1d5ef8_001d6a63:\n"
        "movl %eax, (%esp)\n" /* line 603 */
        "calll CL_RegisterModel\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xbc(%edx)\n"
        "movl 0x1b4(%edi), %edx\n" /* line 607 | weapDef */
        "cmpb $0, (%edx)\n"
        "je .Lf1d5ef8_001d65ad\n"
        "testl %eax, %eax\n"
        "jne .Lf1d5ef8_001d65ad\n"
        "movl %edx, 4(%esp)\n" /* line 608 */
        "movl $str_002b7c94, (%esp)\n" /* "WARNING: Weapon %s could not load world model
" */
        "calll Com_Printf\n"
        "jmp .Lf1d5ef8_001d65ad\n"
        ".Lf1d5ef8_001d6aa3:\n"
        "movl %eax, (%esp)\n" /* line 620 */
        "calll FX_RegisterEffect\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0xc4(%ecx)\n"
        "jmp .Lf1d5ef8_001d65f8\n"
        ".Lf1d5ef8_001d6abc:\n"
        "movl %eax, (%esp)\n" /* line 618 */
        "calll FX_RegisterEffect\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xc0(%edx)\n"
        "jmp .Lf1d5ef8_001d65e9\n"
        ".Lf1d5ef8_001d6ad5:\n"
        "movl $7, 4(%esp)\n" /* line 615 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x180(%ecx)\n"
        "jmp .Lf1d5ef8_001d65da\n"
        ".Lf1d5ef8_001d6af6:\n"
        "movl $7, 4(%esp)\n" /* line 613 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x17c(%edx)\n"
        "jmp .Lf1d5ef8_001d65cb\n"
        ".Lf1d5ef8_001d6b17:\n"
        "movl %eax, (%esp)\n" /* line 662 */
        "calll FX_RegisterEffect\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x160(%edx)\n"
        "jmp .Lf1d5ef8_001d68d8\n"
        ".Lf1d5ef8_001d6b30:\n"
        "movl 4(%edi), %eax\n" /* line 448 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b7be8, 4(%esp)\n" /* "CG_RegisterWeapon: No hand model specified for [%s]" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d5ef8_001d5fea\n"
        ".Lf1d5ef8_001d6b50:\n"
        "movl 4(%edi), %eax\n" /* line 468 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b7c20, 4(%esp)\n" /* "CG_RegisterWeapon: No idle anim specified for [%s]" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d5ef8_001d6097\n"
        ".Lf1d5ef8_001d6b70:\n"
        "leal -0x30(%ebp), %edx\n" /* line 464 | dobjModels */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* weaponNum */
        "movl %ecx, (%esp)\n"
        "calll CG_Weapons_SetToDefault\n"
        "jmp .Lf1d5ef8_001d6083\n"
        ".Lf1d5ef8_001d6b87:\n"
        "movl $7, 4(%esp)\n" /* line 698 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x13c(%edx)\n"
        "jmp .Lf1d5ef8_001d6979\n"
        ".Lf1d5ef8_001d6ba8:\n"
        "movl $7, 4(%esp)\n" /* line 693 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "movl 0x34c(%edi), %eax\n" /* line 694 | weapDef */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterHudMsgIconMaterial\n"
        "jmp .Lf1d5ef8_001d696a\n"
        ".Lf1d5ef8_001d6bcb:\n"
        "movl $7, 4(%esp)\n" /* line 682 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x138(%edx)\n"
        "movl imp_cgs, %edx\n" /* line 683 */
        "movl (%edx), %edx\n"
        "movl 8(%ebp), %ecx\n" /* weaponNum */
        "movl %eax, 0xba54(%edx, %ecx, 4)\n"
        "jmp .Lf1d5ef8_001d695b\n"
        ".Lf1d5ef8_001d6bfe:\n"
        "movl %eax, (%esp)\n" /* line 677 */
        "calll FX_RegisterEffect\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x16c(%ecx)\n"
        "jmp .Lf1d5ef8_001d691f\n"
        ".Lf1d5ef8_001d6c17:\n"
        "movl %eax, (%esp)\n" /* line 674 */
        "calll FX_RegisterEffect\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x164(%ecx)\n"
        "jmp .Lf1d5ef8_001d68f6\n"
        ".Lf1d5ef8_001d6c30:\n"
        "movl %eax, (%esp)\n" /* line 668 */
        "calll CL_RegisterModel\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x140(%edx)\n"
        "testl %eax, %eax\n" /* line 670 */
        "jne .Lf1d5ef8_001d68e7\n"
        "movl 0x1b4(%edi), %eax\n" /* line 671 | weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b7d00, 4(%esp)\n" /* "Weapon %s does not specify a valid projectile model (%s)
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d5ef8_001d68e7\n"
        ".Lf1d5ef8_001d6c75:\n"
        "movl $str_002b7cc4, (%esp)\n" /* line 642 */
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0x118(%edx)\n"
        "jmp .Lf1d5ef8_001d67d4\n"
        ".Lf1d5ef8_001d6c92:\n"
        "movl $str_002b7cd0, (%esp)\n" /* line 646 */
        "calll Com_FindSoundAlias\n"
        "movl -0x88(%ebp), %ecx\n" /* weapInfo */
        "movl %eax, 0x120(%ecx)\n"
        "jmp .Lf1d5ef8_001d6810\n"
        ".Lf1d5ef8_001d6caf:\n"
        "movl $str_002b7ce0, (%esp)\n" /* line 653 */
        "calll Com_FindSoundAlias\n"
        "movl -0x84(%ebp), %edx\n" /* itemInfo */
        "movl %eax, 0x1c(%edx)\n"
        "jmp .Lf1d5ef8_001d6889\n"
        ".Lf1d5ef8_001d6cc9:\n"
        "movl $str_002b7cec, (%esp)\n" /* line 656 */
        "calll Com_FindSoundAlias\n"
        "movl -0x84(%ebp), %edx\n" /* itemInfo */
        "movl %eax, 0x20(%edx)\n"
        "jmp .Lf1d5ef8_001d68a8\n"
        ".Lf1d5ef8_001d6ce3:\n"
        "movl imp_loc_warnings, %eax\n" /* line 705 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1d5ef8_001d6d22\n"
        "movl imp_loc_warningsAsErrors, %eax\n" /* line 707 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1d5ef8_001d6e8e\n"
        "movl 4(%edi), %eax\n" /* line 708 | weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b7d3c, 4(%esp)\n" /* "Weapon %s: Could not translate display name "%s"" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1d5ef8_001d6d22:\n"
        "movl 4(%edi), %eax\n" /* line 712 | weapDef */
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xb0(%edx)\n"
        "jmp .Lf1d5ef8_001d6998\n"
        ".Lf1d5ef8_001d6d36:\n"
        "movl imp_loc_warnings, %eax\n" /* line 718 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1d5ef8_001d6d75\n"
        "movl imp_loc_warningsAsErrors, %eax\n" /* line 720 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1d5ef8_001d6e70\n"
        "movl 0x70(%edi), %eax\n" /* line 721 | weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b7db0, 4(%esp)\n" /* "Weapon %s: Could not translate mode name "%s"" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1d5ef8_001d6d75:\n"
        "movl 0x70(%edi), %eax\n" /* line 725 | weapDef */
        "movl -0x88(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xb4(%edx)\n"
        "jmp .Lf1d5ef8_001d69b7\n"
        ".Lf1d5ef8_001d6d89:\n"
        "movl $0x15, 4(%esp)\n" /* line 570 */
        "movl -0x7c(%ebp), %ecx\n" /* pAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimIsLooped\n"
        "testb %al, %al\n"
        "je .Lf1d5ef8_001d6475\n"
        "movl 0x68(%edi), %eax\n" /* line 571 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b7c60, 4(%esp)\n" /* "CG_RegisterWeapon: ADS anim [%s] cannot be looping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d5ef8_001d6475\n"
        ".Lf1d5ef8_001d6dc4:\n"
        "movl $0, 0x1c(%esp)\n" /* line 593 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* dobjHandle */
        "movl %ebx, 0xc(%esp)\n" /* dobjHandle */
        "movl %esi, 8(%esp)\n" /* i */
        "movl $0x16, 4(%esp)\n"
        "movl -0x80(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl %esi, 8(%esp)\n" /* line 594 | i */
        "movl $0x16, 4(%esp)\n"
        "movl -0x80(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetTime\n"
        "jmp .Lf1d5ef8_001d6586\n"
        ".Lf1d5ef8_001d6e17:\n"
        "movl $0x16, 4(%esp)\n" /* line 573 */
        "movl -0x7c(%ebp), %eax\n" /* pAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimIsLooped\n"
        "testb %al, %al\n"
        "je .Lf1d5ef8_001d6481\n"
        "movl 0x6c(%edi), %eax\n" /* line 574 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b7c60, 4(%esp)\n" /* "CG_RegisterWeapon: ADS anim [%s] cannot be looping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d5ef8_001d6481\n"
        ".Lf1d5ef8_001d6e52:\n"
        "movl 8(%edi), %eax\n" /* line 736 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl (%edi), %eax\n" /* weapDef */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b7e58, (%esp)\n" /* "^3WARNING: Weapon %s: Could not translate AI overlay descrip" */
        "calll Com_Printf\n"
        "jmp .Lf1d5ef8_001d6a15\n"
        ".Lf1d5ef8_001d6e70:\n"
        "movl 0x70(%edi), %eax\n" /* line 723 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl (%edi), %eax\n" /* weapDef */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b7de0, (%esp)\n" /* "^3WARNING: Weapon %s: Could not translate mode name "%s"
" */
        "calll Com_Printf\n"
        "jmp .Lf1d5ef8_001d6d75\n"
        ".Lf1d5ef8_001d6e8e:\n"
        "movl 4(%edi), %eax\n" /* line 710 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl (%edi), %eax\n" /* weapDef */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b7d70, (%esp)\n" /* "^3WARNING: Weapon %s: Could not translate display name "%s"
" */
        "calll Com_Printf\n"
        "jmp .Lf1d5ef8_001d6d22\n"
    );
}
#else
void CG_RegisterWeapon(int weaponNum)
{
    byte *weapDef;
    byte *weapInfo;
    byte *itemInfo;
    struct XAnim_s *pAnims;
    void *pAnimTree;
    char szModelFile[64];
    int dobjHandle;
    int i;
    float rate;
    byte dobjModels[16 * 4]; /* DObjModel_s array, 4 entries x 16 bytes each */

    /* line 411 */
    removeMeWhenMPStopsCrashingInHere = weaponNum;

    /* line 414 */
    if (weaponNum == 0)
        return;

    /* line 424: compute weapInfo pointer = cg_weapons + weaponNum * 0x1b4 */
    {
        byte *cg_weap_base = *(byte **)imp_cg_weapons;
        weapInfo = cg_weap_base + weaponNum * 0x1b4;
    }

    /* line 425 */
    weapDef = (byte *)BG_GetWeaponDef(weaponNum);

    /* line 427: check if already registered */
    if (*(int *)(weapInfo + 0xa8) != 0)
        return;

    /* line 430 */
    SCR_UpdateScreen();

    /* line 432 */
    memset(weapInfo, 0, 0x1b4);
    /* line 433 */
    *(int *)(weapInfo + 0xa8) = 1;

    /* line 436: itemInfo = bg_itemlist + weaponNum * 0x2c */
    {
        byte *bg_items = (byte *)*(int *)imp_bg_itemlist;
        *(int *)(weapInfo + 0xac) = (int)(bg_items + weaponNum * 0x2c);
    }

    /* line 438: itemInfo = cg_items + weaponNum * 0x24 */
    {
        byte *cg_itm = *(byte **)imp_cg_items;
        itemInfo = cg_itm + weaponNum * 0x24;
    }

    /* line 440 */
    CG_RegisterItemVisuals(weaponNum);

    /* line 442 */
    *(int *)(weapInfo + 0xa0) = -1;

    /* line 444: check if viewmodel hand model is specified */
    if (*(char *)*(int *)(weapDef + 0xc) == '\0')
        goto after_viewmodel;

    /* line 447: check if hand model name is set */
    if (*(int *)(weapDef + 0x10) == 0 || *(char *)*(int *)(weapDef + 0x10) == '\0') {
        Com_Error(1, (const char *)str_002b7be8, *(char **)(weapDef + 4));
    }

    /* line 450-453: init dobjModels */
    *(int *)(dobjModels + 0x00) = 0; /* model */
    *(int *)(dobjModels + 0x04) = 0; /* boneName for slot 0 */
    *(int *)(dobjModels + 0x08) = (int)str_002b6e38; /* boneName for slot 0 */
    *(int *)(dobjModels + 0x0c) = 0; /* ignoreCollision for slot 0 */

    /* line 456: build hand model path */
    sprintf(szModelFile, (const char *)str_00215f50, (const char *)str_002b7b28, *(char **)(weapDef + 0x10));
    *(int *)(dobjModels + 0x00) = (int)CL_RegisterModel(szModelFile);

    /* line 460: build viewmodel path */
    sprintf(szModelFile, (const char *)str_00215f50, (const char *)str_002b7b28, *(char **)(weapDef + 0xc));
    *(int *)(dobjModels + 0x10) = (int)CL_RegisterModel(szModelFile);

    /* line 463: check if models are bad */
    if (XModelBad(*(void **)(dobjModels + 0x00)) || XModelBad(*(void **)(dobjModels + 0x10))) {
        CG_Weapons_SetToDefault(weaponNum, (weaponInfo_s (*)[4])dobjModels);
    }

    /* line 467: check if idle anim specified */
    if (*(int *)(weapDef + 0x18) == 0 || *(char *)*(int *)(weapDef + 0x18) == '\0') {
        Com_Error(1, (const char *)str_002b7c20, *(char **)(weapDef + 4));
    }

    /* line 471: create anim tree */
    pAnims = XAnimCreateAnims((const char *)str_002b7c54, 0x17, (void *)*(int *)&imp_Hunk_AllocXAnimClient);

    /* line 475: blend root */
    XAnimBlend(pAnims, 0, (const char *)str_0021df18, 1, 0x16, 0);

    /* line 478-496: create anims for each weapon anim slot */
    {
        byte *animPtr = weapDef;
        i = 1;
        while (i < 0x17) {
            const char *animName = *(const char **)(animPtr + 0x18);
            if (*animName != '\0') {
                XAnimPrecache(animName, (void *)*(int *)&imp_Hunk_AllocXAnimPrecache);
                XAnimCreate(pAnims, i, animName);
            } else {
                /* line 492: use default idle anim */
                XAnimPrecache(*(const char **)(weapDef + 0x18), (void *)*(int *)&imp_Hunk_AllocXAnimPrecache);
                XAnimCreate(pAnims, i, *(const char **)(weapDef + 0x18));
            }
            i++;
            animPtr += 4;
        }
    }

    /* line 499: create anim tree */
    pAnimTree = XAnimCreateTree((void *)pAnims, (void *)*(int *)&imp_Hunk_AllocXAnimClient);

    /* line 503 */
    *(int *)(weapInfo + 0xa4) = (int)pAnimTree;

    /* line 506-507: set rate = 1.0 for all 0x17 anims */
    {
        byte *ratePtr = weapInfo;
        int count = 0x17;
        while (count > 0) {
            *(int *)(ratePtr + 4) = 0x3f800000; /* 1.0f */
            ratePtr += 4;
            count--;
        }
    }

    /* line 510-512: compute fire rate */
    {
        float fireRate = 0.0f;
        if (*(int *)(weapDef + 0x210) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 4);
            fireRate = (float)msec / (float)*(int *)(weapDef + 0x210);
        }
        *(float *)(weapInfo + 0x14) = fireRate;
    }

    /* line 515-517: melee rate */
    {
        float meleeRate = 0.0f;
        if (*(int *)(weapDef + 0x214) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 7);
            meleeRate = (float)msec / (float)*(int *)(weapDef + 0x214);
        }
        *(float *)(weapInfo + 0x20) = meleeRate;
    }

    /* line 520-522 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x218) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 8);
            r = (float)msec / (float)*(int *)(weapDef + 0x218);
        }
        *(float *)(weapInfo + 0x24) = r;
    }

    /* line 525-527 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x21c) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 9);
            r = (float)msec / (float)*(int *)(weapDef + 0x21c);
        }
        *(float *)(weapInfo + 0x28) = r;
    }

    /* line 530-532 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x224) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 0xa);
            r = (float)msec / (float)*(int *)(weapDef + 0x224);
        }
        *(float *)(weapInfo + 0x2c) = r;
    }

    /* line 535-537 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x218) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 0xb);
            r = (float)msec / (float)*(int *)(weapDef + 0x218);
        }
        *(float *)(weapInfo + 0x30) = r;
    }

    /* line 540-542 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x234) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 0xc);
            r = (float)msec / (float)*(int *)(weapDef + 0x234);
        }
        *(float *)(weapInfo + 0x34) = r;
    }

    /* line 545-547 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x230) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 0xd);
            r = (float)msec / (float)*(int *)(weapDef + 0x230);
        }
        *(float *)(weapInfo + 0x38) = r;
    }

    /* line 550-552 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x23c) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 0xe);
            r = (float)msec / (float)*(int *)(weapDef + 0x23c);
        }
        *(float *)(weapInfo + 0x3c) = r;
    }

    /* line 555-557 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x238) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 0xf);
            r = (float)msec / (float)*(int *)(weapDef + 0x238);
        }
        *(float *)(weapInfo + 0x40) = r;
    }

    /* line 560-562 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x244) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 0x10);
            r = (float)msec / (float)*(int *)(weapDef + 0x244);
        }
        *(float *)(weapInfo + 0x44) = r;
    }

    /* line 565-567 */
    {
        float r = 0.0f;
        if (*(int *)(weapDef + 0x240) > 0) {
            int msec = XAnimGetLengthMsec(pAnims, 0x11);
            r = (float)msec / (float)*(int *)(weapDef + 0x240);
        }
        *(float *)(weapInfo + 0x48) = r;
    }

    /* line 570: check if ADS fire anim (0x15) is looped */
    if (*(char *)*(int *)(weapDef + 0x68) != '\0') {
        if (XAnimIsLooped(pAnims, 0x15)) {
            Com_Error(1, (const char *)str_002b7c60, *(char **)(weapDef + 0x68));
        }
    }

    /* line 573: check if ADS up anim (0x16) is looped */
    if (*(char *)*(int *)(weapDef + 0x6c) != '\0') {
        if (XAnimIsLooped(pAnims, 0x16)) {
            Com_Error(1, (const char *)str_002b7c60, *(char **)(weapDef + 0x6c));
        }
    }

    /* line 581: create DObj */
    dobjHandle = weaponNum + 0x400;
    Com_ClientDObjCreate((DObjModel_s *)dobjModels, 2, (struct XAnimTree_s *)pAnimTree, dobjHandle);

    /* line 582 */
    *(int *)(weapInfo + 0x00) = (int)Com_GetClientDObj(dobjHandle, 0);

    /* line 584 */
    I_strncpyz((char *)(weapInfo + 0x60), *(const char **)(weapDef + 0x10), 0x40);

    /* line 587 */
    XAnimClearTreeGoalWeights(pAnimTree, 0, 0);

    /* line 588: set goal weight for idle anim */
    {
        float w_1f = 1.0f;
        XAnimSetGoalWeight(pAnimTree, 0, w_1f, 0, *(float *)(weapInfo + 4), 0, 0, 1);
    }

    /* line 589: set goal weight for second anim */
    {
        float w_1f = 1.0f;
        XAnimSetGoalWeight(pAnimTree, 1, w_1f, 0, *(float *)(weapInfo + 8), 0, 0, 1);
    }

    /* line 591: if ADS up anim exists */
    if (*(char *)*(int *)(weapDef + 0x6c) != '\0') {
        /* line 593 */
        float w_1f = 1.0f;
        XAnimSetGoalWeight(pAnimTree, 0x16, w_1f, 0, 0, 0, 0, 1);
        /* line 594 */
        XAnimSetTime(pAnimTree, 0x16, w_1f);
    }

    /* line 597: update client info with timescale 0.05 */
    DObjUpdateClientInfo(*(struct DObj_s **)(weapInfo + 0x00), 0.05f);

after_viewmodel:
    /* line 601: register world model */
    if (*(char *)*(int *)(weapDef + 0x1b4) != '\0') {
        *(int *)(weapInfo + 0xbc) = (int)CL_RegisterModel(*(const char **)(weapDef + 0x1b4));
        /* line 607 */
        if (*(char *)*(int *)(weapDef + 0x1b4) != '\0' && *(int *)(weapInfo + 0xbc) == 0) {
            Com_Printf((const char *)str_002b7c94, *(char **)(weapDef + 0x1b4));
        }
    }

    /* line 610: register ammo counter material */
    if (*(char *)*(int *)(weapDef + 0x118) != '\0') {
        *(int *)(weapInfo + 0x178) = CL_RegisterMaterialNoMip(*(const char **)(weapDef + 0x118), 7);
    }

    /* line 612: register ammo counter clip material */
    if (*(char *)*(int *)(weapDef + 0x11c) != '\0') {
        *(int *)(weapInfo + 0x17c) = CL_RegisterMaterialNoMip(*(const char **)(weapDef + 0x11c), 7);
    }

    /* line 614: register overlay material */
    if (*(char *)*(int *)(weapDef + 0x274) != '\0') {
        *(int *)(weapInfo + 0x180) = CL_RegisterMaterialNoMip(*(const char **)(weapDef + 0x274), 7);
    }

    /* line 617: register flash effect */
    if (*(char *)*(int *)(weapDef + 0x90) != '\0') {
        *(int *)(weapInfo + 0xc0) = FX_RegisterEffect(*(const char **)(weapDef + 0x90));
    }

    /* line 619: register ads flash effect */
    if (*(char *)*(int *)(weapDef + 0x94) != '\0') {
        *(int *)(weapInfo + 0xc4) = FX_RegisterEffect(*(const char **)(weapDef + 0x94));
    }

    /* line 623-638: register sound aliases */
    *(int *)(weapInfo + 0xd4) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xa0));
    *(int *)(weapInfo + 0xd8) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xa4));
    *(int *)(weapInfo + 0xdc) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xa8));
    *(int *)(weapInfo + 0xe0) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xac));
    *(int *)(weapInfo + 0xe4) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xc0));
    *(int *)(weapInfo + 0xe8) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xc4));
    *(int *)(weapInfo + 0xec) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xc8));
    *(int *)(weapInfo + 0xf0) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xcc));
    *(int *)(weapInfo + 0xf4) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xd0));
    *(int *)(weapInfo + 0xf8) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xd4));
    *(int *)(weapInfo + 0xfc) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xd8));
    *(int *)(weapInfo + 0x100) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xdc));
    *(int *)(weapInfo + 0x104) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xe0));
    *(int *)(weapInfo + 0x108) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xe4));
    *(int *)(weapInfo + 0x10c) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xe8));
    *(int *)(weapInfo + 0x110) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xec));
    *(int *)(weapInfo + 0x114) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xf0));

    /* line 640: last fire sound */
    *(int *)(weapInfo + 0x118) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xf4));
    if (*(int *)(weapInfo + 0x118) == 0) {
        /* line 642: fallback */
        *(int *)(weapInfo + 0x118) = (int)Com_FindSoundAlias((const char *)str_002b7cc4);
    }

    /* line 643-644 */
    *(int *)(weapInfo + 0x11c) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xf8));
    *(int *)(weapInfo + 0x120) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0xfc));
    if (*(int *)(weapInfo + 0x120) == 0) {
        /* line 646: fallback */
        *(int *)(weapInfo + 0x120) = (int)Com_FindSoundAlias((const char *)str_002b7cd0);
    }

    /* line 647-650 */
    *(int *)(weapInfo + 0x124) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0x100));
    *(int *)(weapInfo + 0x128) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0x104));
    *(int *)(weapInfo + 0x12c) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0x108));
    *(int *)(weapInfo + 0x130) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0x10c));

    /* line 652: pickup sound */
    if (*(int *)(itemInfo + 0x1c) == 0) {
        *(int *)(itemInfo + 0x1c) = (int)Com_FindSoundAlias((const char *)str_002b7ce0);
    }

    /* line 654 */
    *(int *)(itemInfo + 0x20) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0x9c));
    if (*(int *)(itemInfo + 0x20) == 0) {
        *(int *)(itemInfo + 0x20) = (int)Com_FindSoundAlias((const char *)str_002b7cec);
    }

    /* line 658: register shell eject effect */
    if (*(char *)*(int *)(weapDef + 0x110) != '\0') {
        *(int *)(weapInfo + 0x15c) = FX_RegisterEffect(*(const char **)(weapDef + 0x110));
    }

    /* line 661: register second shell eject effect */
    if (*(char *)*(int *)(weapDef + 0x114) != '\0') {
        *(int *)(weapInfo + 0x160) = FX_RegisterEffect(*(const char **)(weapDef + 0x114));
    } else {
        /* line 664: copy first to second */
        *(int *)(weapInfo + 0x160) = *(int *)(weapInfo + 0x15c);
    }

    /* line 666: register projectile model */
    if (*(char *)*(int *)(weapDef + 0x38c) != '\0') {
        *(int *)(weapInfo + 0x140) = (int)CL_RegisterModel(*(const char **)(weapDef + 0x38c));
        if (*(int *)(weapInfo + 0x140) == 0) {
            Com_Error(1, (const char *)str_002b7d00, *(char **)(weapDef + 0x00), *(char **)(weapDef + 0x1b4));
        }
    }

    /* line 673: register projectile trail effect */
    if (*(char *)*(int *)(weapDef + 0x394) != '\0') {
        *(int *)(weapInfo + 0x164) = FX_RegisterEffect(*(const char **)(weapDef + 0x394));
    }

    /* line 675: register projectile impact sound */
    *(int *)(weapInfo + 0x168) = (int)Com_FindSoundAlias(*(const char **)(weapDef + 0x398));

    /* line 676: register turret overheat effect */
    if (*(char *)*(int *)(weapDef + 0x458) != '\0') {
        *(int *)(weapInfo + 0x16c) = FX_RegisterEffect(*(const char **)(weapDef + 0x458));
    }

    /* line 678: turret barrel spin speed */
    *(float *)(weapInfo + 0x148) = (float)*(int *)(weapDef + 0x45c);

    /* line 680: register weapon icon material */
    if (*(char *)*(int *)(weapDef + 0x1b8) != '\0') {
        *(int *)(weapInfo + 0x138) = CL_RegisterMaterial(*(const char **)(weapDef + 0x1b8), 7);
        /* line 683 */
        {
            byte *cgsPtr = *(byte **)imp_cgs;
            *(int *)(cgsPtr + 0xba54 + weaponNum * 4) = *(int *)(weapInfo + 0x138);
        }
    } else {
        /* line 688: use hint_usable as fallback icon */
        byte *cgsPtr = *(byte **)imp_cgs;
        *(int *)(cgsPtr + 0xba54 + weaponNum * 4) = *(int *)(cgsPtr + 0xba4c);
    }

    /* line 691: register kill icon */
    if (*(char *)*(int *)(weapDef + 0x34c) != '\0') {
        CL_RegisterMaterial(*(const char **)(weapDef + 0x34c), 7);
        CL_RegisterHudMsgIconMaterial(*(const char **)(weapDef + 0x34c));
    }

    /* line 697: register ammo icon */
    if (*(char *)*(int *)(weapDef + 0x1bc) != '\0') {
        *(int *)(weapInfo + 0x13c) = CL_RegisterMaterial(*(const char **)(weapDef + 0x1bc), 7);
    }

    /* line 702: translate display name */
    *(int *)(weapInfo + 0xb0) = (int)SEH_StringEd_GetString(*(const char **)(weapDef + 4));
    if (*(int *)(weapInfo + 0xb0) == 0) {
        if (*(byte *)(*(byte **)imp_loc_warnings + 8) != 0) {
            if (*(byte *)(*(byte **)imp_loc_warningsAsErrors + 8) != 0) {
                Com_Error(6, (const char *)str_002b7d3c, *(char **)(weapDef + 0x00), *(char **)(weapDef + 4));
            } else {
                Com_Printf((const char *)str_002b7d70, *(char **)(weapDef + 0x00), *(char **)(weapDef + 4));
            }
        }
        /* line 712 */
        *(int *)(weapInfo + 0xb0) = *(int *)(weapDef + 4);
    }

    /* line 715: translate mode name */
    *(int *)(weapInfo + 0xb4) = (int)SEH_StringEd_GetString(*(const char **)(weapDef + 0x70));
    if (*(int *)(weapInfo + 0xb4) == 0) {
        if (*(byte *)(*(byte **)imp_loc_warnings + 8) != 0) {
            if (*(byte *)(*(byte **)imp_loc_warningsAsErrors + 8) != 0) {
                Com_Error(6, (const char *)str_002b7db0, *(char **)(weapDef + 0x00), *(char **)(weapDef + 0x70));
            } else {
                Com_Printf((const char *)str_002b7de0, *(char **)(weapDef + 0x00), *(char **)(weapDef + 0x70));
            }
        }
        /* line 725 */
        *(int *)(weapInfo + 0xb4) = *(int *)(weapDef + 0x70);
    }

    /* line 728: translate AI overlay description */
    *(int *)(weapInfo + 0xb8) = (int)SEH_StringEd_GetString(*(const char **)(weapDef + 8));
    if (*(int *)(weapInfo + 0xb8) == 0) {
        if (*(byte *)(*(byte **)imp_loc_warnings + 8) != 0) {
            if (*(byte *)(*(byte **)imp_loc_warningsAsErrors + 8) != 0) {
                Com_Error(6, (const char *)str_002b7e1c, *(char **)(weapDef + 0x00), *(char **)(weapDef + 8));
            } else {
                Com_Printf((const char *)str_002b7e58, *(char **)(weapDef + 0x00), *(char **)(weapDef + 8));
            }
        }
        /* line 738 */
        *(int *)(weapInfo + 0xb8) = *(int *)(weapDef + 8);
    }
}
#endif

/* line 843 */
__attribute__((naked))
void CG_RegisterItemVisuals(int itemNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 843 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* itemNum */
        /* { scope 1 */
        "leal (%ecx, %ecx, 8), %eax\n" /* line 856 */
        "movl imp_cg_items, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %esi\n" /* itemInfo */
        "movl (%esi), %eax\n" /* line 857 | itemInfo */
        "testl %eax, %eax\n"
        "je .Lf1d6eac_001d6ed4\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 884 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d6eac_001d6ed4:\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 860 */
        "leal (%ecx, %eax, 2), %eax\n"
        "movl imp_bg_itemlist, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, (%esi)\n" /* line 862 | itemInfo */
        "movl %eax, %ebx\n"
        "movl %esi, %edi\n" /* itemInfo */
        "movl $2, -0x20(%ebp)\n"
        ".Lf1d6eac_001d6ef7:\n"
        "movl 8(%ebx), %eax\n" /* line 866 */
        "testl %eax, %eax\n"
        "je .Lf1d6eac_001d6f03\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1d6eac_001d6f57\n"
        ".Lf1d6eac_001d6f03:\n"
        "addl $4, %ebx\n" /* line 871 */
        "addl $4, %edi\n"
        "subl $1, -0x20(%ebp)\n" /* line 864 */
        "jne .Lf1d6eac_001d6ef7\n"
        "movl $7, 4(%esp)\n" /* line 874 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xc(%esi)\n" /* itemInfo */
        "movl -0x1c(%ebp), %edx\n" /* line 876 */
        "movl 4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d6eac_001d6f6c\n"
        "movl %eax, (%esp)\n" /* line 877 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0x1c(%esi)\n" /* itemInfo */
        ".Lf1d6eac_001d6f3d:\n"
        "movl %eax, 0x20(%esi)\n" /* line 878 | itemInfo */
        "movl -0x1c(%ebp), %eax\n" /* line 880 */
        "cmpl $1, 0x1c(%eax)\n"
        "je .Lf1d6eac_001d6f71\n"
        ".Lf1d6eac_001d6f49:\n"
        "movl $1, (%esi)\n" /* line 883 | itemInfo */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 884 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d6eac_001d6f57:\n"
        "calll SCR_UpdateScreen\n" /* line 870 */
        "movl 8(%ebx), %eax\n" /* line 871 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterModel\n"
        "movl %eax, 4(%edi)\n"
        "jmp .Lf1d6eac_001d6f03\n"
        ".Lf1d6eac_001d6f6c:\n"
        "movl 0x1c(%esi), %eax\n" /* itemInfo */
        "jmp .Lf1d6eac_001d6f3d\n"
        ".Lf1d6eac_001d6f71:\n"
        "movl 0x20(%eax), %eax\n" /* line 881 */
        "movl %eax, (%esp)\n"
        "calll CG_RegisterWeapon\n"
        "jmp .Lf1d6eac_001d6f49\n"
    );
}

/* line 892 */
__attribute__((naked))
void CG_RegisterItems(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 892 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x120, %esp\n"
        /* { scope 1 */
        "movl $8, (%esp)\n" /* line 898 */
        "calll CL_GetConfigString\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x109(%ebp), %eax\n" /* items */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl imp_bg_numItems, %edx\n" /* line 900 */
        "cmpl $1, (%edx)\n"
        "jle .Lf1d6f7e_001d7005\n"
        "movl $1, %ebx\n" /* i */
        "movl %edx, %esi\n"
        "jmp .Lf1d6f7e_001d6fd0\n"
        ".Lf1d6f7e_001d6fbb:\n"
        "subl $0x30, %eax\n" /* line 906 */
        "movl %ebx, %ecx\n" /* line 909 | i */
        "andl $3, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1d6f7e_001d6ff4\n"
        ".Lf1d6f7e_001d6fc9:\n"
        "addl $1, %ebx\n" /* line 900 | i */
        "cmpl (%edx), %ebx\n" /* i */
        "jge .Lf1d6f7e_001d7005\n"
        ".Lf1d6f7e_001d6fd0:\n"
        "movl %ebx, %eax\n" /* line 904 | i */
        "testl %ebx, %ebx\n" /* i */
        "js .Lf1d6f7e_001d700f\n"
        ".Lf1d6f7e_001d6fd6:\n"
        "sarl $2, %eax\n"
        "movsbl -0x109(%ebp, %eax), %eax\n"
        "cmpl $0x39, %eax\n" /* line 905 */
        "jle .Lf1d6f7e_001d6fbb\n"
        "subl $0x57, %eax\n" /* line 908 */
        "movl %ebx, %ecx\n" /* line 909 | i */
        "andl $3, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1d6f7e_001d6fc9\n"
        ".Lf1d6f7e_001d6ff4:\n"
        "movl %ebx, (%esp)\n" /* line 910 | i */
        "calll CG_RegisterItemVisuals\n"
        "movl %esi, %edx\n"
        "addl $1, %ebx\n" /* line 900 | i */
        "cmpl (%edx), %ebx\n" /* i */
        "jl .Lf1d6f7e_001d6fd0\n"
        /* } scope */
        ".Lf1d6f7e_001d7005:\n"
        "addl $0x120, %esp\n" /* line 912 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d6f7e_001d700f:\n"
        "leal 3(%ebx), %eax\n" /* line 904 | i */
        "jmp .Lf1d6f7e_001d6fd6\n"
    );
}

/* line 819 */
__attribute__((naked))
void CG_UpdateHandViewmodels(const char *handModel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 819 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl $1, %ebx\n"
        "movl $0x1b4, %edi\n"
        "jmp .Lf1d7014_001d7035\n"
        /* { scope 1: weapDef, pAnimTree, dobjModels, dobjHandle, ... */
        ".Lf1d7014_001d702c:\n"
        "addl $1, %ebx\n" /* line 826 | weaponIdx */
        "addl $0x1b4, %edi\n"
        ".Lf1d7014_001d7035:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n" /* weaponIdx */
        "jg .Lf1d7014_001d718f\n"
        "movl imp_cg_weapons, %eax\n" /* line 828 */
        "movl %edi, %esi\n" /* weapInfo */
        "addl (%eax), %esi\n" /* weapInfo */
        "leal 0x60(%esi), %eax\n" /* line 830 | weapInfo */
        "movl %eax, -0x88(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* handModel */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1d7014_001d702c\n"
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 767 */
        "je .Lf1d7014_001d702c\n"
        "movl %ebx, (%esp)\n" /* line 775 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x84(%ebp)\n" /* weapDef */
        "movl (%esi), %edx\n" /* line 777 */
        "testl %edx, %edx\n"
        "je .Lf1d7014_001d702c\n"
        "movl 0xc(%eax), %eax\n" /* line 780 */
        "cmpb $0, (%eax)\n"
        "je .Lf1d7014_001d702c\n"
        "movl %edx, (%esp)\n" /* line 783 */
        "calll DObjGetTree\n"
        "movl %eax, -0x80(%ebp)\n" /* pAnimTree */
        "leal 0x400(%ebx), %eax\n"
        "movl %eax, -0x7c(%ebp)\n" /* dobjHandle */
        "movl %eax, (%esp)\n" /* line 787 */
        "calll Com_SafeClientDObjFree\n"
        "movl $0, -0x2c(%ebp)\n" /* line 789 */
        "movl $0, -0x28(%ebp)\n" /* line 790 */
        "movl $str_002b6e38, -0x20(%ebp)\n" /* line 791 */
        "movl $0, -0x1c(%ebp)\n" /* line 792 */
        "movl 8(%ebp), %edx\n" /* line 795 | handModel */
        "movl %edx, (%esp)\n"
        "calll CL_RegisterModel\n"
        "movl %eax, -0x30(%ebp)\n" /* dobjModels */
        "movl -0x84(%ebp), %ecx\n" /* line 798 | weapDef */
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b7b28, 8(%esp)\n" /* "xmodel/" */
        "movl $str_00215f50, 4(%esp)\n" /* "%s%s" */
        "leal -0x70(%ebp), %eax\n" /* modelFile */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "leal -0x70(%ebp), %edx\n" /* line 799 | modelFile */
        "movl %edx, (%esp)\n"
        "calll CL_RegisterModel\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 801 | dobjModels */
        "movl %eax, (%esp)\n"
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "je .Lf1d7014_001d719a\n"
        ".Lf1d7014_001d7116:\n"
        "leal -0x30(%ebp), %ecx\n" /* line 802 | dobjModels */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CG_Weapons_SetToDefault\n"
        ".Lf1d7014_001d7125:\n"
        "movl -0x7c(%ebp), %eax\n" /* line 805 | dobjHandle */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x80(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x30(%ebp), %ecx\n" /* dobjModels */
        "movl %ecx, (%esp)\n"
        "calll Com_ClientDObjCreate\n"
        "movl $0, 4(%esp)\n" /* line 806 */
        "movl -0x7c(%ebp), %eax\n" /* dobjHandle */
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, (%esi)\n"
        "movl $0x40, 8(%esp)\n" /* line 808 */
        "movl 8(%ebp), %edx\n" /* handModel */
        "movl %edx, 4(%esp)\n"
        "movl -0x88(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x3d4ccccd, 4(%esp)\n" /* line 810 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjUpdateClientInfo\n"
        "jmp .Lf1d7014_001d702c\n"
        /* } scope */
        /* } scope */
        ".Lf1d7014_001d718f:\n"
        "addl $0x8c, %esp\n" /* line 833 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: weapDef, pAnimTree, dobjModels, dobjHandle, ... */
        /* { scope 2 */
        ".Lf1d7014_001d719a:\n"
        "movl -0x24(%ebp), %eax\n" /* line 801 */
        "movl %eax, (%esp)\n"
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "je .Lf1d7014_001d7125\n"
        "jmp .Lf1d7014_001d7116\n"
    );
}

/* line 2316 */
__attribute__((naked))
void CG_SpawnTracer(vec_t *pstart, vec_t *pend)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2316 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* pstart */
        "movl 0xc(%ebp), %edx\n" /* pend */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 4(%eax), %xmm0\n" /* line 200 */
        "movss %xmm0, -0x30(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x34(%ebp)\n"
        "movss 4(%edx), %xmm1\n" /* line 200 */
        "movss 8(%edx), %xmm2\n" /* line 201 */
        "movss (%edx), %xmm0\n" /* line 248 */
        "subss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "subss -0x30(%ebp), %xmm1\n" /* line 249 */
        "movss %xmm1, -0x20(%ebp)\n"
        "subss -0x34(%ebp), %xmm2\n" /* line 250 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 2328 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x38(%ebp)\n" /* dist */
        "calll CG_AllocLocalEntity\n" /* line 2330 */
        "movl %eax, %esi\n" /* le */
        "movl $0, 8(%eax)\n" /* line 2331 */
        "movss -0x38(%ebp), %xmm0\n" /* line 2332 | dist */
        "movss %xmm0, 0x44(%eax)\n"
        "movl imp_cg, %eax\n" /* line 2333 */
        "movl (%eax), %ebx\n"
        "movl 0x25bb0(%ebx), %edi\n"
        "movl 0x25bac(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1d71b2_001d72db\n"
        "xorl %eax, %eax\n"
        ".Lf1d71b2_001d724d:\n"
        "movl %edi, %edx\n"
        "subl %eax, %edx\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 2334 | dist */
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "movss %xmm0, -0x38(%ebp)\n" /* dist */
        "movl imp_cg_tracerSpeed, %ecx\n"
        "movl (%ecx), %eax\n"
        "divss 8(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* le */
        "movl $2, 0x10(%esi)\n" /* line 2336 | le */
        "movl %edx, 0x14(%esi)\n" /* line 2337 | le */
        "leal 0x1c(%esi), %eax\n" /* line 2338 | le, to */
        /* { scope 2 */
        "movss -0x2c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x1c(%esi)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%eax)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "leal 0x28(%esi), %edx\n" /* line 2339 | le, result */
        "movl (%ecx), %eax\n"
        "movss 8(%eax), %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm1\n" /* dir */
        "movss %xmm1, 0x28(%esi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2341 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d71b2_001d72db:\n"
        "calll rand\n" /* line 2333 */
        "cltd\n"
        "idivl 0x25bac(%ebx)\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "jmp .Lf1d71b2_001d724d\n"
    );
}

/* line 2269 */
__attribute__((naked))
void CG_WhizbySound(vec_t *vStart, vec_t *vEnd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2269 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %ebx\n" /* vStart */
        "movl 0xc(%ebp), %eax\n" /* vEnd */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss (%ebx), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* vDelta */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 2284 | vDir */
        "movl %eax, 4(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* vDelta */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movss -0x20(%ebp), %xmm6\n" /* line 304 | vDir */
        "movss -0x1c(%ebp), %xmm3\n"
        "movss -0x18(%ebp), %xmm5\n"
        "movaps %xmm6, %xmm2\n"
        "mulss -0x14(%ebp), %xmm2\n" /* vDelta */
        "movaps %xmm3, %xmm0\n"
        "mulss -0x10(%ebp), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movl imp_cg, %eax\n" /* line 2287 */
        "movl (%eax), %eax\n"
        "movss 0x28588(%eax), %xmm1\n" /* line 304 */
        "subss (%ebx), %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "movss 0x2858c(%eax), %xmm0\n"
        "subss 4(%ebx), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x28590(%eax), %xmm0\n"
        "subss 8(%ebx), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss lit4_002ed78c, %xmm0\n" /* line 2291 | 64.0f */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1d72f6_001d73c8\n"
        "addss %xmm1, %xmm0\n" /* line 2295 */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf1d72f6_001d73ce\n"
        /* } scope */
        ".Lf1d72f6_001d73c8:\n"
        "addl $0x44, %esp\n" /* line 2308 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d72f6_001d73ce:\n"
        "movaps %xmm6, %xmm4\n" /* line 288 */
        "mulss %xmm1, %xmm4\n"
        "addss (%ebx), %xmm4\n"
        "movss %xmm4, -0x2c(%ebp)\n" /* vProjPos */
        "movaps %xmm3, %xmm2\n" /* line 289 */
        "mulss %xmm1, %xmm2\n"
        "addss 4(%ebx), %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "mulss %xmm5, %xmm1\n" /* line 290 */
        "addss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 248 */
        "subss 0x28588(%eax), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* vDelta */
        "subss 0x2858c(%eax), %xmm2\n" /* line 249 */
        "movss %xmm2, -0x10(%ebp)\n"
        "subss 0x28590(%eax), %xmm1\n" /* line 250 */
        "movss %xmm1, -0xc(%ebp)\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "ucomiss lit4_002eda70, %xmm0\n" /* 140.0f */
        "ja .Lf1d72f6_001d73c8\n"
        "movss lit4_002eda74, %xmm0\n" /* line 288 | -16.0f */
        "mulss %xmm0, %xmm6\n"
        "addss %xmm6, %xmm4\n"
        "movss %xmm4, -0x2c(%ebp)\n" /* vProjPos */
        "mulss %xmm0, %xmm3\n" /* line 289 */
        "addss -0x28(%ebp), %xmm3\n"
        "movss %xmm3, -0x28(%ebp)\n"
        "mulss %xmm0, %xmm5\n" /* line 290 */
        "addss -0x24(%ebp), %xmm5\n"
        "movss %xmm5, -0x24(%ebp)\n"
        "movl imp_cgs, %eax\n" /* line 2307 */
        "movl (%eax), %eax\n"
        "movl 0xc1ac(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* vProjPos */
        "movl %eax, 4(%esp)\n"
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        /* } scope */
        "addl $0x44, %esp\n" /* line 2308 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2582 */
__attribute__((naked))
void CG_BulletHitClientEvent(int sourceEntityNum, vec_t *position, int surfType, int event)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2582 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* position */
        "movl 0x14(%ebp), %eax\n" /* event */
        /* { scope 1 */
        "cmpl $0xb9, %eax\n" /* line 2592 */
        "je .Lf1d74a4_001d757a\n"
        "cmpl $0xb7, %eax\n" /* line 2594 */
        "je .Lf1d74a4_001d7590\n"
        "movl imp_cgs, %eax\n" /* line 2597 */
        "movl (%eax), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* surfType */
        "movl 0xbe00(%eax, %edx, 4), %eax\n"
        ".Lf1d74a4_001d74da:\n"
        "movl %eax, 8(%esp)\n" /* line 2598 */
        "movl %edi, 4(%esp)\n" /* position */
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "movl s_barrelTags, %eax\n" /* line 2600 */
        "movzwl (%eax), %ecx\n" /* flashTag */
        /* { scope 2: muzzle */
        /* { scope 3 */
        "movl imp_cg_tracerChance, %esi\n" /* line 2497 */
        "movl (%esi), %eax\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "jae .Lf1d74a4_001d7572\n"
        "leal -0x24(%ebp), %ebx\n" /* line 2500 | muzzle */
        "movl %ebx, %edx\n"
        "movl 8(%ebp), %eax\n" /* sourceEntityNum */
        "calll CG_CalcMuzzlePoint\n"
        "testl %eax, %eax\n"
        "je .Lf1d74a4_001d7572\n"
        "movl imp_cg, %eax\n" /* line 2503 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl $0xc00000, 0x18(%eax)\n"
        "je .Lf1d74a4_001d7537\n"
        "movl 8(%ebp), %edx\n" /* sourceEntityNum */
        "cmpl 0xd8(%eax), %edx\n"
        "je .Lf1d74a4_001d7566\n"
        ".Lf1d74a4_001d7537:\n"
        "calll rand\n" /* line 2506 */
        "movl %eax, %edx\n"
        "movl (%esi), %eax\n" /* line 2508 */
        "movss lit4_002eda78, %xmm1\n" /* 2147483648.0f */
        "mulss 8(%eax), %xmm1\n"
        "testl %edx, %edx\n"
        "js .Lf1d74a4_001d75a6\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1d74a4_001d7555:\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1d74a4_001d7566\n"
        "movl %edi, 4(%esp)\n" /* line 2509 */
        "movl %ebx, (%esp)\n"
        "calll CG_SpawnTracer\n"
        ".Lf1d74a4_001d7566:\n"
        "movl %edi, 4(%esp)\n" /* line 2516 */
        "movl %ebx, (%esp)\n"
        "calll CG_WhizbySound\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1d74a4_001d7572:\n"
        "addl $0x2c, %esp\n" /* line 2601 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d74a4_001d757a:\n"
        "movl imp_cgs, %eax\n" /* line 2593 */
        "movl (%eax), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* surfType */
        "movl 0xbda4(%eax, %edx, 4), %eax\n"
        "jmp .Lf1d74a4_001d74da\n"
        ".Lf1d74a4_001d7590:\n"
        "movl imp_cgs, %eax\n" /* line 2595 */
        "movl (%eax), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* surfType */
        "movl 0xbe5c(%eax, %edx, 4), %eax\n"
        "jmp .Lf1d74a4_001d74da\n"
        /* { scope 2: muzzle */
        /* { scope 3 */
        ".Lf1d74a4_001d75a6:\n"
        "movl %edx, %eax\n" /* line 2508 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1d74a4_001d7555\n"
    );
}

/* line 1353 */
__attribute__((naked))
void CG_AddPlayerWeapon(GfxEntity *parent, weapProjExposion_t (*ps)[8], centity_t *cent, qboolean bDrawGun)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1353 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movl 8(%ebp), %edi\n" /* parent */
        "movl 0xc(%ebp), %esi\n" /* ps */
        /* { scope 1: ent_axis */
        "movl imp_cg, %eax\n" /* line 1364 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1d75ba_001d75f4\n"
        "movl 0x10(%ebp), %ecx\n" /* cent */
        "movl 0xf0(%ecx), %eax\n"
        "cmpl 0xd8(%edx), %eax\n"
        "je .Lf1d75ba_001d7963\n"
        ".Lf1d75ba_001d75f4:\n"
        "movb $0, -0xf5(%ebp)\n"
        ".Lf1d75ba_001d75fb:\n"
        "testl %esi, %esi\n" /* line 1367 | ps */
        "je .Lf1d75ba_001d7935\n"
        "movl %esi, (%esp)\n" /* line 1373 | ps */
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, -0xf4(%ebp)\n" /* weaponNum */
        "movl $1, -0xec(%ebp)\n" /* bViewModel */
        ".Lf1d75ba_001d761b:\n"
        "movl -0xf4(%ebp), %eax\n" /* line 1377 | weaponNum */
        "testl %eax, %eax\n"
        "jle .Lf1d75ba_001d792a\n"
        "movl 0x10(%ebp), %eax\n" /* line 1381 | cent */
        "testl $0x300, 0xf8(%eax)\n"
        "jne .Lf1d75ba_001d792a\n"
        "movl -0xf4(%ebp), %edx\n" /* line 1384 | weaponNum */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0xfc(%ebp)\n"
        "movl imp_cg_weapons, %eax\n"
        "movl -0xfc(%ebp), %ecx\n"
        "addl (%eax), %ecx\n"
        "movl %ecx, -0xf0(%ebp)\n" /* weapInfo */
        "movl -0xec(%ebp), %eax\n" /* line 1388 | bViewModel */
        "testl %eax, %eax\n"
        "je .Lf1d75ba_001d7884\n"
        /* { scope 2: bolt */
        "movl 0x14(%ebp), %eax\n" /* line 1394 | bDrawGun */
        "testl %eax, %eax\n"
        "jne .Lf1d75ba_001d7a26\n"
        "leal 0x14(%edi), %ecx\n" /* parent */
        "movl %ecx, -0x100(%ebp)\n"
        ".Lf1d75ba_001d7689:\n"
        "movl imp_cg, %eax\n" /* line 1428 */
        "movl (%eax), %ebx\n" /* iBoneIdx */
        "leal 0x2c0bc(%ebx), %edx\n" /* iBoneIdx, to */
        /* { scope 3 */
        "movl 0x3c(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x2c0bc(%ebx)\n"
        "movl 0x40(%edi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0x44(%edi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x2c0c8(%ebx), %esi\n" /* line 1429 | iBoneIdx, pMtxArray */
        "movl %esi, 4(%esp)\n" /* pMtxArray */
        "movl -0x100(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "addl $0x2c0ec, %ebx\n" /* line 1430 | iBoneIdx */
        "movl %ebx, 4(%esp)\n" /* iBoneIdx */
        "movl %esi, (%esp)\n" /* pMtxArray */
        "calll AxisToAngles\n"
        "movl imp_scr_const, %eax\n" /* line 1435 */
        "movzwl 0x94(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xf0(%ebp), %edx\n" /* weapInfo */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetBoneIndex\n"
        "movl %eax, %ebx\n" /* iBoneIdx */
        "cmpl $-1, %eax\n" /* line 1436 */
        "jle .Lf1d75ba_001d7788\n"
        "movl -0xf0(%ebp), %ecx\n" /* line 1438 | weapInfo */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetRotTransArray\n"
        "movl %eax, %esi\n" /* pMtxArray */
        "testl %eax, %eax\n" /* line 1439 */
        "je .Lf1d75ba_001d7788\n"
        "movl 0x14(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x74(%ebp)\n" /* ent_axis */
        "leal -0x74(%ebp), %ecx\n" /* line 200 | ent_axis */
        "movl -0x100(%ebp), %edx\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x6c(%ebp)\n"
        "leal 0x20(%edi), %edx\n"
        /* { scope 3 */
        "movl 0x20(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x68(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x64(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x60(%ebp)\n"
        "leal 0x2c(%edi), %edx\n"
        /* } scope */
        /* { scope 3 */
        "movl 0x2c(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x58(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x54(%ebp)\n"
        /* } scope */
        "movl 0x3c(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 0x40(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x44(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x48(%ebp)\n"
        "movl $ejectBrassCasingOrigin, 8(%esp)\n" /* line 1449 */
        "movl %ecx, 4(%esp)\n"
        "shll $5, %ebx\n" /* iBoneIdx */
        "leal 0x10(%esi, %ebx), %eax\n" /* pMtxArray */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        ".Lf1d75ba_001d7788:\n"
        "movl imp_cg, %esi\n" /* line 1286 */
        "movl (%esi), %ebx\n" /* fx */
        "movl 0x2cd08(%ebx), %eax\n" /* fx */
        "testl %eax, %eax\n"
        "jle .Lf1d75ba_001d77a6\n"
        "subl 0x25bac(%ebx), %eax\n" /* line 1287 | fx */
        "movl %eax, 0x2cd08(%ebx)\n" /* fx */
        ".Lf1d75ba_001d77a6:\n"
        "testb $0x40, 0x25bd1(%ebx)\n" /* line 1289 | fx */
        "jne .Lf1d75ba_001d79a7\n"
        "movl 0x2cd00(%ebx), %eax\n" /* line 1316 | fx */
        "testl %eax, %eax\n"
        "js .Lf1d75ba_001d77fb\n"
        "addl 0x25bac(%ebx), %eax\n" /* line 1318 | fx */
        "movl %eax, 0x2cd00(%ebx)\n" /* fx */
        "movl imp_player_breath_hold_time, %eax\n" /* line 1322 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "cvttss2si %xmm0, %eax\n"
        "cmpl 0x2cd00(%ebx), %eax\n" /* fx */
        "jl .Lf1d75ba_001d7ba8\n"
        "movl 0x2cd08(%ebx), %edi\n" /* line 1326 | fx */
        "testl %edi, %edi\n"
        "jle .Lf1d75ba_001d7b70\n"
        ".Lf1d75ba_001d77fb:\n"
        "movl (%esi), %eax\n" /* line 1333 */
        "movl $0xffffffff, 0x2cd00(%eax)\n"
        "movl $0, 0x2cd04(%eax)\n" /* line 1334 */
        "pxor %xmm0, %xmm0\n" /* line 1335 */
        "movss %xmm0, 0x2cd0c(%eax)\n"
        ".Lf1d75ba_001d781d:\n"
        "movss 0x2cd0c(%eax), %xmm2\n" /* line 1338 */
        "ucomiss %xmm0, %xmm2\n" /* line 1264 */
        "je .Lf1d75ba_001d7b37\n"
        ".Lf1d75ba_001d782e:\n"
        "movl imp_cgs, %eax\n" /* line 1266 */
        "movl (%eax), %eax\n"
        "addl $0x7104, %eax\n"
        "movl $1, %edx\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "leal -0x44(%ebp), %ecx\n" /* bolt */
        ".Lf1d75ba_001d784a:\n"
        "movss 0x38(%eax), %xmm0\n" /* line 1273 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%ecx, %edx, 4)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $0xc, %edx\n" /* line 1272 */
        "jne .Lf1d75ba_001d784a\n"
        "movl $0, 8(%esp)\n" /* line 1275 */
        "movl %ecx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll SND_SetChannelVolumes\n"
        /* } scope */
        ".Lf1d75ba_001d7884:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1458 | cent */
        "cmpb $0, 0x1e2(%ecx)\n"
        "je .Lf1d75ba_001d792a\n"
        "cmpb $0, -0xf5(%ebp)\n"
        "jne .Lf1d75ba_001d7953\n"
        ".Lf1d75ba_001d78a1:\n"
        "movl 0x10(%ebp), %edi\n" /* line 1460 | cent, parent */
        "movb $0, 0x1e2(%edi)\n" /* parent */
        "movl 0x14(%ebp), %edx\n" /* line 1461 | bDrawGun */
        "testl %edx, %edx\n"
        "je .Lf1d75ba_001d792a\n"
        "movl -0xec(%ebp), %eax\n" /* line 1463 | bViewModel */
        "testl %eax, %eax\n"
        "je .Lf1d75ba_001d796f\n"
        "movl s_barrelTags, %eax\n" /* line 1464 */
        "movzwl (%eax), %ecx\n" /* flashTag */
        "movl imp_cg, %eax\n"
        "movl (%eax), %esi\n" /* origin */
        "addl $0x2c0bc, %esi\n" /* origin */
        "movl -0xf4(%ebp), %edx\n" /* line 313 | weaponNum */
        "addl $0x400, %edx\n"
        /* { scope 2: bolt */
        /* { scope 3 */
        "movl imp_cg_weapons, %eax\n" /* line 1230 */
        "movl (%eax), %eax\n"
        "movl -0xfc(%ebp), %edi\n"
        "movl 0xc0(%edi, %eax), %ebx\n" /* fx */
        "testl %ebx, %ebx\n" /* line 1231 | fx */
        "je .Lf1d75ba_001d792a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bolt */
        /* { scope 3 */
        ".Lf1d75ba_001d78f9:\n"
        "movl %edx, -0x44(%ebp)\n" /* line 1234 | bolt */
        "movl %ecx, 4(%esp)\n" /* line 1235 */
        "movl %edx, (%esp)\n"
        "calll FX_GetBoneIndex\n"
        "movl %eax, -0x40(%ebp)\n"
        "testl %eax, %eax\n" /* line 1236 */
        "js .Lf1d75ba_001d792a\n"
        "leal -0x44(%ebp), %eax\n" /* line 1239 | bolt */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* fx */
        "calll FX_PlayEntityEffect\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1d75ba_001d792a:\n"
        "addl $0x11c, %esp\n" /* line 1469 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ent_axis */
        ".Lf1d75ba_001d7935:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1375 | cent */
        "movl 0x1b8(%eax), %eax\n"
        "movl %eax, -0xf4(%ebp)\n" /* weaponNum */
        "movl $0, -0xec(%ebp)\n" /* bViewModel */
        "jmp .Lf1d75ba_001d761b\n"
        ".Lf1d75ba_001d7953:\n"
        "movl -0xec(%ebp), %ecx\n" /* line 1458 | bViewModel */
        "testl %ecx, %ecx\n"
        "jne .Lf1d75ba_001d78a1\n"
        "jmp .Lf1d75ba_001d792a\n"
        ".Lf1d75ba_001d7963:\n"
        "movb $1, -0xf5(%ebp)\n" /* line 1364 */
        "jmp .Lf1d75ba_001d75fb\n"
        ".Lf1d75ba_001d796f:\n"
        "movl s_barrelTags, %eax\n" /* line 1466 */
        "movzwl (%eax), %ecx\n" /* flashTag */
        "movl 0x10(%ebp), %esi\n" /* cent, origin */
        "addl $0x1ec, %esi\n" /* origin */
        "movl 0x10(%ebp), %eax\n" /* cent */
        "movl 0xf0(%eax), %edx\n" /* dobjHandle */
        /* { scope 2: bolt */
        /* { scope 3 */
        "movl imp_cg_weapons, %eax\n" /* line 1230 */
        "movl (%eax), %eax\n"
        "movl -0xfc(%ebp), %edi\n"
        "movl 0xc4(%edi, %eax), %ebx\n" /* fx */
        "testl %ebx, %ebx\n" /* line 1231 | fx */
        "jne .Lf1d75ba_001d78f9\n"
        "jmp .Lf1d75ba_001d792a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: bolt */
        ".Lf1d75ba_001d79a7:\n"
        "cvtsi2ssl 0x25bac(%ebx), %xmm0\n" /* line 1291 | fx */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl imp_player_breath_snd_lerp, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x2cd0c(%ebx), %eax\n" /* fx */
        "movl %eax, 4(%esp)\n"
        "movl $0x3f800000, (%esp)\n"
        "calll DiffTrack\n"
        "fstps 0x2cd0c(%ebx)\n" /* fx */
        "movl 0x2cd00(%ebx), %eax\n" /* line 1293 | fx */
        "testl %eax, %eax\n"
        "js .Lf1d75ba_001d7bc2\n"
        "cmpl 0x2cd04(%ebx), %eax\n" /* line 1307 | fx */
        "jg .Lf1d75ba_001d7b56\n"
        ".Lf1d75ba_001d7a01:\n"
        "movl imp_cg, %esi\n" /* line 1312 */
        "movl (%esi), %edx\n"
        "movl 0x2cd00(%edx), %eax\n"
        "addl 0x25bac(%edx), %eax\n"
        "movl %eax, 0x2cd00(%edx)\n"
        "pxor %xmm0, %xmm0\n"
        "movl %edx, %eax\n"
        "jmp .Lf1d75ba_001d781d\n"
        ".Lf1d75ba_001d7a26:\n"
        "leal -0xe8(%ebp), %ebx\n" /* line 1397 | gun, iBoneIdx */
        "movl $0x74, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iBoneIdx */
        "calll memset\n"
        "movb $0xff, -0x90(%ebp)\n" /* line 1402 */
        "movb $0xff, -0x8f(%ebp)\n" /* line 1403 */
        "movb $0xff, -0x8e(%ebp)\n" /* line 1404 */
        "movb $0xff, -0x8d(%ebp)\n" /* line 1405 */
        "movl $0, -0xe8(%ebp)\n" /* line 1408 | gun */
        "movl $0x8c, -0xe4(%ebp)\n" /* line 1409 */
        "leal 0x14(%esi), %edx\n" /* pMtxArray */
        /* { scope 3 */
        "movl 0x14(%esi), %eax\n" /* line 199 */
        "movl %eax, -0xe0(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xdc(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 201 */
        /* } scope */
        "addss 0xf8(%esi), %xmm0\n" /* line 1413 | pMtxArray */
        "movss %xmm0, -0xd8(%ebp)\n"
        "movl $0x41a00000, 0x10(%esp)\n" /* line 1414 */
        "movl $0x41800000, 0xc(%esp)\n"
        "movl 0x4c(%esi), %eax\n" /* pMtxArray */
        "movl %eax, 8(%esp)\n"
        "movl 0xec(%esi), %eax\n" /* pMtxArray */
        "movl %eax, 4(%esp)\n"
        "leal -0xe0(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddLeanToPosition\n"
        "leal 0x3c(%edi), %edx\n" /* parent */
        /* { scope 3 */
        "movl 0x3c(%edi), %eax\n" /* line 199 */
        "movl %eax, -0xac(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xa8(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xa4(%ebp)\n"
        /* } scope */
        "leal -0xd4(%ebp), %eax\n" /* line 1417 */
        "movl %eax, 4(%esp)\n"
        "leal 0x14(%edi), %eax\n" /* parent */
        "movl %eax, -0x100(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "movl -0xf0(%ebp), %edx\n" /* line 1420 | weapInfo */
        "movl (%edx), %eax\n"
        "movl $0, 8(%esp)\n" /* line 1421 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* iBoneIdx */
        "calll R_AddRefEntityToScene\n"
        "testl %eax, %eax\n" /* line 1423 */
        "je .Lf1d75ba_001d7689\n"
        "movl %eax, (%esp)\n" /* line 1424 */
        "calll R_SkinGfxEntityDelayed\n"
        "jmp .Lf1d75ba_001d7689\n"
        ".Lf1d75ba_001d7b37:\n"
        "jp .Lf1d75ba_001d782e\n" /* line 1264 */
        "movl $0, 4(%esp)\n" /* line 1266 */
        "movl $1, (%esp)\n"
        "calll SND_DeactivateChannelVolumes\n"
        "jmp .Lf1d75ba_001d7884\n"
        ".Lf1d75ba_001d7b56:\n"
        "movl imp_cgs, %eax\n" /* line 1309 */
        "movl (%eax), %eax\n"
        "movl 0xc1c0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_PlayClientSoundAlias\n"
        "jmp .Lf1d75ba_001d7a01\n"
        ".Lf1d75ba_001d7b70:\n"
        "movl imp_cgs, %eax\n" /* line 1328 */
        "movl (%eax), %eax\n"
        "movl 0xc1c8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_PlayClientSoundAlias\n"
        "movl imp_player_breath_snd_delay, %eax\n" /* line 1329 */
        "movl (%eax), %eax\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "mulss 8(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x2cd08(%ebx)\n" /* fx */
        "jmp .Lf1d75ba_001d77fb\n"
        ".Lf1d75ba_001d7ba8:\n"
        "movl imp_cgs, %eax\n" /* line 1324 */
        "movl (%eax), %eax\n"
        "movl 0xc1cc(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_PlayClientSoundAlias\n"
        "jmp .Lf1d75ba_001d77fb\n"
        ".Lf1d75ba_001d7bc2:\n"
        "movl $0, 0x2cd00(%ebx)\n" /* line 1295 | fx */
        "movl 0x2cd08(%ebx), %eax\n" /* line 1297 | fx */
        "testl %eax, %eax\n"
        "jle .Lf1d75ba_001d7be5\n"
        "movl $0, 0x2cd04(%ebx)\n" /* line 1304 | fx */
        "jmp .Lf1d75ba_001d7a01\n"
        ".Lf1d75ba_001d7be5:\n"
        "movl imp_cgs, %eax\n" /* line 1299 */
        "movl (%eax), %eax\n"
        "movl 0xc1c4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_PlayClientSoundAlias\n"
        "movl %eax, 0x2cd04(%ebx)\n" /* fx */
        "movl imp_player_breath_snd_delay, %eax\n" /* line 1300 */
        "movl (%eax), %eax\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "mulss 8(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x2cd08(%ebx)\n" /* fx */
        "jmp .Lf1d75ba_001d7a01\n"
    );
}

/* line 1518 */
__attribute__((naked))
void CG_AddViewWeapon(weapProjExposion_t (*ps)[8])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1518 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1ec, %esp\n"
        /* { scope 1: tempAngles, right */
        "movl 8(%ebp), %edx\n" /* line 1531 | ps */
        "movl 4(%edx), %eax\n"
        "cmpl $4, %eax\n"
        "je .Lf1d7c24_001d7c8f\n"
        "cmpl $5, %eax\n" /* line 1534 */
        "je .Lf1d7c24_001d7c8f\n"
        "movl imp_cg, %ebx\n" /* line 1538 | weapDef */
        "movl (%ebx), %eax\n" /* weapDef */
        "movl 0x25bc0(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1d7c24_001d7c8f\n"
        "movl 0xc(%eax), %edx\n" /* line 1543 */
        "testl %edx, %edx\n"
        "jne .Lf1d7c24_001d7c6a\n"
        "movl imp_cg_drawGun, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1d7c24_001d86b1\n"
        ".Lf1d7c24_001d7c6a:\n"
        "movl $0, -0x188(%ebp)\n" /* drawgun */
        ".Lf1d7c24_001d7c74:\n"
        "movl (%ebx), %ebx\n" /* line 1547 | weapDef */
        "movl 0x2bfd8(%ebx), %eax\n" /* weapDef */
        "testl %eax, %eax\n"
        "jne .Lf1d7c24_001d7c8f\n"
        "movl 8(%ebp), %ecx\n" /* line 1550 | ps */
        "testl $0x300, 0xa0(%ecx)\n"
        "je .Lf1d7c24_001d7c9a\n"
        /* } scope */
        ".Lf1d7c24_001d7c8f:\n"
        "addl $0x1ec, %esp\n" /* line 1626 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tempAngles, right */
        ".Lf1d7c24_001d7c9a:\n"
        "movl %ecx, (%esp)\n" /* line 1553 */
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, -0x184(%ebp)\n" /* weaponIndex */
        "testl %eax, %eax\n" /* line 1555 */
        "jle .Lf1d7c24_001d86d3\n"
        "leal 0x25bc4(%ebx), %esi\n" /* line 937 */
        "movl %esi, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n" /* line 938 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ecx\n"
        "movl 0x2ccdc(%ebx), %edx\n" /* line 941 */
        "addl 0x2cce0(%ebx), %edx\n"
        "subl 0x25bb0(%ebx), %edx\n"
        "testl %edx, %edx\n" /* line 943 */
        "jle .Lf1d7c24_001d897e\n"
        "movl 0x2ccd8(%ebx), %eax\n" /* line 948 */
        "movl (%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lf1d7c24_001d8704\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm3, %xmm2\n"
        "movss lit4_002ed628, %xmm0\n" /* -2.0f */
        ".Lf1d7c24_001d7d05:\n"
        "movaps %xmm0, %xmm1\n" /* line 952 */
        "addss lit4_002ed720, %xmm1\n" /* 3.0f */
        "mulss %xmm2, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movss 0x300(%ecx), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm3, %xmm1\n"
        ".Lf1d7c24_001d7d2c:\n"
        "movl 0x25bac(%ebx), %eax\n" /* line 959 */
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "leal 0x285e0(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x285ec(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x285d4(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll BG_CalculateWeaponPosition_Sway\n"
        "movl imp_cg, %eax\n" /* line 1203 */
        "movl (%eax), %ebx\n"
        "leal 0x25bc4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n" /* line 1205 */
        "calll BG_IsAimDownSightWeapon\n"
        "testl %eax, %eax\n"
        "je .Lf1d7c24_001d7dba\n"
        "leal 0x28490(%ebx), %edx\n" /* line 1208 */
        "movss 0x25ca0(%ebx), %xmm0\n" /* line 1211 */
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jne .Lf1d7c24_001d8940\n"
        "jp .Lf1d7c24_001d8940\n"
        "movl $0, 4(%edx)\n" /* line 1212 */
        ".Lf1d7c24_001d7dab:\n"
        "movl imp_cg, %eax\n" /* line 1216 */
        "movl (%eax), %eax\n"
        "movl 0x25ca0(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        ".Lf1d7c24_001d7dba:\n"
        "movl $0x74, 8(%esp)\n" /* line 1560 */
        "movl $0, 4(%esp)\n"
        "leal -0x174(%ebp), %eax\n" /* hand */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* { scope 2: weapDef, targetPos */
        "pxor %xmm0, %xmm0\n" /* line 183 */
        "movss %xmm0, -0x138(%ebp)\n"
        "movss %xmm0, -0x134(%ebp)\n" /* line 184 */
        "movss %xmm0, -0x130(%ebp)\n" /* line 185 */
        "movl imp_cg, %ebx\n" /* line 1165 */
        "movl (%ebx), %esi\n"
        "ucomiss 0x25c10(%esi), %xmm0\n"
        "jp .Lf1d7c24_001d7e0b\n"
        "je .Lf1d7c24_001d87b0\n"
        ".Lf1d7c24_001d7e0b:\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 1167 | 1.0f */
        "ucomiss 0x25ca0(%esi), %xmm1\n"
        "ja .Lf1d7c24_001d8a46\n"
        "movl (%ebx), %ebx\n"
        /* { scope 3 */
        ".Lf1d7c24_001d7e22:\n"
        "leal 0x25bc4(%ebx), %eax\n" /* line 986 */
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n" /* line 987 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x17c(%ebp)\n" /* weapDef */
        "movl 0x28364(%ebx), %edx\n" /* line 989 */
        "movl %edx, %eax\n"
        "shrl $3, %eax\n"
        "movl %eax, %ecx\n"
        "andb $1, %cl\n"
        "movl %ecx, %esi\n"
        "je .Lf1d7c24_001d87b7\n"
        "movl imp_cg_gun_move_minspeed, %eax\n" /* line 990 */
        "movl (%eax), %eax\n"
        "movl -0x17c(%ebp), %ecx\n" /* weapDef */
        "movss 0x19c(%ecx), %xmm1\n"
        "addss 8(%eax), %xmm1\n"
        ".Lf1d7c24_001d7e70:\n"
        "movl imp_cg, %ebx\n" /* line 998 */
        "movl (%ebx), %ecx\n"
        "movss 0x2bf1c(%ecx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1d7c24_001d8798\n"
        "cmpl $5, 0x25c9c(%ecx)\n"
        "je .Lf1d7c24_001d8798\n"
        "movaps %xmm0, %xmm2\n" /* line 1000 */
        "subss %xmm1, %xmm2\n"
        "cvtsi2ssl 0x25c14(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "pxor %xmm6, %xmm6\n" /* line 45 */
        "movaps %xmm6, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm6\n"
        "ja .Lf1d7c24_001d8a36\n"
        "movaps %xmm6, %xmm2\n"
        "movss lit4_002ed5dc, %xmm1\n" /* -1.0f */
        ".Lf1d7c24_001d7ecc:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm2, %xmm3\n"
        "cmpltss %xmm6, %xmm1\n"
        "andps %xmm1, %xmm3\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "movl %esi, %eax\n" /* line 1003 */
        "testb %al, %al\n"
        "je .Lf1d7c24_001d89ae\n"
        "movl -0x17c(%ebp), %eax\n" /* weapDef */
        "addl $0x174, %eax\n"
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "movl -0x17c(%ebp), %edx\n" /* weapDef */
        "mulss 0x174(%edx), %xmm0\n"
        /* } scope */
        /* { scope 4 */
        ".Lf1d7c24_001d7f0e:\n"
        "movss %xmm0, -0x64(%ebp)\n" /* targetPos */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movaps %xmm2, %xmm0\n" /* line 274 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        /* } scope */
        "movl imp_cg_gun_move_f, %eax\n" /* line 1011 */
        "movl (%eax), %eax\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss -0x64(%ebp), %xmm0\n" /* targetPos */
        "movss %xmm0, -0x64(%ebp)\n" /* targetPos */
        "movl imp_cg_gun_move_r, %eax\n" /* line 1012 */
        "movl (%eax), %eax\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movl imp_cg_gun_move_u, %eax\n" /* line 1013 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm2\n"
        "addss -0x5c(%ebp), %xmm2\n"
        "movss %xmm2, -0x5c(%ebp)\n"
        ".Lf1d7c24_001d7f75:\n"
        "movl 0x25cb8(%ecx), %eax\n" /* line 1018 */
        "cmpl $0x28, %eax\n"
        "je .Lf1d7c24_001d8861\n"
        "cmpl $0xb, %eax\n" /* line 1025 */
        "je .Lf1d7c24_001d898b\n"
        ".Lf1d7c24_001d7f8d:\n"
        "leal 0x28490(%ecx), %edi\n" /* line 1033 | pe */
        "movl %edi, %edx\n" /* pe */
        "movl $1, %ecx\n"
        "movss lit4_002ed658, %xmm7\n" /* 0.0010000000474974513f */
        ".Lf1d7c24_001d7fa2:\n"
        "leal 0x18(%edx), %esi\n" /* line 1518 */
        "movss 0x18(%edx), %xmm3\n" /* line 1037 */
        "movss -0x68(%ebp, %ecx, 4), %xmm2\n"
        "ucomiss %xmm2, %xmm3\n"
        "jp .Lf1d7c24_001d7fbb\n"
        "je .Lf1d7c24_001d804c\n"
        ".Lf1d7c24_001d7fbb:\n"
        "movl (%ebx), %eax\n" /* line 1039 */
        "movss 0x25cbc(%eax), %xmm0\n"
        "ucomiss lit4_002ed7bc, %xmm0\n" /* 11.0f */
        "jne .Lf1d7c24_001d874c\n"
        "jp .Lf1d7c24_001d874c\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm4\n" /* line 1040 */
        "movaps %xmm7, %xmm5\n"
        "movaps %xmm4, %xmm1\n"
        "mulss %xmm7, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movl imp_cg_gun_move_rate, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x1cc(%ebp)\n"
        "movl -0x17c(%ebp), %eax\n" /* weapDef */
        "movss 0x190(%eax), %xmm0\n"
        "movl -0x1cc(%ebp), %eax\n"
        "addss 8(%eax), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        ".Lf1d7c24_001d801f:\n"
        "ucomiss %xmm3, %xmm2\n" /* line 1044 */
        "jbe .Lf1d7c24_001d8728\n"
        "movaps %xmm4, %xmm0\n" /* line 1046 */
        "mulss %xmm5, %xmm0\n"
        "mulss lit4_002ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "maxss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n" /* line 1049 */
        "movss %xmm0, (%esi)\n"
        "ucomiss %xmm2, %xmm0\n" /* line 1050 */
        "ja .Lf1d7c24_001d8743\n"
        ".Lf1d7c24_001d804c:\n"
        "addl $1, %ecx\n" /* line 1060 */
        "addl $4, %edx\n"
        "cmpl $4, %ecx\n" /* line 1035 */
        "jne .Lf1d7c24_001d7fa2\n"
        "movl (%ebx), %edx\n" /* line 1065 */
        "movss 0x25ca0(%edx), %xmm0\n"
        "ucomiss %xmm6, %xmm0\n"
        "jp .Lf1d7c24_001d8070\n"
        "je .Lf1d7c24_001d87df\n"
        ".Lf1d7c24_001d8070:\n"
        "ucomiss lit4_002ed5d8, %xmm0\n" /* line 1068 | 0.5f */
        "jp .Lf1d7c24_001d807f\n"
        "jb .Lf1d7c24_001d88da\n"
        ".Lf1d7c24_001d807f:\n"
        "movaps %xmm6, %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "movaps %xmm6, %xmm2\n"
        /* } scope */
        ".Lf1d7c24_001d8088:\n"
        "leal 0x28498(%edx), %eax\n" /* line 1093 | to */
        /* { scope 3 */
        "movss %xmm2, 0x28498(%edx)\n" /* line 199 */
        "movss %xmm1, 4(%eax)\n" /* line 200 */
        "movss %xmm0, 8(%eax)\n" /* line 201 */
        /* } scope */
        "addss -0x138(%ebp), %xmm2\n" /* line 240 */
        "movss %xmm2, -0x138(%ebp)\n"
        "addss -0x134(%ebp), %xmm1\n" /* line 241 */
        "movss %xmm1, -0x134(%ebp)\n"
        "movaps %xmm0, %xmm3\n" /* line 242 */
        "addss -0x130(%ebp), %xmm3\n"
        "movss %xmm3, -0x130(%ebp)\n"
        "movl (%ebx), %ebx\n" /* line 966 */
        "subss 0x285f0(%ebx), %xmm1\n"
        "movss %xmm1, -0x134(%ebp)\n"
        "addss 0x285f4(%ebx), %xmm3\n" /* line 967 */
        "movss %xmm3, -0x130(%ebp)\n"
        /* { scope 3 */
        "leal -0x4c(%ebp), %eax\n" /* line 1107 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x58(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x64(%ebp), %edx\n" /* targetPos */
        "movl %edx, 4(%esp)\n"
        "leal 0x2c0ec(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x198(%ebp)\n"
        "movss %xmm2, -0x1a8(%ebp)\n"
        "movss %xmm3, -0x1b8(%ebp)\n"
        "calll AngleVectors\n"
        "leal 0x2c0bc(%ebx), %edx\n"
        /* { scope 4 */
        "movl 0x2c0bc(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x138(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x134(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x130(%ebp)\n"
        /* } scope */
        "movss -0x1a8(%ebp), %xmm2\n" /* line 288 */
        "movaps %xmm2, %xmm0\n"
        "mulss -0x64(%ebp), %xmm0\n" /* targetPos */
        "addss -0x138(%ebp), %xmm0\n"
        "movss %xmm0, -0x138(%ebp)\n"
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss -0x60(%ebp), %xmm0\n"
        "addss -0x134(%ebp), %xmm0\n"
        "movss %xmm0, -0x134(%ebp)\n"
        "mulss -0x5c(%ebp), %xmm2\n" /* line 290 */
        "addss -0x130(%ebp), %xmm2\n"
        "movss -0x198(%ebp), %xmm1\n" /* line 1110 | scale */
        "xorps cg_perturbations+1056, %xmm1\n" /* scale */
        /* { scope 4 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x58(%ebp), %xmm0\n"
        "addss -0x138(%ebp), %xmm0\n"
        "movss %xmm0, -0x138(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x54(%ebp), %xmm0\n"
        "addss -0x134(%ebp), %xmm0\n"
        "movss %xmm0, -0x134(%ebp)\n"
        "mulss -0x50(%ebp), %xmm1\n" /* line 290 */
        "addss %xmm2, %xmm1\n"
        /* } scope */
        "movss -0x1b8(%ebp), %xmm3\n" /* line 288 */
        "movaps %xmm3, %xmm0\n"
        "mulss -0x4c(%ebp), %xmm0\n"
        "addss -0x138(%ebp), %xmm0\n"
        "movss %xmm0, -0x138(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 289 */
        "mulss -0x48(%ebp), %xmm0\n"
        "addss -0x134(%ebp), %xmm0\n"
        "movss %xmm0, -0x134(%ebp)\n"
        "mulss -0x44(%ebp), %xmm3\n" /* line 290 */
        "addss %xmm1, %xmm3\n"
        "movss %xmm3, -0x130(%ebp)\n"
        /* } scope */
        "movl 0x25bb0(%ebx), %edx\n" /* line 1188 */
        "subl 0x284dc(%ebx), %edx\n"
        "cmpl $0x95, %edx\n" /* line 1189 */
        "jg .Lf1d7c24_001d881d\n"
        "movss lit4_002ed604, %xmm0\n" /* line 1190 | 0.25f */
        "mulss 0x284d8(%ebx), %xmm0\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "divss lit4_002ed93c, %xmm0\n" /* 150.0f */
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x130(%ebp)\n"
        /* { scope 3 */
        ".Lf1d7c24_001d826e:\n"
        "movl imp_cg, %esi\n" /* line 1119 */
        "movl (%esi), %ebx\n"
        "leal 0x25bc4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n" /* line 1121 */
        "calll BG_IsAimDownSightWeapon\n"
        "testl %eax, %eax\n"
        "je .Lf1d7c24_001d8802\n"
        /* { scope 4 */
        "movss 0x25ca0(%ebx), %xmm1\n" /* line 1123 | fPosLerp */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 1126 | 0.0f */
        "jp .Lf1d7c24_001d82ab\n"
        "je .Lf1d7c24_001d8913\n"
        ".Lf1d7c24_001d82ab:\n"
        "movss -0x138(%ebp), %xmm0\n" /* line 1128 */
        "subss 0x28588(%ebx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c098(%ebx)\n"
        "movss -0x134(%ebp), %xmm0\n" /* line 1129 */
        "subss 0x2858c(%ebx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c09c(%ebx)\n"
        "movss -0x130(%ebp), %xmm0\n" /* line 1130 */
        "subss 0x28590(%ebx), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c0a0(%ebx)\n"
        "movl (%esi), %ebx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1d7c24_001d8301:\n"
        "movl imp_cg_gun_x, %eax\n" /* line 1565 | dir */
        "movl (%eax), %eax\n" /* dir */
        "movss 8(%eax), %xmm1\n" /* scale */
        "leal 0x2c0c8(%ebx), %eax\n" /* weapDef, dir */
        /* { scope 2: weapDef, targetPos */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x2c0c8(%ebx), %xmm0\n"
        "addss -0x138(%ebp), %xmm0\n"
        "movss %xmm0, -0x138(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x134(%ebp), %xmm0\n"
        "movss %xmm0, -0x134(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss -0x130(%ebp), %xmm1\n"
        "movss %xmm1, -0x130(%ebp)\n"
        /* } scope */
        "movl imp_cg_gun_y, %eax\n" /* line 1566 | dir */
        "movl (%eax), %eax\n" /* dir */
        "movss 8(%eax), %xmm1\n" /* scale */
        "leal 0x2c0d4(%ebx), %eax\n" /* weapDef, dir */
        /* { scope 2: weapDef, targetPos */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x2c0d4(%ebx), %xmm0\n"
        "addss -0x138(%ebp), %xmm0\n"
        "movss %xmm0, -0x138(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x134(%ebp), %xmm0\n"
        "movss %xmm0, -0x134(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss -0x130(%ebp), %xmm1\n"
        "movss %xmm1, -0x130(%ebp)\n"
        /* } scope */
        "movl imp_cg_gun_z, %eax\n" /* line 1567 | dir */
        "movl (%eax), %eax\n" /* dir */
        "movss 8(%eax), %xmm1\n" /* scale */
        "leal 0x2c0e0(%ebx), %eax\n" /* weapDef, dir */
        /* { scope 2: weapDef, targetPos */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x2c0e0(%ebx), %xmm0\n"
        "addss -0x138(%ebp), %xmm0\n"
        "movss %xmm0, -0x138(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x134(%ebp), %xmm0\n"
        "movss %xmm0, -0x134(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss -0x130(%ebp), %xmm1\n"
        "movss %xmm1, -0x130(%ebp)\n"
        /* } scope */
        "leal -0xac(%ebp), %ecx\n" /* line 1569 | vAxis2 */
        "movl %ecx, 4(%esp)\n"
        "leal 0x2c0ec(%ebx), %eax\n" /* weapDef */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x28490(%ebx), %eax\n" /* line 1571 | weapDef */
        "movl %eax, -0x180(%ebp)\n" /* pe */
        "movl 8(%ebp), %edx\n" /* line 1573 | ps */
        "movl %edx, -0x100(%ebp)\n" /* ws */
        "movl 0x2bf1c(%ebx), %eax\n" /* line 1574 | weapDef */
        "movl %eax, -0xfc(%ebp)\n"
        "cvtsi2ssl 0x25bac(%ebx), %xmm0\n" /* line 1575 | weapDef */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0xf8(%ebp)\n"
        "leal 0x284b4(%ebx), %edx\n" /* weapDef */
        /* { scope 2: weapDef, targetPos */
        "movl 0x284b4(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0xf4(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xf0(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xec(%ebp)\n"
        /* } scope */
        "movl -0x180(%ebp), %ecx\n" /* line 1577 | pe */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0xe8(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 1578 | ps */
        "movl 0x7a4(%eax), %edx\n"
        "movl 0x25bb0(%ebx), %eax\n" /* weapDef */
        "subl %edx, %eax\n"
        "movl %eax, -0xe4(%ebp)\n"
        "movl 0x2bed4(%ebx), %eax\n" /* line 1579 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf1d7c24_001d84b6\n"
        "subl %edx, %eax\n"
        ".Lf1d7c24_001d84b6:\n"
        "movl %eax, -0xe0(%ebp)\n"
        "movl imp_cg, %edx\n" /* line 1580 */
        "movl (%edx), %esi\n"
        "movl 0x2bf10(%esi), %eax\n"
        "movl %eax, -0xdc(%ebp)\n"
        "movl 0x2bf14(%esi), %eax\n" /* line 1581 */
        "movl %eax, -0xd8(%ebp)\n"
        "leal 0x2c0a4(%esi), %edx\n"
        /* { scope 2: weapDef, targetPos */
        "movl 0x2c0a4(%esi), %eax\n" /* line 199 */
        "movl %eax, -0xd4(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xd0(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xcc(%ebp)\n"
        "leal 0x2c0b0(%esi), %edx\n"
        /* } scope */
        /* { scope 2: weapDef, targetPos */
        "movl 0x2c0b0(%esi), %eax\n" /* line 199 */
        "movl %eax, -0xc8(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xc4(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xc0(%ebp)\n"
        "leal 0x285e0(%esi), %edx\n"
        /* } scope */
        /* { scope 2: weapDef, targetPos */
        "movl 0x285e0(%esi), %eax\n" /* line 199 */
        "movl %eax, -0xbc(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xb8(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xb4(%ebp)\n"
        /* } scope */
        "leal 0x2beec(%esi), %eax\n" /* line 1585 */
        "movl %eax, -0xb0(%ebp)\n"
        "leal -0x28(%ebp), %edi\n" /* line 1587 | angles, pe */
        "movl %edi, 4(%esp)\n" /* pe */
        "leal -0x100(%ebp), %eax\n" /* ws */
        "movl %eax, (%esp)\n"
        "calll BG_CalculateWeaponAngles\n"
        "leal -0x88(%ebp), %ebx\n" /* line 1590 | vAxis, weapDef */
        "movl %ebx, 4(%esp)\n" /* weapDef */
        "movl %edi, (%esp)\n" /* pe */
        "calll AnglesToAxis\n"
        "leal -0x160(%ebp), %ecx\n" /* line 1591 */
        "movl %ecx, 8(%esp)\n"
        "leal -0xac(%ebp), %eax\n" /* vAxis2 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* weapDef */
        "calll MatrixMultiply\n"
        "movl -0x184(%ebp), %edx\n" /* line 1593 | weaponIndex */
        "movl %edx, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ebx\n" /* weapDef */
        "movl 8(%ebp), %ecx\n" /* line 1594 | ps */
        "movl 0xd4(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_IsAimDownSightWeapon\n"
        "testl %eax, %eax\n"
        "je .Lf1d7c24_001d85dc\n"
        "pxor %xmm0, %xmm0\n"
        "movl 8(%ebp), %eax\n" /* ps */
        "ucomiss 0xdc(%eax), %xmm0\n"
        "jp .Lf1d7c24_001d85ce\n"
        "je .Lf1d7c24_001d85dc\n"
        ".Lf1d7c24_001d85ce:\n"
        "movl 0x278(%ebx), %eax\n" /* weapDef */
        "testl %eax, %eax\n"
        "je .Lf1d7c24_001d89f5\n"
        ".Lf1d7c24_001d85dc:\n"
        "movl imp_cg, %ebx\n" /* line 1596 | weapDef */
        "movl (%ebx), %eax\n" /* weapDef */
        "movl 0x285c8(%eax), %edx\n"
        "movl %edx, 0x2c090(%eax)\n"
        "movl 0x285cc(%eax), %edx\n" /* line 1597 */
        "movl %edx, 0x2c094(%eax)\n"
        "movl %eax, %edx\n"
        ".Lf1d7c24_001d85fe:\n"
        "leal 0x284b4(%edx), %ecx\n" /* line 1607 | to */
        /* { scope 2: weapDef, targetPos */
        "movl -0xf4(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x284b4(%edx)\n"
        "movl -0xf0(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0xec(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl -0xe8(%ebp), %eax\n" /* line 1608 */
        "movl -0x180(%ebp), %ecx\n" /* pe */
        "movl %eax, 0x14(%ecx)\n"
        "leal 0x2c0a4(%edx), %ecx\n" /* line 1609 | to */
        /* { scope 2: weapDef, targetPos */
        "movl -0xd4(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x2c0a4(%edx)\n"
        "movl -0xd0(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0xcc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x2c0b0(%edx), %ecx\n" /* line 1610 | to */
        /* { scope 2: weapDef, targetPos */
        "movl -0xc8(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x2c0b0(%edx)\n"
        "movl -0xc4(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0xc0(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0xc, -0x170(%ebp)\n" /* line 1612 */
        "movl -0x188(%ebp), %eax\n" /* line 1615 | drawgun */
        "movl %eax, 0xc(%esp)\n"
        "addl $0x2826c, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "movl %edx, 4(%esp)\n"
        "leal -0x174(%ebp), %ecx\n" /* hand */
        "movl %ecx, (%esp)\n"
        "calll CG_AddPlayerWeapon\n"
        "jmp .Lf1d7c24_001d7c8f\n"
        ".Lf1d7c24_001d86b1:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1543 | fZoom */
        "movl %eax, (%esp)\n"
        "calll CG_GetWeapReticleZoom\n"
        "testb %al, %al\n"
        "jne .Lf1d7c24_001d7c6a\n"
        "movl $1, -0x188(%ebp)\n" /* drawgun */
        "jmp .Lf1d7c24_001d7c74\n"
        ".Lf1d7c24_001d86d3:\n"
        "movl 0x285c8(%ebx), %eax\n" /* line 1619 | weapDef */
        "movl %eax, 0x2c090(%ebx)\n" /* weapDef */
        "movl 0x285cc(%ebx), %eax\n" /* line 1620 | weapDef */
        "movl %eax, 0x2c094(%ebx)\n" /* weapDef */
        "xorl %eax, %eax\n" /* line 1622 */
        "movl %eax, 0x2c098(%ebx)\n" /* weapDef */
        "movl %eax, 0x2c09c(%ebx)\n" /* line 1623 | weapDef */
        "movl %eax, 0x2c0a0(%ebx)\n" /* line 1624 | weapDef */
        "jmp .Lf1d7c24_001d7c8f\n"
        ".Lf1d7c24_001d8704:\n"
        "cvtsi2ssl %edx, %xmm2\n" /* line 949 */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "mulss lit4_002ed628, %xmm0\n" /* -2.0f */
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "jmp .Lf1d7c24_001d7d05\n"
        /* { scope 2: weapDef, targetPos */
        /* { scope 3 */
        ".Lf1d7c24_001d8728:\n"
        "movaps %xmm4, %xmm0\n" /* line 1055 */
        "mulss %xmm5, %xmm0\n"
        "mulss lit4_002ed7d4, %xmm0\n" /* -0.10000000149011612f */
        "minss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n" /* line 1058 */
        "maxss %xmm0, %xmm2\n" /* line 1060 */
        ".Lf1d7c24_001d8743:\n"
        "movss %xmm2, (%esi)\n"
        "jmp .Lf1d7c24_001d804c\n"
        ".Lf1d7c24_001d874c:\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm4\n" /* line 1042 */
        "movaps %xmm7, %xmm5\n"
        "movaps %xmm4, %xmm1\n"
        "mulss %xmm7, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movl imp_cg_gun_move_rate, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x1d0(%ebp)\n"
        "movl -0x17c(%ebp), %eax\n" /* weapDef */
        "movss 0x18c(%eax), %xmm0\n"
        "movl -0x1d0(%ebp), %eax\n"
        "addss 8(%eax), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "jmp .Lf1d7c24_001d801f\n"
        ".Lf1d7c24_001d8798:\n"
        "pxor %xmm6, %xmm6\n" /* line 183 */
        "movss %xmm6, -0x64(%ebp)\n" /* targetPos */
        "movss %xmm6, -0x60(%ebp)\n" /* line 184 */
        "movss %xmm6, -0x5c(%ebp)\n" /* line 185 */
        "jmp .Lf1d7c24_001d7f75\n"
        ".Lf1d7c24_001d87b0:\n"
        "movl %esi, %ebx\n"
        "jmp .Lf1d7c24_001d7e22\n"
        ".Lf1d7c24_001d87b7:\n"
        "testb $4, %dl\n" /* line 991 */
        "je .Lf1d7c24_001d895f\n"
        "movl imp_cg_gun_move_minspeed, %eax\n" /* line 992 */
        "movl (%eax), %eax\n"
        "movl -0x17c(%ebp), %ecx\n" /* weapDef */
        "movss 0x198(%ecx), %xmm1\n"
        "addss 8(%eax), %xmm1\n"
        "jmp .Lf1d7c24_001d7e70\n"
        /* { scope 4 */
        ".Lf1d7c24_001d87df:\n"
        "leal 0x18(%edi), %eax\n" /* line 290 */
        /* } scope */
        /* { scope 4 */
        "movss 0x18(%edi), %xmm2\n" /* line 240 */
        "addss %xmm6, %xmm2\n"
        "movss 4(%eax), %xmm1\n" /* line 241 */
        "addss %xmm6, %xmm1\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "addss %xmm6, %xmm0\n"
        "jmp .Lf1d7c24_001d8088\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf1d7c24_001d8802:\n"
        "xorl %eax, %eax\n" /* line 1141 */
        "movl %eax, 0x2c098(%ebx)\n"
        "movl %eax, 0x2c09c(%ebx)\n" /* line 1142 */
        "movl %eax, 0x2c0a0(%ebx)\n" /* line 1143 */
        "movl (%esi), %ebx\n"
        "jmp .Lf1d7c24_001d8301\n"
        /* } scope */
        ".Lf1d7c24_001d881d:\n"
        "cmpl $0x1c1, %edx\n" /* line 1191 */
        "jg .Lf1d7c24_001d826e\n"
        "movss lit4_002ed604, %xmm0\n" /* line 1192 | 0.25f */
        "mulss 0x284d8(%ebx), %xmm0\n"
        "movl $0x1c2, %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "divss lit4_002eda80, %xmm0\n" /* 300.0f */
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x130(%ebp)\n"
        "jmp .Lf1d7c24_001d826e\n"
        /* { scope 3 */
        ".Lf1d7c24_001d8861:\n"
        "movl -0x17c(%ebp), %eax\n" /* line 1018 | weapDef */
        "addl $0x144, %eax\n"
        /* { scope 4 */
        "movss -0x64(%ebp), %xmm0\n" /* line 240 | targetPos */
        "movl -0x17c(%ebp), %edx\n" /* weapDef */
        "addss 0x144(%edx), %xmm0\n"
        /* } scope */
        /* { scope 4 */
        ".Lf1d7c24_001d887f:\n"
        "movss %xmm0, -0x64(%ebp)\n" /* targetPos */
        "movss -0x60(%ebp), %xmm1\n" /* line 241 */
        "addss 4(%eax), %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n"
        "movss -0x5c(%ebp), %xmm2\n" /* line 242 */
        "addss 8(%eax), %xmm2\n"
        "movss %xmm2, -0x5c(%ebp)\n"
        /* } scope */
        "movl imp_cg_gun_ofs_f, %eax\n" /* line 1028 */
        "movl (%eax), %eax\n"
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n" /* targetPos */
        "movl imp_cg_gun_ofs_r, %eax\n" /* line 1029 */
        "movl (%eax), %eax\n"
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n"
        "movl imp_cg_gun_ofs_u, %eax\n" /* line 1030 */
        "movl (%eax), %eax\n"
        "addss 8(%eax), %xmm2\n"
        "movss %xmm2, -0x5c(%ebp)\n"
        "jmp .Lf1d7c24_001d7f8d\n"
        ".Lf1d7c24_001d88da:\n"
        "mulss lit4_002ed628, %xmm0\n" /* line 1070 | -2.0f */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "leal 0x18(%edi), %eax\n" /* pe */
        /* { scope 4 */
        "movaps %xmm0, %xmm2\n" /* line 288 */
        "mulss 0x18(%edi), %xmm2\n"
        "addss %xmm6, %xmm2\n"
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm6, %xmm1\n"
        "mulss 8(%eax), %xmm0\n" /* line 290 */
        "addss %xmm6, %xmm0\n"
        "jmp .Lf1d7c24_001d8088\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1d7c24_001d8913:\n"
        "movl $0, 0x2c098(%ebx)\n" /* line 1134 */
        "movl imp_cg, %ebx\n" /* line 1135 */
        "movl (%ebx), %eax\n"
        "movl $0, 0x2c09c(%eax)\n"
        "movl $0, 0x2c0a0(%eax)\n" /* line 1136 */
        "movl %eax, %ebx\n"
        "jmp .Lf1d7c24_001d8301\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1d7c24_001d8940:\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 1213 | 0.0f */
        "jne .Lf1d7c24_001d7dab\n"
        "jp .Lf1d7c24_001d7dab\n"
        "movl $1, 4(%edx)\n" /* line 1214 */
        "jmp .Lf1d7c24_001d7dab\n"
        /* { scope 2: weapDef, targetPos */
        /* { scope 3 */
        ".Lf1d7c24_001d895f:\n"
        "movl imp_cg_gun_move_minspeed, %eax\n" /* line 994 */
        "movl (%eax), %eax\n"
        "movl -0x17c(%ebp), %ecx\n" /* weapDef */
        "movss 0x194(%ecx), %xmm1\n"
        "addss 8(%eax), %xmm1\n"
        "jmp .Lf1d7c24_001d7e70\n"
        /* } scope */
        /* } scope */
        ".Lf1d7c24_001d897e:\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 943 | 1.0f */
        "jmp .Lf1d7c24_001d7d2c\n"
        /* { scope 2: weapDef, targetPos */
        /* { scope 3 */
        ".Lf1d7c24_001d898b:\n"
        "movl -0x17c(%ebp), %eax\n" /* line 1025 | weapDef */
        "addl $0x168, %eax\n"
        /* { scope 4 */
        "movss -0x64(%ebp), %xmm0\n" /* line 240 | targetPos */
        "movl -0x17c(%ebp), %edx\n" /* weapDef */
        "addss 0x168(%edx), %xmm0\n"
        "jmp .Lf1d7c24_001d887f\n"
        /* } scope */
        ".Lf1d7c24_001d89ae:\n"
        "andb $4, %dl\n" /* line 1005 */
        "je .Lf1d7c24_001d89d4\n"
        "movl -0x17c(%ebp), %eax\n" /* weapDef */
        "addl $0x150, %eax\n"
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "movl -0x17c(%ebp), %edx\n" /* weapDef */
        "mulss 0x150(%edx), %xmm0\n"
        "jmp .Lf1d7c24_001d7f0e\n"
        ".Lf1d7c24_001d89d4:\n"
        "movl -0x17c(%ebp), %eax\n" /* line 274 | weapDef */
        "addl $0x12c, %eax\n"
        /* } scope */
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "movl -0x17c(%ebp), %edx\n" /* weapDef */
        "mulss 0x12c(%edx), %xmm0\n"
        "jmp .Lf1d7c24_001d7f0e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1d7c24_001d89f5:\n"
        "movl %edi, 4(%esp)\n" /* line 1601 | pe */
        "leal -0x160(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisToAngles\n"
        "movl -0x28(%ebp), %eax\n" /* line 1603 | angles */
        "movl %eax, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x2c090(%esi)\n"
        "movl -0x24(%ebp), %eax\n" /* line 1604 */
        "movl %eax, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x2c094(%esi)\n"
        "movl imp_cg, %ebx\n" /* weapDef */
        "movl (%ebx), %edx\n" /* weapDef */
        "jmp .Lf1d7c24_001d85fe\n"
        /* { scope 2: weapDef, targetPos */
        /* { scope 3 */
        ".Lf1d7c24_001d8a36:\n"
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "jmp .Lf1d7c24_001d7ecc\n"
        /* } scope */
        ".Lf1d7c24_001d8a46:\n"
        "movss %xmm0, -0x34(%ebp)\n" /* line 183 | tempAngles */
        "movss %xmm0, -0x30(%ebp)\n" /* line 184 */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 185 */
        "movl 0x25c10(%esi), %eax\n" /* line 1170 */
        "movl %eax, (%esp)\n"
        "calll GetLeanFraction\n"
        "fstps -0x1bc(%ebp)\n"
        "movss -0x1bc(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm0\n" /* line 1171 */
        "mulss lit4_002ed628, %xmm0\n" /* -2.0f */
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 1173 | 1.0f */
        "subss 0x25ca0(%esi), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "mulss lit4_002eda7c, %xmm1\n" /* 1.600000023841858f */
        "movl $0, 0xc(%esp)\n" /* line 1175 */
        "leal -0x40(%ebp), %eax\n" /* right */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* tempAngles */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x198(%ebp)\n"
        "calll AngleVectors\n"
        /* { scope 3 */
        "movss -0x198(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x40(%ebp), %xmm0\n" /* right */
        "addss -0x138(%ebp), %xmm0\n"
        "movss %xmm0, -0x138(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x3c(%ebp), %xmm0\n"
        "addss -0x134(%ebp), %xmm0\n"
        "movss %xmm0, -0x134(%ebp)\n"
        "mulss -0x38(%ebp), %xmm1\n" /* line 290 */
        "addss -0x130(%ebp), %xmm1\n"
        "movss %xmm1, -0x130(%ebp)\n"
        "movl (%ebx), %ebx\n"
        "jmp .Lf1d7c24_001d7e22\n"
    );
}

/* line 2525 */
__attribute__((naked))
void CG_BulletHitEvent(int sourceEntityNum, vec_t *position, vec_t *normal, vec_t *reflected, int surfType, int event)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2525 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* position */
        "movl 0x18(%ebp), %edx\n" /* surfType */
        "movl 0x1c(%ebp), %eax\n" /* event */
        /* { scope 1 */
        "cmpl $0xb6, %eax\n" /* line 2538 */
        "je .Lf1d8b20_001d8c56\n"
        "cmpl $0xb7, %eax\n" /* line 2544 */
        "je .Lf1d8b20_001d8c7a\n"
        "movl imp_cgs, %ecx\n" /* line 2552 */
        "movl (%ecx), %eax\n"
        "movl 0xbe00(%eax, %edx, 4), %ecx\n"
        "movl 0xc200(%eax), %eax\n" /* line 2553 */
        "movl 4(%eax), %eax\n"
        "movl 0x170(%eax, %edx, 4), %ebx\n" /* fxNormal */
        "movl 0x1cc(%eax, %edx, 4), %esi\n" /* line 2554 | fxReflect */
        ".Lf1d8b20_001d8b6e:\n"
        "movl imp_cg_blood, %eax\n" /* line 2559 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1d8b20_001d8b84\n"
        "cmpl $7, %edx\n"
        "je .Lf1d8b20_001d8ca5\n"
        ".Lf1d8b20_001d8b84:\n"
        "movl %ecx, 8(%esp)\n" /* line 2565 */
        "movl %edi, 4(%esp)\n" /* position */
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "testl %ebx, %ebx\n" /* line 2566 | fxNormal */
        "je .Lf1d8b20_001d8baf\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2567 | normal */
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* position */
        "movl %ebx, (%esp)\n" /* fxNormal */
        "calll FX_PlayEffect\n"
        ".Lf1d8b20_001d8baf:\n"
        "testl %esi, %esi\n" /* line 2568 | fxReflect */
        "je .Lf1d8b20_001d8bc6\n"
        "movl 0x14(%ebp), %eax\n" /* line 2569 | reflected */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* position */
        "movl %esi, (%esp)\n" /* fxReflect */
        "calll FX_PlayEffect\n"
        ".Lf1d8b20_001d8bc6:\n"
        "movl s_barrelTags, %eax\n" /* line 2571 */
        "movzwl (%eax), %ecx\n" /* flashTag */
        /* { scope 2: muzzle */
        /* { scope 3 */
        "movl imp_cg_tracerChance, %esi\n" /* line 2497 */
        "movl (%esi), %eax\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "jae .Lf1d8b20_001d8c4e\n"
        "leal -0x24(%ebp), %ebx\n" /* line 2500 | muzzle */
        "movl %ebx, %edx\n"
        "movl 8(%ebp), %eax\n" /* sourceEntityNum */
        "calll CG_CalcMuzzlePoint\n"
        "testl %eax, %eax\n"
        "je .Lf1d8b20_001d8c4e\n"
        "movl imp_cg, %eax\n" /* line 2503 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl $0xc00000, 0x18(%eax)\n"
        "je .Lf1d8b20_001d8c0f\n"
        "movl 8(%ebp), %edx\n" /* sourceEntityNum */
        "cmpl 0xd8(%eax), %edx\n"
        "je .Lf1d8b20_001d8c42\n"
        ".Lf1d8b20_001d8c0f:\n"
        "calll rand\n" /* line 2506 */
        "movl %eax, %edx\n"
        "movl (%esi), %eax\n" /* line 2508 */
        "movss lit4_002eda78, %xmm1\n" /* 2147483648.0f */
        "mulss 8(%eax), %xmm1\n"
        "testl %edx, %edx\n"
        "js .Lf1d8b20_001d8cba\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1d8b20_001d8c31:\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1d8b20_001d8c42\n"
        "movl %edi, 4(%esp)\n" /* line 2509 */
        "movl %ebx, (%esp)\n"
        "calll CG_SpawnTracer\n"
        ".Lf1d8b20_001d8c42:\n"
        "movl %edi, 4(%esp)\n" /* line 2516 */
        "movl %ebx, (%esp)\n"
        "calll CG_WhizbySound\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1d8b20_001d8c4e:\n"
        "addl $0x2c, %esp\n" /* line 2572 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d8b20_001d8c56:\n"
        "movl imp_cgs, %ecx\n" /* line 2540 */
        "movl (%ecx), %eax\n"
        "movl 0xbda4(%eax, %edx, 4), %ecx\n"
        "movl 0xc200(%eax), %eax\n" /* line 2541 */
        "movl 4(%eax), %eax\n"
        "movl (%eax, %edx, 4), %ebx\n" /* fxNormal */
        "movl 0x5c(%eax, %edx, 4), %esi\n" /* line 2542 | fxReflect */
        "jmp .Lf1d8b20_001d8b6e\n"
        ".Lf1d8b20_001d8c7a:\n"
        "movl imp_cgs, %ecx\n" /* line 2546 */
        "movl (%ecx), %eax\n"
        "movl 0xbe5c(%eax, %edx, 4), %ecx\n"
        "movl 0xc200(%eax), %eax\n" /* line 2547 */
        "movl 4(%eax), %eax\n"
        "movl 0xb8(%eax, %edx, 4), %ebx\n" /* fxNormal */
        "movl 0x114(%eax, %edx, 4), %esi\n" /* line 2548 | fxReflect */
        "jmp .Lf1d8b20_001d8b6e\n"
        ".Lf1d8b20_001d8ca5:\n"
        "movl imp_cgs, %edx\n" /* line 2561 */
        "movl (%edx), %eax\n"
        "movl 0xc204(%eax), %ebx\n" /* fxNormal */
        "xorl %esi, %esi\n" /* fxReflect */
        "jmp .Lf1d8b20_001d8b84\n"
        /* { scope 2: muzzle */
        /* { scope 3 */
        ".Lf1d8b20_001d8cba:\n"
        "movl %edx, %eax\n" /* line 2508 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1d8b20_001d8c31\n"
    );
}

/* line 2400 */
__attribute__((naked))
void CG_DrawTracer(vec_t *start, vec_t *finish)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2400 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18c, %esp\n"
        "movl 8(%ebp), %edi\n" /* start */
        "movl 0xc(%ebp), %esi\n" /* finish */
        /* { scope 1: tracerScaleMinDist */
        "movss (%esi), %xmm2\n" /* line 248 */
        "subss (%edi), %xmm2\n"
        "leal 4(%esi), %eax\n" /* line 249 */
        "movl %eax, -0x154(%ebp)\n"
        "leal 4(%edi), %eax\n"
        "movl %eax, -0x150(%ebp)\n"
        "movss 4(%esi), %xmm4\n"
        "subss 4(%edi), %xmm4\n"
        "leal 8(%esi), %eax\n" /* line 250 */
        "movl %eax, -0x14c(%ebp)\n"
        "leal 8(%edi), %eax\n"
        "movl %eax, -0x148(%ebp)\n"
        "movss 8(%esi), %xmm3\n"
        "subss 8(%edi), %xmm3\n"
        "movl imp_cg, %eax\n" /* line 2410 */
        "movl (%eax), %eax\n"
        "movaps %xmm2, %xmm1\n" /* line 304 */
        "mulss 0x285a0(%eax), %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 0x285a4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0x285a8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss 0x285ac(%eax), %xmm2\n"
        "mulss 0x285b0(%eax), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "mulss 0x285b4(%eax), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss 0x285a0(%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* right */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 0x285a4(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 0x285a8(%eax), %xmm2\n" /* line 274 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "xorps cg_perturbations+1072, %xmm1\n" /* line 2414 | scale */
        /* { scope 2: tracerScaleDistRange */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x285ac(%eax), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* right */
        "movss %xmm0, -0x24(%ebp)\n" /* right */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x285b0(%eax), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 0x285b4(%eax), %xmm1\n" /* line 290 */
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "leal -0x24(%ebp), %eax\n" /* line 2415 | right */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl imp_cg_tracerWidth, %eax\n" /* line 2417 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x13c(%ebp)\n"
        /* { scope 2: tracerScaleDistRange */
        "movl imp_cg_tracerScale, %eax\n" /* line 2376 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "movl imp_cg_tracerScaleMinDist, %eax\n" /* line 2377 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movss %xmm1, -0x144(%ebp)\n" /* tracerScaleMinDist */
        "movl imp_cg_tracerScaleDistRange, %eax\n" /* line 2378 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x140(%ebp)\n" /* tracerScaleDistRange */
        "ucomiss lit4_002ed5d0, %xmm2\n" /* line 2380 | 1.0f */
        "jne .Lf1d8cd0_001d9073\n"
        "jp .Lf1d8cd0_001d9073\n"
        "movss -0x13c(%ebp), %xmm6\n"
        "movaps %xmm6, %xmm1\n"
        /* } scope */
        ".Lf1d8cd0_001d8e54:\n"
        "movss -0x24(%ebp), %xmm5\n" /* line 288 | right */
        "movaps %xmm5, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss (%esi), %xmm0\n"
        "movss %xmm0, -0x134(%ebp)\n" /* verts */
        "movss -0x20(%ebp), %xmm4\n" /* line 289 */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movl -0x154(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x130(%ebp)\n"
        "movss -0x1c(%ebp), %xmm3\n" /* line 290 */
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movl -0x14c(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x12c(%ebp)\n"
        "movl $0x3f800000, -0x118(%ebp)\n" /* line 30 */
        "movl $0x3f800000, -0x114(%ebp)\n" /* line 31 */
        "movl $0x3f800000, -0x110(%ebp)\n" /* line 30 */
        "movl $0x3f800000, -0x10c(%ebp)\n" /* line 31 */
        "movl $0xffffffff, -0x11c(%ebp)\n" /* line 2425 */
        "movss cg_perturbations+1072, %xmm2\n" /* line 2427 */
        "xorps %xmm2, %xmm1\n" /* scale */
        /* { scope 2: tracerScaleDistRange */
        "movaps %xmm5, %xmm0\n" /* line 288 */
        "mulss %xmm1, %xmm0\n"
        "addss (%esi), %xmm0\n"
        "movss %xmm0, -0xf0(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "movl -0x154(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0xec(%ebp)\n"
        "mulss %xmm3, %xmm1\n" /* line 290 */
        "movl -0x14c(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, -0xe8(%ebp)\n"
        /* } scope */
        "movl $0x3f800000, -0xd4(%ebp)\n" /* line 30 */
        "movl $0, -0xd0(%ebp)\n" /* line 31 */
        "movl $0x3f800000, -0xcc(%ebp)\n" /* line 30 */
        "movl $0, -0xc8(%ebp)\n" /* line 31 */
        "movl $0xffffffff, -0xd8(%ebp)\n" /* line 2430 */
        "movaps %xmm6, %xmm1\n" /* line 2432 | scale */
        "xorps %xmm2, %xmm1\n" /* scale */
        /* { scope 2: tracerScaleDistRange */
        "movaps %xmm5, %xmm0\n" /* line 288 */
        "mulss %xmm1, %xmm0\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, -0xac(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "movl -0x150(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n"
        "mulss %xmm3, %xmm1\n" /* line 290 */
        "movl -0x148(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, -0xa4(%ebp)\n"
        /* } scope */
        "movl $0, -0x90(%ebp)\n" /* line 30 */
        "movl $0, -0x8c(%ebp)\n" /* line 31 */
        "movl $0, -0x88(%ebp)\n" /* line 30 */
        "movl $0, -0x84(%ebp)\n" /* line 31 */
        "movl $0xffffffff, -0x94(%ebp)\n" /* line 2435 */
        "mulss %xmm6, %xmm5\n" /* line 288 */
        "addss (%edi), %xmm5\n"
        "movss %xmm5, -0x68(%ebp)\n"
        "mulss %xmm6, %xmm4\n" /* line 289 */
        "movl -0x150(%ebp), %eax\n"
        "addss (%eax), %xmm4\n"
        "movss %xmm4, -0x64(%ebp)\n"
        "mulss %xmm6, %xmm3\n" /* line 290 */
        "movl -0x148(%ebp), %eax\n"
        "addss (%eax), %xmm3\n"
        "movss %xmm3, -0x60(%ebp)\n"
        "movl $0, -0x4c(%ebp)\n" /* line 30 */
        "movl $0x3f800000, -0x48(%ebp)\n" /* line 31 */
        "movl $0, -0x44(%ebp)\n" /* line 30 */
        "movl $0x3f800000, -0x40(%ebp)\n" /* line 31 */
        "movl $0xffffffff, -0x50(%ebp)\n" /* line 2440 */
        "leal -0x134(%ebp), %ebx\n" /* line 2442 | verts */
        "movl %ebx, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll CL_DefaultVertexFrames\n"
        "movl %ebx, 0xc(%esp)\n" /* line 2443 */
        "movl $4, 8(%esp)\n"
        "movl $0x1f, 4(%esp)\n"
        "movl imp_cgs, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0xba3c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_AddPolyToScene\n"
        /* } scope */
        "addl $0x18c, %esp\n" /* line 2444 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tracerScaleMinDist */
        /* { scope 2: tracerScaleDistRange */
        ".Lf1d8cd0_001d9073:\n"
        "movl imp_cg, %eax\n" /* line 2383 */
        "movl (%eax), %ebx\n"
        "addl $0x28588, %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movss %xmm2, -0x178(%ebp)\n"
        "calll Vec3Distance\n"
        "fstps -0x17c(%ebp)\n"
        "movss -0x17c(%ebp), %xmm0\n"
        "movl %ebx, 4(%esp)\n" /* line 2384 */
        "movl %esi, (%esp)\n"
        "movss %xmm0, -0x168(%ebp)\n"
        "calll Vec3Distance\n"
        "fstps -0x17c(%ebp)\n"
        "movss -0x17c(%ebp), %xmm3\n"
        "pxor %xmm4, %xmm4\n" /* line 2386 */
        "movss -0x168(%ebp), %xmm0\n"
        "movss -0x178(%ebp), %xmm2\n"
        "movss -0x144(%ebp), %xmm1\n" /* tracerScaleMinDist */
        "ucomiss %xmm4, %xmm1\n"
        "jp .Lf1d8cd0_001d90e7\n"
        "je .Lf1d8cd0_001d90ef\n"
        ".Lf1d8cd0_001d90e7:\n"
        "subss %xmm1, %xmm0\n" /* line 2388 */
        "subss %xmm1, %xmm3\n" /* line 2389 */
        ".Lf1d8cd0_001d90ef:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 2392 */
        "jbe .Lf1d8cd0_001d917a\n"
        /* { scope 3 */
        "movss -0x140(%ebp), %xmm1\n" /* line 2349 | tracerScaleDistRange */
        "ucomiss %xmm4, %xmm1\n"
        "jbe .Lf1d8cd0_001d916d\n"
        "movaps %xmm0, %xmm1\n" /* line 2352 */
        "divss -0x140(%ebp), %xmm1\n" /* tracerScaleDistRange */
        "mulss %xmm2, %xmm1\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 406 | 1.0f */
        "ucomiss %xmm1, %xmm5\n"
        "ja .Lf1d8cd0_001d9191\n"
        "ucomiss %xmm2, %xmm1\n" /* line 408 */
        "ja .Lf1d8cd0_001d9175\n"
        /* } scope */
        ".Lf1d8cd0_001d9126:\n"
        "movss -0x13c(%ebp), %xmm6\n" /* line 2393 */
        "mulss %xmm1, %xmm6\n"
        ".Lf1d8cd0_001d9132:\n"
        "ucomiss %xmm4, %xmm3\n" /* line 2395 */
        "jbe .Lf1d8cd0_001d9196\n"
        /* { scope 3 */
        /* { scope 4 */
        "movss -0x140(%ebp), %xmm0\n" /* line 2349 | tracerScaleDistRange */
        "ucomiss %xmm4, %xmm0\n"
        "jbe .Lf1d8cd0_001d915c\n"
        "movaps %xmm3, %xmm0\n" /* line 2352 */
        "divss -0x140(%ebp), %xmm0\n" /* tracerScaleDistRange */
        "mulss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm5\n" /* line 406 */
        "ja .Lf1d8cd0_001d918c\n"
        "minss %xmm0, %xmm2\n" /* line 408 */
        /* } scope */
        /* } scope */
        ".Lf1d8cd0_001d915c:\n"
        "movss -0x13c(%ebp), %xmm1\n" /* line 2396 */
        "mulss %xmm2, %xmm1\n"
        "jmp .Lf1d8cd0_001d8e54\n"
        ".Lf1d8cd0_001d916d:\n"
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        /* { scope 3 */
        ".Lf1d8cd0_001d9175:\n"
        "movaps %xmm2, %xmm1\n" /* line 408 */
        "jmp .Lf1d8cd0_001d9126\n"
        /* } scope */
        ".Lf1d8cd0_001d917a:\n"
        "movss -0x13c(%ebp), %xmm6\n" /* line 2392 */
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        "jmp .Lf1d8cd0_001d9132\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1d8cd0_001d918c:\n"
        "movaps %xmm5, %xmm2\n" /* line 406 */
        "jmp .Lf1d8cd0_001d915c\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf1d8cd0_001d9191:\n"
        "movaps %xmm5, %xmm1\n"
        "jmp .Lf1d8cd0_001d9126\n"
        /* } scope */
        ".Lf1d8cd0_001d9196:\n"
        "movss -0x13c(%ebp), %xmm1\n" /* line 2395 */
        "jmp .Lf1d8cd0_001d8e54\n"
    );
}

/* line 1852 */
__attribute__((naked))
void CG_WeaponSlot_f(qboolean next, qboolean ignoreEmpty)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1852 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 1857 */
        "movl (%eax), %esi\n"
        "movl 0x24(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d91a4_001d91e6\n"
        "cmpw $0, 0x25bd0(%esi)\n" /* line 1861 */
        "js .Lf1d91a4_001d91e6\n"
        "testb $0x80, 0x1a(%eax)\n" /* line 1864 */
        "je .Lf1d91a4_001d91e6\n"
        "movl 0x25bb0(%esi), %ecx\n" /* line 1867 */
        "movl %ecx, %eax\n"
        "subl 0x2be54(%esi), %eax\n"
        "movl imp_cg_weaponCycleDelay, %edx\n"
        "movl (%edx), %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jge .Lf1d91a4_001d91ee\n"
        /* } scope */
        ".Lf1d91a4_001d91e6:\n"
        "addl $0x1c, %esp\n" /* line 1891 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d91a4_001d91ee:\n"
        "movl %ecx, 0x2be54(%esi)\n" /* line 1870 */
        "movl $1, (%esp)\n" /* line 1872 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponSlotForName\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 1873 */
        "je .Lf1d91a4_001d928b\n"
        ".Lf1d91a4_001d920e:\n"
        "leal -1(%edx), %eax\n" /* line 1877 */
        "cmpl $1, %eax\n"
        "ja .Lf1d91a4_001d91e6\n"
        "movzbl 0x26118(%edx, %esi), %eax\n" /* line 1880 */
        "movsbl %al, %edi\n" /* iWeaponIndex */
        "testb %al, %al\n" /* line 1883 */
        "je .Lf1d91a4_001d91e6\n"
        "movl %edi, %eax\n" /* line 1646 */
        "sarl $5, %eax\n"
        "movl %edi, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1d91a4_001d91e6\n"
        "movl 0x25bb0(%esi), %eax\n" /* line 2682 */
        "movl %eax, 0x2be54(%esi)\n"
        "movl 0x2be50(%esi), %eax\n" /* line 2684 */
        "cmpl %eax, %edi\n" /* iWeaponIndex */
        "je .Lf1d91a4_001d91e6\n"
        "movl %eax, (%esp)\n" /* line 2687 */
        "calll BG_GetWeaponDef\n"
        "movl 0x36c(%eax), %ebx\n" /* weaponIndex */
        "movl %edi, 0x2be50(%esi)\n" /* line 2689 | iWeaponIndex */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "cmpl %ebx, %edi\n" /* line 2692 | weaponIndex, iWeaponIndex */
        "je .Lf1d91a4_001d91e6\n"
        "movl $0, (%esp)\n" /* line 2693 */
        "calll CL_SetADS\n"
        "jmp .Lf1d91a4_001d91e6\n"
        ".Lf1d91a4_001d928b:\n"
        "movl $1, (%esp)\n" /* line 1874 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %edx\n"
        "jmp .Lf1d91a4_001d920e\n"
        "addb %al, (%eax)\n"
        /* } scope */
        /* } scope */
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* next */
        "testl %eax, %eax\n"
        "je 0x1d93c0\n"
        "movl $1, %ebx\n"
        "movl $1, %eax\n"
        "movl %eax, %esi\n"
        "jmp .Lf1d91a4_001d92d4\n"
        "addl %ebx, %esi\n"
        "testl %esi, %esi\n"
        "jle 0x1d93c9\n"
    );
}

/* line 1943 */
__attribute__((naked))
qboolean CG_SelectFirstWeaponNotInSlot(qboolean bNext, qboolean bIgnoreEmpty)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1943 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1949 | bNext */
        "testl %eax, %eax\n"
        "je .Lf1d92a8_001d93c0\n"
        "movl $1, %ebx\n" /* iStep */
        "movl $1, %eax\n"
        ".Lf1d92a8_001d92c6:\n"
        "movl %eax, %esi\n" /* line 1961 | iWeaponIndex */
        "jmp .Lf1d92a8_001d92d4\n"
        ".Lf1d92a8_001d92ca:\n"
        "addl %ebx, %esi\n" /* iStep, iWeaponIndex */
        "testl %esi, %esi\n" /* iWeaponIndex */
        "jle .Lf1d92a8_001d93c9\n"
        ".Lf1d92a8_001d92d4:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %esi, %eax\n" /* iWeaponIndex */
        "jl .Lf1d92a8_001d93c9\n"
        "movl imp_cg, %eax\n" /* line 1964 */
        "movl (%eax), %edx\n"
        "movl %esi, %eax\n" /* iWeaponIndex */
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n" /* iWeaponIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1d92a8_001d92ca\n"
        "movl $1, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* iWeaponIndex */
        "leal 0x25bc4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_IsPlayerWeaponInSlot\n"
        "testl %eax, %eax\n"
        "jne .Lf1d92a8_001d92ca\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* iWeaponIndex */
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x25bc4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetStackSlotForWeapon\n"
        "testl %eax, %eax\n"
        "jne .Lf1d92a8_001d92ca\n"
        "movl %esi, (%esp)\n" /* line 1968 | iWeaponIndex */
        "calll BG_DoesWeaponNeedSlot\n"
        "testb %al, %al\n"
        "je .Lf1d92a8_001d92ca\n"
        "movl 0xc(%ebp), %edi\n" /* line 1972 | bIgnoreEmpty */
        "testl %edi, %edi\n"
        "je .Lf1d92a8_001d9378\n"
        "movl %esi, 4(%esp)\n" /* iWeaponIndex */
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x25bc4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_WeaponAmmo\n"
        "testl %eax, %eax\n"
        "je .Lf1d92a8_001d92ca\n"
        ".Lf1d92a8_001d9378:\n"
        "movl imp_cg, %eax\n" /* line 2682 */
        "movl (%eax), %edi\n"
        "movl 0x25bb0(%edi), %eax\n"
        "movl %eax, 0x2be54(%edi)\n"
        "movl 0x2be50(%edi), %eax\n" /* line 2684 */
        "cmpl %esi, %eax\n" /* iWeaponIndex */
        "je .Lf1d92a8_001d93b9\n"
        "movl %eax, (%esp)\n" /* line 2687 */
        "calll BG_GetWeaponDef\n"
        "movl 0x36c(%eax), %ebx\n" /* iStep */
        "movl %esi, 0x2be50(%edi)\n" /* line 2689 | iWeaponIndex */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "cmpl %esi, %ebx\n" /* line 2692 | iWeaponIndex, iStep */
        "jne .Lf1d92a8_001d93dd\n"
        ".Lf1d92a8_001d93b9:\n"
        "movl $1, %eax\n" /* line 1964 */
        "jmp .Lf1d92a8_001d93cb\n"
        ".Lf1d92a8_001d93c0:\n"
        "calll BG_GetNumWeapons\n" /* line 1957 */
        "testl %eax, %eax\n" /* line 1961 */
        "jg .Lf1d92a8_001d93d3\n"
        ".Lf1d92a8_001d93c9:\n"
        "xorl %eax, %eax\n" /* line 1964 */
        /* } scope */
        ".Lf1d92a8_001d93cb:\n"
        "addl $0x1c, %esp\n" /* line 1980 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d92a8_001d93d3:\n"
        "movl $0xffffffff, %ebx\n" /* line 1961 | iStep */
        "jmp .Lf1d92a8_001d92c6\n"
        ".Lf1d92a8_001d93dd:\n"
        "movl $0, (%esp)\n" /* line 2693 */
        "calll CL_SetADS\n"
        "movl $1, %eax\n"
        "jmp .Lf1d92a8_001d93cb\n"
    );
}

/* line 1988 */
__attribute__((naked))
void CG_CycleWeap(qboolean bNext, qboolean bIgnoreEmpty)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1988 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* bNext */
        "movl %eax, -0x2c(%ebp)\n" /* bNext */
        "movl 0xc(%ebp), %edx\n" /* bIgnoreEmpty */
        "movl %edx, -0x30(%ebp)\n" /* bIgnoreEmpty */
        /* { scope 1: step, step */
        "movl imp_cg, %esi\n" /* line 1997 | iWeaponIndex */
        "movl (%esi), %eax\n" /* iWeaponIndex */
        "movl 0x24(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d95ef\n"
        "testb $0x80, 0x1a(%eax)\n" /* line 2000 */
        "je .Lf1d93f0_001d95ef\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 2003 | bNext, slot */
        "testl %ebx, %ebx\n" /* slot */
        "je .Lf1d93f0_001d96e6\n"
        "movl $1, -0x28(%ebp)\n" /* iStep */
        "movl $1, %edi\n" /* iSlotLooped */
        "movl $1, -0x24(%ebp)\n" /* iWeaponLooped */
        ".Lf1d93f0_001d9440:\n"
        "movl (%esi), %ebx\n" /* line 2016 | iWeaponIndex, slot */
        "movl $1, 8(%esp)\n"
        "movl 0x2be50(%ebx), %eax\n" /* slot */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%ebx), %esi\n" /* slot, iWeaponIndex */
        "movl %esi, (%esp)\n" /* iWeaponIndex */
        "calll BG_IsPlayerWeaponInSlot\n"
        "testl %eax, %eax\n" /* line 2017 */
        "je .Lf1d93f0_001d9710\n"
        ".Lf1d93f0_001d946a:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 2020 | bIgnoreEmpty */
        "testl %ecx, %ecx\n"
        "je .Lf1d93f0_001d996c\n"
        /* { scope 2 */
        "movl %eax, %ebx\n" /* line 1924 | slot */
        "movl imp_cg, %esi\n"
        /* } scope */
        ".Lf1d93f0_001d947d:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 2024 | iStep */
        "leal 1(%ecx, %ebx), %eax\n"
        "andl $0x80000001, %eax\n"
        "js .Lf1d93f0_001d95f7\n"
        "leal 1(%eax), %ebx\n" /* slot */
        "cmpl %ebx, %edi\n" /* line 2025 | slot, iSlotLooped */
        "je .Lf1d93f0_001d960b\n"
        ".Lf1d93f0_001d949a:\n"
        "movl (%esi), %edx\n" /* line 2029 | iWeaponIndex */
        "movzbl 0x26118(%ebx, %edx), %eax\n" /* slot */
        "testb %al, %al\n"
        "je .Lf1d93f0_001d947d\n"
        "movsbl %al, %eax\n" /* line 2032 */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_WeaponAmmo\n"
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d947d\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "movl (%esi), %eax\n" /* iWeaponIndex */
        ".Lf1d93f0_001d94c9:\n"
        "movzbl 0x26118(%ebx, %eax), %ecx\n" /* line 2034 | weaponIndex */
        "movsbl %cl, %ebx\n" /* weaponIndex */
        /* { scope 2 */
        "movl 0x25bb0(%eax), %edx\n" /* line 2682 */
        "movl %edx, 0x2be54(%eax)\n"
        "movl 0x2be50(%eax), %eax\n" /* line 2684 */
        "cmpl %eax, %ebx\n" /* weaponIndex */
        "je .Lf1d93f0_001d95ef\n"
        "testb %cl, %cl\n" /* line 2687 */
        "jne .Lf1d93f0_001d985b\n"
        ".Lf1d93f0_001d94f6:\n"
        "xorl %edi, %edi\n" /* iSlotLooped */
        ".Lf1d93f0_001d94f8:\n"
        "movl (%esi), %eax\n" /* line 2689 | iWeaponIndex */
        "movl %ebx, 0x2be50(%eax)\n" /* weaponIndex */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "movl %edi, %eax\n" /* line 2692 | iSlotLooped */
        "testb %al, %al\n"
        "jne .Lf1d93f0_001d95ef\n"
        /* } scope */
        ".Lf1d93f0_001d9516:\n"
        "movl $0, 8(%ebp)\n" /* line 2693 | bNext */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2092 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: step, step */
        "jmp CL_SetADS\n" /* line 2693 */
        /* { scope 2 */
        ".Lf1d93f0_001d9529:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1907 | bNext */
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d984a\n"
        "movl $1, -0x1c(%ebp)\n" /* step */
        "movl $1, %ebx\n" /* slot */
        /* } scope */
        ".Lf1d93f0_001d9540:\n"
        "movl -0x30(%ebp), %eax\n" /* line 2083 | bIgnoreEmpty */
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d987a\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %esi\n" /* iWeaponIndex */
        "leal 0x25bc4(%esi), %edi\n" /* iWeaponIndex, iSlotLooped */
        "jmp .Lf1d93f0_001d9569\n"
        /* { scope 2 */
        ".Lf1d93f0_001d955a:\n"
        "addl -0x1c(%ebp), %ebx\n" /* line 1918 | step, slot */
        "leal -1(%ebx), %eax\n" /* slot */
        "cmpl $1, %eax\n"
        "ja .Lf1d93f0_001d989b\n"
        ".Lf1d93f0_001d9569:\n"
        "movzbl 0x26118(%ebx, %esi), %eax\n" /* line 1921 | slot */
        "testb %al, %al\n"
        "je .Lf1d93f0_001d955a\n"
        "movsbl %al, %eax\n" /* line 1924 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll BG_WeaponAmmo\n"
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d955a\n"
        "movl imp_cg, %esi\n"
        ".Lf1d93f0_001d958e:\n"
        "movl (%esi), %eax\n" /* line 1926 */
        "movzbl 0x26118(%ebx, %eax), %ecx\n" /* weaponIndex */
        "movsbl %cl, %ebx\n" /* weaponIndex */
        /* { scope 3 */
        "movl 0x25bb0(%eax), %edx\n" /* line 2682 */
        "movl %edx, 0x2be54(%eax)\n"
        "movl 0x2be50(%eax), %eax\n" /* line 2684 */
        "cmpl %eax, %ebx\n" /* weaponIndex */
        "je .Lf1d93f0_001d95ef\n"
        "testb %cl, %cl\n" /* line 2687 */
        "je .Lf1d93f0_001d95cf\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "cmpl 0x36c(%eax), %ebx\n" /* weaponIndex */
        "je .Lf1d93f0_001d995c\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        ".Lf1d93f0_001d95cf:\n"
        "xorl %edi, %edi\n" /* iSlotLooped */
        ".Lf1d93f0_001d95d1:\n"
        "movl (%esi), %eax\n" /* line 2689 | iWeaponIndex */
        "movl %ebx, 0x2be50(%eax)\n" /* weaponIndex */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "movl %edi, %ecx\n" /* line 2692 | iSlotLooped */
        "testb %cl, %cl\n"
        "je .Lf1d93f0_001d9516\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1d93f0_001d95ef:\n"
        "addl $0x3c, %esp\n" /* line 2092 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: step, step */
        ".Lf1d93f0_001d95f7:\n"
        "subl $1, %eax\n" /* line 2024 */
        "orl $0xfffffffe, %eax\n"
        "addl $1, %eax\n"
        "leal 1(%eax), %ebx\n" /* slot */
        "cmpl %ebx, %edi\n" /* line 2025 | slot, iSlotLooped */
        "jne .Lf1d93f0_001d949a\n"
        ".Lf1d93f0_001d960b:\n"
        "movl -0x30(%ebp), %edx\n" /* line 2040 | bIgnoreEmpty */
        "movl %edx, 4(%esp)\n"
        "movl -0x2c(%ebp), %ecx\n" /* bNext */
        "movl %ecx, (%esp)\n"
        "calll CG_SelectFirstWeaponNotInSlot\n"
        "testl %eax, %eax\n"
        "jne .Lf1d93f0_001d95ef\n"
        /* { scope 2 */
        "movl -0x2c(%ebp), %edx\n" /* line 1907 | bNext */
        "testl %edx, %edx\n"
        "je .Lf1d93f0_001d96ff\n"
        "movl $1, -0x20(%ebp)\n" /* step */
        "movl $1, %ebx\n" /* slot */
        /* } scope */
        ".Lf1d93f0_001d9638:\n"
        "movl -0x30(%ebp), %eax\n" /* line 2032 | bIgnoreEmpty */
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d99c8\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "movl %esi, %edi\n" /* iWeaponIndex, iSlotLooped */
        "jmp .Lf1d93f0_001d9658\n"
        /* { scope 2 */
        ".Lf1d93f0_001d964d:\n"
        "addl -0x20(%ebp), %ebx\n" /* line 1918 | step, slot */
        "leal -1(%ebx), %eax\n" /* slot */
        "cmpl $1, %eax\n"
        "ja .Lf1d93f0_001d9690\n"
        ".Lf1d93f0_001d9658:\n"
        "movl (%esi), %edx\n" /* line 1921 */
        "movzbl 0x26118(%ebx, %edx), %eax\n" /* slot */
        "testb %al, %al\n"
        "je .Lf1d93f0_001d964d\n"
        "movsbl %al, %eax\n" /* line 1924 */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_WeaponAmmo\n"
        "testl %eax, %eax\n"
        "jne .Lf1d93f0_001d98b8\n"
        "movl %edi, %esi\n"
        "addl -0x20(%ebp), %ebx\n" /* line 1918 | step, slot */
        "leal -1(%ebx), %eax\n" /* slot */
        "cmpl $1, %eax\n"
        "jbe .Lf1d93f0_001d9658\n"
        /* } scope */
        ".Lf1d93f0_001d9690:\n"
        "movl (%esi), %edx\n" /* line 2087 | iWeaponIndex */
        "movl 0x2be50(%edx), %ecx\n"
        "movl %ecx, %eax\n"
        "sarl $5, %eax\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1d93f0_001d95ef\n"
        "movl 0x25bb0(%edx), %eax\n" /* line 2682 */
        "movl %eax, 0x2be54(%edx)\n"
        "movl 0x2be50(%edx), %eax\n" /* line 2684 */
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d95ef\n"
        "movl $0, 0x2be50(%edx)\n" /* line 2689 */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "jmp .Lf1d93f0_001d9516\n"
        ".Lf1d93f0_001d96e6:\n"
        "calll BG_GetNumWeapons\n" /* line 2013 */
        "movl %eax, -0x24(%ebp)\n" /* iWeaponLooped */
        "movl $0xffffffff, -0x28(%ebp)\n" /* iStep */
        "movl $2, %edi\n" /* iSlotLooped */
        "jmp .Lf1d93f0_001d9440\n"
        /* { scope 2 */
        ".Lf1d93f0_001d96ff:\n"
        "movl $0xffffffff, -0x20(%ebp)\n" /* line 1907 | step */
        "movl $2, %ebx\n" /* slot */
        "jmp .Lf1d93f0_001d9638\n"
        /* } scope */
        ".Lf1d93f0_001d9710:\n"
        "movl $0, 8(%esp)\n" /* line 2018 */
        "movl 0x2be50(%ebx), %eax\n" /* slot */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* iWeaponIndex */
        "calll BG_GetStackSlotForWeapon\n"
        "testl %eax, %eax\n" /* line 2020 */
        "jne .Lf1d93f0_001d946a\n"
        "movl imp_cg, %eax\n" /* line 2047 */
        "movl (%eax), %eax\n"
        "movl 0x2be50(%eax), %esi\n" /* iWeaponIndex */
        ".Lf1d93f0_001d973f:\n"
        "calll BG_GetNumWeapons\n" /* line 2049 */
        "movl %eax, %ebx\n" /* weaponIndex */
        "calll BG_GetNumWeapons\n"
        "movl %eax, %ecx\n"
        "movl -0x28(%ebp), %edx\n" /* iStep */
        "addl %esi, %edx\n" /* iWeaponIndex */
        "leal -1(%edx, %ebx), %ebx\n" /* weaponIndex */
        "movl %ebx, %eax\n" /* weaponIndex */
        "cltd\n"
        "idivl %ecx\n"
        "leal 1(%edx), %esi\n" /* iWeaponIndex */
        "cmpl %esi, -0x24(%ebp)\n" /* line 2050 | iWeaponIndex, iWeaponLooped */
        "je .Lf1d93f0_001d9529\n"
        "movl imp_cg, %eax\n" /* line 2054 */
        "movl (%eax), %ebx\n" /* weaponIndex */
        "movl %esi, %eax\n" /* iWeaponIndex */
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n" /* iWeaponIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%ebx, %eax, 4), %eax\n" /* weaponIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf1d93f0_001d973f\n"
        "movl 0x2be50(%ebx), %eax\n" /* line 2058 | weaponIndex */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* iWeaponIndex */
        "calll BG_IsPlayerWeaponAnAlt\n"
        "testl %eax, %eax\n"
        "jne .Lf1d93f0_001d973f\n"
        "movl $1, 8(%esp)\n" /* line 2062 */
        "movl %esi, 4(%esp)\n" /* iWeaponIndex */
        "leal 0x25bc4(%ebx), %edi\n" /* weaponIndex, iSlotLooped */
        "movl %edi, (%esp)\n" /* iSlotLooped */
        "calll BG_IsPlayerWeaponInSlot\n"
        "testl %eax, %eax\n"
        "jne .Lf1d93f0_001d973f\n"
        "movl $0, 8(%esp)\n" /* line 2066 */
        "movl %esi, 4(%esp)\n" /* iWeaponIndex */
        "movl %edi, (%esp)\n" /* iSlotLooped */
        "calll BG_GetStackSlotForWeapon\n"
        "testl %eax, %eax\n"
        "jne .Lf1d93f0_001d973f\n"
        "movl -0x30(%ebp), %eax\n" /* line 2070 | bIgnoreEmpty */
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d97f0\n"
        "movl %esi, 4(%esp)\n" /* iWeaponIndex */
        "movl %edi, (%esp)\n" /* iSlotLooped */
        "calll BG_WeaponAmmo\n"
        "testl %eax, %eax\n"
        "je .Lf1d93f0_001d973f\n"
        ".Lf1d93f0_001d97f0:\n"
        "movl %esi, (%esp)\n" /* line 2074 | iWeaponIndex */
        "calll BG_DoesWeaponNeedSlot\n"
        "testb %al, %al\n"
        "je .Lf1d93f0_001d973f\n"
        "movl 0x25bb0(%ebx), %eax\n" /* line 2682 | weaponIndex */
        "movl %eax, 0x2be54(%ebx)\n" /* weaponIndex */
        "movl 0x2be50(%ebx), %eax\n" /* line 2684 | weaponIndex */
        "cmpl %eax, %esi\n" /* iWeaponIndex */
        "je .Lf1d93f0_001d95ef\n"
        "testl %esi, %esi\n" /* line 2687 | iWeaponIndex */
        "jne .Lf1d93f0_001d99aa\n"
        ".Lf1d93f0_001d9822:\n"
        "xorl %ebx, %ebx\n" /* weaponIndex */
        ".Lf1d93f0_001d9824:\n"
        "movl imp_cg, %eax\n" /* line 2689 */
        "movl (%eax), %eax\n"
        "movl %esi, 0x2be50(%eax)\n" /* iWeaponIndex */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "testb %bl, %bl\n" /* line 2692 | weaponIndex */
        "jne .Lf1d93f0_001d95ef\n"
        "jmp .Lf1d93f0_001d9516\n"
        /* { scope 2 */
        ".Lf1d93f0_001d984a:\n"
        "movl $0xffffffff, -0x1c(%ebp)\n" /* line 1907 | step */
        "movl $2, %ebx\n" /* slot */
        "jmp .Lf1d93f0_001d9540\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d93f0_001d985b:\n"
        "movl %eax, (%esp)\n" /* line 2687 */
        "calll BG_GetWeaponDef\n"
        "cmpl 0x36c(%eax), %ebx\n" /* weaponIndex */
        "je .Lf1d93f0_001d9928\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "jmp .Lf1d93f0_001d94f6\n"
        ".Lf1d93f0_001d987a:\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        /* } scope */
        /* { scope 2 */
        ".Lf1d93f0_001d9880:\n"
        "movl (%esi), %eax\n" /* line 1921 */
        "cmpb $0, 0x26118(%ebx, %eax)\n" /* slot */
        "jne .Lf1d93f0_001d958e\n"
        "addl -0x1c(%ebp), %ebx\n" /* line 1918 | step, slot */
        "leal -1(%ebx), %eax\n" /* slot */
        "cmpl $1, %eax\n"
        "jbe .Lf1d93f0_001d9880\n"
        /* } scope */
        ".Lf1d93f0_001d989b:\n"
        "movl -0x30(%ebp), %eax\n" /* line 2083 | bIgnoreEmpty */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %edx\n" /* bNext */
        "movl %edx, (%esp)\n"
        "calll CG_SelectFirstWeaponNotInSlot\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "jmp .Lf1d93f0_001d9690\n"
        ".Lf1d93f0_001d98b8:\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        /* { scope 2 */
        ".Lf1d93f0_001d98be:\n"
        "movl (%esi), %eax\n" /* line 1926 */
        "movzbl 0x26118(%ebx, %eax), %ecx\n" /* weaponIndex */
        "movsbl %cl, %ebx\n" /* weaponIndex */
        /* { scope 3 */
        "movl 0x25bb0(%eax), %edx\n" /* line 2682 */
        "movl %edx, 0x2be54(%eax)\n"
        "movl 0x2be50(%eax), %eax\n" /* line 2684 */
        "cmpl %eax, %ebx\n" /* weaponIndex */
        "je .Lf1d93f0_001d9690\n"
        "testb %cl, %cl\n" /* line 2687 */
        "jne .Lf1d93f0_001d9910\n"
        ".Lf1d93f0_001d98e9:\n"
        "xorl %edi, %edi\n" /* iSlotLooped */
        ".Lf1d93f0_001d98eb:\n"
        "movl (%esi), %eax\n" /* line 2689 | iWeaponIndex */
        "movl %ebx, 0x2be50(%eax)\n" /* weaponIndex */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "movl %edi, %eax\n" /* line 2692 | iSlotLooped */
        "testb %al, %al\n"
        "je .Lf1d93f0_001d9938\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "jmp .Lf1d93f0_001d9690\n"
        ".Lf1d93f0_001d9910:\n"
        "movl %eax, (%esp)\n" /* line 2687 */
        "calll BG_GetWeaponDef\n"
        "cmpl 0x36c(%eax), %ebx\n" /* weaponIndex */
        "je .Lf1d93f0_001d994f\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "jmp .Lf1d93f0_001d98e9\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1d93f0_001d9928:\n"
        "movl $1, %edi\n" /* iSlotLooped */
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "jmp .Lf1d93f0_001d94f8\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1d93f0_001d9938:\n"
        "movl $0, (%esp)\n" /* line 2693 */
        "calll CL_SetADS\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "jmp .Lf1d93f0_001d9690\n"
        ".Lf1d93f0_001d994f:\n"
        "movl $1, %edi\n" /* line 2687 | iSlotLooped */
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "jmp .Lf1d93f0_001d98eb\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1d93f0_001d995c:\n"
        "movl $1, %edi\n" /* iSlotLooped */
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        "jmp .Lf1d93f0_001d95d1\n"
        /* } scope */
        /* } scope */
        ".Lf1d93f0_001d996c:\n"
        "movl %eax, %ebx\n" /* line 2020 | slot */
        "movl imp_cg, %edx\n"
        ".Lf1d93f0_001d9974:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 2024 | iStep */
        "leal 1(%ecx, %ebx), %eax\n"
        "andl $0x80000001, %eax\n"
        "jns .Lf1d93f0_001d998b\n"
        "subl $1, %eax\n"
        "orl $0xfffffffe, %eax\n"
        "addl $1, %eax\n"
        ".Lf1d93f0_001d998b:\n"
        "leal 1(%eax), %ebx\n" /* slot */
        "cmpl %ebx, %edi\n" /* line 2025 | slot, iSlotLooped */
        "je .Lf1d93f0_001d960b\n"
        "movl %edx, %esi\n" /* line 2029 | iWeaponIndex */
        "movl (%edx), %eax\n"
        "cmpb $0, 0x26118(%ebx, %eax)\n" /* slot */
        "jne .Lf1d93f0_001d94c9\n"
        "jmp .Lf1d93f0_001d9974\n"
        ".Lf1d93f0_001d99aa:\n"
        "movl %eax, (%esp)\n" /* line 2687 */
        "calll BG_GetWeaponDef\n"
        "cmpl 0x36c(%eax), %esi\n" /* iWeaponIndex */
        "jne .Lf1d93f0_001d9822\n"
        "movl $1, %ebx\n" /* weaponIndex */
        "jmp .Lf1d93f0_001d9824\n"
        ".Lf1d93f0_001d99c8:\n"
        "movl imp_cg, %esi\n" /* iWeaponIndex */
        /* { scope 2 */
        ".Lf1d93f0_001d99ce:\n"
        "movl (%esi), %eax\n" /* line 1921 */
        "cmpb $0, 0x26118(%ebx, %eax)\n" /* slot */
        "jne .Lf1d93f0_001d98be\n"
        "addl -0x20(%ebp), %ebx\n" /* line 1918 | step, slot */
        "leal -1(%ebx), %eax\n" /* slot */
        "cmpl $1, %eax\n"
        "jbe .Lf1d93f0_001d99ce\n"
        "jmp .Lf1d93f0_001d9690\n"
    );
}

/* line 1781 */
__attribute__((naked))
void CG_OutOfAmmoChange(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1781 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %esi\n" /* line 1786 */
        "movl (%esi), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1d99ee_001d9a91\n"
        "movl 0x25c98(%eax), %eax\n" /* line 1789 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x1c(%ebp)\n" /* weapDef */
        "movl 0x88(%eax), %eax\n" /* line 1791 */
        "testl %eax, %eax\n"
        "jne .Lf1d99ee_001d9a99\n"
        ".Lf1d99ee_001d9a25:\n"
        "movl imp_cg, %edx\n" /* line 1813 */
        "movl (%edx), %ebx\n" /* iNewWeapon */
        "movl $1, 8(%esp)\n"
        "movl 0x25c98(%ebx), %eax\n" /* iNewWeapon */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%ebx), %eax\n" /* iNewWeapon */
        "movl %eax, (%esp)\n"
        "calll BG_IsPlayerWeaponInSlot\n"
        "testl %eax, %eax\n" /* line 1815 */
        "je .Lf1d99ee_001d9a7d\n"
        "xorl %edi, %edi\n"
        "movl $iSlotPreferenceOrder, %esi\n"
        "movl imp_cg, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        /* { scope 2 */
        ".Lf1d99ee_001d9a60:\n"
        "movl (%esi), %eax\n" /* line 1826 */
        "movzbl 0x26118(%eax, %ebx), %eax\n"
        "testb %al, %al\n"
        "jne .Lf1d99ee_001d9b50\n"
        ".Lf1d99ee_001d9a72:\n"
        "addl $1, %edi\n" /* line 1824 | iNewSlot */
        "addl $4, %esi\n"
        "cmpl $2, %edi\n" /* iNewSlot */
        "jne .Lf1d99ee_001d9a60\n"
        /* } scope */
        ".Lf1d99ee_001d9a7d:\n"
        "movl $1, 4(%esp)\n" /* line 1840 */
        "movl $1, (%esp)\n"
        "calll CG_CycleWeap\n"
        /* } scope */
        ".Lf1d99ee_001d9a91:\n"
        "addl $0x2c, %esp\n" /* line 1841 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d99ee_001d9a99:\n"
        "movl $1, %ebx\n" /* line 1791 */
        "movl %esi, %edi\n"
        /* { scope 2 */
        ".Lf1d99ee_001d9aa0:\n"
        "calll BG_GetNumWeapons\n" /* line 1795 */
        "cmpl %ebx, %eax\n" /* iNewWeapon */
        "jl .Lf1d99ee_001d9a25\n"
        "movl %ebx, %eax\n" /* line 1797 | iNewWeapon */
        "sarl $5, %eax\n"
        "movl (%edi), %esi\n"
        "movl %ebx, %ecx\n" /* iNewWeapon */
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1d99ee_001d9acb\n"
        ".Lf1d99ee_001d9ac6:\n"
        "addl $1, %ebx\n" /* line 1795 | iNewWeapon */
        "jmp .Lf1d99ee_001d9aa0\n"
        ".Lf1d99ee_001d9acb:\n"
        "movl %ebx, (%esp)\n" /* line 1799 | iNewWeapon */
        "calll BG_GetWeaponDef\n"
        "movl 0x88(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d99ee_001d9ac6\n"
        "movl %ebx, (%esp)\n" /* line 1801 | iNewWeapon */
        "calll BG_GetWeaponDef\n"
        "movl 0x80(%eax), %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* weapDef */
        "cmpl 0x80(%edx), %eax\n"
        "jne .Lf1d99ee_001d9ac6\n"
        "movl %ebx, 4(%esp)\n" /* line 1804 | iNewWeapon */
        "leal 0x25bc4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_WeaponAmmo\n"
        "testl %eax, %eax\n"
        "je .Lf1d99ee_001d9ac6\n"
        "movl 0x25bb0(%esi), %eax\n" /* line 2682 | weaponIndex */
        "movl %eax, 0x2be54(%esi)\n" /* weaponIndex */
        "movl 0x2be50(%esi), %eax\n" /* line 2684 | weaponIndex */
        "cmpl %eax, %ebx\n" /* iNewWeapon */
        "je .Lf1d99ee_001d9a91\n"
        "testl %ebx, %ebx\n" /* line 2687 | iNewWeapon */
        "jne .Lf1d99ee_001d9be6\n"
        ".Lf1d99ee_001d9b2e:\n"
        "xorl %esi, %esi\n" /* weaponIndex */
        ".Lf1d99ee_001d9b30:\n"
        "movl (%edi), %eax\n" /* line 2689 | iNewSlot */
        "movl %ebx, 0x2be50(%eax)\n" /* iNewWeapon */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "movl %esi, %eax\n" /* line 2692 | weaponIndex */
        "testb %al, %al\n"
        "jne .Lf1d99ee_001d9a91\n"
        "jmp .Lf1d99ee_001d9bbe\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d99ee_001d9b50:\n"
        "movsbl %al, %eax\n" /* line 1829 */
        "movl %eax, 4(%esp)\n"
        "leal 0x25bc4(%ebx), %eax\n" /* iNewWeapon */
        "movl %eax, (%esp)\n"
        "calll BG_WeaponAmmo\n"
        "testl %eax, %eax\n"
        "je .Lf1d99ee_001d9a72\n"
        "movl iSlotPreferenceOrder(, %edi, 4), %eax\n" /* line 1831 */
        "movzbl 0x26118(%eax, %ebx), %edx\n"
        "movsbl %dl, %esi\n" /* weaponIndex */
        /* { scope 3 */
        "movl 0x25bb0(%ebx), %eax\n" /* line 2682 | iNewWeapon */
        "movl %eax, 0x2be54(%ebx)\n" /* iNewWeapon */
        "movl 0x2be50(%ebx), %eax\n" /* line 2684 | iNewWeapon */
        "cmpl %eax, %esi\n" /* weaponIndex */
        "je .Lf1d99ee_001d9a91\n"
        "testb %dl, %dl\n" /* line 2687 */
        "jne .Lf1d99ee_001d9bcf\n"
        ".Lf1d99ee_001d9b9d:\n"
        "xorl %ebx, %ebx\n" /* iNewWeapon */
        ".Lf1d99ee_001d9b9f:\n"
        "movl -0x20(%ebp), %edx\n" /* line 2689 */
        "movl (%edx), %eax\n"
        "movl %esi, 0x2be50(%eax)\n" /* weaponIndex */
        "movl $1, (%esp)\n" /* line 2690 */
        "calll CG_MenuShowNotify\n"
        "testb %bl, %bl\n" /* line 2692 | iNewWeapon */
        "jne .Lf1d99ee_001d9a91\n"
        ".Lf1d99ee_001d9bbe:\n"
        "movl $0, (%esp)\n" /* line 2693 */
        "calll CL_SetADS\n"
        "jmp .Lf1d99ee_001d9a91\n"
        ".Lf1d99ee_001d9bcf:\n"
        "movl %eax, (%esp)\n" /* line 2687 */
        "calll BG_GetWeaponDef\n"
        "cmpl 0x36c(%eax), %esi\n" /* weaponIndex */
        "jne .Lf1d99ee_001d9b9d\n"
        "movl $1, %ebx\n" /* iNewWeapon */
        "jmp .Lf1d99ee_001d9b9f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1d99ee_001d9be6:\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "cmpl 0x36c(%eax), %ebx\n" /* iNewWeapon */
        "jne .Lf1d99ee_001d9b2e\n"
        "movl $1, %esi\n" /* weaponIndex */
        "jmp .Lf1d99ee_001d9b30\n"
    );
}

/* line 1743 */
__attribute__((naked))
void CG_PrevWeapon_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1743 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "calll CG_ScoreboardDisplayed\n" /* line 1745 */
        "testl %eax, %eax\n"
        "jne .Lf1d9c04_001d9c53\n"
        "movl imp_cg, %eax\n" /* line 1751 */
        "movl (%eax), %ecx\n"
        "movl 0x24(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d9c04_001d9c4d\n"
        "cmpw $0, 0x25bd0(%ecx)\n" /* line 1755 */
        "js .Lf1d9c04_001d9c4d\n"
        "testb $0x80, 0x1a(%eax)\n" /* line 1758 */
        "je .Lf1d9c04_001d9c4d\n"
        "movl 0x25bb0(%ecx), %ebx\n" /* line 1761 */
        "movl %ebx, %eax\n"
        "subl 0x2be54(%ecx), %eax\n"
        "movl imp_cg_weaponCycleDelay, %edx\n"
        "movl (%edx), %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jge .Lf1d9c04_001d9c5d\n"
        ".Lf1d9c04_001d9c4d:\n"
        "addl $0x14, %esp\n" /* line 1771 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d9c04_001d9c53:\n"
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp CG_ScrollScoreboardDown\n" /* line 1747 */
        ".Lf1d9c04_001d9c5d:\n"
        "movl %ebx, 0x2be54(%ecx)\n" /* line 1764 */
        "movl $0, 4(%esp)\n" /* line 1770 */
        "movl $0, (%esp)\n"
        "calll CG_CycleWeap\n"
        "addl $0x14, %esp\n" /* line 1771 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1700 */
__attribute__((naked))
void CG_NextWeapon_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1700 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "calll CG_ScoreboardDisplayed\n" /* line 1702 */
        "testl %eax, %eax\n"
        "jne .Lf1d9c7e_001d9ccd\n"
        "movl imp_cg, %eax\n" /* line 1708 */
        "movl (%eax), %ecx\n"
        "movl 0x24(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d9c7e_001d9cc7\n"
        "cmpw $0, 0x25bd0(%ecx)\n" /* line 1712 */
        "js .Lf1d9c7e_001d9cc7\n"
        "testb $0x80, 0x1a(%eax)\n" /* line 1715 */
        "je .Lf1d9c7e_001d9cc7\n"
        "movl 0x25bb0(%ecx), %ebx\n" /* line 1718 */
        "movl %ebx, %eax\n"
        "subl 0x2be54(%ecx), %eax\n"
        "movl imp_cg_weaponCycleDelay, %edx\n"
        "movl (%edx), %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jge .Lf1d9c7e_001d9cd7\n"
        ".Lf1d9c7e_001d9cc7:\n"
        "addl $0x14, %esp\n" /* line 1735 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d9c7e_001d9ccd:\n"
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp CG_ScrollScoreboardUp\n" /* line 1704 */
        ".Lf1d9c7e_001d9cd7:\n"
        "movl %ebx, 0x2be54(%ecx)\n" /* line 1721 */
        "movl $0, 4(%esp)\n" /* line 1734 */
        "movl $1, (%esp)\n"
        "calll CG_CycleWeap\n"
        "addl $0x14, %esp\n" /* line 1735 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 128 */
__attribute__((naked))
void CG_WeaponRunXModelAnims(weapProjExposion_t (*ps)[8], weaponInfo_t *weapInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 128 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 138 | weapInfo */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetTree\n"
        "movl %eax, -0x1c(%ebp)\n" /* pAnimTree */
        "movl 8(%ebp), %eax\n" /* line 140 | ps */
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, %ebx\n" /* weaponIndex */
        "movl %eax, (%esp)\n" /* line 144 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ecx\n"
        "movl 8(%ebp), %edx\n" /* line 147 | ps */
        "cmpl $5, 0xd8(%edx)\n"
        "je .Lf1d9cf8_001d9ea8\n"
        ".Lf1d9cf8_001d9d38:\n"
        "movl 0xc(%edx), %eax\n" /* line 149 */
        "testb $0x40, %al\n"
        "jne .Lf1d9cf8_001d9e8a\n"
        ".Lf1d9cf8_001d9d43:\n"
        "xorl %edx, %edx\n"
        ".Lf1d9cf8_001d9d45:\n"
        "testb $0x10, %al\n" /* line 152 */
        "movl $0, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl 0x32c(%ecx), %esi\n" /* line 156 | i */
        "testl %esi, %esi\n" /* i */
        "je .Lf1d9cf8_001d9d70\n"
        "testl %edx, %edx\n" /* line 158 */
        "jne .Lf1d9cf8_001d9e94\n"
        "movl $0x16, %ecx\n" /* line 164 */
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %ebx, %eax\n" /* weaponIndex */
        "calll CG_PlayADSAnim\n"
        ".Lf1d9cf8_001d9d70:\n"
        "movl 8(%ebp), %edx\n" /* line 169 | ps */
        "movl 0x5d0(%edx), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* weapInfo */
        "cmpl 0xa0(%edx), %eax\n"
        "je .Lf1d9cf8_001d9e7b\n"
        "andb $0xfd, %ah\n" /* line 171 */
        "cmpl $0x13, %eax\n"
        "jbe .Lf1d9cf8_001d9e83\n"
        /* { scope 2 */
        ".Lf1d9cf8_001d9d94:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001d9dfa\n"
        ".Lf1d9cf8_001d9db1:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e4d\n"
        ".Lf1d9cf8_001d9dfa:\n"
        "cmpw $1, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001d9db1\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "addl $4, %ebx\n" /* line 53 */
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "jne .Lf1d9cf8_001d9dfa\n"
        /* } scope */
        ".Lf1d9cf8_001d9e4d:\n"
        "movl 8(%ebp), %edx\n" /* line 266 | ps */
        "movl 0x5d0(%edx), %eax\n"
        "andb $0xfd, %ah\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b7ea0, (%esp)\n" /* "CG_WeaponRunXModelAnims: Unknown weapon animation %i
" */
        "calll Com_Printf\n"
        ".Lf1d9cf8_001d9e69:\n"
        "movl 8(%ebp), %edx\n" /* line 270 | ps */
        "movl 0x5d0(%edx), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* weapInfo */
        "movl %eax, 0xa0(%edx)\n"
        /* } scope */
        ".Lf1d9cf8_001d9e7b:\n"
        "addl $0x3c, %esp\n" /* line 272 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d9cf8_001d9e83:\n"
        "jmpl *.Ljt_1d9cf8_0(, %eax, 4)\n" /* line 171 */
        ".Lf1d9cf8_001d9e8a:\n"
        "movl $1, %edx\n" /* line 149 */
        "jmp .Lf1d9cf8_001d9d45\n"
        ".Lf1d9cf8_001d9e94:\n"
        "movl $0x15, %ecx\n" /* line 160 */
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %ebx, %eax\n" /* weaponIndex */
        "calll CG_PlayADSAnim\n"
        "jmp .Lf1d9cf8_001d9d70\n"
        ".Lf1d9cf8_001d9ea8:\n"
        "movl 0x34(%edx), %eax\n" /* line 147 */
        "subl 0x524(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1d9cf8_001d9ec0\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "movl 0xc(%edx), %eax\n"
        "jmp .Lf1d9cf8_001d9d43\n"
        ".Lf1d9cf8_001d9ec0:\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "jmp .Lf1d9cf8_001d9d38\n"
        ".Lf1d9cf8_001d9ec8:\n"
        "movl $1, %esi\n" /* line 171 | i */
        "jmp .Lf1d9cf8_001d9edb\n"
        ".Lf1d9cf8_001d9ecf:\n"
        "addl $1, %esi\n" /* line 176 | i */
        "cmpl $0x15, %esi\n" /* i */
        "je .Lf1d9cf8_001daba8\n"
        ".Lf1d9cf8_001d9edb:\n"
        "movl %esi, 4(%esp)\n" /* line 178 | i */
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimHasFinished\n"
        "testb %al, %al\n"
        "jne .Lf1d9cf8_001d9ecf\n"
        "movl 0xc(%ebp), %eax\n" /* line 180 | weapInfo */
        "movl $0xffffffff, 0xa0(%eax)\n"
        "jmp .Lf1d9cf8_001d9e7b\n"
        /* { scope 2 */
        ".Lf1d9cf8_001d9f00:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001d9f6a\n"
        ".Lf1d9cf8_001d9f1d:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001d9f5b:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001d9f6a:\n"
        "cmpw $4, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001d9f1d\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001d9f5b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001d9fb4:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da01e\n"
        ".Lf1d9cf8_001d9fd1:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da00f:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da01e:\n"
        "cmpw $0x10, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001d9fd1\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da00f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da068:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da0d2\n"
        ".Lf1d9cf8_001da085:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da0c3:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da0d2:\n"
        "cmpw $0x11, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da085\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x48(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x11, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da0c3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da11c:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da186\n"
        ".Lf1d9cf8_001da139:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da177:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da186:\n"
        "cmpw $0xe, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da139\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da177\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da1d0:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da23a\n"
        ".Lf1d9cf8_001da1ed:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da22b:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da23a:\n"
        "cmpw $0xf, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da1ed\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x40(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0xf, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da22b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da284:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da2ee\n"
        ".Lf1d9cf8_001da2a1:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da2df:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da2ee:\n"
        "cmpw $0xb, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da2a1\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x30(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0xb, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da2df\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da338:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da3a2\n"
        ".Lf1d9cf8_001da355:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da393:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da3a2:\n"
        "cmpw $0xa, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da355\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x2c(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0xa, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da393\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da3ec:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da456\n"
        ".Lf1d9cf8_001da409:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da447:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da456:\n"
        "cmpw $9, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da409\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x28(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $9, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da447\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da4a0:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da50a\n"
        ".Lf1d9cf8_001da4bd:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da4fb:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da50a:\n"
        "cmpw $8, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da4bd\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x24(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da4fb\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da554:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da5be\n"
        ".Lf1d9cf8_001da571:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da5af:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da5be:\n"
        "cmpw $0xc, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da571\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x34(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da5af\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da608:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da672\n"
        ".Lf1d9cf8_001da625:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da663:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da672:\n"
        "cmpw $0xd, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da625\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x38(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0xd, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da663\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da6bc:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da726\n"
        ".Lf1d9cf8_001da6d9:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da717:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da726:\n"
        "cmpw $7, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da6d9\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x20(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $7, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da717\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da770:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da7da\n"
        ".Lf1d9cf8_001da78d:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da7cb:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da7da:\n"
        "cmpw $0x14, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da78d\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x54(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x14, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da7cb\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001da824:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da88e\n"
        ".Lf1d9cf8_001da841:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da87f:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da88e:\n"
        "cmpw $0x13, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da841\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x50(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da87f\n"
        /* } scope */
        ".Lf1d9cf8_001da8d8:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da942\n"
        ".Lf1d9cf8_001da8f5:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da933:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da942:\n"
        "cmpw $0x12, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da8f5\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x12, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da933\n"
        /* { scope 2 */
        ".Lf1d9cf8_001da98c:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001da9f6\n"
        ".Lf1d9cf8_001da9a9:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001da9e7:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001da9f6:\n"
        "cmpw $6, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001da9a9\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $6, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001da9e7\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d9cf8_001daa40:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001daaaa\n"
        ".Lf1d9cf8_001daa5d:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001daa9b:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001daaaa:\n"
        "cmpw $5, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001daa5d\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $5, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001daa9b\n"
        /* } scope */
        ".Lf1d9cf8_001daaf4:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001dab5e\n"
        ".Lf1d9cf8_001dab11:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001dab4f:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001dab5e:\n"
        "cmpw $3, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001dab11\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001dab4f\n"
        ".Lf1d9cf8_001daba8:\n"
        "movl %ebx, (%esp)\n" /* line 186 | weaponIndex */
        "calll BG_ClipForWeapon\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "movl 0x344(%edx, %eax, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1d9cf8_001dac75\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movw $1, %si\n"
        "jmp .Lf1d9cf8_001dac2b\n"
        ".Lf1d9cf8_001dabde:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001dac1c:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001dac2b:\n"
        "cmpw $2, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001dabde\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001dac1c\n"
        ".Lf1d9cf8_001dac75:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 43 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* weapInfo */
        "movl %edi, %ebx\n" /* weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1d9cf8_001dacdf\n"
        ".Lf1d9cf8_001dac92:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1d9cf8_001dacd0:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1d9cf8_001d9e69\n"
        ".Lf1d9cf8_001dacdf:\n"
        "cmpw $1, %si\n" /* line 50 */
        "jne .Lf1d9cf8_001dac92\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%edi), %eax\n" /* weapInfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1d9cf8_001dacd0\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_1d9cf8_0:\n"
        ".long .Lf1d9cf8_001d9ec8\n"
        ".long .Lf1d9cf8_001d9d94\n"
        ".long .Lf1d9cf8_001daaf4\n"
        ".long .Lf1d9cf8_001daa40\n"
        ".long .Lf1d9cf8_001da98c\n"
        ".long .Lf1d9cf8_001da8d8\n"
        ".long .Lf1d9cf8_001da824\n"
        ".long .Lf1d9cf8_001da770\n"
        ".long .Lf1d9cf8_001da6bc\n"
        ".long .Lf1d9cf8_001da608\n"
        ".long .Lf1d9cf8_001da554\n"
        ".long .Lf1d9cf8_001da4a0\n"
        ".long .Lf1d9cf8_001da3ec\n"
        ".long .Lf1d9cf8_001da338\n"
        ".long .Lf1d9cf8_001da284\n"
        ".long .Lf1d9cf8_001da1d0\n"
        ".long .Lf1d9cf8_001da11c\n"
        ".long .Lf1d9cf8_001da068\n"
        ".long .Lf1d9cf8_001d9fb4\n"
        ".long .Lf1d9cf8_001d9f00\n"
        ".text\n"
    );
}

/* line 1475 */
__attribute__((naked))
void CG_UpdateViewWeaponAnim(weapProjExposion_t (*ps)[8])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1475 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1: weapInfo */
        "movl 8(%ebp), %eax\n" /* line 1481 | ps */
        "cmpl $5, 4(%eax)\n"
        "jle .Lf1dad2a_001daf52\n"
        "movl $1, -0x48(%ebp)\n" /* weaponNum */
        "movl $0x1b4, -0x3c(%ebp)\n"
        /* { scope 2: weaponNum */
        "calll BG_GetNumWeapons\n" /* line 286 */
        "cmpl %eax, -0x48(%ebp)\n" /* weaponNum */
        "jg .Lf1dad2a_001daeb0\n"
        ".Lf1dad2a_001dad5c:\n"
        "movl imp_cg_weapons, %eax\n" /* line 288 */
        "movl -0x3c(%ebp), %edx\n"
        "addl (%eax), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* weapInfo */
        "movl (%edx), %eax\n" /* line 289 */
        "testl %eax, %eax\n"
        "je .Lf1dad2a_001dae97\n"
        "movl %eax, (%esp)\n" /* line 292 */
        "calll DObjGetTree\n"
        "movl %eax, %edi\n"
        "movl $0, 8(%esp)\n" /* line 295 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimClearTreeGoalWeights\n"
        "movl $0, 0x1c(%esp)\n" /* line 296 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0x4c(%ebp), %edx\n" /* weapInfo */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl -0x48(%ebp), %eax\n" /* line 298 | weaponNum */
        "movl %eax, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "movl 0x344(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1dad2a_001daeb8\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 43 | weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1dad2a_001dae44\n"
        ".Lf1dad2a_001dadfe:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1dad2a_001dae97\n"
        ".Lf1dad2a_001dae44:\n"
        "cmpw $2, %si\n" /* line 50 */
        "jne .Lf1dad2a_001dadfe\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0x4c(%ebp), %edx\n" /* weapInfo */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "addl $4, %ebx\n" /* line 53 */
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "jne .Lf1dad2a_001dae44\n"
        ".Lf1dad2a_001dae97:\n"
        "addl $1, -0x48(%ebp)\n" /* line 286 | weaponNum */
        "addl $0x1b4, -0x3c(%ebp)\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, -0x48(%ebp)\n" /* weaponNum */
        "jle .Lf1dad2a_001dad5c\n"
        /* } scope */
        /* } scope */
        ".Lf1dad2a_001daeb0:\n"
        "addl $0x6c, %esp\n" /* line 1508 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: weapInfo */
        /* { scope 2: weaponNum */
        /* { scope 3 */
        ".Lf1dad2a_001daeb8:\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 43 | weapInfo */
        "movl $1, %esi\n"
        "jmp .Lf1dad2a_001daf08\n"
        ".Lf1dad2a_001daec2:\n"
        "movl $0, 0x1c(%esp)\n" /* line 53 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1dad2a_001daefd:\n"
        "addl $4, %ebx\n"
        "addl $1, %esi\n"
        "cmpl $0x15, %esi\n" /* line 48 */
        "je .Lf1dad2a_001dae97\n"
        ".Lf1dad2a_001daf08:\n"
        "cmpw $1, %si\n" /* line 50 */
        "jne .Lf1dad2a_001daec2\n"
        "movl $1, 0x1c(%esp)\n" /* line 51 */
        "movl $1, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0x4c(%ebp), %edx\n" /* weapInfo */
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1dad2a_001daefd\n"
        /* } scope */
        /* } scope */
        ".Lf1dad2a_001daf52:\n"
        "movl %eax, (%esp)\n" /* line 1487 */
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, %ebx\n" /* weaponIndex */
        "testl %eax, %eax\n" /* line 1488 */
        "jle .Lf1dad2a_001daeb0\n"
        "movl %eax, (%esp)\n" /* line 1491 */
        "calll CG_RegisterWeapon\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1492 | weaponIndex */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* weaponIndex */
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "movl %edx, -0x50(%ebp)\n"
        "leal (%edx, %eax, 4), %ebx\n" /* weaponIndex */
        "movl %ebx, 4(%esp)\n" /* line 1495 | weaponIndex */
        "movl 8(%ebp), %edx\n" /* ps */
        "movl %edx, (%esp)\n"
        "calll CG_WeaponRunXModelAnims\n"
        "movl imp_cg, %eax\n" /* line 1498 */
        "movl (%eax), %edi\n" /* pAnimTree */
        "cvtsi2ssl 0x25bac(%edi), %xmm0\n" /* pAnimTree */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* weaponIndex */
        "movl %eax, (%esp)\n"
        "calll DObjUpdateClientInfo\n"
        "leal -0x2c(%ebp), %esi\n" /* line 1499 | partBits */
        "movl $0xffffffff, -0x2c(%ebp)\n" /* partBits */
        "movl $0xffffffff, -0x28(%ebp)\n"
        "movl $0xffffffff, -0x24(%ebp)\n"
        "movl $0xffffffff, -0x20(%ebp)\n"
        "movl $0, 8(%esp)\n" /* line 1500 */
        "movl %esi, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* weaponIndex */
        "movl %eax, (%esp)\n"
        "calll CL_DObjCreateSkelForBones\n"
        "testl %eax, %eax\n"
        "je .Lf1dad2a_001db0a1\n"
        ".Lf1dad2a_001daff6:\n"
        "leal 0x25bc4(%edi), %eax\n" /* line 96 */
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 98 */
        "je .Lf1dad2a_001daeb0\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 103 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl -0x50(%ebp), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "leal -0x1c(%ebp), %eax\n" /* line 104 */
        "movl %eax, (%esp)\n"
        "calll DObjGetClientNotifyList\n"
        "movl %eax, -0x40(%ebp)\n"
        "testl %eax, %eax\n" /* line 106 */
        "jle .Lf1dad2a_001daeb0\n"
        "xorl %edi, %edi\n"
        "xorl %esi, %esi\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf1dad2a_001db062\n"
        ".Lf1dad2a_001db03e:\n"
        "movl -0x44(%ebp), %eax\n" /* line 109 */
        "movl 0x124(%eax), %edi\n"
        ".Lf1dad2a_001db047:\n"
        "testl %edi, %edi\n" /* line 117 */
        "je .Lf1dad2a_001db053\n"
        "movl %edi, (%esp)\n" /* line 118 */
        "calll CG_PlayClientSoundAlias\n"
        ".Lf1dad2a_001db053:\n"
        "addl $1, %esi\n" /* line 106 */
        "addl $0xc, %ebx\n"
        "cmpl %esi, -0x40(%ebp)\n"
        "je .Lf1dad2a_001daeb0\n"
        ".Lf1dad2a_001db062:\n"
        "movl $str_00220658, 4(%esp)\n" /* line 108 */
        "movl -0x1c(%ebp), %eax\n"
        "movl (%eax, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1dad2a_001db03e\n"
        "movl $str_00220668, 4(%esp)\n" /* line 110 */
        "movl -0x1c(%ebp), %eax\n"
        "movl (%eax, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dad2a_001db0c2\n"
        "movl -0x44(%ebp), %edx\n" /* line 111 */
        "movl 0x128(%edx), %edi\n"
        "jmp .Lf1dad2a_001db047\n"
        ".Lf1dad2a_001db0a1:\n"
        "movl %esi, 4(%esp)\n" /* line 1502 */
        "movl (%ebx), %eax\n" /* weaponIndex */
        "movl %eax, (%esp)\n"
        "calll DObjCalcAnim\n"
        "movl %esi, 4(%esp)\n" /* line 1503 */
        "movl (%ebx), %eax\n" /* weaponIndex */
        "movl %eax, (%esp)\n"
        "calll DObjCalcSkel\n"
        "jmp .Lf1dad2a_001daff6\n"
        ".Lf1dad2a_001db0c2:\n"
        "movl $str_00220678, 4(%esp)\n" /* line 112 */
        "movl -0x1c(%ebp), %eax\n"
        "movl (%eax, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dad2a_001db0ea\n"
        "movl -0x44(%ebp), %eax\n" /* line 113 */
        "movl 0x12c(%eax), %edi\n"
        "jmp .Lf1dad2a_001db047\n"
        ".Lf1dad2a_001db0ea:\n"
        "movl $str_00220688, 4(%esp)\n" /* line 114 */
        "movl -0x1c(%ebp), %eax\n"
        "movl (%eax, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dad2a_001db047\n"
        "movl -0x44(%ebp), %edx\n" /* line 115 */
        "movl 0x130(%edx), %edi\n"
        "jmp .Lf1dad2a_001db047\n"
    );
}

#else
void CG_Weapons_SetToDefault(int weaponNum, weaponInfo_s (*dobjModels)[4]) {
    byte *weapDef;
    char modelFile[80]; /* 0x58 bytes local */
    const char *handModel;
    const char *viewModel;

    CG_SetWeaponDefToDefaultWeapon(weaponNum);
    weapDef = (byte *)BG_GetWeaponDef(weaponNum);
    Com_Printf("WARNING: gun and/or hand model file for weapon [%s] could not be found\n",
               *(const char **)(weapDef + 4));

    handModel = *(const char **)(weapDef + 0xc);
    if (!handModel || handModel[0] == '\0') {
        Com_Error(1, "could not find default weapon model");
    } else {
        viewModel = *(const char **)(weapDef + 0x10);
        if (!viewModel || viewModel[0] == '\0') {
            Com_Error(1, "could not find default weapon model");
        }
    }

    viewModel = *(const char **)(weapDef + 0x10);
    sprintf(modelFile, "%s%s", "xmodel/", viewModel);
    *(void **)dobjModels = CL_RegisterModel(modelFile);

    handModel = *(const char **)(weapDef + 0xc);
    sprintf(modelFile, "%s%s", "xmodel/", handModel);
    *(void **)((byte *)dobjModels + 0xc) = CL_RegisterModel(modelFile);
}
#endif
