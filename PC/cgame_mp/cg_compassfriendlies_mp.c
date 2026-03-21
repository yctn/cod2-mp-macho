/* Converted to C from ASM: cg_compassfriendlies_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_compassfriendlies_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* math function declarations (can't include <math.h> due to libc.h conflicts) */
extern float floorf(float x);
extern float sinf(float x);
extern float cosf(float x);
extern float sqrtf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

/* External globals (pointer-to-pointer indirections from binary) */
extern byte **cg_glob;              /* imp_cg — pointer to cg_t base */
extern byte **cgs_glob;             /* imp_cgs — pointer to cgs_t base */
extern byte **cg_entities_glob;     /* imp_cg_entities — pointer to centity array base */

/* Dvar pointers (each is a pointer to a dvar_t*) */
extern const dvar_t **dvar_compassSize;              /* imp_cg_hudCompassSize */
extern const dvar_t **dvar_compassMinRange;          /* imp_cg_hudCompassMinRange */
extern const dvar_t **dvar_compassMinSaturation;     /* imp_cg_hudCompassMinRadius */
extern const dvar_t **dvar_compassMaxRange;          /* imp_cg_hudCompassMaxRange */
extern const dvar_t **dvar_compassClampDist;         /* imp_cg_hudObjectiveMaxRange */
extern const dvar_t **dvar_compassClampSaturation;   /* imp_cg_hudObjectiveMinAlpha */
extern const dvar_t **dvar_compassPingFadeTime;      /* imp_cg_hudCompassSoundPingFadeTime */
extern const dvar_t **dvar_compassFade;              /* imp_hud_fade_compass */

/* External function declarations */
extern float CG_FadeHudMenu(const dvar_t *fadeDvar, int displayStartTime, int duration);
extern void CG_UpdateCompPointerOrientation(void);
extern void CG_ApplySplitScreenCompassScale(float *x, float *y, float *w, float *h);
extern float UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle hMaterial);
extern void CG_DrawRotatedPic(float x, float y, float width, float height, int horzAlign, int vertAlign, float angle, const vec_t *color, MaterialHandle material);
extern const float vectoyaw(const vec_t *vec);
extern const float AngleNormalize360(const float angle);
extern const vec_t Vec2Normalize(vec_t *v);

/*
 * cg_t field offsets (from binary layout, may differ from compiled struct).
 * The cg_t struct is very large; these are raw byte offsets.
 */
#define CG_SNAP_PTR            0x20     /* snapshot_t* */
#define CG_TIME                0x25bb0  /* int cg.time */
#define CG_COMPASS_YAW         0x2c5b8  /* float - compass map yaw */
#define CG_COMPASS_DISPLAYTIME 0x2c5c0  /* int - compass display start time */
#define CG_REFDEF_YAW          0x285cc  /* float - refdef viewaxis yaw */
#define CG_ORIGIN_X            0x28588  /* float - predicted player origin X */
#define CG_ORIGIN_Y            0x2858c  /* float - predicted player origin Y */

/*
 * Compass actor array: 64 entries of compassactor_t (28 bytes each)
 * starting at cg_base + 0x2c5d8.
 *
 * compassactor_t layout (binary):
 *   +0x00: int   iLastUpdate
 *   +0x04: float vLastPos[0]   (x)
 *   +0x08: float vLastPos[1]   (y)
 *   +0x0c: float fLastYaw
 *   +0x10: int   pingTime
 *   +0x14: int   beginFadeTime
 *   +0x18: byte  enemy
 * Size = 0x1c (28), count = 64 (0x40)
 */
#define CG_COMPASS_ACTORS      0x2c5d8
#define COMPASS_ACTOR_SIZE     0x1c
#define COMPASS_ACTOR_COUNT    64

/* clientInfo_t is at cg_base + 0xe0914 with stride 1208 bytes.
 * +0x00: infoValid (int)
 * +0x2c: team (int)
 */
#define CG_CLIENTINFO_BASE     0xe0914
#define CLIENTINFO_STRIDE      1208
#define CI_INFOVALID           0x00
#define CI_TEAM                0x2c

/* cgs_t offsets */
#define CGS_COMPASS_BACK       0xc1e0  /* MaterialHandle - compass friendly back material */
#define CGS_COMPASS_PING       0xc1e8  /* MaterialHandle - compass ping material */
#define CGS_COMPASS_DIR(i)     (0xbc6c + (i) * 4) /* MaterialHandle array - compass direction materials */
#define CGS_COMPASS_DOT        0xbc70  /* MaterialHandle - compass dot material */

/* snapshot/ps offsets */
#define SNAP_PS_CLIENTNUM      0xd8    /* int - clientNum within snap->ps */

/* entityState_t offsets within centity_s (binary layout) */
#define ES_EFLAGS              0x08    /* int eFlags */
#define ES_CLIENTNUM           0xf0    /* int clientNum */
#define ES_ETYPE               0xf4    /* int eType */
#define ES_ORIGIN_X            0x1ec   /* float (lerpOrigin.x) */
#define ES_ORIGIN_Y            0x1f0   /* float (lerpOrigin.y) */
#define ES_LEAN                0x1fc   /* float leanf (or similar) used for fLastYaw */

/* centity binary size */
#define CENTITY_BIN_SIZE       0x224   /* binary centity stride, not matching C struct */

/* playerState compass-related */
#define PS_COMPASS_PACKED      0x5b0   /* packed compass friend data */
#define PS_COMPASS_FRIEND_YAW  0x5b3   /* signed byte - friend yaw */
#define PS_COMPASS_EFLAGS      0xae    /* byte - eFlags packed */

/* snapshot playerInfo count + array */
#define SNAP_PS_NUMCLIENTS     0x26b4  /* int - number of clients in snapshot playerInfo */
#define SNAP_PS_CLIENTBASE     0x26bc  /* int array - client nums in playerInfo */
#define SNAP_PI_STRIDE         0xf0    /* stride between playerInfo entries (256-16=240) */

static float dvar_value(const dvar_t **dvpp)
{
    const dvar_t *dv = *dvpp;
    return dv->current.value;
}

void CG_ApplyCompassPointerRadiusScale(float *radiusScale);
void CG_CompassAddWeaponPingInfo(centity_t *cent, const vec_t *origin, int msec);
void CG_DrawCompassFriendlies(rectDef_t *rect, MaterialHandle material, vec_t *color);

/* line 51 */
void CG_ApplyCompassPointerRadiusScale(float *radiusScale)
{
    float compassSizeVal = dvar_value(dvar_compassSize);
    *radiusScale = (float)((double)*radiusScale * ((double)compassSizeVal * 43.75));
}

/* line 15 */
void CG_CompassAddWeaponPingInfo(centity_t *cent, const vec_t *origin, int msec)
{
    cg_t *cg = *(cg_t **)cg_glob;
    int eType = cent->nextState.eType;

    /* line 22: Skip if eType == 2 (ET_PLAYER) */
    if (eType == 2)
        return;

    /* line 26: Get local client number (at cg_base + 4) */
    int localClientNum = cg->clientNum;

    /* Compute localClientInfo pointer: cg_base + 0xe0914 + localClientNum * 1208 */
    clientInfo_t *localClientInfo = &cg->bgs.clientinfo[localClientNum];

    /* line 27: Get entity's clientNum */
    int entClientNum = cent->nextState.number;

    /* Compute entity's clientInfo pointer */
    clientInfo_t *entClientInfo = &cg->bgs.clientinfo[entClientNum];

    /* line 29: Skip if same clientInfo (same client) */
    if (localClientInfo == entClientInfo)
        return;

    /* line 33-35: Check entity's team; skip if spectator (3) */
    int entTeam = entClientInfo->team;
    if (entTeam == 3)
        return;

    /* line 40: Store ping time = cg.time + msec */
    int cgTime = cg->time;
    compassactor_t *actor = &cg->compassActors[entClientNum];
    actor->beginFadeTime = cgTime + msec; /* beginFadeTime */

    /* line 41: Determine enemy flag based on local client's team vs entity's team */
    int localTeam = localClientInfo->team;
    byte enemyFlag;
    if (localTeam == 0) {
        /* No team (FFA) - mark as enemy */
        enemyFlag = 1;
    } else if (localTeam == entTeam) {
        /* Same team - not enemy */
        enemyFlag = 0;
    } else {
        /* Different team - enemy */
        enemyFlag = 1;
    }
    actor->enemy = enemyFlag; /* enemy */

    /* line 43: Only store position if enemy flag is set */
    if (actor->enemy == 0)
        return;

    /* line 44: Store origin into vLastPos */
    actor->vLastPos[0] = origin[0]; /* vLastPos[0] */
    actor->vLastPos[1] = origin[1]; /* vLastPos[1] */
}

/*
 * Helper: compute compass radius scale (distance -> pixel radius)
 * Used in CG_DrawCompassFriendlies for both weapon ping and friendly paths.
 * Equivalent to the repeated asm pattern at lines 55-67 / 321-327.
 */
static float CompassDistToRadius(float dist)
{
    float maxRange = dvar_value(dvar_compassMaxRange);
    float minRange = dvar_value(dvar_compassMinRange);
    float minSat = dvar_value(dvar_compassMinSaturation);
    float compassSize = dvar_value(dvar_compassSize);

    float clampedDist = dist;
    if (clampedDist > maxRange)
        clampedDist = maxRange;

    float rangeFrac = (clampedDist - minRange) / (maxRange - minRange);
    float saturation = minSat + rangeFrac * (1.0f - minSat);

    return (float)((double)compassSize * 43.75 * (double)saturation);
}

/* line 95 */
void CG_DrawCompassFriendlies(rectDef_t *rect, MaterialHandle material, vec_t *color)
{
    cg_t *cg;
    cgs_t *cgs;
    float compassFadeOutAlpha;
    float centerX, centerY;
    int team;
    int i;

    /* line 124: Get the fade dvar and compute duration */
    const dvar_t *fadeDvar = *dvar_compassFade;
    int duration = (int)floorf(fadeDvar->current.value * 1000.0f + 0.5f);

    /* Get cg base */
    cg = *(cg_t **)cg_glob;

    /* Compute fade alpha */
    int displayStartTime = cg->compassFadeTime;
    compassFadeOutAlpha = CG_FadeHudMenu(fadeDvar, displayStartTime, duration);

    /* line 125: Skip if fully transparent */
    if (compassFadeOutAlpha == 0.0f)
        return;

    /* line 128: Get our snap clientNum and check clientInfo */
    snapshot_t *snapPtr = cg->snap;
    int ourClientNum = snapPtr->ps.clientNum;
    clientInfo_t *ourCI = &cg->bgs.clientinfo[ourClientNum];
    int infoValid = ourCI->infoValid;

    if (infoValid == 0)
        return;

    /* line 130: Get our team */
    team = ourCI->team;

    /* line 132: Skip if spectator */
    if (team == 3)
        return;

    /* line 135 */
    CG_UpdateCompPointerOrientation();

    /* line 137: Compute compass center */
    float compassSize = dvar_value(dvar_compassSize);
    centerX = rect->x + 0.5f * compassSize * rect->w;
    centerY = rect->y + rect->h + (-0.5f) * compassSize * rect->h;

    /* line 456-459: Copy base color to fadedColor */
    vec4_t fadedColor;
    fadedColor[0] = color[0];
    fadedColor[1] = color[1];
    fadedColor[2] = color[2];
    fadedColor[3] = color[3];

    /* line 142: Branch based on team */
    if (team != 0) {
        /* team != 0: iterate over snapshot clients */
        snapshot_t *snapPtr2 = cg->snap;
        int numClients = snapPtr2->numEntities;

        for (i = 0; i < numClients; i++) {
            snapshot_t *snap = cg->snap;

            /* line 147: Get clientNum from playerInfo array */
            int clientIdx = snap->entities[i].number;

            /* Compute centity pointer for this client */
            centity_t *centEnt = &((centity_t *)*cg_entities_glob)[clientIdx];

            /* line 148: Check eType == 1 (ET_PLAYER_CORPSE? or ET_GENERAL) */
            if (centEnt->nextState.eType != 1)
                continue;

            /* line 150: Check eFlags bit 1 (crouching/dead?) */
            if (((centEnt->nextState.eFlags >> 16) & 0x02))
                continue;

            /* line 154: Skip negative clientNum */
            if ((int)clientIdx < 0)
                continue;

            /* line 157: Compute clientInfo for this client */
            cg = *(cg_t **)cg_glob;
            clientInfo_t *ci = &cg->bgs.clientinfo[clientIdx];

            /* Check infoValid */
            if (ci->infoValid == 0)
                continue;

            /* line 159: Check team matches ours */
            if (ci->team != team)
                continue;

            /* line 165: Update compass actor iLastUpdate */
            compassactor_t *actor = &cg->compassActors[clientIdx];
            int cgTime = cg->time;
            actor->iLastUpdate = cgTime; /* iLastUpdate */

            /* line 166: Store lerpOrigin into vLastPos */
            actor->vLastPos[0] = centEnt->lerpOrigin[0];
            actor->vLastPos[1] = centEnt->lerpOrigin[1];

            /* line 167: Store lean/yaw into fLastYaw */
            actor->fLastYaw = centEnt->lerpAngles[1];

            /* line 169: Check eFlags bit 6 (firing?) for weapon ping */
            if (!(((centEnt->nextState.eFlags >> 16) & 0x40)))
                continue;

            /* line 170: Extend pingTime if expired */
            cg = *(cg_t **)cg_glob;
            cgTime = cg->time;
            if (actor->pingTime <= cgTime) {
                actor->pingTime = cgTime + 3000; /* 0xbb8 = 3000ms */
            }
        }

        /* Reload snap pointer for compass packed data below */
        snapPtr2 = (*(cg_t **)cg_glob)->snap;

        /* line 174: Check ps.compassFriend packed data */
        int compassPacked = snapPtr2->ps.iCompassFriendInfo;
        if (compassPacked == 0)
            goto draw_friendlies;

        /* line 176: Extract clientNum from packed data (bits 0-5) */
        int packedClientNum = compassPacked & 0x3f;

        /* line 179: Update compass actor iLastUpdate for packed client */
        cg = *(cg_t **)cg_glob;
        compassactor_t *packedActor = &cg->compassActors[packedClientNum];
        packedActor->iLastUpdate = cg->time; /* iLastUpdate */

        /* line 181-182: Extract packed position offsets */
        cg = *(cg_t **)cg_glob;
        snapPtr2 = cg->snap;
        compassPacked = snapPtr2->ps.iCompassFriendInfo;
        int packedX = ((compassPacked & 0x7fc0) >> 4) - 0x3fc;
        int packedY = ((compassPacked & 0xff8000) >> 13) - 0x3fc;
        float deltaX = (float)packedX;
        float deltaY = (float)packedY;

        /* line 184: Check for out-of-range markers (1024 or -1020) */
        if (deltaX == 1024.0f || deltaX == -1020.0f ||
            deltaY == 1024.0f || deltaY == -1020.0f)
        {
            /* line 186: Normalize direction (out-of-range, use unit vector) */
            vec2_t dir;
            dir[0] = deltaX;
            dir[1] = deltaY;
            Vec2Normalize(dir);

            /* line 187: Store normalized position */
            cg = *(cg_t **)cg_glob;
            packedActor = &cg->compassActors[packedClientNum];
            packedActor->vLastPos[0] = dir[0];
            packedActor->vLastPos[1] = dir[1];
        }
        else
        {
            /* line 191-200: Store absolute position (playerOrigin + delta) */
            cg = *(cg_t **)cg_glob;
            packedActor = &cg->compassActors[packedClientNum];
            float playerX = cg->refdef.vieworg[0];
            float playerY = cg->refdef.vieworg[1];
            packedActor->vLastPos[0] = playerX + deltaX;
            packedActor->vLastPos[1] = playerY + deltaY;
        }

        /* line 195: Store packed yaw */
        cg = *(cg_t **)cg_glob;
        snapPtr2 = cg->snap;
        signed char packedYaw = (signed char)(snapPtr2->ps.iCompassFriendInfo >> 24);
        cg->compassActors[packedClientNum].fLastYaw =
            (float)packedYaw * 1.40625f;

        /* line 197: Check eFlags for firing bit */
        snapPtr2 = cg->snap;
        if (((snapPtr2->ps.eFlags >> 16) & 0x80)) {
            /* Update ping time if expired */
            int cgTime2 = cg->time;
            compassactor_t *pActor2 = &cg->compassActors[packedClientNum];
            if (pActor2->pingTime <= cgTime2) {
                pActor2->pingTime = cgTime2 + 3000;
            }
        }
    }

draw_friendlies:
    /* line 202: Clamp color alpha to compassFadeOutAlpha */
    {
        float origAlpha = color[3];
        if (origAlpha > compassFadeOutAlpha)
            color[3] = compassFadeOutAlpha;
    }

    /* line 204-205: Min of fadedColor[3] and compassFadeOutAlpha */
    {
        float a = fadedColor[3];
        if (a > compassFadeOutAlpha)
            a = compassFadeOutAlpha;
        fadedColor[3] = a;
    }

    cg = *(cg_t **)cg_glob;

    /* line 209: Iterate over 64 compass actors */
    for (i = 0; i < COMPASS_ACTOR_COUNT; i++) {
        cg_t *cgBase = *(cg_t **)cg_glob;
        compassactor_t *actor = &cgBase->compassActors[i];

        /* line 211: Reset iLastUpdate if in the future */
        int lastUpdate = actor->iLastUpdate;
        int cgTime = cgBase->time;
        if (lastUpdate > cgTime) {
            actor->iLastUpdate = 0;
        }

        /* line 213: Skip if too old (> 800ms ago) */
        cgTime = cgBase->time;
        if (actor->iLastUpdate < cgTime - 0x320)
            continue;

        /* line 216: Skip our own client */
        snapshot_t *snap2 = cgBase->snap;
        if (i == snap2->ps.clientNum)
            continue;

        /* line 220: Check if position is valid (not tiny/zero) */
        float posX = actor->vLastPos[0];
        float posY = actor->vLastPos[1];
        unsigned int absX = *(unsigned int *)&actor->vLastPos[0] & 0x7fffffff;
        unsigned int absY = *(unsigned int *)&actor->vLastPos[1] & 0x7fffffff;
        float fabsX, fabsY;
        *(unsigned int *)&fabsX = absX;
        *(unsigned int *)&fabsY = absY;

        float iconAlpha2 = 1.0f;
        float radius;

        if (fabsX <= 1.0f && fabsY <= 1.0f) {
            /* line 223: Position is a normalized direction vector (out-of-range target) */
            float dirVec[2];
            dirVec[0] = posX;
            dirVec[1] = posY;
            float yawTo = vectoyaw(dirVec);
            yawTo = AngleNormalize360(yawTo - cgBase->compPointerYaw);

            /* line 224-227: For out-of-range targets, use midpoint alpha and max radius */
            float clampSat = dvar_value(dvar_compassClampSaturation);
            iconAlpha2 = clampSat + (1.0f - clampSat) * 0.5f;

            /* Radius = max (compassSize * 43.75), since dist = maxRange -> frac = 1.0 -> sat = 1.0 */
            float compassSize2 = dvar_value(dvar_compassSize);
            float minRange = dvar_value(dvar_compassMinRange);
            float maxRange = dvar_value(dvar_compassMaxRange);
            float minSat = dvar_value(dvar_compassMinSaturation);
            float rangeFrac = (maxRange - minRange) / (maxRange - minRange);
            float saturation = minSat + rangeFrac * (1.0f - minSat);
            float radius = (float)((double)compassSize2 * 43.75 * (double)saturation);

            float radians = (float)((double)yawTo * 0.017453292519943295);
            float sinVal = sinf(radians);
            float cosVal = cosf(radians);

            float w = compassSize2 * 10.0f;
            float h = dvar_value(dvar_compassSize) * 10.0f;
            float x = centerX + w * (-0.5f) - radius * sinVal;
            float y = centerY + h * (-0.5f) - radius * cosVal;

            CG_ApplySplitScreenCompassScale(&x, &y, &w, &h);

            /* line 265: Compute angle for drawing */
            float refYaw = cgBase->refdefViewAngles[1];
            float actorYaw = actor->fLastYaw;
            float drawAngle = AngleNormalize360(refYaw - actorYaw);

            /* line 267-270: Determine ping flash state */
            int pingTime = actor->pingTime;
            cgTime = cgBase->time;
            int pingFlash = 0;
            if (pingTime > cgTime) {
                int elapsed = pingTime - cgTime;
                int mod = elapsed % 500;
                if (mod > 249) {
                    pingFlash = 1;
                }
            }

            /* line 276: Check if ping has expired */
            int beginFade = actor->beginFadeTime;
            float pingFadeTime = dvar_value(dvar_compassPingFadeTime);
            float fadeEnd = (float)beginFade + pingFadeTime * 1000.0f;
            MaterialHandle friendMat = NULL;
            float iconAlpha;

            if ((float)cgTime < fadeEnd) {
                /* line 278-279: Within ping time */
                if (cgTime >= beginFade) {
                    iconAlpha = 1.0f;
                } else {
                    /* line 281: Fading */
                    iconAlpha = 1.0f + (float)(cgTime - beginFade) / (pingFadeTime * -1000.0f);
                }
                /* line 283: Get compass back material */
                cgs = *(cgs_t **)cgs_glob;
                friendMat = cgs->media.compassping_friendlyfiring;
            } else {
                friendMat = NULL;
            }

            /* line 456-459: Copy color to per-actor color */
            vec4_t actorColor;
            actorColor[0] = color[0];
            actorColor[1] = color[1];
            actorColor[2] = color[2];
            /* line 289: Clamp alpha */
            actorColor[3] = color[3] < compassFadeOutAlpha ? color[3] : compassFadeOutAlpha;

            /* line 290-291: Min of iconAlpha and compassFadeOutAlpha */
            iconAlpha = compassFadeOutAlpha < iconAlpha ? compassFadeOutAlpha : iconAlpha;

            /* line 293: Draw based on ping flash state */
            if (pingFlash == 1) {
                /* line 295: Draw compass dot */
                cgs = *(cgs_t **)cgs_glob;
                MaterialHandle dotMat = cgs->media.friendMaterials[1];
                UI_DrawHandlePic(x, y, w, h, rect->horzAlign, rect->vertAlign, fadedColor, dotMat);
            } else {
                /* line 299-303: Draw direction indicator and/or friend material */
                if (friendMat == NULL || iconAlpha != 1.0f) {
                    /* line 300: Draw direction material */
                    cgs = *(cgs_t **)cgs_glob;
                    MaterialHandle dirMat = cgs->media.friendMaterials[pingFlash];
                    CG_DrawRotatedPic(x, y, w, h, rect->horzAlign, rect->vertAlign, drawAngle, actorColor, dirMat);
                }
                if (friendMat != NULL) {
                    /* line 303: Draw friend material overlay */
                    CG_DrawRotatedPic(x, y, w, h, rect->horzAlign, rect->vertAlign, drawAngle, fadedColor, friendMat);
                }
            }

            cg = *(cg_t **)cg_glob;
            continue;
        }

        /* Normal case: position is absolute coordinates */
        /* line 65-66: Compute position delta */
        vec2_t posDelta;
        posDelta[0] = posX - cgBase->refdef.vieworg[0];
        posDelta[1] = posY - cgBase->refdef.vieworg[1];

        /* line 233: Compute yaw to target */
        float yawTo = vectoyaw(posDelta);
        cgBase = *(cg_t **)cg_glob;
        yawTo = AngleNormalize360(yawTo - cgBase->compPointerYaw);

        /* line 134/81: Compute distance */
        float dist = sqrtf(posDelta[0] * posDelta[0] + posDelta[1] * posDelta[1]);

        /*
         * line 237-250: Compute iconAlpha2 (fade based on distance beyond maxRange)
         * and radius (compass pixel distance from center).
         *
         * iconAlpha2: lerp from 1.0 to clampSat as dist goes from maxRange to clampDist.
         *   If dist <= maxRange, iconAlpha2 = 1.0
         *   If dist >= clampDist, iconAlpha2 = clampSat
         *
         * radius: standard compass radius using clamped distance in [minRange, maxRange].
         */
        float clampDistVal = dvar_value(dvar_compassClampDist);
        float maxRangeVal = dvar_value(dvar_compassMaxRange);
        float minRangeVal = dvar_value(dvar_compassMinRange);
        float minSatVal = dvar_value(dvar_compassMinSaturation);
        float clampSatVal = dvar_value(dvar_compassClampSaturation);
        float compassSzVal = dvar_value(dvar_compassSize);

        /* Compute the alpha-for-distance value (clamp between maxRange and clampDist) */
        float alphaClampedDist;
        if (dist > clampDistVal) {
            alphaClampedDist = clampDistVal;
        } else if (dist >= maxRangeVal) {
            alphaClampedDist = dist;
        } else {
            alphaClampedDist = maxRangeVal;
        }
        {
            float alphaFrac = (alphaClampedDist - maxRangeVal) / (clampDistVal - maxRangeVal);
            iconAlpha2 = 1.0f + alphaFrac * (clampSatVal - 1.0f);
        }

        /* Compute the radius (clamp distance between minRange and maxRange) */
        {
            float radiusDist = dist;
            if (radiusDist > maxRangeVal)
                radiusDist = maxRangeVal;
            if (radiusDist < minRangeVal)
                radiusDist = minRangeVal;
            float rangeFrac = (radiusDist - minRangeVal) / (maxRangeVal - minRangeVal);
            float saturation = minSatVal + rangeFrac * (1.0f - minSatVal);
            radius = (float)((double)compassSzVal * 43.75 * (double)saturation);
        }

        /* line 257: Convert yaw to radians and compute sin/cos */
        float radians2 = (float)((double)yawTo * 0.017453292519943295);
        float sinVal2 = sinf(radians2);
        float cosVal2 = cosf(radians2);

        /* line 82-83: Compute icon size */
        float compassSzFinal = dvar_value(dvar_compassSize);
        float w2 = compassSzFinal * 10.0f;
        float h2 = dvar_value(dvar_compassSize) * 10.0f;

        /* line 259-260: Compute draw position */
        float x2 = centerX + w2 * (-0.5f) - radius * sinVal2;
        float y2 = centerY + h2 * (-0.5f) - radius * cosVal2;

        /* line 262 */
        CG_ApplySplitScreenCompassScale(&x2, &y2, &w2, &h2);

        /* line 265: Compute draw angle */
        cgBase = *(cg_t **)cg_glob;
        float refYaw2 = cgBase->refdefViewAngles[1];
        float actorYaw2 = cgBase->compassActors[i].fLastYaw;
        float drawAngle2 = AngleNormalize360(refYaw2 - actorYaw2);

        /* line 267-270: Ping flash calculation */
        int pingTime2 = cgBase->compassActors[i].pingTime;
        cgTime = cgBase->time;
        int pingFlash2 = 0;
        if (pingTime2 > cgTime) {
            int elapsed2 = pingTime2 - cgTime;
            int mod2 = elapsed2 % 500;
            if (mod2 > 249) {
                pingFlash2 = 1;
            }
        }

        /* line 276: Check begin fade time for ping display */
        int beginFade2 = cgBase->compassActors[i].beginFadeTime;
        float pingFadeTime2 = dvar_value(dvar_compassPingFadeTime);
        float fadeEnd2 = (float)beginFade2 + pingFadeTime2 * 1000.0f;
        MaterialHandle friendMat2 = NULL;

        if ((float)cgTime < fadeEnd2) {
            if (cgTime >= beginFade2) {
                iconAlpha2 = 1.0f;
            } else {
                iconAlpha2 = 1.0f + (float)(cgTime - beginFade2) / (pingFadeTime2 * -1000.0f);
            }
            cgs = *(cgs_t **)cgs_glob;
            friendMat2 = cgs->media.compassping_friendlyfiring;
        }

        /* line 456-459: Build per-actor color */
        vec4_t actorColor2;
        actorColor2[0] = color[0];
        actorColor2[1] = color[1];
        actorColor2[2] = color[2];
        actorColor2[3] = color[3] < compassFadeOutAlpha ? color[3] : compassFadeOutAlpha;

        /* line 290-291: Clamp iconAlpha */
        iconAlpha2 = compassFadeOutAlpha < iconAlpha2 ? compassFadeOutAlpha : iconAlpha2;

        /* line 293: Draw based on ping state */
        if (pingFlash2 == 1) {
            cgs = *(cgs_t **)cgs_glob;
            MaterialHandle dotMat2 = cgs->media.friendMaterials[1];
            UI_DrawHandlePic(x2, y2, w2, h2, rect->horzAlign, rect->vertAlign, fadedColor, dotMat2);
        } else {
            if (friendMat2 == NULL || iconAlpha2 != 1.0f) {
                cgs = *(cgs_t **)cgs_glob;
                MaterialHandle dirMat2 = cgs->media.friendMaterials[pingFlash2];
                CG_DrawRotatedPic(x2, y2, w2, h2, rect->horzAlign, rect->vertAlign, drawAngle2, actorColor2, dirMat2);
            }
            if (friendMat2 != NULL) {
                CG_DrawRotatedPic(x2, y2, w2, h2, rect->horzAlign, rect->vertAlign, drawAngle2, fadedColor, friendMat2);
            }
        }

        cg = *(cg_t **)cg_glob;
    }

    /* line 309: Draw weapon pings (separate loop over all 64 actors) */
    {
        cg_t *cgBase2 = *(cg_t **)cg_glob;
        for (i = 0; i < COMPASS_ACTOR_COUNT; i++) {
            compassactor_t *actor2 = &cgBase2->compassActors[i];

            /* line 312: Check enemy flag */
            if (actor2->enemy == 0)
                continue;

            /* line 314: Check if ping is still valid */
            int pingBeginFade = actor2->beginFadeTime;
            cgBase2 = *(cg_t **)cg_glob;
            cg_t *cg2 = cgBase2;
            float pingFadeVal = dvar_value(dvar_compassPingFadeTime);
            float pingEnd = (float)pingBeginFade + pingFadeVal * 1000.0f;
            int cgTime2 = cg2->time;
            if ((float)cgTime2 > pingEnd)
                continue;
            if (pingBeginFade == 0)
                continue;

            /* line 65-66: Compute position delta */
            vec2_t posDelta2;
            posDelta2[0] = actor2->vLastPos[0] - cg2->refdef.vieworg[0];
            posDelta2[1] = actor2->vLastPos[1] - cg2->refdef.vieworg[1];

            /* line 318: Compute yaw and distance */
            float yaw = vectoyaw(posDelta2);
            yaw = AngleNormalize360(yaw - cg2->compPointerYaw);

            float pingDist = sqrtf(posDelta2[0] * posDelta2[0] + posDelta2[1] * posDelta2[1]);

            /* line 321: Compute radius */
            float pingRadius = CompassDistToRadius(pingDist);

            /* line 327: Convert to radians */
            float pingRadians = (float)((double)yaw * 0.017453292519943295);
            float pingSin = sinf(pingRadians);
            float pingCos = cosf(pingRadians);

            /* line 82-83: Icon size */
            float compassSz3 = dvar_value(dvar_compassSize);
            float pw = compassSz3 * 10.0f;
            float ph = dvar_value(dvar_compassSize) * 10.0f;

            /* line 329-330: Position */
            float px = centerX + pw * (-0.5f) - pingRadius * pingSin;
            float py = centerY + ph * (-0.5f) - pingRadius * pingCos;

            CG_ApplySplitScreenCompassScale(&px, &py, &pw, &ph);

            /* line 334-337: Compute fade alpha */
            float pingAlpha;
            int cgTime3 = cg2->time;
            if (pingBeginFade >= cgTime3) {
                pingAlpha = 1.0f;
            } else {
                float elapsed = (float)(cgTime3 - pingBeginFade);
                float fadeRange = dvar_value(dvar_compassPingFadeTime) * -1000.0f;
                pingAlpha = 1.0f + elapsed / fadeRange;
            }

            /* line 341: Clamp to compassFadeOutAlpha */
            pingAlpha = compassFadeOutAlpha < pingAlpha ? compassFadeOutAlpha : pingAlpha;
            fadedColor[3] = pingAlpha;

            /* line 343: Draw ping */
            cgs = *(cgs_t **)cgs_glob;
            MaterialHandle pingMat = cgs->media.compassping_enemyfiring;
            UI_DrawHandlePic(px, py, pw, ph, rect->horzAlign, rect->vertAlign, fadedColor, pingMat);
        }
    }
}
