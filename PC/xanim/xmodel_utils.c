/* Converted to C from ASM: xmodel_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xmodel_utils.cpp */

#include "common_types.h"
#include "imports.h"

extern const char *SL_ConvertToString(unsigned int stringValue);

static TestLod g_testLods[4]; /* 0x7ef000 */

const char * XModelGetName(const XModel *model);
unsigned char XModelGetFlags(const XModel *model);
const char * XModelGetSurfaceName(const XModel *model, int subMatIndex, int lod);
int XModelGetSurfaces(const XModel *model, struct XSurface_s * * *surfaces, int lod, int * *partBits);
int XModelGetNumLods(const XModel *model);
int XModelNumBones(const XModel *model);
const DObjAnimMat * XModelGetBasePose(const XModel *model);
const DObjAnimMat * XModelGetBasePoseBone(const XModel *model, int skelMatBoneOffset);
jpeg_scan_info XModelSetTestLods(int lodLevel, float dist);
float XModelGetLodOutDist(const XModel *model);
int XModelGetLodForDist(const XModel *model, float dist);

/* line 23 */
const char *XModelGetName(const XModel *model)
{
    return *(const char **)((byte *)model + 0x88);
}

/* line 34 */
unsigned char XModelGetFlags(const XModel *model)
{
    return *(unsigned char *)((byte *)model + 0x8c);
}

/* line 45 */
const char *XModelGetSurfaceName(const XModel *model, int subMatIndex, int lod)
{
    unsigned short *materialNames = *(unsigned short **)((byte *)model + lod * 20 + 0x10);
    unsigned short name = materialNames[subMatIndex];
    if (name == 0)
        return "";
    return SL_ConvertToString(name);
}

/* line 62 */
int XModelGetSurfaces(const XModel *model, struct XSurface_s ***surfaces, int lod, int **partBits)
{
    byte *lodEntry = (byte *)model + lod * 20 + 4;
    byte *surfData = *(byte **)(lodEntry + 0x10);
    *surfaces = *(struct XSurface_s ***)(surfData);
    *partBits = (int *)(surfData + 4);
    return *(short *)(lodEntry + 8);
}

/* line 84 */
int XModelGetNumLods(const XModel *model)
{
    return *(short *)((byte *)model + 0x7c);
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
jpeg_scan_info XModelSetTestLods(int lodLevel, float dist)
{
    *(float *)((byte *)&g_testLods[lodLevel] + 4) = dist;
    *(byte *)&g_testLods[lodLevel] = (dist >= 0.0f) ? 1 : 0;
}

/* line 135 */
float XModelGetLodOutDist(const XModel *model)
{
    int lastLod = *(short *)((byte *)model + 0x7c) - 1;
    if (*(byte *)&g_testLods[lastLod] != 0)
        return *(float *)((byte *)&g_testLods[lastLod] + 4);
    return *(float *)((byte *)model + lastLod * 20 + 4);
}

/* line 149 */
int XModelGetLodForDist(const XModel *model, float dist)
{
    int numLods = *(short *)((byte *)model + 0x7c);
    byte *lodEntry = (byte *)model + 4;
    int i;

    for (i = 0; i < numLods; i++) {
        float lodDist;
        if (*(byte *)&g_testLods[i] != 0)
            lodDist = *(float *)((byte *)&g_testLods[i] + 4);
        else
            lodDist = *(float *)lodEntry;

        if (lodDist == 0.0f || lodDist > dist)
            return i;

        lodEntry += 20;
    }
    return -1;
}
