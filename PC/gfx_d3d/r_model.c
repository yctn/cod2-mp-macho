/* ASM dump from: r_model.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_model.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_local.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 */

static int warnCount; /* warnCount */
static int warnCount_00c85b04; /* warnCount */
static int warnCount_00c85b04; /* warnCount */
static int warnCount_00c85b04; /* warnCount */
static int warnCount_00c85b08; /* warnCount */
static int warnCount_00c85b08; /* warnCount */
static int warnCount_00c85b08; /* warnCount */
static int warnCount_00c85b0c; /* warnCount */
static int warnCount_00c85b0c; /* warnCount */
static int warnCount_00c85b0c; /* warnCount */
static int warnCount_00c85b10; /* warnCount */
static int warnCount_00c85b10; /* warnCount */
static int warnCount_00c85b10; /* warnCount */
extern void * Hunk_AllocInternal(int size);
extern void DB_EnumXAssets(int type, void (*func)(XAssetHeader, void *), void *data, qboolean overrides);
extern int XModelBad(union XAssetHeader header);
extern void XModelUnoptimize(union XAssetHeader header);
extern void XModelOptimize(union XAssetHeader header);
extern float Vec3Distance(const void *a, const void *b);
extern int DObjGetLodForDist(const void *obj, int modelIndex, float dist);
extern void DObjSetModel(struct DObj_s *obj, void *model);
extern int DObjGetNumModels(const struct DObj_s *obj);
extern int DObjGetSurfaces(const struct DObj_s *obj, DSurface_s *surfaces, int *partBits, char *lods);
extern struct XModel * DObjGetModel(const struct DObj_s *obj, int modelIndex);
extern const struct trXSkin_t * XModelGetSkins(const struct XModel *model);
extern struct XModel * XModelPrecache(const char *name, Alloc_t Alloc, Alloc_t AllocColl);
extern Bool R_ValidXModelName(const char *name);
extern refimport_t ri; /* imp_ri */
extern const int boxVerts[24][3]; /* boxVerts — 12 pairs of box edge start/end vertex indices */
extern const int s_streamSourceInfo[]; /* end sentinel for boxVerts iteration */
extern int DObjNumBones(const void *obj);
extern void DObjGetBoneInfo(const void *obj, void **boneInfoArray);
extern void *DObjGetRotTransArray(const void *obj);
extern void CG_DObjCalcPose(void *poseCtx, const void *obj, int *partBits);
extern void MatrixTransformVectorQuatTrans(const vec_t *in, const void *quatTrans, vec_t *out);
extern void MatrixTransformVector(const vec_t *in, const void *matrix, vec_t *out);
extern void R_AddDebugLine(void *debugGlobals, const vec_t *start, const vec_t *end, const vec_t *color);

#define VTABLE(obj) (*(void ***)((void *)(obj)))

typedef HRESULT (*BufferUnlockFn)(void *buffer);

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
static void R_XModelDebugBoxes_impl(const byte *sceneEnt, const byte *ent, const void *obj);
static void R_XModelDebugAxes(void);
static void R_XModelDebugAxes_impl(const byte *sceneEnt, const byte *ent, const void *obj);
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
struct XModel * R_RegisterModel(const char *name)
{
    if (!R_ValidXModelName(name)) {
        ri.Printf(2, "R_RegisterModel: Invalid model name '%s'\n", name);
        return NULL;
    }
    return XModelPrecache(name + 7, Hunk_AllocXModelPrecache, Hunk_AllocXModelPrecacheColl);
}

/* line 200 */
GfxBrushModel * R_RegisterInlineModel(int modelIndex)
{
    int *world = *(int **)((byte *)imp_rgp + 0x109c);
    return (GfxBrushModel *)(*(int *)((byte *)world + 0x138) + modelIndex * 32);
}

/* line 218 */
void R_SetIgnorePrecacheErrors(qboolean ignore)
{
    *(byte *)((byte *)imp_rg + 2) = (ignore != 0);
}

/* line 224 */
qboolean R_GetIgnorePrecacheErrors(void)
{
    return *(byte *)((byte *)imp_rg + 2) != 0;
}

/* line 587 */
void R_UnlockSkinnedCache(void)
{
    DxGlobals *dx;
    GfxBackEndData *frontEndData;
    IDirect3DVertexBuffer9 *vb;

    dx = (DxGlobals *)imp_dx;
    if (!dx->skinnedCacheLockAddr) {
        return;
    }

    dx->skinnedCacheLockAddr = NULL;
    frontEndData = *(GfxBackEndData **)imp_frontEndDataOut;
    vb = (IDirect3DVertexBuffer9 *)frontEndData->skinnedCacheVb->buffer;

    do {
        ((BufferUnlockFn)VTABLE(vb)[0x30 / 4])((void *)vb);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

/* line 2246 */
struct DObj_s * R_GetGfxEntityDObj(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    struct DObj_s *obj = *(struct DObj_s **)ent;
    if (!obj) {
        obj = *(struct DObj_s **)((byte *)sceneEnt + 4);
    } else {
        obj = *(struct DObj_s **)((byte *)imp_rg + 0x3110);
        DObjSetModel(obj, *(void **)((byte *)sceneEnt + 4));
    }
    return obj;
}

/* line 2877 */
void R_DObjReplaceMaterial(struct DObj_s *obj, int lod, int surfaceIndex, MaterialHandle material)
{
    char lods[16];
    int partBits[4];
    DSurface_s surfaces[64];
    int numModels = DObjGetNumModels(obj);

    for (int i = 0; i < numModels; i++)
        lods[i] = (char)lod;

    DObjGetSurfaces(obj, surfaces, partBits, lods);

    short modelIndex = surfaces[surfaceIndex].modelIndex;
    const struct trXSkin_t *skins = XModelGetSkins(DObjGetModel(obj, modelIndex));
    if (!skins)
        return;

    char lodVal = lods[modelIndex];
    short subMatIndex = surfaces[surfaceIndex].subMatIndex;
    ((MaterialHandle **)skins)[lodVal][subMatIndex] = material;
}

/* line 2917 */
static void R_ReleaseModel(union XAssetHeader header, void *data)
{
    if (XModelBad(header))
        return;
    XModelUnoptimize(header);
}

/* line 2949 */
void R_OptimizeAllModels(void)
{
    if (!*(int *)((char *)(*(void **)imp_r_optimizeXModels) + 8))
        return;
    DB_EnumXAssets(1, R_OptimizeModel, 0, 1);
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
static void R_OptimizeModel(XAssetHeader header, void *data)
{
    if (XModelBad(header))
        return;
    XModelOptimize(header);
}

/* line 1696 */
void R_GetRigidTransform(const DObjSkelMat *bone, const vec_t *origin, vec3_t *axis, float scale, vec3_t *boneAxis)
{
    float *ax = (float *)axis;
    float *b = (float *)bone;
    float *ba = (float *)boneAxis;
    float sa[9]; /* scaledAxis = scale * axis (3x3 matrix) */
    int row, col;

    /* Scale the 3x3 axis matrix */
    for (col = 0; col < 9; col++)
        sa[col] = scale * ax[col];

    /* Multiply bone rotation (4x3 at bone+0..+0x2c) by scaled axis (3x3)
     * Result rows 0-3 go to boneAxis[0..3], row 4 (translation) adds origin */
    for (row = 0; row < 4; row++) {
        float r0 = b[row * 4 + 0];
        float r1 = b[row * 4 + 1];
        float r2 = b[row * 4 + 2];

        ba[row * 3 + 0] = r0 * sa[0] + r1 * sa[3] + r2 * sa[6];
        ba[row * 3 + 1] = r0 * sa[1] + r1 * sa[4] + r2 * sa[7];
        ba[row * 3 + 2] = r0 * sa[2] + r1 * sa[5] + r2 * sa[8];

        /* Last row: add origin offset */
        if (row == 3) {
            ba[row * 3 + 0] += origin[0];
            ba[row * 3 + 1] += origin[1];
            ba[row * 3 + 2] += origin[2];
        }
    }
}

/* line 230 */
void R_ModelBounds(GfxBrushModel *bmodel, vec_t *mins, vec_t *maxs)
{
    if (bmodel) {
        mins[0] = bmodel->bounds[0][0];
        mins[1] = bmodel->bounds[0][1];
        mins[2] = bmodel->bounds[0][2];
        maxs[0] = bmodel->bounds[1][0];
        maxs[1] = bmodel->bounds[1][1];
        maxs[2] = bmodel->bounds[1][2];
    } else {
        mins[0] = mins[1] = mins[2] = 0;
        maxs[0] = maxs[1] = maxs[2] = 0;
    }
}

/* line 556 */
extern void R_FatalLockError(HRESULT hr);

void R_LockSkinnedCache(GfxLockType lockType)
{
    byte *frontEndData = *(byte **)imp_frontEndDataOut;
    byte *vb = *(byte **)(*(byte **)(frontEndData + 0x217c78) + 8);
    byte *dx = (byte *)imp_dx;
    void **vtable;
    DWORD lockFlags;
    HRESULT hr;

    /* D3DLOCK_NOOVERWRITE(0x1000) if GPU sync active or lockType!=0, else D3DLOCK_DISCARD(0x2000) */
    if (*(int *)(dx + 0x2c20) != 0 || lockType != 0)
        lockFlags = 0x1000;
    else
        lockFlags = 0x2000;

    /* IDirect3DVertexBuffer9::Lock(0, 0, &pData, lockFlags) — vtable 0x2C */
    vtable = *(void ***)vb;
    hr = ((HRESULT (*)(void *, UINT, UINT, void **, DWORD))(vtable[0x2C / 4]))(
        vb, 0, 0, (void **)(dx + 0x2dc0), lockFlags);

    if (hr < 0)
        R_FatalLockError(hr);

    /* Check alignment of locked pointer */
    if (*(int *)(dx + 0x2dc0) & 0xf) {
        vtable = *(void ***)vb;
        ((HRESULT (*)(void *))(vtable[0x30 / 4]))(vb);
        *(int *)(dx + 0x2dc0) = 0;
    }
}

/* line 2911 */
void R_ShutdownModels(void)
{
    DB_EnumXAssets(1, R_ReleaseModel, 0, 1);
}

/* line 211 */
void R_FinishLoadingModels(void)
{
    if (*(int *)((byte *)(*(int *)imp_r_optimizeXModels) + 8) == 0)
        return;
    DB_EnumXAssets(1, R_OptimizeModel, 0, 1);
}

/* line 2838 */
void R_DObjGetSurfMaterials(struct DObj_s *obj, int lod, MaterialHandle *matHandleArray)
{
    char lods[16];
    int partBits[4];
    DSurface_s surfaces[64];
    int numModels = DObjGetNumModels(obj);

    for (int i = 0; i < numModels; i++)
        lods[i] = (char)lod;

    int surfaceCount = DObjGetSurfaces(obj, surfaces, partBits, lods);

    for (int surfaceIndex = 0; surfaceIndex < surfaceCount; surfaceIndex++) {
        short modelIndex = surfaces[surfaceIndex].modelIndex;
        const struct trXSkin_t *skins = XModelGetSkins(DObjGetModel(obj, modelIndex));
        if (skins) {
            char lodVal = lods[modelIndex];
            short subMatIndex = surfaces[surfaceIndex].subMatIndex;
            matHandleArray[surfaceIndex] = ((MaterialHandle **)skins)[lodVal][subMatIndex];
        } else {
            matHandleArray[surfaceIndex] = 0;
        }
    }
}

/* line 257 */
/* line 257 — Compute per-model LOD levels based on distance and entity scale,
 * then get surfaces for all LODs. Register convention: eax=ent, edx=obj, ecx=surfaces. */
static int R_GetSurfaceData_impl(const byte *ent, const void *obj, void *surfaces, int *partBits, char *lods)
{
    char *rg = (char *)imp_rg;
    int modelCount, i;
    float dist, scale;

    modelCount = DObjGetNumModels(obj);
    scale = *(float *)(ent + 0x38);

    /* Compute distance from entity origin to camera, scaled by LOD parameters */
    dist = Vec3Distance(ent + 0x3c, rg + 0x317c);
    dist = dist * *(float *)(rg + 0x3188) + *(float *)(rg + 0x318c);

    /* Apply entity scale if non-zero */
    if (scale != 0.0f)
        dist /= scale;

    /* Compute LOD level for each sub-model */
    for (i = 0; i < modelCount; i++) {
        lods[i] = (char)DObjGetLodForDist(obj, i, dist);
    }

    return DObjGetSurfaces(obj, surfaces, partBits, lods);
}

static __attribute__((naked))
int R_GetSurfaceData(long unsigned int (*surfaces)[32], int *partBits, char *lods)
{
    __asm__ __volatile__ (
        "pushl 0xc(%esp)\n"
        "pushl 0xc(%esp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_GetSurfaceData_impl\n"
        "addl $20, %esp\n"
        "retl $8\n"
    );
}

#if 0 /* original naked — replaced above */
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
        "movl imp_rg, %ebx\n" /* line 249 */
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
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
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
#endif

/* line 299 — R_XModelDebugBoxes
 * Draws wireframe bounding boxes for each active bone in an XModel.
 * For each bone in partBits, transforms 12 box edge pairs through the bone
 * quaternion and entity matrix, then draws debug lines.
 * Actual convention: eax=sceneEnt, edx=ent, ecx=obj */
static void R_XModelDebugBoxes_impl(const byte *sceneEnt, const byte *ent, const void *obj)
{
    byte surfaces[0x100];
    int partBits[5];
    char lods[16];
    void *boneInfoArray[200];
    int boneIndex, boneCount;

    R_GetSurfaceData_impl(ent, obj, surfaces, partBits, lods);

    /* Calculate bone poses if pose context exists */
    if (*(void **)(sceneEnt + 8))
        CG_DObjCalcPose(*(void **)(sceneEnt + 8), obj, partBits);

    boneCount = DObjNumBones(obj);
    DObjGetBoneInfo(obj, boneInfoArray);
    byte *rotTransArray = (byte *)DObjGetRotTransArray(obj);
    if (!rotTransArray)
        return;

    vec4_t color = {1.0f, 1.0f, 1.0f, 0.0f};
    byte *entMatrix = (byte *)(ent + 0x14);
    float *entOrigin = (float *)(ent + 0x3c);
    byte *debugGlobals = *(byte **)imp_frontEndDataOut + 0x249d18;

    for (boneIndex = 0; boneIndex < boneCount; boneIndex++) {
        /* Check partBits to see if this bone is active */
        if (!((partBits[boneIndex >> 5] >> (boneIndex & 0x1f)) & 1))
            continue;

        float *bi = (float *)boneInfoArray[boneIndex];
        byte *quatTrans = rotTransArray + boneIndex * 0x20;

        /* Draw 12 box edges */
        int edge;
        for (edge = 0; edge < 12; edge++) {
            const int *sv = boxVerts[edge * 2];     /* start vertex indices */
            const int *ev = boxVerts[edge * 2 + 1]; /* end vertex indices */

            /* Build start point from indexed bone info components */
            vec3_t org, vec, start;
            org[0] = bi[sv[0] * 3 + 0];
            org[1] = bi[sv[1] * 3 + 1];
            org[2] = bi[sv[2] * 3 + 2];
            MatrixTransformVectorQuatTrans(org, quatTrans, vec);
            MatrixTransformVector(vec, entMatrix, start);
            start[0] += entOrigin[0];
            start[1] += entOrigin[1];
            start[2] += entOrigin[2];

            /* Build end point */
            vec3_t end;
            org[0] = bi[ev[0] * 3 + 0];
            org[1] = bi[ev[1] * 3 + 1];
            org[2] = bi[ev[2] * 3 + 2];
            MatrixTransformVectorQuatTrans(org, quatTrans, vec);
            MatrixTransformVector(vec, entMatrix, end);
            end[0] += entOrigin[0];
            end[1] += entOrigin[1];
            end[2] += entOrigin[2];

            R_AddDebugLine(debugGlobals, start, end, color);
        }
    }
}

static __attribute__((naked))
void R_XModelDebugBoxes(void)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_XModelDebugBoxes_impl\n"
        "addl $12, %esp\n"
        "retl\n"
    );
}

/* line 365 — R_XModelDebugAxes
 * Draws 3-axis coordinate frames for each active bone in an XModel.
 * For each bone in partBits, draws X/Y/Z axes of length 6.0 as colored debug lines.
 * Actual convention: eax=sceneEnt, edx=ent, ecx=obj */
static void R_XModelDebugAxes_impl(const byte *sceneEnt, const byte *ent, const void *obj)
{
    byte surfaces[0x100];
    int partBits[5];
    char lods[16];
    int boneIndex, boneCount, axis;

    R_GetSurfaceData_impl(ent, obj, surfaces, partBits, lods);

    if (*(void **)(sceneEnt + 8))
        CG_DObjCalcPose(*(void **)(sceneEnt + 8), obj, partBits);

    /* Axis translation vectors: 6 units along each axis */
    vec3_t translation[3] = {{6.0f, 0.0f, 0.0f}, {0.0f, 6.0f, 0.0f}, {0.0f, 0.0f, 6.0f}};

    boneCount = DObjNumBones(obj);
    byte *rotTransArray = (byte *)DObjGetRotTransArray(obj);
    if (!rotTransArray || boneCount <= 0)
        return;

    byte *entMatrix = (byte *)(ent + 0x14);
    float *entOrigin = (float *)(ent + 0x3c);
    byte *debugGlobals = *(byte **)imp_frontEndDataOut + 0x249d18;

    for (boneIndex = 0; boneIndex < boneCount; boneIndex++) {
        if (!((partBits[boneIndex >> 5] >> (boneIndex & 0x1f)) & 1))
            continue;

        byte *quatTrans = rotTransArray + boneIndex * 0x20;

        for (axis = 0; axis < 3; axis++) {
            /* Color: 1.0 in the axis component, 0 elsewhere */
            vec4_t color = {0.0f, 0.0f, 0.0f, 0.0f};
            color[axis] = 1.0f;

            /* Start = bone origin (transform vec3_origin through bone) */
            vec3_t vec, start;
            MatrixTransformVectorQuatTrans((const vec_t *)imp_vec3_origin, quatTrans, vec);
            MatrixTransformVector(vec, entMatrix, start);
            start[0] += entOrigin[0];
            start[1] += entOrigin[1];
            start[2] += entOrigin[2];

            /* End = bone origin + axis * 6.0 (transform axis translation through bone) */
            vec3_t end;
            MatrixTransformVectorQuatTrans(translation[axis], quatTrans, vec);
            MatrixTransformVector(vec, entMatrix, end);
            end[0] += entOrigin[0];
            end[1] += entOrigin[1];
            end[2] += entOrigin[2];

            R_AddDebugLine(debugGlobals, start, end, color);
        }
    }
}

static __attribute__((naked))
void R_XModelDebugAxes(void)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_XModelDebugAxes_impl\n"
        "addl $12, %esp\n"
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
        "movl imp_developer, %eax\n" /* line 2785 */
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
        "movl imp_rg, %eax\n" /* line 2258 */
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
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
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
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
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
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
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
        "movl imp_r_skinCache, %eax\n" /* line 1884 */
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
        "movl imp_dx, %eax\n" /* line 614 */
        "movl 0x2dc0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd1326_000d146a\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1067 */
        "movl (%eax), %eax\n"
        "movl $0x24, %edx\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x40, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl imp_frontEndDataOut, %edi\n" /* line 620 */
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
        "movl $str_00223f60, 4(%esp)\n" /* line 630 */
        "movl $2, (%esp)\n"
        "movl imp_ri, %eax\n"
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
        "movl imp_frontEndDataOut, %eax\n" /* line 1891 */
        "movl (%eax), %eax\n"
        "movl 0x217c78(%eax), %edx\n"
        "movl imp_dx, %eax\n" /* line 1895 */
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
        "movl imp_r_rendererInUse, %edx\n" /* line 1067 */
        "movl (%edx), %edx\n"
        "movl $0x24, %ecx\n"
        "cmpl $2, 8(%edx)\n"
        "movl $0x40, %edx\n"
        "cmovnel %edx, %ecx\n"
        "imull %eax, %ecx\n" /* line 1898 */
        "movl imp_dx, %ebx\n" /* line 1900 | skins */
        "movl 0x2dd4(%ebx), %edx\n" /* skins */
        "leal (%ecx, %edx), %eax\n"
        "cmpl $0xa00000, %eax\n"
        "jle .Lfd1326_000d1528\n"
        "movl imp_frontEndDataOut, %eax\n" /* line 1902 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1326_000d13b0\n"
        "movl %eax, warnCount\n" /* line 1904 */
        "movl $str_00223fa0, 4(%esp)\n" /* line 1905 */
        "movl $2, (%esp)\n"
        "movl imp_ri, %eax\n"
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
        "movl imp_ri, %eax\n"
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
        "movl imp_developer, %eax\n" /* line 2513 */
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
        "movl imp_scene, %eax\n" /* line 2544 */
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
        "movl imp_scene, %eax\n" /* line 2548 */
        "movl $__mh_execute_header, 0x1a55c(%eax)\n"
        "movl imp_frontEndDataOut, %eax\n" /* line 2549 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1568_000d15de\n"
        "movl %eax, warnCount\n" /* line 2551 */
        "movl $str_00223fd4, 4(%esp)\n" /* line 2552 */
        "movl $2, (%esp)\n"
        "movl imp_ri, %eax\n"
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
        "movl imp_scene, %eax\n" /* line 2560 */
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
        "movl imp_frontEndDataOut, %ecx\n" /* line 2578 */
        "movl (%ecx), %eax\n"
        "addl $0x80008, %eax\n"
        "movl %edi, 4(%esp)\n" /* size */
        "movl %eax, (%esp)\n"
        "calll InterlockedExchangeAdd\n"
        "movl %eax, %edx\n"
        "leal (%edi, %eax), %eax\n" /* line 2580 | size */
        "cmpl $0x20000, %eax\n"
        "jbe .Lfd1568_000d17c2\n"
        "movl imp_frontEndDataOut, %edx\n" /* line 2582 */
        "movl (%edx), %eax\n"
        "movl $0x20000, 0x80008(%eax)\n"
        "movl (%edx), %eax\n" /* line 2583 */
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1568_000d15de\n"
        "movl %eax, warnCount\n" /* line 2585 */
        "movl $str_00224008, 4(%esp)\n" /* line 2586 */
        "movl $2, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfd1568_000d15de\n"
        ".Lfd1568_000d17ba:\n"
        "leal -0xfac(%ebp), %edi\n" /* line 2574 | surfBuf, size */
        "jmp .Lfd1568_000d174b\n"
        ".Lfd1568_000d17c2:\n"
        "movl imp_frontEndDataOut, %ecx\n" /* line 2594 */
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
        "movl imp_r_xdebug, %edi\n" /* line 2601 | size */
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
        "movl imp_r_smc_enable, %eax\n" /* line 1979 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfd193e_000d1982\n"
        "movl %edi, (%esp)\n" /* xsurf */
        "calll XSurfaceGetBoneOffset\n"
        "addl $1, %eax\n"
        "je .Lfd193e_000d1982\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1981 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd193e_000d1a38\n"
        ".Lfd193e_000d19d3:\n"
        "movl imp_rg, %eax\n" /* line 1988 */
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
        "movl imp_r_skinCache, %eax\n" /* line 2033 */
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
        "movl imp_dx, %eax\n" /* line 614 */
        "movl 0x2dc0(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lfd193e_000d1b0d\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1067 */
        "movl (%eax), %eax\n"
        "movl $0x24, %edx\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x40, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl imp_frontEndDataOut, %ebx\n" /* line 620 */
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
        "movl $str_00223f60, 4(%esp)\n" /* line 630 */
        "movl $2, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        ".Lfd193e_000d1b0d:\n"
        "movl $0xffffffff, %eax\n"
        /* } scope */
        /* } scope */
        ".Lfd193e_000d1b12:\n"
        "movl %eax, 8(%esi)\n" /* line 2038 | surfPos */
        "testl %eax, %eax\n" /* line 2039 */
        "js .Lfd193e_000d1b53\n"
        "movl imp_frontEndDataOut, %eax\n" /* line 2040 */
        "movl (%eax), %eax\n"
        "movl 0x217c78(%eax), %edx\n"
        "movl imp_dx, %eax\n" /* line 2044 */
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
        "movl imp_r_rendererInUse, %edx\n" /* line 1067 */
        "movl (%edx), %edx\n"
        "movl $0x24, %ecx\n"
        "cmpl $2, 8(%edx)\n"
        "movl $0x40, %edx\n"
        "cmovnel %edx, %ecx\n"
        "imull %eax, %ecx\n" /* line 2047 */
        "movl imp_dx, %ebx\n" /* line 2049 | material */
        "movl 0x2dd4(%ebx), %edx\n" /* material */
        "leal (%ecx, %edx), %eax\n"
        "cmpl $0xa00000, %eax\n"
        "jle .Lfd193e_000d1bf8\n"
        "movl imp_frontEndDataOut, %eax\n" /* line 2051 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd193e_000d1a2e\n"
        "movl %eax, warnCount\n" /* line 2053 */
        "movl $str_00223fa0, 4(%esp)\n" /* line 2054 */
        "movl $2, (%esp)\n"
        "movl imp_ri, %eax\n"
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
        "movl imp_ri, %eax\n"
        "calll *0x24(%eax)\n"
        "jmp .Lfd193e_000d1b37\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfd193e_000d1c1e:\n"
        "movl %eax, 4(%esp)\n" /* line 625 */
        "movl %edx, (%esp)\n"
        "calll InterlockedExchange\n"
        "movl imp_frontEndDataOut, %ecx\n"
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
        "movl imp_developer, %eax\n" /* line 2325 */
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
        "movl imp_rg, %ebx\n" /* line 249 */
        "leal 0x317c(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Vec3Distance\n"
        "fstps -0xedc(%ebp)\n"
        "movss -0xedc(%ebp), %xmm0\n"
        "mulss 0x3188(%ebx), %xmm0\n" /* line 250 */
        "addss 0x318c(%ebx), %xmm0\n"
        "movss -0xebc(%ebp), %xmm1\n" /* line 251 | scale */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
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
        "movl imp_scene, %eax\n" /* line 2358 */
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
        "movl imp_scene, %eax\n" /* line 2362 */
        "movl $__mh_execute_header, 0x1a55c(%eax)\n"
        "movl imp_frontEndDataOut, %eax\n" /* line 2363 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1c38_000d1cae\n"
        "movl %eax, warnCount\n" /* line 2365 */
        "movl $str_00223fd4, 4(%esp)\n" /* line 2366 */
        "movl $2, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfd1c38_000d1cae\n"
        ".Lfd1c38_000d1de2:\n"
        "movl %edi, 4(%esp)\n" /* line 2328 | model */
        "movl imp_rg, %ebx\n" /* size */
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
        "movl imp_scene, %eax\n" /* line 2374 */
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
        "movl imp_frontEndDataOut, %edx\n" /* line 2393 */
        "movl (%edx), %eax\n"
        "addl $0x80008, %eax\n"
        "movl %ebx, 4(%esp)\n" /* size */
        "movl %eax, (%esp)\n"
        "calll InterlockedExchangeAdd\n"
        "movl %eax, %edx\n"
        "leal (%ebx, %eax), %eax\n" /* line 2395 | size */
        "cmpl $0x20000, %eax\n"
        "jbe .Lfd1c38_000d1f3f\n"
        "movl imp_frontEndDataOut, %ecx\n" /* line 2397 */
        "movl (%ecx), %eax\n"
        "movl $0x20000, 0x80008(%eax)\n"
        "movl (%ecx), %eax\n" /* line 2398 */
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfd1c38_000d1cae\n"
        "movl %eax, warnCount\n" /* line 2400 */
        "movl $str_00224008, 4(%esp)\n" /* line 2401 */
        "movl $2, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfd1c38_000d1cae\n"
        ".Lfd1c38_000d1f2f:\n"
        "leal -0xeb0(%ebp), %edx\n" /* line 2389 | surfBuf */
        "movl %edx, -0xec0(%ebp)\n" /* surfPos */
        "movl %edx, %ebx\n" /* size */
        "jmp .Lfd1c38_000d1ec0\n"
        ".Lfd1c38_000d1f3f:\n"
        "movl imp_frontEndDataOut, %ecx\n" /* line 2409 */
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
        "movl imp_r_xdebug, %edx\n" /* line 2416 */
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
        "movl imp_rg, %ebx\n" /* size */
        "movl 0x3110(%ebx), %eax\n" /* size */
        "movl %eax, (%esp)\n"
        "calll DObjSetModel\n"
        "movl 0x3110(%ebx), %ebx\n" /* size */
        /* { scope 2 */
        "movl imp_r_xdebug, %ecx\n" /* line 428 */
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
        "movl imp_r_xdebug, %edx\n"
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
void R_SkinSceneEnt(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    if (*(int *)ent == 1)
        R_SkinXModel(sceneEnt, ent, -1);
    else
        R_SkinSceneDObj(sceneEnt, ent);
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
        "movl imp_dx, %eax\n" /* line 1766 | skinnedSurf */
        "movl %edx, %ebx\n" /* skinVerticesOut */
        "addl 0x2dc0(%eax), %ebx\n" /* skinnedSurf, skinVerticesOut */
        ".Lfd2146_000d2173:\n"
        "movl %edi, (%esp)\n" /* line 1773 | xsurf */
        "calll XSurfaceGetBoneOffset\n"
        "movl %eax, -0xb0(%ebp)\n" /* skinnedSurf, boneOffset */
        "movl imp_r_rendererInUse, %eax\n" /* line 1776 | skinnedSurf */
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
        "mulss lit4_002ed5c4, %xmm0\n" /* 0.00390625f */
        "shufps $0, %xmm0, %xmm0\n"
        "mulps -0x68(%ebp), %xmm0\n" /* __A */
        "movaps %xmm0, -0x68(%ebp)\n" /* __A */
        "leal 0x40(%ebx), %ecx\n"
        "xorl %ebx, %ebx\n"
        "movss lit4_002ed854, %xmm5\n" /* 1.52587890625e-05f */
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
        "mulss lit4_002ed5c4, %xmm0\n" /* 0.00390625f */
        "shufps $0, %xmm0, %xmm0\n"
        "mulps %xmm0, %xmm6\n"
        "leal 0x40(%esi), %ecx\n" /* line 1198 | vertex */
        "xorl %esi, %esi\n" /* vertex */
        "movss lit4_002ed854, %xmm5\n" /* 1.52587890625e-05f */
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
/* line 2224 — XModel skinning: converts bone quaternions to 3x4 matrices,
 * then dispatches per-surface skinning (skinned or rigid transform). */
void R_SkinXModelCmd(SkinXModelCmd *skinCmd, int context)
{
    char *matArray = (char *)imp_g_skinBuffers + context * 5 * 8192;
    const DObjAnimMat *bones = skinCmd->mat;
    int boneCount = skinCmd->boneCount;
    int boneIndex;
    const surfaceType_t *surfPos;
    int surfaceIndex;

    /* Phase 1: Build rotation matrices from bone quaternions */
    for (boneIndex = 0; boneIndex < boneCount; boneIndex++) {
        /* Check if this bone is used (bit test in surfacePartBits) */
        if (skinCmd->surfacePartBits[boneIndex >> 5] & (1 << (boneIndex & 0x1f))) {
            const float *q = bones[boneIndex].quat;
            const float *t = bones[boneIndex].trans;
            float w2 = bones[boneIndex].transWeight;
            float *m = (float *)(matArray + boneIndex * 64);

            /* Quaternion to 3x4 rotation matrix with w2 scaling */
            float xx2 = w2 * q[0], yy2 = w2 * q[1], zz2 = w2 * q[2];
            float xx = xx2 * q[0], xy = xx2 * q[1], xz = xx2 * q[2], xw = xx2 * q[3];
            float yy = yy2 * q[1], yz = yy2 * q[2], yw = yy2 * q[3];
            float zz = zz2 * q[2], zw = zz2 * q[3];

            m[0]  = 1.0f - (yy + zz);  m[1]  = zw + xy;           m[2]  = xz - yw;           m[3]  = 0.0f;
            m[4]  = xy - zw;            m[5]  = 1.0f - (xx + zz);  m[6]  = xw + yz;           m[7]  = 0.0f;
            m[8]  = xz + yw;            m[9]  = yz - xw;           m[10] = 1.0f - (xx + yy);  m[11] = 0.0f;
            m[12] = t[0];               m[13] = t[1];              m[14] = t[2];               m[15] = 1.0f;
        }
    }

    /* Phase 2: Process surfaces */
    surfPos = skinCmd->surfs;
    for (surfaceIndex = 0; surfaceIndex < skinCmd->surfCount; surfaceIndex++) {
        int surfType = *(const int *)surfPos;
        const DObjSkelMat *boneMatrix = (const DObjSkelMat *)(matArray + skinCmd->matOffset[surfaceIndex] * 64);

        if (surfType == 3) {
            /* Skinned surface */
            __asm__ __volatile__ (
                "movl %[surf], %%eax\n"
                "movl %[bone], %%edx\n"
                "calll R_SkinXSurfaceSkinned\n"
                : : [surf]"r"(surfPos), [bone]"r"(boneMatrix) : "eax", "ecx", "edx", "memory"
            );
            surfPos = (const surfaceType_t *)((const byte *)surfPos + 16);
        } else if (surfType == 5) {
            /* Static cached surface — skip */
            surfPos = (const surfaceType_t *)((const byte *)surfPos + 16);
        } else {
            /* Rigid surface (type 4 or other) */
            const byte *rigidSurf = (const byte *)surfPos;
            surfPos = (const surfaceType_t *)(rigidSurf + 0x38);
            {
                extern int XSurfaceGetBoneOffset(int xsurfIndex);
                int boneOffset = XSurfaceGetBoneOffset(*(int *)(rigidSurf + 4));
                GfxEntity *refEnt = skinCmd->e;
                R_GetRigidTransform(
                    (const DObjSkelMat *)((const char *)boneMatrix + boneOffset),
                    (const vec_t *)((const byte *)refEnt + 0x3c),
                    (vec3_t *)((const byte *)refEnt + 0x14),
                    *(float *)((const byte *)refEnt + 0x38),
                    (vec3_t *)(rigidSurf + 8));
            }
        }
    }
}

#if 0 /* original naked — replaced above */
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
        "movl imp_g_skinBuffers, %edx\n"
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
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
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
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
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
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
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
#endif /* original naked R_SkinXModelCmd */

/* line 2162 — R_SkinRigidXModelCmd
 * Processes a rigid XModel skinning command. Builds a 3x4 rotation matrix from the
 * quaternion in the command's DObjAnimMat, then iterates surfaces calling
 * R_SkinXSurfaceSkinned (type!=4,5) or R_GetRigidTransform (type==4) per surface. */
extern int XSurfaceGetBoneOffset(int xsurfIndex);

void R_SkinRigidXModelCmd(SkinRigidXModelCmd *skinRigidCmd)
{
    float *q = skinRigidCmd->mat.quat;
    float scale = skinRigidCmd->mat.transWeight;

    /* Build scaled quaternion products */
    float sx = scale * q[0], sy = scale * q[1], sz = scale * q[2];
    float xx = sx * q[0], xy = sx * q[1], xz = sx * q[2], xw = sx * q[3];
    float yy = sy * q[1], yz = sy * q[2], yw = sy * q[3];
    float zz = sz * q[2], zw = sz * q[3];

    /* Build 3x4 rotation matrix (row-major: 3 rows x 4 cols, last col = translation) */
    float mtx[16]; /* only first 13 used: [0..11] = 3x4 matrix, [12] = 1.0 sentinel */
    mtx[0]  = 1.0f - yy - zz;  mtx[1]  = xy + zw;          mtx[2]  = xz - yw;          mtx[3]  = 0.0f;
    mtx[4]  = xy - zw;          mtx[5]  = 1.0f - xx - zz;   mtx[6]  = yz + xw;          mtx[7]  = 0.0f;
    mtx[8]  = xz + yw;          mtx[9]  = yz - xw;          mtx[10] = 1.0f - xx - yy;   mtx[11] = 0.0f;

    /* Copy translation into matrix row 3 (offset 0x30 = 48 bytes from start) */
    mtx[12] = skinRigidCmd->mat.trans[0];
    *(float *)((byte *)mtx + 0x34) = skinRigidCmd->mat.trans[1];
    *(float *)((byte *)mtx + 0x38) = skinRigidCmd->mat.trans[2];
    *(float *)((byte *)mtx + 0x3c) = 1.0f; /* homogeneous w */

    /* Iterate through surfaces */
    byte *surfPos = (byte *)skinRigidCmd->surfs;
    GfxEntity *refEnt = skinRigidCmd->e;
    int i;

    for (i = 0; i < skinRigidCmd->surfCount; i++) {
        int surfType = *(int *)surfPos;

        if (surfType == 5) {
            /* Skip rigid surface header */
            surfPos += 0x10;
            continue;
        }

        if (surfType == 4) {
            /* Rigid transform path: get bone offset, compute transform, advance by 0x38 */
            byte *rigidSurf = surfPos;
            surfPos += 0x38;
            float entScale = *(float *)((byte *)refEnt + 0x38);
            int boneOffset = XSurfaceGetBoneOffset(*(int *)(rigidSurf + 4));
            R_GetRigidTransform(
                (const DObjSkelMat *)((byte *)mtx + boneOffset),
                (const vec_t *)((byte *)refEnt + 0x3c),
                (vec3_t *)((byte *)refEnt + 0x14),
                entScale,
                (vec3_t *)(rigidSurf + 8)
            );
        } else {
            /* Standard skinned surface: call R_SkinXSurfaceSkinned(eax=surfPos, edx=mtx) */
            byte *surf = surfPos;
            surfPos += 0x10;
            __asm__ __volatile__ (
                "calll R_SkinXSurfaceSkinned\n"
                :
                : "a"(surf), "d"(mtx)
                : "ecx", "memory"
            );
        }
    }
}
