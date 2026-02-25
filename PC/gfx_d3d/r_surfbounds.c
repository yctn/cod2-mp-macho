/* Converted to C from ASM: r_surfbounds.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_surfbounds.cpp */

#include "common_types.h"
#include "imports.h"

extern void GetRotatedBounds(const void *surfBounds, const void *entityBounds, const void *entityAxis, void *out);

extern const vec_t * (*R_BoundsForDrawSurfTable[8])(); /* 0x0 */
static int surfBoundsGlob; /* 0xce7000 */

extern char *r_sceneData; /* 0x195f0f4 */
extern char *r_world; /* 0x195eebc */

const vec_t *R_BoundsForSurf_Triangles(const GfxDrawSurf *drawSurf, int entIndex)
{
    char *surfData = (char *)drawSurf->surface + 4;

    if (entIndex > 0x7fd)
        return (const vec_t *)surfData;

    char *entityBase = *(char **)(r_sceneData + 0x10);
    char *entAddr = entityBase + entIndex * 116;
    GetRotatedBounds(surfData, entAddr + 0x3c, entAddr + 0x14, &surfBoundsGlob);
    return (const vec_t *)&surfBoundsGlob;
}

const vec_t *R_BoundsForSurf_ModelInst(const GfxDrawSurf *drawSurf, int entIndex)
{
    return (const vec_t *)(r_sceneData + entIndex * 52 + 0x5d8);
}

const vec_t *R_BoundsForSurf_StaticModelCached(const GfxDrawSurf *drawSurf, int entIndex)
{
    char *worldData = *(char **)(r_world + 0x109c);
    char *surfPtr = (char *)drawSurf->surface;
    int smodelIndex = *(int *)(*(int *)(surfPtr + 8) + 4);
    char *modelsBase = *(char **)(worldData + 0xf8);
    return (const vec_t *)(modelsBase + smodelIndex * 96 + 0x14);
}

const vec_t *R_BoundsForDrawSurf(const GfxDrawSurf *surf)
{
    int surfType = *surf->surface;
    const vec_t * (*boundsFunc)() = R_BoundsForDrawSurfTable[surfType];
    int entIndex;
    int sortVal;

    if (!boundsFunc)
        return 0;

    sortVal = *(int *)&surf->sort;
    if (sortVal >= 0) {
        entIndex = (sortVal >> 4) & 0xfff;
    } else {
        entIndex = ((unsigned int)sortVal >> 19) & 0xfff;
    }
    if (entIndex >= 0x800)
        entIndex = 0x7fe;

    return boundsFunc(surf, entIndex);
}
