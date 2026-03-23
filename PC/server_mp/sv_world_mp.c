/* ASM dump from: sv_world_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_world_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern clipHandle_t CM_TempBoxModel(const vec_t *mins, const vec_t *maxs, int contents);
extern void CM_UnlinkEntity(int svEntity);
extern int CM_BoxSightTrace(int oldHitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, int brushmask, int contentmask);
extern int CM_PointSightTraceToEntities(const sightpointtrace_t *clip);
extern int CM_ClipSightTraceToEntities(const sightclip_t *clip);
extern void CM_BoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, int brushmask, int contentmask);
extern void CM_PointTraceStaticModels(trace_t *results, const vec_t *start, const vec_t *end, int contentmask);
extern void CM_CalcTraceEntents(const void *extents);
extern void CM_PointTraceToEntities(const pointtrace_t *clip, trace_t *results);
extern void CM_ClipMoveToEntities(const moveclip_t *clip, trace_t *results);
extern int CM_PointTraceStaticModelsComplete(const vec_t *start, const vec_t *end, int contentmask);
extern float RadiusFromBounds(const vec_t *mins, const vec_t *maxs);
extern float RadiusFromBounds2D(const vec_t *mins, const vec_t *maxs);
extern int CM_BoxLeafnums(const vec_t *mins, const vec_t *maxs, int *leafs, int maxLeafs, int *lastLeaf);
extern int CM_LeafCluster(int leafnum);
extern void CM_LinkEntity(int svEntity, const vec_t *absmin, const vec_t *absmax, int clipHandle);
extern int CM_TraceBox(const void *extents, const vec_t *absmin, const vec_t *absmax, float fraction);
extern void CM_TransformedBoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, int clipHandle, int contentmask, const vec_t *origin, const vec_t *angles);
extern int CM_TransformedBoxSightTrace(int oldHitNum, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, int clipHandle, int contentmask, const vec_t *origin, const vec_t *angles);
extern int CM_AreaEntities(const vec_t *mins, const vec_t *maxs, int *entityList, int maxcount, int contentmask);
extern int CM_PointContents(const vec_t *p, int brushmask);
extern int CM_TransformedPointContents(const vec_t *p, int clipHandle, const vec_t *origin, const vec_t *angles);
extern void Com_Error(int code, const char *fmt, ...);
extern gentity_t *SV_GentityNum(int num);
extern void *Com_GetServerDObj(int entityNum);
extern void DObjGetBounds(void *obj, vec_t *absmin, vec_t *absmax);
extern int DObjHasContents(void *obj, int contentmask);
extern void G_DObjCalcPose(gentity_t *ent);
extern void AnglesToAxis(const vec_t *angles, float (*axis)[3]);
extern void MatrixTransposeTransformVector43(const vec_t *in, const float *mat, vec_t *out);
extern void MatrixTransformVector(const vec_t *in, const float (*axis)[3], vec_t *out);
extern int DObjGeomTraceline(void *obj, const vec_t *start, const vec_t *end, int contentmask, void *objTrace);
extern int DObjTraceline(void *obj, const vec_t *start, const vec_t *end, unsigned char *priorityMap, void *objTrace);
extern int SV_SvEntityForGentity(const gentity_t *gEnt);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

__attribute__((used, aligned(4))) vec_t actorLocationalMaxs[3] = {
    64.0f, 64.0f, 72.0f,
}; /* 0x311e40 */
__attribute__((used, aligned(4))) vec_t actorLocationalMins[5] = {
    -64.0f, -64.0f, -32.0f, 0.0f, 0.0f,
}; /* 0x311e4c */

clipHandle_t SV_ClipHandleForEntity(const gentity_t *ent);
int SV_UnlinkEntity(gentity_t *gEnt);
int SV_SightTrace(int *hitNum, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum0, int passEntityNum1, int contentmask);
int SV_Trace(trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask, qboolean locational, unsigned char *priorityMap, qboolean staticmodels);
qboolean SV_TracePassed(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum0, int passEntityNum1, int contentmask, qboolean locational, qboolean staticmodels);
int SV_LinkEntity(gentity_t *gEnt);
int SV_ClipMoveToEntity(const moveclip_t *clip, svEntity_t *check, trace_t *trace);
int SV_PointTraceToEntity(const pointtrace_t *clip, svEntity_t *check, trace_t *trace);
int SV_ClipSightToEntity(const sightclip_t *clip, svEntity_t *check);
int SV_PointSightTraceToEntity(const sightpointtrace_t *clip, svEntity_t *check);
int SV_SightTraceToEntity(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int entityNum, int contentmask);
int SV_PointContents(const vec_t *p, int passEntityNum, int contentmask);

/* line 24 */
clipHandle_t SV_ClipHandleForEntity(const gentity_t *ent)
{
    if (ent->r.bmodel)
        return ent->s.index.brushmodel; /* brush model handle */
    return CM_TempBoxModel(ent->r.mins, ent->r.maxs, ent->r.contents);
}

/* line 43 */
int SV_UnlinkEntity(gentity_t *gEnt)
{
    int svEntityNum = SV_SvEntityForGentity(gEnt);
    gEnt->r.linked = 0;
    CM_UnlinkEntity(svEntityNum);
    return 0;
}

/* line 817 */
int SV_SightTrace(int *hitNum, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum0, int passEntityNum1, int contentmask) {
    /* CM_BoxSightTrace: world BSP sight trace */
    *hitNum = CM_BoxSightTrace(*hitNum, start, end, mins, maxs, 0, contentmask);
    if (*hitNum)
        return 0; /* hit something */

    /* Check if extents are non-zero */
    {
        float extentSum = (maxs[0] - mins[0]) + (maxs[1] - mins[1]) + (maxs[2] - mins[2]);
        if (extentSum == 0.0f) {
            /* Point sight trace */
            sightpointtrace_t clip;
            clip.start[0] = start[0];
            clip.start[1] = start[1];
            clip.start[2] = start[2];
            clip.end[0] = end[0];
            clip.end[1] = end[1];
            clip.end[2] = end[2];
            clip.passEntityNum[0] = passEntityNum0;
            clip.passEntityNum[1] = passEntityNum1;
            clip.contentmask = contentmask;
            *hitNum = CM_PointSightTraceToEntities(&clip);
        } else {
            /* Box sight trace with computed half-extents and midpoints */
            sightclip_t clip;
            float halfX = (maxs[0] - mins[0]) * 0.5f;
            float halfY = (maxs[1] - mins[1]) * 0.5f;
            float halfZ = (maxs[2] - mins[2]) * 0.5f;
            float midX = (maxs[0] + mins[0]) * 0.5f;
            float midY = (maxs[1] + mins[1]) * 0.5f;
            float midZ = (maxs[2] + mins[2]) * 0.5f;

            /* mins = -halfExtent */
            clip.mins[0] = -halfX;
            clip.mins[1] = -halfY;
            clip.mins[2] = -halfZ;
            /* maxs = halfExtent */
            clip.maxs[0] = halfX;
            clip.maxs[1] = halfY;
            clip.maxs[2] = halfZ;
            /* outerSize = halfExtent + 1.0 */
            clip.outerSize[0] = halfX + 1.0f;
            clip.outerSize[1] = halfY + 1.0f;
            clip.outerSize[2] = halfZ + 1.0f;
            /* start = world_start + midpoint */
            clip.start[0] = midX + start[0];
            clip.start[1] = midY + start[1];
            clip.start[2] = midZ + start[2];
            /* end = world_end + midpoint */
            clip.end[0] = midX + end[0];
            clip.end[1] = midY + end[1];
            clip.end[2] = midZ + end[2];
            clip.passEntityNum[0] = passEntityNum0;
            clip.passEntityNum[1] = passEntityNum1;
            clip.contentmask = contentmask;
            *hitNum = CM_ClipSightTraceToEntities(&clip);
        }
    }

    return 0;
}

/* line 604 */
/*
 * SV_Trace: core server trace through world BSP + entities.
 *
 * 1. CM_BoxTrace against world geometry
 * 2. Set entityNum in result (0x3ff = no hit, 0x3fe = world hit)
 * 3. Optional CM_PointTraceStaticModels pass
 * 4. Entity trace: point or box depending on extents
 *
 * Stack layout for point trace clip (pointtrace_t):
 *   -0x6c: clip.start[0..2]   (extents/start at clip+0)
 *   -0x60: clip.end[0..2]
 *   -0x48: clip.passEntityNum
 *   -0x44: clip.passEntityNum2 (ownerNum)
 *   -0x40: clip.contentmask
 *   -0x3c: clip.locational
 *   -0x38: clip.priorityMap
 *   CM_CalcTraceEntents called with &clip
 *   CM_PointTraceToEntities(&clip, results)
 *
 * Stack layout for box trace clip (moveclip_t):
 *   -0x6c: clip.mins[0..2]    (negated half-extent)
 *   -0x60: clip.maxs[0..2]    (half-extent)
 *   -0x54: clip.outerSize[0..2] (half-extent + 1.0)
 *   -0x48: clip.start[0..2]   (midpoint + start)
 *   -0x3c: clip.end[0..2]     (midpoint + end)
 *   -0x24: clip.passEntityNum
 *   -0x20: clip.passEntityNum2 (ownerNum)
 *   -0x1c: clip.contentmask
 *   CM_CalcTraceEntents called with &clip.start (extents ptr)
 *   CM_ClipMoveToEntities(&clip, results)
 */
int SV_Trace(trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask, qboolean locational, unsigned char *priorityMap, qboolean staticmodels)
{
    /* 1. World BSP trace */
    CM_BoxTrace(results, start, end, mins, maxs, 0, contentmask);

    /* 2. Set entityNum: if fraction == 1.0 => 0x3ff (ENTITYNUM_NONE), else 0x3fe (ENTITYNUM_WORLD) */
    {
        int isOne = (results->fraction == 1.0f) ? 1 : 0;
        results->entityNum = (unsigned short)(isOne + 0x3fe);
    }

    /* 3. Early out if fraction is 0.0 */
    if (results->fraction == 0.0f)
        return 0;

    /* 4. Static models trace (optional) */
    if (staticmodels) {
        CM_PointTraceStaticModels(results, start, end, contentmask);
        if (results->fraction == 0.0f)
            return 0;
    }

    /* 5. Entity trace */
    {
        float extentSum = (maxs[0] - mins[0]) + (maxs[1] - mins[1]) + (maxs[2] - mins[2]);

        if (extentSum == 0.0f) {
            /* Point trace path */
            byte clip[0x50]; /* pointtrace_t - sized from stack layout */
            int ownerNum;

            /* Copy start/end */
            ((pointtrace_t *)clip)->extents.start[0] = start[0];
            ((pointtrace_t *)clip)->extents.start[1] = start[1];
            ((pointtrace_t *)clip)->extents.start[2] = start[2];
            ((pointtrace_t *)clip)->extents.end[0] = end[0];
            ((pointtrace_t *)clip)->extents.end[1] = end[1];
            ((pointtrace_t *)clip)->extents.end[2] = end[2];

            /* Calculate trace extents */
            CM_CalcTraceEntents((const void *)clip);

            /* Set passEntityNum */
            ((pointtrace_t *)clip)->passEntityNum = passEntityNum;

            /* Set locational */
            ((pointtrace_t *)clip)->bLocational = locational;

            /* Set priorityMap */
            ((pointtrace_t *)clip)->priorityMap = (int)(intptr_t)priorityMap;

            /* Look up ownerNum */
            if (passEntityNum == 0x3ff) {
                ownerNum = -1;
            } else {
                gentity_t *passEnt = SV_GentityNum(passEntityNum);
                ownerNum = passEnt->r.ownerNum;
                if (ownerNum == 0x3ff)
                    ownerNum = -1;
            }
            ((pointtrace_t *)clip)->passOwnerNum = ownerNum;

            /* Set contentmask */
            ((pointtrace_t *)clip)->contentmask = contentmask;

            /* Call CM_PointTraceToEntities */
            CM_PointTraceToEntities((const pointtrace_t *)clip, results);
        } else {
            /* Box trace path */
            byte clip[0x70]; /* moveclip_t - sized from stack layout */
            int ownerNum;
            float halfX, halfY, halfZ;
            float midX, midY, midZ;

            halfX = (maxs[0] - mins[0]) * 0.5f;
            halfY = (maxs[1] - mins[1]) * 0.5f;
            halfZ = (maxs[2] - mins[2]) * 0.5f;

            midX = (maxs[0] + mins[0]) * 0.5f;
            midY = (maxs[1] + mins[1]) * 0.5f;
            midZ = (maxs[2] + mins[2]) * 0.5f;

            /* Set contentmask */
            ((moveclip_t *)clip)->contentmask = contentmask;

            /* Set passEntityNum */
            ((moveclip_t *)clip)->passEntityNum = passEntityNum;

            /* Look up ownerNum */
            if (passEntityNum == 0x3ff) {
                ownerNum = -1;
            } else {
                gentity_t *passEnt = SV_GentityNum(passEntityNum);
                ownerNum = passEnt->r.ownerNum;
                if (ownerNum == 0x3ff)
                    ownerNum = -1;
            }
            ((moveclip_t *)clip)->passOwnerNum = ownerNum;

            /* mins = -halfExtent */
            ((pointtrace_t *)clip)->extents.start[0] = -halfX;
            ((pointtrace_t *)clip)->extents.start[1] = -halfY;
            ((pointtrace_t *)clip)->extents.start[2] = -halfZ;

            /* maxs = halfExtent */
            ((pointtrace_t *)clip)->extents.end[0] = halfX;
            ((pointtrace_t *)clip)->extents.end[1] = halfY;
            ((pointtrace_t *)clip)->extents.end[2] = halfZ;

            /* outerSize = halfExtent + 1.0 */
            ((pointtrace_t *)clip)->extents.invDelta[0] = halfX + 1.0f;
            ((pointtrace_t *)clip)->extents.invDelta[1] = halfY + 1.0f;
            ((pointtrace_t *)clip)->extents.invDelta[2] = halfZ + 1.0f;

            /* start = midpoint + start */
            ((pointtrace_t *)clip)->passEntityNum = midX + start[0];
            ((pointtrace_t *)clip)->passOwnerNum = midY + start[1];
            ((pointtrace_t *)clip)->contentmask = midZ + start[2];

            /* end = midpoint + end */
            ((pointtrace_t *)clip)->bLocational = midX + end[0];
            ((pointtrace_t *)clip)->priorityMap = midY + end[1];
            ((moveclip_t *)clip)->extents.end[2] = midZ + end[2];

            /* Calculate trace extents */
            CM_CalcTraceEntents(&((moveclip_t *)clip)->extents);

            /* Call CM_ClipMoveToEntities */
            CM_ClipMoveToEntities((const moveclip_t *)clip, results);
        }
    }

    return 0;
}
