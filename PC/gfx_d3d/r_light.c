/* Decompiled from: r_light.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_light.cpp */

#include "common_types.h"
#include "imports.h"

extern struct lightGlob_type lightGlob; /* 0x0 */
extern refimport_t *ri;                 /* 0x195eee0 */
extern r_global_permanent_t *rgp;       /* 0x195eebc */
extern r_globals_t *rg;                 /* 0x195eec8 */
extern GfxScene *gfxScene;             /* 0x195f0f4 */
extern const dvar_t *r_dlightLimit;    /* 0x195eeac */
extern GfxBackEndData **gfxBuf;        /* 0x195eef4 */

extern GfxLightDef *R_LoadLightDef(const char *name);
extern void R_Error(int level, const char *fmt, ...);
extern int stricmp(const char *s1, const char *s2);
extern const vec_t Vec3DistanceSq(const vec_t *p1, const vec_t *p2);
extern float PointToBoxDistSq(const vec_t *pt, const vec_t *mins, const vec_t *maxs);
extern const vec_t *R_BoundsForDrawSurf(const GfxDrawSurf *surf);

GfxLightDef * R_RegisterLightDef(const char *name);
long unsigned int R_InitLightDefs(void);
long unsigned int R_ShutdownLightDefs(void);
int R_GetPointLightPartitions(const GfxDrawSurf *drawSurfs, int drawSurfCount, PointLightPartition *partitions, int partitionLimit);

/* line 21 */
GfxLightDef * R_RegisterLightDef(const char *name)
{
    int defIndex;
    GfxLightDef *result;

    for (;;) {
        /* Search existing defs for a match */
        if (lightGlob.defCount > 0) {
            for (defIndex = 0; defIndex < lightGlob.defCount; defIndex++) {
                if (stricmp(name, lightGlob.defs[defIndex]->name) == 0) {
                    return lightGlob.defs[defIndex];
                }
            }
        }

        /* Not found in existing defs */
        if (lightGlob.defCount == 64) {
            /* Too many light defs loaded - print them all */
            ri->Printf(0, "Exceeded %i light defs. Currently loaded light defs:\n");
            if (lightGlob.defCount > 0) {
                for (defIndex = 0; defIndex < lightGlob.defCount; defIndex++) {
                    ri->Printf(0, "  %s\n", lightGlob.defs[defIndex]->name);
                }
            }
            R_Error(1, "Can't load light def %s; %i unique light defs already loaded", name, lightGlob.defCount);
        }

        /* Try to load the light def */
        result = R_LoadLightDef(name);
        if (result != NULL) {
            /* Successfully loaded - add to the global list */
            lightGlob.defs[lightGlob.defCount] = result;
            lightGlob.defCount++;
            return result;
        }

        /* Load failed - try the default if we haven't already */
        if (stricmp(name, "default") == 0) {
            R_Error(1, "Can't load the default light def '%s'", name);
        }
        name = "default";
    }
}

/* line 62 */
long unsigned int R_InitLightDefs(void)
{
    rgp->dlightDef = R_RegisterLightDef("default");
    return 0;
}

/* line 71 */
long unsigned int R_ShutdownLightDefs(void)
{
    lightGlob.defCount = 0;
    return 0;
}

/*
 * Quickselect to find the top wantedCount most important lights.
 * Importance is measured by radius^2 / distanceSq - lights with larger
 * radius and closer distance are more important.
 *
 * After this function, lights[0..wantedCount-1] will contain the
 * wantedCount most important lights (in no particular order).
 */
static void R_SelectClosestLights(const GfxLight **lights, int totalCount, int wantedCount, const vec_t *viewOrg)
{
    const GfxLight *pivotLight;
    const GfxLight *tmp;
    float cutoff_a, cutoff_b;
    float dist_a, dist_b;
    float score_a, score_b;
    int i, j;

    for (;;) {
        pivotLight = lights[0];
        i = 0;

        /* Forward scan: find first element less important than pivot */
        for (;;) {
            i++;
            if (i >= totalCount) {
                break;
            }

            cutoff_a = lights[i]->position[3];
            cutoff_b = pivotLight->position[3];
            dist_a = Vec3DistanceSq(&lights[i]->position[0], viewOrg);
            dist_b = Vec3DistanceSq(&pivotLight->position[0], viewOrg);

            score_a = cutoff_a * cutoff_a * dist_b;
            score_b = cutoff_b * cutoff_b * dist_a;

            if (score_a < score_b) {
                break;
            }
        }

        /* Reverse scan: find elements from back that are more important */
        j = totalCount - 1;
        while (i <= j) {
            const GfxLight *backLight = lights[j];

            cutoff_a = pivotLight->position[3];
            cutoff_b = backLight->position[3];
            dist_a = Vec3DistanceSq(&pivotLight->position[0], viewOrg);
            dist_b = Vec3DistanceSq(&backLight->position[0], viewOrg);

            score_a = cutoff_a * cutoff_a * dist_b;
            score_b = cutoff_b * cutoff_b * dist_a;

            if (score_a < score_b) {
                /* lights[j] is more important than pivot, swap to position i */
                tmp = lights[i];
                lights[i] = lights[j];
                lights[j] = tmp;

                /* Continue forward scan from i+1 */
                for (;;) {
                    i++;
                    if (i >= j) {
                        goto partition_done;
                    }

                    cutoff_a = lights[i]->position[3];
                    cutoff_b = pivotLight->position[3];
                    dist_a = Vec3DistanceSq(&lights[i]->position[0], viewOrg);
                    dist_b = Vec3DistanceSq(&pivotLight->position[0], viewOrg);

                    score_a = cutoff_a * cutoff_a * dist_b;
                    score_b = cutoff_b * cutoff_b * dist_a;

                    if (score_a < score_b) {
                        break;
                    }
                }
                continue;
            }
            j--;
        }

    partition_done:
        /* i = number of elements more important than pivot (not counting pivot itself) */
        if (totalCount == i) {
            /* All elements were more important than pivot.
             * Swap pivot to the back. */
            tmp = lights[0];
            lights[0] = lights[j];
            lights[j] = tmp;
            i--;
        }

        if (wantedCount == i) {
            return;
        }

        if (wantedCount < i) {
            /* Enough important lights in the left portion, narrow down */
            totalCount = i;
        } else {
            /* Need more lights from the right portion */
            lights = &lights[i];
            totalCount -= i;
            wantedCount -= i;
        }
    }
}

/*
 * For a single light, test all draw surfs and add matching ones to the
 * scene's draw surf list. A draw surf matches if its bounding box is
 * within the light's cutoff distance.
 */
static void R_AddDrawSurfsForLight(const GfxLight *light, const GfxDrawSurf *drawSurfs, int drawSurfCount)
{
    float cutoffDistSq;
    float distSq;
    const vec_t *origin;
    const vec_t *bounds;
    int lastDrawSurf;
    int j;
    const GfxDrawSurf *surf;
    GfxScene *scn;
    GfxDrawSurf *dstSurfs;
    int dsc;

    origin = &light->position[0];
    cutoffDistSq = light->position[3] * light->position[3];

    lastDrawSurf = drawSurfCount - 1;
    if (lastDrawSurf < 0) {
        return;
    }

    surf = &drawSurfs[lastDrawSurf];
    for (j = 0; j < drawSurfCount; j++) {
        bounds = R_BoundsForDrawSurf(surf);
        if (bounds != NULL) {
            distSq = PointToBoxDistSq(origin, bounds, bounds + 3);
            if (distSq <= cutoffDistSq) {
                /* Copy draw surf into scene's draw surf buffer */
                scn = gfxScene;
                dsc = scn->drawSurfCount;
                dstSurfs = scn->drawSurfs;
                dstSurfs[dsc] = *surf;

                /* Increment both scene and backend draw surf counts */
                gfxScene->drawSurfCount++;
                (*gfxBuf)->drawSurfCount++;
            }
        }
        surf--;
    }
}

/* line 205 */
int R_GetPointLightPartitions(const GfxDrawSurf *drawSurfs, int drawSurfCount, PointLightPartition *partitions, int partitionLimit)
{
    const GfxLight *visibleLights[16];
    int visibleCount;
    int visibleLimit;
    int partitionCount;
    int i;
    PointLightPartition *curPartition;
    const GfxLight *light;
    int drawSurfsBefore;

    /* line 217: Gather non-culled dynamic lights */
    visibleCount = 0;
    if (gfxScene->dlightCount > 0) {
        for (i = 0; i < gfxScene->dlightCount; i++) {
            if (!gfxScene->dlightCulled[i]) {
                visibleLights[visibleCount] = &gfxScene->dlights[i];
                visibleCount++;
            }
        }
    }

    /* line 227: Clamp by r_dlightLimit dvar and partitionLimit */
    visibleLimit = partitionLimit;
    if (r_dlightLimit->current.integer < visibleLimit) {
        visibleLimit = r_dlightLimit->current.integer;
    }

    /* line 228: If we have more visible lights than the limit, select the best ones */
    if (visibleLimit < visibleCount) {
        R_SelectClosestLights(visibleLights, visibleCount, visibleLimit, &rg->viewOrg[0]);
        visibleCount = visibleLimit;
    }

    /* line 235: Build partitions for each visible light */
    if (visibleCount <= 0) {
        return 0;
    }

    partitionCount = 0;
    curPartition = partitions;

    for (i = 0; i < visibleCount; i++) {
        light = visibleLights[i];

        /* line 237-240: Set up partition for this light */
        curPartition->light = light;
        curPartition->firstDrawSurf = gfxScene->drawSurfCount;

        /* Test draw surfs against this light and add matching ones */
        R_AddDrawSurfsForLight(light, drawSurfs, drawSurfCount);

        /* line 241-243: Calculate how many draw surfs were added */
        curPartition->drawSurfCount = gfxScene->drawSurfCount - curPartition->firstDrawSurf;
        if (curPartition->drawSurfCount != 0) {
            partitionCount++;
            curPartition++;
        }
    }

    return partitionCount;
}
