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
#ifndef __EMSCRIPTEN__
static int R_FilterEntityIntoCells_r(mnode_t *node, const vec_t *maxs);
#endif
static int R_FilterEntityIntoCells_r_impl(mnode_t *node, int entIndex, const vec_t *mins, const vec_t *maxs);
int R_CellForPoint(const vec_t *origin);
#ifndef __EMSCRIPTEN__
static vec3_t * R_ChopPortalWinding(vec3_t *vertsIn, int *vertexCount, vec3_t *vertsOut);
#endif
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

#ifndef __EMSCRIPTEN__
static void R_AddAabbTreeSurfaces_r(const DpvsPlane *planes, int planeCount, int stackLevel);
#endif
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
#ifndef __EMSCRIPTEN__
static int R_GetFurtherCellList_r(const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t (*v)[128], const GfxCell * *list, int count);
#endif
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
    byte *base = (byte *)imp_scene;
    byte *sceneEnt = base + 0x5c4 + entIndex * 52;
    byte *ent = *(byte **)(base + 0x10) + entIndex * 116;

    R_UpdateXModelBounds(sceneEnt, ent);
    R_SkinSceneEnt(sceneEnt, ent);
    *(int *)(sceneEnt + 0xc) = 5;
    R_AddXModelSurfaces(entIndex);
}

/* line 2343 */
float R_GetFarPlaneDist(void)
{
    float farPlaneDist = *(float *)(*(int *)(*(int *)imp_r_zfar) + 8);

    if (farPlaneDist == 0.0f) {
        byte *scene = (byte *)&rg;
        if (*(int *)(scene + 0x150c) && *(byte *)(scene + 0x14c8) && *(int *)(scene + 0x14ac) == 1) {
            farPlaneDist = *(float *)(scene + 0x14c0);
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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static int R_FilterEntityIntoCells_r(mnode_t *node, int entIndex, const vec_t *mins, const vec_t *maxs)
{
    return R_FilterEntityIntoCells_r_impl(node, entIndex, mins, maxs);
}
#else
/* x86 trampoline: eax=node, edx=entIndex, ecx=mins, stack=maxs → cdecl _impl */
static __attribute__((naked))
int R_FilterEntityIntoCells_r(mnode_t *node, const vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 8(%ebp)\n"          /* maxs (4th arg) */
        "pushl %ecx\n"             /* mins (3rd arg) */
        "pushl %edx\n"             /* entIndex (2nd arg) */
        "pushl %eax\n"             /* node (1st arg) */
        "calll R_FilterEntityIntoCells_r_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

/* line 925 */
int R_CellForPoint(const vec_t *origin)
{
    byte *world;
    byte *node;
    float *plane;
    float dot;

    world = *(byte **)((byte *)imp_rgp + 0x109c);
    if (!world) {
        R_Error(1, str_002259d0);
        world = *(byte **)((byte *)imp_rgp + 0x109c);
    }

    node = *(byte **)(world + 0xc);
    for (;;) {
        /* Leaf node: return cell index */
        if (*(int *)node != -1)
            return *(int *)(node + 8);

        /* Internal node: test against split plane */
        plane = *(float **)(node + 0xc);
        dot = origin[0] * plane[0] + origin[1] * plane[1] + origin[2] * plane[2] - plane[3];

        if (dot > 0.0f)
            node = *(byte **)(node + 0x10); /* front child */
        else
            node = *(byte **)(node + 0x14); /* back child */
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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static vec3_t *R_ChopPortalWinding(vec3_t *vertsIn, int *vertexCount, const float *plane, vec3_t *vertsOut)
{
    return R_ChopPortalWinding_impl(vertsIn, vertexCount, plane, vertsOut);
}
#else
/* x86 trampoline: eax=vertsIn, edx=vertexCount_ptr, ecx=plane, stack=vertsOut → cdecl _impl */
static __attribute__((naked))
vec3_t * R_ChopPortalWinding(vec3_t *vertsIn, int *vertexCount, vec3_t *vertsOut)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 8(%ebp)\n"          /* vertsOut (4th arg) */
        "pushl %ecx\n"             /* plane (3rd arg) */
        "pushl %edx\n"             /* vertexCount_ptr (2nd arg) */
        "pushl %eax\n"             /* vertsIn (1st arg) */
        "calll R_ChopPortalWinding_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void R_GetSidePlaneNormals(vec3_t *winding, int vertexCount, vec3_t *normals)
{
    R_GetSidePlaneNormals_impl(winding, vertexCount, normals);
}
#else
/* x86 trampoline: eax=winding, edx=vertexCount, ecx=normals → cdecl _impl */
static __attribute__((naked))
void R_GetSidePlaneNormals(vec3_t *winding, int vertexCount, vec3_t *normals)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"             /* normals (3rd arg) */
        "pushl %edx\n"             /* vertexCount (2nd arg) */
        "pushl %eax\n"             /* winding (1st arg) */
        "calll R_GetSidePlaneNormals_impl\n"
        "addl $12, %esp\n"
        "retl\n"
    );
}
#endif

/* line 1582 — R_AddStaticModelWithCull
 * Adds a static model to the scene after frustum + occluder culling.
 * LOD distance check, then frustum plane test, then global occluder test.
 * On success: marks frame, adds to scene, skins, and dispatches XModel surfaces. */
static void R_AddStaticModelWithCull_impl(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    byte *rg_ptr = (byte *)&rg;
    int *smodelDync = (int *)(*(int *)(rg_ptr + 0x3194) + smodelIndex * 8);
    int viewCount = *(int *)imp_scene;

    /* Already processed this frame? */
    if (smodelDync[0] == viewCount)
        return;

    /* Get static model instance */
    GfxStaticModelInstance *smodelInst = &rgp.world->smodelInsts[smodelIndex];

    /* LOD distance check (only if cullDist != 0) */
    if (smodelInst->cullDist != 0.0f) {
        float dist = Vec3Distance(smodelInst->origin, (const vec_t *)(rg_ptr + 0x317c));
        float scaledDist = dist * *(float *)(rg_ptr + 0x3188) + *(float *)(rg_ptr + 0x318c);
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

    /* Build scene entity: sceneEnt = scene + 0x5c4 + entIndex * 52 */
    byte *scene = (byte *)imp_scene;
    byte *sceneEnt = scene + 0x5c4 + entIndex * 52;
    /* ent = scene->entities + entIndex * 116 */
    byte *entities = *(byte **)(scene + 0x10);
    byte *ent = entities + entIndex * 116;

    R_SkinStaticModel(sceneEnt, ent, smodelIndex);
    *(int *)(sceneEnt + 0xc) = 5; /* surfaceType = 5 */

    R_AddXModelSurfaces(entIndex);
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void R_AddStaticModelWithCull(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    R_AddStaticModelWithCull_impl(smodelIndex, planes, planeCount, stackLevel);
}
#else
/* x86 trampoline: regparm(3) eax=smodelIndex, edx=planes, ecx=planeCount, stack=stackLevel → cdecl _impl */
static __attribute__((naked)) __attribute_regparm__(3)
void R_AddStaticModelWithCull(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_AddStaticModelWithCull_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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
    byte *rg_ptr = (byte *)&rg;

    /* Per-surface visibility data: skip if already visited this frame */
    int *surfVisData = *(int **)(rg_ptr + 0x3198);
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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void R_AddWorldSurfaceWithCull(int surfIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    R_AddWorldSurfaceWithCull_impl(surfIndex, planes, planeCount, stackLevel);
}
#else
/* x86 trampoline: regparm(3) eax=surfIndex, edx=planes, ecx=planeCount, stack=stackLevel → cdecl _impl */
static __attribute__((naked)) __attribute_regparm__(3)
void R_AddWorldSurfaceWithCull(int surfIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_AddWorldSurfaceWithCull_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

/* line 1088 — R_AddAabbTreeSurfaces_r
 * Recursive AABB tree traversal for the DPVS visibility system.
 * Three-phase culling: (1) near-corner frustum test, (2) occluder test,
 * (3) far-corner plane reduction to eliminate planes for children.
 * Actual calling convention: eax=tree, edx=planes, ecx=planeCount, stack=stackLevel */

/* Helper: add a static model directly to the scene (no frustum/occluder culling) */
static void R_AddStaticModelDirect(int smodelIndex)
{
    byte *rg_ptr = (byte *)&rg;
    int *smodelDync = (int *)(*(int *)(rg_ptr + 0x3194) + smodelIndex * 8);
    int viewCount = *(int *)imp_scene;

    if (smodelDync[0] == viewCount)
        return;
    smodelDync[0] = viewCount;

    GfxStaticModelInstance *inst = &rgp.world->smodelInsts[smodelIndex];

    /* LOD distance check */
    if (inst->cullDist != 0.0f) {
        float dist = Vec3Distance(inst->origin, (const vec_t *)(rg_ptr + 0x317c));
        float scaledDist = dist * *(float *)(rg_ptr + 0x3188) + *(float *)(rg_ptr + 0x318c);
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

    byte *scene = (byte *)imp_scene;
    byte *sceneEnt = scene + 0x5c4 + entIndex * 52;
    byte *ent = *(byte **)(scene + 0x10) + entIndex * 116;
    R_SkinStaticModel(sceneEnt, ent, smodelIndex);
    *(int *)(sceneEnt + 0xc) = 5;
    R_AddXModelSurfaces(entIndex);
}

/* Helper: add a world surface directly (no frustum culling, just frame check) */
static void R_AddWorldSurfaceDirect(int surfIndex)
{
    int *surfVisData = *(int **)((byte *)&rg + 0x3198);
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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void R_AddAabbTreeSurfaces_r(GfxAabbTree *tree, DpvsPlane *planes, int planeCount, int stackLevel)
{
    R_AddAabbTreeSurfaces_r_impl(tree, planes, planeCount, stackLevel);
}
#else
/* x86 trampoline: eax=tree, edx=planes, ecx=planeCount, stack=stackLevel → cdecl _impl */
static __attribute__((naked))
void R_AddAabbTreeSurfaces_r(const DpvsPlane *planes, int planeCount, int stackLevel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_AddAabbTreeSurfaces_r_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static int R_GetFurtherCellList_r(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t *v, const GfxCell **list, int count)
{
    return R_GetFurtherCellList_r_impl(cell, parentPlane, planes, planeCount, v, list, count);
}
#else
/* x86 trampoline: eax=cell, edx=parentPlane, ecx=planes, stack=planeCount,v,list,count → cdecl _impl */
static __attribute__((naked))
int R_GetFurtherCellList_r(const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t (*v)[128], const GfxCell * *list, int count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 0x14(%ebp)\n"
        "pushl 0x10(%ebp)\n"
        "pushl 0xc(%ebp)\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_GetFurtherCellList_r_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

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
            byte *sceneEnt = scene + 0x5c4 + entIndex * 52;
            int surfaceType = *(int *)(sceneEnt + 0xc);

            if (surfaceType == 5) {
                /* Already processed */
                modelRef = (GfxSceneModelCellRef *)(intptr_t)modelRef->next;
                continue;
            }

            byte *entities = *(byte **)(scene + 0x10);
            byte *ent = entities + entIndex * 116;
            int entType = *(int *)ent;

            if (entType <= 1) {
                /* Dynamic model entity */
                if (*(byte *)((byte *)&dpvsGlob + 103)) {
                    /* Check if entity has more than 1 LOD — needs bounds culling */
                    int lodLevel = *(int *)(ent + 0xc);
                    if (lodLevel > 1) {
                        /* Frustum cull against entity bounds (at modelRef+4 = mins/maxs) */
                        float *bounds = (float *)modelRef->mins;
                        if (!R_CullByFrustumPlanes((DpvsPlane *)planes, planeCount, 0, bounds))
                            goto next_modelref;
                        if (!R_CullByOccluders(0, bounds))
                            goto next_modelref;
                    } else {
                        /* Use sceneEnt bounds (at sceneEnt+0x14) */
                        float *bounds = (float *)(sceneEnt + 0x14);
                        if (!R_CullByFrustumPlanes((DpvsPlane *)planes, planeCount, 0, bounds))
                            goto next_modelref;
                        if (!R_CullByOccluders(0, bounds))
                            goto next_modelref;
                    }
                    CG_UsedDObjCalcPose(*(void **)(sceneEnt + 8));
                    R_UpdateXModelBounds(sceneEnt, ent);
                }
                /* Bounds passed — cull in, skin, add surfaces */
                CG_CullIn(*(void **)(sceneEnt + 8));
                R_SkinSceneEnt(sceneEnt, ent);
                *(int *)(sceneEnt + 0xc) = 5;
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
                R_AddBModelSurfaces(sceneEnt, entIndex);
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
                int *groupVisData = *(int **)((byte *)&rg + 0x319c);
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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void R_AddVisibleSurfacesInCell(const GfxCell *cell, const DpvsPlane *planes, int planeCount)
{
    R_AddVisibleSurfacesInCell_impl(cell, planes, planeCount);
}
#else
/* x86 trampoline: eax=cell, edx=planes, ecx=planeCount → cdecl _impl */
static __attribute__((naked))
void R_AddVisibleSurfacesInCell(const GfxCell *cell, const DpvsPlane *planes, int planeCount)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_AddVisibleSurfacesInCell_impl\n"
        "addl $12, %esp\n"
        "retl\n"
    );
}
#endif

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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void R_VisitPortalsForCell(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren)
{
    R_VisitPortalsForCell_impl(cell, parentPortal, parentPlane, planes, planeCount, clipChildren);
}
#else
/* x86 trampoline: eax=cell, edx=parentPortal, ecx=parentPlane, stack=planes,planeCount,clipChildren → cdecl _impl */
static __attribute__((naked))
void R_VisitPortalsForCell(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren)
{
    __asm__ __volatile__ (
        "pushl 0x10(%ebp)\n"  /* clipChildren */
        "pushl 0x0c(%ebp)\n"  /* planeCount */
        "pushl 0x08(%ebp)\n"  /* planes */
        "pushl %ecx\n"        /* parentPlane */
        "pushl %edx\n"        /* parentPortal */
        "pushl %eax\n"        /* cell */
        "calll R_VisitPortalsForCell_impl\n"
        "addl $24, %esp\n"
        "retl\n"
    );
}
#endif

#if 0 /* Original ASM — converted to R_VisitPortalsForCell_impl above */
static __attribute__((naked))
void R_VisitPortalsForCell_original(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren)
{
    __asm__ __volatile__ (
        ".Lff0c9e_000f0c9e:\n"
        "pushl %ebp\n" /* line 1965 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1d0c, %esp\n"
        "movl %eax, -0x1ca8(%ebp)\n"
        "movl %edx, -0x1cac(%ebp)\n"
        "movl %ecx, -0x1cb0(%ebp)\n"
        /* { scope 1: occluderIndex, edgeIndex, occluderIndex, cellList, ... */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        "movl $0, dpvsGlob+56\n" /* line 874 */
        "movl $0, dpvsGlob+64\n" /* line 875 */
        "movl 0x30(%eax), %edx\n" /* line 876 */
        "testl %edx, %edx\n"
        "jle .Lff0c9e_000f0f42\n"
        "movl $0, -0x1ca0(%ebp)\n" /* occluderIndex */
        "movl -0x1ca8(%ebp), %edx\n"
        "movl -0x1ca0(%ebp), %ecx\n" /* occluderIndex */
        ".Lff0c9e_000f0cf1:\n"
        "movl 0x34(%edx), %eax\n" /* line 878 */
        "movl (%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x1c98(%ebp)\n" /* occluder */
        "movl dpvsGlob+40, %eax\n" /* line 850 */
        "testl %eax, %eax\n"
        "je .Lff0c9e_000f0d5d\n"
        /* { scope 3: v */
        "movl -0x1c98(%ebp), %ebx\n" /* line 839 | occluder */
        "movl 0x10(%ebx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lff0c9e_000f0f21\n"
        "movl 0x14(%ebx), %edx\n" /* line 841 */
        "movss (%eax), %xmm6\n" /* line 304 */
        "movss 4(%eax), %xmm5\n"
        "movss 8(%eax), %xmm4\n"
        "movss 0xc(%eax), %xmm3\n" /* line 42 */
        "movaps %xmm5, %xmm0\n" /* line 841 */
        "mulss 4(%edx), %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "pxor %xmm7, %xmm7\n"
        "ucomiss %xmm7, %xmm0\n"
        "jbe .Lff0c9e_000f12c8\n"
        /* } scope */
        ".Lff0c9e_000f0d5d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 853 | planeCount */
        "testl %eax, %eax\n"
        "je .Lff0c9e_000f0dd1\n"
        /* { scope 3: v */
        /* { scope 4 */
        "movl -0x1c98(%ebp), %esi\n" /* line 839 | occluder, plane */
        "movl 0x10(%esi), %ebx\n" /* plane */
        "movl 8(%ebp), %ecx\n" /* planes */
        "xorl %esi, %esi\n" /* plane */
        ".Lff0c9e_000f0d72:\n"
        "testl %ebx, %ebx\n"
        "jle .Lff0c9e_000f0f21\n"
        "movl -0x1c98(%ebp), %edx\n" /* line 841 | occluder */
        "movl 0x14(%edx), %eax\n"
        "movss (%ecx), %xmm6\n" /* line 304 */
        "movss 4(%ecx), %xmm5\n"
        "movss 8(%ecx), %xmm4\n"
        "movss 0xc(%ecx), %xmm3\n" /* line 42 */
        "movaps %xmm4, %xmm0\n" /* line 841 */
        "mulss 8(%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "movaps %xmm6, %xmm2\n"
        "mulss (%eax), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "pxor %xmm7, %xmm7\n"
        "ucomiss %xmm7, %xmm0\n"
        "jbe .Lff0c9e_000f14ad\n"
        /* } scope */
        /* } scope */
        ".Lff0c9e_000f0dc6:\n"
        "addl $0x14, %ecx\n" /* line 857 */
        "addl $1, %esi\n" /* plane */
        "cmpl %esi, 0xc(%ebp)\n" /* line 853 | plane, planeCount */
        "jne .Lff0c9e_000f0d72\n"
        ".Lff0c9e_000f0dd1:\n"
        "cmpl $0x400, dpvsGlob+56\n" /* line 882 */
        "je .Lff0c9e_000f14ed\n"
        ".Lff0c9e_000f0de1:\n"
        "movl dpvsGlob+56, %edx\n" /* line 884 */
        "movl dpvsGlob+60, %eax\n"
        "movl -0x1c98(%ebp), %ecx\n" /* occluder */
        "movl %ecx, (%eax, %edx, 4)\n"
        "addl $1, dpvsGlob+56\n" /* line 885 */
        "movl $0x7fffffff, 0x18(%ecx)\n" /* line 888 */
        "movl dpvsGlob+64, %eax\n" /* line 889 */
        "movl %eax, 0x1c(%ecx)\n"
        "movl dpvsGlob+64, %eax\n" /* line 890 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl dpvsGlob+68, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 0x20(%ecx)\n"
        "movl (%ecx), %eax\n" /* line 892 */
        "testl %eax, %eax\n"
        "jle .Lff0c9e_000f104b\n"
        "xorl %edi, %edi\n" /* planeIndex */
        "xorl %esi, %esi\n" /* plane */
        "movl -0x1c98(%ebp), %ebx\n" /* occluder, i1 */
        "jmp .Lff0c9e_000f0e92\n"
        ".Lff0c9e_000f0e35:\n"
        "movl dpvsGlob+64, %eax\n" /* line 900 */
        "movl dpvsGlob+68, %ebx\n" /* i1 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl -0x1c98(%ebp), %edx\n" /* occluder */
        "movl 4(%edx), %ecx\n"
        "movl (%ecx, %esi), %edx\n"
        "movl %edx, (%eax, %ebx)\n"
        "movl 4(%ecx, %esi), %edx\n"
        "movl %edx, 4(%eax, %ebx)\n"
        "movl 8(%ecx, %esi), %edx\n"
        "movl %edx, 8(%eax, %ebx)\n"
        "movl 0xc(%ecx, %esi), %edx\n"
        "movl %edx, 0xc(%eax, %ebx)\n"
        "movl 0x10(%ecx, %esi), %edx\n"
        "movl %edx, 0x10(%eax, %ebx)\n"
        "addl $1, dpvsGlob+64\n" /* line 901 */
        ".Lff0c9e_000f0e7c:\n"
        "addl $1, %edi\n" /* line 892 | planeIndex */
        "addl $0x14, %esi\n" /* plane */
        "movl -0x1c98(%ebp), %ecx\n" /* occluder */
        "cmpl (%ecx), %edi\n" /* planeIndex */
        "jge .Lff0c9e_000f12c1\n"
        "movl %ecx, %ebx\n" /* i1 */
        ".Lff0c9e_000f0e92:\n"
        "movl 4(%ebx), %eax\n" /* line 894 | i1 */
        "movb $0, 0x13(%eax, %esi)\n"
        "movl %esi, %eax\n" /* line 895 | plane */
        "addl 4(%ebx), %eax\n" /* i1 */
        "movss (%eax), %xmm1\n"
        "mulss dpvsGlob+72, %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss dpvsGlob+76, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss dpvsGlob+80, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss dpvsGlob+84, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jbe .Lff0c9e_000f0e7c\n"
        "movb $1, 0x13(%eax)\n" /* line 897 */
        "cmpl $0x1800, dpvsGlob+64\n" /* line 898 */
        "jne .Lff0c9e_000f0e35\n"
        "movl $str_00225a10, 4(%esp)\n" /* line 899 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lff0c9e_000f0e35\n"
        ".Lff0c9e_000f0f14:\n"
        "movl %edx, %ebx\n" /* i1 */
        ".Lff0c9e_000f0f16:\n"
        "movl dpvsGlob+64, %eax\n" /* line 920 */
        "subl 0x1c(%ebx), %eax\n" /* i1 */
        "movl %eax, 0x1c(%ebx)\n" /* i1 */
        ".Lff0c9e_000f0f21:\n"
        "addl $1, -0x1ca0(%ebp)\n" /* line 876 | occluderIndex */
        "movl -0x1ca0(%ebp), %esi\n" /* occluderIndex, plane */
        "movl -0x1ca8(%ebp), %eax\n"
        "cmpl 0x30(%eax), %esi\n" /* plane */
        "jge .Lff0c9e_000f0f42\n"
        "movl %eax, %edx\n"
        "movl %esi, %ecx\n" /* plane */
        "jmp .Lff0c9e_000f0cf1\n"
        /* } scope */
        ".Lff0c9e_000f0f42:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1975 | planeCount */
        "movl 8(%ebp), %edx\n" /* planes */
        "calll R_AddVisibleSurfacesInCell\n"
        "movl -0x1cac(%ebp), %esi\n" /* line 1944 | cellCount */
        "testl %esi, %esi\n" /* cellCount */
        "je .Lff0c9e_000f0f68\n"
        "movl -0x1cac(%ebp), %eax\n"
        ".Lff0c9e_000f0f5d:\n"
        "movb $1, 1(%eax)\n" /* line 1947 */
        "movl 4(%eax), %eax\n" /* line 1948 */
        "testl %eax, %eax\n" /* line 1944 */
        "jne .Lff0c9e_000f0f5d\n"
        ".Lff0c9e_000f0f68:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1978 | clipChildren, portal */
        "testl %ebx, %ebx\n" /* portal */
        "je .Lff0c9e_000f143d\n"
        "movl -0x1ca8(%ebp), %ebx\n" /* line 1986 | portal */
        "movl 0x20(%ebx), %eax\n" /* portal */
        "testl %eax, %eax\n"
        "jle .Lff0c9e_000f101f\n"
        "xorl %edi, %edi\n" /* portalIndex */
        "movl $0, -0x1cfc(%ebp)\n"
        "movl -0x1ca8(%ebp), %esi\n" /* cellCount */
        "jmp .Lff0c9e_000f0fab\n"
        ".Lff0c9e_000f0f98:\n"
        "movl %esi, %eax\n" /* cellCount */
        ".Lff0c9e_000f0f9a:\n"
        "addl $1, %edi\n" /* portalIndex */
        "addl $0x44, -0x1cfc(%ebp)\n"
        "cmpl 0x20(%eax), %edi\n" /* portalIndex */
        "jge .Lff0c9e_000f101f\n"
        ".Lff0c9e_000f0fa9:\n"
        "movl %eax, %esi\n" /* cellCount */
        ".Lff0c9e_000f0fab:\n"
        "movl -0x1cfc(%ebp), %ebx\n" /* line 1988 | portal */
        "addl 0x24(%esi), %ebx\n" /* cellCount, portal */
        "cmpb $0, 1(%ebx)\n" /* line 1814 | i1 */
        "jne .Lff0c9e_000f0f98\n"
        "leal 8(%ebx), %eax\n" /* line 220 */
        "movss 8(%ebx), %xmm1\n" /* line 1816 | i1 */
        "mulss dpvsGlob+72, %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss dpvsGlob+76, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss dpvsGlob+80, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%eax), %xmm0\n"
        "mulss dpvsGlob+84, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "pxor %xmm7, %xmm7\n"
        "ucomiss %xmm7, %xmm1\n"
        "jbe .Lff0c9e_000f130a\n"
        ".Lff0c9e_000f100a:\n"
        "movl -0x1ca8(%ebp), %eax\n"
        "addl $1, %edi\n" /* line 1986 | portalIndex */
        "addl $0x44, -0x1cfc(%ebp)\n"
        "cmpl 0x20(%eax), %edi\n" /* portalIndex */
        "jl .Lff0c9e_000f0fa9\n"
        ".Lff0c9e_000f101f:\n"
        "movl -0x1cac(%ebp), %edx\n" /* line 1944 */
        "testl %edx, %edx\n"
        "je .Lff0c9e_000f1040\n"
        ".Lff0c9e_000f1029:\n"
        "movl -0x1cac(%ebp), %edx\n" /* line 1947 */
        "movb $0, 1(%edx)\n"
        "movl 4(%edx), %ecx\n" /* line 1948 */
        "movl %ecx, -0x1cac(%ebp)\n"
        "testl %ecx, %ecx\n" /* line 1944 */
        "jne .Lff0c9e_000f1029\n"
        /* } scope */
        ".Lff0c9e_000f1040:\n"
        "addl $0x1d0c, %esp\n" /* line 2023 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff0c9e_000f104b:\n"
        "movl -0x1c98(%ebp), %ebx\n" /* occluder, portal */
        /* { scope 1: occluderIndex, edgeIndex, occluderIndex, cellList, ... */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        ".Lff0c9e_000f1051:\n"
        "movl 8(%ebx), %eax\n" /* line 906 | i1 */
        "testl %eax, %eax\n"
        "jle .Lff0c9e_000f0f16\n"
        "movl $0, -0x1c9c(%ebp)\n" /* edgeIndex */
        "movl -0x1c9c(%ebp), %esi\n" /* edgeIndex, plane */
        "movl -0x1c98(%ebp), %eax\n" /* occluder */
        "jmp .Lff0c9e_000f1179\n"
        /* { scope 3: v */
        /* { scope 4 */
        ".Lff0c9e_000f1077:\n"
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0xc1c(%ebp)\n" /* delta */
        "leal 4(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x1c44(%ebp)\n"
        "movss 4(%eax), %xmm0\n"
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0xc18(%ebp)\n"
        "leal 8(%edi), %ebx\n" /* line 250 */
        "movss 8(%eax), %xmm0\n"
        "subss 8(%edi), %xmm0\n"
        "movss %xmm0, -0xc14(%ebp)\n"
        /* } scope */
        "movl %esi, 8(%esp)\n" /* line 238 | plane */
        "leal -0xc1c(%ebp), %ecx\n" /* delta */
        "movl %ecx, 4(%esp)\n"
        "movl $dpvsGlob+72, (%esp)\n"
        "calll Vec3Cross\n"
        ".Lff0c9e_000f10d1:\n"
        "movl %esi, (%esp)\n" /* line 241 | plane */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss (%esi), %xmm1\n" /* line 27 */
        "mulss (%edi), %xmm1\n"
        "movss 4(%esi), %xmm0\n"
        "movl -0x1c44(%ebp), %eax\n"
        "mulss (%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%esi), %xmm0\n"
        "mulss (%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esi)\n"
        /* { scope 4 */
        "movl $0xc, %eax\n" /* line 19 */
        "movl (%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "movl $0, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x10(%esi)\n"
        "movl $0x10, %eax\n" /* line 20 */
        "movl 4(%esi), %edx\n"
        "testl %edx, %edx\n"
        "movl $4, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x11(%esi)\n"
        "movl $0x14, %eax\n" /* line 21 */
        "movl 8(%esi), %edi\n"
        "testl %edi, %edi\n"
        "movl $8, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x12(%esi)\n"
        /* } scope */
        "movb $0xff, 0x13(%esi)\n" /* line 243 | plane */
        /* } scope */
        "addl $1, dpvsGlob+64\n" /* line 917 */
        ".Lff0c9e_000f1159:\n"
        "addl $1, -0x1c9c(%ebp)\n" /* line 906 | edgeIndex */
        "movl -0x1c9c(%ebp), %ecx\n" /* edgeIndex */
        "movl -0x1c98(%ebp), %edx\n" /* occluder */
        "cmpl %ecx, 8(%edx)\n"
        "jle .Lff0c9e_000f0f14\n"
        "movl %ecx, %esi\n" /* plane */
        "movl %edx, %eax\n"
        ".Lff0c9e_000f1179:\n"
        "shll $4, %esi\n" /* plane */
        "movl 0xc(%eax), %ecx\n" /* line 908 */
        "leal (%esi, %ecx), %ebx\n" /* plane, i1 */
        "movl (%ebx), %eax\n" /* i1 */
        "movl 4(%ebx), %edx\n" /* i1 */
        "movzbl 0x13(%eax), %eax\n"
        "cmpb 0x13(%edx), %al\n"
        "je .Lff0c9e_000f1159\n"
        "movl imp_r_showPortals, %eax\n" /* line 911 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edi\n" /* planeIndex */
        "testl %edi, %edi\n" /* planeIndex */
        "jne .Lff0c9e_000f1288\n"
        ".Lff0c9e_000f11a2:\n"
        "leal (%esi, %ecx), %ecx\n" /* line 914 | plane */
        "movl (%ecx), %eax\n"
        "movzbl 0x13(%eax), %ebx\n" /* i1 */
        "movl dpvsGlob+64, %eax\n" /* line 916 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl dpvsGlob+68, %edx\n"
        "leal (%edx, %eax, 4), %esi\n" /* plane */
        "cmpl $1, %ebx\n" /* i1 */
        "sbbl %eax, %eax\n"
        "andl $4, %eax\n"
        "movl 8(%ecx, %eax), %edi\n" /* planeIndex */
        "movl 8(%ecx, %ebx, 4), %eax\n"
        /* { scope 3: v */
        "pxor %xmm0, %xmm0\n" /* line 229 */
        "ucomiss dpvsGlob+84, %xmm0\n"
        "jp .Lff0c9e_000f11df\n"
        "je .Lff0c9e_000f1077\n"
        ".Lff0c9e_000f11df:\n"
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss dpvsGlob+72, %xmm0\n"
        "movss %xmm0, -0xc1c(%ebp)\n" /* delta */
        "leal 4(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x1c44(%ebp)\n"
        "movss 4(%edi), %xmm0\n"
        "subss dpvsGlob+76, %xmm0\n"
        "movss %xmm0, -0xc18(%ebp)\n"
        "leal 8(%edi), %ebx\n" /* line 250 */
        "movss 8(%edi), %xmm0\n"
        "subss dpvsGlob+80, %xmm0\n"
        "movss %xmm0, -0xc14(%ebp)\n"
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss dpvsGlob+72, %xmm0\n"
        "movss %xmm0, -0xc10(%ebp)\n"
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss dpvsGlob+76, %xmm0\n"
        "movss %xmm0, -0xc0c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss dpvsGlob+80, %xmm0\n"
        "movss %xmm0, -0xc08(%ebp)\n"
        "movl %esi, 8(%esp)\n" /* line 233 | plane */
        "leal -0xc1c(%ebp), %ecx\n" /* delta */
        "movl %ecx, 4(%esp)\n"
        "leal -0xc10(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "jmp .Lff0c9e_000f10d1\n"
        /* } scope */
        ".Lff0c9e_000f1288:\n"
        "movl imp_colorMagenta, %eax\n" /* line 912 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* i1 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebx), %eax\n" /* i1 */
        "movl %eax, 4(%esp)\n"
        "movl imp_frontEndDataOut, %eax\n"
        "movl (%eax), %eax\n"
        "addl $str_00249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugLine\n"
        "movl -0x1c98(%ebp), %edx\n" /* occluder */
        "movl 0xc(%edx), %ecx\n"
        "jmp .Lff0c9e_000f11a2\n"
        ".Lff0c9e_000f12c1:\n"
        "movl %ecx, %ebx\n" /* i1 */
        "jmp .Lff0c9e_000f1051\n"
        /* { scope 3: v */
        ".Lff0c9e_000f12c8:\n"
        "movl %edx, %eax\n" /* line 841 */
        "xorl %edx, %edx\n"
        "jmp .Lff0c9e_000f12fe\n"
        ".Lff0c9e_000f12ce:\n"
        "movaps %xmm4, %xmm0\n" /* line 42 */
        "mulss 0x14(%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 0x10(%eax), %xmm1\n"
        "movaps %xmm6, %xmm2\n"
        "mulss 0xc(%eax), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "addl $0xc, %eax\n"
        "ucomiss %xmm7, %xmm0\n" /* line 841 */
        "ja .Lff0c9e_000f0d5d\n"
        ".Lff0c9e_000f12fe:\n"
        "addl $1, %edx\n" /* line 839 */
        "cmpl %edx, %ecx\n"
        "jne .Lff0c9e_000f12ce\n"
        "jmp .Lff0c9e_000f0f21\n"
        /* } scope */
        /* } scope */
        ".Lff0c9e_000f130a:\n"
        "movl 0xc(%ebp), %esi\n" /* line 966 | planeCount, plane */
        "testl %esi, %esi\n" /* plane */
        "jne .Lff0c9e_000f1506\n"
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        ".Lff0c9e_000f1315:\n"
        "movl dpvsGlob+56, %esi\n" /* line 1658 | plane */
        "movl %esi, -0x1c80(%ebp)\n" /* plane */
        "testl %esi, %esi\n" /* plane */
        "jle .Lff0c9e_000f15bd\n"
        "movl dpvsGlob+60, %eax\n" /* line 1660 */
        "movl %eax, -0x1c7c(%ebp)\n"
        "movl $0, -0x1c78(%ebp)\n" /* occluderIndex */
        "movl -0x1c78(%ebp), %edx\n" /* occluderIndex */
        "movl %eax, %ecx\n"
        "movl (%ecx, %edx, 4), %eax\n"
        "movl 0x1c(%eax), %esi\n" /* plane */
        "movl %esi, -0x1c74(%ebp)\n" /* plane, planeCount */
        "movl 0x20(%eax), %ecx\n"
        /* { scope 3: v */
        "testl %esi, %esi\n" /* line 977 | plane */
        "je .Lff0c9e_000f100a\n"
        /* { scope 4 */
        ".Lff0c9e_000f135d:\n"
        "movl 0x20(%ebx), %eax\n" /* line 954 | i1 */
        "movl %eax, -0x1c6c(%ebp)\n" /* v */
        "movzbl 0x24(%ebx), %edx\n" /* line 955 | i1 */
        "movb %dl, -0x1c6d(%ebp)\n"
        "movzbl %dl, %eax\n"
        /* { scope 5 */
        "movl -0x1c6c(%ebp), %esi\n" /* line 304 | v, plane */
        "addl $4, %esi\n" /* plane */
        "movl %esi, -0x1c68(%ebp)\n" /* plane */
        "movl -0x1c6c(%ebp), %edx\n" /* v */
        "addl $8, %edx\n"
        "movl %edx, -0x1c64(%ebp)\n"
        "movl $0, -0x1c38(%ebp)\n"
        "subl $1, %eax\n"
        "movl %eax, -0x1cc0(%ebp)\n"
        /* } scope */
        ".Lff0c9e_000f13a4:\n"
        "cmpb $0, -0x1c6d(%ebp)\n" /* line 955 */
        "je .Lff0c9e_000f174c\n"
        /* { scope 5 */
        "movss (%ecx), %xmm5\n" /* line 304 */
        "movss 4(%ecx), %xmm4\n"
        "movss 8(%ecx), %xmm2\n"
        "movss 0xc(%ecx), %xmm3\n" /* line 42 */
        /* } scope */
        "movaps %xmm5, %xmm0\n" /* line 957 */
        "movl -0x1c6c(%ebp), %esi\n" /* v, plane */
        "mulss (%esi), %xmm0\n" /* plane */
        "movaps %xmm4, %xmm1\n"
        "movl -0x1c68(%ebp), %eax\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "movl -0x1c64(%ebp), %edx\n"
        "mulss (%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "ucomiss %xmm7, %xmm0\n"
        "jbe .Lff0c9e_000f170b\n"
        /* } scope */
        /* } scope */
        ".Lff0c9e_000f1400:\n"
        "addl $1, -0x1c78(%ebp)\n" /* line 1658 | occluderIndex */
        "movl -0x1c78(%ebp), %eax\n" /* occluderIndex */
        "cmpl %eax, -0x1c80(%ebp)\n"
        "je .Lff0c9e_000f15bd\n"
        "movl %eax, %edx\n"
        "movl -0x1c7c(%ebp), %ecx\n"
        "movl (%ecx, %edx, 4), %eax\n" /* line 1660 */
        "movl 0x1c(%eax), %esi\n" /* plane */
        "movl %esi, -0x1c74(%ebp)\n" /* plane, planeCount */
        "movl 0x20(%eax), %ecx\n"
        /* { scope 3: v */
        "testl %esi, %esi\n" /* line 977 | plane */
        "je .Lff0c9e_000f100a\n"
        "jmp .Lff0c9e_000f135d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        ".Lff0c9e_000f143d:\n"
        "movl $0, 0xc(%esp)\n" /* line 1936 */
        "leal -0x1c1c(%ebp), %eax\n" /* cellList */
        "movl %eax, 8(%esp)\n"
        "leal -0xc1c(%ebp), %eax\n" /* delta */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* planeCount */
        "movl %edx, (%esp)\n"
        "movl 8(%ebp), %ecx\n" /* planes */
        "movl -0x1cb0(%ebp), %edx\n"
        "movl -0x1ca8(%ebp), %eax\n"
        "calll R_GetFurtherCellList_r\n"
        "movl %eax, %esi\n" /* cellCount */
        "testl %eax, %eax\n" /* line 1937 */
        "jg .Lff0c9e_000f16eb\n"
        /* } scope */
        ".Lff0c9e_000f147d:\n"
        "movl -0x1cac(%ebp), %ecx\n" /* line 1944 */
        "testl %ecx, %ecx\n"
        "je .Lff0c9e_000f1040\n"
        ".Lff0c9e_000f148b:\n"
        "movl -0x1cac(%ebp), %ecx\n" /* line 1947 */
        "movb $0, 1(%ecx)\n"
        "movl 4(%ecx), %ebx\n" /* line 1948 | cellIndex */
        "movl %ebx, -0x1cac(%ebp)\n" /* cellIndex */
        "testl %ebx, %ebx\n" /* line 1944 | cellIndex */
        "jne .Lff0c9e_000f148b\n"
        /* } scope */
        "addl $0x1d0c, %esp\n" /* line 2023 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: occluderIndex, edgeIndex, occluderIndex, cellList, ... */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        /* { scope 3: v */
        /* { scope 4 */
        ".Lff0c9e_000f14ad:\n"
        "xorl %edx, %edx\n" /* line 841 */
        "jmp .Lff0c9e_000f14e1\n"
        ".Lff0c9e_000f14b1:\n"
        "movaps %xmm4, %xmm0\n" /* line 42 */
        "mulss 0x14(%eax), %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss 0xc(%eax), %xmm1\n"
        "movaps %xmm5, %xmm2\n"
        "mulss 0x10(%eax), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "addl $0xc, %eax\n"
        "ucomiss %xmm7, %xmm0\n" /* line 841 */
        "ja .Lff0c9e_000f0dc6\n"
        ".Lff0c9e_000f14e1:\n"
        "addl $1, %edx\n" /* line 839 */
        "cmpl %ebx, %edx\n"
        "jne .Lff0c9e_000f14b1\n"
        "jmp .Lff0c9e_000f0f21\n"
        /* } scope */
        /* } scope */
        ".Lff0c9e_000f14ed:\n"
        "movl $str_002259ec, 4(%esp)\n" /* line 883 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lff0c9e_000f0de1\n"
        /* } scope */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        ".Lff0c9e_000f1506:\n"
        "movl 0x20(%ebx), %ecx\n" /* line 954 | i1 */
        "movl %ecx, -0x1c8c(%ebp)\n" /* v */
        "movzbl 0x24(%ebx), %eax\n" /* line 955 | i1 */
        "movb %al, -0x1c91(%ebp)\n"
        "movzbl %al, %edx\n"
        "movl %edx, -0x1c90(%ebp)\n" /* c */
        "addl $4, %ecx\n" /* line 304 */
        "movl %ecx, -0x1c88(%ebp)\n"
        "movl -0x1c8c(%ebp), %ecx\n" /* v */
        "addl $8, %ecx\n"
        "movl %ecx, -0x1c84(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* planes */
        "movl $0, -0x1c34(%ebp)\n"
        ".Lff0c9e_000f1547:\n"
        "cmpb $0, -0x1c91(%ebp)\n" /* line 955 */
        "je .Lff0c9e_000f100a\n"
        "movss (%edx), %xmm6\n" /* line 304 */
        "movss 4(%edx), %xmm5\n"
        "movss 8(%edx), %xmm4\n"
        "movss 0xc(%edx), %xmm3\n" /* line 42 */
        "movaps %xmm4, %xmm0\n" /* line 957 */
        "movl -0x1c84(%ebp), %ecx\n" /* plane */
        "mulss (%ecx), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "movl -0x1c88(%ebp), %esi\n" /* plane */
        "mulss (%esi), %xmm1\n" /* plane */
        "movaps %xmm6, %xmm2\n"
        "movl -0x1c8c(%ebp), %eax\n" /* v */
        "mulss (%eax), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "ucomiss %xmm7, %xmm0\n"
        "jbe .Lff0c9e_000f17c4\n"
        /* } scope */
        ".Lff0c9e_000f15a3:\n"
        "addl $0x14, %edx\n" /* line 966 */
        "addl $1, -0x1c34(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* planeCount */
        "cmpl %eax, -0x1c34(%ebp)\n"
        "jne .Lff0c9e_000f1547\n"
        "jmp .Lff0c9e_000f1315\n"
        ".Lff0c9e_000f15bd:\n"
        "pxor %xmm0, %xmm0\n" /* line 1992 */
        "ucomiss dpvsGlob+84, %xmm0\n"
        "jp .Lff0c9e_000f15cc\n"
        "je .Lff0c9e_000f1622\n"
        ".Lff0c9e_000f15cc:\n"
        "leal 8(%ebx), %edx\n" /* portal */
        "movl %edx, -0x1ca4(%ebp)\n"
        "movss 8(%ebx), %xmm1\n" /* portal */
        "mulss dpvsGlob+72, %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss dpvsGlob+76, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss dpvsGlob+80, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm0\n"
        "mulss dpvsGlob+84, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss lit4_002ed880, %xmm1\n" /* -0.125f */
        "ja .Lff0c9e_000f176d\n"
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        /* { scope 3: v */
        ".Lff0c9e_000f1622:\n"
        "movzbl 0x24(%ebx), %eax\n" /* line 1837 | i1 */
        "movl %eax, -0x1c(%ebp)\n" /* vertCount */
        "movl 0x20(%ebx), %eax\n" /* line 1841 | i1 */
        "leal -0x1c1c(%ebp), %edx\n" /* cellList */
        "movl %edx, (%esp)\n"
        "movl -0x1cb0(%ebp), %ecx\n"
        "leal -0x1c(%ebp), %edx\n" /* vertCount */
        "calll R_ChopPortalWinding\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1842 | vertCount */
        "testl %edx, %edx\n"
        "je .Lff0c9e_000f100a\n"
        "movl dpvsGlob+44, %ecx\n" /* line 1847 */
        "testl %ecx, %ecx\n"
        "je .Lff0c9e_000f167e\n"
        "leal -0x1c1c(%ebp), %esi\n" /* line 1849 | cellList, plane */
        "cmpl %eax, %esi\n" /* plane */
        "je .Lff0c9e_000f1a88\n"
        "movl %esi, %edx\n" /* plane */
        ".Lff0c9e_000f1668:\n"
        "movl %edx, (%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* vertCount */
        "calll R_ChopPortalWinding\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1850 | vertCount */
        "testl %edx, %edx\n"
        "je .Lff0c9e_000f100a\n"
        ".Lff0c9e_000f167e:\n"
        "movl 0xc(%ebp), %esi\n" /* line 1855 | planeCount, plane */
        "testl %esi, %esi\n" /* plane */
        "jle .Lff0c9e_000f182b\n"
        "movl 8(%ebp), %edx\n" /* planes */
        "movl %edx, -0x1c3c(%ebp)\n"
        "movl $0, -0x1c58(%ebp)\n" /* planeIndex */
        "jmp .Lff0c9e_000f16d9\n"
        ".Lff0c9e_000f169e:\n"
        "movl %ecx, %edx\n" /* line 1857 */
        ".Lff0c9e_000f16a0:\n"
        "movl %edx, (%esp)\n"
        "movl -0x1c3c(%ebp), %ecx\n"
        "leal -0x1c(%ebp), %edx\n" /* vertCount */
        "calll R_ChopPortalWinding\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1858 | vertCount */
        "testl %ecx, %ecx\n"
        "je .Lff0c9e_000f100a\n"
        "addl $1, -0x1c58(%ebp)\n" /* line 1855 | planeIndex */
        "addl $0x14, -0x1c3c(%ebp)\n"
        "movl -0x1c58(%ebp), %esi\n" /* planeIndex, plane */
        "cmpl %esi, 0xc(%ebp)\n" /* plane, planeCount */
        "je .Lff0c9e_000f182b\n"
        ".Lff0c9e_000f16d9:\n"
        "leal -0x1c1c(%ebp), %ecx\n" /* line 1857 | cellList */
        "cmpl %ecx, %eax\n"
        "jne .Lff0c9e_000f169e\n"
        "leal -0x161c(%ebp), %edx\n"
        "jmp .Lff0c9e_000f16a0\n"
        /* } scope */
        /* } scope */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        ".Lff0c9e_000f16eb:\n"
        "xorl %ebx, %ebx\n" /* line 1937 | cellIndex */
        ".Lff0c9e_000f16ed:\n"
        "movl -0x1c1c(%ebp, %ebx, 4), %eax\n" /* line 1938 */
        "movl 0xc(%ebp), %ecx\n" /* planeCount */
        "movl 8(%ebp), %edx\n" /* planes */
        "calll R_AddVisibleSurfacesInCell\n"
        "addl $1, %ebx\n" /* line 1937 | cellIndex */
        "cmpl %ebx, %esi\n" /* cellIndex, cellCount */
        "jne .Lff0c9e_000f16ed\n"
        "jmp .Lff0c9e_000f147d\n"
        /* } scope */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        /* { scope 3: v */
        /* { scope 4 */
        ".Lff0c9e_000f170b:\n"
        "movl %esi, %edx\n" /* line 957 | plane */
        "xorl %eax, %eax\n"
        "jmp .Lff0c9e_000f1744\n"
        /* { scope 5 */
        ".Lff0c9e_000f1711:\n"
        "movaps %xmm5, %xmm0\n" /* line 42 */
        "mulss 0xc(%edx), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0x10(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 0x14(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "addl $1, %eax\n"
        "addl $0xc, %edx\n"
        /* } scope */
        "ucomiss %xmm7, %xmm0\n" /* line 957 */
        "ja .Lff0c9e_000f1400\n"
        ".Lff0c9e_000f1744:\n"
        "cmpl -0x1cc0(%ebp), %eax\n" /* line 955 */
        "jne .Lff0c9e_000f1711\n"
        /* } scope */
        ".Lff0c9e_000f174c:\n"
        "addl $0x14, %ecx\n" /* line 977 */
        "addl $1, -0x1c38(%ebp)\n"
        "movl -0x1c74(%ebp), %esi\n" /* planeCount, plane */
        "cmpl %esi, -0x1c38(%ebp)\n" /* plane */
        "jne .Lff0c9e_000f13a4\n"
        "jmp .Lff0c9e_000f100a\n"
        /* } scope */
        /* } scope */
        ".Lff0c9e_000f176d:\n"
        "movl $dpvsGlob+72, 0xc(%esp)\n" /* line 1997 */
        "movl %edx, 8(%esp)\n"
        "movzbl 0x24(%ebx), %eax\n" /* portal */
        "movl %eax, 4(%esp)\n"
        "movl 0x20(%ebx), %eax\n" /* portal */
        "movl %eax, (%esp)\n"
        "calll WindingContainsCoplanarPoint\n"
        "testl %eax, %eax\n"
        "je .Lff0c9e_000f100a\n"
        "movl $0, 4(%ebx)\n" /* line 1999 | portal */
        "movl 0x1c(%ebx), %eax\n" /* line 2000 | portal */
        "movl 0x10(%ebp), %ecx\n" /* clipChildren */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %esi\n" /* planeCount, cellCount */
        "movl %esi, 4(%esp)\n" /* cellCount */
        "movl 8(%ebp), %edx\n" /* planes */
        "movl %edx, (%esp)\n"
        "movl -0x1ca4(%ebp), %ecx\n"
        "movl %ebx, %edx\n" /* portal */
        "calll R_VisitPortalsForCell\n"
        "jmp .Lff0c9e_000f100a\n"
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        ".Lff0c9e_000f17c4:\n"
        "movl $0, -0x1cd0(%ebp)\n" /* line 957 */
        "movl -0x1c90(%ebp), %ecx\n" /* c, plane */
        "subl $1, %ecx\n" /* plane */
        "movl %ecx, -0x1cb4(%ebp)\n" /* plane */
        "movl %ecx, %esi\n" /* plane */
        "jmp .Lff0c9e_000f17e7\n"
        ".Lff0c9e_000f17e1:\n"
        "movl -0x1cb4(%ebp), %esi\n" /* plane */
        ".Lff0c9e_000f17e7:\n"
        "cmpl %esi, -0x1cd0(%ebp)\n" /* line 955 | plane */
        "je .Lff0c9e_000f100a\n"
        "movaps %xmm5, %xmm0\n" /* line 42 */
        "mulss 0x10(%eax), %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss 0xc(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0x14(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "addl $1, -0x1cd0(%ebp)\n"
        "addl $0xc, %eax\n"
        "ucomiss %xmm7, %xmm0\n" /* line 957 */
        "jbe .Lff0c9e_000f17e1\n"
        "jmp .Lff0c9e_000f15a3\n"
        /* } scope */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        /* { scope 3: v */
        ".Lff0c9e_000f182b:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1864 | vertCount */
        "movl %edx, -0x1c60(%ebp)\n" /* vertCount */
        /* } scope */
        "testl %edx, %edx\n" /* line 1876 */
        "je .Lff0c9e_000f100a\n"
        "movl -0x1c60(%ebp), %ecx\n" /* line 1880 | vertCount */
        "testl %ecx, %ecx\n"
        "jle .Lff0c9e_000f194b\n"
        "movl %eax, -0x1c40(%ebp)\n"
        "movl $0, -0x1c5c(%ebp)\n" /* vertIndex */
        "leal 0x2c(%ebx), %edx\n" /* i1 */
        "movl %edx, -0x1cb8(%ebp)\n"
        "leal 0x38(%ebx), %ecx\n" /* i1 */
        "movl %ecx, -0x1cbc(%ebp)\n"
        "jmp .Lff0c9e_000f1915\n"
        /* { scope 3: v */
        ".Lff0c9e_000f1871:\n"
        "cmpb $0x40, 0x25(%ebx)\n" /* line 1794 | i1 */
        "je .Lff0c9e_000f1a93\n"
        ".Lff0c9e_000f187b:\n"
        "movzbl 0x25(%ebx), %eax\n" /* line 1806 | i1 */
        "movl -0x1c40(%ebp), %esi\n" /* plane */
        "movss (%esi), %xmm1\n" /* plane */
        "mulss 0x2c(%ebx), %xmm1\n" /* i1 */
        "movss 4(%esi), %xmm0\n" /* plane */
        "movl -0x1cb8(%ebp), %ecx\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%esi), %xmm0\n" /* plane */
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%edx, %eax, 8)\n"
        "movzbl 0x25(%ebx), %eax\n" /* line 1807 | i1 */
        "movl 0x28(%ebx), %edx\n" /* i1 */
        "movss (%esi), %xmm1\n" /* plane */
        "mulss 0x38(%ebx), %xmm1\n" /* i1 */
        "movss 4(%esi), %xmm0\n" /* plane */
        "movl -0x1cbc(%ebp), %esi\n" /* plane */
        "mulss 4(%esi), %xmm0\n" /* plane */
        "addss %xmm0, %xmm1\n"
        "movl -0x1c40(%ebp), %ecx\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 8(%esi), %xmm0\n" /* plane */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%edx, %eax, 8)\n"
        "addb $1, 0x25(%ebx)\n" /* line 1808 | i1 */
        /* } scope */
        "addl $1, -0x1c5c(%ebp)\n" /* line 1880 | vertIndex */
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x1c40(%ebp)\n"
        "movl -0x1c60(%ebp), %esi\n" /* vertCount, plane */
        "cmpl %esi, -0x1c5c(%ebp)\n" /* plane, vertIndex */
        "je .Lff0c9e_000f194b\n"
        /* { scope 3: v */
        ".Lff0c9e_000f1915:\n"
        "movl 0x28(%ebx), %edx\n" /* line 1789 | i1 */
        "testl %edx, %edx\n"
        "jne .Lff0c9e_000f1871\n"
        "movl dpvsGlob+96, %ecx\n" /* line 1768 */
        "movl %ecx, -0x1c50(%ebp)\n"
        "movl %ecx, %eax\n"
        "testl %ecx, %ecx\n" /* line 1769 */
        "je .Lff0c9e_000f1cf4\n"
        "movl %ecx, %edx\n"
        ".Lff0c9e_000f1938:\n"
        "movl (%eax), %eax\n" /* line 1772 */
        "movl %eax, dpvsGlob+96\n"
        "movl %edx, 0x28(%ebx)\n" /* line 1791 | i1 */
        "movb $0, 0x25(%ebx)\n" /* line 1792 | i1 */
        "jmp .Lff0c9e_000f187b\n"
        /* } scope */
        /* } scope */
        ".Lff0c9e_000f194b:\n"
        "cmpb $0, (%ebx)\n" /* line 2011 | portal */
        "jne .Lff0c9e_000f1be7\n"
        "movl -0x1cac(%ebp), %eax\n" /* line 2013 */
        "movl %eax, 4(%ebx)\n" /* portal */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        "cmpl $0xff, dpvsGlob+88\n" /* line 1707 */
        "jg .Lff0c9e_000f1ca1\n"
        ".Lff0c9e_000f196d:\n"
        "movb $1, (%ebx)\n" /* line 1710 | i1 */
        "movzbl 0x24(%ebx), %edx\n" /* line 1711 | i1 */
        "movl %edx, -0x1c4c(%ebp)\n" /* pointCount */
        "movl 0x20(%ebx), %ecx\n" /* i1, points */
        /* { scope 3: v */
        /* { scope 4 */
        "movss dpvsGlob, %xmm6\n" /* line 304 */
        "movss dpvsGlob+4, %xmm5\n"
        "movss dpvsGlob+8, %xmm4\n"
        "movss dpvsGlob+12, %xmm7\n" /* line 42 */
        "movaps %xmm6, %xmm3\n"
        "mulss (%ecx), %xmm3\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "addss %xmm7, %xmm3\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 494 */
        "leal (%ecx, %eax, 4), %eax\n"
        "leal -0xc(%eax), %edx\n"
        "movaps %xmm6, %xmm2\n" /* line 42 */
        "mulss -0xc(%eax), %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss %xmm7, %xmm2\n"
        "ucomiss %xmm2, %xmm3\n" /* line 495 */
        "jbe .Lff0c9e_000f1c08\n"
        "movl -0x1c4c(%ebp), %eax\n" /* line 498 | pointCount */
        "subl $1, %eax\n"
        "movl %eax, -0x1c48(%ebp)\n"
        "subl $1, %eax\n"
        "jle .Lff0c9e_000f1af4\n"
        "leal 0xc(%ecx), %eax\n" /* line 503 */
        "movaps %xmm4, %xmm2\n" /* line 42 */
        "mulss 8(%eax), %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss 0xc(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss %xmm7, %xmm2\n"
        "ucomiss %xmm2, %xmm3\n" /* line 504 */
        "ja .Lff0c9e_000f1af4\n"
        "movl %ecx, %eax\n" /* line 505 */
        "movaps %xmm2, %xmm3\n"
        "movl $1, %edx\n"
        ".Lff0c9e_000f1a48:\n"
        "addl $1, %edx\n" /* line 498 */
        "cmpl -0x1c48(%ebp), %edx\n"
        "je .Lff0c9e_000f1af4\n"
        "movaps %xmm4, %xmm2\n" /* line 42 */
        "mulss 0x20(%eax), %xmm2\n"
        "movaps %xmm6, %xmm0\n"
        "mulss 0x18(%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 0x1c(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss %xmm7, %xmm2\n"
        "addl $0xc, %eax\n"
        "ucomiss %xmm2, %xmm3\n" /* line 504 */
        "ja .Lff0c9e_000f1af4\n"
        "movaps %xmm2, %xmm3\n" /* line 505 */
        "jmp .Lff0c9e_000f1a48\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        /* { scope 3: v */
        ".Lff0c9e_000f1a88:\n"
        "leal -0x161c(%ebp), %edx\n" /* line 1849 */
        "jmp .Lff0c9e_000f1668\n"
        /* } scope */
        /* { scope 3: v */
        ".Lff0c9e_000f1a93:\n"
        "leal -0xc1c(%ebp), %esi\n" /* line 1797 | delta, plane */
        "movl %esi, 8(%esp)\n" /* plane */
        "movl $0x40, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Com_ConvexHull\n"
        "movl %eax, -0x1c54(%ebp)\n" /* hullPointCount */
        "cmpl $0x40, %eax\n" /* line 1799 */
        "je .Lff0c9e_000f1cc2\n"
        ".Lff0c9e_000f1abc:\n"
        "movzbl -0x1c54(%ebp), %eax\n" /* line 1802 | hullPointCount */
        "movb %al, 0x25(%ebx)\n" /* i1 */
        "movl 0x28(%ebx), %edx\n" /* line 1803 | i1 */
        "movzbl -0x1c54(%ebp), %eax\n" /* hullPointCount */
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0xc1c(%ebp), %ecx\n" /* delta */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x28(%ebx), %edx\n" /* i1 */
        "jmp .Lff0c9e_000f187b\n"
        /* } scope */
        /* } scope */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        /* { scope 3: v */
        /* { scope 4 */
        ".Lff0c9e_000f1af1:\n"
        "movaps %xmm2, %xmm3\n" /* line 512 */
        /* } scope */
        /* } scope */
        ".Lff0c9e_000f1af4:\n"
        "movl dpvsGlob+88, %ecx\n" /* line 1713 */
        "movl %ecx, -0x1c30(%ebp)\n"
        /* { scope 3: v */
        "movl %ecx, %eax\n" /* line 1671 */
        "subl $1, %eax\n"
        /* } scope */
        "sarl $1, %eax\n" /* line 1717 */
        "movl %eax, -0x1ccc(%ebp)\n" /* heapIndex */
        "js .Lff0c9e_000f1ce3\n"
        "movl dpvsGlob+92, %edx\n"
        "movl %edx, -0x1cd0(%ebp)\n"
        "movl -0x1ccc(%ebp), %ecx\n" /* heapIndex */
        "leal (%edx, %ecx, 8), %ecx\n"
        "movl %ecx, -0x1cec(%ebp)\n"
        "ucomiss 4(%ecx), %xmm3\n"
        "jae .Lff0c9e_000f1bb8\n"
        "movl -0x1c30(%ebp), %esi\n" /* plane */
        "movl %esi, -0x1c2c(%ebp)\n" /* plane */
        "movl -0x1ccc(%ebp), %eax\n" /* heapIndex */
        "movl %eax, -0x1c30(%ebp)\n"
        "movl %esi, %ecx\n" /* plane */
        "jmp .Lff0c9e_000f1b6e\n"
        ".Lff0c9e_000f1b54:\n"
        "movl -0x1c30(%ebp), %edx\n"
        "movl %edx, -0x1c2c(%ebp)\n"
        "movl -0x1ccc(%ebp), %ecx\n" /* heapIndex */
        "movl %ecx, -0x1c30(%ebp)\n"
        "movl %edx, %ecx\n"
        ".Lff0c9e_000f1b6e:\n"
        "movl -0x1cec(%ebp), %edx\n" /* line 1719 */
        "movl (%edx), %eax\n"
        "movl 4(%edx), %edx\n"
        "movl -0x1cd0(%ebp), %esi\n" /* plane */
        "movl %eax, (%esi, %ecx, 8)\n" /* plane */
        "movl %edx, 4(%esi, %ecx, 8)\n" /* plane */
        /* { scope 3: v */
        "movl -0x1c30(%ebp), %eax\n" /* line 1671 */
        "subl $1, %eax\n"
        /* } scope */
        "sarl $1, %eax\n" /* line 1717 */
        "movl %eax, -0x1ccc(%ebp)\n" /* heapIndex */
        "js .Lff0c9e_000f1d20\n"
        "movl dpvsGlob+92, %esi\n" /* plane */
        "movl %esi, -0x1cd0(%ebp)\n" /* plane */
        "leal (%esi, %eax, 8), %eax\n" /* plane */
        "movl %eax, -0x1cec(%ebp)\n"
        "ucomiss 4(%eax), %xmm3\n"
        "jb .Lff0c9e_000f1b54\n"
        ".Lff0c9e_000f1bb8:\n"
        "movl -0x1c30(%ebp), %edx\n" /* line 1723 */
        "shll $3, %edx\n"
        "movl -0x1cd0(%ebp), %ecx\n"
        "movl %ebx, (%ecx, %edx)\n" /* i1 */
        "movl dpvsGlob+92, %eax\n" /* line 1724 */
        "movss %xmm3, 4(%edx, %eax)\n"
        "addl $1, dpvsGlob+88\n" /* line 1725 */
        "movl -0x1ca8(%ebp), %eax\n"
        "jmp .Lff0c9e_000f0f9a\n"
        /* } scope */
        ".Lff0c9e_000f1be7:\n"
        "movl -0x1cac(%ebp), %esi\n" /* line 2018 | cellCount */
        "cmpl 4(%ebx), %esi\n" /* portal, cellCount */
        "je .Lff0c9e_000f100a\n"
        "movl $0, 4(%ebx)\n" /* line 2019 | portal */
        "movl -0x1ca8(%ebp), %eax\n"
        "jmp .Lff0c9e_000f0f9a\n"
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        /* { scope 3: v */
        /* { scope 4 */
        ".Lff0c9e_000f1c08:\n"
        "movl -0x1c4c(%ebp), %eax\n" /* line 512 | pointCount */
        "subl $2, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lff0c9e_000f1af1\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 517 */
        "leal (%ecx, %eax, 4), %eax\n"
        "movaps %xmm4, %xmm3\n" /* line 42 */
        "mulss 8(%eax), %xmm3\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "addss %xmm7, %xmm3\n"
        "ucomiss %xmm3, %xmm2\n" /* line 518 */
        "ja .Lff0c9e_000f1af1\n"
        "xorl %edx, %edx\n" /* line 1965 */
        "movl -0x1c4c(%ebp), %esi\n" /* pointCount, cellCount */
        "subl $3, %esi\n" /* cellCount */
        "movl %esi, -0x1cd0(%ebp)\n" /* cellCount */
        "jmp .Lff0c9e_000f1c61\n"
        ".Lff0c9e_000f1c5e:\n"
        "movaps %xmm1, %xmm3\n" /* line 519 */
        ".Lff0c9e_000f1c61:\n"
        "cmpl -0x1cd0(%ebp), %edx\n" /* line 512 */
        "je .Lff0c9e_000f1af4\n"
        "movaps %xmm6, %xmm1\n" /* line 42 */
        "mulss -0xc(%eax), %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "mulss -8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss -4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss %xmm7, %xmm1\n"
        "addl $1, %edx\n"
        "subl $0xc, %eax\n"
        "ucomiss %xmm1, %xmm3\n" /* line 518 */
        "jbe .Lff0c9e_000f1c5e\n"
        "jmp .Lff0c9e_000f1af4\n"
        /* } scope */
        /* } scope */
        ".Lff0c9e_000f1ca1:\n"
        "movl $0x100, 8(%esp)\n" /* line 1708 */
        "movl $str_00225a84, 4(%esp)\n" /* "More than %i queued portals" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lff0c9e_000f196d\n"
        /* } scope */
        /* { scope 2: occluder, delta, planeCount, planeIndex, ... */
        /* { scope 3: v */
        ".Lff0c9e_000f1cc2:\n"
        "movl $0x40, 8(%esp)\n" /* line 1800 */
        "movl $str_00225a4c, 4(%esp)\n" /* "More than %i points on a clipped portal's convex hull
" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lff0c9e_000f1abc\n"
        ".Lff0c9e_000f1ce3:\n"
        "movl dpvsGlob+92, %edx\n"
        "movl %edx, -0x1cd0(%ebp)\n"
        "jmp .Lff0c9e_000f1bb8\n"
        ".Lff0c9e_000f1cf4:\n"
        "movl $0x100, 8(%esp)\n" /* line 1770 */
        "movl $str_00225a30, 4(%esp)\n" /* "more than %i queued portals" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "movl dpvsGlob+96, %eax\n"
        "movl -0x1c50(%ebp), %edx\n"
        "jmp .Lff0c9e_000f1938\n"
        ".Lff0c9e_000f1d20:\n"
        "movl dpvsGlob+92, %eax\n"
        "movl %eax, -0x1cd0(%ebp)\n"
        "jmp .Lff0c9e_000f1bb8\n"
    );
}
#endif /* Original ASM */

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
    *(void **)(poolBuf + 0x1FE00) = 0;

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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static void R_VisitPortals(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount)
{
    R_VisitPortals_impl(cell, parentPlane, planes, planeCount);
}
#else
/* x86 trampoline: all args on stack (cdecl), tail-call to _impl */
static __attribute__((naked))
void R_VisitPortals(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount)
{
    __asm__ __volatile__ (
        "jmp R_VisitPortals_impl\n"
    );
}
#endif

#if 0 /* Original ASM — converted to R_VisitPortals_impl above */
static __attribute__((naked))
void R_VisitPortals_original(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2026 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x190c, %esp\n"
        /* { scope 1: normals, windingVertIndex, useNormalPlanes */
        "movl $0x20000, 4(%esp)\n" /* line 2040 */
        "leal -0x1c(%ebp), %eax\n" /* hullPointsPool_large_local, hullPointsPool */
        "movl %eax, (%esp)\n" /* hullPointsPool */
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* hullPointsPool_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "xorl %ebx, %ebx\n" /* bevelVertIndex */
        "leal -0x200(%eax), %ecx\n"
        "movl %eax, %edx\n" /* hullPointsPool */
        ".Lff1d30_000f1d64:\n"
        "addl $0x40, %ebx\n" /* line 2026 | bevelVertIndex */
        "addl $0x200, %edx\n"
        "addl $0x200, %ecx\n"
        "movl %edx, (%ecx)\n" /* line 2045 */
        "cmpl $0x3fc0, %ebx\n" /* line 2044 | 255 entries * 0x40 step — was Mac symbol MacBuilder_SetControlFontStyle */
        "jne .Lff1d30_000f1d64\n"
        "movl $0, 0x1fe00(%eax)\n" /* line 2046 */
        "movl %eax, dpvsGlob+96\n" /* line 2047 */
        "leal -0x18ac(%ebp), %ebx\n" /* line 2048 | portalQueue, bevelVertIndex */
        "movl %ebx, dpvsGlob+92\n" /* bevelVertIndex */
        "movl $0, dpvsGlob+88\n" /* line 2049 */
        "movl $1, 8(%esp)\n" /* line 2051 */
        "movl 0x14(%ebp), %eax\n" /* planeCount */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* planes */
        "movl %eax, (%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* parentPlane */
        "xorl %edx, %edx\n"
        "movl 8(%ebp), %eax\n" /* cell */
        "calll R_VisitPortalsForCell\n"
        "movl $0, -0x18e8(%ebp)\n" /* iteration */
        ".Lff1d30_000f1dce:\n"
        "movl dpvsGlob+88, %ebx\n" /* line 2053 | bevelVertIndex */
        "testl %ebx, %ebx\n" /* bevelVertIndex */
        "je .Lff1d30_000f235d\n"
        ".Lff1d30_000f1ddc:\n"
        "movl dpvsGlob+92, %eax\n" /* line 1739 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x18f0(%ebp)\n" /* portal */
        "movb $0, (%eax)\n" /* line 1740 */
        "movl dpvsGlob+88, %eax\n" /* line 1742 */
        "subl $1, %eax\n"
        "movl %eax, dpvsGlob+88\n"
        "testl %eax, %eax\n" /* line 1747 */
        "jg .Lff1d30_000f2373\n"
        "leal (, %eax, 8), %edx\n"
        "xorl %esi, %esi\n" /* windingVertIndex */
        "movl dpvsGlob+92, %ebx\n" /* bevelVertIndex */
        ".Lff1d30_000f1e10:\n"
        "movl (%ebx, %edx), %eax\n" /* line 1756 | bevelVertIndex */
        "movl 4(%ebx, %edx), %edx\n" /* bevelVertIndex */
        "movl %eax, (%ebx, %esi)\n" /* bevelVertIndex */
        "movl %edx, 4(%ebx, %esi)\n" /* bevelVertIndex */
        "leal -0x38c(%ebp), %eax\n" /* line 2061 | hull */
        "movl %eax, 8(%esp)\n"
        "movl -0x18f0(%ebp), %edx\n" /* portal */
        "movzbl 0x25(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_ConvexHull\n"
        "movl %eax, %edi\n" /* hullPointCount */
        "movl -0x18f0(%ebp), %ecx\n" /* line 2063 | portal */
        "movl 0x28(%ecx), %edx\n" /* hullPoints */
        /* { scope 2: screenSpaceWinding, forceBevels */
        "movl dpvsGlob+96, %eax\n" /* line 1779 */
        "movl %eax, (%edx)\n"
        "movl %edx, dpvsGlob+96\n" /* line 1780 */
        /* } scope */
        "movl $0, 0x28(%ecx)\n" /* line 2064 */
        "testl %edi, %edi\n" /* line 2065 | hullPointCount */
        "je .Lff1d30_000f1dce\n"
        "addl $1, -0x18e8(%ebp)\n" /* line 2068 | iteration */
        "movl imp_r_portalWalkLimit, %eax\n" /* line 2069 */
        "movl (%eax), %eax\n"
        "movl -0x18e8(%ebp), %ebx\n" /* iteration, bevelVertIndex */
        "cmpl 8(%eax), %ebx\n" /* bevelVertIndex */
        "je .Lff1d30_000f2b21\n"
        "movl -0x18f0(%ebp), %ecx\n" /* line 2083 | portal */
        "movss 0x14(%ecx), %xmm0\n" /* scale */
        "xorps sse_float_sign_mask, %xmm0\n" /* scale — was color+16, fix #143 */
        "addl $8, %ecx\n"
        "movl %ecx, -0x18f4(%ebp)\n"
        /* { scope 2: screenSpaceWinding, forceBevels */
        "movaps %xmm0, %xmm4\n" /* line 272 */
        "movl -0x18f0(%ebp), %ebx\n" /* portal */
        "mulss 8(%ebx), %xmm4\n"
        "movaps %xmm0, %xmm3\n" /* line 273 */
        "mulss 4(%ecx), %xmm3\n"
        "movaps %xmm0, %xmm2\n" /* line 274 */
        "mulss 8(%ecx), %xmm2\n"
        /* } scope */
        "testl %edi, %edi\n" /* line 2084 | hullPointCount */
        "jle .Lff1d30_000f1f6b\n"
        "xorl %ecx, %ecx\n"
        "leal 0x2c(%ebx), %esi\n" /* bevelVertIndex, windingVertIndex */
        "leal 0x38(%ebx), %eax\n" /* bevelVertIndex */
        "movl %eax, -0x18fc(%ebp)\n"
        "xorl %edx, %edx\n"
        "leal -0x68c(%ebp), %eax\n" /* portalVerts */
        ".Lff1d30_000f1edc:\n"
        "movss -0x38c(%edx, %ebp), %xmm1\n" /* line 2086 | scale */
        /* { scope 2: screenSpaceWinding, forceBevels */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "movl -0x18f0(%ebp), %ebx\n" /* portal */
        "mulss 0x2c(%ebx), %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%esi), %xmm1\n" /* line 290 */
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "movss -0x388(%edx, %ebp), %xmm1\n" /* line 2087 | scale */
        /* { scope 2: screenSpaceWinding, forceBevels */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x38(%ebx), %xmm0\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "movl -0x18fc(%ebp), %ebx\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%ebx), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 2084 */
        "addl $0xc, %eax\n"
        "addl $8, %edx\n"
        "cmpl %ecx, %edi\n" /* hullPointCount */
        "jne .Lff1d30_000f1edc\n"
        ".Lff1d30_000f1f6b:\n"
        "movl imp_r_showPortals, %eax\n" /* line 2091 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %esi\n" /* windingVertIndex */
        "testl %esi, %esi\n" /* windingVertIndex */
        "je .Lff1d30_000f1f8a\n"
        "movl imp_r_portalBevelsOnly, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lff1d30_000f2a76\n"
        /* { scope 2: screenSpaceWinding, forceBevels */
        ".Lff1d30_000f1f8a:\n"
        "cmpl $0xa, %edi\n" /* line 785 */
        "setle -0x18d1(%ebp)\n" /* useNormalPlanes */
        "cmpb $0, -0x18d1(%ebp)\n" /* line 786 | useNormalPlanes */
        "je .Lff1d30_000f1fae\n"
        "movl imp_r_portalBevelsOnly, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lff1d30_000f28f1\n"
        ".Lff1d30_000f1fae:\n"
        "movb $1, -0x18d9(%ebp)\n"
        "movl $1, -0x18d0(%ebp)\n" /* forceBevels */
        ".Lff1d30_000f1fbf:\n"
        "leal -0x10ac(%ebp), %ecx\n" /* line 789 | normals */
        "movl %edi, %edx\n"
        "leal -0x68c(%ebp), %eax\n" /* portalVerts */
        "calll R_GetSidePlaneNormals\n"
        "cmpb $0, -0x18d9(%ebp)\n" /* line 791 */
        "jne .Lff1d30_000f1ff4\n"
        "movl imp_r_portalMinClipArea, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lff1d30_000f2af2\n"
        /* { scope 3: bevelVerts, bevelNormals */
        ".Lff1d30_000f1ff4:\n"
        "testl %edi, %edi\n" /* line 664 */
        "jg .Lff1d30_000f26de\n"
        "movl $0x3f800000, -0x18c8(%ebp)\n"
        "movl $0x3f800000, -0x18cc(%ebp)\n"
        "movss lit4_002ed5dc, %xmm6\n" /* -1.0f */
        "movaps %xmm6, %xmm7\n"
        "movss lit4_002ed628, %xmm0\n" /* -2.0f */
        "movaps %xmm0, %xmm1\n"
        ".Lff1d30_000f2026:\n"
        "mulss %xmm0, %xmm1\n" /* line 692 */
        "mulss lit4_002ed604, %xmm1\n" /* 0.25f */
        "movl imp_r_portalMinClipArea, %ebx\n"
        "movl (%ebx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lff1d30_000f2851\n"
        "movl $0, -0x18e4(%ebp)\n" /* clipChildren */
        /* } scope */
        ".Lff1d30_000f2052:\n"
        "cmpb $0, -0x18d9(%ebp)\n" /* line 794 */
        "jne .Lff1d30_000f2430\n"
        "movl $0, -0x18ec(%ebp)\n" /* childPlaneCount */
        ".Lff1d30_000f2069:\n"
        "cmpb $0, -0x18d1(%ebp)\n" /* line 803 | useNormalPlanes */
        "je .Lff1d30_000f217f\n"
        "testl %edi, %edi\n" /* line 805 */
        "jle .Lff1d30_000f217f\n"
        "movl $0, -0x18d8(%ebp)\n" /* line 803 | windingVertIndex */
        "leal -0x68c(%ebp), %esi\n" /* portalVerts, windingVertIndex */
        "pxor %xmm4, %xmm4\n"
        "movss lit4_002ed658, %xmm5\n" /* 0.0010000000474974513f */
        "leal -0x10ac(%ebp), %ecx\n" /* normals */
        "movl -0x18ec(%ebp), %ebx\n" /* childPlaneCount, bevelVertIndex */
        "leal (%ebx, %ebx, 4), %eax\n" /* bevelVertIndex */
        "leal -0x18c(%ebp, %eax, 4), %ebx\n" /* bevelVertIndex */
        ".Lff1d30_000f20b0:\n"
        "movss (%ecx), %xmm3\n" /* line 316 */
        "movss 4(%ecx), %xmm0\n"
        "movss 8(%ecx), %xmm2\n"
        "movaps %xmm3, %xmm1\n" /* line 807 */
        "mulss %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "ucomiss %xmm4, %xmm1\n"
        "jp .Lff1d30_000f20e0\n"
        "je .Lff1d30_000f2166\n"
        ".Lff1d30_000f20e0:\n"
        "movss %xmm3, (%ebx)\n" /* line 199 */
        "movss 4(%ecx), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%ebx)\n"
        "movss 8(%ecx), %xmm1\n" /* line 201 */
        "movss %xmm1, 8(%ebx)\n"
        "mulss (%esi), %xmm3\n" /* line 27 */
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss 8(%esi), %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "movaps %xmm5, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n"
        "movl $0xc, %eax\n" /* line 19 */
        "movl (%ebx), %edx\n"
        "testl %edx, %edx\n"
        "movl $0, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x10(%ebx)\n"
        "movl $0x10, %eax\n" /* line 20 */
        "movl 4(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "movl $4, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x11(%ebx)\n"
        "movl $0x14, %eax\n" /* line 21 */
        "movl 8(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "movl $8, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x12(%ebx)\n"
        "movb $0xff, 0x13(%ebx)\n" /* line 811 | bevelVertIndex */
        "addl $1, -0x18ec(%ebp)\n" /* line 812 | childPlaneCount */
        "addl $0x14, %ebx\n" /* bevelVertIndex */
        ".Lff1d30_000f2166:\n"
        "addl $1, -0x18d8(%ebp)\n" /* line 805 | windingVertIndex */
        "addl $0xc, %ecx\n"
        "addl $0xc, %esi\n" /* windingVertIndex */
        "cmpl -0x18d8(%ebp), %edi\n" /* windingVertIndex */
        "jne .Lff1d30_000f20b0\n"
        ".Lff1d30_000f217f:\n"
        "movl dpvsGlob+40, %edx\n" /* line 816 */
        "testl %edx, %edx\n"
        "je .Lff1d30_000f22cc\n"
        "movl -0x18ec(%ebp), %ecx\n" /* line 818 | childPlaneCount */
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal -0x18c(%ebp, %eax, 4), %esi\n" /* windingVertIndex */
        "movl (%edx), %eax\n"
        "movl %eax, (%esi)\n" /* windingVertIndex */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%esi)\n" /* windingVertIndex */
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%esi)\n" /* windingVertIndex */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* windingVertIndex */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* windingVertIndex */
        /* { scope 3: bevelVerts, bevelNormals */
        "movss (%esi), %xmm7\n" /* line 304 */
        "movss 4(%esi), %xmm6\n"
        "movss 8(%esi), %xmm5\n"
        "movss 0xc(%esi), %xmm4\n" /* line 42 */
        "movaps %xmm7, %xmm3\n"
        "mulss -0x68c(%ebp), %xmm3\n" /* portalVerts */
        "movaps %xmm6, %xmm0\n"
        "mulss -0x688(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm5, %xmm0\n"
        "mulss -0x684(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "addss %xmm4, %xmm3\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 540 */
        "leal -0x68c(%ebp, %eax, 4), %eax\n"
        "leal -0xc(%eax), %edx\n"
        "movaps %xmm7, %xmm2\n" /* line 42 */
        "mulss -0xc(%eax), %xmm2\n"
        "movaps %xmm6, %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss %xmm4, %xmm2\n"
        "ucomiss %xmm3, %xmm2\n" /* line 541 */
        "jbe .Lff1d30_000f27ae\n"
        "leal -1(%edi), %edx\n" /* line 544 */
        "cmpl $1, %edx\n"
        "jle .Lff1d30_000f22b3\n"
        "movaps %xmm6, %xmm1\n" /* line 42 */
        "mulss -0x67c(%ebp), %xmm1\n"
        "movaps %xmm7, %xmm0\n"
        "mulss -0x680(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "mulss -0x678(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss %xmm4, %xmm1\n"
        "ucomiss %xmm3, %xmm1\n" /* line 550 */
        "ja .Lff1d30_000f22b3\n"
        "movaps %xmm1, %xmm3\n" /* line 551 */
        "movl $1, %ecx\n"
        "leal -0x68c(%ebp), %eax\n" /* portalVerts */
        "jmp .Lff1d30_000f2280\n"
        ".Lff1d30_000f227d:\n"
        "movaps %xmm2, %xmm3\n"
        ".Lff1d30_000f2280:\n"
        "addl $1, %ecx\n" /* line 544 */
        "cmpl %edx, %ecx\n"
        "je .Lff1d30_000f22b3\n"
        "movaps %xmm5, %xmm2\n" /* line 42 */
        "mulss 0x20(%eax), %xmm2\n"
        "movaps %xmm6, %xmm0\n"
        "mulss 0x1c(%eax), %xmm0\n"
        "movaps %xmm7, %xmm1\n"
        "mulss 0x18(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss %xmm4, %xmm2\n"
        "addl $0xc, %eax\n"
        "ucomiss %xmm3, %xmm2\n" /* line 550 */
        "jbe .Lff1d30_000f227d\n"
        /* } scope */
        ".Lff1d30_000f22b3:\n"
        "ucomiss lit4_002ed5e8, %xmm3\n" /* line 820 | 0.0f */
        "jbe .Lff1d30_000f22c5\n"
        "subss %xmm3, %xmm4\n" /* line 821 */
        "movss %xmm4, 0xc(%esi)\n" /* windingVertIndex */
        ".Lff1d30_000f22c5:\n"
        "addl $1, -0x18ec(%ebp)\n" /* line 822 | childPlaneCount */
        ".Lff1d30_000f22cc:\n"
        "movl dpvsGlob+44, %ecx\n" /* line 824 */
        "testl %ecx, %ecx\n"
        "je .Lff1d30_000f2a6b\n"
        "movl -0x18ec(%ebp), %ebx\n" /* line 826 | childPlaneCount, bevelVertIndex */
        "leal (%ebx, %ebx, 4), %eax\n" /* bevelVertIndex */
        "shll $2, %eax\n"
        "movl (%ecx), %edx\n"
        "movl %edx, -0x18c(%eax, %ebp)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, -0x188(%eax, %ebp)\n"
        "movl 8(%ecx), %edx\n"
        "movl %edx, -0x184(%eax, %ebp)\n"
        "movl 0xc(%ecx), %edx\n"
        "movl %edx, -0x180(%eax, %ebp)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, -0x17c(%eax, %ebp)\n"
        "addl $1, %ebx\n" /* line 827 | bevelVertIndex */
        "movl %ebx, -0x18ec(%ebp)\n" /* bevelVertIndex, childPlaneCount */
        "movl %ebx, %ecx\n" /* bevelVertIndex */
        /* } scope */
        ".Lff1d30_000f2322:\n"
        "movl -0x18f0(%ebp), %edi\n" /* line 2098 | portal, hullPointCount */
        "movl 0x1c(%edi), %eax\n" /* hullPointCount */
        "movl -0x18e4(%ebp), %edx\n" /* clipChildren */
        "movl %edx, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x18c(%ebp), %ebx\n" /* childPlanes, bevelVertIndex */
        "movl %ebx, (%esp)\n" /* bevelVertIndex */
        "movl -0x18f4(%ebp), %ecx\n"
        "movl %edi, %edx\n" /* hullPointCount */
        "calll R_VisitPortalsForCell\n"
        "movl dpvsGlob+88, %ebx\n" /* line 2053 | bevelVertIndex */
        "testl %ebx, %ebx\n" /* bevelVertIndex */
        "jne .Lff1d30_000f1ddc\n"
        ".Lff1d30_000f235d:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 2101 | hullPointsPool_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x190c, %esp\n" /* line 2102 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: normals, windingVertIndex, useNormalPlanes */
        ".Lff1d30_000f2373:\n"
        "xorl %edi, %edi\n" /* line 1747 */
        "movl $1, %ecx\n"
        "movl $0, -0x18c0(%ebp)\n"
        "jmp .Lff1d30_000f23d2\n"
        ".Lff1d30_000f2386:\n"
        "leal (, %ecx, 8), %esi\n" /* line 1749 | windingVertIndex */
        "movl dpvsGlob+92, %ebx\n" /* bevelVertIndex */
        ".Lff1d30_000f2393:\n"
        "leal (, %eax, 8), %edx\n" /* line 1751 */
        "leal (%esi, %ebx), %eax\n" /* windingVertIndex */
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%ebx, %edx), %xmm0\n" /* bevelVertIndex */
        "jae .Lff1d30_000f2410\n"
        ".Lff1d30_000f23a9:\n"
        "movl 4(%eax), %edx\n" /* line 1753 */
        "movl (%eax), %eax\n"
        "movl -0x18c0(%ebp), %edi\n"
        "movl %eax, (%ebx, %edi, 8)\n" /* bevelVertIndex */
        "movl %edx, 4(%ebx, %edi, 8)\n" /* bevelVertIndex */
        "leal (%ecx, %ecx), %edi\n" /* line 1677 */
        "leal 1(%edi), %edx\n"
        "movl dpvsGlob+88, %eax\n" /* line 1747 */
        "cmpl %edx, %eax\n"
        "jl .Lff1d30_000f241e\n"
        "movl %ecx, -0x18c0(%ebp)\n" /* line 1748 */
        "movl %edx, %ecx\n"
        ".Lff1d30_000f23d2:\n"
        "cmpl %eax, %ecx\n" /* line 1749 */
        "jge .Lff1d30_000f2386\n"
        "movl dpvsGlob+92, %ebx\n" /* bevelVertIndex */
        "leal (, %ecx, 8), %esi\n" /* windingVertIndex */
        "movss 4(%ebx, %esi), %xmm0\n" /* bevelVertIndex */
        "ucomiss 0xc(%ebx, %esi), %xmm0\n" /* bevelVertIndex */
        "jbe .Lff1d30_000f2393\n"
        "leal 2(%edi), %ecx\n" /* line 1750 */
        "leal (, %ecx, 8), %esi\n" /* windingVertIndex */
        "leal (, %eax, 8), %edx\n" /* line 1751 */
        "leal (%esi, %ebx), %eax\n" /* windingVertIndex */
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%ebx, %edx), %xmm0\n" /* bevelVertIndex */
        "jb .Lff1d30_000f23a9\n"
        ".Lff1d30_000f2410:\n"
        "movl -0x18c0(%ebp), %esi\n" /* windingVertIndex */
        "shll $3, %esi\n" /* windingVertIndex */
        "jmp .Lff1d30_000f1e10\n"
        ".Lff1d30_000f241e:\n"
        "leal (, %eax, 8), %edx\n" /* line 1748 */
        "movl dpvsGlob+92, %ebx\n" /* bevelVertIndex */
        "jmp .Lff1d30_000f1e10\n"
        /* { scope 2: screenSpaceWinding, forceBevels */
        ".Lff1d30_000f2430:\n"
        "xorl %ebx, %ebx\n" /* line 794 | bevelVertIndex */
        "movl dpvsGlob+52, %edx\n"
        /* { scope 3: bevelVerts, bevelNormals */
        /* { scope 4 */
        ".Lff1d30_000f2438:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 722 | bevelVertIndex */
        "leal -0xaac(%ebp, %eax, 4), %ecx\n"
        "movss -0x18c8(%ebp), %xmm4\n"
        "jmp .Lff1d30_000f24ec\n"
        ".Lff1d30_000f244f:\n"
        "movaps %xmm7, %xmm5\n" /* line 723 */
        ".Lff1d30_000f2452:\n"
        "movaps %xmm4, %xmm3\n" /* line 726 */
        "mulss 4(%edx), %xmm3\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "addss 0x34(%edx), %xmm3\n"
        "movaps %xmm4, %xmm2\n" /* line 727 */
        "mulss 8(%edx), %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x38(%edx), %xmm2\n"
        "movaps %xmm4, %xmm0\n" /* line 729 */
        "mulss 0xc(%edx), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 0x1c(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss 0x3c(%edx), %xmm0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "divss %xmm0, %xmm1\n"
        "mulss (%edx), %xmm4\n" /* line 731 */
        "mulss 0x10(%edx), %xmm5\n"
        "addss %xmm5, %xmm4\n"
        "addss 0x30(%edx), %xmm4\n"
        "mulss %xmm1, %xmm4\n"
        "movss %xmm4, (%ecx)\n"
        "mulss %xmm1, %xmm3\n" /* line 732 */
        "movss %xmm3, 4(%ecx)\n"
        "mulss %xmm1, %xmm2\n" /* line 733 */
        "movss %xmm2, 8(%ecx)\n"
        "addl $1, %ebx\n" /* line 720 | bevelVertIndex */
        "cmpl $3, %ebx\n" /* bevelVertIndex */
        "jg .Lff1d30_000f2505\n"
        /* } scope */
        /* } scope */
        "addl $0xc, %ecx\n" /* line 794 */
        "movaps %xmm6, %xmm4\n"
        /* { scope 3: bevelVerts, bevelNormals */
        /* { scope 4 */
        "cmpl $1, %ebx\n" /* line 722 | bevelVertIndex */
        "jle .Lff1d30_000f2438\n"
        ".Lff1d30_000f24ec:\n"
        "leal -1(%ebx), %eax\n" /* line 723 | bevelVertIndex */
        "cmpl $1, %eax\n"
        "ja .Lff1d30_000f244f\n"
        "movss -0x18cc(%ebp), %xmm5\n"
        "jmp .Lff1d30_000f2452\n"
        ".Lff1d30_000f2505:\n"
        "movl -0xaac(%ebp), %eax\n" /* line 199 | screenSpaceWinding */
        "movl %eax, -0xa7c(%ebp)\n"
        "movl -0xaa8(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0xa78(%ebp)\n"
        "movl -0xaa4(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0xa74(%ebp)\n"
        "leal -0x4c(%ebp), %ecx\n" /* line 737 | bevelNormals */
        "movl $4, %edx\n"
        "leal -0xaac(%ebp), %eax\n" /* screenSpaceWinding */
        "calll R_GetSidePlaneNormals\n"
        "movl $0, -0x18c4(%ebp)\n"
        "movl $0, -0x18ec(%ebp)\n" /* childPlaneCount */
        "leal -0x18c(%ebp), %esi\n" /* childPlanes, windingVertIndex */
        "movl -0x18c4(%ebp), %edx\n"
        ".Lff1d30_000f255c:\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 742 | from */
        "leal -0x4c(%ebp, %eax, 4), %eax\n" /* from */
        /* { scope 5 */
        "movss (%eax), %xmm2\n" /* line 199 */
        "movss %xmm2, (%esi)\n"
        "movss 4(%eax), %xmm4\n" /* line 200 */
        "movss %xmm4, 4(%esi)\n"
        "movss 8(%eax), %xmm3\n" /* line 201 */
        "movss %xmm3, 8(%esi)\n"
        /* } scope */
        "movl -0x18d0(%ebp), %ebx\n" /* line 743 | forceBevels, bevelVertIndex */
        "testl %ebx, %ebx\n" /* bevelVertIndex */
        "jne .Lff1d30_000f2638\n"
        "testl %edi, %edi\n" /* line 745 */
        "jle .Lff1d30_000f2638\n"
        "movl imp_r_portalBevels, %eax\n" /* line 747 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm5\n"
        "movaps %xmm3, %xmm1\n"
        "mulss -0x10a4(%ebp), %xmm1\n"
        "mulss -0x10ac(%ebp), %xmm2\n" /* normals */
        "movaps %xmm4, %xmm0\n"
        "mulss -0x10a8(%ebp), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "ucomiss %xmm5, %xmm1\n"
        "jbe .Lff1d30_000f25fc\n"
        ".Lff1d30_000f25cc:\n"
        "movl imp_r_showPortals, %eax\n" /* line 749 */
        "movl (%eax), %eax\n"
        "testb $2, 8(%eax)\n"
        "jne .Lff1d30_000f2aa5\n"
        ".Lff1d30_000f25dd:\n"
        "movl -0x18c4(%ebp), %ebx\n" /* line 764 | bevelVertIndex */
        "addl $1, %ebx\n" /* bevelVertIndex */
        ".Lff1d30_000f25e6:\n"
        "cmpl $3, %ebx\n" /* line 740 | bevelVertIndex */
        "jg .Lff1d30_000f2069\n"
        "movl %ebx, -0x18c4(%ebp)\n" /* bevelVertIndex */
        "movl %ebx, %edx\n" /* bevelVertIndex */
        "jmp .Lff1d30_000f255c\n"
        ".Lff1d30_000f25fc:\n"
        "xorl %ecx, %ecx\n" /* line 750 */
        "leal -0x10ac(%ebp), %edx\n" /* normals */
        "jmp .Lff1d30_000f2631\n"
        ".Lff1d30_000f2606:\n"
        "movl %edx, %eax\n" /* line 2026 | planes */
        "addl $0xc, %edx\n"
        "movaps %xmm4, %xmm1\n" /* line 747 */
        "mulss 0x10(%eax), %xmm1\n"
        "movss (%esi), %xmm0\n" /* windingVertIndex */
        "mulss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0x14(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm5, %xmm1\n"
        "ja .Lff1d30_000f25cc\n"
        ".Lff1d30_000f2631:\n"
        "addl $1, %ecx\n" /* line 745 */
        "cmpl %ecx, %edi\n"
        "jne .Lff1d30_000f2606\n"
        ".Lff1d30_000f2638:\n"
        "movl imp_r_showPortals, %eax\n" /* line 756 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lff1d30_000f2768\n"
        ".Lff1d30_000f264a:\n"
        "movl -0x18c4(%ebp), %ecx\n" /* line 757 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal -0xaac(%ebp, %eax, 4), %eax\n"
        "movss (%esi), %xmm1\n" /* line 27 */
        "mulss (%eax), %xmm1\n"
        "movss 4(%esi), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%esi), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esi)\n"
        "movl $0xc, %eax\n" /* line 19 */
        "movl (%esi), %edx\n"
        "testl %edx, %edx\n"
        "movl $0, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x10(%esi)\n"
        "movl $0x10, %eax\n" /* line 20 */
        "movl 4(%esi), %ebx\n"
        "testl %ebx, %ebx\n"
        "movl $4, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, 0x11(%esi)\n"
        "movl 8(%esi), %ecx\n" /* line 21 */
        "testl %ecx, %ecx\n"
        "jle .Lff1d30_000f2847\n"
        "movl $0x14, %eax\n"
        ".Lff1d30_000f26c8:\n"
        "movb %al, 0x12(%esi)\n"
        "movb $0xff, 0x13(%esi)\n" /* line 763 | windingVertIndex */
        "addl $1, -0x18ec(%ebp)\n" /* line 764 | childPlaneCount */
        "addl $0x14, %esi\n" /* windingVertIndex */
        "jmp .Lff1d30_000f25dd\n"
        /* } scope */
        /* } scope */
        /* { scope 3: bevelVerts, bevelNormals */
        ".Lff1d30_000f26de:\n"
        "movss -0x68c(%ebp), %xmm5\n" /* line 667 | portalVerts */
        "movl dpvsGlob+48, %ecx\n"
        "movss -0x688(%ebp), %xmm4\n"
        "movss -0x684(%ebp), %xmm3\n"
        "movaps %xmm3, %xmm2\n"
        "mulss 0x2c(%ecx), %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 0x1c(%ecx), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 0xc(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x3c(%ecx), %xmm2\n"
        "ucomiss lit4_002ed610, %xmm2\n" /* line 668 | 0.125f */
        "jp .Lff1d30_000f2928\n"
        "jae .Lff1d30_000f2928\n"
        ".Lff1d30_000f2734:\n"
        "movl $1, -0x18e4(%ebp)\n" /* clipChildren */
        "movl $0xbf800000, -0x18cc(%ebp)\n"
        "movss -0x18cc(%ebp), %xmm1\n"
        "movss %xmm1, -0x18c8(%ebp)\n"
        "movss lit4_002ed5d0, %xmm6\n" /* 1.0f */
        "movaps %xmm6, %xmm7\n"
        "jmp .Lff1d30_000f2052\n"
        /* } scope */
        /* { scope 3: bevelVerts, bevelNormals */
        /* { scope 4 */
        ".Lff1d30_000f2768:\n"
        "movl imp_colorLtCyan, %eax\n" /* line 757 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x18c4(%ebp), %ebx\n" /* bevelVertIndex */
        "leal (%ebx, %ebx, 2), %eax\n" /* bevelVertIndex */
        "shll $2, %eax\n"
        "leal -0xaa0(%eax, %ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal -0xaac(%ebp), %edx\n" /* screenSpaceWinding */
        "leal (%edx, %eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_frontEndDataOut, %eax\n"
        "movl (%eax), %eax\n"
        "addl $str_00249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugLine\n"
        "jmp .Lff1d30_000f264a\n"
        /* } scope */
        /* } scope */
        /* { scope 3: bevelVerts, bevelNormals */
        ".Lff1d30_000f27ae:\n"
        "leal -2(%edi), %eax\n" /* line 558 */
        "testl %eax, %eax\n"
        "jle .Lff1d30_000f2920\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 563 */
        "leal (, %eax, 4), %edx\n"
        "leal -0x68c(%ebp), %eax\n" /* portalVerts */
        "addl %edx, %eax\n"
        "movaps %xmm5, %xmm3\n" /* line 42 */
        "mulss 8(%eax), %xmm3\n"
        "movaps %xmm6, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm7, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "addss %xmm4, %xmm3\n"
        "ucomiss %xmm2, %xmm3\n" /* line 564 */
        "ja .Lff1d30_000f2920\n"
        "leal -0xc(%edx), %ebx\n" /* line 565 */
        "xorl %ecx, %ecx\n"
        "leal -3(%edi), %edx\n"
        "jmp .Lff1d30_000f2804\n"
        ".Lff1d30_000f2801:\n"
        "movaps %xmm2, %xmm3\n"
        ".Lff1d30_000f2804:\n"
        "cmpl %ecx, %edx\n" /* line 558 */
        "je .Lff1d30_000f22b3\n"
        "leal -0x68c(%ebp), %eax\n" /* line 563 | portalVerts */
        "addl %ebx, %eax\n"
        "movaps %xmm5, %xmm2\n" /* line 42 */
        "mulss 8(%eax), %xmm2\n"
        "movaps %xmm7, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss %xmm4, %xmm2\n"
        "addl $1, %ecx\n"
        "subl $0xc, %ebx\n"
        "ucomiss %xmm3, %xmm2\n" /* line 564 */
        "jbe .Lff1d30_000f2801\n"
        "jmp .Lff1d30_000f22b3\n"
        /* } scope */
        /* { scope 3: bevelVerts, bevelNormals */
        /* { scope 4 */
        ".Lff1d30_000f2847:\n"
        "movl $8, %eax\n" /* line 21 */
        "jmp .Lff1d30_000f26c8\n"
        /* } scope */
        /* } scope */
        /* { scope 3: bevelVerts, bevelNormals */
        ".Lff1d30_000f2851:\n"
        "leal (, %edi, 8), %edx\n" /* line 698 */
        "leal -0xaac(%ebp), %ecx\n" /* screenSpaceWinding, to */
        "addl %edx, %ecx\n" /* to */
        /* { scope 4 */
        "movl -0xaac(%ebp), %eax\n" /* line 37 | screenSpaceWinding */
        "movl %eax, (%ecx)\n"
        "movl -0xaa8(%ebp), %eax\n" /* line 38 */
        "movl %eax, 4(%ecx)\n"
        /* } scope */
        "leal -0xaa4(%edx, %ebp), %edx\n" /* line 699 | to */
        /* { scope 4 */
        "movl -0xaa4(%ebp), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "movl -0xaa0(%ebp), %eax\n" /* line 38 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        "pxor %xmm1, %xmm1\n" /* line 701 */
        "testl %edi, %edi\n"
        "jle .Lff1d30_000f28d7\n"
        "movl $1, %edx\n"
        "pxor %xmm2, %xmm2\n"
        "movl $8, %eax\n"
        ".Lff1d30_000f289f:\n"
        "movss -0xaac(%eax, %ebp), %xmm1\n" /* line 702 */
        "addl $1, %edx\n"
        "addl $8, %eax\n"
        "movss -0xaa8(%eax, %ebp), %xmm0\n"
        "subss -0xab8(%eax, %ebp), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "cmpl %edx, %edi\n" /* line 701 */
        "jge .Lff1d30_000f289f\n"
        "movaps %xmm2, %xmm1\n"
        "mulss lit4_002ed610, %xmm1\n" /* 0.125f */
        ".Lff1d30_000f28d7:\n"
        "movl (%ebx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm1, %xmm0\n"
        "setbe %al\n"
        "movl %eax, -0x18e4(%ebp)\n" /* clipChildren */
        "jmp .Lff1d30_000f2052\n"
        /* } scope */
        ".Lff1d30_000f28f1:\n"
        "movl imp_r_portalBevels, %eax\n" /* line 787 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lff1d30_000f2b0b\n"
        "movb $1, -0x18d9(%ebp)\n" /* line 786 */
        "movl $0, -0x18d0(%ebp)\n" /* forceBevels */
        "jmp .Lff1d30_000f1fbf\n"
        /* { scope 3: bevelVerts, bevelNormals */
        ".Lff1d30_000f2920:\n"
        "movaps %xmm2, %xmm3\n" /* line 558 */
        "jmp .Lff1d30_000f22b3\n"
        /* } scope */
        /* { scope 3: bevelVerts, bevelNormals */
        ".Lff1d30_000f2928:\n"
        "xorl %esi, %esi\n" /* line 668 | windingVertIndex */
        "movl $0x3f800000, -0x18c8(%ebp)\n"
        "movl $0x3f800000, -0x18cc(%ebp)\n"
        "movss lit4_002ed5dc, %xmm6\n" /* -1.0f */
        "movaps %xmm6, %xmm7\n"
        "leal -0x68c(%ebp), %ebx\n" /* portalVerts */
        "jmp .Lff1d30_000f2999\n"
        ".Lff1d30_000f2951:\n"
        "movss 0xc(%ebx), %xmm5\n" /* line 667 */
        "movss 0x10(%ebx), %xmm4\n"
        "movss 0x14(%ebx), %xmm3\n"
        "movaps %xmm3, %xmm2\n"
        "mulss 0x2c(%ecx), %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 0x1c(%ecx), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 0xc(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x3c(%ecx), %xmm2\n"
        "addl $0xc, %ebx\n"
        "movss lit4_002ed610, %xmm0\n" /* line 668 | 0.125f */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lff1d30_000f2734\n"
        ".Lff1d30_000f2999:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 678 | 1.0f */
        "divss %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movaps %xmm5, %xmm1\n" /* line 679 */
        "mulss 4(%ecx), %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 0x14(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0x24(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x34(%ecx), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "leal (, %esi, 8), %edx\n"
        "leal -0xaac(%ebp), %eax\n" /* screenSpaceWinding, v */
        "addl %edx, %eax\n" /* v */
        /* { scope 4 */
        "movaps %xmm5, %xmm0\n" /* line 30 */
        "mulss (%ecx), %xmm0\n"
        "mulss 0x10(%ecx), %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "mulss 0x20(%ecx), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "addss 0x30(%ecx), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movss %xmm1, 4(%eax)\n" /* line 31 */
        /* } scope */
        "movaps %xmm0, %xmm1\n" /* line 680 */
        "minss -0x18c8(%ebp), %xmm1\n"
        "movss %xmm1, -0x18c8(%ebp)\n"
        "maxss %xmm6, %xmm0\n" /* line 682 */
        "movaps %xmm0, %xmm6\n"
        "movss -0xaa8(%edx, %ebp), %xmm0\n" /* line 684 */
        "movaps %xmm0, %xmm1\n"
        "minss -0x18cc(%ebp), %xmm1\n"
        "movss %xmm1, -0x18cc(%ebp)\n"
        "maxss %xmm7, %xmm0\n" /* line 686 */
        "movaps %xmm0, %xmm7\n"
        "addl $1, %esi\n" /* line 664 | windingVertIndex */
        "cmpl %esi, %edi\n" /* windingVertIndex */
        "jne .Lff1d30_000f2951\n"
        "movaps %xmm6, %xmm1\n"
        "subss -0x18c8(%ebp), %xmm1\n"
        "subss -0x18cc(%ebp), %xmm0\n"
        "jmp .Lff1d30_000f2026\n"
        ".Lff1d30_000f2a6b:\n"
        "movl -0x18ec(%ebp), %ecx\n" /* childPlaneCount */
        "jmp .Lff1d30_000f2322\n"
        /* } scope */
        /* } scope */
        /* { scope 2: screenSpaceWinding, forceBevels */
        ".Lff1d30_000f2a76:\n"
        "leal -0x68c(%ebp), %eax\n" /* line 2094 | portalVerts */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* hullPointCount */
        "movl $color, 4(%esp)\n"
        "movl imp_frontEndDataOut, %eax\n"
        "movl (%eax), %eax\n"
        "addl $str_00249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugPolygon\n"
        "jmp .Lff1d30_000f1f8a\n"
        /* } scope */
        /* { scope 2: screenSpaceWinding, forceBevels */
        /* { scope 3: bevelVerts, bevelNormals */
        /* { scope 4 */
        ".Lff1d30_000f2aa5:\n"
        "movl -0x18c4(%ebp), %ebx\n" /* line 750 | bevelVertIndex */
        "addl $1, %ebx\n" /* bevelVertIndex */
        "movl imp_colorMdCyan, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* bevelVertIndex */
        "leal -0xaac(%ebp, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x18c4(%ebp), %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal -0xaac(%ebp, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_frontEndDataOut, %eax\n"
        "movl (%eax), %eax\n"
        "addl $str_00249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugLine\n"
        "jmp .Lff1d30_000f25e6\n"
        ".Lff1d30_000f2af2:\n"
        "movl $0, -0x18ec(%ebp)\n" /* line 740 | childPlaneCount */
        "movl $1, -0x18e4(%ebp)\n" /* clipChildren */
        "jmp .Lff1d30_000f2069\n"
        /* } scope */
        /* } scope */
        ".Lff1d30_000f2b0b:\n"
        "movb $0, -0x18d9(%ebp)\n" /* line 787 */
        "movl $0, -0x18d0(%ebp)\n" /* forceBevels */
        "jmp .Lff1d30_000f1fbf\n"
        /* } scope */
        ".Lff1d30_000f2b21:\n"
        "movl dpvsGlob+88, %ecx\n" /* line 2071 */
        "testl %ecx, %ecx\n"
        "jne .Lff1d30_000f2b7e\n"
        "jmp .Lff1d30_000f2c5c\n"
        ".Lff1d30_000f2b30:\n"
        "leal (, %eax, 8), %edx\n" /* line 1747 */
        "xorl %esi, %esi\n" /* windingVertIndex */
        "movl dpvsGlob+92, %ebx\n" /* bevelVertIndex */
        ".Lff1d30_000f2b3f:\n"
        "movl (%edx, %ebx), %eax\n" /* line 1756 */
        "movl 4(%edx, %ebx), %edx\n"
        "movl %eax, (%esi, %ebx)\n" /* windingVertIndex */
        "movl %edx, 4(%esi, %ebx)\n" /* windingVertIndex */
        "movl -0x18bc(%ebp), %eax\n" /* line 2074 */
        "movl 0x28(%eax), %edx\n" /* hullPoints */
        /* { scope 2: screenSpaceWinding, forceBevels */
        "movl dpvsGlob+96, %eax\n" /* line 1779 */
        "movl %eax, (%edx)\n"
        "movl %edx, dpvsGlob+96\n" /* line 1780 */
        /* } scope */
        "movl -0x18bc(%ebp), %edx\n" /* line 2075 */
        "movl $0, 0x28(%edx)\n"
        "movl dpvsGlob+88, %edi\n" /* line 2071 | hullPointCount */
        "testl %edi, %edi\n" /* hullPointCount */
        "je .Lff1d30_000f2c5c\n"
        ".Lff1d30_000f2b7e:\n"
        "movl dpvsGlob+92, %eax\n" /* line 1739 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x18bc(%ebp)\n"
        "movb $0, (%eax)\n" /* line 1740 */
        "movl dpvsGlob+88, %eax\n" /* line 1742 */
        "subl $1, %eax\n"
        "movl %eax, dpvsGlob+88\n"
        "testl %eax, %eax\n" /* line 1747 */
        "jle .Lff1d30_000f2b30\n"
        "movl $0, -0x18e0(%ebp)\n"
        "xorl %edi, %edi\n"
        "movl $1, %ecx\n"
        "jmp .Lff1d30_000f2bfe\n"
        ".Lff1d30_000f2bb2:\n"
        "leal (, %ecx, 8), %esi\n" /* line 1749 | windingVertIndex */
        "movl dpvsGlob+92, %ebx\n" /* bevelVertIndex */
        ".Lff1d30_000f2bbf:\n"
        "leal (, %eax, 8), %edx\n" /* line 1751 */
        "leal (%esi, %ebx), %eax\n" /* windingVertIndex */
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%ebx, %edx), %xmm0\n" /* bevelVertIndex */
        "jae .Lff1d30_000f2c3c\n"
        ".Lff1d30_000f2bd5:\n"
        "movl 4(%eax), %edx\n" /* line 1753 */
        "movl (%eax), %eax\n"
        "movl -0x18e0(%ebp), %edi\n"
        "movl %eax, (%ebx, %edi, 8)\n" /* bevelVertIndex */
        "movl %edx, 4(%ebx, %edi, 8)\n" /* bevelVertIndex */
        "leal (%ecx, %ecx), %edi\n" /* line 1677 */
        "leal 1(%edi), %edx\n"
        "movl dpvsGlob+88, %eax\n" /* line 1747 */
        "cmpl %eax, %edx\n"
        "jg .Lff1d30_000f2c4a\n"
        "movl %ecx, -0x18e0(%ebp)\n" /* line 1748 */
        "movl %edx, %ecx\n"
        ".Lff1d30_000f2bfe:\n"
        "cmpl %ecx, %eax\n" /* line 1749 */
        "jle .Lff1d30_000f2bb2\n"
        "movl dpvsGlob+92, %ebx\n" /* bevelVertIndex */
        "leal (, %ecx, 8), %esi\n" /* windingVertIndex */
        "movss 4(%ebx, %esi), %xmm0\n" /* bevelVertIndex */
        "ucomiss 0xc(%ebx, %esi), %xmm0\n" /* bevelVertIndex */
        "jbe .Lff1d30_000f2bbf\n"
        "leal 2(%edi), %ecx\n" /* line 1750 */
        "leal (, %ecx, 8), %esi\n" /* windingVertIndex */
        "leal (, %eax, 8), %edx\n" /* line 1751 */
        "leal (%esi, %ebx), %eax\n" /* windingVertIndex */
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%ebx, %edx), %xmm0\n" /* bevelVertIndex */
        "jb .Lff1d30_000f2bd5\n"
        ".Lff1d30_000f2c3c:\n"
        "movl -0x18e0(%ebp), %esi\n" /* windingVertIndex */
        "shll $3, %esi\n" /* windingVertIndex */
        "jmp .Lff1d30_000f2b3f\n"
        ".Lff1d30_000f2c4a:\n"
        "leal (, %eax, 8), %edx\n" /* line 1748 */
        "movl dpvsGlob+92, %ebx\n" /* bevelVertIndex */
        "jmp .Lff1d30_000f2b3f\n"
        ".Lff1d30_000f2c5c:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2101 | hullPointsPool_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x190c, %esp\n" /* line 2102 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* bevelVertIndex */
        /* { scope 1: normals, windingVertIndex, useNormalPlanes */
        "leal -0x1c(%ebp), %edi\n" /* line 2101 | hullPointsPool_large_local, hullPointCount */
        "movl %edi, (%esp)\n" /* hullPointCount */
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* bevelVertIndex */
        "calll __Unwind_Resume\n"
    );
}
#endif /* Original R_VisitPortals ASM */

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
            byte *occ = (byte *)occTable[i];
            int planeCount = *(int *)(occ + 0x1c);
            DpvsPlane *planes = *(DpvsPlane **)(occ + 0x20);
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
        byte *rg_ptr = (byte *)&rg;
        if (*(int *)(rg_ptr + 0x150c) && *(byte *)(rg_ptr + 0x14c8) && *(int *)(rg_ptr + 0x14ac) == 1) {
            farPlaneDist = *(float *)(rg_ptr + 0x14c0);
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
    byte *rg_ptr2 = (byte *)&rg;
    *(const GfxViewParms **)(rg_ptr2 + 0x3190) = viewParms;

    /* Process entities: brush models and dynamic entities */
    {
        byte *scene = (byte *)imp_scene;
        int entityCount = *(int *)(scene + 0xc);
        byte *entities = *(byte **)(scene + 0x10);

        for (i = 0; i < entityCount; i++) {
            byte *ent = entities + i * 116;
            int entType = *(int *)ent;

            if (entType <= 1) {
                /* Dynamic XModel entity */
                byte *sceneEnt = scene + 0x5c4 + i * 52;
                void *dobj = R_GetGfxEntityDObj(sceneEnt, ent);

                vec3_t objmins, objmaxs;
                /* Call DObjGetBounds through refimport function pointer table */
                ((void (*)(void *, vec3_t *, vec3_t *))*(void **)((byte *)imp_ri + 0x1b0))(dobj, &objmins, &objmaxs);

                float scale = *(float *)(ent + 0x38);
                float bounds[6];
                /* bounds = scale * objmins + origin */
                bounds[0] = scale * objmins[0] + *(float *)(ent + 0x3c);
                bounds[1] = scale * objmins[1] + *(float *)(ent + 0x40);
                bounds[2] = scale * objmins[2] + *(float *)(ent + 0x44);
                /* bounds+3 = scale * objmaxs + origin */
                bounds[3] = scale * objmaxs[0] + *(float *)(ent + 0x3c);
                bounds[4] = scale * objmaxs[1] + *(float *)(ent + 0x40);
                bounds[5] = scale * objmaxs[2] + *(float *)(ent + 0x44);

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
                    byte *world = *(byte **)((byte *)&rgp + 0x109c);
                    mnode_t *bspNodes = *(mnode_t **)(world + 0xc);
                    int cell = R_FilterEntityIntoCells_r_impl(bspNodes, i, bounds, bounds + 3);
                    if (cell != -1)
                        continue;
                }

            entity_process:
                R_UpdateXModelBounds(scene + 0x5c4 + i * 52, ent);
                CG_CullIn(*(void **)(scene + 0x5c4 + i * 52 + 8));
                R_SkinSceneEnt(scene + 0x5c4 + i * 52, ent);
                *(int *)(scene + 0x5c4 + i * 52 + 0xc) = 5;
                R_AddXModelSurfaces(i);

            } else if (entType == 3) {
                /* Brush model entity */
                byte *sceneEnt = scene + 0x5c4 + i * 52;
                void *bmodel = *(void **)(sceneEnt + 4);
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
                    transformed[0] = *(float *)(ent + 0x3c) + localX * *(float *)(ent + 0x14) + localY * *(float *)(ent + 0x20) + localZ * *(float *)(ent + 0x2c);
                    transformed[1] = *(float *)(ent + 0x40) + localX * *(float *)(ent + 0x18) + localY * *(float *)(ent + 0x24) + localZ * *(float *)(ent + 0x30);
                    transformed[2] = *(float *)(ent + 0x44) + localX * *(float *)(ent + 0x1c) + localY * *(float *)(ent + 0x28) + localZ * *(float *)(ent + 0x34);

                    AddPointToBounds(transformed, boundsMin, boundsMax);
                }

                float bounds[6];
                bounds[0] = boundsMin[0]; bounds[1] = boundsMin[1]; bounds[2] = boundsMin[2];
                bounds[3] = boundsMax[0]; bounds[4] = boundsMax[1]; bounds[5] = boundsMax[2];

                /* Frustum cull */
                if (!R_CullBoundsAgainstFrustumAndOccluders(bounds, frustumPlanes, frustumPlaneCount))
                    continue;

                /* Filter into BSP cells */
                byte *world = *(byte **)((byte *)&rgp + 0x109c);
                mnode_t *bspNodes = *(mnode_t **)(world + 0xc);
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
            byte *world = *(byte **)((byte *)&rgp + 0x109c);
            GfxCell *cells = *(GfxCell **)(world + 0x100);
            GfxCell *cameraCell = &cells[cameraCellIndex];

            /* Add surfaces from camera cell */
            R_AddVisibleSurfacesInCell_impl(cameraCell, frustumPlanes, frustumPlaneCount);

            /* Try portal traversal for neighboring cells */
            R_VisitPortals(cameraCell, (const DpvsPlane *)&dpvsGlob, frustumPlanes, frustumPlaneCount);

            /* Diagnostic */
            R_dpvs_diag_print(cameraCellIndex, *(byte *)((byte *)&dpvsGlob + 100), cameraCell);
        } else {
            /* Unknown cell — fallback to all cells */
            byte *world = *(byte **)((byte *)&rgp + 0x109c);
            int cellCount = *(int *)(world + 0xfc);
            GfxCell *cells = *(GfxCell **)(world + 0x100);
            for (i = 0; i < cellCount; i++)
                R_AddVisibleSurfacesInCell_impl(&cells[i], frustumPlanes, frustumPlaneCount);
        }
    }

    /* Process sorted world surfaces (sky surfaces) — always add */
    {
        byte *world = *(byte **)((byte *)&rgp + 0x109c);
        int skySurfCount = *(int *)(world + 0x18);
        if (skySurfCount > 0) {
            int *skyStartSurfs = *(int **)(world + 0x1c);
            for (i = 0; i < skySurfCount; i++) {
                int surfIndex = skyStartSurfs[i];
                R_AddWorldSurfaceWithCull_impl(surfIndex, frustumPlanes, 0, 0);
            }
        }
    }

    /* Process dynamic lights */
    {
        byte *scene = (byte *)imp_scene;
        int dlightCount = *(int *)(scene + 0x14);
        if (dlightCount > 0) {
            for (i = 0; i < dlightCount; i++) {
                byte *dlightBase = scene + 0x10 + i * 44;
                float *dlightOrigin = (float *)(dlightBase + 0xc);
                float dlightRadius = *(float *)(dlightBase + 0x18);
                int result = R_CullPointAndRadius(dlightOrigin, dlightRadius, frustumPlanes, frustumPlaneCount);
                *(byte *)(scene + 0x598 + i) = (result == 2) ? 1 : 0;
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

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
void R_AddWorldSurfacesDpvs(const GfxViewParms *viewParms, int cameraCellIndex)
{
    R_AddWorldSurfacesDpvs_impl(viewParms, cameraCellIndex);
}
#else
/* x86 trampoline: stack-based cdecl args, tail-call to _impl */
__attribute__((naked))
void R_AddWorldSurfacesDpvs(const GfxViewParms *viewParms, int cameraCellIndex)
{
    __asm__ __volatile__ (
        "jmp R_AddWorldSurfacesDpvs_impl\n"
    );
}
#endif

#if 0 /* Original ASM — converted to R_AddWorldSurfacesDpvs_impl above */
__attribute__((naked))
void R_AddWorldSurfacesDpvs_original(const GfxViewParms *viewParms, int cameraCellIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2293 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfc, %esp\n"
        /* { scope 1 */
        "movl $__mh_execute_header, 4(%esp)\n" /* line 2297 */
        "leal -0x20(%ebp), %eax\n" /* activeOccluderBuffer_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x20(%ebp), %edx\n" /* activeOccluderBuffer_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %ebx\n" /* dlightIndex */
        "movl $0x1e000, 4(%esp)\n" /* line 2298 */
        "leal -0x1c(%ebp), %eax\n" /* occluderPlaneBuffer_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* occluderPlaneBuffer_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %ebx, dpvsGlob+60\n" /* line 2307 | dlightIndex */
        "movl %eax, dpvsGlob+68\n" /* line 2308 */
        "movl imp_r_drawWorld, %eax\n" /* line 2310 */
        "movl (%eax), %eax\n"
        "movzbl 8(%eax), %eax\n"
        "movb %al, dpvsGlob+100\n"
        "movl imp_r_drawEntities, %eax\n" /* line 2311 */
        "movl (%eax), %eax\n"
        "movzbl 8(%eax), %edx\n"
        "movb %dl, dpvsGlob+101\n"
        "movl imp_r_drawBModels, %eax\n" /* line 2312 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lff2c88_000f2d14\n"
        "testb %dl, %dl\n"
        "jne .Lff2c88_000f3660\n"
        ".Lff2c88_000f2d14:\n"
        "xorl %eax, %eax\n"
        ".Lff2c88_000f2d16:\n"
        "movb %al, dpvsGlob+104\n"
        "movl imp_r_drawSModels, %eax\n" /* line 2313 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lff2c88_000f2d36\n"
        "cmpb $0, dpvsGlob+101\n"
        "jne .Lff2c88_000f364c\n"
        ".Lff2c88_000f2d36:\n"
        "xorl %eax, %eax\n"
        ".Lff2c88_000f2d38:\n"
        "movb %al, dpvsGlob+102\n"
        "movl imp_r_drawXModels, %eax\n" /* line 2314 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lff2c88_000f2d58\n"
        "cmpb $0, dpvsGlob+101\n"
        "jne .Lff2c88_000f3656\n"
        ".Lff2c88_000f2d58:\n"
        "xorl %eax, %eax\n"
        ".Lff2c88_000f2d5a:\n"
        "movb %al, dpvsGlob+103\n"
        "movl $0, dpvsGlob+56\n" /* line 2151 */
        "movl 8(%ebp), %edx\n" /* line 2153 | viewParms */
        "addl $0xc8, %edx\n"
        "movl %edx, dpvsGlob+48\n"
        "movl 8(%ebp), %eax\n" /* line 2154 | viewParms */
        "addl $0x108, %eax\n"
        "movl %eax, dpvsGlob+52\n"
        "leal -0xc8(%ebp), %eax\n" /* line 2155 | frustumPlanes */
        "movl %eax, 0xc(%esp)\n"
        "movl $4, 8(%esp)\n"
        "movl $standardFrustumSidePlanes, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll R_FrustumClipPlanes\n"
        "pxor %xmm3, %xmm3\n" /* line 2157 */
        "movl 8(%ebp), %edx\n" /* viewParms */
        "ucomiss 0xc4(%edx), %xmm3\n"
        "jne .Lff2c88_000f2fbf\n"
        "jp .Lff2c88_000f2fbf\n"
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, dpvsGlob+72\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, dpvsGlob+76\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, dpvsGlob+80\n"
        "movl $0x3f800000, dpvsGlob+84\n" /* line 2110 */
        "movl %edx, %esi\n" /* line 2113 | from */
        "addl $0xc, %esi\n" /* from */
        /* { scope 2: entityCount */
        "movss 0xc(%edx), %xmm1\n" /* line 199 */
        "movss %xmm1, dpvsGlob\n"
        "movl %edx, %ebx\n" /* line 200 */
        "addl $0x10, %ebx\n"
        "movss 0x10(%edx), %xmm2\n"
        "movss %xmm2, dpvsGlob+4\n"
        "movl %edx, %ecx\n" /* line 201 */
        "addl $0x14, %ecx\n"
        "movss 0x14(%edx), %xmm0\n"
        "movss %xmm0, dpvsGlob+8\n"
        /* } scope */
        "mulss dpvsGlob+72, %xmm1\n" /* line 27 */
        "mulss dpvsGlob+76, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss dpvsGlob+80, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss lit4_002ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, dpvsGlob+12\n"
        "movl $0xc, %eax\n" /* line 19 */
        "movl dpvsGlob, %edx\n"
        "testl %edx, %edx\n"
        "movl $0, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+16\n"
        "movl $0x10, %eax\n" /* line 20 */
        "movl dpvsGlob+4, %edi\n"
        "testl %edi, %edi\n"
        "movl $4, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+17\n"
        "movl $0x14, %eax\n" /* line 21 */
        "movl dpvsGlob+8, %edx\n"
        "testl %edx, %edx\n"
        "movl $8, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+18\n"
        "movb $0xff, dpvsGlob+19\n" /* line 2115 */
        "movl $dpvsGlob, dpvsGlob+40\n" /* line 2116 */
        "movl imp_r_zfar, %eax\n" /* line 2347 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n" /* line 2348 */
        "je .Lff2c88_000f360b\n"
        ".Lff2c88_000f2ec4:\n"
        "movl imp_rg, %edi\n" /* bmodel */
        ".Lff2c88_000f2eca:\n"
        "movss dpvsConfig, %xmm4\n" /* line 2350 */
        "maxss %xmm0, %xmm4\n"
        "ucomiss %xmm4, %xmm3\n" /* line 2120 */
        "jae .Lff2c88_000f3ac7\n"
        "movss sse_float_sign_mask, %xmm0\n" /* line 216 — was color+32, fix #143 */
        "movss (%esi), %xmm3\n"
        "xorps %xmm0, %xmm3\n"
        "movss %xmm3, dpvsGlob+20\n"
        "movss (%ebx), %xmm1\n" /* line 217 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, dpvsGlob+24\n"
        "movss (%ecx), %xmm2\n" /* line 218 */
        "xorps %xmm0, %xmm2\n"
        "movss %xmm2, dpvsGlob+28\n"
        /* { scope 2: entityCount */
        "mulss dpvsGlob+72, %xmm3\n" /* line 27 */
        "mulss dpvsGlob+76, %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss dpvsGlob+80, %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm3, %xmm4\n"
        "movss %xmm4, dpvsGlob+32\n"
        /* } scope */
        "movl $0xc, %eax\n" /* line 19 */
        "movl dpvsGlob+20, %ebx\n"
        "testl %ebx, %ebx\n"
        "movl $0, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+36\n"
        "movl $0x10, %eax\n" /* line 20 */
        "movl dpvsGlob+24, %ecx\n"
        "testl %ecx, %ecx\n"
        "movl $4, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+37\n"
        "movl $0x14, %eax\n" /* line 21 */
        "movl dpvsGlob+28, %edx\n"
        "testl %edx, %edx\n"
        "movl $8, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+38\n"
        "movb $0xff, dpvsGlob+39\n" /* line 2128 */
        "movl $dpvsGlob+20, dpvsGlob+44\n" /* line 2129 */
        "movl dpvsGlob+40, %edx\n" /* line 325 */
        "testl %edx, %edx\n"
        "jne .Lff2c88_000f30d5\n"
        ".Lff2c88_000f2fb0:\n"
        "movl $4, -0xe4(%ebp)\n" /* frustumPlaneCount */
        "jmp .Lff2c88_000f30fc\n"
        ".Lff2c88_000f2fbf:\n"
        "movss sse_float_sign_mask, %xmm0\n" /* line 216 — was color+32, fix #143 */
        "movss 0xc(%edx), %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, dpvsGlob+72\n"
        "movss 0x10(%edx), %xmm1\n" /* line 217 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, dpvsGlob+76\n"
        "movss 0x14(%edx), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, dpvsGlob+80\n"
        "movl $0, dpvsGlob+84\n" /* line 2137 */
        "movss 0xc(%edx), %xmm1\n" /* line 199 */
        "movss %xmm1, dpvsGlob\n"
        "movss 0x10(%edx), %xmm0\n" /* line 200 */
        "movss %xmm0, dpvsGlob+4\n"
        "movss 0x14(%edx), %xmm2\n" /* line 201 */
        "movss %xmm2, dpvsGlob+8\n"
        "mulss dpvsGlob+72, %xmm1\n" /* line 27 */
        "mulss dpvsGlob+76, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss dpvsGlob+80, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss lit4_002ed864, %xmm0\n" /* 262144.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, dpvsGlob+12\n"
        "movl $0xc, %eax\n" /* line 19 */
        "movl dpvsGlob, %esi\n"
        "testl %esi, %esi\n"
        "movl $0, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+16\n"
        "movl $0x10, %eax\n" /* line 20 */
        "movl dpvsGlob+4, %ebx\n"
        "testl %ebx, %ebx\n"
        "movl $4, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+17\n"
        "movl $0x14, %eax\n" /* line 21 */
        "movl dpvsGlob+8, %ecx\n"
        "testl %ecx, %ecx\n"
        "movl $8, %edx\n"
        "cmovlel %edx, %eax\n"
        "movb %al, dpvsGlob+18\n"
        "movl $0, dpvsGlob+40\n" /* line 2142 */
        "movl $0, dpvsGlob+44\n" /* line 2145 */
        "movl imp_rg, %edi\n" /* bmodel */
        ".Lff2c88_000f30c7:\n"
        "movl dpvsGlob+40, %edx\n" /* line 325 */
        "testl %edx, %edx\n"
        "je .Lff2c88_000f2fb0\n"
        ".Lff2c88_000f30d5:\n"
        "movl (%edx), %eax\n" /* line 327 */
        "movl %eax, -0x78(%ebp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl $5, -0xe4(%ebp)\n" /* frustumPlaneCount */
        ".Lff2c88_000f30fc:\n"
        "movl dpvsGlob+44, %ecx\n" /* line 330 */
        "testl %ecx, %ecx\n"
        "je .Lff2c88_000f314a\n"
        "movl -0xe4(%ebp), %edx\n" /* line 332 | frustumPlaneCount */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $2, %eax\n"
        "movl (%ecx), %edx\n"
        "movl %edx, -0xc8(%eax, %ebp)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, -0xc4(%eax, %ebp)\n"
        "movl 8(%ecx), %edx\n"
        "movl %edx, -0xc0(%eax, %ebp)\n"
        "movl 0xc(%ecx), %edx\n"
        "movl %edx, -0xbc(%eax, %ebp)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, -0xb8(%eax, %ebp)\n"
        "addl $1, -0xe4(%ebp)\n" /* line 333 | frustumPlaneCount */
        ".Lff2c88_000f314a:\n"
        "movl 8(%ebp), %eax\n" /* line 2329 | viewParms */
        "movl %eax, 0x3190(%edi)\n" /* bmodel */
        /* { scope 2: entityCount */
        /* { scope 3: entIndex, bounds, sceneEnt */
        "movl imp_scene, %edi\n" /* line 1469 | bmodel */
        "movl 0xc(%edi), %edx\n" /* bmodel */
        "movl %edx, -0xe0(%ebp)\n" /* entityCount */
        "testl %edx, %edx\n" /* line 1470 */
        "jle .Lff2c88_000f3455\n"
        "movl $0, -0xd4(%ebp)\n" /* entIndex */
        "movl $0, -0xcc(%ebp)\n"
        "jmp .Lff2c88_000f31a6\n"
        ".Lff2c88_000f3180:\n"
        "addl $1, -0xd4(%ebp)\n" /* entIndex */
        "addl $0x74, -0xcc(%ebp)\n"
        "movl -0xd4(%ebp), %eax\n" /* entIndex */
        "cmpl %eax, -0xe0(%ebp)\n" /* entityCount */
        "je .Lff2c88_000f3455\n"
        "movl imp_scene, %edi\n" /* bmodel */
        ".Lff2c88_000f31a6:\n"
        "movl -0xcc(%ebp), %ebx\n" /* line 1472 | ent */
        "addl 0x10(%edi), %ebx\n" /* bmodel, ent */
        "movl (%ebx), %eax\n" /* line 1475 | ent */
        "cmpl $1, %eax\n"
        "jle .Lff2c88_000f366a\n"
        "cmpl $3, %eax\n" /* line 1477 */
        "jne .Lff2c88_000f3180\n"
        /* { scope 4: bounds, sceneEnt, objmins, objmaxs, ... */
        /* { scope 5 */
        "movl -0xd4(%ebp), %edx\n" /* line 1443 | entIndex */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0x5c4(%edi, %eax, 4), %edi\n" /* occluder */
        "movl %edi, -0xd0(%ebp)\n" /* occluder, sceneEnt */
        "movl 4(%edi), %edi\n" /* line 1446 | bmodel */
        /* { scope 6: transformed */
        /* { scope 7 */
        "leal -0x44(%ebp), %edx\n" /* line 1415 */
        "movl %edx, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* bounds */
        "movl %eax, (%esp)\n"
        "calll ClearBounds\n"
        "xorl %esi, %esi\n" /* corner */
        "leal 0x3c(%ebx), %edx\n" /* planeIndex */
        "movl %edx, -0xf4(%ebp)\n"
        "leal 0x14(%ebx), %eax\n" /* planeIndex */
        "movl %eax, -0xe8(%ebp)\n"
        "leal 0x20(%ebx), %edx\n" /* planeIndex */
        "movl %edx, -0xec(%ebp)\n"
        "leal 0x2c(%ebx), %eax\n" /* planeIndex */
        "movl %eax, -0xf0(%ebp)\n"
        ".Lff2c88_000f3213:\n"
        "movl %esi, %edx\n" /* line 1420 | corner */
        "andl $1, %edx\n"
        "leal (%edx, %edx), %eax\n"
        "addl %edx, %eax\n"
        "movss (%edi, %eax, 4), %xmm1\n" /* occluder */
        "movl %esi, %edx\n" /* line 1421 | corner */
        "sarl $1, %edx\n"
        "andl $1, %edx\n"
        "leal (%edx, %edx), %eax\n"
        "addl %edx, %eax\n"
        "movss 4(%edi, %eax, 4), %xmm2\n" /* occluder */
        "movl %esi, %edx\n" /* line 1422 | corner */
        "sarl $2, %edx\n"
        "andl $1, %edx\n"
        "leal (%edx, %edx), %eax\n"
        "addl %edx, %eax\n"
        "movss 8(%edi, %eax, 4), %xmm3\n" /* occluder */
        "movl 0x3c(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x2c(%ebp)\n" /* transformed */
        "movl -0xf4(%ebp), %edx\n" /* line 200 */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x24(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x14(%ebx), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n" /* transformed */
        "movss %xmm0, -0x2c(%ebp)\n" /* transformed */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "movl -0xe8(%ebp), %eax\n"
        "mulss 4(%eax), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss -0x24(%ebp), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movaps %xmm2, %xmm0\n" /* line 288 */
        "mulss 0x20(%ebx), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n" /* transformed */
        "movss %xmm0, -0x2c(%ebp)\n" /* transformed */
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "movl -0xec(%ebp), %edx\n"
        "mulss 4(%edx), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "mulss 8(%edx), %xmm2\n" /* line 290 */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 288 */
        "mulss 0x2c(%ebx), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n" /* transformed */
        "movss %xmm0, -0x2c(%ebp)\n" /* transformed */
        "movaps %xmm3, %xmm0\n" /* line 289 */
        "movl -0xf0(%ebp), %eax\n"
        "mulss 4(%eax), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "mulss 8(%eax), %xmm3\n" /* line 290 */
        "addss %xmm2, %xmm3\n"
        "movss %xmm3, -0x24(%ebp)\n"
        "leal -0x44(%ebp), %edx\n" /* line 1428 */
        "movl %edx, 8(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* bounds */
        "movl %eax, 4(%esp)\n"
        "leal -0x2c(%ebp), %edx\n" /* transformed */
        "movl %edx, (%esp)\n"
        "calll AddPointToBounds\n"
        "addl $1, %esi\n" /* line 1418 | corner */
        "cmpl $8, %esi\n" /* corner */
        "jne .Lff2c88_000f3213\n"
        /* } scope */
        /* } scope */
        /* { scope 6: transformed */
        "movl -0xe4(%ebp), %eax\n" /* line 383 | frustumPlaneCount */
        "testl %eax, %eax\n"
        "jg .Lff2c88_000f3540\n"
        ".Lff2c88_000f333b:\n"
        "movl dpvsGlob+56, %eax\n" /* line 390 */
        "testl %eax, %eax\n"
        "jle .Lff2c88_000f340d\n"
        "xorl %edi, %edi\n" /* occluder */
        ".Lff2c88_000f334a:\n"
        "movl dpvsGlob+60, %eax\n" /* line 392 */
        "movl (%eax, %edi, 4), %esi\n" /* occluder */
        "movl 0x20(%esi), %edx\n" /* line 394 | occluder */
        "movl 0x1c(%esi), %eax\n" /* occluder */
        "testl %eax, %eax\n"
        "jle .Lff2c88_000f3180\n"
        "movb $0xff, 0x13(%edx)\n" /* line 396 */
        /* { scope 7 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss -0x50(%ebp, %eax), %xmm0\n"
        "mulss (%edx), %xmm0\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss -0x50(%ebp, %eax), %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss -0x50(%ebp, %eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        /* } scope */
        "addss 0xc(%edx), %xmm0\n" /* line 397 */
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lff2c88_000f33fe\n"
        "leal 0x27(%edx), %ecx\n" /* line 398 */
        "xorl %ebx, %ebx\n" /* planeIndex */
        ".Lff2c88_000f33ab:\n"
        "addl $1, %ebx\n" /* line 394 | planeIndex */
        "cmpl 0x1c(%esi), %ebx\n" /* occluder, planeIndex */
        "jge .Lff2c88_000f3180\n"
        "movb $0xff, (%ecx)\n" /* line 396 */
        "movl %ecx, %edx\n" /* line 2293 */
        /* { scope 7 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x50(%ebp, %eax), %xmm0\n"
        "mulss -0x13(%ecx), %xmm0\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0x50(%ebp, %eax), %xmm1\n"
        "mulss -0xf(%ecx), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0x50(%ebp, %eax), %xmm0\n"
        "mulss -0xb(%ecx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "addl $0x14, %ecx\n"
        /* } scope */
        "addss -7(%edx), %xmm0\n" /* line 397 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lff2c88_000f33ab\n"
        ".Lff2c88_000f33fe:\n"
        "addl $1, %edi\n" /* line 390 | occluder */
        "cmpl dpvsGlob+56, %edi\n" /* occluder */
        "jl .Lff2c88_000f334a\n"
        /* } scope */
        ".Lff2c88_000f340d:\n"
        "movl imp_rgp, %eax\n" /* line 1450 */
        "movl 0x109c(%eax), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "leal -0x44(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* bounds */
        "movl -0xd4(%ebp), %edx\n" /* entIndex */
        "calll R_FilterEntityIntoCells_r\n"
        "addl $1, %eax\n"
        "jne .Lff2c88_000f3180\n"
        "movl -0xd4(%ebp), %eax\n" /* line 1453 | entIndex */
        "movl %eax, 4(%esp)\n"
        "movl -0xd0(%ebp), %edx\n" /* sceneEnt */
        "movl %edx, (%esp)\n"
        "calll R_AddBModelSurfaces\n"
        "jmp .Lff2c88_000f3180\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff2c88_000f3455:\n"
        "movl imp_r_skipPvs, %eax\n" /* line 2172 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lff2c88_000f34c1\n"
        "movl 0xc(%ebp), %eax\n" /* line 2175 | cameraCellIndex */
        "testl %eax, %eax\n"
        "js .Lff2c88_000f3a18\n"
        "movl imp_rgp, %eax\n" /* line 2177 */
        "movl 0x109c(%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* cameraCellIndex */
        "shll $2, %eax\n"
        "movl 0xc(%ebp), %ebx\n" /* cameraCellIndex, cell */
        "shll $6, %ebx\n" /* cell */
        "subl %eax, %ebx\n" /* cell */
        "addl 0x100(%edx), %ebx\n" /* cell */
        "movl imp_r_singleCell, %eax\n" /* line 2179 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lff2c88_000f3973\n"
        "movl -0xe4(%ebp), %edx\n" /* line 2187 | frustumPlaneCount */
        "movl %edx, 0xc(%esp)\n"
        "leal -0xc8(%ebp), %eax\n" /* frustumPlanes */
        "movl %eax, 8(%esp)\n"
        "movl $dpvsGlob, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cell */
        "calll R_VisitPortals\n"

        /* DIAGNOSTIC: print state after R_VisitPortals */
        "pushl %eax\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %ebx\n"              /* cellPtr */
        "movzbl dpvsGlob+100, %eax\n"
        "pushl %eax\n"              /* drawWorld */
        "pushl 0xc(%ebp)\n"        /* cameraCellIndex */
        "calll R_dpvs_diag_print\n"
        "addl $12, %esp\n"
        "popl %edx\n"
        "popl %ecx\n"
        "popl %eax\n"
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_DpvsShouldFallbackAllCells\n"
        "testl %eax, %eax\n"
        "jne .Lff2c88_000f3a18\n"

        /* } scope */
        /* { scope 2: entityCount */
        ".Lff2c88_000f34c1:\n"
        "movl dpvsGlob+44, %edi\n" /* line 2227 | bmodel */
        "testl %edi, %edi\n" /* bmodel */
        "je .Lff2c88_000f34e1\n"
        "movl imp_rgp, %eax\n" /* line 2231 */
        "movl 0x109c(%eax), %eax\n"
        "movl 0x18(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lff2c88_000f3936\n"
        /* } scope */
        /* { scope 2: entityCount */
        ".Lff2c88_000f34e1:\n"
        "movl imp_scene, %edi\n" /* line 2281 | bmodel */
        "movl 0x14(%edi), %esi\n" /* bmodel, cellIndex */
        "testl %esi, %esi\n" /* cellIndex */
        "jg .Lff2c88_000f38e0\n"
        /* } scope */
        ".Lff2c88_000f34f2:\n"
        "movl imp_r_vc_makelog, %eax\n" /* line 2334 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* dlightIndex */
        "testl %ebx, %ebx\n" /* dlightIndex */
        "je .Lff2c88_000f351f\n"
        "movl -0xe4(%ebp), %eax\n" /* line 2335 | frustumPlaneCount */
        "movl %eax, 8(%esp)\n"
        "leal -0xc8(%ebp), %edx\n" /* frustumPlanes */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* viewParms */
        "movl %eax, (%esp)\n"
        "calll RB_ShowLightVisCachePoints\n"
        ".Lff2c88_000f351f:\n"
        "leal -0x1c(%ebp), %eax\n" /* occluderPlaneBuffer_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "leal -0x20(%ebp), %eax\n" /* activeOccluderBuffer_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0xfc, %esp\n" /* line 2340 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: entityCount */
        /* { scope 3: entIndex, bounds, sceneEnt */
        /* { scope 4: bounds, sceneEnt, objmins, objmaxs, ... */
        /* { scope 5 */
        /* { scope 6: transformed */
        ".Lff2c88_000f3540:\n"
        "movb $0xff, -0xb5(%ebp)\n" /* line 385 */
        "movzbl -0xb8(%ebp), %eax\n" /* line 51 */
        "movss -0xc8(%ebp), %xmm1\n" /* frustumPlanes */
        "mulss -0x50(%eax, %ebp), %xmm1\n"
        "movzbl -0xb7(%ebp), %eax\n" /* line 52 */
        "movss -0xc4(%ebp), %xmm0\n"
        "mulss -0x50(%ebp, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -0xb6(%ebp), %eax\n" /* line 53 */
        "movss -0x50(%ebp, %eax), %xmm0\n"
        "mulss -0xc0(%ebp), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "addss -0xbc(%ebp), %xmm0\n" /* line 386 */
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lff2c88_000f3180\n"
        "leal -0xa1(%ebp), %ecx\n" /* line 2293 */
        "movl $1, %ebx\n" /* dlightIndex */
        "jmp .Lff2c88_000f35fe\n"
        ".Lff2c88_000f35b0:\n"
        "movb $0xff, (%ecx)\n" /* line 385 */
        "movl %ecx, %edx\n" /* line 2293 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x50(%eax, %ebp), %xmm0\n"
        "mulss -0x13(%ecx), %xmm0\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0x50(%eax, %ebp), %xmm1\n"
        "mulss -0xf(%ecx), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0x50(%eax, %ebp), %xmm0\n"
        "mulss -0xb(%ecx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "addl $1, %ebx\n"
        "addl $0x14, %ecx\n"
        "addss -7(%edx), %xmm0\n" /* line 386 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lff2c88_000f3180\n"
        ".Lff2c88_000f35fe:\n"
        "cmpl %ebx, -0xe4(%ebp)\n" /* line 383 | planeIndex, frustumPlaneCount */
        "jne .Lff2c88_000f35b0\n"
        "jmp .Lff2c88_000f333b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff2c88_000f360b:\n"
        "jp .Lff2c88_000f2ec4\n" /* line 2348 */
        "movl imp_rg, %edi\n" /* bmodel */
        "movl 0x150c(%edi), %eax\n" /* bmodel */
        "testl %eax, %eax\n"
        "je .Lff2c88_000f2eca\n"
        "cmpb $0, 0x14c8(%edi)\n" /* bmodel */
        "je .Lff2c88_000f2eca\n"
        "cmpl $1, 0x14ac(%edi)\n" /* bmodel */
        "jne .Lff2c88_000f2eca\n"
        "movss 0x14c0(%edi), %xmm0\n" /* line 2349 | bmodel */
        "jmp .Lff2c88_000f2eca\n"
        ".Lff2c88_000f364c:\n"
        "movl $1, %eax\n" /* line 2313 */
        "jmp .Lff2c88_000f2d38\n"
        ".Lff2c88_000f3656:\n"
        "movl $1, %eax\n" /* line 2314 */
        "jmp .Lff2c88_000f2d5a\n"
        ".Lff2c88_000f3660:\n"
        "movl $1, %eax\n" /* line 2312 */
        "jmp .Lff2c88_000f2d16\n"
        /* { scope 2: entityCount */
        /* { scope 3: entIndex, bounds, sceneEnt */
        /* { scope 4: bounds, sceneEnt, objmins, objmaxs, ... */
        ".Lff2c88_000f366a:\n"
        "movl -0xd4(%ebp), %edx\n" /* line 1357 | entIndex */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0x5c4(%edi, %eax, 4), %edi\n" /* occluder */
        "movl %edi, -0xdc(%ebp)\n" /* occluder, sceneEnt */
        /* { scope 5 */
        "movl %ebx, 4(%esp)\n" /* line 1232 | planeIndex */
        "movl %edi, (%esp)\n" /* occluder */
        "calll R_GetGfxEntityDObj\n"
        "leal -0x38(%ebp), %edx\n" /* line 1234 | objmaxs */
        "movl %edx, 8(%esp)\n"
        "leal -0x2c(%ebp), %edx\n" /* transformed */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0x1b0(%eax)\n"
        "movss 0x38(%ebx), %xmm1\n" /* line 1236 | planeIndex, scale */
        /* { scope 6: transformed */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x2c(%ebp), %xmm0\n" /* transformed */
        "addss 0x3c(%ebx), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n" /* bounds */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x28(%ebp), %xmm0\n"
        "addss 0x40(%ebx), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "mulss -0x24(%ebp), %xmm1\n" /* line 290 */
        "addss 0x44(%ebx), %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        /* } scope */
        "movss 0x38(%ebx), %xmm1\n" /* line 1237 | planeIndex, scale */
        /* { scope 6: transformed */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x38(%ebp), %xmm0\n" /* objmaxs */
        "addss 0x3c(%ebx), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x34(%ebp), %xmm0\n"
        "addss 0x40(%ebx), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "mulss -0x30(%ebp), %xmm1\n" /* line 290 */
        "addss 0x44(%ebx), %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        /* } scope */
        /* } scope */
        /* { scope 5 */
        "movl -0xe4(%ebp), %edx\n" /* line 383 | frustumPlaneCount */
        "testl %edx, %edx\n"
        "jle .Lff2c88_000f37ef\n"
        "movb $0xff, -0xb5(%ebp)\n" /* line 385 */
        "movzbl -0xb8(%ebp), %eax\n" /* line 51 */
        "movss -0x50(%ebp, %eax), %xmm0\n"
        "mulss -0xc8(%ebp), %xmm0\n" /* frustumPlanes */
        "movzbl -0xb7(%ebp), %eax\n" /* line 52 */
        "movss -0x50(%eax, %ebp), %xmm1\n"
        "mulss -0xc4(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -0xb6(%ebp), %eax\n" /* line 53 */
        "movss -0xc0(%ebp), %xmm0\n"
        "mulss -0x50(%ebp, %eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "addss -0xbc(%ebp), %xmm0\n" /* line 386 */
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lff2c88_000f3180\n"
        "leal -0xa1(%ebp), %ecx\n" /* line 2293 */
        "movl $1, %esi\n" /* cellIndex */
        "jmp .Lff2c88_000f37e7\n"
        ".Lff2c88_000f3799:\n"
        "movb $0xff, (%ecx)\n" /* line 385 */
        "movl %ecx, %edx\n" /* line 2293 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x50(%eax, %ebp), %xmm0\n"
        "mulss -0x13(%ecx), %xmm0\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0x50(%eax, %ebp), %xmm1\n"
        "mulss -0xf(%ecx), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0xb(%ecx), %xmm0\n"
        "mulss -0x50(%ebp, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %esi\n"
        "addl $0x14, %ecx\n"
        "addss -7(%edx), %xmm1\n" /* line 386 */
        "ucomiss %xmm3, %xmm1\n"
        "jbe .Lff2c88_000f3180\n"
        ".Lff2c88_000f37e7:\n"
        "cmpl -0xe4(%ebp), %esi\n" /* line 383 | frustumPlaneCount, occluder */
        "jne .Lff2c88_000f3799\n"
        ".Lff2c88_000f37ef:\n"
        "movl dpvsGlob+56, %eax\n" /* line 390 */
        "testl %eax, %eax\n"
        "jle .Lff2c88_000f3995\n"
        "movl $0, -0xd8(%ebp)\n" /* occluderIndex */
        "movl -0xd8(%ebp), %edx\n" /* occluderIndex */
        ".Lff2c88_000f380c:\n"
        "movl dpvsGlob+60, %eax\n" /* line 392 */
        "movl (%eax, %edx, 4), %edi\n" /* occluder */
        "movl 0x20(%edi), %edx\n" /* line 394 | occluder */
        "movl 0x1c(%edi), %eax\n" /* occluder */
        "testl %eax, %eax\n"
        "jle .Lff2c88_000f3180\n"
        "movb $0xff, 0x13(%edx)\n" /* line 396 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss -0x50(%ebp, %eax), %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss -0x50(%ebp, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss -0x50(%ebp, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%edx), %xmm1\n" /* line 397 */
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm1\n"
        "ja .Lff2c88_000f38c0\n"
        "leal 0x27(%edx), %ecx\n" /* line 398 */
        "xorl %esi, %esi\n" /* occluder */
        ".Lff2c88_000f386d:\n"
        "addl $1, %esi\n" /* line 394 | occluder */
        "cmpl 0x1c(%edi), %esi\n" /* occluder */
        "jge .Lff2c88_000f3180\n"
        "movb $0xff, (%ecx)\n" /* line 396 */
        "movl %ecx, %edx\n" /* line 2293 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x50(%ebp, %eax), %xmm1\n"
        "mulss -0x13(%ecx), %xmm1\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0x50(%ebp, %eax), %xmm0\n"
        "mulss -0xf(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0xb(%ecx), %xmm0\n"
        "mulss -0x50(%ebp, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x14, %ecx\n"
        "addss -7(%edx), %xmm1\n" /* line 397 */
        "ucomiss %xmm3, %xmm1\n"
        "jbe .Lff2c88_000f386d\n"
        ".Lff2c88_000f38c0:\n"
        "addl $1, -0xd8(%ebp)\n" /* line 390 | occluderIndex */
        "movl -0xd8(%ebp), %eax\n" /* occluderIndex */
        "cmpl dpvsGlob+56, %eax\n"
        "jge .Lff2c88_000f3995\n"
        "movl %eax, %edx\n"
        "jmp .Lff2c88_000f380c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: entityCount */
        ".Lff2c88_000f38e0:\n"
        "xorl %ebx, %ebx\n" /* line 2281 | dlightIndex */
        "movl %edi, %esi\n" /* bmodel, cellIndex */
        "jmp .Lff2c88_000f38ec\n"
        ".Lff2c88_000f38e6:\n"
        "movl imp_scene, %edi\n" /* bmodel */
        ".Lff2c88_000f38ec:\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* line 2283 | dlightIndex */
        "leal (%ebx, %eax, 2), %eax\n" /* dlightIndex */
        "leal 0x10(%edi, %eax, 4), %eax\n" /* bmodel */
        "movl -0xe4(%ebp), %edx\n" /* line 2284 | frustumPlaneCount */
        "movl %edx, 0xc(%esp)\n"
        "leal -0xc8(%ebp), %edx\n" /* frustumPlanes */
        "movl %edx, 8(%esp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, 4(%esp)\n"
        "addl $0xc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_CullPointAndRadius\n"
        "cmpl $2, %eax\n"
        "sete 0x598(%esi)\n" /* cellIndex */
        "addl $1, %ebx\n" /* line 2281 | dlightIndex */
        "addl $1, %esi\n" /* cellIndex */
        "cmpl 0x14(%edi), %ebx\n" /* bmodel, dlightIndex */
        "jl .Lff2c88_000f38e6\n"
        "jmp .Lff2c88_000f34f2\n"
        /* } scope */
        /* { scope 2: entityCount */
        ".Lff2c88_000f3936:\n"
        "movl -0xe4(%ebp), %esi\n" /* line 2231 | frustumPlaneCount, cellIndex */
        "subl $1, %esi\n" /* cellIndex */
        "xorl %ebx, %ebx\n" /* surfIndex */
        ".Lff2c88_000f3941:\n"
        "movl 0x1c(%eax), %eax\n" /* line 2232 */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl $0, (%esp)\n"
        "movl %esi, %ecx\n" /* cellIndex */
        "leal -0xc8(%ebp), %edx\n" /* frustumPlanes */
        "calll R_AddWorldSurfaceWithCull\n"
        "addl $1, %ebx\n" /* line 2231 | surfIndex */
        "movl imp_rgp, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "cmpl 0x18(%eax), %ebx\n" /* surfIndex */
        "jl .Lff2c88_000f3941\n"
        "jmp .Lff2c88_000f34e1\n"
        /* } scope */
        /* { scope 2: entityCount */
        ".Lff2c88_000f3973:\n"
        "movl $0, dpvsGlob+44\n" /* line 2181 */
        "movl -0xe4(%ebp), %ecx\n" /* line 2182 | frustumPlaneCount */
        "leal -0xc8(%ebp), %edx\n" /* frustumPlanes */
        "movl %ebx, %eax\n" /* cell */
        "calll R_AddVisibleSurfacesInCell\n"
        "jmp .Lff2c88_000f34c1\n"
        /* { scope 3: entIndex, bounds, sceneEnt */
        /* { scope 4: bounds, sceneEnt, objmins, objmaxs, ... */
        ".Lff2c88_000f3995:\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 1337 */
        "subss -0x50(%ebp), %xmm0\n" /* bounds */
        "ucomiss lit4_002ed884, %xmm0\n" /* 1536.0f */
        "jbe .Lff2c88_000f3a6d\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 1339 */
        "subss -0x4c(%ebp), %xmm0\n"
        "ucomiss lit4_002ed884, %xmm0\n" /* 1536.0f */
        "jbe .Lff2c88_000f3a80\n"
        ".Lff2c88_000f39c3:\n"
        "movl %ebx, 4(%esp)\n" /* line 1388 | planeIndex */
        "movl -0xdc(%ebp), %edx\n" /* sceneEnt */
        "movl %edx, (%esp)\n"
        "calll R_UpdateXModelBounds\n"
        "movl -0xdc(%ebp), %edx\n" /* line 1390 | sceneEnt */
        "movl 8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_CullIn\n"
        "movl %ebx, 4(%esp)\n" /* line 1391 | planeIndex */
        "movl -0xdc(%ebp), %eax\n" /* sceneEnt */
        "movl %eax, (%esp)\n"
        "calll R_SkinSceneEnt\n"
        "movl -0xdc(%ebp), %edx\n" /* line 1392 | sceneEnt */
        "movl $5, 0xc(%edx)\n"
        "movl -0xd4(%ebp), %eax\n" /* line 1394 | entIndex */
        "movl %eax, (%esp)\n"
        "calll R_AddXModelSurfaces\n"
        "jmp .Lff2c88_000f3180\n"
        /* } scope */
        /* } scope */
        ".Lff2c88_000f3a18:\n"
        "movl imp_rgp, %eax\n" /* line 2193 */
        "movl 0x109c(%eax), %eax\n"
        "movl 0xfc(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lff2c88_000f34c1\n"
        "xorl %esi, %esi\n" /* cellIndex */
        "xorl %ebx, %ebx\n" /* cell */
        ".Lff2c88_000f3a35:\n"
        "movl 0x100(%eax), %edx\n" /* line 2194 */
        "leal (%ebx, %edx), %eax\n" /* cell */
        "movl -0xe4(%ebp), %ecx\n" /* frustumPlaneCount */
        "leal -0xc8(%ebp), %edx\n" /* frustumPlanes */
        "calll R_AddVisibleSurfacesInCell\n"
        "addl $1, %esi\n" /* line 2193 | cellIndex */
        "movl imp_rgp, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "addl $0x3c, %ebx\n" /* cell */
        "cmpl %esi, 0xfc(%eax)\n" /* cellIndex */
        "jg .Lff2c88_000f3a35\n"
        "jmp .Lff2c88_000f34c1\n"
        /* { scope 3: entIndex, bounds, sceneEnt */
        /* { scope 4: bounds, sceneEnt, objmins, objmaxs, ... */
        ".Lff2c88_000f3a6d:\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 1344 */
        "subss -0x4c(%ebp), %xmm0\n"
        "ucomiss lit4_002ed884, %xmm0\n" /* 1536.0f */
        "jbe .Lff2c88_000f3a97\n"
        ".Lff2c88_000f3a80:\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x48(%ebp), %xmm0\n"
        "ucomiss lit4_002ed884, %xmm0\n" /* 1536.0f */
        "ja .Lff2c88_000f39c3\n"
        ".Lff2c88_000f3a97:\n"
        "movl imp_rgp, %eax\n" /* line 1386 */
        "movl 0x109c(%eax), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "leal -0x44(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "leal -0x50(%ebp), %ecx\n" /* bounds */
        "movl -0xd4(%ebp), %edx\n" /* entIndex */
        "calll R_FilterEntityIntoCells_r\n"
        "addl $1, %eax\n"
        "jne .Lff2c88_000f3180\n"
        "jmp .Lff2c88_000f39c3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff2c88_000f3ac7:\n"
        "movl $0, dpvsGlob+44\n" /* line 2122 */
        "jmp .Lff2c88_000f30c7\n"
        "movl %eax, %ebx\n" /* ent */
        "leal -0x1c(%ebp), %edx\n" /* line 2335 | occluderPlaneBuffer_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        ".Lff2c88_000f3ae3:\n"
        "leal -0x20(%ebp), %edx\n" /* activeOccluderBuffer_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* dlightIndex */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n" /* dlightIndex */
        "jmp .Lff2c88_000f3ae3\n"
    );
}
#endif /* Original ASM */
