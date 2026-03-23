/* ASM dump from: FxUtil.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxUtil.cpp */

#include "common_types.h"
#include "imports.h"
#include <math.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/EffectsCore/FxMemMgr.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/EffectsCore/FxPrimitives.h"
 *   #include "PC/EffectsCore/FxArchive.h"
 *   #include "PC/EffectsCore/FxScheduler.h"
 */

extern FxHelper *theFxHelper; /* 0x0 */
extern int g_effectVisArrayCount; /* 0x0 */
extern EffectVisInfo g_effectVisArray[1800]; /* 0x0 */
extern int effectActiveCountBolt; /* 0x0 */
extern int effectActiveCountNonBolt; /* 0x0 */
extern int privateEffectActiveCountBolt; /* 0x0 */
extern int privateEffectActiveCountNonBolt; /* 0x0 */
extern int initialEffectActiveCountBolt; /* 0x0 */
extern int initialEffectActiveCountNonBolt; /* 0x0 */
extern int cullEffectCountNonBolt; /* 0x0 */
extern int cullEffectCountBolt; /* 0x0 */
extern int visibleEffectCountNonBolt; /* 0x0 */
extern int visibleEffectCountBolt; /* 0x0 */
extern EffectCluster *effectClusters; /* 0x0 */
extern int effectClusterCount; /* 0x0 */
extern int *clusterSort; /* 0x0 */
extern Effect * *effectListBolt; /* 0x0 */
extern Effect * *effectListNonBolt; /* 0x0 */
extern int effectActiveCount; /* 0x0 */
extern int effectBlockSightCount; /* 0x0 */
extern FxHelper theFxHelpers[1]; /* 0x0 */
extern qboolean fxInitialized[1]; /* 0x0 */
static effectClusterArray_t effectClusterArray; /* effectClusterArray */
static effectListArray_t effectListArrayBolt; /* effectListArrayBolt */
static effectListArray_t effectListArrayNonBolt; /* effectListArrayNonBolt */
static SortedEffect visibleEffectsNonBolt[1800]; /* visibleEffectsNonBolt */
static SortedEffect visibleEffectsBolt[1800]; /* visibleEffectsBolt */

extern Bool FxHelper_IsMaterialRefractive(FxHelper *helper, MaterialHandle material);
extern void FxHelper_FxHelper(FxHelper *helper);
extern void Z_FreeInternal(void *ptr);
extern void *Z_MallocInternal(int size);
extern void __ZdaPv(void *ptr);
extern void Rand_Init(int seed);
extern void FxHelper_Trace(void *helper, void *trace, vec_t *start, vec_t *mins, vec_t *maxs, vec_t *end, int contents, int mask);
extern void AxisCopy(const vec_t *src, vec_t *dst);
extern void CG_GetDObjOrientation(int entityNum, void *axis);
extern void *Com_GetClientDObj(int entityNum, int localClientNum);
extern int DObjNumBones(void *dobj);
extern void CG_DObjCalcBoneGeneric(int entityNum, int localClientNum, int boneIndex);
extern void *DObjGetRotTransArray(void *dobj);
extern void MatrixMultiply(void *a, void *b, void *out);
extern void MatrixTransformVector43(void *trans, void *axis, void *out);
extern void *imp_fx_debugBolt;
extern void AxisTransformVector(void *axis, float x, float y, float z, vec_t *out);
extern void *imp_vec3_origin;
extern void *__Znam(int size);
extern float flrand(float min, float max);
extern void Particle_Particle(void *particle);
extern void Particle_IntegrateTotalVelocity(void *particle, int time, vec_t *velSum);
extern void Cloud_Cloud(void *cloud);
extern void Cylinder_Cylinder(void *cyl);
extern void Light_Light(void *light);
extern void *FxBoltFrame_GetOrientation(void *boltFrame);
extern void OrientationDirFromWorldDir(void *orient, vec_t *normal, vec_t *localNormal);
extern void FxScheduler_Clean(void *scheduler, int bRemoveTemplates, int arg3);
extern void *imp_fxSchedulers;
extern void *imp_theFxScheduler;
extern float Vec3DistanceSq(const vec_t *a, const vec_t *b);
extern float FxRange_GetVal(void *range);
extern void FxHelper_CameraShake(void *helper, vec_t *origin, float intensity, int duration, int fadeTime);
extern void *MediaHandles_GetEffect(void *mediaHandles);
extern void FxScheduler_PlayEffect(void *scheduler, void *effectTemplate, vec_t *origin, vec3_t *ax, void *bolt);
extern void FxScheduler_CreateDecalEffect(void *scheduler, void *primTemp, vec_t *origin, vec3_t *ax);
extern void FxScheduler_FxScheduler(void *scheduler);
extern void FX_InitTemplates(void);
extern void FxHelper_Init(void *helper);
extern void *imp_g_rendererExists;

void FX_InitServer(void);
static int CompareSortedEffects(const void *e0, const void *e1);
static int CompareSortedClusters(const void *e0, const void *e1);
void FX_SetSortGroup(Effect *fx);
int FX_GetCluster(const vec_t *origin);
void FX_CalcOrigin2(const PrimitiveTemplate *primTemp, vec_t *org, vec_t *org2, const vec_t *origin, vec3_t *ax);
Bool FX_GetBoneOrientation(const FxBoltInfo *bolt, orientation_t *orient);
void FX_AddScheduledEffects(const vec_t *start, const vec_t *end);
float FX_GetServerVisibility(const vec_t *start, const vec_t *end);
static void FX_CalcOriginAndAxis(vec_t *orgOut, vec3_t *ax);
static void FX_InitParticle(EffectPrimitive *prim, Particle *particle, vec_t *newOrigin, const vec_t *origin, vec3_t *ax, int indexInBatch);
void FX_AddCameraShake(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddFxRunner(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddDecal(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_DrawAll(void);
static void FX_SetMaterialAndSequenceParams(const int killTime, int indexInBatch);
static Bool FX_AddPrimitive(EffectPrimitive *prim, const vec_t *origin);
void FX_AddCloud(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddFlash(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddLight(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddCylinder(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddLine(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddTail(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddEmitter(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_AddOrientedParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch);
void FX_UpdateScheduledEffectsNonBolt(void);
void FX_UpdateScheduledEffectsBolt(void);
void FX_UpdateAllBolt(void);
void FX_Rewind(int time);
void FX_UpdateAllNonBolt(void);
void FX_DrawScheduledEffects(void);
int FX_Restore(MemoryFile *memFile);
int FX_Init(int rendererExists);
void FX_Free(int bRemoveTemplates);

/* line 340 */
void FX_InitServer(void)
{
    g_effectVisArrayCount = 0;
}

/* line 974 */
static int CompareSortedEffects(const void *e0, const void *e1)
{
    Effect *fx0 = *(Effect **)e0;
    Effect *fx1 = *(Effect **)e1;
    int result;

    result = fx0->mSortGroup - fx1->mSortGroup;
    if (result)
        return result;

    result = clusterSort[fx0->mClusterId] - clusterSort[fx1->mClusterId];
    if (result)
        return result;

    result = (int)(size_t)fx0->mRefEnt.customMaterial - (int)(size_t)fx1->mRefEnt.customMaterial;
    if (result)
        return result;

    return (((SortedEffect *)e1)->distSq > ((SortedEffect *)e0)->distSq) ? 1 : -1;
}

/* line 1001 */
static int CompareSortedClusters(const void *e0, const void *e1)
{
    float v1 = ((SortedCluster *)e1)->distSq;
    float v0 = ((SortedCluster *)e0)->distSq;
    return (v1 > v0) ? 1 : -1;
}

/* line 1549 */
void FX_SetSortGroup(Effect *fx)
{
    fx->mSortGroup = 0;
    if (fx->mRefEnt.customMaterial && FxHelper_IsMaterialRefractive(theFxHelper, fx->mRefEnt.customMaterial)) {
        fx->mSortGroup = -1;
    }
}

/* line 2306 */
static void __attribute__((constructor)) GLOBAL__I_effectClusters(void)
{
    FxHelper_FxHelper(theFxHelpers);
}

/* line 122 */
/* FX_GetCluster — find or create an effect cluster for the given origin */
extern float Vec3DistanceSq(const vec_t *a, const vec_t *b);
int FX_GetCluster(const vec_t *origin)
{
    int i;
    /* Search existing clusters for one within range (131072 distance squared) */
    for (i = 0; i < effectClusterCount; i++) {
        EffectCluster *cluster = &effectClusters[i];
        float distSq = Vec3DistanceSq(origin, cluster->origin);
        if (distSq < 131072.0f) {
            cluster->refCount += 1;
            return i;
        }
    }
    /* No nearby cluster — create a new one */
    {
        EffectCluster *newCluster = &effectClusters[effectClusterCount];
        newCluster->origin[0] = origin[0];
        newCluster->origin[1] = origin[1];
        newCluster->origin[2] = origin[2];
        newCluster->refCount = 1;
        return effectClusterCount++;
    }
}

/* FX_CalcOrigin2 — compute second endpoint for line/cylinder: range offset ± trace to surface */
void FX_CalcOrigin2(const PrimitiveTemplate *primTemp, vec_t *org, vec_t *org2, const vec_t *origin, vec3_t *ax)
{
    byte *pt = (byte *)primTemp;
    int flags = ((PrimitiveTemplate *)pt)->mSpawnFlags;

    if (flags & 0x08) {
        /* Project to infinity: temp = org + ax[0] * 16384 */
        float *axf = (float *)ax;
        vec3_t temp;
        temp[0] = org[0] + axf[0] * 16384.0f;
        temp[1] = org[1] + axf[1] * 16384.0f;
        temp[2] = org[2] + axf[2] * 16384.0f;

        if (flags & 0x20) {
            /* Add endpoint offset to temp */
            float z = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)pt)->mOrigin2Z);
            float y = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)pt)->mOrigin2Y);
            float x = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)pt)->mOrigin2X);
            if (flags & 0x80) {
                /* Axis-aligned offset added directly */
                org2[0] = x; org2[1] = y; org2[2] = z;
                temp[0] += x; temp[1] += y; temp[2] += z;
            } else {
                /* Transform offset through axis, add to temp */
                vec3_t point;
                AxisTransformVector(ax, x, y, z, point);
                temp[0] += point[0]; temp[1] += point[1]; temp[2] += point[2];
            }
        }

        /* Trace from org to temp */
        byte trace[0x44];
        FxHelper_Trace(*(byte **)imp_theFxHelper, trace, org, (vec_t *)imp_vec3_origin, (vec_t *)imp_vec3_origin, temp, -1, 1);
        float fraction = *(float *)trace;

        /* org2 = lerp(org, temp, fraction) */
        org2[0] = org[0] + (temp[0] - org[0]) * fraction;
        org2[1] = org[1] + (temp[1] - org[1]) * fraction;
        org2[2] = org[2] + (temp[2] - org[2]) * fraction;

        /* Play death effect at endpoint if flag 0x10 */
        if (flags & 0x10) {
            void *effect = MediaHandles_GetEffect(&((PrimitiveTemplate *)pt)->mImpactFxHandles);
            vec_t *traceNormal = (vec_t *)(trace + 0x24);
            FxScheduler_PlayEffect(*(void **)imp_theFxScheduler, effect, org2, (vec3_t *)traceNormal, NULL);
        }
    } else {
        /* No projectToInfinity: compute org2 from range values */
        float z = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)pt)->mOrigin2Z);
        float y = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)pt)->mOrigin2Y);
        float x = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)pt)->mOrigin2X);

        if (flags & 0x80) {
            /* Axis-aligned: org2 = {x,y,z} + origin */
            org2[0] = x; org2[1] = y; org2[2] = z;
        } else {
            /* Transform through axis */
            AxisTransformVector(ax, x, y, z, org2);
        }
        org2[0] += origin[0]; org2[1] += origin[1]; org2[2] += origin[2];
    }
}

/* FX_GetBoneOrientation — get bone transform from DObj, convert quat→matrix, apply to orientation */
extern void CG_GetDObjOrientation(int entityNum, void *axis);
extern void *Com_GetClientDObj(int entityNum, int localClientNum);
extern int DObjNumBones(void *dobj);
extern void CG_DObjCalcBoneGeneric(int entityNum, int localClientNum, int boneIndex);
extern void *DObjGetRotTransArray(void *dobj);
extern void MatrixMultiply(void *a, void *b, void *out);
extern void MatrixTransformVector43(void *trans, void *axis, void *out);
extern void *imp_fx_debugBolt;
Bool FX_GetBoneOrientation(const FxBoltInfo *bolt, orientation_t *orient)
{
    int entityNum = bolt->dobjHandle;
    int boneIndex = bolt->boneIndex;

    /* Get entity orientation (axis) */
    float axis[9];
    CG_GetDObjOrientation(entityNum, axis);

    if (boneIndex < 0) {
        /* No bone — just copy entity position from axis calc and axis itself */
        /* orient->origin = position from CG_GetDObjOrientation result */
        /* Actually the ASM copies from -0x54(%ebp) which is a local holding the position */
        /* For simplicity: copy axis to orient->axis, set orient position */
        float *oa = (float *)orient->axis; /* offset 0x0c */
        AxisCopy((vec_t *)axis, (vec_t *)oa);
        /* orient->origin already set by CG_GetDObjOrientation path */
        return 1;
    }

    /* Get DObj for bone */
    void *dobj = Com_GetClientDObj(entityNum, 0);
    if (!dobj) return 0;

    if (boneIndex >= DObjNumBones(dobj))
        return 0;

    /* Calculate bone transform */
    CG_DObjCalcBoneGeneric(entityNum, 0, boneIndex);
    byte *rotTransArray = (byte *)DObjGetRotTransArray(dobj);
    if (!rotTransArray) return 0;

    DObjAnimMat *mat = (DObjAnimMat *)rotTransArray + boneIndex;

    /* Convert quaternion to rotation matrix */
    float scale = mat->transWeight;
    float qx = mat->quat[0] * scale;
    float qy = mat->quat[1] * scale;
    float qz = mat->quat[2] * scale;
    float qw = mat->quat[3];

    float xx = qx * mat->quat[0];
    float xy = qx * mat->quat[1];
    float xz = qx * mat->quat[2];
    float xw = qx * qw;
    float yy = qy * mat->quat[1];
    float yz = qy * mat->quat[2];
    float yw = qy * qw;
    float zz = qz * mat->quat[2];
    float zw = qz * qw;

    float tagAxis[9];
    tagAxis[0] = 1.0f - (yy + zz);
    tagAxis[1] = zw + xy;
    tagAxis[2] = xz - yw;
    tagAxis[3] = xy - zw;
    tagAxis[4] = 1.0f - (xx + zz);
    tagAxis[5] = xw + yz;
    tagAxis[6] = yw + xz;
    tagAxis[7] = yz - xw;
    tagAxis[8] = 1.0f - (xx + yy);

    /* Multiply tagAxis by entity axis → orient->axis */
    MatrixMultiply(tagAxis, axis, (vec_t *)orient->axis);

    /* Transform bone position by entity axis → orient->origin */
    MatrixTransformVector43(mat->trans, axis, orient);

    /* Debug bolt: advance position along forward axis */
    float debugDist = *(float *)(*(byte *)imp_fx_debugBolt + 8);
    if (debugDist != 0.0f) {
        float *oo = (float *)orient;
        float *oaxis = (float *)orient->axis; /* offset 0x0c */
        oo[0] += oaxis[0] * debugDist;
        oo[1] += oaxis[1] * debugDist;
        oo[2] += oaxis[2] * debugDist;
    }

    return 1;
}

/* FX_AddScheduledEffects — walk scheduled effects linked list, dispatch due effects */
extern void Rand_Init(int seed);
extern void FxScheduler_CreateEffect(void *scheduler, void *fx, void *primTemp, void *origin, void *orient, void *ax, int lateTime, int indexInBatch);
void FX_AddScheduledEffects(const vec_t *start, const vec_t *end)
{
    (void)start; (void)end;
    if (!*(byte *)(*(int *)imp_fx_enable + 8))
        return;

    FxScheduler *sched = (FxScheduler *)imp_theFxScheduler;
    ScheduledEffect **prevNext = &sched->mScheduledHead;
    ScheduledEffect *sfx = *prevNext;

    while (sfx) {
        /* Check if effect is due */
        int startTime = sfx->mStartTime;
        int curTime = theFxHelper->mTime;
        if (startTime > curTime) {
            /* Not yet due — advance to next */
            prevNext = (ScheduledEffect **)&sfx->mScheduledNext;
            sfx = *prevNext;
            continue;
        }

        /* Get effect template and prim template */
        const EffectTemplate *fx = sfx->mFx;
        int primIndex = sfx->mPrimIndex;
        byte *primTemp = (byte *)fx->mPrimitives[primIndex];

        /* Init random seed */
        Rand_Init(sfx->mSeed);

        /* Unlink from list */
        *prevNext = (ScheduledEffect *)(size_t)sfx->mScheduledNext;
        sched->mScheduledCount -= 1;

        /* Dispatch effect */
        int boltEntity = sfx->mBolt.dobjHandle;
        int lateTime = curTime - startTime;
        int indexInBatch = sfx->mIndexInBatch;

        if (boltEntity >= 0) {
            /* Bolt-based: get bone orientation */
            orientation_t orient;
            Bool ok = FX_GetBoneOrientation(&sfx->mBolt, &orient);
            if (ok) {
                FxScheduler_CreateEffect(sched, (void *)fx, primTemp,
                    &sfx->mBolt, &orient, (byte *)&orient + 0xc,
                    lateTime, indexInBatch);
            }
        } else {
            /* Origin-based */
            FxScheduler_CreateEffect(sched, (void *)fx, primTemp,
                &sfx->mBolt, sfx->mOrigin, sfx->mAxis,
                lateTime, indexInBatch);
        }

        /* Free scheduled effect */
        if (sfx) __ZdaPv(sfx);

        /* Continue from prevNext (which now points to the next element) */
        sfx = *prevNext;
    }
}

/* line 636 */
/* FX_GetServerVisibility — ray vs effect visibility spheres, returns accumulated visibility */
extern void *imp_fx_visMinTraceDist;
extern float Vec3Normalize(vec_t *v);
float FX_GetServerVisibility(const vec_t *start, const vec_t *end)
{
    int count = g_effectVisArrayCount;
    if (count == 0)
        return 1.0f;

    /* Compute ray direction and length */
    vec3_t dir;
    dir[0] = end[0] - start[0];
    dir[1] = end[1] - start[1];
    dir[2] = end[2] - start[2];
    float len = Vec3Normalize(dir);

    /* Check minimum trace distance */
    float minDist = *(float *)(*(byte *)imp_fx_visMinTraceDist + 8);
    if (len < minDist)
        return 1.0f;

    float halfLen = len * 0.5f;
    float visibility = 1.0f;

    /* Test each visibility sphere */
    int i;
    for (i = 0; i < count; i++) {
        EffectVisInfo *vis = &g_effectVisArray[i];
        /* Project vis center onto ray */
        float dx = vis->origin[0] - start[0];
        float dy = vis->origin[1] - start[1];
        float dz = vis->origin[2] - start[2];
        float t = dx * dir[0] + dy * dir[1] + dz * dir[2];

        /* Check if projection is within ray bounds (within halfLen of center) */
        float absDist = t - halfLen;
        if (absDist < 0) absDist = -absDist;
        if (absDist > halfLen)
            continue;

        /* Compute closest point on ray */
        vec3_t projPt;
        projPt[0] = start[0] + dir[0] * t;
        projPt[1] = start[1] + dir[1] * t;
        projPt[2] = start[2] + dir[2] * t;

        /* Check distance to sphere */
        float distSq = Vec3DistanceSq(vis->origin, projPt);
        if (distSq >= vis->distSq)
            continue;

        /* Apply visibility attenuation */
        visibility *= vis->vis;
    }
    return visibility;
}

/* FX_CalcOriginAndAxis — register convention: eax=prim, edx=orgOut, stack=ax
 * Computes random origin offset based on distribution flags, optionally transforms via bolt */
extern float sinf(float x);
extern float cosf(float x);
extern void RotatePointAroundVector(vec_t *dst, const vec_t *dir, const vec_t *point, float degrees);
extern void Vec3Cross(const vec_t *a, const vec_t *b, vec_t *out);
extern void MakeNormalVectors(const vec_t *forward, vec_t *right, vec_t *up);
extern void AxisTransformVector(void *axis, float x, float y, float z, vec_t *out);
extern void OrientationPosFromWorldPos(void *orient, vec_t *worldPos, vec_t *localPos);
static void FX_CalcOriginAndAxis_impl(byte *prim, vec_t *orgOut, vec3_t *ax)
{
    byte *primTemp = (byte *)((EffectPrimitive *)prim)->primTemp;
    const vec_t *origin = (const vec_t *)((byte *)prim + 4); /* prim origin used as fallback — actually ecx on entry */
    /* Note: ecx=origin was the 3rd register arg in the original ASM.
     * In the callers, origin is at stack[8(%ebp)] which is pushed separately.
     * For this _impl, we don't receive origin directly.
     * Looking at the ASM: %ebx = origin (from ecx), used for adding to org.
     * We'll receive it from the callers via inline ASM which passes ecx. */

    vec3_t up = {0.0f, 0.0f, 1.0f};
    int flags = ((PrimitiveTemplate *)primTemp)->mSpawnFlags;
    vec3_t org;

    /* Compute origin offset from range values */
    if (flags & 0x40) {
        /* Axis-aligned offset */
        float z = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)primTemp)->mOrigin1Z);
        float y = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)primTemp)->mOrigin1Y);
        float x = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)primTemp)->mOrigin1X);
        org[0] = x; org[1] = y; org[2] = z;
    } else {
        /* Transform offset through axis */
        float z = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)primTemp)->mOrigin1Z);
        float y = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)primTemp)->mOrigin1Y);
        float x = FxRange_GetVal((FxRange *)&((PrimitiveTemplate *)primTemp)->mOrigin1X);
        AxisTransformVector(ax, x, y, z, org);
    }

    /* The origin base is added here — but we need the 'origin' param from ecx.
     * For now, orgOut will receive the offset. The caller adds the base. */
    orgOut[0] = org[0];
    orgOut[1] = org[1];
    orgOut[2] = org[2];

    /* Distribution adjustments based on flags */
    if (flags & 1) {
        /* Sphere distribution: random angles, compute point on sphere */
        float phi = flrand(0.0f, 360.0f) * 0.017453292f;
        float sinPhi = sinf(phi);
        float cosPhi = cosf(phi);
        float theta = flrand(0.0f, 180.0f) * 0.017453292f;
        float sinTheta = sinf(theta);
        float cosTheta = cosf(theta);
        float width = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mRadius);
        float height = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mHeight);
        vec3_t pt;
        pt[0] = sinPhi * width * sinTheta;
        pt[1] = cosPhi * width * sinTheta;
        pt[2] = height * cosTheta;
        org[0] += pt[0]; org[1] += pt[1]; org[2] += pt[2];
        orgOut[0] = org[0]; orgOut[1] = org[1]; orgOut[2] = org[2];

        if (flags & 2) {
            /* Normalize direction and set as new axis */
            float len2 = pt[0]*pt[0] + pt[1]*pt[1] + pt[2]*pt[2];
            float len;
            len = sqrtf(len2);
            if (len != 0.0f) {
                float invLen = 1.0f / len;
                ((float *)ax)[0] = pt[0] * invLen;
                ((float *)ax)[1] = pt[1] * invLen;
                ((float *)ax)[2] = pt[2] * invLen;
                /* Build tangent frame */
                MakeNormalVectors((vec_t *)ax, ((vec_t *)ax) + 3, ((vec_t *)ax) + 6);
            }
        }
    } else if (flags & 4) {
        /* Cylinder distribution */
        float rndHeight = flrand(-0.5f, 0.5f);
        float height = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mHeight);
        float width = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mRadius);
        /* pt = ax[1] * width, offset by rndHeight*height along ax[0] */
        vec3_t pt;
        float *axf = (float *)ax;
        pt[0] = axf[3] * width + axf[0] * rndHeight * height;
        pt[1] = axf[4] * width + axf[1] * rndHeight * height;
        pt[2] = axf[5] * width + axf[2] * rndHeight * height;
        /* Rotate around ax[0] by random angle */
        float angle = flrand(0.0f, 360.0f);
        vec3_t rotated;
        RotatePointAroundVector(rotated, (vec_t *)ax, pt, angle);
        org[0] += rotated[0]; org[1] += rotated[1]; org[2] += rotated[2];
        orgOut[0] = org[0]; orgOut[1] = org[1]; orgOut[2] = org[2];

        if (flags & 2) {
            float len2 = rotated[0]*rotated[0] + rotated[1]*rotated[1] + rotated[2]*rotated[2];
            float len;
            len = sqrtf(len2);
            if (len != 0.0f) {
                float invLen = 1.0f / len;
                ((float *)ax)[0] = rotated[0] * invLen;
                ((float *)ax)[1] = rotated[1] * invLen;
                ((float *)ax)[2] = rotated[2] * invLen;
                float absZ = ((float *)ax)[2]; if (absZ < 0) absZ = -absZ;
                if (absZ >= 0.999f) { up[0] = 0; up[1] = 1; up[2] = 0; }
                float *axf2 = (float *)ax;
                Vec3Cross((vec_t *)ax, up, (vec_t *)(axf2 + 3));
                Vec3Normalize((vec_t *)(axf2 + 3));
                Vec3Cross((vec_t *)ax, (vec_t *)(axf2 + 3), (vec_t *)(axf2 + 6));
            }
        }
    }

    /* If bolt exists, transform from world to local */
    byte *bolt = (byte *)&((EffectPrimitive *)prim)->boltFrame;
    if (bolt) {
        void *orient = FxBoltFrame_GetOrientation(bolt);
        vec3_t localOrg;
        OrientationPosFromWorldPos(orient, orgOut, localOrg);
        orgOut[0] = localOrg[0]; orgOut[1] = localOrg[1]; orgOut[2] = localOrg[2];
    }
}
static void FX_CalcOriginAndAxis(vec_t *orgOut, vec3_t *ax) { (void)orgOut; (void)ax; }

/* FX_InitParticle — register convention: eax=prim, edx=particle, ecx=newOrigin, stack: origin, ax, indexInBatch */
extern void AxisTransformVector(void *axis, float x, float y, float z, vec_t *out);
extern void OrientationPosFromWorldPos(void *orient, vec_t *worldPos, vec_t *localPos);
extern void Particle_SetRandomVelocityWeights(void *particle, float w0, float w1, float w2);
extern void Particle_SetRandomVelocity2Weights(void *particle, float w0, float w1, float w2);
extern void Particle_SetAxis(void *particle, vec3_t *ax);
static void FX_InitParticle_impl(byte *prim, byte *particle, vec_t *newOrigin, const vec_t *origin, vec3_t *ax, int indexInBatch)
{
    (void)indexInBatch;
    byte *primTemp = (byte *)((EffectPrimitive *)prim)->primTemp;
    int flags = ((PrimitiveTemplate *)primTemp)->mAttributeFlags;

    /* Random blend weights based on flags */
    if (flags & 0x2000) ((Particle *)particle)->blendWeight[0] = flrand(0.0f, 1.0f);
    if (flags & 0x4000) ((Particle *)particle)->blendWeight[1] = flrand(0.0f, 1.0f);
    if ((short)flags < 0) ((Particle *)particle)->blendWeight[2] = flrand(0.0f, 1.0f); /* bit 15 */
    if (flags & 0x10000) ((Particle *)particle)->blendWeight[3] = flrand(0.0f, 1.0f);
    if (flags & 0x40000) ((Particle *)particle)->blendWeight[4] = flrand(0.0f, 1.0f);
    if (flags & 0x80000) {
        Particle_SetRandomVelocityWeights(particle, flrand(0,1), flrand(0,1), flrand(0,1));
    }
    if (flags & 0x100000) {
        Particle_SetRandomVelocity2Weights(particle, flrand(0,1), flrand(0,1), flrand(0,1));
    }

    /* Range values */
    ((Particle *)particle)->gravity = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mGravity);
    ((Particle *)particle)->windModifier = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mWindModifier);

    /* Calculate origin and set axis */
    FX_CalcOriginAndAxis_impl(prim, newOrigin, ax);
    Particle_SetAxis(particle, ax);

    /* Copy primTemp fields to particle */
    ((Particle *)particle)->nonUniformScale = ((PrimitiveTemplate *)primTemp)->mNonUniformScale;
    ((Particle *)particle)->elasticity = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mElasticity);
    ((Effect *)particle)->mRefEnt.origin[1] = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mRotation);  /* size */
}
static void FX_InitParticle(EffectPrimitive *prim, Particle *particle, vec_t *newOrigin, const vec_t *origin, vec3_t *ax, int indexInBatch) { (void)prim; (void)particle; (void)newOrigin; (void)origin; (void)ax; (void)indexInBatch; }

/* line 1958 */
/* FX_AddCameraShake — calculate shake parameters and apply camera shake */
extern float FxRange_GetVal(void *range);
extern void FxHelper_CameraShake(void *helper, vec_t *origin, float intensity, int duration, int fadeTime);
void FX_AddCameraShake(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)origin; (void)lateTime; (void)indexInBatch;
    vec3_t newOrigin;
    FX_CalcOriginAndAxis_impl((byte *)prim, newOrigin, ax);
    byte *primTemp = (byte *)prim->primTemp;
    float duration = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mLife);
    float fadeTime = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mRadius);
    float intensity = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mElasticity);
    FxHelper_CameraShake(theFxHelper, newOrigin, intensity, (int)duration, (int)fadeTime);
}

/* FX_AddFxRunner — spawn runner effect at calculated origin */
extern void *MediaHandles_GetEffect(void *mediaHandles);
extern void FxScheduler_PlayEffect(void *scheduler, void *effectTemplate, vec_t *origin, vec3_t *ax, void *bolt);
void FX_AddFxRunner(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)origin; (void)lateTime; (void)indexInBatch;
    vec3_t newOrigin;
    FX_CalcOriginAndAxis_impl((byte *)prim, newOrigin, ax);
    byte *primTemp = (byte *)prim->primTemp;
    FxBoltFrame *bolt = (FxBoltFrame *)(size_t)prim->boltFrame._placeholder;
    void *effect = MediaHandles_GetEffect(&((PrimitiveTemplate *)primTemp)->mPlayFxHandles);
    void *scheduler = *(void **)imp_theFxScheduler;
    if (bolt) {
        FxScheduler_PlayEffect(scheduler, effect, newOrigin, NULL, &bolt->mBolt);
    } else {
        FxScheduler_PlayEffect(scheduler, effect, newOrigin, ax, NULL);
    }
}

/* line 1928 */
/* FX_AddDecal — create decal effect at calculated origin */
extern void *imp_theFxScheduler;
extern void FxScheduler_CreateDecalEffect(void *scheduler, void *primTemp, vec_t *origin, vec3_t *ax);
void FX_AddDecal(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)origin; (void)lateTime; (void)indexInBatch;
    vec3_t newOrigin;
    /* FX_CalcOriginAndAxis: register convention eax=prim, edx=orgOut, stack=ax */
    FX_CalcOriginAndAxis_impl((byte *)prim, newOrigin, ax);
    FxScheduler_CreateDecalEffect(*(void **)imp_theFxScheduler, (void *)prim->primTemp, newOrigin, ax);
}

/* FX_DrawAll — cull, sort, draw all visible effects */
extern void *imp_fx_sort;
extern void *imp_fx_draw;
extern void *imp_fx_debug;
extern void FX_Print(const char *fmt, ...);
extern void qsort(void *base, int nmemb, int size, void *cmp);
extern int CompareSortedClusters(const void *a, const void *b);
void FX_DrawAll(void)
{
    typedef void (*DrawFn)(void *);
    typedef Bool (*CullFn)(void *);
    int i;

    /* Phase 1: Cull non-bolt effects that haven't been culled yet */
    if (*(int *)imp_fx_camera_valid) {
        for (i = cullEffectCountNonBolt; i < privateEffectActiveCountNonBolt; i++) {
            byte *eff = ((byte **)effectListNonBolt)[i];
            if (*(byte *)(*(int *)imp_fx_cull + 8)) {
                if (((CullFn)(*(void ***)eff)[4])(eff)) continue;
            }
            int idx = visibleEffectCountNonBolt;
            ((void **)visibleEffectsNonBolt)[idx * 2] = eff;
            float dist = Vec3DistanceSq((vec_t *)&((Effect *)eff)->mRefEnt.origin, theFxHelper->mCamera.vieworg);
            *(float *)((byte *)visibleEffectsNonBolt + idx * 8 + 4) = dist;
            visibleEffectCountNonBolt++;
        }
        cullEffectCountNonBolt = privateEffectActiveCountNonBolt;
    }

    /* Phase 2: Cull bolt effects */
    for (i = cullEffectCountBolt; i < privateEffectActiveCountBolt; i++) {
        byte *eff = ((byte **)effectListBolt)[i];
        if (*(byte *)(*(int *)imp_fx_cull + 8)) {
            if (((CullFn)(*(void ***)eff)[4])(eff)) continue;
        }
        int idx = visibleEffectCountBolt;
        ((void **)visibleEffectsBolt)[idx * 2] = eff;
        float dist = Vec3DistanceSq((vec_t *)&((Effect *)eff)->mRefEnt.origin, theFxHelper->mCamera.vieworg);
        *(float *)((byte *)visibleEffectsBolt + idx * 8 + 4) = dist;
        visibleEffectCountBolt++;
    }
    cullEffectCountBolt = privateEffectActiveCountBolt;

    /* Merge bolt visible into non-bolt visible array */
    for (i = 0; i < visibleEffectCountBolt; i++) {
        int dst = visibleEffectCountNonBolt;
        ((void **)visibleEffectsNonBolt)[dst * 2] = ((void **)visibleEffectsBolt)[i * 2];
        *(float *)((byte *)visibleEffectsNonBolt + dst * 8 + 4) = *(float *)((byte *)visibleEffectsBolt + i * 8 + 4);
        visibleEffectCountNonBolt++;
    }

    /* Phase 3: Update visibility for sight-blocking effects */
    g_effectVisArrayCount = 0;
    if (effectBlockSightCount > 0) {
        for (i = 0; i < effectActiveCountNonBolt; i++) {
            byte *eff = ((byte **)effectListNonBolt)[i];
            if (((byte *)&((Effect *)eff)->mFlags)[1] & 0x10)
                ((DrawFn)(*(void ***)eff)[7])(eff); /* AddVisibility */
        }
        for (i = 0; i < effectActiveCountBolt; i++) {
            byte *eff = ((byte **)effectListBolt)[i];
            if (((byte *)&((Effect *)eff)->mFlags)[1] & 0x10)
                ((DrawFn)(*(void ***)eff)[7])(eff);
        }
    }

    /* Phase 4: Sort effects by cluster distance */
    if (*(byte *)(*(int *)imp_fx_sort + 8)) {
        int effectCount = visibleEffectCountNonBolt;
        /* Build sorted cluster array */
        byte sortedClusters[1800 * 8]; /* {clusterId, distSq} pairs */
        for (i = 0; i < effectClusterCount; i++) {
            *(int *)(sortedClusters + i * 8) = i;
            float dist = Vec3DistanceSq((vec_t *)((byte *)effectClusters + i * 16), theFxHelper->mCamera.vieworg);
            *(float *)(sortedClusters + i * 8 + 4) = dist;
        }
        qsort(sortedClusters, effectClusterCount, 8, CompareSortedClusters);
        /* Build sortOrder lookup */
        int sortOrder[1800];
        for (i = 0; i < effectClusterCount; i++) {
            int cid = *(int *)(sortedClusters + i * 8);
            sortOrder[cid] = i;
        }
        clusterSort = sortOrder;
        qsort(visibleEffectsNonBolt, effectCount, 8, CompareSortedEffects);
        clusterSort = NULL;
    }

    /* Phase 5: Draw visible effects */
    if (*(byte *)(*(int *)imp_fx_draw + 8)) {
        for (i = 0; i < visibleEffectCountNonBolt; i++) {
            byte *eff = ((byte **)visibleEffectsNonBolt)[i * 2];
            ((DrawFn)(*(void ***)eff)[5])(eff); /* Draw */
        }
    }

    /* Phase 6: Debug display */
    if (*(byte *)(*(int *)imp_fx_debug + 8)) {
        FX_Print("Active    FX: %i\n", effectActiveCount);
        FX_Print("Drawn     FX: %i\n", visibleEffectCountNonBolt);
        FX_Print("Scheduled FX: %i\n", *(int *)(*(byte **)imp_theFxScheduler + 8));
    }
}

/* line 1557 */
/* FX_SetMaterialAndSequenceParams — register convention: eax=primTemp, edx=particle, ecx=killTime, stack: indexInBatch */
extern void *MediaHandles_GetHandle(void *mediaHandles);
extern int FxHelper_GetMaterialSubimageCount(void *helper, void *material);
extern int irand(int min, int max);
static void FX_SetMaterialAndSequenceParams_impl(byte *primTemp, byte *particle, int killTime, int indexInBatch)
{
    void *material = MediaHandles_GetHandle(&((PrimitiveTemplate *)primTemp)->mMediaHandles);
    int startFrame = 0;
    float frameRate = 0.0f;

    if (material) {
        int subimageCount = FxHelper_GetMaterialSubimageCount(theFxHelper, material);
        if (subimageCount == 1) {
            startFrame = 0;
            frameRate = 0.0f;
        } else {
            /* Determine start frame based on sequence mode */
            int seqMode = ((PrimitiveTemplate *)primTemp)->mSequenceStartFrameMode;
            if (seqMode == 0) {
                startFrame = ((PrimitiveTemplate *)primTemp)->mSequenceFixedFrameValue - 1;
            } else if (seqMode == 1) {
                startFrame = irand(0, subimageCount);
            } else if (seqMode == 2) {
                startFrame = indexInBatch;
            } else {
                startFrame = 0;
            }
            /* Determine frame rate */
            int rateMode = ((PrimitiveTemplate *)primTemp)->mSequencePlayRateMode;
            if (rateMode == 0) {
                frameRate = ((PrimitiveTemplate *)primTemp)->mSequenceFixedFpsValue / 1000.0f;
            } else if (rateMode == 1) {
                frameRate = (float)subimageCount / (float)killTime;
            } else {
                frameRate = 0.0f;
            }
        }
    }

    ((Particle *)particle)->startFrame = startFrame;
    ((Particle *)particle)->frameRate = frameRate;
    ((Particle *)particle)->sequenceLoopMode = ((PrimitiveTemplate *)primTemp)->mSequenceLoopMode;
    ((Particle *)particle)->sequenceLoopTimes = ((PrimitiveTemplate *)primTemp)->mSequenceLoopTimes;
    *(void **)&((Effect *)particle)->mRefEnt.origin[0] = material;
    ((Effect *)particle)->mSortGroup = 0;

    if (material && FxHelper_IsMaterialRefractive(theFxHelper, (MaterialHandle)material))
        ((Effect *)particle)->mSortGroup = -1;
}

static void FX_SetMaterialAndSequenceParams(const int killTime, int indexInBatch) { }

/* FX_AddPrimitive — register convention: eax=prim, edx=particle, ecx=origin
 * Adds particle to effect system: manages active count, assigns cluster, stores in bolt/nonbolt list */
extern void Effect_SetTimeStartEnd(void *effect, int startTime, int endTime);
extern void Effect_SetBoltFrame(const void *effect, const void *boltFramePtr);
static Bool FX_AddPrimitive_impl(byte *prim, byte *particle, const vec_t *origin)
{
    byte *primTemp = (byte *)((EffectPrimitive *)prim)->primTemp;
    byte *boltInfo = (byte *)&((EffectPrimitive *)prim)->boltFrame;

    /* Check active count limit */
    int slot;
    if (boltInfo) {
        slot = effectActiveCount + 1;
        effectActiveCount = slot;
        if (slot > 1800) {
            effectActiveCount = slot - 1;
            /* Find cluster and try to add anyway via bolt list */
            goto find_cluster;
        }
        int boltSlot = effectActiveCountBolt;
        effectActiveCountBolt = boltSlot + 1;
        ((byte **)effectListBolt)[boltSlot] = particle;
    } else {
        slot = effectActiveCount + 1;
        effectActiveCount = slot;
        if (slot > 1800) {
            effectActiveCount = slot - 1;
            goto find_cluster;
        }
        int nbSlot = effectActiveCountNonBolt;
        effectActiveCountNonBolt = nbSlot + 1;
        ((byte **)effectListNonBolt)[nbSlot] = particle;
    }

find_cluster:;
    /* Assign cluster */
    int clusterId = FX_GetCluster(origin);

    /* Check if blocksSight */
    if (((PrimitiveTemplate *)primTemp)->mAttributeFlags & 0x1000)
        effectBlockSightCount++;

    /* Store effect reference in particle */
    *(byte **)(particle) = (byte *)prim; /* vtable set by constructor, skip */

    /* Set flags from primTemp */
    ((Effect *)particle)->mFlags = ((PrimitiveTemplate *)primTemp)->mAttributeFlags;

    /* Set start/end time */
    int curTime = theFxHelper->mTime;
    float lifeRange = FxRange_GetVal(&((PrimitiveTemplate *)primTemp)->mLife);
    int endTime = curTime + (int)lifeRange;
    Effect_SetTimeStartEnd(particle, curTime, endTime);

    /* Copy effect template references */
    *(int *)&((Effect *)particle)->mRefEnt.dlightColor[2] = *(int *)prim; /* effect template */
    *(int *)&((Effect *)particle)->mRefEnt.materialTime = ((PrimitiveTemplate *)primTemp)->mParentPrimIndex;
    *(int *)&((Effect *)particle)->mRefEnt.axis[0][1] = ((PrimitiveTemplate *)primTemp)->mGroupFlags;

    /* Copy min/max from primTemp */
    ((Effect *)particle)->mRefEnt.axis[0][2] = ((PrimitiveTemplate *)primTemp)->mMin[0]; /* TODO: particle subclass fields 0x14-0x28 */
    ((Effect *)particle)->mRefEnt.axis[1][0] = ((PrimitiveTemplate *)primTemp)->mMin[1];
    ((Effect *)particle)->mRefEnt.axis[1][1] = ((PrimitiveTemplate *)primTemp)->mMin[2];
    ((Effect *)particle)->mRefEnt.axis[1][2] = ((PrimitiveTemplate *)primTemp)->mMax[0];
    ((Effect *)particle)->mRefEnt.axis[2][0] = ((PrimitiveTemplate *)primTemp)->mMax[1];
    ((Effect *)particle)->mRefEnt.axis[2][1] = ((PrimitiveTemplate *)primTemp)->mMax[2];

    /* Get effects from MediaHandles */
    *(void **)&((Effect *)particle)->mRefEnt.dlightColor[1] = MediaHandles_GetEffect(&((PrimitiveTemplate *)primTemp)->mDeathFxHandles); /* emit effect */
    *(void **)&((Effect *)particle)->mRefEnt.dlightColor[0] = MediaHandles_GetEffect(&((PrimitiveTemplate *)primTemp)->mImpactFxHandles); /* death effect */

    /* Call vtable CreateChannelInstances */
    typedef void (*CreateChFn)(void *, void *);
    ((CreateChFn)(*(void ***)particle)[8])(particle, primTemp);

    /* Set bolt frame */
    byte *boltFramePtr = prim + 8;
    Effect_SetBoltFrame((const Effect *)particle, (FxBoltFramePtr *)boltFramePtr);

    /* Store cluster */
    ((Effect *)particle)->mClusterId = clusterId;

    return 1;
}
static Bool FX_AddPrimitive(EffectPrimitive *prim, const vec_t *origin) { (void)prim; (void)origin; return 0; }

/* line 2102 */
/* FX_AddCloud — allocate Cloud, add to system, init, set material, late time, extra cloud setup */
extern void Cloud_Cloud(void *cloud);
void FX_AddCloud(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    byte *p = (byte *)__Znam(0x27c);
    if (p) memset(p, 0, 0x27c);
    Cloud_Cloud(p);
    if (!p) return;
    int added;
    added = FX_AddPrimitive_impl((byte *)prim, (byte *)p, (const vec_t *)origin);
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
    FX_InitParticle_impl((byte *)prim, (byte *)p, newOrigin, (const vec_t *)origin, ax, indexInBatch);
    byte *primTemp = (byte *)prim->primTemp;
    int killTime = ((Effect *)p)->mTimeEnd - ((Effect *)p)->mTimeStart;
    FX_SetMaterialAndSequenceParams_impl(primTemp, p, killTime, indexInBatch);
    if (lateTime > 0) {
        float dt = (float)lateTime * 0.001f;
        vec3_t velSum;
        Particle_IntegrateTotalVelocity(p, lateTime, velSum);
        newOrigin[0] += velSum[0] * dt; newOrigin[1] += velSum[1] * dt; newOrigin[2] += velSum[2] * dt;
    }
    *(float *)&((Effect *)p)->mRefEnt.customMaterial = newOrigin[0]; ((Effect *)p)->mRefEnt.rotation = newOrigin[1]; ((Effect *)p)->mRefEnt.axis[0][0] = newOrigin[2];
    ((Cloud *)p)->randomLengthBlend = flrand(0.0f, 1.0f);
    *(byte *)&((Cloud *)p)->lengthBlendFactor = ((PrimitiveTemplate *)primTemp)->useLength; /* TODO: subclass field at 0x25c */
}

/* line 2063 */
/* FX_AddFlash — allocate Flash (Light subclass), add, set material+origin, call Flash_Init */
extern void *imp__ZTV5Flash;
extern void Flash_Init(void *flash);
void FX_AddFlash(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)ax; (void)lateTime; (void)indexInBatch;
    byte *p = (byte *)__Znam(0xfc);
    if (p) memset(p, 0, 0xfc);
    Light_Light(p);
    /* Set Flash vtable */
    *(void **)p = (byte *)imp__ZTV5Flash + 8;

    int added;
    added = FX_AddPrimitive_impl((byte *)prim, (byte *)p, (const vec_t *)origin);
    if (!(byte)added) {
        /* Call destructor via vtable[1] */
        typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p);
        return;
    }

    byte *primTemp = (byte *)prim->primTemp;
    void *material = MediaHandles_GetHandle(&((PrimitiveTemplate *)primTemp)->mMediaHandles);

    /* Copy origin to p+4 */
    if (origin) {
        *(float *)&((Effect *)p)->mRefEnt.customMaterial = origin[0]; ((Effect *)p)->mRefEnt.rotation = origin[1]; ((Effect *)p)->mRefEnt.axis[0][0] = origin[2];
    } else {
        *(float *)&((Effect *)p)->mRefEnt.customMaterial = 0; ((Effect *)p)->mRefEnt.rotation = 0; ((Effect *)p)->mRefEnt.axis[0][0] = 0;
    }

    *(void **)&((Effect *)p)->mRefEnt.origin[0] = material;

    /* Check flags for random weight */
    if (((PrimitiveTemplate *)primTemp)->mAttributeFlags & 0x2000)
        ((Light *)p)->colorBlendFactor = flrand(0.0f, 1.0f);

    /* Set refractive flag */
    ((Effect *)p)->mSortGroup = 0;
    if (material && FxHelper_IsMaterialRefractive(theFxHelper, (MaterialHandle)material))
        ((Effect *)p)->mSortGroup = -1;

    Flash_Init(p);
}

/* line 1978 */
/* FX_AddLight — allocate Light, add to effect system, set origin + random weights */
extern void Light_Light(void *light);
extern float flrand(float min, float max);
extern void *__Znam(int size);
void FX_AddLight(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)lateTime; (void)indexInBatch;
    byte *light = (byte *)__Znam(0xfc);
    if (light) memset(light, 0, 0xfc);
    Light_Light(light);
    if (!light) return;

    /* FX_AddPrimitive: register eax=prim, edx=particle, ecx=origin */
    int added;
    added = FX_AddPrimitive_impl((byte *)prim, light, (const vec_t *)origin);
    if (!(byte)added) {
        typedef void (*Fn)(void *); ((Fn)(*(void ***)light)[1])(light);
        return;
    }

    /* FX_CalcOriginAndAxis: eax=prim, edx=orgOut, stack=ax */
    vec3_t newOrigin;
    FX_CalcOriginAndAxis_impl((byte *)prim, newOrigin, ax);
    *(float *)&((Effect *)light)->mRefEnt.customMaterial = newOrigin[0];
    ((Effect *)light)->mRefEnt.rotation = newOrigin[1];
    ((Effect *)light)->mRefEnt.axis[0][0] = newOrigin[2];

    byte *primTemp = (byte *)prim->primTemp;
    int flags = ((PrimitiveTemplate *)primTemp)->mAttributeFlags;
    if (flags & 0x2000) /* bit 13 */
        ((Light *)light)->colorBlendFactor = flrand(0.0f, 1.0f);
    if ((short)flags < 0) /* bit 15 */
        ((Light *)light)->sizeBlendFactor = flrand(0.0f, 1.0f);
}

/* FX_AddCylinder — allocate Cylinder, add, init, set material, copy normal/origin */
extern void Cylinder_Cylinder(void *cyl);
extern void *FxBoltFrame_GetOrientation(void *boltFrame);
extern void OrientationDirFromWorldDir(void *orient, vec_t *normal, vec_t *localNormal);
void FX_AddCylinder(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)lateTime;
    byte *p = (byte *)__Znam(0x278);
    if (p) memset(p, 0, 0x278);
    Cylinder_Cylinder(p);
    if (!p) return;
    int added;
    added = FX_AddPrimitive_impl((byte *)prim, (byte *)p, (const vec_t *)origin);
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
    FX_InitParticle_impl((byte *)prim, (byte *)p, newOrigin, (const vec_t *)origin, ax, indexInBatch);
    int killTime = ((Effect *)p)->mTimeEnd - ((Effect *)p)->mTimeStart;
    FX_SetMaterialAndSequenceParams_impl((byte *)prim->primTemp, p, killTime, indexInBatch);

    /* Copy normal to cylinder axis at p+0x48 */
    vec3_t normal;
    normal[0] = ((float *)ax)[0]; normal[1] = ((float *)ax)[1]; normal[2] = ((float *)ax)[2];
    FxBoltFrame *bolt = (FxBoltFrame *)(size_t)prim->boltFrame._placeholder;
    if (bolt) {
        /* Transform normal via bolt orientation */
        void *orient = FxBoltFrame_GetOrientation(bolt);
        vec3_t localNormal;
        OrientationDirFromWorldDir(orient, normal, localNormal);
        ((Effect *)p)->mRefEnt.radius[0] = localNormal[0]; ((Effect *)p)->mRefEnt.radius[1] = localNormal[1]; *(float *)&((Effect *)p)->mRefEnt.materialRGBA = localNormal[2];
    } else {
        ((Effect *)p)->mRefEnt.radius[0] = normal[0]; ((Effect *)p)->mRefEnt.radius[1] = normal[1]; *(float *)&((Effect *)p)->mRefEnt.materialRGBA = normal[2];
    }
    *(float *)&((Effect *)p)->mRefEnt.customMaterial = newOrigin[0]; ((Effect *)p)->mRefEnt.rotation = newOrigin[1]; ((Effect *)p)->mRefEnt.axis[0][0] = newOrigin[2];
}

/* FX_AddLine — allocate Line, add to system, calc origin+endpoint, set material+flags */
extern void Line_Line(void *line);
extern void Particle_SetAxis(void *particle, vec3_t *ax);
extern void OrientationPosFromWorldPos(void *orient, vec_t *worldPos, vec_t *localPos);
void FX_AddLine(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)lateTime; (void)indexInBatch;
    byte *p = (byte *)__Znam(0x258);
    if (p) memset(p, 0, 0x258);
    Line_Line(p);
    if (!p) return;

    int added;
    added = FX_AddPrimitive_impl((byte *)prim, (byte *)p, (const vec_t *)origin);
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }

    /* Calc origin */
    vec3_t newOrigin;
    FX_CalcOriginAndAxis_impl((byte *)prim, newOrigin, ax);

    Particle_SetAxis(p, ax);

    /* Calc second endpoint */
    byte *primTemp = (byte *)prim->primTemp;
    vec3_t org2;
    FX_CalcOrigin2((const PrimitiveTemplate *)primTemp, newOrigin, org2, origin, ax);

    /* Get material */
    void *material = MediaHandles_GetHandle(&((PrimitiveTemplate *)primTemp)->mMediaHandles);

    /* Copy endpoint — transform via bolt if present */
    FxBoltFrame *bolt = (FxBoltFrame *)(size_t)prim->boltFrame._placeholder;
    if (bolt) {
        void *orient = FxBoltFrame_GetOrientation(bolt);
        vec3_t localEnd;
        OrientationPosFromWorldPos(orient, org2, localEnd);
        ((Tail *)p)->endpoint[0] = localEnd[0]; ((Tail *)p)->endpoint[1] = localEnd[1]; ((Tail *)p)->endpoint[2] = localEnd[2];
    } else {
        ((Tail *)p)->endpoint[0] = org2[0]; ((Tail *)p)->endpoint[1] = org2[1]; ((Tail *)p)->endpoint[2] = org2[2];
    }

    /* Copy origin */
    *(float *)&((Effect *)p)->mRefEnt.customMaterial = newOrigin[0]; ((Effect *)p)->mRefEnt.rotation = newOrigin[1]; ((Effect *)p)->mRefEnt.axis[0][0] = newOrigin[2];
    *(void **)&((Effect *)p)->mRefEnt.origin[0] = material;

    /* Random weights based on flags */
    int flags = ((PrimitiveTemplate *)primTemp)->mAttributeFlags;
    if (flags & 0x2000) ((Particle *)p)->blendWeight[0] = flrand(0.0f, 1.0f);
    if (flags & 0x4000) ((Particle *)p)->blendWeight[1] = flrand(0.0f, 1.0f);
    if ((short)flags < 0) ((Particle *)p)->blendWeight[2] = flrand(0.0f, 1.0f);
    if (flags & 0x10000) ((Particle *)p)->blendWeight[3] = flrand(0.0f, 1.0f);

    /* Refractive check */
    ((Effect *)p)->mSortGroup = 0;
    if (material && FxHelper_IsMaterialRefractive(theFxHelper, (MaterialHandle)material))
        ((Effect *)p)->mSortGroup = -1;
}

/* FX_AddParticle — allocate Particle, add to system, init, set material, apply late time */
extern void Particle_Particle(void *particle);
extern void Particle_IntegrateTotalVelocity(void *particle, int time, vec_t *velSum);
void FX_AddParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    byte *p = (byte *)__Znam(0x24c);
    if (p) memset(p, 0, 0x24c);
    Particle_Particle(p);
    if (!p) return;

    /* FX_AddPrimitive: eax=prim, edx=particle, ecx=origin */
    int added;
    added = FX_AddPrimitive_impl((byte *)prim, p, (const vec_t *)origin);
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }

    /* FX_InitParticle: eax=prim, edx=particle, ecx=newOrigin, stack: origin, ax, indexInBatch */
    vec3_t newOrigin;
    FX_InitParticle_impl((byte *)prim, p, newOrigin, (const vec_t *)origin, ax, indexInBatch);

    /* FX_SetMaterialAndSequenceParams: eax=primTemp, edx=particle, ecx=killTime, stack: indexInBatch */
    int killTime = ((Effect *)p)->mTimeEnd - ((Effect *)p)->mTimeStart;
    FX_SetMaterialAndSequenceParams_impl((byte *)prim->primTemp, p, killTime, indexInBatch);

    /* Late time velocity integration */
    if (lateTime > 0) {
        float dt = (float)lateTime * 0.001f;
        vec3_t velSum;
        Particle_IntegrateTotalVelocity(p, lateTime, velSum);
        newOrigin[0] += velSum[0] * dt;
        newOrigin[1] += velSum[1] * dt;
        newOrigin[2] += velSum[2] * dt;
    }

    /* Copy newOrigin to particle origin at offset 4 */
    *(float *)&((Effect *)p)->mRefEnt.customMaterial = newOrigin[0];
    ((Effect *)p)->mRefEnt.rotation = newOrigin[1];
    ((Effect *)p)->mRefEnt.axis[0][0] = newOrigin[2];
}

/* FX_AddTail — allocate Tail, add to system, init, late time, endpoint setup */
extern void Tail_Tail(void *tail);
extern void Tail_InitEndPoint(void *tail);
void FX_AddTail(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    byte *p = (byte *)__Znam(0x278);
    if (p) memset(p, 0, 0x278);
    Tail_Tail(p);
    if (!p) return;
    int added;
    added = FX_AddPrimitive_impl((byte *)prim, (byte *)p, (const vec_t *)origin);
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
    FX_InitParticle_impl((byte *)prim, (byte *)p, newOrigin, (const vec_t *)origin, ax, indexInBatch);
    int killTime = ((Effect *)p)->mTimeEnd - ((Effect *)p)->mTimeStart;
    FX_SetMaterialAndSequenceParams_impl((byte *)prim->primTemp, p, killTime, indexInBatch);
    if (lateTime > 0) {
        float dt = (float)lateTime * 0.001f;
        vec3_t velSum;
        Particle_IntegrateTotalVelocity(p, lateTime, velSum);
        newOrigin[0] += velSum[0] * dt; newOrigin[1] += velSum[1] * dt; newOrigin[2] += velSum[2] * dt;
    }
    /* Copy origin */
    *(float *)&((Effect *)p)->mRefEnt.customMaterial = newOrigin[0]; ((Effect *)p)->mRefEnt.rotation = newOrigin[1]; ((Effect *)p)->mRefEnt.axis[0][0] = newOrigin[2];
    /* Copy endpoint direction = newOrigin - ax[0]*something */
    float ny = newOrigin[1]; /* saved for below */
    ((Tail *)p)->endpoint[0] = newOrigin[0] - ((float *)ax)[0];
    ((Tail *)p)->endpoint[1] = ny - ((float *)ax)[1];
    ((Tail *)p)->endpoint[2] = newOrigin[2] - ((float *)ax)[2];
    /* Random weight */
    ((Tail *)p)->lengthBlendFactor = flrand(0.0f, 1.0f);
    Tail_InitEndPoint(p);
}

/* FX_AddEmitter — allocate Emitter, add to system, init, set material, late time, emitter setup */
extern void Emitter_Emitter(void *emitter);
extern void Particle_GetTotalVelocityAtTime0(void *particle, vec_t *outVector);
void FX_AddEmitter(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    byte *p = (byte *)__Znam(0x29c);
    if (p) memset(p, 0, 0x29c);
    Emitter_Emitter(p);
    if (!p) return;
    int added;
    added = FX_AddPrimitive_impl((byte *)prim, (byte *)p, (const vec_t *)origin);
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
    FX_InitParticle_impl((byte *)prim, (byte *)p, newOrigin, (const vec_t *)origin, ax, indexInBatch);
    byte *primTemp = (byte *)prim->primTemp;
    if (lateTime > 0) {
        float dt = (float)lateTime * 0.001f;
        vec3_t velSum;
        Particle_IntegrateTotalVelocity(p, lateTime, velSum);
        newOrigin[0] += velSum[0] * dt; newOrigin[1] += velSum[1] * dt; newOrigin[2] += velSum[2] * dt;
    }
    /* Emitter-specific: range values for spawn parameters */
    float spawnSize = FxRange_GetVal(primTemp + 0x238);
    float spawnDensity = FxRange_GetVal(primTemp + 0x230);
    float spawnVariance = FxRange_GetVal(primTemp + 0x248);
    float spawnStep = FxRange_GetVal(primTemp + 0x240);
    /* Get material */
    void *material = MediaHandles_GetHandle(&((PrimitiveTemplate *)primTemp)->mMediaHandles);
    /* Copy origin */
    *(float *)&((Effect *)p)->mRefEnt.customMaterial = newOrigin[0]; ((Effect *)p)->mRefEnt.rotation = newOrigin[1]; ((Effect *)p)->mRefEnt.axis[0][0] = newOrigin[2];
    /* Copy endpoint = origin (same position for emitter) */
    ((Tail *)p)->endpoint[0] = newOrigin[0]; ((Tail *)p)->endpoint[1] = newOrigin[1]; ((Tail *)p)->endpoint[2] = newOrigin[2];
    /* Get velocity at t=0 for emit direction */
    vec3_t vel;
    Particle_GetTotalVelocityAtTime0(p, vel);
    ((Tail *)p)->tailLength = vel[0]; ((Tail *)p)->lengthBlendFactor = vel[1]; *(float *)&((Tail *)p)->lengthChannelInstance = vel[2];
    /* Store spawn parameters */
    ((Emitter *)p)->spawnSize = spawnSize;
    ((Emitter *)p)->spawnDensity = spawnDensity;
    ((Emitter *)p)->spawnStep = spawnStep;
    ((Emitter *)p)->spawnVariance = spawnVariance;
    /* Set model reference from primTemp */
    *(int *)&((Effect *)p)->mModelPtr = *(int *)&((PrimitiveTemplate *)primTemp)->mAngle3Delta; /* TODO: subclass field at 0xb4 */
    /* Set emitter effect template */
    ((Emitter *)p)->emitFx = (void *)((PrimitiveTemplate *)primTemp)->mPlayFxHandles;
    /* Set material + refractive flag */
    *(void **)&((Effect *)p)->mRefEnt.origin[0] = material;
    ((Effect *)p)->mSortGroup = 0;
    if (material && FxHelper_IsMaterialRefractive(theFxHelper, (MaterialHandle)material))
        ((Effect *)p)->mSortGroup = -1;
    /* Random weights based on flags */
    int flags = ((PrimitiveTemplate *)primTemp)->mAttributeFlags;
    if (flags & 0x2000) ((Particle *)p)->blendWeight[0] = flrand(0.0f, 1.0f);
    if (flags & 0x4000) ((Particle *)p)->blendWeight[1] = flrand(0.0f, 1.0f);
    if ((short)flags < 0) ((Particle *)p)->blendWeight[2] = flrand(0.0f, 1.0f);
}

/* FX_AddOrientedParticle — allocate, add, init, material, late time, copy normal+origin */
extern void OrientedParticle_OrientedParticle(void *op);
void FX_AddOrientedParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    byte *p = (byte *)__Znam(0x258);
    if (p) memset(p, 0, 0x258);
    OrientedParticle_OrientedParticle(p);
    if (!p) return;
    int added;
    added = FX_AddPrimitive_impl((byte *)prim, (byte *)p, (const vec_t *)origin);
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
    FX_InitParticle_impl((byte *)prim, (byte *)p, newOrigin, (const vec_t *)origin, ax, indexInBatch);
    int killTime = ((Effect *)p)->mTimeEnd - ((Effect *)p)->mTimeStart;
    FX_SetMaterialAndSequenceParams_impl((byte *)prim->primTemp, p, killTime, indexInBatch);
    if (lateTime > 0) {
        float dt = (float)lateTime * 0.001f;
        vec3_t velSum;
        Particle_IntegrateTotalVelocity(p, lateTime, velSum);
        newOrigin[0] += velSum[0] * dt; newOrigin[1] += velSum[1] * dt; newOrigin[2] += velSum[2] * dt;
    }
    /* Copy normal to p+0x24c — either direct or via bolt orientation */
    vec3_t normal;
    normal[0] = ((float *)ax)[0]; normal[1] = ((float *)ax)[1]; normal[2] = ((float *)ax)[2];
    FxBoltFrame *bolt = (FxBoltFrame *)(size_t)prim->boltFrame._placeholder;
    if (bolt) {
        void *orient = FxBoltFrame_GetOrientation(bolt);
        vec3_t localNormal;
        OrientationDirFromWorldDir(orient, normal, localNormal);
        ((Tail *)p)->endpoint[0] = localNormal[0]; ((Tail *)p)->endpoint[1] = localNormal[1]; ((Tail *)p)->endpoint[2] = localNormal[2];
    } else {
        ((Tail *)p)->endpoint[0] = normal[0]; ((Tail *)p)->endpoint[1] = normal[1]; ((Tail *)p)->endpoint[2] = normal[2];
    }
    *(float *)&((Effect *)p)->mRefEnt.customMaterial = newOrigin[0]; ((Effect *)p)->mRefEnt.rotation = newOrigin[1]; ((Effect *)p)->mRefEnt.axis[0][0] = newOrigin[2];
}

/* FX_UpdateScheduledEffectsNonBolt — update non-bolt effects: expire dead, cull visible */
extern void *imp_fx_enable;
extern void *imp_fx_camera_valid;
extern void *imp_fx_cull;
void FX_UpdateScheduledEffectsNonBolt(void)
{
    typedef void (*UpdateFn)(void *);
    typedef Bool (*CullFn)(void *);
    int i;

    if (!*(byte *)(*(int *)imp_fx_enable + 8))
        return;

    cullEffectCountNonBolt = 0;
    visibleEffectCountNonBolt = 0;

    int count = privateEffectActiveCountNonBolt;
    initialEffectActiveCountNonBolt = count;

    /* Phase 1: Update effects — expire dead ones */
    i = 0;
    while (i < count) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        int curTime = theFxHelper->mTime;
        if (curTime > ((Effect *)eff)->mTimeEnd) {
            /* Effect expired — clear flag and remove */
            ((Effect *)eff)->mFlags &= ~0x400;
            /* Swap with last and destroy */
            byte **slot = (byte **)effectListNonBolt + i;
            byte *dead = *slot;
            count--;
            privateEffectActiveCountNonBolt = count;
            byte *last = ((byte **)effectListNonBolt)[count];
            *slot = last;
            ((byte **)effectListNonBolt)[count] = dead;
            /* Call vtable[2] (Die/cleanup) */
            ((UpdateFn)(*(void ***)dead)[2])(dead);
            if (((byte *)&((Effect *)dead)->mFlags)[1] & 0x10)
                effectBlockSightCount--;
            count = privateEffectActiveCountNonBolt;
        } else {
            /* Effect alive — call vtable[3] (Update) */
            Bool alive = ((CullFn)(*(void ***)eff)[3])(eff);
            if (!alive) continue; /* update failed, re-check same index */
            i++;
            count = privateEffectActiveCountNonBolt;
        }
    }

    /* Phase 2: Visibility culling */
    if (!*(int *)imp_fx_camera_valid)
        return;

    for (i = cullEffectCountNonBolt; i < privateEffectActiveCountNonBolt; i++) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        if (*(byte *)(*(int *)imp_fx_cull + 8)) {
            Bool culled = ((CullFn)(*(void ***)eff)[4])(eff);
            if (culled) continue;
        }
        int idx = visibleEffectCountNonBolt;
        ((void **)visibleEffectsNonBolt)[idx * 2] = eff;
        float dist = Vec3DistanceSq((vec_t *)&((Effect *)eff)->mRefEnt.origin, theFxHelper->mCamera.vieworg);
        *(float *)((byte *)visibleEffectsNonBolt + idx * 8 + 4) = dist;
        visibleEffectCountNonBolt++;
    }
    cullEffectCountNonBolt = privateEffectActiveCountNonBolt;
}

/* FX_UpdateScheduledEffectsBolt — update bolt effects: expire dead, cull visible */
void FX_UpdateScheduledEffectsBolt(void)
{
    typedef void (*UpdateFn)(void *);
    typedef Bool (*CullFn)(void *);
    int i, count;

    if (!*(byte *)(*(int *)imp_fx_enable + 8))
        return;

    cullEffectCountBolt = 0;
    visibleEffectCountBolt = 0;

    count = privateEffectActiveCountBolt;
    initialEffectActiveCountBolt = count;

    i = 0;
    while (i < count) {
        byte *eff = ((byte **)effectListBolt)[i];
        int curTime = theFxHelper->mTime;
        if (curTime > ((Effect *)eff)->mTimeEnd) {
            ((Effect *)eff)->mFlags &= ~0x400;
            byte **slot = (byte **)effectListBolt + i;
            byte *dead = *slot;
            count--;
            privateEffectActiveCountBolt = count;
            byte *last = ((byte **)effectListBolt)[count];
            *slot = last;
            ((byte **)effectListBolt)[count] = dead;
            ((UpdateFn)(*(void ***)dead)[2])(dead);
            if (((byte *)&((Effect *)dead)->mFlags)[1] & 0x10)
                effectBlockSightCount--;
            count = privateEffectActiveCountBolt;
        } else {
            Bool alive = ((CullFn)(*(void ***)eff)[3])(eff);
            if (!alive) continue;
            i++;
            count = privateEffectActiveCountBolt;
        }
    }

    for (i = cullEffectCountBolt; i < privateEffectActiveCountBolt; i++) {
        byte *eff = ((byte **)effectListBolt)[i];
        if (*(byte *)(*(int *)imp_fx_cull + 8)) {
            Bool culled = ((CullFn)(*(void ***)eff)[4])(eff);
            if (culled) continue;
        }
        int idx = visibleEffectCountBolt;
        ((void **)visibleEffectsBolt)[idx * 2] = eff;
        float dist = Vec3DistanceSq((vec_t *)&((Effect *)eff)->mRefEnt.origin, theFxHelper->mCamera.vieworg);
        *(float *)((byte *)visibleEffectsBolt + idx * 8 + 4) = dist;
        visibleEffectCountBolt++;
    }
    cullEffectCountBolt = privateEffectActiveCountBolt;
}

/* FX_UpdateAllBolt — phase 1: expire dead effects, phase 2: cleanup clusters, destroy removed effects */
static void FX_RemoveCluster(int clusterId)
{
    byte *clusters = (byte *)effectClusters;
    int lastIdx = effectClusterCount - 1;
    effectClusterCount = lastIdx;
    if (clusterId != lastIdx) {
        /* Swap last cluster into the removed slot */
        memcpy(clusters + clusterId * 16, clusters + lastIdx * 16, 16);
        /* Remap all effects that referenced the moved cluster */
        int i;
        for (i = 0; i < effectActiveCountBolt; i++) {
            byte *eff = ((byte **)effectListBolt)[i];
            if (((Effect *)eff)->mClusterId == lastIdx)
                ((Effect *)eff)->mClusterId = clusterId;
        }
        for (i = 0; i < effectActiveCountNonBolt; i++) {
            byte *eff = ((byte **)effectListNonBolt)[i];
            if (((Effect *)eff)->mClusterId == lastIdx)
                ((Effect *)eff)->mClusterId = clusterId;
        }
    }
}
void FX_UpdateAllBolt(void)
{
    typedef void (*VtFn)(void *);
    typedef Bool (*UpdateFn)(void *);
    int i, count;

    /* Phase 1: expire dead effects */
    count = effectActiveCountBolt;
    privateEffectActiveCountBolt = count;
    initialEffectActiveCountBolt = count;

    i = 0;
    while (i < count) {
        byte *eff = ((byte **)effectListBolt)[i];
        int curTime = theFxHelper->mTime;
        if (curTime > ((Effect *)eff)->mTimeEnd) {
            ((Effect *)eff)->mFlags &= ~0x400;
            /* Swap-remove and destroy */
            byte *dead = eff;
            count--;
            privateEffectActiveCountBolt = count;
            byte *last = ((byte **)effectListBolt)[count];
            ((byte **)effectListBolt)[i] = last;
            ((byte **)effectListBolt)[count] = dead;
            ((VtFn)(*(void ***)dead)[2])(dead); /* Die */
            if (((byte *)&((Effect *)dead)->mFlags)[1] & 0x10)
                effectBlockSightCount--;
            count = privateEffectActiveCountBolt;
        } else {
            Bool alive = ((UpdateFn)(*(void ***)eff)[3])(eff);
            if (!alive) continue;
            i++;
            count = privateEffectActiveCountBolt;
        }
    }

    /* Phase 2: cleanup removed effects — destroy, remove clusters, update counts */
    for (i = count; i < initialEffectActiveCountBolt; i++) {
        byte *eff = ((byte **)effectListBolt)[i];
        int clusterId = ((Effect *)eff)->mClusterId;
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        ((EffectCluster *)cluster)->refCount -= 1;
        if (((EffectCluster *)cluster)->refCount <= 0) {
            FX_RemoveCluster(clusterId);
        }
        ((VtFn)(*(void ***)eff)[1])(eff); /* Delete */
        effectActiveCountBolt--;
        ((byte **)effectListBolt)[i] = ((byte **)effectListBolt)[effectActiveCountBolt];
        effectActiveCount--;
    }
}

/* FX_Rewind — remove effects that start after the given time, for save/load rewind */
void FX_Rewind(int time)
{
    typedef void (*VtFn)(void *);
    int i, count;

    /* Phase 1: Bolt effects — remove those starting after 'time' */
    count = effectActiveCountBolt;
    privateEffectActiveCountBolt = count;
    initialEffectActiveCountBolt = count;

    i = 0;
    while (i < count) {
        byte *eff = ((byte **)effectListBolt)[i];
        if (time < ((Effect *)eff)->mTimeStart) {
            /* Effect starts after rewind time — remove it */
            count--;
            privateEffectActiveCountBolt = count;
            byte **slot = (byte **)effectListBolt + i;
            byte *removed = *slot;
            *slot = ((byte **)effectListBolt)[count];
            ((byte **)effectListBolt)[count] = removed;
            if (((byte *)&((Effect *)removed)->mFlags)[1] & 0x10)
                effectBlockSightCount--;
            count = privateEffectActiveCountBolt;
        } else {
            i++;
            count = privateEffectActiveCountBolt;
        }
    }

    /* Phase 2: Cleanup removed bolt effects */
    for (i = count; i < initialEffectActiveCountBolt; i++) {
        byte *eff = ((byte **)effectListBolt)[i];
        int clusterId = ((Effect *)eff)->mClusterId;
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        ((EffectCluster *)cluster)->refCount -= 1;
        if (((EffectCluster *)cluster)->refCount <= 0)
            FX_RemoveCluster(clusterId);
        ((VtFn)(*(void ***)eff)[1])(eff);
        effectActiveCountBolt--;
        ((byte **)effectListBolt)[i] = ((byte **)effectListBolt)[effectActiveCountBolt];
        effectActiveCount--;
    }

    /* Phase 3: Non-bolt effects — same pattern */
    count = effectActiveCountNonBolt;
    privateEffectActiveCountNonBolt = count;
    initialEffectActiveCountNonBolt = count;

    i = 0;
    while (i < count) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        if (time < ((Effect *)eff)->mTimeStart) {
            count--;
            privateEffectActiveCountNonBolt = count;
            byte **slot = (byte **)effectListNonBolt + i;
            byte *removed = *slot;
            *slot = ((byte **)effectListNonBolt)[count];
            ((byte **)effectListNonBolt)[count] = removed;
            if (((byte *)&((Effect *)removed)->mFlags)[1] & 0x10)
                effectBlockSightCount--;
            count = privateEffectActiveCountNonBolt;
        } else {
            i++;
            count = privateEffectActiveCountNonBolt;
        }
    }

    /* Phase 4: Cleanup removed non-bolt effects */
    for (i = count; i < initialEffectActiveCountNonBolt; i++) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        int clusterId = ((Effect *)eff)->mClusterId;
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        ((EffectCluster *)cluster)->refCount -= 1;
        if (((EffectCluster *)cluster)->refCount <= 0)
            FX_RemoveCluster(clusterId);
        ((VtFn)(*(void ***)eff)[1])(eff);
        effectActiveCountNonBolt--;
        ((byte **)effectListNonBolt)[i] = ((byte **)effectListNonBolt)[effectActiveCountNonBolt];
        effectActiveCount--;
    }
}

/* FX_UpdateAllNonBolt — same as UpdateAllBolt but for non-bolt effects */
void FX_UpdateAllNonBolt(void)
{
    typedef void (*VtFn)(void *);
    typedef Bool (*UpdateFn)(void *);
    int i, count;

    count = effectActiveCountNonBolt;
    privateEffectActiveCountNonBolt = count;
    initialEffectActiveCountNonBolt = count;

    i = 0;
    while (i < count) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        int curTime = theFxHelper->mTime;
        if (curTime > ((Effect *)eff)->mTimeEnd) {
            ((Effect *)eff)->mFlags &= ~0x400;
            byte *dead = eff;
            count--;
            privateEffectActiveCountNonBolt = count;
            byte *last = ((byte **)effectListNonBolt)[count];
            ((byte **)effectListNonBolt)[i] = last;
            ((byte **)effectListNonBolt)[count] = dead;
            ((VtFn)(*(void ***)dead)[2])(dead);
            if (((byte *)&((Effect *)dead)->mFlags)[1] & 0x10)
                effectBlockSightCount--;
            count = privateEffectActiveCountNonBolt;
        } else {
            Bool alive = ((UpdateFn)(*(void ***)eff)[3])(eff);
            if (!alive) continue;
            i++;
            count = privateEffectActiveCountNonBolt;
        }
    }

    for (i = count; i < initialEffectActiveCountNonBolt; i++) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        int clusterId = ((Effect *)eff)->mClusterId;
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        ((EffectCluster *)cluster)->refCount -= 1;
        if (((EffectCluster *)cluster)->refCount <= 0)
            FX_RemoveCluster(clusterId);
        ((VtFn)(*(void ***)eff)[1])(eff);
        effectActiveCountNonBolt--;
        ((byte **)effectListNonBolt)[i] = ((byte **)effectListNonBolt)[effectActiveCountNonBolt];
        effectActiveCount--;
    }
}

/* FX_DrawScheduledEffects — main FX frame tick: cleanup removed, add scheduled, update all */
void FX_DrawScheduledEffects(void)
{
    typedef void (*VtFn)(void *);
    typedef Bool (*UpdateFn)(void *);
    int i, count;

    if (!*(byte *)(*(int *)imp_fx_enable + 8))
        return;

    /* Phase 1: Cleanup removed non-bolt effects (between private and initial counts) */
    count = privateEffectActiveCountNonBolt;
    for (i = count; i < initialEffectActiveCountNonBolt; i++) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        int clusterId = ((Effect *)eff)->mClusterId;
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        ((EffectCluster *)cluster)->refCount -= 1;
        if (((EffectCluster *)cluster)->refCount <= 0)
            FX_RemoveCluster(clusterId);
        ((VtFn)(*(void ***)eff)[1])(eff);
        effectActiveCountNonBolt--;
        ((byte **)effectListNonBolt)[i] = ((byte **)effectListNonBolt)[effectActiveCountNonBolt];
        effectActiveCount--;
    }

    /* Phase 2: Cleanup removed bolt effects */
    count = privateEffectActiveCountBolt;
    for (i = count; i < initialEffectActiveCountBolt; i++) {
        byte *eff = ((byte **)effectListBolt)[i];
        int clusterId = ((Effect *)eff)->mClusterId;
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        ((EffectCluster *)cluster)->refCount -= 1;
        if (((EffectCluster *)cluster)->refCount <= 0)
            FX_RemoveCluster(clusterId);
        ((VtFn)(*(void ***)eff)[1])(eff);
        effectActiveCountBolt--;
        ((byte **)effectListBolt)[i] = ((byte **)effectListBolt)[effectActiveCountBolt];
        effectActiveCount--;
    }

    /* Phase 3: Add scheduled effects */
    FX_AddScheduledEffects(NULL, NULL);

    /* Phase 4: Update bolt effects */
    count = effectActiveCountBolt;
    privateEffectActiveCountBolt = count;
    initialEffectActiveCountBolt = count;
    i = 0;
    while (i < count) {
        byte *eff = ((byte **)effectListBolt)[i];
        int curTime = theFxHelper->mTime;
        if (curTime > ((Effect *)eff)->mTimeEnd) {
            ((Effect *)eff)->mFlags &= ~0x400;
            byte *dead = eff;
            count--;
            privateEffectActiveCountBolt = count;
            byte *last = ((byte **)effectListBolt)[count];
            ((byte **)effectListBolt)[i] = last;
            ((byte **)effectListBolt)[count] = dead;
            ((VtFn)(*(void ***)dead)[2])(dead);
            if (((byte *)&((Effect *)dead)->mFlags)[1] & 0x10) effectBlockSightCount--;
            count = privateEffectActiveCountBolt;
        } else {
            Bool alive = ((UpdateFn)(*(void ***)eff)[3])(eff);
            if (!alive) continue;
            i++;
            count = privateEffectActiveCountBolt;
        }
    }

    /* Phase 5: Update non-bolt effects */
    count = effectActiveCountNonBolt;
    privateEffectActiveCountNonBolt = count;
    initialEffectActiveCountNonBolt = count;
    i = 0;
    while (i < count) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        int curTime = theFxHelper->mTime;
        if (curTime > ((Effect *)eff)->mTimeEnd) {
            ((Effect *)eff)->mFlags &= ~0x400;
            byte *dead = eff;
            count--;
            privateEffectActiveCountNonBolt = count;
            byte *last = ((byte **)effectListNonBolt)[count];
            ((byte **)effectListNonBolt)[i] = last;
            ((byte **)effectListNonBolt)[count] = dead;
            ((VtFn)(*(void ***)dead)[2])(dead);
            if (((byte *)&((Effect *)dead)->mFlags)[1] & 0x10) effectBlockSightCount--;
            count = privateEffectActiveCountNonBolt;
        } else {
            Bool alive = ((UpdateFn)(*(void ***)eff)[3])(eff);
            if (!alive) continue;
            i++;
            count = privateEffectActiveCountNonBolt;
        }
    }
}

/* FX_Restore — restore effects from save file: clean, read archive, reconstruct effect list */
extern void FxArchive_FxArchive(void *arch);
extern void FxArchive_ReadData(void *arch, void *data, int size);
extern void FxArchive_BeginReading(void *arch, void *memFile);
extern void FxHelper_Archive(void *helper, void *arch);
extern void FxScheduler_Archive(void *scheduler, void *arch);
extern void Line_Line(void *line);
extern void Tail_Tail(void *tail);
extern void Emitter_Emitter(void *emitter);
int FX_Restore(MemoryFile *memFile)
{
    typedef void (*VtFn)(void *);
    typedef void (*ArchFn)(void *, void *);
    typedef void (*FixupFn)(void *, void *);
    int i;
    byte arch[16]; /* FxArchive struct */

    FxArchive_FxArchive(arch);

    /* Delete all existing effects */
    for (i = 0; i < effectActiveCountBolt; i++) {
        byte *eff = ((byte **)effectListBolt)[i];
        if (eff) ((VtFn)(*(void ***)eff)[1])(eff);
    }
    for (i = 0; i < effectActiveCountNonBolt; i++) {
        byte *eff = ((byte **)effectListNonBolt)[i];
        if (eff) ((VtFn)(*(void ***)eff)[1])(eff);
    }
    effectActiveCountBolt = 0;
    effectActiveCountNonBolt = 0;
    effectActiveCount = 0;
    effectBlockSightCount = 0;
    effectClusterCount = 0;

    void **schedulerPtr = (void **)imp_theFxScheduler;
    if (*schedulerPtr)
        FxScheduler_Clean(*schedulerPtr, 0, 0);

    /* Begin reading from memFile */
    FxArchive_BeginReading(arch, memFile);
    FxHelper_Archive(theFxHelper, arch);
    FxScheduler_Archive(*schedulerPtr, arch);

    /* Read effects loop */
    for (;;) {
        byte effectType;
        FxArchive_ReadData(arch, &effectType, 1);
        if (effectType == 0) break;

        int size;
        FxArchive_ReadData(arch, &size, 4);

        if (effectType > 12) continue; /* invalid type, skip */

        /* Allocate effect based on type */
        static const int sizes[] = { 0, 0x24c, 0xfc, 0x258, 0x278, 0x278, 0x27c, 0x258, 0x278, 0x29c, 0x258, 0x278, 0xfc };
        static const char *ctors[] = { NULL, "Particle", "Light", "Line", "Tail", "Cylinder", "Cloud", "OrientedParticle", "Tail", "Emitter", "Line", "Cylinder", "Flash" };
        (void)ctors;

        int allocSize = (effectType <= 12) ? sizes[effectType] : 0;
        if (allocSize == 0) continue;

        byte *eff = (byte *)__Znam(allocSize);
        if (eff) memset(eff, 0, allocSize);

        /* Call constructor based on type */
        switch (effectType) {
            case 1: Particle_Particle(eff); break;
            case 2: case 12: Light_Light(eff); break;
            case 3: case 10: Line_Line(eff); break;
            case 4: case 8: Tail_Tail(eff); break;
            case 5: case 11: Cylinder_Cylinder(eff); break;
            case 6: Cloud_Cloud(eff); break;
            case 7: OrientedParticle_OrientedParticle(eff); break;
            case 9: Emitter_Emitter(eff); break;
        }

        /* Archive (read) the effect */
        ((ArchFn)(*(void ***)eff)[10])(eff, arch); /* vtable[10] = Archive */

        /* Get primTemplate from effect template */
        byte *fxTemplate = *(byte **)&((Effect *)eff)->mRefEnt.dlightColor[2];
        int primIdx = *(int *)&((Effect *)eff)->mRefEnt.materialTime;
        byte *primTemp = NULL;
        if (fxTemplate && primIdx < ((EffectTemplate *)fxTemplate)->mPrimitiveCount)
            primTemp = (byte *)((EffectTemplate *)fxTemplate)->mPrimitives[primIdx];

        if (!primTemp) continue;

        /* Call FixupArchiveLoad (vtable[11]) */
        ((FixupFn)(*(void ***)eff)[11])(eff, primTemp);

        if (((byte *)&((Effect *)eff)->mFlags)[1] & 0x10)
            effectBlockSightCount++;

        /* Add to bolt or non-bolt list */
        if (((Effect *)eff)->mBolt) {
            ((byte **)effectListBolt)[effectActiveCountBolt] = eff;
            effectActiveCountBolt++;
        } else {
            ((byte **)effectListNonBolt)[effectActiveCountNonBolt] = eff;
            effectActiveCountNonBolt++;
        }
        effectActiveCount++;
    }

    /* Close archive */
    int bytesRead = ((FxArchive *)arch)->memFile->bytesUsed - ((FxArchive *)arch)->startPos;
    return bytesRead;
}

/* FX_Init — initialize or reinitialize the effects system */
extern void *Z_MallocInternal(int size);
extern void FxScheduler_FxScheduler(void *scheduler);
extern void FX_InitTemplates(void);
extern void FxHelper_Init(void *helper);
extern void *imp_g_rendererExists;
int FX_Init(int rendererExists)
{
    int i;
    if (!*(int *)fxInitialized) {
        *(int *)fxInitialized = 1;
        effectActiveCountBolt = 0;
        effectActiveCountNonBolt = 0;
        effectActiveCount = 0;
        effectBlockSightCount = 0;
        effectClusterCount = 0;
    }
    /* Destroy all existing effects */
    for (i = 0; i < effectActiveCountBolt; i++) {
        void *eff = ((void **)effectListBolt)[i];
        if (eff) { typedef void (*Fn)(void *); ((Fn)(*(void ***)eff)[1])(eff); }
    }
    for (i = 0; i < effectActiveCountNonBolt; i++) {
        void *eff = ((void **)effectListNonBolt)[i];
        if (eff) { typedef void (*Fn)(void *); ((Fn)(*(void ***)eff)[1])(eff); }
    }
    effectActiveCountBolt = 0;
    effectActiveCountNonBolt = 0;
    effectActiveCount = 0;
    effectBlockSightCount = 0;
    effectClusterCount = 0;

    void **schedulerPtr = (void **)imp_theFxScheduler;
    if (*schedulerPtr) {
        FxScheduler_Clean(*schedulerPtr, 1, 0);
        Z_FreeInternal(*schedulerPtr);
        *schedulerPtr = NULL;
        *(void **)imp_fxSchedulers = NULL;
    }

    *(byte *)imp_g_rendererExists = (byte)rendererExists;

    void *newScheduler = Z_MallocInternal(0xc);
    FxScheduler_FxScheduler(newScheduler);
    *schedulerPtr = newScheduler;

    FX_InitTemplates();

    *(void **)imp_fxSchedulers = *schedulerPtr;

    FxHelper_Init(theFxHelper);
    return 1;
}

/* FX_Free — free all effects, optionally remove templates */
extern void Z_FreeInternal(void *ptr);
extern void FxScheduler_Clean(void *scheduler, int bRemoveTemplates, int arg3);
extern void *imp_fxSchedulers;
void FX_Free(int bRemoveTemplates)
{
    int i;
    /* Delete all bolt effects via vtable[1] (destructor) */
    for (i = 0; i < effectActiveCountBolt; i++) {
        void *eff = ((void **)effectListBolt)[i];
        if (eff) {
            typedef void (*DestroyFn)(void *);
            ((DestroyFn)(*(void ***)eff)[1])(eff);
        }
    }
    /* Delete all non-bolt effects */
    for (i = 0; i < effectActiveCountNonBolt; i++) {
        void *eff = ((void **)effectListNonBolt)[i];
        if (eff) {
            typedef void (*DestroyFn)(void *);
            ((DestroyFn)(*(void ***)eff)[1])(eff);
        }
    }
    effectActiveCountBolt = 0;
    effectActiveCountNonBolt = 0;
    effectActiveCount = 0;
    effectBlockSightCount = 0;
    effectClusterCount = 0;

    void **schedulerPtr = (void **)imp_theFxScheduler;
    if (*schedulerPtr) {
        FxScheduler_Clean(*schedulerPtr, (byte)bRemoveTemplates, 0);
        if ((byte)bRemoveTemplates) {
            Z_FreeInternal(*schedulerPtr);
            *schedulerPtr = NULL;
            *(void **)imp_fxSchedulers = NULL;
        }
    }
}
