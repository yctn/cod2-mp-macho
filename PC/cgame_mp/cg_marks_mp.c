/* Decompiled from: cg_marks_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_marks_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern float floorf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern MarkPoly cg_markPolys[1024]; /* 0x0 */
extern MarkPoly *cg_freeMarkPolys; /* 0x0 */
extern MarkVertAssemblyBuffer markVerts; /* 0x0 */

/* Extern declarations for called functions */
extern const vec_t Vec3NormalizeTo(const vec_t *v, vec_t *out);
extern void PerpendicularVector(const vec_t *src, vec_t *dst);
extern void RotatePointAroundVector(vec_t *dst, const vec_t *dir, const vec_t *point, const float degrees);
extern void Vec3Cross(const vec_t *v0, const vec_t *v1, vec_t *cross);
extern Bool FxHelper_CullSphere(const FxHelper *_this, const vec_t *worldPos, float radius, int planeCount);
extern void CL_AddPolyToScene(MaterialHandle mtlHandle, int lmapIndex, int vertCount, const GfxWorldVertex *verts);
extern int CL_MarkFragments(const vec3_t *points, const vec_t *origin, const vec3_t *axis, float radius, int maxPoints, GfxWorldVertex *verts, int maxFragments, GfxMarkFragment *fragmentBuffer, MaterialHandle markMaterial);
extern void Com_Error(errorParm_t code, const char *fmt);

/*
 * Indirect global pointers (absolute addresses from original binary).
 * These are pointer-to-pointer indirections used by the cgame module.
 *   imp_cg_marksLimit -> int** : points to a struct whose field at offset 8 holds the max markPoly count
 *   imp_cg -> char** : points to cg_t* (the main cgame state)
 *   imp_cg_marks -> char** : points to a struct whose byte at offset 8 is a "marks enabled" flag
 *   imp_theFxHelper -> FxHelper* : the FX helper singleton
 */
#define CG_MARKCOUNT_PTR   (*(int **)(imp_cg_marksLimit))
#define CG_PTR             (*(char **)(imp_cg))
#define CG_MARKS_ENABLED   (*(char **)(imp_cg_marks))
#define FX_HELPER_PTR      (*(FxHelper **)(imp_theFxHelper))

/* Offset of activeMarkPolys sentinel within cg_t */
#define CG_ACTIVE_MARKS_OFFSET  0xf3714

/* Helper: get sentinel MarkPoly from cg pointer */
static MarkPoly *CG_GetActiveMarksSentinel(char *cg)
{
    return (MarkPoly *)(cg + CG_ACTIVE_MARKS_OFFSET);
}

/* Helper: interpret int field as MarkPoly pointer */
#define MARKPOLY_PREV(mp)  ((MarkPoly *)(intptr_t)(mp)->prevMark)
#define MARKPOLY_NEXT(mp)  ((MarkPoly *)(intptr_t)(mp)->nextMark)
#define SET_PREV(mp, ptr)  ((mp)->prevMark = (int)(intptr_t)(ptr))
#define SET_NEXT(mp, ptr)  ((mp)->nextMark = (int)(intptr_t)(ptr))

/* Helper: clamp float color component to byte [0, 255] */
static unsigned char ColorFloatToByte(float f)
{
    int val = (int)floorf(f * 255.0f + 0.5f);
    if (val > 255) val = 255;
    else if (val < 0) val = 0;
    return (unsigned char)val;
}

void CG_InitMarkPolys(void);
void CG_AddMarks(void);
void CG_ImpactMark(MaterialHandle markMaterial, const vec_t *origin, const vec_t *dir, float orientation, const vec_t *color, float radius);

/* line 34 */
void CG_InitMarkPolys(void)
{
    int lasttrav;
    int i;
    char *cg;
    MarkPoly *sentinel;

    /* Get max mark poly count from indirect config pointer */
    lasttrav = CG_MARKCOUNT_PTR[2]; /* offset 8 = index 2 */

    /* Zero out all mark polys */
    memset(cg_markPolys, 0, (size_t)lasttrav * sizeof(MarkPoly));

    /* Initialize the active marks doubly-linked list sentinel to empty (self-referencing) */
    cg = CG_PTR;
    sentinel = CG_GetActiveMarksSentinel(cg);
    SET_NEXT(sentinel, sentinel);
    SET_PREV(sentinel, sentinel);

    /* Set head of free list to first mark poly */
    cg_freeMarkPolys = &cg_markPolys[0];

    /* Link free mark polys into a singly-linked list via nextMark */
    for (i = 0; i < lasttrav - 1; i++) {
        SET_NEXT(&cg_markPolys[i], &cg_markPolys[i + 1]);
    }
}

/* line 220 */
void CG_AddMarks(void)
{
    char *cg;
    MarkPoly *sentinel;
    MarkPoly *markPoly;
    MarkPoly *next;
    FxHelper *fxHelper;

    /* Check if marks are enabled */
    if (!*(unsigned char *)(CG_MARKS_ENABLED + 8))
        return;

    cg = CG_PTR;
    sentinel = CG_GetActiveMarksSentinel(cg);
    markPoly = MARKPOLY_NEXT(sentinel);

    if (markPoly == sentinel)
        return;

    fxHelper = FX_HELPER_PTR;

    while (markPoly != sentinel) {
        next = MARKPOLY_NEXT(markPoly);

        /* Cull check: skip if mark is outside the view frustum */
        if (FxHelper_CullSphere(fxHelper, markPoly->origin, markPoly->radius, fxHelper->mCamera.numPlanes)) {
            markPoly = next;
            continue;
        }

        /* Record the frame this mark was last drawn */
        markPoly->lastFrameDrawn = *(int *)cg; /* cg->clientFrame at offset 0 */

        /* Add the mark poly to the render scene */
        CL_AddPolyToScene(markPoly->mtlHandle, (int)markPoly->lmapIndex, (int)markPoly->vertCount, markPoly->verts);

        markPoly = MARKPOLY_NEXT(markPoly);
    }
}

/* line 138 */
void CG_ImpactMark(MaterialHandle markMaterial, const vec_t *origin, const vec_t *dir, float orientation, const vec_t *color, float radius)
{
    char *cg;
    vec3_t axisDir;     /* axis[0]: normalized impact direction */
    vec3_t axisCross;   /* axis[2]: cross product of dir and rotated perp */
    vec3_t axisRight;   /* axis[1]: perpendicular rotated around dir */
    vec3_t perpVec;
    vec3_t originalPoints[4];
    GfxMarkFragment markFragments[384]; /* 0x180 = 384 max fragments */
    int fragmentCount;
    int fragmentIndex;
    GfxColor nativeColor;
    int j;
    MarkPoly *sentinel;
    MarkPoly *markPoly;
    MarkPoly *oldest;
    MarkPoly *current;
    float a, b;

    /* Check if marks are enabled */
    if (!*(unsigned char *)(CG_MARKS_ENABLED + 8))
        return;

    /* Check additional condition in cg_t (offset 0x2bee8, e.g. snapshot availability) */
    cg = CG_PTR;
    if (((cg_t *)cg)->nomarks == 0)
        return;

    /* Build orthonormal axis from impact direction */
    Vec3NormalizeTo(dir, axisDir);
    PerpendicularVector(axisDir, perpVec);
    RotatePointAroundVector(axisRight, axisDir, perpVec, orientation);
    Vec3Cross(axisDir, axisRight, axisCross);

    /* Compute 4 corner points of the mark rectangle */
    for (j = 0; j < 3; j++) {
        a = radius * axisCross[j];
        b = radius * axisRight[j];
        originalPoints[0][j] = origin[j] - a - b;
        originalPoints[1][j] = origin[j] + a - b;
        originalPoints[2][j] = origin[j] + a + b;
        originalPoints[3][j] = origin[j] - a + b;
    }

    /* Generate mark fragments against world geometry */
    fragmentCount = CL_MarkFragments(
        originalPoints,
        origin,
        (const vec3_t *)axisDir,
        radius,
        1024,                              /* maxPoints = 0x400 */
        (GfxWorldVertex *)&markVerts,
        384,                               /* maxFragments = 0x180 */
        markFragments,
        markMaterial
    );

    /* Convert float color [0,1] to packed byte color */
    nativeColor.array[0] = ColorFloatToByte(color[3]); /* alpha */
    nativeColor.array[1] = ColorFloatToByte(color[0]); /* red */
    nativeColor.array[2] = ColorFloatToByte(color[1]); /* green */
    nativeColor.array[3] = ColorFloatToByte(color[2]); /* blue */

    if (fragmentCount <= 0)
        return;

    /* Process each mark fragment */
    for (fragmentIndex = 0; fragmentIndex < fragmentCount; fragmentIndex++) {
        GfxMarkFragment *frag = &markFragments[fragmentIndex];
        GfxWorldVertex *verts = (GfxWorldVertex *)((char *)&markVerts + frag->firstPoint * (int)sizeof(GfxWorldVertex));
        int vertCount = (int)frag->pointCount;

        /* Apply the native color to all vertices in this fragment */
        for (j = 0; j < vertCount; j++) {
            verts[j].color.packed = nativeColor.packed;
        }

        /* Allocate a mark poly from the free list */
        if (cg_freeMarkPolys == NULL) {
            /* No free polys: recycle the oldest active mark */
            cg = CG_PTR;
            sentinel = CG_GetActiveMarksSentinel(cg);
            oldest = MARKPOLY_PREV(sentinel);

            /* Find the mark with the lowest lastFrameDrawn (oldest) */
            if (oldest != sentinel) {
                current = oldest;
                while (1) {
                    if (current->lastFrameDrawn < oldest->lastFrameDrawn) {
                        oldest = current;
                    }
                    current = MARKPOLY_PREV(current);
                    if (current == sentinel)
                        break;
                }
            }

            /* Verify the oldest mark has a valid prev link */
            if (MARKPOLY_PREV(oldest) == NULL) {
                Com_Error(ERR_DROP, "CG_FreeLocalEntity: not active");
                /* Com_Error may return for non-fatal errors; continue with unlink */
            }

            /* Unlink oldest from the active list */
            {
                MarkPoly *prev = MARKPOLY_PREV(oldest);
                MarkPoly *next = MARKPOLY_NEXT(oldest);
                SET_NEXT(prev, next);
                SET_PREV(next, prev);
            }

            /* Push oldest onto the free list */
            SET_NEXT(oldest, cg_freeMarkPolys);
            cg_freeMarkPolys = oldest;
        }

        /* Pop a mark poly from the free list */
        markPoly = cg_freeMarkPolys;
        cg_freeMarkPolys = MARKPOLY_NEXT(markPoly);

        /* Insert the new mark at the head of the active list (after sentinel) */
        cg = CG_PTR;
        sentinel = CG_GetActiveMarksSentinel(cg);
        {
            MarkPoly *oldFirst = MARKPOLY_NEXT(sentinel);
            SET_NEXT(markPoly, oldFirst);
            SET_PREV(markPoly, sentinel);
            SET_PREV(oldFirst, markPoly);
            SET_NEXT(sentinel, markPoly);
        }

        /* Fill in the mark poly fields */
        markPoly->origin[0] = origin[0];
        markPoly->origin[1] = origin[1];
        markPoly->origin[2] = origin[2];
        markPoly->radius = radius;
        markPoly->mtlHandle = frag->markMaterial;
        markPoly->lmapIndex = frag->lmapIndex;
        markPoly->vertCount = frag->pointCount;
        markPoly->lastFrameDrawn = *(int *)cg; /* cg->clientFrame at offset 0 */

        /* Copy vertex data from the mark vert assembly buffer */
        memcpy(markPoly->verts, verts, (size_t)frag->pointCount * sizeof(GfxWorldVertex));
    }
}
