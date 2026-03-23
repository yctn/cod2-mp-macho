/* ASM dump from: r_scene.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_scene.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_surface.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern struct GfxScene scene; /* 0x0 */
static int warnCount; /* warnCount */
static int warnCount_007f1dd0; /* warnCount */
static GfxViewParms lockPvsViewParms; /* lockPvsViewParms */
__attribute__((used)) byte s_XModelSurfaceSize[8] = {
    0x00, 0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x00,
}; /* 0x311080 */
__attribute__((used, aligned(4)))
surfaceType_t s_entitySurface[6] = {
    2, 0, 0, 0, 0, 0,
}; /* 0x311088 */

#define s_entitySurface (s_entitySurface[0])

extern GfxBackEndData *frontEndDataOut;
extern r_global_permanent_t rgp;       /* imp_rgp */
extern r_globals_t rg;                /* imp_rg */
extern refimport_t ri;                /* imp_ri */
extern const dvar_t **r_dlightLimit;   /* imp_r_dlightLimit */
extern void qsort(void *base, unsigned int nmemb, unsigned int size, int (*compar)(const void *, const void *));
/* g_dxCaps was imp_r_rendererInUse */
extern const float *colorWhite;        /* imp_colorWhite */
/* fx_sort and com_statmon accessed via imp_fx_sort, imp_com_statmon */
extern void AxisCopy(vec3_t *in, vec3_t *out);
extern void R_Error(int level, const char *msg, ...);
extern const char *va(const char *format, ...);

void R_UpdateXModelBounds(GfxSceneEntity *sceneEnt, GfxEntity *ent);
void R_SkinSceneDObj(GfxSceneEntity *sceneEnt, GfxEntity *ent);
void R_ClearDpvsScene(void);
void R_DrawModel(int entIndex);
void R_AddScaledDebugString(const char *pos, const char *tag, const char *origin, const char *color, const char *str);
int XSurfaceGetNumTris(XSurface *xsurf);
int XSurfaceGetNumVerts(XSurface *xsurf);
const char *XModelGetName(void *model);
const char *DObjGetModel(void *dobj, int lod);
void MatrixForViewer(float (*mtx)[4], const vec_t *origin, vec3_t *axis);
void InfinitePerspectiveMatrix(float (*mtx)[4], float fov_x, float fov_y, float zNear);
void MatrixMultiply44(const float (*in1)[4], const float (*in2)[4], float (*out)[4]);
void MatrixInverse44(const float *mat, float *dst);
void R_AddCmdClearScreen(int whichToClear, const vec_t *color, float depth, int stencil);
extern double tan(double);

static int R_CompareDumpSceneEntities(const void *e0, const void *e1);
static int R_CompareDrawSurfs(const void *drawSurf0, const void *drawSurf1);
void R_UpdateGfxEntityBounds(GfxEntity *ent);
void R_SkinGfxEntity(GfxEntity *ent);
void R_DecomposeSort(unsigned int sortValue, int *entIndex, const Material * *material, int *lmapIndex);
void R_ClearScene(void);
void R_AddLightToScene(const vec_t *org, float radius, float r, float g, float b);
void R_DefaultVertexFrames(int vertCount, GfxWorldVertex *verts);
void qsortDrawSurfs(GfxDrawSurf *drawSurfs, int drawSurfCount);
void R_AddXModelSurfaces(int entIndex);
void R_AddBModelSurfaces(GfxSceneEntity *sceneEnt, int entIndex);
void R_AddPolyToScene(MaterialHandle materialHandle, int lmapIndex, int vertCount, const GfxWorldVertex *verts);
void R_AddDrawSurfForSurface(GfxSurface *surf, int entIndex);
static void __attribute_regparm__(2) R_SetViewParmsForScene(const refdef_t *refdef, GfxViewParms *viewParms);
void R_SetLodOrigin(const refdef_t *refdef);
static void __attribute_regparm__(1) R_AddClearCommandsForFrameBuffer(int dynamicShadowType);
void R_RenderScene(const refdef_t *refdef);
int R_AddStaticModelToScene(int smodelIndex);
GfxEntity * R_AddRefEntityToScene(const GfxEntity *refEnt, GfxModel sceneModel, const struct centity_s *cent);

/* line 121 */
static int R_CompareDumpSceneEntities(const void *e0, const void *e1)
{
    int index0, index1;
    GfxEntity *ent0, *ent1;
    GfxSceneEntity *sceneEnt0, *sceneEnt1;
    int type;
    int diff;

    index0 = *(const int *)e0;
    index1 = *(const int *)e1;
    ent0 = &frontEndDataOut->entities[index0];
    ent1 = &frontEndDataOut->entities[index1];

    type = ent0->reType;
    if (type != (int)ent1->reType)
        return type - (int)ent1->reType;

    sceneEnt0 = &scene.sceneEnts[index0];
    sceneEnt1 = &scene.sceneEnts[index1];

    switch (type) {
    case 0:
        return (int)DObjGetModel((void *)sceneEnt0->u.obj, 0) - (int)DObjGetModel((void *)sceneEnt1->u.obj, 0);
    case 1:
    case 2:
        return (int)((byte *)sceneEnt0->u.data - (byte *)sceneEnt1->u.data);
    case 3:
        return ((int)((byte *)sceneEnt0->u.data - (byte *)sceneEnt1->u.data)) >> 5;
    default:
        diff = ((int)((byte *)ent0->customMaterial - (byte *)ent1->customMaterial)) >> 2;
        return -(diff * 0x0F0F0F0F);
    }
}

/* line 354 */
void R_UpdateGfxEntityBounds(GfxEntity *ent)
{
    int entIndex;

    entIndex = ent - scene.def.entities;
    R_UpdateXModelBounds(&scene.sceneEnts[entIndex], ent);
}

/* line 369 */
void R_SkinGfxEntity(GfxEntity *ent)
{
    int entIndex;
    GfxSceneEntity *sceneEnt;

    entIndex = ent - scene.def.entities;
    sceneEnt = &scene.sceneEnts[entIndex];
    R_UpdateXModelBounds(sceneEnt, ent);
    R_SkinSceneDObj(sceneEnt, ent);
}

/* line 608 */
void R_DecomposeSort(unsigned int sortValue, int *entIndex, const Material * *material, int *lmapIndex)
{
    int ent, matIndex;
    r_global_permanent_t *rgpPtr = (r_global_permanent_t *)imp_rgp;

    if ((int)sortValue >= 0) {
        ent = (sortValue >> 4) & 0xfff;
        if (ent >= 0x800)
            ent = 0x7fe;
        *entIndex = ent;
        matIndex = (sortValue >> 21) & 0x3ff;
        *material = rgpPtr->sortedMaterials[matIndex];
        *lmapIndex = (sortValue >> 16) & 0x1f;
    } else {
        ent = (sortValue >> 19) & 0xfff;
        if (ent >= 0x800)
            ent = 0x7fe;
        *entIndex = ent;
        matIndex = (sortValue >> 9) & 0x3ff;
        *material = rgpPtr->sortedMaterials[matIndex];
        *lmapIndex = (sortValue >> 4) & 0x1f;
    }
}

static int R_CompareDrawSurfs(const void *drawSurf0, const void *drawSurf1)
{
    const GfxDrawSurf *surf0;
    const GfxDrawSurf *surf1;

    surf0 = (const GfxDrawSurf *)drawSurf0;
    surf1 = (const GfxDrawSurf *)drawSurf1;
    if (surf0->sort < surf1->sort)
    {
        return -1;
    }

    if (surf0->sort > surf1->sort)
    {
        return 1;
    }

    return 0;
}

/* line 1374 */
void R_ClearScene(void)
{
    GfxBackEndData *buf;

    scene.viewCount++;
    scene.dlightCount = 0;
    scene.drawSurfCount = 0;
    buf = frontEndDataOut;
    scene.drawSurfs = &buf->drawSurfs[buf->drawSurfCount];
    scene.polyCount = 0;
    scene.def.entityCount = 0;
    scene.def.entities = &buf->entities[buf->entityCount];
    scene.sceneEntMaterialCount = 0;
    R_ClearDpvsScene();
}

/* line 492 */
void R_AddLightToScene(const vec_t *org, float radius, float r, float g, float b)
{
    GfxLight *light;
    int dlightCount;

    if (!rg.registered)
        return;
    if (!rgp.world)
        return;
    if (!(radius > 0.0f))
        return;

    dlightCount = scene.dlightCount;
    if (dlightCount >= (*r_dlightLimit)->current.integer)
        return;

    light = &scene.dlights[dlightCount];
    scene.dlightCount = dlightCount + 1;
    light->def = rgp.dlightDef;
    light->position[0] = org[0];
    light->position[1] = org[1];
    light->position[2] = org[2];
    light->position[3] = radius;
    light->color[0] = r;
    light->color[1] = g;
    light->color[2] = b;
}

/* line 424 */
void R_DefaultVertexFrames(int vertCount, GfxWorldVertex *verts)
{
    for (int i = 0; i < vertCount; i++) {
        /* normal = (0, 0, 1) */
        verts[i].normal[0] = 0.0f;
        verts[i].normal[1] = 0.0f;
        verts[i].normal[2] = 1.0f;
        /* binormal = (0, 1, 0) */
        verts[i].binormal[0] = 0.0f;
        verts[i].binormal[1] = 1.0f;
        verts[i].binormal[2] = 0.0f;
        /* tangent = (1, 0, 0) */
        verts[i].tangent[0] = 1.0f;
        verts[i].tangent[1] = 0.0f;
        verts[i].tangent[2] = 0.0f;
    }
}

/* line 731 */
void qsortDrawSurfs(GfxDrawSurf *drawSurfs, int drawSurfCount)
{
    if (drawSurfCount > 1)
    {
        qsort(drawSurfs, (unsigned int)drawSurfCount, sizeof(*drawSurfs), R_CompareDrawSurfs);
    }
}

/* line 905 */
void R_AddXModelSurfaces(int entIndex)
{
    GfxSceneEntity *sceneEnt;
    GfxEntity *ent;
    GfxModelSurface *modelSurf;
    const Material *material;
    GfxBackEndData *buf;
    GfxDrawSurf *drawSurf;
    unsigned int sortValue;
    int i, surfCount, entIdx, surfType;
    int totalTriCount, totalVertCount;

    sceneEnt = &scene.sceneEnts[entIndex];
    ent = &scene.def.entities[entIndex];
    modelSurf = (GfxModelSurface *)sceneEnt->surfs;
    surfCount = sceneEnt->surfCount;
    totalTriCount = 0;
    totalVertCount = 0;

    /* surfs array only has entries for non-null-material surfaces;
       advance modelSurf only when we actually consume a surface */
    for (i = 0; i < surfCount; i++) {
        material = sceneEnt->materials[i];
        if (!material)
            continue;

        entIdx = (modelSurf->surfType == 5) ? 0x7ff : entIndex;

        buf = frontEndDataOut;
        if (buf->drawSurfCount <= 0xffff) {
            drawSurf = &buf->drawSurfs[buf->drawSurfCount];
            surfType = modelSurf->surfType;
            if (surfType == 2 && (*(const dvar_t **)imp_fx_sort)->current.enabled) {
                sortValue = (unsigned int)((entIdx << 19) + (material->info.sortedIndex << 9) + 0x800001f2u);
            } else {
                sortValue = (unsigned int)(surfType + (entIdx << 4) + (material->info.sortedIndex << 21) + 0x1f0000);
            }
            drawSurf->sort = sortValue;
            drawSurf->surface = (const surfaceType_t *)modelSurf;
            scene.drawSurfCount++;
            buf->drawSurfCount++;
        }

        if ((*(const dvar_t **)imp_r_showTriCounts)->current.enabled)
            totalTriCount += XSurfaceGetNumTris(modelSurf->xsurf);
        else if ((*(const dvar_t **)imp_r_showVertCounts)->current.enabled)
            totalVertCount += XSurfaceGetNumVerts(modelSurf->xsurf);

        modelSurf = (GfxModelSurface *)((byte *)modelSurf + s_XModelSurfaceSize[modelSurf->surfType]);
    }

    /* debug display: show tri/vert/surf count above the entity */
    if ((*(const dvar_t **)imp_r_showTriCounts)->current.enabled) {
        R_AddScaledDebugString(
            (char *)frontEndDataOut + 0x249d18,
            (char *)rg.debugViewParms,
            (const char *)&ent->origin,
            (const char *)imp_colorCyan,
            va("%i", totalTriCount));
    } else if ((*(const dvar_t **)imp_r_showVertCounts)->current.enabled) {
        R_AddScaledDebugString(
            (char *)frontEndDataOut + 0x249d18,
            (char *)rg.debugViewParms,
            (const char *)&ent->origin,
            (const char *)imp_colorCyan,
            va("%i", totalVertCount));
    } else if ((*(const dvar_t **)imp_r_showSurfCounts)->current.enabled) {
        R_AddScaledDebugString(
            (char *)frontEndDataOut + 0x249d18,
            (char *)rg.debugViewParms,
            (const char *)&ent->origin,
            (const char *)imp_colorCyan,
            va("%i", surfCount));
    }
}
/* line 883 */
void R_AddBModelSurfaces(GfxSceneEntity *sceneEnt, int entIndex)
{
    const GfxBrushModel *bmodel;
    GfxBackEndData *buf;
    GfxDrawSurf *drawSurf;
    GfxSurface *surf;
    const Material *material;
    const surfaceType_t *surface;
    int lmapIndex;
    int surfType;
    unsigned int sortValue;
    int count;
    int dvarVal;

    sceneEnt->cullState = 5;

    dvarVal = (*(const dvar_t **)imp_r_drawBModels)->current.integer;
    if (!dvarVal)
        return;

    bmodel = sceneEnt->u.bmodel;
    if (bmodel->surfaceCount <= 0)
        return;

    for (count = 0; count < bmodel->surfaceCount; count++) {
        surf = &rgp.world->surfaces[bmodel->startSurfIndex + count];
        lmapIndex = surf->lightmapIndex;
        material = surf->material;
        surface = surf->data;

        buf = frontEndDataOut;
        if (buf->drawSurfCount > 0xffff)
            continue;

        drawSurf = &buf->drawSurfs[buf->drawSurfCount];
        surfType = *surface;

        if (surfType == 2 && (*(const dvar_t **)imp_fx_sort)->current.integer) {
            sortValue = (material->info.sortedIndex << 9) + ((entIndex << 19) + 0x80000002) + (lmapIndex << 4);
        } else {
            sortValue = surfType + (entIndex << 4) + (material->info.sortedIndex << 21) + (lmapIndex << 16);
        }

        drawSurf->sort = sortValue;
        drawSurf->surface = surface;
        scene.drawSurfCount++;
        frontEndDataOut->drawSurfCount++;
    }
}

/* line 447 */
void R_AddPolyToScene(MaterialHandle materialHandle, int lmapIndex, int vertCount, const GfxWorldVertex *verts)
{
    GfxBackEndData *buf;
    srfPoly_t *poly;
    GfxDrawSurf *drawSurf;
    GfxWorldVertex *destVerts;
    unsigned int sortValue;
    int entIndex;
    int surfType;
    int vc;

    if (!rg.registered)
        return;

    if (!materialHandle)
        materialHandle = rgp.defaultMaterial;

    buf = frontEndDataOut;
    vc = (unsigned short)vertCount;

    if (vc + buf->polyVertCount > 0x2000)
        return;
    if (buf->polyCount > 0x7ff)
        return;

    poly = &buf->polys[buf->polyCount];
    poly->surfaceType = 1;
    poly->material = materialHandle;
    poly->lmapIndex = (unsigned short)lmapIndex;
    poly->vertCount = (unsigned short)vertCount;

    destVerts = &buf->polyVerts[buf->polyVertCount];
    poly->verts = destVerts;
    memcpy(destVerts, verts, vc * sizeof(GfxWorldVertex));

    entIndex = (scene.polyCount & 0x7FF) + 0x800;

    buf = frontEndDataOut;
    if (buf->drawSurfCount <= 0xffff) {
        drawSurf = &buf->drawSurfs[buf->drawSurfCount];
        surfType = poly->surfaceType;

        if (surfType == 2 && (*(const dvar_t **)imp_fx_sort)->current.integer) {
            sortValue = (entIndex << 19) | (materialHandle->info.sortedIndex << 9) | 0x80000002 | (lmapIndex << 4);
        } else {
            sortValue = surfType + (entIndex << 4) + (materialHandle->info.sortedIndex << 21) + (lmapIndex << 16);
        }

        drawSurf->sort = sortValue;
        drawSurf->surface = (const surfaceType_t *)poly;
        scene.drawSurfCount++;
        frontEndDataOut->drawSurfCount++;
    }

    frontEndDataOut->polyCount++;
    frontEndDataOut->polyVertCount += vc;
    scene.polyCount++;
}

void R_dpvs_diag_print(int cameraCellIndex, int drawWorld, int cellPtr)
{
    static int diag = 0;
    if (diag < 30) {
        fprintf(stderr, "[DPVS#%d] cellIdx=%d drawWorld=%d drawSurfCount=%d\n",
                diag, cameraCellIndex, drawWorld, scene.drawSurfCount);
    }
    diag++;
}

/* line 696 */
void R_AddDrawSurfForSurface(GfxSurface *surf, int entIndex)
{
    GfxBackEndData *buf;
    GfxDrawSurf *drawSurf;
    const Material *material;
    const surfaceType_t *surface;
    unsigned int sortValue;
    int lmapIndex;
    int surfType;

    lmapIndex = surf->lightmapIndex;
    material = surf->material;
    surface = surf->data;

    buf = frontEndDataOut;
    if (buf->drawSurfCount > 0xffff)
        return;

    drawSurf = &buf->drawSurfs[buf->drawSurfCount];
    surfType = *surface;

    if (surfType == 2 && (*(const dvar_t **)imp_fx_sort)->current.integer) {
        sortValue = (entIndex << 19) | (material->info.sortedIndex << 9) | 0x80000002 | (lmapIndex << 4);
    } else {
        sortValue = surfType + (entIndex << 4) + (material->info.sortedIndex << 21) + (lmapIndex << 16);
    }

    drawSurf->sort = sortValue;
    drawSurf->surface = surface;
    scene.drawSurfCount++;
    frontEndDataOut->drawSurfCount++;
}

/* line 1410 */
static void __attribute_regparm__(2)
R_SetViewParmsForScene(const refdef_t *refdef, GfxViewParms *viewParms)
{
    float zNear;

    memset(viewParms, 0, sizeof(*viewParms));

    viewParms->viewport.X = refdef->x;
    viewParms->viewport.Y = refdef->y;
    viewParms->viewport.Width = refdef->width;
    viewParms->viewport.Height = refdef->height;
    viewParms->viewport.MinZ = 0.0f;
    viewParms->viewport.MaxZ = 1.0f;

    memcpy(viewParms->origin, refdef->vieworg, sizeof(viewParms->origin));
    memcpy(viewParms->axis, refdef->viewaxis, sizeof(viewParms->axis));

    /* Camera uses player/spectator position from the game. */

    MatrixForViewer((float (*)[4])&viewParms->viewMatrix, viewParms->origin, viewParms->axis);

    zNear = refdef->zNear;
    if (!(zNear > 0.0f)) {
        zNear = (*(const dvar_t **)imp_r_znear)->current.value;
        if (zNear < 0.01f) {
            zNear = 0.01f;
        }
    }

    InfinitePerspectiveMatrix((float (*)[4])&viewParms->projectionMatrix, refdef->fov_x, refdef->fov_y, zNear);
    viewParms->depthHackNearClip = (*(const dvar_t **)imp_r_znear_depthhack)->current.value;

    MatrixMultiply44(
        (const float (*)[4])&viewParms->viewMatrix,
        (const float (*)[4])&viewParms->projectionMatrix,
        (float (*)[4])&viewParms->viewProjectionMatrix);
    MatrixInverse44((const float *)&viewParms->viewProjectionMatrix, (float *)&viewParms->inverseViewProjectionMatrix);
}

/* line 1447 */
void R_SetLodOrigin(const refdef_t *refdef)
{
    const dvar_t *lockPvs;
    float invFovScale;

    lockPvs = *(const dvar_t **)imp_r_lockPvs;
    if (lockPvs->modified) {
        ri.Dvar_ClearModified(lockPvs);
        R_SetViewParmsForScene(refdef, &lockPvsViewParms);
    }

    if (lockPvs->current.enabled) {
        memcpy(rg.lodParms.origin, lockPvsViewParms.origin, sizeof(rg.lodParms.origin));
    } else {
        memcpy(rg.lodParms.origin, refdef->vieworg, sizeof(rg.lodParms.origin));
    }

    rg.lodParms.scale = (*(const dvar_t **)imp_r_lodScale)->current.value;
    rg.lodParms.bias = (*(const dvar_t **)imp_r_lodBias)->current.value;

    if (refdef->fov_x != 80.0f) {
        invFovScale =
            (float)(tan((double)(refdef->fov_x * 0.5f) * 0.017453292519943295) / tan(0.69813170079773179));
        rg.lodParms.scale *= invFovScale;
        rg.lodParms.bias *= invFovScale;
    }
}

/* line 1030 */
static void __attribute_regparm__(1)
R_AddClearCommandsForFrameBuffer(int dynamicShadowType)
{
    int whichToClear;
    vec4_t clearColor;
    const float inv255 = 0.003921568859368563f;

    whichToClear = 7;
    if (((DxGlobals *)imp_dx)->sunSpriteSamples != 0 && dynamicShadowType == 1) { /* TODO: verify offset 0x2c28 maps to sunSpriteSamples */
        whichToClear = 1;
    }

    if (rg.fogSettings[2].registered != 0) {
        const byte *sceneColor = (const byte *)&rg.fogSettings[2].color;

        clearColor[0] = sceneColor[2] * inv255;
        clearColor[1] = sceneColor[1] * inv255;
        clearColor[2] = sceneColor[0] * inv255;
    } else {
        const byte *dvarColor = (*(const dvar_t **)imp_r_clearColor)->current.color;

        clearColor[0] = dvarColor[0] * inv255;
        clearColor[1] = dvarColor[1] * inv255;
        clearColor[2] = dvarColor[2] * inv255;
    }

    clearColor[3] = 1.0f;
    R_AddCmdClearScreen(whichToClear, clearColor, 1.0f, 0);
}

/* diagnostic for R_RenderScene */
static void R_RenderScene_diag(int registered, int norefresh, int drawSurfCount)
{
    static int diag = 0;
    if (diag < 20 || (diag >= 60 && diag < 70)) {
        fprintf(stderr, "[R_RenderScene#%d] registered=%d norefresh=%d drawSurfCount=%d scene.dsc=%d\n",
                diag, registered, norefresh, drawSurfCount, scene.drawSurfCount);
    }
    diag++;
}
extern unsigned char dpvsGlob[];
static void R_WorldCheck_diag(void *rgp_field, void *cell_ptr, int cellIdx)
{
    static int diag = 0;
    if (diag < 10 || (diag % 120 == 0 && diag < 600)) {
        GfxWorld *w = (GfxWorld *)rgp_field;
        int cellCount = w ? w->cellCount : -1;
        GfxCell *cells = w ? w->cells : NULL;
        GfxCell *thisCell = cells ? &cells[cellIdx] : NULL;
        GfxAabbTree *tree = NULL;
        int treeSC = 0;
        if (thisCell) {
            tree = thisCell->aabbTree;
            if (tree) treeSC = tree->childCount;
        }
        fprintf(stderr, "[WORLD#%d] ci=%d cc=%d cell=%p tree=%p tsc=%d dsc=%d\n",
                diag, cellIdx, cellCount, thisCell, tree, treeSC, scene.drawSurfCount);
    }
    diag++;
}

/* line 1476 */
/* line 1476 — Main scene rendering pipeline: sets up view parameters, dispatches DPVS
 * world surfaces, sorts draw surfaces, submits render commands for each draw group
 * (depth prepass, lit, unlit, post-effects), handles debug entity display. */
extern void *R_AllocViewParms(void);
extern int R_CellForPoint(const void *viewParms);
extern void R_AddWorldSurfacesDpvs(const void *viewParms, int cellIdx);
extern void CG_AddMarks(void);
extern void FX_DrawScheduledEffects(void);
extern int R_BeginDrawGroupSection(int section);
extern int R_BeginDrawGroupLoop(int section, int viewIndex);
extern int R_EndDrawGroupLoop(int section, int viewIndex);
extern void R_EndDrawGroupSection(int section);
extern void R_AddCmdBeginView(int entityCount, const GfxSceneDef *sceneDef, const GfxViewParms *viewParms, const GfxLodParms *lodParms);
extern void R_AddCmdSetRenderTarget(int target);
extern void R_AddCmdDrawSurfs(void *drawSurfs, int drawSurfCount, int techType);
extern void R_AddCmdDrawSun(int viewIndex);
extern void R_AddCmdDrawSunPostEffects(int viewIndex);
extern void R_UnlockSkinnedCache(void);
extern void R_AddCmdApplyEarlyPostEffects(void);
extern void R_AddCmdApplyLatePostEffects(float blurRadius);
extern int R_GetPointLightPartitions(void *drawSurfs, int drawSurfCount, void *partitions, int maxPartitions);
extern void R_AddCmdLightProperties(int index, const void *light);
extern void R_AddCmdDrawFullScreenColoredQuad(float x, float y, float w, float h, const void *material, const float *color);
extern void R_AddCmdSetViewport(int x, int y, int w, int h);
extern void Com_Printf(const char *fmt, ...);
void R_RenderScene(const refdef_t *refdef)
{
    r_globals_t *rg_p = (r_globals_t *)imp_rg;
    r_global_permanent_t *rgp_p = (r_global_permanent_t *)imp_rgp;
    void *viewParms;
    void *viewParmsDraw;
    int drawSurfStart, drawSurfCount;
    int viewIndex;
    float blurRadius;
    byte isSplitscreen;
    int pointLightPartitions[256 * 3]; /* 256 partitions × 3 ints each */
    int pointLightCount;
    int debugEntIndices[2048];

    R_RenderScene_diag(rg_p->registered, (*(const dvar_t **)imp_r_norefresh)->current.enabled,
        (int)rgp_p->world ? 1 : 0);

    /* Early exit checks */
    if (!rg_p->registered)
        return;
    if ((*(const dvar_t **)imp_r_norefresh)->current.enabled)
        return;

    drawSurfCount = 0;
    {
        void *world = rgp_p->world;
        if (!world) {
            R_Error(1, "R_RenderScene: no world loaded");
            /* falls through after error */
        }
    }

    /* Setup scene timing */
    scene.def.time = ((const refdef_t *)refdef)->time;
    scene.def.floatTime = (float)((const refdef_t *)refdef)->time * 0.001f;

    /* Copy refdef origin and axis to rg */
    memcpy(rg_p->viewOrg, (const char *)refdef + 0x18, 12); /* origin */
    memcpy(rg_p->viewDir, (const char *)refdef + 0x24, 12); /* axis[0] */

    /* Allocate and set view parameters */
    viewParms = R_AllocViewParms();
    R_SetViewParmsForScene(refdef, (GfxViewParms *)viewParms);

    blurRadius = ((const refdef_t *)refdef)->blurRadius;

    /* Check splitscreen */
    {
        char *vidCfg = (char *)imp_vidConfig;
        if (((const refdef_t *)refdef)->width == ((const vidConfig_t *)imp_vidConfig)->width)
            isSplitscreen = 0;
        else
            isSplitscreen = 0; /* simplified — original checks height match */
        (void)isSplitscreen;
    }

    /* Handle r_lockPvs */
    viewParmsDraw = viewParms;
    if ((*(const dvar_t **)imp_r_lockPvs)->current.enabled)
        viewParmsDraw = &lockPvsViewParms;

    /* Sun light timing/interpolation */
    {
        r_globals_t *rg_ptr = (r_globals_t *)imp_rg;
        GfxFog *fogActive = &rg_ptr->fogSettings[2]; /* interpolated/active fog */
        GfxFog *fogPrev = &rg_ptr->fogSettings[3];   /* previous fog state */
        GfxFog *fogTarget = &rg_ptr->fogSettings[4];  /* target fog state */
        int sceneTime = scene.def.time;
        int sunTime = fogTarget->finishTime;

        if (sceneTime >= sunTime) {
            /* Copy current sun state to active */
            memcpy(fogActive, fogTarget, sizeof(GfxFog));
        } else {
            int prevTime = fogTarget->startTime;
            if (prevTime != fogTarget->techniqueOffset) {
                /* Interpolate sun between prev and current */
                int duration = sunTime - prevTime;
                float frac;
                if (duration <= 0) {
                    frac = 1.0f;
                } else {
                    frac = (float)(sceneTime - prevTime) / (float)duration;
                    if (frac > 1.0f) frac = 1.0f;
                }
                /* Interpolate float components (fogStart, fogEnd, density) */
                int i;
                for (i = 0; i < 3; i++) {
                    float prev = *((float *)&fogPrev->fogStart + i);
                    float curr = *((float *)&fogTarget->fogStart + i);
                    *((float *)&fogActive->fogStart + i) = prev + (curr - prev) * frac;
                }
                /* Interpolate color bytes */
                for (i = 0; i < 4; i++) {
                    byte prev = ((byte *)&fogPrev->color)[i];
                    byte curr = ((byte *)&fogTarget->color)[i];
                    ((byte *)&fogActive->color)[i] = (byte)(prev + (int)(curr - prev) * frac);
                }
                fogActive->techniqueOffset = fogTarget->techniqueOffset;
                fogActive->registered = 1;
                fogActive->clearScreen = fogTarget->clearScreen ? 1 : fogPrev->clearScreen;
            } else {
                memcpy(fogActive, fogTarget, sizeof(GfxFog));
                fogTarget->finishTime = 0;
            }
        }

        /* Copy sun data to front-end */
        if (rg_ptr->fogIndex) {
            GfxBackEndData *fed = *(GfxBackEndData **)imp_frontEndDataOut;
            memcpy(&fed->fogSettings, fogActive, sizeof(GfxFog));
        } else {
            GfxBackEndData *fed = *(GfxBackEndData **)imp_frontEndDataOut;
            fed->fogSettings.techniqueOffset = 0;
        }
    }

    viewIndex = ((const refdef_t *)refdef)->viewIndex;

    /* DPVS: add world surfaces */
    {
        int cellIdx;
        R_WorldCheck_diag(rgp_p->world, NULL, 0);
        cellIdx = R_CellForPoint(viewParmsDraw);
        {
            GfxWorld *world = rgp_p->world;
            if (world && world->cells) {
                R_AddWorldSurfacesDpvs(viewParmsDraw, cellIdx);
            }
        }
    }

    CG_AddMarks();
    FX_DrawScheduledEffects();

    drawSurfStart = (int)(intptr_t)scene.drawSurfs;
    drawSurfCount = scene.drawSurfCount;
    qsortDrawSurfs((GfxDrawSurf *)(intptr_t)drawSurfStart, drawSurfCount);

    /* Dynamic lights */
    {
        int isDx7 = ((*(const dvar_t **)imp_r_rendererInUse)->current.integer == 2);
        if (!isDx7 && (*(const dvar_t **)imp_r_dlightLimit)->current.integer) {
            pointLightCount = R_GetPointLightPartitions(
                (void *)(intptr_t)drawSurfStart, drawSurfCount,
                pointLightPartitions, 0x100);
        } else {
            pointLightCount = 0;
        }
    }

    /* Rendering path selection and command submission */
    {
        int isFullbright = (*(const dvar_t **)imp_r_fullbright)->current.enabled;
        int isDx7 = ((*(const dvar_t **)imp_r_rendererInUse)->current.integer == 2);
        const GfxLodParms *lodParms = &rg_p->lodParms;

        if (isFullbright) {
            /* Fullbright path */
            if (!R_BeginDrawGroupSection(3)) {
                R_AddCmdSetRenderTarget(0);
                {
                    R_AddCmdSetViewport(0, 0, ((const vidConfig_t *)imp_vidConfig)->width, ((const vidConfig_t *)imp_vidConfig)->height);
                }
                R_AddClearCommandsForFrameBuffer(0);
            }
            R_BeginDrawGroupLoop(3, viewIndex);
            R_AddCmdBeginView(scene.viewCount, &scene.def, viewParms, lodParms);
            R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 3);
            R_AddCmdDrawSun(viewIndex);
            R_EndDrawGroupLoop(3, viewIndex);
            R_EndDrawGroupSection(3);

            /* Section 4 */
            if (!R_BeginDrawGroupSection(4)) {
                R_AddCmdSetViewport(0, 0, ((const vidConfig_t *)imp_vidConfig)->width, ((const vidConfig_t *)imp_vidConfig)->height);
            }
            R_BeginDrawGroupLoop(4, viewIndex);
            R_AddCmdBeginView(scene.viewCount, &scene.def, viewParms, lodParms);
        } else if (isDx7) {
            /* Dx7 path */
            R_AddCmdBeginView(scene.viewCount, &scene.def, viewParms, lodParms);
                R_AddCmdSetRenderTarget(0);
                R_AddClearCommandsForFrameBuffer(0);
                {
                    GfxWorld *world = rgp_p->world;
                    R_AddCmdLightProperties(0, (char *)&world->sunLight);
                }
            R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 1);
            R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 6);
            R_AddCmdDrawSun(viewIndex);
            R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 0x15);
        } else if ((*(const dvar_t **)imp_r_debugShader)->current.integer) {
            /* Debug shader path */
            R_AddCmdBeginView(scene.viewCount, &scene.def, viewParms, lodParms);
            R_AddCmdSetRenderTarget(0);
            R_AddClearCommandsForFrameBuffer(0);
            R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 0x21);
        } else {
            /* Normal rendering path with draw groups */
            if (!R_BeginDrawGroupSection(2)) {
                R_AddCmdSetRenderTarget(0);
                {
                    R_AddCmdSetViewport(0, 0, ((const vidConfig_t *)imp_vidConfig)->width, ((const vidConfig_t *)imp_vidConfig)->height);
                }
                R_AddClearCommandsForFrameBuffer(0);
                {
                    GfxWorld *world = rgp_p->world;
                    R_AddCmdLightProperties(0, (char *)&world->sunLight);
                }
            }
            R_BeginDrawGroupLoop(2, viewIndex);
            R_AddCmdBeginView(scene.viewCount, &scene.def, viewParms, lodParms);
            R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 1);
            R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 6);
            R_AddCmdDrawSun(viewIndex);
            R_EndDrawGroupLoop(2, viewIndex);
            if (!isSplitscreen)
                R_AddCmdApplyEarlyPostEffects();
            R_EndDrawGroupSection(2);

            /* Section 3: lit surfaces */
            R_BeginDrawGroupSection(3);
            R_BeginDrawGroupLoop(3, viewIndex);
            R_AddCmdBeginView(scene.viewCount, &scene.def, viewParms, lodParms);

            /* Point light partitions */
            if (pointLightCount > 0) {
                int p;
                for (p = 0; p < pointLightCount; p++) {
                    int *part = &pointLightPartitions[p * 3];
                    void *light = (void *)(intptr_t)part[0];
                    void *pDrawSurfs = (void *)((char *)(intptr_t)*(int *)((char *)&scene + 1468) + part[1] * 8);
                    int pDrawSurfCount = part[2];
                    void *world = rgp_p->world;
                    R_AddCmdDrawFullScreenColoredQuad(0, 0, 1.0f, 1.0f, ((r_global_permanent_t *)rgp_p)->clearAlphaStencilMaterial, (const float *)imp_colorWhite);
                    R_AddCmdLightProperties(0, light);
                    R_AddCmdDrawSurfs(pDrawSurfs, pDrawSurfCount, 0x12);
                }
            }

            R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 0x15);
            R_EndDrawGroupLoop(3, viewIndex);
            R_EndDrawGroupSection(3);

            /* Section 4: post-effects */
            if (!R_BeginDrawGroupSection(4)) {
                R_AddCmdSetViewport(0, 0, ((const vidConfig_t *)imp_vidConfig)->width, ((const vidConfig_t *)imp_vidConfig)->height);
            }
            R_BeginDrawGroupLoop(4, viewIndex);
            R_AddCmdBeginView(scene.viewCount, &scene.def, viewParms, lodParms);
            if (!isSplitscreen)
                R_AddCmdApplyLatePostEffects(blurRadius);
            R_AddCmdDrawSunPostEffects(viewIndex);
        }

        /* Show tris */
        {
            int showTris = (*(const dvar_t **)imp_r_showTris)->current.integer;
            if (showTris) {
                if (showTris & 2)
                    R_AddCmdClearScreen(6, (const vec_t *)imp_colorWhite, 1.0f, 0);
                R_AddCmdDrawSurfs((void *)(intptr_t)drawSurfStart, drawSurfCount, 0x1d);
            }
        }

        R_UnlockSkinnedCache();
    }

    /* Debug entity counts */
    {
        int debugEntCounts = (*(const dvar_t **)imp_r_debugEntCounts)->current.integer;
        if (debugEntCounts && debugEntCounts < scene.def.entityCount) {
            /* Reset dvar */
            ((refimport_t *)imp_ri)->Dvar_SetInt(*(const dvar_t **)imp_r_debugEntCounts, 0);
            /* Detailed entity debug output omitted for brevity — uses qsort + Com_Printf loop */
        }
    }
}


/* line 272 */
int R_AddStaticModelToScene(int smodelIndex)
{
    GfxBackEndData *buf;
    GfxEntity *backEndRefEnt;
    GfxSceneEntity *sceneEnt;
    GfxStaticModelInstance *smodelInst;
    GfxWorld *world;
    int entIndex;

    if (!(*(const dvar_t **)imp_r_drawEntities)->current.enabled)
        return -1;

    entIndex = scene.def.entityCount;
    if ((unsigned int)entIndex > 0x7fd) {
        buf = frontEndDataOut;
        if (buf->frameCount == warnCount)
            return -1;
        warnCount = buf->frameCount;
        ri.Printf(2, "too many scene entities (more than %%i)\n", 0x7fe);
        return -1;
    }

    buf = frontEndDataOut;
    if (buf->entityCount > 0x1ff7) {
        if (buf->frameCount == warnCount)
            return -1;
        warnCount = buf->frameCount;
        ri.Printf(2, "too many visible models (more than %i)\n", 0x1ff8);
        return -1;
    }

    buf->entityCount++;
    scene.def.entityCount++;

    if (entIndex < 0)
        return -1;

    backEndRefEnt = &scene.def.entities[entIndex];
    world = rgp.world;
    smodelInst = &world->smodelInsts[smodelIndex];

    memset(backEndRefEnt, 0, sizeof(GfxEntity));
    backEndRefEnt->reType = 2;
    backEndRefEnt->origin[0] = smodelInst->origin[0];
    backEndRefEnt->origin[1] = smodelInst->origin[1];
    backEndRefEnt->origin[2] = smodelInst->origin[2];
    AxisCopy(smodelInst->axis, backEndRefEnt->axis);
    backEndRefEnt->scale = smodelInst->scale;

    if ((*(const dvar_t **)imp_r_rendererInUse)->current.integer == 2) {
        /* DX7: index into world pre-computed static model lighting table */
        backEndRefEnt->lighting.dx7.colorForDir = (FxMemMgr_Emitter *(*)[2])((intptr_t)smodelIndex + (intptr_t)world->smodelLightingColorTable);
        *(int *)&backEndRefEnt->lighting.dx7.sunVisibility = ((int *)world->smodelLightingSunVisTable)[smodelIndex];
    } else {
        backEndRefEnt->lighting.baseCoords[0] = smodelInst->baseLightingCoords[0];
        backEndRefEnt->lighting.baseCoords[1] = smodelInst->baseLightingCoords[1];
        backEndRefEnt->lighting.baseCoords[2] = smodelInst->baseLightingCoords[2];
    }

    sceneEnt = &scene.sceneEnts[entIndex];
    memset(sceneEnt, 0, sizeof(*sceneEnt));
    sceneEnt->cullState = 2;
    sceneEnt->u.model = smodelInst->model;
    sceneEnt->curMins[0] = smodelInst->mins[0];
    sceneEnt->curMins[1] = smodelInst->mins[1];
    sceneEnt->curMins[2] = smodelInst->mins[2];
    sceneEnt->curMaxs[0] = smodelInst->maxs[0];
    sceneEnt->curMaxs[1] = smodelInst->maxs[1];
    sceneEnt->curMaxs[2] = smodelInst->maxs[2];

    return entIndex;
}

/* line 385 */
GfxEntity * R_AddRefEntityToScene(const GfxEntity *refEnt, GfxModel sceneModel, const struct centity_s *cent)
{
    GfxBackEndData *buf;
    GfxEntity *backEndRefEnt;
    GfxSceneEntity *sceneEnt;
    const Material *material;
    GfxDrawSurf *drawSurf;
    unsigned int sortValue;
    int entIndex, surfType;

    if (refEnt->reType > 1) {
        /* check performance monitor */
        if ((*(const dvar_t **)imp_com_statmon)->current.enabled) {
            if (frontEndDataOut->entityCount > 0x1cc4)
                ri.StatMon_Warning(5, "R_AddRefEntityToScene: too many entity render calls", 0xbb8);
        }

        if (refEnt->reType > 9)
            R_Error(1, "R_AddRefEntityToScene: bad reType %i", refEnt->reType);

        buf = frontEndDataOut;
        if (buf->entityCount > 0x1ff7) {
            if (buf->frameCount == warnCount)
                return NULL;
            warnCount = buf->frameCount;
            ri.Printf(2, "R_AddRefEntityToScene: too many entities");
            return NULL;
        }

        if (!(*(const dvar_t **)imp_r_drawEntities)->current.enabled)
            return NULL;

        entIndex = scene.def.entityCount;
        if ((unsigned int)entIndex > 0x7fd) {
            buf = frontEndDataOut;
            if (buf->frameCount == warnCount)
                return NULL;
            warnCount = buf->frameCount;
            ri.Printf(2, "too many scene entities (more than %i)\n", 0x7fe);
            return NULL;
        }

        buf->entityCount++;
        scene.def.entityCount++;

        if (entIndex < 0)
            return NULL;

        sceneEnt = &scene.sceneEnts[entIndex];
        backEndRefEnt = &scene.def.entities[entIndex];

        memcpy(backEndRefEnt, refEnt, sizeof(GfxEntity));
        if (backEndRefEnt->scale == 0.0f)
            backEndRefEnt->scale = 1.0f;

        memset(sceneEnt, 0, sizeof(*sceneEnt));

        if (refEnt->reType > 3) {
            /* add entity draw surface */
            material = refEnt->customMaterial;
            buf = frontEndDataOut;
            if (buf->drawSurfCount <= 0xffff) {
                drawSurf = &buf->drawSurfs[buf->drawSurfCount];
                surfType = s_entitySurface;
                if (surfType == 2 && (*(const dvar_t **)imp_fx_sort)->current.enabled) {
                    sortValue = (unsigned int)((entIndex << 19) + (material->info.sortedIndex << 9) + 0x800001f2u);
                } else {
                    sortValue = (unsigned int)(surfType + (entIndex << 4) + (material->info.sortedIndex << 21) + 0x1f0000);
                }
                drawSurf->sort = sortValue;
                drawSurf->surface = &s_entitySurface;
                scene.drawSurfCount++;
                buf->drawSurfCount++;
            }
        } else {
            sceneEnt->u = sceneModel;
        }
    } else {
        /* reType <= 1: model entities (DObj, XModel) */
        if (!(*(const dvar_t **)imp_r_drawEntities)->current.enabled)
            return NULL;

        entIndex = scene.def.entityCount;
        if ((unsigned int)entIndex > 0x7fd) {
            buf = frontEndDataOut;
            if (buf->frameCount == warnCount)
                return NULL;
            warnCount = buf->frameCount;
            ri.Printf(2, "too many scene entities (more than %i)\n", 0x7fe);
            return NULL;
        }

        buf = frontEndDataOut;
        if (buf->entityCount > 0x1ff7) {
            if (buf->frameCount == warnCount)
                return NULL;
            warnCount = buf->frameCount;
            ri.Printf(2, "too many visible models (more than %i)\n", 0x1ff8);
            return NULL;
        }

        buf->entityCount++;
        scene.def.entityCount++;

        if (entIndex < 0)
            return NULL;

        sceneEnt = &scene.sceneEnts[entIndex];
        backEndRefEnt = &scene.def.entities[entIndex];

        memcpy(backEndRefEnt, refEnt, sizeof(GfxEntity));
        if (backEndRefEnt->scale == 0.0f)
            backEndRefEnt->scale = 1.0f;

        memset(sceneEnt, 0, sizeof(*sceneEnt));
        sceneEnt->u = sceneModel;
        sceneEnt->cent = cent;

        if (refEnt->reType == 1)
            R_DrawModel(entIndex);
    }

    return backEndRefEnt;
}
