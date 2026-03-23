/* ASM dump from: xanim.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xanim.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static XAnimInfo g_xAnimInfo[4096]; /* g_xAnimInfo */
static unsigned int g_end; /* g_end */
extern void SL_RemoveRefToString(unsigned int stringValue);
static XAnimNotify g_notifyList[128]; /* g_notifyList */
static int g_notifyListSize; /* g_notifyListSize */
static Bool g_anim_developer; /* g_anim_developer */

extern void * Hunk_AllocAlignInternal(int size, int align);
extern unsigned int SL_GetString_(const char *str, int user, int type);
extern void SL_RemoveRefToStringOfLen(unsigned int stringValue, int len);
extern void * Z_MallocInternal(int size);
extern qboolean Hunk_DataOnHunk(void *data);
extern void Hunk_AddData(int type, void *data, void *alloc);

void XAnimInit(void);
void XAnimShutdown(void);
void XAnimAbort(void);
void XAnimFree(XAnimParts *parts);
void XAnimBlend(XAnim *anims, unsigned int animIndex, const char *name, unsigned int children, unsigned int num, unsigned int flags);
XAnim * XAnimCreateAnims(const char *debugName, int size, Alloc_t Alloc);
void XAnimFreeList(XAnim *anims);
XAnim * XAnimGetAnims(const XAnimTree *tree);
float XAnimGetLength(const XAnim *anims, unsigned int animIndex);
float XAnimGetTime(const XAnimTree *tree, unsigned int animIndex);
float XAnimGetWeight(const XAnimTree *tree, unsigned int animIndex);
Bool XAnimHasFinished(const XAnimTree *tree, unsigned int animIndex);
int XAnimGetNumChildren(const XAnim *anims, unsigned int animIndex);
unsigned int XAnimGetChildAt(const XAnim *anims, unsigned int animIndex, unsigned int childIndex);
const char * XAnimGetAnimName(const XAnim *anims, unsigned int animIndex);
const char * XAnimGetAnimTreeDebugName(const XAnim *anims);
unsigned int XAnimGetAnimTreeSize(const XAnim *anims);
int DObjGetClientNotifyList(XAnimNotify * *notifyList);
static void * Hunk_AllocXAnimPrecache(int size);
Bool XAnimIsPrimitive(XAnim *anims, unsigned int animIndex);
void XAnimSetTime(XAnimTree *tree, unsigned int animIndex, float time);
void XAnimSetAnimRate(XAnimTree *tree, unsigned int animIndex, float rate);
Bool XAnimIsLooped(const XAnim *anims, unsigned int animIndex);
Bool XAnimNotetrackExists(const XAnim *anims, unsigned int animIndex, unsigned int name);
static void Z18XAnim_GetTimeIndexIhEvPK9XAnimTimePK19XAnimDynamicIndicesiPiPf(void); /* void XAnim_GetTimeIndex<unsigned char> */
static void Z28XAnim_GetTimeIndexCompressedItEvPK9XAnimTimePKT_iPiPf(void); /* void XAnim_GetTimeIndexCompressed<unsigned short> */
const char * XAnimGetAnimDebugName(const XAnim *anims, unsigned int animIndex);
XAnimTree * XAnimCreateTree(XAnim *anims, Alloc_t Alloc);
XAnimParts * XAnimPrecache(const char *name, Alloc_t Alloc);
void XAnimCreate(XAnim *anims, unsigned int animIndex, const char *name);
static unsigned int XAnimGetDescendantWithGreatestWeight(void);
int XAnimGetLengthMsec(const XAnim *anims, unsigned int anim);
void XAnimClearGoalWeight(XAnimTree *tree, unsigned int animIndex, float blendTime);
static void XAnim_CalcDeltaForTime(vec_t *posDelta);
void XAnimGetAbsDelta(const XAnim *anims, unsigned int animIndex, vec_t *rot, vec_t *trans, float time);
static void XAnimCalcRelDeltaParts(const float time1, const float time2);
void XAnimGetRelDelta(const XAnim *anims, unsigned int animIndex, vec_t *rot, vec_t *trans, float time1, float time2);
static void XAnimClearTreeWeights(XAnimTree *tree, unsigned int animIndex);
void XAnimCalcDeltaTree(const XAnimTree *tree, const Bool bClear, int bNormQuat, XAnimSimpleRotPos *rotPos);
void XAnimCalcAbsDelta(XAnimTree *tree, unsigned int animIndex, vec_t *rot, vec_t *trans);
void XAnimCalcDelta(XAnimTree *tree, unsigned int animIndex, vec_t *rot, vec_t *trans, int bUseGoalWeight);
static void XAnimResetTime(XAnimTree *tree);
static void XAnimUpdateOldTime(XAnimTree *tree, unsigned int animIndex, XAnimState *syncState, int parentHadWeight, Bool *infoExistsForParent, Bool *childHadWeightForParent);
void DObjInitServerTime(DObj *obj, float dtime);
static int XAnimSetGoalWeightInternal(XAnimTree *tree, unsigned int animIndex, float rate, unsigned int notifyName, unsigned int notifyType);
void XAnimSetCompleteGoalWeight(XAnimTree *tree, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart);
void XAnimCloneAnimTree(const XAnimTree *from, XAnimTree *to);
void XAnimFreeTree(XAnimTree *tree, Free_t Free);
void XAnimClearTree(XAnimTree *tree);
void XAnimCalc(const DObj *obj, unsigned int animIndex, float weightScale, XAnimPart (*rotTransArray)(), int bClear, int bNormQuat, XAnimCalcAnimInfo *info, int rotTransArrayIndex);
void DObjCalcAnim(const DObj *obj, int *partBits);
static float XAnimGetAverageRateFrequency(void);
void XAnimClearTreeGoalWeights(XAnimTree *tree, unsigned int animIndex, float blendTime);
void XAnimClearTreeGoalWeightsStrict(XAnimTree *tree, unsigned int animIndex, float blendTime);
static void XAnimProcessServerNotify(const XAnimTree *tree, XAnimInfo *info, float time, XAnimTree *tree_3, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, int bRestart);
int XAnimSetCompleteGoalWeightKnobAll(XAnimTree *tree, unsigned int animIndex, unsigned int rootIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, int bRestart);
int XAnimSetGoalWeight(XAnimTree *tree, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart);
static void XAnimDisplay(const XAnimTree *tree, int depth);
void DObjDisplayAnim(DObj *obj);
static void XAnimFillInSyncNodes_r(Bool bLoop);
static void XAnimSetupSyncNodes_r(XAnim *anims);
void XAnimSetupSyncNodes(XAnim *anims);
static void XAnimProcessClientNotify(void);
static void XAnimUpdateInfoSyncInternal(XAnimState *syncState, float dtime);
static void XAnimUpdateInfoInternal(const XAnimTree *tree, float dtime);
void DObjUpdateClientInfo(DObj *obj, float dtime);
static float XAnimGetNotifyFracServer(const XAnimState *syncState, const XAnimState *nextSyncState);
static float XAnimGetServerNotifyFracSyncTotal(const XAnimEntry *anim, const XAnimState *syncState, const XAnimState *nextSyncState, float dtime);
static float XAnimFindServerNoteTrack(float dtime);
int DObjUpdateServerInfo(DObj *obj, float dtime, int bNotify);

/* line 117 */
void XAnimInit(void) {
    int i;
    for (i = 0; i < 4096; i++) {
        g_xAnimInfo[i].prev = (unsigned short)((i + 4095) % 4096);
        g_xAnimInfo[i].next = (unsigned short)((i + 1) % 4096);
    }
    g_xAnimInfo[0].s.time = 0.0f;
    g_xAnimInfo[0].s.oldTime = 0.0f;
    g_xAnimInfo[0].s.timeCount = 0;
    g_xAnimInfo[0].s.oldTimeCount = 0;
    g_end = SL_GetString_(str_00217830, 0, 3);
    g_anim_developer = *(int *)(*(byte **)imp_com_developer + 8) != 0;
}

/* line 155 */
void XAnimShutdown(void)
{
    if (!g_end)
        return;
    SL_RemoveRefToString(g_end);
    g_end = 0;
}

/* line 169 */
void XAnimAbort(void)
{
    g_end = 0;
}

/* line 175 */
void XAnimFree(XAnimParts *parts) {
    unsigned short *boneNames = parts->names;
    int boneCount = parts->boneCount;
    int i;

    if (boneCount > 0) {
        for (i = 0; i < boneCount; i++) {
            SL_RemoveRefToString(boneNames[i]);
        }
    }

    if (parts->notifyCount) {
        XAnimNotifyInfo *notify = parts->notify;
        int notifyCount = parts->notifyCount;
        for (i = 0; i < notifyCount; i++) {
            SL_RemoveRefToString(*(unsigned short *)((byte *)notify + i * 8));
        }
    }
}

/* line 307 */
void XAnimBlend(XAnim *anims, unsigned int animIndex, const char *name, unsigned int children, unsigned int num, unsigned int flags) {
    unsigned int j;

    anims->entries[animIndex].numAnims = (unsigned short)num;
    anims->entries[animIndex].u.s.flags = (unsigned short)flags;
    anims->entries[animIndex].u.s.children = (unsigned short)children;

    for (j = 0; j < num; j++) {
        anims->entries[children + j].parent = (unsigned short)animIndex;
    }

    if (anims->debugAnimNames) {
        int len = strlen(name) + 1;
        char *nameCopy = (char *)Z_MallocInternal(len);
        strcpy(nameCopy, name);
        ((char **)anims->debugAnimNames)[animIndex] = nameCopy;
    }
}

/* line 339 */
XAnim * XAnimCreateAnims(const char *debugName, int size, Alloc_t Alloc) {
    XAnim *anims = (XAnim *)Alloc(0xc + size * 8);
    *(int *)((byte *)anims + 4) = size;

    if (g_anim_developer) {
        int len = strlen(debugName) + 1;
        char *nameCopy = (char *)Z_MallocInternal(len);
        strcpy(nameCopy, debugName);
        *(char **)anims = nameCopy;
        *(char **)((byte *)anims + 8) = (char *)Z_MallocInternal(size * 4);
    }

    if (Hunk_DataOnHunk(anims)) {
        Hunk_AddData(6, anims, (void *)Alloc);
    }
    return anims;
}
