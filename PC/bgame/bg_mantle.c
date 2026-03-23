/* Converted to C from ASM: bg_mantle.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_mantle.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

static inline float fabsf_local(float x) { return x < 0 ? -x : x; }

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static const dvar_t *mantle_enable; /* mantle_enable */
static const dvar_t *mantle_debug; /* mantle_debug */
static const dvar_t *mantle_check_range; /* mantle_check_range */
static const dvar_t *mantle_check_radius; /* mantle_check_radius */
static const dvar_t *mantle_check_angle; /* mantle_check_angle */
static const dvar_t *mantle_view_yawcap; /* mantle_view_yawcap */
extern const char str_0021dfa4[];
extern const char str_0021dfb4[];
extern const char str_0021dfc4[];
extern const char str_0021dfd4[];
extern const char str_0021dfe4[];
extern const char str_0021dff4[];
extern const char str_0021e004[];
extern const char str_0021e014[];
extern const char str_0021e024[];
extern const char str_0021e038[];
extern const char str_0021e04c[];

__attribute__((used, aligned(4)))
UInt32 s_mantleTrans[24] = {
    0x00000001, 0x00000008, 0x42640000, 0x00000002, 0x00000008, 0x424c0000,
    0x00000003, 0x00000009, 0x42340000, 0x00000004, 0x00000009, 0x421c0000,
    0x00000005, 0x00000009, 0x42040000, 0x00000006, 0x0000000a, 0x41d80000,
    0x00000007, 0x0000000a, 0x41a80000, 0x00000000, 0x00000000, 0x00000000,
}; /* 0x30aaa0 */
__attribute__((used, aligned(4)))
UInt32 s_mantleAnimNames[16] = {
    (UInt32)str_0021dfa4, (UInt32)str_0021dfb4, (UInt32)str_0021dfc4, (UInt32)str_0021dfd4,
    (UInt32)str_0021dfe4, (UInt32)str_0021dff4, (UInt32)str_0021e004, (UInt32)str_0021e014,
    (UInt32)str_0021e024, (UInt32)str_0021e038, (UInt32)str_0021e04c, 0,
    0, 0, 0, 0,
}; /* 0x30ab00 */
static char (*s_mantleAnims)[64]; /* s_mantleAnims */

#define s_mantleTrans ((MantleAnimTransition *)s_mantleTrans)
#define s_mantleAnimNames ((char **)s_mantleAnimNames)

extern const dvar_t *Dvar_RegisterBool(const char *name, int value, int flags);
extern const dvar_t *Dvar_RegisterFloat(const char *name, float value, float min, float max, int flags);
extern void *Hunk_AllocAlignInternal(int size, int align);
extern void *XAnimCreateAnims(const char *name, int count, void *allocFunc);
extern void XAnimBlend(void *anims, int parent, char *name, int count, int flags, int p6);
extern void XAnimPrecache(const char *name, void *allocFunc);
extern void XAnimCreate(void *anims, int index, const char *name);
extern void XAnimGetAbsDelta(void *anims, int animIndex, float *rot, float *delta, float frac);
extern int XAnimGetLengthMsec(void *anims, int animIndex);
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern float AngleDelta(float a, float b);
extern float AngleNormalize360Accurate(float a);
extern void VectorAngleMultiply(float *trans, float yaw);
extern void BG_AddPredictableEventToPlayerstate(int event, int param, playerState_t *ps);
extern void BG_AnimScriptAnimation(playerState_t *ps, int anim, int *animDef, int force);
extern void BG_AnimScriptEvent(playerState_t *ps, int anim, int p3, int p4);
extern void PM_trace(pmove_t *pm, void *trace, float *start, float *mins, float *maxs, float *end, int entityNum, int contentMask);
extern const char *va(const char *fmt, ...);
extern float Vec3Normalize(float *v);
extern float vectoyaw(float *v);
extern double acos(double x);

void Mantle_RegisterDvars(void);
static void * MantleXAnimPrecacheAlloc(int size);
void Mantle_ShutdownAnims(void);
void Mantle_ClearHint(playerState_t *ps);
void Mantle_CapView(playerState_t *ps);
Bool Mantle_IsWeaponInactive(playerState_t *ps);
void Mantle_CreateAnims(MantleAnimAlloc xanimAlloc);
static void __attribute_regparm__(3) Mantle_GetAnimDelta(MantleState *mstate, int time, float *delta);
void Mantle_Move(pmove_t *pm, playerState_t *ps, pml_t *pml);
static Bool __attribute_regparm__(3) Mantle_CheckLedge(pmove_t *pm, pml_t *pml, byte *mresults, float height);
void Mantle_Check(pmove_t *pm, pml_t *pml);

/* line 161 */
void Mantle_RegisterDvars(void)
{
    mantle_enable = Dvar_RegisterBool("mantle_enable", 1, 0x1180);
    mantle_debug = Dvar_RegisterBool("mantle_debug", 0, 0x1180);
    mantle_check_range = Dvar_RegisterFloat("mantle_check_range", 20.0f, 0.0f, 128.0f, 0x1180);
    mantle_check_radius = Dvar_RegisterFloat("mantle_check_radius", 0.1f, 0.0f, 15.0f, 0x1180);
    mantle_check_angle = Dvar_RegisterFloat("mantle_check_angle", 60.0f, 0.0f, 180.0f, 0x1180);
    mantle_view_yawcap = Dvar_RegisterFloat("mantle_view_yawcap", 60.0f, 0.0f, 180.0f, 0x1180);
}

/* line 183 */
static void * MantleXAnimPrecacheAlloc(int size)
{
    return Hunk_AllocAlignInternal(size, 4);
}

/* line 577 */
void Mantle_ShutdownAnims(void)
{
    s_mantleAnims = 0;
}

/* line 857 */
void Mantle_ClearHint(playerState_t *ps)
{
    ps->mantleState.flags &= ~8;
}

/* line 825 */
void Mantle_CapView(playerState_t *ps)
{
    float yawcap;
    float delta;
    float negcap;

    if (!mantle_enable->current.enabled)
        return;

    delta = AngleDelta(ps->viewangles[1], ps->mantleState.yaw);

    yawcap = mantle_view_yawcap->current.value;
    negcap = -yawcap;

    if (delta < negcap || delta > yawcap) {
        /* Wrap delta into [-yawcap, yawcap] range */
        while (delta < negcap)
            delta += yawcap;
        while (delta > yawcap)
            delta -= yawcap;
    } else {
        return;
    }

    /* Compute clamped value: select negcap if delta > 0, else yawcap */
    {
        float clampVal;
        if (delta > 0.0f)
            clampVal = negcap;
        else
            clampVal = yawcap;

        /* Apply view angle correction */
        {
            int viewDelta = (int)(delta * 182.04444885253906f) & 0xffff;
            ps->delta_angles[1] += viewDelta;
        }

        ps->viewangles[1] = AngleNormalize360Accurate(clampVal + ps->mantleState.yaw);
    }
}

/* line 868 */
Bool Mantle_IsWeaponInactive(playerState_t *ps)
{
    if (!mantle_enable->current.enabled)
        return 0;

    if (!(ps->pm_flags & 4))
        return 0;

    {
        int mantleStateIdx = ps->mantleState.transIndex;
        return s_mantleTrans[mantleStateIdx].overAnimIndex != 10;
    }
}

/* line 519 */
void Mantle_CreateAnims(MantleAnimAlloc xanimAlloc)
{
    int i;
    float rot[4];
    float delta[3];

    if (s_mantleAnims != 0)
        return;

    s_mantleAnims = XAnimCreateAnims("PLAYER_MANTLE", 11, xanimAlloc);
    XAnimBlend(s_mantleAnims, 0, s_mantleAnimNames[0], 10, 1, 0);

    for (i = 1; i < 11; i++) {
        XAnimPrecache(s_mantleAnimNames[i], MantleXAnimPrecacheAlloc);
        XAnimCreate(s_mantleAnims, i, s_mantleAnimNames[i]);
    }

    for (i = 0; i < 7; i++) {
        int upAnimIdx = s_mantleTrans[i].upAnimIndex;
        int overAnimIdx = s_mantleTrans[i].overAnimIndex;

        /* Check up anim X translation ~= 16 */
        XAnimGetAbsDelta(s_mantleAnims, upAnimIdx, rot, delta, 1.0f);
        if (fabsf_local(delta[0] - 16.0f) > 1.0f)
            Com_Error(1, "Mantle anim [%s] has X translation %f, should be %f\n", s_mantleAnimNames[upAnimIdx], (double)delta[0], 16.0);
        if (fabsf_local(delta[1]) > 1.0f)
            Com_Error(1, "Mantle anim [%s] has Y translation %f, should be %f\n", s_mantleAnimNames[upAnimIdx], (double)delta[1], 0.0);
        if (fabsf_local(delta[2] - s_mantleTrans[i].height) > 1.0f)
            Com_Error(1, "Mantle anim [%s] has Z translation %f, should be %f\n", s_mantleAnimNames[upAnimIdx], (double)delta[2], (double)s_mantleTrans[i].height);

        /* Check over anim X translation ~= 31 */
        XAnimGetAbsDelta(s_mantleAnims, overAnimIdx, rot, delta, 1.0f);
        if (fabsf_local(delta[0] - 31.0f) > 1.0f)
            Com_Error(1, "Mantle anim [%s] has X translation %f, should be %f\n", s_mantleAnimNames[overAnimIdx], (double)delta[0], 31.0);
        if (fabsf_local(delta[1]) > 1.0f)
            Com_Error(1, "Mantle anim [%s] has Y translation %f, should be %f\n", s_mantleAnimNames[overAnimIdx], (double)delta[1], 0.0);
        if (fabsf_local(delta[2] + 18.0f) > 1.0f)
            Com_Error(1, "Mantle anim [%s] has Z translation %f, should be %f\n", s_mantleAnimNames[overAnimIdx], (double)delta[2], -18.0);
    }
}

/* line 263 - regparm(3): eax=mstate, edx=time, ecx=delta */
static void __attribute_regparm__(3) Mantle_GetAnimDelta(MantleState *mstate, int time, float *delta)
{
    float rot[4];
    float trans[3];
    int upLen;
    int overLen = 0;

    int mantleIdx = mstate->transIndex;
    upLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[mantleIdx].upAnimIndex);

    if (mstate->flags & 1) {
        overLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[mantleIdx].overAnimIndex);
    }

    if (upLen >= time) {
        /* Within up anim */
        float frac = (float)time / (float)upLen;
        XAnimGetAbsDelta(s_mantleAnims, s_mantleTrans[mantleIdx].upAnimIndex, rot, delta, frac);
    } else {
        /* Past up anim - get full up anim delta, then partial over anim */
        XAnimGetAbsDelta(s_mantleAnims, s_mantleTrans[mantleIdx].upAnimIndex, rot, trans, 1.0f);

        {
            float overFrac = (float)(time - upLen) / (float)overLen;
            XAnimGetAbsDelta(s_mantleAnims, s_mantleTrans[mantleIdx].overAnimIndex, rot, delta, overFrac);
        }

        /* Add up anim's full translation */
        delta[0] += trans[0];
        delta[1] += trans[1];
        delta[2] += trans[2];
    }

    VectorAngleMultiply(delta, mstate->yaw);
}

/* line 744 */
void Mantle_Move(pmove_t *pm, playerState_t *ps, pml_t *pml)
{
    MantleState *mstate;
    int upLen;
    int mantleLength;
    int prevTime;
    int deltaTime;
    float prevTrans[3];
    float trans[3];
    float scale;

    if (!mantle_enable->current.enabled)
        return;

    mstate = &ps->mantleState;

    mstate->flags &= ~8;

    if (mstate->flags & 2) {
        BG_AddPredictableEventToPlayerstate(0x8d, 0, ps);
    }

    /* Get up anim length */
    {
        int idx = mstate->transIndex;
        upLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].upAnimIndex);
    }

    /* Get over anim length if applicable */
    {
        int overLen = 0;
        if (mstate->flags & 1) {
            int idx = mstate->transIndex;
            overLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].overAnimIndex);
        }
        mantleLength = upLen + overLen;
    }

    prevTime = mstate->timer;

    {
        int newTime = prevTime + pml->msec;
        if (newTime > mantleLength)
            newTime = mantleLength;
        mstate->timer = newTime;
    }

    deltaTime = mstate->timer - prevTime;

    /* Get animation deltas */
    Mantle_GetAnimDelta(mstate, prevTime, prevTrans);
    Mantle_GetAnimDelta(mstate, mstate->timer, trans);

    /* Determine current animation to play */
    {
        int idx = mstate->transIndex;
        int currentUpLen;
        int *animDef;

        /* Re-query up anim length */
        currentUpLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].upAnimIndex);
        if (mstate->flags & 1) {
            XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].overAnimIndex);
        }

        if (currentUpLen < mstate->timer) {
            animDef = (int *)&s_mantleTrans[idx].overAnimIndex;
        } else {
            animDef = (int *)&s_mantleTrans[idx].upAnimIndex;
        }

        BG_AnimScriptAnimation(ps, 3, animDef + 5, 1);
    }

    /* Compute delta movement */
    trans[0] -= prevTrans[0];
    trans[1] -= prevTrans[1];
    trans[2] -= prevTrans[2];

    /* Apply position offset */
    ps->origin[0] += trans[0];
    ps->origin[1] += trans[1];
    ps->origin[2] += trans[2];

    /* Compute velocity */
    scale = 1.0f / ((float)deltaTime * 0.001f);
    ps->velocity[0] = trans[0] * scale;
    ps->velocity[1] = trans[1] * scale;
    ps->velocity[2] = trans[2] * scale;

    /* Check if mantle completed */
    if (mantleLength == mstate->timer) {
        ps->pm_flags &= ~4;
        pm->mantleStarted = 0;

        if (mstate->flags & 1) {
            BG_AnimScriptEvent(ps, 3, 0, 1);
        }

        if (mstate->flags & 4) {
            BG_AddPredictableEventToPlayerstate(0x8c, 0, ps);
            ps->eFlags &= ~0x4000;
        }
    }
}

/* line 418 - regparm(3): eax=pm, edx=pml, ecx=mresults; xmm0=height */
static Bool __attribute_regparm__(3) Mantle_CheckLedge(pmove_t *pm, pml_t *pml, byte *mresults_raw, float height)
{
    MantleResults *mr = (MantleResults *)mresults_raw;
    trace_t tr;
    trace_t wallTr;
    playerState_t *ps = pm->ps;
    float playerRadius = ps->maxs[0];
    float mins[3], maxs[3];
    float start[3], end[3];

    {
        const char *msg = va("Checking for ledge at %f units", (double)height);
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", msg);
    }

    /* Set up bounding box */
    mins[0] = -playerRadius;
    mins[1] = -playerRadius;
    mins[2] = 0.0f;
    maxs[0] = playerRadius;
    maxs[1] = playerRadius;
    maxs[2] = playerRadius * 2.0f;

    /* Start from mantleDir intersection point (startPos) */
    start[0] = mr->startPos[0];
    start[1] = mr->startPos[1];
    start[2] = mr->startPos[2];

    /* Apply height offset */
    start[2] += height;

    /* End = start + mantleDir * 16 */
    end[0] = mr->dir[0] * 16.0f + start[0];
    end[1] = mr->dir[1] * 16.0f + start[1];
    end[2] = mr->dir[2] * 16.0f + start[2];

    /* Forward trace */
    PM_trace(pm, &tr, start, mins, maxs, end, ps->clientNum, pm->tracemask);

    if (tr.startsolid || tr.fraction < 1.0f) {
        /* Failed first trace */
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Can't reach ledge from below");
        return 0;
    }

    /* Now trace down from forward position to find the ledge surface */
    start[0] = end[0];
    start[1] = end[1];
    start[2] = end[2];
    end[2] = mr->startPos[2] + 18.0f;

    PM_trace(pm, &tr, start, mins, maxs, end, ps->clientNum, pm->tracemask);

    if (tr.startsolid || tr.fraction == 1.0f) {
        /* No surface found */
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Can't find ledge");
        return 0;
    }

    /* Check surface normal Z >= 0.7 (walkable) */
    if (tr.normal[2] < 0.7f) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Surface too steep");
        return 0;
    }

    /* Store ledge position */
    mr->ledgePos[0] = end[0];
    mr->ledgePos[1] = end[1];
    mr->ledgePos[2] = start[2] + (end[2] - start[2]) * tr.fraction;

    /* Set maxs Z for standing check */
    maxs[2] = 50.0f;

    /* Check standing room on ledge */
    {
        PM_trace(pm, &tr, mr->ledgePos, mins, maxs, mr->ledgePos, ps->clientNum, pm->tracemask);
        if (tr.startsolid) {
            if (mantle_debug->current.enabled)
                Com_Printf("%s\n", "Mantle Failed: No room on ledge");
            return 0;
        }
    }

    /* Ledge found - set hint flags */
    ps->mantleState.flags |= 8;
    mr->flags |= 8;

    if (mantle_debug->current.enabled)
        Com_Printf("%s\n", "Mantle: Found ledge");

    /* Check if player wants to mantle (sprint held) */
    if (!(pm->cmd.buttons & 0x400))
        return 1;

    /* Compute mantle target position */
    if (mr->flags & 1) {
        /* Use player bounding box for over-wall mantle */
        float wallMins[3], wallMaxs[3];
        float wallStart[3], wallEnd[3];

        wallMins[0] = ps->mins[0];
        wallMins[1] = ps->mins[1];
        wallMins[2] = ps->mins[2];
        wallMaxs[0] = ps->maxs[0];
        wallMaxs[1] = ps->maxs[1];
        wallMaxs[2] = 50.0f;

        wallStart[0] = mr->ledgePos[0];
        wallStart[1] = mr->ledgePos[1];
        wallStart[2] = mr->ledgePos[2];

        /* End = ledge position + mantleDir * 31 */
        wallEnd[0] = mr->dir[0] * 31.0f + wallStart[0];
        wallEnd[1] = mr->dir[1] * 31.0f + wallStart[1];
        wallEnd[2] = mr->dir[2] * 31.0f + wallStart[2] - 18.0f;

        PM_trace(pm, &wallTr, wallStart, wallMins, wallMaxs, wallEnd, ps->clientNum, pm->tracemask);

        if (!wallTr.startsolid && wallTr.fraction >= 1.0f) {
            /* Clear path over wall */
            mr->endPos[0] = wallEnd[0];
            mr->endPos[1] = wallEnd[1];
            mr->endPos[2] = wallStart[2] + (wallEnd[2] - wallStart[2]) * wallTr.fraction;
        } else {
            /* Can't get over wall - clear flag and use ledge position */
            mr->flags &= ~1;
            mr->endPos[0] = mr->ledgePos[0];
            mr->endPos[1] = mr->ledgePos[1];
            mr->endPos[2] = mr->ledgePos[2];
        }
    } else {
        /* Normal mantle up - target is ledge position */
        mr->endPos[0] = mr->ledgePos[0];
        mr->endPos[1] = mr->ledgePos[1];
        mr->endPos[2] = mr->ledgePos[2];
    }

    /* Check if player can stand on ledge */
    if (!(ps->eFlags & 4)) {
        /* Crouch check: trace at ledge destination */
        float *pMins = ps->mins;
        float *pMaxs = ps->maxs;

        PM_trace(pm, &tr, mr->ledgePos, pMins, pMaxs, mr->ledgePos, ps->clientNum, pm->tracemask);
        if (tr.startsolid)
            mr->flags |= 2;

        PM_trace(pm, &tr, mr->endPos, pMins, pMaxs, mr->endPos, ps->clientNum, pm->tracemask);
        if (!tr.startsolid)
            mr->flags |= 4;
    }

    /* Set up mantle state */
    {
        MantleState *mantleState = &ps->mantleState;
        float heightDiff;
        int bestTrans = 0;
        float bestDist;
        int mantleTime;
        float animDelta[3];

        mantleState->yaw = vectoyaw(mr->dir);
        mantleState->timer = 0;

        /* Find best matching mantle transition by height */
        heightDiff = mr->ledgePos[2] - mr->startPos[2];
        bestDist = fabsf_local(s_mantleTrans[0].height - heightDiff);
        {
            int j;
            for (j = 1; j < 7; j++) {
                float dist = fabsf_local(s_mantleTrans[j].height - heightDiff);
                if (dist < bestDist) {
                    bestTrans = j;
                    bestDist = dist;
                }
            }
        }

        mantleState->transIndex = bestTrans;
        mantleState->flags = mr->flags;

        /* Compute total mantle time */
        {
            int idx = bestTrans;
            int upAnimLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].upAnimIndex);
            int overAnimLen = 0;
            if (mantleState->flags & 1) {
                overAnimLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].overAnimIndex);
            }
            mantleTime = upAnimLen + overAnimLen;
        }

        /* Compute initial position offset */
        Mantle_GetAnimDelta(mantleState, mantleTime, animDelta);
        {
            ps->origin[0] = mr->endPos[0] - animDelta[0];
            ps->origin[1] = mr->endPos[1] - animDelta[1];
            ps->origin[2] = mr->endPos[2] - animDelta[2];
        }

        ps->pm_flags |= 4;
        ps->eFlags |= 0x4000;

        /* Set pm->mantleEndPos */
        pm->mantleEndPos[0] = mr->endPos[0];
        pm->mantleEndPos[1] = mr->endPos[1];
        pm->mantleEndPos[2] = mr->endPos[2];
        pm->mantleDuration = mantleTime;
        pm->mantleStarted = 1;
    }

    return 1;
}

/* line 669 */
void Mantle_Check(pmove_t *pm, pml_t *pml)
{
    playerState_t *ps;
    float playerRadius;
    float mins[3], maxs[3];
    float start[3], end[3];
    float traceDir[3];
    float mantleDir[3];
    byte trace[0x38];
    float len;
    byte mresults[0x38];
    trace_t *tr;
    MantleResults *results;

    if (mantle_debug->current.enabled)
        Com_Printf("%s\n", "Mantle_Check");

    if (!mantle_enable->current.enabled) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle disabled");
        return;
    }

    ps = pm->ps;

    /* Clear mantle hint */
    ps->mantleState.flags &= ~8;

    /* Check player movement type */
    if (ps->pm_type > 5) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Bad movement type");
        return;
    }

    /* Check not already mantling */
    if (ps->pm_flags & 4) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Already mantling");
        return;
    }

    /* Check not prone or crouch-to-prone */
    if (ps->eFlags & 0xc) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Prone or going prone");
        return;
    }

    /* Check weapon state */
    if (ps->weaponstate >= 0x11 && ps->weaponstate <= 0x16) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Bad weapon state");
        return;
    }

    /* Set up trace parameters */
    {
        float checkRadius;
        float scale;
        float checkRange;

        playerRadius = ps->maxs[0];
        checkRadius = mantle_check_radius->current.value;

        mins[0] = -checkRadius;
        mins[1] = -checkRadius;
        mins[2] = ps->mins[2];

        maxs[0] = checkRadius;
        maxs[1] = checkRadius;
        maxs[2] = ps->maxs[2];

        scale = playerRadius - checkRadius;
        checkRange = scale + mantle_check_range->current.value;

        traceDir[0] = pml->forward[0];
        traceDir[1] = pml->forward[1];
        traceDir[2] = 0.0f;

        Vec3Normalize(traceDir);

        /* Start behind player, end in front */
        start[0] = ps->origin[0] + traceDir[0] * (-scale);
        start[1] = ps->origin[1] + traceDir[1] * (-scale);
        start[2] = ps->origin[2] + traceDir[2] * (-scale);

        end[0] = ps->origin[0] + traceDir[0] * checkRange;
        end[1] = ps->origin[1] + traceDir[1] * checkRange;
        end[2] = ps->origin[2] + traceDir[2] * checkRange;
    }

    tr = (trace_t *)trace;
    results = (MantleResults *)mresults;

    PM_trace(pm, trace, start, mins, maxs, end, ps->clientNum, 0x1000000);

    /* Check we hit something (allsolid or startsolid must be set) */
    if (tr->allsolid == 0 && tr->startsolid == 0) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: No wall found");
        return;
    }

    /* Check we didn't go full distance (i.e. hit a wall) */
    if (tr->fraction == 1.0f) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Trace went full distance");
        return;
    }

    /* Check surface has mantle flag */
    if (!(tr->surfaceFlags & 0x6000000)) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Surface not mantleable");
        return;
    }

    /* Get mantle direction from wall normal */
    mantleDir[0] = -tr->normal[0];
    mantleDir[1] = -tr->normal[1];
    mantleDir[2] = 0.0f;

    len = Vec3Normalize(mantleDir);
    if (len < 0.0001f) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Bad wall normal");
        return;
    }

    /* Check angle between trace direction and mantle direction */
    {
        float dot = traceDir[0] * mantleDir[0] + traceDir[1] * mantleDir[1] + traceDir[2] * mantleDir[2];
        double angle = acos((double)dot) * 57.29577951308232;
        if (angle > (double)mantle_check_angle->current.value) {
            if (mantle_debug->current.enabled)
                Com_Printf("%s\n", "Mantle Failed: Bad approach angle");
            return;
        }
    }

    /* Initialize mantle results */
    memset(mresults, 0, 0x38);

    /* Set mantle direction */
    results->dir[0] = mantleDir[0];
    results->dir[1] = mantleDir[1];
    results->dir[2] = mantleDir[2];

    /* Set player position */
    results->startPos[0] = ps->origin[0];
    results->startPos[1] = ps->origin[1];
    results->startPos[2] = ps->origin[2];

    /* Check if trace hit indicated wall is thin enough to mantle over */
    if (tr->surfaceFlags & 0x4000000) {
        results->flags |= 1;
    }

    /* Try three different ledge heights */
    if (Mantle_CheckLedge(pm, pml, mresults, 60.0f))
        return;
    if (Mantle_CheckLedge(pm, pml, mresults, 40.0f))
        return;
    Mantle_CheckLedge(pm, pml, mresults, 20.0f);
}
