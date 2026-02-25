/* Converted to C from ASM: r_staticmodel.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_staticmodel.cpp */

#include "common_types.h"
#include "imports.h"

extern int XModelGetNumLods(struct XModel *xmodel);
extern int XModelGetSurfaces(struct XModel *xmodel, void *xsurfs, int lodIndex, void *partBits);
extern void *Hunk_AllocAlignInternal(int size, int alignment);

extern r_globals_t *rg; /* 0x195eec8 */
extern r_global_permanent_t *rgp; /* 0x195eebc */

long unsigned int R_InitStaticModelDynamicData(int smodelIndex)
{
    int xsurfs;
    int partBits;
    int lodIndex;
    int maxSurfs;
    int instanceSize;
    void *buffer;

    GfxStaticModelDynamic *smodelDync = &rg->smodelDyncs[smodelIndex];
    struct XModel *xmodel = rgp->world->smodelInsts[smodelIndex].model;

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
    smodelDync->staticSurfs = (GfxStaticSurface *)buffer;
    memset(buffer, 0, instanceSize);
}
