/* ASM dump from: cg_ents_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_ents_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern void DObjUpdateClientInfo(struct DObj_s *obj, float timescale);
extern void * MT_Alloc(int size, int type);

extern const int boxVerts[24][3]; /* boxVerts */

struct XAnim_s * CG_GetMG42Anims(centity_t *cent);
static long unsigned int CG_mg42_DoControllers(const centity_t *cent, int *partBits);
long unsigned int CG_SetFrameInterpolation(void);
long unsigned int CG_ProcessClientNoteTracks(int clientNum);
long unsigned int CG_DObjUpdateInfo(struct DObj_s *obj);
long unsigned int CG_SoundBlend(centity_t *cent);
static long unsigned int * CG_AllocAnimTree(int size);
long unsigned int CG_UsedDObjCalcPose(const centity_t *cent);
long unsigned int CG_CullIn(const centity_t *cent);
long unsigned int CG_AddCEntityToScene(const GfxEntity *ent, const struct DObj_s *obj, const centity_t *cent);
static long unsigned int CG_InterpolateEntityPosition(void);
qboolean CG_DObjGetViewModelTagPos(struct DObj_s *obj, unsigned int tagName, vec_t *pos);
long unsigned int CG_DObjCalcBoneGeneric(int handle, int localClientNum, int boneIndex);
long unsigned int CG_AdjustPositionForMover(const vec_t *in, int moverNum, int fromTime, int toTime, vec_t *out, vec_t *outDeltaAngles);
long unsigned int CG_CalcEntityLerpPositions(centity_t *cent);
long unsigned int CG_EntityEffects(centity_t *cent);
static struct DObj_s * CG_PreProcess_GetDObj(int iEntType);
long unsigned int CG_DObjCalcPose(const centity_t *cent, const struct DObj_s *obj, int *partBits);
long unsigned int CG_DObjCalcBone(const centity_t *cent, struct DObj_s *obj, int boneIndex);
DObjAnimMat * CG_DObjGetLocalTagMatrix(const centity_t *cent, struct DObj_s *obj, unsigned int tagName);
qboolean CG_DObjGetWorldTagPos(const centity_t *cent, struct DObj_s *obj, unsigned int tagName, vec_t *pos);
long unsigned int CG_General(centity_t *cent);
long unsigned int CG_Item(centity_t *cent);
long unsigned int CG_Missile(centity_t *cent);
long unsigned int CG_ScriptMover(centity_t *cent);
long unsigned int CG_ProcessEntity(centity_t *cent);
long unsigned int CG_AddPacketEntities(void);

/* line 253 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
struct XAnim_s * CG_GetMG42Anims(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 253 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 259 | cent */
        "movl 0x1b8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %esi\n" /* weapDef */
        "movl imp_Hunk_AllocXAnimClient, %eax\n" /* line 261 */
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl $str_002abcf4, (%esp)\n" /* "MG42" */
        "calll XAnimCreateAnims\n"
        "movl %eax, %ebx\n" /* pAnims */
        "movl $0, 0x14(%esp)\n" /* line 265 */
        "movl $2, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $str_0021df18, 8(%esp)\n" /* "root" */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimBlend\n"
        "movl imp_Hunk_AllocXAnimPrecache, %edi\n" /* line 269 */
        "movl %edi, 4(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* weapDef */
        "movl %eax, (%esp)\n"
        "calll XAnimPrecache\n"
        "movl 0x18(%esi), %eax\n" /* line 271 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pAnims */
        "calll XAnimCreate\n"
        "movl %edi, 4(%esp)\n" /* line 275 */
        "movl 0x20(%esi), %eax\n" /* weapDef */
        "movl %eax, (%esp)\n"
        "calll XAnimPrecache\n"
        "movl 0x20(%esi), %eax\n" /* line 277 | weapDef */
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pAnims */
        "calll XAnimCreate\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 280 | pAnims */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
struct XAnim_s * CG_GetMG42Anims(centity_t *cent) { return 0; }
#endif

/* line 288 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
long unsigned int CG_mg42_DoControllers(const centity_t *cent, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 288 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %edx, -0x34(%ebp)\n"
        /* { scope 1 */
        "movl %eax, %edi\n" /* line 298 | s1 */
        "addl $0xf0, %edi\n" /* s1 */
        "movl imp_cg, %eax\n" /* line 301 */
        "movl (%eax), %esi\n"
        "leal 0x25bc4(%esi), %ebx\n" /* ps */
        "movl -0x30(%ebp), %edx\n" /* line 303 */
        "movl 0x220(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, -0x2c(%ebp)\n" /* obj */
        "testl $0x300, 0xa0(%ebx)\n" /* line 306 | ps */
        "je .Lf161b64_00161bc7\n"
        "movl 0x594(%ebx), %eax\n" /* ps */
        "movl -0x30(%ebp), %ecx\n"
        "cmpl 0xf0(%ecx), %eax\n"
        "je .Lf161b64_00161d31\n"
        ".Lf161b64_00161bc7:\n"
        "movl 0x68(%edi), %edx\n" /* line 314 | s1 */
        "movl imp_cg, %eax\n"
        "movl (%eax), %ebx\n" /* ps */
        "movl 0x25ba8(%ebx), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll LerpAngle\n"
        "fstps -0x24(%ebp)\n" /* angles */
        "movl 0x6c(%edi), %edx\n" /* line 315 | s1 */
        "movl 0x25ba8(%ebx), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll LerpAngle\n"
        "fstps -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 316 */
        ".Lf161b64_00161c0d:\n"
        "leal -0x24(%ebp), %esi\n" /* line 319 | angles */
        "movl %esi, 0xc(%esp)\n"
        "movl imp_scr_const, %ebx\n" /* ps */
        "movzwl 0x9e(%ebx), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjSetControlTagAngles\n"
        "movl %esi, 0xc(%esp)\n" /* line 320 */
        "movzwl 0xa0(%ebx), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c(%ebp), %ecx\n" /* obj */
        "movl %ecx, (%esp)\n"
        "calll DObjSetControlTagAngles\n"
        "movl 0x70(%edi), %edx\n" /* line 322 | s1 */
        "movl imp_cg, %eax\n"
        "movl (%eax), %edi\n" /* s1 */
        "movl 0x25ba8(%edi), %eax\n" /* s1 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll LerpAngle\n"
        "fstps -0x24(%ebp)\n" /* angles */
        "movl $0, -0x20(%ebp)\n" /* line 323 */
        "movl %esi, 0xc(%esp)\n" /* line 325 */
        "movzwl 0x8c(%ebx), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %edx\n" /* obj */
        "movl %edx, (%esp)\n"
        "calll DObjSetControlTagAngles\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 327 | obj */
        "movl %ecx, (%esp)\n"
        "calll DObjGetTree\n"
        "movl %eax, %edx\n"
        "testl $0x300, 0x25c64(%edi)\n" /* line 330 | s1 */
        "je .Lf161b64_00161cdf\n"
        "movl 0x26158(%edi), %eax\n" /* s1 */
        "movl -0x30(%ebp), %ecx\n"
        "cmpl 0xf0(%ecx), %eax\n"
        "je .Lf161b64_00161cd8\n"
        "movl %ecx, %eax\n"
        "testb $0x40, 0xf8(%eax)\n" /* line 332 */
        "jne .Lf161b64_00161ceb\n"
        ".Lf161b64_00161cd8:\n"
        "movl $1, %ecx\n"
        "jmp .Lf161b64_00161cf0\n"
        ".Lf161b64_00161cdf:\n"
        "movl -0x30(%ebp), %eax\n"
        "testb $0x40, 0xf8(%eax)\n"
        "je .Lf161b64_00161cd8\n"
        ".Lf161b64_00161ceb:\n"
        "movl $2, %ecx\n"
        ".Lf161b64_00161cf0:\n"
        "movl $0, 0x1c(%esp)\n" /* line 337 */
        "movl $0, 0x18(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl $0x3dcccccd, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll XAnimSetCompleteGoalWeightKnobAll\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf161b64_00161d31:\n"
        "movl 0x1f8(%ecx), %eax\n" /* line 308 */
        "movl %eax, 4(%esp)\n"
        "movl 0x285c8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x24(%ebp)\n" /* angles */
        "movl -0x30(%ebp), %edx\n" /* line 309 */
        "movl 0x1fc(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x285cc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 310 */
        "jmp .Lf161b64_00161c0d\n"
    );
}

/* line 563 */
__attribute__((naked))
long unsigned int CG_SetFrameInterpolation(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 563 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 569 */
        "movl (%eax), %ecx\n"
        "movl 0x20(%ecx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl 0x24(%ecx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, %ebx\n" /* line 571 | delta */
        "subl %edx, %ebx\n" /* delta */
        "jne .Lf161d76_00161da0\n"
        "movl $0, 0x25ba8(%ecx)\n" /* line 573 */
        /* } scope */
        ".Lf161d76_00161d9d:\n"
        "popl %ebx\n" /* line 581 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf161d76_00161da0:\n"
        "movl 0x25bb0(%ecx), %eax\n" /* line 577 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "cvtsi2ssl %ebx, %xmm1\n" /* delta */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x25ba8(%ecx)\n"
        "pxor %xmm0, %xmm0\n" /* line 578 */
        "ucomiss 0x25ba8(%ecx), %xmm0\n"
        "jbe .Lf161d76_00161d9d\n"
        "movss %xmm0, 0x25ba8(%ecx)\n" /* line 579 */
        /* } scope */
        "popl %ebx\n" /* line 581 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 589 */
__attribute__((naked))
long unsigned int CG_ProcessClientNoteTracks(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 589 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* clientNum */
        /* { scope 1 */
        "cmpl $0x3f, %edi\n" /* line 594 | clientNum */
        "jbe .Lf161dd4_00161ded\n"
        /* } scope */
        ".Lf161dd4_00161de5:\n"
        "addl $0x3c, %esp\n" /* line 620 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf161dd4_00161ded:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 597 | noteList */
        "movl %eax, (%esp)\n"
        "calll DObjGetClientNotifyList\n"
        "movl %eax, -0x2c(%ebp)\n" /* listSize */
        "testl %eax, %eax\n" /* line 599 */
        "jle .Lf161dd4_00161de5\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %ebx, %ebx\n"
        "leal (%edi, %edi, 4), %edx\n" /* clientNum */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edi, %eax, 2), %eax\n" /* clientNum */
        "leal (, %eax, 8), %edi\n" /* clientNum */
        "jmp .Lf161dd4_00161e24\n"
        ".Lf161dd4_00161e19:\n"
        "addl $1, %esi\n" /* i */
        "addl $0xc, %ebx\n"
        "cmpl %esi, -0x2c(%ebp)\n" /* i, listSize */
        "je .Lf161dd4_00161de5\n"
        ".Lf161dd4_00161e24:\n"
        "movl %ebx, %eax\n" /* line 601 */
        "addl -0x1c(%ebp), %eax\n" /* noteList */
        "cmpl $1, 4(%eax)\n"
        "jne .Lf161dd4_00161e19\n"
        "movl $str_002abcfc, 4(%esp)\n" /* line 604 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf161dd4_00161e65\n"
        "movl %edi, %eax\n" /* line 606 | clientNum */
        "movl imp_cg, %edx\n"
        "addl (%edx), %eax\n"
        "movl $1, 0xe0d08(%eax)\n"
        "movl $1, 0xe0d0c(%eax)\n" /* line 607 */
        "jmp .Lf161dd4_00161e19\n"
        ".Lf161dd4_00161e65:\n"
        "movl $str_002abd14, 4(%esp)\n" /* line 609 */
        "movl -0x1c(%ebp), %eax\n" /* noteList */
        "movl (%ebx, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf161dd4_00161e19\n"
        "movl %edi, %eax\n" /* line 611 | clientNum */
        "movl imp_cg, %edx\n"
        "addl (%edx), %eax\n"
        "movl $0, 0xe0d08(%eax)\n"
        "movl $1, 0xe0d0c(%eax)\n" /* line 612 */
        "jmp .Lf161dd4_00161e19\n"
    );
}

/* line 686 */
long unsigned int CG_DObjUpdateInfo(struct DObj_s *obj)
{
    float timescale = (float)(*(int *)(*(int *)imp_cg + 0x25bac)) * 0.001f;
    DObjUpdateClientInfo(obj, timescale);
    return 0;
}

/* line 905 */
__attribute__((naked))
long unsigned int CG_SoundBlend(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 905 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* cent */
        /* { scope 1 */
        "leal 0xf0(%esi), %ebx\n" /* line 914 | cent, ns */
        "movl 0xb8(%ebx), %eax\n" /* line 916 | ns */
        "testl %eax, %eax\n"
        "je .Lf161ed4_00161efa\n"
        "movl 0xbc(%ebx), %edx\n" /* ns */
        "testl %edx, %edx\n"
        "jne .Lf161ed4_00161f02\n"
        /* } scope */
        ".Lf161ed4_00161efa:\n"
        "addl $0x3c, %esp\n" /* line 933 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf161ed4_00161f02:\n"
        "addl $0x24e, %eax\n" /* line 919 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "leal 0x1ec(%esi), %edi\n" /* cent */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl 0xf0(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundOnCurrentLocalClient\n"
        "testb %al, %al\n"
        "je .Lf161ed4_00161efa\n"
        "movl 0xb8(%ebx), %eax\n" /* line 922 | ns */
        "addl $0x24e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n"
        "calll CL_PickSoundAlias\n"
        "movl %eax, -0x1c(%ebp)\n" /* pAlias0 */
        "movl 0xbc(%ebx), %eax\n" /* line 923 | ns */
        "addl $0x24e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n"
        "calll CL_PickSoundAlias\n"
        "movl %eax, %edx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 925 | pAlias0 */
        "testl %eax, %eax\n"
        "je .Lf161ed4_00161efa\n"
        "testl %edx, %edx\n"
        "je .Lf161ed4_00161efa\n"
        "movss 0xd4(%esi), %xmm1\n" /* line 928 | cent */
        "movl $1, 0x18(%esp)\n" /* line 932 */
        "movl $0, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "movl 0xf0(%esi), %eax\n" /* cent */
        "movl %eax, 0xc(%esp)\n"
        "movss 0xd4(%ebx), %xmm0\n" /* ns */
        "subss %xmm1, %xmm0\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "mulss 0x25ba8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pAlias0 */
        "movl %eax, (%esp)\n"
        "calll SND_PlayBlendedSoundAliases\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 933 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1138 */
static long unsigned int * CG_AllocAnimTree(int size)
{
    return (long unsigned int *)MT_Alloc(size, 5);
}

/* line 1410 */
long unsigned int CG_UsedDObjCalcPose(const centity_t *cent)
{
    if (cent != NULL && *(byte *)((byte *)cent + 0x1e1) == 0)
        *(byte *)((byte *)cent + 0x1e1) = 1;
    return 0;
}

/* line 1425 */
long unsigned int CG_CullIn(const centity_t *cent)
{
    if (cent != NULL)
        *(byte *)((byte *)cent + 0x1e1) = 2;
    return 0;
}

/* line 1438 */
__attribute__((naked))
long unsigned int CG_AddCEntityToScene(const GfxEntity *ent, const struct DObj_s *obj, const centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1438 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* cent */
        /* { scope 1 */
        "movl %ebx, 8(%esp)\n" /* line 1447 | cent */
        "movl 0xc(%ebp), %eax\n" /* obj */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll R_AddRefEntityToScene\n"
        "testl %eax, %eax\n" /* line 1448 */
        "je .Lf162026_0016205b\n"
        "movzbl 0x1e1(%ebx), %edx\n" /* line 1451 | cent */
        "cmpb $1, %dl\n"
        "je .Lf162026_00162075\n"
        "cmpb $2, %dl\n" /* line 1456 */
        "je .Lf162026_00162061\n"
        /* } scope */
        ".Lf162026_0016205b:\n"
        "addl $0x14, %esp\n" /* line 1461 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf162026_00162061:\n"
        "movb $0, 0x1e1(%ebx)\n" /* line 1458 | cent */
        "movl %eax, 8(%ebp)\n" /* line 1459 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1461 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp R_SkinGfxEntityDelayed\n" /* line 1459 */
        ".Lf162026_00162075:\n"
        "movb $0, 0x1e1(%ebx)\n" /* line 1453 | cent */
        "movl %eax, 8(%ebp)\n" /* line 1454 | ent */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1461 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp R_UpdateXModelBoundsDelayed\n" /* line 1454 */
    );
}

/* line 1010 */
static __attribute__((naked))
long unsigned int CG_InterpolateEntityPosition(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1010 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %edi\n" /* cent */
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 1018 */
        "movl (%eax), %esi\n"
        "movss 0x25ba8(%esi), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* f */
        "leal -0x24(%ebp), %eax\n" /* line 1022 | current */
        "movl %eax, 8(%esp)\n"
        "movl 0x20(%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "leal -0x30(%ebp), %ebx\n" /* line 1023 | next */
        "movl %ebx, 8(%esp)\n"
        "movl 0x24(%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xfc(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 1025 | current */
        "movss -0x30(%ebp), %xmm0\n" /* next */
        "subss %xmm1, %xmm0\n"
        "mulss -0x40(%ebp), %xmm0\n" /* f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x1ec(%edi)\n" /* cent */
        "movss -0x20(%ebp), %xmm1\n" /* line 1026 */
        "movss -0x2c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss -0x40(%ebp), %xmm0\n" /* f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x1f0(%edi)\n" /* cent */
        "movss -0x1c(%ebp), %xmm1\n" /* line 1027 */
        "movss -0x28(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss -0x40(%ebp), %xmm0\n" /* f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x1f4(%edi)\n" /* cent */
        "leal -0x24(%ebp), %eax\n" /* line 1029 | current */
        "movl %eax, 8(%esp)\n"
        "movl 0x20(%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x30(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl %ebx, 8(%esp)\n" /* line 1030 */
        "movl 0x24(%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x120(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 1032 | f */
        "movss %xmm0, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* next */
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* current */
        "movl %eax, (%esp)\n"
        "calll LerpAngle\n"
        "fstps 0x1f8(%edi)\n" /* cent */
        "movss -0x40(%ebp), %xmm0\n" /* line 1033 | f */
        "movss %xmm0, 8(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LerpAngle\n"
        "fstps 0x1fc(%edi)\n" /* cent */
        "movss -0x40(%ebp), %xmm0\n" /* line 1034 | f */
        "movss %xmm0, 8(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LerpAngle\n"
        "fstps 0x200(%edi)\n" /* cent */
        "cmpl $1, 0xf4(%edi)\n" /* line 1036 | cent */
        "je .Lf16208a_001621f3\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1047 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16208a_001621f3:\n"
        "movl 0x180(%edi), %eax\n" /* line 1039 | cent */
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %ebx\n"
        "shll $4, %ebx\n"
        "subl %edx, %ebx\n"
        "leal (%eax, %ebx, 2), %ebx\n"
        "leal 0xe0900(%esi, %ebx, 8), %ebx\n"
        "leal 0x14(%ebx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* ci */
        "movss -0x40(%ebp), %xmm0\n" /* line 1040 | f */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x15c(%edi), %eax\n" /* cent */
        "movl %eax, 4(%esp)\n"
        "movl 0x6c(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll LerpAngle\n"
        "movl -0x3c(%ebp), %eax\n" /* ci */
        "fstps 0x3e0(%eax)\n"
        "leal 0x3fc(%ebx), %ecx\n" /* line 1041 | to */
        "leal 0x1f8(%edi), %edx\n" /* cent, from */
        /* { scope 2 */
        "movl 0x1f8(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x3fc(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1042 */
        "movl %eax, 0x1f8(%edi)\n" /* cent */
        "movl %eax, 0x200(%edi)\n" /* line 1043 | cent */
        "movss -0x40(%ebp), %xmm0\n" /* line 1045 | f */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x1c4(%edi), %eax\n" /* cent */
        "movl %eax, 4(%esp)\n"
        "movl 0xd4(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll LerpAngle\n"
        "movl -0x3c(%ebp), %eax\n" /* ci */
        "fstps 0x3e4(%eax)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1047 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 777 */
__attribute__((naked))
qboolean CG_DObjGetViewModelTagPos(struct DObj_s *obj, unsigned int tagName, vec_t *pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 777 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %esi\n" /* obj */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 786 | tagName */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjGetBoneIndex\n"
        "movl %eax, %edi\n" /* boneIndex */
        "testl %eax, %eax\n" /* line 787 */
        "js .Lf1622a2_0016234f\n"
        "movl $0, 8(%esp)\n" /* line 791 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll CL_DObjCreateSkelForBone\n"
        "testl %eax, %eax\n"
        "je .Lf1622a2_00162359\n"
        ".Lf1622a2_001622df:\n"
        "movl %esi, (%esp)\n" /* line 799 | obj */
        "calll DObjGetRotTransArray\n"
        "movl %eax, -0x5c(%ebp)\n" /* mat */
        "testl %eax, %eax\n" /* line 800 */
        "je .Lf1622a2_0016234f\n"
        "leal -0x58(%ebp), %esi\n" /* line 805 | ent_axis, obj */
        "movl %esi, 4(%esp)\n" /* obj */
        "movl imp_cg, %eax\n"
        "movl (%eax), %ebx\n"
        "leal 0x2c0c8(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "leal 0x2c0bc(%ebx), %edx\n"
        /* { scope 2 */
        "movl 0x2c0bc(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x2c(%ebp)\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 807 | pos */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* obj */
        "shll $5, %edi\n" /* boneIndex */
        "movl -0x5c(%ebp), %edx\n" /* mat */
        "leal 0x10(%edx, %edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 809 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1622a2_0016234f:\n"
        "xorl %eax, %eax\n" /* line 808 */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 809 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1622a2_00162359:\n"
        "leal -0x28(%ebp), %ebx\n" /* line 793 | partBits */
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* boneIndex */
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjGetHierarchyBits\n"
        "movl %ebx, 4(%esp)\n" /* line 794 */
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjCalcAnim\n"
        "movl %ebx, 4(%esp)\n" /* line 795 */
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjCalcSkel\n"
        "jmp .Lf1622a2_001622df\n"
    );
}

/* line 1319 */
__attribute__((naked))
long unsigned int CG_DObjCalcBoneGeneric(int handle, int localClientNum, int boneIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1319 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* handle */
        "movl 0x10(%ebp), %edi\n" /* boneIndex */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 1324 | localClientNum */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* handle */
        "calll Com_GetClientDObj\n"
        "movl %eax, %esi\n" /* obj */
        "movl $0, 8(%esp)\n" /* line 1331 */
        "movl %edi, 4(%esp)\n" /* boneIndex */
        "movl %eax, (%esp)\n"
        "calll CL_DObjCreateSkelForBone\n"
        "testl %eax, %eax\n"
        "je .Lf16238a_001623ca\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1348 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16238a_001623ca:\n"
        "leal -0x28(%ebp), %eax\n" /* line 1339 | partBits */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* boneIndex */
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjGetHierarchyBits\n"
        "leal -0x28(%ebp), %eax\n" /* line 1340 | partBits */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjCalcAnim\n"
        "cmpl $0x3ff, %ebx\n" /* line 1341 | handle */
        "jg .Lf16238a_0016241d\n"
        "movl %ebx, %eax\n" /* handle */
        "shll $4, %eax\n"
        "addl %ebx, %eax\n" /* handle */
        "leal (%ebx, %eax, 8), %eax\n" /* handle */
        "movl imp_cg_entities, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %ecx\n"
        "movl 0xf4(%ecx), %eax\n" /* line 1228 */
        "cmpl $1, %eax\n"
        "je .Lf16238a_00162434\n"
        "cmpl $9, %eax\n"
        "je .Lf16238a_001624a9\n"
        ".Lf16238a_0016241d:\n"
        "leal -0x28(%ebp), %eax\n" /* line 1343 | partBits */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjCalcSkel\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1348 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: obj */
        /* { scope 3 */
        ".Lf16238a_00162434:\n"
        "leal 0xf0(%ecx), %edi\n" /* line 1206 | es */
        "movl 0x220(%ecx), %eax\n" /* line 1207 */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, -0x2c(%ebp)\n" /* obj */
        "movl imp_cg, %eax\n" /* line 1210 */
        "movl (%eax), %ebx\n"
        "movl 0x90(%edi), %edx\n" /* es */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0900(%ebx, %eax, 8), %eax\n"
        "leal 0x14(%eax), %edx\n"
        "movl 0x14(%eax), %ecx\n" /* line 1211 */
        "testl %ecx, %ecx\n"
        "je .Lf16238a_0016241d\n"
        "movl 0x25bac(%ebx), %eax\n" /* line 1214 */
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* partBits */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* es */
        "movl -0x2c(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll BG_Player_DoControllers\n"
        "jmp .Lf16238a_0016241d\n"
        /* } scope */
        /* } scope */
        ".Lf16238a_001624a9:\n"
        "leal -0x28(%ebp), %edx\n" /* line 1234 | partBits */
        "movl %ecx, %eax\n"
        "calll CG_mg42_DoControllers\n"
        "jmp .Lf16238a_0016241d\n"
    );
}

/* line 513 */
__attribute__((naked))
long unsigned int CG_AdjustPositionForMover(const vec_t *in, int moverNum, int fromTime, int toTime, vec_t *out, vec_t *outDeltaAngles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 513 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* moverNum */
        "movl 0x18(%ebp), %esi\n" /* out */
        "movl 0x1c(%ebp), %edi\n" /* outDeltaAngles */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 519 | outDeltaAngles */
        "je .Lf1624b8_001624d8\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, (%edi)\n"
        "movl %eax, 4(%edi)\n" /* line 184 */
        "movl %eax, 8(%edi)\n" /* line 185 */
        ".Lf1624b8_001624d8:\n"
        "leal -1(%edx), %eax\n" /* line 522 */
        "cmpl $0x3fc, %eax\n"
        "ja .Lf1624b8_00162500\n"
        "movl %edx, %eax\n" /* line 528 */
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl imp_cg_entities, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* cent */
        "cmpl $6, 0xf4(%ebx)\n" /* line 530 | cent */
        "je .Lf1624b8_0016251b\n"
        ".Lf1624b8_00162500:\n"
        "movl 8(%ebp), %edx\n" /* line 199 | in */
        "movl (%edx), %eax\n"
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        /* } scope */
        ".Lf1624b8_00162513:\n"
        "addl $0x5c, %esp\n" /* line 550 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1624b8_0016251b:\n"
        "leal 0xc(%ebx), %eax\n" /* line 536 | cent */
        "movl %eax, -0x4c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* oldOrigin */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* fromTime */
        "movl %edx, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "addl $0x30, %ebx\n" /* line 537 | cent */
        "leal -0x3c(%ebp), %eax\n" /* oldAngles */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* fromTime */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cent */
        "calll BG_EvaluateTrajectory\n"
        "leal -0x30(%ebp), %eax\n" /* line 539 | origin */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* toTime */
        "movl %eax, 4(%esp)\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "leal -0x48(%ebp), %eax\n" /* line 540 | angles */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* toTime */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cent */
        "calll BG_EvaluateTrajectory\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 249 */
        "subss -0x20(%ebp), %xmm1\n"
        "movss -0x28(%ebp), %xmm2\n" /* line 250 */
        "subss -0x1c(%ebp), %xmm2\n"
        "movss -0x48(%ebp), %xmm5\n" /* line 248 | angles */
        "subss -0x3c(%ebp), %xmm5\n" /* oldAngles */
        "movss -0x44(%ebp), %xmm4\n" /* line 249 */
        "subss -0x38(%ebp), %xmm4\n"
        "movss -0x40(%ebp), %xmm3\n" /* line 250 */
        "subss -0x34(%ebp), %xmm3\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 240 | origin */
        "subss -0x24(%ebp), %xmm0\n" /* oldOrigin */
        "movl 8(%ebp), %edx\n" /* in */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "addss 4(%edx), %xmm1\n" /* line 241 */
        "movss %xmm1, 4(%esi)\n"
        "addss 8(%edx), %xmm2\n" /* line 242 */
        "movss %xmm2, 8(%esi)\n"
        "testl %edi, %edi\n" /* line 546 | outDeltaAngles */
        "je .Lf1624b8_00162513\n"
        "movss %xmm5, (%edi)\n" /* line 199 */
        "movss %xmm4, 4(%edi)\n" /* line 200 */
        "movss %xmm3, 8(%edi)\n" /* line 201 */
        "jmp .Lf1624b8_00162513\n"
    );
}

/* line 1056 */
__attribute__((naked))
long unsigned int CG_CalcEntityLerpPositions(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1056 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* cent */
        /* { scope 1 */
        "movl 0xc(%esi), %eax\n" /* line 1061 | cent */
        "cmpl $1, %eax\n"
        "je .Lf1625f8_001626cc\n"
        "cmpl $3, %eax\n" /* line 1069 */
        "je .Lf1625f8_001626c3\n"
        ".Lf1625f8_00162619:\n"
        "leal 0x1ec(%esi), %eax\n" /* line 1076 | cent */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, 8(%esp)\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %ebx\n" /* ci */
        "movl 0x25bb0(%ebx), %eax\n" /* ci */
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "leal 0x1f8(%esi), %edi\n" /* line 1077 | cent */
        "movl %edi, 8(%esp)\n"
        "movl 0x25bb0(%ebx), %eax\n" /* ci */
        "movl %eax, 4(%esp)\n"
        "leal 0x30(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 0xf4(%esi), %eax\n" /* line 1079 | cent */
        "cmpl $1, %eax\n"
        "je .Lf1625f8_001626da\n"
        "cmpl $2, %eax\n" /* line 1090 */
        "je .Lf1625f8_00162740\n"
        ".Lf1625f8_00162675:\n"
        "movl imp_cg, %eax\n" /* line 1105 */
        "movl (%eax), %edx\n"
        "leal 0x2826c(%edx), %eax\n"
        "cmpl %eax, %esi\n" /* cent */
        "je .Lf1625f8_001626bb\n"
        "movl $0, 0x14(%esp)\n" /* line 1107 */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x25bb0(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x20(%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x7c(%esi), %eax\n" /* cent */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_AdjustPositionForMover\n"
        /* } scope */
        ".Lf1625f8_001626bb:\n"
        "addl $0x3c, %esp\n" /* line 1109 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1625f8_001626c3:\n"
        "cmpl $0x3f, (%esi)\n" /* line 1069 | cent */
        "jg .Lf1625f8_00162619\n"
        ".Lf1625f8_001626cc:\n"
        "movl %esi, %eax\n" /* line 1071 | cent */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1109 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CG_InterpolateEntityPosition\n" /* line 1071 */
        ".Lf1625f8_001626da:\n"
        "movl 0x180(%esi), %edx\n" /* line 1082 | cent */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0900(%ebx, %eax, 8), %eax\n" /* ci */
        "leal 0x14(%eax), %ebx\n" /* ci */
        "movl 0x15c(%esi), %edx\n" /* line 1083 | cent */
        "movl %edx, 0x3e0(%ebx)\n" /* ci */
        "leal 0x3fc(%eax), %ecx\n" /* line 1084 | to */
        /* { scope 2 */
        "movl 0x1f8(%esi), %edx\n" /* line 199 */
        "movl %edx, 0x3fc(%eax)\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1625f8_00162715:\n"
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1097 */
        "movl %eax, 0x1f8(%esi)\n" /* cent */
        "movl %eax, 0x200(%esi)\n" /* line 1098 | cent */
        "movl 0x1c4(%esi), %eax\n" /* line 1100 | cent */
        "movl %eax, 0x3e4(%ebx)\n" /* ci */
        "jmp .Lf1625f8_00162675\n"
        ".Lf1625f8_00162740:\n"
        "movl 0xf0(%esi), %edx\n" /* line 1094 | cent */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl imp_cgs, %edx\n"
        "movl (%edx), %edx\n"
        "leal -0x6bf0(%edx, %eax, 8), %eax\n"
        "leal 4(%eax), %ebx\n" /* ci */
        "movl 0x15c(%esi), %edx\n" /* line 1095 | cent */
        "movl %edx, 0x3e0(%ebx)\n" /* ci */
        "leal 0x3ec(%eax), %ecx\n" /* line 1096 | to */
        /* { scope 2 */
        "movl 0x1f8(%esi), %edx\n" /* line 199 */
        "movl %edx, 0x3ec(%eax)\n"
        "jmp .Lf1625f8_00162715\n"
    );
}

/* line 200 */
__attribute__((naked))
long unsigned int CG_EntityEffects(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 200 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* cent */
        "movl 0x174(%esi), %ebx\n" /* line 203 | cent */
        "testl %ebx, %ebx\n"
        "je .Lf162788_001627d7\n"
        "cmpl $0x00FFFFFF, 0x18c(%esi)\n" /* line 205 | cent */
        "je .Lf162788_0016284c\n"
        "leal 0x24e(%ebx), %eax\n" /* line 216 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x1ec(%esi), %eax\n" /* cent */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAliasByName\n"
        ".Lf162788_001627d7:\n"
        "movl 0x170(%esi), %edx\n" /* line 221 | cent */
        "testl %edx, %edx\n"
        "je .Lf162788_00162845\n"
        "movl %edx, %eax\n" /* line 232 */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss lit4_002ed5d4, %xmm1\n" /* 255.0f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movzbl %dh, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movzbl %dl, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "shrl $0x18, %edx\n"
        "leal (, %edx, 4), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "leal 0x1ec(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CL_AddLightToScene\n"
        ".Lf162788_00162845:\n"
        "addl $0x30, %esp\n" /* line 234 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf162788_0016284c:\n"
        "leal 0x1ec(%esi), %ecx\n" /* line 205 | cent */
        "movl 0x17c(%esi), %eax\n" /* cent */
        "leal (%eax, %eax, 2), %eax\n"
        "movl imp_cgs, %edx\n"
        "movl (%edx), %edx\n"
        "leal 0x8180(%edx, %eax, 4), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 1 */
        /* { scope 2 */
        "movss 0x1ec(%esi), %xmm0\n" /* line 240 | cent */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* origin */
        "movss 4(%ecx), %xmm0\n" /* line 241 */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss 8(%ecx), %xmm0\n" /* line 242 */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        /* } scope */
        "leal 0x24e(%ebx), %eax\n" /* line 212 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* origin */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAliasByName\n"
        "jmp .Lf162788_001627d7\n"
    );
}

/* line 1151 */
static __attribute__((naked))
struct DObj_s * CG_PreProcess_GetDObj(int iEntType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1151 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %esi\n" /* iEntNum */
        "movl %edx, -0x2c(%ebp)\n"
        "movl %ecx, %edi\n" /* model */
        /* { scope 1: dobjModel */
        "movl $0, 4(%esp)\n" /* line 1155 */
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %ebx\n" /* pDObj */
        "testl %eax, %eax\n" /* line 1158 */
        "je .Lf1628ca_0016291d\n"
        "testl %edi, %edi\n" /* model */
        "je .Lf1628ca_00162915\n"
        "movl %edi, 8(%esp)\n" /* model */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* iEntNum */
        "calll CG_CheckDObjInfoMatches\n"
        "testl %eax, %eax\n"
        "je .Lf1628ca_00162915\n"
        /* } scope */
        ".Lf1628ca_0016290b:\n"
        "movl %ebx, %eax\n" /* line 1191 | pDObj */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dobjModel */
        ".Lf1628ca_00162915:\n"
        "movl %esi, (%esp)\n" /* line 1160 | iEntNum */
        "calll CG_SafeDObjFree\n"
        ".Lf1628ca_0016291d:\n"
        "testl %edi, %edi\n" /* line 1166 | model */
        "je .Lf1628ca_001629e5\n"
        /* { scope 2 */
        "cmpl $9, -0x2c(%ebp)\n" /* line 1120 */
        "je .Lf1628ca_001629a7\n"
        "movl %esi, %eax\n"
        "shll $4, %eax\n"
        "addl %esi, %eax\n"
        "leal (%esi, %eax, 8), %eax\n"
        "leal (, %eax, 4), %ebx\n"
        "xorl %edx, %edx\n"
        ".Lf1628ca_0016293e:\n"
        "movl imp_cg_entities, %eax\n" /* line 1175 */
        "movl (%eax), %eax\n"
        "movl %edx, 0x21c(%eax, %ebx)\n"
        "movl %edi, -0x24(%ebp)\n" /* line 1177 | model, dobjModel */
        "movl $0, -0x20(%ebp)\n" /* line 1178 */
        "movl $1, -0x1c(%ebp)\n" /* line 1179 */
        "movl %esi, 0xc(%esp)\n" /* line 1183 | iEntNum */
        "movl %edx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* dobjModel */
        "movl %eax, (%esp)\n"
        "calll Com_ClientDObjCreate\n"
        "movl %edi, 8(%esp)\n" /* line 1184 | model */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* iEntNum */
        "calll CG_SetDObjInfo\n"
        "movl $0, 4(%esp)\n" /* line 1187 */
        "movl %esi, (%esp)\n" /* iEntNum */
        "calll Com_GetClientDObj\n"
        "movl %eax, %ebx\n" /* pDObj */
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1191 | pDObj */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dobjModel */
        /* { scope 2 */
        ".Lf1628ca_001629a7:\n"
        "movl %esi, %eax\n" /* line 1123 */
        "shll $4, %eax\n"
        "addl %esi, %eax\n"
        "leal (%esi, %eax, 8), %eax\n"
        "leal (, %eax, 4), %ebx\n"
        "movl imp_cg_entities, %eax\n"
        "movl (%eax), %edx\n"
        "leal (%ebx, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_GetMG42Anims\n"
        "testl %eax, %eax\n" /* line 1174 */
        "je .Lf1628ca_001629ec\n"
        "movl $CG_AllocAnimTree, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimCreateTree\n"
        "movl %eax, %edx\n"
        "jmp .Lf1628ca_0016293e\n"
        /* } scope */
        ".Lf1628ca_001629e5:\n"
        "xorl %ebx, %ebx\n" /* line 1166 | pDObj */
        "jmp .Lf1628ca_0016290b\n"
        /* { scope 2 */
        ".Lf1628ca_001629ec:\n"
        "xorl %edx, %edx\n" /* line 1174 */
        "jmp .Lf1628ca_0016293e\n"
    );
}

/* line 1247 */
__attribute__((naked))
long unsigned int CG_DObjCalcPose(const centity_t *cent, const struct DObj_s *obj, int *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1247 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cent */
        "movl 0xc(%ebp), %edi\n" /* obj */
        "movl 0x10(%ebp), %edx\n" /* partBits */
        /* { scope 1: es, obj */
        "leal -0x28(%ebp), %esi\n" /* line 1254 | completePartBits */
        "movl (%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* completePartBits */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* line 1260 */
        "movl %edi, (%esp)\n" /* obj */
        "calll DObjCompleteHierarchyBits\n"
        "movl 0x220(%ebx), %eax\n" /* line 1261 | cent */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* obj */
        "calll CL_DObjCreateSkelForBones\n"
        "testl %eax, %eax\n"
        "je .Lf1629f4_00162a4e\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: es, obj */
        ".Lf1629f4_00162a4e:\n"
        "movl %esi, 4(%esp)\n" /* line 1269 */
        "movl %edi, (%esp)\n" /* obj */
        "calll DObjCalcAnim\n"
        "movl 0xf4(%ebx), %eax\n" /* line 1228 */
        "cmpl $1, %eax\n"
        "je .Lf1629f4_00162a82\n"
        "cmpl $9, %eax\n"
        "je .Lf1629f4_00162afd\n"
        ".Lf1629f4_00162a6e:\n"
        "movl %esi, 4(%esp)\n" /* line 1271 */
        "movl %edi, (%esp)\n" /* obj */
        "calll DObjCalcSkel\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: es, obj */
        /* { scope 2 */
        ".Lf1629f4_00162a82:\n"
        "leal 0xf0(%ebx), %eax\n" /* line 1206 */
        "movl %eax, -0x30(%ebp)\n" /* es */
        "movl 0x220(%ebx), %eax\n" /* line 1207 */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, -0x2c(%ebp)\n" /* obj */
        "movl imp_cg, %eax\n" /* line 1210 */
        "movl (%eax), %ebx\n"
        "movl -0x30(%ebp), %eax\n" /* es */
        "movl 0x90(%eax), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0900(%ebx, %eax, 8), %eax\n"
        "leal 0x14(%eax), %edx\n"
        "movl 0x14(%eax), %eax\n" /* line 1211 */
        "testl %eax, %eax\n"
        "je .Lf1629f4_00162a6e\n"
        "movl 0x25bac(%ebx), %eax\n" /* line 1214 */
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* es */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll BG_Player_DoControllers\n"
        "jmp .Lf1629f4_00162a6e\n"
        /* } scope */
        ".Lf1629f4_00162afd:\n"
        "movl %esi, %edx\n" /* line 1234 */
        "movl %ebx, %eax\n"
        "calll CG_mg42_DoControllers\n"
        "jmp .Lf1629f4_00162a6e\n"
    );
}

/* line 1284 */
__attribute__((naked))
long unsigned int CG_DObjCalcBone(const centity_t *cent, struct DObj_s *obj, int boneIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1284 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cent */
        "movl 0xc(%ebp), %edi\n" /* obj */
        "movl 0x10(%ebp), %esi\n" /* boneIndex */
        /* { scope 1: obj */
        "movl 0x220(%ebx), %eax\n" /* line 1295 | cent */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* boneIndex */
        "movl %edi, (%esp)\n" /* obj */
        "calll CL_DObjCreateSkelForBone\n"
        "testl %eax, %eax\n"
        "je .Lf162b0c_00162b40\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1311 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: obj */
        ".Lf162b0c_00162b40:\n"
        "leal -0x28(%ebp), %eax\n" /* line 1303 | partBits */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* boneIndex */
        "movl %edi, (%esp)\n" /* obj */
        "calll DObjGetHierarchyBits\n"
        "leal -0x28(%ebp), %eax\n" /* line 1304 | partBits */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* obj */
        "calll DObjCalcAnim\n"
        "movl 0xf4(%ebx), %eax\n" /* line 1228 */
        "cmpl $1, %eax\n"
        "je .Lf162b0c_00162b8d\n"
        "cmpl $9, %eax\n"
        "je .Lf162b0c_00162c02\n"
        ".Lf162b0c_00162b76:\n"
        "leal -0x28(%ebp), %eax\n" /* line 1306 | partBits */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* obj */
        "calll DObjCalcSkel\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1311 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: obj */
        /* { scope 2 */
        ".Lf162b0c_00162b8d:\n"
        "leal 0xf0(%ebx), %esi\n" /* line 1206 | es */
        "movl 0x220(%ebx), %eax\n" /* line 1207 */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, -0x2c(%ebp)\n" /* obj */
        "movl imp_cg, %eax\n" /* line 1210 */
        "movl (%eax), %ebx\n"
        "movl 0x90(%esi), %edx\n" /* es */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0900(%ebx, %eax, 8), %eax\n"
        "leal 0x14(%eax), %edx\n"
        "movl 0x14(%eax), %eax\n" /* line 1211 */
        "testl %eax, %eax\n"
        "je .Lf162b0c_00162b76\n"
        "movl 0x25bac(%ebx), %eax\n" /* line 1214 */
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* partBits */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* es */
        "movl -0x2c(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll BG_Player_DoControllers\n"
        "jmp .Lf162b0c_00162b76\n"
        /* } scope */
        ".Lf162b0c_00162c02:\n"
        "leal -0x28(%ebp), %edx\n" /* line 1234 | partBits */
        "movl %ebx, %eax\n"
        "calll CG_mg42_DoControllers\n"
        "jmp .Lf162b0c_00162b76\n"
    );
}

/* line 698 */
__attribute__((naked))
DObjAnimMat * CG_DObjGetLocalTagMatrix(const centity_t *cent, struct DObj_s *obj, unsigned int tagName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 698 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* obj */
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 706 | tagName */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjGetBoneIndex\n"
        "movl %eax, %ebx\n" /* boneIndex */
        "testl %eax, %eax\n" /* line 707 */
        "jns .Lf162c12_00162c3b\n"
        ".Lf162c12_00162c32:\n"
        "xorl %eax, %eax\n" /* line 715 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 716 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf162c12_00162c3b:\n"
        "movl %eax, 8(%esp)\n" /* line 711 */
        "movl %esi, 4(%esp)\n" /* obj */
        "movl 8(%ebp), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CG_DObjCalcBone\n"
        "movl %esi, (%esp)\n" /* line 714 | obj */
        "calll DObjGetRotTransArray\n"
        "testl %eax, %eax\n" /* line 715 */
        "je .Lf162c12_00162c32\n"
        "shll $5, %ebx\n" /* boneIndex */
        "addl %ebx, %eax\n" /* boneIndex */
        /* } scope */
        "addl $0x10, %esp\n" /* line 716 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 753 */
__attribute__((naked))
qboolean CG_DObjGetWorldTagPos(const centity_t *cent, struct DObj_s *obj, unsigned int tagName, vec_t *pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 753 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* cent */
        "movl 0xc(%ebp), %esi\n" /* obj */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x10(%ebp), %eax\n" /* line 706 | tagName */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll DObjGetBoneIndex\n"
        "movl %eax, %ebx\n" /* boneIndex */
        "testl %eax, %eax\n" /* line 707 */
        "js .Lf162c66_00162d02\n"
        "movl %eax, 8(%esp)\n" /* line 711 */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CG_DObjCalcBone\n"
        "movl %esi, (%esp)\n" /* line 714 */
        "calll DObjGetRotTransArray\n"
        "testl %eax, %eax\n" /* line 715 */
        "je .Lf162c66_00162d02\n"
        "shll $5, %ebx\n" /* boneIndex */
        /* } scope */
        "movl %eax, %esi\n" /* line 762 | mat */
        "addl %ebx, %esi\n" /* boneIndex, mat */
        "je .Lf162c66_00162d02\n"
        "leal -0x48(%ebp), %ebx\n" /* line 764 | ent_axis, boneIndex */
        "movl %ebx, 4(%esp)\n" /* boneIndex */
        "leal 0x1f8(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x1ec(%edi), %edx\n" /* line 765 | cent, from */
        /* { scope 2 */
        "movl 0x1ec(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 766 | pos */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* boneIndex */
        "leal 0x10(%esi), %eax\n" /* mat */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector43\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 768 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf162c66_00162d02:\n"
        "xorl %eax, %eax\n" /* line 767 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 768 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 69 */
__attribute__((naked))
long unsigned int CG_General(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %esi\n" /* cent */
        /* { scope 1 */
        "leal 0xf0(%esi), %ebx\n" /* line 75 | cent, s1 */
        "testb $0x20, 8(%ebx)\n" /* line 78 | s1 */
        "je .Lf162d0c_00162d32\n"
        /* } scope */
        ".Lf162d0c_00162d27:\n"
        "addl $0xac, %esp\n" /* line 98 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf162d0c_00162d32:\n"
        "movl imp_cgs, %eax\n" /* line 81 */
        "movl (%eax), %edx\n"
        "movl 0x8c(%ebx), %eax\n" /* s1 */
        "movl 0x63c0(%edx, %eax, 4), %ecx\n"
        "movl 4(%ebx), %edx\n" /* s1 */
        "movl 0xf0(%esi), %eax\n" /* cent */
        "calll CG_PreProcess_GetDObj\n"
        "movl %eax, %edi\n" /* obj */
        "testl %eax, %eax\n" /* line 82 */
        "je .Lf162d0c_00162d27\n"
        "movl $0x74, 8(%esp)\n" /* line 85 */
        "movl $0, 4(%esp)\n"
        "leal -0x8c(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x1ec(%esi), %edx\n" /* line 87 | cent */
        "movl %edx, -0xa8(%ebp)\n"
        "movl 0x1ec(%esi), %eax\n" /* line 199 | cent */
        "movl %eax, -0x50(%ebp)\n"
        "leal 0x1f0(%esi), %eax\n" /* line 200 | cent */
        "movl %eax, -0xa4(%ebp)\n"
        "movl 0x1f0(%esi), %eax\n" /* cent */
        "movl %eax, -0x4c(%ebp)\n"
        "leal 0x1f4(%esi), %edx\n" /* line 201 | cent */
        "movl %edx, -0xa0(%ebp)\n"
        "movl 0x1f4(%esi), %eax\n" /* cent */
        "movl %eax, -0x48(%ebp)\n"
        "leal -0x78(%ebp), %eax\n" /* line 90 */
        "movl %eax, 4(%esp)\n"
        "leal 0x1f8(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl $0, -0x8c(%ebp)\n" /* line 92 | ent */
        "testb $4, 0xf9(%esi)\n" /* line 50 */
        "je .Lf162d0c_00162ea2\n"
        "leal 0x204(%esi), %ecx\n" /* line 52 */
        "movl imp_vec3_origin, %eax\n" /* line 310 */
        "movss 0x204(%esi), %xmm0\n" /* cent */
        "ucomiss (%eax), %xmm0\n"
        "jp .Lf162d0c_00162e01\n"
        "je .Lf162d0c_00162eb8\n"
        ".Lf162d0c_00162e01:\n"
        "leal 0x208(%esi), %eax\n" /* cent */
        "movl %eax, -0x9c(%ebp)\n"
        "leal 0x20c(%esi), %ebx\n" /* cent, s1 */
        "xorl %eax, %eax\n"
        ".Lf162d0c_00162e15:\n"
        "testl %eax, %eax\n" /* line 52 */
        "je .Lf162d0c_00162e39\n"
        "movl -0xa8(%ebp), %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl -0xa4(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl -0xa0(%ebp), %edx\n" /* line 201 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        ".Lf162d0c_00162e39:\n"
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x84(%ebp)\n"
        "movl -0x9c(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x80(%ebp)\n"
        "movl (%ebx), %eax\n" /* line 201 | s1 */
        "movl %eax, -0x7c(%ebp)\n"
        "orl $0x80, -0x88(%ebp)\n" /* line 55 */
        /* { scope 2 */
        ".Lf162d0c_00162e5b:\n"
        "movl %esi, 8(%esp)\n" /* line 1447 | cent */
        "movl %edi, 4(%esp)\n" /* obj */
        "leal -0x8c(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll R_AddRefEntityToScene\n"
        "testl %eax, %eax\n" /* line 1448 */
        "je .Lf162d0c_00162d27\n"
        "movzbl 0x1e1(%esi), %edx\n" /* line 1451 | cent */
        "cmpb $1, %dl\n"
        "je .Lf162d0c_00162ef4\n"
        "cmpb $2, %dl\n" /* line 1456 */
        "jne .Lf162d0c_00162d27\n"
        "movb $0, 0x1e1(%esi)\n" /* line 1458 | cent */
        "movl %eax, (%esp)\n" /* line 1459 */
        "calll R_SkinGfxEntityDelayed\n"
        "jmp .Lf162d0c_00162d27\n"
        /* } scope */
        ".Lf162d0c_00162ea2:\n"
        "leal 0x204(%esi), %edx\n" /* line 59 | v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x204(%esi)\n" /* cent */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "jmp .Lf162d0c_00162e5b\n"
        /* } scope */
        ".Lf162d0c_00162eb8:\n"
        "leal 4(%ecx), %edx\n" /* line 310 */
        "movl %edx, -0x9c(%ebp)\n"
        "movss 4(%ecx), %xmm0\n"
        "ucomiss 4(%eax), %xmm0\n"
        "jp .Lf162d0c_00162eea\n"
        "jne .Lf162d0c_00162eea\n"
        "leal 8(%ecx), %ebx\n" /* s1 */
        "movss 8(%ecx), %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "sete %al\n"
        "setnp %dl\n"
        "andb %dl, %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf162d0c_00162e15\n"
        ".Lf162d0c_00162eea:\n"
        "leal 8(%ecx), %ebx\n" /* s1 */
        "xorl %eax, %eax\n"
        "jmp .Lf162d0c_00162e15\n"
        /* { scope 2 */
        ".Lf162d0c_00162ef4:\n"
        "movb $0, 0x1e1(%esi)\n" /* line 1453 | cent */
        "movl %eax, (%esp)\n" /* line 1454 */
        "calll R_UpdateXModelBoundsDelayed\n"
        "jmp .Lf162d0c_00162d27\n"
    );
}

/* line 143 */
__attribute__((naked))
long unsigned int CG_Item(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 143 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %edi\n" /* cent */
        /* { scope 1 */
        "leal 0xf0(%edi), %esi\n" /* line 152 | cent, obj */
        "movl 0x8c(%esi), %edx\n" /* line 155 | obj */
        "movl imp_bg_numItems, %eax\n"
        "cmpl (%eax), %edx\n"
        "jge .Lf162f08_00163029\n"
        ".Lf162f08_00162f30:\n"
        "testb $0x20, 8(%esi)\n" /* line 159 | obj */
        "jne .Lf162f08_0016300b\n"
        "movl 0x8c(%esi), %ecx\n" /* line 162 | obj */
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl imp_bg_itemlist, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x9c(%ebp)\n" /* item */
        "leal (%ecx, %ecx, 8), %edx\n" /* line 163 */
        "movl imp_cg_items, %eax\n"
        "movl (%eax), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* itemInfo */
        "movl (%ebx), %eax\n" /* line 164 | itemInfo */
        "testl %eax, %eax\n"
        "je .Lf162f08_00163016\n"
        "movl 4(%ebx), %eax\n" /* line 170 | itemInfo */
        "testl %eax, %eax\n"
        "je .Lf162f08_00163068\n"
        ".Lf162f08_00162f77:\n"
        "movl 4(%ebx), %ecx\n" /* line 173 | itemInfo */
        "movl 4(%esi), %edx\n" /* obj */
        "movl 0xf0(%edi), %eax\n" /* cent */
        "calll CG_PreProcess_GetDObj\n"
        "movl %eax, %esi\n" /* obj */
        "testl %eax, %eax\n" /* line 176 */
        "je .Lf162f08_0016300b\n"
        "leal -0x8c(%ebp), %ebx\n" /* line 181 | ent, itemInfo */
        "movl $0x74, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* itemInfo */
        "calll memset\n"
        "leal -0x78(%ebp), %eax\n" /* line 183 */
        "movl %eax, 4(%esp)\n"
        "leal 0x1f8(%edi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x1ec(%edi), %edx\n" /* cent */
        /* { scope 2 */
        "movl 0x1ec(%edi), %eax\n" /* line 199 | cent */
        "movl %eax, -0x50(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x48(%ebp)\n"
        /* } scope */
        "movl $0, -0x8c(%ebp)\n" /* line 186 | ent */
        /* { scope 2 */
        "movl %edi, 8(%esp)\n" /* line 1447 | cent */
        "movl %esi, 4(%esp)\n" /* obj */
        "movl %ebx, (%esp)\n" /* itemInfo */
        "calll R_AddRefEntityToScene\n"
        "testl %eax, %eax\n" /* line 1448 */
        "je .Lf162f08_0016300b\n"
        "movzbl 0x1e1(%edi), %edx\n" /* line 1451 | cent */
        "cmpb $1, %dl\n"
        "je .Lf162f08_00163057\n"
        "cmpb $2, %dl\n" /* line 1456 */
        "je .Lf162f08_00163046\n"
        /* } scope */
        /* } scope */
        ".Lf162f08_0016300b:\n"
        "addl $0xac, %esp\n" /* line 190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf162f08_00163016:\n"
        "movl %ecx, (%esp)\n" /* line 166 */
        "calll CG_RegisterItemVisuals\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf162f08_00163029:\n"
        "movl %edx, 8(%esp)\n" /* line 156 */
        "movl $str_002abd2c, 4(%esp)\n" /* "Bad item index %i on entity" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf162f08_00162f30\n"
        /* { scope 2 */
        ".Lf162f08_00163046:\n"
        "movb $0, 0x1e1(%edi)\n" /* line 1458 | cent */
        "movl %eax, (%esp)\n" /* line 1459 */
        "calll R_SkinGfxEntityDelayed\n"
        "jmp .Lf162f08_0016300b\n"
        ".Lf162f08_00163057:\n"
        "movb $0, 0x1e1(%edi)\n" /* line 1453 | cent */
        "movl %eax, (%esp)\n" /* line 1454 */
        "calll R_UpdateXModelBoundsDelayed\n"
        "jmp .Lf162f08_0016300b\n"
        /* } scope */
        ".Lf162f08_00163068:\n"
        "movl -0x9c(%ebp), %edx\n" /* line 171 | item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl $str_002abd4c, 4(%esp)\n" /* "No XModel loaded for item index %i (%s)" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf162f08_00162f77\n"
    );
}

/* line 386 */
__attribute__((naked))
long unsigned int CG_Missile(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 386 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        /* { scope 1: bolt */
        "movl 8(%ebp), %esi\n" /* line 393 | cent, obj */
        "addl $0xf0, %esi\n" /* obj */
        "testb $0x20, 8(%esi)\n" /* line 396 | obj */
        "jne .Lf163092_001630bf\n"
        "movl imp_cg, %eax\n" /* line 400 */
        "movl (%eax), %edx\n"
        "movl 0x54(%esi), %eax\n" /* obj */
        "cmpl 0x25bb0(%edx), %eax\n"
        "jle .Lf163092_001630ca\n"
        /* } scope */
        ".Lf163092_001630bf:\n"
        "addl $0xbc, %esp\n" /* line 449 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bolt */
        ".Lf163092_001630ca:\n"
        "movl 0xc8(%esi), %ebx\n" /* line 403 | obj */
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n"
        "jg .Lf163092_00163254\n"
        ".Lf163092_001630dd:\n"
        "movl 0xc8(%esi), %edx\n" /* line 406 | obj */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x9c(%ebp)\n" /* weapInfo */
        "movl 0xd4(%eax), %eax\n" /* line 409 */
        "testl %eax, %eax\n"
        "je .Lf163092_00163129\n"
        "movl %eax, 8(%esp)\n" /* line 410 */
        "movl 8(%ebp), %edi\n" /* cent */
        "addl $0x1ec, %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cent */
        "movl 0xf0(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        ".Lf163092_00163129:\n"
        "movl -0x9c(%ebp), %ebx\n" /* line 412 | weapInfo */
        "movl 0x140(%ebx), %ecx\n"
        "movl 4(%esi), %edx\n" /* obj */
        "movl 8(%ebp), %ebx\n" /* cent */
        "movl 0xf0(%ebx), %eax\n"
        "calll CG_PreProcess_GetDObj\n"
        "movl %eax, %esi\n" /* obj */
        "testl %eax, %eax\n" /* line 413 */
        "je .Lf163092_001630bf\n"
        "movl -0x9c(%ebp), %eax\n" /* line 417 | weapInfo */
        "movl 0x16c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf163092_001632fa\n"
        /* { scope 2 */
        "cmpb $0, 0x1e3(%ebx)\n" /* line 421 */
        "je .Lf163092_00163263\n"
        "movl 8(%ebp), %edx\n" /* cent */
        "leal 0x1ec(%edx), %edi\n"
        /* } scope */
        ".Lf163092_0016317a:\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 433 | weapInfo */
        "movss 0x148(%ecx), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf163092_001632c9\n"
        "jne .Lf163092_001632c9\n"
        ".Lf163092_0016319b:\n"
        "leal -0x94(%ebp), %ebx\n" /* line 437 | ent */
        "movl $0x74, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        "movl 8(%ebp), %edx\n" /* line 199 | cent */
        "movl 0x1ec(%edx), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x54(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x50(%ebp)\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 440 | weapInfo */
        "movl 0x158(%ecx), %eax\n"
        "orl $0x40, %eax\n"
        "movl %eax, -0x90(%ebp)\n"
        "leal -0x80(%ebp), %eax\n" /* line 442 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, %eax\n"
        "addl $0x1f8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl $0, -0x94(%ebp)\n" /* line 444 | ent */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 1447 | cent */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* obj */
        "movl %ebx, (%esp)\n"
        "calll R_AddRefEntityToScene\n"
        "testl %eax, %eax\n" /* line 1448 */
        "je .Lf163092_001630bf\n"
        "movl 8(%ebp), %ecx\n" /* line 1451 | cent */
        "movzbl 0x1e1(%ecx), %edx\n"
        "cmpb $1, %dl\n"
        "je .Lf163092_00163315\n"
        "cmpb $2, %dl\n" /* line 1456 */
        "jne .Lf163092_001630bf\n"
        "movl 8(%ebp), %ebx\n" /* line 1458 | cent */
        "movb $0, 0x1e1(%ebx)\n"
        "movl %eax, (%esp)\n" /* line 1459 */
        "calll R_SkinGfxEntityDelayed\n"
        "jmp .Lf163092_001630bf\n"
        /* } scope */
        ".Lf163092_00163254:\n"
        "movl $0, 0xc8(%esi)\n" /* line 404 | obj */
        "jmp .Lf163092_001630dd\n"
        /* { scope 2 */
        ".Lf163092_00163263:\n"
        "movl 0xf0(%ebx), %edx\n" /* line 423 */
        "movl %edx, -0x20(%ebp)\n" /* bolt */
        "movl imp_scr_const, %eax\n" /* line 424 */
        "movzwl 0xa2(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FX_GetBoneIndex\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n" /* line 425 */
        "js .Lf163092_00163308\n"
        "leal -0x20(%ebp), %eax\n" /* line 426 | bolt */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %ebx, %edi\n"
        "addl $0x1ec, %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl -0x9c(%ebp), %edx\n" /* weapInfo */
        "movl 0x16c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_PlayEntityEffect\n"
        "movl 8(%ebp), %ebx\n" /* cent */
        ".Lf163092_001632bd:\n"
        "movb $1, 0x1e3(%ebx)\n" /* line 428 */
        "jmp .Lf163092_0016317a\n"
        /* } scope */
        ".Lf163092_001632c9:\n"
        "movl 0x154(%ecx), %eax\n" /* line 434 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x150(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14c(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CL_AddLightToScene\n"
        "jmp .Lf163092_0016319b\n"
        ".Lf163092_001632fa:\n"
        "movl 8(%ebp), %eax\n" /* cent */
        "leal 0x1ec(%eax), %edi\n"
        "jmp .Lf163092_0016317a\n"
        ".Lf163092_00163308:\n"
        "movl 8(%ebp), %ecx\n" /* cent */
        "leal 0x1ec(%ecx), %edi\n"
        "movl %ecx, %ebx\n"
        "jmp .Lf163092_001632bd\n"
        /* { scope 2 */
        ".Lf163092_00163315:\n"
        "movb $0, 0x1e1(%ecx)\n" /* line 1453 */
        "movl %eax, (%esp)\n" /* line 1454 */
        "calll R_UpdateXModelBoundsDelayed\n"
        "jmp .Lf163092_001630bf\n"
    );
}

/* line 457 */
__attribute__((naked))
long unsigned int CG_ScriptMover(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 457 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %esi\n" /* cent */
        /* { scope 1 */
        "leal 0xf0(%esi), %ebx\n" /* line 464 | cent, s1 */
        "testb $0x20, 8(%ebx)\n" /* line 467 | s1 */
        "je .Lf16332a_00163350\n"
        /* } scope */
        ".Lf16332a_00163345:\n"
        "addl $0xac, %esp\n" /* line 503 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16332a_00163350:\n"
        "movl $0x74, 8(%esp)\n" /* line 471 */
        "movl $0, 4(%esp)\n"
        "leal -0x8c(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x1ec(%esi), %edx\n" /* line 473 | cent */
        "movl %edx, -0xa8(%ebp)\n"
        "movl 0x1ec(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x50(%ebp)\n"
        "leal 0x1f0(%esi), %eax\n" /* line 200 */
        "movl %eax, -0xa4(%ebp)\n"
        "movl 0x1f0(%esi), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "leal 0x1f4(%esi), %edx\n" /* line 201 */
        "movl %edx, -0xa0(%ebp)\n"
        "movl 0x1f4(%esi), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "leal -0x78(%ebp), %eax\n" /* line 474 */
        "movl %eax, 4(%esp)\n"
        "leal 0x1f8(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl $0x40, -0x88(%ebp)\n" /* line 475 */
        "cmpl $0x00FFFFFF, 0x9c(%ebx)\n" /* line 477 | s1 */
        "je .Lf16332a_001634f8\n"
        "movl imp_cgs, %eax\n" /* line 479 */
        "movl (%eax), %edx\n"
        "movl 0x8c(%ebx), %eax\n" /* s1 */
        "movl 0x63c0(%edx, %eax, 4), %ecx\n"
        "movl 4(%ebx), %edx\n" /* s1 */
        "movl 0xf0(%esi), %eax\n" /* cent */
        "calll CG_PreProcess_GetDObj\n"
        "movl %eax, %edi\n" /* obj */
        "testl %eax, %eax\n" /* line 480 */
        "je .Lf16332a_00163345\n"
        "movl $0, -0x8c(%ebp)\n" /* line 483 | ent */
        "testb $4, 0xf9(%esi)\n" /* line 50 */
        "je .Lf16332a_001634e2\n"
        "leal 0x204(%esi), %ecx\n" /* line 52 */
        "movl imp_vec3_origin, %eax\n" /* line 310 */
        "movss 0x204(%esi), %xmm0\n"
        "ucomiss (%eax), %xmm0\n"
        "jp .Lf16332a_0016343d\n"
        "je .Lf16332a_0016353b\n"
        ".Lf16332a_0016343d:\n"
        "leal 0x208(%esi), %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        "leal 0x20c(%esi), %ebx\n"
        "xorl %eax, %eax\n"
        ".Lf16332a_00163451:\n"
        "testl %eax, %eax\n" /* line 52 */
        "je .Lf16332a_00163475\n"
        "movl -0xa8(%ebp), %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl -0xa4(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl -0xa0(%ebp), %edx\n" /* line 201 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        ".Lf16332a_00163475:\n"
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x84(%ebp)\n"
        "movl -0x9c(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x80(%ebp)\n"
        "movl (%ebx), %eax\n" /* line 201 */
        "movl %eax, -0x7c(%ebp)\n"
        "orl $0x80, -0x88(%ebp)\n" /* line 55 */
        /* { scope 2 */
        ".Lf16332a_00163497:\n"
        "movl %esi, 8(%esp)\n" /* line 1447 | cent */
        "movl %edi, 4(%esp)\n" /* obj */
        "leal -0x8c(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll R_AddRefEntityToScene\n"
        "testl %eax, %eax\n" /* line 1448 */
        "je .Lf16332a_00163345\n"
        "movzbl 0x1e1(%esi), %edx\n" /* line 1451 | cent */
        "cmpb $1, %dl\n"
        "je .Lf16332a_00163577\n"
        "cmpb $2, %dl\n" /* line 1456 */
        "jne .Lf16332a_00163345\n"
        "movb $0, 0x1e1(%esi)\n" /* line 1458 | cent */
        "movl %eax, (%esp)\n" /* line 1459 */
        "calll R_SkinGfxEntityDelayed\n"
        "jmp .Lf16332a_00163345\n"
        /* } scope */
        ".Lf16332a_001634e2:\n"
        "leal 0x204(%esi), %edx\n" /* line 59 | v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x204(%esi)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "jmp .Lf16332a_00163497\n"
        /* } scope */
        ".Lf16332a_001634f8:\n"
        "movl $3, -0x8c(%ebp)\n" /* line 493 | ent */
        "movl imp_cgs, %eax\n" /* line 500 */
        "movl (%eax), %edx\n"
        "movl 0x8c(%ebx), %eax\n" /* s1 */
        "movl 0x718c(%edx, %eax, 4), %eax\n"
        "movl $0, 8(%esp)\n" /* line 501 */
        "movl %eax, 4(%esp)\n"
        "leal -0x8c(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll R_AddRefEntityToScene\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 503 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16332a_0016353b:\n"
        "leal 4(%ecx), %edx\n" /* line 310 */
        "movl %edx, -0x9c(%ebp)\n"
        "movss 4(%ecx), %xmm0\n"
        "ucomiss 4(%eax), %xmm0\n"
        "jp .Lf16332a_0016356d\n"
        "jne .Lf16332a_0016356d\n"
        "leal 8(%ecx), %ebx\n"
        "movss 8(%ecx), %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "sete %al\n"
        "setnp %dl\n"
        "andb %dl, %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf16332a_00163451\n"
        ".Lf16332a_0016356d:\n"
        "leal 8(%ecx), %ebx\n"
        "xorl %eax, %eax\n"
        "jmp .Lf16332a_00163451\n"
        /* { scope 2 */
        ".Lf16332a_00163577:\n"
        "movb $0, 0x1e1(%esi)\n" /* line 1453 | cent */
        "movl %eax, (%esp)\n" /* line 1454 */
        "calll R_UpdateXModelBoundsDelayed\n"
        "jmp .Lf16332a_00163345\n"
    );
}

/* line 1361 */
__attribute__((naked))
long unsigned int CG_ProcessEntity(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1361 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %esi\n" /* cent */
        "movl %esi, (%esp)\n" /* line 1364 | cent */
        "calll CG_EntityEffects\n"
        "movl 0xf4(%esi), %eax\n" /* line 1366 | cent */
        "cmpl $9, %eax\n"
        "ja .Lf16358c_00163692\n"
        "jmpl *.Ljt_16358c_0(, %eax, 4)\n"
        /* { scope 1 */
        ".Lf16358c_001635b9:\n"
        "movl imp_cg, %edi\n" /* line 950 | fx */
        "movl (%edi), %ebx\n" /* fx, s1 */
        "movl 0x25bb0(%ebx), %eax\n" /* s1 */
        "movl 0x210(%esi), %edx\n"
        "cmpl %edx, %eax\n"
        "jge .Lf16358c_00163802\n"
        "movl %eax, 0x210(%esi)\n" /* line 965 */
        ".Lf16358c_001635db:\n"
        "movss 0x158(%esi), %xmm0\n" /* line 968 */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 969 | 0.0f */
        "jp .Lf16358c_0016382e\n"
        "jne .Lf16358c_0016382e\n"
        ".Lf16358c_001635f6:\n"
        "movl 0x1c8(%esi), %edx\n" /* line 972 */
        "leal -1(%edx), %eax\n" /* line 973 */
        "cmpl $0x3e, %eax\n"
        "ja .Lf16358c_00163877\n"
        "movl imp_cgs, %eax\n" /* line 978 */
        "movl (%eax), %eax\n"
        "movl 0x67c0(%eax, %edx, 4), %edi\n" /* fx */
        "leal 0x14c(%esi), %eax\n" /* line 980 */
        "movl %eax, -0x9c(%ebp)\n"
        "movss 0x14c(%esi), %xmm0\n" /* line 316 */
        "movss 0x150(%esi), %xmm1\n"
        "movss 0x154(%esi), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 980 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf16358c_0016365d\n"
        "je .Lf16358c_00163959\n"
        ".Lf16358c_0016365d:\n"
        "movl 0x190(%esi), %eax\n" /* line 982 */
        "testl %eax, %eax\n"
        "jne .Lf16358c_0016388c\n"
        "movl -0x9c(%ebp), %eax\n" /* line 984 */
        "movl %eax, 8(%esp)\n"
        "leal 0x1ec(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* fx */
        "calll FX_PlayEffect\n"
        /* } scope */
        ".Lf16358c_00163687:\n"
        "addl $0xbc, %esp\n" /* line 1402 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf16358c_00163692:\n"
        "movl %eax, 8(%esp)\n" /* line 1369 */
        "movl $str_002abd78, 4(%esp)\n" /* "Bad entity type: %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "addl $0xbc, %esp\n" /* line 1402 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf16358c_001636b5:\n"
        "movl %esi, (%esp)\n" /* line 1377 | cent */
        "calll CG_General\n"
        "jmp .Lf16358c_00163687\n"
        /* { scope 1 */
        ".Lf16358c_001636bf:\n"
        "leal 0xf0(%esi), %ebx\n" /* line 353 | s1 */
        "testb $0x20, 8(%ebx)\n" /* line 356 | s1 */
        "jne .Lf16358c_00163687\n"
        "movl imp_cgs, %eax\n" /* line 359 */
        "movl (%eax), %edx\n"
        "movl 0x8c(%ebx), %eax\n" /* s1 */
        "movl 0x63c0(%edx, %eax, 4), %ecx\n"
        "movl 4(%ebx), %edx\n" /* s1 */
        "movl 0xf0(%esi), %eax\n"
        "calll CG_PreProcess_GetDObj\n"
        "movl %eax, %edi\n" /* obj */
        "testl %eax, %eax\n" /* line 360 */
        "je .Lf16358c_00163687\n"
        "leal -0x8c(%ebp), %ebx\n" /* line 363 | up, s1 */
        "movl $0x74, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* s1 */
        "calll memset\n"
        "leal 0x1ec(%esi), %eax\n"
        /* { scope 2 */
        "movl 0x1ec(%esi), %ecx\n" /* line 199 */
        "movl %ecx, -0x50(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0x4c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x48(%ebp)\n"
        /* } scope */
        "movl %ecx, -0x84(%ebp)\n" /* line 199 */
        "movl %edx, -0x80(%ebp)\n" /* line 200 */
        "addss lit4_002ed830, %xmm0\n" /* line 368 | 32.0f */
        "movss %xmm0, -0x7c(%ebp)\n"
        "movl $0x80, -0x88(%ebp)\n" /* line 369 */
        "leal -0x78(%ebp), %eax\n" /* line 371 */
        "movl %eax, 4(%esp)\n"
        "leal 0x1f8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl $0, -0x8c(%ebp)\n" /* line 373 | up */
        /* { scope 2 */
        "movl %esi, 8(%esp)\n" /* line 1447 | cent */
        "movl %edi, 4(%esp)\n" /* fx */
        "movl %ebx, (%esp)\n" /* s1 */
        "calll R_AddRefEntityToScene\n"
        "testl %eax, %eax\n" /* line 1448 */
        "je .Lf16358c_00163687\n"
        "movzbl 0x1e1(%esi), %edx\n" /* line 1451 | cent */
        "cmpb $1, %dl\n"
        "je .Lf16358c_00163970\n"
        "cmpb $2, %dl\n" /* line 1456 */
        "jne .Lf16358c_00163687\n"
        "movb $0, 0x1e1(%esi)\n" /* line 1458 | cent */
        "movl %eax, (%esp)\n" /* line 1459 */
        "calll R_SkinGfxEntityDelayed\n"
        "jmp .Lf16358c_00163687\n"
        /* } scope */
        /* } scope */
        ".Lf16358c_001637b4:\n"
        "movl %esi, (%esp)\n" /* line 1395 | cent */
        "calll CG_SoundBlend\n"
        "jmp .Lf16358c_00163687\n"
        ".Lf16358c_001637c1:\n"
        "movl %esi, (%esp)\n" /* line 1392 | cent */
        "calll CG_ScriptMover\n"
        "jmp .Lf16358c_00163687\n"
        ".Lf16358c_001637ce:\n"
        "movl %esi, (%esp)\n" /* line 1389 | cent */
        "calll CG_Missile\n"
        "jmp .Lf16358c_00163687\n"
        ".Lf16358c_001637db:\n"
        "movl %esi, (%esp)\n" /* line 1386 | cent */
        "calll CG_Item\n"
        "jmp .Lf16358c_00163687\n"
        ".Lf16358c_001637e8:\n"
        "movl %esi, (%esp)\n" /* line 1383 | cent */
        "calll CG_Corpse\n"
        "jmp .Lf16358c_00163687\n"
        ".Lf16358c_001637f5:\n"
        "movl %esi, (%esp)\n" /* line 1380 | cent */
        "calll CG_Player\n"
        "jmp .Lf16358c_00163687\n"
        /* { scope 1 */
        ".Lf16358c_00163802:\n"
        "cvttss2si 0x15c(%esi), %ecx\n" /* line 952 */
        "subl %edx, %eax\n" /* line 954 */
        "cmpl %eax, %ecx\n"
        "jg .Lf16358c_00163687\n"
        ".Lf16358c_00163814:\n"
        "leal (%ecx, %edx), %edx\n" /* line 958 */
        "movl %edx, 0x210(%esi)\n"
        "movl 0x25bb0(%ebx), %eax\n" /* line 956 | s1 */
        "subl %edx, %eax\n"
        "cmpl %eax, %ecx\n"
        "jle .Lf16358c_00163814\n"
        "jmp .Lf16358c_001635db\n"
        ".Lf16358c_0016382e:\n"
        "leal 0x1ec(%esi), %eax\n" /* line 969 */
        "movl %eax, 4(%esp)\n"
        "movl (%edi), %eax\n" /* fx */
        "addl $0x25bd8, %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0xa0(%ebp)\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "movss -0xa0(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16358c_001635f6\n"
        "jmp .Lf16358c_00163687\n"
        ".Lf16358c_00163877:\n"
        "movl %edx, 4(%esp)\n" /* line 975 */
        "movl $str_002abd90, (%esp)\n" /* "ERROR: CG_PlayFx called with invalid effect id %i
" */
        "calll Com_Printf\n"
        "jmp .Lf16358c_00163687\n"
        ".Lf16358c_0016388c:\n"
        "leal -0x8c(%ebp), %ebx\n" /* line 988 | up, s1 */
        "movl %ebx, 4(%esp)\n" /* s1 */
        "movl %eax, (%esp)\n"
        "calll ByteToDir\n"
        "movss -0x8c(%ebp), %xmm2\n" /* line 304 | up */
        "movaps %xmm2, %xmm1\n" /* line 990 | scale */
        "mulss 0x14c(%esi), %xmm1\n" /* scale */
        "movss 0x150(%esi), %xmm0\n"
        "mulss -0x88(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n" /* scale */
        "movss 0x154(%esi), %xmm0\n"
        "mulss -0x84(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n" /* scale */
        "xorps boxVerts+288, %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x14c(%esi), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x8c(%ebp)\n" /* up */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x150(%esi), %xmm0\n"
        "addss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "mulss 0x154(%esi), %xmm1\n" /* line 290 */
        "addss -0x84(%ebp), %xmm1\n"
        "movss %xmm1, -0x84(%ebp)\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 991 | s1 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl %ebx, 0xc(%esp)\n" /* line 992 | s1 */
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x1ec(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* fx */
        "calll FX_PlayEffect\n"
        "jmp .Lf16358c_00163687\n"
        ".Lf16358c_00163959:\n"
        "leal 0x1ec(%esi), %eax\n" /* line 997 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* fx */
        "calll FX_PlaySimpleEffect\n"
        "jmp .Lf16358c_00163687\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf16358c_00163970:\n"
        "movb $0, 0x1e1(%esi)\n" /* line 1453 | cent */
        "movl %eax, (%esp)\n" /* line 1454 */
        "calll R_UpdateXModelBoundsDelayed\n"
        "jmp .Lf16358c_00163687\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_16358c_0:\n"
        ".long .Lf16358c_001636b5\n"
        ".long .Lf16358c_001637f5\n"
        ".long .Lf16358c_001637e8\n"
        ".long .Lf16358c_001637db\n"
        ".long .Lf16358c_001637ce\n"
        ".long .Lf16358c_00163687\n"
        ".long .Lf16358c_001637c1\n"
        ".long .Lf16358c_001637b4\n"
        ".long .Lf16358c_001635b9\n"
        ".long .Lf16358c_001636bf\n"
        ".text\n"
    );
}

/* line 629 */
__attribute__((naked))
long unsigned int CG_AddPacketEntities(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 629 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %edi\n" /* line 638 */
        "movl (%edi), %ebx\n" /* num */
        "xorl %esi, %esi\n"
        "movl %esi, 0x2c5a0(%ebx)\n" /* num */
        "movl %esi, 0x284e0(%ebx)\n" /* line 641 | num */
        "movl 0x25bb0(%ebx), %ecx\n" /* line 642 | num */
        "movl %ecx, %eax\n"
        "andl $0xfff, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "shll $3, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "divss lit4_002ed8f8, %xmm0\n" /* 4095.0f */
        "movss %xmm0, 0x284e4(%ebx)\n" /* num */
        "movl %esi, 0x284e8(%ebx)\n" /* line 643 | num */
        "movl %esi, 0x28510(%ebx)\n" /* line 645 | num */
        "movl %ecx, %eax\n" /* line 646 */
        "andl $0x7ff, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "shll $3, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss lit4_002ed8fc, %xmm0\n" /* 0.00048828125f */
        "movss %xmm0, 0x28514(%ebx)\n" /* num */
        "movl %esi, 0x28518(%ebx)\n" /* line 647 | num */
        "movl %esi, 0x28540(%ebx)\n" /* line 649 | num */
        "andl $0x3ff, %ecx\n" /* line 650 */
        "leal (%ecx, %ecx, 2), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "shll $3, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed60c, %xmm0\n" /* 0.0009765625f */
        "movss %xmm0, 0x28544(%ebx)\n" /* num */
        "movl %esi, 0x28548(%ebx)\n" /* line 651 | num */
        "leal 0x284ec(%ebx), %eax\n" /* line 653 | num */
        "movl %eax, 4(%esp)\n"
        "leal 0x284e0(%ebx), %eax\n" /* num */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x2851c(%ebx), %eax\n" /* line 654 | num */
        "movl %eax, 4(%esp)\n"
        "leal 0x28510(%ebx), %eax\n" /* num */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x2854c(%ebx), %eax\n" /* line 655 | num */
        "movl %eax, 4(%esp)\n"
        "leal 0x28540(%ebx), %eax\n" /* num */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl 0x26158(%ebx), %eax\n" /* line 657 | num */
        "movl %eax, -0x1c(%ebp)\n" /* viewlocked_entNum */
        "movl 0x24(%ebx), %eax\n" /* line 660 | num */
        "movl 0x26b4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf163984_00163b00\n"
        "xorl %ebx, %ebx\n" /* num */
        "xorl %esi, %esi\n"
        "jmp .Lf163984_00163ab8\n"
        ".Lf163984_00163aa2:\n"
        "addl $1, %ebx\n" /* num */
        "addl $0xf0, %esi\n"
        "movl (%edi), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "cmpl %ebx, 0x26b4(%eax)\n" /* num */
        "jle .Lf163984_00163b00\n"
        ".Lf163984_00163ab8:\n"
        "movl 0x26bc(%esi, %eax), %edx\n" /* line 662 */
        "cmpl %edx, -0x1c(%ebp)\n" /* line 663 | viewlocked_entNum */
        "je .Lf163984_00163aa2\n"
        "movl %edx, %eax\n" /* line 666 */
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl imp_cg_entities, %ecx\n"
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "cmpl $9, 0xf4(%eax)\n" /* line 671 */
        "jg .Lf163984_00163aa2\n"
        "movl %eax, (%esp)\n" /* line 673 */
        "calll CG_ProcessEntity\n"
        "addl $1, %ebx\n" /* line 660 | num */
        "addl $0xf0, %esi\n"
        "movl (%edi), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "cmpl %ebx, 0x26b4(%eax)\n" /* num */
        "jg .Lf163984_00163ab8\n"
        /* } scope */
        ".Lf163984_00163b00:\n"
        "addl $0x2c, %esp\n" /* line 677 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

#else
static long unsigned int CG_mg42_DoControllers(const centity_t *cent, int *partBits) { return 0; }
#endif
