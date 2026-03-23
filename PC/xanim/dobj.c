/* ASM dump from: dobj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/dobj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/xanim/xanim_local.h"
 *   #include "PC/xanim/xanim_public.h"
 */

extern int XModelGetLodForDist(XModel *model, float dist);
extern const char * SL_ConvertToString(unsigned int stringValue);
extern void SL_RemoveRefToStringOfLen(unsigned int stringValue, int len);
extern unsigned int SL_GetStringOfLen(void *duplicatePartBits, int user, int len, int flag);

static unsigned int g_empty; /* g_empty */

void DObjInit(void);
void DObjShutdown(void);
void DObjAbort(void);
Bool DObjIgnoreCollision(const DObj *obj, int modelIndex);
int DObjSkelIsBoneUpToDate(DObj *obj, int boneIndex);
int DObjSkelAreBonesUpToDate(const DObj *obj, int *partBits);
void DObjFree(DObj_s *obj);
int DObjGetAllocSkelSize(const DObj *obj);
qboolean DObjSkelExists(const DObj *obj, int timeStamp);
void DObjSkelClear(const DObj *obj);
void DObjCreateSkel(const DObj *obj, char *buf, int timeStamp);
int DObjGetNumModels(const DObj *obj);
XModel * DObjGetModel(const DObj *obj, int modelIndex);
DObjAnimMat * DObjGetRotTransArray(const DObj *obj);
int DObjGetMatOffset(const DObj *obj, int modelIndex);
void DObjGetBoneInfo(const DObj *obj, XBoneInfo * *boneInfo);
int DObjGetNumSurfaces(const DObj *obj, char *lods);
struct XSurface_s * DObjGetSurface(const DObj *obj, int modelIndex, int subMatIndex, int lod);
const char * DObjGetSurfaceName(DObj *obj, int modelIndex, int subMatIndex, int lod);
int DObjGetBoneIndex(const DObj *obj, unsigned int boneName);
XAnimTree * DObjGetTree(const DObj *obj);
int DObjBad(const DObj *obj);
int DObjNumBones(const DObj *obj);
int DObjGetLodForDist(const DObj *obj, int modelIndex, float dist);
float DObjGetLodOutDist(const DObj *obj);
int DObjHasContents(DObj *obj, int contentmask);
void DObjSetModel(DObj *obj, const XModel *model);
void DObjGetBounds(const DObj *obj, vec_t *mins, vec_t *maxs);
void DObjGeomTraceline(DObj *obj, vec_t *localStart, vec_t *localEnd, int contentmask, DObjTrace *results);
int DObjGetSurfaces(const DObj *obj, DSurface *surfaces, int *partBits, char *lods);
static void DObjCreateDuplicateParts(const DObj *obj);
void DObjCompleteHierarchyBits(const DObj *obj, int *partBits);
void DObjGetHierarchyBits(DObj *obj, int boneIndex, int *partBits);
void DObjSetLocalTagInternal(const DObj *obj, const vec_t *trans, const vec_t *angles, int boneIndex);
qboolean DObjSetLocalTag(const DObj *obj, int *partBits, unsigned int tagName, const vec_t *trans, const vec_t *angles);
qboolean DObjSetControlTagAngles(const DObj *obj, int *partBits, unsigned int tagName, vec_t *angles);
void DObjDumpInfo(const DObj *obj);
void DObjCreate(void * (*dobjModels)(), unsigned int numModels, XAnimTree_s *tree, char *buf, unsigned int entnum);
void DObjCalcSkel(const DObj *obj, int *partBits);
void DObjTraceline(DObj *obj, vec_t *start, vec_t *end, unsigned char *priorityMap, DObjTrace *trace);

/* line 23 */
void DObjInit(void)
{
    int duplicatePartBits[5] = {0, 0, 0, 0, 0};
    g_empty = SL_GetStringOfLen(duplicatePartBits, 0, 0x11, 0xc);
}

/* line 37 */
void DObjShutdown(void)
{
    if (!g_empty)
        return;
    SL_RemoveRefToStringOfLen(g_empty, 0x11);
    g_empty = 0;
}

/* line 52 */
void DObjAbort(void)
{
    g_empty = 0;
}

/* line 123 */
Bool DObjIgnoreCollision(const DObj *obj, int modelIndex)
{
    return (obj->ignoreCollision >> modelIndex) & 1;
}

/* line 580 */
int DObjSkelIsBoneUpToDate(DObj *obj, int boneIndex)
{
    DSkel *skel = obj->skel;
    return (skel->skelPartBits[boneIndex >> 5] >> (boneIndex & 0x1f)) & 1;
}

/* line 598 */
int DObjSkelAreBonesUpToDate(const DObj *obj, int *partBits)
{
    int i;
    DSkel *skel = obj->skel;
    for (i = 0; i < 4; i++) {
        if (~skel->skelPartBits[1 + i] & partBits[i])
            return 0;
    }
    return 1;
}

/* line 1142 */
void DObjFree(DObj_s *obj) {
    if (obj->tree) {
        obj->animToModel = NULL;
        obj->tree = NULL;
    }
    if (obj->duplicateParts) {
        unsigned short nameVal = obj->duplicateParts;
        if ((unsigned int)nameVal != g_empty) {
            const char *str = SL_ConvertToString(nameVal);
            int len = strlen(str + 16) + 16;
            SL_RemoveRefToStringOfLen(nameVal, len);
        }
        obj->duplicateParts = 0;
    }
}

/* line 1223 */
int DObjGetAllocSkelSize(const DObj *obj)
{
    return (obj->numBones << 5) + 0x30;
}

/* line 1236 */
qboolean DObjSkelExists(const DObj *obj, int timeStamp)
{
    if (obj->timeStamp != timeStamp)
    {
        ((DObj *)obj)->skel = NULL;
        return 0;
    }
    return obj->skel != NULL;
}

/* line 1261 */
void DObjSkelClear(const DObj *obj)
{
    ((DObj *)obj)->timeStamp = 0;
    ((DObj *)obj)->skel = NULL;
}

/* line 1273 */
void DObjCreateSkel(const DObj *obj, char *buf, int timeStamp)
{
    int i;
    DSkel *skel = (DSkel *)buf;
    ((DObj *)obj)->skel = skel;
    ((DObj *)obj)->timeStamp = timeStamp;
    for (i = 0; i < 4; i++) {
        skel->animPartBits[i] = 0;
        skel->controlPartBits[i] = 0;
        skel->skelPartBits[i] = 0;
    }
}

/* line 1301 */
int DObjGetNumModels(const DObj *obj)
{
    return obj->numModels;
}

/* line 1312 */
XModel * DObjGetModel(const DObj *obj, int modelIndex)
{
    return obj->models[modelIndex];
}

/* line 1337 */
DObjAnimMat * DObjGetRotTransArray(const DObj *obj)
{
    DSkel *skel = obj->skel;
    if (skel)
        return skel->mat;
    return 0;
}

/* line 1380 */
int DObjGetMatOffset(const DObj *obj, int modelIndex)
{
    return obj->matOffset[modelIndex];
}

/* line 1393 */
void DObjGetBoneInfo(const DObj *obj, XBoneInfo * *boneInfo) {
    int j, i;
    int numModels = obj->numModels;
    int k = 0;
    for (j = 0; j < numModels; j++) {
        XModel *model = obj->models[j];
        int size = *(short *)(*(int *)model);
        for (i = 0; i < size; i++) {
            boneInfo[k++] = &model->boneInfo[i];
        }
    }
}

/* line 1480 */
int DObjGetNumSurfaces(const DObj *obj, char *lods) {
    int numSurfaces = 0;
    int numModels = obj->numModels;
    int i;
    for (i = numModels - 1; i >= 0; i--) {
        signed char lod = lods[i];
        if (lod >= 0) {
            XModel *model = obj->models[i];
            if (model->lodInfo[(unsigned char)lod].surfs) {
                numSurfaces += model->lodInfo[(unsigned char)lod].numsurfs;
            }
        }
    }
    return numSurfaces;
}

/* line 1509 */
struct XSurface_s * DObjGetSurface(const DObj *obj, int modelIndex, int subMatIndex, int lod)
{
    XModel *model = obj->models[modelIndex];
    XModelSurfs *surfs = model->lodInfo[lod].surfs;
    int *surfList = *(int **)surfs;
    return (struct XSurface_s *)*(int *)(surfList + subMatIndex);
}

/* line 1522 */
const char * DObjGetSurfaceName(DObj *obj, int modelIndex, int subMatIndex, int lod) {
    XModel *model = obj->models[modelIndex];
    unsigned short *matNames = model->lodInfo[lod].surfNames;
    unsigned short name = matNames[subMatIndex];
    if (!name)
        return (const char *)str_00217dc0;
    return SL_ConvertToString(name);
}
