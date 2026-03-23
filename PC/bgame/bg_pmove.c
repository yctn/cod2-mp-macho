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
extern const dvar_t *player_footstepsThreshhold; /* 0x0 */
extern const dvar_t *stopspeed; /* 0x0 */
extern const dvar_t *inertiaMax; /* 0x0 */
extern const dvar_t *inertiaAngle; /* 0x0 */
extern const dvar_t *inertiaDebug; /* 0x0 */
__attribute__((used, aligned(4)))
UInt32 viewLerp_StandCrouch[32] = {
    0x00000000, 0x42700000, 0x00000000, 0x00000001, 0x426e0000, 0x00000000, 0x00000004, 0x426a0000,
    0x00000000, 0x0000001e, 0x42600000, 0x00000000, 0x00000050, 0x42300000, 0x00000000, 0x0000005a,
    0x42260000, 0x00000000, 0x0000005f, 0x42220000, 0x00000000, 0x00000064, 0x42200000, 0x00000000,
    0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
}; /* 0x30a880 */
__attribute__((used, aligned(4)))
UInt32 viewLerp_CrouchStand[32] = {
    0x00000000, 0x42200000, 0x00000000, 0x00000005, 0x42220000, 0x00000000, 0x0000000a, 0x42260000,
    0x00000000, 0x00000014, 0x42300000, 0x00000000, 0x00000046, 0x42600000, 0x00000000, 0x00000060,
    0x426a0000, 0x00000000, 0x00000063, 0x426e0000, 0x00000000, 0x00000064, 0x42700000, 0x00000000,
    0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
}; /* 0x30a7a0 */
__attribute__((used, aligned(4)))
UInt32 viewLerp_CrouchProne[40] = {
    0x00000000, 0x42200000, 0x00000000, 0x0000000b, 0x42180000, 0x00000000, 0x00000016, 0x42040000,
    0x00000000, 0x00000022, 0x41c80000, 0x00000000, 0x0000002d, 0x41800000, 0x00000000, 0x00000032,
    0x41700000, 0x00000000, 0x00000037, 0x41800000, 0x00000000, 0x00000046, 0x41900000, 0x00000000,
    0x0000005a, 0x41880000, 0x00000000, 0x00000064, 0x41300000, 0x00000000, 0xffffffff, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
}; /* 0x30a900 */
__attribute__((used, aligned(4)))
UInt32 viewLerp_ProneCrouch[24] = {
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
void PM_trace(pmove_t *pm, trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentMask) {
    /* Look up the trace handler from pmoveHandlers[pm->handler].trace and tail-call it. */
    unsigned char handlerByte = pm->handler;
    pmove_trace handler = pmoveHandlers[handlerByte].trace;
    handler(results, start, mins, maxs, end, passEntityNum, contentMask);
}

/* line 294 */
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

/* line 3954 */
void PM_SetProneMovementOverride(playerState_t *ps)
{
    int flags = ps->pm_flags;
    if (flags & 1)
        ps->pm_flags = flags | 0x800;
}

/* line 4728 */
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

/* line 3530 */
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

/* line 2723 */
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
        float threshold = player_footstepsThreshhold->current.value;
        return pm->xyspeed >= threshold;
    }
}

/* line 330 */
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

/* line 478 */
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
        float stopspeed_val = stopspeed->current.value;
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
        float inertiaMax_val = inertiaMax->current.value;
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
                float inertiaAngle_val = inertiaAngle->current.value;
                if (dot >= inertiaAngle_val) {
                    /* Direction change within tolerance */
                    goto apply;
                }
            }

            /* Direction change too large, clamp to inertiaMax */
            if (inertiaDebug->current.enabled) {
                Com_Printf("angle is %f (oldVel is (%f,%f), vel is (%f, %f))\n",
                    (double)dot, (double)oldVel[0], (double)oldVel[1],
                    (double)newVel[0], (double)newVel[1]);
                Com_Printf("clamping acceleration from %f to %f\n",
                    (double)accelspeed,
                    (double)inertiaMax->current.value);
            }
            accelspeed = inertiaMax->current.value;
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
