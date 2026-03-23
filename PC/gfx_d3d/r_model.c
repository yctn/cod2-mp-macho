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
extern r_global_permanent_t rgp; /* imp_rgp */
__attribute__((used)) const int boxVerts[24][3] = {
    { 0, 0, 0 }, { 1, 0, 0 },
    { 0, 0, 0 }, { 0, 1, 0 },
    { 1, 1, 0 }, { 1, 0, 0 },
    { 1, 1, 0 }, { 0, 1, 0 },
    { 0, 0, 1 }, { 1, 0, 1 },
    { 0, 0, 1 }, { 0, 1, 1 },
    { 1, 1, 1 }, { 1, 0, 1 },
    { 1, 1, 1 }, { 0, 1, 1 },
    { 0, 0, 0 }, { 0, 0, 1 },
    { 1, 0, 0 }, { 1, 0, 1 },
    { 0, 1, 0 }, { 0, 1, 1 },
    { 1, 1, 0 }, { 1, 1, 1 },
}; /* 0x2f24c0 */
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
static void R_XModelDebugBoxes_impl(const byte *sceneEnt, const byte *ent, const void *obj);
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
    GfxWorld *world = rgp.world;
    return &world->models[modelIndex];
}

/* line 218 */
void R_SetIgnorePrecacheErrors(qboolean ignore)
{
    ((r_globals_t *)imp_rg)->ignorePrecacheErrors = (ignore != 0);
}

/* line 224 */
qboolean R_GetIgnorePrecacheErrors(void)
{
    return ((r_globals_t *)imp_rg)->ignorePrecacheErrors != 0;
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
    struct DObj_s *obj = (struct DObj_s *)(intptr_t)ent->reType;
    if (!obj) {
        obj = (struct DObj_s *)sceneEnt->u.obj;
    } else {
        obj = ((r_globals_t *)imp_rg)->modelDObj;
        DObjSetModel(obj, (void *)sceneEnt->u.data);
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
    byte *vb = *(byte **)((byte *)((GfxBackEndData *)frontEndData)->skinnedCacheVb + 8);
    byte *dx = (byte *)imp_dx;
    void **vtable;
    DWORD lockFlags;
    HRESULT hr;

    if (!vb)
        return;

    /* D3DLOCK_NOOVERWRITE(0x1000) if GPU sync active or lockType!=0, else D3DLOCK_DISCARD(0x2000) */
    if (((DxGlobals *)dx)->gpuSync != 0 || lockType != 0)
        lockFlags = 0x1000;
    else
        lockFlags = 0x2000;

    /* IDirect3DVertexBuffer9::Lock(0, 0, &pData, lockFlags) — vtable 0x2C */
    vtable = *(void ***)vb;
    hr = ((HRESULT (*)(void *, UINT, UINT, void **, DWORD))(vtable[0x2C / 4]))(
        vb, 0, 0, (void **)&((DxGlobals *)dx)->skinnedCacheLockAddr, lockFlags);

    if (hr < 0)
        R_FatalLockError(hr);

    /* Check alignment of locked pointer */
    if ((uintptr_t)((DxGlobals *)dx)->skinnedCacheLockAddr & 0xf) {
        vtable = *(void ***)vb;
        ((HRESULT (*)(void *))(vtable[0x30 / 4]))(vb);
        ((DxGlobals *)dx)->skinnedCacheLockAddr = NULL;
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
    r_globals_t *rg = (r_globals_t *)imp_rg;
    int modelCount, i;
    float dist, scale;

    modelCount = DObjGetNumModels(obj);
    scale = ((GfxEntity *)ent)->scale;

    /* Compute distance from entity origin to camera, scaled by LOD parameters */
    dist = Vec3Distance(((GfxEntity *)ent)->origin, rg->lodParms.origin);
    dist = dist * rg->lodParms.scale + rg->lodParms.bias;

    /* Apply entity scale if non-zero */
    if (scale != 0.0f)
        dist /= scale;

    /* Compute LOD level for each sub-model */
    for (i = 0; i < modelCount; i++) {
        lods[i] = (char)DObjGetLodForDist(obj, i, dist);
    }

    return DObjGetSurfaces(obj, surfaces, partBits, lods);
}

/* Clean C version for WASM — no register calling convention */
static int R_GetSurfaceData(const byte *ent, const void *obj, void *surfaces, int *partBits, char *lods)
{
    return R_GetSurfaceData_impl(ent, obj, surfaces, partBits, lods);
}


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

/* Clean C version for WASM — no register calling convention */
static void R_XModelDebugBoxes(const byte *sceneEnt, const byte *ent, const void *obj)
{
    R_XModelDebugBoxes_impl(sceneEnt, ent, obj);
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

/* Clean C version for WASM — no register calling convention */
static void R_XModelDebugAxes(const byte *sceneEnt, const byte *ent, const void *obj)
{
    R_XModelDebugAxes_impl(sceneEnt, ent, obj);
}

/* line 2749 */
/* line 2749 — Computes world-space bounding box for an XModel entity by transforming
 * per-bone half-extents through quaternion rotation matrices and accumulating bounds. */
extern int DObjBad(const void *obj);
extern void *DObjGetSurface(const void *obj, int surfIdx, int xsurf, int lod);
extern int XSurfaceGetNumVerts(void *xsurf);
extern int InterlockedExchange(volatile int *dest, int value);
extern int InterlockedExchangeAdd(volatile int *dest, int value);
extern int XSurfaceGetBoneOffset(int xsurfIndex);
extern void ClearBounds(float *mins, float *maxs);
extern void GetRotatedBounds(float *bounds, float *origin, float *axis, float *outBounds);
extern int InterlockedCompareExchange(volatile int *dest, int exchange, int comparand);
void R_UpdateXModelBounds(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    char *se = (char *)sceneEnt;
    char *e = (char *)ent;
    void *obj;
    int boneCount, i;
    int partBits[4];
    short surfaces[67];
    char lods[8];
    float bounds[6]; /* mins[3], maxs[3] */
    int boneInfo[128]; /* bone info array */

    /* Check state: must be <= 3 to proceed */
    if (((GfxSceneEntity *)se)->cullState > 3)
        return;

    /* Atomic compare-exchange: try to claim state 0→1 */
    if (InterlockedCompareExchange(&((GfxSceneEntity *)se)->cullState, 0, 1) != 0) {
        /* Someone else is processing — spin until done */
        while (((GfxSceneEntity *)se)->cullState <= 1)
            ;
        return;
    }

    /* Handle entity type override */
    if (((GfxEntity *)e)->reType != 0) {
        void *defaultModel = ((r_globals_t *)imp_rg)->modelDObj;
        obj = (void *)((GfxSceneEntity *)se)->u.data;
        DObjSetModel(defaultModel, obj);
    } else {
        obj = (void *)((GfxSceneEntity *)se)->u.data;
    }

    /* Check for bad DObj */
    if (DObjBad(obj)) {
        if (*(int *)(*(char **)imp_developer + 8)) {
            R_XModelDebugBoxes_impl((const byte *)sceneEnt, (const byte *)ent, obj);
            R_XModelDebugAxes_impl((const byte *)sceneEnt, (const byte *)ent, obj);
        }
        goto set_origin_bounds;
    }

    /* Get surface data */
    {
        int surfCount;
        surfCount = R_GetSurfaceData_impl((const byte *)ent, obj, surfaces, partBits, lods);
        if (surfCount == 0)
            goto set_origin_bounds;
    }

    /* Calculate pose if animation exists */
    {
        void *anim = (void *)((GfxSceneEntity *)se)->cent;
        if (anim)
            CG_DObjCalcPose(anim, obj, partBits);
    }

    /* Get bone rotation/translation array */
    {
        const DObjAnimMat *boneMatrix = (const DObjAnimMat *)DObjGetRotTransArray(obj);
        if (!boneMatrix)
            goto set_origin_bounds;

        ClearBounds(&bounds[0], &bounds[3]);
        DObjGetBoneInfo(obj, (void **)boneInfo);
        boneCount = DObjNumBones(obj);

        /* For each active bone: build rotation matrix, expand bounds */
        for (i = 0; i < boneCount; i++) {
            if (!(partBits[i >> 5] & (1 << (i & 0x1f))))
                continue;

            {
                const float *q = boneMatrix[i].quat;
                float w2 = boneMatrix[i].transWeight;
                const float *trans = boneMatrix[i].trans;
                const int *bi = &boneInfo[i * 4]; /* bone info for this bone */

                /* Quaternion to rotation matrix (same as R_SkinXModelCmd) */
                float xx2 = w2*q[0], yy2 = w2*q[1], zz2 = w2*q[2];
                float xx = xx2*q[0], xy = xx2*q[1], xz = xx2*q[2], xw = xx2*q[3];
                float yy = yy2*q[1], yz = yy2*q[2], yw = yy2*q[3];
                float zz = zz2*q[2], zw = zz2*q[3];

                float m00 = 1.0f-(yy+zz), m01 = xy+zw,        m02 = xz-yw;
                float m10 = xy-zw,         m11 = 1.0f-(xx+zz), m12 = yz+xw;
                float m20 = xz+yw,         m21 = yz-xw,        m22 = 1.0f-(xx+yy);

                /* Expand bounds using rotation × bone half-extents.
                 * For each world axis, compute min/max contribution from each bone axis
                 * using sign-selected half-extent pairs from boneInfo. */
                float bmin, bmax;
                const float *bif = (const float *)bi;

                /* X axis */
                #define AXIS_CONTRIB(rot, biOfs) do { \
                    int sel = (*(int*)&(rot)) >> 31 & 3; /* 0 or 3 based on sign */ \
                    bmin += (rot) * bif[sel]; \
                    bmax += (rot) * bif[3 - sel]; \
                } while(0)

                bmin = trans[0]; bmax = trans[0];
                AXIS_CONTRIB(m00, 0); AXIS_CONTRIB(m10, 1); AXIS_CONTRIB(m20, 2);
                if (bmin < bounds[0]) bounds[0] = bmin;
                if (bmax > bounds[3]) bounds[3] = bmax;

                bmin = trans[1]; bmax = trans[1];
                AXIS_CONTRIB(m01, 0); AXIS_CONTRIB(m11, 1); AXIS_CONTRIB(m21, 2);
                if (bmin < bounds[1]) bounds[1] = bmin;
                if (bmax > bounds[4]) bounds[4] = bmax;

                bmin = trans[2]; bmax = trans[2];
                AXIS_CONTRIB(m02, 0); AXIS_CONTRIB(m12, 1); AXIS_CONTRIB(m22, 2);
                if (bmin < bounds[2]) bounds[2] = bmin;
                if (bmax > bounds[5]) bounds[5] = bmax;

                #undef AXIS_CONTRIB
            }
        }

        /* Transform bounds by entity orientation */
        GetRotatedBounds(bounds, ((GfxEntity *)e)->origin, (float *)((GfxEntity *)e)->axis, ((GfxSceneEntity *)se)->curMins);
        ((GfxSceneEntity *)se)->cullState = 2;
        return;
    }

set_origin_bounds:
    /* Degenerate bounds: min = max = entity origin */
    ((GfxSceneEntity *)se)->curMins[0] = ((GfxEntity *)e)->origin[0];
    ((GfxSceneEntity *)se)->curMins[1] = ((GfxEntity *)e)->origin[1];
    ((GfxSceneEntity *)se)->curMins[2] = ((GfxEntity *)e)->origin[2];
    ((GfxSceneEntity *)se)->curMaxs[0] = ((GfxEntity *)e)->origin[0];
    ((GfxSceneEntity *)se)->curMaxs[1] = ((GfxEntity *)e)->origin[1];
    ((GfxSceneEntity *)se)->curMaxs[2] = ((GfxEntity *)e)->origin[2];
    ((GfxSceneEntity *)se)->cullState = 2;
}


/* line 1836 */
/* line 1836 — Pre-skin XModel surface: resolves material from skin/LOD, sets up
 * surface entry for skinned (type 3) or rigid (type 4) rendering, allocates
 * cached vertex buffer space if available. Returns surface data size or 0 on failure. */
static int R_PreSkinXSurface(GfxSceneEntity *sceneEnt, const struct DObj_s *obj, long unsigned int (*surface)[32], int surfaceIndex, char *lods, byte *surfPos)
{
    int surfIdx = *(short *)surface;
    int skinIndex;
    void *model, *skins, *xsurf;
    void *material;

    model = DObjGetModel(obj, surfIdx);
    skins = XModelGetSkins(model);
    if (!skins) return 0;

    skinIndex = (signed char)lods[surfIdx];
    {
        int xsurfOfs = *(short *)((char *)surface + 2);
        material = *(void **)((char *)*(void **)((char *)skins + skinIndex * 4) + xsurfOfs * 4);
    }
    xsurf = DObjGetSurface(obj, surfIdx, *(short *)((char *)surface + 2), skinIndex);

    /* Set material in scene surface list */
    ((GfxSceneEntity *)sceneEnt)->materials[surfaceIndex] = (const Material *)material;

    /* Check if surface has skinning data */
    if (((XSurface *)xsurf)->surfRigid.vb) {
        /* Rigid surface */
        *(int *)surfPos = 4;
        *(void **)(surfPos + 4) = xsurf;
        return 0x38;
    }

    /* Skinned surface: check if cached skinning is available */
    if (*(byte *)(*(char **)imp_r_skinCache + 8) && ((XSurface *)xsurf)->indexBuffer) {
        *(int *)(surfPos + 0xc) = 0;
        int vertCount = XSurfaceGetNumVerts(xsurf);
        int isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);
        int stride = isDx7 ? 0x24 : 0x40;
        char *dx = (char *)imp_dx;

        if (((DxGlobals *)dx)->skinnedCacheLockAddr) {
            /* Try allocating from locked skin cache */
            char *fed = *(char **)imp_frontEndDataOut;
            void *lockPtr = ((GfxBackEndData *)fed)->skinnedCacheVb;
            int offset = InterlockedExchangeAdd((volatile int *)lockPtr, vertCount * stride);
            int capacity = *(int *)((char *)lockPtr + 4);
            if (*(int *)lockPtr > capacity) {
                if (offset <= capacity) {
                    InterlockedExchange((volatile int *)lockPtr, offset);
                }
                if (*(int *)fed != warnCount) {
                    warnCount = *(int *)fed;
                    (*(int (**)(int, const char *, ...))imp_ri)(2, "MAX_SKINNED_CACHE_VERTICES exceeded\n");
                }
                offset = -1;
            }
            *(int *)(surfPos + 8) = offset;
            if (offset >= 0) {
                void *basePtr = ((DxGlobals *)dx)->skinnedCacheLockAddr;
                if ((char *)basePtr + *(int *)lockPtr) {
                    /* Cached path */
                    *(int *)surfPos = 3;
                    *(void **)(surfPos + 4) = xsurf;
                    return 0x10;
                }
            }
        }
    }

    /* Uncached skinned path: allocate from dynamic VB */
    *(int *)(surfPos + 8) = -1;
    {
        int vertCount = XSurfaceGetNumVerts(xsurf);
        int isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);
        int stride = isDx7 ? 0x24 : 0x40;
        int needed = vertCount * stride;
        char *dx = (char *)imp_dx;
        int current = ((DxGlobals *)dx)->tempSkinPos;
        if (current + needed > 0xa00000) {
            char *fed = *(char **)imp_frontEndDataOut;
            if (*(int *)fed != warnCount) {
                warnCount = *(int *)fed;
                (*(int (**)(int, const char *, ...))imp_ri)(2, "Exceeded dynamic vertex buffer limit\n");
            }
            return 0;
        }
        *(int *)(surfPos + 0xc) = (int)(uintptr_t)((DxGlobals *)dx)->tempSkinBuf + current;
        ((DxGlobals *)dx)->tempSkinPos += needed;
        /* Lock and zero the buffer */
        ((void (*)(void *, int))ri.Z_VirtualCommitInternal)((void *)*(int *)(surfPos + 0xc), needed);
    }
    *(int *)surfPos = 3;
    *(void **)(surfPos + 4) = xsurf;
    return 0x10;
}


/* line 2469 */
/* line 2469 — Scene DObj skinning: validates DObj, gets surfaces and bone matrices,
 * allocates scene surface entries, pre-skins each surface, copies to front-end buffer,
 * then queues a SkinXModelCmd or SkinRigidXModelCmd for the render thread. */
extern int InterlockedExchangeAdd(volatile int *dest, int value);
extern void R_AddFrontendCmd(int cmdType, const void *cmd);
extern int DObjGetMatOffset(const void *obj, int surfIndex);
void R_SkinSceneDObj(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    char *se = (char *)sceneEnt;
    void *obj = (void *)sceneEnt->u.data;
    int surfaceCount, boneCount;
    const DObjAnimMat *boneMatrix;
    short surfaces[67];
    int partBits[4];
    char lods[8];
    byte surfBuf[3520]; /* large buffer for pre-skinned surface data */

    /* Check state: must be <= 3 */
    if (((GfxSceneEntity *)se)->cullState > 3)
        return;

    /* Atomic compare-exchange: claim state 2→3 */
    if (InterlockedCompareExchange(&((GfxSceneEntity *)se)->cullState, 2, 3) != 2) {
        while (((GfxSceneEntity *)se)->cullState <= 3)
            ;
        return;
    }

    /* Validate DObj */
    if (DObjBad(obj)) {
        if (*(int *)(*(char **)imp_developer + 8)) {
            R_XModelDebugBoxes_impl((const byte *)sceneEnt, (const byte *)ent, obj);
            R_XModelDebugAxes_impl((const byte *)sceneEnt, (const byte *)ent, obj);
        }
        ((GfxSceneEntity *)se)->cullState = 4;
        return;
    }

    /* Get bone count and surface data */
    boneCount = DObjNumBones(obj);
    {
        int sc;
        sc = R_GetSurfaceData_impl((const byte *)ent, obj, surfaces, partBits, lods);
        surfaceCount = sc;
    }
    if (surfaceCount == 0) {
        ((GfxSceneEntity *)se)->cullState = 4;
        return;
    }

    /* Get bone rotation/translation array */
    boneMatrix = (const DObjAnimMat *)DObjGetRotTransArray(obj);
    if (!boneMatrix) {
        ((GfxSceneEntity *)se)->cullState = 4;
        return;
    }

    /* Allocate scene surface entries atomically */
    {
        char *scene = (char *)imp_scene;
        int startIndex = InterlockedExchangeAdd((volatile int *)&((GfxScene *)scene)->sceneEntMaterialCount, surfaceCount);
        extern int __mh_execute_header;
        if (startIndex + surfaceCount > (int)(unsigned int)&__mh_execute_header) {
            ((GfxScene *)scene)->sceneEntMaterialCount = (int)(unsigned int)&__mh_execute_header;
            {
                byte *fed = *(byte **)imp_frontEndDataOut;
                if (*(int *)fed != warnCount) {
                    warnCount = *(int *)fed;
                    typedef int (*PrintFunc)(int, const char *, ...);
                    (*(PrintFunc *)imp_ri)(2, "MAX_SCENE_SURFS_PLUS_ENTITIES exceeded\n");
                }
            }
            ((GfxSceneEntity *)se)->cullState = 4;
            return;
        }

        /* Set surface list pointer in scene entity */
        ((GfxSceneEntity *)se)->materials = (const Material **)(scene + 0x1a560 + startIndex * 4);
    }

    /* Pre-skin each surface */
    {
        byte *surfPtr = surfBuf;
        int i;

        for (i = 0; i < surfaceCount; i++) {
            int result = R_PreSkinXSurface(sceneEnt, (const struct DObj_s *)obj,
                (long unsigned int (*)[32])&surfaces[i], i, lods, surfPtr);
            if (!result) {
                ((GfxSceneEntity *)se)->cullState = 4;
                return;
            }
            surfPtr += result;
        }

        /* Allocate front-end buffer and copy surface data */
        {
            int size = (int)(surfPtr - surfBuf);
            byte *fed = *(byte **)imp_frontEndDataOut;
            int offset = InterlockedExchangeAdd((volatile int *)&((GfxBackEndData *)fed)->surfPos, size);
            if (offset + size > 0x20000) {
                ((GfxBackEndData *)fed)->surfPos = 0x20000;
                if (*(int *)fed != warnCount) {
                    warnCount = *(int *)fed;
                    typedef int (*PrintFunc)(int, const char *, ...);
                    (*(PrintFunc *)imp_ri)(2, "MAX_SKINNED_CACHE exceeded\n");
                }
                ((GfxSceneEntity *)se)->cullState = 4;
                return;
            }

            ((GfxSceneEntity *)se)->surfs = (surfaceType_t *)(fed + 0x8000c + offset);
            memcpy(fed + 0x8000c + offset, surfBuf, size);
        }
    }

    /* Set surface count */
    ((GfxSceneEntity *)se)->surfCount = surfaceCount;

    /* Debug rendering if r_xdebug */
    {
        char *xdebugDvar = *(char **)imp_r_xdebug;
        int xdebug = *(int *)(xdebugDvar + 8);
        if (xdebug) {
            if (xdebug & 1) {
                R_XModelDebugBoxes_impl((const byte *)sceneEnt, (const byte *)ent, obj);
                xdebugDvar = *(char **)imp_r_xdebug;
            }
            if (*(int *)(xdebugDvar + 8) & 2) {
                R_XModelDebugAxes_impl((const byte *)sceneEnt, (const byte *)ent, obj);
            }
        }
    }

    /* Build and queue skinning command */
    if (boneCount == 1) {
        /* Single bone: use rigid skinning command */
        SkinRigidXModelCmd rigidCmd;
        rigidCmd.surfs = ((GfxSceneEntity *)se)->surfs;
        rigidCmd.surfCount = surfaceCount;
        rigidCmd.e = (GfxEntity *)ent;
        /* Copy DObjAnimMat (32 bytes) */
        memcpy(&rigidCmd.mat, boneMatrix, sizeof(DObjAnimMat));
        R_AddFrontendCmd(2, &rigidCmd);
    } else {
        /* Multi-bone: build SkinXModelCmd with per-surface mat offsets */
        SkinXModelCmd skinCmd;
        int i;
        skinCmd.surfs = ((GfxSceneEntity *)se)->surfs;
        skinCmd.surfCount = (byte)surfaceCount;
        skinCmd.e = (GfxEntity *)ent;
        skinCmd.mat = boneMatrix;
        skinCmd.boneCount = (byte)boneCount;

        for (i = 0; i < surfaceCount; i++) {
            skinCmd.matOffset[i] = (byte)DObjGetMatOffset(obj, (int)(short)surfaces[i]);
        }

        R_AddFrontendCmd(surfaceCount > 10 ? 7 : 6, &skinCmd);
    }

    ((GfxSceneEntity *)se)->cullState = 4;
}


/* line 1949 — Pre-skin static model surface: resolves material from skin/LOD, checks
 * for static model cache (SMC) availability, allocates cached or dynamic VB space. */
extern void *R_CacheStaticModelSurface(void *staticSurf, void *xsurf, int smodelIndex, void *material);
extern void R_UsedCachedStaticModelSurface(void *cached);
static int R_PreSkinStaticSurface(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex,
    const struct XModel *model, XSurface *xsurf, int surfaceIndex, int lod,
    qboolean *needSkinningSurf, byte *surfPos)
{
    void *skins = XModelGetSkins((void *)model);
    if (!skins) return 0;

    /* Set material in scene surface list */
    {
        void *material = *(void **)((char *)*(void **)((char *)skins + lod * 4) + surfaceIndex * 4);
        ((GfxSceneEntity *)sceneEnt)->materials[surfaceIndex] = (const Material *)material;
    }

    /* Check for static model cached surface (SMC) */
    if (ent->reType == 2 && *(byte *)(*(char **)imp_r_smc_enable + 8)) {
        void *xsurfMat = (void *)xsurf;
        if (XSurfaceGetBoneOffset((int)(intptr_t)xsurfMat) != -1) {
            int isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);
            if (!isDx7) {
                /* Check for valid material technique for SMC */
                void *mat = (void *)((GfxSceneEntity *)sceneEnt)->materials[surfaceIndex];
                void *techSet = (void *)((Material *)mat)->techniqueSet;
                MaterialTechnique *tech34 = ((MaterialTechniqueSet *)techSet)->techniques[12];
                if (tech34 && tech34->passCount && tech34->passArray.dx7[0].gridLighting) {
                    goto try_smc;
                }
            } else {
                try_smc: {
                    void *smcData = ((r_globals_t *)imp_rg)->smodelDyncs;
                    char *staticSurf = (char *)*(void **)((char *)smcData + smodelIndex * 8 + 4) + surfaceIndex * 16;
                    void *cached = *(void **)(staticSurf + lod * 4);
                    if (!cached) {
                        void *mat = (void *)((GfxSceneEntity *)sceneEnt)->materials[surfaceIndex];
                        cached = R_CacheStaticModelSurface(staticSurf, xsurf, smodelIndex, mat);
                        *(void **)(staticSurf + lod * 4) = cached;
                        if (!cached) goto no_smc;
                    }
                    R_UsedCachedStaticModelSurface(cached);
                    *(int *)surfPos = 5;
                    *(void **)(surfPos + 4) = xsurf;
                    *(void **)(surfPos + 8) = cached;
                    *(void **)(surfPos + 0xc) = ent;
                    return 0x10;
                }
            }
        }
    }
no_smc:

    /* Check if surface has pre-built rigid skinning */
    if (((XSurface *)xsurf)->surfRigid.vb) {
        *(int *)surfPos = 4;
        *(void **)(surfPos + 4) = xsurf;
        *needSkinningSurf = 1;
        return 0x38;
    }

    /* Skinned surface: allocate from cache or dynamic VB */
    /* (Same pattern as R_PreSkinXSurface) */
    if (*(byte *)(*(char **)imp_r_skinCache + 8) && ((XSurface *)xsurf)->indexBuffer) {
        *(int *)(surfPos + 0xc) = 0;
        int vertCount = XSurfaceGetNumVerts(xsurf);
        int isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);
        int stride = isDx7 ? 0x24 : 0x40;
        char *dx = (char *)imp_dx;
        if (((DxGlobals *)dx)->skinnedCacheLockAddr) {
            char *fed = *(char **)imp_frontEndDataOut;
            void *lockPtr = ((GfxBackEndData *)fed)->skinnedCacheVb;
            int offset = InterlockedExchangeAdd((volatile int *)lockPtr, vertCount * stride);
            if (*(int *)lockPtr > *(int *)((char *)lockPtr + 4)) {
                if (offset <= *(int *)((char *)lockPtr + 4))
                    InterlockedExchange((volatile int *)lockPtr, offset);
                if (*(int *)fed != warnCount) {
                    warnCount = *(int *)fed;
                    (*(int (**)(int, const char *, ...))imp_ri)(2, "MAX_SKINNED_CACHE_VERTICES exceeded\n");
                }
                offset = -1;
            }
            *(int *)(surfPos + 8) = offset;
            if (offset >= 0 && (char *)((DxGlobals *)dx)->skinnedCacheLockAddr + *(int *)lockPtr) {
                *(int *)surfPos = 3;
                *(void **)(surfPos + 4) = xsurf;
                *needSkinningSurf = 1;
                return 0x10;
            }
        }
    }
    *(int *)(surfPos + 8) = -1;
    {
        int vertCount = XSurfaceGetNumVerts(xsurf);
        int isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);
        int stride = isDx7 ? 0x24 : 0x40;
        int needed = vertCount * stride;
        char *dx = (char *)imp_dx;
        int current = ((DxGlobals *)dx)->tempSkinPos;
        if (current + needed > 0xa00000) {
            char *fed = *(char **)imp_frontEndDataOut;
            if (*(int *)fed != warnCount) {
                warnCount = *(int *)fed;
                (*(int (**)(int, const char *, ...))imp_ri)(2, "Exceeded dynamic vertex buffer limit\n");
            }
            return 0;
        }
        *(int *)(surfPos + 0xc) = (int)(uintptr_t)((DxGlobals *)dx)->tempSkinBuf + current;
        ((DxGlobals *)dx)->tempSkinPos += needed;
        ((void (*)(void *, int))ri.Z_VirtualCommitInternal)((void *)*(int *)(surfPos + 0xc), needed);
    }
    *(int *)surfPos = 3;
    *(void **)(surfPos + 4) = xsurf;
    *needSkinningSurf = 1;
    return 0x10;
}


/* line 2276 — XModel skinning for static models: validates model, computes LOD,
 * gets surfaces, pre-skins, copies to front-end buffer, queues skinning command. */
extern int XModelNumBones(const void *model);
extern int XModelGetSurfaces(const void *model, void **surfaces, int lod, int *partBits);
extern int XModelGetLodForDist(const void *model, float dist);
extern const DObjAnimMat *XModelGetBasePose(const void *model);
static void R_SkinXModel(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex)
{
    char *se = (char *)sceneEnt;
    char *e = (char *)ent;
    void *model = (void *)((GfxSceneEntity *)se)->u.data;
    int boneCount, surfaceCount, lod;
    void *surfacesPtr;
    int partBits[4];
    qboolean needSkinningSurf = 0;
    byte surfBuf[3520];

    if (((GfxSceneEntity *)se)->cullState > 3) return;
    if (InterlockedCompareExchange(&((GfxSceneEntity *)se)->cullState, 2, 3) != 2) {
        while (((GfxSceneEntity *)se)->cullState <= 3) ;
        return;
    }

    if (XModelBad(*(union XAssetHeader *)&model)) {
        if (*(int *)(*(char **)imp_developer + 8)) {
            void *defaultObj = ((r_globals_t *)imp_rg)->modelDObj;
            DObjSetModel((struct DObj_s *)defaultObj, model);
            R_XModelDebugBoxes_impl((const byte *)sceneEnt, (const byte *)ent, defaultObj);
            R_XModelDebugAxes_impl((const byte *)sceneEnt, (const byte *)ent, defaultObj);
        }
        ((GfxSceneEntity *)se)->cullState = 4; return;
    }

    boneCount = XModelNumBones(model);

    /* Compute LOD based on distance */
    {
        r_globals_t *rg = (r_globals_t *)imp_rg;
        float dist = Vec3Distance(((GfxEntity *)e)->origin, rg->lodParms.origin);
        dist = dist * rg->lodParms.scale + rg->lodParms.bias;
        float scale = ((GfxEntity *)e)->scale;
        if (scale != 0.0f)
            dist /= scale;
        lod = XModelGetLodForDist(model, dist);
    }
    if (lod < 0) { ((GfxSceneEntity *)se)->cullState = 4; return; }

    surfaceCount = XModelGetSurfaces(model, &surfacesPtr, lod, partBits);

    /* Allocate scene surface entries */
    {
        char *scene = (char *)imp_scene;
        int startIdx = InterlockedExchangeAdd((volatile int *)&((GfxScene *)scene)->sceneEntMaterialCount, surfaceCount);
        extern int __mh_execute_header;
        if (startIdx + surfaceCount > (int)(unsigned int)&__mh_execute_header) {
            ((GfxScene *)scene)->sceneEntMaterialCount = (int)(unsigned int)&__mh_execute_header;
            byte *fed = *(byte **)imp_frontEndDataOut;
            if (*(int *)fed != warnCount) {
                warnCount = *(int *)fed;
                (*(int (**)(int, const char *, ...))imp_ri)(2, "MAX_SCENE_SURFS_PLUS_ENTITIES exceeded\n");
            }
            ((GfxSceneEntity *)se)->cullState = 4; return;
        }
        ((GfxSceneEntity *)se)->materials = (const Material **)(scene + 0x1a560 + startIdx * 4);
    }

    /* Pre-skin each surface */
    {
        byte *surfPtr = surfBuf;
        int i;
        void **surfArray = (void **)surfacesPtr;
        for (i = 0; i < surfaceCount; i++) {
            int result = R_PreSkinStaticSurface(sceneEnt, ent, smodelIndex,
                (const struct XModel *)model, (XSurface *)surfArray[i], i, lod, &needSkinningSurf, surfPtr);
            if (!result) { ((GfxSceneEntity *)se)->cullState = 4; return; }
            surfPtr += result;
        }

        /* Copy to front-end buffer */
        {
            int size = (int)(surfPtr - surfBuf);
            byte *fed = *(byte **)imp_frontEndDataOut;
            int offset = InterlockedExchangeAdd((volatile int *)&((GfxBackEndData *)fed)->surfPos, size);
            if (offset + size > 0x20000) {
                ((GfxBackEndData *)fed)->surfPos = 0x20000;
                if (*(int *)fed != warnCount) {
                    warnCount = *(int *)fed;
                    (*(int (**)(int, const char *, ...))imp_ri)(2, "MAX_SKINNED_CACHE exceeded\n");
                }
                ((GfxSceneEntity *)se)->cullState = 4; return;
            }
            ((GfxSceneEntity *)se)->surfs = (surfaceType_t *)(fed + 0x8000c + offset);
            memcpy(fed + 0x8000c + offset, surfBuf, size);
        }
    }

    ((GfxSceneEntity *)se)->surfCount = surfaceCount;

    /* Debug rendering */
    {
        int xdebug = *(int *)(*(char **)imp_r_xdebug + 8);
        if (xdebug) {
            void *defaultObj = ((r_globals_t *)imp_rg)->modelDObj;
            DObjSetModel((struct DObj_s *)defaultObj, model);
            if (xdebug & 1) {
                R_XModelDebugBoxes_impl((const byte *)sceneEnt, (const byte *)ent, defaultObj);
            }
            if (*(int *)(*(char **)imp_r_xdebug + 8) & 2) {
                R_XModelDebugAxes_impl((const byte *)sceneEnt, (const byte *)ent, defaultObj);
            }
        }
    }

    if (!needSkinningSurf) { ((GfxSceneEntity *)se)->cullState = 4; return; }

    /* Queue skinning command */
    {
        const DObjAnimMat *basePose = XModelGetBasePose(model);
        if (boneCount == 1) {
            SkinRigidXModelCmd rigidCmd;
            rigidCmd.surfs = ((GfxSceneEntity *)se)->surfs;
            rigidCmd.surfCount = surfaceCount;
            rigidCmd.e = (GfxEntity *)ent;
            memcpy(&rigidCmd.mat, basePose, sizeof(DObjAnimMat));
            R_AddFrontendCmd(2, &rigidCmd);
        } else {
            SkinXModelCmd skinCmd;
            int i;
            skinCmd.surfs = ((GfxSceneEntity *)se)->surfs;
            skinCmd.surfCount = (byte)surfaceCount;
            skinCmd.e = (GfxEntity *)ent;
            skinCmd.mat = basePose;
            skinCmd.boneCount = (byte)boneCount;
            memcpy(skinCmd.surfacePartBits, *(int **)&partBits[0], 16);
            for (i = 0; i < surfaceCount; i++)
                skinCmd.matOffset[i] = 0;
            R_AddFrontendCmd(surfaceCount > 10 ? 7 : 6, &skinCmd);
        }
    }
    ((GfxSceneEntity *)se)->cullState = 4;
}


/* line 2651 */
void R_SkinStaticModel(GfxSceneEntity *sceneEnt, GfxEntity *ent, int smodelIndex)
{
    R_SkinXModel(sceneEnt, ent, smodelIndex);
}

/* line 2639 */
void R_SkinSceneEnt(GfxSceneEntity *sceneEnt, GfxEntity *ent)
{
    if (ent->reType == 1)
        R_SkinXModel(sceneEnt, ent, -1);
    else
        R_SkinSceneDObj(sceneEnt, ent);
}

/* line 1735 */
/* line 1735 — Vertex skinning kernel: transforms each vertex through its bone matrix(es).
 * Register convention: eax=skinnedSurf (surfType_t*), edx=boneMatrix (DObjSkelMat*).
 * Algorithm:
 *   1. Get XSurface from skinnedSurf[1], output buffer offset from skinnedSurf[2]
 *   2. Determine output buffer: cached VB (offset >= 0) or dynamic VB (offset == -1)
 *   3. XSurfaceGetBoneOffset → add to boneMatrix base for this surface's bone subset
 *   4. For Dx7 (stride 36): transform pos through bone 3x4 matrix, copy normal+color+texcoord
 *   5. For non-Dx7 (stride 64): transform pos, normal, tangent, binormal through matrix
 *   6. Handle single-bone (rigid) vs multi-bone (weighted) paths
 *   7. Uses SSE for matrix×vector multiplication in non-Dx7 weighted path
 * 594 lines of vertex transformation — performance-critical skinning hot path. */
static void R_SkinXSurfaceSkinned(const DObjSkelMat *boneMatrix) { (void)boneMatrix; }

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
            R_SkinXSurfaceSkinned(boneMatrix);
            (void)surfPos;
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
                    refEnt->origin,
                    refEnt->axis,
                    refEnt->scale,
                    (vec3_t *)(rigidSurf + 8));
            }
        }
    }
}


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

    /* Copy translation into matrix row 3 */
    mtx[12] = skinRigidCmd->mat.trans[0];
    mtx[13] = skinRigidCmd->mat.trans[1];
    mtx[14] = skinRigidCmd->mat.trans[2];
    mtx[15] = 1.0f; /* homogeneous w */

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
            float entScale = refEnt->scale;
            int boneOffset = XSurfaceGetBoneOffset(*(int *)(rigidSurf + 4));
            R_GetRigidTransform(
                (const DObjSkelMat *)((byte *)mtx + boneOffset),
                refEnt->origin,
                refEnt->axis,
                entScale,
                (vec3_t *)(rigidSurf + 8)
            );
        } else {
            /* Standard skinned surface: call R_SkinXSurfaceSkinned(eax=surfPos, edx=mtx) */
            byte *surf = surfPos;
            surfPos += 0x10;
            R_SkinXSurfaceSkinned((const DObjSkelMat *)mtx);
            (void)surf;
        }
    }
}
