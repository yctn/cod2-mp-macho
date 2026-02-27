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

static const dvar_t *mantle_enable; /* 0x4ed300 */
static const dvar_t *mantle_debug; /* 0x4ed30c */
static const dvar_t *mantle_check_range; /* 0x4ed314 */
static const dvar_t *mantle_check_radius; /* 0x4ed318 */
static const dvar_t *mantle_check_angle; /* 0x4ed310 */
static const dvar_t *mantle_view_yawcap; /* 0x4ed304 */
static MantleAnimTransition s_mantleTrans[7]; /* 0x30aaa0 */
static char * s_mantleAnimNames[11]; /* 0x30ab00 */
static char (*s_mantleAnims)[64]; /* 0x4ed308 */

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
static void __attribute__((regparm(3))) Mantle_GetAnimDelta(byte *mstate, int time, float *delta);
void Mantle_Move(pmove_t *pm, playerState_t *ps, pml_t *pml);
static Bool __attribute__((regparm(3))) Mantle_CheckLedge(pmove_t *pm, pml_t *pml, byte *mresults, float height);
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
    *(int *)((byte *)ps + 0x5c8) &= ~8;
}

/* line 825 */
void Mantle_CapView(playerState_t *ps)
{
    byte *p = (byte *)ps;
    float yawcap;
    float delta;
    float negcap;

    if (!mantle_enable->current.enabled)
        return;

    delta = AngleDelta(*(float *)(p + 0xec), *(float *)(p + 0x5bc));

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
            *(int *)(p + 0x58) += viewDelta;
        }

        *(float *)(p + 0xec) = AngleNormalize360Accurate(clampVal + *(float *)(p + 0x5bc));
    }
}

/* line 868 */
Bool Mantle_IsWeaponInactive(playerState_t *ps)
{
    byte *p = (byte *)ps;

    if (!mantle_enable->current.enabled)
        return 0;

    if (!(*(int *)(p + 0xc) & 4))
        return 0;

    {
        int mantleState = *(int *)(p + 0x5c4);
        return s_mantleTrans[mantleState].overAnimIndex != 10;
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
static void __attribute__((regparm(3))) Mantle_GetAnimDelta(byte *mstate, int time, float *delta)
{
    float rot[4];
    float trans[3];
    int upLen;
    int overLen = 0;

    int mantleIdx = *(int *)(mstate + 8);
    upLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[mantleIdx].upAnimIndex);

    if (*(int *)(mstate + 0xc) & 1) {
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

    VectorAngleMultiply(delta, *(float *)mstate);
}

/* line 744 */
void Mantle_Move(pmove_t *pm, playerState_t *ps, pml_t *pml)
{
    byte *mstate;
    int upLen;
    int mantleLength;
    int prevTime;
    int deltaTime;
    float prevTrans[3];
    float trans[3];
    float scale;

    if (!mantle_enable->current.enabled)
        return;

    mstate = (byte *)ps + 0x5bc;

    *(int *)(mstate + 0xc) &= ~8;

    if (*(int *)(mstate + 0xc) & 2) {
        BG_AddPredictableEventToPlayerstate(0x8d, 0, ps);
    }

    /* Get up anim length */
    {
        int idx = *(int *)(mstate + 8);
        upLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].upAnimIndex);
    }

    /* Get over anim length if applicable */
    {
        int overLen = 0;
        if (*(int *)(mstate + 0xc) & 1) {
            int idx = *(int *)(mstate + 8);
            overLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].overAnimIndex);
        }
        mantleLength = upLen + overLen;
    }

    prevTime = *(int *)(mstate + 4);

    {
        int newTime = prevTime + *(int *)((byte *)pml + 0x28);
        if (newTime > mantleLength)
            newTime = mantleLength;
        *(int *)(mstate + 4) = newTime;
    }

    deltaTime = *(int *)(mstate + 4) - prevTime;

    /* Get animation deltas */
    Mantle_GetAnimDelta(mstate, prevTime, prevTrans);
    Mantle_GetAnimDelta(mstate, *(int *)(mstate + 4), trans);

    /* Determine current animation to play */
    {
        int idx = *(int *)(mstate + 8);
        int currentUpLen;
        int *animDef;

        /* Re-query up anim length */
        currentUpLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].upAnimIndex);
        if (*(int *)(mstate + 0xc) & 1) {
            XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].overAnimIndex);
        }

        if (currentUpLen < *(int *)(mstate + 4)) {
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
    *(float *)((byte *)ps + 0x14) += trans[0];
    *(float *)((byte *)ps + 0x18) += trans[1];
    *(float *)((byte *)ps + 0x1c) += trans[2];

    /* Compute velocity */
    scale = 1.0f / ((float)deltaTime * 0.001f);
    *(float *)((byte *)ps + 0x20) = trans[0] * scale;
    *(float *)((byte *)ps + 0x24) = trans[1] * scale;
    *(float *)((byte *)ps + 0x28) = trans[2] * scale;

    /* Check if mantle completed */
    if (mantleLength == *(int *)(mstate + 4)) {
        *(int *)((byte *)ps + 0xc) &= ~4;
        *(byte *)((byte *)pm + 0xe5) = 0;

        if (*(int *)(mstate + 0xc) & 1) {
            BG_AnimScriptEvent(ps, 3, 0, 1);
        }

        if (*(int *)(mstate + 0xc) & 4) {
            BG_AddPredictableEventToPlayerstate(0x8c, 0, ps);
            *(int *)((byte *)ps + 0xa0) &= ~0x4000;
        }
    }
}

/* line 418 - regparm(3): eax=pm, edx=pml, ecx=mresults; xmm0=height */
static Bool __attribute__((regparm(3))) Mantle_CheckLedge(pmove_t *pm, pml_t *pml, byte *mresults, float height)
{
    byte *ps = (byte *)*(void **)pm;
    float playerRadius = *(float *)(ps + 0x578);
    float mins[3], maxs[3];
    float start[3], end[3];
    byte trace[0x60];

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

    /* Start from mantleDir intersection point */
    start[0] = *(float *)(mresults + 0xc);
    start[1] = *(float *)(mresults + 0x10);
    start[2] = *(float *)(mresults + 0x14);

    /* Apply height offset */
    start[2] += height;

    /* End = start + mantleDir * 16 */
    end[0] = *(float *)mresults * 16.0f + start[0];
    end[1] = *(float *)(mresults + 4) * 16.0f + start[1];
    end[2] = *(float *)(mresults + 8) * 16.0f + start[2];

    /* Forward trace */
    PM_trace(pm, trace, start, mins, maxs, end, *(int *)(ps + 0xcc), *(int *)((byte *)pm + 0x3c));

    if (*(byte *)(trace + 0x23) || *(float *)trace < 1.0f) {
        /* Failed first trace */
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Can't reach ledge from below");
        return 0;
    }

    /* Now trace down from forward position to find the ledge surface */
    start[0] = end[0];
    start[1] = end[1];
    start[2] = end[2];
    end[2] = *(float *)(mresults + 0x14) + 18.0f;

    PM_trace(pm, trace, start, mins, maxs, end, *(int *)(ps + 0xcc), *(int *)((byte *)pm + 0x3c));

    if (*(byte *)(trace + 0x23) || *(float *)trace == 1.0f) {
        /* No surface found */
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Can't find ledge");
        return 0;
    }

    /* Check surface normal Z >= 0.7 (walkable) */
    if (*(float *)(trace + 0xc) < 0.7f) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Surface too steep");
        return 0;
    }

    /* Store ledge 'to' position */
    *(float *)(mresults + 0x18) = end[0];
    *(float *)(mresults + 0x1c) = end[1];
    *(float *)(mresults + 0x20) = start[2] + (end[2] - start[2]) * *(float *)trace;

    /* Set maxs Z for standing check */
    maxs[2] = 50.0f;

    /* Check standing room on ledge */
    {
        float *ledgeTo = (float *)(mresults + 0x18);
        PM_trace(pm, trace, ledgeTo, mins, maxs, ledgeTo, *(int *)(ps + 0xcc), *(int *)((byte *)pm + 0x3c));
        if (*(byte *)(trace + 0x23)) {
            if (mantle_debug->current.enabled)
                Com_Printf("%s\n", "Mantle Failed: No room on ledge");
            return 0;
        }
    }

    /* Ledge found - set hint flags */
    *(int *)(ps + 0x5c8) |= 8;
    *(int *)(mresults + 0x30) |= 8;

    if (mantle_debug->current.enabled)
        Com_Printf("%s\n", "Mantle: Found ledge");

    /* Check if player wants to mantle (sprint held) */
    if (!(*(byte *)((byte *)pm + 9) & 4))
        return 1;

    /* Compute mantle target position */
    if (*(int *)(mresults + 0x30) & 1) {
        /* Use player bounding box for over-wall mantle */
        float wallMins[3], wallMaxs[3];
        float wallStart[3], wallEnd[3];
        byte wallTrace[0x24];

        wallMins[0] = *(float *)(ps + 0x56c);
        wallMins[1] = *(float *)(ps + 0x570);
        wallMins[2] = *(float *)(ps + 0x574);
        wallMaxs[0] = *(float *)(ps + 0x578);
        wallMaxs[1] = *(float *)(ps + 0x57c);
        wallMaxs[2] = 50.0f;

        wallStart[0] = *(float *)(mresults + 0x18);
        wallStart[1] = *(float *)(mresults + 0x1c);
        wallStart[2] = *(float *)(mresults + 0x20);

        /* End = ledge position + mantleDir * 31 */
        wallEnd[0] = *(float *)mresults * 31.0f + wallStart[0];
        wallEnd[1] = *(float *)(mresults + 4) * 31.0f + wallStart[1];
        wallEnd[2] = *(float *)(mresults + 8) * 31.0f + wallStart[2] - 18.0f;

        PM_trace(pm, wallTrace, wallStart, wallMins, wallMaxs, wallEnd, *(int *)(ps + 0xcc), *(int *)((byte *)pm + 0x3c));

        if (!*(byte *)(wallTrace + 0x23) && *(float *)wallTrace >= 1.0f) {
            /* Clear path over wall */
            *(float *)(mresults + 0x24) = wallEnd[0];
            *(float *)(mresults + 0x28) = wallEnd[1];
            *(float *)(mresults + 0x2c) = wallStart[2] + (wallEnd[2] - wallStart[2]) * *(float *)wallTrace;
        } else {
            /* Can't get over wall - clear flag and use ledge position */
            *(int *)(mresults + 0x30) &= ~1;
            *(float *)(mresults + 0x24) = *(float *)(mresults + 0x18);
            *(float *)(mresults + 0x28) = *(float *)(mresults + 0x1c);
            *(float *)(mresults + 0x2c) = *(float *)(mresults + 0x20);
        }
    } else {
        /* Normal mantle up - target is ledge position */
        *(float *)(mresults + 0x24) = *(float *)(mresults + 0x18);
        *(float *)(mresults + 0x28) = *(float *)(mresults + 0x1c);
        *(float *)(mresults + 0x2c) = *(float *)(mresults + 0x20);
    }

    /* Check if player can stand on ledge */
    if (!(*(int *)(ps + 0xa0) & 4)) {
        /* Crouch check: trace at ledge destination */
        float *pMins = (float *)(ps + 0x56c);
        float *pMaxs = (float *)(ps + 0x578);
        float *ledgeTo = (float *)(mresults + 0x18);
        float *target = (float *)(mresults + 0x24);

        PM_trace(pm, trace, ledgeTo, pMins, pMaxs, ledgeTo, *(int *)(ps + 0xcc), *(int *)((byte *)pm + 0x3c));
        if (*(byte *)(trace + 0x23))
            *(int *)(mresults + 0x30) |= 2;

        PM_trace(pm, trace, target, pMins, pMaxs, target, *(int *)(ps + 0xcc), *(int *)((byte *)pm + 0x3c));
        if (!*(byte *)(trace + 0x23))
            *(int *)(mresults + 0x30) |= 4;
    }

    /* Set up mantle state */
    {
        byte *mantleState = ps + 0x5bc;
        float heightDiff;
        int bestTrans = 0;
        float bestDist;
        int mantleTime;
        float animDelta[3];

        *(float *)mantleState = vectoyaw((float *)mresults);
        *(int *)(mantleState + 4) = 0;

        /* Find best matching mantle transition by height */
        heightDiff = *(float *)(mresults + 0x20) - *(float *)(mresults + 0x14);
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

        *(int *)(mantleState + 8) = bestTrans;
        *(int *)(mantleState + 0xc) = *(int *)(mresults + 0x30);

        /* Compute total mantle time */
        {
            int idx = bestTrans;
            int upAnimLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].upAnimIndex);
            int overAnimLen = 0;
            if (*(int *)(mantleState + 0xc) & 1) {
                overAnimLen = XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[idx].overAnimIndex);
            }
            mantleTime = upAnimLen + overAnimLen;
        }

        /* Compute initial position offset */
        Mantle_GetAnimDelta(mantleState, mantleTime, animDelta);
        {
            float *pos = (float *)(ps + 0x14);
            pos[0] = *(float *)(mresults + 0x24) - animDelta[0];
            pos[1] = *(float *)(mresults + 0x28) - animDelta[1];
            pos[2] = *(float *)(mresults + 0x2c) - animDelta[2];
        }

        *(int *)(ps + 0xc) |= 4;
        *(int *)(ps + 0xa0) |= 0x4000;

        /* Set pm->mantleEndPos */
        *(float *)((byte *)pm + 0xe8) = *(float *)(mresults + 0x24);
        *(float *)((byte *)pm + 0xec) = *(float *)(mresults + 0x28);
        *(float *)((byte *)pm + 0xf0) = *(float *)(mresults + 0x2c);
        *(int *)((byte *)pm + 0xf4) = mantleTime;
        *(byte *)((byte *)pm + 0xe5) = 1;
    }

    return 1;
}

/* line 669 */
void Mantle_Check(pmove_t *pm, pml_t *pml)
{
    playerState_t *ps;
    byte *psb;
    float playerRadius;
    float mins[3], maxs[3];
    float start[3], end[3];
    float traceDir[3];
    float mantleDir[3];
    byte trace[0x38];
    float len;
    byte mresults[0x38];

    if (mantle_debug->current.enabled)
        Com_Printf("%s\n", "Mantle_Check");

    if (!mantle_enable->current.enabled) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle disabled");
        return;
    }

    ps = *(playerState_t **)pm;
    psb = (byte *)ps;

    /* Clear mantle hint */
    *(int *)(psb + 0x5c8) &= ~8;

    /* Check player movement type */
    if (*(int *)(psb + 4) > 5) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Bad movement type");
        return;
    }

    /* Check not already mantling */
    if (*(int *)(psb + 0xc) & 4) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Already mantling");
        return;
    }

    /* Check not prone or crouch-to-prone */
    if (*(int *)(psb + 0xa0) & 0xc) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Prone or going prone");
        return;
    }

    /* Check weapon state */
    if (*(int *)(psb + 0xd8) >= 0x11 && *(int *)(psb + 0xd8) <= 0x16) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Bad weapon state");
        return;
    }

    /* Set up trace parameters */
    {
        float checkRadius;
        float scale;
        float checkRange;

        playerRadius = *(float *)(psb + 0x578);
        checkRadius = mantle_check_radius->current.value;

        mins[0] = -checkRadius;
        mins[1] = -checkRadius;
        mins[2] = *(float *)(psb + 0x574);

        maxs[0] = checkRadius;
        maxs[1] = checkRadius;
        maxs[2] = *(float *)(psb + 0x580);

        scale = playerRadius - checkRadius;
        checkRange = scale + mantle_check_range->current.value;

        traceDir[0] = *(float *)((byte *)pml);
        traceDir[1] = *(float *)((byte *)pml + 4);
        traceDir[2] = 0.0f;

        Vec3Normalize(traceDir);

        /* Start behind player, end in front */
        start[0] = *(float *)(psb + 0x14) + traceDir[0] * (-scale);
        start[1] = *(float *)(psb + 0x18) + traceDir[1] * (-scale);
        start[2] = *(float *)(psb + 0x1c) + traceDir[2] * (-scale);

        end[0] = *(float *)(psb + 0x14) + traceDir[0] * checkRange;
        end[1] = *(float *)(psb + 0x18) + traceDir[1] * checkRange;
        end[2] = *(float *)(psb + 0x1c) + traceDir[2] * checkRange;
    }

    PM_trace(pm, trace, start, mins, maxs, end, *(int *)(psb + 0xcc), 0x1000000);

    /* Check we hit something */
    if (*(short *)(trace + 0x22) == 0) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: No wall found");
        return;
    }

    /* Check we didn't go full distance (i.e. hit a wall) */
    if (*(float *)trace == 1.0f) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Trace went full distance");
        return;
    }

    /* Check surface has mantle flag */
    if (!(*(int *)(trace + 0x10) & 0x6000000)) {
        if (mantle_debug->current.enabled)
            Com_Printf("%s\n", "Mantle Failed: Surface not mantleable");
        return;
    }

    /* Get mantle direction from wall normal */
    mantleDir[0] = -*(float *)(trace + 4);
    mantleDir[1] = -*(float *)(trace + 8);
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
    *(float *)(mresults) = mantleDir[0];
    *(float *)(mresults + 4) = mantleDir[1];
    *(float *)(mresults + 8) = mantleDir[2];

    /* Set player position */
    *(float *)(mresults + 0xc) = *(float *)(psb + 0x14);
    *(float *)(mresults + 0x10) = *(float *)(psb + 0x18);
    *(float *)(mresults + 0x14) = *(float *)(psb + 0x1c);

    /* Check if trace hit indicated wall is thin enough to mantle over */
    if (*(byte *)(trace + 0x13) & 4) {
        *(int *)(mresults + 0x30) |= 1;
    }

    /* Try three different ledge heights */
    if (Mantle_CheckLedge(pm, pml, mresults, 60.0f))
        return;
    if (Mantle_CheckLedge(pm, pml, mresults, 40.0f))
        return;
    Mantle_CheckLedge(pm, pml, mresults, 20.0f);
}
