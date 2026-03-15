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
void R_DrawModel(int entIndex);
float R_GetFarPlaneDist(void);
void R_ClearDpvsScene(void);
void R_SetCullDist(float dist);
static int R_FilterEntityIntoCells_r(mnode_t *node, const vec_t *maxs);
static int R_FilterEntityIntoCells_r_impl(mnode_t *node, int entIndex, const vec_t *mins, const vec_t *maxs);
int R_CellForPoint(const vec_t *origin);
static vec3_t * R_ChopPortalWinding(vec3_t *vertsIn, int *vertexCount, vec3_t *vertsOut);
static vec3_t * R_ChopPortalWinding_impl(vec3_t *vertsIn, int *vertexCount, const float *plane, vec3_t *vertsOut);
static void R_GetSidePlaneNormals(vec3_t *winding, int vertexCount, vec3_t *normals);
static void R_GetSidePlaneNormals_impl(vec3_t *winding, int vertexCount, vec3_t *normals);
static __attribute__((regparm(3))) void R_AddStaticModelWithCull(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel);
void R_FrustumClipPlanes(const D3DMATRIX *viewProjMtx, vec4_t *sidePlanes, int sidePlaneCount, DpvsPlane *frustumPlanes);
static __attribute__((regparm(3))) void R_AddWorldSurfaceWithCull(int surfIndex, const DpvsPlane *planes, int planeCount, int stackLevel);
static void R_AddAabbTreeSurfaces_r(const DpvsPlane *planes, int planeCount, int stackLevel);
static int R_GetFurtherCellList_r(const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t (*v)[128], const GfxCell * *list, int count);
static void R_AddVisibleSurfacesInCell(const GfxCell *cell, const DpvsPlane *planes, int planeCount);
static void R_VisitPortalsForCell(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren);
static void R_VisitPortals(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount);
void R_AddWorldSurfacesDpvs(const GfxViewParms *viewParms, int cameraCellIndex);

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

    byte *globals = (byte *)&rgp;
    byte *world = *(byte **)(globals + 0x109c);
    if (!world)
        return;

    int cellCount = *(int *)(world + 0xfc);
    byte *cells = *(byte **)(world + 0x100);
    for (int i = 0; i < cellCount; i++) {
        *(int *)(cells + i * 0x3c + 0x38) = 0;
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
    byte *world = *(byte **)((byte *)&rgp + 0x109c);
    GfxCell *cells = *(GfxCell **)(world + 0x100);
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

/* Trampoline: marshals register args (eax=node, edx=entIndex, ecx=mins, stack=maxs) to cdecl */
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

/* Trampoline: marshals (eax=vertsIn, edx=vertexCount_ptr, ecx=plane, stack=vertsOut) to cdecl */
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

/* Trampoline: marshals (eax=winding, edx=vertexCount, ecx=normals) to cdecl */
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

/* line 1582 */
static __attribute__((naked)) __attribute__((regparm(3)))
void R_AddStaticModelWithCull(int smodelIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1582 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %ebx\n" /* planes */
        "movl %ecx, -0x28(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* stackLevel */
        "movl %eax, -0x2c(%ebp)\n" /* stackLevel */
        /* { scope 1: occluderIndex */
        "movl imp_rg, %esi\n" /* line 1590 | entIndex */
        "movl 0x3194(%esi), %eax\n" /* entIndex */
        "movl -0x24(%ebp), %edx\n"
        "leal (%eax, %edx, 8), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* smodelDync */
        "movl (%eax), %eax\n" /* line 1591 */
        "movl imp_scene, %edx\n"
        "cmpl (%edx), %eax\n"
        "je .Lfef4ee_000ef654\n"
        "movl imp_rgp, %eax\n" /* line 1594 */
        "movl 0x109c(%eax), %eax\n"
        "movl -0x24(%ebp), %ecx\n"
        "leal (%ecx, %ecx, 2), %edi\n" /* smodelInst */
        "shll $5, %edi\n" /* smodelInst */
        "addl 0xf8(%eax), %edi\n" /* smodelInst */
        "pxor %xmm0, %xmm0\n" /* line 1595 */
        "ucomiss (%edi), %xmm0\n" /* smodelInst */
        "jp .Lfef4ee_000ef6f3\n"
        "jne .Lfef4ee_000ef6f3\n"
        ".Lfef4ee_000ef557:\n"
        "leal 0x14(%edi), %esi\n" /* line 1603 | smodelInst, entIndex */
        /* { scope 2 */
        "movl -0x28(%ebp), %ecx\n" /* line 346 */
        "testl %ecx, %ecx\n"
        "jle .Lfef4ee_000ef5be\n"
        "xorl %edx, %edx\n"
        "pxor %xmm2, %xmm2\n"
        ".Lfef4ee_000ef567:\n"
        "movzbl 0x13(%ebx), %eax\n" /* line 348 | occluder */
        "cmpl %eax, -0x2c(%ebp)\n" /* stackLevel */
        "jg .Lfef4ee_000ef5b3\n"
        "movb $0xff, 0x13(%ebx)\n" /* line 350 | occluder */
        "movzbl 0x10(%ebx), %eax\n" /* line 51 */
        "movss (%ebx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%ebx), %eax\n" /* line 52 */
        "movss 4(%ebx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%ebx), %eax\n" /* line 53 */
        "movss 8(%ebx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%ebx), %xmm1\n" /* line 351 | occluder */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lfef4ee_000ef654\n"
        ".Lfef4ee_000ef5b3:\n"
        "addl $1, %edx\n" /* line 346 */
        "addl $0x14, %ebx\n" /* occluder */
        "cmpl %edx, -0x28(%ebp)\n"
        "jne .Lfef4ee_000ef567\n"
        ".Lfef4ee_000ef5be:\n"
        "movl dpvsGlob+56, %edx\n" /* line 355 */
        "testl %edx, %edx\n"
        "jle .Lfef4ee_000ef65c\n"
        "movl $0, -0x1c(%ebp)\n" /* occluderIndex */
        "pxor %xmm3, %xmm3\n"
        "movl -0x1c(%ebp), %edx\n" /* occluderIndex */
        ".Lfef4ee_000ef5da:\n"
        "movl dpvsGlob+60, %eax\n" /* line 357 */
        "movl (%eax, %edx, 4), %ebx\n" /* occluder */
        "movl -0x2c(%ebp), %ecx\n" /* line 358 | stackLevel */
        "cmpl 0x18(%ebx), %ecx\n" /* occluder */
        "jg .Lfef4ee_000ef6d9\n"
        "movl 0x20(%ebx), %edx\n" /* line 361 | occluder */
        "movl 0x1c(%ebx), %eax\n" /* occluder */
        "testl %eax, %eax\n"
        "jle .Lfef4ee_000ef654\n"
        "xorl %ecx, %ecx\n"
        "movaps %xmm3, %xmm2\n"
        ".Lfef4ee_000ef5fd:\n"
        "movzbl 0x13(%edx), %eax\n" /* line 363 */
        "cmpl %eax, -0x2c(%ebp)\n" /* stackLevel */
        "jg .Lfef4ee_000ef649\n"
        "movb $0xff, 0x13(%edx)\n" /* line 365 */
        /* { scope 3 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "addss 0xc(%edx), %xmm1\n" /* line 366 */
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lfef4ee_000ef6d9\n"
        ".Lfef4ee_000ef649:\n"
        "addl $1, %ecx\n" /* line 361 */
        "addl $0x14, %edx\n"
        "cmpl 0x1c(%ebx), %ecx\n" /* occluder */
        "jl .Lfef4ee_000ef5fd\n"
        /* } scope */
        /* } scope */
        ".Lfef4ee_000ef654:\n"
        "addl $0x5c, %esp\n" /* line 1628 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: occluderIndex */
        ".Lfef4ee_000ef65c:\n"
        "movl imp_scene, %edx\n" /* line 1610 */
        "movl (%edx), %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* smodelDync */
        "movl %eax, (%ecx)\n"
        "movl imp_r_showSModelNames, %eax\n" /* line 1617 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfef4ee_000ef73e\n"
        ".Lfef4ee_000ef67a:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1620 */
        "movl %eax, (%esp)\n"
        "calll R_AddStaticModelToScene\n"
        "movl %eax, %esi\n" /* entIndex */
        "testl %eax, %eax\n" /* line 1621 */
        "js .Lfef4ee_000ef654\n"
        "leal (%eax, %eax, 2), %ebx\n" /* line 1624 | sceneEnt */
        "leal (%eax, %ebx, 4), %ebx\n" /* sceneEnt */
        "movl imp_scene, %edx\n"
        "leal 0x5c4(%edx, %ebx, 4), %ebx\n" /* sceneEnt */
        "movl -0x24(%ebp), %ecx\n" /* line 1625 */
        "movl %ecx, 8(%esp)\n"
        "leal (, %eax, 8), %eax\n"
        "subl %esi, %eax\n" /* entIndex */
        "leal (%esi, %eax, 4), %eax\n" /* entIndex */
        "movl 0x10(%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* sceneEnt */
        "calll R_SkinStaticModel\n"
        "movl $5, 0xc(%ebx)\n" /* line 1626 | sceneEnt */
        "movl %esi, 8(%ebp)\n" /* line 1627 | entIndex, stackLevel */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1628 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: occluderIndex */
        "jmp R_AddXModelSurfaces\n" /* line 1627 */
        /* { scope 2 */
        ".Lfef4ee_000ef6d9:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 355 | occluderIndex */
        "movl -0x1c(%ebp), %eax\n" /* occluderIndex */
        "cmpl dpvsGlob+56, %eax\n"
        "jge .Lfef4ee_000ef65c\n"
        "movl %eax, %edx\n"
        "jmp .Lfef4ee_000ef5da\n"
        /* } scope */
        ".Lfef4ee_000ef6f3:\n"
        "leal 0x317c(%esi), %eax\n" /* line 1598 | entIndex */
        "movl %eax, 4(%esp)\n"
        "leal 4(%edi), %eax\n" /* smodelInst */
        "movl %eax, (%esp)\n"
        "calll Vec3Distance\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 0x3188(%esi), %xmm0\n" /* line 1600 | entIndex */
        "addss 0x318c(%esi), %xmm0\n" /* entIndex */
        "ucomiss (%edi), %xmm0\n" /* smodelInst */
        "jbe .Lfef4ee_000ef557\n"
        "movl imp_scene, %edx\n" /* line 1602 */
        "movl (%edx), %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* smodelDync */
        "movl %eax, (%ecx)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1628 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: occluderIndex */
        ".Lfef4ee_000ef73e:\n"
        "movl 0x10(%edi), %eax\n" /* line 1618 | smodelInst */
        "movl %eax, (%esp)\n"
        "calll XModelGetName\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x3e99999a, 0xc(%esp)\n"
        "movl imp_colorWhite, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 4(%edi), %eax\n" /* smodelInst */
        "movl %eax, 4(%esp)\n"
        "movl imp_frontEndDataOut, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugString\n"
        "jmp .Lfef4ee_000ef67a\n"
    );
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

/* line 1068 */
static __attribute__((naked)) __attribute__((regparm(3)))
void R_AddWorldSurfaceWithCull(int surfIndex, const DpvsPlane *planes, int planeCount, int stackLevel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1068 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %ebx\n" /* surfIndex */
        "movl 8(%ebp), %edi\n" /* stackLevel */

        /* { scope 1: occluderIndex */
        "leal (, %eax, 4), %eax\n" /* line 1072 */
        "movl %eax, -0x20(%ebp)\n"
        "movl imp_rg, %esi\n" /* minmax */
        "movl 0x3198(%esi), %eax\n" /* minmax */
        "movl -0x20(%ebp), %esi\n" /* minmax */
        "movl (%eax, %esi), %eax\n"
        "movl imp_scene, %esi\n" /* minmax */
        "cmpl (%esi), %eax\n" /* minmax */
        "je .Lfef8a0_000efa54\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1075 | tris */
        "shll $2, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl imp_rgp, %ebx\n" /* tris */
        "movl 0x109c(%ebx), %eax\n" /* tris */
        "movl 0x14(%eax), %eax\n"
        "movl -0x24(%ebp), %esi\n" /* minmax */
        "movl 8(%eax, %esi), %ebx\n" /* tris */
        "movl imp_r_portalFineCull, %eax\n" /* line 1076 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfef8a0_000efa13\n"
        "leal 4(%ebx), %esi\n" /* tris, minmax */
        /* { scope 2 */
        "testl %ecx, %ecx\n" /* line 346 */
        "jle .Lfef8a0_000ef96a\n"
        "xorl %ebx, %ebx\n" /* occluder */
        "pxor %xmm2, %xmm2\n"
        ".Lfef8a0_000ef915:\n"
        "movzbl 0x13(%edx), %eax\n" /* line 348 */
        "cmpl %eax, %edi\n"
        "jg .Lfef8a0_000ef960\n"
        "movb $0xff, 0x13(%edx)\n" /* line 350 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%edx), %xmm1\n" /* line 351 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lfef8a0_000efa54\n"
        ".Lfef8a0_000ef960:\n"
        "addl $1, %ebx\n" /* line 346 | occluder */
        "addl $0x14, %edx\n"
        "cmpl %ebx, %ecx\n" /* occluder */
        "jne .Lfef8a0_000ef915\n"
        ".Lfef8a0_000ef96a:\n"
        "movl dpvsGlob+56, %eax\n" /* line 355 */
        "testl %eax, %eax\n"
        "jle .Lfef8a0_000efa13\n"
        "movl $0, -0x1c(%ebp)\n" /* occluderIndex */
        "pxor %xmm3, %xmm3\n"
        "movl -0x1c(%ebp), %edx\n" /* occluderIndex */
        ".Lfef8a0_000ef985:\n"
        "movl dpvsGlob+60, %eax\n" /* line 357 */
        "movl (%eax, %edx, 4), %ebx\n" /* occluder */
        "cmpl 0x18(%ebx), %edi\n" /* line 358 | occluder */
        "jg .Lfef8a0_000ef9fd\n"
        "movl 0x20(%ebx), %edx\n" /* line 361 | occluder */
        "movl 0x1c(%ebx), %eax\n" /* occluder */
        "testl %eax, %eax\n"
        "jle .Lfef8a0_000efa54\n"
        "xorl %ecx, %ecx\n"
        "movaps %xmm3, %xmm2\n"
        "jmp .Lfef8a0_000ef9b6\n"
        ".Lfef8a0_000ef9a7:\n"
        "addl $1, %ecx\n"
        "addl $0x14, %edx\n"
        "cmpl 0x1c(%ebx), %ecx\n" /* occluder */
        "jge .Lfef8a0_000efa54\n"
        ".Lfef8a0_000ef9b6:\n"
        "movzbl 0x13(%edx), %eax\n" /* line 363 */
        "cmpl %eax, %edi\n"
        "jg .Lfef8a0_000ef9a7\n"
        "movb $0xff, 0x13(%edx)\n" /* line 365 */
        /* { scope 3 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "addss 0xc(%edx), %xmm1\n" /* line 366 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lfef8a0_000ef9a7\n"
        ".Lfef8a0_000ef9fd:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 355 | occluderIndex */
        "movl -0x1c(%ebp), %ecx\n" /* occluderIndex */
        "cmpl dpvsGlob+56, %ecx\n"
        "jge .Lfef8a0_000efa13\n"
        "movl %ecx, %edx\n"
        "jmp .Lfef8a0_000ef985\n"
        /* } scope */
        /* { scope 2 */
        ".Lfef8a0_000efa13:\n"
        "movl imp_rg, %ebx\n" /* line 580 | occluder */
        "movl 0x3198(%ebx), %edx\n" /* occluder */
        "movl imp_scene, %esi\n" /* minmax */
        "movl (%esi), %eax\n" /* minmax */
        "movl -0x20(%ebp), %ecx\n"
        "movl %eax, (%ecx, %edx)\n"
        "movl imp_rgp, %ebx\n" /* line 581 | occluder */
        "movl 0x109c(%ebx), %eax\n" /* occluder */
        "movl -0x24(%ebp), %edx\n"
        "addl 0x14(%eax), %edx\n"
        "movzwl 6(%edx), %eax\n" /* line 584 */
        "addl $0x800, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll R_AddDrawSurfForSurface\n"
        /* } scope */
        /* } scope */
        ".Lfef8a0_000efa54:\n"
        "addl $0x2c, %esp\n" /* line 1085 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1088 */
static __attribute__((naked))
void R_AddAabbTreeSurfaces_r(const DpvsPlane *planes, int planeCount, int stackLevel)
{
    __asm__ __volatile__ (
        ".Lfefa5c_000efa5c:\n"
        "pushl %ebp\n" /* line 1088 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %edi\n" /* tree */
        "movl %edx, -0x3c(%ebp)\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl 8(%ebp), %esi\n" /* stackLevel */
        /* { scope 1: occluded, occluderIndex, recursionNeeded, smodelIndex */
        /* { scope 2 */
        "testl %ecx, %ecx\n" /* line 415 */
        "jle .Lfefa5c_000efad0\n"
        "xorl %ecx, %ecx\n"
        "pxor %xmm2, %xmm2\n"
        ".Lfefa5c_000efa7a:\n"
        "movzbl 0x13(%edx), %eax\n" /* line 417 */
        "cmpl %eax, %esi\n"
        "jg .Lfefa5c_000efac5\n"
        "movb $0xff, 0x13(%edx)\n" /* line 419 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %edi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%edx), %xmm1\n" /* line 420 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lfefa5c_000efc36\n"
        ".Lfefa5c_000efac5:\n"
        "addl $1, %ecx\n" /* line 415 */
        "addl $0x14, %edx\n"
        "cmpl %ecx, -0x40(%ebp)\n"
        "jne .Lfefa5c_000efa7a\n"
        ".Lfefa5c_000efad0:\n"
        "movl dpvsGlob+56, %eax\n" /* line 424 */
        "testl %eax, %eax\n"
        "jle .Lfefa5c_000efb98\n"
        "movl $0, -0x2c(%ebp)\n" /* occluderIndex */
        "pxor %xmm3, %xmm3\n"
        ".Lfefa5c_000efae8:\n"
        "movl dpvsGlob+60, %eax\n" /* line 426 */
        "movl -0x2c(%ebp), %edx\n" /* occluderIndex */
        "movl (%eax, %edx, 4), %ecx\n"
        "cmpl 0x18(%ecx), %esi\n" /* line 427 */
        "jg .Lfefa5c_000efb85\n"
        "movl 0x20(%ecx), %edx\n" /* line 430 */
        "movl 0x1c(%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lfefa5c_000efc36\n"
        "xorl %ebx, %ebx\n"
        "movb $1, -0x2d(%ebp)\n" /* occluded */
        "movaps %xmm3, %xmm2\n"
        "jmp .Lfefa5c_000efb25\n"
        ".Lfefa5c_000efb15:\n"
        "movl %esi, %eax\n" /* line 438 */
        "movb %al, 0x13(%edx)\n"
        ".Lfefa5c_000efb1a:\n"
        "addl $1, %ebx\n" /* line 430 */
        "addl $0x14, %edx\n"
        "cmpl %ebx, 0x1c(%ecx)\n"
        "jle .Lfefa5c_000efb7b\n"
        ".Lfefa5c_000efb25:\n"
        "movzbl 0x13(%edx), %eax\n" /* line 432 */
        "cmpl %eax, %esi\n"
        "jg .Lfefa5c_000efb1a\n"
        "movb $0xff, 0x13(%edx)\n" /* line 434 */
        /* { scope 3 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %edi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "addss 0xc(%edx), %xmm1\n" /* line 435 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lfefa5c_000efb15\n"
        "movb $0, -0x2d(%ebp)\n" /* occluded */
        "addl $1, %ebx\n" /* line 430 */
        "addl $0x14, %edx\n"
        "cmpl %ebx, 0x1c(%ecx)\n"
        "jg .Lfefa5c_000efb25\n"
        ".Lfefa5c_000efb7b:\n"
        "cmpb $0, -0x2d(%ebp)\n" /* line 440 | occluded */
        "jne .Lfefa5c_000efc36\n"
        ".Lfefa5c_000efb85:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 424 | occluderIndex */
        "movl -0x2c(%ebp), %edx\n" /* occluderIndex */
        "cmpl %edx, dpvsGlob+56\n"
        "jg .Lfefa5c_000efae8\n"
        /* } scope */
        /* { scope 2 */
        ".Lfefa5c_000efb98:\n"
        "movl -0x40(%ebp), %eax\n" /* line 457 */
        "testl %eax, %eax\n"
        "jle .Lfefa5c_000efc3e\n"
        /* } scope */
        "movl -0x3c(%ebp), %edx\n" /* line 1097 */
        "xorl %ecx, %ecx\n"
        "movb $0, -0x4d(%ebp)\n" /* recursionNeeded */
        "pxor %xmm2, %xmm2\n"
        "jmp .Lfefa5c_000efbc2\n"
        /* { scope 2 */
        ".Lfefa5c_000efbb2:\n"
        "movl %esi, %eax\n" /* line 463 */
        "movb %al, 0x13(%edx)\n"
        ".Lfefa5c_000efbb7:\n"
        "addl $1, %ecx\n" /* line 457 */
        "addl $0x14, %edx\n"
        "cmpl %ecx, -0x40(%ebp)\n"
        "je .Lfefa5c_000efc20\n"
        ".Lfefa5c_000efbc2:\n"
        "movzbl 0x13(%edx), %eax\n" /* line 459 */
        "cmpl %eax, %esi\n"
        "jg .Lfefa5c_000efbb7\n"
        "movzbl 0x10(%edx), %eax\n" /* line 64 */
        "movl %edi, %ebx\n"
        "subl %eax, %ebx\n"
        "movss (%edx), %xmm1\n"
        "mulss 0xc(%ebx), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 65 */
        "movl %edi, %ebx\n"
        "subl %eax, %ebx\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x14(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 66 */
        "movl %edi, %ebx\n"
        "subl %eax, %ebx\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x1c(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%edx), %xmm1\n" /* line 462 */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lfefa5c_000efbb2\n"
        "movb $1, -0x4d(%ebp)\n" /* recursionNeeded */
        "addl $1, %ecx\n" /* line 457 */
        "addl $0x14, %edx\n"
        "cmpl %ecx, -0x40(%ebp)\n"
        "jne .Lfefa5c_000efbc2\n"
        ".Lfefa5c_000efc20:\n"
        "cmpb $0, -0x4d(%ebp)\n" /* line 467 | recursionNeeded */
        "je .Lfefa5c_000efc3e\n"
        /* } scope */
        ".Lfefa5c_000efc26:\n"
        "cmpl $0, 0x28(%edi)\n" /* line 1121 | tree */
        "je .Lfefa5c_000efd8e\n"
        "jg .Lfefa5c_000efddb\n" /* line 1123 */
        /* } scope */
        ".Lfefa5c_000efc36:\n"
        "addl $0x6c, %esp\n" /* line 1142 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: occluded, occluderIndex, recursionNeeded, smodelIndex */
        /* { scope 2 */
        ".Lfefa5c_000efc3e:\n"
        "movl dpvsGlob+56, %ecx\n" /* line 470 */
        "testl %ecx, %ecx\n"
        "jle .Lfefa5c_000efc68\n"
        "movl dpvsGlob+60, %ebx\n" /* line 472 */
        "movl (%ebx), %eax\n" /* line 473 */
        "cmpl 0x18(%eax), %esi\n"
        "jle .Lfefa5c_000efc26\n"
        "xorl %edx, %edx\n"
        "jmp .Lfefa5c_000efc61\n"
        ".Lfefa5c_000efc59:\n"
        "movl (%ebx, %edx, 4), %eax\n"
        "cmpl 0x18(%eax), %esi\n"
        "jle .Lfefa5c_000efc26\n"
        ".Lfefa5c_000efc61:\n"
        "addl $1, %edx\n" /* line 470 */
        "cmpl %ecx, %edx\n"
        "jne .Lfefa5c_000efc59\n"
        /* } scope */
        ".Lfefa5c_000efc68:\n"
        "cmpb $0, dpvsGlob+102\n" /* line 1107 */
        "je .Lfefa5c_000efe0b\n"
        "movl 0x20(%edi), %eax\n" /* line 1109 | tree */
        "testl %eax, %eax\n"
        "jle .Lfefa5c_000efe0b\n"
        "movl $0, -0x34(%ebp)\n" /* smodelChildIndex */
        "movl -0x34(%ebp), %edx\n" /* smodelChildIndex */
        "jmp .Lfefa5c_000efd05\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfefa5c_000efc8c:\n"
        "movl imp_r_showSModelNames, %eax\n" /* line 1568 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfefa5c_000efeba\n"
        ".Lfefa5c_000efc9d:\n"
        "movl -0x28(%ebp), %ebx\n" /* line 1571 | smodelIndex, sceneEnt */
        "movl %ebx, (%esp)\n" /* sceneEnt */
        "calll R_AddStaticModelToScene\n"
        "movl %eax, %esi\n" /* entIndex */
        "testl %eax, %eax\n" /* line 1572 */
        "js .Lfefa5c_000efcf5\n"
        "leal (%eax, %eax, 2), %ebx\n" /* line 1575 | sceneEnt */
        "leal (%eax, %ebx, 4), %ebx\n" /* sceneEnt */
        "movl imp_scene, %edx\n"
        "leal 0x5c4(%edx, %ebx, 4), %ebx\n" /* sceneEnt */
        "movl -0x28(%ebp), %eax\n" /* line 1576 | smodelIndex */
        "movl %eax, 8(%esp)\n"
        "leal (, %esi, 8), %eax\n"
        "subl %esi, %eax\n" /* entIndex */
        "leal (%esi, %eax, 4), %eax\n" /* entIndex */
        "movl 0x10(%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* sceneEnt */
        "calll R_SkinStaticModel\n"
        "movl $5, 0xc(%ebx)\n" /* line 1577 | sceneEnt */
        "movl %esi, (%esp)\n" /* line 1578 | entIndex */
        "calll R_AddXModelSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lfefa5c_000efcf5:\n"
        "addl $1, -0x34(%ebp)\n" /* line 1109 | smodelChildIndex */
        "movl -0x34(%ebp), %edx\n" /* smodelChildIndex */
        "cmpl %edx, 0x20(%edi)\n" /* tree */
        "jle .Lfefa5c_000efe0b\n"
        ".Lfefa5c_000efd05:\n"
        "movl 0x24(%edi), %eax\n" /* line 1110 | tree */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* smodelIndex */
        /* { scope 2 */
        /* { scope 3 */
        "movl imp_rg, %esi\n" /* line 1549 | entIndex */
        "movl 0x3194(%esi), %eax\n" /* entIndex */
        "movl -0x28(%ebp), %ecx\n" /* smodelIndex */
        "leal (%eax, %ecx, 8), %edx\n"
        "movl imp_scene, %eax\n" /* line 1550 */
        "movl (%eax), %eax\n"
        "cmpl %eax, (%edx)\n"
        "je .Lfefa5c_000efcf5\n"
        "movl %eax, (%edx)\n" /* line 1552 */
        "movl imp_rgp, %eax\n" /* line 1554 */
        "movl 0x109c(%eax), %eax\n"
        "leal (%ecx, %ecx, 2), %ebx\n" /* sceneEnt */
        "shll $5, %ebx\n" /* sceneEnt */
        "addl 0xf8(%eax), %ebx\n" /* sceneEnt */
        "pxor %xmm0, %xmm0\n" /* line 1555 */
        "ucomiss (%ebx), %xmm0\n" /* sceneEnt */
        "jp .Lfefa5c_000efd53\n"
        "je .Lfefa5c_000efc8c\n"
        ".Lfefa5c_000efd53:\n"
        "leal 0x317c(%esi), %eax\n" /* line 1558 | entIndex */
        "movl %eax, 4(%esp)\n"
        "leal 4(%ebx), %eax\n" /* sceneEnt */
        "movl %eax, (%esp)\n"
        "calll Vec3Distance\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "mulss 0x3188(%esi), %xmm0\n" /* line 1559 | entIndex */
        "addss 0x318c(%esi), %xmm0\n" /* entIndex */
        "ucomiss (%ebx), %xmm0\n" /* sceneEnt */
        "ja .Lfefa5c_000efcf5\n"
        "jmp .Lfefa5c_000efc8c\n"
        /* } scope */
        /* } scope */
        ".Lfefa5c_000efd8e:\n"
        "cmpb $0, dpvsGlob+102\n" /* line 1133 */
        "je .Lfefa5c_000efda2\n"
        "movl 0x20(%edi), %eax\n" /* line 1135 | tree */
        "testl %eax, %eax\n"
        "jg .Lfefa5c_000efe8a\n"
        ".Lfefa5c_000efda2:\n"
        "movl 0x1c(%edi), %ebx\n" /* line 1139 | tree, surfIndex */
        "movl 0x18(%edi), %eax\n" /* tree */
        "testl %eax, %eax\n"
        "jle .Lfefa5c_000efc36\n"
        "addl $1, %esi\n" /* childIndex */
        "movl %esi, -0x1c(%ebp)\n" /* childIndex */
        "xorl %esi, %esi\n" /* childIndex */
        ".Lfefa5c_000efdb8:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1140 */
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* surfIndex */
        "calll R_AddWorldSurfaceWithCull\n"
        "addl $1, %esi\n" /* line 1139 | childIndex */
        "addl $1, %ebx\n" /* surfIndex */
        "cmpl 0x18(%edi), %esi\n" /* tree, childIndex */
        "jl .Lfefa5c_000efdb8\n"
        "jmp .Lfefa5c_000efc36\n"
        ".Lfefa5c_000efddb:\n"
        "addl $1, %esi\n" /* line 1123 | childIndex */
        "movl %esi, -0x24(%ebp)\n" /* childIndex */
        "xorl %esi, %esi\n" /* childIndex */
        "xorl %ebx, %ebx\n" /* surfIndex */
        ".Lfefa5c_000efde5:\n"
        "movl %ebx, %eax\n" /* line 1124 | surfIndex */
        "addl 0x2c(%edi), %eax\n" /* tree */
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl -0x3c(%ebp), %edx\n"
        "calll R_AddAabbTreeSurfaces_r\n"
        "addl $1, %esi\n" /* line 1123 | childIndex */
        "addl $0x30, %ebx\n" /* surfIndex */
        "cmpl 0x28(%edi), %esi\n" /* tree, childIndex */
        "jl .Lfefa5c_000efde5\n"
        "jmp .Lfefa5c_000efc36\n"
        ".Lfefa5c_000efe0b:\n"
        "movl 0x1c(%edi), %eax\n" /* line 1113 | tree */
        "movl 0x18(%edi), %edx\n" /* tree */
        "testl %edx, %edx\n"
        "jle .Lfefa5c_000efc36\n"
        "leal (, %eax, 4), %ebx\n" /* line 1088 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal (, %eax, 4), %esi\n" /* stackLevel */
        "movl $0, -0x38(%ebp)\n" /* surfNodeIndex */
        ".Lfefa5c_000efe31:\n"
        "movl %ebx, %edx\n" /* line 1115 | surfIndex */
        "movl imp_rg, %ecx\n"
        "addl 0x3198(%ecx), %edx\n"
        "movl imp_scene, %ecx\n"
        "movl (%ecx), %eax\n"
        "cmpl %eax, (%edx)\n"
        "je .Lfefa5c_000efe73\n"
        /* { scope 2 */
        "movl %eax, (%edx)\n" /* line 580 */
        "movl imp_rgp, %edx\n" /* line 581 */
        "movl 0x109c(%edx), %eax\n"
        "movl %esi, %edx\n"
        "addl 0x14(%eax), %edx\n"
        "movzwl 6(%edx), %eax\n" /* line 584 */
        "addl $0x800, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll R_AddDrawSurfForSurface\n"
        /* } scope */
        ".Lfefa5c_000efe73:\n"
        "addl $1, -0x38(%ebp)\n" /* line 1113 | surfNodeIndex */
        "addl $4, %ebx\n" /* surfIndex */
        "addl $0xc, %esi\n" /* childIndex */
        "movl -0x38(%ebp), %ecx\n" /* surfNodeIndex */
        "cmpl 0x18(%edi), %ecx\n" /* tree */
        "jl .Lfefa5c_000efe31\n"
        "jmp .Lfefa5c_000efc36\n"
        ".Lfefa5c_000efe8a:\n"
        "leal 1(%esi), %edx\n" /* line 1135 | childIndex */
        "movl %edx, -0x20(%ebp)\n"
        "xorl %ebx, %ebx\n" /* surfIndex */
        "movl %edx, %ecx\n"
        "jmp .Lfefa5c_000efe99\n"
        ".Lfefa5c_000efe96:\n"
        "movl -0x20(%ebp), %ecx\n"
        ".Lfefa5c_000efe99:\n"
        "movl 0x24(%edi), %eax\n" /* line 1136 | tree */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %ecx, (%esp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl -0x3c(%ebp), %edx\n"
        "calll R_AddStaticModelWithCull\n"
        "addl $1, %ebx\n" /* line 1135 | surfIndex */
        "cmpl 0x20(%edi), %ebx\n" /* tree, surfIndex */
        "jl .Lfefa5c_000efe96\n"
        "jmp .Lfefa5c_000efda2\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfefa5c_000efeba:\n"
        "movl 0x10(%ebx), %eax\n" /* line 1569 | sceneEnt */
        "movl %eax, (%esp)\n"
        "calll XModelGetName\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x3e99999a, 0xc(%esp)\n"
        "movl imp_colorWhite, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 4(%ebx), %eax\n" /* sceneEnt */
        "movl %eax, 4(%esp)\n"
        "movl imp_frontEndDataOut, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugString\n"
        "jmp .Lfefa5c_000efc9d\n"
    );
}

/* line 1907 */
static __attribute__((naked))
int R_GetFurtherCellList_r(const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t (*v)[128], const GfxCell * *list, int count)
{
    __asm__ __volatile__ (
        ".Lfefefa_000efefa:\n"
        "pushl %ebp\n" /* line 1907 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %edi\n" /* cell */
        "movl %edx, -0x7c(%ebp)\n"
        "movl %ecx, -0x80(%ebp)\n"
        "movl 0x14(%ebp), %esi\n" /* count */
        /* { scope 1: c, v, occluderIndex, planeIndex, ... */
        "movl 0x20(%eax), %ecx\n" /* line 1912 */
        "testl %ecx, %ecx\n"
        "jle .Lfefefa_000eff5b\n"
        "movl $0, -0x78(%ebp)\n" /* portalIndex */
        "movl $0, -0x2c(%ebp)\n"
        ".Lfefefa_000eff26:\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 1914 | portal */
        "addl 0x24(%edi), %ebx\n" /* cell, portal */
        "movl 0x1c(%ebx), %edx\n" /* portal */
        /* { scope 2: planeCount */
        /* { scope 3: v */
        "testl %esi, %esi\n" /* line 1891 */
        "jle .Lfefefa_000eff68\n"
        "movl 0x10(%ebp), %eax\n" /* line 1893 | list */
        "cmpl (%eax), %edx\n"
        "je .Lfefefa_000eff4b\n"
        "xorl %eax, %eax\n"
        ".Lfefefa_000eff3c:\n"
        "addl $1, %eax\n" /* line 1891 */
        "cmpl %eax, %esi\n"
        "je .Lfefefa_000eff68\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1893 | list */
        "cmpl (%ecx, %eax, 4), %edx\n"
        "jne .Lfefefa_000eff3c\n"
        /* } scope */
        /* } scope */
        ".Lfefefa_000eff4b:\n"
        "addl $1, -0x78(%ebp)\n" /* line 1912 | portalIndex */
        "addl $0x44, -0x2c(%ebp)\n"
        "movl -0x78(%ebp), %eax\n" /* portalIndex */
        "cmpl 0x20(%edi), %eax\n" /* cell */
        "jl .Lfefefa_000eff26\n"
        /* } scope */
        ".Lfefefa_000eff5b:\n"
        "movl %esi, %eax\n" /* line 1926 | count */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: c, v, occluderIndex, planeIndex, ... */
        ".Lfefefa_000eff68:\n"
        "cmpb $0, 1(%ebx)\n" /* line 1814 */
        "jne .Lfefefa_000eff4b\n"
        "leal 8(%ebx), %eax\n" /* line 220 */
        "movss 8(%ebx), %xmm1\n" /* line 1816 */
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
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm1\n"
        "ja .Lfefefa_000eff4b\n"
        "movl 8(%ebp), %edx\n" /* line 966 | planeCount */
        "testl %edx, %edx\n"
        "je .Lfefefa_000f0050\n"
        /* { scope 2: planeCount */
        "movl 0x20(%ebx), %edx\n" /* line 954 */
        "movl %edx, -0x6c(%ebp)\n" /* v */
        "movzbl 0x24(%ebx), %ecx\n" /* line 955 */
        "movb %cl, -0x71(%ebp)\n"
        "movzbl %cl, %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* c */
        "addl $4, %edx\n" /* line 304 */
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n" /* v */
        "addl $8, %edx\n"
        "movl %edx, -0x64(%ebp)\n"
        "movl -0x80(%ebp), %edx\n"
        "movl $0, -0x30(%ebp)\n"
        ".Lfefefa_000efff1:\n"
        "cmpb $0, -0x71(%ebp)\n" /* line 955 */
        "je .Lfefefa_000eff4b\n"
        "movss (%edx), %xmm6\n" /* line 304 */
        "movss 4(%edx), %xmm5\n"
        "movss 8(%edx), %xmm4\n"
        "movss 0xc(%edx), %xmm2\n" /* line 42 */
        "movaps %xmm6, %xmm0\n" /* line 957 */
        "movl -0x6c(%ebp), %eax\n" /* v */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "movl -0x68(%ebp), %ecx\n" /* plane */
        "mulss (%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "movl -0x64(%ebp), %eax\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfefefa_000f0294\n"
        /* } scope */
        ".Lfefefa_000f0041:\n"
        "addl $0x14, %edx\n" /* line 966 */
        "addl $1, -0x30(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* planeCount */
        "cmpl %eax, -0x30(%ebp)\n"
        "jne .Lfefefa_000efff1\n"
        /* { scope 2: planeCount */
        ".Lfefefa_000f0050:\n"
        "movl dpvsGlob+56, %ecx\n" /* line 1658 */
        "movl %ecx, -0x60(%ebp)\n"
        "testl %ecx, %ecx\n"
        "jle .Lfefefa_000f0136\n"
        "movl dpvsGlob+60, %eax\n" /* line 1660 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl $0, -0x58(%ebp)\n" /* occluderIndex */
        "movl %eax, %ecx\n"
        "movl -0x58(%ebp), %edx\n" /* occluderIndex */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* planeCount */
        "movl 0x20(%eax), %ecx\n"
        /* { scope 3: v */
        "testl %edx, %edx\n" /* line 977 */
        "je .Lfefefa_000eff4b\n"
        /* { scope 4 */
        ".Lfefefa_000f0089:\n"
        "movl 0x20(%ebx), %eax\n" /* line 954 */
        "movl %eax, -0x4c(%ebp)\n" /* v */
        "movzbl 0x24(%ebx), %edx\n" /* line 955 */
        "movb %dl, -0x4d(%ebp)\n"
        "movzbl %dl, %eax\n"
        /* { scope 5 */
        "movl -0x4c(%ebp), %edx\n" /* line 304 | v */
        "addl $4, %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl -0x4c(%ebp), %edx\n" /* v */
        "addl $8, %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "movl $0, -0x34(%ebp)\n"
        "subl $1, %eax\n"
        "movl %eax, -0x88(%ebp)\n"
        /* } scope */
        ".Lfefefa_000f00bb:\n"
        "cmpb $0, -0x4d(%ebp)\n" /* line 955 */
        "je .Lfefefa_000f027c\n"
        /* { scope 5 */
        "movss (%ecx), %xmm7\n" /* line 304 */
        "movss 4(%ecx), %xmm6\n"
        "movss 8(%ecx), %xmm5\n"
        "movss 0xc(%ecx), %xmm4\n" /* line 42 */
        /* } scope */
        "movaps %xmm7, %xmm0\n" /* line 957 */
        "movl -0x4c(%ebp), %eax\n" /* v */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "movl -0x48(%ebp), %edx\n"
        "mulss (%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "movl -0x44(%ebp), %eax\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lfefefa_000f023a\n"
        /* } scope */
        /* } scope */
        ".Lfefefa_000f010b:\n"
        "addl $1, -0x58(%ebp)\n" /* line 1658 | occluderIndex */
        "movl -0x60(%ebp), %ecx\n"
        "cmpl %ecx, -0x58(%ebp)\n" /* occluderIndex */
        "je .Lfefefa_000f0136\n"
        "movl -0x5c(%ebp), %ecx\n"
        "movl -0x58(%ebp), %edx\n" /* line 1660 | occluderIndex */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* planeCount */
        "movl 0x20(%eax), %ecx\n"
        /* { scope 3: v */
        "testl %edx, %edx\n" /* line 977 */
        "je .Lfefefa_000eff4b\n"
        "jmp .Lfefefa_000f0089\n"
        /* } scope */
        /* } scope */
        /* { scope 2: planeCount */
        ".Lfefefa_000f0136:\n"
        "movzbl 0x24(%ebx), %eax\n" /* line 1837 */
        "movl %eax, -0x1c(%ebp)\n" /* vertCount */
        "movl 0x20(%ebx), %eax\n" /* line 1838 */
        "movl 0xc(%ebp), %edx\n" /* line 1841 | v */
        "movl %edx, (%esp)\n"
        "movl -0x7c(%ebp), %ecx\n"
        "leal -0x1c(%ebp), %edx\n" /* vertCount */
        "calll R_ChopPortalWinding\n"
        "movl %eax, -0x3c(%ebp)\n" /* w */
        "movl -0x1c(%ebp), %eax\n" /* line 1842 | vertCount */
        "testl %eax, %eax\n"
        "je .Lfefefa_000eff4b\n"
        "movl dpvsGlob+44, %ecx\n" /* line 1847 */
        "testl %ecx, %ecx\n"
        "je .Lfefefa_000f019b\n"
        "movl $0x600, %eax\n" /* line 1849 */
        "movl -0x3c(%ebp), %edx\n" /* w */
        "cmpl %edx, 0xc(%ebp)\n" /* v */
        "movl $0, %edx\n"
        "cmovnel %edx, %eax\n"
        "addl 0xc(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* vertCount */
        "movl -0x3c(%ebp), %eax\n" /* w */
        "calll R_ChopPortalWinding\n"
        "movl %eax, -0x3c(%ebp)\n" /* w */
        "movl -0x1c(%ebp), %eax\n" /* line 1850 | vertCount */
        "testl %eax, %eax\n"
        "je .Lfefefa_000eff4b\n"
        ".Lfefefa_000f019b:\n"
        "movl 8(%ebp), %eax\n" /* line 1855 | planeCount */
        "testl %eax, %eax\n"
        "jle .Lfefefa_000f01f6\n"
        "movl -0x80(%ebp), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl $0, -0x40(%ebp)\n" /* planeIndex */
        "jmp .Lfefefa_000f01b4\n"
        ".Lfefefa_000f01b1:\n"
        "movl -0x38(%ebp), %ecx\n"
        ".Lfefefa_000f01b4:\n"
        "movl $0x600, %eax\n" /* line 1857 */
        "movl 0xc(%ebp), %edx\n" /* v */
        "cmpl %edx, -0x3c(%ebp)\n" /* w */
        "movl $0, %edx\n"
        "cmovnel %edx, %eax\n"
        "addl 0xc(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* vertCount */
        "movl -0x3c(%ebp), %eax\n" /* w */
        "calll R_ChopPortalWinding\n"
        "movl %eax, -0x3c(%ebp)\n" /* w */
        "movl -0x1c(%ebp), %eax\n" /* line 1858 | vertCount */
        "testl %eax, %eax\n"
        "je .Lfefefa_000eff4b\n"
        "addl $1, -0x40(%ebp)\n" /* line 1855 | planeIndex */
        "addl $0x14, -0x38(%ebp)\n"
        "movl -0x40(%ebp), %ecx\n" /* planeIndex */
        "cmpl %ecx, 8(%ebp)\n" /* planeCount */
        "jne .Lfefefa_000f01b1\n"
        /* } scope */
        ".Lfefefa_000f01f6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1919 | vertCount */
        "testl %eax, %eax\n"
        "je .Lfefefa_000eff4b\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1902 */
        "movl 0x10(%ebp), %edx\n" /* list */
        "movl %eax, (%edx, %esi, 4)\n"
        "leal 1(%esi), %edx\n" /* line 1903 */
        "movl 0x1c(%ebx), %eax\n" /* line 1923 | portal */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* list */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* v */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* planeCount */
        "movl %ecx, (%esp)\n"
        "movl -0x80(%ebp), %ecx\n"
        "movl -0x7c(%ebp), %edx\n"
        "calll R_GetFurtherCellList_r\n"
        "movl %eax, %esi\n" /* count */
        "jmp .Lfefefa_000eff4b\n"
        /* { scope 2: planeCount */
        /* { scope 3: v */
        /* { scope 4 */
        ".Lfefefa_000f023a:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 957 | v */
        "xorl %eax, %eax\n"
        "jmp .Lfefefa_000f0274\n"
        /* { scope 5 */
        ".Lfefefa_000f0241:\n"
        "movaps %xmm5, %xmm0\n" /* line 42 */
        "mulss 0x14(%edx), %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss 0x10(%edx), %xmm1\n"
        "movaps %xmm7, %xmm2\n"
        "mulss 0xc(%edx), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "addl $1, %eax\n"
        "addl $0xc, %edx\n"
        /* } scope */
        "ucomiss %xmm3, %xmm0\n" /* line 957 */
        "ja .Lfefefa_000f010b\n"
        ".Lfefefa_000f0274:\n"
        "cmpl -0x88(%ebp), %eax\n" /* line 955 */
        "jne .Lfefefa_000f0241\n"
        /* } scope */
        ".Lfefefa_000f027c:\n"
        "addl $0x14, %ecx\n" /* line 977 */
        "addl $1, -0x34(%ebp)\n"
        "movl -0x54(%ebp), %edx\n" /* planeCount */
        "cmpl %edx, -0x34(%ebp)\n"
        "jne .Lfefefa_000f00bb\n"
        "jmp .Lfefefa_000eff4b\n"
        /* } scope */
        /* } scope */
        /* { scope 2: planeCount */
        ".Lfefefa_000f0294:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 957 | v */
        "movl $0, -0x8c(%ebp)\n"
        "movl -0x70(%ebp), %ecx\n" /* c, plane */
        "subl $1, %ecx\n" /* plane */
        "movl %ecx, -0x84(%ebp)\n" /* plane */
        "jmp .Lfefefa_000f02ec\n"
        ".Lfefefa_000f02af:\n"
        "movaps %xmm6, %xmm0\n" /* line 42 */
        "mulss 0xc(%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 0x10(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0x14(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "addl $1, -0x8c(%ebp)\n"
        "addl $0xc, %eax\n"
        "ucomiss %xmm3, %xmm0\n" /* line 957 */
        "ja .Lfefefa_000f0041\n"
        "movl -0x84(%ebp), %ecx\n" /* plane */
        ".Lfefefa_000f02ec:\n"
        "cmpl %ecx, -0x8c(%ebp)\n" /* line 955 */
        "jne .Lfefefa_000f02af\n"
        "jmp .Lfefefa_000eff4b\n"
    );
}

/* line 1646 */
static __attribute__((naked))
void R_AddVisibleSurfacesInCell(const GfxCell *cell, const DpvsPlane *planes, int planeCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1646 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl %ecx, -0x5c(%ebp)\n"

        /* { scope 1: sceneEnt, ent, count */
        "cmpb $0, dpvsGlob+100\n" /* line 1491 */
        "je .Lff02fa_000f0363\n"
        "movl 0x1c(%eax), %edi\n" /* line 1493 | tree */
        "movl 0x28(%edi), %edx\n" /* line 1495 | tree */
        "testl %edx, %edx\n"
        "jne .Lff02fa_000f073f\n"
        ".Lff02fa_000f0323:\n"
        "cmpb $0, dpvsGlob+102\n" /* line 1502 */
        "je .Lff02fa_000f0355\n"
        "movl 0x20(%edi), %ebx\n" /* line 1504 | tree, smodelChildIndex */
        "testl %ebx, %ebx\n" /* smodelChildIndex */
        "jle .Lff02fa_000f0355\n"
        "xorl %ebx, %ebx\n" /* smodelChildIndex */
        ".Lff02fa_000f0335:\n"
        "movl 0x24(%edi), %eax\n" /* line 1505 | tree */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl $0, (%esp)\n"
        "movl -0x5c(%ebp), %ecx\n"
        "movl -0x58(%ebp), %edx\n"
        "calll R_AddStaticModelWithCull\n"
        "addl $1, %ebx\n" /* line 1504 | smodelChildIndex */
        "cmpl 0x20(%edi), %ebx\n" /* tree, smodelChildIndex */
        "jl .Lff02fa_000f0335\n"
        ".Lff02fa_000f0355:\n"
        "movl 0x1c(%edi), %ebx\n" /* line 1508 | tree, smodelChildIndex */
        "movl 0x18(%edi), %eax\n" /* tree */
        "testl %eax, %eax\n"
        "jg .Lff02fa_000f0a9e\n"
        ".Lff02fa_000f0363:\n"
        "cmpb $0, dpvsGlob+101\n" /* line 1513 */
        "je .Lff02fa_000f037a\n"
        /* { scope 2: occluderIndex, occluderIndex, occluder, occluderIndex, ... */
        "movl -0x54(%ebp), %eax\n" /* line 1176 */
        "movl 0x38(%eax), %edi\n" /* modelRef */
        "testl %edi, %edi\n" /* modelRef */
        "jne .Lff02fa_000f05fc\n"
        /* } scope */
        /* } scope */
        ".Lff02fa_000f037a:\n"
        "cmpb $0, dpvsGlob+100\n" /* line 1649 */
        "je .Lff02fa_000f04ac\n"
        /* { scope 1: sceneEnt, ent, count */
        "movl -0x54(%ebp), %ebx\n" /* line 1637 | smodelChildIndex */
        "movl 0x28(%ebx), %ebx\n" /* smodelChildIndex */
        "movl %ebx, -0x2c(%ebp)\n" /* smodelChildIndex, count */
        "movl -0x54(%ebp), %eax\n"
        "movl 0x2c(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* cullGroup */
        "testl %ebx, %ebx\n" /* smodelChildIndex */
        "je .Lff02fa_000f04ac\n"
        "movl $0, -0x1c(%ebp)\n"
        ".Lff02fa_000f03a8:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 1640 | cullGroup */
        "movl (%ecx), %edx\n"
        "leal (, %edx, 4), %ebx\n" /* smodelChildIndex */
        "movl %ebx, -0x30(%ebp)\n" /* smodelChildIndex */
        "movl imp_rg, %ecx\n"
        "movl 0x319c(%ecx), %eax\n"
        "movl (%eax, %ebx), %eax\n"
        "movl imp_scene, %ebx\n" /* smodelChildIndex */
        "cmpl (%ebx), %eax\n" /* smodelChildIndex */
        "je .Lff02fa_000f0498\n"
        /* { scope 2: occluderIndex, occluderIndex, occluder, occluderIndex, ... */
        "movl imp_rgp, %eax\n" /* line 1526 */
        "movl 0x109c(%eax), %eax\n"
        "movl %edx, %esi\n" /* group */
        "shll $5, %esi\n" /* group */
        "addl 0xf0(%eax), %esi\n" /* group */
        /* { scope 3 */
        "movl -0x5c(%ebp), %eax\n" /* line 383 */
        "testl %eax, %eax\n"
        "jle .Lff02fa_000f0783\n"
        "movl -0x58(%ebp), %eax\n" /* line 385 */
        "movb $0xff, 0x13(%eax)\n"
        "movl -0x58(%ebp), %edx\n" /* line 51 */
        "movzbl 0x10(%edx), %eax\n"
        "movss (%edx), %xmm1\n"
        "mulss (%esi, %eax), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss (%esi, %eax), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "addss 0xc(%edx), %xmm0\n" /* line 386 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lff02fa_000f0498\n"
        "movl %edx, %ecx\n"
        "addl $0x27, %ecx\n"
        "movl $1, %ebx\n" /* planeIndex */
        ".Lff02fa_000f0448:\n"
        "cmpl -0x5c(%ebp), %ebx\n" /* line 383 | planeIndex */
        "je .Lff02fa_000f0783\n"
        "movb $0xff, (%ecx)\n" /* line 385 */
        "movl %ecx, %edx\n" /* line 1646 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x13(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss (%eax, %esi), %xmm1\n"
        "mulss -0xf(%ecx), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss (%eax, %esi), %xmm0\n"
        "mulss -0xb(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %ebx\n"
        "addl $0x14, %ecx\n"
        "addss -7(%edx), %xmm1\n" /* line 386 */
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lff02fa_000f0448\n"
        /* } scope */
        /* } scope */
        ".Lff02fa_000f0498:\n"
        "addl $4, -0x28(%ebp)\n" /* line 1637 | cullGroup */
        "addl $1, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* count */
        "cmpl %edx, -0x1c(%ebp)\n"
        "jne .Lff02fa_000f03a8\n"
        /* } scope */
        ".Lff02fa_000f04ac:\n"
        "addl $0x6c, %esp\n" /* line 1651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: sceneEnt, ent, count */
        /* { scope 2: occluderIndex, occluderIndex, occluder, occluderIndex, ... */
        ".Lff02fa_000f04b4:\n"
        "cmpb $0, dpvsGlob+103\n" /* line 1187 */
        "je .Lff02fa_000f05f1\n"
        "movl 0xc(%ebx), %eax\n" /* line 1189 | planeIndex */
        "subl $1, %eax\n"
        "jle .Lff02fa_000f0ada\n"
        ".Lff02fa_000f04cd:\n"
        "movl -0x50(%ebp), %esi\n" /* line 1195 | sceneEnt, minmax */
        "addl $0x14, %esi\n" /* minmax */
        /* { scope 3 */
        "movl -0x5c(%ebp), %eax\n" /* line 383 */
        "testl %eax, %eax\n"
        "jg .Lff02fa_000f09ed\n"
        ".Lff02fa_000f04de:\n"
        "movl dpvsGlob+56, %ebx\n" /* line 390 | planeIndex */
        "testl %ebx, %ebx\n" /* planeIndex */
        "jle .Lff02fa_000f05bd\n"
        "movl $0, -0x40(%ebp)\n" /* occluderIndex */
        "movl -0x40(%ebp), %edx\n" /* occluderIndex */
        ".Lff02fa_000f04f6:\n"
        "movl dpvsGlob+60, %eax\n" /* line 392 */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* occluder */
        "movl 0x20(%eax), %edx\n" /* line 394 */
        "movl 0x1c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lff02fa_000f05f1\n"
        "movb $0xff, 0x13(%edx)\n" /* line 396 */
        /* { scope 4 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "addss 0xc(%edx), %xmm1\n" /* line 397 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lff02fa_000f05aa\n"
        "leal 0x27(%edx), %ecx\n" /* line 398 */
        "xorl %ebx, %ebx\n" /* planeIndex */
        ".Lff02fa_000f0557:\n"
        "addl $1, %ebx\n" /* line 394 | planeIndex */
        "movl -0x3c(%ebp), %eax\n" /* occluder */
        "cmpl 0x1c(%eax), %ebx\n" /* planeIndex */
        "jge .Lff02fa_000f05f1\n"
        "movb $0xff, (%ecx)\n" /* line 396 */
        "movl %ecx, %edx\n" /* line 1646 */
        /* { scope 4 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x13(%ecx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0xf(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0xb(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x14, %ecx\n"
        /* } scope */
        "addss -7(%edx), %xmm1\n" /* line 397 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lff02fa_000f0557\n"
        ".Lff02fa_000f05aa:\n"
        "addl $1, -0x40(%ebp)\n" /* line 390 | occluderIndex */
        "movl -0x40(%ebp), %edx\n" /* occluderIndex */
        "cmpl dpvsGlob+56, %edx\n"
        "jl .Lff02fa_000f04f6\n"
        /* } scope */
        ".Lff02fa_000f05bd:\n"
        "movl -0x50(%ebp), %ecx\n" /* line 1200 | sceneEnt */
        "movl 8(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_CullIn\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 1201 | ent, planeIndex */
        "movl %ebx, 4(%esp)\n" /* planeIndex */
        "movl -0x50(%ebp), %eax\n" /* sceneEnt */
        "movl %eax, (%esp)\n"
        "calll R_SkinSceneEnt\n"
        "movl -0x50(%ebp), %edx\n" /* line 1202 | sceneEnt */
        "movl $5, 0xc(%edx)\n"
        "movl (%edi), %eax\n" /* line 1204 | modelRef */
        "movl %eax, (%esp)\n"
        "calll R_AddXModelSurfaces\n"
        ".Lff02fa_000f05f1:\n"
        "movl 0x1c(%edi), %edi\n" /* line 1176 | modelRef */
        "testl %edi, %edi\n" /* modelRef */
        "je .Lff02fa_000f037a\n"
        ".Lff02fa_000f05fc:\n"
        "movl (%edi), %edx\n" /* line 1178 | modelRef */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl imp_scene, %ecx\n"
        "leal 0x5c4(%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* sceneEnt */
        "movl %eax, %ebx\n" /* line 1181 | planeIndex */
        "movl 0xc(%eax), %eax\n"
        "cmpl $5, %eax\n"
        "je .Lff02fa_000f05f1\n"
        "leal (, %edx, 8), %eax\n" /* line 1184 */
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x10(%ecx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* ent */
        "movl (%eax), %eax\n" /* line 1185 */
        "cmpl $1, %eax\n"
        "jle .Lff02fa_000f04b4\n"
        "cmpl $3, %eax\n" /* line 1206 */
        "jne .Lff02fa_000f05f1\n"
        "cmpb $0, dpvsGlob+104\n" /* line 1208 */
        "je .Lff02fa_000f05f1\n"
        "leal 4(%edi), %esi\n" /* line 1209 | modelRef, minmax */
        /* { scope 3 */
        "movl -0x5c(%ebp), %eax\n" /* line 383 */
        "testl %eax, %eax\n"
        "jg .Lff02fa_000f0941\n"
        ".Lff02fa_000f065a:\n"
        "movl dpvsGlob+56, %eax\n" /* line 390 */
        "testl %eax, %eax\n"
        "jle .Lff02fa_000f0ac4\n"
        "movl $0, -0x38(%ebp)\n" /* occluderIndex */
        "movl -0x38(%ebp), %ecx\n" /* occluderIndex */
        ".Lff02fa_000f0671:\n"
        "movl dpvsGlob+60, %eax\n" /* line 392 */
        "movl (%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* occluder */
        "movl 0x20(%eax), %edx\n" /* line 394 */
        "movl 0x1c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lff02fa_000f05f1\n"
        "movb $0xff, 0x13(%edx)\n" /* line 396 */
        /* { scope 4 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "addss 0xc(%edx), %xmm1\n" /* line 397 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lff02fa_000f0725\n"
        "leal 0x27(%edx), %ecx\n" /* line 398 */
        "xorl %ebx, %ebx\n" /* planeIndex */
        ".Lff02fa_000f06d2:\n"
        "addl $1, %ebx\n" /* line 394 | planeIndex */
        "movl -0x34(%ebp), %eax\n" /* occluder */
        "cmpl 0x1c(%eax), %ebx\n" /* planeIndex */
        "jge .Lff02fa_000f05f1\n"
        "movb $0xff, (%ecx)\n" /* line 396 */
        "movl %ecx, %edx\n" /* line 1646 */
        /* { scope 4 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x13(%ecx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0xf(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0xb(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x14, %ecx\n"
        /* } scope */
        "addss -7(%edx), %xmm1\n" /* line 397 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lff02fa_000f06d2\n"
        ".Lff02fa_000f0725:\n"
        "addl $1, -0x38(%ebp)\n" /* line 390 | occluderIndex */
        "movl -0x38(%ebp), %edx\n" /* occluderIndex */
        "cmpl dpvsGlob+56, %edx\n"
        "jge .Lff02fa_000f0ac4\n"
        "movl %edx, %ecx\n"
        "jmp .Lff02fa_000f0671\n"
        /* } scope */
        /* } scope */
        ".Lff02fa_000f073f:\n"
        "movl imp_r_portalFineCull, %eax\n" /* line 1495 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lff02fa_000f0323\n"
        "testl %edx, %edx\n" /* line 1497 */
        "jle .Lff02fa_000f0363\n"
        "xorl %esi, %esi\n" /* surfNodeIndex */
        "xorl %ebx, %ebx\n" /* smodelChildIndex */
        ".Lff02fa_000f075c:\n"
        "movl %ebx, %eax\n" /* line 1498 | smodelChildIndex */
        "addl 0x2c(%edi), %eax\n" /* tree */

        "movl $0, (%esp)\n"
        "movl -0x5c(%ebp), %ecx\n"
        "movl -0x58(%ebp), %edx\n"
        "calll R_AddAabbTreeSurfaces_r\n"
        "addl $1, %esi\n" /* line 1497 | surfNodeIndex */
        "addl $0x30, %ebx\n" /* smodelChildIndex */
        "cmpl 0x28(%edi), %esi\n" /* tree, surfNodeIndex */
        "jl .Lff02fa_000f075c\n"
        "jmp .Lff02fa_000f0363\n"
        /* } scope */
        /* { scope 1: sceneEnt, ent, count */
        /* { scope 2: occluderIndex, occluderIndex, occluder, occluderIndex, ... */
        /* { scope 3 */
        ".Lff02fa_000f0783:\n"
        "movl dpvsGlob+56, %eax\n" /* line 390 */
        "testl %eax, %eax\n"
        "jle .Lff02fa_000f085e\n"
        "movl $0, -0x20(%ebp)\n" /* occluderIndex */
        "movl -0x20(%ebp), %ecx\n" /* occluderIndex */
        ".Lff02fa_000f079a:\n"
        "movl dpvsGlob+60, %eax\n" /* line 392 */
        "movl (%eax, %ecx, 4), %edi\n" /* occluder */
        "movl 0x20(%edi), %edx\n" /* line 394 | occluder */
        "movl 0x1c(%edi), %eax\n" /* occluder */
        "testl %eax, %eax\n"
        "jle .Lff02fa_000f0498\n"
        "movb $0xff, 0x13(%edx)\n" /* line 396 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%edx), %xmm1\n" /* line 397 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lff02fa_000f0848\n"
        "leal 0x27(%edx), %ecx\n" /* line 398 */
        "xorl %ebx, %ebx\n" /* planeIndex */
        ".Lff02fa_000f07f8:\n"
        "addl $1, %ebx\n" /* line 394 | planeIndex */
        "cmpl 0x1c(%edi), %ebx\n" /* occluder, planeIndex */
        "jge .Lff02fa_000f0498\n"
        "movb $0xff, (%ecx)\n" /* line 396 */
        "movl %ecx, %edx\n" /* line 1646 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x13(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss (%eax, %esi), %xmm1\n"
        "mulss -0xf(%ecx), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss (%eax, %esi), %xmm0\n"
        "mulss -0xb(%ecx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "addl $0x14, %ecx\n"
        "addss -7(%edx), %xmm0\n" /* line 397 */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lff02fa_000f07f8\n"
        ".Lff02fa_000f0848:\n"
        "addl $1, -0x20(%ebp)\n" /* line 390 | occluderIndex */
        "movl -0x20(%ebp), %ebx\n" /* occluderIndex, planeIndex */
        "cmpl dpvsGlob+56, %ebx\n" /* planeIndex */
        "jge .Lff02fa_000f085e\n"
        "movl %ebx, %ecx\n" /* planeIndex */
        "jmp .Lff02fa_000f079a\n"
        /* } scope */
        ".Lff02fa_000f085e:\n"
        "movl imp_r_showPortals, %eax\n" /* line 1531 */
        "movl (%eax), %eax\n"
        "testb $1, 8(%eax)\n"
        "jne .Lff02fa_000f0914\n"
        ".Lff02fa_000f086f:\n"
        "movl imp_rg, %eax\n" /* line 1534 */
        "movl 0x319c(%eax), %edx\n"
        "movl imp_scene, %ecx\n"
        "movl (%ecx), %eax\n"
        "movl -0x30(%ebp), %ebx\n" /* smodelChildIndex */
        "movl %eax, (%ebx, %edx)\n" /* smodelChildIndex */
        "movl 0x1c(%esi), %eax\n" /* line 1536 | group */
        "movl 0x18(%esi), %edi\n" /* group, tree */
        "testl %edi, %edi\n" /* tree */
        "jle .Lff02fa_000f0498\n"
        "leal (, %eax, 4), %edi\n" /* line 1646 | tree */
        "leal (%eax, %eax, 2), %eax\n"
        "leal (, %eax, 4), %ebx\n" /* smodelChildIndex */
        "movl $0, -0x24(%ebp)\n" /* count */
        /* { scope 3 */
        /* { scope 4 */
        ".Lff02fa_000f08ae:\n"
        "movl imp_rg, %eax\n" /* line 580 */
        "movl 0x3198(%eax), %edx\n"
        "movl imp_scene, %ecx\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx, %edi)\n"
        "movl imp_rgp, %eax\n" /* line 581 */
        "movl 0x109c(%eax), %eax\n"
        "movl %ebx, %edx\n" /* planeIndex */
        "addl 0x14(%eax), %edx\n"
        "movzwl 6(%edx), %eax\n" /* line 584 */
        "addl $0x800, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll R_AddDrawSurfForSurface\n"
        /* } scope */
        /* } scope */
        "addl $1, -0x24(%ebp)\n" /* line 1536 | count */
        "addl $4, %edi\n" /* tree */
        "addl $0xc, %ebx\n" /* smodelChildIndex */
        "movl -0x24(%ebp), %eax\n" /* count */
        "cmpl 0x18(%esi), %eax\n" /* group */
        "jl .Lff02fa_000f08ae\n"
        /* } scope */
        "addl $4, -0x28(%ebp)\n" /* line 1637 | cullGroup */
        "addl $1, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* count */
        "cmpl %edx, -0x1c(%ebp)\n"
        "jne .Lff02fa_000f03a8\n"
        "jmp .Lff02fa_000f04ac\n"
        /* { scope 2: occluderIndex, occluderIndex, occluder, occluderIndex, ... */
        ".Lff02fa_000f0914:\n"
        "movl imp_colorLtYellow, %eax\n" /* line 1532 */
        "movl %eax, 0xc(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* group */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* group */
        "movl imp_frontEndDataOut, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugBox\n"
        "jmp .Lff02fa_000f086f\n"
        /* } scope */
        /* } scope */
        /* { scope 1: sceneEnt, ent, count */
        /* { scope 2: occluderIndex, occluderIndex, occluder, occluderIndex, ... */
        /* { scope 3 */
        ".Lff02fa_000f0941:\n"
        "movl -0x58(%ebp), %ecx\n" /* line 385 */
        "movb $0xff, 0x13(%ecx)\n"
        "movzbl 0x10(%ecx), %eax\n" /* line 51 */
        "movss (%ecx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%ecx), %eax\n" /* line 52 */
        "movss 4(%ecx), %xmm0\n"
        "mulss 4(%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%ecx), %eax\n" /* line 53 */
        "movss 8(%ecx), %xmm0\n"
        "mulss 4(%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%ecx), %xmm1\n" /* line 386 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lff02fa_000f05f1\n"
        "movl -0x58(%ebp), %ecx\n"
        "addl $0x27, %ecx\n"
        "movl $1, %ebx\n" /* planeIndex */
        ".Lff02fa_000f0998:\n"
        "cmpl %ebx, -0x5c(%ebp)\n" /* line 383 | planeIndex */
        "je .Lff02fa_000f065a\n"
        "movb $0xff, (%ecx)\n" /* line 385 */
        "movl %ecx, %edx\n" /* line 1646 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x13(%ecx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0xf(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0xb(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %ebx\n"
        "addl $0x14, %ecx\n"
        "addss -7(%edx), %xmm1\n" /* line 386 */
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lff02fa_000f0998\n"
        "jmp .Lff02fa_000f05f1\n"
        /* } scope */
        /* { scope 3 */
        ".Lff02fa_000f09ed:\n"
        "movl -0x58(%ebp), %eax\n" /* line 385 */
        "movb $0xff, 0x13(%eax)\n"
        "movl -0x58(%ebp), %edx\n" /* line 51 */
        "movzbl 0x10(%edx), %eax\n"
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "movl -0x50(%ebp), %ecx\n" /* sceneEnt */
        "mulss 0x14(%ecx, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss 0x14(%ecx, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%edx), %xmm1\n" /* line 386 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lff02fa_000f05f1\n"
        "movl %edx, %ecx\n"
        "addl $0x27, %ecx\n"
        "movl $1, %ebx\n" /* planeIndex */
        ".Lff02fa_000f0a49:\n"
        "cmpl -0x5c(%ebp), %ebx\n" /* line 383 | planeIndex */
        "je .Lff02fa_000f04de\n"
        "movb $0xff, (%ecx)\n" /* line 385 */
        "movl %ecx, %edx\n" /* line 1646 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x13(%ecx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0xf(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0xb(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %ebx\n"
        "addl $0x14, %ecx\n"
        "addss -7(%edx), %xmm1\n" /* line 386 */
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lff02fa_000f0a49\n"
        "jmp .Lff02fa_000f05f1\n"
        /* } scope */
        /* } scope */
        ".Lff02fa_000f0a9e:\n"
        "xorl %esi, %esi\n" /* line 1508 | surfNodeIndex */
        ".Lff02fa_000f0aa0:\n"
        "movl $0, (%esp)\n" /* line 1509 */
        "movl -0x5c(%ebp), %ecx\n"
        "movl -0x58(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* smodelChildIndex */
        "calll R_AddWorldSurfaceWithCull\n"
        "addl $1, %esi\n" /* line 1508 | surfNodeIndex */
        "addl $1, %ebx\n" /* smodelChildIndex */
        "cmpl %esi, 0x18(%edi)\n" /* surfNodeIndex, tree */
        "jg .Lff02fa_000f0aa0\n"
        "jmp .Lff02fa_000f0363\n"
        /* { scope 2: occluderIndex, occluderIndex, occluder, occluderIndex, ... */
        ".Lff02fa_000f0ac4:\n"
        "movl (%edi), %eax\n" /* line 1212 | modelRef */
        "movl %eax, 4(%esp)\n"
        "movl -0x50(%ebp), %ecx\n" /* sceneEnt */
        "movl %ecx, (%esp)\n"
        "calll R_AddBModelSurfaces\n"
        "jmp .Lff02fa_000f05f1\n"
        ".Lff02fa_000f0ada:\n"
        "leal 4(%edi), %esi\n" /* line 1189 | modelRef, minmax */
        /* { scope 3 */
        "movl -0x5c(%ebp), %eax\n" /* line 383 */
        "testl %eax, %eax\n"
        "jg .Lff02fa_000f0bcd\n"
        ".Lff02fa_000f0ae8:\n"
        "movl dpvsGlob+56, %eax\n" /* line 390 */
        "testl %eax, %eax\n"
        "jle .Lff02fa_000f0c78\n"
        "movl $0, -0x48(%ebp)\n" /* occluderIndex */
        "movl -0x48(%ebp), %ebx\n" /* occluderIndex, planeIndex */
        ".Lff02fa_000f0aff:\n"
        "movl dpvsGlob+60, %eax\n" /* line 392 */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* occluder */
        "movl 0x20(%eax), %edx\n" /* line 394 */
        "movl 0x1c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lff02fa_000f05f1\n"
        "movb $0xff, 0x13(%edx)\n" /* line 396 */
        /* { scope 4 */
        "movzbl 0x10(%edx), %eax\n" /* line 51 */
        "movss (%edx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%edx), %eax\n" /* line 52 */
        "movss 4(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%edx), %eax\n" /* line 53 */
        "movss 8(%edx), %xmm0\n"
        "mulss (%esi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "addss 0xc(%edx), %xmm1\n" /* line 397 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lff02fa_000f0bb3\n"
        "leal 0x27(%edx), %ecx\n" /* line 398 */
        "xorl %ebx, %ebx\n" /* planeIndex */
        ".Lff02fa_000f0b60:\n"
        "addl $1, %ebx\n" /* line 394 | planeIndex */
        "movl -0x44(%ebp), %eax\n" /* occluder */
        "cmpl 0x1c(%eax), %ebx\n" /* planeIndex */
        "jge .Lff02fa_000f05f1\n"
        "movb $0xff, (%ecx)\n" /* line 396 */
        "movl %ecx, %edx\n" /* line 1646 */
        /* { scope 4 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x13(%ecx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0xf(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0xb(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $0x14, %ecx\n"
        /* } scope */
        "addss -7(%edx), %xmm1\n" /* line 397 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lff02fa_000f0b60\n"
        ".Lff02fa_000f0bb3:\n"
        "addl $1, -0x48(%ebp)\n" /* line 390 | occluderIndex */
        "movl -0x48(%ebp), %edx\n" /* occluderIndex */
        "cmpl dpvsGlob+56, %edx\n"
        "jge .Lff02fa_000f0c78\n"
        "movl %edx, %ebx\n" /* planeIndex */
        "jmp .Lff02fa_000f0aff\n"
        ".Lff02fa_000f0bcd:\n"
        "movl -0x58(%ebp), %ebx\n" /* line 385 | planeIndex */
        "movb $0xff, 0x13(%ebx)\n" /* planeIndex */
        "movzbl 0x10(%ebx), %eax\n" /* line 51 */
        "movss (%ebx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl 0x11(%ebx), %eax\n" /* line 52 */
        "movss 4(%ebx), %xmm0\n"
        "mulss 4(%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl 0x12(%ebx), %eax\n" /* line 53 */
        "movss 8(%ebx), %xmm0\n"
        "mulss 4(%edi, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0xc(%ebx), %xmm1\n" /* line 386 | planeIndex */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lff02fa_000f05f1\n"
        "movl %ebx, %ecx\n" /* planeIndex */
        "addl $0x27, %ecx\n"
        "movl $1, %ebx\n" /* planeIndex */
        ".Lff02fa_000f0c23:\n"
        "cmpl -0x5c(%ebp), %ebx\n" /* line 383 | planeIndex */
        "je .Lff02fa_000f0ae8\n"
        "movb $0xff, (%ecx)\n" /* line 385 */
        "movl %ecx, %edx\n" /* line 1646 */
        "movzbl -3(%ecx), %eax\n" /* line 51 */
        "movss -0x13(%ecx), %xmm1\n"
        "mulss (%eax, %esi), %xmm1\n"
        "movzbl -2(%ecx), %eax\n" /* line 52 */
        "movss -0xf(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movzbl -1(%ecx), %eax\n" /* line 53 */
        "movss -0xb(%ecx), %xmm0\n"
        "mulss (%eax, %esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %ebx\n"
        "addl $0x14, %ecx\n"
        "addss -7(%edx), %xmm1\n" /* line 386 */
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lff02fa_000f0c23\n"
        "jmp .Lff02fa_000f05f1\n"
        /* } scope */
        ".Lff02fa_000f0c78:\n"
        "movl -0x50(%ebp), %ecx\n" /* line 1194 | sceneEnt */
        "movl 8(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_UsedDObjCalcPose\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 1195 | ent, planeIndex */
        "movl %ebx, 4(%esp)\n" /* planeIndex */
        "movl -0x50(%ebp), %eax\n" /* sceneEnt */
        "movl %eax, (%esp)\n"
        "calll R_UpdateXModelBounds\n"
        "jmp .Lff02fa_000f04cd\n"
    );
}

/* line 1965 */
static __attribute__((naked))
void R_VisitPortalsForCell(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, DpvsClipChildren clipChildren)
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
        "addl $0x249d18, %eax\n" /* "x;
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

/* line 2026 */
static __attribute__((naked))
void R_VisitPortals(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount)
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
        "addl $0x249d18, %eax\n" /* "x;
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
        "addl $0x249d18, %eax\n" /* "x;
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
        "addl $0x249d18, %eax\n" /* "x;
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

/* line 2293 */
__attribute__((naked))
void R_AddWorldSurfacesDpvs(const GfxViewParms *viewParms, int cameraCellIndex)
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
