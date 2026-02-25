/* Converted to C from ASM: r_staticmodel.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_staticmodel.cpp */

#include "common_types.h"
#include "imports.h"

extern int XModelGetNumLods(void *xmodel);
extern int XModelGetSurfaces(void *xmodel, void *xsurfs, int lodIndex, void *partBits);
extern void *Hunk_AllocAlignInternal(int size, int alignment);

extern char *r_backend; /* 0x195eec8 */
extern char *r_world; /* 0x195eebc */

long unsigned int R_InitStaticModelDynamicData(int smodelIndex)
{
    int xsurfs;
    int partBits;
    int lodIndex;
    int maxSurfs;
    int instanceSize;
    void *buffer;

    /* Get smodelDync entry (8 bytes per entry) */
    char *dynBase = *(char **)(r_backend + 0x3194);
    char *smodelDync = dynBase + smodelIndex * 8;

    /* Get xmodel from static model data */
    char *worldData = *(char **)(r_world + 0x109c);
    char *modelsBase = *(char **)(worldData + 0xf8);
    void *xmodel = *(void **)(modelsBase + smodelIndex * 96 + 0x10);

    /* Find max surface count across all LODs */
    int lodCount = XModelGetNumLods(xmodel);
    maxSurfs = 0;
    if (lodCount > 0) {
        for (lodIndex = 0; lodIndex < lodCount; lodIndex++) {
            int surfCount = XModelGetSurfaces(xmodel, &xsurfs, lodIndex, &partBits);
            if (surfCount > maxSurfs)
                maxSurfs = surfCount;
        }
    }

    instanceSize = maxSurfs << 4;
    buffer = Hunk_AllocAlignInternal(instanceSize, 4);
    *(void **)(smodelDync + 4) = buffer;
    memset(buffer, 0, instanceSize);
}
