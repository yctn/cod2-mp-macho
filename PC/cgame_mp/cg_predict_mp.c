/* ASM dump from: cg_predict_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_predict_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/q_shared.h"
 */

static pmove_t cg_pmove[1]; /* 0xfea400 */
static int cg_numSolidEntities; /* 0xfea900 */
static cg_solidEntities_t cg_solidEntities; /* 0xfea980 */
static int cg_numTriggerEntities; /* 0xfea4f8 */
static centity_t * cg_triggerEntities[256]; /* 0xfea500 */

extern int CM_PointContents(const vec_t *point, unsigned int model);
extern int CM_TransformedPointContents(const vec_t *point, unsigned int model, const vec_t *origin, const vec_t *angles);
extern int CM_ContentsOfModel(unsigned int model);
extern void CM_BoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, unsigned int model, int brushmask);


void CG_ClearSolidList(void);
int CG_PointContents(const vec_t *point, int passEntityNum, int contentmask);
static void CG_InterpolatePlayerState(qboolean grabAngles);
void CG_PredictPlayerState(void);
static void Trace_CalcBounds(const vec_t *end, vec3_t *bounds);
void CG_ClipMoveToEntities(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int skipNumber, int mask, int capsule, trace_t *tr);
void CG_TraceCapsule(trace_t *result, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int skipNumber, int mask);
void CG_BuildSolidList(void);

/* line 49 */
void CG_ClearSolidList(void)
{
    cg_numSolidEntities = 0;
    cg_numTriggerEntities = 0;
}

/* line 276 */
int CG_PointContents(const vec_t *point, int passEntityNum, int contentmask)
{
    int contents;
    int i;

    contents = CM_PointContents(point, 0);

    for (i = 0; i < cg_numSolidEntities; i++) {
        char *cent = ((char **)&cg_solidEntities)[i];
        char *ent = cent + 0xf0;

        if (*(int *)(ent) == passEntityNum)
            continue;
        if (*(int *)(ent + 0x9c) != 0xffffff)
            continue;
        if (*(int *)(ent + 0x8c) == 0)
            continue;

        contents |= CM_TransformedPointContents(point, *(unsigned int *)(ent + 0x8c),
                                                 (const vec_t *)(cent + 0x1ec),
                                                 (const vec_t *)(cent + 0x1f8));
    }

    return contents & contentmask;
}

/* line 321 */
static __attribute__((naked))
void CG_InterpolatePlayerState(qboolean grabAngles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 321 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, -0x4c(%ebp)\n"
        /* { scope 1: cmd */
        "movl 0x195f584, %eax\n" /* line 328 */
        "movl (%eax), %esi\n"
        "leal 0x25bc4(%esi), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* out */
        "movl 0x20(%esi), %edx\n" /* line 329 */
        "movl %edx, -0x44(%ebp)\n" /* prev */
        "movl 0x24(%esi), %edi\n" /* line 330 | next */
        "leal 0xc(%edi), %eax\n" /* line 333 | next */
        "movl $0x26a8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x48(%ebp), %ecx\n" /* out */
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 336 */
        "testl %ebx, %ebx\n"
        "jne .Lf1db1de_001db35a\n"
        ".Lf1db1de_001db228:\n"
        "movl 8(%edi), %eax\n" /* line 347 | next */
        "movl -0x44(%ebp), %edx\n" /* prev */
        "cmpl 8(%edx), %eax\n"
        "jle .Lf1db1de_001db352\n"
        "movss 0x25ba8(%esi), %xmm2\n" /* line 350 */
        "movl 0x14(%edi), %eax\n" /* line 352 | next */
        "movl 0x14(%edx), %edx\n" /* line 353 */
        "leal 0x100(%eax), %ecx\n" /* line 354 */
        "cmpl %edx, %eax\n"
        "cmovll %ecx, %eax\n"
        "subl %edx, %eax\n" /* line 355 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "addl %eax, %edx\n"
        "movl -0x48(%ebp), %eax\n" /* out */
        "movl %edx, 8(%eax)\n"
        "movl -0x44(%ebp), %edx\n" /* line 356 | prev */
        "movss 0x5e0(%edx), %xmm1\n"
        "movss 0x5e0(%edi), %xmm0\n" /* next */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x5d4(%eax)\n"
        "movl -0x4c(%ebp), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1db1de_001db392\n"
        "movl %edi, %ecx\n" /* line 373 | next */
        "movl -0x44(%ebp), %edx\n" /* prev */
        "movl -0x48(%ebp), %eax\n" /* out */
        "xorl %ebx, %ebx\n"
        ".Lf1db1de_001db2a2:\n"
        "movss 0x20(%edx), %xmm1\n" /* line 360 */
        "movss 0x20(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14(%eax)\n"
        "movss 0x2c(%edx), %xmm1\n" /* line 363 */
        "movss 0x2c(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x20(%eax)\n"
        "addl $1, %ebx\n" /* line 358 */
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl $3, %ebx\n"
        "jne .Lf1db1de_001db2a2\n"
        ".Lf1db1de_001db2e9:\n"
        "movl -0x44(%ebp), %edx\n" /* line 367 | prev */
        "movss 0x104(%edx), %xmm1\n"
        "movss 0x104(%edi), %xmm0\n" /* next */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x48(%ebp), %ecx\n" /* out */
        "movss %xmm1, 0xf8(%ecx)\n"
        "movss 0x58(%edx), %xmm1\n" /* line 370 */
        "movss 0x58(%edi), %xmm0\n" /* next */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x4c(%ecx)\n"
        "movss 0xe8(%edx), %xmm1\n" /* line 373 */
        "movss 0xe8(%edi), %xmm0\n" /* next */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 0xdc(%ecx)\n"
        /* } scope */
        ".Lf1db1de_001db352:\n"
        "addl $0x6c, %esp\n" /* line 374 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: cmd */
        /* { scope 2 */
        ".Lf1db1de_001db35a:\n"
        "calll CL_GetCurrentCmdNumber\n" /* line 341 */
        "leal -0x34(%ebp), %ebx\n" /* line 342 | cmd */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetUserCmd\n"
        "movl $0, 0xc(%esp)\n" /* line 344 */
        "movl %ebx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* out */
        "movl %eax, (%esp)\n"
        "calll PM_UpdateViewAngles\n"
        "jmp .Lf1db1de_001db228\n"
        /* } scope */
        ".Lf1db1de_001db392:\n"
        "movl %edi, -0x40(%ebp)\n" /* line 356 | next */
        "movl %edx, %esi\n"
        "movl %eax, %ebx\n"
        "movl $0, -0x3c(%ebp)\n"
        ".Lf1db1de_001db3a0:\n"
        "movss 0x20(%esi), %xmm1\n" /* line 360 */
        "movl -0x40(%ebp), %ecx\n"
        "movss 0x20(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14(%ebx)\n"
        "movss %xmm2, 8(%esp)\n" /* line 362 */
        "movl 0xf4(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xf4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x68(%ebp)\n"
        "calll LerpAngle\n"
        "fstps 0xe8(%ebx)\n"
        "movss 0x2c(%esi), %xmm1\n" /* line 363 */
        "movl -0x40(%ebp), %eax\n"
        "movss 0x2c(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss -0x68(%ebp), %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x20(%ebx)\n"
        "addl $1, -0x3c(%ebp)\n" /* line 358 */
        "addl $4, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "addl $4, %esi\n"
        "addl $4, %ebx\n"
        "cmpl $3, -0x3c(%ebp)\n"
        "jne .Lf1db1de_001db3a0\n"
        "jmp .Lf1db1de_001db2e9\n"
    );
}

/* line 687 */
__attribute__((naked))
void CG_PredictPlayerState(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 687 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfc, %esp\n"
        /* { scope 1 */
        "movl $0x26a8, 4(%esp)\n" /* line 505 */
        "leal -0x20(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "movl %edi, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0xa4(%ebp)\n"
        "movl 0x195f584, %ebx\n" /* line 510 */
        "movl (%ebx), %ebx\n"
        "movl 8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1db426_001db46f\n"
        "movl 0x24(%ebx), %eax\n"
        "testb $0x40, 0x1a(%eax)\n"
        "je .Lf1db426_001db56a\n"
        ".Lf1db426_001db46f:\n"
        "xorl %eax, %eax\n" /* line 512 */
        "calll CG_InterpolatePlayerState\n"
        ".Lf1db426_001db476:\n"
        "movl %edi, (%esp)\n" /* line 678 */
        "calll ZN10LargeLocalD1Ev\n"
        "movl 0x195f584, %eax\n" /* line 700 */
        "movl (%eax), %esi\n"
        "leal 0x25bc4(%esi), %edi\n" /* ps */
        "movl 0xcc(%edi), %eax\n" /* line 701 | ps */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl 0x195f5cc, %eax\n"
        "movl (%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "leal 0x1ec(%edx), %ebx\n" /* line 702 | to */
        "leal 0x25bd8(%esi), %ecx\n" /* from */
        /* { scope 2 */
        "movl 0x25bd8(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x1ec(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "leal 0x1f8(%edx), %eax\n" /* line 703 */
        "movl %eax, 8(%esp)\n"
        "movl 0x25bb0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "addl $0x30, %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 0xd4(%edi), %eax\n" /* line 705 | ps */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ebx\n" /* to */
        "movl 0x24(%esi), %eax\n" /* line 707 */
        "testb $0x80, 0x1a(%eax)\n"
        "jne .Lf1db426_001db626\n"
        ".Lf1db426_001db505:\n"
        "movl $0, 0x2cd10(%esi)\n" /* line 722 */
        ".Lf1db426_001db50f:\n"
        "movl 0x195f584, %eax\n" /* line 726 */
        "movl (%eax), %ebx\n" /* to */
        "movzwl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, 0x2835c(%ebx)\n" /* to */
        "movl $0, 0xc(%esp)\n" /* line 727 */
        "movl $0, 8(%esp)\n"
        "leal 0x2835c(%ebx), %esi\n" /* to */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_PlayerStateToEntityState\n"
        "addl $0x2826c, %ebx\n" /* line 728 | to */
        "movl $0xf0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* to */
        "calll memcpy\n"
        /* } scope */
        "addl $0xfc, %esp\n" /* line 735 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1db426_001db56a:\n"
        "movl 0x195f788, %eax\n" /* line 519 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1db426_001db617\n"
        "movl 0x195f78c, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1db426_001db617\n"
        "leal 0x25bc4(%ebx), %esi\n" /* line 530 */
        "movl %esi, cg_pmove\n"
        "movb $0, 0xfea4e4\n" /* line 531 */
        "movl $0x810011, %edx\n" /* line 534 */
        "cmpl $6, 4(%esi)\n"
        "movl $0x2810011, %eax\n"
        "cmovll %eax, %edx\n"
        "movl %edx, 0xfea43c\n"
        "movl 0x24(%ebx), %eax\n" /* line 540 */
        "cmpl $4, 0x10(%eax)\n"
        "je .Lf1db426_001db736\n"
        ".Lf1db426_001db5c3:\n"
        "calll CL_GetCurrentCmdNumber\n" /* line 544 */
        "movl %eax, -0xa8(%ebp)\n"
        "subl $0x7f, %eax\n" /* line 549 */
        "movl %eax, -0xac(%ebp)\n"
        "leal -0x48(%ebp), %eax\n" /* line 550 */
        "movl %eax, 4(%esp)\n"
        "movl -0xac(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetUserCmd\n"
        "testl %eax, %eax\n"
        "jne .Lf1db426_001db747\n"
        "movl 0x195f940, %eax\n" /* line 552 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1db426_001db476\n"
        "movl $0x2b7ed8, (%esp)\n" /* line 553 */
        "calll Com_Printf\n"
        "jmp .Lf1db426_001db476\n"
        ".Lf1db426_001db617:\n"
        "movl $1, %eax\n" /* line 521 */
        "calll CG_InterpolatePlayerState\n"
        "jmp .Lf1db426_001db476\n"
        ".Lf1db426_001db626:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 707 | fZoom */
        "movl %eax, (%esp)\n"
        "calll CG_GetWeapReticleZoom\n"
        "testb %al, %al\n"
        "je .Lf1db426_001db505\n"
        "pxor %xmm0, %xmm0\n" /* line 709 */
        "ucomiss 0x338(%ebx), %xmm0\n" /* to */
        "jp .Lf1db426_001db64c\n"
        "je .Lf1db426_001db50f\n"
        ".Lf1db426_001db64c:\n"
        "movl 0x2cd10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1db426_001db50f\n"
        "movl $1, 0x2cd10(%esi)\n" /* line 711 */
        "movl 0x338(%ebx), %eax\n" /* line 712 | to */
        "movl %eax, 4(%esp)\n"
        "movl 0x334(%ebx), %eax\n" /* to */
        "movl %eax, (%esp)\n"
        "calll flrand\n"
        "fstps -0xb4(%ebp)\n" /* size */
        "calll randomf\n" /* line 713 */
        "fstps -0xdc(%ebp)\n"
        "movss -0xdc(%ebp), %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xb0(%ebp)\n" /* angle */
        "movss %xmm0, (%esp)\n" /* line 486 */
        "calll cosf\n"
        "fstps -0xbc(%ebp)\n"
        "movss -0xb0(%ebp), %xmm0\n" /* line 485 | angle */
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0xdc(%ebp)\n"
        "movss -0xdc(%ebp), %xmm0\n"
        "mulss -0xb4(%ebp), %xmm0\n" /* size */
        "addss 0x2c048(%esi), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x2c048(%esi)\n" /* line 716 */
        "movss -0xb4(%ebp), %xmm0\n" /* line 717 | size */
        "mulss -0xbc(%ebp), %xmm0\n"
        "movss %xmm0, -0xb4(%ebp)\n" /* size */
        "addss 0x2c04c(%esi), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x2c04c(%esi)\n"
        "jmp .Lf1db426_001db50f\n"
        ".Lf1db426_001db736:\n"
        "andl $0xfdfeffff, %edx\n" /* line 542 */
        "movl %edx, 0xfea43c\n"
        "jmp .Lf1db426_001db5c3\n"
        ".Lf1db426_001db747:\n"
        "movl $0x26a8, 8(%esp)\n" /* line 560 */
        "movl %esi, 4(%esp)\n"
        "movl -0xa4(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "leal -0x64(%ebp), %eax\n" /* line 563 */
        "movl %eax, 4(%esp)\n"
        "movl -0xa8(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetUserCmd\n"
        "movl 0x24(%ebx), %eax\n" /* line 570 */
        "addl $0xc, %eax\n"
        "movl $0x26a8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "movl 0x24(%ebx), %eax\n" /* line 571 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x25bb8(%ebx)\n"
        "movl -0xa4(%ebp), %edx\n" /* line 37 */
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 0x25bf0(%ebx)\n"
        "movl 0x30(%edx), %eax\n" /* line 38 */
        "movl %eax, 0x25bf4(%ebx)\n"
        "movl 0x24(%ebx), %eax\n" /* line 578 */
        "movl 0xc(%eax), %eax\n"
        "cmpl -0x64(%ebp), %eax\n"
        "jge .Lf1db426_001db7cd\n"
        "movl -0xac(%ebp), %eax\n" /* line 581 */
        "cmpl %eax, -0xa8(%ebp)\n"
        "jge .Lf1db426_001db83b\n"
        ".Lf1db426_001db7cd:\n"
        "xorl %esi, %esi\n"
        ".Lf1db426_001db7cf:\n"
        "movl 0x195f940, %ebx\n" /* line 661 */
        "movl (%ebx), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf1db426_001db803\n"
        "movl 0x195f584, %eax\n" /* line 662 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xfea404, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7f48, (%esp)\n" /* "[%i : %i] " */
        "calll Com_Printf\n"
        ".Lf1db426_001db803:\n"
        "testl %esi, %esi\n" /* line 664 */
        "jne .Lf1db426_001dba18\n"
        "movl (%ebx), %eax\n" /* line 666 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1db426_001dba5b\n"
        ".Lf1db426_001db818:\n"
        "movl -0xa4(%ebp), %eax\n" /* line 676 */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x25bc4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_TransitionPlayerState\n"
        "jmp .Lf1db426_001db476\n"
        ".Lf1db426_001db83b:\n"
        "xorl %esi, %esi\n" /* line 581 */
        "jmp .Lf1db426_001db858\n"
        ".Lf1db426_001db83f:\n"
        "addl $1, -0xac(%ebp)\n"
        "movl -0xac(%ebp), %edx\n"
        "cmpl %edx, -0xa8(%ebp)\n"
        "jl .Lf1db426_001db7cf\n"
        ".Lf1db426_001db858:\n"
        "movl $0xfea404, 4(%esp)\n" /* line 584 */
        "movl -0xac(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetUserCmd\n"
        "movl 0xfea404, %edx\n" /* line 587 */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %ebx\n"
        "cmpl 0x25bc4(%ebx), %edx\n"
        "jle .Lf1db426_001db83f\n"
        "cmpl -0x64(%ebp), %edx\n" /* line 591 */
        "jg .Lf1db426_001db83f\n"
        "movl $0xfea420, 4(%esp)\n" /* line 596 */
        "movl -0xac(%ebp), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetUserCmd\n"
        "testl %eax, %eax\n"
        "je .Lf1db426_001db83f\n"
        "movl 0x25bc4(%ebx), %eax\n" /* line 604 */
        "movl -0xa4(%ebp), %edx\n"
        "cmpl (%edx), %eax\n"
        "je .Lf1db426_001dbabd\n"
        ".Lf1db426_001db8b9:\n"
        "movl $cg_pmove, (%esp)\n" /* line 651 */
        "calll Pmove\n"
        "movl 0x195f584, %eax\n" /* line 427 */
        "movl (%eax), %eax\n"
        "movl 0x25bc8(%eax), %edx\n"
        "cmpl $5, %edx\n"
        "jg .Lf1db426_001dba0e\n"
        "xorl %eax, %eax\n" /* line 432 */
        "cmpl $4, %edx\n"
        "sete %al\n"
        "movl %eax, -0x9c(%ebp)\n"
        "cmpl $1, %edx\n" /* line 434 */
        "jbe .Lf1db426_001db8f6\n"
        "testl %eax, %eax\n"
        "je .Lf1db426_001dba0e\n"
        ".Lf1db426_001db8f6:\n"
        "movl cg_numTriggerEntities, %esi\n" /* line 439 */
        "testl %esi, %esi\n"
        "jle .Lf1db426_001dba0e\n"
        "movl $0, -0xa0(%ebp)\n"
        "movl $cg_triggerEntities, -0x8c(%ebp)\n"
        "jmp .Lf1db426_001db94a\n"
        ".Lf1db426_001db91a:\n"
        "cmpl $0xffffff, 0x9c(%eax)\n" /* line 450 */
        "je .Lf1db426_001dba6c\n"
        ".Lf1db426_001db92a:\n"
        "addl $1, -0xa0(%ebp)\n" /* line 439 */
        "addl $4, -0x8c(%ebp)\n"
        "movl -0xa0(%ebp), %eax\n"
        "cmpl cg_numTriggerEntities, %eax\n"
        "jge .Lf1db426_001dba0e\n"
        ".Lf1db426_001db94a:\n"
        "movl -0x8c(%ebp), %eax\n" /* line 441 */
        "movl (%eax), %ebx\n"
        "leal 0xf0(%ebx), %eax\n" /* line 442 */
        "cmpl $3, 4(%eax)\n" /* line 444 */
        "jne .Lf1db426_001db91a\n"
        "movl -0x9c(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1db426_001db91a\n"
        "movl 0x195f944, %eax\n" /* line 384 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1db426_001db92a\n"
        "movl 0x195f584, %eax\n" /* line 387 */
        "movl (%eax), %esi\n"
        "movl 0x25bb0(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x25bc4(%esi), %edx\n"
        "movl %edx, -0xb8(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll BG_PlayerTouchesItem\n"
        "testl %eax, %eax\n"
        "je .Lf1db426_001db92a\n"
        "movl 0x1e8(%ebx), %eax\n" /* line 391 */
        "cmpl 0x25bb0(%esi), %eax\n"
        "je .Lf1db426_001db92a\n"
        "movl $1, 8(%esp)\n" /* line 394 */
        "movl -0xb8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll BG_CanItemBeGrabbed\n"
        "testl %eax, %eax\n"
        "je .Lf1db426_001db92a\n"
        "orl $0x20, 0xf8(%ebx)\n" /* line 398 */
        "movl 0x25bb0(%esi), %eax\n" /* line 401 */
        "movl %eax, 0x1e8(%ebx)\n"
        "movl -0xb8(%ebp), %edx\n" /* line 404 */
        "movl %edx, 8(%esp)\n"
        "movl 0x17c(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x90, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf1db426_001db92a\n"
        ".Lf1db426_001dba0e:\n"
        "movl $1, %esi\n" /* line 439 */
        "jmp .Lf1db426_001db83f\n"
        ".Lf1db426_001dba18:\n"
        "movl 0x195f584, %eax\n" /* line 672 */
        "movl (%eax), %edx\n"
        "leal 0x25bd8(%edx), %ecx\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl 0x25bb0(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x25bb8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x25c24(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll CG_AdjustPositionForMover\n"
        "jmp .Lf1db426_001db818\n"
        ".Lf1db426_001dba5b:\n"
        "movl $0x2b7f54, (%esp)\n" /* line 667 */
        "calll Com_Printf\n"
        "jmp .Lf1db426_001db818\n"
        ".Lf1db426_001dba6c:\n"
        "movl 0x8c(%eax), %edx\n" /* line 455 */
        "testl %edx, %edx\n" /* line 456 */
        "je .Lf1db426_001db92a\n"
        "movl 0x195f584, %eax\n" /* line 459 */
        "movl (%eax), %eax\n"
        "addl $0x25bd8, %eax\n"
        "movl $0xffffffff, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl $0xfea4d0, 0x10(%esp)\n"
        "movl $0xfea4c4, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x88(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_BoxTrace\n"
        "jmp .Lf1db426_001db92a\n"
        ".Lf1db426_001dbabd:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 610 */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x88(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x25bb4(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x25bb8(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x25c24(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x25bd8(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_AdjustPositionForMover\n"
        "movss 0x2ed644, %xmm0\n" /* line 612 | 182.04444885253906f */
        "mulss -0x28(%ebp), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x25c1c(%ebx)\n"
        "movl 0x195f940, %eax\n" /* line 614 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1db426_001dbcf2\n"
        "movl -0xa4(%ebp), %ebx\n"
        "addl $0x14, %ebx\n"
        "movl -0xa4(%ebp), %eax\n" /* line 310 */
        "movss 0x14(%eax), %xmm1\n"
        "ucomiss -0x88(%ebp), %xmm1\n"
        "jne .Lf1db426_001dbceb\n"
        "jp .Lf1db426_001dbceb\n"
        "movss 4(%ebx), %xmm0\n"
        "ucomiss -0x84(%ebp), %xmm0\n"
        "jne .Lf1db426_001dbceb\n"
        "jp .Lf1db426_001dbceb\n"
        "movss 8(%ebx), %xmm0\n"
        "ucomiss -0x80(%ebp), %xmm0\n"
        "jne .Lf1db426_001dbceb\n"
        "jp .Lf1db426_001dbceb\n"
        "movl $1, %eax\n"
        ".Lf1db426_001dbb81:\n"
        "testl %eax, %eax\n" /* line 616 */
        "je .Lf1db426_001dbd4b\n"
        ".Lf1db426_001dbb89:\n"
        "subss -0x88(%ebp), %xmm1\n" /* line 248 */
        "movss %xmm1, -0x90(%ebp)\n"
        "movss 4(%ebx), %xmm0\n" /* line 249 */
        "subss -0x84(%ebp), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "movss 8(%ebx), %xmm0\n" /* line 250 */
        "subss -0x80(%ebp), %xmm0\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm0\n"
        "movss -0x94(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0x98(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "ucomiss 0x2ed7d0, %xmm0\n" /* line 621 | 0.10000000149011612f */
        "jbe .Lf1db426_001db8b9\n"
        "movl 0x195f940, %esi\n" /* line 623 */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1db426_001dbd30\n"
        ".Lf1db426_001dbc0b:\n"
        "movl 0x195f86c, %eax\n" /* line 626 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm2\n"
        "jp .Lf1db426_001dbc26\n"
        "je .Lf1db426_001dbd05\n"
        ".Lf1db426_001dbc26:\n"
        "movl 0x195f584, %ebx\n" /* line 631 */
        "movl (%ebx), %eax\n"
        "movl 0x25bb0(%eax), %edx\n" /* line 632 */
        "subl 0x284c0(%eax), %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "divss %xmm2, %xmm1\n"
        "ucomiss %xmm1, %xmm3\n" /* line 633 */
        "ja .Lf1db426_001dbd67\n"
        "ucomiss %xmm3, %xmm1\n" /* line 636 */
        "jbe .Lf1db426_001dbc64\n"
        "movl (%esi), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1db426_001dbd6f\n"
        ".Lf1db426_001dbc64:\n"
        "movl (%ebx), %eax\n" /* line 639 */
        "leal 0x284c4(%eax), %edx\n"
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x284c4(%eax), %xmm0\n"
        "movss %xmm0, 0x284c4(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "mulss 8(%edx), %xmm1\n" /* line 274 */
        "movss %xmm1, 8(%edx)\n"
        ".Lf1db426_001dbc96:\n"
        "movl (%ebx), %edx\n" /* line 645 */
        "leal 0x284c4(%edx), %eax\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 240 */
        "addss 0x284c4(%edx), %xmm0\n"
        "movss %xmm0, 0x284c4(%edx)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 241 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 242 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movl 0x25bb4(%edx), %eax\n" /* line 646 */
        "movl %eax, 0x284c0(%edx)\n"
        "jmp .Lf1db426_001db8b9\n"
        ".Lf1db426_001dbceb:\n"
        "xorl %eax, %eax\n" /* line 310 */
        "jmp .Lf1db426_001dbb81\n"
        ".Lf1db426_001dbcf2:\n"
        "movl -0xa4(%ebp), %eax\n"
        "leal 0x14(%eax), %ebx\n"
        "movss 0x14(%eax), %xmm1\n"
        "jmp .Lf1db426_001dbb89\n"
        ".Lf1db426_001dbd05:\n"
        "movl 0x195f584, %ebx\n" /* line 643 */
        "movl (%ebx), %eax\n"
        "leal 0x284c4(%eax), %edx\n"
        "movl $0, 0x284c4(%eax)\n" /* line 183 */
        "movl $0, 4(%edx)\n" /* line 184 */
        "movl $0, 8(%edx)\n" /* line 185 */
        "jmp .Lf1db426_001dbc96\n"
        ".Lf1db426_001dbd30:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 624 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x2b7f10, (%esp)\n" /* "Prediction miss: %f
" */
        "calll Com_Printf\n"
        "jmp .Lf1db426_001dbc0b\n"
        ".Lf1db426_001dbd4b:\n"
        "movl $0x2b7efc, (%esp)\n" /* line 617 */
        "calll Com_Printf\n"
        "movl -0xa4(%ebp), %edx\n"
        "movss 0x14(%edx), %xmm1\n"
        "jmp .Lf1db426_001dbb89\n"
        ".Lf1db426_001dbd67:\n"
        "movaps %xmm3, %xmm1\n" /* line 633 */
        "jmp .Lf1db426_001dbc64\n"
        ".Lf1db426_001dbd6f:\n"
        "cvtss2sd %xmm1, %xmm0\n" /* line 637 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x2b7f28, (%esp)\n" /* "Double prediction decay: %f
" */
        "movss %xmm1, -0xd8(%ebp)\n"
        "calll Com_Printf\n"
        "movss -0xd8(%ebp), %xmm1\n"
        "jmp .Lf1db426_001dbc64\n"
        "movl %eax, %ebx\n"
        "movl %edi, (%esp)\n" /* line 678 */
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 115 */
static __attribute__((naked))
void Trace_CalcBounds(const vec_t *end, vec3_t *bounds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 115 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* end */
        "movl 0xc(%ebp), %esi\n" /* bounds */
        "movss (%eax), %xmm5\n" /* line 1203 | start */
        "movss (%ebx), %xmm2\n" /* end */
        "subss %xmm5, %xmm2\n"
        "mulss %xmm0, %xmm2\n" /* fraction */
        "addss %xmm5, %xmm2\n"
        "movss 4(%eax), %xmm1\n" /* line 1204 | start */
        "movss 4(%ebx), %xmm3\n" /* end */
        "subss %xmm1, %xmm3\n"
        "mulss %xmm0, %xmm3\n" /* fraction */
        "addss %xmm1, %xmm3\n"
        "movss 8(%eax), %xmm1\n" /* line 1205 | start */
        "movss 8(%ebx), %xmm4\n" /* end */
        "subss %xmm1, %xmm4\n"
        "mulss %xmm0, %xmm4\n" /* fraction */
        "addss %xmm1, %xmm4\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm5, %xmm0\n"
        "pxor %xmm6, %xmm6\n"
        "movaps %xmm5, %xmm1\n"
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "addss (%edx), %xmm0\n" /* line 120 | mins, fraction */
        "movss %xmm0, (%esi)\n" /* fraction, bounds */
        "movss 4(%eax), %xmm1\n" /* line 121 | start */
        "movaps %xmm3, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm1, %xmm5\n"
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        "addss 4(%edx), %xmm0\n" /* line 121 | mins, fraction */
        "movss %xmm0, 4(%esi)\n" /* fraction, bounds */
        "movss 8(%eax), %xmm1\n" /* line 122 | start */
        "movaps %xmm4, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm1, %xmm5\n"
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm4, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        "addss 8(%edx), %xmm0\n" /* line 122 | mins, fraction */
        "movss %xmm0, 8(%esi)\n" /* fraction, bounds */
        "leal 0xc(%esi), %edx\n" /* line 123 | bounds, mins */
        "movss (%eax), %xmm1\n" /* start */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm2, %xmm5\n"
        "cmpltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        "addss (%ecx), %xmm0\n" /* line 123 | maxs, fraction */
        "movss %xmm0, 0xc(%esi)\n" /* fraction, bounds */
        "movss 4(%eax), %xmm1\n" /* line 124 | start */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm3, %xmm0\n"
        "movaps %xmm3, %xmm2\n"
        "cmpltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "addss 4(%ecx), %xmm0\n" /* line 124 | maxs, fraction */
        "movss %xmm0, 4(%edx)\n" /* fraction, mins */
        "movss 8(%eax), %xmm1\n" /* line 125 | start */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm4, %xmm0\n"
        "movaps %xmm1, %xmm5\n"
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm4, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        "addss 8(%ecx), %xmm0\n" /* line 125 | maxs, fraction */
        "movss %xmm0, 8(%edx)\n" /* fraction, mins */
        "popl %ebx\n" /* line 126 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 135 */
__attribute__((naked))
void CG_ClipMoveToEntities(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int skipNumber, int mask, int capsule, trace_t *tr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 135 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        /* { scope 1 */
        "leal -0x54(%ebp), %eax\n" /* line 148 | bounds */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* end */
        "movl %edx, (%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* tr */
        "movss (%eax), %xmm0\n"
        "movl 0x10(%ebp), %ecx\n" /* maxs */
        "movl 0xc(%ebp), %edx\n" /* mins */
        "movl 8(%ebp), %eax\n" /* start */
        "calll Trace_CalcBounds\n"
        "movl cg_numSolidEntities, %eax\n" /* line 150 */
        "testl %eax, %eax\n"
        "jle .Lf1dbee4_001dc014\n"
        "movl $0, -0x80(%ebp)\n" /* i */
        "movl $cg_solidEntities, %edi\n"
        ".Lf1dbee4_001dbf2b:\n"
        "movl (%edi), %ebx\n" /* line 152 | cent */
        "leal 0xf0(%ebx), %esi\n" /* line 153 | cent, ent */
        "movl 0x18(%ebp), %edx\n" /* line 155 | skipNumber */
        "cmpl %edx, 0xf0(%ebx)\n" /* cent */
        "je .Lf1dbee4_001dbffe\n"
        "movl 0x9c(%esi), %edx\n" /* line 158 | ent */
        "cmpl $0xffffff, %edx\n"
        "je .Lf1dbee4_001dc139\n"
        "movl $0x2000000, %ecx\n" /* line 187 */
        "cmpl $1, 4(%esi)\n" /* ent */
        "movl $1, %eax\n"
        "cmovnel %eax, %ecx\n"
        "testl %ecx, 0x1c(%ebp)\n" /* line 197 | mask */
        "je .Lf1dbee4_001dbffe\n"
        "movzbl %dl, %eax\n" /* line 205 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss %xmm1, -0x24(%ebp)\n" /* bmins */
        "subss 0x2ed5d0, %xmm0\n" /* line 206 | 1.0f */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss %xmm0, -0x30(%ebp)\n" /* bmaxs */
        "movzbl %dh, %eax\n" /* line 207 */
        "subl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "subss %xmm0, %xmm4\n"
        "movss %xmm4, -0x1c(%ebp)\n"
        "sarl $0x10, %edx\n" /* line 208 */
        "movzbl %dl, %eax\n"
        "subl $0x20, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "subss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movss %xmm2, -0x28(%ebp)\n"
        "movss 0x1ec(%ebx), %xmm1\n" /* line 210 | cent */
        "movaps %xmm1, %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* bmins */
        "ucomiss -0x48(%ebp), %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "movss 0x1f0(%ebx), %xmm3\n" /* line 212 | cent */
        "movaps %xmm3, %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "ucomiss -0x44(%ebp), %xmm0\n"
        "jb .Lf1dbee4_001dc01f\n"
        ".Lf1dbee4_001dbffe:\n"
        "addl $1, -0x80(%ebp)\n" /* line 150 | i */
        "addl $4, %edi\n"
        "movl -0x80(%ebp), %eax\n" /* i */
        "cmpl cg_numSolidEntities, %eax\n"
        "jl .Lf1dbee4_001dbf2b\n"
        /* } scope */
        ".Lf1dbee4_001dc014:\n"
        "addl $0xbc, %esp\n" /* line 248 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1dbee4_001dc01f:\n"
        "addss -0x30(%ebp), %xmm1\n" /* line 214 | bmaxs */
        "movss -0x54(%ebp), %xmm0\n" /* bounds */
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "addss -0x2c(%ebp), %xmm3\n" /* line 216 */
        "movss -0x50(%ebp), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "movss 0x1f4(%ebx), %xmm1\n" /* line 218 | cent */
        "movaps %xmm4, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss -0x40(%ebp), %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "addss %xmm2, %xmm1\n" /* line 220 */
        "movss -0x4c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "movl %ecx, 8(%esp)\n" /* line 223 */
        "leal -0x30(%ebp), %eax\n" /* bmaxs */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* bmins */
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "movl %eax, -0x7c(%ebp)\n" /* cmodel */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x3c(%ebp)\n" /* angles */
        "movl %eax, -0x38(%ebp)\n" /* line 184 */
        "movl %eax, -0x34(%ebp)\n" /* line 185 */
        ".Lf1dbee4_001dc084:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 227 | angles */
        "movl %eax, 0x20(%esp)\n"
        "leal 0x1ec(%ebx), %eax\n" /* cent */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* mask */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x7c(%ebp), %edx\n" /* cmodel */
        "movl %edx, 0x14(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* maxs */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* mins */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll CM_TransformedBoxTraceExternal\n"
        "movss -0x78(%ebp), %xmm1\n" /* line 229 | trace */
        "movl 0x24(%ebp), %eax\n" /* tr */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1dbee4_001dc223\n"
        "cmpb $0, -0x56(%ebp)\n" /* line 235 */
        "je .Lf1dbee4_001dc20d\n"
        "movl (%esi), %eax\n" /* line 237 | ent */
        "movw %ax, -0x5c(%ebp)\n"
        "movl -0x78(%ebp), %eax\n" /* line 238 | trace */
        "movl 0x24(%ebp), %edx\n" /* tr */
        "movl %eax, (%edx)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        ".Lf1dbee4_001dc127:\n"
        "movl 0x24(%ebp), %edx\n" /* line 245 | tr */
        "cmpb $0, 0x22(%edx)\n"
        "je .Lf1dbee4_001dbffe\n"
        "jmp .Lf1dbee4_001dc014\n"
        ".Lf1dbee4_001dc139:\n"
        "movl 0x8c(%esi), %eax\n" /* line 160 | ent */
        "movl %eax, -0x7c(%ebp)\n" /* cmodel */
        "movl %eax, (%esp)\n" /* line 162 */
        "calll CM_ContentsOfModel\n"
        "testl %eax, 0x1c(%ebp)\n" /* line 164 | mask */
        "je .Lf1dbee4_001dbffe\n"
        "movl -0x7c(%ebp), %edx\n" /* line 167 | cmodel */
        "movl %edx, (%esp)\n"
        "calll CM_RadiusOfModel\n"
        "fstps -0x8c(%ebp)\n"
        "movss -0x8c(%ebp), %xmm2\n"
        "movss 0x1ec(%ebx), %xmm1\n" /* line 169 | cent */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0x48(%ebp), %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "movss 0x1f0(%ebx), %xmm3\n" /* line 171 | cent */
        "movaps %xmm3, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0x44(%ebp), %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "addss %xmm2, %xmm1\n" /* line 173 */
        "movss -0x54(%ebp), %xmm0\n" /* bounds */
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "addss %xmm2, %xmm3\n" /* line 175 */
        "movss -0x50(%ebp), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "movss 0x1f4(%ebx), %xmm1\n" /* line 177 | cent */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss -0x40(%ebp), %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "addss %xmm2, %xmm1\n" /* line 179 */
        "movss -0x4c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf1dbee4_001dbffe\n"
        "leal 0x1f8(%ebx), %edx\n" /* line 180 | cent */
        /* { scope 2 */
        "movl 0x1f8(%ebx), %eax\n" /* line 199 | cent */
        "movl %eax, -0x3c(%ebp)\n" /* angles */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x34(%ebp)\n"
        "jmp .Lf1dbee4_001dc084\n"
        /* } scope */
        ".Lf1dbee4_001dc20d:\n"
        "cmpb $0, -0x55(%ebp)\n" /* line 240 */
        "je .Lf1dbee4_001dc127\n"
        "movl 0x24(%ebp), %eax\n" /* line 242 | tr */
        "movb $1, 0x23(%eax)\n"
        "jmp .Lf1dbee4_001dc127\n"
        ".Lf1dbee4_001dc223:\n"
        "movl %eax, %edx\n"
        "movl (%esi), %eax\n" /* line 231 | ent */
        "movw %ax, -0x5c(%ebp)\n"
        "movl -0x78(%ebp), %eax\n" /* line 232 | trace */
        "movl %eax, (%edx)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "leal -0x54(%ebp), %eax\n" /* line 233 | bounds */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* end */
        "movl %edx, (%esp)\n"
        "movaps %xmm1, %xmm0\n"
        "movl 0x10(%ebp), %ecx\n" /* maxs */
        "movl 0xc(%ebp), %edx\n" /* mins */
        "movl 8(%ebp), %eax\n" /* start */
        "calll Trace_CalcBounds\n"
        "jmp .Lf1dbee4_001dc127\n"
    );
}

/* line 256 */
void CG_TraceCapsule(trace_t *result, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int skipNumber, int mask)
{
    CM_BoxTrace(result, start, end, mins, maxs, 0, mask);

    if (result->fraction == 1.0f) {
        result->entityNum = 1023;
    } else {
        result->entityNum = 1022;
    }

    if (result->fraction == 0.0f) {
        return;
    }

    CG_ClipMoveToEntities(start, mins, maxs, end, skipNumber, mask, 1, result);
}

/* line 65 */
void CG_BuildSolidList(void)
{
    int i;
    char *cg_s;
    char *snap;
    int numEntities;
    char *cg_entities_base;

    cg_numSolidEntities = 0;
    cg_numTriggerEntities = 0;

    cg_s = *(char **)(*(int *)0x195f584);
    snap = *(char **)(cg_s + 0x24);
    numEntities = *(int *)(snap + 0x26b4);
    cg_entities_base = *(char **)(*(int *)0x195f5cc);

    for (i = 0; i < numEntities; i++) {
        int entityNum = *(int *)(snap + 0x26bc + i * 0xf0);
        char *cent = cg_entities_base + entityNum * 548;
        char *ent = cent + 0xf0;

        if (*(int *)(ent + 0x9c) == 0xffffff) {
            if (*(unsigned char *)(ent + 8) & 1)
                continue;
            if (CM_ContentsOfModel(*(unsigned int *)(ent + 0x8c)) == 0)
                continue;
        }

        if (*(int *)(ent + 4) == 3) {
            cg_triggerEntities[cg_numTriggerEntities] = (centity_t *)cent;
            cg_numTriggerEntities++;
        } else if (*(int *)(ent + 0x9c) != 0) {
            ((centity_t **)&cg_solidEntities)[cg_numSolidEntities] = (centity_t *)cent;
            cg_numSolidEntities++;
        }
    }
}

