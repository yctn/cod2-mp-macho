/* ASM dump from: cg_ents_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_ents_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern void DObjUpdateClientInfo(struct DObj_s *obj, float timescale);
extern void * MT_Alloc(int size, int type);
extern void *BG_GetWeaponDef(int weapIndex);
extern struct XAnim_s *XAnimCreateAnims(const char *debugName, int size, void *Alloc);
extern void XAnimBlend(struct XAnim_s *anims, unsigned int animIndex, const char *name, unsigned int children, unsigned int num, unsigned int flags);
extern void XAnimPrecache(const char *name, void *Alloc);
extern void XAnimCreate(struct XAnim_s *anims, unsigned int animIndex, const char *name);
extern void *Com_GetClientDObj(int entityNum, int localClientNum);
extern float AngleSubtract(float a1, float a2);
extern float LerpAngle(float from, float to, float frac);
extern void DObjSetControlTagAngles(void *obj, int *partBits, unsigned int tagName, float *angles);
extern void *DObjGetTree(void *obj);
extern void XAnimSetCompleteGoalWeightKnobAll(void *tree, int animIndex, float goalWeight, float goalTime, float rate, int notifyType, int notifyClient);

extern const int boxVerts[24][3]; /* boxVerts */

struct XAnim_s * CG_GetMG42Anims(centity_t *cent);
static long unsigned int CG_mg42_DoControllers(const centity_t *cent, int *partBits);
long unsigned int CG_SetFrameInterpolation(void);
long unsigned int CG_ProcessClientNoteTracks(int clientNum);
long unsigned int CG_DObjUpdateInfo(struct DObj_s *obj);
long unsigned int CG_SoundBlend(centity_t *cent);
static long unsigned int * CG_AllocAnimTree(int size);
long unsigned int CG_UsedDObjCalcPose(const centity_t *cent);
long unsigned int CG_CullIn(const centity_t *cent);
long unsigned int CG_AddCEntityToScene(const GfxEntity *ent, const struct DObj_s *obj, const centity_t *cent);
static long unsigned int CG_InterpolateEntityPosition(void);
qboolean CG_DObjGetViewModelTagPos(struct DObj_s *obj, unsigned int tagName, vec_t *pos);
long unsigned int CG_DObjCalcBoneGeneric(int handle, int localClientNum, int boneIndex);
long unsigned int CG_AdjustPositionForMover(const vec_t *in, int moverNum, int fromTime, int toTime, vec_t *out, vec_t *outDeltaAngles);
long unsigned int CG_CalcEntityLerpPositions(centity_t *cent);
long unsigned int CG_EntityEffects(centity_t *cent);
static struct DObj_s * CG_PreProcess_GetDObj(int iEntType);
long unsigned int CG_DObjCalcPose(const centity_t *cent, const struct DObj_s *obj, int *partBits);
long unsigned int CG_DObjCalcBone(const centity_t *cent, struct DObj_s *obj, int boneIndex);
DObjAnimMat * CG_DObjGetLocalTagMatrix(const centity_t *cent, struct DObj_s *obj, unsigned int tagName);
qboolean CG_DObjGetWorldTagPos(const centity_t *cent, struct DObj_s *obj, unsigned int tagName, vec_t *pos);
long unsigned int CG_General(centity_t *cent);
long unsigned int CG_Item(centity_t *cent);
long unsigned int CG_Missile(centity_t *cent);
long unsigned int CG_ScriptMover(centity_t *cent);
long unsigned int CG_ProcessEntity(centity_t *cent);
long unsigned int CG_AddPacketEntities(void);

/* line 253 */
struct XAnim_s * CG_GetMG42Anims(centity_t *cent)
{
    WeaponDef *weapDef;
    struct XAnim_s *pAnims;

    /* line 259: get weapon def from cent->currentState.weapon (offset 0x1b8) */
    weapDef = BG_GetWeaponDef(cent->nextState.weapon);

    /* line 261: create anim tree with 3 slots, name "MG42" */
    pAnims = XAnimCreateAnims((const char *)"MG42", 3, (void *)*(int *)&imp_Hunk_AllocXAnimClient);

    /* line 265: blend root node: index 0, name "root", children 1, num 2, flags 0 */
    XAnimBlend(pAnims, 0, (const char *)"root", 1, 2, 0);

    /* line 269: precache first anim (szXAnims[1]) */
    XAnimPrecache(weapDef->szXAnims[1], (void *)*(int *)&imp_Hunk_AllocXAnimPrecache);

    /* line 271: create anim at index 1 */
    XAnimCreate(pAnims, 1, weapDef->szXAnims[1]);

    /* line 275: precache second anim (szXAnims[3]) */
    XAnimPrecache(weapDef->szXAnims[3], (void *)*(int *)&imp_Hunk_AllocXAnimPrecache);

    /* line 277: create anim at index 2 */
    XAnimCreate(pAnims, 2, weapDef->szXAnims[3]);

    /* line 280 */
    return pAnims;
}

/* line 288 */
static long unsigned int CG_mg42_DoControllers(const centity_t *cent, int *partBits)
{
    cg_t *cg_s;
    playerState_t *ps;
    const entityState_t *s1;
    void *obj;
    float angles[3];
    const scr_const_t *scr;
    struct XAnim_s *tree;
    int animIndex;

    s1 = (const entityState_t *)((const byte *)cent + 0xf0);

    /* line 301 */
    cg_s = *(cg_t **)imp_cg;
    ps = (playerState_t *)((byte *)cg_s + 0x25bc4);

    /* line 303: get DObj for this entity */
    obj = (byte *)Com_GetClientDObj(s1->number, cent->localClientNum);

    /* line 306: check if player state flags & 0x300 set */
    if ((ps->eFlags & 0x300) && ps->viewlocked_entNum == s1->number) {
        /* line 308: player is using this MG42 - use AngleSubtract from viewangles */
        angles[0] = AngleSubtract(cg_s->refdefViewAngles[0], cent->lerpAngles[0]);
        angles[1] = AngleSubtract(cg_s->refdefViewAngles[1], cent->lerpAngles[1]);
        angles[2] = 0.0f;
    } else {
        /* line 314: not our MG42 - lerp angles from entity state */
        angles[0] = LerpAngle(s1->angles2[0], s1->angles2[0], cg_s->frameInterpolation);
        angles[1] = LerpAngle(s1->angles2[1], s1->angles2[1], cg_s->frameInterpolation);
        angles[2] = 0.0f;
    }

    /* line 319: set tag_turret control tag angles */
    scr = *(const scr_const_t **)imp_scr_const;
    DObjSetControlTagAngles(obj, partBits, scr->tag_aim, angles);

    /* line 320: set tag_turret_pitch control tag angles */
    DObjSetControlTagAngles(obj, partBits, scr->tag_aim_animated, angles);

    /* line 322: lerp barrel angle */
    cg_s = *(cg_t **)imp_cg;
    angles[0] = LerpAngle(s1->angles2[2], s1->angles2[2], cg_s->frameInterpolation);
    angles[1] = 0.0f;

    /* line 325: set tag_barrel control tag angles */
    DObjSetControlTagAngles(obj, partBits, scr->tag_flash, angles);

    /* line 327: get anim tree */
    tree = (struct XAnim_s *)DObjGetTree(obj);

    /* line 330-335: determine anim index based on player state */
    if (cg_s->predictedPlayerState.eFlags & 0x300) {
        if (cg_s->predictedPlayerState.viewlocked_entNum == s1->number) {
            animIndex = 1;
        } else {
            if (*(byte *)&cent->nextState.eFlags & 0x40) {
                animIndex = 2;
            } else {
                animIndex = 1;
            }
        }
    } else {
        if (*(byte *)&cent->nextState.eFlags & 0x40) {
            animIndex = 2;
        } else {
            animIndex = 1;
        }
    }

    /* line 337: XAnimSetCompleteGoalWeightKnobAll(tree, animIndex, 1.0f, 0.1f, 1.0f, 0, 0) */
    {
        float goalWeight = 1.0f;     /* 0x3f800000 */
        float goalTime = 0.1f;       /* 0x3dcccccd */
        float rate = 1.0f;           /* 0x3f800000 */
        XAnimSetCompleteGoalWeightKnobAll(tree, animIndex, goalWeight, goalTime, rate, 0, 0);
    }

    return 0;
}
