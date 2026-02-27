/* ASM dump from: r_model.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_model.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_local.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 */

static int warnCount; /* 0xc85b00 */
static int warnCount_00c85b04; /* 0xc85b04 */
static int warnCount_00c85b04; /* 0xc85b04 */
static int warnCount_00c85b04; /* 0xc85b04 */
static int warnCount_00c85b08; /* 0xc85b08 */
static int warnCount_00c85b08; /* 0xc85b08 */
static int warnCount_00c85b08; /* 0xc85b08 */
static int warnCount_00c85b0c; /* 0xc85b0c */
static int warnCount_00c85b0c; /* 0xc85b0c */
static int warnCount_00c85b0c; /* 0xc85b0c */
static int warnCount_00c85b10; /* 0xc85b10 */
static int warnCount_00c85b10; /* 0xc85b10 */
static int warnCount_00c85b10; /* 0xc85b10 */
extern void * Hunk_AllocInternal(int size);
extern void DB_EnumXAssets(int type, void (*func)(XAssetHeader, void *), void *data, qboolean overrides);
static const int boxVerts[24][3]; /* 0x2f24c0 */

static void * Hunk_AllocXModelPrecache(int size);
static void * Hunk_AllocXModelPrecacheColl(int size);
struct XModel * R_RegisterModel(const char *name);
GfxBrushModel * R_RegisterInlineModel(int modelIndex);
void R_SetIgnorePrecacheErrors(qboolean ignore);
qboolean R_GetIgnorePrecacheErrors(void);
void R_UnlockSkinnedCache(void);
struct DObj_s * R_GetGfxEntityDObj(GfxSceneEntity *sceneEnt, GfxEntity *ent);
void R_DObjReplaceMaterial(struct DObj_s *obj, int lod, int surfaceIndex, MaterialHandle material);
static void R_ReleaseModel(union XAssetHeader header, void *data);
void R_OptimizeAllModels(void);
void R_ReleaseAllModels(void);
void * Model_Alloc(int size);
static void R_OptimizeModel(XAssetHeader header, void *data);
void R_GetRigidTransform(const DObjSkelMat *bone, const vec_t *origin, vec3_t *axis, float scale, vec3_t *boneAxis);
void R_ModelBounds(GfxBrushModel *bmodel, vec_t *mins, vec_t *maxs);
void R_LockSkinnedCache(GfxLockType lockType);
void R_ShutdownModels(void);
void R_FinishLoadingModels(void);
void R_DObjGetSurfMaterials(struct DObj_s *obj, int lod, MaterialHandle *matHandleArray);
static int R_GetSurfaceData(long unsigned int (*surfaces)[32], int *partBits, char *lods);
static void R_XModelDebugBoxes(void);
static void R_XModelDebugAxes(void);
void R_UpdateXModelBounds(GfxSceneEntity *sceneEnt, GfxEntity *ent);
static int R_PreSkinXSurface(GfxSceneEntity *sceneEnt, const struct DObj_s *obj, long unsigned int (*surface)[32], int surfaceIndex, char *lods, byte *surfPos);
void R_SkinSceneDObj(GfxSceneEntity *sceneEnt, GfxEntity *ent);
static int R_PreSkinStaticSurface(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex, const struct XModel *model, XSurface *xsurf, int surfaceIndex, int lod, qboolean *needSkinningSurf, byte *surfPos);
static void R_SkinXModel(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex);
void R_SkinStaticModel(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex);
void R_SkinSceneEnt(GfxSceneEntity *sceneEnt, GfxEntity *ent);
static void R_SkinXSurfaceSkinned(const DObjSkelMat *boneMatrix);
void R_SkinXModelCmd(SkinXModelCmd *skinCmd, int context);
void R_SkinRigidXModelCmd(SkinRigidXModelCmd *skinRigidCmd);

/* line 75 */
static void * Hunk_AllocXModelPrecache(int size)
{
    return Hunk_AllocInternal(size);
}

/* line 81 */
static void * Hunk_AllocXModelPrecacheColl(int size)
{
    return Hunk_AllocInternal(size);
}

/* line 188 */
__attribute__((naked))
struct XModel * R_RegisterModel(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 188 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        "movl %ebx, (%esp)\n" /* line 190 | name */
        "calll R_ValidXModelName\n"
        "testb %al, %al\n"
        "je .Lfd0080_000d00b7\n"
        "movl $Hunk_AllocXModelPrecacheColl, 8(%esp)\n" /* line 196 */
        "movl $Hunk_AllocXModelPrecache, 4(%esp)\n"
        "leal 7(%ebx), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll XModelPrecache\n"
        "addl $0x14, %esp\n" /* line 197 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd0080_000d00b7:\n"
        "movl %ebx, 8(%esp)\n" /* line 192 | name */
        "movl $0x223f34, 4(%esp)\n" /* "R_RegisterModel: Invalid model name '%s'
" */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "xorl %eax, %eax\n"
        "addl $0x14, %esp\n" /* line 197 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 200 */
GfxBrushModel * R_RegisterInlineModel(int modelIndex)
{
    int *world = *(int **)(*(int *)0x195eebc + 0x109c);
    return (GfxBrushModel *)(*(int *)((byte *)world + 0x138) + modelIndex * 32);
}

/* line 218 */
void R_SetIgnorePrecacheErrors(qboolean ignore)
{
    *(byte *)(*(int *)0x195eec8 + 2) = (ignore != 0);
}

/* line 224 */
qboolean R_GetIgnorePrecacheErrors(void)
{
    return *(byte *)(*(int *)0x195eec8 + 2) != 0;
}

/* line 587 */
__attribute__((naked))
void R_UnlockSkinnedCache(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 587 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 0x195eed0, %eax\n" /* line 591 */
        "movl 0x2dc0(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfd0120_000d0165\n"
        "movl $0, 0x2dc0(%eax)\n" /* line 593 */
        "movl 0x195eef4, %eax\n" /* line 1005 */
        "movl (%eax), %eax\n"
        "movl 0x217c78(%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* vb */
        "movl 0x195f0e0, %esi\n"
        ".Lfd0120_000d0157:\n"
        "movl (%ebx), %eax\n" /* line 599 | vb */
        "movl %ebx, (%esp)\n" /* vb */
        "calll *0x30(%eax)\n"
        "movl (%esi), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfd0120_000d0157\n"
        /* } scope */
        ".Lfd0120_000d0165:\n"
        "addl $0x10, %esp\n" /* line 602 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2246 */
__attribute__((naked))
struct DObj_s * R_GetGfxEntityDObj(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2246 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* sceneEnt */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 2252 | ent */
        "movl (%eax), %ebx\n" /* obj */
        "testl %ebx, %ebx\n" /* obj */
        "jne .Lfd016c_000d018a\n"
        "movl 4(%edx), %ebx\n" /* line 2253 | obj */
        /* } scope */
        "movl %ebx, %eax\n" /* line 2261 | obj */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd016c_000d018a:\n"
        "movl 0x195eec8, %eax\n" /* line 2258 */
        "movl 0x3110(%eax), %ebx\n" /* obj */
        "movl 4(%edx), %eax\n" /* line 2259 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* obj */
        "calll DObjSetModel\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 2261 | obj */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2877 */
__attribute__((naked))
void R_DObjReplaceMaterial(struct DObj_s *obj, int lod, int surfaceIndex, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2877 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        "movl 8(%ebp), %esi\n" /* obj */
        "movl 0x10(%ebp), %edi\n" /* surfaceIndex */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 2890 | obj */
        "calll DObjGetNumModels\n"
        "testl %eax, %eax\n" /* line 2893 */
        "jle .Lfd01ac_000d023d\n"
        "movzbl 0xc(%ebp), %ecx\n" /* lod */
        "xorl %edx, %edx\n"
        "leal -0x20(%ebp), %ebx\n" /* lods */
        ".Lfd01ac_000d01d3:\n"
        "movb %cl, (%edx, %ebx)\n" /* line 2894 */
        "addl $1, %edx\n" /* line 2893 */
        "cmpl %edx, %eax\n"
        "jne .Lfd01ac_000d01d3\n"
        ".Lfd01ac_000d01dd:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 2896 */
        "leal -0x30(%ebp), %eax\n" /* partBits */
        "movl %eax, 8(%esp)\n"
        "leal -0x130(%ebp), %eax\n" /* surfaces */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjGetSurfaces\n"
        "movswl -0x130(%ebp, %edi, 4), %ebx\n" /* line 2898 */
        /* { scope 2 */
        "movl %ebx, 4(%esp)\n" /* line 1830 */
        "movl %esi, (%esp)\n"
        "calll DObjGetModel\n"
        "movl %eax, (%esp)\n" /* line 1832 */
        "calll XModelGetSkins\n"
        "movl %eax, %ecx\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 2900 */
        "je .Lfd01ac_000d0232\n"
        "movsbl -0x20(%ebp, %ebx), %eax\n" /* line 2905 */
        "movswl -0x12e(%ebp, %edi, 4), %edx\n"
        "movl (%ecx, %eax, 4), %eax\n"
        "movl 0x14(%ebp), %ecx\n" /* material */
        "movl %ecx, (%eax, %edx, 4)\n"
        /* } scope */
        ".Lfd01ac_000d0232:\n"
        "addl $0x13c, %esp\n" /* line 2906 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd01ac_000d023d:\n"
        "leal -0x20(%ebp), %ebx\n" /* lods */
        "jmp .Lfd01ac_000d01dd\n"
    );
}

/* line 2917 */
static __attribute__((naked))
void R_ReleaseModel(union XAssetHeader header, void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2917 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* header */
        "movl %ebx, (%esp)\n" /* line 2919 | header */
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "je .Lfd0242_000d025e\n"
        "addl $0x14, %esp\n" /* line 2922 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd0242_000d025e:\n"
        "movl %ebx, 8(%ebp)\n" /* line 2921 | header */
        "addl $0x14, %esp\n" /* line 2922 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp XModelUnoptimize\n" /* line 2921 */
    );
}

/* line 2949 */
__attribute__((naked))
void R_OptimizeAllModels(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2949 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195f0e8, %eax\n" /* line 2951 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd026c_000d0282\n"
        "leave\n" /* line 2953 */
        "retl\n"
        ".Lfd026c_000d0282:\n"
        "movl $1, 0xc(%esp)\n" /* line 2952 */
        "movl $0, 8(%esp)\n"
        "movl $R_OptimizeModel, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll DB_EnumXAssets\n"
        "leave\n" /* line 2953 */
        "retl\n"
    );
}

/* line 2925 */
void R_ReleaseAllModels(void)
{
    DB_EnumXAssets(1, R_ReleaseModel, 0, 1);
}

/* line 2931 */
void * Model_Alloc(int size)
{
    return Hunk_AllocInternal(size);
}

/* line 2941 */
static __attribute__((naked))
void R_OptimizeModel(XAssetHeader header, void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2941 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* header */
        "movl %ebx, (%esp)\n" /* line 2943 | header */
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "je .Lfd02de_000d02fa\n"
        "addl $0x14, %esp\n" /* line 2946 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd02de_000d02fa:\n"
        "movl %ebx, 8(%ebp)\n" /* line 2945 | header */
        "addl $0x14, %esp\n" /* line 2946 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp XModelOptimize\n" /* line 2945 */
    );
}

/* line 1696 */
__attribute__((naked))
void R_GetRigidTransform(const DObjSkelMat *bone, const vec_t *origin, vec3_t *axis, float scale, vec3_t *boneAxis)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1696 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %edx\n" /* bone */
        "movl 0xc(%ebp), %esi\n" /* origin */
        "movl 0x10(%ebp), %eax\n" /* axis */
        "movss 0x14(%ebp), %xmm1\n" /* scale */
        "movl 0x18(%ebp), %ebx\n" /* boneAxis */
        /* { scope 1 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* scaledAxis */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 274 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "leal 0xc(%eax), %ecx\n" /* line 1701 | v */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0xc(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 274 */
        "mulss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x18(%ebp)\n"
        /* } scope */
        "leal 0x18(%eax), %ecx\n" /* line 1702 | v */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x18(%eax), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "mulss 8(%ecx), %xmm1\n" /* line 274 */
        "movss %xmm1, -0xc(%ebp)\n"
        /* } scope */
        "movss (%edx), %xmm1\n" /* line 1704 */
        "mulss -0x2c(%ebp), %xmm1\n" /* scaledAxis */
        "movss 4(%edx), %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss -0x14(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ebx)\n" /* boneAxis */
        "movss (%edx), %xmm1\n" /* line 1705 */
        "mulss -0x28(%ebp), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss -0x10(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ebx)\n" /* boneAxis */
        "movss (%edx), %xmm1\n" /* line 1706 */
        "mulss -0x24(%ebp), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss -0x18(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ebx)\n" /* boneAxis */
        "leal 0xc(%ebx), %eax\n" /* line 1708 | boneAxis */
        "movss 0x10(%edx), %xmm1\n"
        "mulss -0x2c(%ebp), %xmm1\n" /* scaledAxis */
        "movss 0x14(%edx), %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x18(%edx), %xmm0\n"
        "mulss -0x14(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ebx)\n" /* boneAxis */
        "movss 0x10(%edx), %xmm1\n" /* line 1709 */
        "mulss -0x28(%ebp), %xmm1\n"
        "movss 0x14(%edx), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x18(%edx), %xmm0\n"
        "mulss -0x10(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "movss 0x10(%edx), %xmm1\n" /* line 1710 */
        "mulss -0x24(%ebp), %xmm1\n"
        "movss 0x14(%edx), %xmm0\n"
        "mulss -0x18(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x18(%edx), %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        "leal 0x18(%ebx), %eax\n" /* line 1712 | boneAxis */
        "movss 0x20(%edx), %xmm1\n"
        "mulss -0x2c(%ebp), %xmm1\n" /* scaledAxis */
        "movss 0x24(%edx), %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x28(%edx), %xmm0\n"
        "mulss -0x14(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x18(%ebx)\n" /* boneAxis */
        "movss 0x20(%edx), %xmm1\n" /* line 1713 */
        "mulss -0x28(%ebp), %xmm1\n"
        "movss 0x24(%edx), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x28(%edx), %xmm0\n"
        "mulss -0x10(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "movss 0x20(%edx), %xmm1\n" /* line 1714 */
        "mulss -0x24(%ebp), %xmm1\n"
        "movss 0x24(%edx), %xmm0\n"
        "mulss -0x18(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x28(%edx), %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        "leal 0x24(%ebx), %eax\n" /* line 1716 | boneAxis */
        "movss 0x30(%edx), %xmm1\n"
        "mulss -0x2c(%ebp), %xmm1\n" /* scaledAxis */
        "movss 0x34(%edx), %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edx), %xmm0\n"
        "mulss -0x14(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss (%esi), %xmm1\n" /* origin */
        "movss %xmm1, 0x24(%ebx)\n" /* boneAxis */
        "movss 0x30(%edx), %xmm1\n" /* line 1717 */
        "mulss -0x28(%ebp), %xmm1\n"
        "movss 0x34(%edx), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edx), %xmm0\n"
        "mulss -0x10(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 4(%esi), %xmm1\n" /* origin */
        "movss %xmm1, 4(%eax)\n"
        "movss 0x30(%edx), %xmm1\n" /* line 1718 */
        "mulss -0x24(%ebp), %xmm1\n"
        "movss 0x34(%edx), %xmm0\n"
        "mulss -0x18(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edx), %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 8(%esi), %xmm1\n" /* origin */
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 1719 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 230 */
__attribute__((naked))
void R_ModelBounds(GfxBrushModel *bmodel, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 230 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* bmodel */
        "movl 0xc(%ebp), %edx\n" /* mins */
        "movl 0x10(%ebp), %ebx\n" /* maxs */
        "testl %ecx, %ecx\n" /* line 232 */
        "je .Lfd05b6_000d05ee\n"
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0xc(%ecx), %edx\n"
        /* { scope 1 */
        "movl 0xc(%ecx), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "popl %ebx\n" /* line 241 */
        "popl %ebp\n"
        "retl\n"
        ".Lfd05b6_000d05ee:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "movl %eax, (%ebx)\n" /* line 183 */
        "movl %eax, 4(%ebx)\n" /* line 184 */
        "movl %eax, 8(%ebx)\n" /* line 185 */
        "popl %ebx\n" /* line 241 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 556 */
__attribute__((naked))
void R_LockSkinnedCache(GfxLockType lockType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 556 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "movl 0x195eef4, %eax\n" /* line 1005 */
        "movl (%eax), %eax\n"
        "movl 0x217c78(%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* vb */
        "movl 0x195eed0, %esi\n" /* line 569 */
        "movl 0x2c20(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd0604_000d0633\n"
        "movl 8(%ebp), %eax\n" /* lockType */
        "testl %eax, %eax\n"
        "je .Lfd0604_000d0684\n"
        ".Lfd0604_000d0633:\n"
        "movl $__mh_execute_header, %ecx\n"
        ".Lfd0604_000d0638:\n"
        "leal 0x2dc0(%esi), %eax\n" /* line 574 */
        "movl (%ebx), %edx\n" /* vb */
        "movl %ecx, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* vb */
        "calll *0x2c(%edx)\n"
        "testl %eax, %eax\n" /* line 575 */
        "js .Lfd0604_000d068b\n"
        ".Lfd0604_000d0662:\n"
        "testb $0xf, 0x2dc0(%esi)\n" /* line 577 */
        "je .Lfd0604_000d067d\n"
        "movl (%ebx), %eax\n" /* line 580 | vb */
        "movl %ebx, (%esp)\n" /* vb */
        "calll *0x30(%eax)\n"
        "movl $0, 0x2dc0(%esi)\n" /* line 581 */
        /* } scope */
        ".Lfd0604_000d067d:\n"
        "addl $0x20, %esp\n" /* line 584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd0604_000d0684:\n"
        "movl $0x2000, %ecx\n" /* line 569 */
        "jmp .Lfd0604_000d0638\n"
        ".Lfd0604_000d068b:\n"
        "movl %eax, (%esp)\n" /* line 576 */
        "calll R_FatalLockError\n"
        "jmp .Lfd0604_000d0662\n"
    );
}

/* line 2911 */
void R_ShutdownModels(void)
{
    DB_EnumXAssets(1, R_ReleaseModel, 0, 1);
}

/* line 211 */
__attribute__((naked))
void R_FinishLoadingModels(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 211 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195f0e8, %eax\n" /* line 2951 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd06c2_000d06d8\n"
        "leave\n" /* line 214 */
        "retl\n"
        ".Lfd06c2_000d06d8:\n"
        "movl $1, 0xc(%esp)\n" /* line 2952 */
        "movl $0, 8(%esp)\n"
        "movl $R_OptimizeModel, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll DB_EnumXAssets\n"
        "leave\n" /* line 214 */
        "retl\n"
    );
}

/* line 2838 */
__attribute__((naked))
void R_DObjGetSurfMaterials(struct DObj_s *obj, int lod, MaterialHandle *matHandleArray)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2838 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 2852 | obj */
        "movl %eax, (%esp)\n"
        "calll DObjGetNumModels\n"
        "testl %eax, %eax\n" /* line 2855 */
        "jle .Lfd06fe_000d0761\n"
        "movzbl 0xc(%ebp), %ecx\n" /* lod */
        "xorl %edx, %edx\n"
        "leal -0x20(%ebp), %ebx\n" /* lods */
        ".Lfd06fe_000d0722:\n"
        "movb %cl, (%edx, %ebx)\n" /* line 2856 */
        "addl $1, %edx\n" /* line 2855 */
        "cmpl %edx, %eax\n"
        "jne .Lfd06fe_000d0722\n"
        ".Lfd06fe_000d072c:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 2858 */
        "leal -0x30(%ebp), %eax\n" /* partBits */
        "movl %eax, 8(%esp)\n"
        "leal -0x130(%ebp), %edx\n" /* surfaces */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjGetSurfaces\n"
        "movl %eax, -0x13c(%ebp)\n" /* surfaceCount */
        "testl %eax, %eax\n" /* line 2860 */
        "jg .Lfd06fe_000d0766\n"
        /* } scope */
        ".Lfd06fe_000d0756:\n"
        "addl $0x14c, %esp\n" /* line 2874 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd06fe_000d0761:\n"
        "leal -0x20(%ebp), %ebx\n" /* lods */
        "jmp .Lfd06fe_000d072c\n"
        /* { scope 1 */
        ".Lfd06fe_000d0766:\n"
        "xorl %esi, %esi\n" /* line 2860 | surfaceIndex */
        "jmp .Lfd06fe_000d078e\n"
        ".Lfd06fe_000d076a:\n"
        "movsbl -0x20(%ebp, %ebx), %eax\n" /* line 2872 */
        "movswl -0x12e(%ebp, %edi), %edx\n"
        "movl (%ecx, %eax, 4), %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* matHandleArray */
        "movl %eax, (%edx, %esi, 4)\n"
        ".Lfd06fe_000d0783:\n"
        "addl $1, %esi\n" /* line 2860 | surfaceIndex */
        "cmpl %esi, -0x13c(%ebp)\n" /* surfaceIndex, surfaceCount */
        "je .Lfd06fe_000d0756\n"
        ".Lfd06fe_000d078e:\n"
        "leal (, %esi, 4), %edi\n" /* line 2862 */
        "movswl -0x130(%ebp, %edi), %ebx\n"
        /* { scope 2 */
        "movl %ebx, 4(%esp)\n" /* line 1830 */
        "movl 8(%ebp), %edx\n" /* obj */
        "movl %edx, (%esp)\n"
        "calll DObjGetModel\n"
        "movl %eax, (%esp)\n" /* line 1832 */
        "calll XModelGetSkins\n"
        "movl %eax, %ecx\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 2866 */
        "jne .Lfd06fe_000d076a\n"
        "movl 0x10(%ebp), %eax\n" /* line 2868 | matHandleArray */
        "movl $0, (%eax, %esi, 4)\n"
        "jmp .Lfd06fe_000d0783\n"
    );
}

/* line 257 */
static __attribute__((naked))
int R_GetSurfaceData(long unsigned int (*surfaces)[32], int *partBits, char *lods)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 257 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %edi\n" /* partBits, ent */
        "movl %edx, %esi\n" /* obj */
        "movl %ecx, -0x24(%ebp)\n"
        /* { scope 1: scale */
        "movl %edx, (%esp)\n" /* line 267 */
        "calll DObjGetNumModels\n"
        "movl %eax, -0x20(%ebp)\n" /* modelCount */
        "movss 0x38(%edi), %xmm0\n" /* line 276 | ent */
        "movss %xmm0, -0x1c(%ebp)\n" /* scale */
        /* { scope 2 */
        "movl 0x195eec8, %ebx\n" /* line 249 */
        "leal 0x317c(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x3c(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3Distance\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 0x3188(%ebx), %xmm0\n" /* line 250 */
        "addss 0x318c(%ebx), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 251 | scale */
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lfd07c6_000d085a\n"
        "jne .Lfd07c6_000d085a\n"
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 278 | modelCount */
        "testl %eax, %eax\n"
        "jg .Lfd07c6_000d0865\n"
        ".Lfd07c6_000d0835:\n"
        "movl 0xc(%ebp), %eax\n" /* line 282 | lods */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %eax\n" /* partBits */
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjGetSurfaces\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 283 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: scale */
        /* { scope 2 */
        ".Lfd07c6_000d085a:\n"
        "divss %xmm1, %xmm0\n" /* line 252 */
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 278 | modelCount */
        "testl %eax, %eax\n"
        "jle .Lfd07c6_000d0835\n"
        ".Lfd07c6_000d0865:\n"
        "xorl %ebx, %ebx\n" /* modelIndex */
        ".Lfd07c6_000d0867:\n"
        "movss %xmm0, 8(%esp)\n" /* line 279 */
        "movl %ebx, 4(%esp)\n" /* modelIndex */
        "movl %esi, (%esp)\n" /* obj */
        "movss %xmm0, -0x38(%ebp)\n"
        "calll DObjGetLodForDist\n"
        "movl 0xc(%ebp), %edx\n" /* lods */
        "movb %al, (%ebx, %edx)\n" /* modelIndex */
        "addl $1, %ebx\n" /* line 278 | modelIndex */
        "cmpl %ebx, -0x20(%ebp)\n" /* modelIndex, modelCount */
        "movss -0x38(%ebp), %xmm0\n"
        "jne .Lfd07c6_000d0867\n"
        "movl 0xc(%ebp), %eax\n" /* line 282 | lods */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %eax\n" /* partBits */
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjGetSurfaces\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 283 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 299 */
static __attribute__((naked))
void R_XModelDebugBoxes(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 299 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x39c, %esp\n"
        "movl %eax, %ebx\n" /* sceneEnt */
        "movl %edx, %esi\n" /* ent */
        "movl %ecx, %edi\n" /* obj */
        /* { scope 1 */
        "leal -0x170(%ebp), %ecx\n" /* line 317 | surfaces */
        "leal -0x20(%ebp), %eax\n" /* lods */
        "movl %eax, 4(%esp)\n"
        "leal -0x70(%ebp), %eax\n" /* partBits */
        "movl %eax, (%esp)\n"
        "movl %edi, %edx\n" /* obj */
        "movl %esi, %eax\n" /* ent */
        "calll R_GetSurfaceData\n"
        "movl 8(%ebx), %eax\n" /* line 288 */
        "testl %eax, %eax\n"
        "je .Lfd08b6_000d08fe\n"
        "leal -0x70(%ebp), %edx\n" /* line 294 | partBits */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CG_DObjCalcPose\n"
        ".Lfd08b6_000d08fe:\n"
        "movl %edi, (%esp)\n" /* line 321 | obj */
        "calll DObjNumBones\n"
        "movl %eax, -0x384(%ebp)\n" /* boneCount */
        "leal -0x370(%ebp), %eax\n" /* line 323 | boneInfoArray */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* obj */
        "calll DObjGetBoneInfo\n"
        "movl %edi, (%esp)\n" /* line 324 | obj */
        "calll DObjGetRotTransArray\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 325 */
        "je .Lfd08b6_000d0b22\n"
        "movl $0x3f800000, %eax\n" /* line 328 */
        "movl %eax, -0x60(%ebp)\n" /* color */
        "movl %eax, -0x5c(%ebp)\n" /* line 329 */
        "movl %eax, -0x58(%ebp)\n" /* line 330 */
        "movl $0, -0x54(%ebp)\n" /* line 331 */
        "movl -0x384(%ebp), %ecx\n" /* line 333 | boneCount */
        "testl %ecx, %ecx\n"
        "jle .Lfd08b6_000d0b22\n"
        "movl %edx, -0x37c(%ebp)\n"
        "movl $0, -0x388(%ebp)\n" /* boneIndex */
        "leal 0x14(%esi), %eax\n" /* ent */
        "movl %eax, -0x38c(%ebp)\n"
        "movl -0x388(%ebp), %eax\n" /* boneIndex */
        ".Lfd08b6_000d0972:\n"
        "sarl $5, %eax\n" /* line 335 */
        "movl -0x388(%ebp), %ecx\n" /* boneIndex */
        "andl $0x1f, %ecx\n"
        "movl -0x70(%ebp, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lfd08b6_000d0b02\n"
        "movl -0x388(%ebp), %edx\n" /* line 338 | boneIndex */
        "movl -0x370(%ebp, %edx, 4), %ebx\n" /* boneInfo */
        "movl $0x2f24cc, -0x380(%ebp)\n" /* line 299 */
        "movl $boxVerts, %edi\n" /* obj */
        ".Lfd08b6_000d09a8:\n"
        "movl (%edi), %eax\n" /* line 343 | obj */
        "leal (%eax, %eax, 2), %eax\n"
        "movl (%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x44(%ebp)\n" /* org */
        "movl 4(%edi), %eax\n" /* line 344 | obj */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 4(%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x40(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 345 | obj */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 8(%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x3c(%ebp)\n"
        "leal -0x38(%ebp), %eax\n" /* line 346 | vec */
        "movl %eax, 8(%esp)\n"
        "movl -0x37c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x44(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVectorQuatTrans\n"
        "leal -0x2c(%ebp), %edx\n" /* line 347 | start */
        "movl %edx, 8(%esp)\n"
        "movl -0x38c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* vec */
        "movl %edx, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 240 | start */
        "addss 0x3c(%esi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* start */
        "movss -0x28(%ebp), %xmm0\n" /* line 241 */
        "addss 0x40(%esi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 242 */
        "addss 0x44(%esi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl -0x380(%ebp), %edx\n" /* line 351 */
        "movl (%edx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl (%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x44(%ebp)\n" /* org */
        "movl 4(%edx), %eax\n" /* line 352 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 4(%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x40(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 353 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 8(%ebx, %eax, 4), %eax\n" /* boneInfo */
        "movl %eax, -0x3c(%ebp)\n"
        "leal -0x38(%ebp), %eax\n" /* line 354 | vec */
        "movl %eax, 8(%esp)\n"
        "movl -0x37c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x44(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVectorQuatTrans\n"
        "leal -0x50(%ebp), %edx\n" /* line 355 | end */
        "movl %edx, 8(%esp)\n"
        "movl -0x38c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* vec */
        "movl %edx, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 240 | end */
        "addss 0x3c(%esi), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n" /* end */
        "movss -0x4c(%ebp), %xmm0\n" /* line 241 */
        "addss 0x40(%esi), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss -0x48(%ebp), %xmm0\n" /* line 242 */
        "addss 0x44(%esi), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "leal -0x60(%ebp), %eax\n" /* line 359 | color */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x50(%ebp), %edx\n" /* end */
        "movl %edx, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "movl 0x195eef4, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugLine\n"
        "addl $0x18, %edi\n" /* obj */
        "addl $0x18, -0x380(%ebp)\n"
        "movl $s_streamSourceInfo, %edx\n" /* line 341 */
        "cmpl %edi, %edx\n" /* obj */
        "jne .Lfd08b6_000d09a8\n"
        ".Lfd08b6_000d0b02:\n"
        "addl $1, -0x388(%ebp)\n" /* line 333 | boneIndex */
        "addl $0x20, -0x37c(%ebp)\n"
        "movl -0x388(%ebp), %eax\n" /* boneIndex */
        "cmpl %eax, -0x384(%ebp)\n" /* boneCount */
        "jne .Lfd08b6_000d0972\n"
        /* } scope */
        ".Lfd08b6_000d0b22:\n"
        "addl $0x39c, %esp\n" /* line 362 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 365 */
static __attribute__((naked))
void R_XModelDebugAxes(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 365 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x19c, %esp\n"
        "movl %eax, %ebx\n" /* sceneEnt */
        "movl %edx, %esi\n" /* ent */
        "movl %ecx, %edi\n" /* obj */
        /* { scope 1 */
        "leal -0x188(%ebp), %ecx\n" /* line 380 | surfaces */
        "leal -0x20(%ebp), %eax\n" /* lods */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* partBits */
        "movl %eax, (%esp)\n"
        "movl %edi, %edx\n" /* obj */
        "movl %esi, %eax\n" /* ent */
        "calll R_GetSurfaceData\n"
        "movl 8(%ebx), %eax\n" /* line 288 */
        "testl %eax, %eax\n"
        "je .Lfd0b2e_000d0b76\n"
        "leal -0x54(%ebp), %edx\n" /* line 294 | partBits */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CG_DObjCalcPose\n"
        ".Lfd0b2e_000d0b76:\n"
        "movl $0x40c00000, %edx\n" /* line 383 */
        "movl %edx, -0x88(%ebp)\n" /* translation */
        "xorl %eax, %eax\n" /* line 384 */
        "movl %eax, -0x84(%ebp)\n"
        "movl %eax, -0x80(%ebp)\n" /* line 385 */
        "movl %eax, -0x7c(%ebp)\n" /* line 387 */
        "movl %edx, -0x78(%ebp)\n" /* line 388 */
        "movl %eax, -0x74(%ebp)\n" /* line 389 */
        "movl %eax, -0x70(%ebp)\n" /* line 391 */
        "movl %eax, -0x6c(%ebp)\n" /* line 392 */
        "movl %edx, -0x68(%ebp)\n" /* line 393 */
        "movl %edi, (%esp)\n" /* line 396 | obj */
        "calll DObjNumBones\n"
        "movl %eax, -0x18c(%ebp)\n" /* boneCount */
        "movl %edi, (%esp)\n" /* line 397 | obj */
        "calll DObjGetRotTransArray\n"
        "testl %eax, %eax\n" /* line 398 */
        "je .Lfd0b2e_000d0d58\n"
        "movl -0x18c(%ebp), %ebx\n" /* line 401 | boneCount, boneIndex */
        "testl %ebx, %ebx\n" /* boneIndex */
        "jle .Lfd0b2e_000d0d58\n"
        "movl %eax, %edi\n" /* obj */
        "xorl %ebx, %ebx\n" /* boneIndex */
        "jmp .Lfd0b2e_000d0be2\n"
        ".Lfd0b2e_000d0bd0:\n"
        "addl $1, %ebx\n" /* boneIndex */
        "addl $0x20, %edi\n" /* obj */
        "cmpl %ebx, -0x18c(%ebp)\n" /* boneIndex, boneCount */
        "je .Lfd0b2e_000d0d58\n"
        ".Lfd0b2e_000d0be2:\n"
        "movl %ebx, %eax\n" /* line 403 | boneIndex */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n" /* boneIndex */
        "andl $0x1f, %ecx\n"
        "movl -0x54(%ebp, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lfd0b2e_000d0bd0\n"
        "movl $0, -0x190(%ebp)\n" /* line 404 | axis */
        "leal 0x14(%esi), %eax\n" /* ent */
        "movl %eax, -0x194(%ebp)\n"
        "leal -0x88(%ebp), %edx\n" /* translation */
        "movl %edx, -0x198(%ebp)\n"
        ".Lfd0b2e_000d0c15:\n"
        "movl $0, -0x64(%ebp)\n" /* line 183 | color */
        "movl $0, -0x60(%ebp)\n" /* line 184 */
        "movl $0, -0x5c(%ebp)\n" /* line 185 */
        "movl $0, -0x58(%ebp)\n" /* line 409 */
        "movl -0x190(%ebp), %eax\n" /* line 410 | axis */
        "movl $0x3f800000, -0x64(%ebp, %eax, 4)\n"
        "leal -0x2c(%ebp), %edx\n" /* line 412 | vec */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* obj */
        "movl 0x195ed4c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVectorQuatTrans\n"
        "leal -0x38(%ebp), %eax\n" /* line 413 | start */
        "movl %eax, 8(%esp)\n"
        "movl -0x194(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* vec */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 240 | start */
        "addss 0x3c(%esi), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n" /* start */
        "movss -0x34(%ebp), %xmm0\n" /* line 241 */
        "addss 0x40(%esi), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 242 */
        "addss 0x44(%esi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "leal -0x2c(%ebp), %edx\n" /* line 416 | vec */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* obj */
        "movl -0x198(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVectorQuatTrans\n"
        "leal -0x44(%ebp), %edx\n" /* line 417 | end */
        "movl %edx, 8(%esp)\n"
        "movl -0x194(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2c(%ebp), %edx\n" /* vec */
        "movl %edx, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 240 | end */
        "addss 0x3c(%esi), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n" /* end */
        "movss -0x40(%ebp), %xmm0\n" /* line 241 */
        "addss 0x40(%esi), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 242 */
        "addss 0x44(%esi), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "leal -0x64(%ebp), %eax\n" /* line 420 | color */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x44(%ebp), %edx\n" /* end */
        "movl %edx, 8(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "movl 0x195eef4, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugLine\n"
        "addl $1, -0x190(%ebp)\n" /* line 406 | axis */
        "addl $0xc, -0x198(%ebp)\n"
        "cmpl $3, -0x190(%ebp)\n" /* axis */
        "jne .Lfd0b2e_000d0c15\n"
        "addl $1, %ebx\n" /* line 401 | boneIndex */
        "addl $0x20, %edi\n" /* obj */
        "cmpl %ebx, -0x18c(%ebp)\n" /* boneIndex, boneCount */
        "jne .Lfd0b2e_000d0be2\n"
        /* } scope */
        ".Lfd0b2e_000d0d58:\n"
        "addl $0x19c, %esp\n" /* line 423 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2749 */
__attribute__((naked))
void R_UpdateXModelBounds(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2749 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3bc, %esp\n"
        "movl 8(%ebp), %edi\n" /* sceneEnt */
        /* { scope 1: xx, yy, yz */
        "movl 0xc(%edi), %eax\n" /* line 2766 | sceneEnt */
        "subl $1, %eax\n"
        "jle .Lfd0d64_000d0d86\n"
        /* } scope */
        ".Lfd0d64_000d0d7b:\n"
        "addl $0x3bc, %esp\n" /* line 2835 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xx, yy, yz */
        ".Lfd0d64_000d0d86:\n"
        "leal 0xc(%edi), %eax\n" /* line 2769 | sceneEnt */
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InterlockedCompareExchange\n"
        "testl %eax, %eax\n"
        "je .Lfd0d64_000d0daf\n"
        ".Lfd0d64_000d0da5:\n"
        "movl 0xc(%edi), %eax\n" /* line 2771 | sceneEnt */
        "subl $1, %eax\n"
        "jle .Lfd0d64_000d0da5\n"
        "jmp .Lfd0d64_000d0d7b\n"
        ".Lfd0d64_000d0daf:\n"
        "movl 0xc(%ebp), %eax\n" /* line 2252 | ent */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd0d64_000d0e7a\n"
        "movl 4(%edi), %ebx\n" /* line 2253 */
        ".Lfd0d64_000d0dbf:\n"
        "movl %ebx, (%esp)\n" /* line 2782 | obj */
        "calll DObjBad\n"
        "testl %eax, %eax\n"
        "je .Lfd0d64_000d0e26\n"
        "movl 0x195f0f0, %eax\n" /* line 2785 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %esi\n" /* boneMatrix */
        "testl %esi, %esi\n" /* boneMatrix */
        "jne .Lfd0d64_000d0e0c\n"
        ".Lfd0d64_000d0dd9:\n"
        "movl 0xc(%ebp), %edx\n" /* line 199 | ent */
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "movl 0x40(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x18(%edi)\n"
        "movl 0x44(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x1c(%edi)\n"
        "movl 0x3c(%edx), %eax\n" /* line 199 */
        "movl %eax, 0x20(%edi)\n"
        "movl 0x40(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x24(%edi)\n"
        "movl 0x44(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x28(%edi)\n"
        "movl $2, 0xc(%edi)\n" /* line 2744 */
        "jmp .Lfd0d64_000d0d7b\n"
        ".Lfd0d64_000d0e0c:\n"
        "movl %ebx, %ecx\n" /* line 2788 | obj */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %edi, %eax\n" /* sceneEnt */
        "calll R_XModelDebugBoxes\n"
        "movl %ebx, %ecx\n" /* line 2789 | obj */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %edi, %eax\n" /* sceneEnt */
        "calll R_XModelDebugAxes\n"
        "jmp .Lfd0d64_000d0dd9\n"
        ".Lfd0d64_000d0e26:\n"
        "leal -0x16c(%ebp), %ecx\n" /* line 2800 | surfaces */
        "leal -0x20(%ebp), %eax\n" /* lods */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %esi\n" /* partBits, boneMatrix */
        "movl %esi, (%esp)\n" /* boneMatrix */
        "movl %ebx, %edx\n" /* obj */
        "movl 0xc(%ebp), %eax\n" /* ent */
        "calll R_GetSurfaceData\n"
        "testl %eax, %eax\n" /* line 2802 */
        "jne .Lfd0d64_000d0e99\n"
        "movl 0xc(%ebp), %ecx\n" /* line 199 | ent */
        "movl 0x3c(%ecx), %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "movl 0x40(%ecx), %eax\n" /* line 200 */
        "movl %eax, 0x18(%edi)\n"
        "movl 0x44(%ecx), %eax\n" /* line 201 */
        "movl %eax, 0x1c(%edi)\n"
        "movl 0x3c(%ecx), %eax\n" /* line 199 */
        "movl %eax, 0x20(%edi)\n"
        "movl 0x40(%ecx), %eax\n" /* line 200 */
        "movl %eax, 0x24(%edi)\n"
        "movl 0x44(%ecx), %eax\n" /* line 201 */
        "movl %eax, 0x28(%edi)\n"
        "movl $2, 0xc(%edi)\n" /* line 2744 */
        "jmp .Lfd0d64_000d0d7b\n"
        ".Lfd0d64_000d0e7a:\n"
        "movl 0x195eec8, %eax\n" /* line 2258 */
        "movl 0x3110(%eax), %ebx\n"
        "movl 4(%edi), %eax\n" /* line 2259 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll DObjSetModel\n"
        "jmp .Lfd0d64_000d0dbf\n"
        ".Lfd0d64_000d0e99:\n"
        "movl 8(%edi), %eax\n" /* line 288 */
        "testl %eax, %eax\n"
        "je .Lfd0d64_000d0eb0\n"
        "movl %esi, 8(%esp)\n" /* line 294 */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CG_DObjCalcPose\n"
        ".Lfd0d64_000d0eb0:\n"
        "movl %ebx, (%esp)\n" /* line 2811 | obj */
        "calll DObjGetRotTransArray\n"
        "movl %eax, %esi\n" /* boneMatrix */
        "testl %eax, %eax\n" /* line 2812 */
        "je .Lfd0d64_000d0dd9\n"
        "leal -0x3c(%ebp), %eax\n" /* line 2819 */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %ecx\n" /* bounds */
        "movl %ecx, (%esp)\n"
        "calll ClearBounds\n"
        "leal -0x36c(%ebp), %eax\n" /* line 2820 | boneInfoArray */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* obj */
        "calll DObjGetBoneInfo\n"
        "movl %ebx, (%esp)\n" /* line 2821 | obj */
        "calll DObjNumBones\n"
        "movl %eax, -0x38c(%ebp)\n" /* boneCount */
        "testl %eax, %eax\n" /* line 2822 */
        "jle .Lfd0d64_000d12f3\n"
        "movl %esi, -0x37c(%ebp)\n" /* boneMatrix */
        "movl $0, -0x390(%ebp)\n" /* boneIndex */
        "movl -0x390(%ebp), %eax\n" /* boneIndex */
        ".Lfd0d64_000d0f12:\n"
        "sarl $5, %eax\n" /* line 2824 */
        "movl -0x390(%ebp), %ecx\n" /* boneIndex */
        "andl $0x1f, %ecx\n"
        "movl -0x30(%ebp, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lfd0d64_000d12d3\n"
        /* { scope 2 */
        "movl -0x37c(%ebp), %eax\n" /* line 306 */
        "movss 0x1c(%eax), %xmm1\n" /* scale */
        /* { scope 3 */
        "movss (%eax), %xmm0\n" /* line 272 */
        "movaps %xmm1, %xmm4\n"
        "mulss %xmm0, %xmm4\n"
        "movss 4(%eax), %xmm3\n" /* line 273 */
        "movaps %xmm1, %xmm5\n"
        "mulss %xmm3, %xmm5\n"
        "movss 8(%eax), %xmm2\n" /* line 274 */
        "mulss %xmm2, %xmm1\n"
        /* } scope */
        "mulss %xmm4, %xmm0\n" /* line 308 */
        "movss %xmm0, -0x388(%ebp)\n" /* xx */
        "movaps %xmm4, %xmm6\n" /* line 309 */
        "mulss %xmm3, %xmm6\n"
        "movaps %xmm4, %xmm7\n" /* line 310 */
        "mulss %xmm2, %xmm7\n"
        "movss 0xc(%eax), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm4\n"
        "mulss %xmm5, %xmm3\n" /* line 313 */
        "movss %xmm3, -0x384(%ebp)\n" /* yy */
        "movaps %xmm5, %xmm3\n" /* line 314 */
        "mulss %xmm2, %xmm3\n"
        "movss %xmm3, -0x380(%ebp)\n" /* yz */
        "mulss %xmm0, %xmm5\n" /* line 315 */
        "mulss %xmm1, %xmm2\n" /* line 317 */
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss -0x384(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "movss %xmm3, -0x6c(%ebp)\n" /* boneAxis */
        "movaps %xmm6, %xmm3\n" /* line 321 */
        "addss %xmm1, %xmm3\n"
        "movss %xmm3, -0x398(%ebp)\n"
        "movss %xmm3, -0x68(%ebp)\n"
        "movaps %xmm7, %xmm3\n" /* line 322 */
        "subss %xmm5, %xmm3\n"
        "movss %xmm3, -0x39c(%ebp)\n"
        "movss %xmm3, -0x64(%ebp)\n"
        "subss %xmm1, %xmm6\n" /* line 324 */
        "movss %xmm6, -0x60(%ebp)\n"
        "addss -0x388(%ebp), %xmm2\n" /* line 325 | xx */
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "subss %xmm2, %xmm3\n"
        "movss %xmm3, -0x5c(%ebp)\n"
        "movss -0x380(%ebp), %xmm1\n" /* line 326 | yz */
        "addss %xmm4, %xmm1\n"
        "movss %xmm1, -0x3a0(%ebp)\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "addss %xmm5, %xmm7\n" /* line 328 */
        "movss %xmm7, -0x54(%ebp)\n"
        "movss -0x380(%ebp), %xmm5\n" /* line 329 | yz */
        "subss %xmm4, %xmm5\n"
        "movss %xmm5, -0x50(%ebp)\n"
        "movss -0x388(%ebp), %xmm1\n" /* line 330 | xx */
        "addss -0x384(%ebp), %xmm1\n" /* yy */
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "subss %xmm1, %xmm4\n"
        "movss %xmm4, -0x4c(%ebp)\n"
        /* } scope */
        "movl -0x390(%ebp), %eax\n" /* line 2829 | boneIndex */
        "movl -0x36c(%ebp, %eax, 4), %edx\n"
        "movl -0x37c(%ebp), %ecx\n" /* line 2830 */
        "addl $0x10, %ecx\n"
        "movl %ecx, -0x394(%ebp)\n"
        /* { scope 2 */
        "movl -0x37c(%ebp), %eax\n" /* line 2673 */
        "movss 0x10(%eax), %xmm2\n"
        "movl -0x6c(%ebp), %eax\n" /* line 2676 | boneAxis */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movss (%edx, %eax), %xmm1\n" /* line 2677 */
        "mulss %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "leal 0xc(%edx), %ebx\n" /* line 2678 */
        "movl %ebx, %ecx\n"
        "subl %eax, %ecx\n"
        "mulss (%ecx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movl -0x60(%ebp), %eax\n" /* line 2680 */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "leal 4(%edx), %ecx\n" /* line 2681 */
        "movl %ecx, -0x3a4(%ebp)\n"
        "movss (%ecx, %eax), %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "leal 0x10(%edx), %esi\n" /* line 2682 */
        "movl %esi, %ecx\n"
        "subl %eax, %ecx\n"
        "mulss (%ecx), %xmm6\n"
        "addss %xmm6, %xmm2\n"
        "movl -0x54(%ebp), %eax\n" /* line 2684 */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "leal 8(%edx), %ecx\n" /* line 2685 */
        "movl %ecx, -0x3a8(%ebp)\n"
        "movss (%ecx, %eax), %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "leal 0x14(%edx), %ecx\n" /* line 2686 */
        "movl %ecx, -0x3ac(%ebp)\n"
        "subl %eax, %ecx\n"
        "mulss (%ecx), %xmm7\n"
        "addss %xmm7, %xmm2\n"
        "movss -0x48(%ebp), %xmm0\n" /* line 2688 | bounds */
        "movaps %xmm1, %xmm6\n" /* line 2689 */
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm6\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm6, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n" /* bounds */
        "movss -0x3c(%ebp), %xmm0\n" /* line 2691 */
        "movaps %xmm0, %xmm1\n"
        "cmpnltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl -0x394(%ebp), %eax\n" /* line 2694 */
        "movss 4(%eax), %xmm2\n"
        "movl -0x68(%ebp), %eax\n" /* line 2697 */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movss -0x398(%ebp), %xmm1\n" /* line 2698 */
        "mulss (%edx, %eax), %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movl %ebx, %ecx\n" /* line 2699 */
        "subl %eax, %ecx\n"
        "movss -0x398(%ebp), %xmm0\n"
        "mulss (%ecx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movl -0x5c(%ebp), %eax\n" /* line 2701 */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movl -0x3a4(%ebp), %ecx\n" /* line 2702 */
        "movss (%ecx, %eax), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl %esi, %ecx\n" /* line 2703 */
        "subl %eax, %ecx\n"
        "mulss (%ecx), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "movl -0x50(%ebp), %eax\n" /* line 2705 */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movl -0x3a8(%ebp), %ecx\n" /* line 2706 */
        "movss (%ecx, %eax), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x3ac(%ebp), %ecx\n" /* line 2707 */
        "subl %eax, %ecx\n"
        "mulss (%ecx), %xmm5\n"
        "addss %xmm5, %xmm2\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 2709 */
        "movaps %xmm1, %xmm3\n" /* line 2710 */
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm3\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 2712 */
        "movaps %xmm0, %xmm6\n"
        "cmpnltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm6\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm6, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movl -0x394(%ebp), %eax\n" /* line 2715 */
        "movss 8(%eax), %xmm2\n"
        "movl -0x64(%ebp), %eax\n" /* line 2718 */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movss -0x39c(%ebp), %xmm1\n" /* line 2719 */
        "mulss (%edx, %eax), %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "subl %eax, %ebx\n" /* line 2720 */
        "movss -0x39c(%ebp), %xmm0\n"
        "mulss (%ebx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movl -0x58(%ebp), %eax\n" /* line 2722 */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movss -0x3a0(%ebp), %xmm0\n" /* line 2723 */
        "movl -0x3a4(%ebp), %edx\n"
        "mulss (%edx, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subl %eax, %esi\n" /* line 2724 */
        "movss -0x3a0(%ebp), %xmm0\n"
        "mulss (%esi), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movl -0x4c(%ebp), %eax\n" /* line 2726 */
        "sarl $0x1f, %eax\n"
        "andl $0xc, %eax\n"
        "movl -0x3a8(%ebp), %edx\n" /* line 2727 */
        "movss (%edx, %eax), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subl %eax, -0x3ac(%ebp)\n" /* line 2728 */
        "movl -0x3ac(%ebp), %ecx\n"
        "mulss (%ecx), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 2730 */
        "movaps %xmm1, %xmm3\n" /* line 2731 */
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm3\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 2733 */
        "movaps %xmm0, %xmm6\n"
        "cmpnltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm6\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm6, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        ".Lfd0d64_000d12d3:\n"
        "addl $1, -0x390(%ebp)\n" /* line 2822 | boneIndex */
        "addl $0x20, -0x37c(%ebp)\n"
        "movl -0x390(%ebp), %eax\n" /* boneIndex */
        "cmpl %eax, -0x38c(%ebp)\n" /* boneCount */
        "jne .Lfd0d64_000d0f12\n"
        ".Lfd0d64_000d12f3:\n"
        "leal 0x14(%edi), %eax\n" /* line 2833 | sceneEnt */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "addl $0x14, %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* ent */
        "addl $0x3c, %ecx\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* bounds */
        "movl %edx, (%esp)\n"
        "calll GetRotatedBounds\n"
        "movl $2, 0xc(%edi)\n" /* line 2744 */
        "jmp .Lfd0d64_000d0d7b\n"
    );
}

/* line 1836 */
static __attribute__((naked))
int R_PreSkinXSurface(GfxSceneEntity *sceneEnt, const struct DObj_s *obj, long unsigned int (*surface)[32], int surfaceIndex, char *lods, byte *surfPos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1836 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* surface */
        /* { scope 1 */
        "movswl (%edi), %esi\n" /* line 1855 | surface, xsurf */
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 1830 */
        "movl 0xc(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "movl %eax, (%esp)\n" /* line 1832 */
        "calll XModelGetSkins\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1858 */
        "je .Lfd1326_000d13b0\n"
        "movl 0x18(%ebp), %eax\n" /* line 1860 | lods */
        "movsbl (%esi, %eax), %edx\n" /* xsurf */
        "movswl 2(%edi), %ecx\n" /* line 1862 | surface */
        "leal (, %ecx, 4), %eax\n"
        "addl (%ebx, %edx, 4), %eax\n" /* skins */
        "movl (%eax), %ebx\n" /* skins */
        "movl %edx, 0xc(%esp)\n" /* line 1864 */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* xsurf */
        "movl 0xc(%ebp), %edx\n" /* obj */
        "movl %edx, (%esp)\n"
        "calll DObjGetSurface\n"
        "movl %eax, %esi\n" /* xsurf */
        "movl 0x14(%ebp), %eax\n" /* line 1865 | surfaceIndex */
        "shll $2, %eax\n"
        "movl 8(%ebp), %edx\n" /* sceneEnt */
        "addl 0x2c(%edx), %eax\n"
        "movl %ebx, (%eax)\n" /* skins */
        "movl 0x10(%esi), %eax\n" /* line 1878 | xsurf */
        "testl %eax, %eax\n"
        "je .Lfd1326_000d13ba\n"
        "movl 0x1c(%ebp), %edx\n" /* line 1924 | surfPos */
        "movl $4, (%edx)\n"
        "movl %esi, 4(%edx)\n" /* line 1925 | xsurf */
        "movl $0x38, %eax\n"
        /* } scope */
        ".Lfd1326_000d13a8:\n"
        "addl $0x1c, %esp\n" /* line 1927 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd1326_000d13b0:\n"
        "xorl %eax, %eax\n" /* line 1926 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1927 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd1326_000d13ba:\n"
        "movl 0x195ef14, %eax\n" /* line 1884 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfd1326_000d14ad\n"
        "movl 0x14(%esi), %eax\n" /* line 1886 | xsurf */
        "testl %eax, %eax\n"
        "je .Lfd1326_000d14ad\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1888 | surfPos */
        "movl $0, 0xc(%eax)\n"
        "movl %esi, (%esp)\n" /* line 1889 | xsurf */
        "calll XSurfaceGetNumVerts\n"
        "movl %eax, %ecx\n" /* vertCount */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x195eed0, %eax\n" /* line 614 */
        "movl 0x2dc0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd1326_000d146a\n"
        "movl 0x195eec0, %eax\n" /* line 1067 */
        "movl (%eax), %eax\n"
        "movl $0x24, %edx\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x40, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl 0x195eef4, %edi\n" /* line 620 */
        "movl (%edi), %eax\n"
        "movl 0x217c78(%eax), %eax\n"
        "imull %ecx, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InterlockedExchangeAdd\n"
        "movl (%edi), %ecx\n" /* line 621 */
        "movl 0x217c78(%ecx), %edx\n"
        "movl 4(%edx), %ebx\n"
        "cmpl %ebx, (%edx)\n"
        "jle .Lfd1326_000d146f\n"
        "cmpl %ebx, %eax\n" /* line 624 */
        "jle .Lfd1326_000d1554\n"
        ".Lfd1326_000d1445:\n"
        "movl (%ecx), %eax\n" /* line 627 */
        "cmpl warnCount, %eax\n"
        "je .Lfd1326_000d146a\n"
        "movl %eax, warnCount\n" /* line 629 */
        "movl $0x223f60, 4(%esp)\n" /* line 630 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        ".Lfd1326_000d146a:\n"
        "movl $0xffffffff, %eax\n"
        /* } scope */
        /* } scope */
        ".Lfd1326_000d146f:\n"
        "movl 0x1c(%ebp), %edx\n" /* line 1889 | surfPos */
        "movl %eax, 8(%edx)\n"
        "testl %eax, %eax\n" /* line 1890 */
        "js .Lfd1326_000d14ad\n"
        "movl 0x195eef4, %eax\n" /* line 1891 */
        "movl (%eax), %eax\n"
        "movl 0x217c78(%eax), %edx\n"
        "movl 0x195eed0, %eax\n" /* line 1895 */
        "movl 0x2dc0(%eax), %eax\n"
        "addl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd1326_000d14ad\n"
        ".Lfd1326_000d1497:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1917 | surfPos */
        "movl $3, (%eax)\n"
        "movl %esi, 4(%eax)\n" /* line 1918 | xsurf */
        "movl $0x10, %eax\n"
        "jmp .Lfd1326_000d13a8\n"
        ".Lfd1326_000d14ad:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1897 | surfPos */
        "movl $0xffffffff, 8(%eax)\n"
        "movl %esi, (%esp)\n" /* line 1898 | xsurf */
        "calll XSurfaceGetNumVerts\n"
        "movl 0x195eec0, %edx\n" /* line 1067 */
        "movl (%edx), %edx\n"
        "movl $0x24, %ecx\n"
        "cmpl $2, 8(%edx)\n"
        "movl $0x40, %edx\n"
        "cmovnel %edx, %ecx\n"
        "imull %eax, %ecx\n" /* line 1898 */
        "movl 0x195eed0, %ebx\n" /* line 1900 | skins */
        "movl 0x2dd4(%ebx), %edx\n" /* skins */
        "leal (%ecx, %edx), %eax\n"
        "cmpl $0xa00000, %eax\n"
        "jle .Lfd1326_000d1528\n"
        "movl 0x195eef4, %eax\n" /* line 1902 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1326_000d13b0\n"
        "movl %eax, warnCount\n" /* line 1904 */
        "movl $0x223fa0, 4(%esp)\n" /* line 1905 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lfd1326_000d13a8\n"
        ".Lfd1326_000d1528:\n"
        "addl 0x2dd0(%ebx), %edx\n" /* line 1910 | skins */
        "movl 0x1c(%ebp), %eax\n" /* surfPos */
        "movl %edx, 0xc(%eax)\n"
        "addl %ecx, 0x2dd4(%ebx)\n" /* line 1911 | skins */
        "movl 0x1c(%ebp), %edx\n" /* line 1912 | surfPos */
        "movl 0xc(%edx), %eax\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x24(%eax)\n"
        "jmp .Lfd1326_000d1497\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfd1326_000d1554:\n"
        "movl %eax, 4(%esp)\n" /* line 625 */
        "movl %edx, (%esp)\n"
        "calll InterlockedExchange\n"
        "movl (%edi), %ecx\n"
        "jmp .Lfd1326_000d1445\n"
    );
}

/* line 2469 */
__attribute__((naked))
void R_SkinSceneDObj(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2469 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfec, %esp\n"
        "movl 8(%ebp), %ebx\n" /* sceneEnt */
        /* { scope 1 */
        "movl 0xc(%ebx), %eax\n" /* line 2495 | sceneEnt */
        "cmpl $3, %eax\n"
        "jle .Lfd1568_000d158a\n"
        /* } scope */
        ".Lfd1568_000d157f:\n"
        "addl $0xfec, %esp\n" /* line 2636 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd1568_000d158a:\n"
        "leal 0xc(%ebx), %eax\n" /* line 2498 | sceneEnt */
        "movl $2, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InterlockedCompareExchange\n"
        "cmpl $2, %eax\n"
        "je .Lfd1568_000d15bd\n"
        ".Lfd1568_000d15aa:\n"
        "movl 0xc(%ebx), %eax\n" /* line 2500 | sceneEnt */
        "cmpl $3, %eax\n"
        "jle .Lfd1568_000d15aa\n"
        /* } scope */
        "addl $0xfec, %esp\n" /* line 2636 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd1568_000d15bd:\n"
        "movl 4(%ebx), %esi\n" /* line 2507 | sceneEnt, obj */
        "movl %esi, (%esp)\n" /* line 2511 | obj */
        "calll DObjBad\n"
        "testl %eax, %eax\n"
        "je .Lfd1568_000d15e7\n"
        "movl 0x195f0f0, %eax\n" /* line 2513 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfd1568_000d16a2\n"
        ".Lfd1568_000d15de:\n"
        "movl $4, 0xc(%ebx)\n" /* line 2271 */
        "jmp .Lfd1568_000d157f\n"
        ".Lfd1568_000d15e7:\n"
        "movl %esi, (%esp)\n" /* line 2523 | obj */
        "calll DObjNumBones\n"
        "movl %eax, -0xfc4(%ebp)\n" /* boneCount */
        "leal -0x20(%ebp), %eax\n" /* line 2525 | lods */
        "movl %eax, 4(%esp)\n"
        "leal -0xa0(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "leal -0x1ac(%ebp), %ecx\n" /* surfaces */
        "movl %esi, %edx\n" /* obj */
        "movl 0xc(%ebp), %eax\n" /* ent */
        "calll R_GetSurfaceData\n"
        "movl %eax, -0xfc8(%ebp)\n" /* surfaceCount */
        "testl %eax, %eax\n" /* line 2527 */
        "je .Lfd1568_000d15de\n"
        "movl %esi, (%esp)\n" /* line 2535 | obj */
        "calll DObjGetRotTransArray\n"
        "movl %eax, -0xfc0(%ebp)\n" /* boneMatrix */
        "testl %eax, %eax\n" /* line 2536 */
        "je .Lfd1568_000d15de\n"
        "movl 0x195f0f4, %eax\n" /* line 2544 */
        "addl $0x1a55c, %eax\n"
        "movl -0xfc8(%ebp), %edx\n" /* surfaceCount */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InterlockedExchangeAdd\n"
        "movl %eax, %edx\n"
        "movl -0xfc8(%ebp), %eax\n" /* line 2546 | surfaceCount */
        "addl %edx, %eax\n"
        "cmpl $__mh_execute_header, %eax\n"
        "jbe .Lfd1568_000d16bf\n"
        "movl 0x195f0f4, %eax\n" /* line 2548 */
        "movl $__mh_execute_header, 0x1a55c(%eax)\n"
        "movl 0x195eef4, %eax\n" /* line 2549 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1568_000d15de\n"
        "movl %eax, warnCount\n" /* line 2551 */
        "movl $0x223fd4, 4(%esp)\n" /* line 2552 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfd1568_000d15de\n"
        ".Lfd1568_000d16a2:\n"
        "movl %esi, %ecx\n" /* line 2515 | obj */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %ebx, %eax\n" /* sceneEnt */
        "calll R_XModelDebugBoxes\n"
        "movl %esi, %ecx\n" /* line 2516 | obj */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %ebx, %eax\n" /* sceneEnt */
        "calll R_XModelDebugAxes\n"
        "jmp .Lfd1568_000d15de\n"
        ".Lfd1568_000d16bf:\n"
        "movl 0x195f0f4, %eax\n" /* line 2560 */
        "leal 0x1a560(%eax, %edx, 4), %eax\n"
        "movl %eax, 0x2c(%ebx)\n" /* sceneEnt */
        "movl -0xfc8(%ebp), %eax\n" /* line 2563 | surfaceCount */
        "testl %eax, %eax\n"
        "jle .Lfd1568_000d17ba\n"
        "movl $0, -0xfbc(%ebp)\n" /* surfaceIndex */
        "leal -0xfac(%ebp), %edi\n" /* surfBuf, size */
        "leal -0x1ac(%ebp), %ecx\n" /* surfaces */
        "movl %ecx, -0xfcc(%ebp)\n"
        "jmp .Lfd1568_000d1700\n"
        ".Lfd1568_000d16fa:\n"
        "movl -0xfcc(%ebp), %ecx\n"
        ".Lfd1568_000d1700:\n"
        "movl %edi, 0x14(%esp)\n" /* line 2565 | size */
        "leal -0x20(%ebp), %eax\n" /* lods */
        "movl %eax, 0x10(%esp)\n"
        "movl -0xfbc(%ebp), %edx\n" /* surfaceIndex */
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* obj */
        "movl %ebx, (%esp)\n" /* sceneEnt */
        "calll R_PreSkinXSurface\n"
        "testl %eax, %eax\n" /* line 2566 */
        "je .Lfd1568_000d15de\n"
        "addl %eax, %edi\n" /* line 2568 | size */
        "addl $1, -0xfbc(%ebp)\n" /* line 2563 | surfaceIndex */
        "addl $4, -0xfcc(%ebp)\n"
        "movl -0xfbc(%ebp), %eax\n" /* surfaceIndex */
        "cmpl %eax, -0xfc8(%ebp)\n" /* surfaceCount */
        "jne .Lfd1568_000d16fa\n"
        ".Lfd1568_000d174b:\n"
        "leal -0xfac(%ebp), %edx\n" /* line 2577 | surfBuf */
        "subl %edx, %edi\n" /* size */
        "movl 0x195eef4, %ecx\n" /* line 2578 */
        "movl (%ecx), %eax\n"
        "addl $0x80008, %eax\n"
        "movl %edi, 4(%esp)\n" /* size */
        "movl %eax, (%esp)\n"
        "calll InterlockedExchangeAdd\n"
        "movl %eax, %edx\n"
        "leal (%edi, %eax), %eax\n" /* line 2580 | size */
        "cmpl $0x20000, %eax\n"
        "jbe .Lfd1568_000d17c2\n"
        "movl 0x195eef4, %edx\n" /* line 2582 */
        "movl (%edx), %eax\n"
        "movl $0x20000, 0x80008(%eax)\n"
        "movl (%edx), %eax\n" /* line 2583 */
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1568_000d15de\n"
        "movl %eax, warnCount\n" /* line 2585 */
        "movl $0x224008, 4(%esp)\n" /* line 2586 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfd1568_000d15de\n"
        ".Lfd1568_000d17ba:\n"
        "leal -0xfac(%ebp), %edi\n" /* line 2574 | surfBuf, size */
        "jmp .Lfd1568_000d174b\n"
        ".Lfd1568_000d17c2:\n"
        "movl 0x195eef4, %ecx\n" /* line 2594 */
        "movl (%ecx), %eax\n"
        "addl $0x8000c, %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, 0x30(%ebx)\n" /* sceneEnt */
        "movl %edi, 8(%esp)\n" /* line 2595 | size */
        "leal -0xfac(%ebp), %edx\n" /* surfBuf */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0xfc8(%ebp), %ecx\n" /* line 2599 | surfaceCount */
        "movl %ecx, 0x10(%ebx)\n" /* sceneEnt */
        "movl 0x195f0f8, %edi\n" /* line 2601 | size */
        "movl (%edi), %eax\n" /* size */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfd1568_000d1811\n"
        "andb $1, %dl\n" /* line 428 */
        "jne .Lfd1568_000d189b\n"
        ".Lfd1568_000d180b:\n"
        "testb $2, 8(%eax)\n" /* line 431 */
        "jne .Lfd1568_000d188a\n"
        ".Lfd1568_000d1811:\n"
        "cmpl $1, -0xfc4(%ebp)\n" /* line 2604 | boneCount */
        "je .Lfd1568_000d18db\n"
        "movl -0xfc8(%ebp), %eax\n" /* line 2614 | surfaceCount */
        "testl %eax, %eax\n"
        "jg .Lfd1568_000d18ae\n"
        ".Lfd1568_000d182c:\n"
        "movl 0x30(%ebx), %eax\n" /* line 2617 | sceneEnt */
        "movl %eax, -0xac(%ebp)\n" /* skinCmd */
        "movzbl -0xfc8(%ebp), %eax\n" /* line 2618 | surfaceCount */
        "movb %al, -0x90(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 2619 | ent */
        "movl %edx, -0xa8(%ebp)\n"
        "movl -0xfc0(%ebp), %ecx\n" /* line 2620 | boneMatrix */
        "movl %ecx, -0xa4(%ebp)\n"
        "movzbl -0xfc4(%ebp), %eax\n" /* line 2621 | boneCount */
        "movb %al, -0x8f(%ebp)\n"
        "xorl %eax, %eax\n" /* line 2632 */
        "cmpl $0xa, -0xfc8(%ebp)\n" /* surfaceCount */
        "setg %al\n"
        "addl $6, %eax\n"
        "leal -0xac(%ebp), %edx\n" /* skinCmd */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll R_AddFrontendCmd\n"
        "jmp .Lfd1568_000d15de\n"
        ".Lfd1568_000d188a:\n"
        "movl %esi, %ecx\n" /* line 432 */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %ebx, %eax\n"
        "calll R_XModelDebugAxes\n"
        "jmp .Lfd1568_000d1811\n"
        ".Lfd1568_000d189b:\n"
        "movl %esi, %ecx\n" /* line 429 */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %ebx, %eax\n"
        "calll R_XModelDebugBoxes\n"
        "movl (%edi), %eax\n"
        "jmp .Lfd1568_000d180b\n"
        ".Lfd1568_000d18ae:\n"
        "xorl %edi, %edi\n" /* line 2610 | size */
        ".Lfd1568_000d18b0:\n"
        "movswl -0x1ac(%ebp, %edi, 4), %eax\n" /* line 2615 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjGetMatOffset\n"
        "movb %al, -0x8e(%ebp, %edi)\n"
        "addl $1, %edi\n" /* line 2614 | size */
        "cmpl %edi, -0xfc8(%ebp)\n" /* size, surfaceCount */
        "jne .Lfd1568_000d18b0\n"
        "jmp .Lfd1568_000d182c\n"
        ".Lfd1568_000d18db:\n"
        "movl 0x30(%ebx), %eax\n" /* line 2606 | sceneEnt */
        "movl %eax, -0x4c(%ebp)\n" /* skinRigidCmd */
        "movl -0xfc8(%ebp), %eax\n" /* line 2607 | surfaceCount */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 2608 | ent */
        "movl %edx, -0x44(%ebp)\n"
        "movl -0xfc0(%ebp), %ecx\n" /* line 2609 | boneMatrix */
        "movl (%ecx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "leal -0x4c(%ebp), %eax\n" /* line 2610 | skinRigidCmd */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll R_AddFrontendCmd\n"
        "jmp .Lfd1568_000d15de\n"
    );
}

/* line 1949 */
static __attribute__((naked))
int R_PreSkinStaticSurface(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex, const struct XModel *model, XSurface *xsurf, int surfaceIndex, int lod, qboolean *needSkinningSurf, byte *surfPos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1949 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x18(%ebp), %edi\n" /* xsurf */
        "movl 0x28(%ebp), %esi\n" /* surfPos */
        /* { scope 1 */
        "movl 0x14(%ebp), %eax\n" /* line 1970 | model */
        "movl %eax, (%esp)\n"
        "calll XModelGetSkins\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 1971 */
        "je .Lfd193e_000d1a2e\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1974 | surfaceIndex */
        "shll $2, %eax\n"
        "movl 0x20(%ebp), %ecx\n" /* lod */
        "movl (%edx, %ecx, 4), %edx\n"
        "addl %eax, %edx\n"
        "movl (%edx), %ebx\n" /* material */
        "movl 8(%ebp), %edx\n" /* line 1976 | sceneEnt */
        "addl 0x2c(%edx), %eax\n"
        "movl %ebx, (%eax)\n" /* material */
        "movl 0xc(%ebp), %ecx\n" /* line 1979 | ent */
        "cmpl $2, (%ecx)\n"
        "je .Lfd193e_000d19ac\n"
        ".Lfd193e_000d1982:\n"
        "movl 0x10(%edi), %eax\n" /* line 2027 | xsurf */
        "testl %eax, %eax\n"
        "je .Lfd193e_000d1a60\n"
        "movl $4, (%esi)\n" /* line 2074 | surfPos */
        "movl %edi, 4(%esi)\n" /* line 2075 | xsurf, surfPos */
        "movl 0x24(%ebp), %eax\n" /* line 2076 | needSkinningSurf */
        "movl $1, (%eax)\n"
        "movl $0x38, %eax\n"
        /* } scope */
        ".Lfd193e_000d19a4:\n"
        "addl $0x2c, %esp\n" /* line 2078 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd193e_000d19ac:\n"
        "movl 0x195f0ec, %eax\n" /* line 1979 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfd193e_000d1982\n"
        "movl %edi, (%esp)\n" /* xsurf */
        "calll XSurfaceGetBoneOffset\n"
        "addl $1, %eax\n"
        "je .Lfd193e_000d1982\n"
        "movl 0x195eec0, %eax\n" /* line 1981 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd193e_000d1a38\n"
        ".Lfd193e_000d19d3:\n"
        "movl 0x195eec8, %eax\n" /* line 1988 */
        "movl 0x3194(%eax), %eax\n"
        "movl 0x1c(%ebp), %edx\n" /* surfaceIndex */
        "shll $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* staticSurf */
        "movl 0x10(%ebp), %ecx\n" /* smodelIndex */
        "movl 4(%eax, %ecx, 8), %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* staticSurf */
        "movl 0x20(%ebp), %ecx\n" /* line 1994 | lod */
        "movl (%edx, %ecx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd193e_000d1bcb\n"
        ".Lfd193e_000d1a01:\n"
        "movl %eax, (%esp)\n" /* line 2003 */
        "calll R_UsedCachedStaticModelSurface\n"
        "movl $5, (%esi)\n" /* line 2007 | surfPos */
        "movl %edi, 4(%esi)\n" /* line 2008 | xsurf, surfPos */
        "movl 0x20(%ebp), %ebx\n" /* line 2009 | lod, material */
        "movl -0x1c(%ebp), %edx\n" /* staticSurf */
        "movl (%edx, %ebx, 4), %eax\n"
        "movl %eax, 8(%esi)\n" /* surfPos */
        "movl 0xc(%ebp), %ecx\n" /* line 2010 | ent */
        "movl %ecx, 0xc(%esi)\n" /* surfPos */
        "movl $0x10, %eax\n"
        "jmp .Lfd193e_000d19a4\n"
        ".Lfd193e_000d1a2e:\n"
        "xorl %eax, %eax\n" /* line 2077 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2078 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfd193e_000d1a38:\n"
        "movl 0x38(%ebx), %eax\n" /* line 1938 */
        "movl 0x34(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 1940 */
        "je .Lfd193e_000d1982\n"
        "cmpw $0, 6(%eax)\n"
        "je .Lfd193e_000d1982\n"
        /* } scope */
        "cmpb $0, 0xc(%eax)\n" /* line 1981 */
        "je .Lfd193e_000d1982\n"
        "jmp .Lfd193e_000d19d3\n"
        ".Lfd193e_000d1a60:\n"
        "movl 0x195ef14, %eax\n" /* line 2033 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfd193e_000d1b53\n"
        "movl 0x14(%edi), %eax\n" /* line 2035 | xsurf */
        "testl %eax, %eax\n"
        "je .Lfd193e_000d1b53\n"
        "movl $0, 0xc(%esi)\n" /* line 2037 | surfPos */
        "movl %edi, (%esp)\n" /* line 2038 | xsurf */
        "calll XSurfaceGetNumVerts\n"
        "movl %eax, %ecx\n" /* vertCount */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x195eed0, %eax\n" /* line 614 */
        "movl 0x2dc0(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lfd193e_000d1b0d\n"
        "movl 0x195eec0, %eax\n" /* line 1067 */
        "movl (%eax), %eax\n"
        "movl $0x24, %edx\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x40, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl 0x195eef4, %ebx\n" /* line 620 */
        "movl (%ebx), %eax\n"
        "movl 0x217c78(%eax), %eax\n"
        "imull %ecx, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InterlockedExchangeAdd\n"
        "movl (%ebx), %ebx\n" /* line 621 */
        "movl 0x217c78(%ebx), %edx\n"
        "movl 4(%edx), %ecx\n"
        "cmpl %ecx, (%edx)\n"
        "jle .Lfd193e_000d1b12\n"
        "cmpl %ecx, %eax\n" /* line 624 */
        "jle .Lfd193e_000d1c1e\n"
        ".Lfd193e_000d1ae8:\n"
        "movl (%ebx), %eax\n" /* line 627 */
        "cmpl warnCount, %eax\n"
        "je .Lfd193e_000d1b0d\n"
        "movl %eax, warnCount\n" /* line 629 */
        "movl $0x223f60, 4(%esp)\n" /* line 630 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        ".Lfd193e_000d1b0d:\n"
        "movl $0xffffffff, %eax\n"
        /* } scope */
        /* } scope */
        ".Lfd193e_000d1b12:\n"
        "movl %eax, 8(%esi)\n" /* line 2038 | surfPos */
        "testl %eax, %eax\n" /* line 2039 */
        "js .Lfd193e_000d1b53\n"
        "movl 0x195eef4, %eax\n" /* line 2040 */
        "movl (%eax), %eax\n"
        "movl 0x217c78(%eax), %edx\n"
        "movl 0x195eed0, %eax\n" /* line 2044 */
        "movl 0x2dc0(%eax), %eax\n"
        "addl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd193e_000d1b53\n"
        ".Lfd193e_000d1b37:\n"
        "movl $3, (%esi)\n" /* line 2066 | surfPos */
        "movl %edi, 4(%esi)\n" /* line 2067 | xsurf, surfPos */
        "movl 0x24(%ebp), %ebx\n" /* line 2068 | needSkinningSurf, material */
        "movl $1, (%ebx)\n" /* material */
        "movl $0x10, %eax\n"
        "jmp .Lfd193e_000d19a4\n"
        ".Lfd193e_000d1b53:\n"
        "movl $0xffffffff, 8(%esi)\n" /* line 2046 | surfPos */
        "movl %edi, (%esp)\n" /* line 2047 | xsurf */
        "calll XSurfaceGetNumVerts\n"
        "movl 0x195eec0, %edx\n" /* line 1067 */
        "movl (%edx), %edx\n"
        "movl $0x24, %ecx\n"
        "cmpl $2, 8(%edx)\n"
        "movl $0x40, %edx\n"
        "cmovnel %edx, %ecx\n"
        "imull %eax, %ecx\n" /* line 2047 */
        "movl 0x195eed0, %ebx\n" /* line 2049 | material */
        "movl 0x2dd4(%ebx), %edx\n" /* material */
        "leal (%ecx, %edx), %eax\n"
        "cmpl $0xa00000, %eax\n"
        "jle .Lfd193e_000d1bf8\n"
        "movl 0x195eef4, %eax\n" /* line 2051 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd193e_000d1a2e\n"
        "movl %eax, warnCount\n" /* line 2053 */
        "movl $0x223fa0, 4(%esp)\n" /* line 2054 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lfd193e_000d19a4\n"
        ".Lfd193e_000d1bcb:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1995 | material */
        "movl 0x10(%ebp), %ebx\n" /* smodelIndex, material */
        "movl %ebx, 8(%esp)\n" /* material */
        "movl %edi, 4(%esp)\n" /* xsurf */
        "movl %edx, (%esp)\n"
        "calll R_CacheStaticModelSurface\n"
        "movl 0x20(%ebp), %edx\n" /* lod */
        "movl -0x1c(%ebp), %ecx\n" /* staticSurf */
        "movl %eax, (%ecx, %edx, 4)\n"
        "testl %eax, %eax\n" /* line 2001 */
        "jne .Lfd193e_000d1a01\n"
        "jmp .Lfd193e_000d1982\n"
        ".Lfd193e_000d1bf8:\n"
        "addl 0x2dd0(%ebx), %edx\n" /* line 2059 | material */
        "movl %edx, 0xc(%esi)\n" /* surfPos */
        "addl %ecx, 0x2dd4(%ebx)\n" /* line 2060 | material */
        "movl 0xc(%esi), %eax\n" /* line 2061 | surfPos */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x24(%eax)\n"
        "jmp .Lfd193e_000d1b37\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfd193e_000d1c1e:\n"
        "movl %eax, 4(%esp)\n" /* line 625 */
        "movl %edx, (%esp)\n"
        "calll InterlockedExchange\n"
        "movl 0x195eef4, %ecx\n"
        "movl (%ecx), %ebx\n"
        "jmp .Lfd193e_000d1ae8\n"
    );
}

/* line 2276 */
static __attribute__((naked))
void R_SkinXModel(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2276 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xf0c, %esp\n"
        "movl 8(%ebp), %esi\n" /* sceneEnt */
        /* { scope 1: scale */
        "movl 0xc(%esi), %eax\n" /* line 2307 | sceneEnt */
        "cmpl $3, %eax\n"
        "jle .Lfd1c38_000d1c5a\n"
        /* } scope */
        ".Lfd1c38_000d1c4f:\n"
        "addl $0xf0c, %esp\n" /* line 2466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: scale */
        ".Lfd1c38_000d1c5a:\n"
        "leal 0xc(%esi), %eax\n" /* line 2310 | sceneEnt */
        "movl $2, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InterlockedCompareExchange\n"
        "cmpl $2, %eax\n"
        "je .Lfd1c38_000d1c8d\n"
        ".Lfd1c38_000d1c7a:\n"
        "movl 0xc(%esi), %eax\n" /* line 2312 | sceneEnt */
        "cmpl $3, %eax\n"
        "jle .Lfd1c38_000d1c7a\n"
        /* } scope */
        "addl $0xf0c, %esp\n" /* line 2466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: scale */
        ".Lfd1c38_000d1c8d:\n"
        "movl 4(%esi), %edi\n" /* line 2320 | sceneEnt, model */
        "movl %edi, (%esp)\n" /* line 2323 | model */
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "je .Lfd1c38_000d1cb7\n"
        "movl 0x195f0f0, %eax\n" /* line 2325 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfd1c38_000d1de2\n"
        ".Lfd1c38_000d1cae:\n"
        "movl $4, 0xc(%esi)\n" /* line 2271 */
        "jmp .Lfd1c38_000d1c4f\n"
        ".Lfd1c38_000d1cb7:\n"
        "movl %edi, (%esp)\n" /* line 2337 | model */
        "calll XModelNumBones\n"
        "movl %eax, -0xec8(%ebp)\n" /* boneCount */
        "movl 0xc(%ebp), %eax\n" /* line 2344 | ent */
        "movss 0x38(%eax), %xmm0\n"
        "movss %xmm0, -0xebc(%ebp)\n" /* scale */
        "movl %eax, %edx\n"
        "addl $0x3c, %edx\n"
        /* { scope 2 */
        "movl 0x195eec8, %ebx\n" /* line 249 */
        "leal 0x317c(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Vec3Distance\n"
        "fstps -0xedc(%ebp)\n"
        "movss -0xedc(%ebp), %xmm0\n"
        "mulss 0x3188(%ebx), %xmm0\n" /* line 250 */
        "addss 0x318c(%ebx), %xmm0\n"
        "movss -0xebc(%ebp), %xmm1\n" /* line 251 | scale */
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lfd1c38_000d1e1f\n"
        "jne .Lfd1c38_000d1e1f\n"
        /* } scope */
        ".Lfd1c38_000d1d2b:\n"
        "movss %xmm0, 4(%esp)\n" /* line 2345 */
        "movl %edi, (%esp)\n" /* model */
        "calll XModelGetLodForDist\n"
        "movl %eax, -0xec4(%ebp)\n" /* lod */
        "testl %eax, %eax\n" /* line 2346 */
        "js .Lfd1c38_000d1cae\n"
        "leal -0x20(%ebp), %eax\n" /* line 2353 | partBits */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xec4(%ebp), %eax\n" /* lod */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* surfaces */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* model */
        "calll XModelGetSurfaces\n"
        "movl %eax, -0xecc(%ebp)\n" /* surfaceCount */
        "movl 0x195f0f4, %eax\n" /* line 2358 */
        "addl $0x1a55c, %eax\n"
        "movl -0xecc(%ebp), %edx\n" /* surfaceCount */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll InterlockedExchangeAdd\n"
        "movl %eax, %edx\n"
        "movl -0xecc(%ebp), %eax\n" /* line 2360 | surfaceCount */
        "addl %edx, %eax\n"
        "cmpl $__mh_execute_header, %eax\n"
        "jbe .Lfd1c38_000d1e28\n"
        "movl 0x195f0f4, %eax\n" /* line 2362 */
        "movl $__mh_execute_header, 0x1a55c(%eax)\n"
        "movl 0x195eef4, %eax\n" /* line 2363 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1c38_000d1cae\n"
        "movl %eax, warnCount\n" /* line 2365 */
        "movl $0x223fd4, 4(%esp)\n" /* line 2366 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfd1c38_000d1cae\n"
        ".Lfd1c38_000d1de2:\n"
        "movl %edi, 4(%esp)\n" /* line 2328 | model */
        "movl 0x195eec8, %ebx\n" /* size */
        "movl 0x3110(%ebx), %eax\n" /* size */
        "movl %eax, (%esp)\n"
        "calll DObjSetModel\n"
        "movl 0x3110(%ebx), %ecx\n" /* line 2329 | size */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %esi, %eax\n" /* sceneEnt */
        "calll R_XModelDebugBoxes\n"
        "movl 0x3110(%ebx), %ecx\n" /* line 2330 | size */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %esi, %eax\n" /* sceneEnt */
        "calll R_XModelDebugAxes\n"
        "jmp .Lfd1c38_000d1cae\n"
        /* { scope 2 */
        ".Lfd1c38_000d1e1f:\n"
        "divss %xmm1, %xmm0\n" /* line 252 */
        "jmp .Lfd1c38_000d1d2b\n"
        /* } scope */
        ".Lfd1c38_000d1e28:\n"
        "movl 0x195f0f4, %eax\n" /* line 2374 */
        "leal 0x1a560(%eax, %edx, 4), %eax\n"
        "movl %eax, 0x2c(%esi)\n" /* sceneEnt */
        "movl $0, -0x1c(%ebp)\n" /* line 2376 | needSkinningSurf */
        "movl -0xecc(%ebp), %eax\n" /* line 2378 | surfaceCount */
        "testl %eax, %eax\n"
        "jle .Lfd1c38_000d1f2f\n"
        "xorl %ebx, %ebx\n" /* size */
        "leal -0xeb0(%ebp), %ecx\n" /* surfBuf */
        "movl %ecx, -0xec0(%ebp)\n" /* surfPos */
        "movl %ecx, %edx\n"
        "jmp .Lfd1c38_000d1e64\n"
        ".Lfd1c38_000d1e5e:\n"
        "movl -0xec0(%ebp), %edx\n" /* surfPos */
        ".Lfd1c38_000d1e64:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2380 | surfaces */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %edx, 0x20(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* needSkinningSurf */
        "movl %ecx, 0x1c(%esp)\n"
        "movl -0xec4(%ebp), %edx\n" /* lod */
        "movl %edx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n" /* size */
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* model */
        "movl 0x10(%ebp), %ecx\n" /* smodelIndex */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* sceneEnt */
        "calll R_PreSkinStaticSurface\n"
        "testl %eax, %eax\n" /* line 2381 */
        "je .Lfd1c38_000d1cae\n"
        "addl %eax, -0xec0(%ebp)\n" /* line 2383 | surfPos */
        "addl $1, %ebx\n" /* line 2378 | size */
        "cmpl %ebx, -0xecc(%ebp)\n" /* size, surfaceCount */
        "jne .Lfd1c38_000d1e5e\n"
        "movl -0xec0(%ebp), %ebx\n" /* surfPos, size */
        ".Lfd1c38_000d1ec0:\n"
        "leal -0xeb0(%ebp), %ecx\n" /* line 2392 | surfBuf */
        "subl %ecx, %ebx\n" /* size */
        "movl 0x195eef4, %edx\n" /* line 2393 */
        "movl (%edx), %eax\n"
        "addl $0x80008, %eax\n"
        "movl %ebx, 4(%esp)\n" /* size */
        "movl %eax, (%esp)\n"
        "calll InterlockedExchangeAdd\n"
        "movl %eax, %edx\n"
        "leal (%ebx, %eax), %eax\n" /* line 2395 | size */
        "cmpl $0x20000, %eax\n"
        "jbe .Lfd1c38_000d1f3f\n"
        "movl 0x195eef4, %ecx\n" /* line 2397 */
        "movl (%ecx), %eax\n"
        "movl $0x20000, 0x80008(%eax)\n"
        "movl (%ecx), %eax\n" /* line 2398 */
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1c38_000d1cae\n"
        "movl %eax, warnCount\n" /* line 2400 */
        "movl $0x224008, 4(%esp)\n" /* line 2401 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfd1c38_000d1cae\n"
        ".Lfd1c38_000d1f2f:\n"
        "leal -0xeb0(%ebp), %edx\n" /* line 2389 | surfBuf */
        "movl %edx, -0xec0(%ebp)\n" /* surfPos */
        "movl %edx, %ebx\n" /* size */
        "jmp .Lfd1c38_000d1ec0\n"
        ".Lfd1c38_000d1f3f:\n"
        "movl 0x195eef4, %ecx\n" /* line 2409 */
        "movl (%ecx), %eax\n"
        "addl $0x8000c, %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, 0x30(%esi)\n" /* sceneEnt */
        "movl %ebx, 8(%esp)\n" /* line 2410 | size */
        "leal -0xeb0(%ebp), %edx\n" /* surfBuf */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0xecc(%ebp), %ecx\n" /* line 2414 | surfaceCount */
        "movl %ecx, 0x10(%esi)\n" /* sceneEnt */
        "movl 0x195f0f8, %edx\n" /* line 2416 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd1c38_000d2043\n"
        ".Lfd1c38_000d1f83:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2423 | needSkinningSurf */
        "testl %eax, %eax\n"
        "je .Lfd1c38_000d1cae\n"
        "movl %edi, (%esp)\n" /* line 2429 | model */
        "calll XModelGetBasePose\n"
        "movl %eax, %ecx\n"
        "cmpl $1, -0xec8(%ebp)\n" /* line 2432 | boneCount */
        "je .Lfd1c38_000d20ab\n"
        "movl -0x20(%ebp), %edx\n" /* line 2442 | partBits */
        "movl (%edx), %eax\n"
        "movl %eax, -0xa4(%ebp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, -0xa0(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x98(%ebp)\n"
        "movl -0xecc(%ebp), %eax\n" /* line 2444 | surfaceCount */
        "testl %eax, %eax\n"
        "jle .Lfd1c38_000d20a0\n"
        "xorl %eax, %eax\n"
        "leal -0xb0(%ebp), %edx\n" /* skinCmd */
        ".Lfd1c38_000d1fe1:\n"
        "movb $0, 0x1e(%edx, %eax)\n" /* line 2445 */
        "addl $1, %eax\n" /* line 2444 */
        "cmpl %eax, -0xecc(%ebp)\n" /* surfaceCount */
        "jne .Lfd1c38_000d1fe1\n"
        ".Lfd1c38_000d1ff1:\n"
        "movl 0x30(%esi), %eax\n" /* line 2447 | sceneEnt */
        "movl %eax, -0xb0(%ebp)\n" /* skinCmd */
        "movzbl -0xecc(%ebp), %eax\n" /* line 2448 | surfaceCount */
        "movb %al, -0x94(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* line 2449 | ent */
        "movl %eax, -0xac(%ebp)\n"
        "movl %ecx, -0xa8(%ebp)\n" /* line 2450 */
        "movzbl -0xec8(%ebp), %ecx\n" /* line 2451 | boneCount */
        "movb %cl, -0x93(%ebp)\n"
        "xorl %eax, %eax\n" /* line 2462 */
        "cmpl $0xa, -0xecc(%ebp)\n" /* surfaceCount */
        "setg %al\n"
        "addl $6, %eax\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll R_AddFrontendCmd\n"
        "jmp .Lfd1c38_000d1cae\n"
        ".Lfd1c38_000d2043:\n"
        "movl %edi, 4(%esp)\n" /* line 2419 | model */
        "movl 0x195eec8, %ebx\n" /* size */
        "movl 0x3110(%ebx), %eax\n" /* size */
        "movl %eax, (%esp)\n"
        "calll DObjSetModel\n"
        "movl 0x3110(%ebx), %ebx\n" /* size */
        /* { scope 2 */
        "movl 0x195f0f8, %ecx\n" /* line 428 */
        "movl (%ecx), %eax\n"
        "testb $1, 8(%eax)\n"
        "jne .Lfd1c38_000d208a\n"
        ".Lfd1c38_000d206f:\n"
        "testb $2, 8(%eax)\n" /* line 431 */
        "je .Lfd1c38_000d1f83\n"
        "movl %ebx, %ecx\n" /* line 432 */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %esi, %eax\n"
        "calll R_XModelDebugAxes\n"
        "jmp .Lfd1c38_000d1f83\n"
        ".Lfd1c38_000d208a:\n"
        "movl %ebx, %ecx\n" /* line 429 */
        "movl 0xc(%ebp), %edx\n" /* ent */
        "movl %esi, %eax\n"
        "calll R_XModelDebugBoxes\n"
        "movl 0x195f0f8, %edx\n"
        "movl (%edx), %eax\n"
        "jmp .Lfd1c38_000d206f\n"
        ".Lfd1c38_000d20a0:\n"
        "leal -0xb0(%ebp), %edx\n" /* skinCmd */
        "jmp .Lfd1c38_000d1ff1\n"
        /* } scope */
        ".Lfd1c38_000d20ab:\n"
        "movl 0x30(%esi), %eax\n" /* line 2434 | sceneEnt */
        "movl %eax, -0x50(%ebp)\n" /* skinRigidCmd */
        "movl -0xecc(%ebp), %eax\n" /* line 2435 | surfaceCount */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 2436 | ent */
        "movl %edx, -0x48(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 2437 */
        "movl %eax, -0x44(%ebp)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "leal -0x50(%ebp), %eax\n" /* line 2438 | skinRigidCmd */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll R_AddFrontendCmd\n"
        "jmp .Lfd1c38_000d1cae\n"
    );
}

/* line 2651 */
void R_SkinStaticModel(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex)
{
    R_SkinXModel(sceneEnt, ent, smodelIndex);
}

/* line 2639 */
__attribute__((naked))
void R_SkinSceneEnt(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2639 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* sceneEnt */
        "movl 0xc(%ebp), %eax\n" /* ent */
        "cmpl $1, (%eax)\n" /* line 2641 */
        "je .Lfd2112_000d212f\n"
        "movl %eax, 0xc(%ebp)\n" /* line 2647 | ent */
        "movl %edx, 8(%ebp)\n" /* sceneEnt */
        "leave\n" /* line 2648 */
        "jmp R_SkinSceneDObj\n" /* line 2647 */
        ".Lfd2112_000d212f:\n"
        "movl $0xffffffff, 8(%esp)\n" /* line 2643 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll R_SkinXModel\n"
        "leave\n" /* line 2648 */
        "retl\n"
    );
}

/* line 1735 */
static __attribute__((naked))
void R_SkinXSurfaceSkinned(const DObjSkelMat *boneMatrix)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1735 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl %edx, -0xb4(%ebp)\n"
        /* { scope 1: localVertex, vertIndex, vertCount, inNormalColor, ... */
        "movl 4(%eax), %edi\n" /* line 1741 | skinnedSurf, xsurf */
        "movl 8(%eax), %edx\n" /* line 1763 | skinnedSurf */
        "testl %edx, %edx\n"
        "js .Lfd2146_000d260f\n"
        "movl 0x195eed0, %eax\n" /* line 1766 | skinnedSurf */
        "movl %edx, %ebx\n" /* skinVerticesOut */
        "addl 0x2dc0(%eax), %ebx\n" /* skinnedSurf, skinVerticesOut */
        ".Lfd2146_000d2173:\n"
        "movl %edi, (%esp)\n" /* line 1773 | xsurf */
        "calll XSurfaceGetBoneOffset\n"
        "movl %eax, -0xb0(%ebp)\n" /* skinnedSurf, boneOffset */
        "movl 0x195eec0, %eax\n" /* line 1776 | skinnedSurf */
        "movl (%eax), %eax\n" /* skinnedSurf */
        "cmpl $2, 8(%eax)\n" /* skinnedSurf */
        "je .Lfd2146_000d246b\n"
        "cmpl $-1, -0xb0(%ebp)\n" /* line 1802 | boneOffset */
        "je .Lfd2146_000d2617\n"
        "movl %ebx, %esi\n" /* line 1821 | skinVerticesOut, vertex */
        /* { scope 2: __A */
        "movl %edi, (%esp)\n" /* line 1221 | weightCount */
        "calll XSurfaceGetVertexInfoArray\n"
        "movl %eax, %ebx\n" /* matrixValues */
        "movl %edi, (%esp)\n" /* weightCount */
        "calll XSurfaceGetNumVerts\n"
        "movl %eax, %edi\n" /* matrixValues, weightCount */
        "movl -0xb4(%ebp), %edx\n" /* mat */
        "addl -0xb0(%ebp), %edx\n" /* boneOffset, mat */
        "testl %eax, %eax\n" /* matrixValues */
        "jle .Lfd2146_000d2460\n"
        "xorl %ecx, %ecx\n"
        ".Lfd2146_000d21cb:\n"
        "movl 0xc(%ebx), %eax\n" /* matrixValues */
        "movl %eax, -0x3c(%ebp)\n" /* matrixValues */
        "movl 0x1c(%ebx), %eax\n" /* matrixValues */
        "movl %eax, -0x38(%ebp)\n" /* matrixValues */
        "movl 0x2c(%ebx), %eax\n" /* matrixValues */
        "movl %eax, -0x34(%ebp)\n" /* matrixValues */
        /* { scope 3 */
        "movss (%ebx), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ebx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movss (%ebx), %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ebx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss (%ebx), %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ebx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        "movss 0x10(%ebx), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 0x14(%ebx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x18(%ebx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movss 0x10(%ebx), %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "movss 0x14(%ebx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x18(%ebx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss 0x10(%ebx), %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "movss 0x14(%ebx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x18(%ebx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movss 0x20(%ebx), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 0x24(%ebx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x28(%ebx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss 0x20(%ebx), %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "movss 0x24(%ebx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x28(%ebx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 0x20(%ebx), %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "movss 0x24(%ebx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x28(%ebx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movss 0x30(%ebx), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 0x34(%ebx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ebx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x30(%edx), %xmm1\n"
        "movss %xmm1, -0x58(%ebp)\n" /* localVertex */
        "movss 0x30(%ebx), %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "movss 0x34(%ebx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ebx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x34(%edx), %xmm1\n"
        "movss %xmm1, -0x54(%ebp)\n"
        "movss 0x30(%ebx), %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "movss 0x34(%ebx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ebx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x38(%edx), %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "movl $0x3f800000, -0x4c(%ebp)\n"
        /* } scope */
        "addl $0x40, %ebx\n"
        "movl -0x58(%ebp), %eax\n" /* localVertex, matrixValues */
        "movl %eax, (%esi)\n" /* matrixValues, vertex */
        "movl -0x54(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 4(%esi)\n" /* matrixValues, vertex */
        "movl -0x50(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 8(%esi)\n" /* matrixValues, vertex */
        "movl -0x4c(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0xc(%esi)\n" /* matrixValues, vertex */
        "movl -0x48(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x10(%esi)\n" /* matrixValues, vertex */
        "movl -0x44(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x14(%esi)\n" /* matrixValues, vertex */
        "movl -0x40(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x18(%esi)\n" /* matrixValues, vertex */
        "movl -0x3c(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x1c(%esi)\n" /* matrixValues, vertex */
        "movl -0x38(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x20(%esi)\n" /* matrixValues, vertex */
        "movl -0x34(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x24(%esi)\n" /* matrixValues, vertex */
        "movl -0x30(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x28(%esi)\n" /* matrixValues, vertex */
        "movl -0x2c(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x2c(%esi)\n" /* matrixValues, vertex */
        "movl -0x28(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x30(%esi)\n" /* matrixValues, vertex */
        "movl -0x24(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x34(%esi)\n" /* matrixValues, vertex */
        "movl -0x20(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x38(%esi)\n" /* matrixValues, vertex */
        "movl -0x1c(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x3c(%esi)\n" /* matrixValues, vertex */
        "addl $1, %ecx\n"
        "addl $0x40, %esi\n" /* vertex */
        "cmpl %ecx, %edi\n" /* weightCount */
        "jne .Lfd2146_000d21cb\n"
        /* } scope */
        /* } scope */
        ".Lfd2146_000d2460:\n"
        "addl $0xbc, %esp\n" /* line 1823 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: localVertex, vertIndex, vertCount, inNormalColor, ... */
        ".Lfd2146_000d246b:\n"
        "cmpl $-1, -0xb0(%ebp)\n" /* line 1778 | boneOffset */
        "je .Lfd2146_000d282d\n"
        "movl %ebx, %esi\n" /* line 1797 | skinVerticesOut, vertex */
        /* { scope 2: __A */
        "movl %edi, (%esp)\n" /* line 1221 | weightCount */
        "calll XSurfaceGetVertexInfoArray\n"
        "movl %eax, %ebx\n" /* matrixValues */
        "movl %edi, (%esp)\n" /* weightCount */
        "calll XSurfaceGetNumVerts\n"
        "movl %eax, %edi\n" /* matrixValues, weightCount */
        "movl -0xb4(%ebp), %edx\n" /* mat */
        "addl -0xb0(%ebp), %edx\n" /* boneOffset, mat */
        "testl %eax, %eax\n" /* matrixValues */
        "jle .Lfd2146_000d2460\n"
        "xorl %ecx, %ecx\n"
        ".Lfd2146_000d24a0:\n"
        "movl 0xc(%ebx), %eax\n" /* matrixValues */
        "movl %eax, -0x40(%ebp)\n" /* matrixValues */
        "movl 0x1c(%ebx), %eax\n" /* matrixValues */
        "movl %eax, -0x3c(%ebp)\n" /* matrixValues */
        "movl 0x2c(%ebx), %eax\n" /* matrixValues */
        "movl %eax, -0x38(%ebp)\n" /* matrixValues */
        /* { scope 3 */
        "movss (%ebx), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ebx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x4c(%ebp)\n"
        "movss (%ebx), %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ebx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movss (%ebx), %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ebx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss 0x30(%ebx), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss 0x34(%ebx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ebx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x30(%edx), %xmm1\n"
        "movss %xmm1, -0x58(%ebp)\n" /* localVertex */
        "movss 0x30(%ebx), %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "movss 0x34(%ebx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ebx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x34(%edx), %xmm1\n"
        "movss %xmm1, -0x54(%ebp)\n"
        "movss 0x30(%ebx), %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "movss 0x34(%ebx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ebx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x38(%edx), %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n"
        /* } scope */
        "addl $0x40, %ebx\n"
        "movl -0x58(%ebp), %eax\n" /* localVertex, matrixValues */
        "movl %eax, (%esi)\n" /* matrixValues, vertex */
        "movl -0x54(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 4(%esi)\n" /* matrixValues, vertex */
        "movl -0x50(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 8(%esi)\n" /* matrixValues, vertex */
        "movl -0x4c(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0xc(%esi)\n" /* matrixValues, vertex */
        "movl -0x48(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x10(%esi)\n" /* matrixValues, vertex */
        "movl -0x44(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x14(%esi)\n" /* matrixValues, vertex */
        "movl -0x40(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x18(%esi)\n" /* matrixValues, vertex */
        "movl -0x3c(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x1c(%esi)\n" /* matrixValues, vertex */
        "movl -0x38(%ebp), %eax\n" /* matrixValues */
        "movl %eax, 0x20(%esi)\n" /* matrixValues, vertex */
        "addl $1, %ecx\n"
        "addl $0x24, %esi\n" /* vertex */
        "cmpl %ecx, %edi\n" /* weightCount */
        "jne .Lfd2146_000d24a0\n"
        /* } scope */
        /* } scope */
        "addl $0xbc, %esp\n" /* line 1823 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: localVertex, vertIndex, vertCount, inNormalColor, ... */
        ".Lfd2146_000d260f:\n"
        "movl 0xc(%eax), %ebx\n" /* line 1770 | skinnedSurf, skinVerticesOut */
        "jmp .Lfd2146_000d2173\n"
        ".Lfd2146_000d2617:\n"
        "movl %ebx, %esi\n" /* line 1813 | skinVerticesOut, vertex */
        /* { scope 2: __A */
        "movl %edi, (%esp)\n" /* line 1221 | weightCount */
        "calll XSurfaceGetVertexInfoArray\n"
        "movl %eax, %ebx\n" /* matrixValues */
        "movl %edi, (%esp)\n" /* weightCount */
        "calll XSurfaceGetNumVerts\n"
        "movl %eax, -0x9c(%ebp)\n" /* matrixValues, vertCount */
        "emms\n"
        "testl %eax, %eax\n" /* matrixValues */
        "jle .Lfd2146_000d2460\n"
        "movl $0, -0xa0(%ebp)\n" /* vertIndex */
        "jmp .Lfd2146_000d26a1\n"
        ".Lfd2146_000d2647:\n"
        "addl $0x40, %ebx\n"
        /* { scope 3 */
        ".Lfd2146_000d264a:\n"
        "movaps -0x68(%ebp), %xmm0\n" /* __A */
        "movntps %xmm0, (%esi)\n" /* vertex */
        /* } scope */
        "movaps -0x88(%ebp), %xmm0\n" /* localNormal */
        "shufps $0xfa, -0x98(%ebp), %xmm0\n" /* inNormalColor */
        "movaps -0x88(%ebp), %xmm1\n" /* localNormal */
        "shufps $0xd4, %xmm0, %xmm1\n"
        "movntps %xmm1, 0x10(%esi)\n" /* vertex */
        "shufps $0x4e, %xmm7, %xmm4\n" /* __A */
        "movntps %xmm4, 0x20(%esi)\n" /* vertex */
        "shufps $0x22, -0x78(%ebp), %xmm7\n" /* localTangent, __A */
        "shufps $0x9c, -0x78(%ebp), %xmm7\n" /* localTangent, __A */
        "movntps %xmm7, 0x30(%esi)\n" /* __A, vertex */
        "addl $1, -0xa0(%ebp)\n" /* vertIndex */
        "addl $0x40, %esi\n" /* vertex */
        "movl -0xa0(%ebp), %eax\n" /* vertIndex, matrixValues */
        "cmpl %eax, -0x9c(%ebp)\n" /* matrixValues, vertCount */
        "je .Lfd2146_000d2460\n"
        ".Lfd2146_000d26a1:\n"
        "movswl 0x3e(%ebx), %eax\n" /* matrixValues */
        "addl -0xb4(%ebp), %eax\n" /* matrixValues */
        "prefetchnta 0x80(%ebx)\n"
        "movaps (%ebx), %xmm0\n"
        "movaps %xmm0, -0x98(%ebp)\n" /* inNormalColor */
        "movaps 0x10(%ebx), %xmm3\n"
        "movaps 0x20(%ebx), %xmm2\n"
        "movaps 0x30(%ebx), %xmm0\n"
        /* { scope 3 */
        "movaps (%eax), %xmm6\n"
        "movaps 0x10(%eax), %xmm4\n"
        "movaps 0x20(%eax), %xmm5\n"
        /* } scope */
        "movaps %xmm0, %xmm1\n"
        "shufps $0, %xmm0, %xmm1\n"
        "mulps %xmm6, %xmm1\n"
        "movaps %xmm1, -0x68(%ebp)\n" /* __A */
        "movaps %xmm0, %xmm1\n"
        "shufps $0x55, %xmm0, %xmm1\n"
        "mulps %xmm4, %xmm1\n"
        "shufps $0xaa, %xmm0, %xmm0\n"
        "mulps %xmm5, %xmm0\n"
        "addps 0x30(%eax), %xmm0\n"
        "addps -0x68(%ebp), %xmm1\n" /* __A */
        "addps %xmm1, %xmm0\n"
        "movaps %xmm0, -0x68(%ebp)\n" /* __A */
        "movaps -0x98(%ebp), %xmm0\n" /* inNormalColor */
        "shufps $0, %xmm0, %xmm0\n"
        "mulps %xmm6, %xmm0\n"
        "movaps %xmm0, -0x88(%ebp)\n" /* localNormal */
        "movaps -0x98(%ebp), %xmm1\n" /* inNormalColor */
        "shufps $0x55, %xmm1, %xmm1\n"
        "mulps %xmm4, %xmm1\n"
        "movaps -0x98(%ebp), %xmm0\n" /* inNormalColor */
        "shufps $0xaa, %xmm0, %xmm0\n"
        "mulps %xmm5, %xmm0\n"
        "addps -0x88(%ebp), %xmm1\n" /* localNormal */
        "addps %xmm1, %xmm0\n"
        "movaps %xmm0, -0x88(%ebp)\n" /* localNormal */
        "movaps %xmm3, %xmm7\n" /* __A */
        "shufps $0, %xmm3, %xmm7\n" /* __A */
        "mulps %xmm6, %xmm7\n" /* __A */
        "movaps %xmm3, %xmm1\n"
        "shufps $0x55, %xmm3, %xmm1\n"
        "mulps %xmm4, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "shufps $0xaa, %xmm3, %xmm0\n"
        "mulps %xmm5, %xmm0\n"
        "addps %xmm1, %xmm7\n" /* __A */
        "addps %xmm0, %xmm7\n" /* __A */
        "movaps %xmm2, %xmm1\n"
        "shufps $0, %xmm2, %xmm1\n"
        "mulps %xmm1, %xmm6\n"
        "movaps %xmm2, %xmm0\n"
        "shufps $0x55, %xmm2, %xmm0\n"
        "mulps %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm0\n"
        "shufps $0xaa, %xmm2, %xmm0\n"
        "mulps %xmm0, %xmm5\n"
        "addps %xmm6, %xmm4\n"
        "addps %xmm4, %xmm5\n"
        "movaps %xmm5, -0x78(%ebp)\n" /* localTangent */
        "movaps %xmm3, %xmm4\n"
        "unpckhps %xmm2, %xmm4\n"
        "movzbl 0x3c(%ebx), %eax\n" /* matrixValues */
        "movzbl %al, %edi\n" /* matrixValues, weightCount */
        "testb %al, %al\n" /* matrixValues */
        "je .Lfd2146_000d2647\n"
        "movzbl 0x3d(%ebx), %eax\n" /* matrixValues */
        "cvtsi2ssl %eax, %xmm0\n" /* matrixValues */
        "mulss 0x2ed5c4, %xmm0\n" /* 0.00390625f */
        "shufps $0, %xmm0, %xmm0\n"
        "mulps -0x68(%ebp), %xmm0\n" /* __A */
        "movaps %xmm0, -0x68(%ebp)\n" /* __A */
        "leal 0x40(%ebx), %ecx\n"
        "xorl %ebx, %ebx\n"
        "movss 0x2ed854, %xmm5\n" /* 1.52587890625e-05f */
        ".Lfd2146_000d27cd:\n"
        "movswl 0xc(%ecx), %edx\n" /* mat */
        "addl -0xb4(%ebp), %edx\n" /* mat */
        "movaps (%ecx), %xmm0\n"
        "movzwl 0xe(%ecx), %eax\n" /* matrixValues */
        "cvtsi2ssl %eax, %xmm2\n" /* matrixValues */
        "mulss %xmm5, %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "shufps $0, %xmm0, %xmm1\n"
        "mulps (%edx), %xmm1\n"
        "movaps %xmm0, %xmm3\n"
        "shufps $0x55, %xmm0, %xmm3\n"
        "mulps 0x10(%edx), %xmm3\n"
        "shufps $0xaa, %xmm0, %xmm0\n"
        "mulps 0x20(%edx), %xmm0\n"
        "addps 0x30(%edx), %xmm0\n"
        "addps %xmm3, %xmm1\n"
        "addps %xmm0, %xmm1\n"
        "shufps $0, %xmm2, %xmm2\n"
        "mulps %xmm1, %xmm2\n"
        "addps -0x68(%ebp), %xmm2\n" /* __A */
        "movaps %xmm2, -0x68(%ebp)\n" /* __A */
        "addl $0x10, %ecx\n"
        "addl $1, %ebx\n"
        "cmpl %ebx, %edi\n" /* weightCount */
        "jne .Lfd2146_000d27cd\n"
        "movl %ecx, %ebx\n"
        "jmp .Lfd2146_000d264a\n"
        /* } scope */
        ".Lfd2146_000d282d:\n"
        "movl %ebx, -0xa4(%ebp)\n" /* line 1789 | skinVerticesOut, vertex */
        /* { scope 2: __A */
        "movl %edi, (%esp)\n" /* line 1169 | weightCount */
        "calll XSurfaceGetVertexInfoArray\n"
        "movl %eax, %esi\n" /* vertex */
        "movl %edi, (%esp)\n" /* line 1172 | weightCount */
        "calll XSurfaceGetNumVerts\n"
        "movl %eax, -0xa8(%ebp)\n" /* vertCount */
        "testl %eax, %eax\n" /* line 1177 */
        "jle .Lfd2146_000d2460\n"
        "movl $0, -0xac(%ebp)\n" /* vertIndex */
        "jmp .Lfd2146_000d28d9\n"
        ".Lfd2146_000d285f:\n"
        "leal 0x40(%esi), %esi\n" /* line 1217 | vertex */
        /* { scope 3 */
        ".Lfd2146_000d2862:\n"
        "movaps %xmm6, -0x58(%ebp)\n" /* line 1220 | __A, localVertex */
        /* } scope */
        /* { scope 3 */
        "movups %xmm7, -0x4c(%ebp)\n" /* line 1221 | __A */
        /* } scope */
        "movl 0xc(%ebx), %eax\n" /* matrixValues */
        "movl %eax, -0x40(%ebp)\n" /* matrixValues */
        "movl 0x1c(%ebx), %eax\n" /* line 1223 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x2c(%ebx), %eax\n" /* line 1224 */
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x58(%ebp), %eax\n" /* line 1226 | localVertex */
        "movl -0xa4(%ebp), %edx\n" /* vertex */
        "movl %eax, (%edx)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "addl $1, -0xac(%ebp)\n" /* line 1177 | vertIndex */
        "addl $0x24, %edx\n"
        "movl %edx, -0xa4(%ebp)\n" /* vertex */
        "movl -0xac(%ebp), %eax\n" /* vertIndex */
        "cmpl %eax, -0xa8(%ebp)\n" /* vertCount */
        "je .Lfd2146_000d2460\n"
        ".Lfd2146_000d28d9:\n"
        "movl %esi, %ebx\n" /* line 1179 | vertex */
        "movswl 0x3e(%esi), %eax\n" /* vertex */
        "addl -0xb4(%ebp), %eax\n"
        /* { scope 3 */
        "movaps (%eax), %xmm5\n" /* line 659 */
        "movaps 0x10(%eax), %xmm3\n" /* line 660 */
        "movaps 0x20(%eax), %xmm4\n" /* line 661 */
        /* } scope */
        "movaps (%esi), %xmm1\n" /* line 1184 | vertex */
        "movaps 0x30(%esi), %xmm0\n" /* line 1185 | vertex */
        "movaps %xmm0, %xmm6\n" /* line 669 */
        "shufps $0, %xmm0, %xmm6\n"
        "mulps %xmm5, %xmm6\n" /* line 677 */
        "movaps %xmm0, %xmm2\n"
        "shufps $0x55, %xmm0, %xmm2\n"
        "mulps %xmm3, %xmm2\n" /* line 678 */
        "shufps $0xaa, %xmm0, %xmm0\n"
        "mulps %xmm4, %xmm0\n" /* line 679 */
        "addps 0x30(%eax), %xmm0\n" /* line 681 */
        "addps %xmm2, %xmm6\n"
        "addps %xmm0, %xmm6\n"
        "movaps %xmm1, %xmm7\n"
        "shufps $0, %xmm1, %xmm7\n"
        "mulps %xmm5, %xmm7\n"
        "movaps %xmm1, %xmm0\n"
        "shufps $0x55, %xmm1, %xmm0\n"
        "mulps %xmm0, %xmm3\n"
        "shufps $0xaa, %xmm1, %xmm1\n"
        "mulps %xmm1, %xmm4\n"
        "addps %xmm3, %xmm7\n"
        "addps %xmm4, %xmm7\n"
        "movzbl 0x3c(%esi), %eax\n" /* line 1193 | vertex */
        "movzbl %al, %edi\n" /* weightCount */
        "testb %al, %al\n" /* line 1194 */
        "je .Lfd2146_000d285f\n"
        "movzbl 0x3d(%esi), %eax\n" /* line 1196 | vertex */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed5c4, %xmm0\n" /* 0.00390625f */
        "shufps $0, %xmm0, %xmm0\n"
        "mulps %xmm0, %xmm6\n"
        "leal 0x40(%esi), %ecx\n" /* line 1198 | vertex */
        "xorl %esi, %esi\n" /* vertex */
        "movss 0x2ed854, %xmm5\n" /* 1.52587890625e-05f */
        ".Lfd2146_000d2970:\n"
        "movswl 0xc(%ecx), %edx\n" /* line 1202 */
        "addl -0xb4(%ebp), %edx\n"
        "movaps (%ecx), %xmm0\n" /* line 1205 */
        "movzwl 0xe(%ecx), %eax\n" /* line 1207 */
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss %xmm5, %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "shufps $0, %xmm0, %xmm1\n"
        "mulps (%edx), %xmm1\n"
        "movaps %xmm0, %xmm3\n"
        "shufps $0x55, %xmm0, %xmm3\n"
        "mulps 0x10(%edx), %xmm3\n"
        "shufps $0xaa, %xmm0, %xmm0\n"
        "mulps 0x20(%edx), %xmm0\n"
        "addps 0x30(%edx), %xmm0\n"
        "addps %xmm3, %xmm1\n"
        "addps %xmm0, %xmm1\n"
        "shufps $0, %xmm2, %xmm2\n"
        "mulps %xmm1, %xmm2\n"
        "addps %xmm2, %xmm6\n" /* line 1210 */
        "addl $0x10, %ecx\n"
        "addl $1, %esi\n" /* vertex */
        "cmpl %esi, %edi\n" /* line 1200 | vertex, weightCount */
        "jne .Lfd2146_000d2970\n"
        "movl %ecx, %esi\n" /* vertex */
        "jmp .Lfd2146_000d2862\n"
    );
}

/* line 2224 */
__attribute__((naked))
void R_SkinXModelCmd(SkinXModelCmd *skinCmd, int context)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2224 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* context */
        /* { scope 1: boneCount, refEnt */
        "leal (%eax, %eax, 4), %eax\n" /* line 2234 */
        "shll $0xd, %eax\n"
        "movl 0x195f0fc, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* matArray */
        /* { scope 2: boneMatrix */
        "movl 8(%ebp), %eax\n" /* line 2201 | skinCmd */
        "movzbl 0x1d(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* boneCount */
        "movl 8(%ebp), %edx\n" /* line 2205 | skinCmd */
        "movl 8(%edx), %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* line 2211 | boneCount */
        "testl %ecx, %ecx\n"
        "jle .Lfd29cc_000d2c29\n"
        "movl -0x34(%ebp), %ebx\n" /* matArray, rigidSurf */
        "xorl %edi, %edi\n" /* boneIndex */
        "leal 0x10(%eax), %esi\n" /* scale */
        ".Lfd29cc_000d2a0c:\n"
        "movl %edi, %eax\n" /* line 2217 | boneIndex */
        "sarl $5, %eax\n"
        "movl %edi, %ecx\n" /* boneIndex */
        "andl $0x1f, %ecx\n"
        "movl 8(%ebp), %edx\n" /* skinCmd */
        "movl 0xc(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lfd29cc_000d2b52\n"
        /* { scope 3: xx, yy, zw */
        /* { scope 4 */
        "movss 0xc(%esi), %xmm1\n" /* line 350 | scale */
        /* { scope 5 */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "mulss -0x10(%esi), %xmm3\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss -0xc(%esi), %xmm6\n"
        "mulss -8(%esi), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 352 */
        "mulss -0x10(%esi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* xx */
        "movss -0xc(%esi), %xmm5\n" /* line 353 */
        "movaps %xmm3, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "movss -8(%esi), %xmm2\n" /* line 354 */
        "movaps %xmm3, %xmm7\n"
        "mulss %xmm2, %xmm7\n"
        "movss -4(%esi), %xmm0\n" /* line 355 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm6, %xmm5\n" /* line 357 */
        "movss %xmm5, -0x28(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm5\n" /* line 358 */
        "mulss %xmm2, %xmm5\n"
        "mulss %xmm0, %xmm6\n" /* line 359 */
        "mulss %xmm1, %xmm2\n" /* line 361 */
        "mulss %xmm0, %xmm1\n" /* line 362 */
        "movss %xmm1, -0x3c(%ebp)\n" /* zw */
        "movss -0x28(%ebp), %xmm0\n" /* line 364 | yy */
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, (%ebx)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 365 | zw */
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movaps %xmm7, %xmm0\n" /* line 366 */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "movl $0, 0xc(%ebx)\n" /* line 367 */
        "subss -0x3c(%ebp), %xmm4\n" /* line 369 | zw */
        "movss %xmm4, 0x10(%ebx)\n"
        "addss -0x2c(%ebp), %xmm2\n" /* line 370 | xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 0x14(%ebx)\n"
        "movaps %xmm3, %xmm0\n" /* line 371 */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, 0x18(%ebx)\n"
        "movl $0, 0x1c(%ebx)\n" /* line 372 */
        "addss %xmm6, %xmm7\n" /* line 374 */
        "movss %xmm7, 0x20(%ebx)\n"
        "subss %xmm3, %xmm5\n" /* line 375 */
        "movss %xmm5, 0x24(%ebx)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 376 | xx */
        "addss -0x28(%ebp), %xmm0\n" /* yy */
        "movss %xmm0, -0x2c(%ebp)\n" /* xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x2c(%ebp), %xmm0\n" /* xx */
        "movss %xmm0, 0x28(%ebx)\n"
        "movl $0, 0x2c(%ebx)\n" /* line 377 */
        "leal 0x30(%ebx), %edx\n" /* line 383 | to */
        /* { scope 5 */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, 0x30(%ebx)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $0x3f800000, 0x3c(%ebx)\n" /* line 384 */
        /* } scope */
        /* } scope */
        ".Lfd29cc_000d2b52:\n"
        "addl $1, %edi\n" /* line 2211 | boneIndex */
        "addl $0x20, %esi\n" /* scale */
        "addl $0x40, %ebx\n" /* rigidSurf */
        "cmpl %edi, -0x30(%ebp)\n" /* boneIndex, boneCount */
        "jne .Lfd29cc_000d2a0c\n"
        "movl 8(%ebp), %eax\n" /* skinCmd */
        /* } scope */
        ".Lfd29cc_000d2b67:\n"
        "movl (%eax), %edi\n" /* line 2238 | surfPos */
        "cmpb $0, 0x1c(%eax)\n" /* line 2239 */
        "je .Lfd29cc_000d2c0f\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x38(%ebp)\n" /* surfaceIndex */
        "movl 8(%ebp), %edx\n" /* skinCmd */
        "jmp .Lfd29cc_000d2b99\n"
        /* { scope 2: boneMatrix */
        /* { scope 3: xx, yy, zw */
        ".Lfd29cc_000d2b82:\n"
        "addl $0x10, %edi\n" /* line 2148 */
        /* } scope */
        /* } scope */
        ".Lfd29cc_000d2b85:\n"
        "addl $1, -0x38(%ebp)\n" /* line 2239 | surfaceIndex */
        "addl $1, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* skinCmd */
        "movzbl 0x1c(%edx), %eax\n"
        "cmpl %eax, -0x38(%ebp)\n" /* surfaceIndex */
        "jge .Lfd29cc_000d2c0f\n"
        ".Lfd29cc_000d2b99:\n"
        "movl 4(%edx), %edx\n" /* line 2240 */
        "movl %edx, -0x24(%ebp)\n" /* refEnt */
        /* { scope 2: boneMatrix */
        /* { scope 3: xx, yy, zw */
        "movl -0x1c(%ebp), %edx\n" /* line 2134 */
        "movzbl 0x1e(%edx), %eax\n"
        "shll $6, %eax\n"
        "addl -0x34(%ebp), %eax\n" /* matArray */
        "movl %eax, -0x20(%ebp)\n" /* boneMatrix */
        "movl (%edi), %eax\n" /* line 2136 */
        "cmpl $3, %eax\n"
        "je .Lfd29cc_000d2c17\n"
        "cmpl $5, %eax\n" /* line 2145 */
        "je .Lfd29cc_000d2b82\n"
        "movl %edi, %ebx\n" /* line 2155 | rigidSurf */
        "addl $0x38, %edi\n" /* line 2156 */
        "movl -0x24(%ebp), %eax\n" /* line 2157 | refEnt */
        "movl 0x38(%eax), %esi\n" /* scale */
        /* { scope 4 */
        /* { scope 5 */
        "movl 4(%ebx), %eax\n" /* line 1727 */
        "movl %eax, (%esp)\n"
        "calll XSurfaceGetBoneOffset\n"
        "addl $8, %ebx\n" /* line 1731 */
        "movl %ebx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl -0x24(%ebp), %edx\n" /* refEnt */
        "addl $0x14, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl -0x24(%ebp), %edx\n" /* refEnt */
        "addl $0x3c, %edx\n"
        "movl %edx, 4(%esp)\n"
        "addl -0x20(%ebp), %eax\n" /* boneMatrix */
        "movl %eax, (%esp)\n"
        "calll R_GetRigidTransform\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $1, -0x38(%ebp)\n" /* line 2239 | surfaceIndex */
        "addl $1, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* skinCmd */
        "movzbl 0x1c(%edx), %eax\n"
        "cmpl %eax, -0x38(%ebp)\n" /* surfaceIndex */
        "jl .Lfd29cc_000d2b99\n"
        /* } scope */
        ".Lfd29cc_000d2c0f:\n"
        "addl $0x5c, %esp\n" /* line 2243 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: boneCount, refEnt */
        /* { scope 2: boneMatrix */
        /* { scope 3: xx, yy, zw */
        ".Lfd29cc_000d2c17:\n"
        "movl %edi, %eax\n" /* line 2138 */
        "addl $0x10, %edi\n" /* line 2139 */
        "movl -0x20(%ebp), %edx\n" /* line 2140 | boneMatrix */
        "calll R_SkinXSurfaceSkinned\n"
        "jmp .Lfd29cc_000d2b85\n"
        ".Lfd29cc_000d2c29:\n"
        "movl %edx, %eax\n"
        "jmp .Lfd29cc_000d2b67\n"
    );
}

/* line 2162 */
__attribute__((naked))
void R_SkinRigidXModelCmd(SkinRigidXModelCmd *skinRigidCmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2162 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 2172 | skinRigidCmd */
        "addl $0xc, %eax\n"
        /* { scope 2: xx, yy, zw */
        /* { scope 3: scale */
        "movss 0x1c(%eax), %xmm1\n" /* line 350 | scale */
        /* { scope 4 */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "movl 8(%ebp), %edx\n" /* skinRigidCmd */
        "mulss 0xc(%edx), %xmm3\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%eax), %xmm6\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 352 */
        "mulss 0xc(%edx), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n" /* xx */
        "movss 4(%eax), %xmm4\n" /* line 353 */
        "movaps %xmm3, %xmm5\n"
        "mulss %xmm4, %xmm5\n"
        "movss 8(%eax), %xmm2\n" /* line 354 */
        "movaps %xmm3, %xmm7\n"
        "mulss %xmm2, %xmm7\n"
        "movss 0xc(%eax), %xmm0\n" /* line 355 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm6, %xmm4\n" /* line 357 */
        "movss %xmm4, -0x70(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm4\n" /* line 358 */
        "mulss %xmm2, %xmm4\n"
        "mulss %xmm0, %xmm6\n" /* line 359 */
        "mulss %xmm1, %xmm2\n" /* line 361 */
        "mulss %xmm0, %xmm1\n" /* line 362 */
        "movss %xmm1, -0x7c(%ebp)\n" /* zw */
        "movss -0x70(%ebp), %xmm0\n" /* line 364 | yy */
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x68(%ebp)\n" /* buf */
        "movss -0x7c(%ebp), %xmm0\n" /* line 365 | zw */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "movaps %xmm7, %xmm0\n" /* line 366 */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "xorl %eax, %eax\n" /* line 367 */
        "movl %eax, -0x5c(%ebp)\n"
        "subss -0x7c(%ebp), %xmm5\n" /* line 369 | zw */
        "movss %xmm5, -0x58(%ebp)\n"
        "addss -0x74(%ebp), %xmm2\n" /* line 370 | xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 371 */
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movl %eax, -0x4c(%ebp)\n" /* line 372 */
        "addss %xmm6, %xmm7\n" /* line 374 */
        "movss %xmm7, -0x48(%ebp)\n"
        "subss %xmm3, %xmm4\n" /* line 375 */
        "movss %xmm4, -0x44(%ebp)\n"
        "movss -0x74(%ebp), %xmm0\n" /* line 376 | xx */
        "addss -0x70(%ebp), %xmm0\n" /* yy */
        "movss %xmm0, -0x74(%ebp)\n" /* xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x74(%ebp), %xmm0\n" /* xx */
        "movss %xmm0, -0x40(%ebp)\n"
        "movl %eax, -0x3c(%ebp)\n" /* line 377 */
        "leal -0x68(%ebp), %ecx\n" /* line 383 | buf, to */
        "addl $0x30, %ecx\n" /* to */
        "addl $0x1c, %edx\n" /* from */
        /* { scope 4 */
        "movl 8(%ebp), %ebx\n" /* line 199 | skinRigidCmd */
        "movl 0x1c(%ebx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0x3f800000, -0x2c(%ebp)\n" /* line 384 */
        /* } scope */
        /* } scope */
        "movl (%ebx), %edi\n" /* line 2181 | rigidSurf, surfPos */
        "movl 4(%ebx), %ebx\n" /* line 2182 | rigidSurf */
        "testl %ebx, %ebx\n" /* rigidSurf */
        "jle .Lfd2c30_000d2dc5\n"
        "movl $0, -0x78(%ebp)\n" /* surfaceIndex */
        "movl 8(%ebp), %eax\n" /* skinRigidCmd */
        "jmp .Lfd2c30_000d2da9\n"
        /* { scope 2: xx, yy, zw */
        /* { scope 3: scale */
        ".Lfd2c30_000d2d86:\n"
        "cmpl $4, %eax\n" /* line 2105 */
        "je .Lfd2c30_000d2dd0\n"
        "movl %edi, %eax\n" /* line 2117 */
        "addl $0x10, %edi\n" /* line 2118 */
        "leal -0x68(%ebp), %edx\n" /* line 2119 | buf */
        "calll R_SkinXSurfaceSkinned\n"
        /* } scope */
        /* } scope */
        ".Lfd2c30_000d2d98:\n"
        "addl $1, -0x78(%ebp)\n" /* line 2182 | surfaceIndex */
        "movl -0x78(%ebp), %eax\n" /* surfaceIndex */
        "movl 8(%ebp), %ebx\n" /* skinRigidCmd, rigidSurf */
        "cmpl %eax, 4(%ebx)\n" /* rigidSurf */
        "jle .Lfd2c30_000d2dc5\n"
        ".Lfd2c30_000d2da7:\n"
        "movl %ebx, %eax\n" /* rigidSurf */
        ".Lfd2c30_000d2da9:\n"
        "movl 8(%eax), %esi\n" /* line 2183 | refEnt */
        /* { scope 2: xx, yy, zw */
        /* { scope 3: scale */
        "movl (%edi), %eax\n" /* line 2092 */
        "cmpl $5, %eax\n"
        "jne .Lfd2c30_000d2d86\n"
        "addl $0x10, %edi\n" /* line 2095 */
        /* } scope */
        /* } scope */
        "addl $1, -0x78(%ebp)\n" /* line 2182 | surfaceIndex */
        "movl -0x78(%ebp), %eax\n" /* surfaceIndex */
        "movl 8(%ebp), %ebx\n" /* skinRigidCmd, rigidSurf */
        "cmpl %eax, 4(%ebx)\n" /* rigidSurf */
        "jg .Lfd2c30_000d2da7\n"
        /* } scope */
        ".Lfd2c30_000d2dc5:\n"
        "addl $0x9c, %esp\n" /* line 2186 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: xx, yy, zw */
        /* { scope 3: scale */
        ".Lfd2c30_000d2dd0:\n"
        "movl %edi, %ebx\n" /* line 2108 | rigidSurf */
        "addl $0x38, %edi\n" /* line 2109 */
        "movss 0x38(%esi), %xmm0\n" /* line 2110 */
        "movss %xmm0, -0x6c(%ebp)\n" /* scale */
        /* { scope 4 */
        /* { scope 5 */
        "movl 4(%ebx), %eax\n" /* line 1727 */
        "movl %eax, (%esp)\n"
        "calll XSurfaceGetBoneOffset\n"
        "addl $8, %ebx\n" /* line 1731 */
        "movl %ebx, 0x10(%esp)\n"
        "movss -0x6c(%ebp), %xmm1\n" /* scale */
        "movss %xmm1, 0xc(%esp)\n"
        "leal 0x14(%esi), %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal 0x3c(%esi), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x68(%ebp), %edx\n" /* buf */
        "leal (%edx, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_GetRigidTransform\n"
        "jmp .Lfd2c30_000d2d98\n"
    );
}

