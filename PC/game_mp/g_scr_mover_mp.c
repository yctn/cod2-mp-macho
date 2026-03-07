/* Converted to C from ASM: g_scr_mover_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_scr_mover_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern float Scr_GetFloat(int param);
extern void Scr_GetVector(int param, vec3_t out);
extern int Scr_GetNumParam(void);
extern void Scr_ParamError(int param, const char *msg);
extern void Scr_Error(const char *msg);
extern void Scr_ObjectError(const char *msg);
extern void Scr_Notify(gentity_t *ent, unsigned short name, int numArgs);
extern const char *va(const char *fmt, ...);
extern void Com_DPrintf(const char *fmt, ...);
extern void SV_LinkEntity(gentity_t *ent);
extern void SV_SetBrushModel(gentity_t *ent);
extern void G_DObjUpdate(gentity_t *ent);
extern qboolean G_SpawnFloat(const char *key, const char *defaultValue, float *out);
extern qboolean G_SpawnVector(const char *key, const char *defaultValue, vec3_t out);
extern void BG_EvaluateTrajectory(trajectory_t *tr, int time, vec3_t result);
extern float Vec3Normalize(vec3_t v);
extern float Vec3NormalizeTo(const vec3_t v, vec3_t out);
extern float AngleNormalize180(float angle);
extern float AngleNormalize360(float angle);
extern float AngleSubtract(float a, float b);

extern int __mh_execute_header;
extern gentity_t *g_entities;       /* imp_g_entities */
extern level_locals_t level;        /* imp_level */
extern byte *g_scr_data_ptr;        /* imp_scr_const */

void ScriptEntCmd_MoveTo(scr_entref_t entref);
void ScriptEntCmd_MoveX(scr_entref_t entref);
void ScriptEntCmd_MoveY(scr_entref_t entref);
void ScriptEntCmd_MoveZ(scr_entref_t entref);
void ScriptEntCmd_GravityMove(scr_entref_t entref);
void ScriptEntCmd_RotateTo(scr_entref_t entref);
void ScriptEntCmd_RotatePitch(scr_entref_t entref);
void ScriptEntCmd_RotateYaw(scr_entref_t entref);
void ScriptEntCmd_RotateRoll(scr_entref_t entref);
void ScriptEntCmd_RotateVelocity(scr_entref_t entref);
void ScriptEntCmd_Solid(scr_entref_t entref);
void ScriptEntCmd_NotSolid(scr_entref_t entref);

static const BuiltinMethodDef methods[] = {
    {"moveto", (BuiltinMethod)ScriptEntCmd_MoveTo, 0},
    {"movex", (BuiltinMethod)ScriptEntCmd_MoveX, 0},
    {"movey", (BuiltinMethod)ScriptEntCmd_MoveY, 0},
    {"movez", (BuiltinMethod)ScriptEntCmd_MoveZ, 0},
    {"movegravity", (BuiltinMethod)ScriptEntCmd_GravityMove, 0},
    {"rotateto", (BuiltinMethod)ScriptEntCmd_RotateTo, 0},
    {"rotatepitch", (BuiltinMethod)ScriptEntCmd_RotatePitch, 0},
    {"rotateyaw", (BuiltinMethod)ScriptEntCmd_RotateYaw, 0},
    {"rotateroll", (BuiltinMethod)ScriptEntCmd_RotateRoll, 0},
    {"rotatevelocity", (BuiltinMethod)ScriptEntCmd_RotateVelocity, 0},
    {"solid", (BuiltinMethod)ScriptEntCmd_Solid, 0},
    {"notsolid", (BuiltinMethod)ScriptEntCmd_NotSolid, 0},
};

/* Helper to get mover_ent_t from gentity - overlaid at offset 0x1A8 */
#define MOVER(ent) ((mover_ent_t *)((byte *)(ent) + 0x1A8))

static void VectorCopy(const vec3_t src, vec3_t dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

static void VectorScale(const vec3_t v, float scale, vec3_t out) {
    out[0] = v[0] * scale;
    out[1] = v[1] * scale;
    out[2] = v[2] * scale;
}

static void VectorMA(const vec3_t base, float scale, const vec3_t dir, vec3_t out) {
    out[0] = base[0] + scale * dir[0];
    out[1] = base[1] + scale * dir[1];
    out[2] = base[2] + scale * dir[2];
}

extern float sqrtf(float x);

static float VectorLength(const vec3_t v) {
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

static void VectorSubtract(const vec3_t a, const vec3_t b, vec3_t out) {
    out[0] = a[0] - b[0];
    out[1] = a[1] - b[1];
    out[2] = a[2] - b[2];
}

static gentity_t *GetScriptMoverEntity(scr_entref_t entref) {
    unsigned short entnum = entref.entnum;
    unsigned short classnum = entref.classnum;
    gentity_t *pSelf;

    if (classnum != 0) {
        Scr_ObjectError("not an entity");
        return NULL;
    }

    pSelf = &g_entities[entnum];

    if (pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x42) &&
        pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x44) &&
        pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x46)) {
        Scr_ObjectError(va("entity %i is not a script_brushmodel, script_model, or script_origin", entnum));
    }

    return pSelf;
}

void ScriptEntCmdGetCommandTimes(float *pfTotalTime, float *pfAccelTime, float *pfDecelTime);
void ScriptEntCmd_Solid(scr_entref_t entref);
void ScriptEntCmd_NotSolid(scr_entref_t entref);
BuiltinMethod ScriptEnt_GetMethod(const char **pName);
void InitScriptMover(gentity_t *pSelf);
void SP_script_origin(gentity_t *pSelf);
void SP_script_model(gentity_t *pSelf);
void SP_script_brushmodel(gentity_t *pSelf);
void ScriptEntCmd_GravityMove(scr_entref_t entref);
void ScriptEntCmd_RotateVelocity(scr_entref_t entref);
static qboolean ScriptMover_Updatemove(trajectory_t *pTr, float fSpeed, float fMidTime, float fDecelTime, const vec3_t vPos1, const vec3_t vPos2, const vec3_t vPos3);
void Reached_ScriptMover(gentity_t *pEnt);
static void ScriptMover_SetupMove(trajectory_t *pTr, const vec3_t vPos, const vec3_t vCurrPos, float fTotalTime, float fAccelTime, float fDecelTime, float *pfSpeed, float *pfMidTime, float *pfDecelTime, vec3_t vPos1, vec3_t vPos2, vec3_t vPos3);
void ScriptEnt_RotateAxis(scr_entref_t entref, int iAxis);
void ScriptEntCmd_RotateRoll(scr_entref_t entref);
void ScriptEntCmd_RotateYaw(scr_entref_t entref);
void ScriptEntCmd_RotatePitch(scr_entref_t entref);
void ScriptEnt_MoveAxis(scr_entref_t entref, int iAxis);
void ScriptEntCmd_MoveZ(scr_entref_t entref);
void ScriptEntCmd_MoveY(scr_entref_t entref);
void ScriptEntCmd_MoveX(scr_entref_t entref);
void ScriptEntCmd_RotateTo(scr_entref_t entref);
void ScriptEntCmd_MoveTo(scr_entref_t entref);

/* line 507 */
void ScriptEntCmdGetCommandTimes(float *pfTotalTime, float *pfAccelTime, float *pfDecelTime)
{
    int iNumParms;

    *pfTotalTime = Scr_GetFloat(1);
    if (!(*pfTotalTime > 0.0f)) {
        if (*pfTotalTime == 0.0f) {
            Scr_ParamError(1, "total time must be positive");
        }
    }

    iNumParms = Scr_GetNumParam();
    if (iNumParms > 2) {
        *pfAccelTime = Scr_GetFloat(2);
        if (0.0f > *pfAccelTime) {
            Scr_ParamError(2, "accel time must be nonnegative");
        }

        if (iNumParms > 3) {
            *pfDecelTime = Scr_GetFloat(3);
            if (0.0f > *pfDecelTime) {
                Scr_ParamError(3, "decel time must be nonnegative");
            }
        } else {
            *pfDecelTime = 0.0f;
        }
    } else {
        *pfAccelTime = 0.0f;
        *pfDecelTime = 0.0f;
    }

    if (*pfAccelTime + *pfDecelTime > *pfTotalTime) {
        Scr_Error("accel time plus decel time is greater than total time");
    }
}

/* line 753 */
void ScriptEntCmd_Solid(scr_entref_t entref)
{
    gentity_t *pSelf;
    unsigned short entnum = entref.entnum;
    unsigned short classnum = entref.classnum;

    if (classnum != 0) {
        Scr_ObjectError("not an entity");
        pSelf = (gentity_t *)0;
    } else {
        pSelf = &g_entities[entnum];
    }

    if (pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x42) &&
        pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x44) &&
        pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x46)) {
        Scr_ObjectError(va("entity %i is not a script_brushmodel, script_model, or script_origin", entnum));
    }

    if (pSelf->classname == *(unsigned short *)(g_scr_data_ptr + 0x46)) {
        /* script_origin - cannot use solid */
        Com_DPrintf("cannot use the solid/notsolid commands on a script_origin entity( number %i )\n", pSelf->s.number);
        return;
    }

    if (pSelf->classname == *(unsigned short *)(g_scr_data_ptr + 0x44)) {
        /* script_model */
        pSelf->r.contents = 0x2080;
    } else {
        /* script_brushmodel */
        pSelf->r.contents = 1;
        pSelf->s.eFlags &= ~1;
    }

    SV_LinkEntity(pSelf);
}

/* line 783 */
void ScriptEntCmd_NotSolid(scr_entref_t entref)
{
    gentity_t *pSelf;
    unsigned short entnum = entref.entnum;
    unsigned short classnum = entref.classnum;

    if (classnum != 0) {
        Scr_ObjectError("not an entity");
        pSelf = (gentity_t *)0;
    } else {
        pSelf = &g_entities[entnum];
    }

    if (pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x42) &&
        pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x44) &&
        pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x46)) {
        Scr_ObjectError(va("entity %i is not a script_brushmodel, script_model, or script_origin", entnum));
    }

    if (pSelf->classname == *(unsigned short *)(g_scr_data_ptr + 0x46)) {
        /* script_origin */
        Com_DPrintf("cannot use the solid/notsolid commands on a script_origin entity( number %i )\n", pSelf->s.number);
        return;
    }

    pSelf->r.contents = 0;
    if (pSelf->classname != *(unsigned short *)(g_scr_data_ptr + 0x44)) {
        /* script_brushmodel */
        pSelf->s.eFlags |= 1;
    }

    SV_LinkEntity(pSelf);
}

/* line 823 */
BuiltinMethod ScriptEnt_GetMethod(const char **pName)
{
    const char *name;
    int i;

    name = *pName;
    for (i = 0; i < 12; i++) {
        if (methods[i].actionString && strcmp(name, methods[i].actionString) == 0) {
            *pName = methods[i].actionString;
            return methods[i].actionFunc;
        }
    }
    return NULL;
}

/* line 390 */
void InitScriptMover(gentity_t *pSelf)
{
    float fLight;
    vec3_t vColor;
    qboolean bLightSet;
    int r, g, b, a;

    if (*(byte *)((byte *)&level + 0x1348)) {
        bLightSet = G_SpawnFloat("light", "100", &fLight);
        if (bLightSet | G_SpawnVector("color", "1 1 1", vColor)) {
            r = (int)(vColor[0] * 255.0f);
            if (r >= 0x100)
                r = 0xff;

            g = (int)(vColor[1] * 255.0f);
            if (g > 0xff)
                g = 0xff;

            b = (int)(vColor[2] * 255.0f);
            if (b > 0xff)
                b = 0xff;

            a = (int)(fLight * 0.25f);
            if (a > 0xff)
                a = 0xff;

            pSelf->s.constantLight = r | (g << 8) | (b << 16) | (a << 24);
        }
    }

    pSelf->handler = 5;
    pSelf->r.svFlags = 0;
    pSelf->s.eType = 6;

    VectorCopy(pSelf->r.currentOrigin, pSelf->s.pos.trBase);
    pSelf->s.pos.trType = TR_STATIONARY;

    VectorCopy(pSelf->r.currentAngles, pSelf->s.apos.trBase);
    pSelf->s.apos.trType = TR_STATIONARY;

    pSelf->flags |= 0x1000;
}

/* line 463 */
void SP_script_origin(gentity_t *pSelf)
{
    InitScriptMover(pSelf);
    pSelf->r.contents = 0;
    SV_LinkEntity(pSelf);

    if (pSelf->s.constantLight != 0) {
        pSelf->s.eFlags |= 0x20;
    } else {
        pSelf->r.svFlags |= 1;
    }
}

/* line 452 */
void SP_script_model(gentity_t *pSelf)
{
    G_DObjUpdate(pSelf);
    InitScriptMover(pSelf);
    pSelf->r.svFlags |= 4;
    pSelf->r.contents = 0x2080;
    SV_LinkEntity(pSelf);
}

/* line 442 */
void SP_script_brushmodel(gentity_t *pSelf)
{
    SV_SetBrushModel(pSelf);
    InitScriptMover(pSelf);
    pSelf->r.contents = 1;
    SV_LinkEntity(pSelf);
}

/* line 570 */
void ScriptEntCmd_GravityMove(scr_entref_t entref)
{
    gentity_t *pSelf;
    vec3_t vVel;
    float fTime;
    trajectory_t *pTr;

    pSelf = GetScriptMoverEntity(entref);

    Scr_GetVector(0, vVel);
    fTime = Scr_GetFloat(1);

    pTr = &pSelf->s.pos;
    pTr->trTime = level.time;
    pTr->trDuration = (int)(fTime * 1000.0f);

    VectorCopy(pSelf->r.currentOrigin, pTr->trBase);
    VectorCopy(vVel, pTr->trDelta);
    pSelf->s.pos.trType = TR_GRAVITY;

    BG_EvaluateTrajectory(pTr, level.time, pSelf->r.currentOrigin);
    SV_LinkEntity(pSelf);
}

/* Helper: setup velocity-based rotation/movement trajectory */
static void SetupVelocityTrajectory(gentity_t *pSelf, trajectory_t *pTr, const vec3_t vCurrPos,
    const vec3_t vSpeed, float fTotalTime, float fAccelTime, float fDecelTime,
    float *pfDecelTime, float *pfSpeed, float *pfMidTime,
    vec3_t to, vec3_t result, vec3_t endPos)
{
    float speed;

    if (pTr->trType != TR_STATIONARY) {
        BG_EvaluateTrajectory(pTr, level.time, vCurrPos);
    }

    if (fAccelTime == 0.0f && fDecelTime == 0.0f) {
        /* No acceleration, no deceleration - simple linear */
        pTr->trTime = level.time;
        pTr->trDuration = (int)(fTotalTime * 1000.0f);
        *pfMidTime = fTotalTime;
        *pfDecelTime = 0.0f;

        VectorCopy(vCurrPos, pTr->trBase);
        VectorCopy(vSpeed, pTr->trDelta);
        pTr->trType = TR_LINEAR_STOP;

        BG_EvaluateTrajectory(pTr, level.time, vCurrPos);
        BG_EvaluateTrajectory(pTr, level.time + pTr->trDuration, endPos);

        SV_LinkEntity(pSelf);
        return;
    }

    *pfMidTime = fTotalTime - fAccelTime - fDecelTime;
    *pfDecelTime = fDecelTime;
    speed = VectorLength(vSpeed);
    *pfSpeed = speed;

    if (fAccelTime == 0.0f) {
        /* No accel, just midTime and decel */
        VectorCopy(vCurrPos, to);

        if (*pfMidTime != 0.0f) {
            pTr->trTime = level.time;
            pTr->trDuration = (int)(*pfMidTime * 1000.0f);
            VectorCopy(vCurrPos, pTr->trBase);
            VectorCopy(vSpeed, pTr->trDelta);
            pTr->trType = TR_LINEAR_STOP;
        } else {
            pTr->trTime = level.time;
            pTr->trDuration = (int)(*pfDecelTime * 1000.0f);
            VectorCopy(vCurrPos, pTr->trBase);
            VectorCopy(vSpeed, pTr->trDelta);
            pTr->trType = TR_DECELERATE;
        }
    } else {
        /* Has accel phase */
        pTr->trTime = level.time;
        pTr->trDuration = (int)(fAccelTime * 1000.0f);
        VectorCopy(vCurrPos, pTr->trBase);
        VectorCopy(vSpeed, pTr->trDelta);
        pTr->trType = TR_ACCELERATE;

        BG_EvaluateTrajectory(pTr, level.time + pTr->trDuration, to);
    }

    /* Compute result = to + vSpeed * midTime */
    VectorMA(to, *pfMidTime, vSpeed, result);

    if (*pfDecelTime == 0.0f) {
        VectorCopy(result, endPos);
    } else {
        /* Setup decel trajectory to compute endPos */
        trajectory_t tr;
        tr.trType = TR_DECELERATE;
        tr.trTime = level.time;
        tr.trDuration = (int)(*pfDecelTime * 1000.0f);
        VectorCopy(result, tr.trBase);
        VectorCopy(vSpeed, tr.trDelta);
        BG_EvaluateTrajectory(&tr, level.time + tr.trDuration, endPos);
    }

    BG_EvaluateTrajectory(pTr, level.time, vCurrPos);
    SV_LinkEntity(pSelf);
}

/* line 732 */
void ScriptEntCmd_RotateVelocity(scr_entref_t entref)
{
    gentity_t *pSelf;
    vec3_t vSpeed;
    float fDecelTime, fAccelTime, fTotalTime;
    mover_ent_t *mover;
    trajectory_t *pTr;

    pSelf = GetScriptMoverEntity(entref);

    Scr_GetVector(0, vSpeed);
    ScriptEntCmdGetCommandTimes(&fTotalTime, &fAccelTime, &fDecelTime);

    mover = MOVER(pSelf);
    pTr = &pSelf->s.apos;

    SetupVelocityTrajectory(pSelf, pTr, pSelf->r.currentAngles, vSpeed,
        fTotalTime, fAccelTime, fDecelTime,
        &mover->aDecelTime, &mover->aSpeed, &mover->aMidTime,
        mover->apos1, mover->apos2, mover->apos3);
}

/* line 13 */
static qboolean ScriptMover_Updatemove(trajectory_t *pTr, float fSpeed, float fMidTime, float fDecelTime, const vec3_t vPos1, const vec3_t vPos2, const vec3_t vPos3)
{
    int trDuration;
    vec3_t vMove;
    float scale;

    trDuration = (int)(fMidTime * 1000.0f);

    if (pTr->trType == TR_ACCELERATE) {
        if (trDuration > 0) {
            /* Accel phase still running */
            pTr->trTime = level.time;
            pTr->trDuration = trDuration;
            VectorCopy(vPos1, pTr->trBase);

            VectorSubtract(vPos2, vPos1, vMove);
            scale = 1000.0f / (float)trDuration;
            VectorScale(vMove, scale, pTr->trDelta);
            pTr->trType = TR_LINEAR_STOP;
            return 0;
        }
        /* Fall through to TR_LINEAR_STOP/decel check */
    }

    if (pTr->trType == TR_LINEAR_STOP || pTr->trType == TR_ACCELERATE) {
        if (fDecelTime > 0.0f) {
            /* Start decel phase */
            pTr->trTime = level.time;
            pTr->trDuration = (int)(fDecelTime * 1000.0f);
            VectorCopy(vPos2, pTr->trBase);

            VectorSubtract(vPos3, vPos2, vMove);
            Vec3Normalize(vMove);
            VectorScale(vMove, fSpeed, vMove);
            VectorCopy(vMove, pTr->trDelta);
            pTr->trType = TR_DECELERATE;
            return 0;
        }
    }

    if (pTr->trType == TR_GRAVITY) {
        /* Evaluate current position, then stop */
        BG_EvaluateTrajectory(pTr, level.time, pTr->trBase);
    }

    /* Copy final destination */
    VectorCopy(vPos3, pTr->trBase);
    pTr->trTime = level.time;
    pTr->trType = TR_STATIONARY;
    return 1;
}

/* line 75 */
void Reached_ScriptMover(gentity_t *pEnt)
{
    qboolean bMoveFinished;
    mover_ent_t *mover = MOVER(pEnt);

    /* Check position trajectory */
    bMoveFinished = pEnt->s.pos.trType;
    if (bMoveFinished) {
        if (pEnt->s.pos.trTime + pEnt->s.pos.trDuration <= level.time) {
            bMoveFinished = ScriptMover_Updatemove(&pEnt->s.pos,
                mover->speed, mover->midTime, mover->decelTime,
                mover->pos1, mover->pos2, mover->pos3);

            BG_EvaluateTrajectory(&pEnt->s.pos, level.time, pEnt->r.currentOrigin);
            SV_LinkEntity(pEnt);

            if (bMoveFinished) {
                Scr_Notify(pEnt, *(unsigned short *)(g_scr_data_ptr + 0x28), 0);
            }
        }
    }

    /* Check angle trajectory */
    if (!pEnt->s.apos.trType)
        return;

    if (pEnt->s.apos.trTime + pEnt->s.apos.trDuration > level.time)
        return;

    bMoveFinished = ScriptMover_Updatemove(&pEnt->s.apos,
        mover->aSpeed, mover->aMidTime, mover->aDecelTime,
        mover->apos1, mover->apos2, mover->apos3);

    BG_EvaluateTrajectory(&pEnt->s.apos, level.time, pEnt->r.currentAngles);
    SV_LinkEntity(pEnt);

    if (!bMoveFinished)
        return;

    pEnt->r.currentAngles[0] = AngleNormalize180(pEnt->r.currentAngles[0]);
    pEnt->r.currentAngles[1] = AngleNormalize360(pEnt->r.currentAngles[1]);
    pEnt->r.currentAngles[2] = AngleNormalize180(pEnt->r.currentAngles[2]);

    Scr_Notify(pEnt, *(unsigned short *)(g_scr_data_ptr + 0x40), 0);
}

/* line 118 */
static void ScriptMover_SetupMove(trajectory_t *pTr, const vec3_t vPos, const vec3_t vCurrPos,
    float fTotalTime, float fAccelTime, float fDecelTime,
    float *pfSpeed, float *pfMidTime, float *pfDecelTime,
    vec3_t vPos1, vec3_t vPos2, vec3_t vPos3)
{
    vec3_t vMove;
    vec3_t vMaxSpeed;
    float speed;
    float scale;

    VectorSubtract(vPos, vCurrPos, vMove);

    if (pTr->trType != TR_STATIONARY) {
        BG_EvaluateTrajectory(pTr, level.time, (float *)vCurrPos);
        VectorSubtract(vPos, vCurrPos, vMove);
    }

    if (fAccelTime == 0.0f && fDecelTime == 0.0f) {
        /* Simple linear move */
        pTr->trTime = level.time;
        pTr->trDuration = (int)(fTotalTime * 1000.0f);
        *pfMidTime = fTotalTime;
        *pfDecelTime = 0.0f;
        VectorCopy(vPos, vPos3);

        VectorCopy(vCurrPos, pTr->trBase);
        scale = 1000.0f / (float)pTr->trDuration;
        VectorScale(vMove, scale, pTr->trDelta);
        pTr->trType = TR_LINEAR_STOP;

        BG_EvaluateTrajectory(pTr, level.time, (float *)vCurrPos);
    } else {
        /* Move with accel/decel */
        *pfMidTime = fTotalTime - fAccelTime - fDecelTime;
        *pfDecelTime = fDecelTime;

        /* speed = 2 * dist / (2*totalTime - accelTime - decelTime) */
        speed = VectorLength(vMove) * 2.0f / (fTotalTime * 2.0f - fAccelTime - fDecelTime);
        *pfSpeed = speed;

        Vec3NormalizeTo(vMove, vMaxSpeed);
        VectorScale(vMaxSpeed, speed, vMaxSpeed);

        if (fAccelTime == 0.0f) {
            /* No accel, copy current pos as start */
            VectorCopy(vCurrPos, vPos1);

            if (*pfMidTime != 0.0f) {
                /* Mid (linear) phase */
                pTr->trTime = level.time;
                pTr->trDuration = (int)(*pfMidTime * 1000.0f);
                VectorCopy(vCurrPos, pTr->trBase);

                /* Velocity = vMaxSpeed * midTime, scaled to duration */
                VectorScale(vMaxSpeed, *pfMidTime, vMove);
                scale = 1000.0f / (float)pTr->trDuration;
                VectorScale(vMove, scale, pTr->trDelta);
                pTr->trType = TR_LINEAR_STOP;
            } else {
                /* Just decel phase */
                pTr->trTime = level.time;
                pTr->trDuration = (int)(*pfDecelTime * 1000.0f);
                VectorCopy(vCurrPos, pTr->trBase);
                VectorCopy(vMaxSpeed, pTr->trDelta);
                pTr->trType = TR_DECELERATE;
            }
        } else {
            /* Accel phase */
            pTr->trTime = level.time;
            pTr->trDuration = (int)(fAccelTime * 1000.0f);
            VectorCopy(vCurrPos, pTr->trBase);
            VectorScale(vMaxSpeed, fAccelTime, vMove);
            scale = 1000.0f / (float)pTr->trDuration;
            VectorScale(vMove, scale, pTr->trDelta);
            pTr->trType = TR_ACCELERATE;

            BG_EvaluateTrajectory(pTr, level.time + pTr->trDuration, vPos1);
        }

        /* vPos2 = vPos1 + vMaxSpeed * midTime */
        VectorMA(vPos1, *pfMidTime, vMaxSpeed, vPos2);
        VectorCopy(vPos, vPos3);

        BG_EvaluateTrajectory(pTr, level.time, (float *)vCurrPos);
    }
}

/* line 673 */
void ScriptEnt_RotateAxis(scr_entref_t entref, int iAxis)
{
    gentity_t *pSelf;
    float fMove;
    float fDecelTime, fAccelTime, fTotalTime;
    vec3_t vRot;
    mover_ent_t *mover;

    pSelf = GetScriptMoverEntity(entref);

    fMove = Scr_GetFloat(0);
    ScriptEntCmdGetCommandTimes(&fTotalTime, &fAccelTime, &fDecelTime);

    VectorCopy(pSelf->r.currentAngles, vRot);
    vRot[iAxis] += fMove;

    mover = MOVER(pSelf);
    ScriptMover_SetupMove(&pSelf->s.apos, vRot, pSelf->r.currentAngles,
        fTotalTime, fAccelTime, fDecelTime,
        &mover->aSpeed, &mover->aMidTime, &mover->aDecelTime,
        mover->apos1, mover->apos2, mover->apos3);

    SV_LinkEntity(pSelf);
}

/* line 720 */
void ScriptEntCmd_RotateRoll(scr_entref_t entref)
{
    ScriptEnt_RotateAxis(entref, 2);
}

/* line 709 */
void ScriptEntCmd_RotateYaw(scr_entref_t entref)
{
    ScriptEnt_RotateAxis(entref, 1);
}

/* line 698 */
void ScriptEntCmd_RotatePitch(scr_entref_t entref)
{
    ScriptEnt_RotateAxis(entref, 0);
}

/* line 588 */
void ScriptEnt_MoveAxis(scr_entref_t entref, int iAxis)
{
    gentity_t *pSelf;
    float fMove;
    float fDecelTime, fAccelTime, fTotalTime;
    vec3_t vPos;
    mover_ent_t *mover;

    pSelf = GetScriptMoverEntity(entref);

    fMove = Scr_GetFloat(0);
    ScriptEntCmdGetCommandTimes(&fTotalTime, &fAccelTime, &fDecelTime);

    VectorCopy(pSelf->r.currentOrigin, vPos);
    vPos[iAxis] += fMove;

    mover = MOVER(pSelf);
    ScriptMover_SetupMove(&pSelf->s.pos, vPos, pSelf->r.currentOrigin,
        fTotalTime, fAccelTime, fDecelTime,
        &mover->speed, &mover->midTime, &mover->decelTime,
        mover->pos1, mover->pos2, mover->pos3);

    SV_LinkEntity(pSelf);
}

/* line 635 */
void ScriptEntCmd_MoveZ(scr_entref_t entref)
{
    ScriptEnt_MoveAxis(entref, 2);
}

/* line 624 */
void ScriptEntCmd_MoveY(scr_entref_t entref)
{
    ScriptEnt_MoveAxis(entref, 1);
}

/* line 613 */
void ScriptEntCmd_MoveX(scr_entref_t entref)
{
    ScriptEnt_MoveAxis(entref, 0);
}

/* line 646 */
void ScriptEntCmd_RotateTo(scr_entref_t entref)
{
    gentity_t *pSelf;
    vec3_t vDest;
    float fDecelTime, fAccelTime, fTotalTime;
    vec3_t vRot;
    mover_ent_t *mover;
    int i;

    pSelf = GetScriptMoverEntity(entref);

    Scr_GetVector(0, vDest);
    ScriptEntCmdGetCommandTimes(&fTotalTime, &fAccelTime, &fDecelTime);

    for (i = 1; i < 4; i++) {
        vRot[i - 1] = pSelf->r.currentAngles[i - 1] + AngleSubtract(vDest[i - 1], pSelf->r.currentAngles[i - 1]);
    }

    mover = MOVER(pSelf);
    ScriptMover_SetupMove(&pSelf->s.apos, vRot, pSelf->r.currentAngles,
        fTotalTime, fAccelTime, fDecelTime,
        &mover->aSpeed, &mover->aMidTime, &mover->aDecelTime,
        mover->apos1, mover->apos2, mover->apos3);

    SV_LinkEntity(pSelf);
}

/* line 550 */
void ScriptEntCmd_MoveTo(scr_entref_t entref)
{
    gentity_t *pSelf;
    vec3_t vPos;
    float fDecelTime, fAccelTime, fTotalTime;
    mover_ent_t *mover;

    pSelf = GetScriptMoverEntity(entref);

    Scr_GetVector(0, vPos);
    ScriptEntCmdGetCommandTimes(&fTotalTime, &fAccelTime, &fDecelTime);

    mover = MOVER(pSelf);
    ScriptMover_SetupMove(&pSelf->s.pos, vPos, pSelf->r.currentOrigin,
        fTotalTime, fAccelTime, fDecelTime,
        &mover->speed, &mover->midTime, &mover->decelTime,
        mover->pos1, mover->pos2, mover->pos3);

    SV_LinkEntity(pSelf);
}
