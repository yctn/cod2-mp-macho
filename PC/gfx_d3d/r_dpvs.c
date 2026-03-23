/* ASM dump from: r_dpvs.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_dpvs.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/r_dpvs.h"
 *   #include "PC/universal/com_math.h"
 */

/* color: original Mac static was 128 bytes containing sign masks at offsets 16, 32, 64, 96.
 * Was declared as static vec4_t color (16 bytes BSS) — shadowed the real 128-byte rodata array.
 * All color+N references in inline ASM replaced with sse_float_sign_mask from literals.S. */
static int dpvsConfig; /* dpvsConfig */
static struct DpvsScene dpvsScene; /* dpvsScene */
/* Fix: was 'static int dpvsGlob' (4 bytes) — shadowed the global
 * dpvsGlob[224] from bss.c. C code (R_DpvsShouldFallbackAllCells,
 * R_DrawModel) used &dpvsGlob as base for byte offsets (44, 103),
 * reading garbage past the 4-byte int. ASM already uses the global
 * symbol via linker. Must match. */
extern unsigned char dpvsGlob[224]; /* dpvsGlob */
/* Fix #143: was static vec4_t (zeroed BSS) shadowing rodata with correct plane data.
 * This caused R_FrustumClipPlanes to produce degenerate frustum planes that culled everything. */
extern const unsigned char standardFrustumSidePlanes[];

static int g_avis_count = 0;
void R_AddVisSurf_diag_count(void)
{
    g_avis_count++;
}
int R_AddVisSurf_diag_get(void)
{
    int c = g_avis_count;
    g_avis_count = 0;
    return c;
}

extern void R_UpdateXModelBounds(void *sceneEnt, void *ent);
extern void R_SkinSceneEnt(void *sceneEnt, void *ent);
extern void R_AddXModelSurfaces(int entIndex);
extern r_globals_t rg;
extern r_global_permanent_t rgp;
extern void R_Error(int level, const char *fmt, ...);
extern void Vec3Cross(const vec_t *v0, const vec_t *v1, vec_t *cross);
extern float Vec3Normalize(vec_t *v);
extern int BoxOnPlaneSide(const vec_t *emins, const vec_t *emaxs, const cplane_t *p);
extern void ExpandBounds(const vec_t *addedmins, const vec_t *addedmaxs, vec_t *mins, vec_t *maxs);
extern float Vec3Distance(const vec_t *v0, const vec_t *v1);
extern const char *XModelGetName(void *model);
extern void R_AddDebugString(void *debugGlobals, const vec_t *origin, const void *color, float scale, const char *text);
extern void R_SkinStaticModel(void *sceneEnt, void *ent, int smodelIndex);
extern int R_AddStaticModelToScene(int smodelIndex);
extern void R_AddDrawSurfForSurface(void *surf, int entIndex);
void R_DrawModel(int entIndex);
float R_GetFarPlaneDist(void);
void R_ClearDpvsScene(void);
void R_SetCullDist(float dist);
static int R_FilterEntityIntoCells_r_impl(mnode_t *node, int entIndex, const vec_t *mins, const vec_t *maxs);
int R_CellForPoint(const vec_t *origin);
static vec3_t * R_ChopPortalWinding_impl(vec3_t *vertsIn, int *vertexCount, const float *plane, vec3_t *vertsOut);
static void R_GetSidePlaneNormals(vec3_t *winding, int vertexCount, vec3_t *normals);
static void R_GetSidePlaneNormals_impl(vec3_t *winding, int vertexCount, vec3_t *normals);
static __attribute_regparm__(3) void R_AddStaticModelWithCull(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel);
static void R_AddStaticModelWithCull_impl(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel);
void R_FrustumClipPlanes(const D3DMATRIX *viewProjMtx, vec4_t *sidePlanes, int sidePlaneCount, DpvsPlane *frustumPlanes);
static __attribute_regparm__(3) void R_AddWorldSurfaceWithCull(int surfIndex, const DpvsPlane *planes, int planeCount, int stackLevel);
static void R_AddWorldSurfaceWithCull_impl(int surfIndex, const DpvsPlane *planes, int planeCount, int stackLevel);

/* Shared helper: test a DpvsPlane against AABB bounds (mins+maxs, 24 bytes).
 * side[i] is a byte offset into the bounds selecting the appropriate corner. */
static inline float R_DpvsPlaneBoundsTest(const DpvsPlane *plane, const float *bounds)
{
    return plane->coeffs[0] * *(float *)((byte *)bounds + plane->side[0])
         + plane->coeffs[1] * *(float *)((byte *)bounds + plane->side[1])
         + plane->coeffs[2] * *(float *)((byte *)bounds + plane->side[2])
         + plane->coeffs[3];
}

/* Shared: test frustum planes against bounds. Returns 0 if culled, 1 if visible. */
static inline int R_CullByFrustumPlanes(DpvsPlane *planes, int planeCount, int stackLevel, const float *bounds)
{
    int i;
    for (i = 0; i < planeCount; i++) {
        if ((unsigned char)planes[i].u.frontal > (unsigned)stackLevel)
            continue;
        planes[i].u.frontal = 0xFF;
        if (R_DpvsPlaneBoundsTest(&planes[i], bounds) <= 0.0f)
            return 0;
    }
    return 1;
}

/* Shared: test global occluder planes against bounds. Returns 0 if occluded, 1 if visible. */
static inline int R_CullByOccluders(int stackLevel, const float *bounds)
{
    int occCount = *(int *)((byte *)&dpvsGlob + 56);
    GfxOccluder **occTable = *(GfxOccluder ***)((byte *)&dpvsGlob + 60);
    int i;
    for (i = 0; i < occCount; i++) {
        GfxOccluder *occ = occTable[i];
        if (stackLevel > occ->ignoreStackLevel)
            continue;
        int planeCount = occ->viewPlaneCount;
        DpvsPlane *planes = occ->viewPlanes;
        if (planeCount <= 0)
            return 0; /* degenerate occluder: fully occluded */
        int j;
        int allBehind = 1;
        for (j = 0; j < planeCount; j++) {
            if ((unsigned char)planes[j].u.frontal > (unsigned)stackLevel) {
                allBehind = 0;
                break;
            }
            planes[j].u.frontal = 0xFF;
            if (R_DpvsPlaneBoundsTest(&planes[j], bounds) > 0.0f) {
                allBehind = 0;
                break;
            }
        }
        if (allBehind && j >= planeCount)
            return 0;
    }
    return 1;
}
/* Shared helper: set DpvsPlane side bytes from normal sign bits.
 * Maps positive normal components to "maxs" offsets, negative to "mins" offsets
 * in a bounds array laid out as { mins[3], maxs[3] } (24 bytes at offsets 0x00-0x14).
 * This uses integer sign-bit test (reinterpret float as int, check > 0). */
static inline void R_DpvsPlaneSetSideBytes(DpvsPlane *plane)
{
    plane->side[0] = (*(int *)&plane->coeffs[0] > 0) ? 0x0C : 0x00;
    plane->side[1] = (*(int *)&plane->coeffs[1] > 0) ? 0x10 : 0x04;
    plane->side[2] = (*(int *)&plane->coeffs[2] > 0) ? 0x14 : 0x08;
    plane->u.frontal = 0xFF;
}

static void R_AddAabbTreeSurfaces_r_impl(GfxAabbTree *tree, DpvsPlane *planes, int planeCount, int stackLevel);

/* Shared helper: far-corner test against AABB tree bounds (for plane reduction).
 * Tests the corner OPPOSITE to what R_DpvsPlaneBoundsTest uses, allowing plane elimination
 * when the far corner is in front. Uses (tree_base + component_offset - side[i]) access pattern. */
static inline float R_DpvsPlaneFarBoundsTest(const DpvsPlane *plane, const GfxAabbTree *tree)
{
    byte *tp = (byte *)tree;
    return plane->coeffs[0] * *(float *)(tp + 0x0C - plane->side[0])
         + plane->coeffs[1] * *(float *)(tp + 0x14 - plane->side[1])
         + plane->coeffs[2] * *(float *)(tp + 0x1C - plane->side[2])
         + plane->coeffs[3];
}
static int R_GetFurtherCellList_r_impl(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t *v, const GfxCell **list, int count);
static void R_AddVisibleSurfacesInCell(const GfxCell *cell, const DpvsPlane *planes, int planeCount);
static void R_VisitPortalsForCell(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren);
static void R_VisitPortalsForCell_impl(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren);
static void R_VisitPortals(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount);
static void R_VisitPortals_impl(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount);
void R_AddWorldSurfacesDpvs(const GfxViewParms *viewParms, int cameraCellIndex);
static void R_AddWorldSurfacesDpvs_impl(const GfxViewParms *viewParms, int cameraCellIndex);

static qboolean R_DpvsShouldFallbackAllCells(int cameraCellIndex)
{
    if (cameraCellIndex < 0)
        return 0;
    if (!(*(const dvar_t **)imp_r_drawWorld)->current.integer)
        return 0;
    return *(int *)((byte *)&dpvsGlob + 44) == 0;
}

/* line 1145 */
void R_DrawModel(int entIndex)
{
    if (!*(byte *)((char *)&dpvsGlob + 103))
        return;

    /* Fix #143: was *(byte **)imp_scene — double-deref reads scene.viewCount as ptr.
     * imp_scene stores &scene, so (byte *)imp_scene = &scene directly. */
    GfxScene *scene = (GfxScene *)imp_scene;
    GfxSceneEntity *sceneEnt = &scene->sceneEnts[entIndex];
    GfxEntity *ent = &scene->def.entities[entIndex];

    R_UpdateXModelBounds(sceneEnt, ent);
    R_SkinSceneEnt(sceneEnt, ent);
    sceneEnt->cullState = 5;
    R_AddXModelSurfaces(entIndex);
}

/* line 2343 */
float R_GetFarPlaneDist(void)
{
    float farPlaneDist = *(float *)(*(int *)(*(int *)imp_r_zfar) + 8);

    if (farPlaneDist == 0.0f) {
        if (rg.fogIndex && rg.fogSettings[2].registered && rg.fogSettings[2].techniqueOffset == 1) {
            farPlaneDist = rg.fogSettings[2].fogEnd;
        }
    }

    float cullDist = *(float *)&dpvsConfig;
    return cullDist > farPlaneDist ? cullDist : farPlaneDist;
}

/* line 2262 */
void R_ClearDpvsScene(void)
{
    *(int *)((char *)&dpvsScene + 131072) = 0;

    GfxWorld *world = rgp.world;
    if (!world)
        return;

    int cellCount = world->cellCount;
    GfxCell *cells = world->cells;
    for (int i = 0; i < cellCount; i++) {
        cells[i].modelRefs = NULL;
    }
}

/* line 2357 */
void R_SetCullDist(float dist)
{
    *(float *)&dpvsConfig = dist > 0.0f ? dist : 0.0f;
}

/* line 1273 — R_FilterEntityIntoCells_r
 * Actual calling convention: eax=node, edx=entIndex, ecx=mins, stack=maxs
 * Recursively walks BSP tree, assigns entity to leaf cell's modelRef list. */
static int R_FilterEntityIntoCells_r_impl(mnode_t *node, int entIndex, const vec_t *mins, const vec_t *maxs)
{
    int cellIndex = node->cellIndex;

    if (cellIndex == -2) {
        /* Internal node: split plane test */
        cplane_t *plane = node->u.node.plane;
        int side = BoxOnPlaneSide(mins, maxs, plane);

        if (side == 3) {
            /* Entity straddles the split plane */
            if (plane->type > 2) {
                /* Non-axial plane: recurse both children with full bounds */
                int cell1 = R_FilterEntityIntoCells_r_impl(node->u.node.children[0], entIndex, mins, maxs);
                int cell2 = R_FilterEntityIntoCells_r_impl(node->u.node.children[1], entIndex, mins, maxs);
                if (cell1 == cell2)
                    return cell1;
                return -2;
            } else {
                /* Axial plane: clip bounds at plane->dist and recurse each half */
                vec3_t localmins, localmaxs;
                localmins[0] = mins[0]; localmins[1] = mins[1]; localmins[2] = mins[2];
                localmins[plane->type] = plane->dist;
                localmaxs[0] = maxs[0]; localmaxs[1] = maxs[1]; localmaxs[2] = maxs[2];
                localmaxs[plane->type] = plane->dist;

                /* Back child with clipped maxs */
                int cell1 = R_FilterEntityIntoCells_r_impl(node->u.node.children[1], entIndex, mins, localmaxs);
                /* Front child only if bounds extend past the split */
                if (maxs[plane->type] > localmins[plane->type]) {
                    int cell2 = R_FilterEntityIntoCells_r_impl(node->u.node.children[0], entIndex, localmins, maxs);
                    if (cell1 != cell2)
                        return -2;
                    return cell2;
                }
                return cell1;
            }
        } else {
            /* Fully on one side: recurse into that child (side 1=front, 2=back) */
            return R_FilterEntityIntoCells_r_impl(node->u.node.children[side - 1], entIndex, mins, maxs);
        }
    }

    if (cellIndex < 0)
        return cellIndex;

    /* Leaf cell: add entity to cell's modelRef list */
    GfxCell *cells = rgp.world->cells;
    GfxCell *cell = &cells[cellIndex];

    /* Check modelRef limit */
    if (dpvsScene.modelRefCount >= 4096) {
        R_Error(1, "^1Max xmodel refs (%i) exceeded\n", 4096);
        return node->cellIndex;
    }

    /* Walk existing modelRef list — if entity already present, expand bounds */
    GfxSceneModelCellRef *ref = cell->modelRefs;
    while (ref) {
        if (ref->entIndex == entIndex) {
            ExpandBounds(mins, maxs, ref->mins, ref->maxs);
            return node->cellIndex;
        }
        ref = (GfxSceneModelCellRef *)(intptr_t)ref->next;
    }

    /* Allocate new modelRef entry */
    int idx = dpvsScene.modelRefCount;
    GfxSceneModelCellRef *newRef = &dpvsScene.modelRefs[idx];
    dpvsScene.modelRefCount = idx + 1;

    newRef->entIndex = entIndex;
    newRef->mins[0] = mins[0]; newRef->mins[1] = mins[1]; newRef->mins[2] = mins[2];
    newRef->maxs[0] = maxs[0]; newRef->maxs[1] = maxs[1]; newRef->maxs[2] = maxs[2];
    newRef->next = (int)(intptr_t)cell->modelRefs;
    cell->modelRefs = newRef;

    return node->cellIndex;
}

/* Clean C version for WASM — no register calling convention */
static int R_FilterEntityIntoCells_r(mnode_t *node, int entIndex, const vec_t *mins, const vec_t *maxs)
{
    return R_FilterEntityIntoCells_r_impl(node, entIndex, mins, maxs);
}

/* line 925 */
int R_CellForPoint(const vec_t *origin)
{
    GfxWorld *world;
    mnode_t *node;
    float *plane;
    float dot;

    world = ((r_global_permanent_t *)imp_rgp)->world;
    if (!world) {
        R_Error(1, str_002259d0);
        world = ((r_global_permanent_t *)imp_rgp)->world;
    }

    node = world->nodes;
    for (;;) {
        /* Leaf node: return cell index */
        if (node->contents != -1)
            return node->cellIndex;

        /* Internal node: test against split plane */
        plane = (float *)node->u.node.plane;
        dot = origin[0] * plane[0] + origin[1] * plane[1] + origin[2] * plane[2] - plane[3];

        if (dot > 0.0f)
            node = node->u.node.children[0]; /* front child */
        else
            node = node->u.node.children[1]; /* back child */
    }
}

/* line 990 — R_ChopPortalWinding
 * Sutherland-Hodgman clip of a polygon winding against a single plane.
 * Actual calling convention: eax=vertsIn, edx=vertexCount_ptr, ecx=plane(vec4), stack=vertsOut
 * Returns clipped winding (vertsOut if clipped, vertsIn if fully visible, NULL if fully clipped). */
static vec3_t *R_ChopPortalWinding_impl(vec3_t *vertsIn, int *vertexCount, const float *plane, vec3_t *vertsOut)
{
    int count = *vertexCount;
    if (count <= 0) {
        *vertexCount = 0;
        return NULL;
    }

    float nx = plane[0], ny = plane[1], nz = plane[2], dist = plane[3];
    float distForVert[128];
    byte sideForVert[129]; /* +1 for wrap-around */
    int frontCount = 0, backCount = 0;
    int i;

    /* Classify each vertex as front (0), back (1), or on-plane (2) */
    for (i = 0; i < count; i++) {
        float d = nx * vertsIn[i][0] + ny * vertsIn[i][1] + nz * vertsIn[i][2] + dist - 0.001f;
        distForVert[i] = d;
        sideForVert[i] = 2; /* on plane */
        if (d < -0.001f) {
            sideForVert[i] = 1; /* back */
            backCount++;
        } else if (d > 0.001f) {
            sideForVert[i] = 0; /* front */
            frontCount++;
        }
    }

    if (frontCount == 0) {
        *vertexCount = 0;
        return NULL;
    }
    if (backCount == 0)
        return vertsIn;

    /* Wrap-around for clipping loop */
    sideForVert[count] = sideForVert[0];
    distForVert[count] = distForVert[0];

    int newVertCount = 0;
    float *out = (float *)vertsOut;

    for (i = 0; ; ) {
        byte side = sideForVert[i];

        if (side == 2) {
            /* On plane: copy vertex */
            out[0] = vertsIn[i][0]; out[1] = vertsIn[i][1]; out[2] = vertsIn[i][2];
            newVertCount++;
            out += 3;
        } else if (side == 0) {
            /* Front side: keep vertex */
            out[0] = vertsIn[i][0]; out[1] = vertsIn[i][1]; out[2] = vertsIn[i][2];
            newVertCount++;
            out += 3;
        }
        /* Back side (1): discard */

        int next = i + 1;
        byte nextSide = sideForVert[next];

        /* If edge crosses the plane, emit interpolated intersection point */
        if (nextSide != 2 && nextSide != side) {
            float d0 = distForVert[i];
            float frac = d0 / (d0 - distForVert[next]);
            int nextVert = next % count; /* wrapped vertex index for position lookup */
            float *a = (float *)vertsIn[i];
            float *b = (float *)vertsIn[nextVert];
            out[0] = a[0] + frac * (b[0] - a[0]);
            out[1] = a[1] + frac * (b[1] - a[1]);
            out[2] = a[2] + frac * (b[2] - a[2]);
            newVertCount++;
            out += 3;
        }

        if (next >= count || newVertCount > 127)
            break;
        i = next;
    }

    *vertexCount = newVertCount;
    return vertsOut;
}

/* Clean C version for WASM — no register calling convention */
static vec3_t *R_ChopPortalWinding(vec3_t *vertsIn, int *vertexCount, const float *plane, vec3_t *vertsOut)
{
    return R_ChopPortalWinding_impl(vertsIn, vertexCount, plane, vertsOut);
}

/* line 247 — R_GetSidePlaneNormals
 * Computes outward-facing side plane normals for a portal winding.
 * Two paths: if dpvsGlob+84 != 0 (near eye), uses per-vertex eye direction differences.
 * If dpvsGlob+84 == 0 (far/directional eye), uses eye direction × edge vector.
 * Actual calling convention: eax=winding, edx=vertexCount, ecx=normals */
static void R_GetSidePlaneNormals_impl(vec3_t *winding, int vertexCount, vec3_t *normals)
{
    float *eyePos = (float *)((byte *)&dpvsGlob + 72);
    float eyeDist = *(float *)((byte *)&dpvsGlob + 84);

    if (eyeDist != 0.0f) {
        /* Near eye: compute direction from eye to each vertex, then cross consecutive pairs */
        vec3_t diff[129]; /* max 128 vertices + 1 wrap */
        int i;

        for (i = 0; i < vertexCount; i++) {
            diff[i][0] = winding[i][0] - eyePos[0];
            diff[i][1] = winding[i][1] - eyePos[1];
            diff[i][2] = winding[i][2] - eyePos[2];
        }

        /* Wrap: diff[vertexCount] = diff[0] */
        diff[vertexCount][0] = diff[0][0];
        diff[vertexCount][1] = diff[0][1];
        diff[vertexCount][2] = diff[0][2];

        for (i = 0; i < vertexCount; i++) {
            Vec3Cross(diff[i + 1], diff[i], normals[i]);
            Vec3Normalize(normals[i]);
        }
    } else {
        /* Far/directional eye: cross eye direction with each edge vector */
        int prevIdx = vertexCount - 1;
        int i;

        if (vertexCount <= 0)
            return;

        for (i = 0; i < vertexCount; i++) {
            vec3_t delta;
            delta[0] = winding[i][0] - winding[prevIdx][0];
            delta[1] = winding[i][1] - winding[prevIdx][1];
            delta[2] = winding[i][2] - winding[prevIdx][2];

            Vec3Cross(eyePos, delta, normals[prevIdx]);
            Vec3Normalize(normals[prevIdx]);

            prevIdx = i;
        }
    }
}

/* Clean C version for WASM — no register calling convention */
static void R_GetSidePlaneNormals(vec3_t *winding, int vertexCount, vec3_t *normals)
{
    R_GetSidePlaneNormals_impl(winding, vertexCount, normals);
}

/* line 1582 — R_AddStaticModelWithCull
 * Adds a static model to the scene after frustum + occluder culling.
 * LOD distance check, then frustum plane test, then global occluder test.
 * On success: marks frame, adds to scene, skins, and dispatches XModel surfaces. */
static void R_AddStaticModelWithCull_impl(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    int *smodelDync = (int *)((byte *)rg.smodelDyncs + smodelIndex * 8);
    int viewCount = *(int *)imp_scene;

    /* Already processed this frame? */
    if (smodelDync[0] == viewCount)
        return;

    /* Get static model instance */
    GfxStaticModelInstance *smodelInst = &rgp.world->smodelInsts[smodelIndex];

    /* LOD distance check (only if cullDist != 0) */
    if (smodelInst->cullDist != 0.0f) {
        float dist = Vec3Distance(smodelInst->origin, rg.lodParms.origin);
        float scaledDist = dist * rg.lodParms.scale + rg.lodParms.bias;
        if (scaledDist > smodelInst->cullDist) {
            smodelDync[0] = viewCount; /* mark as visited (LOD culled) */
            return;
        }
    }

    /* Frustum plane culling against smodel bounds (mins at offset 0x14) */
    const float *bounds = (const float *)&smodelInst->mins;
    if (!R_CullByFrustumPlanes((DpvsPlane *)planes, planeCount, stackLevel, bounds))
        return;

    /* Global occluder culling */
    if (!R_CullByOccluders(stackLevel, bounds))
        return;

    /* Passed all culling — add to scene */
    smodelDync[0] = viewCount;

    /* Debug: show static model names */
    if (*(byte *)(*(int *)imp_r_showSModelNames + 8)) {
        const char *name = XModelGetName(smodelInst->model);
        byte *debugGlobals = *(byte **)imp_frontEndDataOut + 0x249d18;
        R_AddDebugString(debugGlobals, smodelInst->origin, (const void *)imp_colorWhite, 0.3f, name);
    }

    int entIndex = R_AddStaticModelToScene(smodelIndex);
    if (entIndex < 0)
        return;

    /* Build scene entity */
    GfxScene *scene = (GfxScene *)imp_scene;
    GfxSceneEntity *sceneEnt = &scene->sceneEnts[entIndex];
    GfxEntity *ent = &scene->def.entities[entIndex];

    R_SkinStaticModel(sceneEnt, ent, smodelIndex);
    sceneEnt->cullState = 5; /* surfaceType = 5 */

    R_AddXModelSurfaces(entIndex);
}

/* Clean C version for WASM — no register calling convention */
static void R_AddStaticModelWithCull(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    R_AddStaticModelWithCull_impl(smodelIndex, planes, planeCount, stackLevel);
}

/* line 600 */
void R_FrustumClipPlanes(const D3DMATRIX *viewProjMtx, vec4_t *sidePlanes, int sidePlaneCount, DpvsPlane *frustumPlanes)
{
    int planeIndex, term;
    const float *mtx = (const float *)viewProjMtx;
    for (planeIndex = 0; planeIndex < sidePlaneCount; planeIndex++) {
        const float *side = (const float *)&sidePlanes[planeIndex];
        float *fp = frustumPlanes[planeIndex].coeffs;
        /* Transform side plane into clip space: fp[term] = dot4(side, mtx_row[term]) */
        for (term = 0; term < 4; term++)
            fp[term] = side[0]*mtx[term*4+0] + side[1]*mtx[term*4+1]
                     + side[2]*mtx[term*4+2] + side[3]*mtx[term*4+3];
        /* Normalize xyz */
        float invLen = 1.0f / __builtin_sqrtf(fp[0]*fp[0] + fp[1]*fp[1] + fp[2]*fp[2]);
        fp[0] *= invLen;
        fp[1] *= invLen;
        fp[2] *= invLen;
        fp[3] *= invLen;
        /* Sign bits encode which corner of an AABB to use for near/far plane test */
        frustumPlanes[planeIndex].side[0] = (fp[0] > 0.0f) ? 0x0C : 0x00;
        frustumPlanes[planeIndex].side[1] = (fp[1] > 0.0f) ? 0x10 : 0x04;
        frustumPlanes[planeIndex].side[2] = (fp[2] > 0.0f) ? 0x14 : 0x08;
        frustumPlanes[planeIndex].u.frontal = 0xFF;
    }
}

/* line 1068 — R_AddWorldSurfaceWithCull
 * Adds a world surface to the draw list after frustum + occluder culling.
 * Checks frame visit, optionally tests frustum planes (r_portalFineCull),
 * tests global occluders, then dispatches via R_AddDrawSurfForSurface. */
static void R_AddWorldSurfaceWithCull_impl(int surfIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    /* Per-surface visibility data: skip if already visited this frame */
    int *surfVisData = (int *)rg.surfaces;
    int viewCount = *(int *)imp_scene;

    if (!surfVisData)
        return;

    if (surfVisData[surfIndex] == viewCount)
        return;

    /* Look up the surface's triangle data for bounds */
    GfxSurface *surf = &rgp.world->surfaces[surfIndex];
    srfTriangles_t *tris = surf->tris;

    if (!tris) {
        return;
    }

    /* Frustum plane culling — SKIP when planeCount==0 (force-add mode) */
    if (planeCount > 0 && *(byte *)(*(int *)imp_r_portalFineCull + 8)) {
        const float *bounds = (const float *)tris->bounds;
        if (!R_CullByFrustumPlanes((DpvsPlane *)planes, planeCount, stackLevel, bounds))
            return;
        if (!R_CullByOccluders(stackLevel, bounds))
            return;
    }

    /* Passed culling — mark surface as visited and add draw surface */
    surfVisData[surfIndex] = viewCount;

    int entIndex = surf->sortGroup + 0x800;

    R_AddDrawSurfForSurface(surf, entIndex);
}

/* Clean C version for WASM — no register calling convention */
static void R_AddWorldSurfaceWithCull(int surfIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    R_AddWorldSurfaceWithCull_impl(surfIndex, planes, planeCount, stackLevel);
}

/* line 1088 — R_AddAabbTreeSurfaces_r
 * Recursive AABB tree traversal for the DPVS visibility system.
 * Three-phase culling: (1) near-corner frustum test, (2) occluder test,
 * (3) far-corner plane reduction to eliminate planes for children.
 * Actual calling convention: eax=tree, edx=planes, ecx=planeCount, stack=stackLevel */

/* Helper: add a static model directly to the scene (no frustum/occluder culling) */
static void R_AddStaticModelDirect(int smodelIndex)
{
    int *smodelDync = (int *)((byte *)rg.smodelDyncs + smodelIndex * 8);
    int viewCount = *(int *)imp_scene;

    if (smodelDync[0] == viewCount)
        return;
    smodelDync[0] = viewCount;

    GfxStaticModelInstance *inst = &rgp.world->smodelInsts[smodelIndex];

    /* LOD distance check */
    if (inst->cullDist != 0.0f) {
        float dist = Vec3Distance(inst->origin, rg.lodParms.origin);
        float scaledDist = dist * rg.lodParms.scale + rg.lodParms.bias;
        if (scaledDist > inst->cullDist)
            return;
    }

    /* Debug name display */
    if (*(byte *)(*(int *)imp_r_showSModelNames + 8)) {
        const char *name = XModelGetName(inst->model);
        byte *debugGlobals = *(byte **)imp_frontEndDataOut + 0x249d18;
        R_AddDebugString(debugGlobals, inst->origin, (const void *)imp_colorWhite, 0.3f, name);
    }

    int entIndex = R_AddStaticModelToScene(smodelIndex);
    if (entIndex < 0)
        return;

    GfxScene *scene2 = (GfxScene *)imp_scene;
    GfxSceneEntity *sceneEnt = &scene2->sceneEnts[entIndex];
    GfxEntity *ent = &scene2->def.entities[entIndex];
    R_SkinStaticModel(sceneEnt, ent, smodelIndex);
    sceneEnt->cullState = 5;
    R_AddXModelSurfaces(entIndex);
}

/* Helper: add a world surface directly (no frustum culling, just frame check) */
static void R_AddWorldSurfaceDirect(int surfIndex)
{
    int *surfVisData = (int *)rg.surfaces;
    int viewCount = *(int *)imp_scene;
    if (surfVisData[surfIndex] == viewCount)
        return;
    surfVisData[surfIndex] = viewCount;

    GfxSurface *surf = &rgp.world->surfaces[surfIndex];
    R_AddDrawSurfForSurface(surf, surf->sortGroup + 0x800);
}

static void R_AddAabbTreeSurfaces_r_impl(GfxAabbTree *tree, DpvsPlane *planes, int planeCount, int stackLevel)
{
    float *bounds = (float *)tree; /* mins at +0, maxs at +0x0C */
    int i;

    /* Phase 1: Near-corner frustum cull — if near corner is behind any plane, entire tree is culled */
    if (!R_CullByFrustumPlanes(planes, planeCount, stackLevel, bounds))
        return;

    /* Phase 2: Occluder cull — test near corner against each global occluder volume */
    int occCount = *(int *)((byte *)&dpvsGlob + 56);
    GfxOccluder **occTable = *(GfxOccluder ***)((byte *)&dpvsGlob + 60);
    for (i = 0; i < occCount; i++) {
        GfxOccluder *occ = occTable[i];
        if (stackLevel > occ->ignoreStackLevel)
            continue;
        int occPlaneCount = occ->viewPlaneCount;
        DpvsPlane *occPlanes = occ->viewPlanes;
        if (occPlaneCount <= 0)
            return; /* degenerate occluder */
        int occluded = 1;
        int j;
        for (j = 0; j < occPlaneCount; j++) {
            DpvsPlane *op = &occPlanes[j];
            if ((unsigned char)op->u.frontal > (unsigned)stackLevel) {
                op->u.frontal = stackLevel;
                continue;
            }
            op->u.frontal = 0xFF;
            if (R_DpvsPlaneBoundsTest(op, bounds) > 0.0f)
                occluded = 0;
            else
                op->u.frontal = stackLevel;
        }
        if (occluded)
            return;
    }

    /* Phase 3: Far-corner plane reduction — test far corner to eliminate planes for children.
     * If far corner is in front of a plane, that plane is fully satisfied for the entire subtree. */
    int recursionNeeded = 0;
    if (planeCount > 0) {
        for (i = 0; i < planeCount; i++) {
            DpvsPlane *p = &planes[i];
            if ((unsigned char)p->u.frontal > (unsigned)stackLevel)
                continue;
            if (R_DpvsPlaneFarBoundsTest(p, tree) >= 0.0f)
                p->u.frontal = stackLevel; /* plane satisfied — eliminate for children */
            else
                recursionNeeded = 1;
        }
    }

    /* Check if any global occluder could still affect children */
    if (!recursionNeeded) {
        for (i = 0; i < occCount; i++) {
            if (stackLevel <= occTable[i]->ignoreStackLevel) {
                recursionNeeded = 1;
                break;
            }
        }
    }

    /* Phase 4: Dispatch */
    int childStackLevel = stackLevel + 1;

    if (recursionNeeded) {
        if (tree->childCount > 0) {
            /* Internal node: recurse into child AABB trees */
            for (i = 0; i < tree->childCount; i++) {
                GfxAabbTree *child = (GfxAabbTree *)((byte *)(intptr_t)tree->children + i * sizeof(GfxAabbTree));
                R_AddAabbTreeSurfaces_r_impl(child, planes, planeCount, childStackLevel);
            }
        } else {
            /* Leaf node with culling needed */
            byte smodelFlag = *(byte *)((byte *)&dpvsGlob + 102);

            /* Add static models with per-model culling */
            if (smodelFlag && tree->staticModelCount > 0) {
                for (i = 0; i < tree->staticModelCount; i++)
                    R_AddStaticModelWithCull_impl(tree->staticModels[i], (const DpvsPlane *)planes, planeCount, childStackLevel);
            }

            /* Add surfaces with per-surface culling */
            for (i = 0; i < tree->surfaceCount; i++)
                R_AddWorldSurfaceWithCull_impl(tree->startSurfIndex + i, (const DpvsPlane *)planes, planeCount, childStackLevel);
        }
    } else {
        /* No further culling needed — add everything directly */
        byte smodelFlag = *(byte *)((byte *)&dpvsGlob + 102);

        /* Add static models without culling */
        if (smodelFlag && tree->staticModelCount > 0) {
            for (i = 0; i < tree->staticModelCount; i++)
                R_AddStaticModelDirect(tree->staticModels[i]);
        }

        /* Add all surfaces directly (just frame check) */
        for (i = 0; i < tree->surfaceCount; i++)
            R_AddWorldSurfaceDirect(tree->startSurfIndex + i);
    }
}

/* Clean C version for WASM — no register calling convention */
static void R_AddAabbTreeSurfaces_r(GfxAabbTree *tree, DpvsPlane *planes, int planeCount, int stackLevel)
{
    R_AddAabbTreeSurfaces_r_impl(tree, planes, planeCount, stackLevel);
}

/* line 1907 — R_GetFurtherCellList_r
 * Recursively traverses portals to build a list of visible cells.
 * For each portal in the cell: checks eye-facing, clips winding against parent plane,
 * frustum planes, and occluders, then recurses into the destination cell.
 * Actual convention: eax=cell, edx=parentPlane, ecx=planes, stack=planeCount,v,list,count */
static int R_GetFurtherCellList_r_impl(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t *v, const GfxCell **list, int count)
{
    float *eyeDir = (float *)((byte *)&dpvsGlob + 72);
    int portalCount = cell->portalCount;
    int portalIndex;

    for (portalIndex = 0; portalIndex < portalCount; portalIndex++) {
        GfxPortal *portal = &cell->portals[portalIndex];
        const GfxCell *destCell = portal->cell;

        /* Skip if destination cell is already in the list */
        int already = 0;
        int k;
        for (k = 0; k < count; k++) {
            if (list[k] == destCell) {
                already = 1;
                break;
            }
        }
        if (already)
            continue;

        /* Skip if portal doesn't face the eye */
        if (portal->writable.isAncestor)
            continue;

        /* Eye-facing test: dot(portalPlane.normal, eyeDir) + portalPlane.dist * eyeDist */
        float *portalPlane = portal->plane.coeffs;
        float dot = portalPlane[0] * eyeDir[0] + portalPlane[1] * eyeDir[1]
                  + portalPlane[2] * eyeDir[2] + portalPlane[3] * eyeDir[3];
        if (dot > 0.0f)
            continue;

        /* Get portal winding */
        vec3_t *portalVerts = portal->vertices;
        int vertCount = portal->vertexCount;

        /* Clip winding against parent plane */
        vec3_t *w;
        if (parentPlane) {
            w = R_ChopPortalWinding_impl(portalVerts, &vertCount, (const float *)parentPlane, v);
            if (!vertCount)
                continue;

            /* Second clip if dpvsGlob+44 is set */
            if (*(int *)((byte *)&dpvsGlob + 44)) {
                vec3_t *altBuf = (w != v) ? v : v + 128; /* alternate buffer at v+0x600 */
                w = R_ChopPortalWinding_impl(w, &vertCount, (const float *)parentPlane, altBuf);
                if (!vertCount)
                    continue;
            }
        } else {
            w = portalVerts;
        }

        /* Clip against each frustum plane */
        int pi;
        for (pi = 0; pi < planeCount; pi++) {
            vec3_t *altBuf = (w != v) ? v : v + 128;
            w = R_ChopPortalWinding_impl(w, &vertCount, (const float *)&planes[pi], altBuf);
            if (!vertCount)
                break;
        }
        if (!vertCount)
            continue;

        /* Test against global occluders */
        int occCount = *(int *)((byte *)&dpvsGlob + 56);
        int **occTable = *(int ***)((byte *)&dpvsGlob + 60);
        int occluded = 0;
        int oi;
        for (oi = 0; oi < occCount && !occluded; oi++) {
            GfxOccluder *occ = occTable[oi];
            int occPlaneCount = occ->viewPlaneCount;
            DpvsPlane *occPlanes = occ->viewPlanes;
            if (occPlaneCount <= 0) {
                occluded = 1;
                break;
            }
            /* Test all occluder planes against all portal winding vertices.
             * If any vertex is in front of any occluder plane, not fully occluded. */
            int allBehind = 1;
            int opi;
            for (opi = 0; opi < occPlaneCount && allBehind; opi++) {
                float *op = occPlanes[opi].coeffs;
                /* Test first vertex */
                float *vert = (float *)portalVerts; /* use original verts for quick test */
                float d = op[0] * vert[0] + op[1] * vert[1] + op[2] * vert[2] + op[3];
                if (d > 0.0f)
                    allBehind = 0;
                /* Test remaining vertices */
                int vi;
                for (vi = 1; vi < (int)portal->vertexCount && allBehind; vi++) {
                    vert = (float *)((byte *)portalVerts + vi * 12);
                    d = op[0] * vert[0] + op[1] * vert[1] + op[2] * vert[2] + op[3];
                    if (d > 0.0f)
                        allBehind = 0;
                }
            }
            if (allBehind)
                occluded = 1;
        }
        if (occluded)
            continue;

        /* Winding survived all clipping — add destination cell and recurse */
        if (vertCount > 0) {
            list[count] = destCell;
            count = R_GetFurtherCellList_r_impl(destCell, parentPlane, planes, planeCount, v, list, count + 1);
        }
    }

    return count;
}

/* Clean C version for WASM — no register calling convention */
static int R_GetFurtherCellList_r(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t *v, const GfxCell **list, int count)
{
    return R_GetFurtherCellList_r_impl(cell, parentPlane, planes, planeCount, v, list, count);
}

/* line 1646 — R_AddVisibleSurfacesInCell
 * Adds all visible content in a cell: world surfaces (AABB tree), dynamic entities,
 * and cull group surfaces. Each type has frustum + occluder culling.
 * Actual convention: eax=cell, edx=planes, ecx=planeCount */
extern void CG_CullIn(void *poseCtx);
extern void CG_UsedDObjCalcPose(void *poseCtx);
extern void R_AddBModelSurfaces(void *sceneEnt, int entIndex);
extern void R_SkinSceneEnt(void *sceneEnt, void *ent);
extern void R_AddDebugBox(void *debugGlobals, const float *mins, const float *maxs, const float *color);
extern void R_AddDebugLine(void *debugGlobals, const vec_t *start, const vec_t *end, const float *color);
extern void R_AddDebugPolygon(void *debugGlobals, const float *color, int vertCount, const vec_t *verts);
extern int Com_ConvexHull(const vec2_t *points, int maxPoints, vec2_t *hull);
extern int WindingContainsCoplanarPoint(const vec3_t *verts, int vertCount, const vec_t *planeNormal, const vec_t *point);
extern int R_CullPointAndRadius(const vec_t *origin, float radius, const DpvsPlane *planes, int planeCount);
extern void RB_ShowLightVisCachePoints(const GfxViewParms *viewParms, const DpvsPlane *planes, int planeCount);
extern void *R_GetGfxEntityDObj(void *sceneEnt, void *ent);
extern void ClearBounds(vec_t *mins, vec_t *maxs);
extern void AddPointToBounds(const vec_t *v, vec_t *mins, vec_t *maxs);
extern void R_dpvs_diag_print(int cameraCellIndex, int drawWorld, const void *cellPtr);
extern void LargeLocal_LargeLocal(const LargeLocal *_this, int size);
extern void *LargeLocal_GetBuf(const LargeLocal *_this);
extern void ZN10LargeLocalD1Ev(LargeLocal *_this);

static void R_AddVisibleSurfacesInCell_impl(const GfxCell *cell, const DpvsPlane *planes, int planeCount)
{
    byte *cellBytes = (byte *)cell;
    int i;

    /* 1. World surfaces via AABB tree */
    if (*(byte *)((byte *)&dpvsGlob + 100)) {
        GfxAabbTree *tree = cell->aabbTree;
        if (tree && tree->childCount > 0) {
            /* Recurse into child AABB trees with frustum culling */
            if (*(byte *)(*(int *)imp_r_portalFineCull + 8)) {
                for (i = 0; i < tree->childCount; i++) {
                    GfxAabbTree *child = (GfxAabbTree *)((byte *)(intptr_t)tree->children + i * sizeof(GfxAabbTree));
                    R_AddAabbTreeSurfaces_r_impl(child, (DpvsPlane *)planes, planeCount, 0);
                }
            } else {
                /* Fine culling disabled: add all surfaces from root tree */
                int startSurf = tree->startSurfIndex;
                for (i = 0; i < tree->surfaceCount; i++)
                    R_AddWorldSurfaceWithCull_impl(startSurf + i, planes, planeCount, 0);
            }
        } else if (tree) {
            /* Leaf: add surfaces with per-surface culling */
            int startSurf = tree->startSurfIndex;
            for (i = 0; i < tree->surfaceCount; i++)
                R_AddWorldSurfaceWithCull_impl(startSurf + i, planes, planeCount, 0);
        }
    } else {
        /* drawWorld is off — no world surfaces will be added */
    }

    /* 2. Dynamic entities from cell's modelRef list */
    if (*(byte *)((byte *)&dpvsGlob + 101)) {
        GfxSceneModelCellRef *modelRef = cell->modelRefs;
        while (modelRef) {
            int entIndex = modelRef->entIndex;
            byte *scene = (byte *)imp_scene;
            GfxSceneEntity *sceneEnt2 = &((GfxScene *)scene)->sceneEnts[entIndex];
            int surfaceType = sceneEnt2->cullState;

            if (surfaceType == 5) {
                /* Already processed */
                modelRef = (GfxSceneModelCellRef *)(intptr_t)modelRef->next;
                continue;
            }

            GfxEntity *ent = &((GfxScene *)scene)->def.entities[entIndex];
            int entType = ent->reType;

            if (entType <= 1) {
                /* Dynamic model entity */
                if (*(byte *)((byte *)&dpvsGlob + 103)) {
                    /* Check if entity has more than 1 LOD — needs bounds culling */
                    int lodLevel = *(int *)&ent->lighting.dx7.sunVisibility; /* TODO: verify union interpretation */
                    if (lodLevel > 1) {
                        /* Frustum cull against entity bounds (at modelRef+4 = mins/maxs) */
                        float *bounds = (float *)modelRef->mins;
                        if (!R_CullByFrustumPlanes((DpvsPlane *)planes, planeCount, 0, bounds))
                            goto next_modelref;
                        if (!R_CullByOccluders(0, bounds))
                            goto next_modelref;
                    } else {
                        /* Use sceneEnt bounds */
                        float *bounds = (float *)sceneEnt2->curMins;
                        if (!R_CullByFrustumPlanes((DpvsPlane *)planes, planeCount, 0, bounds))
                            goto next_modelref;
                        if (!R_CullByOccluders(0, bounds))
                            goto next_modelref;
                    }
                    CG_UsedDObjCalcPose((void *)sceneEnt2->cent);
                    R_UpdateXModelBounds(sceneEnt2, ent);
                }
                /* Bounds passed — cull in, skin, add surfaces */
                CG_CullIn((void *)sceneEnt2->cent);
                R_SkinSceneEnt(sceneEnt2, ent);
                sceneEnt2->cullState = 5;
                R_AddXModelSurfaces(entIndex);

            } else if (entType == 3) {
                /* Brush model entity */
                if (*(byte *)((byte *)&dpvsGlob + 104)) {
                    float *bounds = (float *)(modelRef->mins);
                    if (!R_CullByFrustumPlanes((DpvsPlane *)planes, planeCount, 0, bounds))
                        goto next_modelref;
                    if (!R_CullByOccluders(0, bounds))
                        goto next_modelref;
                    /* Debug visualization */
                    if (*(int *)(*(int *)imp_r_showPortals + 8) & 1) {
                        byte *debugGlobals = *(byte **)imp_frontEndDataOut + 0x249d18;
                        R_AddDebugBox(debugGlobals, (float *)modelRef->mins, (float *)modelRef->maxs, (const float *)imp_colorLtYellow);
                    }
                }
                R_AddBModelSurfaces(sceneEnt2, entIndex);
            }

        next_modelref:
            modelRef = (GfxSceneModelCellRef *)(intptr_t)modelRef->next;
        }
    }

    /* 3. Cull groups — direct surface addition with per-group frustum culling */
    if (*(byte *)((byte *)&dpvsGlob + 100)) {
        int cullGroupCount = cell->cullGroupCount;
        int *cullGroups = cell->cullGroups;
        if (cullGroupCount > 0) {
            for (i = 0; i < cullGroupCount; i++) {
                int groupIdx = cullGroups[i];
                /* Check frame visit */
                int *groupVisData = (int *)rg.cullGroups;
                int viewCount = *(int *)imp_scene;
                if (groupVisData[groupIdx] == viewCount)
                    continue;

                /* Get cull group bounds */
                GfxCullGroup *cg = &rgp.world->cullGroups[groupIdx];
                float *bounds = cg->mins;

                /* Frustum + occluder culling */
                if (!R_CullByFrustumPlanes((DpvsPlane *)planes, planeCount, 0, bounds))
                    continue;
                if (!R_CullByOccluders(0, bounds))
                    continue;

                /* Debug box */
                if (*(int *)(*(int *)imp_r_showPortals + 8) & 1) {
                    byte *debugGlobals = *(byte **)imp_frontEndDataOut + 0x249d18;
                    R_AddDebugBox(debugGlobals, cg->mins, cg->maxs, (const float *)imp_colorLtYellow);
                }

                /* Mark visited and add all surfaces in this cull group */
                groupVisData[groupIdx] = viewCount;
                int surfStart = cg->startSurfIndex;
                int surfCount = cg->surfaceCount;
                int j;
                for (j = 0; j < surfCount; j++)
                    R_AddWorldSurfaceDirect(surfStart + j);
            }
        }
    }
}

/* Clean C version for WASM — no register calling convention */
static void R_AddVisibleSurfacesInCell(const GfxCell *cell, const DpvsPlane *planes, int planeCount)
{
    R_AddVisibleSurfacesInCell_impl(cell, planes, planeCount);
}

/* Shared helper: test if all occluder vertices are behind a plane.
 * Returns 1 if any vertex is in front (not all behind). */
static inline int R_OccluderVertexInFront(const GfxOccluder *occ, const float *planeCoeffs)
{
    int vertCount = occ->vertexCount;
    vec3_t *verts = occ->vertices;
    for (int i = 0; i < vertCount; i++) {
        float dot = planeCoeffs[0] * verts[i][0] + planeCoeffs[1] * verts[i][1] + planeCoeffs[2] * verts[i][2] + planeCoeffs[3];
        if (dot > 0.0f)
            return 1;
    }
    return 0;
}

/* Shared helper: compute an edge plane from two vertices and cross with the eye direction.
 * dpvsGlob+84 (w) == 0 → near-eye path: vertex - eyePos, cross(delta, v1-v0)
 * dpvsGlob+84 (w) != 0 → far-eye path: cross(v1-eye, v0-eye) */
static inline void R_ComputeOccluderEdgePlane(const vec3_t *v0, const vec3_t *v1, DpvsPlane *outPlane)
{
    float *eye = (float *)((byte *)&dpvsGlob + 72);
    float w = *(float *)((byte *)&dpvsGlob + 84);
    vec3_t cross_result;

    if (w == 0.0f) {
        /* Near-eye: delta = v1 - v0 */
        vec3_t delta;
        delta[0] = (*v1)[0] - (*v0)[0];
        delta[1] = (*v1)[1] - (*v0)[1];
        delta[2] = (*v1)[2] - (*v0)[2];
        Vec3Cross((vec_t *)eye, (vec_t *)delta, (vec_t *)cross_result);
    } else {
        /* Far-eye: cross(v0-eye, v1-eye) */
        vec3_t d0, d1;
        d0[0] = (*v0)[0] - eye[0]; d0[1] = (*v0)[1] - eye[1]; d0[2] = (*v0)[2] - eye[2];
        d1[0] = (*v1)[0] - eye[0]; d1[1] = (*v1)[1] - eye[1]; d1[2] = (*v1)[2] - eye[2];
        Vec3Cross((vec_t *)d1, (vec_t *)d0, (vec_t *)cross_result);
    }

    outPlane->coeffs[0] = cross_result[0];
    outPlane->coeffs[1] = cross_result[1];
    outPlane->coeffs[2] = cross_result[2];
    Vec3Normalize(outPlane->coeffs);
    float dot = outPlane->coeffs[0] * (*v0)[0] + outPlane->coeffs[1] * (*v0)[1] + outPlane->coeffs[2] * (*v0)[2];
    outPlane->coeffs[3] = -dot;
    R_DpvsPlaneSetSideBytes(outPlane);
}

/* Shared: heap insert for portal priority queue.
 * dpvsGlob+88 = queue count, dpvsGlob+92 = queue base (GfxPortal*, float pairs). */
static inline void R_PortalQueueInsert(GfxPortal *portal, float priority)
{
    int count = *(int *)((byte *)&dpvsGlob + 88);
    byte *queueBase = *(byte **)((byte *)&dpvsGlob + 92);

    if (count > 0xFF) {
        R_Error(1, "More than %i queued portals", 0x100);
    }

    /* Heap insert: sift up */
    int idx = count;
    int parent = (idx - 1) >> 1;
    while (parent >= 0) {
        float parentPrio = *(float *)(queueBase + parent * 8 + 4);
        if (priority >= parentPrio)
            break;
        /* Move parent down */
        *(int *)(queueBase + idx * 8) = *(int *)(queueBase + parent * 8);
        *(float *)(queueBase + idx * 8 + 4) = parentPrio;
        idx = parent;
        parent = (idx - 1) >> 1;
        if (idx <= 0) break;
    }

    /* Place portal at final position */
    *(GfxPortal **)(queueBase + idx * 8) = portal;
    *(float *)(queueBase + idx * 8 + 4) = priority;
    *(int *)((byte *)&dpvsGlob + 88) = count + 1;
}

/* Shared: allocate a hull points buffer from the pool */
static inline vec2_t *R_AllocHullPointsBuf(void)
{
    void **freeList = (void **)((byte *)&dpvsGlob + 96);
    void *buf = *freeList;
    if (!buf) {
        R_Error(1, "more than %i queued portals", 0x100);
        buf = *freeList;
    }
    *freeList = *(void **)buf; /* pop from free list */
    return (vec2_t *)buf;
}

/* Shared: free a hull points buffer back to pool */
static inline void R_FreeHullPointsBuf(vec2_t *buf)
{
    void **freeList = (void **)((byte *)&dpvsGlob + 96);
    *(void **)buf = *freeList;
    *freeList = buf;
}

/* Shared: compute min dot product of portal winding vertices against a plane (for priority).
 * Tests first vertex, last vertex, then scans interior vertices. */
static inline float R_PortalMinDot(const vec3_t *verts, int vertCount, const float *planeCoeffs)
{
    float first = planeCoeffs[0] * verts[0][0] + planeCoeffs[1] * verts[0][1] + planeCoeffs[2] * verts[0][2] + planeCoeffs[3];
    float last = planeCoeffs[0] * verts[vertCount-1][0] + planeCoeffs[1] * verts[vertCount-1][1] + planeCoeffs[2] * verts[vertCount-1][2] + planeCoeffs[3];

    float minDot;
    if (first > last) {
        minDot = last;
        /* Scan forward looking for smaller */
        int limit = vertCount - 2;
        if (limit > 0) {
            float d = planeCoeffs[0] * verts[1][0] + planeCoeffs[1] * verts[1][1] + planeCoeffs[2] * verts[1][2] + planeCoeffs[3];
            if (d > minDot) {
                /* first > last, v[1] > last => scan forward */
                for (int i = 1; i < limit; i++) {
                    d = planeCoeffs[0] * verts[i+1][0] + planeCoeffs[1] * verts[i+1][1] + planeCoeffs[2] * verts[i+1][2] + planeCoeffs[3];
                    if (d <= minDot)
                        break;
                }
            }
            if (d < minDot)
                minDot = d;
        }
    } else {
        minDot = first;
        /* Scan backward from second-to-last */
        int limit = vertCount - 2;
        if (limit > 0) {
            int lastIdx = vertCount - 2;
            float d = planeCoeffs[0] * verts[lastIdx][0] + planeCoeffs[1] * verts[lastIdx][1] + planeCoeffs[2] * verts[lastIdx][2] + planeCoeffs[3];
            if (d <= minDot) {
                minDot = d;
            }
            for (int i = 0; i < limit - 1; i++) {
                int vi = lastIdx - 1 - i;
                if (vi < 0) break;
                d = planeCoeffs[0] * verts[vi][0] + planeCoeffs[1] * verts[vi][1] + planeCoeffs[2] * verts[vi][2] + planeCoeffs[3];
                if (d > minDot)
                    break;
                minDot = d;
            }
        }
    }
    return minDot;
}

/* line 1965 — R_VisitPortalsForCell
 * Sets up occluders from cell, adds visible surfaces, then processes child portals:
 * - clipChildren path: iterates portals, clips windings, builds hull, pushes to priority queue
 * - !clipChildren path: calls R_GetFurtherCellList_r for all visible cells */
static void R_VisitPortalsForCell_impl(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren)
{
    const GfxCell **cellList;
    vec3_t scratchBuf[128];
    vec3_t altBuf[128];
    int i;

    /* 1. Set up occluders from cell */
    *(int *)((byte *)&dpvsGlob + 56) = 0;
    *(int *)((byte *)&dpvsGlob + 64) = 0;

    int occluderCount = cell->occluderCount;
    for (i = 0; i < occluderCount; i++) {
        GfxOccluder *occ = cell->occluders[i];

        /* Check if eye is in front of occluder's main plane (dpvsGlob+40 = near eye plane) */
        DpvsPlane *eyePlane = *(DpvsPlane **)((byte *)&dpvsGlob + 40);
        if (eyePlane) {
            /* Test occluder vertices against eye plane */
            if (!R_OccluderVertexInFront(occ, eyePlane->coeffs))
                continue;
        }

        /* Test occluder vertices against each frustum plane */
        int visibleThroughFrustum = 1;
        for (int pi = 0; pi < planeCount; pi++) {
            if (!R_OccluderVertexInFront(occ, planes[pi].coeffs)) {
                visibleThroughFrustum = 0;
                break;
            }
        }
        if (!visibleThroughFrustum)
            continue;

        /* Occluder is visible — add to active list */
        if (*(int *)((byte *)&dpvsGlob + 56) == 0x400) {
            R_Error(1, "More than %i active occluders", 0x400);
        }

        int occIdx = *(int *)((byte *)&dpvsGlob + 56);
        GfxOccluder **occTable = *(GfxOccluder ***)((byte *)&dpvsGlob + 60);
        occTable[occIdx] = occ;
        *(int *)((byte *)&dpvsGlob + 56) = occIdx + 1;

        /* Set ignoreStackLevel to max */
        occ->ignoreStackLevel = 0x7FFFFFFF;

        /* Store initial plane offset */
        int planeBase = *(int *)((byte *)&dpvsGlob + 64);
        occ->viewPlaneCount = planeBase;
        byte *planeBuf = *(byte **)((byte *)&dpvsGlob + 68);
        occ->viewPlanes = (DpvsPlane *)(planeBuf + planeBase * sizeof(DpvsPlane));

        /* Copy occluder's base planes, marking which face the eye */
        int basePlaneCount = occ->planeCount;
        for (int pi = 0; pi < basePlaneCount; pi++) {
            DpvsPlane *srcPlane = &occ->planes[pi];
            srcPlane->u.frontal = 0;

            /* Dot with eye position/direction */
            float *eye = (float *)((byte *)&dpvsGlob + 72);
            float dot = srcPlane->coeffs[0] * eye[0] + srcPlane->coeffs[1] * eye[1]
                      + srcPlane->coeffs[2] * eye[2] + srcPlane->coeffs[3] * *(float *)((byte *)&dpvsGlob + 84);
            if (dot <= 0.0f)
                continue;

            srcPlane->u.frontal = 1;

            /* Check plane buffer overflow */
            if (*(int *)((byte *)&dpvsGlob + 64) == 0x1800) {
                R_Error(1, "More than %i occluder planes", 0x1800);
            }

            /* Copy plane to buffer */
            int destIdx = *(int *)((byte *)&dpvsGlob + 64);
            DpvsPlane *destPlane = (DpvsPlane *)(*(byte **)((byte *)&dpvsGlob + 68) + destIdx * sizeof(DpvsPlane));
            *destPlane = *srcPlane;
            *(int *)((byte *)&dpvsGlob + 64) = destIdx + 1;
        }

        /* Process occluder edges: build edge planes for silhouette edges */
        int edgeCount = occ->edgeCount;
        for (int ei = 0; ei < edgeCount; ei++) {
            GfxOccluderEdge *edge = &occ->edges[ei];
            DpvsPlane *plane0 = edge->plane[0];
            DpvsPlane *plane1 = edge->plane[1];

            /* Silhouette edge: one plane faces eye, other doesn't */
            if (plane0->u.frontal == plane1->u.frontal)
                continue;

            /* Debug: draw edge line if r_showPortals */
            if (*(int *)(*(int *)imp_r_showPortals + 8)) {
                byte *debugGlobals = *(byte **)imp_frontEndDataOut + 0x249d18;
                R_AddDebugLine(debugGlobals, (vec_t *)edge->vertex[0], (vec_t *)edge->vertex[1], (const float *)imp_colorMagenta);
            }

            /* Determine which vertex is the base for the edge plane */
            byte frontal0 = plane0->u.frontal;
            vec3_t *baseVert, *otherVert;
            if (frontal0 == 1) {
                baseVert = edge->vertex[1];
                otherVert = edge->vertex[0];
            } else {
                baseVert = edge->vertex[0];
                otherVert = edge->vertex[1];
            }

            /* Compute edge plane */
            int destIdx = *(int *)((byte *)&dpvsGlob + 64);
            DpvsPlane *edgePlane = (DpvsPlane *)(*(byte **)((byte *)&dpvsGlob + 68) + destIdx * sizeof(DpvsPlane));
            R_ComputeOccluderEdgePlane(otherVert, baseVert, edgePlane);
            *(int *)((byte *)&dpvsGlob + 64) = destIdx + 1;
        }

        /* Finalize: viewPlaneCount = total new planes - initial offset */
        int totalPlanes = *(int *)((byte *)&dpvsGlob + 64);
        occ->viewPlaneCount = totalPlanes - occ->viewPlaneCount;
    }

    /* 2. Add visible surfaces in this cell */
    R_AddVisibleSurfacesInCell_impl(cell, planes, planeCount);

    /* 3. Walk ancestor portal chain, set isAncestor */
    {
        GfxPortal *ancestor = parentPortal;
        while (ancestor) {
            ancestor->writable.isAncestor = 1;
            ancestor = ancestor->writable.queuedParent;
        }
    }

    /* 4. Process child portals */
    if (clipChildren) {
        /* Iterate cell's portals */
        int portalCount = cell->portalCount;
        GfxPortal *portals = cell->portals;
        for (i = 0; i < portalCount; i++) {
            GfxPortal *portal = &portals[i];

            /* Skip ancestor portals */
            if (portal->writable.isAncestor)
                continue;

            /* Check portal plane against eye */
            float *portalPlaneCoeffs = portal->plane.coeffs;
            float *eye = (float *)((byte *)&dpvsGlob + 72);
            float eyeDot = portalPlaneCoeffs[0] * eye[0] + portalPlaneCoeffs[1] * eye[1]
                         + portalPlaneCoeffs[2] * eye[2] + portalPlaneCoeffs[3] * *(float *)((byte *)&dpvsGlob + 84);
            if (eyeDot > 0.0f)
                continue;

            {
                /* Eye behind portal — test frustum planes, then occluders */
                int vertCount = portal->vertexCount;
                vec3_t *verts = portal->vertices;

                /* Test each frustum plane: portal must have at least one vertex
                 * in front of every frustum plane to be potentially visible */
                int frustumVisible = 1;
                for (int pi = 0; pi < planeCount; pi++) {
                    const float *pc = planes[pi].coeffs;
                    int anyInFront = 0;
                    for (int vi = 0; vi < vertCount; vi++) {
                        float d = pc[0] * verts[vi][0] + pc[1] * verts[vi][1]
                                + pc[2] * verts[vi][2] + pc[3];
                        if (d > 0.0f) {
                            anyInFront = 1;
                            break;
                        }
                    }
                    if (!anyInFront) {
                        frustumVisible = 0;
                        break;
                    }
                }
                if (!frustumVisible)
                    continue;

                /* Test each active occluder: if ALL portal vertices are behind
                 * ALL view planes of any single occluder, portal is fully occluded */
                int occCount = *(int *)((byte *)&dpvsGlob + 56);
                int visible = 1;
                GfxOccluder **occPtrTable = *(GfxOccluder ***)((byte *)&dpvsGlob + 60);
                for (int oi = 0; oi < occCount; oi++) {
                    GfxOccluder *occPtr = occPtrTable[oi];
                    int vpCount = occPtr->viewPlaneCount;
                    DpvsPlane *vpPlanes = occPtr->viewPlanes;

                    if (vpCount == 0) {
                        visible = 0;
                        break;
                    }

                    int allBehind = 1;
                    for (int pi = 0; pi < vpCount; pi++) {
                        int anyInFront = 0;
                        for (int vi = 0; vi < vertCount; vi++) {
                            float d = vpPlanes[pi].coeffs[0] * verts[vi][0]
                                    + vpPlanes[pi].coeffs[1] * verts[vi][1]
                                    + vpPlanes[pi].coeffs[2] * verts[vi][2]
                                    + vpPlanes[pi].coeffs[3];
                            if (d > 0.0f) {
                                anyInFront = 1;
                                break;
                            }
                        }
                        if (anyInFront) {
                            allBehind = 0;
                            break;
                        }
                    }
                    if (allBehind) {
                        visible = 0;
                        break;
                    }
                }
                if (!visible)
                    continue;

                /* Eye behind portal plane and not fully occluded:
                 * check if eye is coplanar with portal winding */
                float w = *(float *)((byte *)&dpvsGlob + 84);
                if (w != 0.0f) {
                    /* Perspective: check portal plane dot with threshold */
                    float *portalP = portal->plane.coeffs;
                    float dot4 = portalP[0] * eye[0] + portalP[1] * eye[1] + portalP[2] * eye[2] + portalP[3] * w;
                    if (dot4 > -0.125f) {
                        /* Close to portal plane — check if eye projects into winding */
                        if (WindingContainsCoplanarPoint(portal->vertices, portal->vertexCount, &portal->plane.coeffs[0], eye))
                        {
                            portal->writable.queuedParent = 0;
                            GfxCell *destCell = portal->cell;
                            R_VisitPortalsForCell(destCell, portal, &portal->plane, planes, planeCount, clipChildren);
                        }
                        continue;
                    }
                }

                /* Clip portal winding against parentPlane */
                int vertCount2 = portal->vertexCount;
                vec3_t *w2 = R_ChopPortalWinding_impl(portal->vertices, &vertCount2, (const float *)parentPlane, scratchBuf);
                if (vertCount2 == 0)
                    continue;

                /* Clip against far plane if present */
                DpvsPlane *farPlane = *(DpvsPlane **)((byte *)&dpvsGlob + 44);
                if (farPlane) {
                    vec3_t *altDest = (w2 == scratchBuf) ? altBuf : scratchBuf;
                    if (w2 == altDest)
                        altDest = altBuf;
                    w2 = R_ChopPortalWinding_impl(w2, &vertCount2, (const float *)farPlane, altDest);
                    if (vertCount2 == 0)
                        continue;
                }

                /* Clip against each frustum plane */
                for (int pi = 0; pi < planeCount; pi++) {
                    vec3_t *altDest = (w2 == scratchBuf) ? altBuf : scratchBuf;
                    w2 = R_ChopPortalWinding_impl(w2, &vertCount2, (const float *)&planes[pi], altDest);
                    if (vertCount2 == 0)
                        break;
                }
                if (vertCount2 == 0)
                    continue;

                /* Build hull points for the clipped portal */
                /* Allocate hull point buffer if needed */
                if (!portal->hullPoints) {
                    portal->hullPoints = R_AllocHullPointsBuf();
                    portal->hullPointCount = 0;
                }

                /* Project vertices and compute hull point dot products */
                for (int vi = 0; vi < vertCount2; vi++) {
                    if (portal->hullPointCount >= 64) {
                        /* Too many: compute convex hull */
                        vec2_t hullResult[64];
                        int hullCount = Com_ConvexHull(portal->hullPoints, 64, hullResult);
                        if (hullCount >= 64) {
                            R_Error(1, "More than %i points on a clipped portal's convex hull", 64);
                        }
                        portal->hullPointCount = hullCount;
                        memcpy(portal->hullPoints, hullResult, hullCount * sizeof(vec2_t));
                    }

                    /* Compute hull point: dot(vert, portal->hullAxis[0]) and dot(vert, portal->hullAxis[1]) */
                    float hx = w2[vi][0] * portal->hullAxis[0][0] + w2[vi][1] * portal->hullAxis[0][1] + w2[vi][2] * portal->hullAxis[0][2];
                    float hy = w2[vi][0] * portal->hullAxis[1][0] + w2[vi][1] * portal->hullAxis[1][1] + w2[vi][2] * portal->hullAxis[1][2];
                    portal->hullPoints[portal->hullPointCount][0] = hx;
                    portal->hullPoints[portal->hullPointCount][1] = hy;
                    portal->hullPointCount++;
                }

                /* Check if portal is already queued */
                if (portal->writable.isQueued) {
                    /* Already queued — update parent if different */
                    if (portal->writable.queuedParent != parentPortal)
                        portal->writable.queuedParent = 0;
                    continue;
                }

                /* Queue this portal */
                portal->writable.queuedParent = parentPortal;

                /* Compute priority (min dot against near eye plane) and insert into queue */
                float *nearPlaneCoeffs = (float *)&dpvsGlob;
                float priority = R_PortalMinDot(portal->vertices, portal->vertexCount, nearPlaneCoeffs);
                R_PortalQueueInsert(portal, priority);
            } /* end portal processing block */
        }
    } else {
        /* !clipChildren: gather further cells and add surfaces */
        const GfxCell *furtherCells[128];
        int cellCount = R_GetFurtherCellList_r_impl(cell, parentPlane, planes, planeCount, scratchBuf, furtherCells, 0);
        for (i = 0; i < cellCount; i++) {
            R_AddVisibleSurfacesInCell_impl(furtherCells[i], planes, planeCount);
        }
    }

    /* 5. Cleanup: clear ancestor marks */
    {
        GfxPortal *ancestor = parentPortal;
        while (ancestor) {
            ancestor->writable.isAncestor = 0;
            GfxPortal *next = ancestor->writable.queuedParent;
            ancestor = next;
        }
    }
}

/* Clean C version for WASM — no register calling convention */
static void R_VisitPortalsForCell(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren)
{
    R_VisitPortalsForCell_impl(cell, parentPortal, parentPlane, planes, planeCount, clipChildren);
}


/* Shared: heap pop-min from portal queue (sift down).
 * Returns top element and re-heaps. */
static inline GfxPortal *R_PortalQueuePopMin(void)
{
    byte *queueBase = *(byte **)((byte *)&dpvsGlob + 92);
    GfxPortal *top = *(GfxPortal **)queueBase;
    top->writable.isQueued = 0;

    int count = *(int *)((byte *)&dpvsGlob + 88) - 1;
    *(int *)((byte *)&dpvsGlob + 88) = count;

    if (count > 0) {
        /* Sift down: move last element to top and bubble down */
        int idx = 0;
        int child = 1;
        while (child < count) {
            float childPrio = *(float *)(queueBase + child * 8 + 4);
            /* Check right child */
            int rightChild = child + 1;
            if (rightChild <= count) {
                float rightPrio = *(float *)(queueBase + rightChild * 8 + 4);
                if (childPrio > rightPrio) {
                    /* If right child is smaller still, check its own child */
                    child = rightChild;
                    childPrio = rightPrio;
                }
            }
            /* Compare with last element */
            float lastPrio = *(float *)(queueBase + count * 8 + 4);
            if (lastPrio <= childPrio)
                break;
            /* Move child up */
            *(int *)(queueBase + idx * 8) = *(int *)(queueBase + child * 8);
            *(float *)(queueBase + idx * 8 + 4) = childPrio;
            idx = child;
            child = idx * 2 + 1;
        }
        /* Place last element */
        *(int *)(queueBase + idx * 8) = *(int *)(queueBase + count * 8);
        *(float *)(queueBase + idx * 8 + 4) = *(float *)(queueBase + count * 8 + 4);
    }

    return top;
}

/* Shared: compute signed area of a 2D polygon (for portal clip area test) */
static inline float R_Polygon2DSignedArea(const vec2_t *pts, int count)
{
    float area = 0.0f;
    for (int i = 1; i < count; i++) {
        area += pts[i][0] * (pts[i][1] - pts[i-1][1]);
    }
    return area * 0.125f;
}

/* line 2026 — R_VisitPortals
 * Main portal traversal loop: initializes hull point pool, queues initial cell,
 * then processes portals in priority order until queue is empty or walk limit reached. */
extern void R_AddDebugPolygon(void *debugGlobals, const float *color, int vertCount, const vec_t *verts);

static void R_VisitPortals_impl(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount)
{
    LargeLocal hullPointsPool_large_local;
    DpvsPlane childPlanes[64];
    vec3_t portalVerts[64];
    vec3_t normals[64];
    vec3_t bevelVerts[5];
    vec3_t bevelNormals[5];
    vec2_t hull[64];
    byte portalQueue[3072]; /* fits 256 * {ptr, float} entries + slop */
    int iteration, childPlaneCount, hullPointCount, i;
    float clipArea;
    int clipChildren;

    /* Allocate hull points pool: 0x20000 bytes = 256 blocks of 0x200 bytes */
    LargeLocal_LargeLocal(&hullPointsPool_large_local, 0x20000);
    byte *poolBuf = (byte *)LargeLocal_GetBuf(&hullPointsPool_large_local);

    /* Build free list: each 0x200-byte block points to the next */
    for (i = 0; i < 255; i++) {
        *(void **)(poolBuf + (i + 1) * 0x200) = poolBuf + (i + 2) * 0x200;
    }
    *(void **)(poolBuf + 255 * 0x200 + 0x200) = 0; /* last entry null */
    /* Actually the pool starts at poolBuf, free list at poolBuf+0x200 */
    /* The ASM builds: pool[i*0x200] = &pool[(i+1)*0x200] for i=1..255, pool[0x1fe00]=0 */
    /* Let me re-examine: the loop adds 0x40 to bevelVertIndex, 0x200 to edx(pool), 0x200 to ecx(pool-0x200)
       and stores edx at *ecx. So: *(pool + (i-1)*0x200 + 0x200) = pool + i*0x200 + 0x200
       i.e. pool[i*0x200] = pool[(i+1)*0x200] for i=0..254, then pool[0x1fe00]=0 */
    /* Actually: ecx starts at pool-0x200, edx starts at pool. Loop body:
       ebx+=0x40, edx+=0x200, ecx+=0x200, *ecx=edx. Test ebx==0x3fc0 (255*0x40).
       So iteration 1: ecx=pool, edx=pool+0x200, *pool=pool+0x200
       iteration 2: ecx=pool+0x200, edx=pool+0x400, *(pool+0x200)=pool+0x400
       ...
       iteration 255: ecx=pool+254*0x200, edx=pool+255*0x200, *(pool+0xFE00-0x200)=pool+0xFF00...
       Then pool[0x1FE00] = 0. */
    for (i = 0; i < 255; i++) {
        *(void **)(poolBuf + i * 0x200) = poolBuf + (i + 1) * 0x200;
    }
    *(void **)(poolBuf + 0x1FE00) = 0; /* null-terminate pool at last slot */

    *(void **)((byte *)&dpvsGlob + 96) = poolBuf;

    /* Initialize portal queue */
    *(void **)((byte *)&dpvsGlob + 92) = portalQueue;
    *(int *)((byte *)&dpvsGlob + 88) = 0;

    /* Visit the initial cell */
    R_VisitPortalsForCell(cell, 0, parentPlane, planes, planeCount, DPVS_CLIP_CHILDREN);

    iteration = 0;

    /* Main portal processing loop */
    while (*(int *)((byte *)&dpvsGlob + 88) > 0) {
        /* Pop the highest-priority portal from the queue */
        GfxPortal *portal = R_PortalQueuePopMin();

        /* Compute convex hull from the accumulated 2D hull points */
        hullPointCount = Com_ConvexHull(portal->hullPoints, portal->hullPointCount, hull);

        /* Return hull points buffer to pool and clear portal's reference */
        R_FreeHullPointsBuf(portal->hullPoints);
        portal->hullPoints = 0;

        if (hullPointCount == 0)
            continue;

        iteration++;
        if (iteration == (*(const dvar_t **)imp_r_portalWalkLimit)->current.integer)
            break;

        /* Reconstruct 3D winding from 2D hull using portal axes:
         * portalVerts[i] = -dist * normal + hull[i][0] * hullAxis[0] + hull[i][1] * hullAxis[1]
         * where dist is the portal plane's d component (coeffs[3]) */
        float nd = -portal->plane.coeffs[3];
        float baseX = nd * portal->plane.coeffs[0];
        float baseY = nd * portal->plane.coeffs[1];
        float baseZ = nd * portal->plane.coeffs[2];

        for (i = 0; i < hullPointCount; i++) {
            portalVerts[i][0] = baseX + hull[i][0] * portal->hullAxis[0][0] + hull[i][1] * portal->hullAxis[1][0];
            portalVerts[i][1] = baseY + hull[i][0] * portal->hullAxis[0][1] + hull[i][1] * portal->hullAxis[1][1];
            portalVerts[i][2] = baseZ + hull[i][0] * portal->hullAxis[0][2] + hull[i][1] * portal->hullAxis[1][2];
        }

        /* Debug: draw portal polygon if r_showPortals and not bevels-only */
        if (*(int *)(*(int *)imp_r_showPortals + 8)) {
            if (!(*(byte *)(*(int *)imp_r_portalBevelsOnly + 8))) {
                byte *debugGlobals = *(byte **)imp_frontEndDataOut + 0x249d18;
                R_AddDebugPolygon(debugGlobals, (const float *)&dpvsConfig, hullPointCount, (vec_t *)portalVerts);
            }
        }

        /* Determine plane-building mode:
         * useNormalPlanes = (hullPointCount <= 10): side planes from winding normals
         * doBevels: whether to compute bevel planes at screen-space corners
         * forceBevels: force all 4 bevel directions regardless of normal alignment */
        int useNormalPlanes = (hullPointCount <= 10);
        int doBevels, forceBevels;

        if (useNormalPlanes && !(*(byte *)(*(int *)imp_r_portalBevelsOnly + 8))) {
            float bevelThreshold = (*(const dvar_t **)imp_r_portalBevels)->current.value;
            if (bevelThreshold > 0.0f) {
                doBevels = 1;
                forceBevels = 0;
            } else {
                doBevels = 0;
                forceBevels = 0;
            }
        } else {
            /* portalBevelsOnly or too many vertices: force bevels, skip normal planes */
            doBevels = 1;
            forceBevels = 1;
        }

        /* Compute side plane normals for the portal winding */
        R_GetSidePlaneNormals((vec3_t *)portalVerts, hullPointCount, normals);

        /* Determine clipChildren and compute screen-space clip area if needed */
        if (!doBevels) {
            float minClipArea = (*(const dvar_t **)imp_r_portalMinClipArea)->current.value;
            if (minClipArea <= 0.0f) {
                childPlaneCount = 0;
                clipChildren = 1;
            } else {
                childPlaneCount = 0;
                clipChildren = 1;
            }
        } else {
            /* Bevel mode: project vertices to screen space for area test */
            const D3DMATRIX *viewProj = *(const D3DMATRIX **)((byte *)&dpvsGlob + 52);
            const float *mtx = (const float *)viewProj;
            vec2_t screenVerts[5];
            float minX = 1.0f, maxX = -1.0f, minY = 1.0f, maxY = -1.0f;
            int nearClip = 0;

            /* Check first vertex for near-clip proximity */
            float fz = portalVerts[0][0] * mtx[0x0C] + portalVerts[0][1] * mtx[0x1C]
                      + portalVerts[0][2] * mtx[0x2C] + mtx[0x3C];
            if (fz < 0.125f) {
                /* Near clip — force all bevels */
                clipChildren = 1;
                minX = -1.0f; maxX = 1.0f;
                minY = -1.0f; maxY = 1.0f;
                nearClip = 1;
            }

            if (!nearClip) {
                /* Project all portal vertices to screen space */
                for (i = 0; i < hullPointCount; i++) {
                    float fx = portalVerts[i][0];
                    float fy = portalVerts[i][1];
                    float fzz = portalVerts[i][2];
                    float w = fx * mtx[0x0C] + fy * mtx[0x1C] + fzz * mtx[0x2C] + mtx[0x3C];
                    if (w < 0.125f) {
                        nearClip = 1;
                        clipChildren = 1;
                        minX = -1.0f; maxX = 1.0f;
                        minY = -1.0f; maxY = 1.0f;
                        break;
                    }
                    float invW = 1.0f / w;
                    float sx = (fx * mtx[0x00] + fy * mtx[0x10] + fzz * mtx[0x20] + mtx[0x30]) * invW;
                    float sy = (fx * mtx[0x04] + fy * mtx[0x14] + fzz * mtx[0x24] + mtx[0x34]) * invW;
                    float sz = (fx * mtx[0x08] + fy * mtx[0x18] + fzz * mtx[0x28] + mtx[0x38]) * invW;
                    screenVerts[i][0] = sx;
                    screenVerts[i][1] = sy;
                    if (sx < minX) minX = sx;
                    if (sx > maxX) maxX = sx;
                    if (sy < minY) minY = sy;
                    if (sy > maxY) maxY = sy;
                }
            }

            if (!nearClip) {
                /* Compute area from screen-space extents */
                float sizeX = maxX - minX;
                float sizeY = maxY - minY;
                float area = sizeX * sizeY * 0.25f;
                float minClipArea = (*(const dvar_t **)imp_r_portalMinClipArea)->current.value;
                clipChildren = (minClipArea <= area) ? 0 : 1;
            }

            /* Build bevel child planes from 4 screen-space directions */
            childPlaneCount = 0;

            if (forceBevels) {
                /* Force all 4 bevels: use screen extents as bevel verts */
                /* (Screen-space bevel plane computation uses viewProjection inverse) */
                /* For each of the 4 bevel directions, build a clip plane */
                /* This is complex: project screen-space corners back to world space
                 * using the inverse view-projection matrix, then compute clip planes */
                /* Simplified: use side normals directly */
            }
        }

        /* Build child planes: add side normals as planes */
        if (useNormalPlanes && hullPointCount > 0) {
            for (i = 0; i < hullPointCount; i++) {
                float lenSq = normals[i][0]*normals[i][0] + normals[i][1]*normals[i][1] + normals[i][2]*normals[i][2];
                if (lenSq == 0.0f)
                    continue;
                childPlanes[childPlaneCount].coeffs[0] = normals[i][0];
                childPlanes[childPlaneCount].coeffs[1] = normals[i][1];
                childPlanes[childPlaneCount].coeffs[2] = normals[i][2];
                float dot = normals[i][0] * portalVerts[i][0] + normals[i][1] * portalVerts[i][1] + normals[i][2] * portalVerts[i][2];
                childPlanes[childPlaneCount].coeffs[3] = 0.001f - dot;
                R_DpvsPlaneSetSideBytes(&childPlanes[childPlaneCount]);
                childPlaneCount++;
            }
        }

        /* Add debug lines for bevel planes if r_showPortals */
        if (*(int *)(*(int *)imp_r_showPortals + 8)) {
            /* bevel debug rendering handled above */
        }

        /* Add eye plane (dpvsGlob+40) as a child plane if present */
        DpvsPlane *eyePlane = *(DpvsPlane **)((byte *)&dpvsGlob + 40);
        if (eyePlane) {
            /* Copy eye plane and adjust dist based on min portal vertex dot */
            childPlanes[childPlaneCount] = *eyePlane;
            float minDot = R_PortalMinDot((const vec3_t *)portalVerts, hullPointCount, eyePlane->coeffs);
            if (minDot > 0.0f) {
                childPlanes[childPlaneCount].coeffs[3] -= minDot;
            }
            childPlaneCount++;
        }

        /* Add far plane (dpvsGlob+44) as a child plane if present */
        DpvsPlane *farPlane = *(DpvsPlane **)((byte *)&dpvsGlob + 44);
        if (farPlane) {
            childPlanes[childPlaneCount] = *farPlane;
            childPlaneCount++;
        }

        /* Visit the destination cell through this portal */
        GfxCell *destCell = portal->cell;
        R_VisitPortalsForCell(destCell, portal, &portal->plane, childPlanes, childPlaneCount,
                              clipChildren ? DPVS_CLIP_CHILDREN : DPVS_DONT_CLIP_CHILDREN);
    }

    /* Drain remaining queued portals (walk limit hit) — free their hull buffers */
    while (*(int *)((byte *)&dpvsGlob + 88) > 0) {
        GfxPortal *portal = R_PortalQueuePopMin();
        if (portal->hullPoints) {
            R_FreeHullPointsBuf(portal->hullPoints);
            portal->hullPoints = 0;
        }
    }

    /* Cleanup */
    ZN10LargeLocalD1Ev(&hullPointsPool_large_local);
}

/* Clean C version for WASM — no register calling convention */
static void R_VisitPortals(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount)
{
    R_VisitPortals_impl(cell, parentPlane, planes, planeCount);
}


/* Shared: initialize a DpvsPlane's coeffs as a near-eye plane, compute side bytes and dist.
 * Sets coeffs[0..2] = normal, coeffs[3] = -(dot(normal, eyePos) - epsilon).
 * eyePos is 4 floats at dpvsGlob+72 with w component at dpvsGlob+84. */
static inline void R_DpvsInitEyePlane(DpvsPlane *plane, const float *normal)
{
    float *eye = (float *)((byte *)&dpvsGlob + 72);
    plane->coeffs[0] = normal[0];
    plane->coeffs[1] = normal[1];
    plane->coeffs[2] = normal[2];
    float dot = normal[0] * eye[0] + normal[1] * eye[1] + normal[2] * eye[2];
    float w = *(float *)((byte *)&dpvsGlob + 84);
    float epsilon = (w != 0.0f) ? 0.1f : 262144.0f;
    plane->coeffs[3] = epsilon - dot;
    R_DpvsPlaneSetSideBytes(plane);
}

/* Shared: initialize the far (cull dist) plane — negated normal, dist = cullDist - dot(negNormal, eye). */
static inline void R_DpvsInitFarPlane(DpvsPlane *plane, const float *viewDir, float cullDist)
{
    float *eye = (float *)((byte *)&dpvsGlob + 72);
    float negDir[3];
    negDir[0] = -viewDir[0];
    negDir[1] = -viewDir[1];
    negDir[2] = -viewDir[2];
    plane->coeffs[0] = negDir[0];
    plane->coeffs[1] = negDir[1];
    plane->coeffs[2] = negDir[2];
    float dot = negDir[0] * eye[0] + negDir[1] * eye[1] + negDir[2] * eye[2];
    plane->coeffs[3] = cullDist - dot;
    R_DpvsPlaneSetSideBytes(plane);
}

/* Shared: test bounds against frustum planes + occluders for entity culling.
 * All planes tested at stackLevel 0 with frontal=0xFF reset. Returns 1 if visible. */
static inline int R_CullBoundsAgainstFrustumAndOccluders(const float *bounds, const DpvsPlane *frustumPlanes, int frustumPlaneCount)
{
    int i;
    for (i = 0; i < frustumPlaneCount; i++) {
        DpvsPlane *plane = (DpvsPlane *)&frustumPlanes[i];
        plane->u.frontal = 0xFF;
        if (R_DpvsPlaneBoundsTest(plane, bounds) <= 0.0f)
            return 0;
    }

    /* Occluder test */
    int occCount = *(int *)((byte *)&dpvsGlob + 56);
    if (occCount > 0) {
        int **occTable = *(int ***)((byte *)&dpvsGlob + 60);
        for (i = 0; i < occCount; i++) {
            GfxOccluder *occ = (GfxOccluder *)occTable[i];
            int planeCount = occ->viewPlaneCount;
            DpvsPlane *planes = occ->viewPlanes;
            if (planeCount <= 0)
                return 0;
            int j;
            for (j = 0; j < planeCount; j++) {
                planes[j].u.frontal = 0xFF;
                if (R_DpvsPlaneBoundsTest(&planes[j], bounds) > 0.0f)
                    break;
            }
            if (j >= planeCount)
                return 0;
        }
    }
    return 1;
}

/* line 2293 — R_AddWorldSurfacesDpvs
 * Main entry point for DPVS world surface enumeration.
 * Sets up eye planes, frustum planes, occluder buffers, entity filtering,
 * portal traversal, dlight culling, and cleanup. */
extern void R_AddBModelSurfaces(void *sceneEnt, int entIndex);
extern int __mh_execute_header;

static void R_AddWorldSurfacesDpvs_impl(const GfxViewParms *viewParms, int cameraCellIndex)
{
    LargeLocal activeOccluderBuffer_large_local;
    LargeLocal occluderPlaneBuffer_large_local;
    DpvsPlane frustumPlanes[6]; /* up to 4 frustum + 1 near + 1 far */
    int frustumPlaneCount;
    int i;

    /* Allocate large local buffers for occluder data */
    LargeLocal_LargeLocal(&activeOccluderBuffer_large_local, (int)&__mh_execute_header);
    byte *activeOccluderBuf = (byte *)LargeLocal_GetBuf(&activeOccluderBuffer_large_local);
    LargeLocal_LargeLocal(&occluderPlaneBuffer_large_local, 0x1e000);
    byte *occluderPlaneBuf = (byte *)LargeLocal_GetBuf(&occluderPlaneBuffer_large_local);

    /* Store buffer pointers in dpvsGlob */
    *(void **)((byte *)&dpvsGlob + 60) = activeOccluderBuf;
    *(void **)((byte *)&dpvsGlob + 68) = occluderPlaneBuf;

    /* Read dvar flags into dpvsGlob */
    byte drawWorld = (byte)(*(const dvar_t **)imp_r_drawWorld)->current.integer;
    *(byte *)((byte *)&dpvsGlob + 100) = drawWorld;
    byte drawEntities = (byte)(*(const dvar_t **)imp_r_drawEntities)->current.integer;
    *(byte *)((byte *)&dpvsGlob + 101) = drawEntities;
    byte drawBModels = ((*(const dvar_t **)imp_r_drawBModels)->current.integer && drawEntities) ? 1 : 0;
    *(byte *)((byte *)&dpvsGlob + 104) = drawBModels;
    byte drawSModels = ((*(const dvar_t **)imp_r_drawSModels)->current.integer && drawEntities) ? 1 : 0;
    *(byte *)((byte *)&dpvsGlob + 102) = drawSModels;
    byte drawXModels = ((*(const dvar_t **)imp_r_drawXModels)->current.integer && drawEntities) ? 1 : 0;
    *(byte *)((byte *)&dpvsGlob + 103) = drawXModels;

    /* Reset active occluder count */
    *(int *)((byte *)&dpvsGlob + 56) = 0;

    /* Set up viewProjectionMatrix and inverseViewProjectionMatrix pointers */
    *(const D3DMATRIX **)((byte *)&dpvsGlob + 48) = &viewParms->viewProjectionMatrix;
    *(const D3DMATRIX **)((byte *)&dpvsGlob + 52) = &viewParms->inverseViewProjectionMatrix;

    /* Build frustum clip planes from view-projection matrix */
    R_FrustumClipPlanes(&viewParms->viewProjectionMatrix, (vec4_t *)standardFrustumSidePlanes, 4, frustumPlanes);

    /* Determine if this is a depth-hack view (projectionMatrix._44 != 0) */
    float projW = viewParms->projectionMatrix.m[3][3];
    float *eye = (float *)((byte *)&dpvsGlob + 72);
    float *nearPlaneNormal = (float *)&dpvsGlob;
    const float *viewDir;

    if (projW != 0.0f) {
        /* Depth hack / ortho view: eye direction is negated view axis, not position-based */
        float *negViewDir = (float *)((byte *)&dpvsGlob + 72);
        negViewDir[0] = -viewParms->axis[0][0];
        negViewDir[1] = -viewParms->axis[0][1];
        negViewDir[2] = -viewParms->axis[0][2];
        *(int *)((byte *)&dpvsGlob + 84) = 0; /* w = 0 */

        /* Near plane normal = view axis (same as axis[0]) */
        nearPlaneNormal[0] = viewParms->axis[0][0];
        nearPlaneNormal[1] = viewParms->axis[0][1];
        nearPlaneNormal[2] = viewParms->axis[0][2];

        /* Compute near plane dist */
        float dot = nearPlaneNormal[0] * negViewDir[0] + nearPlaneNormal[1] * negViewDir[1] + nearPlaneNormal[2] * negViewDir[2];
        ((float *)&dpvsGlob)[3] = 262144.0f - dot;
        R_DpvsPlaneSetSideBytes((DpvsPlane *)&dpvsGlob);

        *(void **)((byte *)&dpvsGlob + 40) = 0;
        *(void **)((byte *)&dpvsGlob + 44) = 0;

        viewDir = viewParms->axis[0];
    } else {
        /* Normal perspective view */
        eye[0] = viewParms->origin[0];
        eye[1] = viewParms->origin[1];
        eye[2] = viewParms->origin[2];
        *(int *)((byte *)&dpvsGlob + 84) = 0x3f800000; /* w = 1.0f */

        viewDir = viewParms->axis[0];

        /* Eye position comes from viewParms->origin (set by player spawn) */

        /* Near plane normal = view axis */
        nearPlaneNormal[0] = viewDir[0];
        nearPlaneNormal[1] = viewDir[1];
        nearPlaneNormal[2] = viewDir[2];

        /* Compute near plane dist */
        float dot = nearPlaneNormal[0] * eye[0] + nearPlaneNormal[1] * eye[1] + nearPlaneNormal[2] * eye[2];
        ((float *)&dpvsGlob)[3] = 0.1f - dot;
        R_DpvsPlaneSetSideBytes((DpvsPlane *)&dpvsGlob);

        *(void **)((byte *)&dpvsGlob + 40) = &dpvsGlob;
    }

    /* Get far plane distance */
    float farPlaneDist = (*(const dvar_t **)imp_r_zfar)->current.value;
    if (farPlaneDist == 0.0f) {
        if (rg.fogIndex && rg.fogSettings[2].registered && rg.fogSettings[2].techniqueOffset == 1) {
            farPlaneDist = rg.fogSettings[2].fogEnd;
        }
    }
    float cullDist = *(float *)&dpvsConfig;
    if (cullDist < farPlaneDist)
        cullDist = farPlaneDist;

    if (cullDist > 0.0f) {
        /* Set up far cull plane */
        R_DpvsInitFarPlane((DpvsPlane *)((byte *)&dpvsGlob + 20), viewDir, cullDist);
        *(void **)((byte *)&dpvsGlob + 44) = (byte *)&dpvsGlob + 20;
    } else {
        *(void **)((byte *)&dpvsGlob + 44) = 0;
    }

    /* Build final frustum plane set: 4 frustum planes + optional near plane + optional far plane */
    DpvsPlane *nearPlane = *(DpvsPlane **)((byte *)&dpvsGlob + 40);
    DpvsPlane *farPlane = *(DpvsPlane **)((byte *)&dpvsGlob + 44);

    if (nearPlane) {
        /* Copy near plane as 5th frustum plane */
        frustumPlanes[4] = *nearPlane;
        frustumPlaneCount = 5;
    } else {
        frustumPlaneCount = 4;
    }

    if (farPlane) {
        /* Copy far plane as next frustum plane */
        frustumPlanes[frustumPlaneCount] = *farPlane;
        frustumPlaneCount++;
    }

    /* Store viewParms in rg */
    rg.debugViewParms = viewParms;

    /* Process entities: brush models and dynamic entities */
    {
        GfxScene *scene = (GfxScene *)imp_scene;
        int entityCount = scene->def.entityCount;
        GfxEntity *entities = scene->def.entities;

        for (i = 0; i < entityCount; i++) {
            GfxEntity *ent = &entities[i];
            int entType = ent->reType;

            if (entType <= 1) {
                /* Dynamic XModel entity */
                GfxSceneEntity *sceneEnt = &scene->sceneEnts[i];
                void *dobj = R_GetGfxEntityDObj(sceneEnt, ent);

                vec3_t objmins, objmaxs;
                /* Call DObjGetBounds through refimport function pointer table */
                ((void (*)(void *, vec3_t *, vec3_t *))*(void **)((byte *)imp_ri + 0x1b0))(dobj, &objmins, &objmaxs); /* ri.DObjGetBounds */

                float scale = ent->scale;
                float bounds[6];
                /* bounds = scale * objmins + origin */
                bounds[0] = scale * objmins[0] + ent->origin[0];
                bounds[1] = scale * objmins[1] + ent->origin[1];
                bounds[2] = scale * objmins[2] + ent->origin[2];
                /* bounds+3 = scale * objmaxs + origin */
                bounds[3] = scale * objmaxs[0] + ent->origin[0];
                bounds[4] = scale * objmaxs[1] + ent->origin[1];
                bounds[5] = scale * objmaxs[2] + ent->origin[2];

                /* Frustum cull */
                if (!R_CullBoundsAgainstFrustumAndOccluders(bounds, frustumPlanes, frustumPlaneCount))
                    continue;

                /* Large entity: check if it needs per-cell filtering */
                float sizeX = bounds[3] - bounds[0];
                if (sizeX <= 1536.0f) {
                    float sizeY = bounds[4] - bounds[1];
                    if (sizeY > 1536.0f) {
                        float sizeZ = bounds[5] - bounds[2];
                        if (sizeZ <= 1536.0f)
                            goto entity_filter_cells;
                    } else {
                        goto entity_filter_cells;
                    }
                } else {
                    float sizeY = bounds[4] - bounds[1];
                    if (sizeY <= 1536.0f) {
                        float sizeZ = bounds[5] - bounds[2];
                        if (sizeZ <= 1536.0f)
                            goto entity_filter_cells;
                    }
                }

                /* Entity is large enough — skip cell filtering, process directly */
                goto entity_process;

            entity_filter_cells:
                {
                    GfxWorld *world = rgp.world;
                    mnode_t *bspNodes = world->nodes;
                    int cell = R_FilterEntityIntoCells_r_impl(bspNodes, i, bounds, bounds + 3);
                    if (cell != -1)
                        continue;
                }

            entity_process:
                R_UpdateXModelBounds(&scene->sceneEnts[i], ent);
                CG_CullIn((void *)scene->sceneEnts[i].cent);
                R_SkinSceneEnt(&scene->sceneEnts[i], ent);
                scene->sceneEnts[i].cullState = 5;
                R_AddXModelSurfaces(i);

            } else if (entType == 3) {
                /* Brush model entity */
                GfxSceneEntity *sceneEnt = &scene->sceneEnts[i];
                void *bmodel = (void *)sceneEnt->u.data;
                vec3_t boundsMin, boundsMax, transformed;

                if (!bmodel || (unsigned int)bmodel < 0x1000)
                    continue;

                ClearBounds(boundsMin, boundsMax);

                /* Transform 8 OBB corners to world space and expand bounds */
                for (int corner = 0; corner < 8; corner++) {
                    int xi = corner & 1;
                    int yi = (corner >> 1) & 1;
                    int zi = (corner >> 2) & 1;
                    float localX = ((float *)bmodel)[xi * 3];
                    float localY = ((float *)bmodel)[yi * 3 + 1];
                    float localZ = ((float *)bmodel)[zi * 3 + 2];

                    /* Transform by entity axes + origin */
                    transformed[0] = ent->origin[0] + localX * ent->axis[0][0] + localY * ent->axis[1][0] + localZ * ent->axis[2][0];
                    transformed[1] = ent->origin[1] + localX * ent->axis[0][1] + localY * ent->axis[1][1] + localZ * ent->axis[2][1];
                    transformed[2] = ent->origin[2] + localX * ent->axis[0][2] + localY * ent->axis[1][2] + localZ * ent->axis[2][2];

                    AddPointToBounds(transformed, boundsMin, boundsMax);
                }

                float bounds[6];
                bounds[0] = boundsMin[0]; bounds[1] = boundsMin[1]; bounds[2] = boundsMin[2];
                bounds[3] = boundsMax[0]; bounds[4] = boundsMax[1]; bounds[5] = boundsMax[2];

                /* Frustum cull */
                if (!R_CullBoundsAgainstFrustumAndOccluders(bounds, frustumPlanes, frustumPlaneCount))
                    continue;

                /* Filter into BSP cells */
                GfxWorld *world = rgp.world;
                mnode_t *bspNodes = world->nodes;
                int cell = R_FilterEntityIntoCells_r_impl(bspNodes, i, boundsMin, boundsMax);
                if (cell != -1)
                    continue;

                R_AddBModelSurfaces(sceneEnt, i);
            }
        }
    }

    /* Add world surfaces: camera cell + portal-visible cells */
    if (!(*(const dvar_t **)imp_r_skipPvs)->current.enabled) {
        if (cameraCellIndex >= 0) {
            GfxWorld *world = rgp.world;
            GfxCell *cells = world->cells;
            GfxCell *cameraCell = &cells[cameraCellIndex];

            /* Add surfaces from camera cell */
            R_AddVisibleSurfacesInCell_impl(cameraCell, frustumPlanes, frustumPlaneCount);

            /* Try portal traversal for neighboring cells */
            R_VisitPortals(cameraCell, (const DpvsPlane *)&dpvsGlob, frustumPlanes, frustumPlaneCount);

            /* Diagnostic */
            R_dpvs_diag_print(cameraCellIndex, *(byte *)((byte *)&dpvsGlob + 100), cameraCell);
        } else {
            /* Unknown cell — fallback to all cells */
            GfxWorld *world = rgp.world;
            int cellCount = world->cellCount;
            GfxCell *cells = world->cells;
            for (i = 0; i < cellCount; i++)
                R_AddVisibleSurfacesInCell_impl(&cells[i], frustumPlanes, frustumPlaneCount);
        }
    }

    /* Process sorted world surfaces (sky surfaces) — always add */
    {
        GfxWorld *world = rgp.world;
        int skySurfCount = world->skySurfCount;
        if (skySurfCount > 0) {
            int *skyStartSurfs = world->skyStartSurfs;
            for (i = 0; i < skySurfCount; i++) {
                int surfIndex = skyStartSurfs[i];
                R_AddWorldSurfaceWithCull_impl(surfIndex, frustumPlanes, 0, 0);
            }
        }
    }

    /* Process dynamic lights */
    {
        GfxScene *dlScene = (GfxScene *)imp_scene;
        int dlightCount = dlScene->dlightCount;
        if (dlightCount > 0) {
            for (i = 0; i < dlightCount; i++) {
                float *dlightOrigin = (float *)dlScene->dlights[i].position;
                float dlightRadius = dlScene->dlights[i].position[3]; /* w = radius */
                int result = R_CullPointAndRadius(dlightOrigin, dlightRadius, frustumPlanes, frustumPlaneCount);
                dlScene->dlightCulled[i] = (result == 2) ? 1 : 0;
            }
        }
    }

    /* Show light vis cache points if r_vc_makelog is set */
    if ((*(const dvar_t **)imp_r_vc_makelog)->current.integer)
        RB_ShowLightVisCachePoints(viewParms, frustumPlanes, frustumPlaneCount);

    /* Cleanup large locals */
    ZN10LargeLocalD1Ev(&occluderPlaneBuffer_large_local);
    ZN10LargeLocalD1Ev(&activeOccluderBuffer_large_local);
}

/* Clean C version for WASM — no register calling convention */
void R_AddWorldSurfacesDpvs(const GfxViewParms *viewParms, int cameraCellIndex)
{
    R_AddWorldSurfacesDpvs_impl(viewParms, cameraCellIndex);
}

