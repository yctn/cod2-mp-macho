/* Converted to C from ASM: cg_playerstate_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_playerstate_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

/* External globals (pointer-to-pointer indirections from binary) */
extern char **cg_glob;    /* 0x195f584 -- pointer to cg_t base */
extern char **cg_globUI;  /* 0x195ecb4 -- pointer to cg_t base (UI/alternate) */
extern char **cg_globSnap; /* 0x195f950 -- pointer to snap/cgs base */

/* External function declarations */
extern void AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern const float AngleNormalize360(const float angle);
extern float randomf(void);
extern void CL_SetADS(int ads);
extern void CG_SetEquippedOffHand(int offHandIndex);
extern void CG_HoldBreathInit(void);
extern void CG_ResetLowHealthOverlay(void);
extern void CG_MenuShowNotify(int menuToShow);
extern void CG_EntityEvent(centity_t *cent, int event);

void CG_Respawn(void);
void CG_DamageFeedback(int yawByte, int pitchByte, int damage);
void CG_TransitionPlayerState(playerState_t *ps, playerState_t *ops);

/*
 * cg_t field offsets from binary layout (may differ from compiled struct).
 * These are raw byte offsets from the cg_t base pointer.
 */
#define CG_SNAP_PTR            0x20     /* snapshot_t* snap */
#define CG_OFF_25BB0           0x25bb0  /* field copied to damageTime area */
#define CG_OFF_25BBC           0x25bbc  /* zeroed on respawn */
#define CG_OFF_25BC4           0x25bc4  /* memcpy dest (snap->ps area) */
#define CG_OFF_25C94           0x25c94  /* offHandIndex-related, copied to 0x2be70 */
#define CG_OFF_25C98           0x25c98  /* copied to 0x2be50 */
#define CG_OFF_28490           0x28490  /* 48-byte region zeroed (rep stosl 0xc dwords) */
#define CG_OFF_284C4           0x284c4  /* vec3 zeroed */
#define CG_OFF_285D4           0x285d4  /* vec3 zeroed */
#define CG_OFF_285E0           0x285e0  /* vec3 zeroed */
#define CG_OFF_285EC           0x285ec  /* vec3 zeroed */
#define CG_OFF_28594           0x28594  /* refdef right vector (3 floats) */
#define CG_OFF_285A0           0x285a0  /* refdef up vector (3 floats) */
#define CG_OFF_2826C           0x2826c  /* predictedPlayerEntity (centity_t) */
#define CG_OFF_2BDE8           0x2bde8  /* zeroed */
#define CG_OFF_2BDEC           0x2bdec  /* zeroed */
#define CG_OFF_2BE30           0x2be30  /* zeroed */
#define CG_OFF_2BE48           0x2be48  /* attackerTime store */
#define CG_OFF_2BE50           0x2be50  /* copy from 25c98 */
#define CG_OFF_2BE54           0x2be54  /* copy from 25bb0 */
#define CG_OFF_2BE70           0x2be70  /* copy from 25c94 */
#define CG_OFF_2BE74           0x2be74  /* viewDamage[0].time -- memset 0x60 bytes */
#define CG_OFF_2BE80           0x2be80  /* viewDamage[i].time for comparison */
#define CG_OFF_2BED4           0x2bed4  /* zeroed on respawn; snap serverTime on damage */
#define CG_OFF_2BF0C           0x2bf0c  /* damageTime = time + 500 */
#define CG_OFF_2BF10           0x2bf10  /* damageX */
#define CG_OFF_2BF14           0x2bf14  /* damageY */
#define CG_OFF_2BF1C           0x2bf1c  /* zeroed */
#define CG_OFF_2C030           0x2c030  /* vec3 zeroed */
#define CG_OFF_2C03C           0x2c03c  /* vec3 zeroed */
#define CG_OFF_2C0A4           0x2c0a4  /* vec3 zeroed */
#define CG_OFF_2C0B0           0x2c0b0  /* vec3 zeroed */
#define CG_OFF_2C50C           0x2c50c  /* memset 0x90 bytes */
#define CG_OFF_2CD10           0x2cd10  /* zeroed */

/* Offset of eventParm in binary's centity layout */
#define CENT_EVENT_PARM        0x190

/* Helper macros for byte-offset pointer access */
#define CG_INT(base, off)      (*(int *)((base) + (off)))
#define CG_FLOAT(base, off)    (*(float *)((base) + (off)))
#define CG_PTR(base, off)      (*(char **)((base) + (off)))

static void VectorClear3Int(char *base, int off)
{
    CG_INT(base, off + 0) = 0;
    CG_INT(base, off + 4) = 0;
    CG_INT(base, off + 8) = 0;
}

/* line 83 */
void CG_Respawn(void)
{
    char *cg = *cg_glob;
    char *snap;

    /* line 85: cg->field_25bbc = 0 */
    CG_INT(cg, CG_OFF_25BBC) = 0;

    /* line 88: memcpy(cg + 0x25bc4, snap->ps + 0xc, 0x26a8)
     * snap is at cg->snap (offset 0x20), ps starts at snap + 0xc */
    snap = CG_PTR(cg, CG_SNAP_PTR);
    memcpy(cg + CG_OFF_25BC4, snap + 0xc, 0x26a8);

    /* line 91: cg->field_2be50 = cg->field_25c98 */
    CG_INT(cg, CG_OFF_2BE50) = CG_INT(cg, CG_OFF_25C98);

    /* line 92: cg->field_2be54 = cg->field_25bb0 */
    CG_INT(cg, CG_OFF_2BE54) = CG_INT(cg, CG_OFF_25BB0);

    /* line 93: cg->field_2be70 = cg->field_25c94 */
    CG_INT(cg, CG_OFF_2BE70) = CG_INT(cg, CG_OFF_25C94);

    /* lines 95-97: zero three fields */
    CG_INT(cg, CG_OFF_2BDE8) = 0;
    CG_INT(cg, CG_OFF_2BDEC) = 0;
    CG_INT(cg, CG_OFF_2BE30) = 0;

    /* lines 99-101: zero three vec3 regions (inline VectorClear) */
    VectorClear3Int(cg, CG_OFF_285D4);
    VectorClear3Int(cg, CG_OFF_285E0);
    VectorClear3Int(cg, CG_OFF_285EC);

    /* lines 103-104: zero two more vec3 regions */
    VectorClear3Int(cg, CG_OFF_2C03C);
    VectorClear3Int(cg, CG_OFF_2C030);

    /* line 106 */
    CG_INT(cg, CG_OFF_2BF1C) = 0;

    /* line 108: memset(cg + 0x28490, 0, 48) -- rep stosl 0xc dwords */
    memset(cg + CG_OFF_28490, 0, 48);

    /* line 110 */
    CG_INT(cg, CG_OFF_2BED4) = 0;

    /* lines 111-112: zero damageX and damageY */
    CG_INT(cg, CG_OFF_2BF10) = 0;
    CG_INT(cg, CG_OFF_2BF14) = 0;

    /* lines 113-114: zero two more vec3 regions */
    VectorClear3Int(cg, CG_OFF_2C0A4);
    VectorClear3Int(cg, CG_OFF_2C0B0);

    /* line 116: memset(cg + 0x2be74, 0, 0x60) -- viewDamage array (8 * 12 = 96 = 0x60) */
    memset(cg + CG_OFF_2BE74, 0, 0x60);

    /* line 117: memset(cg + 0x2c50c, 0, 0x90) */
    memset(cg + CG_OFF_2C50C, 0, 0x90);

    /* line 119: zero another vec3 */
    VectorClear3Int(cg, CG_OFF_284C4);

    /* line 121 */
    CG_INT(cg, CG_OFF_2CD10) = 0;

    /* line 124: *(*(cg_globUI) + 8) = 0 */
    {
        char *uiBase = *cg_globUI;
        CG_INT(uiBase, 8) = 0;
    }

    /* line 127 */
    CL_SetADS(0);

    /* line 130: CG_SetEquippedOffHand(cg->field_25c94) */
    CG_SetEquippedOffHand(CG_INT(cg, CG_OFF_25C94));

    /* line 132 */
    CG_HoldBreathInit();

    /* line 134: tail-call to CG_ResetLowHealthOverlay */
    CG_ResetLowHealthOverlay();
}

/* line 18 */
void CG_DamageFeedback(int yawByte, int pitchByte, int damage)
{
    char *cg;
    float count;
    float negCount;
    vec3_t angles;
    vec3_t dir;
    float dot;
    int slot;
    int i;
    char *snap;

    /* line 28: cg->attackerTime = cg->field_25bb0 (time) */
    cg = *cg_glob;
    CG_INT(cg, CG_OFF_2BE48) = CG_INT(cg, CG_OFF_25BB0);

    /* line 30: count = (float)damage * 0.2f */
    count = (float)damage * 0.2f;

    /* line 32-34: clamp count to [5.0, 90.0] */
    if (count < 5.0f) {
        count = 5.0f;
        negCount = -5.0f;
    } else if (count > 90.0f) {
        count = 90.0f;
        negCount = -90.0f;
    } else {
        negCount = -count;
    }

    /* line 38: if yawByte == 255 and pitchByte == 255, use non-directional damage */
    if (yawByte == 255 && pitchByte == 255) {
        /* lines 40-41: non-directional damage */
        cg = *cg_glob;
        CG_FLOAT(cg, CG_OFF_2BF14) = 0.0f;
        CG_FLOAT(cg, CG_OFF_2BF10) = negCount;
    } else {
        /* line 47: yaw angle = (float)yawByte / 255.0f * 360.0f */
        float yaw = (float)yawByte / 255.0f * 360.0f;
        /* line 49: pitch angle = (float)pitchByte / 255.0f * 360.0f */
        float pitch = (float)pitchByte / 255.0f * 360.0f;

        /* lines 49-51: set up angles vector */
        angles[0] = pitch;
        angles[1] = yaw;
        angles[2] = 0.0f;

        /* line 53: compute direction vectors from angles */
        AngleVectors(angles, dir, NULL, NULL);

        /* line 55: reload cg pointer after function call */
        cg = *cg_glob;

        /* lines 55-56: compute dot products with refdef axes
         * cg->damageY = DotProduct(dir, cg->refdef_up) * negCount
         * cg->damageX = DotProduct(dir, cg->refdef_right) * count */
        {
            float *up = (float *)(cg + CG_OFF_285A0);
            float *right = (float *)(cg + CG_OFF_28594);

            /* damageY = DotProduct(dir, up) * negCount */
            dot = dir[0] * up[0] + dir[1] * up[1] + dir[2] * up[2];
            CG_FLOAT(cg, CG_OFF_2BF14) = dot * negCount;

            /* damageX = DotProduct(dir, right) * count */
            dot = dir[0] * right[0] + dir[1] * right[1] + dir[2] * right[2];
            CG_FLOAT(cg, CG_OFF_2BF10) = dot * count;
        }

        /* lines 59-63: find the viewDamage slot with the smallest time
         * viewDamage entries are 12 bytes each: { int time, int duration, float yaw } */
        slot = 0;
        for (i = 1; i < 8; i++) {
            int thisTime = CG_INT(cg, CG_OFF_2BE74 + i * 12);
            int slotTime = CG_INT(cg, CG_OFF_2BE74 + slot * 12);
            if (thisTime < slotTime) {
                slot = i;
            }
        }

        /* line 65: viewDamage[slot].time = snap->serverTime */
        snap = CG_PTR(cg, CG_SNAP_PTR);
        CG_INT(cg, CG_OFF_2BE74 + slot * 12) = CG_INT(snap, 8);

        /* line 66: viewDamage[slot].duration = (*cg_globSnap)->serverTime */
        {
            char *snapBase = *cg_globSnap;
            CG_INT(cg, CG_OFF_2BE74 + slot * 12 + 4) = CG_INT(snapBase, 8);
        }

        /* line 67: viewDamage[slot].yaw = AngleNormalize360(yaw + (randomf() - 0.5f) * 20.0f) */
        {
            float r = randomf();
            float jitteredYaw = yaw + (r - 0.5f) * 20.0f;
            float normYaw = AngleNormalize360(jitteredYaw);
            CG_FLOAT(cg, CG_OFF_2BE74 + slot * 12 + 8) = normYaw;
        }

        /* Need to re-read cg after function calls */
        cg = *cg_glob;
    }

    /* line 70: cg->damageTime = cg->time + 500 */
    cg = *cg_glob;
    CG_INT(cg, CG_OFF_2BF0C) = CG_INT(cg, CG_OFF_25BB0) + 500;

    /* line 71: cg->field_2bed4 = snap->serverTime */
    snap = CG_PTR(cg, CG_SNAP_PTR);
    CG_INT(cg, CG_OFF_2BED4) = CG_INT(snap, 8);

    /* line 72 */
    CG_MenuShowNotify(0);
}

/* line 173: CG_TransitionPlayerState
 * This function processes player state transitions, checking for new events
 * and optionally calling CG_DamageFeedback for damage events.
 *
 * Inner logic (lines 149-165) iterates backward through the event sequence
 * to fire any new events that occurred between ops and ps.
 */
void CG_TransitionPlayerState(playerState_t *ps, playerState_t *ops)
{
    char *cg;
    char *cent;
    int i;
    int idx;
    int event;

    /* line 176: if ps->damageEvent != ops->damageEvent */
    if (ps->damageEvent != ops->damageEvent) {
        /* line 178: if ps->damageCount != 0, call CG_DamageFeedback */
        if (ps->damageCount != 0) {
            CG_DamageFeedback(ps->damageYaw, ps->damagePitch, ps->damageCount);
        }
    }

    /* line 149: get cent = cg_base + 0x2826c (predictedPlayerEntity) */
    cg = *cg_glob;
    cent = cg + CG_OFF_2826C;

    /* line 151: iterate from ps->eventSequence - 4 up to ps->eventSequence */
    i = ps->eventSequence - 4;

    while (i < ps->eventSequence) {
        /* line 154: if i < ops->eventSequence, skip old events */
        if (i < ops->eventSequence) {
            /* But if i is within 4 of ops->eventSequence, check for changes */
            if (i < ops->eventSequence - 4) {
                i++;
                continue;
            }
            idx = i & 3;
            event = ps->events[idx];
            if (event == ops->events[idx]) {
                i++;
                continue;
            }
        } else {
            /* i >= ops->eventSequence: this is a new event, always process it */
            idx = i & 3;
            event = ps->events[idx];
        }

        /* line 160: set cent->eventParm from ps->eventParms[idx] */
        CG_INT(cent, CENT_EVENT_PARM) = ps->eventParms[idx];

        /* line 161: fire the event */
        CG_EntityEvent((centity_t *)cent, event);

        i++;
    }
}
