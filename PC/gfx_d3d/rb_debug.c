/* ASM dump from: rb_debug.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_debug.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 */

extern refimport_t ri;                 /* imp_ri */
extern r_global_permanent_t rgp;        /* imp_rgp */
/* g_dxCaps was imp_r_rendererInUse */
extern r_backEndGlobals_t backEnd;      /* imp_backEnd */
extern void **g_drawSurf;              /* imp_tess */
extern void **g_viewParms;             /* imp_backEndData */

extern void R_ConvertColorToBytes(const vec_t *colorFloat, byte *colorBytes);
extern void RB_DrawLines3D(int count, int width, const GfxPointVertex *verts, int depthTest);
extern void RB_EndSurface(void);
extern void RB_Set3D(void);
extern void RB_BeginSurface(const Material *material, MaterialTechniqueType techType, int lmapIndex);
extern void RB_DrawTextInSpace(const char *text, FontHandle font, const vec_t *org, const vec_t *xPixelStep, const vec_t *yPixelStep, D3DCOLOR color);
extern void R_AddDebugString(DebugGlobals *debugGlobalsEntry, const vec_t *origin, const vec_t *color, float scale, const char *string);
extern const char *va(const char *fmt, ...);
extern double sin(double x);

/* DebugGlobals base offset within *g_viewParms (GfxBackEndData): 0x249d18 */
#define DBGGLOB_OFF   0x249d18

static int RB_AddDebugLine(const vec_t *start, const vec_t *end, const vec_t *color, int depthTest, int vertCount, int vertLimit, GfxPointVertex *verts);
static JCOEF RB_DrawDebugStrings(trDebugString_t *strings, int stringCount);
static JCOEF RB_DrawPolyOutlines(void);
static JCOEF RB_DrawDebugLines(trDebugLine_t *lines, int lineCount);
static JCOEF RB_DrawPolyInteriors(void);
JCOEF RB_DrawDebug(const GfxViewParms *viewParms);

/*
 * RB_AddDebugLine
 *
 * Adds a debug line (2 verts) to the vertex buffer.
 * If the buffer is full, flushes current lines via RB_DrawLines3D,
 * then resets vertCount to 0 and starts fresh.
 *
 * Returns new vertCount.
 */
static int RB_AddDebugLine(const vec_t *start, const vec_t *end, const vec_t *color, int depthTest, int vertCount, int vertLimit, GfxPointVertex *verts)
{
    int newVertCount = vertCount + 2;

    if (newVertCount > vertLimit) {
        /* Buffer full - flush existing lines */
        RB_DrawLines3D(vertCount / 2, 1, verts, depthTest);
        vertCount = 0;
        newVertCount = 2;
    }

    {
        GfxPointVertex *v0 = &verts[vertCount];
        GfxPointVertex *v1 = &verts[vertCount + 1];

        /* Convert color to bytes and store in first vert */
        R_ConvertColorToBytes(color, v0->color);

        /* Copy color bytes to second vert */
        *(int *)v1->color = *(int *)v0->color;

        /* Copy start position */
        v0->xyz[0] = start[0];
        v0->xyz[1] = start[1];
        v0->xyz[2] = start[2];

        /* Copy end position */
        v1->xyz[0] = end[0];
        v1->xyz[1] = end[1];
        v1->xyz[2] = end[2];
    }

    return newVertCount;
}

/*
 * RB_DrawDebugStrings
 *
 * Draws all debug strings in world space.
 * If the back-end is in 2D projection mode, switches to 3D first.
 * After drawing, checks if there are pending tris and flushes them.
 */
static JCOEF RB_DrawDebugStrings(trDebugString_t *strings, int stringCount)
{
    int stringIndex;
    materialCommands_t *tess;

    if (stringCount == 0) {
        return 0;
    }

    /* If currently in 2D projection, switch to 3D */
    if (backEnd.projection2D != 0) {
        RB_Set3D();
    }

    if (stringCount > 0) {
        for (stringIndex = 0; stringIndex < stringCount; stringIndex++) {
            trDebugString_t *s = &strings[stringIndex];
            byte colorBytes[4];
            vec3_t xStep, yStep;

            /* Convert color float to bytes */
            R_ConvertColorToBytes(s->color, colorBytes);

            /* Scale is negated */
            float scale = -s->scale;

            /* Get viewParms from backEnd */
            const GfxViewParms *vp = backEnd.viewParms;

            /* xStep = scale * viewParms->axis[1] */
            xStep[0] = scale * vp->axis[1][0];
            xStep[1] = scale * vp->axis[1][1];
            xStep[2] = scale * vp->axis[1][2];

            /* yStep = scale * viewParms->axis[2] */
            yStep[0] = scale * vp->axis[2][0];
            yStep[1] = scale * vp->axis[2][1];
            yStep[2] = scale * vp->axis[2][2];

            /* Draw text in 3D space */
            RB_DrawTextInSpace(
                s->text,
                backEnd.debugFont,
                s->xyz,
                xStep,
                yStep,
                *(D3DCOLOR *)colorBytes
            );
        }
    }

    /* Check if there are pending tris to flush */
    tess = *(materialCommands_t **)g_drawSurf;
    if (tess->indexCount != 0 || tess->optimizedIndexCount != 0) {
        RB_EndSurface();
    }

    return 0;
}

/*
 * RB_DrawPolyOutlines
 *
 * Draws wireframe outlines for all debug polygons.
 * Allocates temporary vertex buffer, iterates over all polys,
 * and draws lines between consecutive vertices.
 */
static JCOEF RB_DrawPolyOutlines(void)
{
    GfxPointVertex *verts;
    int polyIndex;
    int vertCount = 0;
    int polyCount;

    /* Allocate temp vertex buffer: 0xaa50 bytes = 2730 GfxPointVertex (16 bytes each) */
    verts = (GfxPointVertex *)ri.Z_MallocInternal(0xaa50);

    DebugGlobals *dbg = (DebugGlobals *)(*(byte **)g_viewParms + DBGGLOB_OFF);
    polyCount = dbg->polyCount;

    if (polyCount <= 0) {
        ri.Z_FreeInternal(verts);
        return 0;
    }

    for (polyIndex = 0; polyIndex < polyCount; polyIndex++) {
        vec3_t *polyVerts;
        int polyVertCount;
        int vertIndex;
        int lastVert;

        dbg = (DebugGlobals *)(*(byte **)g_viewParms + DBGGLOB_OFF);
        GfxDebugPoly *poly = &dbg->polys[polyIndex];

        /* Get first vert index and compute polyVerts base */
        polyVerts = &dbg->verts[poly->firstVert];

        polyVertCount = poly->vertCount;
        if (polyVertCount <= 0) {
            continue;
        }

        lastVert = polyVertCount - 1;
        {
            vec3_t *currentEdgeStart = &polyVerts[lastVert];
            for (vertIndex = 0; vertIndex < polyVertCount; vertIndex++) {
                vertCount = RB_AddDebugLine(
                    (const vec_t *)currentEdgeStart,
                    (const vec_t *)&polyVerts[vertIndex],
                    (const vec_t *)poly->color, /* color at start of GfxDebugPoly */
                    0,
                    vertCount,
                    0xaa5, /* vertLimit = 2725 */
                    verts
                );
                currentEdgeStart = &polyVerts[vertIndex];
            }
        }
    }

    /* Flush remaining lines if any */
    {
        int lineCount = vertCount / 2;
        if (lineCount != 0) {
            RB_DrawLines3D(lineCount, 1, verts, 0);
        }
    }

    ri.Z_FreeInternal(verts);

    return 0;
}

/*
 * RB_DrawDebugLines
 *
 * Draws a set of debug lines, grouping by depth test state.
 * When the depthTest flag changes between consecutive lines,
 * the current batch is flushed with RB_DrawLines3D.
 */
static JCOEF RB_DrawDebugLines(trDebugLine_t *lines, int lineCount)
{
    GfxPointVertex *verts;
    int depthTest;
    int lineIndex;
    int vertCount;
    int lineDepthTest;

    if (lineCount == 0) {
        return 0;
    }

    /* If currently in 2D projection, switch to 3D */
    if (backEnd.projection2D != 0) {
        RB_Set3D();
    }

    /* Allocate temp vertex buffer */
    verts = (GfxPointVertex *)ri.Z_MallocInternal(0xaa50);

    /* Initialize depthTest from first line */
    depthTest = (lines->depthTest != 0) ? 1 : 0;

    if (lineCount > 0) {
        trDebugLine_t *line = lines;
        lineIndex = 0;
        vertCount = 0;

        while (lineIndex < lineCount) {
            lineDepthTest = (line->depthTest != 0) ? 1 : 0;

            if (lineDepthTest != depthTest) {
                /* Depth test changed - flush current batch */
                int count = vertCount / 2;
                if (count != 0) {
                    RB_DrawLines3D(count, 1, verts, depthTest);
                }
                depthTest = lineDepthTest;
                vertCount = 0;
            }

            /* Add this line */
            vertCount = RB_AddDebugLine(
                line->start,
                line->end,
                line->color,
                lineDepthTest,
                vertCount,
                0xaa5,
                verts
            );

            lineIndex++;
            line++;
        }
    } else {
        lineDepthTest = depthTest;
        vertCount = 0;
    }

    /* Flush remaining lines */
    {
        int count = vertCount / 2;
        if (count != 0) {
            RB_DrawLines3D(count, 1, verts, lineDepthTest);
        }
    }

    ri.Z_FreeInternal(verts);

    return 0;
}

/*
 * RB_DrawPolyInteriors
 *
 * Draws filled debug polygons as triangle fans.
 * Uses RB_BeginSurface/RB_EndSurface for batched rendering.
 */
static JCOEF RB_DrawPolyInteriors(void)
{
    byte *data;
    byte *drawSurf;
    int polyCount;
    int polyIndex;
    int polyOffset;

    /* Begin surface with white material, technique type 3, no lightmap */
    RB_BeginSurface(rgp.whiteMaterial, 3, 0);

    data = *(byte **)g_viewParms;
    polyCount = *(int *)(data + DBGGLOB_OFF + 0x10); /* debugGlobals.polyCount */

    if (polyCount <= 0) {
        RB_EndSurface();
        return 0;
    }

    polyOffset = 0;
    drawSurf = *(byte **)g_drawSurf;

    for (polyIndex = 0; polyIndex < polyCount; polyIndex++) {
        byte *poly;
        vec3_t *polyVerts;
        int polyVertCount;
        int indexCount;
        int vertIndex;
        D3DCOLOR colorBytes;

        poly = data + *(int *)(data + DBGGLOB_OFF + 0x0C) + polyOffset;

        /* Get polygon vertices */
        {
            int firstVert = *(int *)(poly + 0x10);
            vec3_t *vertsBase = *(vec3_t **)(data + DBGGLOB_OFF);
            polyVerts = &vertsBase[firstVert];
        }

        /* Convert color */
        R_ConvertColorToBytes((const vec_t *)poly, (byte *)&colorBytes);

        polyVertCount = *(int *)(poly + 0x14);
        indexCount = polyVertCount * 3 - 6; /* triangle fan: (n-2) * 3 indices */

        /* Check if we need to overflow / restart the surface */
        {
            int newVertTotal = polyVertCount + *(int *)(drawSurf + 0x5a7d4);
            int newIndexTotal = indexCount + *(int *)(drawSurf + 0x5a7d0);

            if (newVertTotal > 0x154a || newIndexTotal > 0x100000) {
                int oldBatch = *(int *)(drawSurf + 0x5a7cc);

                RB_EndSurface();
                RB_BeginSurface(
                    *(const Material **)(drawSurf + 0x5a7bc),
                    *(MaterialTechniqueType *)(drawSurf + 0x5a7c0),
                    *(int *)(drawSurf + 0x5a7c4)
                );

                if (oldBatch != *(int *)(drawSurf + 0x5a7cc)) {
                    /* Batch counter changed - check pending tris */
                    if (*(int *)(drawSurf + 0x5a7d0) != 0 || *(int *)(drawSurf + 0x5a7e0) != 0) {
                        RB_EndSurface();
                    }
                    drawSurf = *(byte **)g_drawSurf;
                    *(int *)(drawSurf + 0x5a7cc) = oldBatch;
                }
            }
        }

        /* Emit vertices */
        if (polyVertCount > 0) {
            byte *dxCapsData = *(byte **)imp_r_rendererInUse;
            int surfaceType = *(int *)(dxCapsData + 8);
            vec3_t *pv = polyVerts;

            for (vertIndex = 0; vertIndex < polyVertCount; vertIndex++) {
                int baseVert = vertIndex + *(int *)(drawSurf + 0x5a7d4);

                if (surfaceType == 2) {
                    /* Type 2: 36-byte stride vertices (GfxWorldVertexDx7-like) */
                    int vertOff = baseVert * 9 * 4; /* 36 bytes per vert */
                    byte *to = drawSurf + vertOff;

                    /* xyz */
                    *(float *)(to + 0) = (*pv)[0];
                    *(float *)(to + 4) = (*pv)[1];
                    *(float *)(to + 8) = (*pv)[2];

                    /* normal = {0, 0, 1} */
                    *(float *)(to + 0x0c) = 0.0f;
                    *(float *)(to + 0x10) = 0.0f;
                    *(float *)(to + 0x14) = 1.0f;

                    /* color */
                    *(D3DCOLOR *)(to + 0x18) = colorBytes;

                    /* texcoord = {0, 0} */
                    *(float *)(to + 0x0c + 0x10) = 0.0f;
                    *(float *)(to + 0x10 + 0x10) = 0.0f;
                } else {
                    /* Type != 2: 64-byte stride vertices (GfxVertex-like) */
                    int vertOff = baseVert * 64;
                    byte *to = drawSurf + vertOff;

                    /* xyz */
                    *(float *)(to + 0) = (*pv)[0];
                    *(float *)(to + 4) = (*pv)[1];
                    *(float *)(to + 8) = (*pv)[2];

                    /* w = 1.0 */
                    *(float *)(to + 0x0c) = 1.0f;

                    /* normal = {0, 0, 1} at offset 0x10 */
                    *(float *)(to + 0x10) = 0.0f;
                    *(float *)(to + 0x14) = 0.0f;
                    *(float *)(to + 0x18) = 1.0f;

                    /* color */
                    *(D3DCOLOR *)(to + 0x1c) = colorBytes;

                    /* binormal at offset 0x20 */
                    *(float *)(to + 0x20) = 0.0f;
                    *(float *)(to + 0x24) = 1.0f;
                    *(float *)(to + 0x28) = 0.0f;

                    /* tangent at offset 0x30 */
                    *(float *)(to + 0x30) = 1.0f;
                    *(float *)(to + 0x34) = 0.0f;
                    *(float *)(to + 0x38) = 0.0f;

                    /* texcoord at offset 0x20 */
                    *(float *)(to + 0x20) = 0.0f;
                    *(float *)(to + 0x24) = 0.0f;
                }

                pv++;
            }
        }

        /* Emit triangle fan indices */
        if (polyVertCount > 2) {
            for (vertIndex = 2; vertIndex < polyVertCount; vertIndex++) {
                short *indices;
                int indexBase;
                short baseVertIdx;

                /* Index 0: first vertex */
                indexBase = *(int *)(drawSurf + 0x5a7d0);
                indices = *(short **)(drawSurf + 0x5a7b0);
                baseVertIdx = (short)*(int *)(drawSurf + 0x5a7d4);
                indices[indexBase] = baseVertIdx;

                /* Index 1: current vertex */
                indexBase = *(int *)(drawSurf + 0x5a7d0);
                indices = *(short **)(drawSurf + 0x5a7b0);
                indices[indexBase + 1] = (short)(vertIndex + *(int *)(drawSurf + 0x5a7d4));

                /* Index 2: previous vertex */
                indexBase = *(int *)(drawSurf + 0x5a7d0);
                indices = *(short **)(drawSurf + 0x5a7b0);
                indices[indexBase + 2] = (short)(vertIndex + *(int *)(drawSurf + 0x5a7d4) - 1);

                *(int *)(drawSurf + 0x5a7d0) += 3;
            }
        }

        /* Advance vertex base count */
        *(int *)(drawSurf + 0x5a7d4) += polyVertCount;

        /* Next poly */
        polyOffset += 0x18;
        data = *(byte **)g_viewParms;
        drawSurf = *(byte **)g_drawSurf;
    }

    RB_EndSurface();

    return 0;
}

/*
 * RB_DrawDebug
 *
 * Main entry point for drawing all debug primitives:
 * plumes, polygon interiors/outlines, debug lines, and debug strings.
 */
JCOEF RB_DrawDebug(const GfxViewParms *viewParms)
{
    byte *data;
    int plumeIndex;
    int plumeCount;
    byte *backEndPtr;

    data = *(byte **)g_viewParms;
    plumeCount = *(int *)(data + DBGGLOB_OFF + 0x4C); /* debugGlobals.plumeCount */

    if (plumeCount > 0) {
        const vec_t *dir = viewParms->axis[1]; /* axis[1] at offset 0x18 */
        int plumeOffset = 0;

        for (plumeIndex = 0; plumeIndex < plumeCount; plumeIndex++) {
            byte *plume;
            int time;
            int startTime;
            int duration;
            int elapsed;
            vec3_t org;

            data = *(byte **)g_viewParms;
            plume = data + *(int *)(data + DBGGLOB_OFF + 0x48) + plumeOffset;

            backEndPtr = (byte *)&backEnd;
            time = *(int *)(backEndPtr + 0x3b8); /* sceneDef.time */

            startTime = *(int *)(plume + 0x20);
            elapsed = time - startTime;

            if (elapsed < 0) {
                plumeOffset += 0x28;
                continue;
            }

            duration = *(int *)(plume + 0x24);
            if (elapsed > duration) {
                plumeOffset += 0x28;
                continue;
            }

            /* Set alpha based on fade */
            *(float *)(plume + 0x18) = 1.0f;

            data = *(byte **)g_viewParms;
            {
                byte *plumeData = data + *(int *)(data + DBGGLOB_OFF + 0x48) + plumeOffset;

                if (elapsed * 2 > duration) {
                    /* Fading out: alpha = -2*elapsed/duration + 2 */
                    float fElapsed = (float)elapsed;
                    float fDuration = (float)duration;
                    *(float *)(plumeData + 0x18) = fElapsed * -2.0f / fDuration + 2.0f;
                }
            }

            /* Compute world position with sin-based animation */
            {
                double angle = (double)elapsed * 0.012566370614359173 + (double)plumeIndex;
                float sinVal = (float)sin(angle);
                float height = sinVal * 4.0f;

                data = *(byte **)g_viewParms;
                {
                    byte *plumeOrigin = data + *(int *)(data + DBGGLOB_OFF + 0x48) + plumeOffset;

                    /* org = plumeOrigin + height * viewParms->axis[1] */
                    org[0] = height * viewParms->axis[1][0] + *(float *)(plumeOrigin + 0);
                    org[1] = height * viewParms->axis[1][1] + *(float *)(plumeOrigin + 4);
                    org[2] = height * viewParms->axis[1][2] + *(float *)(plumeOrigin + 8);

                    /* Adjust Z by small vertical offset */
                    org[2] = (float)elapsed * 0.06400000303983688f + org[2];
                }

                /* Add debug string showing the score */
                data = *(byte **)g_viewParms;
                {
                    byte *plumeData2 = data + *(int *)(data + DBGGLOB_OFF + 0x48) + plumeOffset;
                    const char *scoreStr = va("%i", *(int *)(plumeData2 + 0x1c));

                    R_AddDebugString(
                        (DebugGlobals *)(data + DBGGLOB_OFF),
                        org,
                        (const vec_t *)(plumeData2 + 0xc), /* color */
                        0.5f,
                        scoreStr
                    );
                }
            }

            plumeOffset += 0x28;
        }
    }

    /* Draw debug polys if any */
    data = *(byte **)g_viewParms;
    if (*(int *)(data + DBGGLOB_OFF + 0x10) != 0) { /* debugGlobals.polyCount */
        backEndPtr = (byte *)&backEnd;
        if (backEnd.projection2D != 0) {
            RB_Set3D();
        }
        RB_DrawPolyInteriors();
        RB_DrawPolyOutlines();

        /* Clear poly count */
        data = *(byte **)g_viewParms;
        *(int *)(data + DBGGLOB_OFF + 0x10) = 0;
    }

    /* Draw debug lines (internal + external) */
    data = *(byte **)g_viewParms;
    RB_DrawDebugLines(
        *(trDebugLine_t **)(data + DBGGLOB_OFF + 0x30), /* debugGlobals.lines */
        *(int *)(data + DBGGLOB_OFF + 0x34)              /* debugGlobals.lineCount */
    );

    data = *(byte **)g_viewParms;
    RB_DrawDebugLines(
        *(trDebugLine_t **)(data + DBGGLOB_OFF + 0x3C), /* debugGlobals.externLines */
        *(int *)(data + DBGGLOB_OFF + 0x40)              /* debugGlobals.externLineCount */
    );

    /* Clear line count */
    data = *(byte **)g_viewParms;
    *(int *)(data + DBGGLOB_OFF + 0x34) = 0;

    /* Draw debug strings (internal + external) */
    data = *(byte **)g_viewParms;
    RB_DrawDebugStrings(
        *(trDebugString_t **)(data + DBGGLOB_OFF + 0x18), /* debugGlobals.strings */
        *(int *)(data + DBGGLOB_OFF + 0x1C)                /* debugGlobals.stringCount */
    );

    data = *(byte **)g_viewParms;
    RB_DrawDebugStrings(
        *(trDebugString_t **)(data + DBGGLOB_OFF + 0x24), /* debugGlobals.externStrings */
        *(int *)(data + DBGGLOB_OFF + 0x28)                /* debugGlobals.externStringCount */
    );

    return 0;
}
