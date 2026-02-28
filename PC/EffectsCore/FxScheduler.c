/* ASM dump from: FxScheduler.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxScheduler.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/FxPrimitives.h"
 *   #include "PC/EffectsCore/FxUtil.h"
 *   #include "PC/EffectsCore/FxMemMgr.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/EffectsCore/FxCurve.h"
 *   #include "PC/EffectsCore/FxChannel.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/EffectsCore/FxArchive.h"
 *   #include "Mac/Tools/MacSwap.h"
 */

extern int irand(int min, int max);

extern FxScheduler * fxSchedulers[1]; /* 0x0 */
static EffectTemplate * effectTemplateArray[256]; /* effectTemplateArray */
static int effectTemplateArrayCount; /* effectTemplateArrayCount */

TMediaElement MediaHandles_GetHandle(const MediaHandles * _this);
void FxScheduler_FxScheduler(const FxScheduler * _this);
float FxScheduler_GetEffectLength(const FxScheduler * _this, EffectTemplate *fx);
void FX_InitTemplates(void);
EffectTemplate * FX_TryRegisterEffect(const char *name);
static void GLOBAL__I__ZN17PrimitiveTemplate8gmMemMgrE(void); /* global constructors keyed to PrimitiveTemplate_gmMemMgr */
Bool FX_GetBoltingFrame(const PrimitiveTemplate *primTemp, const FxBoltInfo *bolt, FxBoltFramePtr *boltFrame);
void FxScheduler_CreateEffect(const FxScheduler * _this, const EffectTemplate *fx, const PrimitiveTemplate *primTemp, const FxBoltInfo *bolt, const vec_t *origin, MediaHandles * (*axis)[4], int lateTime, int indexInBatch);
void FxScheduler_PlayEffect(const FxScheduler * _this, const EffectTemplate *fx, const vec_t *origin, MediaHandles * (*axis)[4], const FxBoltInfo *bolt);
void FxScheduler_Clean(const FxScheduler * _this, int bRemoveTemplates, EffectTemplate *fxToPreserve);
void FxScheduler_GetDecalColor(const FxScheduler * _this, const PrimitiveTemplate *primTemp, vec_t *rgba);
float FxScheduler_GetDecalAlpha(const FxScheduler * _this, const PrimitiveTemplate *primTemp);
float FxScheduler_GetDecalSize(const FxScheduler * _this, const PrimitiveTemplate *primTemp);
EffectTemplate * MediaHandles_GetEffect(const MediaHandles * _this);
void FxScheduler_CreateDecalEffect(const FxScheduler * _this, const PrimitiveTemplate *primTemp, vec_t *org, MediaHandles * (*ax)[4]);
void ScheduledEffect_Archive(const ScheduledEffect * _this, FxArchive *arch);
void FxScheduler_Archive(const FxScheduler * _this, FxArchive *arch);

/* line 75 */
TMediaElement MediaHandles_GetHandle(const MediaHandles * _this)
{
    unsigned short count = *(unsigned short *)((byte *)_this + 4);
    TMediaElement result;
    TMediaElement *elements;

    if (!count) {
        result.data = NULL;
        return result;
    }

    elements = *(TMediaElement **)((byte *)_this);
    return elements[irand(0, count)];
}

/* line 90 */
void FxScheduler_FxScheduler(const FxScheduler * _this)
{
    *(int *)((byte *)_this + 4) = 0;
    *(int *)((byte *)_this + 8) = 0;
}

/* line 459 */
float FxScheduler_GetEffectLength(const FxScheduler * _this, EffectTemplate *fx)
{
    int count = *(int *)((byte *)fx + 4);
    float maxLen = 0.0f;
    int i;

    for (i = 0; i < count; i++) {
        PrimitiveTemplate *prim = *(PrimitiveTemplate **)((byte *)fx + 8 + i * 4);
        float len = *(float *)((byte *)prim + 0x4c) + *(float *)((byte *)prim + 0x5c);
        if (len > maxLen)
            maxLen = len;
    }

    return maxLen;
}

/* line 789 */
void FX_InitTemplates(void)
{
    effectTemplateArrayCount = 0;
}

/* line 834 */
__attribute__((naked))
EffectTemplate * FX_TryRegisterEffect(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 834 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "leal -0x50(%ebp), %eax\n" /* line 838 | parser */
        "movl %eax, (%esp)\n"
        "calll GenericParser2_GenericParser2\n"
        /* { scope 2 */
        "movl effectTemplateArrayCount, %eax\n" /* line 803 */
        "movl %eax, -0x5c(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf6164a_00061693\n"
        "xorl %edi, %edi\n" /* effectIndex */
        "movl $effectTemplateArray, %esi\n"
        ".Lf6164a_00061671:\n"
        "movl (%esi), %ebx\n" /* line 805 */
        "movl 8(%ebp), %eax\n" /* line 809 | name */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf6164a_000616c8\n"
        "addl $1, %edi\n" /* line 803 | effectIndex */
        "addl $4, %esi\n"
        "cmpl %edi, -0x5c(%ebp)\n" /* effectIndex */
        "jne .Lf6164a_00061671\n"
        /* } scope */
        ".Lf6164a_00061693:\n"
        "movl 8(%ebp), %eax\n" /* line 846 | name */
        "movl %eax, 4(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* parser */
        "movl %eax, (%esp)\n"
        "calll FX_ParseEffect\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 847 */
        "je .Lf6164a_000616f1\n"
        "movl effectTemplateArrayCount, %eax\n" /* line 822 */
        "cmpl $0x100, %eax\n"
        "je .Lf6164a_000616dd\n"
        "movl %edx, effectTemplateArray(, %eax, 4)\n" /* line 828 */
        "addl $1, %eax\n" /* line 829 */
        "movl %eax, effectTemplateArrayCount\n"
        "movl %edx, %ebx\n" /* line 850 | registeredTemplate */
        ".Lf6164a_000616c8:\n"
        "leal -0x50(%ebp), %eax\n" /* line 853 | parser */
        "movl %eax, (%esp)\n"
        "calll ZN14GenericParser2D1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 854 | registeredTemplate */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6164a_000616dd:\n"
        "movl $0x100, 4(%esp)\n" /* line 824 */
        "movl $str_0021a904, (%esp)\n" /* "^1Max effect templates of '%i' exceeded
" */
        "calll FX_Print\n"
        ".Lf6164a_000616f1:\n"
        "xorl %ebx, %ebx\n" /* line 853 | registeredTemplate */
        "leal -0x50(%ebp), %eax\n" /* parser */
        "movl %eax, (%esp)\n"
        "calll ZN14GenericParser2D1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 854 | registeredTemplate */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* registeredTemplate */
        /* { scope 1 */
        "leal -0x50(%ebp), %eax\n" /* line 853 | parser */
        "movl %eax, (%esp)\n"
        "calll ZN14GenericParser2D1Ev\n"
        "movl %ebx, (%esp)\n" /* registeredTemplate */
        "calll __Unwind_Resume\n"
    );
}

/* line 952 */
static void GLOBAL__I__ZN17PrimitiveTemplate8gmMemMgrE(void) /* global constructors keyed to PrimitiveTemplate_gmMemMgr */
{
}

/* line 580 */
__attribute__((naked))
Bool FX_GetBoltingFrame(const PrimitiveTemplate *primTemp, const FxBoltInfo *bolt, FxBoltFramePtr *boltFrame)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 580 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* bolt */
        "movl 0x10(%ebp), %ebx\n" /* boltFrame */
        "movl 8(%ebp), %eax\n" /* line 585 | primTemp */
        "testb $2, 0x90(%eax)\n"
        "je .Lf61724_000617a0\n"
        "testl %edx, %edx\n"
        "je .Lf61724_000617a0\n"
        "movl (%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "js .Lf61724_000617a0\n"
        "leal -0xc(%ebp), %eax\n" /* line 587 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_Acquire\n"
        "subl $4, %esp\n"
        "movl (%ebx), %eax\n" /* line 78 */
        "cmpl -0xc(%ebp), %eax\n"
        "je .Lf61724_00061779\n"
        "testl %eax, %eax\n" /* line 80 */
        "je .Lf61724_00061772\n"
        "movl %eax, (%esp)\n" /* line 82 */
        "calll FxBoltFrame_Release\n"
        "movl $0, (%ebx)\n" /* line 83 */
        ".Lf61724_00061772:\n"
        "movl -0xc(%ebp), %eax\n" /* line 106 */
        "testl %eax, %eax\n" /* line 85 */
        "jne .Lf61724_000617aa\n"
        ".Lf61724_00061779:\n"
        "testl %eax, %eax\n" /* line 60 */
        "je .Lf61724_00061785\n"
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_Release\n"
        ".Lf61724_00061785:\n"
        "movl (%ebx), %edx\n" /* line 588 | boltFrame */
        "testl %edx, %edx\n"
        "jne .Lf61724_00061792\n"
        ".Lf61724_0006178b:\n"
        "xorl %eax, %eax\n" /* line 591 */
        "movl -4(%ebp), %ebx\n" /* line 598 | boltFrame */
        "leave\n"
        "retl\n"
        ".Lf61724_00061792:\n"
        "movl (%ebx), %eax\n" /* line 591 | boltFrame */
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_GetOrientation\n"
        "testl %eax, %eax\n"
        "je .Lf61724_0006178b\n"
        ".Lf61724_000617a0:\n"
        "movl $1, %eax\n"
        "movl -4(%ebp), %ebx\n" /* line 598 | boltFrame */
        "leave\n"
        "retl\n"
        ".Lf61724_000617aa:\n"
        "addl $1, (%eax)\n" /* line 39 */
        "movl %eax, (%ebx)\n" /* line 86 */
        "movl -0xc(%ebp), %eax\n"
        "jmp .Lf61724_00061779\n"
        "movl %eax, %ebx\n"
        "movl -0xc(%ebp), %eax\n" /* line 60 */
        "testl %eax, %eax\n"
        "je .Lf61724_000617c5\n"
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_Release\n"
        ".Lf61724_000617c5:\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 688 */
__attribute__((naked))
void FxScheduler_CreateEffect(const FxScheduler * _this, const EffectTemplate *fx, const PrimitiveTemplate *primTemp, const FxBoltInfo *bolt, const vec_t *origin, MediaHandles * (*axis)[4], int lateTime, int indexInBatch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 688 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* primTemp */
        /* { scope 1 */
        "movl $0, -0x1c(%ebp)\n" /* line 58 */
        "leal -0x48(%ebp), %esi\n" /* line 695 | ax */
        "movl %esi, 4(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "testb $1, 0x95(%ebx)\n" /* line 605 */
        "je .Lf617ce_00061840\n"
        "movl $0x43b40000, 4(%esp)\n" /* line 607 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "leal -0x3c(%ebp), %edi\n"
        "fstps 0xc(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* axis */
        "addl $0xc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll RotatePointAroundVector\n"
        "leal -0x30(%ebp), %eax\n" /* line 608 */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        ".Lf617ce_00061840:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 699 */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* bolt */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* primTemp */
        "calll FX_GetBoltingFrame\n"
        "testb %al, %al\n"
        "je .Lf617ce_00061869\n"
        "movl 0xc(%ebp), %eax\n" /* line 702 | fx */
        "movl %eax, -0x24(%ebp)\n" /* prim */
        "movl %ebx, -0x20(%ebp)\n" /* line 703 | primTemp */
        "cmpl $0xc, 0x40(%ebx)\n" /* line 631 */
        "jbe .Lf617ce_00061880\n"
        ".Lf617ce_00061869:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 60 */
        "testl %eax, %eax\n"
        "je .Lf617ce_00061878\n"
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_Release\n"
        /* } scope */
        ".Lf617ce_00061878:\n"
        "addl $0x5c, %esp\n" /* line 705 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf617ce_00061880:\n"
        "movl 0x40(%ebx), %eax\n" /* line 631 */
        "jmpl *.Ljt_617ce_0(, %eax, 4)\n"
        ".Lf617ce_0006188a:\n"
        "movl 0x24(%ebp), %eax\n" /* line 634 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddParticle\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_000618b0:\n"
        "movl 0x24(%ebp), %eax\n" /* line 678 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddCloud\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_000618d6:\n"
        "movl 0x24(%ebp), %eax\n" /* line 674 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddFlash\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_000618ff:\n"
        "movl 0x24(%ebp), %eax\n" /* line 670 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddCameraShake\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_00061928:\n"
        "movl 0x24(%ebp), %eax\n" /* line 666 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddLight\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_00061951:\n"
        "movl 0x24(%ebp), %eax\n" /* line 662 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddFxRunner\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_0006197a:\n"
        "movl 0x24(%ebp), %eax\n" /* line 658 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddOrientedParticle\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_000619a3:\n"
        "movl 0x24(%ebp), %eax\n" /* line 654 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddDecal\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_000619cc:\n"
        "movl 0x24(%ebp), %eax\n" /* line 650 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddEmitter\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_000619f5:\n"
        "movl 0x24(%ebp), %eax\n" /* line 646 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddCylinder\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_00061a1e:\n"
        "movl 0x24(%ebp), %eax\n" /* line 642 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddTail\n"
        "jmp .Lf617ce_00061869\n"
        ".Lf617ce_00061a47:\n"
        "movl 0x24(%ebp), %eax\n" /* line 638 | indexInBatch */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* lateTime */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* prim */
        "movl %eax, (%esp)\n"
        "calll FX_AddLine\n"
        "jmp .Lf617ce_00061869\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 60 */
        "testl %eax, %eax\n"
        "je .Lf617ce_00061a81\n"
        "movl %eax, (%esp)\n"
        "calll FxBoltFrame_Release\n"
        ".Lf617ce_00061a81:\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_617ce_0:\n"
        ".long .Lf617ce_00061869\n"
        ".long .Lf617ce_0006188a\n"
        ".long .Lf617ce_00061a47\n"
        ".long .Lf617ce_00061a1e\n"
        ".long .Lf617ce_000619f5\n"
        ".long .Lf617ce_000619cc\n"
        ".long .Lf617ce_000619a3\n"
        ".long .Lf617ce_0006197a\n"
        ".long .Lf617ce_00061951\n"
        ".long .Lf617ce_00061928\n"
        ".long .Lf617ce_000618ff\n"
        ".long .Lf617ce_000618d6\n"
        ".long .Lf617ce_000618b0\n"
        ".text\n"
    );
}

/* line 283 */
__attribute__((naked))
void FxScheduler_PlayEffect(const FxScheduler * _this, const EffectTemplate *fx, const vec_t *origin, MediaHandles * (*axis)[4], const FxBoltInfo *bolt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 283 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        /* { scope 1: t */
        "movl imp_theFxHelper, %ebx\n" /* line 295 | ptr */
        "movl (%ebx), %eax\n" /* ptr */
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetSeed\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl %eax, (%esp)\n" /* line 296 */
        "calll Rand_Init\n"
        "movl 0xc(%ebp), %eax\n" /* line 299 | fx */
        "testl %eax, %eax\n"
        "je .Lf61a8a_00061e68\n"
        ".Lf61a8a_00061abe:\n"
        "movl imp_fx_freeze, %eax\n" /* line 316 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf61a8a_00061e24\n"
        "movl imp_fx_enable, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf61a8a_00061e24\n"
        "movl 0x18(%ebp), %eax\n" /* line 320 | bolt */
        "testl %eax, %eax\n"
        "je .Lf61a8a_00061eb7\n"
        "movl 0x18(%ebp), %ecx\n" /* line 325 | bolt */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf61a8a_00061e24\n"
        "leal -0x48(%ebp), %eax\n" /* line 327 | or_ */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll FX_GetBoneOrientation\n"
        "testb %al, %al\n"
        "je .Lf61a8a_00061e24\n"
        ".Lf61a8a_00061b0f:\n"
        "movl 0xc(%ebp), %eax\n" /* line 362 | fx */
        "movl 4(%eax), %edi\n" /* prim */
        "testl %edi, %edi\n" /* prim */
        "jle .Lf61a8a_00061e24\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl $0, -0x64(%ebp)\n" /* i */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n" /* factor */
        "movl $0, -0x58(%ebp)\n" /* numAdded */
        "movl $0, -0x4c(%ebp)\n"
        "movl 8(%eax), %edi\n" /* line 364 | prim */
        /* { scope 2 */
        "ucomiss 0x60(%edi), %xmm0\n" /* line 257 */
        "jne .Lf61a8a_00061d9f\n"
        ".Lf61a8a_00061b4b:\n"
        "jp .Lf61a8a_00061d9f\n"
        "xorl %eax, %eax\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf61a8a_00061b56:\n"
        "ucomiss 0x64(%edi), %xmm0\n" /* line 268 */
        "jp .Lf61a8a_00061b5e\n"
        "je .Lf61a8a_00061b87\n"
        ".Lf61a8a_00061b5e:\n"
        "testb %al, %al\n" /* line 270 */
        "je .Lf61a8a_00061e2f\n"
        ".Lf61a8a_00061b66:\n"
        "movl imp_theFxHelper, %eax\n" /* line 273 */
        "movl (%eax), %eax\n"
        "movss 0x64(%edi), %xmm0\n"
        "mulss 0xf8(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n" /* line 275 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf61a8a_00061d71\n"
        /* } scope */
        ".Lf61a8a_00061b87:\n"
        "testb $4, 0x95(%edi)\n" /* line 374 | prim */
        "je .Lf61a8a_00061bb8\n"
        "movl 0x2a0(%edi), %eax\n" /* line 377 | prim */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* origin */
        "movl %eax, 4(%esp)\n"
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_CullSpherePreviousFrame\n"
        "testb %al, %al\n"
        "jne .Lf61a8a_00061d71\n"
        ".Lf61a8a_00061bb8:\n"
        "leal 0x50(%edi), %eax\n" /* line 381 | prim */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, -0x60(%ebp)\n" /* count */
        "testl %edx, %edx\n" /* line 383 */
        "je .Lf61a8a_00061d71\n"
        "movl 0x94(%edi), %eax\n" /* line 386 | prim */
        "testb $2, %ah\n"
        "je .Lf61a8a_00061c1a\n"
        "movss 0x4c(%edi), %xmm0\n" /* line 389 | prim */
        "movss %xmm0, -0x5c(%ebp)\n" /* factor */
        "subss 0x48(%edi), %xmm0\n" /* prim */
        "movss %xmm0, -0x5c(%ebp)\n" /* factor */
        "andl $0x7fffffff, -0x5c(%ebp)\n" /* factor */
        "cvtsi2ssl %edx, %xmm0\n"
        "movss -0x5c(%ebp), %xmm1\n" /* factor */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n" /* factor */
        ".Lf61a8a_00061c1a:\n"
        "movl -0x60(%ebp), %edx\n" /* line 393 | count */
        "addl %edx, -0x58(%ebp)\n" /* numAdded */
        /* { scope 2 */
        "testl %edx, %edx\n" /* line 394 */
        "jle .Lf61a8a_00061d71\n"
        "movl $0, -0x54(%ebp)\n" /* t */
        "jmp .Lf61a8a_00061d09\n"
        ".Lf61a8a_00061c34:\n"
        "cvtsi2ssl -0x54(%ebp), %xmm0\n" /* line 397 | t */
        "mulss -0x5c(%ebp), %xmm0\n" /* factor */
        "cvttss2si %xmm0, %esi\n" /* delay */
        "testl %esi, %esi\n" /* line 401 | delay */
        "jle .Lf61a8a_00061d2d\n"
        /* { scope 3 */
        ".Lf61a8a_00061c4a:\n"
        "movl $0x50, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf61a8a_00061cf7\n"
        "movl $0x50, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        "movl imp_theFxHelper, %edx\n" /* line 412 */
        "movl (%edx), %eax\n"
        "addl 4(%eax), %esi\n" /* delay */
        "movl %esi, 8(%ebx)\n" /* delay, ptr */
        "movl 0xc(%ebp), %eax\n" /* line 413 | fx */
        "movl %eax, (%ebx)\n" /* ptr */
        "movl -0x64(%ebp), %ecx\n" /* line 414 | i */
        "movl %ecx, 4(%ebx)\n" /* ptr */
        "movl -0x54(%ebp), %eax\n" /* line 415 | t */
        "movl %eax, 0x48(%ebx)\n" /* ptr */
        "movl (%edx), %eax\n" /* line 417 */
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetSeed\n"
        "addl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x44(%ebx)\n" /* ptr */
        "movl 0x18(%ebp), %esi\n" /* line 420 | bolt, delay */
        "testl %esi, %esi\n" /* delay */
        "je .Lf61a8a_00061e55\n"
        "movl 0x18(%ebp), %ecx\n" /* line 421 | bolt */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %eax, 0xc(%ebx)\n" /* ptr */
        "movl %edx, 0x10(%ebx)\n" /* ptr */
        ".Lf61a8a_00061cc0:\n"
        "leal 0x14(%ebx), %edx\n" /* line 428 | ptr, to */
        /* { scope 3 */
        "movl -0x48(%ebp), %eax\n" /* line 199 | or_ */
        "movl %eax, 0x14(%ebx)\n" /* ptr */
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x40(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x20(%ebx), %eax\n" /* line 429 | ptr */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "movl 8(%ebp), %edx\n" /* line 434 | this */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x4c(%ebx)\n" /* ptr */
        "movl %ebx, 4(%edx)\n" /* line 435 | ptr */
        "addl $1, 8(%edx)\n" /* line 436 */
        ".Lf61a8a_00061cf7:\n"
        "addl $1, -0x54(%ebp)\n" /* line 394 | t */
        "movl -0x54(%ebp), %ecx\n" /* t */
        "cmpl %ecx, -0x60(%ebp)\n" /* count */
        "je .Lf61a8a_00061d71\n"
        ".Lf61a8a_00061d03:\n"
        "movl 0x94(%edi), %eax\n" /* prim */
        ".Lf61a8a_00061d09:\n"
        "testb $2, %ah\n" /* line 396 */
        "jne .Lf61a8a_00061c34\n"
        "leal 0x48(%edi), %eax\n" /* line 399 | prim */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x68(%ebp)\n"
        "cvttss2si -0x68(%ebp), %esi\n" /* delay */
        "testl %esi, %esi\n" /* line 401 | delay */
        "jg .Lf61a8a_00061c4a\n"
        ".Lf61a8a_00061d2d:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 403 | t */
        "movl %ecx, 0x1c(%esp)\n"
        "negl %esi\n" /* delay */
        "movl %esi, 0x18(%esp)\n" /* delay */
        "leal -0x48(%ebp), %edx\n" /* or_ */
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* bolt */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* prim */
        "movl 0xc(%ebp), %edx\n" /* fx */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll FxScheduler_CreateEffect\n"
        "addl $1, -0x54(%ebp)\n" /* line 394 | t */
        "movl -0x54(%ebp), %ecx\n" /* t */
        "cmpl %ecx, -0x60(%ebp)\n" /* count */
        "jne .Lf61a8a_00061d03\n"
        /* } scope */
        ".Lf61a8a_00061d71:\n"
        "addl $1, -0x64(%ebp)\n" /* line 362 | i */
        "addl $4, -0x50(%ebp)\n"
        "addl $0x369d035, -0x4c(%ebp)\n"
        "movl -0x64(%ebp), %edx\n" /* i */
        "movl 0xc(%ebp), %eax\n" /* fx */
        "cmpl 4(%eax), %edx\n"
        "jge .Lf61a8a_00061de7\n"
        "pxor %xmm0, %xmm0\n"
        "movl -0x50(%ebp), %eax\n"
        "movl 8(%eax), %edi\n" /* line 364 | prim */
        /* { scope 2 */
        "ucomiss 0x60(%edi), %xmm0\n" /* line 257 */
        "je .Lf61a8a_00061b4b\n"
        ".Lf61a8a_00061d9f:\n"
        "movl imp_theFxHelper, %ebx\n" /* line 260 | ptr */
        "movl (%ebx), %eax\n" /* ptr */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* origin */
        "movl %edx, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm1\n"
        "movl (%ebx), %eax\n" /* line 262 | ptr */
        "movss 0x60(%edi), %xmm0\n"
        "mulss 0xf8(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n" /* line 264 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf61a8a_00061d71\n"
        "movl $1, %eax\n"
        "pxor %xmm0, %xmm0\n"
        "jmp .Lf61a8a_00061b56\n"
        /* } scope */
        ".Lf61a8a_00061de7:\n"
        "movl -0x58(%ebp), %ebx\n" /* line 450 | numAdded, ptr */
        "testl %ebx, %ebx\n" /* ptr */
        "je .Lf61a8a_00061e24\n"
        "movl imp_fx_count, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf61a8a_00061e24\n"
        "movl $0xbb8, 0xc(%esp)\n" /* line 453 */
        "movl imp_colorYellow, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x58(%ebp), %ecx\n" /* numAdded */
        "movl %ecx, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* or_ */
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x104(%eax)\n"
        /* } scope */
        ".Lf61a8a_00061e24:\n"
        "addl $0x8c, %esp\n" /* line 456 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: t */
        /* { scope 2 */
        ".Lf61a8a_00061e2f:\n"
        "movl imp_theFxHelper, %eax\n" /* line 271 */
        "movl (%eax), %eax\n"
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* origin */
        "movl %ecx, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm1\n"
        "jmp .Lf61a8a_00061b66\n"
        /* } scope */
        /* { scope 2 */
        ".Lf61a8a_00061e55:\n"
        "movl $0xffffffff, 0xc(%ebx)\n" /* line 424 | ptr */
        "movl $0xffffffff, 0x10(%ebx)\n" /* line 425 | ptr */
        "jmp .Lf61a8a_00061cc0\n"
        /* } scope */
        ".Lf61a8a_00061e68:\n"
        "movl $1, 4(%esp)\n" /* line 303 */
        "movl (%ebx), %eax\n" /* ptr */
        "movl %eax, (%esp)\n"
        "calll FxHelper_SetIgnorePrecacheErrors\n"
        "movl $str_0021a930, (%esp)\n" /* line 304 */
        "calll FX_RegisterEffect\n"
        "movl %eax, 0xc(%ebp)\n" /* fx */
        "movl $0, 4(%esp)\n" /* line 305 */
        "movl (%ebx), %eax\n" /* ptr */
        "movl %eax, (%esp)\n"
        "calll FxHelper_SetIgnorePrecacheErrors\n"
        "movl 0xc(%ebp), %eax\n" /* line 306 | fx */
        "testl %eax, %eax\n"
        "jne .Lf61a8a_00061abe\n"
        "movl $str_0021a940, (%esp)\n" /* line 158 */
        "calll FX_Print\n"
        "jmp .Lf61a8a_00061e24\n"
        ".Lf61a8a_00061eb7:\n"
        "movl 0x10(%ebp), %eax\n" /* line 348 | origin */
        "testl %eax, %eax\n"
        "je .Lf61a8a_00061ee9\n"
        "movl 0x10(%ebp), %edx\n" /* line 199 | origin */
        "movl (%edx), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* or_ */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        ".Lf61a8a_00061ed2:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 353 */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* axis */
        "movl %ecx, (%esp)\n"
        "calll AxisCopy\n"
        "jmp .Lf61a8a_00061b0f\n"
        ".Lf61a8a_00061ee9:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x48(%ebp)\n" /* or_ */
        "movl %eax, -0x44(%ebp)\n" /* line 184 */
        "movl %eax, -0x40(%ebp)\n" /* line 185 */
        "jmp .Lf61a8a_00061ed2\n"
    );
}

/* overload skip: FxScheduler_PlayEffect (0x61ef6) */

/* overload skip: FxScheduler_PlayEffect (0x61f6a) */

/* overload skip: FxScheduler_PlayEffect (0x61fca) */

/* line 102 */
__attribute__((naked))
void FxScheduler_Clean(const FxScheduler * _this, int bRemoveTemplates, EffectTemplate *fxToPreserve)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movzbl 0xc(%ebp), %esi\n" /* bRemoveTemplates */
        "jmp .Lf6201c_0006203c\n"
        ".Lf6201c_0006202e:\n"
        "movl 0x4c(%edx), %eax\n" /* line 115 */
        "movl %eax, 4(%ebx)\n" /* this */
        "movl %edx, (%esp)\n" /* line 35 */
        "calll __ZdaPv\n"
        ".Lf6201c_0006203c:\n"
        "movl 4(%ebx), %edx\n" /* line 112 | this */
        "testl %edx, %edx\n"
        "jne .Lf6201c_0006202e\n"
        "movl $0, 8(%ebx)\n" /* line 118 | this */
        "movl %esi, %eax\n" /* line 121 | bRemoveTemplates */
        "testb %al, %al\n"
        "je .Lf6201c_000620b2\n"
        /* { scope 1 */
        "movl effectTemplateArrayCount, %eax\n" /* line 900 */
        "testl %eax, %eax\n"
        "jle .Lf6201c_0006208e\n"
        "xorl %esi, %esi\n" /* effectIndex */
        "xorl %edi, %edi\n" /* foundTemplateToPreserve */
        "movl $effectTemplateArray, %ebx\n" /* this */
        "jmp .Lf6201c_00062080\n"
        ".Lf6201c_00062064:\n"
        "movl %eax, (%esp)\n" /* line 912 */
        "calll FX_CleanTemplate\n"
        "movl $0, (%ebx)\n" /* line 913 | this */
        ".Lf6201c_00062072:\n"
        "addl $1, %esi\n" /* line 900 | effectIndex */
        "addl $4, %ebx\n" /* this */
        "cmpl %esi, effectTemplateArrayCount\n" /* effectIndex */
        "jle .Lf6201c_00062090\n"
        ".Lf6201c_00062080:\n"
        "movl (%ebx), %eax\n" /* line 902 | this */
        "cmpl %eax, 0x10(%ebp)\n" /* line 905 | fxToPreserve */
        "jne .Lf6201c_00062064\n"
        "movl $1, %edi\n" /* foundTemplateToPreserve */
        "jmp .Lf6201c_00062072\n"
        ".Lf6201c_0006208e:\n"
        "xorl %edi, %edi\n" /* line 900 | foundTemplateToPreserve */
        ".Lf6201c_00062090:\n"
        "movl $0, effectTemplateArrayCount\n" /* line 916 */
        "movl %edi, %eax\n" /* line 918 | foundTemplateToPreserve */
        "testb %al, %al\n"
        "je .Lf6201c_000620b2\n"
        "movl 0x10(%ebp), %eax\n" /* line 919 | fxToPreserve */
        "movl %eax, effectTemplateArray\n"
        "movl $1, effectTemplateArrayCount\n"
        /* } scope */
        ".Lf6201c_000620b2:\n"
        "addl $0x1c, %esp\n" /* line 128 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 482 */
__attribute__((naked))
void FxScheduler_GetDecalColor(const FxScheduler * _this, const PrimitiveTemplate *primTemp, vec_t *rgba)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 482 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* primTemp */
        "movl 0x10(%ebp), %esi\n" /* rgba */
        /* { scope 1 */
        "leal -0x24(%ebp), %eax\n" /* line 490 | colorChannelInstance */
        "movl %eax, 4(%esp)\n"
        "leal 0x100(%ebx), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "testb $0x20, 0x91(%ebx)\n" /* line 492 | primTemp */
        "jne .Lf620ba_000621c9\n"
        /* { scope 2 */
        "movl -0x24(%ebp), %ecx\n" /* line 91 | colorChannelInstance */
        "movl (%ecx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull -0x20(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* keySize */
        "pxor %xmm3, %xmm3\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf620ba_00062117\n"
        "movl $0, -0x20(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %ebx\n" /* line 97 | keySize */
        ".Lf620ba_00062117:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%ebx, %edx), %eax\n" /* keySize */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf620ba_000623c2\n"
        /* } scope */
        ".Lf620ba_00062126:\n"
        "movl -0x20(%ebp), %eax\n" /* line 148 */
        "shll $4, %eax\n"
        "addl %ecx, %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "movaps %xmm3, %xmm2\n" /* line 74 | frac */
        "subss %xmm1, %xmm2\n" /* frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale, frac */
        /* { scope 4 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movss 8(%edx), %xmm1\n" /* line 265 */
        "movss 0x18(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movss 0xc(%edx), %xmm1\n" /* line 266 */
        "movss 0x1c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movss -0x1c(%ebp), %xmm0\n" /* line 39 | scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%esi), %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%esi), %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "mulss 8(%esi), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%esi)\n"
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 502 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf620ba_000621c9:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 494 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "fstps -0x5c(%ebp)\n"
        "movss -0x5c(%ebp), %xmm5\n"
        "leal -0x30(%ebp), %eax\n" /* line 495 | colorRandChannelInstance */
        "movl %eax, 4(%esp)\n"
        "leal 0x10c(%ebx), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "movss %xmm5, -0x58(%ebp)\n"
        "calll FxChannelInstance_Create\n"
        /* { scope 2 */
        "movl -0x24(%ebp), %ecx\n" /* line 91 | colorChannelInstance */
        "movl (%ecx), %ebx\n" /* keySize */
        "addl $1, %ebx\n" /* keySize */
        "movl %ebx, %eax\n" /* line 92 | keySize */
        "imull -0x20(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %edx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "movss -0x58(%ebp), %xmm5\n"
        "jbe .Lf620ba_00062230\n"
        "movl $0, -0x20(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %edx\n" /* line 97 */
        ".Lf620ba_00062230:\n"
        "shll $2, %ebx\n" /* line 100 | keySize */
        "leal (%edx, %ebx), %eax\n"
        "pxor %xmm0, %xmm0\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lf620ba_00062400\n"
        /* } scope */
        ".Lf620ba_00062247:\n"
        "movl -0x20(%ebp), %eax\n" /* line 148 */
        "shll $4, %eax\n"
        "addl %ecx, %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "movaps %xmm3, %xmm2\n" /* line 74 | frac */
        "subss %xmm1, %xmm2\n" /* frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale, frac */
        /* { scope 4 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "leal 4(%esi), %eax\n" /* line 265 */
        "movl %eax, -0x3c(%ebp)\n"
        "movss 8(%edx), %xmm1\n"
        "movss 0x18(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "leal 8(%esi), %edi\n" /* line 266 */
        "movss 0xc(%edx), %xmm1\n"
        "movss 0x1c(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl -0x30(%ebp), %ecx\n" /* line 91 | colorRandChannelInstance */
        "movl (%ecx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull -0x2c(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf620ba_000622ec\n"
        "movl $0, -0x2c(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %ebx\n" /* line 97 | keySize */
        ".Lf620ba_000622ec:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf620ba_000623e1\n"
        /* } scope */
        ".Lf620ba_000622fb:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 148 */
        "shll $4, %eax\n"
        "addl %ecx, %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 67 */
        "subss %xmm1, %xmm3\n" /* line 74 | frac */
        "movss 0x10(%edx), %xmm0\n" /* scale */
        "subss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm3\n" /* scale, frac */
        /* { scope 4 */
        "movss 4(%edx), %xmm1\n" /* line 264 */
        "movss 8(%edx), %xmm2\n" /* line 265 */
        "movss 0xc(%edx), %xmm4\n" /* line 266 */
        /* } scope */
        /* } scope */
        /* } scope */
        "movss 0x18(%edx), %xmm0\n" /* line 249 */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "subss 4(%esi), %xmm2\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 250 */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "subss 8(%esi), %xmm4\n"
        "movss 0x14(%edx), %xmm0\n" /* line 288 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss (%esi), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss (%esi), %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "mulss %xmm5, %xmm2\n" /* line 289 */
        "addss 4(%esi), %xmm2\n"
        "movl -0x3c(%ebp), %eax\n"
        "movss %xmm2, (%eax)\n"
        "mulss %xmm4, %xmm5\n" /* line 290 */
        "addss 8(%esi), %xmm5\n"
        "movss %xmm5, (%edi)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 74 | scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss (%esi), %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%esi), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "mulss 8(%esi), %xmm0\n" /* line 274 */
        "movss %xmm0, (%edi)\n"
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 502 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf620ba_000623c2:\n"
        "addl $1, -0x20(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lf620ba_00062126\n"
        "addl $1, -0x20(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf620ba_000623c2\n"
        "jmp .Lf620ba_00062126\n"
        /* } scope */
        /* { scope 2 */
        ".Lf620ba_000623e1:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lf620ba_000622fb\n"
        "addl $1, -0x2c(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf620ba_000623e1\n"
        "jmp .Lf620ba_000622fb\n"
        ".Lf620ba_00062400:\n"
        "pxor %xmm3, %xmm3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf620ba_00062404:\n"
        "addl $1, -0x20(%ebp)\n" /* line 102 */
        "addl %ebx, %eax\n" /* line 100 | keySize */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf620ba_00062404\n"
        "jmp .Lf620ba_00062247\n"
    );
}

/* line 505 */
__attribute__((naked))
float FxScheduler_GetDecalAlpha(const FxScheduler * _this, const PrimitiveTemplate *primTemp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 505 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* primTemp */
        /* { scope 1 */
        "leal -0x14(%ebp), %eax\n" /* line 514 | alphaChannelInstance */
        "movl %eax, 4(%esp)\n"
        "leal 0x118(%ebx), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "testb $0x40, 0x91(%ebx)\n" /* line 516 | primTemp */
        "jne .Lf62414_000624de\n"
        /* { scope 2 */
        "movl -0x14(%ebp), %ecx\n" /* line 91 | alphaChannelInstance */
        "movl (%ecx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull -0x10(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* keySize */
        "pxor %xmm5, %xmm5\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm5, %xmm0\n"
        "jbe .Lf62414_0006246c\n"
        "movl $0, -0x10(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %ebx\n" /* line 97 | keySize */
        ".Lf62414_0006246c:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm5\n"
        "ja .Lf62414_00062620\n"
        /* } scope */
        ".Lf62414_0006247b:\n"
        "movl -0x10(%ebp), %eax\n" /* line 126 */
        "leal (%ecx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "movaps %xmm5, %xmm3\n" /* line 32 */
        "subss %xmm1, %xmm3\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "mulss -0xc(%ebp), %xmm3\n"
        "ucomiss %xmm3, %xmm5\n" /* line 406 */
        "ja .Lf62414_0006260f\n"
        ".Lf62414_000624c1:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 408 | 1.0f */
        "minss %xmm3, %xmm0\n"
        "movaps %xmm0, %xmm3\n"
        /* } scope */
        "movss %xmm3, -0x3c(%ebp)\n" /* line 528 */
        "flds -0x3c(%ebp)\n"
        "addl $0x54, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf62414_000624de:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 518 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "fstps -0x2c(%ebp)\n" /* randomWeight */
        "leal -0x20(%ebp), %eax\n" /* line 519 | alphaRandChannelInstance */
        "movl %eax, 4(%esp)\n"
        "leal 0x124(%ebx), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        /* { scope 2 */
        "movl -0x14(%ebp), %ecx\n" /* line 91 | alphaChannelInstance */
        "movl (%ecx), %ebx\n" /* keySize */
        "addl $1, %ebx\n" /* keySize */
        "movl %ebx, %eax\n" /* line 92 | keySize */
        "imull -0x10(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %edx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf62414_00062536\n"
        "movl $0, -0x10(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %edx\n" /* line 97 */
        ".Lf62414_00062536:\n"
        "shll $2, %ebx\n" /* line 100 | keySize */
        "leal (%ebx, %edx), %eax\n" /* keySize */
        "pxor %xmm0, %xmm0\n"
        "pxor %xmm5, %xmm5\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lf62414_0006265e\n"
        /* } scope */
        ".Lf62414_0006254d:\n"
        "movl -0x10(%ebp), %eax\n" /* line 126 */
        "leal (%ecx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm5, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl -0x20(%ebp), %ecx\n" /* line 91 | alphaRandChannelInstance */
        "movl (%ecx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull -0x1c(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm5, %xmm0\n"
        "jbe .Lf62414_000625ad\n"
        "movl $0, -0x1c(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %ebx\n" /* line 97 | keySize */
        ".Lf62414_000625ad:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm5\n"
        "ja .Lf62414_0006263f\n"
        /* } scope */
        ".Lf62414_000625bc:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 126 */
        "leal (%ecx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "movaps %xmm5, %xmm3\n" /* line 55 */
        "subss %xmm1, %xmm3\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "mulss -0x2c(%ebp), %xmm3\n" /* randomWeight */
        "addss %xmm4, %xmm3\n"
        "mulss -0xc(%ebp), %xmm3\n"
        "ucomiss %xmm3, %xmm5\n" /* line 406 */
        "jbe .Lf62414_000624c1\n"
        ".Lf62414_0006260f:\n"
        "movaps %xmm5, %xmm3\n"
        /* } scope */
        "movss %xmm3, -0x3c(%ebp)\n" /* line 528 */
        "flds -0x3c(%ebp)\n"
        "addl $0x54, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf62414_00062620:\n"
        "addl $1, -0x10(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm5\n"
        "jbe .Lf62414_0006247b\n"
        "addl $1, -0x10(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm5\n"
        "ja .Lf62414_00062620\n"
        "jmp .Lf62414_0006247b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf62414_0006263f:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm5\n"
        "jbe .Lf62414_000625bc\n"
        "addl $1, -0x1c(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm5\n"
        "ja .Lf62414_0006263f\n"
        "jmp .Lf62414_000625bc\n"
        ".Lf62414_0006265e:\n"
        "pxor %xmm5, %xmm5\n"
        /* } scope */
        /* { scope 2 */
        ".Lf62414_00062662:\n"
        "addl $1, -0x10(%ebp)\n" /* line 102 */
        "addl %ebx, %eax\n" /* line 100 | keySize */
        "ucomiss (%eax), %xmm5\n"
        "ja .Lf62414_00062662\n"
        "jmp .Lf62414_0006254d\n"
    );
}

/* line 531 */
__attribute__((naked))
float FxScheduler_GetDecalSize(const FxScheduler * _this, const PrimitiveTemplate *primTemp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 531 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* primTemp */
        /* { scope 1 */
        "leal -0x14(%ebp), %eax\n" /* line 539 | sizeChannelInstance */
        "movl %eax, 4(%esp)\n"
        "leal 0x130(%ebx), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        "cmpw $0, 0x90(%ebx)\n" /* line 541 | primTemp */
        "js .Lf62672_00062722\n"
        /* { scope 2 */
        "movl -0x14(%ebp), %ecx\n" /* line 91 | sizeChannelInstance */
        "movl (%ecx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull -0x10(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* keySize */
        "pxor %xmm3, %xmm3\n" /* line 94 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf62672_000626cb\n"
        "movl $0, -0x10(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %ebx\n" /* line 97 | keySize */
        ".Lf62672_000626cb:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf62672_00062851\n"
        /* } scope */
        ".Lf62672_000626da:\n"
        "movl -0x10(%ebp), %eax\n" /* line 126 */
        "leal (%ecx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 32 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "mulss -0xc(%ebp), %xmm3\n" /* line 55 */
        /* } scope */
        "movss %xmm3, -0x3c(%ebp)\n" /* line 551 */
        "flds -0x3c(%ebp)\n"
        "addl $0x54, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf62672_00062722:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 543 */
        "movl $0, (%esp)\n"
        "calll flrand\n"
        "fstps -0x2c(%ebp)\n" /* randomWeight */
        "leal -0x20(%ebp), %eax\n" /* line 544 | sizeRandChannelInstance */
        "movl %eax, 4(%esp)\n"
        "leal 0x13c(%ebx), %eax\n" /* primTemp */
        "movl %eax, (%esp)\n"
        "calll FxChannelInstance_Create\n"
        /* { scope 2 */
        "movl -0x14(%ebp), %ecx\n" /* line 91 | sizeChannelInstance */
        "movl (%ecx), %ebx\n" /* keySize */
        "addl $1, %ebx\n" /* keySize */
        "movl %ebx, %eax\n" /* line 92 | keySize */
        "imull -0x10(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %edx\n"
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf62672_0006277a\n"
        "movl $0, -0x10(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %edx\n" /* line 97 */
        ".Lf62672_0006277a:\n"
        "shll $2, %ebx\n" /* line 100 | keySize */
        "leal (%ebx, %edx), %eax\n" /* keySize */
        "pxor %xmm0, %xmm0\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lf62672_0006288b\n"
        /* } scope */
        ".Lf62672_00062791:\n"
        "movl -0x10(%ebp), %eax\n" /* line 126 */
        "leal (%ecx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        "movaps %xmm3, %xmm4\n" /* line 56 */
        "subss %xmm1, %xmm4\n"
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "addss %xmm2, %xmm4\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movl -0x20(%ebp), %ecx\n" /* line 91 | sizeRandChannelInstance */
        "movl (%ecx), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 92 */
        "imull -0x1c(%ebp), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 8(%eax), %ebx\n" /* keySize */
        "movss 8(%eax), %xmm0\n" /* line 94 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf62672_000627f1\n"
        "movl $0, -0x1c(%ebp)\n" /* line 96 */
        "leal 8(%ecx), %ebx\n" /* line 97 | keySize */
        ".Lf62672_000627f1:\n"
        "shll $2, %edx\n" /* line 100 */
        "leal (%edx, %ebx), %eax\n"
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf62672_00062870\n"
        /* } scope */
        ".Lf62672_000627fc:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 126 */
        "leal (%ecx, %eax, 8), %eax\n"
        "leal 8(%eax), %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movss 8(%eax), %xmm1\n" /* line 49 */
        "movss 4(%edx), %xmm2\n" /* line 51 */
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm3\n" /* line 55 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "addss %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "mulss -0x2c(%ebp), %xmm3\n" /* randomWeight */
        "addss %xmm4, %xmm3\n"
        "mulss -0xc(%ebp), %xmm3\n"
        /* } scope */
        "movss %xmm3, -0x3c(%ebp)\n" /* line 551 */
        "flds -0x3c(%ebp)\n"
        "addl $0x54, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf62672_00062851:\n"
        "addl $1, -0x10(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lf62672_000626da\n"
        "addl $1, -0x10(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf62672_00062851\n"
        "jmp .Lf62672_000626da\n"
        /* } scope */
        /* { scope 2 */
        ".Lf62672_00062870:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "jbe .Lf62672_000627fc\n"
        "addl $1, -0x1c(%ebp)\n" /* line 102 */
        "addl %edx, %eax\n" /* line 100 */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf62672_00062870\n"
        "jmp .Lf62672_000627fc\n"
        ".Lf62672_0006288b:\n"
        "pxor %xmm3, %xmm3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf62672_0006288f:\n"
        "addl $1, -0x10(%ebp)\n" /* line 102 */
        "addl %ebx, %eax\n" /* line 100 | keySize */
        "ucomiss (%eax), %xmm3\n"
        "ja .Lf62672_0006288f\n"
        "jmp .Lf62672_00062791\n"
    );
}

/* line 69 */
__attribute__((naked))
EffectTemplate * MediaHandles_GetEffect(const MediaHandles * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movzwl 4(%edx), %eax\n" /* line 79 */
        "testw %ax, %ax\n"
        "jne .Lf628a0_000628bb\n"
        "xorl %eax, %eax\n" /* line 82 */
        "addl $0x14, %esp\n" /* line 72 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf628a0_000628bb:\n"
        "movl (%edx), %ebx\n" /* line 84 */
        "movzwl %ax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll irand\n"
        "movl (%ebx, %eax, 4), %eax\n"
        "addl $0x14, %esp\n" /* line 72 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 554 */
__attribute__((naked))
void FxScheduler_CreateDecalEffect(const FxScheduler * _this, const PrimitiveTemplate *primTemp, vec_t *org, MediaHandles * (*ax)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 554 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* primTemp */
        /* { scope 1 */
        "leal 0x220(%esi), %eax\n" /* line 563 | primTemp */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetVal\n"
        "fstps -0x30(%ebp)\n" /* rotation */
        "leal -0x28(%ebp), %edi\n" /* line 565 | rgba */
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* primTemp */
        "movl %ebx, (%esp)\n" /* this */
        "calll FxScheduler_GetDecalColor\n"
        "movl %esi, 4(%esp)\n" /* line 566 | primTemp */
        "movl %ebx, (%esp)\n" /* this */
        "calll FxScheduler_GetDecalAlpha\n"
        "fstps -0x1c(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* line 568 | primTemp */
        "movl %ebx, (%esp)\n" /* this */
        "calll FxScheduler_GetDecalSize\n"
        "fstps -0x2c(%ebp)\n" /* size */
        "movzwl 0x6c(%esi), %eax\n" /* line 79 */
        "testw %ax, %ax\n"
        "jne .Lf628da_0006296e\n"
        "xorl %edx, %edx\n" /* line 82 */
        ".Lf628da_00062936:\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 575 | size */
        "movss %xmm0, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* rotation */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* ax */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* org */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_ImpactMark\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 577 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf628da_0006296e:\n"
        "movl 0x68(%esi), %ebx\n" /* line 84 */
        "movzwl %ax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll irand\n"
        "movl (%ebx, %eax, 4), %edx\n"
        "jmp .Lf628da_00062936\n"
    );
}

/* line 759 */
__attribute__((naked))
void ScheduledEffect_Archive(const ScheduledEffect * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 759 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* arch */
        "movl %edi, 4(%esp)\n" /* line 767 | this */
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveEffect\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lf6298a_00062ab5\n"
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 4(%edi)\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lf6298a_00062adc\n"
        /* { scope 1: f */
        ".Lf6298a_000629d6:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 8(%edi)\n"
        "leal 0xc(%edi), %eax\n" /* line 771 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveFxBoltInfo\n"
        "leal 0x14(%edi), %esi\n" /* line 775 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lf6298a_00062b15\n"
        ".Lf6298a_00062a0f:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x20(%edi), %esi\n" /* line 776 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lf6298a_00062b79\n"
        ".Lf6298a_00062a30:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x2c(%edi), %esi\n" /* line 777 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lf6298a_00062bdd\n"
        ".Lf6298a_00062a51:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "leal 0x38(%edi), %esi\n" /* line 778 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "je .Lf6298a_00062c41\n"
        ".Lf6298a_00062a72:\n"
        "movl $0xc, 8(%esp)\n" /* line 115 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "je .Lf6298a_00062ca2\n"
        /* { scope 1: f */
        ".Lf6298a_00062a90:\n"
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 201 | i */
        "movl %eax, 0x44(%edi)\n"
        "addl $0x2c, %esp\n" /* line 782 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf6298a_00062ab5:\n"
        "movl 4(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lf6298a_000629d6\n"
        ".Lf6298a_00062adc:\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "leal 0xc(%edi), %eax\n" /* line 771 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* arch */
        "calll FxArchive_ArchiveFxBoltInfo\n"
        "leal 0x14(%edi), %esi\n" /* line 775 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lf6298a_00062a0f\n"
        ".Lf6298a_00062b15:\n"
        "movl 0x14(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x20(%edi), %esi\n" /* line 776 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lf6298a_00062a30\n"
        ".Lf6298a_00062b79:\n"
        "movl 0x20(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x2c(%edi), %esi\n" /* line 777 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lf6298a_00062a51\n"
        ".Lf6298a_00062bdd:\n"
        "movl 0x2c(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "leal 0x38(%edi), %esi\n" /* line 778 | this, v */
        "cmpb $0, 4(%ebx)\n" /* line 227 */
        "jne .Lf6298a_00062a72\n"
        ".Lf6298a_00062c41:\n"
        "movl 0x38(%edi), %eax\n" /* line 115 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* } scope */
        /* { scope 2 */
        "movl $4, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        "cmpb $0, 4(%ebx)\n" /* line 200 */
        "jne .Lf6298a_00062a90\n"
        ".Lf6298a_00062ca2:\n"
        "movl 0x44(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 1: f */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 782 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 710 */
__attribute__((naked))
void FxScheduler_Archive(const FxScheduler * _this, FxArchive *arch)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 710 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* arch */
        /* { scope 1: i */
        "cmpb $0, 4(%esi)\n" /* line 717 | arch */
        "je .Lf62cc8_00062d14\n"
        "movl $0, 4(%edi)\n" /* line 720 | this */
        "movl $0, 8(%edi)\n" /* line 721 | this */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 100 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_ReadData\n"
        "movl -0x1c(%ebp), %eax\n" /* line 46 | i */
        "movl %eax, -0x30(%ebp)\n" /* pendingCount */
        /* } scope */
        "testl %eax, %eax\n" /* line 722 */
        "jne .Lf62cc8_00062d67\n"
        /* } scope */
        ".Lf62cc8_00062d0c:\n"
        "addl $0x3c, %esp\n" /* line 756 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lf62cc8_00062d14:\n"
        "movl 8(%edi), %eax\n" /* line 722 | this */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 2 */
        "movl $4, 8(%esp)\n" /* line 137 */
        "leal -0x1c(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "movl imp_theFxScheduler, %eax\n" /* line 753 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %ebx\n" /* sfx */
        "testl %ebx, %ebx\n" /* sfx */
        "je .Lf62cc8_00062d0c\n"
        ".Lf62cc8_00062d3f:\n"
        "movl %esi, 4(%esp)\n" /* line 754 | arch */
        "movl %ebx, (%esp)\n" /* sfx */
        "calll ScheduledEffect_Archive\n"
        "movl 0x4c(%ebx), %ebx\n" /* line 753 | sfx */
        "testl %ebx, %ebx\n" /* sfx */
        "je .Lf62cc8_00062d0c\n"
        "movl %esi, 4(%esp)\n" /* line 754 | arch */
        "movl %ebx, (%esp)\n" /* sfx */
        "calll ScheduledEffect_Archive\n"
        "movl 0x4c(%ebx), %ebx\n" /* line 753 | sfx */
        "testl %ebx, %ebx\n" /* sfx */
        "jne .Lf62cc8_00062d3f\n"
        "jmp .Lf62cc8_00062d0c\n"
        ".Lf62cc8_00062d67:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 722 */
        "jmp .Lf62cc8_00062d95\n"
        ".Lf62cc8_00062d70:\n"
        "movl 8(%edx, %eax, 4), %edx\n" /* line 730 */
        "testl %edx, %edx\n"
        "je .Lf62cc8_00062ddd\n"
        "movl 4(%edi), %eax\n" /* line 732 | this */
        "movl %eax, 0x4c(%ebx)\n" /* sfx */
        "movl %ebx, 4(%edi)\n" /* line 733 | sfx, this */
        "addl $1, 8(%edi)\n" /* line 734 | this */
        ".Lf62cc8_00062d85:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 35 */
        "movl -0x2c(%ebp), %eax\n" /* line 722 */
        "cmpl %eax, -0x30(%ebp)\n" /* pendingCount */
        "je .Lf62cc8_00062d0c\n"
        /* { scope 2 */
        ".Lf62cc8_00062d95:\n"
        "movl $0x50, (%esp)\n" /* line 24 */
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* ptr */
        "testl %eax, %eax\n" /* line 25 */
        "je .Lf62cc8_00062dbf\n"
        "movl $0x50, 8(%esp)\n" /* line 27 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        ".Lf62cc8_00062dbf:\n"
        "movl %esi, 4(%esp)\n" /* line 725 | arch */
        "movl %ebx, (%esp)\n" /* sfx */
        "calll ScheduledEffect_Archive\n"
        "movl (%ebx), %edx\n" /* line 726 | sfx */
        "testl %edx, %edx\n"
        "je .Lf62cc8_00062ddd\n"
        "movl 4(%ebx), %eax\n" /* line 728 | sfx */
        "testl %eax, %eax\n"
        "js .Lf62cc8_00062ddd\n"
        "cmpl 4(%edx), %eax\n"
        "jl .Lf62cc8_00062d70\n"
        ".Lf62cc8_00062ddd:\n"
        "testl %ebx, %ebx\n" /* line 35 | ptr */
        "je .Lf62cc8_00062d85\n"
        "movl %ebx, (%esp)\n" /* ptr */
        "calll __ZdaPv\n"
        "jmp .Lf62cc8_00062d85\n"
    );
}

