/* Converted to C from ASM: cg_players_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_players_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
extern float fabsf(float);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/universal/q_shared.h"
 */

extern void *Com_GetClientDObj(int clientNum, int localClientNum);
extern void BG_UpdatePlayerDObj(void *obj, entityState_t *es, byte *ci, int p4);
extern void BG_PlayerAnimation(void *obj, entityState_t *es, byte *ci);
extern void XAnimClearTreeGoalWeights(void *pAnimTree, unsigned short animIndex, int flags);
extern void XAnimSetCompleteGoalWeight(void *pAnimTree, unsigned short animIndex, float goalWeight, float goalTime, float rate, int p6, int p7, int p8);
extern void Com_Printf(const char *fmt, ...);
extern void AnglesToAxis(float *angles, float *axis);
extern void CG_AddCEntityToScene(byte *body, void *obj, centity_t *cent);
extern void CG_AddPlayerWeapon(byte *body, int unused, centity_t *cent, int flag);
extern int CG_DObjGetWorldTagPos(centity_t *cent, void *obj, unsigned short tag, float *origin);
extern void CL_DrawSprite(MaterialHandle material, byte *rgbaColor, float *origin, float radius, int time, int flags);
extern void XAnimClearTreeGoalWeightsStrict(void *pAnimTree, unsigned short animIndex, int flags);
extern void XAnimSetGoalWeight(void *pAnimTree, unsigned short animIndex, float goalWeight, float goalTime, float rate, int p6, int p7, int p8);
extern float XAnimGetWeight(void *pAnimTree, unsigned short animIndex);
extern int XAnimGetNumChildren(void *pXAnims, unsigned short animIndex);
extern unsigned short XAnimGetChildAt(void *pXAnims, unsigned short parentIndex, int childNum);
extern const char *XAnimGetAnimDebugName(void *pXAnims, unsigned short animIndex);
extern void XAnimCalcAbsDelta(void *pAnimTree, unsigned short animIndex, float *rot, float *trans);
extern void Com_Error(int level, const char *fmt, ...);
extern void *BG_GetWeaponDef(int weaponIndex);
extern float vectosignedyaw(float *axis);
extern float RotationToYaw(float *rot);
extern void YawToAxis(float yaw, float *axis);
extern void MatrixMultiply43(float *a, float *b, float *out);
extern void AxisToAngles(float *axis, float *angles);
extern void VectorAngleMultiply(float *trans, float yaw);
extern void CG_TraceCapsule(byte *trace, float *start, float *mins, float *maxs, float *end, int entityNum, int contentMask);
extern DObjAnimMat *CG_DObjGetLocalTagMatrix(const centity_t *cent, void *obj, unsigned int tagName);
extern const char *CL_GetConfigString(int index);
extern MaterialHandle CL_RegisterMaterial(const char *name, int flags);

extern byte *cgs_ptr;           /* imp_cg */
extern byte *cg_ptr;            /* imp_cgs */
extern byte cg_entities_ptr[];   /* imp_cg_entities */
extern byte *cg_tags_ptr;       /* imp_scr_const */
extern byte *cg_debug_ptr;      /* imp_cg_debugPosition */
extern byte *cg_sprite_ptr;     /* imp_cg_headIconMinScreenRadius */
extern byte *cg_sprite2_ptr;    /* imp_cg_voiceIconSize */
extern byte *cg_sprite3_ptr;    /* imp_cg_scriptIconSize */
extern byte *cg_sprite4_ptr;    /* imp_cg_constantSizeHeadIcons */
extern byte *cg_sprite5_ptr;    /* imp_cg_youInKillCamSize */
extern byte *cg_sprite6_ptr;    /* imp_cg_connectionIconSize */
extern byte *cg_pmove_mins;    /* imp_vec3_origin */

void CG_UpdatePlayerDObj(centity_t *cent);
void CG_ResetPlayerEntity(centity_t *cent);
static void CG_PlayerFloatSprite(centity_t *cent, MaterialHandle material, float additionalRadiusSize, int height, int fixedScreenSize);
void CG_PlayerSprites(centity_t *cent);
void CG_Player(centity_t *cent);
void CG_Corpse(centity_t *cent);

/* Client info stride: clientNum * 151 * 8 = clientNum * 1208 */
#define CI_STRIDE 1208

/* line 531 */
void CG_UpdatePlayerDObj(centity_t *cent)
{
    entityState_t *es;
    int clientNum;
    byte *cgs;
    byte *ci;
    void *obj;

    if (!cent->nextValid)
        return;

    es = &cent->nextState;
    clientNum = es->clientNum;

    cgs = *(byte **)cgs_ptr;
    ci = cgs + 0xe0914 + clientNum * CI_STRIDE;

    obj = Com_GetClientDObj(clientNum, cent->localClientNum);
    BG_UpdatePlayerDObj(obj, es, ci, 0);
}

/* line 552 */
void CG_ResetPlayerEntity(centity_t *cent)
{
    entityState_t *es;
    byte *cgs;
    byte *ciBase;
    byte *ci;
    int clientNum;
    int deadFlag;
    void *pAnimTree;

    es = &cent->nextState;
    cgs = *(byte **)cgs_ptr;
    clientNum = es->clientNum;

    ciBase = cgs + 0xe0900 + clientNum * CI_STRIDE;
    ci = ciBase + 0x14;

    deadFlag = es->eFlags & 0x20000;

    if (!deadFlag) {
        pAnimTree = *(void **)(ci + 0x4a4);

        /* Clear tree goal weights */
        XAnimClearTreeGoalWeights(pAnimTree, *(unsigned short *)(cgs + 0xe08e4), 0);

        /* Set complete goal weights for 3 anim indices */
        XAnimSetCompleteGoalWeight(pAnimTree, *(unsigned short *)(cgs + 0xe08d0), 0.0f, 0.0f, 1.0f, 0, 0, 0);
        XAnimSetCompleteGoalWeight(pAnimTree, *(unsigned short *)(cgs + 0xe08d2), 1.0f, 0.0f, 1.0f, 0, 0, 0);
        XAnimSetCompleteGoalWeight(pAnimTree, *(unsigned short *)(cgs + 0xe08d4), 0.0f, 0.0f, 1.0f, 0, 0, 0);

        /* Zero out lerpAnim ranges */
        memset(ciBase + 0x394, 0, 48);
        *(float *)(ci + 0x380) = *(float *)(ci + 0x3ec);
        *(int *)(ci + 0x384) = 0;
        *(int *)(ci + 0x388) = 0;
        *(int *)(ci + 0x38c) = 0;

        memset(ciBase + 0x3c4, 0, 48);
        *(float *)(ci + 0x3b0) = *(float *)(ci + 0x3ec);
        *(int *)(ci + 0x3b4) = 0;
        *(int *)(ci + 0x3b8) = *(int *)(ci + 0x3e8);
        *(int *)(ci + 0x3bc) = 0;
    }

    /* Debug print */
    {
        byte *debugDvar = *(byte **)cg_debug_ptr;
        debugDvar = *(byte **)debugDvar;
        if (*(byte *)(debugDvar + 8)) {
            Com_Printf("%i ResetPlayerEntity yaw=%f\n", cent->nextState.number, (double)*(float *)(ci + 0x3b0));
        }
    }
}

/* line 25 */
static void CG_PlayerFloatSprite(centity_t *cent, MaterialHandle material, float additionalRadiusSize, int height, int fixedScreenSize)
{
    byte *cgs;
    byte *snap;
    int clientNum;
    void *obj;
    vec3_t origin;
    byte rgbaColor[4];
    float radius;
    int drawFlags;
    int time;

    cgs = *(byte **)cgs_ptr;
    snap = *(byte **)(cgs + 0x24);

    /* Check if spectating/killcam */
    if (*(int *)(snap + 0x18) & 0xc00000) {
        clientNum = cent->nextState.number;
        if (clientNum == *(int *)(snap + 0xd8)) {
            if (!*(int *)(cgs + 0x25bc0))
                return;
        }
    } else {
        clientNum = cent->nextState.number;
    }

    /* Try to get head tag position */
    obj = Com_GetClientDObj(clientNum, cent->localClientNum);
    if (obj) {
        unsigned short tag = *(unsigned short *)(cg_tags_ptr + 0x96);
        if (CG_DObjGetWorldTagPos(cent, obj, tag, origin)) {
            origin[2] += (float)height + 21.0f;
            goto draw;
        }
    }

    /* Fallback: use lerpOrigin with larger offset */
    origin[0] = cent->lerpOrigin[0];
    origin[1] = cent->lerpOrigin[1];
    origin[2] = cent->lerpOrigin[2];
    origin[2] += (float)height + 82.0f;

draw:
    if (fixedScreenSize) {
        radius = (additionalRadiusSize + 10.0f) * 0.0043f;
        drawFlags = 0x3000;
    } else {
        radius = additionalRadiusSize + 10.0f;
        drawFlags = 0;
    }

    rgbaColor[0] = 0xFF;
    rgbaColor[1] = 0xFF;
    rgbaColor[2] = 0xFF;
    rgbaColor[3] = 0xFF;

    time = *(int *)(*(byte **)cg_sprite_ptr + 8);
    CL_DrawSprite(material, rgbaColor, origin, radius, time, drawFlags);
}

/* line 75 */
void CG_PlayerSprites(centity_t *cent)
{
    byte *cgs;
    byte *snap;
    byte *ci;
    int iTeam;
    int localTeam;
    float additionalRadiusSize;
    int eFlags;
    int height;
    MaterialHandle material;

    cgs = *(byte **)cgs_ptr;

    /* Get target player's client info */
    ci = cgs + 0xe0914 + cent->nextState.clientNum * CI_STRIDE;
    if (!*(int *)ci)
        return;
    iTeam = *(int *)(ci + 0x2c);

    /* Get local player's client info */
    snap = *(byte **)(cgs + 0x24);
    ci = cgs + 0xe0914 + *(int *)(snap + 0xd8) * CI_STRIDE;
    if (!*(int *)ci)
        return;
    localTeam = *(int *)(ci + 0x2c);

    /* Check headicon */
    {
        int headicon = *(int *)((byte *)cent + 0x184);
        if (headicon) {
            int headiconTeam = *(int *)((byte *)cent + 0x188);
            if (!headiconTeam || localTeam == 3 || localTeam == headiconTeam) {
                const char *str = CL_GetConfigString(headicon + 30);
                material = CL_RegisterMaterial(str, 7);
                if (material) {
                    float spriteSize = *(float *)(*(byte **)cg_sprite3_ptr + 8);
                    int fixedScreen = (int)*(byte *)(*(byte **)cg_sprite4_ptr + 8);
                    CG_PlayerFloatSprite(cent, material, spriteSize, 0, fixedScreen);
                    additionalRadiusSize = 16.0f + *(float *)(*(byte **)cg_sprite3_ptr + 8);
                    goto check_local_player;
                }
            }
        }
    }

    additionalRadiusSize = 0.0f;

check_local_player:
    /* Check if this is the local player */
    cgs = *(byte **)cgs_ptr;
    if (cent->nextState.number == *(int *)(cgs + 4)) {
        if (*(int *)(cgs + 0x2cd14)) {
            /* Show "you" indicator */
            height = (int)additionalRadiusSize;
            material = *(MaterialHandle *)(*(byte **)cg_ptr + 0xba38);
            CG_PlayerFloatSprite(cent, material,
                *(float *)(*(byte **)cg_sprite5_ptr + 8), height, 1);
            return;
        }
    }

    /* Check talking flag (EF_TALK = 0x80) */
    eFlags = cent->nextState.eFlags;
    if (eFlags & 0x80) {
        height = (int)additionalRadiusSize;
        material = *(MaterialHandle *)(*(byte **)cg_ptr + 0xba34);
        CG_PlayerFloatSprite(cent, material,
            *(float *)(*(byte **)cg_sprite6_ptr + 8), height, 0);
        return;
    }

    /* Must be same team or spectator to show team sprites */
    if (iTeam != localTeam && localTeam != 3)
        return;

    /* Check headicon timer */
    if (*(int *)((byte *)cent + 0x218) > *(int *)(cgs + 0x25bb0)) {
        height = (int)additionalRadiusSize;
        material = *(MaterialHandle *)((byte *)cent + 0x214);
        CG_PlayerFloatSprite(cent, material,
            *(float *)(*(byte **)cg_sprite2_ptr + 8), height, 0);
        return;
    }

    /* Check EF_YOURTEAMMATE flag */
    if (!(eFlags & 0x200000))
        return;

    /* Show friendly indicator */
    additionalRadiusSize -= 5.0f;
    height = (int)additionalRadiusSize;
    material = *(MaterialHandle *)(*(byte **)cg_ptr + 0xba30);
    CG_PlayerFloatSprite(cent, material,
        *(float *)(*(byte **)cg_sprite2_ptr + 8), height, 0);
}

/* line 378 */
void CG_Player(centity_t *cent)
{
    entityState_t *es;
    int iClientNum;
    void *obj;
    byte body[0x74];
    byte *cgs;

    es = &cent->nextState;

    /* line 390: EF_NODRAW */
    if (es->eFlags & 0x20)
        return;

    /* line 393: EF_DEAD */
    if (es->eFlags & 0x20000)
        return;

    /* line 396: spectator/killcam check */
    cgs = *(byte **)cgs_ptr;
    {
        byte *snap = *(byte **)(cgs + 0x24);
        if (*(int *)(snap + 0x18) & 0xc00000) {
            if (es->number == *(int *)(snap + 0xd8)) {
                if (!*(int *)(cgs + 0x25bc0))
                    return;
            }
        }
    }

    /* line 402 */
    iClientNum = es->clientNum;

    /* line 405 */
    obj = Com_GetClientDObj(es->number, cent->localClientNum);
    if (!obj)
        return;

    /* line 409: init body refEntity */
    memset(body, 0, 0x74);
    body[0x58] = 0xFF;
    body[0x59] = 0xFF;
    body[0x5A] = 0xFF;
    body[0x5B] = 0xFF;

    /* line 419: compute CI and call BG_PlayerAnimation */
    {
        byte *ci = cgs + 0xe0914 + iClientNum * CI_STRIDE;
        BG_PlayerAnimation(obj, es, ci);
    }

    /* line 421: turret check (eFlags & EF_TURRET) */
    if (es->eFlags & 0x300) {
        int turretEntNum = es->otherEntityNum;

        if (turretEntNum <= 0x3f) {
            /* Small entity: use cent directly */
            goto render;
        }
        if (turretEntNum == 0x3ff) {
            goto render;
        }

        /* Turret animation processing */
        {
            byte *ciBase = cgs + 0xe0900 + iClientNum * CI_STRIDE;
            byte *turretCi = ciBase + 0x14;
            byte *pLerpAnim;
            int animValue;
            byte *animPtr;
            centity_t *pTurretCEnt;
            void *turretObj;
            DObjAnimMat *tagMat;
            void *weapDef;
            void *pAnimTree;
            void *pXAnims;
            unsigned short baseAnim;
            unsigned short heightAnim;
            unsigned short leafAnim1;
            unsigned short leafAnim2;
            int numVertChildren, numHorChildren;
            int i, iPrevBlend, iHorChild;
            float localYaw, fDelta, fPrevTransZ, fPrevBlend;
            float prevHeight, fHeightRatio, tagHeight, frac;
            float rot[4], trans[3];
            float tagAxis[9];
            float turretAxis4x3[12];
            float localAxis4x3[12];
            float finalAxis4x3[12];
            int frameDuration;
            int broke;

            /* line 203: check turretCi has valid data */
            if (!*(int *)turretCi)
                goto render;

            pLerpAnim = ciBase + 0x394;

            /* line 208: check pLerpAnim fields */
            animValue = *(int *)(pLerpAnim + 0x10);
            if (!animValue)
                goto render;

            animPtr = *(byte **)(pLerpAnim + 0x14);
            if (!animPtr)
                goto render;

            if (!(animPtr[0x50] & 4))
                goto render;

            /* line 211: get turret centity */
            pTurretCEnt = (centity_t *)(*(byte **)cg_entities_ptr + turretEntNum * sizeof(centity_t));

            /* line 212 */
            if (!pTurretCEnt->nextValid)
                goto render;

            /* line 215: get turret DObj */
            turretObj = Com_GetClientDObj(pTurretCEnt->nextState.number, pTurretCEnt->localClientNum);
            if (!turretObj)
                goto render;

            /* line 219: get tag matrix */
            tagMat = CG_DObjGetLocalTagMatrix(pTurretCEnt, turretObj,
                (unsigned int)*(unsigned short *)(cg_tags_ptr + 0x98));
            if (!tagMat) {
                /* line 222 */
                Com_Printf("CG_Player: turret tag not found\n");
                goto render;
            }

            /* line 226: check frame duration */
            frameDuration = *(int *)(cgs + 0x25bac);
            if (!frameDuration)
                goto render;

            /* line 230: get weapon def */
            weapDef = BG_GetWeaponDef(pTurretCEnt->nextState.weapon);

            /* line 234 */
            pAnimTree = *(void **)(turretCi + 0x4a4);
            pXAnims = *(void **)(cgs + 0xe08cc);
            baseAnim = (unsigned short)(animValue & ~0x200);

            /* line 306: quaternion to 3x3 rotation matrix */
            {
                float s = tagMat->transWeight;
                float sx = s * tagMat->quat[0];
                float sy = s * tagMat->quat[1];
                float sz = s * tagMat->quat[2];
                float xx = sx * tagMat->quat[0];
                float xy = sx * tagMat->quat[1];
                float xz = sx * tagMat->quat[2];
                float xw = sx * tagMat->quat[3];
                float yy = sy * tagMat->quat[1];
                float yz = sy * tagMat->quat[2];
                float yw = sy * tagMat->quat[3];
                float zz = sz * tagMat->quat[2];
                float zw = sz * tagMat->quat[3];

                tagAxis[0] = 1.0f - (yy + zz);
                tagAxis[1] = xy + zw;
                tagAxis[2] = xz - yw;
                tagAxis[3] = xy - zw;
                tagAxis[4] = 1.0f - (xx + zz);
                tagAxis[5] = xw + yz;
                tagAxis[6] = xz + yw;
                tagAxis[7] = yz - xw;
                tagAxis[8] = 1.0f - (xx + yy);
            }

            /* line 239: get local yaw from tag axis */
            localYaw = vectosignedyaw(tagAxis);

            /* line 241: build turret 4x3 matrix */
            AnglesToAxis(pTurretCEnt->lerpAngles, turretAxis4x3);
            turretAxis4x3[9]  = pTurretCEnt->lerpOrigin[0];
            turretAxis4x3[10] = pTurretCEnt->lerpOrigin[1];
            turretAxis4x3[11] = pTurretCEnt->lerpOrigin[2];

            /* line 304: compute tag height */
            tagHeight = (cent->lerpOrigin[0] - turretAxis4x3[9])  * turretAxis4x3[6]
                      + (cent->lerpOrigin[1] - turretAxis4x3[10]) * turretAxis4x3[7]
                      + (cent->lerpOrigin[2] - turretAxis4x3[11]) * turretAxis4x3[8];

            /* line 246 */
            fDelta = tagHeight - tagMat->trans[2];

            /* line 248: clear weights */
            XAnimClearTreeGoalWeightsStrict(pAnimTree, baseAnim, 0);

            /* line 250: get vertical children count */
            numVertChildren = XAnimGetNumChildren(pXAnims, baseAnim);
            if (!numVertChildren)
                Com_Error(1, "Player anim '%s' has no children",
                    XAnimGetAnimDebugName(pXAnims, baseAnim));

            /* line 256: loop init */
            fPrevBlend = 0.0f;
            prevHeight = 0.0f;
            iPrevBlend = 0;
            leafAnim2 = 0;
            leafAnim1 = 0;
            broke = 0;
            frac = 0.0f;

            /* line 260: vertical children loop */
            for (i = 0; i < numVertChildren; i++) {
                float rawBlend;

                /* line 262 */
                heightAnim = XAnimGetChildAt(pXAnims, baseAnim, i);

                /* line 263: set temp weight = 1.0 */
                XAnimSetGoalWeight(pAnimTree, heightAnim, 1.0f, 1.0f, 1.0f, 0, 0, 0);

                /* line 265 */
                numHorChildren = XAnimGetNumChildren(pXAnims, heightAnim);
                if (!numHorChildren)
                    Com_Error(1, "Player anim '%s' has no children",
                        XAnimGetAnimDebugName(pXAnims, heightAnim));

                /* line 269: compute horizontal blend */
                rawBlend = (float)numHorChildren * 0.5f
                    - localYaw / *(float *)((byte *)weapDef + 0x564);

                /* line 271: clamp */
                if (rawBlend < 0.0f) {
                    iHorChild = 0;
                    rawBlend = 0.0f;
                } else if (rawBlend >= (float)(numHorChildren - 1)) {
                    iHorChild = numHorChildren - 1;
                    rawBlend = (float)iHorChild;
                } else {
                    iHorChild = (int)rawBlend;
                }

                /* line 277 */
                frac = rawBlend - (float)iHorChild;

                /* line 279 */
                leafAnim1 = XAnimGetChildAt(pXAnims, heightAnim, iHorChild);
                XAnimSetGoalWeight(pAnimTree, leafAnim1, 1.0f - frac,
                    1.0f, 1.0f, 0, 0, 0);

                /* line 282 */
                if (frac != 0.0f) {
                    leafAnim2 = XAnimGetChildAt(pXAnims, heightAnim, iHorChild + 1);
                    XAnimSetGoalWeight(pAnimTree, leafAnim2, frac,
                        1.0f, 1.0f, 0, 0, 0);
                }

                /* line 288 */
                XAnimCalcAbsDelta(pAnimTree, heightAnim, rot, trans);

                /* line 289: check height */
                if (trans[2] >= fDelta) {
                    fPrevTransZ = prevHeight;
                    broke = 1;
                    break;
                }

                /* line 296: save state for next iteration */
                prevHeight = trans[2];
                fPrevBlend = frac;
                iPrevBlend = iHorChild;
            }

            if (!broke) {
                /* fell through: save last iteration's state */
                fPrevBlend = frac;
                iPrevBlend = iHorChild;
                fPrevTransZ = prevHeight;
            }

            /* line 299: clear and set final weights */
            XAnimClearTreeGoalWeightsStrict(pAnimTree, baseAnim, 0);

            /* line 301: leafAnim1 with goalTime */
            {
                float cw = XAnimGetWeight(pAnimTree, leafAnim1);
                float tw = 1.0f - frac;
                float spd = fabsf(cw - tw) * 1000.0f / (float)frameDuration;
                float gt = 0.0f;
                if (spd > 0.0f)
                    gt = 1.0f / spd;
                XAnimSetGoalWeight(pAnimTree, leafAnim1, tw, gt, 1.0f, 0, 0, 0);
            }

            /* line 304: leafAnim2 if needed */
            if (frac != 0.0f) {
                float cw = XAnimGetWeight(pAnimTree, leafAnim2);
                float spd = fabsf(cw - frac) * 1000.0f / (float)frameDuration;
                float gt = 0.0f;
                if (spd > 0.0f)
                    gt = 1.0f / spd;
                XAnimSetGoalWeight(pAnimTree, leafAnim2, frac, gt, 1.0f, 0, 0, 0);
            }

            /* line 310: height interpolation */
            if (i == 0 || i == numVertChildren) {
                /* line 313: boundary - single height level */
                float cw = XAnimGetWeight(pAnimTree, heightAnim);
                float spd = fabsf(cw - 1.0f) * 1000.0f / (float)frameDuration;
                float gt = 0.0f;
                if (spd > 0.0f)
                    gt = 1.0f / spd;
                XAnimSetGoalWeight(pAnimTree, heightAnim, 1.0f, gt, 1.0f, 0, 0, 0);
            } else {
                /* line 320: interpolate between two height levels */
                unsigned short prevHeightAnim;

                fHeightRatio = (fDelta - fPrevTransZ) / (trans[2] - fPrevTransZ);

                /* line 322: current height level */
                {
                    float cw = XAnimGetWeight(pAnimTree, heightAnim);
                    float spd = fabsf(cw - fHeightRatio) * 1000.0f / (float)frameDuration;
                    float gt = 0.0f;
                    if (spd > 0.0f)
                        gt = 1.0f / spd;
                    XAnimSetGoalWeight(pAnimTree, heightAnim, fHeightRatio, gt, 1.0f, 0, 0, 0);
                }

                /* line 325: previous height level */
                prevHeightAnim = XAnimGetChildAt(pXAnims, baseAnim, i - 1);

                /* line 327 */
                {
                    float gw = 1.0f - fHeightRatio;
                    float cw = XAnimGetWeight(pAnimTree, prevHeightAnim);
                    float spd = fabsf(cw - gw) * 1000.0f / (float)frameDuration;
                    float gt = 0.0f;
                    if (spd > 0.0f)
                        gt = 1.0f / spd;
                    XAnimSetGoalWeight(pAnimTree, prevHeightAnim, gw, gt, 1.0f, 0, 0, 0);
                }

                /* line 330: prev horizontal blend */
                {
                    unsigned short prevLeaf = XAnimGetChildAt(pXAnims, prevHeightAnim, iPrevBlend);
                    float gw = 1.0f - fPrevBlend;
                    float cw = XAnimGetWeight(pAnimTree, prevLeaf);
                    float spd = fabsf(cw - gw) * 1000.0f / (float)frameDuration;
                    float gt = 0.0f;
                    if (spd > 0.0f)
                        gt = 1.0f / spd;
                    XAnimSetGoalWeight(pAnimTree, prevLeaf, gw, gt, 1.0f, 0, 0, 0);

                    /* line 334 */
                    if (fPrevBlend != 0.0f) {
                        unsigned short prevLeaf2 = XAnimGetChildAt(pXAnims, prevHeightAnim, iPrevBlend + 1);
                        cw = XAnimGetWeight(pAnimTree, prevLeaf2);
                        spd = fabsf(cw - fPrevBlend) * 1000.0f / (float)frameDuration;
                        gt = 0.0f;
                        if (spd > 0.0f)
                            gt = 1.0f / spd;
                        XAnimSetGoalWeight(pAnimTree, prevLeaf2, fPrevBlend, gt, 1.0f, 0, 0, 0);
                    }
                }
            }

            /* line 342: calc final abs delta */
            XAnimCalcAbsDelta(pAnimTree, baseAnim, rot, trans);

            /* line 343: rotate trans by localYaw */
            VectorAngleMultiply(trans, localYaw);

            /* line 344: build local 4x3 matrix */
            {
                float rotYaw = RotationToYaw(rot);
                YawToAxis(localYaw + rotYaw, localAxis4x3);
            }
            localAxis4x3[9]  = trans[0] + tagMat->trans[0];
            localAxis4x3[10] = trans[1] + tagMat->trans[1];
            localAxis4x3[11] = tagHeight;

            /* line 351: multiply with turret matrix */
            MatrixMultiply43(localAxis4x3, turretAxis4x3, finalAxis4x3);

            /* line 353: extract angles and position */
            AxisToAngles(finalAxis4x3, cent->lerpAngles);
            cent->lerpOrigin[0] = finalAxis4x3[9];
            cent->lerpOrigin[1] = finalAxis4x3[10];
            cent->lerpOrigin[2] = finalAxis4x3[11];

            /* line 362: trace capsule to clamp Z */
            {
                float start[3], end[3];
                byte trace[0x44];
                float *traceBounds = (float *)cg_pmove_mins;

                start[0] = cent->lerpOrigin[0];
                start[1] = cent->lerpOrigin[1];
                start[2] = pTurretCEnt->lerpOrigin[2];

                end[0] = cent->lerpOrigin[0];
                end[1] = cent->lerpOrigin[1];
                end[2] = cent->lerpOrigin[2];

                CG_TraceCapsule(trace, start, traceBounds, traceBounds,
                    end, cent->nextState.number, 0x2810011);

                /* line 363 */
                if (*(float *)trace < 1.0f) {
                    cent->lerpOrigin[2] = start[2]
                        + (end[2] - start[2]) * (*(float *)trace);
                }
            }
        }
    }

render:
    /* line 424 */
    AnglesToAxis(cent->lerpAngles, (float *)(body + 0x14));

    /* body.origin = lerpOrigin */
    *(float *)(body + 0x3C) = cent->lerpOrigin[0];
    *(float *)(body + 0x40) = cent->lerpOrigin[1];
    *(float *)(body + 0x44) = cent->lerpOrigin[2];

    /* body.oldOrigin */
    *(float *)(body + 0x08) = cent->lerpOrigin[0];
    *(float *)(body + 0x0C) = cent->lerpOrigin[1];

    /* line 433 */
    {
        float z = cent->lerpOrigin[2] + es->fTorsoPitch;

        /* line 435: stance height */
        if (es->eFlags & 8)
            z += 12.0f;
        else if (es->eFlags & 4)
            z += 20.0f;
        else
            z += 32.0f;

        *(float *)(body + 0x10) = z;
    }

    /* line 442 */
    *(int *)(body + 0x00) = 0;
    /* line 444 */
    *(int *)(body + 0x04) = 0x80;

    /* line 446 */
    CG_AddCEntityToScene(body, obj, cent);

    /* line 449 */
    if (es->eFlags & 0x20000)
        return;

    /* line 451 */
    CG_AddPlayerWeapon(body, 0, cent, 1);
}


/* line 466 */
void CG_Corpse(centity_t *cent)
{
    entityState_t *es;
    byte *cg;
    byte *ci;
    int clientNum;
    void *obj;
    byte body[0x74];
    float z;

    es = &cent->nextState;

    /* Check EF_NODRAW */
    if (es->eFlags & 0x20)
        return;

    clientNum = cent->nextState.number;

    cg = *(byte **)cg_ptr;
    ci = cg - 0x6bec + clientNum * CI_STRIDE;

    /* Update player DObj */
    obj = Com_GetClientDObj(clientNum, cent->localClientNum);
    BG_UpdatePlayerDObj(obj, es, ci, 0);

    /* Get DObj again */
    obj = Com_GetClientDObj(cent->nextState.number, cent->localClientNum);
    if (!obj)
        return;

    /* Set up body refEntity */
    memset(body, 0, 0x74);

    /* body.materialRGBA = white */
    body[0x58] = 0xFF;
    body[0x59] = 0xFF;
    body[0x5A] = 0xFF;
    body[0x5B] = 0xFF;

    /* BG_PlayerAnimation */
    BG_PlayerAnimation(obj, es, ci);

    /* AnglesToAxis(lerpAngles, body.axis) */
    AnglesToAxis(cent->lerpAngles, (float *)(body + 0x14));

    /* body.origin = lerpOrigin */
    *(float *)(body + 0x3C) = cent->lerpOrigin[0];
    *(float *)(body + 0x40) = cent->lerpOrigin[1];
    *(float *)(body + 0x44) = cent->lerpOrigin[2];

    /* body.oldOrigin[0,1] = lerpOrigin[0,1] */
    *(float *)(body + 0x08) = cent->lerpOrigin[0];
    *(float *)(body + 0x0C) = cent->lerpOrigin[1];

    /* body.oldOrigin[2] = lerpOrigin[2] + fTorsoPitch + stance height */
    z = cent->lerpOrigin[2] + es->fTorsoPitch;

    if (es->eFlags & 8) {
        z += 12.0f;  /* crouching */
    } else if (es->eFlags & 4) {
        z += 20.0f;  /* prone */
    } else {
        z += 32.0f;  /* standing */
    }
    *(float *)(body + 0x10) = z;

    /* body.reType = 0 */
    *(int *)(body + 0x00) = 0;
    /* body.renderFxFlags = RF_SHADOW */
    *(int *)(body + 0x04) = 0x80;

    /* Add to scene */
    CG_AddCEntityToScene(body, obj, cent);
}
