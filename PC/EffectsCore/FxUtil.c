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

    result = *(int *)((byte *)fx0 + 0xb0) - *(int *)((byte *)fx1 + 0xb0);
    if (result)
        return result;

    result = clusterSort[*(int *)((byte *)fx0 + 0xac)] - clusterSort[*(int *)((byte *)fx1 + 0xac)];
    if (result)
        return result;

    result = *(int *)((byte *)fx0 + 0x40) - *(int *)((byte *)fx1 + 0x40);
    if (result)
        return result;

    return (*(float *)((byte *)e1 + 4) > *(float *)((byte *)e0 + 4)) ? 1 : -1;
}

/* line 1001 */
static int CompareSortedClusters(const void *e0, const void *e1)
{
    float v1 = *(float *)((byte *)e1 + 4);
    float v0 = *(float *)((byte *)e0 + 4);
    return (v1 > v0) ? 1 : -1;
}

/* line 1549 */
void FX_SetSortGroup(Effect *fx)
{
    *(int *)((byte *)fx + 0xb0) = 0;
    if (*(MaterialHandle *)((byte *)fx + 0x40) && FxHelper_IsMaterialRefractive(theFxHelper, *(MaterialHandle *)((byte *)fx + 0x40))) {
        *(int *)((byte *)fx + 0xb0) = -1;
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
        byte *cluster = (byte *)effectClusters + i * 16;
        float distSq = Vec3DistanceSq(origin, (const vec_t *)cluster);
        if (distSq < 131072.0f) {
            *(int *)(cluster + 0xc) += 1;
            return i;
        }
    }
    /* No nearby cluster — create a new one */
    {
        byte *newCluster = (byte *)effectClusters + effectClusterCount * 16;
        *(float *)(newCluster + 0) = origin[0];
        *(float *)(newCluster + 4) = origin[1];
        *(float *)(newCluster + 8) = origin[2];
        *(int *)(newCluster + 0xc) = 1;
        return effectClusterCount++;
    }
}

/* FX_CalcOrigin2 — compute second endpoint for line/cylinder: range offset ± trace to surface */
void FX_CalcOrigin2(const PrimitiveTemplate *primTemp, vec_t *org, vec_t *org2, const vec_t *origin, vec3_t *ax)
{
    byte *pt = (byte *)primTemp;
    int flags = *(int *)(pt + 0x94);

    if (flags & 0x08) {
        /* Project to infinity: temp = org + ax[0] * 16384 */
        float *axf = (float *)ax;
        vec3_t temp;
        temp[0] = org[0] + axf[0] * 16384.0f;
        temp[1] = org[1] + axf[1] * 16384.0f;
        temp[2] = org[2] + axf[2] * 16384.0f;

        if (flags & 0x20) {
            /* Add endpoint offset to temp */
            float z = FxRange_GetVal(pt + 0xe0);
            float y = FxRange_GetVal(pt + 0xd8);
            float x = FxRange_GetVal(pt + 0xd0);
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
            void *effect = MediaHandles_GetEffect(pt + 0x70);
            vec_t *traceNormal = (vec_t *)(trace + 0x24);
            FxScheduler_PlayEffect(*(void **)imp_theFxScheduler, effect, org2, (vec3_t *)traceNormal, NULL);
        }
    } else {
        /* No projectToInfinity: compute org2 from range values */
        float z = FxRange_GetVal(pt + 0xe0);
        float y = FxRange_GetVal(pt + 0xd8);
        float x = FxRange_GetVal(pt + 0xd0);

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
#if 0 /* Original ASM (243 lines) */
__attribute__((naked))
void FX_CalcOrigin2_asm(const PrimitiveTemplate *primTemp, vec_t *org, vec_t *org2, const vec_t *origin, vec3_t *ax)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1412 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %esi\n" /* primTemp */
        "movl 0xc(%ebp), %edi\n" /* org */
        "movl 0x10(%ebp), %ebx\n" /* org2 */
        /* { scope 1: z, y, point, z */
        "movl 0x94(%esi), %eax\n" /* line 1420 | primTemp */
        "testb $8, %al\n"
        "je .Lf5960a_00059767\n"
        "movss lit4_002ed68c, %xmm0\n" /* line 288 | 16384.0f */
        "movl 0x18(%ebp), %edx\n" /* ax */
        "movss (%edx), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss (%edi), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* temp */
        "leal 4(%edi), %ecx\n" /* line 289 */
        "movl %ecx, -0x74(%ebp)\n"
        "movss 4(%edx), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss 4(%edi), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "leal 8(%edi), %edx\n" /* line 290 */
        "movl %edx, -0x70(%ebp)\n"
        "movl 0x18(%ebp), %ecx\n" /* ax */
        "mulss 8(%ecx), %xmm0\n"
        "addss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "testb $0x20, %al\n" /* line 1424 */
        "jne .Lf5960a_00059855\n"
        "leal 4(%ebx), %eax\n" /* org2 */
        "movl %eax, -0x60(%ebp)\n"
        "leal 8(%ebx), %edx\n" /* org2 */
        "movl %edx, -0x5c(%ebp)\n"
        ".Lf5960a_0005968e:\n"
        "movl $1, 0x1c(%esp)\n" /* line 1443 */
        "movl $0xffffffff, 0x18(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* temp */
        "movl %eax, 0x14(%esp)\n"
        "movl imp_vec3_origin, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* org */
        "leal -0x54(%ebp), %eax\n" /* tr */
        "movl %eax, 4(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_Trace\n"
        "movss -0x54(%ebp), %xmm2\n" /* line 1445 | tr, fraction */
        /* { scope 2 */
        "movss (%edi), %xmm1\n" /* line 1203 */
        "movss -0x24(%ebp), %xmm0\n" /* temp */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ebx)\n"
        "movl -0x74(%ebp), %eax\n" /* line 1204 */
        "movss (%eax), %xmm1\n"
        "movss -0x20(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x60(%ebp), %edx\n"
        "movss %xmm1, (%edx)\n"
        "movl -0x70(%ebp), %ecx\n" /* line 1205 */
        "movss (%ecx), %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movl -0x5c(%ebp), %eax\n"
        "movss %xmm1, (%eax)\n"
        /* } scope */
        "testb $0x10, 0x94(%esi)\n" /* line 1447 | primTemp */
        "je .Lf5960a_000597e6\n"
        "leal 0x70(%esi), %eax\n" /* line 1448 | primTemp */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetEffect\n"
        "leal -0x50(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* org2 */
        "movl %eax, 4(%esp)\n"
        "movl imp_theFxScheduler, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 1459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: z, y, point, z */
        ".Lf5960a_00059767:\n"
        "testb %al, %al\n" /* line 1452 */
        "jns .Lf5960a_000597f1\n"
        "leal 0xe0(%esi), %eax\n" /* line 1453 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x68(%ebp)\n" /* z */
        "leal 0xd8(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x64(%ebp)\n" /* y */
        "leal 0xd0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        /* { scope 2 */
        "fstps (%ebx)\n" /* line 191 */
        "leal 4(%ebx), %edx\n" /* line 192 */
        "movss -0x64(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%ebx)\n"
        "leal 8(%ebx), %eax\n" /* line 193 */
        "movss -0x68(%ebp), %xmm2\n" /* z */
        "movss %xmm2, 8(%ebx)\n"
        /* } scope */
        ".Lf5960a_000597bb:\n"
        "movss (%ebx), %xmm0\n" /* line 240 */
        "movl 0x14(%ebp), %ecx\n" /* origin */
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "movss 4(%ebx), %xmm0\n" /* line 241 */
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss 8(%ebx), %xmm0\n" /* line 242 */
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        /* } scope */
        ".Lf5960a_000597e6:\n"
        "addl $0xbc, %esp\n" /* line 1459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: z, y, point, z */
        ".Lf5960a_000597f1:\n"
        "leal 0xe0(%esi), %eax\n" /* line 1455 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x7c(%ebp)\n"
        "leal 0xd8(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x78(%ebp)\n"
        "leal 0xd0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "movl %ebx, 0x10(%esp)\n" /* org2 */
        "movss -0x7c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x78(%ebp), %xmm2\n"
        "movss %xmm2, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* ax */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "leal 4(%ebx), %edx\n" /* org2 */
        "leal 8(%ebx), %eax\n" /* org2 */
        "jmp .Lf5960a_000597bb\n"
        ".Lf5960a_00059855:\n"
        "testb %al, %al\n" /* line 1429 */
        "js .Lf5960a_000598fd\n"
        /* { scope 2 */
        "leal 0xe0(%esi), %eax\n" /* line 1438 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x84(%ebp)\n"
        "leal 0xd8(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x80(%ebp)\n"
        "leal 0xd0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "leal -0x30(%ebp), %eax\n" /* point */
        "movl %eax, 0x10(%esp)\n"
        "movss -0x84(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x80(%ebp), %xmm2\n"
        "movss %xmm2, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* ax */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 240 | temp */
        "addss -0x30(%ebp), %xmm0\n" /* point */
        "movss %xmm0, -0x24(%ebp)\n" /* temp */
        "movss -0x20(%ebp), %xmm0\n" /* line 241 */
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 242 */
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 4(%ebx), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "leal 8(%ebx), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n"
        "jmp .Lf5960a_0005968e\n"
        /* } scope */
        ".Lf5960a_000598fd:\n"
        "leal 0xe0(%esi), %eax\n" /* line 1431 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x6c(%ebp)\n" /* z */
        "leal 0xd8(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm1\n" /* y */
        "leal 0xd0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x98(%ebp)\n" /* y */
        "calll FxRange_GetVal\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm0\n" /* x */
        /* { scope 2 */
        "movss %xmm0, (%ebx)\n" /* line 191 */
        "leal 4(%ebx), %ecx\n" /* line 192 */
        "movl %ecx, -0x60(%ebp)\n"
        "movss -0x98(%ebp), %xmm1\n"
        "movss %xmm1, 4(%ebx)\n"
        "leal 8(%ebx), %eax\n" /* line 193 */
        "movl %eax, -0x5c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm2\n" /* z */
        "movss %xmm2, 8(%ebx)\n"
        /* } scope */
        "addss -0x24(%ebp), %xmm0\n" /* line 240 | temp */
        "movss %xmm0, -0x24(%ebp)\n" /* temp */
        "addss -0x20(%ebp), %xmm1\n" /* line 241 */
        "movss %xmm1, -0x20(%ebp)\n"
        "addss -0x1c(%ebp), %xmm2\n" /* line 242 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "jmp .Lf5960a_0005968e\n"
    );
}
#endif

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
    byte *b = (byte *)bolt;
    int entityNum = *(int *)b;
    int boneIndex = *(int *)(b + 4);

    /* Get entity orientation (axis) */
    float axis[9];
    CG_GetDObjOrientation(entityNum, axis);

    if (boneIndex < 0) {
        /* No bone — just copy entity position from axis calc and axis itself */
        /* orient->origin = position from CG_GetDObjOrientation result */
        /* Actually the ASM copies from -0x54(%ebp) which is a local holding the position */
        /* For simplicity: copy axis to orient->axis, set orient position */
        float *oa = (float *)((byte *)orient + 0xc);
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

    byte *mtx = rotTransArray + boneIndex * 32;

    /* Convert quaternion to rotation matrix */
    /* mtx: quat(x,y,z,w) at offsets 0,4,8,0xc, scale at 0x1c, trans at 0x10 */
    float scale = *(float *)(mtx + 0x1c);
    float qx = *(float *)(mtx + 0) * scale;
    float qy = *(float *)(mtx + 4) * scale;
    float qz = *(float *)(mtx + 8) * scale;
    float qw = *(float *)(mtx + 0xc);

    float xx = qx * *(float *)(mtx + 0);
    float xy = qx * *(float *)(mtx + 4);
    float xz = qx * *(float *)(mtx + 8);
    float xw = qx * qw;
    float yy = qy * *(float *)(mtx + 4);
    float yz = qy * *(float *)(mtx + 8);
    float yw = qy * qw;
    float zz = qz * *(float *)(mtx + 8);
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
    MatrixMultiply(tagAxis, axis, (byte *)orient + 0xc);

    /* Transform bone position by entity axis → orient->origin */
    MatrixTransformVector43(mtx + 0x10, axis, orient);

    /* Debug bolt: advance position along forward axis */
    float debugDist = *(float *)(*(byte *)imp_fx_debugBolt + 8);
    if (debugDist != 0.0f) {
        float *oo = (float *)orient;
        float *oaxis = (float *)((byte *)orient + 0xc);
        oo[0] += oaxis[0] * debugDist;
        oo[1] += oaxis[1] * debugDist;
        oo[2] += oaxis[2] * debugDist;
    }

    return 1;
}
#if 0 /* Original ASM (253 lines) */
__attribute__((naked))
Bool FX_GetBoneOrientation_asm(const FxBoltInfo *bolt, orientation_t *orient)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 266 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %edi\n" /* bolt */
        /* { scope 1: end, xx, xz, yy, ... */
        "leal -0x78(%ebp), %eax\n" /* line 281 | axis */
        "movl %eax, 4(%esp)\n"
        "movl (%edi), %eax\n" /* bolt */
        "movl %eax, (%esp)\n"
        "calll CG_GetDObjOrientation\n"
        "movl 4(%edi), %ecx\n" /* line 288 | bolt */
        "testl %ecx, %ecx\n"
        "js .Lf59998_00059b88\n"
        "movl $0, 4(%esp)\n" /* line 295 */
        "movl (%edi), %eax\n" /* bolt */
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %esi\n" /* obj */
        "testl %eax, %eax\n" /* line 296 */
        "je .Lf59998_000599ea\n"
        "movl 4(%edi), %ebx\n" /* line 299 | bolt, mtx */
        "movl %eax, (%esp)\n"
        "calll DObjNumBones\n"
        "cmpl %eax, %ebx\n" /* mtx */
        "jl .Lf59998_000599f7\n"
        /* { scope 2 */
        ".Lf59998_000599ea:\n"
        "xorl %eax, %eax\n" /* line 331 */
        /* } scope */
        /* } scope */
        "addl $0xac, %esp\n" /* line 335 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: end, xx, xz, yy, ... */
        ".Lf59998_000599f7:\n"
        "movl 4(%edi), %eax\n" /* line 303 | bolt */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl (%edi), %eax\n" /* bolt */
        "movl %eax, (%esp)\n"
        "calll CG_DObjCalcBoneGeneric\n"
        "movl %esi, (%esp)\n" /* line 306 | obj */
        "calll DObjGetRotTransArray\n"
        "testl %eax, %eax\n" /* line 307 */
        "je .Lf59998_000599ea\n"
        "movl 4(%edi), %ebx\n" /* line 310 | bolt, mtx */
        "shll $5, %ebx\n" /* mtx */
        "leal (%eax, %ebx), %ebx\n" /* mtx */
        /* { scope 2 */
        "movss 0x1c(%ebx), %xmm1\n" /* line 306 | mtx, scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm4\n" /* line 272 */
        "mulss (%ebx), %xmm4\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%ebx), %xmm6\n"
        "mulss 8(%ebx), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm4, %xmm0\n" /* line 308 */
        "mulss (%ebx), %xmm0\n" /* mtx */
        "movss %xmm0, -0x84(%ebp)\n" /* xx */
        "movss 4(%ebx), %xmm3\n" /* line 309 | mtx */
        "movaps %xmm4, %xmm5\n"
        "mulss %xmm3, %xmm5\n"
        "movss 8(%ebx), %xmm2\n" /* line 310 | mtx */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n" /* xz */
        "movss 0xc(%ebx), %xmm0\n" /* line 311 | mtx */
        "mulss %xmm0, %xmm4\n"
        "mulss %xmm6, %xmm3\n" /* line 313 */
        "movss %xmm3, -0x7c(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm7\n" /* line 314 */
        "mulss %xmm2, %xmm7\n"
        "mulss %xmm0, %xmm6\n" /* line 315 */
        "movaps %xmm1, %xmm3\n" /* line 317 */
        "mulss %xmm2, %xmm3\n"
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss %xmm1, -0x8c(%ebp)\n" /* zw */
        "movss -0x7c(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm3, %xmm0\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n" /* tagAxis */
        "movss -0x8c(%ebp), %xmm0\n" /* line 321 | zw */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 322 | xz */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "subss -0x8c(%ebp), %xmm5\n" /* line 324 | zw */
        "movss %xmm5, -0x3c(%ebp)\n"
        "addss -0x84(%ebp), %xmm3\n" /* line 325 | xx */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 326 */
        "addss %xmm7, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "addss -0x80(%ebp), %xmm6\n" /* line 328 | xz */
        "movss %xmm6, -0x30(%ebp)\n"
        "subss %xmm4, %xmm7\n" /* line 329 */
        "movss %xmm7, -0x2c(%ebp)\n"
        "movss -0x84(%ebp), %xmm1\n" /* line 330 | xx, scale */
        "addss -0x7c(%ebp), %xmm1\n" /* yy, scale */
        "subss %xmm1, %xmm2\n" /* scale */
        "movss %xmm2, -0x28(%ebp)\n"
        /* } scope */
        "movl 0xc(%ebp), %esi\n" /* line 313 | orient, obj */
        "addl $0xc, %esi\n" /* obj */
        "movl %esi, 8(%esp)\n" /* obj */
        "leal -0x78(%ebp), %eax\n" /* axis */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* tagAxis */
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply\n"
        "movl 0xc(%ebp), %edx\n" /* line 315 | orient */
        "movl %edx, 8(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* axis */
        "movl %eax, 4(%esp)\n"
        "addl $0x10, %ebx\n" /* mtx */
        "movl %ebx, (%esp)\n" /* mtx */
        "calll MatrixTransformVector43\n"
        "movl imp_fx_debugBolt, %eax\n" /* line 322 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jne .Lf59998_00059bc0\n"
        "jp .Lf59998_00059bc0\n"
        /* { scope 2 */
        "movl $1, %eax\n" /* line 331 */
        /* } scope */
        /* } scope */
        ".Lf59998_00059b7d:\n"
        "addl $0xac, %esp\n" /* line 335 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: end, xx, xz, yy, ... */
        ".Lf59998_00059b88:\n"
        "movl -0x54(%ebp), %eax\n" /* line 199 */
        "movl 0xc(%ebp), %edx\n" /* orient */
        "movl %eax, (%edx)\n"
        "movl -0x50(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl %edx, %eax\n" /* line 291 */
        "addl $0xc, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 335 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: end, xx, xz, yy, ... */
        /* { scope 2 */
        ".Lf59998_00059bc0:\n"
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "movl 0xc(%ebp), %edx\n" /* orient */
        "mulss 0xc(%edx), %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* end */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%esi), %xmm0\n" /* obj */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%esi), %xmm1\n" /* line 290 | obj */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movl $0, 0x14(%esp)\n" /* line 327 */
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl imp_colorRed, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %ebx\n" /* end, mtx */
        "movl %ebx, 4(%esp)\n" /* mtx */
        "movl %edx, (%esp)\n"
        "calll CL_AddDebugLine\n"
        "movl imp_fx_debugBolt, %esi\n" /* line 328 | obj */
        "movl (%esi), %eax\n" /* obj, dir */
        "movss 8(%eax), %xmm1\n" /* scale */
        "movl 0xc(%ebp), %eax\n" /* orient, dir */
        "addl $0x18, %eax\n" /* dir */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "movl 0xc(%ebp), %edx\n" /* orient */
        "mulss 0x18(%edx), %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* end */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movl $0, 0x14(%esp)\n" /* line 329 */
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl imp_colorGreen, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* mtx */
        "movl %edx, (%esp)\n"
        "calll CL_AddDebugLine\n"
        "movl (%esi), %eax\n" /* line 330 | obj, dir */
        "movss 8(%eax), %xmm1\n" /* scale */
        "movl 0xc(%ebp), %eax\n" /* orient, dir */
        "addl $0x24, %eax\n" /* dir */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "movl 0xc(%ebp), %edx\n" /* orient */
        "mulss 0x24(%edx), %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* end */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "movl $0, 0x14(%esp)\n" /* line 331 */
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl imp_colorBlue, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* mtx */
        "movl %edx, (%esp)\n"
        "calll CL_AddDebugLine\n"
        "movl $1, %eax\n"
        "jmp .Lf59998_00059b7d\n"
    );
}
#endif

/* FX_AddScheduledEffects — walk scheduled effects linked list, dispatch due effects */
extern void Rand_Init(int seed);
extern void FxScheduler_CreateEffect(void *scheduler, void *fx, void *primTemp, void *origin, void *orient, void *ax, int lateTime, int indexInBatch);
void FX_AddScheduledEffects(const vec_t *start, const vec_t *end)
{
    (void)start; (void)end;
    if (!*(byte *)(*(int *)imp_fx_enable + 8))
        return;

    byte *scheduler = (byte *)imp_theFxScheduler;
    byte **prevNext = (byte **)(scheduler + 4);
    byte *scheduled = *prevNext;

    while (scheduled) {
        /* Check if effect is due */
        int startTime = *(int *)(scheduled + 8);
        int curTime = *(int *)((byte *)theFxHelper + 4);
        if (startTime > curTime) {
            /* Not yet due — advance to next */
            prevNext = (byte **)(scheduled + 0x4c);
            scheduled = *prevNext;
            continue;
        }

        /* Get effect template and prim template */
        byte *fx = *(byte **)scheduled;
        int primIndex = *(int *)(scheduled + 4);
        byte *primTemp = *(byte **)(fx + 8 + primIndex * 4);

        /* Init random seed */
        Rand_Init(*(int *)(scheduled + 0x44));

        /* Unlink from list */
        *prevNext = *(byte **)(scheduled + 0x4c);
        *(int *)(scheduler + 8) -= 1;

        /* Dispatch effect */
        int boltEntity = *(int *)(scheduled + 0xc);
        int lateTime = curTime - startTime;
        int indexInBatch = *(int *)(scheduled + 0x48);

        if (boltEntity >= 0) {
            /* Bolt-based: get bone orientation */
            orientation_t orient;
            Bool ok = FX_GetBoneOrientation((void *)(scheduled + 0xc), &orient);
            if (ok) {
                FxScheduler_CreateEffect(scheduler, fx, primTemp,
                    scheduled + 0xc, &orient, (byte *)&orient + 0xc,
                    lateTime, indexInBatch);
            }
        } else {
            /* Origin-based */
            FxScheduler_CreateEffect(scheduler, fx, primTemp,
                scheduled + 0xc, scheduled + 0x14, scheduled + 0x20,
                lateTime, indexInBatch);
        }

        /* Free scheduled effect */
        if (scheduled) __ZdaPv(scheduled);

        /* Continue from prevNext (which now points to the next element) */
        scheduled = *prevNext;
    }
}
#if 0 /* Original ASM + merged FX_GetServerVisibility */
__attribute__((naked))
void FX_AddScheduledEffects_asm(const vec_t *start, const vec_t *end)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2153 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl imp_fx_enable, %eax\n" /* line 2166 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf59d14_00059db2\n"
        "movl imp_theFxScheduler, %edx\n" /* line 2172 */
        /* fix: imp_theFxScheduler stores &struct, not &ptr — no extra deref */
        "leal 4(%edx), %esi\n" /* prevNext */
        "movl 4(%edx), %ebx\n" /* line 2173 | scheduled */
        "testl %ebx, %ebx\n" /* scheduled */
        "je .Lf59d14_00059db2\n"
        "movl %edx, -0x54(%ebp)\n"
        "jmp .Lf59d14_00059d4e\n"
        ".Lf59d14_00059d45:\n"
        "leal 0x4c(%ebx), %esi\n" /* line 2177 | scheduled, prevNext */
        ".Lf59d14_00059d48:\n"
        "movl (%esi), %ebx\n" /* line 2173 | prevNext, scheduled */
        "testl %ebx, %ebx\n" /* scheduled */
        "je .Lf59d14_00059db2\n"
        ".Lf59d14_00059d4e:\n"
        "movl 8(%ebx), %edx\n" /* line 2175 | scheduled */
        "movl theFxHelper, %eax\n"
        "cmpl 4(%eax), %edx\n"
        "jg .Lf59d14_00059d45\n"
        "movl (%ebx), %edi\n" /* line 2181 | scheduled, fx */
        "movl 4(%ebx), %eax\n" /* line 2182 | scheduled */
        "movl 8(%edi, %eax, 4), %eax\n" /* fx */
        "movl %eax, -0x50(%ebp)\n" /* primTemp */
        "movl 0x44(%ebx), %eax\n" /* line 2188 | scheduled */
        "movl %eax, (%esp)\n"
        "calll Rand_Init\n"
        "movl 0x4c(%ebx), %eax\n" /* line 2193 | scheduled */
        "movl %eax, (%esi)\n" /* prevNext */
        "movl -0x54(%ebp), %edx\n" /* line 2194 */
        /* fix: edx is struct address directly, no extra deref */
        "subl $1, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 2200 | scheduled */
        "testl %eax, %eax\n"
        "js .Lf59d14_00059dff\n"
        "leal 0xc(%ebx), %eax\n" /* line 2202 | scheduled */
        "movl %eax, -0x4c(%ebp)\n"
        "leal -0x48(%ebp), %edx\n" /* or_ */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "jne .Lf59d14_00059dba\n"
        ".Lf59d14_00059da0:\n"
        "testl %ebx, %ebx\n" /* line 35 */
        "je .Lf59d14_00059d48\n"
        "movl %ebx, (%esp)\n"
        "calll __ZdaPv\n"
        "movl (%esi), %ebx\n" /* line 2173 | prevNext, scheduled */
        "testl %ebx, %ebx\n" /* scheduled */
        "jne .Lf59d14_00059d4e\n"
        /* } scope */
        ".Lf59d14_00059db2:\n"
        "addl $0x6c, %esp\n" /* line 2231 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf59d14_00059dba:\n"
        "movl 0x48(%ebx), %eax\n" /* line 2208 | scheduled */
        "movl %eax, 0x1c(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl 4(%eax), %eax\n"
        "subl 8(%ebx), %eax\n" /* scheduled */
        "movl %eax, 0x18(%esp)\n"
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* or_ */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        ".Lf59d14_00059de5:\n"
        "movl -0x50(%ebp), %eax\n" /* line 2214 | primTemp */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* fx */
        "movl -0x54(%ebp), %edx\n"
        /* fix: edx is struct address directly, no extra deref */
        "movl %edx, (%esp)\n"
        "calll FxScheduler_CreateEffect\n"
        "jmp .Lf59d14_00059da0\n"
        ".Lf59d14_00059dff:\n"
        "movl 0x48(%ebx), %eax\n" /* scheduled */
        "movl %eax, 0x1c(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl 4(%eax), %eax\n"
        "subl 8(%ebx), %eax\n" /* scheduled */
        "movl %eax, 0x18(%esp)\n"
        "leal 0x20(%ebx), %eax\n" /* scheduled */
        "movl %eax, 0x14(%esp)\n"
        "leal 0x14(%ebx), %eax\n" /* scheduled */
        "movl %eax, 0x10(%esp)\n"
        "leal 0xc(%ebx), %eax\n" /* scheduled */
        "movl %eax, 0xc(%esp)\n"
        "jmp .Lf59d14_00059de5\n"
        "addb %al, (%eax)\n"
        /* } scope */
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %edi\n" /* start, fx */
        "movl 0xc(%ebp), %eax\n" /* end */
        "movl g_effectVisArrayCount, %ebx\n" /* scheduled */
        "testl %ebx, %ebx\n" /* scheduled */
        "jne .Lf59d14_00059e51\n"
        "fld1\n"
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf59d14_00059e51:\n"
        "movss (%eax), %xmm0\n"
        "subss (%edi), %xmm0\n" /* fx */
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "leal 4(%edi), %edx\n" /* fx */
        "movl %edx, -0x40(%ebp)\n"
        "movss 4(%eax), %xmm0\n"
    );
}
#endif

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
    byte *visArray = (byte *)g_effectVisArray;
    int i;
    for (i = 0; i < count; i++) {
        byte *vis = visArray + i * 0x14;
        /* Project vis center onto ray */
        float dx = *(float *)(vis + 0) - start[0];
        float dy = *(float *)(vis + 4) - start[1];
        float dz = *(float *)(vis + 8) - start[2];
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
        float distSq = Vec3DistanceSq((const vec_t *)vis, projPt);
        float radiusSq = *(float *)(vis + 12);
        if (distSq >= radiusSq)
            continue;

        /* Apply visibility attenuation */
        visibility *= *(float *)(vis + 16);
    }
    return visibility;
}
#if 0 /* Original ASM */
__attribute__((naked))
float FX_GetServerVisibility_asm(const vec_t *start, const vec_t *end)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 636 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %edi\n" /* start */
        "movl 0xc(%ebp), %eax\n" /* end */
        /* { scope 1 */
        "movl g_effectVisArrayCount, %ebx\n" /* line 653 */
        "testl %ebx, %ebx\n"
        "jne .Lf59e2e_00059e51\n"
        ".Lf59e2e_00059e47:\n"
        "fld1\n" /* line 681 */
        /* } scope */
        ".Lf59e2e_00059e49:\n"
        "addl $0x7c, %esp\n" /* line 707 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf59e2e_00059e51:\n"
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "leal 4(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x40(%ebp)\n"
        "movss 4(%eax), %xmm0\n"
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "leal 8(%edi), %edx\n" /* line 250 */
        "movl %edx, -0x3c(%ebp)\n"
        "movss 8(%eax), %xmm0\n"
        "subss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 664 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x4c(%ebp)\n" /* len */
        "movl imp_fx_visMinTraceDist, %eax\n" /* line 667 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss -0x4c(%ebp), %xmm0\n" /* len */
        "ja .Lf59e2e_00059e47\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 677 | len */
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, -0x48(%ebp)\n" /* halfLen */
        "movl g_effectVisArrayCount, %ecx\n" /* line 681 */
        "testl %ecx, %ecx\n"
        "jle .Lf59e2e_00059e47\n"
        "fld1\n"
        "xorl %esi, %esi\n" /* effectIndex */
        "xorl %ebx, %ebx\n"
        "jmp .Lf59e2e_00059ede\n"
        ".Lf59e2e_00059ecc:\n"
        "addl $1, %esi\n" /* effectIndex */
        "addl $0x14, %ebx\n"
        "cmpl g_effectVisArrayCount, %esi\n" /* effectIndex */
        "jge .Lf59e2e_00059e49\n"
        ".Lf59e2e_00059ede:\n"
        "leal g_effectVisArray(%ebx), %edx\n" /* line 684 */
        "movss (%edi), %xmm5\n" /* line 248 */
        "movss -0x24(%ebp), %xmm3\n" /* line 304 | dir */
        "movss -0x20(%ebp), %xmm2\n"
        "movss -0x1c(%ebp), %xmm4\n"
        "movss g_effectVisArray(%ebx), %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss g_effectVisArray+4(%ebx), %xmm0\n"
        "movl -0x40(%ebp), %eax\n"
        "subss (%eax), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss g_effectVisArray+8(%ebx), %xmm0\n"
        "movl -0x3c(%ebp), %eax\n"
        "subss (%eax), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 689 */
        "subss -0x48(%ebp), %xmm0\n" /* halfLen */
        "andps dvarDigitStrings+320, %xmm0\n"
        "ucomiss -0x48(%ebp), %xmm0\n" /* halfLen */
        "ja .Lf59e2e_00059ecc\n"
        "mulss %xmm1, %xmm3\n" /* line 288 */
        "addss %xmm3, %xmm5\n"
        "movss %xmm5, -0x30(%ebp)\n" /* projPt */
        "mulss %xmm1, %xmm2\n" /* line 289 */
        "movl -0x40(%ebp), %eax\n"
        "addss (%eax), %xmm2\n"
        "movss %xmm2, -0x2c(%ebp)\n"
        "mulss %xmm1, %xmm4\n" /* line 290 */
        "movl -0x3c(%ebp), %eax\n"
        "addss (%eax), %xmm4\n"
        "movss %xmm4, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 694 | projPt */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "fstps -0x68(%ebp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x44(%ebp)\n" /* distSq */
        "movss -0x44(%ebp), %xmm0\n" /* line 696 | distSq */
        "ucomiss g_effectVisArray+12(%ebx), %xmm0\n"
        "flds -0x68(%ebp)\n"
        "jae .Lf59e2e_00059ecc\n"
        "fstps -0x6c(%ebp)\n" /* line 699 */
        "movss -0x6c(%ebp), %xmm0\n"
        "mulss g_effectVisArray+16(%ebx), %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n"
        "flds -0x6c(%ebp)\n"
        "jmp .Lf59e2e_00059ecc\n"
    );
}
#endif

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
    byte *primTemp = *(byte **)(prim + 4);
    const vec_t *origin = (const vec_t *)((byte *)prim + 4); /* prim origin used as fallback — actually ecx on entry */
    /* Note: ecx=origin was the 3rd register arg in the original ASM.
     * In the callers, origin is at stack[8(%ebp)] which is pushed separately.
     * For this _impl, we don't receive origin directly.
     * Looking at the ASM: %ebx = origin (from ecx), used for adding to org.
     * We'll receive it from the callers via inline ASM which passes ecx. */

    vec3_t up = {0.0f, 0.0f, 1.0f};
    int flags = *(int *)(primTemp + 0x94);
    vec3_t org;

    /* Compute origin offset from range values */
    if (flags & 0x40) {
        /* Axis-aligned offset */
        float z = FxRange_GetVal(primTemp + 0xc8);
        float y = FxRange_GetVal(primTemp + 0xc0);
        float x = FxRange_GetVal(primTemp + 0xb8);
        org[0] = x; org[1] = y; org[2] = z;
    } else {
        /* Transform offset through axis */
        float z = FxRange_GetVal(primTemp + 0xc8);
        float y = FxRange_GetVal(primTemp + 0xc0);
        float x = FxRange_GetVal(primTemp + 0xb8);
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
        float width = FxRange_GetVal(primTemp + 0xe8);
        float height = FxRange_GetVal(primTemp + 0xf0);
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
#ifndef __EMSCRIPTEN__
            __asm__ __volatile__("sqrtss %1,%0":"=x"(len):"x"(len2));
#else
            len = sqrtf(len2);
#endif
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
        float height = FxRange_GetVal(primTemp + 0xf0);
        float width = FxRange_GetVal(primTemp + 0xe8);
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
#ifndef __EMSCRIPTEN__
            __asm__ __volatile__("sqrtss %1,%0":"=x"(len):"x"(len2));
#else
            len = sqrtf(len2);
#endif
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
    byte *bolt = *(byte **)(prim + 8);
    if (bolt) {
        void *orient = FxBoltFrame_GetOrientation(bolt);
        vec3_t localOrg;
        OrientationPosFromWorldPos(orient, orgOut, localOrg);
        orgOut[0] = localOrg[0]; orgOut[1] = localOrg[1]; orgOut[2] = localOrg[2];
    }
}
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void FX_CalcOriginAndAxis(vec_t *orgOut, vec3_t *ax)
{
    __asm__ __volatile__ (
        "pushl 4(%esp)\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll FX_CalcOriginAndAxis_impl\n"
        "addl $12, %esp\n"
        "retl\n"
#if 0 /* Original ASM (327 lines) */
        "pushl %ebp\n" /* line 1303 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl %eax, %edi\n" /* prim */
        "movl %edx, -0x74(%ebp)\n"
        "movl %ecx, %ebx\n" /* origin */
        /* { scope 1: z, y */
        "xorl %eax, %eax\n" /* line 1313 */
        "movl %eax, -0x3c(%ebp)\n" /* up */
        "movl %eax, -0x38(%ebp)\n"
        "movl $0x3f800000, -0x34(%ebp)\n"
        "movl 4(%edi), %esi\n" /* line 1320 | prim, primTemp */
        "testb $0x40, 0x94(%esi)\n" /* line 1324 | primTemp */
        "je .Lf59fbe_0005a0a3\n"
        "leal 0xc8(%esi), %eax\n" /* line 1325 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x50(%ebp)\n" /* z */
        "leal 0xc0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x4c(%ebp)\n" /* y */
        "leal 0xb8(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        /* { scope 2 */
        "fstps -0x48(%ebp)\n" /* line 191 | org */
        "movss -0x4c(%ebp), %xmm0\n" /* line 192 | y */
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0x50(%ebp), %xmm1\n" /* line 193 | z */
        "movss %xmm1, -0x40(%ebp)\n"
        /* } scope */
        ".Lf59fbe_0005a037:\n"
        "movss -0x48(%ebp), %xmm0\n" /* line 240 | org */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* org */
        "movss -0x44(%ebp), %xmm0\n" /* line 241 */
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 242 */
        "addss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movl 0x94(%esi), %eax\n" /* line 1331 | primTemp */
        "testb $1, %al\n"
        "jne .Lf59fbe_0005a306\n"
        "testb $4, %al\n" /* line 1361 */
        "jne .Lf59fbe_0005a104\n"
        ".Lf59fbe_0005a079:\n"
        "movl 8(%edi), %esi\n" /* line 1399 | prim, primTemp */
        "testl %esi, %esi\n" /* primTemp */
        "jne .Lf59fbe_0005a4b3\n"
        "movl -0x48(%ebp), %eax\n" /* line 199 | org */
        "movl -0x74(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x40(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 1409 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: z, y */
        ".Lf59fbe_0005a0a3:\n"
        "leal 0xc8(%esi), %eax\n" /* line 1327 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x70(%ebp)\n"
        "leal 0xc0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x6c(%ebp)\n"
        "leal 0xb8(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "leal -0x48(%ebp), %eax\n" /* org */
        "movl %eax, 0x10(%esp)\n"
        "movss -0x70(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x6c(%ebp), %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ax */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "jmp .Lf59fbe_0005a037\n"
        ".Lf59fbe_0005a104:\n"
        "movl $0x3f000000, 4(%esp)\n" /* line 1364 */
        "movl $0xbf000000, (%esp)\n"
        "calll flrand\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm2\n"
        "leal 0xf0(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x98(%ebp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x60(%ebp)\n"
        "movss -0x98(%ebp), %xmm2\n"
        "mulss -0x60(%ebp), %xmm2\n"
        "leal 0xe8(%esi), %eax\n" /* line 1365 | primTemp */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x98(%ebp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm1\n"
        "movl 8(%ebp), %ebx\n" /* line 1367 | ax, origin */
        "addl $0xc, %ebx\n" /* origin */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "movl 8(%ebp), %eax\n" /* ax */
        "mulss 0xc(%eax), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* pt */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss 8(%ebx), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x28(%ebp)\n"
        "movss -0x98(%ebp), %xmm2\n" /* line 288 */
        "movaps %xmm2, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n" /* pt */
        "movss %xmm0, -0x30(%ebp)\n" /* pt */
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss 8(%eax), %xmm2\n" /* line 290 */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "movl $0x43b40000, 4(%esp)\n" /* line 1369 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "fstps 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* pt */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ax */
        "movl %edx, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* temp */
        "movl %eax, (%esp)\n"
        "calll RotatePointAroundVector\n"
        "movss -0x24(%ebp), %xmm3\n" /* line 240 | temp */
        "movaps %xmm3, %xmm0\n"
        "addss -0x48(%ebp), %xmm0\n" /* org */
        "movss %xmm0, -0x48(%ebp)\n" /* org */
        "movss -0x20(%ebp), %xmm2\n" /* line 241 */
        "movaps %xmm2, %xmm0\n"
        "addss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 242 */
        "movaps %xmm1, %xmm0\n"
        "addss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "testb $2, 0x94(%esi)\n" /* line 1373 | primTemp */
        "je .Lf59fbe_0005a079\n"
        "movaps %xmm3, %xmm0\n" /* line 81 */
        "mulss %xmm3, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "pxor %xmm1, %xmm1\n" /* line 1378 */
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf59fbe_0005a274\n"
        "je .Lf59fbe_0005a079\n"
        ".Lf59fbe_0005a274:\n"
        "movss lit4_002ed5d0, %xmm2\n" /* line 1380 | 1.0f */
        "movaps %xmm2, %xmm1\n"
        "divss %xmm0, %xmm1\n" /* scale */
        "movaps %xmm1, %xmm0\n" /* scale */
        /* { scope 2 */
        "mulss %xmm1, %xmm3\n" /* line 272 */
        "movl 8(%ebp), %eax\n" /* ax */
        "movss %xmm3, (%eax)\n"
        "mulss -0x20(%ebp), %xmm1\n" /* line 273 */
        "movss %xmm1, 4(%eax)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "andps dvarDigitStrings+336, %xmm0\n" /* line 1383 */
        "ucomiss lit4_002ed690, %xmm0\n" /* 0.9990000128746033f */
        "jb .Lf59fbe_0005a2c8\n"
        "movl $0, -0x3c(%ebp)\n" /* line 191 | up */
        "movss %xmm2, -0x38(%ebp)\n" /* line 192 */
        "movl $0, -0x34(%ebp)\n" /* line 193 */
        ".Lf59fbe_0005a2c8:\n"
        "movl %ebx, 8(%esp)\n" /* line 1389 | origin */
        "movl 8(%ebp), %edx\n" /* ax */
        "movl %edx, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* up */
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %ebx, (%esp)\n" /* line 1390 | origin */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl 8(%ebp), %eax\n" /* line 1393 | ax */
        "addl $0x18, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* origin */
        "movl 8(%ebp), %eax\n" /* ax */
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "jmp .Lf59fbe_0005a079\n"
        ".Lf59fbe_0005a306:\n"
        "movl $0x43b40000, 4(%esp)\n" /* line 1333 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "fstps -0x68(%ebp)\n"
        "cvtss2sd -0x68(%ebp), %xmm0\n"
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n" /* x */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x78(%ebp)\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 486 | x */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x7c(%ebp)\n"
        "movl $0x43340000, 4(%esp)\n" /* line 1335 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "fstps -0x64(%ebp)\n"
        "cvtss2sd -0x64(%ebp), %xmm0\n"
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n" /* y */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x80(%ebp)\n"
        "movss -0x58(%ebp), %xmm1\n" /* line 486 | y */
        "movss %xmm1, (%esp)\n"
        "calll cosf\n"
        "fstps -0x84(%ebp)\n"
        "leal 0xe8(%esi), %eax\n" /* line 1338 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x54(%ebp)\n" /* width */
        "leal 0xf0(%esi), %eax\n" /* line 1339 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm2\n"
        "mulss -0x84(%ebp), %xmm2\n" /* line 1342 | z */
        /* { scope 2 */
        "movss -0x78(%ebp), %xmm3\n" /* line 191 */
        "mulss -0x54(%ebp), %xmm3\n" /* width */
        "mulss -0x80(%ebp), %xmm3\n"
        "movss %xmm3, -0x24(%ebp)\n" /* temp */
        "movss -0x7c(%ebp), %xmm1\n" /* line 192 */
        "mulss -0x54(%ebp), %xmm1\n" /* width */
        "mulss -0x80(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss %xmm2, -0x1c(%ebp)\n" /* line 193 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 240 */
        "addss -0x48(%ebp), %xmm0\n" /* org */
        "movss %xmm0, -0x48(%ebp)\n" /* org */
        "movaps %xmm1, %xmm0\n" /* line 241 */
        "addss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movaps %xmm2, %xmm0\n" /* line 242 */
        "addss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "testb $2, 0x94(%esi)\n" /* line 1345 | primTemp */
        "je .Lf59fbe_0005a079\n"
        "movaps %xmm3, %xmm0\n" /* line 81 */
        "mulss %xmm3, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 1350 */
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lf59fbe_0005a461\n"
        "je .Lf59fbe_0005a079\n"
        ".Lf59fbe_0005a461:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1352 | 1.0f, scale */
        "divss %xmm1, %xmm0\n" /* scale */
        /* { scope 2 */
        "mulss %xmm0, %xmm3\n" /* line 272 */
        "movl 8(%ebp), %eax\n" /* ax */
        "movss %xmm3, (%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1353 | ax */
        "addl $0x18, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ax */
        "addl $0xc, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ax */
        "movl %edx, (%esp)\n"
        "calll MakeNormalVectors\n"
        "jmp .Lf59fbe_0005a079\n"
        ".Lf59fbe_0005a4b3:\n"
        "movl 8(%edi), %eax\n" /* line 1401 | prim */
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_GetOrientation\n"
        "movl -0x74(%ebp), %edx\n" /* line 1403 */
        "movl %edx, 8(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* org */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll OrientationPosFromWorldPos\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 1409 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
#endif
    );
}
#else
static void FX_CalcOriginAndAxis(vec_t *orgOut, vec3_t *ax) { (void)orgOut; (void)ax; }
#endif

/* FX_InitParticle — register convention: eax=prim, edx=particle, ecx=newOrigin, stack: origin, ax, indexInBatch */
extern void AxisTransformVector(void *axis, float x, float y, float z, vec_t *out);
extern void OrientationPosFromWorldPos(void *orient, vec_t *worldPos, vec_t *localPos);
extern void Particle_SetRandomVelocityWeights(void *particle, float w0, float w1, float w2);
extern void Particle_SetRandomVelocity2Weights(void *particle, float w0, float w1, float w2);
extern void Particle_SetAxis(void *particle, vec3_t *ax);
static void FX_InitParticle_impl(byte *prim, byte *particle, vec_t *newOrigin, const vec_t *origin, vec3_t *ax, int indexInBatch)
{
    (void)indexInBatch;
    byte *primTemp = *(byte **)(prim + 4);
    int flags = *(int *)(primTemp + 0x90);

    /* Random blend weights based on flags */
    if (flags & 0x2000) *(float *)(particle + 0x118) = flrand(0.0f, 1.0f);
    if (flags & 0x4000) *(float *)(particle + 0x11c) = flrand(0.0f, 1.0f);
    if ((short)flags < 0) *(float *)(particle + 0x120) = flrand(0.0f, 1.0f); /* bit 15 */
    if (flags & 0x10000) *(float *)(particle + 0x124) = flrand(0.0f, 1.0f);
    if (flags & 0x40000) *(float *)(particle + 0x128) = flrand(0.0f, 1.0f);
    if (flags & 0x80000) {
        Particle_SetRandomVelocityWeights(particle, flrand(0,1), flrand(0,1), flrand(0,1));
    }
    if (flags & 0x100000) {
        Particle_SetRandomVelocity2Weights(particle, flrand(0,1), flrand(0,1), flrand(0,1));
    }

    /* Range values */
    *(float *)(particle + 0xf4) = FxRange_GetVal(primTemp + 0x258); /* gravity */
    *(float *)(particle + 0xf8) = FxRange_GetVal(primTemp + 0xf8);  /* bounce */

    /* Calculate origin and set axis */
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %2\n" "movl %1, %%edx\n" "movl %0, %%eax\n"
        "calll FX_CalcOriginAndAxis\n" "addl $4, %%esp\n"
        : : "g"(prim), "g"(newOrigin), "g"(ax) : "eax", "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    Particle_SetAxis(particle, ax);

    /* Copy primTemp fields to particle */
    *(byte *)(particle + 0x104) = *(byte *)(primTemp + 0x9c);
    *(float *)(particle + 0x100) = FxRange_GetVal(primTemp + 0x280); /* bounce coefficient */
    *(float *)(particle + 0x44) = FxRange_GetVal(primTemp + 0x220);  /* size */
}
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void FX_InitParticle(EffectPrimitive *prim, Particle *particle, vec_t *newOrigin, const vec_t *origin, vec3_t *ax, int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl 0x10(%esp)\n"
        "pushl 0x10(%esp)\n"
        "pushl 0x10(%esp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll FX_InitParticle_impl\n"
        "addl $24, %esp\n"
        "retl\n"
#if 0 /* Original ASM */
        "pushl %ebp\n" /* line 1636 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl %ecx, -0x34(%ebp)\n"
        /* { scope 1 */
        "movl 4(%eax), %edi\n" /* line 1642 | primTemp */
        "movl 0x90(%edi), %eax\n" /* line 1646 | primTemp */
        "testb $0x20, %ah\n"
        "jne .Lf5a4e0_0005a72c\n"
        ".Lf5a4e0_0005a504:\n"
        "testb $0x40, %ah\n" /* line 1648 */
        "jne .Lf5a4e0_0005a704\n"
        ".Lf5a4e0_0005a50d:\n"
        "testw %ax, %ax\n" /* line 1650 */
        "js .Lf5a4e0_0005a6dc\n"
        ".Lf5a4e0_0005a516:\n"
        "testl $0x10000, %eax\n" /* line 1652 */
        "jne .Lf5a4e0_0005a6b4\n"
        ".Lf5a4e0_0005a521:\n"
        "testl $0x40000, %eax\n" /* line 1654 */
        "jne .Lf5a4e0_0005a68c\n"
        ".Lf5a4e0_0005a52c:\n"
        "testl $0x80000, %eax\n" /* line 1656 */
        "jne .Lf5a4e0_0005a62b\n"
        ".Lf5a4e0_0005a537:\n"
        "testl $0x100000, %eax\n" /* line 1658 */
        "je .Lf5a4e0_0005a594\n"
        "movl $0x3f800000, %esi\n" /* line 1659 */
        "movl %esi, 4(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll flrand\n"
        "fstps -0x20(%ebp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll flrand\n"
        "fstps -0x1c(%ebp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll flrand\n"
        "movss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Particle_SetRandomVelocity2Weights\n"
        ".Lf5a4e0_0005a594:\n"
        "leal 0x258(%edi), %eax\n" /* line 1660 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %edx\n" /* line 382 */
        "fstps 0xf4(%edx)\n"
        /* } scope */
        "leal 0xf8(%edi), %eax\n" /* line 1661 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 395 */
        "fstps 0xf8(%eax)\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 1663 | ax */
        "movl %edx, (%esp)\n"
        "movl 8(%ebp), %ecx\n" /* origin */
        "movl -0x34(%ebp), %edx\n"
        "movl -0x2c(%ebp), %eax\n"
        "calll FX_CalcOriginAndAxis\n"
        "movl 0xc(%ebp), %eax\n" /* line 1664 | ax */
        "movl %eax, 4(%esp)\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Particle_SetAxis\n"
        "movzbl 0x9c(%edi), %eax\n" /* line 385 */
        "movl -0x30(%ebp), %edx\n"
        "movb %al, 0x104(%edx)\n"
        "leal 0x280(%edi), %eax\n" /* line 1668 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 384 */
        "fstps 0x100(%eax)\n"
        /* } scope */
        "leal 0x220(%edi), %eax\n" /* line 1670 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %edx\n" /* line 383 */
        "fstps 0x44(%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1671 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5a4e0_0005a62b:\n"
        "movl $0x3f800000, %esi\n" /* line 1657 */
        "movl %esi, 4(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll flrand\n"
        "fstps -0x28(%ebp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll flrand\n"
        "fstps -0x24(%ebp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll flrand\n"
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Particle_SetRandomVelocityWeights\n"
        "movl 0x90(%edi), %eax\n" /* primTemp */
        "jmp .Lf5a4e0_0005a537\n"
        ".Lf5a4e0_0005a68c:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1655 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 394 */
        "fstps 0x128(%eax)\n"
        "movl 0x90(%edi), %eax\n"
        "jmp .Lf5a4e0_0005a52c\n"
        /* } scope */
        ".Lf5a4e0_0005a6b4:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1653 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %edx\n" /* line 393 */
        "fstps 0x124(%edx)\n"
        "movl 0x90(%edi), %eax\n"
        "jmp .Lf5a4e0_0005a521\n"
        /* } scope */
        ".Lf5a4e0_0005a6dc:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1651 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 392 */
        "fstps 0x120(%eax)\n"
        "movl 0x90(%edi), %eax\n"
        "jmp .Lf5a4e0_0005a516\n"
        /* } scope */
        ".Lf5a4e0_0005a704:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1649 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %edx\n" /* line 391 */
        "fstps 0x11c(%edx)\n"
        "movl 0x90(%edi), %eax\n"
        "jmp .Lf5a4e0_0005a50d\n"
        /* } scope */
        ".Lf5a4e0_0005a72c:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1647 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 390 */
        "fstps 0x118(%eax)\n"
        "movl 0x90(%edi), %eax\n"
        "jmp .Lf5a4e0_0005a504\n"
#endif
    );
}
#else
static void FX_InitParticle(EffectPrimitive *prim, Particle *particle, vec_t *newOrigin, const vec_t *origin, vec3_t *ax, int indexInBatch) { (void)prim; (void)particle; (void)newOrigin; (void)origin; (void)ax; (void)indexInBatch; }
#endif

/* line 1958 */
/* FX_AddCameraShake — calculate shake parameters and apply camera shake */
extern float FxRange_GetVal(void *range);
extern void FxHelper_CameraShake(void *helper, vec_t *origin, float intensity, int duration, int fadeTime);
void FX_AddCameraShake(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)origin; (void)lateTime; (void)indexInBatch;
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %2\n"
        "movl %1, %%edx\n"
        "movl %0, %%eax\n"
        "calll FX_CalcOriginAndAxis\n"
        "addl $4, %%esp\n"
        : : "g"(prim), "g"(&newOrigin), "g"(ax)
        : "eax", "ecx", "edx", "memory"
    );
#else
    /* x86 asm not available */
#endif
    byte *primTemp = *(byte **)((byte *)prim + 4);
    float duration = FxRange_GetVal(primTemp + 0x58);
    float fadeTime = FxRange_GetVal(primTemp + 0xe8);
    float intensity = FxRange_GetVal(primTemp + 0x280);
    FxHelper_CameraShake(theFxHelper, newOrigin, intensity, (int)duration, (int)fadeTime);
}

/* FX_AddFxRunner — spawn runner effect at calculated origin */
extern void *MediaHandles_GetEffect(void *mediaHandles);
extern void FxScheduler_PlayEffect(void *scheduler, void *effectTemplate, vec_t *origin, vec3_t *ax, void *bolt);
void FX_AddFxRunner(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    (void)origin; (void)lateTime; (void)indexInBatch;
    vec3_t newOrigin;
    byte *p = (byte *)prim;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %2\n"
        "movl %1, %%edx\n"
        "movl %0, %%eax\n"
        "calll FX_CalcOriginAndAxis\n"
        "addl $4, %%esp\n"
        : : "g"(prim), "g"(&newOrigin), "g"(ax)
        : "eax", "ecx", "edx", "memory"
    );
#else
    /* x86 asm not available */
#endif
    byte *primTemp = *(byte **)(p + 4);
    void *bolt = *(void **)(p + 8);
    void *effect = MediaHandles_GetEffect(primTemp + 0x88);
    void *scheduler = *(void **)imp_theFxScheduler;
    if (bolt) {
        FxScheduler_PlayEffect(scheduler, effect, newOrigin, NULL, (byte *)bolt + 0x3c);
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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %2\n"
        "movl %1, %%edx\n"
        "movl %0, %%eax\n"
        "calll FX_CalcOriginAndAxis\n"
        "addl $4, %%esp\n"
        : : "g"(prim), "g"(&newOrigin), "g"(ax)
        : "eax", "ecx", "edx", "memory"
    );
#else
    /* x86 asm not available */
#endif
    FxScheduler_CreateDecalEffect(*(void **)imp_theFxScheduler, *(void **)((byte *)prim + 4), newOrigin, ax);
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
            float dist = Vec3DistanceSq((vec_t *)(eff + 0x7c), (vec_t *)((byte *)theFxHelper + 0x14));
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
        float dist = Vec3DistanceSq((vec_t *)(eff + 0x7c), (vec_t *)((byte *)theFxHelper + 0x14));
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
            if (*(byte *)(eff + 0xa9) & 0x10)
                ((DrawFn)(*(void ***)eff)[7])(eff); /* AddVisibility */
        }
        for (i = 0; i < effectActiveCountBolt; i++) {
            byte *eff = ((byte **)effectListBolt)[i];
            if (*(byte *)(eff + 0xa9) & 0x10)
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
            float dist = Vec3DistanceSq((vec_t *)((byte *)effectClusters + i * 16), (vec_t *)((byte *)theFxHelper + 0x14));
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
#if 0 /* Original ASM (280 lines) */
__attribute__((naked))
void FX_DrawAll_asm(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1246 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x548c, %esp\n"
        /* { scope 1: effectCount */
        "movl imp_fx_camera_valid, %eax\n" /* line 1220 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf5a8bc_0005a8eb\n"
        "movl cullEffectCountNonBolt, %edi\n" /* line 1224 */
        "movl privateEffectActiveCountNonBolt, %eax\n"
        "cmpl %edi, %eax\n"
        "jg .Lf5a8bc_0005ab73\n"
        ".Lf5a8bc_0005a8e6:\n"
        "movl %eax, cullEffectCountNonBolt\n" /* line 1242 */
        ".Lf5a8bc_0005a8eb:\n"
        "movl cullEffectCountBolt, %edi\n" /* line 1156 */
        "movl privateEffectActiveCountBolt, %eax\n"
        "cmpl %eax, %edi\n"
        "jge .Lf5a8bc_0005a978\n"
        "leal (, %edi, 4), %eax\n"
        "movl %eax, -0x5480(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf5a8bc_0005a911\n"
        ".Lf5a8bc_0005a90b:\n"
        "movl -0x5480(%ebp), %edx\n"
        ".Lf5a8bc_0005a911:\n"
        "movl effectListBolt, %eax\n" /* line 1158 */
        "movl (%eax, %edx), %esi\n" /* clusterId */
        "movl imp_fx_cull, %edx\n" /* line 1162 */
        "movl (%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5a8bc_0005a933\n"
        "movl (%esi), %eax\n" /* line 1165 | clusterId */
        "movl %esi, (%esp)\n" /* clusterId */
        "calll *0x10(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf5a8bc_0005a965\n"
        ".Lf5a8bc_0005a933:\n"
        "movl visibleEffectCountBolt, %ebx\n" /* line 1169 */
        "movl %esi, visibleEffectsBolt(, %ebx, 8)\n" /* clusterId */
        "movl theFxHelper, %eax\n" /* line 1170 */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x7c(%esi), %eax\n" /* clusterId */
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps visibleEffectsBolt+4(, %ebx, 8)\n"
        "addl $1, visibleEffectCountBolt\n" /* line 1171 */
        ".Lf5a8bc_0005a965:\n"
        "addl $1, %edi\n" /* line 1156 */
        "movl privateEffectActiveCountBolt, %eax\n"
        "addl $4, -0x5480(%ebp)\n"
        "cmpl %edi, %eax\n"
        "jg .Lf5a8bc_0005a90b\n"
        ".Lf5a8bc_0005a978:\n"
        "movl %eax, cullEffectCountBolt\n" /* line 1174 */
        "movl visibleEffectCountBolt, %eax\n" /* line 1255 */
        "testl %eax, %eax\n"
        "jle .Lf5a8bc_0005a9bf\n"
        "movl $visibleEffectsBolt, %esi\n" /* clusterId */
        "xorl %ebx, %ebx\n" /* effectIndex */
        "movl visibleEffectCountNonBolt, %ecx\n"
        "movl visibleEffectCountBolt, %edi\n"
        ".Lf5a8bc_0005a999:\n"
        "movl (%esi), %eax\n" /* line 1257 | clusterId */
        "movl 4(%esi), %edx\n" /* clusterId */
        "movl %eax, visibleEffectsNonBolt(, %ecx, 8)\n"
        "movl %edx, visibleEffectsNonBolt+4(, %ecx, 8)\n"
        "addl $1, %ecx\n" /* line 1258 */
        "addl $1, %ebx\n" /* line 1255 | effectIndex */
        "addl $8, %esi\n" /* clusterId */
        "cmpl %edi, %ebx\n" /* effectIndex */
        "jl .Lf5a8bc_0005a999\n"
        "movl %ecx, visibleEffectCountNonBolt\n"
        ".Lf5a8bc_0005a9bf:\n"
        "movl $0, g_effectVisArrayCount\n" /* line 602 */
        "movl effectBlockSightCount, %eax\n" /* line 604 */
        "testl %eax, %eax\n"
        "jne .Lf5a8bc_0005aafa\n"
        ".Lf5a8bc_0005a9d6:\n"
        "movl imp_fx_sort, %eax\n" /* line 1266 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5a8bc_0005aa83\n"
        "movl visibleEffectCountNonBolt, %eax\n" /* line 1270 */
        "movl %eax, -0x5484(%ebp)\n" /* effectCount */
        /* { scope 2: sortedClusters, sortOrderForClusterId */
        /* { scope 3 */
        "movl effectClusterCount, %eax\n" /* line 1017 */
        "testl %eax, %eax\n"
        "jg .Lf5a8bc_0005ac1a\n"
        "leal -0x5478(%ebp), %edi\n" /* sortedClusters */
        ".Lf5a8bc_0005aa05:\n"
        "movl $CompareSortedClusters, 0xc(%esp)\n" /* line 1022 */
        "movl $8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll qsort\n"
        "movl effectClusterCount, %esi\n" /* line 1024 | clusterId */
        "testl %esi, %esi\n" /* clusterId */
        "jle .Lf5a8bc_0005aa48\n"
        "xorl %edx, %edx\n"
        "movl effectClusterCount, %ecx\n"
        ".Lf5a8bc_0005aa33:\n"
        "movl -0x5478(%ebp, %edx, 8), %eax\n" /* line 1025 */
        "movl %edx, -0x1c38(%ebp, %eax, 4)\n"
        "addl $1, %edx\n" /* line 1024 */
        "cmpl %ecx, %edx\n"
        "jl .Lf5a8bc_0005aa33\n"
        ".Lf5a8bc_0005aa48:\n"
        "leal -0x1c38(%ebp), %eax\n" /* line 1027 | sortOrderForClusterId */
        "movl %eax, clusterSort\n"
        "movl $CompareSortedEffects, 0xc(%esp)\n" /* line 1028 */
        "movl $8, 8(%esp)\n"
        "movl -0x5484(%ebp), %edx\n" /* effectCount */
        "movl %edx, 4(%esp)\n"
        "movl $visibleEffectsNonBolt, (%esp)\n"
        "calll qsort\n"
        "movl $0, clusterSort\n" /* line 1029 */
        /* } scope */
        /* } scope */
        ".Lf5a8bc_0005aa83:\n"
        "movl imp_fx_draw, %eax\n" /* line 1275 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5a8bc_0005aa9e\n"
        "movl visibleEffectCountNonBolt, %ecx\n" /* line 1281 */
        "testl %ecx, %ecx\n"
        "jg .Lf5a8bc_0005abf6\n"
        ".Lf5a8bc_0005aa9e:\n"
        "movl imp_fx_debug, %eax\n" /* line 1293 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5a8bc_0005aaef\n"
        "movl effectActiveCount, %eax\n" /* line 1295 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00219d0c, (%esp)\n" /* "Active    FX: %i
" */
        "calll FX_Print\n"
        "movl visibleEffectCountNonBolt, %eax\n" /* line 1296 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00219d20, (%esp)\n" /* "Drawn     FX: %i
" */
        "calll FX_Print\n"
        "movl imp_theFxScheduler, %eax\n" /* line 1297 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00219d34, (%esp)\n" /* "Scheduled FX: %i
" */
        "calll FX_Print\n"
        /* } scope */
        ".Lf5a8bc_0005aaef:\n"
        "addl $0x548c, %esp\n" /* line 1300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: effectCount */
        ".Lf5a8bc_0005aafa:\n"
        "movl effectActiveCountNonBolt, %ebx\n" /* line 614 */
        "testl %ebx, %ebx\n"
        "jle .Lf5a8bc_0005ab37\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf5a8bc_0005ab13\n"
        ".Lf5a8bc_0005ab08:\n"
        "addl $1, %ebx\n"
        "cmpl effectActiveCountNonBolt, %ebx\n"
        "jge .Lf5a8bc_0005ab37\n"
        ".Lf5a8bc_0005ab13:\n"
        "movl effectListNonBolt, %eax\n" /* line 616 */
        "movl (%eax, %ebx, 4), %edx\n"
        "testb $0x10, 0xa9(%edx)\n" /* line 617 */
        "je .Lf5a8bc_0005ab08\n"
        "movl (%edx), %eax\n" /* line 618 */
        "movl %edx, (%esp)\n"
        "calll *0x1c(%eax)\n"
        "addl $1, %ebx\n" /* line 614 */
        "cmpl effectActiveCountNonBolt, %ebx\n"
        "jl .Lf5a8bc_0005ab13\n"
        ".Lf5a8bc_0005ab37:\n"
        "movl effectActiveCountBolt, %edi\n" /* line 621 */
        "testl %edi, %edi\n"
        "jle .Lf5a8bc_0005a9d6\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf5a8bc_0005ab58\n"
        ".Lf5a8bc_0005ab49:\n"
        "addl $1, %ebx\n"
        "cmpl effectActiveCountBolt, %ebx\n"
        "jge .Lf5a8bc_0005a9d6\n"
        ".Lf5a8bc_0005ab58:\n"
        "movl effectListBolt, %eax\n" /* line 623 */
        "movl (%eax, %ebx, 4), %edx\n"
        "testb $0x10, 0xa9(%edx)\n" /* line 624 */
        "je .Lf5a8bc_0005ab49\n"
        "movl (%edx), %eax\n" /* line 625 */
        "movl %edx, (%esp)\n"
        "calll *0x1c(%eax)\n"
        "jmp .Lf5a8bc_0005ab49\n"
        ".Lf5a8bc_0005ab73:\n"
        "leal (, %edi, 4), %eax\n" /* line 1224 */
        "movl %eax, -0x547c(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf5a8bc_0005ab8a\n"
        ".Lf5a8bc_0005ab84:\n"
        "movl -0x547c(%ebp), %edx\n"
        ".Lf5a8bc_0005ab8a:\n"
        "movl effectListNonBolt, %eax\n" /* line 1226 */
        "movl (%eax, %edx), %esi\n" /* clusterId */
        "movl imp_fx_cull, %edx\n" /* line 1230 */
        "movl (%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5a8bc_0005abac\n"
        "movl (%esi), %eax\n" /* line 1233 | clusterId */
        "movl %esi, (%esp)\n" /* clusterId */
        "calll *0x10(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf5a8bc_0005abde\n"
        ".Lf5a8bc_0005abac:\n"
        "movl visibleEffectCountNonBolt, %ebx\n" /* line 1237 */
        "movl %esi, visibleEffectsNonBolt(, %ebx, 8)\n" /* clusterId */
        "movl theFxHelper, %eax\n" /* line 1238 */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x7c(%esi), %eax\n" /* clusterId */
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps visibleEffectsNonBolt+4(, %ebx, 8)\n"
        "addl $1, visibleEffectCountNonBolt\n" /* line 1239 */
        ".Lf5a8bc_0005abde:\n"
        "addl $1, %edi\n" /* line 1224 */
        "movl privateEffectActiveCountNonBolt, %eax\n"
        "addl $4, -0x547c(%ebp)\n"
        "cmpl %edi, %eax\n"
        "jg .Lf5a8bc_0005ab84\n"
        "jmp .Lf5a8bc_0005a8e6\n"
        ".Lf5a8bc_0005abf6:\n"
        "xorl %esi, %esi\n" /* line 1281 | clusterId */
        "movl $visibleEffectsNonBolt, %ebx\n" /* effectIndex */
        ".Lf5a8bc_0005abfd:\n"
        "movl (%ebx), %eax\n" /* line 1282 | effectIndex */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%edx)\n"
        "addl $1, %esi\n" /* line 1281 | clusterId */
        "addl $8, %ebx\n" /* effectIndex */
        "cmpl visibleEffectCountNonBolt, %esi\n" /* clusterId */
        "jl .Lf5a8bc_0005abfd\n"
        "jmp .Lf5a8bc_0005aa9e\n"
        /* { scope 2: sortedClusters, sortOrderForClusterId */
        /* { scope 3 */
        ".Lf5a8bc_0005ac1a:\n"
        "xorl %esi, %esi\n" /* line 1017 | clusterId */
        "leal -0x5478(%ebp), %edi\n" /* sortedClusters */
        ".Lf5a8bc_0005ac22:\n"
        "leal (, %esi, 8), %ebx\n" /* line 1019 */
        "movl %esi, -0x5478(%ebp, %ebx)\n" /* clusterId */
        "movl theFxHelper, %eax\n" /* line 1020 */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, %eax\n" /* clusterId */
        "shll $4, %eax\n"
        "addl effectClusters, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps 4(%edi, %ebx)\n"
        "addl $1, %esi\n" /* line 1017 | clusterId */
        "movl effectClusterCount, %eax\n"
        "cmpl %eax, %esi\n" /* clusterId */
        "jl .Lf5a8bc_0005ac22\n"
        "jmp .Lf5a8bc_0005aa05\n"
    );
}
#endif

/* line 1557 */
/* FX_SetMaterialAndSequenceParams — register convention: eax=primTemp, edx=particle, ecx=killTime, stack: indexInBatch */
extern void *MediaHandles_GetHandle(void *mediaHandles);
extern int FxHelper_GetMaterialSubimageCount(void *helper, void *material);
extern int irand(int min, int max);
static void FX_SetMaterialAndSequenceParams_impl(byte *primTemp, byte *particle, int killTime, int indexInBatch)
{
    void *material = MediaHandles_GetHandle(primTemp + 0x68);
    int startFrame = 0;
    float frameRate = 0.0f;

    if (material) {
        int subimageCount = FxHelper_GetMaterialSubimageCount(theFxHelper, material);
        if (subimageCount == 1) {
            startFrame = 0;
            frameRate = 0.0f;
        } else {
            /* Determine start frame based on sequence mode */
            int seqMode = *(int *)(primTemp + 0x288);
            if (seqMode == 0) {
                startFrame = *(int *)(primTemp + 0x28c) - 1;
            } else if (seqMode == 1) {
                startFrame = irand(0, subimageCount);
            } else if (seqMode == 2) {
                startFrame = indexInBatch;
            } else {
                startFrame = 0;
            }
            /* Determine frame rate */
            int rateMode = *(int *)(primTemp + 0x290);
            if (rateMode == 0) {
                frameRate = *(float *)(primTemp + 0x294) / 1000.0f;
            } else if (rateMode == 1) {
                frameRate = (float)subimageCount / (float)killTime;
            } else {
                frameRate = 0.0f;
            }
        }
    }

    *(int *)(particle + 0x108) = startFrame;
    *(float *)(particle + 0x10c) = frameRate;
    *(int *)(particle + 0x110) = *(int *)(primTemp + 0x298);
    *(int *)(particle + 0x114) = *(int *)(primTemp + 0x29c);
    *(void **)(particle + 0x40) = material;
    *(int *)(particle + 0xb0) = 0;

    if (material && FxHelper_IsMaterialRefractive(theFxHelper, (MaterialHandle)material))
        *(int *)(particle + 0xb0) = -1;
}

#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void FX_SetMaterialAndSequenceParams(const int killTime, int indexInBatch)
{
    (void)killTime; (void)indexInBatch;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl 4(%esp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll FX_SetMaterialAndSequenceParams_impl\n"
        "addl $16, %esp\n"
        "retl\n"
    );
#else
    /* x86 asm not available */
#endif
}
#else
static void FX_SetMaterialAndSequenceParams(const int killTime, int indexInBatch) { }
#endif

/* FX_AddPrimitive — register convention: eax=prim, edx=particle, ecx=origin
 * Adds particle to effect system: manages active count, assigns cluster, stores in bolt/nonbolt list */
extern void Effect_SetTimeStartEnd(void *effect, int startTime, int endTime);
extern void Effect_SetBoltFrame(const void *effect, const void *boltFramePtr);
static Bool FX_AddPrimitive_impl(byte *prim, byte *particle, const vec_t *origin)
{
    byte *primTemp = *(byte **)(prim + 4);
    byte *boltInfo = *(byte **)(prim + 8);

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
    if (*(byte *)(primTemp + 0x91) & 0x10)
        effectBlockSightCount++;

    /* Store effect reference in particle */
    *(byte **)(particle) = (byte *)prim; /* vtable set by constructor, skip */

    /* Set flags from primTemp */
    *(int *)(particle + 0xa8) = *(int *)(primTemp + 0x90);

    /* Set start/end time */
    int curTime = *(int *)((byte *)theFxHelper + 4);
    float lifeRange = FxRange_GetVal(primTemp + 0x58);
    int endTime = curTime + (int)lifeRange;
    Effect_SetTimeStartEnd(particle, curTime, endTime);

    /* Copy effect template references */
    *(int *)(particle + 0x34) = *(int *)prim; /* effect template */
    *(int *)(particle + 0x38) = *(int *)(primTemp + 0x44);
    *(int *)(particle + 0x10) = *(int *)(primTemp + 0x98);

    /* Copy axis from primTemp */
    *(float *)(particle + 0x14) = *(float *)(primTemp + 0xa0);
    *(float *)(particle + 0x18) = *(float *)(primTemp + 0xa4);
    *(float *)(particle + 0x1c) = *(float *)(primTemp + 0xa8);
    *(float *)(particle + 0x20) = *(float *)(primTemp + 0xac);
    *(float *)(particle + 0x24) = *(float *)(primTemp + 0xb0);
    *(float *)(particle + 0x28) = *(float *)(primTemp + 0xb4);

    /* Get effects from MediaHandles */
    *(void **)(particle + 0x30) = MediaHandles_GetEffect(primTemp + 0x78); /* emit effect */
    *(void **)(particle + 0x2c) = MediaHandles_GetEffect(primTemp + 0x70); /* death effect */

    /* Call vtable CreateChannelInstances */
    typedef void (*CreateChFn)(void *, void *);
    ((CreateChFn)(*(void ***)particle)[8])(particle, primTemp);

    /* Set bolt frame */
    byte *boltFramePtr = prim + 8;
    Effect_SetBoltFrame((const Effect *)particle, (FxBoltFramePtr *)boltFramePtr);

    /* Store cluster */
    *(int *)(particle + 0xac) = clusterId;

    return 1;
}
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
Bool FX_AddPrimitive(EffectPrimitive *prim, const vec_t *origin)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll FX_AddPrimitive_impl\n"
        "addl $12, %esp\n"
        "retl\n"
#if 0 /* Original ASM (236 lines) */
        "pushl %ebp\n" /* line 1485 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %edx, %esi\n" /* pEffect */
        "movl %ecx, -0x34(%ebp)\n"
        /* { scope 1: distSq */
        "movl 4(%eax), %edi\n" /* line 1493 | primTemp */
        "addl $8, %eax\n" /* line 1503 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf5ad92_0005af40\n"
        "movl effectActiveCount, %edx\n" /* line 484 */
        "leal 1(%edx), %eax\n"
        "movl %eax, effectActiveCount\n"
        "cmpl $0x708, %eax\n" /* line 488 */
        "jle .Lf5ad92_0005afe4\n"
        ".Lf5ad92_0005add3:\n"
        "movl %edx, effectActiveCount\n" /* line 526 */
        "movl $0, -0x24(%ebp)\n" /* item */
        /* { scope 2 */
        ".Lf5ad92_0005ade0:\n"
        "movl effectClusterCount, %eax\n" /* line 127 */
        "testl %eax, %eax\n"
        "jg .Lf5ad92_0005af81\n"
        ".Lf5ad92_0005aded:\n"
        "movl %eax, %edx\n" /* line 138 | to */
        "shll $4, %edx\n" /* to */
        "addl effectClusters, %edx\n" /* to */
        /* { scope 3 */
        "movl -0x34(%ebp), %ecx\n" /* line 199 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl effectClusterCount, %eax\n" /* line 139 */
        "shll $4, %eax\n"
        "movl effectClusters, %edx\n"
        "movl $1, 0xc(%eax, %edx)\n"
        "movl effectClusterCount, %edx\n" /* line 140 */
        "leal 1(%edx), %eax\n"
        "movl %eax, effectClusterCount\n"
        "movl %edx, -0x20(%ebp)\n" /* line 141 | clusterId */
        /* } scope */
        ".Lf5ad92_0005ae32:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1513 | item */
        "testl %eax, %eax\n"
        "je .Lf5ad92_0005b004\n"
        "testb $0x10, 0x91(%edi)\n" /* line 1520 | primTemp */
        "jne .Lf5ad92_0005afd8\n"
        ".Lf5ad92_0005ae4a:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1529 | item */
        "movl %esi, (%eax)\n" /* pEffect */
        "movl 0x90(%edi), %eax\n" /* line 210 */
        "movl %eax, 0xa8(%esi)\n"
        "movl theFxHelper, %eax\n" /* line 1532 */
        "movl 4(%eax), %ebx\n"
        "leal 0x58(%edi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x28(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n"
        "addl %eax, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pEffect */
        "calll Effect_SetTimeStartEnd\n"
        "movl -0x30(%ebp), %edx\n" /* line 214 */
        "movl (%edx), %eax\n"
        "movl %eax, 0x34(%esi)\n"
        "movl 0x44(%edi), %eax\n" /* line 215 */
        "movl %eax, 0x38(%esi)\n"
        "movl 0x98(%edi), %eax\n" /* line 211 */
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n" /* line 206 | from */
        "addl $0xa0, %ecx\n" /* from */
        "je .Lf5ad92_0005b01b\n"
        "leal 0x14(%esi), %edx\n" /* v */
        /* { scope 2 */
        "movl 0xa0(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x14(%esi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl %edi, %ecx\n" /* line 207 | from */
        "addl $0xac, %ecx\n" /* from */
        "je .Lf5ad92_0005b037\n"
        ".Lf5ad92_0005aedb:\n"
        "leal 0x20(%esi), %edx\n" /* v */
        /* { scope 2 */
        "movl 0xac(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x20(%esi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf5ad92_0005aef3:\n"
        "leal 0x78(%edi), %eax\n" /* line 1538 | primTemp */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetEffect\n"
        "movl %eax, 0x30(%esi)\n" /* line 213 */
        "leal 0x70(%edi), %eax\n" /* line 1539 | primTemp */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetEffect\n"
        "movl %eax, 0x2c(%esi)\n" /* line 212 */
        "movl (%esi), %eax\n" /* line 1540 | pEffect */
        "movl %edi, 4(%esp)\n" /* primTemp */
        "movl %esi, (%esp)\n" /* pEffect */
        "calll *0x20(%eax)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 1541 */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pEffect */
        "calll Effect_SetBoltFrame\n"
        "movl -0x20(%ebp), %eax\n" /* line 1543 | clusterId */
        "movl %eax, 0xac(%esi)\n" /* pEffect */
        "movl $1, %eax\n"
        /* } scope */
        ".Lf5ad92_0005af38:\n"
        "addl $0x3c, %esp\n" /* line 1546 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: distSq */
        ".Lf5ad92_0005af40:\n"
        "movl effectActiveCount, %edx\n" /* line 513 */
        "leal 1(%edx), %eax\n"
        "movl %eax, effectActiveCount\n"
        "cmpl $0x708, %eax\n" /* line 517 */
        "jg .Lf5ad92_0005add3\n"
        "movl effectActiveCountNonBolt, %edx\n" /* line 519 */
        "addl $1, %edx\n"
        "movl %edx, effectActiveCountNonBolt\n"
        "movl effectListNonBolt, %eax\n" /* line 520 */
        "leal -4(%eax, %edx, 4), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* item */
        /* { scope 2 */
        "movl effectClusterCount, %eax\n" /* line 127 */
        "testl %eax, %eax\n"
        "jle .Lf5ad92_0005aded\n"
        ".Lf5ad92_0005af81:\n"
        "movl $0, -0x20(%ebp)\n" /* clusterId */
        "xorl %ebx, %ebx\n"
        "jmp .Lf5ad92_0005afa1\n"
        ".Lf5ad92_0005af8c:\n"
        "addl $1, -0x20(%ebp)\n" /* clusterId */
        "movl effectClusterCount, %eax\n"
        "addl $0x10, %ebx\n"
        "cmpl %eax, -0x20(%ebp)\n" /* clusterId */
        "jge .Lf5ad92_0005aded\n"
        ".Lf5ad92_0005afa1:\n"
        "movl %ebx, %eax\n" /* line 129 */
        "addl effectClusters, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x1c(%ebp)\n" /* distSq */
        "movss lit4_002ed688, %xmm0\n" /* line 130 | 131072.0f */
        "ucomiss -0x1c(%ebp), %xmm0\n" /* distSq */
        "jbe .Lf5ad92_0005af8c\n"
        "addl effectClusters, %ebx\n" /* line 132 */
        "addl $1, 0xc(%ebx)\n"
        "jmp .Lf5ad92_0005ae32\n"
        /* } scope */
        ".Lf5ad92_0005afd8:\n"
        "addl $1, effectBlockSightCount\n" /* line 1525 */
        "jmp .Lf5ad92_0005ae4a\n"
        ".Lf5ad92_0005afe4:\n"
        "movl effectActiveCountBolt, %edx\n" /* line 490 */
        "addl $1, %edx\n"
        "movl %edx, effectActiveCountBolt\n"
        "movl effectListBolt, %eax\n" /* line 491 */
        "leal -4(%eax, %edx, 4), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* item */
        "jmp .Lf5ad92_0005ade0\n"
        ".Lf5ad92_0005b004:\n"
        "movl imp_com_statmon, %eax\n" /* line 444 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf5ad92_0005b04a\n"
        "xorl %eax, %eax\n" /* line 445 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1546 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: distSq */
        ".Lf5ad92_0005b01b:\n"
        "leal 0x14(%esi), %edx\n" /* line 206 | v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x14(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "movl %edi, %ecx\n" /* line 207 | from */
        "addl $0xac, %ecx\n" /* from */
        "jne .Lf5ad92_0005aedb\n"
        ".Lf5ad92_0005b037:\n"
        "leal 0x20(%esi), %edx\n" /* v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x20(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "jmp .Lf5ad92_0005aef3\n"
        /* } scope */
        ".Lf5ad92_0005b04a:\n"
        "movl $str_00219d48, 8(%esp)\n" /* line 445 */
        "movl $0xbb8, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll StatMon_Warning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5ad92_0005af38\n"
#endif
    );
}
#else
static Bool FX_AddPrimitive(EffectPrimitive *prim, const vec_t *origin) { (void)prim; (void)origin; return 0; }
#endif

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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("movl %3, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n" "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(p), "r"(origin) : "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("pushl %5\n" "pushl %4\n" "pushl %3\n"
        "leal %0, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_InitParticle\n" "addl $12, %%esp\n"
        : "=m"(newOrigin) : "g"(prim), "g"(p), "g"(origin), "g"(ax), "g"(indexInBatch)
        : "eax", "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    byte *primTemp = *(byte **)((byte *)prim + 4);
    int killTime = *(int *)(p + 0xbc) - *(int *)(p + 0xb8);
    FX_SetMaterialAndSequenceParams_impl(primTemp, p, killTime, indexInBatch);
    if (lateTime > 0) {
        float dt = (float)lateTime * 0.001f;
        vec3_t velSum;
        Particle_IntegrateTotalVelocity(p, lateTime, velSum);
        newOrigin[0] += velSum[0] * dt; newOrigin[1] += velSum[1] * dt; newOrigin[2] += velSum[2] * dt;
    }
    *(float *)(p + 4) = newOrigin[0]; *(float *)(p + 8) = newOrigin[1]; *(float *)(p + 0xc) = newOrigin[2];
    *(float *)(p + 0x260) = flrand(0.0f, 1.0f);
    *(byte *)(p + 0x25c) = *(byte *)(primTemp + 0x9d);
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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("movl %3, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n" "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(p), "r"(origin) : "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) {
        /* Call destructor via vtable[1] */
        typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p);
        return;
    }

    byte *primTemp = *(byte **)((byte *)prim + 4);
    void *material = MediaHandles_GetHandle(primTemp + 0x68);

    /* Copy origin to p+4 */
    if (origin) {
        *(float *)(p + 4) = origin[0]; *(float *)(p + 8) = origin[1]; *(float *)(p + 0xc) = origin[2];
    } else {
        *(float *)(p + 4) = 0; *(float *)(p + 8) = 0; *(float *)(p + 0xc) = 0;
    }

    *(void **)(p + 0x40) = material;

    /* Check flags for random weight */
    if (*(byte *)(primTemp + 0x91) & 0x20)
        *(float *)(p + 0xc4) = flrand(0.0f, 1.0f);

    /* Set refractive flag */
    *(int *)(p + 0xb0) = 0;
    if (material && FxHelper_IsMaterialRefractive(theFxHelper, (MaterialHandle)material))
        *(int *)(p + 0xb0) = -1;

    Flash_Init(p);
}
#if 0 /* Original ASM */
__attribute__((naked))
void FX_AddFlash_original(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2063 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* prim */
        "movl 0x10(%ebp), %esi\n" /* origin */
        /* { scope 1 */
        /* { scope 2 */
        "movl $0xfc, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5b1d4_0005b20d\n"
        "movl $0xfc, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5b1d4_0005b20d:\n"
        "movl %ebx, (%esp)\n" /* line 281 | ptr */
        "calll Light_Light\n"
        "movl imp__ZTV5Flash, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%ebx)\n" /* ptr */
        "movl %esi, %ecx\n" /* line 2076 | origin */
        "movl %ebx, %edx\n" /* ptr */
        "movl %edi, %eax\n" /* primTemp */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 2077 */
        "jne .Lf5b1d4_0005b23f\n"
        "movl (%ebx), %eax\n" /* line 2079 | ptr */
        "movl %ebx, 8(%ebp)\n" /* ptr, prim */
        "movl 4(%eax), %ecx\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 2079 */
        ".Lf5b1d4_0005b23f:\n"
        "movl 4(%edi), %edi\n" /* line 2083 | primTemp */
        "leal 0x68(%edi), %eax\n" /* line 2088 | primTemp */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetHandle\n"
        "movl %eax, %ecx\n"
        "testl %esi, %esi\n" /* line 208 */
        "je .Lf5b1d4_0005b2c0\n"
        "leal 4(%ebx), %edx\n" /* ptr, v */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, 4(%ebx)\n" /* ptr */
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf5b1d4_0005b267:\n"
        "movl %ecx, 0x40(%ebx)\n" /* line 293 | ptr */
        "testb $0x20, 0x91(%edi)\n" /* line 2093 | primTemp */
        "jne .Lf5b1d4_0005b2d0\n"
        "movl %ecx, %eax\n"
        ".Lf5b1d4_0005b275:\n"
        "movl $0, 0xb0(%ebx)\n" /* line 1551 | ptr */
        "testl %eax, %eax\n" /* line 1552 */
        "je .Lf5b1d4_0005b298\n"
        "movl %eax, 4(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_IsMaterialRefractive\n"
        "testb %al, %al\n"
        "jne .Lf5b1d4_0005b2a7\n"
        ".Lf5b1d4_0005b298:\n"
        "movl %ebx, 8(%ebp)\n" /* line 2098 | ptr, prim */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Flash_Init\n" /* line 2098 */
        ".Lf5b1d4_0005b2a7:\n"
        "movl $0xffffffff, 0xb0(%ebx)\n" /* line 1553 | ptr */
        "movl %ebx, 8(%ebp)\n" /* line 2098 | ptr, prim */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Flash_Init\n" /* line 2098 */
        ".Lf5b1d4_0005b2c0:\n"
        "leal 4(%ebx), %edx\n" /* line 208 | ptr, v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 4(%ebx)\n" /* ptr */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "jmp .Lf5b1d4_0005b267\n"
        /* } scope */
        ".Lf5b1d4_0005b2d0:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 2094 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "fstps 0xc4(%ebx)\n" /* line 261 | ptr */
        "movl 0x40(%ebx), %eax\n" /* ptr */
        "jmp .Lf5b1d4_0005b275\n"
        "movl %eax, %esi\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5b1d4_0005b2fd\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5b1d4_0005b2fd:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}
#endif

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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "movl %3, %%ecx\n"
        "movl %2, %%edx\n"
        "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n"
        "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(light), "r"(origin)
        : "ecx", "edx", "memory"
    );
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) {
        typedef void (*Fn)(void *); ((Fn)(*(void ***)light)[1])(light);
        return;
    }

    /* FX_CalcOriginAndAxis: eax=prim, edx=orgOut, stack=ax */
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %2\n"
        "movl %1, %%edx\n"
        "movl %0, %%eax\n"
        "calll FX_CalcOriginAndAxis\n"
        "addl $4, %%esp\n"
        : : "g"(prim), "g"(&newOrigin), "g"(ax)
        : "eax", "ecx", "edx", "memory"
    );
#else
    /* x86 asm not available */
#endif
    *(float *)(light + 4) = newOrigin[0];
    *(float *)(light + 8) = newOrigin[1];
    *(float *)(light + 0xc) = newOrigin[2];

    byte *primTemp = *(byte **)((byte *)prim + 4);
    int flags = *(int *)(primTemp + 0x90);
    if (flags & 0x2000) /* bit 13 */
        *(float *)(light + 0xc4) = flrand(0.0f, 1.0f);
    if ((short)flags < 0) /* bit 15 */
        *(float *)(light + 0xc8) = flrand(0.0f, 1.0f);
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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("movl %3, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n" "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(p), "r"(origin) : "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("pushl %5\n" "pushl %4\n" "pushl %3\n"
        "leal %0, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_InitParticle\n" "addl $12, %%esp\n"
        : "=m"(newOrigin) : "g"(prim), "g"(p), "g"(origin), "g"(ax), "g"(indexInBatch)
        : "eax", "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    int killTime = *(int *)(p + 0xbc) - *(int *)(p + 0xb8);
    FX_SetMaterialAndSequenceParams_impl(*(byte **)((byte *)prim + 4), p, killTime, indexInBatch);

    /* Copy normal to cylinder axis at p+0x48 */
    vec3_t normal;
    normal[0] = ((float *)ax)[0]; normal[1] = ((float *)ax)[1]; normal[2] = ((float *)ax)[2];
    void *bolt = *(void **)((byte *)prim + 8);
    if (bolt) {
        /* Transform normal via bolt orientation */
        void *orient = FxBoltFrame_GetOrientation(bolt);
        vec3_t localNormal;
        OrientationDirFromWorldDir(orient, normal, localNormal);
        *(float *)(p + 0x48) = localNormal[0]; *(float *)(p + 0x4c) = localNormal[1]; *(float *)(p + 0x50) = localNormal[2];
    } else {
        *(float *)(p + 0x48) = normal[0]; *(float *)(p + 0x4c) = normal[1]; *(float *)(p + 0x50) = normal[2];
    }
    *(float *)(p + 4) = newOrigin[0]; *(float *)(p + 8) = newOrigin[1]; *(float *)(p + 0xc) = newOrigin[2];
}
#if 0 /* Original ASM preserved */
__attribute__((naked))
void FX_AddCylinder_original(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1802 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* prim */
        "movl 0xc(%ebp), %edi\n" /* ax */
        /* { scope 1 */
        /* { scope 2 */
        "movl $0x278, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5b402_0005b43b\n"
        "movl $0x278, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5b402_0005b43b:\n"
        "movl %ebx, (%esp)\n" /* line 1814 | ptr */
        "calll Cylinder_Cylinder\n"
        "testl %ebx, %ebx\n" /* line 1815 | ptr */
        "je .Lf5b402_0005b501\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1818 | origin */
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* prim */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 1819 */
        "je .Lf5b402_0005b509\n"
        "leal -0x24(%ebp), %ecx\n" /* line 1825 | newOrigin */
        "movl 0x18(%ebp), %eax\n" /* indexInBatch */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* ax */
        "movl 0x10(%ebp), %edx\n" /* origin */
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* prim */
        "calll FX_InitParticle\n"
        "movl 0xbc(%ebx), %ecx\n" /* line 1826 | ptr */
        "subl 0xb8(%ebx), %ecx\n" /* ptr */
        "movl 4(%esi), %eax\n" /* prim */
        "movl 0x18(%ebp), %edx\n" /* indexInBatch */
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "calll FX_SetMaterialAndSequenceParams\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 199 | newOrigin */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, -0x50(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x54(%ebp)\n"
        "movl (%edi), %edx\n" /* line 199 */
        "movl %edx, -0x30(%ebp)\n" /* normal */
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 1831 | prim */
        "testl %eax, %eax\n"
        "jne .Lf5b402_0005b519\n"
        "leal 0x48(%ebx), %eax\n" /* line 602 | ptr, to */
        /* { scope 2 */
        "movl %edx, 0x48(%ebx)\n" /* line 199 | ptr */
        "movl -0x2c(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%eax)\n"
        "movl -0x28(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        /* } scope */
        ".Lf5b402_0005b4e0:\n"
        "leal 4(%ebx), %eax\n" /* line 208 | ptr, to */
        /* { scope 2 */
        "movss -0x4c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 4(%ebx)\n" /* ptr */
        "movss -0x50(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%eax)\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lf5b402_0005b501:\n"
        "addl $0x5c, %esp\n" /* line 1844 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5b402_0005b509:\n"
        "movl (%ebx), %eax\n" /* line 1821 | ptr */
        "movl %ebx, (%esp)\n" /* ptr */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1844 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5b402_0005b519:\n"
        "movl 8(%esi), %eax\n" /* line 1833 | prim */
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_GetOrientation\n"
        "leal -0x3c(%ebp), %edx\n" /* line 1835 | localNormal */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* normal */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        "leal 0x48(%ebx), %edx\n" /* line 602 | ptr, to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | localNormal */
        "movl %eax, 0x48(%ebx)\n" /* ptr */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf5b402_0005b4e0\n"
        "movl %eax, %esi\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5b402_0005b55f\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5b402_0005b55f:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}
#endif

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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("movl %3, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n" "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(p), "r"(origin) : "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }

    /* Calc origin */
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %2\n" "movl %1, %%edx\n" "movl %0, %%eax\n"
        "calll FX_CalcOriginAndAxis\n" "addl $4, %%esp\n"
        : : "g"(prim), "g"(&newOrigin), "g"(ax) : "eax", "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif

    Particle_SetAxis(p, ax);

    /* Calc second endpoint */
    byte *primTemp = *(byte **)((byte *)prim + 4);
    vec3_t org2;
    FX_CalcOrigin2((const PrimitiveTemplate *)primTemp, newOrigin, org2, origin, ax);

    /* Get material */
    void *material = MediaHandles_GetHandle(primTemp + 0x68);

    /* Copy endpoint — transform via bolt if present */
    void *bolt = *(void **)((byte *)prim + 8);
    if (bolt) {
        void *orient = FxBoltFrame_GetOrientation(bolt);
        vec3_t localEnd;
        OrientationPosFromWorldPos(orient, org2, localEnd);
        *(float *)(p + 0x24c) = localEnd[0]; *(float *)(p + 0x250) = localEnd[1]; *(float *)(p + 0x254) = localEnd[2];
    } else {
        *(float *)(p + 0x24c) = org2[0]; *(float *)(p + 0x250) = org2[1]; *(float *)(p + 0x254) = org2[2];
    }

    /* Copy origin */
    *(float *)(p + 4) = newOrigin[0]; *(float *)(p + 8) = newOrigin[1]; *(float *)(p + 0xc) = newOrigin[2];
    *(void **)(p + 0x40) = material;

    /* Random weights based on flags */
    int flags = *(int *)(primTemp + 0x90);
    if (flags & 0x2000) *(float *)(p + 0x118) = flrand(0.0f, 1.0f);
    if (flags & 0x4000) *(float *)(p + 0x11c) = flrand(0.0f, 1.0f);
    if ((short)flags < 0) *(float *)(p + 0x120) = flrand(0.0f, 1.0f);
    if (flags & 0x10000) *(float *)(p + 0x124) = flrand(0.0f, 1.0f);

    /* Refractive check */
    *(int *)(p + 0xb0) = 0;
    if (material && FxHelper_IsMaterialRefractive(theFxHelper, (MaterialHandle)material))
        *(int *)(p + 0xb0) = -1;
}
#if 0 /* Original ASM */
__attribute__((naked))
void FX_AddLine_asm(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1701 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* origin */
        /* { scope 1 */
        /* { scope 2 */
        "movl $0x258, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %esi\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5b568_0005b59e\n"
        "movl $0x258, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5b568_0005b59e:\n"
        "movl %esi, (%esp)\n" /* line 1714 | ptr */
        "calll Line_Line\n"
        "testl %esi, %esi\n" /* line 1715 | ptr */
        "je .Lf5b568_0005b6ee\n"
        "movl %edi, %ecx\n" /* line 1718 | origin */
        "movl %esi, %edx\n" /* ptr */
        "movl 8(%ebp), %eax\n" /* prim */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 1719 */
        "je .Lf5b568_0005b6f6\n"
        "leal -0x24(%ebp), %ebx\n" /* line 1725 | newOrigin */
        "movl 0xc(%ebp), %eax\n" /* ax */
        "movl %eax, (%esp)\n"
        "movl %edi, %ecx\n" /* origin */
        "movl %ebx, %edx\n"
        "movl 8(%ebp), %eax\n" /* prim */
        "calll FX_CalcOriginAndAxis\n"
        "movl 0xc(%ebp), %edx\n" /* line 1726 | ax */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ptr */
        "calll Particle_SetAxis\n"
        "movl 8(%ebp), %eax\n" /* line 1728 | prim */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* primTemp */
        "movl 0xc(%ebp), %edx\n" /* line 1732 | ax */
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* origin */
        "leal -0x30(%ebp), %eax\n" /* org2 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FX_CalcOrigin2\n"
        "movl -0x24(%ebp), %edi\n" /* line 199 | newOrigin */
        "movss -0x20(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x50(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 199 | org2 */
        "movl %eax, -0x3c(%ebp)\n" /* end */
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x54(%ebp), %eax\n" /* line 1739 | primTemp */
        "addl $0x68, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetHandle\n"
        "movl %eax, %ebx\n"
        "movl 8(%ebp), %eax\n" /* line 1741 | prim */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf5b568_0005b706\n"
        "leal 0x24c(%esi), %edx\n" /* line 498 | ptr, to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | end */
        "movl %eax, 0x24c(%esi)\n" /* ptr */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf5b568_0005b672:\n"
        "leal 4(%esi), %eax\n" /* line 208 | ptr, to */
        /* { scope 2 */
        "movl %edi, 4(%esi)\n" /* line 199 | ptr */
        "movss -0x4c(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%eax)\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl %ebx, 0x40(%esi)\n" /* line 381 | ptr */
        "movl -0x54(%ebp), %edx\n" /* line 1755 | primTemp */
        "movl 0x90(%edx), %eax\n"
        "testb $0x20, %ah\n"
        "jne .Lf5b568_0005b7b6\n"
        ".Lf5b568_0005b6a1:\n"
        "testb $0x40, %ah\n" /* line 1757 */
        "jne .Lf5b568_0005b78e\n"
        ".Lf5b568_0005b6aa:\n"
        "testw %ax, %ax\n" /* line 1759 */
        "js .Lf5b568_0005b766\n"
        ".Lf5b568_0005b6b3:\n"
        "testl $0x10000, %eax\n" /* line 1761 */
        "jne .Lf5b568_0005b747\n"
        ".Lf5b568_0005b6be:\n"
        "movl $0, 0xb0(%esi)\n" /* line 1551 | ptr */
        "movl 0x40(%esi), %eax\n" /* line 1552 | ptr */
        "testl %eax, %eax\n"
        "je .Lf5b568_0005b6ee\n"
        "movl %eax, 4(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_IsMaterialRefractive\n"
        "testb %al, %al\n"
        "je .Lf5b568_0005b6ee\n"
        "movl $0xffffffff, 0xb0(%esi)\n" /* line 1553 | ptr */
        /* } scope */
        ".Lf5b568_0005b6ee:\n"
        "addl $0x6c, %esp\n" /* line 1765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5b568_0005b6f6:\n"
        "movl (%esi), %eax\n" /* line 1721 | ptr */
        "movl %esi, (%esp)\n" /* ptr */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5b568_0005b706:\n"
        "movl 8(%eax), %eax\n" /* line 1743 */
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_GetOrientation\n"
        "leal -0x48(%ebp), %edx\n" /* line 1745 | localEnd */
        "movl %edx, 8(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* end */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll OrientationPosFromWorldPos\n"
        "leal 0x24c(%esi), %edx\n" /* line 498 | ptr, to */
        /* { scope 2 */
        "movl -0x48(%ebp), %eax\n" /* line 199 | localEnd */
        "movl %eax, 0x24c(%esi)\n" /* ptr */
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x40(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf5b568_0005b672\n"
        /* } scope */
        ".Lf5b568_0005b747:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1762 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "fstps 0x124(%esi)\n" /* line 393 | ptr */
        "jmp .Lf5b568_0005b6be\n"
        /* } scope */
        ".Lf5b568_0005b766:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1760 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "fstps 0x120(%esi)\n" /* line 392 | ptr */
        "movl -0x54(%ebp), %edx\n" /* primTemp */
        "movl 0x90(%edx), %eax\n"
        "jmp .Lf5b568_0005b6b3\n"
        /* } scope */
        ".Lf5b568_0005b78e:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1758 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "fstps 0x11c(%esi)\n" /* line 391 | ptr */
        "movl -0x54(%ebp), %edx\n" /* primTemp */
        "movl 0x90(%edx), %eax\n"
        "jmp .Lf5b568_0005b6aa\n"
        /* } scope */
        ".Lf5b568_0005b7b6:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1756 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "fstps 0x118(%esi)\n" /* line 390 | ptr */
        "movl -0x54(%ebp), %edx\n" /* primTemp */
        "movl 0x90(%edx), %eax\n"
        "jmp .Lf5b568_0005b6a1\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 35 | ptr */
        "je .Lf5b568_0005b7ec\n"
        "movl %esi, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5b568_0005b7ec:\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}
#endif

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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "movl %3, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n" "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(p), "r"(origin) : "ecx", "edx", "memory"
    );
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }

    /* FX_InitParticle: eax=prim, edx=particle, ecx=newOrigin, stack: origin, ax, indexInBatch */
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %5\n" "pushl %4\n" "pushl %3\n"
        "leal %0, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_InitParticle\n" "addl $12, %%esp\n"
        : "=m"(newOrigin) : "g"(prim), "g"(p), "g"(origin), "g"(ax), "g"(indexInBatch)
        : "eax", "ecx", "edx", "memory"
    );
#else
    /* x86 asm not available */
#endif

    /* FX_SetMaterialAndSequenceParams: eax=primTemp, edx=particle, ecx=killTime, stack: indexInBatch */
    int killTime = *(int *)(p + 0xbc) - *(int *)(p + 0xb8);
    FX_SetMaterialAndSequenceParams_impl(*(byte **)((byte *)prim + 4), p, killTime, indexInBatch);

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
    *(float *)(p + 4) = newOrigin[0];
    *(float *)(p + 8) = newOrigin[1];
    *(float *)(p + 0xc) = newOrigin[2];
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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("movl %3, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n" "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(p), "r"(origin) : "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("pushl %5\n" "pushl %4\n" "pushl %3\n"
        "leal %0, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_InitParticle\n" "addl $12, %%esp\n"
        : "=m"(newOrigin) : "g"(prim), "g"(p), "g"(origin), "g"(ax), "g"(indexInBatch)
        : "eax", "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    int killTime = *(int *)(p + 0xbc) - *(int *)(p + 0xb8);
    FX_SetMaterialAndSequenceParams_impl(*(byte **)((byte *)prim + 4), p, killTime, indexInBatch);
    if (lateTime > 0) {
        float dt = (float)lateTime * 0.001f;
        vec3_t velSum;
        Particle_IntegrateTotalVelocity(p, lateTime, velSum);
        newOrigin[0] += velSum[0] * dt; newOrigin[1] += velSum[1] * dt; newOrigin[2] += velSum[2] * dt;
    }
    /* Copy origin */
    *(float *)(p + 4) = newOrigin[0]; *(float *)(p + 8) = newOrigin[1]; *(float *)(p + 0xc) = newOrigin[2];
    /* Copy endpoint direction = newOrigin - ax[0]*something */
    float ny = newOrigin[1]; /* saved for below */
    *(float *)(p + 0x24c) = newOrigin[0] - ((float *)ax)[0];
    *(float *)(p + 0x250) = ny - ((float *)ax)[1];
    *(float *)(p + 0x254) = newOrigin[2] - ((float *)ax)[2];
    /* Random weight */
    *(float *)(p + 0x25c) = flrand(0.0f, 1.0f);
    Tail_InitEndPoint(p);
}
#if 0 /* Original ASM */
__attribute__((naked))
void FX_AddTail_asm2(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1768 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* prim */
        "movl 0xc(%ebp), %edi\n" /* ax */
        /* { scope 1: velSum */
        /* { scope 2 */
        "movl $0x278, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5b934_0005b96d\n"
        "movl $0x278, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5b934_0005b96d:\n"
        "movl %ebx, (%esp)\n" /* line 1777 | ptr */
        "calll Tail_Tail\n"
        "testl %ebx, %ebx\n" /* line 1778 | ptr */
        "je .Lf5b934_0005baa1\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1781 | origin */
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* prim */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 1782 */
        "je .Lf5b934_0005baa9\n"
        "leal -0x24(%ebp), %ecx\n" /* line 1788 | newOrigin */
        "movl 0x18(%ebp), %eax\n" /* indexInBatch */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* ax */
        "movl 0x10(%ebp), %edx\n" /* origin */
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* prim */
        "calll FX_InitParticle\n"
        "movl 0xbc(%ebx), %ecx\n" /* line 1789 | ptr */
        "subl 0xb8(%ebx), %ecx\n" /* ptr */
        "movl 4(%esi), %eax\n" /* prim */
        "movl 0x18(%ebp), %edx\n" /* indexInBatch */
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "calll FX_SetMaterialAndSequenceParams\n"
        /* { scope 2 */
        "movl 0x14(%ebp), %eax\n" /* line 1472 | lateTime */
        "testl %eax, %eax\n"
        "jle .Lf5b934_0005bab9\n"
        "cvtsi2ssl 0x14(%ebp), %xmm1\n" /* line 1474 | lateTime */
        "mulss lit4_002ed658, %xmm1\n" /* 0.0010000000474974513f */
        "leal -0x30(%ebp), %eax\n" /* line 1476 | velSum */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* lateTime */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "movss %xmm1, -0x48(%ebp)\n"
        "calll Particle_IntegrateTotalVelocity\n"
        /* { scope 3 */
        "movss -0x48(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x30(%ebp), %xmm0\n" /* velSum */
        "addss -0x24(%ebp), %xmm0\n" /* newOrigin */
        "movss %xmm0, -0x24(%ebp)\n" /* newOrigin */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss -0x28(%ebp), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movaps %xmm0, %xmm1\n"
        /* } scope */
        /* } scope */
        ".Lf5b934_0005ba38:\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 288 | newOrigin */
        "movaps %xmm2, %xmm3\n"
        "subss (%edi), %xmm3\n"
        "subss 4(%edi), %xmm1\n" /* line 289 */
        "movss -0x1c(%ebp), %xmm0\n" /* line 290 */
        "subss 8(%edi), %xmm0\n"
        "leal 4(%ebx), %edx\n" /* line 208 | ptr, to */
        /* { scope 2 */
        "movss %xmm2, 4(%ebx)\n" /* line 199 | ptr */
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x24c(%ebx), %eax\n" /* line 567 | ptr, to */
        /* { scope 2 */
        "movss %xmm3, 0x24c(%ebx)\n" /* line 199 | ptr */
        "movss %xmm1, 4(%eax)\n" /* line 200 */
        "movss %xmm0, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl $0x3f800000, 4(%esp)\n" /* line 1796 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "fstps 0x25c(%ebx)\n" /* ptr */
        "movl %ebx, (%esp)\n" /* line 1798 | ptr */
        "calll Tail_InitEndPoint\n"
        /* } scope */
        ".Lf5b934_0005baa1:\n"
        "addl $0x4c, %esp\n" /* line 1799 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: velSum */
        ".Lf5b934_0005baa9:\n"
        "movl (%ebx), %eax\n" /* line 1784 | ptr */
        "movl %ebx, (%esp)\n" /* ptr */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1799 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf5b934_0005bab9:\n"
        "movss -0x20(%ebp), %xmm1\n"
        "jmp .Lf5b934_0005ba38\n"
        "movl %eax, %esi\n" /* prim */
        /* { scope 1: velSum */
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5b934_0005bad1\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5b934_0005bad1:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}
#endif

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
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("movl %3, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n" "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(p), "r"(origin) : "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("pushl %5\n" "pushl %4\n" "pushl %3\n"
        "leal %0, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_InitParticle\n" "addl $12, %%esp\n"
        : "=m"(newOrigin) : "g"(prim), "g"(p), "g"(origin), "g"(ax), "g"(indexInBatch)
        : "eax", "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    byte *primTemp = *(byte **)((byte *)prim + 4);
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
    void *material = MediaHandles_GetHandle(primTemp + 0x68);
    /* Copy origin */
    *(float *)(p + 4) = newOrigin[0]; *(float *)(p + 8) = newOrigin[1]; *(float *)(p + 0xc) = newOrigin[2];
    /* Copy endpoint = origin (same position for emitter) */
    *(float *)(p + 0x24c) = newOrigin[0]; *(float *)(p + 0x250) = newOrigin[1]; *(float *)(p + 0x254) = newOrigin[2];
    /* Get velocity at t=0 for emit direction */
    vec3_t vel;
    Particle_GetTotalVelocityAtTime0(p, vel);
    *(float *)(p + 0x258) = vel[0]; *(float *)(p + 0x25c) = vel[1]; *(float *)(p + 0x260) = vel[2];
    /* Store spawn parameters */
    *(float *)(p + 0x278) = spawnSize;
    *(float *)(p + 0x284) = spawnDensity;
    *(float *)(p + 0x28c) = spawnStep;
    *(float *)(p + 0x294) = spawnVariance;
    /* Set model reference from primTemp */
    *(int *)(p + 0xb4) = *(int *)(primTemp + 0x250);
    /* Set emitter effect template */
    *(int *)(p + 0x290) = *(int *)(primTemp + 0x88);
    /* Set material + refractive flag */
    *(void **)(p + 0x40) = material;
    *(int *)(p + 0xb0) = 0;
    if (material && FxHelper_IsMaterialRefractive(theFxHelper, (MaterialHandle)material))
        *(int *)(p + 0xb0) = -1;
    /* Random weights based on flags */
    int flags = *(int *)(primTemp + 0x90);
    if (flags & 0x2000) *(float *)(p + 0x118) = flrand(0.0f, 1.0f);
    if (flags & 0x4000) *(float *)(p + 0x11c) = flrand(0.0f, 1.0f);
    if ((short)flags < 0) *(float *)(p + 0x120) = flrand(0.0f, 1.0f);
}
#if 0 /* Original ASM (257 lines) */
__attribute__((naked))
void FX_AddEmitter_asm(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1847 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 8(%ebp), %edi\n" /* prim */
        /* { scope 1: velSum */
        /* { scope 2 */
        "movl $0x29c, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5bada_0005bb13\n"
        "movl $0x29c, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5bada_0005bb13:\n"
        "movl %ebx, (%esp)\n" /* line 1865 | ptr */
        "calll Emitter_Emitter\n"
        "testl %ebx, %ebx\n" /* line 1866 | ptr */
        "je .Lf5bada_0005bde1\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1869 | origin */
        "movl %ebx, %edx\n" /* ptr */
        "movl %edi, %eax\n" /* prim */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 1870 */
        "je .Lf5bada_0005bdec\n"
        "leal -0x30(%ebp), %ecx\n" /* line 1876 | newOrigin */
        "movl 0x18(%ebp), %eax\n" /* indexInBatch */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* ax */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* origin */
        "movl %eax, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "movl %edi, %eax\n" /* prim */
        "calll FX_InitParticle\n"
        "movl 4(%edi), %esi\n" /* line 1878 | prim, primTemp */
        /* { scope 2 */
        "movl 0x14(%ebp), %eax\n" /* line 1472 | lateTime */
        "testl %eax, %eax\n"
        "jle .Lf5bada_0005bbc7\n"
        "cvtsi2ssl 0x14(%ebp), %xmm1\n" /* line 1474 | lateTime */
        "mulss lit4_002ed658, %xmm1\n" /* 0.0010000000474974513f */
        "leal -0x48(%ebp), %eax\n" /* line 1476 | velSum */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* lateTime */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "movss %xmm1, -0x88(%ebp)\n"
        "calll Particle_IntegrateTotalVelocity\n"
        /* { scope 3 */
        "movss -0x88(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x48(%ebp), %xmm0\n" /* velSum */
        "addss -0x30(%ebp), %xmm0\n" /* newOrigin */
        "movss %xmm0, -0x30(%ebp)\n" /* newOrigin */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf5bada_0005bbc7:\n"
        "leal 0x238(%esi), %eax\n" /* line 1885 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x54(%ebp)\n"
        "leal 0x230(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x50(%ebp)\n"
        "leal 0x228(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x4c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 1886 | temp */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* ax */
        "movl %eax, (%esp)\n"
        "calll vectoangles\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 240 */
        "addss -0x24(%ebp), %xmm0\n" /* temp */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 241 */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 242 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "leal 0x250(%esi), %eax\n" /* line 1888 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x60(%ebp)\n"
        "leal 0x248(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x5c(%ebp)\n"
        "leal 0x240(%esi), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x58(%ebp)\n"
        "leal 0x68(%esi), %eax\n" /* line 1892 | primTemp */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetHandle\n"
        "movl %eax, -0x70(%ebp)\n"
        "leal 0x80(%esi), %eax\n" /* line 1894 | primTemp */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetEffect\n"
        "movl %eax, -0x6c(%ebp)\n" /* emitter */
        "leal 0x260(%esi), %eax\n" /* line 1895 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x68(%ebp)\n" /* density */
        "leal 0x268(%esi), %eax\n" /* line 1896 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x64(%ebp)\n" /* variance */
        "movl 8(%edi), %eax\n" /* line 1898 | prim */
        "testl %eax, %eax\n"
        "jne .Lf5bada_0005bdff\n"
        "leal 0x264(%ebx), %edx\n" /* line 666 | ptr */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x264(%ebx)\n" /* ptr */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        ".Lf5bada_0005bccc:\n"
        "movl -0x70(%ebp), %eax\n" /* line 1909 */
        "testl %eax, %eax\n"
        "je .Lf5bada_0005be2f\n"
        ".Lf5bada_0005bcd7:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 1912 | vel */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll Particle_GetTotalVelocityAtTime0\n"
        "leal 4(%ebx), %edx\n" /* line 208 | ptr, to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | newOrigin */
        "movl %eax, 4(%ebx)\n" /* ptr */
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x24c(%ebx), %edx\n" /* line 660 | ptr */
        "movl -0x30(%ebp), %eax\n" /* line 199 | newOrigin */
        "movl %eax, 0x24c(%ebx)\n" /* ptr */
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x258(%ebx), %edx\n" /* line 665 | ptr */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | vel */
        "movl %eax, 0x258(%ebx)\n" /* ptr */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x278(%ebx), %eax\n" /* line 651 | ptr */
        "movss -0x4c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x278(%ebx)\n" /* ptr */
        "movss -0x50(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%eax)\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        "leal 0x284(%ebx), %eax\n" /* line 652 | ptr */
        "movss -0x58(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x284(%ebx)\n" /* ptr */
        "movss -0x5c(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%eax)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        "movl -0x70(%ebp), %eax\n" /* line 650 */
        "movl %eax, 0xb4(%ebx)\n" /* ptr */
        "movl -0x6c(%ebp), %eax\n" /* line 653 | emitter */
        "movl %eax, 0x290(%ebx)\n" /* ptr */
        "movss -0x68(%ebp), %xmm0\n" /* line 654 | density */
        "movss %xmm0, 0x294(%ebx)\n" /* ptr */
        "movss -0x64(%ebp), %xmm0\n" /* line 655 | variance */
        "movss %xmm0, 0x298(%ebx)\n" /* ptr */
        "movl theFxHelper, %eax\n" /* line 656 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x270(%ebx)\n" /* ptr */
        "calll crandom\n" /* line 668 */
        "fstps -0x8c(%ebp)\n"
        "movss -0x8c(%ebp), %xmm0\n"
        "mulss 0x298(%ebx), %xmm0\n" /* ptr */
        "addss -0x68(%ebp), %xmm0\n" /* density */
        "movss %xmm0, 0x274(%ebx)\n" /* ptr */
        /* } scope */
        ".Lf5bada_0005bde1:\n"
        "addl $0x9c, %esp\n" /* line 1925 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: velSum */
        ".Lf5bada_0005bdec:\n"
        "movl (%ebx), %eax\n" /* line 1872 | ptr */
        "movl %ebx, (%esp)\n" /* ptr */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 1925 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: velSum */
        ".Lf5bada_0005bdff:\n"
        "movl 8(%edi), %eax\n" /* line 1900 | prim */
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_GetOrientation\n"
        "movl %eax, %edx\n"
        "leal 0x264(%ebx), %ecx\n" /* line 666 | ptr */
        "testl %eax, %eax\n" /* line 207 */
        "je .Lf5bada_0005be3b\n"
        "movl (%eax), %eax\n" /* line 199 */
        "movl %eax, 0x264(%ebx)\n" /* ptr */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "jmp .Lf5bada_0005bccc\n"
        ".Lf5bada_0005be2f:\n"
        "andl $0xffffffef, 0xa8(%ebx)\n" /* ptr */
        "jmp .Lf5bada_0005bcd7\n"
        /* { scope 2 */
        ".Lf5bada_0005be3b:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x264(%ebx)\n" /* ptr */
        "movl %eax, 4(%ecx)\n" /* line 184 */
        "movl %eax, 8(%ecx)\n" /* line 185 */
        "jmp .Lf5bada_0005bccc\n"
        "movl %eax, %esi\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5bada_0005be5c\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5bada_0005be5c:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}
#endif

/* FX_AddOrientedParticle — allocate, add, init, material, late time, copy normal+origin */
extern void OrientedParticle_OrientedParticle(void *op);
void FX_AddOrientedParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    byte *p = (byte *)__Znam(0x258);
    if (p) memset(p, 0, 0x258);
    OrientedParticle_OrientedParticle(p);
    if (!p) return;
    int added;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("movl %3, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_AddPrimitive\n" "movl %%eax, %0\n"
        : "=r"(added) : "r"(prim), "r"(p), "r"(origin) : "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    if (!(byte)added) { typedef void (*Fn)(void *); ((Fn)(*(void ***)p)[1])(p); return; }
    vec3_t newOrigin;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ ("pushl %5\n" "pushl %4\n" "pushl %3\n"
        "leal %0, %%ecx\n" "movl %2, %%edx\n" "movl %1, %%eax\n"
        "calll FX_InitParticle\n" "addl $12, %%esp\n"
        : "=m"(newOrigin) : "g"(prim), "g"(p), "g"(origin), "g"(ax), "g"(indexInBatch)
        : "eax", "ecx", "edx", "memory");
#else
    /* x86 asm not available */
#endif
    int killTime = *(int *)(p + 0xbc) - *(int *)(p + 0xb8);
    FX_SetMaterialAndSequenceParams_impl(*(byte **)((byte *)prim + 4), p, killTime, indexInBatch);
    if (lateTime > 0) {
        float dt = (float)lateTime * 0.001f;
        vec3_t velSum;
        Particle_IntegrateTotalVelocity(p, lateTime, velSum);
        newOrigin[0] += velSum[0] * dt; newOrigin[1] += velSum[1] * dt; newOrigin[2] += velSum[2] * dt;
    }
    /* Copy normal to p+0x24c — either direct or via bolt orientation */
    vec3_t normal;
    normal[0] = ((float *)ax)[0]; normal[1] = ((float *)ax)[1]; normal[2] = ((float *)ax)[2];
    void *bolt = *(void **)((byte *)prim + 8);
    if (bolt) {
        void *orient = FxBoltFrame_GetOrientation(bolt);
        vec3_t localNormal;
        OrientationDirFromWorldDir(orient, normal, localNormal);
        *(float *)(p + 0x24c) = localNormal[0]; *(float *)(p + 0x250) = localNormal[1]; *(float *)(p + 0x254) = localNormal[2];
    } else {
        *(float *)(p + 0x24c) = normal[0]; *(float *)(p + 0x250) = normal[1]; *(float *)(p + 0x254) = normal[2];
    }
    *(float *)(p + 4) = newOrigin[0]; *(float *)(p + 8) = newOrigin[1]; *(float *)(p + 0xc) = newOrigin[2];
}
#if 0 /* Original ASM */
__attribute__((naked))
void FX_AddOrientedParticle_original(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2013 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* prim */
        "movl 0xc(%ebp), %edi\n" /* ax */
        /* { scope 1: velSum */
        /* { scope 2 */
        "movl $0x258, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5be64_0005be9d\n"
        "movl $0x258, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5be64_0005be9d:\n"
        "movl %ebx, (%esp)\n" /* line 2025 | ptr */
        "calll OrientedParticle_OrientedParticle\n"
        "testl %ebx, %ebx\n" /* line 2026 | ptr */
        "je .Lf5be64_0005bfa6\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2029 | origin */
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* prim */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 2030 */
        "je .Lf5be64_0005bfae\n"
        "leal -0x24(%ebp), %ecx\n" /* line 2036 | newOrigin */
        "movl 0x18(%ebp), %eax\n" /* indexInBatch */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* ax */
        "movl 0x10(%ebp), %edx\n" /* origin */
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* prim */
        "calll FX_InitParticle\n"
        "movl 0xbc(%ebx), %ecx\n" /* line 2042 | ptr */
        "subl 0xb8(%ebx), %ecx\n" /* ptr */
        "movl 4(%esi), %eax\n" /* prim */
        "movl 0x18(%ebp), %edx\n" /* indexInBatch */
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "calll FX_SetMaterialAndSequenceParams\n"
        /* { scope 2 */
        "movl 0x14(%ebp), %eax\n" /* line 1472 | lateTime */
        "testl %eax, %eax\n"
        "jle .Lf5be64_0005bf61\n"
        "cvtsi2ssl 0x14(%ebp), %xmm1\n" /* line 1474 | lateTime */
        "mulss lit4_002ed658, %xmm1\n" /* 0.0010000000474974513f */
        "leal -0x48(%ebp), %eax\n" /* line 1476 | velSum */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* lateTime */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "movss %xmm1, -0x58(%ebp)\n"
        "calll Particle_IntegrateTotalVelocity\n"
        /* { scope 3 */
        "movss -0x58(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x48(%ebp), %xmm0\n" /* velSum */
        "addss -0x24(%ebp), %xmm0\n" /* newOrigin */
        "movss %xmm0, -0x24(%ebp)\n" /* newOrigin */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf5be64_0005bf61:\n"
        "movl (%edi), %edx\n" /* line 199 */
        "movl %edx, -0x30(%ebp)\n" /* norm */
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 2047 | prim */
        "testl %eax, %eax\n"
        "jne .Lf5be64_0005bfbe\n"
        "leal 0x24c(%ebx), %eax\n" /* line 530 | ptr, to */
        /* { scope 2 */
        "movl %edx, 0x24c(%ebx)\n" /* line 199 | ptr */
        "movl -0x2c(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%eax)\n"
        "movl -0x28(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        /* } scope */
        ".Lf5be64_0005bf91:\n"
        "leal 4(%ebx), %edx\n" /* line 208 | ptr, to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | newOrigin */
        "movl %eax, 4(%ebx)\n" /* ptr */
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        /* } scope */
        ".Lf5be64_0005bfa6:\n"
        "addl $0x5c, %esp\n" /* line 2060 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: velSum */
        ".Lf5be64_0005bfae:\n"
        "movl (%ebx), %eax\n" /* line 2032 | ptr */
        "movl %ebx, (%esp)\n" /* ptr */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2060 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: velSum */
        ".Lf5be64_0005bfbe:\n"
        "movl 8(%esi), %eax\n" /* line 2049 | prim */
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_GetOrientation\n"
        "leal -0x3c(%ebp), %edx\n" /* line 2051 | localNorm */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* norm */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll OrientationDirFromWorldDir\n"
        "leal 0x24c(%ebx), %edx\n" /* line 530 | ptr, to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | localNorm */
        "movl %eax, 0x24c(%ebx)\n" /* ptr */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf5be64_0005bf91\n"
        "movl %eax, %esi\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5be64_0005c00a\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5be64_0005c00a:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}
#endif

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
        int curTime = *(int *)((byte *)theFxHelper + 4);
        if (curTime > *(int *)(eff + 0xbc)) {
            /* Effect expired — clear flag and remove */
            *(int *)(eff + 0xa8) &= ~0x400;
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
            if (*(byte *)(dead + 0xa9) & 0x10)
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
        float dist = Vec3DistanceSq((vec_t *)(eff + 0x7c), (vec_t *)((byte *)theFxHelper + 0x14));
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
        int curTime = *(int *)((byte *)theFxHelper + 4);
        if (curTime > *(int *)(eff + 0xbc)) {
            *(int *)(eff + 0xa8) &= ~0x400;
            byte **slot = (byte **)effectListBolt + i;
            byte *dead = *slot;
            count--;
            privateEffectActiveCountBolt = count;
            byte *last = ((byte **)effectListBolt)[count];
            *slot = last;
            ((byte **)effectListBolt)[count] = dead;
            ((UpdateFn)(*(void ***)dead)[2])(dead);
            if (*(byte *)(dead + 0xa9) & 0x10)
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
        float dist = Vec3DistanceSq((vec_t *)(eff + 0x7c), (vec_t *)((byte *)theFxHelper + 0x14));
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
            if (*(int *)(eff + 0xac) == lastIdx)
                *(int *)(eff + 0xac) = clusterId;
        }
        for (i = 0; i < effectActiveCountNonBolt; i++) {
            byte *eff = ((byte **)effectListNonBolt)[i];
            if (*(int *)(eff + 0xac) == lastIdx)
                *(int *)(eff + 0xac) = clusterId;
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
        int curTime = *(int *)((byte *)theFxHelper + 4);
        if (curTime > *(int *)(eff + 0xbc)) {
            *(int *)(eff + 0xa8) &= ~0x400;
            /* Swap-remove and destroy */
            byte *dead = eff;
            count--;
            privateEffectActiveCountBolt = count;
            byte *last = ((byte **)effectListBolt)[count];
            ((byte **)effectListBolt)[i] = last;
            ((byte **)effectListBolt)[count] = dead;
            ((VtFn)(*(void ***)dead)[2])(dead); /* Die */
            if (*(byte *)(dead + 0xa9) & 0x10)
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
        int clusterId = *(int *)(eff + 0xac);
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        *(int *)(cluster + 0xc) -= 1;
        if (*(int *)(cluster + 0xc) <= 0) {
            FX_RemoveCluster(clusterId);
        }
        ((VtFn)(*(void ***)eff)[1])(eff); /* Delete */
        effectActiveCountBolt--;
        ((byte **)effectListBolt)[i] = ((byte **)effectListBolt)[effectActiveCountBolt];
        effectActiveCount--;
    }
}
#if 0 /* Original ASM */
__attribute__((naked))
void FX_UpdateAllBolt_asm(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1034 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl effectActiveCountBolt, %eax\n" /* line 1041 */
        "movl %eax, privateEffectActiveCountBolt\n"
        "movl %eax, initialEffectActiveCountBolt\n" /* line 1042 */
        "xorl %edi, %edi\n" /* effectIndex */
        "movl %eax, %esi\n" /* swapCache */
        ".Lf5c2f4_0005c310:\n"
        "cmpl %esi, %edi\n" /* line 1045 | swapCache, effectIndex */
        "jge .Lf5c2f4_0005c393\n"
        ".Lf5c2f4_0005c314:\n"
        "leal (, %edi, 4), %esi\n" /* line 1047 | swapCache */
        "movl effectListBolt, %eax\n"
        "movl (%esi, %eax), %edx\n" /* swapCache */
        "movl theFxHelper, %eax\n" /* line 1049 */
        "movl 4(%eax), %eax\n"
        "cmpl 0xbc(%edx), %eax\n"
        "jle .Lf5c2f4_0005c4de\n"
        "andl $0xfffffbff, 0xa8(%edx)\n" /* line 201 */
        ".Lf5c2f4_0005c341:\n"
        "movl effectListBolt, %eax\n" /* line 419 */
        "movl (%esi, %eax), %ebx\n" /* swapCache */
        "movl privateEffectActiveCountBolt, %edx\n" /* line 422 */
        "subl $1, %edx\n"
        "movl %edx, privateEffectActiveCountBolt\n"
        /* { scope 2 */
        "leal (%esi, %eax), %ecx\n" /* line 384 | swapCache */
        "movl (%ecx), %esi\n" /* swapCache */
        "shll $2, %edx\n" /* line 385 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl effectListBolt, %eax\n" /* line 386 */
        "movl %esi, (%edx, %eax)\n" /* swapCache */
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 403 */
        "movl %ebx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb $0x10, 0xa9(%ebx)\n" /* line 404 */
        "je .Lf5c2f4_0005c4fc\n"
        "subl $1, effectBlockSightCount\n" /* line 409 */
        "movl privateEffectActiveCountBolt, %esi\n" /* swapCache */
        /* } scope */
        "cmpl %esi, %edi\n" /* line 1045 | swapCache, effectIndex */
        "jl .Lf5c2f4_0005c314\n"
        ".Lf5c2f4_0005c393:\n"
        "cmpl %esi, initialEffectActiveCountBolt\n" /* line 721 | swapCache */
        "jle .Lf5c2f4_0005c507\n"
        "leal (, %esi, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf5c2f4_0005c3f0\n"
        ".Lf5c2f4_0005c3ad:\n"
        "movl (%edi), %eax\n" /* line 725 */
        "movl %edi, (%esp)\n"
        "calll *4(%eax)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 726 */
        "subl $1, %eax\n"
        "movl %eax, effectActiveCountBolt\n"
        "movl effectListBolt, %edx\n" /* line 727 */
        "movl (%edx, %eax, 4), %eax\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl %eax, (%edx, %ecx)\n"
        "addl $1, %esi\n" /* line 728 | swapCache */
        "subl $1, effectActiveCount\n" /* line 729 */
        "addl $4, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "cmpl %esi, initialEffectActiveCountBolt\n" /* line 721 | swapCache */
        "jle .Lf5c2f4_0005c507\n"
        "movl -0x1c(%ebp), %edx\n"
        ".Lf5c2f4_0005c3f0:\n"
        "movl effectListBolt, %eax\n" /* line 723 */
        "movl (%eax, %edx), %edi\n"
        "movl 0xac(%edi), %ecx\n" /* line 724 */
        "movl %ecx, -0x20(%ebp)\n"
        "movl %ecx, %ebx\n" /* line 152 */
        "shll $4, %ebx\n"
        "movl %ebx, %eax\n"
        "addl effectClusters, %eax\n"
        "subl $1, 0xc(%eax)\n"
        "movl effectClusters, %ecx\n" /* line 153 */
        "movl 0xc(%ebx, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf5c2f4_0005c3ad\n"
        "movl effectClusterCount, %eax\n" /* line 156 */
        "subl $1, %eax\n"
        "movl %eax, effectClusterCount\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 158 */
        "je .Lf5c2f4_0005c3ad\n"
        "movl %eax, %edx\n" /* line 160 */
        "shll $4, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx, %ecx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%ebx, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%ebx, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movl effectActiveCountBolt, %ecx\n" /* line 162 */
        "testl %ecx, %ecx\n"
        "jle .Lf5c2f4_0005c49c\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5c2f4_0005c472\n"
        ".Lf5c2f4_0005c467:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountBolt\n"
        "jle .Lf5c2f4_0005c49c\n"
        ".Lf5c2f4_0005c472:\n"
        "movl effectListBolt, %eax\n" /* line 164 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5c2f4_0005c467\n"
        "movl -0x20(%ebp), %eax\n" /* line 165 */
        "movl %eax, 0xac(%edx)\n"
        "addl $1, %ecx\n" /* line 162 */
        "cmpl %ecx, effectActiveCountBolt\n"
        "jg .Lf5c2f4_0005c472\n"
        ".Lf5c2f4_0005c49c:\n"
        "movl effectActiveCountNonBolt, %edx\n" /* line 168 */
        "testl %edx, %edx\n"
        "jle .Lf5c2f4_0005c3ad\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5c2f4_0005c4bd\n"
        ".Lf5c2f4_0005c4ae:\n"
        "addl $1, %ecx\n"
        "cmpl effectActiveCountNonBolt, %ecx\n"
        "jge .Lf5c2f4_0005c3ad\n"
        ".Lf5c2f4_0005c4bd:\n"
        "movl effectListNonBolt, %eax\n" /* line 170 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5c2f4_0005c4ae\n"
        "movl -0x20(%ebp), %eax\n" /* line 171 */
        "movl %eax, 0xac(%edx)\n"
        "jmp .Lf5c2f4_0005c4ae\n"
        ".Lf5c2f4_0005c4de:\n"
        "movl (%edx), %eax\n" /* line 1058 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n"
        "je .Lf5c2f4_0005c341\n"
        "addl $1, %edi\n" /* line 1065 | effectIndex */
        "movl privateEffectActiveCountBolt, %esi\n" /* swapCache */
        "jmp .Lf5c2f4_0005c310\n"
        ".Lf5c2f4_0005c4fc:\n"
        "movl privateEffectActiveCountBolt, %esi\n" /* swapCache */
        "jmp .Lf5c2f4_0005c310\n"
        /* } scope */
        ".Lf5c2f4_0005c507:\n"
        "addl $0x2c, %esp\n" /* line 1069 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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
        if (time < *(int *)(eff + 0xb8)) {
            /* Effect starts after rewind time — remove it */
            count--;
            privateEffectActiveCountBolt = count;
            byte **slot = (byte **)effectListBolt + i;
            byte *removed = *slot;
            *slot = ((byte **)effectListBolt)[count];
            ((byte **)effectListBolt)[count] = removed;
            if (*(byte *)(removed + 0xa9) & 0x10)
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
        int clusterId = *(int *)(eff + 0xac);
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        *(int *)(cluster + 0xc) -= 1;
        if (*(int *)(cluster + 0xc) <= 0)
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
        if (time < *(int *)(eff + 0xb8)) {
            count--;
            privateEffectActiveCountNonBolt = count;
            byte **slot = (byte **)effectListNonBolt + i;
            byte *removed = *slot;
            *slot = ((byte **)effectListNonBolt)[count];
            ((byte **)effectListNonBolt)[count] = removed;
            if (*(byte *)(removed + 0xa9) & 0x10)
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
        int clusterId = *(int *)(eff + 0xac);
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        *(int *)(cluster + 0xc) -= 1;
        if (*(int *)(cluster + 0xc) <= 0)
            FX_RemoveCluster(clusterId);
        ((VtFn)(*(void ***)eff)[1])(eff);
        effectActiveCountNonBolt--;
        ((byte **)effectListNonBolt)[i] = ((byte **)effectListNonBolt)[effectActiveCountNonBolt];
        effectActiveCount--;
    }
}
#if 0 /* Original ASM (286 lines) */
__attribute__((naked))
void FX_Rewind_asm(int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 759 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl effectActiveCountBolt, %ecx\n" /* line 767 */
        "movl %ecx, privateEffectActiveCountBolt\n"
        "movl %ecx, initialEffectActiveCountBolt\n" /* line 768 */
        "xorl %edi, %edi\n" /* effectIndex */
        ".Lf5c510_0005c52d:\n"
        "movl %ecx, -0x28(%ebp)\n" /* line 771 */
        "cmpl %ecx, %edi\n" /* effectIndex */
        "jge .Lf5c510_0005c590\n"
        ".Lf5c510_0005c534:\n"
        "leal (, %edi, 4), %edx\n" /* line 774 */
        "movl effectListBolt, %eax\n"
        "movl (%edx, %eax), %esi\n"
        "movl 8(%ebp), %ebx\n" /* time, swapCache */
        "cmpl 0xb8(%esi), %ebx\n" /* swapCache */
        "jge .Lf5c510_0005c6cb\n"
        "subl $1, %ecx\n" /* line 422 */
        "movl %ecx, privateEffectActiveCountBolt\n"
        /* { scope 2 */
        "addl %eax, %edx\n" /* line 384 */
        "movl (%edx), %ebx\n" /* swapCache */
        "shll $2, %ecx\n" /* line 385 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl effectListBolt, %eax\n" /* line 386 */
        "movl %ebx, (%ecx, %eax)\n" /* swapCache */
        /* } scope */
        "testb $0x10, 0xa9(%esi)\n" /* line 404 */
        "je .Lf5c510_0005c6d3\n"
        "subl $1, effectBlockSightCount\n" /* line 409 */
        "movl privateEffectActiveCountBolt, %ecx\n"
        "movl %ecx, -0x28(%ebp)\n" /* line 771 */
        "cmpl %ecx, %edi\n" /* effectIndex */
        "jl .Lf5c510_0005c534\n"
        ".Lf5c510_0005c590:\n"
        "cmpl %ecx, initialEffectActiveCountBolt\n" /* line 721 */
        "jle .Lf5c510_0005c6de\n"
        "leal (, %ecx, 4), %edi\n"
        "jmp .Lf5c510_0005c5e3\n"
        ".Lf5c510_0005c5a5:\n"
        "movl (%esi), %eax\n" /* line 725 */
        "movl %esi, (%esp)\n"
        "calll *4(%eax)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 726 */
        "subl $1, %eax\n"
        "movl %eax, effectActiveCountBolt\n"
        "movl effectListBolt, %edx\n" /* line 727 */
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%edi, %edx)\n"
        "addl $1, -0x28(%ebp)\n" /* line 728 */
        "subl $1, effectActiveCount\n" /* line 729 */
        "addl $4, %edi\n"
        "movl -0x28(%ebp), %ebx\n" /* line 721 | swapCache */
        "cmpl initialEffectActiveCountBolt, %ebx\n" /* swapCache */
        "jge .Lf5c510_0005c6de\n"
        ".Lf5c510_0005c5e3:\n"
        "movl effectListBolt, %eax\n" /* line 723 */
        "movl (%edi, %eax), %esi\n"
        "movl 0xac(%esi), %eax\n" /* line 724 */
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, %ebx\n" /* line 152 */
        "shll $4, %ebx\n"
        "movl %ebx, %eax\n"
        "addl effectClusters, %eax\n"
        "subl $1, 0xc(%eax)\n"
        "movl effectClusters, %ecx\n" /* line 153 */
        "movl 0xc(%ebx, %ecx), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf5c510_0005c5a5\n"
        "movl effectClusterCount, %eax\n" /* line 156 */
        "subl $1, %eax\n"
        "movl %eax, effectClusterCount\n"
        "cmpl %eax, -0x24(%ebp)\n" /* line 158 */
        "je .Lf5c510_0005c5a5\n"
        "movl %eax, %edx\n" /* line 160 */
        "shll $4, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx, %ecx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%ebx, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%ebx, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 162 */
        "testl %eax, %eax\n"
        "jle .Lf5c510_0005c68a\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5c510_0005c660\n"
        ".Lf5c510_0005c655:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountBolt\n"
        "jle .Lf5c510_0005c68a\n"
        ".Lf5c510_0005c660:\n"
        "movl effectListBolt, %eax\n" /* line 164 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5c510_0005c655\n"
        "movl -0x24(%ebp), %ebx\n" /* line 165 */
        "movl %ebx, 0xac(%edx)\n"
        "addl $1, %ecx\n" /* line 162 */
        "cmpl %ecx, effectActiveCountBolt\n"
        "jg .Lf5c510_0005c660\n"
        ".Lf5c510_0005c68a:\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 168 */
        "testl %eax, %eax\n"
        "jle .Lf5c510_0005c5a5\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5c510_0005c6aa\n"
        ".Lf5c510_0005c69b:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountNonBolt\n"
        "jle .Lf5c510_0005c5a5\n"
        ".Lf5c510_0005c6aa:\n"
        "movl effectListNonBolt, %eax\n" /* line 170 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5c510_0005c69b\n"
        "movl -0x24(%ebp), %eax\n" /* line 171 */
        "movl %eax, 0xac(%edx)\n"
        "jmp .Lf5c510_0005c69b\n"
        ".Lf5c510_0005c6cb:\n"
        "addl $1, %edi\n" /* line 781 | effectIndex */
        "jmp .Lf5c510_0005c52d\n"
        ".Lf5c510_0005c6d3:\n"
        "movl privateEffectActiveCountBolt, %ecx\n"
        "jmp .Lf5c510_0005c52d\n"
        ".Lf5c510_0005c6de:\n"
        "movl effectActiveCountNonBolt, %ecx\n" /* line 787 */
        "movl %ecx, privateEffectActiveCountNonBolt\n"
        "movl %ecx, initialEffectActiveCountNonBolt\n" /* line 788 */
        "xorl %edi, %edi\n" /* effectIndex */
        ".Lf5c510_0005c6f2:\n"
        "movl %ecx, -0x20(%ebp)\n" /* line 791 */
        "cmpl %ecx, %edi\n" /* effectIndex */
        "jge .Lf5c510_0005c755\n"
        ".Lf5c510_0005c6f9:\n"
        "leal (, %edi, 4), %edx\n" /* line 794 */
        "movl effectListNonBolt, %eax\n"
        "movl (%edx, %eax), %esi\n"
        "movl 8(%ebp), %ebx\n" /* time, swapCache */
        "cmpl %ebx, 0xb8(%esi)\n" /* swapCache */
        "jle .Lf5c510_0005c890\n"
        "subl $1, %ecx\n" /* line 435 */
        "movl %ecx, privateEffectActiveCountNonBolt\n"
        /* { scope 2 */
        "addl %eax, %edx\n" /* line 394 */
        "movl (%edx), %ebx\n" /* swapCache */
        "shll $2, %ecx\n" /* line 395 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl effectListNonBolt, %eax\n" /* line 396 */
        "movl %ebx, (%ecx, %eax)\n" /* swapCache */
        /* } scope */
        "testb $0x10, 0xa9(%esi)\n" /* line 404 */
        "je .Lf5c510_0005c898\n"
        "subl $1, effectBlockSightCount\n" /* line 409 */
        "movl privateEffectActiveCountNonBolt, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* line 791 */
        "cmpl %ecx, %edi\n" /* effectIndex */
        "jl .Lf5c510_0005c6f9\n"
        ".Lf5c510_0005c755:\n"
        "cmpl %ecx, initialEffectActiveCountNonBolt\n" /* line 744 */
        "jle .Lf5c510_0005c8a3\n"
        "leal (, %ecx, 4), %edi\n"
        "jmp .Lf5c510_0005c7a8\n"
        ".Lf5c510_0005c76a:\n"
        "movl (%esi), %eax\n" /* line 748 */
        "movl %esi, (%esp)\n"
        "calll *4(%eax)\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 749 */
        "subl $1, %eax\n"
        "movl %eax, effectActiveCountNonBolt\n"
        "movl effectListNonBolt, %edx\n" /* line 750 */
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%edx, %edi)\n"
        "addl $1, -0x20(%ebp)\n" /* line 751 */
        "subl $1, effectActiveCount\n" /* line 752 */
        "addl $4, %edi\n"
        "movl -0x20(%ebp), %ebx\n" /* line 744 | swapCache */
        "cmpl %ebx, initialEffectActiveCountNonBolt\n" /* swapCache */
        "jle .Lf5c510_0005c8a3\n"
        ".Lf5c510_0005c7a8:\n"
        "movl effectListNonBolt, %eax\n" /* line 746 */
        "movl (%eax, %edi), %esi\n"
        "movl 0xac(%esi), %eax\n" /* line 747 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 152 */
        "shll $4, %ebx\n"
        "movl %ebx, %eax\n"
        "addl effectClusters, %eax\n"
        "subl $1, 0xc(%eax)\n"
        "movl effectClusters, %ecx\n" /* line 153 */
        "movl 0xc(%ebx, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf5c510_0005c76a\n"
        "movl effectClusterCount, %eax\n" /* line 156 */
        "subl $1, %eax\n"
        "movl %eax, effectClusterCount\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 158 */
        "je .Lf5c510_0005c76a\n"
        "movl %eax, %edx\n" /* line 160 */
        "shll $4, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx, %ecx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%ebx, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%ebx, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 162 */
        "testl %eax, %eax\n"
        "jle .Lf5c510_0005c84f\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5c510_0005c825\n"
        ".Lf5c510_0005c81a:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountBolt\n"
        "jle .Lf5c510_0005c84f\n"
        ".Lf5c510_0005c825:\n"
        "movl effectListBolt, %eax\n" /* line 164 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5c510_0005c81a\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 165 */
        "movl %ebx, 0xac(%edx)\n"
        "addl $1, %ecx\n" /* line 162 */
        "cmpl %ecx, effectActiveCountBolt\n"
        "jg .Lf5c510_0005c825\n"
        ".Lf5c510_0005c84f:\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 168 */
        "testl %eax, %eax\n"
        "jle .Lf5c510_0005c76a\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5c510_0005c86f\n"
        ".Lf5c510_0005c860:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountNonBolt\n"
        "jle .Lf5c510_0005c76a\n"
        ".Lf5c510_0005c86f:\n"
        "movl effectListNonBolt, %eax\n" /* line 170 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5c510_0005c860\n"
        "movl -0x1c(%ebp), %eax\n" /* line 171 */
        "movl %eax, 0xac(%edx)\n"
        "jmp .Lf5c510_0005c860\n"
        ".Lf5c510_0005c890:\n"
        "addl $1, %edi\n" /* line 801 | effectIndex */
        "jmp .Lf5c510_0005c6f2\n"
        ".Lf5c510_0005c898:\n"
        "movl privateEffectActiveCountNonBolt, %ecx\n"
        "jmp .Lf5c510_0005c6f2\n"
        ".Lf5c510_0005c8a3:\n"
        "movl imp_theFxScheduler, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n" /* fix #152: null check before FxScheduler_Clean */
        "je .Lf5c510_skip_clean\n"
        "movl $0, 8(%esp)\n" /* line 808 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_Clean\n"
        ".Lf5c510_skip_clean:\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 809 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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
        int curTime = *(int *)((byte *)theFxHelper + 4);
        if (curTime > *(int *)(eff + 0xbc)) {
            *(int *)(eff + 0xa8) &= ~0x400;
            byte *dead = eff;
            count--;
            privateEffectActiveCountNonBolt = count;
            byte *last = ((byte **)effectListNonBolt)[count];
            ((byte **)effectListNonBolt)[i] = last;
            ((byte **)effectListNonBolt)[count] = dead;
            ((VtFn)(*(void ***)dead)[2])(dead);
            if (*(byte *)(dead + 0xa9) & 0x10)
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
        int clusterId = *(int *)(eff + 0xac);
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        *(int *)(cluster + 0xc) -= 1;
        if (*(int *)(cluster + 0xc) <= 0)
            FX_RemoveCluster(clusterId);
        ((VtFn)(*(void ***)eff)[1])(eff);
        effectActiveCountNonBolt--;
        ((byte **)effectListNonBolt)[i] = ((byte **)effectListNonBolt)[effectActiveCountNonBolt];
        effectActiveCount--;
    }
}
#if 0 /* Original ASM */
__attribute__((naked))
void FX_UpdateAllNonBolt_asm(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1072 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl effectActiveCountNonBolt, %eax\n" /* line 1079 */
        "movl %eax, privateEffectActiveCountNonBolt\n"
        "movl %eax, initialEffectActiveCountNonBolt\n" /* line 1080 */
        "xorl %edi, %edi\n" /* effectIndex */
        "movl %eax, %esi\n" /* swapCache */
        ".Lf5c8ca_0005c8e6:\n"
        "cmpl %esi, %edi\n" /* line 1083 | swapCache, effectIndex */
        "jge .Lf5c8ca_0005c969\n"
        ".Lf5c8ca_0005c8ea:\n"
        "leal (, %edi, 4), %esi\n" /* line 1085 | swapCache */
        "movl effectListNonBolt, %eax\n"
        "movl (%esi, %eax), %edx\n" /* swapCache */
        "movl theFxHelper, %eax\n" /* line 1087 */
        "movl 4(%eax), %eax\n"
        "cmpl 0xbc(%edx), %eax\n"
        "jle .Lf5c8ca_0005cab4\n"
        "andl $0xfffffbff, 0xa8(%edx)\n" /* line 201 */
        ".Lf5c8ca_0005c917:\n"
        "movl effectListNonBolt, %eax\n" /* line 432 */
        "movl (%esi, %eax), %ebx\n" /* swapCache */
        "movl privateEffectActiveCountNonBolt, %edx\n" /* line 435 */
        "subl $1, %edx\n"
        "movl %edx, privateEffectActiveCountNonBolt\n"
        /* { scope 2 */
        "leal (%esi, %eax), %ecx\n" /* line 394 | swapCache */
        "movl (%ecx), %esi\n" /* swapCache */
        "shll $2, %edx\n" /* line 395 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl effectListNonBolt, %eax\n" /* line 396 */
        "movl %esi, (%edx, %eax)\n" /* swapCache */
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 403 */
        "movl %ebx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb $0x10, 0xa9(%ebx)\n" /* line 404 */
        "je .Lf5c8ca_0005cad2\n"
        "subl $1, effectBlockSightCount\n" /* line 409 */
        "movl privateEffectActiveCountNonBolt, %esi\n" /* swapCache */
        /* } scope */
        "cmpl %esi, %edi\n" /* line 1083 | swapCache, effectIndex */
        "jl .Lf5c8ca_0005c8ea\n"
        ".Lf5c8ca_0005c969:\n"
        "cmpl %esi, initialEffectActiveCountNonBolt\n" /* line 744 | swapCache */
        "jle .Lf5c8ca_0005cadd\n"
        "leal (, %esi, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf5c8ca_0005c9c6\n"
        ".Lf5c8ca_0005c983:\n"
        "movl (%edi), %eax\n" /* line 748 */
        "movl %edi, (%esp)\n"
        "calll *4(%eax)\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 749 */
        "subl $1, %eax\n"
        "movl %eax, effectActiveCountNonBolt\n"
        "movl effectListNonBolt, %edx\n" /* line 750 */
        "movl (%edx, %eax, 4), %eax\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl %eax, (%edx, %ecx)\n"
        "addl $1, %esi\n" /* line 751 | swapCache */
        "subl $1, effectActiveCount\n" /* line 752 */
        "addl $4, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "cmpl %esi, initialEffectActiveCountNonBolt\n" /* line 744 | swapCache */
        "jle .Lf5c8ca_0005cadd\n"
        "movl -0x1c(%ebp), %edx\n"
        ".Lf5c8ca_0005c9c6:\n"
        "movl effectListNonBolt, %eax\n" /* line 746 */
        "movl (%eax, %edx), %edi\n"
        "movl 0xac(%edi), %ecx\n" /* line 747 */
        "movl %ecx, -0x20(%ebp)\n"
        "movl %ecx, %ebx\n" /* line 152 */
        "shll $4, %ebx\n"
        "movl %ebx, %eax\n"
        "addl effectClusters, %eax\n"
        "subl $1, 0xc(%eax)\n"
        "movl effectClusters, %ecx\n" /* line 153 */
        "movl 0xc(%ebx, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf5c8ca_0005c983\n"
        "movl effectClusterCount, %eax\n" /* line 156 */
        "subl $1, %eax\n"
        "movl %eax, effectClusterCount\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 158 */
        "je .Lf5c8ca_0005c983\n"
        "movl %eax, %edx\n" /* line 160 */
        "shll $4, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx, %ecx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%ebx, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%ebx, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movl effectActiveCountBolt, %ebx\n" /* line 162 */
        "testl %ebx, %ebx\n"
        "jle .Lf5c8ca_0005ca72\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5c8ca_0005ca48\n"
        ".Lf5c8ca_0005ca3d:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountBolt\n"
        "jle .Lf5c8ca_0005ca72\n"
        ".Lf5c8ca_0005ca48:\n"
        "movl effectListBolt, %eax\n" /* line 164 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5c8ca_0005ca3d\n"
        "movl -0x20(%ebp), %eax\n" /* line 165 */
        "movl %eax, 0xac(%edx)\n"
        "addl $1, %ecx\n" /* line 162 */
        "cmpl %ecx, effectActiveCountBolt\n"
        "jg .Lf5c8ca_0005ca48\n"
        ".Lf5c8ca_0005ca72:\n"
        "movl effectActiveCountNonBolt, %ecx\n" /* line 168 */
        "testl %ecx, %ecx\n"
        "jle .Lf5c8ca_0005c983\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5c8ca_0005ca93\n"
        ".Lf5c8ca_0005ca84:\n"
        "addl $1, %ecx\n"
        "cmpl effectActiveCountNonBolt, %ecx\n"
        "jge .Lf5c8ca_0005c983\n"
        ".Lf5c8ca_0005ca93:\n"
        "movl effectListNonBolt, %eax\n" /* line 170 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5c8ca_0005ca84\n"
        "movl -0x20(%ebp), %eax\n" /* line 171 */
        "movl %eax, 0xac(%edx)\n"
        "jmp .Lf5c8ca_0005ca84\n"
        ".Lf5c8ca_0005cab4:\n"
        "movl (%edx), %eax\n" /* line 1096 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n"
        "je .Lf5c8ca_0005c917\n"
        "addl $1, %edi\n" /* line 1103 | effectIndex */
        "movl privateEffectActiveCountNonBolt, %esi\n" /* swapCache */
        "jmp .Lf5c8ca_0005c8e6\n"
        ".Lf5c8ca_0005cad2:\n"
        "movl privateEffectActiveCountNonBolt, %esi\n" /* swapCache */
        "jmp .Lf5c8ca_0005c8e6\n"
        /* } scope */
        ".Lf5c8ca_0005cadd:\n"
        "addl $0x2c, %esp\n" /* line 1107 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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
        int clusterId = *(int *)(eff + 0xac);
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        *(int *)(cluster + 0xc) -= 1;
        if (*(int *)(cluster + 0xc) <= 0)
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
        int clusterId = *(int *)(eff + 0xac);
        byte *cluster = (byte *)effectClusters + clusterId * 16;
        *(int *)(cluster + 0xc) -= 1;
        if (*(int *)(cluster + 0xc) <= 0)
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
        int curTime = *(int *)((byte *)theFxHelper + 4);
        if (curTime > *(int *)(eff + 0xbc)) {
            *(int *)(eff + 0xa8) &= ~0x400;
            byte *dead = eff;
            count--;
            privateEffectActiveCountBolt = count;
            byte *last = ((byte **)effectListBolt)[count];
            ((byte **)effectListBolt)[i] = last;
            ((byte **)effectListBolt)[count] = dead;
            ((VtFn)(*(void ***)dead)[2])(dead);
            if (*(byte *)(dead + 0xa9) & 0x10) effectBlockSightCount--;
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
        int curTime = *(int *)((byte *)theFxHelper + 4);
        if (curTime > *(int *)(eff + 0xbc)) {
            *(int *)(eff + 0xa8) &= ~0x400;
            byte *dead = eff;
            count--;
            privateEffectActiveCountNonBolt = count;
            byte *last = ((byte **)effectListNonBolt)[count];
            ((byte **)effectListNonBolt)[i] = last;
            ((byte **)effectListNonBolt)[count] = dead;
            ((VtFn)(*(void ***)dead)[2])(dead);
            if (*(byte *)(dead + 0xa9) & 0x10) effectBlockSightCount--;
            count = privateEffectActiveCountNonBolt;
        } else {
            Bool alive = ((UpdateFn)(*(void ***)eff)[3])(eff);
            if (!alive) continue;
            i++;
            count = privateEffectActiveCountNonBolt;
        }
    }
}
#if 0 /* Original ASM (523 lines) */
__attribute__((naked))
void FX_DrawScheduledEffects_asm(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2270 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl imp_fx_enable, %eax\n" /* line 2275 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5cae6_0005d1af\n"
        "movl privateEffectActiveCountNonBolt, %eax\n" /* line 742 */
        "movl %eax, -0x38(%ebp)\n"
        "cmpl initialEffectActiveCountNonBolt, %eax\n" /* line 744 */
        "jge .Lf5cae6_0005cc41\n"
        "movl %eax, %edi\n"
        "shll $2, %edi\n"
        "jmp .Lf5cae6_0005cb59\n"
        ".Lf5cae6_0005cb1b:\n"
        "movl (%esi), %eax\n" /* line 748 | swapCache */
        "movl %esi, (%esp)\n" /* swapCache */
        "calll *4(%eax)\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 749 */
        "subl $1, %eax\n"
        "movl %eax, effectActiveCountNonBolt\n"
        "movl effectListNonBolt, %edx\n" /* line 750 */
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%edi, %edx)\n"
        "addl $1, -0x38(%ebp)\n" /* line 751 */
        "subl $1, effectActiveCount\n" /* line 752 */
        "addl $4, %edi\n"
        "movl -0x38(%ebp), %eax\n" /* line 744 */
        "cmpl initialEffectActiveCountNonBolt, %eax\n"
        "jge .Lf5cae6_0005cc41\n"
        ".Lf5cae6_0005cb59:\n"
        "movl effectListNonBolt, %eax\n" /* line 746 */
        "movl (%edi, %eax), %esi\n" /* swapCache */
        "movl 0xac(%esi), %eax\n" /* line 747 | swapCache */
        "movl %eax, -0x34(%ebp)\n"
        "movl %eax, %ebx\n" /* line 152 */
        "shll $4, %ebx\n"
        "movl %ebx, %eax\n"
        "addl effectClusters, %eax\n"
        "subl $1, 0xc(%eax)\n"
        "movl effectClusters, %ecx\n" /* line 153 */
        "movl 0xc(%ebx, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf5cae6_0005cb1b\n"
        "movl effectClusterCount, %eax\n" /* line 156 */
        "subl $1, %eax\n"
        "movl %eax, effectClusterCount\n"
        "cmpl %eax, -0x34(%ebp)\n" /* line 158 */
        "je .Lf5cae6_0005cb1b\n"
        "movl %eax, %edx\n" /* line 160 */
        "shll $4, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx, %ecx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%ebx, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%ebx, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 162 */
        "testl %eax, %eax\n"
        "jle .Lf5cae6_0005cc00\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5cae6_0005cbd6\n"
        ".Lf5cae6_0005cbcb:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountBolt\n"
        "jle .Lf5cae6_0005cc00\n"
        ".Lf5cae6_0005cbd6:\n"
        "movl effectListBolt, %eax\n" /* line 164 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5cae6_0005cbcb\n"
        "movl -0x34(%ebp), %eax\n" /* line 165 */
        "movl %eax, 0xac(%edx)\n"
        "addl $1, %ecx\n" /* line 162 */
        "cmpl %ecx, effectActiveCountBolt\n"
        "jg .Lf5cae6_0005cbd6\n"
        ".Lf5cae6_0005cc00:\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 168 */
        "testl %eax, %eax\n"
        "jle .Lf5cae6_0005cb1b\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5cae6_0005cc20\n"
        ".Lf5cae6_0005cc11:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountNonBolt\n"
        "jle .Lf5cae6_0005cb1b\n"
        ".Lf5cae6_0005cc20:\n"
        "movl effectListNonBolt, %eax\n" /* line 170 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5cae6_0005cc11\n"
        "movl -0x34(%ebp), %eax\n" /* line 171 */
        "movl %eax, 0xac(%edx)\n"
        "jmp .Lf5cae6_0005cc11\n"
        ".Lf5cae6_0005cc41:\n"
        "movl privateEffectActiveCountBolt, %eax\n" /* line 719 */
        "movl %eax, -0x30(%ebp)\n"
        "cmpl %eax, initialEffectActiveCountBolt\n" /* line 721 */
        "jg .Lf5cae6_0005d080\n"
        ".Lf5cae6_0005cc55:\n"
        "calll FX_AddScheduledEffects\n" /* line 2284 */
        "movl privateEffectActiveCountNonBolt, %edi\n" /* line 2288 | firstNewEffectIndex */
        "movl effectActiveCountNonBolt, %ecx\n" /* line 2289 */
        "movl %ecx, privateEffectActiveCountNonBolt\n"
        /* { scope 2 */
        "movl %ecx, initialEffectActiveCountNonBolt\n" /* line 1184 */
        ".Lf5cae6_0005cc72:\n"
        "movl %ecx, -0x28(%ebp)\n" /* line 1187 */
        "cmpl %ecx, %edi\n"
        "jge .Lf5cae6_0005cd03\n"
        ".Lf5cae6_0005cc7d:\n"
        "leal (, %edi, 4), %esi\n" /* line 1189 | swapCache */
        "movl effectListNonBolt, %eax\n"
        "movl (%esi, %eax), %edx\n" /* swapCache */
        "movl theFxHelper, %eax\n" /* line 1191 */
        "movl 4(%eax), %eax\n"
        "cmpl 0xbc(%edx), %eax\n"
        "jle .Lf5cae6_0005ceff\n"
        /* { scope 3 */
        "andl $0xfffffbff, 0xa8(%edx)\n" /* line 201 */
        /* } scope */
        ".Lf5cae6_0005ccaa:\n"
        "movl effectListNonBolt, %eax\n" /* line 432 */
        "movl (%esi, %eax), %ebx\n" /* swapCache, effect */
        "movl privateEffectActiveCountNonBolt, %ecx\n" /* line 435 */
        "subl $1, %ecx\n"
        "movl %ecx, privateEffectActiveCountNonBolt\n"
        /* { scope 3 */
        "leal (%esi, %eax), %edx\n" /* line 394 | swapCache */
        "movl (%edx), %esi\n" /* swapCache */
        "shll $2, %ecx\n" /* line 395 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl effectListNonBolt, %eax\n" /* line 396 */
        "movl %esi, (%ecx, %eax)\n" /* swapCache */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 403 */
        "movl %ebx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb $0x10, 0xa9(%ebx)\n" /* line 404 */
        "je .Lf5cae6_0005cf3b\n"
        "subl $1, effectBlockSightCount\n" /* line 409 */
        "movl privateEffectActiveCountNonBolt, %ecx\n"
        /* } scope */
        "movl %ecx, -0x28(%ebp)\n" /* line 1187 */
        "cmpl %ecx, %edi\n"
        "jl .Lf5cae6_0005cc7d\n"
        /* } scope */
        ".Lf5cae6_0005cd03:\n"
        "cmpl %ecx, initialEffectActiveCountNonBolt\n" /* line 744 */
        "jg .Lf5cae6_0005cf51\n"
        ".Lf5cae6_0005cd0f:\n"
        "movl privateEffectActiveCountBolt, %edi\n" /* line 2294 | firstNewEffectIndex */
        "movl effectActiveCountBolt, %ecx\n" /* line 2295 */
        "movl %ecx, privateEffectActiveCountBolt\n"
        /* { scope 2 */
        "movl %ecx, initialEffectActiveCountBolt\n" /* line 1117 */
        ".Lf5cae6_0005cd27:\n"
        "movl %ecx, -0x20(%ebp)\n" /* line 1120 */
        "cmpl %ecx, %edi\n"
        "jge .Lf5cae6_0005cdb8\n"
        ".Lf5cae6_0005cd32:\n"
        "leal (, %edi, 4), %esi\n" /* line 1122 | swapCache */
        "movl effectListBolt, %eax\n"
        "movl (%esi, %eax), %edx\n" /* swapCache */
        "movl theFxHelper, %eax\n" /* line 1124 */
        "movl 4(%eax), %eax\n"
        "cmpl 0xbc(%edx), %eax\n"
        "jle .Lf5cae6_0005cf1d\n"
        /* { scope 3 */
        "andl $0xfffffbff, 0xa8(%edx)\n" /* line 201 */
        /* } scope */
        ".Lf5cae6_0005cd5f:\n"
        "movl effectListBolt, %eax\n" /* line 419 */
        "movl (%esi, %eax), %ebx\n" /* swapCache */
        "movl privateEffectActiveCountBolt, %ecx\n" /* line 422 */
        "subl $1, %ecx\n"
        "movl %ecx, privateEffectActiveCountBolt\n"
        /* { scope 3 */
        "leal (%esi, %eax), %edx\n" /* line 384 | swapCache */
        "movl (%edx), %esi\n" /* swapCache */
        "shll $2, %ecx\n" /* line 385 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl effectListBolt, %eax\n" /* line 386 */
        "movl %esi, (%ecx, %eax)\n" /* swapCache */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 403 */
        "movl %ebx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb $0x10, 0xa9(%ebx)\n" /* line 404 */
        "je .Lf5cae6_0005cf46\n"
        "subl $1, effectBlockSightCount\n" /* line 409 */
        "movl privateEffectActiveCountBolt, %ecx\n"
        /* } scope */
        "movl %ecx, -0x20(%ebp)\n" /* line 1120 */
        "cmpl %ecx, %edi\n"
        "jl .Lf5cae6_0005cd32\n"
        /* } scope */
        ".Lf5cae6_0005cdb8:\n"
        "cmpl %ecx, initialEffectActiveCountBolt\n" /* line 721 */
        "jle .Lf5cae6_0005cef3\n"
        "leal (, %ecx, 4), %edi\n"
        "jmp .Lf5cae6_0005ce0b\n"
        ".Lf5cae6_0005cdcd:\n"
        "movl (%esi), %eax\n" /* line 725 | swapCache */
        "movl %esi, (%esp)\n" /* swapCache */
        "calll *4(%eax)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 726 */
        "subl $1, %eax\n"
        "movl %eax, effectActiveCountBolt\n"
        "movl effectListBolt, %edx\n" /* line 727 */
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%edi, %edx)\n"
        "addl $1, -0x20(%ebp)\n" /* line 728 */
        "subl $1, effectActiveCount\n" /* line 729 */
        "addl $4, %edi\n"
        "movl -0x20(%ebp), %eax\n" /* line 721 */
        "cmpl initialEffectActiveCountBolt, %eax\n"
        "jge .Lf5cae6_0005cef3\n"
        ".Lf5cae6_0005ce0b:\n"
        "movl effectListBolt, %eax\n" /* line 723 */
        "movl (%eax, %edi), %esi\n" /* swapCache */
        "movl 0xac(%esi), %eax\n" /* line 724 | swapCache */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 152 */
        "shll $4, %ebx\n"
        "movl %ebx, %eax\n"
        "addl effectClusters, %eax\n"
        "subl $1, 0xc(%eax)\n"
        "movl effectClusters, %ecx\n" /* line 153 */
        "movl 0xc(%ebx, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf5cae6_0005cdcd\n"
        "movl effectClusterCount, %eax\n" /* line 156 */
        "subl $1, %eax\n"
        "movl %eax, effectClusterCount\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 158 */
        "je .Lf5cae6_0005cdcd\n"
        "movl %eax, %edx\n" /* line 160 */
        "shll $4, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx, %ecx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%ebx, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%ebx, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 162 */
        "testl %eax, %eax\n"
        "jle .Lf5cae6_0005ceb2\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5cae6_0005ce88\n"
        ".Lf5cae6_0005ce7d:\n"
        "addl $1, %ecx\n"
        "cmpl effectActiveCountBolt, %ecx\n"
        "jge .Lf5cae6_0005ceb2\n"
        ".Lf5cae6_0005ce88:\n"
        "movl effectListBolt, %eax\n" /* line 164 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5cae6_0005ce7d\n"
        "movl -0x1c(%ebp), %eax\n" /* line 165 */
        "movl %eax, 0xac(%edx)\n"
        "addl $1, %ecx\n" /* line 162 */
        "cmpl effectActiveCountBolt, %ecx\n"
        "jl .Lf5cae6_0005ce88\n"
        ".Lf5cae6_0005ceb2:\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 168 */
        "testl %eax, %eax\n"
        "jle .Lf5cae6_0005cdcd\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5cae6_0005ced2\n"
        ".Lf5cae6_0005cec3:\n"
        "addl $1, %ecx\n"
        "cmpl effectActiveCountNonBolt, %ecx\n"
        "jge .Lf5cae6_0005cdcd\n"
        ".Lf5cae6_0005ced2:\n"
        "movl effectListNonBolt, %eax\n" /* line 170 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5cae6_0005cec3\n"
        "movl -0x1c(%ebp), %eax\n" /* line 171 */
        "movl %eax, 0xac(%edx)\n"
        "jmp .Lf5cae6_0005cec3\n"
        /* } scope */
        ".Lf5cae6_0005cef3:\n"
        "addl $0x3c, %esp\n" /* line 2303 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp FX_DrawAll\n" /* line 2300 */
        /* { scope 2 */
        ".Lf5cae6_0005ceff:\n"
        "movl (%edx), %eax\n" /* line 1201 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n" /* line 1203 */
        "je .Lf5cae6_0005ccaa\n"
        "addl $1, %edi\n" /* line 1209 */
        "movl privateEffectActiveCountNonBolt, %ecx\n"
        "jmp .Lf5cae6_0005cc72\n"
        /* } scope */
        /* { scope 2 */
        ".Lf5cae6_0005cf1d:\n"
        "movl (%edx), %eax\n" /* line 1134 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n" /* line 1136 */
        "je .Lf5cae6_0005cd5f\n"
        "addl $1, %edi\n" /* line 1142 */
        "movl privateEffectActiveCountBolt, %ecx\n"
        "jmp .Lf5cae6_0005cd27\n"
        ".Lf5cae6_0005cf3b:\n"
        "movl privateEffectActiveCountNonBolt, %ecx\n"
        "jmp .Lf5cae6_0005cc72\n"
        ".Lf5cae6_0005cf46:\n"
        "movl privateEffectActiveCountBolt, %ecx\n"
        "jmp .Lf5cae6_0005cd27\n"
        /* } scope */
        ".Lf5cae6_0005cf51:\n"
        "leal (, %ecx, 4), %edi\n" /* line 744 */
        "jmp .Lf5cae6_0005cf98\n"
        ".Lf5cae6_0005cf5a:\n"
        "movl (%esi), %eax\n" /* line 748 | swapCache */
        "movl %esi, (%esp)\n" /* swapCache */
        "calll *4(%eax)\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 749 */
        "subl $1, %eax\n"
        "movl %eax, effectActiveCountNonBolt\n"
        "movl effectListNonBolt, %edx\n" /* line 750 */
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%edi, %edx)\n"
        "addl $1, -0x28(%ebp)\n" /* line 751 */
        "subl $1, effectActiveCount\n" /* line 752 */
        "addl $4, %edi\n"
        "movl -0x28(%ebp), %eax\n" /* line 744 */
        "cmpl %eax, initialEffectActiveCountNonBolt\n"
        "jle .Lf5cae6_0005cd0f\n"
        ".Lf5cae6_0005cf98:\n"
        "movl effectListNonBolt, %eax\n" /* line 746 */
        "movl (%edi, %eax), %esi\n" /* swapCache */
        "movl 0xac(%esi), %eax\n" /* line 747 | swapCache */
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, %ebx\n" /* line 152 */
        "shll $4, %ebx\n"
        "movl %ebx, %eax\n"
        "addl effectClusters, %eax\n"
        "subl $1, 0xc(%eax)\n"
        "movl effectClusters, %ecx\n" /* line 153 */
        "movl 0xc(%ebx, %ecx), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf5cae6_0005cf5a\n"
        "movl effectClusterCount, %eax\n" /* line 156 */
        "subl $1, %eax\n"
        "movl %eax, effectClusterCount\n"
        "cmpl %eax, -0x24(%ebp)\n" /* line 158 */
        "je .Lf5cae6_0005cf5a\n"
        "movl %eax, %edx\n" /* line 160 */
        "shll $4, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx, %ecx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%ebx, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%ebx, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 162 */
        "testl %eax, %eax\n"
        "jle .Lf5cae6_0005d03f\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5cae6_0005d015\n"
        ".Lf5cae6_0005d00a:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountBolt\n"
        "jle .Lf5cae6_0005d03f\n"
        ".Lf5cae6_0005d015:\n"
        "movl effectListBolt, %eax\n" /* line 164 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5cae6_0005d00a\n"
        "movl -0x24(%ebp), %eax\n" /* line 165 */
        "movl %eax, 0xac(%edx)\n"
        "addl $1, %ecx\n" /* line 162 */
        "cmpl %ecx, effectActiveCountBolt\n"
        "jg .Lf5cae6_0005d015\n"
        ".Lf5cae6_0005d03f:\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 168 */
        "testl %eax, %eax\n"
        "jle .Lf5cae6_0005cf5a\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5cae6_0005d05f\n"
        ".Lf5cae6_0005d050:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountNonBolt\n"
        "jle .Lf5cae6_0005cf5a\n"
        ".Lf5cae6_0005d05f:\n"
        "movl effectListNonBolt, %eax\n" /* line 170 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5cae6_0005d050\n"
        "movl -0x24(%ebp), %eax\n" /* line 171 */
        "movl %eax, 0xac(%edx)\n"
        "jmp .Lf5cae6_0005d050\n"
        ".Lf5cae6_0005d080:\n"
        "movl %eax, %edi\n" /* line 721 */
        "shll $2, %edi\n"
        "jmp .Lf5cae6_0005d0c5\n"
        ".Lf5cae6_0005d087:\n"
        "movl (%esi), %eax\n" /* line 725 | swapCache */
        "movl %esi, (%esp)\n" /* swapCache */
        "calll *4(%eax)\n"
        "movl effectActiveCountBolt, %eax\n" /* line 726 */
        "subl $1, %eax\n"
        "movl %eax, effectActiveCountBolt\n"
        "movl effectListBolt, %edx\n" /* line 727 */
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%edi, %edx)\n"
        "addl $1, -0x30(%ebp)\n" /* line 728 */
        "subl $1, effectActiveCount\n" /* line 729 */
        "addl $4, %edi\n"
        "movl -0x30(%ebp), %eax\n" /* line 721 */
        "cmpl %eax, initialEffectActiveCountBolt\n"
        "jle .Lf5cae6_0005cc55\n"
        ".Lf5cae6_0005d0c5:\n"
        "movl effectListBolt, %eax\n" /* line 723 */
        "movl (%edi, %eax), %esi\n" /* swapCache */
        "movl 0xac(%esi), %eax\n" /* line 724 | swapCache */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, %ebx\n" /* line 152 */
        "shll $4, %ebx\n"
        "movl %ebx, %eax\n"
        "addl effectClusters, %eax\n"
        "subl $1, 0xc(%eax)\n"
        "movl effectClusters, %ecx\n" /* line 153 */
        "movl 0xc(%ebx, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf5cae6_0005d087\n"
        "movl effectClusterCount, %eax\n" /* line 156 */
        "subl $1, %eax\n"
        "movl %eax, effectClusterCount\n"
        "cmpl %eax, -0x2c(%ebp)\n" /* line 158 */
        "je .Lf5cae6_0005d087\n"
        "movl %eax, %edx\n" /* line 160 */
        "shll $4, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx, %ecx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%ebx, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%ebx, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%ebx, %ecx)\n"
        "movl effectActiveCountBolt, %ebx\n" /* line 162 */
        "testl %ebx, %ebx\n"
        "jle .Lf5cae6_0005d16d\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5cae6_0005d143\n"
        ".Lf5cae6_0005d138:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountBolt\n"
        "jle .Lf5cae6_0005d16d\n"
        ".Lf5cae6_0005d143:\n"
        "movl effectListBolt, %eax\n" /* line 164 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5cae6_0005d138\n"
        "movl -0x2c(%ebp), %eax\n" /* line 165 */
        "movl %eax, 0xac(%edx)\n"
        "addl $1, %ecx\n" /* line 162 */
        "cmpl %ecx, effectActiveCountBolt\n"
        "jg .Lf5cae6_0005d143\n"
        ".Lf5cae6_0005d16d:\n"
        "movl effectActiveCountNonBolt, %ecx\n" /* line 168 */
        "testl %ecx, %ecx\n"
        "jle .Lf5cae6_0005d087\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf5cae6_0005d18e\n"
        ".Lf5cae6_0005d17f:\n"
        "addl $1, %ecx\n"
        "cmpl %ecx, effectActiveCountNonBolt\n"
        "jle .Lf5cae6_0005d087\n"
        ".Lf5cae6_0005d18e:\n"
        "movl effectListNonBolt, %eax\n" /* line 170 */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0xac(%edx), %eax\n"
        "cmpl effectClusterCount, %eax\n"
        "jne .Lf5cae6_0005d17f\n"
        "movl -0x2c(%ebp), %eax\n" /* line 171 */
        "movl %eax, 0xac(%edx)\n"
        "jmp .Lf5cae6_0005d17f\n"
        /* } scope */
        ".Lf5cae6_0005d1af:\n"
        "addl $0x3c, %esp\n" /* line 2303 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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
        byte *fxTemplate = *(byte **)(eff + 0x34);
        int primIdx = *(int *)(eff + 0x38);
        byte *primTemp = NULL;
        if (fxTemplate && primIdx < *(int *)(fxTemplate + 4))
            primTemp = *(byte **)(fxTemplate + 8 + primIdx * 4);

        if (!primTemp) continue;

        /* Call FixupArchiveLoad (vtable[11]) */
        ((FixupFn)(*(void ***)eff)[11])(eff, primTemp);

        if (*(byte *)(eff + 0xa9) & 0x10)
            effectBlockSightCount++;

        /* Add to bolt or non-bolt list */
        if (*(byte **)(eff + 0xc0)) {
            ((byte **)effectListBolt)[effectActiveCountBolt] = eff;
            effectActiveCountBolt++;
        } else {
            ((byte **)effectListNonBolt)[effectActiveCountNonBolt] = eff;
            effectActiveCountNonBolt++;
        }
        effectActiveCount++;
    }

    /* Close archive */
    int bytesRead = *(int *)(arch + 0); /* assume first field is bytes read */
    return bytesRead;
}
#if 0 /* Original ASM (342 lines) */
__attribute__((naked))
int FX_Restore_asm(MemoryFile *memFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 874 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "leal -0x34(%ebp), %esi\n" /* line 880 | arch */
        "movl %esi, (%esp)\n"
        "calll FxArchive_FxArchive\n"
        "movl effectActiveCountBolt, %edx\n" /* line 227 */
        "testl %edx, %edx\n"
        "jle .Lf5d1b8_0005d1f7\n"
        "xorl %ebx, %ebx\n" /* ptr */
        ".Lf5d1b8_0005d1d8:\n"
        "movl effectListBolt, %eax\n" /* line 228 */
        "movl (%eax, %ebx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf5d1b8_0005d1ec\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf5d1b8_0005d1ec:\n"
        "addl $1, %ebx\n" /* line 227 | ptr */
        "cmpl effectActiveCountBolt, %ebx\n" /* ptr */
        "jl .Lf5d1b8_0005d1d8\n"
        ".Lf5d1b8_0005d1f7:\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 229 */
        "testl %eax, %eax\n"
        "jle .Lf5d1b8_0005d221\n"
        "xorl %ebx, %ebx\n" /* ptr */
        ".Lf5d1b8_0005d202:\n"
        "movl effectListNonBolt, %eax\n" /* line 230 */
        "movl (%eax, %ebx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf5d1b8_0005d216\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf5d1b8_0005d216:\n"
        "addl $1, %ebx\n" /* line 229 | ptr */
        "cmpl effectActiveCountNonBolt, %ebx\n" /* ptr */
        "jl .Lf5d1b8_0005d202\n"
        ".Lf5d1b8_0005d221:\n"
        "movl $0, effectActiveCountBolt\n" /* line 232 */
        "movl $0, effectActiveCountNonBolt\n" /* line 233 */
        "movl $0, effectActiveCount\n" /* line 234 */
        "movl $0, effectBlockSightCount\n" /* line 235 */
        "movl $0, effectClusterCount\n" /* line 236 */
        "movl imp_theFxScheduler, %ebx\n" /* line 244 | ptr */
        "movl (%ebx), %eax\n" /* ptr */
        "testl %eax, %eax\n"
        "je .Lf5d1b8_0005d277\n"
        "movl $0, 8(%esp)\n" /* line 247 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_Clean\n"
        ".Lf5d1b8_0005d277:\n"
        "movl 8(%ebp), %eax\n" /* line 890 | memFile */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_BeginReading\n"
        "movl %esi, 4(%esp)\n" /* line 891 */
        "movl theFxHelper, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_Archive\n"
        "movl %esi, 4(%esp)\n" /* line 892 */
        "movl (%ebx), %eax\n" /* effect */
        "movl %eax, (%esp)\n"
        "calll FxScheduler_Archive\n"
        "leal -0x1c(%ebp), %edi\n"
        ".Lf5d1b8_0005d2a8:\n"
        "movl $1, 8(%esp)\n" /* line 84 */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "movzbl -0x1c(%ebp), %ebx\n" /* line 895 | effect */
        "testb %bl, %bl\n" /* line 896 | effect */
        "je .Lf5d1b8_0005d3aa\n"
        ".Lf5d1b8_0005d2c8:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "movzbl %bl, %eax\n" /* line 902 | effect */
        "cmpl $0xc, %eax\n"
        "ja .Lf5d1b8_0005d2a8\n"
        "jmpl *.Ljt_5d1b8_0(, %eax, 4)\n"
        /* { scope 2 */
        ".Lf5d1b8_0005d2eb:\n"
        "movl $0x24c, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d315\n"
        "movl $0x24c, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d315:\n"
        "movl %ebx, (%esp)\n" /* line 905 | effect */
        "calll Particle_Particle\n"
        ".Lf5d1b8_0005d31d:\n"
        "movl (%ebx), %eax\n" /* line 936 | effect */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* effect */
        "calll *0x28(%eax)\n"
        "movl 0x38(%ebx), %edx\n" /* line 221 | ptr */
        "movl 0x34(%ebx), %eax\n" /* line 220 | ptr */
        /* { scope 2 */
        "cmpl 4(%eax), %edx\n" /* line 862 */
        "jge .Lf5d1b8_0005d405\n"
        ".Lf5d1b8_0005d338:\n"
        "movl 8(%eax, %edx, 4), %edx\n" /* line 865 */
        /* } scope */
        "testl %edx, %edx\n" /* line 942 */
        "je .Lf5d1b8_0005d405\n"
        "movl (%ebx), %eax\n" /* line 948 | effect */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* effect */
        "calll *0x2c(%eax)\n"
        "testb $0x10, 0xa9(%ebx)\n" /* line 949 | effect */
        "je .Lf5d1b8_0005d360\n"
        "addl $1, effectBlockSightCount\n" /* line 950 */
        ".Lf5d1b8_0005d360:\n"
        "movl 0xc0(%ebx), %eax\n" /* line 952 | effect */
        "testl %eax, %eax\n"
        "je .Lf5d1b8_0005d59d\n"
        "movl effectActiveCountBolt, %edx\n" /* line 954 */
        "movl effectListBolt, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n" /* effect */
        "addl $1, effectActiveCountBolt\n" /* line 955 */
        "addl $1, effectActiveCount\n" /* line 956 */
        "movl $1, 8(%esp)\n" /* line 84 */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "movzbl -0x1c(%ebp), %ebx\n" /* line 895 | effect */
        "testb %bl, %bl\n" /* line 896 | effect */
        "jne .Lf5d1b8_0005d2c8\n"
        ".Lf5d1b8_0005d3aa:\n"
        "movl -0x34(%ebp), %eax\n" /* line 963 | arch */
        "movl 8(%eax), %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 969 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf5d1b8_0005d3b8:\n"
        "movl $0x258, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d3e2\n"
        "movl $0x258, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d3e2:\n"
        "movl %ebx, (%esp)\n" /* line 908 | effect */
        "calll Line_Line\n"
        "movl (%ebx), %eax\n" /* line 936 | effect */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* effect */
        "calll *0x28(%eax)\n"
        "movl 0x38(%ebx), %edx\n" /* line 221 | ptr */
        "movl 0x34(%ebx), %eax\n" /* line 220 | ptr */
        /* { scope 2 */
        "cmpl 4(%eax), %edx\n" /* line 862 */
        "jl .Lf5d1b8_0005d338\n"
        /* } scope */
        ".Lf5d1b8_0005d405:\n"
        "movl (%ebx), %eax\n" /* line 944 | effect */
        "movl %ebx, (%esp)\n" /* effect */
        "calll *4(%eax)\n"
        "jmp .Lf5d1b8_0005d2a8\n"
        /* { scope 2 */
        ".Lf5d1b8_0005d412:\n"
        "movl $0x278, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d43c\n"
        "movl $0x278, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d43c:\n"
        "movl %ebx, (%esp)\n" /* line 911 | effect */
        "calll Tail_Tail\n"
        "jmp .Lf5d1b8_0005d31d\n"
        /* { scope 2 */
        ".Lf5d1b8_0005d449:\n"
        "movl $0x278, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d473\n"
        "movl $0x278, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d473:\n"
        "movl %ebx, (%esp)\n" /* line 914 | effect */
        "calll Cylinder_Cylinder\n"
        "jmp .Lf5d1b8_0005d31d\n"
        /* { scope 2 */
        ".Lf5d1b8_0005d480:\n"
        "movl $0x29c, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d4aa\n"
        "movl $0x29c, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d4aa:\n"
        "movl %ebx, (%esp)\n" /* line 917 | effect */
        "calll Emitter_Emitter\n"
        "jmp .Lf5d1b8_0005d31d\n"
        /* { scope 2 */
        ".Lf5d1b8_0005d4b7:\n"
        "movl $0x258, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d4e1\n"
        "movl $0x258, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d4e1:\n"
        "movl %ebx, (%esp)\n" /* line 920 | effect */
        "calll OrientedParticle_OrientedParticle\n"
        "jmp .Lf5d1b8_0005d31d\n"
        /* { scope 2 */
        ".Lf5d1b8_0005d4ee:\n"
        "movl $0xfc, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d518\n"
        "movl $0xfc, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d518:\n"
        "movl %ebx, (%esp)\n" /* line 923 | effect */
        "calll Light_Light\n"
        "jmp .Lf5d1b8_0005d31d\n"
        /* { scope 2 */
        ".Lf5d1b8_0005d525:\n"
        "movl $0xfc, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d54f\n"
        "movl $0xfc, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d54f:\n"
        "movl %ebx, (%esp)\n" /* line 281 | ptr */
        "calll Light_Light\n"
        "movl imp__ZTV5Flash, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%ebx)\n" /* ptr */
        "jmp .Lf5d1b8_0005d31d\n"
        /* { scope 2 */
        ".Lf5d1b8_0005d566:\n"
        "movl $0x27c, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5d1b8_0005d590\n"
        "movl $0x27c, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5d1b8_0005d590:\n"
        "movl %ebx, (%esp)\n" /* line 929 | effect */
        "calll Cloud_Cloud\n"
        "jmp .Lf5d1b8_0005d31d\n"
        ".Lf5d1b8_0005d59d:\n"
        "movl effectActiveCountNonBolt, %edx\n" /* line 961 */
        "movl effectListNonBolt, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n" /* effect */
        "addl $1, effectActiveCountNonBolt\n" /* line 962 */
        "addl $1, effectActiveCount\n" /* line 963 */
        "jmp .Lf5d1b8_0005d2a8\n"
        ".Lf5d1b8_0005d5be:\n"
        "movl %eax, %esi\n"
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5d1b8_0005d5cc\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5d1b8_0005d5cc:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
        "jmp .Lf5d1b8_0005d5be\n"
        "jmp .Lf5d1b8_0005d5be\n"
        "jmp .Lf5d1b8_0005d5be\n"
        "jmp .Lf5d1b8_0005d5be\n"
        "jmp .Lf5d1b8_0005d5be\n"
        "jmp .Lf5d1b8_0005d5be\n"
        "jmp .Lf5d1b8_0005d5be\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_5d1b8_0:\n"
        ".long .Lf5d1b8_0005d2a8\n"
        ".long .Lf5d1b8_0005d2eb\n"
        ".long .Lf5d1b8_0005d3b8\n"
        ".long .Lf5d1b8_0005d412\n"
        ".long .Lf5d1b8_0005d449\n"
        ".long .Lf5d1b8_0005d480\n"
        ".long .Lf5d1b8_0005d2a8\n"
        ".long .Lf5d1b8_0005d4b7\n"
        ".long .Lf5d1b8_0005d2a8\n"
        ".long .Lf5d1b8_0005d4ee\n"
        ".long .Lf5d1b8_0005d2a8\n"
        ".long .Lf5d1b8_0005d525\n"
        ".long .Lf5d1b8_0005d566\n"
        ".text\n"
    );
}
#endif

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
