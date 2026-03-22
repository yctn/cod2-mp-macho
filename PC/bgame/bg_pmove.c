/* ASM dump from: bg_pmove.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_pmove.cpp */

#include "common_types.h"
#include "imports.h"
#include <math.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/q_shared.h"
 */

extern float AngleDelta(float angle1, float angle2);
extern float AngleNormalize360Accurate(float angle);
extern qboolean BG_CheckProne(int passEntityNum, const vec_t *vPos, const float fSize, const float fHeight, const float fYaw, float *pfTorsoHeight, float *pfTorsoPitch, float *pfWaistPitch, const qboolean bAlreadyProne, const qboolean bOnGround, vec_t *vGroundNormal, int handler, proneCheckType_t proneCheckType, float prone_feet_dist);
extern float Vec3Normalize(vec_t *v);
extern float Vec2Normalize(vec_t *v);
extern void Com_Printf(const char *fmt, ...);

extern pmoveHandler_t pmoveHandlers[2]; /* 0x0 */
__attribute__((used, aligned(4)))
UInt32 viewLerp_StandCrouch_storage[32] __asm__("viewLerp_StandCrouch") = {
    0x00000000, 0x42700000, 0x00000000, 0x00000001, 0x426e0000, 0x00000000, 0x00000004, 0x426a0000,
    0x00000000, 0x0000001e, 0x42600000, 0x00000000, 0x00000050, 0x42300000, 0x00000000, 0x0000005a,
    0x42260000, 0x00000000, 0x0000005f, 0x42220000, 0x00000000, 0x00000064, 0x42200000, 0x00000000,
    0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
}; /* 0x30a880 */
__attribute__((used, aligned(4)))
UInt32 viewLerp_CrouchStand_storage[32] __asm__("viewLerp_CrouchStand") = {
    0x00000000, 0x42200000, 0x00000000, 0x00000005, 0x42220000, 0x00000000, 0x0000000a, 0x42260000,
    0x00000000, 0x00000014, 0x42300000, 0x00000000, 0x00000046, 0x42600000, 0x00000000, 0x00000060,
    0x426a0000, 0x00000000, 0x00000063, 0x426e0000, 0x00000000, 0x00000064, 0x42700000, 0x00000000,
    0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
}; /* 0x30a7a0 */
__attribute__((used, aligned(4)))
UInt32 viewLerp_CrouchProne_storage[40] __asm__("viewLerp_CrouchProne") = {
    0x00000000, 0x42200000, 0x00000000, 0x0000000b, 0x42180000, 0x00000000, 0x00000016, 0x42040000,
    0x00000000, 0x00000022, 0x41c80000, 0x00000000, 0x0000002d, 0x41800000, 0x00000000, 0x00000032,
    0x41700000, 0x00000000, 0x00000037, 0x41800000, 0x00000000, 0x00000046, 0x41900000, 0x00000000,
    0x0000005a, 0x41880000, 0x00000000, 0x00000064, 0x41300000, 0x00000000, 0xffffffff, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
}; /* 0x30a900 */
__attribute__((used, aligned(4)))
UInt32 viewLerp_ProneCrouch_storage[24] __asm__("viewLerp_ProneCrouch") = {
    0x00000000, 0x41300000, 0x00000000, 0x00000005, 0x41200000, 0x00000000, 0x0000001e, 0x41a80000,
    0x00000000, 0x00000032, 0x41c80000, 0x00000000, 0x00000043, 0x41f80000, 0x00000000, 0x00000053,
    0x42080000, 0x00000000, 0x00000064, 0x42200000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000,
}; /* 0x30a820 */
static vec3_t CorrectSolidDeltas[26]; /* CorrectSolidDeltas */

void PM_trace(pmove_t *pm, trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentMask);
void PM_AddTouchEnt(pmove_t *pm, int entityNum);
void PM_AddEvent(playerState_t *ps, int newEvent);
int PM_GetEffectiveStance(playerState_t *ps);
int PM_GroundSurfaceType(pml_t *pml);
int PM_GetViewHeightLerpTime(const playerState_t *ps, int iTarget, qboolean bDown);
void PM_SetProneMovementOverride(playerState_t *ps);
float BG_GetSpeed(const playerState_t *ps, int time);
static qboolean BG_CheckProneTurned(void);
qboolean PM_ShouldMakeFootsteps(pmove_t *pm);
void PM_ClipVelocity(const vec_t *in, const vec_t *normal, vec_t *out);
static void PM_Accelerate(pml_t *pml);
static void PM_Friction(void);
void PM_UpdateLean(playerState_t *ps, float msec, usercmd_t *cmd, void (*capsuleTrace)());
void PM_UpdateViewAngles(playerState_t *ps, float msec, usercmd_t *cmd, int handler);
void PM_UpdatePronePitch(pmove_t *pm, pml_t *pml);
void PM_playerTrace(pmove_t *pm, trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentMask);
static void PM_SetMovementDir(void);
static void PM_AirMove(pmove_t *pm);
static void PM_LadderMove(pmove_t *pm);
static void PM_ViewHeightAdjust(pml_t *pml);
static void PM_CheckDuck(void);
void PM_FootstepEvent(pmove_t *pm, pml_t *pml, int iOldBobCycle, int iNewBobCycle, qboolean bFootStep);
static void PM_Footsteps(pml_t *pml);
static void PM_GroundTrace(pmove_t *pm, pml_t *pml);
void Pmove(pmove_t *pm);

/* line 247 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void PM_trace(pmove_t *pm, trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentMask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 247 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* results, pm */
        "movl %eax, -0x10(%ebp)\n" /* pm, results */
        "movl 0x10(%ebp), %eax\n" /* start, pm */
        "movl %eax, 0xc(%ebp)\n" /* pm, results */
        "movl 0x14(%ebp), %edi\n" /* mins */
        "movl 0x18(%ebp), %esi\n" /* maxs */
        "movl 0x1c(%ebp), %ebx\n" /* end */
        "movl 0x20(%ebp), %ecx\n" /* passEntityNum */
        "movl 8(%ebp), %eax\n" /* line 249 | pm */
        "movzbl 0xe4(%eax), %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x24(%ebp), %eax\n" /* contentMask */
        "movl %eax, 0x20(%ebp)\n" /* passEntityNum */
        "movl %ecx, 0x1c(%ebp)\n" /* end */
        "movl %ebx, 0x18(%ebp)\n" /* end, maxs */
        "movl %esi, 0x14(%ebp)\n" /* maxs, mins */
        "movl %edi, 0x10(%ebp)\n" /* mins, start */
        "movl -0x10(%ebp), %eax\n" /* results */
        "movl %eax, 8(%ebp)\n" /* pm */
        "movl pmoveHandlers(, %edx, 4), %ecx\n"
        "addl $4, %esp\n" /* line 250 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 249 */
    );
}
#else
void PM_trace(pmove_t *pm, trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentMask) {
    /* Look up the trace handler from pmoveHandlers[pm->handler].trace and tail-call it. */
    unsigned char handlerByte = pm->handler;
    pmove_trace handler = pmoveHandlers[handlerByte].trace;
    handler(results, start, mins, maxs, end, passEntityNum, contentMask);
}
#endif

/* line 294 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void PM_AddTouchEnt(pmove_t *pm, int entityNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 294 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* pm */
        "movl 0xc(%ebp), %esi\n" /* entityNum */
        /* { scope 1 */
        "cmpl $0x3fe, %esi\n" /* line 298 | entityNum */
        "je .Lf6bdc6_0006be00\n"
        "movl 0x40(%edi), %ebx\n" /* line 303 | pm */
        "cmpl $0x20, %ebx\n"
        "je .Lf6bdc6_0006be00\n"
        "testl %ebx, %ebx\n" /* line 309 */
        "jle .Lf6bdc6_0006be05\n"
        "cmpl 0x44(%edi), %esi\n" /* line 311 | pm, entityNum */
        "je .Lf6bdc6_0006be00\n"
        "movl %edi, %ecx\n" /* line 313 | pm */
        "xorl %edx, %edx\n"
        ".Lf6bdc6_0006bdef:\n"
        "addl $1, %edx\n" /* line 309 */
        "cmpl %edx, %ebx\n"
        "je .Lf6bdc6_0006be05\n"
        "movl 0x48(%ecx), %eax\n" /* line 311 */
        "addl $4, %ecx\n"
        "cmpl %eax, %esi\n" /* entityNum */
        "jne .Lf6bdc6_0006bdef\n"
        /* } scope */
        ".Lf6bdc6_0006be00:\n"
        "popl %ebx\n" /* line 320 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6bdc6_0006be05:\n"
        "movl %esi, 0x44(%edi, %ebx, 4)\n" /* line 318 | entityNum, pm */
        "addl $1, %ebx\n" /* line 319 */
        "movl %ebx, 0x40(%edi)\n" /* pm */
        /* } scope */
        "popl %ebx\n" /* line 320 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void PM_AddTouchEnt(pmove_t *pm, int entityNum) {
    int numtouch;
    int i;

    /* ENTITYNUM_WORLD = 0x3fe */
    if (entityNum == 0x3fe)
        return;

    numtouch = pm->numtouch;

    /* MAX_TOUCHENTS = 32 */
    if (numtouch == 0x20)
        return;

    /* Check if entityNum is already in the touch list */
    for (i = 0; i < numtouch; i++) {
        if (pm->touchents[i] == entityNum)
            return;
    }

    /* Add the entity */
    pm->touchents[numtouch] = entityNum;
    pm->numtouch = numtouch + 1;
}
#endif

void BG_AddPredictableEventToPlayerstate(int newEvent, int eventParm, playerState_t *ps);

/* line 283 */
void PM_AddEvent(playerState_t *ps, int newEvent)
{
    BG_AddPredictableEventToPlayerstate(newEvent, 0, ps);
}

/* line 348 */
int PM_GetEffectiveStance(playerState_t *ps)
{
    int val = ps->viewHeightTarget;

    if (val == 0x28)
        return 2;
    return val == 0xb;
}

/* line 816 */
int PM_GroundSurfaceType(pml_t *pml)
{
    int val = pml->groundTrace.surfaceFlags;

    if (val & 0x2000)
        return 0;
    return (val & 0x1f00000) >> 20;
}

/* line 1803 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
int PM_GetViewHeightLerpTime(const playerState_t *ps, int iTarget, qboolean bDown)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1803 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* iTarget */
        "cmpl $0xb, %eax\n" /* line 1806 */
        "je .Lf6be72_0006be90\n"
        "cmpl $0x28, %eax\n" /* line 1810 */
        "je .Lf6be72_0006be89\n"
        ".Lf6be72_0006be82:\n"
        "movl $0xc8, %eax\n" /* line 1812 */
        "popl %ebp\n" /* line 1826 */
        "retl\n"
        ".Lf6be72_0006be89:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1812 | bDown */
        "testl %eax, %eax\n"
        "jne .Lf6be72_0006be82\n"
        ".Lf6be72_0006be90:\n"
        "movl $0x190, %eax\n"
        "popl %ebp\n" /* line 1826 */
        "retl\n"
    );
}
#else
int PM_GetViewHeightLerpTime(const playerState_t *ps, int iTarget, qboolean bDown) {
    /* iTarget 0xb (11 = prone height) always returns 400ms */
    if (iTarget == 0xb)
        return 0x190; /* 400 */

    /* iTarget 0x28 (40 = stand height): if going down returns 200ms, else 400ms */
    if (iTarget == 0x28) {
        if (bDown)
            return 0xc8; /* 200 */
        return 0x190; /* 400 */
    }

    /* Default: 200ms */
    return 0xc8; /* 200 */
}
#endif

/* line 3954 */
void PM_SetProneMovementOverride(playerState_t *ps)
{
    int flags = ps->pm_flags;
    if (flags & 1)
        ps->pm_flags = flags | 0x800;
}

/* line 4728 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
float BG_GetSpeed(const playerState_t *ps, int time)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4728 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "movl 0xc(%ebp), %eax\n" /* time */
        "testb $0x20, 0xc(%edx)\n" /* line 4731 */
        "je .Lf6beae_0006bed3\n"
        "subl 0x70(%edx), %eax\n" /* line 4734 */
        "cmpl $0x1f3, %eax\n"
        "jle .Lf6beae_0006becf\n"
        "flds 0x28(%edx)\n" /* line 4737 */
        "leave\n" /* line 4743 */
        "retl\n"
        ".Lf6beae_0006becf:\n"
        "fldz\n" /* line 4734 */
        "leave\n" /* line 4743 */
        "retl\n"
        ".Lf6beae_0006bed3:\n"
        "movss 0x20(%edx), %xmm1\n" /* line 134 */
        "movss 0x24(%edx), %xmm0\n"
        "mulss %xmm1, %xmm1\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "movss %xmm1, -4(%ebp)\n"
        "flds -4(%ebp)\n"
        "leave\n" /* line 4743 */
        "retl\n"
    );
}
#else
float BG_GetSpeed(const playerState_t *ps, int time) {
    /* pm_flags bit 5 (0x20) = noclip/spectator jump */
    if (ps->pm_flags & 0x20) {
        /* Check if enough time has passed since jumpTime */
        int elapsed = time - ps->jumpTime;
        if (elapsed > 0x1f3) /* 499 */
            return ps->velocity[2];
        return 0.0f;
    }
    /* Compute 2D speed: sqrt(vx*vx + vy*vy) */
    {
        float vx = ps->velocity[0];
        float vy = ps->velocity[1];
        return sqrtf(vx * vx + vy * vy);
    }
}
#endif

/* line 3530 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
qboolean BG_CheckProneTurned(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3530 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "addl $-0x80, %esp\n"
        "movl %eax, %ebx\n" /* ps */
        "movl %edx, %esi\n" /* handler */
        /* { scope 1 */
        "movl 0xec(%eax), %eax\n" /* line 3537 */
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "calll AngleDelta\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 3538 */
        "andps CorrectSolidDeltas+336, %xmm0\n"
        "divss lit4_002ed6e8, %xmm0\n" /* 240.0f */
        "movss lit4_002ed5d0, %xmm2\n" /* line 3539 | 1.0f */
        "subss %xmm0, %xmm2\n"
        "mulss %xmm2, %xmm1\n"
        "movss -0x38(%ebp), %xmm3\n" /* newProneYaw */
        "subss %xmm1, %xmm3\n" /* newProneYaw */
        "movss %xmm3, (%esp)\n" /* newProneYaw */
        "movss %xmm0, -0x18(%ebp)\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "calll AngleNormalize360Accurate\n"
        "movss -0x18(%ebp), %xmm0\n" /* line 3543 */
        "mulss lit4_002ed6ec, %xmm0\n" /* 45.0f */
        "movss -0x28(%ebp), %xmm2\n"
        "mulss lit4_002ed6f0, %xmm2\n" /* 66.0f */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x34(%esp)\n"
        "movl $0, 0x30(%esp)\n"
        "movl %esi, %edx\n" /* handler */
        "movzbl %dl, %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl $0, 0x28(%esp)\n"
        "xorl %eax, %eax\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* ps */
        "setne %al\n"
        "movl %eax, 0x24(%esp)\n"
        "movl $1, 0x20(%esp)\n"
        "leal 0x5b0(%ebx), %eax\n" /* ps */
        "movl %eax, 0x1c(%esp)\n"
        "leal 0x5ac(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal 0x5a8(%ebx), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "fstps 0x10(%esp)\n"
        "movl $0x41f00000, 0xc(%esp)\n"
        "movl 0x578(%ebx), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "leal 0x14(%ebx), %eax\n" /* ps */
        "movl %eax, 4(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_CheckProne\n"
        /* } scope */
        "subl $-0x80, %esp\n" /* line 3544 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
/* Register-convention: eax=ps, edx=handler, xmm0=newProneYaw.
   Only called from asm in x86 mode. In Emscripten, callers use _impl directly. */
static qboolean BG_CheckProneTurned_impl(byte *ps_bytes, int handler, float newProneYaw)
{
    playerState_t *ps = (playerState_t *)ps_bytes;
    float oldProneYaw = ps->viewangles[1];
    float delta = AngleDelta(newProneYaw, oldProneYaw);
    float absDelta = (float)fabs(delta);
    float t = absDelta / 240.0f;
    float scale = 1.0f - t;
    float adjustedYaw = newProneYaw - (delta * scale);
    float normalizedYaw = AngleNormalize360Accurate(adjustedYaw);
    float proneFeetDist = t * 45.0f + scale * 66.0f;

    return BG_CheckProne(
        ps->clientNum,                             /* passEntityNum */
        ps->origin,                                /* vPos */
        ps->maxs[0],                               /* fSize */
        30.0f,                                     /* fHeight */
        normalizedYaw,                             /* fYaw */
        &ps->fTorsoHeight,                         /* pfTorsoHeight */
        &ps->fTorsoPitch,                          /* pfTorsoPitch */
        &ps->fWaistPitch,                          /* pfWaistPitch */
        1,                                         /* bAlreadyProne */
        ps->groundEntityNum != 0x3ff ? 1 : 0,     /* bOnGround */
        NULL,                                      /* vGroundNormal */
        (unsigned char)handler,                    /* handler */
        0,                                         /* proneCheckType */
        proneFeetDist                              /* prone_feet_dist */
    );
}
#endif

/* line 2723 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
qboolean PM_ShouldMakeFootsteps(pmove_t *pm)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2723 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* pm */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 2729 | pm */
        "movl 0xc(%eax), %edx\n" /* line 2732 */
        "movl %edx, %ecx\n"
        "andl $0x100, %ecx\n"
        "movl 0xf4(%eax), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "je .Lf6c00a_0006c04e\n"
        "cmpl $0xb, %eax\n" /* line 353 */
        "je .Lf6c00a_0006c04e\n"
        "testl %ecx, %ecx\n" /* line 2759 */
        "jne .Lf6c00a_0006c04e\n"
        "movl imp_player_footstepsThreshhold, %eax\n" /* line 2760 */
        "movl (%eax), %eax\n"
        "movss 0xdc(%ebx), %xmm0\n" /* pm */
        "ucomiss 8(%eax), %xmm0\n"
        "setae %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 2768 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6c00a_0006c04e:\n"
        "xorl %eax, %eax\n" /* line 2760 */
        /* } scope */
        "popl %ebx\n" /* line 2768 */
        "popl %ebp\n"
        "retl\n"
    );
}
#else
qboolean PM_ShouldMakeFootsteps(pmove_t *pm) {
    playerState_t *ps = pm->ps;
    int flags, hasSprintFlag, stance;

    flags = ps->pm_flags;
    hasSprintFlag = flags & 0x100;

    /* Check stance via viewHeightTarget */
    stance = ps->viewHeightTarget;
    if (stance == 0x28)  /* stand height (40) */
        return 0;
    if (stance == 0xb)   /* prone height (11) */
        return 0;

    /* Check sprint flag */
    if (hasSprintFlag)
        return 0;

    /* Compare pm->xyspeed with footsteps threshold dvar */
    {
        void *threshDvar = *(void **)imp_player_footstepsThreshhold;
        float threshold = *(float *)((byte *)threshDvar + 8);
        return pm->xyspeed >= threshold;
    }
}
#endif

/* line 330 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void PM_ClipVelocity(const vec_t *in, const vec_t *normal, vec_t *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 330 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* in */
        "movl 0xc(%ebp), %eax\n" /* normal */
        "movl 0x10(%ebp), %ecx\n" /* out */
        /* { scope 1 */
        "movss (%edx), %xmm4\n" /* line 304 */
        "movss (%eax), %xmm3\n"
        "movaps %xmm4, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm1\n" /* line 336 | scale */
        "andps CorrectSolidDeltas+352, %xmm1\n" /* scale */
        "mulss lit4_002ed670, %xmm1\n" /* -0.0010000000474974513f, scale */
        "addss %xmm2, %xmm1\n" /* scale */
        "xorps CorrectSolidDeltas+368, %xmm1\n" /* scale */
        /* { scope 2 */
        "mulss %xmm1, %xmm3\n" /* line 288 */
        "addss %xmm3, %xmm4\n"
        "movss %xmm4, (%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        "popl %ebp\n" /* line 337 */
        "retl\n"
    );
}
#else
void PM_ClipVelocity(const vec_t *in, const vec_t *normal, vec_t *out) {
    float dot, scale, overbounce;

    /* DotProduct(in, normal) */
    dot = in[0] * normal[0] + in[1] * normal[1] + in[2] * normal[2];

    /* Compute scale with overbounce:
       scale = dot + fabs(dot) * (-0.001f)
       overbounce = -scale */
    {
        float absDot = dot;
        if (absDot < 0.0f)
            absDot = -absDot;
        scale = dot + absDot * (-0.001f);
    }
    overbounce = -scale;

    /* out = in + normal * overbounce */
    out[0] = in[0] + normal[0] * overbounce;
    out[1] = in[1] + normal[1] * overbounce;
    out[2] = in[2] + normal[2] * overbounce;
}
#endif

/* line 478 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void PM_Accelerate(pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 478 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %eax, %esi\n" /* ps */
        "movl %edx, -0x50(%ebp)\n"
        "movl %ecx, %edi\n" /* wishdir */
        "movaps %xmm0, %xmm3\n" /* wishspeed */
        "movaps %xmm1, %xmm4\n" /* accel */
        "testb $0x20, 0xc(%eax)\n" /* line 480 */
        "jne .Lf6c0d8_0006c209\n"
        /* { scope 1: oldVelocity, velocity */
        "leal 0x20(%eax), %ebx\n" /* line 491 */
        "leal 0x24(%eax), %eax\n" /* line 304 */
        "movl %eax, -0x4c(%ebp)\n"
        "leal 4(%ecx), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "leal 0x28(%esi), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "leal 8(%ecx), %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movss 0x20(%esi), %xmm0\n" /* line 492 | ps */
        "mulss (%ecx), %xmm0\n"
        "movss 0x24(%esi), %xmm1\n" /* ps */
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss 0x28(%esi), %xmm1\n" /* ps */
        "mulss 8(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n" /* wishspeed */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 493 | 0.0f */
        "jp .Lf6c0d8_0006c154\n"
        "jbe .Lf6c0d8_0006c1fe\n"
        ".Lf6c0d8_0006c154:\n"
        "movl imp_stopspeed, %eax\n" /* line 497 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "maxss %xmm3, %xmm2\n" /* wishspeed */
        "movl -0x50(%ebp), %eax\n" /* line 498 */
        "mulss 0x24(%eax), %xmm4\n" /* accel */
        "mulss %xmm4, %xmm2\n" /* accel */
        "minss %xmm2, %xmm0\n" /* line 499 */
        "movaps %xmm0, %xmm2\n"
        "cmpl $2, 4(%esi)\n" /* line 454 */
        "je .Lf6c0d8_0006c1c3\n"
        "movl imp_inertiaMax, %edx\n" /* line 457 */
        "movl (%edx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jae .Lf6c0d8_0006c1c3\n"
        "movss 0x2c(%esi), %xmm4\n" /* line 126 */
        "movss 0x30(%esi), %xmm3\n"
        "movaps %xmm4, %xmm0\n" /* line 461 */
        "mulss %xmm4, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "ucomisd lit8_00307c90, %xmm0\n" /* 0.0001 */
        "jp .Lf6c0d8_0006c2bc\n"
        "jae .Lf6c0d8_0006c2bc\n"
        ".Lf6c0d8_0006c1c3:\n"
        "movaps %xmm2, %xmm1\n" /* line 467 */
        ".Lf6c0d8_0006c1c6:\n"
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss (%edi), %xmm0\n"
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "movl -0x48(%ebp), %eax\n"
        "mulss (%eax), %xmm0\n"
        "movl -0x4c(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movl -0x40(%ebp), %eax\n" /* line 290 */
        "mulss (%eax), %xmm1\n"
        "movl -0x44(%ebp), %edx\n"
        "addss (%edx), %xmm1\n"
        "movss %xmm1, 8(%ebx)\n"
        /* } scope */
        ".Lf6c0d8_0006c1fe:\n"
        "addl $0xac, %esp\n" /* line 524 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: oldVelocity, velocity */
        ".Lf6c0d8_0006c209:\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%ecx), %xmm1\n"
        "movaps %xmm0, %xmm2\n" /* line 274 */
        "mulss 8(%ecx), %xmm2\n"
        "leal 0x20(%eax), %ebx\n" /* line 515 */
        "mulss (%ecx), %xmm0\n" /* line 248 */
        "subss 0x20(%eax), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* pushDir */
        "subss 0x24(%eax), %xmm1\n" /* line 249 */
        "movss %xmm1, -0x28(%ebp)\n"
        "subss 0x28(%eax), %xmm2\n" /* line 250 */
        "movss %xmm2, -0x24(%ebp)\n"
        "leal -0x2c(%ebp), %eax\n" /* line 516 | pushDir */
        "movl %eax, (%esp)\n"
        "movss %xmm3, -0x78(%ebp)\n" /* wishspeed */
        "movss %xmm4, -0x88(%ebp)\n" /* accel */
        "calll Vec3Normalize\n"
        "fstps -0x3c(%ebp)\n" /* pushLen */
        "movss -0x88(%ebp), %xmm4\n" /* line 518 | accel */
        "movaps %xmm4, %xmm1\n" /* accel */
        "movl -0x50(%ebp), %eax\n"
        "mulss 0x24(%eax), %xmm1\n"
        "movss -0x78(%ebp), %xmm3\n" /* wishspeed */
        "mulss %xmm3, %xmm1\n" /* wishspeed */
        "movss -0x3c(%ebp), %xmm0\n" /* line 519 | pushLen */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* line 288 | pushDir */
        "addss 0x20(%esi), %xmm0\n"
        "movss %xmm0, 0x20(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x28(%ebp), %xmm0\n"
        "addss 0x24(%esi), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "mulss -0x24(%ebp), %xmm1\n" /* line 290 */
        "addss 0x28(%esi), %xmm1\n"
        "movss %xmm1, 8(%ebx)\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 524 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: oldVelocity, velocity */
        /* { scope 2 */
        ".Lf6c0d8_0006c2bc:\n"
        "movaps %xmm2, %xmm0\n" /* line 100 */
        "mulss (%edi), %xmm0\n"
        "addss 0x20(%esi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* pushDir */
        "movaps %xmm2, %xmm0\n" /* line 101 */
        "mulss 4(%edi), %xmm0\n"
        "addss 0x24(%esi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss %xmm4, -0x20(%ebp)\n" /* line 37 | oldVelocity */
        "movss %xmm3, -0x1c(%ebp)\n" /* line 38 */
        "leal -0x20(%ebp), %eax\n" /* line 435 | oldVelocity */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x68(%ebp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "leal -0x2c(%ebp), %eax\n" /* line 436 | pushDir */
        "movl %eax, (%esp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 114 | oldVelocity */
        "mulss -0x2c(%ebp), %xmm1\n" /* pushDir */
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl imp_inertiaAngle, %eax\n" /* line 439 */
        "movl (%eax), %eax\n"
        "ucomiss 8(%eax), %xmm1\n"
        "movss -0x68(%ebp), %xmm2\n"
        "jae .Lf6c0d8_0006c1c3\n"
        "movl imp_inertiaDebug, %eax\n" /* line 442 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf6c0d8_0006c354\n"
        /* } scope */
        ".Lf6c0d8_0006c343:\n"
        "movl imp_inertiaMax, %eax\n" /* line 467 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "jmp .Lf6c0d8_0006c1c6\n"
        /* { scope 2 */
        ".Lf6c0d8_0006c354:\n"
        "cvtss2sd -0x28(%ebp), %xmm0\n" /* line 444 */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd -0x2c(%ebp), %xmm0\n" /* pushDir */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd -0x1c(%ebp), %xmm0\n"
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd -0x20(%ebp), %xmm0\n" /* oldVelocity */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 4(%esp)\n"
        "movl $str_0021be98, (%esp)\n" /* "angle is %f (oldVel is (%f,%f), vel is (%f, %f))
" */
        "calll Com_Printf\n"
        "movl imp_inertiaMax, %edx\n" /* line 445 */
        "movl (%edx), %eax\n"
        "cvtss2sd 8(%eax), %xmm0\n"
        "movsd %xmm0, 0xc(%esp)\n"
        "movss -0x68(%ebp), %xmm2\n"
        "cvtss2sd %xmm2, %xmm2\n"
        "movsd %xmm2, 4(%esp)\n"
        "movl $str_0021becc, (%esp)\n" /* "clamping acceleration from %f to %f
" */
        "calll Com_Printf\n"
        "jmp .Lf6c0d8_0006c343\n"
    );
}

/* line 367 */
static __attribute__((naked))
void PM_Friction(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 367 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %esi\n" /* ps */
        "movl %edx, %edi\n" /* pml */
        /* { scope 1 */
        "leal 0x20(%eax), %ebx\n" /* line 375 | vel */
        "movss 0x20(%eax), %xmm0\n" /* line 199 */
        "movss 4(%ebx), %xmm1\n" /* line 200 */
        "movss 8(%ebx), %xmm2\n" /* line 201 */
        "movl 0x2c(%edx), %eax\n" /* line 378 */
        "testl %eax, %eax\n"
        "je .Lf6c3ca_0006c466\n"
        "pxor %xmm2, %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm2\n"
        "ucomiss lit4_002ed5d0, %xmm2\n" /* line 382 | 1.0f */
        "jb .Lf6c3ca_0006c487\n"
        ".Lf6c3ca_0006c411:\n"
        "testl %eax, %eax\n" /* line 390 */
        "jne .Lf6c3ca_0006c49b\n"
        ".Lf6c3ca_0006c419:\n"
        "pxor %xmm3, %xmm3\n" /* line 403 */
        "movaps %xmm3, %xmm1\n"
        ".Lf6c3ca_0006c420:\n"
        "cmpl $4, 4(%esi)\n" /* line 408 | ps */
        "je .Lf6c3ca_0006c4f4\n"
        ".Lf6c3ca_0006c42a:\n"
        "movaps %xmm2, %xmm0\n" /* line 413 */
        "subss %xmm1, %xmm0\n"
        "maxss %xmm0, %xmm3\n" /* line 414 */
        "movaps %xmm3, %xmm0\n"
        "divss %xmm2, %xmm0\n" /* line 418 */
        "movaps %xmm0, %xmm1\n" /* line 420 */
        "mulss (%ebx), %xmm1\n" /* vel */
        "movss %xmm1, (%ebx)\n" /* vel */
        "movaps %xmm0, %xmm1\n" /* line 421 */
        "mulss 4(%ebx), %xmm1\n" /* vel */
        "movss %xmm1, 4(%ebx)\n" /* vel */
        "mulss 8(%ebx), %xmm0\n" /* line 422 | vel */
        "movss %xmm0, 8(%ebx)\n" /* vel */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 423 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6c3ca_0006c466:\n"
        "mulss %xmm2, %xmm2\n" /* line 378 */
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm2\n"
        "ucomiss lit4_002ed5d0, %xmm2\n" /* line 382 | 1.0f */
        "jae .Lf6c3ca_0006c411\n"
        ".Lf6c3ca_0006c487:\n"
        "jp .Lf6c3ca_0006c411\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, (%ebx)\n"
        "movl %eax, 4(%ebx)\n" /* line 184 */
        "movl %eax, 8(%ebx)\n" /* line 185 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 423 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6c3ca_0006c49b:\n"
        "testb $2, 0x48(%edi)\n" /* line 390 | pml */
        "jne .Lf6c3ca_0006c419\n"
        "movl 0xc(%esi), %edx\n" /* line 393 | ps */
        "testb $4, %dh\n"
        "jne .Lf6c3ca_0006c419\n"
        "movl imp_stopspeed, %eax\n" /* line 395 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "maxss %xmm2, %xmm0\n"
        "testb $2, %dh\n" /* line 398 */
        "jne .Lf6c3ca_0006c50d\n"
        "andl $0x80000, %edx\n" /* line 400 */
        "je .Lf6c3ca_0006c515\n"
        "movl %esi, (%esp)\n" /* line 401 | ps */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss %xmm2, -0x48(%ebp)\n"
        "calll Jump_ReduceFriction\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss -0x48(%ebp), %xmm2\n"
        "jmp .Lf6c3ca_0006c515\n"
        ".Lf6c3ca_0006c4f4:\n"
        "movaps %xmm2, %xmm0\n" /* line 409 */
        "mulss lit4_002ed6d4, %xmm0\n" /* 5.0f */
        "mulss 0x24(%edi), %xmm0\n" /* pml */
        "addss %xmm0, %xmm1\n"
        "jmp .Lf6c3ca_0006c42a\n"
        ".Lf6c3ca_0006c50d:\n"
        "mulss lit4_002ed6f4, %xmm0\n" /* line 399 | 0.30000001192092896f */
        ".Lf6c3ca_0006c515:\n"
        "movl imp_friction, %eax\n" /* line 403 */
        "movl (%eax), %eax\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "mulss 0x24(%edi), %xmm1\n" /* pml */
        "pxor %xmm3, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "jmp .Lf6c3ca_0006c420\n"
    );
}

/* line 3407 */
__attribute__((naked))
void PM_UpdateLean(playerState_t *ps, float msec, usercmd_t *cmd, void (*capsuleTrace)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3407 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xa0, %esp\n"
        "movl 8(%ebp), %esi\n" /* ps */
        "movss 0xc(%ebp), %xmm3\n" /* msec */
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 3417 | cmd */
        "movl 4(%eax), %ecx\n"
        "testb $0xc0, %cl\n"
        "je .Lf6c536_0006c55f\n"
        "cmpw $0, 0xc(%esi)\n" /* ps */
        "jns .Lf6c536_0006c5fc\n"
        ".Lf6c536_0006c55f:\n"
        "xorl %edx, %edx\n" /* line 3424 */
        ".Lf6c536_0006c561:\n"
        "testl $0x300, 0xa0(%esi)\n" /* line 3438 | ps */
        "movl $0, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl 0xf4(%esi), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "je .Lf6c536_0006c587\n"
        "cmpl $0xb, %eax\n" /* line 353 */
        "je .Lf6c536_0006c749\n"
        ".Lf6c536_0006c587:\n"
        "movss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        ".Lf6c536_0006c58f:\n"
        "movss 0x4c(%esi), %xmm0\n" /* line 3451 | ps */
        "cmpl $0, %edx\n" /* line 3453 */
        "jne .Lf6c536_0006c5d8\n"
        "pxor %xmm4, %xmm4\n" /* line 3455 */
        "ucomiss %xmm4, %xmm0\n"
        "jbe .Lf6c536_0006c77b\n"
        "movaps %xmm3, %xmm1\n" /* line 3457 */
        "divss lit4_002ed6f8, %xmm1\n" /* -280.0f */
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm1, %xmm4\n" /* line 3458 */
        "ja .Lf6c536_0006c7d4\n"
        ".Lf6c536_0006c5c2:\n"
        "movss %xmm1, 0x4c(%esi)\n" /* line 3488 | ps */
        "ucomiss %xmm4, %xmm1\n" /* line 3493 */
        "jp .Lf6c536_0006c631\n"
        "jne .Lf6c536_0006c631\n"
        /* } scope */
        ".Lf6c536_0006c5ce:\n"
        "addl $0xa0, %esp\n" /* line 3519 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6c536_0006c5d8:\n"
        "jle .Lf6c536_0006c788\n" /* line 3470 */
        "ucomiss %xmm0, %xmm2\n" /* line 3472 */
        "ja .Lf6c536_0006c756\n"
        "movaps %xmm0, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 3475 */
        "jbe .Lf6c536_0006c772\n"
        ".Lf6c536_0006c5f3:\n"
        "movaps %xmm2, %xmm1\n"
        "pxor %xmm4, %xmm4\n"
        "jmp .Lf6c536_0006c5c2\n"
        ".Lf6c536_0006c5fc:\n"
        "movl 4(%esi), %eax\n" /* line 3417 | ps */
        "cmpl $5, %eax\n"
        "jg .Lf6c536_0006c55f\n"
        "cmpl $0x3ff, 0x60(%esi)\n" /* ps */
        "je .Lf6c536_0006c7dc\n"
        ".Lf6c536_0006c615:\n"
        "movl %ecx, %eax\n" /* line 3421 */
        "andl $0x40, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %edx, %edx\n"
        "notl %edx\n"
        "testb %cl, %cl\n" /* line 3423 */
        "jns .Lf6c536_0006c561\n"
        "addl $1, %edx\n" /* line 3424 */
        "jmp .Lf6c536_0006c561\n"
        ".Lf6c536_0006c631:\n"
        "leal 0x14(%esi), %eax\n" /* line 3493 | ps */
        /* { scope 2 */
        "movl 0x14(%esi), %ecx\n" /* line 199 */
        "movl %ecx, -0x14(%ebp)\n" /* start */
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0x10(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        /* } scope */
        "addss 0xf8(%esi), %xmm0\n" /* line 3505 | ps */
        "movss %xmm0, -0xc(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n" /* line 199 | end */
        "movl %edx, -0x1c(%ebp)\n" /* line 200 */
        "movss %xmm0, -0x18(%ebp)\n" /* line 201 */
        "movl $0x41a00000, 0x10(%esp)\n" /* line 3508 */
        "movl $0x41800000, 0xc(%esp)\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm1, %xmm4\n"
        "seta %al\n"
        "addl %eax, %eax\n"
        "negl %eax\n"
        "addl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl 0xec(%esi), %eax\n" /* ps */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %ebx\n" /* end */
        "movl %ebx, (%esp)\n"
        "movss %xmm4, -0x88(%ebp)\n"
        "calll AddLeanToPosition\n"
        "movl $0xc1000000, %eax\n" /* line 191 */
        "movl %eax, -0x2c(%ebp)\n" /* tmins */
        "movl %eax, -0x28(%ebp)\n" /* line 192 */
        "movl %eax, -0x24(%ebp)\n" /* line 193 */
        "movl $0x41000000, %eax\n" /* line 191 */
        "movl %eax, -0x38(%ebp)\n" /* tmaxs */
        "movl %eax, -0x34(%ebp)\n" /* line 192 */
        "movl %eax, -0x30(%ebp)\n" /* line 193 */
        "movl $0x2810011, 0x18(%esp)\n" /* line 3513 */
        "movl 0xcc(%esi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* tmaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* tmins */
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "leal -0x5c(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* capsuleTrace */
        "movl -0x5c(%ebp), %eax\n" /* line 3515 | trace */
        "movl %eax, (%esp)\n"
        "calll UnGetLeanFraction\n"
        "fstps -0x6c(%ebp)\n"
        "movss 0x4c(%esi), %xmm1\n" /* line 3516 | ps */
        "movaps %xmm1, %xmm0\n"
        "andps CorrectSolidDeltas+400, %xmm0\n"
        "ucomiss -0x6c(%ebp), %xmm0\n"
        "movss -0x88(%ebp), %xmm4\n"
        "jbe .Lf6c536_0006c5ce\n"
        "xorl %eax, %eax\n" /* line 3517 */
        "ucomiss %xmm1, %xmm4\n"
        "seta %al\n"
        "addl %eax, %eax\n"
        "negl %eax\n"
        "addl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x6c(%ebp), %xmm0\n"
        "movss %xmm0, 0x4c(%esi)\n" /* ps */
        /* } scope */
        "addl $0xa0, %esp\n" /* line 3519 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6c536_0006c749:\n"
        "movss lit4_002ed604, %xmm2\n" /* line 353 | 0.25f */
        "jmp .Lf6c536_0006c58f\n"
        ".Lf6c536_0006c756:\n"
        "movaps %xmm3, %xmm1\n" /* line 3473 */
        "divss lit4_002ed700, %xmm1\n" /* 350.0f */
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 3475 */
        "ja .Lf6c536_0006c5f3\n"
        ".Lf6c536_0006c772:\n"
        "pxor %xmm4, %xmm4\n"
        "jmp .Lf6c536_0006c5c2\n"
        ".Lf6c536_0006c77b:\n"
        "ucomiss %xmm0, %xmm4\n" /* line 3461 */
        "ja .Lf6c536_0006c7b8\n"
        "movaps %xmm0, %xmm1\n" /* line 3483 */
        "jmp .Lf6c536_0006c5c2\n"
        ".Lf6c536_0006c788:\n"
        "movaps %xmm2, %xmm1\n" /* line 3480 */
        "xorps CorrectSolidDeltas+384, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf6c536_0006c7a7\n"
        "divss lit4_002ed704, %xmm3\n" /* line 3481 | -350.0f */
        "mulss %xmm3, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        ".Lf6c536_0006c7a7:\n"
        "ucomiss %xmm0, %xmm1\n" /* line 3483 */
        "ja .Lf6c536_0006c772\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf6c536_0006c5c2\n"
        ".Lf6c536_0006c7b8:\n"
        "movaps %xmm3, %xmm1\n" /* line 3463 */
        "divss lit4_002ed6fc, %xmm1\n" /* 280.0f */
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm4, %xmm1\n" /* line 3464 */
        "jbe .Lf6c536_0006c5c2\n"
        ".Lf6c536_0006c7d4:\n"
        "movaps %xmm4, %xmm1\n"
        "jmp .Lf6c536_0006c5c2\n"
        ".Lf6c536_0006c7dc:\n"
        "subl $1, %eax\n" /* line 3417 */
        "jne .Lf6c536_0006c55f\n"
        "jmp .Lf6c536_0006c615\n"
    );
}

/* line 3555 */
__attribute__((naked))
void PM_UpdateViewAngles(playerState_t *ps, float msec, usercmd_t *cmd, int handler)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3555 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 8(%ebp), %esi\n" /* ps */
        "movss 0xc(%ebp), %xmm0\n" /* msec */
        "movss %xmm0, -0x3c(%ebp)\n" /* msec */
        "movl 0x10(%ebp), %eax\n" /* cmd */
        "movl %eax, -0x40(%ebp)\n" /* cmd */
        "movzbl 0x14(%ebp), %edx\n" /* handler */
        "movb %dl, -0x41(%ebp)\n" /* handler */
        /* { scope 1 */
        "cmpl $5, 4(%esi)\n" /* line 3574 | ps */
        "je .Lf6c7ea_0006c920\n"
        "jg .Lf6c7ea_0006c92b\n" /* line 3578 */
        "movss 0xec(%esi), %xmm0\n" /* line 3592 | ps */
        "movss %xmm0, -0x34(%ebp)\n" /* oldViewYaw */
        "movl imp_player_view_pitch_up, %eax\n" /* line 3594 */
        "movl (%eax), %eax\n"
        "movss lit4_002ed644, %xmm1\n" /* 182.04444885253906f */
        "movss 8(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* minPitch */
        "movl imp_player_view_pitch_down, %eax\n" /* line 3595 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "andl $0xffff, %eax\n"
        "movl %eax, -0x8c(%ebp)\n" /* maxPitch */
        "movl -0x40(%ebp), %ecx\n" /* cmd */
        "movl %esi, %edx\n" /* ps */
        "xorl %ebx, %ebx\n" /* bRetry */
        "movss lit4_002ed648, %xmm1\n" /* 0.0054931640625f */
        "movl -0x24(%ebp), %eax\n" /* minPitch */
        "negl %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        ".Lf6c7ea_0006c883:\n"
        "movl 0x54(%edx), %eax\n" /* line 3600 */
        "addw 0xc(%ecx), %ax\n"
        "testl %ebx, %ebx\n" /* line 3601 | bRetry */
        "jne .Lf6c7ea_0006c992\n"
        "cwtl\n" /* line 3604 */
        "cmpl %eax, -0x8c(%ebp)\n" /* maxPitch */
        "jge .Lf6c7ea_0006c978\n"
        "movl -0x8c(%ebp), %eax\n" /* line 3606 | maxPitch */
        "movl -0x40(%ebp), %edi\n" /* cmd, i */
        "subl 0xc(%edi), %eax\n" /* i */
        "movl %eax, 0x54(%esi)\n" /* ps */
        "movswl -0x8c(%ebp), %eax\n" /* maxPitch */
        ".Lf6c7ea_0006c8b5:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 3616 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0xe8(%edx)\n"
        "addl $1, %ebx\n" /* line 3598 | bRetry */
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $3, %ebx\n" /* bRetry */
        "jne .Lf6c7ea_0006c883\n"
        "movss 0xec(%esi), %xmm0\n" /* line 3619 | ps */
        "movss %xmm0, -0x30(%ebp)\n" /* newViewYaw */
        "testl $0x300, 0xa0(%esi)\n" /* line 3621 | ps */
        "jne .Lf6c7ea_0006cbb8\n"
        "movl 0xc(%esi), %edx\n" /* line 3646 | ps */
        "testb $4, %dl\n"
        "jne .Lf6c7ea_0006cc86\n"
        "testb $0x20, %dl\n" /* line 3653 */
        "jne .Lf6c7ea_0006cae3\n"
        ".Lf6c7ea_0006c905:\n"
        "andb $1, %dl\n" /* line 3675 */
        "jne .Lf6c7ea_0006c998\n"
        ".Lf6c7ea_0006c90e:\n"
        "movl 4(%esi), %eax\n" /* line 3842 | ps */
        "cmpl $3, %eax\n"
        "je .Lf6c7ea_0006c920\n"
        "cmpl $2, %eax\n" /* line 3844 */
        "je .Lf6c7ea_0006c920\n"
        "cmpl $4, %eax\n" /* line 3852 */
        "jne .Lf6c7ea_0006c945\n"
        /* } scope */
        ".Lf6c7ea_0006c920:\n"
        "addl $0xcc, %esp\n" /* line 3857 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6c7ea_0006c92b:\n"
        "movl 0x58(%esi), %eax\n" /* line 3582 | ps */
        "movl -0x40(%ebp), %edi\n" /* cmd, i */
        "addw 0x10(%edi), %ax\n" /* i */
        "cmpl $0x3e7, 0x130(%esi)\n" /* line 3583 | ps */
        "je .Lf6c7ea_0006cc6a\n"
        ".Lf6c7ea_0006c945:\n"
        "movzbl -0x41(%ebp), %eax\n" /* line 3856 | handler */
        "leal (%eax, %eax, 2), %eax\n"
        "movl pmoveHandlers(, %eax, 4), %eax\n"
        "movl %eax, 0x14(%ebp)\n" /* handler */
        "movl -0x40(%ebp), %eax\n" /* cmd */
        "movl %eax, 0x10(%ebp)\n" /* cmd */
        "movss -0x3c(%ebp), %xmm0\n" /* msec */
        "movss %xmm0, 0xc(%ebp)\n" /* msec */
        "movl %esi, 8(%ebp)\n" /* ps */
        /* } scope */
        "addl $0xcc, %esp\n" /* line 3857 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp PM_UpdateLean\n" /* line 3856 */
        ".Lf6c7ea_0006c978:\n"
        "cmpl -0x50(%ebp), %eax\n" /* line 3609 */
        "jge .Lf6c7ea_0006c8b5\n"
        "movl -0x50(%ebp), %eax\n" /* line 3611 */
        "movl -0x40(%ebp), %edi\n" /* cmd, i */
        "subl 0xc(%edi), %eax\n" /* i */
        "movl %eax, 0x54(%esi)\n" /* ps */
        "movl -0x24(%ebp), %eax\n" /* line 3612 | minPitch */
        "negl %eax\n"
        ".Lf6c7ea_0006c992:\n"
        "cwtl\n"
        "jmp .Lf6c7ea_0006c8b5\n"
        ".Lf6c7ea_0006c998:\n"
        "testl $0x300, 0xa0(%esi)\n" /* line 3675 | ps */
        "jne .Lf6c7ea_0006c90e\n"
        "movl 0xec(%esi), %eax\n" /* line 3682 | ps */
        "movl %eax, 4(%esp)\n"
        "movl 0x584(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm1\n"
        "movl imp_bg_prone_yawcap, %eax\n" /* line 3686 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "subss lit4_002ed6d4, %xmm0\n" /* 5.0f */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf6c7ea_0006ca0a\n"
        "xorps CorrectSolidDeltas+416, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf6c7ea_0006ca0a\n"
        "movl -0x40(%ebp), %eax\n" /* cmd */
        "cmpw $0, 0x18(%eax)\n"
        "je .Lf6c7ea_0006d13e\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lf6c7ea_0006ca0a\n"
        "je .Lf6c7ea_0006d13e\n"
        ".Lf6c7ea_0006ca0a:\n"
        "movss -0x3c(%ebp), %xmm3\n" /* line 3688 | msec */
        "mulss lit4_002ed708, %xmm3\n" /* 55.0f */
        "movaps %xmm3, %xmm2\n"
        "mulss lit4_002ed658, %xmm2\n" /* 0.0010000000474974513f */
        "movaps %xmm1, %xmm0\n"
        "andps CorrectSolidDeltas+432, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf6c7ea_0006d054\n"
        "movss 0xec(%esi), %xmm0\n" /* line 3689 | ps */
        "movss %xmm0, -0x38(%ebp)\n" /* newProneYaw */
        ".Lf6c7ea_0006ca42:\n"
        "movzbl -0x41(%ebp), %edi\n" /* line 3693 | handler, i */
        "movl $0, -0x2c(%ebp)\n" /* proneBlocked */
        "movl $1, %ebx\n" /* bRetry */
        "leal 0x14(%esi), %eax\n" /* ps */
        "movl %eax, -0x4c(%ebp)\n"
        "jmp .Lf6c7ea_0006ca81\n"
        ".Lf6c7ea_0006ca5a:\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3723 | 0.0f */
        "jbe .Lf6c7ea_0006d015\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        ".Lf6c7ea_0006ca6f:\n"
        "addss -0x38(%ebp), %xmm1\n" /* line 3733 | newProneYaw */
        "movss %xmm1, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps -0x38(%ebp)\n" /* newProneYaw */
        ".Lf6c7ea_0006ca81:\n"
        "movl %edi, %edx\n" /* line 3699 | i */
        "movss -0x38(%ebp), %xmm0\n" /* newProneYaw */
        "movl %esi, %eax\n" /* ps */
        "calll BG_CheckProneTurned\n"
        "testl %eax, %eax\n"
        "jne .Lf6c7ea_0006ccb3\n"
        "testl %ebx, %ebx\n" /* line 3716 | bRetry */
        "je .Lf6c7ea_0006cd42\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 3719 | newProneYaw */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x584(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 3720 */
        "andps CorrectSolidDeltas+432, %xmm0\n"
        "xorl %ebx, %ebx\n" /* bRetry */
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "seta %bl\n" /* bRetry */
        "testl %ebx, %ebx\n" /* line 3721 | bRetry */
        "jne .Lf6c7ea_0006ca5a\n"
        "movl $1, -0x2c(%ebp)\n" /* proneBlocked */
        "jmp .Lf6c7ea_0006ca6f\n"
        ".Lf6c7ea_0006cae3:\n"
        "cmpl $0x3ff, 0x60(%esi)\n" /* line 3653 | ps */
        "jne .Lf6c7ea_0006c905\n"
        "movl imp_bg_ladder_yawcap, %ebx\n" /* bRetry */
        "movl (%ebx), %eax\n" /* bRetry */
        "pxor %xmm0, %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "jp .Lf6c7ea_0006cb08\n"
        "je .Lf6c7ea_0006c905\n"
        ".Lf6c7ea_0006cb08:\n"
        "leal 0x64(%esi), %eax\n" /* line 3655 | ps */
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm3\n"
        "addss lit4_002ed64c, %xmm3\n" /* 180.0f */
        "movl 0xec(%esi), %eax\n" /* line 3656 | ps */
        "movl %eax, 4(%esp)\n"
        "movss %xmm3, (%esp)\n"
        "movss %xmm3, -0x78(%ebp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm2\n"
        "movl (%ebx), %eax\n" /* line 3657 | bRetry */
        "movss 8(%eax), %xmm1\n"
        "ucomiss %xmm1, %xmm2\n"
        "movss -0x78(%ebp), %xmm3\n"
        "ja .Lf6c7ea_0006d18b\n"
        "movaps %xmm1, %xmm0\n"
        "xorps CorrectSolidDeltas+416, %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf6c7ea_0006d24b\n"
        "addss %xmm2, %xmm1\n" /* line 3663 */
        ".Lf6c7ea_0006cb70:\n"
        "movaps %xmm1, %xmm0\n" /* line 3665 */
        "mulss lit4_002ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x58(%esi)\n" /* ps */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3667 | 0.0f */
        "jbe .Lf6c7ea_0006d22f\n"
        "movl imp_bg_ladder_yawcap, %eax\n" /* line 3668 */
        "movl (%eax), %eax\n"
        "subss 8(%eax), %xmm3\n"
        "movss %xmm3, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps 0xec(%esi)\n" /* ps */
        "movl 0xc(%esi), %edx\n" /* ps */
        "jmp .Lf6c7ea_0006c905\n"
        ".Lf6c7ea_0006cbb8:\n"
        "xorl %edi, %edi\n" /* line 3621 | i */
        "leal 0x114(%esi), %ebx\n" /* ps, bRetry */
        "movl -0x2c(%ebx), %eax\n" /* line 3625 | bRetry */
        "movl %eax, 4(%esp)\n"
        "movl -8(%ebx), %eax\n" /* bRetry */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm2\n"
        "movss (%ebx), %xmm1\n" /* line 3627 | bRetry */
        "ucomiss %xmm1, %xmm2\n"
        "ja .Lf6c7ea_0006cc61\n"
        ".Lf6c7ea_0006cbe3:\n"
        "movaps %xmm1, %xmm0\n"
        "xorps CorrectSolidDeltas+416, %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf6c7ea_0006cc2f\n"
        "addss %xmm2, %xmm1\n" /* line 3632 */
        ".Lf6c7ea_0006cbf6:\n"
        "movaps %xmm1, %xmm0\n" /* line 3634 */
        "mulss lit4_002ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, -0xc0(%ebx)\n" /* bRetry */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3636 | 0.0f */
        "jbe .Lf6c7ea_0006cc98\n"
        "movss -8(%ebx), %xmm0\n" /* line 3637 | bRetry */
        "subss (%ebx), %xmm0\n" /* bRetry */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps -0x2c(%ebx)\n" /* bRetry */
        ".Lf6c7ea_0006cc2f:\n"
        "addl $1, %edi\n" /* line 3623 | i */
        "addl $4, %ebx\n" /* bRetry */
        "cmpl $2, %edi\n" /* i */
        "je .Lf6c7ea_0006c920\n"
        "movl -0x2c(%ebx), %eax\n" /* line 3625 | bRetry */
        "movl %eax, 4(%esp)\n"
        "movl -8(%ebx), %eax\n" /* bRetry */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm2\n"
        "movss (%ebx), %xmm1\n" /* line 3627 | bRetry */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf6c7ea_0006cbe3\n"
        ".Lf6c7ea_0006cc61:\n"
        "subss %xmm1, %xmm2\n" /* line 3630 */
        "movaps %xmm2, %xmm1\n"
        "jmp .Lf6c7ea_0006cbf6\n"
        ".Lf6c7ea_0006cc6a:\n"
        "cwtl\n" /* line 3584 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed648, %xmm0\n" /* 0.0054931640625f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x130(%esi)\n" /* ps */
        "jmp .Lf6c7ea_0006c945\n"
        ".Lf6c7ea_0006cc86:\n"
        "movl %esi, 8(%ebp)\n" /* line 3648 | ps */
        /* } scope */
        "addl $0xcc, %esp\n" /* line 3857 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Mantle_CapView\n" /* line 3648 */
        ".Lf6c7ea_0006cc98:\n"
        "movss -8(%ebx), %xmm0\n" /* line 3639 | bRetry */
        "addss (%ebx), %xmm0\n" /* bRetry */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps -0x2c(%ebx)\n" /* bRetry */
        "jmp .Lf6c7ea_0006cc2f\n"
        ".Lf6c7ea_0006ccb3:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 3701 */
        "movl %edx, -0x48(%ebp)\n"
        "movl $0x42340000, 0x34(%esp)\n"
        "movl $0, 0x30(%esp)\n"
        "movl %edi, 0x2c(%esp)\n" /* i */
        "movl $0, 0x28(%esp)\n"
        "xorl %eax, %eax\n"
        "cmpl $0x3ff, 0x60(%esi)\n" /* ps */
        "setne %al\n"
        "movl %eax, 0x24(%esp)\n"
        "movl $1, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0xec(%esi), %eax\n" /* ps */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41f00000, 0xc(%esp)\n"
        "movl 0x578(%esi), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xcc(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_CheckProne\n"
        "testl %eax, %eax\n" /* line 3703 */
        "jne .Lf6c7ea_0006d197\n"
        ".Lf6c7ea_0006cd3b:\n"
        "movl $1, -0x2c(%ebp)\n" /* line 3697 | proneBlocked */
        ".Lf6c7ea_0006cd42:\n"
        "movl 0xec(%esi), %eax\n" /* line 3737 | ps */
        "movl %eax, 4(%esp)\n"
        "movl 0x584(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3738 | 0.0f */
        "jp .Lf6c7ea_0006cd71\n"
        "je .Lf6c7ea_0006cee5\n"
        ".Lf6c7ea_0006cd71:\n"
        "movss 0x584(%esi), %xmm0\n" /* line 3740 | ps */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movzbl -0x41(%ebp), %eax\n" /* handler */
        "movl %eax, -0x20(%ebp)\n"
        "movl $1, %edi\n" /* i */
        "leal 0x14(%esi), %edx\n" /* ps */
        "movl %edx, -0x48(%ebp)\n"
        "jmp .Lf6c7ea_0006ce04\n"
        ".Lf6c7ea_0006cd92:\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3762 | 0.0f */
        "jbe .Lf6c7ea_0006d022\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed644, %xmm0\n" /* 182.04444885253906f */
        ".Lf6c7ea_0006cdaf:\n"
        "cvttss2si %xmm0, %eax\n" /* line 3770 */
        "andl $0xffff, %eax\n"
        "addl %eax, 0x58(%esi)\n" /* ps */
        "addss 0xec(%esi), %xmm1\n" /* line 3771 | ps */
        "movss %xmm1, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fsts 0xec(%esi)\n" /* ps */
        "fstps 4(%esp)\n" /* line 3772 */
        "movl 0x584(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm1\n"
        "testl %ebx, %ebx\n" /* line 3774 | bRetry */
        "je .Lf6c7ea_0006cff0\n"
        ".Lf6c7ea_0006cdf5:\n"
        "movl $1, -0x2c(%ebp)\n" /* line 3740 | proneBlocked */
        "movl -0x20(%ebp), %eax\n"
        "movss -0x1c(%ebp), %xmm0\n"
        ".Lf6c7ea_0006ce04:\n"
        "movl $0x42340000, 0x34(%esp)\n" /* line 3745 */
        "movl $0, 0x30(%esp)\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl $0, 0x28(%esp)\n"
        "xorl %eax, %eax\n"
        "cmpl $0x3ff, 0x60(%esi)\n" /* ps */
        "setne %al\n"
        "movl %eax, 0x24(%esp)\n"
        "movl $1, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl $0x41f00000, 0xc(%esp)\n"
        "movl 0x578(%esi), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xcc(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "calll BG_CheckProne\n"
        "movl %eax, %ebx\n" /* bRetry */
        "testl %eax, %eax\n" /* line 3747 */
        "movss -0x68(%ebp), %xmm1\n"
        "jne .Lf6c7ea_0006cec0\n"
        ".Lf6c7ea_0006ce8d:\n"
        "testl %edi, %edi\n" /* line 3756 | i */
        "je .Lf6c7ea_0006cee5\n"
        "movaps %xmm1, %xmm0\n" /* line 3759 */
        "andps CorrectSolidDeltas+432, %xmm0\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "seta %al\n"
        "movzbl %al, %edi\n" /* i */
        "testl %edi, %edi\n" /* line 3760 | i */
        "jne .Lf6c7ea_0006cd92\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed644, %xmm0\n" /* 182.04444885253906f */
        "jmp .Lf6c7ea_0006cdaf\n"
        ".Lf6c7ea_0006cec0:\n"
        "movl -0x20(%ebp), %edx\n" /* line 3749 */
        "movss -0x1c(%ebp), %xmm0\n"
        "movl %esi, %eax\n" /* ps */
        "calll BG_CheckProneTurned\n"
        "testl %eax, %eax\n"
        "movss -0x68(%ebp), %xmm1\n"
        "je .Lf6c7ea_0006ce8d\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 3751 */
        "movss %xmm0, 0x584(%esi)\n" /* ps */
        ".Lf6c7ea_0006cee5:\n"
        "movl imp_bg_prone_yawcap, %edx\n" /* line 3783 */
        "movl (%edx), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lf6c7ea_0006d04b\n"
        "movaps %xmm2, %xmm0\n"
        "xorps CorrectSolidDeltas+416, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf6c7ea_0006cf51\n"
        "addss %xmm2, %xmm1\n" /* line 3789 */
        ".Lf6c7ea_0006cf0e:\n"
        "movaps %xmm1, %xmm0\n" /* line 3791 */
        "mulss lit4_002ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x58(%esi)\n" /* ps */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3793 | 0.0f */
        "jbe .Lf6c7ea_0006d167\n"
        "movl (%edx), %eax\n" /* line 3794 */
        "movss 0x584(%esi), %xmm0\n" /* ps */
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps 0xec(%esi)\n" /* ps */
        ".Lf6c7ea_0006cf51:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 3799 | proneBlocked */
        "testl %edx, %edx\n"
        "jne .Lf6c7ea_0006d07e\n"
        ".Lf6c7ea_0006cf5c:\n"
        "movl 0xe8(%esi), %eax\n" /* line 3823 | ps */
        "movl %eax, 4(%esp)\n"
        "movl 0x58c(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "ucomiss lit4_002ed6ec, %xmm0\n" /* line 3824 | 45.0f */
        "ja .Lf6c7ea_0006d037\n"
        "ucomiss lit4_002ed714, %xmm0\n" /* -45.0f */
        "jp .Lf6c7ea_0006c90e\n"
        "jae .Lf6c7ea_0006c90e\n"
        "movss lit4_002ed6ec, %xmm2\n" /* line 3830 | 45.0f */
        "movaps %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        ".Lf6c7ea_0006cfab:\n"
        "movaps %xmm1, %xmm0\n" /* line 3832 */
        "mulss lit4_002ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x54(%esi)\n" /* ps */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3834 | 0.0f */
        "jbe .Lf6c7ea_0006d14a\n"
        "movss 0x58c(%esi), %xmm0\n" /* line 3835 | ps */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize180Accurate\n"
        "fstps 0xe8(%esi)\n" /* ps */
        "jmp .Lf6c7ea_0006c90e\n"
        ".Lf6c7ea_0006cff0:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 3775 */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x68(%ebp), %xmm1\n"
        "jmp .Lf6c7ea_0006cdf5\n"
        ".Lf6c7ea_0006d015:\n"
        "movss lit4_002ed5dc, %xmm1\n" /* line 3723 | -1.0f */
        "jmp .Lf6c7ea_0006ca6f\n"
        ".Lf6c7ea_0006d022:\n"
        "movss lit4_002ed5dc, %xmm1\n" /* line 3762 | -1.0f */
        "movss lit4_002ed70c, %xmm0\n" /* -182.04444885253906f */
        "jmp .Lf6c7ea_0006cdaf\n"
        ".Lf6c7ea_0006d037:\n"
        "movss lit4_002ed6ec, %xmm2\n" /* line 3828 | 45.0f */
        "movaps %xmm0, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "jmp .Lf6c7ea_0006cfab\n"
        ".Lf6c7ea_0006d04b:\n"
        "subss %xmm2, %xmm1\n" /* line 3787 */
        "jmp .Lf6c7ea_0006cf0e\n"
        ".Lf6c7ea_0006d054:\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 3690 | 0.0f */
        "jbe .Lf6c7ea_0006d253\n"
        "mulss lit4_002ed670, %xmm3\n" /* line 3691 | -0.0010000000474974513f */
        "movaps %xmm3, %xmm0\n"
        "addss 0x584(%esi), %xmm0\n" /* ps */
        "movss %xmm0, -0x38(%ebp)\n" /* newProneYaw */
        "jmp .Lf6c7ea_0006ca42\n"
        ".Lf6c7ea_0006d07e:\n"
        "orl $0x10000, 0xc(%esi)\n" /* line 3801 | ps */
        "movl 0xec(%esi), %eax\n" /* line 3803 | ps */
        "movl %eax, 4(%esp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* oldViewYaw */
        "movss %xmm0, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x28(%ebp)\n" /* deltaYaw1 */
        "movss -0x28(%ebp), %xmm0\n" /* line 3806 | deltaYaw1 */
        "andps CorrectSolidDeltas+432, %xmm0\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "ja .Lf6c7ea_0006cf5c\n"
        "jp .Lf6c7ea_0006cf5c\n"
        "movl 0xec(%esi), %eax\n" /* line 3808 | ps */
        "movl %eax, 4(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* newViewYaw */
        "movss %xmm0, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n" /* line 3810 | deltaYaw1 */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf6c7ea_0006cf5c\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 3812 | deltaYaw1 */
        "mulss lit4_002ed710, %xmm1\n" /* 0.9800000190734863f */
        "movaps %xmm1, %xmm0\n" /* line 3813 */
        "addss 0xec(%esi), %xmm0\n" /* ps */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps 0xec(%esi)\n" /* ps */
        "movss -0x68(%ebp), %xmm1\n" /* line 3814 */
        "mulss lit4_002ed644, %xmm1\n" /* 182.04444885253906f */
        "cvttss2si %xmm1, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x58(%esi)\n" /* ps */
        "jmp .Lf6c7ea_0006cf5c\n"
        ".Lf6c7ea_0006d13e:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 3697 | proneBlocked */
        "jmp .Lf6c7ea_0006cd42\n"
        ".Lf6c7ea_0006d14a:\n"
        "addss 0x58c(%esi), %xmm2\n" /* line 3837 | ps */
        "movss %xmm2, (%esp)\n"
        "calll AngleNormalize180Accurate\n"
        "fstps 0xe8(%esi)\n" /* ps */
        "jmp .Lf6c7ea_0006c90e\n"
        ".Lf6c7ea_0006d167:\n"
        "movl (%edx), %eax\n" /* line 3796 */
        "movss 0x584(%esi), %xmm0\n" /* ps */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps 0xec(%esi)\n" /* ps */
        "jmp .Lf6c7ea_0006cf51\n"
        ".Lf6c7ea_0006d18b:\n"
        "subss %xmm1, %xmm2\n" /* line 3661 */
        "movaps %xmm2, %xmm1\n"
        "jmp .Lf6c7ea_0006cb70\n"
        ".Lf6c7ea_0006d197:\n"
        "movl $0x42340000, 0x34(%esp)\n" /* line 3705 */
        "movl $0, 0x30(%esp)\n"
        "movl %edi, 0x2c(%esp)\n" /* i */
        "movl $0, 0x28(%esp)\n"
        "xorl %eax, %eax\n"
        "cmpl $0x3ff, 0x60(%esi)\n" /* ps */
        "setne %al\n"
        "movl %eax, 0x24(%esp)\n"
        "movl $1, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x38(%ebp), %xmm0\n" /* newProneYaw */
        "movss %xmm0, 0x10(%esp)\n"
        "movl $0x41f00000, 0xc(%esp)\n"
        "movl 0x578(%esi), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xcc(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_CheckProne\n"
        "testl %eax, %eax\n" /* line 3707 */
        "je .Lf6c7ea_0006cd3b\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 3708 | newProneYaw */
        "movss %xmm0, 0x584(%esi)\n" /* ps */
        "jmp .Lf6c7ea_0006cd42\n"
        ".Lf6c7ea_0006d22f:\n"
        "movl imp_bg_ladder_yawcap, %eax\n" /* line 3670 */
        "movl (%eax), %eax\n"
        "addss 8(%eax), %xmm3\n"
        "movss %xmm3, (%esp)\n"
        "calll AngleNormalize360Accurate\n"
        "fstps 0xec(%esi)\n" /* ps */
        ".Lf6c7ea_0006d24b:\n"
        "movl 0xc(%esi), %edx\n" /* ps */
        "jmp .Lf6c7ea_0006c905\n"
        ".Lf6c7ea_0006d253:\n"
        "addss 0x584(%esi), %xmm2\n" /* line 3693 | ps */
        "movss %xmm2, -0x38(%ebp)\n" /* newProneYaw */
        "jmp .Lf6c7ea_0006ca42\n"
    );
}

/* line 3867 */
__attribute__((naked))
void PM_UpdatePronePitch(pmove_t *pm, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3867 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %eax\n" /* pm */
        "movl 0xc(%ebp), %esi\n" /* pml */
        /* { scope 1 */
        "movl (%eax), %ebx\n" /* line 3875 | ps */
        "testb $1, 0xc(%ebx)\n" /* line 3878 | ps */
        "je .Lf6d266_0006d3cc\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 3885 | ps */
        "je .Lf6d266_0006d3d3\n"
        "movl 0x30(%esi), %eax\n" /* line 3899 | pml */
        "testl %eax, %eax\n"
        "je .Lf6d266_0006d46d\n"
        "movss lit4_002ed6ac, %xmm0\n" /* 0.699999988079071f */
        "ucomiss 0x44(%esi), %xmm0\n" /* pml */
        "ja .Lf6d266_0006d4b8\n"
        ".Lf6d266_0006d2aa:\n"
        "leal 0x3c(%esi), %eax\n" /* line 3910 | pml */
        "movl %eax, 4(%esp)\n"
        "movl 0x584(%ebx), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll PitchForYawOnNormal\n"
        ".Lf6d266_0006d2bf:\n"
        "movl 0x588(%ebx), %eax\n" /* line 3915 | ps */
        "movl %eax, 4(%esp)\n"
        "fstps (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 3916 */
        "ucomiss %xmm3, %xmm1\n"
        "jp .Lf6d266_0006d2e4\n"
        "je .Lf6d266_0006d33f\n"
        ".Lf6d266_0006d2e4:\n"
        "movss lit4_002ed6d0, %xmm2\n" /* line 3918 | 70.0f */
        "mulss 0x24(%esi), %xmm2\n" /* pml */
        "movaps %xmm1, %xmm0\n"
        "andps CorrectSolidDeltas+448, %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf6d266_0006d4a3\n"
        "xorl %eax, %eax\n" /* line 3919 */
        "ucomiss %xmm1, %xmm3\n"
        "seta %al\n"
        "addl %eax, %eax\n"
        "negl %eax\n"
        "addl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss 0x588(%ebx), %xmm2\n" /* ps */
        "movss %xmm2, 0x588(%ebx)\n" /* ps */
        ".Lf6d266_0006d32b:\n"
        "movl 0x588(%ebx), %eax\n" /* line 3922 | ps */
        "movl %eax, (%esp)\n"
        "calll AngleNormalize180Accurate\n"
        "fstps 0x588(%ebx)\n" /* ps */
        ".Lf6d266_0006d33f:\n"
        "movl 0x30(%esi), %ecx\n" /* line 3929 | pml */
        "testl %ecx, %ecx\n"
        "jne .Lf6d266_0006d489\n"
        "fldz\n"
        ".Lf6d266_0006d34c:\n"
        "movl 0x58c(%ebx), %eax\n" /* line 3935 | ps */
        "movl %eax, 4(%esp)\n"
        "fstps (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 3936 */
        "ucomiss %xmm3, %xmm1\n"
        "jp .Lf6d266_0006d371\n"
        "je .Lf6d266_0006d3cc\n"
        ".Lf6d266_0006d371:\n"
        "movss lit4_002ed6d0, %xmm2\n" /* line 3938 | 70.0f */
        "mulss 0x24(%esi), %xmm2\n" /* pml */
        "movaps %xmm1, %xmm0\n"
        "andps CorrectSolidDeltas+448, %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf6d266_0006d474\n"
        "xorl %eax, %eax\n" /* line 3939 */
        "ucomiss %xmm1, %xmm3\n"
        "seta %al\n"
        "addl %eax, %eax\n"
        "negl %eax\n"
        "addl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss 0x58c(%ebx), %xmm2\n" /* ps */
        "movss %xmm2, 0x58c(%ebx)\n" /* ps */
        ".Lf6d266_0006d3b8:\n"
        "movl 0x58c(%ebx), %eax\n" /* line 3942 | ps */
        "movl %eax, (%esp)\n"
        "calll AngleNormalize180Accurate\n"
        "fstps 0x58c(%ebx)\n" /* ps */
        /* } scope */
        ".Lf6d266_0006d3cc:\n"
        "addl $0x50, %esp\n" /* line 3944 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf6d266_0006d3d3:\n"
        "movzbl 0xe4(%eax), %eax\n" /* line 3890 */
        "movl 0x30(%esi), %edx\n" /* pml */
        "testl %edx, %edx\n"
        "jne .Lf6d266_0006d4d2\n"
        "xorl %edx, %edx\n"
        ".Lf6d266_0006d3e7:\n"
        "movl $0x42840000, 0x34(%esp)\n"
        "movl $0, 0x30(%esp)\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl %edx, 0x28(%esp)\n"
        "movl $0, 0x24(%esp)\n"
        "movl $1, 0x20(%esp)\n"
        "leal 0x5b0(%ebx), %eax\n" /* ps */
        "movl %eax, 0x1c(%esp)\n"
        "leal 0x5ac(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal 0x5a8(%ebx), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x584(%ebx), %eax\n" /* ps */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41f00000, 0xc(%esp)\n"
        "movl 0x578(%ebx), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "leal 0x14(%ebx), %eax\n" /* ps */
        "movl %eax, 4(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_CheckProne\n"
        "testl %eax, %eax\n" /* line 3892 */
        "je .Lf6d266_0006d4da\n"
        /* } scope */
        ".Lf6d266_0006d462:\n"
        "movl 0x30(%esi), %eax\n" /* line 3909 | pml */
        "testl %eax, %eax\n"
        "jne .Lf6d266_0006d2aa\n"
        ".Lf6d266_0006d46d:\n"
        "fldz\n" /* line 3910 */
        "jmp .Lf6d266_0006d2bf\n"
        ".Lf6d266_0006d474:\n"
        "addss 0x58c(%ebx), %xmm1\n" /* line 3941 | ps */
        "movss %xmm1, 0x58c(%ebx)\n" /* ps */
        "jmp .Lf6d266_0006d3b8\n"
        ".Lf6d266_0006d489:\n"
        "leal 0x3c(%esi), %eax\n" /* line 3930 | pml */
        "movl %eax, 4(%esp)\n"
        "movl 0xec(%ebx), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll PitchForYawOnNormal\n"
        "jmp .Lf6d266_0006d34c\n"
        ".Lf6d266_0006d4a3:\n"
        "addss 0x588(%ebx), %xmm1\n" /* line 3921 | ps */
        "movss %xmm1, 0x588(%ebx)\n" /* ps */
        "jmp .Lf6d266_0006d32b\n"
        ".Lf6d266_0006d4b8:\n"
        "movl %ebx, 8(%esp)\n" /* line 3902 | ps */
        "movl $0, 4(%esp)\n"
        "movl $0x8d, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf6d266_0006d462\n"
        /* { scope 2 */
        ".Lf6d266_0006d4d2:\n"
        "leal 0x3c(%esi), %edx\n" /* line 3890 | pml */
        "jmp .Lf6d266_0006d3e7\n"
        ".Lf6d266_0006d4da:\n"
        "movl %ebx, 8(%esp)\n" /* line 3895 | ps */
        "movl $0, 4(%esp)\n"
        "movl $0x8d, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "orl $0x10000, 0xc(%ebx)\n" /* line 3896 | ps */
        "jmp .Lf6d266_0006d462\n"
    );
}

/* line 260 */
__attribute__((naked))
void PM_playerTrace(pmove_t *pm, trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentMask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 260 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pm */
        "movl 0xc(%ebp), %edi\n" /* results */
        "movl 0x10(%ebp), %eax\n" /* start */
        "movl %eax, -0x20(%ebp)\n" /* start */
        "movl 0x14(%ebp), %edx\n" /* mins */
        "movl %edx, -0x24(%ebp)\n" /* mins */
        "movl 0x18(%ebp), %eax\n" /* maxs */
        "movl %eax, -0x28(%ebp)\n" /* maxs */
        "movl 0x1c(%ebp), %edx\n" /* end */
        "movl %edx, -0x2c(%ebp)\n" /* end */
        "movl 0x20(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, -0x30(%ebp)\n" /* passEntityNum */
        "movl 0x24(%ebp), %edx\n" /* contentMask */
        "movl %edx, -0x34(%ebp)\n" /* contentMask */
        "movzbl 0xe4(%esi), %eax\n" /* line 262 | pm */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0x30(%ebp), %edx\n" /* passEntityNum */
        "movl %edx, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %edx\n" /* end */
        "movl %edx, 0x10(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* maxs */
        "movl %edx, 0xc(%esp)\n"
        "movl -0x24(%ebp), %edx\n" /* mins */
        "movl %edx, 8(%esp)\n"
        "movl -0x20(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* results */
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, 0x23(%edi)\n" /* line 264 | results */
        "je .Lf6d4fe_0006d609\n"
        "testb $2, 0x17(%edi)\n" /* line 268 | results */
        "je .Lf6d4fe_0006d609\n"
        "movzwl 0x1c(%edi), %eax\n" /* line 271 | results */
        "movzwl %ax, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* entityNum */
        /* { scope 1 */
        /* { scope 2 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf6d4fe_0006d5ba\n"
        "movl 0x40(%esi), %ebx\n" /* line 303 | pm */
        "cmpl $0x20, %ebx\n"
        "je .Lf6d4fe_0006d5ba\n"
        "testl %ebx, %ebx\n" /* line 309 */
        "jle .Lf6d4fe_0006d611\n"
        "movl -0x1c(%ebp), %eax\n" /* line 311 | entityNum */
        "cmpl 0x44(%esi), %eax\n" /* pm */
        "je .Lf6d4fe_0006d5ba\n"
        "movl %esi, %ecx\n" /* pm */
        "xorl %edx, %edx\n"
        ".Lf6d4fe_0006d5a8:\n"
        "addl $1, %edx\n" /* line 309 */
        "cmpl %edx, %ebx\n"
        "je .Lf6d4fe_0006d611\n"
        "movl 0x48(%ecx), %eax\n" /* line 311 */
        "addl $4, %ecx\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* entityNum */
        "jne .Lf6d4fe_0006d5a8\n"
        /* } scope */
        /* } scope */
        ".Lf6d4fe_0006d5ba:\n"
        "andl $0xfdffffff, 0x3c(%esi)\n" /* line 272 | pm */
        "movzbl 0xe4(%esi), %eax\n" /* line 273 | pm */
        "leal (%eax, %eax, 2), %eax\n"
        "andl $0xfdffffff, -0x34(%ebp)\n" /* contentMask */
        "movl -0x34(%ebp), %edx\n" /* contentMask */
        "movl %edx, 0x20(%ebp)\n" /* passEntityNum */
        "movl -0x30(%ebp), %edx\n" /* passEntityNum */
        "movl %edx, 0x1c(%ebp)\n" /* end */
        "movl -0x2c(%ebp), %edx\n" /* end */
        "movl %edx, 0x18(%ebp)\n" /* maxs */
        "movl -0x28(%ebp), %edx\n" /* maxs */
        "movl %edx, 0x14(%ebp)\n" /* mins */
        "movl -0x24(%ebp), %edx\n" /* mins */
        "movl %edx, 0x10(%ebp)\n" /* start */
        "movl -0x20(%ebp), %edx\n" /* start */
        "movl %edx, 0xc(%ebp)\n" /* results */
        "movl %edi, 8(%ebp)\n" /* results, pm */
        "movl pmoveHandlers(, %eax, 4), %ecx\n"
        "addl $0x4c, %esp\n" /* line 274 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 273 */
        ".Lf6d4fe_0006d609:\n"
        "addl $0x4c, %esp\n" /* line 274 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf6d4fe_0006d611:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 318 | entityNum */
        "movl %eax, 0x44(%esi, %ebx, 4)\n" /* pm */
        "addl $1, %ebx\n" /* line 319 */
        "movl %ebx, 0x40(%esi)\n" /* pm */
        "jmp .Lf6d4fe_0006d5ba\n"
    );
}

/* line 734 */
static __attribute__((naked))
void PM_SetMovementDir(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 734 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* pm */
        "movl %edx, %ecx\n" /* pml */
        /* { scope 1: dir */
        "movl (%eax), %esi\n" /* line 743 | ps */
        "movl 0xc(%esi), %eax\n" /* line 747 | ps */
        "testb $1, %al\n"
        "je .Lf6d620_0006d646\n"
        "testl $0x300, 0xa0(%esi)\n" /* ps */
        "je .Lf6d620_0006d7a1\n"
        ".Lf6d620_0006d646:\n"
        "testb $0x20, %al\n" /* line 764 */
        "jne .Lf6d620_0006d73b\n"
        "leal 0x14(%esi), %eax\n" /* line 778 | ps */
        "leal 0x60(%ecx), %edx\n" /* pml */
        /* { scope 2 */
        "movss 0x14(%esi), %xmm2\n" /* line 248 */
        "subss 0x60(%ecx), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* moved */
        "movss 4(%eax), %xmm1\n" /* line 249 */
        "subss 4(%edx), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "cmpw $0, 0x1c(%edi)\n" /* line 783 | pm */
        "jne .Lf6d620_0006d69a\n"
        ".Lf6d620_0006d688:\n"
        "movl $0, 0x9c(%esi)\n" /* line 811 | ps */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dir */
        ".Lf6d620_0006d69a:\n"
        "cmpl $0x3ff, 0x60(%esi)\n" /* line 783 | ps */
        "je .Lf6d620_0006d688\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "sqrtss %xmm2, %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 783 | 0.0f */
        "jp .Lf6d620_0006d6c6\n"
        "je .Lf6d620_0006d688\n"
        ".Lf6d620_0006d6c6:\n"
        "movss lit4_002ed6d4, %xmm0\n" /* 5.0f */
        "mulss 0x24(%ecx), %xmm0\n" /* pml */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf6d620_0006d688\n"
        /* { scope 2 */
        "leal -0x30(%ebp), %ebx\n" /* line 787 | dir */
        "movl %ebx, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* moved */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl %ebx, 4(%esp)\n" /* line 788 */
        "movl %ebx, (%esp)\n"
        "calll vectoangles\n"
        "movl 0xec(%esi), %eax\n" /* line 790 | ps */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x40(%ebp)\n"
        "cvttss2si -0x40(%ebp), %eax\n"
        "cmpb $0, 0x1c(%edi)\n" /* line 792 | pm */
        "jns .Lf6d620_0006d772\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 793 */
        "addss lit4_002ed64c, %xmm0\n" /* 180.0f */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x3c(%ebp)\n"
        "cvttss2si -0x3c(%ebp), %eax\n"
        "jmp .Lf6d620_0006d772\n"
        /* } scope */
        ".Lf6d620_0006d73b:\n"
        "leal 0x64(%esi), %eax\n" /* line 766 | ps */
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movl 0xec(%esi), %eax\n" /* line 767 | ps */
        "movl %eax, 4(%esp)\n"
        "addss lit4_002ed64c, %xmm0\n" /* 180.0f */
        "movss %xmm0, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x44(%ebp)\n"
        "cvttss2si -0x44(%ebp), %eax\n"
        ".Lf6d620_0006d772:\n"
        "movl %eax, %edx\n" /* line 751 */
        "testl %eax, %eax\n"
        "js .Lf6d620_0006d7c3\n"
        /* { scope 2 */
        ".Lf6d620_0006d778:\n"
        "cmpl $0x5a, %edx\n" /* line 795 */
        "jg .Lf6d620_0006d790\n"
        "movl %eax, %edx\n"
        ".Lf6d620_0006d77f:\n"
        "movsbl %dl, %eax\n" /* line 807 */
        "movl %eax, 0x9c(%esi)\n" /* ps */
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dir */
        /* { scope 2 */
        ".Lf6d620_0006d790:\n"
        "movl $0x5a, %edx\n" /* line 797 */
        "testl %eax, %eax\n"
        "movl $0xffffffa6, %eax\n"
        "cmovlel %eax, %edx\n"
        "jmp .Lf6d620_0006d77f\n"
        /* } scope */
        ".Lf6d620_0006d7a1:\n"
        "movl 0xec(%esi), %eax\n" /* line 749 | ps */
        "movl %eax, 4(%esp)\n"
        "movl 0x584(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x48(%ebp)\n"
        "cvttss2si -0x48(%ebp), %eax\n"
        "jmp .Lf6d620_0006d772\n"
        /* { scope 2 */
        ".Lf6d620_0006d7c3:\n"
        "negl %edx\n" /* line 795 */
        "jmp .Lf6d620_0006d778\n"
    );
}

/* line 902 */
static __attribute__((naked))
void PM_AirMove(pmove_t *pm)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 902 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl %edx, %esi\n" /* pml */
        /* { scope 1 */
        "movl (%eax), %edi\n" /* line 915 | ps */
        "movl %edi, %eax\n" /* line 918 | ps */
        "calll PM_Friction\n"
        "movl -0x48(%ebp), %eax\n" /* line 920 */
        "movsbl 0x1c(%eax), %ecx\n"
        "movsbl %cl, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n" /* fmove */
        "movl -0x48(%ebp), %eax\n" /* line 921 */
        "movsbl 0x1d(%eax), %ebx\n"
        "movsbl %bl, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* smove */
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 81 */
        "imull %ecx, %eax\n"
        "movl %ebx, %edx\n"
        "imull %ebx, %edx\n"
        "addl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "movl %ecx, %eax\n" /* line 587 */
        "negl %eax\n"
        "cmpl $-1, %ecx\n"
        "cmovlel %eax, %ecx\n"
        "movl %ebx, %edx\n" /* line 588 */
        "movl %ebx, %eax\n"
        "negl %eax\n"
        "cmpl $-1, %ebx\n"
        "cmovlel %eax, %edx\n"
        "cmpl %edx, %ecx\n"
        "cmovgel %ecx, %edx\n"
        "pxor %xmm2, %xmm2\n" /* line 591 */
        "testl %edx, %edx\n"
        "je .Lf6d7c8_0006d88d\n"
        "cvtsi2ssl 0x50(%edi), %xmm2\n" /* line 594 */
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "mulss lit4_002ed718, %xmm1\n" /* 127.0f */
        "divss %xmm1, %xmm2\n"
        "testb $1, 0xd(%edi)\n" /* line 596 */
        "je .Lf6d7c8_0006d9e1\n"
        ".Lf6d7c8_0006d85f:\n"
        "mulss lit4_002ed71c, %xmm2\n" /* line 597 | 0.4000000059604645f */
        "movl 4(%edi), %eax\n" /* line 601 */
        "cmpl $2, %eax\n"
        "je .Lf6d7c8_0006da01\n"
        ".Lf6d7c8_0006d873:\n"
        "cmpl $3, %eax\n" /* line 603 */
        "je .Lf6d7c8_0006da0e\n"
        "cmpl $4, %eax\n" /* line 606 */
        "jne .Lf6d7c8_0006d88d\n"
        "movl imp_player_spectateSpeedScale, %eax\n" /* line 607 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm2\n"
        /* } scope */
        ".Lf6d7c8_0006d88d:\n"
        "movl $0, 8(%esi)\n" /* line 927 | pml */
        "movl $0, 0x14(%esi)\n" /* line 928 | pml */
        "movl %esi, (%esp)\n" /* line 929 | pml */
        "movss %xmm2, -0x58(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal 0xc(%esi), %eax\n" /* line 930 | pml */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl %esi, %eax\n" /* pml */
        "movl $1, %edx\n"
        "leal -0x24(%ebp), %ecx\n" /* wishvel */
        "movss -0x58(%ebp), %xmm2\n"
        ".Lf6d7c8_0006d8c6:\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 933 | fmove */
        "mulss (%eax), %xmm0\n"
        "movss -0x40(%ebp), %xmm1\n" /* smove */
        "mulss 0xc(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%ecx, %edx, 4)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $3, %edx\n" /* line 932 */
        "jne .Lf6d7c8_0006d8c6\n"
        "xorl %edx, %edx\n" /* line 934 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | wishvel */
        "movl %eax, -0x30(%ebp)\n" /* wishdir */
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, -0x28(%ebp)\n" /* line 201 */
        "leal -0x30(%ebp), %ebx\n" /* line 937 | wishdir */
        "movl %ebx, (%esp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x3c(%ebp)\n" /* wishspeed */
        "movss lit4_002ed5d0, %xmm1\n" /* line 941 | 1.0f */
        "movss -0x58(%ebp), %xmm2\n"
        "movss -0x3c(%ebp), %xmm0\n" /* wishspeed */
        "mulss %xmm2, %xmm0\n"
        "movl %ebx, %ecx\n"
        "movl %esi, %edx\n" /* pml */
        "movl %edi, %eax\n" /* ps */
        "calll PM_Accelerate\n"
        "movl 0x30(%esi), %ecx\n" /* line 946 | pml */
        "testl %ecx, %ecx\n"
        "je .Lf6d7c8_0006d9b8\n"
        "leal 0x20(%edi), %eax\n" /* line 947 | ps */
        "movss 0x20(%edi), %xmm4\n" /* line 304 */
        "movss 0x3c(%esi), %xmm3\n"
        "movaps %xmm4, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "movss 0x24(%edi), %xmm0\n"
        "mulss 0x40(%esi), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss 0x28(%edi), %xmm0\n"
        "mulss 0x44(%esi), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm1\n" /* line 336 | scale */
        "andps CorrectSolidDeltas+464, %xmm1\n" /* scale */
        "mulss lit4_002ed670, %xmm1\n" /* -0.0010000000474974513f, scale */
        "addss %xmm2, %xmm1\n" /* scale */
        "xorps CorrectSolidDeltas+480, %xmm1\n" /* scale */
        /* { scope 2 */
        "mulss %xmm1, %xmm3\n" /* line 288 */
        "addss %xmm3, %xmm4\n"
        "movss %xmm4, 0x20(%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x40(%esi), %xmm0\n"
        "addss 0x24(%edi), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 0x44(%esi), %xmm1\n" /* line 290 */
        "addss 0x28(%edi), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        ".Lf6d7c8_0006d9b8:\n"
        "movl $1, 8(%esp)\n" /* line 949 */
        "movl %esi, 4(%esp)\n" /* pml */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll PM_StepSlideMove\n"
        "movl %esi, %edx\n" /* line 952 | pml */
        "movl -0x48(%ebp), %eax\n"
        "calll PM_SetMovementDir\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 953 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf6d7c8_0006d9e1:\n"
        "pxor %xmm0, %xmm0\n" /* line 596 */
        "ucomiss 0x4c(%edi), %xmm0\n"
        "jp .Lf6d7c8_0006d85f\n"
        "jne .Lf6d7c8_0006d85f\n"
        "movl 4(%edi), %eax\n" /* line 601 */
        "cmpl $2, %eax\n"
        "jne .Lf6d7c8_0006d873\n"
        ".Lf6d7c8_0006da01:\n"
        "mulss lit4_002ed720, %xmm2\n" /* line 602 | 3.0f */
        "jmp .Lf6d7c8_0006d88d\n"
        ".Lf6d7c8_0006da0e:\n"
        "mulss lit4_002ed5e0, %xmm2\n" /* line 604 | 6.0f */
        "jmp .Lf6d7c8_0006d88d\n"
    );
}

/* line 4158 */
static __attribute__((naked))
void PM_LadderMove(pmove_t *pm)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4158 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl %edx, %edi\n" /* pml */
        /* { scope 1 */
        "movl (%eax), %esi\n" /* line 4174 | ps */
        "movl %edx, 4(%esp)\n" /* line 4178 */
        "movl %eax, (%esp)\n"
        "calll Jump_Check\n"
        "testb %al, %al\n"
        "jne .Lf6da1c_0006de2d\n"
        "movss lit4_002ed604, %xmm3\n" /* line 4189 | 0.25f */
        "addss 8(%edi), %xmm3\n" /* pml */
        "mulss lit4_002ed6c0, %xmm3\n" /* 2.5f */
        "movss lit4_002ed5d0, %xmm0\n" /* line 4190 | 1.0f */
        "ucomiss %xmm0, %xmm3\n"
        "jbe .Lf6da1c_0006dea9\n"
        ".Lf6da1c_0006da66:\n"
        "movl $0, 8(%edi)\n" /* line 4199 | pml */
        "movl %edi, (%esp)\n" /* line 4200 | pml */
        "movss %xmm0, -0x68(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl $0, 0x14(%edi)\n" /* line 4204 | pml */
        "leal 0xc(%edi), %eax\n" /* line 4205 | pml */
        "movl %eax, -0x54(%ebp)\n"
        "leal -0x44(%ebp), %ebx\n" /* vTempRight */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "leal 0x64(%esi), %edx\n" /* line 4206 | ps */
        "movl %edx, -0x50(%ebp)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ProjectPointOnPlane\n"
        "movl -0x58(%ebp), %eax\n" /* line 4214 | cmd */
        "addl $4, %eax\n" /* cmd */
        /* { scope 2 */
        /* { scope 3 */
        "movsbl 0x18(%eax), %ebx\n" /* line 586 */
        "movsbl 0x19(%eax), %edx\n"
        "movl %ebx, %eax\n" /* line 81 */
        "imull %ebx, %eax\n"
        "movl %edx, %ecx\n"
        "imull %edx, %ecx\n"
        "addl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "sqrtss %xmm0, %xmm2\n"
        "movl %ebx, %ecx\n" /* line 587 */
        "movl %ebx, %eax\n"
        "negl %eax\n"
        "cmpl $-1, %ebx\n"
        "cmovlel %eax, %ecx\n"
        "movl %edx, %eax\n" /* line 588 */
        "negl %eax\n"
        "cmpl $-1, %edx\n"
        "cmovlel %eax, %edx\n"
        "cmpl %edx, %ecx\n"
        "cmovll %edx, %ecx\n"
        "testl %ecx, %ecx\n" /* line 591 */
        "movss -0x68(%ebp), %xmm3\n"
        "jne .Lf6da1c_0006dce6\n"
        "pxor %xmm1, %xmm1\n"
        /* } scope */
        /* } scope */
        ".Lf6da1c_0006db01:\n"
        "movl $0, -0x38(%ebp)\n" /* line 183 | wishvel */
        "movl $0, -0x34(%ebp)\n" /* line 184 */
        "movl $0, -0x30(%ebp)\n" /* line 185 */
        "movl -0x58(%ebp), %edx\n" /* line 4217 */
        "movzbl 0x1c(%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf6da1c_0006db40\n"
        "mulss lit4_002ed5d8, %xmm3\n" /* line 4218 | 0.5f */
        "mulss %xmm1, %xmm3\n"
        "movsbl %al, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl -0x58(%ebp), %edx\n"
        ".Lf6da1c_0006db40:\n"
        "movzbl 0x1d(%edx), %eax\n" /* line 4223 */
        "testb %al, %al\n"
        "je .Lf6da1c_0006db90\n"
        "mulss lit4_002ed724, %xmm1\n" /* line 4224 | 0.20000000298023224f, scale */
        "movsbl %al, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "movl -0x54(%ebp), %eax\n"
        "mulss (%eax), %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n" /* wishvel */
        "movss %xmm0, -0x38(%ebp)\n" /* wishvel */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        /* } scope */
        ".Lf6da1c_0006db90:\n"
        "leal -0x2c(%ebp), %ebx\n" /* line 4230 | wishdir */
        "movl %ebx, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* wishvel */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "movss lit4_002ed728, %xmm1\n" /* line 4232 | 9.0f */
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "movl %ebx, %ecx\n"
        "movl %edi, %edx\n" /* pml */
        "movl %esi, %eax\n" /* ps */
        "calll PM_Accelerate\n"
        "movl -0x58(%ebp), %edx\n" /* line 4234 */
        "cmpb $0, 0x1c(%edx)\n"
        "jne .Lf6da1c_0006dd40\n"
        "movss 0x28(%esi), %xmm1\n" /* line 4236 | ps */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf6da1c_0006dec7\n"
        "cvtsi2ssl 0x48(%esi), %xmm0\n" /* line 4238 | ps */
        "mulss 0x24(%edi), %xmm0\n" /* pml */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm1, 0x28(%esi)\n" /* ps */
        "pxor %xmm1, %xmm1\n" /* line 4239 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf6da1c_0006de93\n"
        ".Lf6da1c_0006dbff:\n"
        "movl -0x58(%ebp), %eax\n"
        ".Lf6da1c_0006dc02:\n"
        "cmpb $0, 0x1d(%eax)\n" /* line 4250 */
        "je .Lf6da1c_0006dd4c\n"
        ".Lf6da1c_0006dc0c:\n"
        "movl 0x2c(%edi), %ebx\n" /* line 4275 | pml */
        "testl %ebx, %ebx\n"
        "jne .Lf6da1c_0006dc72\n"
        "movl -0x50(%ebp), %eax\n" /* line 4278 */
        "movss (%eax), %xmm0\n" /* scale */
        "mulss 0x20(%esi), %xmm0\n" /* ps, scale */
        "movss 4(%eax), %xmm1\n"
        "mulss 0x24(%esi), %xmm1\n" /* ps */
        "addss %xmm1, %xmm0\n" /* scale */
        "xorps CorrectSolidDeltas+496, %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 100 */
        "mulss (%eax), %xmm1\n"
        "addss 0x20(%esi), %xmm1\n"
        "movss %xmm1, 0x20(%esi)\n"
        "mulss 4(%eax), %xmm0\n" /* line 101 */
        "addss 0x24(%esi), %xmm0\n"
        "movss %xmm0, 0x24(%esi)\n"
        /* } scope */
        "movss 0x28(%esi), %xmm2\n" /* line 4281 | ps */
        "mulss %xmm1, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "ucomiss %xmm1, %xmm2\n"
        "jae .Lf6da1c_0006de3f\n"
        ".Lf6da1c_0006dc72:\n"
        "movl $0, 8(%esp)\n" /* line 4291 */
        "movl %edi, 4(%esp)\n" /* pml */
        "movl -0x58(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll PM_StepSlideMove\n"
        "movl -0x50(%ebp), %eax\n" /* line 4294 */
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "movl 0xec(%esi), %eax\n" /* line 4295 | ps */
        "movl %eax, 4(%esp)\n"
        "addss lit4_002ed64c, %xmm0\n" /* 180.0f */
        "movss %xmm0, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x4c(%ebp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "movl %eax, %edx\n" /* line 4297 */
        "testl %eax, %eax\n"
        "js .Lf6da1c_0006dea2\n"
        ".Lf6da1c_0006dcca:\n"
        "cmpl $0x4b, %edx\n"
        "jg .Lf6da1c_0006de19\n"
        "movl %eax, %edx\n"
        ".Lf6da1c_0006dcd5:\n"
        "movsbl %dl, %eax\n" /* line 4305 */
        "movl %eax, 0x9c(%esi)\n" /* ps */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 4306 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf6da1c_0006dce6:\n"
        "cvtsi2ssl 0x50(%esi), %xmm1\n" /* line 594 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "mulss lit4_002ed718, %xmm2\n" /* 127.0f */
        "divss %xmm2, %xmm1\n"
        "testb $1, 0xd(%esi)\n" /* line 596 */
        "je .Lf6da1c_0006de6d\n"
        ".Lf6da1c_0006dd09:\n"
        "mulss lit4_002ed71c, %xmm1\n" /* line 597 | 0.4000000059604645f */
        ".Lf6da1c_0006dd11:\n"
        "movl 4(%esi), %eax\n" /* line 601 */
        "cmpl $2, %eax\n"
        "je .Lf6da1c_0006deba\n"
        "cmpl $3, %eax\n" /* line 603 */
        "je .Lf6da1c_0006de86\n"
        "cmpl $4, %eax\n" /* line 606 */
        "jne .Lf6da1c_0006db01\n"
        "movl imp_player_spectateSpeedScale, %eax\n" /* line 607 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm1\n"
        "jmp .Lf6da1c_0006db01\n"
        ".Lf6da1c_0006dd40:\n"
        "movl %edx, %eax\n"
        /* } scope */
        /* } scope */
        "cmpb $0, 0x1d(%eax)\n" /* line 4250 */
        "jne .Lf6da1c_0006dc0c\n"
        ".Lf6da1c_0006dd4c:\n"
        "movl -0x54(%ebp), %edx\n" /* line 37 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* vSideDir */
        "movl 4(%edx), %eax\n" /* line 38 */
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 4253 | vSideDir */
        "movl %eax, (%esp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 114 | vSideDir */
        "movaps %xmm2, %xmm1\n"
        "mulss 0x20(%esi), %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss 0x24(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "pxor %xmm4, %xmm4\n" /* line 4257 */
        "ucomiss %xmm4, %xmm1\n"
        "jp .Lf6da1c_0006dd91\n"
        "je .Lf6da1c_0006dc0c\n"
        ".Lf6da1c_0006dd91:\n"
        "movaps %xmm1, %xmm0\n" /* line 4259 | scale */
        "xorps CorrectSolidDeltas+496, %xmm0\n" /* scale */
        /* { scope 2 */
        "mulss %xmm0, %xmm2\n" /* line 100 */
        "addss 0x20(%esi), %xmm2\n"
        "movss %xmm2, 0x20(%esi)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 101 */
        "addss 0x24(%esi), %xmm0\n"
        "movss %xmm0, 0x24(%esi)\n"
        /* } scope */
        "movaps %xmm1, %xmm2\n" /* line 4261 */
        "mulss 0x24(%edi), %xmm2\n" /* pml */
        "mulss lit4_002ed6a8, %xmm2\n" /* 16.0f */
        "movss CorrectSolidDeltas+512, %xmm0\n" /* line 54 */
        "movaps %xmm2, %xmm3\n"
        "andps %xmm0, %xmm3\n"
        "andps %xmm1, %xmm0\n" /* line 4262 */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf6da1c_0006dc0c\n"
        "ucomiss lit4_002ed5d0, %xmm3\n" /* line 4264 | 1.0f */
        "jb .Lf6da1c_0006def4\n"
        ".Lf6da1c_0006ddef:\n"
        "subss %xmm2, %xmm1\n" /* line 4267 */
        "movaps %xmm1, %xmm0\n" /* line 100 */
        "mulss -0x20(%ebp), %xmm0\n" /* vSideDir */
        "addss 0x20(%esi), %xmm0\n"
        "movss %xmm0, 0x20(%esi)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 101 */
        "addss 0x24(%esi), %xmm1\n"
        "movss %xmm1, 0x24(%esi)\n"
        "jmp .Lf6da1c_0006dc0c\n"
        ".Lf6da1c_0006de19:\n"
        "movl $0x4b, %edx\n" /* line 4299 */
        "testl %eax, %eax\n"
        "movl $0xffffffb5, %eax\n"
        "cmovlel %eax, %edx\n"
        "jmp .Lf6da1c_0006dcd5\n"
        ".Lf6da1c_0006de2d:\n"
        "movl %edi, %edx\n" /* line 4180 | pml */
        "movl -0x58(%ebp), %eax\n"
        "calll PM_AirMove\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 4306 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6da1c_0006de3f:\n"
        "movss lit4_002ed6cc, %xmm1\n" /* line 100 | -50.0f */
        "movss (%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x20(%esi), %xmm0\n"
        "movss %xmm0, 0x20(%esi)\n"
        "mulss 4(%eax), %xmm1\n" /* line 101 */
        "addss 0x24(%esi), %xmm1\n"
        "movss %xmm1, 0x24(%esi)\n"
        "jmp .Lf6da1c_0006dc72\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf6da1c_0006de6d:\n"
        "pxor %xmm0, %xmm0\n" /* line 596 */
        "ucomiss 0x4c(%esi), %xmm0\n"
        "jp .Lf6da1c_0006dd09\n"
        "je .Lf6da1c_0006dd11\n"
        "jmp .Lf6da1c_0006dd09\n"
        ".Lf6da1c_0006de86:\n"
        "mulss lit4_002ed5e0, %xmm1\n" /* line 604 | 6.0f */
        "jmp .Lf6da1c_0006db01\n"
        /* } scope */
        /* } scope */
        ".Lf6da1c_0006de93:\n"
        "movl $0, 0x28(%esi)\n" /* line 4240 | ps */
        "movl -0x58(%ebp), %eax\n"
        "jmp .Lf6da1c_0006dc02\n"
        ".Lf6da1c_0006dea2:\n"
        "negl %edx\n" /* line 4297 */
        "jmp .Lf6da1c_0006dcca\n"
        ".Lf6da1c_0006dea9:\n"
        "movss lit4_002ed5dc, %xmm0\n" /* line 4192 | -1.0f */
        "maxss %xmm3, %xmm0\n"
        "jmp .Lf6da1c_0006da66\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf6da1c_0006deba:\n"
        "mulss lit4_002ed720, %xmm1\n" /* line 602 | 3.0f */
        "jmp .Lf6da1c_0006db01\n"
        /* } scope */
        /* } scope */
        ".Lf6da1c_0006dec7:\n"
        "cvtsi2ssl 0x48(%esi), %xmm0\n" /* line 4244 | ps */
        "mulss 0x24(%edi), %xmm0\n" /* pml */
        "addss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 4246 */
        "movaps %xmm0, %xmm2\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movss %xmm0, 0x28(%esi)\n" /* ps */
        "jmp .Lf6da1c_0006dbff\n"
        ".Lf6da1c_0006def4:\n"
        "jp .Lf6da1c_0006ddef\n" /* line 4264 */
        "xorl %eax, %eax\n" /* line 4265 */
        "ucomiss %xmm2, %xmm4\n"
        "seta %al\n"
        "addl %eax, %eax\n"
        "negl %eax\n"
        "addl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "jmp .Lf6da1c_0006ddef\n"
    );
}

/* line 1942 */
static __attribute__((naked))
void PM_ViewHeightAdjust(pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1942 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl %eax, %edi\n" /* pm */
        "movl %edx, -0x50(%ebp)\n"
        /* { scope 1: iLerpFrac */
        "movl (%eax), %ebx\n" /* line 1948 | ps */
        "movl 0xf4(%ebx), %eax\n" /* line 1952 | ps */
        "testl %eax, %eax\n"
        "je .Lf6df12_0006dfb4\n"
        "movss 0xf8(%ebx), %xmm1\n" /* ps */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "je .Lf6df12_0006dfb2\n"
        ".Lf6df12_0006df44:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1961 */
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf6df12_0006df59\n"
        "jp .Lf6df12_0006df59\n"
        "movl 0xfc(%ebx), %edx\n" /* ps */
        "testl %edx, %edx\n"
        "je .Lf6df12_0006dfc6\n"
        /* { scope 2: bDown, vFlatForward, pCurr, pCurr */
        ".Lf6df12_0006df59:\n"
        "cmpl $0xb, %eax\n" /* line 1967 */
        "je .Lf6df12_0006dfe6\n"
        "cmpl $0x28, %eax\n"
        "je .Lf6df12_0006dfe6\n"
        "cmpl $0x3c, %eax\n"
        "je .Lf6df12_0006dfe6\n"
        "movl $0, 0xfc(%ebx)\n" /* line 1969 | ps */
        "cvtsi2ssl 0xf4(%ebx), %xmm2\n" /* line 1971 | ps */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf6df12_0006e31b\n"
        "movss lit4_002ed64c, %xmm0\n" /* line 1973 | 180.0f */
        "movl -0x50(%ebp), %eax\n"
        "mulss 0x24(%eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xf8(%ebx)\n" /* ps */
        "ucomiss %xmm2, %xmm0\n" /* line 1974 */
        "jb .Lf6df12_0006dfc6\n"
        ".Lf6df12_0006dfa8:\n"
        "movss %xmm2, 0xf8(%ebx)\n" /* line 1981 | ps */
        "jmp .Lf6df12_0006dfc6\n"
        /* } scope */
        ".Lf6df12_0006dfb2:\n"
        "jp .Lf6df12_0006df44\n" /* line 1952 */
        ".Lf6df12_0006dfb4:\n"
        "cmpl $4, 4(%ebx)\n" /* line 1955 | ps */
        "je .Lf6df12_0006dfd1\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1959 */
        "movss %xmm0, 0xf8(%ebx)\n" /* ps */
        /* } scope */
        ".Lf6df12_0006dfc6:\n"
        "addl $0x8c, %esp\n" /* line 2164 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iLerpFrac */
        ".Lf6df12_0006dfd1:\n"
        "movl $0, 0xf8(%ebx)\n" /* line 1956 | ps */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 2164 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iLerpFrac */
        /* { scope 2: bDown, vFlatForward, pCurr, pCurr */
        ".Lf6df12_0006dfe6:\n"
        "movl 0xfc(%ebx), %ecx\n" /* line 1986 | ps */
        "testl %ecx, %ecx\n"
        "je .Lf6df12_0006e2b2\n"
        "movl 0x104(%ebx), %esi\n" /* line 1989 | ps, iTarget */
        "movl %esi, -0x48(%ebp)\n" /* iTarget, bDown */
        "movl 0x100(%ebx), %esi\n" /* ps, iTarget */
        /* { scope 3 */
        "cmpl $0xb, %esi\n" /* line 1806 */
        "je .Lf6df12_0006e37c\n"
        "cmpl $0x28, %esi\n" /* line 1810 */
        "je .Lf6df12_0006e371\n"
        ".Lf6df12_0006e015:\n"
        "movl $0xc8, %edx\n" /* line 1812 */
        /* } scope */
        ".Lf6df12_0006e01a:\n"
        "movl 4(%edi), %eax\n" /* line 1992 | pm */
        "subl %ecx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "movl %eax, -0x2c(%ebp)\n"
        "testl %eax, %eax\n" /* line 1993 */
        "js .Lf6df12_0006e3b2\n"
        "cmpl $0x64, %eax\n" /* line 1995 */
        "jg .Lf6df12_0006e386\n"
        "je .Lf6df12_0006e386\n" /* line 1998 */
        ".Lf6df12_0006e04a:\n"
        "cmpl $0xb, %esi\n" /* line 2006 | iTarget */
        "je .Lf6df12_0006e400\n"
        "cmpl $0x28, %esi\n" /* line 2011 | iTarget */
        "je .Lf6df12_0006e46e\n"
        /* { scope 3 */
        "movl -0x2c(%ebp), %edx\n" /* line 1842 */
        "testl %edx, %edx\n"
        "je .Lf6df12_0006e098\n"
        "movl $viewLerp_CrouchStand+24, %edx\n" /* line 1845 */
        "movl $viewLerp_CrouchStand+12, -0x30(%ebp)\n"
        "movl $1, %ecx\n"
        ".Lf6df12_0006e074:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1855 */
        "movl (%eax), %esi\n"
        "cmpl %esi, -0x2c(%ebp)\n"
        "je .Lf6df12_0006e614\n"
        "jl .Lf6df12_0006e623\n" /* line 1864 */
        "addl $1, %ecx\n" /* line 1880 */
        "movl %edx, -0x30(%ebp)\n"
        "movl (%edx), %eax\n" /* line 1853 */
        "addl $0xc, %edx\n"
        "addl $1, %eax\n"
        "jne .Lf6df12_0006e074\n"
        ".Lf6df12_0006e098:\n"
        "cvtsi2ssl viewLerp_CrouchStand+8, %xmm3\n" /* line 1885 */
        "movss viewLerp_CrouchStand+4, %xmm2\n" /* line 1886 */
        /* } scope */
        ".Lf6df12_0006e0a8:\n"
        "movss %xmm2, 0xf8(%ebx)\n" /* line 2021 | ps */
        "movss 0x108(%ebx), %xmm1\n" /* line 2024 | ps */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "andps CorrectSolidDeltas+528, %xmm0\n"
        "ucomiss lit4_002ed72c, %xmm0\n" /* 0.05000000074505806f */
        "jbe .Lf6df12_0006e19b\n"
        /* { scope 3 */
        "leal 0x20(%ebx), %eax\n" /* line 2030 | ps */
        "movl 0x20(%ebx), %esi\n" /* line 199 */
        "movss 4(%eax), %xmm0\n" /* line 200 */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 2033 */
        "subss %xmm1, %xmm0\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 2035 | ps */
        "je .Lf6df12_0006e4d9\n"
        ".Lf6df12_0006e101:\n"
        "movaps %xmm0, %xmm1\n" /* line 2037 */
        "movl -0x50(%ebp), %eax\n"
        "divss 0x24(%eax), %xmm1\n"
        "movl %eax, %edx\n" /* line 2038 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* vFlatForward */
        "movl 4(%edx), %eax\n" /* line 2039 */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 2040 */
        "leal -0x24(%ebp), %eax\n" /* line 2041 | vFlatForward */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "movss %xmm3, -0x78(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x68(%ebp), %xmm1\n" /* line 272 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x24(%ebp), %xmm0\n" /* vFlatForward */
        "movss %xmm0, 0x20(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 0x24(%ebx)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 274 */
        "movss %xmm1, 0x28(%ebx)\n"
        "movl $1, 8(%esp)\n" /* line 2045 */
        "movl -0x50(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pm */
        "calll PM_StepSlideMove\n"
        "movl %esi, 0x20(%ebx)\n" /* line 199 */
        "movss -0x38(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 0x24(%ebx)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 0x28(%ebx)\n"
        "movss -0x78(%ebp), %xmm3\n" /* line 2051 */
        "movss %xmm3, 0x108(%ebx)\n" /* ps */
        /* } scope */
        ".Lf6df12_0006e19b:\n"
        "movl 0xfc(%ebx), %eax\n" /* line 2057 | ps */
        "testl %eax, %eax\n"
        "je .Lf6df12_0006e2b2\n"
        "movl 0x100(%ebx), %ecx\n" /* line 2061 | ps */
        "cmpl %ecx, 0xf4(%ebx)\n" /* ps */
        "je .Lf6df12_0006dfc6\n"
        "jge .Lf6df12_0006e3e7\n" /* line 2063 */
        "movl 0x104(%ebx), %eax\n" /* ps */
        "testl %eax, %eax\n"
        "jne .Lf6df12_0006dfc6\n"
        ".Lf6df12_0006e1cf:\n"
        "movl $0x64, -0x4c(%ebp)\n" /* line 2069 | iLerpFrac */
        "movl -0x2c(%ebp), %eax\n"
        "subl %eax, -0x4c(%ebp)\n" /* iLerpFrac */
        "movl 0x104(%ebx), %eax\n" /* line 2070 | ps */
        "xorl $1, %eax\n"
        "movl %eax, 0x104(%ebx)\n" /* ps */
        "testl %eax, %eax\n" /* line 2073 */
        "je .Lf6df12_0006e451\n"
        "cmpl $0x3c, %ecx\n" /* line 2075 */
        "je .Lf6df12_0006e4ca\n"
        "cmpl $0x28, %ecx\n" /* line 2077 */
        "je .Lf6df12_0006e605\n"
        ".Lf6df12_0006e205:\n"
        "cmpl $0x64, -0x4c(%ebp)\n" /* line 2088 | iLerpFrac */
        "je .Lf6df12_0006e4e6\n"
        "movl 0x104(%ebx), %eax\n" /* line 2097 | ps, bDown */
        "movl 0x100(%ebx), %ecx\n" /* ps */
        /* { scope 3 */
        "cmpl $0xb, %ecx\n" /* line 1806 */
        "je .Lf6df12_0006e517\n"
        "cmpl $0x28, %ecx\n" /* line 1810 */
        "je .Lf6df12_0006e50f\n"
        ".Lf6df12_0006e22d:\n"
        "movss lit4_002ed734, %xmm1\n" /* line 1812 | 200.0f */
        /* } scope */
        ".Lf6df12_0006e235:\n"
        "cvtsi2ssl -0x4c(%ebp), %xmm0\n" /* line 2100 | iLerpFrac */
        "mulss lit4_002ed738, %xmm0\n" /* 0.009999999776482582f */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "movl 4(%edi), %eax\n" /* pm */
        "subl %edx, %eax\n"
        "movl %eax, 0xfc(%ebx)\n" /* ps */
        "cmpl $0xb, %ecx\n" /* line 2103 */
        "je .Lf6df12_0006e524\n"
        "cmpl $0x28, %ecx\n" /* line 2108 */
        "je .Lf6df12_0006e5b6\n"
        /* { scope 3 */
        "movl -0x4c(%ebp), %esi\n" /* line 1842 | iLerpFrac */
        "testl %esi, %esi\n"
        "je .Lf6df12_0006e29d\n"
        "movl $viewLerp_CrouchStand+24, %edx\n" /* line 1844 */
        "movl $viewLerp_CrouchStand+12, %edi\n" /* pCurr */
        "movl $1, %ecx\n"
        ".Lf6df12_0006e27d:\n"
        "movl (%edi), %esi\n" /* line 1855 | pCurr */
        "cmpl %esi, -0x4c(%ebp)\n" /* iLerpFrac */
        "je .Lf6df12_0006e6b9\n"
        "jl .Lf6df12_0006e707\n" /* line 1864 */
        "addl $1, %ecx\n" /* line 1880 */
        "movl %edx, %edi\n" /* pCurr */
        "movl (%edx), %eax\n" /* line 1853 */
        "addl $0xc, %edx\n"
        "addl $1, %eax\n"
        "jne .Lf6df12_0006e27d\n"
        ".Lf6df12_0006e29d:\n"
        "cvtsi2ssl viewLerp_CrouchStand+8, %xmm2\n" /* line 1885 */
        /* } scope */
        ".Lf6df12_0006e2a5:\n"
        "movss %xmm2, 0x108(%ebx)\n" /* line 2120 | ps */
        "jmp .Lf6df12_0006dfc6\n"
        ".Lf6df12_0006e2b2:\n"
        "cvtsi2ssl 0xf4(%ebx), %xmm0\n" /* line 2125 | ps */
        "ucomiss 0xf8(%ebx), %xmm0\n" /* ps */
        "jp .Lf6df12_0006e2c9\n"
        "je .Lf6df12_0006dfc6\n"
        ".Lf6df12_0006e2c9:\n"
        "movl 4(%edi), %eax\n" /* line 2127 | pm */
        "movl %eax, 0xfc(%ebx)\n" /* ps */
        "movl 0xf4(%ebx), %edx\n" /* line 2129 | ps */
        "cmpl $0xb, %edx\n"
        "je .Lf6df12_0006e345\n"
        "cmpl $0x28, %edx\n" /* line 2139 */
        "je .Lf6df12_0006e3be\n"
        "cmpl $0x3c, %edx\n" /* line 2147 */
        "jne .Lf6df12_0006dfc6\n"
        "movl $0, 0x104(%ebx)\n" /* line 2150 | ps */
        "movl $0x28, %eax\n" /* line 2153 */
        "movss lit4_002ed73c, %xmm0\n" /* 40.0f */
        "ucomiss 0xf8(%ebx), %xmm0\n" /* ps */
        "cmovbel %edx, %eax\n"
        "movl %eax, 0x100(%ebx)\n" /* ps */
        "jmp .Lf6df12_0006dfc6\n"
        ".Lf6df12_0006e31b:\n"
        "movss lit4_002ed650, %xmm0\n" /* line 1979 | -180.0f */
        "movl -0x50(%ebp), %edx\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xf8(%ebx)\n" /* ps */
        "ucomiss %xmm0, %xmm2\n" /* line 1980 */
        "jae .Lf6df12_0006dfa8\n"
        "jmp .Lf6df12_0006dfc6\n"
        ".Lf6df12_0006e345:\n"
        "movl $1, 0x104(%ebx)\n" /* line 2132 | ps */
        "movss 0xf8(%ebx), %xmm0\n" /* line 2134 | ps */
        "movl $0x28, %eax\n" /* line 2135 */
        "ucomiss lit4_002ed73c, %xmm0\n" /* 40.0f */
        "cmovbel %edx, %eax\n"
        "movl %eax, 0x100(%ebx)\n" /* ps */
        "jmp .Lf6df12_0006dfc6\n"
        /* { scope 3 */
        ".Lf6df12_0006e371:\n"
        "movl -0x48(%ebp), %eax\n" /* line 1812 | bDown */
        "testl %eax, %eax\n"
        "jne .Lf6df12_0006e015\n"
        ".Lf6df12_0006e37c:\n"
        "movl $0x190, %edx\n"
        "jmp .Lf6df12_0006e01a\n"
        /* } scope */
        ".Lf6df12_0006e386:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 2000 | iTarget */
        "movss %xmm0, 0xf8(%ebx)\n" /* ps */
        "movl $0, 0xfc(%ebx)\n" /* line 2001 | ps */
        "movl $0, 0x108(%ebx)\n" /* line 2002 | ps */
        "movl $0x64, -0x2c(%ebp)\n"
        "jmp .Lf6df12_0006e19b\n"
        ".Lf6df12_0006e3b2:\n"
        "movl $0, -0x2c(%ebp)\n"
        "jmp .Lf6df12_0006e04a\n"
        ".Lf6df12_0006e3be:\n"
        "movss 0xf8(%ebx), %xmm0\n" /* line 2141 | ps */
        "xorl %eax, %eax\n" /* line 2142 */
        "ucomiss lit4_002ed73c, %xmm0\n" /* 40.0f */
        "seta %al\n"
        "movl %eax, 0x104(%ebx)\n" /* ps */
        "movl $0x28, 0x100(%ebx)\n" /* line 2145 | ps */
        "jmp .Lf6df12_0006dfc6\n"
        ".Lf6df12_0006e3e7:\n"
        "jle .Lf6df12_0006dfc6\n" /* line 2063 */
        "movl 0x104(%ebx), %eax\n" /* ps */
        "testl %eax, %eax\n"
        "jne .Lf6df12_0006e1cf\n"
        "jmp .Lf6df12_0006dfc6\n"
        /* { scope 3 */
        ".Lf6df12_0006e400:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1842 */
        "testl %eax, %eax\n"
        "je .Lf6df12_0006e43c\n"
        "movl $viewLerp_CrouchProne+24, %edx\n" /* line 1845 */
        "movl $viewLerp_CrouchProne+12, -0x34(%ebp)\n"
        "movl $1, %ecx\n"
        ".Lf6df12_0006e418:\n"
        "movl -0x34(%ebp), %eax\n" /* line 1855 */
        "movl (%eax), %esi\n"
        "cmpl %esi, -0x2c(%ebp)\n"
        "je .Lf6df12_0006e6f5\n"
        "jl .Lf6df12_0006e6c3\n" /* line 1864 */
        "addl $1, %ecx\n" /* line 1880 */
        "movl %edx, -0x34(%ebp)\n"
        "movl (%edx), %eax\n" /* line 1853 */
        "addl $0xc, %edx\n"
        "addl $1, %eax\n"
        "jne .Lf6df12_0006e418\n"
        ".Lf6df12_0006e43c:\n"
        "cvtsi2ssl viewLerp_CrouchProne+8, %xmm3\n" /* line 1885 */
        "movss viewLerp_CrouchProne+4, %xmm2\n" /* line 1886 */
        "jmp .Lf6df12_0006e0a8\n"
        /* } scope */
        ".Lf6df12_0006e451:\n"
        "cmpl $0xb, %ecx\n" /* line 2082 */
        "je .Lf6df12_0006e4ca\n"
        "cmpl $0x28, %ecx\n" /* line 2084 */
        "jne .Lf6df12_0006e205\n"
        "movl $0x3c, 0x100(%ebx)\n" /* line 2085 | ps */
        "jmp .Lf6df12_0006e205\n"
        ".Lf6df12_0006e46e:\n"
        "movl -0x48(%ebp), %eax\n" /* line 2013 | bDown */
        "testl %eax, %eax\n"
        "je .Lf6df12_0006e565\n"
        /* { scope 3 */
        "movl -0x2c(%ebp), %esi\n" /* line 1842 */
        "testl %esi, %esi\n"
        "je .Lf6df12_0006e4b5\n"
        "movl $viewLerp_StandCrouch+24, %edx\n" /* line 1845 */
        "movl $viewLerp_StandCrouch+12, -0x44(%ebp)\n" /* pCurr */
        "movl $1, %ecx\n"
        ".Lf6df12_0006e491:\n"
        "movl -0x44(%ebp), %eax\n" /* line 1855 | pCurr */
        "movl (%eax), %esi\n"
        "cmpl %esi, -0x2c(%ebp)\n"
        "je .Lf6df12_0006e7c6\n"
        "jl .Lf6df12_0006e794\n" /* line 1864 */
        "addl $1, %ecx\n" /* line 1880 */
        "movl %edx, -0x44(%ebp)\n" /* pCurr */
        "movl (%edx), %eax\n" /* line 1853 */
        "addl $0xc, %edx\n"
        "addl $1, %eax\n"
        "jne .Lf6df12_0006e491\n"
        ".Lf6df12_0006e4b5:\n"
        "cvtsi2ssl viewLerp_StandCrouch+8, %xmm3\n" /* line 1885 */
        "movss viewLerp_StandCrouch+4, %xmm2\n" /* line 1886 */
        "jmp .Lf6df12_0006e0a8\n"
        /* } scope */
        ".Lf6df12_0006e4ca:\n"
        "movl $0x28, 0x100(%ebx)\n" /* line 2083 | ps */
        "jmp .Lf6df12_0006e205\n"
        /* { scope 3 */
        ".Lf6df12_0006e4d9:\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* line 2036 | 0.5f */
        "jmp .Lf6df12_0006e101\n"
        /* } scope */
        ".Lf6df12_0006e4e6:\n"
        "cvtsi2ssl 0x100(%ebx), %xmm0\n" /* line 2090 | ps */
        "movss %xmm0, 0xf8(%ebx)\n" /* ps */
        "movl $0, 0xfc(%ebx)\n" /* line 2091 | ps */
        "movl $0, 0x108(%ebx)\n" /* line 2092 | ps */
        "jmp .Lf6df12_0006dfc6\n"
        /* { scope 3 */
        ".Lf6df12_0006e50f:\n"
        "testl %eax, %eax\n" /* line 1812 */
        "jne .Lf6df12_0006e22d\n"
        ".Lf6df12_0006e517:\n"
        "movss lit4_002ed730, %xmm1\n" /* 400.0f */
        "jmp .Lf6df12_0006e235\n"
        /* } scope */
        /* { scope 3 */
        ".Lf6df12_0006e524:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1842 | iLerpFrac */
        "testl %eax, %eax\n"
        "je .Lf6df12_0006e558\n"
        "movl $viewLerp_CrouchProne+24, %edx\n" /* line 1844 */
        "movl $viewLerp_CrouchProne+12, %edi\n" /* pCurr */
        "movl $1, %eax\n"
        ".Lf6df12_0006e53a:\n"
        "movl (%edi), %esi\n" /* line 1855 | pCurr */
        "cmpl %esi, -0x4c(%ebp)\n" /* iLerpFrac */
        "je .Lf6df12_0006e6b9\n"
        "jl .Lf6df12_0006e744\n" /* line 1864 */
        "addl $1, %eax\n" /* line 1880 */
        "movl %edx, %edi\n" /* pCurr */
        "leal 0xc(%edx), %edx\n" /* line 1853 */
        "cmpl $-1, (%edi)\n" /* pCurr */
        "jne .Lf6df12_0006e53a\n"
        ".Lf6df12_0006e558:\n"
        "cvtsi2ssl viewLerp_CrouchProne+8, %xmm2\n" /* line 1885 */
        "jmp .Lf6df12_0006e2a5\n"
        /* } scope */
        /* { scope 3 */
        ".Lf6df12_0006e565:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 1842 */
        "testl %ecx, %ecx\n"
        "je .Lf6df12_0006e5a1\n"
        "movl $viewLerp_ProneCrouch+24, %edx\n" /* line 1845 */
        "movl $viewLerp_ProneCrouch+12, -0x40(%ebp)\n" /* pCurr */
        "movl $1, %ecx\n"
        ".Lf6df12_0006e57d:\n"
        "movl -0x40(%ebp), %eax\n" /* line 1855 | pCurr */
        "movl (%eax), %esi\n"
        "cmpl %esi, -0x2c(%ebp)\n"
        "je .Lf6df12_0006e782\n"
        "jl .Lf6df12_0006e750\n" /* line 1864 */
        "addl $1, %ecx\n" /* line 1880 */
        "movl %edx, -0x40(%ebp)\n" /* pCurr */
        "movl (%edx), %eax\n" /* line 1853 */
        "addl $0xc, %edx\n"
        "addl $1, %eax\n"
        "jne .Lf6df12_0006e57d\n"
        ".Lf6df12_0006e5a1:\n"
        "cvtsi2ssl viewLerp_ProneCrouch+8, %xmm3\n" /* line 1885 */
        "movss viewLerp_ProneCrouch+4, %xmm2\n" /* line 1886 */
        "jmp .Lf6df12_0006e0a8\n"
        /* } scope */
        ".Lf6df12_0006e5b6:\n"
        "movl 0x104(%ebx), %eax\n" /* line 2110 | ps */
        "testl %eax, %eax\n"
        "je .Lf6df12_0006e67c\n"
        /* { scope 3 */
        "movl -0x4c(%ebp), %eax\n" /* line 1842 | iLerpFrac */
        "testl %eax, %eax\n"
        "je .Lf6df12_0006e5f8\n"
        "movl $viewLerp_StandCrouch+24, %edx\n" /* line 1844 */
        "movl $viewLerp_StandCrouch+12, %edi\n" /* pCurr */
        "movl $1, %eax\n"
        ".Lf6df12_0006e5da:\n"
        "movl (%edi), %esi\n" /* line 1855 | pCurr */
        "cmpl %esi, -0x4c(%ebp)\n" /* iLerpFrac */
        "je .Lf6df12_0006e6b9\n"
        "jl .Lf6df12_0006e7e7\n" /* line 1864 */
        "addl $1, %eax\n" /* line 1880 */
        "movl %edx, %edi\n" /* pCurr */
        "leal 0xc(%edx), %edx\n" /* line 1853 */
        "cmpl $-1, (%edi)\n" /* pCurr */
        "jne .Lf6df12_0006e5da\n"
        ".Lf6df12_0006e5f8:\n"
        "cvtsi2ssl viewLerp_StandCrouch+8, %xmm2\n" /* line 1885 */
        "jmp .Lf6df12_0006e2a5\n"
        /* } scope */
        ".Lf6df12_0006e605:\n"
        "movl $0xb, 0x100(%ebx)\n" /* line 2078 | ps */
        "jmp .Lf6df12_0006e205\n"
        /* { scope 3 */
        ".Lf6df12_0006e614:\n"
        "cvtsi2ssl 8(%eax), %xmm3\n" /* line 1858 */
        "movss 4(%eax), %xmm2\n" /* line 1859 */
        "jmp .Lf6df12_0006e0a8\n"
        /* { scope 4 */
        ".Lf6df12_0006e623:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1868 */
        "leal viewLerp_CrouchStand(, %eax, 4), %eax\n"
        "leal -0xc(%eax), %ecx\n"
        "movl -0xc(%eax), %edx\n" /* line 1872 */
        "movl -0x2c(%ebp), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "subl %edx, %esi\n"
        "cvtsi2ssl %esi, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 8(%ecx), %edx\n" /* line 1875 */
        "cvtsi2ssl %edx, %xmm3\n"
        "movl -0x30(%ebp), %esi\n"
        ".Lf6df12_0006e650:\n"
        "movl 8(%esi), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss 4(%ecx), %xmm0\n" /* line 1876 */
        "movss 4(%esi), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "jmp .Lf6df12_0006e0a8\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf6df12_0006e67c:\n"
        "movl -0x4c(%ebp), %edi\n" /* line 1842 | iLerpFrac, pCurr */
        "testl %edi, %edi\n" /* pCurr */
        "je .Lf6df12_0006e6ac\n"
        "movl $viewLerp_ProneCrouch+24, %edx\n" /* line 1844 */
        "movl $viewLerp_ProneCrouch+12, %edi\n" /* pCurr */
        "movl $1, %eax\n"
        ".Lf6df12_0006e692:\n"
        "movl (%edi), %esi\n" /* line 1855 | pCurr */
        "cmpl %esi, -0x4c(%ebp)\n" /* iLerpFrac */
        "je .Lf6df12_0006e6b9\n"
        "jl .Lf6df12_0006e7d8\n" /* line 1864 */
        "addl $1, %eax\n" /* line 1880 */
        "movl %edx, %edi\n" /* pCurr */
        "leal 0xc(%edx), %edx\n" /* line 1853 */
        "cmpl $-1, (%edi)\n" /* pCurr */
        "jne .Lf6df12_0006e692\n"
        ".Lf6df12_0006e6ac:\n"
        "cvtsi2ssl viewLerp_ProneCrouch+8, %xmm2\n" /* line 1885 */
        "jmp .Lf6df12_0006e2a5\n"
        /* } scope */
        /* { scope 3 */
        ".Lf6df12_0006e6b9:\n"
        "cvtsi2ssl 8(%edi), %xmm2\n" /* line 1858 | pCurr */
        "jmp .Lf6df12_0006e2a5\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf6df12_0006e6c3:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1868 */
        "leal viewLerp_CrouchProne(, %eax, 4), %eax\n"
        "leal -0xc(%eax), %ecx\n"
        "movl -0xc(%eax), %edx\n" /* line 1872 */
        "movl -0x2c(%ebp), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "subl %edx, %esi\n"
        "cvtsi2ssl %esi, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 8(%ecx), %edx\n" /* line 1875 */
        "cvtsi2ssl %edx, %xmm3\n"
        "movl -0x34(%ebp), %esi\n"
        "jmp .Lf6df12_0006e650\n"
        /* } scope */
        ".Lf6df12_0006e6f5:\n"
        "movl -0x34(%ebp), %esi\n" /* line 1858 */
        "cvtsi2ssl 8(%esi), %xmm3\n"
        "movss 4(%esi), %xmm2\n" /* line 1859 */
        "jmp .Lf6df12_0006e0a8\n"
        /* } scope */
        /* { scope 3 */
        ".Lf6df12_0006e707:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1868 */
        "leal viewLerp_CrouchStand(, %eax, 4), %eax\n"
        ".Lf6df12_0006e711:\n"
        "movl -0xc(%eax), %edx\n" /* line 1872 */
        "movl -4(%eax), %ecx\n" /* line 1875 */
        "cvtsi2ssl %ecx, %xmm2\n"
        "movl -0x4c(%ebp), %eax\n" /* iLerpFrac */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "subl %edx, %esi\n"
        "cvtsi2ssl %esi, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 8(%edi), %eax\n" /* pCurr */
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "jmp .Lf6df12_0006e2a5\n"
        /* } scope */
        /* { scope 3 */
        ".Lf6df12_0006e744:\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 1868 */
        "leal viewLerp_CrouchProne(, %eax, 4), %eax\n"
        "jmp .Lf6df12_0006e711\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf6df12_0006e750:\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal viewLerp_ProneCrouch(, %eax, 4), %eax\n"
        "leal -0xc(%eax), %ecx\n"
        "movl -0xc(%eax), %edx\n" /* line 1872 */
        "movl -0x2c(%ebp), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "subl %edx, %esi\n"
        "cvtsi2ssl %esi, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 8(%ecx), %edx\n" /* line 1875 */
        "cvtsi2ssl %edx, %xmm3\n"
        "movl -0x40(%ebp), %esi\n" /* pCurr */
        "jmp .Lf6df12_0006e650\n"
        /* } scope */
        ".Lf6df12_0006e782:\n"
        "movl -0x40(%ebp), %edx\n" /* line 1858 | pCurr */
        "cvtsi2ssl 8(%edx), %xmm3\n"
        "movss 4(%edx), %xmm2\n" /* line 1859 */
        "jmp .Lf6df12_0006e0a8\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf6df12_0006e794:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1868 */
        "leal viewLerp_StandCrouch(, %eax, 4), %eax\n"
        "leal -0xc(%eax), %ecx\n"
        "movl -0xc(%eax), %edx\n" /* line 1872 */
        "movl -0x2c(%ebp), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "subl %edx, %esi\n"
        "cvtsi2ssl %esi, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 8(%ecx), %edx\n" /* line 1875 */
        "cvtsi2ssl %edx, %xmm3\n"
        "movl -0x44(%ebp), %esi\n" /* pCurr */
        "jmp .Lf6df12_0006e650\n"
        /* } scope */
        ".Lf6df12_0006e7c6:\n"
        "movl -0x44(%ebp), %edx\n" /* line 1858 | pCurr */
        "cvtsi2ssl 8(%edx), %xmm3\n"
        "movss 4(%edx), %xmm2\n" /* line 1859 */
        "jmp .Lf6df12_0006e0a8\n"
        /* } scope */
        /* { scope 3 */
        ".Lf6df12_0006e7d8:\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 1868 */
        "leal viewLerp_ProneCrouch(, %eax, 4), %eax\n"
        "jmp .Lf6df12_0006e711\n"
        /* } scope */
        /* { scope 3 */
        ".Lf6df12_0006e7e7:\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal viewLerp_StandCrouch(, %eax, 4), %eax\n"
        "jmp .Lf6df12_0006e711\n"
    );
}

/* line 2179 */
static __attribute__((naked))
void PM_CheckDuck(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2179 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %eax, %esi\n" /* pm */
        "movl %edx, %ebx\n" /* pml */
        /* { scope 1: vPoint, delta, vEnd */
        "movl (%eax), %edi\n" /* line 2189 | ps */
        "movl $0, 0xe0(%eax)\n" /* line 2193 */
        "cmpl $4, 4(%edi)\n" /* line 2196 | ps */
        "je .Lf6e7f6_0006eb96\n"
        "movl 0xc(%edi), %eax\n" /* line 2224 | ps */
        "andl $1, %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl 0x56c(%edi), %eax\n" /* line 2230 | ps */
        "movl %eax, 0xc4(%esi)\n" /* pm */
        "movl 0x570(%edi), %eax\n" /* line 2231 | ps */
        "movl %eax, 0xc8(%esi)\n" /* pm */
        "movl 0x578(%edi), %eax\n" /* line 2233 | ps */
        "movl %eax, 0xd0(%esi)\n" /* pm */
        "movl 0x57c(%edi), %eax\n" /* line 2234 | ps */
        "movl %eax, 0xd4(%esi)\n" /* pm */
        "movl 0x574(%edi), %eax\n" /* line 2236 | ps */
        "movl %eax, 0xcc(%esi)\n" /* pm */
        "cmpl $5, 4(%edi)\n" /* line 2238 | ps */
        "jg .Lf6e7f6_0006eb6e\n"
        "movl 0xa0(%edi), %eax\n" /* line 2268 | ps */
        "testb $3, %ah\n"
        "je .Lf6e7f6_0006ebf7\n"
        "testb $1, %ah\n" /* line 2270 */
        "jne .Lf6e7f6_0006ed77\n"
        "testb $2, %ah\n" /* line 2275 */
        "je .Lf6e7f6_0006ee6d\n"
        "movl 0xc(%edi), %eax\n" /* line 2278 | ps */
        "orl $2, %eax\n"
        "andl $0xfffffffe, %eax\n"
        "movl %eax, 0xc(%edi)\n" /* ps */
        ".Lf6e7f6_0006e898:\n"
        "movl 0xfc(%edi), %eax\n" /* line 2525 | ps */
        "testl %eax, %eax\n"
        "jne .Lf6e7f6_0006e8ce\n"
        "movl 0xc(%edi), %eax\n" /* line 2527 | ps */
        "testb $1, %al\n"
        "jne .Lf6e7f6_0006ed06\n"
        "cmpl $0xb, 0xf4(%edi)\n" /* line 2549 | ps */
        "je .Lf6e7f6_0006f097\n"
        "andl $2, %eax\n" /* line 2557 */
        "cmpl $1, %eax\n" /* line 2559 */
        "sbbl %eax, %eax\n"
        "andl $0x14, %eax\n"
        "addl $0x28, %eax\n"
        "movl %eax, 0xf4(%edi)\n" /* ps */
        ".Lf6e7f6_0006e8ce:\n"
        "movl %ebx, %edx\n" /* line 2570 | pml */
        "movl %esi, %eax\n" /* pm */
        "calll PM_ViewHeightAdjust\n"
        "movl 0xf4(%edi), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "je .Lf6e7f6_0006ee76\n"
        "cmpl $0xb, %eax\n" /* line 353 */
        "je .Lf6e7f6_0006eecd\n"
        "movl 0x580(%edi), %eax\n" /* line 2591 | ps */
        "movl %eax, 0xd8(%esi)\n" /* pm */
        "andl $0xfffffff3, 0xa0(%edi)\n" /* line 2592 | ps */
        "movl 0xc(%edi), %eax\n" /* line 2593 | ps */
        "andl $0xfffffffc, %eax\n"
        "movl %eax, 0xc(%edi)\n" /* ps */
        ".Lf6e7f6_0006e90b:\n"
        "testb $1, %al\n" /* line 2597 */
        "je .Lf6e7f6_0006eb8b\n"
        "movl -0x74(%ebp), %ecx\n" /* line 2599 */
        "testl %ecx, %ecx\n"
        "jne .Lf6e7f6_0006eb8b\n"
        /* { scope 2 */
        "cmpw $0, 0x1c(%esi)\n" /* line 2606 | pm */
        "jne .Lf6e7f6_0006edc3\n"
        ".Lf6e7f6_0006e929:\n"
        "leal 0x14(%edi), %ebx\n" /* line 2613 | ps, pml */
        "movl 0x14(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* vEnd */
        "movl 0x18(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss lit4_002ed6b4, %xmm0\n" /* line 2614 | 10.0f */
        "addss 0x1c(%edi), %xmm0\n" /* ps */
        "movss %xmm0, -0x28(%ebp)\n"
        "leal 0xd0(%esi), %eax\n" /* line 2615 | pm */
        "movl %eax, -0x70(%ebp)\n"
        "leal 0xc4(%esi), %edx\n" /* pm */
        "movl %edx, -0x6c(%ebp)\n"
        "movzbl 0xe4(%esi), %edx\n" /* pm */
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x3c(%esi), %eax\n" /* pm */
        "andl $0xfdffffff, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vEnd */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* pml */
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *pmoveHandlers(, %edx, 4)\n"
        "movss -0x54(%ebp), %xmm2\n" /* line 2616 | trace, fraction */
        /* { scope 3 */
        "movss 0x14(%edi), %xmm1\n" /* line 1203 */
        "movss -0x30(%ebp), %xmm0\n" /* vEnd */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* vEnd */
        "movss 0x18(%edi), %xmm1\n" /* line 1204 */
        "movss -0x2c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss 0x1c(%edi), %xmm1\n" /* line 1205 */
        "movss -0x28(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        "movzbl 0xe4(%esi), %edx\n" /* line 2618 | pm */
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x3c(%esi), %eax\n" /* pm */
        "andl $0xfdffffff, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* pml */
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vEnd */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *pmoveHandlers(, %edx, 4)\n"
        "movss -0x54(%ebp), %xmm2\n" /* line 2619 | trace, fraction */
        /* { scope 3 */
        "movss -0x30(%ebp), %xmm1\n" /* line 1203 | vEnd */
        "movss 0x14(%edi), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14(%edi)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 1204 */
        "movss 0x18(%edi), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ebx)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 1205 */
        "movss 0x1c(%edi), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%ebx)\n"
        /* } scope */
        "movl 0xec(%edi), %eax\n" /* line 2622 | ps */
        "movl %eax, 0x584(%edi)\n" /* ps */
        "movl 0x14(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n" /* vPoint */
        "movl 0x18(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movss 0x1c(%edi), %xmm0\n" /* line 201 */
        "subss lit4_002ed604, %xmm0\n" /* line 2626 | 0.25f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movzbl 0xe4(%esi), %edx\n" /* line 2627 | pm */
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x3c(%esi), %eax\n" /* pm */
        "andl $0xfdffffff, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* vPoint */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* pml */
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *pmoveHandlers(, %edx, 4)\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 2629 */
        "je .Lf6e7f6_0006ed91\n"
        ".Lf6e7f6_0006eb0e:\n"
        "movl $0, 0x588(%edi)\n" /* line 2636 | ps */
        ".Lf6e7f6_0006eb18:\n"
        "movl 0xe8(%edi), %eax\n" /* line 2640 | ps */
        "movl %eax, 4(%esp)\n"
        "movl 0x588(%edi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps -0x68(%ebp)\n" /* delta */
        "movss -0x68(%ebp), %xmm0\n" /* line 2641 | delta */
        "ucomiss lit4_002ed714, %xmm0\n" /* -45.0f */
        "jae .Lf6e7f6_0006eea3\n"
        "jp .Lf6e7f6_0006eea3\n"
        "movss 0xe8(%edi), %xmm0\n" /* line 2642 | ps */
        "subss lit4_002ed6ec, %xmm0\n" /* 45.0f */
        "movss %xmm0, 0x58c(%edi)\n" /* ps */
        /* } scope */
        /* } scope */
        "addl $0xac, %esp\n" /* line 2649 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vPoint, delta, vEnd */
        ".Lf6e7f6_0006eb6e:\n"
        "movl 0x580(%edi), %eax\n" /* line 2240 | ps */
        "movl %eax, 0xd8(%esi)\n" /* pm */
        "movl $8, 0xf4(%edi)\n" /* line 2241 | ps */
        "movl %esi, %eax\n" /* line 2243 | pm */
        "calll PM_ViewHeightAdjust\n"
        /* } scope */
        ".Lf6e7f6_0006eb8b:\n"
        "addl $0xac, %esp\n" /* line 2649 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vPoint, delta, vEnd */
        ".Lf6e7f6_0006eb96:\n"
        "movl $0xc1000000, %eax\n" /* line 2198 */
        "movl %eax, 0xc4(%esi)\n" /* pm */
        "movl %eax, 0xc8(%esi)\n" /* line 2199 | pm */
        "movl %eax, 0xcc(%esi)\n" /* line 2200 | pm */
        "movl $0x41000000, %eax\n" /* line 2202 */
        "movl %eax, 0xd0(%esi)\n" /* pm */
        "movl %eax, 0xd4(%esi)\n" /* line 2203 | pm */
        "movl $0x41800000, 0xd8(%esi)\n" /* line 2204 | pm */
        "andl $0xfffffffc, 0xc(%edi)\n" /* line 2207 | ps */
        "movl 8(%esi), %eax\n" /* line 2209 | pm */
        "testb $1, %ah\n"
        "jne .Lf6e7f6_0006eefa\n"
        ".Lf6e7f6_0006ebd8:\n"
        "movl $0, 0xf4(%edi)\n" /* line 2216 | ps */
        "movl $0, 0xf8(%edi)\n" /* line 2217 | ps */
        /* } scope */
        "addl $0xac, %esp\n" /* line 2649 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vPoint, delta, vEnd */
        ".Lf6e7f6_0006ebf7:\n"
        "movl 0xc(%edi), %eax\n" /* line 2283 | ps */
        "testw %ax, %ax\n"
        "js .Lf6e7f6_0006e898\n"
        "testb $0x20, %al\n" /* line 2339 */
        "je .Lf6e7f6_0006ef3e\n"
        "movl 8(%esi), %edx\n" /* pm */
        "testb $3, %dh\n"
        "jne .Lf6e7f6_0006ef1d\n"
        ".Lf6e7f6_0006ec17:\n"
        "testb $1, %dh\n" /* line 2400 */
        "je .Lf6e7f6_0006ef46\n"
        "testb $1, %al\n" /* line 2403 */
        "jne .Lf6e7f6_0006ed83\n"
        "cmpl $0x3ff, 0x60(%edi)\n" /* ps */
        "je .Lf6e7f6_0006e898\n"
        "movl $0x42840000, 0x34(%esp)\n"
        "movl $0, 0x30(%esp)\n"
        "movzbl 0xe4(%esi), %eax\n" /* pm */
        "movl %eax, 0x2c(%esp)\n"
        "movl $0, 0x28(%esp)\n"
        "movl $1, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "leal 0x5b0(%edi), %eax\n" /* ps */
        "movl %eax, 0x1c(%esp)\n"
        "leal 0x5ac(%edi), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal 0x5a8(%edi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xec(%edi), %eax\n" /* ps */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41f00000, 0xc(%esp)\n"
        "movl 0xd0(%esi), %eax\n" /* pm */
        "movl %eax, 8(%esp)\n"
        "leal 0x14(%edi), %eax\n" /* ps */
        "movl %eax, 4(%esp)\n"
        "movl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_CheckProne\n"
        "testl %eax, %eax\n"
        "jne .Lf6e7f6_0006ed80\n"
        "cmpl $0x3ff, 0x60(%edi)\n" /* line 2420 | ps */
        "je .Lf6e7f6_0006e898\n"
        "movl 0xc(%edi), %eax\n" /* line 2422 | ps */
        "orl $0x10000, %eax\n"
        "movl %eax, 0xc(%edi)\n" /* ps */
        "testb $0x20, 9(%esi)\n" /* line 2425 | pm */
        "jne .Lf6e7f6_0006e898\n"
        "testb $2, %al\n" /* line 2427 */
        "je .Lf6e7f6_0006f1fd\n"
        "movl %edi, 8(%esp)\n" /* line 2428 | ps */
        "movl $0, 4(%esp)\n"
        "movl $0x8d, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf6e7f6_0006e898\n"
        ".Lf6e7f6_0006ed06:\n"
        "movl 0xf4(%edi), %eax\n" /* line 2529 | ps */
        "cmpl $0x3c, %eax\n"
        "je .Lf6e7f6_0006f088\n"
        "cmpl $0xb, %eax\n" /* line 2536 */
        "je .Lf6e7f6_0006e8ce\n"
        "movl $0xb, 0xf4(%edi)\n" /* line 2538 | ps */
        "movl $1, 0xe0(%esi)\n" /* line 2540 | pm */
        "movl $1, 0x18(%esp)\n" /* line 2541 */
        "movl $1, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_PlayAnim\n"
        "movl %edi, (%esp)\n" /* line 2543 | ps */
        "calll Jump_ActivateSlowdown\n"
        "jmp .Lf6e7f6_0006e8ce\n"
        ".Lf6e7f6_0006ed77:\n"
        "testb $2, %ah\n" /* line 2270 */
        "jne .Lf6e7f6_0006ee6d\n"
        ".Lf6e7f6_0006ed80:\n"
        "movl 0xc(%edi), %eax\n" /* line 2273 | ps */
        ".Lf6e7f6_0006ed83:\n"
        "orl $1, %eax\n"
        "andl $0xfffffffd, %eax\n"
        "movl %eax, 0xc(%edi)\n" /* ps */
        "jmp .Lf6e7f6_0006e898\n"
        /* { scope 2 */
        ".Lf6e7f6_0006ed91:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 2629 | 1.0f */
        "ucomiss -0x54(%ebp), %xmm0\n" /* trace */
        "jbe .Lf6e7f6_0006eb0e\n"
        "leal -0x50(%ebp), %eax\n" /* line 2632 */
        "movl %eax, 4(%esp)\n"
        "movl 0x584(%edi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll PitchForYawOnNormal\n"
        "fstps 0x588(%edi)\n" /* ps */
        "jmp .Lf6e7f6_0006eb18\n"
        ".Lf6e7f6_0006edc3:\n"
        "andb $0xf7, %ah\n" /* line 2608 */
        "movl %eax, 0xc(%edi)\n" /* ps */
        "movl %edi, (%esp)\n" /* line 2609 | ps */
        "calll PM_ExitAimDownSight\n"
        "jmp .Lf6e7f6_0006e929\n"
        /* } scope */
        ".Lf6e7f6_0006edd6:\n"
        "movl 0x580(%edi), %eax\n" /* line 2472 | ps */
        "movl %eax, 0xd8(%esi)\n" /* pm */
        "leal 0xd0(%esi), %edx\n" /* line 2473 | pm */
        "movl %edx, -0x5c(%ebp)\n"
        "leal 0xc4(%esi), %eax\n" /* pm */
        "movl %eax, -0x60(%ebp)\n"
        "leal 0x14(%edi), %edx\n" /* ps */
        "movl %edx, -0x64(%ebp)\n"
        "movzbl 0xe4(%esi), %edx\n" /* pm */
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x3c(%esi), %eax\n" /* pm */
        "andl $0xfdffffff, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *pmoveHandlers(, %edx, 4)\n"
        "cmpb $0, -0x32(%ebp)\n" /* line 2474 */
        "jne .Lf6e7f6_0006f142\n"
        "movl $0, 0xc(%esp)\n" /* line 2477 */
        "movl $0, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        ".Lf6e7f6_0006ee6d:\n"
        "andl $0xfffffffc, 0xc(%edi)\n" /* line 2480 | ps */
        "jmp .Lf6e7f6_0006e898\n"
        ".Lf6e7f6_0006ee76:\n"
        "movl $0x42480000, 0xd8(%esi)\n" /* line 2583 | pm */
        "movl 0xa0(%edi), %eax\n" /* line 2585 | ps */
        "orl $4, %eax\n"
        "andl $0xfffffff7, %eax\n"
        "movl %eax, 0xa0(%edi)\n" /* ps */
        "movl 0xc(%edi), %eax\n" /* line 2587 | ps */
        "orl $2, %eax\n"
        "andl $0xfffffffe, %eax\n"
        "movl %eax, 0xc(%edi)\n" /* ps */
        "jmp .Lf6e7f6_0006e90b\n"
        /* { scope 2 */
        ".Lf6e7f6_0006eea3:\n"
        "ucomiss lit4_002ed6ec, %xmm0\n" /* line 2643 | 45.0f */
        "jbe .Lf6e7f6_0006efe8\n"
        "movss lit4_002ed6ec, %xmm0\n" /* line 2644 | 45.0f */
        "addss 0xe8(%edi), %xmm0\n" /* ps */
        "movss %xmm0, 0x58c(%edi)\n" /* ps */
        "jmp .Lf6e7f6_0006eb8b\n"
        /* } scope */
        ".Lf6e7f6_0006eecd:\n"
        "movl $0x41f00000, 0xd8(%esi)\n" /* line 2575 | pm */
        "movl 0xa0(%edi), %eax\n" /* line 2577 | ps */
        "orl $8, %eax\n"
        "andl $0xfffffffb, %eax\n"
        "movl %eax, 0xa0(%edi)\n" /* ps */
        "movl 0xc(%edi), %eax\n" /* line 2579 | ps */
        "orl $1, %eax\n"
        "andl $0xfffffffd, %eax\n"
        "movl %eax, 0xc(%edi)\n" /* ps */
        "jmp .Lf6e7f6_0006e90b\n"
        ".Lf6e7f6_0006eefa:\n"
        "andb $0xfe, %ah\n" /* line 2211 */
        "movl %eax, 8(%esi)\n" /* pm */
        "movl %edi, 8(%esp)\n" /* line 2212 | ps */
        "movl $0, 4(%esp)\n"
        "movl $0x8c, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf6e7f6_0006ebd8\n"
        ".Lf6e7f6_0006ef1d:\n"
        "andb $0xfc, %dh\n" /* line 2341 */
        "movl %edx, 8(%esi)\n" /* pm */
        "movl %edi, 8(%esp)\n" /* line 2342 | ps */
        "movl $0, 4(%esp)\n"
        "movl $0x8c, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "movl 0xc(%edi), %eax\n" /* ps */
        ".Lf6e7f6_0006ef3e:\n"
        "movl 8(%esi), %edx\n" /* pm */
        "jmp .Lf6e7f6_0006ec17\n"
        ".Lf6e7f6_0006ef46:\n"
        "andb $2, %dh\n" /* line 2435 */
        "jne .Lf6e7f6_0006eff9\n"
        "testb $1, %al\n" /* line 2469 */
        "jne .Lf6e7f6_0006edd6\n"
        "testb $2, %al\n" /* line 2501 */
        "je .Lf6e7f6_0006e898\n"
        "movl 0x580(%edi), %eax\n" /* line 2504 | ps */
        "movl %eax, 0xd8(%esi)\n" /* pm */
        "leal 0x14(%edi), %ecx\n" /* line 2505 | ps */
        "movzbl 0xe4(%esi), %edx\n" /* pm */
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x3c(%esi), %eax\n" /* pm */
        "andl $0xfdffffff, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "leal 0xd0(%esi), %eax\n" /* pm */
        "movl %eax, 0xc(%esp)\n"
        "leal 0xc4(%esi), %eax\n" /* pm */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *pmoveHandlers(, %edx, 4)\n"
        "cmpb $0, -0x32(%ebp)\n" /* line 2506 */
        "je .Lf6e7f6_0006f1d4\n"
        "testb $0x20, 9(%esi)\n" /* line 2517 | pm */
        "jne .Lf6e7f6_0006e898\n"
        "movl %edi, 8(%esp)\n" /* line 2518 | ps */
        "movl $1, 4(%esp)\n"
        "movl $0x8d, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf6e7f6_0006e898\n"
        /* { scope 2 */
        ".Lf6e7f6_0006efe8:\n"
        "movl 0x588(%edi), %eax\n" /* line 2646 | ps */
        "movl %eax, 0x58c(%edi)\n" /* ps */
        "jmp .Lf6e7f6_0006eb8b\n"
        /* } scope */
        ".Lf6e7f6_0006eff9:\n"
        "testb $1, %al\n" /* line 2437 */
        "je .Lf6e7f6_0006f0e8\n"
        "movl $0x42480000, 0xd8(%esi)\n" /* line 2439 | pm */
        "leal 0x14(%edi), %ecx\n" /* line 2440 | ps */
        "movzbl 0xe4(%esi), %edx\n" /* pm */
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x3c(%esi), %eax\n" /* pm */
        "andl $0xfdffffff, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0xcc(%edi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "leal 0xd0(%esi), %eax\n" /* pm */
        "movl %eax, 0xc(%esp)\n"
        "leal 0xc4(%esi), %eax\n" /* pm */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *pmoveHandlers(, %edx, 4)\n"
        "cmpb $0, -0x32(%ebp)\n" /* line 2441 */
        "je .Lf6e7f6_0006f111\n"
        "testb $0x20, 9(%esi)\n" /* line 2453 | pm */
        "jne .Lf6e7f6_0006e898\n"
        "movl %edi, 8(%esp)\n" /* line 2454 | ps */
        "movl $2, 4(%esp)\n"
        "movl $0x8e, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf6e7f6_0006e898\n"
        ".Lf6e7f6_0006f088:\n"
        "movl $0x28, 0xf4(%edi)\n" /* line 2531 | ps */
        "jmp .Lf6e7f6_0006e8ce\n"
        ".Lf6e7f6_0006f097:\n"
        "movl $0x28, 0xf4(%edi)\n" /* line 2551 | ps */
        "movl $1, 0xe0(%esi)\n" /* line 2553 | pm */
        "movl $1, 0x18(%esp)\n" /* line 2554 */
        "movl $1, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_PlayAnim\n"
        "jmp .Lf6e7f6_0006e8ce\n"
        ".Lf6e7f6_0006f0e8:\n"
        "movl $0, 0xc(%esp)\n" /* line 2460 */
        "movl $0, 8(%esp)\n"
        "movl $0xd, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "orl $2, 0xc(%edi)\n" /* line 2463 | ps */
        "jmp .Lf6e7f6_0006e898\n"
        ".Lf6e7f6_0006f111:\n"
        "movl $0, 0xc(%esp)\n" /* line 2444 */
        "movl $0, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "movl 0xc(%edi), %eax\n" /* line 2448 | ps */
        "andl $0xfffffffe, %eax\n"
        "orl $2, %eax\n"
        "movl %eax, 0xc(%edi)\n" /* ps */
        "jmp .Lf6e7f6_0006e898\n"
        ".Lf6e7f6_0006f142:\n"
        "movl $0x42480000, 0xd8(%esi)\n" /* line 2485 | pm */
        "movzbl 0xe4(%esi), %eax\n" /* line 2486 | pm */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x3c(%esi), %edx\n" /* pm */
        "andl $0xfdffffff, %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0xcc(%edi), %edx\n" /* ps */
        "movl %edx, 0x14(%esp)\n"
        "movl -0x64(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0x60(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl -0x64(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x54(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x32(%ebp)\n" /* line 2487 */
        "jne .Lf6e7f6_0006f1ad\n"
        "movl 0xc(%edi), %eax\n" /* line 2491 | ps */
        "andl $0xfffffffe, %eax\n"
        "orl $2, %eax\n"
        "movl %eax, 0xc(%edi)\n" /* ps */
        "jmp .Lf6e7f6_0006e898\n"
        ".Lf6e7f6_0006f1ad:\n"
        "testb $0x20, 9(%esi)\n" /* line 2496 | pm */
        "jne .Lf6e7f6_0006e898\n"
        "movl %edi, 8(%esp)\n" /* line 2497 | ps */
        "movl $1, 4(%esp)\n"
        "movl $0x8e, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf6e7f6_0006e898\n"
        ".Lf6e7f6_0006f1d4:\n"
        "movl $0, 0xc(%esp)\n" /* line 2509 */
        "movl $0, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "andl $0xfffffffd, 0xc(%edi)\n" /* line 2512 | ps */
        "jmp .Lf6e7f6_0006e898\n"
        ".Lf6e7f6_0006f1fd:\n"
        "movl %edi, 8(%esp)\n" /* line 2430 | ps */
        "movl $0, 4(%esp)\n"
        "movl $0x8c, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "jmp .Lf6e7f6_0006e898\n"
    );
}

/* line 2659 */
__attribute__((naked))
void PM_FootstepEvent(pmove_t *pm, pml_t *pml, int iOldBobCycle, int iNewBobCycle, qboolean bFootStep)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2659 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pm */
        /* { scope 1: iClipMask, mins, maxs, vEnd, ... */
        "movl (%esi), %ebx\n" /* line 2663 | pm, ps */
        "movzbl 0x10(%ebp), %edx\n" /* line 2667 | iOldBobCycle */
        "addb $0x40, %dl\n"
        "movzbl 0x14(%ebp), %eax\n" /* iNewBobCycle */
        "addb $0x40, %al\n"
        "xorb %al, %dl\n"
        "jns .Lf6f21a_0006f271\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 2669 | ps */
        "je .Lf6f21a_0006f27c\n"
        "movl 0x18(%ebp), %eax\n" /* line 2711 | bFootStep */
        "testl %eax, %eax\n"
        "je .Lf6f21a_0006f271\n"
        /* { scope 2: passEntityNum */
        "movl 0xc(%ebp), %edx\n" /* line 822 | pml */
        "movl 0x48(%edx), %eax\n"
        "testb $0x20, %ah\n"
        "je .Lf6f21a_0006f460\n"
        ".Lf6f21a_0006f25b:\n"
        "xorl %eax, %eax\n" /* line 1329 */
        /* } scope */
        /* { scope 2: passEntityNum */
        ".Lf6f21a_0006f25d:\n"
        "movl %ebx, 8(%esp)\n" /* line 285 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        /* } scope */
        /* } scope */
        ".Lf6f21a_0006f271:\n"
        "addl $0x8c, %esp\n" /* line 2715 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iClipMask, mins, maxs, vEnd, ... */
        ".Lf6f21a_0006f27c:\n"
        "movl 0x18(%ebp), %eax\n" /* line 2671 | bFootStep */
        "testl %eax, %eax\n"
        "je .Lf6f21a_0006f271\n"
        "testb $0x20, 0xc(%ebx)\n" /* ps */
        "je .Lf6f21a_0006f271\n"
        /* { scope 2: passEntityNum */
        "movss 0xc8(%esi), %xmm1\n" /* line 200 */
        "movss lit4_002ed5e0, %xmm4\n" /* line 2682 | 6.0f */
        "movss 0xc4(%esi), %xmm0\n" /* pm */
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* mins */
        "addss %xmm4, %xmm1\n" /* line 2683 */
        "movss %xmm1, -0x20(%ebp)\n"
        "movss lit4_002ed740, %xmm3\n" /* line 2684 | 8.0f */
        "movss %xmm3, -0x1c(%ebp)\n"
        "leal 0xd0(%esi), %eax\n" /* pm */
        /* { scope 3: entityNum */
        "movss 0xd0(%esi), %xmm0\n" /* line 199 */
        "movss 4(%eax), %xmm2\n" /* line 200 */
        "movss 8(%eax), %xmm1\n" /* line 201 */
        /* } scope */
        "subss %xmm4, %xmm0\n" /* line 2686 */
        "movss %xmm0, -0x30(%ebp)\n" /* maxs */
        "subss %xmm4, %xmm2\n" /* line 2687 */
        "movss %xmm2, -0x2c(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 2690 */
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm0\n"
        "andnps %xmm3, %xmm1\n"
        "orps %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movl 0x3c(%esi), %eax\n" /* line 2696 | pm */
        "andl $0xfdfeffff, %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* iClipMask */
        "leal 0x14(%ebx), %edx\n" /* line 2699 | ps */
        "movl %edx, -0x78(%ebp)\n"
        "leal 0x64(%ebx), %eax\n" /* ps, dir */
        /* { scope 3: entityNum */
        "movss lit4_002ed744, %xmm1\n" /* line 288 | -31.0f */
        "movss 0x64(%ebx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x14(%ebx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* vEnd */
        "movss 4(%eax), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        /* } scope */
        "movl 0xcc(%ebx), %eax\n" /* line 2701 | ps */
        "movl %eax, -0x70(%ebp)\n" /* passEntityNum */
        /* { scope 3: entityNum */
        "movzbl 0xe4(%esi), %eax\n" /* line 262 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x74(%ebp), %edx\n" /* iClipMask */
        "movl %edx, 0x18(%esp)\n"
        "movl -0x70(%ebp), %edx\n" /* passEntityNum */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* maxs */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* mins */
        "movl %edx, 8(%esp)\n"
        "movl -0x78(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 264 */
        "je .Lf6f21a_0006f438\n"
        "testb $2, -0x49(%ebp)\n" /* line 268 */
        "je .Lf6f21a_0006f438\n"
        "movl -0x44(%ebp), %eax\n" /* line 271 */
        "movzwl %ax, %edx\n"
        "movl %edx, -0x6c(%ebp)\n" /* entityNum */
        /* { scope 4 */
        /* { scope 5 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf6f21a_0006f3f0\n"
        "movl 0x40(%esi), %edi\n" /* line 303 */
        "cmpl $0x20, %edi\n"
        "je .Lf6f21a_0006f3f0\n"
        "testl %edi, %edi\n" /* line 309 */
        "jle .Lf6f21a_0006f4b1\n"
        "movl -0x6c(%ebp), %eax\n" /* line 311 | entityNum */
        "cmpl %eax, 0x44(%esi)\n"
        "je .Lf6f21a_0006f3f0\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf6f21a_0006f3da:\n"
        "addl $1, %edx\n" /* line 309 */
        "cmpl %edx, %edi\n"
        "je .Lf6f21a_0006f4b1\n"
        "movl 0x48(%ecx), %eax\n" /* line 311 */
        "addl $4, %ecx\n"
        "cmpl -0x6c(%ebp), %eax\n" /* entityNum */
        "jne .Lf6f21a_0006f3da\n"
        /* } scope */
        /* } scope */
        ".Lf6f21a_0006f3f0:\n"
        "andl $0xfdffffff, 0x3c(%esi)\n" /* line 272 */
        "movzbl 0xe4(%esi), %eax\n" /* line 273 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x74(%ebp), %edx\n" /* iClipMask */
        "movl %edx, 0x18(%esp)\n"
        "movl -0x70(%ebp), %edx\n" /* passEntityNum */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* maxs */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* mins */
        "movl %edx, 8(%esp)\n"
        "movl -0x78(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        /* } scope */
        ".Lf6f21a_0006f438:\n"
        "movl -0x50(%ebp), %eax\n" /* line 2702 */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "movzbl %al, %edx\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 2703 | 1.0f */
        "ucomiss -0x60(%ebp), %xmm0\n" /* trace */
        "jp .Lf6f21a_0006f493\n"
        "jne .Lf6f21a_0006f493\n"
        "movl $0x16, %eax\n"
        "jmp .Lf6f21a_0006f25d\n"
        /* } scope */
        /* { scope 2: passEntityNum */
        ".Lf6f21a_0006f460:\n"
        "andl $0x1f00000, %eax\n" /* line 825 */
        "shrl $0x14, %eax\n"
        "movzbl %al, %edx\n"
        "testb %al, %al\n" /* line 1320 */
        "je .Lf6f21a_0006f25b\n"
        "movl 0xc(%ebx), %eax\n" /* line 1323 */
        "testb $1, %al\n" /* line 1324 */
        "jne .Lf6f21a_0006f4a1\n"
        "testb $1, %ah\n" /* line 1326 */
        "jne .Lf6f21a_0006f4a9\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss 0x4c(%ebx), %xmm0\n"
        "jp .Lf6f21a_0006f4a9\n"
        "jne .Lf6f21a_0006f4a9\n"
        ".Lf6f21a_0006f48b:\n"
        "leal 1(%edx), %eax\n" /* line 1329 */
        "jmp .Lf6f21a_0006f25d\n"
        /* } scope */
        /* { scope 2: passEntityNum */
        ".Lf6f21a_0006f493:\n"
        "testb %al, %al\n" /* line 2703 */
        "jne .Lf6f21a_0006f48b\n"
        "movl $0x16, %eax\n"
        "jmp .Lf6f21a_0006f25d\n"
        /* } scope */
        /* { scope 2: passEntityNum */
        ".Lf6f21a_0006f4a1:\n"
        "leal 0x2f(%edx), %eax\n" /* line 1325 */
        "jmp .Lf6f21a_0006f25d\n"
        ".Lf6f21a_0006f4a9:\n"
        "leal 0x18(%edx), %eax\n" /* line 1327 */
        "jmp .Lf6f21a_0006f25d\n"
        /* } scope */
        /* { scope 2: passEntityNum */
        /* { scope 3: entityNum */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf6f21a_0006f4b1:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 318 | entityNum */
        "movl %eax, 0x44(%esi, %edi, 4)\n"
        "addl $1, %edi\n" /* line 319 */
        "movl %edi, 0x40(%esi)\n"
        "jmp .Lf6f21a_0006f3f0\n"
    );
}

/* line 2806 */
static __attribute__((naked))
void PM_Footsteps(pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2806 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %esi\n" /* pm */
        "movl %edx, -0x38(%ebp)\n"
        /* { scope 1 */
        "movl (%eax), %ebx\n" /* line 2826 | ps */
        "cmpl $5, 4(%ebx)\n" /* line 2840 | ps */
        "jg .Lf6f4c4_0006f574\n"
        "movl 0xcc(%ebx), %ecx\n" /* line 2844 | ps */
        "cmpl $0x3f, %ecx\n"
        "jle .Lf6f4c4_0006f57c\n"
        "movl $0, -0x24(%ebp)\n" /* ci */
        ".Lf6f4c4_0006f4f4:\n"
        "movl imp_player_dmgtimer_stumbleTime, %eax\n" /* line 2861 */
        "movl (%eax), %edx\n"
        "movl 0x94(%ebx), %eax\n" /* ps */
        "subl 8(%edx), %eax\n" /* line 2863 */
        "movl %eax, -0x28(%ebp)\n" /* stumble_end_time */
        "movl $0, %eax\n"
        "cmovnsl -0x28(%ebp), %eax\n" /* stumble_end_time */
        "movl %eax, -0x28(%ebp)\n" /* stumble_end_time */
        "movss 0x20(%ebx), %xmm1\n" /* line 2879 | ps */
        "movss 0x24(%ebx), %xmm0\n" /* ps */
        "mulss %xmm1, %xmm1\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "movss %xmm1, 0xdc(%esi)\n"
        "testl $0x300, 0xa0(%ebx)\n" /* line 2882 | ps */
        "je .Lf6f4c4_0006f5a0\n"
        "movl 0xc(%ebx), %eax\n" /* line 2885 | ps */
        "testb $1, %al\n"
        "jne .Lf6f4c4_0006fb35\n"
        "testb $2, %al\n" /* line 2887 */
        "jne .Lf6f4c4_0006f98a\n"
        ".Lf6f4c4_0006f554:\n"
        "movl $1, 0xc(%esp)\n" /* line 3288 */
        "movl $1, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        /* } scope */
        ".Lf6f4c4_0006f574:\n"
        "addl $0x5c, %esp\n" /* line 3301 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6f4c4_0006f57c:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 2845 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl imp_bgs, %edx\n"
        "movl (%edx), %edx\n"
        "leal 0xb3bfc(%edx, %eax, 8), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* ci */
        "jmp .Lf6f4c4_0006f4f4\n"
        ".Lf6f4c4_0006f5a0:\n"
        "movl 0xf4(%ebx), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "je .Lf6f4c4_0006fb5d\n"
        "cmpl $0xb, %eax\n" /* line 353 */
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* iStance */
        ".Lf6f4c4_0006f5bb:\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 2902 | ps */
        "je .Lf6f4c4_0006f9b2\n"
        ".Lf6f4c4_0006f5c8:\n"
        "movl 0xc(%ebx), %edi\n" /* ps, footstep */
        ".Lf6f4c4_0006f5cb:\n"
        "testl $0x100, %edi\n" /* line 2936 | footstep */
        "jne .Lf6f4c4_0006f5e5\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss 0x4c(%ebx), %xmm0\n" /* ps */
        "jne .Lf6f4c4_0006f5e5\n"
        "jp .Lf6f4c4_0006f5e5\n"
        "movb $0, -0x31(%ebp)\n"
        "jmp .Lf6f4c4_0006f5e9\n"
        ".Lf6f4c4_0006f5e5:\n"
        "movb $1, -0x31(%ebp)\n"
        ".Lf6f4c4_0006f5e9:\n"
        "movss 0xdc(%esi), %xmm1\n" /* line 2939 | pm */
        "movl imp_player_moveThreshhold, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf6f4c4_0006f895\n"
        "cmpl $1, 4(%ebx)\n" /* ps */
        "je .Lf6f4c4_0006f895\n"
        "cvtsi2ssl 0x50(%ebx), %xmm2\n" /* line 3087 | ps */
        "movzbl 0x1c(%esi), %edx\n" /* line 3088 | pm */
        "testb %dl, %dl\n"
        "je .Lf6f4c4_0006fb69\n"
        "cmpb $0, 0x1d(%esi)\n" /* line 3090 | pm */
        "je .Lf6f4c4_0006fc6e\n"
        "movl imp_player_strafeSpeedScale, %eax\n" /* line 3092 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss lit4_002ed67c, %xmm0\n" /* 0.75f */
        "addss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "testb %dl, %dl\n" /* line 3093 */
        "js .Lf6f4c4_00070257\n"
        ".Lf6f4c4_0006f66b:\n"
        "movl $1, 0xc(%esp)\n" /* line 3100 */
        "movl $0, 8(%esp)\n"
        ".Lf6f4c4_0006f67b:\n"
        "movl $8, 4(%esp)\n" /* line 3111 */
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x48(%ebp)\n"
        "calll BG_UpdateConditionValue\n"
        "movl 0xc(%ebx), %edi\n" /* ps, footstep */
        "movss 0xdc(%esi), %xmm1\n" /* pm */
        "movss -0x48(%ebp), %xmm2\n"
        ".Lf6f4c4_0006f6a6:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 3115 */
        "je .Lf6f4c4_0006f6b4\n"
        "mulss lit4_002ed71c, %xmm2\n" /* line 3116 | 0.4000000059604645f */
        /* { scope 2 */
        ".Lf6f4c4_0006f6b4:\n"
        "movl (%esi), %eax\n" /* line 1903 */
        "movl 0xfc(%eax), %ecx\n" /* line 1906 */
        "testl %ecx, %ecx\n"
        "je .Lf6f4c4_0006fbb6\n"
        "movl 0x100(%eax), %edx\n" /* line 1910 */
        "cmpl $0xb, %edx\n"
        "je .Lf6f4c4_0006fce9\n"
        /* } scope */
        "cmpl $0x28, %edx\n"
        "jne .Lf6f4c4_0006fbb6\n"
        "movl 0x104(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf6f4c4_0006fbb6\n"
        "movl 4(%esi), %eax\n" /* line 1921 */
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss lit4_002ed730, %xmm0\n" /* 400.0f */
        "pxor %xmm5, %xmm5\n" /* line 1922 */
        "ucomiss %xmm0, %xmm5\n"
        "ja .Lf6f4c4_0006fbb6\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 1924 | 1.0f */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf6f4c4_00070331\n"
        "movss lit4_002ed768, %xmm4\n" /* 0.6499999761581421f */
        "movaps %xmm5, %xmm3\n"
        ".Lf6f4c4_0006f724:\n"
        "mulss lit4_002ed764, %xmm3\n" /* line 3124 | 0.15000000596046448f */
        "addss %xmm3, %xmm4\n"
        "mulss %xmm4, %xmm2\n"
        ".Lf6f4c4_0006f734:\n"
        "cmpl $1, -0x2c(%ebp)\n" /* line 3130 | iStance */
        "je .Lf6f4c4_0006fdb2\n"
        "cmpl $2, -0x2c(%ebp)\n" /* line 3144 | iStance */
        "jne .Lf6f4c4_0006fbca\n"
        ".Lf6f4c4_0006f748:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 3146 */
        "je .Lf6f4c4_00070067\n"
        "divss %xmm2, %xmm1\n" /* line 3147 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed770, %xmm0\n" /* 0.3149999976158142f */
        "movss %xmm0, -0x1c(%ebp)\n"
        ".Lf6f4c4_0006f766:\n"
        "movl %edi, %eax\n" /* line 3152 | footstep */
        "testb %al, %al\n"
        "jns .Lf6f4c4_00070026\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 3154 */
        "je .Lf6f4c4_000701f1\n"
        "movl -0x28(%ebp), %edx\n" /* line 3157 | stumble_end_time */
        "cmpl 0x90(%ebx), %edx\n" /* ps */
        "jl .Lf6f4c4_000701a1\n"
        "movl $1, 0xc(%esp)\n" /* line 3161 */
        "movl $7, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        /* { scope 2 */
        ".Lf6f4c4_0006f7ac:\n"
        "movl (%esi), %eax\n" /* line 2729 */
        "movl 0xc(%eax), %edx\n" /* line 2732 */
        "movl %edx, %ecx\n"
        "andl $0x100, %ecx\n"
        /* { scope 3 */
        "movl 0xf4(%eax), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "je .Lf6f4c4_0006fd4b\n"
        "cmpl $0xb, %eax\n" /* line 353 */
        "je .Lf6f4c4_0006fd4b\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 2759 */
        "jne .Lf6f4c4_0006fd4b\n"
        "movl imp_player_footstepsThreshhold, %eax\n" /* line 2760 */
        "movl (%eax), %eax\n"
        "movss 0xdc(%esi), %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "setae %al\n"
        "movzbl %al, %edi\n"
        /* } scope */
        ".Lf6f4c4_0006f7f2:\n"
        "movl 8(%ebx), %edx\n" /* line 3265 | ps */
        "movl %edx, -0x30(%ebp)\n" /* old */
        "cvtsi2ssl %edx, %xmm0\n" /* line 3267 */
        "movl -0x38(%ebp), %eax\n"
        "cvtsi2ssl 0x28(%eax), %xmm1\n"
        "mulss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "addss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, 8(%ebx)\n" /* ps */
        "cmpw $0, 0x1c(%esi)\n" /* line 3270 | pm */
        "jne .Lf6f4c4_0006fd52\n"
        "movss 0xdc(%esi), %xmm0\n" /* line 3273 | pm */
        "ucomiss lit4_002ed788, %xmm0\n" /* 120.0f */
        "ja .Lf6f4c4_0006f574\n"
        "movl 0xf4(%ebx), %eax\n" /* line 3276 | ps */
        "cmpl $0xb, %eax\n"
        "je .Lf6f4c4_000702ad\n"
        "cmpl $0x28, %eax\n" /* line 3278 */
        "je .Lf6f4c4_000702ea\n"
        ".Lf6f4c4_0006f856:\n"
        "movl -0x20(%ebp), %eax\n" /* line 3281 | animResult */
        "testl %eax, %eax\n"
        "jns .Lf6f4c4_0006f574\n"
        ".Lf6f4c4_0006f861:\n"
        "movl -0x28(%ebp), %edx\n" /* line 3284 | stumble_end_time */
        "cmpl 0x90(%ebx), %edx\n" /* ps */
        "jge .Lf6f4c4_0006f554\n"
        "movl $1, 0xc(%esp)\n" /* line 3285 */
        "movl $0x1f, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "jmp .Lf6f4c4_0006f574\n"
        ".Lf6f4c4_0006f895:\n"
        "ucomiss lit4_002ed5d0, %xmm1\n" /* line 2941 | 1.0f */
        "jb .Lf6f4c4_0006fc29\n"
        ".Lf6f4c4_0006f8a2:\n"
        "movl -0x24(%ebp), %edi\n" /* line 2947 | ci, footstep */
        "testl %edi, %edi\n" /* footstep */
        "je .Lf6f4c4_0006fa9f\n"
        "movl imp_player_turnAnims, %eax\n" /* line 2949 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf6f4c4_0006fa9f\n"
        "movl -0x24(%ebp), %esi\n" /* line 2951 | ci, pm */
        "cmpb $0, 0x4b4(%esi)\n" /* pm */
        "je .Lf6f4c4_0006fc3b\n"
        "movl 0x4b0(%esi), %ecx\n" /* pm */
        "testl %ecx, %ecx\n"
        "jne .Lf6f4c4_00070080\n"
        "movl -0x24(%ebp), %edx\n" /* ci */
        ".Lf6f4c4_0006f8df:\n"
        "movl 0x384(%edx), %esi\n" /* line 2953 | pm */
        "testl %esi, %esi\n" /* pm */
        "je .Lf6f4c4_0006fd83\n"
        "movss 0x3b0(%edx), %xmm1\n" /* line 2955 */
        "movss 0x380(%edx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf6f4c4_0006fe4c\n"
        "movl $0xe, %edx\n"
        "movl $0xe, %eax\n"
        ".Lf6f4c4_0006f910:\n"
        "movl -0x24(%ebp), %esi\n" /* line 2960 | ci, pm */
        "movss %xmm1, 0x380(%esi)\n" /* pm */
        "movb %al, 0x4b4(%esi)\n" /* line 2962 | pm */
        "movl imp_bgs, %eax\n" /* line 2963 */
        "movl (%eax), %eax\n"
        "cmpl 0xb3bdc(%eax), %ecx\n"
        "jge .Lf6f4c4_0006faa1\n"
        "movl $0, 0x4b0(%esi)\n" /* line 2969 | pm */
        "jmp .Lf6f4c4_0006faa1\n"
        ".Lf6f4c4_0006f943:\n"
        "cmpl $0xe, %edx\n" /* line 2997 */
        "je .Lf6f4c4_00070114\n"
        "cmpl $0xf, %edx\n" /* line 3010 */
        "je .Lf6f4c4_000700af\n"
        "movl $1, 0xc(%esp)\n" /* line 3025 */
        "movl $2, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        ".Lf6f4c4_0006f975:\n"
        "testl %eax, %eax\n" /* line 3070 */
        "jns .Lf6f4c4_0006f574\n"
        "cmpl $0x28, 0xf4(%ebx)\n" /* line 3072 | ps */
        "jne .Lf6f4c4_0006f861\n"
        ".Lf6f4c4_0006f98a:\n"
        "movl $1, 0xc(%esp)\n" /* line 3073 */
        "movl $2, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 3301 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6f4c4_0006f9b2:\n"
        "cmpl $1, 4(%ebx)\n" /* line 2902 | ps */
        "je .Lf6f4c4_0006f5c8\n"
        "movl 0xc(%ebx), %edi\n" /* line 2904 | ps, footstep */
        "testl $0x20, %edi\n" /* footstep */
        "je .Lf6f4c4_0006fa8c\n"
        /* { scope 2 */
        "movl 4(%esi), %eax\n" /* line 2909 | pm */
        "subl 0x70(%ebx), %eax\n" /* ps */
        "cmpl $0x12b, %eax\n"
        "jle .Lf6f4c4_0006f574\n"
        "movss 0x28(%ebx), %xmm0\n" /* line 2912 | ps */
        "andl $0x100, %edi\n" /* line 2915 | footstep */
        "jne .Lf6f4c4_0006fe83\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss 0x4c(%ebx), %xmm1\n" /* ps */
        "jp .Lf6f4c4_0006fe87\n"
        "jne .Lf6f4c4_0006fe87\n"
        "movaps %xmm0, %xmm2\n" /* line 2918 */
        "divss lit4_002ed750, %xmm2\n" /* 95.25f */
        "mulss lit4_002ed754, %xmm2\n" /* 0.44999998807907104f */
        ".Lf6f4c4_0006fa14:\n"
        "ucomiss %xmm1, %xmm0\n" /* line 2921 */
        "jb .Lf6f4c4_000702d5\n"
        "movl $1, 0xc(%esp)\n" /* line 2922 */
        "movl $0x12, 8(%esp)\n"
        ".Lf6f4c4_0006fa2d:\n"
        "movl $3, 4(%esp)\n" /* line 2924 */
        "movl %ebx, (%esp)\n" /* ps */
        "movss %xmm2, -0x48(%ebp)\n"
        "calll BG_AnimScriptAnimation\n"
        "movss -0x48(%ebp), %xmm2\n"
        "movl 8(%ebx), %edx\n" /* line 2927 | ps */
        "cvtsi2ssl %edx, %xmm0\n" /* line 2928 */
        "movl -0x38(%ebp), %eax\n"
        "cvtsi2ssl 0x28(%eax), %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, 8(%ebx)\n" /* ps */
        "movl $1, 0x10(%esp)\n" /* line 2929 */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pm */
        "calll PM_FootstepEvent\n"
        "movl 0xc(%ebx), %edi\n" /* ps, footstep */
        /* } scope */
        ".Lf6f4c4_0006fa8c:\n"
        "movl %edi, %eax\n" /* line 2932 | footstep */
        "andl $3, %eax\n"
        "cmpl %eax, -0x2c(%ebp)\n" /* iStance */
        "jne .Lf6f4c4_0006f5cb\n"
        "jmp .Lf6f4c4_0006f574\n"
        ".Lf6f4c4_0006fa9f:\n"
        "xorl %edx, %edx\n" /* line 2982 */
        ".Lf6f4c4_0006faa1:\n"
        "movl 0xf4(%ebx), %eax\n" /* line 2991 | ps */
        "cmpl $0xb, %eax\n"
        "je .Lf6f4c4_0006fe02\n"
        "cmpl $0x28, %eax\n" /* line 2995 */
        "je .Lf6f4c4_0006f943\n"
        "cmpl $0xe, %edx\n" /* line 3030 */
        "je .Lf6f4c4_0006fe9f\n"
        "cmpl $0xf, %edx\n" /* line 3043 */
        "je .Lf6f4c4_0006ff39\n"
        "movl -0x28(%ebp), %eax\n" /* line 3057 | stumble_end_time */
        "cmpl 0x90(%ebx), %eax\n" /* ps */
        "jge .Lf6f4c4_0006fe27\n"
        "cvtsi2ssl 0x98(%ebx), %xmm0\n" /* line 3059 | ps, flinch_angle */
        /* { scope 2 */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 2782 | 0.0f */
        "jb .Lf6f4c4_0006fd38\n"
        ".Lf6f4c4_0006faef:\n"
        "ucomiss lit4_002ed758, %xmm0\n" /* line 2786 | 315.0f */
        "jae .Lf6f4c4_0006fc48\n"
        "ucomiss lit4_002ed6ec, %xmm0\n" /* 45.0f */
        "jp .Lf6f4c4_0006fb0b\n"
        "jb .Lf6f4c4_0006fc48\n"
        ".Lf6f4c4_0006fb0b:\n"
        "ucomiss lit4_002ed6ec, %xmm0\n" /* line 2788 | 45.0f */
        "jb .Lf6f4c4_000700c4\n"
        "ucomiss lit4_002ed75c, %xmm0\n" /* 135.0f */
        "jae .Lf6f4c4_000700c4\n"
        "jp .Lf6f4c4_000700c4\n"
        "movl $0x21, %eax\n"
        "jmp .Lf6f4c4_0006fc4d\n"
        /* } scope */
        ".Lf6f4c4_0006fb35:\n"
        "movl $1, 0xc(%esp)\n" /* line 2886 */
        "movl $3, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 3301 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6f4c4_0006fb5d:\n"
        "movl $2, -0x2c(%ebp)\n" /* line 350 | iStance */
        "jmp .Lf6f4c4_0006f5bb\n"
        ".Lf6f4c4_0006fb69:\n"
        "cmpb $0, 0x1d(%esi)\n" /* line 3103 | pm */
        "je .Lf6f4c4_0006f6a6\n"
        "movl imp_player_strafeSpeedScale, %eax\n" /* line 3105 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss lit4_002ed67c, %xmm0\n" /* 0.75f */
        "addss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "jle .Lf6f4c4_00070273\n" /* line 3108 */
        "movl $1, 0xc(%esp)\n" /* line 3109 */
        "movl $2, 8(%esp)\n"
        "jmp .Lf6f4c4_0006f67b\n"
        ".Lf6f4c4_0006fbb6:\n"
        "cmpl $1, -0x2c(%ebp)\n" /* line 3125 | iStance */
        "je .Lf6f4c4_0006fdaa\n"
        "cmpl $2, -0x2c(%ebp)\n" /* line 3127 | iStance */
        "je .Lf6f4c4_0006fcdc\n"
        ".Lf6f4c4_0006fbca:\n"
        "movl %edi, %edx\n" /* line 3196 | footstep */
        "testb %dl, %dl\n"
        "js .Lf6f4c4_0006fc87\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 3234 */
        "je .Lf6f4c4_0006ff90\n"
        "divss %xmm2, %xmm1\n" /* line 3237 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed780, %xmm0\n" /* 0.3050000071525574f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 3241 | stumble_end_time */
        "cmpl 0x90(%ebx), %eax\n" /* ps */
        "jge .Lf6f4c4_000700ec\n"
        "movl $1, 0xc(%esp)\n" /* line 3242 */
        "movl $0x25, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_0006fc29:\n"
        "jp .Lf6f4c4_0006f8a2\n" /* line 2941 */
        "movl $0, 8(%ebx)\n" /* line 2942 | ps */
        "jmp .Lf6f4c4_0006f8a2\n"
        ".Lf6f4c4_0006fc3b:\n"
        "movl 0x4b0(%esi), %ecx\n" /* pm */
        "movl %esi, %edx\n" /* pm */
        "jmp .Lf6f4c4_0006f8df\n"
        /* { scope 2 */
        ".Lf6f4c4_0006fc48:\n"
        "movl $0x1f, %eax\n" /* line 2790 */
        /* } scope */
        ".Lf6f4c4_0006fc4d:\n"
        "movl $1, 0xc(%esp)\n" /* line 3060 */
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "jmp .Lf6f4c4_0006f574\n"
        ".Lf6f4c4_0006fc6e:\n"
        "testb %dl, %dl\n" /* line 3096 */
        "jns .Lf6f4c4_0006f66b\n"
        "movl imp_player_backSpeedScale, %eax\n" /* line 3097 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm2\n"
        "jmp .Lf6f4c4_0006f66b\n"
        ".Lf6f4c4_0006fc87:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 3201 */
        "je .Lf6f4c4_0006ffdb\n"
        "divss %xmm2, %xmm1\n" /* line 3204 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed778, %xmm0\n" /* 0.32499998807907104f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 3208 | stumble_end_time */
        "cmpl 0x90(%ebx), %eax\n" /* ps */
        "jge .Lf6f4c4_00070151\n"
        "movl $1, 0xc(%esp)\n" /* line 3209 */
        "movl $0x26, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_0006fcdc:\n"
        "mulss lit4_002ed768, %xmm2\n" /* line 3128 | 0.6499999761581421f */
        "jmp .Lf6f4c4_0006f748\n"
        /* { scope 2 */
        ".Lf6f4c4_0006fce9:\n"
        "movl 4(%esi), %eax\n" /* line 1921 */
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss lit4_002ed730, %xmm0\n" /* 400.0f */
        "pxor %xmm5, %xmm5\n" /* line 1922 */
        "ucomiss %xmm0, %xmm5\n"
        "ja .Lf6f4c4_0006fbb6\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 1924 | 1.0f */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf6f4c4_00070312\n"
        "movss lit4_002ed764, %xmm4\n" /* 0.15000000596046448f */
        "movaps %xmm5, %xmm3\n"
        /* } scope */
        ".Lf6f4c4_0006fd23:\n"
        "mulss lit4_002ed768, %xmm3\n" /* line 3122 | 0.6499999761581421f */
        "addss %xmm3, %xmm4\n"
        "mulss %xmm4, %xmm2\n"
        "jmp .Lf6f4c4_0006f734\n"
        /* { scope 2 */
        ".Lf6f4c4_0006fd38:\n"
        "jp .Lf6f4c4_0006faef\n" /* line 2782 */
        "addss lit4_002ed638, %xmm0\n" /* line 2783 | 360.0f */
        "jmp .Lf6f4c4_0006faef\n"
        /* } scope */
        /* { scope 2 */
        ".Lf6f4c4_0006fd4b:\n"
        "xorl %edi, %edi\n" /* line 2760 */
        "jmp .Lf6f4c4_0006f7f2\n"
        /* } scope */
        ".Lf6f4c4_0006fd52:\n"
        "movl -0x20(%ebp), %eax\n" /* line 3296 | animResult */
        "testl %eax, %eax\n"
        "js .Lf6f4c4_00070288\n"
        ".Lf6f4c4_0006fd5d:\n"
        "movl %edi, 0x10(%esp)\n" /* line 3300 | footstep */
        "movl 8(%ebx), %eax\n" /* ps */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* old */
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pm */
        "calll PM_FootstepEvent\n"
        "jmp .Lf6f4c4_0006f574\n"
        ".Lf6f4c4_0006fd83:\n"
        "movl imp_bgs, %eax\n" /* line 2972 */
        "movl (%eax), %eax\n"
        "cmpl 0xb3bdc(%eax), %ecx\n"
        "jle .Lf6f4c4_0006fe5b\n"
        "movl -0x24(%ebp), %edx\n" /* line 2975 | ci */
        "movl 0x3b0(%edx), %eax\n"
        "movl %eax, 0x380(%edx)\n"
        "jmp .Lf6f4c4_0006f574\n"
        ".Lf6f4c4_0006fdaa:\n"
        "mulss lit4_002ed764, %xmm2\n" /* line 3126 | 0.15000000596046448f */
        ".Lf6f4c4_0006fdb2:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 3132 */
        "je .Lf6f4c4_0006ff20\n"
        "divss %xmm2, %xmm1\n" /* line 3133 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed76c, %xmm0\n" /* 0.23999999463558197f */
        "movss %xmm0, -0x1c(%ebp)\n"
        ".Lf6f4c4_0006fdd0:\n"
        "movl %edi, %eax\n" /* line 3138 | footstep */
        "testb %al, %al\n"
        "jns .Lf6f4c4_0006fef8\n"
        "movl $1, 0xc(%esp)\n" /* line 3139 */
        "movl $9, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_0006fe02:\n"
        "movl $1, 0xc(%esp)\n" /* line 2993 */
        "movl $3, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "jmp .Lf6f4c4_0006f975\n"
        ".Lf6f4c4_0006fe27:\n"
        "movl $1, 0xc(%esp)\n" /* line 3066 */
        "movl $1, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "jmp .Lf6f4c4_0006f975\n"
        ".Lf6f4c4_0006fe4c:\n"
        "movl $0xf, %edx\n" /* line 2955 */
        "movl $0xf, %eax\n"
        "jmp .Lf6f4c4_0006f910\n"
        ".Lf6f4c4_0006fe5b:\n"
        "testl %ecx, %ecx\n" /* line 2978 */
        "je .Lf6f4c4_0006fa9f\n"
        "movl -0x24(%ebp), %esi\n" /* line 2980 | ci, pm */
        "movl $0, 0x4b0(%esi)\n" /* pm */
        "movl 0x3b0(%esi), %eax\n" /* line 2982 | pm */
        "movl %eax, 0x380(%esi)\n" /* pm */
        "xorl %edx, %edx\n"
        "jmp .Lf6f4c4_0006faa1\n"
        ".Lf6f4c4_0006fe83:\n"
        "pxor %xmm1, %xmm1\n"
        /* { scope 2 */
        ".Lf6f4c4_0006fe87:\n"
        "movaps %xmm0, %xmm2\n" /* line 2916 */
        "divss lit4_002ed748, %xmm2\n" /* 38.10000228881836f */
        "mulss lit4_002ed74c, %xmm2\n" /* 0.3499999940395355f */
        "jmp .Lf6f4c4_0006fa14\n"
        /* } scope */
        ".Lf6f4c4_0006fe9f:\n"
        "movl $1, 0xc(%esp)\n" /* line 3032 */
        "movl $0xe, 8(%esp)\n"
        ".Lf6f4c4_0006feaf:\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "testl %eax, %eax\n" /* line 3033 */
        "jle .Lf6f4c4_0006f975\n"
        "movl -0x24(%ebp), %eax\n" /* ci */
        "movl 0x4b0(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf6f4c4_0006f574\n"
        "movl %eax, %edx\n"
        "movl imp_bgs, %eax\n" /* line 3036 */
        "movl (%eax), %eax\n"
        "movl 0xb3bdc(%eax), %eax\n"
        "addl 0x88(%ebx), %eax\n" /* ps */
        "movl %eax, 0x4b0(%edx)\n"
        "jmp .Lf6f4c4_0006f574\n"
        ".Lf6f4c4_0006fef8:\n"
        "movl $1, 0xc(%esp)\n" /* line 3141 */
        "movl $8, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_0006ff20:\n"
        "divss %xmm2, %xmm1\n" /* line 3135 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed604, %xmm0\n" /* 0.25f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "jmp .Lf6f4c4_0006fdd0\n"
        ".Lf6f4c4_0006ff39:\n"
        "movl $1, 0xc(%esp)\n" /* line 3045 */
        "movl $0xf, 8(%esp)\n"
        ".Lf6f4c4_0006ff49:\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "testl %eax, %eax\n" /* line 3046 */
        "jle .Lf6f4c4_0006f975\n"
        "movl -0x24(%ebp), %esi\n" /* ci, pm */
        "movl 0x4b0(%esi), %edx\n" /* pm */
        "testl %edx, %edx\n"
        "jne .Lf6f4c4_0006f574\n"
        "movl imp_bgs, %eax\n" /* line 3049 */
        "movl (%eax), %eax\n"
        "movl 0xb3bdc(%eax), %eax\n"
        "addl 0x88(%ebx), %eax\n" /* ps */
        "movl %eax, 0x4b0(%esi)\n" /* pm */
        "jmp .Lf6f4c4_0006f574\n"
        ".Lf6f4c4_0006ff90:\n"
        "divss %xmm2, %xmm1\n" /* line 3250 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed784, %xmm0\n" /* 0.33500000834465027f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 3254 | stumble_end_time */
        "cmpl 0x90(%ebx), %eax\n" /* ps */
        "jge .Lf6f4c4_00070179\n"
        "movl $1, 0xc(%esp)\n" /* line 3255 */
        "movl $0x23, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_0006ffdb:\n"
        "divss %xmm2, %xmm1\n" /* line 3217 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed77c, %xmm0\n" /* 0.36000001430511475f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 3221 | stumble_end_time */
        "cmpl 0x90(%ebx), %eax\n" /* ps */
        "jge .Lf6f4c4_00070129\n"
        "movl $1, 0xc(%esp)\n" /* line 3222 */
        "movl $0x24, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_00070026:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 3175 */
        "je .Lf6f4c4_00070224\n"
        "movl -0x28(%ebp), %edx\n" /* line 3178 | stumble_end_time */
        "cmpl 0x90(%ebx), %edx\n" /* ps */
        "jl .Lf6f4c4_000701c9\n"
        "movl $1, 0xc(%esp)\n" /* line 3182 */
        "movl $6, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_00070067:\n"
        "divss %xmm2, %xmm1\n" /* line 3149 */
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed774, %xmm0\n" /* 0.3400000035762787f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "jmp .Lf6f4c4_0006f766\n"
        ".Lf6f4c4_00070080:\n"
        "movl imp_bgs, %eax\n" /* line 2952 */
        "movl (%eax), %eax\n"
        "movl 0xb3bdc(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl $str_0021bef4, (%esp)\n" /* "turn anim end time is %i, time is %i
" */
        "calll Com_DPrintf\n"
        "movl 0x4b0(%esi), %ecx\n" /* pm */
        "movl -0x24(%ebp), %edx\n" /* ci */
        "jmp .Lf6f4c4_0006f8df\n"
        ".Lf6f4c4_000700af:\n"
        "movl $1, 0xc(%esp)\n" /* line 3012 */
        "movl $0x11, 8(%esp)\n"
        "jmp .Lf6f4c4_0006ff49\n"
        /* { scope 2 */
        ".Lf6f4c4_000700c4:\n"
        "ucomiss lit4_002ed75c, %xmm0\n" /* line 2790 | 135.0f */
        "jb .Lf6f4c4_000700e2\n"
        "ucomiss lit4_002ed760, %xmm0\n" /* 225.0f */
        "jae .Lf6f4c4_000700e2\n"
        "jp .Lf6f4c4_000700e2\n"
        "movl $0x20, %eax\n"
        "jmp .Lf6f4c4_0006fc4d\n"
        ".Lf6f4c4_000700e2:\n"
        "movl $0x22, %eax\n"
        "jmp .Lf6f4c4_0006fc4d\n"
        /* } scope */
        ".Lf6f4c4_000700ec:\n"
        "movl $1, 0xc(%esp)\n" /* line 3245 */
        "movl $4, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_00070114:\n"
        "movl $1, 0xc(%esp)\n" /* line 2999 */
        "movl $0x10, 8(%esp)\n"
        "jmp .Lf6f4c4_0006feaf\n"
        ".Lf6f4c4_00070129:\n"
        "movl $1, 0xc(%esp)\n" /* line 3225 */
        "movl $0xb, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_00070151:\n"
        "movl $1, 0xc(%esp)\n" /* line 3212 */
        "movl $5, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_00070179:\n"
        "movl $1, 0xc(%esp)\n" /* line 3258 */
        "movl $0xa, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_000701a1:\n"
        "movl $1, 0xc(%esp)\n" /* line 3167 */
        "movl $0x28, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_000701c9:\n"
        "movl $1, 0xc(%esp)\n" /* line 3188 */
        "movl $0x27, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_000701f1:\n"
        "movl -0x28(%ebp), %eax\n" /* line 3166 | stumble_end_time */
        "cmpl 0x90(%ebx), %eax\n" /* ps */
        "jl .Lf6f4c4_000701a1\n"
        "movl $1, 0xc(%esp)\n" /* line 3170 */
        "movl $0xd, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_00070224:\n"
        "movl -0x28(%ebp), %eax\n" /* line 3187 | stumble_end_time */
        "cmpl 0x90(%ebx), %eax\n" /* ps */
        "jl .Lf6f4c4_000701c9\n"
        "movl $1, 0xc(%esp)\n" /* line 3191 */
        "movl $0xc, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f7ac\n"
        ".Lf6f4c4_00070257:\n"
        "movl imp_player_backSpeedScale, %eax\n" /* line 3094 */
        "movl (%eax), %eax\n"
        "movaps %xmm1, %xmm0\n"
        "addss 8(%eax), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "jmp .Lf6f4c4_0006f66b\n"
        ".Lf6f4c4_00070273:\n"
        "movl $1, 0xc(%esp)\n" /* line 3111 */
        "movl $1, 8(%esp)\n"
        "jmp .Lf6f4c4_0006f67b\n"
        ".Lf6f4c4_00070288:\n"
        "movl $1, 0xc(%esp)\n" /* line 3297 */
        "movl $1, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "jmp .Lf6f4c4_0006fd5d\n"
        ".Lf6f4c4_000702ad:\n"
        "movl $1, 0xc(%esp)\n" /* line 3277 */
        "movl $3, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f856\n"
        /* { scope 2 */
        ".Lf6f4c4_000702d5:\n"
        "movl $1, 0xc(%esp)\n" /* line 2924 */
        "movl $0x13, 8(%esp)\n"
        "jmp .Lf6f4c4_0006fa2d\n"
        /* } scope */
        ".Lf6f4c4_000702ea:\n"
        "movl $1, 0xc(%esp)\n" /* line 3279 */
        "movl $2, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptAnimation\n"
        "movl %eax, -0x20(%ebp)\n" /* animResult */
        "jmp .Lf6f4c4_0006f856\n"
        ".Lf6f4c4_00070312:\n"
        "ucomiss %xmm5, %xmm0\n" /* line 3121 */
        "jp .Lf6f4c4_0007031d\n"
        "je .Lf6f4c4_0006fbb6\n"
        ".Lf6f4c4_0007031d:\n"
        "movaps %xmm0, %xmm4\n"
        "mulss lit4_002ed764, %xmm4\n" /* 0.15000000596046448f */
        "subss %xmm0, %xmm3\n"
        "jmp .Lf6f4c4_0006fd23\n"
        ".Lf6f4c4_00070331:\n"
        "ucomiss %xmm5, %xmm0\n" /* line 3123 */
        "jp .Lf6f4c4_0007033c\n"
        "je .Lf6f4c4_0006fbb6\n"
        ".Lf6f4c4_0007033c:\n"
        "movaps %xmm0, %xmm4\n"
        "mulss lit4_002ed768, %xmm4\n" /* 0.6499999761581421f */
        "subss %xmm0, %xmm3\n"
        "jmp .Lf6f4c4_0006f724\n"
    );
}

/* line 1679 */
static __attribute__((naked))
void PM_GroundTrace(pmove_t *pm, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1679 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl %eax, -0xb8(%ebp)\n"
        "movl %edx, -0xbc(%ebp)\n"
        /* { scope 1: passEntityNum, i, point, trace, ... */
        "movl (%eax), %eax\n" /* line 1688 */
        "movl %eax, -0xac(%ebp)\n" /* ps */
        "movl %eax, %edx\n" /* line 1691 */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* start */
        "movl 0x18(%edx), %eax\n" /* line 1692 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x14(%edx), %eax\n" /* line 1693 */
        "movl %eax, -0x30(%ebp)\n" /* point */
        "movl 0x18(%edx), %eax\n" /* line 1694 */
        "movl %eax, -0x2c(%ebp)\n"
        "testl $0x300, 0xa0(%edx)\n" /* line 1696 */
        "je .Lf70350_000708bf\n"
        "movl 0x1c(%edx), %eax\n" /* line 1698 */
        "movl %eax, -0x1c(%ebp)\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 1699 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x28(%ebp)\n"
        "movl -0xac(%ebp), %eax\n" /* ps */
        ".Lf70350_000703b8:\n"
        "movl -0xb8(%ebp), %esi\n" /* line 1710 | contentMask */
        "movl 0x3c(%esi), %ebx\n" /* contentMask */
        "movl 0xcc(%eax), %eax\n"
        "movl %eax, -0xa8(%ebp)\n" /* passEntityNum */
        "addl $0xd0, %esi\n" /* contentMask */
        "movl %esi, -0xb4(%ebp)\n" /* contentMask */
        "movl -0xb8(%ebp), %edx\n"
        "addl $0xc4, %edx\n"
        "movl %edx, -0xb0(%ebp)\n"
        /* { scope 2: passEntityNum, passEntityNum */
        "movl -0xb8(%ebp), %ecx\n" /* line 262 */
        "movzbl 0xe4(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl -0xa8(%ebp), %esi\n" /* passEntityNum */
        "movl %esi, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* point */
        "movl %edx, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %esi\n"
        "movl %esi, 8(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %ecx\n" /* trace */
        "movl %ecx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 264 */
        "je .Lf70350_000708b7\n"
        "movl -0x4c(%ebp), %edx\n" /* line 268 */
        "testl $0x2000000, %edx\n"
        "jne .Lf70350_000709bd\n"
        /* } scope */
        ".Lf70350_00070451:\n"
        "movl -0x60(%ebp), %eax\n" /* line 1711 | trace */
        "movl -0xbc(%ebp), %esi\n" /* contentMask */
        "movl %eax, 0x38(%esi)\n" /* contentMask */
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x3c(%esi)\n" /* contentMask */
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x40(%esi)\n" /* contentMask */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x44(%esi)\n" /* contentMask */
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x48(%esi)\n" /* contentMask */
        "movl %edx, 0x4c(%esi)\n" /* contentMask */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x50(%esi)\n" /* contentMask */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x54(%esi)\n" /* contentMask */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x58(%esi)\n" /* contentMask */
        "cmpb $0, -0x3e(%ebp)\n" /* line 1714 */
        "je .Lf70350_00070795\n"
        /* { scope 2: passEntityNum, passEntityNum */
        "movl -0xb8(%ebp), %eax\n" /* line 1574 */
        "movl (%eax), %ebx\n" /* ps */
        "movl $0, -0xa4(%ebp)\n" /* i */
        "leal 0x14(%ebx), %edx\n" /* ps */
        "movl %edx, -0xc0(%ebp)\n"
        "leal 0x18(%ebx), %ecx\n" /* ps */
        "movl %ecx, -0xc4(%ebp)\n"
        "leal 0x1c(%ebx), %esi\n" /* ps, damage */
        "movl %esi, -0xc8(%ebp)\n" /* damage */
        "movl %eax, %ecx\n"
        ".Lf70350_000704c3:\n"
        "movl -0xa4(%ebp), %edx\n" /* line 1579 | i, b */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $2, %eax\n"
        "leal CorrectSolidDeltas(%eax), %edx\n" /* b */
        /* { scope 3: entityNum */
        "movss 0x14(%ebx), %xmm0\n" /* line 240 */
        "addss CorrectSolidDeltas(%eax), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* point */
        "movss 0x18(%ebx), %xmm0\n" /* line 241 */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 0x1c(%ebx), %xmm0\n" /* line 242 */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        "movl 0x3c(%ecx), %esi\n" /* line 1580 | contentMask */
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, -0xa0(%ebp)\n" /* passEntityNum */
        /* { scope 3: entityNum */
        "movzbl 0xe4(%ecx), %eax\n" /* line 262 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %esi, 0x18(%esp)\n"
        "movl -0xa0(%ebp), %edx\n" /* passEntityNum */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* point */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* point */
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %ecx\n" /* trace */
        "movl %ecx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 264 */
        "je .Lf70350_00070610\n"
        "testb $2, -0x49(%ebp)\n" /* line 268 */
        "je .Lf70350_00070610\n"
        "movl -0x44(%ebp), %eax\n" /* line 271 */
        "movzwl %ax, %edx\n"
        "movl %edx, -0x9c(%ebp)\n" /* entityNum */
        /* { scope 4 */
        /* { scope 5 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf70350_000705b9\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 303 */
        "movl 0x40(%ecx), %edi\n"
        "cmpl $0x20, %edi\n"
        "je .Lf70350_000705bf\n"
        "testl %edi, %edi\n" /* line 309 */
        "jle .Lf70350_000708f0\n"
        "cmpl %edx, 0x44(%ecx)\n" /* line 311 */
        "je .Lf70350_000705b9\n"
        "movl %ecx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf70350_000705a0:\n"
        "addl $1, %ecx\n" /* line 309 */
        "cmpl %ecx, %edi\n"
        "je .Lf70350_000708f0\n"
        "movl 0x48(%edx), %eax\n" /* line 311 */
        "addl $4, %edx\n"
        "cmpl -0x9c(%ebp), %eax\n" /* entityNum */
        "jne .Lf70350_000705a0\n"
        ".Lf70350_000705b9:\n"
        "movl -0xb8(%ebp), %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf70350_000705bf:\n"
        "andl $0xfdffffff, 0x3c(%ecx)\n" /* line 272 */
        "movzbl 0xe4(%ecx), %eax\n" /* line 273 */
        "leal (%eax, %eax, 2), %eax\n"
        "andl $0xfdffffff, %esi\n" /* entityNum */
        "movl %esi, 0x18(%esp)\n" /* entityNum */
        "movl -0xa0(%ebp), %esi\n" /* passEntityNum, entityNum */
        "movl %esi, 0x14(%esp)\n" /* entityNum */
        "leal -0x3c(%ebp), %edx\n" /* point */
        "movl %edx, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %esi\n" /* entityNum */
        "movl %esi, 8(%esp)\n" /* entityNum */
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %ecx\n" /* trace */
        "movl %ecx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        /* } scope */
        ".Lf70350_00070610:\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 1581 */
        "je .Lf70350_00070635\n"
        "addl $1, -0xa4(%ebp)\n" /* line 1577 | i */
        "cmpl $0x1a, -0xa4(%ebp)\n" /* i */
        "je .Lf70350_00070bd4\n"
        "movl -0xb8(%ebp), %ecx\n"
        "jmp .Lf70350_000704c3\n"
        ".Lf70350_00070635:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 199 | point */
        "movl -0xc0(%ebp), %esi\n"
        "movl %eax, (%esi)\n"
        "addl $4, %esi\n" /* line 200 */
        "movl %esi, -0x98(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl -0xc0(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "addl $8, %edx\n" /* line 201 */
        "movl %edx, -0x94(%ebp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl -0xc0(%ebp), %ecx\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0x14(%ebx), %eax\n" /* line 1585 | ps */
        "movl %eax, -0x3c(%ebp)\n" /* point */
        "movl 0x18(%ebx), %eax\n" /* line 1586 | ps */
        "movl %eax, -0x38(%ebp)\n"
        "movss 0x1c(%ebx), %xmm0\n" /* line 1587 | ps */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x34(%ebp)\n"
        "movl -0xb8(%ebp), %eax\n" /* line 1589 */
        "movl 0x3c(%eax), %esi\n" /* contentMask */
        "movl 0xcc(%ebx), %ebx\n" /* ps */
        "movl %ebx, -0x90(%ebp)\n" /* ps, passEntityNum */
        /* { scope 3: entityNum */
        "movzbl 0xe4(%eax), %eax\n" /* line 262 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* point */
        "movl %edx, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl -0xc0(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 264 */
        "jne .Lf70350_00070cb0\n"
        "movl -0x4c(%ebp), %edx\n"
        /* } scope */
        ".Lf70350_000706ee:\n"
        "movl -0x60(%ebp), %eax\n" /* line 1590 | trace */
        "movl -0xbc(%ebp), %ecx\n"
        "movl %eax, 0x38(%ecx)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x3c(%ecx)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x40(%ecx)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x44(%ecx)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x48(%ecx)\n"
        "movl %edx, 0x4c(%ecx)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x50(%ecx)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x54(%ecx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x58(%ecx)\n"
        "movss -0x60(%ebp), %xmm2\n" /* line 1592 | trace, fraction */
        /* { scope 3: entityNum */
        "movl -0xc0(%ebp), %esi\n" /* line 1203 | entityNum */
        "movss (%esi), %xmm1\n" /* entityNum */
        "movss -0x3c(%ebp), %xmm0\n" /* point */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n" /* entityNum */
        "movl -0xc4(%ebp), %eax\n" /* line 1204 */
        "movss (%eax), %xmm1\n"
        "movss -0x38(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x98(%ebp), %edx\n"
        "movss %xmm1, (%edx)\n"
        "movl -0xc8(%ebp), %ecx\n" /* line 1205 */
        "movss (%ecx), %xmm1\n"
        "movss -0x34(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movl -0x94(%ebp), %esi\n" /* entityNum */
        "movss %xmm1, (%esi)\n" /* entityNum */
        /* } scope */
        /* } scope */
        ".Lf70350_00070795:\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 1720 */
        "jne .Lf70350_00070a63\n"
        ".Lf70350_0007079f:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1738 | 1.0f */
        "ucomiss -0x60(%ebp), %xmm0\n" /* trace */
        "jne .Lf70350_00070911\n"
        "jp .Lf70350_00070911\n"
        /* { scope 2: passEntityNum, passEntityNum */
        "movl -0xb8(%ebp), %eax\n" /* line 1630 */
        "movl (%eax), %ebx\n" /* ps */
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 1634 | ps */
        "je .Lf70350_00070f9b\n"
        "movl %eax, %esi\n" /* contentMask */
        "leal 0x14(%ebx), %ecx\n" /* line 1640 | ps */
        "movl 0x14(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x3c(%ebp)\n" /* point */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movss 8(%ecx), %xmm0\n" /* line 201 */
        "subss lit4_002ed78c, %xmm0\n" /* line 1641 | 64.0f */
        "movss %xmm0, -0x34(%ebp)\n"
        "movzbl 0xe4(%esi), %edx\n" /* line 1643 | contentMask */
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x3c(%esi), %eax\n" /* contentMask */
        "movl %eax, 0x18(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* point */
        "movl %eax, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %esi\n" /* contentMask */
        "movl %esi, 8(%esp)\n" /* contentMask */
        "movl %ecx, 4(%esp)\n"
        "leal -0x84(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *pmoveHandlers(, %edx, 4)\n"
        "movss -0x84(%ebp), %xmm1\n" /* line 1644 | trace */
        "ucomiss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "jne .Lf70350_00070d6e\n"
        "jp .Lf70350_00070d6e\n"
        "movl -0xb8(%ebp), %eax\n" /* line 1646 */
        "cmpb $0, 0x1c(%eax)\n"
        "js .Lf70350_000710a0\n"
        "movl $1, 0xc(%esp)\n" /* line 1647 */
        "movl $0, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        ".Lf70350_00070884:\n"
        "movl -0xbc(%ebp), %edx\n" /* line 1651 */
        "movl $0, 0x34(%edx)\n"
        "movl $0x3ff, 0x60(%ebx)\n" /* line 1668 | ps */
        "movl -0xbc(%ebp), %ecx\n" /* line 1669 */
        "movl $0, 0x30(%ecx)\n"
        "movl $0, 0x2c(%ecx)\n" /* line 1670 */
        /* } scope */
        /* } scope */
        ".Lf70350_000708ac:\n"
        "addl $0xec, %esp\n" /* line 1792 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf70350_000708b7:\n"
        "movl -0x4c(%ebp), %edx\n"
        "jmp .Lf70350_00070451\n"
        /* { scope 1: passEntityNum, i, point, trace, ... */
        ".Lf70350_000708bf:\n"
        "movss lit4_002ed604, %xmm1\n" /* line 1706 | 0.25f */
        "movl -0xac(%ebp), %ecx\n" /* ps */
        "movss 0x1c(%ecx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss 0x1c(%ecx), %xmm0\n" /* line 1707 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf70350_000703b8\n"
        /* { scope 2: passEntityNum, passEntityNum */
        /* { scope 3: entityNum */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf70350_000708f0:\n"
        "movl -0x9c(%ebp), %edx\n" /* line 318 | entityNum */
        "movl -0xb8(%ebp), %eax\n"
        "movl %edx, 0x44(%eax, %edi, 4)\n"
        "addl $1, %edi\n" /* line 319 */
        "movl %edi, 0x40(%eax)\n"
        "movl -0xb8(%ebp), %ecx\n"
        "jmp .Lf70350_000705bf\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf70350_00070911:\n"
        "movl -0xac(%ebp), %esi\n" /* line 1747 | ps, contentMask */
        "testb $0x20, 0xc(%esi)\n" /* contentMask */
        "je .Lf70350_00070c09\n"
        ".Lf70350_00070921:\n"
        "movss lit4_002ed6ac, %xmm0\n" /* line 1766 | 0.699999988079071f */
        "ucomiss -0x54(%ebp), %xmm0\n"
        "ja .Lf70350_00071045\n"
        "movl -0xbc(%ebp), %ecx\n" /* line 1780 */
        "movl $1, 0x30(%ecx)\n"
        "movl $1, 0x34(%ecx)\n" /* line 1782 */
        "movl $1, 0x2c(%ecx)\n" /* line 1784 */
        "movl -0xac(%ebp), %esi\n" /* line 1786 | ps, contentMask */
        "cmpl $0x3ff, 0x60(%esi)\n" /* contentMask */
        "je .Lf70350_00070de0\n"
        ".Lf70350_00070961:\n"
        "movzwl -0x44(%ebp), %eax\n" /* line 1789 */
        "movl %eax, 0x60(%esi)\n" /* contentMask */
        "movl -0x44(%ebp), %eax\n" /* line 1791 */
        "movzwl %ax, %ebx\n" /* entityNum */
        /* { scope 2: passEntityNum, passEntityNum */
        /* { scope 3: entityNum */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf70350_000708ac\n"
        "movl -0xb8(%ebp), %eax\n" /* line 303 */
        "movl 0x40(%eax), %edi\n"
        "cmpl $0x20, %edi\n"
        "je .Lf70350_000708ac\n"
        "testl %edi, %edi\n" /* line 309 */
        "jle .Lf70350_00071030\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 311 */
        "cmpl 0x44(%ecx), %ebx\n" /* entityNum */
        "je .Lf70350_000708ac\n"
        "xorl %edx, %edx\n"
        ".Lf70350_000709a3:\n"
        "addl $1, %edx\n" /* line 309 */
        "cmpl %edx, %edi\n"
        "je .Lf70350_00071030\n"
        "movl 0x48(%ecx), %eax\n" /* line 311 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n" /* entityNum */
        "jne .Lf70350_000709a3\n"
        "jmp .Lf70350_000708ac\n"
        /* } scope */
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        ".Lf70350_000709bd:\n"
        "movl -0x44(%ebp), %eax\n" /* line 271 */
        "movzwl %ax, %esi\n" /* entityNum */
        /* { scope 3: entityNum */
        /* { scope 4 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf70350_00070a01\n"
        "movl -0xb8(%ebp), %eax\n" /* line 303 */
        "movl 0x40(%eax), %edi\n"
        "cmpl $0x20, %edi\n"
        "je .Lf70350_00070a01\n"
        "testl %edi, %edi\n" /* line 309 */
        "jle .Lf70350_0007107a\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 311 */
        "cmpl %esi, 0x44(%ecx)\n" /* entityNum */
        "je .Lf70350_00070a07\n"
        "xorl %edx, %edx\n"
        ".Lf70350_000709ec:\n"
        "addl $1, %edx\n" /* line 309 */
        "cmpl %edx, %edi\n"
        "je .Lf70350_0007107a\n"
        "movl 0x48(%ecx), %eax\n" /* line 311 */
        "addl $4, %ecx\n"
        "cmpl %eax, %esi\n" /* entityNum */
        "jne .Lf70350_000709ec\n"
        ".Lf70350_00070a01:\n"
        "movl -0xb8(%ebp), %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf70350_00070a07:\n"
        "andl $0xfdffffff, 0x3c(%ecx)\n" /* line 272 */
        "movzbl 0xe4(%ecx), %eax\n" /* line 273 */
        "leal (%eax, %eax, 2), %eax\n"
        "andl $0xfdffffff, %ebx\n" /* entityNum */
        "movl %ebx, 0x18(%esp)\n" /* entityNum */
        "movl -0xa8(%ebp), %esi\n" /* passEntityNum, entityNum */
        "movl %esi, 0x14(%esp)\n" /* entityNum */
        "leal -0x30(%ebp), %edx\n" /* point */
        "movl %edx, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %esi\n" /* entityNum */
        "movl %esi, 8(%esp)\n" /* entityNum */
        "leal -0x24(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %ecx\n" /* trace */
        "movl %ecx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "movl -0x4c(%ebp), %edx\n"
        "jmp .Lf70350_00070451\n"
        /* } scope */
        ".Lf70350_00070a63:\n"
        "movl -0xac(%ebp), %edx\n" /* line 1722 | ps */
        "movss 0x1c(%edx), %xmm0\n"
        "subss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 1723 */
        "movl 0x3c(%ecx), %ebx\n" /* contentMask */
        "movl 0xcc(%edx), %esi\n" /* contentMask */
        "movl %esi, -0x8c(%ebp)\n" /* contentMask, passEntityNum */
        /* { scope 2: passEntityNum, passEntityNum */
        "movzbl 0xe4(%ecx), %eax\n" /* line 262 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* point */
        "movl %edx, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %esi\n"
        "movl %esi, 8(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %ecx\n" /* trace */
        "movl %ecx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 264 */
        "je .Lf70350_00070b89\n"
        "testb $2, -0x49(%ebp)\n" /* line 268 */
        "je .Lf70350_00070b89\n"
        "movl -0x44(%ebp), %eax\n" /* line 271 */
        "movzwl %ax, %esi\n" /* entityNum */
        /* { scope 3: entityNum */
        /* { scope 4 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf70350_00070b2f\n"
        "movl -0xb8(%ebp), %eax\n" /* line 303 */
        "movl 0x40(%eax), %edi\n"
        "cmpl $0x20, %edi\n"
        "je .Lf70350_00070b2f\n"
        "testl %edi, %edi\n" /* line 309 */
        "jle .Lf70350_00071113\n"
        "movl -0xb8(%ebp), %edx\n" /* line 311 */
        "cmpl %esi, 0x44(%edx)\n" /* entityNum */
        "je .Lf70350_000712a9\n"
        "movl %edx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf70350_00070b1a:\n"
        "addl $1, %edx\n" /* line 309 */
        "cmpl %edx, %edi\n"
        "je .Lf70350_00071113\n"
        "movl 0x48(%ecx), %eax\n" /* line 311 */
        "addl $4, %ecx\n"
        "cmpl %esi, %eax\n" /* entityNum */
        "jne .Lf70350_00070b1a\n"
        ".Lf70350_00070b2f:\n"
        "movl -0xb8(%ebp), %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf70350_00070b35:\n"
        "andl $0xfdffffff, 0x3c(%ecx)\n" /* line 272 */
        "movzbl 0xe4(%ecx), %eax\n" /* line 273 */
        "leal (%eax, %eax, 2), %eax\n"
        "andl $0xfdffffff, %ebx\n" /* entityNum */
        "movl %ebx, 0x18(%esp)\n" /* entityNum */
        "movl -0x8c(%ebp), %esi\n" /* passEntityNum, entityNum */
        "movl %esi, 0x14(%esp)\n" /* entityNum */
        "leal -0x30(%ebp), %edx\n" /* point */
        "movl %edx, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %esi\n" /* entityNum */
        "movl %esi, 8(%esp)\n" /* entityNum */
        "leal -0x24(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %ecx\n" /* trace */
        "movl %ecx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        /* } scope */
        ".Lf70350_00070b89:\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 1724 */
        "jne .Lf70350_00070dad\n"
        "movl -0x60(%ebp), %eax\n" /* line 1734 | trace */
        "movl -0xbc(%ebp), %edx\n"
        "movl %eax, 0x38(%edx)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x3c(%edx)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x40(%edx)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x44(%edx)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x48(%edx)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x4c(%edx)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x50(%edx)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x54(%edx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x58(%edx)\n"
        "jmp .Lf70350_0007079f\n"
        /* { scope 2: passEntityNum, passEntityNum */
        ".Lf70350_00070bd4:\n"
        "movl $0x3ff, 0x60(%ebx)\n" /* line 1597 | ps */
        "movl -0xbc(%ebp), %eax\n" /* line 1598 */
        "movl $0, 0x30(%eax)\n"
        "movl $0, 0x34(%eax)\n" /* line 1600 */
        "movl $0, 0x2c(%eax)\n" /* line 1602 */
        "movl %ebx, (%esp)\n" /* line 1603 | ps */
        "calll Jump_ClearState\n"
        /* } scope */
        /* } scope */
        "addl $0xec, %esp\n" /* line 1792 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: passEntityNum, i, point, trace, ... */
        ".Lf70350_00070c09:\n"
        "movss 0x28(%esi), %xmm0\n" /* line 1747 | contentMask */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf70350_00070921\n"
        "movl %esi, %eax\n" /* contentMask */
        "addl $0x20, %eax\n"
        "movss 0x20(%esi), %xmm1\n" /* contentMask */
        "mulss -0x5c(%ebp), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "mulss -0x58(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss -0x54(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss lit4_002ed6b4, %xmm1\n" /* 10.0f */
        "jbe .Lf70350_00070921\n"
        "movl -0xb8(%ebp), %eax\n" /* line 1751 */
        "cmpb $0, 0x1c(%eax)\n"
        "js .Lf70350_00071277\n"
        "movl $0, 0xc(%esp)\n" /* line 1752 */
        "movl $0, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* contentMask */
        "calll BG_AnimScriptEvent\n"
        ".Lf70350_00070c83:\n"
        "movl -0xbc(%ebp), %ecx\n" /* line 1756 */
        "movl $0, 0x34(%ecx)\n"
        "movl -0xac(%ebp), %esi\n" /* line 1759 | ps, contentMask */
        "movl $0x3ff, 0x60(%esi)\n" /* contentMask */
        "movl $0, 0x30(%ecx)\n" /* line 1760 */
        "movl $0, 0x2c(%ecx)\n" /* line 1761 */
        "jmp .Lf70350_000708ac\n"
        /* { scope 2: passEntityNum, passEntityNum */
        /* { scope 3: entityNum */
        ".Lf70350_00070cb0:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 268 */
        "testl $0x2000000, %edx\n"
        "je .Lf70350_000706ee\n"
        "movl -0x44(%ebp), %eax\n" /* line 271 */
        "movzwl %ax, %ebx\n" /* entityNum */
        /* { scope 4 */
        /* { scope 5 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf70350_00070d09\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 303 */
        "movl 0x40(%ecx), %edi\n"
        "cmpl $0x20, %edi\n"
        "je .Lf70350_00070d09\n"
        "testl %edi, %edi\n" /* line 309 */
        "jle .Lf70350_000710fe\n"
        "movl -0xb8(%ebp), %eax\n" /* line 311 */
        "cmpl %ebx, 0x44(%eax)\n" /* entityNum */
        "je .Lf70350_000712a2\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf70350_00070cf4:\n"
        "addl $1, %edx\n" /* line 309 */
        "cmpl %edx, %edi\n"
        "je .Lf70350_000710fe\n"
        "movl 0x48(%ecx), %eax\n" /* line 311 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n" /* entityNum */
        "jne .Lf70350_00070cf4\n"
        ".Lf70350_00070d09:\n"
        "movl -0xb8(%ebp), %edx\n"
        /* } scope */
        /* } scope */
        ".Lf70350_00070d0f:\n"
        "andl $0xfdffffff, 0x3c(%edx)\n" /* line 272 */
        "movzbl 0xe4(%edx), %eax\n" /* line 273 */
        "leal (%eax, %eax, 2), %eax\n"
        "andl $0xfdffffff, %esi\n" /* entityNum */
        "movl %esi, 0x18(%esp)\n" /* entityNum */
        "movl -0x90(%ebp), %ecx\n" /* passEntityNum */
        "movl %ecx, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %esi\n" /* point, entityNum */
        "movl %esi, 0x10(%esp)\n" /* entityNum */
        "movl -0xb4(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl -0xc0(%ebp), %esi\n" /* entityNum */
        "movl %esi, 4(%esp)\n" /* entityNum */
        "leal -0x60(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "movl -0x4c(%ebp), %edx\n"
        "jmp .Lf70350_000706ee\n"
        /* } scope */
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        ".Lf70350_00070d6e:\n"
        "movss lit4_002ed790, %xmm0\n" /* line 1655 | 0.015625f */
        "xorl %eax, %eax\n"
        "ucomiss %xmm1, %xmm0\n"
        "seta %al\n"
        "movl -0xbc(%ebp), %ecx\n"
        "movl %eax, 0x34(%ecx)\n"
        ".Lf70350_00070d87:\n"
        "movl $0x3ff, 0x60(%ebx)\n" /* line 1668 | ps */
        "movl -0xbc(%ebp), %ecx\n" /* line 1669 */
        "movl $0, 0x30(%ecx)\n"
        "movl $0, 0x2c(%ecx)\n" /* line 1670 */
        /* } scope */
        /* } scope */
        "addl $0xec, %esp\n" /* line 1792 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: passEntityNum, i, point, trace, ... */
        ".Lf70350_00070dad:\n"
        "movl -0xac(%ebp), %esi\n" /* line 1726 | ps, contentMask */
        "movl $0x3ff, 0x60(%esi)\n" /* contentMask */
        "movl -0xbc(%ebp), %eax\n" /* line 1727 */
        "movl $0, 0x30(%eax)\n"
        "movl $0, 0x34(%eax)\n" /* line 1729 */
        "movl $0, 0x2c(%eax)\n" /* line 1731 */
        /* } scope */
        "addl $0xec, %esp\n" /* line 1792 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: passEntityNum, i, point, trace, ... */
        /* { scope 2: passEntityNum, passEntityNum */
        ".Lf70350_00070de0:\n"
        "movss 0x74(%ecx), %xmm5\n" /* line 1425 */
        "cvtsi2ssl 0x48(%esi), %xmm6\n" /* line 1426 | damage */
        "movss CorrectSolidDeltas+544, %xmm3\n"
        "movaps %xmm6, %xmm7\n"
        "xorps %xmm3, %xmm7\n"
        "movaps %xmm7, %xmm4\n" /* line 1428 */
        "mulss lit4_002ed5d8, %xmm4\n" /* 0.5f */
        "movaps %xmm5, %xmm2\n" /* line 1432 */
        "mulss %xmm5, %xmm2\n"
        "movss 0x68(%ecx), %xmm0\n"
        "subss 0x1c(%esi), %xmm0\n" /* damage */
        "movaps %xmm4, %xmm1\n"
        "mulss lit4_002ed794, %xmm1\n" /* -4.0f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "ucomiss lit4_002ed5e8, %xmm2\n" /* line 1433 | 0.0f */
        "jp .Lf70350_00070e36\n"
        "jb .Lf70350_00071095\n"
        ".Lf70350_00070e36:\n"
        "movaps %xmm5, %xmm1\n" /* line 1438 */
        "xorps %xmm3, %xmm1\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "cvtss2sd %xmm2, %xmm0\n" /* line 1436 */
        "sqrtsd %xmm0, %xmm0\n"
        "subsd %xmm0, %xmm1\n"
        "addss %xmm4, %xmm4\n"
        "cvtss2sd %xmm4, %xmm0\n"
        "divsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm2\n"
        "mulss %xmm7, %xmm2\n"
        "addss %xmm5, %xmm2\n"
        "xorps %xmm3, %xmm2\n"
        "mulss %xmm2, %xmm2\n" /* line 1439 */
        "addss %xmm6, %xmm6\n"
        "divss %xmm6, %xmm2\n"
        "movl imp_bg_fallDamageMaxHeight, %eax\n" /* line 1442 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm3\n"
        "movl imp_bg_fallDamageMinHeight, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "ucomiss %xmm3, %xmm1\n"
        "jae .Lf70350_00071244\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1447 */
        "jae .Lf70350_000710f7\n"
        "movl -0xbc(%ebp), %eax\n"
        "testb $1, 0x48(%eax)\n"
        "jne .Lf70350_000710f7\n"
        "movl -0xac(%ebp), %edx\n" /* ps */
        "cmpl $5, 4(%edx)\n"
        "jg .Lf70350_000710f7\n"
        "ucomiss %xmm3, %xmm2\n" /* line 1451 */
        "jb .Lf70350_000710c5\n"
        "movl $0x64, %esi\n" /* damage */
        ".Lf70350_00070ecb:\n"
        "ucomiss lit4_002ed79c, %xmm2\n" /* line 1462 | 12.0f */
        "ja .Lf70350_00071195\n"
        "jp .Lf70350_00071195\n"
        "xorl %ebx, %ebx\n" /* viewDip */
        ".Lf70350_00070ee0:\n"
        "testl %esi, %esi\n" /* line 1477 | damage */
        "je .Lf70350_00071128\n"
        "cmpl $0x63, %esi\n" /* line 1481 | damage */
        "jg .Lf70350_00071202\n"
        "movl -0xbc(%ebp), %edx\n"
        "testb $2, 0x48(%edx)\n"
        "jne .Lf70350_00071202\n"
        "leal (%esi, %esi, 4), %edx\n" /* line 1483 | damage */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "addl $0x1f4, %eax\n"
        "cmpl $0x7d0, %eax\n" /* line 1484 */
        "jle .Lf70350_00071380\n"
        "movss lit4_002ed724, %xmm1\n" /* 0.20000000298023224f */
        "movl $0x7d0, %eax\n"
        ".Lf70350_00070f2a:\n"
        "movl -0xac(%ebp), %ecx\n" /* line 1494 | ps */
        "movl %eax, 0x10(%ecx)\n"
        "orl $0x200, 0xc(%ecx)\n" /* line 1495 */
        "movl %ecx, %eax\n" /* line 1496 | result */
        "addl $0x20, %eax\n" /* result */
        /* { scope 3: entityNum */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x20(%ecx), %xmm0\n"
        "movss %xmm0, 0x20(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        ".Lf70350_00070f63:\n"
        "movl -0xbc(%ebp), %ecx\n" /* line 822 */
        "movl 0x48(%ecx), %eax\n"
        "testb $0x20, %ah\n"
        "je .Lf70350_00071267\n"
        "movl $0x74, %eax\n"
        ".Lf70350_00070f7a:\n"
        "movl -0xac(%ebp), %edx\n" /* line 1503 | ps */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* damage */
        "movl %eax, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "movl -0xac(%ebp), %esi\n" /* ps, damage */
        "jmp .Lf70350_00070961\n"
        ".Lf70350_00070f9b:\n"
        "movl %eax, %esi\n" /* damage */
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        "leal 0x14(%ebx), %ecx\n" /* line 1660 | ps */
        "movl 0x14(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x3c(%ebp)\n" /* point */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movss 8(%ecx), %xmm0\n" /* line 201 */
        "subss lit4_002ed5d0, %xmm0\n" /* line 1661 | 1.0f */
        "movss %xmm0, -0x34(%ebp)\n"
        "movzbl 0xe4(%esi), %edx\n" /* line 1663 | contentMask */
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x3c(%esi), %eax\n" /* contentMask */
        "movl %eax, 0x18(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* point */
        "movl %eax, 0x10(%esp)\n"
        "movl -0xb4(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0xb0(%ebp), %esi\n" /* contentMask */
        "movl %esi, 8(%esp)\n" /* contentMask */
        "movl %ecx, 4(%esp)\n"
        "leal -0x84(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *pmoveHandlers(, %edx, 4)\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1664 | 1.0f */
        "ucomiss -0x84(%ebp), %xmm0\n" /* trace */
        "setne %al\n"
        "setp %dl\n"
        "orb %dl, %al\n"
        "movzbl %al, %eax\n"
        "movl -0xbc(%ebp), %edx\n"
        "movl %eax, 0x34(%edx)\n"
        "jmp .Lf70350_00070d87\n"
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        /* { scope 3: entityNum */
        ".Lf70350_00071030:\n"
        "movl -0xb8(%ebp), %edx\n" /* line 318 */
        "movl %ebx, 0x44(%edx, %edi, 4)\n" /* entityNum */
        "addl $1, %edi\n" /* line 319 */
        "movl %edi, 0x40(%edx)\n"
        "jmp .Lf70350_000708ac\n"
        /* } scope */
        /* } scope */
        ".Lf70350_00071045:\n"
        "movl -0xac(%ebp), %eax\n" /* line 1770 | ps */
        "movl $0x3ff, 0x60(%eax)\n"
        "movl -0xbc(%ebp), %edx\n" /* line 1771 */
        "movl $1, 0x30(%edx)\n"
        "movl $1, 0x34(%edx)\n" /* line 1773 */
        "movl $0, 0x2c(%edx)\n" /* line 1775 */
        "movl %eax, (%esp)\n" /* line 1776 */
        "calll Jump_ClearState\n"
        "jmp .Lf70350_000708ac\n"
        /* { scope 2: passEntityNum, passEntityNum */
        /* { scope 3: entityNum */
        /* { scope 4 */
        ".Lf70350_0007107a:\n"
        "movl -0xb8(%ebp), %edx\n" /* line 318 */
        "movl %esi, 0x44(%edx, %edi, 4)\n" /* entityNum */
        "addl $1, %edi\n" /* line 319 */
        "movl %edi, 0x40(%edx)\n"
        "movl -0xb8(%ebp), %ecx\n"
        "jmp .Lf70350_00070a07\n"
        ".Lf70350_00071095:\n"
        "movl -0xac(%ebp), %esi\n" /* ps, entityNum */
        "jmp .Lf70350_00070961\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        ".Lf70350_000710a0:\n"
        "movl $1, 0xc(%esp)\n" /* line 1649 */
        "movl $0, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "jmp .Lf70350_00070884\n"
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        ".Lf70350_000710c5:\n"
        "movaps %xmm2, %xmm0\n" /* line 1457 */
        "subss %xmm1, %xmm0\n"
        "subss %xmm1, %xmm3\n"
        "divss %xmm3, %xmm0\n"
        "mulss lit4_002ed798, %xmm0\n" /* 100.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl $0x64, %esi\n" /* line 154 */
        "movl %eax, %ecx\n"
        "subl $0x64, %ecx\n"
        "cmovsl %eax, %esi\n"
        "negl %eax\n"
        "testl %eax, %eax\n"
        "js .Lf70350_00070ecb\n"
        ".Lf70350_000710f7:\n"
        "xorl %esi, %esi\n"
        "jmp .Lf70350_00070ecb\n"
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        /* { scope 3: entityNum */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf70350_000710fe:\n"
        "movl -0xb8(%ebp), %eax\n" /* line 318 */
        "movl %ebx, 0x44(%eax, %edi, 4)\n" /* entityNum */
        "addl $1, %edi\n" /* line 319 */
        "movl %edi, 0x40(%eax)\n"
        "jmp .Lf70350_00070d09\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        /* { scope 3: entityNum */
        /* { scope 4 */
        ".Lf70350_00071113:\n"
        "movl -0xb8(%ebp), %edx\n" /* line 318 */
        "movl %esi, 0x44(%edx, %edi, 4)\n" /* entityNum */
        "addl $1, %edi\n" /* line 319 */
        "movl %edi, 0x40(%edx)\n"
        "jmp .Lf70350_00070b2f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: passEntityNum, passEntityNum */
        ".Lf70350_00071128:\n"
        "ucomiss lit4_002ed608, %xmm2\n" /* line 1505 | 4.0f */
        "jbe .Lf70350_00071095\n"
        "ucomiss lit4_002ed740, %xmm2\n" /* line 1507 | 8.0f */
        "jae .Lf70350_000712b0\n"
        "jp .Lf70350_000712b0\n"
        /* { scope 3: entityNum */
        "movl -0xbc(%ebp), %ecx\n" /* line 822 */
        "movl 0x48(%ecx), %eax\n"
        "testb $0x20, %ah\n"
        "jne .Lf70350_00071308\n"
        "andl $0x1f00000, %eax\n" /* line 825 */
        "shrl $0x14, %eax\n"
        "movzbl %al, %edx\n"
        "testb %al, %al\n" /* line 1345 */
        "je .Lf70350_00071308\n"
        "leal 0x18(%edx), %eax\n" /* line 1347 */
        /* } scope */
        /* { scope 3: entityNum */
        ".Lf70350_00071170:\n"
        "movl -0xac(%ebp), %esi\n" /* line 285 | ps, entityNum */
        "movl %esi, 8(%esp)\n" /* entityNum */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "movl -0xac(%ebp), %esi\n" /* ps, entityNum */
        "jmp .Lf70350_00070961\n"
        /* } scope */
        ".Lf70350_00071195:\n"
        "movaps %xmm2, %xmm0\n" /* line 1468 */
        "subss lit4_002ed79c, %xmm0\n" /* 12.0f */
        "divss lit4_002ed7a0, %xmm0\n" /* 26.0f */
        "movss lit4_002ed608, %xmm1\n" /* 4.0f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %ebx\n" /* viewDip */
        "cmpl $0x19, %ebx\n" /* line 1469 | viewDip */
        "movl $0x18, %eax\n"
        "cmovgel %eax, %ebx\n" /* viewDip */
        "movl $1, 0xc(%esp)\n" /* line 1473 */
        "movl $0, 8(%esp)\n"
        "movl $5, 4(%esp)\n"
        "movl -0xac(%ebp), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0xd8(%ebp)\n"
        "calll BG_AnimScriptEvent\n"
        "movss -0xd8(%ebp), %xmm2\n"
        "jmp .Lf70350_00070ee0\n"
        ".Lf70350_00071202:\n"
        "movl -0xac(%ebp), %eax\n" /* line 1500 | ps, result */
        "addl $0x20, %eax\n" /* result */
        /* { scope 3: entityNum */
        "movss lit4_002ed7a8, %xmm0\n" /* line 272 | 0.6700000166893005f */
        "movl -0xac(%ebp), %edx\n" /* ps */
        "movss 0x20(%edx), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 0x20(%edx)\n"
        "movss 4(%eax), %xmm1\n" /* line 273 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%eax), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        "jmp .Lf70350_00070f63\n"
        /* } scope */
        ".Lf70350_00071244:\n"
        "movl $str_0021bf1c, (%esp)\n" /* line 1444 */
        "movss %xmm2, -0xd8(%ebp)\n"
        "calll Com_Printf\n"
        "xorl %esi, %esi\n" /* damage */
        "movss -0xd8(%ebp), %xmm2\n"
        "jmp .Lf70350_00070ecb\n"
        ".Lf70350_00071267:\n"
        "andl $0x1f00000, %eax\n" /* line 822 */
        "shrl $0x14, %eax\n"
        "addl $0x74, %eax\n"
        "jmp .Lf70350_00070f7a\n"
        /* } scope */
        ".Lf70350_00071277:\n"
        "movl $0, 0xc(%esp)\n" /* line 1754 */
        "movl $0, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl -0xac(%ebp), %edx\n" /* ps */
        "movl %edx, (%esp)\n"
        "calll BG_AnimScriptEvent\n"
        "jmp .Lf70350_00070c83\n"
        ".Lf70350_000712a2:\n"
        "movl %eax, %edx\n"
        "jmp .Lf70350_00070d0f\n"
        ".Lf70350_000712a9:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf70350_00070b35\n"
        /* { scope 2: passEntityNum, passEntityNum */
        ".Lf70350_000712b0:\n"
        "ucomiss lit4_002ed79c, %xmm2\n" /* line 1511 | 12.0f */
        "jae .Lf70350_0007130f\n"
        "jp .Lf70350_0007130f\n"
        /* { scope 3: entityNum */
        "movl -0xbc(%ebp), %edx\n" /* line 822 */
        "movl 0x48(%edx), %eax\n"
        "testb $0x20, %ah\n"
        "jne .Lf70350_00071394\n"
        "andl $0x1f00000, %eax\n" /* line 825 */
        "shrl $0x14, %eax\n"
        "movzbl %al, %edx\n"
        "testb %al, %al\n" /* line 1363 */
        "je .Lf70350_00071394\n"
        "leal 1(%edx), %eax\n" /* line 1365 */
        /* } scope */
        /* { scope 3: entityNum */
        ".Lf70350_000712e3:\n"
        "movl -0xac(%ebp), %ecx\n" /* line 285 | ps */
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "movl -0xac(%ebp), %esi\n" /* ps, entityNum */
        "jmp .Lf70350_00070961\n"
        /* } scope */
        /* { scope 3: entityNum */
        ".Lf70350_00071308:\n"
        "xorl %eax, %eax\n" /* line 1347 */
        "jmp .Lf70350_00071170\n"
        /* } scope */
        ".Lf70350_0007130f:\n"
        "movl -0xac(%ebp), %eax\n" /* line 1517 | ps, result */
        "addl $0x20, %eax\n" /* result */
        /* { scope 3: entityNum */
        "movss lit4_002ed7a8, %xmm0\n" /* line 272 | 0.6700000166893005f */
        "movl -0xac(%ebp), %esi\n" /* ps, entityNum */
        "movss 0x20(%esi), %xmm1\n" /* entityNum */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 0x20(%esi)\n" /* entityNum */
        "movss 4(%eax), %xmm1\n" /* line 273 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%eax), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl -0xbc(%ebp), %edx\n" /* line 822 */
        "movl 0x48(%edx), %eax\n"
        "testb $0x20, %ah\n"
        "je .Lf70350_000713af\n"
        "movl $0x5d, %eax\n"
        ".Lf70350_0007135f:\n"
        "movl -0xac(%ebp), %ecx\n" /* line 1518 | ps */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* viewDip */
        "movl %eax, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "movl -0xac(%ebp), %esi\n" /* ps, damage */
        "jmp .Lf70350_00070961\n"
        ".Lf70350_00071380:\n"
        "cmpl $0x1f4, %eax\n" /* line 1487 */
        "jg .Lf70350_0007139b\n"
        "movss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "jmp .Lf70350_00070f2a\n"
        /* { scope 3: entityNum */
        ".Lf70350_00071394:\n"
        "xorl %eax, %eax\n" /* line 1365 */
        "jmp .Lf70350_000712e3\n"
        /* } scope */
        ".Lf70350_0007139b:\n"
        "cmpl $0x5db, %eax\n" /* line 1489 */
        "jle .Lf70350_000713bc\n"
        "movss lit4_002ed724, %xmm1\n" /* 0.20000000298023224f */
        "jmp .Lf70350_00070f2a\n"
        ".Lf70350_000713af:\n"
        "andl $0x1f00000, %eax\n" /* line 822 */
        "shrl $0x14, %eax\n"
        "addl $0x5d, %eax\n"
        "jmp .Lf70350_0007135f\n"
        ".Lf70350_000713bc:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 1492 */
        "subss lit4_002ed7a4, %xmm1\n" /* 500.0f */
        "divss lit4_002ed5c8, %xmm1\n" /* 1000.0f */
        "mulss lit4_002ed61c, %xmm1\n" /* -0.30000001192092896f */
        "addss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "jmp .Lf70350_00070f2a\n"
    );
}

/* line 4683 */
__attribute__((naked))
void Pmove(pmove_t *pm)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4683 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x21c, %esp\n"
        "movl 8(%ebp), %edi\n" /* pm */
        /* { scope 1 */
        "movl (%edi), %eax\n" /* line 4688 | pm */
        "movl %eax, -0x178(%ebp)\n" /* ps */
        "movl 4(%edi), %edx\n" /* line 4700 | pm */
        "movl %edx, -0x17c(%ebp)\n" /* finalTime */
        "movl %eax, %ecx\n" /* line 4702 */
        "movl (%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lf713e6_00071984\n"
        "addl $0x3e8, %eax\n" /* line 4705 */
        "cmpl %eax, %edx\n"
        "jg .Lf713e6_000723fc\n"
        ".Lf713e6_0007141f:\n"
        "movl $0, 0x40(%edi)\n" /* line 4708 | pm */
        "movl -0x178(%ebp), %eax\n" /* line 4712 | ps */
        "movl (%eax), %ecx\n"
        "cmpl %ecx, -0x17c(%ebp)\n" /* finalTime */
        "je .Lf713e6_00071984\n"
        "leal 4(%edi), %edx\n" /* pm */
        "movl %edx, -0x188(%ebp)\n"
        /* { scope 2: pml */
        ".Lf713e6_00071443:\n"
        "movl -0x17c(%ebp), %eax\n" /* line 4716 | finalTime */
        "subl %ecx, %eax\n"
        "cmpl $0x43, %eax\n" /* line 4717 */
        "movl $0x42, %edx\n"
        "cmovgel %edx, %eax\n"
        "addl %ecx, %eax\n" /* line 4720 */
        "movl %eax, 4(%edi)\n" /* pm */
        /* { scope 3: wishvel, wishdir, wishspeed, wishspeed, ... */
        "movl (%edi), %esi\n" /* line 4326 */
        "movl %edi, (%esp)\n" /* line 4331 */
        "calll BG_AnimUpdatePlayerStateConditions\n"
        "cmpw $0, 0xc(%esi)\n" /* line 4335 */
        "jns .Lf713e6_0007187d\n"
        "andl $0x2300, 8(%edi)\n" /* line 4339 */
        "movb $0, 0x1c(%edi)\n" /* line 4340 */
        "movb $0, 0x1d(%edi)\n" /* line 4341 */
        "leal 0x20(%esi), %ecx\n" /* line 4342 */
        "movl %ecx, -0x180(%ebp)\n"
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, 0x20(%esi)\n"
        "movl %eax, 4(%ecx)\n" /* line 192 */
        "movl %eax, 8(%ecx)\n" /* line 193 */
        ".Lf713e6_00071493:\n"
        "movl 8(%edi), %eax\n" /* line 4349 */
        "testl $0x40000, %eax\n"
        "je .Lf713e6_000714ad\n"
        "andl $0x43300, %eax\n" /* line 4353 */
        "movl %eax, 8(%edi)\n"
        "movb $0, 0x1c(%edi)\n" /* line 4354 */
        "movb $0, 0x1d(%edi)\n" /* line 4355 */
        ".Lf713e6_000714ad:\n"
        "movl 0xc(%esi), %ecx\n" /* line 4359 */
        "andl $0xfffeffff, %ecx\n"
        "movl %ecx, 0xc(%esi)\n"
        "cmpl $5, 4(%esi)\n" /* line 4361 */
        "jle .Lf713e6_000714c9\n"
        "andl $0xfdffffff, 0x3c(%edi)\n" /* line 4362 */
        "movl 0xc(%esi), %ecx\n"
        ".Lf713e6_000714c9:\n"
        "testb $1, %cl\n" /* line 4365 */
        "je .Lf713e6_00071848\n"
        "movzbl 0x1c(%edi), %eax\n" /* line 4368 */
        "movzbl 0x38(%edi), %edx\n"
        "cmpb %dl, %al\n"
        "je .Lf713e6_000714ff\n"
        "movsbl %al, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movss CorrectSolidDeltas+560, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "movsbl %dl, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "andps %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf713e6_00071534\n"
        ".Lf713e6_000714ff:\n"
        "movzbl 0x1d(%edi), %eax\n"
        "movzbl 0x39(%edi), %edx\n"
        "cmpb %dl, %al\n"
        "je .Lf713e6_00071830\n"
        "movsbl %al, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movss CorrectSolidDeltas+560, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "movsbl %dl, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "andps %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf713e6_00071830\n"
        ".Lf713e6_00071534:\n"
        "movl %esi, (%esp)\n" /* line 4371 */
        "calll PM_InteruptWeaponWithProneMove\n"
        "testl %eax, %eax\n"
        "jne .Lf713e6_00071a03\n"
        ".Lf713e6_00071544:\n"
        "movl 0xc(%esi), %ecx\n"
        ".Lf713e6_00071547:\n"
        "movl 0xf4(%esi), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "je .Lf713e6_0007185d\n"
        ".Lf713e6_00071556:\n"
        "xorl %ebx, %ebx\n" /* line 353 */
        "cmpl $0xb, %eax\n"
        "sete %bl\n"
        ".Lf713e6_0007155e:\n"
        "andb $0x40, %cl\n" /* line 4391 */
        "je .Lf713e6_0007156c\n"
        "cmpl $1, %ebx\n" /* stance */
        "je .Lf713e6_000719f6\n"
        ".Lf713e6_0007156c:\n"
        "testb $4, 0xa(%edi)\n" /* line 4399 */
        "je .Lf713e6_00071867\n"
        "movl 0xa0(%esi), %eax\n" /* line 4400 */
        "orl $0x200000, %eax\n"
        "movl %eax, 0xa0(%esi)\n"
        ".Lf713e6_00071587:\n"
        "andl $0xffffffbf, %eax\n" /* line 4406 */
        "movl %eax, 0xa0(%esi)\n"
        "cmpl $5, 4(%esi)\n" /* line 4409 */
        "je .Lf713e6_000715b9\n"
        "testb $0x10, 0xd(%esi)\n" /* line 4412 */
        "jne .Lf713e6_000715b3\n"
        "movl 0xd8(%esi), %eax\n" /* line 4414 */
        "testl %eax, %eax\n"
        "je .Lf713e6_000719c1\n"
        "cmpl $3, %eax\n"
        "je .Lf713e6_000719c1\n"
        ".Lf713e6_000715b3:\n"
        "cmpl $5, 4(%esi)\n" /* line 4432 */
        "jg .Lf713e6_000715c9\n"
        ".Lf713e6_000715b9:\n"
        "testl $0x4001, 8(%edi)\n"
        "jne .Lf713e6_000715c9\n"
        "andl $0xffffefff, 0xc(%esi)\n" /* line 4434 */
        ".Lf713e6_000715c9:\n"
        "movl $0x7c, 8(%esp)\n" /* line 4438 */
        "movl $0, 4(%esp)\n"
        "leal -0xe8(%ebp), %ecx\n" /* pml */
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl 4(%edi), %ecx\n" /* line 4441 */
        "movl %ecx, %edx\n"
        "subl (%esi), %edx\n"
        "movl %edx, -0xc0(%ebp)\n"
        "testl %edx, %edx\n" /* line 4442 */
        "jle .Lf713e6_000719a6\n"
        "movl $0xc8, %eax\n" /* line 4445 */
        "cmpl $0xc9, %edx\n"
        "cmovll -0xc0(%ebp), %eax\n"
        "movl %eax, -0xc0(%ebp)\n"
        ".Lf713e6_00071614:\n"
        "movl %ecx, (%esi)\n" /* line 4446 */
        "leal 0x14(%esi), %eax\n" /* line 4449 */
        "movl %eax, -0x174(%ebp)\n"
        "movl 0x14(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x88(%ebp)\n"
        "leal 0x18(%esi), %edx\n" /* line 200 */
        "movl %edx, -0x170(%ebp)\n"
        "movl 0x18(%esi), %eax\n"
        "movl %eax, -0x84(%ebp)\n"
        "leal 0x1c(%esi), %ecx\n" /* line 201 */
        "movl %ecx, -0x16c(%ebp)\n"
        "movl 0x1c(%esi), %eax\n"
        "movl %eax, -0x80(%ebp)\n"
        "movl 0x20(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x7c(%ebp)\n"
        "leal 0x24(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x168(%ebp)\n"
        "movl 0x24(%esi), %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "leal 0x28(%esi), %edx\n" /* line 201 */
        "movl %edx, -0x164(%ebp)\n"
        "movl 0x28(%esi), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "cvtsi2ssl -0xc0(%ebp), %xmm0\n" /* line 4454 */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0xc4(%ebp)\n"
        "leal -0xe8(%ebp), %ecx\n" /* line 4456 | pml */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_AdjustAimSpreadScale\n"
        "movzbl 0xe4(%edi), %eax\n" /* line 4459 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x188(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "cvtsi2ssl -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PM_UpdateViewAngles\n"
        "leal -0xd0(%ebp), %edx\n" /* line 4461 */
        "movl %edx, 0xc(%esp)\n"
        "leal -0xdc(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "leal -0xe8(%ebp), %eax\n" /* pml */
        "movl %eax, 4(%esp)\n"
        "leal 0xe8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "cmpb $0, 0x1c(%edi)\n" /* line 4464 */
        "jl .Lf713e6_000719b5\n"
        "jle .Lf713e6_000719e7\n" /* line 4468 */
        ".Lf713e6_000716fe:\n"
        "andl $0xffffff7f, 0xc(%esi)\n" /* line 4470 */
        ".Lf713e6_00071705:\n"
        "cmpl $5, 4(%esi)\n" /* line 4473 */
        "jle .Lf713e6_00071713\n"
        "movb $0, 0x1c(%edi)\n" /* line 4475 */
        "movb $0, 0x1d(%edi)\n" /* line 4476 */
        ".Lf713e6_00071713:\n"
        "subl $1, %ebx\n" /* line 4480 | stance */
        "je .Lf713e6_0007198f\n"
        ".Lf713e6_0007171c:\n"
        "movl %esi, (%esp)\n" /* line 4486 */
        "calll Mantle_ClearHint\n"
        "cmpl $7, 4(%esi)\n" /* line 4488 */
        "ja .Lf713e6_00071734\n"
        "movl 4(%esi), %eax\n"
        "jmpl *.Ljt_713e6_0(, %eax, 4)\n"
        ".Lf713e6_00071734:\n"
        "testl $0x300, 0xa0(%esi)\n" /* line 4569 */
        "je .Lf713e6_0007188b\n"
        "movl 0xc(%esi), %ecx\n" /* line 4008 */
        "testb $0x20, %cl\n"
        "je .Lf713e6_00071755\n"
        "orl $0x40000, %ecx\n" /* line 4009 */
        "movl %ecx, 0xc(%esi)\n"
        ".Lf713e6_00071755:\n"
        "andl $0xffffffdf, %ecx\n" /* line 4011 */
        "movl %ecx, 0xc(%esi)\n"
        "movl $0x3ff, 0x60(%esi)\n" /* line 4572 */
        "movl $0, -0xb8(%ebp)\n" /* line 4573 */
        "movl $0, -0xb4(%ebp)\n" /* line 4575 */
        "movl $0, -0xbc(%ebp)\n" /* line 4577 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl -0x180(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl %eax, 4(%ecx)\n" /* line 184 */
        "movl %eax, 8(%ecx)\n" /* line 185 */
        "leal -0xe8(%ebp), %eax\n" /* line 4581 | pml */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightFlag\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %edx\n" /* line 3972 */
        "movl 0xc(%edx), %eax\n" /* line 3975 */
        "movl %eax, %ecx\n"
        "andb $0xfe, %ch\n"
        "movl %ecx, 0xc(%edx)\n"
        "cmpl $5, 4(%edx)\n" /* line 3977 */
        "jg .Lf713e6_000717bf\n"
        "testb $0x10, 9(%edi)\n" /* line 3980 */
        "jne .Lf713e6_000723ae\n"
        /* } scope */
        ".Lf713e6_000717bf:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4584 | pml */
        "movl %edi, %eax\n"
        "calll PM_CheckDuck\n"
        "movl 0x10(%esi), %eax\n" /* line 3366 */
        "testl %eax, %eax\n"
        "je .Lf713e6_000717e6\n"
        "movl -0xc0(%ebp), %edx\n" /* line 3368 */
        "cmpl %edx, %eax\n"
        "jle .Lf713e6_0007239b\n"
        "subl %edx, %eax\n" /* line 3375 */
        "movl %eax, 0x10(%esi)\n"
        ".Lf713e6_000717e6:\n"
        "movl 0x78(%esi), %edx\n" /* line 3380 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_000717fb\n"
        "xorl %eax, %eax\n" /* line 3385 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x78(%esi)\n"
        ".Lf713e6_000717fb:\n"
        "movl 0x80(%esi), %edx\n" /* line 3389 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_00071816\n"
        "xorl %eax, %eax\n" /* line 3394 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x80(%esi)\n"
        ".Lf713e6_00071816:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4586 | pml */
        "movl %edi, %eax\n"
        "calll PM_Footsteps\n"
        "movl %esi, (%esp)\n" /* line 4587 */
        "calll PM_ResetWeaponState\n"
        "jmp .Lf713e6_00071946\n"
        ".Lf713e6_00071830:\n"
        "testb $0x40, %cl\n" /* line 4378 */
        "jne .Lf713e6_00071547\n"
        "movl 0xd8(%esi), %eax\n"
        "cmpl $2, %eax\n"
        "ja .Lf713e6_0007240a\n"
        ".Lf713e6_00071848:\n"
        "andb $0xf7, %ch\n" /* line 4385 */
        "movl %ecx, 0xc(%esi)\n"
        "movl 0xf4(%esi), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "jne .Lf713e6_00071556\n"
        ".Lf713e6_0007185d:\n"
        "movl $2, %ebx\n"
        "jmp .Lf713e6_0007155e\n"
        ".Lf713e6_00071867:\n"
        "movl 0xa0(%esi), %eax\n" /* line 4402 */
        "andl $0xffdfffff, %eax\n"
        "movl %eax, 0xa0(%esi)\n"
        "jmp .Lf713e6_00071587\n"
        ".Lf713e6_0007187d:\n"
        "leal 0x20(%esi), %eax\n"
        "movl %eax, -0x180(%ebp)\n"
        "jmp .Lf713e6_00071493\n"
        ".Lf713e6_0007188b:\n"
        "testb $4, 0xc(%esi)\n" /* line 4591 */
        "je .Lf713e6_00072928\n"
        ".Lf713e6_00071895:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4601 | pml */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Mantle_Check\n"
        "movl 0xc(%esi), %ecx\n" /* line 4602 */
        "testb $4, %cl\n"
        "je .Lf713e6_00072466\n"
        "testb $0x20, %cl\n" /* line 4008 */
        "je .Lf713e6_000718c1\n"
        "orl $0x40000, %ecx\n" /* line 4009 */
        "movl %ecx, 0xc(%esi)\n"
        ".Lf713e6_000718c1:\n"
        "andl $0xffffffdf, %ecx\n" /* line 4011 */
        "movl %ecx, 0xc(%esi)\n"
        "movl $0x3ff, 0x60(%esi)\n" /* line 4605 */
        "movl $0, -0xb8(%ebp)\n" /* line 4606 */
        "movl $0, -0xbc(%ebp)\n" /* line 4607 */
        "leal -0xe8(%ebp), %ecx\n" /* line 4609 | pml */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightFlag\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %edx\n" /* line 3972 */
        "movl 0xc(%edx), %eax\n" /* line 3975 */
        "movl %eax, %ecx\n"
        "andb $0xfe, %ch\n"
        "movl %ecx, 0xc(%edx)\n"
        "cmpl $5, 4(%edx)\n" /* line 3977 */
        "jg .Lf713e6_00071911\n"
        "testb $0x10, 9(%edi)\n" /* line 3980 */
        "jne .Lf713e6_00072418\n"
        /* } scope */
        ".Lf713e6_00071911:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4611 | pml */
        "movl %edi, %eax\n"
        "calll PM_CheckDuck\n"
        "leal -0xe8(%ebp), %eax\n" /* line 4612 | pml */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Mantle_Move\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4613 | pml */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_Weapon\n"
        /* } scope */
        ".Lf713e6_00071946:\n"
        "movl 4(%edi), %eax\n" /* line 4722 | pm */
        "movl %eax, 0x20(%edi)\n" /* pm */
        "movl 8(%edi), %eax\n" /* pm */
        "movl %eax, 0x24(%edi)\n" /* pm */
        "movl 0xc(%edi), %eax\n" /* pm */
        "movl %eax, 0x28(%edi)\n" /* pm */
        "movl 0x10(%edi), %eax\n" /* pm */
        "movl %eax, 0x2c(%edi)\n" /* pm */
        "movl 0x14(%edi), %eax\n" /* pm */
        "movl %eax, 0x30(%edi)\n" /* pm */
        "movl 0x18(%edi), %eax\n" /* pm */
        "movl %eax, 0x34(%edi)\n" /* pm */
        "movl 0x1c(%edi), %eax\n" /* pm */
        "movl %eax, 0x38(%edi)\n" /* pm */
        /* } scope */
        "movl -0x178(%ebp), %edx\n" /* line 4712 | ps */
        "movl (%edx), %ecx\n"
        "cmpl %ecx, -0x17c(%ebp)\n" /* finalTime */
        "jne .Lf713e6_00071443\n"
        /* } scope */
        ".Lf713e6_00071984:\n"
        "addl $0x21c, %esp\n" /* line 4724 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: pml */
        /* { scope 3: wishvel, wishdir, wishspeed, wishspeed, ... */
        ".Lf713e6_0007198f:\n"
        "testb $8, 0xd(%esi)\n" /* line 4480 */
        "je .Lf713e6_0007171c\n"
        "movb $0, 0x1c(%edi)\n" /* line 4482 */
        "movb $0, 0x1d(%edi)\n" /* line 4483 */
        "jmp .Lf713e6_0007171c\n"
        ".Lf713e6_000719a6:\n"
        "movl $1, -0xc0(%ebp)\n" /* line 4443 */
        "jmp .Lf713e6_00071614\n"
        ".Lf713e6_000719b5:\n"
        "orl $0x80, 0xc(%esi)\n" /* line 4466 */
        "jmp .Lf713e6_00071705\n"
        ".Lf713e6_000719c1:\n"
        "movl %esi, (%esp)\n" /* line 4417 */
        "calll PM_WeaponAmmoAvailable\n"
        "testl %eax, %eax\n"
        "je .Lf713e6_000715b3\n"
        "testb $1, 8(%edi)\n" /* line 4419 */
        "je .Lf713e6_000715b3\n"
        "orl $0x40, 0xa0(%esi)\n" /* line 4422 */
        "jmp .Lf713e6_000715b3\n"
        ".Lf713e6_000719e7:\n"
        "cmpb $0, 0x1d(%edi)\n" /* line 4468 */
        "je .Lf713e6_00071705\n"
        "jmp .Lf713e6_000716fe\n"
        ".Lf713e6_000719f6:\n"
        "movb $0, 0x1c(%edi)\n" /* line 4393 */
        "movb $0, 0x1d(%edi)\n" /* line 4394 */
        "jmp .Lf713e6_0007156c\n"
        ".Lf713e6_00071a03:\n"
        "andl $0xfffff7ff, 0xc(%esi)\n" /* line 4373 */
        "movl %esi, (%esp)\n" /* line 4374 */
        "calll PM_ExitAimDownSight\n"
        "jmp .Lf713e6_00071544\n"
        ".Lf713e6_00071a17:\n"
        "movl 0xc(%esi), %ecx\n" /* line 4008 */
        "testb $0x20, %cl\n"
        "je .Lf713e6_00071a28\n"
        "orl $0x40000, %ecx\n" /* line 4009 */
        "movl %ecx, 0xc(%esi)\n"
        ".Lf713e6_00071a28:\n"
        "andl $0xffffffdf, %ecx\n" /* line 4011 */
        "movl %ecx, 0xc(%esi)\n"
        "leal -0xe8(%ebp), %eax\n" /* line 4538 | pml */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightFlag\n"
        ".Lf713e6_00071a40:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4539 | pml */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightLerp\n"
        "jmp .Lf713e6_00071946\n"
        ".Lf713e6_00071a57:\n"
        "movl 0xc(%esi), %ecx\n" /* line 4008 */
        "testb $0x20, %cl\n"
        "je .Lf713e6_00071a68\n"
        "orl $0x40000, %ecx\n" /* line 4009 */
        "movl %ecx, 0xc(%esi)\n"
        ".Lf713e6_00071a68:\n"
        "andl $0xffffffdf, %ecx\n" /* line 4011 */
        "movl %ecx, 0xc(%esi)\n"
        "movl $0x3ff, 0x60(%esi)\n" /* line 4546 */
        "movl $0, -0xb8(%ebp)\n" /* line 4547 */
        "movl $0, -0xb4(%ebp)\n" /* line 4549 */
        "movl $0, -0xbc(%ebp)\n" /* line 4551 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl -0x180(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl %eax, 4(%ecx)\n" /* line 184 */
        "movl %eax, 8(%ecx)\n" /* line 185 */
        "leal -0xe8(%ebp), %eax\n" /* line 4555 | pml */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightFlag\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %edx\n" /* line 3972 */
        "movl 0xc(%edx), %eax\n" /* line 3975 */
        "movl %eax, %ecx\n"
        "andb $0xfe, %ch\n"
        "movl %ecx, 0xc(%edx)\n"
        "cmpl $5, 4(%edx)\n" /* line 3977 */
        "jg .Lf713e6_00071ad2\n"
        "testb $0x10, 9(%edi)\n" /* line 3980 */
        "jne .Lf713e6_00072cf4\n"
        /* } scope */
        ".Lf713e6_00071ad2:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4558 | pml */
        "movl %edi, %eax\n"
        "calll PM_CheckDuck\n"
        "movl 0x10(%esi), %eax\n" /* line 3366 */
        "testl %eax, %eax\n"
        "je .Lf713e6_00071af9\n"
        "movl -0xc0(%ebp), %edx\n" /* line 3368 */
        "cmpl %edx, %eax\n"
        "jle .Lf713e6_00072da3\n"
        "subl %edx, %eax\n" /* line 3375 */
        "movl %eax, 0x10(%esi)\n"
        ".Lf713e6_00071af9:\n"
        "movl 0x78(%esi), %edx\n" /* line 3380 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_00071b0e\n"
        "xorl %eax, %eax\n" /* line 3385 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x78(%esi)\n"
        ".Lf713e6_00071b0e:\n"
        "movl 0x80(%esi), %edx\n" /* line 3389 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_00071b29\n"
        "xorl %eax, %eax\n" /* line 3394 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x80(%esi)\n"
        ".Lf713e6_00071b29:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4562 | pml */
        "movl %edi, %eax\n"
        "calll PM_Footsteps\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4564 | pml */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_Weapon\n"
        "jmp .Lf713e6_00071946\n"
        ".Lf713e6_00071b4d:\n"
        "movl 0xc(%esi), %ecx\n" /* line 4008 */
        "testb $0x20, %cl\n"
        "je .Lf713e6_00071b5e\n"
        "orl $0x40000, %ecx\n" /* line 4009 */
        "movl %ecx, 0xc(%esi)\n"
        ".Lf713e6_00071b5e:\n"
        "andl $0xffffffdf, %ecx\n" /* line 4011 */
        "movl %ecx, 0xc(%esi)\n"
        "leal -0xe8(%ebp), %ecx\n" /* line 4505 | pml */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightFlag\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %edx\n" /* line 3972 */
        "movl 0xc(%edx), %eax\n" /* line 3975 */
        "movl %eax, %ecx\n"
        "andb $0xfe, %ch\n"
        "movl %ecx, 0xc(%edx)\n"
        "cmpl $5, 4(%edx)\n" /* line 3977 */
        "jg .Lf713e6_00071b93\n"
        "testb $0x10, 9(%edi)\n" /* line 3980 */
        "jne .Lf713e6_00072ca6\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00071b93:\n"
        "movl (%edi), %ebx\n" /* line 1133 | ps */
        "movl $0x3c, 0xf4(%ebx)\n" /* line 1138 | ps */
        "leal 0x20(%ebx), %eax\n" /* line 1142 | ps */
        "movl %eax, -0x15c(%ebp)\n"
        "movss 0x20(%ebx), %xmm0\n" /* line 324 */
        "leal 0x24(%ebx), %edx\n"
        "movl %edx, -0x154(%ebp)\n"
        "movss 0x24(%ebx), %xmm1\n"
        "leal 0x28(%ebx), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n"
        "movss 0x28(%ebx), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm2\n"
        "ucomiss lit4_002ed5d0, %xmm2\n" /* line 1143 | 1.0f */
        "jb .Lf713e6_00073277\n"
        ".Lf713e6_00071bee:\n"
        "movl imp_friction, %eax\n" /* line 1151 */
        "movl (%eax), %eax\n"
        "movss lit4_002ed600, %xmm1\n" /* 1.5f */
        "mulss 8(%eax), %xmm1\n"
        "movl imp_stopspeed, %eax\n" /* line 1152 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "maxss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n" /* line 1156 */
        "mulss -0xc4(%ebp), %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "maxss %xmm3, %xmm1\n" /* line 1157 */
        "movaps %xmm1, %xmm0\n"
        "divss %xmm2, %xmm0\n" /* line 1159 */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0x20(%ebx), %xmm1\n"
        "movss %xmm1, 0x20(%ebx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 0x24(%ebx), %xmm1\n"
        "movl -0x15c(%ebp), %eax\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 0x28(%ebx), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        ".Lf713e6_00071c62:\n"
        "movsbl 0x1c(%edi), %eax\n" /* line 1164 */
        "cvtsi2ssl %eax, %xmm3\n"
        "movsbl 0x1d(%edi), %eax\n" /* line 1165 */
        "cvtsi2ssl %eax, %xmm2\n"
        "movl 8(%edi), %eax\n" /* line 1168 */
        "pxor %xmm4, %xmm4\n"
        "testb %al, %al\n"
        "jns .Lf713e6_00071c85\n"
        "movss lit4_002ed718, %xmm4\n" /* 127.0f */
        ".Lf713e6_00071c85:\n"
        "testb $0x40, %al\n" /* line 1170 */
        "je .Lf713e6_00071c91\n"
        "subss lit4_002ed718, %xmm4\n" /* line 1171 | 127.0f */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00071c91:\n"
        "cvttss2si %xmm3, %eax\n" /* line 539 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvttss2si %xmm2, %eax\n" /* line 540 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "maxss %xmm1, %xmm0\n"
        "cvttss2si %xmm4, %eax\n" /* line 542 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "maxss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 545 */
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf713e6_00073122\n"
        "jp .Lf713e6_00073122\n"
        "pxor %xmm5, %xmm5\n"
        ".Lf713e6_00071ce6:\n"
        "movl $1, %edx\n" /* line 563 */
        "movl $4, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf713e6_00071cf0:\n"
        "movaps %xmm3, %xmm0\n" /* line 1177 */
        "mulss -0xec(%eax, %ebp), %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss -0xe0(%eax, %ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0xd4(%eax, %ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x4c(%eax, %ebp)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 1176 */
        "jne .Lf713e6_00071cf0\n"
        "movl -0x48(%ebp), %eax\n" /* line 199 | wishvel */
        "movl %eax, -0x3c(%ebp)\n" /* wishdir */
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x40(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x34(%ebp)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 1180 | wishdir */
        "movl %eax, (%esp)\n"
        "movss %xmm5, -0x1e8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x158(%ebp)\n" /* wishspeed */
        "movss lit4_002ed728, %xmm1\n" /* line 1183 | 9.0f */
        "movss -0x1e8(%ebp), %xmm5\n"
        "movss -0x158(%ebp), %xmm0\n" /* wishspeed */
        "mulss %xmm5, %xmm0\n"
        "leal -0x3c(%ebp), %ecx\n" /* wishdir */
        "leal -0xe8(%ebp), %edx\n" /* pml */
        "movl %ebx, %eax\n" /* ps */
        "calll PM_Accelerate\n"
        "movss -0xc4(%ebp), %xmm1\n" /* line 1186 | scale */
        "leal 0x14(%ebx), %eax\n" /* ps, result */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "movl -0x15c(%ebp), %edx\n"
        "mulss (%edx), %xmm0\n"
        "addss 0x14(%ebx), %xmm0\n"
        "movss %xmm0, 0x14(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "movl -0x154(%ebp), %ecx\n"
        "mulss (%ecx), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movl -0x150(%ebp), %edx\n" /* line 290 */
        "mulss (%edx), %xmm1\n"
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_00071dc7:\n"
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        /* } scope */
        "movl 0x10(%esi), %eax\n" /* line 3366 */
        "testl %eax, %eax\n"
        "je .Lf713e6_00071df4\n"
        "movl -0xc0(%ebp), %edx\n" /* line 3368 */
        "cmpl %edx, %eax\n"
        "jg .Lf713e6_00072b6e\n"
        "andl $0xfff7f9ff, 0xc(%esi)\n" /* line 3370 */
        "movl $0, 0x10(%esi)\n" /* line 3371 */
        ".Lf713e6_00071df4:\n"
        "movl 0x78(%esi), %edx\n" /* line 3380 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_00071e09\n"
        "xorl %eax, %eax\n" /* line 3385 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x78(%esi)\n"
        ".Lf713e6_00071e09:\n"
        "movl 0x80(%esi), %edx\n" /* line 3389 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_00071e24\n"
        "xorl %eax, %eax\n" /* line 3394 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x80(%esi)\n"
        ".Lf713e6_00071e24:\n"
        "leal -0xe8(%ebp), %ecx\n" /* line 4520 | pml */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightLerp\n"
        "jmp .Lf713e6_00071946\n"
        ".Lf713e6_00071e3b:\n"
        "movl 0xc(%esi), %ecx\n" /* line 4008 */
        "testb $0x20, %cl\n"
        "je .Lf713e6_00071e4c\n"
        "orl $0x40000, %ecx\n" /* line 4009 */
        "movl %ecx, 0xc(%esi)\n"
        ".Lf713e6_00071e4c:\n"
        "andl $0xffffffdf, %ecx\n" /* line 4011 */
        "movl %ecx, 0xc(%esi)\n"
        "leal -0xe8(%ebp), %eax\n" /* line 4515 | pml */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightFlag\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %edx\n" /* line 3972 */
        "movl 0xc(%edx), %eax\n" /* line 3975 */
        "movl %eax, %ecx\n"
        "andb $0xfe, %ch\n"
        "movl %ecx, 0xc(%edx)\n"
        "cmpl $5, 4(%edx)\n" /* line 3977 */
        "jg .Lf713e6_00071e81\n"
        "testb $0x10, 9(%edi)\n" /* line 3980 */
        "jne .Lf713e6_00072c58\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00071e81:\n"
        "movl (%edi), %ebx\n" /* line 1211 | ps */
        "movl $0x3c, 0xf4(%ebx)\n" /* line 1216 | ps */
        "movsbl 0x1c(%edi), %eax\n" /* line 1218 */
        "cvtsi2ssl %eax, %xmm3\n"
        "movsbl 0x1d(%edi), %eax\n" /* line 1219 */
        "cvtsi2ssl %eax, %xmm4\n"
        "movl 8(%edi), %eax\n" /* line 1228 */
        "pxor %xmm5, %xmm5\n"
        "testb %al, %al\n"
        "jns .Lf713e6_00071eb0\n"
        "movss lit4_002ed718, %xmm5\n" /* 127.0f */
        ".Lf713e6_00071eb0:\n"
        "testb $0x40, %al\n" /* line 1230 */
        "je .Lf713e6_00071ebc\n"
        "subss lit4_002ed718, %xmm5\n" /* line 1231 | 127.0f */
        ".Lf713e6_00071ebc:\n"
        "pxor %xmm0, %xmm0\n" /* line 1235 */
        "ucomiss %xmm0, %xmm3\n"
        "jne .Lf713e6_00071ed0\n"
        "jp .Lf713e6_00071ed0\n"
        "ucomiss %xmm0, %xmm4\n"
        "je .Lf713e6_00072b8d\n"
        ".Lf713e6_00071ed0:\n"
        "leal 0x20(%ebx), %eax\n" /* line 1239 | ps */
        "movl %eax, -0x184(%ebp)\n"
        "movss 0x20(%ebx), %xmm0\n" /* line 324 */
        "movss 0x24(%ebx), %xmm1\n"
        "movss 0x28(%ebx), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm2\n"
        "ucomiss lit4_002ed5d0, %xmm2\n" /* line 1241 | 1.0f */
        "jb .Lf713e6_00073672\n"
        ".Lf713e6_00071f0d:\n"
        "movl imp_friction, %eax\n" /* line 1249 */
        "movl (%eax), %eax\n"
        "movss lit4_002ed600, %xmm1\n" /* 1.5f */
        "mulss 8(%eax), %xmm1\n"
        "movl imp_stopspeed, %eax\n" /* line 1250 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "maxss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n" /* line 1254 */
        "mulss -0xc4(%ebp), %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "pxor %xmm1, %xmm1\n" /* line 1256 */
        "maxss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "divss %xmm2, %xmm0\n" /* line 1258 */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0x20(%ebx), %xmm1\n"
        "movss %xmm1, 0x20(%ebx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 0x24(%ebx), %xmm1\n"
        "movl -0x184(%ebp), %eax\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 0x28(%ebx), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00071f88:\n"
        "cvttss2si %xmm3, %eax\n" /* line 539 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "cvttss2si %xmm4, %eax\n" /* line 540 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "maxss %xmm1, %xmm0\n"
        "cvttss2si %xmm5, %eax\n" /* line 542 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "maxss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 545 */
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf713e6_000731a3\n"
        "jp .Lf713e6_000731a3\n"
        "pxor %xmm2, %xmm2\n"
        /* } scope */
        /* } scope */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_00071fdd:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 1269 */
        "movl $0, -0x30(%ebp)\n" /* up */
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 1270 */
        "leal -0x24(%ebp), %eax\n" /* line 1271 | forward */
        "movl %eax, 8(%esp)\n"
        "leal -0xdc(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x30(%ebp), %ecx\n" /* up */
        "movl %ecx, (%esp)\n"
        "movss %xmm2, -0x1b8(%ebp)\n"
        "movss %xmm3, -0x1c8(%ebp)\n"
        "movss %xmm4, -0x1d8(%ebp)\n"
        "movss %xmm5, -0x1e8(%ebp)\n"
        "calll Vec3Cross\n"
        "movl $1, %edx\n"
        "movss -0x1e8(%ebp), %xmm5\n"
        "movss -0x1d8(%ebp), %xmm4\n"
        "movss -0x1c8(%ebp), %xmm3\n"
        "movss -0x1b8(%ebp), %xmm2\n"
        ".Lf713e6_00072053:\n"
        "leal (, %edx, 4), %eax\n" /* line 1274 */
        "movaps %xmm3, %xmm0\n"
        "mulss -0x28(%ebp, %eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0xe0(%ebp, %eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss -0x34(%ebp, %eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%ebp, %eax)\n"
        "addl $1, %edx\n"
        "cmpl $4, %edx\n" /* line 1273 */
        "jne .Lf713e6_00072053\n"
        /* } scope */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | wishdir */
        "movl %eax, -0x48(%ebp)\n" /* wishvel */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        "leal -0x48(%ebp), %eax\n" /* line 1278 | wishvel */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x1b8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x14c(%ebp)\n" /* wishspeed */
        "movss lit4_002ed728, %xmm1\n" /* line 1281 | 9.0f */
        "movss -0x1b8(%ebp), %xmm2\n"
        "movss -0x14c(%ebp), %xmm0\n" /* wishspeed */
        "mulss %xmm2, %xmm0\n"
        "leal -0x48(%ebp), %ecx\n" /* wishvel */
        "leal -0xe8(%ebp), %edx\n" /* pml */
        "movl %ebx, %eax\n" /* ps */
        "calll PM_Accelerate\n"
        "movss -0xc4(%ebp), %xmm1\n" /* line 1284 | scale */
        "leal 0x14(%ebx), %eax\n" /* ps, result */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x20(%ebx), %xmm0\n"
        "addss 0x14(%ebx), %xmm0\n"
        "movss %xmm0, 0x14(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "movl -0x184(%ebp), %edx\n"
        "mulss 4(%edx), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%edx), %xmm1\n" /* line 290 */
        "jmp .Lf713e6_00071dc7\n"
        /* } scope */
        /* } scope */
        ".Lf713e6_00072124:\n"
        "movl 0xc(%esi), %ecx\n" /* line 4008 */
        "testb $0x20, %cl\n"
        "je .Lf713e6_00072135\n"
        "orl $0x40000, %ecx\n" /* line 4009 */
        "movl %ecx, 0xc(%esi)\n"
        ".Lf713e6_00072135:\n"
        "andl $0xffffffdf, %ecx\n" /* line 4011 */
        "movl %ecx, 0xc(%esi)\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4493 | pml */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightFlag\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %edx\n" /* line 3972 */
        "movl 0xc(%edx), %eax\n" /* line 3975 */
        "movl %eax, %ecx\n"
        "andb $0xfe, %ch\n"
        "movl %ecx, 0xc(%edx)\n"
        "cmpl $5, 4(%edx)\n" /* line 3977 */
        "jg .Lf713e6_0007216a\n"
        "testb $0x10, 9(%edi)\n" /* line 3980 */
        "jne .Lf713e6_00072d42\n"
        /* } scope */
        ".Lf713e6_0007216a:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4496 | pml */
        "movl %edi, %eax\n"
        "calll PM_CheckDuck\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %ecx\n" /* line 853 */
        "movl %ecx, -0x160(%ebp)\n" /* ps */
        "leal -0xe8(%ebp), %edx\n" /* line 857 | pml */
        "movl %ecx, %eax\n"
        "calll PM_Friction\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        "movl -0x188(%ebp), %eax\n" /* line 586 */
        "movsbl 0x18(%eax), %ebx\n"
        "movsbl 0x19(%eax), %edx\n"
        "movl %ebx, %eax\n" /* line 81 */
        "imull %ebx, %eax\n"
        "movl %edx, %ecx\n"
        "imull %edx, %ecx\n"
        "addl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "movl %ebx, %ecx\n" /* line 587 */
        "movl %ebx, %eax\n"
        "negl %eax\n"
        "cmpl $-1, %ebx\n"
        "cmovlel %eax, %ecx\n"
        "movl %edx, %eax\n" /* line 588 */
        "negl %eax\n"
        "cmpl $-1, %edx\n"
        "cmovlel %eax, %edx\n"
        "cmpl %edx, %ecx\n"
        "cmovll %edx, %ecx\n"
        "testl %ecx, %ecx\n" /* line 591 */
        "je .Lf713e6_0007223d\n"
        "movl -0x160(%ebp), %edx\n" /* line 594 | ps */
        "cvtsi2ssl 0x50(%edx), %xmm2\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "mulss lit4_002ed718, %xmm1\n" /* 127.0f */
        "divss %xmm1, %xmm2\n"
        "testb $1, 0xd(%edx)\n" /* line 596 */
        "je .Lf713e6_00072c3f\n"
        ".Lf713e6_000721f6:\n"
        "mulss lit4_002ed71c, %xmm2\n" /* line 597 | 0.4000000059604645f */
        ".Lf713e6_000721fe:\n"
        "movl -0x160(%ebp), %edx\n" /* line 601 | ps */
        "movl 4(%edx), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lf713e6_0007368a\n"
        "cmpl $3, %eax\n" /* line 603 */
        "je .Lf713e6_00073807\n"
        "cmpl $4, %eax\n" /* line 606 */
        "jne .Lf713e6_0007222a\n"
        "movl imp_player_spectateSpeedScale, %eax\n" /* line 607 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm2\n"
        /* } scope */
        ".Lf713e6_0007222a:\n"
        "pxor %xmm0, %xmm0\n" /* line 864 */
        "ucomiss %xmm0, %xmm2\n"
        "jne .Lf713e6_00073224\n"
        "jp .Lf713e6_00073224\n"
        ".Lf713e6_0007223d:\n"
        "movl $0, -0x3c(%ebp)\n" /* line 866 | wishdir */
        "movl $0, -0x38(%ebp)\n" /* line 867 */
        "movl $0, -0x34(%ebp)\n" /* line 868 */
        ".Lf713e6_00072252:\n"
        "movl -0x160(%ebp), %edx\n" /* line 876 | ps */
        "movl 0x50(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf713e6_000722e7\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        "cvtsi2ssl %eax, %xmm1\n" /* line 550 */
        "movss lit4_002ed718, %xmm2\n" /* 127.0f */
        "mulss %xmm2, %xmm1\n"
        "divss lit4_002ed7ac, %xmm1\n" /* 16129.0f */
        "testb $1, 0xd(%edx)\n" /* line 552 */
        "je .Lf713e6_00072db6\n"
        ".Lf713e6_00072285:\n"
        "mulss lit4_002ed71c, %xmm1\n" /* line 553 | 0.4000000059604645f */
        ".Lf713e6_0007228d:\n"
        "movl -0x160(%ebp), %edx\n" /* line 557 | ps */
        "movl 4(%edx), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lf713e6_0007367d\n"
        "cmpl $3, %eax\n" /* line 559 */
        "je .Lf713e6_000737fa\n"
        "cmpl $4, %eax\n" /* line 562 */
        "jne .Lf713e6_000722b9\n"
        "movl imp_player_spectateSpeedScale, %eax\n" /* line 563 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm1\n"
        /* } scope */
        ".Lf713e6_000722b9:\n"
        "movl 8(%edi), %eax\n" /* line 879 */
        "testb $0x40, %al\n"
        "je .Lf713e6_000722d5\n"
        "movaps %xmm1, %xmm0\n" /* line 880 */
        "mulss lit4_002ed7b0, %xmm0\n" /* -127.0f */
        "addss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        ".Lf713e6_000722d5:\n"
        "testb %al, %al\n" /* line 881 */
        "jns .Lf713e6_000722e7\n"
        "mulss %xmm2, %xmm1\n" /* line 882 */
        "addss -0x34(%ebp), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        ".Lf713e6_000722e7:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 199 | wishdir */
        "movl %eax, -0x48(%ebp)\n" /* wishvel */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        "leal -0x48(%ebp), %ecx\n" /* line 886 | wishvel */
        "movl %ecx, (%esp)\n"
        "calll Vec3Normalize\n"
        "movss lit4_002ed740, %xmm1\n" /* line 888 | 8.0f */
        "fstps -0x1fc(%ebp)\n"
        "movss -0x1fc(%ebp), %xmm0\n"
        "leal -0x48(%ebp), %ecx\n" /* wishvel */
        "leal -0xe8(%ebp), %edx\n" /* pml */
        "movl -0x160(%ebp), %eax\n" /* ps */
        "calll PM_Accelerate\n"
        "movl $0, 8(%esp)\n" /* line 890 */
        "leal -0xe8(%ebp), %eax\n" /* pml */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_StepSlideMove\n"
        /* } scope */
        "movl 0x10(%esi), %eax\n" /* line 3366 */
        "testl %eax, %eax\n"
        "je .Lf713e6_00072362\n"
        "movl -0xc0(%ebp), %edx\n" /* line 3368 */
        "cmpl %edx, %eax\n"
        "jle .Lf713e6_00072d90\n"
        "subl %edx, %eax\n" /* line 3375 */
        "movl %eax, 0x10(%esi)\n"
        ".Lf713e6_00072362:\n"
        "movl 0x78(%esi), %edx\n" /* line 3380 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_00072377\n"
        "xorl %eax, %eax\n" /* line 3385 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x78(%esi)\n"
        ".Lf713e6_00072377:\n"
        "movl 0x80(%esi), %edx\n" /* line 3389 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_00071a40\n"
        "xorl %eax, %eax\n" /* line 3394 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x80(%esi)\n"
        "jmp .Lf713e6_00071a40\n"
        ".Lf713e6_0007239b:\n"
        "andl $0xfff7f9ff, 0xc(%esi)\n" /* line 3370 */
        "movl $0, 0x10(%esi)\n" /* line 3371 */
        "jmp .Lf713e6_000717e6\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_000723ae:\n"
        "testb $1, %al\n" /* line 3983 */
        "jne .Lf713e6_000717bf\n"
        "testb $0x40, %al\n" /* line 3986 */
        "je .Lf713e6_000717bf\n"
        "movl 0xd8(%edx), %eax\n" /* line 3992 */
        "cmpl $5, %eax\n"
        "je .Lf713e6_000717bf\n"
        "cmpl $7, %eax\n"
        "je .Lf713e6_000717bf\n"
        "cmpl $9, %eax\n"
        "je .Lf713e6_000717bf\n"
        "cmpl $8, %eax\n"
        "je .Lf713e6_000717bf\n"
        "cmpl $6, %eax\n"
        "je .Lf713e6_000717bf\n"
        "orb $1, %ch\n" /* line 3996 */
        "movl %ecx, 0xc(%edx)\n"
        "jmp .Lf713e6_000717bf\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf713e6_000723fc:\n"
        "movl %edx, %eax\n" /* line 4706 */
        "subl $0x3e8, %eax\n"
        "movl %eax, (%ecx)\n"
        "jmp .Lf713e6_0007141f\n"
        /* { scope 2: pml */
        /* { scope 3: wishvel, wishdir, wishspeed, wishspeed, ... */
        ".Lf713e6_0007240a:\n"
        "cmpl $5, %eax\n" /* line 4378 */
        "jne .Lf713e6_00071547\n"
        "jmp .Lf713e6_00071848\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072418:\n"
        "testb $1, %al\n" /* line 3983 */
        "jne .Lf713e6_00071911\n"
        "testb $0x40, %al\n" /* line 3986 */
        "je .Lf713e6_00071911\n"
        "movl 0xd8(%edx), %eax\n" /* line 3992 */
        "cmpl $5, %eax\n"
        "je .Lf713e6_00071911\n"
        "cmpl $7, %eax\n"
        "je .Lf713e6_00071911\n"
        "cmpl $9, %eax\n"
        "je .Lf713e6_00071911\n"
        "cmpl $8, %eax\n"
        "je .Lf713e6_00071911\n"
        "cmpl $6, %eax\n"
        "je .Lf713e6_00071911\n"
        "orb $1, %ch\n" /* line 3996 */
        "movl %ecx, 0xc(%edx)\n"
        "jmp .Lf713e6_00071911\n"
        /* } scope */
        ".Lf713e6_00072466:\n"
        "leal -0xe8(%ebp), %ecx\n" /* line 4617 | pml */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdateAimDownSightFlag\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %edx\n" /* line 3972 */
        "movl 0xc(%edx), %eax\n" /* line 3975 */
        "movl %eax, %ecx\n"
        "andb $0xfe, %ch\n"
        "movl %ecx, 0xc(%edx)\n"
        "cmpl $5, 4(%edx)\n" /* line 3977 */
        "jg .Lf713e6_00072495\n"
        "testb $0x10, 9(%edi)\n" /* line 3980 */
        "jne .Lf713e6_00072bf1\n"
        /* } scope */
        ".Lf713e6_00072495:\n"
        "leal -0xe8(%ebp), %eax\n" /* line 4621 | pml */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_UpdatePronePitch\n"
        "cmpl $6, 4(%esi)\n" /* line 4623 */
        "je .Lf713e6_00073076\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_000724b1:\n"
        "movl (%edi), %ebx\n" /* line 4035 | ps */
        "movl -0xbc(%ebp), %eax\n" /* line 4038 */
        "testl %eax, %eax\n"
        "je .Lf713e6_00072b66\n"
        "movl 0xc(%ebx), %edx\n" /* line 4039 | ps */
        "andl $0xfffbffff, %edx\n"
        "movl %edx, 0xc(%ebx)\n" /* ps */
        ".Lf713e6_000724cd:\n"
        "movl 0x10(%ebx), %eax\n" /* line 4041 | ps */
        "testl %eax, %eax\n"
        "je .Lf713e6_00072679\n"
        "testb $6, %dh\n" /* line 4043 */
        "je .Lf713e6_00072679\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_000724e1:\n"
        "movl 0x10(%esi), %eax\n" /* line 3366 */
        "testl %eax, %eax\n"
        "jne .Lf713e6_00072727\n"
        ".Lf713e6_000724ec:\n"
        "movl 0xc(%esi), %ecx\n"
        ".Lf713e6_000724ef:\n"
        "movl 0x78(%esi), %edx\n" /* line 3380 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_00072504\n"
        "xorl %eax, %eax\n" /* line 3385 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x78(%esi)\n"
        ".Lf713e6_00072504:\n"
        "movl 0x80(%esi), %edx\n" /* line 3389 */
        "testl %edx, %edx\n"
        "jle .Lf713e6_0007251f\n"
        "xorl %eax, %eax\n" /* line 3394 */
        "subl -0xc0(%ebp), %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, 0x80(%esi)\n"
        /* } scope */
        ".Lf713e6_0007251f:\n"
        "andb $0x20, %cl\n" /* line 4631 */
        "jne .Lf713e6_00073064\n"
        "movl -0xbc(%ebp), %ebx\n" /* line 4633 | stance */
        "testl %ebx, %ebx\n" /* stance */
        "je .Lf713e6_00072742\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %ebx\n" /* line 978 */
        "testb $8, 0xe(%ebx)\n" /* line 981 */
        "jne .Lf713e6_00072dcf\n"
        ".Lf713e6_00072542:\n"
        "leal -0xe8(%ebp), %ecx\n" /* line 984 | pml */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Jump_Check\n"
        "testb %al, %al\n"
        "jne .Lf713e6_00072742\n"
        "leal -0xe8(%ebp), %edx\n" /* line 990 | pml */
        "movl %ebx, %eax\n"
        "calll PM_Friction\n"
        "movzbl 0x1c(%edi), %ecx\n" /* line 992 */
        "movsbl %cl, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x114(%ebp)\n" /* fmove */
        "movsbl 0x1d(%edi), %edx\n" /* line 993 */
        "movsbl %dl, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss %xmm1, -0x110(%ebp)\n" /* smove */
        "movl 4(%edi), %eax\n" /* line 995 */
        "movl %eax, -0xf4(%ebp)\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0xf8(%ebp)\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        "movl (%edi), %eax\n" /* line 636 */
        "movl %eax, -0x10c(%ebp)\n" /* ps */
        "movsbl %cl, %eax\n" /* line 639 */
        "imull %eax, %eax\n" /* line 81 */
        "imull %edx, %edx\n"
        "addl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "sqrtss %xmm0, %xmm3\n"
        "testb %cl, %cl\n" /* line 640 */
        "js .Lf713e6_0007385e\n"
        "movss CorrectSolidDeltas+560, %xmm7\n" /* line 54 */
        "movss -0x114(%ebp), %xmm2\n" /* fmove */
        "andps %xmm7, %xmm2\n"
        ".Lf713e6_000725d7:\n"
        "movl imp_player_strafeSpeedScale, %eax\n"
        "movl (%eax), %eax\n"
        "movss -0x110(%ebp), %xmm1\n" /* smove */
        "mulss 8(%eax), %xmm1\n"
        "andps %xmm7, %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "pxor %xmm5, %xmm5\n"
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm5, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "ucomiss %xmm5, %xmm1\n" /* line 647 */
        "jne .Lf713e6_0007369f\n"
        "jp .Lf713e6_0007369f\n"
        "pxor %xmm2, %xmm2\n"
        /* } scope */
        ".Lf713e6_00072620:\n"
        "movl 0x90(%ebx), %edx\n" /* line 1000 | damage_timer */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        "testl %edx, %edx\n" /* line 707 */
        "je .Lf713e6_0007329f\n"
        "movl imp_player_dmgtimer_maxTime, %eax\n" /* line 710 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "pxor %xmm1, %xmm1\n" /* line 711 */
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf713e6_00072649\n"
        "jnp .Lf713e6_0007329f\n"
        ".Lf713e6_00072649:\n"
        "movl imp_player_dmgtimer_minScale, %eax\n" /* line 719 */
        "movl (%eax), %eax\n"
        "movss CorrectSolidDeltas+576, %xmm6\n"
        "movss 8(%eax), %xmm1\n"
        "xorps %xmm6, %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "jmp .Lf713e6_000732af\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072679:\n"
        "movl -0xbc(%ebp), %eax\n" /* line 4047 */
        "testl %eax, %eax\n"
        "je .Lf713e6_00072b78\n"
        "movss lit4_002ed740, %xmm0\n" /* 8.0f */
        "movss %xmm0, -0x128(%ebp)\n" /* scale */
        ".Lf713e6_00072697:\n"
        "andb $0x20, %dl\n" /* line 4052 */
        "je .Lf713e6_000726a9\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* ps */
        "je .Lf713e6_000737bc\n"
        ".Lf713e6_000726a9:\n"
        "movl -0xe8(%ebp), %eax\n" /* line 4061 | pml */
        "movl %eax, -0x30(%ebp)\n" /* up */
        "movl -0xe4(%ebp), %eax\n" /* line 4062 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n" /* line 4063 */
        "leal -0x30(%ebp), %eax\n" /* line 4064 | up */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movb $0, -0x145(%ebp)\n"
        ".Lf713e6_000726d6:\n"
        "cmpl $5, 4(%ebx)\n" /* line 4067 | ps */
        "jle .Lf713e6_00072ddc\n"
        "movl $0x3ff, 0x60(%ebx)\n" /* line 4069 | ps */
        "movl $0, -0xb8(%ebp)\n" /* line 4070 */
        "movl $0, -0xb4(%ebp)\n" /* line 4072 */
        "movl $0, -0xbc(%ebp)\n" /* line 4074 */
        "movl 0xc(%ebx), %edx\n" /* line 4008 | ps */
        ".Lf713e6_00072708:\n"
        "testb $0x20, %dl\n"
        "je .Lf713e6_00072716\n"
        "orl $0x40000, %edx\n" /* line 4009 */
        "movl %edx, 0xc(%ebx)\n" /* ps */
        ".Lf713e6_00072716:\n"
        "andl $0xffffffdf, %edx\n" /* line 4011 */
        "movl %edx, 0xc(%ebx)\n" /* ps */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl 0x10(%esi), %eax\n" /* line 3366 */
        "testl %eax, %eax\n"
        "je .Lf713e6_000724ec\n"
        ".Lf713e6_00072727:\n"
        "movl -0xc0(%ebp), %edx\n" /* line 3368 */
        "cmpl %edx, %eax\n"
        "jle .Lf713e6_00072bd9\n"
        "subl %edx, %eax\n" /* line 3375 */
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %ecx\n"
        "jmp .Lf713e6_000724ef\n"
        /* } scope */
        ".Lf713e6_00072742:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4636 | pml */
        "movl %edi, %eax\n"
        "calll PM_AirMove\n"
        ".Lf713e6_0007274f:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4639 | pml */
        "movl %edi, %eax\n"
        "calll PM_GroundTrace\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4642 | pml */
        "movl %edi, %eax\n"
        "calll PM_Footsteps\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4645 | pml */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_Weapon\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movl (%edi), %ebx\n" /* line 3321 | ps */
        "movss 0xdc(%edi), %xmm1\n" /* line 3324 */
        "movl imp_bg_foliagesnd_minspeed, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf713e6_00072954\n"
        "movl imp_bg_foliagesnd_resetinterval, %eax\n" /* line 3327 */
        "movl (%eax), %edx\n"
        "movl 0x44(%ebx), %eax\n" /* ps */
        "addl 8(%edx), %eax\n"
        "cmpl 4(%edi), %eax\n"
        "jl .Lf713e6_00072bcd\n"
        /* } scope */
        ".Lf713e6_000727b0:\n"
        "movl -0x174(%ebp), %eax\n" /* line 248 */
        "movss (%eax), %xmm0\n"
        "subss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, -0xf0(%ebp)\n"
        "movl -0x170(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm5\n"
        "subss -0x84(%ebp), %xmm5\n"
        "movl -0x16c(%ebp), %edx\n" /* line 250 */
        "movss (%edx), %xmm6\n"
        "subss -0x80(%ebp), %xmm6\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 4658 */
        "movss %xmm0, -0x18c(%ebp)\n"
        "movl -0x180(%ebp), %eax\n" /* line 316 */
        "movss (%eax), %xmm4\n"
        "movl -0x168(%ebp), %edx\n"
        "movss (%edx), %xmm7\n"
        "movl -0x164(%ebp), %ecx\n"
        "movss (%ecx), %xmm3\n"
        "movss -0xf0(%ebp), %xmm2\n" /* line 4660 */
        "mulss %xmm2, %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -0x18c(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "movaps %xmm7, %xmm1\n"
        "mulss %xmm7, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "mulss lit4_002ed604, %xmm0\n" /* 0.25f */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf713e6_00072947\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 4661 | 1.0f, scale */
        "divss -0x18c(%ebp), %xmm0\n" /* scale */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movss -0xf0(%ebp), %xmm1\n" /* line 272 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "mulss %xmm0, %xmm5\n" /* line 273 */
        "movss %xmm5, 4(%eax)\n"
        "mulss %xmm0, %xmm6\n" /* line 274 */
        "movss %xmm6, 8(%eax)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "movss %xmm0, -0x18c(%ebp)\n"
        "movaps %xmm1, %xmm4\n"
        "movss (%edx), %xmm7\n"
        "movaps %xmm0, %xmm2\n"
        /* } scope */
        ".Lf713e6_000728c2:\n"
        "subss 0x2c(%esi), %xmm4\n" /* line 65 */
        "subss 0x30(%esi), %xmm7\n" /* line 66 */
        "movss lit4_002ed5d0, %xmm0\n" /* line 45 | 1.0f */
        "subss -0x18c(%ebp), %xmm0\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm2, %xmm1\n"
        "cmpnltss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n" /* line 58 */
        "addss 0x2c(%esi), %xmm4\n"
        "movss %xmm4, 0x2c(%esi)\n"
        "mulss %xmm7, %xmm0\n" /* line 59 */
        "addss 0x30(%esi), %xmm0\n"
        "movss %xmm0, 0x30(%esi)\n"
        "movl -0x180(%ebp), %eax\n" /* line 4671 */
        "movl %eax, (%esp)\n"
        "calll Sys_SnapVector\n"
        "jmp .Lf713e6_00071946\n"
        ".Lf713e6_00072928:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4594 | pml */
        "movl %edi, %eax\n"
        "calll PM_CheckDuck\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4597 | pml */
        "movl %edi, %eax\n"
        "calll PM_GroundTrace\n"
        "jmp .Lf713e6_00071895\n"
        ".Lf713e6_00072947:\n"
        "movss -0x18c(%ebp), %xmm2\n"
        "jmp .Lf713e6_000728c2\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072954:\n"
        "subss %xmm2, %xmm1\n" /* line 3333 */
        "movl imp_bg_foliagesnd_maxspeed, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 3334 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movl imp_bg_foliagesnd_slowinterval, %eax\n" /* line 3336 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_bg_foliagesnd_fastinterval, %eax\n" /* line 3338 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "addl 0x44(%ebx), %eax\n" /* ps */
        "cmpl 4(%edi), %eax\n"
        "jge .Lf713e6_000727b0\n"
        "leal 0xc4(%edi), %eax\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        "movss lit4_002ed67c, %xmm0\n" /* line 272 | 0.75f */
        "movss 0xc4(%edi), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n" /* wishvel */
        "movss 4(%eax), %xmm1\n" /* line 273 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 274 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        /* } scope */
        "movss 0xd0(%edi), %xmm1\n" /* line 272 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* wishdir */
        "mulss 0xd4(%edi), %xmm0\n" /* line 273 */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss lit4_002ed7b8, %xmm0\n" /* line 3343 | 0.8999999761581421f */
        "mulss 0xd8(%edi), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl 0xcc(%ebx), %eax\n" /* line 3344 | ps */
        "movl %eax, -0x104(%ebp)\n" /* passEntityNum */
        "leal 0x14(%ebx), %edx\n" /* ps */
        "movl %edx, -0x108(%ebp)\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        "movzbl 0xe4(%edi), %eax\n" /* line 262 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl $2, 0x18(%esp)\n"
        "movl -0x104(%ebp), %ecx\n" /* passEntityNum */
        "movl %ecx, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* wishdir */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x48(%ebp), %ecx\n" /* wishvel */
        "movl %ecx, 8(%esp)\n"
        "movl -0x108(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x6c(%ebp), %ecx\n" /* trace */
        "movl %ecx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x49(%ebp)\n" /* line 264 */
        "je .Lf713e6_00072b39\n"
        "testb $2, -0x55(%ebp)\n" /* line 268 */
        "je .Lf713e6_00072b39\n"
        "movl -0x50(%ebp), %eax\n" /* line 271 */
        "movzwl %ax, %edx\n"
        "movl %edx, -0x100(%ebp)\n" /* entityNum */
        /* { scope 6: i, i, ps, i */
        /* { scope 7 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf713e6_00072ae7\n"
        "movl 0x40(%edi), %ecx\n" /* line 303 */
        "cmpl $0x20, %ecx\n"
        "je .Lf713e6_00072ae7\n"
        "testl %ecx, %ecx\n" /* line 309 */
        "jle .Lf713e6_00073974\n"
        "movl -0x100(%ebp), %edx\n" /* line 311 | entityNum */
        "cmpl %edx, 0x44(%edi)\n"
        "je .Lf713e6_00072ae7\n"
        "movl %edi, %edx\n"
        "movl $0, -0xfc(%ebp)\n" /* i */
        ".Lf713e6_00072ac6:\n"
        "addl $1, -0xfc(%ebp)\n" /* line 309 | i */
        "cmpl -0xfc(%ebp), %ecx\n" /* i */
        "je .Lf713e6_00073974\n"
        "movl 0x48(%edx), %eax\n" /* line 311 */
        "addl $4, %edx\n"
        "cmpl -0x100(%ebp), %eax\n" /* entityNum */
        "jne .Lf713e6_00072ac6\n"
        /* } scope */
        /* } scope */
        ".Lf713e6_00072ae7:\n"
        "andl $0xfdffffff, 0x3c(%edi)\n" /* line 272 */
        "movzbl 0xe4(%edi), %eax\n" /* line 273 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl $2, 0x18(%esp)\n"
        "movl -0x104(%ebp), %edx\n" /* passEntityNum */
        "movl %edx, 0x14(%esp)\n"
        "movl -0x108(%ebp), %ecx\n"
        "movl %ecx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* wishdir */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x48(%ebp), %ecx\n" /* wishvel */
        "movl %ecx, 8(%esp)\n"
        "movl -0x108(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x6c(%ebp), %ecx\n" /* trace */
        "movl %ecx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        /* } scope */
        ".Lf713e6_00072b39:\n"
        "cmpb $0, -0x49(%ebp)\n" /* line 3345 */
        "je .Lf713e6_000727b0\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        "movl %ebx, 8(%esp)\n" /* line 285 */
        "movl $0, 4(%esp)\n"
        "movl $0x8b, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        /* } scope */
        "movl 4(%edi), %eax\n" /* line 3350 */
        "movl %eax, 0x44(%ebx)\n" /* ps */
        "jmp .Lf713e6_000727b0\n"
        ".Lf713e6_00072b66:\n"
        "movl 0xc(%ebx), %edx\n" /* ps */
        "jmp .Lf713e6_000724cd\n"
        /* } scope */
        ".Lf713e6_00072b6e:\n"
        "subl %edx, %eax\n" /* line 3375 */
        "movl %eax, 0x10(%esi)\n"
        "jmp .Lf713e6_00071df4\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072b78:\n"
        "movss lit4_002ed7b4, %xmm1\n" /* line 4047 | 30.0f */
        "movss %xmm1, -0x128(%ebp)\n" /* scale */
        "jmp .Lf713e6_00072697\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072b8d:\n"
        "jp .Lf713e6_00071ed0\n" /* line 1235 */
        "ucomiss %xmm0, %xmm5\n"
        "jp .Lf713e6_00071ed0\n"
        "jne .Lf713e6_00071ed0\n"
        "leal 0x20(%ebx), %edx\n" /* ps */
        "movl %edx, -0x184(%ebp)\n"
        ".Lf713e6_00072bab:\n"
        "movl imp_vec3_origin, %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, 0x20(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl -0x184(%ebp), %ecx\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "jmp .Lf713e6_00071f88\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072bcd:\n"
        "movl $0, 0x44(%ebx)\n" /* line 3328 | ps */
        "jmp .Lf713e6_000727b0\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072bd9:\n"
        "movl 0xc(%esi), %ecx\n" /* line 3370 */
        "andl $0xfff7f9ff, %ecx\n"
        "movl %ecx, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 3371 */
        "jmp .Lf713e6_000724ef\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072bf1:\n"
        "testb $1, %al\n" /* line 3983 */
        "jne .Lf713e6_00072495\n"
        "testb $0x40, %al\n" /* line 3986 */
        "je .Lf713e6_00072495\n"
        "movl 0xd8(%edx), %eax\n" /* line 3992 */
        "cmpl $5, %eax\n"
        "je .Lf713e6_00072495\n"
        "cmpl $7, %eax\n"
        "je .Lf713e6_00072495\n"
        "cmpl $9, %eax\n"
        "je .Lf713e6_00072495\n"
        "cmpl $8, %eax\n"
        "je .Lf713e6_00072495\n"
        "cmpl $6, %eax\n"
        "je .Lf713e6_00072495\n"
        "orb $1, %ch\n" /* line 3996 */
        "movl %ecx, 0xc(%edx)\n"
        "jmp .Lf713e6_00072495\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_00072c3f:\n"
        "pxor %xmm0, %xmm0\n" /* line 596 */
        "ucomiss 0x4c(%edx), %xmm0\n"
        "jp .Lf713e6_000721f6\n"
        "je .Lf713e6_000721fe\n"
        "jmp .Lf713e6_000721f6\n"
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072c58:\n"
        "testb $1, %al\n" /* line 3983 */
        "jne .Lf713e6_00071e81\n"
        "testb $0x40, %al\n" /* line 3986 */
        "je .Lf713e6_00071e81\n"
        "movl 0xd8(%edx), %eax\n" /* line 3992 */
        "cmpl $5, %eax\n"
        "je .Lf713e6_00071e81\n"
        "cmpl $7, %eax\n"
        "je .Lf713e6_00071e81\n"
        "cmpl $9, %eax\n"
        "je .Lf713e6_00071e81\n"
        "cmpl $8, %eax\n"
        "je .Lf713e6_00071e81\n"
        "cmpl $6, %eax\n"
        "je .Lf713e6_00071e81\n"
        "orb $1, %ch\n" /* line 3996 */
        "movl %ecx, 0xc(%edx)\n"
        "jmp .Lf713e6_00071e81\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072ca6:\n"
        "testb $1, %al\n" /* line 3983 */
        "jne .Lf713e6_00071b93\n"
        "testb $0x40, %al\n" /* line 3986 */
        "je .Lf713e6_00071b93\n"
        "movl 0xd8(%edx), %eax\n" /* line 3992 */
        "cmpl $5, %eax\n"
        "je .Lf713e6_00071b93\n"
        "cmpl $7, %eax\n"
        "je .Lf713e6_00071b93\n"
        "cmpl $9, %eax\n"
        "je .Lf713e6_00071b93\n"
        "cmpl $8, %eax\n"
        "je .Lf713e6_00071b93\n"
        "cmpl $6, %eax\n"
        "je .Lf713e6_00071b93\n"
        "orb $1, %ch\n" /* line 3996 */
        "movl %ecx, 0xc(%edx)\n"
        "jmp .Lf713e6_00071b93\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072cf4:\n"
        "testb $1, %al\n" /* line 3983 */
        "jne .Lf713e6_00071ad2\n"
        "testb $0x40, %al\n" /* line 3986 */
        "je .Lf713e6_00071ad2\n"
        "movl 0xd8(%edx), %eax\n" /* line 3992 */
        "cmpl $5, %eax\n"
        "je .Lf713e6_00071ad2\n"
        "cmpl $7, %eax\n"
        "je .Lf713e6_00071ad2\n"
        "cmpl $9, %eax\n"
        "je .Lf713e6_00071ad2\n"
        "cmpl $8, %eax\n"
        "je .Lf713e6_00071ad2\n"
        "cmpl $6, %eax\n"
        "je .Lf713e6_00071ad2\n"
        "orb $1, %ch\n" /* line 3996 */
        "movl %ecx, 0xc(%edx)\n"
        "jmp .Lf713e6_00071ad2\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072d42:\n"
        "testb $1, %al\n" /* line 3983 */
        "jne .Lf713e6_0007216a\n"
        "testb $0x40, %al\n" /* line 3986 */
        "je .Lf713e6_0007216a\n"
        "movl 0xd8(%edx), %eax\n" /* line 3992 */
        "cmpl $5, %eax\n"
        "je .Lf713e6_0007216a\n"
        "cmpl $7, %eax\n"
        "je .Lf713e6_0007216a\n"
        "cmpl $9, %eax\n"
        "je .Lf713e6_0007216a\n"
        "cmpl $8, %eax\n"
        "je .Lf713e6_0007216a\n"
        "cmpl $6, %eax\n"
        "je .Lf713e6_0007216a\n"
        "orb $1, %ch\n" /* line 3996 */
        "movl %ecx, 0xc(%edx)\n"
        "jmp .Lf713e6_0007216a\n"
        /* } scope */
        ".Lf713e6_00072d90:\n"
        "andl $0xfff7f9ff, 0xc(%esi)\n" /* line 3370 */
        "movl $0, 0x10(%esi)\n" /* line 3371 */
        "jmp .Lf713e6_00072362\n"
        ".Lf713e6_00072da3:\n"
        "andl $0xfff7f9ff, 0xc(%esi)\n" /* line 3370 */
        "movl $0, 0x10(%esi)\n" /* line 3371 */
        "jmp .Lf713e6_00071af9\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_00072db6:\n"
        "pxor %xmm0, %xmm0\n" /* line 552 */
        "ucomiss 0x4c(%edx), %xmm0\n"
        "jp .Lf713e6_00072285\n"
        "je .Lf713e6_0007228d\n"
        "jmp .Lf713e6_00072285\n"
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072dcf:\n"
        "movl %ebx, (%esp)\n" /* line 982 */
        "calll Jump_ApplySlowdown\n"
        "jmp .Lf713e6_00072542\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00072ddc:\n"
        "movl 0xc(%ebx), %edx\n" /* line 4081 | ps */
        "testl $0x40000, %edx\n"
        "jne .Lf713e6_00072708\n"
        "movl 0xf4(%ebx), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "je .Lf713e6_00072dff\n"
        "cmpl $0xb, %eax\n" /* line 353 */
        "je .Lf713e6_00072708\n"
        ".Lf713e6_00072dff:\n"
        "movl 4(%edi), %eax\n" /* line 4095 */
        "subl 0x70(%ebx), %eax\n" /* ps */
        "cmpl $0x12b, %eax\n"
        "jle .Lf713e6_00072708\n"
        "movss 0xc8(%edi), %xmm1\n" /* line 200 */
        "movss lit4_002ed5e0, %xmm4\n" /* line 4104 | 6.0f */
        "movss 0xc4(%edi), %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* wishvel */
        "addss %xmm4, %xmm1\n" /* line 4105 */
        "movss %xmm1, -0x44(%ebp)\n"
        "movss lit4_002ed740, %xmm3\n" /* line 4106 | 8.0f */
        "movss %xmm3, -0x40(%ebp)\n"
        "leal 0xd0(%edi), %eax\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        "movss 0xd0(%edi), %xmm0\n" /* line 199 */
        "movss 4(%eax), %xmm2\n" /* line 200 */
        "movss 8(%eax), %xmm1\n" /* line 201 */
        /* } scope */
        "subss %xmm4, %xmm0\n" /* line 4108 */
        "movss %xmm0, -0x3c(%ebp)\n" /* wishdir */
        "subss %xmm4, %xmm2\n" /* line 4109 */
        "movss %xmm2, -0x38(%ebp)\n"
        "movaps %xmm1, %xmm2\n" /* line 4112 */
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm3, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "leal 0x14(%ebx), %eax\n" /* line 4118 | ps */
        "movl %eax, -0x144(%ebp)\n"
        "movss -0x128(%ebp), %xmm0\n" /* line 288 | scale */
        "mulss -0x30(%ebp), %xmm0\n" /* up */
        "addss 0x14(%ebx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* forward */
        "leal 0x18(%ebx), %edx\n" /* line 289 */
        "movl %edx, -0x140(%ebp)\n"
        "movss -0x128(%ebp), %xmm0\n" /* scale */
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss 0x18(%ebx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "leal 0x1c(%ebx), %ecx\n" /* line 290 */
        "movl %ecx, -0x13c(%ebp)\n"
        "movss -0x128(%ebp), %xmm0\n" /* scale */
        "mulss -0x28(%ebp), %xmm0\n"
        "addss 0x1c(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0x3c(%edi), %eax\n" /* line 4119 */
        "movl %eax, -0x138(%ebp)\n" /* contentMask */
        "movl 0xcc(%ebx), %edx\n" /* ps */
        "movl %edx, -0x134(%ebp)\n" /* passEntityNum */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movzbl 0xe4(%edi), %eax\n" /* line 262 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x138(%ebp), %ecx\n" /* contentMask */
        "movl %ecx, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* forward */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* wishdir */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* wishvel */
        "movl %edx, 8(%esp)\n"
        "movl -0x144(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x6c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x49(%ebp)\n" /* line 264 */
        "je .Lf713e6_00073009\n"
        "testb $2, -0x55(%ebp)\n" /* line 268 */
        "je .Lf713e6_00073009\n"
        "movl -0x50(%ebp), %eax\n" /* line 271 */
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x130(%ebp)\n" /* entityNum */
        /* { scope 6: i, i, ps, i */
        /* { scope 7 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf713e6_00072fae\n"
        "movl 0x40(%edi), %ecx\n" /* line 303 */
        "cmpl $0x20, %ecx\n"
        "je .Lf713e6_00072fae\n"
        "testl %ecx, %ecx\n" /* line 309 */
        "jle .Lf713e6_00073a54\n"
        "movl -0x130(%ebp), %edx\n" /* line 311 | entityNum */
        "cmpl %edx, 0x44(%edi)\n"
        "je .Lf713e6_00072fae\n"
        "movl %edi, %edx\n"
        "movl $0, -0x12c(%ebp)\n" /* i */
        ".Lf713e6_00072f8d:\n"
        "addl $1, -0x12c(%ebp)\n" /* line 309 | i */
        "cmpl -0x12c(%ebp), %ecx\n" /* i */
        "je .Lf713e6_00073a54\n"
        "movl 0x48(%edx), %eax\n" /* line 311 */
        "addl $4, %edx\n"
        "cmpl -0x130(%ebp), %eax\n" /* entityNum */
        "jne .Lf713e6_00072f8d\n"
        /* } scope */
        /* } scope */
        ".Lf713e6_00072fae:\n"
        "andl $0xfdffffff, 0x3c(%edi)\n" /* line 272 */
        "movzbl 0xe4(%edi), %eax\n" /* line 273 */
        "leal (%eax, %eax, 2), %eax\n"
        "andl $0xfdffffff, -0x138(%ebp)\n" /* contentMask */
        "movl -0x138(%ebp), %edx\n" /* contentMask */
        "movl %edx, 0x18(%esp)\n"
        "movl -0x134(%ebp), %ecx\n" /* passEntityNum */
        "movl %ecx, 0x14(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* forward */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* wishdir */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* wishvel */
        "movl %edx, 8(%esp)\n"
        "movl -0x144(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x6c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        /* } scope */
        ".Lf713e6_00073009:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 4120 | 1.0f */
        "ucomiss -0x6c(%ebp), %xmm0\n" /* trace */
        "ja .Lf713e6_000738fd\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_0007301b:\n"
        "movl 0xc(%ebx), %edx\n" /* line 4008 | ps */
        "testb $0x20, %dl\n"
        "je .Lf713e6_0007302c\n"
        "orl $0x40000, %edx\n" /* line 4009 */
        "movl %edx, 0xc(%ebx)\n" /* ps */
        ".Lf713e6_0007302c:\n"
        "andl $0xffffffdf, %edx\n" /* line 4011 */
        "movl %edx, 0xc(%ebx)\n" /* ps */
        /* } scope */
        "cmpb $0, -0x145(%ebp)\n" /* line 4145 */
        "je .Lf713e6_000724e1\n"
        "movl $1, 0xc(%esp)\n" /* line 4148 */
        "movl $0, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "jmp .Lf713e6_000724e1\n"
        /* } scope */
        ".Lf713e6_00073064:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 4632 | pml */
        "movl %edi, %eax\n"
        "calll PM_LadderMove\n"
        "jmp .Lf713e6_0007274f\n"
        ".Lf713e6_00073076:\n"
        "movl -0xbc(%ebp), %eax\n" /* line 1090 */
        "testl %eax, %eax\n"
        "je .Lf713e6_000724b1\n"
        "movl -0x180(%ebp), %edx\n" /* line 324 */
        "movss (%edx), %xmm0\n"
        "movl -0x168(%ebp), %ecx\n"
        "movss (%ecx), %xmm1\n"
        "movl -0x164(%ebp), %eax\n"
        "movss (%eax), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "subss lit4_002ed694, %xmm1\n" /* 20.0f */
        "xorl %eax, %eax\n" /* line 1097 */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jbe .Lf713e6_000738c9\n"
        ".Lf713e6_000730d1:\n"
        "movl %edx, (%esp)\n" /* line 1103 */
        "movss %xmm1, -0x1a8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        "movss -0x1a8(%ebp), %xmm1\n" /* line 272 */
        "movaps %xmm1, %xmm0\n"
        "movl -0x180(%ebp), %ecx\n"
        "mulss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "movl -0x168(%ebp), %eax\n"
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movl -0x164(%ebp), %edx\n" /* line 274 */
        "mulss (%edx), %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "jmp .Lf713e6_000724b1\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00073122:\n"
        "cvtsi2ssl 0x50(%ebx), %xmm5\n" /* line 550 */
        "mulss %xmm1, %xmm5\n"
        "movaps %xmm3, %xmm0\n" /* line 81 */
        "mulss %xmm3, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "mulss lit4_002ed718, %xmm0\n" /* 127.0f */
        "divss %xmm0, %xmm5\n"
        "testb $1, 0xd(%ebx)\n" /* line 552 */
        "jne .Lf713e6_00073199\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss 0x4c(%ebx), %xmm1\n"
        "jp .Lf713e6_00073199\n"
        "jne .Lf713e6_00073199\n"
        ".Lf713e6_0007316a:\n"
        "movl 4(%ebx), %eax\n" /* line 557 */
        "cmpl $2, %eax\n"
        "je .Lf713e6_00073821\n"
        "cmpl $3, %eax\n" /* line 559 */
        "je .Lf713e6_00073842\n"
        "cmpl $4, %eax\n" /* line 562 */
        "jne .Lf713e6_00071ce6\n"
        "movl imp_player_spectateSpeedScale, %eax\n" /* line 563 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm5\n"
        "jmp .Lf713e6_00071ce6\n"
        ".Lf713e6_00073199:\n"
        "mulss lit4_002ed71c, %xmm5\n" /* line 553 | 0.4000000059604645f */
        "jmp .Lf713e6_0007316a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_000731a3:\n"
        "cvtsi2ssl 0x50(%ebx), %xmm2\n" /* line 550 */
        "mulss %xmm1, %xmm2\n"
        "movaps %xmm3, %xmm0\n" /* line 81 */
        "mulss %xmm3, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "mulss lit4_002ed718, %xmm0\n" /* 127.0f */
        "divss %xmm0, %xmm2\n"
        "testb $1, 0xd(%ebx)\n" /* line 552 */
        "jne .Lf713e6_0007321a\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss 0x4c(%ebx), %xmm1\n"
        "jp .Lf713e6_0007321a\n"
        "jne .Lf713e6_0007321a\n"
        ".Lf713e6_000731eb:\n"
        "movl 4(%ebx), %eax\n" /* line 557 */
        "cmpl $2, %eax\n"
        "je .Lf713e6_00073814\n"
        "cmpl $3, %eax\n" /* line 559 */
        "je .Lf713e6_00073835\n"
        "cmpl $4, %eax\n" /* line 562 */
        "jne .Lf713e6_00071fdd\n"
        "movl imp_player_spectateSpeedScale, %eax\n" /* line 563 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm2\n"
        "jmp .Lf713e6_00071fdd\n"
        ".Lf713e6_0007321a:\n"
        "mulss lit4_002ed71c, %xmm2\n" /* line 553 | 0.4000000059604645f */
        "jmp .Lf713e6_000731eb\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00073224:\n"
        "movsbl 0x1c(%edi), %eax\n" /* line 873 */
        "cvtsi2ssl %eax, %xmm4\n"
        "movsbl 0x1d(%edi), %eax\n"
        "cvtsi2ssl %eax, %xmm3\n"
        "movl $1, %edx\n"
        ".Lf713e6_00073239:\n"
        "leal (, %edx, 4), %eax\n"
        "movaps %xmm2, %xmm1\n"
        "mulss -0xec(%ebp, %eax), %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss -0xe0(%ebp, %eax), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x40(%ebp, %eax)\n"
        "addl $1, %edx\n"
        "cmpl $4, %edx\n" /* line 872 */
        "jne .Lf713e6_00073239\n"
        "jmp .Lf713e6_00072252\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00073277:\n"
        "jp .Lf713e6_00071bee\n" /* line 1143 */
        "movl imp_vec3_origin, %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, 0x20(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl -0x15c(%ebp), %ecx\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "jmp .Lf713e6_00071c62\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_0007329f:\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 711 | 1.0f */
        "movss CorrectSolidDeltas+576, %xmm6\n"
        /* } scope */
        /* } scope */
        ".Lf713e6_000732af:\n"
        "mulss %xmm1, %xmm2\n" /* line 1000 */
        "movss %xmm2, -0xec(%ebp)\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 1003 | 1000.0f */
        "mulss -0xc4(%ebp), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 0x90(%ebx)\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 1005 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "jae .Lf713e6_0007384f\n"
        ".Lf713e6_000732e8:\n"
        "movl $0, -0xe0(%ebp)\n" /* line 1011 */
        "movl $0, -0xd4(%ebp)\n" /* line 1012 */
        "movss -0xe8(%ebp), %xmm2\n" /* line 304 | pml */
        "movss -0xac(%ebp), %xmm3\n"
        "movaps %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss -0xe4(%ebp), %xmm0\n"
        "mulss -0xa8(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "pxor %xmm5, %xmm5\n"
        "mulss -0xa4(%ebp), %xmm5\n"
        "addss %xmm5, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 336 | scale */
        "andps %xmm7, %xmm0\n" /* scale */
        "movss lit4_002ed670, %xmm4\n" /* -0.0010000000474974513f */
        "mulss %xmm4, %xmm0\n" /* scale */
        "addss %xmm1, %xmm0\n" /* scale */
        "xorps %xmm6, %xmm0\n" /* scale */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movaps %xmm3, %xmm1\n" /* line 288 */
        "mulss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0xe8(%ebp)\n" /* pml */
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss -0xa8(%ebp), %xmm1\n"
        "addss -0xe4(%ebp), %xmm1\n"
        "movss %xmm1, -0xe4(%ebp)\n"
        "mulss -0xa4(%ebp), %xmm0\n" /* line 290 */
        "addss -0xe0(%ebp), %xmm0\n"
        "movss %xmm0, -0xe0(%ebp)\n"
        /* } scope */
        "movss -0xdc(%ebp), %xmm2\n" /* line 304 */
        "movaps %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss -0xd8(%ebp), %xmm0\n"
        "mulss -0xa8(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss %xmm5, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 336 | scale */
        "andps %xmm7, %xmm0\n" /* scale */
        "mulss %xmm4, %xmm0\n" /* scale */
        "addss %xmm1, %xmm0\n" /* scale */
        "xorps %xmm6, %xmm0\n" /* scale */
        /* { scope 5: entityNum, entityNum, entityNum */
        "mulss %xmm0, %xmm3\n" /* line 288 */
        "addss %xmm3, %xmm2\n"
        "movss %xmm2, -0xdc(%ebp)\n"
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss -0xa8(%ebp), %xmm1\n"
        "addss -0xd8(%ebp), %xmm1\n"
        "movss %xmm1, -0xd8(%ebp)\n"
        "mulss -0xa4(%ebp), %xmm0\n" /* line 290 */
        "addss -0xd4(%ebp), %xmm0\n"
        "movss %xmm0, -0xd4(%ebp)\n"
        /* } scope */
        "leal -0xe8(%ebp), %eax\n" /* line 1018 | pml */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0xdc(%ebp), %edx\n" /* line 1019 */
        "movl %edx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl $1, %edx\n"
        ".Lf713e6_00073436:\n"
        "leal (, %edx, 4), %eax\n" /* line 1022 */
        "movss -0x114(%ebp), %xmm0\n" /* fmove */
        "mulss -0xec(%ebp, %eax), %xmm0\n"
        "movss -0x110(%ebp), %xmm1\n" /* smove */
        "mulss -0xe0(%ebp, %eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%ebp, %eax)\n"
        "addl $1, %edx\n"
        "cmpl $4, %edx\n" /* line 1021 */
        "jne .Lf713e6_00073436\n"
        "movl -0x3c(%ebp), %eax\n" /* line 199 | wishdir */
        "movl %eax, -0x48(%ebp)\n" /* wishvel */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        "leal -0x48(%ebp), %ecx\n" /* line 1027 | wishvel */
        "movl %ecx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x1fc(%ebp)\n"
        "movss -0x1fc(%ebp), %xmm0\n"
        "mulss -0xec(%ebp), %xmm0\n" /* line 1028 */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movl 0xf4(%ebx), %eax\n" /* line 350 */
        "cmpl $0x28, %eax\n"
        "je .Lf713e6_0007382e\n"
        "cmpl $0xb, %eax\n" /* line 353 */
        "sete %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lf713e6_000734bc:\n"
        "testb $2, -0xa0(%ebp)\n" /* line 1035 */
        "jne .Lf713e6_00073697\n"
        "movl 0xc(%ebx), %edx\n" /* ps */
        "testb $4, %dh\n"
        "je .Lf713e6_0007379d\n"
        ".Lf713e6_000734d5:\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 1039 | 1.0f */
        ".Lf713e6_000734dd:\n"
        "andb $2, %dh\n" /* line 1045 */
        "je .Lf713e6_000734ea\n"
        "mulss lit4_002ed604, %xmm1\n" /* line 1046 | 0.25f */
        ".Lf713e6_000734ea:\n"
        "leal -0x48(%ebp), %ecx\n" /* line 1048 | wishvel */
        "leal -0xe8(%ebp), %edx\n" /* pml */
        "movl %ebx, %eax\n" /* ps */
        "calll PM_Accelerate\n"
        "testb $2, -0xa0(%ebp)\n" /* line 1053 */
        "jne .Lf713e6_0007350d\n"
        "testb $4, 0xd(%ebx)\n" /* ps */
        "je .Lf713e6_00073793\n"
        ".Lf713e6_0007350d:\n"
        "cvtsi2ssl 0x48(%ebx), %xmm1\n" /* line 1054 | ps */
        "mulss -0xc4(%ebp), %xmm1\n"
        "movss 0x28(%ebx), %xmm0\n" /* ps */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x28(%ebx)\n" /* ps */
        "movaps %xmm0, %xmm5\n"
        ".Lf713e6_0007352b:\n"
        "leal 0x20(%ebx), %eax\n" /* line 1056 | ps */
        "movss 0x20(%ebx), %xmm3\n" /* line 324 */
        "movss 0x24(%ebx), %xmm4\n"
        "movaps %xmm3, %xmm0\n" /* line 81 */
        "mulss %xmm3, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm6\n"
        "movss -0xac(%ebp), %xmm2\n" /* line 304 */
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0xa8(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss -0xa4(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* line 336 | scale */
        "andps CorrectSolidDeltas+560, %xmm1\n" /* scale */
        "mulss lit4_002ed670, %xmm1\n" /* -0.0010000000474974513f, scale */
        "addss %xmm0, %xmm1\n" /* scale */
        "xorps CorrectSolidDeltas+576, %xmm1\n" /* scale */
        /* { scope 5: entityNum, entityNum, entityNum */
        "mulss %xmm1, %xmm2\n" /* line 288 */
        "addss %xmm3, %xmm2\n"
        "movss %xmm2, 0x20(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0xa8(%ebp), %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, 0x24(%ebx)\n"
        "mulss -0xa4(%ebp), %xmm1\n" /* line 290 */
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, 0x28(%ebx)\n"
        /* } scope */
        "mulss %xmm2, %xmm3\n" /* line 1063 */
        "mulss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm3\n"
        "mulss %xmm1, %xmm5\n"
        "addss %xmm5, %xmm3\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm3\n"
        "jbe .Lf713e6_00073630\n"
        "movl %eax, (%esp)\n" /* line 1066 */
        "movss %xmm6, -0x1f8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x1f8(%ebp), %xmm6\n" /* line 272 */
        "movaps %xmm6, %xmm0\n"
        "mulss 0x20(%ebx), %xmm0\n"
        "movss %xmm0, 0x20(%ebx)\n"
        "movaps %xmm6, %xmm0\n" /* line 273 */
        "mulss 0x24(%ebx), %xmm0\n"
        "movss %xmm0, 0x24(%ebx)\n"
        "mulss 0x28(%ebx), %xmm6\n" /* line 274 */
        "movss %xmm6, 0x28(%ebx)\n"
        ".Lf713e6_00073630:\n"
        "pxor %xmm1, %xmm1\n" /* line 1071 */
        "ucomiss 0x20(%ebx), %xmm1\n" /* ps */
        "jne .Lf713e6_00073656\n"
        "jp .Lf713e6_00073656\n"
        "ucomiss 0x24(%ebx), %xmm1\n" /* ps */
        "jp .Lf713e6_00073656\n"
        "jne .Lf713e6_00073656\n"
        ".Lf713e6_00073644:\n"
        "leal -0xe8(%ebp), %edx\n" /* line 1075 | pml */
        "movl %edi, %eax\n"
        "calll PM_SetMovementDir\n"
        "jmp .Lf713e6_0007274f\n"
        ".Lf713e6_00073656:\n"
        "movl $0, 8(%esp)\n" /* line 1072 */
        "leal -0xe8(%ebp), %eax\n" /* pml */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_StepSlideMove\n"
        "jmp .Lf713e6_00073644\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_00073672:\n"
        "jnp .Lf713e6_00072bab\n" /* line 1241 */
        "jmp .Lf713e6_00071f0d\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_0007367d:\n"
        "mulss lit4_002ed720, %xmm1\n" /* line 558 | 3.0f */
        "jmp .Lf713e6_000722b9\n"
        /* } scope */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_0007368a:\n"
        "mulss lit4_002ed720, %xmm2\n" /* line 602 | 3.0f */
        "jmp .Lf713e6_0007222a\n"
        ".Lf713e6_00073697:\n"
        "movl 0xc(%ebx), %edx\n"
        "jmp .Lf713e6_000734d5\n"
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_0007369f:\n"
        "movl -0x10c(%ebp), %eax\n" /* line 650 | ps */
        "cvtsi2ssl 0x50(%eax), %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "mulss lit4_002ed718, %xmm3\n" /* 127.0f */
        "divss %xmm3, %xmm2\n"
        "testb $1, 0xd(%eax)\n" /* line 652 */
        "je .Lf713e6_0007377a\n"
        ".Lf713e6_000736c4:\n"
        "mulss lit4_002ed71c, %xmm2\n" /* line 653 | 0.4000000059604645f */
        ".Lf713e6_000736cc:\n"
        "movl -0x10c(%ebp), %edx\n" /* line 657 | ps */
        "movl 4(%edx), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lf713e6_000738bc\n"
        "cmpl $3, %eax\n" /* line 661 */
        "je .Lf713e6_000738dc\n"
        /* { scope 6: i, i, ps, i */
        /* { scope 7 */
        "movl -0x10c(%ebp), %ecx\n" /* line 350 | ps */
        "movl 0xf4(%ecx), %eax\n"
        "cmpl $0x28, %eax\n"
        "je .Lf713e6_000738f6\n"
        "cmpl $0xb, %eax\n" /* line 353 */
        "sete %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lf713e6_00073705:\n"
        "movl -0x10c(%ebp), %ecx\n" /* line 1906 | ps */
        "movl 0xfc(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf713e6_00073737\n"
        "movl 0x100(%ecx), %ecx\n" /* line 1910 */
        "movl %ecx, -0x200(%ebp)\n"
        "cmpl $0xb, %ecx\n"
        "je .Lf713e6_00073996\n"
        "cmpl $0x28, -0x200(%ebp)\n"
        "je .Lf713e6_000739eb\n"
        ".Lf713e6_00073737:\n"
        "cmpl $1, %eax\n" /* line 676 */
        "je .Lf713e6_00073931\n"
        "cmpl $2, %eax\n" /* line 678 */
        "je .Lf713e6_00073989\n"
        /* } scope */
        ".Lf713e6_00073749:\n"
        "movl -0x10c(%ebp), %edx\n" /* line 683 | ps */
        "movl 0xd4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf713e6_00073882\n"
        ".Lf713e6_0007375d:\n"
        "testl $0x800, -0xf8(%ebp)\n" /* line 686 */
        "je .Lf713e6_00072620\n"
        "mulss lit4_002ed71c, %xmm2\n" /* line 687 | 0.4000000059604645f */
        "jmp .Lf713e6_00072620\n"
        ".Lf713e6_0007377a:\n"
        "pxor %xmm0, %xmm0\n" /* line 652 */
        "ucomiss 0x4c(%eax), %xmm0\n"
        "jp .Lf713e6_000736c4\n"
        "je .Lf713e6_000736cc\n"
        "jmp .Lf713e6_000736c4\n"
        ".Lf713e6_00073793:\n"
        "movss 0x28(%ebx), %xmm5\n"
        "jmp .Lf713e6_0007352b\n"
        /* } scope */
        ".Lf713e6_0007379d:\n"
        "cmpl $1, %eax\n" /* line 1037 */
        "je .Lf713e6_000738e9\n"
        "cmpl $2, %eax\n" /* line 1039 */
        "je .Lf713e6_0007393e\n"
        "movss lit4_002ed728, %xmm1\n" /* 9.0f */
        "jmp .Lf713e6_000734dd\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_000737bc:\n"
        "leal 0x64(%ebx), %eax\n" /* line 4052 | ps */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movss CorrectSolidDeltas+576, %xmm0\n" /* line 216 */
        "movss 0x64(%ebx), %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* up */
        "movss 4(%eax), %xmm1\n" /* line 217 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movb $1, -0x145(%ebp)\n"
        "jmp .Lf713e6_000726d6\n"
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_000737fa:\n"
        "mulss lit4_002ed5e0, %xmm1\n" /* line 560 | 6.0f */
        "jmp .Lf713e6_000722b9\n"
        /* } scope */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_00073807:\n"
        "mulss lit4_002ed5e0, %xmm2\n" /* line 604 | 6.0f */
        "jmp .Lf713e6_0007222a\n"
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00073814:\n"
        "mulss lit4_002ed720, %xmm2\n" /* line 558 | 3.0f */
        "jmp .Lf713e6_00071fdd\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00073821:\n"
        "mulss lit4_002ed720, %xmm5\n" /* 3.0f */
        "jmp .Lf713e6_00071ce6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_0007382e:\n"
        "movb $2, %al\n" /* line 350 */
        "jmp .Lf713e6_000734bc\n"
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00073835:\n"
        "mulss lit4_002ed5e0, %xmm2\n" /* line 560 | 6.0f */
        "jmp .Lf713e6_00071fdd\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00073842:\n"
        "mulss lit4_002ed5e0, %xmm5\n" /* 6.0f */
        "jmp .Lf713e6_00071ce6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_0007384f:\n"
        "movl $0, 0x90(%ebx)\n" /* line 1006 */
        "jmp .Lf713e6_000732e8\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_0007385e:\n"
        "movl imp_player_backSpeedScale, %eax\n" /* line 54 */
        "movl (%eax), %eax\n"
        "movss -0x114(%ebp), %xmm2\n" /* fmove */
        "mulss 8(%eax), %xmm2\n"
        "movss CorrectSolidDeltas+560, %xmm7\n"
        "andps %xmm7, %xmm2\n"
        "jmp .Lf713e6_000725d7\n"
        ".Lf713e6_00073882:\n"
        "movl %eax, (%esp)\n" /* line 683 */
        "movss %xmm2, -0x1b8(%ebp)\n"
        "calll BG_GetWeaponDef\n"
        "movss 0x264(%eax), %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "movss -0x1b8(%ebp), %xmm2\n"
        "ja .Lf713e6_0007394b\n"
        ".Lf713e6_000738af:\n"
        "movss CorrectSolidDeltas+560, %xmm7\n"
        "jmp .Lf713e6_0007375d\n"
        ".Lf713e6_000738bc:\n"
        "mulss lit4_002ed720, %xmm2\n" /* line 659 | 3.0f */
        "jmp .Lf713e6_00073749\n"
        /* } scope */
        /* } scope */
        ".Lf713e6_000738c9:\n"
        "jp .Lf713e6_000730d1\n" /* line 1097 */
        "movl %eax, (%edx)\n" /* line 183 */
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "jmp .Lf713e6_000724b1\n"
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_000738dc:\n"
        "mulss lit4_002ed5e0, %xmm2\n" /* line 663 | 6.0f */
        "jmp .Lf713e6_00073749\n"
        /* } scope */
        ".Lf713e6_000738e9:\n"
        "movss lit4_002ed69c, %xmm1\n" /* line 1037 | 19.0f */
        "jmp .Lf713e6_000734dd\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        /* { scope 7 */
        ".Lf713e6_000738f6:\n"
        "movb $2, %al\n" /* line 350 */
        "jmp .Lf713e6_00073705\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        ".Lf713e6_000738fd:\n"
        "testb $8, -0x5c(%ebp)\n" /* line 4120 */
        "je .Lf713e6_0007301b\n"
        "movl -0xbc(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf713e6_0007391b\n"
        "cmpb $0, 0x1c(%edi)\n"
        "jle .Lf713e6_0007301b\n"
        ".Lf713e6_0007391b:\n"
        "movl 0xc(%ebx), %eax\n" /* line 4122 | ps */
        "testb $0x20, %al\n"
        "je .Lf713e6_00073a69\n"
        "orl $0x20, %eax\n" /* line 4002 */
        "movl %eax, 0xc(%ebx)\n" /* ps */
        "jmp .Lf713e6_000724e1\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00073931:\n"
        "mulss lit4_002ed764, %xmm2\n" /* line 677 | 0.15000000596046448f */
        "jmp .Lf713e6_00073749\n"
        /* } scope */
        /* } scope */
        ".Lf713e6_0007393e:\n"
        "movss lit4_002ed79c, %xmm1\n" /* line 1039 | 12.0f */
        "jmp .Lf713e6_000734dd\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        ".Lf713e6_0007394b:\n"
        "movl -0x10c(%ebp), %edx\n" /* line 684 | ps */
        "movl 0xd4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movss -0x1b8(%ebp), %xmm2\n"
        "mulss 0x264(%eax), %xmm2\n"
        "jmp .Lf713e6_000738af\n"
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        /* { scope 7 */
        ".Lf713e6_00073974:\n"
        "movl -0x100(%ebp), %eax\n" /* line 318 | entityNum */
        "movl %eax, 0x44(%edi, %ecx, 4)\n"
        "leal 1(%ecx), %eax\n" /* line 319 */
        "movl %eax, 0x40(%edi)\n"
        "jmp .Lf713e6_00072ae7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00073989:\n"
        "mulss lit4_002ed768, %xmm2\n" /* line 679 | 0.6499999761581421f */
        "jmp .Lf713e6_00073749\n"
        ".Lf713e6_00073996:\n"
        "subl %edx, -0xf4(%ebp)\n" /* line 1921 */
        "cvtsi2ssl -0xf4(%ebp), %xmm0\n"
        "divss lit4_002ed730, %xmm0\n" /* 400.0f */
        "pxor %xmm1, %xmm1\n" /* line 1922 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf713e6_00073737\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 1924 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf713e6_00073c53\n"
        "movss lit4_002ed764, %xmm3\n" /* 0.15000000596046448f */
        "pxor %xmm1, %xmm1\n"
        ".Lf713e6_000739d6:\n"
        "mulss lit4_002ed768, %xmm1\n" /* line 673 | 0.6499999761581421f */
        "addss %xmm3, %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "jmp .Lf713e6_00073749\n"
        ".Lf713e6_000739eb:\n"
        "movl -0x10c(%ebp), %ecx\n" /* line 1910 | ps */
        "movl 0x104(%ecx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf713e6_00073737\n"
        "subl %edx, -0xf4(%ebp)\n" /* line 1921 */
        "cvtsi2ssl -0xf4(%ebp), %xmm0\n"
        "divss lit4_002ed730, %xmm0\n" /* 400.0f */
        "pxor %xmm1, %xmm1\n" /* line 1922 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf713e6_00073737\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 1924 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf713e6_00073c76\n"
        "movss lit4_002ed768, %xmm3\n" /* 0.6499999761581421f */
        "pxor %xmm1, %xmm1\n"
        ".Lf713e6_00073a3f:\n"
        "mulss lit4_002ed764, %xmm1\n" /* line 675 | 0.15000000596046448f */
        "addss %xmm1, %xmm3\n"
        "mulss %xmm3, %xmm2\n"
        "jmp .Lf713e6_00073749\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        /* { scope 7 */
        ".Lf713e6_00073a54:\n"
        "movl -0x130(%ebp), %eax\n" /* line 318 | entityNum */
        "movl %eax, 0x44(%edi, %ecx, 4)\n"
        "addl $1, %ecx\n" /* line 319 */
        "movl %ecx, 0x40(%edi)\n"
        "jmp .Lf713e6_00072fae\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf713e6_00073a69:\n"
        "leal 0x64(%ebx), %edx\n" /* line 4124 | ps, to */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movl -0x68(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x64(%ebx)\n"
        "movl -0x64(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x60(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movss CorrectSolidDeltas+576, %xmm0\n" /* line 216 */
        "movss 0x64(%ebx), %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* up */
        "movss 4(%edx), %xmm1\n" /* line 217 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss 8(%edx), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* { scope 5: entityNum, entityNum, entityNum */
        "movss -0x128(%ebp), %xmm0\n" /* line 288 | scale */
        "mulss -0x30(%ebp), %xmm0\n" /* up */
        "movl -0x144(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* forward */
        "movss -0x128(%ebp), %xmm0\n" /* line 289 | scale */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movl -0x140(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x128(%ebp), %xmm0\n" /* line 290 | scale */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x128(%ebp)\n" /* scale */
        "movl -0x13c(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "movl 0x3c(%edi), %edx\n" /* line 4128 */
        "movl %edx, -0x124(%ebp)\n" /* contentMask */
        "movl 0xcc(%ebx), %ecx\n" /* ps */
        "movl %ecx, -0x120(%ebp)\n" /* passEntityNum */
        /* { scope 5: entityNum, entityNum, entityNum */
        "movzbl 0xe4(%edi), %eax\n" /* line 262 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %edx, 0x18(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* forward */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* wishdir */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* wishvel */
        "movl %edx, 8(%esp)\n"
        "movl -0x144(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x6c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        "cmpb $0, -0x49(%ebp)\n" /* line 264 */
        "je .Lf713e6_00073c2e\n"
        "testb $2, -0x55(%ebp)\n" /* line 268 */
        "je .Lf713e6_00073c2e\n"
        "movl -0x50(%ebp), %eax\n" /* line 271 */
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x11c(%ebp)\n" /* entityNum */
        /* { scope 6: i, i, ps, i */
        /* { scope 7 */
        "cmpw $0x3fe, %ax\n" /* line 298 */
        "je .Lf713e6_00073bd3\n"
        "movl 0x40(%edi), %ecx\n" /* line 303 */
        "cmpl $0x20, %ecx\n"
        "je .Lf713e6_00073bd3\n"
        "testl %ecx, %ecx\n" /* line 309 */
        "jle .Lf713e6_00073bc3\n"
        "movl -0x11c(%ebp), %eax\n" /* line 311 | entityNum */
        "cmpl %eax, 0x44(%edi)\n"
        "je .Lf713e6_00073bd3\n"
        "movl %edi, %edx\n"
        "movl $0, -0x118(%ebp)\n" /* i */
        "jmp .Lf713e6_00073bb4\n"
        ".Lf713e6_00073ba6:\n"
        "movl 0x48(%edx), %eax\n"
        "addl $4, %edx\n"
        "cmpl -0x11c(%ebp), %eax\n" /* entityNum */
        "je .Lf713e6_00073bd3\n"
        ".Lf713e6_00073bb4:\n"
        "addl $1, -0x118(%ebp)\n" /* line 309 | i */
        "cmpl -0x118(%ebp), %ecx\n" /* i */
        "jne .Lf713e6_00073ba6\n"
        ".Lf713e6_00073bc3:\n"
        "movl -0x11c(%ebp), %eax\n" /* line 318 | entityNum */
        "movl %eax, 0x44(%edi, %ecx, 4)\n"
        "addl $1, %ecx\n" /* line 319 */
        "movl %ecx, 0x40(%edi)\n"
        /* } scope */
        /* } scope */
        ".Lf713e6_00073bd3:\n"
        "andl $0xfdffffff, 0x3c(%edi)\n" /* line 272 */
        "movzbl 0xe4(%edi), %eax\n" /* line 273 */
        "leal (%eax, %eax, 2), %eax\n"
        "andl $0xfdffffff, -0x124(%ebp)\n" /* contentMask */
        "movl -0x124(%ebp), %edx\n" /* contentMask */
        "movl %edx, 0x18(%esp)\n"
        "movl -0x120(%ebp), %ecx\n" /* passEntityNum */
        "movl %ecx, 0x14(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* forward */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %ecx\n" /* wishdir */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* wishvel */
        "movl %edx, 8(%esp)\n"
        "movl -0x144(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x6c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *pmoveHandlers(, %eax, 4)\n"
        /* } scope */
        ".Lf713e6_00073c2e:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 4129 | 1.0f */
        "ucomiss -0x6c(%ebp), %xmm0\n" /* trace */
        "jbe .Lf713e6_0007301b\n"
        "testb $8, -0x5c(%ebp)\n"
        "je .Lf713e6_0007301b\n"
        "orl $0x20, 0xc(%ebx)\n" /* line 4002 | ps */
        "jmp .Lf713e6_000724e1\n"
        /* } scope */
        /* { scope 4: up, forward, ps, passEntityNum, ... */
        /* { scope 5: entityNum, entityNum, entityNum */
        /* { scope 6: i, i, ps, i */
        ".Lf713e6_00073c53:\n"
        "pxor %xmm3, %xmm3\n" /* line 672 */
        "ucomiss %xmm3, %xmm0\n"
        "jp .Lf713e6_00073c62\n"
        "je .Lf713e6_00073737\n"
        ".Lf713e6_00073c62:\n"
        "movaps %xmm0, %xmm3\n"
        "mulss lit4_002ed764, %xmm3\n" /* 0.15000000596046448f */
        "subss %xmm0, %xmm1\n"
        "jmp .Lf713e6_000739d6\n"
        ".Lf713e6_00073c76:\n"
        "pxor %xmm3, %xmm3\n" /* line 674 */
        "ucomiss %xmm3, %xmm0\n"
        "jp .Lf713e6_00073c85\n"
        "je .Lf713e6_00073737\n"
        ".Lf713e6_00073c85:\n"
        "movaps %xmm0, %xmm3\n"
        "mulss lit4_002ed768, %xmm3\n" /* 0.6499999761581421f */
        "subss %xmm0, %xmm1\n"
        "jmp .Lf713e6_00073a3f\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_713e6_0:\n"
        ".long .Lf713e6_00071734\n"
        ".long .Lf713e6_00071a57\n"
        ".long .Lf713e6_00071b4d\n"
        ".long .Lf713e6_00071e3b\n"
        ".long .Lf713e6_00072124\n"
        ".long .Lf713e6_00071a17\n"
        ".long .Lf713e6_00071734\n"
        ".long .Lf713e6_00071a57\n"
        ".text\n"
    );
}

#else
/* NOTE: PM_Accelerate uses register calling convention on x86:
   eax=ps, edx=pml, ecx=wishdir, xmm0=wishspeed, xmm1=accel.
   The prototype here doesn't match. Under Emscripten, callers (also in asm)
   are not compiled, so this stub is never called. The _impl below contains
   the faithful C logic for reference/future use. */
static void PM_Accelerate_impl(playerState_t *ps, pml_t *pml, const vec_t *wishdir, float wishspeed, float accel) {
    float addspeed, accelspeed, currentspeed;
    vec_t *velocity;

    /* pm_flags bit 5 (0x20) = noclip/spectator */
    if (ps->pm_flags & 0x20) {
        /* Noclip/spectator acceleration: direct velocity push */
        float pushDir[3], pushLen, push;

        /* wishvel = wishdir * wishspeed */
        pushDir[0] = wishspeed * wishdir[0] - ps->velocity[0];
        pushDir[1] = wishspeed * wishdir[1] - ps->velocity[1];
        pushDir[2] = wishspeed * wishdir[2] - ps->velocity[2];

        pushLen = Vec3Normalize(pushDir);

        /* push = min(pushLen, accel * pml->frametime * wishspeed) */
        push = accel * pml->frametime * wishspeed;
        if (pushLen < push)
            push = pushLen;

        /* velocity += pushDir * push */
        ps->velocity[0] += pushDir[0] * push;
        ps->velocity[1] += pushDir[1] * push;
        ps->velocity[2] += pushDir[2] * push;
        return;
    }

    /* Normal acceleration */
    velocity = ps->velocity;

    /* currentspeed = DotProduct(velocity, wishdir) */
    currentspeed = velocity[0] * wishdir[0] + velocity[1] * wishdir[1] + velocity[2] * wishdir[2];

    /* addspeed = wishspeed - currentspeed */
    addspeed = wishspeed - currentspeed;
    if (addspeed <= 0.0f)
        return;

    /* accelspeed = accel * max(wishspeed, stopspeed) * frametime */
    {
        float stopspeed_val = *(float *)((byte *)(*(void **)imp_stopspeed) + 8);
        float maxspd = wishspeed;
        if (stopspeed_val > maxspd)
            maxspd = stopspeed_val;
        accelspeed = accel * pml->frametime * maxspd;
    }

    /* Clamp accelspeed to addspeed */
    if (accelspeed > addspeed)
        accelspeed = addspeed;

    /* Inertia check: if not noclip mode 2 */
    if (ps->pm_type != 2) {
        float inertiaMax_val = *(float *)((byte *)(*(void **)imp_inertiaMax) + 8);
        if (accelspeed > inertiaMax_val) {
            /* Check if direction change is significant */
            float oldVel[2], newVel[2], dot;

            oldVel[0] = ps->oldVelocity[0];
            oldVel[1] = ps->oldVelocity[1];

            /* Check if old velocity magnitude is significant */
            {
                double mag2 = (double)(oldVel[0] * oldVel[0] + oldVel[1] * oldVel[1]);
                if (mag2 < 0.0001) {
                    /* Small velocity, just use inertiaMax */
                    accelspeed = inertiaMax_val;
                    goto apply;
                }
            }

            /* Compute new velocity direction */
            newVel[0] = accelspeed * wishdir[0] + velocity[0];
            newVel[1] = accelspeed * wishdir[1] + velocity[1];

            Vec2Normalize(oldVel);
            Vec2Normalize(newVel);

            /* dot = DotProduct2D(oldVel, newVel) */
            dot = oldVel[0] * newVel[0] + oldVel[1] * newVel[1];

            {
                float inertiaAngle_val = *(float *)((byte *)(*(void **)imp_inertiaAngle) + 8);
                if (dot >= inertiaAngle_val) {
                    /* Direction change within tolerance */
                    goto apply;
                }
            }

            /* Direction change too large, clamp to inertiaMax */
            if (*(byte *)((byte *)(*(void **)imp_inertiaDebug) + 8)) {
                Com_Printf("angle is %f (oldVel is (%f,%f), vel is (%f, %f))\n",
                    (double)dot, (double)oldVel[0], (double)oldVel[1],
                    (double)newVel[0], (double)newVel[1]);
                Com_Printf("clamping acceleration from %f to %f\n",
                    (double)accelspeed,
                    (double)*(float *)((byte *)(*(void **)imp_inertiaMax) + 8));
            }
            accelspeed = *(float *)((byte *)(*(void **)imp_inertiaMax) + 8);
        }
    }

apply:
    /* Apply acceleration: velocity += wishdir * accelspeed */
    velocity[0] += wishdir[0] * accelspeed;
    velocity[1] += wishdir[1] * accelspeed;
    velocity[2] += wishdir[2] * accelspeed;
}

static void PM_Accelerate(pml_t *pml) {
    /* Register-convention stub: not callable from standard C.
       See PM_Accelerate_impl for the actual algorithm. */
    (void)pml;
}
#endif
