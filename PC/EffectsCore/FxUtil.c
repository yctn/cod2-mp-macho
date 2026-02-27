/* ASM dump from: FxUtil.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxUtil.cpp */

#include "common_types.h"
#include "imports.h"

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
static effectClusterArray_t effectClusterArray; /* 0x4a7600 */
static effectListArray_t effectListArrayBolt; /* 0x4a5980 */
static effectListArray_t effectListArrayNonBolt; /* 0x4a3d00 */
static SortedEffect visibleEffectsNonBolt[1800]; /* 0x4b1ec0 */
static SortedEffect visibleEffectsBolt[1800]; /* 0x4ae680 */

void FX_InitServer(void);
static int CompareSortedEffects(const void *e0, const void *e1);
static int CompareSortedClusters(const void *e0, const void *e1);
void FX_SetSortGroup(Effect *fx);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__I_effectClusters(void); /* global constructors keyed to effectClusters */
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
static __attribute__((naked))
int CompareSortedEffects(const void *e0, const void *e1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 974 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edi\n" /* e1 */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 982 | e0 */
        "movl (%eax), %esi\n"
        "movl (%edi), %ebx\n" /* line 983 | e1 */
        "movl 0xb0(%esi), %eax\n" /* line 985 */
        "subl 0xb0(%ebx), %eax\n" /* line 986 */
        "jne .Lf5946e_000594ae\n"
        "movl clusterSort, %edx\n" /* line 989 */
        "movl 0xac(%esi), %eax\n"
        "movl 0xac(%ebx), %ecx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "subl (%edx, %ecx, 4), %eax\n" /* line 990 */
        "jne .Lf5946e_000594ae\n"
        "movl 0x40(%esi), %eax\n" /* line 993 */
        "subl 0x40(%ebx), %eax\n" /* line 994 */
        "je .Lf5946e_000594b3\n"
        /* } scope */
        ".Lf5946e_000594ae:\n"
        "popl %ebx\n" /* line 998 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5946e_000594b3:\n"
        "movss 4(%edi), %xmm0\n" /* line 997 | e1 */
        "movl 8(%ebp), %eax\n" /* e0 */
        "ucomiss 4(%eax), %xmm0\n"
        "seta %al\n"
        "movzbl %al, %eax\n"
        "leal -1(%eax, %eax), %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 998 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1001 */
static int CompareSortedClusters(const void *e0, const void *e1)
{
    float v1 = *(float *)((byte *)e1 + 4);
    float v0 = *(float *)((byte *)e0 + 4);
    return (v1 > v0) ? 1 : -1;
}

/* line 1549 */
__attribute__((naked))
void FX_SetSortGroup(Effect *fx)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1549 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* fx */
        "movl $0, 0xb0(%ebx)\n" /* line 1551 | fx */
        "movl 0x40(%ebx), %eax\n" /* line 1552 | fx */
        "testl %eax, %eax\n"
        "je .Lf594ec_00059526\n"
        "movl %eax, 4(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_IsMaterialRefractive\n"
        "testb %al, %al\n"
        "je .Lf594ec_00059526\n"
        "movl $0xffffffff, 0xb0(%ebx)\n" /* line 1553 | fx */
        ".Lf594ec_00059526:\n"
        "addl $0x14, %esp\n" /* line 1554 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2306 */
static __attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2306 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 110 */
        "je .Lf5952c_0005953c\n"
        ".Lf5952c_0005953a:\n"
        "leave\n" /* line 2306 */
        "retl\n"
        ".Lf5952c_0005953c:\n"
        "subl $1, %eax\n" /* line 110 */
        "jne .Lf5952c_0005953a\n"
        "movl $theFxHelpers, (%esp)\n"
        "calll FxHelper_FxHelper\n"
        "leave\n" /* line 2306 */
        "retl\n"
    );
}

/* line 2307 */
static __attribute__((naked))
void GLOBAL__I_effectClusters(void) /* global constructors keyed to effectClusters */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2307 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 122 */
__attribute__((naked))
int FX_GetCluster(const vec_t *origin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* origin */
        /* { scope 1 */
        "movl effectClusterCount, %eax\n" /* line 127 */
        "testl %eax, %eax\n"
        "jg .Lf59564_000595c4\n"
        ".Lf59564_00059579:\n"
        "movl %eax, %edx\n" /* line 138 | to */
        "shll $4, %edx\n" /* to */
        "addl effectClusters, %edx\n" /* to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | origin */
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %eax\n" /* line 200 | origin */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 201 | origin */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl effectClusterCount, %eax\n" /* line 139 */
        "shll $4, %eax\n"
        "movl effectClusters, %edx\n"
        "movl $1, 0xc(%eax, %edx)\n"
        "movl effectClusterCount, %edx\n" /* line 140 */
        "leal 1(%edx), %eax\n"
        "movl %eax, effectClusterCount\n"
        "movl %edx, %esi\n" /* line 141 | clusterId */
        /* } scope */
        ".Lf59564_000595ba:\n"
        "movl %esi, %eax\n" /* line 142 | clusterId */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf59564_000595c4:\n"
        "xorl %esi, %esi\n" /* line 127 | clusterId */
        "xorl %ebx, %ebx\n"
        "jmp .Lf59564_000595d9\n"
        ".Lf59564_000595ca:\n"
        "addl $1, %esi\n" /* clusterId */
        "movl effectClusterCount, %eax\n"
        "addl $0x10, %ebx\n"
        "cmpl %eax, %esi\n" /* clusterId */
        "jge .Lf59564_00059579\n"
        ".Lf59564_000595d9:\n"
        "movl %ebx, %eax\n" /* line 129 */
        "addl effectClusters, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* origin */
        "calll Vec3DistanceSq\n"
        "fstps -0x1c(%ebp)\n" /* distSq */
        "movss 0x2ed688, %xmm0\n" /* line 130 | 131072.0f */
        "ucomiss -0x1c(%ebp), %xmm0\n" /* distSq */
        "jbe .Lf59564_000595ca\n"
        "addl effectClusters, %ebx\n" /* line 132 */
        "addl $1, 0xc(%ebx)\n"
        "jmp .Lf59564_000595ba\n"
    );
}

/* line 1412 */
__attribute__((naked))
void FX_CalcOrigin2(const PrimitiveTemplate *primTemp, vec_t *org, vec_t *org2, const vec_t *origin, vec3_t *ax)
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
        "movss 0x2ed68c, %xmm0\n" /* line 288 | 16384.0f */
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
        "movl 0x195ed4c, %eax\n"
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
        "movl 0x195ed48, %eax\n"
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

/* line 266 */
__attribute__((naked))
Bool FX_GetBoneOrientation(const FxBoltInfo *bolt, orientation_t *orient)
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
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
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
        "movl 0x195ed74, %eax\n" /* line 322 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
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
        "movl 0x195ed58, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %ebx\n" /* end, mtx */
        "movl %ebx, 4(%esp)\n" /* mtx */
        "movl %edx, (%esp)\n"
        "calll CL_AddDebugLine\n"
        "movl 0x195ed74, %esi\n" /* line 328 | obj */
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
        "movl 0x195ed60, %eax\n"
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
        "movl 0x195ed78, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* mtx */
        "movl %edx, (%esp)\n"
        "calll CL_AddDebugLine\n"
        "movl $1, %eax\n"
        "jmp .Lf59998_00059b7d\n"
    );
}

/* line 2153 */
__attribute__((naked))
void FX_AddScheduledEffects(const vec_t *start, const vec_t *end)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2153 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl 0x195ed80, %eax\n" /* line 2166 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf59d14_00059db2\n"
        "movl 0x195ed48, %edx\n" /* line 2172 */
        "movl (%edx), %eax\n"
        "leal 4(%eax), %esi\n" /* prevNext */
        "movl 4(%eax), %ebx\n" /* line 2173 | scheduled */
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
        "movl (%edx), %eax\n"
        "subl $1, 8(%eax)\n"
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
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
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

/* line 636 */
__attribute__((naked))
float FX_GetServerVisibility(const vec_t *start, const vec_t *end)
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
        "movl 0x195ed50, %eax\n" /* line 667 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss -0x4c(%ebp), %xmm0\n" /* len */
        "ja .Lf59e2e_00059e47\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 677 | len */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
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
        "movss 0xffef04(%ebx), %xmm0\n"
        "movl -0x40(%ebp), %eax\n"
        "subss (%eax), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xffef08(%ebx), %xmm0\n"
        "movl -0x3c(%ebp), %eax\n"
        "subss (%eax), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 689 */
        "subss -0x48(%ebp), %xmm0\n" /* halfLen */
        "andps 0x2f03a0, %xmm0\n"
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
        "ucomiss 0xffef0c(%ebx), %xmm0\n"
        "flds -0x68(%ebp)\n"
        "jae .Lf59e2e_00059ecc\n"
        "fstps -0x6c(%ebp)\n" /* line 699 */
        "movss -0x6c(%ebp), %xmm0\n"
        "mulss 0xffef10(%ebx), %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n"
        "flds -0x6c(%ebp)\n"
        "jmp .Lf59e2e_00059ecc\n"
    );
}

/* line 1303 */
static __attribute__((naked))
void FX_CalcOriginAndAxis(vec_t *orgOut, vec3_t *ax)
{
    __asm__ __volatile__ (
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
        "movss 0x2ed5d0, %xmm2\n" /* line 1380 | 1.0f */
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
        "andps 0x2f03b0, %xmm0\n" /* line 1383 */
        "ucomiss 0x2ed690, %xmm0\n" /* 0.9990000128746033f */
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
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
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
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
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
        "movss 0x2ed5d0, %xmm0\n" /* line 1352 | 1.0f, scale */
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
    );
}

/* line 1636 */
static __attribute__((naked))
void FX_InitParticle(EffectPrimitive *prim, Particle *particle, vec_t *newOrigin, const vec_t *origin, vec3_t *ax, int indexInBatch)
{
    __asm__ __volatile__ (
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
    );
}

/* line 1958 */
__attribute__((naked))
void FX_AddCameraShake(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1958 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %ebx\n" /* prim */
        "movl 0x10(%ebp), %ecx\n" /* origin */
        /* { scope 1 */
        "leal -0x14(%ebp), %esi\n" /* line 1965 | newOrigin */
        "movl 0xc(%ebp), %eax\n" /* ax */
        "movl %eax, (%esp)\n"
        "movl %esi, %edx\n"
        "movl %ebx, %eax\n" /* primTemp */
        "calll FX_CalcOriginAndAxis\n"
        "movl 4(%ebx), %ebx\n" /* line 1967 | primTemp */
        "leal 0x58(%ebx), %eax\n" /* line 1974 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x20(%ebp)\n"
        "leal 0xe8(%ebx), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x1c(%ebp)\n"
        "addl $0x280, %ebx\n" /* primTemp */
        "movl %ebx, (%esp)\n" /* primTemp */
        "calll FxRange_GetVal\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "fstps 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CameraShake\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 1975 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1938 */
__attribute__((naked))
void FX_AddFxRunner(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1938 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* prim */
        "movl 0xc(%ebp), %edi\n" /* ax */
        "movl 0x10(%ebp), %ecx\n" /* origin */
        /* { scope 1 */
        "leal -0x24(%ebp), %esi\n" /* line 1945 | newOrigin */
        "movl %edi, (%esp)\n" /* ax */
        "movl %esi, %edx\n"
        "movl %ebx, %eax\n" /* prim */
        "calll FX_CalcOriginAndAxis\n"
        "movl 4(%ebx), %eax\n" /* line 1947 | prim */
        "movl 8(%ebx), %edx\n" /* line 1951 | prim */
        "testl %edx, %edx\n"
        "je .Lf5a7d2_0005a83b\n"
        "movl 8(%ebx), %ebx\n" /* line 1952 | prim */
        "addl $0x3c, %ebx\n" /* prim */
        "addl $0x88, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetEffect\n"
        "movl %ebx, 0x10(%esp)\n" /* prim */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* line 1954 */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1955 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5a7d2_0005a83b:\n"
        "addl $0x88, %eax\n" /* line 1954 */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetEffect\n"
        "movl $0, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* ax */
        "movl %esi, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_PlayEffect\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1955 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1928 */
__attribute__((naked))
void FX_AddDecal(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1928 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* prim */
        "movl 0xc(%ebp), %esi\n" /* ax */
        "movl 0x10(%ebp), %ecx\n" /* origin */
        /* { scope 1 */
        "leal -0x24(%ebp), %ebx\n" /* line 1932 | newOrigin */
        "movl %esi, (%esp)\n" /* ax */
        "movl %ebx, %edx\n"
        "movl %edi, %eax\n" /* prim */
        "calll FX_CalcOriginAndAxis\n"
        "movl %esi, 0xc(%esp)\n" /* line 1934 | ax */
        "movl %ebx, 8(%esp)\n"
        "movl 4(%edi), %eax\n" /* prim */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_CreateDecalEffect\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1935 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1246 */
__attribute__((naked))
void FX_DrawAll(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1246 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x548c, %esp\n"
        /* { scope 1: effectCount */
        "movl 0x195ed54, %eax\n" /* line 1220 */
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
        "movl 0x195ed44, %edx\n" /* line 1162 */
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
        "fstps 0x4ae684(, %ebx, 8)\n"
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
        "movl %edx, 0x4b1ec4(, %ecx, 8)\n"
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
        "movl 0x195ed68, %eax\n" /* line 1266 */
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
        "movl 0x195ed7c, %eax\n" /* line 1275 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5a8bc_0005aa9e\n"
        "movl visibleEffectCountNonBolt, %ecx\n" /* line 1281 */
        "testl %ecx, %ecx\n"
        "jg .Lf5a8bc_0005abf6\n"
        ".Lf5a8bc_0005aa9e:\n"
        "movl 0x195ed6c, %eax\n" /* line 1293 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5a8bc_0005aaef\n"
        "movl effectActiveCount, %eax\n" /* line 1295 */
        "movl %eax, 4(%esp)\n"
        "movl $0x219d0c, (%esp)\n" /* "Active    FX: %i
" */
        "calll FX_Print\n"
        "movl visibleEffectCountNonBolt, %eax\n" /* line 1296 */
        "movl %eax, 4(%esp)\n"
        "movl $0x219d20, (%esp)\n" /* "Drawn     FX: %i
" */
        "calll FX_Print\n"
        "movl 0x195ed48, %eax\n" /* line 1297 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x219d34, (%esp)\n" /* "Scheduled FX: %i
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
        "movl 0x195ed44, %edx\n" /* line 1230 */
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
        "fstps 0x4b1ec4(, %ebx, 8)\n"
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

/* line 1557 */
static __attribute__((naked))
void FX_SetMaterialAndSequenceParams(const int killTime, int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1557 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %esi\n" /* primTemp */
        "movl %edx, %ebx\n" /* particle */
        "movl %ecx, -0x20(%ebp)\n"
        /* { scope 1 */
        "leal 0x68(%eax), %eax\n" /* line 1568 */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_GetHandle\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 1570 */
        "je .Lf5ac64_0005ad35\n"
        "movl %eax, 4(%esp)\n" /* line 1577 */
        "movl theFxHelper, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetMaterialSubimageCount\n"
        "movl %eax, -0x1c(%ebp)\n" /* subimageCount */
        "cmpl $1, %eax\n" /* line 1580 */
        "je .Lf5ac64_0005ad5b\n"
        "movl 0x288(%esi), %edx\n" /* line 1589 | primTemp */
        "testl %edx, %edx\n"
        "jne .Lf5ac64_0005ad48\n"
        "movl 0x28c(%esi), %eax\n" /* line 1591 | primTemp */
        "subl $1, %eax\n"
        ".Lf5ac64_0005acbd:\n"
        "movl 0x290(%esi), %edx\n" /* line 1607 | primTemp */
        "testl %edx, %edx\n"
        "jne .Lf5ac64_0005ad3d\n"
        "movss 0x294(%esi), %xmm1\n" /* line 1609 | primTemp */
        "divss 0x2ed5c8, %xmm1\n" /* 1000.0f */
        ".Lf5ac64_0005acd7:\n"
        "movl %eax, 0x108(%ebx)\n" /* line 386 */
        "movss %xmm1, 0x10c(%ebx)\n" /* line 387 */
        "movl 0x298(%esi), %eax\n" /* line 388 */
        "movl %eax, 0x110(%ebx)\n"
        "movl 0x29c(%esi), %eax\n" /* line 389 */
        "movl %eax, 0x114(%ebx)\n"
        "movl %edi, 0x40(%ebx)\n" /* line 381 */
        "movl $0, 0xb0(%ebx)\n" /* line 1551 */
        "testl %edi, %edi\n" /* line 1552 */
        "je .Lf5ac64_0005ad2d\n"
        "movl %edi, 4(%esp)\n"
        "movl theFxHelper, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_IsMaterialRefractive\n"
        "testb %al, %al\n"
        "je .Lf5ac64_0005ad2d\n"
        "movl $0xffffffff, 0xb0(%ebx)\n" /* line 1553 */
        /* } scope */
        ".Lf5ac64_0005ad2d:\n"
        "addl $0x2c, %esp\n" /* line 1633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5ac64_0005ad35:\n"
        "xorl %eax, %eax\n" /* line 1570 */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf5ac64_0005acd7\n"
        ".Lf5ac64_0005ad3d:\n"
        "subl $1, %edx\n" /* line 1611 */
        "je .Lf5ac64_0005ad66\n"
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf5ac64_0005acd7\n"
        ".Lf5ac64_0005ad48:\n"
        "cmpl $1, %edx\n" /* line 1593 */
        "je .Lf5ac64_0005ad79\n"
        "xorl %eax, %eax\n" /* line 1597 */
        "cmpl $2, %edx\n"
        "cmovel 8(%ebp), %eax\n" /* indexInBatch */
        "jmp .Lf5ac64_0005acbd\n"
        ".Lf5ac64_0005ad5b:\n"
        "xorb %al, %al\n" /* line 1580 */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf5ac64_0005acd7\n"
        ".Lf5ac64_0005ad66:\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm1\n" /* line 1613 | subimageCount */
        "cvtsi2ssl -0x20(%ebp), %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "jmp .Lf5ac64_0005acd7\n"
        ".Lf5ac64_0005ad79:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1595 | subimageCount */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll irand\n"
        "jmp .Lf5ac64_0005acbd\n"
    );
}

/* line 1485 */
static __attribute__((naked))
Bool FX_AddPrimitive(EffectPrimitive *prim, const vec_t *origin)
{
    __asm__ __volatile__ (
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
        "movss 0x2ed688, %xmm0\n" /* line 130 | 131072.0f */
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
        "movl 0x195ed14, %eax\n" /* line 444 */
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
        "movl $0x219d48, 8(%esp)\n" /* line 445 */
        "movl $0xbb8, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll StatMon_Warning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5ad92_0005af38\n"
    );
}

/* line 2102 */
__attribute__((naked))
void FX_AddCloud(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2102 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %esi\n" /* prim */
        /* { scope 1: velSum */
        /* { scope 2 */
        "movl $0x27c, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5b06e_0005b0a3\n"
        "movl $0x27c, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5b06e_0005b0a3:\n"
        "movl %ebx, (%esp)\n" /* line 2111 | ptr */
        "calll Cloud_Cloud\n"
        "testl %ebx, %ebx\n" /* line 2112 | ptr */
        "je .Lf5b06e_0005b1a8\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2115 | origin */
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* primTemp */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 2116 */
        "je .Lf5b06e_0005b1af\n"
        "leal -0x14(%ebp), %ecx\n" /* line 2122 | newOrigin */
        "movl 0x18(%ebp), %eax\n" /* indexInBatch */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* ax */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* origin */
        "movl %eax, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* primTemp */
        "calll FX_InitParticle\n"
        "movl 4(%esi), %esi\n" /* line 2124 | primTemp */
        "movl 0xbc(%ebx), %ecx\n" /* line 2128 | ptr */
        "subl 0xb8(%ebx), %ecx\n" /* ptr */
        "movl 0x18(%ebp), %eax\n" /* indexInBatch */
        "movl %eax, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* primTemp */
        "calll FX_SetMaterialAndSequenceParams\n"
        /* { scope 2 */
        "movl 0x14(%ebp), %eax\n" /* line 1472 | lateTime */
        "testl %eax, %eax\n"
        "jle .Lf5b06e_0005b16c\n"
        "cvtsi2ssl 0x14(%ebp), %xmm1\n" /* line 1474 | lateTime */
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        "leal -0x20(%ebp), %eax\n" /* line 1476 | velSum */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* lateTime */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "movss %xmm1, -0x38(%ebp)\n"
        "calll Particle_IntegrateTotalVelocity\n"
        /* { scope 3 */
        "movss -0x38(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n" /* velSum */
        "addss -0x14(%ebp), %xmm0\n" /* newOrigin */
        "movss %xmm0, -0x14(%ebp)\n" /* newOrigin */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "mulss -0x18(%ebp), %xmm1\n" /* line 290 */
        "addss -0xc(%ebp), %xmm1\n"
        "movss %xmm1, -0xc(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf5b06e_0005b16c:\n"
        "leal 4(%ebx), %edx\n" /* line 208 | ptr, to */
        /* { scope 2 */
        "movl -0x14(%ebp), %eax\n" /* line 199 | newOrigin */
        "movl %eax, 4(%ebx)\n" /* ptr */
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $0x3f800000, 4(%esp)\n" /* line 2132 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "fstps 0x260(%ebx)\n" /* ptr */
        "movzbl 0x9d(%esi), %eax\n" /* line 2133 | primTemp */
        "movb %al, 0x25c(%ebx)\n" /* ptr */
        /* } scope */
        ".Lf5b06e_0005b1a8:\n"
        "addl $0x40, %esp\n" /* line 2134 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: velSum */
        ".Lf5b06e_0005b1af:\n"
        "movl (%ebx), %eax\n" /* line 2118 | ptr */
        "movl %ebx, (%esp)\n" /* ptr */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 2134 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %esi\n" /* primTemp */
        /* { scope 1: velSum */
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5b06e_0005b1cc\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5b06e_0005b1cc:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 2063 */
__attribute__((naked))
void FX_AddFlash(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
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
        "movl 0x195ed70, %eax\n"
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

/* line 1978 */
__attribute__((naked))
void FX_AddLight(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1978 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* prim */
        /* { scope 1 */
        /* { scope 2 */
        "movl $0xfc, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5b306_0005b33b\n"
        "movl $0xfc, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5b306_0005b33b:\n"
        "movl %ebx, (%esp)\n" /* line 1987 | ptr */
        "calll Light_Light\n"
        "testl %ebx, %ebx\n" /* line 1988 | ptr */
        "je .Lf5b306_0005b392\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1991 | origin */
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* primTemp */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 1992 */
        "je .Lf5b306_0005b399\n"
        "leal -0x14(%ebp), %edx\n" /* line 1998 | newOrigin */
        "movl 0xc(%ebp), %eax\n" /* ax */
        "movl %eax, (%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* origin */
        "movl %esi, %eax\n" /* primTemp */
        "calll FX_CalcOriginAndAxis\n"
        "leal 4(%ebx), %edx\n" /* line 208 | ptr, to */
        /* { scope 2 */
        "movl -0x14(%ebp), %eax\n" /* line 199 | newOrigin */
        "movl %eax, 4(%ebx)\n" /* ptr */
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 4(%esi), %esi\n" /* line 2002 | primTemp */
        "movl 0x90(%esi), %eax\n" /* line 2006 | primTemp */
        "testb $0x20, %ah\n"
        "jne .Lf5b306_0005b3c9\n"
        ".Lf5b306_0005b38d:\n"
        "testw %ax, %ax\n" /* line 2008 */
        "js .Lf5b306_0005b3a8\n"
        /* } scope */
        ".Lf5b306_0005b392:\n"
        "addl $0x20, %esp\n" /* line 2010 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5b306_0005b399:\n"
        "movl (%ebx), %eax\n" /* line 1994 | ptr */
        "movl %ebx, (%esp)\n" /* ptr */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 2010 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5b306_0005b3a8:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 2009 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "fstps 0xc8(%ebx)\n" /* line 262 | ptr */
        /* } scope */
        /* } scope */
        "addl $0x20, %esp\n" /* line 2010 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5b306_0005b3c9:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 2007 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        /* { scope 2 */
        "fstps 0xc4(%ebx)\n" /* line 261 | ptr */
        "movl 0x90(%esi), %eax\n"
        "jmp .Lf5b306_0005b38d\n"
        "movl %eax, %esi\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5b306_0005b3f9\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5b306_0005b3f9:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 1802 */
__attribute__((naked))
void FX_AddCylinder(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
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

/* line 1701 */
__attribute__((naked))
void FX_AddLine(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
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

/* line 1674 */
__attribute__((naked))
void FX_AddParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1674 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %esi\n" /* prim */
        /* { scope 1: velSum */
        /* { scope 2 */
        "movl $0x24c, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf5b7f6_0005b82b\n"
        "movl $0x24c, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf5b7f6_0005b82b:\n"
        "movl %ebx, (%esp)\n" /* line 1682 | ptr */
        "calll Particle_Particle\n"
        "testl %ebx, %ebx\n" /* line 1683 | ptr */
        "je .Lf5b7f6_0005b907\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1686 | origin */
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* prim */
        "calll FX_AddPrimitive\n"
        "testb %al, %al\n" /* line 1687 */
        "je .Lf5b7f6_0005b90e\n"
        "leal -0x14(%ebp), %ecx\n" /* line 1693 | newOrigin */
        "movl 0x18(%ebp), %eax\n" /* indexInBatch */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* ax */
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* origin */
        "movl %eax, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "movl %esi, %eax\n" /* prim */
        "calll FX_InitParticle\n"
        "movl 0xbc(%ebx), %ecx\n" /* line 1694 | ptr */
        "subl 0xb8(%ebx), %ecx\n" /* ptr */
        "movl 4(%esi), %eax\n" /* prim */
        "movl 0x18(%ebp), %edx\n" /* indexInBatch */
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* ptr */
        "calll FX_SetMaterialAndSequenceParams\n"
        /* { scope 2 */
        "movl 0x14(%ebp), %esi\n" /* line 1472 | lateTime */
        "testl %esi, %esi\n"
        "jle .Lf5b7f6_0005b8f2\n"
        "cvtsi2ssl 0x14(%ebp), %xmm1\n" /* line 1474 | lateTime */
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        "leal -0x20(%ebp), %eax\n" /* line 1476 | velSum */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* lateTime */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "movss %xmm1, -0x38(%ebp)\n"
        "calll Particle_IntegrateTotalVelocity\n"
        /* { scope 3 */
        "movss -0x38(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n" /* velSum */
        "addss -0x14(%ebp), %xmm0\n" /* newOrigin */
        "movss %xmm0, -0x14(%ebp)\n" /* newOrigin */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "mulss -0x18(%ebp), %xmm1\n" /* line 290 */
        "addss -0xc(%ebp), %xmm1\n"
        "movss %xmm1, -0xc(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf5b7f6_0005b8f2:\n"
        "leal 4(%ebx), %edx\n" /* line 208 | ptr, to */
        /* { scope 2 */
        "movl -0x14(%ebp), %eax\n" /* line 199 | newOrigin */
        "movl %eax, 4(%ebx)\n" /* ptr */
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        /* } scope */
        ".Lf5b7f6_0005b907:\n"
        "addl $0x40, %esp\n" /* line 1698 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: velSum */
        ".Lf5b7f6_0005b90e:\n"
        "movl (%ebx), %eax\n" /* line 1689 | ptr */
        "movl %ebx, (%esp)\n" /* ptr */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 1698 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %esi\n" /* prim */
        /* { scope 1: velSum */
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf5b7f6_0005b92b\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        ".Lf5b7f6_0005b92b:\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 1768 */
__attribute__((naked))
void FX_AddTail(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
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
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
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

/* line 1847 */
__attribute__((naked))
void FX_AddEmitter(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
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
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
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

/* line 2013 */
__attribute__((naked))
void FX_AddOrientedParticle(EffectPrimitive *prim, vec3_t *ax, const vec_t *origin, const int lateTime, const int indexInBatch)
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
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
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

/* line 2234 */
__attribute__((naked))
void FX_UpdateScheduledEffectsNonBolt(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2234 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x195ed80, %eax\n" /* line 2237 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5c012_0005c165\n"
        "movl $0, cullEffectCountNonBolt\n" /* line 2241 */
        "movl $0, visibleEffectCountNonBolt\n" /* line 2242 */
        /* { scope 1 */
        "movl privateEffectActiveCountNonBolt, %ecx\n" /* line 1184 */
        "movl %ecx, initialEffectActiveCountNonBolt\n"
        "xorl %edi, %edi\n" /* index0 */
        ".Lf5c012_0005c04e:\n"
        "movl %ecx, %edx\n" /* line 1187 */
        "cmpl %ecx, %edi\n" /* index0 */
        "jge .Lf5c012_0005c0d0\n"
        ".Lf5c012_0005c054:\n"
        "leal (, %edi, 4), %ebx\n" /* line 1189 | effect */
        "movl effectListNonBolt, %eax\n"
        "movl (%ebx, %eax), %edx\n" /* effect */
        "movl theFxHelper, %eax\n" /* line 1191 */
        "movl 4(%eax), %eax\n"
        "cmpl 0xbc(%edx), %eax\n"
        "jle .Lf5c012_0005c16d\n"
        /* { scope 2 */
        "andl $0xfffffbff, 0xa8(%edx)\n" /* line 201 */
        /* } scope */
        ".Lf5c012_0005c081:\n"
        "movl effectListNonBolt, %eax\n" /* line 432 */
        "leal (%ebx, %eax), %edx\n"
        "movl (%edx), %ebx\n"
        "movl privateEffectActiveCountNonBolt, %ecx\n" /* line 435 */
        "subl $1, %ecx\n"
        "movl %ecx, privateEffectActiveCountNonBolt\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl (%edx), %esi\n" /* line 394 | swapCache */
        "shll $2, %ecx\n" /* line 395 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl effectListNonBolt, %eax\n" /* line 396 */
        "movl %esi, (%ecx, %eax)\n" /* swapCache */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 403 */
        "movl %ebx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb $0x10, 0xa9(%ebx)\n" /* line 404 */
        "je .Lf5c012_0005c0c4\n"
        "subl $1, effectBlockSightCount\n" /* line 409 */
        ".Lf5c012_0005c0c4:\n"
        "movl privateEffectActiveCountNonBolt, %ecx\n"
        /* } scope */
        "movl %ecx, %edx\n" /* line 1187 */
        "cmpl %ecx, %edi\n" /* index0 */
        "jl .Lf5c012_0005c054\n"
        /* } scope */
        ".Lf5c012_0005c0d0:\n"
        "movl 0x195ed54, %eax\n" /* line 1220 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf5c012_0005c165\n"
        "movl cullEffectCountNonBolt, %edi\n" /* line 1224 | index0 */
        "cmpl %ecx, %edi\n" /* index0 */
        "jge .Lf5c012_0005c15f\n"
        "leal (, %edi, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf5c012_0005c0fa\n"
        ".Lf5c012_0005c0f7:\n"
        "movl -0x1c(%ebp), %edx\n"
        ".Lf5c012_0005c0fa:\n"
        "movl effectListNonBolt, %eax\n" /* line 1226 */
        "movl (%eax, %edx), %esi\n" /* swapCache */
        "movl 0x195ed44, %edx\n" /* line 1230 */
        "movl (%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5c012_0005c11c\n"
        "movl (%esi), %eax\n" /* line 1233 | swapCache */
        "movl %esi, (%esp)\n" /* swapCache */
        "calll *0x10(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf5c012_0005c14e\n"
        ".Lf5c012_0005c11c:\n"
        "movl visibleEffectCountNonBolt, %ebx\n" /* line 1237 | effect */
        "movl %esi, visibleEffectsNonBolt(, %ebx, 8)\n" /* swapCache */
        "movl theFxHelper, %eax\n" /* line 1238 */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x7c(%esi), %eax\n" /* swapCache */
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps 0x4b1ec4(, %ebx, 8)\n"
        "addl $1, visibleEffectCountNonBolt\n" /* line 1239 */
        ".Lf5c012_0005c14e:\n"
        "addl $1, %edi\n" /* line 1224 | index0 */
        "movl privateEffectActiveCountNonBolt, %edx\n"
        "addl $4, -0x1c(%ebp)\n"
        "cmpl %edx, %edi\n" /* index0 */
        "jl .Lf5c012_0005c0f7\n"
        ".Lf5c012_0005c15f:\n"
        "movl %edx, cullEffectCountNonBolt\n" /* line 1242 */
        ".Lf5c012_0005c165:\n"
        "addl $0x2c, %esp\n" /* line 2249 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5c012_0005c16d:\n"
        "movl (%edx), %eax\n" /* line 1201 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n" /* line 1203 */
        "je .Lf5c012_0005c081\n"
        "addl $1, %edi\n" /* line 1209 | index0 */
        "movl privateEffectActiveCountNonBolt, %ecx\n"
        "jmp .Lf5c012_0005c04e\n"
    );
}

/* line 2252 */
__attribute__((naked))
void FX_UpdateScheduledEffectsBolt(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2252 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x195ed80, %eax\n" /* line 2255 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5c18c_0005c2ce\n"
        "movl $0, cullEffectCountBolt\n" /* line 2259 */
        "movl $0, visibleEffectCountBolt\n" /* line 2260 */
        /* { scope 1 */
        "movl privateEffectActiveCountBolt, %ecx\n" /* line 1117 */
        "movl %ecx, initialEffectActiveCountBolt\n"
        "xorl %edi, %edi\n" /* index0 */
        ".Lf5c18c_0005c1c8:\n"
        "movl %ecx, %eax\n" /* line 1120 */
        "cmpl %ecx, %edi\n" /* index0 */
        "jge .Lf5c18c_0005c24a\n"
        ".Lf5c18c_0005c1ce:\n"
        "leal (, %edi, 4), %ebx\n" /* line 1122 | effect */
        "movl effectListBolt, %eax\n"
        "movl (%ebx, %eax), %edx\n" /* effect */
        "movl theFxHelper, %eax\n" /* line 1124 */
        "movl 4(%eax), %eax\n"
        "cmpl 0xbc(%edx), %eax\n"
        "jle .Lf5c18c_0005c2d6\n"
        /* { scope 2 */
        "andl $0xfffffbff, 0xa8(%edx)\n" /* line 201 */
        /* } scope */
        ".Lf5c18c_0005c1fb:\n"
        "movl effectListBolt, %eax\n" /* line 419 */
        "leal (%ebx, %eax), %edx\n"
        "movl (%edx), %ebx\n"
        "movl privateEffectActiveCountBolt, %ecx\n" /* line 422 */
        "subl $1, %ecx\n"
        "movl %ecx, privateEffectActiveCountBolt\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl (%edx), %esi\n" /* line 384 | swapCache */
        "shll $2, %ecx\n" /* line 385 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl effectListBolt, %eax\n" /* line 386 */
        "movl %esi, (%ecx, %eax)\n" /* swapCache */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 403 */
        "movl %ebx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb $0x10, 0xa9(%ebx)\n" /* line 404 */
        "je .Lf5c18c_0005c23e\n"
        "subl $1, effectBlockSightCount\n" /* line 409 */
        ".Lf5c18c_0005c23e:\n"
        "movl privateEffectActiveCountBolt, %ecx\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 1120 */
        "cmpl %ecx, %edi\n" /* index0 */
        "jl .Lf5c18c_0005c1ce\n"
        /* } scope */
        ".Lf5c18c_0005c24a:\n"
        "movl cullEffectCountBolt, %edi\n" /* line 1156 | index0 */
        "cmpl %ecx, %edi\n" /* index0 */
        "jge .Lf5c18c_0005c2c9\n"
        "leal (, %edi, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf5c18c_0005c265\n"
        ".Lf5c18c_0005c262:\n"
        "movl -0x1c(%ebp), %edx\n"
        ".Lf5c18c_0005c265:\n"
        "movl effectListBolt, %eax\n" /* line 1158 */
        "movl (%eax, %edx), %esi\n" /* swapCache */
        "movl 0x195ed44, %edx\n" /* line 1162 */
        "movl (%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf5c18c_0005c287\n"
        "movl (%esi), %eax\n" /* line 1165 | swapCache */
        "movl %esi, (%esp)\n" /* swapCache */
        "calll *0x10(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf5c18c_0005c2b9\n"
        ".Lf5c18c_0005c287:\n"
        "movl visibleEffectCountBolt, %ebx\n" /* line 1169 | effect */
        "movl %esi, visibleEffectsBolt(, %ebx, 8)\n" /* swapCache */
        "movl theFxHelper, %eax\n" /* line 1170 */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x7c(%esi), %eax\n" /* swapCache */
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps 0x4ae684(, %ebx, 8)\n"
        "addl $1, visibleEffectCountBolt\n" /* line 1171 */
        ".Lf5c18c_0005c2b9:\n"
        "addl $1, %edi\n" /* line 1156 | index0 */
        "movl privateEffectActiveCountBolt, %eax\n"
        "addl $4, -0x1c(%ebp)\n"
        "cmpl %eax, %edi\n" /* index0 */
        "jl .Lf5c18c_0005c262\n"
        ".Lf5c18c_0005c2c9:\n"
        "movl %eax, cullEffectCountBolt\n" /* line 1174 */
        ".Lf5c18c_0005c2ce:\n"
        "addl $0x2c, %esp\n" /* line 2267 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5c18c_0005c2d6:\n"
        "movl (%edx), %eax\n" /* line 1134 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n" /* line 1136 */
        "je .Lf5c18c_0005c1fb\n"
        "addl $1, %edi\n" /* line 1142 | index0 */
        "movl privateEffectActiveCountBolt, %ecx\n"
        "jmp .Lf5c18c_0005c1c8\n"
    );
}

/* line 1034 */
__attribute__((naked))
void FX_UpdateAllBolt(void)
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

/* line 759 */
__attribute__((naked))
void FX_Rewind(int time)
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
        "movl $0, 8(%esp)\n" /* line 808 */
        "movl $0, 4(%esp)\n"
        "movl 0x195ed48, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_Clean\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 809 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1072 */
__attribute__((naked))
void FX_UpdateAllNonBolt(void)
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

/* line 2270 */
__attribute__((naked))
void FX_DrawScheduledEffects(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2270 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x195ed80, %eax\n" /* line 2275 */
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

/* line 874 */
__attribute__((naked))
int FX_Restore(MemoryFile *memFile)
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
        "movl 0x195ed48, %ebx\n" /* line 244 | ptr */
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
        "jmpl *0x2f03c0(, %eax, 4)\n"
        /* { scope 2 */
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
        "movl 0x195ed70, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%ebx)\n" /* ptr */
        "jmp .Lf5d1b8_0005d31d\n"
        /* { scope 2 */
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
    );
}

/* line 348 */
__attribute__((naked))
int FX_Init(int rendererExists)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 348 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movzbl 8(%ebp), %esi\n" /* rendererExists */
        "movl fxInitialized, %eax\n" /* line 352 */
        "testl %eax, %eax\n"
        "jne .Lf5d5e2_0005d633\n"
        "movl $1, fxInitialized\n" /* line 354 */
        "movl $0, effectActiveCountBolt\n" /* line 355 */
        "movl $0, effectActiveCountNonBolt\n" /* line 356 */
        "movl $0, effectActiveCount\n" /* line 357 */
        "movl $0, effectBlockSightCount\n" /* line 358 */
        "movl $0, effectClusterCount\n" /* line 359 */
        ".Lf5d5e2_0005d633:\n"
        "movl effectActiveCountBolt, %ebx\n" /* line 227 */
        "testl %ebx, %ebx\n"
        "jle .Lf5d5e2_0005d65e\n"
        "xorl %ebx, %ebx\n"
        ".Lf5d5e2_0005d63f:\n"
        "movl effectListBolt, %eax\n" /* line 228 */
        "movl (%eax, %ebx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf5d5e2_0005d653\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf5d5e2_0005d653:\n"
        "addl $1, %ebx\n" /* line 227 */
        "cmpl effectActiveCountBolt, %ebx\n"
        "jl .Lf5d5e2_0005d63f\n"
        ".Lf5d5e2_0005d65e:\n"
        "movl effectActiveCountNonBolt, %ecx\n" /* line 229 */
        "testl %ecx, %ecx\n"
        "jle .Lf5d5e2_0005d689\n"
        "xorl %ebx, %ebx\n"
        ".Lf5d5e2_0005d66a:\n"
        "movl effectListNonBolt, %eax\n" /* line 230 */
        "movl (%eax, %ebx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf5d5e2_0005d67e\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf5d5e2_0005d67e:\n"
        "addl $1, %ebx\n" /* line 229 */
        "cmpl effectActiveCountNonBolt, %ebx\n"
        "jl .Lf5d5e2_0005d66a\n"
        ".Lf5d5e2_0005d689:\n"
        "movl $0, effectActiveCountBolt\n" /* line 232 */
        "movl $0, effectActiveCountNonBolt\n" /* line 233 */
        "movl $0, effectActiveCount\n" /* line 234 */
        "movl $0, effectBlockSightCount\n" /* line 235 */
        "movl $0, effectClusterCount\n" /* line 236 */
        "movl 0x195ed48, %ebx\n" /* line 244 */
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf5d5e2_0005d6fa\n"
        "movl $0, 8(%esp)\n" /* line 247 */
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FxScheduler_Clean\n"
        "movl (%ebx), %eax\n" /* line 91 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $0, (%ebx)\n" /* line 252 */
        "movl 0x195ed64, %eax\n" /* line 253 */
        "movl $0, (%eax)\n"
        ".Lf5d5e2_0005d6fa:\n"
        "movl 0x195ed5c, %eax\n" /* line 364 */
        "movl %esi, %edx\n" /* rendererExists */
        "movb %dl, (%eax)\n"
        "movl $0xc, (%esp)\n" /* line 89 */
        "calll Z_MallocInternal\n"
        "movl %eax, %esi\n"
        "movl %eax, (%esp)\n" /* line 367 */
        "calll FxScheduler_FxScheduler\n"
        "movl 0x195ed48, %ebx\n"
        "movl %esi, (%ebx)\n" /* rendererExists */
        "calll FX_InitTemplates\n" /* line 369 */
        "movl (%ebx), %edx\n" /* line 371 */
        "movl 0x195ed64, %eax\n"
        "movl %edx, (%eax)\n"
        "movl theFxHelper, %eax\n" /* line 374 */
        "movl %eax, (%esp)\n"
        "calll FxHelper_Init\n"
        "movl $1, %eax\n" /* line 377 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 91 */
        "calll Z_FreeInternal\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 240 */
__attribute__((naked))
void FX_Free(int bRemoveTemplates)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 240 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movzbl 8(%ebp), %esi\n" /* bRemoveTemplates */
        "movl effectActiveCountBolt, %eax\n" /* line 227 */
        "testl %eax, %eax\n"
        "jle .Lf5d75a_0005d790\n"
        "xorl %ebx, %ebx\n"
        ".Lf5d75a_0005d771:\n"
        "movl effectListBolt, %eax\n" /* line 228 */
        "movl (%eax, %ebx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf5d75a_0005d785\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf5d75a_0005d785:\n"
        "addl $1, %ebx\n" /* line 227 */
        "cmpl effectActiveCountBolt, %ebx\n"
        "jl .Lf5d75a_0005d771\n"
        ".Lf5d75a_0005d790:\n"
        "movl effectActiveCountNonBolt, %eax\n" /* line 229 */
        "testl %eax, %eax\n"
        "jle .Lf5d75a_0005d7ba\n"
        "xorl %ebx, %ebx\n"
        ".Lf5d75a_0005d79b:\n"
        "movl effectListNonBolt, %eax\n" /* line 230 */
        "movl (%eax, %ebx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf5d75a_0005d7af\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf5d75a_0005d7af:\n"
        "addl $1, %ebx\n" /* line 229 */
        "cmpl effectActiveCountNonBolt, %ebx\n"
        "jl .Lf5d75a_0005d79b\n"
        ".Lf5d75a_0005d7ba:\n"
        "movl $0, effectActiveCountBolt\n" /* line 232 */
        "movl $0, effectActiveCountNonBolt\n" /* line 233 */
        "movl $0, effectActiveCount\n" /* line 234 */
        "movl $0, effectBlockSightCount\n" /* line 235 */
        "movl $0, effectClusterCount\n" /* line 236 */
        "movl 0x195ed48, %ebx\n" /* line 244 */
        "movl (%ebx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf5d75a_0005d817\n"
        "movl $0, 8(%esp)\n" /* line 247 */
        "movl %esi, %ecx\n" /* bRemoveTemplates */
        "movzbl %cl, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FxScheduler_Clean\n"
        "movl %esi, %eax\n" /* line 248 | bRemoveTemplates */
        "testb %al, %al\n"
        "jne .Lf5d75a_0005d81e\n"
        ".Lf5d75a_0005d817:\n"
        "addl $0x10, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf5d75a_0005d81e:\n"
        "movl (%ebx), %eax\n" /* line 91 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $0, (%ebx)\n" /* line 252 */
        "movl 0x195ed64, %eax\n" /* line 253 */
        "movl $0, (%eax)\n"
        "addl $0x10, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

