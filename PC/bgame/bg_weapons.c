/* ASM dump from: bg_weapons.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_weapons.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 */

extern int bg_iNumWeapons; /* 0x0 */
extern WeaponDef * bg_weaponDefs[128]; /* 0x0 */
static WeaponDef * bg_weapAmmoTypes[128]; /* 0x4ea720 */
static int bg_iNumAmmoTypes; /* 0x4ea700 */
static WeaponDef * bg_sharedAmmoCaps[128]; /* 0x4ea940 */
static int bg_iNumSharedAmmoCaps; /* 0x4ea920 */
static WeaponDef * bg_weapClips[128]; /* 0x4eab60 */
static int bg_iNumWeapClips; /* 0x4eab40 */

void BG_ShutdownWeaponDefFiles(void);
WeaponDef * BG_GetWeaponDef(int iWeapon);
void BG_ClearWeaponDef(void);
int BG_GetNumWeapons(void);
int BG_GetAmmoTypeMax(int iAmmoIndex);
int BG_GetAmmoClipSize(int iClipIndex);
int BG_FindWeaponIndexForName(const char *name);
Bool BG_IsAnyEmptyPrimaryWeaponSlot(const playerState_t *ps);
Bool PM_IsBinocularsADS(const playerState_t *ps);
void PM_ExitAimDownSight(playerState_t *ps);
float BG_GetBobCycle(const playerState_t *ps);
float BG_GetVerticalBobFactor(const playerState_t *ps, float cycle, float speed, float maxAmp);
float BG_GetHorizontalBobFactor(const playerState_t *ps, float cycle, float speed, float maxAmp);
static void BG_SetupClipIndexes(int weapIndex);
static void BG_SetupSharedAmmoIndexes(int weapIndex);
static void BG_SetupAmmoIndexes(int weapIndex);
qboolean BG_IsAimDownSightWeapon(int iWeapon);
Bool BG_DoesWeaponRequireSlot(int weaponIndex);
Bool BG_DoesWeaponNeedSlot(int weapIndex);
int BG_GetEmptySlotForWeapon(const playerState_t *pPS, int iWeaponIndex);
int BG_GetStackSlotForWeapon(const playerState_t *pPS, int iWeaponIndex, weapSlot_t preferedSlot);
qboolean BG_IsPlayerWeaponAnAlt(int iWeaponIndex, int iAltIndex);
void BG_GetSpreadForWeapon(const playerState_t *ps, int weaponIndex, float *minSpread, float *maxSpread);
int BG_ClipForWeapon(int weapon);
int BG_AmmoForWeapon(int weapon);
qboolean BG_WeaponIsClipOnly(int weapon);
int PM_WeaponAmmoAvailable(playerState_t *ps);
int BG_WeaponAmmo(const playerState_t *ps, int weapon);
int BG_IsPlayerWeaponInSlot(const playerState_t *pPS, int iWeaponIndex, qboolean bAnyMode);
int BG_GetTotalAmmoReserve(const playerState_t *ps, int weaponIndex);
static void PM_ReloadClip(void);
static qboolean PM_Weapon_AllowReload(void);
int BG_GetFirstEquippedOffhand(const playerState_t *ps, int offhandClass);
void PM_AdjustAimSpreadScale(pmove_t *pm, pml_t *pml);
static qboolean BG_CalculateWeaponPosition_GunRecoil_SingleAngle(float fGunKickSpeedMax, float fGunKickSpeedDecay, float fGunKickStaticDecay);
static void PM_Weapon_ReloadDelayedAction(void);
int BG_GetViewmodelWeaponIndex(const playerState_t *ps);
void BG_WeaponFireRecoil(const playerState_t *ps, vec_t *vGunSpeed, vec_t *kickAVel);
void BG_CalculateWeaponPosition_Sway(playerState_t *ps, vec_t *swayViewAngles, vec_t *swayOffset, vec_t *swayAngles, float ssSwayScale, int frametime);
int BG_GetFirstAvailableOffhand(const playerState_t *ps, int offhandClass);
int BG_GetMaxPickupableAmmo(const playerState_t *ps, int weaponIndex);
void PM_UpdateAimDownSightFlag(pmove_t *pm, pml_t *pml);
Bool BG_IsWeaponValid(const playerState_t *ps, int weaponIndex);
qboolean BG_TakePlayerWeapon(playerState_t *pPS, int iWeaponIndex);
static void PM_BeginWeaponChange(void);
static void PM_SetReloadingState(void);
static void PM_BeginWeaponReload(void);
void PM_UpdateAimDownSightLerp(pmove_t *pm, pml_t *pml);
void PM_ResetWeaponState(playerState_t *ps);
qboolean PM_InteruptWeaponWithProneMove(playerState_t *ps);
void PM_Weapon(pmove_t *pm, pml_t *pml);
int BG_GetWeaponIndexForName(const char *name, BG_RegisterWeapon regWeap);
void BG_FillInAmmoItems(BG_RegisterWeapon regWeap);
void CG_SetWeaponDefToDefaultWeapon(int iWeapon);
void BG_CalculateWeaponAngles(weaponState_t *ws, vec_t *angles);
void BG_CalculateViewAngles(viewState_t *vs, vec_t *angles);

/* line 67 */
void BG_ShutdownWeaponDefFiles(void)
{
    bg_iNumWeapons = 0;
}

/* line 517 */
WeaponDef * BG_GetWeaponDef(int iWeapon)
{
    return bg_weaponDefs[iWeapon];
}

/* line 376 */
__attribute__((naked))
void BG_ClearWeaponDef(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 376 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll BG_LoadDefaultWeaponDef\n" /* line 382 */
        "movl %eax, bg_weaponDefs\n"
        "movl %eax, bg_weapAmmoTypes\n" /* line 384 */
        "movl $1, bg_iNumAmmoTypes\n" /* line 385 */
        "movl %eax, bg_sharedAmmoCaps\n" /* line 387 */
        "movl $1, bg_iNumSharedAmmoCaps\n" /* line 388 */
        "movl %eax, bg_weapClips\n" /* line 390 */
        "movl $1, bg_iNumWeapClips\n" /* line 391 */
        "movl 0x195eda8, %eax\n"
        "leal 0x1600(%eax), %edx\n"
        ".Lf7a6b8_0007a700:\n"
        "movl $0, 0x48(%eax)\n" /* line 394 */
        "addl $0x2c, %eax\n"
        "cmpl %eax, %edx\n" /* line 393 */
        "jne .Lf7a6b8_0007a700\n"
        "calll BG_LoadPlayerAnimTypes\n" /* line 402 */
        "leave\n" /* line 407 */
        "jmp BG_InitWeaponStrings\n" /* line 405 */
    );
}

/* line 558 */
int BG_GetNumWeapons(void)
{
    return bg_iNumWeapons;
}

/* line 580 */
int BG_GetAmmoTypeMax(int iAmmoIndex)
{
    return *(int *)((byte *)bg_weapAmmoTypes[iAmmoIndex] + 0x1d4);
}

/* line 604 */
int BG_GetAmmoClipSize(int iClipIndex)
{
    return *(int *)((byte *)bg_weapClips[iClipIndex] + 0x1d8);
}

/* line 713 */
__attribute__((naked))
int BG_FindWeaponIndexForName(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 713 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "movl bg_iNumWeapons, %ecx\n" /* line 717 */
        "testl %ecx, %ecx\n"
        "jg .Lf7a754_0007a776\n"
        ".Lf7a754_0007a76a:\n"
        "xorl %ebx, %ebx\n" /* weapIndex */
        /* } scope */
        ".Lf7a754_0007a76c:\n"
        "movl %ebx, %eax\n" /* line 724 | weapIndex */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7a754_0007a776:\n"
        "movl $1, %ebx\n" /* line 717 | weapIndex */
        "movl $bg_weaponDefs, %esi\n"
        ".Lf7a754_0007a780:\n"
        "movl 4(%esi), %eax\n" /* line 719 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* name */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf7a754_0007a76c\n"
        "addl $1, %ebx\n" /* line 717 | weapIndex */
        "addl $4, %esi\n"
        "cmpl bg_iNumWeapons, %ebx\n" /* weapIndex */
        "jle .Lf7a754_0007a780\n"
        "jmp .Lf7a754_0007a76a\n"
    );
}

/* line 889 */
Bool BG_IsAnyEmptyPrimaryWeaponSlot(const playerState_t *ps)
{
    return *(byte *)((byte *)ps + 0x555) == 0 || *(byte *)((byte *)ps + 0x556) == 0;
}

/* line 1425 */
Bool PM_IsBinocularsADS(const playerState_t *ps)
{
    int val = *(int *)((byte *)ps + 0xd8) - 0x13;
    return (unsigned int)val <= 1;
}

/* line 1482 */
__attribute__((naked))
void PM_ExitAimDownSight(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1482 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ps */
        "movl $0x95, 4(%esp)\n" /* line 1484 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        "andl $0xffffffbf, 0xc(%ebx)\n" /* line 1485 | ps */
        "addl $0x14, %esp\n" /* line 1486 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4071 */
float BG_GetBobCycle(const playerState_t *ps)
{
    double val = (float)(*(unsigned char *)((byte *)ps + 8)) / 255.0f;
    return (float)(val * 3.141592653589793 * 2.0 + 6.283185307179586);
}

/* line 4088 */
__attribute__((naked))
float BG_GetVerticalBobFactor(const playerState_t *ps, float cycle, float speed, float maxAmp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4088 */
        "movl %esp, %ebp\n"
        "subl $0x68, %esp\n"
        "movss 0xc(%ebp), %xmm3\n" /* cycle */
        "movss 0x10(%ebp), %xmm0\n" /* speed */
        "movss 0x14(%ebp), %xmm1\n" /* maxAmp */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 4092 | ps */
        "movl 0xf4(%eax), %eax\n"
        "cmpl $0xb, %eax\n"
        "je .Lf7a848_0007a90a\n"
        "cmpl $0x28, %eax\n" /* line 4094 */
        "je .Lf7a848_0007a91e\n"
        "movl 0x195ee3c, %eax\n" /* line 4097 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        ".Lf7a848_0007a887:\n"
        "minss %xmm2, %xmm1\n" /* line 4099 */
        "movaps %xmm3, %xmm0\n" /* line 4102 */
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movss %xmm3, -0x48(%ebp)\n"
        "calll sinf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "movss -0x48(%ebp), %xmm3\n"
        "mulss 0x2ed608, %xmm3\n" /* 4.0f */
        "cvtss2sd %xmm3, %xmm0\n"
        "addsd 0x307ca0, %xmm0\n" /* 1.5707963267948966 */
        "movsd %xmm0, (%esp)\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "calll sin\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n"
        "mulss 0x2ed724, %xmm0\n" /* 0.20000000298023224f */
        "movss -0x28(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "mulss 0x2ed67c, %xmm1\n" /* 0.75f */
        "movss -0x38(%ebp), %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        /* } scope */
        "movss %xmm2, -0x4c(%ebp)\n" /* line 4103 */
        "flds -0x4c(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7a848_0007a90a:\n"
        "movl 0x195ee28, %eax\n" /* line 4093 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "jmp .Lf7a848_0007a887\n"
        ".Lf7a848_0007a91e:\n"
        "movl 0x195ee34, %eax\n" /* line 4095 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "jmp .Lf7a848_0007a887\n"
    );
}

/* line 4113 */
__attribute__((naked))
float BG_GetHorizontalBobFactor(const playerState_t *ps, float cycle, float speed, float maxAmp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4113 */
        "movl %esp, %ebp\n"
        "subl $0x48, %esp\n"
        "movss 0x10(%ebp), %xmm0\n" /* speed */
        "movss 0x14(%ebp), %xmm1\n" /* maxAmp */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 4117 | ps */
        "movl 0xf4(%eax), %eax\n"
        "cmpl $0xb, %eax\n"
        "je .Lf7a932_0007a98c\n"
        "cmpl $0x28, %eax\n" /* line 4119 */
        "je .Lf7a932_0007a99a\n"
        "movl 0x195ee3c, %eax\n" /* line 4122 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        ".Lf7a932_0007a961:\n"
        "minss %xmm0, %xmm1\n" /* line 4124 */
        "movl 0xc(%ebp), %eax\n" /* line 4127 | cycle */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "calll sinf\n"
        "fstps -0xc(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n"
        /* } scope */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 4128 */
        "flds -0x2c(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7a932_0007a98c:\n"
        "movl 0x195ee28, %eax\n" /* line 4118 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf7a932_0007a961\n"
        ".Lf7a932_0007a99a:\n"
        "movl 0x195ee34, %eax\n" /* line 4120 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf7a932_0007a961\n"
    );
}

/* line 285 */
static __attribute__((naked))
void BG_SetupClipIndexes(int weapIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x28(%ebp)\n"
        /* { scope 1 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "movl %eax, -0x20(%ebp)\n" /* weapDef */
        "movl bg_iNumWeapClips, %esi\n" /* line 295 */
        "testl %esi, %esi\n"
        "jg .Lf7a9aa_0007a9ec\n"
        "xorl %eax, %eax\n"
        ".Lf7a9aa_0007a9cc:\n"
        "movl -0x20(%ebp), %edx\n" /* line 323 | weapDef */
        "movl %edx, bg_weapClips(, %eax, 4)\n"
        "movl %eax, 0x1d0(%edx)\n" /* line 324 */
        "leal 1(%esi), %eax\n" /* line 325 */
        "movl %eax, bg_iNumWeapClips\n"
        /* } scope */
        ".Lf7a9aa_0007a9e4:\n"
        "addl $0x3c, %esp\n" /* line 326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7a9aa_0007a9ec:\n"
        "movl 0x1cc(%eax), %edx\n" /* line 297 */
        "movl %edx, -0x24(%ebp)\n"
        "xorl %edi, %edi\n" /* iIndex */
        "movl $bg_weapClips, %ebx\n" /* otherWeapDef */
        "movl %edx, %ecx\n"
        "jmp .Lf7a9aa_0007aa03\n"
        ".Lf7a9aa_0007aa00:\n"
        "movl -0x24(%ebp), %ecx\n"
        ".Lf7a9aa_0007aa03:\n"
        "movl (%ebx), %eax\n" /* otherWeapDef */
        "movl %ecx, 4(%esp)\n"
        "movl 0x1cc(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf7a9aa_0007aa29\n"
        "addl $1, %edi\n" /* line 295 | iIndex */
        "addl $4, %ebx\n" /* otherWeapDef */
        "cmpl %esi, %edi\n" /* iIndex */
        "jne .Lf7a9aa_0007aa00\n"
        "movl %esi, %eax\n"
        "jmp .Lf7a9aa_0007a9cc\n"
        ".Lf7a9aa_0007aa29:\n"
        "movl -0x20(%ebp), %eax\n" /* line 301 | weapDef */
        "movl %edi, 0x1d0(%eax)\n" /* iIndex */
        "movl bg_weapClips(, %edi, 4), %edx\n" /* line 305 */
        "movl 0x1d8(%edx), %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* weapDef */
        "cmpl 0x1d8(%ecx), %eax\n"
        "je .Lf7a9aa_0007a9e4\n"
        "testl %edi, %edi\n" /* iIndex */
        "je .Lf7a9aa_0007a9e4\n"
        "cmpl $1, -0x28(%ebp)\n" /* line 308 */
        "jle .Lf7a9aa_0007a9e4\n"
        "movl $1, -0x1c(%ebp)\n" /* line 305 | j */
        "movl $bg_weaponDefs, %esi\n"
        "jmp .Lf7a9aa_0007aa7c\n"
        ".Lf7a9aa_0007aa62:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 308 | j */
        "addl $4, %esi\n"
        "movl -0x1c(%ebp), %ecx\n" /* j */
        "cmpl %ecx, -0x28(%ebp)\n"
        "je .Lf7a9aa_0007a9e4\n"
        "movl bg_weapClips(, %edi, 4), %edx\n"
        ".Lf7a9aa_0007aa7c:\n"
        "movl 4(%esi), %ebx\n" /* line 310 | otherWeapDef */
        "movl 0x1cc(%ebx), %eax\n" /* line 312 | otherWeapDef */
        "movl %eax, 4(%esp)\n"
        "movl 0x1cc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf7a9aa_0007aa62\n"
        "movl 0x1d8(%ebx), %eax\n" /* otherWeapDef */
        "movl bg_weapClips(, %edi, 4), %edx\n"
        "cmpl 0x1d8(%edx), %eax\n"
        "jne .Lf7a9aa_0007aa62\n"
        "movl %eax, 0x18(%esp)\n" /* line 313 */
        "movl (%ebx), %eax\n" /* otherWeapDef */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x20(%ebp), %edx\n" /* weapDef */
        "movl 0x1d8(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x1c4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21ca94, 4(%esp)\n" /* "Clip Size mismatch for "%s" clip: '%s" set it to %i, but "%" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7a9aa_0007aa62\n"
    );
}

/* line 228 */
static __attribute__((naked))
void BG_SetupSharedAmmoIndexes(int weapIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 228 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x24(%ebp)\n"
        /* { scope 1: j */
        "movl bg_weaponDefs(, %eax, 4), %ebx\n" /* line 521 | weapDef */
        "movl $0xffffffff, 0x1e4(%ebx)\n" /* line 235 | weapDef */
        "movl 0x1e0(%ebx), %eax\n" /* line 237 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf7aaf0_0007ab20\n"
        /* } scope */
        ".Lf7aaf0_0007ab18:\n"
        "addl $0x3c, %esp\n" /* line 277 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: j */
        ".Lf7aaf0_0007ab20:\n"
        "movl %eax, 8(%esp)\n" /* line 240 */
        "movl (%ebx), %eax\n" /* weapDef */
        "movl %eax, 4(%esp)\n"
        "movl $0x21caec, (%esp)\n" /* "%s: %s
" */
        "calll Com_DPrintf\n"
        "movl bg_iNumSharedAmmoCaps, %eax\n" /* line 243 */
        "testl %eax, %eax\n"
        "jg .Lf7aaf0_0007ab5e\n"
        "xorl %edi, %edi\n" /* iIndex */
        ".Lf7aaf0_0007ab41:\n"
        "movl %ebx, bg_sharedAmmoCaps(, %edi, 4)\n" /* line 274 | weapDef */
        "movl %edi, 0x1e4(%ebx)\n" /* line 275 | iIndex, weapDef */
        "addl $1, %eax\n" /* line 276 */
        "movl %eax, bg_iNumSharedAmmoCaps\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 277 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: j */
        ".Lf7aaf0_0007ab5e:\n"
        "xorl %edi, %edi\n" /* line 243 | iIndex */
        "movl $bg_sharedAmmoCaps, %esi\n"
        "jmp .Lf7aaf0_0007ab76\n"
        ".Lf7aaf0_0007ab67:\n"
        "addl $1, %edi\n" /* iIndex */
        "movl bg_iNumSharedAmmoCaps, %eax\n"
        "addl $4, %esi\n"
        "cmpl %eax, %edi\n" /* iIndex */
        "jge .Lf7aaf0_0007ab41\n"
        ".Lf7aaf0_0007ab76:\n"
        "movl 0x1e0(%ebx), %eax\n" /* line 245 | weapDef */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl 0x1e0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf7aaf0_0007ab67\n"
        "movl %edi, 0x1e4(%ebx)\n" /* line 249 | iIndex, weapDef */
        "movl bg_sharedAmmoCaps(, %edi, 4), %edx\n" /* line 253 */
        "movl 0x1e8(%edx), %eax\n"
        "cmpl 0x1e8(%ebx), %eax\n" /* weapDef */
        "je .Lf7aaf0_0007ab18\n"
        "testl %edi, %edi\n" /* iIndex */
        "je .Lf7aaf0_0007ab18\n"
        /* { scope 2 */
        "cmpl $1, -0x24(%ebp)\n" /* line 259 */
        "jle .Lf7aaf0_0007ab18\n"
        /* } scope */
        "movl $1, -0x20(%ebp)\n" /* line 253 | j */
        "movl $bg_weaponDefs, -0x1c(%ebp)\n"
        "jmp .Lf7aaf0_0007abf0\n"
        /* { scope 2 */
        ".Lf7aaf0_0007abd5:\n"
        "addl $1, -0x20(%ebp)\n" /* line 259 | j */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* j */
        "cmpl %eax, -0x24(%ebp)\n"
        "je .Lf7aaf0_0007ab18\n"
        "movl bg_sharedAmmoCaps(, %edi, 4), %edx\n"
        ".Lf7aaf0_0007abf0:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 261 */
        "movl 4(%eax), %esi\n" /* otherWeapDef */
        "movl 0x1e0(%esi), %eax\n" /* line 263 | otherWeapDef */
        "movl %eax, 4(%esp)\n"
        "movl 0x1e0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf7aaf0_0007abd5\n"
        "movl 0x1e8(%esi), %eax\n" /* otherWeapDef */
        "movl bg_sharedAmmoCaps(, %edi, 4), %edx\n"
        "cmpl 0x1e8(%edx), %eax\n"
        "jne .Lf7aaf0_0007abd5\n"
        "movl %eax, 0x18(%esp)\n" /* line 264 */
        "movl (%esi), %eax\n" /* otherWeapDef */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x1e8(%ebx), %eax\n" /* weapDef */
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n" /* weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x1e0(%ebx), %eax\n" /* weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $0x21caf4, 4(%esp)\n" /* "Shared ammo cap mismatch for "%s" shared ammo cap: '%s" set" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7aaf0_0007abd5\n"
    );
}

/* line 179 */
static __attribute__((naked))
void BG_SetupAmmoIndexes(int weapIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 179 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x28(%ebp)\n"
        /* { scope 1 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "movl %eax, -0x20(%ebp)\n" /* weapDef */
        "movl bg_iNumAmmoTypes, %esi\n" /* line 189 */
        "testl %esi, %esi\n"
        "jg .Lf7ac64_0007aca6\n"
        "xorl %eax, %eax\n"
        ".Lf7ac64_0007ac86:\n"
        "movl -0x20(%ebp), %edx\n" /* line 217 | weapDef */
        "movl %edx, bg_weapAmmoTypes(, %eax, 4)\n"
        "movl %eax, 0x1c8(%edx)\n" /* line 218 */
        "leal 1(%esi), %eax\n" /* line 219 */
        "movl %eax, bg_iNumAmmoTypes\n"
        /* } scope */
        ".Lf7ac64_0007ac9e:\n"
        "addl $0x3c, %esp\n" /* line 220 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7ac64_0007aca6:\n"
        "movl 0x1c4(%eax), %edx\n" /* line 191 */
        "movl %edx, -0x24(%ebp)\n"
        "xorl %edi, %edi\n" /* iIndex */
        "movl $bg_weapAmmoTypes, %ebx\n" /* otherWeapDef */
        "movl %edx, %ecx\n"
        "jmp .Lf7ac64_0007acbd\n"
        ".Lf7ac64_0007acba:\n"
        "movl -0x24(%ebp), %ecx\n"
        ".Lf7ac64_0007acbd:\n"
        "movl (%ebx), %eax\n" /* otherWeapDef */
        "movl %ecx, 4(%esp)\n"
        "movl 0x1c4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf7ac64_0007ace3\n"
        "addl $1, %edi\n" /* line 189 | iIndex */
        "addl $4, %ebx\n" /* otherWeapDef */
        "cmpl %esi, %edi\n" /* iIndex */
        "jne .Lf7ac64_0007acba\n"
        "movl %esi, %eax\n"
        "jmp .Lf7ac64_0007ac86\n"
        ".Lf7ac64_0007ace3:\n"
        "movl -0x20(%ebp), %eax\n" /* line 195 | weapDef */
        "movl %edi, 0x1c8(%eax)\n" /* iIndex */
        "movl bg_weapAmmoTypes(, %edi, 4), %edx\n" /* line 199 */
        "movl 0x1d4(%edx), %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* weapDef */
        "cmpl 0x1d4(%ecx), %eax\n"
        "je .Lf7ac64_0007ac9e\n"
        "testl %edi, %edi\n" /* iIndex */
        "je .Lf7ac64_0007ac9e\n"
        "cmpl $1, -0x28(%ebp)\n" /* line 202 */
        "jle .Lf7ac64_0007ac9e\n"
        "movl $1, -0x1c(%ebp)\n" /* line 199 | j */
        "movl $bg_weaponDefs, %esi\n"
        "jmp .Lf7ac64_0007ad36\n"
        ".Lf7ac64_0007ad1c:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 202 | j */
        "addl $4, %esi\n"
        "movl -0x1c(%ebp), %ecx\n" /* j */
        "cmpl %ecx, -0x28(%ebp)\n"
        "je .Lf7ac64_0007ac9e\n"
        "movl bg_weapAmmoTypes(, %edi, 4), %edx\n"
        ".Lf7ac64_0007ad36:\n"
        "movl 4(%esi), %ebx\n" /* line 204 | otherWeapDef */
        "movl 0x1c4(%ebx), %eax\n" /* line 206 | otherWeapDef */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf7ac64_0007ad1c\n"
        "movl 0x1d4(%ebx), %eax\n" /* otherWeapDef */
        "movl bg_weapAmmoTypes(, %edi, 4), %edx\n"
        "cmpl 0x1d4(%edx), %eax\n"
        "jne .Lf7ac64_0007ad1c\n"
        "movl %eax, 0x18(%esp)\n" /* line 207 */
        "movl (%ebx), %eax\n" /* otherWeapDef */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x20(%ebp), %edx\n" /* weapDef */
        "movl 0x1d4(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x1c4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21cb5c, 4(%esp)\n" /* "Max ammo mismatch for "%s" ammo: '%s" set it to %i, but "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7ac64_0007ad1c\n"
    );
}

/* line 870 */
qboolean BG_IsAimDownSightWeapon(int iWeapon)
{
    return *(int *)((byte *)bg_weaponDefs[iWeapon] + 0x32c);
}

/* line 880 */
Bool BG_DoesWeaponRequireSlot(int weaponIndex)
{
    int val = *(int *)(*(byte **)((byte *)&bg_weaponDefs + weaponIndex * 4) + 0x80);
    return (unsigned int)(val - 1) <= 1;
}

/* line 920 */
__attribute__((naked))
Bool BG_DoesWeaponNeedSlot(int weapIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 920 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 521 | weapIndex */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "cmpl $9, 0x7c(%eax)\n" /* line 926 */
        "je .Lf7ade2_0007adff\n"
        "movl 0x84(%eax), %eax\n" /* line 929 */
        "testl %eax, %eax\n"
        "je .Lf7ade2_0007ae03\n"
        ".Lf7ade2_0007adff:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 933 */
        "retl\n"
        /* { scope 1 */
        ".Lf7ade2_0007ae03:\n"
        "movl $1, %eax\n" /* line 929 */
        /* } scope */
        "popl %ebp\n" /* line 933 */
        "retl\n"
    );
}

/* line 1097 */
__attribute__((naked))
int BG_GetEmptySlotForWeapon(const playerState_t *pPS, int iWeaponIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1097 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* line 1103 | iWeaponIndex */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x80(%eax), %eax\n"
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf7ae0a_0007ae41\n"
        "movl 8(%ebp), %eax\n" /* line 1108 | pPS */
        "cmpb $0, 0x555(%eax)\n"
        "je .Lf7ae0a_0007ae45\n"
        "cmpb $0, 0x556(%eax)\n" /* line 1110 */
        "jne .Lf7ae0a_0007ae41\n"
        "movl $2, %eax\n"
        "popl %ebp\n" /* line 1118 */
        "retl\n"
        ".Lf7ae0a_0007ae41:\n"
        "xorl %eax, %eax\n" /* line 1110 */
        "popl %ebp\n" /* line 1118 */
        "retl\n"
        ".Lf7ae0a_0007ae45:\n"
        "movl $1, %eax\n" /* line 1108 */
        "popl %ebp\n" /* line 1118 */
        "retl\n"
    );
}

/* line 1130 */
__attribute__((naked))
int BG_GetStackSlotForWeapon(const playerState_t *pPS, int iWeaponIndex, weapSlot_t preferedSlot)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1130 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 521 | iWeaponIndex */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x88(%eax), %edx\n" /* line 1136 */
        "testl %edx, %edx\n"
        "je .Lf7ae4c_0007aec6\n"
        "movl 0x80(%eax), %eax\n" /* line 1139 */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf7ae4c_0007aec6\n"
        "movl 0x10(%ebp), %eax\n" /* line 1144 | preferedSlot */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf7ae4c_0007aed5\n"
        ".Lf7ae4c_0007ae7c:\n"
        "movl 8(%ebp), %edx\n" /* line 1153 | pPS */
        "movzbl 0x555(%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf7ae4c_0007aecc\n"
        "movsbl %al, %eax\n" /* line 1155 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x88(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf7ae4c_0007aecc\n"
        "movzbl 0x556(%edx), %eax\n" /* line 1158 */
        "testb %al, %al\n"
        "je .Lf7ae4c_0007aebd\n"
        "movsbl %al, %eax\n" /* line 1160 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x88(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7ae4c_0007aec6\n"
        ".Lf7ae4c_0007aebd:\n"
        "movl $2, %edx\n"
        /* } scope */
        ".Lf7ae4c_0007aec2:\n"
        "movl %edx, %eax\n" /* line 1168 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7ae4c_0007aec6:\n"
        "xorl %edx, %edx\n" /* line 1160 */
        /* } scope */
        "movl %edx, %eax\n" /* line 1168 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7ae4c_0007aecc:\n"
        "movl $1, %edx\n" /* line 1160 */
        /* } scope */
        "movl %edx, %eax\n" /* line 1168 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7ae4c_0007aed5:\n"
        "movl 0x10(%ebp), %edx\n" /* line 1146 | preferedSlot */
        "movl 8(%ebp), %ecx\n" /* pPS */
        "movzbl 0x554(%edx, %ecx), %eax\n"
        "testb %al, %al\n"
        "je .Lf7ae4c_0007aec2\n"
        "movsbl %al, %eax\n" /* line 1149 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x88(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7ae4c_0007ae7c\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 1168 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1178 */
__attribute__((naked))
qboolean BG_IsPlayerWeaponAnAlt(int iWeaponIndex, int iAltIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1178 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* iWeaponIndex */
        "movl 0xc(%ebp), %ecx\n" /* iAltIndex */
        /* { scope 1 */
        "movl bg_weaponDefs(, %edx, 4), %eax\n" /* line 1182 */
        "movl 0x36c(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 1183 */
        "je .Lf7af00_0007af3e\n"
        "cmpl %ecx, %eax\n" /* line 1185 */
        "je .Lf7af00_0007af37\n"
        ".Lf7af00_0007af1e:\n"
        "cmpl %eax, %edx\n" /* line 1187 */
        "je .Lf7af00_0007af3e\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 1189 */
        "movl 0x36c(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 1183 */
        "je .Lf7af00_0007af3e\n"
        "cmpl %eax, %ecx\n" /* line 1185 */
        "jne .Lf7af00_0007af1e\n"
        ".Lf7af00_0007af37:\n"
        "movl $1, %eax\n" /* line 1183 */
        /* } scope */
        "popl %ebp\n" /* line 1192 */
        "retl\n"
        /* { scope 1 */
        ".Lf7af00_0007af3e:\n"
        "xorl %eax, %eax\n" /* line 1183 */
        /* } scope */
        "popl %ebp\n" /* line 1192 */
        "retl\n"
    );
}

/* line 1328 */
__attribute__((naked))
void BG_GetSpreadForWeapon(const playerState_t *ps, int weaponIndex, float *minSpread, float *maxSpread)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1328 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* minSpread */
        "movl 0x14(%ebp), %ebx\n" /* maxSpread */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 521 | weaponIndex */
        "movl bg_weaponDefs(, %eax, 4), %edx\n"
        "movl 8(%ebp), %eax\n" /* line 1335 | ps */
        "movss 0xf8(%eax), %xmm2\n"
        "ucomiss 0x2ed73c, %xmm2\n" /* 40.0f */
        "jbe .Lf7af42_0007afbd\n"
        "subss 0x2ed73c, %xmm2\n" /* line 1337 | 40.0f */
        "divss 0x2ed694, %xmm2\n" /* 20.0f */
        "movss 0x290(%edx), %xmm1\n" /* line 1339 */
        "movss 0x28c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss 0x29c(%edx), %xmm1\n" /* line 1340 */
        "movss 0x298(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, (%ebx)\n" /* maxSpread */
        /* } scope */
        "popl %ebx\n" /* line 1349 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7af42_0007afbd:\n"
        "subss 0x2ed7bc, %xmm2\n" /* line 1344 | 11.0f */
        "divss 0x2ed7c0, %xmm2\n" /* 29.0f */
        "movss 0x294(%edx), %xmm1\n" /* line 1346 */
        "movss 0x290(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss 0x2a0(%edx), %xmm1\n" /* line 1347 */
        "movss 0x29c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, (%ebx)\n" /* maxSpread */
        /* } scope */
        "popl %ebx\n" /* line 1349 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1723 */
int BG_ClipForWeapon(int weapon)
{
    return *(int *)((byte *)bg_weaponDefs[weapon] + 0x1d0);
}

/* line 1734 */
int BG_AmmoForWeapon(int weapon)
{
    return *(int *)((byte *)bg_weaponDefs[weapon] + 0x1c8);
}

/* line 1745 */
qboolean BG_WeaponIsClipOnly(int weapon)
{
    return *(int *)((byte *)bg_weaponDefs[weapon] + 0x340);
}

/* line 1844 */
int PM_WeaponAmmoAvailable(playerState_t *ps)
{
    int weapon = *(int *)((byte *)ps + 0xd4);
    int clipIndex = *(int *)((byte *)bg_weaponDefs[weapon] + 0x1d0);
    return *(int *)((byte *)ps + 0x344 + clipIndex * 4);
}

/* line 1758 */
__attribute__((naked))
int BG_WeaponAmmo(const playerState_t *ps, int weapon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1758 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* ps */
        "movl 0xc(%ebp), %eax\n" /* line 521 | weapon */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x1c8(%eax), %edx\n"
        "movl 0x1d0(%eax), %ecx\n"
        "movl 0x144(%ebx, %edx, 4), %eax\n"
        "addl 0x344(%ebx, %ecx, 4), %eax\n"
        "popl %ebx\n" /* line 1767 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1050 */
__attribute__((naked))
int BG_IsPlayerWeaponInSlot(const playerState_t *pPS, int iWeaponIndex, qboolean bAnyMode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1050 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* pPS */
        "movl 0xc(%ebp), %edx\n" /* iWeaponIndex */
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 1056 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%ebx, %eax, 4), %eax\n" /* pPS */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7b0a4_0007b0f8\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1061 | bAnyMode */
        "testl %ecx, %ecx\n"
        "jne .Lf7b0a4_0007b110\n"
        "movl bg_weaponDefs(, %edx, 4), %eax\n" /* line 1065 */
        "movl 0x80(%eax), %eax\n"
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf7b0a4_0007b0f8\n"
        "movsbl 0x555(%ebx), %eax\n" /* line 1070 | pPS */
        "cmpl %eax, %edx\n"
        "je .Lf7b0a4_0007b107\n"
        "movsbl 0x556(%ebx), %eax\n" /* line 1072 | pPS */
        "cmpl %eax, %edx\n"
        "je .Lf7b0a4_0007b0fe\n"
        ".Lf7b0a4_0007b0f8:\n"
        "xorl %eax, %eax\n" /* line 1061 */
        /* } scope */
        ".Lf7b0a4_0007b0fa:\n"
        "popl %ebx\n" /* line 1086 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b0a4_0007b0fe:\n"
        "movl $2, %eax\n" /* line 1061 */
        /* } scope */
        "popl %ebx\n" /* line 1086 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b0a4_0007b107:\n"
        "movl $1, %eax\n" /* line 1061 */
        /* } scope */
        "popl %ebx\n" /* line 1086 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b0a4_0007b110:\n"
        "movl %edx, %ecx\n" /* line 1056 */
        ".Lf7b0a4_0007b112:\n"
        "movl bg_weaponDefs(, %ecx, 4), %esi\n" /* line 521 */
        "movl 0x80(%esi), %eax\n" /* line 1065 | curWeapDef */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf7b0a4_0007b0f8\n"
        "movsbl 0x555(%ebx), %eax\n" /* line 1070 | pPS */
        "cmpl %eax, %ecx\n"
        "je .Lf7b0a4_0007b107\n"
        "movsbl 0x556(%ebx), %eax\n" /* line 1072 | pPS */
        "cmpl %eax, %ecx\n"
        "je .Lf7b0a4_0007b0fe\n"
        "movl 0x36c(%esi), %eax\n" /* line 1080 | curWeapDef */
        "testl %eax, %eax\n"
        "cmovnel %eax, %ecx\n"
        "cmpl %edx, %ecx\n" /* line 1061 */
        "jne .Lf7b0a4_0007b112\n"
        "xorl %eax, %eax\n"
        "jmp .Lf7b0a4_0007b0fa\n"
    );
}

/* line 1270 */
__attribute__((naked))
int BG_GetTotalAmmoReserve(const playerState_t *ps, int weaponIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1270 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* weaponIndex */
        /* { scope 1 */
        "movl bg_weaponDefs(, %ebx, 4), %eax\n" /* line 521 */
        "movl 0x1c8(%eax), %edx\n" /* line 1736 */
        "movl %edx, -0x41c(%ebp)\n" /* ammoIndex */
        "movl 0x1d0(%eax), %edi\n" /* line 1725 | clipIndex */
        "leal -0x218(%ebp), %eax\n" /* line 1281 | ammoCounted */
        "movl $0x200, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal -0x418(%ebp), %eax\n" /* line 1282 | clipCounted */
        "movl $0x200, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl bg_weaponDefs(, %ebx, 4), %esi\n" /* line 521 */
        "movl 0x1e4(%esi), %edx\n" /* line 1285 | weapDef */
        "testl %edx, %edx\n"
        "js .Lf7b150_0007b2d9\n"
        "movl bg_iNumWeapons, %ecx\n" /* line 1287 */
        "movl %ecx, -0x420(%ebp)\n"
        "testl %ecx, %ecx\n"
        "jle .Lf7b150_0007b283\n"
        "movl $0, -0x42c(%ebp)\n" /* ammo */
        "movl $1, %edx\n"
        "movl $bg_weaponDefs, %ebx\n" /* weaponIndex */
        "jmp .Lf7b150_0007b201\n"
        ".Lf7b150_0007b1f3:\n"
        "addl $1, %edx\n"
        "addl $4, %ebx\n" /* weaponIndex */
        "cmpl -0x420(%ebp), %edx\n"
        "jg .Lf7b150_0007b272\n"
        ".Lf7b150_0007b201:\n"
        "movl %edx, %eax\n" /* line 1289 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 8(%ebp), %edi\n" /* ps, clipIndex */
        "movl 0x544(%edi, %eax, 4), %eax\n" /* clipIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7b150_0007b1f3\n"
        "movl 4(%ebx), %ecx\n" /* line 521 */
        "movl 0x1e4(%ecx), %eax\n" /* line 1293 */
        "cmpl 0x1e4(%esi), %eax\n" /* weapDef */
        "jne .Lf7b150_0007b1f3\n"
        "movl 0x340(%ecx), %eax\n" /* line 1295 */
        "testl %eax, %eax\n"
        "je .Lf7b150_0007b29e\n"
        "movl 0x1d0(%ecx), %eax\n" /* line 1725 */
        "cmpl $0, -0x418(%ebp, %eax, 4)\n" /* line 1297 */
        "jne .Lf7b150_0007b1f3\n"
        "movl $1, -0x418(%ebp, %eax, 4)\n" /* line 1299 */
        "movl 0x1d0(%ecx), %eax\n" /* line 1300 */
        "movl 0x344(%edi, %eax, 4), %ecx\n" /* clipIndex */
        "addl %ecx, -0x42c(%ebp)\n" /* ammo */
        "addl $1, %edx\n" /* line 1287 */
        "addl $4, %ebx\n" /* weaponIndex */
        "cmpl -0x420(%ebp), %edx\n"
        "jle .Lf7b150_0007b201\n"
        ".Lf7b150_0007b272:\n"
        "movl -0x42c(%ebp), %eax\n" /* ammo */
        /* } scope */
        "addl $0x43c, %esp\n" /* line 1323 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b150_0007b283:\n"
        "movl $0, -0x42c(%ebp)\n" /* line 1287 | ammo */
        "movl -0x42c(%ebp), %eax\n" /* ammo */
        /* } scope */
        "addl $0x43c, %esp\n" /* line 1323 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b150_0007b29e:\n"
        "movl 0x1c8(%ecx), %eax\n" /* line 1736 */
        "movl -0x218(%ebp, %eax, 4), %edi\n" /* line 1305 | clipIndex */
        "testl %edi, %edi\n" /* clipIndex */
        "jne .Lf7b150_0007b1f3\n"
        "movl $1, -0x218(%ebp, %eax, 4)\n" /* line 1307 */
        "movl 0x1c8(%ecx), %eax\n" /* line 1308 */
        "movl 8(%ebp), %edi\n" /* ps, clipIndex */
        "movl 0x144(%edi, %eax, 4), %edi\n" /* clipIndex */
        "addl %edi, -0x42c(%ebp)\n" /* clipIndex, ammo */
        "jmp .Lf7b150_0007b1f3\n"
        ".Lf7b150_0007b2d9:\n"
        "movl 0x340(%esi), %ebx\n" /* line 1316 | weapDef, weaponIndex */
        "testl %ebx, %ebx\n" /* weaponIndex */
        "jne .Lf7b150_0007b306\n"
        "movl -0x41c(%ebp), %edx\n" /* line 1319 | ammoIndex */
        "movl 8(%ebp), %ecx\n" /* ps */
        "movl 0x144(%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x42c(%ebp)\n" /* ammo */
        "movl %edx, %eax\n"
        /* } scope */
        "addl $0x43c, %esp\n" /* line 1323 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b150_0007b306:\n"
        "movl 8(%ebp), %eax\n" /* line 1317 | ps */
        "movl 0x344(%eax, %edi, 4), %edi\n" /* clipIndex */
        "movl %edi, -0x42c(%ebp)\n" /* clipIndex, ammo */
        "movl %edi, %eax\n" /* clipIndex */
        /* } scope */
        "addl $0x43c, %esp\n" /* line 1323 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1775 */
static __attribute__((naked))
void PM_ReloadClip(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1775 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl %eax, %esi\n" /* ps */
        /* { scope 1 */
        "movl 0xd4(%eax), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %edx\n"
        "movl 0xd8(%esi), %eax\n" /* line 1786 | ps */
        "subl $7, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "cmpl $1, %eax\n"
        "jbe .Lf7b324_0007b3c2\n"
        ".Lf7b324_0007b34d:\n"
        "movl 0x1c8(%edx), %eax\n" /* line 1736 */
        "movl %eax, -0x10(%ebp)\n" /* ammo */
        "movl 0x1d0(%edx), %edi\n" /* line 1725 */
        "movl 0x144(%esi, %eax, 4), %ebx\n" /* line 1792 | ps, ammoReserve */
        "movl bg_weapClips(, %edi, 4), %eax\n" /* line 608 */
        "movl 0x1d8(%eax), %ecx\n"
        "movl 0x344(%esi, %edi, 4), %eax\n" /* line 1795 | ps */
        "movl %eax, -0x18(%ebp)\n"
        "movl %ecx, %eax\n"
        "subl -0x18(%ebp), %eax\n"
        "cmpl %eax, %ebx\n" /* line 1797 | ammoReserve */
        "cmovll %ebx, %eax\n" /* ammoReserve */
        "cmpl $1, -0x14(%ebp)\n" /* line 1800 */
        "jbe .Lf7b324_0007b3ce\n"
        "movl 0x360(%edx), %edx\n" /* line 1809 */
        "testl %edx, %edx\n"
        "jne .Lf7b324_0007b3b6\n"
        ".Lf7b324_0007b394:\n"
        "testl %eax, %eax\n" /* line 1815 */
        "je .Lf7b324_0007b3ae\n"
        ".Lf7b324_0007b398:\n"
        "subl %eax, %ebx\n" /* line 1817 | ammoReserve */
        "movl -0x10(%ebp), %edx\n" /* ammo */
        "movl %ebx, 0x144(%esi, %edx, 4)\n" /* ammoReserve, ps */
        "addl -0x18(%ebp), %eax\n" /* line 1818 */
        "movl %eax, 0x344(%esi, %edi, 4)\n" /* ps */
        /* } scope */
        ".Lf7b324_0007b3ae:\n"
        "addl $0xc, %esp\n" /* line 1820 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b324_0007b3b6:\n"
        "cmpl %edx, %ecx\n" /* line 1809 */
        "jle .Lf7b324_0007b394\n"
        "cmpl %edx, %eax\n"
        "jle .Lf7b324_0007b394\n"
        "movl %edx, %eax\n"
        "jmp .Lf7b324_0007b398\n"
        ".Lf7b324_0007b3c2:\n"
        "movl 0x364(%edx), %ecx\n" /* line 1786 */
        "testl %ecx, %ecx\n"
        "jne .Lf7b324_0007b34d\n"
        "jmp .Lf7b324_0007b3ae\n"
        ".Lf7b324_0007b3ce:\n"
        "movl 0x364(%edx), %edx\n" /* line 1802 */
        "cmpl %edx, %ecx\n"
        "jle .Lf7b324_0007b394\n"
        "cmpl %edx, %eax\n"
        "jle .Lf7b324_0007b394\n"
        "movl %edx, %eax\n"
        "jmp .Lf7b324_0007b394\n"
    );
}

/* line 2320 */
static __attribute__((naked))
qboolean PM_Weapon_AllowReload(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2320 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl %eax, %edx\n" /* ps */
        /* { scope 1 */
        "movl 0xd4(%eax), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %ecx\n"
        "movl 0x1d0(%ecx), %ebx\n" /* line 1725 */
        "movl 0x1c8(%ecx), %eax\n" /* line 2330 */
        "movl 0x144(%edx, %eax, 4), %esi\n" /* ps */
        "testl %esi, %esi\n"
        "je .Lf7b3e0_0007b44e\n"
        "movl 0x344(%edx, %ebx, 4), %esi\n" /* ps */
        "movl bg_weapClips(, %ebx, 4), %eax\n" /* line 608 */
        "movl 0x1d8(%eax), %eax\n"
        "cmpl %eax, %esi\n" /* line 2330 */
        "jge .Lf7b3e0_0007b44e\n"
        "movl 0x358(%ecx), %ebx\n" /* line 2332 | clipWeap */
        "testl %ebx, %ebx\n" /* clipWeap */
        "je .Lf7b3e0_0007b441\n"
        "movl 0x360(%ecx), %edx\n" /* line 2335 | ps */
        "testl %edx, %edx\n" /* ps */
        "je .Lf7b3e0_0007b44a\n"
        "cmpl %eax, %edx\n" /* ps */
        "jge .Lf7b3e0_0007b44a\n"
        "subl %esi, %eax\n" /* line 2342 */
        "cmpl %eax, %edx\n" /* ps */
        "jg .Lf7b3e0_0007b44e\n"
        ".Lf7b3e0_0007b441:\n"
        "movl $1, %eax\n" /* line 2337 */
        /* } scope */
        "popl %ebx\n" /* line 2353 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b3e0_0007b44a:\n"
        "testl %esi, %esi\n" /* line 2337 */
        "je .Lf7b3e0_0007b441\n"
        ".Lf7b3e0_0007b44e:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 2353 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 842 */
__attribute__((naked))
int BG_GetFirstEquippedOffhand(const playerState_t *ps, int offhandClass)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 842 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* offhandClass */
        /* { scope 1 */
        "movl bg_iNumWeapons, %esi\n" /* line 560 */
        "testl %esi, %esi\n" /* line 850 | weapCount */
        "jle .Lf7b454_0007b4b6\n"
        "movl $1, %edx\n"
        "movl $bg_weaponDefs, %ebx\n"
        "jmp .Lf7b454_0007b480\n"
        ".Lf7b454_0007b476:\n"
        "addl $1, %edx\n"
        "addl $4, %ebx\n"
        "cmpl %edx, %esi\n" /* weapCount */
        "jl .Lf7b454_0007b4b6\n"
        ".Lf7b454_0007b480:\n"
        "movl 4(%ebx), %eax\n" /* line 854 */
        "cmpl %edi, 0x84(%eax)\n" /* offhandClass */
        "jne .Lf7b454_0007b476\n"
        "movl %edx, %eax\n" /* line 857 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* ps */
        "movl 0x544(%ecx, %eax, 4), %eax\n"
        "movzbl -0x10(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7b454_0007b476\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 864 */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b454_0007b4b6:\n"
        "xorl %edx, %edx\n" /* line 850 */
        /* } scope */
        "movl %edx, %eax\n" /* line 864 */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2654 */
__attribute__((naked))
void PM_AdjustAimSpreadScale(pmove_t *pm, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2654 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 2664 | pm */
        "movl (%eax), %ebx\n" /* ps */
        "movl 0xd4(%ebx), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %esi\n"
        "movss 0x2a4(%esi), %xmm0\n" /* line 2675 | weapDef */
        "pxor %xmm3, %xmm3\n" /* line 2676 */
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf7b4c4_0007b534\n"
        "jp .Lf7b4c4_0007b534\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        ".Lf7b4c4_0007b4fa:\n"
        "movss 0x2ed5d4, %xmm1\n" /* line 2731 | 255.0f */
        "mulss %xmm1, %xmm0\n"
        "addss 0x5d4(%ebx), %xmm0\n" /* ps */
        "movss %xmm0, 0x5d4(%ebx)\n" /* ps */
        "ucomiss %xmm0, %xmm3\n" /* line 2732 */
        "ja .Lf7b4c4_0007b598\n"
        ".Lf7b4c4_0007b51b:\n"
        "ucomiss 0x2ed5d4, %xmm0\n" /* line 2734 | 255.0f */
        "jbe .Lf7b4c4_0007b52c\n"
        "movss %xmm1, 0x5d4(%ebx)\n" /* line 2735 | ps */
        /* } scope */
        ".Lf7b4c4_0007b52c:\n"
        "addl $0x4c, %esp\n" /* line 2736 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b4c4_0007b534:\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 2678 | ps */
        "je .Lf7b4c4_0007b5b8\n"
        ".Lf7b4c4_0007b53d:\n"
        "movl 0xa0(%ebx), %eax\n" /* line 2680 | ps */
        "testb $8, %al\n"
        "je .Lf7b4c4_0007b5aa\n"
        "mulss 0x2b8(%esi), %xmm0\n" /* line 2681 | weapDef */
        ".Lf7b4c4_0007b54f:\n"
        "movl 0xc(%ebp), %eax\n" /* line 2685 | pml */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* decrease */
        "movss 0x2ed5d0, %xmm0\n" /* line 2687 | 1.0f */
        "ucomiss 0xdc(%ebx), %xmm0\n" /* ps */
        "jne .Lf7b4c4_0007b5e8\n"
        ".Lf7b4c4_0007b56d:\n"
        "jp .Lf7b4c4_0007b5e8\n"
        "movaps %xmm3, %xmm0\n"
        "subss -0x20(%ebp), %xmm0\n" /* decrease */
        "movss 0x2ed5d4, %xmm1\n" /* line 2731 | 255.0f */
        "mulss %xmm1, %xmm0\n"
        "addss 0x5d4(%ebx), %xmm0\n" /* ps */
        "movss %xmm0, 0x5d4(%ebx)\n" /* ps */
        "ucomiss %xmm0, %xmm3\n" /* line 2732 */
        "jbe .Lf7b4c4_0007b51b\n"
        ".Lf7b4c4_0007b598:\n"
        "movl $0, 0x5d4(%ebx)\n" /* line 2733 | ps */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2736 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b4c4_0007b5aa:\n"
        "testb $4, %al\n" /* line 2682 */
        "je .Lf7b4c4_0007b54f\n"
        "mulss 0x2b4(%esi), %xmm0\n" /* line 2683 | weapDef */
        "jmp .Lf7b4c4_0007b54f\n"
        ".Lf7b4c4_0007b5b8:\n"
        "cmpl $1, 4(%ebx)\n" /* line 2678 | ps */
        "je .Lf7b4c4_0007b53d\n"
        "mulss 0x2ed5d8, %xmm0\n" /* line 2679 | 0.5f */
        "movl 0xc(%ebp), %eax\n" /* line 2685 | pml */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* decrease */
        "movss 0x2ed5d0, %xmm0\n" /* line 2687 | 1.0f */
        "ucomiss 0xdc(%ebx), %xmm0\n" /* ps */
        "je .Lf7b4c4_0007b56d\n"
        ".Lf7b4c4_0007b5e8:\n"
        "ucomiss 0x2ac(%esi), %xmm3\n" /* line 2695 | weapDef */
        "jne .Lf7b4c4_0007b660\n"
        "jp .Lf7b4c4_0007b660\n"
        "movaps %xmm3, %xmm5\n"
        ".Lf7b4c4_0007b5f6:\n"
        "movss 0x2b0(%esi), %xmm4\n" /* line 2705 | weapDef */
        "ucomiss %xmm3, %xmm4\n"
        "jp .Lf7b4c4_0007b605\n"
        "je .Lf7b4c4_0007b63e\n"
        ".Lf7b4c4_0007b605:\n"
        "movl 8(%ebp), %eax\n" /* line 2707 | pm */
        "cmpw $0, 0x1c(%eax)\n"
        "je .Lf7b4c4_0007b63e\n"
        "movss 0x20(%ebx), %xmm2\n" /* line 126 */
        "movss 0x24(%ebx), %xmm1\n"
        "movl 0x195ee38, %eax\n" /* line 2709 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf7b4c4_0007b703\n"
        ".Lf7b4c4_0007b63e:\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 2715 | ps */
        "je .Lf7b4c4_0007b6de\n"
        ".Lf7b4c4_0007b64b:\n"
        "movaps %xmm5, %xmm0\n" /* line 2717 */
        "movl 0xc(%ebp), %eax\n" /* pml */
        "mulss 0x24(%eax), %xmm0\n"
        "subss -0x20(%ebp), %xmm0\n" /* decrease */
        "jmp .Lf7b4c4_0007b4fa\n"
        ".Lf7b4c4_0007b660:\n"
        "movl 8(%ebp), %edi\n" /* line 2695 | pm */
        "movaps %xmm3, %xmm5\n"
        "movl $2, -0x1c(%ebp)\n"
        ".Lf7b4c4_0007b66d:\n"
        "cvtsi2ssl 0x2c(%edi), %xmm0\n" /* line 2700 */
        "mulss 0x2ed648, %xmm0\n" /* 0.0054931640625f */
        "movss %xmm0, 4(%esp)\n"
        "cvtsi2ssl 0x10(%edi), %xmm0\n"
        "mulss 0x2ed648, %xmm0\n" /* 0.0054931640625f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm5, -0x38(%ebp)\n"
        "calll AngleSubtract\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "andps 0x2f09c0, %xmm0\n"
        "mulss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "mulss 0x2ac(%esi), %xmm0\n" /* weapDef */
        "movl 0xc(%ebp), %eax\n" /* pml */
        "divss 0x24(%eax), %xmm0\n"
        "movss -0x38(%ebp), %xmm5\n"
        "addss %xmm0, %xmm5\n"
        "addl $4, %edi\n"
        "subl $1, -0x1c(%ebp)\n" /* line 2698 */
        "jne .Lf7b4c4_0007b66d\n"
        "pxor %xmm3, %xmm3\n"
        "jmp .Lf7b4c4_0007b5f6\n"
        ".Lf7b4c4_0007b6de:\n"
        "cmpl $1, 4(%ebx)\n" /* line 2715 | ps */
        "je .Lf7b4c4_0007b64b\n"
        "xorl %eax, %eax\n"
        "movss 0x2ed7c4, %xmm0\n" /* 1.2799999713897705f */
        ".Lf7b4c4_0007b6f2:\n"
        "addss %xmm0, %xmm5\n" /* line 2718 */
        "addl $1, %eax\n" /* line 2717 */
        "cmpl $2, %eax\n"
        "jne .Lf7b4c4_0007b6f2\n"
        "jmp .Lf7b4c4_0007b64b\n"
        ".Lf7b4c4_0007b703:\n"
        "addss %xmm4, %xmm5\n" /* line 2710 */
        "jmp .Lf7b4c4_0007b63e\n"
    );
}

/* line 4436 */
static __attribute__((naked))
qboolean BG_CalculateWeaponPosition_GunRecoil_SingleAngle(float fGunKickSpeedMax, float fGunKickSpeedDecay, float fGunKickStaticDecay)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4436 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl %eax, %ecx\n" /* fOffset */
        "movaps %xmm0, %xmm7\n" /* fTimeStep */
        "movss %xmm3, -4(%ebp)\n" /* fGunKickStaticDecay */
        "movss 8(%ebp), %xmm6\n" /* fGunKickSpeedDecay */
        "movss 0xc(%ebp), %xmm3\n" /* fGunKickStaticDecay */
        /* { scope 1 */
        "movss (%eax), %xmm5\n" /* line 4441 */
        "movss 0x2f09d0, %xmm4\n"
        "movaps %xmm5, %xmm0\n"
        "andps %xmm4, %xmm0\n"
        "ucomiss 0x2ed604, %xmm0\n" /* 0.25f */
        "jae .Lf7b70c_0007b762\n"
        "jp .Lf7b70c_0007b762\n"
        "movss (%edx), %xmm0\n" /* speed */
        "andps %xmm4, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jae .Lf7b70c_0007b762\n"
        "jp .Lf7b70c_0007b762\n"
        "xorl %eax, %eax\n" /* line 4443 */
        "movl %eax, (%ecx)\n" /* fOffset */
        "movl %eax, (%edx)\n" /* line 4444 | speed */
        "movl $1, %eax\n"
        /* } scope */
        "leave\n" /* line 4497 */
        "retl\n"
        /* { scope 1 */
        ".Lf7b70c_0007b762:\n"
        "movaps %xmm7, %xmm0\n" /* line 4451 | fTimeStep */
        "mulss (%edx), %xmm0\n" /* speed */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, (%ecx)\n" /* fOffset */
        "ucomiss %xmm1, %xmm0\n" /* line 4455 | fOfsCap */
        "jbe .Lf7b70c_0007b7e5\n"
        "movss %xmm1, (%ecx)\n" /* line 4457 | fOfsCap, fOffset */
        "pxor %xmm4, %xmm4\n" /* line 4458 */
        "movss (%edx), %xmm0\n" /* speed */
        "ucomiss %xmm4, %xmm0\n"
        "jbe .Lf7b70c_0007b86c\n"
        ".Lf7b70c_0007b78b:\n"
        "movss %xmm4, (%edx)\n" /* line 4465 | speed */
        "movss (%ecx), %xmm0\n" /* fOffset */
        ".Lf7b70c_0007b793:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 4469 */
        "jbe .Lf7b70c_0007b7fe\n"
        ".Lf7b70c_0007b798:\n"
        "mulss %xmm7, %xmm2\n" /* line 4470 | fTimeStep, fGunKickAccel */
        "movss (%edx), %xmm0\n" /* speed */
        "subss %xmm2, %xmm0\n" /* fGunKickAccel */
        "movss %xmm0, (%edx)\n" /* speed */
        ".Lf7b70c_0007b7a8:\n"
        "mulss %xmm0, %xmm6\n" /* line 4475 */
        "mulss %xmm7, %xmm6\n" /* fTimeStep */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, (%edx)\n" /* speed */
        "ucomiss %xmm4, %xmm0\n" /* line 4476 */
        "jbe .Lf7b70c_0007b81c\n"
        ".Lf7b70c_0007b7bd:\n"
        "mulss %xmm7, %xmm3\n" /* line 4478 | fTimeStep */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, (%edx)\n" /* speed */
        "ucomiss %xmm0, %xmm4\n" /* line 4479 */
        "ja .Lf7b70c_0007b874\n"
        ".Lf7b70c_0007b7d2:\n"
        "ucomiss -4(%ebp), %xmm0\n" /* line 4490 */
        "jbe .Lf7b70c_0007b842\n"
        ".Lf7b70c_0007b7d8:\n"
        "movss -4(%ebp), %xmm0\n" /* line 4491 */
        "movss %xmm0, (%edx)\n" /* speed */
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 4497 */
        "retl\n"
        /* { scope 1 */
        ".Lf7b70c_0007b7e5:\n"
        "xorps 0x2f09e0, %xmm1\n" /* line 4461 | fOfsCap */
        "ucomiss %xmm0, %xmm1\n" /* fOfsCap */
        "ja .Lf7b70c_0007b85b\n"
        "pxor %xmm4, %xmm4\n"
        "movss (%ecx), %xmm0\n" /* fOffset */
        "ucomiss %xmm4, %xmm0\n" /* line 4469 */
        "ja .Lf7b70c_0007b798\n"
        ".Lf7b70c_0007b7fe:\n"
        "ucomiss %xmm0, %xmm4\n" /* line 4471 */
        "ja .Lf7b70c_0007b880\n"
        "movss (%edx), %xmm0\n" /* speed */
        "mulss %xmm0, %xmm6\n" /* line 4475 */
        "mulss %xmm7, %xmm6\n" /* fTimeStep */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, (%edx)\n" /* speed */
        "ucomiss %xmm4, %xmm0\n" /* line 4476 */
        "ja .Lf7b70c_0007b7bd\n"
        ".Lf7b70c_0007b81c:\n"
        "mulss %xmm7, %xmm3\n" /* line 4484 | fTimeStep */
        "addss %xmm3, %xmm0\n"
        "movaps %xmm4, %xmm1\n" /* line 4486 | fOfsCap */
        "cmpltss %xmm0, %xmm4\n"
        "andps %xmm4, %xmm1\n" /* fOfsCap */
        "andnps %xmm0, %xmm4\n"
        "orps %xmm1, %xmm4\n" /* fOfsCap */
        "movss %xmm4, (%edx)\n" /* speed */
        "movaps %xmm4, %xmm0\n"
        "ucomiss -4(%ebp), %xmm0\n" /* line 4490 */
        "ja .Lf7b70c_0007b7d8\n"
        ".Lf7b70c_0007b842:\n"
        "movss -4(%ebp), %xmm3\n" /* line 4492 */
        "xorps 0x2f09e0, %xmm3\n"
        "ucomiss %xmm0, %xmm3\n"
        "jbe .Lf7b70c_0007b857\n"
        "movss %xmm3, (%edx)\n" /* line 4493 | speed */
        ".Lf7b70c_0007b857:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 4497 */
        "retl\n"
        /* { scope 1 */
        ".Lf7b70c_0007b85b:\n"
        "movss %xmm1, (%ecx)\n" /* line 4463 | fOfsCap, fOffset */
        "pxor %xmm4, %xmm4\n" /* line 4464 */
        "ucomiss (%edx), %xmm4\n" /* speed */
        "ja .Lf7b70c_0007b78b\n"
        ".Lf7b70c_0007b86c:\n"
        "movaps %xmm1, %xmm0\n" /* fOfsCap */
        "jmp .Lf7b70c_0007b793\n"
        ".Lf7b70c_0007b874:\n"
        "movss %xmm4, (%edx)\n" /* line 4480 | speed */
        "movaps %xmm4, %xmm0\n"
        "jmp .Lf7b70c_0007b7d2\n"
        ".Lf7b70c_0007b880:\n"
        "mulss %xmm7, %xmm2\n" /* line 4472 | fTimeStep, fGunKickAccel */
        "addss (%edx), %xmm2\n" /* speed, fGunKickAccel */
        "movss %xmm2, (%edx)\n" /* fGunKickAccel, speed */
        "movaps %xmm2, %xmm0\n" /* fGunKickAccel */
        "jmp .Lf7b70c_0007b7a8\n"
    );
}

/* line 2361 */
static __attribute__((naked))
void PM_Weapon_ReloadDelayedAction(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2361 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %ebx\n" /* ps */
        /* { scope 1 */
        "movl 0xd4(%eax), %edx\n" /* line 2365 | iWeapon */
        /* { scope 2 */
        "movl bg_weaponDefs(, %edx, 4), %esi\n" /* line 521 */
        /* } scope */
        "movl 0x328(%esi), %edi\n" /* line 2367 | weapDef */
        "testl %edi, %edi\n"
        "je .Lf7b894_0007b8d9\n"
        "leal 0x55c(%eax), %edi\n"
        "movl %edx, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "andl $0x1f, %edx\n"
        "movl 0x55c(%ebx, %eax), %eax\n" /* line 2367 | ps */
        "movl %edx, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf7b894_0007b8e7\n"
        ".Lf7b894_0007b8d9:\n"
        "movl %ebx, %eax\n" /* line 2424 | ps */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2426 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp PM_ReloadClip\n" /* line 2424 */
        ".Lf7b894_0007b8e7:\n"
        "movl $0xfffffffe, %eax\n" /* line 817 */
        "roll %cl, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "andl %eax, (%edx, %edi)\n"
        "movl $0xa2, 4(%esp)\n" /* line 2370 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        "movl 0xd8(%ebx), %eax\n" /* line 2373 | ps */
        "subl $7, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf7b894_0007b97d\n"
        ".Lf7b894_0007b912:\n"
        "movl 0x34(%ebx), %edx\n" /* line 2377 | ps */
        "testl %edx, %edx\n"
        "je .Lf7b894_0007b8d9\n"
        /* { scope 2 */
        "cmpl $1, %eax\n" /* line 2382 */
        "jbe .Lf7b894_0007b991\n"
        "movl 0xd4(%ebx), %eax\n" /* line 2395 | ps */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x1d0(%eax), %eax\n"
        "movl 0x344(%ebx, %eax, 4), %eax\n" /* ps */
        "testl %eax, %eax\n"
        "jne .Lf7b894_0007b943\n"
        "movl 0x78(%esi), %edi\n" /* weapDef */
        "testl %edi, %edi\n"
        "je .Lf7b894_0007b989\n"
        ".Lf7b894_0007b943:\n"
        "movl 0x218(%esi), %ecx\n" /* line 2398 | weapDef */
        ".Lf7b894_0007b949:\n"
        "movl 0x220(%esi), %eax\n" /* line 2400 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7b894_0007b958\n"
        "cmpl %eax, %ecx\n"
        "cmovgl %eax, %ecx\n"
        ".Lf7b894_0007b958:\n"
        "movl 0x20c(%esi), %eax\n" /* line 2406 | weapDef */
        "cmpl %eax, %ecx\n"
        "movl $1, %edx\n"
        "cmovlel %edx, %eax\n"
        "subl %eax, %ecx\n" /* line 2411 */
        "testl %ecx, %ecx\n" /* line 2412 */
        "jle .Lf7b894_0007b8d9\n"
        "movl %ecx, 0x38(%ebx)\n" /* line 2415 | ps */
        /* } scope */
        /* } scope */
        ".Lf7b894_0007b975:\n"
        "addl $0x2c, %esp\n" /* line 2426 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b894_0007b97d:\n"
        "movl 0x228(%esi), %ecx\n" /* line 2373 | weapDef */
        "testl %ecx, %ecx\n"
        "jne .Lf7b894_0007b912\n"
        "jmp .Lf7b894_0007b975\n"
        /* { scope 2 */
        ".Lf7b894_0007b989:\n"
        "movl 0x21c(%esi), %ecx\n" /* line 2396 | weapDef */
        "jmp .Lf7b894_0007b949\n"
        ".Lf7b894_0007b991:\n"
        "movl 0x228(%esi), %ecx\n" /* line 2386 | weapDef */
        "movl 0x224(%esi), %eax\n" /* weapDef */
        "cmpl %eax, %ecx\n"
        "jl .Lf7b894_0007b958\n"
        "movl %eax, %ecx\n"
        "jmp .Lf7b894_0007b958\n"
    );
}

/* line 781 */
__attribute__((naked))
int BG_GetViewmodelWeaponIndex(const playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 781 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* ps */
        /* { scope 1 */
        "movl 0xc(%eax), %edx\n" /* line 785 */
        "testl $0x20000, %edx\n"
        "je .Lf7b9a6_0007b9f2\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jle .Lf7b9a6_0007ba09\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7b9a6_0007ba0e\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7b9a6_0007b9d7:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jl .Lf7b9a6_0007ba09\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7b9a6_0007b9d7\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        /* } scope */
        ".Lf7b9a6_0007b9ef:\n"
        "popl %ebx\n" /* line 801 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b9a6_0007b9f2:\n"
        "andb $0x10, %dl\n" /* line 790 */
        "jne .Lf7b9a6_0007ba00\n"
        "movl 0xd4(%eax), %eax\n" /* line 797 */
        /* } scope */
        "popl %ebx\n" /* line 801 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b9a6_0007ba00:\n"
        "movl 0xd0(%eax), %eax\n" /* line 792 */
        /* } scope */
        "popl %ebx\n" /* line 801 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b9a6_0007ba09:\n"
        "xorl %eax, %eax\n" /* line 797 */
        /* } scope */
        "popl %ebx\n" /* line 801 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7b9a6_0007ba0e:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7b9a6_0007b9ef\n"
    );
}

/* line 3998 */
__attribute__((naked))
void BG_WeaponFireRecoil(const playerState_t *ps, vec_t *vGunSpeed, vec_t *kickAVel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3998 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ps */
        "movl 0x10(%ebp), %edi\n" /* kickAVel */
        /* { scope 1 */
        "movl 0xc(%esi), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf7ba18_0007bbdb\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jg .Lf7ba18_0007bc2b\n"
        ".Lf7ba18_0007ba43:\n"
        "xorl %eax, %eax\n" /* line 797 */
        ".Lf7ba18_0007ba45:\n"
        "movl bg_weaponDefs(, %eax, 4), %ebx\n" /* line 521 */
        "movss 0xdc(%esi), %xmm0\n" /* line 4010 | ps */
        "movss %xmm0, -0x20(%ebp)\n" /* fPosLerp */
        "movl 0x40(%esi), %eax\n" /* line 4015 | ps */
        "testl %eax, %eax\n"
        "jle .Lf7ba18_0007bc04\n"
        ".Lf7ba18_0007ba64:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* line 4017 | 1.0f */
        "jne .Lf7ba18_0007bc65\n"
        "jp .Lf7ba18_0007bc65\n"
        "movss 0x2ed738, %xmm1\n" /* line 4018 | 0.009999999776482582f */
        "movss %xmm1, -0x1c(%ebp)\n" /* fReducePercent */
        "mulss 0x47c(%ebx), %xmm1\n" /* weapDef */
        "movss %xmm1, -0x1c(%ebp)\n" /* fReducePercent */
        ".Lf7ba18_0007ba91:\n"
        "movss 0x4a0(%ebx), %xmm0\n" /* line 4025 | weapDef */
        "movss %xmm0, -0x60(%ebp)\n"
        "movss 0x4a4(%ebx), %xmm1\n" /* weapDef */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll randomf\n"
        "fstps -0x5c(%ebp)\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss -0x5c(%ebp), %xmm1\n"
        "addss -0x60(%ebp), %xmm1\n"
        "movss 0x4a8(%ebx), %xmm0\n" /* line 4026 | weapDef */
        "movss %xmm0, -0x58(%ebp)\n"
        "movss 0x4ac(%ebx), %xmm0\n" /* weapDef */
        "subss -0x58(%ebp), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll randomf\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "mulss -0x54(%ebp), %xmm0\n"
        "addss -0x58(%ebp), %xmm0\n"
        "movss -0x78(%ebp), %xmm1\n"
        ".Lf7ba18_0007bb06:\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 4035 | fReducePercent */
        "mulss -0x1c(%ebp), %xmm1\n" /* line 4037 | fReducePercent */
        "xorps 0x2f09f0, %xmm1\n"
        "movss %xmm1, (%edi)\n" /* kickAVel */
        "movss %xmm0, 4(%edi)\n" /* line 4038 | kickAVel */
        "mulss 0x2ed63c, %xmm0\n" /* line 4039 | -0.5f */
        "movss %xmm0, 8(%edi)\n" /* kickAVel */
        "movss -0x20(%ebp), %xmm1\n" /* line 4042 | fPosLerp */
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "jbe .Lf7ba18_0007bcfa\n"
        "movss 0x480(%ebx), %xmm0\n" /* line 4044 | weapDef */
        "movss %xmm0, -0x40(%ebp)\n"
        "movss 0x484(%ebx), %xmm1\n" /* weapDef */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll randomf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss -0x3c(%ebp), %xmm1\n"
        "addss -0x40(%ebp), %xmm1\n"
        "movss 0x488(%ebx), %xmm0\n" /* line 4045 | weapDef */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 0x48c(%ebx), %xmm0\n" /* weapDef */
        "subss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll randomf\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "mulss -0x34(%ebp), %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        ".Lf7ba18_0007bbaf:\n"
        "movss -0x78(%ebp), %xmm1\n" /* line 4050 */
        "mulss -0x1c(%ebp), %xmm1\n" /* line 4056 | fReducePercent */
        "movl 0xc(%ebp), %eax\n" /* vGunSpeed */
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 4057 | fReducePercent */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 4058 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7ba18_0007bbdb:\n"
        "testb $0x10, %al\n" /* line 790 */
        "jne .Lf7ba18_0007bc20\n"
        "movl 0xd4(%esi), %eax\n" /* line 797 */
        "movl bg_weaponDefs(, %eax, 4), %ebx\n" /* line 521 */
        "movss 0xdc(%esi), %xmm0\n" /* line 4010 | ps */
        "movss %xmm0, -0x20(%ebp)\n" /* fPosLerp */
        "movl 0x40(%esi), %eax\n" /* line 4015 | ps */
        "testl %eax, %eax\n"
        "jg .Lf7ba18_0007ba64\n"
        ".Lf7ba18_0007bc04:\n"
        "movaps %xmm0, %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 4023 | 1.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf7ba18_0007bc7a\n"
        "jp .Lf7ba18_0007bc7a\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* fReducePercent */
        "jmp .Lf7ba18_0007ba91\n"
        ".Lf7ba18_0007bc20:\n"
        "movl 0xd0(%esi), %eax\n" /* line 792 */
        "jmp .Lf7ba18_0007ba45\n"
        ".Lf7ba18_0007bc2b:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7ba18_0007bd70\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7ba18_0007bc44:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jl .Lf7ba18_0007ba43\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7ba18_0007bc44\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7ba18_0007ba45\n"
        ".Lf7ba18_0007bc65:\n"
        "movss 0x2ed738, %xmm0\n" /* line 4020 | 0.009999999776482582f */
        "movss %xmm0, -0x1c(%ebp)\n" /* fReducePercent */
        "mulss 0x4c4(%ebx), %xmm0\n" /* weapDef */
        ".Lf7ba18_0007bc7a:\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* fReducePercent */
        "movss 0x4e8(%ebx), %xmm1\n" /* line 4030 | weapDef */
        "movss %xmm1, -0x50(%ebp)\n"
        "movss 0x4ec(%ebx), %xmm1\n" /* weapDef */
        "subss -0x50(%ebp), %xmm1\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll randomf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss -0x4c(%ebp), %xmm1\n"
        "addss -0x50(%ebp), %xmm1\n"
        "movss 0x4f0(%ebx), %xmm0\n" /* line 4031 | weapDef */
        "movss %xmm0, -0x48(%ebp)\n"
        "movss 0x4f4(%ebx), %xmm0\n" /* weapDef */
        "subss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll randomf\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "mulss -0x44(%ebp), %xmm0\n"
        "addss -0x48(%ebp), %xmm0\n"
        "movss -0x78(%ebp), %xmm1\n"
        "jmp .Lf7ba18_0007bb06\n"
        ".Lf7ba18_0007bcfa:\n"
        "movss 0x4c8(%ebx), %xmm1\n" /* line 4049 | weapDef */
        "movss %xmm1, -0x30(%ebp)\n"
        "movss 0x4cc(%ebx), %xmm1\n" /* weapDef */
        "subss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll randomf\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss -0x2c(%ebp), %xmm1\n"
        "addss -0x30(%ebp), %xmm1\n"
        "movss 0x4d0(%ebx), %xmm0\n" /* line 4050 | weapDef */
        "movss %xmm0, -0x28(%ebp)\n"
        "movss 0x4d4(%ebx), %xmm0\n" /* weapDef */
        "subss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll randomf\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "mulss -0x24(%ebp), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "jmp .Lf7ba18_0007bbaf\n"
        ".Lf7ba18_0007bd70:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7ba18_0007ba45\n"
    );
}

/* line 4814 */
__attribute__((naked))
void BG_CalculateWeaponPosition_Sway(playerState_t *ps, vec_t *swayViewAngles, vec_t *swayOffset, vec_t *swayAngles, float ssSwayScale, int frametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4814 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ps */
        "movss 0x18(%ebp), %xmm7\n" /* ssSwayScale */
        "movl 0x1c(%ebp), %esi\n" /* frametime */
        /* { scope 1 */
        "movss 0xdc(%edi), %xmm5\n" /* line 4822 | ps, f */
        "testl %esi, %esi\n" /* line 4826 | frametime */
        "je .Lf7bd7e_0007c0af\n"
        "movl 0xc(%edi), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf7bd7e_0007c0b7\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jg .Lf7bd7e_0007c125\n"
        ".Lf7bd7e_0007bdbe:\n"
        "xorl %eax, %eax\n" /* line 797 */
        ".Lf7bd7e_0007bdc0:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "cvtsi2ssl %esi, %xmm0\n" /* line 4832 | frametime */
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x3c(%ebp)\n" /* dt */
        "movl 0x32c(%eax), %ecx\n" /* line 4834 */
        "testl %ecx, %ecx\n"
        "je .Lf7bd7e_0007c0eb\n"
        ".Lf7bd7e_0007bde6:\n"
        "ucomiss 0x2ed5e8, %xmm5\n" /* line 4836 | 0.0f */
        "jbe .Lf7bd7e_0007bdfd\n"
        "movl 0x278(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf7bd7e_0007c0af\n"
        ".Lf7bd7e_0007bdfd:\n"
        "movss 0x2e8(%eax), %xmm0\n" /* line 4839 */
        "movss 0x304(%eax), %xmm6\n"
        "subss %xmm0, %xmm6\n"
        "mulss %xmm5, %xmm6\n"
        "addss %xmm0, %xmm6\n"
        "movss 0x2ec(%eax), %xmm0\n" /* line 4840 */
        "movss 0x308(%eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* swayLerpSpeed */
        "movss 0x2f0(%eax), %xmm0\n" /* line 4841 */
        "movss 0x30c(%eax), %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "addss %xmm0, %xmm4\n"
        "movss 0x2f4(%eax), %xmm0\n" /* line 4842 */
        "movss 0x310(%eax), %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm0, %xmm3\n"
        "movss 0x2f8(%eax), %xmm0\n" /* line 4843 */
        "movss 0x314(%eax), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm5, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "movss 0x2fc(%eax), %xmm0\n" /* line 4844 */
        "movss 0x318(%eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        ".Lf7bd7e_0007beaa:\n"
        "mulss %xmm7, %xmm4\n" /* line 4856 */
        "movss %xmm4, -0x2c(%ebp)\n"
        "mulss %xmm7, %xmm3\n" /* line 4857 */
        "movss %xmm3, -0x30(%ebp)\n"
        "mulss %xmm7, %xmm2\n" /* line 4858 */
        "movss %xmm2, -0x34(%ebp)\n"
        "mulss %xmm7, %xmm1\n" /* line 4859 */
        "movss %xmm1, -0x38(%ebp)\n"
        "leal 0xe8(%edi), %ebx\n" /* line 4862 | ps */
        "leal -0x24(%ebp), %eax\n" /* deltaAngles */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* swayViewAngles */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movss %xmm6, -0x58(%ebp)\n"
        "calll AnglesSubtract\n"
        "movss -0x3c(%ebp), %xmm1\n" /* line 4865 | dt */
        "mulss 0x2ed7c8, %xmm1\n" /* 60.0f */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f, scale */
        "divss %xmm1, %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm4\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm4\n" /* deltaAngles */
        "movaps %xmm0, %xmm5\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm5\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "movss -0x58(%ebp), %xmm6\n" /* line 4867 */
        "movaps %xmm6, %xmm2\n"
        "xorps 0x2f0a00, %xmm2\n"
        "movaps %xmm4, %xmm1\n" /* line 45 */
        "subss %xmm6, %xmm1\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm6, %xmm0\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm0\n"
        "andnps %xmm4, %xmm1\n"
        "orps %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* line 4867 | deltaAngles */
        "movaps %xmm5, %xmm0\n" /* line 45 */
        "subss %xmm6, %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "cmpnltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm5, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n" /* line 4868 */
        "movss -0x38(%ebp), %xmm0\n" /* line 4872 */
        "mulss -0x24(%ebp), %xmm0\n" /* deltaAngles */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0x3c(%ebp), %xmm1\n" /* line 4874 | dt */
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x40(%ebp), %xmm4\n" /* swayLerpSpeed */
        "movss %xmm4, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* swayOffset */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "mulss -0x34(%ebp), %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "calll DiffTrack\n"
        "movl 0x10(%ebp), %eax\n" /* swayOffset */
        "fstps 4(%eax)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 4875 | dt */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x40(%ebp), %xmm1\n" /* swayLerpSpeed */
        "movss %xmm1, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* swayOffset */
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll DiffTrack\n"
        "movl 0x10(%ebp), %eax\n" /* swayOffset */
        "fstps 8(%eax)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 4878 */
        "mulss -0x24(%ebp), %xmm0\n" /* deltaAngles */
        "movss %xmm0, -0x24(%ebp)\n" /* deltaAngles */
        "movss -0x30(%ebp), %xmm1\n" /* line 4879 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x3c(%ebp), %xmm4\n" /* line 4881 | dt */
        "movss %xmm4, 0xc(%esp)\n"
        "movss -0x40(%ebp), %xmm1\n" /* swayLerpSpeed */
        "movss %xmm1, 8(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* swayAngles */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll DiffTrackAngle\n"
        "movl 0x14(%ebp), %eax\n" /* swayAngles */
        "fstps (%eax)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 4882 | dt */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x40(%ebp), %xmm1\n" /* swayLerpSpeed */
        "movss %xmm1, 8(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* swayAngles */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DiffTrackAngle\n"
        "movl 0x14(%ebp), %eax\n" /* swayAngles */
        "fstps 4(%eax)\n"
        "movl 0xe8(%edi), %eax\n" /* line 199 */
        "movl 0xc(%ebp), %edx\n" /* swayViewAngles */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf7bd7e_0007c0af:\n"
        "addl $0x5c, %esp\n" /* line 4886 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7bd7e_0007c0b7:\n"
        "testb $0x10, %al\n" /* line 790 */
        "jne .Lf7bd7e_0007c15b\n"
        "movl 0xd4(%edi), %eax\n" /* line 797 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "cvtsi2ssl %esi, %xmm0\n" /* line 4832 | frametime */
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x3c(%ebp)\n" /* dt */
        "movl 0x32c(%eax), %ecx\n" /* line 4834 */
        "testl %ecx, %ecx\n"
        "jne .Lf7bd7e_0007bde6\n"
        ".Lf7bd7e_0007c0eb:\n"
        "movss 0x2e8(%eax), %xmm6\n" /* line 4848 */
        "movss 0x2ec(%eax), %xmm4\n" /* line 4849 */
        "movss %xmm4, -0x40(%ebp)\n" /* swayLerpSpeed */
        "movss 0x2f0(%eax), %xmm4\n" /* line 4850 */
        "movss 0x2f4(%eax), %xmm3\n" /* line 4851 */
        "movss 0x2f8(%eax), %xmm2\n" /* line 4852 */
        "movss 0x2fc(%eax), %xmm1\n" /* line 4853 */
        "jmp .Lf7bd7e_0007beaa\n"
        ".Lf7bd7e_0007c125:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7bd7e_0007c166\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7bd7e_0007c13a:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jl .Lf7bd7e_0007bdbe\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7bd7e_0007c13a\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7bd7e_0007bdc0\n"
        ".Lf7bd7e_0007c15b:\n"
        "movl 0xd0(%edi), %eax\n" /* line 792 */
        "jmp .Lf7bd7e_0007bdc0\n"
        ".Lf7bd7e_0007c166:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7bd7e_0007bdc0\n"
    );
}

/* line 808 */
__attribute__((naked))
int BG_GetFirstAvailableOffhand(const playerState_t *ps, int offhandClass)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 808 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        /* { scope 1 */
        "movl bg_iNumWeapons, %edi\n" /* line 560 */
        "testl %edi, %edi\n" /* line 818 | weapCount */
        "jle .Lf7c174_0007c1f7\n"
        "movl $1, %ebx\n" /* weapIndex */
        "movl $bg_weaponDefs, %esi\n"
        "jmp .Lf7c174_0007c19d\n"
        ".Lf7c174_0007c193:\n"
        "addl $1, %ebx\n" /* weapIndex */
        "addl $4, %esi\n"
        "cmpl %ebx, %edi\n" /* weapIndex, weapCount */
        "jl .Lf7c174_0007c1f7\n"
        ".Lf7c174_0007c19d:\n"
        "movl 4(%esi), %edx\n" /* line 521 */
        "movl 0xc(%ebp), %eax\n" /* line 822 | offhandClass */
        "cmpl %eax, 0x84(%edx)\n"
        "jne .Lf7c174_0007c193\n"
        "movl %ebx, %eax\n" /* line 825 | weapIndex */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n" /* weapIndex */
        "andl $0x1f, %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* ps */
        "movl 0x544(%ecx, %eax, 4), %eax\n"
        "movzbl -0x10(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c174_0007c193\n"
        "movl 0x1c8(%edx), %eax\n" /* line 828 */
        "movl 0x1d0(%edx), %edx\n"
        "movl 8(%ebp), %ecx\n" /* ps */
        "movl 0x144(%ecx, %eax, 4), %eax\n"
        "addl 0x344(%ecx, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7c174_0007c193\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 835 | weapIndex */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7c174_0007c1f7:\n"
        "xorl %ebx, %ebx\n" /* line 818 | weapIndex */
        /* } scope */
        "movl %ebx, %eax\n" /* line 835 | weapIndex */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1202 */
__attribute__((naked))
int BG_GetMaxPickupableAmmo(const playerState_t *ps, int weaponIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1202 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "leal -0x218(%ebp), %eax\n" /* line 1213 | ammoCounted */
        "movl $0x200, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal -0x418(%ebp), %eax\n" /* line 1214 | clipCounted */
        "movl $0x200, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0xc(%ebp), %eax\n" /* line 521 | weaponIndex */
        "movl bg_weaponDefs(, %eax, 4), %edi\n"
        "movl 0x1c8(%edi), %ecx\n" /* line 1736 | weapDef */
        "movl 0x1d0(%edi), %edx\n" /* line 1725 | weapDef */
        "movl 0x1e4(%edi), %eax\n" /* line 1219 | weapDef */
        "testl %eax, %eax\n"
        "js .Lf7c204_0007c371\n"
        "movl bg_sharedAmmoCaps(, %eax, 4), %eax\n" /* line 621 */
        "movl 0x1e8(%eax), %eax\n"
        "movl %eax, -0x41c(%ebp)\n" /* ammo */
        "movl bg_iNumWeapons, %eax\n" /* line 1223 */
        "movl %eax, -0x420(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf7c204_0007c325\n"
        "movl $1, %ebx\n" /* currWeap */
        "movl $bg_weaponDefs, %esi\n"
        "jmp .Lf7c204_0007c2b0\n"
        ".Lf7c204_0007c2a2:\n"
        "addl $1, %ebx\n" /* currWeap */
        "addl $4, %esi\n"
        "cmpl %ebx, -0x420(%ebp)\n" /* currWeap */
        "jl .Lf7c204_0007c325\n"
        ".Lf7c204_0007c2b0:\n"
        "movl %ebx, %eax\n" /* line 1225 | currWeap */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n" /* currWeap */
        "andl $0x1f, %ecx\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "movl 0x544(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c204_0007c2a2\n"
        "movl 4(%esi), %edx\n" /* line 521 */
        "movl 0x1e4(%edx), %eax\n" /* line 1229 */
        "cmpl 0x1e4(%edi), %eax\n" /* weapDef */
        "jne .Lf7c204_0007c2a2\n"
        "movl 0x340(%edx), %eax\n" /* line 1231 */
        "testl %eax, %eax\n"
        "je .Lf7c204_0007c336\n"
        "movl 0x1d0(%edx), %eax\n" /* line 1725 */
        "movl -0x418(%ebp, %eax, 4), %ecx\n" /* line 1233 */
        "testl %ecx, %ecx\n"
        "jne .Lf7c204_0007c2a2\n"
        "movl $1, -0x418(%ebp, %eax, 4)\n" /* line 1235 */
        "movl 0x1d0(%edx), %eax\n" /* line 1236 */
        "movl 8(%ebp), %edx\n" /* ps */
        "movl 0x344(%edx, %eax, 4), %edx\n"
        "subl %edx, -0x41c(%ebp)\n" /* ammo */
        "addl $1, %ebx\n" /* line 1223 | currWeap */
        "addl $4, %esi\n"
        "cmpl %ebx, -0x420(%ebp)\n" /* currWeap */
        "jge .Lf7c204_0007c2b0\n"
        ".Lf7c204_0007c325:\n"
        "movl -0x41c(%ebp), %eax\n" /* ammo */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7c204_0007c336:\n"
        "movl 0x1c8(%edx), %eax\n" /* line 1736 */
        "movl -0x218(%ebp, %eax, 4), %ecx\n" /* line 1241 */
        "testl %ecx, %ecx\n"
        "jne .Lf7c204_0007c2a2\n"
        "movl $1, -0x218(%ebp, %eax, 4)\n" /* line 1243 */
        "movl 0x1c8(%edx), %eax\n" /* line 1244 */
        "movl 8(%ebp), %edx\n" /* ps */
        "movl 0x144(%edx, %eax, 4), %edx\n"
        "subl %edx, -0x41c(%ebp)\n" /* ammo */
        "jmp .Lf7c204_0007c2a2\n"
        ".Lf7c204_0007c371:\n"
        "movl 0x340(%edi), %ebx\n" /* line 1252 | weapDef, currWeap */
        "testl %ebx, %ebx\n" /* currWeap */
        "jne .Lf7c204_0007c3ab\n"
        "movl bg_weapAmmoTypes(, %ecx, 4), %eax\n" /* line 1255 */
        "movl 0x1d4(%eax), %eax\n"
        "movl %eax, -0x41c(%ebp)\n" /* ammo */
        "movl 8(%ebp), %edx\n" /* ps */
        "movl 0x144(%edx, %ecx, 4), %edx\n"
        "subl %edx, %eax\n"
        "movl %eax, -0x41c(%ebp)\n" /* ammo */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7c204_0007c3ab:\n"
        "movl bg_weapClips(, %edx, 4), %eax\n" /* line 1253 */
        "movl 0x1d8(%eax), %eax\n"
        "movl %eax, -0x41c(%ebp)\n" /* ammo */
        "movl 8(%ebp), %eax\n" /* ps */
        "movl 0x344(%eax, %edx, 4), %eax\n"
        "subl %eax, -0x41c(%ebp)\n" /* ammo */
        "movl -0x41c(%ebp), %eax\n" /* ammo */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1438 */
__attribute__((naked))
void PM_UpdateAimDownSightFlag(pmove_t *pm, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1438 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1444 | pm */
        "movl (%eax), %ebx\n" /* ps */
        "movl 0xc(%ebx), %esi\n" /* line 1447 | ps */
        "movl %esi, -0x20(%ebp)\n"
        "movl %esi, %edi\n"
        "andl $0xffffffbf, %edi\n"
        "movl %edi, %esi\n"
        "movl %edi, 0xc(%ebx)\n" /* ps */
        "movl 4(%ebx), %eax\n" /* line 1367 */
        "cmpl $1, %eax\n"
        "je .Lf7c3e0_0007c465\n"
        "jl .Lf7c3e0_0007c46f\n"
        "cmpl $7, %eax\n"
        "jg .Lf7c3e0_0007c46f\n"
        ".Lf7c3e0_0007c40d:\n"
        "xorl %edx, %edx\n" /* line 1418 */
        ".Lf7c3e0_0007c40f:\n"
        "movl 8(%ebp), %eax\n" /* line 1450 | pm */
        "testb $0x10, 9(%eax)\n"
        "jne .Lf7c3e0_0007c4e2\n"
        "movl 0xd8(%ebx), %eax\n" /* ps */
        "subl $0x13, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf7c3e0_0007c4e2\n"
        ".Lf7c3e0_0007c42e:\n"
        "andl $0x40, %esi\n" /* line 1474 */
        "je .Lf7c3e0_0007c518\n"
        ".Lf7c3e0_0007c437:\n"
        "movl $1, 0xc(%esp)\n" /* line 1475 */
        "movl $1, 8(%esp)\n"
        "movl $7, 4(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_UpdateConditionValue\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1479 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7c3e0_0007c465:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1372 | pml */
        "movl 0x34(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf7c3e0_0007c40d\n"
        ".Lf7c3e0_0007c46f:\n"
        "testl $0x20000, %edi\n" /* line 785 */
        "je .Lf7c3e0_0007c546\n"
        "movl bg_iNumWeapons, %eax\n" /* line 771 */
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n"
        "jg .Lf7c3e0_0007c566\n"
        ".Lf7c3e0_0007c48b:\n"
        "xorl %eax, %eax\n" /* line 797 */
        ".Lf7c3e0_0007c48d:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 1401 */
        "movl 0x32c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7c3e0_0007c40d\n"
        "movl 0xd8(%ebx), %edx\n" /* line 1405 */
        "leal -0xc(%edx), %eax\n"
        "cmpl $4, %eax\n"
        "jbe .Lf7c3e0_0007c40d\n"
        "leal -0xa(%edx), %eax\n" /* line 1409 */
        "cmpl $1, %eax\n"
        "jbe .Lf7c3e0_0007c40d\n"
        "leal -1(%edx), %eax\n" /* line 1413 */
        "cmpl $1, %eax\n"
        "jbe .Lf7c3e0_0007c40d\n"
        "leal -0x11(%edx), %eax\n" /* line 1417 */
        "cmpl $5, %eax\n"
        "jbe .Lf7c3e0_0007c5a8\n"
        "movl $1, %edx\n" /* line 1418 */
        "jmp .Lf7c3e0_0007c40f\n"
        ".Lf7c3e0_0007c4e2:\n"
        "testb %dl, %dl\n" /* line 1452 */
        "je .Lf7c3e0_0007c42e\n"
        "testb $1, -0x20(%ebp)\n" /* line 1455 */
        "je .Lf7c3e0_0007c559\n"
        "movl 8(%ebp), %eax\n" /* line 1458 | pm */
        "testb $0x10, 0x25(%eax)\n"
        "je .Lf7c3e0_0007c504\n"
        "cmpw $0, 0x1c(%eax)\n"
        "jne .Lf7c3e0_0007c42e\n"
        ".Lf7c3e0_0007c504:\n"
        "movl %edi, %esi\n" /* line 1463 */
        "orl $0x840, %esi\n"
        "movl %esi, 0xc(%ebx)\n" /* ps */
        "andl $0x40, %esi\n" /* line 1474 */
        "jne .Lf7c3e0_0007c437\n"
        ".Lf7c3e0_0007c518:\n"
        "movl $1, 0xc(%esp)\n" /* line 1477 */
        "movl $0, 8(%esp)\n"
        "movl $7, 4(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_UpdateConditionValue\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1479 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7c3e0_0007c546:\n"
        "testl $0x10, %edi\n" /* line 790 */
        "jne .Lf7c3e0_0007c59d\n"
        "movl 0xd4(%ebx), %eax\n" /* line 797 */
        "jmp .Lf7c3e0_0007c48d\n"
        ".Lf7c3e0_0007c559:\n"
        "movl %edi, %esi\n" /* line 1469 */
        "orl $0x40, %esi\n"
        "movl %esi, 0xc(%ebx)\n" /* ps */
        "jmp .Lf7c3e0_0007c42e\n"
        ".Lf7c3e0_0007c566:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7c3e0_0007c5be\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7c3e0_0007c57b:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, -0x1c(%ebp)\n"
        "jl .Lf7c3e0_0007c48b\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7c3e0_0007c57b\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7c3e0_0007c48d\n"
        ".Lf7c3e0_0007c59d:\n"
        "movl 0xd0(%ebx), %eax\n" /* line 792 */
        "jmp .Lf7c3e0_0007c48d\n"
        ".Lf7c3e0_0007c5a8:\n"
        "leal -0x13(%edx), %eax\n" /* line 1418 */
        "cmpl $1, %eax\n"
        "ja .Lf7c3e0_0007c40d\n"
        "movl $1, %edx\n"
        "jmp .Lf7c3e0_0007c40f\n"
        ".Lf7c3e0_0007c5be:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7c3e0_0007c48d\n"
    );
}

/* line 895 */
__attribute__((naked))
Bool BG_IsWeaponValid(const playerState_t *ps, int weaponIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 895 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* ps */
        "movl 0xc(%ebp), %edx\n" /* weaponIndex */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 877 */
        "js .Lf7c5cc_0007c5e3\n"
        "cmpl bg_iNumWeapons, %edx\n"
        "jle .Lf7c5cc_0007c63d\n"
        ".Lf7c5cc_0007c5e3:\n"
        "xorl %ebx, %ebx\n"
        ".Lf7c5cc_0007c5e5:\n"
        "movl %edx, %eax\n" /* line 904 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%esi, %eax, 4), %eax\n" /* ps */
        "sarl %cl, %eax\n"
        "xorl %ecx, %ecx\n"
        "testb $1, %al\n"
        "cmovnel %ebx, %ecx\n" /* altIndex */
        "movl bg_weaponDefs(, %edx, 4), %eax\n" /* line 521 */
        "movl 0x84(%eax), %ebx\n" /* line 909 | altIndex */
        "testl %ebx, %ebx\n" /* altIndex */
        "jne .Lf7c5cc_0007c636\n"
        "movl 0x36c(%eax), %ebx\n" /* line 911 | altIndex */
        "movsbl 0x555(%esi), %eax\n" /* line 913 | ps */
        "cmpl %eax, %edx\n"
        "je .Lf7c5cc_0007c636\n"
        "movsbl 0x556(%esi), %eax\n" /* ps */
        "cmpl %eax, %edx\n"
        "je .Lf7c5cc_0007c636\n"
        "cmpl %ebx, %edx\n" /* altIndex */
        "je .Lf7c5cc_0007c636\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 918 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7c5cc_0007c636:\n"
        "movzbl %cl, %eax\n" /* line 913 */
        /* } scope */
        "popl %ebx\n" /* line 918 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7c5cc_0007c63d:\n"
        "movl $1, %ebx\n" /* line 877 */
        "jmp .Lf7c5cc_0007c5e5\n"
    );
}

/* line 944 */
__attribute__((naked))
qboolean BG_TakePlayerWeapon(playerState_t *pPS, int iWeaponIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 944 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %edi\n" /* pPS */
        /* { scope 1: curWeapDef */
        "leal 0x544(%edi), %esi\n" /* line 952 | pPS */
        "movl 0xc(%ebp), %eax\n" /* line 807 | iWeaponIndex */
        "sarl $5, %eax\n"
        "leal (, %eax, 4), %ebx\n"
        "movl 0xc(%ebp), %eax\n" /* iWeaponIndex */
        "andl $0x1f, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x544(%edi, %ebx), %eax\n" /* line 952 | pPS */
        "movzbl -0x1c(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c644_0007c77f\n"
        "movl 0xc(%ebp), %eax\n" /* line 521 | iWeaponIndex */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* weapDef */
        /* { scope 2 */
        "movl 0xc(%ebp), %edx\n" /* line 1056 | iWeaponIndex */
        ".Lf7c644_0007c691:\n"
        "movl bg_weaponDefs(, %edx, 4), %ecx\n" /* line 521 */
        "movl 0x80(%ecx), %eax\n" /* line 1065 */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf7c644_0007c6d4\n"
        "movsbl 0x555(%edi), %eax\n" /* line 1070 | pPS */
        "cmpl %eax, %edx\n"
        "je .Lf7c644_0007c789\n"
        "movsbl 0x556(%edi), %eax\n" /* line 1072 | pPS */
        "cmpl %eax, %edx\n"
        "je .Lf7c644_0007c876\n"
        "movl 0x36c(%ecx), %eax\n" /* line 1080 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %edx\n"
        "cmpl 0xc(%ebp), %edx\n" /* line 1061 | iWeaponIndex */
        "jne .Lf7c644_0007c691\n"
        /* } scope */
        ".Lf7c644_0007c6d4:\n"
        "movl $0xfffffffe, %eax\n" /* line 817 */
        "movzbl -0x1c(%ebp), %ecx\n"
        "roll %cl, %eax\n"
        "andl %eax, (%esi, %ebx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 985 | weapDef */
        "movl 0x36c(%eax), %edx\n"
        "testl %edx, %edx\n" /* line 986 */
        "jne .Lf7c644_0007c707\n"
        ".Lf7c644_0007c6ef:\n"
        "movl 0xc(%ebp), %eax\n" /* line 992 | iWeaponIndex */
        "cmpl 0xd4(%edi), %eax\n" /* pPS */
        "je .Lf7c644_0007c768\n"
        ".Lf7c644_0007c6fa:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 996 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: curWeapDef */
        ".Lf7c644_0007c707:\n"
        "movl %edx, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, %ebx\n"
        "andl $0x1f, %ebx\n"
        "movl (%esi, %eax), %eax\n" /* line 986 */
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c644_0007c6ef\n"
        ".Lf7c644_0007c722:\n"
        "movl $0xfffffffe, %eax\n" /* line 817 */
        "movl %ebx, %ecx\n"
        "roll %cl, %eax\n"
        "movl -0x2c(%ebp), %ecx\n"
        "andl %eax, (%esi, %ecx)\n"
        "movl bg_weaponDefs(, %edx, 4), %eax\n" /* line 989 */
        "movl 0x36c(%eax), %edx\n"
        "testl %edx, %edx\n" /* line 986 */
        "je .Lf7c644_0007c6ef\n"
        "movl %edx, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, %ebx\n"
        "andl $0x1f, %ebx\n"
        "movl (%eax, %esi), %eax\n" /* line 986 */
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf7c644_0007c722\n"
        "movl 0xc(%ebp), %eax\n" /* line 992 | iWeaponIndex */
        "cmpl 0xd4(%edi), %eax\n" /* pPS */
        "jne .Lf7c644_0007c6fa\n"
        ".Lf7c644_0007c768:\n"
        "movl $0, 0xd4(%edi)\n" /* line 993 | pPS */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 996 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: curWeapDef */
        ".Lf7c644_0007c77f:\n"
        "xorl %eax, %eax\n" /* line 952 */
        /* } scope */
        "addl $0x20, %esp\n" /* line 996 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: curWeapDef */
        /* { scope 2 */
        ".Lf7c644_0007c789:\n"
        "movl $1, -0x10(%ebp)\n" /* line 1070 */
        /* } scope */
        ".Lf7c644_0007c790:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 961 | weapDef */
        "movl 0x88(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7c644_0007c866\n"
        "movl bg_iNumWeapons, %ecx\n" /* line 963 */
        "movl %ecx, -0x24(%ebp)\n"
        "testl %ecx, %ecx\n"
        "jle .Lf7c644_0007c856\n"
        "movl $1, %edx\n"
        ".Lf7c644_0007c7b7:\n"
        "movl %edx, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl %edx, %eax\n"
        "andl $0x1f, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x18(%ebp), %ecx\n" /* line 967 */
        "movl (%esi, %ecx), %eax\n"
        "movzbl -0x2c(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c644_0007c882\n"
        /* { scope 2 */
        "movl -0x18(%ebp), %ecx\n" /* line 1056 */
        "movl 0x544(%edi, %ecx), %eax\n" /* pPS */
        "movzbl -0x2c(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c644_0007c840\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl %edx, %eax\n"
        ".Lf7c644_0007c7f7:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "movl %eax, -0x14(%ebp)\n" /* curWeapDef */
        "movl 0x80(%eax), %ecx\n" /* line 1065 */
        "subl $1, %ecx\n"
        "cmpl $1, %ecx\n"
        "ja .Lf7c644_0007c840\n"
        "movsbl 0x555(%edi), %eax\n" /* line 1070 | pPS */
        "cmpl %eax, -0x2c(%ebp)\n"
        "je .Lf7c644_0007c882\n"
        "movsbl 0x556(%edi), %eax\n" /* line 1072 | pPS */
        "cmpl %eax, -0x2c(%ebp)\n"
        "je .Lf7c644_0007c882\n"
        "movl -0x14(%ebp), %eax\n" /* line 1080 | curWeapDef */
        "movl 0x36c(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "testl %eax, %eax\n"
        "cmovel -0x2c(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "cmpl %edx, %eax\n" /* line 1061 */
        "jne .Lf7c644_0007c7f7\n"
        /* } scope */
        ".Lf7c644_0007c840:\n"
        "movl -0x10(%ebp), %ecx\n" /* line 969 */
        "movb %dl, 0x554(%ecx, %edi)\n"
        "cmpl bg_iNumWeapons, %edx\n" /* line 974 */
        "jle .Lf7c644_0007c6d4\n"
        ".Lf7c644_0007c856:\n"
        "movl -0x10(%ebp), %eax\n" /* line 975 */
        "movb $0, 0x554(%eax, %edi)\n"
        "jmp .Lf7c644_0007c6d4\n"
        ".Lf7c644_0007c866:\n"
        "movl -0x10(%ebp), %ecx\n" /* line 979 */
        "movb $0, 0x554(%ecx, %edi)\n"
        "jmp .Lf7c644_0007c6d4\n"
        /* { scope 2 */
        ".Lf7c644_0007c876:\n"
        "movl $2, -0x10(%ebp)\n" /* line 1072 */
        "jmp .Lf7c644_0007c790\n"
        /* } scope */
        ".Lf7c644_0007c882:\n"
        "addl $1, %edx\n" /* line 963 */
        "cmpl %edx, -0x24(%ebp)\n"
        "jge .Lf7c644_0007c7b7\n"
        "jmp .Lf7c644_0007c856\n"
    );
}

/* line 2093 */
static __attribute__((naked))
void PM_BeginWeaponChange(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2093 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ebx\n" /* ps */
        "movl %edx, %esi\n" /* newweapon */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 2102 */
        "je .Lf7c890_0007c8b8\n"
        "movl %edx, %eax\n"
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%ebx, %eax, 4), %eax\n" /* ps */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c890_0007c924\n"
        ".Lf7c890_0007c8b8:\n"
        "cmpl $2, 0xd8(%ebx)\n" /* line 2105 | ps */
        "je .Lf7c890_0007c924\n"
        "movl $0, 0x38(%ebx)\n" /* line 2109 | ps */
        "movl 0xd4(%ebx), %edi\n" /* line 2111 | ps */
        "testl %edi, %edi\n" /* line 2116 */
        "je .Lf7c890_0007c904\n"
        "leal 0x544(%ebx), %eax\n" /* ps */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edi, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edi, %edx\n"
        "andl $0x1f, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x544(%ebx, %eax), %eax\n" /* line 2116 | ps */
        "movl %edx, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c890_0007c904\n"
        "movl 0x3c(%ebx), %eax\n" /* ps */
        "testl %eax, %eax\n"
        "jle .Lf7c890_0007c92c\n"
        ".Lf7c890_0007c904:\n"
        "movl $0, 0x34(%ebx)\n" /* line 2119 | ps */
        "movl $2, 0xd8(%ebx)\n" /* line 2120 | ps */
        "movl $0, 0x3c(%ebx)\n" /* line 2121 | ps */
        "movl %ebx, (%esp)\n" /* line 2123 | ps */
        "calll PM_SetProneMovementOverride\n"
        /* } scope */
        ".Lf7c890_0007c924:\n"
        "addl $0x3c, %esp\n" /* line 2177 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7c890_0007c92c:\n"
        "movl bg_weaponDefs(, %edi, 4), %edx\n" /* line 521 */
        "movl %edx, -0x24(%ebp)\n" /* oldWeapDef */
        "testl %esi, %esi\n" /* line 2129 | newweapon */
        "jne .Lf7c890_0007ca1a\n"
        ".Lf7c890_0007c93e:\n"
        "movb $0, -0x25(%ebp)\n"
        ".Lf7c890_0007c942:\n"
        "movl -0x24(%ebp), %edx\n" /* line 2133 | oldWeapDef */
        "movl 0x340(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7c890_0007ca32\n"
        "movl 0x1d0(%edx), %eax\n" /* line 2135 */
        "movl 0x344(%ebx, %eax, 4), %eax\n" /* ps */
        "testl %eax, %eax\n"
        "jne .Lf7c890_0007ca32\n"
        "xorl %eax, %eax\n"
        ".Lf7c890_0007c96a:\n"
        "movl $0, 0x3c(%ebx)\n" /* line 2140 | ps */
        "cmpb $0, -0x25(%ebp)\n" /* line 2142 */
        "jne .Lf7c890_0007ca4d\n"
        "testl %eax, %eax\n" /* line 2148 */
        "jne .Lf7c890_0007caa8\n"
        ".Lf7c890_0007c983:\n"
        "testb $4, 0xc(%ebx)\n" /* line 2156 | ps */
        "je .Lf7c890_0007ca83\n"
        ".Lf7c890_0007c98d:\n"
        "movl $2, 0xd8(%ebx)\n" /* line 2160 | ps */
        "movl %ebx, (%esp)\n" /* line 2162 | ps */
        "calll PM_SetProneMovementOverride\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 2164 */
        "je .Lf7c890_0007ca3c\n"
        "movl -0x24(%ebp), %ecx\n" /* line 2165 | oldWeapDef */
        "movl 0x238(%ecx), %eax\n"
        "movl %eax, 0x34(%ebx)\n" /* ps */
        /* { scope 2 */
        /* { scope 3 */
        "movl -0x20(%ebp), %edx\n" /* line 1056 */
        "movl 0x544(%ebx, %edx), %eax\n"
        "movzbl -0x1c(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c890_0007c924\n"
        /* } scope */
        /* } scope */
        "movl %edi, %edx\n" /* line 2167 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf7c890_0007c9cf:\n"
        "movl bg_weaponDefs(, %edx, 4), %ecx\n" /* line 521 */
        "movl 0x80(%ecx), %eax\n" /* line 1065 */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf7c890_0007c924\n"
        "movsbl 0x555(%ebx), %eax\n" /* line 1070 */
        "cmpl %eax, %edx\n"
        "je .Lf7c890_0007cade\n"
        "movsbl 0x556(%ebx), %eax\n" /* line 1072 */
        "cmpl %eax, %edx\n"
        "je .Lf7c890_0007cb4e\n"
        "movl 0x36c(%ecx), %eax\n" /* line 1080 */
        "testl %eax, %eax\n"
        "cmovnel %eax, %edx\n"
        "cmpl %edi, %edx\n" /* line 1061 */
        "jne .Lf7c890_0007c9cf\n"
        "jmp .Lf7c890_0007c924\n"
        /* } scope */
        /* } scope */
        ".Lf7c890_0007ca1a:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2129 | oldWeapDef */
        "cmpl 0x36c(%eax), %esi\n" /* newweapon */
        "jne .Lf7c890_0007c93e\n"
        "movb $1, -0x25(%ebp)\n"
        "jmp .Lf7c890_0007c942\n"
        ".Lf7c890_0007ca32:\n"
        "movl $1, %eax\n" /* line 2135 */
        "jmp .Lf7c890_0007c96a\n"
        ".Lf7c890_0007ca3c:\n"
        "movl -0x24(%ebp), %edi\n" /* line 2167 | oldWeapDef */
        "movl 0x230(%edi), %eax\n"
        "movl %eax, 0x34(%ebx)\n" /* ps */
        "jmp .Lf7c890_0007c924\n"
        ".Lf7c890_0007ca4d:\n"
        "movl $0x9c, 4(%esp)\n" /* line 2144 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jg .Lf7c890_0007c98d\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0xf, %eax\n"
        "movl %eax, 0x5d0(%ebx)\n"
        "jmp .Lf7c890_0007c98d\n"
        ".Lf7c890_0007ca83:\n"
        "movl $0, 0xc(%esp)\n" /* line 2157 */
        "movl $0, 8(%esp)\n"
        "movl $6, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "jmp .Lf7c890_0007c98d\n"
        ".Lf7c890_0007caa8:\n"
        "movl $0x9b, 4(%esp)\n" /* line 2150 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jg .Lf7c890_0007c983\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $9, %eax\n"
        "movl %eax, 0x5d0(%ebx)\n"
        "jmp .Lf7c890_0007c983\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf7c890_0007cade:\n"
        "movl $1, %edx\n" /* line 1070 */
        /* } scope */
        ".Lf7c890_0007cae3:\n"
        "movl %esi, %eax\n" /* line 1012 */
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl -0x2c(%ebp), %edi\n"
        "movl (%edi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7c890_0007c924\n"
        "movl bg_weaponDefs(, %esi, 4), %eax\n" /* line 1017 */
        "movl 0x80(%eax), %eax\n"
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf7c890_0007c924\n"
        "leal -1(%edx), %eax\n" /* line 1022 */
        "cmpl $1, %eax\n"
        "ja .Lf7c890_0007c924\n"
        "movsbl 0x554(%edx, %ebx), %eax\n" /* line 1031 */
        "cmpl %eax, %esi\n"
        "je .Lf7c890_0007cb40\n"
        "cmpl 0xd4(%ebx), %esi\n"
        "je .Lf7c890_0007cb40\n"
        "movl $0, 0xd4(%ebx)\n" /* line 1032 */
        ".Lf7c890_0007cb40:\n"
        "movl %esi, %eax\n" /* line 1035 */
        "movb %al, 0x554(%edx, %ebx)\n"
        "jmp .Lf7c890_0007c924\n"
        /* } scope */
        ".Lf7c890_0007cb4e:\n"
        "movl $2, %edx\n" /* line 2156 */
        "jmp .Lf7c890_0007cae3\n"
    );
}

/* line 2011 */
static __attribute__((naked))
void PM_SetReloadingState(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2011 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %ebx\n" /* ps */
        /* { scope 1 */
        "movl 0xd4(%eax), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %edx\n"
        "movl 0x1d0(%edx), %eax\n" /* line 2019 */
        "movl 0x344(%ebx, %eax, 4), %edi\n" /* ps, reloadTime */
        "testl %edi, %edi\n" /* reloadTime */
        "jne .Lf7cb56_0007cb8a\n"
        "movl 0x78(%edx), %esi\n" /* iWeapon */
        "testl %esi, %esi\n" /* iWeapon */
        "je .Lf7cb56_0007cc86\n"
        ".Lf7cb56_0007cb8a:\n"
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jle .Lf7cb56_0007cc42\n"
        ".Lf7cb56_0007cb94:\n"
        "movl 0x218(%edx), %eax\n" /* line 2029 */
        "movl %eax, 0x34(%ebx)\n" /* ps */
        "movl $0x96, 4(%esp)\n" /* line 2031 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        ".Lf7cb56_0007cbad:\n"
        "xorl %eax, %eax\n" /* line 2035 */
        "cmpl $8, 0xd8(%ebx)\n" /* ps */
        "sete %al\n"
        "addl $5, %eax\n"
        "movl %eax, 0xd8(%ebx)\n" /* ps */
        /* { scope 2 */
        "movl 0xd4(%ebx), %esi\n" /* line 1956 | iWeapon */
        /* { scope 3 */
        "movl bg_weaponDefs(, %esi, 4), %edx\n" /* line 521 */
        /* } scope */
        "subl $7, %eax\n" /* line 1958 */
        "cmpl $1, %eax\n"
        "jbe .Lf7cb56_0007ccaa\n"
        "movl 0x1d0(%edx), %eax\n" /* line 1976 */
        "movl 0x344(%ebx, %eax, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf7cb56_0007cc33\n"
        ".Lf7cb56_0007cbec:\n"
        "movl 0x218(%edx), %edi\n" /* line 1979 | reloadTime */
        ".Lf7cb56_0007cbf2:\n"
        "movl 0x220(%edx), %eax\n" /* line 1981 */
        "testl %eax, %eax\n"
        "jne .Lf7cb56_0007cc2c\n"
        ".Lf7cb56_0007cbfc:\n"
        "movl 0x328(%edx), %eax\n" /* line 1986 */
        "testl %eax, %eax\n"
        "je .Lf7cb56_0007cc1d\n"
        "movl %esi, %eax\n" /* iWeapon */
        "sarl $5, %eax\n"
        "andl $0x1f, %esi\n" /* iWeapon */
        "movl 0x55c(%ebx, %eax, 4), %eax\n"
        "movl %esi, %ecx\n" /* iWeapon */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf7cb56_0007cc5e\n"
        ".Lf7cb56_0007cc1d:\n"
        "testl %edi, %edi\n" /* line 1999 | reloadTime */
        "je .Lf7cb56_0007cc24\n"
        "movl %edi, 0x38(%ebx)\n" /* line 2001 | reloadTime */
        /* } scope */
        /* } scope */
        ".Lf7cb56_0007cc24:\n"
        "addl $0x1c, %esp\n" /* line 2040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf7cb56_0007cc2c:\n"
        "cmpl %eax, %edi\n" /* line 1981 | reloadTime */
        "cmovgl %eax, %edi\n" /* reloadTime */
        "jmp .Lf7cb56_0007cbfc\n"
        ".Lf7cb56_0007cc33:\n"
        "movl 0x78(%edx), %eax\n" /* line 1976 */
        "testl %eax, %eax\n"
        "jne .Lf7cb56_0007cbec\n"
        "movl 0x21c(%edx), %edi\n" /* line 1977 | reloadTime */
        "jmp .Lf7cb56_0007cbf2\n"
        /* } scope */
        ".Lf7cb56_0007cc42:\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0xb, %eax\n"
        "movl %eax, 0x5d0(%ebx)\n"
        "jmp .Lf7cb56_0007cb94\n"
        /* { scope 2 */
        ".Lf7cb56_0007cc5e:\n"
        "testl %edi, %edi\n" /* line 1988 | reloadTime */
        "je .Lf7cb56_0007cd02\n"
        "movl 0x20c(%edx), %eax\n" /* line 1991 */
        "cmpl %eax, %edi\n" /* reloadTime */
        "cmovlel %edi, %eax\n" /* reloadTime */
        "testl %eax, %eax\n" /* line 1994 */
        "movl $1, %edx\n"
        "cmovel %edx, %eax\n"
        "movl %eax, 0x38(%ebx)\n" /* line 1997 */
        /* } scope */
        /* } scope */
        ".Lf7cb56_0007cc7e:\n"
        "addl $0x1c, %esp\n" /* line 2040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7cb56_0007cc86:\n"
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jle .Lf7cb56_0007cccd\n"
        "movl 0x21c(%edx), %eax\n" /* line 2022 */
        "movl %eax, 0x34(%ebx)\n" /* ps */
        "movl $0x97, 4(%esp)\n" /* line 2024 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        "jmp .Lf7cb56_0007cbad\n"
        /* { scope 2 */
        ".Lf7cb56_0007ccaa:\n"
        "movl 0x228(%edx), %edi\n" /* line 1960 | reloadTime */
        "testl %edi, %edi\n" /* reloadTime */
        "je .Lf7cb56_0007cbfc\n"
        "movl 0x224(%edx), %eax\n" /* line 1962 */
        "cmpl %eax, %edi\n" /* reloadTime */
        "jl .Lf7cb56_0007cbfc\n"
        "movl %eax, %edi\n" /* reloadTime */
        "jmp .Lf7cb56_0007cbfc\n"
        /* } scope */
        ".Lf7cb56_0007cccd:\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0xc, %eax\n"
        "movl %eax, 0x5d0(%ebx)\n"
        "movl 0x21c(%edx), %eax\n" /* line 2022 */
        "movl %eax, 0x34(%ebx)\n" /* ps */
        "movl $0x97, 4(%esp)\n" /* line 2024 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        "jmp .Lf7cb56_0007cbad\n"
        /* { scope 2 */
        ".Lf7cb56_0007cd02:\n"
        "movl 0x34(%ebx), %edi\n" /* line 1989 | reloadTime */
        "movl 0x20c(%edx), %eax\n" /* line 1991 */
        "cmpl %eax, %edi\n" /* reloadTime */
        "cmovlel %edi, %eax\n" /* reloadTime */
        "testl %eax, %eax\n" /* line 1994 */
        "movl $1, %edx\n"
        "cmovel %edx, %eax\n"
        "movl %eax, 0x38(%ebx)\n" /* line 1997 */
        "jmp .Lf7cb56_0007cc7e\n"
    );
}

/* line 2048 */
static __attribute__((naked))
void PM_BeginWeaponReload(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2048 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %ebx\n" /* ps */
        /* { scope 1 */
        "movl 0xd4(%eax), %edx\n" /* line 2052 | iWeapon */
        /* { scope 2 */
        "movl bg_weaponDefs(, %edx, 4), %esi\n" /* line 521 */
        /* } scope */
        "movl 0xd8(%eax), %eax\n" /* line 2055 */
        "testl %eax, %eax\n"
        "je .Lf7cd22_0007cd56\n"
        "cmpl $3, %eax\n"
        "je .Lf7cd22_0007cd56\n"
        "cmpl $4, %eax\n"
        "je .Lf7cd22_0007cd56\n"
        /* } scope */
        ".Lf7cd22_0007cd4e:\n"
        "addl $0x1c, %esp\n" /* line 2083 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7cd22_0007cd56:\n"
        "testl %edx, %edx\n" /* line 2058 */
        "je .Lf7cd22_0007cd4e\n"
        "cmpl bg_iNumWeapons, %edx\n"
        "jg .Lf7cd22_0007cd4e\n"
        "movl 0x340(%esi), %eax\n" /* line 2062 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7cd22_0007ce8f\n"
        ".Lf7cd22_0007cd70:\n"
        "movl $0x95, 4(%esp)\n" /* line 2066 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        "movl 0x35c(%esi), %eax\n" /* line 2068 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7cd22_0007ce71\n"
        "movl 0x224(%esi), %eax\n" /* weapDef */
        "testl %eax, %eax\n"
        "je .Lf7cd22_0007ce71\n"
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jg .Lf7cd22_0007cdb9\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0xd, %eax\n"
        "movl %eax, 0x5d0(%ebx)\n"
        ".Lf7cd22_0007cdb9:\n"
        "movl 0x224(%esi), %eax\n" /* line 2072 | weapDef */
        "movl %eax, 0x34(%ebx)\n" /* ps */
        "movl $7, 0xd8(%ebx)\n" /* line 2074 | ps */
        "movl $0x98, 4(%esp)\n" /* line 2075 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        /* { scope 2 */
        "movl 0xd4(%ebx), %esi\n" /* line 1956 | iWeapon */
        /* { scope 3 */
        "movl bg_weaponDefs(, %esi, 4), %edx\n" /* line 521 */
        /* } scope */
        "movl 0xd8(%ebx), %eax\n" /* line 1958 */
        "subl $7, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf7cd22_0007cebf\n"
        "movl 0x1d0(%edx), %eax\n" /* line 1976 */
        "movl 0x344(%ebx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf7cd22_0007ce17\n"
        "movl 0x78(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7cd22_0007ceb4\n"
        ".Lf7cd22_0007ce17:\n"
        "movl 0x218(%edx), %edi\n" /* line 1979 | reloadTime */
        ".Lf7cd22_0007ce1d:\n"
        "movl 0x220(%edx), %eax\n" /* line 1981 */
        "testl %eax, %eax\n"
        "je .Lf7cd22_0007ce2c\n"
        "cmpl %eax, %edi\n" /* reloadTime */
        "cmovgl %eax, %edi\n" /* reloadTime */
        ".Lf7cd22_0007ce2c:\n"
        "movl 0x328(%edx), %eax\n" /* line 1986 */
        "testl %eax, %eax\n"
        "je .Lf7cd22_0007ce7f\n"
        "movl %esi, %eax\n" /* iWeapon */
        "sarl $5, %eax\n"
        "andl $0x1f, %esi\n" /* iWeapon */
        "movl 0x55c(%ebx, %eax, 4), %eax\n"
        "movl %esi, %ecx\n" /* iWeapon */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7cd22_0007ce7f\n"
        "testl %edi, %edi\n" /* line 1988 | reloadTime */
        "jne .Lf7cd22_0007ce54\n"
        "movl 0x34(%ebx), %edi\n" /* line 1989 | reloadTime */
        ".Lf7cd22_0007ce54:\n"
        "movl 0x20c(%edx), %eax\n" /* line 1991 */
        "cmpl %eax, %edi\n" /* reloadTime */
        "cmovlel %edi, %eax\n" /* reloadTime */
        "testl %eax, %eax\n" /* line 1994 */
        "movl $1, %edx\n"
        "cmovel %edx, %eax\n"
        "movl %eax, 0x38(%ebx)\n" /* line 1997 */
        "jmp .Lf7cd22_0007cd4e\n"
        /* } scope */
        ".Lf7cd22_0007ce71:\n"
        "movl %ebx, %eax\n" /* line 2081 | ps */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2083 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp PM_SetReloadingState\n" /* line 2081 */
        /* { scope 2 */
        ".Lf7cd22_0007ce7f:\n"
        "testl %edi, %edi\n" /* line 1999 | reloadTime */
        "je .Lf7cd22_0007cd4e\n"
        "movl %edi, 0x38(%ebx)\n" /* line 2001 | reloadTime */
        "jmp .Lf7cd22_0007cd4e\n"
        /* } scope */
        ".Lf7cd22_0007ce8f:\n"
        "movl $1, 0xc(%esp)\n" /* line 2063 */
        "movl $0, 8(%esp)\n"
        "movl $0xa, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "jmp .Lf7cd22_0007cd70\n"
        /* { scope 2 */
        ".Lf7cd22_0007ceb4:\n"
        "movl 0x21c(%edx), %edi\n" /* line 1977 | reloadTime */
        "jmp .Lf7cd22_0007ce1d\n"
        ".Lf7cd22_0007cebf:\n"
        "movl 0x228(%edx), %edi\n" /* line 1960 | reloadTime */
        "testl %edi, %edi\n" /* reloadTime */
        "je .Lf7cd22_0007ce2c\n"
        "movl 0x224(%edx), %eax\n" /* line 1962 */
        "cmpl %eax, %edi\n" /* reloadTime */
        "jl .Lf7cd22_0007ce2c\n"
        "movl %eax, %edi\n" /* reloadTime */
        "jmp .Lf7cd22_0007ce2c\n"
    );
}

/* line 1489 */
__attribute__((naked))
void PM_UpdateAimDownSightLerp(pmove_t *pm, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1489 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1497 | pm */
        "movl (%eax), %ebx\n" /* ps */
        "movl 0xc(%ebx), %edi\n" /* line 785 */
        "testl $0x20000, %edi\n"
        "je .Lf7cee2_0007cf59\n"
        "movl bg_iNumWeapons, %esi\n" /* line 771 */
        "testl %esi, %esi\n"
        "jg .Lf7cee2_0007cf71\n"
        ".Lf7cee2_0007cf05:\n"
        "xorl %eax, %eax\n" /* line 797 */
        ".Lf7cee2_0007cf07:\n"
        "movl bg_weaponDefs(, %eax, 4), %edx\n" /* line 521 */
        "movl 0x195ee24, %eax\n" /* line 1504 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf7cee2_0007cf33\n"
        "movl 0x128(%ebx), %eax\n" /* ps */
        "testl %eax, %eax\n"
        "je .Lf7cee2_0007cf33\n"
        "movl 0x278(%edx), %eax\n" /* line 1506 */
        "testl %eax, %eax\n"
        "jne .Lf7cee2_0007d18f\n"
        ".Lf7cee2_0007cf33:\n"
        "movl 0x32c(%edx), %eax\n" /* line 1518 */
        "testl %eax, %eax\n"
        "jne .Lf7cee2_0007cfab\n"
        "movl $0, 0xdc(%ebx)\n" /* line 1520 | ps */
        "movl $0, 0xe0(%ebx)\n" /* line 1521 | ps */
        /* } scope */
        ".Lf7cee2_0007cf51:\n"
        "addl $0x1c, %esp\n" /* line 1571 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7cee2_0007cf59:\n"
        "testl $0x10, %edi\n" /* line 790 */
        "jne .Lf7cee2_0007cf69\n"
        "movl 0xd4(%ebx), %eax\n" /* line 797 */
        "jmp .Lf7cee2_0007cf07\n"
        ".Lf7cee2_0007cf69:\n"
        "movl 0xd0(%ebx), %eax\n" /* line 792 */
        "jmp .Lf7cee2_0007cf07\n"
        ".Lf7cee2_0007cf71:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7cee2_0007d1bc\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7cee2_0007cf8a:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %esi\n"
        "jl .Lf7cee2_0007cf05\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7cee2_0007cf8a\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7cee2_0007cf07\n"
        ".Lf7cee2_0007cfab:\n"
        "movl 0x35c(%edx), %eax\n" /* line 1528 */
        "testl %eax, %eax\n"
        "jne .Lf7cee2_0007d118\n"
        "cmpl $5, 0xd8(%ebx)\n" /* ps */
        "je .Lf7cee2_0007d133\n"
        ".Lf7cee2_0007cfc6:\n"
        "movl 0x330(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7cee2_0007d149\n"
        ".Lf7cee2_0007cfd4:\n"
        "andl $0x40, %edi\n" /* line 1535 */
        "jne .Lf7cee2_0007d16f\n"
        ".Lf7cee2_0007cfdd:\n"
        "xorl %ecx, %ecx\n"
        ".Lf7cee2_0007cfdf:\n"
        "movl 0x348(%edx), %edi\n" /* line 1540 */
        "testl %edi, %edi\n"
        "je .Lf7cee2_0007cff4\n"
        "movl 0x38(%ebx), %esi\n" /* ps */
        "testl %esi, %esi\n"
        "jne .Lf7cee2_0007d15b\n"
        ".Lf7cee2_0007cff4:\n"
        "movss 0x2ed5d0, %xmm3\n" /* line 1545 | 1.0f */
        "ucomiss 0xdc(%ebx), %xmm3\n" /* ps */
        "jne .Lf7cee2_0007d0d0\n"
        "jp .Lf7cee2_0007d0d0\n"
        "testb %cl, %cl\n"
        "jne .Lf7cee2_0007d0d0\n"
        "movl 0x195ee48, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf7cee2_0007d0d0\n"
        "movl 0xe0(%ebx), %ecx\n" /* line 1547 | ps */
        "testl %ecx, %ecx\n"
        "jne .Lf7cee2_0007d1c9\n"
        "movl 8(%ebp), %ecx\n" /* line 1548 | pm */
        "addl 4(%ecx), %eax\n"
        "movl %eax, 0xe0(%ebx)\n" /* ps */
        ".Lf7cee2_0007d043:\n"
        "movl 8(%ebp), %ecx\n" /* line 1550 | pm */
        "cmpl 4(%ecx), %eax\n"
        "jg .Lf7cee2_0007d0e2\n"
        "movl $0, 0xe0(%ebx)\n" /* line 1553 | ps */
        ".Lf7cee2_0007d059:\n"
        "movss 0xdc(%ebx), %xmm1\n" /* line 1561 | ps */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "je .Lf7cee2_0007d179\n"
        ".Lf7cee2_0007d06e:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1567 | pml */
        "cvtsi2ssl 0x28(%ecx), %xmm0\n"
        "mulss 0x58c(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xdc(%ebx)\n" /* ps */
        "movaps %xmm1, %xmm0\n"
        ".Lf7cee2_0007d08d:\n"
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm3, %xmm1\n"
        "movaps %xmm3, %xmm4\n"
        "cmpnltss %xmm2, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm2, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss %xmm0, 0xdc(%ebx)\n" /* line 1569 | ps */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1571 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7cee2_0007d0d0:\n"
        "movl $0, 0xe0(%ebx)\n" /* line 1557 | ps */
        "testb %cl, %cl\n" /* line 1561 */
        "je .Lf7cee2_0007d059\n"
        ".Lf7cee2_0007d0e2:\n"
        "movss 0xdc(%ebx), %xmm1\n" /* ps */
        "ucomiss %xmm3, %xmm1\n"
        "je .Lf7cee2_0007d184\n"
        ".Lf7cee2_0007d0f3:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1565 | pml */
        "cvtsi2ssl 0x28(%eax), %xmm0\n"
        "mulss 0x588(%edx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xdc(%ebx)\n" /* ps */
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf7cee2_0007d08d\n"
        ".Lf7cee2_0007d118:\n"
        "movl 0xd8(%ebx), %ecx\n" /* line 1528 | ps */
        "leal -5(%ecx), %eax\n"
        "cmpl $3, %eax\n"
        "jbe .Lf7cee2_0007cfdd\n"
        "cmpl $9, %ecx\n"
        "jne .Lf7cee2_0007cfc6\n"
        ".Lf7cee2_0007d133:\n"
        "movl 0x34(%ebx), %eax\n" /* ps */
        "subl 0x524(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf7cee2_0007cfdd\n"
        "jmp .Lf7cee2_0007cfc6\n"
        ".Lf7cee2_0007d149:\n"
        "cmpl $4, 0xd8(%ebx)\n" /* ps */
        "jne .Lf7cee2_0007cfd4\n"
        "jmp .Lf7cee2_0007cfdd\n"
        ".Lf7cee2_0007d15b:\n"
        "cmpl $3, 0xd8(%ebx)\n" /* line 1540 | ps */
        "movl $1, %eax\n"
        "cmovel %eax, %ecx\n"
        "jmp .Lf7cee2_0007cff4\n"
        ".Lf7cee2_0007d16f:\n"
        "movl $1, %ecx\n" /* line 1535 */
        "jmp .Lf7cee2_0007cfdf\n"
        ".Lf7cee2_0007d179:\n"
        "jnp .Lf7cee2_0007cf51\n" /* line 1561 */
        "jmp .Lf7cee2_0007d06e\n"
        ".Lf7cee2_0007d184:\n"
        "jnp .Lf7cee2_0007cf51\n"
        "jmp .Lf7cee2_0007d0f3\n"
        ".Lf7cee2_0007d18f:\n"
        "movl $0x95, 4(%esp)\n" /* line 1484 */
        "movl %ebx, (%esp)\n"
        "calll PM_AddEvent\n"
        "andl $0xffffffbf, 0xc(%ebx)\n" /* line 1485 */
        "movl $0, 0xdc(%ebx)\n" /* line 1509 | ps */
        "movl $0, 0xe0(%ebx)\n" /* line 1510 | ps */
        "jmp .Lf7cee2_0007cf51\n"
        ".Lf7cee2_0007d1bc:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7cee2_0007cf07\n"
        ".Lf7cee2_0007d1c9:\n"
        "movl 0xe0(%ebx), %eax\n"
        "jmp .Lf7cee2_0007d043\n"
    );
}

/* line 3987 */
__attribute__((naked))
void PM_ResetWeaponState(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3987 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ps */
        "andl $0xfffff7ef, 0xc(%ebx)\n" /* line 3305 */
        "movl 0xd8(%ebx), %eax\n" /* line 3307 */
        "subl $0x11, %eax\n"
        "cmpl $5, %eax\n"
        "jbe .Lf7d1d4_0007d22b\n"
        ".Lf7d1d4_0007d1f3:\n"
        "movl $0, 0x34(%ebx)\n" /* line 3310 */
        "movl $0, 0x38(%ebx)\n" /* line 3311 */
        "movl $0, 0xd8(%ebx)\n" /* line 3312 */
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jg .Lf7d1d4_0007d225\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%ebx)\n"
        ".Lf7d1d4_0007d225:\n"
        "addl $0x14, %esp\n" /* line 3990 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf7d1d4_0007d22b:\n"
        "movl $0, 0xdc(%ebx)\n" /* line 3582 */
        "movl $0x95, 4(%esp)\n" /* line 1484 */
        "movl %ebx, (%esp)\n"
        "calll PM_AddEvent\n"
        "andl $0xfffdffbf, 0xc(%ebx)\n" /* line 3575 */
        "movl $0xa9, 4(%esp)\n" /* line 3576 */
        "movl %ebx, (%esp)\n"
        "calll PM_AddEvent\n"
        "jmp .Lf7d1d4_0007d1f3\n"
    );
}

/* line 1699 */
__attribute__((naked))
qboolean PM_InteruptWeaponWithProneMove(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1699 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ps */
        "movl 0xd8(%ebx), %edx\n" /* line 1702 | ps */
        "cmpl $2, %edx\n"
        "jbe .Lf7d25e_0007d2eb\n"
        "cmpl $5, %edx\n"
        "je .Lf7d25e_0007d2eb\n"
        "cmpl $7, %edx\n"
        "je .Lf7d25e_0007d2eb\n"
        "cmpl $9, %edx\n"
        "je .Lf7d25e_0007d2eb\n"
        "cmpl $8, %edx\n"
        "je .Lf7d25e_0007d2eb\n"
        "cmpl $6, %edx\n"
        "je .Lf7d25e_0007d2eb\n"
        "cmpl $4, %edx\n"
        "je .Lf7d25e_0007d2eb\n"
        "cmpl $3, %edx\n" /* line 1706 */
        "je .Lf7d25e_0007d2f6\n"
        "cmpl $0xb, %edx\n"
        "je .Lf7d25e_0007d2f6\n"
        "leal -0xc(%edx), %eax\n"
        "cmpl $4, %eax\n"
        "jbe .Lf7d25e_0007d2f6\n"
        "andl $0xfffff7ef, 0xc(%ebx)\n" /* line 3305 | ps */
        "leal -0x11(%edx), %eax\n" /* line 3307 */
        "cmpl $5, %eax\n"
        "jbe .Lf7d25e_0007d2fe\n"
        ".Lf7d25e_0007d2b2:\n"
        "movl $0, 0x34(%ebx)\n" /* line 3310 | ps */
        "movl $0, 0x38(%ebx)\n" /* line 3311 | ps */
        "movl $0, 0xd8(%ebx)\n" /* line 3312 | ps */
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jg .Lf7d25e_0007d2eb\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%ebx)\n"
        "movl $1, %eax\n"
        "jmp .Lf7d25e_0007d2f0\n"
        ".Lf7d25e_0007d2eb:\n"
        "movl $1, %eax\n"
        ".Lf7d25e_0007d2f0:\n"
        "addl $0x14, %esp\n" /* line 1711 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf7d25e_0007d2f6:\n"
        "xorl %eax, %eax\n" /* line 488 */
        "addl $0x14, %esp\n" /* line 1711 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf7d25e_0007d2fe:\n"
        "movl $0, 0xdc(%ebx)\n" /* line 3582 | ps */
        "movl $0x95, 4(%esp)\n" /* line 1484 */
        "movl %ebx, (%esp)\n"
        "calll PM_AddEvent\n"
        "andl $0xfffdffbf, 0xc(%ebx)\n" /* line 3575 | ps */
        "movl $0xa9, 4(%esp)\n" /* line 3576 */
        "movl %ebx, (%esp)\n" /* ps */
        "calll PM_AddEvent\n"
        "jmp .Lf7d25e_0007d2b2\n"
    );
}

/* line 3827 */
__attribute__((naked))
void PM_Weapon(pmove_t *pm, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3827 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %eax\n" /* pm */
        "movl %eax, -0x54(%ebp)\n" /* pm */
        "movl 0xc(%ebp), %edx\n" /* pml */
        "movl %edx, -0x58(%ebp)\n" /* pml */
        /* { scope 1: breathGaspTime, weapDef, reloadRequested, clipWeap, ... */
        "movl (%eax), %edi\n" /* line 3832 | ps */
        "testb $0x10, 0xd(%edi)\n" /* line 3836 | ps */
        "jne .Lf7d332_0007d361\n"
        "cmpl $5, 4(%edi)\n" /* line 3840 | ps */
        "jg .Lf7d332_0007d369\n"
        "testl $0x300, 0xa0(%edi)\n" /* line 3847 | ps */
        "je .Lf7d332_0007d37b\n"
        /* } scope */
        ".Lf7d332_0007d361:\n"
        "addl $0x6c, %esp\n" /* line 3979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: breathGaspTime, weapDef, reloadRequested, clipWeap, ... */
        ".Lf7d332_0007d369:\n"
        "movl $0, 0xd4(%edi)\n" /* line 3842 | ps */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 3979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: breathGaspTime, weapDef, reloadRequested, clipWeap, ... */
        ".Lf7d332_0007d37b:\n"
        "movl -0x58(%ebp), %ecx\n" /* line 3850 | pml */
        "movl %ecx, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movl %eax, (%esp)\n"
        "calll PM_UpdateAimDownSightLerp\n"
        /* { scope 2: weapCount */
        "movl -0x54(%ebp), %edx\n" /* line 1636 | pm */
        "movl (%edx), %ebx\n"
        "movl 0xc(%ebx), %esi\n" /* line 785 */
        "testl $0x20000, %esi\n"
        "je .Lf7d332_0007db2a\n"
        "movl bg_iNumWeapons, %eax\n" /* line 771 */
        "movl %eax, -0x48(%ebp)\n"
        "testl %eax, %eax\n"
        "jg .Lf7d332_0007db3d\n"
        ".Lf7d332_0007d3b1:\n"
        "xorl %eax, %eax\n" /* line 797 */
        /* { scope 3 */
        ".Lf7d332_0007d3b3:\n"
        "movl bg_weaponDefs(, %eax, 4), %ecx\n" /* line 521 */
        /* } scope */
        "movl 0x195ee44, %eax\n" /* line 1642 */
        "movl (%eax), %eax\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "movss 8(%eax), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %edx\n"
        "movl 0x195ee2c, %eax\n" /* line 1643 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* breathGaspTime */
        "testl %edx, %edx\n" /* line 1645 */
        "jle .Lf7d332_0007e20b\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 1653 | 1.0f */
        "ucomiss 0xdc(%ebx), %xmm2\n"
        "jne .Lf7d332_0007d422\n"
        "jp .Lf7d332_0007d422\n"
        "movl 0x278(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d422\n"
        "cmpl $9, 0x7c(%ecx)\n"
        "je .Lf7d332_0007d422\n"
        "movl -0x54(%ebp), %ecx\n" /* line 1655 | pm */
        "cmpw $0, 8(%ecx)\n"
        "js .Lf7d332_0007e6fa\n"
        ".Lf7d332_0007d422:\n"
        "andl $0xffffbfff, %esi\n" /* line 1588 */
        "movl %esi, 0xc(%ebx)\n"
        ".Lf7d332_0007d42b:\n"
        "testl $0x4000, %esi\n" /* line 1660 */
        "je .Lf7d332_0007e1f4\n"
        "movl 0x5b8(%ebx), %eax\n" /* line 1661 */
        "movl -0x58(%ebp), %ecx\n" /* pml */
        "addl 0x28(%ecx), %eax\n"
        "movl %eax, 0x5b8(%ebx)\n"
        ".Lf7d332_0007d449:\n"
        "movl 0x5b8(%ebx), %ecx\n" /* line 1665 */
        "testl %ecx, %ecx\n"
        "js .Lf7d332_0007e556\n"
        ".Lf7d332_0007d457:\n"
        "testl $0x4000, %esi\n" /* line 1668 */
        "je .Lf7d332_0007e1ec\n"
        "cmpl 0x5b8(%ebx), %edx\n"
        "jge .Lf7d332_0007e22d\n"
        "addl -0x4c(%ebp), %edx\n" /* line 1670 | breathGaspTime */
        "movl %edx, 0x5b8(%ebx)\n"
        /* { scope 3 */
        "andl $0xffffbfff, %esi\n" /* line 1588 */
        "movl %esi, 0xc(%ebx)\n"
        /* } scope */
        ".Lf7d332_0007d481:\n"
        "movl 0x195ee40, %eax\n" /* line 1685 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "cvtsi2ssl 0x5b8(%ebx), %xmm1\n" /* ps */
        "cvtsi2ssl %edx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 0x195ee4c, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        ".Lf7d332_0007d4b7:\n"
        "movl -0x58(%ebp), %edx\n" /* line 1690 | pml */
        "movl 0x24(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl 0x5b4(%ebx), %eax\n" /* ps */
        "movl %eax, 4(%esp)\n"
        "mulss 0xdc(%ebx), %xmm1\n" /* ps */
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll DiffTrack\n"
        "fstps 0x5b4(%ebx)\n" /* ps */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007d4eb:\n"
        "testb $0x10, 0xc(%edi)\n" /* line 3538 | iWeapon */
        "je .Lf7d332_0007d508\n"
        "movl 0xd0(%edi), %ecx\n" /* line 3541 | iWeapon */
        "movl bg_weaponDefs(, %ecx, 4), %edx\n" /* line 521 */
        "cmpl $1, 0x78(%edx)\n" /* line 3546 */
        "je .Lf7d332_0007e5e5\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007d508:\n"
        "movl -0x54(%ebp), %eax\n" /* line 2754 | pm */
        "movl (%eax), %ecx\n"
        "movl 0xd4(%ecx), %ebx\n" /* line 521 */
        "movl bg_weaponDefs(, %ebx, 4), %esi\n"
        "movl 0x40(%ecx), %eax\n" /* line 2759 */
        "testl %eax, %eax\n"
        "jle .Lf7d332_0007d532\n"
        /* { scope 3 */
        "movl -0x58(%ebp), %edx\n" /* line 154 | pml */
        "subl 0x28(%edx), %eax\n"
        "movl $0, %edx\n"
        "cmovsl %edx, %eax\n"
        /* } scope */
        "movl %eax, 0x40(%ecx)\n" /* line 2762 */
        ".Lf7d332_0007d532:\n"
        "movl 0x34(%ecx), %eax\n" /* line 2765 */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d54a\n"
        "movl -0x58(%ebp), %edx\n" /* line 2767 | pml */
        "subl 0x28(%edx), %eax\n"
        "movl %eax, 0x34(%ecx)\n"
        "testl %eax, %eax\n" /* line 2769 */
        "jle .Lf7d332_0007e6a1\n"
        ".Lf7d332_0007d54a:\n"
        "movl 0x38(%ecx), %eax\n" /* line 2803 */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d562\n"
        "movl -0x58(%ebp), %edx\n" /* line 2805 | pml */
        "subl 0x28(%edx), %eax\n"
        "movl %eax, 0x38(%ecx)\n"
        "testl %eax, %eax\n" /* line 2806 */
        "jle .Lf7d332_0007e6da\n"
        ".Lf7d332_0007d562:\n"
        "movl $0, -0x50(%ebp)\n" /* line 2808 | delayedAction */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007d569:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 3708 | pm */
        "movl (%ecx), %esi\n" /* weapDef */
        "movl 0xd8(%esi), %edx\n" /* line 3718 | weapDef */
        "leal -0x11(%edx), %ecx\n"
        "cmpl $5, %ecx\n"
        "jbe .Lf7d332_0007d5b8\n"
        "movss 0xdc(%esi), %xmm0\n" /* line 3723 | weapDef */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf7d332_0007d5a8\n"
        "movl 0xd4(%esi), %eax\n" /* line 3727 | weapDef */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x278(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d6f9\n"
        ".Lf7d332_0007d5a8:\n"
        "movl -0x54(%ebp), %eax\n" /* line 3731 | pm */
        "testl $0x30015, 8(%eax)\n"
        "jne .Lf7d332_0007d6f9\n"
        ".Lf7d332_0007d5b8:\n"
        "cmpl $5, %edx\n" /* line 3735 */
        "je .Lf7d332_0007d6f9\n"
        "cmpl $7, %edx\n"
        "je .Lf7d332_0007d6f9\n"
        "cmpl $9, %edx\n"
        "je .Lf7d332_0007d6f9\n"
        "cmpl $8, %edx\n"
        "je .Lf7d332_0007d6f9\n"
        "cmpl $6, %edx\n"
        "je .Lf7d332_0007d6f9\n"
        "leal -3(%edx), %eax\n" /* line 3738 */
        "cmpl $1, %eax\n"
        "jbe .Lf7d332_0007d6f9\n"
        "cmpl $0xa, %edx\n"
        "je .Lf7d332_0007d6f9\n"
        "cmpl $0xb, %edx\n"
        "je .Lf7d332_0007d6f9\n"
        "leal -0xa(%edx), %eax\n" /* line 3741 */
        "cmpl $1, %eax\n"
        "jbe .Lf7d332_0007d6f9\n"
        "leal -1(%edx), %eax\n" /* line 3744 */
        "cmpl $1, %eax\n"
        "jbe .Lf7d332_0007d6f9\n"
        "leal -0xc(%edx), %eax\n" /* line 3747 */
        "cmpl $4, %eax\n"
        "jbe .Lf7d332_0007d6f9\n"
        "movl -0x54(%ebp), %eax\n" /* line 3750 | pm */
        "movzbl 0x28(%eax), %eax\n"
        "movb %al, -0x42(%ebp)\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movzbl 0xc(%eax), %ebx\n" /* ps */
        "movzbl 0x29(%eax), %eax\n" /* line 3751 */
        "movb %al, -0x41(%ebp)\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movzbl 0xd(%eax), %eax\n"
        "movb %al, -0x5d(%ebp)\n"
        "cmpl $0, 0x128(%esi)\n" /* line 3754 | weapDef */
        "jne .Lf7d332_0007d65b\n"
        "cmpb %bl, -0x42(%ebp)\n" /* ps */
        "je .Lf7d332_0007e1b6\n"
        ".Lf7d332_0007d65b:\n"
        "movl $1, %eax\n"
        ".Lf7d332_0007d660:\n"
        "cmpl $5, %ecx\n" /* line 3756 */
        "ja .Lf7d332_0007ebc2\n"
        "testb %al, %al\n"
        "je .Lf7d332_0007ebc2\n"
        "andl $0xfffff7ef, 0xc(%esi)\n" /* line 3305 | weapDef */
        "leal -0x11(%edx), %eax\n" /* line 3307 */
        "cmpl $5, %eax\n"
        "ja .Lf7d332_0007d6b1\n"
        "movl $0, 0xdc(%esi)\n" /* line 3582 | weapDef */
        "movl $0x95, 4(%esp)\n" /* line 1484 */
        "movl %esi, (%esp)\n"
        "calll PM_AddEvent\n"
        "andl $0xfffdffbf, 0xc(%esi)\n" /* line 3575 | weapDef */
        "movl $0xa9, 4(%esp)\n" /* line 3576 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        ".Lf7d332_0007d6b1:\n"
        "movl $0, 0x34(%esi)\n" /* line 3310 | weapDef */
        "movl $0, 0x38(%esi)\n" /* line 3311 | weapDef */
        "movl $0, 0xd8(%esi)\n" /* line 3312 | weapDef */
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007d6e3\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%esi)\n"
        ".Lf7d332_0007d6e3:\n"
        "movl -0x54(%ebp), %edx\n" /* line 3761 | pm */
        "testb $1, 8(%edx)\n"
        "je .Lf7d332_0007f159\n"
        "movl $1, 0x34(%esi)\n" /* line 3762 | weapDef */
        "movl (%edx), %esi\n" /* weapDef */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007d6f9:\n"
        "testl $0x300, 0xa0(%esi)\n" /* line 3476 | weapDef */
        "jne .Lf7d332_0007d7f7\n"
        "testb $4, 0xf(%esi)\n" /* line 3480 | weapDef */
        "jne .Lf7d332_0007d7f7\n"
        "movl 0xd8(%esi), %edx\n" /* line 3487 | weapDef */
        "leal -0x11(%edx), %eax\n"
        "cmpl $5, %eax\n"
        "jbe .Lf7d332_0007d7fd\n"
        "leal -0xc(%edx), %eax\n" /* line 3490 */
        "cmpl $3, %eax\n"
        "jbe .Lf7d332_0007d7f7\n"
        "movl -0x54(%ebp), %ecx\n" /* line 3495 | pm */
        "movzbl 0xd(%ecx), %edx\n"
        "movl %edx, %eax\n"
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%esi, %eax, 4), %eax\n" /* weapDef */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7d332_0007d755\n"
        "movl %edx, 0xd0(%esi)\n" /* line 3496 | weapDef */
        ".Lf7d332_0007d755:\n"
        "movl -0x54(%ebp), %edx\n" /* line 3498 | pm */
        "movl 8(%edx), %eax\n"
        "testl $0x10000, %eax\n"
        "je .Lf7d332_0007e89b\n"
        "movl $1, -0x20(%ebp)\n"
        /* { scope 3 */
        ".Lf7d332_0007d76d:\n"
        "movl bg_iNumWeapons, %ecx\n" /* line 560 */
        "movl %ecx, -0x3c(%ebp)\n" /* weapCount */
        "testl %ecx, %ecx\n" /* line 818 */
        "jle .Lf7d332_0007d7e2\n"
        "movl $1, %ebx\n"
        "movl $bg_weaponDefs, -0x1c(%ebp)\n"
        "jmp .Lf7d332_0007d794\n"
        ".Lf7d332_0007d788:\n"
        "addl $1, %ebx\n"
        "addl $4, -0x1c(%ebp)\n"
        "cmpl %ebx, -0x3c(%ebp)\n" /* weapCount */
        "jl .Lf7d332_0007d7e2\n"
        ".Lf7d332_0007d794:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 521 */
        "movl 4(%eax), %edx\n"
        "movl -0x20(%ebp), %ecx\n" /* line 822 */
        "cmpl %ecx, 0x84(%edx)\n"
        "jne .Lf7d332_0007d788\n"
        "movl %ebx, %eax\n" /* line 825 */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7d332_0007d788\n"
        "movl 0x1c8(%edx), %eax\n" /* line 828 */
        "movl 0x1d0(%edx), %edx\n"
        "movl 0x144(%esi, %eax, 4), %eax\n"
        "addl 0x344(%esi, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d788\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 3507 | offHandIndex */
        "jne .Lf7d332_0007f223\n"
        ".Lf7d332_0007d7e2:\n"
        "movl $0x94, 4(%esp)\n" /* line 3445 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        ".Lf7d332_0007d7f2:\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movl (%eax), %esi\n" /* weapDef */
        ".Lf7d332_0007d7f7:\n"
        "movl 0xd8(%esi), %edx\n" /* weapDef */
        /* } scope */
        ".Lf7d332_0007d7fd:\n"
        "leal -0x11(%edx), %eax\n" /* line 2831 */
        "cmpl $5, %eax\n"
        "jbe .Lf7d332_0007d86e\n"
        "leal -0xc(%edx), %eax\n" /* line 2834 */
        "cmpl $4, %eax\n"
        "jbe .Lf7d332_0007d86e\n"
        "movl 0x34(%esi), %eax\n" /* line 2837 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d84b\n"
        "cmpl $5, %edx\n"
        "je .Lf7d332_0007d84b\n"
        "cmpl $7, %edx\n"
        "je .Lf7d332_0007d84b\n"
        "cmpl $9, %edx\n"
        "je .Lf7d332_0007d84b\n"
        "cmpl $8, %edx\n"
        "je .Lf7d332_0007d84b\n"
        "cmpl $6, %edx\n"
        "je .Lf7d332_0007d84b\n"
        "cmpl $4, %edx\n"
        "je .Lf7d332_0007d84b\n"
        "leal -3(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf7d332_0007d86e\n"
        "cmpl $0xa, %edx\n"
        "je .Lf7d332_0007d86e\n"
        "cmpl $0xb, %edx\n"
        "je .Lf7d332_0007d86e\n"
        "movl 0x38(%esi), %eax\n" /* weapDef */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d86e\n"
        ".Lf7d332_0007d84b:\n"
        "movl %esi, (%esp)\n" /* line 2839 | weapDef */
        "calll Mantle_IsWeaponInactive\n"
        "testb %al, %al\n"
        "je .Lf7d332_0007e649\n"
        "movl 0xd4(%esi), %eax\n" /* line 2841 | weapDef */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007dbd6\n"
        ".Lf7d332_0007d869:\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movl (%edx), %esi\n" /* weapDef */
        /* { scope 2: weapCount */
        ".Lf7d332_0007d86e:\n"
        "movl 0xd4(%esi), %edx\n" /* line 521 */
        "movl bg_weaponDefs(, %edx, 4), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* weapDef */
        "movl 0xd8(%esi), %ebx\n" /* line 2548 | ps, weapDef */
        "leal -0x11(%ebx), %eax\n" /* weapDef */
        "cmpl $5, %eax\n"
        "jbe .Lf7d332_0007e1d6\n"
        "leal -0xc(%ebx), %eax\n" /* line 2551 | weapDef */
        "cmpl $4, %eax\n"
        "jbe .Lf7d332_0007d931\n"
        "movl -0x54(%ebp), %ecx\n" /* pm */
        "movl 8(%ecx), %ecx\n"
        "shrl $4, %ecx\n"
        "andl $1, %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* reloadRequested */
        "movl 0xc(%esi), %eax\n" /* line 2559 | ps */
        "testb $8, %al\n"
        "je .Lf7d332_0007d8bf\n"
        "andl $0xfffffff7, %eax\n" /* line 2561 */
        "movl %eax, 0xc(%esi)\n" /* ps */
        "movl $1, -0x5c(%ebp)\n" /* reloadRequested */
        ".Lf7d332_0007d8bf:\n"
        "movl -0x34(%ebp), %eax\n" /* line 2566 | weapDef */
        "movl 0x35c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d8de\n"
        "cmpl $7, %ebx\n" /* weapDef */
        "je .Lf7d332_0007e716\n"
        "cmpl $5, %ebx\n" /* weapDef */
        "je .Lf7d332_0007e716\n"
        ".Lf7d332_0007d8de:\n"
        "cmpl $0xb, %ebx\n" /* line 2578 | weapDef */
        "ja .Lf7d332_0007e565\n"
        ".Lf7d332_0007d8e7:\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* weapDef */
        "shll %cl, %eax\n"
        "testl $0xc06, %eax\n"
        "jne .Lf7d332_0007e639\n"
        "testl $0x3e0, %eax\n"
        "je .Lf7d332_0007e565\n"
        "movl -0x54(%ebp), %eax\n" /* line 2586 | pm */
        "movl 0xe0(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf7d332_0007eafb\n"
        "movl bg_weaponDefs(, %edx, 4), %eax\n" /* line 2588 */
        "movl 0x340(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7d332_0007ee13\n"
        "movl -0x54(%ebp), %ecx\n" /* pm */
        "movl (%ecx), %esi\n" /* ps */
        ".Lf7d332_0007d931:\n"
        "movl 0xd8(%esi), %ecx\n" /* ps */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007d937:\n"
        "movl 0xd4(%esi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %ebx\n"
        "leal -0x11(%ecx), %eax\n" /* line 3223 */
        "cmpl $5, %eax\n"
        "jbe .Lf7d332_0007d99d\n"
        "leal -0xc(%ecx), %eax\n" /* line 3226 */
        "cmpl $4, %eax\n"
        "jbe .Lf7d332_0007d99d\n"
        "movl 0x1f4(%ebx), %eax\n" /* line 3244 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d99d\n"
        "movl -0x50(%ebp), %eax\n" /* line 3247 | delayedAction */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d99d\n"
        "movl 0x38(%esi), %eax\n" /* line 3250 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007e782\n"
        "cmpl $5, %ecx\n"
        "je .Lf7d332_0007e782\n"
        "cmpl $7, %ecx\n"
        "je .Lf7d332_0007e782\n"
        "cmpl $9, %ecx\n"
        "je .Lf7d332_0007e782\n"
        "cmpl $8, %ecx\n"
        "je .Lf7d332_0007e782\n"
        "cmpl $6, %ecx\n"
        "je .Lf7d332_0007e782\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007d99d:\n"
        "movl 0xd4(%edi), %edx\n" /* line 1893 | iWeapon */
        /* { scope 3 */
        "movl bg_weaponDefs(, %edx, 4), %esi\n" /* line 521 */
        /* } scope */
        "movl 0xd8(%edi), %ecx\n" /* line 1895 */
        "movl %ecx, -0x5c(%ebp)\n" /* reloadRequested */
        "movl %ecx, %eax\n"
        "subl $0x11, %eax\n"
        "cmpl $5, %eax\n"
        "jbe .Lf7d332_0007dac8\n"
        "addl $5, %eax\n" /* line 1898 */
        "cmpl $4, %eax\n"
        "jbe .Lf7d332_0007dac8\n"
        "movl 0x328(%esi), %eax\n" /* line 1901 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007dac8\n"
        "leal 0x55c(%edi), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %edx, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "leal (, %eax, 4), %ebx\n"
        "andl $0x1f, %edx\n"
        "movl 0x55c(%edi, %ebx), %eax\n" /* line 1901 */
        "movl %edx, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7d332_0007dac8\n"
        "cmpl $4, -0x5c(%ebp)\n" /* line 1903 | reloadRequested */
        "je .Lf7d332_0007eaba\n"
        ".Lf7d332_0007da10:\n"
        "movl 0x34(%edi), %eax\n" /* line 1916 */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007da45\n"
        "movl -0x5c(%ebp), %eax\n" /* reloadRequested */
        "subl $3, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf7d332_0007dac8\n"
        "cmpl $0xa, -0x5c(%ebp)\n" /* reloadRequested */
        "je .Lf7d332_0007dac8\n"
        "cmpl $0xb, -0x5c(%ebp)\n" /* reloadRequested */
        "je .Lf7d332_0007dac8\n"
        "movl 0x38(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007dac8\n"
        ".Lf7d332_0007da45:\n"
        "cmpl $4, -0x5c(%ebp)\n" /* line 1918 | reloadRequested */
        "je .Lf7d332_0007eb92\n"
        "movl -0x5c(%ebp), %eax\n" /* line 1922 | reloadRequested */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007dac8\n"
        "movss 0xdc(%edi), %xmm0\n" /* line 1924 */
        "ucomiss 0x2ed67c, %xmm0\n" /* 0.75f */
        "jbe .Lf7d332_0007ed7d\n"
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007da88\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $7, %eax\n"
        "movl %eax, 0x5d0(%edi)\n"
        ".Lf7d332_0007da88:\n"
        "movl $4, 0xd8(%edi)\n" /* line 1929 */
        "movl 0x208(%esi), %eax\n" /* line 1930 | weapDef */
        "movl %eax, 0x34(%edi)\n"
        "movl 0x20c(%esi), %eax\n" /* line 1932 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007ecbd\n"
        "cmpl 0x208(%esi), %eax\n" /* weapDef */
        "jge .Lf7d332_0007ecbd\n"
        "movl %eax, 0x38(%edi)\n" /* line 1933 */
        ".Lf7d332_0007dab8:\n"
        "movl $0xa1, 4(%esp)\n" /* line 1937 */
        "movl %edi, (%esp)\n"
        "calll PM_AddEvent\n"
        /* } scope */
        ".Lf7d332_0007dac8:\n"
        "movl 0xc(%edi), %ebx\n" /* line 3872 | ps */
        "testb $1, %bl\n" /* ps */
        "je .Lf7d332_0007dade\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "cmpw $0, 0x1c(%eax)\n"
        "jne .Lf7d332_0007e1dd\n"
        ".Lf7d332_0007dade:\n"
        "movl 0xd8(%edi), %eax\n" /* ps */
        "subl $0xa, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf7d332_0007e1dd\n"
        ".Lf7d332_0007daf0:\n"
        "movl -0x50(%ebp), %esi\n" /* line 3885 | delayedAction, weapDef */
        "testl %esi, %esi\n" /* weapDef */
        "jne .Lf7d332_0007db0d\n"
        "movl 0x34(%edi), %ecx\n" /* ps */
        "testl %ecx, %ecx\n"
        "jne .Lf7d332_0007d361\n"
        "movl 0x38(%edi), %edx\n" /* ps */
        "testl %edx, %edx\n"
        "jne .Lf7d332_0007d361\n"
        ".Lf7d332_0007db0d:\n"
        "cmpl $0x16, 0xd8(%edi)\n" /* line 3888 | ps */
        "ja .Lf7d332_0007dbe9\n"
        "movl 0xd8(%edi), %edx\n" /* ps */
        "movl %edx, -0x5c(%ebp)\n" /* reloadRequested */
        "jmpl *0x2f0a10(, %edx, 4)\n"
        /* { scope 2: weapCount */
        ".Lf7d332_0007db2a:\n"
        "testl $0x10, %esi\n" /* line 790 */
        "jne .Lf7d332_0007db78\n"
        "movl 0xd4(%ebx), %eax\n" /* line 797 */
        "jmp .Lf7d332_0007d3b3\n"
        ".Lf7d332_0007db3d:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7d332_0007e6ed\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7d332_0007db56:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, -0x48(%ebp)\n"
        "jl .Lf7d332_0007d3b1\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7d332_0007db56\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7d332_0007d3b3\n"
        ".Lf7d332_0007db78:\n"
        "movl 0xd0(%ebx), %eax\n" /* line 792 */
        "jmp .Lf7d332_0007d3b3\n"
        /* } scope */
        "andl $0xfffff7ef, %ebx\n" /* line 3305 | weapDef */
        "movl %ebx, 0xc(%edi)\n" /* weapDef, iWeapon */
        "movl -0x5c(%ebp), %eax\n" /* line 3307 | reloadRequested */
        "subl $0x11, %eax\n"
        "cmpl $5, %eax\n"
        "jbe .Lf7d332_0007eb55\n"
        ".Lf7d332_0007db9b:\n"
        "movl $0, 0x34(%edi)\n" /* line 3310 | iWeapon */
        "movl $0, 0x38(%edi)\n" /* line 3311 | iWeapon */
        ".Lf7d332_0007dba9:\n"
        "movl $0, 0xd8(%edi)\n" /* line 3312 | iWeapon */
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007d361\n"
        ".Lf7d332_0007dbbd:\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%edi)\n"
        "jmp .Lf7d332_0007d361\n"
        ".Lf7d332_0007dbd6:\n"
        "xorl %edx, %edx\n" /* line 2842 */
        "movl %esi, %eax\n" /* weapDef */
        "calll PM_BeginWeaponChange\n"
        "movl -0x54(%ebp), %ecx\n" /* pm */
        "movl (%ecx), %esi\n" /* weapDef */
        "jmp .Lf7d332_0007d86e\n"
        ".Lf7d332_0007dbe9:\n"
        "movl 0xd4(%edi), %eax\n" /* line 3965 | ps */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d361\n"
        "movl -0x54(%ebp), %edx\n" /* line 2888 | pm */
        "testb $1, 8(%edx)\n"
        "jne .Lf7d332_0007e244\n"
        "movl -0x50(%ebp), %ecx\n" /* delayedAction */
        "testl %ecx, %ecx\n"
        "jne .Lf7d332_0007e244\n"
        "movl (%edx), %eax\n" /* line 2890 */
        "cmpl $3, 0xd8(%eax)\n" /* line 2894 */
        "je .Lf7d332_0007ea8a\n"
        ".Lf7d332_0007dc1e:\n"
        "movl $0, 0xd8(%eax)\n" /* line 2899 */
        "jmp .Lf7d332_0007d361\n"
        /* { scope 2: weapCount */
        "movl -0x54(%ebp), %eax\n" /* line 3383 | pm */
        "movl (%eax), %ebx\n" /* weapDef */
        "testl $0x30000, 0x24(%eax)\n" /* line 3388 */
        "je .Lf7d332_0007dc48\n"
        "testl $0x30000, 8(%eax)\n"
        "jne .Lf7d332_0007dfae\n"
        ".Lf7d332_0007dc48:\n"
        "movl 0xd0(%ebx), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl $0xf, 0xd8(%ebx)\n" /* line 3396 | weapDef */
        "movl 0x204(%eax), %eax\n" /* line 3397 */
        "movl %eax, 0x34(%ebx)\n" /* weapDef */
        "movl $0, 0x38(%ebx)\n" /* line 3398 | weapDef */
        "orl $0x10, 0xc(%ebx)\n" /* line 3399 | weapDef */
        "movl %ebx, 8(%esp)\n" /* line 3401 | weapDef */
        "movl 0xd0(%ebx), %eax\n" /* weapDef */
        "movl %eax, 4(%esp)\n"
        "movl $0xa6, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jg .Lf7d332_0007dcaa\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $2, %eax\n"
        "movl %eax, 0x5d0(%ebx)\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf7d332_0007dcaa:\n"
        "movl 0xd0(%ebx), %eax\n" /* line 1725 | ps */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x1d0(%eax), %eax\n"
        "subl $1, 0x344(%ebx, %eax, 4)\n" /* line 1834 | ps */
        /* } scope */
        /* } scope */
        "movl $1, 0xc(%esp)\n" /* line 3407 */
        "movl $0, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "movl 0xd0(%ebx), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x1c8(%eax), %edx\n" /* line 3410 */
        "movl 0x1d0(%eax), %ecx\n"
        "movl 0x144(%ebx, %edx, 4), %eax\n" /* ps */
        "addl 0x344(%ebx, %ecx, 4), %eax\n" /* ps */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d361\n"
        "movl $0x94, 0xc(%ebp)\n" /* line 3411 | pml */
        "movl %ebx, 8(%ebp)\n" /* ps, pm */
        /* } scope */
        /* } scope */
        ".Lf7d332_0007dd1e:\n"
        "addl $0x6c, %esp\n" /* line 3979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: breathGaspTime, weapDef, reloadRequested, clipWeap, ... */
        /* { scope 2: weapCount */
        "jmp PM_AddEvent\n" /* line 2645 */
        /* } scope */
        "movl 0xd4(%edi), %eax\n" /* line 3421 | iWeapon */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007ecc9\n"
        "movl $0, 0x34(%edi)\n" /* line 3423 | iWeapon */
        "movl $1, 0x38(%edi)\n" /* line 3424 | iWeapon */
        ".Lf7d332_0007dd46:\n"
        "movl $0x10, 0xd8(%edi)\n" /* line 3436 | iWeapon */
        "andl $0xfffff7ef, %ebx\n" /* line 3437 | ps */
        "movl %ebx, 0xc(%edi)\n" /* ps, iWeapon */
        "jmp .Lf7d332_0007d361\n"
        /* { scope 2: weapCount */
        "movl 0xd4(%edi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl $0x12, 0xd8(%edi)\n" /* line 3608 | iWeapon */
        "movl 0x240(%eax), %eax\n" /* line 3609 */
        "movl %eax, 0x34(%edi)\n" /* iWeapon */
        "movl $0, 0x38(%edi)\n" /* line 3610 | iWeapon */
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007d361\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x11, %eax\n"
        "movl %eax, 0x5d0(%edi)\n"
        "jmp .Lf7d332_0007d361\n"
        /* } scope */
        /* { scope 2: weapCount */
        "movl 0xd4(%edi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x214(%eax), %edx\n" /* line 3160 */
        "subl 0x200(%eax), %edx\n"
        "cmpl %edx, 0x34(%edi)\n" /* iWeapon */
        "jge .Lf7d332_0007ddcc\n"
        "movl %edx, 0x34(%edi)\n" /* line 3161 | iWeapon */
        ".Lf7d332_0007ddcc:\n"
        "movl $0xa4, 4(%esp)\n" /* line 3163 */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll PM_AddEvent\n"
        "movl $0xb, 0xd8(%edi)\n" /* line 3165 | iWeapon */
        ".Lf7d332_0007dde6:\n"
        "movl %edi, 8(%ebp)\n" /* line 3166 | iWeapon, pm */
        /* } scope */
        /* } scope */
        ".Lf7d332_0007dde9:\n"
        "addl $0x6c, %esp\n" /* line 3979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: breathGaspTime, weapDef, reloadRequested, clipWeap, ... */
        /* { scope 2: weapCount */
        "jmp PM_SetProneMovementOverride\n" /* line 2248 */
        /* } scope */
        "movl 0x5d0(%edi), %eax\n" /* line 499 */
        "testl $0xfffffdff, %eax\n"
        "je .Lf7d332_0007de16\n"
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007de16\n"
        "andl $0x200, %eax\n" /* line 488 */
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%edi)\n"
        ".Lf7d332_0007de16:\n"
        "movl $0, 0xd8(%edi)\n" /* line 3202 | iWeapon */
        "jmp .Lf7d332_0007d361\n"
        /* { scope 2: weapCount */
        "movl 0xd0(%edi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl $0xd, 0xd8(%edi)\n" /* line 3347 | iWeapon */
        "movl 0x210(%eax), %eax\n" /* line 3348 */
        "movl %eax, 0x34(%edi)\n" /* iWeapon */
        "movl $0, 0x38(%edi)\n" /* line 3349 | iWeapon */
        "orl $0x10, %ebx\n" /* line 3350 | weapDef */
        "movl %ebx, 0xc(%edi)\n" /* weapDef, iWeapon */
        "movl %edi, 8(%esp)\n" /* line 3352 | iWeapon */
        "movl 0xd0(%edi), %eax\n" /* iWeapon */
        "movl %eax, 4(%esp)\n"
        "movl $0xa5, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007dde6\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x13, %eax\n"
        "movl %eax, 0x5d0(%edi)\n"
        "jmp .Lf7d332_0007dde6\n"
        /* } scope */
        /* { scope 2: weapCount */
        "movl 0xd0(%edi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl $0xe, 0xd8(%edi)\n" /* line 3368 | iWeapon */
        "movl $0, 0x34(%edi)\n" /* line 3369 | iWeapon */
        "movl $0, 0x38(%edi)\n" /* line 3370 | iWeapon */
        "orl $0x10, %ebx\n" /* line 3371 | weapDef */
        "movl %ebx, 0xc(%edi)\n" /* weapDef, iWeapon */
        "movl 0x248(%eax), %eax\n" /* line 3372 */
        "movl %eax, 0x3c(%edi)\n" /* iWeapon */
        "jmp .Lf7d332_0007d361\n"
        /* } scope */
        /* { scope 2: weapCount */
        "movl bg_iNumWeapons, %esi\n" /* line 771 */
        "testl %esi, %esi\n"
        "jle .Lf7d332_0007eb8b\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7d332_0007eff3\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7d332_0007def2:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %esi\n"
        "jl .Lf7d332_0007eb8b\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7d332_0007def2\n"
        "movl %ecx, %eax\n"
        ".Lf7d332_0007df0b:\n"
        "movzbl %al, %eax\n" /* line 774 */
        /* { scope 3 */
        ".Lf7d332_0007df0e:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        /* } scope */
        "movl $0x13, 0xd8(%edi)\n" /* line 3626 | iWeapon */
        "movl 0x2c0(%eax), %eax\n" /* line 3627 */
        "movl %eax, 0x34(%edi)\n" /* iWeapon */
        "movl $0, 0x38(%edi)\n" /* line 3628 | iWeapon */
        "orl $0x20000, %ebx\n" /* line 3568 | offHandIndex */
        "movl %ebx, 0xc(%edi)\n" /* offHandIndex, iWeapon */
        "movl $0xa8, 4(%esp)\n" /* line 3569 */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll PM_AddEvent\n"
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jle .Lf7d332_0007dbbd\n"
        "jmp .Lf7d332_0007d361\n"
        /* } scope */
        "movl $0x14, 0xd8(%edi)\n" /* line 3637 | iWeapon */
        "movl $0, 0x34(%edi)\n" /* line 3638 | iWeapon */
        "movl $0, 0x38(%edi)\n" /* line 3639 | iWeapon */
        "jmp .Lf7d332_0007d361\n"
        "movl -0x54(%ebp), %edx\n" /* line 3668 | pm */
        "movl (%edx), %ebx\n" /* weapDef */
        "movl $0x16, 0xd8(%ebx)\n" /* line 3671 | weapDef */
        "andl $0xfffdffff, 0xc(%ebx)\n" /* line 3575 | offHandIndex */
        "movl $0xa9, 4(%esp)\n" /* line 3576 */
        "movl %ebx, (%esp)\n" /* offHandIndex */
        "calll PM_AddEvent\n"
        "movl -0x54(%ebp), %ecx\n" /* line 3675 | pm */
        "cmpb $0, 0xc(%ecx)\n"
        "jne .Lf7d332_0007ed06\n"
        "movl $0, 0x34(%ebx)\n" /* line 3677 | weapDef */
        ".Lf7d332_0007dfae:\n"
        "movl $1, 0x38(%ebx)\n" /* line 3678 | weapDef */
        "jmp .Lf7d332_0007d361\n"
        /* { scope 2: weapCount */
        "movl -0x54(%ebp), %eax\n" /* line 2198 | pm */
        "movl (%eax), %esi\n" /* weapDef */
        "movl %esi, (%esp)\n" /* line 2205 | weapDef */
        "calll Mantle_IsWeaponInactive\n"
        "testb %al, %al\n"
        "jne .Lf7d332_0007dff7\n"
        "movl 0xc(%esi), %ebx\n" /* line 2207 | weapDef, weaponDef */
        "testb $0x20, %bl\n" /* weaponDef */
        "jne .Lf7d332_0007dff7\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movzbl 0xc(%edx), %edi\n"
        "movl %edi, %eax\n" /* line 807 */
        "sarl $5, %eax\n"
        "movl %edi, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%esi, %eax, 4), %edx\n" /* line 2207 | weapDef */
        "movl %edx, %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf7d332_0007f0f7\n"
        ".Lf7d332_0007dff7:\n"
        "xorl %edi, %edi\n" /* line 2219 */
        "xorl %ecx, %ecx\n"
        "movl 0x544(%esi), %edx\n" /* weapDef */
        ".Lf7d332_0007e001:\n"
        "sarl %cl, %edx\n" /* line 2223 */
        "andb $1, %dl\n"
        "jne .Lf7d332_0007ed49\n"
        "xorl %edi, %edi\n"
        "xorl %eax, %eax\n"
        ".Lf7d332_0007e010:\n"
        "movl 0xd4(%esi), %ecx\n" /* line 2226 | weapDef */
        "movl %ecx, -0x24(%ebp)\n"
        "movzbl %al, %eax\n" /* line 2228 */
        "movl %eax, 0xd4(%esi)\n" /* weapDef */
        "cmpl %ecx, %edi\n" /* line 2233 */
        "je .Lf7d332_0007eda3\n"
        "movl -0x24(%ebp), %ebx\n" /* line 2241 | weaponDef */
        "testl %ebx, %ebx\n" /* weaponDef */
        "jne .Lf7d332_0007eede\n"
        "movl $1, 0xd8(%esi)\n" /* line 2243 | weapDef */
        "movl bg_weaponDefs(, %edi, 4), %eax\n" /* line 2244 */
        "movl 0x234(%eax), %eax\n"
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        "movl $0x437f0000, 0x5d4(%esi)\n" /* line 2245 | weapDef */
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007e076\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0xa, %eax\n"
        "movl %eax, 0x5d0(%esi)\n"
        ".Lf7d332_0007e076:\n"
        "movl %esi, 8(%ebp)\n" /* line 2248 | weapDef, pm */
        "jmp .Lf7d332_0007dde9\n"
        /* } scope */
        /* { scope 2: weapCount */
        "movl 0xd4(%edi), %esi\n" /* line 521 */
        "movl bg_weaponDefs(, %esi, 4), %ebx\n"
        "movl -0x50(%ebp), %eax\n" /* line 2478 | delayedAction */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007eddc\n"
        "movl 0x34(%edi), %eax\n" /* line 2486 | iWeapon */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d361\n"
        ".Lf7d332_0007e0a1:\n"
        "movl %esi, %edx\n" /* line 817 */
        "sarl $5, %edx\n"
        "andl $0x1f, %esi\n"
        "movl $0xfffffffe, %eax\n"
        "movl %esi, %ecx\n"
        "roll %cl, %eax\n"
        "andl %eax, 0x55c(%edi, %edx, 4)\n"
        "movl 0x35c(%ebx), %esi\n" /* line 2490 | weapDef, ps */
        "testl %esi, %esi\n" /* ps */
        "je .Lf7d332_0007dba9\n"
        "cmpl $6, 0xd8(%edi)\n" /* line 2492 | iWeapon */
        "je .Lf7d332_0007e0df\n"
        "movl %edi, %eax\n" /* iWeapon */
        "calll PM_Weapon_AllowReload\n"
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007efe5\n"
        ".Lf7d332_0007e0df:\n"
        "movl 0x22c(%ebx), %ecx\n" /* line 2497 | weapDef */
        "testl %ecx, %ecx\n"
        "je .Lf7d332_0007dba9\n"
        ".Lf7d332_0007e0ed:\n"
        "movl $9, 0xd8(%edi)\n" /* line 2499 | iWeapon */
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007e114\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0xe, %eax\n"
        "movl %eax, 0x5d0(%edi)\n"
        ".Lf7d332_0007e114:\n"
        "movl 0x22c(%ebx), %eax\n" /* line 2501 | weapDef */
        "movl %eax, 0x34(%edi)\n" /* iWeapon */
        "movl $0x99, 0xc(%ebp)\n" /* line 2502 | pml */
        /* } scope */
        /* { scope 2: weapCount */
        "movl %edi, 8(%ebp)\n" /* line 2645 | iWeapon, pm */
        "jmp .Lf7d332_0007dd1e\n"
        /* } scope */
        /* { scope 2: weapCount */
        "movl 0xd4(%edi), %esi\n" /* line 521 */
        "movl bg_weaponDefs(, %esi, 4), %ebx\n"
        "movl -0x50(%ebp), %eax\n" /* line 2437 | delayedAction */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007edd0\n"
        ".Lf7d332_0007e144:\n"
        "movl 0x34(%edi), %eax\n" /* line 2440 | iWeapon */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d361\n"
        "cmpl $8, 0xd8(%edi)\n" /* line 2443 | iWeapon */
        "jne .Lf7d332_0007e176\n"
        "movl 0xd4(%edi), %esi\n" /* iWeapon, ps */
        "movl bg_weaponDefs(, %esi, 4), %eax\n"
        "movl 0x1d0(%eax), %eax\n"
        "movl 0x344(%edi, %eax, 4), %eax\n" /* iWeapon */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007e18b\n"
        ".Lf7d332_0007e176:\n"
        "movl %edi, %eax\n" /* iWeapon */
        "calll PM_Weapon_AllowReload\n"
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007efe5\n"
        "movl 0xd4(%edi), %esi\n" /* iWeapon, ps */
        ".Lf7d332_0007e18b:\n"
        "movl %esi, %edx\n" /* line 817 */
        "sarl $5, %edx\n"
        "andl $0x1f, %esi\n"
        "movl $0xfffffffe, %eax\n"
        "movl %esi, %ecx\n"
        "roll %cl, %eax\n"
        "andl %eax, 0x55c(%edi, %edx, 4)\n"
        "movl 0x22c(%ebx), %esi\n" /* line 2452 | weapDef, ps */
        "testl %esi, %esi\n" /* ps */
        "jne .Lf7d332_0007e0ed\n"
        "jmp .Lf7d332_0007dba9\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e1b6:\n"
        "cmpb %al, -0x41(%ebp)\n" /* line 3754 */
        "jne .Lf7d332_0007d65b\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "testl $0x30015, 8(%eax)\n"
        "jne .Lf7d332_0007d65b\n"
        "xorl %eax, %eax\n"
        "jmp .Lf7d332_0007d660\n"
        ".Lf7d332_0007e1d6:\n"
        "movl %ebx, %ecx\n" /* ps */
        "jmp .Lf7d332_0007d937\n"
        /* } scope */
        ".Lf7d332_0007e1dd:\n"
        "movl $0x437f0000, 0x5d4(%edi)\n" /* line 3878 | ps */
        "jmp .Lf7d332_0007daf0\n"
        /* { scope 2: weapCount */
        ".Lf7d332_0007e1ec:\n"
        "addl -0x4c(%ebp), %edx\n" /* line 1679 | breathGaspTime */
        "jmp .Lf7d332_0007d481\n"
        ".Lf7d332_0007e1f4:\n"
        "movl 0x5b8(%ebx), %eax\n" /* line 1663 */
        "movl -0x58(%ebp), %ecx\n" /* pml */
        "subl 0x28(%ecx), %eax\n"
        "movl %eax, 0x5b8(%ebx)\n"
        "jmp .Lf7d332_0007d449\n"
        ".Lf7d332_0007e20b:\n"
        "andl $0xffffbfff, %esi\n" /* line 1588 */
        "movl %esi, 0xc(%ebx)\n"
        "movl $0x3f800000, 0x5b4(%ebx)\n" /* line 1648 */
        "movl $0, 0x5b8(%ebx)\n" /* line 1649 */
        "jmp .Lf7d332_0007d4eb\n"
        ".Lf7d332_0007e22d:\n"
        "movl 0x195ee50, %eax\n" /* line 1679 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "movss 0x2ed5dc, %xmm1\n" /* -1.0f */
        "jmp .Lf7d332_0007d4b7\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e244:\n"
        "movl bg_weaponDefs(, %eax, 4), %ebx\n" /* line 521 */
        "cmpl $1, 0x78(%ebx)\n" /* line 2924 | weapDef */
        "je .Lf7d332_0007e79b\n"
        "movl 0x1fc(%ebx), %eax\n" /* line 2946 | weapDef */
        "movl %eax, 0x38(%edi)\n" /* iWeapon */
        "movl 0x204(%ebx), %eax\n" /* line 2947 | weapDef */
        "movl %eax, 0x34(%edi)\n" /* iWeapon */
        "movl 0x348(%ebx), %eax\n" /* line 2949 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007e297\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 2950 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss 0xdc(%edi), %xmm1\n" /* iWeapon */
        "divss 0x588(%ebx), %xmm0\n" /* weapDef */
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movl %eax, 0x38(%edi)\n" /* iWeapon */
        ".Lf7d332_0007e297:\n"
        "movl $1, 0xc(%esp)\n" /* line 2953 */
        "movl $0, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll BG_AnimScriptEvent\n"
        "movl 0x328(%ebx), %esi\n" /* line 2956 | weapDef */
        "testl %esi, %esi\n" /* weapDef */
        "je .Lf7d332_0007e2dd\n"
        "movl 0xd4(%edi), %ecx\n" /* line 2957 | iWeapon, bitNum */
        /* { scope 3 */
        "movl %ecx, %edx\n" /* line 812 */
        "sarl $5, %edx\n"
        "andl $0x1f, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orl %eax, 0x55c(%edi, %edx, 4)\n"
        /* } scope */
        ".Lf7d332_0007e2dd:\n"
        "cmpl $3, 0xd8(%edi)\n" /* line 2959 | iWeapon */
        "je .Lf7d332_0007e311\n"
        "movss 0xdc(%edi), %xmm0\n" /* line 2961 | iWeapon */
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jb .Lf7d332_0007ea6f\n"
        "movl 0x204(%ebx), %eax\n" /* line 2962 | weapDef */
        "imull 0x478(%ebx), %eax\n" /* weapDef */
        "addl 0x1fc(%ebx), %eax\n" /* weapDef */
        "movl %eax, 0x40(%edi)\n" /* iWeapon */
        ".Lf7d332_0007e311:\n"
        "movl $3, 0xd8(%edi)\n" /* line 2969 | iWeapon */
        "movl %edi, (%esp)\n" /* line 2970 | iWeapon */
        "calll PM_SetProneMovementOverride\n"
        /* { scope 3 */
        "movl 0xd4(%edi), %esi\n" /* line 521 */
        "movl bg_weaponDefs(, %esi, 4), %edx\n"
        /* { scope 4 */
        "movl 0x1d0(%edx), %ecx\n" /* line 1725 */
        "movl 0x344(%edi, %ecx, 4), %eax\n" /* line 1849 */
        /* } scope */
        "testl %eax, %eax\n" /* line 3011 */
        "jle .Lf7d332_0007e859\n"
        /* } scope */
        "movl 0x38(%edi), %edx\n" /* line 3116 | iWeapon */
        "testl %edx, %edx\n"
        "jne .Lf7d332_0007d361\n"
        "testl $0x300, 0xa0(%edi)\n" /* line 3128 | iWeapon */
        "jne .Lf7d332_0007e366\n"
        "subl $1, %eax\n" /* line 1834 */
        "movl %eax, 0x344(%edi, %ecx, 4)\n"
        ".Lf7d332_0007e366:\n"
        "cmpl $1, 0x78(%ebx)\n" /* line 3132 | weapDef */
        "je .Lf7d332_0007e965\n"
        ".Lf7d332_0007e370:\n"
        "movss 0xdc(%edi), %xmm0\n" /* line 3054 | iWeapon */
        "ucomiss 0x2ed67c, %xmm0\n" /* 0.75f */
        "jbe .Lf7d332_0007e838\n"
        "movl bg_weaponDefs(, %esi, 4), %eax\n" /* line 3056 */
        "movl 0x1d0(%eax), %eax\n"
        "cmpl $1, 0x344(%edi, %eax, 4)\n" /* iWeapon */
        "sbbl %edx, %edx\n"
        "notl %edx\n"
        "addl $6, %edx\n"
        /* { scope 3 */
        ".Lf7d332_0007e3a1:\n"
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007e3bd\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl %eax, %edx\n"
        "movl %edx, 0x5d0(%edi)\n"
        /* } scope */
        ".Lf7d332_0007e3bd:\n"
        "movl bg_weaponDefs(, %esi, 4), %eax\n" /* line 3138 */
        "movl 0x1d0(%eax), %eax\n"
        "movl 0x344(%edi, %eax, 4), %ecx\n" /* iWeapon */
        "testl %ecx, %ecx\n"
        "jne .Lf7d332_0007e823\n"
        "movl $0xa0, 4(%esp)\n" /* line 3139 */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll PM_AddEvent\n"
        /* { scope 3 */
        ".Lf7d332_0007e3e9:\n"
        "movl 0xc(%edi), %ebx\n" /* line 785 */
        "testl $0x20000, %ebx\n"
        "je .Lf7d332_0007e809\n"
        "movl bg_iNumWeapons, %esi\n" /* line 771 */
        "testl %esi, %esi\n"
        "jle .Lf7d332_0007e88e\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7d332_0007ed73\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7d332_0007e41f:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %esi\n"
        "jl .Lf7d332_0007e88e\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7d332_0007e41f\n"
        "movl %ecx, %eax\n"
        ".Lf7d332_0007e438:\n"
        "movzbl %al, %eax\n" /* line 774 */
        "movl 0xd4(%edi), %esi\n"
        /* { scope 4 */
        ".Lf7d332_0007e441:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        /* } scope */
        "movss 0x2ed5d0, %xmm2\n" /* line 1605 | 1.0f */
        "ucomiss 0xdc(%edi), %xmm2\n"
        "jne .Lf7d332_0007e4b5\n"
        "jp .Lf7d332_0007e4b5\n"
        "movl 0x278(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf7d332_0007e4b5\n"
        "cmpl $9, 0x7c(%eax)\n"
        "je .Lf7d332_0007e4b5\n"
        "movl 0x195ee44, %eax\n" /* line 1608 */
        "movl (%eax), %eax\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "movss 8(%eax), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %edx\n"
        "movl 0x195ee30, %eax\n" /* line 1609 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "cvttss2si %xmm0, %ecx\n"
        "movl 0x5b8(%edi), %eax\n" /* line 1611 */
        "cmpl %eax, %edx\n"
        "jle .Lf7d332_0007e4af\n"
        "leal (%ecx, %eax), %eax\n" /* line 1613 */
        "cmpl %eax, %edx\n" /* line 1616 */
        "cmovgel %eax, %edx\n"
        "movl %edx, 0x5b8(%edi)\n"
        ".Lf7d332_0007e4af:\n"
        "andb $0xbf, %bh\n" /* line 1588 */
        "movl %ebx, 0xc(%edi)\n"
        /* } scope */
        /* { scope 3 */
        ".Lf7d332_0007e4b5:\n"
        "movl bg_weaponDefs(, %esi, 4), %eax\n" /* line 521 */
        "ucomiss 0xdc(%edi), %xmm2\n" /* line 3087 | iWeapon */
        "jp .Lf7d332_0007e4cb\n"
        "je .Lf7d332_0007e802\n"
        ".Lf7d332_0007e4cb:\n"
        "movss 0x2ed5d4, %xmm1\n" /* line 3091 | 255.0f */
        "movss 0x2a8(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x5d4(%edi), %xmm0\n" /* iWeapon */
        "movss %xmm0, 0x5d4(%edi)\n" /* iWeapon */
        "ucomiss %xmm1, %xmm0\n" /* line 3092 */
        "jbe .Lf7d332_0007e4fc\n"
        "movss %xmm1, 0x5d4(%edi)\n" /* line 3093 | iWeapon */
        ".Lf7d332_0007e4fc:\n"
        "movl bg_weaponDefs(, %esi, 4), %edx\n"
        /* } scope */
        ".Lf7d332_0007e503:\n"
        "movl 0x340(%edx), %eax\n" /* line 2633 */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007d361\n"
        "movl 0x1d0(%edx), %eax\n" /* line 2636 */
        "movl 0x344(%edi, %eax, 4), %eax\n" /* iWeapon */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d361\n"
        "movl 0x1c8(%edx), %eax\n" /* line 2639 */
        "movl 0x144(%edi, %eax, 4), %eax\n" /* iWeapon */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d361\n"
        "movl %esi, 4(%esp)\n" /* line 2643 | ps */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll BG_TakePlayerWeapon\n"
        "movl $0x92, 0xc(%ebp)\n" /* line 2645 | pml */
        "movl %edi, 8(%ebp)\n" /* iWeapon, pm */
        "jmp .Lf7d332_0007dd1e\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e556:\n"
        "movl $0, 0x5b8(%ebx)\n" /* line 1666 */
        "jmp .Lf7d332_0007d457\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e565:\n"
        "movl bg_weaponDefs(, %edx, 4), %eax\n" /* line 521 */
        "movl 0x1d0(%eax), %ecx\n" /* line 1725 */
        "movl %ecx, -0x30(%ebp)\n" /* clipWeap */
        "movl 0x1c8(%eax), %eax\n" /* line 1736 */
        "movl %eax, -0x2c(%ebp)\n" /* ammoWeap */
        "movl -0x5c(%ebp), %eax\n" /* line 2604 | reloadRequested */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007e5d3\n"
        ".Lf7d332_0007e585:\n"
        "xorl %eax, %eax\n"
        ".Lf7d332_0007e587:\n"
        "movl -0x30(%ebp), %edx\n" /* line 2609 | clipWeap */
        "movl 0x344(%esi, %edx, 4), %ecx\n" /* ps */
        "testl %ecx, %ecx\n"
        "jne .Lf7d332_0007e5b8\n"
        "movl -0x2c(%ebp), %ecx\n" /* ammoWeap */
        "movl 0x144(%esi, %ecx, 4), %edx\n" /* ps */
        "testl %edx, %edx\n"
        "je .Lf7d332_0007e5b8\n"
        "cmpl $3, %ebx\n" /* weapDef */
        "je .Lf7d332_0007e5b8\n"
        "testb $1, 0xc(%esi)\n" /* ps */
        "je .Lf7d332_0007e5bc\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "cmpw $0, 0x1c(%edx)\n"
        "je .Lf7d332_0007e5bc\n"
        ".Lf7d332_0007e5b8:\n"
        "testl %eax, %eax\n" /* line 2618 */
        "je .Lf7d332_0007e639\n"
        ".Lf7d332_0007e5bc:\n"
        "movl %esi, %eax\n" /* line 2619 | ps */
        "calll PM_BeginWeaponReload\n"
        "movl -0x54(%ebp), %ecx\n" /* pm */
        "movl (%ecx), %esi\n" /* ps */
        "movl 0xd8(%esi), %ecx\n" /* ps */
        "jmp .Lf7d332_0007d937\n"
        ".Lf7d332_0007e5d3:\n"
        "movl %esi, %eax\n" /* line 2604 | ps */
        "calll PM_Weapon_AllowReload\n"
        "testl %eax, %eax\n"
        "je .Lf7d332_0007e585\n"
        "movl $1, %eax\n"
        "jmp .Lf7d332_0007e587\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e5e5:\n"
        "movl 0x3c(%edi), %eax\n" /* line 3549 | iWeapon */
        "testl %eax, %eax\n"
        "jle .Lf7d332_0007d508\n"
        "movl 0x33c(%edx), %edx\n" /* line 3552 */
        "testl %edx, %edx\n"
        "je .Lf7d332_0007d508\n"
        "movl -0x58(%ebp), %edx\n" /* line 3553 | pml */
        "subl 0x28(%edx), %eax\n"
        "movl %eax, 0x3c(%edi)\n" /* iWeapon */
        "testl %eax, %eax\n" /* line 3555 */
        "jg .Lf7d332_0007d508\n"
        /* { scope 3 */
        "movl bg_weaponDefs(, %ecx, 4), %eax\n" /* line 1725 */
        "movl 0x1d0(%eax), %eax\n"
        "subl $1, 0x344(%edi, %eax, 4)\n" /* line 1834 */
        /* } scope */
        "movl $0xc5, 4(%esp)\n" /* line 3558 */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll PM_AddEvent\n"
        "jmp .Lf7d332_0007d361\n"
        ".Lf7d332_0007e639:\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movl (%eax), %esi\n" /* weapDef */
        "movl 0xd8(%esi), %ecx\n" /* weapDef */
        "jmp .Lf7d332_0007d937\n"
        /* } scope */
        ".Lf7d332_0007e649:\n"
        "movl 0xc(%esi), %eax\n" /* line 2845 | weapDef */
        "testb $0x20, %al\n"
        "je .Lf7d332_0007e750\n"
        "movl 0xd4(%esi), %eax\n" /* line 2847 | weapDef */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007e68e\n"
        ".Lf7d332_0007e65e:\n"
        "movl -0x54(%ebp), %ecx\n" /* pm */
        "movl (%ecx), %esi\n" /* weapDef */
        "jmp .Lf7d332_0007d86e\n"
        ".Lf7d332_0007e668:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2871 */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007e65e\n"
        ".Lf7d332_0007e66f:\n"
        "movl -0x38(%ebp), %eax\n"
        "sarl $5, %eax\n"
        "andl $0x1f, -0x38(%ebp)\n"
        "movl 0x544(%esi, %eax, 4), %eax\n" /* weapDef */
        "movzbl -0x38(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf7d332_0007d869\n"
        ".Lf7d332_0007e68e:\n"
        "xorl %edx, %edx\n" /* line 2872 */
        "movl %esi, %eax\n" /* weapDef */
        "calll PM_BeginWeaponChange\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movl (%eax), %esi\n" /* weapDef */
        "jmp .Lf7d332_0007d86e\n"
        /* { scope 2: weapCount */
        ".Lf7d332_0007e6a1:\n"
        "movl 0xd8(%ecx), %edx\n" /* line 2773 */
        "leal -0xc(%edx), %eax\n"
        "cmpl $4, %eax\n"
        "jbe .Lf7d332_0007e6ce\n"
        "movl 0x324(%esi), %eax\n" /* weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007e6ce\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "testb $1, 8(%eax)\n"
        "je .Lf7d332_0007e6ce\n"
        "movzbl 0xc(%eax), %eax\n"
        "cmpl %eax, %ebx\n" /* weapDef */
        "je .Lf7d332_0007ee43\n"
        ".Lf7d332_0007e6ce:\n"
        "movl $0, 0x34(%ecx)\n" /* line 2798 */
        "jmp .Lf7d332_0007d54a\n"
        ".Lf7d332_0007e6da:\n"
        "movl $0, 0x38(%ecx)\n" /* line 2808 */
        "movl $1, -0x50(%ebp)\n" /* delayedAction */
        "jmp .Lf7d332_0007d569\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e6ed:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7d332_0007d3b3\n"
        ".Lf7d332_0007e6fa:\n"
        "movl 0x5b8(%ebx), %eax\n" /* line 1657 */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d42b\n"
        "orl $0x4000, %esi\n" /* line 1579 */
        "movl %esi, 0xc(%ebx)\n"
        "jmp .Lf7d332_0007d42b\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e716:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 2568 | pm */
        "testb $1, 8(%ecx)\n"
        "je .Lf7d332_0007d8de\n"
        "testb $1, 0x24(%ecx)\n"
        "jne .Lf7d332_0007d8de\n"
        "cmpl $7, %ebx\n" /* line 2570 | weapDef */
        "je .Lf7d332_0007ee02\n"
        "cmpl $5, %ebx\n" /* line 2572 | weapDef */
        "jne .Lf7d332_0007d8de\n"
        "movb $6, %bl\n" /* line 2573 | weapDef */
        "movl $6, 0xd8(%esi)\n" /* ps */
        "jmp .Lf7d332_0007d8e7\n"
        /* } scope */
        ".Lf7d332_0007e750:\n"
        "testl $0x4000000, %eax\n" /* line 2852 */
        "je .Lf7d332_0007e8b2\n"
        "movl 0xd4(%esi), %ebx\n" /* line 2854 | weapDef */
        "testl %ebx, %ebx\n" /* weapDef */
        "jne .Lf7d332_0007e76f\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movl (%eax), %esi\n" /* weapDef */
        "jmp .Lf7d332_0007d86e\n"
        ".Lf7d332_0007e76f:\n"
        "xorl %edx, %edx\n" /* line 2855 */
        "movl %esi, %eax\n" /* weapDef */
        "calll PM_BeginWeaponChange\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movl (%edx), %esi\n" /* weapDef */
        "jmp .Lf7d332_0007d86e\n"
        /* { scope 2: weapCount */
        ".Lf7d332_0007e782:\n"
        "movl -0x54(%ebp), %edx\n" /* line 3253 | pm */
        "testb $4, 8(%edx)\n"
        "jne .Lf7d332_0007e973\n"
        "andl $0xffffdfff, 0xc(%esi)\n" /* line 3255 | weapDef */
        "jmp .Lf7d332_0007d99d\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e79b:\n"
        "movl -0x50(%ebp), %eax\n" /* line 2926 | delayedAction */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007e311\n"
        "movl 0x1d0(%ebx), %eax\n" /* line 2929 | weapDef */
        "movl 0x344(%edi, %eax, 4), %eax\n" /* iWeapon */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007e7ed\n"
        "movl 0x248(%ebx), %eax\n" /* line 2931 | weapDef */
        "movl %eax, 0x3c(%edi)\n" /* iWeapon */
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007e7dd\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x13, %eax\n"
        "movl %eax, 0x5d0(%edi)\n"
        ".Lf7d332_0007e7dd:\n"
        "movl $0x9d, 4(%esp)\n" /* line 2935 */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll PM_AddEvent\n"
        ".Lf7d332_0007e7ed:\n"
        "movl 0x210(%ebx), %eax\n" /* line 2938 | weapDef */
        "movl %eax, 0x38(%edi)\n" /* iWeapon */
        "movl $0, 0x34(%edi)\n" /* line 2939 | iWeapon */
        "jmp .Lf7d332_0007e311\n"
        ".Lf7d332_0007e802:\n"
        "movl %eax, %edx\n"
        "jmp .Lf7d332_0007e503\n"
        /* { scope 3 */
        ".Lf7d332_0007e809:\n"
        "testb $0x10, %bl\n" /* line 790 */
        "je .Lf7d332_0007ea62\n"
        "movl 0xd0(%edi), %eax\n" /* line 792 */
        "movl 0xd4(%edi), %esi\n"
        "jmp .Lf7d332_0007e441\n"
        /* } scope */
        ".Lf7d332_0007e823:\n"
        "movl $0x9e, 4(%esp)\n" /* line 3141 */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll PM_AddEvent\n"
        "jmp .Lf7d332_0007e3e9\n"
        ".Lf7d332_0007e838:\n"
        "movl bg_weaponDefs(, %esi, 4), %eax\n" /* line 3063 */
        "movl 0x1d0(%eax), %eax\n"
        "cmpl $1, 0x344(%edi, %eax, 4)\n" /* iWeapon */
        "sbbl %edx, %edx\n"
        "notl %edx\n"
        "addl $3, %edx\n"
        "jmp .Lf7d332_0007e3a1\n"
        /* { scope 3 */
        ".Lf7d332_0007e859:\n"
        "movl 0x1c8(%edx), %eax\n" /* line 3013 */
        "movl 0x144(%edi, %eax, 4), %ebx\n" /* iWeapon, weapDef */
        "testl %ebx, %ebx\n" /* weapDef */
        "setg %al\n"
        "movzbl %al, %eax\n"
        "cmpl $1, 0x78(%edx)\n" /* line 3015 */
        "je .Lf7d332_0007eb08\n"
        "testl %eax, %eax\n" /* line 3020 */
        "je .Lf7d332_0007ed50\n"
        ".Lf7d332_0007e880:\n"
        "movl %edi, %eax\n" /* line 3026 | iWeapon */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 3979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: breathGaspTime, weapDef, reloadRequested, clipWeap, ... */
        /* { scope 2: weapCount */
        /* { scope 3 */
        "jmp PM_BeginWeaponReload\n" /* line 3026 */
        /* } scope */
        /* { scope 3 */
        ".Lf7d332_0007e88e:\n"
        "xorl %eax, %eax\n" /* line 797 */
        "movl 0xd4(%edi), %esi\n"
        "jmp .Lf7d332_0007e441\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e89b:\n"
        "testl $0x20000, %eax\n" /* line 3500 */
        "je .Lf7d332_0007d7f2\n"
        "movl $2, -0x20(%ebp)\n"
        "jmp .Lf7d332_0007d76d\n"
        /* } scope */
        ".Lf7d332_0007e8b2:\n"
        "movl 0xd4(%esi), %ecx\n" /* line 2866 | weapDef */
        "movl %ecx, -0x38(%ebp)\n"
        "movl -0x54(%ebp), %ecx\n" /* pm */
        "movzbl 0xc(%ecx), %edx\n"
        "movzbl %dl, %ebx\n" /* weapDef */
        "cmpl %ebx, -0x38(%ebp)\n" /* weapDef */
        "je .Lf7d332_0007e668\n"
        "testw %ax, %ax\n"
        "jns .Lf7d332_0007e8de\n"
        "movl -0x38(%ebp), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf7d332_0007e66f\n"
        ".Lf7d332_0007e8de:\n"
        "testb %dl, %dl\n"
        "je .Lf7d332_0007e952\n"
        /* { scope 2: weapCount */
        "xorl %edx, %edx\n" /* line 877 */
        "cmpl bg_iNumWeapons, %ebx\n"
        "setle %dl\n"
        "movl %ebx, %eax\n" /* line 904 */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x544(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "xorl %ecx, %ecx\n"
        "testb $1, %al\n"
        "cmovnel %edx, %ecx\n"
        "movl bg_weaponDefs(, %ebx, 4), %eax\n" /* line 521 */
        "movl 0x84(%eax), %edx\n" /* line 909 */
        "testl %edx, %edx\n"
        "jne .Lf7d332_0007ed6b\n"
        "movl 0x36c(%eax), %edx\n" /* line 911 */
        "movsbl 0x555(%esi), %eax\n" /* line 913 */
        "cmpl %eax, %ebx\n"
        "je .Lf7d332_0007ed6b\n"
        "movsbl 0x556(%esi), %eax\n"
        "cmpl %eax, %ebx\n"
        "je .Lf7d332_0007ed6b\n"
        "cmpl %edx, %ebx\n"
        "je .Lf7d332_0007ed6b\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf7d332_0007e94a:\n"
        "testl %eax, %eax\n" /* line 2866 */
        "je .Lf7d332_0007e668\n"
        ".Lf7d332_0007e952:\n"
        "movl %ebx, %edx\n" /* line 2868 | weapDef */
        "movl %esi, %eax\n" /* weapDef */
        "calll PM_BeginWeaponChange\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movl (%eax), %esi\n" /* weapDef */
        "jmp .Lf7d332_0007d86e\n"
        /* { scope 2: weapCount */
        ".Lf7d332_0007e965:\n"
        "movl 0x204(%ebx), %eax\n" /* line 3133 | weapDef */
        "movl %eax, 0x34(%edi)\n" /* iWeapon */
        "jmp .Lf7d332_0007e370\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007e973:\n"
        "movl 0xc(%esi), %eax\n" /* line 3259 | weapDef */
        "testb $0x20, %ah\n"
        "jne .Lf7d332_0007d99d\n"
        "orb $0x20, %ah\n" /* line 3262 */
        "movl %eax, 0xc(%esi)\n" /* weapDef */
        "movss 0xdc(%esi), %xmm0\n" /* line 3265 | weapDef */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf7d332_0007e9a4\n"
        "movl 0x278(%ebx), %eax\n" /* weapDef */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d99d\n"
        ".Lf7d332_0007e9a4:\n"
        "cmpl $0xb, 0xd8(%esi)\n" /* line 3269 | weapDef */
        "ja .Lf7d332_0007e9bf\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0xc06, %eax\n"
        "jne .Lf7d332_0007d99d\n"
        ".Lf7d332_0007e9bf:\n"
        "movl $1, 0xc(%esp)\n" /* line 3282 */
        "movl $0, 8(%esp)\n"
        "movl $0x11, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* weapDef */
        "calll BG_AnimScriptEvent\n"
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007e9fc\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $8, %eax\n"
        "movl %eax, 0x5d0(%esi)\n"
        ".Lf7d332_0007e9fc:\n"
        "movl $0xa3, 4(%esp)\n" /* line 3287 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        "movl 0x200(%ebx), %edx\n" /* line 3289 | weapDef */
        "testl %edx, %edx\n"
        "jne .Lf7d332_0007f195\n"
        /* { scope 3 */
        "movl 0xd4(%esi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x214(%eax), %edx\n" /* line 3160 */
        "subl 0x200(%eax), %edx\n"
        "cmpl %edx, 0x34(%esi)\n" /* weapDef */
        "jge .Lf7d332_0007ea3b\n"
        "movl %edx, 0x34(%esi)\n" /* line 3161 | weapDef */
        ".Lf7d332_0007ea3b:\n"
        "movl $0xa4, 4(%esp)\n" /* line 3163 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        "movl $0xb, 0xd8(%esi)\n" /* line 3165 | weapDef */
        "movl %esi, (%esp)\n" /* line 3166 | weapDef */
        "calll PM_SetProneMovementOverride\n"
        "jmp .Lf7d332_0007d99d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        /* { scope 3 */
        ".Lf7d332_0007ea62:\n"
        "movl 0xd4(%edi), %esi\n" /* line 797 */
        "movl %esi, %eax\n"
        "jmp .Lf7d332_0007e441\n"
        /* } scope */
        ".Lf7d332_0007ea6f:\n"
        "movl 0x204(%ebx), %eax\n" /* line 2964 | weapDef */
        "imull 0x4c0(%ebx), %eax\n" /* weapDef */
        "addl 0x1fc(%ebx), %eax\n" /* weapDef */
        "movl %eax, 0x40(%edi)\n" /* iWeapon */
        "jmp .Lf7d332_0007e311\n"
        /* } scope */
        ".Lf7d332_0007ea8a:\n"
        "movl 0x5d0(%eax), %edx\n" /* line 499 */
        "testl $0xfffffdff, %edx\n"
        "je .Lf7d332_0007dc1e\n"
        /* { scope 2: weapCount */
        "cmpl $5, 4(%eax)\n" /* line 485 */
        "jg .Lf7d332_0007dc1e\n"
        "andl $0x200, %edx\n" /* line 488 */
        "xorb $2, %dh\n"
        "movl %edx, 0x5d0(%eax)\n"
        "jmp .Lf7d332_0007dc1e\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007eaba:\n"
        "movl -0x50(%ebp), %eax\n" /* line 1905 | delayedAction */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007da10\n"
        "movl $0xfffffffe, %eax\n" /* line 817 */
        "roll %cl, %eax\n"
        "movl -0x28(%ebp), %edx\n"
        "andl %eax, (%ebx, %edx)\n"
        "movl $0xa2, 4(%esp)\n" /* line 1909 */
        "movl %edi, (%esp)\n"
        "calll PM_AddEvent\n"
        "movl 0x34(%edi), %eax\n" /* line 1911 */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d361\n"
        "movl 0xd8(%edi), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* reloadRequested */
        "jmp .Lf7d332_0007da45\n"
        ".Lf7d332_0007eafb:\n"
        "movl (%eax), %esi\n" /* weapDef */
        "movl 0xd8(%esi), %ecx\n" /* weapDef */
        "jmp .Lf7d332_0007d937\n"
        /* } scope */
        /* { scope 2: weapCount */
        /* { scope 3 */
        ".Lf7d332_0007eb08:\n"
        "testl %eax, %eax\n" /* line 3024 */
        "jne .Lf7d332_0007e880\n"
        ".Lf7d332_0007eb10:\n"
        "movl %esi, %edx\n" /* line 817 */
        "sarl $5, %edx\n"
        "andl $0x1f, %esi\n"
        "movl $0xfffffffe, %eax\n"
        "movl %esi, %ecx\n"
        "roll %cl, %eax\n"
        "andl %eax, 0x55c(%edi, %edx, 4)\n"
        "movl 0x5d0(%edi), %eax\n" /* line 499 */
        "testl $0xfffffdff, %eax\n"
        "je .Lf7d332_0007eb49\n"
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007eb49\n"
        "andl $0x200, %eax\n" /* line 488 */
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%edi)\n"
        ".Lf7d332_0007eb49:\n"
        "addl $0x1f4, 0x34(%edi)\n" /* line 3032 | iWeapon */
        "jmp .Lf7d332_0007d361\n"
        /* } scope */
        /* } scope */
        ".Lf7d332_0007eb55:\n"
        "movl $0, 0xdc(%edi)\n" /* line 3582 | iWeapon */
        "movl $0x95, 4(%esp)\n" /* line 1484 */
        "movl %edi, (%esp)\n"
        "calll PM_AddEvent\n"
        "andl $0xfffdffbf, 0xc(%edi)\n" /* line 3575 | iWeapon */
        "movl $0xa9, 4(%esp)\n" /* line 3576 */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll PM_AddEvent\n"
        "jmp .Lf7d332_0007db9b\n"
        /* { scope 2: weapCount */
        ".Lf7d332_0007eb8b:\n"
        "xorl %eax, %eax\n" /* line 771 */
        "jmp .Lf7d332_0007df0e\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007eb92:\n"
        "movl 0x5d0(%edi), %eax\n" /* line 499 */
        "testl $0xfffffdff, %eax\n"
        "je .Lf7d332_0007ebb3\n"
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007ebb3\n"
        "andl $0x200, %eax\n" /* line 488 */
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%edi)\n"
        ".Lf7d332_0007ebb3:\n"
        "movl $0, 0xd8(%edi)\n" /* line 1880 */
        "jmp .Lf7d332_0007dac8\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007ebc2:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 3767 | pm */
        "movl 8(%ecx), %eax\n"
        "testb $1, %al\n"
        "jne .Lf7d332_0007d6f9\n"
        "cmpl $0x14, %edx\n" /* line 3771 */
        "je .Lf7d332_0007f1fc\n"
        ".Lf7d332_0007ebd9:\n"
        "movl 0x195ee20, %eax\n" /* line 3783 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf7d332_0007f163\n"
        "movl -0x54(%ebp), %eax\n" /* line 3785 | pm */
        "testb $0x40, 0x25(%eax)\n"
        "jne .Lf7d332_0007edf9\n"
        "testb $0x40, 9(%eax)\n"
        "je .Lf7d332_0007edf9\n"
        "movl 0xd8(%esi), %eax\n" /* line 3787 | weapDef */
        "subl $0x11, %eax\n"
        "cmpl $6, %eax\n"
        "setae %al\n"
        ".Lf7d332_0007ec10:\n"
        "movl 0xd8(%esi), %edx\n" /* line 3788 | weapDef */
        "cmpl $0x11, %edx\n"
        "jle .Lf7d332_0007edfb\n"
        "cmpl $0x14, %edx\n" /* line 3795 */
        "jg .Lf7d332_0007edfb\n"
        "movl $1, %edx\n"
        ".Lf7d332_0007ec2d:\n"
        "testb %al, %al\n" /* line 3798 */
        "je .Lf7d332_0007f045\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jle .Lf7d332_0007f03b\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "movl 0x78(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "cmpl $3, %eax\n"
        "je .Lf7d332_0007ec7c\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7d332_0007ec5d:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jl .Lf7d332_0007f0ed\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7d332_0007ec5d\n"
        "testb %cl, %cl\n" /* line 3800 */
        "je .Lf7d332_0007f03b\n"
        ".Lf7d332_0007ec7c:\n"
        "movl -0x54(%ebp), %eax\n" /* line 3803 | pm */
        "cmpb $0, 0xc(%eax)\n"
        "jne .Lf7d332_0007f320\n"
        /* { scope 3 */
        "cmpl $3, -0x40(%ebp)\n" /* line 773 */
        "je .Lf7d332_0007f3fc\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        "jmp .Lf7d332_0007ecaf\n"
        ".Lf7d332_0007ec9f:\n"
        "movl 8(%edx), %eax\n"
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7d332_0007f4e9\n"
        ".Lf7d332_0007ecaf:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jge .Lf7d332_0007ec9f\n"
        "xorl %eax, %eax\n"
        "jmp .Lf7d332_0007f404\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007ecbd:\n"
        "movl $1, 0x38(%edi)\n" /* line 1935 */
        "jmp .Lf7d332_0007dab8\n"
        /* } scope */
        ".Lf7d332_0007ecc9:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 3430 */
        "movl 0x244(%eax), %eax\n"
        "movl %eax, 0x34(%edi)\n" /* iWeapon */
        "movl $0, 0x38(%edi)\n" /* line 3431 | iWeapon */
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007dd46\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x12, %eax\n"
        "movl %eax, 0x5d0(%edi)\n"
        "jmp .Lf7d332_0007dd46\n"
        ".Lf7d332_0007ed06:\n"
        "movl 0xd4(%ebx), %eax\n" /* line 3684 | weapDef */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x244(%eax), %eax\n"
        "movl %eax, 0x34(%ebx)\n" /* weapDef */
        "movl $0, 0x38(%ebx)\n" /* line 3685 | weapDef */
        /* { scope 2: weapCount */
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jg .Lf7d332_0007d361\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x12, %eax\n"
        "movl %eax, 0x5d0(%ebx)\n"
        "jmp .Lf7d332_0007d361\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007ed49:\n"
        "movl %edi, %eax\n" /* line 2223 */
        "jmp .Lf7d332_0007e010\n"
        /* } scope */
        /* { scope 2: weapCount */
        /* { scope 3 */
        ".Lf7d332_0007ed50:\n"
        "movl $0x92, 4(%esp)\n" /* line 3021 */
        "movl %edi, (%esp)\n" /* iWeapon */
        "calll PM_AddEvent\n"
        "movl 0xd4(%edi), %esi\n" /* iWeapon, weapDef */
        "jmp .Lf7d332_0007eb10\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007ed6b:\n"
        "movzbl %cl, %eax\n" /* line 913 */
        "jmp .Lf7d332_0007e94a\n"
        /* } scope */
        /* { scope 2: weapCount */
        /* { scope 3 */
        ".Lf7d332_0007ed73:\n"
        "movl $1, %eax\n" /* line 773 */
        "jmp .Lf7d332_0007e438\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007ed7d:\n"
        "cmpl $5, 4(%edi)\n" /* line 485 */
        "jg .Lf7d332_0007da88\n"
        "movl 0x5d0(%edi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $4, %eax\n"
        "movl %eax, 0x5d0(%edi)\n"
        "jmp .Lf7d332_0007da88\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007eda3:\n"
        "movl $0, 0xd8(%esi)\n" /* line 2236 | weapDef */
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007d361\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%esi)\n"
        "jmp .Lf7d332_0007d361\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007edd0:\n"
        "movl %edi, %eax\n" /* line 2438 | iWeapon */
        "calll PM_Weapon_ReloadDelayedAction\n"
        "jmp .Lf7d332_0007e144\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007eddc:\n"
        "movl %edi, %eax\n" /* line 2480 | iWeapon */
        "calll PM_Weapon_ReloadDelayedAction\n"
        "movl 0x34(%edi), %eax\n" /* line 2482 | iWeapon */
        "testl %eax, %eax\n"
        "jne .Lf7d332_0007d361\n"
        "movl 0xd4(%edi), %esi\n" /* iWeapon, ps */
        "jmp .Lf7d332_0007e0a1\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007edf9:\n"
        "xorl %eax, %eax\n" /* line 3787 */
        ".Lf7d332_0007edfb:\n"
        "xorl %edx, %edx\n" /* line 3795 */
        "jmp .Lf7d332_0007ec2d\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007ee02:\n"
        "movb $8, %bl\n" /* line 2571 | weapDef */
        "movl $8, 0xd8(%esi)\n" /* ps */
        "jmp .Lf7d332_0007d8e7\n"
        ".Lf7d332_0007ee13:\n"
        "movl $1, 0xc(%esp)\n" /* line 2589 */
        "movl $0, 8(%esp)\n"
        "movl $0xa, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movl (%edx), %esi\n" /* ps */
        "movl 0xd8(%esi), %ecx\n" /* ps */
        "jmp .Lf7d332_0007d937\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007ee43:\n"
        "movl bg_weaponDefs(, %ebx, 4), %eax\n" /* line 2773 */
        "movl 0x1d0(%eax), %eax\n"
        "movl 0x344(%ecx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7d332_0007e6ce\n"
        "movl $1, 0x34(%ecx)\n" /* line 2775 */
        "cmpl $5, %edx\n" /* line 2779 */
        "je .Lf7d332_0007f1c2\n"
        "cmpl $7, %edx\n"
        "je .Lf7d332_0007f1c2\n"
        "cmpl $9, %edx\n"
        "je .Lf7d332_0007f1c2\n"
        "cmpl $8, %edx\n"
        "je .Lf7d332_0007f1c2\n"
        "cmpl $6, %edx\n"
        "je .Lf7d332_0007f1c2\n"
        ".Lf7d332_0007ee93:\n"
        "cmpl $4, %edx\n" /* line 2787 */
        "je .Lf7d332_0007eeae\n"
        "leal -3(%edx), %eax\n" /* line 2791 */
        "cmpl $1, %eax\n"
        "jbe .Lf7d332_0007eeae\n"
        "cmpl $0xa, %edx\n"
        "je .Lf7d332_0007eeae\n"
        "cmpl $0xb, %edx\n"
        "jne .Lf7d332_0007d54a\n"
        ".Lf7d332_0007eeae:\n"
        "movl 0x5d0(%ecx), %eax\n" /* line 499 */
        "testl $0xfffffdff, %eax\n"
        "je .Lf7d332_0007eecf\n"
        /* { scope 3 */
        "cmpl $5, 4(%ecx)\n" /* line 485 */
        "jg .Lf7d332_0007eecf\n"
        "andl $0x200, %eax\n" /* line 488 */
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%ecx)\n"
        /* } scope */
        ".Lf7d332_0007eecf:\n"
        "movl $0, 0xd8(%ecx)\n" /* line 2794 */
        "jmp .Lf7d332_0007d54a\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007eede:\n"
        "movl $1, 0xd8(%esi)\n" /* line 2252 | weapDef */
        "movl %esi, (%esp)\n" /* line 2253 | weapDef */
        "calll PM_SetProneMovementOverride\n"
        "testl %edi, %edi\n" /* line 2255 */
        "je .Lf7d332_0007ef0a\n"
        "movl -0x24(%ebp), %edx\n"
        "movl bg_weaponDefs(, %edx, 4), %eax\n"
        "cmpl 0x36c(%eax), %edi\n"
        "je .Lf7d332_0007f3e7\n"
        ".Lf7d332_0007ef0a:\n"
        "movl $0x9a, 4(%esp)\n" /* line 2263 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        "movl bg_weaponDefs(, %edi, 4), %eax\n" /* line 2265 */
        "movl 0x234(%eax), %eax\n"
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        /* { scope 3 */
        ".Lf7d332_0007ef2a:\n"
        "movl bg_weaponDefs(, %edi, 4), %ebx\n" /* line 521 */
        /* } scope */
        "movl $1, 0xc(%esp)\n" /* line 2271 */
        "movl 0x74(%ebx), %eax\n" /* weaponDef */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0xcc(%esi), %eax\n" /* weapDef */
        "movl %eax, (%esp)\n"
        "calll BG_UpdateConditionValue\n"
        "movl $1, 0xc(%esp)\n" /* line 2272 */
        "movl 0x7c(%ebx), %eax\n" /* weaponDef */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 0xcc(%esi), %eax\n" /* weapDef */
        "movl %eax, (%esp)\n"
        "calll BG_UpdateConditionValue\n"
        "testl %edi, %edi\n" /* line 2276 | iWeapon */
        "je .Lf7d332_0007ef95\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl bg_weaponDefs(, %ecx, 4), %eax\n"
        "cmpl 0x36c(%eax), %edi\n" /* iWeapon */
        "je .Lf7d332_0007f3a8\n"
        ".Lf7d332_0007ef95:\n"
        "movl $0, 0xc(%esp)\n" /* line 2288 */
        "movl $0, 8(%esp)\n"
        "movl $7, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* weapDef */
        "calll BG_AnimScriptEvent\n"
        "movl $0x437f0000, 0x5d4(%esi)\n" /* line 2292 | weapDef */
        /* { scope 3 */
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007d361\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0xa, %eax\n"
        "movl %eax, 0x5d0(%esi)\n"
        "jmp .Lf7d332_0007d361\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007efe5:\n"
        "movl %edi, %eax\n" /* line 2494 | iWeapon */
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 3979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: breathGaspTime, weapDef, reloadRequested, clipWeap, ... */
        /* { scope 2: weapCount */
        "jmp PM_SetReloadingState\n" /* line 2494 */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007eff3:\n"
        "movl $1, %eax\n" /* line 773 */
        "jmp .Lf7d332_0007df0b\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007effd:\n"
        "movl 0xd4(%ebx), %eax\n" /* line 3684 | weapDef */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl 0x244(%eax), %eax\n"
        "movl %eax, 0x34(%ebx)\n" /* weapDef */
        "movl $0, 0x38(%ebx)\n" /* line 3685 | weapDef */
        /* { scope 3 */
        "cmpl $5, 4(%ebx)\n" /* line 485 */
        "jg .Lf7d332_0007f0ed\n"
        "movl 0x5d0(%ebx), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x12, %eax\n"
        "movl %eax, 0x5d0(%ebx)\n"
        ".Lf7d332_0007f03b:\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movl (%edx), %esi\n"
        "jmp .Lf7d332_0007d6f9\n"
        /* } scope */
        ".Lf7d332_0007f045:\n"
        "testb %dl, %dl\n" /* line 3810 */
        "je .Lf7d332_0007f03b\n"
        "cmpl $0x12, 0xd8(%esi)\n" /* line 3812 | weapDef */
        "je .Lf7d332_0007f517\n"
        /* { scope 3 */
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jle .Lf7d332_0007f092\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7d332_0007f50a\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        "jmp .Lf7d332_0007f08b\n"
        ".Lf7d332_0007f07b:\n"
        "movl 8(%edx), %eax\n"
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7d332_0007f500\n"
        ".Lf7d332_0007f08b:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ebx, %ecx\n"
        "jle .Lf7d332_0007f07b\n"
        ".Lf7d332_0007f092:\n"
        "xorl %eax, %eax\n"
        /* { scope 4 */
        ".Lf7d332_0007f094:\n"
        "movl bg_weaponDefs(, %eax, 4), %ecx\n" /* line 521 */
        /* } scope */
        "movl $0x15, 0xd8(%esi)\n" /* line 3653 | weapDef */
        "movl 0x195ee48, %eax\n" /* line 3654 */
        "movl (%eax), %edx\n"
        "movl 0x2c4(%ecx), %eax\n"
        "addl 8(%edx), %eax\n"
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        "movl $0, 0x38(%esi)\n" /* line 3655 | weapDef */
        "movl $0xac, 4(%esp)\n" /* line 3657 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007f159\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%esi)\n"
        ".Lf7d332_0007f0ed:\n"
        "movl -0x54(%ebp), %ecx\n" /* pm */
        "movl (%ecx), %esi\n"
        "jmp .Lf7d332_0007d6f9\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f0f7:\n"
        "andl $0x4000000, %ebx\n" /* line 2210 | weaponDef */
        "jne .Lf7d332_0007dff7\n"
        "cmpl %edi, bg_iNumWeapons\n" /* line 2219 */
        "jge .Lf7d332_0007e001\n"
        "jmp .Lf7d332_0007dff7\n"
        /* } scope */
        /* { scope 2: weapCount */
        /* { scope 3 */
        ".Lf7d332_0007f114:\n"
        "movl 0xd4(%esi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %ebx\n"
        "movl $0x95, 4(%esp)\n" /* line 1484 */
        "movl %esi, (%esp)\n"
        "calll PM_AddEvent\n"
        "andl $0xffffffbf, 0xc(%esi)\n" /* line 1485 */
        "movl $0, 0x34(%esi)\n" /* line 3596 | weapDef */
        "movl 0x195ee48, %eax\n" /* line 3597 */
        "movl (%eax), %edx\n"
        "movl 0x2c4(%ebx), %eax\n" /* weapDef */
        "addl 8(%edx), %eax\n"
        "movl %eax, 0x38(%esi)\n" /* weapDef */
        "movl $0x11, 0xd8(%esi)\n" /* line 3598 | weapDef */
        ".Lf7d332_0007f159:\n"
        "movl -0x54(%ebp), %eax\n" /* pm */
        "movl (%eax), %esi\n" /* weapDef */
        "jmp .Lf7d332_0007d6f9\n"
        /* } scope */
        ".Lf7d332_0007f163:\n"
        "movl -0x54(%ebp), %edx\n" /* line 3792 | pm */
        "movl 8(%edx), %eax\n"
        "shrl $0xe, %eax\n"
        "movl %eax, %edx\n" /* line 3794 */
        "andb $1, %dl\n"
        "je .Lf7d332_0007f1be\n"
        "movl 0xd8(%esi), %eax\n" /* weapDef */
        "subl $0x11, %eax\n"
        "cmpl $5, %eax\n"
        "jbe .Lf7d332_0007f1be\n"
        "movl $1, %eax\n"
        ".Lf7d332_0007f186:\n"
        "testb %dl, %dl\n" /* line 3795 */
        "je .Lf7d332_0007ec10\n"
        "xorl %edx, %edx\n"
        "jmp .Lf7d332_0007ec2d\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f195:\n"
        "movl 0x214(%ebx), %eax\n" /* line 3291 | weapDef */
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        "movl 0x200(%ebx), %eax\n" /* line 3292 | weapDef */
        "movl %eax, 0x38(%esi)\n" /* weapDef */
        "movl $0xa, 0xd8(%esi)\n" /* line 3293 | weapDef */
        "movl %esi, (%esp)\n" /* line 3294 | weapDef */
        "calll PM_SetProneMovementOverride\n"
        "jmp .Lf7d332_0007d99d\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f1be:\n"
        "xorl %eax, %eax\n" /* line 3794 */
        "jmp .Lf7d332_0007f186\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f1c2:\n"
        "movl $0, 0x34(%ecx)\n" /* line 2780 */
        "cmpl $5, %edx\n" /* line 2782 */
        "jne .Lf7d332_0007f37f\n"
        ".Lf7d332_0007f1d2:\n"
        "cmpl $9, %edx\n"
        "je .Lf7d332_0007ee93\n"
        ".Lf7d332_0007f1db:\n"
        "movl 0x35c(%esi), %eax\n" /* weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007ee93\n"
        "movl 0x224(%esi), %ebx\n" /* weapDef */
        "testl %ebx, %ebx\n" /* weapDef */
        "jne .Lf7d332_0007e6ce\n"
        "jmp .Lf7d332_0007ee93\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f1fc:\n"
        "testb $0x28, 0x24(%ecx)\n" /* line 3773 */
        "jne .Lf7d332_0007f303\n"
        "testb $0x28, %al\n" /* line 3776 */
        "je .Lf7d332_0007ebd9\n"
        "movl $0xaa, 4(%esp)\n" /* line 3777 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        "jmp .Lf7d332_0007ebd9\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f223:\n"
        "movl %esi, 8(%esp)\n" /* line 3509 | weapDef */
        "movl %ebx, 4(%esp)\n" /* offHandIndex */
        "movl $0xa7, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "movl %ebx, 0xd0(%esi)\n" /* line 3510 | offHandIndex, weapDef */
        "movl bg_weaponDefs(, %ebx, 4), %ebx\n" /* line 521 */
        "cmpl $1, 0x78(%ebx)\n" /* line 3520 | offHandIndex */
        "je .Lf7d332_0007f264\n"
        "movl (%ebx), %eax\n" /* line 3521 | offHandIndex */
        "movl %eax, 8(%esp)\n"
        "movl $0x21cbb4, 4(%esp)\n" /* "[%s] Only grenades are currently supported for off hand use
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf7d332_0007f264:\n"
        "movl 0x84(%ebx), %eax\n" /* line 3523 | offHandIndex */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007f464\n"
        ".Lf7d332_0007f272:\n"
        "movl 0xd4(%esi), %eax\n" /* line 3526 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7d332_0007f289\n"
        "cmpl $0x10, 0xd8(%esi)\n" /* weapDef */
        "jne .Lf7d332_0007f483\n"
        /* { scope 3 */
        ".Lf7d332_0007f289:\n"
        "movl 0xd0(%esi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl $0xd, 0xd8(%esi)\n" /* line 3347 | weapDef */
        "movl 0x210(%eax), %eax\n" /* line 3348 */
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        "movl $0, 0x38(%esi)\n" /* line 3349 | weapDef */
        "orl $0x10, 0xc(%esi)\n" /* line 3350 | weapDef */
        "movl %esi, 8(%esp)\n" /* line 3352 | weapDef */
        "movl 0xd0(%esi), %eax\n" /* weapDef */
        "movl %eax, 4(%esp)\n"
        "movl $0xa5, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007f2eb\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x13, %eax\n"
        "movl %eax, 0x5d0(%esi)\n"
        ".Lf7d332_0007f2eb:\n"
        "movl %esi, (%esp)\n" /* line 3355 | weapDef */
        "calll PM_SetProneMovementOverride\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movl (%edx), %esi\n" /* weapDef */
        "movl 0xd8(%esi), %edx\n" /* weapDef */
        "jmp .Lf7d332_0007d7fd\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f303:\n"
        "testb $0x28, %al\n" /* line 3778 */
        "jne .Lf7d332_0007ebd9\n"
        "movl $0xab, 4(%esp)\n" /* line 3779 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        "jmp .Lf7d332_0007ebd9\n"
        ".Lf7d332_0007f320:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 3805 | pm */
        "testb $0x10, 9(%ecx)\n"
        "jne .Lf7d332_0007f114\n"
        /* { scope 3 */
        "movl 0xd4(%esi), %eax\n" /* line 521 */
        "movl bg_weaponDefs(, %eax, 4), %eax\n"
        "movl $0x12, 0xd8(%esi)\n" /* line 3608 | weapDef */
        "movl 0x240(%eax), %eax\n" /* line 3609 */
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        "movl $0, 0x38(%esi)\n" /* line 3610 | weapDef */
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007f159\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x11, %eax\n"
        "movl %eax, 0x5d0(%esi)\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movl (%edx), %esi\n"
        "jmp .Lf7d332_0007d6f9\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f37f:\n"
        "cmpl $7, %edx\n" /* line 2782 */
        "je .Lf7d332_0007f1d2\n"
        "cmpl $9, %edx\n"
        "je .Lf7d332_0007ee93\n"
        "cmpl $8, %edx\n"
        "je .Lf7d332_0007f1db\n"
        "cmpl $6, %edx\n"
        "jne .Lf7d332_0007ee93\n"
        "jmp .Lf7d332_0007f1db\n"
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f3a8:\n"
        "movss 0x2ed7cc, %xmm0\n" /* line 2279 | 128.0f */
        "ucomiss 0x5d4(%esi), %xmm0\n" /* weapDef */
        "jbe .Lf7d332_0007f3c1\n"
        "movss %xmm0, 0x5d4(%esi)\n" /* line 2280 | weapDef */
        ".Lf7d332_0007f3c1:\n"
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007d361\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x10, %eax\n"
        "movl %eax, 0x5d0(%esi)\n"
        "jmp .Lf7d332_0007d361\n"
        ".Lf7d332_0007f3e7:\n"
        "movl bg_weaponDefs(, %edi, 4), %eax\n" /* line 2259 */
        "movl 0x23c(%eax), %eax\n"
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        "jmp .Lf7d332_0007ef2a\n"
        /* } scope */
        /* { scope 2: weapCount */
        /* { scope 3 */
        ".Lf7d332_0007f3fc:\n"
        "movl $1, %eax\n" /* line 773 */
        ".Lf7d332_0007f401:\n"
        "movzbl %al, %eax\n" /* line 774 */
        /* { scope 4 */
        ".Lf7d332_0007f404:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        /* } scope */
        "movl $0x13, 0xd8(%esi)\n" /* line 3626 | weapDef */
        "movl 0x2c0(%eax), %eax\n" /* line 3627 */
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        "movl $0, 0x38(%esi)\n" /* line 3628 | weapDef */
        "orl $0x20000, 0xc(%esi)\n" /* line 3568 | weapDef */
        "movl $0xa8, 4(%esp)\n" /* line 3569 */
        "movl %esi, (%esp)\n" /* weapDef */
        "calll PM_AddEvent\n"
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007f0ed\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "movl %eax, 0x5d0(%esi)\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movl (%edx), %esi\n"
        "jmp .Lf7d332_0007d6f9\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        ".Lf7d332_0007f464:\n"
        "movl (%ebx), %eax\n" /* line 3524 | offHandIndex */
        "movl %eax, 8(%esp)\n"
        "movl $0x21cbf4, 4(%esp)\n" /* "[%s] No offhand class set
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7d332_0007f272\n"
        /* { scope 3 */
        ".Lf7d332_0007f483:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "movl $0xc, 0xd8(%esi)\n" /* line 3327 | weapDef */
        "movl 0x240(%eax), %eax\n" /* line 3328 */
        "movl %eax, 0x34(%esi)\n" /* weapDef */
        "movl $0, 0x38(%esi)\n" /* line 3329 | weapDef */
        "andl $0xffffffef, 0xc(%esi)\n" /* line 3330 | weapDef */
        "movl $0x95, 4(%esp)\n" /* line 1484 */
        "movl %esi, (%esp)\n"
        "calll PM_AddEvent\n"
        "andl $0xffffffbf, 0xc(%esi)\n" /* line 1485 */
        "cmpl $5, 4(%esi)\n" /* line 485 */
        "jg .Lf7d332_0007f4f0\n"
        "movl 0x5d0(%esi), %eax\n" /* line 488 */
        "andl $0x200, %eax\n"
        "xorb $2, %ah\n"
        "orl $0x11, %eax\n"
        "movl %eax, 0x5d0(%esi)\n"
        "movl -0x54(%ebp), %ecx\n" /* pm */
        "movl (%ecx), %esi\n"
        "movl 0xd8(%esi), %edx\n"
        "jmp .Lf7d332_0007d7fd\n"
        /* } scope */
        /* } scope */
        /* { scope 2: weapCount */
        /* { scope 3 */
        ".Lf7d332_0007f4e9:\n"
        "movl %ecx, %eax\n" /* line 773 */
        "jmp .Lf7d332_0007f401\n"
        ".Lf7d332_0007f4f0:\n"
        "movl -0x54(%ebp), %edx\n" /* pm */
        "movl (%edx), %esi\n"
        "movl 0xd8(%esi), %edx\n"
        "jmp .Lf7d332_0007d7fd\n"
        /* } scope */
        /* { scope 3 */
        ".Lf7d332_0007f500:\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7d332_0007f094\n"
        ".Lf7d332_0007f50a:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7d332_0007f094\n"
        /* } scope */
        ".Lf7d332_0007f517:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 3668 | pm */
        "movl (%ecx), %ebx\n" /* weapDef */
        "movl $0x16, 0xd8(%ebx)\n" /* line 3671 | weapDef */
        "andl $0xfffdffff, 0xc(%ebx)\n" /* line 3575 | offHandIndex */
        "movl $0xa9, 4(%esp)\n" /* line 3576 */
        "movl %ebx, (%esp)\n" /* offHandIndex */
        "calll PM_AddEvent\n"
        "movl -0x54(%ebp), %eax\n" /* line 3675 | pm */
        "cmpb $0, 0xc(%eax)\n"
        "jne .Lf7d332_0007effd\n"
        "movl $0, 0x34(%ebx)\n" /* line 3677 | weapDef */
        "movl $1, 0x38(%ebx)\n" /* line 3678 | weapDef */
        "movl (%eax), %esi\n" /* weapDef */
        "jmp .Lf7d332_0007d6f9\n"
    );
}

/* line 732 */
__attribute__((naked))
int BG_GetWeaponIndexForName(const char *name, BG_RegisterWeapon regWeap)
{
    __asm__ __volatile__ (
        ".Lf7f560_0007f560:\n"
        "pushl %ebp\n" /* line 732 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "cmpb $0, (%edi)\n" /* line 737 | name */
        "jne .Lf7f560_0007f57d\n"
        ".Lf7f560_0007f571:\n"
        "xorl %esi, %esi\n" /* line 450 */
        /* } scope */
        ".Lf7f560_0007f573:\n"
        "movl %esi, %eax\n" /* line 752 | weapIndex */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7f560_0007f57d:\n"
        "movl $0x218298, 4(%esp)\n" /* line 737 */
        "movl %edi, (%esp)\n" /* name */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf7f560_0007f571\n"
        "movl bg_iNumWeapons, %eax\n" /* line 717 */
        "testl %eax, %eax\n"
        "jg .Lf7f560_0007f6d1\n"
        ".Lf7f560_0007f59e:\n"
        "cmpb $0, (%edi)\n" /* line 4903 | name */
        "je .Lf7f560_0007f6b5\n"
        "movl %edi, 4(%esp)\n" /* line 4905 | name */
        "movl $0x21cc10, (%esp)\n" /* "mp" */
        "calll BG_LoadWeaponDefInternal\n"
        "movl %eax, %ebx\n" /* weapDef */
        "testl %eax, %eax\n" /* line 4906 */
        "je .Lf7f560_0007f683\n"
        ".Lf7f560_0007f5c1:\n"
        "movl bg_iNumWeapons, %esi\n" /* line 435 */
        "addl $1, %esi\n"
        "movl %esi, bg_iNumWeapons\n"
        "movl %ebx, bg_weaponDefs(, %esi, 4)\n" /* line 438 | weapDef */
        "movl %esi, %eax\n" /* line 418 */
        "calll BG_SetupAmmoIndexes\n"
        "movl %esi, %eax\n" /* line 419 */
        "calll BG_SetupSharedAmmoIndexes\n"
        "movl %esi, %eax\n" /* line 420 */
        "calll BG_SetupClipIndexes\n"
        /* { scope 2 */
        "movl bg_weaponDefs(, %esi, 4), %ebx\n" /* line 521 | weapDef */
        "leal (%esi, %esi, 4), %eax\n" /* line 101 */
        "leal (%esi, %eax, 2), %eax\n"
        "movl 0x195eda8, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x98(%ebx), %edx\n" /* line 104 | weapDef */
        "movl %edx, 4(%eax)\n"
        "movl 0x1b4(%ebx), %edx\n" /* line 105 | weapDef */
        "movl %edx, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n" /* line 106 */
        "movl 0x1b8(%ebx), %edx\n" /* line 107 | weapDef */
        "movl %edx, 0x10(%eax)\n"
        "movl 4(%ebx), %edx\n" /* line 108 | weapDef */
        "movl %edx, 0x14(%eax)\n"
        "movl 0x1c0(%ebx), %edx\n" /* line 109 | weapDef */
        "movl %edx, 0x18(%eax)\n"
        "movl $1, 0x1c(%eax)\n" /* line 110 */
        "movl %esi, 0x20(%eax)\n" /* line 112 */
        "movl 0x1c8(%ebx), %edx\n" /* line 113 | weapDef */
        "movl %edx, 0x24(%eax)\n"
        "movl 0x1d0(%ebx), %edx\n" /* line 114 | weapDef */
        "movl %edx, 0x28(%eax)\n"
        /* } scope */
        /* { scope 2 */
        "movl $0, 0x36c(%ebx)\n" /* line 344 | weapDef */
        "movl 0x368(%ebx), %eax\n" /* line 346 | weapDef */
        "cmpb $0, (%eax)\n"
        "jne .Lf7f560_0007f711\n"
        /* } scope */
        ".Lf7f560_0007f668:\n"
        "movl 0xc(%ebp), %eax\n" /* line 449 | regWeap */
        "testl %eax, %eax\n"
        "je .Lf7f560_0007f573\n"
        "movl %esi, (%esp)\n" /* line 450 */
        "calll *0xc(%ebp)\n" /* regWeap */
        /* } scope */
        "movl %esi, %eax\n" /* line 752 | weapIndex */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7f560_0007f683:\n"
        "movl $0x21ca4c, 4(%esp)\n" /* line 4909 */
        "movl $0x21cc10, (%esp)\n" /* "mp" */
        "calll BG_LoadWeaponDefInternal\n"
        "movl %eax, %ebx\n" /* weapDef */
        "testl %eax, %eax\n" /* line 4910 */
        "je .Lf7f560_0007f7c1\n"
        ".Lf7f560_0007f6a1:\n"
        "movl %edi, 4(%esp)\n" /* line 4912 | name */
        "movl %ebx, (%esp)\n" /* weapDef */
        "calll SetConfigString\n"
        "testl %ebx, %ebx\n" /* line 745 | weapDef */
        "jne .Lf7f560_0007f5c1\n"
        ".Lf7f560_0007f6b5:\n"
        "movl %edi, 4(%esp)\n" /* line 747 | name */
        "movl $0x21cc14, (%esp)\n" /* "Couldn't find weapon "%s"
" */
        "calll Com_DPrintf\n"
        "xorl %esi, %esi\n" /* weapIndex */
        /* } scope */
        "movl %esi, %eax\n" /* line 752 | weapIndex */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7f560_0007f6d1:\n"
        "movl $1, %esi\n" /* line 717 */
        "movl $bg_weaponDefs, %ebx\n" /* weapDef */
        "jmp .Lf7f560_0007f6ef\n"
        ".Lf7f560_0007f6dd:\n"
        "addl $1, %esi\n"
        "addl $4, %ebx\n" /* weapDef */
        "cmpl bg_iNumWeapons, %esi\n"
        "jg .Lf7f560_0007f59e\n"
        ".Lf7f560_0007f6ef:\n"
        "movl 4(%ebx), %eax\n" /* line 719 | weapDef */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* altWeapDef */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf7f560_0007f6dd\n"
        "testl %esi, %esi\n" /* line 741 | weapIndex */
        "je .Lf7f560_0007f59e\n"
        "jmp .Lf7f560_0007f573\n"
        /* { scope 2 */
        ".Lf7f560_0007f711:\n"
        "movl 0xc(%ebp), %edx\n" /* line 349 | regWeap */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponIndexForName\n"
        "movl %eax, %edi\n" /* altWeapDef */
        "testl %eax, %eax\n" /* line 351 */
        "je .Lf7f560_0007f798\n"
        ".Lf7f560_0007f726:\n"
        "movl %edi, 0x36c(%ebx)\n" /* line 354 | altWeapDef, weapDef */
        "movl bg_weaponDefs(, %edi, 4), %edi\n" /* line 356 | altWeapDef */
        "movl 0x80(%ebx), %eax\n" /* line 359 | weapDef */
        "cmpl 0x80(%edi), %eax\n" /* altWeapDef */
        "je .Lf7f560_0007f761\n"
        "movl (%edi), %eax\n" /* line 360 | altWeapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl (%ebx), %eax\n" /* weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $0x21cc60, 4(%esp)\n" /* "weapon '%s' does not have same weaponSlot setting as its al" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf7f560_0007f761:\n"
        "movl 0x88(%ebx), %eax\n" /* line 363 | weapDef */
        "cmpl 0x88(%edi), %eax\n" /* altWeapDef */
        "je .Lf7f560_0007f668\n"
        "movl (%edi), %eax\n" /* line 364 | altWeapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl (%ebx), %eax\n" /* weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $0x21ccac, 4(%esp)\n" /* "weapon '%s' does not have same slotStackable setting as its" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7f560_0007f668\n"
        ".Lf7f560_0007f798:\n"
        "movl (%ebx), %eax\n" /* line 352 | weapDef */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x368(%ebx), %eax\n" /* weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $0x21cc30, 4(%esp)\n" /* "could not find altWeapon '%s' for weapon '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7f560_0007f726\n"
        /* } scope */
        ".Lf7f560_0007f7c1:\n"
        "movl $0x21ca60, 4(%esp)\n" /* line 4911 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7f560_0007f6a1\n"
    );
}

/* line 123 */
__attribute__((naked))
void BG_FillInAmmoItems(BG_RegisterWeapon regWeap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 123 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl 0x195edac, %eax\n" /* line 133 */
        "cmpl $0x81, (%eax)\n"
        "jle .Lf7f7da_0007f8d5\n"
        "movl $0x81, %edi\n" /* i */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0x195eda8, %ebx\n"
        "addl $0x162c, %ebx\n"
        "jmp .Lf7f7da_0007f818\n"
        ".Lf7f7da_0007f80a:\n"
        "addl $1, %edi\n" /* i */
        "addl $0x2c, %ebx\n"
        "cmpl (%eax), %edi\n" /* i */
        "jge .Lf7f7da_0007f8d5\n"
        ".Lf7f7da_0007f818:\n"
        "cmpl $2, 0x1c(%ebx)\n" /* line 136 */
        "jne .Lf7f7da_0007f80a\n"
        "movl $0x40, 8(%esp)\n" /* line 139 */
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movzbl -0x58(%ebp), %eax\n" /* line 141 | name */
        "testb %al, %al\n"
        "je .Lf7f7da_0007f85c\n"
        "cmpb $0x20, %al\n" /* line 143 */
        "je .Lf7f7da_0007f8f3\n"
        "leal -0x58(%ebp), %edx\n" /* name */
        ".Lf7f7da_0007f84b:\n"
        "addl $1, %edx\n" /* line 141 */
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf7f7da_0007f85c\n"
        "cmpb $0x20, %al\n" /* line 143 */
        "jne .Lf7f7da_0007f84b\n"
        "movb $0, (%edx)\n" /* line 145 */
        ".Lf7f7da_0007f85c:\n"
        "movl 8(%ebp), %eax\n" /* line 149 | regWeap */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponIndexForName\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 150 */
        "jne .Lf7f7da_0007f8fe\n"
        "movl 0x14(%ebx), %eax\n" /* line 160 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21ccfc, (%esp)\n" /* "^3WARNING^7: Could not find weapon for ammo item %s
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %eax\n" /* line 162 | regWeap */
        "movl %eax, 4(%esp)\n"
        "movl $0x21ca4c, (%esp)\n" /* "defaultweapon_mp" */
        "calll BG_GetWeaponIndexForName\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 163 */
        "je .Lf7f7da_0007f8dd\n"
        ".Lf7f7da_0007f8a4:\n"
        "movl bg_weaponDefs(, %esi, 4), %eax\n" /* line 521 */
        "movl $1, 0x20(%ebx)\n" /* line 167 */
        "movl 0x1c8(%eax), %edx\n" /* line 168 */
        "movl %edx, 0x24(%ebx)\n"
        "movl 0x1d0(%eax), %eax\n" /* line 169 */
        "movl %eax, 0x28(%ebx)\n"
        "movl -0x5c(%ebp), %eax\n"
        "addl $1, %edi\n" /* line 133 | i */
        "addl $0x2c, %ebx\n"
        "cmpl (%eax), %edi\n" /* i */
        "jl .Lf7f7da_0007f818\n"
        /* } scope */
        ".Lf7f7da_0007f8d5:\n"
        "addl $0x6c, %esp\n" /* line 171 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7f7da_0007f8dd:\n"
        "movl $0x21cd34, 4(%esp)\n" /* line 164 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7f7da_0007f8a4\n"
        ".Lf7f7da_0007f8f3:\n"
        "leal -0x58(%ebp), %edx\n" /* line 143 | name */
        "movb $0, (%edx)\n" /* line 145 */
        "jmp .Lf7f7da_0007f85c\n"
        ".Lf7f7da_0007f8fe:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "movl %edx, 0x20(%ebx)\n" /* line 153 */
        "movl 0x1c8(%eax), %edx\n" /* line 154 */
        "movl %edx, 0x24(%ebx)\n"
        "movl 0x1d0(%eax), %eax\n" /* line 155 */
        "movl %eax, 0x28(%ebx)\n"
        "jmp .Lf7f7da_0007f8d5\n"
    );
}

/* line 532 */
__attribute__((naked))
void CG_SetWeaponDefToDefaultWeapon(int iWeapon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 532 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* iWeapon */
        /* { scope 1 */
        "movl $0, 4(%esp)\n" /* line 762 */
        "movl $0x21ca4c, (%esp)\n" /* "defaultweapon_mp" */
        "calll BG_GetWeaponIndexForName\n"
        "movl %eax, %ebx\n" /* defaultWeaponNum */
        "testl %eax, %eax\n" /* line 540 */
        "je .Lf7f91c_0007f990\n"
        ".Lf7f91c_0007f941:\n"
        "movl bg_weaponDefs(, %esi, 4), %edx\n" /* line 543 */
        "movl bg_weaponDefs(, %ebx, 4), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl bg_weaponDefs(, %esi, 4), %edx\n" /* line 544 */
        "movl bg_weaponDefs(, %ebx, 4), %eax\n"
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "xorl %ecx, %ecx\n"
        ".Lf7f91c_0007f96b:\n"
        "movl bg_weaponDefs(, %esi, 4), %eax\n" /* line 547 */
        "movl bg_weaponDefs(, %ebx, 4), %edx\n"
        "movl 0x14(%edx, %ecx, 4), %edx\n"
        "movl %edx, 0x14(%eax, %ecx, 4)\n"
        "addl $1, %ecx\n" /* line 546 */
        "cmpl $0x17, %ecx\n"
        "jne .Lf7f91c_0007f96b\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 548 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7f91c_0007f990:\n"
        "movl $0x21cd7c, 4(%esp)\n" /* line 541 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf7f91c_0007f941\n"
    );
}

/* line 4563 */
__attribute__((naked))
void BG_CalculateWeaponAngles(weaponState_t *ws, vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4563 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        /* { scope 1: fTimeStep, fGunKickAccel */
        "movl 8(%ebp), %edx\n" /* line 4568 | ws */
        "movl (%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* line 183 | angles */
        "movl $0, (%ecx)\n"
        "addl $4, %ecx\n" /* line 184 */
        "movl %ecx, -0x58(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* angles */
        "movl $0, 4(%edi)\n"
        "addl $8, %edi\n" /* line 185 */
        "movl %edi, -0x5c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* angles */
        "movl $0, 8(%edx)\n"
        "movss 0x4c(%eax), %xmm0\n" /* line 4573 */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf7f9a6_000807e7\n"
        "jne .Lf7f9a6_000807e7\n"
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_0007f9f8:\n"
        "movl 8(%ebp), %edx\n" /* line 4233 | ws */
        "movl (%edx), %esi\n"
        "movl 0xc(%esi), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf7f9a6_0007fb59\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jg .Lf7f9a6_0007fb73\n"
        ".Lf7f9a6_0007fa19:\n"
        "xorl %eax, %eax\n" /* line 797 */
        ".Lf7f9a6_0007fa1b:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "movl 0x32c(%eax), %edx\n" /* line 4238 */
        "testl %edx, %edx\n"
        "je .Lf7f9a6_0007fa4c\n"
        "movss 0xdc(%esi), %xmm0\n" /* line 4241 */
        "mulss 0x46c(%eax), %xmm0\n"
        "movl 0xc(%ebp), %ecx\n" /* angles */
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movl 8(%ebp), %edi\n" /* ws */
        "movl (%edi), %esi\n"
        /* { scope 3 */
        ".Lf7f9a6_0007fa4c:\n"
        "movl 0xc(%esi), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf7f9a6_0007fbad\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jle .Lf7f9a6_000807d9\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7f9a6_000809af\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7f9a6_0007fa81:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jl .Lf7f9a6_000807d9\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7f9a6_0007fa81\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        /* { scope 4 */
        "movl bg_weaponDefs(, %eax, 4), %ebx\n" /* line 521 */
        /* } scope */
        "movl 0xa0(%esi), %edx\n" /* line 4149 */
        "movl %edx, %eax\n"
        "shrl $3, %eax\n"
        "andb $1, %al\n"
        "je .Lf7f9a6_0007fbd5\n"
        ".Lf7f9a6_0007fab7:\n"
        "movss 0x1b0(%ebx), %xmm1\n" /* line 4150 | weapDef */
        "movl 8(%ebp), %ecx\n" /* line 4157 | ws */
        "movss 4(%ecx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf7f9a6_0007fbf7\n"
        ".Lf7f9a6_0007fad0:\n"
        "cmpl $5, 0xd8(%esi)\n"
        "je .Lf7f9a6_0007fbf7\n"
        "movaps %xmm0, %xmm2\n" /* line 4159 */
        "subss %xmm1, %xmm2\n"
        "cvtsi2ssl 0x50(%esi), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf7f9a6_00080a9c\n"
        "pxor %xmm2, %xmm2\n"
        "movss 0x2ed5dc, %xmm1\n" /* -1.0f */
        ".Lf7f9a6_0007fb12:\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm2, %xmm3\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm3\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "testb %al, %al\n" /* line 4162 */
        "jne .Lf7f9a6_00080938\n"
        "andb $4, %dl\n" /* line 4164 */
        "je .Lf7f9a6_00080a86\n"
        "leal 0x15c(%ebx), %eax\n" /* weapDef */
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss 0x15c(%ebx), %xmm0\n"
        "jmp .Lf7f9a6_00080949\n"
        /* } scope */
        /* } scope */
        ".Lf7f9a6_0007fb59:\n"
        "testb $0x10, %al\n" /* line 790 */
        "jne .Lf7f9a6_0007fb68\n"
        "movl 0xd4(%esi), %eax\n" /* line 797 */
        "jmp .Lf7f9a6_0007fa1b\n"
        ".Lf7f9a6_0007fb68:\n"
        "movl 0xd0(%esi), %eax\n" /* line 792 */
        "jmp .Lf7f9a6_0007fa1b\n"
        ".Lf7f9a6_0007fb73:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7f9a6_000809c9\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7f9a6_0007fb8c:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jl .Lf7f9a6_0007fa19\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7f9a6_0007fb8c\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_0007fa1b\n"
        /* { scope 3 */
        ".Lf7f9a6_0007fbad:\n"
        "testb $0x10, %al\n" /* line 790 */
        "je .Lf7f9a6_0008088c\n"
        "movl 0xd0(%esi), %eax\n" /* line 792 */
        /* { scope 4 */
        ".Lf7f9a6_0007fbbb:\n"
        "movl bg_weaponDefs(, %eax, 4), %ebx\n" /* line 521 */
        /* } scope */
        "movl 0xa0(%esi), %edx\n" /* line 4149 */
        "movl %edx, %eax\n"
        "shrl $3, %eax\n"
        "andb $1, %al\n"
        "jne .Lf7f9a6_0007fab7\n"
        ".Lf7f9a6_0007fbd5:\n"
        "testb $4, %dl\n" /* line 4151 */
        "je .Lf7f9a6_0008087f\n"
        "movss 0x1ac(%ebx), %xmm1\n" /* line 4152 | weapDef */
        ".Lf7f9a6_0007fbe6:\n"
        "movl 8(%ebp), %ecx\n" /* line 4157 | ws */
        "movss 4(%ecx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf7f9a6_0007fad0\n"
        ".Lf7f9a6_0007fbf7:\n"
        "movl $0, -0x24(%ebp)\n" /* line 183 | vTargetAng */
        "movl $0, -0x20(%ebp)\n" /* line 184 */
        "movl $0, -0x1c(%ebp)\n" /* line 185 */
        ".Lf7f9a6_0007fc0c:\n"
        "movss 0xdc(%esi), %xmm1\n" /* line 4174 */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lf7f9a6_0007fc1f\n"
        "je .Lf7f9a6_0007fc4f\n"
        ".Lf7f9a6_0007fc1f:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 4176 | 1.0f */
        "subss %xmm1, %xmm0\n"
        /* { scope 4 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm1\n" /* vTargetAng */
        "movss %xmm1, -0x24(%ebp)\n" /* vTargetAng */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x1c(%ebp)\n"
        ".Lf7f9a6_0007fc4f:\n"
        "movl 8(%ebp), %eax\n" /* ws */
        "movl $1, %ecx\n"
        "movss 0x2ed7d0, %xmm6\n" /* 0.10000000149011612f */
        "movss 0x2ed7d4, %xmm5\n" /* -0.10000000149011612f */
        "movss 0x2ed7bc, %xmm4\n" /* 11.0f */
        ".Lf7f9a6_0007fc6f:\n"
        "leal 0xc(%eax), %edx\n" /* line 4563 */
        /* } scope */
        "movss 0xc(%eax), %xmm3\n" /* line 4182 */
        "movss -0x28(%ebp, %ecx, 4), %xmm2\n"
        "ucomiss %xmm2, %xmm3\n"
        "jp .Lf7f9a6_0007fc84\n"
        "je .Lf7f9a6_0007fcdc\n"
        ".Lf7f9a6_0007fc84:\n"
        "movss 0xf8(%esi), %xmm0\n" /* line 4185 */
        "ucomiss %xmm4, %xmm0\n"
        "jne .Lf7f9a6_0007fe66\n"
        "jp .Lf7f9a6_0007fe66\n"
        "movaps %xmm2, %xmm1\n" /* line 4186 */
        "subss %xmm3, %xmm1\n"
        "movl 8(%ebp), %edi\n" /* ws */
        "mulss 8(%edi), %xmm1\n"
        "mulss 0x1a4(%ebx), %xmm1\n" /* weapDef */
        ".Lf7f9a6_0007fcb2:\n"
        "ucomiss %xmm3, %xmm2\n" /* line 4190 */
        "jbe .Lf7f9a6_0007fe45\n"
        "movl 8(%ebp), %edi\n" /* line 4192 | ws */
        "movss 8(%edi), %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "maxss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n" /* line 4195 */
        "movss %xmm0, (%edx)\n"
        "ucomiss %xmm2, %xmm0\n" /* line 4196 */
        "ja .Lf7f9a6_0007fe5d\n"
        ".Lf7f9a6_0007fcdc:\n"
        "addl $1, %ecx\n" /* line 4206 */
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 4180 */
        "jne .Lf7f9a6_0007fc6f\n"
        "movss 0xdc(%esi), %xmm1\n" /* line 4210 */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lf7f9a6_0007fcfe\n"
        "je .Lf7f9a6_0007fe82\n"
        ".Lf7f9a6_0007fcfe:\n"
        "ucomiss 0x2ed5d8, %xmm1\n" /* line 4213 | 0.5f */
        "jae .Lf7f9a6_0007fd5c\n"
        "jp .Lf7f9a6_0007fd5c\n"
        "mulss 0x2ed628, %xmm1\n" /* line 4215 | -2.0f */
        "addss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movl 8(%ebp), %eax\n" /* ws */
        "addl $0xc, %eax\n"
        /* { scope 4 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "movl 8(%ebp), %edx\n" /* ws */
        "mulss 0xc(%edx), %xmm0\n"
        "movl 0xc(%ebp), %ecx\n" /* angles */
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%ecx), %xmm0\n"
        "movl -0x58(%ebp), %edi\n"
        "movss %xmm0, (%edi)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%ecx), %xmm1\n"
        "movl -0x5c(%ebp), %eax\n"
        "movss %xmm1, (%eax)\n"
        "movl (%edx), %esi\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_0007fd5c:\n"
        "movl 0xc(%esi), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "jne .Lf7f9a6_0007fecd\n"
        ".Lf7f9a6_0007fd6a:\n"
        "testb $0x10, %al\n" /* line 790 */
        "je .Lf7f9a6_000808be\n"
        "movl 0xd0(%esi), %eax\n" /* line 792 */
        ".Lf7f9a6_0007fd78:\n"
        "movl bg_weaponDefs(, %eax, 4), %edx\n" /* line 521 */
        "movl 0x32c(%edx), %eax\n" /* line 4266 */
        "testl %eax, %eax\n"
        "jne .Lf7f9a6_0007ff25\n"
        ".Lf7f9a6_0007fd8d:\n"
        "movss 0x2cc(%edx), %xmm5\n" /* line 4271 */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm5\n"
        "jne .Lf7f9a6_000808a2\n"
        "jp .Lf7f9a6_000808a2\n"
        "movss 0x2ed7d8, %xmm5\n" /* 80.0f */
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        ".Lf7f9a6_0007fdb8:\n"
        "movl 0xa0(%esi), %eax\n" /* line 4283 */
        "testb $8, %al\n"
        "jne .Lf7f9a6_0007ff73\n"
        ".Lf7f9a6_0007fdc6:\n"
        "testb $4, %al\n" /* line 4285 */
        "jne .Lf7f9a6_00080854\n"
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        ".Lf7f9a6_0007fdd6:\n"
        "movl 0x278(%edx), %edi\n" /* line 4290 */
        "testl %edi, %edi\n"
        "je .Lf7f9a6_0007fdf7\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss 0xdc(%esi), %xmm1\n"
        "jne .Lf7f9a6_000808af\n"
        "jp .Lf7f9a6_000808af\n"
        ".Lf7f9a6_0007fdf7:\n"
        "movl 8(%ebp), %eax\n" /* line 4293 | ws */
        "movss 0x18(%eax), %xmm2\n"
        "ucomiss %xmm2, %xmm4\n"
        "jp .Lf7f9a6_0007fe0a\n"
        "je .Lf7f9a6_0007ff80\n"
        ".Lf7f9a6_0007fe0a:\n"
        "ucomiss %xmm2, %xmm4\n" /* line 4295 */
        "ja .Lf7f9a6_00080909\n"
        "movl 8(%ebp), %ecx\n" /* line 4303 | ws */
        "movss 8(%ecx), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, 0x18(%ecx)\n"
        "ucomiss %xmm2, %xmm4\n" /* line 4304 */
        "jbe .Lf7f9a6_000809f0\n"
        "movss %xmm4, 0x18(%ecx)\n" /* line 4305 */
        "movl 8(%ebp), %ecx\n" /* ws */
        "jmp .Lf7f9a6_0007ff87\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        /* { scope 3 */
        ".Lf7f9a6_0007fe45:\n"
        "movl 8(%ebp), %edi\n" /* line 4201 | ws */
        "movss 8(%edi), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "minss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n" /* line 4204 */
        "maxss %xmm0, %xmm2\n" /* line 4206 */
        ".Lf7f9a6_0007fe5d:\n"
        "movss %xmm2, (%edx)\n"
        "jmp .Lf7f9a6_0007fcdc\n"
        ".Lf7f9a6_0007fe66:\n"
        "movaps %xmm2, %xmm1\n" /* line 4188 */
        "subss %xmm3, %xmm1\n"
        "movl 8(%ebp), %edi\n" /* ws */
        "mulss 8(%edi), %xmm1\n"
        "mulss 0x1a0(%ebx), %xmm1\n" /* weapDef */
        "jmp .Lf7f9a6_0007fcb2\n"
        /* { scope 4 */
        ".Lf7f9a6_0007fe82:\n"
        "movl 8(%ebp), %eax\n" /* line 290 | ws */
        "addl $0xc, %eax\n"
        /* } scope */
        /* { scope 4 */
        "movl 0xc(%ebp), %edx\n" /* line 240 | angles */
        "movss (%edx), %xmm0\n"
        "movl 8(%ebp), %ecx\n" /* ws */
        "addss 0xc(%ecx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss 4(%edx), %xmm0\n" /* line 241 */
        "addss 4(%eax), %xmm0\n"
        "movl -0x58(%ebp), %edi\n"
        "movss %xmm0, (%edi)\n"
        "movss 8(%edx), %xmm0\n" /* line 242 */
        "addss 8(%eax), %xmm0\n"
        "movl -0x5c(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "movl (%ecx), %esi\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        "movl 0xc(%esi), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf7f9a6_0007fd6a\n"
        ".Lf7f9a6_0007fecd:\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jle .Lf7f9a6_000807d2\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7f9a6_000809bc\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7f9a6_0007fef4:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ebx, %ecx\n"
        "jg .Lf7f9a6_000807d2\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7f9a6_0007fef4\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "movl bg_weaponDefs(, %eax, 4), %edx\n" /* line 521 */
        "movl 0x32c(%edx), %eax\n" /* line 4266 */
        "testl %eax, %eax\n"
        "je .Lf7f9a6_0007fd8d\n"
        ".Lf7f9a6_0007ff25:\n"
        "movss 0xdc(%esi), %xmm0\n" /* line 4268 */
        "movss 0x2cc(%edx), %xmm1\n"
        "movss 0x2c8(%edx), %xmm5\n"
        "subss %xmm1, %xmm5\n"
        "mulss %xmm0, %xmm5\n"
        "addss %xmm1, %xmm5\n"
        "movss 0x2d4(%edx), %xmm1\n" /* line 4269 */
        "movss 0x2d0(%edx), %xmm3\n"
        "subss %xmm1, %xmm3\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm1, %xmm3\n"
        "movl 0xa0(%esi), %eax\n" /* line 4283 */
        "testb $8, %al\n"
        "je .Lf7f9a6_0007fdc6\n"
        ".Lf7f9a6_0007ff73:\n"
        "movss 0x2dc(%edx), %xmm4\n" /* line 4284 */
        "jmp .Lf7f9a6_0007fdd6\n"
        ".Lf7f9a6_0007ff80:\n"
        "movss 8(%eax), %xmm1\n"
        "movl %eax, %ecx\n"
        ".Lf7f9a6_0007ff87:\n"
        "mulss 0x18(%ecx), %xmm5\n" /* line 4310 */
        "movss %xmm5, -0x2c(%ebp)\n"
        "movl 0x278(%edx), %ebx\n" /* line 4312 | weapDef */
        "testl %ebx, %ebx\n" /* weapDef */
        "je .Lf7f9a6_000800e1\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 4313 | 1.0f */
        "subss 0xdc(%esi), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* ws */
        ".Lf7f9a6_0007ffbb:\n"
        "movl 0x50(%edi), %edx\n" /* line 4315 */
        "mulss 0x2ed5c8, %xmm1\n" /* 1000.0f */
        "mulss %xmm1, %xmm3\n"
        "cvttss2si %xmm3, %eax\n"
        "addl %eax, (%edx)\n"
        "movl 0x50(%edi), %eax\n" /* line 4317 */
        "cvtsi2ssl (%eax), %xmm0\n"
        "mulss 0x2ed618, %xmm0\n" /* 0.0005000000237487257f */
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "mulss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "movl -0x5c(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 0x50(%edi), %eax\n" /* line 4320 */
        "cvtsi2ssl (%eax), %xmm0\n"
        "mulss 0x2ed7dc, %xmm0\n" /* 0.000699999975040555f */
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "mulss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "movl -0x58(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl 0x50(%edi), %eax\n" /* line 4323 */
        "cvtsi2ssl (%eax), %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x48(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss -0x48(%ebp), %xmm0\n"
        "movss 0x2ed738, %xmm1\n" /* 0.009999999776482582f */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* angles */
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        "movl (%edi), %ebx\n" /* line 4345 | ps */
        "movl 0xc(%ebx), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf7f9a6_000800e8\n"
        "movl bg_iNumWeapons, %esi\n" /* line 771 */
        "testl %esi, %esi\n"
        "jle .Lf7f9a6_000807cb\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7f9a6_000809e3\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7f9a6_000800c3:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %esi\n"
        "jl .Lf7f9a6_000807cb\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7f9a6_000800c3\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_000800f6\n"
        ".Lf7f9a6_000800e1:\n"
        "movl %ecx, %edi\n"
        "jmp .Lf7f9a6_0007ffbb\n"
        ".Lf7f9a6_000800e8:\n"
        "testb $0x10, %al\n" /* line 790 */
        "je .Lf7f9a6_00080861\n"
        "movl 0xd0(%ebx), %eax\n" /* line 792 */
        /* { scope 3 */
        ".Lf7f9a6_000800f6:\n"
        "movl bg_weaponDefs(, %eax, 4), %esi\n" /* line 521 */
        /* } scope */
        "movzbl 8(%ebx), %eax\n" /* line 4351 | ps */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "addsd %xmm0, %xmm0\n"
        "movsd 0x307c98, %xmm1\n" /* 6.283185307179586 */
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd 0x307ca8, %xmm0\n" /* 0.7853981633974483 */
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* cycle */
        "movss 0x2ed7e0, %xmm0\n" /* line 4352 | 0.1599999964237213f */
        "movss %xmm0, -0x44(%ebp)\n" /* speed */
        "movl 8(%ebp), %eax\n" /* ws */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n" /* speed */
        /* { scope 3 */
        "movl 0xf4(%ebx), %eax\n" /* line 4092 */
        "cmpl $0xb, %eax\n"
        "je .Lf7f9a6_00080843\n"
        "cmpl $0x28, %eax\n" /* line 4094 */
        "je .Lf7f9a6_000808f3\n"
        "movl 0x195ee3c, %eax\n" /* line 4097 */
        "movl (%eax), %eax\n"
        "movss -0x44(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        ".Lf7f9a6_00080189:\n"
        "movss 0x2ed6b4, %xmm1\n" /* line 4099 | 10.0f */
        "movaps %xmm1, %xmm2\n"
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        /* } scope */
        "movss -0x40(%ebp), %xmm0\n" /* line 4102 | cycle */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm1\n"
        "movss -0x40(%ebp), %xmm0\n" /* cycle */
        "mulss 0x2ed608, %xmm0\n" /* 4.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd 0x307ca0, %xmm0\n" /* 1.5707963267948966 */
        "movsd %xmm0, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll sin\n"
        "fstpl -0x50(%ebp)\n"
        "cvtsd2ss -0x50(%ebp), %xmm0\n"
        "mulss 0x2ed724, %xmm0\n" /* 0.20000000298023224f */
        "movss -0x78(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "mulss 0x2ed67c, %xmm1\n" /* 0.75f */
        "mulss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "xorl $0x80000000, -0x30(%ebp)\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl 0xf4(%ebx), %eax\n" /* line 4117 */
        "cmpl $0xb, %eax\n"
        "je .Lf7f9a6_0008082d\n"
        "cmpl $0x28, %eax\n" /* line 4119 */
        "je .Lf7f9a6_000808dd\n"
        "movl 0x195ee3c, %eax\n" /* line 4122 */
        "movl (%eax), %eax\n"
        "movss -0x44(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        ".Lf7f9a6_0008024b:\n"
        "movss 0x2ed6b4, %xmm4\n" /* line 4124 | 10.0f */
        "movaps %xmm4, %xmm3\n"
        "cmpltss %xmm0, %xmm4\n"
        "andps %xmm4, %xmm3\n"
        "andnps %xmm0, %xmm4\n"
        "orps %xmm3, %xmm4\n"
        /* } scope */
        /* } scope */
        "movss -0x40(%ebp), %xmm0\n" /* line 4127 | cycle */
        "movss %xmm0, (%esp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "calll sinf\n"
        "fstps -0x54(%ebp)\n"
        "movss -0x98(%ebp), %xmm4\n"
        "mulss -0x54(%ebp), %xmm4\n"
        "xorps 0x2f0a70, %xmm4\n"
        "cvtss2sd -0x40(%ebp), %xmm0\n" /* line 4356 | cycle */
        "subsd 0x307cb0, %xmm0\n" /* 0.4712389167638204 */
        "cvtsd2ss %xmm0, %xmm2\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 4357 | speed */
        "mulss 0x2ed600, %xmm0\n" /* 1.5f */
        /* { scope 3 */
        /* { scope 4 */
        "movl 0xf4(%ebx), %eax\n" /* line 4117 */
        "cmpl $0xb, %eax\n"
        "je .Lf7f9a6_00080819\n"
        "cmpl $0x28, %eax\n" /* line 4119 */
        "je .Lf7f9a6_000808c9\n"
        "movl 0x195ee3c, %eax\n" /* line 4122 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        ".Lf7f9a6_000802d7:\n"
        "movss 0x2ed6b4, %xmm0\n" /* line 4124 | 10.0f */
        "movaps %xmm0, %xmm3\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movss %xmm2, (%esp)\n" /* line 4127 */
        "movss %xmm1, -0x78(%ebp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "calll sinf\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm2\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        /* } scope */
        /* } scope */
        "pxor %xmm0, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm2, %xmm1\n"
        "cmpnltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss 0xdc(%ebx), %xmm3\n" /* line 4360 | ps */
        "movss -0x98(%ebp), %xmm4\n" /* line 4363 */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm3\n"
        "jp .Lf7f9a6_0008035c\n"
        "je .Lf7f9a6_0008038d\n"
        ".Lf7f9a6_0008035c:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 4365 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss 0x284(%esi), %xmm1\n" /* weapDef */
        "mulss %xmm3, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 4366 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "mulss %xmm0, %xmm4\n" /* line 4367 */
        "mulss %xmm0, %xmm2\n" /* line 4368 */
        ".Lf7f9a6_0008038d:\n"
        "movl 0x278(%esi), %edx\n" /* line 4371 | weapDef */
        "testl %edx, %edx\n"
        "je .Lf7f9a6_00080781\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 4372 | 1.0f, scale */
        "subss %xmm3, %xmm0\n" /* scale */
        /* { scope 3 */
        "movss -0x30(%ebp), %xmm3\n" /* line 272 */
        "mulss %xmm0, %xmm3\n"
        "movss %xmm3, -0x30(%ebp)\n"
        "mulss %xmm0, %xmm4\n" /* line 273 */
        "mulss %xmm0, %xmm2\n" /* line 274 */
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        ".Lf7f9a6_000803c0:\n"
        "movl 0xc(%ebp), %eax\n" /* line 240 | angles */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addss 4(%eax), %xmm4\n" /* line 241 */
        "movl -0x58(%ebp), %eax\n"
        "movss %xmm4, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 242 | angles */
        "addss 8(%edx), %xmm2\n"
        "movl -0x5c(%ebp), %ecx\n"
        "movss %xmm2, (%ecx)\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        "movl 8(%ebp), %eax\n" /* line 4389 | ws */
        "movl 0x20(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf7f9a6_00080532\n"
        "movl (%eax), %esi\n" /* line 4392 | weapDef */
        "movl 0xc(%esi), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf7f9a6_0008086c\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jg .Lf7f9a6_00080975\n"
        ".Lf7f9a6_00080412:\n"
        "xorl %eax, %eax\n" /* line 797 */
        /* { scope 3 */
        ".Lf7f9a6_00080414:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        /* } scope */
        "movss 0xdc(%esi), %xmm1\n" /* line 4397 | weapDef */
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movaps %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm3\n" /* line 4398 */
        "mulss 0x2ed798, %xmm3\n" /* 100.0f */
        "movaps %xmm2, %xmm4\n" /* line 4399 */
        "mulss 0x2ed730, %xmm4\n" /* 400.0f */
        "pxor %xmm0, %xmm0\n" /* line 4400 */
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lf7f9a6_00080457\n"
        "je .Lf7f9a6_00080475\n"
        ".Lf7f9a6_00080457:\n"
        "movl 0x278(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7f9a6_00080475\n"
        "mulss 0x2ed6c4, %xmm1\n" /* line 4401 | -0.75f */
        "addss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "mulss %xmm1, %xmm2\n"
        ".Lf7f9a6_00080475:\n"
        "movl 8(%ebp), %edx\n" /* line 4403 | ws */
        "movl 0x1c(%edx), %eax\n"
        "subl %edi, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "ucomiss %xmm0, %xmm3\n" /* line 4404 */
        "ja .Lf7f9a6_000809f8\n"
        "subss %xmm3, %xmm0\n" /* line 4416 */
        "divss %xmm4, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 4417 */
        "ucomiss %xmm3, %xmm1\n"
        "jbe .Lf7f9a6_00080534\n"
        "movss 0x2ed5d0, %xmm4\n" /* line 4419 | 1.0f */
        "subss %xmm1, %xmm4\n"
        "movss %xmm4, (%esp)\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "calll GetLeanFraction\n"
        "fstps -0x3c(%ebp)\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss -0x3c(%ebp), %xmm1\n"
        "movss -0x88(%ebp), %xmm2\n" /* line 4420 */
        "mulss %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 4422 */
        "movl 8(%ebp), %eax\n" /* ws */
        "mulss 0x24(%eax), %xmm0\n"
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm0\n"
        "movl 0xc(%ebp), %edx\n" /* angles */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movaps %xmm1, %xmm2\n" /* line 4423 */
        "mulss 0x28(%eax), %xmm2\n"
        "movl -0x58(%ebp), %ecx\n"
        "movss (%ecx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "mulss 0x28(%eax), %xmm1\n" /* line 4424 */
        "mulss %xmm3, %xmm1\n"
        "movl -0x5c(%ebp), %edi\n"
        "addss (%edi), %xmm1\n"
        "movss %xmm1, (%edi)\n"
        ".Lf7f9a6_00080532:\n"
        "movl (%eax), %esi\n" /* weapDef */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_00080534:\n"
        "movl 0xc(%esi), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "jne .Lf7f9a6_0008078b\n"
        "testb $0x10, %al\n" /* line 790 */
        "je .Lf7f9a6_00080897\n"
        "movl 0xd0(%esi), %eax\n" /* line 792 */
        ".Lf7f9a6_00080550:\n"
        "movl bg_weaponDefs(, %eax, 4), %ebx\n" /* line 521 */
        "movl 0x32c(%ebx), %eax\n" /* line 4520 | weapDef */
        "testl %eax, %eax\n"
        "je .Lf7f9a6_00080741\n"
        "movss 0xdc(%esi), %xmm1\n" /* line 4523 | bCanStop */
        "movss 0x4d8(%ebx), %xmm0\n" /* line 4526 | weapDef */
        "movss 0x490(%ebx), %xmm2\n" /* weapDef */
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* fGunKickAccel */
        "movss 0x4dc(%ebx), %xmm0\n" /* line 4527 | weapDef */
        "movss 0x494(%ebx), %xmm7\n" /* weapDef */
        "subss %xmm0, %xmm7\n"
        "mulss %xmm1, %xmm7\n"
        "addss %xmm0, %xmm7\n"
        "movss 0x4e0(%ebx), %xmm0\n" /* line 4528 | weapDef */
        "movss 0x498(%ebx), %xmm6\n" /* weapDef */
        "subss %xmm0, %xmm6\n"
        "mulss %xmm1, %xmm6\n"
        "addss %xmm0, %xmm6\n"
        "movss 0x4e4(%ebx), %xmm0\n" /* line 4529 | weapDef */
        "movss 0x49c(%ebx), %xmm5\n" /* weapDef */
        "subss %xmm0, %xmm5\n"
        "mulss %xmm1, %xmm5\n"
        "addss %xmm0, %xmm5\n"
        "movl 8(%ebp), %eax\n" /* line 4532 | ws */
        "movss 8(%eax), %xmm4\n"
        "pxor %xmm0, %xmm0\n" /* line 4533 */
        "ucomiss %xmm0, %xmm4\n"
        "jbe .Lf7f9a6_00080a7c\n"
        "movl %eax, %edx\n"
        "addl $0x38, %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "leal 0x2c(%edx), %edi\n"
        "leal 0x3c(%edx), %ecx\n"
        "movl %ecx, -0x68(%ebp)\n"
        "leal 0x30(%edx), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "jmp .Lf7f9a6_000806f0\n"
        ".Lf7f9a6_00080613:\n"
        "subsd 0x307cb8, %xmm0\n" /* line 4539 | 0.005 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n" /* fTimeStep */
        "movss 0x2ed7e4, %xmm4\n" /* 0.004999999888241291f */
        ".Lf7f9a6_0008062c:\n"
        "movss 0x2e0(%ebx), %xmm1\n" /* line 4548 | weapDef */
        "movss %xmm5, 4(%esp)\n"
        "movss %xmm6, (%esp)\n"
        "movaps %xmm7, %xmm3\n"
        "movss -0x34(%ebp), %xmm2\n" /* fGunKickAccel */
        "movaps %xmm4, %xmm0\n"
        "movl -0x64(%ebp), %edx\n"
        "movl %edi, %eax\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "movss %xmm5, -0xa8(%ebp)\n"
        "movss %xmm6, -0xb8(%ebp)\n"
        "movss %xmm7, -0xc8(%ebp)\n"
        "calll BG_CalculateWeaponPosition_GunRecoil_SingleAngle\n"
        "movl %eax, %esi\n" /* bCanStop */
        "movss 0x2e4(%ebx), %xmm1\n" /* line 4549 | weapDef */
        "movss -0xa8(%ebp), %xmm5\n"
        "movss %xmm5, 4(%esp)\n"
        "movss -0xb8(%ebp), %xmm6\n"
        "movss %xmm6, (%esp)\n"
        "movss -0xc8(%ebp), %xmm7\n"
        "movaps %xmm7, %xmm3\n"
        "movss -0x34(%ebp), %xmm2\n" /* fGunKickAccel */
        "movss -0x98(%ebp), %xmm4\n"
        "movaps %xmm4, %xmm0\n"
        "movl -0x68(%ebp), %edx\n"
        "movl -0x60(%ebp), %eax\n"
        "calll BG_CalculateWeaponPosition_GunRecoil_SingleAngle\n"
        "testl %eax, %eax\n"
        "movss -0xa8(%ebp), %xmm5\n"
        "movss -0xb8(%ebp), %xmm6\n"
        "movss -0xc8(%ebp), %xmm7\n"
        "je .Lf7f9a6_000806df\n"
        "testl %esi, %esi\n" /* bCanStop */
        "jne .Lf7f9a6_0008070e\n"
        ".Lf7f9a6_000806df:\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 4533 | fTimeStep */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf7f9a6_0008070e\n"
        "movaps %xmm0, %xmm4\n"
        ".Lf7f9a6_000806f0:\n"
        "cvtss2sd %xmm4, %xmm0\n" /* line 4536 */
        "ucomisd 0x307cb8, %xmm0\n" /* 0.005 */
        "ja .Lf7f9a6_00080613\n"
        "movl $0, -0x38(%ebp)\n" /* fTimeStep */
        "jmp .Lf7f9a6_0008062c\n"
        ".Lf7f9a6_0008070e:\n"
        "movl 8(%ebp), %ecx\n" /* ws */
        ".Lf7f9a6_00080711:\n"
        "movl 0xc(%ebp), %edx\n" /* line 240 | angles */
        "movss (%edx), %xmm0\n"
        "addss 0x2c(%ecx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl -0x58(%ebp), %eax\n" /* line 241 */
        "movss (%eax), %xmm0\n"
        "addss 4(%edi), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl -0x5c(%ebp), %edx\n" /* line 242 */
        "movss (%edx), %xmm0\n"
        "addss 8(%edi), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        /* } scope */
        ".Lf7f9a6_00080741:\n"
        "movl 8(%ebp), %ecx\n" /* line 4589 | ws */
        "movl 0x44(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edi\n" /* angles */
        "movl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps (%edi)\n"
        "movl 8(%ebp), %edx\n" /* line 4590 | ws */
        "movl 0x48(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x58(%ebp), %ecx\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "movl -0x58(%ebp), %edi\n"
        "fstps (%edi)\n"
        /* } scope */
        "addl $0xdc, %esp\n" /* line 4591 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf7f9a6_00080781:\n"
        "movss -0x30(%ebp), %xmm0\n"
        "jmp .Lf7f9a6_000803c0\n"
        /* { scope 1: fTimeStep, fGunKickAccel */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_0008078b:\n"
        "movl bg_iNumWeapons, %ebx\n" /* line 771 */
        "testl %ebx, %ebx\n"
        "jle .Lf7f9a6_000807e0\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7f9a6_000809d6\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7f9a6_000807ae:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jl .Lf7f9a6_000807e0\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7f9a6_000807ae\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_00080550\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000807cb:\n"
        "xorl %eax, %eax\n" /* line 797 */
        "jmp .Lf7f9a6_000800f6\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000807d2:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf7f9a6_0007fd78\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        /* { scope 3 */
        ".Lf7f9a6_000807d9:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf7f9a6_0007fbbb\n"
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000807e0:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf7f9a6_00080550\n"
        /* } scope */
        ".Lf7f9a6_000807e7:\n"
        "movss %xmm0, (%esp)\n" /* line 4575 */
        "calll GetLeanFraction\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm0\n"
        "mulss 0x2ed628, %xmm0\n" /* line 4576 | -2.0f */
        "movl 0xc(%ebp), %eax\n" /* angles */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "jmp .Lf7f9a6_0007f9f8\n"
        /* { scope 2: vTargetAng, speed, cycle */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf7f9a6_00080819:\n"
        "movl 0x195ee28, %eax\n" /* line 4118 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "jmp .Lf7f9a6_000802d7\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf7f9a6_0008082d:\n"
        "movl 0x195ee28, %eax\n"
        "movl (%eax), %eax\n"
        "movss -0x44(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf7f9a6_0008024b\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf7f9a6_00080843:\n"
        "movl 0x195ee28, %eax\n" /* line 4093 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf7f9a6_00080189\n"
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_00080854:\n"
        "movss 0x2d8(%edx), %xmm4\n" /* line 4286 */
        "jmp .Lf7f9a6_0007fdd6\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_00080861:\n"
        "movl 0xd4(%ebx), %eax\n" /* line 797 */
        "jmp .Lf7f9a6_000800f6\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_0008086c:\n"
        "testb $0x10, %al\n" /* line 790 */
        "jne .Lf7f9a6_0008096a\n"
        "movl 0xd4(%esi), %eax\n" /* line 797 */
        "jmp .Lf7f9a6_00080414\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        /* { scope 3 */
        ".Lf7f9a6_0008087f:\n"
        "movss 0x1a8(%ebx), %xmm1\n" /* line 4154 | weapDef */
        "jmp .Lf7f9a6_0007fbe6\n"
        ".Lf7f9a6_0008088c:\n"
        "movl 0xd4(%esi), %eax\n" /* line 797 */
        "jmp .Lf7f9a6_0007fbbb\n"
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_00080897:\n"
        "movl 0xd4(%esi), %eax\n"
        "jmp .Lf7f9a6_00080550\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000808a2:\n"
        "movss 0x2d4(%edx), %xmm3\n" /* line 4274 */
        "jmp .Lf7f9a6_0007fdb8\n"
        ".Lf7f9a6_000808af:\n"
        "movl 8(%ebp), %edi\n" /* ws */
        "movss 8(%edi), %xmm1\n"
        "movl %edi, %ecx\n"
        "jmp .Lf7f9a6_0007ff87\n"
        ".Lf7f9a6_000808be:\n"
        "movl 0xd4(%esi), %eax\n" /* line 797 */
        "jmp .Lf7f9a6_0007fd78\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf7f9a6_000808c9:\n"
        "movl 0x195ee34, %eax\n" /* line 4120 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "jmp .Lf7f9a6_000802d7\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf7f9a6_000808dd:\n"
        "movl 0x195ee34, %eax\n"
        "movl (%eax), %eax\n"
        "movss -0x44(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf7f9a6_0008024b\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf7f9a6_000808f3:\n"
        "movl 0x195ee34, %eax\n" /* line 4095 */
        "movl (%eax), %eax\n"
        "movss -0x44(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf7f9a6_00080189\n"
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_00080909:\n"
        "movss 8(%eax), %xmm1\n" /* line 4297 */
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x18(%eax)\n"
        "ucomiss %xmm4, %xmm0\n" /* line 4298 */
        "jbe .Lf7f9a6_000809f0\n"
        "movss %xmm4, 0x18(%eax)\n" /* line 4299 */
        "movl 8(%ebp), %ecx\n" /* ws */
        "jmp .Lf7f9a6_0007ff87\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        /* { scope 3 */
        ".Lf7f9a6_00080938:\n"
        "leal 0x180(%ebx), %eax\n" /* line 4162 | weapDef */
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss 0x180(%ebx), %xmm0\n"
        /* } scope */
        /* { scope 4 */
        ".Lf7f9a6_00080949:\n"
        "movss %xmm0, -0x24(%ebp)\n" /* vTargetAng */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm2\n" /* line 274 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "jmp .Lf7f9a6_0007fc0c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_0008096a:\n"
        "movl 0xd0(%esi), %eax\n" /* line 792 */
        "jmp .Lf7f9a6_00080414\n"
        ".Lf7f9a6_00080975:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf7f9a6_00080aac\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf7f9a6_0008098e:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %ebx\n"
        "jl .Lf7f9a6_00080412\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf7f9a6_0008098e\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_00080414\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        /* { scope 3 */
        ".Lf7f9a6_000809af:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_0007fbbb\n"
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000809bc:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_0007fd78\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000809c9:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_0007fa1b\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000809d6:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_00080550\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000809e3:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_000800f6\n"
        ".Lf7f9a6_000809f0:\n"
        "movl 8(%ebp), %ecx\n" /* ws */
        "jmp .Lf7f9a6_0007ff87\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_000809f8:\n"
        "divss %xmm3, %xmm0\n" /* line 4406 */
        "movss %xmm0, (%esp)\n" /* line 4407 */
        "movss %xmm2, -0x88(%ebp)\n"
        "calll GetLeanFraction\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm1\n"
        "movss -0x88(%ebp), %xmm2\n" /* line 4408 */
        "mulss %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 4410 */
        "movl 8(%ebp), %ecx\n" /* ws */
        "mulss 0x24(%ecx), %xmm0\n"
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm0\n"
        "movl 0xc(%ebp), %edi\n" /* angles */
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm1, %xmm2\n" /* line 4411 */
        "mulss 0x28(%ecx), %xmm2\n"
        "movl -0x58(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "mulss 0x28(%ecx), %xmm1\n" /* line 4412 */
        "mulss %xmm3, %xmm1\n"
        "movl -0x5c(%ebp), %edx\n"
        "addss (%edx), %xmm1\n"
        "movss %xmm1, (%edx)\n"
        "movl (%ecx), %esi\n" /* weapDef */
        "jmp .Lf7f9a6_00080534\n"
        ".Lf7f9a6_00080a7c:\n"
        "leal 0x2c(%eax), %edi\n"
        "movl %eax, %ecx\n"
        "jmp .Lf7f9a6_00080711\n"
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf7f9a6_00080a86:\n"
        "leal 0x138(%ebx), %eax\n" /* line 274 */
        /* } scope */
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss 0x138(%ebx), %xmm0\n"
        "jmp .Lf7f9a6_00080949\n"
        /* } scope */
        ".Lf7f9a6_00080a9c:\n"
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "subss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "jmp .Lf7f9a6_0007fb12\n"
        /* } scope */
        /* } scope */
        /* { scope 2: vTargetAng, speed, cycle */
        ".Lf7f9a6_00080aac:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf7f9a6_00080414\n"
    );
}

/* line 4797 */
__attribute__((naked))
void BG_CalculateViewAngles(viewState_t *vs, vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4797 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "pxor %xmm5, %xmm5\n" /* line 183 */
        "movl 0xc(%ebp), %eax\n" /* angles */
        "movss %xmm5, (%eax)\n"
        "addl $4, %eax\n" /* line 184 */
        "movl %eax, -0x40(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* angles */
        "movss %xmm5, 4(%edx)\n"
        "addl $8, %edx\n" /* line 185 */
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* angles */
        "movss %xmm5, 8(%eax)\n"
        /* { scope 1: speed, cycle, cycle */
        "movl 8(%ebp), %edx\n" /* line 4603 | vs */
        "movl 4(%edx), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf80aba_00080bf8\n"
        "movl (%edx), %ebx\n" /* line 4606 */
        "movl 0xc(%ebx), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf80aba_00080def\n"
        "movl bg_iNumWeapons, %esi\n" /* line 771 */
        "testl %esi, %esi\n"
        "jg .Lf80aba_00081431\n"
        ".Lf80aba_00080b19:\n"
        "xorl %eax, %eax\n" /* line 797 */
        /* { scope 2 */
        ".Lf80aba_00080b1b:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        /* } scope */
        "movss 0xdc(%ebx), %xmm0\n" /* line 4611 */
        "movaps %xmm0, %xmm1\n"
        "mulss 0x2ed63c, %xmm1\n" /* -0.5f */
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n" /* fFactor */
        "ucomiss %xmm5, %xmm0\n" /* line 4612 */
        "jp .Lf80aba_00080b4d\n"
        "je .Lf80aba_00080b6c\n"
        ".Lf80aba_00080b4d:\n"
        "movl 0x278(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf80aba_00080b6c\n"
        "mulss 0x2ed5d8, %xmm0\n" /* line 4613 | 0.5f */
        "addss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* fFactor */
        ".Lf80aba_00080b6c:\n"
        "movl 8(%ebp), %edx\n" /* line 4615 | vs */
        "movl 8(%edx), %eax\n"
        "subl %edi, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed798, %xmm1\n" /* line 4616 | 100.0f */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf80aba_00081500\n"
        "subss %xmm1, %xmm0\n" /* line 4627 */
        "divss 0x2ed6d8, %xmm0\n" /* -400.0f */
        "addss %xmm2, %xmm0\n"
        "ucomiss %xmm5, %xmm0\n" /* line 4628 */
        "jbe .Lf80aba_00080bfa\n"
        "movaps %xmm2, %xmm1\n" /* line 4630 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "calll GetLeanFraction\n"
        "fstps -0x38(%ebp)\n"
        "movss -0x88(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "subss -0x38(%ebp), %xmm0\n"
        "mulss -0x34(%ebp), %xmm0\n" /* line 4631 | fFactor */
        "movaps %xmm0, %xmm1\n" /* line 4633 */
        "movl 8(%ebp), %eax\n" /* vs */
        "mulss 0xc(%eax), %xmm1\n"
        "movl 0xc(%ebp), %edx\n" /* angles */
        "addss (%edx), %xmm1\n"
        "movss %xmm1, (%edx)\n"
        "mulss 0x10(%eax), %xmm0\n" /* line 4634 */
        "movl -0x3c(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* vs */
        ".Lf80aba_00080bf8:\n"
        "movl (%edx), %ebx\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00080bfa:\n"
        "movl 0xc(%ebx), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "jne .Lf80aba_00080c14\n"
        "testb $0x10, %al\n" /* line 790 */
        "jne .Lf80aba_00080de4\n"
        "movl 0xd4(%ebx), %eax\n" /* line 797 */
        "jmp .Lf80aba_00080c24\n"
        ".Lf80aba_00080c14:\n"
        "movl bg_iNumWeapons, %esi\n" /* line 771 */
        "testl %esi, %esi\n"
        "jg .Lf80aba_00080e02\n"
        ".Lf80aba_00080c22:\n"
        "xorl %eax, %eax\n" /* line 797 */
        ".Lf80aba_00080c24:\n"
        "movl bg_weaponDefs(, %eax, 4), %eax\n" /* line 521 */
        "movl 0x278(%eax), %edi\n" /* line 4656 */
        "testl %edi, %edi\n"
        "je .Lf80aba_00080d91\n"
        "movl 0x32c(%eax), %esi\n" /* line 4659 */
        "testl %esi, %esi\n"
        "je .Lf80aba_000813ec\n"
        "movss 0xdc(%ebx), %xmm0\n" /* line 4661 */
        "movss 0x2cc(%eax), %xmm1\n"
        "movss 0x2c8(%eax), %xmm3\n"
        "subss %xmm1, %xmm3\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm1, %xmm3\n"
        "movss 0x2d4(%eax), %xmm1\n" /* line 4662 */
        "movss 0x2d0(%eax), %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "pxor %xmm5, %xmm5\n"
        ".Lf80aba_00080c8b:\n"
        "movl 0xa0(%ebx), %edx\n" /* line 4676 */
        "testb $8, %dl\n"
        "je .Lf80aba_000813d6\n"
        "movss 0x2dc(%eax), %xmm4\n" /* line 4677 */
        ".Lf80aba_00080ca2:\n"
        "ucomiss 0xdc(%ebx), %xmm5\n" /* line 4683 */
        "jp .Lf80aba_00080cb1\n"
        "je .Lf80aba_000813b5\n"
        ".Lf80aba_00080cb1:\n"
        "movl 8(%ebp), %edx\n" /* line 4686 | vs */
        "movss 0x1c(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm4\n"
        "jp .Lf80aba_0008146b\n"
        "jne .Lf80aba_0008146b\n"
        ".Lf80aba_00080cc8:\n"
        "movaps %xmm3, %xmm1\n" /* line 4703 */
        "mulss 0x1c(%edx), %xmm1\n"
        "mulss 0xdc(%ebx), %xmm1\n" /* line 4704 */
        "movss 0x5b4(%ebx), %xmm0\n" /* line 4705 */
        "mulss %xmm0, %xmm1\n"
        "movl %edx, %eax\n" /* line 4707 */
        "movl 0x20(%edx), %edx\n"
        "mulss 0x18(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "mulss %xmm0, %xmm2\n"
        "cvttss2si %xmm2, %eax\n"
        "addl %eax, (%edx)\n"
        "movl 8(%ebp), %edx\n" /* line 4709 | vs */
        "movl 0x20(%edx), %eax\n"
        "cvtsi2ssl (%eax), %xmm0\n"
        "mulss 0x2ed7dc, %xmm0\n" /* 0.000699999975040555f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll sinf\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "mulss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "movl -0x40(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 4712 | vs */
        "movl 0x20(%edx), %eax\n"
        "cvtsi2ssl (%eax), %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll sinf\n"
        "fstps -0x44(%ebp)\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss -0x44(%ebp), %xmm1\n"
        "mulss 0x2ed738, %xmm1\n" /* 0.009999999776482582f */
        "movl 0xc(%ebp), %eax\n" /* angles */
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* vs */
        "movl (%edx), %ebx\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00080d91:\n"
        "movl 0xc(%ebx), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf80aba_00080e3c\n"
        "movl bg_iNumWeapons, %esi\n" /* line 771 */
        "testl %esi, %esi\n"
        "jle .Lf80aba_000813bd\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf80aba_000814c5\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf80aba_00080dc6:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %esi\n"
        "jl .Lf80aba_000813bd\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf80aba_00080dc6\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf80aba_00080e4a\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00080de4:\n"
        "movl 0xd0(%ebx), %eax\n" /* line 792 */
        "jmp .Lf80aba_00080c24\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00080def:\n"
        "testb $0x10, %al\n" /* line 790 */
        "jne .Lf80aba_000814a0\n"
        "movl 0xd4(%ebx), %eax\n" /* line 797 */
        "jmp .Lf80aba_00080b1b\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00080e02:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf80aba_000814d2\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf80aba_00080e1b:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %esi\n"
        "jl .Lf80aba_00080c22\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf80aba_00080e1b\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf80aba_00080c24\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00080e3c:\n"
        "testb $0x10, %al\n" /* line 790 */
        "je .Lf80aba_0008141c\n"
        "movl 0xd0(%ebx), %eax\n" /* line 792 */
        /* { scope 2 */
        ".Lf80aba_00080e4a:\n"
        "movl bg_weaponDefs(, %eax, 4), %esi\n" /* line 521 */
        /* } scope */
        "movl 0x278(%esi), %ecx\n" /* line 4733 | weapDef */
        "testl %ecx, %ecx\n"
        "je .Lf80aba_0008112a\n"
        "movzbl 8(%ebx), %eax\n" /* line 4737 */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "addsd %xmm0, %xmm0\n"
        "movsd 0x307c98, %xmm1\n" /* 6.283185307179586 */
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd 0x307ca8, %xmm0\n" /* 0.7853981633974483 */
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* cycle */
        "movss 0x2ed7e0, %xmm0\n" /* line 4738 | 0.1599999964237213f */
        "movss %xmm0, -0x30(%ebp)\n" /* speed */
        "movl 8(%ebp), %eax\n" /* vs */
        "mulss 0x14(%eax), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* speed */
        /* { scope 2 */
        "movl 0xf4(%ebx), %eax\n" /* line 4092 */
        "cmpl $0xb, %eax\n"
        "je .Lf80aba_0008157b\n"
        "cmpl $0x28, %eax\n" /* line 4094 */
        "je .Lf80aba_0008158c\n"
        "movl 0x195ee3c, %eax\n" /* line 4097 */
        "movl (%eax), %eax\n"
        "movss -0x30(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        ".Lf80aba_00080eeb:\n"
        "movss 0x2ed6b4, %xmm1\n" /* line 4099 | 10.0f */
        "movaps %xmm1, %xmm2\n"
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movss -0x2c(%ebp), %xmm0\n" /* line 4102 | cycle */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm1\n"
        "movss -0x2c(%ebp), %xmm0\n" /* cycle */
        "mulss 0x2ed608, %xmm0\n" /* 4.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd 0x307ca0, %xmm0\n" /* 1.5707963267948966 */
        "movsd %xmm0, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll sin\n"
        "fstpl -0x50(%ebp)\n"
        "cvtsd2ss -0x50(%ebp), %xmm0\n"
        "mulss 0x2ed724, %xmm0\n" /* 0.20000000298023224f */
        "movss -0x78(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "mulss 0x2ed67c, %xmm1\n" /* 0.75f */
        "mulss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "xorl $0x80000000, -0x1c(%ebp)\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xf4(%ebx), %eax\n" /* line 4117 */
        "cmpl $0xb, %eax\n"
        "je .Lf80aba_00081565\n"
        "cmpl $0x28, %eax\n" /* line 4119 */
        "je .Lf80aba_000815b6\n"
        "movl 0x195ee3c, %eax\n" /* line 4122 */
        "movl (%eax), %eax\n"
        "movss -0x30(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        ".Lf80aba_00080fad:\n"
        "movss 0x2ed6b4, %xmm4\n" /* line 4124 | 10.0f */
        "movaps %xmm4, %xmm3\n"
        "cmpltss %xmm0, %xmm4\n"
        "andps %xmm4, %xmm3\n"
        "andnps %xmm0, %xmm4\n"
        "orps %xmm3, %xmm4\n"
        /* } scope */
        /* } scope */
        "movss -0x2c(%ebp), %xmm0\n" /* line 4127 | cycle */
        "movss %xmm0, (%esp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "calll sinf\n"
        "fstps -0x54(%ebp)\n"
        "movss -0x98(%ebp), %xmm4\n"
        "mulss -0x54(%ebp), %xmm4\n"
        "xorps 0x2f0a80, %xmm4\n"
        "cvtss2sd -0x2c(%ebp), %xmm0\n" /* line 4742 | cycle */
        "subsd 0x307cb0, %xmm0\n" /* 0.4712389167638204 */
        "cvtsd2ss %xmm0, %xmm2\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 4743 | speed */
        "mulss 0x2ed600, %xmm0\n" /* 1.5f */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xf4(%ebx), %eax\n" /* line 4117 */
        "cmpl $0xb, %eax\n"
        "je .Lf80aba_00081551\n"
        "cmpl $0x28, %eax\n" /* line 4119 */
        "je .Lf80aba_000815a2\n"
        "movl 0x195ee3c, %eax\n" /* line 4122 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        ".Lf80aba_00081039:\n"
        "movss 0x2ed6b4, %xmm0\n" /* line 4124 | 10.0f */
        "movaps %xmm0, %xmm3\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movss %xmm2, (%esp)\n" /* line 4127 */
        "movss %xmm1, -0x78(%ebp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "calll sinf\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm3\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm3\n"
        /* } scope */
        /* } scope */
        "pxor %xmm0, %xmm0\n" /* line 45 */
        "movaps %xmm0, %xmm1\n"
        "subss %xmm3, %xmm1\n"
        "movaps %xmm3, %xmm2\n"
        "cmpnltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm3\n"
        "movss 0xdc(%ebx), %xmm2\n" /* line 4746 */
        "movss -0x98(%ebp), %xmm4\n" /* line 4749 */
        "ucomiss %xmm0, %xmm2\n"
        "jp .Lf80aba_000810bd\n"
        "je .Lf80aba_00081427\n"
        ".Lf80aba_000810bd:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 4751 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss 0x284(%esi), %xmm1\n" /* weapDef */
        "mulss %xmm2, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 4752 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "mulss %xmm0, %xmm4\n" /* line 4753 */
        "mulss %xmm0, %xmm3\n" /* line 4754 */
        "movaps %xmm1, %xmm0\n"
        ".Lf80aba_000810f1:\n"
        "mulss %xmm2, %xmm0\n" /* line 240 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* angles */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "mulss %xmm2, %xmm4\n" /* line 241 */
        "addss 4(%eax), %xmm4\n"
        "movl -0x40(%ebp), %edx\n"
        "movss %xmm4, (%edx)\n"
        "mulss %xmm3, %xmm2\n" /* line 242 */
        "addss 8(%eax), %xmm2\n"
        "movl -0x3c(%ebp), %eax\n"
        "movss %xmm2, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* vs */
        "movl (%edx), %ebx\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_0008112a:\n"
        "movl 0xc(%ebx), %eax\n" /* line 785 */
        "testl $0x20000, %eax\n"
        "je .Lf80aba_00081195\n"
        "movl bg_iNumWeapons, %esi\n" /* line 771 */
        "testl %esi, %esi\n"
        "jle .Lf80aba_000813c4\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf80aba_000814df\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf80aba_0008115b:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %esi, %ecx\n"
        "jg .Lf80aba_000813c4\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf80aba_0008115b\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        /* { scope 2 */
        "movl bg_weaponDefs(, %eax, 4), %esi\n" /* line 521 */
        /* } scope */
        "testl $0x300, 0xa0(%ebx)\n" /* line 4777 */
        "je .Lf80aba_000811b6\n"
        /* } scope */
        ".Lf80aba_0008118a:\n"
        "addl $0xac, %esp\n" /* line 4805 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00081195:\n"
        "testb $0x10, %al\n" /* line 790 */
        "je .Lf80aba_000813cb\n"
        "movl 0xd0(%ebx), %eax\n" /* line 792 */
        /* { scope 2 */
        ".Lf80aba_000811a3:\n"
        "movl bg_weaponDefs(, %eax, 4), %esi\n" /* line 521 */
        /* } scope */
        "testl $0x300, 0xa0(%ebx)\n" /* line 4777 */
        "jne .Lf80aba_0008118a\n"
        ".Lf80aba_000811b6:\n"
        "movss 0xdc(%ebx), %xmm0\n" /* line 4781 */
        "movss %xmm0, -0x28(%ebp)\n"
        "pxor %xmm0, %xmm0\n"
        "movss -0x28(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lf80aba_000811d3\n"
        "je .Lf80aba_0008118a\n"
        ".Lf80aba_000811d3:\n"
        "movss 0x288(%esi), %xmm2\n" /* weapDef */
        "movss %xmm2, -0x24(%ebp)\n"
        "ucomiss %xmm0, %xmm2\n"
        "jp .Lf80aba_000811e7\n"
        "je .Lf80aba_0008118a\n"
        ".Lf80aba_000811e7:\n"
        "movzbl 8(%ebx), %eax\n" /* line 4783 */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "addsd %xmm0, %xmm0\n"
        "addsd 0x307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* cycle */
        "movl 8(%ebp), %eax\n" /* line 4785 | vs */
        "movss 0x14(%eax), %xmm0\n" /* speed */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xf4(%ebx), %eax\n" /* line 4092 */
        "cmpl $0xb, %eax\n"
        "je .Lf80aba_000815cc\n"
        "cmpl $0x28, %eax\n" /* line 4094 */
        "je .Lf80aba_000814ec\n"
        "movl 0x195ee3c, %eax\n" /* line 4097 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        ".Lf80aba_00081247:\n"
        "movss 0x2ed6ec, %xmm0\n" /* line 4099 | 45.0f */
        "movaps %xmm0, %xmm1\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 4102 | cycle */
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "calll sinf\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm1\n"
        "movss -0x20(%ebp), %xmm0\n" /* cycle */
        "mulss 0x2ed608, %xmm0\n" /* 4.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd 0x307ca0, %xmm0\n" /* 1.5707963267948966 */
        "movsd %xmm0, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll sin\n"
        "fstpl -0x60(%ebp)\n"
        "cvtsd2ss -0x60(%ebp), %xmm0\n"
        "mulss 0x2ed724, %xmm0\n" /* 0.20000000298023224f */
        "movss -0x78(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "mulss 0x2ed67c, %xmm1\n" /* 0.75f */
        "movss -0x88(%ebp), %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        /* } scope */
        /* } scope */
        "movss -0x28(%ebp), %xmm3\n" /* line 4787 */
        "mulss -0x24(%ebp), %xmm3\n"
        "mulss %xmm3, %xmm2\n"
        "movl 0xc(%ebp), %eax\n" /* angles */
        "movss (%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 4789 | vs */
        "movss 0x14(%edx), %xmm0\n" /* speed */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xf4(%ebx), %eax\n" /* line 4117 */
        "cmpl $0xb, %eax\n"
        "je .Lf80aba_000815e0\n"
        "cmpl $0x28, %eax\n" /* line 4119 */
        "je .Lf80aba_000815f4\n"
        "movl 0x195ee3c, %eax\n" /* line 4122 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        ".Lf80aba_0008132d:\n"
        "movss 0x2ed6ec, %xmm0\n" /* line 4124 | 45.0f */
        "movaps %xmm0, %xmm2\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movss -0x20(%ebp), %xmm3\n" /* line 4127 | cycle */
        "movss %xmm3, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll sinf\n"
        "fstps -0x64(%ebp)\n"
        "movss -0x78(%ebp), %xmm1\n"
        "mulss -0x64(%ebp), %xmm1\n"
        /* } scope */
        /* } scope */
        "movss 0xdc(%ebx), %xmm0\n" /* line 4791 */
        "mulss 0x288(%esi), %xmm0\n" /* weapDef */
        "mulss %xmm0, %xmm1\n"
        "movl -0x40(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 4805 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00081398:\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 4696 | 0.5f */
        "movl 8(%ebp), %eax\n" /* vs */
        "mulss 0x18(%eax), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "maxss %xmm1, %xmm4\n" /* line 4698 */
        "movss %xmm4, 0x1c(%eax)\n"
        ".Lf80aba_000813b5:\n"
        "movl 8(%ebp), %edx\n" /* vs */
        "jmp .Lf80aba_00080cc8\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_000813bd:\n"
        "xorl %eax, %eax\n" /* line 797 */
        "jmp .Lf80aba_00080e4a\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_000813c4:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf80aba_000811a3\n"
        ".Lf80aba_000813cb:\n"
        "movl 0xd4(%ebx), %eax\n"
        "jmp .Lf80aba_000811a3\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_000813d6:\n"
        "andb $4, %dl\n" /* line 4678 */
        "je .Lf80aba_000814b8\n"
        "movss 0x2d8(%eax), %xmm4\n" /* line 4679 */
        "jmp .Lf80aba_00080ca2\n"
        ".Lf80aba_000813ec:\n"
        "movss 0x2cc(%eax), %xmm3\n" /* line 4664 */
        "pxor %xmm5, %xmm5\n"
        "ucomiss %xmm5, %xmm3\n"
        "jne .Lf80aba_000814ab\n"
        "jp .Lf80aba_000814ab\n"
        "movss 0x2ed7d8, %xmm3\n" /* 80.0f */
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "jmp .Lf80aba_00080c8b\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_0008141c:\n"
        "movl 0xd4(%ebx), %eax\n" /* line 797 */
        "jmp .Lf80aba_00080e4a\n"
        ".Lf80aba_00081427:\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "jmp .Lf80aba_000810f1\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00081431:\n"
        "movl 0x1007fa4, %eax\n" /* line 773 */
        "cmpl $3, 0x78(%eax)\n"
        "je .Lf80aba_00081608\n"
        "movl $1, %ecx\n"
        "movl $bg_weaponDefs, %edx\n"
        ".Lf80aba_0008144a:\n"
        "addl $1, %ecx\n" /* line 771 */
        "cmpl %ecx, %esi\n"
        "jl .Lf80aba_00080b19\n"
        "movl 8(%edx), %eax\n" /* line 773 */
        "addl $4, %edx\n"
        "cmpl $3, 0x78(%eax)\n"
        "jne .Lf80aba_0008144a\n"
        "movl %ecx, %eax\n"
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf80aba_00080b1b\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_0008146b:\n"
        "ucomiss %xmm1, %xmm4\n" /* line 4688 */
        "jbe .Lf80aba_00081398\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 4690 | 0.5f */
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x1c(%edx)\n"
        "ucomiss %xmm4, %xmm0\n" /* line 4691 */
        "jbe .Lf80aba_000813b5\n"
        "movss %xmm4, 0x1c(%edx)\n" /* line 4692 */
        "movl 8(%ebp), %edx\n" /* vs */
        "jmp .Lf80aba_00080cc8\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_000814a0:\n"
        "movl 0xd0(%ebx), %eax\n" /* line 792 */
        "jmp .Lf80aba_00080b1b\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_000814ab:\n"
        "movss 0x2d4(%eax), %xmm2\n" /* line 4667 */
        "jmp .Lf80aba_00080c8b\n"
        ".Lf80aba_000814b8:\n"
        "movss 0x2ed5d0, %xmm4\n" /* line 4678 | 1.0f */
        "jmp .Lf80aba_00080ca2\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_000814c5:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf80aba_00080e4a\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_000814d2:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf80aba_00080c24\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_000814df:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf80aba_000811a3\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf80aba_000814ec:\n"
        "movl 0x195ee34, %eax\n" /* line 4095 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "jmp .Lf80aba_00081247\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00081500:\n"
        "divss %xmm1, %xmm0\n" /* line 4618 */
        "movss %xmm0, (%esp)\n" /* line 4619 */
        "calll GetLeanFraction\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm1\n"
        "mulss -0x34(%ebp), %xmm1\n" /* line 4620 | fFactor */
        "movaps %xmm1, %xmm0\n" /* line 4622 */
        "movl 8(%ebp), %eax\n" /* vs */
        "mulss 0xc(%eax), %xmm0\n"
        "movl 0xc(%ebp), %edx\n" /* angles */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "mulss 0x10(%eax), %xmm1\n" /* line 4623 */
        "movl -0x3c(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* vs */
        "movl (%edx), %ebx\n"
        "jmp .Lf80aba_00080bfa\n"
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf80aba_00081551:\n"
        "movl 0x195ee28, %eax\n" /* line 4118 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "jmp .Lf80aba_00081039\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf80aba_00081565:\n"
        "movl 0x195ee28, %eax\n"
        "movl (%eax), %eax\n"
        "movss -0x30(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf80aba_00080fad\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf80aba_0008157b:\n"
        "movl 0x195ee28, %eax\n" /* line 4093 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf80aba_00080eeb\n"
        ".Lf80aba_0008158c:\n"
        "movl 0x195ee34, %eax\n" /* line 4095 */
        "movl (%eax), %eax\n"
        "movss -0x30(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf80aba_00080eeb\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf80aba_000815a2:\n"
        "movl 0x195ee34, %eax\n" /* line 4120 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "jmp .Lf80aba_00081039\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf80aba_000815b6:\n"
        "movl 0x195ee34, %eax\n"
        "movl (%eax), %eax\n"
        "movss -0x30(%ebp), %xmm0\n" /* speed */
        "mulss 8(%eax), %xmm0\n"
        "jmp .Lf80aba_00080fad\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf80aba_000815cc:\n"
        "movl 0x195ee28, %eax\n" /* line 4093 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "jmp .Lf80aba_00081247\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf80aba_000815e0:\n"
        "movl 0x195ee28, %eax\n" /* line 4118 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "jmp .Lf80aba_0008132d\n"
        ".Lf80aba_000815f4:\n"
        "movl 0x195ee34, %eax\n" /* line 4120 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "jmp .Lf80aba_0008132d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: speed, cycle, cycle */
        ".Lf80aba_00081608:\n"
        "movl $1, %eax\n" /* line 773 */
        "movzbl %al, %eax\n" /* line 774 */
        "jmp .Lf80aba_00080b1b\n"
    );
}

