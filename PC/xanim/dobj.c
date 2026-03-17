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
    return (*(unsigned char *)((byte *)obj + 0x1a) >> modelIndex) & 1;
}

/* line 580 */
int DObjSkelIsBoneUpToDate(DObj *obj, int boneIndex)
{
    int *skel = *(int **)((byte *)obj + 4);
    return (*(int *)((byte *)skel + 0x20 + (boneIndex >> 5) * 4) >> (boneIndex & 0x1f)) & 1;
}

/* line 598 */
int DObjSkelAreBonesUpToDate(const DObj *obj, int *partBits)
{
    int i;
    int *skel = *(int **)((char *)obj + 4);
    for (i = 0; i < 4; i++) {
        if (~*(int *)((char *)skel + 0x24 + i * 4) & partBits[i])
            return 0;
    }
    return 1;
}

/* line 1142 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void DObjFree(DObj_s *obj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1142 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* obj */
        "movl (%ebx), %eax\n" /* line 1150 | obj */
        "testl %eax, %eax\n"
        "je .Lf74630_0007464e\n"
        "movl $0, 0xc(%ebx)\n" /* line 1155 | obj */
        "movl $0, (%ebx)\n" /* line 1156 | obj */
        ".Lf74630_0007464e:\n"
        "movzwl 0x10(%ebx), %eax\n" /* line 1160 | obj */
        "testw %ax, %ax\n"
        "je .Lf74630_00074692\n"
        "movzwl %ax, %eax\n" /* line 1162 */
        "cmpl g_empty, %eax\n"
        "je .Lf74630_0007468c\n"
        "movl %eax, (%esp)\n" /* line 1163 */
        "calll SL_ConvertToString\n"
        "leal 0x10(%eax), %edi\n" /* line 896 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl $0x10, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movzwl 0x10(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToStringOfLen\n"
        ".Lf74630_0007468c:\n"
        "movw $0, 0x10(%ebx)\n" /* line 1164 | obj */
        ".Lf74630_00074692:\n"
        "addl $0x10, %esp\n" /* line 1168 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void DObjFree(DObj_s *obj) {
    if (*(int *)obj) {
        *(int *)((byte *)obj + 0xc) = 0;
        *(int *)obj = 0;
    }
    if (*(unsigned short *)((byte *)obj + 0x10)) {
        unsigned short nameVal = *(unsigned short *)((byte *)obj + 0x10);
        if ((unsigned int)nameVal != g_empty) {
            const char *str = SL_ConvertToString(nameVal);
            int len = strlen(str + 16) + 16;
            SL_RemoveRefToStringOfLen(nameVal, len);
        }
        *(unsigned short *)((byte *)obj + 0x10) = 0;
    }
}
#endif

/* line 1223 */
int DObjGetAllocSkelSize(const DObj *obj)
{
    return (*(unsigned char *)((byte *)obj + 0x19) << 5) + 0x30;
}

/* line 1236 */
qboolean DObjSkelExists(const DObj *obj, int timeStamp)
{
    if (*(int *)((byte *)obj + 8) != timeStamp)
    {
        *(int *)((byte *)obj + 4) = 0;
        return 0;
    }
    return *(int *)((byte *)obj + 4) != 0;
}

/* line 1261 */
void DObjSkelClear(const DObj *obj)
{
    *(int *)((byte *)obj + 8) = 0;
    *(int *)((byte *)obj + 4) = 0;
}

/* line 1273 */
void DObjCreateSkel(const DObj *obj, char *buf, int timeStamp)
{
    int i;
    *(char **)((char *)obj + 4) = buf;
    *(int *)((char *)obj + 8) = timeStamp;
    for (i = 0; i < 4; i++) {
        *(int *)(buf + i * 4) = 0;
        *(int *)(buf + i * 4 + 0x10) = 0;
        *(int *)(buf + i * 4 + 0x20) = 0;
    }
}

/* line 1301 */
int DObjGetNumModels(const DObj *obj)
{
    return *(unsigned char *)((byte *)obj + 0x18);
}

/* line 1312 */
XModel * DObjGetModel(const DObj *obj, int modelIndex)
{
    return *(XModel **)((byte *)obj + 0x1c + modelIndex * 4);
}

/* line 1337 */
DObjAnimMat * DObjGetRotTransArray(const DObj *obj)
{
    int *skel = *(int **)((byte *)obj + 4);
    if (skel)
        return (DObjAnimMat *)((byte *)skel + 0x30);
    return 0;
}

/* line 1380 */
int DObjGetMatOffset(const DObj *obj, int modelIndex)
{
    return *(unsigned char *)((byte *)obj + 0x44 + modelIndex);
}

/* line 1393 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void DObjGetBoneInfo(const DObj *obj, XBoneInfo * *boneInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1393 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* boneInfo */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1401 | obj */
        "cmpb $0, 0x18(%eax)\n"
        "je .Lf7475e_000747bc\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0x14(%ebp)\n" /* j */
        "movl %eax, %edx\n"
        ".Lf7475e_0007477f:\n"
        "movl 0x1c(%edx), %edi\n" /* line 1403 | model */
        "movl (%edi), %eax\n" /* line 1405 | model */
        "movswl (%eax), %esi\n" /* size */
        "testl %esi, %esi\n" /* line 1406 | size */
        "jle .Lf7475e_000747a3\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf7475e_0007478f:\n"
        "movl %edx, %eax\n" /* line 1407 */
        "addl 0x60(%edi), %eax\n" /* model */
        "movl %eax, (%ebx)\n" /* boneInfo */
        "addl $1, %ecx\n" /* line 1406 */
        "addl $4, %ebx\n" /* boneInfo */
        "addl $0x28, %edx\n"
        "cmpl %ecx, %esi\n" /* size */
        "jne .Lf7475e_0007478f\n"
        ".Lf7475e_000747a3:\n"
        "addl $1, -0x14(%ebp)\n" /* line 1401 | j */
        "addl $4, -0x10(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* obj */
        "movzbl 0x18(%edx), %eax\n"
        "cmpl %eax, -0x14(%ebp)\n" /* j */
        "jge .Lf7475e_000747bc\n"
        "movl -0x10(%ebp), %edx\n"
        "jmp .Lf7475e_0007477f\n"
        /* } scope */
        ".Lf7475e_000747bc:\n"
        "addl $8, %esp\n" /* line 1409 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void DObjGetBoneInfo(const DObj *obj, XBoneInfo * *boneInfo) {
    int j, i;
    int numModels = *(unsigned char *)((byte *)obj + 0x18);
    int k = 0;
    for (j = 0; j < numModels; j++) {
        int *model = *(int **)((byte *)obj + 0x1c + j * 4);
        int size = *(short *)(*(int *)model);
        for (i = 0; i < size; i++) {
            boneInfo[k++] = (XBoneInfo *)((byte *)*(int *)((byte *)model + 0x60) + i * 0x28);
        }
    }
}
#endif

/* line 1480 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int DObjGetNumSurfaces(const DObj *obj, char *lods)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1480 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edx\n" /* obj */
        /* { scope 1 */
        "movzbl 0x18(%edx), %eax\n" /* line 1490 */
        "subl $1, %eax\n"
        "js .Lf747c4_00074828\n"
        "leal 0x1c(%edx, %eax, 4), %ebx\n"
        "movl $0, -0x10(%ebp)\n" /* numSurfaces */
        "xorl %esi, %esi\n"
        "movl %eax, %edi\n"
        "notl %edi\n"
        "movl 0xc(%ebp), %ecx\n" /* lods */
        "addl %eax, %ecx\n"
        ".Lf747c4_000747ef:\n"
        "movzbl (%ecx), %eax\n" /* line 1492 */
        "testb %al, %al\n"
        "js .Lf747c4_00074810\n"
        "movzbl %al, %eax\n" /* line 1494 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl (%ebx), %edx\n"
        "leal 4(%edx, %eax, 4), %eax\n"
        "movl 0x10(%eax), %edx\n" /* line 1496 */
        "testl %edx, %edx\n"
        "je .Lf747c4_00074810\n"
        "movswl 8(%eax), %eax\n" /* line 1498 */
        "addl %eax, -0x10(%ebp)\n" /* numSurfaces */
        ".Lf747c4_00074810:\n"
        "subl $1, %esi\n"
        "subl $1, %ecx\n"
        "subl $4, %ebx\n"
        "cmpl %edi, %esi\n" /* line 1490 */
        "jne .Lf747c4_000747ef\n"
        /* } scope */
        "movl -0x10(%ebp), %eax\n" /* line 1501 | numSurfaces */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf747c4_00074828:\n"
        "movl $0, -0x10(%ebp)\n" /* line 1490 | numSurfaces */
        /* } scope */
        "movl -0x10(%ebp), %eax\n" /* line 1501 | numSurfaces */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
int DObjGetNumSurfaces(const DObj *obj, char *lods) {
    int numSurfaces = 0;
    int numModels = *(unsigned char *)((byte *)obj + 0x18);
    int i;
    for (i = numModels - 1; i >= 0; i--) {
        signed char lod = lods[i];
        if (lod >= 0) {
            int *model = *(int **)((byte *)obj + 0x1c + i * 4);
            byte *lodInfo = (byte *)model + (unsigned char)lod * 20 + 4;
            if (*(int *)(lodInfo + 0x10)) {
                numSurfaces += *(short *)(lodInfo + 8);
            }
        }
    }
    return numSurfaces;
}
#endif

/* line 1509 */
struct XSurface_s * DObjGetSurface(const DObj *obj, int modelIndex, int subMatIndex, int lod)
{
    char *model = (char *)(*(int *)((char *)obj + 0x1c + modelIndex * 4));
    char *lodInfo = model + lod * 20;
    int *surfs = *(int **)(lodInfo + 0x14);
    int *surfList = *(int **)surfs;
    return (struct XSurface_s *)*(int *)(surfList + subMatIndex);
}

/* line 1522 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
const char * DObjGetSurfaceName(DObj *obj, int modelIndex, int subMatIndex, int lod)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1522 */
        "movl %esp, %ebp\n"
        "movl 0x14(%ebp), %eax\n" /* lod, subMatIndex */
        /* { scope 1 */
        "leal (%eax, %eax, 4), %eax\n" /* line 1529 */
        "shll $2, %eax\n"
        "movl 8(%ebp), %ecx\n" /* obj */
        "movl 0xc(%ebp), %edx\n" /* modelIndex */
        "addl 0x1c(%ecx, %edx, 4), %eax\n"
        "movl 0x10(%eax), %edx\n"
        "movl 0x10(%ebp), %eax\n" /* subMatIndex */
        "movzwl (%edx, %eax, 2), %eax\n"
        "testw %ax, %ax\n" /* line 1530 */
        "jne .Lf7485e_0007488a\n"
        /* } scope */
        "movl $str_00217dc0, %eax\n" /* line 1531 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7485e_0007488a:\n"
        "movzwl %ax, %eax\n" /* line 1530 */
        "movl %eax, 8(%ebp)\n" /* obj */
        /* } scope */
        "popl %ebp\n" /* line 1531 */
        /* { scope 1 */
        "jmp SL_ConvertToString\n" /* line 1530 */
    );
}

/* line 1632 */
__attribute__((naked))
int DObjGetBoneIndex(const DObj *obj, unsigned int boneName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1632 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* obj */
        /* { scope 1: numModels, boneIndex */
        /* { scope 2 */
        "movzbl 0x18(%eax), %edx\n" /* line 217 */
        "movl %edx, -0x20(%ebp)\n" /* numModels */
        "testl %edx, %edx\n" /* line 220 */
        "jg .Lf74896_000748ba\n"
        ".Lf74896_000748ad:\n"
        "movl $0xffffffff, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf74896_000748b2:\n"
        "addl $0x2c, %esp\n" /* line 1646 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numModels, boneIndex */
        /* { scope 2 */
        ".Lf74896_000748ba:\n"
        "movl %eax, %esi\n" /* line 220 */
        "xorl %edi, %edi\n" /* j */
        "movl $0, -0x1c(%ebp)\n" /* boneIndex */
        ".Lf74896_000748c5:\n"
        "movl 0x1c(%esi), %ebx\n" /* line 222 | model */
        "movl 0xc(%ebp), %eax\n" /* line 223 | boneName */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* model */
        "calll XModelGetBoneIndex\n"
        "testl %eax, %eax\n" /* line 224 */
        "jns .Lf74896_000748f0\n"
        "movl (%ebx), %eax\n" /* line 220 | model */
        "movswl (%eax), %eax\n"
        "addl %eax, -0x1c(%ebp)\n" /* boneIndex */
        "addl $1, %edi\n" /* j */
        "addl $4, %esi\n"
        "cmpl %edi, -0x20(%ebp)\n" /* j, numModels */
        "jne .Lf74896_000748c5\n"
        "jmp .Lf74896_000748ad\n"
        ".Lf74896_000748f0:\n"
        "addl -0x1c(%ebp), %eax\n" /* line 225 | boneIndex */
        "jmp .Lf74896_000748b2\n"
    );
}

/* line 1696 */
XAnimTree * DObjGetTree(const DObj *obj)
{
    return *(XAnimTree **)obj;
}

/* line 1709 */
__attribute__((naked))
int DObjBad(const DObj *obj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1709 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* obj */
        /* { scope 1 */
        "movzbl 0x18(%ecx), %edx\n" /* line 1713 */
        "movl %edx, %eax\n"
        "subl $1, %eax\n"
        "js .Lf74900_00074937\n"
        "leal 0x1c(%ecx, %eax, 4), %ebx\n"
        "xorl %esi, %esi\n"
        "movl %edx, %edi\n"
        ".Lf74900_0007491f:\n"
        "movl (%ebx), %eax\n" /* line 1715 */
        "movl %eax, (%esp)\n"
        "calll XModelBad\n"
        "testl %eax, %eax\n"
        "jne .Lf74900_00074941\n"
        "addl $1, %esi\n"
        "subl $4, %ebx\n"
        "cmpl %edi, %esi\n" /* line 1713 */
        "jne .Lf74900_0007491f\n"
        ".Lf74900_00074937:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1719 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf74900_00074941:\n"
        "movl $1, %eax\n" /* line 1715 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1719 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1728 */
int DObjNumBones(const DObj *obj)
{
    return *(unsigned char *)((byte *)obj + 0x19);
}

/* line 2125 */
int DObjGetLodForDist(const DObj *obj, int modelIndex, float dist)
{
    return XModelGetLodForDist(*(XModel **)((byte *)obj + 0x1c + modelIndex * 4), dist);
}

/* line 2131 */
__attribute__((naked))
float DObjGetLodOutDist(const DObj *obj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2131 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* obj */
        /* { scope 1 */
        "pxor %xmm0, %xmm0\n" /* line 2138 */
        "cmpb $0, 0x18(%edi)\n" /* obj */
        "jne .Lf74976_0007499c\n"
        /* } scope */
        "movss %xmm0, -0x3c(%ebp)\n" /* line 2145 */
        "flds -0x3c(%ebp)\n"
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf74976_0007499c:\n"
        "movl %edi, %ebx\n" /* line 2138 | obj */
        "xorl %esi, %esi\n" /* modelIndex */
        "pxor %xmm0, %xmm0\n"
        ".Lf74976_000749a4:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 2140 */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "calll XModelGetLodOutDist\n"
        "fstps -0x1c(%ebp)\n" /* lodOutDistCur */
        "movss -0x38(%ebp), %xmm0\n" /* line 2141 */
        "movss -0x1c(%ebp), %xmm1\n" /* lodOutDistCur */
        "maxss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "addl $1, %esi\n" /* line 2138 | modelIndex */
        "addl $4, %ebx\n"
        "movzbl 0x18(%edi), %eax\n" /* obj */
        "cmpl %esi, %eax\n" /* modelIndex */
        "jg .Lf74976_000749a4\n"
        /* } scope */
        "movss %xmm0, -0x3c(%ebp)\n" /* line 2145 */
        "flds -0x3c(%ebp)\n"
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2242 */
__attribute__((naked))
int DObjHasContents(DObj *obj, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2242 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* obj */
        /* { scope 1 */
        "cmpb $0, 0x18(%edi)\n" /* line 2246 | obj */
        "jne .Lf749e6_00074a02\n"
        ".Lf749e6_000749f8:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf749e6_000749fa:\n"
        "addl $0x1c, %esp\n" /* line 2252 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf749e6_00074a02:\n"
        "movl %edi, %ebx\n" /* line 2246 | obj */
        "xorl %esi, %esi\n" /* i */
        ".Lf749e6_00074a06:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 2248 */
        "movl %eax, (%esp)\n"
        "calll XModelGetContents\n"
        "testl %eax, 0xc(%ebp)\n" /* contentmask */
        "jne .Lf749e6_00074a26\n"
        "addl $1, %esi\n" /* line 2246 | i */
        "addl $4, %ebx\n"
        "movzbl 0x18(%edi), %eax\n" /* obj */
        "cmpl %esi, %eax\n" /* i */
        "jg .Lf749e6_00074a06\n"
        "jmp .Lf749e6_000749f8\n"
        ".Lf749e6_00074a26:\n"
        "movl $1, %eax\n"
        "jmp .Lf749e6_000749fa\n"
    );
}

/* line 2362 */
void DObjSetModel(DObj *obj, const XModel *model)
{
    *(int *)((byte *)obj + 4) = *(int *)model + 0x14;
    *(unsigned char *)((byte *)obj + 0x19) = (unsigned char)*(unsigned short *)*(int *)model;
    *(const XModel **)((byte *)obj + 0x1c) = model;
}

/* line 1323 */
__attribute__((naked))
void DObjGetBounds(const DObj *obj, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1323 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* obj */
        "movl 0xc(%ebp), %edx\n" /* mins */
        "movl 0x10(%ebp), %esi\n" /* maxs */
        "leal 0x4c(%ecx), %ebx\n" /* line 1327 | from */
        /* { scope 1 */
        "movl 0x4c(%ecx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x58(%ecx), %edx\n" /* line 1328 | from */
        /* { scope 1 */
        "movl 0x58(%ecx), %eax\n" /* line 199 */
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        /* } scope */
        "popl %ebx\n" /* line 1329 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2076 */
__attribute__((naked))
void DObjGeomTraceline(DObj *obj, vec_t *localStart, vec_t *localEnd, int contentmask, DObjTrace *results)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2076 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl 0x18(%ebp), %eax\n" /* line 2087 | results */
        "movw $0, 0x14(%eax)\n"
        "movw $0, 0x16(%eax)\n" /* line 2088 */
        "movl 0x18(%ebp), %edx\n" /* line 2090 | results */
        "movl (%edx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* trace */
        "movl $0, -0x2c(%ebp)\n" /* line 2092 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, -0x34(%ebp)\n" /* line 184 */
        "movl %eax, -0x30(%ebp)\n" /* line 185 */
        "movl 8(%ebp), %ecx\n" /* line 1341 | obj */
        "movl 4(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf74a86_00074ad5\n"
        "movl %eax, %edi\n" /* line 2096 | boneMtxList */
        "addl $0x30, %edi\n" /* boneMtxList */
        "je .Lf74a86_00074ad2\n"
        "movl 8(%ebp), %eax\n" /* line 2098 | obj */
        "cmpb $0, 0x18(%eax)\n"
        "jne .Lf74a86_00074b03\n"
        ".Lf74a86_00074ad2:\n"
        "movl 0x18(%ebp), %edx\n" /* results */
        ".Lf74a86_00074ad5:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2113 | trace */
        "movl %eax, (%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2115 */
        "movl %eax, 4(%edx)\n"
        "movl 0x18(%ebp), %edx\n" /* line 2116 | results, to */
        "addl $8, %edx\n" /* to */
        /* { scope 2 */
        "movl -0x38(%ebp), %eax\n" /* line 199 */
        "movl 0x18(%ebp), %ecx\n" /* results */
        "movl %eax, 8(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x30(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2117 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf74a86_00074b03:\n"
        "movl %eax, %esi\n" /* line 2098 */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf74a86_00074b07:\n"
        "movl 0x1c(%esi), %edx\n" /* line 2100 */
        "movl (%edx), %eax\n" /* line 2101 */
        "movl %eax, -0x50(%ebp)\n" /* modelParts */
        "movl 4(%eax), %eax\n" /* line 2103 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* names */
        "movl 0x14(%ebp), %eax\n" /* line 2105 | contentmask */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* localEnd */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* localStart */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* boneMtxList */
        "leal -0x3c(%ebp), %ecx\n" /* trace */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll XModelTraceLine\n"
        "testl %eax, %eax\n" /* line 2106 */
        "js .Lf74a86_00074b51\n"
        "movl -0x4c(%ebp), %edx\n" /* line 2107 | names */
        "movzwl (%edx, %eax, 2), %eax\n"
        "movl 0x18(%ebp), %ecx\n" /* results */
        "movw %ax, 0x14(%ecx)\n"
        ".Lf74a86_00074b51:\n"
        "movl -0x50(%ebp), %edx\n" /* line 2109 | modelParts */
        "movswl (%edx), %eax\n"
        "shll $5, %eax\n"
        "addl %eax, %edi\n" /* boneMtxList */
        "addl $1, %ebx\n" /* line 2098 | i */
        "addl $4, %esi\n"
        "movl 8(%ebp), %ecx\n" /* obj */
        "movzbl 0x18(%ecx), %eax\n"
        "cmpl %ebx, %eax\n" /* i */
        "jg .Lf74a86_00074b07\n"
        "jmp .Lf74a86_00074ad2\n"
    );
}

/* line 1539 */
__attribute__((naked))
int DObjGetSurfaces(const DObj *obj, DSurface *surfaces, int *partBits, char *lods)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1539 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1563 | partBits */
        "movl $0, (%eax)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 1565 | obj */
        "movzbl 0x18(%edx), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* numModels */
        "testl %edx, %edx\n" /* line 1568 */
        "jle .Lf74b72_00074dce\n"
        "movb $0, -0x4d(%ebp)\n" /* j */
        "movl $0, -0x58(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* surfaceCount */
        "movl 0xc(%ebp), %ecx\n" /* surfaces */
        "movl %ecx, -0x5c(%ebp)\n"
        ".Lf74b72_00074bc3:\n"
        "movzbl -0x4d(%ebp), %eax\n" /* line 1570 | j */
        "movl 0x14(%ebp), %ebx\n" /* lods */
        "movzbl (%eax, %ebx), %eax\n"
        "testb %al, %al\n"
        "js .Lf74b72_00074cab\n"
        "movl -0x58(%ebp), %ecx\n" /* line 1572 */
        "movl 8(%ebp), %ebx\n" /* obj */
        "movl 0x1c(%ebx, %ecx, 4), %edx\n"
        "movzbl %al, %eax\n" /* line 1573 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal 4(%edx, %eax, 4), %ecx\n"
        "movl 0x10(%ecx), %eax\n" /* line 1574 */
        "movl %eax, -0x48(%ebp)\n" /* surfs */
        "testl %eax, %eax\n" /* line 1575 */
        "je .Lf74b72_00074cab\n"
        "movl (%edx), %eax\n" /* line 1577 */
        "movswl (%eax), %eax\n"
        "subl $1, %eax\n"
        "sarl $5, %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* numBoneBits */
        "movswl 8(%ecx), %ecx\n" /* line 1579 */
        "movl %ecx, -0x4c(%ebp)\n" /* numsurfs */
        "movl %ecx, %eax\n" /* line 1581 */
        "addl -0x34(%ebp), %eax\n" /* surfaceCount */
        "cmpl $0x40, %eax\n"
        "jg .Lf74b72_00074cf0\n"
        ".Lf74b72_00074c1b:\n"
        "movl -0x4c(%ebp), %esi\n" /* line 1592 | numsurfs */
        "testl %esi, %esi\n"
        "jle .Lf74b72_00074c49\n"
        "movzbw -0x4d(%ebp), %cx\n" /* j */
        "movl -0x5c(%ebp), %eax\n"
        "addl $2, %eax\n"
        "xorl %edx, %edx\n"
        ".Lf74b72_00074c2f:\n"
        "movw %dx, (%eax)\n" /* line 1594 */
        "movw %cx, -2(%eax)\n" /* line 1595 */
        "addl $1, %edx\n" /* line 1592 */
        "addl $1, -0x34(%ebp)\n" /* surfaceCount */
        "addl $4, -0x5c(%ebp)\n"
        "addl $4, %eax\n"
        "cmpl %edx, -0x4c(%ebp)\n" /* numsurfs */
        "jne .Lf74b72_00074c2f\n"
        ".Lf74b72_00074c49:\n"
        "movl -0x58(%ebp), %edx\n" /* line 1598 */
        "movl 8(%ebp), %ecx\n" /* obj */
        "movzbl 0x44(%edx, %ecx), %eax\n"
        "movl -0x48(%ebp), %ebx\n" /* line 1599 | surfs */
        "addl $4, %ebx\n"
        "movl %ebx, -0x44(%ebp)\n" /* surfPartBits */
        "movl %eax, %edx\n" /* line 1600 */
        "sarl $5, %edx\n"
        "movl %eax, %edi\n" /* line 1603 | targBoneIndexLow */
        "andl $0x1f, %edi\n" /* targBoneIndexLow */
        "je .Lf74b72_00074cca\n"
        "movl $0x20, -0x38(%ebp)\n" /* line 1605 | invTargBoneIndexLow */
        "subl %edi, -0x38(%ebp)\n" /* targBoneIndexLow, invTargBoneIndexLow */
        "movl -0x48(%ebp), %ecx\n" /* line 1607 | surfs */
        "movl 4(%ecx), %eax\n"
        "movl %edi, %ecx\n" /* targBoneIndexLow */
        "shll %cl, %eax\n"
        "movl 0x10(%ebp), %ebx\n" /* partBits */
        "orl %eax, (%ebx, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1608 */
        "movl %edx, -0x3c(%ebp)\n" /* targBoneIndexHigh */
        "movl -0x40(%ebp), %ebx\n" /* line 1609 | numBoneBits */
        "testl %ebx, %ebx\n"
        "jg .Lf74b72_00074d89\n"
        "xorl %eax, %eax\n"
        ".Lf74b72_00074c96:\n"
        "movl -0x44(%ebp), %ebx\n" /* line 1611 | surfPartBits */
        "movl (%ebx, %eax, 4), %eax\n"
        "movzbl -0x38(%ebp), %ecx\n" /* invTargBoneIndexLow */
        "shrl %cl, %eax\n"
        "movl -0x3c(%ebp), %ebx\n" /* targBoneIndexHigh */
        "movl 0x10(%ebp), %edx\n" /* partBits */
        "orl %eax, (%edx, %ebx, 4)\n"
        ".Lf74b72_00074cab:\n"
        "addb $1, -0x4d(%ebp)\n" /* line 1568 | j */
        "movzbl -0x4d(%ebp), %eax\n" /* j */
        "movl %eax, -0x58(%ebp)\n"
        "cmpl %eax, -0x54(%ebp)\n" /* numModels */
        "jg .Lf74b72_00074bc3\n"
        /* } scope */
        "movl -0x34(%ebp), %eax\n" /* line 1624 | surfaceCount */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf74b72_00074cca:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 1617 | numBoneBits */
        "testl %ecx, %ecx\n"
        "js .Lf74b72_00074cab\n"
        "movl 0x10(%ebp), %eax\n" /* partBits */
        "leal (%eax, %edx, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf74b72_00074cd9:\n"
        "movl (%edx), %eax\n" /* line 1618 */
        "movl -0x44(%ebp), %ebx\n" /* surfPartBits */
        "orl (%ebx, %ecx, 4), %eax\n"
        "movl %eax, (%edx)\n"
        "addl $1, %ecx\n" /* line 1617 */
        "addl $4, %edx\n"
        "cmpl %ecx, -0x40(%ebp)\n" /* numBoneBits */
        "jge .Lf74b72_00074cd9\n"
        "jmp .Lf74b72_00074cab\n"
        ".Lf74b72_00074cf0:\n"
        "movl $0x40, 4(%esp)\n" /* line 1583 */
        "movl $str_0021bfd8, (%esp)\n" /* "ERROR: models with more than %i total surfaces
" */
        "calll Com_Printf\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* modelIndex */
        "movl %ebx, %edx\n"
        "jmp .Lf74b72_00074d15\n"
        ".Lf74b72_00074d12:\n"
        "movl -0x2c(%ebp), %edx\n"
        ".Lf74b72_00074d15:\n"
        "movl 0x1c(%edx), %edi\n" /* line 1314 */
        "movl 0x14(%ebp), %esi\n" /* line 1539 | lods */
        "addl -0x30(%ebp), %esi\n" /* modelIndex */
        "leal -0x20(%ebp), %ecx\n" /* line 1587 | debugPartBits */
        "movl %ecx, 0xc(%esp)\n"
        "movsbl (%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %ebx\n" /* xsurfs */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* targBoneIndexLow */
        "calll XModelGetSurfaces\n"
        "movl %eax, %ebx\n"
        "movsbl (%esi), %esi\n"
        "movl %edi, (%esp)\n" /* targBoneIndexLow */
        "calll XModelGetName\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021c008, (%esp)\n" /* "  model '%s' lod %i has %i surfaces
" */
        "calll Com_Printf\n"
        "addl $1, -0x30(%ebp)\n" /* line 1584 | modelIndex */
        "addl $4, -0x2c(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* modelIndex */
        "cmpl %eax, -0x54(%ebp)\n" /* numModels */
        "jne .Lf74b72_00074d12\n"
        "movl $str_0021c030, 4(%esp)\n" /* line 1589 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf74b72_00074c1b\n"
        ".Lf74b72_00074d89:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1539 | partBits */
        "leal (%ecx, %edx, 4), %ebx\n"
        "xorl %esi, %esi\n"
        "movl -0x44(%ebp), %eax\n" /* surfPartBits */
        "movl %eax, -0x6c(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf74b72_00074d9e\n"
        ".Lf74b72_00074d9b:\n"
        "movl -0x6c(%ebp), %ecx\n"
        ".Lf74b72_00074d9e:\n"
        "movl (%ecx), %edx\n" /* line 1610 */
        "movzbl -0x38(%ebp), %ecx\n" /* invTargBoneIndexLow */
        "shrl %cl, %edx\n"
        "movl -0x6c(%ebp), %ecx\n"
        "movl 4(%ecx), %eax\n"
        "movl %edi, %ecx\n" /* targBoneIndexLow */
        "shll %cl, %eax\n"
        "orl %eax, %edx\n"
        "orl %edx, (%ebx)\n"
        "addl $1, %esi\n" /* line 1609 */
        "addl $4, -0x6c(%ebp)\n"
        "addl $4, %ebx\n"
        "cmpl %esi, -0x40(%ebp)\n" /* numBoneBits */
        "jne .Lf74b72_00074d9b\n"
        "movl -0x40(%ebp), %eax\n" /* line 1539 | numBoneBits */
        "addl %eax, -0x3c(%ebp)\n" /* targBoneIndexHigh */
        "jmp .Lf74b72_00074c96\n"
        ".Lf74b72_00074dce:\n"
        "movl $0, -0x34(%ebp)\n" /* line 1568 | surfaceCount */
        /* } scope */
        "movl -0x34(%ebp), %eax\n" /* line 1624 | surfaceCount */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 240 */
static __attribute__((naked))
void DObjCreateDuplicateParts(const DObj *obj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 240 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4ac, %esp\n"
        "movl %eax, -0x4a4(%ebp)\n"
        /* { scope 1: name */
        "movl $0, -0x45c(%ebp)\n" /* line 266 | duplicatePartBits */
        "movl $0, -0x458(%ebp)\n"
        "movl $0, -0x454(%ebp)\n"
        "movl $0, -0x450(%ebp)\n"
        "movl %eax, %edx\n" /* line 269 */
        "movl 0x1c(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movswl (%eax), %eax\n"
        "movl %eax, -0x49c(%ebp)\n" /* boneIndex */
        "movzbl 0x18(%edx), %eax\n" /* line 271 */
        "subl $1, %eax\n"
        "jle .Lf74de0_000750aa\n"
        "movl %edx, -0x474(%ebp)\n"
        "movl %edx, -0x470(%ebp)\n"
        "movl $1, -0x4a0(%ebp)\n" /* j */
        "movl $0, -0x46c(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf74de0_00074e99\n"
        ".Lf74de0_00074e5b:\n"
        "movl %eax, %edx\n"
        ".Lf74de0_00074e5d:\n"
        "addl $1, -0x4a0(%ebp)\n" /* j */
        "movl (%edx), %eax\n"
        "movswl (%eax), %eax\n"
        "addl %eax, -0x49c(%ebp)\n" /* boneIndex */
        "addl $4, -0x474(%ebp)\n"
        "addl $1, -0x470(%ebp)\n"
        "movl -0x4a4(%ebp), %edx\n"
        "movzbl 0x18(%edx), %eax\n"
        "cmpl %eax, -0x4a0(%ebp)\n" /* j */
        "jge .Lf74de0_000750a0\n"
        "movl -0x474(%ebp), %eax\n"
        ".Lf74de0_00074e99:\n"
        "movl 0x20(%eax), %eax\n" /* line 273 */
        "movl %eax, -0x498(%ebp)\n" /* model */
        "movl -0x470(%ebp), %edx\n" /* line 274 */
        "cmpb $0xff, 0x3d(%edx)\n"
        "jne .Lf74de0_00074e5b\n"
        "movl (%eax), %edx\n" /* line 277 */
        "movl 4(%edx), %eax\n" /* line 279 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x48c(%ebp)\n" /* boneNames */
        "movswl (%edx), %edx\n" /* line 280 */
        "movl %edx, -0x490(%ebp)\n" /* numBones */
        "testl %edx, %edx\n" /* line 288 */
        "jle .Lf74de0_00075051\n"
        "movzbl -0x49c(%ebp), %eax\n" /* boneIndex */
        "addb $1, %al\n"
        "movb %al, -0x475(%ebp)\n"
        "movl $0, -0x494(%ebp)\n" /* localBoneIndex */
        "movb $0, -0x485(%ebp)\n" /* bRootMeld */
        "movl -0x494(%ebp), %edx\n" /* localBoneIndex */
        "movl -0x48c(%ebp), %eax\n" /* line 290 | boneNames */
        "movzwl (%eax, %edx, 2), %edx\n"
        "movl %edx, -0x484(%ebp)\n" /* name */
        /* { scope 2: numModels, boneIndex */
        /* { scope 3 */
        "movl -0x4a4(%ebp), %eax\n" /* line 217 */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x480(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 220 */
        "jg .Lf74de0_00074fd9\n"
        ".Lf74de0_00074f1a:\n"
        "movl $0xffffffff, %ebx\n" /* model */
        ".Lf74de0_00074f1f:\n"
        "movl -0x49c(%ebp), %ecx\n" /* boneIndex */
        "addl -0x494(%ebp), %ecx\n" /* localBoneIndex */
        /* } scope */
        /* } scope */
        "cmpl %ecx, %ebx\n" /* line 292 | parentIndex */
        "je .Lf74de0_00074f8f\n"
        "movl -0x494(%ebp), %eax\n" /* line 295 | localBoneIndex */
        "testl %eax, %eax\n"
        "movl $1, %eax\n"
        "movzbl -0x485(%ebp), %edx\n" /* bRootMeld */
        "cmovel %eax, %edx\n"
        "movb %dl, -0x485(%ebp)\n" /* bRootMeld */
        "movzbl -0x475(%ebp), %eax\n" /* line 304 */
        "movl -0x46c(%ebp), %edx\n"
        "movb %al, -0x44c(%ebp, %edx)\n"
        "movl %ecx, %edx\n" /* line 305 */
        "sarl $5, %edx\n"
        "andl $0x1f, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x45c(%ebp, %edx, 4)\n"
        "leal 1(%ebx), %eax\n" /* line 308 | parentIndex */
        "movl -0x46c(%ebp), %edx\n"
        "movb %al, -0x44b(%edx, %ebp)\n"
        "addl $2, %edx\n" /* line 310 */
        "movl %edx, -0x46c(%ebp)\n"
        ".Lf74de0_00074f8f:\n"
        "addl $1, -0x494(%ebp)\n" /* line 288 | localBoneIndex */
        "addb $1, -0x475(%ebp)\n"
        "movl -0x494(%ebp), %eax\n" /* localBoneIndex */
        "cmpl %eax, -0x490(%ebp)\n" /* numBones */
        "je .Lf74de0_00075048\n"
        "movl %eax, %edx\n"
        "movl -0x48c(%ebp), %eax\n" /* line 290 | boneNames */
        "movzwl (%eax, %edx, 2), %edx\n"
        "movl %edx, -0x484(%ebp)\n" /* name */
        /* { scope 2: numModels, boneIndex */
        /* { scope 3 */
        "movl -0x4a4(%ebp), %eax\n" /* line 217 */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x480(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 220 */
        "jle .Lf74de0_00074f1a\n"
        ".Lf74de0_00074fd9:\n"
        "movl -0x4a4(%ebp), %esi\n"
        "xorl %edi, %edi\n" /* j */
        "movl $0, -0x47c(%ebp)\n" /* boneIndex */
        "movl 0x1c(%esi), %ebx\n" /* line 222 | model */
        "movl -0x484(%ebp), %edx\n" /* line 223 | name */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* model */
        "calll XModelGetBoneIndex\n"
        "testl %eax, %eax\n" /* line 224 */
        "jns .Lf74de0_0007503a\n"
        ".Lf74de0_00075004:\n"
        "movl (%ebx), %eax\n" /* line 220 | model */
        "movswl (%eax), %eax\n"
        "addl %eax, -0x47c(%ebp)\n" /* boneIndex */
        "addl $1, %edi\n" /* j */
        "addl $4, %esi\n"
        "cmpl %edi, -0x480(%ebp)\n" /* j, numModels */
        "je .Lf74de0_00074f1a\n"
        "movl 0x1c(%esi), %ebx\n" /* line 222 | model */
        "movl -0x484(%ebp), %edx\n" /* line 223 | name */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* model */
        "calll XModelGetBoneIndex\n"
        "testl %eax, %eax\n" /* line 224 */
        "js .Lf74de0_00075004\n"
        ".Lf74de0_0007503a:\n"
        "movl -0x47c(%ebp), %edx\n" /* line 225 | boneIndex */
        "leal (%eax, %edx), %ebx\n" /* model */
        "jmp .Lf74de0_00074f1f\n"
        /* } scope */
        /* } scope */
        ".Lf74de0_00075048:\n"
        "cmpb $0, -0x485(%ebp)\n" /* line 313 | bRootMeld */
        "jne .Lf74de0_000750c4\n"
        ".Lf74de0_00075051:\n"
        "movl -0x4a4(%ebp), %edx\n" /* line 314 */
        "movl 0x1c(%edx), %eax\n"
        "movl 0x88(%eax), %ebx\n" /* parentIndex */
        "movl -0x498(%ebp), %eax\n" /* model */
        "movl 0x88(%eax), %esi\n"
        "movl -0x48c(%ebp), %edx\n" /* boneNames */
        "movzwl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 0xc(%esp)\n" /* parentIndex */
        "movl %esi, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021c060, (%esp)\n" /* "WARNING: Attempting to meld model, but root part '%s' of mod" */
        "calll Com_Printf\n"
        "movl -0x498(%ebp), %edx\n" /* model */
        "jmp .Lf74de0_00074e5d\n"
        ".Lf74de0_000750a0:\n"
        "movl -0x46c(%ebp), %edi\n" /* line 324 | j */
        "testl %edi, %edi\n" /* j */
        "jne .Lf74de0_000750cf\n"
        ".Lf74de0_000750aa:\n"
        "movl g_empty, %eax\n" /* line 333 */
        "movl -0x4a4(%ebp), %edx\n"
        "movw %ax, 0x10(%edx)\n"
        /* } scope */
        "addl $0x4ac, %esp\n" /* line 337 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf74de0_000750c4:\n"
        "movl -0x498(%ebp), %edx\n" /* model */
        "jmp .Lf74de0_00074e5d\n"
        /* { scope 1: name */
        ".Lf74de0_000750cf:\n"
        "movl -0x46c(%ebp), %eax\n" /* line 326 */
        "movb $0, -0x44c(%ebp, %eax)\n"
        "leal -0x45c(%ebp), %eax\n" /* line 329 | duplicatePartBits */
        "movl $0xc, 0xc(%esp)\n"
        "movl -0x46c(%ebp), %edx\n"
        "addl $0x11, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        "movl -0x4a4(%ebp), %edx\n"
        "movw %ax, 0x10(%edx)\n"
        /* } scope */
        "addl $0x4ac, %esp\n" /* line 337 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 463 */
__attribute__((naked))
void DObjCompleteHierarchyBits(const DObj *obj, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 463 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 482 | obj */
        "movzbl 0x19(%edx), %eax\n"
        "leal -1(%eax), %ebx\n" /* boneIndex */
        "cmpw $0, 0x10(%edx)\n" /* line 487 */
        "je .Lf7511e_0007528d\n"
        "movl %edx, %ecx\n"
        ".Lf7511e_0007513e:\n"
        "movzwl 0x10(%ecx), %eax\n" /* line 492 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, -0x3c(%ebp)\n" /* duplicatePartBits */
        "addl $0x10, %eax\n" /* line 493 */
        "movl %eax, -0x44(%ebp)\n" /* duplicateParts */
        "movl $0, -0x38(%ebp)\n" /* line 497 | startIndex */
        "movl 8(%ebp), %esi\n" /* line 502 | obj */
        "movl 0x1c(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* model */
        "movswl (%eax), %edx\n" /* line 503 */
        "cmpl %edx, %ebx\n" /* line 504 | boneIndex */
        "jl .Lf7511e_00075281\n"
        "movl %esi, %ecx\n" /* line 505 */
        "movl $0, -0x4c(%ebp)\n" /* j */
        "leal -0x38(%ebp), %esi\n" /* startIndex */
        ".Lf7511e_0007517c:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 506 | j */
        "addl $4, %esi\n"
        "movl %edx, (%esi)\n" /* line 508 */
        "movl 0x20(%ecx), %eax\n" /* line 502 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* model */
        "movswl (%eax), %eax\n" /* line 503 */
        "addl %eax, %edx\n"
        "addl $4, %ecx\n"
        "cmpl %edx, %ebx\n" /* line 504 | boneIndex */
        "jge .Lf7511e_0007517c\n"
        ".Lf7511e_00075199:\n"
        "movl -0x48(%ebp), %eax\n" /* line 511 | model */
        "movl 4(%eax), %edx\n"
        "addl $4, %edx\n"
        "movl %edx, -0x40(%ebp)\n" /* parentList */
        "movl -0x4c(%ebp), %ecx\n" /* j */
        "movl -0x38(%ebp, %ecx, 4), %edi\n"
        ".Lf7511e_000751ac:\n"
        "movl %ebx, %esi\n" /* line 516 | boneIndex */
        "subl %edi, %esi\n"
        "movl %esi, -0x5c(%ebp)\n" /* localBoneIndex */
        "js .Lf7511e_00075218\n"
        ".Lf7511e_000751b5:\n"
        "movl %ebx, %eax\n" /* line 530 | boneIndex */
        "sarl $5, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "movl %ebx, %ecx\n" /* boneIndex */
        "andl $0x1f, %ecx\n"
        "movl 0xc(%ebp), %esi\n" /* partBits */
        "movl (%edx, %esi), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf7511e_0007520c\n"
        "movl -0x3c(%ebp), %esi\n" /* line 536 | duplicatePartBits */
        "movl (%esi, %edx), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf7511e_0007523f\n"
        "movl -0x48(%ebp), %edx\n" /* line 538 | model */
        "movswl 2(%edx), %eax\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 539 | localBoneIndex */
        "subl %eax, %ecx\n"
        "js .Lf7511e_00075262\n"
        "movl -0x40(%ebp), %esi\n" /* line 541 | parentList */
        "movzbl (%esi, %ecx), %eax\n"
        "movl %ebx, %ecx\n" /* boneIndex */
        "subl %eax, %ecx\n"
        ".Lf7511e_000751f7:\n"
        "movl %ecx, %edx\n" /* line 569 */
        "sarl $5, %edx\n"
        "andl $0x1f, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "movl 0xc(%ebp), %esi\n" /* partBits */
        "orl %eax, (%esi, %edx, 4)\n"
        ".Lf7511e_0007520c:\n"
        "subl $1, %ebx\n" /* line 570 | boneIndex */
        ".Lf7511e_0007520f:\n"
        "movl %ebx, %esi\n" /* line 516 | boneIndex */
        "subl %edi, %esi\n"
        "movl %esi, -0x5c(%ebp)\n" /* localBoneIndex */
        "jns .Lf7511e_000751b5\n"
        ".Lf7511e_00075218:\n"
        "subl $1, -0x4c(%ebp)\n" /* line 519 | j */
        "js .Lf7511e_00075279\n"
        "movl -0x4c(%ebp), %edi\n" /* line 525 | j */
        "movl 8(%ebp), %edx\n" /* obj */
        "movl 0x1c(%edx, %edi, 4), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* model */
        "movl 4(%eax), %ecx\n" /* line 526 */
        "addl $4, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n" /* parentList */
        "movl -0x38(%ebp, %edi, 4), %edi\n"
        "jmp .Lf7511e_000751ac\n"
        ".Lf7511e_0007523f:\n"
        "movl -0x44(%ebp), %edx\n" /* line 559 | duplicateParts */
        "movzbl (%edx), %eax\n"
        "subl $1, %eax\n"
        "cmpl %eax, %ebx\n" /* boneIndex */
        "je .Lf7511e_00075259\n"
        ".Lf7511e_0007524c:\n"
        "addl $2, %edx\n" /* line 564 */
        "movzbl (%edx), %eax\n" /* line 559 */
        "subl $1, %eax\n"
        "cmpl %eax, %ebx\n" /* boneIndex */
        "jne .Lf7511e_0007524c\n"
        ".Lf7511e_00075259:\n"
        "movzbl 1(%edx), %eax\n" /* line 561 */
        "leal -1(%eax), %ecx\n"
        "jmp .Lf7511e_000751f7\n"
        ".Lf7511e_00075262:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 545 | j */
        "movl 8(%ebp), %ecx\n" /* obj */
        "movzbl 0x3c(%edx, %ecx), %eax\n"
        "movzbl %al, %ecx\n"
        "addb $1, %al\n" /* line 546 */
        "jne .Lf7511e_000751f7\n"
        "subl $1, %ebx\n" /* line 570 | boneIndex */
        "jmp .Lf7511e_0007520f\n"
        /* } scope */
        ".Lf7511e_00075279:\n"
        "addl $0x6c, %esp\n" /* line 572 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7511e_00075281:\n"
        "movl $0, -0x4c(%ebp)\n" /* line 505 | j */
        "jmp .Lf7511e_00075199\n"
        ".Lf7511e_0007528d:\n"
        "movl %edx, %eax\n" /* line 488 */
        "calll DObjCreateDuplicateParts\n"
        "movl 8(%ebp), %ecx\n" /* obj */
        "jmp .Lf7511e_0007513e\n"
    );
}

/* line 345 */
__attribute__((naked))
void DObjGetHierarchyBits(DObj *obj, int boneIndex, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 345 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* boneIndex */
        "xorl %eax, %eax\n"
        /* { scope 1 */
        ".Lf7529c_000752aa:\n"
        "movl 0x10(%ebp), %edx\n" /* line 366 | partBits */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 365 */
        "cmpl $4, %eax\n"
        "jne .Lf7529c_000752aa\n"
        "movl 8(%ebp), %ecx\n" /* line 368 | obj */
        "movzbl 0x18(%ecx), %ebx\n" /* localBoneIndex */
        "movzbl %bl, %edi\n" /* localBoneIndex */
        "movl %edi, -0x4c(%ebp)\n" /* numModels */
        "cmpw $0, 0x10(%ecx)\n" /* line 371 */
        "je .Lf7529c_0007542f\n"
        "movl %ecx, %edx\n"
        ".Lf7529c_000752d6:\n"
        "movzwl 0x10(%edx), %eax\n" /* line 376 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, -0x40(%ebp)\n" /* duplicatePartBits */
        "addl $0x10, %eax\n" /* line 377 */
        "movl %eax, -0x48(%ebp)\n" /* duplicateParts */
        "movl $0, -0x38(%ebp)\n" /* line 381 | startIndex */
        "movl 8(%ebp), %ecx\n" /* line 386 | obj */
        "movl 0x1c(%ecx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* model */
        "movswl (%eax), %edx\n" /* line 387 */
        "cmpl %esi, %edx\n" /* line 388 | boneIndex */
        "jle .Lf7529c_000753d5\n"
        "movl $0, -0x3c(%ebp)\n"
        ".Lf7529c_0007530f:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 399 | model */
        "movl 4(%eax), %edx\n"
        "addl $4, %edx\n"
        "movl %edx, -0x44(%ebp)\n" /* parentList */
        ".Lf7529c_0007531b:\n"
        "movl %esi, %ebx\n" /* line 403 | boneIndex, localBoneIndex */
        "movl -0x3c(%ebp), %ecx\n"
        "subl -0x38(%ebp, %ecx, 4), %ebx\n" /* localBoneIndex */
        ".Lf7529c_00075324:\n"
        "movl %esi, %eax\n" /* line 408 | boneIndex */
        "sarl $5, %eax\n"
        "shll $2, %eax\n"
        "movl %esi, %ecx\n" /* boneIndex */
        "andl $0x1f, %ecx\n"
        "movl $1, %edi\n"
        "shll %cl, %edi\n"
        "movl 0x10(%ebp), %edx\n" /* partBits */
        "orl %edi, (%edx, %eax)\n"
        "movl -0x40(%ebp), %edi\n" /* line 410 | duplicatePartBits */
        "movl (%edi, %eax), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf7529c_0007539f\n"
        "movl -0x6c(%ebp), %edx\n" /* line 412 | model */
        "movswl 2(%edx), %eax\n"
        "subl %eax, %ebx\n" /* line 413 | localBoneIndex */
        "jns .Lf7529c_000753e2\n"
        "movl -0x3c(%ebp), %edi\n" /* line 419 */
        "movl 8(%ebp), %edx\n" /* obj */
        "movzbl 0x3c(%edi, %edx), %eax\n"
        "movzbl %al, %esi\n" /* boneIndex */
        "addb $1, %al\n" /* line 420 */
        "je .Lf7529c_000753da\n"
        "movl %edi, %edx\n"
        ".Lf7529c_0007536d:\n"
        "leal -0x38(%ebp, %edx, 4), %eax\n"
        "movl $0xfffffffc, %ecx\n"
        ".Lf7529c_00075376:\n"
        "subl $1, %edx\n" /* line 443 */
        "movl %esi, %ebx\n" /* line 446 | boneIndex, localBoneIndex */
        "subl (%ecx, %eax), %ebx\n" /* localBoneIndex */
        "subl $4, %eax\n"
        "testl %ebx, %ebx\n" /* line 447 | localBoneIndex */
        "js .Lf7529c_00075376\n"
        "movl 8(%ebp), %edi\n" /* line 450 | obj */
        "movl 0x1c(%edi, %edx, 4), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* model */
        "movl 4(%eax), %ecx\n" /* line 451 */
        "addl $4, %ecx\n"
        "movl %ecx, -0x44(%ebp)\n" /* parentList */
        "movl %edx, -0x3c(%ebp)\n"
        "jmp .Lf7529c_00075324\n"
        ".Lf7529c_0007539f:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 432 | duplicateParts */
        "movzbl (%ecx), %eax\n"
        "subl $1, %eax\n"
        "cmpl %eax, %esi\n" /* boneIndex */
        "je .Lf7529c_000753c7\n"
        "movl %ecx, %edx\n"
        ".Lf7529c_000753ae:\n"
        "addl $2, %edx\n" /* line 437 */
        "movzbl (%edx), %eax\n" /* line 432 */
        "subl $1, %eax\n"
        "cmpl %eax, %esi\n" /* boneIndex */
        "jne .Lf7529c_000753ae\n"
        "movzbl 1(%edx), %eax\n" /* line 434 */
        "leal -1(%eax), %esi\n" /* boneIndex */
        "movl -0x3c(%ebp), %edx\n"
        "jmp .Lf7529c_0007536d\n"
        ".Lf7529c_000753c7:\n"
        "movl %ecx, %edx\n"
        "movzbl 1(%edx), %eax\n"
        "leal -1(%eax), %esi\n" /* boneIndex */
        "movl -0x3c(%ebp), %edx\n"
        "jmp .Lf7529c_0007536d\n"
        ".Lf7529c_000753d5:\n"
        "subb $1, %bl\n" /* line 391 | localBoneIndex */
        "jne .Lf7529c_000753f0\n"
        /* } scope */
        ".Lf7529c_000753da:\n"
        "addl $0x7c, %esp\n" /* line 455 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7529c_000753e2:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 415 | parentList */
        "movzbl (%ebx, %ecx), %eax\n" /* localBoneIndex */
        "subl %eax, %esi\n" /* boneIndex */
        "jmp .Lf7529c_0007531b\n"
        ".Lf7529c_000753f0:\n"
        "movl 8(%ebp), %ecx\n" /* line 394 | obj */
        "movl $1, -0x3c(%ebp)\n"
        "leal -0x38(%ebp), %ebx\n" /* startIndex, localBoneIndex */
        ".Lf7529c_000753fd:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 396 */
        "movl %edx, (%ebx, %eax, 4)\n" /* localBoneIndex */
        "movl 0x20(%ecx), %eax\n" /* line 386 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* model */
        "movswl (%eax), %eax\n" /* line 387 */
        "addl %eax, %edx\n"
        "cmpl %edx, %esi\n" /* line 388 | boneIndex */
        "jl .Lf7529c_0007530f\n"
        "addl $1, -0x3c(%ebp)\n" /* line 390 */
        "addl $4, %ecx\n"
        "movl -0x4c(%ebp), %edi\n" /* line 391 | numModels */
        "cmpl %edi, -0x3c(%ebp)\n"
        "jne .Lf7529c_000753fd\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 455 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7529c_0007542f:\n"
        "movl %ecx, %eax\n" /* line 372 */
        "calll DObjCreateDuplicateParts\n"
        "movl 8(%ebp), %edx\n" /* obj */
        "jmp .Lf7529c_000752d6\n"
    );
}

/* line 2261 */
__attribute__((naked))
void DObjSetLocalTagInternal(const DObj *obj, const vec_t *trans, const vec_t *angles, int boneIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2261 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* trans */
        "movl 0x10(%ebp), %esi\n" /* angles */
        "movl 0x14(%ebp), %edx\n" /* boneIndex */
        /* { scope 1: radians, radians, radians */
        "movl 8(%ebp), %eax\n" /* line 1341 | obj */
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf7543e_000755c0\n"
        "addl $0x30, %eax\n" /* line 2270 */
        "je .Lf7543e_000755c0\n"
        "shll $5, %edx\n" /* line 2273 */
        "leal (%edx, %eax), %ebx\n" /* rotTrans */
        "testl %esi, %esi\n" /* line 2275 | angles */
        "je .Lf7543e_000755c8\n"
        "cvtss2sd 4(%esi), %xmm0\n" /* line 2277 | angles */
        "mulsd lit8_00307c68, %xmm0\n" /* 0.008726646259971648 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x28(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x2c(%ebp)\n"
        /* } scope */
        "cvtss2sd (%esi), %xmm0\n" /* line 2278 | angles */
        "mulsd lit8_00307c68, %xmm0\n" /* 0.008726646259971648 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x30(%ebp)\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x34(%ebp)\n"
        /* } scope */
        "cvtss2sd 8(%esi), %xmm0\n" /* line 2279 | angles */
        "mulsd lit8_00307c68, %xmm0\n" /* 0.008726646259971648 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm4\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "movss %xmm4, -0x48(%ebp)\n"
        "calll cosf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm3\n"
        /* } scope */
        "movss -0x30(%ebp), %xmm2\n" /* line 2281 */
        "xorps CorrectSolidDeltas+640, %xmm2\n"
        "mulss -0x28(%ebp), %xmm2\n"
        "movss -0x30(%ebp), %xmm7\n" /* line 2282 */
        "mulss -0x2c(%ebp), %xmm7\n"
        "movss -0x28(%ebp), %xmm5\n" /* line 2283 */
        "mulss -0x34(%ebp), %xmm5\n"
        "movss -0x2c(%ebp), %xmm6\n" /* line 2284 */
        "mulss -0x34(%ebp), %xmm6\n"
        "movss -0x48(%ebp), %xmm4\n" /* line 2286 */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* rotTrans */
        "movaps %xmm3, %xmm0\n" /* line 2287 */
        "mulss %xmm7, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* rotTrans */
        "mulss %xmm4, %xmm7\n" /* line 2288 */
        "mulss %xmm3, %xmm5\n"
        "subss %xmm7, %xmm5\n"
        "movss %xmm5, 8(%ebx)\n" /* rotTrans */
        "mulss %xmm3, %xmm6\n" /* line 2289 */
        "mulss %xmm4, %xmm2\n"
        "subss %xmm2, %xmm6\n"
        "movss %xmm6, 0xc(%ebx)\n" /* rotTrans */
        ".Lf7543e_000755a5:\n"
        "movl $0, 0x1c(%ebx)\n" /* line 2296 | rotTrans */
        "leal 0x10(%ebx), %edx\n" /* line 2297 | rotTrans, to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 */
        "movl %eax, 0x10(%ebx)\n"
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        /* } scope */
        ".Lf7543e_000755c0:\n"
        "addl $0x5c, %esp\n" /* line 2298 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: radians, radians, radians */
        ".Lf7543e_000755c8:\n"
        "xorl %eax, %eax\n" /* line 447 */
        "movl %eax, (%ebx)\n"
        "movl %eax, 4(%ebx)\n" /* line 448 */
        "movl %eax, 8(%ebx)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%ebx)\n" /* line 450 */
        "jmp .Lf7543e_000755a5\n"
    );
}

/* line 2327 */
__attribute__((naked))
qboolean DObjSetLocalTag(const DObj *obj, int *partBits, unsigned int tagName, const vec_t *trans, const vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2327 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1: numModels, boneIndex */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 217 | obj */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 220 */
        "jg .Lf755de_000755ff\n"
        /* } scope */
        ".Lf755de_000755f5:\n"
        "xorl %eax, %eax\n" /* line 2337 */
        /* } scope */
        ".Lf755de_000755f7:\n"
        "addl $0x2c, %esp\n" /* line 2338 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numModels, boneIndex */
        /* { scope 2 */
        ".Lf755de_000755ff:\n"
        "movl 8(%ebp), %esi\n" /* line 220 | obj */
        "xorl %edi, %edi\n" /* j */
        "movl $0, -0x1c(%ebp)\n" /* boneIndex */
        ".Lf755de_0007560b:\n"
        "movl 0x1c(%esi), %ebx\n" /* line 222 | model */
        "movl 0x10(%ebp), %ecx\n" /* line 223 | tagName */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* model */
        "calll XModelGetBoneIndex\n"
        "testl %eax, %eax\n" /* line 224 */
        "jns .Lf755de_00075636\n"
        "movl (%ebx), %eax\n" /* line 220 | model */
        "movswl (%eax), %eax\n"
        "addl %eax, -0x1c(%ebp)\n" /* boneIndex */
        "addl $1, %edi\n" /* j */
        "addl $4, %esi\n"
        "cmpl %edi, -0x20(%ebp)\n" /* j, numModels */
        "jne .Lf755de_0007560b\n"
        "jmp .Lf755de_000755f5\n"
        /* } scope */
        ".Lf755de_00075636:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 2332 | boneIndex */
        "addl %eax, %esi\n" /* boneIndex */
        "js .Lf755de_000755f5\n"
        /* { scope 2 */
        "movl %esi, %edx\n" /* line 1428 */
        "sarl $5, %edx\n"
        "movl %esi, %ecx\n" /* line 1429 */
        "andl $0x1f, %ecx\n"
        "movl $1, %ebx\n" /* boneIndexLow */
        "shll %cl, %ebx\n" /* boneIndexLow */
        "movl 0xc(%ebp), %eax\n" /* line 1431 | partBits */
        "testl %ebx, (%eax, %edx, 4)\n" /* boneIndexLow */
        "je .Lf755de_000755f5\n"
        "movl 8(%ebp), %ecx\n" /* line 1434 | obj */
        "movl 4(%ecx), %eax\n"
        "testl %ebx, 0x20(%eax, %edx, 4)\n" /* line 1435 | boneIndexLow */
        "jne .Lf755de_000755f5\n"
        "orl %ebx, (%eax, %edx, 4)\n" /* line 1438 | boneIndexLow */
        /* } scope */
        "movl %esi, 0xc(%esp)\n" /* line 2336 | boneIndex */
        "movl 0x18(%ebp), %eax\n" /* angles */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* trans */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjSetLocalTagInternal\n"
        "movl $1, %eax\n"
        "jmp .Lf755de_000755f7\n"
    );
}

/* line 2307 */
__attribute__((naked))
qboolean DObjSetControlTagAngles(const DObj *obj, int *partBits, unsigned int tagName, vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2307 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1: numModels, boneIndex */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 217 | obj */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 220 */
        "jg .Lf7568c_000756ad\n"
        /* } scope */
        ".Lf7568c_000756a3:\n"
        "xorl %eax, %eax\n" /* line 2317 */
        /* } scope */
        ".Lf7568c_000756a5:\n"
        "addl $0x2c, %esp\n" /* line 2318 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: numModels, boneIndex */
        /* { scope 2 */
        ".Lf7568c_000756ad:\n"
        "movl 8(%ebp), %esi\n" /* line 220 | obj */
        "xorl %edi, %edi\n" /* j */
        "movl $0, -0x1c(%ebp)\n" /* boneIndex */
        ".Lf7568c_000756b9:\n"
        "movl 0x1c(%esi), %ebx\n" /* line 222 | model */
        "movl 0x10(%ebp), %ecx\n" /* line 223 | tagName */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* model */
        "calll XModelGetBoneIndex\n"
        "testl %eax, %eax\n" /* line 224 */
        "jns .Lf7568c_000756e4\n"
        "movl (%ebx), %eax\n" /* line 220 | model */
        "movswl (%eax), %eax\n"
        "addl %eax, -0x1c(%ebp)\n" /* boneIndex */
        "addl $1, %edi\n" /* j */
        "addl $4, %esi\n"
        "cmpl %edi, -0x20(%ebp)\n" /* j, numModels */
        "jne .Lf7568c_000756b9\n"
        "jmp .Lf7568c_000756a3\n"
        /* } scope */
        ".Lf7568c_000756e4:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 2312 | boneIndex */
        "addl %eax, %esi\n" /* boneIndex */
        "js .Lf7568c_000756a3\n"
        /* { scope 2 */
        "movl %esi, %edx\n" /* line 1459 */
        "sarl $5, %edx\n"
        "movl %esi, %ecx\n" /* line 1460 */
        "andl $0x1f, %ecx\n"
        "movl $1, %ebx\n" /* boneIndexLow */
        "shll %cl, %ebx\n" /* boneIndexLow */
        "movl 0xc(%ebp), %eax\n" /* line 1462 | partBits */
        "testl %ebx, (%eax, %edx, 4)\n" /* boneIndexLow */
        "je .Lf7568c_000756a3\n"
        "movl 8(%ebp), %ecx\n" /* line 1465 | obj */
        "movl 4(%ecx), %eax\n"
        "testl %ebx, 0x20(%eax, %edx, 4)\n" /* line 1466 | boneIndexLow */
        "jne .Lf7568c_000756a3\n"
        "orl %ebx, 0x10(%eax, %edx, 4)\n" /* line 1469 | boneIndexLow */
        "orl %ebx, (%eax, %edx, 4)\n" /* line 1470 | boneIndexLow */
        /* } scope */
        "movl %esi, 0xc(%esp)\n" /* line 2316 | boneIndex */
        "movl 0x14(%ebp), %eax\n" /* angles */
        "movl %eax, 8(%esp)\n"
        "movl imp_vec3_origin, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll DObjSetLocalTagInternal\n"
        "movl $1, %eax\n"
        "jmp .Lf7568c_000756a5\n"
    );
}

/* line 63 */
__attribute__((naked))
void DObjDumpInfo(const DObj *obj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 63 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %eax\n" /* obj */
        "movl %eax, -0x48(%ebp)\n" /* obj */
        /* { scope 1: numModels, numModels, index, numModels */
        "testl %eax, %eax\n" /* line 73 */
        "je .Lf7573e_00075a5d\n"
        "movl $str_0021c0e4, (%esp)\n" /* line 79 */
        "calll Com_Printf\n"
        "movl -0x48(%ebp), %edx\n" /* line 80 | obj */
        "movzbl 0x18(%edx), %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* numModels */
        "testl %edx, %edx\n" /* line 83 */
        "jg .Lf7573e_00075a19\n"
        ".Lf7573e_00075773:\n"
        "movl $str_0021c0fc, (%esp)\n" /* line 89 */
        "calll Com_Printf\n"
        "movl -0x48(%ebp), %edx\n" /* line 90 | obj */
        "movzbl 0x19(%edx), %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* numBones */
        "testl %edx, %edx\n" /* line 91 */
        "jle .Lf7573e_00075824\n"
        "movl $0, -0x40(%ebp)\n" /* i */
        /* { scope 2 */
        ".Lf7573e_00075798:\n"
        "movl -0x48(%ebp), %eax\n" /* line 1670 | obj */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 1673 */
        "jle .Lf7573e_000759fa\n"
        "movl -0x48(%ebp), %edx\n" /* line 1676 | obj */
        "movl 0x1c(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1678 */
        "movl (%eax), %eax\n"
        "movswl (%edx), %ecx\n" /* line 1679 */
        "cmpl %ecx, -0x40(%ebp)\n" /* line 1682 | i */
        "jl .Lf7573e_00075a01\n"
        "movl -0x48(%ebp), %ebx\n" /* obj, model */
        "xorl %edi, %edi\n" /* baseBoneIndex */
        "xorl %esi, %esi\n" /* j */
        ".Lf7573e_000757ca:\n"
        "addl %ecx, %edi\n" /* line 1673 | baseBoneIndex */
        "addl $1, %esi\n" /* j */
        "cmpl %esi, -0x30(%ebp)\n" /* j, numModels */
        "je .Lf7573e_000759fa\n"
        "movl 0x20(%ebx), %eax\n" /* line 1676 | model */
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1678 */
        "movl (%eax), %eax\n"
        "movswl (%edx), %ecx\n" /* line 1679 */
        "movl -0x40(%ebp), %edx\n" /* line 1680 | i */
        "subl %edi, %edx\n" /* baseBoneIndex */
        "addl $4, %ebx\n" /* model */
        "cmpl %ecx, %edx\n" /* line 1682 */
        "jge .Lf7573e_000757ca\n"
        ".Lf7573e_000757f1:\n"
        "movzwl (%eax, %edx, 2), %eax\n" /* line 1683 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        /* } scope */
        ".Lf7573e_000757fd:\n"
        "movl %eax, 8(%esp)\n" /* line 92 */
        "movl -0x40(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021c108, (%esp)\n" /* "Bone %d: '%s'
" */
        "calll Com_Printf\n"
        "addl $1, -0x40(%ebp)\n" /* line 91 | i */
        "movl -0x40(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x3c(%ebp)\n" /* numBones */
        "jne .Lf7573e_00075798\n"
        ".Lf7573e_00075824:\n"
        "movl -0x48(%ebp), %eax\n" /* line 94 | obj */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf7573e_000759db\n"
        "movl $str_0021c118, (%esp)\n" /* line 96 */
        "calll Com_Printf\n"
        "movl -0x48(%ebp), %edx\n" /* line 97 | obj */
        "movzwl 0x10(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "leal 0x10(%eax), %edx\n"
        "cmpb $0, 0x10(%eax)\n" /* line 101 */
        "je .Lf7573e_000759e7\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movzbl 1(%edx), %eax\n" /* line 104 */
        "subl $1, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* index */
        /* { scope 2 */
        "movl -0x48(%ebp), %eax\n" /* line 1670 | obj */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 1673 */
        "jle .Lf7573e_000759a5\n"
        ".Lf7573e_00075879:\n"
        "movl -0x48(%ebp), %edx\n" /* line 1676 | obj */
        "movl 0x1c(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1678 */
        "movl (%eax), %eax\n"
        "movswl (%edx), %ecx\n" /* line 1679 */
        "cmpl %ecx, -0x24(%ebp)\n" /* line 1682 | index */
        "jl .Lf7573e_00075a09\n"
        "movl -0x48(%ebp), %ebx\n" /* obj, model */
        "xorl %edi, %edi\n" /* baseBoneIndex */
        "xorl %esi, %esi\n" /* j */
        ".Lf7573e_00075899:\n"
        "addl %ecx, %edi\n" /* line 1673 | baseBoneIndex */
        "addl $1, %esi\n" /* j */
        "cmpl %esi, -0x28(%ebp)\n" /* j, numModels */
        "je .Lf7573e_000759a5\n"
        "movl 0x20(%ebx), %eax\n" /* line 1676 | model */
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1678 */
        "movl (%eax), %eax\n"
        "movswl (%edx), %ecx\n" /* line 1679 */
        "movl -0x24(%ebp), %edx\n" /* line 1680 | index */
        "subl %edi, %edx\n" /* baseBoneIndex */
        "addl $4, %ebx\n" /* model */
        "cmpl %ecx, %edx\n" /* line 1682 */
        "jge .Lf7573e_00075899\n"
        ".Lf7573e_000758c0:\n"
        "movzwl (%eax, %edx, 2), %eax\n" /* line 1683 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, -0x2c(%ebp)\n"
        /* } scope */
        "movl -0x4c(%ebp), %edx\n" /* line 104 */
        "movzbl 1(%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movzbl (%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 2 */
        "movl -0x48(%ebp), %eax\n" /* line 1670 | obj */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 1673 */
        "jle .Lf7573e_000759d4\n"
        ".Lf7573e_000758f7:\n"
        "movl -0x48(%ebp), %edx\n" /* line 1676 | obj */
        "movl 0x1c(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1678 */
        "movl (%eax), %eax\n"
        "movswl (%edx), %edx\n" /* line 1679 */
        "cmpl %edx, -0x1c(%ebp)\n" /* line 1682 */
        "jl .Lf7573e_00075a11\n"
        "movl -0x48(%ebp), %ebx\n" /* obj, model */
        "xorl %edi, %edi\n" /* baseBoneIndex */
        "xorl %esi, %esi\n" /* j */
        ".Lf7573e_00075917:\n"
        "addl %edx, %edi\n" /* line 1673 | baseBoneIndex */
        "addl $1, %esi\n" /* j */
        "cmpl %esi, -0x20(%ebp)\n" /* j, numModels */
        "je .Lf7573e_000759d4\n"
        "movl 0x20(%ebx), %eax\n" /* line 1676 | model */
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1678 */
        "movl (%eax), %eax\n"
        "movswl (%edx), %edx\n" /* line 1679 */
        "movl -0x1c(%ebp), %ecx\n" /* line 1680 */
        "subl %edi, %ecx\n" /* baseBoneIndex */
        "addl $4, %ebx\n" /* model */
        "cmpl %edx, %ecx\n" /* line 1682 */
        "jge .Lf7573e_00075917\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edx\n"
        ".Lf7573e_00075943:\n"
        "movzwl (%eax, %edx, 2), %eax\n" /* line 1683 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        /* } scope */
        ".Lf7573e_0007594f:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 104 */
        "movl %edx, 0x10(%esp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x4c(%ebp), %edx\n"
        "movzbl (%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021c12c, (%esp)\n" /* "%d ('%s') -> %d ('%s')
" */
        "calll Com_Printf\n"
        "addl $2, -0x4c(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 101 */
        "cmpb $0, (%eax)\n"
        "je .Lf7573e_000759e7\n"
        "movl -0x4c(%ebp), %edx\n"
        "movzbl 1(%edx), %eax\n" /* line 104 */
        "subl $1, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* index */
        /* { scope 2 */
        "movl -0x48(%ebp), %eax\n" /* line 1670 | obj */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 1673 */
        "jg .Lf7573e_00075879\n"
        ".Lf7573e_000759a5:\n"
        "movl $0, -0x2c(%ebp)\n"
        /* } scope */
        "movl -0x4c(%ebp), %edx\n" /* line 104 */
        "movzbl 1(%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movzbl (%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 2 */
        "movl -0x48(%ebp), %eax\n" /* line 1670 | obj */
        "movzbl 0x18(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* numModels */
        "testl %eax, %eax\n" /* line 1673 */
        "jg .Lf7573e_000758f7\n"
        ".Lf7573e_000759d4:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf7573e_0007594f\n"
        /* } scope */
        ".Lf7573e_000759db:\n"
        "movl $str_0021c144, (%esp)\n" /* line 111 */
        "calll Com_Printf\n"
        ".Lf7573e_000759e7:\n"
        "movl $str_002160e8, 8(%ebp)\n" /* line 114 | obj */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 115 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: numModels, numModels, index, numModels */
        "jmp Com_Printf\n" /* line 114 */
        /* { scope 2 */
        ".Lf7573e_000759fa:\n"
        "xorl %eax, %eax\n" /* line 1673 */
        "jmp .Lf7573e_000757fd\n"
        ".Lf7573e_00075a01:\n"
        "movl -0x40(%ebp), %edx\n" /* line 1682 | i */
        "jmp .Lf7573e_000757f1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf7573e_00075a09:\n"
        "movl -0x24(%ebp), %edx\n" /* index */
        "jmp .Lf7573e_000758c0\n"
        ".Lf7573e_00075a11:\n"
        "movl -0x1c(%ebp), %edx\n"
        "jmp .Lf7573e_00075943\n"
        /* } scope */
        ".Lf7573e_00075a19:\n"
        "movl -0x48(%ebp), %esi\n" /* line 83 | obj */
        "movl $0, -0x34(%ebp)\n" /* boneIndex */
        "xorl %edi, %edi\n" /* j */
        ".Lf7573e_00075a25:\n"
        "movl 0x1c(%esi), %ebx\n" /* line 85 | model */
        "movl 0x88(%ebx), %eax\n" /* line 86 | model */
        "movl %eax, 8(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* boneIndex */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021c0f0, (%esp)\n" /* "%d: '%s'
" */
        "calll Com_Printf\n"
        "movl (%ebx), %eax\n" /* line 83 | model */
        "movswl (%eax), %eax\n"
        "addl %eax, -0x34(%ebp)\n" /* boneIndex */
        "addl $1, %edi\n" /* j */
        "addl $4, %esi\n"
        "cmpl %edi, -0x38(%ebp)\n" /* j, numModels */
        "jne .Lf7573e_00075a25\n"
        "jmp .Lf7573e_00075773\n"
        ".Lf7573e_00075a5d:\n"
        "movl $str_0021c0d8, 8(%ebp)\n" /* line 75 | obj */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 115 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: numModels, numModels, index, numModels */
        "jmp Com_Printf\n" /* line 114 */
    );
}

/* line 1005 */
__attribute__((naked))
void DObjCreate(void * (*dobjModels)(), unsigned int numModels, XAnimTree_s *tree, char *buf, unsigned int entnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1005 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* tree */
        /* { scope 1: modelMin, modelMax */
        "movl 0x14(%ebp), %eax\n" /* line 1032 | buf */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n" /* line 1033 */
        "movw $0, 0x10(%eax)\n" /* line 1034 */
        "movb $0, 0x1a(%eax)\n" /* line 1035 */
        /* { scope 2 */
        "movl %esi, (%eax)\n" /* line 942 */
        "testl %esi, %esi\n" /* line 944 */
        "je .Lf75a70_00075d06\n"
        "movl (%esi), %eax\n" /* line 951 */
        "movl 4(%eax), %ecx\n"
        "leal (%ecx, %ecx), %edx\n" /* line 954 */
        "leal 8(%edx, %esi), %eax\n"
        "movl 0x14(%ebp), %ebx\n" /* buf, pAge */
        "movl %eax, 0xc(%ebx)\n" /* pAge */
        "leal (%eax, %edx), %ebx\n" /* line 956 | pAge */
        "movzbl (%ebx), %eax\n" /* line 959 | pAge */
        "addb $1, %al\n"
        "je .Lf75a70_00075ce5\n"
        ".Lf75a70_00075ac4:\n"
        "movb %al, (%ebx)\n" /* line 965 | pAge */
        /* } scope */
        "movl 0x18(%ebp), %eax\n" /* line 1040 | entnum */
        "movw %ax, 4(%esi)\n" /* tree */
        ".Lf75a70_00075acd:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1047 | numModels */
        "testl %eax, %eax\n"
        "jne .Lf75a70_00075b3c\n"
        "xorl %eax, %eax\n"
        "movb $0, -0x45(%ebp)\n"
        ".Lf75a70_00075ada:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1104 | buf */
        "movb %al, 0x18(%edx)\n"
        "movzbl -0x45(%ebp), %ecx\n" /* line 1106 */
        "movb %cl, 0x19(%edx)\n"
        /* { scope 2 */
        "movzbl %al, %edi\n" /* line 979 | numModels */
        "testl %edi, %edi\n" /* line 984 | numModels */
        "jg .Lf75a70_00075c1a\n"
        "pxor %xmm0, %xmm0\n"
        "movaps %xmm0, %xmm5\n"
        "movaps %xmm0, %xmm3\n"
        "movaps %xmm0, %xmm1\n"
        "movaps %xmm0, %xmm4\n"
        "movaps %xmm0, %xmm2\n"
        ".Lf75a70_00075b05:\n"
        "movl 0x14(%ebp), %eax\n" /* line 994 | buf, to */
        "addl $0x4c, %eax\n" /* to */
        /* { scope 3 */
        "movl 0x14(%ebp), %ebx\n" /* line 199 | buf */
        "movss %xmm3, 0x4c(%ebx)\n"
        "movss %xmm5, 4(%eax)\n" /* line 200 */
        "movss %xmm0, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 995 | pAge, to */
        "addl $0x58, %eax\n" /* to */
        /* { scope 3 */
        "movss %xmm2, 0x58(%ebx)\n" /* line 199 */
        "movss %xmm4, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0xcc, %esp\n" /* line 1113 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: modelMin, modelMax */
        ".Lf75a70_00075b3c:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1047 | buf */
        "movl %edx, -0x40(%ebp)\n"
        "movl %edx, %esi\n" /* tree */
        "movl 8(%ebp), %edi\n" /* dobjModels, numModels */
        "movl $0, -0x4c(%ebp)\n" /* newNumModels */
        "movl $0, -0x58(%ebp)\n" /* boneIndex */
        "movl %edx, %ecx\n"
        "jmp .Lf75a70_00075b91\n"
        ".Lf75a70_00075b59:\n"
        "testl %ebx, %ebx\n" /* line 1089 | model */
        "je .Lf75a70_00075b74\n"
        "movl (%ebx), %eax\n" /* line 1091 | model */
        "movswl (%eax), %eax\n"
        "addl -0x58(%ebp), %eax\n" /* boneIndex */
        "cmpl $0x7f, %eax\n" /* line 1092 */
        "jg .Lf75a70_00075d12\n"
        "movb %al, -0x45(%ebp)\n"
        "movl %eax, -0x58(%ebp)\n" /* boneIndex */
        ".Lf75a70_00075b74:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 1100 | newNumModels */
        "addl $0xc, %edi\n" /* line 1047 | numModels */
        "addl $4, -0x40(%ebp)\n"
        "addl $1, %esi\n" /* tree */
        "movl -0x4c(%ebp), %ebx\n" /* newNumModels, model */
        "cmpl %ebx, 0xc(%ebp)\n" /* model, numModels */
        "je .Lf75a70_00075cde\n"
        "movl -0x40(%ebp), %ecx\n"
        ".Lf75a70_00075b91:\n"
        "movl (%edi), %ebx\n" /* line 1049 | numModels, model */
        "movl %ebx, 0x1c(%ecx)\n" /* line 1050 | model */
        "leal 0x3c(%esi), %eax\n" /* line 1005 | tree */
        "movl %eax, -0x3c(%ebp)\n"
        "movb $0xff, 0x3c(%esi)\n" /* line 1051 | tree */
        "movzbl -0x58(%ebp), %edx\n" /* line 1052 | boneIndex */
        "movb %dl, -0x45(%ebp)\n"
        "movb %dl, 0x44(%esi)\n" /* tree */
        "movl 8(%edi), %eax\n" /* line 1053 | numModels */
        "testl %eax, %eax\n"
        "je .Lf75a70_00075bc2\n"
        "movl $1, %eax\n" /* line 1054 */
        "movzbl -0x4c(%ebp), %ecx\n" /* newNumModels */
        "shll %cl, %eax\n"
        "movl 0x14(%ebp), %edx\n" /* buf */
        "orb %al, 0x1a(%edx)\n"
        ".Lf75a70_00075bc2:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1056 | newNumModels */
        "testl %eax, %eax\n"
        "je .Lf75a70_00075b59\n"
        "movl 4(%edi), %ecx\n" /* line 1067 | numModels */
        "movl %ecx, -0x54(%ebp)\n" /* boneName */
        "testl %ecx, %ecx\n" /* line 1068 */
        "je .Lf75a70_00075b59\n"
        "cmpb $0, (%ecx)\n"
        "je .Lf75a70_00075b59\n"
        "movl %ecx, (%esp)\n" /* line 1071 */
        "calll SL_FindString\n"
        "movl %eax, -0x50(%ebp)\n" /* name */
        "testl %eax, %eax\n" /* line 1072 */
        "je .Lf75a70_00075bf2\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1074 | newNumModels */
        "testl %eax, %eax\n"
        "jg .Lf75a70_00075d47\n"
        ".Lf75a70_00075bf2:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1085 | buf */
        "movl 0x1c(%edx), %eax\n"
        "movl 0x88(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x54(%ebp), %ecx\n" /* boneName */
        "movl %ecx, 4(%esp)\n"
        "movl $str_0021c15c, (%esp)\n" /* "WARNING: Part '%s' not found in model '%s' or any of its des" */
        "calll Com_Printf\n"
        "jmp .Lf75a70_00075b59\n"
        /* { scope 2 */
        ".Lf75a70_00075c1a:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 984 | buf, pAge */
        "xorl %esi, %esi\n" /* modelIndex */
        "pxor %xmm0, %xmm0\n"
        "movaps %xmm0, %xmm5\n"
        "movaps %xmm0, %xmm3\n"
        "movaps %xmm0, %xmm1\n"
        "movaps %xmm0, %xmm4\n"
        "movaps %xmm0, %xmm2\n"
        ".Lf75a70_00075c32:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 986 | pAge */
        "testl %eax, %eax\n"
        "je .Lf75a70_00075ccb\n"
        "leal -0x30(%ebp), %edx\n" /* line 988 | modelMax */
        "movl %edx, 8(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* modelMin */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x78(%ebp)\n"
        "movss %xmm1, -0x88(%ebp)\n"
        "movss %xmm2, -0x98(%ebp)\n"
        "movss %xmm3, -0xa8(%ebp)\n"
        "movss %xmm4, -0xb8(%ebp)\n"
        "movss %xmm5, -0xc8(%ebp)\n"
        "calll XModelGetBounds\n"
        "movss -0xa8(%ebp), %xmm3\n" /* line 240 */
        "addss -0x24(%ebp), %xmm3\n" /* modelMin */
        "movss -0xc8(%ebp), %xmm5\n" /* line 241 */
        "addss -0x20(%ebp), %xmm5\n"
        "movss -0x78(%ebp), %xmm0\n" /* line 242 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss -0x98(%ebp), %xmm2\n" /* line 240 */
        "addss -0x30(%ebp), %xmm2\n" /* modelMax */
        "movss -0xb8(%ebp), %xmm4\n" /* line 241 */
        "addss -0x2c(%ebp), %xmm4\n"
        "movss -0x88(%ebp), %xmm1\n" /* line 242 */
        "addss -0x28(%ebp), %xmm1\n"
        ".Lf75a70_00075ccb:\n"
        "addl $1, %esi\n" /* line 984 | modelIndex */
        "addl $4, %ebx\n" /* pAge */
        "cmpl %esi, %edi\n" /* modelIndex, numModels */
        "jne .Lf75a70_00075c32\n"
        "jmp .Lf75a70_00075b05\n"
        /* } scope */
        ".Lf75a70_00075cde:\n"
        "movl %ebx, %eax\n" /* line 1047 | model */
        "jmp .Lf75a70_00075ada\n"
        /* { scope 2 */
        ".Lf75a70_00075ce5:\n"
        "leal 1(%ebx), %eax\n" /* line 962 | pAge */
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $1, %eax\n"
        "jmp .Lf75a70_00075ac4\n"
        ".Lf75a70_00075d06:\n"
        "movl $0, 0xc(%eax)\n" /* line 946 */
        "jmp .Lf75a70_00075acd\n"
        /* } scope */
        ".Lf75a70_00075d12:\n"
        "movl $0x7f, 0xc(%esp)\n" /* line 1094 */
        "movl 0x14(%ebp), %ecx\n" /* buf */
        "movl 0x1c(%ecx), %eax\n"
        "movl 0x88(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021c1a4, 4(%esp)\n" /* "dobj for xmodel '%s' has more than %d bones" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movzbl -0x4c(%ebp), %eax\n" /* newNumModels */
        "jmp .Lf75a70_00075ada\n"
        ".Lf75a70_00075d47:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1074 | buf */
        "movl %eax, -0x44(%ebp)\n"
        "movl $0, -0x5c(%ebp)\n" /* k */
        "movl %eax, %ecx\n"
        "jmp .Lf75a70_00075d6f\n"
        ".Lf75a70_00075d58:\n"
        "addl $1, -0x5c(%ebp)\n" /* k */
        "addl $4, -0x44(%ebp)\n"
        "movl -0x5c(%ebp), %eax\n" /* k */
        "cmpl %eax, -0x4c(%ebp)\n" /* newNumModels */
        "je .Lf75a70_00075bf2\n"
        "movl -0x44(%ebp), %ecx\n"
        ".Lf75a70_00075d6f:\n"
        "movl -0x50(%ebp), %edx\n" /* line 1076 | name */
        "movl %edx, 4(%esp)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XModelGetBoneIndex\n"
        "testl %eax, %eax\n" /* line 1077 */
        "js .Lf75a70_00075d58\n"
        "movl -0x5c(%ebp), %edx\n" /* line 1079 | k */
        "movl 0x14(%ebp), %ecx\n" /* buf */
        "addb 0x44(%edx, %ecx), %al\n"
        "movl -0x3c(%ebp), %edx\n"
        "movb %al, (%edx)\n"
        "jmp .Lf75a70_00075b59\n"
    );
}

/* line 625 */
__attribute__((naked))
void DObjCalcSkel(const DObj *obj, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 625 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        /* { scope 1: xx, yy, yz */
        "movl 8(%ebp), %eax\n" /* line 656 | obj */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* skel */
        "movl %eax, %edx\n"
        "movl $1, %ebx\n" /* bFinished */
        "movl $1, %ecx\n"
        ".Lf75d9a_00075dbb:\n"
        "movl 0xc(%ebp), %esi\n" /* line 663 | partBits */
        "movl -4(%esi, %ecx, 4), %eax\n"
        "notl %eax\n"
        "orl 0x20(%edx), %eax\n"
        "movl %eax, -0x3c(%ebp, %ecx, 4)\n"
        "addl $1, %eax\n" /* line 664 */
        "movl $0, %eax\n"
        "cmovnel %eax, %ebx\n" /* bFinished */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $5, %ecx\n" /* line 661 */
        "jne .Lf75d9a_00075dbb\n"
        "testb %bl, %bl\n" /* line 668 | bFinished */
        "jne .Lf75d9a_0007647d\n"
        "movl 8(%ebp), %eax\n" /* line 674 | obj */
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf75d9a_00076488\n"
        "movl %eax, %edx\n"
        ".Lf75d9a_00075df9:\n"
        "movzwl 0x10(%edx), %eax\n" /* line 679 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, -0x7c(%ebp)\n" /* savedDuplicatePartBits */
        "addl $0x10, %eax\n" /* line 680 */
        "movl %eax, -0x84(%ebp)\n" /* duplicateParts */
        "movl -0x80(%ebp), %ebx\n" /* skel, bFinished */
        "movl $1, %esi\n"
        "leal -0x28(%ebp), %edi\n" /* controlPartBits, childMat */
        ".Lf75d9a_00075e1c:\n"
        "movl 0x20(%ebx), %eax\n" /* line 684 | bFinished */
        "movl 0xc(%ebp), %ecx\n" /* partBits */
        "orl -4(%ecx, %esi, 4), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* bFinished */
        "leal (, %esi, 4), %ecx\n" /* line 685 */
        "movl -0x3c(%ebp, %ecx), %edx\n"
        "movl %edx, %eax\n"
        "notl %eax\n"
        "andl 0x10(%ebx), %eax\n" /* bFinished */
        "movl %eax, -4(%edi, %ecx)\n" /* childMat */
        "orl %eax, %edx\n" /* line 686 */
        "movl -0x7c(%ebp), %eax\n" /* savedDuplicatePartBits */
        "orl -4(%eax, %esi, 4), %edx\n"
        "movl %edx, -0x4c(%ebp, %ecx)\n"
        "addl $1, %esi\n"
        "addl $4, %ebx\n" /* bFinished */
        "cmpl $5, %esi\n" /* line 682 */
        "jne .Lf75d9a_00075e1c\n"
        "movl $1, %ecx\n"
        ".Lf75d9a_00075e5c:\n"
        "leal (, %ecx, 4), %edx\n" /* line 625 */
        "movl -0x4c(%ebp, %edx), %eax\n" /* line 707 */
        "notl %eax\n"
        "orl %eax, -4(%edi, %edx)\n" /* childMat */
        "addl $1, %ecx\n"
        "cmpl $5, %ecx\n" /* line 706 */
        "jne .Lf75d9a_00075e5c\n"
        "movl 8(%ebp), %edx\n" /* line 709 | obj */
        "movzbl 0x18(%edx), %eax\n"
        "movl -0x80(%ebp), %ecx\n" /* line 711 | skel */
        "addl $0x30, %ecx\n"
        "movl %ecx, -0x90(%ebp)\n" /* sourceMat */
        "testl %eax, %eax\n" /* line 718 */
        "jle .Lf75d9a_0007647d\n"
        "movl %edx, -0x50(%ebp)\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl %ecx, %edi\n" /* childMat */
        "movl -0x84(%ebp), %esi\n" /* duplicateParts */
        "movl %esi, -0x88(%ebp)\n" /* pos */
        "movl $0, -0x4c(%ebp)\n"
        "leal (%edx, %eax), %eax\n"
        "movl %eax, -0xb4(%ebp)\n"
        "movl 0x1c(%edx), %eax\n" /* line 720 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x98(%ebp)\n" /* model */
        "movl -0x50(%ebp), %ecx\n" /* line 721 */
        "movzbl 0x3c(%ecx), %eax\n"
        "cmpb $0xff, %al\n" /* line 724 */
        "je .Lf75d9a_00076a14\n"
        ".Lf75d9a_00075ece:\n"
        "movzbl %al, %eax\n" /* line 791 */
        "shll $5, %eax\n"
        "movl -0x90(%ebp), %esi\n" /* sourceMat */
        "addl %eax, %esi\n"
        "movl -0x98(%ebp), %edx\n" /* line 793 | model */
        "movzwl 2(%edx), %eax\n"
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n"
        "je .Lf75d9a_00076d53\n"
        "movl -0x4c(%ebp), %eax\n"
        "leal (%eax, %edx), %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "jmp .Lf75d9a_00076285\n"
        ".Lf75d9a_00075f03:\n"
        "movss (%edi), %xmm0\n" /* line 171 */
        "movaps %xmm0, %xmm7\n"
        "movss 0xc(%esi), %xmm5\n"
        "movss 0xc(%edi), %xmm6\n"
        "movss %xmm6, -0xc4(%ebp)\n"
        "movss (%esi), %xmm2\n"
        "movss 8(%edi), %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n"
        "movss 4(%esi), %xmm3\n"
        "movss 4(%edi), %xmm0\n"
        "movaps %xmm0, %xmm4\n"
        "movss 8(%esi), %xmm1\n"
        "movaps %xmm5, %xmm0\n" /* line 174 */
        "mulss %xmm6, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss %xmm0, 0xc(%edi)\n"
        "movaps %xmm7, %xmm0\n" /* line 176 */
        "mulss %xmm5, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm5, %xmm0\n" /* line 177 */
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss %xmm0, 4(%edi)\n"
        "mulss -0xbc(%ebp), %xmm5\n" /* line 178 */
        "mulss %xmm4, %xmm2\n"
        "addss %xmm5, %xmm2\n"
        "mulss %xmm7, %xmm3\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm6, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0xbc(%ebp)\n"
        "movss %xmm1, 8(%edi)\n"
        /* { scope 2: xx, yy, yz, yw */
        ".Lf75d9a_000760d8:\n"
        "movss -0xc0(%ebp), %xmm3\n" /* line 567 */
        "mulss %xmm3, %xmm3\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss -0xbc(%ebp), %xmm6\n"
        "mulss %xmm6, %xmm6\n"
        "addss %xmm6, %xmm3\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "pxor %xmm6, %xmm6\n" /* line 149 */
        "ucomiss %xmm6, %xmm3\n"
        "jp .Lf75d9a_00076123\n"
        "je .Lf75d9a_00076495\n"
        ".Lf75d9a_00076123:\n"
        "movss lit4_002ed62c, %xmm0\n" /* line 151 | 2.0f */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, 0x1c(%edi)\n"
        "movl $0x3f800000, -0xb0(%ebp)\n"
        /* } scope */
        /* { scope 2: xx, yy, yz, yw */
        ".Lf75d9a_0007613e:\n"
        "movss 0x1c(%esi), %xmm2\n" /* line 306 | scale */
        /* { scope 3 */
        "movaps %xmm2, %xmm5\n" /* line 272 */
        "mulss (%esi), %xmm5\n"
        "movaps %xmm2, %xmm7\n" /* line 273 */
        "mulss 4(%esi), %xmm7\n"
        "mulss 8(%esi), %xmm2\n" /* line 274 */
        /* } scope */
        "movaps %xmm5, %xmm6\n" /* line 308 */
        "mulss (%esi), %xmm6\n"
        "movss %xmm6, -0x78(%ebp)\n" /* xx */
        "movss 4(%esi), %xmm6\n" /* line 309 */
        "movaps %xmm5, %xmm4\n"
        "mulss %xmm6, %xmm4\n"
        "movss 8(%esi), %xmm1\n" /* line 310 */
        "movaps %xmm5, %xmm3\n"
        "mulss %xmm1, %xmm3\n"
        "movss 0xc(%esi), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm5\n"
        "mulss %xmm7, %xmm6\n" /* line 313 */
        "movss %xmm6, -0x74(%ebp)\n" /* yy */
        "movaps %xmm7, %xmm6\n" /* line 314 */
        "mulss %xmm1, %xmm6\n"
        "movss %xmm6, -0x70(%ebp)\n" /* yz */
        "mulss %xmm0, %xmm7\n" /* line 315 */
        "movaps %xmm2, %xmm6\n" /* line 317 */
        "mulss %xmm1, %xmm6\n"
        "mulss %xmm0, %xmm2\n" /* line 318 */
        /* } scope */
        "movss -0x74(%ebp), %xmm0\n" /* line 140 | yy */
        "addss %xmm6, %xmm0\n"
        "movss -0xb0(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss 0x10(%edi), %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss 0x14(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "addss %xmm7, %xmm0\n"
        "mulss 0x18(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x10(%esi), %xmm1\n"
        "addss %xmm2, %xmm4\n" /* line 141 */
        "mulss 0x10(%edi), %xmm4\n"
        "addss -0x78(%ebp), %xmm6\n" /* xx */
        "movss -0xb0(%ebp), %xmm0\n"
        "subss %xmm6, %xmm0\n"
        "mulss 0x14(%edi), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss -0x70(%ebp), %xmm0\n" /* yz */
        "subss %xmm5, %xmm0\n"
        "mulss 0x18(%edi), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "addss 0x14(%esi), %xmm4\n"
        "subss %xmm7, %xmm3\n" /* line 142 */
        "mulss 0x10(%edi), %xmm3\n"
        "addss -0x70(%ebp), %xmm5\n" /* yz */
        "mulss 0x14(%edi), %xmm5\n"
        "addss %xmm5, %xmm3\n"
        "movss -0x78(%ebp), %xmm0\n" /* xx */
        "addss -0x74(%ebp), %xmm0\n" /* yy */
        "movss -0xb0(%ebp), %xmm6\n"
        "subss %xmm0, %xmm6\n"
        "movss %xmm6, -0xb0(%ebp)\n"
        "mulss 0x18(%edi), %xmm6\n"
        "addss %xmm6, %xmm3\n"
        "addss 0x18(%esi), %xmm3\n"
        "movss %xmm3, 0x18(%edi)\n"
        "movss %xmm1, 0x10(%edi)\n" /* line 143 */
        "movss %xmm4, 0x14(%edi)\n" /* line 144 */
        ".Lf75d9a_00076273:\n"
        "addl $0x20, %edi\n" /* line 793 | childMat */
        "addl $1, %eax\n"
        "cmpl %eax, -0xac(%ebp)\n"
        "je .Lf75d9a_000764b8\n"
        ".Lf75d9a_00076285:\n"
        "movl %eax, %ebx\n" /* line 795 | bFinished */
        "sarl $5, %ebx\n" /* bFinished */
        "movl %eax, %ecx\n" /* line 796 */
        "andl $0x1f, %ecx\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "testl %edx, -0x28(%ebp, %ebx, 4)\n" /* line 802 */
        "je .Lf75d9a_00076273\n"
        "testl %edx, -0x48(%ebp, %ebx, 4)\n" /* line 810 */
        "je .Lf75d9a_00075f03\n"
        "movss (%esi), %xmm3\n" /* line 191 */
        "movss 0xc(%edi), %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movss 0xc(%esi), %xmm7\n"
        "movss (%edi), %xmm6\n"
        "movss %xmm6, -0xc0(%ebp)\n"
        "movss 8(%esi), %xmm4\n"
        "movss 4(%edi), %xmm0\n"
        "movaps %xmm0, %xmm5\n"
        "movss 4(%esi), %xmm2\n"
        "movss 8(%edi), %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 194 */
        "mulss %xmm7, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm5, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss %xmm0, 0xc(%edi)\n"
        "movaps %xmm3, %xmm0\n" /* line 196 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 197 */
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss %xmm0, 4(%edi)\n"
        "mulss %xmm4, %xmm1\n" /* line 198 */
        "mulss %xmm6, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss %xmm5, %xmm3\n"
        "subss %xmm3, %xmm1\n"
        "mulss -0xbc(%ebp), %xmm7\n"
        "addss %xmm7, %xmm1\n"
        "movss %xmm1, -0xbc(%ebp)\n"
        "movss %xmm1, 8(%edi)\n"
        "jmp .Lf75d9a_000760d8\n"
        /* } scope */
        ".Lf75d9a_0007647d:\n"
        "addl $0xdc, %esp\n" /* line 932 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xx, yy, yz */
        ".Lf75d9a_00076488:\n"
        "calll DObjCreateDuplicateParts\n" /* line 675 */
        "movl 8(%ebp), %edx\n" /* obj */
        "jmp .Lf75d9a_00075df9\n"
        /* { scope 2: xx, yy, yz, yw */
        ".Lf75d9a_00076495:\n"
        "movl $0x3f800000, -0xb0(%ebp)\n" /* line 155 */
        "movss -0xb0(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%edi)\n"
        "movl $0x40000000, 0x1c(%edi)\n" /* line 156 */
        "jmp .Lf75d9a_0007613e\n"
        /* } scope */
        ".Lf75d9a_000764b8:\n"
        "movl -0xac(%ebp), %eax\n" /* line 793 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0x98(%ebp), %edx\n" /* model */
        "movl -0x98(%ebp), %ecx\n" /* model */
        ".Lf75d9a_000764cd:\n"
        "movl 0xc(%edx), %edx\n" /* line 838 */
        "movl %edx, -0x8c(%ebp)\n" /* trans */
        "movl 4(%ecx), %esi\n" /* line 840 */
        "addl $4, %esi\n"
        "movl %esi, -0x94(%ebp)\n" /* parentList */
        "movswl (%ecx), %edx\n" /* line 843 */
        "movswl 2(%ecx), %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x9c(%ebp)\n" /* i */
        "je .Lf75d9a_000769e0\n"
        "movl $0, -0x58(%ebp)\n"
        "leal 0x10(%edi), %esi\n" /* childMat */
        "jmp .Lf75d9a_00076939\n"
        ".Lf75d9a_00076506:\n"
        "testl %ebx, -0x48(%ebp, %edx, 4)\n" /* line 858 | bFinished */
        "jne .Lf75d9a_00076b43\n"
        "movl -0x94(%ebp), %edx\n" /* line 859 | parentList */
        "movl -0x58(%ebp), %ecx\n"
        "movzbl (%edx, %ecx), %eax\n" /* in */
        "shll $5, %eax\n" /* in */
        "movl %edi, %edx\n" /* childMat */
        "subl %eax, %edx\n" /* in */
        /* { scope 2: xx, yy, yz, yw */
        "movss -0x10(%esi), %xmm0\n" /* line 171 */
        "movaps %xmm0, %xmm7\n"
        "movss 0xc(%edx), %xmm5\n"
        "movss -4(%esi), %xmm6\n"
        "movss %xmm6, -0xc4(%ebp)\n"
        "movss (%edx), %xmm2\n"
        "movss -8(%esi), %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n"
        "movss 4(%edx), %xmm3\n"
        "movss -0xc(%esi), %xmm0\n"
        "movaps %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm1\n"
        "movaps %xmm5, %xmm0\n" /* line 174 */
        "mulss %xmm6, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss %xmm0, -4(%esi)\n"
        "movaps %xmm7, %xmm0\n" /* line 176 */
        "mulss %xmm5, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss %xmm0, -0x10(%esi)\n"
        "movaps %xmm5, %xmm0\n" /* line 177 */
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss %xmm0, -0xc(%esi)\n"
        "mulss -0xbc(%ebp), %xmm5\n" /* line 178 */
        "mulss %xmm4, %xmm2\n"
        "addss %xmm5, %xmm2\n"
        "mulss %xmm7, %xmm3\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm6, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0xbc(%ebp)\n"
        "movss %xmm1, -8(%esi)\n"
        /* } scope */
        /* { scope 2: xx, yy, yz, yw */
        ".Lf75d9a_000766fb:\n"
        "movss -0xc0(%ebp), %xmm3\n" /* line 567 */
        "mulss %xmm3, %xmm3\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss -0xbc(%ebp), %xmm6\n"
        "mulss %xmm6, %xmm6\n"
        "addss %xmm6, %xmm3\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "pxor %xmm6, %xmm6\n" /* line 149 */
        "ucomiss %xmm6, %xmm3\n"
        "jp .Lf75d9a_00076746\n"
        "je .Lf75d9a_00076d30\n"
        ".Lf75d9a_00076746:\n"
        "movss lit4_002ed62c, %xmm0\n" /* line 151 | 2.0f */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, 0xc(%esi)\n"
        "movl $0x3f800000, -0xb0(%ebp)\n"
        /* } scope */
        ".Lf75d9a_00076761:\n"
        "movss (%esi), %xmm6\n" /* line 240 */
        "movss %xmm6, -0xa0(%ebp)\n"
        "movl -0x8c(%ebp), %eax\n" /* trans */
        "addss (%eax), %xmm6\n"
        "movss %xmm6, -0xa0(%ebp)\n"
        "movss %xmm6, (%esi)\n"
        "movss 4(%esi), %xmm0\n" /* line 241 */
        "movss %xmm0, -0xa4(%ebp)\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n"
        "movss %xmm0, 4(%esi)\n"
        "movss 8(%esi), %xmm7\n" /* line 242 */
        "addss 8(%eax), %xmm7\n"
        "movss %xmm7, 8(%esi)\n"
        "movl -0x58(%ebp), %edx\n"
        "movl -0x94(%ebp), %ecx\n" /* parentList */
        "movzbl (%edx, %ecx), %eax\n"
        "shll $5, %eax\n"
        "movl %edi, %edx\n"
        "subl %eax, %edx\n"
        /* { scope 2: xx, yy, yz, yw */
        /* { scope 3 */
        "movss 0x1c(%edx), %xmm1\n" /* line 306 | scale */
        /* { scope 4 */
        "movaps %xmm1, %xmm5\n" /* line 272 */
        "mulss (%edx), %xmm5\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "mulss 8(%edx), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm5, %xmm6\n" /* line 308 */
        "mulss (%edx), %xmm6\n"
        "movss %xmm6, -0x6c(%ebp)\n" /* xx */
        "movss 4(%edx), %xmm6\n" /* line 309 */
        "movaps %xmm5, %xmm4\n"
        "mulss %xmm6, %xmm4\n"
        "movss 8(%edx), %xmm2\n" /* line 310 */
        "movaps %xmm5, %xmm3\n"
        "mulss %xmm2, %xmm3\n"
        "movss 0xc(%edx), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm5\n"
        "mulss -0x5c(%ebp), %xmm6\n" /* line 313 */
        "movss %xmm6, -0x68(%ebp)\n" /* yy */
        "movss -0x5c(%ebp), %xmm6\n" /* line 314 */
        "mulss %xmm2, %xmm6\n"
        "movss %xmm6, -0x64(%ebp)\n" /* yz */
        "movss -0x5c(%ebp), %xmm6\n" /* line 315 */
        "mulss %xmm0, %xmm6\n"
        "movss %xmm6, -0x60(%ebp)\n" /* yw */
        "movaps %xmm1, %xmm6\n" /* line 317 */
        "mulss %xmm2, %xmm6\n"
        "mulss %xmm0, %xmm1\n" /* line 318 */
        /* } scope */
        /* } scope */
        "movss -0x68(%ebp), %xmm0\n" /* line 140 | yy */
        "addss %xmm6, %xmm0\n"
        "movss -0xb0(%ebp), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss -0xa0(%ebp), %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss -0xa4(%ebp), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -0x60(%ebp), %xmm0\n" /* yw */
        "addss %xmm3, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x10(%edx), %xmm2\n"
        "addss %xmm1, %xmm4\n" /* line 141 */
        "mulss -0xa0(%ebp), %xmm4\n"
        "addss -0x6c(%ebp), %xmm6\n" /* xx */
        "movss -0xb0(%ebp), %xmm0\n"
        "subss %xmm6, %xmm0\n"
        "mulss -0xa4(%ebp), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss -0x64(%ebp), %xmm0\n" /* yz */
        "subss %xmm5, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "addss 0x14(%edx), %xmm4\n"
        "subss -0x60(%ebp), %xmm3\n" /* line 142 | yw */
        "mulss -0xa0(%ebp), %xmm3\n"
        "addss -0x64(%ebp), %xmm5\n" /* yz */
        "mulss -0xa4(%ebp), %xmm5\n"
        "addss %xmm5, %xmm3\n"
        "movss -0x6c(%ebp), %xmm0\n" /* xx */
        "addss -0x68(%ebp), %xmm0\n" /* yy */
        "movss -0xb0(%ebp), %xmm6\n"
        "subss %xmm0, %xmm6\n"
        "mulss %xmm6, %xmm7\n"
        "addss %xmm7, %xmm3\n"
        "addss 0x18(%edx), %xmm3\n"
        "movss %xmm3, 8(%esi)\n"
        "movss %xmm2, (%esi)\n" /* line 143 */
        "movss %xmm4, 4(%esi)\n" /* line 144 */
        ".Lf75d9a_00076915:\n"
        "addl $0x20, %edi\n" /* line 843 | childMat */
        "addl $0x20, %esi\n"
        "addl $0xc, -0x8c(%ebp)\n" /* trans */
        "addl $1, -0x4c(%ebp)\n"
        "addl $1, -0x58(%ebp)\n"
        "movl -0x58(%ebp), %eax\n"
        "cmpl %eax, -0x9c(%ebp)\n" /* i */
        "je .Lf75d9a_000769e0\n"
        ".Lf75d9a_00076939:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 845 */
        "sarl $5, %edx\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 846 */
        "andl $0x1f, %ecx\n"
        "movl $1, %ebx\n" /* bFinished */
        "shll %cl, %ebx\n" /* bFinished */
        "testl %ebx, -0x28(%ebp, %edx, 4)\n" /* line 848 | bFinished */
        "jne .Lf75d9a_00076506\n"
        "movl -0x88(%ebp), %ecx\n" /* line 875 | pos */
        "movzbl (%ecx), %eax\n"
        "subl $1, %eax\n"
        "cmpl -0x4c(%ebp), %eax\n"
        "jne .Lf75d9a_00076915\n"
        "addl $2, %ecx\n" /* line 877 */
        "movl %ecx, -0x88(%ebp)\n" /* pos */
        "testl %ebx, -0x38(%ebp, %edx, 4)\n" /* line 878 | bFinished */
        "jne .Lf75d9a_00076915\n"
        "movzbl -1(%ecx), %eax\n" /* line 899 */
        "subl $1, %eax\n"
        "shll $5, %eax\n"
        "movl -0x90(%ebp), %ecx\n" /* sourceMat */
        "movl (%eax, %ecx), %edx\n"
        "movl %edx, -0x10(%esi)\n"
        "movl 4(%eax, %ecx), %edx\n"
        "movl %edx, -0xc(%esi)\n"
        "movl 8(%eax, %ecx), %edx\n"
        "movl %edx, -8(%esi)\n"
        "movl 0xc(%eax, %ecx), %edx\n"
        "movl %edx, -4(%esi)\n"
        "movl 0x10(%eax, %ecx), %edx\n"
        "movl %edx, (%esi)\n"
        "movl 0x14(%eax, %ecx), %edx\n"
        "movl %edx, 4(%esi)\n"
        "movl 0x18(%eax, %ecx), %edx\n"
        "movl %edx, 8(%esi)\n"
        "movl 0x1c(%eax, %ecx), %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "addl $0x20, %edi\n" /* line 843 | childMat */
        "addl $0x20, %esi\n"
        "addl $0xc, -0x8c(%ebp)\n" /* trans */
        "addl $1, -0x4c(%ebp)\n"
        "addl $1, -0x58(%ebp)\n"
        "movl -0x58(%ebp), %eax\n"
        "cmpl %eax, -0x9c(%ebp)\n" /* i */
        "jne .Lf75d9a_00076939\n"
        ".Lf75d9a_000769e0:\n"
        "addl $4, -0x54(%ebp)\n"
        "addl $1, -0x50(%ebp)\n"
        "movl -0x50(%ebp), %edx\n" /* line 718 */
        "cmpl %edx, -0xb4(%ebp)\n"
        "je .Lf75d9a_0007647d\n"
        "movl -0x54(%ebp), %edx\n"
        "movl 0x1c(%edx), %eax\n" /* line 720 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x98(%ebp)\n" /* model */
        "movl -0x50(%ebp), %ecx\n" /* line 721 */
        "movzbl 0x3c(%ecx), %eax\n"
        "cmpb $0xff, %al\n" /* line 724 */
        "jne .Lf75d9a_00075ece\n"
        ".Lf75d9a_00076a14:\n"
        "movl -0x98(%ebp), %esi\n" /* line 726 | model */
        "movzwl 2(%esi), %eax\n"
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n"
        "je .Lf75d9a_00076d77\n"
        "movl -0x4c(%ebp), %ebx\n" /* bFinished */
        "addl %ebx, %edx\n" /* bFinished */
        "movl %edx, -0xa8(%ebp)\n"
        "movss lit4_002ed62c, %xmm4\n" /* 2.0f */
        "jmp .Lf75d9a_00076a9b\n"
        /* { scope 2: xx, yy, yz, yw */
        ".Lf75d9a_00076a3f:\n"
        "movss (%edi), %xmm3\n" /* line 567 */
        "movss 4(%edi), %xmm0\n"
        "movss 8(%edi), %xmm1\n"
        "movss 0xc(%edi), %xmm2\n"
        "mulss %xmm3, %xmm3\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "pxor %xmm0, %xmm0\n" /* line 149 */
        "ucomiss %xmm0, %xmm3\n"
        "jp .Lf75d9a_00076a7d\n"
        "je .Lf75d9a_00076d64\n"
        ".Lf75d9a_00076a7d:\n"
        "movaps %xmm4, %xmm0\n" /* line 151 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, 0x1c(%edi)\n"
        /* } scope */
        ".Lf75d9a_00076a89:\n"
        "addl $0x20, %edi\n" /* line 726 | childMat */
        "addl $1, %ebx\n" /* bFinished */
        "cmpl %ebx, -0xa8(%ebp)\n" /* bFinished */
        "je .Lf75d9a_00076b29\n"
        ".Lf75d9a_00076a9b:\n"
        "movl %ebx, %esi\n" /* line 728 | bFinished */
        "sarl $5, %esi\n"
        "movl %ebx, %ecx\n" /* line 729 | bFinished */
        "andl $0x1f, %ecx\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "testl %edx, -0x28(%ebp, %esi, 4)\n" /* line 731 */
        "jne .Lf75d9a_00076a3f\n"
        "movl -0x88(%ebp), %ecx\n" /* line 747 | pos */
        "movzbl (%ecx), %eax\n"
        "subl $1, %eax\n"
        "cmpl %eax, %ebx\n" /* bFinished */
        "jne .Lf75d9a_00076a89\n"
        "addl $2, %ecx\n" /* line 749 */
        "movl %ecx, -0x88(%ebp)\n" /* pos */
        "testl %edx, -0x38(%ebp, %esi, 4)\n" /* line 750 */
        "jne .Lf75d9a_00076a89\n"
        "movzbl -1(%ecx), %eax\n" /* line 771 */
        "subl $1, %eax\n"
        "shll $5, %eax\n"
        "movl -0x90(%ebp), %esi\n" /* sourceMat */
        "movl (%eax, %esi), %edx\n"
        "movl %edx, (%edi)\n" /* childMat */
        "movl 4(%eax, %esi), %edx\n"
        "movl %edx, 4(%edi)\n" /* childMat */
        "movl 8(%eax, %esi), %edx\n"
        "movl %edx, 8(%edi)\n" /* childMat */
        "movl 0xc(%eax, %esi), %edx\n"
        "movl %edx, 0xc(%edi)\n" /* childMat */
        "movl 0x10(%eax, %esi), %edx\n"
        "movl %edx, 0x10(%edi)\n" /* childMat */
        "movl 0x14(%eax, %esi), %edx\n"
        "movl %edx, 0x14(%edi)\n" /* childMat */
        "movl 0x18(%eax, %esi), %edx\n"
        "movl %edx, 0x18(%edi)\n" /* childMat */
        "movl 0x1c(%eax, %esi), %eax\n"
        "movl %eax, 0x1c(%edi)\n" /* childMat */
        "addl $0x20, %edi\n" /* line 726 | childMat */
        "addl $1, %ebx\n" /* bFinished */
        "cmpl %ebx, -0xa8(%ebp)\n" /* bFinished */
        "jne .Lf75d9a_00076a9b\n"
        ".Lf75d9a_00076b29:\n"
        "movl -0xa8(%ebp), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0x98(%ebp), %edx\n" /* model */
        "movl -0x98(%ebp), %ecx\n" /* model */
        "jmp .Lf75d9a_000764cd\n"
        ".Lf75d9a_00076b43:\n"
        "movl -0x58(%ebp), %edx\n" /* line 861 */
        "movl -0x94(%ebp), %ecx\n" /* parentList */
        "movzbl (%edx, %ecx), %eax\n" /* in */
        "shll $5, %eax\n" /* in */
        "movl %edi, %edx\n" /* childMat */
        "subl %eax, %edx\n" /* in */
        /* { scope 2: xx, yy, yz, yw */
        "movss (%edx), %xmm3\n" /* line 191 */
        "movss -4(%esi), %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movss 0xc(%edx), %xmm7\n"
        "movss -0x10(%esi), %xmm6\n"
        "movss %xmm6, -0xc0(%ebp)\n"
        "movss 8(%edx), %xmm4\n"
        "movss -0xc(%esi), %xmm0\n"
        "movaps %xmm0, %xmm5\n"
        "movss 4(%edx), %xmm2\n"
        "movss -8(%esi), %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 194 */
        "mulss %xmm7, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm5, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss %xmm0, -4(%esi)\n"
        "movaps %xmm3, %xmm0\n" /* line 196 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss %xmm0, -0x10(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 197 */
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss -0xbc(%ebp), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss %xmm0, -0xc(%esi)\n"
        "mulss %xmm4, %xmm1\n" /* line 198 */
        "mulss %xmm6, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss %xmm5, %xmm3\n"
        "subss %xmm3, %xmm1\n"
        "mulss -0xbc(%ebp), %xmm7\n"
        "addss %xmm7, %xmm1\n"
        "movss %xmm1, -0xbc(%ebp)\n"
        "movss %xmm1, -8(%esi)\n"
        "jmp .Lf75d9a_000766fb\n"
        /* } scope */
        /* { scope 2: xx, yy, yz, yw */
        ".Lf75d9a_00076d30:\n"
        "movl $0x3f800000, -0xb0(%ebp)\n" /* line 155 */
        "movss -0xb0(%ebp), %xmm0\n"
        "movss %xmm0, -4(%esi)\n"
        "movl $0x40000000, 0xc(%esi)\n" /* line 156 */
        "jmp .Lf75d9a_00076761\n"
        ".Lf75d9a_00076d53:\n"
        "movl -0x98(%ebp), %edx\n" /* model */
        "movl -0x98(%ebp), %ecx\n" /* model */
        "jmp .Lf75d9a_000764cd\n"
        /* } scope */
        /* { scope 2: xx, yy, yz, yw */
        ".Lf75d9a_00076d64:\n"
        "movl $0x3f800000, 0xc(%edi)\n" /* line 155 */
        "movl $0x40000000, 0x1c(%edi)\n" /* line 156 */
        "jmp .Lf75d9a_00076a89\n"
        ".Lf75d9a_00076d77:\n"
        "movl %esi, %edx\n"
        "movl %esi, %ecx\n"
        "jmp .Lf75d9a_000764cd\n"
    );
}

/* line 1763 */
__attribute__((naked))
void DObjTraceline(DObj *obj, vec_t *start, vec_t *end, unsigned char *priorityMap, DObjTrace *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1763 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x27c, %esp\n"
        /* { scope 1: v, xx, xz, yy, ... */
        "movl 0x18(%ebp), %eax\n" /* line 1814 | trace */
        "movl $0, 4(%eax)\n"
        "movw $0, 0x14(%eax)\n" /* line 1815 */
        "movw $0, 0x16(%eax)\n" /* line 1816 */
        "addl $8, %eax\n" /* line 1817 */
        "movl %eax, -0x1f8(%ebp)\n" /* v */
        /* { scope 2: xx, xy, xz, yy, ... */
        "pxor %xmm2, %xmm2\n" /* line 183 */
        "movl 0x18(%ebp), %edx\n" /* trace */
        "movss %xmm2, 8(%edx)\n"
        "addl $0xc, %edx\n" /* line 184 */
        "movl %edx, -0x1f4(%ebp)\n"
        "movl 0x18(%ebp), %ecx\n" /* trace */
        "movss %xmm2, 0xc(%ecx)\n"
        "addl $0x10, %ecx\n" /* line 185 */
        "movl %ecx, -0x1f0(%ebp)\n"
        "movl 0x18(%ebp), %esi\n" /* trace */
        "movss %xmm2, 0x10(%esi)\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 248 | end */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x188(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* start */
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x188(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* line 249 | end */
        "addl $4, %edx\n"
        "movl %edx, -0x1ec(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x1e8(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* end */
        "movss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x18c(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* start */
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x18c(%ebp)\n"
        "addl $8, %ecx\n" /* line 250 */
        "movl %ecx, -0x1e4(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1e0(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* end */
        "movss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x190(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* start */
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x190(%ebp)\n"
        "movss -0x188(%ebp), %xmm1\n" /* line 316 */
        "mulss %xmm1, %xmm1\n"
        "movss -0x18c(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x190(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1821 */
        "jp .Lf76d80_00076e95\n"
        "je .Lf76d80_00077836\n"
        ".Lf76d80_00076e95:\n"
        "movl 8(%ebp), %edx\n" /* line 1341 | obj */
        "movl 4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf76d80_00077836\n"
        "addl $0x30, %eax\n" /* line 1828 */
        "movl %eax, -0x238(%ebp)\n" /* boneMatrix */
        "je .Lf76d80_00077836\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1834 | 1.0f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, -0x248(%ebp)\n" /* invL2 */
        "movzwl 0x10(%edx), %eax\n" /* line 1842 */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x268(%ebp)\n"
        "calll SL_ConvertToString\n"
        "addl $0x10, %eax\n"
        "movl %eax, -0x204(%ebp)\n" /* pos */
        "movss (%esi), %xmm1\n" /* line 1853 | bStartSolid */
        "movss %xmm1, -0x230(%ebp)\n" /* solidHitFrac */
        "movl 8(%ebp), %eax\n" /* line 1855 | obj */
        "cmpb $0, 0x18(%eax)\n"
        "movss -0x268(%ebp), %xmm2\n"
        "je .Lf76d80_00077836\n"
        "movl %eax, -0x160(%ebp)\n"
        "movl %eax, -0x15c(%ebp)\n"
        "movl $2, -0x210(%ebp)\n" /* lowestPriority */
        "movl $0, -0x218(%ebp)\n" /* globalBoneIndex */
        "movl $0xffffffff, -0x220(%ebp)\n" /* hitT */
        "movl $0, -0x214(%ebp)\n" /* j */
        "movl $0xffffffff, -0x21c(%ebp)\n" /* traceHitT */
        "movss %xmm2, -0x224(%ebp)\n" /* hitSign */
        "movl $0, -0x234(%ebp)\n" /* hitBoneMatrix */
        "movl %eax, %edx\n"
        ".Lf76d80_00076f56:\n"
        "movl 0x1c(%edx), %edx\n" /* line 1857 */
        "movl %edx, -0x244(%ebp)\n" /* model */
        "movl (%edx), %ecx\n" /* line 1858 */
        "movl %ecx, -0x240(%ebp)\n" /* modelParts */
        "movl 4(%ecx), %esi\n" /* line 1859 | bStartSolid */
        "movl %esi, -0x1fc(%ebp)\n" /* bStartSolid, hierarchy */
        "movl (%esi), %eax\n" /* line 1860 | bStartSolid */
        "movl %eax, -0x208(%ebp)\n" /* names */
        "movswl (%ecx), %edx\n" /* line 1861 */
        "movl %edx, -0x23c(%ebp)\n" /* size */
        "movl 8(%ebp), %ecx\n" /* line 1862 | obj */
        "movzbl 0x1a(%ecx), %ecx\n"
        "movl %ecx, -0x200(%ebp)\n" /* ignoreCollision */
        "movl $1, %eax\n"
        "movzbl -0x214(%ebp), %ecx\n" /* j */
        "shll %cl, %eax\n"
        "andl %eax, -0x200(%ebp)\n" /* ignoreCollision */
        "testl %edx, %edx\n" /* line 1864 */
        "jle .Lf76d80_0007793c\n"
        "movl $0, -0x228(%ebp)\n" /* localBoneIndex */
        "movl $0, -0x16c(%ebp)\n"
        "movl -0x218(%ebp), %ecx\n" /* globalBoneIndex */
        "movl -0x238(%ebp), %ebx\n" /* boneMatrix */
        "addl $0x10, %ebx\n"
        "movl -0x228(%ebp), %edx\n" /* localBoneIndex */
        ".Lf76d80_00076fd3:\n"
        "movl -0x240(%ebp), %esi\n" /* line 1866 | modelParts, bStartSolid */
        "movl 0x10(%esi), %eax\n" /* bStartSolid */
        "movzbw (%eax, %edx), %di\n" /* classification */
        "movzwl %di, %eax\n" /* line 1867 | classification */
        "movl 0x14(%ebp), %esi\n" /* priorityMap, bStartSolid */
        "movzbl (%eax, %esi), %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, -0x20c(%ebp)\n" /* currentPriority */
        "movl -0x204(%ebp), %esi\n" /* line 1868 | pos, bStartSolid */
        "movzbl (%esi), %eax\n" /* bStartSolid */
        "subl $1, %eax\n"
        "cmpl %ecx, %eax\n"
        "je .Lf76d80_00077903\n"
        "subb $1, %dl\n" /* line 1879 */
        "je .Lf76d80_0007796f\n"
        ".Lf76d80_00077011:\n"
        "movw %di, -0x154(%ebp, %ecx, 2)\n" /* line 1895 | classification */
        "movl -0x200(%ebp), %edx\n" /* line 1897 | ignoreCollision */
        "testl %edx, %edx\n"
        "jne .Lf76d80_00077896\n"
        "movl -0x16c(%ebp), %edx\n" /* line 1900 */
        "movl -0x244(%ebp), %ecx\n" /* model */
        "addl 0x60(%ecx), %edx\n"
        "movss 0x24(%edx), %xmm0\n" /* line 1901 */
        "movss %xmm0, -0x24c(%ebp)\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf76d80_00077052\n"
        "je .Lf76d80_00077896\n"
        ".Lf76d80_00077052:\n"
        "movl -0x210(%ebp), %eax\n" /* line 1906 | lowestPriority */
        "cmpl %eax, -0x20c(%ebp)\n" /* currentPriority */
        "jb .Lf76d80_00077896\n"
        "leal 0x18(%edx), %eax\n" /* line 1907 */
        "movl -0x238(%ebp), %ecx\n" /* line 1763 | boneMatrix */
        "addl $0x1c, %ecx\n"
        "movl %ecx, -0x168(%ebp)\n"
        /* { scope 2: xx, xy, xz, yy, ... */
        /* { scope 3 */
        "movss 0xc(%ebx), %xmm2\n" /* line 306 | scale */
        /* { scope 4 */
        "movaps %xmm2, %xmm3\n" /* line 272 */
        "mulss -0x10(%ebx), %xmm3\n"
        "movaps %xmm2, %xmm5\n" /* line 273 */
        "mulss -0xc(%ebx), %xmm5\n"
        "mulss -8(%ebx), %xmm2\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 308 */
        "mulss -0x10(%ebx), %xmm0\n"
        "movss %xmm0, -0x1dc(%ebp)\n" /* xx */
        "movl -0x238(%ebp), %ecx\n" /* line 1763 | boneMatrix */
        "addl $4, %ecx\n"
        "movl %ecx, -0x164(%ebp)\n"
        "movss -0xc(%ebx), %xmm4\n" /* line 309 */
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0x1d8(%ebp)\n" /* xy */
        "movl -0x238(%ebp), %esi\n" /* line 1763 | boneMatrix */
        "addl $8, %esi\n"
        "movss -8(%ebx), %xmm1\n" /* line 310 */
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1d4(%ebp)\n" /* xz */
        "movl -0x238(%ebp), %ecx\n" /* line 1763 | boneMatrix */
        "addl $0xc, %ecx\n"
        "movss -4(%ebx), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm5, %xmm4\n" /* line 313 */
        "movss %xmm4, -0x1d0(%ebp)\n" /* yy */
        "movaps %xmm5, %xmm4\n" /* line 314 */
        "mulss %xmm1, %xmm4\n"
        "movss %xmm4, -0x1cc(%ebp)\n" /* yz */
        "mulss %xmm0, %xmm5\n" /* line 315 */
        "mulss %xmm2, %xmm1\n" /* line 317 */
        "mulss %xmm0, %xmm2\n" /* line 318 */
        /* } scope */
        "movss 0x18(%edx), %xmm4\n" /* line 398 */
        "movss 4(%eax), %xmm6\n"
        "movss 8(%eax), %xmm7\n"
        "movss -0x1d0(%ebp), %xmm0\n" /* yy */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x270(%ebp)\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x270(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0x180(%ebp)\n"
        "movss -0x1d8(%ebp), %xmm0\n" /* xy */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss -0x180(%ebp), %xmm0\n"
        "movss %xmm0, -0x180(%ebp)\n"
        "movss -0x1d4(%ebp), %xmm0\n" /* xz */
        "addss %xmm5, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss -0x180(%ebp), %xmm0\n"
        "movss %xmm0, -0x180(%ebp)\n"
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, -0x180(%ebp)\n"
        "addss -0x1d8(%ebp), %xmm2\n" /* line 399 | xy */
        "mulss %xmm4, %xmm2\n"
        "addss -0x1dc(%ebp), %xmm1\n" /* xx */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x184(%ebp)\n"
        "movss -0x1cc(%ebp), %xmm0\n" /* yz */
        "subss %xmm3, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss -0x184(%ebp), %xmm0\n"
        "movss %xmm0, -0x184(%ebp)\n"
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x184(%ebp)\n"
        "movss -0x1d4(%ebp), %xmm1\n" /* line 400 | xz */
        "subss %xmm5, %xmm1\n"
        "movaps %xmm1, %xmm5\n"
        "mulss %xmm4, %xmm5\n"
        "addss -0x1cc(%ebp), %xmm3\n" /* yz */
        "mulss %xmm6, %xmm3\n"
        "addss %xmm3, %xmm5\n"
        "movss -0x1dc(%ebp), %xmm2\n" /* xx */
        "addss -0x1d0(%ebp), %xmm2\n" /* yy */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "addss 8(%ebx), %xmm5\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 248 | start */
        "movss (%eax), %xmm6\n"
        "movaps %xmm6, %xmm7\n"
        "subss -0x180(%ebp), %xmm7\n"
        "movl -0x1e8(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x1c8(%ebp)\n"
        "movaps %xmm0, %xmm1\n"
        "subss -0x184(%ebp), %xmm1\n"
        "movl -0x1e0(%ebp), %eax\n" /* line 250 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x1c4(%ebp)\n"
        "movaps %xmm0, %xmm4\n"
        "subss %xmm5, %xmm4\n"
        "movss -0x188(%ebp), %xmm3\n" /* line 1915 */
        "mulss %xmm7, %xmm3\n"
        "movss -0x18c(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss -0x190(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "xorps CorrectSolidDeltas+656, %xmm3\n"
        "mulss -0x248(%ebp), %xmm3\n" /* invL2 */
        "movss lit4_002ed5d0, %xmm2\n" /* line 1916 | 1.0f */
        "ucomiss %xmm3, %xmm2\n"
        "ja .Lf76d80_000779e5\n"
        "movl 0x10(%ebp), %eax\n" /* line 248 | end */
        "movss (%eax), %xmm2\n"
        "subss -0x180(%ebp), %xmm2\n"
        "movl -0x1ec(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm0\n"
        "subss -0x184(%ebp), %xmm0\n"
        "movl -0x1e4(%ebp), %eax\n" /* line 250 */
        "movss (%eax), %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "mulss %xmm2, %xmm2\n" /* line 316 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        ".Lf76d80_00077324:\n"
        "movss -0x24c(%ebp), %xmm0\n" /* line 1934 */
        "subss %xmm2, %xmm0\n"
        "pxor %xmm1, %xmm1\n" /* line 1935 */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf76d80_00077896\n"
        "movl -0x210(%ebp), %eax\n" /* line 1938 | lowestPriority */
        "cmpl %eax, -0x20c(%ebp)\n" /* currentPriority */
        "je .Lf76d80_00077bc4\n"
        ".Lf76d80_0007734f:\n"
        "subss (%ebx), %xmm6\n" /* line 248 */
        "movss -0x1c8(%ebp), %xmm0\n" /* line 249 */
        "subss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x178(%ebp)\n"
        "movss -0x1c4(%ebp), %xmm1\n" /* line 250 */
        "subss 8(%ebx), %xmm1\n"
        "movss %xmm1, -0x17c(%ebp)\n"
        /* { scope 2: xx, xy, xz, yy, ... */
        "movl -0x168(%ebp), %eax\n" /* line 306 */
        "movss (%eax), %xmm2\n" /* scale */
        /* { scope 3 */
        "movaps %xmm2, %xmm5\n" /* line 272 */
        "mulss -0x10(%ebx), %xmm5\n"
        "movaps %xmm2, %xmm7\n" /* line 273 */
        "mulss -0xc(%ebx), %xmm7\n"
        "mulss -8(%ebx), %xmm2\n" /* line 274 */
        /* } scope */
        "movaps %xmm5, %xmm0\n" /* line 308 */
        "mulss -0x10(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c0(%ebp)\n" /* xx */
        "movl -0x164(%ebp), %eax\n" /* line 309 */
        "movss (%eax), %xmm4\n"
        "movaps %xmm5, %xmm3\n"
        "mulss %xmm4, %xmm3\n"
        "movss (%esi), %xmm1\n" /* line 310 */
        "movaps %xmm5, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1bc(%ebp)\n" /* xz */
        "movss (%ecx), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm5\n"
        "mulss %xmm7, %xmm4\n" /* line 313 */
        "movss %xmm4, -0x1b8(%ebp)\n" /* yy */
        "movaps %xmm7, %xmm4\n" /* line 314 */
        "mulss %xmm1, %xmm4\n"
        "movss %xmm4, -0x1b4(%ebp)\n" /* yz */
        "mulss %xmm0, %xmm7\n" /* line 315 */
        "movaps %xmm2, %xmm4\n" /* line 317 */
        "mulss %xmm1, %xmm4\n"
        "mulss %xmm0, %xmm2\n" /* line 318 */
        /* } scope */
        "movss -0x1b8(%ebp), %xmm0\n" /* line 1747 | yy */
        "addss %xmm4, %xmm0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "mulss -0x178(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x1bc(%ebp), %xmm0\n" /* xz */
        "subss %xmm7, %xmm0\n"
        "mulss -0x17c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* localStart */
        "subss %xmm2, %xmm3\n" /* line 1748 */
        "mulss %xmm6, %xmm3\n"
        "addss -0x1c0(%ebp), %xmm4\n" /* xx */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm4, %xmm0\n"
        "mulss -0x178(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss -0x1b4(%ebp), %xmm0\n" /* yz */
        "addss %xmm5, %xmm0\n"
        "mulss -0x17c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x20(%ebp)\n"
        "addss -0x1bc(%ebp), %xmm7\n" /* line 1749 | xz */
        "movss %xmm7, -0x1bc(%ebp)\n" /* xz */
        "mulss %xmm7, %xmm6\n"
        "movss -0x1b4(%ebp), %xmm0\n" /* yz */
        "subss %xmm5, %xmm0\n"
        "movss -0x178(%ebp), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm6\n"
        "movss -0x1c0(%ebp), %xmm2\n" /* xx */
        "addss -0x1b8(%ebp), %xmm2\n" /* yy */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "mulss -0x17c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm6\n"
        "movss %xmm6, -0x1c(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 248 | end */
        "movss (%eax), %xmm4\n"
        "subss (%ebx), %xmm4\n"
        "movl -0x1ec(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm7\n"
        "subss 4(%ebx), %xmm7\n"
        "movl -0x1e4(%ebp), %eax\n" /* line 250 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x174(%ebp)\n"
        "subss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x174(%ebp)\n"
        /* { scope 2: xx, xy, xz, yy, ... */
        "movl -0x168(%ebp), %eax\n" /* line 306 */
        "movss (%eax), %xmm2\n" /* scale */
        /* { scope 3 */
        "movaps %xmm2, %xmm6\n" /* line 272 */
        "mulss -0x10(%ebx), %xmm6\n"
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss -0xc(%ebx), %xmm0\n"
        "movss %xmm0, -0x170(%ebp)\n"
        "mulss -8(%ebx), %xmm2\n" /* line 274 */
        /* } scope */
        "movaps %xmm6, %xmm1\n" /* line 308 */
        "mulss -0x10(%ebx), %xmm1\n"
        "movss %xmm1, -0x1b0(%ebp)\n" /* xx */
        "movl -0x164(%ebp), %eax\n" /* line 309 */
        "movss (%eax), %xmm5\n"
        "movaps %xmm6, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "movss (%esi), %xmm1\n" /* line 310 */
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1ac(%ebp)\n" /* xz */
        "movss (%ecx), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm6\n"
        "mulss -0x170(%ebp), %xmm5\n" /* line 313 */
        "movss %xmm5, -0x1a8(%ebp)\n" /* yy */
        "movss -0x170(%ebp), %xmm5\n" /* line 314 */
        "mulss %xmm1, %xmm5\n"
        "movss %xmm5, -0x1a4(%ebp)\n" /* yz */
        "movss -0x170(%ebp), %xmm5\n" /* line 315 */
        "mulss %xmm0, %xmm5\n"
        "movss %xmm5, -0x1a0(%ebp)\n" /* yw */
        "movaps %xmm2, %xmm5\n" /* line 317 */
        "mulss %xmm1, %xmm5\n"
        "mulss %xmm0, %xmm2\n" /* line 318 */
        /* } scope */
        "movss -0x1a8(%ebp), %xmm0\n" /* line 1747 | yy */
        "addss %xmm5, %xmm0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x1ac(%ebp), %xmm0\n" /* xz */
        "subss -0x1a0(%ebp), %xmm0\n" /* yw */
        "mulss -0x174(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* localEnd */
        "subss %xmm2, %xmm3\n" /* line 1748 */
        "mulss %xmm4, %xmm3\n"
        "addss -0x1b0(%ebp), %xmm5\n" /* xx */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm5, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss -0x1a4(%ebp), %xmm0\n" /* yz */
        "addss %xmm6, %xmm0\n"
        "mulss -0x174(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x2c(%ebp)\n"
        "movss -0x1ac(%ebp), %xmm0\n" /* line 1749 | xz */
        "addss -0x1a0(%ebp), %xmm0\n" /* yw */
        "mulss %xmm0, %xmm4\n"
        "movss -0x1a4(%ebp), %xmm1\n" /* yz */
        "subss %xmm6, %xmm1\n"
        "mulss %xmm1, %xmm7\n"
        "addss %xmm7, %xmm4\n"
        "movss -0x1b0(%ebp), %xmm2\n" /* xx */
        "addss -0x1a8(%ebp), %xmm2\n" /* yy */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "mulss -0x174(%ebp), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, -0x28(%ebp)\n"
        "movl -0x210(%ebp), %eax\n" /* line 1951 | lowestPriority */
        "cmpl %eax, -0x20c(%ebp)\n" /* currentPriority */
        "je .Lf76d80_000779d9\n"
        "movss -0x230(%ebp), %xmm5\n" /* solidHitFrac */
        ".Lf76d80_000776cb:\n"
        "movl %edx, %ecx\n" /* line 1959 */
        "pxor %xmm4, %xmm4\n"
        "movl $1, %esi\n" /* bStartSolid */
        "movb $1, -0x229(%ebp)\n" /* bEndSolid */
        "movss lit4_002ed5dc, %xmm7\n" /* -1.0f */
        "movaps %xmm7, %xmm3\n"
        "pxor %xmm6, %xmm6\n"
        ".Lf76d80_000776ec:\n"
        "xorl %edx, %edx\n"
        ".Lf76d80_000776ee:\n"
        "movss (%ecx, %edx, 4), %xmm0\n" /* line 1967 */
        "leal (, %edx, 4), %eax\n"
        "movss -0x24(%ebp, %eax), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "movss -0x30(%ebp, %eax), %xmm1\n" /* line 1968 */
        "subss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 1970 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf76d80_000778cf\n"
        "ucomiss %xmm0, %xmm1\n" /* line 1972 */
        "ja .Lf76d80_00077896\n"
        "movaps %xmm2, %xmm0\n" /* line 1976 */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "mulss %xmm4, %xmm0\n" /* line 1978 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf76d80_0007775d\n"
        "movaps %xmm2, %xmm4\n" /* line 1980 */
        "divss %xmm1, %xmm4\n"
        "ucomiss %xmm5, %xmm4\n" /* line 1981 */
        "jae .Lf76d80_00077896\n"
        "movl %edx, -0x220(%ebp)\n" /* line 1982 | hitT */
        "movss %xmm3, -0x224(%ebp)\n" /* hitSign */
        ".Lf76d80_0007775d:\n"
        "xorl %esi, %esi\n" /* bStartSolid */
        ".Lf76d80_0007775f:\n"
        "addl $1, %edx\n" /* line 1965 */
        "cmpl $3, %edx\n"
        "jne .Lf76d80_000776ee\n"
        "ucomiss lit4_002ed5d0, %xmm3\n" /* line 2001 | 1.0f */
        "jp .Lf76d80_00077772\n"
        "je .Lf76d80_00077782\n"
        ".Lf76d80_00077772:\n"
        "addl $0xc, %ecx\n" /* line 2004 */
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "jmp .Lf76d80_000776ec\n"
        ".Lf76d80_00077782:\n"
        "movl %esi, %eax\n" /* line 2007 | bStartSolid */
        "testb %al, %al\n"
        "je .Lf76d80_00077841\n"
        "cmpb $0, -0x229(%ebp)\n" /* line 2010 | bEndSolid */
        "je .Lf76d80_00077896\n"
        "movss -0x188(%ebp), %xmm0\n" /* line 2014 */
        "movl 0xc(%ebp), %edx\n" /* start */
        "mulss (%edx), %xmm0\n"
        "movss -0x18c(%ebp), %xmm1\n"
        "mulss -0x1c8(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf76d80_00077896\n"
        "movl 0x18(%ebp), %eax\n" /* line 2018 | trace */
        "movl $0, (%eax)\n"
        "movl -0x228(%ebp), %edx\n" /* line 2019 | localBoneIndex */
        "movl -0x208(%ebp), %ecx\n" /* names */
        "movzwl (%ecx, %edx, 2), %eax\n"
        "movl 0x18(%ebp), %esi\n" /* trace, bStartSolid */
        "movw %ax, 0x14(%esi)\n" /* bStartSolid */
        "movw %di, 0x16(%esi)\n" /* line 2020 | classification, bStartSolid */
        "movss -0x188(%ebp), %xmm0\n" /* line 2022 */
        "ucomiss %xmm2, %xmm0\n"
        "jne .Lf76d80_0007780f\n"
        "jp .Lf76d80_0007780f\n"
        "movss -0x18c(%ebp), %xmm1\n"
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf76d80_0007780f\n"
        "je .Lf76d80_00077c1c\n"
        ".Lf76d80_0007780f:\n"
        "movl 0xc(%ebp), %edx\n" /* line 37 | start */
        "movl (%edx), %eax\n"
        "movl -0x1f8(%ebp), %ecx\n" /* v */
        "movl %eax, (%ecx)\n"
        "movl -0x1e8(%ebp), %esi\n" /* line 38 */
        "movl (%esi), %eax\n"
        "movl -0x1f4(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl %ecx, (%esp)\n" /* line 2025 */
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        /* } scope */
        ".Lf76d80_00077836:\n"
        "addl $0x27c, %esp\n" /* line 2068 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: v, xx, xz, yy, ... */
        ".Lf76d80_00077841:\n"
        "movl -0x210(%ebp), %edx\n" /* line 2036 | lowestPriority */
        "cmpl %edx, -0x20c(%ebp)\n" /* currentPriority */
        "je .Lf76d80_00077c0d\n"
        "movl 0x18(%ebp), %esi\n" /* trace, bStartSolid */
        ".Lf76d80_00077856:\n"
        "movss %xmm4, (%esi)\n" /* line 2046 | bStartSolid */
        "movl -0x228(%ebp), %edx\n" /* line 2048 | localBoneIndex */
        "movl -0x208(%ebp), %ecx\n" /* names */
        "movzwl (%ecx, %edx, 2), %eax\n"
        "movw %ax, 0x14(%esi)\n" /* bStartSolid */
        "movw %di, 0x16(%esi)\n" /* line 2049 | classification, bStartSolid */
        "movl -0x20c(%ebp), %esi\n" /* currentPriority, bStartSolid */
        "movl %esi, -0x210(%ebp)\n" /* bStartSolid, lowestPriority */
        "movl -0x220(%ebp), %eax\n" /* hitT */
        "movl %eax, -0x21c(%ebp)\n" /* traceHitT */
        "movl -0x238(%ebp), %edx\n" /* boneMatrix */
        "movl %edx, -0x234(%ebp)\n" /* hitBoneMatrix */
        ".Lf76d80_00077896:\n"
        "addl $1, -0x228(%ebp)\n" /* line 1864 | localBoneIndex */
        "addl $0x20, -0x238(%ebp)\n" /* boneMatrix */
        "addl $0x20, %ebx\n"
        "movl -0x228(%ebp), %ecx\n" /* localBoneIndex */
        "addl -0x218(%ebp), %ecx\n" /* globalBoneIndex */
        "addl $0x28, -0x16c(%ebp)\n"
        "movl -0x228(%ebp), %esi\n" /* localBoneIndex, bStartSolid */
        "cmpl %esi, -0x23c(%ebp)\n" /* bStartSolid, size */
        "je .Lf76d80_00077936\n"
        "movl %esi, %edx\n" /* bStartSolid */
        "jmp .Lf76d80_00076fd3\n"
        ".Lf76d80_000778cf:\n"
        "ucomiss %xmm6, %xmm1\n" /* line 1987 */
        "jbe .Lf76d80_0007775f\n"
        "movaps %xmm2, %xmm0\n" /* line 1990 */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm0\n" /* line 1992 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf76d80_000778f7\n"
        "movaps %xmm2, %xmm5\n" /* line 1994 */
        "divss %xmm1, %xmm5\n"
        "ucomiss %xmm5, %xmm4\n" /* line 1995 */
        "jae .Lf76d80_00077896\n"
        ".Lf76d80_000778f7:\n"
        "movb $0, -0x229(%ebp)\n" /* line 1996 | bEndSolid */
        "jmp .Lf76d80_0007775f\n"
        ".Lf76d80_00077903:\n"
        "addl $2, %esi\n" /* line 1870 | bStartSolid */
        "movl %esi, -0x204(%ebp)\n" /* bStartSolid, pos */
        "subb $1, %dl\n" /* line 1871 */
        "jne .Lf76d80_00077011\n"
        "movzbl -1(%esi), %eax\n" /* line 1873 | bStartSolid */
        "movzwl -0x156(%ebp, %eax, 2), %edi\n" /* classification */
        "movzwl %di, %eax\n" /* line 1874 | classification */
        "movl 0x14(%ebp), %edx\n" /* priorityMap */
        "movzbl (%edx, %eax), %eax\n"
        "movl %eax, -0x20c(%ebp)\n" /* currentPriority */
        "jmp .Lf76d80_00077011\n"
        ".Lf76d80_00077936:\n"
        "movl %ecx, -0x218(%ebp)\n" /* line 1864 | globalBoneIndex */
        ".Lf76d80_0007793c:\n"
        "addl $1, -0x214(%ebp)\n" /* line 1855 | j */
        "addl $4, -0x160(%ebp)\n"
        "addl $1, -0x15c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* obj */
        "movzbl 0x18(%edx), %eax\n"
        "cmpl -0x214(%ebp), %eax\n" /* j */
        "jle .Lf76d80_00077a3b\n"
        "movl -0x160(%ebp), %edx\n"
        "jmp .Lf76d80_00076f56\n"
        ".Lf76d80_0007796f:\n"
        "movl -0x240(%ebp), %esi\n" /* line 1881 | modelParts, bStartSolid */
        "movswl 2(%esi), %eax\n" /* bStartSolid */
        "cmpl %eax, -0x228(%ebp)\n" /* localBoneIndex */
        "jge .Lf76d80_000779af\n"
        "movl -0x15c(%ebp), %edx\n" /* line 1883 */
        "movzbl 0x3c(%edx), %eax\n"
        "cmpb $0xff, %al\n" /* line 1884 */
        "je .Lf76d80_000779d3\n"
        "movzbl %al, %eax\n"
        "movzwl -0x154(%ebp, %eax, 2), %edi\n" /* classification */
        "movzwl %di, %eax\n" /* classification */
        ".Lf76d80_0007799d:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1891 | priorityMap */
        "movzbl (%edx, %eax), %eax\n"
        "movl %eax, -0x20c(%ebp)\n" /* currentPriority */
        "jmp .Lf76d80_00077011\n"
        ".Lf76d80_000779af:\n"
        "movl -0x228(%ebp), %esi\n" /* line 1888 | localBoneIndex, bStartSolid */
        "subl %eax, %esi\n" /* bStartSolid */
        "movl -0x1fc(%ebp), %edx\n" /* hierarchy */
        "movzbl 4(%edx, %esi), %eax\n"
        "movl %ecx, %esi\n" /* bStartSolid */
        "subl %eax, %esi\n" /* bStartSolid */
        "movzwl -0x154(%ebp, %esi, 2), %edi\n" /* classification */
        "movzwl %di, %eax\n" /* classification */
        "jmp .Lf76d80_0007799d\n"
        ".Lf76d80_000779d3:\n"
        "xorl %edi, %edi\n" /* line 1884 | classification */
        "xorl %eax, %eax\n"
        "jmp .Lf76d80_0007799d\n"
        ".Lf76d80_000779d9:\n"
        "movl 0x18(%ebp), %ecx\n" /* line 1952 | trace */
        "movss (%ecx), %xmm5\n"
        "jmp .Lf76d80_000776cb\n"
        ".Lf76d80_000779e5:\n"
        "pxor %xmm5, %xmm5\n" /* line 1918 */
        "ucomiss %xmm5, %xmm3\n"
        "jbe .Lf76d80_00077bf1\n"
        "movss -0x188(%ebp), %xmm2\n" /* line 288 */
        "mulss %xmm3, %xmm2\n"
        "addss %xmm7, %xmm2\n"
        "movss -0x18c(%ebp), %xmm0\n" /* line 289 */
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x190(%ebp), %xmm0\n" /* line 290 */
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss %xmm2, %xmm2\n" /* line 316 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm4, %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "jmp .Lf76d80_00077324\n"
        ".Lf76d80_00077a3b:\n"
        "movl -0x234(%ebp), %eax\n" /* line 2059 | hitBoneMatrix */
        "testl %eax, %eax\n"
        "je .Lf76d80_00077836\n"
        /* { scope 2: xx, xy, xz, yy, ... */
        "movl -0x234(%ebp), %ecx\n" /* line 306 | hitBoneMatrix */
        "movss 0x1c(%ecx), %xmm1\n" /* scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm4\n" /* line 272 */
        "mulss (%ecx), %xmm4\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%ecx), %xmm6\n"
        "mulss 8(%ecx), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm4, %xmm0\n" /* line 308 */
        "mulss (%ecx), %xmm0\n"
        "movss %xmm0, -0x19c(%ebp)\n" /* xx */
        "movss 4(%ecx), %xmm3\n" /* line 309 */
        "movaps %xmm4, %xmm5\n"
        "mulss %xmm3, %xmm5\n"
        "movss 8(%ecx), %xmm2\n" /* line 310 */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x198(%ebp)\n" /* xz */
        "movss 0xc(%ecx), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm4\n"
        "mulss %xmm6, %xmm3\n" /* line 313 */
        "movss %xmm3, -0x194(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm7\n" /* line 314 */
        "mulss %xmm2, %xmm7\n"
        "mulss %xmm0, %xmm6\n" /* line 315 */
        "movaps %xmm1, %xmm3\n" /* line 317 */
        "mulss %xmm2, %xmm3\n"
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss %xmm1, -0x26c(%ebp)\n" /* zw */
        "movss -0x194(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm3, %xmm0\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x54(%ebp)\n" /* axis */
        "movss -0x26c(%ebp), %xmm0\n" /* line 321 | zw */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movss -0x198(%ebp), %xmm0\n" /* line 322 | xz */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "subss -0x26c(%ebp), %xmm5\n" /* line 324 | zw */
        "movss %xmm5, -0x48(%ebp)\n"
        "addss -0x19c(%ebp), %xmm3\n" /* line 325 | xx */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 326 */
        "addss %xmm7, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "addss -0x198(%ebp), %xmm6\n" /* line 328 | xz */
        "movss %xmm6, -0x3c(%ebp)\n"
        "subss %xmm4, %xmm7\n" /* line 329 */
        "movss %xmm7, -0x38(%ebp)\n"
        "movss -0x19c(%ebp), %xmm4\n" /* line 330 | xx */
        "addss -0x194(%ebp), %xmm4\n" /* yy */
        "subss %xmm4, %xmm2\n"
        "movss %xmm2, -0x34(%ebp)\n"
        "movl -0x21c(%ebp), %edx\n" /* traceHitT */
        "leal (%edx, %edx, 2), %eax\n"
        "leal -0x54(%ebp, %eax, 4), %eax\n"
        /* } scope */
        /* { scope 2: xx, xy, xz, yy, ... */
        "movss -0x224(%ebp), %xmm0\n" /* line 272 | hitSign */
        "mulss (%eax), %xmm0\n"
        "movl -0x1f8(%ebp), %ecx\n" /* v */
        "movss %xmm0, (%ecx)\n"
        "movss -0x224(%ebp), %xmm0\n" /* line 273 | hitSign */
        "mulss 4(%eax), %xmm0\n"
        "movl -0x1f4(%ebp), %esi\n"
        "movss %xmm0, (%esi)\n"
        "movss -0x224(%ebp), %xmm0\n" /* line 274 | hitSign */
        "mulss 8(%eax), %xmm0\n"
        "movl -0x1f0(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        /* } scope */
        /* } scope */
        "addl $0x27c, %esp\n" /* line 2068 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: v, xx, xz, yy, ... */
        ".Lf76d80_00077bc4:\n"
        "mulss -0x248(%ebp), %xmm0\n" /* line 1940 | invL2 */
        "sqrtss %xmm0, %xmm0\n"
        "subss %xmm0, %xmm3\n"
        "movl 0x18(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm3\n"
        "jb .Lf76d80_0007734f\n"
        ".Lf76d80_00077be0:\n"
        "movl -0x20c(%ebp), %ecx\n" /* line 2054 | currentPriority */
        "movl %ecx, -0x210(%ebp)\n" /* lowestPriority */
        "jmp .Lf76d80_00077896\n"
        ".Lf76d80_00077bf1:\n"
        "movaps %xmm7, %xmm2\n" /* line 316 */
        "mulss %xmm7, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm4, %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "jmp .Lf76d80_00077324\n"
        ".Lf76d80_00077c0d:\n"
        "movl 0x18(%ebp), %ecx\n" /* line 2038 | trace */
        "ucomiss (%ecx), %xmm4\n"
        "jae .Lf76d80_00077be0\n"
        "movl %ecx, %esi\n" /* bStartSolid */
        "jmp .Lf76d80_00077856\n"
        ".Lf76d80_00077c1c:\n"
        "movss -0x190(%ebp), %xmm0\n" /* line 45 */
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm7, %xmm1\n"
        "cmpnltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movl 0x18(%ebp), %eax\n" /* line 2029 | trace */
        "movss %xmm0, 0x10(%eax)\n"
        "jmp .Lf76d80_00077836\n"
    );
}

#else
const char * DObjGetSurfaceName(DObj *obj, int modelIndex, int subMatIndex, int lod) {
    byte *model = *(byte **)((byte *)obj + 0x1c + modelIndex * 4);
    unsigned short *matNames = *(unsigned short **)(model + lod * 20 + 0x10);
    unsigned short name = matNames[subMatIndex];
    if (!name)
        return (const char *)str_00217dc0;
    return SL_ConvertToString(name);
}
#endif
