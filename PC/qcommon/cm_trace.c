/* ASM dump from: cm_trace.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_trace.cpp */

#include "common_types.h"
#include "imports.h"
#include <math.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern void * Sys_GetValue(int key);
cmodel_t * CM_ClipHandleToModel(clipHandle_t handle);
static int CM_TestInLeafBrushNode_r(void);
static int CM_SightTraceThroughBrush(cbrush_t *brush);
static int CM_SightTraceThroughLeafBrushNode_r(const vec_t *p2);
static int CM_SightTraceThroughLeaf(trace_t *trace);
static int CM_TraceThroughLeafBrushNode_r(const vec_t *p2, trace_t *trace);
static int CM_SightTraceThroughTree(const traceWork_t *tw, const vec_t *p2, trace_t *trace);
static Bool CM_TraceThroughLeafBrushNode(void);
static qboolean CM_TraceSphereThroughSphere(const vec_t *vStationary, trace_t *trace);
static qboolean CM_SightTraceSphereThroughSphere(const vec_t *vStationary, trace_t *trace);
clipHandle_t CM_TempBoxModel(const vec_t *mins, const vec_t *maxs, int contents);
static int CM_TraceThroughTree(const vec_t *p2, trace_t *trace);
int CM_ContentsOfModel(clipHandle_t handle);
float CM_RadiusOfModel(clipHandle_t handle);
static int CM_Trace(trace_t *results, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask);
int CM_BoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask);
int CM_BoxSightTrace(int oldHitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask);
int CM_TransformedBoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles);
int CM_TransformedBoxTraceExternal(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles);
int CM_TransformedBoxSightTrace(int hitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, clipHandle_t model, int brushmask, const vec_t *origin, const vec_t *angles);

/* line 79 */
cmodel_t * CM_ClipHandleToModel(clipHandle_t handle)
{
    clipMap_t *cm = (clipMap_t *)imp_cm;
    if (handle < cm->numSubModels) {
        return &cm->cmodels[handle];
    }
    return *(cmodel_t **)((char *)Sys_GetValue(3) + 0x14); /* Sys_GetValue(3)->clipMap at 0x14 */
}

/* line 254 */
/* CM_TestInLeafBrushNode_r: register calling convention (eax=tw, edx=node, ecx=trace)
 * Recursive collision test against brush node tree.
 *
 * Node layout (cLeafBrushNode_t, 20 bytes):
 *   byte  0:   axis
 *   short 2:   leafBrushCount (<0 = has children, 0 = leaf with dist test, >0 = brush list)
 *   int   4:   contents
 *   float 8:   dist (when leafBrushCount<=0) / ptr to brush indices (when >0)
 *   u16  0x10: childOffset[0]
 *   u16  0x12: childOffset[1]
 *   0x14: next node (stride 20)
 */
static void __attribute_regparm__(3) CM_TestInLeafBrushNode_r_impl(traceWork_t *tw, byte *node, trace_t *trace)
{
    int k;

top:
    /* Check contents mask */
    if (!(tw->contents & ((cLeafBrushNode_t *)node)->contents))
        return;

    {
        short leafBrushCount = ((cLeafBrushNode_t *)node)->leafBrushCount;

        if (leafBrushCount == 0) {
            goto leaf_dist_test;
        }

        if (leafBrushCount > 0) {
            /* Brush list node */
            if (leafBrushCount <= 0)
                return;

            for (k = 0; k < (int)leafBrushCount; k++) {
                if (!(tw->contents & ((cLeafBrushNode_t *)node)->contents))
                    continue;

                {
                    /* Get brush pointer: node->data.leaf.brushes is pointer to unsigned short array */
                    unsigned short *brushIndices = ((cLeafBrushNode_t *)node)->data.leaf.brushes;
                    unsigned int brushIdx = brushIndices[k];
                    /* brush = cm->brushes + brushIdx */
                    clipMap_t *cm = (clipMap_t *)imp_cm;
                    cbrush_t *brush = &cm->brushes[brushIdx];

                    /* Check contents */
                    if (!(tw->contents & brush->contents))
                        goto next_brush;

                    /* AABB overlap test: tw->bounds[0] vs brush maxs, brush mins vs tw->bounds[1] */
                    if (tw->bounds[0][0] > brush->maxs[0])
                        goto next_brush;
                    if (tw->bounds[0][1] > brush->maxs[1])
                        goto next_brush;
                    if (tw->bounds[0][2] > brush->maxs[2])
                        goto next_brush;
                    if (brush->mins[0] > tw->bounds[1][0])
                        goto next_brush;
                    if (brush->mins[1] > tw->bounds[1][1])
                        goto next_brush;
                    if (brush->mins[2] > tw->bounds[1][2])
                        goto next_brush;

                    {
                        /* Side/plane tests */
                        cbrushside_t *sidesPtr = brush->sides;
                        int sideCount = brush->numsides;
                        int j;

                        if (sideCount == 0)
                            goto hit;

                        {
                            float tw_radius_z = tw->offsetZ;
                            float tw_offset = tw->radius;
                            float tw_x = tw->extents.start[0];
                            float tw_y = tw->extents.start[1];
                            float tw_z = tw->extents.start[2];

                            /* Test first plane */
                            {
                                cplane_t *plane = sidesPtr[0].plane;
                                float dot = tw_x * plane->normal[0]
                                          + tw_y * plane->normal[1]
                                          + tw_z * plane->normal[2];
                                float absNz = fabsf(tw_radius_z * plane->normal[2]);
                                float threshold = tw_offset + plane->dist + absNz;
                                float dist = dot - threshold;
                                if (dist > 0.0f)
                                    goto next_brush;
                            }

                            /* Test remaining planes */
                            for (j = 0; j < sideCount - 1; j++) {
                                cplane_t *plane = sidesPtr[j + 1].plane;
                                float dot = tw_x * plane->normal[0]
                                          + tw_y * plane->normal[1]
                                          + tw_z * plane->normal[2];
                                float absNz = fabsf(tw_radius_z * plane->normal[2]);
                                float threshold = tw_offset + plane->dist + absNz;
                                float dist = dot - threshold;
                                if (dist > 0.0f)
                                    goto next_brush;
                            }
                        }

                    hit:
                        /* Hit: set trace results */
                        trace->allsolid = 1;
                        trace->startsolid = 1;
                        trace->fraction = 0.0f;
                        trace->contents = brush->contents;
                    }

                next_brush:
                    if (trace->allsolid != 0)
                        return;
                }
            }
            return;
        }

        /* leafBrushCount < 0: has children */
        /* Recurse into first child (node + 0x14) */
        CM_TestInLeafBrushNode_r_impl(tw, node + 0x14, trace);
        if (trace->allsolid != 0)
            return;
    }

leaf_dist_test:
    {
        unsigned int axis = ((cLeafBrushNode_t *)node)->axis;
        float dist = ((cLeafBrushNode_t *)node)->data.children.dist;
        float tw_min = tw->bounds[0][axis];

        if (tw_min > dist) {
            /* Go to child[0] and loop */
            unsigned short childOff = ((cLeafBrushNode_t *)node)->data.children.childOffset[0];
            node = node + childOff * 20;
            /* Check contents and continue */
            if (!(tw->contents & ((cLeafBrushNode_t *)node)->contents))
                return;
            goto top;
        }

        {
            float tw_max = tw->bounds[1][axis];

            if (tw_max >= dist) {
                /* Straddles: recurse into child[0], then fall through to child[1] */
                unsigned short childOff0 = ((cLeafBrushNode_t *)node)->data.children.childOffset[0];
                byte *child0 = node + childOff0 * 20;
                CM_TestInLeafBrushNode_r_impl(tw, child0, trace);
                if (trace->allsolid != 0)
                    return;
            }

            /* Go to child[1] and loop */
            {
                unsigned short childOff1 = ((cLeafBrushNode_t *)node)->data.children.childOffset[1];
                node = node + childOff1 * 20;
                goto top;
            }
        }
    }
}

static int CM_TestInLeafBrushNode_r(void)
{
    /* Register calling convention trampoline - this is called from other naked asm functions
     * with eax=tw, edx=node, ecx=trace. In the #else (Emscripten) build,
     * the callers would also be converted to C, so we just declare this as a stub.
     * The _impl version is what gets called. */
    return 0;
}
