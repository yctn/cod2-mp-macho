/* ASM dump from: cg_view_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_view_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <math.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/xanim/xanim_public.h"
 */

__attribute__((used, aligned(4))) vec_t maxs[3] = {
    4.0f, 4.0f, 4.0f,
}; /* 0x314660 */
__attribute__((used, aligned(4))) vec_t mins[5] = {
    -4.0f, -4.0f, -4.0f, 0.0f, 0.0f,
}; /* 0x31466c */

extern void Com_Printf(const char *fmt, ...);
extern void FX_FreeSystem(void);
extern void FX_InitSystem(int maxEffects);
extern int Cmd_Argc(void);
extern const char *CG_Argv(int arg);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int FX_RegisterEffect(const char *name);
extern void FX_PlaySimpleEffect(int effectIndex, const vec_t *origin);
extern double atof(const char *str);
extern int BG_GetViewmodelWeaponIndex(void *ps);
extern void *BG_GetWeaponDef(int weapIndex);
extern int BG_IsAimDownSightWeapon(int weapIndex);
extern float atanf(float x);
extern float sinf(float x);
extern double tan(double x);
extern void CL_ResetSkeletonCache(int level);
extern void CG_UpdateViewWeaponAnim(void *ps);
extern void CL_FX_AdjustCamera(void *refdef);
extern void FX_AdjustTime(int serverTime);
extern int CG_PointContents(const vec_t *point, int passEntityNum, int contentmask);
extern void CG_PredictPlayerState(void);
extern void AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern void CG_TraceCapsule(trace_t *result, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int skipNumber, int mask);

void CG_FxRestart(void);
void CG_FxTest(void);
float CG_GetViewFov(void);
static void CG_CalcFov(void);
void CG_FxSetTestPosition(void);
static void CG_OffsetThirdPersonView(void);
static void CG_CalcViewValues(void);
void CG_InitView(void);
qboolean CG_DrawActiveFrame(int serverTime, DemoType demoType, CubemapShot cubemapShot, int cubemapSize, qboolean renderScreen);

/* line 56 */
void CG_FxRestart(void)
{
    Com_Printf((const char *)"FX Restarting so off-line changes are loaded.\n");
    FX_FreeSystem();
    FX_InitSystem(1);
}

/* line 64 */
void CG_FxTest(void)
{
    char *cg_s;
    char *fxName;
    int fx;

    if (Cmd_Argc() - 1 <= 0) {
        Com_Printf((const char *)"Must supply filename from base path.  Optional restart time.\n");
    }

    cg_s = (char *)*(int *)imp_cg;
    {
        cg_t *cg = (cg_t *)cg_s;
        fxName = cg->testFxName;
        I_strncpyz(fxName, CG_Argv(1), 0x40);

        fx = FX_RegisterEffect(fxName);
        Com_Printf((const char *)"Spawning Fx %s\n", fxName);
        FX_PlaySimpleEffect(fx, (const vec_t *)cg->testFxPos);
        cg->testFxTime = cg->time;

        if (Cmd_Argc() == 3) {
            double d = atof(CG_Argv(2));
            cg->testFxRespawnTime = (int)(d * 1000.0);
        } else {
            cg->testFxRespawnTime = 0;
        }
    }
}

/* line 390 */
float CG_GetViewFov(void)
{
    char *cg_s;
    int weapIndex;
    char *weapDef;
    float fov_x;

    cg_s = (char *)*(int *)imp_cg;
    {
        cg_t *cg = (cg_t *)cg_s;
        weapIndex = BG_GetViewmodelWeaponIndex((void *)&cg->predictedPlayerState);
        weapDef = (char *)BG_GetWeaponDef(weapIndex);

        if (cg->predictedPlayerState.pm_type == 5) {
            fov_x = 90.0f;
        } else {
            fov_x = *(float *)((char *)(*(int *)imp_cg_fov) + 8);

            if (BG_IsAimDownSightWeapon(weapIndex)) {
                float fPosLerp = cg->predictedPlayerState.fWeaponPosFrac;
                float adsFov = ((WeaponDef *)weapDef)->fAdsZoomFov;

                if (fPosLerp == 1.0f) {
                    fov_x = adsFov;
                } else if (fPosLerp != 0.0f) {
                    float transTime;
                    float normalizedLerp;

                    if (cg->playerEntity.bPositionToADS != 0) {
                        transTime = ((WeaponDef *)weapDef)->fAdsZoomInFrac;
                    } else {
                        transTime = ((WeaponDef *)weapDef)->fAdsZoomOutFrac;
                    }

                    normalizedLerp = fPosLerp - (1.0f - transTime);
                    if (normalizedLerp > 0.0f) {
                        normalizedLerp /= transTime;
                        if (normalizedLerp > 0.0f) {
                            fov_x -= (fov_x - adsFov) * normalizedLerp;
                        }
                    }
                }
            }
        }

        /* Scope overlay check */
        if (cg->predictedPlayerState.eFlags & 0x300) {
            fov_x = 55.0f;
        }
    }

    /* Apply fov scale */
    fov_x *= *(float *)((char *)(*(int *)imp_cg_fovScale) + 8);

    /* Clamp to minimum */
    {
        float fovClamp = *(float *)((char *)(*(int *)imp_cg_fovMin) + 8);
        if (fovClamp > fov_x) {
            fov_x = fovClamp;
        }
    }

    return fov_x;
}

/* line 468 */
static void CG_CalcFov(void)
{
    float fov;
    double halfAngle;
    float tanVal;
    float fov_x, fov_y;
    char *cg_s;

    fov = CG_GetViewFov();

    halfAngle = (double)fov * 0.017453292519943295 * 0.5;
    tanVal = (float)tan(halfAngle) * 0.75f;

    cg_s = (char *)*(int *)imp_cg;
    {
        cg_t *cg = (cg_t *)cg_s;
        fov_x = (float)((double)atanf(tanVal * (*(cgs_t **)imp_cgs)->viewAspect) * 57.29577951308232 * 2.0);
        fov_y = (float)((double)atanf(tanVal) * 57.29577951308232 * 2.0);

        if (CG_PointContents((const vec_t *)cg->refdef.vieworg, -1, 0x20)) {
            float phase = (float)(cg->time) / 1000.0f * 0.4f;
            float wave = sinf((float)((double)phase * 3.141592653589793 * 2.0));
            fov_x += wave;
            fov_y -= wave;
        }

        cg->refdef.fov_x = fov_x;
        cg->refdef.fov_y = fov_y;
        cg->zoomSensitivity = fov_x / *(float *)((char *)(*(int *)imp_cg_fov) + 8);
    }
}

/* line 49 */
void CG_FxSetTestPosition(void)
{
    char *cg_s = (char *)*(int *)imp_cg;
    float *start = (float *)(cg_s + 0x28588);
    float *dir = (float *)(cg_s + 0x28594);
    float *result = (float *)(cg_s + 0x2c01c);

    result[0] = start[0] + 100.0f * dir[0];
    result[1] = start[1] + 100.0f * dir[1];
    result[2] = start[2] + 100.0f * dir[2];

    Com_Printf((const char *)"\n\nFX Testing position set to: (%f, %f, %f)\n\n",
               (double)result[0], (double)result[1], (double)result[2]);
}

/* line 128 */
static void CG_OffsetThirdPersonView(void)
{
    byte *cg_s;
    byte *origin;     /* cg_s + 0x28588 */
    byte *viewAngles; /* cg_s + 0x285c8 */
    float focusAngles[3];
    float forward[3], right[3], up[3];
    float focusPoint[3];
    float view[3];
    float trace_fraction; /* trace.fraction */
    byte trace[64]; /* trace_t - only need fraction at offset 0 */
    float scale;
    float dist2d;
    float dz;
    double angle;

    /* line 139 */
    cg_s = *(byte **)imp_cg;
    {
        cg_t *cg = (cg_t *)cg_s;
        origin = (byte *)cg->refdef.vieworg;
        viewAngles = (byte *)cg->refdefViewAngles;

        /* Add predicted error to z */
        cg->refdef.vieworg[2] += cg->predictedPlayerState.viewHeightCurrent;

        /* Copy view angles to focusAngles */
        focusAngles[0] = cg->refdefViewAngles[0];
        focusAngles[1] = cg->refdefViewAngles[1];
        focusAngles[2] = cg->refdefViewAngles[2];

        /* line 144: if pm_type > 5 */
        if (cg->predictedPlayerState.pm_type > 5) {
            /* line 146-147 */
            focusAngles[1] = (float)cg->predictedPlayerState.stats[1];
            cg->refdefViewAngles[1] = (float)cg->predictedPlayerState.stats[1];
        }
    }

    /* line 152: clamp focusAngles[0] to min(45.0f, focusAngles[0]) */
    if (focusAngles[0] < 45.0f) {
        /* keep focusAngles[0] */
    } else {
        focusAngles[0] = 45.0f;
    }

    /* line 154: AngleVectors(focusAngles, forward, NULL, NULL) */
    AngleVectors(focusAngles, forward, (void *)0, (void *)0);

    /* line 156-160: compute focus point = origin + forward*512 */
    focusPoint[0] = forward[0] * 512.0f + *(float *)(origin + 0);
    focusPoint[1] = forward[1] * 512.0f + *(float *)(origin + 4);
    focusPoint[2] = forward[2] * 512.0f + *(float *)(origin + 8);

    /* Copy origin to view, add 8.0 to z */
    view[0] = *(float *)(origin + 0);
    view[1] = *(float *)(origin + 4);
    view[2] = *(float *)(origin + 8) + 8.0f;

    /* line 162: halve viewAngles pitch */
    *(float *)(viewAngles + 0) *= 0.5f;

    /* line 163: subtract cg_thirdPersonAngle from viewAngles yaw */
    {
        byte *dvar = *(byte **)imp_cg_thirdPersonAngle;
        *(float *)(viewAngles + 4) -= *(float *)((byte *)dvar + 8);
    }

    /* line 165: AngleVectors(viewAngles, forward, right, up) */
    AngleVectors((float *)viewAngles, forward, right, up);

    /* line 167: get range and negate */
    {
        byte *dvar = *(byte **)imp_cg_thirdPersonRange;
        scale = *(float *)((byte *)dvar + 8);
    }
    /* xorps colorWhiteFaded+64 negates the float (0x80000000 sign bit) */
    {
        union { float f; unsigned int u; } conv;
        conv.f = scale;
        conv.u ^= 0x80000000u;
        scale = conv.f;
    }

    /* VectorMA: view += scale * forward */
    view[0] += scale * forward[0];
    view[1] += scale * forward[1];
    view[2] += scale * forward[2];

    /* line 172: first trace from origin to view */
    CG_TraceCapsule((trace_t *)trace, (const vec_t *)origin, (const vec_t *)&mins, (const vec_t *)&maxs,
                    (const vec_t *)view, ((cg_t *)cg_s)->predictedPlayerState.clientNum, 0x811);

    trace_fraction = *(float *)trace;

    if (trace_fraction != 1.0f) {
        /* trace didn't make it all the way - interpolate */
        /* VectorLerp: view = origin + fraction * (view - origin) */
        view[0] = *(float *)(origin + 0) + trace_fraction * (view[0] - *(float *)(origin + 0));
        view[1] = *(float *)(origin + 4) + trace_fraction * (view[1] - *(float *)(origin + 4));
        {
            float newZ = *(float *)(origin + 8) + trace_fraction * (view[2] - *(float *)(origin + 8));
            /* line 177: add (1-fraction)*32 to z */
            view[2] = newZ + (1.0f - trace_fraction) * 32.0f;
        }

        /* line 181: second trace */
        CG_TraceCapsule((trace_t *)trace, (const vec_t *)origin, (const vec_t *)&mins, (const vec_t *)&maxs,
                        (const vec_t *)view, ((cg_t *)cg_s)->predictedPlayerState.clientNum, 0x811);
        trace_fraction = *(float *)trace;

        /* VectorLerp again */
        view[0] = *(float *)(origin + 0) + trace_fraction * (view[0] - *(float *)(origin + 0));
        view[1] = *(float *)(origin + 4) + trace_fraction * (view[1] - *(float *)(origin + 4));
        view[2] = *(float *)(origin + 8) + trace_fraction * (view[2] - *(float *)(origin + 8));
    }

    /* line 185: copy view back to origin */
    cg_s = *(byte **)imp_cg;
    origin = cg_s + 0x28588;
    *(float *)(origin + 0) = view[0];
    *(float *)(origin + 4) = view[1];
    *(float *)(origin + 8) = view[2];

    /* line 248-250: compute delta from focusPoint to new origin */
    {
        float dx = focusPoint[0] - *(float *)(origin + 0);
        float dy = focusPoint[1] - *(float *)(origin + 4);
        dz = focusPoint[2] - *(float *)(origin + 8);

        /* line 81: compute 2D distance */
        dist2d = dx * dx + dy * dy;
        dist2d = __builtin_sqrtf(dist2d);

        /* line 190: clamp dist2d to min 1.0 */
        if (dist2d < 1.0f) {
            dist2d = 1.0;
        }

        /* line 194: compute pitch from atan2 */
        angle = atan2((double)dz, (double)dist2d);
        ((cg_t *)cg_s)->refdefViewAngles[0] = (float)(angle * -57.29577951308232);
    }
}

/* line 686 */

void CG_InitView(void)
{
    cg_t *cg;
    int renderPlayerState;

    cg = (cg_t *)*(int *)imp_cg;
    cg->refdef.time = cg->time;
    cg->refdef.zNear = 0x3f800000; /* 1.0f */

    if (*(unsigned char *)((char *)(*(int *)imp_cg_thirdPerson) + 8) != 0) {
        renderPlayerState = 1;
    } else if (cg->snap->ps.pm_type > 5) {
        renderPlayerState = 1;
    } else {
        renderPlayerState = 0;
    }

    cg->renderingThirdPerson = renderPlayerState;
    CG_PredictPlayerState();
    CL_ResetSkeletonCache(0);

    cg = (cg_t *)*(int *)imp_cg;
    CG_UpdateViewWeaponAnim((void *)&cg->predictedPlayerState);
    CG_CalcViewValues();
    CL_FX_AdjustCamera((void *)&cg->refdef);
    FX_AdjustTime(cg->time);
}

/* line 935 */
