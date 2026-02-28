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
static void XAnimCalcDeltaTree(const XAnimTree *tree, const Bool bClear, int bNormQuat, XAnimSimpleRotPos *rotPos);
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
static void XAnimCalc(const DObj *obj, unsigned int animIndex, float weightScale, XAnimPart (*rotTransArray)(), int bClear, int bNormQuat, XAnimCalcAnimInfo *info, int rotTransArrayIndex);
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
__attribute__((naked))
void XAnimInit(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "xorl %edx, %edx\n"
        "movl $g_xAnimInfo, %ecx\n"
        "jmp .Lf38dd0_00038dfe\n"
        /* { scope 1 */
        ".Lf38dd0_00038ddf:\n"
        "movw %ax, 8(%ecx)\n" /* line 123 */
        "addl $1, %edx\n" /* line 124 */
        "movl %edx, %eax\n"
        "andl $0x80000fff, %eax\n"
        "js .Lf38dd0_00038e26\n"
        ".Lf38dd0_00038def:\n"
        "movw %ax, 0xa(%ecx)\n"
        "addl $0x28, %ecx\n"
        "cmpl $__mh_execute_header, %edx\n" /* line 121 */
        "je .Lf38dd0_00038e40\n"
        ".Lf38dd0_00038dfe:\n"
        "leal 0xfff(%edx), %eax\n" /* line 123 */
        "andl $0x80000fff, %eax\n"
        "jns .Lf38dd0_00038ddf\n"
        "subl $1, %eax\n"
        "orl $0xfffff000, %eax\n"
        "addl $1, %eax\n"
        "movw %ax, 8(%ecx)\n"
        "addl $1, %edx\n" /* line 124 */
        "movl %edx, %eax\n"
        "andl $0x80000fff, %eax\n"
        "jns .Lf38dd0_00038def\n"
        ".Lf38dd0_00038e26:\n"
        "subl $1, %eax\n"
        "orl $0xfffff000, %eax\n"
        "addl $1, %eax\n"
        "movw %ax, 0xa(%ecx)\n"
        "addl $0x28, %ecx\n"
        "cmpl $__mh_execute_header, %edx\n" /* line 121 */
        "jne .Lf38dd0_00038dfe\n"
        ".Lf38dd0_00038e40:\n"
        "xorl %eax, %eax\n" /* line 127 */
        "movl %eax, g_xAnimInfo+12\n" /* line 129 */
        "movl %eax, g_xAnimInfo+16\n" /* line 130 */
        "movw $0, g_xAnimInfo+20\n" /* line 133 */
        "movw $0, g_xAnimInfo+22\n" /* line 134 */
        "movl $3, 8(%esp)\n" /* line 136 */
        "movl $0, 4(%esp)\n"
        "movl $str_00217830, (%esp)\n" /* "end" */
        "calll SL_GetString_\n"
        "movl %eax, g_end\n"
        "movl imp_com_developer, %eax\n" /* line 141 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "setne g_anim_developer\n"
        /* } scope */
        "leave\n" /* line 152 */
        "retl\n"
    );
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
__attribute__((naked))
void XAnimFree(XAnimParts *parts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 175 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 183 | parts */
        "movl 0x10(%eax), %edi\n" /* boneNames */
        "movswl 0xe(%eax), %esi\n" /* line 184 | notifyInfoIndex */
        "testl %esi, %esi\n" /* line 185 | notifyInfoIndex */
        "jg .Lf38eca_00038ef4\n"
        "movl %eax, %ecx\n"
        "movl 0x1c(%ecx), %ebx\n" /* line 188 | notify */
        "cmpb $0, 0xc(%ecx)\n"
        "jne .Lf38eca_00038f15\n"
        /* } scope */
        ".Lf38eca_00038eec:\n"
        "addl $0x1c, %esp\n" /* line 190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf38eca_00038ef4:\n"
        "xorl %ebx, %ebx\n" /* line 185 | notify */
        ".Lf38eca_00038ef6:\n"
        "movzwl (%edi, %ebx, 2), %eax\n" /* line 186 | boneNames */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "addl $1, %ebx\n" /* line 185 | notify */
        "cmpl %ebx, %esi\n" /* notify, notifyInfoIndex */
        "jne .Lf38eca_00038ef6\n"
        "movl 8(%ebp), %ecx\n" /* parts */
        "movl 0x1c(%ecx), %ebx\n" /* line 188 | notify */
        "cmpb $0, 0xc(%ecx)\n"
        "je .Lf38eca_00038eec\n"
        ".Lf38eca_00038f15:\n"
        "xorl %esi, %esi\n" /* notifyInfoIndex */
        ".Lf38eca_00038f17:\n"
        "movzwl (%ebx), %eax\n" /* line 189 | notify */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "addl $1, %esi\n" /* line 188 | notifyInfoIndex */
        "addl $8, %ebx\n" /* notify */
        "movswl %si, %edx\n" /* notifyInfoIndex */
        "movl 8(%ebp), %ecx\n" /* parts */
        "movzbl 0xc(%ecx), %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lf38eca_00038f17\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 307 */
__attribute__((naked))
void XAnimBlend(XAnim *anims, unsigned int animIndex, const char *name, unsigned int children, unsigned int num, unsigned int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 307 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* anims */
        "movl 0x14(%ebp), %ecx\n" /* children */
        "movl 0x18(%ebp), %edi\n" /* num */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 315 | animIndex */
        "leal (%esi, %edx, 8), %eax\n" /* anims */
        "leal 0xc(%eax), %edx\n"
        "movw %di, 0xc(%eax)\n" /* line 316 | num */
        "movl 0x1c(%ebp), %eax\n" /* line 318 | flags */
        "movw %ax, 4(%edx)\n"
        "movw %cx, 6(%edx)\n" /* line 320 */
        "testl %edi, %edi\n" /* line 323 | num */
        "je .Lf38f3e_00038f83\n"
        "movl 0xc(%ebp), %ebx\n" /* animIndex */
        "xorl %edx, %edx\n"
        "movzwl %cx, %ecx\n"
        ".Lf38f3e_00038f74:\n"
        "leal (%edx, %ecx), %eax\n" /* line 325 */
        "movw %bx, 0xe(%esi, %eax, 8)\n" /* anims */
        "addl $1, %edx\n" /* line 323 */
        "cmpl %edx, %edi\n" /* num */
        "jne .Lf38f3e_00038f74\n"
        ".Lf38f3e_00038f83:\n"
        "movl 8(%esi), %edx\n" /* line 329 | anims */
        "testl %edx, %edx\n"
        "je .Lf38f3e_00038fbb\n"
        "cld\n" /* line 332 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0x10(%ebp), %edi\n" /* name, num */
        "repne scasb %es:(%edi), %al\n" /* num */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* line 333 | name */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "movl 8(%esi), %eax\n" /* line 334 | anims */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        "movl %ebx, (%eax, %edx, 4)\n"
        /* } scope */
        ".Lf38f3e_00038fbb:\n"
        "addl $0x1c, %esp\n" /* line 336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 339 */
__attribute__((naked))
XAnim * XAnimCreateAnims(const char *debugName, int size, Alloc_t Alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 339 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 353 | size */
        "leal 0xc(, %edx, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x10(%ebp)\n" /* Alloc */
        "movl %eax, %esi\n" /* anims */
        "movl 0xc(%ebp), %eax\n" /* line 354 | size */
        "movl %eax, 4(%esi)\n" /* anims */
        "cmpb $0, g_anim_developer\n" /* line 356 */
        "jne .Lf38fc4_0003901b\n"
        ".Lf38fc4_00038fee:\n"
        "movl %esi, (%esp)\n" /* line 365 | anims */
        "calll Hunk_DataOnHunk\n"
        "testl %eax, %eax\n"
        "je .Lf38fc4_00039011\n"
        "movl 0x10(%ebp), %eax\n" /* line 366 | Alloc */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* anims */
        "movl $6, (%esp)\n"
        "calll Hunk_AddData\n"
        /* } scope */
        ".Lf38fc4_00039011:\n"
        "movl %esi, %eax\n" /* line 369 | anims */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf38fc4_0003901b:\n"
        "cld\n" /* line 358 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* debugName */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl 8(%ebp), %edx\n" /* line 359 | debugName */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl %ebx, (%esi)\n" /* line 360 | anims */
        "movl 0xc(%ebp), %eax\n" /* line 361 | size */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 8(%esi)\n" /* anims */
        "jmp .Lf38fc4_00038fee\n"
    );
}

/* line 382 */
__attribute__((naked))
void XAnimFreeList(XAnim *anims)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 382 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* anims */
        /* { scope 1 */
        "movl (%edi), %eax\n" /* line 386 | anims */
        "testl %eax, %eax\n"
        "je .Lf39058_00039078\n"
        "movl %eax, (%esp)\n" /* line 392 */
        "calll Z_FreeInternal\n"
        "movl $0, (%edi)\n" /* line 393 | anims */
        ".Lf39058_00039078:\n"
        "movl 8(%edi), %ebx\n" /* line 396 | anims */
        "testl %ebx, %ebx\n"
        "je .Lf39058_000390c9\n"
        "movl 4(%edi), %ecx\n" /* line 398 | anims */
        "testl %ecx, %ecx\n"
        "je .Lf39058_000390d1\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %eax, %eax\n"
        "movl 8(%edi), %edx\n" /* anims */
        ".Lf39058_0003908d:\n"
        "leal (, %eax, 4), %ebx\n" /* line 400 */
        "movl (%edx, %ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf39058_000390b0\n"
        "movl %eax, (%esp)\n" /* line 402 */
        "calll Z_FreeInternal\n"
        "movl 8(%edi), %eax\n" /* line 403 | anims */
        "movl $0, (%ebx, %eax)\n"
        "movl 8(%edi), %edx\n" /* anims */
        ".Lf39058_000390b0:\n"
        "addl $1, %esi\n" /* line 398 | i */
        "movl %esi, %eax\n" /* i */
        "cmpl 4(%edi), %esi\n" /* anims, i */
        "jb .Lf39058_0003908d\n"
        "movl %edx, (%esp)\n" /* line 406 */
        "calll Z_FreeInternal\n"
        "movl $0, 8(%edi)\n" /* line 407 | anims */
        /* } scope */
        ".Lf39058_000390c9:\n"
        "addl $0x1c, %esp\n" /* line 409 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf39058_000390d1:\n"
        "movl 8(%edi), %edx\n" /* anims */
        /* { scope 1 */
        "movl %edx, (%esp)\n" /* line 406 */
        "calll Z_FreeInternal\n"
        "movl $0, 8(%edi)\n" /* line 407 | anims */
        "jmp .Lf39058_000390c9\n"
    );
}

/* line 597 */
XAnim * XAnimGetAnims(const XAnimTree *tree)
{
    return *(XAnim **)tree;
}

/* line 2832 */
float XAnimGetLength(const XAnim *anims, unsigned int animIndex)
{
    byte *entry = *(byte **)((byte *)anims + 0x10 + animIndex * 8);
    return (float)*(unsigned short *)entry / *(float *)(entry + 4);
}

/* line 2868 */
float XAnimGetTime(const XAnimTree *tree, unsigned int animIndex)
{
    unsigned short info = *(unsigned short *)((char *)tree + 8 + animIndex * 2);
    if (!info)
        return 0.0f;
    return *(float *)((char *)&g_xAnimInfo[0] + info * 40 + 0x0c);
}

/* line 2887 */
float XAnimGetWeight(const XAnimTree *tree, unsigned int animIndex)
{
    unsigned short info = *(unsigned short *)((char *)tree + 8 + animIndex * 2);
    if (!info)
        return 0.0f;
    return *(float *)((char *)&g_xAnimInfo[0] + info * 40 + 0x20);
}

/* line 2906 */
__attribute__((naked))
Bool XAnimHasFinished(const XAnimTree *tree, unsigned int animIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2906 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 2915 | animIndex */
        "movl 8(%ebp), %eax\n" /* tree */
        "movzwl 8(%eax, %edx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 2916 */
        "je .Lf39164_000391af\n"
        "movzwl %ax, %eax\n" /* line 2920 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movss 0xc(%eax), %xmm1\n" /* line 2921 */
        "movss 4(%edx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf39164_000391af\n"
        "ucomiss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "jp .Lf39164_000391a1\n"
        "je .Lf39164_000391af\n"
        ".Lf39164_000391a1:\n"
        "movzwl 8(%edx), %eax\n"
        "cmpw 0xa(%edx), %ax\n"
        "jg .Lf39164_000391af\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 2922 */
        "retl\n"
        /* { scope 1 */
        ".Lf39164_000391af:\n"
        "movl $1, %eax\n" /* line 2921 */
        /* } scope */
        "popl %ebp\n" /* line 2922 */
        "retl\n"
    );
}

/* line 2930 */
int XAnimGetNumChildren(const XAnim *anims, unsigned int animIndex)
{
    return *(unsigned short *)((byte *)anims + animIndex * 8 + 0xc);
}

/* line 2944 */
unsigned int XAnimGetChildAt(const XAnim *anims, unsigned int animIndex, unsigned int childIndex)
{
    return *(unsigned short *)((byte *)anims + animIndex * 8 + 0x12) + childIndex;
}

/* line 2959 */
const char * XAnimGetAnimName(const XAnim *anims, unsigned int animIndex)
{
    char *entry = (char *)anims + animIndex * 8 + 0xc;
    if (*(unsigned short *)entry != 0)
        return (const char *)str_002157b8;
    return *(const char **)(*(void **)(entry + 4) + 0x24);
}

/* line 3021 */
const char * XAnimGetAnimTreeDebugName(const XAnim *anims)
{
    return *(const char **)anims;
}

/* line 3033 */
unsigned int XAnimGetAnimTreeSize(const XAnim *anims)
{
    return *(unsigned int *)((byte *)anims + 4);
}

/* line 3196 */
int DObjGetClientNotifyList(XAnimNotify * *notifyList)
{
    *notifyList = g_notifyList;
    return g_notifyListSize;
}

/* line 4025 */
static void * Hunk_AllocXAnimPrecache(int size)
{
    return Hunk_AllocAlignInternal(size, 4);
}

/* line 4131 */
Bool XAnimIsPrimitive(XAnim *anims, unsigned int animIndex)
{
    return *(unsigned short *)((byte *)anims + animIndex * 8 + 0xc) == 0;
}

/* line 4137 */
__attribute__((naked))
void XAnimSetTime(XAnimTree *tree, unsigned int animIndex, float time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4137 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %ecx\n" /* time */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 4148 | animIndex */
        "movl 8(%ebp), %eax\n" /* tree */
        "movzwl 8(%eax, %edx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 4149 */
        "je .Lf3925e_0003929c\n"
        "movzwl %ax, %eax\n" /* line 4159 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* line 4161 */
        "movl %ecx, 0xc(%eax)\n" /* line 4162 */
        "movw $0, 8(%edx)\n" /* line 4163 */
        "movl %ecx, 4(%edx)\n" /* line 4164 */
        "movw $0, 0xa(%edx)\n" /* line 4165 */
        "movw $0xffff, 2(%eax)\n" /* line 4167 */
        /* } scope */
        ".Lf3925e_0003929c:\n"
        "popl %ebp\n" /* line 4168 */
        "retl\n"
    );
}

/* line 4272 */
void XAnimSetAnimRate(XAnimTree *tree, unsigned int animIndex, float rate)
{
    unsigned short index = *(unsigned short *)((byte *)tree + 8 + animIndex * 2);
    *(float *)((byte *)&g_xAnimInfo[index] + 0x24) = rate;
}

/* line 4279 */
Bool XAnimIsLooped(const XAnim *anims, unsigned int animIndex)
{
    char *entry = (char *)anims + animIndex * 8 + 0xc;
    if (*(unsigned short *)entry != 0)
        return *(unsigned short *)(entry + 4) & 1;
    return *(unsigned char *)(*(char **)(entry + 4) + 2);
}

/* line 4292 */
__attribute__((naked))
Bool XAnimNotetrackExists(const XAnim *anims, unsigned int animIndex, unsigned int name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4292 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0x10(%ebp), %esi\n" /* name */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 4300 | animIndex */
        "movl 8(%ebp), %eax\n" /* anims */
        "movl 0x10(%eax, %edx, 8), %eax\n"
        "movl 0x1c(%eax), %edx\n" /* line 4303 */
        "testl %edx, %edx\n" /* line 4304 */
        "je .Lf392e4_0003932b\n"
        "movzbl 0xc(%eax), %ebx\n" /* line 4307 */
        "testl %ebx, %ebx\n"
        "jle .Lf392e4_0003932b\n"
        "movzwl (%edx), %eax\n" /* line 4309 */
        "cmpl %eax, %esi\n" /* name */
        "je .Lf392e4_00039322\n"
        "leal 8(%edx), %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf392e4_00039311:\n"
        "addl $1, %edx\n" /* line 4307 */
        "cmpl %ebx, %edx\n"
        "je .Lf392e4_0003932b\n"
        "movzwl (%ecx), %eax\n" /* line 4309 */
        "addl $8, %ecx\n"
        "cmpl %eax, %esi\n" /* name */
        "jne .Lf392e4_00039311\n"
        ".Lf392e4_00039322:\n"
        "movl $1, %eax\n" /* line 4307 */
        /* } scope */
        "popl %ebx\n" /* line 4314 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf392e4_0003932b:\n"
        "xorl %eax, %eax\n" /* line 4307 */
        /* } scope */
        "popl %ebx\n" /* line 4314 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 762 */
static __attribute__((naked))
void Z18XAnim_GetTimeIndexIhEvPK9XAnimTimePK19XAnimDynamicIndicesiPiPf(void) /* void XAnim_GetTimeIndex<unsigned char> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 762 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n"
        "cmpl %ecx, 4(%eax)\n" /* line 766 */
        "jle .Lf39334_000393b7\n"
        /* { scope 1 */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 698 */
        "mulss (%eax), %xmm0\n"
        "cvttss2si %xmm0, %esi\n"
        "movl 0xc(%eax), %edi\n" /* line 700 | frameIndex */
        "movl %edx, %ecx\n" /* line 702 */
        "addl %esi, %ecx\n"
        "movzbl (%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jge .Lf39334_000393de\n"
        "movl $0, -0x14(%ebp)\n" /* low */
        ".Lf39334_0003936c:\n"
        "movl -0x14(%ebp), %eax\n" /* line 709 | low */
        "addl %esi, %eax\n"
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "movl %edx, %ebx\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 710 */
        "addl %edx, %ecx\n"
        "movzbl (%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jl .Lf39334_000393b3\n"
        "leal 1(%ecx), %eax\n" /* line 715 */
        "movl %eax, -0x10(%ebp)\n"
        "movzbl 1(%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jl .Lf39334_0003948c\n"
        "addl $1, %edx\n" /* line 717 */
        "movl %edx, -0x14(%ebp)\n" /* low */
        "leal -1(%esi), %ebx\n" /* line 718 */
        "movl -0x1c(%ebp), %ecx\n" /* line 719 */
        "addl %ebx, %ecx\n"
        "movzbl (%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jge .Lf39334_00039482\n"
        ".Lf39334_000393b3:\n"
        "movl %ebx, %esi\n" /* line 702 */
        "jmp .Lf39334_0003936c\n"
        ".Lf39334_000393b7:\n"
        "movl %eax, %ecx\n"
        /* } scope */
        "cvtsi2ssl 0xc(%eax), %xmm0\n" /* line 773 */
        "movss 8(%eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* keyFrameLerpFrac */
        "movss %xmm1, (%eax)\n"
        "movl 0xc(%ecx), %eax\n" /* line 774 */
        "movl 8(%ebp), %edx\n" /* keyFrameIndex */
        "movl %eax, (%edx)\n"
        "addl $0x14, %esp\n" /* line 778 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf39334_000393de:\n"
        "leal 1(%ecx), %eax\n" /* line 729 */
        "movl %eax, -0x10(%ebp)\n"
        "movzbl 1(%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jl .Lf39334_00039445\n"
        ".Lf39334_000393ec:\n"
        "leal 1(%esi), %ebx\n" /* line 750 */
        "movl -0x20(%ebp), %edx\n"
        "leal (%ebx, %edx), %eax\n" /* line 736 */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "leal (%edx, %eax), %esi\n"
        "sarl $1, %esi\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 737 */
        "addl %esi, %ecx\n"
        "movzbl (%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jge .Lf39334_00039437\n"
        ".Lf39334_0003940b:\n"
        "addl $1, %ebx\n" /* line 740 */
        "movl -0x1c(%ebp), %ecx\n" /* line 741 */
        "movzbl (%ecx, %ebx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jl .Lf39334_00039490\n"
        "movl %esi, -0x20(%ebp)\n" /* line 731 */
        "movl %esi, %edx\n"
        "leal (%ebx, %edx), %eax\n" /* line 736 */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "leal (%edx, %eax), %esi\n"
        "sarl $1, %esi\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 737 */
        "addl %esi, %ecx\n"
        "movzbl (%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jl .Lf39334_0003940b\n"
        ".Lf39334_00039437:\n"
        "leal 1(%ecx), %edx\n" /* line 748 */
        "movl %edx, -0x10(%ebp)\n"
        "movzbl 1(%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* frameIndex */
        "jge .Lf39334_000393ec\n"
        ".Lf39334_00039445:\n"
        "movzbl (%ecx), %edx\n" /* line 757 */
        "movzbl %dl, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movl -0x18(%ebp), %ecx\n"
        "movss 8(%ecx), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movl -0x10(%ebp), %ecx\n"
        "movzbl (%ecx), %eax\n"
        "movzbl %dl, %edx\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* keyFrameLerpFrac */
        "movss %xmm1, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 758 | keyFrameIndex */
        "movl %esi, (%edx)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 778 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf39334_00039482:\n"
        "leal 1(%ecx), %edx\n" /* line 719 */
        "movl %edx, -0x10(%ebp)\n"
        "movl %ebx, %esi\n"
        "jmp .Lf39334_00039445\n"
        ".Lf39334_0003948c:\n"
        "movl %edx, %esi\n" /* line 751 */
        "jmp .Lf39334_00039445\n"
        ".Lf39334_00039490:\n"
        "leal -1(%ebx), %esi\n" /* line 743 */
        "addl %esi, %ecx\n"
        "leal 1(%ecx), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "jmp .Lf39334_00039445\n"
    );
}

/* line 691 */
static __attribute__((naked))
void Z28XAnim_GetTimeIndexCompressedItEvPK9XAnimTimePKT_iPiPf(void) /* void XAnim_GetTimeIndexCompressed<unsigned short> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 691 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, -0x14(%ebp)\n" /* keyFrameLerpFrac */
        "movl %edx, -0x18(%ebp)\n"
        "movl %ecx, -0x1c(%ebp)\n"
        /* { scope 1 */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 698 */
        "mulss (%eax), %xmm0\n"
        "cvttss2si %xmm0, %ecx\n"
        "movl 0xc(%eax), %esi\n" /* line 700 | frameIndex */
        "leal (%edx, %ecx, 2), %edx\n" /* line 702 */
        "movzwl (%edx), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jge .Lf3949e_00039542\n"
        "movl %ecx, %ebx\n" /* high */
        "xorl %edi, %edi\n" /* low */
        ".Lf3949e_000394cd:\n"
        "leal (%edi, %ebx), %eax\n" /* line 709 | low */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "leal (%edx, %eax), %ecx\n"
        "sarl $1, %ecx\n"
        "movl -0x18(%ebp), %eax\n" /* line 710 */
        "leal (%eax, %ecx, 2), %edx\n"
        "movzwl (%edx), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jl .Lf3949e_0003953e\n"
        "leal 2(%edx), %edi\n" /* line 715 | low */
        "movzwl 2(%edx), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jl .Lf3949e_0003950a\n"
        "leal 1(%ecx), %edi\n" /* line 717 | low */
        "subl $1, %ebx\n" /* line 718 | high */
        "movl -0x18(%ebp), %eax\n" /* line 719 */
        "leal (%eax, %ebx, 2), %edx\n"
        "movzwl (%edx), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jl .Lf3949e_000394cd\n"
        "leal 2(%edx), %edi\n" /* low */
        "movl %ebx, %ecx\n" /* high */
        ".Lf3949e_0003950a:\n"
        "movzwl (%edx), %edx\n" /* line 757 */
        "cvtsi2ssl %edx, %xmm0\n"
        "movl -0x14(%ebp), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movzwl (%edi), %eax\n" /* low */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* keyFrameLerpFrac */
        "movss %xmm1, (%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 758 | keyFrameIndex */
        "movl %ecx, (%eax)\n"
        /* } scope */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3949e_0003953e:\n"
        "movl %ecx, %ebx\n" /* line 702 | high */
        "jmp .Lf3949e_000394cd\n"
        ".Lf3949e_00039542:\n"
        "leal 2(%edx), %edi\n" /* line 729 | low */
        "movzwl 2(%edx), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jl .Lf3949e_0003950a\n"
        "leal 1(%ecx), %ebx\n" /* line 731 | high */
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, -0x10(%ebp)\n"
        ".Lf3949e_00039556:\n"
        "leal (%ebx, %edx), %eax\n" /* line 736 | high */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "leal (%edx, %eax), %ecx\n"
        "sarl $1, %ecx\n"
        "movl -0x18(%ebp), %eax\n" /* line 737 */
        "leal (%eax, %ecx, 2), %edx\n"
        "movzwl (%edx), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jge .Lf3949e_0003959d\n"
        ".Lf3949e_00039570:\n"
        "addl $1, %ebx\n" /* line 740 | high */
        "movl -0x18(%ebp), %edx\n" /* line 741 */
        "movzwl (%edx, %ebx, 2), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jl .Lf3949e_000395b4\n"
        "movl %ecx, -0x10(%ebp)\n" /* line 731 */
        "movl %ecx, %edx\n"
        "leal (%ebx, %edx), %eax\n" /* line 736 | high */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "leal (%edx, %eax), %ecx\n"
        "sarl $1, %ecx\n"
        "movl -0x18(%ebp), %eax\n" /* line 737 */
        "leal (%eax, %ecx, 2), %edx\n"
        "movzwl (%edx), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jl .Lf3949e_00039570\n"
        ".Lf3949e_0003959d:\n"
        "leal 2(%edx), %edi\n" /* line 748 | low */
        "movzwl 2(%edx), %eax\n"
        "cmpl %eax, %esi\n" /* frameIndex */
        "jl .Lf3949e_0003950a\n"
        "leal 1(%ecx), %ebx\n" /* line 750 | high */
        "movl -0x10(%ebp), %edx\n"
        "jmp .Lf3949e_00039556\n"
        ".Lf3949e_000395b4:\n"
        "leal -1(%ebx), %ecx\n" /* line 743 | high */
        "leal (%edx, %ecx, 2), %edx\n"
        "leal 2(%edx), %edi\n" /* low */
        "jmp .Lf3949e_0003950a\n"
    );
}

/* line 2996 */
__attribute__((naked))
const char * XAnimGetAnimDebugName(const XAnim *anims, unsigned int animIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2996 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* anims */
        "movl 0xc(%ebp), %ecx\n" /* animIndex */
        /* { scope 1 */
        "leal (%eax, %ecx, 8), %edx\n" /* line 3006 */
        "leal 0xc(%edx), %ebx\n" /* anim */
        "movl 8(%eax), %eax\n" /* line 3007 */
        "testl %eax, %eax\n"
        "je .Lf395c2_000395fd\n"
        "movl (%eax, %ecx, 4), %ecx\n" /* line 3010 */
        "cmpw $0, 0xc(%edx)\n" /* line 3011 */
        "jne .Lf395c2_0003960a\n"
        "movl 4(%ebx), %eax\n" /* anim */
        "cmpb $0, 0x28(%eax)\n"
        "je .Lf395c2_0003960a\n"
        "movl %ecx, 0xc(%ebp)\n" /* line 3012 | animIndex */
        "movl $str_00217860, 8(%ebp)\n" /* anims */
        /* } scope */
        "popl %ebx\n" /* line 3013 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp va\n" /* line 3012 */
        ".Lf395c2_000395fd:\n"
        "cmpw $0, 0xc(%edx)\n" /* line 3008 */
        "jne .Lf395c2_0003960f\n"
        "movl 4(%ebx), %eax\n" /* anim */
        "movl 0x24(%eax), %ecx\n"
        /* } scope */
        ".Lf395c2_0003960a:\n"
        "movl %ecx, %eax\n" /* line 3013 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf395c2_0003960f:\n"
        "movl %ecx, 0xc(%ebp)\n" /* line 3008 | animIndex */
        "movl $str_0021785c, 8(%ebp)\n" /* anims */
        /* } scope */
        "popl %ebx\n" /* line 3013 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp va\n" /* line 3008 */
    );
}

/* line 447 */
__attribute__((naked))
XAnimTree * XAnimCreateTree(XAnim *anims, Alloc_t Alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 447 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* anims */
        /* { scope 1 */
        "movl 4(%ebx), %esi\n" /* line 420 */
        "leal 9(%esi, %esi, 4), %esi\n"
        "movl %esi, (%esp)\n" /* line 460 | entrySize */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, %edi\n"
        "movl %esi, 8(%esp)\n" /* line 461 | entrySize */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl %ebx, (%edi)\n" /* line 463 | anims */
        /* } scope */
        "movl %edi, %eax\n" /* line 499 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 224 */
__attribute__((naked))
XAnimParts * XAnimPrecache(const char *name, Alloc_t Alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 224 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1: size, notifyInfoIndex */
        "movl %edi, 4(%esp)\n" /* line 196 */
        "movl $5, (%esp)\n"
        "calll Hunk_FindDataForFile\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 230 */
        "je .Lf3965c_00039688\n"
        /* } scope */
        ".Lf3965c_0003967e:\n"
        "movl %ebx, %eax\n" /* line 256 | parts */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: size, notifyInfoIndex */
        ".Lf3965c_00039688:\n"
        "movl 0xc(%ebp), %eax\n" /* line 233 | Alloc */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* name */
        "calll XAnimLoadFile\n"
        "movl %eax, %ebx\n" /* parts */
        "testl %eax, %eax\n" /* line 234 */
        "je .Lf3965c_000396c5\n"
        ".Lf3965c_0003969d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 254 | Alloc */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* parts */
        "movl %edi, 4(%esp)\n" /* name */
        "movl $5, (%esp)\n"
        "calll Hunk_SetDataForFile\n"
        "movl %eax, 0x24(%ebx)\n" /* parts */
        /* } scope */
        "movl %ebx, %eax\n" /* line 256 | parts */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: size, notifyInfoIndex */
        ".Lf3965c_000396c5:\n"
        "movl $str_00217870, 8(%esp)\n" /* line 236 */
        "movl %edi, 4(%esp)\n" /* name */
        "movl $str_00217878, (%esp)\n" /* "^3WARNING: Couldn't find xanim '%s', using default xanim '%s" */
        "calll Com_Printf\n"
        "movl $str_00217870, 4(%esp)\n" /* line 196 */
        "movl $5, (%esp)\n"
        "calll Hunk_FindDataForFile\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 238 */
        "je .Lf3965c_000397b0\n"
        /* { scope 2 */
        ".Lf3965c_000396fb:\n"
        "movl $0x2c, (%esp)\n" /* line 209 */
        "calll *0xc(%ebp)\n" /* Alloc */
        "movl %eax, %ebx\n"
        "movl (%esi), %eax\n" /* line 210 | notify */
        "movl %eax, (%ebx)\n"
        "movl 4(%esi), %eax\n" /* notify */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%esi), %eax\n" /* notify */
        "movl %eax, 8(%ebx)\n"
        "movl 0xc(%esi), %eax\n" /* notify */
        "movl %eax, 0xc(%ebx)\n"
        "movl 0x10(%esi), %edx\n" /* notify */
        "movl %edx, -0x24(%ebp)\n"
        "movl %edx, 0x10(%ebx)\n"
        "movl 0x14(%esi), %eax\n" /* notify */
        "movl %eax, 0x14(%ebx)\n"
        "movl 0x18(%esi), %eax\n" /* notify */
        "movl %eax, 0x18(%ebx)\n"
        "movl 0x1c(%esi), %eax\n" /* notify */
        "movl %eax, 0x1c(%ebx)\n"
        "movl 0x20(%esi), %eax\n" /* notify */
        "movl %eax, 0x20(%ebx)\n"
        "movl 0x24(%esi), %eax\n" /* notify */
        "movl %eax, 0x24(%ebx)\n"
        "movl 0x28(%esi), %eax\n" /* notify */
        "movl %eax, 0x28(%ebx)\n"
        "movswl 0xe(%ebx), %eax\n" /* line 213 */
        "movl %eax, -0x20(%ebp)\n" /* size */
        "testl %eax, %eax\n" /* line 214 */
        "jg .Lf3965c_00039795\n"
        ".Lf3965c_00039755:\n"
        "movl 0x1c(%ebx), %esi\n" /* line 217 | notify */
        "cmpb $0, 0xc(%ebx)\n"
        "jne .Lf3965c_00039767\n"
        /* } scope */
        "movb $1, 0x28(%ebx)\n" /* line 251 | parts */
        "jmp .Lf3965c_0003969d\n"
        /* { scope 2 */
        ".Lf3965c_00039767:\n"
        "movw $0, -0x1a(%ebp)\n" /* line 217 | notifyInfoIndex */
        ".Lf3965c_0003976d:\n"
        "movzwl (%esi), %eax\n" /* line 218 | notify */
        "movl %eax, (%esp)\n"
        "calll SL_AddRefToString\n"
        "addw $1, -0x1a(%ebp)\n" /* line 217 | notifyInfoIndex */
        "addl $8, %esi\n" /* notify */
        "movzbl 0xc(%ebx), %edx\n"
        "movswl -0x1a(%ebp), %eax\n" /* notifyInfoIndex */
        "cmpl %eax, %edx\n"
        "jg .Lf3965c_0003976d\n"
        /* } scope */
        "movb $1, 0x28(%ebx)\n" /* line 251 | parts */
        "jmp .Lf3965c_0003969d\n"
        /* { scope 2 */
        ".Lf3965c_00039795:\n"
        "xorl %esi, %esi\n" /* line 214 | notify */
        ".Lf3965c_00039797:\n"
        "movl -0x24(%ebp), %edx\n" /* line 215 */
        "movzwl (%edx, %esi, 2), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_AddRefToString\n"
        "addl $1, %esi\n" /* line 214 | notify */
        "cmpl %esi, -0x20(%ebp)\n" /* notify, size */
        "jne .Lf3965c_00039797\n"
        "jmp .Lf3965c_00039755\n"
        /* } scope */
        ".Lf3965c_000397b0:\n"
        "movl 0xc(%ebp), %edx\n" /* line 240 | Alloc */
        "movl %edx, 4(%esp)\n"
        "movl $str_00217870, (%esp)\n" /* "void" */
        "calll XAnimLoadFile\n"
        "movl %eax, %esi\n" /* defaultParts */
        "testl %eax, %eax\n" /* line 241 */
        "je .Lf3965c_000397ed\n"
        "movl 0xc(%ebp), %eax\n" /* line 247 | Alloc */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* defaultParts */
        "movl $str_00217870, 4(%esp)\n" /* "void" */
        "movl $5, (%esp)\n"
        "calll Hunk_SetDataForFile\n"
        "jmp .Lf3965c_000396fb\n"
        ".Lf3965c_000397ed:\n"
        "movl $str_00217870, 8(%esp)\n" /* line 243 */
        "movl $str_002178c0, 4(%esp)\n" /* "Cannot find xanim '%s'." */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf3965c_0003967e\n"
    );
}

/* line 274 */
__attribute__((naked))
void XAnimCreate(XAnim *anims, unsigned int animIndex, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 274 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* anims */
        "movl %eax, -0x1c(%ebp)\n" /* anims */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        "movl %edx, -0x20(%ebp)\n" /* animIndex */
        "movl 0x10(%ebp), %esi\n" /* name */
        /* { scope 1 */
        "movl %esi, 4(%esp)\n" /* line 196 */
        "movl $5, (%esp)\n"
        "calll Hunk_FindDataForFile\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 284 */
        "je .Lf3980e_0003988d\n"
        "movl -0x20(%ebp), %ecx\n" /* line 293 | animIndex */
        "movl -0x1c(%ebp), %ebx\n" /* anims */
        "leal (%ebx, %ecx, 8), %eax\n"
        "movw $0, 0xc(%eax)\n" /* line 294 */
        "movl %edx, 0x10(%eax)\n" /* line 295 */
        "movl 8(%ebx), %edi\n" /* line 297 */
        "testl %edi, %edi\n"
        "je .Lf3980e_00039885\n"
        "cld\n" /* line 300 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* name */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl %esi, 4(%esp)\n" /* line 301 | name */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x1c(%ebp), %edx\n" /* line 302 | anims */
        "movl 8(%edx), %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* animIndex */
        "movl %ebx, (%eax, %ecx, 4)\n"
        /* } scope */
        ".Lf3980e_00039885:\n"
        "addl $0x2c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3980e_0003988d:\n"
        "movl %esi, 0x10(%ebp)\n" /* line 286 | name */
        "movl $str_002178dc, 0xc(%ebp)\n" /* animIndex */
        "movl $1, 8(%ebp)\n" /* anims */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Error\n" /* line 286 */
    );
}

/* line 3869 */
static __attribute__((naked))
unsigned int XAnimGetDescendantWithGreatestWeight(void)
{
    __asm__ __volatile__ (
        ".Lf398aa_000398aa:\n"
        "pushl %ebp\n" /* line 3869 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl %eax, %esi\n" /* tree */
        /* { scope 1: bestWeight, i, anim */
        "movl (%eax), %eax\n" /* line 3878 */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0xb0(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039e7e\n"
        "testw %ax, %ax\n" /* line 3891 */
        "je .Lf398aa_00039e8b\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n" /* bestWeight */
        "movl $0, -0xb8(%ebp)\n" /* result */
        "movl $0, -0xb4(%ebp)\n" /* i */
        "movl -0xb0(%ebp), %edx\n" /* anim, animIndex */
        ".Lf398aa_00039902:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "movl -0xb4(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n" /* testWeight */
        "movss -0xc4(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0xc0(%ebp), %xmm0\n" /* testWeight */
        "jae .Lf398aa_00039e5c\n"
        "movl %edx, -0xbc(%ebp)\n" /* line 3899 | animIndex, test */
        /* { scope 2: bestWeight, i, anim */
        "movl (%esi), %eax\n" /* line 3878 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0xa4(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039e36\n"
        "je .Lf398aa_00039e5c\n" /* line 3891 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0xac(%ebp)\n" /* bestWeight */
        "movl $0, -0xa8(%ebp)\n" /* i */
        "movl $0, -0xbc(%ebp)\n" /* test */
        "movl -0xa4(%ebp), %edx\n" /* anim, animIndex */
        ".Lf398aa_00039989:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "movl -0xa8(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x1c(%ebp), %xmm0\n"
        "jae .Lf398aa_00039e1a\n"
        "movl %edx, -0x50(%ebp)\n" /* line 3899 | animIndex */
        /* { scope 3: bestWeight, i, anim */
        "movl (%esi), %eax\n" /* line 3878 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x98(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039dfd\n"
        "je .Lf398aa_00039e1a\n" /* line 3891 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n" /* bestWeight */
        "movl $0, -0x9c(%ebp)\n" /* i */
        "movl $0, -0x50(%ebp)\n"
        "movl -0x98(%ebp), %edx\n" /* anim, animIndex */
        ".Lf398aa_00039a04:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "movl -0x9c(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x20(%ebp), %xmm0\n"
        "jae .Lf398aa_00039de1\n"
        "movl %edx, -0x4c(%ebp)\n" /* line 3899 | animIndex */
        /* { scope 4: bestWeight, i, anim */
        "movl (%esi), %eax\n" /* line 3878 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x8c(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039dc7\n"
        "je .Lf398aa_00039de1\n" /* line 3891 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n" /* bestWeight */
        "movl $0, -0x90(%ebp)\n" /* i */
        "movl $0, -0x4c(%ebp)\n"
        "movl -0x8c(%ebp), %edx\n" /* anim, animIndex */
        ".Lf398aa_00039a7f:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "movl -0x90(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x24(%ebp), %xmm0\n"
        "jae .Lf398aa_00039dab\n"
        "movl %edx, -0x48(%ebp)\n" /* line 3899 | animIndex */
        /* { scope 5: bestWeight, i, anim */
        "movl (%esi), %eax\n" /* line 3878 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x80(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039d91\n"
        "je .Lf398aa_00039dab\n" /* line 3891 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x88(%ebp)\n" /* bestWeight */
        "movl $0, -0x84(%ebp)\n" /* i */
        "movl $0, -0x48(%ebp)\n"
        "movl -0x80(%ebp), %edx\n" /* anim, animIndex */
        ".Lf398aa_00039af4:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "movl -0x84(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss -0x88(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x28(%ebp), %xmm0\n"
        "jae .Lf398aa_00039d78\n"
        "movl %edx, -0x44(%ebp)\n" /* line 3899 | animIndex */
        /* { scope 6: bestWeight, i, anim */
        "movl (%esi), %eax\n" /* line 3878 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x74(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039d5e\n"
        "je .Lf398aa_00039d78\n" /* line 3891 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n" /* bestWeight */
        "movl $0, -0x78(%ebp)\n" /* i */
        "movl $0, -0x44(%ebp)\n"
        "movl -0x74(%ebp), %edx\n" /* anim, animIndex */
        ".Lf398aa_00039b63:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "movl -0x78(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x2c(%ebp), %xmm0\n"
        "jae .Lf398aa_00039d4b\n"
        "movl %edx, -0x40(%ebp)\n" /* line 3899 | animIndex */
        /* { scope 7: bestWeight, i, anim */
        "movl (%esi), %eax\n" /* line 3878 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x68(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039d34\n"
        "je .Lf398aa_00039d4b\n" /* line 3891 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n" /* bestWeight */
        "movl $0, -0x6c(%ebp)\n" /* i */
        "movl $0, -0x40(%ebp)\n"
        "movl -0x68(%ebp), %edx\n" /* anim, animIndex */
        ".Lf398aa_00039bcc:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "movl -0x6c(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss -0x70(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x30(%ebp), %xmm0\n"
        "jae .Lf398aa_00039d21\n"
        "movl %edx, -0x3c(%ebp)\n" /* line 3899 | animIndex */
        /* { scope 8: bestWeight, anim */
        "movl (%esi), %eax\n" /* line 3878 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x5c(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039d0a\n"
        "je .Lf398aa_00039d21\n" /* line 3891 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n" /* bestWeight */
        "movl $0, -0x60(%ebp)\n" /* i */
        "movl $0, -0x3c(%ebp)\n"
        "movl -0x5c(%ebp), %edx\n" /* anim, animIndex */
        ".Lf398aa_00039c35:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "movl -0x60(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x34(%ebp), %xmm0\n"
        "jae .Lf398aa_00039cf7\n"
        "movl %edx, %edi\n" /* line 3899 | animIndex */
        /* { scope 9 */
        "movl (%esi), %eax\n" /* line 3878 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x54(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf398aa_00039ce6\n"
        "je .Lf398aa_00039cf7\n" /* line 3891 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n" /* bestWeight */
        "xorl %ebx, %ebx\n" /* i */
        "xorl %edi, %edi\n"
        "movl -0x54(%ebp), %edx\n" /* anim, animIndex */
        "jmp .Lf398aa_00039c9a\n"
        ".Lf398aa_00039c8d:\n"
        "addl $1, %ebx\n" /* i */
        "movl -0x54(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl %ebx, %eax\n" /* i */
        "jle .Lf398aa_00039ce6\n"
        ".Lf398aa_00039c9a:\n"
        "movzwl 6(%edx), %eax\n" /* line 3895 | animIndex */
        "leal (%ebx, %eax), %edx\n" /* i, animIndex */
        "movzwl 8(%esi, %edx, 2), %eax\n" /* tree */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x38(%ebp), %xmm0\n"
        "jae .Lf398aa_00039c8d\n"
        "movl %esi, %eax\n" /* line 3899 | tree */
        "calll XAnimGetDescendantWithGreatestWeight\n"
        "testl %eax, %eax\n" /* line 3900 */
        "je .Lf398aa_00039c8d\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0x58(%ebp)\n" /* bestWeight */
        "movl %eax, %edi\n"
        "addl $1, %ebx\n" /* line 3891 | i */
        "movl -0x54(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl %ebx, %eax\n" /* i */
        "jg .Lf398aa_00039c9a\n"
        /* } scope */
        ".Lf398aa_00039ce6:\n"
        "testl %edi, %edi\n" /* line 3900 */
        "je .Lf398aa_00039cf7\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0x64(%ebp)\n" /* bestWeight */
        "movl %edi, -0x3c(%ebp)\n"
        ".Lf398aa_00039cf7:\n"
        "addl $1, -0x60(%ebp)\n" /* line 3891 | i */
        "movl -0x5c(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl -0x60(%ebp), %eax\n" /* i */
        "jg .Lf398aa_00039c35\n"
        /* } scope */
        ".Lf398aa_00039d0a:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 3900 | animIndex */
        "testl %edx, %edx\n" /* animIndex */
        "je .Lf398aa_00039d21\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0x70(%ebp)\n" /* bestWeight */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        ".Lf398aa_00039d21:\n"
        "addl $1, -0x6c(%ebp)\n" /* line 3891 | i */
        "movl -0x68(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl -0x6c(%ebp), %eax\n" /* i */
        "jg .Lf398aa_00039bcc\n"
        /* } scope */
        ".Lf398aa_00039d34:\n"
        "movl -0x40(%ebp), %eax\n" /* line 3900 */
        "testl %eax, %eax\n"
        "je .Lf398aa_00039d4b\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0x7c(%ebp)\n" /* bestWeight */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        ".Lf398aa_00039d4b:\n"
        "addl $1, -0x78(%ebp)\n" /* line 3891 | i */
        "movl -0x74(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl -0x78(%ebp), %eax\n" /* i */
        "jg .Lf398aa_00039b63\n"
        /* } scope */
        ".Lf398aa_00039d5e:\n"
        "movl -0x44(%ebp), %eax\n" /* line 3900 */
        "testl %eax, %eax\n"
        "je .Lf398aa_00039d78\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0x88(%ebp)\n" /* bestWeight */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        ".Lf398aa_00039d78:\n"
        "addl $1, -0x84(%ebp)\n" /* line 3891 | i */
        "movl -0x80(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl %eax, -0x84(%ebp)\n" /* i */
        "jl .Lf398aa_00039af4\n"
        /* } scope */
        ".Lf398aa_00039d91:\n"
        "movl -0x48(%ebp), %eax\n" /* line 3900 */
        "testl %eax, %eax\n"
        "je .Lf398aa_00039dab\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0x94(%ebp)\n" /* bestWeight */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        ".Lf398aa_00039dab:\n"
        "addl $1, -0x90(%ebp)\n" /* line 3891 | i */
        "movl -0x8c(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl %eax, -0x90(%ebp)\n" /* i */
        "jl .Lf398aa_00039a7f\n"
        /* } scope */
        ".Lf398aa_00039dc7:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 3900 */
        "testl %eax, %eax\n"
        "je .Lf398aa_00039de1\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0xa0(%ebp)\n" /* bestWeight */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        ".Lf398aa_00039de1:\n"
        "addl $1, -0x9c(%ebp)\n" /* line 3891 | i */
        "movl -0x98(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl %eax, -0x9c(%ebp)\n" /* i */
        "jl .Lf398aa_00039a04\n"
        /* } scope */
        ".Lf398aa_00039dfd:\n"
        "movl -0x50(%ebp), %eax\n" /* line 3900 */
        "testl %eax, %eax\n"
        "je .Lf398aa_00039e1a\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0xac(%ebp)\n" /* bestWeight */
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, -0xbc(%ebp)\n" /* test */
        ".Lf398aa_00039e1a:\n"
        "addl $1, -0xa8(%ebp)\n" /* line 3891 | i */
        "movl -0xa4(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl -0xa8(%ebp), %eax\n" /* i */
        "jg .Lf398aa_00039989\n"
        /* } scope */
        ".Lf398aa_00039e36:\n"
        "movl -0xbc(%ebp), %eax\n" /* line 3900 | test */
        "testl %eax, %eax\n"
        "je .Lf398aa_00039e5c\n"
        "movss -0xc0(%ebp), %xmm0\n" /* line 3901 | testWeight */
        "movss %xmm0, -0xc4(%ebp)\n" /* bestWeight */
        "movl -0xbc(%ebp), %eax\n" /* test */
        "movl %eax, -0xb8(%ebp)\n" /* result */
        ".Lf398aa_00039e5c:\n"
        "addl $1, -0xb4(%ebp)\n" /* line 3891 | i */
        "movl -0xb0(%ebp), %edx\n" /* anim, animIndex */
        "movzwl (%edx), %eax\n" /* animIndex */
        "cmpl %eax, -0xb4(%ebp)\n" /* i */
        "jl .Lf398aa_00039902\n"
        "movl -0xb8(%ebp), %edx\n" /* result, animIndex */
        /* } scope */
        ".Lf398aa_00039e7e:\n"
        "movl %edx, %eax\n" /* line 3907 | animIndex */
        "addl $0xbc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bestWeight, i, anim */
        ".Lf398aa_00039e8b:\n"
        "xorl %edx, %edx\n" /* line 3891 | animIndex */
        /* } scope */
        "movl %edx, %eax\n" /* line 3907 | animIndex */
        "addl $0xbc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2857 */
int XAnimGetLengthMsec(const XAnim *anims, unsigned int anim)
{
    byte *entry = *(byte **)((byte *)anims + 0x10 + anim * 8);
    return (int)((float)*(unsigned short *)entry / *(float *)(entry + 4) * 1000.0f);
}

/* line 3586 */
__attribute__((naked))
void XAnimClearGoalWeight(XAnimTree *tree, unsigned int animIndex, float blendTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3586 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movss 0x10(%ebp), %xmm1\n" /* blendTime */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 3595 | animIndex */
        "movl 8(%ebp), %eax\n" /* tree */
        "movzwl 8(%eax, %edx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 3596 */
        "je .Lf39ec2_00039f23\n"
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* info */
        "leal 0xc(%ebx), %eax\n" /* line 3601 | info */
        "pxor %xmm2, %xmm2\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm2\n"
        "jp .Lf39ec2_00039efa\n"
        "je .Lf39ec2_00039f29\n"
        ".Lf39ec2_00039efa:\n"
        "movss %xmm1, 0xc(%eax)\n" /* line 3610 */
        ".Lf39ec2_00039eff:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "ucomiss %xmm2, %xmm1\n" /* line 3615 */
        "jne .Lf39ec2_00039f14\n"
        "jp .Lf39ec2_00039f14\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        ".Lf39ec2_00039f14:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf39ec2_00039f35\n"
        ".Lf39ec2_00039f1d:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        ".Lf39ec2_00039f23:\n"
        "addl $0x14, %esp\n" /* line 3619 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf39ec2_00039f29:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf39ec2_00039eff\n"
        "jmp .Lf39ec2_00039efa\n"
        ".Lf39ec2_00039f35:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf39ec2_00039f1d\n"
    );
}

/* line 1161 */
static __attribute__((naked))
void XAnim_CalcDeltaForTime(vec_t *posDelta)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1161 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movaps %xmm0, %xmm3\n" /* time */
        "movl %edx, %esi\n" /* rotDelta */
        "movl %ecx, -0x44(%ebp)\n"
        /* { scope 1: animTime, keyFrameIndex, keyFrameLerpFrac */
        "movl 0x20(%eax), %edx\n" /* line 1170 | anim */
        "movl %edx, -0x3c(%ebp)\n" /* animDelta */
        "movzwl (%eax), %eax\n" /* line 1171 | anim */
        "movzwl %ax, %ecx\n" /* anim */
        "movl %ecx, -0x40(%ebp)\n" /* frameCount */
        "ucomiss lit4_002ed5d0, %xmm0\n" /* line 1172 | 1.0f */
        "jp .Lf39f48_00039f73\n"
        "je .Lf39f48_00039fd8\n"
        ".Lf39f48_00039f73:\n"
        "testw %ax, %ax\n" /* anim */
        "je .Lf39f48_00039fd5\n"
        "cmpl $0xff, -0x40(%ebp)\n" /* line 1181 | frameCount */
        "jg .Lf39f48_0003a06c\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 1092 | animDelta */
        "movl 4(%ecx), %edi\n" /* indices */
        "testl %edi, %edi\n" /* indices */
        "je .Lf39f48_0003a353\n"
        /* { scope 2 */
        "cmpw $0, (%edi)\n" /* line 1067 */
        "jne .Lf39f48_0003a2ae\n"
        "movswl 4(%edi), %eax\n" /* line 878 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movswl 6(%edi), %eax\n" /* line 879 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        /* } scope */
        ".Lf39f48_00039fb6:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 1134 | animDelta */
        "movl (%edx), %esi\n" /* indices */
        "testl %esi, %esi\n" /* indices */
        "je .Lf39f48_0003a0b7\n"
        /* { scope 2 */
        "cmpw $0, (%esi)\n" /* line 1112 */
        "jne .Lf39f48_0003a25e\n"
        "leal 4(%esi), %edx\n" /* line 1114 | from */
        /* { scope 3 */
        "movl 4(%esi), %eax\n" /* line 199 */
        "jmp .Lf39f48_0003a021\n"
        ".Lf39f48_00039fd5:\n"
        "movl -0x3c(%ebp), %edx\n" /* animDelta */
        /* } scope */
        /* } scope */
        ".Lf39f48_00039fd8:\n"
        "movl 4(%edx), %eax\n" /* line 1020 */
        "testl %eax, %eax\n"
        "je .Lf39f48_0003a0cc\n"
        "movzwl (%eax), %edx\n" /* line 1010 */
        "testw %dx, %dx\n"
        "jne .Lf39f48_0003a03a\n"
        "leal 4(%eax), %edx\n"
        /* { scope 2 */
        ".Lf39f48_00039fee:\n"
        "movswl (%edx), %eax\n" /* line 878 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movswl 2(%edx), %eax\n" /* line 879 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        /* } scope */
        ".Lf39f48_0003a006:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1048 | animDelta */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf39f48_0003a0b7\n"
        "movzwl (%ecx), %eax\n" /* line 1036 */
        "testw %ax, %ax\n"
        "jne .Lf39f48_0003a045\n"
        "leal 4(%ecx), %edx\n" /* line 1037 | from */
        /* { scope 2 */
        "movl 4(%ecx), %eax\n" /* line 199 */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf39f48_0003a021:\n"
        "movl -0x44(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf39f48_0003a032:\n"
        "addl $0x5c, %esp\n" /* line 1192 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: animTime, keyFrameIndex, keyFrameLerpFrac */
        ".Lf39f48_0003a03a:\n"
        "movzwl %dx, %edx\n" /* line 1010 */
        "movl 4(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "jmp .Lf39f48_00039fee\n"
        /* { scope 2 */
        ".Lf39f48_0003a045:\n"
        "movzwl %ax, %eax\n" /* line 201 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 4(%ecx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        /* } scope */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 199 */
        "movl -0x44(%ebp), %ecx\n"
        "movl %edx, (%ecx)\n"
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl 8(%eax), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1192 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: animTime, keyFrameIndex, keyFrameLerpFrac */
        ".Lf39f48_0003a06c:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 1092 | animDelta */
        "movl 4(%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf39f48_0003a341\n"
        /* { scope 2 */
        "cmpw $0, (%ebx)\n" /* line 1067 */
        "jne .Lf39f48_0003a182\n"
        "movswl 4(%ebx), %eax\n" /* line 878 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movswl 6(%ebx), %eax\n" /* line 879 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        /* } scope */
        ".Lf39f48_0003a09d:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 1134 | animDelta */
        "movl (%edx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf39f48_0003a0b7\n"
        /* { scope 2 */
        "cmpw $0, (%ebx)\n" /* line 1112 */
        "jne .Lf39f48_0003a0de\n"
        "leal 4(%ebx), %edx\n" /* line 1114 | from */
        /* { scope 3 */
        "movl 4(%ebx), %eax\n" /* line 199 */
        "jmp .Lf39f48_0003a021\n"
        /* } scope */
        /* } scope */
        ".Lf39f48_0003a0b7:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl -0x44(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1192 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: animTime, keyFrameIndex, keyFrameLerpFrac */
        ".Lf39f48_0003a0cc:\n"
        "movl $0, (%esi)\n" /* line 1026 */
        "movl $0x46fffe00, 4(%esi)\n" /* line 1027 */
        "jmp .Lf39f48_0003a006\n"
        /* { scope 2 */
        ".Lf39f48_0003a0de:\n"
        "movss %xmm3, -0x30(%ebp)\n" /* line 684 | animTime */
        "movl -0x40(%ebp), %eax\n" /* line 685 | frameCount */
        "movl %eax, -0x2c(%ebp)\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 686 */
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "cvttss2si %xmm1, %eax\n" /* line 687 */
        "movl %eax, -0x24(%ebp)\n"
        "movzwl (%ebx), %ecx\n" /* line 1119 | tableSize */
        "leal 8(%ebx), %esi\n" /* indices */
        /* { scope 3 */
        "cmpl -0x2c(%ebp), %ecx\n" /* line 766 */
        "jl .Lf39f48_0003a20c\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 773 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* keyFrameLerpFrac */
        "movl %eax, -0x1c(%ebp)\n" /* line 774 | keyFrameIndex */
        "movaps %xmm1, %xmm2\n"
        /* } scope */
        ".Lf39f48_0003a11f:\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 1121 | from */
        "shll $2, %eax\n" /* from */
        "addl 4(%ebx), %eax\n" /* from */
        ".Lf39f48_0003a128:\n"
        "leal 0xc(%eax), %edx\n" /* to */
        /* { scope 3 */
        "movss (%eax), %xmm1\n" /* line 264 */
        "movss 0xc(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x44(%ebp), %ecx\n"
        "movss %xmm1, (%ecx)\n"
        "movss 4(%eax), %xmm1\n" /* line 265 */
        "movss 4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss 8(%eax), %xmm1\n" /* line 266 */
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "jmp .Lf39f48_0003a032\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf39f48_0003a182:\n"
        "movss %xmm3, -0x30(%ebp)\n" /* line 684 | animTime */
        "movl -0x40(%ebp), %eax\n" /* line 685 | frameCount */
        "movl %eax, -0x2c(%ebp)\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 686 */
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "cvttss2si %xmm1, %eax\n" /* line 687 */
        "movl %eax, -0x24(%ebp)\n"
        "movzwl (%ebx), %ecx\n" /* line 1074 | tableSize */
        "leal 8(%ebx), %edi\n" /* indices */
        /* { scope 3 */
        "cmpl -0x2c(%ebp), %ecx\n" /* line 766 */
        "jl .Lf39f48_0003a230\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 773 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* keyFrameLerpFrac */
        "movl %eax, -0x1c(%ebp)\n" /* line 774 | keyFrameIndex */
        "movaps %xmm1, %xmm2\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf39f48_0003a1c5:\n"
        "shll $2, %edx\n" /* line 1079 | from */
        "addl 4(%ebx), %edx\n" /* from */
        /* { scope 3 */
        "movswl (%edx), %ecx\n" /* line 795 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "movswl 4(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movswl 2(%edx), %ecx\n" /* line 796 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "movswl 6(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "jmp .Lf39f48_0003a09d\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf39f48_0003a20c:\n"
        "leal -0x30(%ebp), %eax\n" /* line 768 | animTime */
        "leal -0x20(%ebp), %edx\n" /* keyFrameLerpFrac */
        "movl %edx, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* keyFrameIndex */
        "movl %edx, (%esp)\n"
        "movl %esi, %edx\n"
        "calll Z28XAnim_GetTimeIndexCompressedItEvPK9XAnimTimePKT_iPiPf\n"
        "movss -0x20(%ebp), %xmm2\n" /* keyFrameLerpFrac */
        "movl -0x1c(%ebp), %eax\n" /* keyFrameIndex */
        "jmp .Lf39f48_0003a11f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf39f48_0003a230:\n"
        "leal -0x30(%ebp), %eax\n" /* animTime */
        "leal -0x20(%ebp), %edx\n" /* keyFrameLerpFrac */
        "movl %edx, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* keyFrameIndex */
        "movl %edx, (%esp)\n"
        "movl %edi, %edx\n"
        "movss %xmm3, -0x58(%ebp)\n"
        "calll Z28XAnim_GetTimeIndexCompressedItEvPK9XAnimTimePKT_iPiPf\n"
        "movss -0x58(%ebp), %xmm3\n"
        "movss -0x20(%ebp), %xmm2\n" /* keyFrameLerpFrac */
        "movl -0x1c(%ebp), %edx\n" /* keyFrameIndex */
        "jmp .Lf39f48_0003a1c5\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf39f48_0003a25e:\n"
        "movss %xmm3, -0x30(%ebp)\n" /* line 684 | animTime */
        "movl -0x40(%ebp), %eax\n" /* line 685 | frameCount */
        "movl %eax, -0x2c(%ebp)\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 686 */
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "cvttss2si %xmm0, %eax\n" /* line 687 */
        "movl %eax, -0x24(%ebp)\n"
        "movzwl (%esi), %ecx\n" /* line 1119 | indices, tableSize */
        "leal 8(%esi), %edx\n" /* indices */
        "leal -0x30(%ebp), %eax\n" /* animTime */
        "leal -0x1c(%ebp), %ebx\n" /* keyFrameIndex */
        "movl %ebx, 4(%esp)\n"
        "leal -0x20(%ebp), %ebx\n" /* keyFrameLerpFrac */
        "movl %ebx, (%esp)\n"
        "calll Z18XAnim_GetTimeIndexIhEvPK9XAnimTimePK19XAnimDynamicIndicesiPiPf\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 1121 | keyFrameIndex, frac */
        "movl -0x20(%ebp), %eax\n" /* keyFrameLerpFrac, from */
        "leal (%eax, %eax, 2), %eax\n" /* from */
        "shll $2, %eax\n" /* from */
        "addl 4(%esi), %eax\n" /* indices, from */
        "jmp .Lf39f48_0003a128\n"
        /* } scope */
        /* { scope 2 */
        ".Lf39f48_0003a2ae:\n"
        "movss %xmm3, -0x30(%ebp)\n" /* line 684 | animTime */
        "movl -0x40(%ebp), %eax\n" /* line 685 | frameCount */
        "movl %eax, -0x2c(%ebp)\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 686 */
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "cvttss2si %xmm0, %eax\n" /* line 687 */
        "movl %eax, -0x24(%ebp)\n"
        "movzwl (%edi), %ecx\n" /* line 1074 | indices, tableSize */
        "leal 8(%edi), %edx\n" /* indices */
        "leal -0x30(%ebp), %eax\n" /* animTime */
        "leal -0x20(%ebp), %ebx\n" /* keyFrameLerpFrac */
        "movl %ebx, 4(%esp)\n"
        "leal -0x1c(%ebp), %ebx\n" /* keyFrameIndex */
        "movl %ebx, (%esp)\n"
        "movss %xmm3, -0x58(%ebp)\n"
        "calll Z18XAnim_GetTimeIndexIhEvPK9XAnimTimePK19XAnimDynamicIndicesiPiPf\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 1079 | keyFrameLerpFrac */
        "movl -0x1c(%ebp), %edx\n" /* keyFrameIndex, from */
        "shll $2, %edx\n" /* from */
        "addl 4(%edi), %edx\n" /* indices, from */
        /* { scope 3 */
        "movswl (%edx), %ecx\n" /* line 795 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "movswl 4(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movswl 2(%edx), %ecx\n" /* line 796 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "movswl 6(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movss -0x58(%ebp), %xmm3\n"
        "jmp .Lf39f48_00039fb6\n"
        /* } scope */
        /* } scope */
        ".Lf39f48_0003a341:\n"
        "movl $0, (%esi)\n" /* line 1098 */
        "movl $0x46fffe00, 4(%esi)\n" /* line 1099 */
        "jmp .Lf39f48_0003a09d\n"
        ".Lf39f48_0003a353:\n"
        "movl $0, (%esi)\n" /* line 1098 */
        "movl $0x46fffe00, 4(%esi)\n" /* line 1099 */
        "jmp .Lf39f48_00039fb6\n"
    );
}

/* line 3484 */
__attribute__((naked))
void XAnimGetAbsDelta(const XAnim *anims, unsigned int animIndex, vec_t *rot, vec_t *trans, float time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3484 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* rot */
        "movl 0x14(%ebp), %ebx\n" /* trans */
        /* { scope 1: Q, vec */
        "movl 0xc(%ebp), %edx\n" /* line 3493 | animIndex */
        "shll $3, %edx\n"
        "addl 8(%ebp), %edx\n" /* anims */
        "leal 0xc(%edx), %eax\n"
        "cmpw $0, 0xc(%edx)\n" /* line 3495 */
        "jne .Lf3a366_0003a390\n"
        "movl 4(%eax), %eax\n" /* line 3497 */
        "cmpb $0, 3(%eax)\n" /* line 3500 */
        "jne .Lf3a366_0003a3aa\n"
        ".Lf3a366_0003a390:\n"
        "xorl %eax, %eax\n" /* line 3526 */
        "movl %eax, (%esi)\n" /* rot */
        "movl $0x3f800000, 4(%esi)\n" /* line 3527 | rot */
        "movl %eax, (%ebx)\n" /* line 183 */
        "movl %eax, 4(%ebx)\n" /* line 184 */
        "movl %eax, 8(%ebx)\n" /* line 185 */
        /* } scope */
        "addl $0x20, %esp\n" /* line 3532 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Q, vec */
        /* { scope 2 */
        ".Lf3a366_0003a3aa:\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 1262 | vec */
        "leal -0x10(%ebp), %edx\n" /* Q */
        "movss 0x18(%ebp), %xmm0\n" /* time */
        "calll XAnim_CalcDeltaForTime\n"
        "movss lit4_002ed664, %xmm0\n" /* line 100 | 3.0518509447574615e-05f */
        "movss -0x10(%ebp), %xmm2\n" /* Q */
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss -0xc(%ebp), %xmm0\n" /* line 101 */
        "addss %xmm1, %xmm0\n"
        "movss -0x1c(%ebp), %xmm3\n" /* line 288 | vec */
        "addss %xmm1, %xmm3\n"
        "movss -0x18(%ebp), %xmm4\n" /* line 289 */
        "addss %xmm1, %xmm4\n"
        "movss -0x14(%ebp), %xmm5\n" /* line 290 */
        "addss %xmm1, %xmm5\n"
        /* } scope */
        "ucomiss %xmm1, %xmm2\n" /* line 3509 */
        "jne .Lf3a366_0003a405\n"
        "jp .Lf3a366_0003a405\n"
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf3a366_0003a405\n"
        "je .Lf3a366_0003a423\n"
        ".Lf3a366_0003a405:\n"
        "movss %xmm2, (%esi)\n" /* line 37 */
        "movss %xmm0, 4(%esi)\n" /* line 38 */
        ".Lf3a366_0003a40e:\n"
        "movss %xmm3, (%ebx)\n" /* line 199 */
        "movss %xmm4, 4(%ebx)\n" /* line 200 */
        "movss %xmm5, 8(%ebx)\n" /* line 201 */
        /* } scope */
        "addl $0x20, %esp\n" /* line 3532 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Q, vec */
        ".Lf3a366_0003a423:\n"
        "movl $0, (%esi)\n" /* line 3515 | rot */
        "movl $0x3f800000, 4(%esi)\n" /* line 3516 | rot */
        "jmp .Lf3a366_0003a40e\n"
    );
}

/* line 1216 */
static __attribute__((naked))
void XAnimCalcRelDeltaParts(const float time1, const float time2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1216 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %ebx\n" /* parts */
        "movaps %xmm0, %xmm7\n" /* weightScale */
        "movss %xmm1, -0x50(%ebp)\n"
        "movss %xmm2, -0x54(%ebp)\n"
        "movl %edx, %esi\n" /* rotPos */
        "movl %ecx, %edi\n" /* quatIndex */
        /* { scope 1 */
        "leal -0x24(%ebp), %ecx\n" /* line 1226 | vec1 */
        "leal -0x40(%ebp), %edx\n" /* Q */
        "movaps %xmm1, %xmm0\n"
        "movss %xmm7, -0x68(%ebp)\n" /* weightScale */
        "calll XAnim_CalcDeltaForTime\n"
        "leal -0x30(%ebp), %ecx\n" /* line 1227 | vec2 */
        "leal -0x38(%ebp), %edx\n"
        "movss -0x54(%ebp), %xmm0\n"
        "movl %ebx, %eax\n" /* parts */
        "calll XAnim_CalcDeltaForTime\n"
        "cmpb $0, 2(%ebx)\n" /* line 1229 | parts */
        "movss -0x68(%ebp), %xmm7\n" /* weightScale */
        "je .Lf3a432_0003a48d\n"
        "movss -0x50(%ebp), %xmm0\n"
        "ucomiss -0x54(%ebp), %xmm0\n"
        "ja .Lf3a432_0003a5bd\n"
        ".Lf3a432_0003a48d:\n"
        "movss -0x30(%ebp), %xmm6\n" /* vec2 */
        "movss -0x2c(%ebp), %xmm5\n"
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        ".Lf3a432_0003a4a1:\n"
        "movaps %xmm7, %xmm4\n" /* line 1244 | weightScale */
        "mulss lit4_002ed668, %xmm4\n" /* 9.313794180343393e-10f */
        "movss -0x38(%ebp), %xmm2\n" /* line 1246 */
        "movaps %xmm2, %xmm0\n"
        "mulss -0x3c(%ebp), %xmm0\n"
        "movss -0x34(%ebp), %xmm3\n"
        "movaps %xmm3, %xmm1\n"
        "mulss -0x40(%ebp), %xmm1\n" /* Q */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss (%esi), %xmm0\n" /* rotPos */
        "movss %xmm0, (%esi)\n" /* rotPos */
        "mulss -0x40(%ebp), %xmm2\n" /* line 1247 | Q */
        "mulss -0x3c(%ebp), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss %xmm2, %xmm4\n"
        "addss 4(%esi), %xmm4\n" /* rotPos */
        "movss %xmm4, 4(%esi)\n" /* rotPos */
        "subss -0x24(%ebp), %xmm6\n" /* line 248 | vec1 */
        "subss -0x20(%ebp), %xmm5\n" /* line 249 */
        "movss -0x58(%ebp), %xmm0\n" /* line 250 */
        "subss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "leal -0x40(%ebp, %edi, 8), %eax\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss (%eax), %xmm4\n" /* line 1201 */
        "movaps %xmm4, %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "movss 4(%eax), %xmm1\n" /* line 1202 */
        "movaps %xmm1, %xmm3\n"
        "mulss %xmm1, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "ucomiss lit4_002ed5e8, %xmm3\n" /* line 1203 | 0.0f */
        "je .Lf3a432_0003a642\n"
        ".Lf3a432_0003a537:\n"
        "movss lit4_002ed62c, %xmm0\n" /* line 1206 | 2.0f */
        "divss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm2\n" /* line 1207 */
        "mulss %xmm4, %xmm1\n" /* line 1208 */
        "mulss %xmm0, %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 1210 | 1.0f */
        "subss %xmm2, %xmm3\n"
        "mulss %xmm6, %xmm3\n"
        "movaps %xmm5, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss %xmm1, %xmm6\n" /* line 1211 */
        "mulss %xmm5, %xmm2\n"
        "addss %xmm2, %xmm6\n"
        "subss %xmm6, %xmm5\n"
        /* } scope */
        /* } scope */
        ".Lf3a432_0003a57a:\n"
        "movaps %xmm7, %xmm0\n" /* line 1252 | weightScale */
        "addss 8(%esi), %xmm0\n" /* rotPos */
        "movss %xmm0, 8(%esi)\n" /* rotPos */
        "leal 0xc(%esi), %eax\n" /* line 1253 | rotPos, result */
        /* { scope 2 */
        "mulss %xmm7, %xmm3\n" /* line 288 */
        "addss 0xc(%esi), %xmm3\n"
        "movss %xmm3, 0xc(%esi)\n"
        "mulss %xmm7, %xmm5\n" /* line 289 */
        "addss 4(%eax), %xmm5\n"
        "movss %xmm5, 4(%eax)\n"
        "mulss -0x4c(%ebp), %xmm7\n" /* line 290 */
        "addss 8(%eax), %xmm7\n"
        "movss %xmm7, 8(%eax)\n"
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3a432_0003a5bd:\n"
        "movl 0x20(%ebx), %eax\n" /* line 1233 | parts */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n" /* line 1234 */
        "je .Lf3a432_0003a48d\n"
        "movzwl (%ecx), %eax\n" /* line 1236 */
        "testw %ax, %ax\n"
        "je .Lf3a432_0003a48d\n"
        "movzwl %ax, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 4(%ecx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        /* { scope 2 */
        "movss -0x30(%ebp), %xmm6\n" /* line 240 | vec2 */
        "addss (%eax), %xmm6\n"
        "movss %xmm6, -0x30(%ebp)\n" /* vec2 */
        "movss -0x2c(%ebp), %xmm5\n" /* line 241 */
        "addss 4(%eax), %xmm5\n"
        "movss %xmm5, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 242 */
        "movss %xmm0, -0x58(%ebp)\n"
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movl 4(%ecx), %eax\n"
        /* } scope */
        /* { scope 2 */
        "subss (%eax), %xmm6\n" /* line 248 */
        "movss %xmm6, -0x30(%ebp)\n" /* vec2 */
        "subss 4(%eax), %xmm5\n" /* line 249 */
        "movss %xmm5, -0x2c(%ebp)\n"
        "subss 8(%eax), %xmm0\n" /* line 250 */
        "movss %xmm0, -0x58(%ebp)\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "jmp .Lf3a432_0003a4a1\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf3a432_0003a642:\n"
        "jp .Lf3a432_0003a537\n" /* line 1203 */
        "movaps %xmm6, %xmm3\n"
        "jmp .Lf3a432_0003a57a\n"
    );
}

/* line 3428 */
__attribute__((naked))
void XAnimGetRelDelta(const XAnim *anims, unsigned int animIndex, vec_t *rot, vec_t *trans, float time1, float time2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3428 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* rot */
        "movl 0x14(%ebp), %ebx\n" /* trans */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 3437 | animIndex */
        "shll $3, %edx\n"
        "addl 8(%ebp), %edx\n" /* anims */
        "leal 0xc(%edx), %eax\n"
        "cmpw $0, 0xc(%edx)\n" /* line 3439 */
        "jne .Lf3a650_0003a67a\n"
        "movl 4(%eax), %eax\n" /* line 3441 */
        "cmpb $0, 3(%eax)\n" /* line 3444 */
        "jne .Lf3a650_0003a694\n"
        ".Lf3a650_0003a67a:\n"
        "xorl %eax, %eax\n" /* line 3470 */
        "movl %eax, (%esi)\n" /* rot */
        "movl $0x3f800000, 4(%esi)\n" /* line 3471 | rot */
        "movl %eax, (%ebx)\n" /* line 183 */
        "movl %eax, 4(%ebx)\n" /* line 184 */
        "movl %eax, 8(%ebx)\n" /* line 185 */
        /* } scope */
        "addl $0x30, %esp\n" /* line 3476 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3a650_0003a694:\n"
        "pxor %xmm3, %xmm3\n" /* line 23 */
        "movss %xmm3, -0x20(%ebp)\n" /* rotPos */
        "movss %xmm3, -0x1c(%ebp)\n" /* line 24 */
        "movss %xmm3, -0x18(%ebp)\n" /* line 3447 */
        "movss %xmm3, -0x14(%ebp)\n" /* line 183 */
        "movss %xmm3, -0x10(%ebp)\n" /* line 184 */
        "movss %xmm3, -0xc(%ebp)\n" /* line 185 */
        "leal -0x20(%ebp), %edx\n" /* line 3450 | rotPos */
        "xorl %ecx, %ecx\n"
        "movss 0x1c(%ebp), %xmm2\n" /* time2 */
        "movss 0x18(%ebp), %xmm1\n" /* time1 */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm3, -0x38(%ebp)\n"
        "calll XAnimCalcRelDeltaParts\n"
        "movss -0x38(%ebp), %xmm3\n" /* line 3453 */
        "ucomiss -0x20(%ebp), %xmm3\n" /* rotPos */
        "jne .Lf3a650_0003a6ec\n"
        "jp .Lf3a650_0003a6ec\n"
        "ucomiss -0x1c(%ebp), %xmm3\n"
        "jp .Lf3a650_0003a6ec\n"
        "je .Lf3a650_0003a70f\n"
        ".Lf3a650_0003a6ec:\n"
        "movl -0x20(%ebp), %eax\n" /* line 37 | rotPos */
        "movl %eax, (%esi)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 38 */
        "movl %eax, 4(%esi)\n"
        ".Lf3a650_0003a6f7:\n"
        "movl -0x14(%ebp), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 3476 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3a650_0003a70f:\n"
        "movl $0, (%esi)\n" /* line 3459 | rot */
        "movl $0x3f800000, 4(%esi)\n" /* line 3460 | rot */
        "jmp .Lf3a650_0003a6f7\n"
    );
}

/* line 3792 */
static __attribute__((naked))
void XAnimClearTreeWeights(XAnimTree *tree, unsigned int animIndex)
{
    __asm__ __volatile__ (
        ".Lf3a71e_0003a71e:\n"
        "pushl %ebp\n" /* line 3792 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl %eax, -0xc0(%ebp)\n"
        "movl %edx, -0xc4(%ebp)\n"
        /* { scope 1: animIndex */
        "movl %eax, %ecx\n" /* line 3803 */
        "movzwl 8(%eax, %edx, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "movl %edx, -0xb4(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003ae60\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "movl -0xc4(%ebp), %ecx\n"
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0xb0(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3808 */
        "movl %eax, -0xbc(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3809 */
        "jle .Lf3a71e_0003aded\n"
        "movl $0, -0xb8(%ebp)\n" /* i */
        ".Lf3a71e_0003a77f:\n"
        "movl -0xb0(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %eax\n"
        "addl -0xb8(%ebp), %eax\n" /* i */
        "movl %eax, -0xac(%ebp)\n" /* animIndex */
        /* { scope 2: numAnims, i, anim */
        /* { scope 3: animIndex, infoIndex */
        "movl -0xc0(%ebp), %ecx\n" /* line 3803 */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003add4\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "movl -0xac(%ebp), %ecx\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0xa0(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3808 */
        "movl %eax, -0xa8(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3809 */
        "jle .Lf3a71e_0003ad67\n"
        "movl $0, -0xa4(%ebp)\n" /* i */
        ".Lf3a71e_0003a7df:\n"
        "movl -0xa0(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %eax\n"
        "addl -0xa4(%ebp), %eax\n" /* i */
        "movl %eax, -0x9c(%ebp)\n" /* animIndex */
        /* { scope 4: numAnims, i, anim */
        /* { scope 5: animIndex, infoIndex */
        "movl -0xc0(%ebp), %ecx\n" /* line 3803 */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003ad4e\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "movl -0x9c(%ebp), %ecx\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x90(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3808 */
        "movl %eax, -0x98(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3809 */
        "jle .Lf3a71e_0003acee\n"
        "movl $0, -0x94(%ebp)\n" /* i */
        ".Lf3a71e_0003a83f:\n"
        "movl -0x90(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %eax\n"
        "addl -0x94(%ebp), %eax\n" /* i */
        "movl %eax, -0x8c(%ebp)\n" /* animIndex */
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: animIndex, infoIndex */
        "movl -0xc0(%ebp), %ecx\n" /* line 3803 */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003acd5\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "movl -0x8c(%ebp), %ecx\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x80(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3808 */
        "movl %eax, -0x88(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3809 */
        "jle .Lf3a71e_0003ac75\n"
        "movl $0, -0x84(%ebp)\n" /* i */
        ".Lf3a71e_0003a89c:\n"
        "movl -0x80(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %eax\n"
        "addl -0x84(%ebp), %eax\n" /* i */
        "movl %eax, -0x7c(%ebp)\n" /* animIndex */
        /* { scope 8: numAnims, i, anim */
        /* { scope 9: animIndex, infoIndex */
        "movl -0xc0(%ebp), %ecx\n" /* line 3803 */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003ac5c\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "movl -0x7c(%ebp), %ecx\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3808 */
        "movl %eax, -0x78(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3809 */
        "jle .Lf3a71e_0003abff\n"
        "movl $0, -0x74(%ebp)\n" /* i */
        ".Lf3a71e_0003a8ea:\n"
        "movl -0x70(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %eax\n"
        "addl -0x74(%ebp), %eax\n" /* i */
        "movl %eax, -0x6c(%ebp)\n" /* animIndex */
        /* { scope 10: numAnims, i, anim */
        /* { scope 11: animIndex, infoIndex */
        "movl -0xc0(%ebp), %ecx\n" /* line 3803 */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003abef\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "movl -0x6c(%ebp), %ecx\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x60(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3808 */
        "movl %eax, -0x68(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3809 */
        "jle .Lf3a71e_0003ab92\n"
        "movl $0, -0x64(%ebp)\n" /* i */
        ".Lf3a71e_0003a935:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %eax\n"
        "addl -0x64(%ebp), %eax\n" /* i */
        "movl %eax, -0x5c(%ebp)\n" /* animIndex */
        /* { scope 12: numAnims, i, anim */
        /* { scope 13: animIndex, infoIndex */
        "movl -0xc0(%ebp), %ecx\n" /* line 3803 */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003ab82\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "movl -0x5c(%ebp), %ecx\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x50(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3808 */
        "movl %eax, -0x58(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3809 */
        "jle .Lf3a71e_0003ab25\n"
        "movl $0, -0x54(%ebp)\n" /* i */
        ".Lf3a71e_0003a980:\n"
        "movl -0x50(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %eax\n"
        "addl -0x54(%ebp), %eax\n" /* i */
        "movl %eax, -0x4c(%ebp)\n" /* animIndex */
        /* { scope 14: numAnims, i, anim */
        /* { scope 15: animIndex, infoIndex */
        "movl -0xc0(%ebp), %ecx\n" /* line 3803 */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003ab15\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "movl -0x4c(%ebp), %ecx\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x40(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3808 */
        "movl %eax, -0x48(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3809 */
        "jle .Lf3a71e_0003aab8\n"
        "movl $0, -0x44(%ebp)\n" /* i */
        "jmp .Lf3a71e_0003aa34\n"
        /* { scope 16: anim */
        /* { scope 17 */
        /* { scope 18 */
        ".Lf3a71e_0003a9cd:\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 1287 */
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 19 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3a71e_0003aaa2\n"
        ".Lf3a71e_0003a9e4:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movw %di, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %di, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0x3c(%ebp), %eax\n" /* line 3814 | animIndex */
        "movl -0xc0(%ebp), %edx\n"
        "movw $0, 8(%edx, %eax, 2)\n"
        /* } scope */
        /* } scope */
        ".Lf3a71e_0003aa24:\n"
        "addl $1, -0x44(%ebp)\n" /* line 3809 | i */
        "movl -0x44(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x48(%ebp)\n" /* numAnims */
        "je .Lf3a71e_0003aab8\n"
        ".Lf3a71e_0003aa34:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %eax\n"
        "addl -0x44(%ebp), %eax\n" /* i */
        "movl %eax, -0x3c(%ebp)\n" /* animIndex */
        /* { scope 16: anim */
        /* { scope 17 */
        "movl %eax, %edx\n" /* line 3803 */
        "movl -0xc0(%ebp), %ecx\n"
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "movzwl %ax, %edi\n"
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3a71e_0003aa24\n"
        "movl (%ecx), %eax\n" /* line 3807 */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %esi\n" /* line 3808 | numAnims */
        "testl %esi, %esi\n" /* line 3809 | numAnims */
        "jle .Lf3a71e_0003a9cd\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3a71e_0003aa6f:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "movl -0xc0(%ebp), %eax\n"
        "calll XAnimClearTreeWeights\n"
        "addl $1, %ebx\n" /* line 3809 | i */
        "cmpl %ebx, %esi\n" /* i, numAnims */
        "jne .Lf3a71e_0003aa6f\n"
        /* { scope 18 */
        "leal (%edi, %edi, 4), %eax\n" /* line 1287 */
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 19 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3a71e_0003a9e4\n"
        ".Lf3a71e_0003aaa2:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3a71e_0003a9e4\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 16: anim */
        ".Lf3a71e_0003aab8:\n"
        "movl -0x34(%ebp), %edx\n" /* line 1287 | infoIndex */
        "leal (%edx, %edx, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 17 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3a71e_0003ae6b\n"
        ".Lf3a71e_0003aad2:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x34(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0x4c(%ebp), %edx\n" /* line 3814 | animIndex */
        "movl -0xc0(%ebp), %ecx\n"
        "movw $0, 8(%ecx, %edx, 2)\n"
        /* } scope */
        /* } scope */
        ".Lf3a71e_0003ab15:\n"
        "addl $1, -0x54(%ebp)\n" /* line 3809 | i */
        "movl -0x54(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x58(%ebp)\n" /* numAnims */
        "jne .Lf3a71e_0003a980\n"
        /* { scope 14: numAnims, i, anim */
        ".Lf3a71e_0003ab25:\n"
        "movl -0x30(%ebp), %edx\n" /* line 1287 | infoIndex */
        "leal (%edx, %edx, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 15: animIndex, infoIndex */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3a71e_0003ae81\n"
        ".Lf3a71e_0003ab3f:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0x5c(%ebp), %edx\n" /* line 3814 | animIndex */
        "movl -0xc0(%ebp), %ecx\n"
        "movw $0, 8(%ecx, %edx, 2)\n"
        /* } scope */
        /* } scope */
        ".Lf3a71e_0003ab82:\n"
        "addl $1, -0x64(%ebp)\n" /* line 3809 | i */
        "movl -0x64(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x68(%ebp)\n" /* numAnims */
        "jne .Lf3a71e_0003a935\n"
        /* { scope 12: numAnims, i, anim */
        ".Lf3a71e_0003ab92:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1287 | infoIndex */
        "leal (%edx, %edx, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 13: animIndex, infoIndex */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3a71e_0003ae97\n"
        ".Lf3a71e_0003abac:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x2c(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0x6c(%ebp), %edx\n" /* line 3814 | animIndex */
        "movl -0xc0(%ebp), %ecx\n"
        "movw $0, 8(%ecx, %edx, 2)\n"
        /* } scope */
        /* } scope */
        ".Lf3a71e_0003abef:\n"
        "addl $1, -0x74(%ebp)\n" /* line 3809 | i */
        "movl -0x74(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x78(%ebp)\n" /* numAnims */
        "jne .Lf3a71e_0003a8ea\n"
        /* { scope 10: numAnims, i, anim */
        ".Lf3a71e_0003abff:\n"
        "movl -0x28(%ebp), %edx\n" /* line 1287 | infoIndex */
        "leal (%edx, %edx, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 11: animIndex, infoIndex */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3a71e_0003aead\n"
        ".Lf3a71e_0003ac19:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x28(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0x7c(%ebp), %edx\n" /* line 3814 | animIndex */
        "movl -0xc0(%ebp), %ecx\n"
        "movw $0, 8(%ecx, %edx, 2)\n"
        /* } scope */
        /* } scope */
        ".Lf3a71e_0003ac5c:\n"
        "addl $1, -0x84(%ebp)\n" /* line 3809 | i */
        "movl -0x84(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x88(%ebp)\n" /* numAnims */
        "jne .Lf3a71e_0003a89c\n"
        /* { scope 8: numAnims, i, anim */
        ".Lf3a71e_0003ac75:\n"
        "movl -0x24(%ebp), %edx\n" /* line 1287 | infoIndex */
        "leal (%edx, %edx, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 9: animIndex, infoIndex */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3a71e_0003aec3\n"
        ".Lf3a71e_0003ac8f:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x24(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0x8c(%ebp), %edx\n" /* line 3814 | animIndex */
        "movl -0xc0(%ebp), %ecx\n"
        "movw $0, 8(%ecx, %edx, 2)\n"
        /* } scope */
        /* } scope */
        ".Lf3a71e_0003acd5:\n"
        "addl $1, -0x94(%ebp)\n" /* line 3809 | i */
        "movl -0x94(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x98(%ebp)\n" /* numAnims */
        "jne .Lf3a71e_0003a83f\n"
        /* { scope 6: numAnims, i, anim */
        ".Lf3a71e_0003acee:\n"
        "movl -0x20(%ebp), %edx\n" /* line 1287 | infoIndex */
        "leal (%edx, %edx, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 7: animIndex, infoIndex */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3a71e_0003aed9\n"
        ".Lf3a71e_0003ad08:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0x9c(%ebp), %edx\n" /* line 3814 | animIndex */
        "movl -0xc0(%ebp), %ecx\n"
        "movw $0, 8(%ecx, %edx, 2)\n"
        /* } scope */
        /* } scope */
        ".Lf3a71e_0003ad4e:\n"
        "addl $1, -0xa4(%ebp)\n" /* line 3809 | i */
        "movl -0xa4(%ebp), %eax\n" /* i */
        "cmpl %eax, -0xa8(%ebp)\n" /* numAnims */
        "jne .Lf3a71e_0003a7df\n"
        /* { scope 4: numAnims, i, anim */
        ".Lf3a71e_0003ad67:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1287 | infoIndex */
        "leal (%edx, %edx, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 5: animIndex, infoIndex */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3a71e_0003ad8e\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        ".Lf3a71e_0003ad8e:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x1c(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0xac(%ebp), %edx\n" /* line 3814 | animIndex */
        "movl -0xc0(%ebp), %ecx\n"
        "movw $0, 8(%ecx, %edx, 2)\n"
        /* } scope */
        /* } scope */
        ".Lf3a71e_0003add4:\n"
        "addl $1, -0xb8(%ebp)\n" /* line 3809 | i */
        "movl -0xb8(%ebp), %eax\n" /* i */
        "cmpl %eax, -0xbc(%ebp)\n" /* numAnims */
        "jne .Lf3a71e_0003a77f\n"
        ".Lf3a71e_0003aded:\n"
        "movl -0xb4(%ebp), %edx\n" /* line 1287 | infoIndex */
        "leal (%edx, %edx, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 2: numAnims, i, anim */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3a71e_0003ae17\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        ".Lf3a71e_0003ae17:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0xb4(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        "movl -0xc4(%ebp), %edx\n" /* line 3814 */
        "movl -0xc0(%ebp), %ecx\n"
        "movw $0, 8(%ecx, %edx, 2)\n"
        /* } scope */
        ".Lf3a71e_0003ae60:\n"
        "addl $0xcc, %esp\n" /* line 3815 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: animIndex */
        /* { scope 2: numAnims, i, anim */
        /* { scope 3: animIndex, infoIndex */
        /* { scope 4: numAnims, i, anim */
        /* { scope 5: animIndex, infoIndex */
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: animIndex, infoIndex */
        /* { scope 8: numAnims, i, anim */
        /* { scope 9: animIndex, infoIndex */
        /* { scope 10: numAnims, i, anim */
        /* { scope 11: animIndex, infoIndex */
        /* { scope 12: numAnims, i, anim */
        /* { scope 13: animIndex, infoIndex */
        /* { scope 14: numAnims, i, anim */
        /* { scope 15: animIndex, infoIndex */
        /* { scope 16: anim */
        /* { scope 17 */
        ".Lf3a71e_0003ae6b:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3a71e_0003aad2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 14: numAnims, i, anim */
        /* { scope 15: animIndex, infoIndex */
        ".Lf3a71e_0003ae81:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3a71e_0003ab3f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 12: numAnims, i, anim */
        /* { scope 13: animIndex, infoIndex */
        ".Lf3a71e_0003ae97:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3a71e_0003abac\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 10: numAnims, i, anim */
        /* { scope 11: animIndex, infoIndex */
        ".Lf3a71e_0003aead:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3a71e_0003ac19\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 8: numAnims, i, anim */
        /* { scope 9: animIndex, infoIndex */
        ".Lf3a71e_0003aec3:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3a71e_0003ac8f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: animIndex, infoIndex */
        ".Lf3a71e_0003aed9:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3a71e_0003ad08\n"
    );
}

/* line 2675 */
static __attribute__((naked))
void XAnimCalcDeltaTree(const XAnimTree *tree, const Bool bClear, int bNormQuat, XAnimSimpleRotPos *rotPos)
{
    __asm__ __volatile__ (
        ".Lf3aef0_0003aef0:\n"
        "pushl %ebp\n" /* line 2675 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl %edx, %esi\n" /* animIndex */
        "movaps %xmm0, %xmm3\n" /* weightScale */
        "movb %cl, -0x69(%ebp)\n"
        "movzbl 8(%ebp), %eax\n" /* bNormQuat */
        "movb %al, -0x6a(%ebp)\n" /* bNormQuat */
        /* { scope 1: Q, vec, i, y */
        "movl -0x68(%ebp), %edx\n" /* line 2694 */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 2695 */
        "movzwl %ax, %edi\n" /* numAnims */
        "testw %ax, %ax\n" /* line 2696 */
        "jne .Lf3aef0_0003af8c\n"
        "cmpb $0, -0x69(%ebp)\n" /* line 2698 */
        "jne .Lf3aef0_0003b039\n"
        "movl -0x5c(%ebp), %eax\n" /* line 2705 | anim */
        "movl 4(%eax), %ebx\n" /* parts */
        "cmpb $0, 3(%ebx)\n" /* line 2708 | parts */
        "je .Lf3aef0_0003af81\n"
        ".Lf3aef0_0003af3e:\n"
        "movl -0x68(%ebp), %edx\n" /* line 2712 */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n" /* line 2713 */
        "je .Lf3aef0_0003af81\n"
        "movzwl %ax, %eax\n" /* line 2718 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "leal 0xc(%eax), %esi\n" /* animIndex */
        "cmpb $0, 6(%edx)\n" /* line 2720 */
        "jne .Lf3aef0_0003b069\n"
        "movl $1, %ecx\n" /* line 2723 */
        "movl 0xc(%ebp), %edx\n" /* rotPos */
        "movss 0xc(%eax), %xmm2\n"
        "movss 4(%esi), %xmm1\n" /* animIndex */
        "movaps %xmm3, %xmm0\n" /* weightScale */
        "movl %ebx, %eax\n" /* parts */
        "calll XAnimCalcRelDeltaParts\n"
        /* } scope */
        ".Lf3aef0_0003af81:\n"
        "addl $0xac, %esp\n" /* line 2824 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Q, vec, i, y */
        ".Lf3aef0_0003af8c:\n"
        "testl %edi, %edi\n" /* line 2727 | numAnims */
        "jle .Lf3aef0_0003b005\n"
        "movl -0x5c(%ebp), %eax\n" /* line 2730 | anim */
        "movzwl 6(%eax), %ebx\n" /* parts */
        "movl -0x68(%ebp), %ecx\n"
        "leal 8(%ecx, %ebx, 2), %edx\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf3aef0_0003afca\n"
        ".Lf3aef0_0003afa2:\n"
        "movl -0x9c(%ebp), %eax\n" /* line 2736 | state */
        "movss 0x14(%eax), %xmm0\n"
        ".Lf3aef0_0003afad:\n"
        "pxor %xmm4, %xmm4\n" /* line 2738 */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3aef0_0003b108\n"
        "jne .Lf3aef0_0003b108\n"
        ".Lf3aef0_0003afc0:\n"
        "addl $1, %ecx\n" /* line 2727 */
        "addl $2, %edx\n"
        "cmpl %ecx, %edi\n" /* numAnims */
        "je .Lf3aef0_0003b005\n"
        ".Lf3aef0_0003afca:\n"
        "leal (%ecx, %ebx), %eax\n" /* line 2723 */
        "movl %eax, -0x64(%ebp)\n"
        "movzwl (%edx), %eax\n" /* line 2730 */
        "testw %ax, %ax\n" /* line 2731 */
        "je .Lf3aef0_0003afc0\n"
        "movzwl %ax, %eax\n" /* line 2735 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo+12(, %eax, 8), %eax\n"
        "movl %eax, -0x9c(%ebp)\n" /* state */
        "movl -0x68(%ebp), %eax\n" /* line 2736 */
        "movzbl 7(%eax), %esi\n" /* animIndex */
        "movl %esi, %eax\n" /* animIndex */
        "testb %al, %al\n"
        "je .Lf3aef0_0003afa2\n"
        "movl -0x9c(%ebp), %eax\n" /* state */
        "movss 0x10(%eax), %xmm0\n"
        "jmp .Lf3aef0_0003afad\n"
        ".Lf3aef0_0003b005:\n"
        "cmpb $0, -0x69(%ebp)\n" /* line 2818 */
        "je .Lf3aef0_0003af81\n"
        "xorl %eax, %eax\n" /* line 23 */
        "movl 0xc(%ebp), %edx\n" /* rotPos */
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 24 */
        "movl %eax, 8(%edx)\n" /* line 2821 */
        "movl 0xc(%ebp), %edx\n" /* line 2822 | rotPos, v */
        "addl $0xc, %edx\n" /* v */
        /* { scope 2 */
        "movl 0xc(%ebp), %ecx\n" /* line 183 | rotPos */
        "movl %eax, 0xc(%ecx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        /* } scope */
        "addl $0xac, %esp\n" /* line 2824 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Q, vec, i, y */
        ".Lf3aef0_0003b039:\n"
        "xorl %eax, %eax\n" /* line 23 */
        "movl 0xc(%ebp), %ebx\n" /* rotPos */
        "movl %eax, (%ebx)\n"
        "movl %eax, 4(%ebx)\n" /* line 24 */
        "movl %eax, 8(%ebx)\n" /* line 2701 | parts */
        "movl %ebx, %edx\n" /* line 2702 | parts, v */
        "addl $0xc, %edx\n" /* v */
        /* { scope 2 */
        "movl %eax, 0xc(%ebx)\n" /* line 183 */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "movl -0x5c(%ebp), %eax\n" /* line 2705 | anim */
        "movl 4(%eax), %ebx\n" /* parts */
        "cmpb $0, 3(%ebx)\n" /* line 2708 | parts */
        "jne .Lf3aef0_0003af3e\n"
        "jmp .Lf3aef0_0003af81\n"
        /* { scope 2 */
        ".Lf3aef0_0003b069:\n"
        "leal -0x34(%ebp), %ecx\n" /* line 1262 | vec */
        "leal -0x28(%ebp), %edx\n" /* Q */
        "movss 0xc(%eax), %xmm0\n"
        "movl %ebx, %eax\n"
        "movss %xmm3, -0x98(%ebp)\n"
        "calll XAnim_CalcDeltaForTime\n"
        "movss -0x98(%ebp), %xmm3\n" /* line 1264 */
        "movaps %xmm3, %xmm1\n" /* scale */
        "mulss lit4_002ed664, %xmm1\n" /* 3.0518509447574615e-05f, scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 100 */
        "mulss -0x28(%ebp), %xmm0\n" /* Q */
        "movl 0xc(%ebp), %ecx\n" /* rotPos */
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "mulss -0x24(%ebp), %xmm1\n" /* line 101 */
        "addss 4(%ecx), %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 1266 */
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "movl %ecx, %eax\n" /* line 1267 | result */
        "addl $0xc, %eax\n" /* result */
        /* { scope 3 */
        "movaps %xmm3, %xmm0\n" /* line 288 */
        "mulss -0x34(%ebp), %xmm0\n" /* vec */
        "addss 0xc(%ecx), %xmm0\n"
        "movss %xmm0, 0xc(%ecx)\n"
        "movaps %xmm3, %xmm0\n" /* line 289 */
        "mulss -0x30(%ebp), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss -0x2c(%ebp), %xmm3\n" /* line 290 */
        "addss 8(%eax), %xmm3\n"
        "movss %xmm3, 8(%eax)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0xac, %esp\n" /* line 2824 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Q, vec, i, y */
        ".Lf3aef0_0003b108:\n"
        "leal 1(%ecx), %edx\n" /* line 2741 */
        "cmpl %edx, %edi\n" /* numAnims */
        "jle .Lf3aef0_0003b26b\n"
        "movl %esi, %eax\n" /* line 2730 | animIndex */
        "testb %al, %al\n"
        "je .Lf3aef0_0003b22f\n"
        "leal (%edx, %ebx), %eax\n"
        "movl -0x68(%ebp), %ebx\n" /* parts */
        "leal 8(%ebx, %eax, 2), %ecx\n" /* parts */
        "movl %edx, %ebx\n" /* parts */
        "movl %edi, %edx\n" /* numAnims */
        "jmp .Lf3aef0_0003b13b\n"
        ".Lf3aef0_0003b12d:\n"
        "addl $1, %ebx\n" /* line 2741 | parts */
        "addl $2, %ecx\n"
        "cmpl %edx, %ebx\n" /* parts */
        "je .Lf3aef0_0003b26b\n"
        ".Lf3aef0_0003b13b:\n"
        "movzwl (%ecx), %eax\n" /* line 2744 */
        "testw %ax, %ax\n" /* line 2745 */
        "je .Lf3aef0_0003b12d\n"
        "movzwl %ax, %eax\n" /* line 2750 */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm1\n"
        "ucomiss %xmm4, %xmm1\n" /* line 2752 */
        "jp .Lf3aef0_0003b159\n"
        "je .Lf3aef0_0003b12d\n"
        ".Lf3aef0_0003b159:\n"
        "cmpb $0, -0x69(%ebp)\n" /* line 2755 */
        "jne .Lf3aef0_0003b3e5\n"
        "leal -0x4c(%ebp), %eax\n" /* newRotPos */
        "movl %eax, -0x60(%ebp)\n" /* rotPos2 */
        "movl %eax, %ecx\n"
        ".Lf3aef0_0003b16b:\n"
        "movl %ecx, 4(%esp)\n" /* line 2757 */
        "movl $1, (%esp)\n"
        "movl $1, %ecx\n"
        "movl -0x64(%ebp), %edx\n"
        "movl -0x68(%ebp), %eax\n"
        "movss %xmm1, -0x88(%ebp)\n"
        "movss %xmm3, -0x98(%ebp)\n" /* weightScale */
        "calll XAnimCalcDeltaTree\n"
        "movl -0x5c(%ebp), %eax\n" /* line 2758 | anim */
        "movzwl 6(%eax), %edx\n"
        "addl %ebx, %edx\n" /* parts */
        "movl -0x60(%ebp), %ecx\n" /* rotPos2 */
        "movl %ecx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movss -0x88(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimCalcDeltaTree\n"
        "leal 1(%ebx), %eax\n" /* line 2760 | parts */
        "cmpl %eax, %edi\n" /* numAnims */
        "movss -0x98(%ebp), %xmm3\n" /* weightScale */
        "jle .Lf3aef0_0003b290\n"
        "movl %eax, %ebx\n" /* parts */
        "pxor %xmm4, %xmm4\n"
        "movl %edi, %esi\n" /* numAnims, animIndex */
        "jmp .Lf3aef0_0003b1fe\n"
        ".Lf3aef0_0003b1df:\n"
        "movss 0x14(%eax), %xmm0\n" /* line 2769 */
        ".Lf3aef0_0003b1e4:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 2771 */
        "jp .Lf3aef0_0003b2e7\n"
        "jne .Lf3aef0_0003b2e7\n"
        ".Lf3aef0_0003b1f3:\n"
        "addl $1, %ebx\n" /* line 2760 | parts */
        "cmpl %ebx, %esi\n" /* parts, animIndex */
        "je .Lf3aef0_0003b294\n"
        ".Lf3aef0_0003b1fe:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 2763 | anim */
        "movzwl 6(%edx), %eax\n"
        "leal (%ebx, %eax), %edx\n" /* parts */
        "movl -0x68(%ebp), %ecx\n"
        "movzwl 8(%ecx, %edx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 2764 */
        "je .Lf3aef0_0003b1f3\n"
        "movzwl %ax, %eax\n" /* line 2768 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo+12(, %eax, 8), %eax\n"
        "cmpb $0, 7(%ecx)\n" /* line 2769 */
        "je .Lf3aef0_0003b1df\n"
        "movss 0x10(%eax), %xmm0\n"
        "jmp .Lf3aef0_0003b1e4\n"
        ".Lf3aef0_0003b22f:\n"
        "leal (%edx, %ebx), %eax\n" /* line 2741 */
        "movl -0x68(%ebp), %ebx\n" /* parts */
        "leal 8(%ebx, %eax, 2), %ecx\n" /* parts */
        "movl %edx, %ebx\n" /* parts */
        ".Lf3aef0_0003b23b:\n"
        "movzwl (%ecx), %eax\n" /* line 2744 */
        "testw %ax, %ax\n" /* line 2745 */
        "je .Lf3aef0_0003b261\n"
        "movzwl %ax, %eax\n" /* line 2750 */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+32(, %eax, 8), %xmm1\n"
        "ucomiss %xmm4, %xmm1\n" /* line 2752 */
        "jp .Lf3aef0_0003b159\n"
        "jne .Lf3aef0_0003b159\n"
        ".Lf3aef0_0003b261:\n"
        "addl $1, %ebx\n" /* line 2741 | parts */
        "addl $2, %ecx\n"
        "cmpl %edi, %ebx\n" /* numAnims, parts */
        "jne .Lf3aef0_0003b23b\n"
        ".Lf3aef0_0003b26b:\n"
        "movzbl -0x69(%ebp), %ecx\n" /* line 2814 */
        "movl 0xc(%ebp), %ebx\n" /* rotPos, parts */
        "movl %ebx, 4(%esp)\n" /* parts */
        "movzbl -0x6a(%ebp), %eax\n" /* bNormQuat */
        "movl %eax, (%esp)\n"
        "movaps %xmm3, %xmm0\n" /* weightScale */
        "movl -0x64(%ebp), %edx\n"
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimCalcDeltaTree\n"
        "jmp .Lf3aef0_0003af81\n"
        ".Lf3aef0_0003b290:\n"
        "pxor %xmm4, %xmm4\n"
        ".Lf3aef0_0003b294:\n"
        "cmpb $0, -0x6a(%ebp)\n" /* line 2777 | bNormQuat */
        "jne .Lf3aef0_0003b318\n"
        "movl 0xc(%ebp), %edx\n" /* line 2780 | rotPos */
        "movss 8(%edx), %xmm1\n"
        "ucomiss %xmm4, %xmm1\n"
        "jp .Lf3aef0_0003b2ad\n"
        "je .Lf3aef0_0003af81\n"
        ".Lf3aef0_0003b2ad:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 2783 | 1.0f, scale */
        "divss %xmm1, %xmm0\n" /* scale */
        "movl %edx, %eax\n" /* result */
        "addl $0xc, %eax\n" /* result */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss %xmm1, 0xc(%edx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%eax), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        "jmp .Lf3aef0_0003af81\n"
        /* } scope */
        ".Lf3aef0_0003b2e7:\n"
        "movl -0x60(%ebp), %eax\n" /* line 2774 | rotPos2 */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl -0x68(%ebp), %eax\n"
        "movss %xmm3, -0x98(%ebp)\n" /* weightScale */
        "calll XAnimCalcDeltaTree\n"
        "pxor %xmm4, %xmm4\n"
        "movss -0x98(%ebp), %xmm3\n" /* weightScale */
        "jmp .Lf3aef0_0003b1f3\n"
        ".Lf3aef0_0003b318:\n"
        "cmpb $0, -0x69(%ebp)\n" /* line 2788 */
        "je .Lf3aef0_0003b3f2\n"
        "movl 0xc(%ebp), %ecx\n" /* line 126 | rotPos */
        "movss (%ecx), %xmm2\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "ucomiss %xmm4, %xmm2\n" /* line 2791 */
        "jp .Lf3aef0_0003b341\n"
        "je .Lf3aef0_0003b398\n"
        /* { scope 2 */
        ".Lf3aef0_0003b341:\n"
        "movss %xmm2, -0x1c(%ebp)\n" /* line 69 | y */
        "movl -0x1c(%ebp), %edx\n" /* line 71 | y */
        "sarl $1, %edx\n"
        "movl $0x5f3759df, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* i */
        "movss -0x20(%ebp), %xmm1\n" /* line 72 | i */
        "mulss lit4_002ed5d8, %xmm2\n" /* line 73 | 0.5f */
        "mulss %xmm1, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "movss lit4_002ed600, %xmm0\n" /* 1.5f */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* y */
        /* } scope */
        "mulss %xmm3, %xmm0\n" /* line 2792 | weightScale, scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 86 */
        "mulss (%ecx), %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "mulss 4(%ecx), %xmm0\n" /* line 87 */
        "movss %xmm0, 4(%ecx)\n"
        /* } scope */
        ".Lf3aef0_0003b398:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 2794 | rotPos, parts */
        "movss 8(%ebx), %xmm0\n" /* parts */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3aef0_0003b3ab\n"
        "je .Lf3aef0_0003af81\n"
        ".Lf3aef0_0003b3ab:\n"
        "movaps %xmm3, %xmm1\n" /* line 2796 | weightScale, scale */
        "divss %xmm0, %xmm1\n" /* scale */
        "movl %ebx, %eax\n" /* parts, result */
        "addl $0xc, %eax\n" /* result */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0xc(%ebx), %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "movss %xmm3, 8(%ebx)\n" /* line 2797 | weightScale, parts */
        "jmp .Lf3aef0_0003af81\n"
        ".Lf3aef0_0003b3e5:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2755 | rotPos */
        "movl %edx, -0x60(%ebp)\n" /* rotPos2 */
        "movl %edx, %ecx\n"
        "jmp .Lf3aef0_0003b16b\n"
        ".Lf3aef0_0003b3f2:\n"
        "movl -0x60(%ebp), %eax\n" /* line 126 | rotPos2 */
        "movss (%eax), %xmm2\n"
        "movss 4(%eax), %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "ucomiss %xmm4, %xmm2\n" /* line 2803 */
        "jp .Lf3aef0_0003b411\n"
        "je .Lf3aef0_0003b47a\n"
        /* { scope 2 */
        ".Lf3aef0_0003b411:\n"
        "movss %xmm2, -0x20(%ebp)\n" /* line 69 | i */
        "movl -0x20(%ebp), %edx\n" /* line 71 | i */
        "sarl $1, %edx\n"
        "movl $0x5f3759df, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* y */
        "movss -0x1c(%ebp), %xmm1\n" /* line 72 | y */
        "mulss lit4_002ed5d8, %xmm2\n" /* line 73 | 0.5f */
        "mulss %xmm1, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "movss lit4_002ed600, %xmm0\n" /* 1.5f */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* i */
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 2804 | weightScale, scale */
        "mulss %xmm0, %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 100 */
        "movl -0x60(%ebp), %edx\n" /* rotPos2 */
        "mulss (%edx), %xmm0\n"
        "movl 0xc(%ebp), %ecx\n" /* rotPos */
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "mulss 4(%edx), %xmm1\n" /* line 101 */
        "addss 4(%ecx), %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        /* } scope */
        ".Lf3aef0_0003b47a:\n"
        "movl -0x60(%ebp), %ebx\n" /* line 2806 | rotPos2, parts */
        "movss 8(%ebx), %xmm0\n" /* parts */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3aef0_0003b48d\n"
        "je .Lf3aef0_0003af81\n"
        ".Lf3aef0_0003b48d:\n"
        "movaps %xmm3, %xmm1\n" /* line 2808 | weightScale, scale */
        "divss %xmm0, %xmm1\n" /* scale */
        "movl 0xc(%ebp), %eax\n" /* rotPos, result */
        "addl $0xc, %eax\n" /* result */
        "movl %ebx, %edx\n" /* parts, dir */
        "addl $0xc, %edx\n" /* dir */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0xc(%ebx), %xmm0\n"
        "movl 0xc(%ebp), %ecx\n" /* rotPos */
        "addss 0xc(%ecx), %xmm0\n"
        "movss %xmm0, 0xc(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%edx), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%edx), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "addss 8(%ecx), %xmm3\n" /* line 2809 | weightScale */
        "movss %xmm3, 8(%ecx)\n" /* weightScale */
        "jmp .Lf3aef0_0003af81\n"
    );
}

/* line 3392 */
__attribute__((naked))
void XAnimCalcAbsDelta(XAnimTree *tree, unsigned int animIndex, vec_t *rot, vec_t *trans)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3392 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* tree */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        "movl 0x10(%ebp), %esi\n" /* rot */
        "movl 0x14(%ebp), %ebx\n" /* trans */
        /* { scope 1 */
        "movb $1, 6(%eax)\n" /* line 3402 */
        "movb $1, 7(%eax)\n" /* line 3403 */
        "leal -0x20(%ebp), %ecx\n" /* line 3404 | rotPos */
        "movl %ecx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $1, %ecx\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "calll XAnimCalcDeltaTree\n"
        "pxor %xmm0, %xmm0\n" /* line 3407 */
        "ucomiss -0x20(%ebp), %xmm0\n" /* rotPos */
        "jne .Lf3b4e4_0003b534\n"
        "jp .Lf3b4e4_0003b534\n"
        "ucomiss -0x1c(%ebp), %xmm0\n"
        "jp .Lf3b4e4_0003b534\n"
        "je .Lf3b4e4_0003b557\n"
        ".Lf3b4e4_0003b534:\n"
        "movl -0x20(%ebp), %eax\n" /* line 37 | rotPos */
        "movl %eax, (%esi)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 38 */
        "movl %eax, 4(%esi)\n"
        "movl -0x14(%ebp), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 3420 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3b4e4_0003b557:\n"
        "movl $0, (%esi)\n" /* line 3413 | rot */
        "movl $0x3f800000, 4(%esi)\n" /* line 3414 | rot */
        "movl -0x14(%ebp), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 3420 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3356 */
__attribute__((naked))
void XAnimCalcDelta(XAnimTree *tree, unsigned int animIndex, vec_t *rot, vec_t *trans, int bUseGoalWeight)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3356 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* tree */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        "movl 0x10(%ebp), %esi\n" /* rot */
        "movl 0x14(%ebp), %ebx\n" /* trans */
        /* { scope 1 */
        "movb $0, 6(%eax)\n" /* line 3366 */
        "movl 0x18(%ebp), %ecx\n" /* line 3367 | bUseGoalWeight */
        "movb %cl, 7(%eax)\n"
        "leal -0x20(%ebp), %ecx\n" /* line 3368 | rotPos */
        "movl %ecx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $1, %ecx\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "calll XAnimCalcDeltaTree\n"
        "pxor %xmm0, %xmm0\n" /* line 3371 */
        "ucomiss -0x20(%ebp), %xmm0\n" /* rotPos */
        "jp .Lf3b57c_0003b5c6\n"
        "je .Lf3b57c_0003b5ce\n"
        ".Lf3b57c_0003b5c6:\n"
        "ucomiss -0x1c(%ebp), %xmm0\n"
        "jp .Lf3b57c_0003b5f3\n"
        "jne .Lf3b57c_0003b5f3\n"
        ".Lf3b57c_0003b5ce:\n"
        "movl $0, (%esi)\n" /* line 3377 | rot */
        "movl $0x3f800000, 4(%esi)\n" /* line 3378 | rot */
        "movl -0x14(%ebp), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 3384 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3b57c_0003b5f3:\n"
        "movl -0x20(%ebp), %eax\n" /* line 37 | rotPos */
        "movl %eax, (%esi)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 38 */
        "movl %eax, 4(%esi)\n"
        "movl -0x14(%ebp), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 3384 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1929 */
static __attribute__((naked))
void XAnimResetTime(XAnimTree *tree)
{
    __asm__ __volatile__ (
        ".Lf3b616_0003b616:\n"
        "pushl %ebp\n" /* line 1929 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x7c(%ebp)\n"
        /* { scope 1 */
        "movzwl 8(%eax, %edx, 2), %eax\n" /* line 1940 */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003bb4a\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 2: i, numAnims, anim */
        /* { scope 3 */
        "leal 0xc(%eax), %ecx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "je .Lf3b616_0003bb52\n"
        ".Lf3b616_0003b64e:\n"
        "movl $0, (%ecx)\n" /* line 1919 */
        "movw $0, 8(%ecx)\n" /* line 1920 */
        "movl $0, 4(%ecx)\n" /* line 1921 */
        "movw $0, 0xa(%ecx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003b66d:\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 1947 */
        "movl (%ecx), %eax\n"
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x70(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x74(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3b616_0003bb4a\n"
        "movl $0, -0x78(%ebp)\n" /* i */
        ".Lf3b616_0003b691:\n"
        "movl -0x70(%ebp), %ecx\n" /* line 1951 | anim, animIndex */
        "movzwl 6(%ecx), %eax\n"
        "movl -0x78(%ebp), %ecx\n" /* i, animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 2: i, numAnims, anim */
        /* { scope 3 */
        "movl -0x7c(%ebp), %edx\n" /* line 1940 | animIndex */
        "movzwl 8(%edx, %ecx, 2), %eax\n" /* animIndex */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003bb3a\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 4: i, numAnims, anim */
        /* { scope 5 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3b616_0003b6d1\n"
        "jp .Lf3b616_0003b6d1\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3b616_0003b6f0\n"
        ".Lf3b616_0003b6d1:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003b6f0:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1947 | animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x64(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x68(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3b616_0003bb3a\n"
        "movl $0, -0x6c(%ebp)\n" /* i */
        "movl -0x6c(%ebp), %ecx\n" /* i */
        ".Lf3b616_0003b717:\n"
        "movl -0x64(%ebp), %edx\n" /* line 1951 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 4: i, numAnims, anim */
        /* { scope 5 */
        "movl -0x7c(%ebp), %edx\n" /* line 1940 | animIndex */
        "movzwl 8(%edx, %ecx, 2), %eax\n" /* animIndex */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003bb2a\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 6: i, numAnims, anim */
        /* { scope 7 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3b616_0003b754\n"
        "jp .Lf3b616_0003b754\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3b616_0003b773\n"
        ".Lf3b616_0003b754:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003b773:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1947 | animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x58(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x5c(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3b616_0003bb2a\n"
        "movl $0, -0x60(%ebp)\n" /* i */
        "movl -0x60(%ebp), %ecx\n" /* i */
        ".Lf3b616_0003b79a:\n"
        "movl -0x58(%ebp), %edx\n" /* line 1951 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 6: i, numAnims, anim */
        /* { scope 7 */
        "movl -0x7c(%ebp), %edx\n" /* line 1940 | animIndex */
        "movzwl 8(%edx, %ecx, 2), %eax\n" /* animIndex */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003bb17\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 8: i, numAnims, anim */
        /* { scope 9 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3b616_0003b7d7\n"
        "jp .Lf3b616_0003b7d7\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3b616_0003b7f6\n"
        ".Lf3b616_0003b7d7:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003b7f6:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1947 | animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x50(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3b616_0003bb17\n"
        "movl $0, -0x54(%ebp)\n" /* i */
        "movl -0x54(%ebp), %ecx\n" /* i */
        ".Lf3b616_0003b81d:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 1951 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 8: i, numAnims, anim */
        /* { scope 9 */
        "movl -0x7c(%ebp), %edx\n" /* line 1940 | animIndex */
        "movzwl 8(%edx, %ecx, 2), %eax\n" /* animIndex */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003bb04\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 10: i, numAnims, anim */
        /* { scope 11 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3b616_0003b85a\n"
        "jp .Lf3b616_0003b85a\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3b616_0003b879\n"
        ".Lf3b616_0003b85a:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003b879:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1947 | animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x44(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3b616_0003bb04\n"
        "movl $0, -0x48(%ebp)\n" /* i */
        "movl -0x48(%ebp), %ecx\n" /* i */
        ".Lf3b616_0003b8a0:\n"
        "movl -0x40(%ebp), %edx\n" /* line 1951 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 10: i, numAnims, anim */
        /* { scope 11 */
        "movl -0x7c(%ebp), %edx\n" /* line 1940 | animIndex */
        "movzwl 8(%edx, %ecx, 2), %eax\n" /* animIndex */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003baf4\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 12: i, numAnims, anim */
        /* { scope 13 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3b616_0003b8dd\n"
        "jp .Lf3b616_0003b8dd\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3b616_0003b8fc\n"
        ".Lf3b616_0003b8dd:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003b8fc:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1947 | animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x38(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3b616_0003baf4\n"
        "movl $0, -0x3c(%ebp)\n" /* i */
        "movl -0x3c(%ebp), %ecx\n" /* i */
        ".Lf3b616_0003b923:\n"
        "movl -0x34(%ebp), %edx\n" /* line 1951 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 12: i, numAnims, anim */
        /* { scope 13 */
        "movl -0x7c(%ebp), %edx\n" /* line 1940 | animIndex */
        "movzwl 8(%edx, %ecx, 2), %eax\n" /* animIndex */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003bae1\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 14: i, numAnims, anim */
        /* { scope 15 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3b616_0003b960\n"
        "jp .Lf3b616_0003b960\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3b616_0003b97f\n"
        ".Lf3b616_0003b960:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003b97f:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1947 | animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x2c(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3b616_0003bae1\n"
        "movl $0, -0x30(%ebp)\n" /* i */
        "movl -0x30(%ebp), %ecx\n" /* i */
        ".Lf3b616_0003b9a6:\n"
        "movl -0x28(%ebp), %edx\n" /* line 1951 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 14: i, numAnims, anim */
        /* { scope 15 */
        "movl -0x7c(%ebp), %edx\n" /* line 1940 | animIndex */
        "movzwl 8(%edx, %ecx, 2), %eax\n" /* animIndex */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003bace\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 16 */
        /* { scope 17 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3b616_0003b9e3\n"
        "jp .Lf3b616_0003b9e3\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3b616_0003ba02\n"
        ".Lf3b616_0003b9e3:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003ba02:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1947 | animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x20(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3b616_0003bace\n"
        "movl $0, -0x24(%ebp)\n" /* i */
        "movl -0x24(%ebp), %ecx\n" /* i */
        "jmp .Lf3b616_0003ba3b\n"
        ".Lf3b616_0003ba2b:\n"
        "addl $1, -0x24(%ebp)\n" /* i */
        "movl -0x24(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x20(%ebp)\n" /* numAnims */
        "je .Lf3b616_0003bace\n"
        ".Lf3b616_0003ba3b:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1951 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 16 */
        /* { scope 17 */
        "movl -0x7c(%ebp), %edx\n" /* line 1940 | animIndex */
        "movzwl 8(%edx, %ecx, 2), %eax\n" /* animIndex */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3b616_0003ba2b\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 18 */
        /* { scope 19 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3b616_0003ba74\n"
        "jp .Lf3b616_0003ba74\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3b616_0003ba93\n"
        ".Lf3b616_0003ba74:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3b616_0003ba93:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1947 | animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edi\n" /* anim */
        "movzwl 0xc(%eax), %esi\n" /* line 1948 | numAnims */
        "testl %esi, %esi\n" /* line 1950 | numAnims */
        "jle .Lf3b616_0003ba2b\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3b616_0003baa8:\n"
        "movzwl 6(%edi), %edx\n" /* line 1951 | anim, animIndex */
        "leal (%ebx, %edx), %edx\n" /* i, animIndex */
        "movl -0x7c(%ebp), %eax\n"
        "calll XAnimResetTime\n"
        "addl $1, %ebx\n" /* line 1950 | i */
        "cmpl %ebx, %esi\n" /* i, numAnims */
        "jne .Lf3b616_0003baa8\n"
        /* } scope */
        /* } scope */
        "addl $1, -0x24(%ebp)\n" /* i */
        "movl -0x24(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x20(%ebp)\n" /* numAnims */
        "jne .Lf3b616_0003ba3b\n"
        /* } scope */
        /* } scope */
        ".Lf3b616_0003bace:\n"
        "addl $1, -0x30(%ebp)\n" /* i */
        "movl -0x30(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x2c(%ebp)\n" /* numAnims */
        "je .Lf3b616_0003bae1\n"
        "movl %eax, %ecx\n"
        "jmp .Lf3b616_0003b9a6\n"
        /* } scope */
        /* } scope */
        ".Lf3b616_0003bae1:\n"
        "addl $1, -0x3c(%ebp)\n" /* i */
        "movl -0x3c(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x38(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3b616_0003baf4\n"
        "movl %edx, %ecx\n" /* animIndex */
        "jmp .Lf3b616_0003b923\n"
        /* } scope */
        /* } scope */
        ".Lf3b616_0003baf4:\n"
        "addl $1, -0x48(%ebp)\n" /* i */
        "movl -0x48(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x44(%ebp)\n" /* numAnims */
        "jne .Lf3b616_0003b8a0\n"
        /* } scope */
        /* } scope */
        ".Lf3b616_0003bb04:\n"
        "addl $1, -0x54(%ebp)\n" /* i */
        "movl -0x54(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x50(%ebp)\n" /* numAnims */
        "je .Lf3b616_0003bb17\n"
        "movl %eax, %ecx\n"
        "jmp .Lf3b616_0003b81d\n"
        /* } scope */
        /* } scope */
        ".Lf3b616_0003bb17:\n"
        "addl $1, -0x60(%ebp)\n" /* i */
        "movl -0x60(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x5c(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3b616_0003bb2a\n"
        "movl %edx, %ecx\n" /* animIndex */
        "jmp .Lf3b616_0003b79a\n"
        /* } scope */
        /* } scope */
        ".Lf3b616_0003bb2a:\n"
        "addl $1, -0x6c(%ebp)\n" /* i */
        "movl -0x6c(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x68(%ebp)\n" /* numAnims */
        "jne .Lf3b616_0003b717\n"
        /* } scope */
        /* } scope */
        ".Lf3b616_0003bb3a:\n"
        "addl $1, -0x78(%ebp)\n" /* i */
        "movl -0x78(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x74(%ebp)\n" /* numAnims */
        "jne .Lf3b616_0003b691\n"
        /* } scope */
        ".Lf3b616_0003bb4a:\n"
        "addl $0x7c, %esp\n" /* line 1952 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: i, numAnims, anim */
        /* { scope 3 */
        ".Lf3b616_0003bb52:\n"
        "jp .Lf3b616_0003b64e\n" /* line 1916 */
        "cmpw $0, 8(%ecx)\n"
        "je .Lf3b616_0003b66d\n"
        "jmp .Lf3b616_0003b64e\n"
    );
}

/* line 1955 */
static __attribute__((naked))
void XAnimUpdateOldTime(XAnimTree *tree, unsigned int animIndex, XAnimState *syncState, int parentHadWeight, Bool *infoExistsForParent, Bool *childHadWeightForParent)
{
    __asm__ __volatile__ (
        ".Lf3bb68_0003bb68:\n"
        "pushl %ebp\n" /* line 1955 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl %edx, -0x50(%ebp)\n" /* parentHadWeight */
        "movl %ecx, -0x54(%ebp)\n"
        "movaps %xmm0, %xmm4\n" /* dtime */
        "movzbl 8(%ebp), %edx\n" /* parentHadWeight */
        /* { scope 1 */
        "movl -0x50(%ebp), %ecx\n" /* line 1972 */
        "movzwl 8(%eax, %ecx, 2), %eax\n"
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 1973 */
        "je .Lf3bb68_0003bc74\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 1977 */
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* info */
        "movl %eax, %esi\n" /* line 1978 | state */
        "addl $0xc, %esi\n" /* state */
        "testb %dl, %dl\n" /* line 1980 */
        "jne .Lf3bb68_0003bd7d\n"
        ".Lf3bb68_0003bbb2:\n"
        "movb $0, -0x45(%ebp)\n"
        "xorl %ecx, %ecx\n"
        ".Lf3bb68_0003bbb8:\n"
        "testb %dl, %dl\n" /* line 1982 */
        "jne .Lf3bb68_0003bd07\n"
        ".Lf3bb68_0003bbc0:\n"
        "movl 0x10(%esi), %eax\n" /* line 1984 | state */
        "movl %eax, 0x14(%esi)\n" /* state */
        "movl $0, 0xc(%esi)\n" /* line 1985 | state */
        "cmpb $0, -0x45(%ebp)\n" /* line 1995 */
        "je .Lf3bb68_0003bd62\n"
        ".Lf3bb68_0003bbd7:\n"
        "movl $1, %eax\n"
        ".Lf3bb68_0003bbdc:\n"
        "movb %al, -0x19(%ebp)\n" /* infoExists */
        "movl -0x4c(%ebp), %ebx\n" /* line 1997 | i */
        "movl (%ebx), %eax\n" /* i */
        "movl -0x50(%ebp), %edx\n"
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %ebx\n" /* i */
        "movl %ebx, -0x38(%ebp)\n" /* i, anim */
        "movzwl 0xc(%eax), %edi\n" /* line 1998 | numAnims */
        "movzwl %di, %eax\n" /* numAnims */
        "movl %eax, -0x44(%ebp)\n" /* numAnims */
        "testw %di, %di\n" /* line 2000 | numAnims */
        "jne .Lf3bb68_0003bc7c\n"
        "movl 4(%ebx), %eax\n" /* line 2005 | i */
        "pxor %xmm0, %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "setne %al\n"
        "setp %dl\n"
        "orb %dl, %al\n"
        "movb %al, -0x1a(%ebp)\n" /* childHadWeight */
        ".Lf3bb68_0003bc15:\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 2018 | infoExists */
        "jne .Lf3bb68_0003bce4\n"
        ".Lf3bb68_0003bc1f:\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 1273 | info */
        "movzwl 4(%ebx), %eax\n"
        "testw %ax, %ax\n"
        "jne .Lf3bb68_0003beda\n"
        "movl %ebx, %eax\n"
        ".Lf3bb68_0003bc31:\n"
        "movw $0xffff, 2(%eax)\n" /* line 1278 */
        "movw $0, 8(%eax)\n" /* line 1290 */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movl -0x3c(%ebp), %edx\n" /* info */
        "movw %ax, 0xa(%edx)\n"
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0x40(%ebp), %ecx\n" /* infoIndex */
        "movw %cx, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, g_xAnimInfo+10\n" /* line 1298 */
        "movl -0x50(%ebp), %eax\n" /* line 2022 */
        "movl -0x4c(%ebp), %edx\n"
        "movw $0, 8(%edx, %eax, 2)\n"
        /* } scope */
        ".Lf3bb68_0003bc74:\n"
        "addl $0x6c, %esp\n" /* line 2053 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3bb68_0003bc7c:\n"
        "movb $0, -0x1a(%ebp)\n" /* line 2009 | childHadWeight */
        "testb $4, 4(%ebx)\n" /* line 2011 | i */
        "movl -0x54(%ebp), %ebx\n" /* i */
        "cmovnel %esi, %ebx\n" /* state, i */
        "movl %ebx, -0x54(%ebp)\n" /* i */
        "movl -0x44(%ebp), %ebx\n" /* line 2014 | numAnims, i */
        "testl %ebx, %ebx\n" /* i */
        "jle .Lf3bb68_0003bc15\n"
        "movzbl %cl, %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3bb68_0003bc9c:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2015 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "leal -0x1a(%ebp), %ecx\n" /* childHadWeight */
        "movl %ecx, 8(%esp)\n"
        "leal -0x19(%ebp), %eax\n" /* infoExists */
        "movl %eax, 4(%esp)\n"
        "movl -0x30(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "movaps %xmm4, %xmm0\n" /* dtime */
        "movl -0x54(%ebp), %ecx\n"
        "movl -0x4c(%ebp), %eax\n"
        "movss %xmm4, -0x68(%ebp)\n" /* dtime */
        "calll XAnimUpdateOldTime\n"
        "addl $1, %ebx\n" /* line 2014 | i */
        "cmpl %ebx, -0x44(%ebp)\n" /* i, numAnims */
        "movss -0x68(%ebp), %xmm4\n" /* dtime */
        "jne .Lf3bb68_0003bc9c\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 2018 | infoExists */
        "je .Lf3bb68_0003bc1f\n"
        ".Lf3bb68_0003bce4:\n"
        "cmpb $0, -0x45(%ebp)\n" /* line 2026 */
        "je .Lf3bb68_0003bd9b\n"
        "cmpb $0, -0x1a(%ebp)\n" /* childHadWeight */
        "je .Lf3bb68_0003bd9b\n"
        "movl 0x10(%ebp), %edx\n" /* line 2046 | childHadWeightForParent */
        "movb $1, (%edx)\n"
        ".Lf3bb68_0003bcfe:\n"
        "movzwl 8(%esi), %edx\n" /* state */
        "jmp .Lf3bb68_0003bdd4\n"
        ".Lf3bb68_0003bd07:\n"
        "movss 0xc(%esi), %xmm2\n" /* line 1982 | state */
        "ucomiss %xmm2, %xmm4\n" /* dtime */
        "jae .Lf3bb68_0003bbc0\n"
        "movss 0x14(%esi), %xmm1\n" /* line 1989 | state */
        "movss 0x10(%esi), %xmm3\n" /* state */
        "movaps %xmm3, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm4, %xmm0\n" /* dtime */
        "divss %xmm2, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x14(%esi)\n" /* state */
        "ucomiss lit4_002ed66c, %xmm0\n" /* line 1990 | 1.0000001111620804e-06f */
        "jae .Lf3bb68_0003bd4f\n"
        "jp .Lf3bb68_0003bd4f\n"
        "mulss lit4_002ed658, %xmm3\n" /* line 1991 | 0.0010000000474974513f */
        "movss %xmm3, 0x14(%esi)\n" /* state */
        ".Lf3bb68_0003bd4f:\n"
        "subss %xmm4, %xmm2\n" /* line 1992 | dtime */
        "movss %xmm2, 0xc(%esi)\n" /* state */
        "cmpb $0, -0x45(%ebp)\n" /* line 1995 */
        "jne .Lf3bb68_0003bbd7\n"
        ".Lf3bb68_0003bd62:\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss 0x10(%esi), %xmm0\n" /* state */
        "jne .Lf3bb68_0003bbd7\n"
        "jp .Lf3bb68_0003bbd7\n"
        "xorl %eax, %eax\n"
        "jmp .Lf3bb68_0003bbdc\n"
        ".Lf3bb68_0003bd7d:\n"
        "pxor %xmm0, %xmm0\n" /* line 1980 */
        "ucomiss 0x14(%esi), %xmm0\n" /* state */
        "jp .Lf3bb68_0003bd8d\n"
        "je .Lf3bb68_0003bbb2\n"
        ".Lf3bb68_0003bd8d:\n"
        "movb $1, -0x45(%ebp)\n"
        "movl $1, %ecx\n"
        "jmp .Lf3bb68_0003bbb8\n"
        ".Lf3bb68_0003bd9b:\n"
        "testw %di, %di\n" /* line 2028 | numAnims */
        "jne .Lf3bb68_0003bdeb\n"
        ".Lf3bb68_0003bda0:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 2036 */
        "movss (%ecx), %xmm0\n"
        "ucomiss (%esi), %xmm0\n" /* state */
        "jne .Lf3bb68_0003bdb8\n"
        "jp .Lf3bb68_0003bdb8\n"
        "movzwl 8(%esi), %edx\n" /* state */
        "cmpw 8(%ecx), %dx\n"
        "je .Lf3bb68_0003bdd4\n"
        ".Lf3bb68_0003bdb8:\n"
        "movss %xmm0, (%esi)\n" /* line 2038 | state */
        "movl -0x54(%ebp), %ebx\n" /* line 2039 | i */
        "movzwl 8(%ebx), %eax\n" /* i */
        "movw %ax, 8(%esi)\n" /* state */
        "movl -0x3c(%ebp), %eax\n" /* line 2041 | info */
        "movw $0xffff, 2(%eax)\n"
        "movzwl 8(%esi), %edx\n" /* state */
        ".Lf3bb68_0003bdd4:\n"
        "movl (%esi), %eax\n" /* line 2049 | state */
        "movl %eax, 4(%esi)\n" /* state */
        "movw %dx, 0xa(%esi)\n" /* line 2050 | state */
        "movl 0xc(%ebp), %ecx\n" /* line 2052 | infoExistsForParent */
        "movb $1, (%ecx)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2053 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3bb68_0003bdeb:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 2028 | anim */
        "testb $4, 4(%ecx)\n"
        "je .Lf3bb68_0003bda0\n"
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss (%esi), %xmm0\n"
        "je .Lf3bb68_0003bef3\n"
        ".Lf3bb68_0003be01:\n"
        "movl $0, (%esi)\n" /* line 1919 */
        "movw $0, 8(%esi)\n" /* line 1920 */
        "movl $0, 4(%esi)\n" /* line 1921 */
        "movw $0, 0xa(%esi)\n" /* line 1922 */
        "movl -0x3c(%ebp), %ebx\n" /* line 1924 | info */
        "movw $0xffff, 2(%ebx)\n"
        "movl -0x44(%ebp), %ecx\n" /* line 2032 | numAnims */
        "testl %ecx, %ecx\n"
        "jle .Lf3bb68_0003bcfe\n"
        "movl $0, -0x2c(%ebp)\n" /* line 2030 */
        "movl -0x2c(%ebp), %ecx\n"
        "jmp .Lf3bb68_0003be4c\n"
        ".Lf3bb68_0003be3a:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 2032 */
        "movl -0x2c(%ebp), %edx\n"
        "cmpl %edx, -0x44(%ebp)\n" /* numAnims */
        "je .Lf3bb68_0003bcfe\n"
        "movl %edx, %ecx\n"
        ".Lf3bb68_0003be4c:\n"
        "movl -0x38(%ebp), %ebx\n" /* line 2033 | anim, i */
        "movzwl 6(%ebx), %eax\n" /* i */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 2: anim */
        /* { scope 3 */
        "movl -0x4c(%ebp), %edx\n" /* line 1940 */
        "movzwl 8(%edx, %ecx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3bb68_0003be3a\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 4 */
        /* { scope 5 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3bb68_0003be85\n"
        "jp .Lf3bb68_0003be85\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3bb68_0003bea4\n"
        ".Lf3bb68_0003be85:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3bb68_0003bea4:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 1947 */
        "movl (%edx), %eax\n"
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %edi\n" /* line 1948 | numAnims */
        "testl %edi, %edi\n" /* line 1950 | numAnims */
        "jle .Lf3bb68_0003be3a\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3bb68_0003bebc:\n"
        "movl -0x34(%ebp), %eax\n" /* line 1951 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "movl -0x4c(%ebp), %eax\n"
        "calll XAnimResetTime\n"
        "addl $1, %ebx\n" /* line 1950 | i */
        "cmpl %ebx, %edi\n" /* i, numAnims */
        "jne .Lf3bb68_0003bebc\n"
        "jmp .Lf3bb68_0003be3a\n"
        /* } scope */
        /* } scope */
        ".Lf3bb68_0003beda:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "movl -0x3c(%ebp), %eax\n" /* info */
        "jmp .Lf3bb68_0003bc31\n"
        ".Lf3bb68_0003bef3:\n"
        "jp .Lf3bb68_0003be01\n" /* line 1916 */
        "cmpw $0, 8(%esi)\n"
        "jne .Lf3bb68_0003be01\n"
        "xorl %edx, %edx\n"
        "jmp .Lf3bb68_0003bdd4\n"
    );
}

/* line 3081 */
__attribute__((naked))
void DObjInitServerTime(DObj *obj, float dtime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3081 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* obj */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 3091 | obj */
        "testl %eax, %eax\n"
        "je .Lf3bf0c_0003bf4f\n"
        "movl $0, -0x28(%ebp)\n" /* line 3097 | syncState */
        "movw $0, -0x20(%ebp)\n" /* line 3098 */
        "leal -0x28(%ebp), %ecx\n" /* line 3100 | syncState */
        "leal -0xa(%ebp), %eax\n" /* childHadWeight */
        "movl %eax, 8(%esp)\n"
        "leal -9(%ebp), %eax\n" /* infoExists */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* dtime */
        "xorl %edx, %edx\n"
        "movl (%ebx), %eax\n" /* obj */
        "calll XAnimUpdateOldTime\n"
        /* } scope */
        ".Lf3bf0c_0003bf4f:\n"
        "addl $0x34, %esp\n" /* line 3103 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3910 */
static __attribute__((naked))
int XAnimSetGoalWeightInternal(XAnimTree *tree, unsigned int animIndex, float rate, unsigned int notifyName, unsigned int notifyType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3910 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movaps %xmm0, %xmm4\n" /* goalWeight */
        "movaps %xmm1, %xmm3\n" /* goalTime */
        "movss %xmm2, -0x30(%ebp)\n"
        /* { scope 1: bestWeight */
        "movzwl 8(%eax, %edx, 2), %eax\n" /* line 3925 */
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 3926 */
        "jne .Lf3bf56_0003c110\n"
        "pxor %xmm1, %xmm1\n" /* line 3928 */
        "ucomiss %xmm1, %xmm0\n"
        "je .Lf3bf56_0003c17d\n"
        /* { scope 2 */
        ".Lf3bf56_0003bf8e:\n"
        "movzwl g_xAnimInfo+10, %ecx\n" /* line 3547 */
        "testw %cx, %cx\n" /* line 3548 */
        "je .Lf3bf56_0003c24a\n"
        "movzwl %cx, %edx\n" /* line 3570 */
        "leal (%edx, %edx, 4), %edx\n"
        "shll $3, %edx\n"
        "movzwl g_xAnimInfo+10(%edx), %eax\n"
        "movw %ax, g_xAnimInfo+10\n" /* line 3571 */
        "leal (%eax, %eax, 4), %eax\n" /* line 3573 */
        "movw $0, g_xAnimInfo+8(, %eax, 8)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 3580 */
        "movl -0x28(%ebp), %ebx\n"
        "movw %cx, 8(%ebx, %eax, 2)\n"
        "leal g_xAnimInfo(%edx), %ebx\n" /* line 3582 */
        /* } scope */
        ".Lf3bf56_0003bfd2:\n"
        "leal 0xc(%ebx), %edx\n" /* line 1846 */
        "cld\n"
        "movl $7, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movw $0, 4(%ebx)\n" /* line 1847 */
        "movw $0xffff, 2(%ebx)\n" /* line 1848 */
        "movw $0, (%ebx)\n" /* line 1849 */
        "movw $0, 6(%ebx)\n" /* line 1850 */
        "movl -0x2c(%ebp), %edi\n" /* line 3942 | i */
        "testl %edi, %edi\n" /* i */
        "je .Lf3bf56_0003c13f\n"
        ".Lf3bf56_0003c003:\n"
        "ucomiss %xmm1, %xmm3\n" /* line 3952 | goalTime */
        "jne .Lf3bf56_0003c158\n"
        ".Lf3bf56_0003c00c:\n"
        "jp .Lf3bf56_0003c158\n"
        "movss %xmm4, 0x14(%edx)\n" /* line 3953 | goalWeight */
        ".Lf3bf56_0003c017:\n"
        "ucomiss %xmm1, %xmm4\n" /* line 3957 | goalWeight */
        "jp .Lf3bf56_0003c022\n"
        "je .Lf3bf56_0003c1a3\n"
        ".Lf3bf56_0003c022:\n"
        "movss 0x14(%edx), %xmm1\n" /* line 3959 */
        "ucomiss %xmm1, %xmm4\n" /* goalWeight */
        "jb .Lf3bf56_0003c1ef\n"
        "movaps %xmm4, %xmm0\n" /* line 3960 | goalWeight */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n" /* goalTime */
        "divss %xmm4, %xmm3\n" /* goalWeight, goalTime */
        "movss %xmm3, 0xc(%edx)\n" /* goalTime */
        ".Lf3bf56_0003c044:\n"
        "movss %xmm4, 0x10(%edx)\n" /* line 3977 | goalWeight */
        "movss -0x30(%ebp), %xmm0\n" /* line 3979 */
        "movss %xmm0, 0x24(%ebx)\n" /* info */
        "movl 8(%ebp), %eax\n" /* line 3981 | notifyName */
        "movw %ax, 4(%ebx)\n" /* info */
        "movl 8(%ebp), %esi\n" /* line 3982 | notifyName, anim */
        "testl %esi, %esi\n" /* anim */
        "jne .Lf3bf56_0003c1df\n"
        ".Lf3bf56_0003c065:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 3987 | bForce */
        "movl (%ecx), %eax\n" /* bForce */
        "movl -0x2c(%ebp), %edx\n"
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %esi\n" /* anim */
        "movl 8(%ebp), %ecx\n" /* line 3988 | notifyName, bForce */
        "testl %ecx, %ecx\n" /* bForce */
        "je .Lf3bf56_0003c195\n"
        "cmpw $0, 0xc(%eax)\n"
        "je .Lf3bf56_0003c195\n"
        "testb $3, 4(%esi)\n" /* anim */
        "je .Lf3bf56_0003c195\n"
        /* { scope 2 */
        "movzwl 0xc(%eax), %eax\n" /* line 3880 */
        "testw %ax, %ax\n"
        "je .Lf3bf56_0003c232\n"
        "testw %ax, %ax\n" /* line 3891 */
        "je .Lf3bf56_0003c234\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* bestWeight */
        "xorl %edi, %edi\n" /* i */
        "movl $0, -0x20(%ebp)\n"
        "jmp .Lf3bf56_0003c0cb\n"
        ".Lf3bf56_0003c0bd:\n"
        "addl $1, %edi\n" /* i */
        "movzwl (%esi), %eax\n"
        "cmpl %eax, %edi\n" /* i */
        "jge .Lf3bf56_0003c27d\n"
        ".Lf3bf56_0003c0cb:\n"
        "movzwl 6(%esi), %eax\n" /* line 3895 */
        "leal (%edi, %eax), %edx\n" /* i */
        "movl -0x28(%ebp), %ecx\n"
        "movzwl 8(%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 3896 | bestWeight */
        "ucomiss -0x1c(%ebp), %xmm0\n"
        "jae .Lf3bf56_0003c0bd\n"
        "movl %ecx, %eax\n" /* line 3899 */
        "calll XAnimGetDescendantWithGreatestWeight\n"
        "testl %eax, %eax\n" /* line 3900 */
        "je .Lf3bf56_0003c0bd\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 3901 */
        "movss %xmm0, -0x24(%ebp)\n" /* bestWeight */
        "movl %eax, -0x20(%ebp)\n"
        "jmp .Lf3bf56_0003c0bd\n"
        /* } scope */
        ".Lf3bf56_0003c110:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 3937 */
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* info */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3bf56_0003c208\n"
        ".Lf3bf56_0003c127:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        "pxor %xmm1, %xmm1\n"
        "leal 0xc(%ebx), %edx\n"
        "movl -0x2c(%ebp), %edi\n" /* line 3942 | i */
        "testl %edi, %edi\n" /* i */
        "jne .Lf3bf56_0003c003\n"
        ".Lf3bf56_0003c13f:\n"
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f, goalWeight */
        "movaps %xmm1, %xmm3\n" /* goalTime */
        "movss %xmm4, -0x30(%ebp)\n" /* goalWeight */
        "ucomiss %xmm1, %xmm3\n" /* line 3952 | goalTime */
        "je .Lf3bf56_0003c00c\n"
        ".Lf3bf56_0003c158:\n"
        "ucomiss 0x14(%edx), %xmm1\n" /* line 3954 */
        "jne .Lf3bf56_0003c017\n"
        "jp .Lf3bf56_0003c017\n"
        "movaps %xmm4, %xmm0\n" /* line 3955 | goalWeight */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0x14(%edx)\n"
        "jmp .Lf3bf56_0003c017\n"
        ".Lf3bf56_0003c17d:\n"
        "jp .Lf3bf56_0003bf8e\n" /* line 3928 */
        "testb %cl, %cl\n" /* bForce */
        "jne .Lf3bf56_0003bf8e\n"
        ".Lf3bf56_0003c18b:\n"
        "xorl %eax, %eax\n" /* line 4000 */
        /* } scope */
        ".Lf3bf56_0003c18d:\n"
        "addl $0x5c, %esp\n" /* line 4003 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bestWeight */
        ".Lf3bf56_0003c195:\n"
        "movw $0, (%ebx)\n" /* line 3997 | info */
        ".Lf3bf56_0003c19a:\n"
        "movl 0xc(%ebp), %eax\n" /* line 4000 | notifyType */
        "movw %ax, 6(%ebx)\n" /* info */
        "jmp .Lf3bf56_0003c18b\n"
        ".Lf3bf56_0003c1a3:\n"
        "ucomiss 0x10(%edx), %xmm1\n" /* line 3966 */
        "jp .Lf3bf56_0003c1b9\n"
        "jne .Lf3bf56_0003c1b9\n"
        "movss 0xc(%edx), %xmm0\n" /* line 3972 */
        "ucomiss %xmm3, %xmm0\n" /* goalTime */
        "jbe .Lf3bf56_0003c044\n"
        ".Lf3bf56_0003c1b9:\n"
        "movss %xmm3, 0xc(%edx)\n" /* line 3973 | goalTime */
        "movss %xmm4, 0x10(%edx)\n" /* line 3977 | goalWeight */
        "movss -0x30(%ebp), %xmm0\n" /* line 3979 */
        "movss %xmm0, 0x24(%ebx)\n" /* info */
        "movl 8(%ebp), %eax\n" /* line 3981 | notifyName */
        "movw %ax, 4(%ebx)\n" /* info */
        "movl 8(%ebp), %esi\n" /* line 3982 | notifyName, anim */
        "testl %esi, %esi\n" /* anim */
        "je .Lf3bf56_0003c065\n"
        ".Lf3bf56_0003c1df:\n"
        "movl 8(%ebp), %edx\n" /* line 3983 | notifyName */
        "movl %edx, (%esp)\n"
        "calll SL_AddRefToString\n"
        "jmp .Lf3bf56_0003c065\n"
        ".Lf3bf56_0003c1ef:\n"
        "movaps %xmm1, %xmm0\n" /* line 3962 */
        "subss %xmm4, %xmm0\n" /* goalWeight */
        "mulss %xmm0, %xmm3\n" /* goalTime */
        "divss %xmm1, %xmm3\n" /* goalTime */
        "movss %xmm3, 0xc(%edx)\n" /* goalTime */
        "jmp .Lf3bf56_0003c044\n"
        ".Lf3bf56_0003c208:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "movss -0x58(%ebp), %xmm4\n"
        "movss -0x48(%ebp), %xmm3\n"
        "jmp .Lf3bf56_0003c127\n"
        /* { scope 2 */
        ".Lf3bf56_0003c232:\n"
        "movl %edx, %eax\n" /* line 3880 */
        /* } scope */
        ".Lf3bf56_0003c234:\n"
        "movw %ax, (%ebx)\n" /* line 3991 | info */
        "testw %ax, %ax\n" /* line 3992 */
        "jne .Lf3bf56_0003c19a\n"
        "movl $2, %eax\n"
        "jmp .Lf3bf56_0003c18d\n"
        /* { scope 2 */
        ".Lf3bf56_0003c24a:\n"
        "movl $str_00217834, 4(%esp)\n" /* line 3554 */
        "movl $1, (%esp)\n"
        "movss %xmm3, -0x48(%ebp)\n"
        "movss %xmm4, -0x58(%ebp)\n"
        "calll Com_Error\n"
        "xorl %ebx, %ebx\n"
        "pxor %xmm1, %xmm1\n"
        "movss -0x48(%ebp), %xmm3\n"
        "movss -0x58(%ebp), %xmm4\n"
        "jmp .Lf3bf56_0003bfd2\n"
        /* } scope */
        /* { scope 2 */
        ".Lf3bf56_0003c27d:\n"
        "movl -0x20(%ebp), %eax\n" /* line 3891 */
        "jmp .Lf3bf56_0003c234\n"
    );
}

/* line 4317 */
__attribute__((naked))
void XAnimSetCompleteGoalWeight(XAnimTree *tree, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4317 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* tree */
        "movss 0x10(%ebp), %xmm0\n" /* goalWeight */
        /* { scope 1: numAnims, i */
        "movaps %xmm0, %xmm1\n" /* line 4324 */
        "cmpnltss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "andps %xmm1, %xmm0\n"
        "movl 0x20(%ebp), %eax\n" /* line 4327 | notifyType */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* notifyName */
        "movl %eax, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movss 0x18(%ebp), %xmm2\n" /* rate */
        "movss 0x14(%ebp), %xmm1\n" /* goalTime */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimSetGoalWeightInternal\n"
        "movl 0xc(%ebp), %eax\n" /* line 4330 | animIndex */
        "testl %eax, %eax\n"
        "je .Lf3c282_0003c328\n"
        "movl 0xc(%ebp), %ebx\n" /* animIndex, parentAnimIndex */
        ".Lf3c282_0003c2cf:\n"
        "movl (%edi), %edx\n" /* line 4332 | tree */
        "movzwl 0xe(%edx, %ebx, 8), %esi\n"
        "movzwl %si, %ebx\n" /* parentAnimIndex */
        "movzwl 8(%edi, %ebx, 2), %eax\n" /* line 4334 | tree */
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 4336 */
        "je .Lf3c282_0003c2f9\n"
        "leal (%edx, %edx, 4), %eax\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss g_xAnimInfo+28(, %eax, 8), %xmm0\n"
        "jne .Lf3c282_0003c323\n"
        "jp .Lf3c282_0003c323\n"
        ".Lf3c282_0003c2f9:\n"
        "movl $0, 4(%esp)\n" /* line 4338 */
        "movl $0, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movss 0x14(%ebp), %xmm1\n" /* goalTime */
        "movaps %xmm2, %xmm0\n"
        "movl %ebx, %edx\n" /* parentAnimIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimSetGoalWeightInternal\n"
        ".Lf3c282_0003c323:\n"
        "testw %si, %si\n" /* line 4330 */
        "jne .Lf3c282_0003c2cf\n"
        ".Lf3c282_0003c328:\n"
        "movl 0x24(%ebp), %eax\n" /* line 4341 | bRestart */
        "testl %eax, %eax\n"
        "je .Lf3c282_0003c387\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 4200 | animIndex */
        "testl %eax, %eax\n"
        "jne .Lf3c282_0003c38f\n"
        "movl (%edi), %edx\n"
        ".Lf3c282_0003c338:\n"
        "movl 0xc(%ebp), %eax\n" /* line 4224 | animIndex */
        "cmpw $0, 0xc(%edx, %eax, 8)\n"
        "jne .Lf3c282_0003c387\n"
        "movzwl 8(%edi, %eax, 2), %eax\n" /* line 4229 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 3: numAnims, anim */
        /* { scope 4 */
        "leal 0xc(%eax), %ecx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3c282_0003c368\n"
        "jp .Lf3c282_0003c368\n"
        "cmpw $0, 8(%ecx)\n"
        "je .Lf3c282_0003c387\n"
        ".Lf3c282_0003c368:\n"
        "movl $0, (%ecx)\n" /* line 1919 */
        "movw $0, 8(%ecx)\n" /* line 1920 */
        "movl $0, 4(%ecx)\n" /* line 1921 */
        "movw $0, 0xa(%ecx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3c282_0003c387:\n"
        "addl $0x2c, %esp\n" /* line 4345 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numAnims, i */
        /* { scope 2 */
        ".Lf3c282_0003c38f:\n"
        "movl (%edi), %edx\n" /* line 4205 */
        "movl 0xc(%ebp), %ecx\n" /* animIndex */
        ".Lf3c282_0003c394:\n"
        "movzwl 8(%edi, %ecx, 2), %eax\n" /* line 4204 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* i */
        "leal (%edx, %ecx, 8), %eax\n" /* line 4205 */
        "leal 0xc(%eax), %esi\n"
        "cmpw $0, 0xc(%eax)\n" /* line 4206 */
        "je .Lf3c282_0003c3b6\n"
        "testb $4, 4(%esi)\n" /* line 4208 */
        "jne .Lf3c282_0003c3c8\n"
        ".Lf3c282_0003c3b6:\n"
        "movzwl 0xe(%edx, %ecx, 8), %eax\n" /* line 4200 */
        "movzwl %ax, %ecx\n"
        "testw %ax, %ax\n"
        "jne .Lf3c282_0003c394\n"
        "jmp .Lf3c282_0003c338\n"
        /* { scope 3: numAnims, anim */
        /* { scope 4 */
        ".Lf3c282_0003c3c8:\n"
        "leal 0xc(%ebx), %eax\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%ebx), %xmm0\n"
        "je .Lf3c282_0003c4a6\n"
        ".Lf3c282_0003c3d9:\n"
        "movl $0, (%eax)\n" /* line 1919 */
        "movw $0, 8(%eax)\n" /* line 1920 */
        "movl $0, 4(%eax)\n" /* line 1921 */
        "movw $0, 0xa(%eax)\n" /* line 1922 */
        "movw $0xffff, 2(%ebx)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        "movzwl (%esi), %eax\n" /* line 4214 */
        "movl %eax, -0x28(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 4216 */
        "jle .Lf3c282_0003c387\n"
        "movl $0, -0x24(%ebp)\n" /* i */
        "jmp .Lf3c282_0003c41b\n"
        ".Lf3c282_0003c40b:\n"
        "addl $1, -0x24(%ebp)\n" /* i */
        "movl -0x24(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x28(%ebp)\n" /* numAnims */
        "je .Lf3c282_0003c387\n"
        ".Lf3c282_0003c41b:\n"
        "movzwl 6(%esi), %eax\n" /* line 4217 */
        "movl -0x24(%ebp), %ecx\n" /* i, animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 3: numAnims, anim */
        /* { scope 4 */
        "movzwl 8(%edi, %ecx, 2), %eax\n" /* line 1940 */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3c282_0003c40b\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 5 */
        /* { scope 6 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3c282_0003c451\n"
        "jp .Lf3c282_0003c451\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3c282_0003c470\n"
        ".Lf3c282_0003c451:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3c282_0003c470:\n"
        "movl (%edi), %eax\n" /* line 1947 */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x20(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3c282_0003c40b\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3c282_0003c488:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1951 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "movl %edi, %eax\n"
        "calll XAnimResetTime\n"
        "addl $1, %ebx\n" /* line 1950 | i */
        "cmpl %ebx, -0x20(%ebp)\n" /* i, numAnims */
        "jne .Lf3c282_0003c488\n"
        "jmp .Lf3c282_0003c40b\n"
        /* } scope */
        /* } scope */
        /* { scope 3: numAnims, anim */
        /* { scope 4 */
        ".Lf3c282_0003c4a6:\n"
        "jp .Lf3c282_0003c3d9\n" /* line 1916 */
        "cmpw $0, 8(%eax)\n"
        "je .Lf3c282_0003c387\n"
        "jmp .Lf3c282_0003c3d9\n"
    );
}

/* line 4357 */
__attribute__((naked))
void XAnimCloneAnimTree(const XAnimTree *from, XAnimTree *to)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4357 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edx\n" /* from */
        /* { scope 1 */
        "movl (%edx), %eax\n" /* line 4371 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* size */
        "testl %eax, %eax\n" /* line 4372 */
        "jle .Lf3c4bc_0003c63e\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* to */
        "movl $0, -0x24(%ebp)\n" /* i */
        "jmp .Lf3c4bc_0003c55a\n"
        ".Lf3c4bc_0003c4e7:\n"
        "movzwl 8(%edi), %eax\n" /* line 4377 */
        "movzwl %ax, %esi\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 4378 */
        "je .Lf3c4bc_0003c540\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 1287 */
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 2 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3c4bc_0003c667\n"
        ".Lf3c4bc_0003c50a:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movw %si, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %si, g_xAnimInfo+10\n" /* line 1298 */
        "movw $0, 8(%edi)\n" /* line 4381 */
        ".Lf3c4bc_0003c540:\n"
        "addl $1, -0x24(%ebp)\n" /* line 4372 | i */
        "addl $2, -0x1c(%ebp)\n"
        "addl $2, %edi\n"
        "movl -0x24(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x20(%ebp)\n" /* size */
        "je .Lf3c4bc_0003c63e\n"
        ".Lf3c4bc_0003c557:\n"
        "movl -0x1c(%ebp), %edx\n"
        ".Lf3c4bc_0003c55a:\n"
        "movzwl 8(%edx), %eax\n" /* line 4374 */
        "movzwl %ax, %esi\n" /* infoIndex */
        "testw %ax, %ax\n" /* line 4375 */
        "je .Lf3c4bc_0003c4e7\n"
        "movzwl 8(%edi), %eax\n" /* line 4386 */
        "testw %ax, %ax\n"
        "jne .Lf3c4bc_0003c646\n"
        /* { scope 2 */
        "movzwl g_xAnimInfo+10, %ecx\n" /* line 3547 */
        "testw %cx, %cx\n" /* line 3548 */
        "je .Lf3c4bc_0003c690\n"
        "movzwl %cx, %edx\n" /* line 3570 */
        "leal (%edx, %edx, 4), %edx\n"
        "shll $3, %edx\n"
        "movzwl g_xAnimInfo+10(%edx), %eax\n"
        "movw %ax, g_xAnimInfo+10\n" /* line 3571 */
        "leal (%eax, %eax, 4), %eax\n" /* line 3573 */
        "movw $0, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %cx, 8(%edi)\n" /* line 3580 */
        "leal g_xAnimInfo(%edx), %ebx\n" /* line 3582 | info */
        /* } scope */
        ".Lf3c4bc_0003c5b0:\n"
        "leal (%esi, %esi, 4), %edx\n" /* line 4350 */
        "shll $3, %edx\n"
        "movl g_xAnimInfo(%edx), %eax\n"
        "movl %eax, (%ebx)\n" /* info */
        "movl g_xAnimInfo+4(%edx), %eax\n"
        "movl %eax, 4(%ebx)\n" /* info */
        "movl g_xAnimInfo+8(%edx), %eax\n"
        "movl %eax, 8(%ebx)\n" /* info */
        "movl g_xAnimInfo+12(%edx), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* info */
        "movl g_xAnimInfo+16(%edx), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* info */
        "movl g_xAnimInfo+20(%edx), %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* info */
        "movl g_xAnimInfo+24(%edx), %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* info */
        "movl g_xAnimInfo+28(%edx), %eax\n"
        "movl %eax, 0x1c(%ebx)\n" /* info */
        "movl g_xAnimInfo+32(%edx), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* info */
        "movl g_xAnimInfo+36(%edx), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* info */
        "movzwl 4(%ebx), %eax\n" /* line 4352 | info */
        "testw %ax, %ax\n"
        "je .Lf3c4bc_0003c540\n"
        "movzwl %ax, %eax\n" /* line 4353 */
        "movl %eax, (%esp)\n"
        "calll SL_AddRefToString\n"
        "addl $1, -0x24(%ebp)\n" /* line 4372 | i */
        "addl $2, -0x1c(%ebp)\n"
        "addl $2, %edi\n"
        "movl -0x24(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x20(%ebp)\n" /* size */
        "jne .Lf3c4bc_0003c557\n"
        /* } scope */
        ".Lf3c4bc_0003c63e:\n"
        "addl $0x2c, %esp\n" /* line 4402 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3c4bc_0003c646:\n"
        "movzwl %ax, %eax\n" /* line 4393 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* info */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3c4bc_0003c67d\n"
        ".Lf3c4bc_0003c65c:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        "jmp .Lf3c4bc_0003c5b0\n"
        /* { scope 2 */
        ".Lf3c4bc_0003c667:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3c4bc_0003c50a\n"
        /* } scope */
        ".Lf3c4bc_0003c67d:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3c4bc_0003c65c\n"
        /* { scope 2 */
        ".Lf3c4bc_0003c690:\n"
        "movl $str_00217834, 4(%esp)\n" /* line 3554 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %ebx, %ebx\n" /* info */
        "jmp .Lf3c4bc_0003c5b0\n"
    );
}

/* line 502 */
__attribute__((naked))
void XAnimFreeTree(XAnimTree *tree, Free_t Free)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 502 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* tree */
        "movl %eax, -0x24(%ebp)\n" /* tree */
        "movl 0xc(%ebp), %edx\n" /* Free */
        "movl %edx, -0x28(%ebp)\n" /* Free */
        /* { scope 1: anim */
        "movl (%eax), %edx\n" /* line 509 */
        "movl 4(%edx), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* size */
        /* { scope 2 */
        "movzwl 8(%eax), %eax\n" /* line 3803 */
        "movzwl %ax, %edi\n"
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3c6ac_0003c739\n"
        "leal 0xc(%edx), %eax\n" /* line 3807 */
        "movl %eax, -0x1c(%ebp)\n" /* anim */
        "movzwl 0xc(%edx), %esi\n" /* line 3808 | numAnims */
        "testl %esi, %esi\n" /* line 3809 | numAnims */
        "jg .Lf3c6ac_0003c7ce\n"
        /* { scope 3 */
        "leal (%edi, %edi, 4), %eax\n" /* line 1287 */
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 4 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3c6ac_0003c7b8\n"
        ".Lf3c6ac_0003c6fe:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movw %di, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %di, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 3814 | tree */
        "movw $0, 8(%eax)\n"
        "movl (%eax), %edx\n"
        /* } scope */
        /* { scope 2 */
        ".Lf3c6ac_0003c739:\n"
        "movl 4(%edx), %edi\n" /* line 3829 | size */
        "movl -0x24(%ebp), %edx\n" /* line 3834 | tree */
        "leal 8(%edx, %edi, 2), %eax\n"
        "testl %edi, %edi\n" /* line 3836 | size */
        "jle .Lf3c6ac_0003c78d\n"
        "xorl %esi, %esi\n" /* i */
        "movl %eax, %ebx\n" /* i */
        "jmp .Lf3c6ac_0003c757\n"
        ".Lf3c6ac_0003c74d:\n"
        "addl $1, %esi\n" /* i */
        "addl $2, %ebx\n" /* i */
        "cmpl %esi, %edi\n" /* i, size */
        "je .Lf3c6ac_0003c78d\n"
        ".Lf3c6ac_0003c757:\n"
        "movzwl (%ebx), %edx\n" /* line 3838 | i */
        "testw %dx, %dx\n"
        "je .Lf3c6ac_0003c74d\n"
        "movl -0x24(%ebp), %ecx\n" /* line 3847 | tree */
        "movl (%ecx), %eax\n"
        "movl 0x10(%eax, %esi, 8), %eax\n"
        "movswl 0xe(%eax), %eax\n"
        "addl $0x10, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movzwl %dx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToStringOfLen\n"
        "movw $0, (%ebx)\n" /* line 3848 | i */
        "addl $1, %esi\n" /* line 3836 | i */
        "addl $2, %ebx\n" /* i */
        "cmpl %esi, %edi\n" /* i, size */
        "jne .Lf3c6ac_0003c757\n"
        /* } scope */
        ".Lf3c6ac_0003c78d:\n"
        "movl -0x28(%ebp), %eax\n" /* line 542 | Free */
        "testl %eax, %eax\n"
        "je .Lf3c6ac_0003c7b0\n"
        "movl -0x20(%ebp), %edx\n" /* line 546 | size */
        "leal 9(%edx, %edx, 4), %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* Free */
        "movl -0x24(%ebp), %ecx\n" /* tree */
        "movl %ecx, 8(%ebp)\n" /* tree */
        "movl -0x28(%ebp), %ecx\n" /* Free */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 547 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: anim */
        "jmpl *%ecx\n" /* line 546 */
        /* } scope */
        ".Lf3c6ac_0003c7b0:\n"
        "addl $0x2c, %esp\n" /* line 547 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf3c6ac_0003c7b8:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3c6ac_0003c6fe\n"
        /* } scope */
        /* } scope */
        ".Lf3c6ac_0003c7ce:\n"
        "xorl %ebx, %ebx\n" /* line 3809 | i */
        ".Lf3c6ac_0003c7d0:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 3810 | anim */
        "movzwl 6(%ecx), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "movl -0x24(%ebp), %eax\n" /* tree */
        "calll XAnimClearTreeWeights\n"
        "addl $1, %ebx\n" /* line 3809 | i */
        "cmpl %ebx, %esi\n" /* i, numAnims */
        "jne .Lf3c6ac_0003c7d0\n"
        /* { scope 3 */
        "leal (%edi, %edi, 4), %eax\n" /* line 1287 */
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 4 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3c6ac_0003c6fe\n"
        "jmp .Lf3c6ac_0003c7b8\n"
    );
}

/* line 3853 */
__attribute__((naked))
void XAnimClearTree(XAnimTree *tree)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3853 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 3803 | tree */
        "movzwl 8(%edx), %eax\n"
        "movzwl %ax, %edi\n"
        "testw %ax, %ax\n" /* line 3804 */
        "je .Lf3c802_0003c8e0\n"
        "movl (%edx), %eax\n" /* line 3807 */
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %esi\n" /* line 3808 | numAnims */
        "testl %esi, %esi\n" /* line 3809 | numAnims */
        "jg .Lf3c802_0003c8fa\n"
        /* { scope 2 */
        "leal (%edi, %edi, 4), %eax\n" /* line 1287 */
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 3 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3c802_0003c8e4\n"
        ".Lf3c802_0003c849:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        "movw $0, 8(%ebx)\n" /* line 1290 | info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1296 */
        "movw %ax, 0xa(%ebx)\n" /* info */
        "movzwl g_xAnimInfo+10, %eax\n" /* line 1297 */
        "leal (%eax, %eax, 4), %eax\n"
        "movw %di, g_xAnimInfo+8(, %eax, 8)\n"
        "movw %di, g_xAnimInfo+10\n" /* line 1298 */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3814 | tree */
        "movw $0, 8(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* tree */
        /* } scope */
        /* { scope 1 */
        ".Lf3c802_0003c885:\n"
        "movl (%ecx), %eax\n" /* line 3829 */
        "movl 4(%eax), %edi\n" /* size */
        "leal 8(%ecx, %edi, 2), %eax\n" /* line 3834 */
        "testl %edi, %edi\n" /* line 3836 | size */
        "jle .Lf3c802_0003c8d8\n"
        "xorl %esi, %esi\n" /* i */
        "movl %eax, %ebx\n" /* i */
        "jmp .Lf3c802_0003c8a2\n"
        ".Lf3c802_0003c898:\n"
        "addl $1, %esi\n" /* i */
        "addl $2, %ebx\n" /* i */
        "cmpl %esi, %edi\n" /* i, size */
        "je .Lf3c802_0003c8d8\n"
        ".Lf3c802_0003c8a2:\n"
        "movzwl (%ebx), %edx\n" /* line 3838 | i */
        "testw %dx, %dx\n"
        "je .Lf3c802_0003c898\n"
        "movl 8(%ebp), %ecx\n" /* line 3847 | tree */
        "movl (%ecx), %eax\n"
        "movl 0x10(%eax, %esi, 8), %eax\n"
        "movswl 0xe(%eax), %eax\n"
        "addl $0x10, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movzwl %dx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToStringOfLen\n"
        "movw $0, (%ebx)\n" /* line 3848 | i */
        "addl $1, %esi\n" /* line 3836 | i */
        "addl $2, %ebx\n" /* i */
        "cmpl %esi, %edi\n" /* i, size */
        "jne .Lf3c802_0003c8a2\n"
        /* } scope */
        ".Lf3c802_0003c8d8:\n"
        "addl $0x2c, %esp\n" /* line 3866 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf3c802_0003c8e0:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf3c802_0003c885\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf3c802_0003c8e4:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3c802_0003c849\n"
        /* } scope */
        /* } scope */
        ".Lf3c802_0003c8fa:\n"
        "xorl %ebx, %ebx\n" /* line 3809 | i */
        ".Lf3c802_0003c8fc:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 3810 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "movl 8(%ebp), %eax\n" /* tree */
        "calll XAnimClearTreeWeights\n"
        "addl $1, %ebx\n" /* line 3809 | i */
        "cmpl %ebx, %esi\n" /* i, numAnims */
        "jne .Lf3c802_0003c8fc\n"
        /* { scope 2 */
        "leal (%edi, %edi, 4), %eax\n" /* line 1287 */
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        /* { scope 3 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3c802_0003c849\n"
        "jmp .Lf3c802_0003c8e4\n"
    );
}

/* line 2372 */
static __attribute__((naked))
void XAnimCalc(const DObj *obj, unsigned int animIndex, float weightScale, XAnimPart (*rotTransArray)(), int bClear, int bNormQuat, XAnimCalcAnimInfo *info, int rotTransArrayIndex)
{
    __asm__ __volatile__ (
        ".Lf3c92e_0003c92e:\n"
        "pushl %ebp\n" /* line 2372 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x19c, %esp\n"
        "movl %eax, -0x16c(%ebp)\n"
        "movl %edx, -0x170(%ebp)\n"
        "movss %xmm0, -0x174(%ebp)\n"
        "movl %ecx, -0x178(%ebp)\n"
        "movzbl 8(%ebp), %eax\n" /* bClear */
        "movb %al, -0x179(%ebp)\n" /* bClear */
        "movzbl 0xc(%ebp), %edx\n" /* bNormQuat */
        "movb %dl, -0x17a(%ebp)\n" /* bNormQuat */
        /* { scope 1: numModels, models, ignorePartBits, animToModel, ... */
        "movl -0x16c(%ebp), %ecx\n" /* line 2389 */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x160(%ebp)\n" /* tree */
        "movl (%ecx), %edx\n" /* line 2394 */
        "movl -0x170(%ebp), %ebx\n" /* j */
        "leal (%edx, %ebx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x164(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 2395 */
        "movzwl %ax, %edi\n" /* numAnims */
        "testw %ax, %ax\n" /* line 2396 */
        "jne .Lf3c92e_0003ce4c\n"
        "cmpb $0, -0x179(%ebp)\n" /* line 2398 | bClear */
        "jne .Lf3c92e_0003cecc\n"
        ".Lf3c92e_0003c9a7:\n"
        "movl -0x16c(%ebp), %eax\n"
        ".Lf3c92e_0003c9ad:\n"
        "movl 0xc(%eax), %ecx\n" /* line 2404 */
        "movl 4(%edx), %eax\n"
        "leal (%ecx, %eax, 2), %edx\n"
        "movl -0x170(%ebp), %ebx\n" /* line 2405 | j */
        "addl %ebx, %ebx\n" /* j */
        "movl %ebx, -0x168(%ebp)\n" /* j */
        "cmpw $0, (%ecx, %ebx)\n"
        "jne .Lf3c92e_0003d18e\n"
        "movzbl (%edx), %eax\n" /* line 2407 */
        "movl -0x170(%ebp), %ecx\n"
        "movb %al, 1(%edx, %ecx)\n"
        "movl -0x16c(%ebp), %eax\n" /* line 2408 */
        "addl 0xc(%eax), %ebx\n" /* j */
        "movl %ebx, -0xc4(%ebp)\n" /* j */
        "movzbl 0x18(%eax), %edx\n"
        "movl %edx, -0x158(%ebp)\n" /* numModels */
        "addl $0x1c, %eax\n"
        "movl %eax, -0x154(%ebp)\n" /* models */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        "movl -0x164(%ebp), %ecx\n" /* line 624 | anim */
        "movl 4(%ecx), %eax\n"
        "movl 0x10(%eax), %ebx\n" /* line 627 */
        "movl %ebx, -0x140(%ebp)\n" /* partNames */
        "movswl 0xe(%eax), %eax\n" /* line 628 */
        "leal 0x10(%eax), %edx\n" /* line 631 */
        "movl %edx, -0x138(%ebp)\n" /* len */
        "xorl %edx, %edx\n"
        ".Lf3c92e_0003ca1f:\n"
        "movl $0, -0xb0(%ebp, %edx, 4)\n" /* line 635 */
        "addl $1, %edx\n" /* line 634 */
        "cmpl $4, %edx\n"
        "jne .Lf3c92e_0003ca1f\n"
        "movl %eax, %edi\n" /* line 637 */
        "subl $1, %edi\n"
        "js .Lf3c92e_0003ca51\n"
        "leal -0xa1(%eax, %ebp), %edx\n"
        "movl %edx, %eax\n"
        "subl %edi, %eax\n"
        "subl $1, %eax\n"
        ".Lf3c92e_0003ca47:\n"
        "movb $0x7f, (%edx)\n" /* line 638 */
        "subl $1, %edx\n"
        "cmpl %edx, %eax\n" /* line 637 */
        "jne .Lf3c92e_0003ca47\n"
        ".Lf3c92e_0003ca51:\n"
        "movl -0x158(%ebp), %eax\n" /* line 641 | numModels */
        "testl %eax, %eax\n"
        "jle .Lf3c92e_0003cb4a\n"
        "leal (%edi, %edi), %eax\n" /* line 655 */
        "movl -0x140(%ebp), %ecx\n" /* partNames */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x150(%ebp)\n"
        "movl $0, -0x134(%ebp)\n" /* j */
        "movl $0, -0x14c(%ebp)\n" /* boneIndex */
        "movl %eax, -0x184(%ebp)\n"
        "movl -0x134(%ebp), %ebx\n" /* j */
        ".Lf3c92e_0003ca90:\n"
        "movl -0x154(%ebp), %edx\n" /* line 643 | models */
        "movl (%edx, %ebx, 4), %eax\n"
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 645 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x13c(%ebp)\n" /* boneNames */
        "movswl (%edx), %edx\n" /* line 646 */
        "movl %edx, -0x144(%ebp)\n" /* numBones */
        "testl %edx, %edx\n" /* line 650 */
        "jle .Lf3c92e_0003cb31\n"
        "movl $0, -0x148(%ebp)\n" /* localBoneIndex */
        "movl -0x148(%ebp), %ecx\n" /* localBoneIndex */
        ".Lf3c92e_0003cac3:\n"
        "movl -0x13c(%ebp), %ebx\n" /* line 652 | boneNames */
        "movzwl (%ebx, %ecx, 2), %esi\n" /* name */
        "testl %edi, %edi\n" /* line 653 */
        "js .Lf3c92e_0003cb15\n"
        "movl -0x150(%ebp), %edx\n" /* line 655 */
        "movzwl (%edx), %eax\n"
        "cmpl %esi, %eax\n" /* name */
        "je .Lf3c92e_0003d3a8\n"
        "movl -0x184(%ebp), %edx\n" /* line 2372 */
        "addl -0x140(%ebp), %edx\n" /* partNames */
        "movl %edi, %ecx\n" /* part */
        "xorl %ebx, %ebx\n" /* modelPartIndex */
        ".Lf3c92e_0003caf2:\n"
        "subl $1, %ecx\n" /* line 653 */
        "cmpl %ebx, %edi\n"
        "je .Lf3c92e_0003cb15\n"
        "movzwl -2(%edx), %eax\n" /* line 655 */
        "addl $1, %ebx\n"
        "subl $2, %edx\n"
        "cmpl %esi, %eax\n" /* name */
        "jne .Lf3c92e_0003caf2\n"
        "cmpb $0x7f, -0xa0(%ebp, %ecx)\n" /* line 657 */
        "je .Lf3c92e_0003d3b8\n"
        ".Lf3c92e_0003cb15:\n"
        "addl $1, -0x148(%ebp)\n" /* line 650 | localBoneIndex */
        "addl $1, -0x14c(%ebp)\n" /* boneIndex */
        "movl -0x148(%ebp), %ecx\n" /* localBoneIndex */
        "cmpl %ecx, -0x144(%ebp)\n" /* numBones */
        "jne .Lf3c92e_0003cac3\n"
        ".Lf3c92e_0003cb31:\n"
        "addl $1, -0x134(%ebp)\n" /* line 641 | j */
        "movl -0x134(%ebp), %ebx\n" /* j */
        "cmpl %ebx, -0x158(%ebp)\n" /* numModels */
        "jne .Lf3c92e_0003ca90\n"
        ".Lf3c92e_0003cb4a:\n"
        "movl $0xb, 0xc(%esp)\n" /* line 667 */
        "movl -0x138(%ebp), %eax\n" /* len */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0xb0(%ebp), %edx\n" /* animToModel */
        "movl %edx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        /* } scope */
        /* } scope */
        "movl -0xc4(%ebp), %ecx\n" /* line 2408 */
        "movw %ax, (%ecx)\n"
        "movl -0x16c(%ebp), %ebx\n" /* j */
        "movl 0xc(%ebx), %ecx\n" /* j */
        ".Lf3c92e_0003cb84:\n"
        "movl -0x168(%ebp), %edx\n" /* line 2421 */
        "movzwl (%edx, %ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %esi\n" /* animToModel */
        "movl 0x10(%ebp), %edx\n" /* info */
        "movl %eax, %ecx\n"
        "xorl %ebx, %ebx\n" /* j */
        ".Lf3c92e_0003cb9f:\n"
        "movl 0x4010(%edx), %eax\n" /* line 2424 */
        "notl %eax\n"
        "andl (%ecx), %eax\n"
        "orl %eax, 0x4000(%edx)\n"
        "addl $1, %ebx\n" /* line 2423 | j */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $4, %ebx\n" /* j */
        "jne .Lf3c92e_0003cb9f\n"
        "movl -0x164(%ebp), %ecx\n" /* line 2426 | anim */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0x15c(%ebp)\n" /* parts */
        "movl -0x170(%ebp), %ebx\n" /* line 2429 | j */
        "movl -0x160(%ebp), %edx\n" /* tree */
        "movzwl 8(%edx, %ebx, 2), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+12(, %eax, 8), %xmm1\n"
        "ucomiss lit4_002ed5d0, %xmm1\n" /* line 2434 | 1.0f */
        "jp .Lf3c92e_0003cbf8\n"
        "je .Lf3c92e_0003cf8d\n"
        ".Lf3c92e_0003cbf8:\n"
        "movzwl (%ecx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3c92e_0003d397\n"
        "cmpw $0xff, %ax\n" /* line 2441 */
        "ja .Lf3c92e_0003d445\n"
        "movl 0x10(%ebp), %ebx\n" /* line 2442 | info, j */
        "addl $0x4010, %ebx\n" /* j */
        "movl %ebx, -0xf8(%ebp)\n" /* j, ignorePartBits */
        "addl $0x10, %esi\n" /* animToModel */
        "movl %esi, -0xf4(%ebp)\n" /* animToModel */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        "movzwl %ax, %eax\n" /* line 863 */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movss %xmm1, -0xb0(%ebp)\n" /* line 684 | animToModel */
        "movl %eax, -0xac(%ebp)\n" /* line 685 */
        "cvtsi2ssl %eax, %xmm0\n" /* line 686 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n"
        "cvttss2si %xmm0, %eax\n" /* line 687 */
        "movl %eax, -0xa4(%ebp)\n"
        /* } scope */
        "movss -0x174(%ebp), %xmm3\n" /* line 870 */
        "mulss lit4_002ed664, %xmm3\n" /* 3.0518509447574615e-05f */
        "movl -0x15c(%ebp), %eax\n" /* line 872 | parts */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0xe4(%ebp)\n" /* simpleQuatBits */
        "movl -0x15c(%ebp), %edx\n" /* line 873 | parts */
        "movswl 0xe(%edx), %edx\n"
        "movl %edx, -0xe8(%ebp)\n" /* size */
        "testl %edx, %edx\n" /* line 874 */
        "jle .Lf3c92e_0003cec1\n"
        "movl $0, -0xf0(%ebp)\n" /* animPartIndex */
        "jmp .Lf3c92e_0003cd71\n"
        ".Lf3c92e_0003cc97:\n"
        "movl -0xec(%ebp), %eax\n" /* line 889 | part */
        "movl 4(%eax), %ebx\n" /* to */
        "testl %ebx, %ebx\n" /* to */
        "je .Lf3c92e_0003dbca\n"
        "leal 8(%edi), %esi\n" /* line 890 | totalRotTrans, out */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movzwl (%ebx), %eax\n" /* line 792 */
        "testw %ax, %ax\n"
        "jne .Lf3c92e_0003daee\n"
        "movswl 4(%ebx), %eax\n" /* line 827 | to */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 8(%edi), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "movswl 6(%ebx), %eax\n" /* line 828 | to */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 4(%esi), %xmm0\n" /* out */
        "movss %xmm0, 4(%esi)\n" /* out */
        /* } scope */
        ".Lf3c92e_0003cce3:\n"
        "movl -0xec(%ebp), %edx\n" /* line 899 | part */
        "movl (%edx), %ebx\n" /* rotFrameDeltas */
        "testl %ebx, %ebx\n" /* rotFrameDeltas */
        "je .Lf3c92e_0003cd46\n"
        "leal 0x10(%edi), %esi\n" /* line 900 | totalRotTrans, out */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movzwl (%ebx), %eax\n" /* line 838 | to */
        "testw %ax, %ax\n"
        "jne .Lf3c92e_0003d740\n"
        "leal 4(%ebx), %eax\n" /* line 840 | to, dir */
        /* { scope 5 */
        "movss -0x174(%ebp), %xmm0\n" /* line 288 */
        "mulss 4(%ebx), %xmm0\n"
        "addss 0x10(%edi), %xmm0\n"
        "movss %xmm0, 0x10(%edi)\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 290 */
        "mulss 8(%eax), %xmm0\n"
        "addss 8(%esi), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003cd46:\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 902 */
        "addss 0x1c(%edi), %xmm0\n" /* totalRotTrans */
        "movss %xmm0, 0x1c(%edi)\n" /* totalRotTrans */
        ".Lf3c92e_0003cd58:\n"
        "addl $1, -0xf0(%ebp)\n" /* line 874 | animPartIndex */
        "movl -0xf0(%ebp), %edx\n" /* animPartIndex */
        "cmpl %edx, -0xe8(%ebp)\n" /* size */
        "je .Lf3c92e_0003cec1\n"
        ".Lf3c92e_0003cd71:\n"
        "movl -0xf0(%ebp), %ecx\n" /* line 876 | animPartIndex */
        "movl -0xf4(%ebp), %ebx\n" /* animToModel, to */
        "movzbl (%ecx, %ebx), %edx\n"
        "movl %edx, %eax\n" /* line 880 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl -0xf8(%ebp), %ebx\n" /* ignorePartBits, to */
        "movl (%ebx, %eax, 4), %eax\n" /* to */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003cd58\n"
        "shll $5, %edx\n" /* line 883 */
        "movl -0x178(%ebp), %edi\n" /* totalRotTrans */
        "addl %edx, %edi\n" /* totalRotTrans */
        "movl -0x15c(%ebp), %edx\n" /* line 885 | parts */
        "movl 0x18(%edx), %eax\n"
        "movl -0xf0(%ebp), %ecx\n" /* animPartIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "movl %eax, -0xec(%ebp)\n" /* part */
        "movl %ecx, %eax\n" /* line 887 */
        "sarl $3, %eax\n"
        "movl -0xe4(%ebp), %ebx\n" /* simpleQuatBits, to */
        "movsbl (%ebx, %eax), %eax\n" /* to */
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003cc97\n"
        "movl -0xec(%ebp), %edx\n" /* line 896 | part */
        "movl 4(%edx), %ebx\n" /* rotFrameDeltas */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 5 */
        "movzwl (%ebx), %eax\n" /* line 815 */
        "testw %ax, %ax\n"
        "jne .Lf3c92e_0003da0d\n"
        "leal 4(%ebx), %edx\n" /* line 817 | base */
        /* { scope 6 */
        "movswl 4(%ebx), %eax\n" /* line 837 | to */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movswl 2(%edx), %eax\n" /* line 838 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 4(%edi), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movswl 4(%edx), %eax\n" /* line 839 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 8(%edi), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "movswl 6(%edx), %eax\n" /* line 840 | dir */
        "cvtsi2ssl %eax, %xmm0\n" /* dir */
        "mulss %xmm3, %xmm0\n"
        "addss 0xc(%edi), %xmm0\n"
        "movss %xmm0, 0xc(%edi)\n"
        "jmp .Lf3c92e_0003cce3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003ce4c:\n"
        "testl %edi, %edi\n" /* line 2450 | numAnims */
        "jg .Lf3c92e_0003cf3b\n"
        ".Lf3c92e_0003ce54:\n"
        "cmpb $0, -0x179(%ebp)\n" /* line 2577 | bClear */
        "je .Lf3c92e_0003cec1\n"
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        "movl -0x16c(%ebp), %edx\n" /* line 994 */
        "cmpb $0, 0x19(%edx)\n"
        "je .Lf3c92e_0003cec1\n"
        "xorl %ebx, %ebx\n" /* modelPartIndex */
        ".Lf3c92e_0003ce6b:\n"
        "movl %ebx, %eax\n" /* line 996 | modelPartIndex */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n" /* modelPartIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* info */
        "movl 0x4010(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003cea9\n"
        "xorl %eax, %eax\n" /* line 438 */
        "movl -0x178(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl %eax, 4(%ecx)\n" /* line 439 */
        "movl %eax, 8(%ecx)\n" /* line 440 */
        "movl %eax, 0xc(%ecx)\n" /* line 441 */
        "movl %eax, 0x1c(%ecx)\n" /* line 1000 */
        "movl %ecx, %edx\n" /* line 1001 | v */
        "addl $0x10, %edx\n" /* v */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        "movl %eax, 0x10(%ecx)\n" /* line 183 */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        ".Lf3c92e_0003cea9:\n"
        "addl $1, %ebx\n" /* line 994 | modelPartIndex */
        "addl $0x20, -0x178(%ebp)\n"
        "movl -0x16c(%ebp), %edx\n"
        "movzbl 0x19(%edx), %eax\n"
        "cmpl %eax, %ebx\n" /* modelPartIndex */
        "jl .Lf3c92e_0003ce6b\n"
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003cec1:\n"
        "addl $0x19c, %esp\n" /* line 2579 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numModels, models, ignorePartBits, animToModel, ... */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        ".Lf3c92e_0003cecc:\n"
        "movl -0x16c(%ebp), %ecx\n" /* line 994 */
        "cmpb $0, 0x19(%ecx)\n"
        "je .Lf3c92e_0003d390\n"
        "movl -0x178(%ebp), %ebx\n" /* modelPartIndex */
        "xorl %esi, %esi\n" /* modelPartIndex */
        ".Lf3c92e_0003cee4:\n"
        "movl %esi, %eax\n" /* line 996 | modelPartIndex */
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n" /* modelPartIndex */
        "andl $0x1f, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* info */
        "movl 0x4010(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003cf1a\n"
        "xorl %eax, %eax\n" /* line 438 */
        "movl %eax, (%ebx)\n"
        "movl %eax, 4(%ebx)\n" /* line 439 */
        "movl %eax, 8(%ebx)\n" /* line 440 */
        "movl %eax, 0xc(%ebx)\n" /* line 441 */
        "movl %eax, 0x1c(%ebx)\n" /* line 1000 | modelPartIndex */
        "leal 0x10(%ebx), %edx\n" /* line 1001 | modelPartIndex, v */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        "movl %eax, 0x10(%ebx)\n" /* line 183 */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        ".Lf3c92e_0003cf1a:\n"
        "addl $1, %esi\n" /* line 994 | modelPartIndex */
        "addl $0x20, %ebx\n" /* modelPartIndex */
        "movl -0x16c(%ebp), %ecx\n"
        "movzbl 0x19(%ecx), %eax\n"
        "cmpl %esi, %eax\n" /* modelPartIndex */
        "jg .Lf3c92e_0003cee4\n"
        "movl -0x160(%ebp), %ebx\n" /* tree, modelPartIndex */
        "movl (%ebx), %edx\n" /* modelPartIndex */
        "jmp .Lf3c92e_0003c9a7\n"
        /* } scope */
        ".Lf3c92e_0003cf3b:\n"
        "movl -0x164(%ebp), %ecx\n" /* line 2454 | anim */
        "movzwl 6(%ecx), %esi\n" /* animToModel */
        "movl -0x160(%ebp), %eax\n" /* tree */
        "leal 8(%eax, %esi, 2), %ebx\n" /* j */
        "xorl %ecx, %ecx\n"
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003cf51:\n"
        "leal (%ecx, %esi), %edx\n" /* line 874 */
        /* } scope */
        /* } scope */
        "movzwl (%ebx), %eax\n" /* line 2454 | j */
        "testw %ax, %ax\n" /* line 2455 */
        "je .Lf3c92e_0003cf7e\n"
        "movzwl %ax, %eax\n" /* line 2459 */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+32(, %eax, 8), %xmm0\n"
        "pxor %xmm2, %xmm2\n" /* line 2461 */
        "ucomiss %xmm2, %xmm0\n"
        "jp .Lf3c92e_0003d7fe\n"
        "jne .Lf3c92e_0003d7fe\n"
        ".Lf3c92e_0003cf7e:\n"
        "addl $1, %ecx\n" /* line 2450 */
        "addl $2, %ebx\n" /* j */
        "cmpl %ecx, %edi\n" /* numAnims */
        "jne .Lf3c92e_0003cf51\n"
        "jmp .Lf3c92e_0003ce54\n"
        ".Lf3c92e_0003cf8d:\n"
        "movl %ecx, %ebx\n" /* j */
        "movl %ecx, %eax\n"
        ".Lf3c92e_0003cf91:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2437 | info */
        "addl $0x4010, %ecx\n"
        "movl %ecx, -0x108(%ebp)\n" /* ignorePartBits */
        "addl $0x10, %esi\n" /* animToModel */
        "movl %esi, -0x104(%ebp)\n" /* animToModel */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        "movss -0x174(%ebp), %xmm1\n" /* line 949 */
        "mulss lit4_002ed664, %xmm1\n" /* 3.0518509447574615e-05f */
        "movl 0x14(%ebx), %ebx\n" /* line 951 | totalRotTrans */
        "movl %ebx, -0xfc(%ebp)\n" /* totalRotTrans, simpleQuatBits */
        "movswl 0xe(%eax), %eax\n" /* line 952 */
        "movl %eax, -0x100(%ebp)\n" /* size */
        "testl %eax, %eax\n" /* line 953 */
        "jle .Lf3c92e_0003cec1\n"
        "xorl %esi, %esi\n" /* animPartIndex */
        "jmp .Lf3c92e_0003d09f\n"
        ".Lf3c92e_0003cfdb:\n"
        "movl 4(%edi), %eax\n" /* line 968 | part */
        "testl %eax, %eax\n"
        "je .Lf3c92e_0003d42e\n"
        "leal 8(%ebx), %ecx\n" /* line 970 | totalRotTrans */
        "movzwl (%eax), %edx\n" /* line 911 */
        "testw %dx, %dx\n"
        "jne .Lf3c92e_0003d382\n"
        "leal 4(%eax), %edx\n"
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003cff8:\n"
        "movswl (%edx), %eax\n" /* line 827 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movswl 2(%edx), %eax\n" /* line 828 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        /* } scope */
        ".Lf3c92e_0003d021:\n"
        "movl (%edi), %edx\n" /* line 982 | part */
        "testl %edx, %edx\n"
        "je .Lf3c92e_0003d07e\n"
        "leal 0x10(%ebx), %ecx\n" /* line 983 | totalRotTrans */
        "movzwl (%edx), %eax\n" /* line 931 */
        "testw %ax, %ax\n"
        "jne .Lf3c92e_0003d160\n"
        "leal 4(%edx), %eax\n"
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movss -0x174(%ebp), %xmm0\n" /* line 288 */
        "mulss 4(%edx), %xmm0\n"
        /* } scope */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d046:\n"
        "addss 0x10(%ebx), %xmm0\n"
        "movss %xmm0, 0x10(%ebx)\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 290 */
        "mulss 8(%eax), %xmm0\n"
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        /* } scope */
        ".Lf3c92e_0003d07e:\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 985 */
        "addss 0x1c(%ebx), %xmm0\n" /* totalRotTrans */
        "movss %xmm0, 0x1c(%ebx)\n" /* totalRotTrans */
        ".Lf3c92e_0003d090:\n"
        "addl $1, %esi\n" /* line 953 | animPartIndex */
        "cmpl %esi, -0x100(%ebp)\n" /* animPartIndex, size */
        "je .Lf3c92e_0003cec1\n"
        ".Lf3c92e_0003d09f:\n"
        "movl -0x104(%ebp), %ecx\n" /* line 955 | animToModel */
        "movzbl (%ecx, %esi), %edx\n"
        "movl %edx, %eax\n" /* line 959 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl -0x108(%ebp), %ebx\n" /* ignorePartBits, totalRotTrans */
        "movl (%ebx, %eax, 4), %eax\n" /* totalRotTrans */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003d090\n"
        "shll $5, %edx\n" /* line 962 */
        "movl -0x178(%ebp), %ebx\n" /* totalRotTrans */
        "addl %edx, %ebx\n" /* totalRotTrans */
        "movl -0x15c(%ebp), %edx\n" /* line 964 | parts */
        "movl 0x18(%edx), %eax\n"
        "leal (%eax, %esi, 8), %edi\n" /* part */
        "movl %esi, %eax\n" /* line 966 | animPartIndex */
        "sarl $3, %eax\n"
        "movl -0xfc(%ebp), %ecx\n" /* simpleQuatBits */
        "movsbl (%ecx, %eax), %eax\n"
        "movl %esi, %ecx\n" /* animPartIndex */
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003cfdb\n"
        "movl 4(%edi), %eax\n" /* line 979 | part, rotFrames */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movzwl (%eax), %edx\n" /* line 920 */
        "testw %dx, %dx\n"
        "jne .Lf3c92e_0003d17d\n"
        "leal 4(%eax), %edx\n" /* line 921 | base */
        /* { scope 5 */
        "movswl 4(%eax), %eax\n" /* line 837 */
        /* } scope */
        /* { scope 5 */
        ".Lf3c92e_0003d109:\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss (%ebx), %xmm0\n" /* to */
        "movss %xmm0, (%ebx)\n" /* to */
        "movswl 2(%edx), %eax\n" /* line 838 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 4(%ebx), %xmm0\n" /* to */
        "movss %xmm0, 4(%ebx)\n" /* to */
        "movswl 4(%edx), %eax\n" /* line 839 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 8(%ebx), %xmm0\n" /* to */
        "movss %xmm0, 8(%ebx)\n" /* to */
        "movswl 6(%edx), %eax\n" /* line 840 | dir */
        "cvtsi2ssl %eax, %xmm0\n" /* dir */
        "mulss %xmm1, %xmm0\n"
        "addss 0xc(%ebx), %xmm0\n" /* to */
        "movss %xmm0, 0xc(%ebx)\n" /* to */
        "jmp .Lf3c92e_0003d021\n"
        /* } scope */
        /* } scope */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d160:\n"
        "movzwl %ax, %eax\n" /* line 290 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 4(%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        /* } scope */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movss -0x174(%ebp), %xmm0\n" /* line 288 */
        "mulss (%eax), %xmm0\n"
        "jmp .Lf3c92e_0003d046\n"
        /* } scope */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 5 */
        ".Lf3c92e_0003d17d:\n"
        "movzwl %dx, %edx\n" /* line 840 */
        "movl 4(%eax), %eax\n" /* dir */
        "leal (%eax, %edx, 8), %edx\n"
        /* } scope */
        /* { scope 5 */
        "movswl (%edx), %eax\n" /* line 837 */
        "jmp .Lf3c92e_0003d109\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003d18e:\n"
        "movl -0x170(%ebp), %eax\n" /* line 2410 */
        "leal (%edx, %eax), %ebx\n" /* j */
        "movzbl (%edx), %eax\n"
        "cmpb %al, 1(%ebx)\n" /* j */
        "je .Lf3c92e_0003cb84\n"
        "movb %al, 1(%ebx)\n" /* line 2412 | j */
        "movl -0x164(%ebp), %edx\n" /* line 2413 | anim */
        "movl 4(%edx), %eax\n"
        "movswl 0xe(%eax), %eax\n"
        "addl $0x10, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x16c(%ebp), %ecx\n"
        "movl 0xc(%ecx), %eax\n"
        "movl -0x168(%ebp), %ebx\n" /* j */
        "movzwl (%ebx, %eax), %eax\n" /* j */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToStringOfLen\n"
        "movl -0x16c(%ebp), %eax\n" /* line 2414 */
        "addl 0xc(%eax), %ebx\n" /* j */
        "movl %ebx, -0xc8(%ebp)\n" /* j */
        "movzbl 0x18(%eax), %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* numModels */
        "addl $0x1c, %eax\n"
        "movl %eax, -0x12c(%ebp)\n" /* models */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        "movl -0x164(%ebp), %ecx\n" /* line 624 | anim */
        "movl 4(%ecx), %eax\n"
        "movl 0x10(%eax), %ebx\n" /* line 627 */
        "movl %ebx, -0x118(%ebp)\n" /* partNames */
        "movswl 0xe(%eax), %eax\n" /* line 628 */
        "leal 0x10(%eax), %edx\n" /* line 631 */
        "movl %edx, -0x110(%ebp)\n" /* len */
        "xorl %edx, %edx\n"
        ".Lf3c92e_0003d218:\n"
        "movl $0, -0xb0(%ebp, %edx, 4)\n" /* line 635 */
        "addl $1, %edx\n" /* line 634 */
        "cmpl $4, %edx\n"
        "jne .Lf3c92e_0003d218\n"
        "movl %eax, %edi\n" /* line 637 */
        "subl $1, %edi\n"
        "js .Lf3c92e_0003d24a\n"
        "leal -0xa1(%eax, %ebp), %edx\n"
        "movl %edx, %eax\n"
        "subl %edi, %eax\n"
        "subl $1, %eax\n"
        ".Lf3c92e_0003d240:\n"
        "movb $0x7f, (%edx)\n" /* line 638 */
        "subl $1, %edx\n"
        "cmpl %edx, %eax\n" /* line 637 */
        "jne .Lf3c92e_0003d240\n"
        ".Lf3c92e_0003d24a:\n"
        "movl -0x130(%ebp), %eax\n" /* line 641 | numModels */
        "testl %eax, %eax\n"
        "jle .Lf3c92e_0003d343\n"
        "leal (%edi, %edi), %eax\n" /* line 655 */
        "movl -0x118(%ebp), %ecx\n" /* partNames */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x128(%ebp)\n"
        "movl $0, -0x10c(%ebp)\n" /* j */
        "movl $0, -0x124(%ebp)\n" /* boneIndex */
        "movl %eax, -0x180(%ebp)\n"
        "movl -0x10c(%ebp), %ebx\n" /* j */
        ".Lf3c92e_0003d289:\n"
        "movl -0x12c(%ebp), %edx\n" /* line 643 | models */
        "movl (%edx, %ebx, 4), %eax\n"
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 645 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x114(%ebp)\n" /* boneNames */
        "movswl (%edx), %edx\n" /* line 646 */
        "movl %edx, -0x11c(%ebp)\n" /* numBones */
        "testl %edx, %edx\n" /* line 650 */
        "jle .Lf3c92e_0003d32a\n"
        "movl $0, -0x120(%ebp)\n" /* localBoneIndex */
        "movl -0x120(%ebp), %ecx\n" /* localBoneIndex */
        ".Lf3c92e_0003d2bc:\n"
        "movl -0x114(%ebp), %ebx\n" /* line 652 | boneNames */
        "movzwl (%ebx, %ecx, 2), %esi\n" /* name */
        "testl %edi, %edi\n" /* line 653 */
        "js .Lf3c92e_0003d30e\n"
        "movl -0x128(%ebp), %edx\n" /* line 655 */
        "movzwl (%edx), %eax\n"
        "cmpl %esi, %eax\n" /* name */
        "je .Lf3c92e_0003d3eb\n"
        "movl -0x180(%ebp), %edx\n" /* line 2372 */
        "addl -0x118(%ebp), %edx\n" /* partNames */
        "movl %edi, %ecx\n" /* part */
        "xorl %ebx, %ebx\n" /* modelPartIndex */
        ".Lf3c92e_0003d2eb:\n"
        "subl $1, %ecx\n" /* line 653 */
        "cmpl %ebx, %edi\n"
        "je .Lf3c92e_0003d30e\n"
        "movzwl -2(%edx), %eax\n" /* line 655 */
        "addl $1, %ebx\n"
        "subl $2, %edx\n"
        "cmpl %esi, %eax\n" /* name */
        "jne .Lf3c92e_0003d2eb\n"
        "cmpb $0x7f, -0xa0(%ebp, %ecx)\n" /* line 657 */
        "je .Lf3c92e_0003d3fb\n"
        ".Lf3c92e_0003d30e:\n"
        "addl $1, -0x120(%ebp)\n" /* line 650 | localBoneIndex */
        "addl $1, -0x124(%ebp)\n" /* boneIndex */
        "movl -0x120(%ebp), %ecx\n" /* localBoneIndex */
        "cmpl %ecx, -0x11c(%ebp)\n" /* numBones */
        "jne .Lf3c92e_0003d2bc\n"
        ".Lf3c92e_0003d32a:\n"
        "addl $1, -0x10c(%ebp)\n" /* line 641 | j */
        "movl -0x10c(%ebp), %ebx\n" /* j */
        "cmpl %ebx, -0x130(%ebp)\n" /* numModels */
        "jne .Lf3c92e_0003d289\n"
        ".Lf3c92e_0003d343:\n"
        "movl $0xb, 0xc(%esp)\n" /* line 667 */
        "movl -0x110(%ebp), %eax\n" /* len */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0xb0(%ebp), %edx\n" /* animToModel */
        "movl %edx, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        /* } scope */
        /* } scope */
        "movl -0xc8(%ebp), %ecx\n" /* line 2414 */
        "movw %ax, (%ecx)\n"
        "movl -0x16c(%ebp), %ebx\n" /* j */
        "movl 0xc(%ebx), %ecx\n" /* j */
        "jmp .Lf3c92e_0003cb84\n"
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d382:\n"
        "movzwl %dx, %edx\n" /* line 911 */
        "movl 4(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "jmp .Lf3c92e_0003cff8\n"
        ".Lf3c92e_0003d390:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf3c92e_0003c9ad\n"
        ".Lf3c92e_0003d397:\n"
        "movl -0x15c(%ebp), %ebx\n" /* parts, rotFrameDeltas */
        "movl -0x15c(%ebp), %eax\n" /* parts */
        "jmp .Lf3c92e_0003cf91\n"
        /* } scope */
        /* } scope */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d3a8:\n"
        "movl %edi, %ecx\n" /* line 655 */
        "cmpb $0x7f, -0xa0(%ebp, %ecx)\n" /* line 657 */
        "jne .Lf3c92e_0003cb15\n"
        ".Lf3c92e_0003d3b8:\n"
        "movzbl -0x14c(%ebp), %ebx\n" /* line 659 | boneIndex */
        "movb %bl, -0xa0(%ebp, %ecx)\n"
        "movl -0x14c(%ebp), %eax\n" /* line 660 | boneIndex */
        "sarl $5, %eax\n"
        "movl -0x14c(%ebp), %ecx\n" /* boneIndex */
        "andl $0x1f, %ecx\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "orl %edx, -0xb0(%ebp, %eax, 4)\n"
        "jmp .Lf3c92e_0003cb15\n"
        /* } scope */
        /* } scope */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d3eb:\n"
        "movl %edi, %ecx\n" /* line 655 */
        "cmpb $0x7f, -0xa0(%ebp, %ecx)\n" /* line 657 */
        "jne .Lf3c92e_0003d30e\n"
        ".Lf3c92e_0003d3fb:\n"
        "movzbl -0x124(%ebp), %ebx\n" /* line 659 | boneIndex */
        "movb %bl, -0xa0(%ebp, %ecx)\n"
        "movl -0x124(%ebp), %eax\n" /* line 660 | boneIndex */
        "sarl $5, %eax\n"
        "movl -0x124(%ebp), %ecx\n" /* boneIndex */
        "andl $0x1f, %ecx\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "orl %edx, -0xb0(%ebp, %eax, 4)\n"
        "jmp .Lf3c92e_0003d30e\n"
        /* } scope */
        /* } scope */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d42e:\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 974 */
        "addss 0xc(%ebx), %xmm0\n" /* totalRotTrans */
        "movss %xmm0, 0xc(%ebx)\n" /* totalRotTrans */
        "jmp .Lf3c92e_0003d021\n"
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003d445:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2444 | info */
        "addl $0x4010, %ecx\n"
        "movl %ecx, -0xe0(%ebp)\n" /* ignorePartBits */
        "addl $0x10, %esi\n" /* animToModel */
        "movl %esi, -0xdc(%ebp)\n" /* animToModel */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        "movzwl %ax, %eax\n" /* line 863 */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movss %xmm1, -0xb0(%ebp)\n" /* line 684 | animToModel */
        "movl %eax, -0xac(%ebp)\n" /* line 685 */
        "cvtsi2ssl %eax, %xmm0\n" /* line 686 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n"
        "cvttss2si %xmm0, %eax\n" /* line 687 */
        "movl %eax, -0xa4(%ebp)\n"
        /* } scope */
        "movss -0x174(%ebp), %xmm3\n" /* line 870 */
        "mulss lit4_002ed664, %xmm3\n" /* 3.0518509447574615e-05f */
        "movl -0x15c(%ebp), %ebx\n" /* line 872 | parts, to */
        "movl 0x14(%ebx), %ebx\n" /* to */
        "movl %ebx, -0xcc(%ebp)\n" /* to, simpleQuatBits */
        "movl -0x15c(%ebp), %eax\n" /* line 873 | parts */
        "movswl 0xe(%eax), %eax\n"
        "movl %eax, -0xd0(%ebp)\n" /* size */
        "testl %eax, %eax\n" /* line 874 */
        "jle .Lf3c92e_0003cec1\n"
        "movl $0, -0xd8(%ebp)\n" /* animPartIndex */
        "jmp .Lf3c92e_0003d5a8\n"
        ".Lf3c92e_0003d4ce:\n"
        "movl -0xd4(%ebp), %eax\n" /* line 889 | part */
        "movl 4(%eax), %ebx\n" /* to */
        "testl %ebx, %ebx\n" /* to */
        "je .Lf3c92e_0003dbb3\n"
        "leal 8(%edi), %esi\n" /* line 890 | totalRotTrans, out */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movzwl (%ebx), %eax\n" /* line 792 */
        "testw %ax, %ax\n"
        "jne .Lf3c92e_0003d97c\n"
        "movswl 4(%ebx), %eax\n" /* line 827 | to */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 8(%edi), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "movswl 6(%ebx), %eax\n" /* line 828 | to */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 4(%esi), %xmm0\n" /* out */
        "movss %xmm0, 4(%esi)\n" /* out */
        /* } scope */
        ".Lf3c92e_0003d51a:\n"
        "movl -0xd4(%ebp), %edx\n" /* line 899 | part */
        "movl (%edx), %ebx\n" /* rotFrameDeltas */
        "testl %ebx, %ebx\n" /* rotFrameDeltas */
        "je .Lf3c92e_0003d57d\n"
        "leal 0x10(%edi), %esi\n" /* line 900 | totalRotTrans, out */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        "movzwl (%ebx), %eax\n" /* line 838 | to */
        "testw %ax, %ax\n"
        "jne .Lf3c92e_0003d683\n"
        "leal 4(%ebx), %eax\n" /* line 840 | to, dir */
        /* { scope 5 */
        "movss -0x174(%ebp), %xmm0\n" /* line 288 */
        "mulss 4(%ebx), %xmm0\n"
        "addss 0x10(%edi), %xmm0\n"
        "movss %xmm0, 0x10(%edi)\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 290 */
        "mulss 8(%eax), %xmm0\n"
        "addss 8(%esi), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003d57d:\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 902 */
        "addss 0x1c(%edi), %xmm0\n" /* totalRotTrans */
        "movss %xmm0, 0x1c(%edi)\n" /* totalRotTrans */
        ".Lf3c92e_0003d58f:\n"
        "addl $1, -0xd8(%ebp)\n" /* line 874 | animPartIndex */
        "movl -0xd8(%ebp), %edx\n" /* animPartIndex */
        "cmpl %edx, -0xd0(%ebp)\n" /* size */
        "je .Lf3c92e_0003cec1\n"
        ".Lf3c92e_0003d5a8:\n"
        "movl -0xdc(%ebp), %ecx\n" /* line 876 | animToModel */
        "movl -0xd8(%ebp), %ebx\n" /* animPartIndex, to */
        "movzbl (%ecx, %ebx), %edx\n"
        "movl %edx, %eax\n" /* line 880 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl -0xe0(%ebp), %ebx\n" /* ignorePartBits, to */
        "movl (%ebx, %eax, 4), %eax\n" /* to */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003d58f\n"
        "shll $5, %edx\n" /* line 883 */
        "movl -0x178(%ebp), %edi\n" /* totalRotTrans */
        "addl %edx, %edi\n" /* totalRotTrans */
        "movl -0x15c(%ebp), %edx\n" /* line 885 | parts */
        "movl 0x18(%edx), %eax\n"
        "movl -0xd8(%ebp), %ecx\n" /* animPartIndex */
        "leal (%eax, %ecx, 8), %eax\n"
        "movl %eax, -0xd4(%ebp)\n" /* part */
        "movl %ecx, %eax\n" /* line 887 */
        "sarl $3, %eax\n"
        "movl -0xcc(%ebp), %ebx\n" /* simpleQuatBits, to */
        "movsbl (%ebx, %eax), %eax\n" /* to */
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003d4ce\n"
        "movl -0xd4(%ebp), %edx\n" /* line 896 | part */
        "movl 4(%edx), %ebx\n" /* rotFrameDeltas */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 5 */
        "movzwl (%ebx), %eax\n" /* line 815 */
        "testw %ax, %ax\n"
        "jne .Lf3c92e_0003d898\n"
        "leal 4(%ebx), %edx\n" /* line 817 | base */
        /* { scope 6 */
        "movswl 4(%ebx), %eax\n" /* line 837 | to */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movswl 2(%edx), %eax\n" /* line 838 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 4(%edi), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movswl 4(%edx), %eax\n" /* line 839 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 8(%edi), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "movswl 6(%edx), %eax\n" /* line 840 | dir */
        "cvtsi2ssl %eax, %xmm0\n" /* dir */
        "mulss %xmm3, %xmm0\n"
        "addss 0xc(%edi), %xmm0\n"
        "movss %xmm0, 0xc(%edi)\n"
        "jmp .Lf3c92e_0003d51a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d683:\n"
        "movzwl %ax, %ecx\n" /* line 844 | tableSize */
        "leal 8(%ebx), %edx\n" /* to, indices */
        /* { scope 5 */
        "cmpl -0xac(%ebp), %ecx\n" /* line 766 */
        "jl .Lf3c92e_0003db7e\n"
        "cvtsi2ssl -0xa4(%ebp), %xmm0\n" /* line 773 */
        "movss -0xa8(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n" /* keyFrameLerpFrac */
        "movl -0xa4(%ebp), %eax\n" /* line 774 */
        "movl %eax, -0x20(%ebp)\n" /* keyFrameIndex */
        "movaps %xmm1, %xmm2\n"
        /* } scope */
        ".Lf3c92e_0003d6ba:\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 846 | from */
        "shll $2, %eax\n" /* from */
        "addl 4(%ebx), %eax\n" /* to, from */
        "leal 0xc(%eax), %edx\n" /* to */
        /* { scope 5 */
        "movss (%eax), %xmm1\n" /* line 870 */
        "movss 0xc(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss -0x174(%ebp), %xmm1\n"
        "addss (%esi), %xmm1\n" /* out */
        "movss %xmm1, (%esi)\n" /* out */
        "movss 4(%eax), %xmm1\n" /* line 871 */
        "movss 4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss -0x174(%ebp), %xmm1\n"
        "addss 4(%esi), %xmm1\n" /* out */
        "movss %xmm1, 4(%esi)\n" /* out */
        "movss 8(%eax), %xmm1\n" /* line 872 */
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss -0x174(%ebp), %xmm1\n"
        "addss 8(%esi), %xmm1\n" /* out */
        "movss %xmm1, 8(%esi)\n" /* out */
        "jmp .Lf3c92e_0003d57d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d740:\n"
        "movzwl %ax, %ecx\n" /* line 844 | tableSize */
        "leal 8(%ebx), %edx\n" /* to, indices */
        "leal -0x1c(%ebp), %eax\n" /* keyFrameLerpFrac */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* keyFrameIndex */
        "movl %eax, (%esp)\n"
        "leal -0xb0(%ebp), %eax\n" /* animToModel */
        "movss %xmm3, -0x198(%ebp)\n"
        "calll Z18XAnim_GetTimeIndexIhEvPK9XAnimTimePK19XAnimDynamicIndicesiPiPf\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 846 | keyFrameLerpFrac */
        "movl -0x20(%ebp), %eax\n" /* keyFrameIndex, from */
        "leal (%eax, %eax, 2), %eax\n" /* from */
        "shll $2, %eax\n" /* from */
        "addl 4(%ebx), %eax\n" /* to, from */
        "leal 0xc(%eax), %edx\n" /* to */
        /* { scope 5 */
        "movss (%eax), %xmm1\n" /* line 870 */
        "movss 0xc(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss -0x174(%ebp), %xmm1\n"
        "addss 0x10(%edi), %xmm1\n" /* totalRotTrans */
        "movss %xmm1, 0x10(%edi)\n" /* totalRotTrans */
        "movss 4(%eax), %xmm1\n" /* line 871 */
        "movss 4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss -0x174(%ebp), %xmm1\n"
        "addss 4(%esi), %xmm1\n" /* out */
        "movss %xmm1, 4(%esi)\n" /* out */
        "movss 8(%eax), %xmm1\n" /* line 872 */
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss -0x174(%ebp), %xmm1\n"
        "addss 8(%esi), %xmm1\n" /* out */
        "movss %xmm1, 8(%esi)\n" /* out */
        "movss -0x198(%ebp), %xmm3\n"
        "jmp .Lf3c92e_0003cd46\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003d7fe:\n"
        "addl $1, %ecx\n" /* line 2464 */
        "movl %ecx, -0xbc(%ebp)\n"
        "cmpl %ecx, %edi\n" /* numAnims */
        "jle .Lf3c92e_0003d857\n"
        "movl %ecx, %eax\n"
        "addl %esi, %eax\n" /* animToModel */
        "movl -0x160(%ebp), %ebx\n" /* tree, j */
        "leal 8(%ebx, %eax, 2), %ecx\n" /* j */
        "movl -0xbc(%ebp), %ebx\n" /* j */
        ".Lf3c92e_0003d81f:\n"
        "movzwl (%ecx), %eax\n" /* line 2468 */
        "testw %ax, %ax\n" /* line 2469 */
        "je .Lf3c92e_0003d84d\n"
        "movzwl %ax, %eax\n" /* line 2473 */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+32(, %eax, 8), %xmm1\n"
        "movss %xmm1, -0xc0(%ebp)\n"
        "ucomiss %xmm2, %xmm1\n" /* line 2475 */
        "jp .Lf3c92e_0003dc4b\n"
        "jne .Lf3c92e_0003dc4b\n"
        ".Lf3c92e_0003d84d:\n"
        "addl $1, %ebx\n" /* line 2464 | j */
        "addl $2, %ecx\n"
        "cmpl %edi, %ebx\n" /* numAnims, j */
        "jne .Lf3c92e_0003d81f\n"
        ".Lf3c92e_0003d857:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 2573 | rotTransArrayIndex */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %ebx\n" /* info, j */
        "movl %ebx, 8(%esp)\n" /* j */
        "movzbl -0x17a(%ebp), %eax\n" /* bNormQuat */
        "movl %eax, 4(%esp)\n"
        "movzbl -0x179(%ebp), %eax\n" /* bClear */
        "movl %eax, (%esp)\n"
        "movl -0x178(%ebp), %ecx\n"
        "movss -0x174(%ebp), %xmm0\n"
        "movl -0x16c(%ebp), %eax\n"
        "calll XAnimCalc\n"
        "jmp .Lf3c92e_0003cec1\n"
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 5 */
        ".Lf3c92e_0003d898:\n"
        "movzwl %ax, %ecx\n" /* line 821 | tableSize */
        "leal 8(%ebx), %edx\n" /* indices */
        /* { scope 6 */
        "cmpl -0xac(%ebp), %ecx\n" /* line 766 */
        "jl .Lf3c92e_0003dbe1\n"
        "cvtsi2ssl -0xa4(%ebp), %xmm0\n" /* line 773 */
        "movss -0xa8(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n" /* keyFrameLerpFrac */
        "movl -0xa4(%ebp), %eax\n" /* line 774 */
        "movl %eax, -0x20(%ebp)\n" /* keyFrameIndex */
        "movaps %xmm1, %xmm2\n"
        "movl %eax, %ecx\n"
        /* } scope */
        ".Lf3c92e_0003d8d1:\n"
        "shll $3, %ecx\n" /* line 826 | from */
        "addl 4(%ebx), %ecx\n" /* to, from */
        "leal 8(%ecx), %ebx\n" /* to */
        /* { scope 6 */
        "movswl (%ecx), %edx\n" /* line 815 */
        "cvtsi2ssl %edx, %xmm1\n"
        "movswl 8(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss (%edi), %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movswl 2(%ecx), %edx\n" /* line 816 */
        "cvtsi2ssl %edx, %xmm1\n"
        "movswl 2(%ebx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss 4(%edi), %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "movswl 4(%ecx), %edx\n" /* line 817 | base */
        "cvtsi2ssl %edx, %xmm1\n" /* base */
        "movswl 4(%ebx), %eax\n"
        "subl %edx, %eax\n" /* base */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss 8(%edi), %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "movswl 6(%ecx), %edx\n" /* line 818 */
        "cvtsi2ssl %edx, %xmm0\n"
        "movswl 6(%ebx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 0xc(%edi), %xmm0\n"
        "movss %xmm0, 0xc(%edi)\n"
        "jmp .Lf3c92e_0003d51a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003d97c:\n"
        "movzwl %ax, %ecx\n" /* line 798 | tableSize */
        "leal 8(%ebx), %edx\n" /* indices */
        /* { scope 5 */
        "cmpl -0xac(%ebp), %ecx\n" /* line 766 */
        "jl .Lf3c92e_0003dc16\n"
        "cvtsi2ssl -0xa4(%ebp), %xmm0\n" /* line 773 */
        "movss -0xa8(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* keyFrameIndex */
        "movl -0xa4(%ebp), %eax\n" /* line 774 */
        "movl %eax, -0x1c(%ebp)\n" /* keyFrameLerpFrac */
        "movaps %xmm1, %xmm2\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf3c92e_0003d9b5:\n"
        "shll $2, %edx\n" /* line 803 | from */
        "addl 4(%ebx), %edx\n" /* from */
        /* { scope 5 */
        "movswl (%edx), %ecx\n" /* line 805 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "movswl 4(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss (%esi), %xmm1\n" /* out */
        "movss %xmm1, (%esi)\n" /* out */
        "movswl 2(%edx), %ecx\n" /* line 806 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "movswl 6(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 4(%esi), %xmm0\n" /* out */
        "movss %xmm0, 4(%esi)\n" /* out */
        "jmp .Lf3c92e_0003d51a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 5 */
        ".Lf3c92e_0003da0d:\n"
        "movzwl %ax, %ecx\n" /* line 821 | tableSize */
        "leal 8(%ebx), %edx\n" /* indices */
        "leal -0x20(%ebp), %eax\n" /* keyFrameIndex */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* keyFrameLerpFrac */
        "movl %eax, (%esp)\n"
        "leal -0xb0(%ebp), %eax\n" /* animToModel */
        "movss %xmm3, -0x198(%ebp)\n"
        "calll Z18XAnim_GetTimeIndexIhEvPK9XAnimTimePK19XAnimDynamicIndicesiPiPf\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 826 | keyFrameIndex */
        "movl -0x1c(%ebp), %ecx\n" /* keyFrameLerpFrac, from */
        "shll $3, %ecx\n" /* from */
        "addl 4(%ebx), %ecx\n" /* to, from */
        "leal 8(%ecx), %ebx\n" /* to */
        /* { scope 6 */
        "movswl (%ecx), %edx\n" /* line 815 */
        "cvtsi2ssl %edx, %xmm1\n"
        "movswl 8(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x198(%ebp), %xmm3\n"
        "mulss %xmm3, %xmm1\n"
        "addss (%edi), %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movswl 2(%ecx), %edx\n" /* line 816 */
        "cvtsi2ssl %edx, %xmm1\n"
        "movswl 2(%ebx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss 4(%edi), %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "movswl 4(%ecx), %edx\n" /* line 817 | base */
        "cvtsi2ssl %edx, %xmm1\n" /* base */
        "movswl 4(%ebx), %eax\n"
        "subl %edx, %eax\n" /* base */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss 8(%edi), %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "movswl 6(%ecx), %edx\n" /* line 818 */
        "cvtsi2ssl %edx, %xmm0\n"
        "movswl 6(%ebx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 0xc(%edi), %xmm0\n"
        "movss %xmm0, 0xc(%edi)\n"
        "jmp .Lf3c92e_0003cce3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003daee:\n"
        "movzwl %ax, %ecx\n" /* line 798 | tableSize */
        "leal 8(%ebx), %edx\n" /* indices */
        "leal -0x1c(%ebp), %eax\n" /* keyFrameLerpFrac */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* keyFrameIndex */
        "movl %eax, (%esp)\n"
        "leal -0xb0(%ebp), %eax\n" /* animToModel */
        "movss %xmm3, -0x198(%ebp)\n"
        "calll Z18XAnim_GetTimeIndexIhEvPK9XAnimTimePK19XAnimDynamicIndicesiPiPf\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 803 | keyFrameLerpFrac */
        "movl -0x20(%ebp), %edx\n" /* keyFrameIndex, from */
        "shll $2, %edx\n" /* from */
        "addl 4(%ebx), %edx\n" /* from */
        /* { scope 5 */
        "movswl (%edx), %ecx\n" /* line 805 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "movswl 4(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x198(%ebp), %xmm3\n"
        "mulss %xmm3, %xmm1\n"
        "addss 8(%edi), %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "movswl 2(%edx), %ecx\n" /* line 806 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "movswl 6(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss 4(%esi), %xmm0\n" /* out */
        "movss %xmm0, 4(%esi)\n" /* out */
        "jmp .Lf3c92e_0003cce3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 5 */
        ".Lf3c92e_0003db7e:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 768 | keyFrameLerpFrac */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* keyFrameIndex */
        "movl %eax, (%esp)\n"
        "leal -0xb0(%ebp), %eax\n" /* animToModel */
        "movss %xmm3, -0x198(%ebp)\n"
        "calll Z28XAnim_GetTimeIndexCompressedItEvPK9XAnimTimePKT_iPiPf\n"
        "movss -0x198(%ebp), %xmm3\n"
        "movss -0x1c(%ebp), %xmm2\n" /* keyFrameLerpFrac */
        "movl -0x20(%ebp), %eax\n" /* keyFrameIndex */
        "jmp .Lf3c92e_0003d6ba\n"
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003dbb3:\n"
        "movss -0x174(%ebp), %xmm0\n" /* line 892 */
        "addss 0xc(%edi), %xmm0\n" /* totalRotTrans */
        "movss %xmm0, 0xc(%edi)\n" /* totalRotTrans */
        "jmp .Lf3c92e_0003d51a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        ".Lf3c92e_0003dbca:\n"
        "movss -0x174(%ebp), %xmm0\n"
        "addss 0xc(%edi), %xmm0\n" /* totalRotTrans */
        "movss %xmm0, 0xc(%edi)\n" /* totalRotTrans */
        "jmp .Lf3c92e_0003cce3\n"
        /* } scope */
        /* } scope */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        /* { scope 3: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 5 */
        /* { scope 6 */
        ".Lf3c92e_0003dbe1:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 768 | keyFrameLerpFrac */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* keyFrameIndex */
        "movl %eax, (%esp)\n"
        "leal -0xb0(%ebp), %eax\n" /* animToModel */
        "movss %xmm3, -0x198(%ebp)\n"
        "calll Z28XAnim_GetTimeIndexCompressedItEvPK9XAnimTimePKT_iPiPf\n"
        "movss -0x198(%ebp), %xmm3\n"
        "movss -0x1c(%ebp), %xmm2\n" /* keyFrameLerpFrac */
        "movl -0x20(%ebp), %ecx\n" /* keyFrameIndex */
        "jmp .Lf3c92e_0003d8d1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: keyFrameIndex, keyFrameLerpFrac */
        /* { scope 5 */
        ".Lf3c92e_0003dc16:\n"
        "leal -0x20(%ebp), %eax\n" /* keyFrameIndex */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* keyFrameLerpFrac */
        "movl %eax, (%esp)\n"
        "leal -0xb0(%ebp), %eax\n" /* animToModel */
        "movss %xmm3, -0x198(%ebp)\n"
        "calll Z28XAnim_GetTimeIndexCompressedItEvPK9XAnimTimePKT_iPiPf\n"
        "movss -0x198(%ebp), %xmm3\n"
        "movss -0x20(%ebp), %xmm2\n" /* keyFrameIndex */
        "movl -0x1c(%ebp), %edx\n" /* keyFrameLerpFrac */
        "jmp .Lf3c92e_0003d9b5\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3c92e_0003dc4b:\n"
        "cmpb $0, -0x179(%ebp)\n" /* line 2478 | bClear */
        "jne .Lf3c92e_0003e141\n"
        "movl 0x14(%ebp), %eax\n" /* line 2484 | rotTransArrayIndex */
        "shll $5, %eax\n"
        "movl 0x10(%ebp), %esi\n" /* info, animToModel */
        "addl %eax, %esi\n" /* animToModel */
        "movl -0x16c(%ebp), %ecx\n" /* line 2485 */
        "movzbl 0x19(%ecx), %eax\n"
        "addl %eax, 0x14(%ebp)\n" /* rotTransArrayIndex */
        "cmpl $0x200, 0x14(%ebp)\n" /* line 2486 | rotTransArrayIndex */
        "jg .Lf3c92e_0003e14c\n"
        ".Lf3c92e_0003dc7d:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2493 | rotTransArrayIndex */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* info */
        "movl %ecx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "movl %esi, %ecx\n" /* animToModel */
        "movl -0x16c(%ebp), %eax\n"
        "calll XAnimCalc\n"
        "movl -0x164(%ebp), %eax\n" /* line 2494 | anim */
        "movzwl 6(%eax), %edx\n"
        "addl %ebx, %edx\n" /* j */
        "movl 0x14(%ebp), %ecx\n" /* rotTransArrayIndex */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* info */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl %esi, %ecx\n" /* animToModel */
        "movss -0xc0(%ebp), %xmm0\n"
        "movl -0x16c(%ebp), %eax\n"
        "calll XAnimCalc\n"
        "leal 1(%ebx), %eax\n" /* line 2496 | j */
        "cmpl %eax, %edi\n" /* numAnims */
        "jle .Lf3c92e_0003dd5a\n"
        "movl %eax, %ebx\n" /* j */
        "jmp .Lf3c92e_0003dcf7\n"
        ".Lf3c92e_0003dcf0:\n"
        "addl $1, %ebx\n" /* j */
        "cmpl %ebx, %edi\n" /* j, numAnims */
        "je .Lf3c92e_0003dd5a\n"
        ".Lf3c92e_0003dcf7:\n"
        "movl -0x164(%ebp), %edx\n" /* line 2500 | anim */
        "movzwl 6(%edx), %eax\n"
        "leal (%ebx, %eax), %edx\n" /* j */
        "movl -0x160(%ebp), %ecx\n" /* tree */
        "movzwl 8(%ecx, %edx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 2501 */
        "je .Lf3c92e_0003dcf0\n"
        "movzwl %ax, %eax\n" /* line 2505 */
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+32(, %eax, 8), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 2507 | 0.0f */
        "jp .Lf3c92e_0003dd2e\n"
        "je .Lf3c92e_0003dcf0\n"
        ".Lf3c92e_0003dd2e:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2510 | rotTransArrayIndex */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* info */
        "movl %ecx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl %esi, %ecx\n" /* animToModel */
        "movl -0x16c(%ebp), %eax\n"
        "calll XAnimCalc\n"
        "jmp .Lf3c92e_0003dcf0\n"
        ".Lf3c92e_0003dd5a:\n"
        "cmpb $0, -0x17a(%ebp)\n" /* line 2513 | bNormQuat */
        "jne .Lf3c92e_0003de3f\n"
        "movl -0x16c(%ebp), %eax\n" /* line 2516 */
        "cmpb $0, 0x19(%eax)\n"
        "je .Lf3c92e_0003cec1\n"
        "xorl %edx, %edx\n"
        ".Lf3c92e_0003dd79:\n"
        "movl %edx, %eax\n" /* line 2518 */
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* info, j */
        "movl 0x4010(%ebx, %eax, 4), %eax\n" /* j */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003de1e\n"
        "movl -0x178(%ebp), %eax\n" /* line 2521 */
        "movss 0x1c(%eax), %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lf3c92e_0003ddad\n"
        "je .Lf3c92e_0003de1e\n"
        ".Lf3c92e_0003ddad:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 2523 | 1.0f */
        "divss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* line 519 */
        "mulss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 520 */
        "mulss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 521 */
        "mulss 8(%eax), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        "movaps %xmm0, %xmm1\n" /* line 522 */
        "mulss 0xc(%eax), %xmm1\n"
        "movss %xmm1, 0xc(%eax)\n"
        "movl -0x178(%ebp), %eax\n" /* line 2529 | result */
        "addl $0x10, %eax\n" /* result */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "movl -0x178(%ebp), %ecx\n"
        "mulss 0x10(%ecx), %xmm1\n"
        "movss %xmm1, 0x10(%ecx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%eax), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        ".Lf3c92e_0003de1e:\n"
        "addl $1, %edx\n" /* line 2516 */
        "addl $0x20, -0x178(%ebp)\n"
        "movl -0x16c(%ebp), %ebx\n" /* j */
        "movzbl 0x19(%ebx), %eax\n" /* j */
        "cmpl %eax, %edx\n"
        "jl .Lf3c92e_0003dd79\n"
        "jmp .Lf3c92e_0003cec1\n"
        ".Lf3c92e_0003de3f:\n"
        "cmpb $0, -0x179(%ebp)\n" /* line 2535 | bClear */
        "je .Lf3c92e_0003dfae\n"
        "movl -0x16c(%ebp), %ebx\n" /* line 2537 | j */
        "cmpb $0, 0x19(%ebx)\n" /* j */
        "je .Lf3c92e_0003cec1\n"
        "xorl %ebx, %ebx\n" /* j */
        ".Lf3c92e_0003de5e:\n"
        "movl %ebx, %eax\n" /* line 2539 | j */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n" /* j */
        "andl $0x1f, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* info */
        "movl 0x4010(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003df8d\n"
        "movl -0x178(%ebp), %ecx\n" /* line 567 */
        "movss (%ecx), %xmm3\n"
        "movss 4(%ecx), %xmm0\n"
        "movss 8(%ecx), %xmm1\n"
        "movss 0xc(%ecx), %xmm2\n"
        "mulss %xmm3, %xmm3\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "pxor %xmm2, %xmm2\n" /* line 2543 */
        "ucomiss %xmm2, %xmm3\n"
        "jp .Lf3c92e_0003debc\n"
        "je .Lf3c92e_0003df35\n"
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        ".Lf3c92e_0003debc:\n"
        "movss %xmm3, -0x20(%ebp)\n" /* line 69 | keyFrameIndex */
        "movl -0x20(%ebp), %edx\n" /* line 71 | keyFrameIndex */
        "sarl $1, %edx\n"
        "movl $0x5f3759df, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* keyFrameLerpFrac */
        "movss -0x1c(%ebp), %xmm1\n" /* line 72 | keyFrameLerpFrac */
        "mulss lit4_002ed5d8, %xmm3\n" /* line 73 | 0.5f */
        "mulss %xmm1, %xmm3\n"
        "mulss %xmm1, %xmm3\n"
        "movss lit4_002ed600, %xmm0\n" /* 1.5f */
        "subss %xmm3, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* keyFrameIndex */
        /* } scope */
        "movss -0x174(%ebp), %xmm1\n" /* line 2544 | scale */
        "mulss %xmm0, %xmm1\n" /* scale */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        "movaps %xmm1, %xmm0\n" /* line 519 */
        "mulss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 520 */
        "mulss 4(%ecx), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 521 */
        "mulss 8(%ecx), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "mulss 0xc(%ecx), %xmm1\n" /* line 522 */
        "movss %xmm1, 0xc(%ecx)\n"
        /* } scope */
        ".Lf3c92e_0003df35:\n"
        "movl -0x178(%ebp), %eax\n" /* line 2546 */
        "movss 0x1c(%eax), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jp .Lf3c92e_0003df47\n"
        "je .Lf3c92e_0003df8d\n"
        ".Lf3c92e_0003df47:\n"
        "movss -0x174(%ebp), %xmm1\n" /* line 2548 | scale */
        "divss %xmm0, %xmm1\n" /* scale */
        "addl $0x10, %eax\n" /* result */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "movl -0x178(%ebp), %edx\n"
        "mulss 0x10(%edx), %xmm0\n"
        "movss %xmm0, 0x10(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "movss -0x174(%ebp), %xmm0\n" /* line 2549 */
        "movss %xmm0, 0x1c(%edx)\n"
        ".Lf3c92e_0003df8d:\n"
        "addl $1, %ebx\n" /* line 2537 | j */
        "addl $0x20, -0x178(%ebp)\n"
        "movl -0x16c(%ebp), %edx\n"
        "movzbl 0x19(%edx), %eax\n"
        "cmpl %eax, %ebx\n" /* j */
        "jl .Lf3c92e_0003de5e\n"
        "jmp .Lf3c92e_0003cec1\n"
        ".Lf3c92e_0003dfae:\n"
        "movl -0x16c(%ebp), %ecx\n" /* line 2555 */
        "cmpb $0, 0x19(%ecx)\n"
        "je .Lf3c92e_0003cec1\n"
        "xorl %ebx, %ebx\n" /* j */
        ".Lf3c92e_0003dfc0:\n"
        "movl %ebx, %eax\n" /* line 2557 | j */
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n" /* j */
        "andl $0x1f, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* info */
        "movl 0x4010(%edx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3c92e_0003e11d\n"
        "movss (%esi), %xmm3\n" /* line 567 */
        "movss 4(%esi), %xmm0\n"
        "movss 8(%esi), %xmm1\n"
        "movss 0xc(%esi), %xmm2\n"
        "mulss %xmm3, %xmm3\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "pxor %xmm2, %xmm2\n" /* line 2561 */
        "ucomiss %xmm2, %xmm3\n"
        "jp .Lf3c92e_0003e01c\n"
        "je .Lf3c92e_0003e0ae\n"
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        ".Lf3c92e_0003e01c:\n"
        "movss %xmm3, -0x1c(%ebp)\n" /* line 69 | keyFrameLerpFrac */
        "movl -0x1c(%ebp), %edx\n" /* line 71 | keyFrameLerpFrac */
        "sarl $1, %edx\n"
        "movl $0x5f3759df, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* keyFrameIndex */
        "movss -0x20(%ebp), %xmm1\n" /* line 72 | keyFrameIndex */
        "mulss lit4_002ed5d8, %xmm3\n" /* line 73 | 0.5f */
        "mulss %xmm1, %xmm3\n"
        "mulss %xmm1, %xmm3\n"
        "movss lit4_002ed600, %xmm0\n" /* 1.5f */
        "subss %xmm3, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* keyFrameLerpFrac */
        /* } scope */
        "movss -0x174(%ebp), %xmm1\n" /* line 2562 | scale */
        "mulss %xmm0, %xmm1\n" /* scale */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        "movaps %xmm1, %xmm0\n" /* line 537 */
        "mulss (%esi), %xmm0\n"
        "movl -0x178(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 538 */
        "mulss 4(%esi), %xmm0\n"
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 539 */
        "mulss 8(%esi), %xmm0\n"
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "mulss 0xc(%esi), %xmm1\n" /* line 540 */
        "addss 0xc(%ecx), %xmm1\n"
        "movss %xmm1, 0xc(%ecx)\n"
        /* } scope */
        ".Lf3c92e_0003e0ae:\n"
        "movss 0x1c(%esi), %xmm0\n" /* line 2564 | animToModel */
        "ucomiss %xmm2, %xmm0\n"
        "jp .Lf3c92e_0003e0ba\n"
        "je .Lf3c92e_0003e11d\n"
        ".Lf3c92e_0003e0ba:\n"
        "movss -0x174(%ebp), %xmm1\n" /* line 2566 | scale */
        "divss %xmm0, %xmm1\n" /* scale */
        "movl -0x178(%ebp), %eax\n" /* result */
        "addl $0x10, %eax\n" /* result */
        "leal 0x10(%esi), %edx\n" /* animToModel, dir */
        /* { scope 2: animToModel, boneIndex, localBoneIndex, numBones, ... */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x10(%esi), %xmm0\n"
        "movl -0x178(%ebp), %ecx\n"
        "addss 0x10(%ecx), %xmm0\n"
        "movss %xmm0, 0x10(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%edx), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%edx), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        "movss -0x174(%ebp), %xmm0\n" /* line 2567 */
        "addss 0x1c(%ecx), %xmm0\n"
        "movss %xmm0, 0x1c(%ecx)\n"
        ".Lf3c92e_0003e11d:\n"
        "addl $1, %ebx\n" /* line 2555 | j */
        "addl $0x20, -0x178(%ebp)\n"
        "addl $0x20, %esi\n" /* animToModel */
        "movl -0x16c(%ebp), %edx\n"
        "movzbl 0x19(%edx), %eax\n"
        "cmpl %eax, %ebx\n" /* j */
        "jl .Lf3c92e_0003dfc0\n"
        "jmp .Lf3c92e_0003cec1\n"
        ".Lf3c92e_0003e141:\n"
        "movl -0x178(%ebp), %esi\n" /* line 2489 | animToModel */
        "jmp .Lf3c92e_0003dc7d\n"
        ".Lf3c92e_0003e14c:\n"
        "movl $str_002178f4, (%esp)\n" /* line 2488 */
        "calll Com_Printf\n"
        "jmp .Lf3c92e_0003cec1\n"
    );
}

/* line 3211 */
__attribute__((naked))
void DObjCalcAnim(const DObj *obj, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3211 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x405c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 3228 | obj */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x404c(%ebp)\n" /* skel */
        "movl %eax, %edx\n"
        "movl $1, %ecx\n"
        "movl $1, %ebx\n" /* mat */
        "leal -0x38(%ebp), %esi\n"
        ".Lf3e15e_0003e185:\n"
        "movl 0xc(%ebp), %edi\n" /* line 3235 | partBits, model */
        "movl -4(%edi, %ebx, 4), %eax\n" /* model */
        "notl %eax\n"
        "orl (%edx), %eax\n"
        "movl %eax, (%esi)\n"
        "addl $1, %eax\n" /* line 3236 */
        "movl $0, %eax\n"
        "cmovnel %eax, %ecx\n"
        "addl $1, %ebx\n" /* mat */
        "addl $4, %esi\n"
        "addl $4, %edx\n"
        "cmpl $5, %ebx\n" /* line 3233 | mat */
        "jne .Lf3e15e_0003e185\n"
        "testb %cl, %cl\n" /* line 3240 */
        "jne .Lf3e15e_0003e3ab\n"
        "movl -0x404c(%ebp), %edx\n" /* line 3243 | skel */
        "movl $1, %esi\n"
        "movb $4, %bl\n" /* mat */
        ".Lf3e15e_0003e1c0:\n"
        "movl (%edx), %eax\n" /* line 3263 */
        "movl 0xc(%ebp), %ecx\n" /* partBits */
        "orl -4(%ebx, %ecx), %eax\n" /* mat */
        "movl %eax, (%edx)\n"
        "movl -0x3c(%ebx, %ebp), %eax\n" /* line 3264 | mat */
        "movl %eax, -0x2c(%ebx, %ebp)\n" /* mat */
        "addl $1, %esi\n"
        "addl $4, %ebx\n" /* mat */
        "addl $4, %edx\n"
        "cmpl $5, %esi\n" /* line 3261 */
        "jne .Lf3e15e_0003e1c0\n"
        "movl -0x404c(%ebp), %ebx\n" /* line 3267 | skel, mat */
        "addl $0x30, %ebx\n" /* mat */
        "movl 8(%ebp), %edi\n" /* line 3269 | obj, model */
        "movl (%edi), %edx\n" /* model */
        "testl %edx, %edx\n"
        "je .Lf3e15e_0003e3b6\n"
        "orl $0x80000000, -0x1c(%ebp)\n" /* line 3271 */
        "movl $0, 0xc(%esp)\n" /* line 3273 */
        "leal -0x4038(%ebp), %eax\n" /* info */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "movl %ebx, %ecx\n" /* mat */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "xorl %edx, %edx\n"
        "movl %edi, %eax\n" /* model */
        "calll XAnimCalc\n"
        "movl 8(%ebp), %edx\n" /* obj */
        ".Lf3e15e_0003e235:\n"
        "cmpb $0, 0x18(%edx)\n" /* line 3279 */
        "je .Lf3e15e_0003e3ab\n"
        "movl %edx, -0x4040(%ebp)\n"
        "xorl %ecx, %ecx\n"
        "movl $0, -0x4044(%ebp)\n" /* j */
        "movss lit4_002ed664, %xmm2\n" /* 3.0518509447574615e-05f */
        "movl %edx, %edi\n" /* model */
        "movl 0x1c(%edi), %eax\n" /* line 3281 | model */
        "movl (%eax), %edi\n" /* model */
        "movzwl 2(%edi), %eax\n" /* line 3283 | model */
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n"
        "jne .Lf3e15e_0003e351\n"
        ".Lf3e15e_0003e270:\n"
        "movl %ecx, %esi\n"
        ".Lf3e15e_0003e272:\n"
        "movl 8(%edi), %ecx\n" /* line 3305 | model */
        "movswl (%edi), %edx\n" /* line 3309 | model */
        "movswl 2(%edi), %eax\n" /* model */
        "subl %eax, %edx\n"
        "movl %edx, -0x403c(%ebp)\n"
        "je .Lf3e15e_0003e317\n"
        "xorl %edi, %edi\n" /* model */
        "movaps %xmm2, %xmm1\n"
        "movl %ecx, %edx\n"
        ".Lf3e15e_0003e291:\n"
        "movl %esi, %eax\n" /* line 3311 */
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl -0x38(%ebp, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3e15e_0003e2ff\n"
        "movswl (%edx), %eax\n" /* line 849 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "movswl 2(%edx), %eax\n" /* line 850 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movswl 4(%edx), %eax\n" /* line 851 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "movswl 6(%edx), %eax\n" /* line 852 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n"
        "leal 0x10(%ebx), %eax\n" /* line 3324 | mat, v */
        /* { scope 2 */
        "movl $0, 0x10(%ebx)\n" /* line 183 */
        "movl $0, 4(%eax)\n" /* line 184 */
        "movl $0, 8(%eax)\n" /* line 185 */
        /* } scope */
        ".Lf3e15e_0003e2ff:\n"
        "addl $0x20, %ebx\n" /* line 3309 | mat */
        "addl $1, %esi\n"
        "addl $1, %edi\n" /* model */
        "addl $8, %edx\n"
        "cmpl %edi, -0x403c(%ebp)\n" /* model */
        "jne .Lf3e15e_0003e291\n"
        ".Lf3e15e_0003e317:\n"
        "addl $1, -0x4044(%ebp)\n" /* line 3279 | j */
        "addl $4, -0x4040(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* obj */
        "movzbl 0x18(%edx), %eax\n"
        "cmpl -0x4044(%ebp), %eax\n" /* j */
        "jle .Lf3e15e_0003e3ab\n"
        "movl %esi, %ecx\n"
        "movl -0x4040(%ebp), %edi\n" /* model */
        "movl 0x1c(%edi), %eax\n" /* line 3281 | model */
        "movl (%eax), %edi\n" /* model */
        "movzwl 2(%edi), %eax\n" /* line 3283 | model */
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n"
        "je .Lf3e15e_0003e270\n"
        ".Lf3e15e_0003e351:\n"
        "movl %ecx, %esi\n"
        "addl %ecx, %edx\n"
        ".Lf3e15e_0003e355:\n"
        "movl %esi, %eax\n" /* line 3285 */
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl -0x38(%ebp, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf3e15e_0003e39c\n"
        "movl $0, (%ebx)\n" /* line 3298 | mat */
        "movl $0, 4(%ebx)\n" /* line 3299 | mat */
        "movl $0, 8(%ebx)\n" /* line 3300 | mat */
        "movl $0x3f800000, 0xc(%ebx)\n" /* line 3301 | mat */
        "leal 0x10(%ebx), %eax\n" /* line 3302 | mat, v */
        /* { scope 2 */
        "movl $0, 0x10(%ebx)\n" /* line 183 */
        "movl $0, 4(%eax)\n" /* line 184 */
        "movl $0, 8(%eax)\n" /* line 185 */
        /* } scope */
        ".Lf3e15e_0003e39c:\n"
        "addl $0x20, %ebx\n" /* line 3283 | mat */
        "addl $1, %esi\n"
        "cmpl %edx, %esi\n"
        "jne .Lf3e15e_0003e355\n"
        "jmp .Lf3e15e_0003e272\n"
        /* } scope */
        ".Lf3e15e_0003e3ab:\n"
        "addl $0x405c, %esp\n" /* line 3329 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf3e15e_0003e3b6:\n"
        "movl %edi, %edx\n" /* model */
        "jmp .Lf3e15e_0003e235\n"
    );
}

/* line 1314 */
static __attribute__((naked))
float XAnimGetAverageRateFrequency(void)
{
    __asm__ __volatile__ (
        ".Lf3e3be_0003e3be:\n"
        "pushl %ebp\n" /* line 1314 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x15c, %esp\n"
        "movl %eax, %ebx\n" /* tree */
        /* { scope 1: numAnims, info, weight, totalWeight, ... */
        "movl (%eax), %eax\n" /* line 1331 */
        "leal (%eax, %edx, 8), %edx\n" /* animIndex */
        "leal 0xc(%edx), %eax\n" /* animIndex */
        "movl %eax, -0xe4(%ebp)\n" /* anim */
        "movzwl 0xc(%edx), %eax\n" /* line 1332 | animIndex */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0xf4(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "jne .Lf3e3be_0003e405\n"
        "movl -0xe4(%ebp), %edx\n" /* line 1337 | anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        "addl $0x15c, %esp\n" /* line 1365 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numAnims, info, weight, totalWeight, ... */
        ".Lf3e3be_0003e405:\n"
        "movl -0xf4(%ebp), %ecx\n" /* line 1342 | numAnims */
        "pxor %xmm4, %xmm4\n"
        "testl %ecx, %ecx\n"
        "jle .Lf3e3be_0003eb94\n"
        "xorl %esi, %esi\n" /* line 1337 | i */
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm6\n"
        "movss %xmm4, -0xe8(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003e479\n"
        /* { scope 2: numAnims, i, info, weight, ... */
        ".Lf3e3be_0003e42a:\n"
        "movl -0xcc(%ebp), %edx\n" /* anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        ".Lf3e3be_0003e438:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1357 */
        "jp .Lf3e3be_0003e43f\n"
        "je .Lf3e3be_0003e46a\n"
        ".Lf3e3be_0003e43f:\n"
        "addss -0xec(%ebp), %xmm6\n" /* line 1360 | weight */
        "mulss -0xec(%ebp), %xmm0\n" /* line 1361 | weight */
        "movl -0xf0(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm0\n"
        "addss -0xe8(%ebp), %xmm0\n" /* totalDtime */
        "movss %xmm0, -0xe8(%ebp)\n" /* totalDtime */
        ".Lf3e3be_0003e46a:\n"
        "addl $1, %esi\n" /* line 1342 | i */
        "cmpl %esi, -0xf4(%ebp)\n" /* i, numAnims */
        "je .Lf3e3be_0003eba2\n"
        ".Lf3e3be_0003e479:\n"
        "movl -0xe4(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "leal (%esi, %eax), %edx\n" /* i, animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003e46a\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0xf0(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm0\n" /* line 1351 */
        "movss %xmm0, -0xec(%ebp)\n" /* weight */
        "ucomiss %xmm4, %xmm0\n" /* line 1353 */
        "jp .Lf3e3be_0003e4b7\n"
        "je .Lf3e3be_0003e46a\n"
        /* { scope 2: numAnims, i, info, weight, ... */
        ".Lf3e3be_0003e4b7:\n"
        "movl (%ebx), %eax\n" /* line 1331 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0xcc(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1332 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0xe0(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "je .Lf3e3be_0003e42a\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 1342 | numAnims */
        "testl %ecx, %ecx\n"
        "jle .Lf3e3be_0003e46a\n"
        "xorl %edi, %edi\n" /* line 1337 | i */
        "movss %xmm4, -0xd4(%ebp)\n" /* totalWeight */
        "movss %xmm4, -0xd0(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003e558\n"
        /* { scope 3: numAnims, i, info, weight, ... */
        ".Lf3e3be_0003e4f9:\n"
        "movl -0xb0(%ebp), %edx\n" /* anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        ".Lf3e3be_0003e507:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1357 */
        "jp .Lf3e3be_0003e50e\n"
        "je .Lf3e3be_0003e549\n"
        ".Lf3e3be_0003e50e:\n"
        "movss -0xd4(%ebp), %xmm1\n" /* line 1360 | totalWeight */
        "addss -0xd8(%ebp), %xmm1\n" /* weight */
        "movss %xmm1, -0xd4(%ebp)\n" /* totalWeight */
        "mulss -0xd8(%ebp), %xmm0\n" /* line 1361 | weight */
        "movl -0xdc(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm0\n"
        "addss -0xd0(%ebp), %xmm0\n" /* totalDtime */
        "movss %xmm0, -0xd0(%ebp)\n" /* totalDtime */
        ".Lf3e3be_0003e549:\n"
        "addl $1, %edi\n" /* line 1342 | i */
        "cmpl %edi, -0xe0(%ebp)\n" /* i, numAnims */
        "je .Lf3e3be_0003ebc0\n"
        ".Lf3e3be_0003e558:\n"
        "movl -0xcc(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "leal (%edi, %eax), %edx\n" /* i, animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003e549\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0xdc(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm0\n" /* line 1351 */
        "movss %xmm0, -0xd8(%ebp)\n" /* weight */
        "ucomiss %xmm4, %xmm0\n" /* line 1353 */
        "jp .Lf3e3be_0003e596\n"
        "je .Lf3e3be_0003e549\n"
        /* { scope 3: numAnims, i, info, weight, ... */
        ".Lf3e3be_0003e596:\n"
        "movl (%ebx), %eax\n" /* line 1331 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0xb0(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1332 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0xc8(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "je .Lf3e3be_0003e4f9\n"
        "movl -0xc8(%ebp), %edx\n" /* line 1342 | numAnims, animIndex */
        "testl %edx, %edx\n" /* animIndex */
        "jle .Lf3e3be_0003e549\n"
        "movl $0, -0xc4(%ebp)\n" /* line 1337 | i */
        "movss %xmm4, -0xb8(%ebp)\n" /* totalWeight */
        "movss %xmm4, -0xb4(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003e649\n"
        /* { scope 4: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e5e0:\n"
        "movl -0x94(%ebp), %edx\n" /* anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        ".Lf3e3be_0003e5ee:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1357 */
        "jp .Lf3e3be_0003e5f5\n"
        "je .Lf3e3be_0003e630\n"
        ".Lf3e3be_0003e5f5:\n"
        "movss -0xb8(%ebp), %xmm1\n" /* line 1360 | totalWeight */
        "addss -0xbc(%ebp), %xmm1\n" /* weight */
        "movss %xmm1, -0xb8(%ebp)\n" /* totalWeight */
        "mulss -0xbc(%ebp), %xmm0\n" /* line 1361 | weight */
        "movl -0xc0(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm0\n"
        "addss -0xb4(%ebp), %xmm0\n" /* totalDtime */
        "movss %xmm0, -0xb4(%ebp)\n" /* totalDtime */
        ".Lf3e3be_0003e630:\n"
        "addl $1, -0xc4(%ebp)\n" /* line 1342 | i */
        "movl -0xc4(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0xc8(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3e3be_0003ebe8\n"
        ".Lf3e3be_0003e649:\n"
        "movl -0xb0(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "movl -0xc4(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003e630\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0xc0(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm0\n" /* line 1351 */
        "movss %xmm0, -0xbc(%ebp)\n" /* weight */
        "ucomiss %xmm4, %xmm0\n" /* line 1353 */
        "jp .Lf3e3be_0003e68c\n"
        "je .Lf3e3be_0003e630\n"
        /* { scope 4: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e68c:\n"
        "movl (%ebx), %eax\n" /* line 1331 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x94(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1332 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0xac(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "je .Lf3e3be_0003e5e0\n"
        "movl -0xac(%ebp), %eax\n" /* line 1342 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf3e3be_0003e630\n"
        "movl $0, -0xa8(%ebp)\n" /* line 1337 | i */
        "movss %xmm4, -0x9c(%ebp)\n" /* totalWeight */
        "movss %xmm4, -0x98(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003e740\n"
        /* { scope 5: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e6da:\n"
        "movl -0x7c(%ebp), %edx\n" /* anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        ".Lf3e3be_0003e6e5:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1357 */
        "jp .Lf3e3be_0003e6ec\n"
        "je .Lf3e3be_0003e727\n"
        ".Lf3e3be_0003e6ec:\n"
        "movss -0x9c(%ebp), %xmm1\n" /* line 1360 | totalWeight */
        "addss -0xa0(%ebp), %xmm1\n" /* weight */
        "movss %xmm1, -0x9c(%ebp)\n" /* totalWeight */
        "mulss -0xa0(%ebp), %xmm0\n" /* line 1361 | weight */
        "movl -0xa4(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm0\n"
        "addss -0x98(%ebp), %xmm0\n" /* totalDtime */
        "movss %xmm0, -0x98(%ebp)\n" /* totalDtime */
        ".Lf3e3be_0003e727:\n"
        "addl $1, -0xa8(%ebp)\n" /* line 1342 | i */
        "movl -0xa8(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0xac(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3e3be_0003ec10\n"
        ".Lf3e3be_0003e740:\n"
        "movl -0x94(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "movl -0xa8(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003e727\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0xa4(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm0\n" /* line 1351 */
        "movss %xmm0, -0xa0(%ebp)\n" /* weight */
        "ucomiss %xmm4, %xmm0\n" /* line 1353 */
        "jp .Lf3e3be_0003e783\n"
        "je .Lf3e3be_0003e727\n"
        /* { scope 5: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e783:\n"
        "movl (%ebx), %eax\n" /* line 1331 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x7c(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1332 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x90(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "je .Lf3e3be_0003e6da\n"
        "movl -0x90(%ebp), %eax\n" /* line 1342 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf3e3be_0003e727\n"
        "movl $0, -0x8c(%ebp)\n" /* line 1337 | i */
        "movss %xmm4, -0x84(%ebp)\n" /* totalWeight */
        "movss %xmm4, -0x80(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003e823\n"
        /* { scope 6: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e7cb:\n"
        "movl -0x64(%ebp), %edx\n" /* anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        ".Lf3e3be_0003e7d6:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1357 */
        "jp .Lf3e3be_0003e7dd\n"
        "je .Lf3e3be_0003e80a\n"
        ".Lf3e3be_0003e7dd:\n"
        "movss -0x84(%ebp), %xmm1\n" /* line 1360 | totalWeight */
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x84(%ebp)\n" /* totalWeight */
        "mulss %xmm0, %xmm2\n" /* line 1361 */
        "movl -0x88(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm2\n"
        "addss -0x80(%ebp), %xmm2\n" /* totalDtime */
        "movss %xmm2, -0x80(%ebp)\n" /* totalDtime */
        ".Lf3e3be_0003e80a:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 1342 | i */
        "movl -0x8c(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x90(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3e3be_0003ec38\n"
        ".Lf3e3be_0003e823:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "movl -0x8c(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003e80a\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x88(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm2\n" /* line 1351 */
        "ucomiss %xmm4, %xmm2\n" /* line 1353 */
        "jp .Lf3e3be_0003e85b\n"
        "je .Lf3e3be_0003e80a\n"
        /* { scope 6: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e85b:\n"
        "movl (%ebx), %eax\n" /* line 1331 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x64(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1332 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x78(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "je .Lf3e3be_0003e7cb\n"
        "movl -0x78(%ebp), %eax\n" /* line 1342 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf3e3be_0003e80a\n"
        "movl $0, -0x74(%ebp)\n" /* line 1337 | i */
        "movss %xmm4, -0x6c(%ebp)\n" /* totalWeight */
        "movss %xmm4, -0x68(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003e8d9\n"
        /* { scope 7: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e893:\n"
        "movl -0x4c(%ebp), %edx\n" /* anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        ".Lf3e3be_0003e89e:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1357 */
        "jp .Lf3e3be_0003e8a5\n"
        "je .Lf3e3be_0003e8c9\n"
        ".Lf3e3be_0003e8a5:\n"
        "movss -0x6c(%ebp), %xmm1\n" /* line 1360 | totalWeight */
        "addss %xmm3, %xmm1\n"
        "movss %xmm1, -0x6c(%ebp)\n" /* totalWeight */
        "mulss %xmm0, %xmm3\n" /* line 1361 */
        "movl -0x70(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm3\n"
        "addss -0x68(%ebp), %xmm3\n" /* totalDtime */
        "movss %xmm3, -0x68(%ebp)\n" /* totalDtime */
        ".Lf3e3be_0003e8c9:\n"
        "addl $1, -0x74(%ebp)\n" /* line 1342 | i */
        "movl -0x74(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x78(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3e3be_0003ec5d\n"
        ".Lf3e3be_0003e8d9:\n"
        "movl -0x64(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "movl -0x74(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003e8c9\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm3\n" /* line 1351 */
        "ucomiss %xmm4, %xmm3\n" /* line 1353 */
        "jp .Lf3e3be_0003e90b\n"
        "je .Lf3e3be_0003e8c9\n"
        /* { scope 7: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e90b:\n"
        "movl (%ebx), %eax\n" /* line 1331 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x4c(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1332 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x60(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "je .Lf3e3be_0003e893\n"
        "movl -0x60(%ebp), %eax\n" /* line 1342 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf3e3be_0003e8c9\n"
        "movl $0, -0x5c(%ebp)\n" /* line 1337 | i */
        "movss %xmm4, -0x54(%ebp)\n" /* totalWeight */
        "movss %xmm4, -0x50(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003e989\n"
        /* { scope 8: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e943:\n"
        "movl -0x34(%ebp), %edx\n" /* anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        ".Lf3e3be_0003e94e:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1357 */
        "jp .Lf3e3be_0003e955\n"
        "je .Lf3e3be_0003e979\n"
        ".Lf3e3be_0003e955:\n"
        "movss -0x54(%ebp), %xmm1\n" /* line 1360 | totalWeight */
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0x54(%ebp)\n" /* totalWeight */
        "mulss %xmm0, %xmm5\n" /* line 1361 */
        "movl -0x58(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm5\n"
        "addss -0x50(%ebp), %xmm5\n" /* totalDtime */
        "movss %xmm5, -0x50(%ebp)\n" /* totalDtime */
        ".Lf3e3be_0003e979:\n"
        "addl $1, -0x5c(%ebp)\n" /* line 1342 | i */
        "movl -0x5c(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x60(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3e3be_0003ec7c\n"
        ".Lf3e3be_0003e989:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "movl -0x5c(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003e979\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm5\n" /* line 1351 */
        "ucomiss %xmm4, %xmm5\n" /* line 1353 */
        "jp .Lf3e3be_0003e9bb\n"
        "je .Lf3e3be_0003e979\n"
        /* { scope 8: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003e9bb:\n"
        "movl (%ebx), %eax\n" /* line 1331 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x34(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1332 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x48(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "je .Lf3e3be_0003e943\n"
        "movl -0x48(%ebp), %eax\n" /* line 1342 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf3e3be_0003e979\n"
        "movl $0, -0x44(%ebp)\n" /* line 1337 | i */
        "movss %xmm4, -0x3c(%ebp)\n" /* totalWeight */
        "movss %xmm4, -0x38(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003ea39\n"
        /* { scope 9 */
        ".Lf3e3be_0003e9f3:\n"
        "movl -0x1c(%ebp), %edx\n" /* anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 8(%eax), %xmm0\n"
        /* } scope */
        ".Lf3e3be_0003e9fe:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1357 */
        "jp .Lf3e3be_0003ea05\n"
        "je .Lf3e3be_0003ea29\n"
        ".Lf3e3be_0003ea05:\n"
        "movss -0x3c(%ebp), %xmm1\n" /* line 1360 | totalWeight */
        "addss %xmm7, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* totalWeight */
        "mulss %xmm0, %xmm7\n" /* line 1361 */
        "movl -0x40(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm7\n"
        "addss -0x38(%ebp), %xmm7\n" /* totalDtime */
        "movss %xmm7, -0x38(%ebp)\n" /* totalDtime */
        ".Lf3e3be_0003ea29:\n"
        "addl $1, -0x44(%ebp)\n" /* line 1342 | i */
        "movl -0x44(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x48(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3e3be_0003ec9b\n"
        ".Lf3e3be_0003ea39:\n"
        "movl -0x34(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "movl -0x44(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003ea29\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm7\n" /* line 1351 */
        "ucomiss %xmm4, %xmm7\n" /* line 1353 */
        "jp .Lf3e3be_0003ea6b\n"
        "je .Lf3e3be_0003ea29\n"
        /* { scope 9 */
        ".Lf3e3be_0003ea6b:\n"
        "movl (%ebx), %eax\n" /* line 1331 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x1c(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1332 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x30(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 1333 */
        "je .Lf3e3be_0003e9f3\n"
        "movl -0x30(%ebp), %eax\n" /* line 1342 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf3e3be_0003ea29\n"
        "movl $0, -0x2c(%ebp)\n" /* line 1337 | i */
        "movss %xmm4, -0x24(%ebp)\n" /* totalWeight */
        "movss %xmm4, -0x20(%ebp)\n" /* totalDtime */
        "jmp .Lf3e3be_0003eab3\n"
        ".Lf3e3be_0003eaa3:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 1342 | i */
        "movl -0x2c(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x30(%ebp)\n" /* animIndex, numAnims */
        "je .Lf3e3be_0003ecba\n"
        ".Lf3e3be_0003eab3:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1345 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "movl -0x2c(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* tree */
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf3e3be_0003eaa3\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm1\n" /* line 1351 */
        "ucomiss %xmm4, %xmm1\n" /* line 1353 */
        "jp .Lf3e3be_0003eae5\n"
        "je .Lf3e3be_0003eaa3\n"
        ".Lf3e3be_0003eae5:\n"
        "movl %ebx, %eax\n" /* line 1356 | tree */
        "movss %xmm1, -0x108(%ebp)\n"
        "movss %xmm2, -0x118(%ebp)\n"
        "movss %xmm3, -0x128(%ebp)\n"
        "movss %xmm4, -0x138(%ebp)\n"
        "movss %xmm5, -0x148(%ebp)\n"
        "movss %xmm6, -0x158(%ebp)\n"
        "movss %xmm7, -0x168(%ebp)\n"
        "calll XAnimGetAverageRateFrequency\n"
        "movss -0x108(%ebp), %xmm1\n" /* line 1357 */
        "movss -0x118(%ebp), %xmm2\n"
        "movss -0x128(%ebp), %xmm3\n"
        "movss -0x138(%ebp), %xmm4\n"
        "movss -0x148(%ebp), %xmm5\n"
        "movss -0x158(%ebp), %xmm6\n"
        "movss -0x168(%ebp), %xmm7\n"
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003eb67\n"
        "je .Lf3e3be_0003ecd9\n"
        ".Lf3e3be_0003eb67:\n"
        "movss -0x24(%ebp), %xmm4\n" /* line 1360 | totalWeight */
        "addss %xmm1, %xmm4\n"
        "movss %xmm4, -0x24(%ebp)\n" /* totalWeight */
        "mulss %xmm0, %xmm1\n" /* line 1361 */
        "movl -0x28(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm1\n"
        "addss -0x20(%ebp), %xmm1\n" /* totalDtime */
        "movss %xmm1, -0x20(%ebp)\n" /* totalDtime */
        "pxor %xmm4, %xmm4\n"
        "jmp .Lf3e3be_0003eaa3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3e3be_0003eb94:\n"
        "movaps %xmm4, %xmm0\n" /* line 1364 */
        /* } scope */
        "addl $0x15c, %esp\n" /* line 1365 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numAnims, info, weight, totalWeight, ... */
        ".Lf3e3be_0003eba2:\n"
        "ucomiss %xmm4, %xmm6\n" /* line 1364 */
        "jp .Lf3e3be_0003eba9\n"
        "je .Lf3e3be_0003eb94\n"
        ".Lf3e3be_0003eba9:\n"
        "movss -0xe8(%ebp), %xmm0\n" /* totalDtime */
        "divss %xmm6, %xmm0\n"
        /* } scope */
        "addl $0x15c, %esp\n" /* line 1365 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numAnims, info, weight, totalWeight, ... */
        /* { scope 2: numAnims, i, info, weight, ... */
        ".Lf3e3be_0003ebc0:\n"
        "movss -0xd4(%ebp), %xmm0\n" /* line 1364 | totalWeight */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003ebd3\n"
        "je .Lf3e3be_0003e46a\n"
        ".Lf3e3be_0003ebd3:\n"
        "movss -0xd0(%ebp), %xmm0\n" /* totalDtime */
        "divss -0xd4(%ebp), %xmm0\n" /* totalWeight */
        "jmp .Lf3e3be_0003e438\n"
        /* { scope 3: numAnims, i, info, weight, ... */
        ".Lf3e3be_0003ebe8:\n"
        "movss -0xb8(%ebp), %xmm0\n" /* totalWeight */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003ebfb\n"
        "je .Lf3e3be_0003e549\n"
        ".Lf3e3be_0003ebfb:\n"
        "movss -0xb4(%ebp), %xmm0\n" /* totalDtime */
        "divss -0xb8(%ebp), %xmm0\n" /* totalWeight */
        "jmp .Lf3e3be_0003e507\n"
        /* { scope 4: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003ec10:\n"
        "movss -0x9c(%ebp), %xmm0\n" /* totalWeight */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003ec23\n"
        "je .Lf3e3be_0003e630\n"
        ".Lf3e3be_0003ec23:\n"
        "movss -0x98(%ebp), %xmm0\n" /* totalDtime */
        "divss -0x9c(%ebp), %xmm0\n" /* totalWeight */
        "jmp .Lf3e3be_0003e5ee\n"
        /* { scope 5: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003ec38:\n"
        "movss -0x84(%ebp), %xmm0\n" /* totalWeight */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003ec4b\n"
        "je .Lf3e3be_0003e727\n"
        ".Lf3e3be_0003ec4b:\n"
        "movss -0x80(%ebp), %xmm0\n" /* totalDtime */
        "divss -0x84(%ebp), %xmm0\n" /* totalWeight */
        "jmp .Lf3e3be_0003e6e5\n"
        /* { scope 6: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003ec5d:\n"
        "movss -0x6c(%ebp), %xmm0\n" /* totalWeight */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003ec6d\n"
        "je .Lf3e3be_0003e80a\n"
        ".Lf3e3be_0003ec6d:\n"
        "movss -0x68(%ebp), %xmm0\n" /* totalDtime */
        "divss -0x6c(%ebp), %xmm0\n" /* totalWeight */
        "jmp .Lf3e3be_0003e7d6\n"
        /* { scope 7: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003ec7c:\n"
        "movss -0x54(%ebp), %xmm0\n" /* totalWeight */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003ec8c\n"
        "je .Lf3e3be_0003e8c9\n"
        ".Lf3e3be_0003ec8c:\n"
        "movss -0x50(%ebp), %xmm0\n" /* totalDtime */
        "divss -0x54(%ebp), %xmm0\n" /* totalWeight */
        "jmp .Lf3e3be_0003e89e\n"
        /* { scope 8: numAnims, i, info, totalWeight, ... */
        ".Lf3e3be_0003ec9b:\n"
        "movss -0x3c(%ebp), %xmm0\n" /* totalWeight */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003ecab\n"
        "je .Lf3e3be_0003e979\n"
        ".Lf3e3be_0003ecab:\n"
        "movss -0x38(%ebp), %xmm0\n" /* totalDtime */
        "divss -0x3c(%ebp), %xmm0\n" /* totalWeight */
        "jmp .Lf3e3be_0003e94e\n"
        /* { scope 9 */
        ".Lf3e3be_0003ecba:\n"
        "movss -0x24(%ebp), %xmm0\n" /* totalWeight */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf3e3be_0003ecca\n"
        "je .Lf3e3be_0003ea29\n"
        ".Lf3e3be_0003ecca:\n"
        "movss -0x20(%ebp), %xmm0\n" /* totalDtime */
        "divss -0x24(%ebp), %xmm0\n" /* totalWeight */
        "jmp .Lf3e3be_0003e9fe\n"
        ".Lf3e3be_0003ecd9:\n"
        "pxor %xmm4, %xmm4\n"
        "jmp .Lf3e3be_0003eaa3\n"
    );
}

/* line 3622 */
__attribute__((naked))
void XAnimClearTreeGoalWeights(XAnimTree *tree, unsigned int animIndex, float blendTime)
{
    __asm__ __volatile__ (
        ".Lf3ece2_0003ece2:\n"
        "pushl %ebp\n" /* line 3622 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* animIndex */
        /* { scope 1: numAnims, i, anim */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f3ee\n"
        /* { scope 2: numAnims, i, anim */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003ed1f\n"
        "je .Lf3ece2_0003f408\n"
        ".Lf3ece2_0003ed1f:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003ed29:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "je .Lf3ece2_0003f3f6\n"
        /* { scope 3: numAnims, i, anim */
        ".Lf3ece2_0003ed3e:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3ece2_0003f41c\n"
        ".Lf3ece2_0003ed4b:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3637 */
        "movl %eax, -0x78(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3638 */
        "jle .Lf3ece2_0003f3ee\n"
        "movl $0, -0x74(%ebp)\n" /* i */
        "movl -0x74(%ebp), %esi\n" /* i, animIndex */
        ".Lf3ece2_0003ed78:\n"
        "movl -0x70(%ebp), %edx\n" /* line 3639 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 2: numAnims, i, anim */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f3af\n"
        /* { scope 3: numAnims, i, anim */
        /* { scope 4: numAnims, i, anim */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003edb9\n"
        "jne .Lf3ece2_0003edb9\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003edc3\n"
        ".Lf3ece2_0003edb9:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003edc3:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3ece2_0003eddd\n"
        "jp .Lf3ece2_0003eddd\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 5: numAnims, i, anim */
        ".Lf3ece2_0003eddd:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003edf7\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        ".Lf3ece2_0003edf7:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x64(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3637 */
        "movl %eax, -0x6c(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3638 */
        "jle .Lf3ece2_0003f3af\n"
        "movl $0, -0x68(%ebp)\n" /* i */
        "movl -0x68(%ebp), %esi\n" /* i, animIndex */
        ".Lf3ece2_0003ee24:\n"
        "movl -0x64(%ebp), %edx\n" /* line 3639 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 3: numAnims, i, anim */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f386\n"
        /* { scope 4: numAnims, i, anim */
        /* { scope 5: numAnims, i, anim */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003ee65\n"
        "jne .Lf3ece2_0003ee65\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003ee6f\n"
        ".Lf3ece2_0003ee65:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003ee6f:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3ece2_0003ee89\n"
        "jp .Lf3ece2_0003ee89\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 6: numAnims, i, anim */
        ".Lf3ece2_0003ee89:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3ece2_0003f3d8\n"
        ".Lf3ece2_0003ee96:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x58(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3637 */
        "movl %eax, -0x60(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3638 */
        "jle .Lf3ece2_0003f386\n"
        "movl $0, -0x5c(%ebp)\n" /* i */
        "movl -0x5c(%ebp), %esi\n" /* i, animIndex */
        ".Lf3ece2_0003eec3:\n"
        "movl -0x58(%ebp), %edx\n" /* line 3639 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 4: numAnims, i, anim */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f35d\n"
        /* { scope 5: numAnims, i, anim */
        /* { scope 6: numAnims, i, anim */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003ef04\n"
        "jne .Lf3ece2_0003ef04\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003ef0e\n"
        ".Lf3ece2_0003ef04:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003ef0e:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3ece2_0003ef28\n"
        "jp .Lf3ece2_0003ef28\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 7: numAnims, i, anim */
        ".Lf3ece2_0003ef28:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3ece2_0003f3c2\n"
        ".Lf3ece2_0003ef35:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3637 */
        "movl %eax, -0x54(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3638 */
        "jle .Lf3ece2_0003f35d\n"
        "movl $0, -0x50(%ebp)\n" /* i */
        "movl -0x50(%ebp), %esi\n" /* i, animIndex */
        ".Lf3ece2_0003ef62:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 3639 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 5: numAnims, i, anim */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f334\n"
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: numAnims, i, anim */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003efa3\n"
        "jne .Lf3ece2_0003efa3\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003efad\n"
        ".Lf3ece2_0003efa3:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003efad:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3ece2_0003efc7\n"
        "jp .Lf3ece2_0003efc7\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 8 */
        ".Lf3ece2_0003efc7:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3ece2_0003f399\n"
        ".Lf3ece2_0003efd4:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x40(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3637 */
        "movl %eax, -0x48(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3638 */
        "jle .Lf3ece2_0003f334\n"
        "movl $0, -0x44(%ebp)\n" /* i */
        "movl -0x44(%ebp), %esi\n" /* i, animIndex */
        ".Lf3ece2_0003f001:\n"
        "movl -0x40(%ebp), %edx\n" /* line 3639 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 6: numAnims, i, anim */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f30b\n"
        /* { scope 7: numAnims, i, anim */
        /* { scope 8 */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003f042\n"
        "jne .Lf3ece2_0003f042\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003f04c\n"
        ".Lf3ece2_0003f042:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003f04c:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3ece2_0003f066\n"
        "jp .Lf3ece2_0003f066\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 9 */
        ".Lf3ece2_0003f066:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3ece2_0003f370\n"
        ".Lf3ece2_0003f073:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3637 */
        "movl %eax, -0x3c(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3638 */
        "jle .Lf3ece2_0003f30b\n"
        "movl $0, -0x38(%ebp)\n" /* i */
        "movl -0x38(%ebp), %esi\n" /* i, animIndex */
        ".Lf3ece2_0003f0a0:\n"
        "movl -0x34(%ebp), %edx\n" /* line 3639 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 7: numAnims, i, anim */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f2f8\n"
        /* { scope 8 */
        /* { scope 9 */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003f0e1\n"
        "jne .Lf3ece2_0003f0e1\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003f0eb\n"
        ".Lf3ece2_0003f0e1:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003f0eb:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3ece2_0003f105\n"
        "jp .Lf3ece2_0003f105\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 10 */
        ".Lf3ece2_0003f105:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3ece2_0003f347\n"
        ".Lf3ece2_0003f112:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3637 */
        "movl %eax, -0x30(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3638 */
        "jle .Lf3ece2_0003f2f8\n"
        "movl $0, -0x2c(%ebp)\n" /* i */
        "movl -0x2c(%ebp), %esi\n" /* i, animIndex */
        ".Lf3ece2_0003f13f:\n"
        "movl -0x28(%ebp), %edx\n" /* line 3639 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 8 */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f2e5\n"
        /* { scope 9 */
        /* { scope 10 */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003f180\n"
        "jne .Lf3ece2_0003f180\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003f18a\n"
        ".Lf3ece2_0003f180:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003f18a:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3ece2_0003f1a4\n"
        "jp .Lf3ece2_0003f1a4\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 11 */
        ".Lf3ece2_0003f1a4:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3ece2_0003f31e\n"
        ".Lf3ece2_0003f1b1:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3637 */
        "movl %eax, -0x24(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3638 */
        "jle .Lf3ece2_0003f2e5\n"
        "movl $0, -0x20(%ebp)\n" /* i */
        "movl -0x20(%ebp), %esi\n" /* i, animIndex */
        "jmp .Lf3ece2_0003f20f\n"
        /* { scope 9 */
        /* { scope 10 */
        /* { scope 11 */
        /* { scope 12 */
        ".Lf3ece2_0003f1e0:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edi\n" /* anim */
        "movzwl 0xc(%eax), %esi\n" /* line 3637 | animIndex */
        "testl %esi, %esi\n" /* line 3638 | animIndex */
        "jg .Lf3ece2_0003f2ab\n"
        /* } scope */
        ".Lf3ece2_0003f1fd:\n"
        "addl $1, -0x20(%ebp)\n" /* i */
        "movl -0x20(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x24(%ebp)\n" /* numAnims */
        "je .Lf3ece2_0003f2e5\n"
        ".Lf3ece2_0003f20d:\n"
        "movl %edx, %esi\n" /* animIndex */
        ".Lf3ece2_0003f20f:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 3639 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 9 */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f1fd\n"
        /* { scope 10 */
        /* { scope 11 */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3ece2_0003f24c\n"
        "jne .Lf3ece2_0003f24c\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003f256\n"
        ".Lf3ece2_0003f24c:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3ece2_0003f256:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3ece2_0003f270\n"
        "jp .Lf3ece2_0003f270\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 12 */
        ".Lf3ece2_0003f270:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3ece2_0003f1e0\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edi\n" /* anim */
        "movzwl 0xc(%eax), %esi\n" /* line 3637 | animIndex */
        "testl %esi, %esi\n" /* line 3638 | animIndex */
        "jle .Lf3ece2_0003f1fd\n"
        ".Lf3ece2_0003f2ab:\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3ece2_0003f2ad:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3639 | blendTime */
        "movss %xmm0, 8(%esp)\n"
        "movzwl 6(%edi), %eax\n" /* anim */
        "leal (%ebx, %eax), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* tree */
        "movl %eax, (%esp)\n"
        "calll XAnimClearTreeGoalWeights\n"
        "addl $1, %ebx\n" /* line 3638 | i */
        "cmpl %ebx, %esi\n" /* i, animIndex */
        "jne .Lf3ece2_0003f2ad\n"
        /* } scope */
        "addl $1, -0x20(%ebp)\n" /* i */
        "movl -0x20(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x24(%ebp)\n" /* numAnims */
        "jne .Lf3ece2_0003f20d\n"
        /* } scope */
        ".Lf3ece2_0003f2e5:\n"
        "addl $1, -0x2c(%ebp)\n" /* i */
        "movl -0x2c(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x30(%ebp)\n" /* numAnims */
        "je .Lf3ece2_0003f2f8\n"
        "movl %eax, %esi\n" /* animIndex */
        "jmp .Lf3ece2_0003f13f\n"
        /* } scope */
        ".Lf3ece2_0003f2f8:\n"
        "addl $1, -0x38(%ebp)\n" /* i */
        "movl -0x38(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x3c(%ebp)\n" /* numAnims */
        "je .Lf3ece2_0003f30b\n"
        "movl %edx, %esi\n" /* animIndex */
        "jmp .Lf3ece2_0003f0a0\n"
        /* } scope */
        ".Lf3ece2_0003f30b:\n"
        "addl $1, -0x44(%ebp)\n" /* i */
        "movl -0x44(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x48(%ebp)\n" /* numAnims */
        "je .Lf3ece2_0003f334\n"
        "movl %eax, %esi\n" /* animIndex */
        "jmp .Lf3ece2_0003f001\n"
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: numAnims, i, anim */
        /* { scope 8 */
        /* { scope 9 */
        /* { scope 10 */
        /* { scope 11 */
        ".Lf3ece2_0003f31e:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3ece2_0003f1b1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3ece2_0003f334:\n"
        "addl $1, -0x50(%ebp)\n" /* line 3638 | i */
        "movl -0x50(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x54(%ebp)\n" /* numAnims */
        "je .Lf3ece2_0003f35d\n"
        "movl %edx, %esi\n" /* animIndex */
        "jmp .Lf3ece2_0003ef62\n"
        /* { scope 5: numAnims, i, anim */
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: numAnims, i, anim */
        /* { scope 8 */
        /* { scope 9 */
        /* { scope 10 */
        ".Lf3ece2_0003f347:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3ece2_0003f112\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3ece2_0003f35d:\n"
        "addl $1, -0x5c(%ebp)\n" /* line 3638 | i */
        "movl -0x5c(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x60(%ebp)\n" /* numAnims */
        "je .Lf3ece2_0003f386\n"
        "movl %eax, %esi\n" /* animIndex */
        "jmp .Lf3ece2_0003eec3\n"
        /* { scope 4: numAnims, i, anim */
        /* { scope 5: numAnims, i, anim */
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: numAnims, i, anim */
        /* { scope 8 */
        /* { scope 9 */
        ".Lf3ece2_0003f370:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3ece2_0003f073\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3ece2_0003f386:\n"
        "addl $1, -0x68(%ebp)\n" /* line 3638 | i */
        "movl -0x68(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x6c(%ebp)\n" /* numAnims */
        "je .Lf3ece2_0003f3af\n"
        "movl %edx, %esi\n" /* animIndex */
        "jmp .Lf3ece2_0003ee24\n"
        /* { scope 3: numAnims, i, anim */
        /* { scope 4: numAnims, i, anim */
        /* { scope 5: numAnims, i, anim */
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: numAnims, i, anim */
        /* { scope 8 */
        ".Lf3ece2_0003f399:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3ece2_0003efd4\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3ece2_0003f3af:\n"
        "addl $1, -0x74(%ebp)\n" /* line 3638 | i */
        "movl -0x74(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x78(%ebp)\n" /* numAnims */
        "je .Lf3ece2_0003f3ee\n"
        "movl %eax, %esi\n" /* animIndex */
        "jmp .Lf3ece2_0003ed78\n"
        /* { scope 2: numAnims, i, anim */
        /* { scope 3: numAnims, i, anim */
        /* { scope 4: numAnims, i, anim */
        /* { scope 5: numAnims, i, anim */
        /* { scope 6: numAnims, i, anim */
        /* { scope 7: numAnims, i, anim */
        ".Lf3ece2_0003f3c2:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3ece2_0003ef35\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: numAnims, i, anim */
        /* { scope 5: numAnims, i, anim */
        /* { scope 6: numAnims, i, anim */
        ".Lf3ece2_0003f3d8:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3ece2_0003ee96\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3ece2_0003f3ee:\n"
        "addl $0x7c, %esp\n" /* line 3640 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numAnims, i, anim */
        /* { scope 2: numAnims, i, anim */
        ".Lf3ece2_0003f3f6:\n"
        "jp .Lf3ece2_0003ed3e\n" /* line 3615 */
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        "jmp .Lf3ece2_0003ed3e\n"
        ".Lf3ece2_0003f408:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3ece2_0003ed29\n"
        "jmp .Lf3ece2_0003ed1f\n"
        /* { scope 3: numAnims, i, anim */
        ".Lf3ece2_0003f41c:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3ece2_0003ed4b\n"
    );
}

/* line 3643 */
__attribute__((naked))
void XAnimClearTreeGoalWeightsStrict(XAnimTree *tree, unsigned int animIndex, float blendTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3643 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 3652 | tree */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* animIndex */
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 3653 */
        "movl %eax, -0x24(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3654 */
        "jle .Lf3f432_0003f56c\n"
        "movl $0, -0x20(%ebp)\n" /* i */
        "movl -0x20(%ebp), %esi\n" /* i, animIndex */
        "jmp .Lf3f432_0003f496\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf3f432_0003f467:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edi\n" /* anim */
        "movzwl 0xc(%eax), %esi\n" /* line 3637 | animIndex */
        "testl %esi, %esi\n" /* line 3638 | animIndex */
        "jg .Lf3f432_0003f532\n"
        /* } scope */
        ".Lf3f432_0003f484:\n"
        "addl $1, -0x20(%ebp)\n" /* line 3654 | i */
        "movl -0x20(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x24(%ebp)\n" /* numAnims */
        "je .Lf3f432_0003f56c\n"
        ".Lf3f432_0003f494:\n"
        "movl %edx, %esi\n" /* animIndex */
        ".Lf3f432_0003f496:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 3655 | anim */
        "movzwl 6(%edx), %eax\n"
        "addl %eax, %esi\n" /* animIndex */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 3631 | tree */
        "movzwl 8(%edx, %esi, 2), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3f432_0003f484\n"
        /* { scope 3 */
        /* { scope 4 */
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n"
        "leal 0xc(%ebx), %eax\n" /* line 3601 */
        "pxor %xmm1, %xmm1\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm1\n"
        "jp .Lf3f432_0003f4d3\n"
        "jne .Lf3f432_0003f4d3\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss 0x10(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3f432_0003f4dd\n"
        ".Lf3f432_0003f4d3:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3610 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        ".Lf3f432_0003f4dd:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movss 0x10(%ebp), %xmm0\n" /* line 3615 | blendTime */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf3f432_0003f4f7\n"
        "jp .Lf3f432_0003f4f7\n"
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 5 */
        ".Lf3f432_0003f4f7:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3f432_0003f467\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 3636 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edi\n" /* anim */
        "movzwl 0xc(%eax), %esi\n" /* line 3637 | animIndex */
        "testl %esi, %esi\n" /* line 3638 | animIndex */
        "jle .Lf3f432_0003f484\n"
        ".Lf3f432_0003f532:\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3f432_0003f534:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3639 | blendTime */
        "movss %xmm0, 8(%esp)\n"
        "movzwl 6(%edi), %eax\n" /* anim */
        "leal (%ebx, %eax), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* tree */
        "movl %eax, (%esp)\n"
        "calll XAnimClearTreeGoalWeights\n"
        "addl $1, %ebx\n" /* line 3638 | i */
        "cmpl %ebx, %esi\n" /* i, animIndex */
        "jne .Lf3f432_0003f534\n"
        /* } scope */
        "addl $1, -0x20(%ebp)\n" /* line 3654 | i */
        "movl -0x20(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x24(%ebp)\n" /* numAnims */
        "jne .Lf3f432_0003f494\n"
        /* } scope */
        ".Lf3f432_0003f56c:\n"
        "addl $0x2c, %esp\n" /* line 3656 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2233 */
static __attribute__((naked))
void XAnimProcessServerNotify(const XAnimTree *tree, XAnimInfo *info, float time, XAnimTree *tree_3, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, int bRestart)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2233 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x28(%ebp)\n" /* blendTime */
        "movl %edx, -0x2c(%ebp)\n" /* parentAnim */
        "movss %xmm0, -0x30(%ebp)\n"
        /* { scope 1 */
        "cmpw $0, 4(%eax)\n" /* line 2242 */
        "je .Lf3f576_0003f607\n"
        "cmpw $0, 4(%edx)\n" /* line 2244 */
        "je .Lf3f576_0003f607\n"
        "movss 0xc(%edx), %xmm1\n" /* line 2247 */
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "ucomiss %xmm2, %xmm1\n"
        "je .Lf3f576_0003f743\n"
        ".Lf3f576_0003f5ae:\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 2254 | parentAnim, i */
        "cmpw $0, 2(%ebx)\n" /* i */
        "js .Lf3f576_0003f818\n"
        ".Lf3f576_0003f5bc:\n"
        "cmpw $0, (%ecx)\n" /* line 2270 | anim */
        "je .Lf3f576_0003f6ba\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 2273 | parentAnim, i */
        "movzwl (%ebx), %edx\n" /* i */
        "movl -0x28(%ebp), %ecx\n" /* blendTime, anim */
        "movl (%ecx), %eax\n" /* anim */
        "leal 0xc(%eax, %edx, 8), %ecx\n" /* anim */
        "movl 4(%ecx), %ecx\n" /* line 2278 | anim */
        "movl %ecx, -0x24(%ebp)\n" /* anim, parts */
        "movswl 2(%ebx), %edi\n" /* line 2284 | i, notifyIndex */
        "movl 0x1c(%ecx), %eax\n" /* line 2287 | anim */
        "leal (%eax, %edi, 8), %esi\n" /* notifyInfoIndex */
        "ucomiss -0x30(%ebp), %xmm1\n" /* line 2289 */
        "jbe .Lf3f576_0003f6d7\n"
        ".Lf3f576_0003f5ef:\n"
        "movss 4(%esi), %xmm0\n" /* line 2291 | notifyInfoIndex */
        "movss -0x30(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf3f576_0003f888\n"
        "ucomiss %xmm0, %xmm1\n" /* line 2305 */
        "jbe .Lf3f576_0003f60f\n"
        /* } scope */
        ".Lf3f576_0003f607:\n"
        "addl $0x3c, %esp\n" /* line 2368 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3f576_0003f60f:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2313 | parentAnim */
        "movzwl 4(%eax), %ebx\n" /* notifyName */
        /* { scope 2 */
        "movzwl (%esi), %eax\n" /* line 2058 | notifyInfoIndex */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "movl $1, 0xc(%esp)\n" /* line 2059 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* blendTime */
        "movzwl 4(%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_NotifyNum\n"
        /* } scope */
        "addl $8, %esi\n" /* line 2314 | notifyInfoIndex */
        "addl $1, %edi\n" /* line 2315 | notifyIndex */
        "movl -0x24(%ebp), %ecx\n" /* line 2310 | parts, anim */
        "movzbl 0xc(%ecx), %eax\n" /* anim */
        "cmpl %eax, %edi\n" /* notifyIndex */
        "jl .Lf3f576_0003f60f\n"
        "movl 0x1c(%ecx), %esi\n" /* line 2321 | anim, notifyInfoIndex */
        "movss -0x30(%ebp), %xmm0\n"
        "ucomiss 4(%esi), %xmm0\n" /* notifyInfoIndex */
        "jbe .Lf3f576_0003f607\n"
        "leal 0xc(%esi), %edi\n" /* notifyInfoIndex, notifyIndex */
        ".Lf3f576_0003f669:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2324 | parentAnim */
        "movzwl 4(%eax), %ebx\n" /* notifyName */
        /* { scope 2 */
        "movzwl (%esi), %eax\n" /* line 2058 | notifyInfoIndex */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "movl $1, 0xc(%esp)\n" /* line 2059 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* blendTime */
        "movzwl 4(%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_NotifyNum\n"
        /* } scope */
        "addl $8, %esi\n" /* line 2321 | notifyInfoIndex */
        "movss (%edi), %xmm0\n" /* notifyIndex */
        "addl $8, %edi\n" /* notifyIndex */
        "movss -0x30(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf3f576_0003f669\n"
        "jmp .Lf3f576_0003f607\n"
        ".Lf3f576_0003f6ba:\n"
        "movl -0x2c(%ebp), %ebx\n" /* parentAnim, notifyName */
        "movl 4(%ecx), %ecx\n" /* line 2278 | anim */
        "movl %ecx, -0x24(%ebp)\n" /* anim, parts */
        "movswl 2(%ebx), %edi\n" /* line 2284 | i, notifyIndex */
        "movl 0x1c(%ecx), %eax\n" /* line 2287 | anim */
        "leal (%eax, %edi, 8), %esi\n" /* notifyInfoIndex */
        "ucomiss -0x30(%ebp), %xmm1\n" /* line 2289 */
        "ja .Lf3f576_0003f5ef\n"
        ".Lf3f576_0003f6d7:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 2333 */
        "ucomiss %xmm2, %xmm0\n"
        "jne .Lf3f576_0003f78b\n"
        "jp .Lf3f576_0003f78b\n"
        "ucomiss 4(%esi), %xmm1\n" /* line 2337 | notifyInfoIndex */
        "ja .Lf3f576_0003f607\n"
        ".Lf3f576_0003f6f5:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2345 | parentAnim */
        "movzwl 4(%eax), %ebx\n" /* notifyName */
        /* { scope 2 */
        "movzwl (%esi), %eax\n" /* line 2058 | notifyInfoIndex */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "movl $1, 0xc(%esp)\n" /* line 2059 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* blendTime */
        "movzwl 4(%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_NotifyNum\n"
        /* } scope */
        "addl $8, %esi\n" /* line 2346 | notifyInfoIndex */
        "addl $1, %edi\n" /* line 2347 | notifyIndex */
        "movl -0x24(%ebp), %ecx\n" /* line 2342 | parts, anim */
        "movzbl 0xc(%ecx), %eax\n" /* anim */
        "cmpl %eax, %edi\n" /* notifyIndex */
        "jl .Lf3f576_0003f6f5\n"
        "jmp .Lf3f576_0003f607\n"
        ".Lf3f576_0003f743:\n"
        "jp .Lf3f576_0003f5ae\n" /* line 2247 */
        ".Lf3f576_0003f749:\n"
        "movl g_end, %eax\n" /* line 2261 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "movl $1, 0xc(%esp)\n" /* line 2262 */
        "movl -0x2c(%ebp), %edx\n" /* parentAnim */
        "movzwl 4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x28(%ebp), %ecx\n" /* blendTime, anim */
        "movzwl 4(%ecx), %eax\n" /* anim */
        "subl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_NotifyNum\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2368 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3f576_0003f78b:\n"
        "movss 4(%esi), %xmm0\n" /* line 2353 | notifyInfoIndex */
        "ucomiss -0x30(%ebp), %xmm0\n"
        "jae .Lf3f576_0003f607\n"
        "ucomiss %xmm0, %xmm1\n" /* line 2356 */
        "ja .Lf3f576_0003f607\n"
        "leal 8(%esi), %ebx\n" /* line 2357 | notifyInfoIndex, notifyName */
        "movl %ebx, -0x1c(%ebp)\n" /* notifyName, anim */
        "addl $0xc, %esi\n" /* notifyInfoIndex */
        "movl %ebx, %edx\n" /* notifyName */
        "jmp .Lf3f576_0003f7b3\n"
        ".Lf3f576_0003f7b0:\n"
        "movl -0x1c(%ebp), %edx\n" /* anim */
        ".Lf3f576_0003f7b3:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2364 | parentAnim */
        "movzwl 4(%eax), %ebx\n" /* notifyName */
        /* { scope 2 */
        "movzwl -8(%edx), %eax\n" /* line 2058 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "movl $1, 0xc(%esp)\n" /* line 2059 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "movl -0x28(%ebp), %ecx\n" /* blendTime */
        "movzwl 4(%ecx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_NotifyNum\n"
        /* } scope */
        "addl $1, %edi\n" /* line 2366 | notifyIndex */
        "movl -0x24(%ebp), %ebx\n" /* line 2361 | parts, notifyName */
        "movzbl 0xc(%ebx), %eax\n" /* notifyName */
        "cmpl %eax, %edi\n" /* notifyIndex */
        "jge .Lf3f576_0003f607\n"
        "movss (%esi), %xmm0\n" /* notifyInfoIndex */
        "addl $8, -0x1c(%ebp)\n" /* anim */
        "addl $8, %esi\n" /* notifyInfoIndex */
        "movss -0x30(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf3f576_0003f7b0\n"
        "jmp .Lf3f576_0003f607\n"
        ".Lf3f576_0003f818:\n"
        "cmpw $0, (%ecx)\n" /* line 4179 */
        "jne .Lf3f576_0003f86f\n"
        "movl %ecx, %eax\n"
        /* { scope 2 */
        ".Lf3f576_0003f820:\n"
        "movl 4(%eax), %eax\n" /* line 1380 */
        "movl 0x1c(%eax), %edi\n" /* line 1389 */
        "movzbl 0xc(%eax), %edx\n" /* line 1391 */
        "testl %edx, %edx\n"
        "jg .Lf3f576_0003f8fd\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf3f576_0003f834:\n"
        "subl %edi, %eax\n" /* line 4188 | numAnims */
        "sarl $3, %eax\n"
        "movzwl %ax, %eax\n"
        "movl -0x2c(%ebp), %edx\n" /* parentAnim */
        "movw %ax, 2(%edx)\n"
        "testw %ax, %ax\n" /* line 2257 */
        "jns .Lf3f576_0003f5bc\n"
        ".Lf3f576_0003f84c:\n"
        "ucomiss -0x30(%ebp), %xmm1\n" /* line 2259 */
        "ja .Lf3f576_0003f749\n"
        "movss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jne .Lf3f576_0003f607\n"
        "jnp .Lf3f576_0003f749\n"
        "jmp .Lf3f576_0003f607\n"
        ".Lf3f576_0003f86f:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 4181 | parentAnim */
        "movzwl (%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3f576_0003f84c\n"
        "movzwl %ax, %edx\n" /* line 4183 */
        "movl -0x28(%ebp), %ebx\n" /* blendTime, info */
        "movl (%ebx), %eax\n" /* info */
        "leal 0xc(%eax, %edx, 8), %eax\n"
        "jmp .Lf3f576_0003f820\n"
        ".Lf3f576_0003f888:\n"
        "leal 8(%esi), %eax\n" /* line 2291 | notifyInfoIndex */
        "movl %eax, -0x20(%ebp)\n" /* i */
        "addl $0xc, %esi\n" /* notifyInfoIndex */
        "movl %eax, %ecx\n" /* anim */
        "jmp .Lf3f576_0003f898\n"
        ".Lf3f576_0003f895:\n"
        "movl -0x20(%ebp), %ecx\n" /* i, anim */
        ".Lf3f576_0003f898:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2297 | parentAnim */
        "movzwl 4(%edx), %ebx\n" /* notifyName */
        /* { scope 2 */
        "movzwl -8(%ecx), %eax\n" /* line 2058 */
        "movl %eax, (%esp)\n"
        "calll Scr_AddConstString\n"
        "movl $1, 0xc(%esp)\n" /* line 2059 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0, 4(%esp)\n"
        "movl -0x28(%ebp), %ebx\n" /* blendTime, i */
        "movzwl 4(%ebx), %eax\n" /* i */
        "subl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_NotifyNum\n"
        /* } scope */
        "addl $1, %edi\n" /* line 2299 | notifyIndex */
        "movl -0x24(%ebp), %edx\n" /* line 2295 | parts */
        "movzbl 0xc(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* notifyIndex */
        "jge .Lf3f576_0003f607\n"
        "movss (%esi), %xmm0\n" /* notifyInfoIndex */
        "addl $8, -0x20(%ebp)\n" /* i */
        "addl $8, %esi\n" /* notifyInfoIndex */
        "movss -0x30(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf3f576_0003f895\n"
        "jmp .Lf3f576_0003f607\n"
        /* { scope 2 */
        ".Lf3f576_0003f8fd:\n"
        "movl %edi, %ebx\n" /* line 1391 | bestNotifyInfo */
        "movss lit4_002ed62c, %xmm3\n" /* 2.0f */
        "xorl %esi, %esi\n" /* notifyInfoIndex */
        "xorl %eax, %eax\n"
        ".Lf3f576_0003f90b:\n"
        "movss 4(%ebx), %xmm0\n" /* line 1393 | bestNotifyInfo */
        "ucomiss %xmm0, %xmm1\n" /* line 1395 */
        "ja .Lf3f576_0003f91f\n"
        "ucomiss %xmm0, %xmm3\n" /* line 1397 */
        "jbe .Lf3f576_0003f91f\n"
        "movl %ebx, %eax\n" /* bestNotifyInfo */
        "movaps %xmm0, %xmm3\n"
        ".Lf3f576_0003f91f:\n"
        "addl $1, %esi\n" /* line 1391 | notifyInfoIndex */
        "addl $8, %ebx\n" /* bestNotifyInfo */
        "cmpl %esi, %edx\n" /* notifyInfoIndex */
        "jne .Lf3f576_0003f90b\n"
        "jmp .Lf3f576_0003f834\n"
        "addb %al, (%eax)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "pxor %xmm0, %xmm0\n"
        "movss 0x14(%ebp), %xmm1\n" /* goalTime */
        "movaps %xmm1, %xmm2\n"
        "cmpnltss lit4_002ed658, %xmm1\n" /* 0.0010000000474974513f */
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movss %xmm1, 0x14(%ebp)\n" /* goalTime */
        "movl 0xc(%ebp), %eax\n" /* animIndex */
        "testl %eax, %eax\n"
        "je .Lf3f576_0003f9f6\n"
        "movl 8(%ebp), %eax\n" /* tree */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* animIndex */
        "movzwl 0xe(%edx, %ecx, 8), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0xc(%eax), %ebx\n" /* bestNotifyInfo */
        "movl %ebx, -0x48(%ebp)\n" /* bestNotifyInfo */
        "movzwl 0xc(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle 0x3fdc8\n"
        "movzwl 6(%ebx), %ebx\n" /* bestNotifyInfo */
        "movl 8(%ebp), %ecx\n" /* tree */
        "leal 8(%ecx, %ebx, 2), %edx\n"
        "xorl %ecx, %ecx\n"
        "movaps %xmm0, %xmm4\n"
        "movaps %xmm0, %xmm1\n"
        "movss vec2_origin+612, %xmm2\n"
        "jmp .Lf3f576_0003f9c6\n"
        ".Lf3f576_0003f9a6:\n"
        "movaps %xmm4, %xmm0\n"
        "leal (%ebx, %ecx), %eax\n" /* bestNotifyInfo */
        "cmpl %eax, 0xc(%ebp)\n" /* animIndex */
        "je .Lf3f576_0003f9e5\n"
        ".Lf3f576_0003f9b1:\n"
        "maxss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "addl $1, %ecx\n"
        "addl $2, %edx\n"
        "cmpl %ecx, %edi\n"
        "je 0x3fdce\n"
        ".Lf3f576_0003f9c6:\n"
        "movzwl (%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf3f576_0003f9a6\n"
        "movzwl %ax, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+32(, %eax, 8), %xmm0\n"
        "leal (%ebx, %ecx), %eax\n" /* bestNotifyInfo */
        "cmpl %eax, 0xc(%ebp)\n" /* animIndex */
        "jne .Lf3f576_0003f9b1\n"
        ".Lf3f576_0003f9e5:\n"
        "movss 0x14(%ebp), %xmm3\n" /* goalTime */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "andps %xmm2, %xmm0\n"
        "jmp .Lf3f576_0003f9b1\n"
        ".Lf3f576_0003f9f6:\n"
        "movaps %xmm1, %xmm0\n"
        "movl $0, 4(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* bRestart */
        "movl %eax, (%esp)\n"
        "xorl %ecx, %ecx\n"
    );
}

/* line 3719 */
__attribute__((naked))
int XAnimSetCompleteGoalWeightKnobAll(XAnimTree *tree, unsigned int animIndex, unsigned int rootIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, int bRestart)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3719 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: parentAnim, numAnims, i, numAnims, ... */
        "pxor %xmm0, %xmm0\n" /* line 3727 */
        "movss 0x14(%ebp), %xmm1\n" /* goalWeight */
        "movaps %xmm1, %xmm2\n"
        "cmpnltss lit4_002ed658, %xmm1\n" /* 0.0010000000474974513f */
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movss %xmm1, 0x14(%ebp)\n" /* goalWeight */
        /* { scope 2: blendTime, blendTime */
        "movl 0xc(%ebp), %eax\n" /* line 3675 | animIndex */
        "testl %eax, %eax\n"
        "je .Lf3f930_0003f9f6\n"
        "movl 8(%ebp), %eax\n" /* line 3678 | tree */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* line 3680 | animIndex */
        "movzwl 0xe(%edx, %ecx, 8), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0xc(%eax), %ebx\n" /* info */
        "movl %ebx, -0x48(%ebp)\n" /* info, parentAnim */
        "movzwl 0xc(%eax), %edi\n" /* line 3684 | numAnims */
        "testl %edi, %edi\n" /* line 3685 | numAnims */
        "jle .Lf3f930_0003fdc8\n"
        "movzwl 6(%ebx), %ebx\n" /* line 3688 | info */
        "movl 8(%ebp), %ecx\n" /* tree */
        "leal 8(%ecx, %ebx, 2), %edx\n"
        "xorl %ecx, %ecx\n"
        "movaps %xmm0, %xmm4\n"
        "movaps %xmm0, %xmm1\n"
        "movss vec2_origin+612, %xmm2\n"
        "jmp .Lf3f930_0003f9c6\n"
        ".Lf3f930_0003f9a6:\n"
        "movaps %xmm4, %xmm0\n" /* line 3690 */
        "leal (%ebx, %ecx), %eax\n" /* line 3692 | info */
        "cmpl %eax, 0xc(%ebp)\n" /* animIndex */
        "je .Lf3f930_0003f9e5\n"
        ".Lf3f930_0003f9b1:\n"
        "maxss %xmm1, %xmm0\n" /* line 3693 */
        "movaps %xmm0, %xmm1\n"
        "addl $1, %ecx\n" /* line 3685 */
        "addl $2, %edx\n"
        "cmpl %ecx, %edi\n" /* numAnims */
        "je .Lf3f930_0003fdce\n"
        ".Lf3f930_0003f9c6:\n"
        "movzwl (%edx), %eax\n" /* line 3688 */
        "testw %ax, %ax\n" /* line 3690 */
        "je .Lf3f930_0003f9a6\n"
        "movzwl %ax, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+32(, %eax, 8), %xmm0\n"
        "leal (%ebx, %ecx), %eax\n" /* line 3692 | info */
        "cmpl %eax, 0xc(%ebp)\n" /* animIndex */
        "jne .Lf3f930_0003f9b1\n"
        ".Lf3f930_0003f9e5:\n"
        "movss 0x14(%ebp), %xmm3\n" /* line 54 | goalWeight */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "andps %xmm2, %xmm0\n"
        "jmp .Lf3f930_0003f9b1\n"
        ".Lf3f930_0003f9f6:\n"
        "movaps %xmm1, %xmm0\n"
        /* } scope */
        ".Lf3f930_0003f9f9:\n"
        "movl $0, 4(%esp)\n" /* line 3731 */
        "movl 0x20(%ebp), %eax\n" /* notifyName */
        "movl %eax, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movss 0x1c(%ebp), %xmm2\n" /* rate */
        "movss 0x18(%ebp), %xmm1\n" /* goalTime */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        "movl 8(%ebp), %eax\n" /* tree */
        "calll XAnimSetGoalWeightInternal\n"
        "movl %eax, -0x4c(%ebp)\n" /* error */
        "movl 0xc(%ebp), %eax\n" /* line 4239 | animIndex */
        "testl %eax, %eax\n"
        "je .Lf3f930_0003fa44\n"
        "movl 8(%ebp), %ebx\n" /* line 4241 | tree, info */
        "movl (%ebx), %ecx\n" /* info */
        "movl 0xc(%ebp), %eax\n" /* animIndex */
        "movzwl 0xe(%ecx, %eax, 8), %ebx\n" /* info */
        "movl 8(%ebp), %edx\n" /* line 4243 | tree */
        "cmpw $0, 8(%edx, %ebx, 2)\n"
        "je .Lf3f930_0003fe97\n"
        ".Lf3f930_0003fa44:\n"
        "movl 0x24(%ebp), %eax\n" /* line 3735 | bRestart */
        "testl %eax, %eax\n"
        "je .Lf3f930_0003faa5\n"
        /* { scope 2: blendTime, blendTime */
        "movl 0xc(%ebp), %esi\n" /* line 4200 | animIndex */
        "testl %esi, %esi\n"
        "je .Lf3f930_0003fd64\n"
        "movl 8(%ebp), %ebx\n" /* line 4205 | tree, info */
        "movl (%ebx), %ecx\n" /* info */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        "jmp .Lf3f930_0003fa63\n"
        ".Lf3f930_0003fa60:\n"
        "movl 8(%ebp), %ebx\n" /* tree, info */
        ".Lf3f930_0003fa63:\n"
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* line 4204 | info */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* info */
        "leal (%ecx, %edx, 8), %eax\n" /* line 4205 */
        "leal 0xc(%eax), %esi\n"
        "cmpw $0, 0xc(%eax)\n" /* line 4206 */
        "je .Lf3f930_0003fa89\n"
        "testb $4, 4(%esi)\n" /* line 4208 */
        "jne .Lf3f930_0003ffdb\n"
        ".Lf3f930_0003fa89:\n"
        "movzwl 0xe(%ecx, %edx, 8), %eax\n" /* line 4200 */
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n"
        "jne .Lf3f930_0003fa60\n"
        "movl 0xc(%ebp), %eax\n" /* line 4224 | animIndex */
        "cmpw $0, 0xc(%ecx, %eax, 8)\n"
        "je .Lf3f930_0003fd78\n"
        /* } scope */
        ".Lf3f930_0003faa5:\n"
        "movl 0xc(%ebp), %eax\n" /* line 3740 | animIndex */
        "testl %eax, %eax\n"
        "je .Lf3f930_0003fd52\n"
        ".Lf3f930_0003fab0:\n"
        "movl 8(%ebp), %eax\n" /* line 3745 | tree */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* animIndex */
        "movzwl 0xe(%edx, %ecx, 8), %eax\n"
        "movzwl %ax, %edi\n" /* numAnims */
        "cmpl %edi, 0x10(%ebp)\n" /* line 3746 | numAnims, rootIndex */
        "je .Lf3f930_0003fc7d\n"
        /* { scope 2: blendTime, blendTime */
        ".Lf3f930_0003fac9:\n"
        "testw %ax, %ax\n" /* line 3675 */
        "je .Lf3f930_0003fb98\n"
        "movzwl 0xe(%edx, %edi, 8), %eax\n" /* line 3680 */
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* parentAnim */
        "movzwl 0xc(%eax), %eax\n" /* line 3684 */
        "movl %eax, -0x34(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 3685 */
        "jg .Lf3f930_0003fcbc\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm1\n"
        ".Lf3f930_0003faf6:\n"
        "mulss 0x18(%ebp), %xmm1\n" /* line 3697 | goalTime */
        "movss %xmm1, -0x2c(%ebp)\n" /* blendTime */
        "movl -0x34(%ebp), %eax\n" /* line 3699 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf3f930_0003fb98\n"
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "ucomiss %xmm4, %xmm1\n" /* line 3596 */
        "jp .Lf3f930_0003fb16\n"
        "je .Lf3f930_00040150\n"
        ".Lf3f930_0003fb16:\n"
        "xorl %esi, %esi\n"
        "jmp .Lf3f930_0003fb22\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        ".Lf3f930_0003fb1a:\n"
        "addl $1, %esi\n" /* line 3699 */
        "cmpl -0x34(%ebp), %esi\n" /* numAnims */
        "je .Lf3f930_0003fb98\n"
        ".Lf3f930_0003fb22:\n"
        "movl -0x30(%ebp), %edx\n" /* line 3701 | parentAnim */
        "movzwl 6(%edx), %eax\n"
        "leal (%esi, %eax), %eax\n"
        "cmpl %eax, %edi\n" /* numAnims */
        "je .Lf3f930_0003fb1a\n"
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "movl 8(%ebp), %edx\n" /* line 3595 | tree */
        "movzwl 8(%edx, %eax, 2), %eax\n"
        "testw %ax, %ax\n" /* line 3596 */
        "je .Lf3f930_0003fb1a\n"
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* line 3601 | i */
        "pxor %xmm2, %xmm2\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm2\n"
        "jne .Lf3f930_0003fc88\n"
        "jp .Lf3f930_0003fc88\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss -0x2c(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3f930_0003fb76\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 3610 | blendTime */
        "movss %xmm1, 0xc(%eax)\n"
        ".Lf3f930_0003fb76:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        /* { scope 5 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3f930_0003fca6\n"
        ".Lf3f930_0003fb8a:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $1, %esi\n" /* line 3699 */
        "cmpl -0x34(%ebp), %esi\n" /* numAnims */
        "jne .Lf3f930_0003fb22\n"
        /* } scope */
        ".Lf3f930_0003fb98:\n"
        "movl $0, 4(%esp)\n" /* line 3752 */
        "movl $0, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movss 0x18(%ebp), %xmm1\n" /* goalTime */
        "movaps %xmm2, %xmm0\n"
        "movl %edi, %edx\n" /* numAnims */
        "movl 8(%ebp), %eax\n" /* tree */
        "calll XAnimSetGoalWeightInternal\n"
        "movl 0x24(%ebp), %eax\n" /* line 3754 | bRestart */
        "testl %eax, %eax\n"
        "je .Lf3f930_0003fc5f\n"
        /* { scope 2: blendTime, blendTime */
        "testl %edi, %edi\n" /* line 4200 | numAnims */
        "je .Lf3f930_0003fd2f\n"
        "movl 8(%ebp), %ebx\n" /* line 4205 | tree, info */
        "movl (%ebx), %ecx\n" /* info */
        "movl %edi, %edx\n" /* numAnims */
        "jmp .Lf3f930_0003fbe2\n"
        ".Lf3f930_0003fbdf:\n"
        "movl 8(%ebp), %ebx\n" /* tree, info */
        ".Lf3f930_0003fbe2:\n"
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* line 4204 | info */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* info */
        "leal (%ecx, %edx, 8), %eax\n" /* line 4205 */
        "leal 0xc(%eax), %esi\n"
        "cmpw $0, 0xc(%eax)\n" /* line 4206 */
        "je .Lf3f930_0003fc08\n"
        "testb $4, 4(%esi)\n" /* line 4208 */
        "jne .Lf3f930_0003fee5\n"
        ".Lf3f930_0003fc08:\n"
        "movzwl 0xe(%ecx, %edx, 8), %eax\n" /* line 4200 */
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n"
        "jne .Lf3f930_0003fbdf\n"
        ".Lf3f930_0003fc15:\n"
        "cmpw $0, 0xc(%ecx, %edi, 8)\n" /* line 4224 */
        "jne .Lf3f930_0003fc5f\n"
        "movl 8(%ebp), %edx\n" /* line 4229 | tree, info */
        "movzwl 8(%edx, %edi, 2), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "leal 0xc(%edx), %eax\n" /* line 1914 */
        "pxor %xmm4, %xmm4\n" /* line 1916 */
        "ucomiss 0xc(%edx), %xmm4\n"
        "je .Lf3f930_0003fd39\n"
        ".Lf3f930_0003fc40:\n"
        "movl $0, (%eax)\n" /* line 1919 */
        "movw $0, 8(%eax)\n" /* line 1920 */
        "movl $0, 4(%eax)\n" /* line 1921 */
        "movw $0, 0xa(%eax)\n" /* line 1922 */
        "movw $0xffff, 2(%edx)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3f930_0003fc5f:\n"
        "testl %edi, %edi\n" /* line 3740 | numAnims */
        "je .Lf3f930_0003fd52\n"
        ".Lf3f930_0003fc67:\n"
        "movl 8(%ebp), %ebx\n" /* line 3745 | tree, info */
        "movl (%ebx), %edx\n" /* info */
        "movzwl 0xe(%edx, %edi, 8), %eax\n"
        "movzwl %ax, %edi\n" /* numAnims */
        "cmpl %edi, 0x10(%ebp)\n" /* line 3746 | numAnims, rootIndex */
        "jne .Lf3f930_0003fac9\n"
        /* } scope */
        ".Lf3f930_0003fc7d:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 3757 | error */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: parentAnim, numAnims, i, numAnims, ... */
        /* { scope 2: blendTime, blendTime */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        ".Lf3f930_0003fc88:\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 3605 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        /* { scope 5 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3f930_0003fb8a\n"
        ".Lf3f930_0003fca6:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3f930_0003fb8a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3f930_0003fcbc:\n"
        "movzwl 6(%edx), %ebx\n" /* line 3688 | info */
        "movl 8(%ebp), %eax\n" /* tree */
        "leal 8(%eax, %ebx, 2), %edx\n"
        "xorl %ecx, %ecx\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movss vec2_origin+612, %xmm2\n"
        "jmp .Lf3f930_0003fd02\n"
        ".Lf3f930_0003fce2:\n"
        "movaps %xmm4, %xmm0\n" /* line 3690 */
        "leal (%ebx, %ecx), %eax\n" /* line 3692 | info */
        "cmpl %eax, %edi\n" /* numAnims */
        "je .Lf3f930_0003fd20\n"
        ".Lf3f930_0003fcec:\n"
        "maxss %xmm1, %xmm0\n" /* line 3693 */
        "movaps %xmm0, %xmm1\n"
        "addl $1, %ecx\n" /* line 3685 */
        "addl $2, %edx\n"
        "cmpl %ecx, -0x34(%ebp)\n" /* numAnims */
        "je .Lf3f930_0003faf6\n"
        ".Lf3f930_0003fd02:\n"
        "movzwl (%edx), %eax\n" /* line 3688 */
        "testw %ax, %ax\n" /* line 3690 */
        "je .Lf3f930_0003fce2\n"
        "movzwl %ax, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movss g_xAnimInfo+32(, %eax, 8), %xmm0\n"
        "leal (%ebx, %ecx), %eax\n" /* line 3692 | info */
        "cmpl %eax, %edi\n" /* numAnims */
        "jne .Lf3f930_0003fcec\n"
        ".Lf3f930_0003fd20:\n"
        "movaps %xmm3, %xmm5\n" /* line 54 */
        "subss %xmm0, %xmm5\n"
        "movaps %xmm5, %xmm0\n"
        "andps %xmm2, %xmm0\n"
        "jmp .Lf3f930_0003fcec\n"
        ".Lf3f930_0003fd2f:\n"
        "movl 8(%ebp), %ebx\n" /* tree */
        "movl (%ebx), %ecx\n"
        "jmp .Lf3f930_0003fc15\n"
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        ".Lf3f930_0003fd39:\n"
        "jp .Lf3f930_0003fc40\n" /* line 1916 */
        "cmpw $0, 8(%eax)\n"
        "jne .Lf3f930_0003fc40\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "testl %edi, %edi\n" /* line 3740 | numAnims */
        "jne .Lf3f930_0003fc67\n"
        /* { scope 2: blendTime, blendTime */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        ".Lf3f930_0003fd52:\n"
        "movl $1, -0x4c(%ebp)\n" /* line 1924 | error */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x4c(%ebp), %eax\n" /* line 3757 | error */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf3f930_0003fd64:\n"
        "movl 8(%ebp), %ebx\n" /* tree, info */
        "movl (%ebx), %ecx\n" /* info */
        /* { scope 1: parentAnim, numAnims, i, numAnims, ... */
        /* { scope 2: blendTime, blendTime */
        "movl 0xc(%ebp), %eax\n" /* line 4224 | animIndex */
        "cmpw $0, 0xc(%ecx, %eax, 8)\n"
        "jne .Lf3f930_0003faa5\n"
        ".Lf3f930_0003fd78:\n"
        "movl 8(%ebp), %ecx\n" /* line 4229 | tree */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "leal 0xc(%edx), %eax\n" /* line 1914 */
        "pxor %xmm4, %xmm4\n" /* line 1916 */
        "ucomiss 0xc(%edx), %xmm4\n"
        "jne .Lf3f930_0003fda4\n"
        "jp .Lf3f930_0003fda4\n"
        "cmpw $0, 8(%eax)\n"
        "je .Lf3f930_0003faa5\n"
        ".Lf3f930_0003fda4:\n"
        "movl $0, (%eax)\n" /* line 1919 */
        "movw $0, 8(%eax)\n" /* line 1920 */
        "movl $0, 4(%eax)\n" /* line 1921 */
        "movw $0, 0xa(%eax)\n" /* line 1922 */
        "movw $0xffff, 2(%edx)\n" /* line 1924 */
        "jmp .Lf3f930_0003faa5\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        ".Lf3f930_0003fdc8:\n"
        "movaps %xmm0, %xmm4\n" /* line 3685 */
        "movaps %xmm0, %xmm1\n"
        ".Lf3f930_0003fdce:\n"
        "mulss 0x18(%ebp), %xmm1\n" /* line 3697 | goalTime */
        "movss %xmm1, -0x44(%ebp)\n" /* blendTime */
        "testl %edi, %edi\n" /* line 3699 | numAnims */
        "jle .Lf3f930_0003fe60\n"
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        "ucomiss %xmm4, %xmm1\n" /* line 4205 */
        "jp .Lf3f930_0003fdeb\n"
        "je .Lf3f930_000400c9\n"
        ".Lf3f930_0003fdeb:\n"
        "xorl %esi, %esi\n"
        "jmp .Lf3f930_0003fdf6\n"
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        ".Lf3f930_0003fdef:\n"
        "addl $1, %esi\n" /* line 3699 */
        "cmpl %edi, %esi\n" /* numAnims */
        "je .Lf3f930_0003fe60\n"
        ".Lf3f930_0003fdf6:\n"
        "movl -0x48(%ebp), %edx\n" /* line 3701 | parentAnim */
        "movzwl 6(%edx), %eax\n"
        "leal (%esi, %eax), %eax\n"
        "cmpl %eax, 0xc(%ebp)\n" /* animIndex */
        "je .Lf3f930_0003fdef\n"
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "movl 8(%ebp), %edx\n" /* line 3595 | tree */
        "movzwl 8(%edx, %eax, 2), %eax\n"
        "testw %ax, %ax\n" /* line 3596 */
        "je .Lf3f930_0003fdef\n"
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* line 3601 | i */
        "pxor %xmm2, %xmm2\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm2\n"
        "jne .Lf3f930_0003fe6a\n"
        "jp .Lf3f930_0003fe6a\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss -0x44(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3f930_0003fe43\n"
        "movss -0x44(%ebp), %xmm1\n" /* line 3610 | blendTime */
        "movss %xmm1, 0xc(%eax)\n"
        ".Lf3f930_0003fe43:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        /* { scope 5 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "jne .Lf3f930_0003fe84\n"
        ".Lf3f930_0003fe53:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $1, %esi\n" /* line 3699 */
        "cmpl %edi, %esi\n" /* numAnims */
        "jne .Lf3f930_0003fdf6\n"
        ".Lf3f930_0003fe60:\n"
        "movss 0x14(%ebp), %xmm0\n" /* goalWeight */
        "jmp .Lf3f930_0003f9f9\n"
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        ".Lf3f930_0003fe6a:\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 3605 | blendTime */
        "movss %xmm0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        /* { scope 5 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3f930_0003fe53\n"
        ".Lf3f930_0003fe84:\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        "jmp .Lf3f930_0003fe53\n"
        ".Lf3f930_0003fe97:\n"
        "movl 8(%ebp), %eax\n" /* tree */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3f930_0003fe9a:\n"
        "movl $0, 4(%esp)\n" /* line 4245 */
        "movl $0, (%esp)\n"
        "movl $1, %ecx\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movss 0x18(%ebp), %xmm1\n" /* goalTime */
        "pxor %xmm0, %xmm0\n"
        "movl %ebx, %edx\n" /* info */
        "calll XAnimSetGoalWeightInternal\n"
        "testl %ebx, %ebx\n" /* line 4239 | info */
        "je .Lf3f930_0003fa44\n"
        "movl 8(%ebp), %eax\n" /* line 4241 | tree */
        "movl (%eax), %ecx\n"
        "movzwl 0xe(%ecx, %ebx, 8), %ebx\n" /* info */
        "cmpw $0, 8(%eax, %ebx, 2)\n" /* line 4243 */
        "je .Lf3f930_0003fe9a\n"
        "jmp .Lf3f930_0003fa44\n"
        /* { scope 2: blendTime, blendTime */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        ".Lf3f930_0003fee5:\n"
        "leal 0xc(%ebx), %eax\n" /* line 1914 */
        "pxor %xmm4, %xmm4\n" /* line 1916 */
        "ucomiss 0xc(%ebx), %xmm4\n"
        "jne .Lf3f930_0003feff\n"
        "jp .Lf3f930_0003feff\n"
        "cmpw $0, 8(%eax)\n"
        "je .Lf3f930_0003fc67\n"
        ".Lf3f930_0003feff:\n"
        "movl $0, (%eax)\n" /* line 1919 */
        "movw $0, 8(%eax)\n" /* line 1920 */
        "movl $0, 4(%eax)\n" /* line 1921 */
        "movw $0, 0xa(%eax)\n" /* line 1922 */
        "movw $0xffff, 2(%ebx)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        "movzwl (%esi), %eax\n" /* line 4214 */
        "movl %eax, -0x28(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 4216 */
        "jle .Lf3f930_0003fc67\n"
        "movl $0, -0x24(%ebp)\n" /* i */
        "jmp .Lf3f930_0003ff45\n"
        ".Lf3f930_0003ff35:\n"
        "addl $1, -0x24(%ebp)\n" /* i */
        "movl -0x24(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x28(%ebp)\n" /* numAnims */
        "je .Lf3f930_0003fc67\n"
        ".Lf3f930_0003ff45:\n"
        "movzwl 6(%esi), %eax\n" /* line 4217 */
        "movl -0x24(%ebp), %ecx\n" /* i, animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "movl 8(%ebp), %edx\n" /* line 1940 | tree */
        "movzwl 8(%edx, %ecx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3f930_0003ff35\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 5 */
        /* { scope 6 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3f930_0003ff7e\n"
        "jp .Lf3f930_0003ff7e\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3f930_0003ff9d\n"
        ".Lf3f930_0003ff7e:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3f930_0003ff9d:\n"
        "movl 8(%ebp), %edx\n" /* line 1947 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x20(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf3f930_0003ff35\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3f930_0003ffbc:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1951 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "movl 8(%ebp), %eax\n" /* tree */
        "calll XAnimResetTime\n"
        "addl $1, %ebx\n" /* line 1950 | i */
        "cmpl %ebx, -0x20(%ebp)\n" /* i, numAnims */
        "jne .Lf3f930_0003ffbc\n"
        "jmp .Lf3f930_0003ff35\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        ".Lf3f930_0003ffdb:\n"
        "leal 0xc(%ebx), %eax\n" /* line 1914 */
        "pxor %xmm4, %xmm4\n" /* line 1916 */
        "ucomiss 0xc(%ebx), %xmm4\n"
        "jne .Lf3f930_0003fff5\n"
        "jp .Lf3f930_0003fff5\n"
        "cmpw $0, 8(%eax)\n"
        "je .Lf3f930_0003fab0\n"
        ".Lf3f930_0003fff5:\n"
        "movl $0, (%eax)\n" /* line 1919 */
        "movw $0, 8(%eax)\n" /* line 1920 */
        "movl $0, 4(%eax)\n" /* line 1921 */
        "movw $0, 0xa(%eax)\n" /* line 1922 */
        "movw $0xffff, 2(%ebx)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        "movzwl (%esi), %eax\n" /* line 4214 */
        "movl %eax, -0x40(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 4216 */
        "jle .Lf3f930_0003fab0\n"
        "movl $0, -0x3c(%ebp)\n" /* i */
        "jmp .Lf3f930_0004003b\n"
        ".Lf3f930_0004002b:\n"
        "addl $1, -0x3c(%ebp)\n" /* i */
        "movl -0x3c(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x40(%ebp)\n" /* numAnims */
        "je .Lf3f930_0003fab0\n"
        ".Lf3f930_0004003b:\n"
        "movzwl 6(%esi), %eax\n" /* line 4217 */
        "movl -0x3c(%ebp), %ecx\n" /* i, animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "movl 8(%ebp), %edx\n" /* line 1940 | tree */
        "movzwl 8(%edx, %ecx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf3f930_0004002b\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 5 */
        /* { scope 6 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf3f930_00040074\n"
        "jp .Lf3f930_00040074\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf3f930_00040093\n"
        ".Lf3f930_00040074:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf3f930_00040093:\n"
        "movl 8(%ebp), %edx\n" /* line 1947 | tree */
        "movl (%edx), %eax\n"
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %edi\n" /* line 1948 | numAnims */
        "testl %edi, %edi\n" /* line 1950 | numAnims */
        "jle .Lf3f930_0004002b\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf3f930_000400ab:\n"
        "movl -0x38(%ebp), %eax\n" /* line 1951 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "movl 8(%ebp), %eax\n" /* tree */
        "calll XAnimResetTime\n"
        "addl $1, %ebx\n" /* line 1950 | i */
        "cmpl %ebx, %edi\n" /* i, numAnims */
        "jne .Lf3f930_000400ab\n"
        "jmp .Lf3f930_0004002b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        ".Lf3f930_000400c9:\n"
        "xorl %esi, %esi\n" /* line 3699 */
        ".Lf3f930_000400cb:\n"
        "movl -0x48(%ebp), %edx\n" /* line 3701 | parentAnim */
        "movzwl 6(%edx), %eax\n"
        "leal (%esi, %eax), %eax\n"
        "cmpl %eax, 0xc(%ebp)\n" /* animIndex */
        "je .Lf3f930_0004013f\n"
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "movl 8(%ebp), %ecx\n" /* line 3595 | tree */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "testw %ax, %ax\n" /* line 3596 */
        "je .Lf3f930_0004013f\n"
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* line 3601 | i */
        "pxor %xmm0, %xmm0\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm0\n"
        "jp .Lf3f930_00040107\n"
        "je .Lf3f930_000401ce\n"
        ".Lf3f930_00040107:\n"
        "movss -0x44(%ebp), %xmm1\n" /* line 3605 | blendTime */
        "movss %xmm1, 0xc(%eax)\n"
        ".Lf3f930_00040111:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 5 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3f930_00040139\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        ".Lf3f930_00040139:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3f930_0004013f:\n"
        "addl $1, %esi\n" /* line 3699 */
        "cmpl %esi, %edi\n" /* numAnims */
        "jne .Lf3f930_000400cb\n"
        "movss 0x14(%ebp), %xmm0\n" /* goalWeight */
        "jmp .Lf3f930_0003f9f9\n"
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        ".Lf3f930_00040150:\n"
        "xorl %esi, %esi\n"
        ".Lf3f930_00040152:\n"
        "movl -0x30(%ebp), %edx\n" /* line 3701 | parentAnim */
        "movzwl 6(%edx), %eax\n"
        "leal (%esi, %eax), %eax\n"
        "cmpl %eax, %edi\n" /* numAnims */
        "je .Lf3f930_000401c1\n"
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        "movl 8(%ebp), %ecx\n" /* line 3595 | tree */
        "movzwl 8(%ecx, %eax, 2), %eax\n"
        "testw %ax, %ax\n" /* line 3596 */
        "je .Lf3f930_000401c1\n"
        "movzwl %ax, %eax\n" /* line 3600 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* line 3601 | i */
        "pxor %xmm0, %xmm0\n" /* line 3603 */
        "ucomiss 0x10(%eax), %xmm0\n"
        "jp .Lf3f930_00040189\n"
        "je .Lf3f930_000401ec\n"
        ".Lf3f930_00040189:\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 3605 | blendTime */
        "movss %xmm1, 0xc(%eax)\n"
        ".Lf3f930_00040193:\n"
        "movl $0, 0x10(%eax)\n" /* line 3613 */
        "movl $0, 0x14(%eax)\n" /* line 3616 */
        /* { scope 5 */
        "movzwl 4(%ebx), %eax\n" /* line 1273 */
        "testw %ax, %ax\n"
        "je .Lf3f930_000401bb\n"
        "movzwl %ax, %eax\n" /* line 1275 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movw $0, 4(%ebx)\n" /* line 1276 */
        ".Lf3f930_000401bb:\n"
        "movw $0xffff, 2(%ebx)\n" /* line 1278 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf3f930_000401c1:\n"
        "addl $1, %esi\n" /* line 3699 */
        "cmpl %esi, -0x34(%ebp)\n" /* numAnims */
        "jne .Lf3f930_00040152\n"
        "jmp .Lf3f930_0003fb98\n"
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        ".Lf3f930_000401ce:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss -0x44(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3f930_00040111\n"
        "movss -0x44(%ebp), %xmm2\n" /* line 3610 | blendTime */
        "movss %xmm2, 0xc(%eax)\n"
        "jmp .Lf3f930_00040111\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: blendTime, blendTime */
        /* { scope 3: numAnims, anim, anim */
        /* { scope 4 */
        ".Lf3f930_000401ec:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 3609 */
        "ucomiss -0x2c(%ebp), %xmm0\n" /* blendTime */
        "jbe .Lf3f930_00040193\n"
        "movss -0x2c(%ebp), %xmm2\n" /* line 3610 | blendTime */
        "movss %xmm2, 0xc(%eax)\n"
        "jmp .Lf3f930_00040193\n"
    );
}

/* line 4251 */
__attribute__((naked))
int XAnimSetGoalWeight(XAnimTree *tree, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4251 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* tree */
        "movss 0x10(%ebp), %xmm0\n" /* goalWeight */
        /* { scope 1: numAnims, i */
        "movaps %xmm0, %xmm1\n" /* line 4257 */
        "cmpnltss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "andps %xmm1, %xmm0\n"
        "movl 0x20(%ebp), %eax\n" /* line 4260 | notifyType */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* notifyName */
        "movl %eax, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movss 0x18(%ebp), %xmm2\n" /* rate */
        "movss 0x14(%ebp), %xmm1\n" /* goalTime */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimSetGoalWeightInternal\n"
        "movl %eax, -0x2c(%ebp)\n" /* error */
        "movl 0xc(%ebp), %ebx\n" /* line 4239 | animIndex, info */
        "testl %ebx, %ebx\n" /* info */
        "je .Lf40204_00040263\n"
        "movl (%edi), %ecx\n" /* line 4241 */
        "movl 0xc(%ebp), %eax\n" /* animIndex */
        "movzwl 0xe(%ecx, %eax, 8), %ebx\n" /* info */
        "cmpw $0, 8(%edi, %ebx, 2)\n" /* line 4243 */
        "je .Lf40204_000402d1\n"
        ".Lf40204_00040263:\n"
        "movl 0x24(%ebp), %ecx\n" /* line 4264 | bRestart */
        "testl %ecx, %ecx\n"
        "je .Lf40204_000402c6\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %edx\n" /* line 4200 | animIndex */
        "testl %edx, %edx\n"
        "jne .Lf40204_0004031b\n"
        "movl (%edi), %ecx\n"
        ".Lf40204_00040277:\n"
        "movl 0xc(%ebp), %eax\n" /* line 4224 | animIndex */
        "cmpw $0, 0xc(%ecx, %eax, 8)\n"
        "jne .Lf40204_000402c6\n"
        "movzwl 8(%edi, %eax, 2), %eax\n" /* line 4229 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 3: numAnims, anim */
        /* { scope 4 */
        "leal 0xc(%eax), %ecx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf40204_000402a7\n"
        "jp .Lf40204_000402a7\n"
        "cmpw $0, 8(%ecx)\n"
        "je .Lf40204_000402c6\n"
        ".Lf40204_000402a7:\n"
        "movl $0, (%ecx)\n" /* line 1919 */
        "movw $0, 8(%ecx)\n" /* line 1920 */
        "movl $0, 4(%ecx)\n" /* line 1921 */
        "movw $0, 0xa(%ecx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf40204_000402c6:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 4269 | error */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numAnims, i */
        ".Lf40204_000402d1:\n"
        "movl $0, 4(%esp)\n" /* line 4245 */
        "movl $0, (%esp)\n"
        "movl $1, %ecx\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movss 0x14(%ebp), %xmm1\n" /* goalTime */
        "pxor %xmm0, %xmm0\n"
        "movl %ebx, %edx\n" /* info */
        "movl %edi, %eax\n"
        "calll XAnimSetGoalWeightInternal\n"
        "testl %ebx, %ebx\n" /* line 4239 | info */
        "je .Lf40204_00040263\n"
        "movl (%edi), %ecx\n" /* line 4241 */
        "movzwl 0xe(%ecx, %ebx, 8), %ebx\n" /* info */
        "cmpw $0, 8(%edi, %ebx, 2)\n" /* line 4243 */
        "je .Lf40204_000402d1\n"
        "jmp .Lf40204_00040263\n"
        /* { scope 2 */
        ".Lf40204_0004031b:\n"
        "movl (%edi), %ecx\n" /* line 4205 */
        "movl 0xc(%ebp), %edx\n" /* animIndex */
        ".Lf40204_00040320:\n"
        "movzwl 8(%edi, %edx, 2), %eax\n" /* line 4204 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %ebx\n" /* i */
        "leal (%ecx, %edx, 8), %eax\n" /* line 4205 */
        "leal 0xc(%eax), %esi\n"
        "cmpw $0, 0xc(%eax)\n" /* line 4206 */
        "je .Lf40204_00040342\n"
        "testb $4, 4(%esi)\n" /* line 4208 */
        "jne .Lf40204_00040354\n"
        ".Lf40204_00040342:\n"
        "movzwl 0xe(%ecx, %edx, 8), %eax\n" /* line 4200 */
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n"
        "jne .Lf40204_00040320\n"
        "jmp .Lf40204_00040277\n"
        /* { scope 3: numAnims, anim */
        /* { scope 4 */
        ".Lf40204_00040354:\n"
        "leal 0xc(%ebx), %eax\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%ebx), %xmm0\n"
        "je .Lf40204_00040436\n"
        ".Lf40204_00040365:\n"
        "movl $0, (%eax)\n" /* line 1919 */
        "movw $0, 8(%eax)\n" /* line 1920 */
        "movl $0, 4(%eax)\n" /* line 1921 */
        "movw $0, 0xa(%eax)\n" /* line 1922 */
        "movw $0xffff, 2(%ebx)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        "movzwl (%esi), %eax\n" /* line 4214 */
        "movl %eax, -0x28(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 4216 */
        "jle .Lf40204_000402c6\n"
        "movl $0, -0x24(%ebp)\n" /* i */
        "jmp .Lf40204_000403ab\n"
        ".Lf40204_0004039b:\n"
        "addl $1, -0x24(%ebp)\n" /* i */
        "movl -0x24(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x28(%ebp)\n" /* numAnims */
        "je .Lf40204_000402c6\n"
        ".Lf40204_000403ab:\n"
        "movzwl 6(%esi), %eax\n" /* line 4217 */
        "movl -0x24(%ebp), %ecx\n" /* i, animIndex */
        "addl %eax, %ecx\n" /* animIndex */
        /* { scope 3: numAnims, anim */
        /* { scope 4 */
        "movzwl 8(%edi, %ecx, 2), %eax\n" /* line 1940 */
        "testw %ax, %ax\n" /* line 1941 */
        "je .Lf40204_0004039b\n"
        "movzwl %ax, %eax\n" /* line 1945 | info */
        "leal (%eax, %eax, 4), %eax\n" /* info */
        "leal g_xAnimInfo(, %eax, 8), %eax\n" /* info */
        /* { scope 5 */
        /* { scope 6 */
        "leal 0xc(%eax), %edx\n" /* line 1914 */
        "pxor %xmm0, %xmm0\n" /* line 1916 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jne .Lf40204_000403e1\n"
        "jp .Lf40204_000403e1\n"
        "cmpw $0, 8(%edx)\n"
        "je .Lf40204_00040400\n"
        ".Lf40204_000403e1:\n"
        "movl $0, (%edx)\n" /* line 1919 */
        "movw $0, 8(%edx)\n" /* line 1920 */
        "movl $0, 4(%edx)\n" /* line 1921 */
        "movw $0, 0xa(%edx)\n" /* line 1922 */
        "movw $0xffff, 2(%eax)\n" /* line 1924 */
        /* } scope */
        /* } scope */
        ".Lf40204_00040400:\n"
        "movl (%edi), %eax\n" /* line 1947 */
        "leal (%eax, %ecx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1948 */
        "movl %eax, -0x20(%ebp)\n" /* numAnims */
        "testl %eax, %eax\n" /* line 1950 */
        "jle .Lf40204_0004039b\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf40204_00040418:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1951 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* i */
        "movl %edi, %eax\n"
        "calll XAnimResetTime\n"
        "addl $1, %ebx\n" /* line 1950 | i */
        "cmpl %ebx, -0x20(%ebp)\n" /* i, numAnims */
        "jne .Lf40204_00040418\n"
        "jmp .Lf40204_0004039b\n"
        /* } scope */
        /* } scope */
        /* { scope 3: numAnims, anim */
        /* { scope 4 */
        ".Lf40204_00040436:\n"
        "jp .Lf40204_00040365\n" /* line 1916 */
        "cmpw $0, 8(%eax)\n"
        "je .Lf40204_000402c6\n"
        "jmp .Lf40204_00040365\n"
    );
}

/* line 2582 */
static __attribute__((naked))
void XAnimDisplay(const XAnimTree *tree, int depth)
{
    __asm__ __volatile__ (
        ".Lf4044c_0004044c:\n"
        "pushl %ebp\n" /* line 2582 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %edx, %esi\n" /* animIndex */
        "movl %ecx, -0x3c(%ebp)\n"
        /* { scope 1 */
        "movzwl 8(%eax, %edx, 2), %edx\n" /* line 2599 */
        "testw %dx, %dx\n" /* line 2600 */
        "je .Lf4044c_00040599\n"
        "movl (%eax), %ecx\n" /* line 2603 */
        "leal (%ecx, %esi, 8), %eax\n"
        "leal 0xc(%eax), %ebx\n" /* color */
        "movl %ebx, -0x2c(%ebp)\n" /* color, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 2604 */
        "movw %ax, -0x32(%ebp)\n"
        "movzwl %ax, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* numAnims */
        "movzwl %dx, %eax\n" /* line 2607 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* info */
        "movl %eax, %edi\n" /* line 2608 | state */
        "addl $0xc, %edi\n" /* state */
        "movl -0x3c(%ebp), %eax\n" /* line 2612 */
        "testl %eax, %eax\n"
        "jg .Lf4044c_00040675\n"
        /* { scope 2 */
        "leal (%ecx, %esi, 8), %edx\n" /* line 3006 */
        "leal 0xc(%edx), %ebx\n" /* anim */
        "movl 8(%ecx), %eax\n" /* line 3007 */
        "testl %eax, %eax\n"
        "je .Lf4044c_000406a1\n"
        ".Lf4044c_000404b5:\n"
        "movl (%eax, %esi, 4), %eax\n" /* line 3010 */
        "movl %eax, -0x24(%ebp)\n" /* debugName */
        "cmpw $0, 0xc(%edx)\n" /* line 3011 */
        "je .Lf4044c_0004063a\n"
        /* } scope */
        ".Lf4044c_000404c6:\n"
        "movss 0x14(%edi), %xmm3\n" /* line 2617 | state */
        "movss 0x10(%edi), %xmm2\n" /* state */
        "ucomiss %xmm3, %xmm2\n"
        "jbe .Lf4044c_000405a1\n"
        ".Lf4044c_000404d9:\n"
        "movl $str_00217918, %ebx\n" /* color */
        "cmpw $0, -0x32(%ebp)\n" /* line 2624 */
        "jne .Lf4044c_000405bc\n"
        ".Lf4044c_000404e9:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2626 | anim */
        "movl 4(%edx), %eax\n"
        "movss (%edi), %xmm4\n" /* line 2629 | state */
        "movss 4(%edi), %xmm5\n" /* state */
        "movaps %xmm4, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 2630 | 0.0f */
        "jb .Lf4044c_00040817\n"
        ".Lf4044c_0004050c:\n"
        "movss 8(%eax), %xmm0\n" /* line 2632 */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf4044c_00040778\n"
        "jp .Lf4044c_00040778\n"
        "pxor %xmm0, %xmm0\n"
        "movsd %xmm0, -0x20(%ebp)\n"
        "movl -0x28(%ebp), %edx\n" /* line 2633 | info */
        "movzwl 4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf4044c_00040795\n"
        ".Lf4044c_0004053d:\n"
        "movzwl %ax, %eax\n" /* line 2635 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 0x34(%esp)\n"
        "movsd -0x20(%ebp), %xmm0\n"
        "movsd %xmm0, 0x2c(%esp)\n"
        "cvtss2sd (%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd 4(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd 0x10(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x14(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* debugName */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* color */
        "movl $str_00217920, (%esp)\n" /* "%s%s: (weight) %.2f -> %.2f, (time) %.2f -> %.2f, (realtimed" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf4044c_00040599:\n"
        "addl $0x7c, %esp\n" /* line 2671 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4044c_000405a1:\n"
        "movl $str_0021791c, %ebx\n" /* line 2619 | color */
        "ucomiss %xmm2, %xmm3\n"
        "movl $str_002157b8, %eax\n"
        "cmovbel %eax, %ebx\n" /* color */
        "cmpw $0, -0x32(%ebp)\n" /* line 2624 */
        "je .Lf4044c_000404e9\n"
        ".Lf4044c_000405bc:\n"
        "movl -0x28(%ebp), %edx\n" /* line 2644 | info */
        "movzwl 4(%edx), %ecx\n"
        "testw %cx, %cx\n"
        "jne .Lf4044c_000406ba\n"
        /* { scope 2 */
        "movl -0x38(%ebp), %edx\n" /* line 4126 */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "cmpw $0, 0xc(%eax)\n" /* line 4127 */
        "je .Lf4044c_000405e8\n"
        "testb $3, 4(%edx)\n"
        "je .Lf4044c_000408c1\n"
        ".Lf4044c_000405e8:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf4044c_000405ed:\n"
        "testl %eax, %eax\n" /* line 2660 */
        "je .Lf4044c_000407e7\n"
        "cvtss2sd (%edi), %xmm0\n" /* line 2661 | state */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd 4(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd %xmm2, %xmm2\n"
        "movsd %xmm2, 0x14(%esp)\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* debugName */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* color */
        "movl $str_00217a14, (%esp)\n" /* "%s%s: (weight) %.2f -> %.2f, (time) %.2f -> %.2f
" */
        "calll Com_Printf\n"
        "jmp .Lf4044c_00040741\n"
        /* { scope 2 */
        ".Lf4044c_0004063a:\n"
        "movl 4(%ebx), %eax\n" /* line 3011 | anim */
        "cmpb $0, 0x28(%eax)\n"
        "je .Lf4044c_000404c6\n"
        "movl -0x24(%ebp), %ebx\n" /* line 3012 | debugName, anim */
        "movl %ebx, 4(%esp)\n" /* anim */
        "movl $str_00217860, (%esp)\n" /* "^3%s (missing)" */
        "calll va\n"
        "movl %eax, -0x24(%ebp)\n" /* debugName */
        /* } scope */
        "movss 0x14(%edi), %xmm3\n" /* line 2617 | state */
        "movss 0x10(%edi), %xmm2\n" /* state */
        "ucomiss %xmm3, %xmm2\n"
        "jbe .Lf4044c_000405a1\n"
        "jmp .Lf4044c_000404d9\n"
        ".Lf4044c_00040675:\n"
        "xorl %ebx, %ebx\n" /* line 2612 | color */
        ".Lf4044c_00040677:\n"
        "movl $str_00217914, (%esp)\n" /* line 2613 */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 2612 | color */
        "cmpl %ebx, -0x3c(%ebp)\n" /* color */
        "jne .Lf4044c_00040677\n"
        "movl -0x38(%ebp), %edx\n"
        "movl (%edx), %ecx\n"
        /* { scope 2 */
        "leal (%ecx, %esi, 8), %edx\n" /* line 3006 */
        "leal 0xc(%edx), %ebx\n" /* anim */
        "movl 8(%ecx), %eax\n" /* line 3007 */
        "testl %eax, %eax\n"
        "jne .Lf4044c_000404b5\n"
        ".Lf4044c_000406a1:\n"
        "cmpw $0, 0xc(%edx)\n" /* line 3008 */
        "jne .Lf4044c_000408cf\n"
        "movl 4(%ebx), %eax\n" /* anim */
        "movl 0x24(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* debugName */
        "jmp .Lf4044c_000404c6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4044c_000406ba:\n"
        "movl -0x38(%ebp), %edx\n" /* line 4126 */
        "movl (%edx), %eax\n"
        "leal (%eax, %esi, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "cmpw $0, 0xc(%eax)\n" /* line 4127 */
        "je .Lf4044c_000406d6\n"
        "testb $3, 4(%edx)\n"
        "je .Lf4044c_000408c8\n"
        ".Lf4044c_000406d6:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf4044c_000406db:\n"
        "testl %eax, %eax\n" /* line 2646 */
        "je .Lf4044c_00040880\n"
        "movl -0x28(%ebp), %eax\n" /* line 2648 | info */
        "cmpw $0, (%eax)\n"
        "jne .Lf4044c_0004082a\n"
        "movzwl %cx, %eax\n" /* line 2649 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 0x2c(%esp)\n"
        "cvtss2sd (%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd 4(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd 0x10(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x14(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl -0x24(%ebp), %edx\n" /* debugName */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* color */
        "movl $str_002179b8, (%esp)\n" /* "%s%s: (weight) %.2f -> %.2f, (time) %.2f -> %.2f, '%s'
" */
        "calll Com_Printf\n"
        ".Lf4044c_00040741:\n"
        "movl -0x30(%ebp), %esi\n" /* line 2666 | numAnims, animIndex */
        "testl %esi, %esi\n" /* animIndex */
        "jle .Lf4044c_00040599\n"
        "movl -0x3c(%ebp), %esi\n" /* animIndex */
        "addl $1, %esi\n" /* animIndex */
        "xorl %ebx, %ebx\n" /* color */
        ".Lf4044c_00040754:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2669 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* color */
        "movl %esi, %ecx\n" /* animIndex */
        "movl -0x38(%ebp), %eax\n"
        "calll XAnimDisplay\n"
        "addl $1, %ebx\n" /* line 2666 | color */
        "cmpl %ebx, -0x30(%ebp)\n" /* color, numAnims */
        "jne .Lf4044c_00040754\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 2671 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4044c_00040778:\n"
        "divss %xmm0, %xmm1\n" /* line 2632 */
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, -0x20(%ebp)\n"
        "movl -0x28(%ebp), %edx\n" /* line 2633 | info */
        "movzwl 4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "jne .Lf4044c_0004053d\n"
        ".Lf4044c_00040795:\n"
        "movsd -0x20(%ebp), %xmm0\n" /* line 2639 */
        "movsd %xmm0, 0x2c(%esp)\n"
        "cvtss2sd %xmm4, %xmm4\n"
        "movsd %xmm4, 0x24(%esp)\n"
        "cvtss2sd %xmm5, %xmm5\n"
        "movsd %xmm5, 0x1c(%esp)\n"
        "cvtss2sd %xmm2, %xmm2\n"
        "movsd %xmm2, 0x14(%esp)\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* debugName */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* color */
        "movl $str_00217970, (%esp)\n" /* "%s%s: (weight) %.2f -> %.2f, (time) %.2f -> %.2f, (realtimed" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 2671 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4044c_000407e7:\n"
        "cvtss2sd %xmm2, %xmm2\n" /* line 2663 */
        "movsd %xmm2, 0x14(%esp)\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, 0xc(%esp)\n"
        "movl -0x24(%ebp), %edx\n" /* debugName */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* color */
        "movl $str_00217a48, (%esp)\n" /* "%s%s: (weight) %.2f -> %.2f
" */
        "calll Com_Printf\n"
        "jmp .Lf4044c_00040741\n"
        ".Lf4044c_00040817:\n"
        "jp .Lf4044c_0004050c\n" /* line 2630 */
        "addss lit4_002ed5d0, %xmm1\n" /* line 2631 | 1.0f */
        "jmp .Lf4044c_0004050c\n"
        ".Lf4044c_0004082a:\n"
        "movzwl %cx, %eax\n" /* line 2651 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 0x2c(%esp)\n"
        "cvtss2sd (%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd 4(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd 0x10(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x14(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* debugName */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* color */
        "movl $str_002179b8, (%esp)\n" /* "%s%s: (weight) %.2f -> %.2f, (time) %.2f -> %.2f, '%s'
" */
        "calll Com_Printf\n"
        "jmp .Lf4044c_00040741\n"
        ".Lf4044c_00040880:\n"
        "movzwl %cx, %eax\n" /* line 2655 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 0x1c(%esp)\n"
        "cvtss2sd 0x10(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x14(%edi), %xmm0\n" /* state */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl -0x24(%ebp), %edx\n" /* debugName */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* color */
        "movl $str_002179f0, (%esp)\n" /* "%s%s: (weight) %.2f -> %.2f, '%s'
" */
        "calll Com_Printf\n"
        "jmp .Lf4044c_00040741\n"
        /* { scope 2 */
        ".Lf4044c_000408c1:\n"
        "xorl %eax, %eax\n" /* line 4127 */
        "jmp .Lf4044c_000405ed\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4044c_000408c8:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4044c_000406db\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4044c_000408cf:\n"
        "movl %esi, 4(%esp)\n" /* line 3008 | animIndex */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, -0x24(%ebp)\n" /* debugName */
        "jmp .Lf4044c_000404c6\n"
    );
}

/* line 3338 */
__attribute__((naked))
void DObjDisplayAnim(DObj *obj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3338 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 3340 | obj */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf408e8_0004090d\n"
        "xorl %ecx, %ecx\n" /* line 3346 */
        "xorl %edx, %edx\n"
        "calll XAnimDisplay\n"
        "movl $str_002160e8, 8(%ebp)\n" /* line 3347 | obj */
        "leave\n" /* line 3348 */
        "jmp Com_Printf\n" /* line 3347 */
        ".Lf408e8_0004090d:\n"
        "movl $str_00217a68, 8(%ebp)\n" /* line 3342 | obj */
        "leave\n" /* line 3348 */
        "jmp Com_Printf\n" /* line 3342 */
    );
}

/* line 4033 */
static __attribute__((naked))
void XAnimFillInSyncNodes_r(Bool bLoop)
{
    __asm__ __volatile__ (
        ".Lf4091a_0004091a:\n"
        "pushl %ebp\n" /* line 4033 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %edi\n" /* anims */
        "movb %cl, -0x25(%ebp)\n"
        /* { scope 1: anim */
        "leal (%eax, %edx, 8), %eax\n" /* line 4040 */
        "leal 0xc(%eax), %esi\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 4041 */
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* numAnims */
        "testw %ax, %ax\n" /* line 4042 */
        "jne .Lf4091a_00040991\n"
        "movl 4(%esi), %ecx\n" /* line 4044 | anim */
        "movzbl -0x25(%ebp), %eax\n"
        "cmpb 2(%ecx), %al\n"
        "je .Lf4091a_00040989\n"
        "cmpb $0, 0x28(%ecx)\n" /* line 4046 */
        "jne .Lf4091a_00040a87\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 4055 */
        "jne .Lf4091a_00040a53\n"
        "movl (%edi), %ebx\n" /* line 4061 | anims, count */
        /* { scope 2 */
        "movl 8(%edi), %eax\n" /* line 3007 */
        "testl %eax, %eax\n"
        "je .Lf4091a_00040af0\n"
        "movl (%eax, %edx, 4), %eax\n" /* line 3010 */
        /* } scope */
        ".Lf4091a_0004096d:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 4061 | count */
        "movl %eax, 8(%esp)\n"
        "movl $str_00217b10, 4(%esp)\n" /* "animation '%s' in '%s' cannot be sync nonlooping and loopin" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf4091a_00040989:\n"
        "addl $0x3c, %esp\n" /* line 4082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim */
        ".Lf4091a_00040991:\n"
        "testb $3, 4(%esi)\n" /* line 4067 | anim */
        "je .Lf4091a_00040a0b\n"
        "xorl %ebx, %ebx\n" /* count */
        ".Lf4091a_00040999:\n"
        "addl $1, %ebx\n" /* line 4072 | count */
        "movzwl 6(%esi), %eax\n" /* line 4073 | anim */
        "leal (%edi, %eax, 8), %eax\n" /* anims */
        "leal 0xc(%eax), %esi\n" /* anim */
        "cmpw $0, 0xc(%eax)\n" /* line 4070 */
        "jne .Lf4091a_00040999\n"
        /* { scope 2 */
        "leal (%edi, %edx, 8), %ecx\n" /* line 3006 */
        "leal 0xc(%ecx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* anim */
        "movl 8(%edi), %eax\n" /* line 3007 */
        "testl %eax, %eax\n"
        "je .Lf4091a_00040adb\n"
        "movl (%eax, %edx, 4), %edx\n" /* line 3010 */
        "cmpw $0, 0xc(%ecx)\n" /* line 3011 */
        "jne .Lf4091a_000409e9\n"
        "movl -0x20(%ebp), %ecx\n" /* anim */
        "movl 4(%ecx), %eax\n"
        "cmpb $0, 0x28(%eax)\n"
        "je .Lf4091a_000409e9\n"
        "movl %edx, 4(%esp)\n" /* line 3012 */
        "movl $str_00217860, (%esp)\n" /* "^3%s (missing)" */
        "calll va\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf4091a_000409e9:\n"
        "movl %edx, 0x10(%esp)\n" /* line 4075 | animIndex */
        "movl %ebx, 0xc(%esp)\n" /* count */
        "movl (%edi), %eax\n" /* anims */
        "movl %eax, 8(%esp)\n"
        "movl $str_00217b50, 4(%esp)\n" /* "duplicate specification of animation sync in '%s', %d nodes" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf4091a_00040a0b:\n"
        "cmpb $1, -0x25(%ebp)\n" /* line 4078 */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "addl $2, %eax\n"
        "orw %ax, 4(%esi)\n" /* anim */
        "movl -0x24(%ebp), %eax\n" /* line 4080 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf4091a_00040989\n"
        "movzbl -0x25(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n" /* count */
        "movl %eax, %ecx\n"
        "jmp .Lf4091a_00040a35\n"
        ".Lf4091a_00040a32:\n"
        "movl -0x1c(%ebp), %ecx\n"
        ".Lf4091a_00040a35:\n"
        "movzwl 6(%esi), %edx\n" /* line 4081 | anim, animIndex */
        "leal (%ebx, %edx), %edx\n" /* count, animIndex */
        "movl %edi, %eax\n" /* anims */
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4080 | count */
        "cmpl %ebx, -0x24(%ebp)\n" /* count, numAnims */
        "jne .Lf4091a_00040a32\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 4082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim */
        ".Lf4091a_00040a53:\n"
        "movl (%edi), %ebx\n" /* line 4057 | anims, count */
        /* { scope 2 */
        "movl 8(%edi), %eax\n" /* line 3007 */
        "testl %eax, %eax\n"
        "je .Lf4091a_00040af8\n"
        "movl (%eax, %edx, 4), %eax\n" /* line 3010 */
        /* } scope */
        ".Lf4091a_00040a63:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 4057 | count */
        "movl %eax, 8(%esp)\n"
        "movl $str_00217ad0, 4(%esp)\n" /* "animation '%s' in '%s' cannot be sync looping and nonloopin" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 4082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim */
        ".Lf4091a_00040a87:\n"
        "movl $Hunk_AllocXAnimPrecache, 4(%esp)\n" /* line 4049 */
        "movl $str_00217a74, (%esp)\n" /* "void_loop" */
        "calll XAnimPrecache\n"
        "movl $str_00217a74, 4(%esp)\n" /* line 196 */
        "movl $5, (%esp)\n"
        "calll Hunk_FindDataForFile\n"
        "movl %eax, 4(%esi)\n" /* line 4051 | anim */
        "testl %eax, %eax\n" /* line 4052 */
        "jne .Lf4091a_00040989\n"
        "movl $str_00217a74, 8(%esp)\n" /* line 4053 */
        "movl $str_00217a80, 4(%esp)\n" /* "Cannot find 'xanim/%s'.
This is a default xanim file that y" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf4091a_00040989\n"
        /* { scope 2 */
        ".Lf4091a_00040adb:\n"
        "cmpw $0, 0xc(%ecx)\n" /* line 3008 */
        "jne .Lf4091a_00040b00\n"
        "movl -0x20(%ebp), %edx\n" /* anim */
        "movl 4(%edx), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "jmp .Lf4091a_000409e9\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4091a_00040af0:\n"
        "movl 0x24(%ecx), %eax\n"
        "jmp .Lf4091a_0004096d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4091a_00040af8:\n"
        "movl 0x24(%ecx), %eax\n"
        "jmp .Lf4091a_00040a63\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4091a_00040b00:\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, %edx\n"
        "jmp .Lf4091a_000409e9\n"
    );
}

/* line 4085 */
static __attribute__((naked))
void XAnimSetupSyncNodes_r(XAnim *anims)
{
    __asm__ __volatile__ (
        ".Lf40b18_00040b18:\n"
        "pushl %ebp\n" /* line 4085 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, -0x68(%ebp)\n"
        /* { scope 1: anim, numAnims */
        "leal (%eax, %edx, 8), %edx\n" /* line 4093 | animIndex */
        "leal 0xc(%edx), %eax\n" /* animIndex */
        "movl %eax, -0x64(%ebp)\n" /* anim */
        "movzwl 0xc(%edx), %eax\n" /* line 4094 | animIndex */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x60(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 4095 */
        "je .Lf40b18_00040e39\n"
        "movl -0x64(%ebp), %edx\n" /* line 4098 | anim, animIndex */
        "movzwl 4(%edx), %eax\n" /* animIndex */
        "movl %eax, %ebx\n" /* line 4099 | flag */
        "andl $3, %ebx\n" /* flag */
        "jne .Lf40b18_00040e1b\n"
        "movl -0x60(%ebp), %eax\n" /* line 4111 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf40b18_00040e39\n"
        "movl $0, -0x1c(%ebp)\n" /* line 4106 */
        "jmp .Lf40b18_00040b98\n"
        /* { scope 2: anim, numAnims */
        ".Lf40b18_00040b66:\n"
        "cmpl $3, %ebx\n" /* line 4101 | flag */
        "je .Lf40b18_00040fcf\n"
        ".Lf40b18_00040b6f:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 4103 | anim */
        "orw $4, 4(%eax)\n"
        "subl $1, %ebx\n" /* line 4105 | flag */
        "sete %al\n"
        "movl -0x58(%ebp), %ebx\n" /* line 4106 | numAnims, flag */
        "testl %ebx, %ebx\n" /* flag */
        "jg .Lf40b18_00040f2c\n"
        /* } scope */
        ".Lf40b18_00040b88:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 4111 */
        "movl -0x1c(%ebp), %edx\n" /* animIndex */
        "cmpl %edx, -0x60(%ebp)\n" /* animIndex, numAnims */
        "je .Lf40b18_00040e39\n"
        /* { scope 2: anim, numAnims */
        ".Lf40b18_00040b98:\n"
        "movl -0x64(%ebp), %edx\n" /* line 4093 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl -0x1c(%ebp), %eax\n"
        "movl -0x68(%ebp), %edx\n" /* animIndex */
        "leal (%edx, %eax, 8), %eax\n" /* animIndex */
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x5c(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 4094 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x58(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 4095 */
        "je .Lf40b18_00040b88\n"
        "movl -0x5c(%ebp), %edx\n" /* line 4098 | anim, animIndex */
        "movzwl 4(%edx), %eax\n" /* animIndex */
        "movl %eax, %ebx\n" /* line 4099 | flag */
        "andl $3, %ebx\n" /* flag */
        "jne .Lf40b18_00040b66\n"
        "movl -0x58(%ebp), %ecx\n" /* line 4111 | numAnims */
        "testl %ecx, %ecx\n"
        "jle .Lf40b18_00040b88\n"
        "movl $0, -0x20(%ebp)\n" /* line 4106 */
        "jmp .Lf40b18_00040c0d\n"
        /* { scope 3: anim, numAnims */
        ".Lf40b18_00040bdb:\n"
        "cmpl $3, %ebx\n" /* line 4101 | flag */
        "je .Lf40b18_00040fb6\n"
        ".Lf40b18_00040be4:\n"
        "movl -0x54(%ebp), %eax\n" /* line 4103 | anim */
        "orw $4, 4(%eax)\n"
        "subl $1, %ebx\n" /* line 4105 | flag */
        "sete %al\n"
        "movl -0x50(%ebp), %edx\n" /* line 4106 | numAnims, animIndex */
        "testl %edx, %edx\n" /* animIndex */
        "jg .Lf40b18_00040f06\n"
        /* } scope */
        ".Lf40b18_00040bfd:\n"
        "addl $1, -0x20(%ebp)\n" /* line 4111 */
        "movl -0x20(%ebp), %eax\n"
        "cmpl %eax, -0x58(%ebp)\n" /* numAnims */
        "je .Lf40b18_00040b88\n"
        /* { scope 3: anim, numAnims */
        ".Lf40b18_00040c0d:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 4093 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl -0x20(%ebp), %eax\n"
        "movl -0x68(%ebp), %edx\n" /* animIndex */
        "leal (%edx, %eax, 8), %eax\n" /* animIndex */
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x54(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 4094 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x50(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 4095 */
        "je .Lf40b18_00040bfd\n"
        "movl -0x54(%ebp), %edx\n" /* line 4098 | anim, animIndex */
        "movzwl 4(%edx), %eax\n" /* animIndex */
        "movl %eax, %ebx\n" /* line 4099 | flag */
        "andl $3, %ebx\n" /* flag */
        "jne .Lf40b18_00040bdb\n"
        "movl -0x50(%ebp), %eax\n" /* line 4111 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf40b18_00040bfd\n"
        "movl $0, -0x24(%ebp)\n" /* line 4106 */
        "jmp .Lf40b18_00040c82\n"
        /* { scope 4: anim, numAnims */
        ".Lf40b18_00040c50:\n"
        "cmpl $3, %ebx\n" /* line 4101 | flag */
        "je .Lf40b18_00040f9d\n"
        ".Lf40b18_00040c59:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 4103 | anim */
        "orw $4, 4(%eax)\n"
        "subl $1, %ebx\n" /* line 4105 | flag */
        "sete %al\n"
        "movl -0x48(%ebp), %edi\n" /* line 4106 | numAnims */
        "testl %edi, %edi\n" /* numAnims */
        "jg .Lf40b18_00040ee0\n"
        /* } scope */
        ".Lf40b18_00040c72:\n"
        "addl $1, -0x24(%ebp)\n" /* line 4111 */
        "movl -0x24(%ebp), %edx\n" /* animIndex */
        "cmpl %edx, -0x50(%ebp)\n" /* animIndex, numAnims */
        "je .Lf40b18_00040bfd\n"
        /* { scope 4: anim, numAnims */
        ".Lf40b18_00040c82:\n"
        "movl -0x54(%ebp), %edx\n" /* line 4093 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl -0x24(%ebp), %eax\n"
        "movl -0x68(%ebp), %edx\n" /* animIndex */
        "leal (%edx, %eax, 8), %eax\n" /* animIndex */
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x4c(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 4094 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x48(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 4095 */
        "je .Lf40b18_00040c72\n"
        "movl -0x4c(%ebp), %edx\n" /* line 4098 | anim, animIndex */
        "movzwl 4(%edx), %eax\n" /* animIndex */
        "movl %eax, %ebx\n" /* line 4099 | flag */
        "andl $3, %ebx\n" /* flag */
        "jne .Lf40b18_00040c50\n"
        "movl -0x48(%ebp), %esi\n" /* line 4111 | numAnims, anim */
        "testl %esi, %esi\n" /* anim */
        "jle .Lf40b18_00040c72\n"
        "movl $0, -0x28(%ebp)\n" /* line 4106 */
        "jmp .Lf40b18_00040cf7\n"
        /* { scope 5: anim, numAnims */
        ".Lf40b18_00040cc5:\n"
        "cmpl $3, %ebx\n" /* line 4101 | flag */
        "je .Lf40b18_00040f84\n"
        ".Lf40b18_00040cce:\n"
        "movl -0x44(%ebp), %eax\n" /* line 4103 | anim */
        "orw $4, 4(%eax)\n"
        "subl $1, %ebx\n" /* line 4105 | flag */
        "sete %al\n"
        "movl -0x40(%ebp), %ebx\n" /* line 4106 | numAnims, flag */
        "testl %ebx, %ebx\n" /* flag */
        "jg .Lf40b18_00040e91\n"
        /* } scope */
        ".Lf40b18_00040ce7:\n"
        "addl $1, -0x28(%ebp)\n" /* line 4111 */
        "movl -0x28(%ebp), %eax\n"
        "cmpl %eax, -0x48(%ebp)\n" /* numAnims */
        "je .Lf40b18_00040c72\n"
        /* { scope 5: anim, numAnims */
        ".Lf40b18_00040cf7:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 4093 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl -0x28(%ebp), %eax\n"
        "movl -0x68(%ebp), %edx\n" /* animIndex */
        "leal (%edx, %eax, 8), %eax\n" /* animIndex */
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x44(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 4094 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x40(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 4095 */
        "je .Lf40b18_00040ce7\n"
        "movl -0x44(%ebp), %edx\n" /* line 4098 | anim, animIndex */
        "movzwl 4(%edx), %eax\n" /* animIndex */
        "movl %eax, %ebx\n" /* line 4099 | flag */
        "andl $3, %ebx\n" /* flag */
        "jne .Lf40b18_00040cc5\n"
        "movl -0x40(%ebp), %ecx\n" /* line 4111 | numAnims */
        "testl %ecx, %ecx\n"
        "jle .Lf40b18_00040ce7\n"
        "movl $0, -0x2c(%ebp)\n" /* line 4106 */
        "jmp .Lf40b18_00040d6c\n"
        /* { scope 6 */
        ".Lf40b18_00040d3a:\n"
        "cmpl $3, %ebx\n" /* line 4101 | flag */
        "je .Lf40b18_00040f6b\n"
        ".Lf40b18_00040d43:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 4103 | anim */
        "orw $4, 4(%eax)\n"
        "subl $1, %ebx\n" /* line 4105 | flag */
        "sete %al\n"
        "movl -0x38(%ebp), %edx\n" /* line 4106 | numAnims, animIndex */
        "testl %edx, %edx\n" /* animIndex */
        "jg .Lf40b18_00040e6b\n"
        /* } scope */
        ".Lf40b18_00040d5c:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 4111 */
        "movl -0x2c(%ebp), %edx\n" /* animIndex */
        "cmpl %edx, -0x40(%ebp)\n" /* animIndex, numAnims */
        "je .Lf40b18_00040ce7\n"
        /* { scope 6 */
        ".Lf40b18_00040d6c:\n"
        "movl -0x44(%ebp), %edx\n" /* line 4093 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl -0x2c(%ebp), %eax\n"
        "movl -0x68(%ebp), %edx\n" /* animIndex */
        "leal (%edx, %eax, 8), %eax\n" /* animIndex */
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x3c(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 4094 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x38(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 4095 */
        "je .Lf40b18_00040d5c\n"
        "movl -0x3c(%ebp), %edx\n" /* line 4098 | anim, animIndex */
        "movzwl 4(%edx), %eax\n" /* animIndex */
        "movl %eax, %ebx\n" /* line 4099 | flag */
        "andl $3, %ebx\n" /* flag */
        "jne .Lf40b18_00040d3a\n"
        "movl -0x38(%ebp), %eax\n" /* line 4111 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf40b18_00040d5c\n"
        "movl $0, -0x30(%ebp)\n" /* line 4106 */
        "jmp .Lf40b18_00040dd3\n"
        /* { scope 7 */
        ".Lf40b18_00040daf:\n"
        "cmpl $3, %ebx\n" /* line 4101 | flag */
        "je .Lf40b18_00040f52\n"
        ".Lf40b18_00040db8:\n"
        "orw $4, 4(%esi)\n" /* line 4103 | anim */
        "subl $1, %ebx\n" /* line 4105 | flag */
        "sete %al\n"
        "testl %edi, %edi\n" /* line 4106 | numAnims */
        "jg .Lf40b18_00040e41\n"
        /* } scope */
        ".Lf40b18_00040dc7:\n"
        "addl $1, -0x30(%ebp)\n" /* line 4111 */
        "movl -0x30(%ebp), %eax\n"
        "cmpl %eax, -0x38(%ebp)\n" /* numAnims */
        "je .Lf40b18_00040d5c\n"
        /* { scope 7 */
        ".Lf40b18_00040dd3:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 4093 | anim, animIndex */
        "movzwl 6(%edx), %eax\n" /* animIndex */
        "addl -0x30(%ebp), %eax\n"
        "movl -0x68(%ebp), %edx\n" /* animIndex */
        "leal (%edx, %eax, 8), %eax\n" /* animIndex */
        "leal 0xc(%eax), %esi\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 4094 */
        "movzwl %ax, %edi\n" /* numAnims */
        "testw %ax, %ax\n" /* line 4095 */
        "je .Lf40b18_00040dc7\n"
        "movzwl 4(%esi), %eax\n" /* line 4098 | anim */
        "movl %eax, %ebx\n" /* line 4099 | flag */
        "andl $3, %ebx\n" /* flag */
        "jne .Lf40b18_00040daf\n"
        "testl %edi, %edi\n" /* line 4111 | numAnims */
        "jle .Lf40b18_00040dc7\n"
        "xorl %ebx, %ebx\n" /* line 4106 | flag */
        ".Lf40b18_00040e03:\n"
        "movzwl 6(%esi), %edx\n" /* line 4112 | anim, animIndex */
        "leal (%ebx, %edx), %edx\n" /* flag, animIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimSetupSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4111 | flag */
        "cmpl %ebx, %edi\n" /* flag, numAnims */
        "jne .Lf40b18_00040e03\n"
        "jmp .Lf40b18_00040dc7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf40b18_00040e1b:\n"
        "cmpl $3, %ebx\n" /* line 4101 | flag */
        "je .Lf40b18_00040fe8\n"
        ".Lf40b18_00040e24:\n"
        "movl -0x64(%ebp), %eax\n" /* line 4103 | anim */
        "orw $4, 4(%eax)\n"
        "subl $1, %ebx\n" /* line 4105 | flag */
        "sete %al\n"
        "movl -0x60(%ebp), %esi\n" /* line 4106 | numAnims, anim */
        "testl %esi, %esi\n" /* anim */
        "jg .Lf40b18_00040eb7\n"
        /* } scope */
        ".Lf40b18_00040e39:\n"
        "addl $0x6c, %esp\n" /* line 4113 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim, numAnims */
        /* { scope 2: anim, numAnims */
        /* { scope 3: anim, numAnims */
        /* { scope 4: anim, numAnims */
        /* { scope 5: anim, numAnims */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf40b18_00040e41:\n"
        "movzbl %al, %eax\n" /* line 4106 */
        "movl %eax, -0x34(%ebp)\n"
        "xorl %ebx, %ebx\n" /* flag */
        "movl %eax, %ecx\n"
        "jmp .Lf40b18_00040e50\n"
        ".Lf40b18_00040e4d:\n"
        "movl -0x34(%ebp), %ecx\n"
        ".Lf40b18_00040e50:\n"
        "movzwl 6(%esi), %edx\n" /* line 4107 | anim, animIndex */
        "leal (%ebx, %edx), %edx\n" /* flag, animIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4106 | flag */
        "cmpl %ebx, %edi\n" /* flag, numAnims */
        "jne .Lf40b18_00040e4d\n"
        "jmp .Lf40b18_00040dc7\n"
        /* } scope */
        ".Lf40b18_00040e6b:\n"
        "movzbl %al, %esi\n" /* anim */
        "xorl %ebx, %ebx\n" /* flag */
        ".Lf40b18_00040e70:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 4107 | anim */
        "movzwl 6(%eax), %edx\n" /* animIndex */
        "leal (%ebx, %edx), %edx\n" /* flag, animIndex */
        "movl %esi, %ecx\n" /* anim */
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4106 | flag */
        "cmpl %ebx, -0x38(%ebp)\n" /* flag, numAnims */
        "jne .Lf40b18_00040e70\n"
        "jmp .Lf40b18_00040d5c\n"
        /* } scope */
        ".Lf40b18_00040e91:\n"
        "movzbl %al, %esi\n" /* anim */
        "xorl %ebx, %ebx\n" /* flag */
        ".Lf40b18_00040e96:\n"
        "movl -0x44(%ebp), %eax\n" /* line 4107 | anim */
        "movzwl 6(%eax), %edx\n" /* animIndex */
        "leal (%ebx, %edx), %edx\n" /* flag, animIndex */
        "movl %esi, %ecx\n" /* anim */
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4106 | flag */
        "cmpl %ebx, -0x40(%ebp)\n" /* flag, numAnims */
        "jne .Lf40b18_00040e96\n"
        "jmp .Lf40b18_00040ce7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf40b18_00040eb7:\n"
        "movzbl %al, %esi\n" /* anim */
        "xorl %ebx, %ebx\n" /* flag */
        ".Lf40b18_00040ebc:\n"
        "movl -0x64(%ebp), %eax\n" /* line 4107 | anim */
        "movzwl 6(%eax), %edx\n" /* animIndex */
        "leal (%ebx, %edx), %edx\n" /* flag, animIndex */
        "movl %esi, %ecx\n" /* anim */
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4106 | flag */
        "cmpl %ebx, -0x60(%ebp)\n" /* flag, numAnims */
        "jne .Lf40b18_00040ebc\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 4113 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim, numAnims */
        /* { scope 2: anim, numAnims */
        /* { scope 3: anim, numAnims */
        /* { scope 4: anim, numAnims */
        ".Lf40b18_00040ee0:\n"
        "movzbl %al, %esi\n" /* line 4106 | anim */
        "xorl %ebx, %ebx\n" /* flag */
        ".Lf40b18_00040ee5:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 4107 | anim */
        "movzwl 6(%eax), %edx\n" /* animIndex */
        "leal (%ebx, %edx), %edx\n" /* flag, animIndex */
        "movl %esi, %ecx\n" /* anim */
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4106 | flag */
        "cmpl %ebx, -0x48(%ebp)\n" /* flag, numAnims */
        "jne .Lf40b18_00040ee5\n"
        "jmp .Lf40b18_00040c72\n"
        /* } scope */
        ".Lf40b18_00040f06:\n"
        "movzbl %al, %esi\n" /* anim */
        "xorl %ebx, %ebx\n" /* flag */
        ".Lf40b18_00040f0b:\n"
        "movl -0x54(%ebp), %eax\n" /* line 4107 | anim */
        "movzwl 6(%eax), %edx\n" /* animIndex */
        "leal (%ebx, %edx), %edx\n" /* flag, animIndex */
        "movl %esi, %ecx\n" /* anim */
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4106 | flag */
        "cmpl %ebx, -0x50(%ebp)\n" /* flag, numAnims */
        "jne .Lf40b18_00040f0b\n"
        "jmp .Lf40b18_00040bfd\n"
        /* } scope */
        ".Lf40b18_00040f2c:\n"
        "movzbl %al, %esi\n" /* anim */
        "xorl %ebx, %ebx\n" /* flag */
        ".Lf40b18_00040f31:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 4107 | anim */
        "movzwl 6(%eax), %edx\n" /* animIndex */
        "leal (%ebx, %edx), %edx\n" /* flag, animIndex */
        "movl %esi, %ecx\n" /* anim */
        "movl -0x68(%ebp), %eax\n"
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4106 | flag */
        "cmpl %ebx, -0x58(%ebp)\n" /* flag, numAnims */
        "jne .Lf40b18_00040f31\n"
        "jmp .Lf40b18_00040b88\n"
        /* { scope 3: anim, numAnims */
        /* { scope 4: anim, numAnims */
        /* { scope 5: anim, numAnims */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf40b18_00040f52:\n"
        "movl $str_00217b98, 4(%esp)\n" /* line 4102 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf40b18_00040db8\n"
        /* } scope */
        ".Lf40b18_00040f6b:\n"
        "movl $str_00217b98, 4(%esp)\n" /* "animation cannot be sync looping and sync nonlooping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf40b18_00040d43\n"
        /* } scope */
        ".Lf40b18_00040f84:\n"
        "movl $str_00217b98, 4(%esp)\n" /* "animation cannot be sync looping and sync nonlooping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf40b18_00040cce\n"
        /* } scope */
        ".Lf40b18_00040f9d:\n"
        "movl $str_00217b98, 4(%esp)\n" /* "animation cannot be sync looping and sync nonlooping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf40b18_00040c59\n"
        /* } scope */
        ".Lf40b18_00040fb6:\n"
        "movl $str_00217b98, 4(%esp)\n" /* "animation cannot be sync looping and sync nonlooping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf40b18_00040be4\n"
        /* } scope */
        ".Lf40b18_00040fcf:\n"
        "movl $str_00217b98, 4(%esp)\n" /* "animation cannot be sync looping and sync nonlooping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf40b18_00040b6f\n"
        /* } scope */
        ".Lf40b18_00040fe8:\n"
        "movl $str_00217b98, 4(%esp)\n" /* "animation cannot be sync looping and sync nonlooping" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf40b18_00040e24\n"
    );
}

/* line 4116 */
__attribute__((naked))
void XAnimSetupSyncNodes(XAnim *anims)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4116 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %esi\n" /* line 4093 | anims, anim */
        "addl $0xc, %esi\n" /* anim */
        "movl 8(%ebp), %edx\n" /* line 4094 | anims */
        "movzwl 0xc(%edx), %eax\n"
        "movzwl %ax, %edi\n" /* numAnims */
        "testw %ax, %ax\n" /* line 4095 */
        "je .Lf41002_0004103f\n"
        "movzwl 4(%esi), %eax\n" /* line 4098 | anim */
        "movl %eax, %ebx\n" /* line 4099 | flag */
        "andl $3, %ebx\n" /* flag */
        "je .Lf41002_00041047\n"
        "cmpl $3, %ebx\n" /* line 4101 | flag */
        "je .Lf41002_00041098\n"
        ".Lf41002_00041030:\n"
        "orw $4, 4(%esi)\n" /* line 4103 | anim */
        "subl $1, %ebx\n" /* line 4105 | flag */
        "sete %al\n"
        "testl %edi, %edi\n" /* line 4106 | numAnims */
        "jg .Lf41002_0004106b\n"
        /* } scope */
        ".Lf41002_0004103f:\n"
        "addl $0x2c, %esp\n" /* line 4119 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf41002_00041047:\n"
        "testl %edi, %edi\n" /* line 4111 | numAnims */
        "jle .Lf41002_0004103f\n"
        "xorl %ebx, %ebx\n" /* line 4106 | flag */
        ".Lf41002_0004104d:\n"
        "movzwl 6(%esi), %edx\n" /* line 4112 | anim */
        "leal (%ebx, %edx), %edx\n" /* flag */
        "movl 8(%ebp), %eax\n" /* anims */
        "calll XAnimSetupSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4111 | flag */
        "cmpl %ebx, %edi\n" /* flag, numAnims */
        "jne .Lf41002_0004104d\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 4119 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf41002_0004106b:\n"
        "movzbl %al, %eax\n" /* line 4106 */
        "movl %eax, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n" /* flag */
        "movl %eax, %ecx\n"
        "jmp .Lf41002_0004107a\n"
        ".Lf41002_00041077:\n"
        "movl -0x1c(%ebp), %ecx\n"
        ".Lf41002_0004107a:\n"
        "movzwl 6(%esi), %edx\n" /* line 4107 | anim */
        "leal (%ebx, %edx), %edx\n" /* flag */
        "movl 8(%ebp), %eax\n" /* anims */
        "calll XAnimFillInSyncNodes_r\n"
        "addl $1, %ebx\n" /* line 4106 | flag */
        "cmpl %ebx, %edi\n" /* flag, numAnims */
        "jne .Lf41002_00041077\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 4119 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf41002_00041098:\n"
        "movl $str_00217b98, 4(%esp)\n" /* line 4102 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf41002_00041030\n"
    );
}

/* line 1507 */
static __attribute__((naked))
void XAnimProcessClientNotify(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1507 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movaps %xmm0, %xmm4\n" /* dtime */
        /* { scope 1: notifyType, notifyType, notetrackName, notetrackName, ... */
        "leal 0xc(%eax), %ecx\n" /* line 1515 | info */
        "movl %ecx, -0x54(%ebp)\n" /* state */
        "movzwl 6(%eax), %ecx\n" /* line 1521 | info */
        "testw %cx, %cx\n" /* line 1522 */
        "je .Lf410ae_000411bc\n"
        "movl -0x54(%ebp), %ebx\n" /* line 1527 | state, i */
        "movss 4(%ebx), %xmm1\n" /* i */
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        "ucomiss %xmm5, %xmm1\n"
        "jne .Lf410ae_000411c7\n"
        "jp .Lf410ae_000411c7\n"
        "movzwl %cx, %ecx\n" /* line 1529 */
        "movl %ecx, -0x50(%ebp)\n" /* notifyType */
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "je .Lf410ae_00041125\n"
        ".Lf410ae_000410fa:\n"
        "movl -0x54(%ebp), %eax\n" /* line 1425 | state */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf410ae_00041418\n"
        "ucomiss %xmm5, %xmm0\n" /* line 1427 */
        "jbe .Lf410ae_00041be2\n"
        "movaps %xmm5, %xmm0\n" /* line 1428 */
        "subss 4(%eax), %xmm0\n"
        "addss %xmm5, %xmm0\n"
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004112a\n"
        ".Lf410ae_00041125:\n"
        "jp .Lf410ae_000410fa\n" /* line 1422 */
        ".Lf410ae_00041127:\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        ".Lf410ae_0004112a:\n"
        "movl g_end, %edi\n" /* line 1529 | notetrackName */
        /* { scope 2 */
        /* { scope 3 */
        "movl g_notifyListSize, %esi\n" /* line 1490 | i */
        "subl $1, %esi\n" /* i */
        "js .Lf410ae_0004117c\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 1492 | i */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jae .Lf410ae_0004117c\n"
        "movl %esi, %ecx\n" /* line 1494 | i */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf410ae_0004114f:\n"
        "movl (%edx), %eax\n" /* line 1495 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "subl $1, %ecx\n" /* line 1490 */
        "cmpl %ebx, %esi\n" /* i */
        "je .Lf410ae_0004117a\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1492 */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "addl $1, %ebx\n" /* i */
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jb .Lf410ae_0004114f\n"
        ".Lf410ae_0004117a:\n"
        "movl %ecx, %esi\n" /* line 1490 | i */
        ".Lf410ae_0004117c:\n"
        "leal (%esi, %esi, 2), %ebx\n" /* line 1498 | i */
        "leal 0xc(, %ebx, 4), %ebx\n" /* i */
        "leal g_notifyList(%ebx), %esi\n" /* i */
        "movl %edi, (%esp)\n" /* line 1499 */
        "movss %xmm0, -0x88(%ebp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, g_notifyList(%ebx)\n" /* i */
        "movss -0x88(%ebp), %xmm0\n" /* line 1500 */
        "movss %xmm0, 8(%esi)\n" /* i */
        "movl -0x50(%ebp), %eax\n" /* line 1501 | notifyType */
        "movl %eax, 4(%esi)\n" /* i */
        "addl $1, g_notifyListSize\n" /* line 1503 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf410ae_000411bc:\n"
        "addl $0xac, %esp\n" /* line 1621 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: notifyType, notifyType, notetrackName, notetrackName, ... */
        ".Lf410ae_000411c7:\n"
        "cmpw $0, (%edx)\n" /* line 1533 | anim */
        "je .Lf410ae_00041299\n"
        "movl -0x54(%ebp), %ebx\n" /* line 1535 | state, i */
        "movss (%ebx), %xmm2\n" /* i */
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lf410ae_000411e4\n"
        "ucomiss %xmm5, %xmm2\n"
        "jne .Lf410ae_000411bc\n"
        "jp .Lf410ae_000411bc\n"
        ".Lf410ae_000411e4:\n"
        "movzwl %cx, %ecx\n" /* line 1536 */
        "movl %ecx, -0x4c(%ebp)\n" /* notifyType */
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "jne .Lf410ae_000415b5\n"
        "jp .Lf410ae_000415b5\n"
        ".Lf410ae_000411f9:\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        ".Lf410ae_000411fc:\n"
        "movl g_end, %edi\n" /* line 1536 | notetrackName */
        /* { scope 2 */
        /* { scope 3 */
        "movl g_notifyListSize, %esi\n" /* line 1490 | i */
        "subl $1, %esi\n" /* i */
        "js .Lf410ae_0004124e\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 1492 | i */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jae .Lf410ae_0004124e\n"
        "movl %esi, %ecx\n" /* line 1494 | i */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf410ae_00041221:\n"
        "movl (%edx), %eax\n" /* line 1495 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "subl $1, %ecx\n" /* line 1490 */
        "cmpl %ebx, %esi\n" /* i */
        "je .Lf410ae_0004124c\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1492 */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "addl $1, %ebx\n" /* i */
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jb .Lf410ae_00041221\n"
        ".Lf410ae_0004124c:\n"
        "movl %ecx, %esi\n" /* line 1490 | i */
        ".Lf410ae_0004124e:\n"
        "leal (%esi, %esi, 2), %ebx\n" /* line 1498 | i */
        "leal 0xc(, %ebx, 4), %ebx\n" /* i */
        "leal g_notifyList(%ebx), %esi\n" /* i */
        "movl %edi, (%esp)\n" /* line 1499 */
        "movss %xmm0, -0x88(%ebp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, g_notifyList(%ebx)\n" /* i */
        "movss -0x88(%ebp), %xmm0\n" /* line 1500 */
        "movss %xmm0, 8(%esi)\n" /* i */
        "movl -0x4c(%ebp), %eax\n" /* line 1501 | notifyType */
        "movl %eax, 4(%esi)\n" /* i */
        "addl $1, g_notifyListSize\n" /* line 1503 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0xac, %esp\n" /* line 1621 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: notifyType, notifyType, notetrackName, notetrackName, ... */
        ".Lf410ae_00041299:\n"
        "movl 4(%edx), %edx\n" /* line 1540 | anim */
        "movl %edx, -0x6c(%ebp)\n" /* anim, parts */
        /* { scope 2 */
        "movl 0x1c(%edx), %esi\n" /* line 1389 */
        "movzbl 0xc(%edx), %ebx\n" /* line 1391 */
        "testl %ebx, %ebx\n"
        "jg .Lf410ae_00041582\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf410ae_000412b0:\n"
        "subl %esi, %eax\n" /* line 1543 | i, info */
        "shrl $3, %eax\n" /* info */
        "movw %ax, -0x68(%ebp)\n" /* info, notifyIndex */
        "movzwl %ax, %eax\n" /* line 1547 | info */
        "leal (%esi, %eax, 8), %edi\n" /* i, notetrackName */
        "movl -0x54(%ebp), %ebx\n" /* line 1549 | state, i */
        "movss (%ebx), %xmm2\n" /* i */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf410ae_00041446\n"
        "movss 4(%edi), %xmm3\n" /* line 1551 | notetrackName */
        "ucomiss %xmm3, %xmm2\n"
        "ja .Lf410ae_00041733\n"
        "ucomiss %xmm3, %xmm1\n" /* line 1563 */
        "ja .Lf410ae_000411bc\n"
        "movzwl %cx, %ecx\n" /* line 1564 */
        "movl %ecx, -0x28(%ebp)\n"
        "movl g_notifyListSize, %ecx\n"
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "jne .Lf410ae_000413e6\n"
        ".Lf410ae_000412fb:\n"
        "jp .Lf410ae_000413e6\n"
        ".Lf410ae_00041301:\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        ".Lf410ae_00041304:\n"
        "movzwl (%edi), %eax\n" /* line 1569 | notetrackName, info */
        "movl %eax, -0x44(%ebp)\n" /* info, notetrackName */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %ebx\n" /* line 1490 | i */
        "subl $1, %ebx\n" /* i */
        "js .Lf410ae_00041352\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1492 | i */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jae .Lf410ae_00041352\n"
        "movl %ebx, %ecx\n" /* line 1494 | i */
        "xorl %esi, %esi\n" /* i */
        ".Lf410ae_00041325:\n"
        "movl (%edx), %eax\n" /* line 1495 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "subl $1, %ecx\n" /* line 1490 */
        "cmpl %esi, %ebx\n" /* i */
        "je .Lf410ae_00041350\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1492 */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "addl $1, %esi\n" /* i */
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jb .Lf410ae_00041325\n"
        ".Lf410ae_00041350:\n"
        "movl %ecx, %ebx\n" /* line 1490 | i */
        ".Lf410ae_00041352:\n"
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 1498 | i */
        "leal 0xc(, %ebx, 4), %ebx\n" /* i */
        "leal g_notifyList(%ebx), %esi\n" /* i */
        "movl -0x44(%ebp), %ecx\n" /* line 1499 | notetrackName */
        "movl %ecx, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, g_notifyList(%ebx)\n" /* i */
        "movss -0x88(%ebp), %xmm0\n" /* line 1500 */
        "movss %xmm0, 8(%esi)\n" /* i */
        "movl -0x28(%ebp), %ebx\n" /* line 1501 | i */
        "movl %ebx, 4(%esi)\n" /* i */
        "movl g_notifyListSize, %ecx\n" /* line 1503 */
        "addl $1, %ecx\n"
        "movl %ecx, g_notifyListSize\n"
        /* } scope */
        /* } scope */
        "addl $8, %edi\n" /* line 1570 | notetrackName */
        "addw $1, -0x68(%ebp)\n" /* line 1571 | notifyIndex */
        "movzwl -0x68(%ebp), %edx\n" /* line 1566 | notifyIndex, anim */
        "movl -0x6c(%ebp), %ebx\n" /* parts, i */
        "movzbl 0xc(%ebx), %eax\n" /* i, info */
        "cmpl %eax, %edx\n" /* info, anim */
        "movss -0x98(%ebp), %xmm4\n" /* dtime */
        "jae .Lf410ae_00041a2c\n"
        "movl -0x54(%ebp), %eax\n" /* state, info */
        "movss 4(%eax), %xmm1\n" /* info */
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        "movss 4(%edi), %xmm3\n" /* notetrackName */
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "je .Lf410ae_000412fb\n"
        ".Lf410ae_000413e6:\n"
        "movl -0x54(%ebp), %ebx\n" /* line 1425 | state */
        "movss (%ebx), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf410ae_000418e4\n"
        "ucomiss %xmm3, %xmm0\n" /* line 1427 */
        "jbe .Lf410ae_000419a9\n"
        "movaps %xmm3, %xmm0\n" /* line 1428 */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041304\n"
        ".Lf410ae_00041418:\n"
        "ucomiss %xmm5, %xmm0\n" /* line 1436 */
        "jbe .Lf410ae_00041bce\n"
        ".Lf410ae_00041421:\n"
        "ucomiss %xmm1, %xmm5\n"
        "jb .Lf410ae_00041127\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        "movl -0x54(%ebp), %ebx\n" /* state */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004112a\n"
        ".Lf410ae_00041446:\n"
        "ucomiss %xmm5, %xmm2\n" /* line 1590 */
        "je .Lf410ae_000415ec\n"
        ".Lf410ae_0004144f:\n"
        "movss 4(%edi), %xmm3\n" /* line 1608 | notetrackName */
        "ucomiss %xmm2, %xmm3\n"
        "jae .Lf410ae_000411bc\n"
        "ucomiss %xmm3, %xmm1\n" /* line 1611 */
        "ja .Lf410ae_000411bc\n"
        "movzwl %cx, %ecx\n" /* line 1612 */
        "movl %ecx, -0x34(%ebp)\n"
        "leal 0xc(%edi), %ecx\n" /* notetrackName */
        "movl %ecx, -0x1c(%ebp)\n"
        "movl g_notifyListSize, %ecx\n"
        ".Lf410ae_00041478:\n"
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "jne .Lf410ae_00041956\n"
        "jp .Lf410ae_00041956\n"
        ".Lf410ae_00041487:\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        ".Lf410ae_0004148a:\n"
        "movzwl (%edi), %ebx\n" /* line 1617 | notetrackName, i */
        "movl %ebx, -0x38(%ebp)\n" /* i, notetrackName */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %ebx\n" /* line 1490 | i */
        "subl $1, %ebx\n" /* i */
        "js .Lf410ae_000414d8\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1492 | i */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jae .Lf410ae_000414d8\n"
        "movl %ebx, %ecx\n" /* line 1494 | i */
        "xorl %esi, %esi\n" /* i */
        ".Lf410ae_000414ab:\n"
        "movl (%edx), %eax\n" /* line 1495 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "subl $1, %ecx\n" /* line 1490 */
        "cmpl %esi, %ebx\n" /* i */
        "je .Lf410ae_000414d6\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1492 */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "addl $1, %esi\n" /* i */
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jb .Lf410ae_000414ab\n"
        ".Lf410ae_000414d6:\n"
        "movl %ecx, %ebx\n" /* line 1490 | i */
        ".Lf410ae_000414d8:\n"
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 1498 | i */
        "leal 0xc(, %ebx, 4), %ebx\n" /* i */
        "leal g_notifyList(%ebx), %esi\n" /* i */
        "movl -0x38(%ebp), %eax\n" /* line 1499 | notetrackName */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, g_notifyList(%ebx)\n" /* i */
        "movss -0x88(%ebp), %xmm0\n" /* line 1500 */
        "movss %xmm0, 8(%esi)\n" /* i */
        "movl -0x34(%ebp), %ecx\n" /* line 1501 */
        "movl %ecx, 4(%esi)\n" /* i */
        "movl g_notifyListSize, %eax\n" /* line 1503 */
        "addl $1, %eax\n"
        "movl %eax, %ecx\n"
        "movl %eax, g_notifyListSize\n"
        /* } scope */
        /* } scope */
        "addl $8, %edi\n" /* line 1618 | notetrackName */
        "addw $1, -0x68(%ebp)\n" /* line 1619 | notifyIndex */
        "movzwl -0x68(%ebp), %edx\n" /* line 1614 | notifyIndex, anim */
        "movl -0x6c(%ebp), %ebx\n" /* parts, i */
        "movzbl 0xc(%ebx), %eax\n" /* i, info */
        "cmpl %eax, %edx\n" /* info, anim */
        "movss -0x98(%ebp), %xmm4\n" /* dtime */
        "jae .Lf410ae_000411bc\n"
        "movl -0x1c(%ebp), %eax\n" /* info */
        "movss (%eax), %xmm0\n" /* info */
        "addl $8, %eax\n" /* info */
        "movl %eax, -0x1c(%ebp)\n" /* info */
        "movl -0x54(%ebp), %ebx\n" /* state, i */
        "movss (%ebx), %xmm2\n" /* i */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf410ae_000411bc\n"
        "movss 4(%ebx), %xmm1\n" /* i */
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        "movss 4(%edi), %xmm3\n" /* notetrackName */
        "jmp .Lf410ae_00041478\n"
        /* { scope 2 */
        ".Lf410ae_00041582:\n"
        "movl %esi, %eax\n" /* line 1391 */
        "movss lit4_002ed62c, %xmm2\n" /* 2.0f */
        "xorl %edx, %edx\n"
        "xorl %edi, %edi\n"
        ".Lf410ae_00041590:\n"
        "movss 4(%eax), %xmm0\n" /* line 1393 */
        "ucomiss %xmm0, %xmm1\n" /* line 1395 */
        "ja .Lf410ae_000415a4\n"
        "ucomiss %xmm0, %xmm2\n" /* line 1397 */
        "jbe .Lf410ae_000415a4\n"
        "movl %eax, %edi\n"
        "movaps %xmm0, %xmm2\n"
        ".Lf410ae_000415a4:\n"
        "addl $1, %edx\n" /* line 1391 */
        "addl $8, %eax\n"
        "cmpl %edx, %ebx\n"
        "jne .Lf410ae_00041590\n"
        "movl %edi, %eax\n"
        "jmp .Lf410ae_000412b0\n"
        /* } scope */
        ".Lf410ae_000415b5:\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1425 */
        "ja .Lf410ae_00041883\n"
        "ucomiss %xmm5, %xmm2\n" /* line 1436 */
        "jbe .Lf410ae_00041c51\n"
        ".Lf410ae_000415c7:\n"
        "ucomiss %xmm1, %xmm5\n"
        "jb .Lf410ae_000411f9\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        "movl -0x54(%ebp), %ebx\n" /* state */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_000411fc\n"
        ".Lf410ae_000415ec:\n"
        "jp .Lf410ae_0004144f\n" /* line 1590 */
        "ucomiss 4(%edi), %xmm1\n" /* line 1594 | notetrackName */
        "ja .Lf410ae_000411bc\n"
        "movzwl %cx, %ecx\n" /* line 1595 */
        "movl %ecx, -0x30(%ebp)\n"
        "movl g_notifyListSize, %ecx\n"
        "movss 4(%edi), %xmm2\n" /* line 1600 | notetrackName, time */
        /* { scope 2 */
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "jne .Lf410ae_00041701\n"
        ".Lf410ae_00041616:\n"
        "jp .Lf410ae_00041701\n"
        ".Lf410ae_0004161c:\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        /* } scope */
        ".Lf410ae_0004161f:\n"
        "movzwl (%edi), %ebx\n" /* line 1600 | notetrackName, i */
        "movl %ebx, -0x3c(%ebp)\n" /* i, notetrackName */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %ebx\n" /* line 1490 | i */
        "subl $1, %ebx\n" /* i */
        "js .Lf410ae_0004166d\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1492 | i */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jae .Lf410ae_0004166d\n"
        "movl %ebx, %ecx\n" /* line 1494 | i */
        "xorl %esi, %esi\n" /* i */
        ".Lf410ae_00041640:\n"
        "movl (%edx), %eax\n" /* line 1495 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "subl $1, %ecx\n" /* line 1490 */
        "cmpl %esi, %ebx\n" /* i */
        "je .Lf410ae_0004166b\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1492 */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "addl $1, %esi\n" /* i */
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jb .Lf410ae_00041640\n"
        ".Lf410ae_0004166b:\n"
        "movl %ecx, %ebx\n" /* line 1490 | i */
        ".Lf410ae_0004166d:\n"
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 1498 | i */
        "leal 0xc(, %ebx, 4), %ebx\n" /* i */
        "leal g_notifyList(%ebx), %esi\n" /* i */
        "movl -0x3c(%ebp), %eax\n" /* line 1499 | notetrackName */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, g_notifyList(%ebx)\n" /* i */
        "movss -0x88(%ebp), %xmm0\n" /* line 1500 */
        "movss %xmm0, 8(%esi)\n" /* i */
        "movl -0x30(%ebp), %ecx\n" /* line 1501 */
        "movl %ecx, 4(%esi)\n" /* i */
        "movl g_notifyListSize, %ecx\n" /* line 1503 */
        "addl $1, %ecx\n"
        "movl %ecx, g_notifyListSize\n"
        /* } scope */
        /* } scope */
        "addl $8, %edi\n" /* line 1601 | notetrackName */
        "addw $1, -0x68(%ebp)\n" /* line 1602 | notifyIndex */
        "movzwl -0x68(%ebp), %edx\n" /* line 1597 | notifyIndex, anim */
        "movl -0x6c(%ebp), %ebx\n" /* parts, i */
        "movzbl 0xc(%ebx), %eax\n" /* i, info */
        "cmpl %eax, %edx\n" /* info, anim */
        "movss -0x98(%ebp), %xmm4\n" /* dtime */
        "jae .Lf410ae_000411bc\n"
        "movl -0x54(%ebp), %eax\n" /* state, info */
        "movss 4(%eax), %xmm1\n" /* info */
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        "movss 4(%edi), %xmm2\n" /* line 1600 | notetrackName, time */
        /* { scope 2 */
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "je .Lf410ae_00041616\n"
        ".Lf410ae_00041701:\n"
        "movl -0x54(%ebp), %eax\n" /* line 1425 | state */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf410ae_0004191d\n"
        "ucomiss %xmm2, %xmm0\n" /* line 1427 */
        "jbe .Lf410ae_000419ce\n"
        "movaps %xmm2, %xmm0\n" /* line 1428 */
        "subss 4(%eax), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004161f\n"
        /* } scope */
        ".Lf410ae_00041733:\n"
        "movzwl %cx, %ecx\n" /* line 1551 */
        "movl %ecx, -0x2c(%ebp)\n"
        "leal 0xc(%edi), %eax\n" /* notetrackName, info */
        "movl %eax, -0x24(%ebp)\n" /* info */
        "movl g_notifyListSize, %ecx\n"
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "jne .Lf410ae_00041859\n"
        ".Lf410ae_0004174e:\n"
        "jp .Lf410ae_00041859\n"
        ".Lf410ae_00041754:\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        ".Lf410ae_00041757:\n"
        "movzwl (%edi), %ebx\n" /* line 1555 | notetrackName, i */
        "movl %ebx, -0x48(%ebp)\n" /* i, notetrackName */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %ebx\n" /* line 1490 | i */
        "subl $1, %ebx\n" /* i */
        "js .Lf410ae_000418a4\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1492 | i */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jae .Lf410ae_000418a4\n"
        "movl %ebx, %ecx\n" /* line 1494 | i */
        "xorl %esi, %esi\n" /* i */
        ".Lf410ae_00041780:\n"
        "movl (%edx), %eax\n" /* line 1495 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "subl $1, %ecx\n" /* line 1490 */
        "cmpl %esi, %ebx\n" /* i */
        "je .Lf410ae_000417ab\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1492 */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "addl $1, %esi\n" /* i */
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jb .Lf410ae_00041780\n"
        ".Lf410ae_000417ab:\n"
        "leal (%ecx, %ecx, 2), %ebx\n" /* line 1498 | i */
        "leal 0xc(, %ebx, 4), %ebx\n" /* i */
        "leal g_notifyList(%ebx), %esi\n" /* i */
        "movl -0x48(%ebp), %eax\n" /* line 1499 | notetrackName */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, g_notifyList(%ebx)\n" /* i */
        "movss -0x88(%ebp), %xmm0\n" /* line 1500 */
        "movss %xmm0, 8(%esi)\n" /* i */
        "movl -0x2c(%ebp), %ecx\n" /* line 1501 */
        "movl %ecx, 4(%esi)\n" /* i */
        "movl g_notifyListSize, %ecx\n" /* line 1503 */
        "addl $1, %ecx\n"
        "movl %ecx, g_notifyListSize\n"
        /* } scope */
        /* } scope */
        "addl $8, %edi\n" /* line 1556 | notetrackName */
        "addw $1, -0x68(%ebp)\n" /* line 1557 | notifyIndex */
        "movzwl -0x68(%ebp), %edx\n" /* line 1553 | notifyIndex, anim */
        "movl -0x6c(%ebp), %ebx\n" /* parts, i */
        "movzbl 0xc(%ebx), %eax\n" /* i, info */
        "cmpl %eax, %edx\n" /* info, anim */
        "movss -0x98(%ebp), %xmm4\n" /* dtime */
        "jae .Lf410ae_000411bc\n"
        "movl -0x24(%ebp), %eax\n" /* info */
        "movss (%eax), %xmm0\n" /* info */
        "addl $8, %eax\n" /* info */
        "movl %eax, -0x24(%ebp)\n" /* info */
        "movl -0x54(%ebp), %ebx\n" /* state, i */
        "movss (%ebx), %xmm2\n" /* i */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf410ae_000411bc\n"
        "movss 4(%ebx), %xmm1\n" /* i */
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        "movss 4(%edi), %xmm3\n" /* notetrackName */
        "ucomiss %xmm5, %xmm1\n" /* line 1422 */
        "je .Lf410ae_0004174e\n"
        ".Lf410ae_00041859:\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1425 */
        "jbe .Lf410ae_000418ab\n"
        "ucomiss %xmm3, %xmm2\n" /* line 1427 */
        "jbe .Lf410ae_00041984\n"
        "movaps %xmm3, %xmm0\n" /* line 1428 */
        "movl -0x54(%ebp), %eax\n" /* state */
        "subss 4(%eax), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041757\n"
        ".Lf410ae_00041883:\n"
        "ucomiss %xmm5, %xmm2\n" /* line 1427 */
        "jbe .Lf410ae_00041c2c\n"
        "movaps %xmm5, %xmm0\n" /* line 1428 */
        "movl -0x54(%ebp), %eax\n" /* state */
        "subss 4(%eax), %xmm0\n"
        "addss %xmm5, %xmm0\n"
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_000411fc\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf410ae_000418a4:\n"
        "movl %ebx, %ecx\n" /* line 1490 | i */
        "jmp .Lf410ae_000417ab\n"
        /* } scope */
        /* } scope */
        ".Lf410ae_000418ab:\n"
        "ucomiss %xmm3, %xmm2\n" /* line 1436 */
        "ja .Lf410ae_000418bf\n"
        "ucomiss %xmm5, %xmm2\n"
        "jne .Lf410ae_00041754\n"
        "jp .Lf410ae_00041754\n"
        ".Lf410ae_000418bf:\n"
        "ucomiss %xmm1, %xmm3\n"
        "jb .Lf410ae_00041754\n"
        "movaps %xmm3, %xmm0\n" /* line 1437 */
        "movl -0x54(%ebp), %eax\n" /* state */
        "subss 4(%eax), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041757\n"
        ".Lf410ae_000418e4:\n"
        "ucomiss %xmm3, %xmm0\n" /* line 1436 */
        "ja .Lf410ae_000418f8\n"
        "ucomiss %xmm5, %xmm0\n"
        "jne .Lf410ae_00041301\n"
        "jp .Lf410ae_00041301\n"
        ".Lf410ae_000418f8:\n"
        "ucomiss %xmm1, %xmm3\n"
        "jb .Lf410ae_00041301\n"
        "movaps %xmm3, %xmm0\n" /* line 1437 */
        "movl -0x54(%ebp), %ebx\n" /* state */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041304\n"
        /* { scope 2 */
        ".Lf410ae_0004191d:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 1436 */
        "ja .Lf410ae_00041931\n"
        "ucomiss %xmm5, %xmm0\n"
        "jne .Lf410ae_0004161c\n"
        "jp .Lf410ae_0004161c\n"
        ".Lf410ae_00041931:\n"
        "ucomiss %xmm1, %xmm2\n"
        "jb .Lf410ae_0004161c\n"
        "movaps %xmm2, %xmm0\n" /* line 1437 */
        "movl -0x54(%ebp), %eax\n" /* state */
        "subss 4(%eax), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004161f\n"
        /* } scope */
        ".Lf410ae_00041956:\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1425 */
        "jbe .Lf410ae_000419f3\n"
        "ucomiss %xmm3, %xmm2\n" /* line 1427 */
        "jbe .Lf410ae_00041c07\n"
        "movaps %xmm3, %xmm0\n" /* line 1428 */
        "movl -0x54(%ebp), %eax\n" /* state */
        "subss 4(%eax), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004148a\n"
        ".Lf410ae_00041984:\n"
        "ucomiss %xmm1, %xmm3\n" /* line 1430 */
        "jb .Lf410ae_00041754\n"
        "movaps %xmm3, %xmm0\n" /* line 1431 */
        "movl -0x54(%ebp), %ebx\n" /* state */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041757\n"
        ".Lf410ae_000419a9:\n"
        "ucomiss %xmm1, %xmm3\n" /* line 1430 */
        "jb .Lf410ae_00041301\n"
        "movaps %xmm3, %xmm0\n" /* line 1431 */
        "movl -0x54(%ebp), %eax\n" /* state */
        "subss 4(%eax), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041304\n"
        /* { scope 2 */
        ".Lf410ae_000419ce:\n"
        "ucomiss %xmm1, %xmm2\n" /* line 1430 */
        "jb .Lf410ae_0004161c\n"
        "movaps %xmm2, %xmm0\n" /* line 1431 */
        "movl -0x54(%ebp), %ebx\n" /* state */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004161f\n"
        /* } scope */
        ".Lf410ae_000419f3:\n"
        "ucomiss %xmm3, %xmm2\n" /* line 1436 */
        "ja .Lf410ae_00041a07\n"
        "ucomiss %xmm5, %xmm2\n"
        "jne .Lf410ae_00041487\n"
        "jp .Lf410ae_00041487\n"
        ".Lf410ae_00041a07:\n"
        "ucomiss %xmm1, %xmm3\n"
        "jb .Lf410ae_00041487\n"
        "movaps %xmm3, %xmm0\n" /* line 1437 */
        "movl -0x54(%ebp), %eax\n" /* state */
        "subss 4(%eax), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004148a\n"
        ".Lf410ae_00041a2c:\n"
        "movl 0x1c(%ebx), %edi\n" /* line 1577 | i, notetrackName */
        "movss 4(%edi), %xmm1\n" /* notetrackName */
        "movl -0x54(%ebp), %eax\n" /* state, info */
        "movss (%eax), %xmm2\n" /* info */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf410ae_000411bc\n"
        "leal 0x14(%edi), %ebx\n" /* notetrackName, i */
        "movl %ebx, -0x20(%ebp)\n" /* i */
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        ".Lf410ae_00041a52:\n"
        "movl -0x54(%ebp), %eax\n" /* line 1422 | state */
        "movss 4(%eax), %xmm0\n"
        "ucomiss %xmm5, %xmm0\n"
        "jne .Lf410ae_00041b4a\n"
        "jp .Lf410ae_00041b4a\n"
        ".Lf410ae_00041a69:\n"
        "movaps %xmm5, %xmm0\n" /* line 1437 */
        ".Lf410ae_00041a6c:\n"
        "movzwl (%edi), %eax\n" /* line 1579 | notetrackName, info */
        "movl %eax, -0x40(%ebp)\n" /* info, notetrackName */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %ebx\n" /* line 1490 | i */
        "subl $1, %ebx\n" /* i */
        "js .Lf410ae_00041aba\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1492 | i */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jae .Lf410ae_00041aba\n"
        "movl %ebx, %ecx\n" /* line 1494 | i */
        "xorl %esi, %esi\n" /* i */
        ".Lf410ae_00041a8d:\n"
        "movl (%edx), %eax\n" /* line 1495 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "subl $1, %ecx\n" /* line 1490 */
        "cmpl %esi, %ebx\n" /* i */
        "je .Lf410ae_00041ab8\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1492 */
        "leal g_notifyList(, %eax, 4), %edx\n"
        "addl $1, %esi\n" /* i */
        "ucomiss 8(%edx), %xmm0\n" /* line 1493 */
        "jb .Lf410ae_00041a8d\n"
        ".Lf410ae_00041ab8:\n"
        "movl %ecx, %ebx\n" /* line 1490 | i */
        ".Lf410ae_00041aba:\n"
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 1498 | i */
        "leal 0xc(, %ebx, 4), %ebx\n" /* i */
        "leal g_notifyList(%ebx), %esi\n" /* i */
        "movl -0x40(%ebp), %ecx\n" /* line 1499 | notetrackName */
        "movl %ecx, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm4, -0x98(%ebp)\n"
        "movss %xmm5, -0xa8(%ebp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, g_notifyList(%ebx)\n" /* i */
        "movss -0x88(%ebp), %xmm0\n" /* line 1500 */
        "movss %xmm0, 8(%esi)\n" /* i */
        "movl -0x28(%ebp), %ebx\n" /* line 1501 | i */
        "movl %ebx, 4(%esi)\n" /* i */
        "movl g_notifyListSize, %ecx\n" /* line 1503 */
        "addl $1, %ecx\n"
        "movl %ecx, g_notifyListSize\n"
        /* } scope */
        /* } scope */
        "addl $0x10, %edi\n" /* line 1577 | notetrackName */
        "movl -0x20(%ebp), %eax\n" /* info */
        "movss (%eax), %xmm1\n" /* info */
        "addl $0x10, %eax\n" /* info */
        "movl %eax, -0x20(%ebp)\n" /* info */
        "movl -0x54(%ebp), %ebx\n" /* state, i */
        "movss (%ebx), %xmm2\n" /* i */
        "ucomiss %xmm1, %xmm2\n"
        "movss -0x98(%ebp), %xmm4\n" /* dtime */
        "movss -0xa8(%ebp), %xmm5\n"
        "ja .Lf410ae_00041a52\n"
        "jmp .Lf410ae_000411bc\n"
        ".Lf410ae_00041b4a:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 1425 */
        "jbe .Lf410ae_00041b70\n"
        "ucomiss %xmm1, %xmm2\n" /* line 1427 */
        "jbe .Lf410ae_00041ba9\n"
        "movaps %xmm1, %xmm0\n" /* line 1428 */
        "movl -0x54(%ebp), %ebx\n" /* state */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041a6c\n"
        ".Lf410ae_00041b70:\n"
        "ucomiss %xmm1, %xmm2\n" /* line 1436 */
        "ja .Lf410ae_00041b84\n"
        "ucomiss %xmm5, %xmm2\n"
        "jne .Lf410ae_00041a69\n"
        "jp .Lf410ae_00041a69\n"
        ".Lf410ae_00041b84:\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf410ae_00041a69\n"
        "movaps %xmm1, %xmm0\n" /* line 1437 */
        "movl -0x54(%ebp), %ebx\n" /* state */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041a6c\n"
        ".Lf410ae_00041ba9:\n"
        "ucomiss %xmm0, %xmm1\n" /* line 1430 */
        "jb .Lf410ae_00041a69\n"
        "movaps %xmm1, %xmm0\n" /* line 1431 */
        "movl -0x54(%ebp), %eax\n" /* state */
        "subss 4(%eax), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_00041a6c\n"
        ".Lf410ae_00041bce:\n"
        "ucomiss %xmm5, %xmm0\n" /* line 1436 */
        "jne .Lf410ae_00041127\n"
        "jnp .Lf410ae_00041421\n"
        "jmp .Lf410ae_00041127\n"
        ".Lf410ae_00041be2:\n"
        "ucomiss %xmm1, %xmm5\n" /* line 1430 */
        "jb .Lf410ae_00041127\n"
        "movaps %xmm5, %xmm0\n" /* line 1431 */
        "movl -0x54(%ebp), %ecx\n" /* state */
        "subss 4(%ecx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004112a\n"
        ".Lf410ae_00041c07:\n"
        "ucomiss %xmm1, %xmm3\n" /* line 1430 */
        "jb .Lf410ae_00041487\n"
        "movaps %xmm3, %xmm0\n" /* line 1431 */
        "movl -0x54(%ebp), %ebx\n" /* state */
        "subss 4(%ebx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_0004148a\n"
        ".Lf410ae_00041c2c:\n"
        "ucomiss %xmm1, %xmm5\n" /* line 1430 */
        "jb .Lf410ae_000411f9\n"
        "movaps %xmm5, %xmm0\n" /* line 1431 */
        "movl -0x54(%ebp), %ecx\n" /* state */
        "subss 4(%ecx), %xmm0\n"
        "addss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "divss %xmm4, %xmm0\n"
        "jmp .Lf410ae_000411fc\n"
        ".Lf410ae_00041c51:\n"
        "ucomiss %xmm5, %xmm2\n" /* line 1436 */
        "jne .Lf410ae_000411f9\n"
        "jnp .Lf410ae_000415c7\n"
        "jmp .Lf410ae_000411f9\n"
    );
}

/* line 1624 */
static __attribute__((naked))
void XAnimUpdateInfoSyncInternal(XAnimState *syncState, float dtime)
{
    __asm__ __volatile__ (
        ".Lf41c66_00041c66:\n"
        "pushl %ebp\n" /* line 1624 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl %eax, %edi\n" /* tree */
        "movss %xmm0, -0x80(%ebp)\n"
        "movl %ecx, %esi\n" /* bNotify */
        /* { scope 1: bNotify */
        "movzwl 8(%eax, %edx, 2), %eax\n" /* line 1637 */
        "testw %ax, %ax\n" /* line 1638 */
        "je .Lf41c66_000421da\n"
        "movzwl %ax, %eax\n" /* line 1642 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* info */
        "movl %eax, %ebx\n" /* line 1643 | state */
        "addl $0xc, %ebx\n" /* state */
        "pxor %xmm0, %xmm0\n" /* line 1645 */
        "ucomiss 0x14(%ebx), %xmm0\n" /* state */
        "jp .Lf41c66_00041cae\n"
        "je .Lf41c66_000421da\n"
        ".Lf41c66_00041cae:\n"
        "ucomiss 0x10(%ebx), %xmm0\n" /* line 1648 | state */
        "movl $0, %eax\n"
        "cmovel %eax, %esi\n" /* info */
        "cmovpl %ecx, %esi\n" /* info */
        "movl (%edi), %eax\n" /* line 1651 | tree */
        "leal 0xc(%eax, %edx, 8), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* anim */
        "movl 8(%ebp), %eax\n" /* line 1653 | syncState */
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%ebx), %xmm0\n" /* state */
        "jne .Lf41c66_00041ce2\n"
        "jp .Lf41c66_00041ce2\n"
        "movl %eax, %edx\n" /* animIndex */
        "movzwl 0xa(%ebx), %eax\n" /* state */
        "cmpw 0xa(%edx), %ax\n" /* animIndex */
        "je .Lf41c66_00041d03\n"
        ".Lf41c66_00041ce2:\n"
        "movss %xmm0, (%ebx)\n" /* line 1655 | state */
        "movl 8(%ebp), %ecx\n" /* line 1656 | syncState */
        "movzwl 0xa(%ecx), %eax\n"
        "movw %ax, 8(%ebx)\n" /* state */
        "movss %xmm0, 4(%ebx)\n" /* line 1657 | state */
        "movw %ax, 0xa(%ebx)\n" /* line 1658 | state */
        "movl -0x74(%ebp), %eax\n" /* line 1660 | info */
        "movw $0xffff, 2(%eax)\n"
        ".Lf41c66_00041d03:\n"
        "movl %esi, %edx\n" /* line 1663 | info, animIndex */
        "testb %dl, %dl\n" /* animIndex */
        "jne .Lf41c66_0004230f\n"
        "movl 8(%ebp), %edx\n" /* line 1666 | syncState, animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%edx), %eax\n" /* line 1667 | animIndex */
        "movw %ax, 8(%ebx)\n" /* state */
        "movl -0x74(%ebp), %ecx\n" /* line 1669 | info */
        "movw $0xffff, 2(%ecx)\n"
        "movl %esi, %eax\n" /* line 1671 | info */
        "testb %al, %al\n"
        "jne .Lf41c66_00042345\n"
        ".Lf41c66_00041d2f:\n"
        "movl -0x70(%ebp), %edx\n" /* line 1674 | anim, animIndex */
        "movzwl (%edx), %edx\n" /* animIndex */
        "movl %edx, -0x78(%ebp)\n" /* animIndex, numAnims */
        "testl %edx, %edx\n" /* line 1676 | animIndex */
        "jle .Lf41c66_000421da\n"
        "movl %esi, %eax\n" /* info */
        "movb %al, -0x1d(%ebp)\n"
        "movl $0, -0x7c(%ebp)\n" /* i */
        ".Lf41c66_00041d4c:\n"
        "movl -0x70(%ebp), %edx\n" /* line 1677 | anim, animIndex */
        "movzwl 6(%edx), %eax\n"
        "movl -0x7c(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        /* { scope 2: i, numAnims, anim */
        /* { scope 3: bNotify */
        "movzwl 8(%edi, %edx, 2), %eax\n" /* line 1637 | tree */
        "testw %ax, %ax\n" /* line 1638 */
        "je .Lf41c66_000421ca\n"
        "movzwl %ax, %eax\n" /* line 1642 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %esi\n" /* info */
        "leal 0xc(%esi), %ebx\n" /* line 1643 | info, state */
        "pxor %xmm0, %xmm0\n" /* line 1645 */
        "ucomiss 0x14(%ebx), %xmm0\n" /* state */
        "jp .Lf41c66_00041d86\n"
        "je .Lf41c66_000421ca\n"
        ".Lf41c66_00041d86:\n"
        "movb $0, -0x69(%ebp)\n" /* line 1648 | bNotify */
        "ucomiss 0x10(%ebx), %xmm0\n" /* state */
        "movl $0, %ecx\n"
        "movzbl -0x1d(%ebp), %eax\n"
        "cmovnel %eax, %ecx\n"
        "cmovpl %eax, %ecx\n"
        "movb %cl, -0x69(%ebp)\n" /* bNotify */
        "movl (%edi), %eax\n" /* line 1651 | tree */
        "leal 0xc(%eax, %edx, 8), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* anim */
        "movl 8(%ebp), %edx\n" /* line 1653 | syncState, animIndex */
        "movss 4(%edx), %xmm0\n" /* animIndex */
        "ucomiss 4(%ebx), %xmm0\n" /* state */
        "jne .Lf41c66_00041dc3\n"
        "jp .Lf41c66_00041dc3\n"
        "movzwl 0xa(%ebx), %eax\n" /* state */
        "cmpw 0xa(%edx), %ax\n" /* animIndex */
        "je .Lf41c66_00041de1\n"
        ".Lf41c66_00041dc3:\n"
        "movss %xmm0, (%ebx)\n" /* line 1655 | state */
        "movl 8(%ebp), %ecx\n" /* line 1656 | syncState */
        "movzwl 0xa(%ecx), %eax\n"
        "movw %ax, 8(%ebx)\n" /* state */
        "movss %xmm0, 4(%ebx)\n" /* line 1657 | state */
        "movw %ax, 0xa(%ebx)\n" /* line 1658 | state */
        "movw $0xffff, 2(%esi)\n" /* line 1660 | info */
        ".Lf41c66_00041de1:\n"
        "cmpb $0, -0x69(%ebp)\n" /* line 1663 | bNotify */
        "jne .Lf41c66_000422c9\n"
        "movl 8(%ebp), %edx\n" /* line 1666 | syncState, animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%edx), %eax\n" /* line 1667 | animIndex */
        "movw %ax, 8(%ebx)\n" /* state */
        "movw $0xffff, 2(%esi)\n" /* line 1669 | info */
        "cmpb $0, -0x69(%ebp)\n" /* line 1671 | bNotify */
        "jne .Lf41c66_000422fb\n"
        ".Lf41c66_00041e0a:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1674 | anim */
        "movzwl (%ecx), %ecx\n"
        "movl %ecx, -0x64(%ebp)\n" /* numAnims */
        "testl %ecx, %ecx\n" /* line 1676 */
        "jle .Lf41c66_000421ca\n"
        "movzbl -0x69(%ebp), %eax\n" /* bNotify */
        "movb %al, -0x1c(%ebp)\n"
        "movl $0, -0x68(%ebp)\n" /* i */
        ".Lf41c66_00041e29:\n"
        "movl -0x60(%ebp), %edx\n" /* line 1677 | anim, animIndex */
        "movzwl 6(%edx), %eax\n"
        "movl -0x68(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        /* { scope 4: i, numAnims, anim */
        /* { scope 5: bNotify */
        "movzwl 8(%edi, %edx, 2), %eax\n" /* line 1637 | tree */
        "testw %ax, %ax\n" /* line 1638 */
        "je .Lf41c66_000421ba\n"
        "movzwl %ax, %eax\n" /* line 1642 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %esi\n" /* info */
        "leal 0xc(%esi), %ebx\n" /* line 1643 | info, state */
        "pxor %xmm0, %xmm0\n" /* line 1645 */
        "ucomiss 0x14(%ebx), %xmm0\n" /* state */
        "jp .Lf41c66_00041e63\n"
        "je .Lf41c66_000421ba\n"
        ".Lf41c66_00041e63:\n"
        "movb $0, -0x59(%ebp)\n" /* line 1648 | bNotify */
        "ucomiss 0x10(%ebx), %xmm0\n" /* state */
        "movl $0, %ecx\n"
        "movzbl -0x1c(%ebp), %eax\n"
        "cmovnel %eax, %ecx\n"
        "cmovpl %eax, %ecx\n"
        "movb %cl, -0x59(%ebp)\n" /* bNotify */
        "movl (%edi), %eax\n" /* line 1651 | tree */
        "leal 0xc(%eax, %edx, 8), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* anim */
        "movl 8(%ebp), %edx\n" /* line 1653 | syncState, animIndex */
        "movss 4(%edx), %xmm0\n" /* animIndex */
        "ucomiss 4(%ebx), %xmm0\n" /* state */
        "jne .Lf41c66_00041ea0\n"
        "jp .Lf41c66_00041ea0\n"
        "movzwl 0xa(%ebx), %eax\n" /* state */
        "cmpw 0xa(%edx), %ax\n" /* animIndex */
        "je .Lf41c66_00041ebe\n"
        ".Lf41c66_00041ea0:\n"
        "movss %xmm0, (%ebx)\n" /* line 1655 | state */
        "movl 8(%ebp), %ecx\n" /* line 1656 | syncState */
        "movzwl 0xa(%ecx), %eax\n"
        "movw %ax, 8(%ebx)\n" /* state */
        "movss %xmm0, 4(%ebx)\n" /* line 1657 | state */
        "movw %ax, 0xa(%ebx)\n" /* line 1658 | state */
        "movw $0xffff, 2(%esi)\n" /* line 1660 | info */
        ".Lf41c66_00041ebe:\n"
        "cmpb $0, -0x59(%ebp)\n" /* line 1663 | bNotify */
        "jne .Lf41c66_000422b1\n"
        ".Lf41c66_00041ec8:\n"
        "movl 8(%ebp), %edx\n" /* line 1666 | syncState, animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%edx), %eax\n" /* line 1667 | animIndex */
        "movw %ax, 8(%ebx)\n" /* state */
        "movw $0xffff, 2(%esi)\n" /* line 1669 | info */
        "cmpb $0, -0x59(%ebp)\n" /* line 1671 | bNotify */
        "jne .Lf41c66_0004229d\n"
        ".Lf41c66_00041ee7:\n"
        "movl -0x50(%ebp), %ecx\n" /* line 1674 | anim */
        "movzwl (%ecx), %ecx\n"
        "movl %ecx, -0x54(%ebp)\n" /* numAnims */
        "testl %ecx, %ecx\n" /* line 1676 */
        "jle .Lf41c66_000421ba\n"
        "movzbl -0x59(%ebp), %eax\n" /* bNotify */
        "movb %al, -0x1b(%ebp)\n"
        "movl $0, -0x58(%ebp)\n" /* i */
        ".Lf41c66_00041f06:\n"
        "movl -0x50(%ebp), %edx\n" /* line 1677 | anim, animIndex */
        "movzwl 6(%edx), %eax\n"
        "movl -0x58(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        /* { scope 6: i, numAnims, anim */
        /* { scope 7: bNotify */
        "movzwl 8(%edi, %edx, 2), %eax\n" /* line 1637 | tree */
        "testw %ax, %ax\n" /* line 1638 */
        "je .Lf41c66_000421aa\n"
        "movzwl %ax, %eax\n" /* line 1642 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %esi\n" /* info */
        "leal 0xc(%esi), %ebx\n" /* line 1643 | info, state */
        "pxor %xmm0, %xmm0\n" /* line 1645 */
        "ucomiss 0x14(%ebx), %xmm0\n" /* state */
        "jp .Lf41c66_00041f40\n"
        "je .Lf41c66_000421aa\n"
        ".Lf41c66_00041f40:\n"
        "movb $0, -0x49(%ebp)\n" /* line 1648 | bNotify */
        "ucomiss 0x10(%ebx), %xmm0\n" /* state */
        "movl $0, %ecx\n"
        "movzbl -0x1b(%ebp), %eax\n"
        "cmovnel %eax, %ecx\n"
        "cmovpl %eax, %ecx\n"
        "movb %cl, -0x49(%ebp)\n" /* bNotify */
        "movl (%edi), %eax\n" /* line 1651 | tree */
        "leal 0xc(%eax, %edx, 8), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* anim */
        "movl 8(%ebp), %edx\n" /* line 1653 | syncState, animIndex */
        "movss 4(%edx), %xmm0\n" /* animIndex */
        "ucomiss 4(%ebx), %xmm0\n" /* state */
        "jne .Lf41c66_00041f7d\n"
        "jp .Lf41c66_00041f7d\n"
        "movzwl 0xa(%ebx), %eax\n" /* state */
        "cmpw 0xa(%edx), %ax\n" /* animIndex */
        "je .Lf41c66_00041f9b\n"
        ".Lf41c66_00041f7d:\n"
        "movss %xmm0, (%ebx)\n" /* line 1655 | state */
        "movl 8(%ebp), %ecx\n" /* line 1656 | syncState */
        "movzwl 0xa(%ecx), %eax\n"
        "movw %ax, 8(%ebx)\n" /* state */
        "movss %xmm0, 4(%ebx)\n" /* line 1657 | state */
        "movw %ax, 0xa(%ebx)\n" /* line 1658 | state */
        "movw $0xffff, 2(%esi)\n" /* line 1660 | info */
        ".Lf41c66_00041f9b:\n"
        "cmpb $0, -0x49(%ebp)\n" /* line 1663 | bNotify */
        "jne .Lf41c66_00042285\n"
        ".Lf41c66_00041fa5:\n"
        "movl 8(%ebp), %edx\n" /* line 1666 | syncState, animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%edx), %eax\n" /* line 1667 | animIndex */
        "movw %ax, 8(%ebx)\n" /* state */
        "movw $0xffff, 2(%esi)\n" /* line 1669 | info */
        "cmpb $0, -0x49(%ebp)\n" /* line 1671 | bNotify */
        "jne .Lf41c66_00042271\n"
        ".Lf41c66_00041fc4:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 1674 | anim */
        "movzwl (%ecx), %ecx\n"
        "movl %ecx, -0x44(%ebp)\n" /* numAnims */
        "testl %ecx, %ecx\n" /* line 1676 */
        "jle .Lf41c66_000421aa\n"
        "movzbl -0x49(%ebp), %eax\n" /* bNotify */
        "movb %al, -0x1a(%ebp)\n"
        "movl $0, -0x48(%ebp)\n" /* i */
        ".Lf41c66_00041fe3:\n"
        "movl -0x40(%ebp), %edx\n" /* line 1677 | anim, animIndex */
        "movzwl 6(%edx), %eax\n"
        "movl -0x48(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        /* { scope 8: i, numAnims, anim */
        /* { scope 9: bNotify */
        "movzwl 8(%edi, %edx, 2), %eax\n" /* line 1637 | tree */
        "testw %ax, %ax\n" /* line 1638 */
        "je .Lf41c66_0004219a\n"
        "movzwl %ax, %eax\n" /* line 1642 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %esi\n" /* info */
        "leal 0xc(%esi), %ebx\n" /* line 1643 | info, state */
        "pxor %xmm0, %xmm0\n" /* line 1645 */
        "ucomiss 0x14(%ebx), %xmm0\n" /* state */
        "jp .Lf41c66_0004201d\n"
        "je .Lf41c66_0004219a\n"
        ".Lf41c66_0004201d:\n"
        "movb $0, -0x39(%ebp)\n" /* line 1648 | bNotify */
        "ucomiss 0x10(%ebx), %xmm0\n" /* state */
        "movl $0, %ecx\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "cmovnel %eax, %ecx\n"
        "cmovpl %eax, %ecx\n"
        "movb %cl, -0x39(%ebp)\n" /* bNotify */
        "movl (%edi), %eax\n" /* line 1651 | tree */
        "leal 0xc(%eax, %edx, 8), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* anim */
        "movl 8(%ebp), %edx\n" /* line 1653 | syncState, animIndex */
        "movss 4(%edx), %xmm0\n" /* animIndex */
        "ucomiss 4(%ebx), %xmm0\n" /* state */
        "jne .Lf41c66_0004205a\n"
        "jp .Lf41c66_0004205a\n"
        "movzwl 0xa(%ebx), %eax\n" /* state */
        "cmpw 0xa(%edx), %ax\n" /* animIndex */
        "je .Lf41c66_00042078\n"
        ".Lf41c66_0004205a:\n"
        "movss %xmm0, (%ebx)\n" /* line 1655 | state */
        "movl 8(%ebp), %ecx\n" /* line 1656 | syncState */
        "movzwl 0xa(%ecx), %eax\n"
        "movw %ax, 8(%ebx)\n" /* state */
        "movss %xmm0, 4(%ebx)\n" /* line 1657 | state */
        "movw %ax, 0xa(%ebx)\n" /* line 1658 | state */
        "movw $0xffff, 2(%esi)\n" /* line 1660 | info */
        ".Lf41c66_00042078:\n"
        "cmpb $0, -0x39(%ebp)\n" /* line 1663 | bNotify */
        "jne .Lf41c66_00042259\n"
        ".Lf41c66_00042082:\n"
        "movl 8(%ebp), %edx\n" /* line 1666 | syncState, animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%edx), %eax\n" /* line 1667 | animIndex */
        "movw %ax, 8(%ebx)\n" /* state */
        "movw $0xffff, 2(%esi)\n" /* line 1669 | info */
        "cmpb $0, -0x39(%ebp)\n" /* line 1671 | bNotify */
        "jne .Lf41c66_00042245\n"
        ".Lf41c66_000420a1:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 1674 | anim */
        "movzwl (%ecx), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* numAnims */
        "testl %ecx, %ecx\n" /* line 1676 */
        "jle .Lf41c66_0004219a\n"
        "movzbl -0x39(%ebp), %eax\n" /* bNotify */
        "movb %al, -0x19(%ebp)\n"
        "movl $0, -0x38(%ebp)\n" /* i */
        ".Lf41c66_000420c0:\n"
        "movl -0x30(%ebp), %edx\n" /* line 1677 | anim, animIndex */
        "movzwl 6(%edx), %eax\n"
        "movl -0x38(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        /* { scope 10: anim */
        /* { scope 11 */
        "movzwl 8(%edi, %edx, 2), %eax\n" /* line 1637 | tree */
        "testw %ax, %ax\n" /* line 1638 */
        "je .Lf41c66_0004218a\n"
        "movzwl %ax, %eax\n" /* line 1642 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %esi\n" /* info */
        "leal 0xc(%esi), %ebx\n" /* line 1643 | info, state */
        "pxor %xmm0, %xmm0\n" /* line 1645 */
        "ucomiss 0x14(%ebx), %xmm0\n" /* state */
        "jp .Lf41c66_000420fa\n"
        "je .Lf41c66_0004218a\n"
        ".Lf41c66_000420fa:\n"
        "movb $0, -0x29(%ebp)\n" /* line 1648 | bNotify */
        "ucomiss 0x10(%ebx), %xmm0\n" /* state */
        "movl $0, %eax\n"
        "movzbl -0x19(%ebp), %ecx\n"
        "cmovnel %ecx, %eax\n"
        "cmovpl %ecx, %eax\n"
        "movb %al, -0x29(%ebp)\n" /* bNotify */
        "movl (%edi), %eax\n" /* line 1651 | tree */
        "leal 0xc(%eax, %edx, 8), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* anim */
        "movl 8(%ebp), %eax\n" /* line 1653 | syncState */
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%ebx), %xmm0\n" /* state */
        "jne .Lf41c66_00042139\n"
        "jp .Lf41c66_00042139\n"
        "movl %eax, %edx\n" /* animIndex */
        "movzwl 0xa(%ebx), %eax\n" /* state */
        "cmpw 0xa(%edx), %ax\n" /* animIndex */
        "je .Lf41c66_00042157\n"
        ".Lf41c66_00042139:\n"
        "movss %xmm0, (%ebx)\n" /* line 1655 | state */
        "movl 8(%ebp), %ecx\n" /* line 1656 | syncState */
        "movzwl 0xa(%ecx), %eax\n"
        "movw %ax, 8(%ebx)\n" /* state */
        "movss %xmm0, 4(%ebx)\n" /* line 1657 | state */
        "movw %ax, 0xa(%ebx)\n" /* line 1658 | state */
        "movw $0xffff, 2(%esi)\n" /* line 1660 | info */
        ".Lf41c66_00042157:\n"
        "cmpb $0, -0x29(%ebp)\n" /* line 1663 | bNotify */
        "jne .Lf41c66_0004222d\n"
        ".Lf41c66_00042161:\n"
        "movl 8(%ebp), %edx\n" /* line 1666 | syncState, animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%edx), %eax\n" /* line 1667 | animIndex */
        "movw %ax, 8(%ebx)\n" /* state */
        "movw $0xffff, 2(%esi)\n" /* line 1669 | info */
        "cmpb $0, -0x29(%ebp)\n" /* line 1671 | bNotify */
        "jne .Lf41c66_00042219\n"
        ".Lf41c66_00042180:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 1674 | anim */
        "movzwl (%ecx), %esi\n" /* info */
        "testl %esi, %esi\n" /* line 1676 | info */
        "jg .Lf41c66_000421e5\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_0004218a:\n"
        "addl $1, -0x38(%ebp)\n" /* i */
        "movl -0x38(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x34(%ebp)\n" /* animIndex, numAnims */
        "jne .Lf41c66_000420c0\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_0004219a:\n"
        "addl $1, -0x48(%ebp)\n" /* i */
        "movl -0x48(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x44(%ebp)\n" /* numAnims */
        "jne .Lf41c66_00041fe3\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_000421aa:\n"
        "addl $1, -0x58(%ebp)\n" /* i */
        "movl -0x58(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x54(%ebp)\n" /* numAnims */
        "jne .Lf41c66_00041f06\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_000421ba:\n"
        "addl $1, -0x68(%ebp)\n" /* i */
        "movl -0x68(%ebp), %edx\n" /* i, animIndex */
        "cmpl %edx, -0x64(%ebp)\n" /* animIndex, numAnims */
        "jne .Lf41c66_00041e29\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_000421ca:\n"
        "addl $1, -0x7c(%ebp)\n" /* i */
        "movl -0x7c(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x78(%ebp)\n" /* numAnims */
        "jne .Lf41c66_00041d4c\n"
        /* } scope */
        ".Lf41c66_000421da:\n"
        "addl $0x8c, %esp\n" /* line 1678 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bNotify */
        /* { scope 2: i, numAnims, anim */
        /* { scope 3: bNotify */
        /* { scope 4: i, numAnims, anim */
        /* { scope 5: bNotify */
        /* { scope 6: i, numAnims, anim */
        /* { scope 7: bNotify */
        /* { scope 8: i, numAnims, anim */
        /* { scope 9: bNotify */
        /* { scope 10: anim */
        /* { scope 11 */
        ".Lf41c66_000421e5:\n"
        "movzbl -0x29(%ebp), %eax\n" /* line 1676 | bNotify */
        "movl %eax, -0x24(%ebp)\n"
        "xorl %ebx, %ebx\n" /* state */
        ".Lf41c66_000421ee:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 1677 | anim */
        "movzwl 6(%ecx), %edx\n" /* animIndex */
        "leal (%ebx, %edx), %edx\n" /* state, animIndex */
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x80(%ebp), %xmm0\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %edi, %eax\n" /* tree */
        "calll XAnimUpdateInfoSyncInternal\n"
        "addl $1, %ebx\n" /* line 1676 | state */
        "cmpl %ebx, %esi\n" /* state, info */
        "jne .Lf41c66_000421ee\n"
        "jmp .Lf41c66_0004218a\n"
        ".Lf41c66_00042219:\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 1672 */
        "movl -0x28(%ebp), %edx\n" /* anim, animIndex */
        "movl %esi, %eax\n" /* info */
        "calll XAnimProcessClientNotify\n"
        "jmp .Lf41c66_00042180\n"
        ".Lf41c66_0004222d:\n"
        "movl 8(%ebp), %eax\n" /* line 1664 | syncState */
        "movss (%eax), %xmm0\n"
        "movl -0x28(%ebp), %ecx\n" /* anim */
        "movl %esi, %edx\n" /* info, animIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimProcessServerNotify\n"
        "jmp .Lf41c66_00042161\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_00042245:\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 1672 */
        "movl -0x30(%ebp), %edx\n" /* anim, animIndex */
        "movl %esi, %eax\n" /* info */
        "calll XAnimProcessClientNotify\n"
        "jmp .Lf41c66_000420a1\n"
        ".Lf41c66_00042259:\n"
        "movl 8(%ebp), %eax\n" /* line 1664 | syncState */
        "movss (%eax), %xmm0\n"
        "movl -0x30(%ebp), %ecx\n" /* anim */
        "movl %esi, %edx\n" /* info, animIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimProcessServerNotify\n"
        "jmp .Lf41c66_00042082\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_00042271:\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 1672 */
        "movl -0x40(%ebp), %edx\n" /* anim, animIndex */
        "movl %esi, %eax\n" /* info */
        "calll XAnimProcessClientNotify\n"
        "jmp .Lf41c66_00041fc4\n"
        ".Lf41c66_00042285:\n"
        "movl 8(%ebp), %eax\n" /* line 1664 | syncState */
        "movss (%eax), %xmm0\n"
        "movl -0x40(%ebp), %ecx\n" /* anim */
        "movl %esi, %edx\n" /* info, animIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimProcessServerNotify\n"
        "jmp .Lf41c66_00041fa5\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_0004229d:\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 1672 */
        "movl -0x50(%ebp), %edx\n" /* anim, animIndex */
        "movl %esi, %eax\n" /* info */
        "calll XAnimProcessClientNotify\n"
        "jmp .Lf41c66_00041ee7\n"
        ".Lf41c66_000422b1:\n"
        "movl 8(%ebp), %eax\n" /* line 1664 | syncState */
        "movss (%eax), %xmm0\n"
        "movl -0x50(%ebp), %ecx\n" /* anim */
        "movl %esi, %edx\n" /* info, animIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimProcessServerNotify\n"
        "jmp .Lf41c66_00041ec8\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_000422c9:\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movss (%eax), %xmm0\n"
        "movl -0x60(%ebp), %ecx\n" /* anim */
        "movl %esi, %edx\n" /* info, animIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimProcessServerNotify\n"
        "movl 8(%ebp), %edx\n" /* line 1666 | syncState, animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%edx), %eax\n" /* line 1667 | animIndex */
        "movw %ax, 8(%ebx)\n" /* state */
        "movw $0xffff, 2(%esi)\n" /* line 1669 | info */
        "cmpb $0, -0x69(%ebp)\n" /* line 1671 | bNotify */
        "je .Lf41c66_00041e0a\n"
        ".Lf41c66_000422fb:\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 1672 */
        "movl -0x60(%ebp), %edx\n" /* anim, animIndex */
        "movl %esi, %eax\n" /* info */
        "calll XAnimProcessClientNotify\n"
        "jmp .Lf41c66_00041e0a\n"
        /* } scope */
        /* } scope */
        ".Lf41c66_0004230f:\n"
        "movl 8(%ebp), %ecx\n" /* line 1664 | syncState */
        "movss (%ecx), %xmm0\n"
        "movl -0x70(%ebp), %ecx\n" /* anim */
        "movl -0x74(%ebp), %edx\n" /* info, animIndex */
        "movl %edi, %eax\n" /* tree */
        "calll XAnimProcessServerNotify\n"
        "movl 8(%ebp), %edx\n" /* line 1666 | syncState, animIndex */
        "movl (%edx), %eax\n" /* animIndex */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%edx), %eax\n" /* line 1667 | animIndex */
        "movw %ax, 8(%ebx)\n" /* state */
        "movl -0x74(%ebp), %ecx\n" /* line 1669 | info */
        "movw $0xffff, 2(%ecx)\n"
        "movl %esi, %eax\n" /* line 1671 | info */
        "testb %al, %al\n"
        "je .Lf41c66_00041d2f\n"
        ".Lf41c66_00042345:\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 1672 */
        "movl -0x70(%ebp), %edx\n" /* anim, animIndex */
        "movl %ecx, %eax\n"
        "calll XAnimProcessClientNotify\n"
        "jmp .Lf41c66_00041d2f\n"
    );
}

/* line 1681 */
static __attribute__((naked))
void XAnimUpdateInfoInternal(const XAnimTree *tree, float dtime)
{
    __asm__ __volatile__ (
        ".Lf4235a_0004235a:\n"
        "pushl %ebp\n" /* line 1681 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movl %ecx, %edi\n" /* bNotify */
        /* { scope 1: info, totalDtime, bNotify */
        "movl %eax, %ebx\n" /* line 1697 | state */
        "movzwl 8(%eax, %edx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 1698 */
        "je .Lf4235a_00042448\n"
        "movzwl %ax, %eax\n" /* line 1702 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* info */
        "movl %eax, %esi\n" /* line 1703 | state */
        "addl $0xc, %esi\n" /* state */
        "pxor %xmm2, %xmm2\n" /* line 1705 */
        "ucomiss 0x14(%esi), %xmm2\n" /* state */
        "jp .Lf4235a_000423a5\n"
        "je .Lf4235a_00042448\n"
        ".Lf4235a_000423a5:\n"
        "ucomiss 0x10(%esi), %xmm2\n" /* line 1708 | state */
        "movl $0, %eax\n"
        "cmovel %eax, %edi\n" /* bNotify */
        "cmovpl %ecx, %edi\n" /* bNotify */
        "movl (%ebx), %eax\n" /* line 1711 | state */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* anim */
        "movzwl 0xc(%eax), %eax\n" /* line 1712 */
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x44(%ebp)\n" /* numAnims */
        "testw %ax, %ax\n" /* line 1714 */
        "jne .Lf4235a_00042453\n"
        "movl 4(%edx), %eax\n" /* line 1716 */
        "movss 0x18(%esi), %xmm3\n" /* line 1721 | state */
        "mulss 8(%eax), %xmm3\n"
        "mulss %xmm0, %xmm3\n"
        "ucomiss %xmm2, %xmm3\n" /* line 1722 */
        "jp .Lf4235a_000423ea\n"
        "je .Lf4235a_00042448\n"
        ".Lf4235a_000423ea:\n"
        "movaps %xmm3, %xmm2\n" /* line 1725 */
        "addss 4(%esi), %xmm2\n" /* state */
        "movzwl 8(%esi), %ebx\n" /* line 1726 | state */
        "movss lit4_002ed5d0, %xmm0\n" /* line 1730 | 1.0f */
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf4235a_00042410\n"
        "cmpb $0, 2(%eax)\n" /* line 1732 */
        "jne .Lf4235a_00042543\n"
        "movaps %xmm0, %xmm2\n"
        ".Lf4235a_00042410:\n"
        "xorl %ecx, %ecx\n"
        ".Lf4235a_00042412:\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 1751 */
        "movss (%esi), %xmm0\n" /* state */
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf4235a_00042448\n"
        "movl %edi, %eax\n" /* line 1754 | bNotify */
        "testb %al, %al\n"
        "jne .Lf4235a_0004279f\n"
        ".Lf4235a_0004242d:\n"
        "movss %xmm2, (%esi)\n" /* line 1757 | state */
        "movw %bx, 8(%esi)\n" /* line 1758 | state */
        "movl -0x40(%ebp), %edx\n" /* line 1760 | info */
        "movw $0xffff, 2(%edx)\n"
        "movl %edi, %ecx\n" /* line 1762 | bNotify */
        "testb %cl, %cl\n"
        "jne .Lf4235a_00042725\n"
        /* } scope */
        ".Lf4235a_00042448:\n"
        "addl $0x8c, %esp\n" /* line 1841 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: info, totalDtime, bNotify */
        ".Lf4235a_00042453:\n"
        "testb $3, 4(%edx)\n" /* line 1770 */
        "je .Lf4235a_000424f3\n"
        /* { scope 2: anim */
        "movl -0x44(%ebp), %eax\n" /* line 1342 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf4235a_0004271d\n"
        /* } scope */
        "xorl %ebx, %ebx\n" /* line 1770 | state */
        "movaps %xmm2, %xmm3\n"
        "movss %xmm2, -0x34(%ebp)\n" /* totalDtime */
        "jmp .Lf4235a_00042480\n"
        /* { scope 2: anim */
        ".Lf4235a_00042474:\n"
        "addl $1, %ebx\n" /* line 1342 | i */
        "cmpl %ebx, -0x44(%ebp)\n" /* i, numAnims */
        "je .Lf4235a_00042560\n"
        ".Lf4235a_00042480:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 1345 | anim */
        "movzwl 6(%edx), %eax\n"
        "leal (%ebx, %eax), %edx\n" /* i */
        "movl -0x4c(%ebp), %ecx\n"
        "movzwl 8(%ecx, %edx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf4235a_00042474\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm1\n" /* line 1351 */
        "ucomiss %xmm2, %xmm1\n" /* line 1353 */
        "jp .Lf4235a_000424b3\n"
        "je .Lf4235a_00042474\n"
        ".Lf4235a_000424b3:\n"
        "movl %ecx, %eax\n" /* line 1356 */
        "movss %xmm1, -0x68(%ebp)\n"
        "movss %xmm2, -0x78(%ebp)\n"
        "movss %xmm3, -0x88(%ebp)\n"
        "calll XAnimGetAverageRateFrequency\n"
        "movss -0x68(%ebp), %xmm1\n" /* line 1357 */
        "movss -0x78(%ebp), %xmm2\n"
        "movss -0x88(%ebp), %xmm3\n"
        "ucomiss %xmm2, %xmm0\n"
        "jp .Lf4235a_0004273d\n"
        "jne .Lf4235a_0004273d\n"
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf4235a_00042474\n"
        /* } scope */
        ".Lf4235a_000424f3:\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 1835 */
        "mulss 0x18(%esi), %xmm0\n" /* state */
        "movss %xmm0, -0x20(%ebp)\n"
        "ucomiss %xmm2, %xmm0\n" /* line 1836 */
        "je .Lf4235a_00042794\n"
        ".Lf4235a_0004250b:\n"
        "movl -0x44(%ebp), %eax\n" /* line 1839 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf4235a_00042448\n"
        "movl %edi, %edx\n" /* bNotify */
        "movzbl %dl, %esi\n" /* state */
        "xorl %ebx, %ebx\n" /* state */
        ".Lf4235a_0004251d:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1840 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* state */
        "movl %esi, %ecx\n" /* state */
        "movss -0x20(%ebp), %xmm0\n"
        "movl -0x4c(%ebp), %eax\n"
        "calll XAnimUpdateInfoInternal\n"
        "addl $1, %ebx\n" /* line 1839 | state */
        "cmpl %ebx, -0x44(%ebp)\n" /* state, numAnims */
        "jne .Lf4235a_0004251d\n"
        "jmp .Lf4235a_00042448\n"
        ".Lf4235a_00042543:\n"
        "movl %ebx, %edx\n" /* line 1732 | state */
        ".Lf4235a_00042545:\n"
        "subss %xmm0, %xmm2\n" /* line 1740 */
        "addl $1, %edx\n" /* line 1741 */
        "ucomiss %xmm0, %xmm2\n" /* line 1738 */
        "jae .Lf4235a_00042545\n"
        "movswl %dx, %ecx\n"
        "movswl %bx, %eax\n" /* state */
        "subl %eax, %ecx\n"
        "movl %edx, %ebx\n" /* state */
        "jmp .Lf4235a_00042412\n"
        /* { scope 2: anim */
        ".Lf4235a_00042560:\n"
        "ucomiss %xmm2, %xmm3\n" /* line 1364 */
        "jp .Lf4235a_0004256b\n"
        "je .Lf4235a_0004271d\n"
        ".Lf4235a_0004256b:\n"
        "movss -0x34(%ebp), %xmm0\n" /* totalDtime */
        "divss %xmm3, %xmm0\n"
        /* } scope */
        ".Lf4235a_00042574:\n"
        "mulss 0x18(%esi), %xmm0\n" /* line 1774 | state */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0x50(%ebp), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "ucomiss %xmm2, %xmm0\n" /* line 1775 */
        "jp .Lf4235a_00042598\n"
        "je .Lf4235a_00042448\n"
        ".Lf4235a_00042598:\n"
        "movaps %xmm0, %xmm2\n" /* line 1781 */
        "addss 4(%esi), %xmm2\n" /* state */
        "movzwl 0xa(%esi), %ebx\n" /* line 1782 | state */
        "movss lit4_002ed5d0, %xmm1\n" /* line 1786 | 1.0f */
        "movaps %xmm1, %xmm0\n"
        "ucomiss %xmm1, %xmm2\n"
        "jb .Lf4235a_000425c4\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1788 | anim */
        "testb $2, 4(%eax)\n"
        "je .Lf4235a_000426fc\n"
        "movaps %xmm1, %xmm2\n" /* line 1796 */
        ".Lf4235a_000425c4:\n"
        "movswl %bx, %eax\n" /* line 1809 | state */
        "movswl 8(%esi), %edx\n" /* state */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss (%esi), %xmm0\n" /* state */
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf4235a_00042448\n"
        "movl %edi, %edx\n" /* line 1812 | bNotify */
        "testb %dl, %dl\n"
        "jne .Lf4235a_00042760\n"
        ".Lf4235a_000425ec:\n"
        "movss %xmm2, (%esi)\n" /* line 1815 | state */
        "movw %bx, 8(%esi)\n" /* line 1816 | state */
        "movl -0x40(%ebp), %ecx\n" /* line 1818 | info */
        "movw $0xffff, 2(%ecx)\n"
        "movl %edi, %ebx\n" /* line 1820 | bNotify, state */
        "testb %bl, %bl\n" /* state */
        "jne .Lf4235a_00042780\n"
        ".Lf4235a_00042607:\n"
        "movl -0x44(%ebp), %eax\n" /* line 1826 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf4235a_00042448\n"
        "movl %edi, %edx\n" /* bNotify */
        "movb %dl, -0x21(%ebp)\n"
        "movl $0, -0x48(%ebp)\n" /* i */
        ".Lf4235a_0004261e:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 1827 | anim */
        "movzwl 6(%ecx), %eax\n"
        "movl -0x48(%ebp), %edx\n" /* i, animIndex */
        "addl %eax, %edx\n" /* animIndex */
        /* { scope 2: anim */
        /* { scope 3 */
        "movl -0x4c(%ebp), %ebx\n" /* line 1637 | state */
        "movzwl 8(%ebx, %edx, 2), %eax\n" /* state */
        "testw %ax, %ax\n" /* line 1638 */
        "je .Lf4235a_000426e7\n"
        "movzwl %ax, %eax\n" /* line 1642 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edi\n" /* info */
        "leal 0xc(%edi), %ebx\n" /* line 1643 | info, state */
        "pxor %xmm0, %xmm0\n" /* line 1645 */
        "ucomiss 0x14(%ebx), %xmm0\n" /* state */
        "jp .Lf4235a_0004265b\n"
        "je .Lf4235a_000426e7\n"
        ".Lf4235a_0004265b:\n"
        "movb $0, -0x2d(%ebp)\n" /* line 1648 | bNotify */
        "ucomiss 0x10(%ebx), %xmm0\n" /* state */
        "movl $0, %eax\n"
        "movzbl -0x21(%ebp), %ecx\n"
        "cmovnel %ecx, %eax\n"
        "cmovpl %ecx, %eax\n"
        "movb %al, -0x2d(%ebp)\n" /* bNotify */
        "movl -0x4c(%ebp), %ecx\n" /* line 1651 */
        "movl (%ecx), %eax\n"
        "leal 0xc(%eax, %edx, 8), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* anim */
        "movss 4(%esi), %xmm0\n" /* line 1653 */
        "ucomiss 4(%ebx), %xmm0\n" /* state */
        "jne .Lf4235a_00042698\n"
        "jp .Lf4235a_00042698\n"
        "movzwl 0xa(%ebx), %eax\n" /* state */
        "cmpw 0xa(%esi), %ax\n"
        "je .Lf4235a_000426b3\n"
        ".Lf4235a_00042698:\n"
        "movss %xmm0, (%ebx)\n" /* line 1655 | state */
        "movzwl 0xa(%esi), %eax\n" /* line 1656 */
        "movw %ax, 8(%ebx)\n" /* state */
        "movss %xmm0, 4(%ebx)\n" /* line 1657 | state */
        "movw %ax, 0xa(%ebx)\n" /* line 1658 | state */
        "movw $0xffff, 2(%edi)\n" /* line 1660 | info */
        ".Lf4235a_000426b3:\n"
        "cmpb $0, -0x2d(%ebp)\n" /* line 1663 | bNotify */
        "jne .Lf4235a_000427cf\n"
        ".Lf4235a_000426bd:\n"
        "movl (%esi), %eax\n" /* line 1666 */
        "movl %eax, (%ebx)\n" /* state */
        "movzwl 8(%esi), %eax\n" /* line 1667 */
        "movw %ax, 8(%ebx)\n" /* state */
        "movw $0xffff, 2(%edi)\n" /* line 1669 | info */
        "cmpb $0, -0x2d(%ebp)\n" /* line 1671 | bNotify */
        "jne .Lf4235a_00042817\n"
        ".Lf4235a_000426d9:\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 1674 | anim, state */
        "movzwl (%ebx), %edi\n" /* state, info */
        "testl %edi, %edi\n" /* line 1676 | info */
        "jg .Lf4235a_000427e5\n"
        /* } scope */
        /* } scope */
        ".Lf4235a_000426e7:\n"
        "addl $1, -0x48(%ebp)\n" /* line 1826 | i */
        "movl -0x48(%ebp), %ebx\n" /* i, state */
        "cmpl %ebx, -0x44(%ebp)\n" /* state, numAnims */
        "jne .Lf4235a_0004261e\n"
        "jmp .Lf4235a_00042448\n"
        ".Lf4235a_000426fc:\n"
        "subss %xmm0, %xmm2\n" /* line 1798 */
        "addl $1, %ebx\n" /* line 1799 | state */
        "ucomiss %xmm0, %xmm2\n" /* line 1796 */
        "jb .Lf4235a_000425c4\n"
        "subss %xmm0, %xmm2\n" /* line 1798 */
        "addl $1, %ebx\n" /* line 1799 | state */
        "ucomiss %xmm0, %xmm2\n" /* line 1796 */
        "jae .Lf4235a_000426fc\n"
        "jmp .Lf4235a_000425c4\n"
        /* { scope 2: anim */
        ".Lf4235a_0004271d:\n"
        "movaps %xmm2, %xmm0\n" /* line 1364 */
        "jmp .Lf4235a_00042574\n"
        /* } scope */
        ".Lf4235a_00042725:\n"
        "movaps %xmm3, %xmm0\n" /* line 1763 */
        "movl -0x3c(%ebp), %edx\n" /* anim */
        "movl -0x40(%ebp), %eax\n" /* info */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1841 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: info, totalDtime, bNotify */
        "jmp XAnimProcessClientNotify\n" /* line 1763 */
        /* { scope 2: anim */
        ".Lf4235a_0004273d:\n"
        "addss %xmm1, %xmm3\n" /* line 1360 */
        "mulss %xmm0, %xmm1\n" /* line 1361 */
        "movl -0x38(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm1\n"
        "addss -0x34(%ebp), %xmm1\n" /* totalDtime */
        "movss %xmm1, -0x34(%ebp)\n" /* totalDtime */
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf4235a_00042474\n"
        /* } scope */
        ".Lf4235a_00042760:\n"
        "movaps %xmm2, %xmm0\n" /* line 1813 */
        "movl -0x3c(%ebp), %ecx\n" /* anim */
        "movl -0x40(%ebp), %edx\n" /* info */
        "movl -0x4c(%ebp), %eax\n"
        "movss %xmm2, -0x78(%ebp)\n"
        "calll XAnimProcessServerNotify\n"
        "movss -0x78(%ebp), %xmm2\n"
        "jmp .Lf4235a_000425ec\n"
        ".Lf4235a_00042780:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1821 */
        "movl -0x3c(%ebp), %edx\n" /* anim */
        "movl %ecx, %eax\n"
        "calll XAnimProcessClientNotify\n"
        "jmp .Lf4235a_00042607\n"
        ".Lf4235a_00042794:\n"
        "jnp .Lf4235a_00042448\n" /* line 1836 */
        "jmp .Lf4235a_0004250b\n"
        ".Lf4235a_0004279f:\n"
        "movaps %xmm2, %xmm0\n" /* line 1755 */
        "movl -0x3c(%ebp), %ecx\n" /* anim */
        "movl -0x40(%ebp), %edx\n" /* info */
        "movl -0x4c(%ebp), %eax\n"
        "movss %xmm2, -0x78(%ebp)\n"
        "movss %xmm3, -0x88(%ebp)\n"
        "calll XAnimProcessServerNotify\n"
        "movss -0x88(%ebp), %xmm3\n"
        "movss -0x78(%ebp), %xmm2\n"
        "jmp .Lf4235a_0004242d\n"
        /* { scope 2: anim */
        /* { scope 3 */
        ".Lf4235a_000427cf:\n"
        "movss (%esi), %xmm0\n" /* line 1664 */
        "movl -0x2c(%ebp), %ecx\n" /* anim */
        "movl %edi, %edx\n" /* info */
        "movl -0x4c(%ebp), %eax\n"
        "calll XAnimProcessServerNotify\n"
        "jmp .Lf4235a_000426bd\n"
        ".Lf4235a_000427e5:\n"
        "movzbl -0x2d(%ebp), %eax\n" /* line 1676 | bNotify */
        "movl %eax, -0x28(%ebp)\n"
        "xorl %ebx, %ebx\n" /* state */
        ".Lf4235a_000427ee:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 1677 | anim */
        "movzwl 6(%ecx), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* state */
        "movl %esi, (%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movl -0x28(%ebp), %ecx\n"
        "movl -0x4c(%ebp), %eax\n"
        "calll XAnimUpdateInfoSyncInternal\n"
        "addl $1, %ebx\n" /* line 1676 | state */
        "cmpl %ebx, %edi\n" /* state, info */
        "jne .Lf4235a_000427ee\n"
        "jmp .Lf4235a_000426e7\n"
        ".Lf4235a_00042817:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1672 */
        "movl -0x2c(%ebp), %edx\n" /* anim */
        "movl %edi, %eax\n" /* info */
        "calll XAnimProcessClientNotify\n"
        "jmp .Lf4235a_000426d9\n"
    );
}

/* line 3111 */
__attribute__((naked))
void DObjUpdateClientInfo(DObj *obj, float dtime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3111 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* obj */
        /* { scope 1 */
        "movl $0, g_notifyListSize\n" /* line 3123 */
        "movl (%ebx), %eax\n" /* line 3125 | obj */
        "testl %eax, %eax\n"
        "je .Lf4282c_0004288c\n"
        "movl $0, -0x28(%ebp)\n" /* line 3131 | syncState */
        "movw $0, -0x20(%ebp)\n" /* line 3132 */
        "leal -0x28(%ebp), %ecx\n" /* line 3134 | syncState */
        "leal -0xa(%ebp), %eax\n" /* childHadWeight */
        "movl %eax, 8(%esp)\n"
        "leal -9(%ebp), %eax\n" /* infoExists */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* dtime */
        "xorl %edx, %edx\n"
        "movl (%ebx), %eax\n" /* obj */
        "calll XAnimUpdateOldTime\n"
        "movl $1, %ecx\n" /* line 3135 */
        "movss 0xc(%ebp), %xmm0\n" /* dtime */
        "xorl %edx, %edx\n"
        "movl (%ebx), %eax\n" /* obj */
        "calll XAnimUpdateInfoInternal\n"
        /* } scope */
        ".Lf4282c_0004288c:\n"
        "addl $0x34, %esp\n" /* line 3138 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1450 */
static __attribute__((naked))
float XAnimGetNotifyFracServer(const XAnimState *syncState, const XAnimState *nextSyncState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1450 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl %eax, %ebx\n" /* tree */
        "movl %edx, %esi\n" /* info */
        "movaps %xmm0, %xmm5\n" /* dtime */
        /* { scope 1: bestNotifyInfo */
        "cmpw $0, 4(%eax)\n" /* line 1457 */
        "je .Lf42892_00042912\n"
        "cmpw $0, 4(%edx)\n"
        "je .Lf42892_00042912\n"
        "cmpw $0, (%ecx)\n" /* line 1460 | anim */
        "je .Lf42892_0004292b\n"
        "movzwl (%edx), %eax\n" /* line 1462 */
        "testw %ax, %ax\n"
        "jne .Lf42892_00042922\n"
        "movl 0xc(%ebp), %eax\n" /* line 1422 | nextSyncState */
        "movss 4(%eax), %xmm2\n"
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
        "ucomiss %xmm4, %xmm2\n"
        "jp .Lf42892_000428d9\n"
        ".Lf42892_000428d3:\n"
        "je .Lf42892_000429ae\n"
        ".Lf42892_000428d9:\n"
        "movss (%eax), %xmm1\n" /* line 1425 */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf42892_00042999\n"
        "ucomiss %xmm4, %xmm1\n" /* line 1427 */
        "jbe .Lf42892_000429a5\n"
        "movswl 0xa(%eax), %eax\n" /* line 1428 */
        "movl 8(%ebp), %ecx\n" /* syncState */
        "movswl 0xa(%ecx), %edx\n"
        "subl %edx, %eax\n"
        "addl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "subss 4(%ecx), %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "divss %xmm5, %xmm0\n"
        "jmp .Lf42892_0004291a\n"
        /* { scope 2 */
        ".Lf42892_00042912:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1437 | 1.0f */
        /* } scope */
        /* } scope */
        ".Lf42892_0004291a:\n"
        "addl $4, %esp\n" /* line 1479 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bestNotifyInfo */
        ".Lf42892_00042922:\n"
        "movzwl %ax, %edx\n" /* line 1464 */
        "movl (%ebx), %eax\n" /* tree */
        "leal 0xc(%eax, %edx, 8), %ecx\n" /* anim */
        ".Lf42892_0004292b:\n"
        "movl 4(%ecx), %edi\n" /* line 1469 | anim, parts */
        "movl %edi, %eax\n" /* parts */
        "cmpw $0, 2(%esi)\n" /* line 1472 | info */
        "js .Lf42892_000429ca\n"
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
        ".Lf42892_00042943:\n"
        "movswl 2(%esi), %edx\n" /* line 1478 | info */
        "movl 0x1c(%edi), %eax\n" /* parts */
        "movss 4(%eax, %edx, 8), %xmm3\n" /* time */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 1422 | nextSyncState */
        "movss 4(%eax), %xmm2\n"
        "ucomiss %xmm4, %xmm2\n"
        "jp .Lf42892_0004295f\n"
        "je .Lf42892_000429ae\n"
        ".Lf42892_0004295f:\n"
        "movss (%eax), %xmm1\n" /* line 1425 */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf42892_000429b9\n"
        "ucomiss %xmm3, %xmm1\n" /* line 1427 */
        "ja .Lf42892_00042a2d\n"
        ".Lf42892_00042971:\n"
        "ucomiss %xmm2, %xmm3\n" /* line 1436 */
        "jb .Lf42892_000429ae\n"
        "movl 0xc(%ebp), %edx\n" /* line 1437 | nextSyncState */
        "movswl 0xa(%edx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* syncState */
        "movswl 0xa(%ecx), %edx\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "subss 4(%ecx), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "divss %xmm5, %xmm0\n"
        "jmp .Lf42892_0004291a\n"
        /* } scope */
        ".Lf42892_00042999:\n"
        "ucomiss %xmm4, %xmm1\n" /* line 1436 */
        "ja .Lf42892_000429a5\n"
        "ucomiss %xmm4, %xmm1\n"
        "jne .Lf42892_000429ae\n"
        "jp .Lf42892_000429ae\n"
        ".Lf42892_000429a5:\n"
        "ucomiss %xmm2, %xmm4\n"
        "jae .Lf42892_00042a53\n"
        /* { scope 2 */
        ".Lf42892_000429ae:\n"
        "movaps %xmm4, %xmm0\n" /* line 1437 */
        /* } scope */
        /* } scope */
        ".Lf42892_000429b1:\n"
        "addl $4, %esp\n" /* line 1479 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bestNotifyInfo */
        /* { scope 2 */
        ".Lf42892_000429b9:\n"
        "ucomiss %xmm3, %xmm1\n" /* line 1436 */
        "ja .Lf42892_00042971\n"
        "ucomiss %xmm4, %xmm1\n"
        "jne .Lf42892_000429ae\n"
        "jnp .Lf42892_00042971\n"
        "movaps %xmm4, %xmm0\n" /* line 1437 */
        "jmp .Lf42892_000429b1\n"
        /* } scope */
        ".Lf42892_000429ca:\n"
        "movss 0xc(%esi), %xmm0\n" /* line 4176 | info */
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf42892_000429de\n"
        "je .Lf42892_00042a17\n"
        ".Lf42892_000429de:\n"
        "cmpw $0, (%ecx)\n" /* line 4179 | anim */
        "je .Lf42892_000429f5\n"
        "movzwl (%esi), %eax\n" /* line 4181 | info */
        "testw %ax, %ax\n"
        "je .Lf42892_00042a17\n"
        "movzwl %ax, %edx\n" /* line 4183 */
        "movl (%ebx), %eax\n" /* tree */
        "movl 0x10(%eax, %edx, 8), %eax\n"
        /* { scope 2 */
        ".Lf42892_000429f5:\n"
        "movl 0x1c(%eax), %edx\n" /* line 1389 */
        "movzbl 0xc(%eax), %eax\n" /* line 1391 */
        "testl %eax, %eax\n"
        "jg .Lf42892_00042a79\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf42892_00042a02:\n"
        "subl %edx, %eax\n" /* line 4188 */
        "sarl $3, %eax\n"
        "movzwl %ax, %eax\n"
        "movw %ax, 2(%esi)\n" /* info */
        "testw %ax, %ax\n" /* line 1475 */
        "jns .Lf42892_00042943\n"
        ".Lf42892_00042a17:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1422 | nextSyncState */
        "movss 4(%eax), %xmm2\n"
        "ucomiss %xmm4, %xmm2\n"
        "jnp .Lf42892_000428d3\n"
        "jmp .Lf42892_000428d9\n"
        /* { scope 2 */
        ".Lf42892_00042a2d:\n"
        "movswl 0xa(%eax), %eax\n" /* line 1428 */
        "movl 8(%ebp), %ecx\n" /* syncState */
        "movswl 0xa(%ecx), %edx\n"
        "subl %edx, %eax\n"
        "addl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "subss 4(%ecx), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "divss %xmm5, %xmm0\n"
        "jmp .Lf42892_0004291a\n"
        /* } scope */
        ".Lf42892_00042a53:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1437 | nextSyncState */
        "movswl 0xa(%edx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* syncState */
        "movswl 0xa(%ecx), %edx\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "subss 4(%ecx), %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "divss %xmm5, %xmm0\n"
        "jmp .Lf42892_0004291a\n"
        /* { scope 2 */
        ".Lf42892_00042a79:\n"
        "movl %edx, %ecx\n" /* line 1391 */
        "movl $0, -0x10(%ebp)\n" /* bestNotifyInfo */
        "movss lit4_002ed62c, %xmm2\n" /* 2.0f */
        "xorl %ebx, %ebx\n" /* notifyInfoIndex */
        ".Lf42892_00042a8c:\n"
        "movss 4(%ecx), %xmm1\n" /* line 1393 */
        "ucomiss %xmm1, %xmm0\n" /* line 1395 */
        "ja .Lf42892_00042aa1\n"
        "ucomiss %xmm1, %xmm2\n" /* line 1397 */
        "jbe .Lf42892_00042aa1\n"
        "movl %ecx, -0x10(%ebp)\n" /* bestNotifyInfo */
        "movaps %xmm1, %xmm2\n"
        ".Lf42892_00042aa1:\n"
        "addl $1, %ebx\n" /* line 1391 | notifyInfoIndex */
        "addl $8, %ecx\n"
        "cmpl %ebx, %eax\n" /* notifyInfoIndex */
        "jne .Lf42892_00042a8c\n"
        "movl -0x10(%ebp), %eax\n" /* bestNotifyInfo */
        "jmp .Lf42892_00042a02\n"
    );
}

/* line 2063 */
static __attribute__((naked))
float XAnimGetServerNotifyFracSyncTotal(const XAnimEntry *anim, const XAnimState *syncState, const XAnimState *nextSyncState, float dtime)
{
    __asm__ __volatile__ (
        ".Lf42ab4_00042ab4:\n"
        "pushl %ebp\n" /* line 2063 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %esi\n" /* tree */
        "movl %ecx, -0x78(%ebp)\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        /* { scope 1: anim */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movss %xmm0, -0x74(%ebp)\n" /* minFrac */
        "movl -0x78(%ebp), %edx\n" /* line 2073 | info */
        "movzwl (%edx), %ebx\n" /* info, i */
        "testl %ebx, %ebx\n" /* i */
        "jle .Lf42ab4_00042b30\n"
        "xorl %edi, %edi\n" /* i */
        ".Lf42ab4_00042aef:\n"
        "movl -0x78(%ebp), %edx\n" /* line 2075 | info */
        "movzwl 6(%edx), %eax\n" /* info */
        "leal (%edi, %eax), %ecx\n" /* i */
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042b24\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042b1c\n"
        "je .Lf42ab4_00042b24\n"
        ".Lf42ab4_00042b1c:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042b3b\n"
        "jne .Lf42ab4_00042b3b\n"
        ".Lf42ab4_00042b24:\n"
        "addl $1, %edi\n" /* line 2073 | i */
        "cmpl %ebx, %edi\n" /* i */
        "jl .Lf42ab4_00042aef\n"
        "movss -0x74(%ebp), %xmm0\n" /* minFrac */
        /* } scope */
        ".Lf42ab4_00042b30:\n"
        "addl $0x9c, %esp\n" /* line 2095 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: anim */
        ".Lf42ab4_00042b3b:\n"
        "movl (%esi), %eax\n" /* line 2086 | tree */
        "leal (%eax, %ecx, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* i */
        "movl %eax, -0x6c(%ebp)\n" /* anim */
        /* { scope 2: i */
        /* { scope 3: anim */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl -0x6c(%ebp), %ecx\n" /* anim */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 2073 | i */
        "je .Lf42ab4_00042bbb\n"
        "movl $0, -0x68(%ebp)\n" /* i */
        "movl -0x6c(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042b78:\n"
        "movzwl 6(%edx), %eax\n" /* line 2075 | info */
        "movl -0x68(%ebp), %ecx\n" /* i */
        "addl %eax, %ecx\n"
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042baf\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042ba4\n"
        "je .Lf42ab4_00042bac\n"
        ".Lf42ab4_00042ba4:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042be6\n"
        "jne .Lf42ab4_00042be6\n"
        ".Lf42ab4_00042bac:\n"
        "movl -0x6c(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042baf:\n"
        "addl $1, -0x68(%ebp)\n" /* line 2073 | i */
        "movzwl (%edx), %eax\n" /* info */
        "cmpl -0x68(%ebp), %eax\n" /* i */
        "jg .Lf42ab4_00042b78\n"
        /* } scope */
        /* } scope */
        ".Lf42ab4_00042bbb:\n"
        "movss -0x74(%ebp), %xmm0\n" /* line 2090 | minFrac */
        "ucomiss -0x30(%ebp), %xmm0\n"
        "jbe .Lf42ab4_00042bdb\n"
        "movss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n" /* minFrac */
        "movl -0x78(%ebp), %eax\n"
        "movzwl (%eax), %ebx\n" /* i */
        "jmp .Lf42ab4_00042b24\n"
        ".Lf42ab4_00042bdb:\n"
        "movl -0x78(%ebp), %edx\n"
        "movzwl (%edx), %ebx\n" /* i */
        "jmp .Lf42ab4_00042b24\n"
        /* { scope 2: i */
        /* { scope 3: anim */
        ".Lf42ab4_00042be6:\n"
        "movl (%esi), %eax\n" /* line 2086 | tree */
        "leal (%eax, %ecx, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* i */
        "movl %eax, -0x64(%ebp)\n" /* anim */
        /* { scope 4: i */
        /* { scope 5: anim */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl -0x64(%ebp), %ecx\n" /* anim */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 2073 | i */
        "je .Lf42ab4_00042c6b\n"
        "movl $0, -0x60(%ebp)\n" /* i */
        "movl -0x64(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042c23:\n"
        "movzwl 6(%edx), %eax\n" /* line 2075 | info */
        "movl -0x60(%ebp), %ecx\n" /* i */
        "addl %eax, %ecx\n"
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042c5a\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042c4f\n"
        "je .Lf42ab4_00042c57\n"
        ".Lf42ab4_00042c4f:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042c7d\n"
        "jne .Lf42ab4_00042c7d\n"
        ".Lf42ab4_00042c57:\n"
        "movl -0x64(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042c5a:\n"
        "addl $1, -0x60(%ebp)\n" /* line 2073 | i */
        "movzwl (%edx), %eax\n" /* info */
        "cmpl %eax, -0x60(%ebp)\n" /* i */
        "jl .Lf42ab4_00042c23\n"
        "movss -0x28(%ebp), %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf42ab4_00042c6b:\n"
        "minss -0x30(%ebp), %xmm0\n" /* line 2090 */
        "movss %xmm0, -0x30(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n" /* anim */
        "jmp .Lf42ab4_00042baf\n"
        /* { scope 4: i */
        /* { scope 5: anim */
        ".Lf42ab4_00042c7d:\n"
        "movl (%esi), %eax\n" /* line 2086 | tree */
        "leal (%eax, %ecx, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* i */
        "movl %eax, -0x5c(%ebp)\n" /* anim */
        /* { scope 6: i */
        /* { scope 7: anim */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl -0x5c(%ebp), %ecx\n" /* anim */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 2073 | i */
        "je .Lf42ab4_00042d02\n"
        "movl $0, -0x58(%ebp)\n" /* i */
        "movl -0x5c(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042cba:\n"
        "movzwl 6(%edx), %eax\n" /* line 2075 | info */
        "movl -0x58(%ebp), %ecx\n" /* i */
        "addl %eax, %ecx\n"
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042cf1\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042ce6\n"
        "je .Lf42ab4_00042cee\n"
        ".Lf42ab4_00042ce6:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042d14\n"
        "jne .Lf42ab4_00042d14\n"
        ".Lf42ab4_00042cee:\n"
        "movl -0x5c(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042cf1:\n"
        "addl $1, -0x58(%ebp)\n" /* line 2073 | i */
        "movzwl (%edx), %eax\n" /* info */
        "cmpl %eax, -0x58(%ebp)\n" /* i */
        "jl .Lf42ab4_00042cba\n"
        "movss -0x24(%ebp), %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf42ab4_00042d02:\n"
        "minss -0x28(%ebp), %xmm0\n" /* line 2090 */
        "movss %xmm0, -0x28(%ebp)\n"
        "movl -0x64(%ebp), %edx\n" /* anim */
        "jmp .Lf42ab4_00042c5a\n"
        /* { scope 6: i */
        /* { scope 7: anim */
        ".Lf42ab4_00042d14:\n"
        "movl (%esi), %eax\n" /* line 2086 | tree */
        "leal (%eax, %ecx, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* i */
        "movl %eax, -0x54(%ebp)\n" /* anim */
        /* { scope 8: i */
        /* { scope 9: anim */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl -0x54(%ebp), %ecx\n" /* anim */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 2073 | i */
        "je .Lf42ab4_00042d99\n"
        "movl $0, -0x50(%ebp)\n" /* i */
        "movl -0x54(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042d51:\n"
        "movzwl 6(%edx), %eax\n" /* line 2075 | info */
        "movl -0x50(%ebp), %ecx\n" /* i */
        "addl %eax, %ecx\n"
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042d88\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042d7d\n"
        "je .Lf42ab4_00042d85\n"
        ".Lf42ab4_00042d7d:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042dab\n"
        "jne .Lf42ab4_00042dab\n"
        ".Lf42ab4_00042d85:\n"
        "movl -0x54(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042d88:\n"
        "addl $1, -0x50(%ebp)\n" /* line 2073 | i */
        "movzwl (%edx), %eax\n" /* info */
        "cmpl %eax, -0x50(%ebp)\n" /* i */
        "jl .Lf42ab4_00042d51\n"
        "movss -0x20(%ebp), %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf42ab4_00042d99:\n"
        "minss -0x24(%ebp), %xmm0\n" /* line 2090 */
        "movss %xmm0, -0x24(%ebp)\n"
        "movl -0x5c(%ebp), %edx\n" /* anim */
        "jmp .Lf42ab4_00042cf1\n"
        /* { scope 8: i */
        /* { scope 9: anim */
        ".Lf42ab4_00042dab:\n"
        "movl (%esi), %eax\n" /* line 2086 | tree */
        "leal (%eax, %ecx, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* i */
        "movl %eax, -0x4c(%ebp)\n" /* anim */
        /* { scope 10: i */
        /* { scope 11: anim */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl -0x4c(%ebp), %ecx\n" /* anim */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 2073 | i */
        "je .Lf42ab4_00042e30\n"
        "movl $0, -0x48(%ebp)\n" /* i */
        "movl -0x4c(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042de8:\n"
        "movzwl 6(%edx), %eax\n" /* line 2075 | info */
        "movl -0x48(%ebp), %ecx\n" /* i */
        "addl %eax, %ecx\n"
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042e1f\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042e14\n"
        "je .Lf42ab4_00042e1c\n"
        ".Lf42ab4_00042e14:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042e42\n"
        "jne .Lf42ab4_00042e42\n"
        ".Lf42ab4_00042e1c:\n"
        "movl -0x4c(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042e1f:\n"
        "addl $1, -0x48(%ebp)\n" /* line 2073 | i */
        "movzwl (%edx), %eax\n" /* info */
        "cmpl -0x48(%ebp), %eax\n" /* i */
        "jg .Lf42ab4_00042de8\n"
        "movss -0x2c(%ebp), %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf42ab4_00042e30:\n"
        "minss -0x20(%ebp), %xmm0\n" /* line 2090 */
        "movss %xmm0, -0x20(%ebp)\n"
        "movl -0x54(%ebp), %edx\n" /* anim */
        "jmp .Lf42ab4_00042d88\n"
        /* { scope 10: i */
        /* { scope 11: anim */
        ".Lf42ab4_00042e42:\n"
        "movl (%esi), %eax\n" /* line 2086 | tree */
        "leal (%eax, %ecx, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* i */
        "movl %eax, -0x44(%ebp)\n" /* anim */
        /* { scope 12: i */
        /* { scope 13: anim */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl -0x44(%ebp), %ecx\n" /* anim */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movss %xmm0, -0x70(%ebp)\n" /* testFrac */
        "cmpw $0, 0xc(%ebx)\n" /* line 2073 | i */
        "je .Lf42ab4_00042ec2\n"
        "movl $0, -0x40(%ebp)\n" /* i */
        "movl -0x44(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042e7f:\n"
        "movzwl 6(%edx), %eax\n" /* line 2075 | info */
        "movl -0x40(%ebp), %ecx\n" /* i */
        "addl %eax, %ecx\n"
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042eb6\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042eab\n"
        "je .Lf42ab4_00042eb3\n"
        ".Lf42ab4_00042eab:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042ed9\n"
        "jne .Lf42ab4_00042ed9\n"
        ".Lf42ab4_00042eb3:\n"
        "movl -0x44(%ebp), %edx\n" /* anim, info */
        ".Lf42ab4_00042eb6:\n"
        "addl $1, -0x40(%ebp)\n" /* line 2073 | i */
        "movzwl (%edx), %eax\n" /* info */
        "cmpl -0x40(%ebp), %eax\n" /* i */
        "jg .Lf42ab4_00042e7f\n"
        /* } scope */
        /* } scope */
        ".Lf42ab4_00042ec2:\n"
        "movss -0x70(%ebp), %xmm0\n" /* line 2090 | testFrac */
        "minss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl -0x4c(%ebp), %edx\n" /* anim */
        "jmp .Lf42ab4_00042e1f\n"
        /* { scope 12: i */
        /* { scope 13: anim */
        ".Lf42ab4_00042ed9:\n"
        "movl (%esi), %eax\n" /* line 2086 | tree */
        "leal (%eax, %ecx, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* i */
        "movl %eax, -0x3c(%ebp)\n" /* anim */
        /* { scope 14: i */
        /* { scope 15: anim */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl -0x3c(%ebp), %ecx\n" /* anim */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 2073 | i */
        "je .Lf42ab4_00042f59\n"
        "movl $0, -0x38(%ebp)\n" /* i */
        ".Lf42ab4_00042f13:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 2075 | anim, info */
        "movzwl 6(%edx), %eax\n" /* info */
        "movl -0x38(%ebp), %ecx\n" /* i */
        "addl %eax, %ecx\n"
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042f4a\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042f42\n"
        "je .Lf42ab4_00042f4a\n"
        ".Lf42ab4_00042f42:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042f70\n"
        "jne .Lf42ab4_00042f70\n"
        ".Lf42ab4_00042f4a:\n"
        "addl $1, -0x38(%ebp)\n" /* line 2073 | i */
        "movl -0x3c(%ebp), %edx\n" /* anim, info */
        "movzwl (%edx), %eax\n" /* info */
        "cmpl -0x38(%ebp), %eax\n" /* i */
        "jg .Lf42ab4_00042f13\n"
        /* } scope */
        /* } scope */
        ".Lf42ab4_00042f59:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 2090 */
        "minss -0x70(%ebp), %xmm0\n" /* testFrac */
        "movss %xmm0, -0x70(%ebp)\n" /* testFrac */
        "movl -0x44(%ebp), %edx\n" /* anim */
        "jmp .Lf42ab4_00042eb6\n"
        /* { scope 14: i */
        /* { scope 15: anim */
        ".Lf42ab4_00042f70:\n"
        "movl (%esi), %eax\n" /* line 2086 | tree */
        "leal (%eax, %ecx, 8), %ebx\n" /* i */
        "leal 0xc(%ebx), %eax\n" /* i */
        "movl %eax, -0x34(%ebp)\n" /* anim */
        /* { scope 16 */
        /* { scope 17 */
        "movl 0xc(%ebp), %eax\n" /* line 2071 | nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl -0x34(%ebp), %ecx\n" /* anim */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movaps %xmm0, %xmm1\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 2073 | i */
        "je .Lf42ab4_0004301f\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf42ab4_00042fb4\n"
        ".Lf42ab4_00042fa5:\n"
        "jne .Lf42ab4_00042fe7\n" /* line 2086 */
        ".Lf42ab4_00042fa7:\n"
        "addl $1, %ebx\n" /* line 2073 | i */
        "movl -0x34(%ebp), %edx\n" /* anim, info */
        "movzwl (%edx), %eax\n" /* info */
        "cmpl %ebx, %eax\n" /* i */
        "jle .Lf42ab4_0004301f\n"
        ".Lf42ab4_00042fb4:\n"
        "movl -0x34(%ebp), %edx\n" /* line 2075 | anim, info */
        "movzwl 6(%edx), %eax\n" /* info */
        "leal (%ebx, %eax), %ecx\n" /* i */
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 | tree */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf42ab4_00042fa7\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n" /* info */
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n" /* info */
        "jp .Lf42ab4_00042fe1\n"
        "je .Lf42ab4_00042fa7\n"
        ".Lf42ab4_00042fe1:\n"
        "ucomiss 0x1c(%edx), %xmm0\n" /* info */
        "jnp .Lf42ab4_00042fa5\n"
        ".Lf42ab4_00042fe7:\n"
        "movl (%esi), %eax\n" /* line 2089 | tree */
        "leal 0xc(%eax, %ecx, 8), %ecx\n"
        "movl 0xc(%ebp), %eax\n" /* nextSyncState */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* syncState */
        "movl %eax, (%esp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "movl %esi, %eax\n" /* tree */
        "movss %xmm1, -0x98(%ebp)\n"
        "calll XAnimGetServerNotifyFracSyncTotal\n"
        "movss -0x98(%ebp), %xmm1\n" /* line 2090 */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf42ab4_00042fa7\n"
        /* } scope */
        /* } scope */
        ".Lf42ab4_0004301f:\n"
        "minss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "jmp .Lf42ab4_00042f4a\n"
    );
}

/* line 2098 */
static __attribute__((naked))
float XAnimFindServerNoteTrack(float dtime)
{
    __asm__ __volatile__ (
        ".Lf4302e_0004302e:\n"
        "pushl %ebp\n" /* line 2098 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %esi\n" /* tree */
        "movss %xmm0, -0x5c(%ebp)\n"
        /* { scope 1: info, totalDtime */
        "movzwl 8(%eax, %edx, 2), %eax\n" /* line 2117 */
        "testw %ax, %ax\n" /* line 2118 */
        "je .Lf4302e_0004310e\n"
        "movzwl %ax, %eax\n" /* line 2122 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* info */
        "movl %eax, %ebx\n" /* line 2123 | state */
        "addl $0xc, %ebx\n" /* state */
        "pxor %xmm2, %xmm2\n" /* line 2125 */
        "ucomiss 0x14(%ebx), %xmm2\n" /* state */
        "jp .Lf4302e_00043074\n"
        "je .Lf4302e_0004310e\n"
        ".Lf4302e_00043074:\n"
        "ucomiss 0x10(%ebx), %xmm2\n" /* state */
        "jp .Lf4302e_00043080\n"
        "je .Lf4302e_0004310e\n"
        ".Lf4302e_00043080:\n"
        "movl (%esi), %eax\n" /* line 2128 | tree */
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* animIndex */
        "movl %edx, -0x50(%ebp)\n" /* animIndex, anim */
        "movzwl 0xc(%eax), %eax\n" /* line 2129 */
        "movzwl %ax, %edx\n" /* animIndex */
        "movl %edx, -0x58(%ebp)\n" /* animIndex, numAnims */
        "testw %ax, %ax\n" /* line 2130 */
        "jne .Lf4302e_00043124\n"
        "movl -0x50(%ebp), %edx\n" /* line 2132 | anim, animIndex */
        "movl 4(%edx), %eax\n" /* animIndex */
        "movss 0x18(%ebx), %xmm3\n" /* line 2135 | state */
        "mulss 8(%eax), %xmm3\n"
        "mulss -0x5c(%ebp), %xmm3\n"
        "ucomiss %xmm2, %xmm3\n" /* line 2136 */
        "je .Lf4302e_000433e3\n"
        ".Lf4302e_000430bc:\n"
        "movaps %xmm3, %xmm2\n" /* line 2139 */
        "addss 4(%ebx), %xmm2\n" /* state */
        "movzwl 0xa(%ebx), %ecx\n" /* line 2140 | state */
        "cmpb $0, 2(%eax)\n" /* line 2144 */
        "jne .Lf4302e_000432d6\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 2146 | 1.0f */
        "ucomiss %xmm5, %xmm2\n"
        "jb .Lf4302e_000430e2\n"
        "movaps %xmm5, %xmm2\n"
        ".Lf4302e_000430e2:\n"
        "movss (%ebx), %xmm4\n" /* line 2161 | state */
        "movswl %cx, %eax\n"
        "movswl 8(%ebx), %edx\n" /* state, animIndex */
        "subl %edx, %eax\n" /* animIndex */
        "cvtsi2ssl %eax, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf4302e_00043308\n"
        ".Lf4302e_00043103:\n"
        "movaps %xmm5, %xmm1\n" /* line 2204 */
        "jmp .Lf4302e_00043116\n"
        ".Lf4302e_00043108:\n"
        "jp .Lf4302e_0004328d\n" /* line 2217 */
        ".Lf4302e_0004310e:\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 2222 | 1.0f */
        /* } scope */
        ".Lf4302e_00043116:\n"
        "movaps %xmm1, %xmm0\n" /* line 2230 */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: info, totalDtime */
        ".Lf4302e_00043124:\n"
        "movl -0x50(%ebp), %eax\n" /* line 2172 | anim */
        "testb $3, 4(%eax)\n"
        "je .Lf4302e_00043275\n"
        /* { scope 2: i */
        "movl -0x58(%ebp), %eax\n" /* line 1342 | numAnims */
        "testl %eax, %eax\n"
        "jg .Lf4302e_00043340\n"
        ".Lf4302e_0004313c:\n"
        "movaps %xmm2, %xmm0\n" /* line 1364 */
        /* } scope */
        ".Lf4302e_0004313f:\n"
        "mulss 0x18(%ebx), %xmm0\n" /* line 2174 | state */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss -0x5c(%ebp), %xmm0\n"
        "mulss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "ucomiss %xmm2, %xmm0\n" /* line 2175 */
        "je .Lf4302e_00043432\n"
        ".Lf4302e_00043161:\n"
        "movaps %xmm0, %xmm2\n"
        "addss 4(%ebx), %xmm2\n" /* line 2180 | state */
        "movzwl 0xa(%ebx), %ecx\n" /* line 2181 | state */
        "movl -0x50(%ebp), %eax\n" /* line 2185 | anim */
        "testb $2, 4(%eax)\n"
        "je .Lf4302e_00043410\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 2188 | 1.0f */
        "ucomiss %xmm5, %xmm2\n"
        "jb .Lf4302e_0004318a\n"
        "movaps %xmm5, %xmm2\n"
        ".Lf4302e_0004318a:\n"
        "movss (%ebx), %xmm3\n" /* line 2204 | state */
        "movswl %cx, %eax\n"
        "movswl 8(%ebx), %edx\n" /* state, animIndex */
        "subl %edx, %eax\n" /* animIndex */
        "cvtsi2ssl %eax, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf4302e_00043103\n"
        "movss %xmm3, -0x30(%ebp)\n" /* line 2207 */
        "movzwl 8(%ebx), %eax\n" /* line 2208 | state */
        "movw %ax, -0x2a(%ebp)\n"
        "movss %xmm2, -0x34(%ebp)\n" /* line 2209 | nextState */
        "movw %cx, -0x2c(%ebp)\n" /* line 2210 */
        /* { scope 2: i */
        /* { scope 3 */
        "leal -0x34(%ebp), %edx\n" /* line 2071 | nextState */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movl -0x50(%ebp), %ecx\n" /* anim */
        "movl -0x54(%ebp), %edx\n" /* info */
        "movl %esi, %eax\n"
        "calll XAnimGetNotifyFracServer\n"
        "movaps %xmm0, %xmm1\n"
        "movl -0x50(%ebp), %eax\n" /* line 2073 | anim */
        "movzwl (%eax), %edi\n" /* i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf4302e_00043116\n"
        "movl $0, -0x44(%ebp)\n" /* i */
        "jmp .Lf4302e_00043204\n"
        ".Lf4302e_000431f7:\n"
        "addl $1, -0x44(%ebp)\n" /* i */
        "cmpl %edi, -0x44(%ebp)\n" /* i */
        "jge .Lf4302e_00043116\n"
        ".Lf4302e_00043204:\n"
        "movl -0x50(%ebp), %edx\n" /* line 2075 | anim */
        "movzwl 6(%edx), %eax\n"
        "movl -0x44(%ebp), %ecx\n" /* i */
        "addl %eax, %ecx\n"
        "movzwl 8(%esi, %ecx, 2), %eax\n" /* line 2079 */
        "testw %ax, %ax\n" /* line 2080 */
        "je .Lf4302e_000431f7\n"
        "movzwl %ax, %eax\n" /* line 2084 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %edx\n"
        "pxor %xmm0, %xmm0\n" /* line 2086 */
        "ucomiss 0x20(%edx), %xmm0\n"
        "jp .Lf4302e_00043233\n"
        "je .Lf4302e_000431f7\n"
        ".Lf4302e_00043233:\n"
        "ucomiss 0x1c(%edx), %xmm0\n"
        "jp .Lf4302e_0004323b\n"
        "je .Lf4302e_000431f7\n"
        ".Lf4302e_0004323b:\n"
        "movl (%esi), %eax\n" /* line 2089 */
        "leal 0xc(%eax, %ecx, 8), %ecx\n"
        "leal -0x34(%ebp), %eax\n" /* nextState */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movl %esi, %eax\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll XAnimGetServerNotifyFracSyncTotal\n"
        "movss -0x78(%ebp), %xmm1\n" /* line 2090 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf4302e_0004343d\n"
        "movaps %xmm0, %xmm1\n"
        "movl -0x50(%ebp), %edx\n" /* anim */
        "movzwl (%edx), %edi\n" /* i */
        "jmp .Lf4302e_000431f7\n"
        /* } scope */
        /* } scope */
        ".Lf4302e_00043275:\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 2216 */
        "mulss 0x18(%ebx), %xmm0\n" /* state */
        "movss %xmm0, -0x40(%ebp)\n"
        "ucomiss %xmm2, %xmm0\n" /* line 2217 */
        "je .Lf4302e_00043108\n"
        ".Lf4302e_0004328d:\n"
        "movl -0x58(%ebp), %eax\n" /* line 2222 | numAnims */
        "testl %eax, %eax\n"
        "jle .Lf4302e_0004310e\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 2217 | 1.0f */
        "xorl %ebx, %ebx\n" /* state */
        ".Lf4302e_000432a2:\n"
        "movl -0x50(%ebp), %eax\n" /* line 2224 | anim */
        "movzwl 6(%eax), %edx\n"
        "leal (%ebx, %edx), %edx\n" /* state */
        "movss -0x40(%ebp), %xmm0\n"
        "movl %esi, %eax\n" /* tree */
        "movss %xmm1, -0x78(%ebp)\n"
        "calll XAnimFindServerNoteTrack\n"
        "movss -0x78(%ebp), %xmm1\n" /* line 2225 */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "addl $1, %ebx\n" /* line 2222 | state */
        "cmpl %ebx, -0x58(%ebp)\n" /* state, numAnims */
        "jne .Lf4302e_000432a2\n"
        "jmp .Lf4302e_00043116\n"
        ".Lf4302e_000432d6:\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 2151 | 1.0f */
        "ucomiss %xmm5, %xmm2\n"
        "jb .Lf4302e_000430e2\n"
        ".Lf4302e_000432e7:\n"
        "subss %xmm5, %xmm2\n" /* line 2153 */
        "addl $1, %ecx\n" /* line 2154 */
        "ucomiss %xmm5, %xmm2\n" /* line 2151 */
        "jb .Lf4302e_000430e2\n"
        "subss %xmm5, %xmm2\n" /* line 2153 */
        "addl $1, %ecx\n" /* line 2154 */
        "ucomiss %xmm5, %xmm2\n" /* line 2151 */
        "jae .Lf4302e_000432e7\n"
        "jmp .Lf4302e_000430e2\n"
        ".Lf4302e_00043308:\n"
        "movss %xmm4, -0x30(%ebp)\n" /* line 2164 */
        "movzwl 8(%ebx), %eax\n" /* line 2165 | state */
        "movw %ax, -0x2a(%ebp)\n"
        "movss %xmm2, -0x34(%ebp)\n" /* line 2166 | nextState */
        "movw %cx, -0x2c(%ebp)\n" /* line 2167 */
        "leal -0x34(%ebp), %eax\n" /* line 2169 | nextState */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* state */
        "movaps %xmm3, %xmm0\n"
        "movl -0x50(%ebp), %ecx\n" /* anim */
        "movl -0x54(%ebp), %edx\n" /* info, animIndex */
        "movl %esi, %eax\n" /* tree */
        "calll XAnimGetNotifyFracServer\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf4302e_00043116\n"
        ".Lf4302e_00043340:\n"
        "xorl %edi, %edi\n" /* line 2172 | i */
        "movaps %xmm2, %xmm3\n"
        "movss %xmm2, -0x48(%ebp)\n" /* totalDtime */
        "jmp .Lf4302e_00043358\n"
        /* { scope 2: i */
        ".Lf4302e_0004334c:\n"
        "addl $1, %edi\n" /* line 1342 | i */
        "cmpl %edi, -0x58(%ebp)\n" /* i, numAnims */
        "je .Lf4302e_000433ee\n"
        ".Lf4302e_00043358:\n"
        "movl -0x50(%ebp), %edx\n" /* line 1345 | anim */
        "movzwl 6(%edx), %eax\n"
        "leal (%edi, %eax), %edx\n" /* i */
        "movzwl 8(%esi, %edx, 2), %eax\n"
        "testw %ax, %ax\n" /* line 1346 */
        "je .Lf4302e_0004334c\n"
        "movzwl %ax, %eax\n" /* line 1350 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal g_xAnimInfo(, %eax, 8), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* info */
        "movss 0x20(%eax), %xmm1\n" /* line 1351 */
        "ucomiss %xmm2, %xmm1\n" /* line 1353 */
        "jp .Lf4302e_00043388\n"
        "je .Lf4302e_0004334c\n"
        ".Lf4302e_00043388:\n"
        "movl %esi, %eax\n" /* line 1356 */
        "movss %xmm1, -0x78(%ebp)\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "movss %xmm3, -0x98(%ebp)\n"
        "calll XAnimGetAverageRateFrequency\n"
        "movss -0x78(%ebp), %xmm1\n" /* line 1357 */
        "movss -0x88(%ebp), %xmm2\n"
        "movss -0x98(%ebp), %xmm3\n"
        "ucomiss %xmm2, %xmm0\n"
        "jp .Lf4302e_000433c0\n"
        "je .Lf4302e_00043407\n"
        ".Lf4302e_000433c0:\n"
        "addss %xmm1, %xmm3\n" /* line 1360 */
        "mulss %xmm0, %xmm1\n" /* line 1361 */
        "movl -0x4c(%ebp), %eax\n" /* info */
        "mulss 0x24(%eax), %xmm1\n"
        "addss -0x48(%ebp), %xmm1\n" /* totalDtime */
        "movss %xmm1, -0x48(%ebp)\n" /* totalDtime */
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf4302e_0004334c\n"
        /* } scope */
        ".Lf4302e_000433e3:\n"
        "jnp .Lf4302e_0004310e\n" /* line 2136 */
        "jmp .Lf4302e_000430bc\n"
        /* { scope 2: i */
        ".Lf4302e_000433ee:\n"
        "ucomiss %xmm2, %xmm3\n" /* line 1364 */
        "jp .Lf4302e_000433f9\n"
        "je .Lf4302e_0004313c\n"
        ".Lf4302e_000433f9:\n"
        "movss -0x48(%ebp), %xmm0\n" /* totalDtime */
        "divss %xmm3, %xmm0\n"
        "jmp .Lf4302e_0004313f\n"
        ".Lf4302e_00043407:\n"
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf4302e_0004334c\n"
        /* } scope */
        ".Lf4302e_00043410:\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 2194 | 1.0f */
        "ucomiss %xmm5, %xmm2\n"
        "jb .Lf4302e_0004318a\n"
        ".Lf4302e_00043421:\n"
        "subss %xmm5, %xmm2\n" /* line 2196 */
        "addl $1, %ecx\n" /* line 2197 */
        "ucomiss %xmm5, %xmm2\n" /* line 2194 */
        "jae .Lf4302e_00043421\n"
        "jmp .Lf4302e_0004318a\n"
        ".Lf4302e_00043432:\n"
        "jnp .Lf4302e_0004310e\n" /* line 2175 */
        "jmp .Lf4302e_00043161\n"
        ".Lf4302e_0004343d:\n"
        "movl -0x50(%ebp), %eax\n" /* anim */
        "movzwl (%eax), %edi\n" /* i */
        "jmp .Lf4302e_000431f7\n"
    );
}

/* line 3146 */
__attribute__((naked))
int DObjUpdateServerInfo(DObj *obj, float dtime, int bNotify)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3146 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* obj */
        "movss 0xc(%ebp), %xmm1\n" /* dtime */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 3155 | obj */
        "testl %eax, %eax\n"
        "je .Lf43448_000434a7\n"
        "movl 0x10(%ebp), %edx\n" /* line 3161 | bNotify */
        "testl %edx, %edx\n"
        "je .Lf43448_000434ad\n"
        "movaps %xmm1, %xmm0\n" /* line 3169 */
        "xorl %edx, %edx\n"
        "movss %xmm1, -0x18(%ebp)\n"
        "calll XAnimFindServerNoteTrack\n"
        "movss -0x18(%ebp), %xmm1\n" /* line 3172 */
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "jp .Lf43448_00043483\n"
        "je .Lf43448_00043494\n"
        ".Lf43448_00043483:\n"
        "mulss %xmm1, %xmm0\n" /* line 3174 */
        "addss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "ucomiss %xmm0, %xmm1\n" /* line 3175 */
        "jae .Lf43448_000434c1\n"
        ".Lf43448_00043494:\n"
        "movl $1, %ecx\n" /* line 3184 */
        "movaps %xmm1, %xmm0\n"
        "xorl %edx, %edx\n"
        "movl (%ebx), %eax\n" /* obj */
        "calll XAnimUpdateInfoInternal\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf43448_000434a7:\n"
        "addl $0x14, %esp\n" /* line 3188 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf43448_000434ad:\n"
        "xorl %ecx, %ecx\n" /* line 3163 */
        "movaps %xmm1, %xmm0\n"
        "xorl %edx, %edx\n"
        "calll XAnimUpdateInfoInternal\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 3188 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf43448_000434c1:\n"
        "movl $1, %ecx\n" /* line 3177 */
        "xorl %edx, %edx\n"
        "movl (%ebx), %eax\n" /* obj */
        "calll XAnimUpdateInfoInternal\n"
        "movl $1, %eax\n"
        "jmp .Lf43448_000434a7\n"
    );
}

