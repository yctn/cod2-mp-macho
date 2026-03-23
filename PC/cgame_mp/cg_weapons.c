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
extern byte scr_const[];
static const int iSlotPreferenceOrder[2]; /* iSlotPreferenceOrder */
__attribute__((used, packed, aligned(4)))
UInt32 s_barrelTags_storage[8] = {
    (UInt32)(scr_const + 140),
    (UInt32)(scr_const + 142),
    (UInt32)(scr_const + 144),
    (UInt32)(scr_const + 146),
    0,
    0,
    0,
    0,
}; /* 0x314b00 */

#define s_barrelTags ((weapSlot_t (**)[64])s_barrelTags_storage)

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

/* line 311 */
int CG_WeaponDObjHandle(int weaponNum)
{
    return weaponNum + 0x400;
}

/* line 363 */
void CG_Weapons_SetToDefault(int weaponNum, weaponInfo_s (*dobjModels)[4]) {
    byte *weapDef;
    char modelFile[80]; /* 0x58 bytes local */
    const char *handModel;
    const char *viewModel;

    CG_SetWeaponDefToDefaultWeapon(weaponNum);
    weapDef = (byte *)BG_GetWeaponDef(weaponNum);
    Com_Printf("WARNING: gun and/or hand model file for weapon [%s] could not be found\n",
               ((WeaponDef *)weapDef)->szDisplayName);

    handModel = ((WeaponDef *)weapDef)->szGunXModel;
    if (!handModel || handModel[0] == '\0') {
        Com_Error(1, "could not find default weapon model");
    } else {
        viewModel = ((WeaponDef *)weapDef)->szHandXModel;
        if (!viewModel || viewModel[0] == '\0') {
            Com_Error(1, "could not find default weapon model");
        }
    }

    viewModel = ((WeaponDef *)weapDef)->szHandXModel;
    sprintf(modelFile, "%s%s", "xmodel/", viewModel);
    ((DObjModel_s *)dobjModels)[0].model = (struct XModel *)CL_RegisterModel(modelFile);

    handModel = ((WeaponDef *)weapDef)->szGunXModel;
    sprintf(modelFile, "%s%s", "xmodel/", handModel);
    dobjModels[1].model = (struct XModel *)CL_RegisterModel(modelFile);
}
