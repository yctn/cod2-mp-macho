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

extern vec3_t mins; /* mins */
extern vec3_t maxs; /* maxs */

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
    Com_Printf((const char *)str_002b74b0);
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
        Com_Printf((const char *)str_002b74e0);
    }

    cg_s = (char *)*(int *)imp_cg;
    {
        cg_t *cg = (cg_t *)cg_s;
        fxName = cg->testFxName;
        I_strncpyz(fxName, CG_Argv(1), 0x40);

        fx = FX_RegisterEffect(fxName);
        Com_Printf((const char *)str_002b7520, fxName);
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
                float adsFov = *(float *)(weapDef + 0x268);

                if (fPosLerp == 1.0f) {
                    fov_x = adsFov;
                } else if (fPosLerp != 0.0f) {
                    float transTime;
                    float normalizedLerp;

                    if (cg->playerEntity.bPositionToADS != 0) {
                        transTime = *(float *)(weapDef + 0x26c);
                    } else {
                        transTime = *(float *)(weapDef + 0x270);
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
        fov_x = (float)((double)atanf(tanVal * *(float *)((char *)*(int *)imp_cgs + 0x5e94)) * 57.29577951308232 * 2.0);
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

    Com_Printf((const char *)str_002b7530,
               (double)result[0], (double)result[1], (double)result[2]);
}

/* line 128 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void CG_OffsetThirdPersonView(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 128 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 139 */
        "movl (%eax), %esi\n"
        "movss 0x28590(%esi), %xmm0\n"
        "addss 0x25cbc(%esi), %xmm0\n"
        "movss %xmm0, 0x28590(%esi)\n"
        "leal 0x285c8(%esi), %edi\n"
        /* { scope 2 */
        "movl 0x285c8(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x54(%ebp)\n" /* focusAngles */
        "movl 4(%edi), %eax\n" /* line 200 | from */
        "movl %eax, -0x50(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 201 | from */
        "movl %eax, -0x4c(%ebp)\n"
        /* } scope */
        "cmpl $5, 0x25bc8(%esi)\n" /* line 144 */
        "jle .Lf1d128e_001d12fa\n"
        "cvtsi2ssl 0x25cf4(%esi), %xmm0\n" /* line 146 */
        "movss %xmm0, -0x50(%ebp)\n"
        "cvtsi2ssl 0x25cf4(%esi), %xmm0\n" /* line 147 */
        "movss %xmm0, 0x285cc(%esi)\n"
        ".Lf1d128e_001d12fa:\n"
        "movss lit4_002ed6ec, %xmm0\n" /* line 152 | 45.0f */
        "movss -0x54(%ebp), %xmm2\n" /* focusAngles */
        "movaps %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm3\n"
        "cmpnltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n" /* focusAngles */
        "movl $0, 0xc(%esp)\n" /* line 154 */
        "movl $0, 8(%esp)\n"
        "leal -0x24(%ebp), %ebx\n" /* forward */
        "movl %ebx, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* focusAngles */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "leal 0x28588(%esi), %eax\n" /* line 156 */
        "movl %eax, -0x88(%ebp)\n"
        "movss lit4_002ed828, %xmm0\n" /* line 288 | 512.0f */
        "movss -0x24(%ebp), %xmm1\n" /* forward */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x7c(%ebp)\n"
        "addss 0x28588(%esi), %xmm1\n"
        "movss %xmm1, -0x7c(%ebp)\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 289 */
        "mulss %xmm0, %xmm2\n"
        "movss %xmm2, -0x80(%ebp)\n"
        "addss 0x2858c(%esi), %xmm2\n"
        "movss %xmm2, -0x80(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 290 */
        "movss %xmm0, -0x84(%ebp)\n"
        "addss 0x28590(%esi), %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n"
        "movl 0x28588(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x48(%ebp)\n" /* view */
        "movl 0x2858c(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movss lit4_002ed740, %xmm0\n" /* line 160 | 8.0f */
        "addss 0x28590(%esi), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movss lit4_002ed5d8, %xmm0\n" /* line 162 | 0.5f */
        "mulss 0x285c8(%esi), %xmm0\n"
        "movss %xmm0, 0x285c8(%esi)\n"
        "movl imp_cg_thirdPersonAngle, %eax\n" /* line 163 */
        "movl (%eax), %eax\n"
        "movss 0x285cc(%esi), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, 0x285cc(%esi)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 165 | up */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* right */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* from */
        "calll AngleVectors\n"
        "movl imp_cg_thirdPersonRange, %eax\n" /* line 167 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n" /* scale */
        "xorps colorWhiteFaded+64, %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x24(%ebp), %xmm0\n" /* forward */
        "addss -0x48(%ebp), %xmm0\n" /* view */
        "movss %xmm0, -0x48(%ebp)\n" /* view */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "addss -0x40(%ebp), %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        /* } scope */
        "movl $0x811, 0x18(%esp)\n" /* line 172 */
        "movl 0x25c90(%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x48(%ebp), %edi\n" /* view, from */
        "movl %edi, 0x10(%esp)\n" /* from */
        "movl $maxs, 0xc(%esp)\n"
        "movl $mins, 8(%esp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %ebx\n" /* trace */
        "movl %ebx, (%esp)\n"
        "calll CG_TraceCapsule\n"
        "movss -0x78(%ebp), %xmm2\n" /* line 174 | trace */
        "ucomiss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "jp .Lf1d128e_001d1584\n"
        "jne .Lf1d128e_001d1584\n"
        ".Lf1d128e_001d14ba:\n"
        "movl imp_cg, %eax\n" /* line 185 */
        "movl (%eax), %ebx\n"
        "leal 0x28588(%ebx), %edx\n" /* to */
        /* { scope 2 */
        "movl -0x48(%ebp), %eax\n" /* line 199 | view */
        "movl %eax, 0x28588(%ebx)\n"
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x40(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movss -0x7c(%ebp), %xmm0\n" /* line 248 */
        "subss 0x28588(%ebx), %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "movss -0x80(%ebp), %xmm1\n" /* line 249 */
        "subss 4(%edx), %xmm1\n"
        "movss %xmm1, -0x80(%ebp)\n"
        "movss -0x84(%ebp), %xmm0\n" /* line 250 */
        "subss 8(%edx), %xmm0\n"
        "movss -0x7c(%ebp), %xmm2\n" /* line 81 */
        "mulss %xmm2, %xmm2\n"
        "movss %xmm2, -0x7c(%ebp)\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "sqrtss %xmm2, %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 190 | 1.0f */
        "ucomiss %xmm1, %xmm3\n"
        "ja .Lf1d128e_001d157a\n"
        "cvtss2sd %xmm1, %xmm1\n"
        ".Lf1d128e_001d1535:\n"
        "movsd %xmm1, 8(%esp)\n" /* line 194 */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll atan2\n"
        "fstpl -0x90(%ebp)\n"
        "cvtsd2ss -0x90(%ebp), %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd lit8_00307da0, %xmm0\n" /* -57.29577951308232 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x285c8(%ebx)\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 195 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d128e_001d157a:\n"
        "movsd lit8_00307c10, %xmm1\n" /* line 190 | 1.0 */
        "jmp .Lf1d128e_001d1535\n"
        ".Lf1d128e_001d1584:\n"
        "movss 0x28588(%esi), %xmm1\n" /* line 1203 */
        "movss -0x48(%ebp), %xmm0\n" /* view */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n" /* view */
        "movl -0x88(%ebp), %eax\n" /* line 1204 */
        "movss 4(%eax), %xmm1\n"
        "movss -0x44(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 1205 */
        "movss -0x40(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 177 | 1.0f */
        "subss -0x78(%ebp), %xmm0\n" /* trace */
        "mulss lit4_002ed830, %xmm0\n" /* 32.0f */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movl $0x811, 0x18(%esp)\n" /* line 181 */
        "movl 0x25c90(%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n" /* from */
        "movl $maxs, 0xc(%esp)\n"
        "movl $mins, 8(%esp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CG_TraceCapsule\n"
        "movss -0x78(%ebp), %xmm2\n" /* line 182 | trace, fraction */
        /* { scope 2 */
        "movss 0x28588(%esi), %xmm1\n" /* line 1203 */
        "movss -0x48(%ebp), %xmm0\n" /* view */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n" /* view */
        "movl -0x88(%ebp), %eax\n" /* line 1204 */
        "movss 4(%eax), %xmm1\n"
        "movss -0x44(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 1205 */
        "movss -0x40(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        "jmp .Lf1d128e_001d14ba\n"
    );
}
#else
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
#endif

/* line 686 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void CG_CalcViewValues(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 686 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 692 */
        "movl (%eax), %esi\n"
        "leal 0x28570(%esi), %eax\n"
        "movl $0x58, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "calll CL_GetMenuBlurRadius\n" /* line 694 */
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm1\n"
        "movl imp_cgDC, %eax\n" /* line 695 */
        "movss 0x28(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "movss %xmm0, 0x285c0(%esi)\n"
        "movl 0xc(%esi), %eax\n" /* line 697 */
        "testl %eax, %eax\n"
        "jne .Lf1d1694_001d1d27\n"
        "movl 0x24(%esi), %eax\n" /* line 704 */
        "cmpl $5, 0x10(%eax)\n"
        "je .Lf1d1694_001d1d12\n"
        "movl imp_cg_viewsize, %eax\n" /* line 707 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0xe0(%ebp)\n" /* viewSize */
        "movl %eax, %edi\n"
        ".Lf1d1694_001d1724:\n"
        "movl imp_cgs, %eax\n" /* line 106 */
        "movl (%eax), %ecx\n"
        "imull 0x5e8c(%ecx), %edi\n"
        "movl $0x51eb851f, %eax\n"
        "imull %edi\n"
        "sarl $5, %edx\n"
        "movl %edi, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 0x28578(%esi)\n"
        "movl imp_cg, %eax\n" /* line 107 */
        "movl (%eax), %edi\n"
        "movl 0x28578(%edi), %ebx\n"
        "andl $0xfffffffe, %ebx\n"
        "movl %ebx, 0x28578(%edi)\n"
        "movl -0xe0(%ebp), %edx\n" /* line 109 | viewSize */
        "imull 0x5e90(%ecx), %edx\n"
        "movl %edx, -0x110(%ebp)\n"
        "movl $0x51eb851f, %eax\n"
        "imull %edx\n"
        "movl %edx, %esi\n"
        "sarl $5, %esi\n"
        "movl -0x110(%ebp), %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %esi\n"
        "andl $0xfffffffe, %esi\n" /* line 110 */
        "movl %esi, 0x2857c(%edi)\n"
        "movl 0x5e8c(%ecx), %edx\n" /* line 112 */
        "subl %ebx, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "addl 0x5e84(%ecx), %eax\n"
        "movl %eax, 0x28570(%edi)\n"
        "movl 0x5e90(%ecx), %edx\n" /* line 113 */
        "subl %esi, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "addl 0x5e88(%ecx), %eax\n"
        "movl %eax, 0x28574(%edi)\n"
        "movl %esi, 0x14(%esp)\n" /* line 115 */
        "movl 0x28578(%edi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x28574(%edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x28570(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x3f800000, (%esp)\n"
        "calll SetScreenScaling\n"
        "leal 0x25bc4(%edi), %ebx\n" /* line 712 | ps */
        "cmpl $5, 4(%ebx)\n" /* line 715 | ps */
        "je .Lf1d1694_001d1ded\n"
        "movl %ebx, (%esp)\n" /* line 724 | ps */
        "calll BG_GetBobCycle\n"
        "fstps 0x2bf18(%edi)\n"
        "movl 0x25bb0(%edi), %eax\n" /* line 725 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_GetSpeed\n"
        "fstps 0x2bf1c(%edi)\n"
        "leal 0x28588(%edi), %ebx\n" /* line 727 | to */
        "leal 0x25bd8(%edi), %edx\n" /* from */
        /* { scope 2 */
        "movl 0x25bd8(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x28588(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "leal 0x285c8(%edi), %ecx\n" /* line 728 | to */
        "leal 0x25cac(%edi), %edx\n" /* from */
        /* { scope 2 */
        "movl 0x25cac(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x285c8(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl imp_cg_errorDecay, %eax\n" /* line 731 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm1\n"
        "jbe .Lf1d1694_001d18c3\n"
        /* { scope 2 */
        "movl 0x25bb0(%edi), %eax\n" /* line 737 */
        "subl 0x284c0(%edi), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movaps %xmm1, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "ucomiss %xmm3, %xmm2\n" /* line 738 */
        "ja .Lf1d1694_001d2145\n"
        ".Lf1d1694_001d18b9:\n"
        "movl $0, 0x284c0(%edi)\n" /* line 744 */
        /* } scope */
        ".Lf1d1694_001d18c3:\n"
        "movl imp_cg, %eax\n" /* line 577 */
        "movl (%eax), %ebx\n"
        "leal 0x25bc4(%ebx), %edi\n"
        "testl $0x300, 0xa0(%edi)\n" /* line 579 */
        "jne .Lf1d1694_001d21e4\n"
        ".Lf1d1694_001d18e0:\n"
        "movl (%eax), %edx\n" /* line 750 */
        "movl 0x25bc0(%edx), %ebx\n" /* to */
        "testl %ebx, %ebx\n" /* to */
        "jne .Lf1d1694_001d21da\n"
        "movl 0x24(%edx), %eax\n" /* line 320 */
        "cmpl $5, 0x10(%eax)\n"
        "je .Lf1d1694_001d1bf4\n"
        "testl $0x300, 0x25c64(%edx)\n" /* line 323 */
        "jne .Lf1d1694_001d1bf4\n"
        "leal 0x28490(%edx), %ebx\n" /* line 326 */
        "leal 0x25bc4(%edx), %ecx\n" /* line 328 */
        "movl %ecx, -0x48(%ebp)\n"
        "movl 0x2bed4(%edx), %eax\n" /* line 329 */
        "testl %eax, %eax\n"
        "je .Lf1d1694_001d192c\n"
        "subl 0x7a4(%ecx), %eax\n"
        ".Lf1d1694_001d192c:\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl imp_cg, %edx\n" /* line 330 */
        "movl (%edx), %edx\n"
        "movl %edx, -0xe4(%ebp)\n"
        "movl 0x25bb0(%edx), %eax\n"
        "movl -0x48(%ebp), %edx\n"
        "subl 0x7a4(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl -0xe4(%ebp), %ecx\n" /* line 331 */
        "movl 0x2bf10(%ecx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x2bf14(%ecx), %eax\n" /* line 332 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x2bf1c(%ecx), %eax\n" /* line 333 */
        "movl %eax, -0x34(%ebp)\n"
        "cvtsi2ssl 0x25bac(%ecx), %xmm0\n" /* line 334 */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x30(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* line 335 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %ecx, %eax\n" /* line 336 */
        "addl $0x2beec, %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "leal -0xa8(%ebp), %eax\n" /* line 338 */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_CalculateViewAngles\n"
        "movl -0xe4(%ebp), %ebx\n" /* line 340 */
        "addl $0x285c8, %ebx\n"
        "movl -0xe4(%ebp), %eax\n" /* line 240 */
        "movss 0x285c8(%eax), %xmm0\n"
        "addss -0xa8(%ebp), %xmm0\n"
        "movss %xmm0, 0x285c8(%eax)\n"
        "movss 4(%ebx), %xmm0\n" /* line 241 */
        "addss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movss 8(%ebx), %xmm0\n" /* line 242 */
        "addss -0xa0(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "addl $0x28588, %eax\n" /* line 343 */
        "movl %eax, -0xcc(%ebp)\n"
        "movl -0xe4(%ebp), %edx\n" /* line 346 */
        "movss 0x28590(%edx), %xmm0\n"
        "addss 0x25cbc(%edx), %xmm0\n"
        "movss %xmm0, 0x28590(%edx)\n"
        "movl imp_bg_bobMax, %edi\n" /* line 349 */
        "movl (%edi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2bf1c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x2bf18(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, %esi\n"
        "addl $0x25bc4, %esi\n"
        "movl %esi, (%esp)\n"
        "calll BG_GetVerticalBobFactor\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm0\n"
        "movl -0xe4(%ebp), %ecx\n" /* line 350 */
        "addss 0x28590(%ecx), %xmm0\n"
        "movss %xmm0, 0x28590(%ecx)\n"
        "movl (%edi), %eax\n" /* line 351 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2bf1c(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x2bf18(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll BG_GetHorizontalBobFactor\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm1\n"
        "movl $0, 0xc(%esp)\n" /* line 352 */
        "leal -0x78(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movss %xmm1, -0xf8(%ebp)\n"
        "calll AngleVectors\n"
        "movss -0xf8(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x78(%ebp), %xmm0\n"
        "movl -0xe4(%ebp), %ebx\n"
        "addss 0x28588(%ebx), %xmm0\n"
        "movss %xmm0, 0x28588(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x74(%ebp), %xmm0\n"
        "movl -0xcc(%ebp), %eax\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss -0x70(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 0x28590(%ebx)\n"
        "movl 0x25bb0(%ebx), %edx\n" /* line 356 */
        "movl %edx, %eax\n"
        "subl 0x284dc(%ebx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 357 | 0.0f */
        "jb .Lf1d1694_001d250e\n"
        ".Lf1d1694_001d1b41:\n"
        "movss lit4_002ed93c, %xmm1\n" /* line 359 | 150.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1d1694_001d2261\n"
        "divss %xmm1, %xmm0\n" /* line 362 */
        "movl -0xe4(%ebp), %edx\n"
        "mulss 0x284d8(%edx), %xmm0\n"
        "addss 0x28590(%edx), %xmm0\n"
        "movss %xmm0, 0x28590(%edx)\n"
        ".Lf1d1694_001d1b74:\n"
        "movl imp_cg, %ebx\n" /* line 204 */
        "movl (%ebx), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "movl %edx, %ecx\n" /* line 206 */
        "subl 0x284d4(%eax), %ecx\n"
        "js .Lf1d1694_001d219d\n"
        "cmpl $0x63, %ecx\n" /* line 210 */
        "jle .Lf1d1694_001d21a3\n"
        ".Lf1d1694_001d1b99:\n"
        "movl imp_cg, %edx\n" /* line 375 */
        "movl (%edx), %ebx\n"
        "movl $0x41a00000, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movl 0x25c10(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x285cc(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x28588(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddLeanToPosition\n"
        "movss lit4_002ed740, %xmm0\n" /* line 378 | 8.0f */
        "addss 0x25be0(%ebx), %xmm0\n"
        "ucomiss 0x28590(%ebx), %xmm0\n"
        "jbe .Lf1d1694_001d1bf4\n"
        "movss %xmm0, 0x28590(%ebx)\n" /* line 379 */
        ".Lf1d1694_001d1bf4:\n"
        "calll CG_ShakeCamera\n" /* line 761 */
        "movl imp_cg, %eax\n" /* line 764 */
        "movl (%eax), %ebx\n" /* to */
        "leal 0x28594(%ebx), %esi\n" /* to */
        "movl %esi, 4(%esp)\n"
        "leal 0x285c8(%ebx), %edi\n" /* to */
        "movl %edi, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x2c0bc(%ebx), %edx\n" /* line 608 */
        "leal 0x28588(%ebx), %ecx\n"
        "movl %ecx, -0xc8(%ebp)\n"
        "movl 0x28588(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x2c0bc(%ebx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x2c0c8(%ebx), %edx\n" /* line 609 */
        "movl 0x28594(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x2c0c8(%ebx)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x2c0d4(%ebx), %edx\n" /* line 610 */
        "leal 0x285a0(%ebx), %eax\n"
        "movl %eax, -0xc4(%ebp)\n"
        "movl 0x285a0(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x2c0d4(%ebx)\n"
        "movl -0xc4(%ebp), %ecx\n" /* line 200 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x2c0e0(%ebx), %edx\n" /* line 611 */
        "leal 0x285ac(%ebx), %eax\n"
        "movl %eax, -0xc0(%ebp)\n"
        "movl 0x285ac(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x2c0e0(%ebx)\n"
        "movl -0xc0(%ebp), %ecx\n" /* line 200 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x2c0ec(%ebx), %edx\n" /* line 612 */
        "movl 0x285c8(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x2c0ec(%ebx)\n"
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x25bc4(%ebx), %edx\n" /* line 630 */
        "movl 4(%edx), %eax\n" /* line 632 */
        "subl $4, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1d1694_001d1cfd\n"
        "movl 0x25bc0(%ebx), %ecx\n" /* line 635 */
        "testl %ecx, %ecx\n"
        "je .Lf1d1694_001d1e57\n"
        ".Lf1d1694_001d1cfd:\n"
        "calll CG_PerturbCamera\n" /* line 771 */
        "calll CG_CalcFov\n" /* line 774 */
        /* } scope */
        ".Lf1d1694_001d1d07:\n"
        "addl $0x14c, %esp\n" /* line 775 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d1694_001d1d12:\n"
        "movl $0x64, -0xe0(%ebp)\n" /* line 704 | viewSize */
        "movl -0xe0(%ebp), %edi\n" /* viewSize */
        "jmp .Lf1d1694_001d1724\n"
        ".Lf1d1694_001d1d27:\n"
        "leal 0x25bc4(%esi), %ebx\n" /* line 517 */
        "movl $0, 0x28570(%esi)\n" /* line 518 */
        "movl $0, 0x28574(%esi)\n" /* line 519 */
        "movl 0x10(%esi), %edx\n" /* line 520 */
        "leal 2(%edx), %eax\n"
        "movl %eax, 0x28578(%esi)\n"
        "movl %eax, 0x2857c(%esi)\n" /* line 521 */
        "cvtsi2ssl %edx, %xmm0\n" /* line 522 */
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, (%esp)\n"
        "calll atan2\n"
        "fstpl -0x108(%ebp)\n"
        "movsd -0x108(%ebp), %xmm0\n"
        "mulsd lit8_00307da8, %xmm0\n" /* 114.59155902616465 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x28580(%esi)\n"
        "movss %xmm0, 0x28584(%esi)\n" /* line 523 */
        "leal 0x28588(%esi), %ecx\n" /* line 524 */
        "leal 0x25bd8(%esi), %edx\n"
        "movl 0x25bd8(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x28588(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movss 0x28590(%esi), %xmm0\n" /* line 525 */
        "addss 0xf8(%ebx), %xmm0\n"
        "movss %xmm0, 0x28590(%esi)\n"
        "cmpl $6, 0xc(%esi)\n" /* line 527 */
        "ja .Lf1d1694_001d1d07\n"
        "movl 0xc(%esi), %eax\n"
        "jmpl *.Ljt_1d1694_0(, %eax, 4)\n"
        ".Lf1d1694_001d1ded:\n"
        "leal 0x28588(%edi), %ecx\n" /* line 717 | to */
        "leal 0x25bd8(%edi), %edx\n" /* from */
        /* { scope 2 */
        "movl 0x25bd8(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x28588(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x285c8(%edi), %edx\n" /* line 718 | to */
        "leal 0x25cac(%edi), %ecx\n" /* from */
        /* { scope 2 */
        "movl 0x25cac(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x285c8(%edi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x28594(%edi), %eax\n" /* line 719 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll AnglesToAxis\n"
        "calll CG_CalcFov\n" /* line 720 */
        /* } scope */
        "addl $0x14c, %esp\n" /* line 775 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d1694_001d1e57:\n"
        "testl $0x300, 0xa0(%edx)\n" /* line 638 */
        "jne .Lf1d1694_001d1cfd\n"
        "movl %edx, (%esp)\n" /* line 641 */
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 643 */
        "jle .Lf1d1694_001d1cfd\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 646 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0xbc(%ebp)\n"
        "movl (%eax), %edx\n" /* line 647 */
        "testl %edx, %edx\n"
        "je .Lf1d1694_001d1cfd\n"
        "movl imp_scr_const, %eax\n" /* line 650 */
        "movzwl 0x9c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll DObjGetBoneIndex\n"
        "movl %eax, -0xb8(%ebp)\n"
        "testl %eax, %eax\n" /* line 651 */
        "js .Lf1d1694_001d1cfd\n"
        "movl -0xbc(%ebp), %edx\n" /* line 654 */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetRotTransArray\n"
        "testl %eax, %eax\n" /* line 655 */
        "je .Lf1d1694_001d1cfd\n"
        "shll $5, -0xb8(%ebp)\n" /* line 658 */
        "addl -0xb8(%ebp), %eax\n"
        "movss 0x1c(%eax), %xmm1\n" /* line 306 */
        "movaps %xmm1, %xmm4\n" /* line 272 */
        "mulss (%eax), %xmm4\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%eax), %xmm6\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        "movaps %xmm4, %xmm0\n" /* line 308 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, -0xb4(%ebp)\n"
        "movss 4(%eax), %xmm3\n" /* line 309 */
        "movaps %xmm4, %xmm5\n"
        "mulss %xmm3, %xmm5\n"
        "movss 8(%eax), %xmm2\n" /* line 310 */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xb0(%ebp)\n"
        "movss 0xc(%eax), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm4\n"
        "mulss %xmm6, %xmm3\n" /* line 313 */
        "movss %xmm3, -0xac(%ebp)\n"
        "movaps %xmm6, %xmm7\n" /* line 314 */
        "mulss %xmm2, %xmm7\n"
        "mulss %xmm0, %xmm6\n" /* line 315 */
        "movaps %xmm1, %xmm3\n" /* line 317 */
        "mulss %xmm2, %xmm3\n"
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss %xmm1, -0x10c(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n" /* line 320 */
        "addss %xmm3, %xmm0\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movss -0x10c(%ebp), %xmm0\n" /* line 321 */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0xb0(%ebp), %xmm0\n" /* line 322 */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "subss -0x10c(%ebp), %xmm5\n" /* line 324 */
        "movss %xmm5, -0x3c(%ebp)\n"
        "addss -0xb4(%ebp), %xmm3\n" /* line 325 */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 326 */
        "addss %xmm7, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "addss -0xb0(%ebp), %xmm6\n" /* line 328 */
        "movss %xmm6, -0x30(%ebp)\n"
        "subss %xmm4, %xmm7\n" /* line 329 */
        "movss %xmm7, -0x2c(%ebp)\n"
        "movss -0xb4(%ebp), %xmm1\n" /* line 330 */
        "addss -0xac(%ebp), %xmm1\n"
        "subss %xmm1, %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "leal 0x10(%eax), %edx\n"
        "movl 0x10(%eax), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n"
        "leal -0x48(%ebp), %ecx\n" /* line 200 */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x28594(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x78(%ebp)\n"
        "leal -0x78(%ebp), %edx\n" /* line 200 */
        "movl 4(%esi), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x70(%ebp)\n"
        "movl 0x285a0(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0xc4(%ebp), %eax\n" /* line 200 */
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 201 */
        "movss %xmm1, -0x64(%ebp)\n"
        "movl 0x285ac(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x60(%ebp)\n"
        "movl -0xc0(%ebp), %eax\n" /* line 200 */
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 201 */
        "movss %xmm1, -0x58(%ebp)\n"
        "movl 0x28588(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x54(%ebp)\n"
        "movl -0xc8(%ebp), %eax\n" /* line 200 */
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 201 */
        "movss %xmm1, -0x4c(%ebp)\n"
        "leal -0xa8(%ebp), %eax\n" /* line 668 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll MatrixMultiply43\n"
        "movl -0xa8(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x28594(%ebx)\n"
        "movl -0xa4(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl -0xa0(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x285a0(%ebx)\n"
        "movl -0x98(%ebp), %eax\n" /* line 200 */
        "movl -0xc4(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x94(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl -0x90(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x285ac(%ebx)\n"
        "movl -0x8c(%ebp), %eax\n" /* line 200 */
        "movl -0xc0(%ebp), %ecx\n"
        "movl %eax, 4(%ecx)\n"
        "movl -0x88(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl -0x84(%ebp), %eax\n" /* line 199 */
        "movl %eax, 0x28588(%ebx)\n"
        "movl -0x80(%ebp), %eax\n" /* line 200 */
        "movl -0xc8(%ebp), %ebx\n"
        "movl %eax, 4(%ebx)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        "movl %edi, 4(%esp)\n" /* line 675 */
        "movl %esi, (%esp)\n"
        "calll AxisToAngles\n"
        "jmp .Lf1d1694_001d1cfd\n"
        /* { scope 2 */
        ".Lf1d1694_001d2145:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 738 | 1.0f */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf1d1694_001d18b9\n"
        "leal 0x284c4(%edi), %eax\n" /* line 740 | dir */
        /* { scope 3 */
        "movaps %xmm2, %xmm0\n" /* line 288 */
        "mulss 0x284c4(%edi), %xmm0\n"
        "addss 0x28588(%edi), %xmm0\n"
        "movss %xmm0, 0x28588(%edi)\n"
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "mulss 8(%eax), %xmm2\n" /* line 290 */
        "addss 8(%ebx), %xmm2\n"
        "movss %xmm2, 8(%ebx)\n"
        "jmp .Lf1d1694_001d18c3\n"
        /* } scope */
        /* } scope */
        ".Lf1d1694_001d219d:\n"
        "movl %edx, 0x284d4(%eax)\n" /* line 208 */
        ".Lf1d1694_001d21a3:\n"
        "movl imp_cg, %eax\n" /* line 212 */
        "movl (%eax), %edx\n"
        "movl $0x64, %eax\n"
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x284d0(%edx), %xmm0\n"
        "divss lit4_002eda64, %xmm0\n" /* -100.0f */
        "addss 0x28590(%edx), %xmm0\n"
        "movss %xmm0, 0x28590(%edx)\n"
        "jmp .Lf1d1694_001d1b99\n"
        ".Lf1d1694_001d21da:\n"
        "calll CG_OffsetThirdPersonView\n" /* line 753 */
        "jmp .Lf1d1694_001d1bf4\n"
        ".Lf1d1694_001d21e4:\n"
        "movl 0x594(%edi), %eax\n" /* line 585 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl imp_cg_entities, %eax\n"
        "movl (%eax), %eax\n"
        "leal (%eax, %edx, 4), %esi\n"
        "movl 0x220(%esi), %eax\n" /* line 586 */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 588 */
        "je .Lf1d1694_001d2257\n"
        "leal 0x28588(%ebx), %eax\n" /* line 591 */
        "movl %eax, 0xc(%esp)\n"
        "movl imp_scr_const, %eax\n"
        "movzwl 0x9a(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CG_DObjGetWorldTagPos\n"
        "testl %eax, %eax\n"
        "je .Lf1d1694_001d2448\n"
        ".Lf1d1694_001d224a:\n"
        "cmpl $2, 0x590(%edi)\n" /* line 595 */
        "je .Lf1d1694_001d2461\n"
        ".Lf1d1694_001d2257:\n"
        "movl imp_cg, %eax\n"
        "jmp .Lf1d1694_001d18e0\n"
        ".Lf1d1694_001d2261:\n"
        "ucomiss lit4_002eda5c, %xmm0\n" /* line 364 | 450.0f */
        "jae .Lf1d1694_001d1b74\n"
        "jp .Lf1d1694_001d1b74\n"
        "subss %xmm1, %xmm0\n" /* line 368 */
        "divss lit4_002eda60, %xmm0\n" /* -300.0f */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movl -0xe4(%ebp), %ecx\n"
        "mulss 0x284d8(%ecx), %xmm0\n"
        "addss 0x28590(%ecx), %xmm0\n"
        "movss %xmm0, 0x28590(%ecx)\n"
        "jmp .Lf1d1694_001d1b74\n"
        ".Lf1d1694_001d22ab:\n"
        "leal 0x28594(%esi), %eax\n" /* line 530 */
        "xorl %edx, %edx\n" /* line 191 */
        "movl %edx, 0x28594(%esi)\n"
        "movl %edx, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, %ebx\n" /* line 193 */
        "movl %ebx, 8(%eax)\n"
        "movl imp_cg, %eax\n" /* line 531 */
        "movl (%eax), %eax\n"
        "leal 0x285a0(%eax), %ecx\n"
        "movl %edx, 0x285a0(%eax)\n" /* line 191 */
        "movl %ebx, 4(%ecx)\n" /* line 192 */
        "movl %edx, 8(%ecx)\n" /* line 193 */
        "leal 0x285ac(%eax), %ecx\n" /* line 532 */
        "movl $0xbf800000, 0x285ac(%eax)\n" /* line 191 */
        "movl %edx, 4(%ecx)\n" /* line 192 */
        "movl %edx, 8(%ecx)\n" /* line 193 */
        "jmp .Lf1d1694_001d1d07\n"
        ".Lf1d1694_001d22f8:\n"
        "leal 0x28594(%esi), %eax\n" /* line 535 */
        "xorl %edx, %edx\n" /* line 191 */
        "movl %edx, 0x28594(%esi)\n"
        "movl %edx, 4(%eax)\n" /* line 192 */
        "movl $0xbf800000, 8(%eax)\n" /* line 193 */
        "movl imp_cg, %eax\n" /* line 536 */
        "movl (%eax), %eax\n"
        "leal 0x285a0(%eax), %ecx\n"
        "movl %edx, 0x285a0(%eax)\n" /* line 191 */
        "movl $0x3f800000, %ebx\n" /* line 192 */
        "movl %ebx, 4(%ecx)\n"
        "movl %edx, 8(%ecx)\n" /* line 193 */
        "leal 0x285ac(%eax), %ecx\n" /* line 537 */
        "movl %ebx, 0x285ac(%eax)\n" /* line 191 */
        "movl %edx, 4(%ecx)\n" /* line 192 */
        "movl %edx, 8(%ecx)\n" /* line 193 */
        "jmp .Lf1d1694_001d1d07\n"
        ".Lf1d1694_001d2345:\n"
        "leal 0x28594(%esi), %eax\n" /* line 540 */
        "movl $0xbf800000, %ebx\n" /* line 191 */
        "movl %ebx, 0x28594(%esi)\n"
        "xorl %edx, %edx\n" /* line 192 */
        "movl %edx, 4(%eax)\n"
        "movl %edx, 8(%eax)\n" /* line 193 */
        "movl imp_cg, %eax\n" /* line 541 */
        "movl (%eax), %eax\n"
        "leal 0x285a0(%eax), %ecx\n"
        "movl %edx, 0x285a0(%eax)\n" /* line 191 */
        "movl %ebx, 4(%ecx)\n" /* line 192 */
        "movl %edx, 8(%ecx)\n" /* line 193 */
        "leal 0x285ac(%eax), %ecx\n" /* line 542 */
        "movl %edx, 0x285ac(%eax)\n" /* line 191 */
        "movl %edx, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        "jmp .Lf1d1694_001d1d07\n"
        ".Lf1d1694_001d2392:\n"
        "leal 0x28594(%esi), %eax\n" /* line 545 */
        "movl $0x3f800000, %ebx\n" /* line 191 */
        "movl %ebx, 0x28594(%esi)\n"
        "xorl %edx, %edx\n" /* line 192 */
        "movl %edx, 4(%eax)\n"
        "movl %edx, 8(%eax)\n" /* line 193 */
        "movl imp_cg, %eax\n" /* line 546 */
        "movl (%eax), %eax\n"
        "leal 0x285a0(%eax), %ecx\n"
        "movl %edx, 0x285a0(%eax)\n" /* line 191 */
        "movl %ebx, 4(%ecx)\n" /* line 192 */
        ".Lf1d1694_001d23c1:\n"
        "movl %edx, 8(%ecx)\n" /* line 193 */
        "leal 0x285ac(%eax), %ecx\n" /* line 552 */
        "movl %edx, 0x285ac(%eax)\n" /* line 191 */
        "movl %edx, 4(%ecx)\n" /* line 192 */
        "movl %ebx, 8(%ecx)\n" /* line 193 */
        "jmp .Lf1d1694_001d1d07\n"
        ".Lf1d1694_001d23db:\n"
        "leal 0x28594(%esi), %eax\n" /* line 550 */
        "xorl %edx, %edx\n" /* line 191 */
        "movl %edx, 0x28594(%esi)\n"
        "movl $0xbf800000, 4(%eax)\n" /* line 192 */
        "movl %edx, 8(%eax)\n" /* line 193 */
        "movl imp_cg, %eax\n" /* line 551 */
        "movl (%eax), %eax\n"
        "leal 0x285a0(%eax), %ecx\n"
        "movl $0x3f800000, %ebx\n" /* line 191 */
        "movl %ebx, 0x285a0(%eax)\n"
        "movl %edx, 4(%ecx)\n" /* line 192 */
        "jmp .Lf1d1694_001d23c1\n"
        ".Lf1d1694_001d2410:\n"
        "leal 0x28594(%esi), %eax\n" /* line 555 */
        "xorl %edx, %edx\n" /* line 191 */
        "movl %edx, 0x28594(%esi)\n"
        "movl $0x3f800000, %ebx\n" /* line 192 */
        "movl %ebx, 4(%eax)\n"
        "movl %edx, 8(%eax)\n" /* line 193 */
        "movl imp_cg, %eax\n" /* line 556 */
        "movl (%eax), %eax\n"
        "leal 0x285a0(%eax), %ecx\n"
        "movl $0xbf800000, 0x285a0(%eax)\n" /* line 191 */
        "movl %edx, 4(%ecx)\n" /* line 192 */
        "jmp .Lf1d1694_001d23c1\n"
        ".Lf1d1694_001d2448:\n"
        "movl $str_002b7560, 4(%esp)\n" /* line 592 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d1694_001d224a\n"
        ".Lf1d1694_001d2461:\n"
        "movl 0x25bc0(%ebx), %edi\n" /* line 595 */
        "testl %edi, %edi\n"
        "jne .Lf1d1694_001d2257\n"
        "movss 0x285c8(%ebx), %xmm0\n" /* line 597 */
        "movss %xmm0, -0xdc(%ebp)\n"
        "calll crandom\n"
        "fstps -0xd8(%ebp)\n"
        "movl 0x1b8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movss -0xd8(%ebp), %xmm1\n"
        "mulss 0x580(%eax), %xmm1\n"
        "movss -0xdc(%ebp), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x285c8(%ebx)\n"
        "movss 0x285cc(%ebx), %xmm1\n" /* line 598 */
        "movss %xmm1, -0xd4(%ebp)\n"
        "calll crandom\n"
        "fstps -0xd0(%ebp)\n"
        "movl 0x1b8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movss -0xd0(%ebp), %xmm0\n"
        "mulss 0x57c(%eax), %xmm0\n"
        "movss -0xd4(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x285cc(%ebx)\n"
        "jmp .Lf1d1694_001d2257\n"
        ".Lf1d1694_001d250e:\n"
        "jp .Lf1d1694_001d1b41\n" /* line 357 */
        "leal -0x1c2(%edx), %eax\n" /* line 358 */
        "movl %eax, 0x284dc(%ebx)\n"
        "jmp .Lf1d1694_001d1b41\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_1d1694_0:\n"
        ".long .Lf1d1694_001d1d07\n"
        ".long .Lf1d1694_001d22ab\n"
        ".long .Lf1d1694_001d22f8\n"
        ".long .Lf1d1694_001d2345\n"
        ".long .Lf1d1694_001d2392\n"
        ".long .Lf1d1694_001d23db\n"
        ".long .Lf1d1694_001d2410\n"
        ".text\n"
    );
}
#endif

void CG_InitView(void)
{
    cg_t *cg;
    int renderPlayerState;

    cg = (cg_t *)*(int *)imp_cg;
    *(int *)((char *)cg + 0x285b8) = cg->time; /* TODO: unknown offset 0x285b8 */
    *(int *)((char *)cg + 0x285bc) = 0x3f800000; /* TODO: unknown offset 0x285bc */

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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
qboolean CG_DrawActiveFrame(int serverTime, DemoType demoType, CubemapShot cubemapShot, int cubemapSize, qboolean renderScreen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 935 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* serverTime */
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 942 */
        "movl (%eax), %ebx\n"
        "movl 0x25bb0(%ebx), %edx\n"
        "movl %edx, 0x25bb4(%ebx)\n"
        "movl %ecx, 0x25bb0(%ebx)\n" /* line 943 */
        "movl %ecx, 0xe08f4(%ebx)\n" /* line 944 */
        "movl 0xc(%ebp), %eax\n" /* line 946 | demoType */
        "movl %eax, 8(%ebx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 947 | cubemapShot */
        "movl %eax, 0xc(%ebx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 948 | cubemapSize */
        "movl %eax, 0x10(%ebx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 949 | renderScreen */
        "movl %eax, 0x14(%ebx)\n"
        "movl %ecx, %eax\n" /* line 951 */
        "subl %edx, %eax\n"
        "movl %eax, 0x25bac(%ebx)\n"
        "testl %eax, %eax\n" /* line 952 */
        "js .Lf1d25bc_001d29e6\n"
        ".Lf1d25bc_001d2611:\n"
        "calll CG_AddLagometerFrameInfo\n" /* line 957 */
        "movl 0x25bac(%ebx), %eax\n" /* line 959 */
        "movl %eax, 0xe08fc(%ebx)\n"
        "cmpb $0, 0x2a5fc(%ebx)\n" /* line 963 */
        "je .Lf1d25bc_001d2640\n"
        "movl imp_bgs, %eax\n" /* line 965 */
        "movl $0, (%eax)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1d25bc_001d2638:\n"
        "addl $0x4c, %esp\n" /* line 1149 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d25bc_001d2640:\n"
        "movl imp_bgs, %esi\n" /* line 969 */
        "leal 0x2cd18(%ebx), %eax\n"
        "movl %eax, (%esi)\n"
        "calll CG_ProcessSnapshots\n" /* line 972 */
        "movl 0x14(%ebx), %ecx\n" /* line 974 */
        "testl %ecx, %ecx\n"
        "je .Lf1d25bc_001d29d6\n"
        "movl 0x24(%ebx), %eax\n" /* line 982 */
        "testl %eax, %eax\n"
        "je .Lf1d25bc_001d29d6\n"
        "testb $2, (%eax)\n"
        "jne .Lf1d25bc_001d29d6\n"
        "movl imp_legacyHacks, %eax\n" /* line 992 */
        "movl (%eax), %eax\n"
        "cmpb $0, 0x5c(%eax)\n"
        "jne .Lf1d25bc_001d29c9\n"
        ".Lf1d25bc_001d2683:\n"
        "movb $0, 0xdc(%eax)\n" /* line 1008 */
        "movl imp_cg, %eax\n" /* line 1011 */
        "movl (%eax), %edi\n" /* delayedDrawing */
        "addl $1, (%edi)\n" /* delayedDrawing */
        "leal 0x28588(%edi), %esi\n" /* line 1013 | delayedDrawing, result */
        "movss 0x25ba8(%edi), %xmm2\n" /* delayedDrawing, frac */
        "movl 0x20(%edi), %edx\n" /* delayedDrawing */
        "leal 0x20(%edx), %ebx\n" /* from */
        "movl 0x24(%edi), %eax\n" /* delayedDrawing */
        "leal 0x20(%eax), %ecx\n" /* to */
        /* { scope 2 */
        "movss 0x20(%edx), %xmm1\n" /* line 264 */
        "movss 0x20(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x28588(%edi)\n"
        "movss 4(%ebx), %xmm1\n" /* line 265 */
        "movss 4(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movss 8(%ebx), %xmm1\n" /* line 266 */
        "movss 8(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movl 0x24(%edi), %eax\n" /* line 1014 | delayedDrawing */
        "movss 0x28590(%edi), %xmm0\n" /* delayedDrawing */
        "addss 0x104(%eax), %xmm0\n"
        "movss %xmm0, 0x28590(%edi)\n" /* delayedDrawing */
        "leal 0x28570(%edi), %eax\n" /* line 1015 | delayedDrawing */
        "movl %eax, (%esp)\n"
        "calll CL_SetLodOrigin\n"
        "movl 0x24(%edi), %edx\n" /* line 1017 | delayedDrawing */
        "movl 0x25bb0(%edi), %eax\n" /* delayedDrawing */
        "subl 0x7b0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_AdjustTime\n"
        "movl 0x20(%edi), %ecx\n" /* line 1020 | delayedDrawing */
        "movl 0x5e4(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1d25bc_001d2a05\n"
        "movl imp_cgs, %eax\n" /* line 1022 */
        "movl (%eax), %eax\n"
        "addl $0x68c4, %eax\n"
        "movl %eax, 0x2ccd8(%edi)\n" /* delayedDrawing */
        "movl 0x2ccf8(%edi), %eax\n" /* line 1023 | delayedDrawing */
        "movl %eax, 0x2ccdc(%edi)\n" /* delayedDrawing */
        "movl 0x2ccfc(%edi), %eax\n" /* line 1024 | delayedDrawing */
        "movl %eax, 0x2cce0(%edi)\n" /* delayedDrawing */
        ".Lf1d25bc_001d277d:\n"
        "movl imp_cg, %eax\n" /* line 1032 */
        "movl (%eax), %ebx\n" /* from */
        "movl 0x2cce0(%ebx), %eax\n" /* from */
        "movl %eax, 8(%esp)\n"
        "movl 0x2ccdc(%ebx), %eax\n" /* from */
        "movl %eax, 4(%esp)\n"
        "movl 0x2ccd8(%ebx), %eax\n" /* from */
        "movl %eax, (%esp)\n"
        "calll CG_UpdateShellShock\n"
        "movl imp_cg_thirdPerson, %eax\n" /* line 842 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1d25bc_001d29fb\n"
        "movl 0x24(%ebx), %eax\n"
        "cmpl $5, 0x10(%eax)\n"
        "jg .Lf1d25bc_001d29fb\n"
        "xorl %eax, %eax\n"
        ".Lf1d25bc_001d27c6:\n"
        "movl %eax, 0x25bc0(%ebx)\n"
        "movl imp_cg, %eax\n" /* line 814 */
        "movl %eax, -0x24(%ebp)\n"
        "movl (%eax), %ecx\n"
        "movl 0x24(%ecx), %eax\n"
        "movl 0x26b4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf1d25bc_001d2c1f\n"
        ".Lf1d25bc_001d27e7:\n"
        "testb $0x80, 0x1a(%eax)\n" /* line 1042 */
        "jne .Lf1d25bc_001d2a3f\n"
        "leal 0x2c030(%ecx), %edx\n" /* line 1048 | v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x2c030(%ecx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        /* } scope */
        "movl -0x24(%ebp), %ecx\n" /* line 1049 | v */
        "movl (%ecx), %edx\n"
        "leal 0x2c03c(%edx), %ecx\n" /* v */
        /* { scope 2 */
        "movl %eax, 0x2c03c(%edx)\n" /* line 183 */
        "movl %eax, 4(%ecx)\n" /* line 184 */
        "movl %eax, 8(%ecx)\n" /* line 185 */
        /* } scope */
        ".Lf1d25bc_001d281c:\n"
        "movl $0, (%esp)\n" /* line 1052 */
        "calll CL_ResetSkeletonCache\n"
        "calll CG_AddPacketEntities\n" /* line 1054 */
        "calll R_UpdateEffectsNonBolt\n" /* line 1057 */
        "calll CG_AddLocalEntities\n" /* line 1059 */
        "calll CL_Input\n" /* line 1062 */
        "calll CG_PredictPlayerState\n" /* line 1066 */
        "movl imp_cg, %eax\n" /* line 1070 */
        "movl (%eax), %esi\n" /* result */
        "leal 0x25bc4(%esi), %ebx\n" /* result, from */
        "movl %ebx, (%esp)\n" /* from */
        "calll CG_UpdateViewWeaponAnim\n"
        "calll CG_CalcViewValues\n" /* line 1073 */
        "leal 0x28594(%esi), %eax\n" /* line 1076 | result */
        "movl %eax, 8(%esp)\n"
        "leal 0x28588(%esi), %eax\n" /* result */
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%esi), %eax\n" /* result */
        "movl 0xd8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_SetListener\n"
        "movl %ebx, (%esp)\n" /* line 1082 | from */
        "calll CG_AddViewWeapon\n"
        "leal 0x28570(%esi), %eax\n" /* line 1084 | result */
        "movl %eax, (%esp)\n"
        "calll CL_FX_AdjustCamera\n"
        "movl 0x2c02c(%esi), %eax\n" /* line 783 */
        "testl %eax, %eax\n"
        "jle .Lf1d25bc_001d28b2\n"
        "addl 0x2c028(%esi), %eax\n" /* line 785 */
        "cmpl %eax, 0x25bb0(%esi)\n"
        "jg .Lf1d25bc_001d2cec\n"
        ".Lf1d25bc_001d28b2:\n"
        "movl imp_cg, %ebx\n" /* line 1090 | from */
        "movl %ebx, -0x24(%ebp)\n" /* from */
        "movl (%ebx), %ebx\n" /* from */
        "movl 0x24(%ebx), %eax\n" /* from */
        "testl $0xc00000, 0x18(%eax)\n"
        "jne .Lf1d25bc_001d2c9e\n"
        ".Lf1d25bc_001d28cd:\n"
        "movl -0x24(%ebp), %edx\n" /* line 1106 */
        "movl (%edx), %eax\n"
        "movl 0x26158(%eax), %edx\n"
        "cmpl $0x3ff, %edx\n"
        "je .Lf1d25bc_001d28fd\n"
        "movl %edx, %eax\n" /* line 1107 */
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl imp_cg_entities, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_ProcessEntity\n"
        ".Lf1d25bc_001d28fd:\n"
        "movl imp_cg_dumpAnims, %eax\n" /* line 916 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf1d25bc_001d291d\n"
        "movl imp_cg_paused, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d25bc_001d2d1d\n"
        ".Lf1d25bc_001d291d:\n"
        "calll R_UpdateEffectsBolt\n" /* line 1111 */
        "calll CL_BeginDelayedDrawing\n" /* line 1113 */
        "movl %eax, %edi\n" /* delayedDrawing */
        "calll CG_DrawPlayerSprites\n" /* line 1115 */
        "calll CG_Draw3dHudElems\n" /* line 1117 */
        "calll CG_Draw2D\n" /* line 1121 */
        "movl %edi, (%esp)\n" /* line 1124 | delayedDrawing */
        "calll CL_EndDelayedDrawing\n"
        "movl imp_cg, %eax\n" /* line 1127 */
        "movl (%eax), %esi\n" /* result */
        "movl 0x2be50(%esi), %ebx\n" /* result, from */
        "testl %ebx, %ebx\n" /* from */
        "js .Lf1d25bc_001d295a\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n" /* from */
        "jle .Lf1d25bc_001d29a7\n"
        /* { scope 2 */
        ".Lf1d25bc_001d295a:\n"
        "calll BG_GetNumWeapons\n" /* line 1131 */
        "movl %eax, 8(%esp)\n"
        "movl 0x2be50(%esi), %eax\n" /* result */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b758c, (%esp)\n" /* "WARNING: Invalid weaponSelect setting %i (out of range 0 - %" */
        "calll Com_Printf\n"
        "movl $1, %ecx\n"
        "movl %esi, %edx\n" /* result */
        ".Lf1d25bc_001d2980:\n"
        "movzbl 0x26118(%ecx, %edx), %eax\n" /* line 1135 */
        "testb %al, %al\n"
        "je .Lf1d25bc_001d2995\n"
        "movsbl %al, %eax\n" /* line 1136 */
        "movl %eax, 0x2be50(%edx)\n"
        ".Lf1d25bc_001d2995:\n"
        "addl $1, %ecx\n" /* line 1133 */
        "cmpl $3, %ecx\n"
        "jne .Lf1d25bc_001d2980\n"
        "movl $0, 0x2be50(%edx)\n" /* line 1139 */
        /* } scope */
        ".Lf1d25bc_001d29a7:\n"
        "calll CG_DrawActive\n" /* line 1143 */
        "movl %edi, (%esp)\n" /* line 1145 | delayedDrawing */
        "calll CL_IssueDelayedDrawing\n"
        "movl imp_bgs, %eax\n" /* line 1147 */
        "movl $0, (%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lf1d25bc_001d2638\n"
        ".Lf1d25bc_001d29c9:\n"
        "cmpb $0, 0x9c(%eax)\n" /* line 992 */
        "je .Lf1d25bc_001d2683\n"
        ".Lf1d25bc_001d29d6:\n"
        "movl $0, (%esi)\n" /* line 994 */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1149 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d25bc_001d29e6:\n"
        "movl $0, 0x25bac(%ebx)\n" /* line 954 */
        "movl %ecx, 0x25bb4(%ebx)\n" /* line 955 */
        "jmp .Lf1d25bc_001d2611\n"
        ".Lf1d25bc_001d29fb:\n"
        "movl $1, %eax\n" /* line 842 */
        "jmp .Lf1d25bc_001d27c6\n"
        ".Lf1d25bc_001d2a05:\n"
        "movl %edx, %eax\n" /* line 1028 */
        "shll $7, %eax\n"
        "leal 0x68c0(%eax, %edx, 4), %eax\n"
        "movl imp_cgs, %edx\n"
        "addl (%edx), %eax\n"
        "addl $4, %eax\n"
        "movl %eax, 0x2ccd8(%edi)\n" /* delayedDrawing */
        "movl 0x5e8(%ecx), %eax\n" /* line 1029 */
        "movl %eax, 0x2ccdc(%edi)\n" /* delayedDrawing */
        "movl 0x5ec(%ecx), %eax\n" /* line 1030 */
        "movl %eax, 0x2cce0(%edi)\n" /* delayedDrawing */
        "jmp .Lf1d25bc_001d277d\n"
        ".Lf1d25bc_001d2a3f:\n"
        "leal 0x25bc4(%ecx), %eax\n" /* line 238 */
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, (%esp)\n" /* line 239 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl imp_cg, %eax\n" /* line 242 */
        "movl %eax, -0x24(%ebp)\n"
        "movl (%eax), %eax\n"
        "movl 0x25bac(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf1d25bc_001d281c\n"
        "movl %edi, %esi\n"
        "pxor %xmm3, %xmm3\n"
        "leal -1(%edi), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        ".Lf1d25bc_001d2a7f:\n"
        "movl $5, %eax\n" /* line 247 */
        "cmpl $6, %esi\n"
        "cmovll %esi, %eax\n"
        "cvtsi2ssl %eax, %xmm4\n"
        "mulss lit4_002ed658, %xmm4\n" /* 0.0010000000474974513f */
        "movl -0x1c(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1d25bc_001d2d5a\n"
        "xorl %edx, %edx\n" /* line 1147 */
        "movl -0x24(%ebp), %ebx\n" /* from */
        "movl (%ebx), %ecx\n" /* from */
        "movss lit4_002ed6b4, %xmm6\n" /* 10.0f */
        "movss colorWhiteFaded+112, %xmm5\n"
        "movss lit4_002eda6c, %xmm7\n" /* 2400.0f */
        ".Lf1d25bc_001d2ac0:\n"
        "movss 0x2c030(%ecx, %edx, 4), %xmm1\n" /* line 252 */
        "ucomiss %xmm3, %xmm1\n"
        "jne .Lf1d25bc_001d2b17\n"
        "jp .Lf1d25bc_001d2b17\n"
        "movss 0x2c03c(%ecx, %edx, 4), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf1d25bc_001d2b93\n"
        "jp .Lf1d25bc_001d2b93\n"
        ".Lf1d25bc_001d2ae8:\n"
        "addl $1, %edx\n" /* line 250 */
        "cmpl $3, %edx\n"
        "jne .Lf1d25bc_001d2ac0\n"
        ".Lf1d25bc_001d2af0:\n"
        "subl $5, %esi\n" /* line 242 */
        "movl $0xcccccccd, %edx\n"
        "movl -0x28(%ebp), %eax\n"
        "mull %edx\n"
        "shrl $2, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "movl %edi, %eax\n"
        "subl %edx, %eax\n"
        "subl $5, %eax\n"
        "cmpl %eax, %esi\n"
        "jne .Lf1d25bc_001d2a7f\n"
        "jmp .Lf1d25bc_001d281c\n"
        ".Lf1d25bc_001d2b17:\n"
        "movss 0x2c03c(%ecx, %edx, 4), %xmm0\n" /* line 255 */
        "ucomiss %xmm3, %xmm0\n"
        "jp .Lf1d25bc_001d2b93\n"
        "jne .Lf1d25bc_001d2b93\n"
        ".Lf1d25bc_001d2b27:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 273 */
        "movl (%ebx), %eax\n"
        "movaps %xmm4, %xmm2\n"
        "mulss 0x2c030(%eax, %edx, 4), %xmm2\n"
        "movss 0x2c03c(%eax, %edx, 4), %xmm1\n" /* line 274 */
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm3\n"
        "ja .Lf1d25bc_001d2c08\n"
        ".Lf1d25bc_001d2b51:\n"
        "movaps %xmm2, %xmm0\n" /* line 277 */
        "addss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "ucomiss %xmm3, %xmm1\n"
        "jb .Lf1d25bc_001d2be8\n"
        "movss %xmm0, 0x2c03c(%eax, %edx, 4)\n" /* line 279 */
        "movl -0x24(%ebp), %ebx\n" /* line 280 */
        "movl (%ebx), %eax\n"
        "movss 0x2c03c(%eax, %edx, 4), %xmm1\n"
        "ucomiss %xmm3, %xmm1\n"
        "jp .Lf1d25bc_001d2bba\n"
        "jne .Lf1d25bc_001d2bba\n"
        ".Lf1d25bc_001d2b83:\n"
        "movl $0, 0x2c030(%eax, %edx, 4)\n" /* line 287 */
        "jmp .Lf1d25bc_001d2ae8\n"
        ".Lf1d25bc_001d2b93:\n"
        "ucomiss %xmm3, %xmm0\n" /* line 257 */
        "jbe .Lf1d25bc_001d2c15\n"
        "movss lit4_002ed5dc, %xmm0\n" /* line 269 | -1.0f */
        ".Lf1d25bc_001d2ba0:\n"
        "mulss %xmm7, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c030(%ecx, %edx, 4)\n"
        "jmp .Lf1d25bc_001d2b27\n"
        ".Lf1d25bc_001d2bba:\n"
        "movaps %xmm1, %xmm0\n" /* line 284 */
        "andps %xmm5, %xmm0\n"
        "ucomiss %xmm6, %xmm0\n"
        "jbe .Lf1d25bc_001d2ae8\n"
        "ucomiss %xmm3, %xmm1\n" /* line 286 */
        "jbe .Lf1d25bc_001d2d50\n"
        "movss %xmm6, -0x3c(%ebp)\n" /* line 287 */
        "movl -0x3c(%ebp), %ebx\n"
        ".Lf1d25bc_001d2bda:\n"
        "movl %ebx, 0x2c03c(%eax, %edx, 4)\n" /* line 286 */
        "movl -0x24(%ebp), %ebx\n" /* line 287 */
        "movl (%ebx), %eax\n"
        "jmp .Lf1d25bc_001d2b83\n"
        ".Lf1d25bc_001d2be8:\n"
        "movl $0, 0x2c03c(%eax, %edx, 4)\n" /* line 292 */
        "movl -0x24(%ebp), %ebx\n" /* line 293 */
        "movl (%ebx), %eax\n"
        "movl $0, 0x2c030(%eax, %edx, 4)\n"
        "jmp .Lf1d25bc_001d2ae8\n"
        ".Lf1d25bc_001d2c08:\n"
        "mulss lit4_002eda68, %xmm2\n" /* line 275 | 0.05999999865889549f */
        "jmp .Lf1d25bc_001d2b51\n"
        ".Lf1d25bc_001d2c15:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 274 | 1.0f */
        "jmp .Lf1d25bc_001d2ba0\n"
        ".Lf1d25bc_001d2c1f:\n"
        "xorl %edi, %edi\n" /* line 814 */
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "xorl %esi, %esi\n"
        "jmp .Lf1d25bc_001d2c4b\n"
        ".Lf1d25bc_001d2c2b:\n"
        "addl $1, %edi\n"
        "addl $0xf0, %esi\n"
        "movl -0x2c(%ebp), %ebx\n"
        "movl %ebx, -0x24(%ebp)\n"
        "movl (%ebx), %ecx\n"
        "movl 0x24(%ecx), %eax\n"
        "cmpl 0x26b4(%eax), %edi\n"
        "jge .Lf1d25bc_001d27e7\n"
        ".Lf1d25bc_001d2c4b:\n"
        "movl 0x26bc(%esi, %eax), %ebx\n" /* line 816 */
        "movl $0, 4(%esp)\n" /* line 817 */
        "movl %ebx, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "testl %eax, %eax\n" /* line 818 */
        "je .Lf1d25bc_001d2c76\n"
        "movl %eax, (%esp)\n" /* line 820 */
        "calll CG_DObjUpdateInfo\n"
        "movl %ebx, (%esp)\n" /* line 824 */
        "calll CG_ProcessClientNoteTracks\n"
        ".Lf1d25bc_001d2c76:\n"
        "movl %ebx, %eax\n" /* line 827 */
        "shll $4, %eax\n"
        "addl %ebx, %eax\n"
        "leal (%ebx, %eax, 8), %eax\n"
        "movl imp_cg_entities, %ecx\n"
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "cmpl $9, 0xf4(%eax)\n" /* line 828 */
        "jg .Lf1d25bc_001d2c2b\n"
        "movl %eax, (%esp)\n" /* line 829 */
        "calll CG_CalcEntityLerpPositions\n"
        "jmp .Lf1d25bc_001d2c2b\n"
        ".Lf1d25bc_001d2c9e:\n"
        "movl $0, 4(%esp)\n" /* line 1092 */
        "movl 0xd8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "testl %eax, %eax\n" /* line 1093 */
        "je .Lf1d25bc_001d2cd1\n"
        "movl %eax, (%esp)\n" /* line 1095 */
        "calll CG_DObjUpdateInfo\n"
        "movl 0x24(%ebx), %eax\n" /* line 1099 | from */
        "movl 0xd8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_ProcessClientNoteTracks\n"
        ".Lf1d25bc_001d2cd1:\n"
        "addl $0x2826c, %ebx\n" /* line 1102 | from */
        "movl %ebx, (%esp)\n" /* from */
        "calll CG_CalcEntityLerpPositions\n"
        "movl %ebx, (%esp)\n" /* line 1103 | from */
        "calll CG_ProcessEntity\n"
        "jmp .Lf1d25bc_001d28cd\n"
        ".Lf1d25bc_001d2cec:\n"
        "leal 0x2bfdc(%esi), %eax\n" /* line 789 */
        "movl %eax, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "leal 0x2c01c(%esi), %edx\n" /* line 791 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FX_PlaySimpleEffect\n"
        "movl 0x25bb0(%esi), %eax\n" /* line 792 */
        "movl %eax, 0x2c028(%esi)\n"
        "jmp .Lf1d25bc_001d28b2\n"
        ".Lf1d25bc_001d2d1d:\n"
        "movl $0, 4(%esp)\n" /* line 918 */
        "movl %edx, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 919 */
        "je .Lf1d25bc_001d291d\n"
        "movl $str_002b7580, (%esp)\n" /* line 921 */
        "calll Com_Printf\n"
        "movl %ebx, (%esp)\n" /* line 922 */
        "calll DObjDisplayAnim\n"
        "jmp .Lf1d25bc_001d291d\n"
        ".Lf1d25bc_001d2d50:\n"
        "movl $0xc1200000, %ebx\n" /* line 282 */
        "jmp .Lf1d25bc_001d2bda\n"
        ".Lf1d25bc_001d2d5a:\n"
        "xorl %edx, %edx\n" /* line 247 */
        "movl -0x24(%ebp), %ebx\n"
        "movl (%ebx), %ecx\n"
        "movss lit4_002ed5dc, %xmm7\n" /* -1.0f */
        ".Lf1d25bc_001d2d69:\n"
        "movss 0x2c030(%ecx, %edx, 4), %xmm1\n" /* line 252 */
        "ucomiss %xmm3, %xmm1\n"
        "jne .Lf1d25bc_001d2d96\n"
        "jp .Lf1d25bc_001d2d96\n"
        "movss 0x2c03c(%ecx, %edx, 4), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf1d25bc_001d2da6\n"
        "jp .Lf1d25bc_001d2da6\n"
        ".Lf1d25bc_001d2d89:\n"
        "addl $1, %edx\n" /* line 250 */
        "cmpl $3, %edx\n"
        "jne .Lf1d25bc_001d2d69\n"
        "jmp .Lf1d25bc_001d2af0\n"
        ".Lf1d25bc_001d2d96:\n"
        "movss 0x2c03c(%ecx, %edx, 4), %xmm0\n" /* line 255 */
        "ucomiss %xmm3, %xmm0\n"
        "jp .Lf1d25bc_001d2da6\n"
        "je .Lf1d25bc_001d2df2\n"
        ".Lf1d25bc_001d2da6:\n"
        "movaps %xmm3, %xmm2\n" /* line 257 */
        "movss lit4_002ed5d0, %xmm6\n" /* 1.0f */
        "movaps %xmm6, %xmm5\n"
        "cmpnltss %xmm0, %xmm2\n"
        "andps %xmm2, %xmm5\n"
        "andnps %xmm7, %xmm2\n"
        "orps %xmm5, %xmm2\n"
        "movss 0x25ca0(%ecx), %xmm0\n" /* line 262 */
        "ucomiss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "jbe .Lf1d25bc_001d2e4f\n"
        "movaps %xmm2, %xmm0\n" /* line 263 */
        "movl -0x20(%ebp), %eax\n"
        "mulss 0x4b0(%eax), %xmm0\n"
        ".Lf1d25bc_001d2de1:\n"
        "mulss %xmm4, %xmm0\n" /* line 269 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c030(%ecx, %edx, 4)\n"
        ".Lf1d25bc_001d2df2:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 273 */
        "movl (%ebx), %eax\n"
        "movaps %xmm4, %xmm2\n"
        "mulss 0x2c030(%eax, %edx, 4), %xmm2\n"
        "movss 0x2c03c(%eax, %edx, 4), %xmm1\n" /* line 274 */
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm3\n"
        "jbe .Lf1d25bc_001d2e20\n"
        "mulss lit4_002eda68, %xmm2\n" /* line 275 | 0.05999999865889549f */
        ".Lf1d25bc_001d2e20:\n"
        "addss %xmm1, %xmm2\n" /* line 277 */
        "mulss %xmm2, %xmm1\n"
        "ucomiss %xmm3, %xmm1\n"
        "jb .Lf1d25bc_001d2eb8\n"
        "movss %xmm2, 0x2c03c(%eax, %edx, 4)\n" /* line 279 */
        "ucomiss %xmm3, %xmm2\n" /* line 280 */
        "jne .Lf1d25bc_001d2e5f\n"
        "jp .Lf1d25bc_001d2e5f\n"
        ".Lf1d25bc_001d2e41:\n"
        "movss %xmm3, 0x2c030(%eax, %edx, 4)\n" /* line 293 */
        "jmp .Lf1d25bc_001d2d89\n"
        ".Lf1d25bc_001d2e4f:\n"
        "movaps %xmm2, %xmm0\n" /* line 265 */
        "movl -0x20(%ebp), %ebx\n"
        "mulss 0x4f8(%ebx), %xmm0\n"
        "jmp .Lf1d25bc_001d2de1\n"
        ".Lf1d25bc_001d2e5f:\n"
        "movaps %xmm2, %xmm0\n" /* line 284 */
        "andps colorWhiteFaded+112, %xmm0\n"
        "ucomiss lit4_002ed6b4, %xmm0\n" /* 10.0f */
        "jbe .Lf1d25bc_001d2d89\n"
        "movaps %xmm3, %xmm0\n" /* line 286 */
        "movss lit4_002ed98c, %xmm5\n" /* -10.0f */
        "movss lit4_002ed6b4, %xmm6\n" /* 10.0f */
        "movaps %xmm5, %xmm1\n"
        "cmpnltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm6, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c03c(%eax, %edx, 4)\n"
        "movl -0x24(%ebp), %ebx\n" /* line 287 */
        "movl (%ebx), %eax\n"
        "movl $0, 0x2c030(%eax, %edx, 4)\n"
        "jmp .Lf1d25bc_001d2d89\n"
        ".Lf1d25bc_001d2eb8:\n"
        "movss %xmm3, 0x2c03c(%eax, %edx, 4)\n" /* line 292 */
        "jmp .Lf1d25bc_001d2e41\n"
    );
}
#endif
