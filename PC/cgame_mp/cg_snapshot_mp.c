/* Decompiled from: cg_snapshot_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_snapshot_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

/*
 * NOTE: The binary uses different struct sizes than common_types.h:
 *   - entityState_t is 0xf0 (240) bytes in binary vs 0xec (236) in C
 *   - centity_s is 0x224 (548) bytes in binary vs 0x21c (540) in C
 *   - playerState_t is 0x26a8 bytes in binary vs 0x7ac in C
 *   - snapshot_t is 0x12dc0 bytes in binary vs 0x10ac4 in C
 * Therefore all struct accesses use byte-offset pointer arithmetic
 * with the actual binary offsets.
 */

/* External globals (pointers-to-pointers) */
extern char **cg_glob;           /* imp_cg — pointer to cg_t base */
extern char **cg_entities_glob;  /* imp_cg_entities — pointer to centity array base */
extern char **cgs_glob;          /* imp_cgs — pointer to cgs_t base */
extern char **cg_dvar1;          /* imp_cg_nopredict */
extern char **cg_dvar2;          /* imp_cg_synchronousClients */

/* External function declarations */
extern void BG_EvaluateTrajectory(void *traj, int time, float *result);
extern void BG_PlayerStateToEntityState(void *ps, void *es, int extrapolate, int snap);
extern void CG_ResetPlayerEntity(centity_t *cent);
extern void XAnimCloneAnimTree(void *srcTree, void *destTree);
extern int I_stricmp(const char *s1, const char *s2);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void CL_ResetSkeletonCache(int val);
extern void CG_SetFrameInterpolation(void);
extern void CG_ExecuteNewServerCommands(int serverCommandSequence);
extern void CG_CheckOpenWaitingScriptMenu(void);
extern void CG_Respawn(void);
extern void CG_BuildSolidList(void);
extern void CG_ClearSolidList(void);
extern void CG_PlaySmokeGrenadesAtTime(int time);
extern void CG_SetEquippedOffHand(int offHandIndex);
extern void CG_TransitionPlayerState(void *newPs, void *oldPs);
extern void CG_CheckEvents(void *cent);
extern void CG_UpdatePlayerDObj(void *cent);
extern void CG_UpdateHandViewmodels(const char *configStr);
extern void CG_AddLagometerSnapshotInfo(void *snap);
extern int CL_GetSnapshot(int snapshotNumber, void *snap);
extern void CL_GetCurrentSnapshotNumber(int *snapshotNumber, int *serverTime);
extern const char *CL_GetConfigString(int index);
extern void CG_GameMessage(const char *msg);
extern void CG_SafeDObjFree(int entNum);
extern void CG_InitView(void);
extern void SND_SetListener(int clientNum, float *origin, float *axis);
extern void SND_FadeAllSounds(float volume, int duration);
extern void AnglesToAxis(float *angles, float *axis);
extern const char *va(const char *fmt, ...);
extern const char *UI_SafeTranslateString(const char *ref);
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern int strcmp(const char *s1, const char *s2);
extern void *XAnimGetAnims(void *tree);
extern int XAnimIsLooped(void *anims, int animIndex);
extern int XAnimGetNumChildren(void *anims, int animIndex);
extern void XAnimSetTime(void *tree, int animIndex, float time);

/* ===== Binary layout offsets for centity (stride = 0x224 = 548 bytes) ===== */
#define CENT_STRIDE              0x224
/* currentState offsets (from centity base) */
#define CENT_CS_NUMBER           0x000
#define CENT_CS_ETYPE            0x004
#define CENT_CS_EFLAGS           0x008
#define CENT_CS_POS              0x00c   /* trajectory_t, 36 bytes */
#define CENT_CS_APOS             0x030
#define CENT_CS_CLIENTNUM        0x090
#define CENT_CS_EVENTSEQUENCE    0x0a4
#define CENT_CS_LEANF            0x0d4
#define CENT_CS_DMGFLAGS         0x0d8
/* nextState offsets */
#define CENT_NS_NUMBER           0x0f0
#define CENT_NS_ETYPE            0x0f4
#define CENT_NS_EFLAGS           0x0f8
#define CENT_NS_POS              0x0fc
#define CENT_NS_APOS             0x120
#define CENT_NS_TIME             0x144
#define CENT_NS_TIME2            0x148
#define CENT_NS_INDEX            0x17c   /* 0xf0 + 0x8c */
#define CENT_NS_CLIENTNUM        0x180
#define CENT_NS_EVENTSEQUENCE    0x194
#define CENT_NS_LEANF            0x1c4
/* other centity fields */
#define CENT_NEXTVALID           0x1e0
#define CENT_CULLIN              0x1e1
#define CENT_BMUZZLEFLASH        0x1e2
#define CENT_BTRAILMADE          0x1e3
#define CENT_PREVIOUSEVENTSEQ    0x1e4
#define CENT_MISCTIME            0x1e8
#define CENT_LERPORIGIN          0x1ec
#define CENT_LERPANGLES          0x1f8
#define CENT_LIGHTINGORIGIN      0x204
#define CENT_TREE                0x21c

/* ===== Binary layout offsets for cg_t ===== */
#define CG_CLIENTFRAME           0x00
#define CG_CLIENTNUM             0x04
#define CG_DEMOTYPE              0x08
#define CG_CUBEMAPSHOT           0x0c
#define CG_LATESTSNAPSHOTNUM     0x18
#define CG_LATESTSNAPSHOTTIME    0x1c
#define CG_SNAP                  0x20
#define CG_NEXTSNAP              0x24
#define CG_ACTIVESNAPSHOTS       0x28
#define CG_TIME                  0x25bb0
#define CG_OLDTIME               0x25bb4
#define CG_MAPRESTART            0x25bbc
#define CG_PREDICTEDPS           0x25bc4
#define CG_PREDICTEDERRORTIME    0x284c0
#define CG_PREDICTEDERROR        0x284c4
#define CG_FIRSTPERSONGUNINIT    0x2cd14
#define CG_CLIENTINFO_BASE       0xe0900
#define CG_LATESTSERVERTIME      0xe08f4
#define CG_SERVERTIME2           0xe08f8

/* ===== Binary layout offsets for snapshot_t (size = 0x12dc0) ===== */
#define SNAP_SIZE                0x12dc0
#define SNAP_SNAPFLAGS           0x000
#define SNAP_PING                0x004
#define SNAP_SERVERTIME          0x008
#define SNAP_PS                  0x00c
#define SNAP_PS_VIEWANGLES       0x0f4   /* relative to snap start: 0xc + viewangles offset */
#define SNAP_PS_VIEWHEIGHTCURRENT 0x104  /* 0xc + 0xf8 */
#define SNAP_PS_CLIENTNUM        0x0d8   /* snap.ps + 0xcc = clientNum? Let me use raw */
#define SNAP_PS_ORIGIN           0x020   /* snap + 0x20 = ps.origin? */
#define SNAP_PS_VIEWANGLE2       0x02c   /* snap + 0x2c */
#define SNAP_PS_VIEWHEIGHT       0x110   /* snap + 0x110 */
#define SNAP_NUMENTITIES         0x26b4
#define SNAP_NUMCLIENTS          0x26b8
#define SNAP_ENTITIES            0x26bc
#define SNAP_CLIENTS             0x116b0
#define SNAP_SERVERCMDSEQ        0x12dbc

/* ===== Binary layout offsets for cgs_t ===== */
#define CGS_PROCESSEDSNAPSHOTNUM 0x5e9c

/* ===== clientInfo_t binary offsets (size = 0x4b8, stride = 0x4b8) ===== */
#define CI_STRIDE                0x4b8
#define CI_INFOVALID             0x000
#define CI_NEXTVALID             0x004
#define CI_CLIENTNUM             0x008
#define CI_NAME                  0x00c
#define CI_TEAM                  0x02c
#define CI_MODEL                 0x040
#define CI_ATTACHMODELNAMES      0x080
#define CI_ATTACHTAGNAMES        0x200
#define CI_DOBJDIRTY             0x3f8
#define CI_PXANIMTREE            0x4a4

/* ===== clientState_t binary offsets (size = 0x5c) ===== */
#define CLSTATE_STRIDE           0x5c

/* ===== entityState_t binary size ===== */
#define ES_BINSIZE               0x0f0

/* ===== Inline helper: VectorCopy ===== */
#define VectorCopy3(src, dst) do { \
    ((int*)(dst))[0] = ((int*)(src))[0]; \
    ((int*)(dst))[1] = ((int*)(src))[1]; \
    ((int*)(dst))[2] = ((int*)(src))[2]; \
} while(0)

/* ===== Inline helper: VectorClear ===== */
#define VectorClear3(v) do { \
    ((int*)(v))[0] = 0; \
    ((int*)(v))[1] = 0; \
    ((int*)(v))[2] = 0; \
} while(0)

/* Forward declarations */
static void CG_ResetEntity(char *cent);
void CG_SetNextSnap(snapshot_t *snap);
void CG_SetInitialSnapshot(snapshot_t *snap);
void CG_ProcessSnapshots(void);

/* Helper to compute centity pointer from entity number */
static char *CG_EntityPtr(int entNum)
{
    return (char *)&((centity_t *)*cg_entities_glob)[entNum];
}

/* Helper to compute clientInfo pointer from client number */
static char *CG_ClientInfoPtr(char *cg, int clientNum)
{
    return (char *)&((cg_t *)cg)->bgs.clientinfo[clientNum];
}

/* ============================================================
 * CG_ResetEntity
 * Resets a centity when transitioning snapshots.
 * Called with centity pointer (binary layout).
 * ============================================================ */

/* line 47 */
static void CG_ResetEntity(char *cent)
{
    cg_t *cg = *(cg_t **)cg_glob;
    cgs_t *cgs = *(cgs_t **)cgs_glob;
    int eType;

    /* line 54: clear lightingOrigin (3 ints at offset 0x204) */
    VectorClear3((char *)((centity_t *)cent)->lightingOrigin);

    /* line 56: memcpy(cent, cent + 0xf0, 0xf0)
     * Copy nextState over currentState */
    memcpy(cent, cent + ES_BINSIZE, ES_BINSIZE) /* copy nextState -> currentState */;

    /* line 58-59: clear bTrailMade and cullIn */
    ((centity_t *)cent)->bTrailMade = 0;
    ((centity_t *)cent)->cullIn = 0;

    /* line 61: BG_EvaluateTrajectory(&cent->nextState.pos, cg->time, &cent->lerpOrigin) */
    BG_EvaluateTrajectory((char *)&((centity_t *)cent)->nextState.pos, cg->time, (float *)((char *)((centity_t *)cent)->lerpOrigin));

    /* line 62: BG_EvaluateTrajectory(&cent->nextState.apos, cg->time, &cent->lerpAngles) */
    BG_EvaluateTrajectory((char *)&((centity_t *)cent)->nextState.apos, cg->time, (float *)((char *)((centity_t *)cent)->lerpAngles));

    /* line 64: switch on nextState.eType */
    eType = ((centity_t *)cent)->nextState.eType;

    switch (eType)
    {
    case 0:  /* ET_GENERAL */
    case 4:  /* ET_ITEM */
        /* line 69: cent->previousEventSequence = 0 */
        ((centity_t *)cent)->previousEventSequence = 0;
        break;

    case 1:  /* ET_PLAYER */
    {
        char *ci;
        int clientNum;

        /* line 73: cent->previousEventSequence = cent->nextState.eventSequence */
        ((centity_t *)cent)->previousEventSequence = ((centity_t *)cent)->nextState.eventSequence;

        /* line 75: compute clientInfo pointer from nextState.clientNum */
        clientNum = ((centity_t *)cent)->nextState.clientNum;
        ci = (char *)&((cg_t *)cg)->bgs.clientinfo[clientNum] - 0x14; /* clientInfo base (0x14 before clientinfo[] entry) */

        /* line 76: ci->lerpMoveDir = cent->nextState.angles2[1]
         * ci = &clientinfo[clientNum] - 0x14, so (ci+0x14) = &clientinfo[clientNum]
         * (ci+0x14)+0x3e0 = clientinfo[clientNum].lerpMoveDir
         */
        ((clientInfo_t *)(ci + 0x14))->lerpMoveDir = *(int *)(cent + 0x15c) /* cent->nextState.angles2[1] */;

        /* line 77: ci->lerpLean = cent->nextState.leanf */
        ((clientInfo_t *)(ci + 0x14))->lerpLean = *(int *)&((centity_t *)cent)->nextState.leanf;

        /* line 78: VectorCopy cent->lerpAngles to ci + 0x3fc */
        {
            char *to = ci + 0x3fc;
            VectorCopy3((char *)((centity_t *)cent)->lerpAngles, to);
        }

        /* line 79-80: clear lerpAngles[0] and lerpAngles[2] (or lightingOrigin[0,2]?) */
        /* Actually: 0x1f8 = lerpAngles, 0x200 = lerpAngles + 8 = lerpAngles[2] */
        /* asm: movl $0, 0x1f8(%ebx) and movl $0, 0x200(%ebx) */
        /* lerpAngles[0] = 0 and lerpAngles[2] = 0 */
        *(int *)((char *)((centity_t *)cent)->lerpAngles) = 0;
        *(int *)((char *)((centity_t *)cent)->lerpAngles + 8) = 0;

        /* line 81: CG_ResetPlayerEntity(cent) */
        CG_ResetPlayerEntity((centity_t *)cent);
        break;
    }

    case 2:  /* ET_CORPSE */
    {
        char *ci;
        char *corpseInfo;
        char *corpseBase;
        void *pXAnimTree;
        int entNum;
        int clientNum;

        /* line 88: compute clientInfo from nextState.clientNum */
        clientNum = ((centity_t *)cent)->nextState.clientNum;
        ci = (char *)&((cg_t *)cg)->bgs.clientinfo[clientNum];

        /* line 89: compute corpseInfo from currentState.number
         * corpseInfo is in a separate array accessed relative to cgs */
        entNum = ((centity_t *)cent)->nextState.number;
        /* The asm computes: leal -0x6bf0(%edx, %eax, 8) where edx = *cgs_glob
         * and eax = 151*entNum (clientInfo_t stride/8 * entNum)
         * So: corpseBase = cgs + entNum * CI_STRIDE - 0x6bf0
         * corpseInfo = corpseBase + 4 (skipping the tree pointer)
         */
        {
            char *cgs_ptr = *cgs_glob;
            /* cgs + entNum * CI_STRIDE - 0x6bf0 */
            corpseBase = cgs_ptr + entNum * CI_STRIDE - 0x6bf0;
            corpseInfo = corpseBase + 4;
        }

        /* line 90: save pXAnimTree */
        pXAnimTree = ((clientInfo_t *)corpseInfo)->pXAnimTree;

        /* line 92: test cent->nextState.eFlags & 8 */
        if (((centity_t *)cent)->nextState.eFlags & 8)
        {
            int attachIndex;

            /* Inline CG_CopyClientInfoModel: memcpy(corpseInfo, ci, 0x4b8) */
            memcpy(corpseInfo, ci, CI_STRIDE);

            /* Clear certain attachment model names */
            {
                char *tagSrc = corpseBase + 0x204;  /* corpseBase + 4 + 0x200 = attachTagNames */
                char *modelDst = corpseInfo;
                for (attachIndex = 0; attachIndex < 6; attachIndex++)
                {
                    if (I_stricmp(tagSrc, (const char *)"J_Spine4") == 0)
                    {
                        ((clientInfo_t *)modelDst)->attachModelNames[0][0] = 0;   /* attachModelNames[i][0] = 0 */
                        ((clientInfo_t *)modelDst)->attachTagNames[0][0] = 0;   /* attachTagNames[i][0] = 0 */
                    }
                    tagSrc += 0x40;
                    modelDst += 0x40;
                }
            }

            /* line 95: restore pXAnimTree */
            ((clientInfo_t *)corpseInfo)->pXAnimTree = pXAnimTree;

            /* line 96: XAnimCloneAnimTree(ci->pXAnimTree, pXAnimTree) */
            XAnimCloneAnimTree(((clientInfo_t *)ci)->pXAnimTree, pXAnimTree);

            /* line 98: cent->previousEventSequence = 0 */
            ((centity_t *)cent)->previousEventSequence = 0;
        }
        else
        {
            /* line 103: check corpseInfo->model[0] (at corpseInfo + 0x40) */
            if (((clientInfo_t *)corpseInfo)->model[0] != 0)
            {
                /* line 104-105: check if corpseInfo->clientNum != ci->clientNum */
                if (((clientInfo_t *)corpseInfo)->clientNum != ((clientInfo_t *)ci)->clientNum)
                {
                    /* Copy ci to corpseInfo */
                    goto do_corpse_copy_from_ci;
                }
                /* else: clientNum matches, skip copy */
            }
            else
            {
                /* model[0] == 0: copy from ci */
                do_corpse_copy_from_ci:
                {
                    int attachIndex;
                    char *src = ci;

                    /* If model[0] was zero, src = ci; otherwise src was already ci */
                    /* Actually the asm at .Lf1dc43c_001dc72f sets eax = ci then jumps to copy */
                    memcpy(corpseInfo, src, CI_STRIDE);

                    /* Clear certain attachment model names */
                    {
                        char *tagSrc = corpseBase + 0x204;
                        char *modelDst = corpseInfo;
                        for (attachIndex = 0; attachIndex < 6; attachIndex++)
                        {
                            if (I_stricmp(tagSrc, (const char *)"J_Spine4") == 0)
                            {
                                ((clientInfo_t *)modelDst)->attachModelNames[0][0] = 0;
                                ((clientInfo_t *)modelDst)->attachTagNames[0][0] = 0;
                            }
                            tagSrc += 0x40;
                            modelDst += 0x40;
                        }
                    }

                    /* line 106: restore pXAnimTree */
                    ((clientInfo_t *)corpseInfo)->pXAnimTree = pXAnimTree;
                }
            }

            /* line 109: cent->previousEventSequence = cent->nextState.eventSequence */
            ((centity_t *)cent)->previousEventSequence = ((centity_t *)cent)->nextState.eventSequence;
        }

        /* line 112: corpseInfo->dobjDirty = 1 */
        ((clientInfo_t *)corpseInfo)->dobjDirty = 1;
        break;
    }

    default:
        /* line 117: cent->previousEventSequence = cent->nextState.eventSequence */
        ((centity_t *)cent)->previousEventSequence = ((centity_t *)cent)->nextState.eventSequence;
        break;
    }
}

/* ============================================================
 * CG_SetNextSnap
 * Sets the next snapshot and processes entity transitions.
 * ============================================================ */

/* Inline helper: CG_ClearClientInfos (the inline function at lines 20-30) */
static void CG_ClearClientInfos_Inline(char *dest, char *src, char *tagBase, int size)
{
    int attachIndex;
    char *tagSrc = tagBase;
    char *dst = dest;

    memcpy(dest, src, size);

    for (attachIndex = 0; attachIndex < 6; attachIndex++)
    {
        if (I_stricmp(tagSrc, (const char *)"J_Spine4") == 0)
        {
            ((clientInfo_t *)dst)->attachModelNames[0][0] = 0;
            ((clientInfo_t *)dst)->attachTagNames[0][0] = 0;
        }
        tagSrc += 0x40;
        dst += 0x40;
    }
}

/* ============================================================
 * CG_TransitionSnapshot (inlined, lines 183-202, 244-292)
 * Called to advance the snapshot state.
 * ============================================================ */

static void CG_TransitionSnapshot_Inline(void)
{
    cg_t *cg = *(cg_t **)cg_glob;
    centity_t *cg_ents = (centity_t *)*cg_entities_glob;
    char *snap;
    int numClients, i;

    snap = (char *)cg->snap;

    /* line 244: process clients in snap->numClients */
    numClients = *(int *)((char *)snap + SNAP_NUMCLIENTS);
    for (i = 0; i < numClients; i++)
    {
        char *clState = (char *)snap + SNAP_CLIENTS + i * CLSTATE_STRIDE;
        int clientNum = ((clientState_t *)clState)->clientIndex;
        char *ci = (char *)&((cg_t *)cg)->bgs.clientinfo[clientNum];

        /* line 248: check ci->nextValid */
        if (((clientInfo_t *)ci)->nextValid == 0)
        {
            /* line 250: already not valid, just clear nextValid */
            ((clientInfo_t *)ci)->nextValid = 0;
            continue;
        }
        else
        {
            /* line 253-256: save pXAnimTree, memset ci, restore pXAnimTree, SafeDObjFree */
            void *savedTree = ((clientInfo_t *)ci)->pXAnimTree;
            memset(ci, 0, CI_STRIDE);
            ((clientInfo_t *)ci)->pXAnimTree = savedTree;
            CG_SafeDObjFree(clientNum);
            continue;
        }
    }

    /* line 271: cg->snap = cg->nextSnap */
    cg->snap = cg->nextSnap;

    /* line 273: check if snap->ps.eFlags has teleport bits */
    snap = (char *)cg->nextSnap;
    if (((snapshot_t *)snap)->ps.pm_flags & 0xc00000)  /* ps.eFlags offset = ps + 0xc? */
    {
        /* line 275: get player entity and copy nextState to currentState */
        int playerEntNum = ((snapshot_t *)snap)->ps.clientNum;
        char *playerEnt = (char *)&cg_ents[playerEntNum];
        memcpy(playerEnt, playerEnt + ES_BINSIZE, ES_BINSIZE) /* copy nextState -> currentState */;
    }

    /* line 279: for each entity in snap, copy nextState to currentState */
    {
        int numEnts = ((snapshot_t *)snap)->numEntities;
        for (i = 0; i < numEnts; i++)
        {
            char *snapEnt = (char *)&((snapshot_t *)snap)->entities[i];
            int entNum = ((entityState_t *)snapEnt)->number;
            char *cent = (char *)&cg_ents[entNum];
            memcpy(cent, cent + ES_BINSIZE, ES_BINSIZE) /* copy nextState -> currentState */;
        }
    }
}

/* line 297 */
void CG_SetNextSnap(snapshot_t *snap_param)
{
    char centInPrevSnapshot[1024];
    char *snap = (char *)snap_param;
    cg_t *cg = *(cg_t **)cg_glob;
    centity_t *cg_ents = (centity_t *)*cg_entities_glob;
    char *prevSnap;
    int i;

    /* line 314: clear centInPrevSnapshot */
    memset(centInPrevSnapshot, 0, 0x400);

    /* line 316: get previous snap */
    prevSnap = (char *)cg->nextSnap;

    if (prevSnap)
    {
        int numEnts;

        /* line 319: mark entities from previous snap */
        numEnts = ((snapshot_t *)prevSnap)->numEntities;
        if (numEnts > 0)
        {
            for (i = 0; i < numEnts; i++)
            {
                char *snapEnt = (char *)&((snapshot_t *)prevSnap)->entities[i];
                int entNum = ((entityState_t *)snapEnt)->number;
                char *cent = (char *)&cg_ents[entNum];

                /* line 325: cent->nextValid = 0 */
                ((centity_t *)cent)->nextValid = 0;

                /* line 326: centInPrevSnapshot[entNum] = 1 */
                centInPrevSnapshot[entNum] = 1;
            }
        }

        /* line 329-333: handle the player's own entity */
        {
            int playerNum = ((snapshot_t *)prevSnap)->ps.clientNum;
            char *playerEnt = (char *)&cg_ents[playerNum];
            if (((centity_t *)playerEnt)->nextValid)
            {
                ((centity_t *)playerEnt)->nextValid = 0;
                centInPrevSnapshot[playerNum] = 1;
            }
        }
    }

    /* line 337: cg->nextSnap = snap */
    cg->nextSnap = (snapshot_t *)snap;

    /* line 339: if snap is NULL */
    if (!snap)
    {
        /* line 341 */
        CG_ClearSolidList();
        return;
    }

    /* line 347: CL_ResetSkeletonCache(0) */
    CL_ResetSkeletonCache(0);

    /* line 349: CG_SetFrameInterpolation */
    CG_SetFrameInterpolation();

    /* line 351: CG_ExecuteNewServerCommands(snap->serverCommandSequence) */
    CG_ExecuteNewServerCommands(((snapshot_t *)snap)->serverCommandSequence);

    /* line 355 */
    CG_CheckOpenWaitingScriptMenu();

    /* line 361: process clients */
    {
        int numClients = ((snapshot_t *)snap)->numClients;
        if (numClients > 0)
        {
            for (i = 0; i < numClients; i++)
            {
                char *clState = (char *)snap + SNAP_CLIENTS + i * CLSTATE_STRIDE;
                int clientNum;
                char *ci;
                int modelIndex;
                const char *configStr;

                /* line 363: advance past header */
                char *clData = clState + 0xc;  /* skip to client data portion */

                /* line 368: get clientNum from clientState */
                clientNum = ((clientState_t *)clState)->attachModelIndex[0];
                ci = (char *)&((cg_t *)cg)->bgs.clientinfo[clientNum];

                /* line 369: check ci->infoValid. If not valid, use clState->oldteam instead */
                if (((clientInfo_t *)ci)->infoValid == 0)
                    modelIndex = ((clientState_t *)clState)->attachModelIndex[1];  /* oldteam / some field */
                else
                    modelIndex = ((clientInfo_t *)ci)->team;  /* team field at CI + 0x2c = 0x30 (model count?) */

                /* line 370-373: set ci fields */
                ((clientInfo_t *)ci)->oldteam = modelIndex;
                ((clientInfo_t *)ci)->infoValid = 1;
                ((clientInfo_t *)ci)->nextValid = 1;
                ((clientInfo_t *)ci)->clientNum = ((clientState_t *)clState)->attachModelIndex[0];
                ((clientInfo_t *)ci)->team = ((clientState_t *)clState)->attachModelIndex[1];

                /* line 380: compare ci->name with clData+0x3c (name from clientState) */
                {
                    char *ciName = ((clientInfo_t *)ci)->name;
                    char *clName = clState + 0xc + 0x30;  /* clData offset for name */

                    if (strcmp(ciName, clName) != 0)
                    {
                        /* line 382: if ci->name[0] is set, show team change message */
                        if (((clientInfo_t *)ci)->name[0] != 0)
                        {
                            /* line 383 */
                            const char *translated = UI_SafeTranslateString((const char *)"CGAME_PLAYERRENAMES");
                            const char *msg = va((const char *)"%s^7 %s %s", ciName, translated, clName);
                            CG_GameMessage(msg);
                        }

                        /* line 384: copy new name */
                        I_strncpyz(ciName, clName, 0x20);
                    }
                }

                /* line 387: get config string for model */
                {
                    int configIndex = ((clientState_t *)clState)->attachModelIndex[2];
                    configStr = CL_GetConfigString(configIndex + 0x14e);
                }

                /* line 388: compare ci->model with config string */
                {
                    char *ciModel = ((clientInfo_t *)ci)->model;
                    if (strcmp(ciModel, configStr) != 0)
                    {
                        /* line 390: copy new model */
                        I_strncpyz(ciModel, configStr, 0x40);
                        ((clientInfo_t *)ci)->dobjDirty = 1;
                    }
                }

                /* line 391-410: process 6 attachment slots */
                {
                    char *clStateSlots = clState + 0xc;  /* start of per-slot data in clientState */
                    int slot;
                    char *ciAttachModel = ((clientInfo_t *)ci)->attachModelNames[0];
                    char *ciAttachTag = ((clientInfo_t *)ci)->attachTagNames[0];

                    for (slot = 0; slot < 6; slot++)
                    {
                        /* line 396: get config string for attachment model */
                        int attachModelIdx = *(int *)(clStateSlots + 0x0c); /* clientState slot: attachModelIndex at +0x0c */
                        configStr = CL_GetConfigString(attachModelIdx + 0x14e);

                        if (strcmp(ciAttachModel, configStr) != 0)
                        {
                            /* line 399: copy new attachment model name */
                            I_strncpyz(ciAttachModel, configStr, 0x40);
                            ((clientInfo_t *)ci)->dobjDirty = 1;
                        }

                        /* line 403: get config string for attachment tag */
                        {
                            int attachTagIdx = *(int *)(clStateSlots + 0x24); /* clientState slot: attachTagIndex at +0x24 */
                            const char *tagStr = CL_GetConfigString(attachTagIdx + 0x6e);

                            if (strcmp(ciAttachTag, tagStr) != 0)
                            {
                                /* line 406: copy new attachment tag name */
                                I_strncpyz(ciAttachTag, tagStr, 0x40);
                                ((clientInfo_t *)ci)->dobjDirty = 1;
                            }
                        }

                        ciAttachModel += 0x40;
                        ciAttachTag += 0x40;
                        clStateSlots += 4;
                    }
                }
            }
        }
    }

    /* line 412: store snap serverTime related fields */
    cg = *(cg_t **)cg_glob;
    cg->identifyClientNum = ((snapshot_t *)snap)->ps.stats[3];
    cg->identifyClientHealth = ((snapshot_t *)snap)->ps.stats[4];

    /* line 415: get entnum from ps */
    {
        int entnum = ((snapshot_t *)snap)->ps.clientNum;

        /* line 417: check ps.eFlags for teleport bits */
        if (((snapshot_t *)snap)->ps.pm_flags & 0xc00000)
        {
            /* line 419-422: player entity state conversion */
            char *playerEnt = CG_EntityPtr(entnum);

            /* line 420: set nextState.number = entnum (lower 16 bits) */
            ((centity_t *)playerEnt)->nextState.number = (unsigned short)entnum;

            /* line 421: BG_PlayerStateToEntityState */
            BG_PlayerStateToEntityState((char *)&((snapshot_t *)snap)->ps, playerEnt + ES_BINSIZE, 0, 0);

            /* line 422: set nextValid = 1 */
            ((centity_t *)playerEnt)->nextValid = 1;

            /* line 424-434: check mapRestart and handle player reset */
            {
                cg_t *cgBase = *(cg_t **)cg_glob;
                char *oldSnap = (char *)cgBase->snap;

                if (cgBase->mapRestart || ((snapshot_t *)snap)->ps.stats[5] != ((snapshot_t *)oldSnap)->ps.stats[5])
                {
                    /* line 426/432: copy ps to old snap's ps */
                    memcpy((char *)&((snapshot_t *)oldSnap)->ps, (char *)&((snapshot_t *)snap)->ps, 0x26a8);

                    /* line 427/433: CG_ResetEntity */
                    CG_ResetEntity(playerEnt);

                    if (cgBase->mapRestart || !centInPrevSnapshot[entnum] ||
                        (((centity_t *)playerEnt)->currentState.eFlags ^ ((centity_t *)playerEnt)->nextState.eFlags) & 2)
                    {
                        /* Just reset, already done */
                    }

                    /* Check if we need Respawn */
                    if (cgBase->mapRestart)
                    {
                        CG_Respawn();
                        /* line 434: clear predictedError */
                        VectorClear3(cgBase->predictedError);
                    }
                    else
                    {
                        /* Non-mapRestart but ps changed */
                        CG_Respawn();
                    }
                }
                else if (entnum != ((snapshot_t *)oldSnap)->ps.clientNum)
                {
                    /* Different client num: also need full transition */
                    memcpy((char *)&((snapshot_t *)oldSnap)->ps, (char *)&((snapshot_t *)snap)->ps, 0x26a8);
                    CG_Respawn();
                }
                else
                {
                    /* Same client, check centInPrevSnapshot */
                    if (!centInPrevSnapshot[entnum] || (((centity_t *)playerEnt)->currentState.eFlags ^ ((centity_t *)playerEnt)->nextState.eFlags) & 2)
                    {
                        /* Need reset */
                        memcpy((char *)&((snapshot_t *)oldSnap)->ps, (char *)&((snapshot_t *)snap)->ps, 0x26a8);
                        CG_ResetEntity(playerEnt);
                        VectorClear3(cgBase->predictedError);
                    }
                    /* else: no changes needed */
                }
            }
        }
        else
        {
            /* No teleport flags */
            cg_t *cgBase = *(cg_t **)cg_glob;
            char *oldSnap = (char *)cgBase->snap;

            if (cgBase->mapRestart)
            {
                /* mapRestart: copy and respawn */
                memcpy(oldSnap + 0xc, snap + 0xc, 0x26a8);
                CG_Respawn();
            }
            else
            {
                /* Check if ps has changed */
                if (((snapshot_t *)snap)->ps.stats[5] != ((snapshot_t *)oldSnap)->ps.stats[5])
                {
                    memcpy(oldSnap + 0xc, snap + 0xc, 0x26a8);
                    CG_Respawn();
                }
                else if (entnum != ((snapshot_t *)oldSnap)->ps.clientNum)
                {
                    memcpy(oldSnap + 0xc, snap + 0xc, 0x26a8);
                    CG_Respawn();
                }
                /* else: no changes needed */
            }
        }
    }

    /* line 446: process snap entities */
    {
        int numEnts = ((snapshot_t *)snap)->numEntities;
        for (i = 0; i < numEnts; i++)
        {
            char *snapEnt = (char *)&((snapshot_t *)snap)->entities[i];
            int entNum = ((entityState_t *)snapEnt)->number;
            char *cent = CG_EntityPtr(entNum);

            /* line 451: copy snap entity to cent->nextState */
            memcpy(cent + ES_BINSIZE, snapEnt, ES_BINSIZE);

            /* line 453: cent->nextValid = 1 */
            ((centity_t *)cent)->nextValid = 1;

            /* line 457: check if entity was in prev snapshot */
            if (centInPrevSnapshot[entNum])
            {
                /* Check if eFlags changed for bit 2 */
                if ((((centity_t *)cent)->currentState.eFlags ^ ((entityState_t *)snapEnt)->eFlags) & 2)
                {
                    /* eFlags bit 2 changed: reset entity */
                    CG_ResetEntity(cent);
                }
                /* else: no reset needed */
            }
            else
            {
                /* line 458: entity wasn't in prev snapshot: reset */
                CG_ResetEntity(cent);
            }
        }
    }

    /* line 461: update player DObjs for clients */
    {
        int numClients = ((snapshot_t *)snap)->numClients;
        for (i = 0; i < numClients; i++)
        {
            char *clState = (char *)snap + SNAP_CLIENTS + i * CLSTATE_STRIDE;
            int clientNum = ((clientState_t *)clState)->attachModelIndex[0];
            CG_UpdatePlayerDObj(CG_EntityPtr(clientNum));
        }
    }

    /* line 465: update view model */
    {
        int viewModelIndex = ((snapshot_t *)snap)->ps.viewmodelIndex;  /* ps.viewmodelIndex */
        if (viewModelIndex > 0)
        {
            const char *cfgStr = CL_GetConfigString(viewModelIndex + 0x14e);
            CG_UpdateHandViewmodels(cfgStr);
        }
    }

    /* line 473 */
    CG_BuildSolidList();

    /* lines 183-218: check firstPersonGunInit and handle initialization */
    {
        cg_t *cgBase = *(cg_t **)cg_glob;
        int gunInit = cgBase->inKillCam;
        char *nextSnap;

        if (!gunInit)
        {
            nextSnap = (char *)cgBase->nextSnap;
            int hasGun = ((snapshot_t *)nextSnap)->ps.deltaTime;  /* ps.weapon or similar */

            if (hasGun)
            {
                /* line 185: set firstPersonGunInit = 1 */
                cgBase->inKillCam = 1;

                /* line 188 */
                CG_SetEquippedOffHand(0);

                /* line 191 */
                CG_PlaySmokeGrenadesAtTime(cgBase->time);
            }
        }

        if (gunInit || (((snapshot_t *)cgBase->nextSnap)->ps.deltaTime != 0))
        {
            /* line 200: play smoke grenades and handle corpse anim trees */
            nextSnap = (char *)cgBase->nextSnap;
            if (((snapshot_t *)nextSnap)->ps.deltaTime == 0)
            {
                /* line 197: clear firstPersonGunInit */
                cgBase->inKillCam = 0;

                /* line 200 */
                cgBase = *cg_glob;
                CG_PlaySmokeGrenadesAtTime(cgBase->time);

                /* line 202-218: process entities for corpse anim trees */
                {
                    int numEnts;
                    nextSnap = (char *)cgBase->nextSnap;
                    numEnts = ((snapshot_t *)nextSnap)->numEntities;

                    for (i = 0; i < numEnts; i++)
                    {
                        char *snapEnt = (char *)&((snapshot_t *)nextSnap)->entities[i];
                        int entNum = ((entityState_t *)snapEnt)->number;
                        char *cent = CG_EntityPtr(entNum);

                        /* line 206: check if eType == 2 (corpse) */
                        if (((centity_t *)cent)->nextState.eType != 2)
                            continue;

                        /* line 211: get corpseInfo for this entity */
                        {
                            char *cgs_ptr = *cgs_glob;
                            int csNum = ((centity_t *)cent)->nextState.number;
                            char *corpseBase = cgs_ptr + csNum * CI_STRIDE - 0x6bf0;
                            char *corpseCI = corpseBase + 4;

                            /* line 212: save pXAnimTree */
                            void *savedTree = *(void **)(corpseCI + CI_PXANIMTREE);

                            /* line 214: get animation state, mask out bit 9 */
                            int animState = *(int *)(corpseCI + 0x390) /* clientInfo->animState at 0x390 */ & ~0x200;

                            /* line 215: get anims from tree */
                            void *anims = XAnimGetAnims(savedTree);

                            /* line 216: if animState is 0, skip */
                            if (animState == 0)
                                continue;

                            /* Check if anim is looped */
                            if (XAnimIsLooped(anims, animState))
                                continue;

                            /* Check if anim has children */
                            if (XAnimGetNumChildren(anims, animState) != 0)
                                continue;

                            /* line 218: set anim time to 1.0f */
                            XAnimSetTime(savedTree, animState, 1.0f);
                        }
                    }
                }
            }
        }
    }

    /* line 477-483: check events for entities in snap */
    {
        int numEnts = ((snapshot_t *)snap)->numEntities;
        for (i = 0; i < numEnts; i++)
        {
            char *snapEnt = (char *)&((snapshot_t *)snap)->entities[i];
            int entNum = ((entityState_t *)snapEnt)->number;
            CG_CheckEvents(CG_EntityPtr(entNum));
        }
    }

    /* line 487: CG_TransitionPlayerState */
    {
        cg_t *cgBase = *(cg_t **)cg_glob;
        int isDemo = cgBase->demoType;

        if (!isDemo)
        {
            char *nextSnap = (char *)cgBase->nextSnap;
            if (!(*(int *)((char *)&((snapshot_t *)nextSnap)->ps.pm_flags + 2) /* ps.pm_flags high word at +2 */ & 0x40))
            {
                /* Check two dvars */
                char *dv1 = cg_dvar1 ? *cg_dvar1 : NULL;
                if (!dv1 || *(char *)(dv1 + 8) == 0)
                {
                    char *dv2 = cg_dvar2 ? *cg_dvar2 : NULL;
                    if (!dv2 || *(char *)(dv2 + 8) == 0)
                        return;
                }
            }
        }

        /* line 488: CG_TransitionPlayerState */
        {
            cg_t *cgBase2 = *(cg_t **)cg_glob;
            char *oldSnap = (char *)cgBase2->snap;
            char *newSnap = (char *)cgBase2->nextSnap;
            CG_TransitionPlayerState((char *)&((snapshot_t *)newSnap)->ps, (char *)&((snapshot_t *)oldSnap)->ps);
        }
    }
}

/* ============================================================
 * CG_SetInitialSnapshot
 * Initializes the first snapshot received.
 * ============================================================ */

/* line 129 */
void CG_SetInitialSnapshot(snapshot_t *snap_param)
{
    char *snap = (char *)snap_param;
    cg_t *cg;
    float clientViewOrigin[3];
    float clientViewAxis[9];

    /* line 137: CG_SetNextSnap(NULL) */
    CG_SetNextSnap(NULL);

    /* line 141-142: cg->snap = snap, cg->nextSnap = snap */
    cg = *(cg_t **)cg_glob;
    cg->snap = (snapshot_t *)snap;
    cg->nextSnap = (snapshot_t *)snap;

    /* line 144-146: set time fields */
    {
        int serverTime = ((snapshot_t *)snap)->serverTime;
        cg->time = serverTime;
        cg->bgs.time = serverTime;
        cg->oldTime = serverTime;
    }

    /* line 148-149: compute clientViewOrigin from ps.origin + viewheight */
    {
        /* VectorCopy(snap->ps.origin, clientViewOrigin) */
        clientViewOrigin[0] = ((snapshot_t *)snap)->ps.origin[0];
        clientViewOrigin[1] = ((snapshot_t *)snap)->ps.origin[1];

        /* line 149: snap->ps.origin[2] + snap->ps.viewHeightCurrent */
        float z;
        /* Use SSE: movss 8(%edx) loads snap + 0x28, then addss 0x104(%ebx) adds snap + 0x104 */
        {
            float origin_z;
            float viewHeight;
            /* Read raw bytes using memcpy for float */
            origin_z = ((snapshot_t *)snap)->ps.origin[2];
            viewHeight = ((snapshot_t *)snap)->ps.viewHeightCurrent;
            clientViewOrigin[2] = origin_z + viewHeight;
        }
    }

    /* line 151: AnglesToAxis(snap->ps.viewangles, clientViewAxis) */
    AnglesToAxis(((snapshot_t *)snap)->ps.viewangles, clientViewAxis);

    /* line 152: SND_SetListener */
    {
        int clientNum = ((snapshot_t *)snap)->ps.clientNum;
        SND_SetListener(clientNum, clientViewOrigin, clientViewAxis);
    }

    /* line 159: SND_FadeAllSounds(1.0f, 0) */
    SND_FadeAllSounds(1.0f, 0);

    /* line 161 */
    CG_Respawn();

    /* line 164 */
    CG_PlaySmokeGrenadesAtTime(cg->time);

    /* line 166 */
    CG_InitView();

    /* line 168: cg->nextSnap = NULL */
    cg->nextSnap = NULL;
}

/* ============================================================
 * CG_ReadNextSnapshot (inlined helper)
 * Reads the next snapshot from the client.
 * ============================================================ */

static char *CG_ReadNextSnapshot(void)
{
    cgs_t *cgs = *(cgs_t **)cgs_glob;
    cg_t *cg = *(cg_t **)cg_glob;
    int snapshotNum;
    int latestNum;
    char *dest;

    latestNum = cg->latestSnapshotNum;
    snapshotNum = cgs->processedSnapshotNum;

    /* line 519: check if way out of range */
    if (latestNum > snapshotNum + 0x3e8)
    {
        Com_Printf("WARNING: CG_ReadNextSnapshot: way out of range, %i > %i\n",
                    latestNum, snapshotNum);
    }

    /* line 522-551 */
    while (snapshotNum < latestNum)
    {
        /* line 525-527: determine which activeSnapshot buffer to use */
        dest = (char *)&cg->activeSnapshots[0];
        if ((char *)cg->snap == dest)
            dest = (char *)&cg->activeSnapshots[1];

        /* line 535-536: advance processedSnapshotNum and get snapshot */
        snapshotNum++;
        cgs->processedSnapshotNum = snapshotNum;

        cgs = *(cgs_t **)cgs_glob;
        if (CL_GetSnapshot(cgs->processedSnapshotNum, dest))
        {
            /* line 541 */
            CG_AddLagometerSnapshotInfo(dest);
            return dest;
        }

        /* line 551: failed to get snapshot */
        CG_AddLagometerSnapshotInfo(NULL);

        cg = *(cg_t **)cg_glob;
        cgs = *(cgs_t **)cgs_glob;
        snapshotNum = cgs->processedSnapshotNum;
        latestNum = cg->latestSnapshotNum;
    }

    return NULL;
}

/* ============================================================
 * CG_ProcessSnapshots
 * Main snapshot processing loop.
 * ============================================================ */

/* line 581 */
void CG_ProcessSnapshots(void)
{
    cg_t *cg;
    int n;
    int cgTime;
    int snapTime;
    char *snap;
    char *curSnap;
    char *nextSnap;

    /* line 587: get current snapshot number */
    cg = *(cg_t **)cg_glob;
    CL_GetCurrentSnapshotNumber(&n, &cg->latestSnapshotTime);

    /* line 588-595 */
    if (n < cg->latestSnapshotNum)
    {
        /* line 590-593: error */
        Com_Error(1, (const char *)"\x15" "CG_ProcessSnapshots: n < cg->latestSnapshotNum");
    }
    cg->latestSnapshotNum = n;

    /* line 598 */
    cg = *(cg_t **)cg_glob;
    cg->bgs.latestSnapshotTime = cg->latestSnapshotTime;

    /* line 603: main processing loop */
    for (;;)
    {
        cg = *(cg_t **)cg_glob;
        curSnap = (char *)cg->snap;

        /* No current snapshot yet: bootstrap both current and next from the
         * first active snapshot so the prediction path always has a snap. */
        if (curSnap == NULL)
        {
            snap = CG_ReadNextSnapshot();
            if (!snap)
                return;

            if (((snapshot_t *)snap)->snapFlags & 2)
            {
                continue;
            }

            CG_SetInitialSnapshot((snapshot_t *)snap);
            CG_SetNextSnap((snapshot_t *)snap);
            CG_TransitionSnapshot_Inline();
            continue;
        }

        nextSnap = (char *)cg->nextSnap;

        if (nextSnap != NULL)
        {
            CG_SetFrameInterpolation();
        }

        /* If we already have a queued future snapshot, either keep
         * interpolating toward it or transition to it when its time arrives. */
        if (nextSnap != NULL && nextSnap != curSnap)
        {
            cg = *(cg_t **)cg_glob;
            curSnap = (char *)cg->snap;
            nextSnap = (char *)cg->nextSnap;
            cgTime = cg->time;

            if (cgTime < ((snapshot_t *)curSnap)->serverTime ||
                cgTime >= ((snapshot_t *)nextSnap)->serverTime)
            {
                CG_TransitionSnapshot_Inline();
                continue;
            }

            return;
        }

        /* Queue the next active snapshot now that the previous transition is
         * complete and both snap pointers refer to the current frame. */
        snap = CG_ReadNextSnapshot();
        if (!snap)
        {
            snapTime = ((snapshot_t *)curSnap)->serverTime;
            if (cg->time < snapTime)
            {
                cg->time = snapTime;
                cg->bgs.time = snapTime;
            }
            return;
        }

        if (((snapshot_t *)snap)->snapFlags & 2)
        {
            continue;
        }

        if ((((snapshot_t *)snap)->snapFlags ^ ((snapshot_t *)curSnap)->snapFlags) & 4)
        {
            CG_SetInitialSnapshot((snapshot_t *)snap);
            CG_SetNextSnap((snapshot_t *)snap);
            CG_TransitionSnapshot_Inline();
            continue;
        }

        if (((snapshot_t *)snap)->serverTime < ((snapshot_t *)curSnap)->serverTime)
        {
            Com_Error(1, (const char *)"\x15" "CG_ProcessSnapshots: Server time went backwards");
        }

        CG_SetNextSnap((snapshot_t *)snap);
    }
}
