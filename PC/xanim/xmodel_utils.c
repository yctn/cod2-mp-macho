/* Converted to C from ASM: xmodel_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xmodel_utils.cpp */

#include "common_types.h"
#include "imports.h"

extern const char *SL_ConvertToString(unsigned int stringValue);

static TestLod g_testLods[4]; /* g_testLods */

const char * XModelGetName(const XModel *model);
unsigned char XModelGetFlags(const XModel *model);
const char * XModelGetSurfaceName(const XModel *model, int subMatIndex, int lod);
int XModelGetSurfaces(const XModel *model, struct XSurface_s * * *surfaces, int lod, int * *partBits);
int XModelGetNumLods(const XModel *model);
int XModelNumBones(const XModel *model);
const DObjAnimMat * XModelGetBasePose(const XModel *model);
const DObjAnimMat * XModelGetBasePoseBone(const XModel *model, int skelMatBoneOffset);
void XModelSetTestLods(int lodLevel, float dist);
float XModelGetLodOutDist(const XModel *model);
int XModelGetLodForDist(const XModel *model, float dist);

/* line 23 */
const char *XModelGetName(const XModel *model)
{
    return model->name;
}

/* line 34 */
unsigned char XModelGetFlags(const XModel *model)
{
    return model->flags;
}

/* line 45 */
const char *XModelGetSurfaceName(const XModel *model, int subMatIndex, int lod)
{
    unsigned short *materialNames = model->lodInfo[lod].surfNames;
    unsigned short name = materialNames[subMatIndex];
    if (name == 0)
        return "";
    return SL_ConvertToString(name);
}

/* line 62 */
int XModelGetSurfaces(const XModel *model, struct XSurface_s ***surfaces, int lod, int **partBits)
{
    XModelSurfs *surfData = model->lodInfo[lod].surfs;
    if (!surfData) {
        *surfaces = NULL;
        *partBits = NULL;
        return 0;
    }
    *surfaces = *(struct XSurface_s ***)(surfData);
    *partBits = (int *)((byte *)surfData + 4);
    return model->lodInfo[lod].numsurfs;
}

/* line 84 */
int XModelGetNumLods(const XModel *model)
{
    return model->numLods;
}

/* line 95 */
int XModelNumBones(const XModel *model)
{
    return *(short *)(*(byte **)model);
}

/* line 107 */
const DObjAnimMat *XModelGetBasePose(const XModel *model)
{
    return (const DObjAnimMat *)(*(byte **)model + 0x44);
}

/* line 113 */
const DObjAnimMat *XModelGetBasePoseBone(const XModel *model, int skelMatBoneOffset)
{
    return (const DObjAnimMat *)(*(byte **)model + 0x44 + ((unsigned int)skelMatBoneOffset >> 1));
}

/* line 175 */
void XModelSetTestLods(int lodLevel, float dist)
{
    *(float *)((byte *)&g_testLods[lodLevel] + 4) = dist;
    *(byte *)&g_testLods[lodLevel] = (dist >= 0.0f) ? 1 : 0;
}

/* line 135 */
float XModelGetLodOutDist(const XModel *model)
{
    int lastLod = model->numLods - 1;
    if (*(byte *)&g_testLods[lastLod] != 0)
        return *(float *)((byte *)&g_testLods[lastLod] + 4);
    return model->lodInfo[lastLod].dist;
}

/* line 149 */
int XModelGetLodForDist(const XModel *model, float dist)
{
    int numLods = model->numLods;
    int i;

    for (i = 0; i < numLods; i++) {
        float lodDist;
        if (*(byte *)&g_testLods[i] != 0)
            lodDist = *(float *)((byte *)&g_testLods[i] + 4);
        else
            lodDist = model->lodInfo[i].dist;

        if (lodDist == 0.0f || lodDist > dist)
            return i;
    }
    return -1;
}
