/* Converted to C from ASM: cg_event_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_event_mp.cpp */

#include "common_types.h"
#include "imports.h"

/*
 * NOTE: The binary uses different struct sizes than common_types.h:
 *   - entityState_t is 0xf0 (240) bytes in binary vs 0xec (236) in C
 *   - centity_s is 0x224 (548) bytes in binary vs 0x220 (544) in C
 * Therefore all struct accesses use byte-offset pointer arithmetic
 * with the actual binary offsets.
 */

/* External globals (pointers-to-pointers, accessed via absolute addresses in binary) */
extern char **cg_glob;            /* imp_cg -- pointer to cg_t base */
extern char **cgs_glob;           /* imp_cgs -- pointer to cgs_t base */
extern char **cg_weaponDefs;      /* imp_cg_weapons -- pointer to weapon defs base */
extern char **cg_entities_glob;   /* imp_cg_entities -- pointer to centity array base */
extern char **cg_itemDefs;        /* imp_cg_items -- pointer to item defs base */
extern char **cg_dvar_debug;      /* imp_cg_debugEvents -- debug event dvar */
extern char **cg_dvar_footsteps;  /* imp_cg_footsteps -- footstep dvar */
extern char **cg_eventNames;      /* imp_eventnames -- event name strings array */
extern char **cg_uiglob;          /* imp_legacyHacks -- pointer to UI globals base */
extern char **cg_dvar_shellshock_min; /* imp_bg_fallDamageMinHeight -- shellshock min dvar */
extern char **cg_dvar_shellshock_max; /* imp_bg_fallDamageMaxHeight -- shellshock max dvar */
extern int  **cg_itemCount;       /* imp_bg_numItems -- max item count */
extern char **cg_itemInfo;        /* imp_bg_itemlist -- item info base */
extern char **cg_dvar1;           /* imp_cg_nopredict */
extern char **cg_dvar2;           /* imp_cg_synchronousClients */

/* External function declarations */
extern void Com_Printf(const char *msg, ...);
extern void Com_DPrintf(const char *msg, ...);
extern void Com_Error(int level, const char *msg, ...);
extern void *BG_GetWeaponDef(int weapon);
extern int BG_WeaponIsClipOnly(int weapon);
extern void CG_PlayEntitySoundAlias(int entNum, int alias);
extern void CG_PlaySoundAlias(int entNum, void *origin, int alias);
extern void CG_PlaySoundAliasByName(int entNum, void *origin, const char *name);
extern void CG_PlaySoundAliasAsMasterByName(int entNum, void *origin, const char *name);
extern void CG_FireWeapon(centity_t *cent, int weaponId, int hand);
extern void CG_EjectWeaponBrass(entityState_t *es, int weaponId);
extern void CG_PrepOffHand(entityState_t *es, int weaponId, int eventParm);
extern void CG_UseOffHand(centity_t *cent, int weaponId, int eventParm);
extern void CG_SetEquippedOffHand(int weaponId);
extern void CG_SelectWeaponIndex(int weaponId);
extern void CG_OutOfAmmoChange(void);
extern void CG_SwitchOffHandCmd(void);
extern void CG_MenuShowNotify(int val);
extern void CG_StartShakeCamera(float intensity, void *origin, int radius, float duration);
extern void CG_BulletHitEvent(int otherEntNum, void *position, void *dir, void *reflect, int surfType, int event);
extern void CG_BulletHitClientEvent(int otherEntNum, void *position, int surfType, int event);
extern void CG_CompassAddWeaponPingInfo(void *ent, void *position, int duration);
extern void CG_PriorityCenterPrint(const char *msg, float scale, int priority);
extern void CL_DeathMessagePrint(const char *attackerName, float *attackerColor, const char *targetName, float *victimColor, const char *iconShader, float iconWidth, float iconHeight, float *iconColor, int iconHorzFlip);
extern void CG_DrawScoreboard_GetTeamColor(int team, float *color);
extern void CL_SetADS(int val);
extern void CG_CalcEntityLerpPositions(centity_t *cent);
extern void CG_CheckOpenWaitingScriptMenu(void);
extern void ByteToDir(int dirByte, float *dir);
extern void AngleVectors(float *angles, float *forward, void *right, float *up);
extern void FX_PlayEffect(int effectId, void *origin, float *dir);
extern void FX_PlayEntityEffect(int effectId, void *origin, int boneIndex, int *entityInfo);
extern void FX_WarpTime(int time);
extern int FX_GetBoneIndex(int entNum, int tagName);
extern const char *CL_GetConfigString(int index);
extern unsigned short SL_GetString(const char *str, int a2);
extern void Scr_SetString(unsigned short *str, int a2);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void I_strncat(char *dest, int maxlen, const char *src);
extern const char *va(const char *fmt, ...);

/* entityState_s field offsets (0xf0-byte struct in binary) */
#define ES_NUMBER       0x00
#define ES_ETYPE        0x04
#define ES_EFLAGS       0x08
#define ES_APOS_BASE    0x3c  /* apos.trBase (vec3_t) */
#define ES_TIME         0x54
#define ES_ORIGIN2      0x5c
#define ES_ANGLES2      0x68
#define ES_OTHERENTNUM  0x74
#define ES_ATTACKERENTNUM 0x78
#define ES_SURFTYPE     0x88
#define ES_INDEX        0x8c
#define ES_CLIENTNUM    0x90
#define ES_EVENTPARM    0xa0
#define ES_EVENTSEQ     0xa4
#define ES_WEAPON       0xc8
#define ES_LEANF        0xd4
#define ES_DMGFLAGS     0xd8

/* centity_s field offsets */
#define CENT_NEXTSTATE  0xf0
#define CENT_EVPARM     0x190  /* nextState.eventParm (for CG_CheckEvents) */
#define CENT_EVSEQ      0x194  /* nextState.eventSequence */
#define CENT_EVENTS     0x198  /* nextState.events[4] */
#define CENT_EVPARMS    0x1a8  /* nextState.eventParms[4] */
#define CENT_NEXTVALID  0x1e0
#define CENT_PREVEVSEQ  0x1e4
#define CENT_MISCTIME   0x1e8
#define CENT_LERPORIGIN 0x1ec  /* position */
#define CENT_ETYPE      0xf4   /* nextState.eType */

/* cg_t field offsets */
#define CG_SNAP         0x24
#define CG_LOCALCLIENT  0x04
#define CG_FIELD_8      0x08
#define CG_CLIENTNUM    0x25c90
#define CG_TIME         0x25bb0
#define CG_SHELLSHOCK_VIEWANGLE 0x284d0
#define CG_SHELLSHOCK_TILT   0x284d8
#define CG_SHELLSHOCK_TIME   0x284dc
#define CG_VEHFLAG      0x2bee8
#define CG_DEATHFADE     0x2cd14
#define CG_KILLCAM_NAME  0x2b54c
#define CG_OFFHAND       0x2be70
#define CG_OFFHAND2      0x2be50
#define CG_CLIENTINFO    0xe0900

/* snapshot field offsets */
#define SNAP_FLAGS      0x18
#define SNAP_PS_CLIENTNUM 0xd8
#define SNAP_PS_WEAPON    0x5a0

/* cgs_t field offsets */
/* Sound alias table: various arrays at offsets in cgs_t */
#define CGS_SND_FOOTSTEP1_FIRST       0xbeb8   /* first person footsteps set 1 */
#define CGS_SND_FOOTSTEP1_THIRD       0xbf14   /* third person footsteps set 1 */
#define CGS_SND_FOOTSTEP2_THIRD       0xbf70   /* third person footsteps set 2 */
#define CGS_SND_FOOTSTEP2_FIRST       0xbfcc   /* first person footsteps set 2 */
#define CGS_SND_FOOTSTEP3_FIRST       0xc028   /* first person footsteps set 3 */
#define CGS_SND_FOOTSTEP3_THIRD       0xc084   /* third person footsteps set 3 */
#define CGS_SND_SPRINT_FIRST          0xc0e0   /* first person sprint */
#define CGS_SND_SPRINT_THIRD          0xc13c   /* third person sprint */
#define CGS_SND_PRONE_LOOP_3P         0xc198   /* third person prone loop */
#define CGS_SND_PRONE_LOOP_1P_NONVIEW 0xc19c   /* first person prone loop (non-viewer) */
#define CGS_SND_PRONE_LOOP_1P_VIEW    0xc1a0   /* first person prone loop (viewer) */
#define CGS_SND_PRONE_STOP_1P         0xc1a4   /* first person prone stop */
#define CGS_SND_WEAPON_PICKUP         0xc1a8   /* weapon pickup */
#define CGS_SND_NIGHTVISION_ON        0xc1b8   /* nightvision on */
#define CGS_SND_NIGHTVISION_OFF       0xc1bc   /* nightvision off */
#define CGS_SND_NOAMMO                0xbc84   /* no ammo click */
#define CGS_SND_MELEE_HIT             0xbc88   /* melee hit */
#define CGS_SND_BULLET_WHIZBY         0xbc90   /* bullet whizby sounds (array) */
#define CGS_SND_BULLET_FLESH          0xbcec   /* bullet flesh sounds (array) */
#define CGS_SND_GRENADE_BOUNCE        0xbd48   /* grenade bounce sounds (array) */
#define CGS_FXLOOKUP                  0xc200   /* fx lookup table */
#define CGS_FX_CUSTOM                 0x5f80   /* custom fx (configstring-based) */
#define CGS_FX_DEATHFX                0x67c0   /* death fx array */

/* weaponDef field offsets (used for weapon sound lookups) */
/* These are offsets within the weapon-indexed data structure */

/* Item-related offset calculations */
/* item stride: index * (index*2*5 + 1) * 4... actually: index * 0x6d * 4 = index * 0x1b4 */
/* weapon data stride: weapon * (weapon*2+weapon*2*8+weapon) * 4 */

/* Float constants from rodata */
static const float f_0_01   = 0.009999999776482582f;
static const float f_4_0    = 4.0f;
static const float f_12_0   = 12.0f;
static const float f_24_0   = 24.0f;
static const float f_26_0   = 26.0f;
static const float f_100_0  = 100.0f;
static const float f_0_9    = 0.8999999761581421f;
static const float f_neg16  = -16.0f;
static const float f_1_4    = 1.399999976158142f;
static const float f_2_8    = 2.799999952316284f;

/* Helper: compute weapon data offset for weapon index */
/* (%ecx, %ecx, 2) -> ecx*3, (%eax, %eax, 8) -> eax*9, so ecx*3*9=ecx*27, then (ecx + ecx*27*4) = ecx*(1+108)=ecx*109 */
/* Actually: lea (%ecx,%ecx,2),%eax => eax=ecx*3; lea (%eax,%eax,8),%eax => eax=ecx*3*9=ecx*27; lea (%ecx,%eax,4),%eax => eax=ecx+ecx*27*4=ecx*109=ecx*0x6d */
#define WEAPON_DATA_STRIDE 109

static int weaponDataOffset(int weapon) {
    return weapon * WEAPON_DATA_STRIDE;
}

/* Forward declarations */
void CG_EntityEvent(centity_t *cent, int event);
void CG_CheckEvents(centity_t *cent);

/*
 * Helper: CG_PlayFootstepWithProne
 * Plays a prone movement sound based on isFirstPerson flag.
 * entNum = es->number
 * isFirstPerson = 1 if viewer is this entity, 0 otherwise
 */
static void PlayProneSound(int entNum, int isFirstPerson, int soundOffset) {
    char *cgs = *cgs_glob;
    int alias = *(int *)(cgs + soundOffset);
    CG_PlayEntitySoundAlias(entNum, alias);
}

/* line 346 */
void CG_EntityEvent(centity_t *cent, int event)
{
    char *es;           /* nextState pointer */
    char *position;     /* lerpOrigin pointer */
    int eventParm;
    int clientNum;
    int isFirstPerson;  /* flag: this entity is the viewer's entity */
    int isViewerFlag;   /* flag: related to viewer entity check */
    int entNum;
    float dir[3];
    float reflect[3];
    float forward[3];   /* reused as attackerColor in some paths */
    float up[3];        /* reused as iconColor in some paths */
    char *cgs;
    char *cg;
    char *snap;
    int idx;
    int weapon;

    /* Obituary-related locals */
    float attackerColor[4];
    float victimColor[4];
    float iconColor[4];
    int target;
    int attacker;
    char targetName[34];    /* 0x22 bytes */
    char attackerName[34];  /* 0x22 bytes */
    float iconWidth;
    const char *iconShader;
    int iconHorzFlip;
    char *victimCI;
    char *attackerCI;
    unsigned short tagName;
    int boneIndex;

    /* line 361 */
    if (event == 0) {
        /* line 363 */
        cg = *((char **)cg_dvar_debug);
        if (*(char *)(cg + 8) != 0) {
            /* "CG_EntityEvent: NULL\n" */
            Com_Printf((const char *)str_002b83c8);
        }
        return;
    }

    /* line 368 */
    position = (char *)cent + CENT_LERPORIGIN;
    /* line 370 */
    es = (char *)cent + CENT_NEXTSTATE;
    /* line 371 */
    eventParm = *(int *)(es + ES_EVENTPARM);

    /* line 372: check if this entity is the viewer */
    cg = *cg_glob;
    snap = *(char **)(cg + CG_SNAP);
    isFirstPerson = 0;
    isViewerFlag = 0;
    if (*(int *)(snap + SNAP_FLAGS) & 0xc00000) {
        int esNumber = *(int *)(es + ES_NUMBER);
        if (esNumber == *(int *)(snap + SNAP_PS_CLIENTNUM)) {
            isFirstPerson = 1;
            isViewerFlag = 1;
        }
    }

    /* line 374: debug event printing */
    cg = *((char **)cg_dvar_debug);
    if (*(char *)(cg + 8) != 0) {
        /* "ent:%3i  event:%3i " */
        Com_Printf((const char *)str_002b83e4, *(int *)(es + ES_NUMBER), event);
        /* line 380 */
        cg = *((char **)cg_dvar_debug);
        if (*(char *)(cg + 8) != 0) {
            /* "CG_EntityEvent:%s\n" */
            char **eventNames = (char **)(*cg_eventNames);
            Com_Printf((const char *)str_002b83f8, eventNames[event]);
        }
    }

    /* line 383 */
    clientNum = *(int *)(es + ES_CLIENTNUM);
    /* line 384 */
    if ((unsigned int)clientNum >= 0x40) {
        clientNum = 0;
    }

    /* line 387 */
    weapon = *(int *)(es + ES_WEAPON);
    if (weapon != 0) {
        BG_GetWeaponDef(weapon);
    }

    /* line 389: main event dispatch */
    if (event >= 1 && event <= 23) {
        /* Footstep sounds set 1 (events 1-23) */
        int sndIdx = event - 1;

        /* line 391 */
        cg = *((char **)cg_dvar_footsteps);
        if (*(char *)(cg + 8) != 0) {
            /* line 393 */
            cgs = *cgs_glob;
            if (isFirstPerson) {
                /* line 394: third person sound */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(cgs + CGS_SND_FOOTSTEP1_THIRD + sndIdx * 4));
            } else {
                /* line 396: first person sound */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(cgs + CGS_SND_FOOTSTEP1_FIRST + sndIdx * 4));
            }
        }

        /* line 398 */
        entNum = *(int *)(es + ES_NUMBER);

        /* Prone movement sound (lines 268-280) */
        cgs = *cgs_glob;
        if (isViewerFlag) {
            /* line 271 */
            CG_PlayEntitySoundAlias(entNum, *(int *)(cgs + CGS_SND_PRONE_LOOP_1P_NONVIEW));
        } else {
            /* line 278 */
            CG_PlayEntitySoundAlias(entNum, *(int *)(cgs + CGS_SND_PRONE_LOOP_3P));
        }
        return;
    }

    if (event >= 24 && event <= 46) {
        /* Footstep sounds set 2 (events 24-46) */
        int sndIdx = event - 24;

        /* line 403 */
        cg = *((char **)cg_dvar_footsteps);
        if (*(char *)(cg + 8) != 0) {
            cgs = *cgs_glob;
            if (isFirstPerson) {
                /* line 405-406: first person */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(cgs + CGS_SND_FOOTSTEP2_FIRST + sndIdx * 4));
            } else {
                /* line 408: third person */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(cgs + CGS_SND_FOOTSTEP2_THIRD + sndIdx * 4));
            }
        }

        /* line 410 */
        entNum = *(int *)(es + ES_NUMBER);

        /* Prone sound */
        cgs = *cgs_glob;
        if (isViewerFlag) {
            /* line 273 */
            CG_PlayEntitySoundAlias(entNum, *(int *)(cgs + CGS_SND_PRONE_STOP_1P));
        } else {
            /* line 280 */
            CG_PlayEntitySoundAlias(entNum, *(int *)(cgs + CGS_SND_PRONE_LOOP_1P_VIEW));
        }
        return;
    }

    if (event >= 47 && event <= 69) {
        /* Footstep sounds set 3 (events 47-69) */
        int sndIdx = event - 47;

        /* line 415 */
        cg = *((char **)cg_dvar_footsteps);
        if (*(char *)(cg + 8) != 0) {
            cgs = *cgs_glob;
            if (isFirstPerson) {
                /* line 417-418: third person */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(cgs + CGS_SND_FOOTSTEP3_THIRD + sndIdx * 4));
            } else {
                /* line 420: first person */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(cgs + CGS_SND_FOOTSTEP3_FIRST + sndIdx * 4));
            }
        }

        /* line 422 */
        entNum = *(int *)(es + ES_NUMBER);

        /* Prone sound */
        cgs = *cgs_glob;
        if (isViewerFlag) {
            /* line 273 */
            CG_PlayEntitySoundAlias(entNum, *(int *)(cgs + CGS_SND_PRONE_STOP_1P));
        } else {
            /* line 280 */
            CG_PlayEntitySoundAlias(entNum, *(int *)(cgs + CGS_SND_PRONE_LOOP_1P_VIEW));
        }
        return;
    }

    if (event >= 70 && event <= 92) {
        /* Sprint sounds set 1 (events 70-92) */
        int sndIdx = event - 70;

        /* line 427 */
        cgs = *cgs_glob;
        if (isFirstPerson) {
            /* line 428 */
            CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                *(int *)(cgs + CGS_SND_FOOTSTEP1_THIRD + sndIdx * 4));
        } else {
            /* line 430 */
            CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                *(int *)(cgs + CGS_SND_FOOTSTEP1_FIRST + sndIdx * 4));
        }

        /* line 431 */
        entNum = *(int *)(es + ES_NUMBER);

        /* Prone sound */
        cgs = *cgs_glob;
        if (isViewerFlag) {
            /* line 271 */
            CG_PlayEntitySoundAlias(entNum, *(int *)(cgs + CGS_SND_PRONE_LOOP_1P_NONVIEW));
        } else {
            /* line 278 */
            CG_PlayEntitySoundAlias(entNum, *(int *)(cgs + CGS_SND_PRONE_LOOP_3P));
        }
        return;
    }

    if (event >= 93 && event <= 115) {
        /* Sprint sounds set 2 (events 93-115) */
        int sndIdx = event - 93;

        /* line 436 */
        cgs = *cgs_glob;
        if (isFirstPerson) {
            /* line 437 */
            CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                *(int *)(cgs + CGS_SND_SPRINT_THIRD + sndIdx * 4));
        } else {
            /* line 439 */
            CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                *(int *)(cgs + CGS_SND_SPRINT_FIRST + sndIdx * 4));
        }

        /* line 440 */
        cg = *cg_glob;
        if (clientNum == *(int *)(cg + CG_CLIENTNUM)) {
            /* line 443 */
            float neg = -(float)eventParm;
            *(float *)(cg + CG_SHELLSHOCK_TILT) = neg;
            /* line 444 */
            *(int *)(cg + CG_SHELLSHOCK_TIME) = *(int *)(cg + CG_TIME);
        }
        return;
    }

    if (event >= 116 && event <= 138) {
        /* Prone sounds (events 116-138) */
        int sndIdx = event - 116;

        /* line 450 */
        cgs = *cgs_glob;
        if (isFirstPerson) {
            /* line 451 */
            CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                *(int *)(cgs + CGS_SND_SPRINT_THIRD + sndIdx * 4));
        } else {
            /* line 453 */
            CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                *(int *)(cgs + CGS_SND_SPRINT_FIRST + sndIdx * 4));
        }

        /* line 454: melee hit sound */
        CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
            *(int *)(cgs + CGS_SND_MELEE_HIT));

        /* line 455 */
        cg = *cg_glob;
        if (clientNum == *(int *)(cg + CG_CLIENTNUM)) {
            /* line 457: shellshock calculation */
            char *ssMin = *cg_dvar_shellshock_min;
            float ssMinVal = *(float *)(ssMin + 8);
            float parm = (float)eventParm * f_0_01;
            char *ssMax = *cg_dvar_shellshock_max;
            float ssMaxVal = *(float *)(ssMax + 8);
            float delta = ssMaxVal - ssMinVal;
            float shellshock = parm * delta + ssMinVal;

            /* line 460 */
            if (shellshock > f_12_0) {
                /* line 463 */
                float tilt = (shellshock - f_12_0) / f_26_0;
                tilt = tilt * f_4_0 + f_4_0;
                int tiltInt = (int)tilt;

                /* line 464 */
                float tiltVal;
                if (tiltInt > 24) {
                    tiltVal = f_24_0;
                } else if (tiltInt <= 0) {
                    return;
                } else {
                    tiltVal = (float)tiltInt;
                }

                /* line 470 */
                *(float *)(cg + CG_SHELLSHOCK_TILT) = -tiltVal;
                /* line 471 */
                cg = *cg_glob;
                *(int *)(cg + CG_SHELLSHOCK_TIME) = *(int *)(cg + CG_TIME);
            }
        }
        return;
    }

    /* Events 139+ go through jump table (event - 0x8b) */
    /* Since we can't reproduce the exact jump table, we use a switch */
    {
        int jmpIdx = event - 0x8b;
        if ((unsigned int)jmpIdx > 0x3b) {
            /* line 859: unknown event */
            char **eventNames = (char **)(*cg_eventNames);
            /* "Unknown event: '%s'" */
            Com_Error(1, (const char *)str_002b84e8, eventNames[event]);
            return;
        }

        /* The jump table maps event codes 0x8b-0xc6 to various handlers.
         * We reconstruct the switch based on the asm source line references. */
        switch (event) {

        /* line 484: weapon pickup sound */
        case 0x8b:
        {
            cgs = *cgs_glob;
            CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                *(int *)(cgs + CGS_SND_WEAPON_PICKUP));
            return;
        }

        /* line 489: stance change down (client-only) */
        case 0x8c:
        {
            cg = *cg_glob;
            if (clientNum != *(int *)(cg + CG_CLIENTNUM)) {
                /* "Event %s just for client %i was sent to other clients\n" */
                char **eventNames2 = (char **)(*cg_eventNames);
                Com_DPrintf((const char *)str_002b840c, *(char **)(((char *)eventNames2) + 0x230), clientNum);
                return;
            }
            /* line 492 */
            char *ui = *cg_uiglob;
            if (*(int *)(ui + 0xc) != 0)
                return;
            /* line 493 */
            *(int *)(ui + 0x8) = 0;
            return;
        }

        /* line 498: stance change up (client-only) */
        case 0x8d:
        {
            cg = *cg_glob;
            if (clientNum != *(int *)(cg + CG_CLIENTNUM)) {
                char **eventNames2 = (char **)(*cg_eventNames);
                Com_DPrintf((const char *)str_002b840c, *(char **)(((char *)eventNames2) + 0x234), clientNum);
                return;
            }
            /* line 501 */
            char *ui = *cg_uiglob;
            if (*(int *)(ui + 0xc) != 0)
                return;
            /* line 502 */
            *(int *)(ui + 0x8) = 1;
            return;
        }

        /* line 507: stance change crouch (client-only) */
        case 0x8e:
        {
            cg = *cg_glob;
            if (clientNum != *(int *)(cg + CG_CLIENTNUM)) {
                char **eventNames2 = (char **)(*cg_eventNames);
                Com_DPrintf((const char *)str_002b840c, *(char **)(((char *)eventNames2) + 0x238), clientNum);
                return;
            }
            /* line 510 */
            char *ui = *cg_uiglob;
            if (*(int *)(ui + 0xc) != 0)
                return;
            /* line 511 */
            *(int *)(ui + 0x8) = 2;
            return;
        }

        /* line 520: shellshock / viewkick (client-only) */
        case 0x8f:
        {
            cg = *cg_glob;
            if (clientNum != *(int *)(cg + CG_CLIENTNUM)) {
                char **eventNames2 = (char **)(*cg_eventNames);
                Com_DPrintf((const char *)str_002b840c, *(char **)(((char *)eventNames2) + 0x23c), clientNum);
                return;
            }
            /* line 523 */
            if (*(int *)(cg + CG_FIELD_8) != 0)
                return;
            char *dv1 = *cg_dvar1;
            if (*(char *)(dv1 + 8) != 0)
                return;
            char *dv2 = *cg_dvar2;
            if (*(char *)(dv2 + 8) != 0)
                return;

            /* line 528 */
            int cgTime = *(int *)(cg + CG_TIME);
            int prevTime = *(int *)(cg + CG_SHELLSHOCK_VIEWANGLE + 4);
            int timeDiff = cgTime - prevTime;
            float viewAngle = 0.0f;

            /* line 529 */
            if (timeDiff <= 99) {
                /* line 530 */
                int remaining = 100 - timeDiff;
                viewAngle = (float)remaining * *(float *)(cg + CG_SHELLSHOCK_VIEWANGLE);
                viewAngle /= f_100_0;
                viewAngle *= f_0_9;
            }

            /* line 536 */
            int parmAdj = eventParm - 128;
            viewAngle += (float)parmAdj;
            *(float *)(cg + CG_SHELLSHOCK_VIEWANGLE) = viewAngle;

            /* line 537 */
            cg = *cg_glob;
            float curAngle = *(float *)(cg + CG_SHELLSHOCK_VIEWANGLE);
            if (curAngle > f_24_0) {
                /* line 538 */
                *(float *)(cg + CG_SHELLSHOCK_VIEWANGLE) = 24.0f;
            } else if (curAngle < f_neg16) {
                /* line 540 */
                *(float *)(cg + CG_SHELLSHOCK_VIEWANGLE) = -16.0f;
            }

            /* line 542 */
            cg = *cg_glob;
            *(int *)(cg + CG_SHELLSHOCK_VIEWANGLE + 4) = *(int *)(cg + CG_TIME);
            return;
        }

        /* line 552: item sound events (0x90, 0x91) */
        case 0x90:
        case 0x91:
        {
            int itemIndex = *(int *)(es + ES_EVENTPARM);
            if (itemIndex <= 0)
                return;
            int *itemCnt = *cg_itemCount;
            if (itemIndex >= *itemCnt)
                return;

            /* line 556 */
            char *itemDefs = *cg_itemDefs;
            char *itemData = itemDefs + itemIndex * 9 * 4;

            if (event == 0x90) {
                /* line 559 */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(itemData + 0x1c));
            } else {
                /* line 561 */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(itemData + 0x20));
            }

            /* line 564 */
            cg = *cg_glob;
            snap = *(char **)(cg + CG_SNAP);
            if (!(*(int *)(snap + SNAP_FLAGS) & 0xc00000))
                return;
            if (*(int *)(es + ES_NUMBER) != *(int *)(snap + SNAP_PS_CLIENTNUM))
                return;

            /* line 237: check item type for offhand weapon equip */
            {
                int itemid = itemIndex;
                char *itemInfoBase = *cg_itemInfo;
                char *item = itemInfoBase + itemid * (1 + 2 * 5) * 4;
                int weapId = *(int *)(item + 0x20);
                if (*(int *)(item + 0x1c) != 1)
                    return;

                /* line 242 */
                char *weapDef = (char *)BG_GetWeaponDef(weapId);
                /* line 244 */
                if (*(int *)(weapDef + 0x7c) == 9)
                    return;

                /* line 247 */
                if (*(int *)(weapDef + 0x84) != 0) {
                    /* line 249 */
                    if (*(int *)(cg + CG_OFFHAND) != 0)
                        return;
                    /* line 250 */
                    CG_SetEquippedOffHand(weapId);
                } else {
                    /* line 254 */
                    if (*(int *)(cg + CG_OFFHAND2) != 0)
                        return;
                    /* line 255 */
                    CG_SelectWeaponIndex(weapId);
                }
            }
            return;
        }

        /* line 576: weapon fire sound 1 */
        case 0x92:
        {
            if (isFirstPerson) {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                int alias = *(int *)(wepData + 0xfc);
                if (alias != 0) {
                    /* line 577 */
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
                /* line 578: fall through to alt sound */
                alias = *(int *)(wepData + 0x104);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
            } else {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                /* line 580 */
                int alias = *(int *)(wepData + 0xf8);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
                /* line 582-583 */
                alias = *(int *)(wepData + 0x100);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
            }
            return;
        }

        /* line 587: weapon fire sound 2 */
        case 0x93:
        {
            if (isFirstPerson) {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                int alias = *(int *)(wepData + 0x104);
                if (alias != 0) {
                    /* line 588 */
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
                /* line 589-590 */
                alias = *(int *)(wepData + 0xfc);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
            } else {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                /* line 591-592 */
                int alias = *(int *)(wepData + 0x100);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
                /* line 593-594 */
                alias = *(int *)(wepData + 0xf8);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
            }
            return;
        }

        /* line 598: weapon reload sound 1 */
        case 0x94:
        {
            if (isFirstPerson) {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                int alias = *(int *)(wepData + 0x10c);
                if (alias != 0) {
                    /* line 599 */
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
                /* fallthrough: line 600 */
                alias = *(int *)(wepData + 0x108);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                }
            } else {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                /* line 607 */
                int alias = *(int *)(wepData + 0x110);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                }
            }
            return;
        }

        /* line 605: weapon reload sound 2 */
        case 0x95:
        {
            if (isFirstPerson) {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                int alias = *(int *)(wepData + 0x114);
                if (alias != 0) {
                    /* line 606 */
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
                /* fallthrough: line 607-608 */
                alias = *(int *)(wepData + 0x110);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                }
            } else {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                /* line 608 */
                int alias = *(int *)(wepData + 0x108);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                }
            }
            return;
        }

        /* line 613: no ammo / weapon change */
        case 0x96:
        {
            int w = *(int *)(es + ES_WEAPON);
            if (!BG_WeaponIsClipOnly(w)) {
                /* line 614 */
                cgs = *cgs_glob;
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER),
                    *(int *)(cgs + CGS_SND_NOAMMO));
            }
            /* line 615 */
            cg = *cg_glob;
            snap = *(char **)(cg + CG_SNAP);
            if (!(*(int *)(snap + SNAP_FLAGS) & 0xc00000))
                return;
            if (*(int *)(es + ES_NUMBER) != *(int *)(snap + SNAP_PS_CLIENTNUM))
                return;
            /* line 616 */
            CG_OutOfAmmoChange();
            return;
        }

        /* line 620: switch offhand */
        case 0x97:
        {
            cg = *cg_glob;
            snap = *(char **)(cg + CG_SNAP);
            if (!(*(int *)(snap + SNAP_FLAGS) & 0xc00000))
                return;
            if (*(int *)(es + ES_NUMBER) != *(int *)(snap + SNAP_PS_CLIENTNUM))
                return;
            /* line 622 */
            CG_MenuShowNotify(4);
            /* line 623 */
            CG_SwitchOffHandCmd();
            return;
        }

        /* line 629: clear ADS */
        case 0x98:
        {
            cg = *cg_glob;
            snap = *(char **)(cg + CG_SNAP);
            if (!(*(int *)(snap + SNAP_FLAGS) & 0xc00000))
                return;
            if (*(int *)(es + ES_NUMBER) != *(int *)(snap + SNAP_PS_CLIENTNUM))
                return;
            /* line 630 */
            CL_SetADS(0);
            return;
        }

        /* line 634: weapon raise sound */
        case 0x99:
        {
            weapon = *(int *)(es + ES_WEAPON);
            int wepOff = weaponDataOffset(weapon);
            char *wepDefs = *cg_weaponDefs;
            char *wepData = wepDefs + wepOff * 4;
            int alias = *(int *)(wepData + 0x118);
            if (alias != 0) {
                /* line 635 */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
            }
            return;
        }

        /* line 640: weapon putaway sound */
        case 0x9a:
        {
            weapon = *(int *)(es + ES_WEAPON);
            int wepOff = weaponDataOffset(weapon);
            char *wepDefs = *cg_weaponDefs;
            char *wepData = wepDefs + wepOff * 4;
            int alias = *(int *)(wepData + 0x120);
            if (alias != 0) {
                /* line 641 */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
            }
            return;
        }

        /* line 646: weapon alt raise sound */
        case 0x9b:
        {
            weapon = *(int *)(es + ES_WEAPON);
            int wepOff = weaponDataOffset(weapon);
            char *wepDefs = *cg_weaponDefs;
            char *wepData = wepDefs + wepOff * 4;
            int alias = *(int *)(wepData + 0x11c);
            if (alias != 0) {
                /* line 647 */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
            }
            return;
        }

        /* line 651: fire weapon both barrels */
        case 0x9c:
        {
            /* line 651 */
            CG_FireWeapon(cent, 0xb0, 0);
            /* line 652 */
            CG_FireWeapon(cent, 0xb0, 1);
            return;
        }

        /* line 656: fire weapon alt both barrels */
        case 0x9d:
        {
            /* line 656 */
            CG_FireWeapon(cent, 0xb1, 2);
            /* line 657 */
            CG_FireWeapon(cent, 0xb1, 3);
            return;
        }

        /* line 664: grenade explosion / shake camera */
        case 0x9e:
        {
            /* line 664: CG_StartShakeCamera(0.05f, position, 100, 100.0f) */
            /* 0x3d4ccccd = 0.05f, 0x42c80000 = 100.0f */
            CG_StartShakeCamera(0.05f, position, 100, 100.0f);
            /* line 665 */
            CG_FireWeapon(cent, 0xaf, 0);
            /* line 667 */
            {
                int ep = eventParm;
                int entStride = ep * 16 + ep;
                entStride = ep + entStride * 8;
                char *ents = *cg_entities_glob;
                char *entData = ents + entStride * 4;
                /* line 668 */
                if (*(char *)(entData + 0x1e0) == 0)
                    return;
                if (*(int *)(entData + 0xf4) != 1)
                    return;
                cg = *cg_glob;
                snap = *(char **)(cg + CG_SNAP);
                int snapWeapon = *(int *)(snap + SNAP_PS_WEAPON);
                if (snapWeapon == *(int *)((char *)cent + CENT_NEXTSTATE + ES_NUMBER))
                    return;
                /* line 669 */
                CG_CompassAddWeaponPingInfo(entData, position, 50);
            }
            return;
        }

        /* line 674: weapon sound alt */
        case 0x9f:
        {
            weapon = *(int *)(es + ES_WEAPON);
            int wepOff = weaponDataOffset(weapon);
            char *wepDefs = *cg_weaponDefs;
            char *wepData = wepDefs + wepOff * 4;
            int alias = *(int *)(wepData + 0xd8);
            if (alias != 0) {
                /* line 675 */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
            }
            return;
        }

        /* line 681: fire weapon generic */
        case 0xa0:
        {
            /* line 681 */
            CG_FireWeapon(cent, event, 0);
            return;
        }

        /* line 685: weapon bolt sound */
        case 0xa1:
        {
            if (isFirstPerson) {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                int alias = *(int *)(wepData + 0xf4);
                if (alias != 0) {
                    /* line 686 */
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                    return;
                }
                /* line 687-688 */
                alias = *(int *)(wepData + 0xf0);
                if (alias != 0) {
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                }
            } else {
                weapon = *(int *)(es + ES_WEAPON);
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                char *wepData = wepDefs + wepOff * 4;
                int alias = *(int *)(wepData + 0xec);
                if (alias != 0) {
                    /* line 697 */
                    CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
                }
            }
            return;
        }

        /* line 692: eject brass */
        case 0xa2:
        {
            /* line 692 */
            CG_EjectWeaponBrass((entityState_t *)es, 0xa2);
            return;
        }

        /* line 696: weapon sound misc */
        case 0xa3:
        {
            weapon = *(int *)(es + ES_WEAPON);
            int wepOff = weaponDataOffset(weapon);
            char *wepDefs = *cg_weaponDefs;
            char *wepData = wepDefs + wepOff * 4;
            int alias = *(int *)(wepData + 0xec);
            if (alias != 0) {
                /* line 697 */
                CG_PlayEntitySoundAlias(*(int *)(es + ES_NUMBER), alias);
            }
            return;
        }

        /* line 704: prep offhand */
        case 0xa4:
        {
            /* line 704 */
            CG_PrepOffHand((entityState_t *)es, 0xa5, *(int *)(es + ES_EVENTPARM));
            return;
        }

        /* line 708: use offhand */
        case 0xa5:
        {
            /* line 708 */
            CG_UseOffHand(cent, 0xa6, *(int *)(es + ES_EVENTPARM));
            return;
        }

        /* line 712: equip offhand */
        case 0xa6:
        {
            /* line 712 */
            if (!isFirstPerson)
                return;
            CG_SetEquippedOffHand(*(int *)(es + ES_EVENTPARM));
            return;
        }

        /* line 724: nightvision on sound */
        case 0xa7:
        {
            cgs = *cgs_glob;
            CG_PlayEntitySoundAlias(*(int *)(es + ES_OTHERENTNUM),
                *(int *)(cgs + CGS_SND_NIGHTVISION_ON));
            return;
        }

        /* line 728: nightvision off sound */
        case 0xa8:
        {
            cgs = *cgs_glob;
            CG_PlaySoundAlias(*(int *)(es + ES_OTHERENTNUM), position,
                *(int *)(cgs + CGS_SND_NIGHTVISION_OFF));
            return;
        }

        /* line 733: bullet impact (no direction) */
        case 0xa9:
        {
            /* line 191-193: up vector */
            dir[0] = 0.0f;
            dir[1] = 0.0f;
            dir[2] = 1.0f;

            /* line 733 */
            cgs = *cgs_glob;
            CG_PlaySoundAlias(0x3fe, position,
                *(int *)(cgs + CGS_SND_BULLET_FLESH));

            /* line 734 */
            {
                char *fxLookup = *(char **)(cgs + CGS_FXLOOKUP);
                char *fxData = *(char **)(fxLookup + 4);
                int fxId = *(int *)(fxData + 0x33c);
                if (fxId != 0) {
                    /* line 735 */
                    FX_PlayEffect(fxId, position, dir);
                }
            }
            return;
        }

        /* line 747: bullet hit event (with direction + reflect) */
        case 0xaa:
        {
            /* line 747 */
            ByteToDir(*(int *)(es + ES_EVENTPARM), dir);
            /* line 748 */
            ByteToDir(*(int *)(es + ES_DMGFLAGS), reflect);
            /* line 749 */
            CG_BulletHitEvent(*(int *)(es + ES_OTHERENTNUM), position,
                dir, reflect, *(int *)(es + ES_SURFTYPE), event);
            return;
        }

        /* line 754: bullet hit client event */
        case 0xab:
        {
            /* line 754 */
            CG_BulletHitClientEvent(*(int *)(es + ES_OTHERENTNUM), position,
                *(int *)(es + ES_SURFTYPE), event);
            return;
        }

        /* line 759: bullet whizby */
        case 0xac:
        {
            /* line 759 */
            ByteToDir(*(int *)(es + ES_EVENTPARM), dir);
            /* line 760 */
            cgs = *cgs_glob;
            int surfType = *(int *)(es + ES_SURFTYPE);
            CG_PlaySoundAlias(0x3fe, position,
                *(int *)(cgs + CGS_SND_BULLET_WHIZBY + surfType * 4));
            /* line 761 */
            {
                char *fxLookup = *(char **)(cgs + CGS_FXLOOKUP);
                char *fxData = *(char **)(fxLookup + 4);
                int fxId = *(int *)(fxData + 0x2e0 + surfType * 4);
                if (fxId != 0) {
                    /* line 762 */
                    FX_PlayEffect(fxId, position, dir);
                }
            }
            return;
        }

        /* line 767: bullet flesh hit */
        case 0xad:
        {
            /* line 767 */
            ByteToDir(*(int *)(es + ES_EVENTPARM), dir);
            /* line 768 */
            cgs = *cgs_glob;
            int surfType2 = *(int *)(es + ES_SURFTYPE);
            CG_PlaySoundAlias(0x3fe, position,
                *(int *)(cgs + CGS_SND_BULLET_FLESH + surfType2 * 4));

            /* line 770 */
            {
                char *fxLookup = *(char **)(cgs + CGS_FXLOOKUP);
                char *fxData = *(char **)(fxLookup + 4);
                int fxId = *(int *)(fxData + 0x33c + surfType2 * 4);
                if (fxId != 0) {
                    /* line 771 */
                    FX_PlayEffect(fxId, position, dir);
                }
            }

            /* line 773 */
            weapon = *(int *)(es + ES_WEAPON);
            {
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                int fxId = *(int *)(wepDefs + 0x164 + wepOff * 4);
                if (fxId != 0) {
                    /* line 774 */
                    FX_PlayEffect(fxId, position, dir);
                }

                weapon = *(int *)(es + ES_WEAPON);
                wepOff = weaponDataOffset(weapon);
                /* line 776 */
                int sndAlias = *(int *)(wepDefs + 0x168 + wepOff * 4);
                if (sndAlias != 0) {
                    /* line 777 */
                    CG_PlaySoundAlias(0x3fe, position, sndAlias);
                }
            }
            return;
        }

        /* line 781: grenade bounce FX */
        case 0xae:
        {
            /* line 781 */
            ByteToDir(*(int *)(es + ES_EVENTPARM), dir);
            /* line 783 */
            weapon = *(int *)(es + ES_WEAPON);
            {
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;

                /* line 804 */
                cgs = *cgs_glob;
                int surfType3 = *(int *)(es + ES_SURFTYPE);
                CG_PlaySoundAlias(0x3fe, position,
                    *(int *)(cgs + CGS_SND_GRENADE_BOUNCE + surfType3 * 4));

                /* line 805 */
                {
                    char *fxLookup = *(char **)(cgs + CGS_FXLOOKUP);
                    char *fxData = *(char **)(fxLookup + 4);
                    int surfType4 = *(int *)(es + ES_SURFTYPE);
                    int fxId = *(int *)(fxData + 0x398 + surfType4 * 4);
                    if (fxId != 0) {
                        /* line 806 */
                        FX_PlayEffect(fxId, position, dir);
                    }
                }

                /* line 808 */
                weapon = *(int *)(es + ES_WEAPON);
                wepOff = weaponDataOffset(weapon);
                int fxId2 = *(int *)(wepDefs + 0x164 + wepOff * 4);
                if (fxId2 != 0) {
                    /* line 809 */
                    FX_PlayEffect(fxId2, position, dir);
                }

                /* line 810 */
                weapon = *(int *)(es + ES_WEAPON);
                wepOff = weaponDataOffset(weapon);
                int sndAlias = *(int *)(wepDefs + 0x168 + wepOff * 4);
                if (sndAlias != 0) {
                    /* line 811 */
                    CG_PlaySoundAlias(0x3fe, position, sndAlias);
                }
            }

            /* line 812 */
            cg = *cg_glob;
            *(int *)(cg + CG_VEHFLAG) = 0;
            return;
        }

        /* line 799: grenade explosion FX (with warp time) */
        case 0xaf:
        {
            /* line 799 */
            cg = *cg_glob;
            *(int *)(cg + CG_VEHFLAG) = 1;

            /* line 803 */
            ByteToDir(*(int *)(es + ES_EVENTPARM), dir);

            /* line 804 */
            cgs = *cgs_glob;
            int surfType5 = *(int *)(es + ES_SURFTYPE);
            CG_PlaySoundAlias(0x3fe, position,
                *(int *)(cgs + CGS_SND_GRENADE_BOUNCE + surfType5 * 4));

            /* line 805 */
            {
                char *fxLookup = *(char **)(cgs + CGS_FXLOOKUP);
                char *fxData = *(char **)(fxLookup + 4);
                int surfType6 = *(int *)(es + ES_SURFTYPE);
                int fxId = *(int *)(fxData + 0x398 + surfType6 * 4);
                if (fxId != 0) {
                    /* line 806 */
                    FX_PlayEffect(fxId, position, dir);
                }
            }

            /* line 808 */
            weapon = *(int *)(es + ES_WEAPON);
            {
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                int fxId = *(int *)(wepDefs + 0x164 + wepOff * 4);
                if (fxId != 0) {
                    /* line 809 */
                    FX_PlayEffect(fxId, position, dir);
                }

                weapon = *(int *)(es + ES_WEAPON);
                wepOff = weaponDataOffset(weapon);
                /* line 810 */
                int sndAlias = *(int *)(wepDefs + 0x168 + wepOff * 4);
                if (sndAlias != 0) {
                    /* line 811 */
                    CG_PlaySoundAlias(0x3fe, position, sndAlias);
                }
            }

            /* line 812 */
            cg = *cg_glob;
            *(int *)(cg + CG_VEHFLAG) = 0;
            return;
        }

        /* line 781 (variant): grenade bounce with warp time */
        case 0xb0:
        {
            /* line 781 */
            ByteToDir(*(int *)(es + ES_EVENTPARM), dir);

            /* line 783 */
            weapon = *(int *)(es + ES_WEAPON);
            {
                int wepOff = weaponDataOffset(weapon);
                char *wepDefs = *cg_weaponDefs;
                int fxId = *(int *)(wepDefs + 0x164 + wepOff * 4);
                if (fxId != 0) {
                    /* line 786 */
                    FX_WarpTime(*(int *)(es + ES_TIME));
                    /* line 787 */
                    weapon = *(int *)(es + ES_WEAPON);
                    wepOff = weaponDataOffset(weapon);
                    fxId = *(int *)(wepDefs + 0x164 + wepOff * 4);
                    FX_PlayEffect(fxId, position, dir);
                    /* line 789 */
                    cg = *cg_glob;
                    FX_WarpTime(*(int *)(cg + CG_TIME));
                }

                /* line 791 */
                weapon = *(int *)(es + ES_WEAPON);
                wepOff = weaponDataOffset(weapon);
                int sndAlias = *(int *)(wepDefs + 0x168 + wepOff * 4);
                if (sndAlias == 0)
                    return;

                /* line 793 */
                if (*(char *)(es + 0x0a) & 1) {
                    cg = *cg_glob;
                    int cgTime2 = *(int *)(cg + CG_TIME);
                    int esTime = *(int *)(es + ES_TIME);
                    if (cgTime2 - esTime > 49)
                        return;
                }
                /* line 794 */
                CG_PlaySoundAlias(0x3fe, position, sndAlias);
            }
            return;
        }

        /* line 816: play config string sound */
        case 0xb1:
        {
            int csIndex = *(int *)(es + ES_EVENTPARM) + 0x24e;
            const char *csStr = CL_GetConfigString(csIndex);
            CG_PlaySoundAliasByName(*(int *)(es + ES_NUMBER),
                es + 0x18, csStr);
            return;
        }

        /* line 819: play config string sound as master */
        case 0xb2:
        {
            int csIndex = *(int *)(es + ES_EVENTPARM) + 0x24e;
            const char *csStr = CL_GetConfigString(csIndex);
            CG_PlaySoundAliasAsMasterByName(*(int *)(es + ES_NUMBER),
                es + 0x18, csStr);
            return;
        }

        /* line 837: shake camera from entity */
        case 0xb3:
        {
            int duration = *(int *)(es + 0x6c);
            int esTime = *(int *)(es + ES_TIME);
            float intensity = *(float *)(es + 0x68);
            CG_StartShakeCamera(intensity, position, esTime, *(float *)&duration);
            return;
        }

        /* Obituary event (death message) */
        case 0xc5:
        {
            /* line 40-42: init colors to 1.0 */
            attackerColor[0] = 1.0f;
            attackerColor[1] = 1.0f;
            attackerColor[2] = 1.0f;
            attackerColor[3] = 1.0f;
            victimColor[0] = 1.0f;
            victimColor[1] = 1.0f;
            victimColor[2] = 1.0f;
            victimColor[3] = 1.0f;
            iconColor[0] = 1.0f;
            iconColor[1] = 1.0f;
            iconColor[2] = 1.0f;
            iconColor[3] = 1.0f;

            /* line 50-51 */
            target = *(int *)(es + ES_OTHERENTNUM);
            attacker = *(int *)(es + ES_ATTACKERENTNUM);

            /* line 87: check eventParm for weapon/means of death */
            int ep = *(int *)(es + ES_EVENTPARM);
            if ((ep & 0x80) == 0) {
                /* line 99 */
                char *weapDef = (char *)BG_GetWeaponDef(ep);
                /* line 100 */
                const char *killIcon = *(const char **)(weapDef + 0x34c);
                if (*killIcon == '\0') {
                    /* Default icon */
                    iconWidth = f_1_4;
                    iconShader = (const char *)str_002a763c;
                    iconHorzFlip = 0;
                } else {
                    /* line 102 */
                    iconShader = killIcon;
                    /* line 103 */
                    int isWideIcon = *(int *)(weapDef + 0x350);
                    if (isWideIcon) {
                        iconWidth = f_2_8;
                    } else {
                        iconWidth = f_1_4;
                    }
                    /* line 105 */
                    iconHorzFlip = *(int *)(weapDef + 0x354) != 0;
                }
            } else {
                /* Means of death icon lookup */
                int mod = (ep & 0x7f) - 7;
                if ((unsigned int)mod > 5) {
                    /* default icon */
                    iconWidth = f_1_4;
                    iconShader = (const char *)str_002a763c;
                    iconHorzFlip = 0;
                } else {
                    switch (mod) {
                    case 0: /* line 105 - melee icon */
                        iconWidth = f_1_4;
                        iconShader = (const char *)str_002a75fc;
                        iconHorzFlip = 0;
                        break;
                    case 1: /* line 116 */
                        iconWidth = f_1_4;
                        iconShader = (const char *)str_002a762c;
                        iconHorzFlip = 0;
                        break;
                    case 2: /* line 121 */
                        iconWidth = f_1_4;
                        iconShader = (const char *)str_002a89d8;
                        iconHorzFlip = 0;
                        break;
                    case 3: /* line 125 */
                        iconWidth = f_1_4;
                        iconShader = (const char *)str_002a760c;
                        iconHorzFlip = 0;
                        break;
                    case 4: /* line 129 */
                        iconWidth = f_1_4;
                        iconShader = (const char *)str_002a761c;
                        iconHorzFlip = 0;
                        break;
                    default:
                        iconWidth = f_1_4;
                        iconShader = (const char *)str_002a763c;
                        iconHorzFlip = 0;
                        break;
                    }
                }
            }

            /* line 144: validate target */
            if ((unsigned int)target > 63) {
                /* line 145 */
                Com_Error(1, (const char *)str_002b8444);
            }

            /* line 146: get victim client info */
            {
                int tgt = target;
                int tgtOff = tgt * (1 + (tgt * 5 * 16 - tgt * 5) * 2);
                /* Simplified: the asm computes: tgt + (tgt*5 * (16-1)) * 2 = tgt*(1 + 5*15*2) = tgt*151 */
                /* Actually: lea (%edx,%edx,4),%eax => eax=tgt*5; shl $4,%edx; sub %eax,%edx => edx=tgt*5*16-tgt*5=tgt*75 */
                /* lea (%ecx,%edx,2),%edx => edx=tgt+tgt*75*2=tgt*(1+150)=tgt*151 */
                /* then lea 0xe0900(%ebx,%edx,8) => base + 0xe0900 + tgt*151*8 = base + 0xe0900 + tgt*1208 */
            }
            cg = *cg_glob;
            {
                char *clientInfoBase = cg + CG_CLIENTINFO + target * 1208;
                victimCI = clientInfoBase + 0x14;

                /* line 147 */
                if (*(int *)(clientInfoBase + 0x14) == 0)
                    return;

                /* line 150 */
                I_strncpyz(targetName, clientInfoBase + 0x20, 0x20);
                /* line 151 */
                I_strncat(targetName, 0x22, (const char *)str_002b3b48);
                /* line 152 */
                CG_DrawScoreboard_GetTeamColor(*(int *)(victimCI + 0x30 - 0x14), victimColor);

                /* line 155: check if local client info exists */
                int localClient = *(int *)(cg + CG_LOCALCLIENT);
                char *localCI = cg + CG_CLIENTINFO + localClient * 1208;
                if (*(int *)(localCI + 0x14) == 0)
                    return;
            }

            /* line 158: check attacker */
            if ((unsigned int)attacker <= 63) {
                /* line 166: get attacker client info */
                char *atkInfoBase = cg + CG_CLIENTINFO + attacker * 1208;
                attackerCI = atkInfoBase + 0x14;

                /* line 167 */
                if (*(int *)(atkInfoBase + 0x14) == 0)
                    return;

                /* line 169 */
                I_strncpyz(attackerName, atkInfoBase + 0x20, 0x20);
                /* line 170 */
                I_strncat(attackerName, 0x22, (const char *)str_002b3b48);
                /* line 171 */
                CG_DrawScoreboard_GetTeamColor(*(int *)(attackerCI + 0x30 - 0x14), attackerColor);

                /* line 174 */
                snap = *(char **)(cg + CG_SNAP);
                if (target == *(int *)(snap + SNAP_PS_CLIENTNUM)) {
                    /* line 175: copy attacker name to killcam */
                    I_strncpyz(cg + CG_KILLCAM_NAME, attackerName, 0x20);
                }
            } else {
                /* line 162 */
                attackerName[0] = '\0';
                attacker = 0x3fe;
                attackerCI = (char *)0;
            }

            /* line 178: check if suicide */
            if (attacker == target) {
                /* line 180 */
                attackerName[0] = '\0';
                cg = *cg_glob;
            } else {
                /* line 183 */
                cg = *cg_glob;
                snap = *(char **)(cg + CG_SNAP);
                int localClientNum = *(int *)(snap + SNAP_PS_CLIENTNUM);

                if (attacker == localClientNum) {
                    /* line 185: "you killed" */
                    if (attackerCI != (char *)0) {
                        int atkTeam = *(int *)(attackerCI + 0x30 - 0x14);
                        if (atkTeam != 0 && atkTeam == *(int *)(victimCI + 0x30 - 0x14)) {
                            /* line 186: team kill */
                            const char *msg = va((const char *)str_002b8478, targetName, (const char *)str_002b8468);
                            /* line 205 */
                            cg = *cg_glob;
                            if (*(int *)(cg + CG_DEATHFADE) == 0) {
                                CG_PriorityCenterPrint(msg, 9.6f, 1);
                            }
                            cg = *cg_glob;
                        } else {
                            /* line 188 */
                            const char *msg = va((const char *)str_002b8498, targetName);
                            cg = *cg_glob;
                            if (*(int *)(cg + CG_DEATHFADE) == 0) {
                                CG_PriorityCenterPrint(msg, 9.6f, 1);
                            }
                            cg = *cg_glob;
                        }
                    } else {
                        const char *msg = va((const char *)str_002b8498, targetName);
                        cg = *cg_glob;
                        if (*(int *)(cg + CG_DEATHFADE) == 0) {
                            CG_PriorityCenterPrint(msg, 9.6f, 1);
                        }
                        cg = *cg_glob;
                    }
                } else if (target == localClientNum) {
                    /* line 199: "you were killed" */
                    if (attackerCI != (char *)0) {
                        int atkTeam = *(int *)(attackerCI + 0x30 - 0x14);
                        if (atkTeam != 0 && atkTeam == *(int *)(victimCI + 0x30 - 0x14)) {
                            /* line 202 */
                            const char *msg = va((const char *)str_002b84ac, attackerName, (const char *)str_002b8468);
                            cg = *cg_glob;
                            if (*(int *)(cg + CG_DEATHFADE) == 0) {
                                CG_PriorityCenterPrint(msg, 9.6f, 1);
                            }
                            cg = *cg_glob;
                        } else {
                            /* line 204 */
                            const char *msg = va((const char *)str_002b84d0, attackerName);
                            cg = *cg_glob;
                            if (*(int *)(cg + CG_DEATHFADE) == 0) {
                                CG_PriorityCenterPrint(msg, 9.6f, 1);
                            }
                            cg = *cg_glob;
                        }
                    } else {
                        const char *msg = va((const char *)str_002b84d0, attackerName);
                        cg = *cg_glob;
                        if (*(int *)(cg + CG_DEATHFADE) == 0) {
                            CG_PriorityCenterPrint(msg, 9.6f, 1);
                        }
                        cg = *cg_glob;
                    }
                }
            }

            /* line 217: death message print */
            if (*(int *)(cg + CG_DEATHFADE) != 0)
                return;

            /* line 219 */
            CL_DeathMessagePrint(attackerName, attackerColor, targetName,
                victimColor, iconShader, iconWidth, 1.4f, iconColor, iconHorzFlip);
            return;
        }

        /* line 292: CG_PlayFx - play effect from entity config */
        case 0xb4:
        {
            /* line 219: get angles */
            float *angles = (float *)(es + ES_APOS_BASE);

            /* line 292 */
            int fxIndex = *(int *)((char *)cent + 0x190);
            int fxIdx = fxIndex - 1;
            if ((unsigned int)fxIdx > 62) {
                /* line 295 */
                Com_Printf((const char *)str_002abd90, fxIndex);
                return;
            }

            /* line 298 */
            cgs = *cgs_glob;
            int fxId = *(int *)(cgs + CGS_FX_DEATHFX + fxIdx * 4);

            /* line 300 */
            AngleVectors(angles, forward, (void *)0, up);
            /* line 301 */
            FX_PlayEffect(fxId, position, forward);
            return;
        }

        /* line 317: play fx from config string */
        case 0xb5:
        {
            int csIndex2 = *(int *)(es + ES_EVENTPARM) + 0x38e;
            const char *csStr2 = CL_GetConfigString(csIndex2);

            /* line 323: parse fx index from config string */
            cgs = *cgs_glob;
            {
                signed char c0 = csStr2[0];
                signed char c1 = csStr2[1];
                int fxIdx2 = c1 + c0 * 10;
                int fxId2 = *(int *)(cgs + CGS_FX_CUSTOM + fxIdx2 * 4);

                /* line 325 */
                int entNum2 = *(int *)((char *)cent + CENT_NEXTSTATE + ES_NUMBER);
                int entityInfo = entNum2;

                /* line 326 */
                tagName = SL_GetString(csStr2 + 2, 0);

                /* line 327 */
                boneIndex = FX_GetBoneIndex(entityInfo, (int)tagName);

                /* line 328 */
                Scr_SetString(&tagName, 0);

                /* line 329 */
                if (boneIndex < 0)
                    return;

                /* line 332 */
                FX_PlayEntityEffect(fxId2, position, 0, &entityInfo);
            }
            return;
        }

        /* All other events that don't have specific handlers go to the default case */
        default:
        {
            /* line 859: unknown event */
            char **eventNames3 = (char **)(*cg_eventNames);
            Com_Error(1, (const char *)str_002b84e8, eventNames3[event]);
            return;
        }

        } /* end switch(event) */
    } /* end jump table block */
}

/* line 871 */
void CG_CheckEvents(centity_t *cent)
{
    char *c = (char *)cent;
    int eType;
    int eventSequence;
    int prevEventSeq;
    int i;
    int oldEventParm;
    int diff;

    /* line 877 */
    eType = *(int *)(c + CENT_ETYPE);
    if (eType > 10) {
        /* line 879 */
        i = *(int *)(c + CENT_PREVEVSEQ);
        if (i == 0) {
            /* line 881 */
            *(int *)(c + CENT_PREVEVSEQ) = 1;
            /* line 884 */
            CG_CalcEntityLerpPositions(cent);
            /* line 885 */
            CG_EntityEvent(cent, eType - 10);
        }
        return;
    }

    /* line 891 */
    eventSequence = *(int *)(c + CENT_EVSEQ);
    if (eventSequence == 0) {
        /* line 893 */
        *(int *)(c + CENT_PREVEVSEQ) = 0;
        return;
    }

    prevEventSeq = *(int *)(c + CENT_PREVEVSEQ);

    /* line 897 */
    if (eventSequence < prevEventSeq) {
        /* line 899 */
        prevEventSeq -= 256;
        *(int *)(c + CENT_PREVEVSEQ) = prevEventSeq;
    }

    /* line 901 */
    diff = eventSequence - prevEventSeq;
    if (diff > 4) {
        /* line 903 */
        prevEventSeq = eventSequence - 4;
        *(int *)(c + CENT_PREVEVSEQ) = prevEventSeq;
    }

    /* line 906 */
    if (prevEventSeq >= eventSequence) {
        /* line 908 */
        *(int *)(c + CENT_PREVEVSEQ) = eventSequence;
        return;
    }

    /* line 913 */
    CG_CalcEntityLerpPositions(cent);

    /* line 916 */
    oldEventParm = *(unsigned char *)(c + CENT_EVPARM);
    i = *(int *)(c + CENT_PREVEVSEQ);

    /* line 917 */
    while (i != eventSequence) {
        /* line 919 */
        int evIdx = i & 3;
        int ev = *(int *)(c + CENT_EVENTS + evIdx * 4);

        /* line 921 */
        int evParm = *(int *)(c + CENT_EVPARMS + evIdx * 4);
        *(int *)(c + CENT_EVPARM) = evParm;

        /* line 922 */
        CG_EntityEvent(cent, ev);

        /* line 917 */
        i++;
    }

    /* line 924 */
    *(int *)(c + CENT_EVPARM) = (unsigned char)oldEventParm;

    /* line 925 */
    *(int *)(c + CENT_PREVEVSEQ) = eventSequence;
}
