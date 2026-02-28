/* Converted to C from ASM: cg_predict_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_predict_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern float sinf(float x);
extern float cosf(float x);
extern float sqrtf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/q_shared.h"
 */

static pmove_t cg_pmove[1]; /* cg_pmove */
static int cg_numSolidEntities; /* cg_numSolidEntities */
static cg_solidEntities_t cg_solidEntities; /* cg_solidEntities */
static int cg_numTriggerEntities; /* cg_numTriggerEntities */
static centity_t * cg_triggerEntities[256]; /* cg_triggerEntities */

extern int CM_PointContents(const vec_t *point, unsigned int model);
extern int CM_TransformedPointContents(const vec_t *point, unsigned int model, const vec_t *origin, const vec_t *angles);
extern int CM_ContentsOfModel(unsigned int model);
extern void CM_BoxTrace(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, unsigned int model, int brushmask);
extern unsigned int CM_TempBoxModel(const vec_t *mins, const vec_t *maxs, int capsule);
extern void CM_TransformedBoxTraceExternal(trace_t *results, const vec_t *start, const vec_t *end, const vec_t *mins, const vec_t *maxs, unsigned int model, int brushmask, const vec_t *origin, const vec_t *angles);
extern float CM_RadiusOfModel(unsigned int model);
extern int CL_GetCurrentCmdNumber(void);
extern qboolean CL_GetUserCmd(int cmdNumber, usercmd_t *ucmd);
extern void PM_UpdateViewAngles(playerState_t *ps, const usercmd_t *cmd, int, int);
extern float LerpAngle(float from, float to, float frac);
extern void Pmove(pmove_t *pm);
extern void CG_TransitionPlayerState(playerState_t *ps, playerState_t *ops);
extern void BG_PlayerStateToEntityState(playerState_t *ps, entityState_t *es, int, int);
extern void BG_EvaluateTrajectory(trajectory_t *tr, int atTime, vec_t *result);
extern WeaponDef * BG_GetWeaponDef(int weapon);
extern qboolean CG_GetWeapReticleZoom(float *fZoom);
extern float flrand(float min, float max);
extern float randomf(void);
extern float AngleNormalize360(float angle);
extern qboolean BG_PlayerTouchesItem(playerState_t *ps, centity_t *item, int atTime);
extern qboolean BG_CanItemBeGrabbed(centity_t *item, playerState_t *ps, int);
extern void BG_AddPredictableEventToPlayerstate(int event, int eventParm, playerState_t *ps);
extern void CG_AdjustPositionForMover(const vec_t *in, int moverNum, int fromTime, int toTime, vec_t *out, vec_t *outDeltaAngles);
extern void LargeLocal_LargeLocal(void *ll, int size);
extern void * LargeLocal_GetBuf(void *ll);
extern void ZN10LargeLocalD1Ev(void *ll);
extern void Com_Printf(const char *fmt, ...);

/* External globals */
extern byte **cg_glob;           /* imp_cg — pointer to cg_t base */
extern byte **cg_entities_glob;  /* imp_cg_entities — pointer to centity array base */

/* Dvar pointers (pointer-to-pointer) */
extern const dvar_t **dvar_nopredict;    /* imp_cg_nopredict — cg_nopredict */
extern const dvar_t **dvar_synchronous;  /* imp_cg_synchronousClients — cg_synchronousClients */
extern const dvar_t **dvar_developer;    /* imp_cg_showmiss — developer */
extern const dvar_t **dvar_autoPickup;   /* imp_cg_predictItems — cg_autoPickup */
extern const dvar_t **dvar_errorDecay;   /* imp_cg_errorDecay — cg_errorDecay */

/* cg_t field offsets */
#define CG_DEMOYPE          0x08
#define CG_SNAP              0x20
#define CG_NEXTSNAP          0x24
#define CG_FRAMEINTERP       0x25ba8
#define CG_TIME              0x25bb0
#define CG_OLDTIME           0x25bb4
#define CG_PHYSICSTIME       0x25bb8
#define CG_PREDICTEDPS       0x25bc4
#define CG_PREDICTEDPS_ORIGIN 0x25bd8
#define CG_PREDICTEDERRORTIME 0x284c0
#define CG_PREDICTEDERROR    0x284c4
#define CG_KICKYAW           0x2c048
#define CG_KICKPITCH         0x2c04c
#define CG_ZOOMKICKED        0x2cd10

/* sizeof(playerState_t) in binary = 0x26A8, larger than common_types.h definition */
#define REAL_PS_SIZE 0x26a8

void CG_ClearSolidList(void);
int CG_PointContents(const vec_t *point, int passEntityNum, int contentmask);
static void CG_InterpolatePlayerState(qboolean grabAngles);
void CG_PredictPlayerState(void);
static void Trace_CalcBounds(const vec_t *start, const vec_t *mins, const vec_t *maxs, float fraction, const vec_t *end, vec3_t *bounds);
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
        centity_t *cent = ((centity_t **)&cg_solidEntities)[i];
        entityState_t *ent = &cent->nextState;

        if (ent->number == passEntityNum)
            continue;
        if (ent->solid != 0xffffff)
            continue;
        if (ent->index.brushmodel == 0)
            continue;

        contents |= CM_TransformedPointContents(point, ent->index.brushmodel,
                                                 cent->lerpOrigin,
                                                 cent->lerpAngles);
    }

    return contents & contentmask;
}

/* line 321 */
static void CG_InterpolatePlayerState(qboolean grabAngles)
{
    byte *cg;
    playerState_t *out;
    snapshot_t *prev;
    snapshot_t *next;
    usercmd_t cmd;
    float f;
    int i;

    cg = *cg_glob;
    out = (playerState_t *)(cg + CG_PREDICTEDPS);
    prev = *(snapshot_t **)(cg + CG_SNAP);
    next = *(snapshot_t **)(cg + CG_NEXTSNAP);

    /* Copy next snapshot's playerstate to predicted */
    memcpy(out, &next->ps, REAL_PS_SIZE);

    if (grabAngles) {
        int cmdNum = CL_GetCurrentCmdNumber();
        CL_GetUserCmd(cmdNum, &cmd);
        PM_UpdateViewAngles(out, &cmd, 0, 0);
    }

    /* Don't interpolate if snaps are at same time or reversed */
    if (next->serverTime <= prev->serverTime)
        return;

    f = *(float *)(cg + CG_FRAMEINTERP);

    /* Interpolate bobCycle with wrap-around */
    {
        int nextBob = next->ps.bobCycle;
        int prevBob = prev->ps.bobCycle;
        int adjusted = nextBob;
        if (nextBob < prevBob)
            adjusted = nextBob + 256;
        out->bobCycle = prevBob + (int)((float)(adjusted - prevBob) * f);
    }

    /* Interpolate aimSpreadScale */
    out->aimSpreadScale = prev->ps.aimSpreadScale +
        (next->ps.aimSpreadScale - prev->ps.aimSpreadScale) * f;

    if (grabAngles) {
        /* View angles already set by PM_UpdateViewAngles; interpolate position and velocity */
        for (i = 0; i < 3; i++) {
            out->origin[i] = prev->ps.origin[i] + (next->ps.origin[i] - prev->ps.origin[i]) * f;
            out->velocity[i] = prev->ps.velocity[i] + (next->ps.velocity[i] - prev->ps.velocity[i]) * f;
        }
    } else {
        /* Interpolate position, velocity, and view angles */
        for (i = 0; i < 3; i++) {
            out->origin[i] = prev->ps.origin[i] + (next->ps.origin[i] - prev->ps.origin[i]) * f;
            out->viewangles[i] = LerpAngle(prev->ps.viewangles[i], next->ps.viewangles[i], f);
            out->velocity[i] = prev->ps.velocity[i] + (next->ps.velocity[i] - prev->ps.velocity[i]) * f;
        }
    }

    /* Interpolate remaining fields */
    out->viewHeightCurrent = prev->ps.viewHeightCurrent +
        (next->ps.viewHeightCurrent - prev->ps.viewHeightCurrent) * f;
    out->leanf = prev->ps.leanf + (next->ps.leanf - prev->ps.leanf) * f;
    out->fWeaponPosFrac = prev->ps.fWeaponPosFrac +
        (next->ps.fWeaponPosFrac - prev->ps.fWeaponPosFrac) * f;
}

/* line 687 */
void CG_PredictPlayerState(void)
{
    byte ll[32]; /* LargeLocal object */
    byte *oldPlayerState;
    byte *cg;
    playerState_t *ps;
    snapshot_t *nextSnap;
    int cmdNum, oldest;
    usercmd_t curCmd;
    qboolean moved;
    WeaponDef *weapDef;
    int cg_time;

    LargeLocal_LargeLocal(ll, REAL_PS_SIZE);
    oldPlayerState = (byte *)LargeLocal_GetBuf(ll);

    cg = *cg_glob;

    /* Check if we should just interpolate (demo playback or follow mode) */
    if (*(int *)(cg + CG_DEMOYPE) != 0) {
        CG_InterpolatePlayerState(0);
        goto cleanup;
    }
    nextSnap = *(snapshot_t **)(cg + CG_NEXTSNAP);
    if (nextSnap->ps.pm_flags & 0x400000) { /* PMF_FOLLOW */
        CG_InterpolatePlayerState(0);
        goto cleanup;
    }

    /* Check nopredict / synchronous dvars */
    if (*(byte *)((byte *)*dvar_nopredict + 8) != 0 ||
        *(byte *)((byte *)*dvar_synchronous + 8) != 0) {
        CG_InterpolatePlayerState(1);
        goto cleanup;
    }

    ps = (playerState_t *)(cg + CG_PREDICTEDPS);

    /* Set up pmove */
    cg_pmove[0].ps = ps;
    cg_pmove[0].handler = 0;

    /* Set tracemask based on pm_type */
    {
        int mask;
        if (ps->pm_type < 6)
            mask = 0x2810011;
        else
            mask = 0x810011;

        /* Dead players: remove some collision flags */
        nextSnap = *(snapshot_t **)(cg + CG_NEXTSNAP);
        if (nextSnap->ps.pm_type == 4) /* PM_DEAD */
            mask &= ~0x02010000;

        cg_pmove[0].tracemask = mask;
    }

    /* Get command range */
    cmdNum = CL_GetCurrentCmdNumber();
    oldest = cmdNum - 127;

    /* Verify oldest command is available */
    {
        usercmd_t oldestCmd;
        if (!CL_GetUserCmd(oldest, &oldestCmd)) {
            if (*(int *)((byte *)*dvar_developer + 8) != 0)
                Com_Printf("CG_PredictPlayerState: CMD_BACKUP exceeded\n");
            goto cleanup;
        }
    }

    /* Save current predicted player state */
    memcpy(oldPlayerState, ps, REAL_PS_SIZE);

    /* Get current (latest) user command */
    CL_GetUserCmd(cmdNum, &curCmd);

    /* Reset predicted state to next snapshot's state */
    cg = *cg_glob;
    nextSnap = *(snapshot_t **)(cg + CG_NEXTSNAP);
    memcpy(ps, &nextSnap->ps, REAL_PS_SIZE);

    /* Set physics time to snapshot time */
    *(int *)(cg + CG_PHYSICSTIME) = nextSnap->serverTime;

    /* Restore old velocity from saved state */
    ps->oldVelocity[0] = ((playerState_t *)oldPlayerState)->oldVelocity[0];
    ps->oldVelocity[1] = ((playerState_t *)oldPlayerState)->oldVelocity[1];

    /* Check if we need to predict */
    nextSnap = *(snapshot_t **)(cg + CG_NEXTSNAP);
    if (nextSnap->ps.commandTime >= curCmd.serverTime)
        goto postPredict;

    /* Prediction loop */
    moved = 0;
    for (; oldest <= cmdNum; oldest++) {
        /* Get user command for this step */
        CL_GetUserCmd(oldest, &cg_pmove[0].cmd);

        cg = *cg_glob;

        /* Skip commands that are before our current time */
        if (cg_pmove[0].cmd.serverTime <= ps->commandTime)
            continue;

        /* Skip commands after the target time */
        if (cg_pmove[0].cmd.serverTime > curCmd.serverTime)
            continue;

        /* Get previous command for oldcmd */
        if (!CL_GetUserCmd(oldest - 1, &cg_pmove[0].oldcmd))
            continue;

        /* First prediction step: handle mover adjustment */
        if (ps->commandTime == ((playerState_t *)oldPlayerState)->commandTime) {
            vec3_t oldOrigin;
            vec3_t deltaAngles;
            vec3_t delta;
            float len;
            int isMatch;

            /* Adjust position for any mover we're standing on */
            CG_AdjustPositionForMover(
                ps->origin,
                ps->groundEntityNum,
                *(int *)(cg + CG_OLDTIME),
                *(int *)(cg + CG_PHYSICSTIME),
                oldOrigin, deltaAngles);

            /* Adjust yaw delta_angles for mover rotation */
            ps->delta_angles[1] += (int)(deltaAngles[1] * (65536.0f / 360.0f)) & 0xffff;

            /* Check prediction error */
            if (*(int *)((byte *)*dvar_developer + 8) != 0) {
                /* Compare old predicted origin with mover-adjusted origin */
                float *oldOrig = &((playerState_t *)oldPlayerState)->origin[0];
                isMatch = (oldOrig[0] == oldOrigin[0] &&
                           oldOrig[1] == oldOrigin[1] &&
                           oldOrig[2] == oldOrigin[2]);
                if (!isMatch) {
                    Com_Printf("CG_PredictPlayerState: prediction not matched\n");
                }
            }

            /* Compute position delta */
            delta[0] = ((playerState_t *)oldPlayerState)->origin[0] - oldOrigin[0];
            delta[1] = ((playerState_t *)oldPlayerState)->origin[1] - oldOrigin[1];
            delta[2] = ((playerState_t *)oldPlayerState)->origin[2] - oldOrigin[2];

            /* Check magnitude of prediction error */
            len = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
            if (len > 0.1f) {
                float *predictedError;
                float errorDecayVal;

                if (*(int *)((byte *)*dvar_developer + 8) != 0)
                    Com_Printf("Prediction miss: %f\n", (double)len);

                /* Apply error decay */
                errorDecayVal = *(float *)((byte *)*dvar_errorDecay + 8);
                predictedError = (float *)(cg + CG_PREDICTEDERROR);

                if (errorDecayVal == 0.0f) {
                    /* No decay: clear error */
                    predictedError[0] = 0.0f;
                    predictedError[1] = 0.0f;
                    predictedError[2] = 0.0f;
                } else {
                    float t;
                    int cg_time_val = *(int *)(cg + CG_TIME);
                    int errorTime = *(int *)(cg + CG_PREDICTEDERRORTIME);

                    t = 1.0f - (float)(cg_time_val - errorTime) / errorDecayVal;
                    if (t < 0.0f)
                        t = 0.0f;

                    if (t > 0.0f && *(int *)((byte *)*dvar_developer + 8) != 0)
                        Com_Printf("Double prediction decay: %f\n", (double)t);

                    /* Scale existing error by decay factor */
                    predictedError[0] *= t;
                    predictedError[1] *= t;
                    predictedError[2] *= t;
                }

                /* Add new delta to prediction error */
                predictedError[0] += delta[0];
                predictedError[1] += delta[1];
                predictedError[2] += delta[2];

                /* Record error time */
                *(int *)(cg + CG_PREDICTEDERRORTIME) = *(int *)(cg + CG_OLDTIME);
            }
        }

        /* Run prediction */
        Pmove(&cg_pmove[0]);

        /* Touch trigger entities */
        {
            int pm_type;
            cg = *cg_glob;
            pm_type = ps->pm_type;

            if (pm_type <= 5) {
                int inDeadState = (pm_type == 4);
                if (pm_type <= 1 || inDeadState) {
                    int j;
                    for (j = 0; j < cg_numTriggerEntities; j++) {
                        centity_t *cent = cg_triggerEntities[j];
                        entityState_t *ent = &cent->nextState;

                        /* Item pickup prediction */
                        if (ent->eType == 3 && !inDeadState) { /* ET_ITEM */
                            if (*(byte *)((byte *)*dvar_autoPickup + 8) == 0)
                                continue;

                            cg = *cg_glob;
                            cg_time = *(int *)(cg + CG_TIME);

                            if (!BG_PlayerTouchesItem(ps, cent, cg_time))
                                continue;
                            if (cent->miscTime == cg_time)
                                continue;
                            if (!BG_CanItemBeGrabbed(cent, ps, 1))
                                continue;

                            /* Predict item pickup */
                            cent->nextState.eFlags |= 0x20; /* EF_NODRAW predicted */
                            cent->miscTime = cg_time;
                            BG_AddPredictableEventToPlayerstate(0x90, cent->nextState.index.item, ps);
                            continue;
                        }

                        /* Brush model trigger: point trace */
                        if (ent->solid == 0xffffff) {
                            unsigned int cmodel = ent->index.brushmodel;
                            if (cmodel != 0) {
                                trace_t trace;
                                cg = *cg_glob;
                                CM_BoxTrace(&trace,
                                    ps->origin, ps->origin,
                                    cg_pmove[0].mins, cg_pmove[0].maxs,
                                    cmodel, -1);
                            }
                        }
                    }
                }
            }
        }

        moved = 1;
    }

postPredict:
    /* Debug output */
    if (*(int *)((byte *)*dvar_developer + 8) > 1) {
        cg = *cg_glob;
        Com_Printf("[%i : %i] ", cg_pmove[0].cmd.serverTime, *(int *)(cg + CG_TIME));
    }

    if (moved) {
        /* Adjust for mover after prediction */
        vec3_t deltaAngles;
        cg = *cg_glob;
        CG_AdjustPositionForMover(
            ps->origin,
            ps->groundEntityNum,
            *(int *)(cg + CG_PHYSICSTIME),
            *(int *)(cg + CG_TIME),
            ps->origin, deltaAngles);
    } else {
        /* No prediction occurred */
        if (*(int *)((byte *)*dvar_developer + 8) != 0)
            Com_Printf("not moved\n");
    }

    /* Transition player state (handle events etc) */
    cg = *cg_glob;
    CG_TransitionPlayerState(ps, (playerState_t *)oldPlayerState);

cleanup:
    ZN10LargeLocalD1Ev(ll);

    /* Post-prediction: update entity state from predicted player state */
    cg = *cg_glob;
    ps = (playerState_t *)(cg + CG_PREDICTEDPS);

    /* Find our client entity */
    {
        int clientNum = ps->clientNum;
        byte *entities = *cg_entities_glob;
        byte *cent = entities + clientNum * 548; /* sizeof(centity_t) = 548 */
        float *lerpOrigin = (float *)(cent + 0x1EC); /* centity_t.lerpOrigin */
        float *lerpAngles = (float *)(cent + 0x1F8); /* centity_t.lerpAngles */

        /* Copy predicted origin to lerpOrigin */
        lerpOrigin[0] = ps->origin[0];
        lerpOrigin[1] = ps->origin[1];
        lerpOrigin[2] = ps->origin[2];

        /* Evaluate angular trajectory for lerpAngles */
        BG_EvaluateTrajectory(
            (trajectory_t *)(cent + 0x30), /* currentState.apos */
            *(int *)(cg + CG_TIME),
            lerpAngles);
    }

    /* Handle ADS zoom kick */
    weapDef = BG_GetWeaponDef(ps->weapon);
    nextSnap = *(snapshot_t **)(cg + CG_NEXTSNAP);

    if (nextSnap->ps.pm_flags & 0x800000) { /* ADS flag */
        float fZoom;
        if (CG_GetWeapReticleZoom(&fZoom)) {
            if (weapDef->adsViewErrorMax != 0.0f) {
                if (*(int *)(cg + CG_ZOOMKICKED) == 0) {
                    float size, angle, sinAngle, cosAngle;
                    float *kickYaw = (float *)(cg + CG_KICKYAW);
                    float *kickPitch = (float *)(cg + CG_KICKPITCH);

                    *(int *)(cg + CG_ZOOMKICKED) = 1;

                    size = flrand(weapDef->adsViewErrorMin, weapDef->adsViewErrorMax);
                    angle = randomf() * 2.0f * 3.14159265358979323846f;

                    cosAngle = cosf(angle);
                    sinAngle = sinf(angle);

                    *kickYaw = AngleNormalize360(*kickYaw + sinAngle * size);
                    *kickPitch = AngleNormalize360(*kickPitch + cosAngle * size);
                }
            }
        }
    } else {
        *(int *)(cg + CG_ZOOMKICKED) = 0;
    }

    /* Convert predicted player state to entity state */
    {
        entityState_t *es = (entityState_t *)(cg + 0x2835c); /* predictedPlayerEntity.nextState */
        byte *entBase = cg + 0x2826c; /* predictedPlayerEntity (currentState) */

        es->number = ps->clientNum;
        BG_PlayerStateToEntityState(ps, es, 0, 0);

        /* Copy nextState to currentState */
        memcpy(entBase, es, 0xF0); /* sizeof(entityState_t) = 0xF0 */
    }
}

/* line 115 */
static void Trace_CalcBounds(const vec_t *start, const vec_t *mins, const vec_t *maxs, float fraction, const vec_t *end, vec3_t *bounds)
{
    float hit0, hit1, hit2;

    /* Compute hit point along trace */
    hit0 = start[0] + (end[0] - start[0]) * fraction;
    hit1 = start[1] + (end[1] - start[1]) * fraction;
    hit2 = start[2] + (end[2] - start[2]) * fraction;

    /* bounds[0..2] = min(start, hit) + mins */
    bounds[0][0] = (start[0] < hit0 ? start[0] : hit0) + mins[0];
    bounds[0][1] = (start[1] < hit1 ? start[1] : hit1) + mins[1];
    bounds[0][2] = (start[2] < hit2 ? start[2] : hit2) + mins[2];

    /* bounds[3..5] = max(start, hit) + maxs */
    bounds[1][0] = (start[0] > hit0 ? start[0] : hit0) + maxs[0];
    bounds[1][1] = (start[1] > hit1 ? start[1] : hit1) + maxs[1];
    bounds[1][2] = (start[2] > hit2 ? start[2] : hit2) + maxs[2];
}

/* line 135 */
void CG_ClipMoveToEntities(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int skipNumber, int mask, int capsule, trace_t *tr)
{
    int i;
    vec3_t bounds[2]; /* [0]=mins [1]=maxs of trace extent */
    trace_t trace;
    vec3_t bmins, bmaxs;
    vec3_t angles;
    unsigned int cmodel;

    /* Compute trace extent bounds */
    Trace_CalcBounds(start, mins, maxs, tr->fraction, end, bounds);

    for (i = 0; i < cg_numSolidEntities; i++) {
        centity_t *cent = ((centity_t **)&cg_solidEntities)[i];
        entityState_t *ent = &cent->nextState;

        /* Skip self */
        if (ent->number == skipNumber)
            continue;

        if (ent->solid == 0xffffff) {
            /* SOLID_BMODEL */
            cmodel = ent->index.brushmodel;

            /* Check contents match */
            if (!(CM_ContentsOfModel(cmodel) & mask))
                continue;

            /* Broadphase: check against model radius */
            {
                float radius = CM_RadiusOfModel(cmodel);

                if (cent->lerpOrigin[0] - radius >= bounds[1][0])
                    continue;
                if (cent->lerpOrigin[1] - radius >= bounds[1][1])
                    continue;
                if (cent->lerpOrigin[0] + radius <= bounds[0][0])
                    continue;
                if (cent->lerpOrigin[1] + radius <= bounds[0][1])
                    continue;
                if (cent->lerpOrigin[2] - radius >= bounds[1][2])
                    continue;
                if (cent->lerpOrigin[2] + radius <= bounds[0][2])
                    continue;
            }

            /* Copy angles from entity */
            angles[0] = cent->lerpAngles[0];
            angles[1] = cent->lerpAngles[1];
            angles[2] = cent->lerpAngles[2];
        } else {
            /* Encoded solid dimensions */
            int solid = ent->solid;
            int w, h1, h2;
            int contentFlags;

            /* Decode solid: content type check */
            contentFlags = (ent->eType == 1) ? 0x2000000 : 1;
            if (!(contentFlags & mask))
                continue;

            /* Decode dimensions */
            w = solid & 0xFF;
            h1 = (solid >> 8) & 0xFF;
            h2 = (solid >> 16) & 0xFF;

            bmins[0] = bmins[1] = (float)(1 - w);
            bmaxs[0] = bmaxs[1] = (float)(w - 1);
            bmins[2] = 1.0f - (float)(h1 - 1);
            bmaxs[2] = (float)(h2 - 32) - 1.0f;

            /* Broadphase AABB check */
            if (cent->lerpOrigin[0] + bmins[0] >= bounds[1][0])
                continue;
            if (cent->lerpOrigin[1] + bmins[1] >= bounds[1][1])
                continue;
            if (cent->lerpOrigin[0] + bmaxs[0] <= bounds[0][0])
                continue;
            if (cent->lerpOrigin[1] + bmaxs[1] <= bounds[0][1])
                continue;
            if (cent->lerpOrigin[2] + bmins[2] >= bounds[1][2])
                continue;
            if (cent->lerpOrigin[2] + bmaxs[2] <= bounds[0][2])
                continue;

            /* Create temp box model */
            cmodel = CM_TempBoxModel(bmins, bmaxs, capsule);

            /* Clear angles for non-bmodel */
            angles[0] = 0.0f;
            angles[1] = 0.0f;
            angles[2] = 0.0f;
        }

        /* Perform trace against entity */
        CM_TransformedBoxTraceExternal(&trace, start, end, mins, maxs,
            cmodel, mask, cent->lerpOrigin, angles);

        if (trace.fraction < tr->fraction) {
            /* New closest hit */
            trace.entityNum = ent->number;
            *tr = trace;

            /* Recalculate trace bounds for tighter culling */
            Trace_CalcBounds(start, mins, maxs, trace.fraction, end, bounds);
        } else if (trace.allsolid) {
            tr->allsolid = 1;
        } else if (trace.startsolid) {
            tr->startsolid = 1;
        }

        if (tr->allsolid)
            return;
    }
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
    byte *cg;
    snapshot_t *snap;
    int numEntities;
    byte *cg_entities_base;

    cg_numSolidEntities = 0;
    cg_numTriggerEntities = 0;

    cg = *cg_glob;
    snap = *(snapshot_t **)(cg + CG_NEXTSNAP);
    numEntities = snap->numEntities;
    cg_entities_base = *cg_entities_glob;

    for (i = 0; i < numEntities; i++) {
        entityState_t *snapEnt = &snap->entities[i];
        int entityNum = snapEnt->number;
        centity_t *cent = (centity_t *)(cg_entities_base + entityNum * 548);
        entityState_t *ent = &cent->nextState;

        if (ent->solid == 0xffffff) {
            if (ent->eFlags & 1)
                continue;
            if (CM_ContentsOfModel(ent->index.brushmodel) == 0)
                continue;
        }

        if (ent->eType == 3) { /* ET_ITEM */
            cg_triggerEntities[cg_numTriggerEntities] = cent;
            cg_numTriggerEntities++;
        } else if (ent->solid != 0) {
            ((centity_t **)&cg_solidEntities)[cg_numSolidEntities] = cent;
            cg_numSolidEntities++;
        }
    }
}
