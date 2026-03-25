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
static WeaponDef * bg_weapAmmoTypes[128]; /* bg_weapAmmoTypes */
static int bg_iNumAmmoTypes; /* bg_iNumAmmoTypes */
static WeaponDef * bg_sharedAmmoCaps[128]; /* bg_sharedAmmoCaps */
static int bg_iNumSharedAmmoCaps; /* bg_iNumSharedAmmoCaps */
static WeaponDef * bg_weapClips[128]; /* bg_weapClips */
static int bg_iNumWeapClips; /* bg_iNumWeapClips */

void BG_ShutdownWeaponDefFiles(void);
WeaponDef * BG_GetWeaponDef(int iWeapon);
extern void *BG_LoadDefaultWeaponDef(void);
extern void BG_LoadPlayerAnimTypes(void);
extern void BG_InitWeaponStrings(void);
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
void BG_ClearWeaponDef(void) {
    WeaponDef *defaultDef;
    gitem_t *itemList;
    int i;

    /* Load the default weapon definition */
    defaultDef = (WeaponDef *)BG_LoadDefaultWeaponDef();

    /* Initialize weapon defs array with the default */
    bg_weaponDefs[0] = defaultDef;

    /* Initialize ammo types */
    bg_weapAmmoTypes[0] = defaultDef;
    bg_iNumAmmoTypes = 1;

    /* Initialize shared ammo caps */
    bg_sharedAmmoCaps[0] = defaultDef;
    bg_iNumSharedAmmoCaps = 1;

    /* Initialize weapon clips */
    bg_weapClips[0] = defaultDef;
    bg_iNumWeapClips = 1;

    /* The original loop writes base+0x48, then advances by sizeof(gitem_t).
       That maps to giType for item slots 1..128, leaving slot 0 untouched. */
    itemList = (gitem_t *)((void *)imp_bg_itemlist);
    for (i = 1; i <= 128; i++) {
        itemList[i].giType = 0;
    }

    /* Load player animation types and weapon strings */
    BG_LoadPlayerAnimTypes();
    BG_InitWeaponStrings();
}

/* line 558 */
int BG_GetNumWeapons(void)
{
    return bg_iNumWeapons;
}

/* line 580 */
int BG_GetAmmoTypeMax(int iAmmoIndex)
{
    return bg_weapAmmoTypes[iAmmoIndex]->iMaxAmmo;
}

/* line 604 */
int BG_GetAmmoClipSize(int iClipIndex)
{
    return bg_weapClips[iClipIndex]->iClipSize;
}

/* line 713 */
int BG_FindWeaponIndexForName(const char *name)
{
    extern int bg_iNumWeapons;
    extern WeaponDef *bg_weaponDefs[128];
    extern int I_stricmp(const char *, const char *);
    int weapIndex;
    for (weapIndex = 1; weapIndex <= bg_iNumWeapons; weapIndex++) {
        const char *defName = *(const char **)bg_weaponDefs[weapIndex];
        if (I_stricmp(name, defName) == 0)
            return weapIndex;
    }
    return 0;
}
