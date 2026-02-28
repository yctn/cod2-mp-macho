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
    return *cg_entities_glob + entNum * CENT_STRIDE;
}

/* Helper to compute clientInfo pointer from client number */
static char *CG_ClientInfoPtr(char *cg, int clientNum)
{
    return cg + CG_CLIENTINFO_BASE + 0x14 + clientNum * CI_STRIDE;
}

/* ============================================================
 * CG_ResetEntity
 * Resets a centity when transitioning snapshots.
 * Called with centity pointer (binary layout).
 * ============================================================ */

/* line 47 */
static void CG_ResetEntity(char *cent)
{
    char *cg = *cg_glob;
    char *cgs = *cgs_glob;
    int eType;

    /* line 54: clear lightingOrigin (3 ints at offset 0x204) */
    VectorClear3(cent + CENT_LIGHTINGORIGIN);

    /* line 56: memcpy(cent, cent + 0xf0, 0xf0)
     * Copy nextState over currentState */
    memcpy(cent, cent + ES_BINSIZE, ES_BINSIZE);

    /* line 58-59: clear bTrailMade and cullIn */
    *(char *)(cent + CENT_BTRAILMADE) = 0;
    *(char *)(cent + CENT_CULLIN) = 0;

    /* line 61: BG_EvaluateTrajectory(&cent->nextState.pos, cg->time, &cent->lerpOrigin) */
    BG_EvaluateTrajectory(cent + CENT_NS_POS, *(int *)(cg + CG_TIME), (float *)(cent + CENT_LERPORIGIN));

    /* line 62: BG_EvaluateTrajectory(&cent->nextState.apos, cg->time, &cent->lerpAngles) */
    BG_EvaluateTrajectory(cent + CENT_NS_APOS, *(int *)(cg + CG_TIME), (float *)(cent + CENT_LERPANGLES));

    /* line 64: switch on nextState.eType */
    eType = *(int *)(cent + CENT_NS_ETYPE);

    switch (eType)
    {
    case 0:  /* ET_GENERAL */
    case 4:  /* ET_ITEM */
        /* line 69: cent->previousEventSequence = 0 */
        *(int *)(cent + CENT_PREVIOUSEVENTSEQ) = 0;
        break;

    case 1:  /* ET_PLAYER */
    {
        char *ci;
        int clientNum;

        /* line 73: cent->previousEventSequence = cent->nextState.eventSequence */
        *(int *)(cent + CENT_PREVIOUSEVENTSEQ) = *(int *)(cent + CENT_NS_EVENTSEQUENCE);

        /* line 75: compute clientInfo pointer from nextState.clientNum */
        clientNum = *(int *)(cent + CENT_NS_CLIENTNUM);
        ci = cg + CG_CLIENTINFO_BASE + clientNum * CI_STRIDE;

        /* line 76: ci->legs.oldFrameModel = cent->nextState.index (at 0x15c from cent) */
        /* ci + 0x14 + 0x3e0 = ci + 0x3f4 = leftHandGun offset */
        /* Actually: leal 0x14(%eax), %ecx gets us to ci+0x14 (the "real" clientInfo start)
         * Then 0x3e0(%ecx) = ci + 0x14 + 0x3e0 = ci + 0x3f4
         * In clientInfo_t, offset 0x3f4 = leftHandGun
         * cent + 0x15c = nextState offset 0x6c (from nextState base 0xf0: 0xf0+0x6c=0x15c)
         * entityState offset 0x6c = angles2[0] (angles2 at 0x68, so 0x6c = angles2[1])
         * Hmm, actually 0x15c = 0xf0 + 0x6c. entityState offset 0x6c = angles2[1]
         */
        *(int *)(ci + 0x14 + 0x3e0) = *(int *)(cent + 0x15c);

        /* line 77: ci + 0x14 + 0x3e4 = cent + 0x1c4 (nextState.leanf) */
        *(int *)(ci + 0x14 + 0x3e4) = *(int *)(cent + CENT_NS_LEANF);

        /* line 78: VectorCopy cent->lerpAngles to ci + 0x3fc */
        {
            char *to = ci + 0x3fc;
            VectorCopy3(cent + CENT_LERPANGLES, to);
        }

        /* line 79-80: clear lerpAngles[0] and lerpAngles[2] (or lightingOrigin[0,2]?) */
        /* Actually: 0x1f8 = lerpAngles, 0x200 = lerpAngles + 8 = lerpAngles[2] */
        /* asm: movl $0, 0x1f8(%ebx) and movl $0, 0x200(%ebx) */
        /* lerpAngles[0] = 0 and lerpAngles[2] = 0 */
        *(int *)(cent + CENT_LERPANGLES) = 0;
        *(int *)(cent + CENT_LERPANGLES + 8) = 0;

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
        clientNum = *(int *)(cent + CENT_NS_CLIENTNUM);
        ci = cg + CG_CLIENTINFO_BASE + 0x14 + clientNum * CI_STRIDE;

        /* line 89: compute corpseInfo from currentState.number
         * corpseInfo is in a separate array accessed relative to cgs */
        entNum = *(int *)(cent + CENT_NS_NUMBER);
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
        pXAnimTree = *(void **)(corpseInfo + CI_PXANIMTREE);

        /* line 92: test cent->nextState.eFlags & 8 */
        if (*(int *)(cent + CENT_NS_EFLAGS) & 8)
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
                    if (I_stricmp(tagSrc, (const char *)str_002b7f68) == 0)
                    {
                        *(char *)(modelDst + 0x80) = 0;   /* attachModelNames[i][0] = 0 */
                        *(char *)(modelDst + 0x200) = 0;   /* attachTagNames[i][0] = 0 */
                    }
                    tagSrc += 0x40;
                    modelDst += 0x40;
                }
            }

            /* line 95: restore pXAnimTree */
            *(void **)(corpseInfo + CI_PXANIMTREE) = pXAnimTree;

            /* line 96: XAnimCloneAnimTree(ci->pXAnimTree, pXAnimTree) */
            XAnimCloneAnimTree(*(void **)(ci + CI_PXANIMTREE), pXAnimTree);

            /* line 98: cent->previousEventSequence = 0 */
            *(int *)(cent + CENT_PREVIOUSEVENTSEQ) = 0;
        }
        else
        {
            /* line 103: check corpseInfo->model[0] (at corpseInfo + 0x40) */
            if (*(char *)(corpseInfo + 0x40) != 0)
            {
                /* line 104-105: check if corpseInfo->clientNum != ci->clientNum */
                if (*(int *)(corpseInfo + 0x08) != *(int *)(ci + 0x08))
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
                            if (I_stricmp(tagSrc, (const char *)str_002b7f68) == 0)
                            {
                                *(char *)(modelDst + 0x80) = 0;
                                *(char *)(modelDst + 0x200) = 0;
                            }
                            tagSrc += 0x40;
                            modelDst += 0x40;
                        }
                    }

                    /* line 106: restore pXAnimTree */
                    *(void **)(corpseInfo + CI_PXANIMTREE) = pXAnimTree;
                }
            }

            /* line 109: cent->previousEventSequence = cent->nextState.eventSequence */
            *(int *)(cent + CENT_PREVIOUSEVENTSEQ) = *(int *)(cent + CENT_NS_EVENTSEQUENCE);
        }

        /* line 112: corpseInfo->dobjDirty = 1 */
        *(int *)(corpseInfo + CI_DOBJDIRTY) = 1;
        break;
    }

    default:
        /* line 117: cent->previousEventSequence = cent->nextState.eventSequence */
        *(int *)(cent + CENT_PREVIOUSEVENTSEQ) = *(int *)(cent + CENT_NS_EVENTSEQUENCE);
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
        if (I_stricmp(tagSrc, (const char *)str_002b7f68) == 0)
        {
            *(char *)(dst + 0x80) = 0;
            *(char *)(dst + 0x200) = 0;
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
    char *cg = *cg_glob;
    char *cg_ents = *cg_entities_glob;
    char *snap;
    int numClients, i;

    snap = *(char **)(cg + CG_SNAP);

    /* line 244: process clients in snap->numClients */
    numClients = *(int *)((char *)snap + SNAP_NUMCLIENTS);
    for (i = 0; i < numClients; i++)
    {
        char *clState = (char *)snap + SNAP_CLIENTS + i * CLSTATE_STRIDE;
        int clientNum = *(int *)(clState + 0xc);  /* clientState.clientNum offset */
        char *ci = cg + CG_CLIENTINFO_BASE + 0x14 + clientNum * CI_STRIDE;

        /* line 248: check ci->nextValid */
        if (*(int *)(ci + CI_NEXTVALID) == 0)
        {
            /* line 250: already not valid, just clear nextValid */
            *(int *)(ci + CI_NEXTVALID) = 0;
            continue;
        }
        else
        {
            /* line 253-256: save pXAnimTree, memset ci, restore pXAnimTree, SafeDObjFree */
            void *savedTree = *(void **)(ci + CI_PXANIMTREE);
            memset(ci, 0, CI_STRIDE);
            *(void **)(ci + CI_PXANIMTREE) = savedTree;
            CG_SafeDObjFree(clientNum);
            continue;
        }
    }

    /* line 271: cg->snap = cg->nextSnap */
    *(char **)(cg + CG_SNAP) = *(char **)(cg + CG_NEXTSNAP);

    /* line 273: check if snap->ps.eFlags has teleport bits */
    snap = *(char **)(cg + CG_NEXTSNAP);
    if (*(int *)(snap + SNAP_PS + 0x0c) & 0xc00000)  /* ps.eFlags offset = ps + 0xc? */
    {
        /* line 275: get player entity and copy nextState to currentState */
        int playerEntNum = *(int *)(snap + SNAP_PS_CLIENTNUM);
        char *playerEnt = cg_ents + playerEntNum * CENT_STRIDE;
        memcpy(playerEnt, playerEnt + ES_BINSIZE, ES_BINSIZE);
    }

    /* line 279: for each entity in snap, copy nextState to currentState */
    {
        int numEnts = *(int *)(snap + SNAP_NUMENTITIES);
        for (i = 0; i < numEnts; i++)
        {
            char *snapEnt = snap + SNAP_ENTITIES + i * ES_BINSIZE;
            int entNum = *(int *)(snapEnt + 0xc);  /* entity number in entity data */
            char *cent = cg_ents + entNum * CENT_STRIDE;
            memcpy(cent, cent + ES_BINSIZE, ES_BINSIZE);
        }
    }
}

/* line 297 */
void CG_SetNextSnap(snapshot_t *snap_param)
{
    char centInPrevSnapshot[1024];
    char *snap = (char *)snap_param;
    char *cg = *cg_glob;
    char *cg_ents = *cg_entities_glob;
    char *prevSnap;
    int i;

    /* line 314: clear centInPrevSnapshot */
    memset(centInPrevSnapshot, 0, 0x400);

    /* line 316: get previous snap */
    prevSnap = *(char **)(cg + CG_NEXTSNAP);

    if (prevSnap)
    {
        int numEnts;

        /* line 319: mark entities from previous snap */
        numEnts = *(int *)(prevSnap + SNAP_NUMENTITIES);
        if (numEnts > 0)
        {
            for (i = 0; i < numEnts; i++)
            {
                char *snapEnt = prevSnap + SNAP_ENTITIES + i * ES_BINSIZE;
                int entNum = *(int *)(snapEnt + 0xc);  /* entity number in snap entity */
                char *cent = cg_ents + entNum * CENT_STRIDE;

                /* line 325: cent->nextValid = 0 */
                *(char *)(cent + CENT_NEXTVALID) = 0;

                /* line 326: centInPrevSnapshot[entNum] = 1 */
                centInPrevSnapshot[entNum] = 1;
            }
        }

        /* line 329-333: handle the player's own entity */
        {
            int playerNum = *(int *)(prevSnap + SNAP_PS_CLIENTNUM);
            char *playerEnt = cg_ents + playerNum * CENT_STRIDE;
            if (*(char *)(playerEnt + CENT_NEXTVALID))
            {
                *(char *)(playerEnt + CENT_NEXTVALID) = 0;
                centInPrevSnapshot[playerNum] = 1;
            }
        }
    }

    /* line 337: cg->nextSnap = snap */
    *(char **)(cg + CG_NEXTSNAP) = snap;

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
    CG_ExecuteNewServerCommands(*(int *)(snap + SNAP_SERVERCMDSEQ));

    /* line 355 */
    CG_CheckOpenWaitingScriptMenu();

    /* line 361: process clients */
    {
        int numClients = *(int *)(snap + SNAP_NUMCLIENTS);
        if (numClients > 0)
        {
            for (i = 0; i < numClients; i++)
            {
                char *clState = snap + SNAP_CLIENTS + i * CLSTATE_STRIDE;
                int clientNum;
                char *ci;
                int modelIndex;
                const char *configStr;

                /* line 363: advance past header */
                char *clData = clState + 0xc;  /* skip to client data portion */

                /* line 368: get clientNum from clientState */
                clientNum = *(int *)(clState + 0xc);
                ci = cg + CG_CLIENTINFO_BASE + 0x14 + clientNum * CI_STRIDE;

                /* line 369: check ci->infoValid. If not valid, use clState->oldteam instead */
                if (*(int *)(ci + CI_INFOVALID) == 0)
                    modelIndex = *(int *)(clState + 0x10);  /* oldteam / some field */
                else
                    modelIndex = *(int *)(ci + 0x2c);  /* team field at CI + 0x2c = 0x30 (model count?) */

                /* line 370-373: set ci fields */
                *(int *)(ci + 0x30) = modelIndex;
                *(int *)(ci + CI_INFOVALID) = 1;
                *(int *)(ci + CI_NEXTVALID) = 1;
                *(int *)(ci + CI_CLIENTNUM) = *(int *)(clState + 0xc);
                *(int *)(ci + 0x2c) = *(int *)(clState + 0x10);

                /* line 380: compare ci->name with clData+0x3c (name from clientState) */
                {
                    char *ciName = ci + CI_NAME;
                    char *clName = clState + 0xc + 0x30;  /* clData offset for name */

                    if (strcmp(ciName, clName) != 0)
                    {
                        /* line 382: if ci->name[0] is set, show team change message */
                        if (*(char *)(ci + CI_NAME) != 0)
                        {
                            /* line 383 */
                            const char *translated = UI_SafeTranslateString((const char *)str_002b7f74);
                            const char *msg = va((const char *)str_002b7f88, ciName, translated, clName);
                            CG_GameMessage(msg);
                        }

                        /* line 384: copy new name */
                        I_strncpyz(ciName, clName, 0x20);
                    }
                }

                /* line 387: get config string for model */
                {
                    int configIndex = *(int *)(clState + 0x14);
                    configStr = CL_GetConfigString(configIndex + 0x14e);
                }

                /* line 388: compare ci->model with config string */
                {
                    char *ciModel = ci + CI_MODEL;
                    if (strcmp(ciModel, configStr) != 0)
                    {
                        /* line 390: copy new model */
                        I_strncpyz(ciModel, configStr, 0x40);
                        *(int *)(ci + CI_DOBJDIRTY) = 1;
                    }
                }

                /* line 391-410: process 6 attachment slots */
                {
                    char *clStateSlots = clState + 0xc;  /* start of per-slot data in clientState */
                    int slot;
                    char *ciAttachModel = ci + CI_ATTACHMODELNAMES;
                    char *ciAttachTag = ci + CI_ATTACHTAGNAMES;

                    for (slot = 0; slot < 6; slot++)
                    {
                        /* line 396: get config string for attachment model */
                        int attachModelIdx = *(int *)(clStateSlots + 0x0c);
                        configStr = CL_GetConfigString(attachModelIdx + 0x14e);

                        if (strcmp(ciAttachModel, configStr) != 0)
                        {
                            /* line 399: copy new attachment model name */
                            I_strncpyz(ciAttachModel, configStr, 0x40);
                            *(int *)(ci + CI_DOBJDIRTY) = 1;
                        }

                        /* line 403: get config string for attachment tag */
                        {
                            int attachTagIdx = *(int *)(clStateSlots + 0x24);
                            const char *tagStr = CL_GetConfigString(attachTagIdx + 0x6e);

                            if (strcmp(ciAttachTag, tagStr) != 0)
                            {
                                /* line 406: copy new attachment tag name */
                                I_strncpyz(ciAttachTag, tagStr, 0x40);
                                *(int *)(ci + CI_DOBJDIRTY) = 1;
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
    cg = *cg_glob;
    {
        char *cgBase = cg;
        *(int *)(cgBase + 0x2bddc) = *(int *)(snap + 0x144);
        *(int *)(cgBase + 0x2bde0) = *(int *)(snap + 0x148);
    }

    /* line 415: get entnum from ps */
    {
        int entnum = *(int *)(snap + SNAP_PS_CLIENTNUM);

        /* line 417: check ps.eFlags for teleport bits */
        if (*(int *)(snap + SNAP_PS + 0x0c) & 0xc00000)
        {
            /* line 419-422: player entity state conversion */
            char *playerEnt = CG_EntityPtr(entnum);

            /* line 420: set nextState.number = entnum (lower 16 bits) */
            *(int *)(playerEnt + CENT_NS_NUMBER) = (unsigned short)entnum;

            /* line 421: BG_PlayerStateToEntityState */
            BG_PlayerStateToEntityState(snap + SNAP_PS, playerEnt + ES_BINSIZE, 0, 0);

            /* line 422: set nextValid = 1 */
            *(char *)(playerEnt + CENT_NEXTVALID) = 1;

            /* line 424-434: check mapRestart and handle player reset */
            {
                char *cgBase = *cg_glob;
                char *oldSnap = *(char **)(cgBase + CG_SNAP);

                if (*(int *)(cgBase + CG_MAPRESTART) || *(int *)(snap + SNAP_PS + 0x140) != *(int *)(oldSnap + SNAP_PS + 0x140))
                {
                    /* line 426/432: copy ps to old snap's ps */
                    memcpy(oldSnap + SNAP_PS, snap + SNAP_PS, 0x26a8);

                    /* line 427/433: CG_ResetEntity */
                    CG_ResetEntity(playerEnt);

                    if (*(int *)(cgBase + CG_MAPRESTART) || !centInPrevSnapshot[entnum] ||
                        (*(int *)(playerEnt + 0x8) ^ *(int *)(playerEnt + CENT_NS_EFLAGS)) & 2)
                    {
                        /* Just reset, already done */
                    }

                    /* Check if we need Respawn */
                    if (*(int *)(cgBase + CG_MAPRESTART))
                    {
                        CG_Respawn();
                        /* line 434: clear predictedError */
                        VectorClear3(cgBase + CG_PREDICTEDERROR);
                    }
                    else
                    {
                        /* Non-mapRestart but ps changed */
                        CG_Respawn();
                    }
                }
                else if (entnum != *(int *)(oldSnap + SNAP_PS_CLIENTNUM))
                {
                    /* Different client num: also need full transition */
                    memcpy(oldSnap + SNAP_PS, snap + SNAP_PS, 0x26a8);
                    CG_Respawn();
                }
                else
                {
                    /* Same client, check centInPrevSnapshot */
                    if (!centInPrevSnapshot[entnum] || (*(int *)(playerEnt + 0x8) ^ *(int *)(playerEnt + CENT_NS_EFLAGS)) & 2)
                    {
                        /* Need reset */
                        memcpy(oldSnap + SNAP_PS, snap + SNAP_PS, 0x26a8);
                        CG_ResetEntity(playerEnt);
                        VectorClear3(cgBase + CG_PREDICTEDERROR);
                    }
                    /* else: no changes needed */
                }
            }
        }
        else
        {
            /* No teleport flags */
            char *cgBase = *cg_glob;
            char *oldSnap = *(char **)(cgBase + CG_SNAP);

            if (*(int *)(cgBase + CG_MAPRESTART))
            {
                /* mapRestart: copy and respawn */
                memcpy(oldSnap + 0xc, snap + 0xc, 0x26a8);
                CG_Respawn();
            }
            else
            {
                /* Check if ps has changed */
                if (*(int *)(snap + SNAP_PS + 0x140) != *(int *)(oldSnap + SNAP_PS + 0x140))
                {
                    memcpy(oldSnap + 0xc, snap + 0xc, 0x26a8);
                    CG_Respawn();
                }
                else if (entnum != *(int *)(oldSnap + SNAP_PS_CLIENTNUM))
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
        int numEnts = *(int *)(snap + SNAP_NUMENTITIES);
        for (i = 0; i < numEnts; i++)
        {
            char *snapEnt = snap + SNAP_ENTITIES + i * ES_BINSIZE;
            int entNum = *(int *)(snapEnt + 0xc);  /* entity number */
            char *cent = CG_EntityPtr(entNum);

            /* line 451: copy snap entity to cent->nextState */
            memcpy(cent + ES_BINSIZE, snapEnt, ES_BINSIZE);

            /* line 453: cent->nextValid = 1 */
            *(char *)(cent + CENT_NEXTVALID) = 1;

            /* line 457: check if entity was in prev snapshot */
            if (centInPrevSnapshot[entNum])
            {
                /* Check if eFlags changed for bit 2 */
                if ((*(int *)(cent + CENT_CS_EFLAGS) ^ *(int *)(snapEnt + 0x08)) & 2)
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
        int numClients = *(int *)(snap + SNAP_NUMCLIENTS);
        for (i = 0; i < numClients; i++)
        {
            char *clState = snap + SNAP_CLIENTS + i * CLSTATE_STRIDE;
            int clientNum = *(int *)(clState + 0xc);
            CG_UpdatePlayerDObj(CG_EntityPtr(clientNum));
        }
    }

    /* line 465: update view model */
    {
        int viewModelIndex = *(int *)(snap + SNAP_PS + 0xe4);  /* ps.viewmodelIndex */
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
        char *cgBase = *cg_glob;
        int gunInit = *(int *)(cgBase + CG_FIRSTPERSONGUNINIT);
        char *nextSnap;

        if (!gunInit)
        {
            nextSnap = *(char **)(cgBase + CG_NEXTSNAP);
            int hasGun = *(int *)(nextSnap + 0x7b0);  /* ps.weapon or similar */

            if (hasGun)
            {
                /* line 185: set firstPersonGunInit = 1 */
                *(int *)(cgBase + CG_FIRSTPERSONGUNINIT) = 1;

                /* line 188 */
                CG_SetEquippedOffHand(0);

                /* line 191 */
                CG_PlaySmokeGrenadesAtTime(*(int *)(cgBase + CG_TIME));
            }
        }

        if (gunInit || (*(int *)(*(char **)(cgBase + CG_NEXTSNAP) + 0x7b0) != 0))
        {
            /* line 200: play smoke grenades and handle corpse anim trees */
            nextSnap = *(char **)(cgBase + CG_NEXTSNAP);
            if (*(int *)(nextSnap + 0x7b0) == 0)
            {
                /* line 197: clear firstPersonGunInit */
                *(int *)(cgBase + CG_FIRSTPERSONGUNINIT) = 0;

                /* line 200 */
                cgBase = *cg_glob;
                CG_PlaySmokeGrenadesAtTime(*(int *)(cgBase + CG_TIME));

                /* line 202-218: process entities for corpse anim trees */
                {
                    int numEnts;
                    nextSnap = *(char **)(cgBase + CG_NEXTSNAP);
                    numEnts = *(int *)(nextSnap + SNAP_NUMENTITIES);

                    for (i = 0; i < numEnts; i++)
                    {
                        char *snapEnt = nextSnap + SNAP_ENTITIES + i * ES_BINSIZE;
                        int entNum = *(int *)(snapEnt + 0xc);
                        char *cent = CG_EntityPtr(entNum);

                        /* line 206: check if eType == 2 (corpse) */
                        if (*(int *)(cent + CENT_NS_ETYPE) != 2)
                            continue;

                        /* line 211: get corpseInfo for this entity */
                        {
                            char *cgs_ptr = *cgs_glob;
                            int csNum = *(int *)(cent + CENT_NS_NUMBER);
                            char *corpseBase = cgs_ptr + csNum * CI_STRIDE - 0x6bf0;
                            char *corpseCI = corpseBase + 4;

                            /* line 212: save pXAnimTree */
                            void *savedTree = *(void **)(corpseCI + CI_PXANIMTREE);

                            /* line 214: get animation state, mask out bit 9 */
                            int animState = *(int *)(corpseCI + 0x390) & ~0x200;

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
        int numEnts = *(int *)(snap + SNAP_NUMENTITIES);
        for (i = 0; i < numEnts; i++)
        {
            char *snapEnt = snap + SNAP_ENTITIES + i * ES_BINSIZE;
            int entNum = *(int *)(snapEnt + 0xc);
            CG_CheckEvents(CG_EntityPtr(entNum));
        }
    }

    /* line 487: CG_TransitionPlayerState */
    {
        char *cgBase = *cg_glob;
        int isDemo = *(int *)(cgBase + CG_DEMOTYPE);

        if (!isDemo)
        {
            char *nextSnap = *(char **)(cgBase + CG_NEXTSNAP);
            if (!(*(int *)(nextSnap + SNAP_PS + 0x0e) & 0x40))
            {
                /* Check two dvars */
                char *dv1 = *cg_dvar1;
                if (*(char *)(dv1 + 8) == 0)
                {
                    char *dv2 = *cg_dvar2;
                    if (*(char *)(dv2 + 8) == 0)
                        return;
                }
            }
        }

        /* line 488: CG_TransitionPlayerState */
        {
            char *cgBase2 = *cg_glob;
            char *oldSnap = *(char **)(cgBase2 + CG_SNAP);
            char *newSnap = *(char **)(cgBase2 + CG_NEXTSNAP);
            CG_TransitionPlayerState(newSnap + SNAP_PS, oldSnap + SNAP_PS);
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
    char *cg;
    float clientViewOrigin[3];
    float clientViewAxis[9];

    /* line 137: CG_SetNextSnap(NULL) */
    CG_SetNextSnap(NULL);

    /* line 141-142: cg->snap = snap, cg->nextSnap = snap */
    cg = *cg_glob;
    *(char **)(cg + CG_SNAP) = snap;
    *(char **)(cg + CG_NEXTSNAP) = snap;

    /* line 144-146: set time fields */
    {
        int serverTime = *(int *)(snap + SNAP_SERVERTIME);
        *(int *)(cg + CG_TIME) = serverTime;
        *(int *)(cg + CG_LATESTSERVERTIME) = serverTime;
        *(int *)(cg + CG_OLDTIME) = serverTime;
    }

    /* line 148-149: compute clientViewOrigin from ps.origin + viewheight */
    {
        /* VectorCopy(snap->ps.origin, clientViewOrigin) */
        clientViewOrigin[0] = *(float *)(snap + 0x20);
        clientViewOrigin[1] = *(float *)(snap + 0x24);

        /* line 149: snap->ps.origin[2] + snap->ps.viewHeightCurrent */
        float z;
        /* Use SSE: movss 8(%edx) loads snap + 0x28, then addss 0x104(%ebx) adds snap + 0x104 */
        {
            float origin_z;
            float viewHeight;
            /* Read raw bytes using memcpy for float */
            memcpy(&origin_z, snap + 0x28, sizeof(float));
            memcpy(&viewHeight, snap + 0x104, sizeof(float));
            clientViewOrigin[2] = origin_z + viewHeight;
        }
    }

    /* line 151: AnglesToAxis(snap->ps.viewangles, clientViewAxis) */
    AnglesToAxis((float *)(snap + 0xf4), clientViewAxis);

    /* line 152: SND_SetListener */
    {
        int clientNum = *(int *)(snap + SNAP_PS_CLIENTNUM);
        SND_SetListener(clientNum, clientViewOrigin, clientViewAxis);
    }

    /* line 159: SND_FadeAllSounds(1.0f, 0) */
    SND_FadeAllSounds(1.0f, 0);

    /* line 161 */
    CG_Respawn();

    /* line 164 */
    CG_PlaySmokeGrenadesAtTime(*(int *)(cg + CG_TIME));

    /* line 166 */
    CG_InitView();

    /* line 168: cg->nextSnap = NULL */
    *(char **)(cg + CG_NEXTSNAP) = NULL;
}

/* ============================================================
 * CG_ReadNextSnapshot (inlined helper)
 * Reads the next snapshot from the client.
 * ============================================================ */

static char *CG_ReadNextSnapshot(void)
{
    char *cgs = *cgs_glob;
    char *cg = *cg_glob;
    int snapshotNum;
    int latestNum;
    char *dest;

    latestNum = *(int *)(cg + CG_LATESTSNAPSHOTNUM);
    snapshotNum = *(int *)(cgs + CGS_PROCESSEDSNAPSHOTNUM);

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
        dest = cg + CG_ACTIVESNAPSHOTS;
        if (*(char **)(cg + CG_SNAP) == dest)
            dest = cg + CG_ACTIVESNAPSHOTS + SNAP_SIZE;

        /* line 535-536: advance processedSnapshotNum and get snapshot */
        snapshotNum++;
        *(int *)(cgs + CGS_PROCESSEDSNAPSHOTNUM) = snapshotNum;

        cgs = *cgs_glob;
        if (CL_GetSnapshot(*(int *)(cgs + CGS_PROCESSEDSNAPSHOTNUM), dest))
        {
            /* line 541 */
            CG_AddLagometerSnapshotInfo(dest);
            return dest;
        }

        /* line 551: failed to get snapshot */
        CG_AddLagometerSnapshotInfo(NULL);

        cg = *cg_glob;
        cgs = *cgs_glob;
        snapshotNum = *(int *)(cgs + CGS_PROCESSEDSNAPSHOTNUM);
        latestNum = *(int *)(cg + CG_LATESTSNAPSHOTNUM);
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
    char *cg;
    int n;
    int serverTime;
    char *snap;

    /* line 587: get current snapshot number */
    cg = *cg_glob;
    CL_GetCurrentSnapshotNumber(&n, (int *)(cg + CG_LATESTSNAPSHOTTIME));

    /* line 588-595 */
    if (n < *(int *)(cg + CG_LATESTSNAPSHOTNUM))
    {
        /* line 590-593: error */
        Com_Error(1, (const char *)str_002b7f94);
    }
    *(int *)(cg + CG_LATESTSNAPSHOTNUM) = n;

    /* line 598 */
    cg = *cg_glob;
    *(int *)(cg + CG_SERVERTIME2) = *(int *)(cg + CG_LATESTSNAPSHOTTIME);

    /* line 603: main processing loop */
    for (;;)
    {
        cg = *cg_glob;

        /* Check if we have a snap but no nextSnap */
        if (*(char **)(cg + CG_SNAP) == NULL)
        {
            /* No snap at all: read next */
            snap = CG_ReadNextSnapshot();
            if (!snap)
                return;

            /* line 614: check snapFlags for not-active bit */
            if (*(char *)snap & 2)
            {
                /* Not active, continue loop */
                continue;
            }

            /* line 616-617: initial snapshot setup */
            CG_SetInitialSnapshot((snapshot_t *)snap);
            CG_SetNextSnap((snapshot_t *)snap);

            /* Run CG_TransitionSnapshot inline (lines 244-292) */
            CG_TransitionSnapshot_Inline();

            /* line 279: copy currentState from nextState for all entities */
            /* (already done in CG_TransitionSnapshot_Inline) */
            continue;
        }

        if (*(char **)(cg + CG_NEXTSNAP) != NULL)
        {
            /* line 633: have both snap and nextSnap */
            CG_SetFrameInterpolation();

            /* line 641: check if nextSnap == snap (transitioning complete) */
            cg = *cg_glob;
            if (*(char **)(cg + CG_NEXTSNAP) == *(char **)(cg + CG_SNAP))
            {
                /* Already at the same snapshot */
            }
            else
            {
                /* line 643: check frameInterpolation */
                int interp = *(int *)(cg + 0xc);  /* cubemapShot/demo related field? */
                if (!interp)
                {
                    /* Need to transition and get next */
                    goto read_and_set;
                }
            }

            /* Read next snapshot */
            snap = CG_ReadNextSnapshot();
            if (!snap)
            {
                /* line 678: no more snapshots, check time */
                cg = *cg_glob;
                {
                    char *curSnap = *(char **)(cg + CG_SNAP);
                    int snapTime = *(int *)(curSnap + SNAP_SERVERTIME);
                    if (*(int *)(cg + CG_TIME) < snapTime)
                    {
                        *(int *)(cg + CG_TIME) = snapTime;
                        *(int *)(cg + CG_LATESTSERVERTIME) = snapTime;
                    }
                }
                return;
            }

            /* line 647: got a snapshot */
            /* line 653: check if snapFlags changed (bit 4) */
            cg = *cg_glob;
            {
                char *oldNextSnap = *(char **)(cg + CG_NEXTSNAP);
                if ((*(int *)snap ^ *(int *)oldNextSnap) & 4)
                {
                    /* line 655-656: reinitialize */
                    CG_SetInitialSnapshot((snapshot_t *)snap);
                    CG_SetNextSnap((snapshot_t *)snap);

                    /* Run CG_TransitionSnapshot */
                    CG_TransitionSnapshot_Inline();
                    continue;
                }

                /* line 661: check that snap time hasn't gone backwards */
                if (*(int *)(snap + SNAP_SERVERTIME) < *(int *)(oldNextSnap + SNAP_SERVERTIME))
                {
                    Com_Error(1, (const char *)str_002b8000);
                }
            }

            /* line 664: set next snap */
            CG_SetNextSnap((snapshot_t *)snap);

            /* Check for transition needed (lines 668+) */
            cg = *cg_glob;
            {
                int cgTime = *(int *)(cg + CG_TIME);
                char *curSnap = *(char **)(cg + CG_SNAP);
                char *nextSnap = *(char **)(cg + CG_NEXTSNAP);

                if (cgTime < *(int *)(curSnap + SNAP_SERVERTIME))
                    goto do_transition;

                if (cgTime < *(int *)(nextSnap + SNAP_SERVERTIME))
                    return;

                do_transition:
                /* Need to transition */
                CG_TransitionSnapshot_Inline();
                continue;
            }
        }
        else
        {
            /* Have snap but no nextSnap */
            read_and_set:
            snap = CG_ReadNextSnapshot();
            if (!snap)
                return;

            /* line 606: check snapFlags bit 2 */
            if (*(char *)snap & 2)
            {
                /* Not active, continue */
                continue;
            }

            /* line 616-617 */
            CG_SetInitialSnapshot((snapshot_t *)snap);
            CG_SetNextSnap((snapshot_t *)snap);

            CG_TransitionSnapshot_Inline();
            continue;
        }
    }
}
