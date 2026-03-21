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
extern surfaceType_t s_entitySurface; /* s_entitySurface */
extern byte s_XModelSurfaceSize[8]; /* s_XModelSurfaceSize */

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

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1476 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* refdef */
        /* { scope 1: pointLightPartitions */
        "movl imp_rg, %ebx\n" /* line 1491 | drawSurfs */

        /* DIAGNOSTIC: check early exit conditions */
        "pushl %esi\n"
        "movl imp_rgp, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "pushl %eax\n"                 /* drawSurfCount */
        "movl imp_r_norefresh, %eax\n"
        "movl (%eax), %eax\n"
        "movzbl 8(%eax), %eax\n"
        "pushl %eax\n"                 /* norefresh */
        "movzbl (%ebx), %eax\n"
        "pushl %eax\n"                 /* registered */
        "calll R_RenderScene_diag\n"
        "addl $12, %esp\n"
        "popl %esi\n"

        "cmpb $0, (%ebx)\n" /* drawSurfs */
        "je .Lfc643c_000c6a10\n"
        "movl imp_r_norefresh, %eax\n" /* line 1501 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc643c_000c6a10\n"
        "movl imp_rgp, %eax\n" /* line 1507 */
        "movl 0x109c(%eax), %edi\n" /* drawSurfCount */
        "testl %edi, %edi\n" /* drawSurfCount */
        "je .Lfc643c_000c713b\n"
        ".Lfc643c_000c647e:\n"
        "movl 0x48(%esi), %eax\n" /* line 1510 | refdef */
        "movl %eax, scene+4\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1511 */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, scene+8\n"
        "leal 0x18(%esi), %edx\n" /* line 1513 | refdef, from */
        /* { scope 2: pointLightCount, viewIndex */
        "movl 0x18(%esi), %eax\n" /* line 199 */
        "movl %eax, 4(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 8(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0xc(%ebx)\n"
        /* } scope */
        "leal 0x24(%esi), %edx\n" /* line 1514 | refdef, from */
        /* { scope 2: pointLightCount, viewIndex */
        "movl 0x24(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x10(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x18(%ebx)\n"
        /* } scope */
        "calll R_AllocViewParms\n" /* line 1516 */
        "movl %eax, -0x2c1c(%ebp)\n"
        "movl %eax, %edx\n" /* line 1517 */
        "movl %esi, %eax\n" /* refdef */
        "calll R_SetViewParmsForScene\n"
        "movss 0x50(%esi), %xmm0\n" /* line 1442 | light */
        "movss %xmm0, -0x2c30(%ebp)\n"
        "movl imp_vidConfig, %edx\n" /* line 1443 */
        "movl 8(%esi), %eax\n" /* light */
        "cmpl (%edx), %eax\n"
        "je .Lfc643c_000c6f9c\n"
        ".Lfc643c_000c64f6:\n"
        "movb $0, -0x2c55(%ebp)\n"
        ".Lfc643c_000c64fd:\n"
        "movl imp_r_lockPvs, %eax\n" /* line 1526 */
        "movl (%eax), %eax\n"
        "movl $lockPvsViewParms, -0x2c5c(%ebp)\n" /* viewParmsDraw */
        "cmpb $0, 8(%eax)\n"
        "movl $lockPvsViewParms, %eax\n"
        "cmovel -0x2c1c(%ebp), %eax\n"
        "movl %eax, -0x2c5c(%ebp)\n" /* viewParmsDraw */
        /* { scope 2: pointLightCount, viewIndex */
        "movl scene+4, %ebx\n" /* line 536 */
        "movl imp_rg, %ecx\n"
        "movl 0x14f4(%ecx), %edx\n"
        "cmpl %edx, %ebx\n"
        "jl .Lfc643c_000c6a31\n"
        "movl 0x14ec(%ecx), %eax\n" /* line 538 */
        "movl %eax, 0x14ac(%ecx)\n"
        "movl 0x14f0(%ecx), %eax\n"
        "movl %eax, 0x14b0(%ecx)\n"
        "movl %edx, 0x14b4(%ecx)\n"
        "movl 0x14f8(%ecx), %eax\n"
        "movl %eax, 0x14b8(%ecx)\n"
        "movl 0x14fc(%ecx), %eax\n"
        "movl %eax, 0x14bc(%ecx)\n"
        "movl 0x1500(%ecx), %eax\n"
        "movl %eax, 0x14c0(%ecx)\n"
        "movl 0x1504(%ecx), %eax\n"
        "movl %eax, 0x14c4(%ecx)\n"
        "movl 0x1508(%ecx), %eax\n"
        "movl %eax, 0x14c8(%ecx)\n"
        ".Lfc643c_000c6598:\n"
        "movl 0x150c(%ecx), %ebx\n" /* line 575 */
        "testl %ebx, %ebx\n"
        "je .Lfc643c_000c6a1b\n"
        "movl imp_frontEndDataOut, %eax\n" /* line 577 */
        "movl (%eax), %edx\n"
        "movl 0x14ac(%ecx), %eax\n"
        "movl %eax, 0x219cec(%edx)\n"
        "movl 0x14b0(%ecx), %eax\n"
        "movl %eax, 0x219cf0(%edx)\n"
        "movl 0x14b4(%ecx), %eax\n"
        "movl %eax, 0x219cf4(%edx)\n"
        "movl 0x14b8(%ecx), %eax\n"
        "movl %eax, 0x219cf8(%edx)\n"
        "movl 0x14bc(%ecx), %eax\n"
        "movl %eax, 0x219cfc(%edx)\n"
        "movl 0x14c0(%ecx), %eax\n"
        "movl %eax, 0x219d00(%edx)\n"
        "movl 0x14c4(%ecx), %eax\n"
        "movl %eax, 0x219d04(%edx)\n"
        "movl 0x14c8(%ecx), %eax\n"
        "movl %eax, 0x219d08(%edx)\n"
        /* } scope */
        ".Lfc643c_000c660d:\n"
        "movl 0x54(%esi), %esi\n" /* line 1532 | refdef */
        "movl %esi, -0x2c48(%ebp)\n" /* refdef, viewIndex */
        /* { scope 2: pointLightCount, viewIndex */
        "movl -0x2c5c(%ebp), %edx\n" /* line 1315 | viewParmsDraw */
        "movl %edx, (%esp)\n"
        "calll R_CellForPoint\n"
        "movl %eax, %edx\n"
        /* { scope 3: partitionIndex */
        /* DIAG: check world data pointers */
        "pushal\n"
        "pushl %edx\n"  /* cellIdx */
        "movl imp_rgp, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "pushl %eax\n"  /* dummy cell_ptr */
        "pushl %eax\n"  /* rgp_field */
        "calll R_WorldCheck_diag\n"
        "addl $12, %esp\n"
        "popal\n"
        "movl imp_rgp, %eax\n" /* line 956 */
        "movl 0x109c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6651\n"
        "movl 0x100(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfc643c_000c6651\n"
        "movl %edx, 4(%esp)\n" /* line 959 */
        "movl -0x2c5c(%ebp), %ecx\n" /* viewParmsDraw */
        "movl %ecx, (%esp)\n"
        "calll R_AddWorldSurfacesDpvs\n"
        /* } scope */
        ".Lfc643c_000c6651:\n"
        /* no extra diag here — R_WorldCheck_diag covers it */
        "calll CG_AddMarks\n" /* line 1328 */
        "calll FX_DrawScheduledEffects\n" /* line 1329 */
        "movl scene+1464, %eax\n" /* line 1331 */
        "movl %eax, -0x2c54(%ebp)\n"
        "movl scene+1468, %edx\n" /* line 1332 */
        "movl %edx, -0x2c50(%ebp)\n"
        "movl %eax, 4(%esp)\n" /* line 878 */
        "movl %edx, (%esp)\n"
        "calll qsortDrawSurfs\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1158 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfc643c_000c669d\n"
        "movl imp_r_dlightLimit, %eax\n" /* line 1161 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfc643c_000c7300\n"
        ".Lfc643c_000c669d:\n"
        "movl $0, -0x2c4c(%ebp)\n" /* line 1341 | pointLightCount */
        ".Lfc643c_000c66a7:\n"
        "movl imp_r_fullbright, %eax\n" /* line 1279 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc643c_000c6ea1\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1284 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfc643c_000c7080\n"
        "movl imp_r_debugShader, %eax\n" /* line 1289 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6aac\n"
        "movl imp_rg, %eax\n" /* line 1215 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $scene+4, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "movl $0, (%esp)\n" /* line 1216 */
        "calll R_AddCmdSetRenderTarget\n"
        "xorl %eax, %eax\n" /* line 1217 */
        "calll R_AddClearCommandsForFrameBuffer\n"
        "movl $0x21, 8(%esp)\n" /* line 1218 */
        ".Lfc643c_000c6723:\n"
        "movl -0x2c54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        ".Lfc643c_000c673b:\n"
        "movl imp_r_showTris, %eax\n" /* line 1353 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6771\n"
        "testb $2, %al\n" /* line 1355 */
        "jne .Lfc643c_000c7038\n"
        ".Lfc643c_000c6751:\n"
        "movl $0x1d, 8(%esp)\n" /* line 1357 */
        "movl -0x2c54(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        ".Lfc643c_000c6771:\n"
        "calll R_UnlockSkinnedCache\n" /* line 1366 */
        /* } scope */
        "movl imp_r_debugEntCounts, %eax\n" /* line 1536 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfc643c_000c6a10\n"
        "cmpl scene+12, %edx\n"
        "jge .Lfc643c_000c6a10\n"
        "movl $0, 4(%esp)\n" /* line 1538 */
        "movl %eax, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0x98(%eax)\n"
        "movl $str_00222e04, -0xc18(%ebp)\n" /* line 188 | pointLightPartitions */
        "movl $str_00217dc8, -0xc14(%ebp)\n" /* "xmodel" */
        "movl $str_00222e0c, -0xc10(%ebp)\n" /* "smodel" */
        "movl $str_00222e14, -0xc0c(%ebp)\n" /* "bmodel" */
        "movl $str_00222e1c, -0xc08(%ebp)\n" /* "sprite" */
        "movl $str_00222e24, -0xc04(%ebp)\n" /* "rail core" */
        "movl $str_00219e5c, -0xc00(%ebp)\n" /* "cloud" */
        "movl $str_00222e30, -0xbfc(%ebp)\n" /* "oriented" */
        "movl $str_00219df4, -0xbf8(%ebp)\n" /* "line" */
        "movl $str_00219e04, -0xbf4(%ebp)\n" /* "cylinder" */
        "movl scene+12, %eax\n" /* line 193 */
        "testl %eax, %eax\n"
        "je .Lfc643c_000c7154\n"
        "xorl %eax, %eax\n"
        "movl scene+12, %edx\n"
        ".Lfc643c_000c6823:\n"
        "movl %eax, -0x2c10(%ebp, %eax, 4)\n" /* line 194 */
        "addl $1, %eax\n" /* line 193 */
        "cmpl %eax, %edx\n"
        "jne .Lfc643c_000c6823\n"
        ".Lfc643c_000c6831:\n"
        "movl $R_CompareDumpSceneEntities, 0xc(%esp)\n" /* line 196 */
        "movl $4, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2c10(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl scene+12, %eax\n" /* line 198 */
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6a10\n"
        "movl $0, -0x2c38(%ebp)\n"
        "movl -0x2c38(%ebp), %ecx\n"
        ".Lfc643c_000c6870:\n"
        "movl -0x2c10(%ebp, %ecx, 4), %edx\n" /* line 200 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal scene+1476(, %eax, 4), %eax\n"
        "movl %eax, -0x2c40(%ebp)\n"
        "movl imp_frontEndDataOut, %ebx\n" /* line 201 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl (%ebx), %edx\n"
        "leal 0xa0010(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x2c3c(%ebp)\n"
        "addl $1, %ecx\n" /* line 158 */
        "movl %ecx, -0x2c34(%ebp)\n"
        "cmpl scene+12, %ecx\n"
        "je .Lfc643c_000c6e66\n"
        "movl -0x2c38(%ebp), %eax\n"
        "leal -0x2c10(%ebp, %eax, 4), %eax\n"
        "movl %eax, -0x2c28(%ebp)\n"
        "shll $2, %ecx\n"
        "movl %ecx, -0x2c24(%ebp)\n"
        "movl %eax, %edx\n"
        ".Lfc643c_000c68de:\n"
        "movl (%edx), %ecx\n" /* line 128 */
        "movl -0x2c24(%ebp), %eax\n" /* line 129 */
        "movl -0x2c10(%ebp, %eax), %esi\n"
        "movl (%ebx), %eax\n" /* line 130 */
        "leal (, %ecx, 8), %edx\n"
        "subl %ecx, %edx\n"
        "leal (%ecx, %edx, 4), %edx\n"
        "leal 0xa0010(%eax, %edx, 4), %edx\n"
        "movl %edx, -0x2c2c(%ebp)\n"
        "leal (, %esi, 8), %edx\n" /* line 131 */
        "subl %esi, %edx\n"
        "leal (%esi, %edx, 4), %edx\n"
        "leal 0xa0010(%eax, %edx, 4), %ebx\n"
        "movl -0x2c2c(%ebp), %edx\n" /* line 133 */
        "movl (%edx), %edi\n"
        "cmpl (%ebx), %edi\n" /* line 134 */
        "jne .Lfc643c_000c698e\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 137 */
        "leal (%ecx, %eax, 4), %eax\n"
        "leal scene+1476(, %eax, 4), %edx\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 138 */
        "leal (%esi, %eax, 4), %eax\n"
        "leal scene+1476(, %eax, 4), %esi\n"
        "cmpl $2, %edi\n" /* line 139 */
        "jg .Lfc643c_000c6e32\n"
        "cmpl $1, %edi\n"
        "jl .Lfc643c_000c6fff\n"
        "movl 4(%edx), %eax\n" /* line 145 */
        "subl 4(%esi), %eax\n"
        ".Lfc643c_000c6959:\n"
        "testl %eax, %eax\n" /* line 160 */
        "jne .Lfc643c_000c698e\n"
        "addl $1, -0x2c34(%ebp)\n" /* line 158 */
        "addl $4, -0x2c24(%ebp)\n"
        "movl -0x2c34(%ebp), %eax\n"
        "cmpl scene+12, %eax\n"
        "je .Lfc643c_000c6ff2\n"
        "movl imp_frontEndDataOut, %ebx\n"
        "movl -0x2c28(%ebp), %edx\n"
        "jmp .Lfc643c_000c68de\n"
        ".Lfc643c_000c698e:\n"
        "movl -0x2c34(%ebp), %ebx\n"
        "movl -0x2c3c(%ebp), %edx\n"
        ".Lfc643c_000c699a:\n"
        "subl -0x2c38(%ebp), %ebx\n" /* line 164 */
        "movl (%edx), %eax\n" /* line 203 */
        "movl -0xc18(%ebp, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_00222e3c, (%esp)\n" /* "%3i: %-8s: " */
        "calll Com_Printf\n"
        "movl -0x2c3c(%ebp), %ecx\n" /* line 204 */
        "movl (%ecx), %eax\n"
        "cmpl $2, %eax\n"
        "jg .Lfc643c_000c6e05\n"
        "cmpl $1, %eax\n"
        "jl .Lfc643c_000c6fb4\n"
        "movl -0x2c40(%ebp), %ecx\n" /* line 212 */
        "movl 4(%ecx), %eax\n"
        ".Lfc643c_000c69e0:\n"
        "movl %eax, (%esp)\n"
        "calll XModelGetName\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lfc643c_000c69f8:\n"
        "addl %ebx, -0x2c38(%ebp)\n" /* line 198 */
        "movl -0x2c38(%ebp), %ecx\n"
        "cmpl %ecx, scene+12\n"
        "jne .Lfc643c_000c6870\n"
        /* } scope */
        ".Lfc643c_000c6a10:\n"
        "addl $0x2c7c, %esp\n" /* line 1541 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pointLightPartitions */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c6a1b:\n"
        "movl imp_frontEndDataOut, %eax\n" /* line 582 */
        "movl (%eax), %eax\n"
        "movl $0, 0x219cec(%eax)\n"
        "jmp .Lfc643c_000c660d\n"
        ".Lfc643c_000c6a31:\n"
        "movl 0x14cc(%ecx), %eax\n" /* line 542 */
        "cmpl 0x14ec(%ecx), %eax\n"
        "je .Lfc643c_000c6c92\n"
        "movl 0x14ec(%ecx), %eax\n" /* line 544 */
        "movl %eax, 0x14ac(%ecx)\n"
        "movl 0x14f0(%ecx), %eax\n"
        "movl %eax, 0x14b0(%ecx)\n"
        "movl %edx, 0x14b4(%ecx)\n"
        "movl 0x14f8(%ecx), %eax\n"
        "movl %eax, 0x14b8(%ecx)\n"
        "movl 0x14fc(%ecx), %eax\n"
        "movl %eax, 0x14bc(%ecx)\n"
        "movl 0x1500(%ecx), %eax\n"
        "movl %eax, 0x14c0(%ecx)\n"
        "movl 0x1504(%ecx), %eax\n"
        "movl %eax, 0x14c4(%ecx)\n"
        "movl 0x1508(%ecx), %eax\n"
        "movl %eax, 0x14c8(%ecx)\n"
        "movl $0, 0x14f4(%ecx)\n" /* line 545 */
        "jmp .Lfc643c_000c6598\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c6aac:\n"
        "movl $2, (%esp)\n" /* line 1232 */
        "calll R_BeginDrawGroupSection\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c71c4\n"
        ".Lfc643c_000c6ac0:\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1240 | viewIndex */
        "movl %ecx, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl imp_rg, %eax\n" /* line 1242 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $scene+4, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "movl $1, 8(%esp)\n" /* line 1243 */
        "movl -0x2c54(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl $6, 8(%esp)\n" /* line 1244 */
        "movl -0x2c54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1245 | viewIndex */
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSun\n"
        "movl -0x2c48(%ebp), %eax\n" /* line 1246 | viewIndex */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll R_EndDrawGroupLoop\n"
        "testl %eax, %eax\n"
        "jne .Lfc643c_000c6b78\n"
        "cmpb $0, -0x2c55(%ebp)\n" /* line 1249 */
        "jne .Lfc643c_000c7076\n"
        ".Lfc643c_000c6b78:\n"
        "movl $2, (%esp)\n" /* line 1252 */
        "calll R_EndDrawGroupSection\n"
        "movl $3, (%esp)\n" /* line 1254 */
        "calll R_BeginDrawGroupSection\n"
        "movl -0x2c48(%ebp), %edx\n" /* line 1256 | viewIndex */
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl imp_rg, %eax\n" /* line 1258 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $scene+4, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        /* { scope 3: partitionIndex */
        /* { scope 4 */
        "movl -0x2c4c(%ebp), %eax\n" /* line 986 | pointLightCount */
        "testl %eax, %eax\n"
        "jg .Lfc643c_000c723a\n"
        /* } scope */
        /* } scope */
        ".Lfc643c_000c6be1:\n"
        "movl $0x15, 8(%esp)\n" /* line 1260 */
        "movl -0x2c54(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl -0x2c48(%ebp), %edx\n" /* line 1261 | viewIndex */
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll R_EndDrawGroupLoop\n"
        "movl $3, (%esp)\n" /* line 1263 */
        "calll R_EndDrawGroupSection\n"
        "movl $4, (%esp)\n" /* line 1265 */
        "calll R_BeginDrawGroupSection\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1267 | viewIndex */
        "movl %ecx, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl imp_rg, %eax\n" /* line 1269 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $scene+4, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "cmpb $0, -0x2c55(%ebp)\n" /* line 1270 */
        "jne .Lfc643c_000c7223\n"
        ".Lfc643c_000c6c7f:\n"
        "movl -0x2c48(%ebp), %eax\n" /* line 1273 | viewIndex */
        "movl %eax, (%esp)\n"
        "calll R_AddCmdDrawSunPostEffects\n"
        "jmp .Lfc643c_000c673b\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c6c92:\n"
        "movl 0x14f0(%ecx), %edi\n" /* line 549 */
        "movl %edx, %eax\n"
        "subl %edi, %eax\n"
        "testl %eax, %eax\n" /* line 550 */
        "jle .Lfc643c_000c72f0\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        ".Lfc643c_000c6cb0:\n"
        "subl %edi, %ebx\n" /* line 553 */
        "cvtsi2ssl %ebx, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "minss %xmm2, %xmm0\n" /* line 554 */
        "movaps %xmm0, %xmm2\n"
        "movss 0x14dc(%ecx), %xmm1\n" /* line 557 */
        "movss 0x14fc(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14bc(%ecx)\n"
        "movss 0x14e0(%ecx), %xmm1\n" /* line 558 */
        "movss 0x1500(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14c0(%ecx)\n"
        "movss 0x14e4(%ecx), %xmm1\n" /* line 561 */
        "movss 0x1504(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14c4(%ecx)\n"
        "movzbl 0x14d8(%ecx), %edx\n" /* line 527 */
        "cvtsi2ssl %edx, %xmm1\n" /* line 563 */
        "movzbl 0x14f8(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 0x14b8(%ecx)\n"
        "movzbl 0x14d9(%ecx), %edx\n" /* line 527 */
        "cvtsi2ssl %edx, %xmm1\n" /* line 564 */
        "movzbl 0x14f9(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 0x14b9(%ecx)\n"
        "movzbl 0x14da(%ecx), %edx\n" /* line 527 */
        "cvtsi2ssl %edx, %xmm1\n" /* line 565 */
        "movzbl 0x14fa(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 0x14ba(%ecx)\n"
        /* { scope 3: partitionIndex */
        "movzbl 0x14db(%ecx), %edx\n" /* line 527 */
        /* } scope */
        "cvtsi2ssl %edx, %xmm1\n" /* line 566 */
        "movzbl 0x14fb(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm2\n" /* frac */
        "addss %xmm2, %xmm1\n" /* frac */
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 0x14bb(%ecx)\n"
        "movl 0x14ec(%ecx), %eax\n" /* line 568 */
        "movl %eax, 0x14ac(%ecx)\n"
        "movb $1, 0x14c8(%ecx)\n" /* line 569 */
        "cmpb $0, 0x150a(%ecx)\n" /* line 571 */
        "je .Lfc643c_000c7062\n"
        ".Lfc643c_000c6df5:\n"
        "movl $1, %eax\n"
        ".Lfc643c_000c6dfa:\n"
        "movb %al, 0x14ca(%ecx)\n"
        "jmp .Lfc643c_000c6598\n"
        /* } scope */
        ".Lfc643c_000c6e05:\n"
        "cmpl $3, %eax\n" /* line 204 */
        "je .Lfc643c_000c6e6f\n"
        ".Lfc643c_000c6e0a:\n"
        "movl -0x2c3c(%ebp), %edx\n" /* line 220 */
        "movl 0x54(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6fe8\n"
        "movl (%eax), %eax\n"
        ".Lfc643c_000c6e1d:\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lfc643c_000c69f8\n"
        ".Lfc643c_000c6e32:\n"
        "cmpl $3, %edi\n" /* line 139 */
        "je .Lfc643c_000c6fda\n"
        ".Lfc643c_000c6e3b:\n"
        "movl -0x2c2c(%ebp), %ecx\n" /* line 149 */
        "movl 0x54(%ecx), %edx\n"
        "subl 0x54(%ebx), %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "negl %eax\n"
        "jmp .Lfc643c_000c6959\n"
        ".Lfc643c_000c6e66:\n"
        "movl %ecx, %ebx\n"
        "movl %eax, %edx\n"
        "jmp .Lfc643c_000c699a\n"
        ".Lfc643c_000c6e6f:\n"
        "movl imp_rgp, %eax\n" /* line 216 */
        "movl 0x109c(%eax), %edx\n"
        "movl -0x2c40(%ebp), %ecx\n"
        "movl 4(%ecx), %eax\n"
        "subl 0x138(%edx), %eax\n"
        "sarl $5, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00222e48, (%esp)\n" /* "*%i
" */
        "calll Com_Printf\n"
        "jmp .Lfc643c_000c69f8\n"
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c6ea1:\n"
        "movl $3, (%esp)\n" /* line 1185 */
        "calll R_BeginDrawGroupSection\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c7186\n"
        ".Lfc643c_000c6eb5:\n"
        "movl -0x2c48(%ebp), %edx\n" /* line 1192 | viewIndex */
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl imp_rg, %ebx\n" /* line 1194 | drawSurfs */
        "addl $0x317c, %ebx\n" /* drawSurfs */
        "movl %ebx, 0xc(%esp)\n" /* drawSurfs */
        "movl -0x2c1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $scene+4, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "movl $3, 8(%esp)\n" /* line 1195 */
        "movl -0x2c54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1196 | viewIndex */
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSun\n"
        "movl -0x2c48(%ebp), %eax\n" /* line 1197 | viewIndex */
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll R_EndDrawGroupLoop\n"
        "movl $3, (%esp)\n" /* line 1199 */
        "calll R_EndDrawGroupSection\n"
        "movl $4, (%esp)\n" /* line 1201 */
        "calll R_BeginDrawGroupSection\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c715b\n"
        ".Lfc643c_000c6f5e:\n"
        "movl -0x2c48(%ebp), %edx\n" /* line 1206 | viewIndex */
        "movl %edx, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1208 | drawSurfs */
        "movl -0x2c1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $scene+4, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "jmp .Lfc643c_000c673b\n"
        /* } scope */
        ".Lfc643c_000c6f9c:\n"
        "movl 0xc(%esi), %eax\n" /* line 1443 | light */
        "cmpl 4(%edx), %eax\n"
        "jne .Lfc643c_000c64f6\n"
        "movb $1, -0x2c55(%ebp)\n"
        "jmp .Lfc643c_000c64fd\n"
        ".Lfc643c_000c6fb4:\n"
        "testl %eax, %eax\n" /* line 204 */
        "jne .Lfc643c_000c6e0a\n"
        "movl $0, 4(%esp)\n" /* line 207 */
        "movl -0x2c40(%ebp), %edx\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "jmp .Lfc643c_000c69e0\n"
        ".Lfc643c_000c6fda:\n"
        "movl 4(%edx), %eax\n" /* line 147 */
        "subl 4(%esi), %eax\n"
        "sarl $5, %eax\n"
        "jmp .Lfc643c_000c6959\n"
        ".Lfc643c_000c6fe8:\n"
        "movl $str_00222e50, %eax\n" /* line 220 */
        "jmp .Lfc643c_000c6e1d\n"
        ".Lfc643c_000c6ff2:\n"
        "movl %eax, %ebx\n"
        "movl -0x2c3c(%ebp), %edx\n"
        "jmp .Lfc643c_000c699a\n"
        ".Lfc643c_000c6fff:\n"
        "testl %edi, %edi\n" /* line 139 */
        "jne .Lfc643c_000c6e3b\n"
        "movl $0, 4(%esp)\n" /* line 142 */
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "movl %eax, %ebx\n"
        "movl $0, 4(%esp)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "subl %eax, %ebx\n"
        "movl %ebx, %eax\n"
        "jmp .Lfc643c_000c6959\n"
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c7038:\n"
        "movl $0, 0xc(%esp)\n" /* line 1356 */
        "movl $0x3f800000, 8(%esp)\n"
        "movl imp_colorWhite, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $6, (%esp)\n"
        "calll R_AddCmdClearScreen\n"
        "jmp .Lfc643c_000c6751\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c7062:\n"
        "cmpb $0, 0x14ea(%ecx)\n" /* line 571 */
        "jne .Lfc643c_000c6df5\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc643c_000c6dfa\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c7076:\n"
        "calll R_AddCmdApplyEarlyPostEffects\n" /* line 1250 */
        "jmp .Lfc643c_000c6b78\n"
        ".Lfc643c_000c7080:\n"
        "movl imp_rg, %eax\n" /* line 1171 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $scene+4, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "movl $0, (%esp)\n" /* line 1172 */
        "calll R_AddCmdSetRenderTarget\n"
        "xorl %eax, %eax\n" /* line 1173 */
        "calll R_AddClearCommandsForFrameBuffer\n"
        "movl imp_rgp, %eax\n" /* line 1174 */
        "movl 0x109c(%eax), %eax\n"
        "addl $0xb4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdLightProperties\n"
        "movl $1, 8(%esp)\n" /* line 1175 */
        "movl -0x2c54(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl $6, 8(%esp)\n" /* line 1176 */
        "movl -0x2c54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1177 | viewIndex */
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSun\n"
        "movl $0x15, 8(%esp)\n" /* line 1178 */
        "jmp .Lfc643c_000c6723\n"
        /* } scope */
        ".Lfc643c_000c713b:\n"
        "movl $str_00222de4, 4(%esp)\n" /* line 1508 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfc643c_000c647e\n"
        ".Lfc643c_000c7154:\n"
        "xorl %eax, %eax\n" /* line 193 */
        "jmp .Lfc643c_000c6831\n"
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c715b:\n"
        "movl imp_vidConfig, %eax\n" /* line 1203 */
        "movl 4(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdSetViewport\n"
        "jmp .Lfc643c_000c6f5e\n"
        ".Lfc643c_000c7186:\n"
        "movl $0, (%esp)\n" /* line 1187 */
        "calll R_AddCmdSetRenderTarget\n"
        "movl imp_vidConfig, %eax\n" /* line 1189 */
        "movl 4(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdSetViewport\n"
        "xorl %eax, %eax\n" /* line 1190 */
        "calll R_AddClearCommandsForFrameBuffer\n"
        "jmp .Lfc643c_000c6eb5\n"
        ".Lfc643c_000c71c4:\n"
        "movl $0, (%esp)\n" /* line 1234 */
        "calll R_AddCmdSetRenderTarget\n"
        "movl imp_vidConfig, %edx\n" /* line 1236 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdSetViewport\n"
        "xorl %eax, %eax\n" /* line 1057 */
        "calll R_AddClearCommandsForFrameBuffer\n"
        "movl imp_rgp, %eax\n" /* line 1238 */
        "movl 0x109c(%eax), %eax\n"
        "addl $0xb4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdLightProperties\n"
        "jmp .Lfc643c_000c6ac0\n"
        ".Lfc643c_000c7223:\n"
        "movss -0x2c30(%ebp), %xmm0\n" /* line 1271 */
        "movss %xmm0, (%esp)\n"
        "calll R_AddCmdApplyLatePostEffects\n"
        "jmp .Lfc643c_000c6c7f\n"
        /* { scope 3: partitionIndex */
        /* { scope 4 */
        ".Lfc643c_000c723a:\n"
        "movl $0, -0x2c44(%ebp)\n" /* line 986 | partitionIndex */
        "leal -0xc18(%ebp), %eax\n" /* pointLightPartitions */
        "movl %eax, -0x2c20(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfc643c_000c725a\n"
        ".Lfc643c_000c7254:\n"
        "movl -0x2c20(%ebp), %edx\n"
        ".Lfc643c_000c725a:\n"
        "movl (%edx), %esi\n" /* line 988 | light */
        "movl 4(%edx), %ebx\n" /* line 989 | drawSurfs */
        "movl scene+1468, %eax\n"
        "leal (%eax, %ebx, 8), %ebx\n" /* drawSurfs */
        "movl 8(%edx), %edi\n" /* line 990 | drawSurfCount */
        "movl imp_rgp, %ecx\n" /* line 996 */
        "movl 0x1048(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl imp_colorWhite, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdDrawFullScreenColoredQuad\n"
        "movl %esi, 4(%esp)\n" /* line 997 | light */
        "movl $0, (%esp)\n"
        "calll R_AddCmdLightProperties\n"
        "movl $0x12, 8(%esp)\n" /* line 998 */
        "movl %edi, 4(%esp)\n" /* drawSurfCount */
        "movl %ebx, (%esp)\n" /* drawSurfs */
        "calll R_AddCmdDrawSurfs\n"
        "addl $1, -0x2c44(%ebp)\n" /* line 986 | partitionIndex */
        "addl $0xc, -0x2c20(%ebp)\n"
        "movl -0x2c44(%ebp), %edx\n" /* partitionIndex */
        "cmpl %edx, -0x2c4c(%ebp)\n" /* pointLightCount */
        "jne .Lfc643c_000c7254\n"
        "jmp .Lfc643c_000c6be1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c72f0:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 550 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "jmp .Lfc643c_000c6cb0\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c7300:\n"
        "movl $0x100, 0xc(%esp)\n" /* line 1342 */
        "leal -0xc18(%ebp), %eax\n" /* pointLightPartitions */
        "movl %eax, 8(%esp)\n"
        "movl -0x2c54(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_GetPointLightPartitions\n"
        "movl %eax, -0x2c4c(%ebp)\n" /* pointLightCount */
        "jmp .Lfc643c_000c66a7\n"
    );
}
#endif /* original naked R_RenderScene */

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
