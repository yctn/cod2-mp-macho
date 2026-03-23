/* ASM dump from: FxScheduler.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxScheduler.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/FxPrimitives.h"
 *   #include "PC/EffectsCore/FxUtil.h"
 *   #include "PC/EffectsCore/FxMemMgr.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/EffectsCore/FxCurve.h"
 *   #include "PC/EffectsCore/FxChannel.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/EffectsCore/FxArchive.h"
 *   #include "Mac/Tools/MacSwap.h"
 */

extern int irand(int min, int max);
extern refexport_t re; /* imp_re */

extern FxScheduler * fxSchedulers[1]; /* 0x0 */
static EffectTemplate * effectTemplateArray[256]; /* effectTemplateArray */
static int effectTemplateArrayCount; /* effectTemplateArrayCount */

/* extern function declarations */
extern void GenericParser2_GenericParser2(GenericParser2 *parser);
extern void ZN14GenericParser2D1Ev(GenericParser2 *parser);
extern EffectTemplate *FX_ParseEffect(GenericParser2 *parser, const char *name);
extern void FX_Print(const char *msg, ...);
extern void FxBoltFrame_Release(const FxBoltFrame *frame);
extern const orientation_t *FxBoltFrame_GetOrientation(const FxBoltFrame *frame);
extern const FxBoltFramePtr FxBoltFrame_Acquire(const FxBoltInfo *bolt);
extern void AxisCopy(const vec_t *src, vec_t *dst);
extern float flrand(float min, float max);
extern void RotatePointAroundVector(vec_t *dst, const vec_t *src, const vec_t *dir, float degrees);
extern void Vec3Cross(const vec_t *a, const vec_t *b, vec_t *out);
extern int FxHelper_GetSeed(const FxHelper *helper);
extern void Rand_Init(int seed);
extern void FxHelper_SetIgnorePrecacheErrors(const FxHelper *helper, int ignore);
extern EffectTemplate *FX_RegisterEffect(const char *fileName);
extern Bool FX_GetBoneOrientation(const FxBoltInfo *bolt, orientation_t *orient);
extern Bool FxHelper_CullSpherePreviousFrame(const FxHelper *helper, const vec_t *worldPos, float radius);
extern float FxRange_GetVal(const FxRange *range);
extern float Vec3DistanceSq(const vec_t *a, const vec_t *b);
extern void FxChannelInstance_Create(const FxChannel *master, FxChannelInstance *createe);
extern void FX_CleanTemplate(EffectTemplate *fx);
extern void CG_ImpactMark(MaterialHandle markMaterial, const vec_t *origin, const vec_t *dir, float orientation, const vec_t *color, float radius);
extern void FxArchive_ReadData(const FxArchive *arch, void *p, int byteCount);
extern void FxArchive_WriteData(const FxArchive *arch, const void *p, int byteCount);
extern void FxArchive_ArchiveEffect(const FxArchive *arch, const EffectTemplate **fx);
extern void FxArchive_ArchiveFxBoltInfo(const FxArchive *arch, FxBoltInfo *bolt);

extern void FX_AddParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddLine(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddTail(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddCylinder(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddEmitter(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddDecal(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddOrientedParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddFxRunner(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddLight(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddCameraShake(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddFlash(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
extern void FX_AddCloud(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);

extern void *__Znam(unsigned int size);
extern void __ZdaPv(void *ptr);

TMediaElement MediaHandles_GetHandle(const MediaHandles * _this);
void FxScheduler_FxScheduler(const FxScheduler * _this);
float FxScheduler_GetEffectLength(const FxScheduler * _this, EffectTemplate *fx);
void FX_InitTemplates(void);
EffectTemplate * FX_TryRegisterEffect(const char *name);
static void GLOBAL__I__ZN17PrimitiveTemplate8gmMemMgrE(void); /* global constructors keyed to PrimitiveTemplate_gmMemMgr */
Bool FX_GetBoltingFrame(const PrimitiveTemplate *primTemp, const FxBoltInfo *bolt, FxBoltFramePtr *boltFrame);
void FxScheduler_CreateEffect(const FxScheduler * _this, const EffectTemplate *fx, const PrimitiveTemplate *primTemp, const FxBoltInfo *bolt, const vec_t *origin, MediaHandles * (*axis)[4], int lateTime, int indexInBatch);
void FxScheduler_PlayEffect(const FxScheduler * _this, const EffectTemplate *fx, const vec_t *origin, MediaHandles * (*axis)[4], const FxBoltInfo *bolt);
void FxScheduler_Clean(const FxScheduler * _this, int bRemoveTemplates, EffectTemplate *fxToPreserve);
void FxScheduler_GetDecalColor(const FxScheduler * _this, const PrimitiveTemplate *primTemp, vec_t *rgba);
float FxScheduler_GetDecalAlpha(const FxScheduler * _this, const PrimitiveTemplate *primTemp);
float FxScheduler_GetDecalSize(const FxScheduler * _this, const PrimitiveTemplate *primTemp);
EffectTemplate * MediaHandles_GetEffect(const MediaHandles * _this);
void FxScheduler_CreateDecalEffect(const FxScheduler * _this, const PrimitiveTemplate *primTemp, vec_t *org, MediaHandles * (*ax)[4]);
void ScheduledEffect_Archive(const ScheduledEffect * _this, FxArchive *arch);
void FxScheduler_Archive(const FxScheduler * _this, FxArchive *arch);

/* line 75 */
TMediaElement MediaHandles_GetHandle(const MediaHandles * _this)
{
    unsigned short count = _this->mMediaList.size;
    TMediaElement result;
    TMediaElement *elements;

    if (!count) {
        result.data = NULL;
        return result;
    }

    elements = _this->mMediaList.elements;
    return elements[irand(0, count)];
}

/* line 90 */
void FxScheduler_FxScheduler(const FxScheduler * _this)
{
    FxScheduler *sched = (FxScheduler *)_this;
    sched->mScheduledHead = NULL;
    sched->mScheduledCount = 0;
}

/* line 459 */
float FxScheduler_GetEffectLength(const FxScheduler * _this, EffectTemplate *fx)
{
    int count = fx->mPrimitiveCount;
    float maxLen = 0.0f;
    int i;

    for (i = 0; i < count; i++) {
        PrimitiveTemplate *prim = fx->mPrimitives[i];
        float len = prim->mSpawnDelay.mMax + prim->mLife.mMax;
        if (len > maxLen)
            maxLen = len;
    }

    return maxLen;
}

/* line 789 */
void FX_InitTemplates(void)
{
    effectTemplateArrayCount = 0;
}

/* line 834 */
EffectTemplate * FX_TryRegisterEffect(const char *name)
{
    GenericParser2 parser;
    int effectIndex;
    int count;
    EffectTemplate *registeredTemplate;
    EffectTemplate *fx;

    GenericParser2_GenericParser2(&parser);

    /* Search existing templates */
    count = effectTemplateArrayCount;
    for (effectIndex = 0; effectIndex < count; effectIndex++) {
        registeredTemplate = effectTemplateArray[effectIndex];
        if (strcmp(*(const char **)registeredTemplate, name) == 0) {
            /* Found existing template */
            ZN14GenericParser2D1Ev(&parser);
            return registeredTemplate;
        }
    }

    /* Parse new effect */
    fx = FX_ParseEffect(&parser, name);
    if (!fx) {
        ZN14GenericParser2D1Ev(&parser);
        return NULL;
    }

    /* Register the new template */
    if (effectTemplateArrayCount == 256) {
        FX_Print(str_0021a904, 256);
        ZN14GenericParser2D1Ev(&parser);
        return NULL;
    }

    effectTemplateArray[effectTemplateArrayCount] = fx;
    effectTemplateArrayCount++;
    registeredTemplate = fx;

    ZN14GenericParser2D1Ev(&parser);
    return registeredTemplate;
}


/* line 952 */
static void GLOBAL__I__ZN17PrimitiveTemplate8gmMemMgrE(void) /* global constructors keyed to PrimitiveTemplate_gmMemMgr */
{
}

/* line 580 */
Bool FX_GetBoltingFrame(const PrimitiveTemplate *primTemp, const FxBoltInfo *bolt, FxBoltFramePtr *boltFrame)
{
    FxBoltFramePtr acquired;
    FxBoltFrame *oldFrame;
    FxBoltFrame *newFrame;
    FxBoltFrame *curFrame;

    /* Check if bolting is enabled and valid */
    if (!(primTemp->mAttributeFlags & 2) || !bolt || bolt->dobjHandle < 0) {
        return 1; /* true - no bolting needed */
    }

    /* Acquire bolt frame */
    acquired = FxBoltFrame_Acquire(bolt);
    newFrame = (FxBoltFrame *)(void *)(size_t)acquired._placeholder;
    oldFrame = (FxBoltFrame *)(void *)(size_t)boltFrame->_placeholder;

    if (oldFrame == newFrame) {
        /* Same frame, just release the acquired one */
        if (oldFrame) {
            FxBoltFrame_Release(oldFrame);
        }
    } else {
        /* Different frame - release old, install new */
        if (oldFrame) {
            FxBoltFrame_Release(oldFrame);
            boltFrame->_placeholder = 0;
        }
        if (newFrame) {
            /* AddRef */
            newFrame->refCount += 1;
            boltFrame->_placeholder = (int)(size_t)(void *)newFrame;
            /* Release the acquired ref */
            if (newFrame) {
                FxBoltFrame_Release(newFrame);
            }
        } else {
            /* newFrame is NULL, release acquired */
            /* (nothing to release since newFrame is NULL) */
        }
    }

    /* Check if boltFrame has a valid frame with orientation */
    curFrame = (FxBoltFrame *)(void *)(size_t)boltFrame->_placeholder;
    if (!curFrame) {
        return 0; /* false */
    }
    if (!FxBoltFrame_GetOrientation(curFrame)) {
        return 0; /* false */
    }

    return 1; /* true */
}


/* line 688 */
void FxScheduler_CreateEffect(const FxScheduler * _this, const EffectTemplate *fx, const PrimitiveTemplate *primTemp, const FxBoltInfo *bolt, const vec_t *origin, MediaHandles * (*axis)[4], int lateTime, int indexInBatch)
{
    FxBoltFramePtr boltFrame;
    vec3_t ax[3];
    EffectPrimitive prim;
    int primType;

    boltFrame._placeholder = 0;

    /* Copy axis */
    AxisCopy((const vec_t *)axis, (vec_t *)ax);

    /* Handle random rotation around forward axis */
    if (primTemp->mSpawnFlags & 1) {
        vec3_t rotated;
        float angle = flrand(0.0f, 360.0f);
        RotatePointAroundVector(rotated, (const vec_t *)ax, (const vec_t *)axis + 3, angle);
        Vec3Cross((const vec_t *)ax, rotated, ax[1]);
    }

    /* Get bolting frame */
    if (!FX_GetBoltingFrame(primTemp, bolt, &boltFrame)) {
        goto cleanup;
    }

    /* Set up primitive */
    prim.fx = fx;
    prim.primTemp = primTemp;

    /* Dispatch based on primitive type (offset 0x40) */
    primType = primTemp->mType;
    if (primType > 12) {
        goto cleanup;
    }

    switch (primType) {
    case 0: /* none */
        break;
    case 1: /* particle */
        FX_AddParticle(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 2: /* line */
        FX_AddLine(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 3: /* tail */
        FX_AddTail(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 4: /* cylinder */
        FX_AddCylinder(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 5: /* emitter */
        FX_AddEmitter(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 6: /* decal */
        FX_AddDecal(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 7: /* oriented particle */
        FX_AddOrientedParticle(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 8: /* fx runner */
        FX_AddFxRunner(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 9: /* light */
        FX_AddLight(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 10: /* camera shake */
        FX_AddCameraShake(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 11: /* flash */
        FX_AddFlash(&prim, ax, origin, lateTime, indexInBatch);
        break;
    case 12: /* cloud */
        FX_AddCloud(&prim, ax, origin, lateTime, indexInBatch);
        break;
    }

cleanup:
    if (boltFrame._placeholder) {
        FxBoltFrame_Release((FxBoltFrame *)(void *)(size_t)boltFrame._placeholder);
    }
}


/* line 283 */
void FxScheduler_PlayEffect(const FxScheduler * _this, const EffectTemplate *fx, const vec_t *origin, MediaHandles * (*axis)[4], const FxBoltInfo *bolt)
{
    FxHelper *helper;
    int seed;
    orientation_t or_;
    vec3_t ax[3];
    int i;
    float factor;
    int numAdded;
    int seedOffset;
    PrimitiveTemplate *prim;
    float distSq;
    int rangeCheck;
    float culldist;

    helper = *(FxHelper **)&imp_theFxHelper;

    /* Get and set seed */
    seed = FxHelper_GetSeed(helper);
    ((FxScheduler *)_this)->mSeed = seed;
    Rand_Init(seed);

    /* Handle null fx */
    if (!fx) {
        FxHelper_SetIgnorePrecacheErrors(helper, 1);
        fx = FX_RegisterEffect(str_0021a930);
        FxHelper_SetIgnorePrecacheErrors(helper, 0);
        if (!fx) {
            FX_Print(str_0021a940);
            return;
        }
    }

    /* Check fx_freeze and fx_enable dvars */
    {
        dvar_t *freezeDvar = *(dvar_t **)&imp_fx_freeze;
        dvar_t *enableDvar = *(dvar_t **)&imp_fx_enable;
        if (freezeDvar->current.enabled != 0)
            return;
        if (enableDvar->current.enabled == 0)
            return;
    }

    /* Get origin and axis from bolt or params */
    if (bolt) {
        /* Check bolt validity */
        if (bolt->dobjHandle < 0)
            return;
        if (!FX_GetBoneOrientation(bolt, &or_))
            return;
    } else {
        /* Use provided origin */
        if (origin) {
            or_.origin[0] = origin[0];
            or_.origin[1] = origin[1];
            or_.origin[2] = origin[2];
        } else {
            or_.origin[0] = 0.0f;
            or_.origin[1] = 0.0f;
            or_.origin[2] = 0.0f;
        }
        AxisCopy((const vec_t *)axis, (vec_t *)ax);
    }

    /* Iterate primitives */
    numAdded = 0;
    seedOffset = 0;

    for (i = 0; i < fx->mPrimitiveCount; i++) {
        int count;
        int t;
        float spawnDistSq;
        float cullDistSq;
        int flags;

        prim = fx->mPrimitives[i];
        factor = 0.0f;

        /* Cull distance check (mSpawnRange offset 0x60) */
        if (prim->mSpawnRange.mMin != 0.0f) {
            /* Far cull check */
            distSq = Vec3DistanceSq(origin, helper->mCamera.vieworg);
            culldist = prim->mSpawnRange.mMin * helper->adsZoomFactor;
            if (distSq > culldist * culldist) {
                continue;
            }
            rangeCheck = 1;
        } else {
            rangeCheck = 0;
        }

        /* Near cull check (mSpawnRange.max offset 0x64) */
        if (prim->mSpawnRange.mMax != 0.0f) {
            if (!rangeCheck) {
                distSq = Vec3DistanceSq(origin, helper->mCamera.vieworg);
            }
            culldist = prim->mSpawnRange.mMax * helper->adsZoomFactor;
            if (distSq > culldist * culldist) {
                continue;
            }
        }

        /* CullSphere check */
        if (prim->mSpawnFlags & 4) {
            if (FxHelper_CullSpherePreviousFrame(helper, origin, prim->spawnFrustumCullRadius)) {
                continue;
            }
        }

        /* Get spawn count */
        {
            float fcount = FxRange_GetVal(&prim->mSpawnCount);
            count = (int)(fcount + 0.5f);
        }
        if (count == 0)
            continue;

        /* Calculate delay factor if FLAG_USE_EVEN_DISTRIBUTION (flag bit 0x200 at offset 0x94) */
        flags = prim->mSpawnFlags;
        if (flags & 0x200) {
            float start = prim->mSpawnDelay.mMin;
            float end = prim->mSpawnDelay.mMax;
            factor = end - start;
            if (factor < 0.0f)
                factor = -factor;
            factor = factor / (float)count;
        }

        numAdded += count;

        /* Spawn each instance */
        for (t = 0; t < count; t++) {
            int delay;

            flags = prim->mSpawnFlags;
            if (flags & 0x200) {
                /* Even distribution delay */
                delay = (int)((float)t * factor);
            } else {
                /* Random delay from FxRange */
                float fdelay = FxRange_GetVal(&prim->mSpawnDelay);
                delay = (int)fdelay;
            }

            if (delay > 0) {
                /* Schedule the effect for future execution */
                ScheduledEffect *sfx = (ScheduledEffect *)__Znam(0x50);
                if (!sfx)
                    continue;
                memset(sfx, 0, 0x50);

                /* Set start time = current time + delay */
                sfx->mStartTime = helper->mTime + delay;
                /* Set fx */
                sfx->mFx = fx;
                /* Set prim index */
                sfx->mPrimIndex = i;
                /* Set index in batch */
                sfx->mIndexInBatch = t;
                /* Set seed */
                sfx->mSeed = FxHelper_GetSeed(helper) + seedOffset;
                /* Set bolt info */
                if (bolt) {
                    sfx->mBolt.dobjHandle = bolt->dobjHandle;
                    sfx->mBolt.boneIndex = bolt->boneIndex;
                } else {
                    sfx->mBolt.dobjHandle = -1;
                    sfx->mBolt.boneIndex = -1;
                }
                /* Copy origin */
                sfx->mOrigin[0] = or_.origin[0];
                sfx->mOrigin[1] = or_.origin[1];
                sfx->mOrigin[2] = or_.origin[2];
                /* Copy axis */
                AxisCopy((const vec_t *)ax, (vec_t *)sfx->mAxis);
                /* Link into scheduler list */
                sfx->mScheduledNext = ((FxScheduler *)_this)->mScheduledCount; /* link into list */
                ((FxScheduler *)_this)->mScheduledCount = (int)(size_t)sfx;
                ((FxScheduler *)_this)->mScheduledCount += 1;
            } else {
                /* Spawn immediately */
                FxScheduler_CreateEffect(_this, fx, prim, bolt, (const vec_t *)or_.origin, (MediaHandles *(*)[4])ax, -delay, t);
            }
        }

        seedOffset += 0x369d035;
    }

    /* Display debug count */
    if (numAdded) {
        dvar_t *countDvar = *(dvar_t **)&imp_fx_count;
        if (countDvar->current.enabled != 0) {
            re.AddPlume(or_.origin, numAdded, *(const vec_t **)&imp_colorYellow, 3000);
        }
    }
}


/* overload skip: FxScheduler_PlayEffect (0x61ef6) */

/* overload skip: FxScheduler_PlayEffect (0x61f6a) */

/* overload skip: FxScheduler_PlayEffect (0x61fca) */

/* line 102 */
void FxScheduler_Clean(const FxScheduler * _this, int bRemoveTemplates, EffectTemplate *fxToPreserve)
{
    byte *self = (byte *)_this;
    ScheduledEffect *sfx;
    int effectIndex;
    int foundTemplateToPreserve;

    /* Free all scheduled effects */
    while ((sfx = (ScheduledEffect *)(size_t)((FxScheduler *)_this)->mScheduledCount) != NULL) {
        ((FxScheduler *)_this)->mScheduledCount = sfx->mScheduledNext;
        __ZdaPv(sfx);
    }
    ((FxScheduler *)_this)->mScheduledCount = 0;

    /* Remove templates if requested */
    if (!(byte)bRemoveTemplates)
        return;

    foundTemplateToPreserve = 0;
    for (effectIndex = 0; effectIndex < effectTemplateArrayCount; effectIndex++) {
        if (effectTemplateArray[effectIndex] == fxToPreserve) {
            foundTemplateToPreserve = 1;
        } else {
            FX_CleanTemplate(effectTemplateArray[effectIndex]);
            effectTemplateArray[effectIndex] = NULL;
        }
    }

    effectTemplateArrayCount = 0;
    if (foundTemplateToPreserve) {
        effectTemplateArray[0] = fxToPreserve;
        effectTemplateArrayCount = 1;
    }
}


/*
 * Helper: advance FxCurveIterator to find the key segment containing time t.
 * The curve keys are stored as: [time, val0, val1, ...] with stride = (dimensionCount+1).
 * This performs the "find key" loop seen in the ASM (lines 91-102).
 */
static void FxCurveIterator_FindKey(const FxCurve *curve, int *currentKeyIndex, float t)
{
    int keyStride = curve->dimensionCount + 1;
    const float *keys = curve->keys;
    const float *lastKeyTime;

    /* Compute pointer to last key's time value */
    lastKeyTime = &keys[(*currentKeyIndex) * keyStride];

    /* Check if last key time > 0 (meaning we haven't gone past the end); if so reset index */
    if (*lastKeyTime > 0.0f) {
        *currentKeyIndex = 0;
        lastKeyTime = &keys[0];
    }

    /* Advance past the last key to find the end sentinel */
    {
        const float *endCheck = lastKeyTime + keyStride;
        while (t > *endCheck) {
            (*currentKeyIndex)++;
            endCheck += keyStride;
        }
    }
}

/*
 * Helper: interpolate a 3-component curve at time t (for color channels).
 * Returns interpolated vec3 in out[0..2].
 */
static void FxCurve_Interp3(const FxCurve *curve, int keyIndex, float t, float *out)
{
    int stride = curve->dimensionCount + 1;
    const float *keyBase = &curve->keys[keyIndex * stride];
    float keyTime = keyBase[0];
    float nextKeyTime = keyBase[stride];
    float frac;

    frac = (t - keyTime) / (nextKeyTime - keyTime);

    out[0] = keyBase[1] + (keyBase[stride + 1] - keyBase[1]) * frac;
    out[1] = keyBase[2] + (keyBase[stride + 2] - keyBase[2]) * frac;
    out[2] = keyBase[3] + (keyBase[stride + 3] - keyBase[3]) * frac;
}

/*
 * Helper: interpolate a 1-component curve at time t.
 * Returns the interpolated single float.
 */
static float FxCurve_Interp1(const FxCurve *curve, int keyIndex, float t)
{
    /* 1-component curve: stride = 2 (time + value), so keys are stored at ecx+keyIndex*8+8 */
    const float *keyBase = &curve->keys[keyIndex * 2];
    float keyTime = keyBase[0];
    float keyVal = keyBase[1];
    float nextKeyTime = keyBase[2];
    float nextKeyVal = keyBase[3];
    float frac;

    frac = (t - keyTime) / (nextKeyTime - keyTime);
    return keyVal + (nextKeyVal - keyVal) * frac;
}

/* line 482 */
void FxScheduler_GetDecalColor(const FxScheduler * _this, const PrimitiveTemplate *primTemp, vec_t *rgba)
{
    FxChannelInstance colorChannelInstance;
    const FxCurve *curve;
    int keyIndex;
    float scale;
    float t;

    /* Create color channel instance from primTemp offset 0x100 */
    FxChannelInstance_Create(&primTemp->mFxChannels[0], &colorChannelInstance); /* color channel */

    if (primTemp->mAttributeFlags & 0x2000) { /* bit 13 = use random color */
        /* Random color path */
        float randomWeight = flrand(0.0f, 1.0f);
        FxChannelInstance colorRandChannelInstance;
        FxChannelInstance_Create(&primTemp->mFxChannels[1], &colorRandChannelInstance); /* colorRand channel */

        /* Evaluate main color channel at t=0 */
        curve = colorChannelInstance.curveIterator.master;
        keyIndex = colorChannelInstance.curveIterator.currentKeyIndex;
        t = 0.0f;
        FxCurveIterator_FindKey(curve, &keyIndex, t);
        colorChannelInstance.curveIterator.currentKeyIndex = keyIndex;

        {
            float baseColor[3];
            FxCurve_Interp3(curve, keyIndex, t, baseColor);
            rgba[0] = baseColor[0];
            rgba[1] = baseColor[1];
            rgba[2] = baseColor[2];
        }

        /* Evaluate random color channel at t=0 */
        {
            const FxCurve *randCurve = colorRandChannelInstance.curveIterator.master;
            int randKeyIndex = colorRandChannelInstance.curveIterator.currentKeyIndex;
            float randColor[3];
            float diff[3];

            FxCurveIterator_FindKey(randCurve, &randKeyIndex, t);
            colorRandChannelInstance.curveIterator.currentKeyIndex = randKeyIndex;

            {
                int stride = randCurve->dimensionCount + 1;
                const float *keyBase = &randCurve->keys[randKeyIndex * stride];
                float keyTime = keyBase[0];
                float nextKeyTime = keyBase[stride];
                float frac = (t - keyTime) / (nextKeyTime - keyTime);

                randColor[0] = keyBase[1] + (keyBase[stride + 1] - keyBase[1]) * frac;
                randColor[1] = keyBase[2] + (keyBase[stride + 2] - keyBase[2]) * frac;
                randColor[2] = keyBase[3] + (keyBase[stride + 3] - keyBase[3]) * frac;
            }

            /* Blend: base + (rand - base) * randomWeight */
            rgba[0] = rgba[0] + (randColor[0] - rgba[0]) * randomWeight;
            rgba[1] = rgba[1] + (randColor[1] - rgba[1]) * randomWeight;
            rgba[2] = rgba[2] + (randColor[2] - rgba[2]) * randomWeight;
        }

        /* Apply scale */
        scale = colorRandChannelInstance.scale;
        rgba[0] *= scale;
        rgba[1] *= scale;
        rgba[2] *= scale;
    } else {
        /* Non-random color path */
        curve = colorChannelInstance.curveIterator.master;
        keyIndex = colorChannelInstance.curveIterator.currentKeyIndex;
        t = 0.0f;
        FxCurveIterator_FindKey(curve, &keyIndex, t);
        colorChannelInstance.curveIterator.currentKeyIndex = keyIndex;

        {
            float color[3];
            FxCurve_Interp3(curve, keyIndex, t, color);
            rgba[0] = color[0];
            rgba[1] = color[1];
            rgba[2] = color[2];
        }

        /* Apply scale */
        scale = colorChannelInstance.scale;
        rgba[0] *= scale;
        rgba[1] *= scale;
        rgba[2] *= scale;
    }
}


/* line 505 */
float FxScheduler_GetDecalAlpha(const FxScheduler * _this, const PrimitiveTemplate *primTemp)
{
    FxChannelInstance alphaChannelInstance;
    const FxCurve *curve;
    int keyIndex;
    float t;
    float result;

    /* Create alpha channel instance from primTemp offset 0x118 */
    FxChannelInstance_Create(&primTemp->mFxChannels[2], &alphaChannelInstance); /* alpha channel */

    if (primTemp->mAttributeFlags & 0x4000) { /* bit 14 = use random alpha */
        /* Random alpha path */
        float randomWeight = flrand(0.0f, 1.0f);
        FxChannelInstance alphaRandChannelInstance;
        float baseVal, randVal;

        FxChannelInstance_Create(&primTemp->mFxChannels[3], &alphaRandChannelInstance); /* alphaRand channel */

        /* Evaluate main alpha channel at t=0 */
        curve = alphaChannelInstance.curveIterator.master;
        keyIndex = alphaChannelInstance.curveIterator.currentKeyIndex;
        t = 0.0f;
        FxCurveIterator_FindKey(curve, &keyIndex, t);
        alphaChannelInstance.curveIterator.currentKeyIndex = keyIndex;
        baseVal = FxCurve_Interp1(curve, keyIndex, t);

        /* Evaluate random alpha channel at t=0 */
        {
            const FxCurve *randCurve = alphaRandChannelInstance.curveIterator.master;
            int randKeyIndex = alphaRandChannelInstance.curveIterator.currentKeyIndex;

            FxCurveIterator_FindKey(randCurve, &randKeyIndex, t);
            alphaRandChannelInstance.curveIterator.currentKeyIndex = randKeyIndex;
            randVal = FxCurve_Interp1(randCurve, randKeyIndex, t);
        }

        /* Blend and apply scale */
        result = (baseVal + (randVal - baseVal) * randomWeight) * alphaChannelInstance.scale;
    } else {
        /* Non-random alpha path */
        curve = alphaChannelInstance.curveIterator.master;
        keyIndex = alphaChannelInstance.curveIterator.currentKeyIndex;
        t = 0.0f;
        FxCurveIterator_FindKey(curve, &keyIndex, t);
        alphaChannelInstance.curveIterator.currentKeyIndex = keyIndex;
        result = FxCurve_Interp1(curve, keyIndex, t) * alphaChannelInstance.scale;
    }

    /* Clamp to [0, 1] */
    if (result < 0.0f)
        result = 0.0f;
    if (result > 1.0f)
        result = 1.0f;

    return result;
}


/* line 531 */
float FxScheduler_GetDecalSize(const FxScheduler * _this, const PrimitiveTemplate *primTemp)
{
    FxChannelInstance sizeChannelInstance;
    const FxCurve *curve;
    int keyIndex;
    float t;
    float result;

    /* Create size channel instance from primTemp offset 0x130 */
    FxChannelInstance_Create(&primTemp->mFxChannels[4], &sizeChannelInstance); /* size channel */

    if ((short)primTemp->mAttributeFlags < 0) { /* bit 15 = use random size */
        /* Random size path (bit 15 set = signed negative) */
        float randomWeight = flrand(0.0f, 1.0f);
        FxChannelInstance sizeRandChannelInstance;
        float baseVal, randVal;

        FxChannelInstance_Create(&primTemp->mFxChannels[5], &sizeRandChannelInstance); /* sizeRand channel */

        /* Evaluate main size channel at t=0 */
        curve = sizeChannelInstance.curveIterator.master;
        keyIndex = sizeChannelInstance.curveIterator.currentKeyIndex;
        t = 0.0f;
        FxCurveIterator_FindKey(curve, &keyIndex, t);
        sizeChannelInstance.curveIterator.currentKeyIndex = keyIndex;
        baseVal = FxCurve_Interp1(curve, keyIndex, t);

        /* Evaluate random size channel at t=0 */
        {
            const FxCurve *randCurve = sizeRandChannelInstance.curveIterator.master;
            int randKeyIndex = sizeRandChannelInstance.curveIterator.currentKeyIndex;

            FxCurveIterator_FindKey(randCurve, &randKeyIndex, t);
            sizeRandChannelInstance.curveIterator.currentKeyIndex = randKeyIndex;
            randVal = FxCurve_Interp1(randCurve, randKeyIndex, t);
        }

        /* Blend and apply scale */
        result = (baseVal + (randVal - baseVal) * randomWeight) * sizeChannelInstance.scale;
    } else {
        /* Non-random size path */
        curve = sizeChannelInstance.curveIterator.master;
        keyIndex = sizeChannelInstance.curveIterator.currentKeyIndex;
        t = 0.0f;
        FxCurveIterator_FindKey(curve, &keyIndex, t);
        sizeChannelInstance.curveIterator.currentKeyIndex = keyIndex;
        result = FxCurve_Interp1(curve, keyIndex, t) * sizeChannelInstance.scale;
    }

    return result;
}


/* line 69 */
EffectTemplate * MediaHandles_GetEffect(const MediaHandles * _this)
{
    unsigned short count = _this->mMediaList.size;
    TMediaElement *elements;

    if (!count) {
        return NULL;
    }

    elements = *(TMediaElement **)_this; /* mMediaList.elements */
    return (EffectTemplate *)elements[irand(0, count)].data;
}


/* line 554 */
void FxScheduler_CreateDecalEffect(const FxScheduler * _this, const PrimitiveTemplate *primTemp, vec_t *org, MediaHandles * (*ax)[4])
{
    float rotation;
    vec3_t rgba;
    float alpha;
    float size;
    MaterialHandle markMaterial;
    unsigned short count;
    TMediaElement *elements;

    /* Get rotation from primTemp offset 0x220 (mRotation range) */
    rotation = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mRotation);

    /* Get decal color */
    FxScheduler_GetDecalColor(_this, primTemp, rgba);

    /* Get decal alpha */
    alpha = FxScheduler_GetDecalAlpha(_this, primTemp);
    (void)alpha; /* stored in rgba but used implicitly */

    /* Get decal size */
    size = FxScheduler_GetDecalSize(_this, primTemp);

    /* Get mark material from MediaHandles at primTemp offset 0x68 */
    count = primTemp->mMediaHandles.mMediaList.size;
    if (!count) {
        markMaterial = NULL;
    } else {
        elements = *(TMediaElement **)&primTemp->mMediaHandles; /* mMediaHandles.mMediaList.elements */
        markMaterial = (MaterialHandle)elements[irand(0, count)].data;
    }

    /* Call CG_ImpactMark */
    CG_ImpactMark(markMaterial, org, (const vec_t *)ax, rotation, rgba, size);
}


/* Helper: Archive an int field (read or write depending on arch->isReading at offset 4) */
static void FxArchive_ArchiveInt(const FxArchive *arch, int *field)
{
    int tmp;
    if (arch->isReading) {
        /* Reading */
        FxArchive_ReadData(arch, &tmp, 4);
        *field = tmp;
    } else {
        /* Writing */
        tmp = *field;
        FxArchive_WriteData(arch, &tmp, 4);
    }
}

/* Helper: Archive a vec3_t field */
static void FxArchive_ArchiveVec3(const FxArchive *arch, vec_t *v)
{
    int tmp;
    if (arch->isReading) {
        /* Reading */
        FxArchive_ReadData(arch, v, 0xc);
    } else {
        /* Writing - write each component as 4 bytes */
        tmp = *(int *)&v[0];
        FxArchive_WriteData(arch, &tmp, 4);
        tmp = *(int *)&v[1];
        FxArchive_WriteData(arch, &tmp, 4);
        tmp = *(int *)&v[2];
        FxArchive_WriteData(arch, &tmp, 4);
    }
}

/* line 759 */
void ScheduledEffect_Archive(const ScheduledEffect * _this, FxArchive *arch)
{
    ScheduledEffect *sfxPtr = (ScheduledEffect *)_this;

    /* Archive effect template pointer */
    FxArchive_ArchiveEffect(arch, &sfxPtr->mFx);

    /* Archive mPrimIndex */
    FxArchive_ArchiveInt(arch, &sfxPtr->mPrimIndex);

    /* Archive mStartTime */
    FxArchive_ArchiveInt(arch, &sfxPtr->mStartTime);

    /* Archive bolt info */
    FxArchive_ArchiveFxBoltInfo(arch, &sfxPtr->mBolt);

    /* Archive mOrigin */
    FxArchive_ArchiveVec3(arch, sfxPtr->mOrigin);

    /* Archive mAxis[0] */
    FxArchive_ArchiveVec3(arch, sfxPtr->mAxis[0]);

    /* Archive mAxis[1] */
    FxArchive_ArchiveVec3(arch, sfxPtr->mAxis[1]);

    /* Archive mAxis[2] */
    FxArchive_ArchiveVec3(arch, sfxPtr->mAxis[2]);

    /* Archive mSeed */
    FxArchive_ArchiveInt(arch, &sfxPtr->mSeed);
}


/* line 710 */
void FxScheduler_Archive(const FxScheduler * _this, FxArchive *arch)
{
    byte *self = (byte *)_this;
    int pendingCount;
    int i;
    ScheduledEffect *sfx;

    FxScheduler *sched_self = (FxScheduler *)_this;
    if (arch->isReading) {
        /* Reading */
        sched_self->mScheduledHead = NULL;
        sched_self->mScheduledCount = 0;

        /* Read pending count */
        FxArchive_ReadData(arch, &pendingCount, 4);

        for (i = 0; i < pendingCount; i++) {
            ScheduledEffect *newSfx = (ScheduledEffect *)__Znam(0x50);
            if (newSfx) {
                memset(newSfx, 0, 0x50);
            }

            ScheduledEffect_Archive(newSfx, arch);

            /* Validate: fx must exist and primIndex must be valid */
            {
                const EffectTemplate *fx = newSfx->mFx;
                int primIndex = newSfx->mPrimIndex;
                if (fx && primIndex >= 0 && primIndex < fx->mPrimitiveCount) {
                    /* Get the primitive template */
                    PrimitiveTemplate *prim = fx->mPrimitives[primIndex];
                    (void)prim;
                    /* Link into scheduler list */
                    newSfx->mScheduledNext = (int)(size_t)sched_self->mScheduledHead;
                    sched_self->mScheduledHead = newSfx;
                    sched_self->mScheduledCount += 1;
                } else {
                    /* Invalid - free */
                    if (newSfx)
                        __ZdaPv(newSfx);
                }
            }
        }
    } else {
        /* Writing */
        int tmp = sched_self->mScheduledCount;
        FxArchive_WriteData(arch, &tmp, 4);

        /* Iterate linked list and archive each */
        {
            FxScheduler *sched = *(FxScheduler **)&imp_theFxScheduler;
            sfx = (ScheduledEffect *)(size_t)sched->mScheduledCount; /* head of list */
            while (sfx) {
                ScheduledEffect_Archive(sfx, arch);
                sfx = (ScheduledEffect *)(size_t)sfx->mScheduledNext;
            }
        }
    }
}

