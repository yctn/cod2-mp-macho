/* Converted to C from ASM: Fxexport.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/Fxexport.cpp */

#include "common_types.h"
#include "imports.h"

extern volatile qboolean fx_camera_valid; /* 0x0 */

extern void *Com_GetClientDObj(int entNum, int localClientNum);
extern int DObjGetBoneIndex(void *dobj, unsigned int bone);
extern void FxScheduler_PlayEffect(void *scheduler, EffectTemplate *fx, const vec_t *org, ...);
extern int FX_Init(int rendererExists);
extern void FX_Free(int freeAll);
extern void FxHelper_AdjustCamera(void *helper, void *refdef, float zfar);
extern void FxHelper_AdjustTime(void *helper, int time);
extern void FxHelper_WarpTime(void *helper, int time);
extern float FxScheduler_GetEffectLength(void *scheduler, EffectTemplate *fx);

extern byte *fx_scheduler_ptr;  /* imp_theFxScheduler */
extern byte *fx_helper_ptr;     /* imp_theFxHelper */
/* fix #153: fx_time_* stubs were 64-byte arrays not aliased to import pointers.
   Access the BSS globals directly instead. */
extern int effectActiveCountBolt;
extern int privateEffectActiveCountBolt;
extern int effectActiveCountNonBolt;
extern int privateEffectActiveCountNonBolt;

int FX_GetBoneIndex(const int entNum, unsigned int bone);
void FX_PlaySimpleEffect(EffectTemplate *fx, const vec_t *org);
void FX_PlayEffect(EffectTemplate *fx, const vec_t *org, const vec_t *fwd);
void FX_PlayEntityEffect(EffectTemplate *fx, const vec_t *org, vec3_t *axis, const FxBoltInfo *bolt);
int FX_InitSystem(int rendererExists);
void FX_FreeSystem(void);
void FX_FreeActive(void);
void FX_AdjustCamera(PrimType (*refdef)[256], float zfar);
void FX_AdjustTime(int time);
void FX_WarpTime(int time);
float FX_GetEffectLength(EffectTemplate *fx);
void Server_SwitchToValidFxScheduler(void);

/* line 49 */
int FX_GetBoneIndex(const int entNum, unsigned int bone)
{
    void *pObj = Com_GetClientDObj(entNum, 0);
    if (pObj == NULL)
        return -1;
    return DObjGetBoneIndex(pObj, bone);
}

/* line 60 */
/* fix #153: fx_scheduler_ptr is imp_theFxScheduler which stores &theFxScheduler;
   theFxScheduler stores the heap FxScheduler pointer — need double deref */
void FX_PlaySimpleEffect(EffectTemplate *fx, const vec_t *org)
{
    FxScheduler_PlayEffect(*(void **)*(void **)&fx_scheduler_ptr, fx, org);
}

/* line 67 */
void FX_PlayEffect(EffectTemplate *fx, const vec_t *org, const vec_t *fwd)
{
    FxScheduler_PlayEffect(*(void **)*(void **)&fx_scheduler_ptr, fx, org, fwd);
}

/* line 81 */
void FX_PlayEntityEffect(EffectTemplate *fx, const vec_t *org, vec3_t *axis, const FxBoltInfo *bolt)
{
    FxScheduler_PlayEffect(*(void **)*(void **)&fx_scheduler_ptr, fx, org, axis, bolt);
}

/* line 89 */
int FX_InitSystem(int rendererExists)
{
    return FX_Init((unsigned char)rendererExists);
}

/* line 95 */
void FX_FreeSystem(void)
{
    FX_Free(1);
}

/* line 101 */
void FX_FreeActive(void)
{
    FX_Free(0);
}

/* line 107 */
/* fix #153: fx_helper_ptr is imp_theFxHelper which stores &theFxHelper;
   theFxHelper stores &theFxHelpers (BSS struct) — need double deref */
void FX_AdjustCamera(PrimType (*refdef)[256], float zfar)
{
    FxHelper_AdjustCamera(*(void **)*(void **)&fx_helper_ptr, refdef, zfar);
    fx_camera_valid = 1;
}

/* line 120 */
void FX_AdjustTime(int time)
{
    fx_camera_valid = 0;
    FxHelper_AdjustTime(*(void **)*(void **)&fx_helper_ptr, time);
    privateEffectActiveCountBolt = effectActiveCountBolt;
    privateEffectActiveCountNonBolt = effectActiveCountNonBolt;
}

/* line 135 */
void FX_WarpTime(int time)
{
    FxHelper_WarpTime(*(void **)*(void **)&fx_helper_ptr, time);
}

/* line 143 */
float FX_GetEffectLength(EffectTemplate *fx)
{
    return FxScheduler_GetEffectLength(*(void **)*(void **)&fx_scheduler_ptr, fx);
}

/* line 29 */
void Server_SwitchToValidFxScheduler(void)
{
    /* empty - no-op */
}
