/* ASM dump from: bg_misc.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_misc.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 */

extern const dvar_t *player_view_pitch_up; /* 0x0 */
extern const dvar_t *player_view_pitch_down; /* 0x0 */
extern const dvar_t *bg_ladder_yawcap; /* 0x0 */
extern const dvar_t *bg_prone_yawcap; /* 0x0 */
extern const dvar_t *bg_foliagesnd_minspeed; /* 0x0 */
extern const dvar_t *bg_foliagesnd_maxspeed; /* 0x0 */
extern const dvar_t *bg_foliagesnd_slowinterval; /* 0x0 */
extern const dvar_t *bg_foliagesnd_fastinterval; /* 0x0 */
extern const dvar_t *bg_foliagesnd_resetinterval; /* 0x0 */
extern const dvar_t *bg_fallDamageMinHeight; /* 0x0 */
extern const dvar_t *bg_fallDamageMaxHeight; /* 0x0 */
extern const dvar_t *inertiaMax; /* 0x0 */
extern const dvar_t *inertiaDebug; /* 0x0 */
extern const dvar_t *inertiaAngle; /* 0x0 */
extern const dvar_t *friction; /* 0x0 */
extern const dvar_t *stopspeed; /* 0x0 */
extern const dvar_t *bg_swingSpeed; /* 0x0 */
extern const dvar_t *bg_bobAmplitudeStanding; /* 0x0 */
extern const dvar_t *bg_bobAmplitudeDucked; /* 0x0 */
extern const dvar_t *bg_bobAmplitudeProne; /* 0x0 */
extern const dvar_t *bg_bobMax; /* 0x0 */
extern const dvar_t *bg_aimSpreadMoveSpeedThreshold; /* 0x0 */
extern const dvar_t *player_breath_hold_time; /* 0x0 */
extern const dvar_t *player_breath_gasp_time; /* 0x0 */
extern const dvar_t *player_breath_fire_delay; /* 0x0 */
extern const dvar_t *player_breath_gasp_scale; /* 0x0 */
extern const dvar_t *player_breath_hold_lerp; /* 0x0 */
extern const dvar_t *player_breath_gasp_lerp; /* 0x0 */
extern const dvar_t *player_breath_snd_lerp; /* 0x0 */
extern const dvar_t *player_breath_snd_delay; /* 0x0 */
extern const dvar_t *player_toggleBinoculars; /* 0x0 */
extern const dvar_t *player_scopeExitOnDamage; /* 0x0 */
extern const dvar_t *player_adsExitDelay; /* 0x0 */
extern const dvar_t *player_dmgtimer_timePerPoint; /* 0x0 */
extern const dvar_t *player_dmgtimer_maxTime; /* 0x0 */
extern const dvar_t *player_dmgtimer_minScale; /* 0x0 */
extern const dvar_t *player_dmgtimer_stumbleTime; /* 0x0 */
extern const dvar_t *player_dmgtimer_flinchTime; /* 0x0 */
extern char * eventnames[199]; /* 0x0 */
extern const int singleClientEvents[7]; /* 0x0 */
extern const dvar_t *player_moveThreshhold; /* 0x0 */
extern const dvar_t *player_footstepsThreshhold; /* 0x0 */
extern const dvar_t *player_strafeSpeedScale; /* 0x0 */
extern const dvar_t *player_backSpeedScale; /* 0x0 */
extern const dvar_t *player_spectateSpeedScale; /* 0x0 */
extern const dvar_t *player_turnAnims; /* 0x0 */

/* Extern declarations for called functions */
extern int I_stricmp(const char *s1, const char *s2);
extern int G_GetWeaponIndexForName(const char *name);
extern qboolean BG_DoesWeaponNeedSlot(int weapon);
extern int BG_GetMaxPickupableAmmo(const playerState_t *ps, int weapon);
extern qboolean BG_WeaponIsClipOnly(int weapon);
extern void Com_Error(errorParm_t code, const char *fmt, ...);
extern const char *va(const char *format, ...);

void BG_RegisterDvars(void);
const gitem_t * BG_FindItemForWeapon(int weapon);
const gitem_t * G_FindItem(const char *pickupName);
void BG_AddPredictableEventToPlayerstate(int newEvent, int eventParm, playerState_t *ps);
void BG_PlayerStateToEntityState(playerState_t *ps, entityState_t *s, qboolean snap, int handler);
void BG_EvaluateTrajectoryDelta(const trajectory_t *tr, int atTime, vec_t *result);
qboolean BG_CanItemBeGrabbed(const entityState_t *ent, const playerState_t *ps, qboolean bTouched);
qboolean BG_CheckProneValid(int passEntityNum, const vec_t *vPos, const float fSize, const float fHeight, const float fYaw, float *pfTorsoHeight, float *pfTorsoPitch, float *pfWaistPitch, const qboolean bAlreadyProne, const qboolean bOnGround, vec_t *vGroundNormal, int handler, proneCheckType_t proneCheckType, float prone_feet_dist);
qboolean BG_CheckProne(int passEntityNum, const vec_t *vPos, const float fSize, const float fHeight, const float fYaw, float *pfTorsoHeight, float *pfTorsoPitch, float *pfWaistPitch, const qboolean bAlreadyProne, const qboolean bOnGround, vec_t *vGroundNormal, int handler, proneCheckType_t proneCheckType, float prone_feet_dist);
void BG_EvaluateTrajectory(const trajectory_t *tr, int atTime, vec_t *result);
qboolean BG_PlayerTouchesItem(playerState_t *ps, entityState_t *item, int atTime);

/* line 341 */
__attribute__((naked))
void BG_RegisterDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 341 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 355 */
        "movl $0x42b40000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x42aa0000, %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21b9d8, (%esp)\n" /* "player_view_pitch_up" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_view_pitch_up\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 356 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21b9f0, (%esp)\n" /* "player_view_pitch_down" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_view_pitch_down\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 359 */
        "movl $0x43b40000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x42c80000, 4(%esp)\n"
        "movl $0x21ba08, (%esp)\n" /* "bg_ladder_yawcap" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_ladder_yawcap\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 360 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21ba1c, (%esp)\n" /* "bg_prone_yawcap" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_prone_yawcap\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 362 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x42200000, 4(%esp)\n"
        "movl $0x21ba2c, (%esp)\n" /* "bg_foliagesnd_minspeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_foliagesnd_minspeed\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 363 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x43340000, 4(%esp)\n"
        "movl $0x21ba44, (%esp)\n" /* "bg_foliagesnd_maxspeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_foliagesnd_maxspeed\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 364 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x5dc, 4(%esp)\n"
        "movl $0x21ba5c, (%esp)\n" /* "bg_foliagesnd_slowinterval" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, bg_foliagesnd_slowinterval\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 365 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1f4, 4(%esp)\n"
        "movl $0x21ba78, (%esp)\n" /* "bg_foliagesnd_fastinterval" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, bg_foliagesnd_fastinterval\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 366 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1f4, 4(%esp)\n"
        "movl $0x21ba94, (%esp)\n" /* "bg_foliagesnd_resetinterval" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, bg_foliagesnd_resetinterval\n"
        "movl $0x1188, 0x10(%esp)\n" /* line 369 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0x3f800000, %edi\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x43800000, 4(%esp)\n"
        "movl $0x21bab0, (%esp)\n" /* "bg_fallDamageMinHeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_fallDamageMinHeight\n"
        "movl $0x1188, 0x10(%esp)\n" /* line 370 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x43f00000, 4(%esp)\n"
        "movl $0x21bac8, (%esp)\n" /* "bg_fallDamageMaxHeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_fallDamageMaxHeight\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 376 */
        "movl $0x447a0000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x42480000, 4(%esp)\n"
        "movl $0x21bae0, (%esp)\n" /* "inertiaMax" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, inertiaMax\n"
        "movl $0x1180, 8(%esp)\n" /* line 377 */
        "movl $0, 4(%esp)\n"
        "movl $0x21baec, (%esp)\n" /* "inertiaDebug" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, inertiaDebug\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 379 */
        "movl %edi, 0xc(%esp)\n"
        "movl $0xbf800000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21bafc, (%esp)\n" /* "inertiaAngle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, inertiaAngle\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 384 */
        "movl $0x42c80000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x40b00000, 4(%esp)\n"
        "movl $0x21bb0c, (%esp)\n" /* "friction" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, friction\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 385 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x42c80000, 4(%esp)\n"
        "movl $0x21bb18, (%esp)\n" /* "stopspeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, stopspeed\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 387 */
        "movl %edi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3e4ccccd, 4(%esp)\n"
        "movl $0x21bb24, (%esp)\n" /* "bg_swingSpeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_swingSpeed\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 389 */
        "movl %edi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3be56042, 4(%esp)\n"
        "movl $0x21bb34, (%esp)\n" /* "bg_bobAmplitudeStanding" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_bobAmplitudeStanding\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 390 */
        "movl %edi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3bf5c28f, 4(%esp)\n"
        "movl $0x21bb4c, (%esp)\n" /* "bg_bobAmplitudeDucked" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_bobAmplitudeDucked\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 391 */
        "movl %edi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3cf5c28f, 4(%esp)\n"
        "movl $0x21bb64, (%esp)\n" /* "bg_bobAmplitudeProne" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_bobAmplitudeProne\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 392 */
        "movl $0x42100000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x41000000, 4(%esp)\n"
        "movl $0x21bb7c, (%esp)\n" /* "bg_bobMax" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_bobMax\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 394 */
        "movl $0x43960000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x41300000, 4(%esp)\n"
        "movl $0x21bb88, (%esp)\n" /* "bg_aimSpreadMoveSpeedThreshold" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, bg_aimSpreadMoveSpeedThreshold\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 396 */
        "movl $0x41f00000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x40900000, %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x21bba8, (%esp)\n" /* "player_breath_hold_time" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_breath_hold_time\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 397 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21bbc0, (%esp)\n" /* "player_breath_gasp_time" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_breath_gasp_time\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 398 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21bbd8, (%esp)\n" /* "player_breath_fire_delay" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_breath_fire_delay\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 399 */
        "movl $0x42480000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x21bbf4, (%esp)\n" /* "player_breath_gasp_scale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_breath_gasp_scale\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 400 */
        "movl $0x42480000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x40800000, 4(%esp)\n"
        "movl $0x21bc10, (%esp)\n" /* "player_breath_hold_lerp" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_breath_hold_lerp\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 401 */
        "movl $0x42480000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x40c00000, 4(%esp)\n"
        "movl $0x21bc28, (%esp)\n" /* "player_breath_gasp_lerp" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_breath_gasp_lerp\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 402 */
        "movl $0x42c80000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x40000000, 4(%esp)\n"
        "movl $0x21bc40, (%esp)\n" /* "player_breath_snd_lerp" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_breath_snd_lerp\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 403 */
        "movl $0x40000000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21bc58, (%esp)\n" /* "player_breath_snd_delay" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_breath_snd_delay\n"
        "movl $0x1100, 8(%esp)\n" /* line 408 */
        "movl $1, 4(%esp)\n"
        "movl $0x21bc70, (%esp)\n" /* "player_toggleBinoculars" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, player_toggleBinoculars\n"
        "movl $0x1180, 8(%esp)\n" /* line 410 */
        "movl $0, 4(%esp)\n"
        "movl $0x21bc88, (%esp)\n" /* "player_scopeExitOnDamage" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, player_scopeExitOnDamage\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 411 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21bca4, (%esp)\n" /* "player_adsExitDelay" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, player_adsExitDelay\n"
        "movl $0x11c0, 0x10(%esp)\n" /* line 419 */
        "movl $0x41a00000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0x322bcc77, 8(%esp)\n"
        "movl $0x41200000, 4(%esp)\n"
        "movl $0x21bcb8, (%esp)\n" /* "player_moveThreshhold" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_moveThreshhold\n"
        "movl $0x11c0, 0x10(%esp)\n" /* line 420 */
        "movl $0x47435000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21bcd0, (%esp)\n" /* "player_footstepsThreshhold" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_footstepsThreshhold\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 427 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3f4ccccd, 4(%esp)\n"
        "movl $0x21bcec, (%esp)\n" /* "player_strafeSpeedScale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_strafeSpeedScale\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 428 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3f333333, 4(%esp)\n"
        "movl $0x21bd04, (%esp)\n" /* "player_backSpeedScale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_backSpeedScale\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 430 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x40000000, 4(%esp)\n"
        "movl $0x21bd1c, (%esp)\n" /* "player_spectateSpeedScale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_spectateSpeedScale\n"
        "movl $0x1180, 8(%esp)\n" /* line 432 */
        "movl $0, 4(%esp)\n"
        "movl $0x21bd38, (%esp)\n" /* "player_turnAnims" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, player_turnAnims\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 442 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x42c80000, 4(%esp)\n"
        "movl $0x21bd4c, (%esp)\n" /* "player_dmgtimer_timePerPoint" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_dmgtimer_timePerPoint\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 443 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x443b8000, 4(%esp)\n"
        "movl $0x21bd6c, (%esp)\n" /* "player_dmgtimer_maxTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_dmgtimer_maxTime\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 444 */
        "movl %edi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21bd84, (%esp)\n" /* "player_dmgtimer_minScale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, player_dmgtimer_minScale\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 445 */
        "movl $0x7d0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1f4, 4(%esp)\n"
        "movl $0x21bda0, (%esp)\n" /* "player_dmgtimer_stumbleTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, player_dmgtimer_stumbleTime\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 446 */
        "movl $0x7d0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1f4, 4(%esp)\n"
        "movl $0x21bdbc, (%esp)\n" /* "player_dmgtimer_flinchTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, player_dmgtimer_flinchTime\n"
        "calll Jump_RegisterDvars\n" /* line 452 */
        "addl $0x2c, %esp\n" /* line 454 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Mantle_RegisterDvars\n" /* line 453 */
    );
}

/* line 463 */
const gitem_t *BG_FindItemForWeapon(int weapon)
{
    char *base = *(char **)0x195eda8;
    return (const gitem_t *)(base + weapon * 44);
}

/* line 476 */
const gitem_t *G_FindItem(const char *pickupName)
{
    int iIndex;
    int count;
    char *base;
    int weaponIndex;

    count = **(int **)0x195edac;
    base = *(char **)0x195eda8;

    for (iIndex = 0x81; iIndex < count; iIndex++) {
        char *it = base + iIndex * 44;
        if (I_stricmp(*(const char **)(it + 0x14), pickupName) == 0) {
            return (const gitem_t *)it;
        }
        if (I_stricmp(*(const char **)it, pickupName) == 0) {
            return (const gitem_t *)it;
        }
    }

    weaponIndex = G_GetWeaponIndexForName(pickupName);
    if (weaponIndex == 0) {
        return NULL;
    }
    return (const gitem_t *)(base + weaponIndex * 44);
}

/* line 793 */
void BG_AddPredictableEventToPlayerstate(int newEvent, int eventParm, playerState_t *ps)
{
    int seq;
    int index;

    if (newEvent == 0)
        return;

    seq = *(int *)((char *)ps + 0xa4);
    index = seq & 3;
    *(int *)((char *)ps + 0xa8 + index * 4) = (unsigned char)newEvent;
    *(int *)((char *)ps + 0xb8 + index * 4) = (unsigned char)eventParm;
    *(int *)((char *)ps + 0xa4) = seq + 1;
}

/* line 819 */
__attribute__((naked))
void BG_PlayerStateToEntityState(playerState_t *ps, entityState_t *s, qboolean snap, int handler)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 819 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* snap */
        "movzbl 0x14(%ebp), %esi\n" /* handler */
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 828 | ps */
        "movl 0xc(%edx), %eax\n"
        "andl $0xc00000, %eax\n"
        "cmpl $1, %eax\n" /* line 829 */
        "sbbl %eax, %eax\n"
        "andl $4, %eax\n"
        "addl $1, %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* s */
        "movl %eax, 4(%ecx)\n"
        "movl $1, 0xc(%ecx)\n" /* line 836 */
        "movl 0xc(%ebp), %ecx\n" /* line 837 | s, to */
        "addl $0x18, %ecx\n" /* to */
        "movl 8(%ebp), %edx\n" /* ps, from */
        "addl $0x14, %edx\n" /* from */
        /* { scope 2 */
        "movl 8(%ebp), %edi\n" /* line 199 | ps */
        "movl 0x14(%edi), %eax\n"
        "movl 0xc(%ebp), %edi\n" /* s */
        "movl %eax, 0x18(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 840 | snap */
        "je .Lf6a520_0006a5a5\n"
        "cvttss2si 0x18(%edi), %eax\n" /* line 841 | i */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x18(%edi)\n" /* i */
        "cvttss2si 0x1c(%edi), %eax\n" /* i */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x1c(%edi)\n" /* i */
        "cvttss2si 0x20(%edi), %eax\n" /* i */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x20(%edi)\n" /* i */
        ".Lf6a520_0006a5a5:\n"
        "movl 0xc(%ebp), %eax\n" /* line 844 | s */
        "movl $1, 0x30(%eax)\n"
        "movl %eax, %ecx\n" /* line 845 | to */
        "addl $0x3c, %ecx\n" /* to */
        "movl 8(%ebp), %edx\n" /* ps, from */
        "addl $0xe8, %edx\n" /* from */
        /* { scope 2 */
        "movl 8(%ebp), %edi\n" /* line 199 | ps */
        "movl 0xe8(%edi), %eax\n"
        "movl 0xc(%ebp), %edi\n" /* s */
        "movl %eax, 0x3c(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 848 | snap */
        "je .Lf6a520_0006a606\n"
        "cvttss2si 0x3c(%edi), %eax\n" /* line 849 | i */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x3c(%edi)\n" /* i */
        "cvttss2si 0x40(%edi), %eax\n" /* i */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x40(%edi)\n" /* i */
        "cvttss2si 0x44(%edi), %eax\n" /* i */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x44(%edi)\n" /* i */
        ".Lf6a520_0006a606:\n"
        "movl 8(%ebp), %eax\n" /* line 853 | ps */
        "cvtsi2ssl 0x9c(%eax), %xmm0\n"
        "movl 0xc(%ebp), %edx\n" /* s */
        "movss %xmm0, 0x6c(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 856 | ps */
        "movl 0x7c(%ecx), %eax\n"
        "movl %eax, 0xcc(%edx)\n"
        "movl 0x84(%ecx), %eax\n" /* line 857 */
        "movl %eax, 0xd0(%edx)\n"
        "movl 0xcc(%ecx), %eax\n" /* line 859 */
        "movl %eax, 0x90(%edx)\n"
        "movl 0xa0(%ecx), %eax\n" /* line 863 */
        "movl %eax, 8(%edx)\n"
        "testl $0x300, 0xa0(%ecx)\n" /* line 867 */
        "je .Lf6a520_0006a65b\n"
        "movl 0x594(%ecx), %eax\n" /* line 868 */
        "movl %eax, 0x74(%edx)\n"
        ".Lf6a520_0006a65b:\n"
        "movl 8(%ebp), %ebx\n" /* line 870 | ps, snap */
        "cmpl $5, 4(%ebx)\n" /* snap */
        "jle .Lf6a520_0006a935\n"
        "movl 0xc(%ebp), %edi\n" /* line 871 | s, i */
        "movl 8(%edi), %eax\n" /* i */
        "orl $0x20000, %eax\n"
        "movl %eax, 8(%edi)\n" /* i */
        ".Lf6a520_0006a676:\n"
        "movl 8(%ebp), %ecx\n" /* line 876 | ps */
        "testb $0x40, 0xc(%ecx)\n"
        "je .Lf6a520_0006a7ff\n"
        "orl $0x40000, %eax\n" /* line 877 */
        "movl 0xc(%ebp), %ebx\n" /* s, snap */
        "movl %eax, 8(%ebx)\n" /* snap */
        "movl 8(%ebp), %edx\n" /* line 882 | ps */
        "movl 0x4c(%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* s */
        "movl %eax, 0xd4(%ecx)\n"
        "movl %edx, (%esp)\n" /* line 885 */
        "calll PM_GetEffectiveStance\n"
        "subl $1, %eax\n"
        "je .Lf6a520_0006a82a\n"
        ".Lf6a520_0006a6ae:\n"
        "xorl %eax, %eax\n" /* line 912 */
        "movl 0xc(%ebp), %edx\n" /* s */
        "movl %eax, 0xe4(%edx)\n"
        "movl %eax, 0xe8(%edx)\n" /* line 913 */
        "movl %eax, 0xec(%edx)\n" /* line 914 */
        "movl 8(%ebp), %ecx\n" /* line 918 | ps */
        "movl 0x5cc(%ecx), %edx\n"
        "movl %ecx, %ebx\n" /* snap */
        "movl 0xa4(%ecx), %ecx\n"
        "cmpl %ecx, %edx\n"
        "js .Lf6a520_0006a8cf\n"
        ".Lf6a520_0006a6de:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 932 | s */
        "movl $0, 0xa0(%ecx)\n"
        "movl 8(%ebp), %ebx\n" /* line 939 | ps, snap */
        "movl 0xc8(%ebx), %edi\n" /* snap, i */
        "cmpl 0xa4(%ebx), %edi\n" /* snap, i */
        "je .Lf6a520_0006a90b\n"
        ".Lf6a520_0006a700:\n"
        "movl %esi, %edx\n" /* handler */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl 0x195edb0, %ecx\n"
        "addl %ecx, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* ps */
        /* { scope 2 */
        ".Lf6a520_0006a719:\n"
        "movl %edi, %ebx\n" /* line 944 | i, snap */
        "andl $3, %ebx\n" /* snap */
        "movl %ebx, -0x1c(%ebp)\n" /* snap */
        "movzbl 0xa8(%eax, %ebx, 4), %esi\n" /* event */
        "movl -0x24(%ebp), %ecx\n" /* line 947 */
        "movl 8(%ecx), %edx\n"
        "testl %edx, %edx\n" /* line 948 */
        "je .Lf6a520_0006a746\n"
        "movl %esi, %ebx\n" /* line 949 | event, snap */
        "movzbl %bl, %eax\n" /* snap */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* s */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *%edx\n"
        ".Lf6a520_0006a746:\n"
        "movl %esi, %eax\n" /* line 955 | event */
        "movzbl %al, %ebx\n" /* snap */
        "movl $0x8c, %edx\n"
        "cmpl %ebx, %edx\n" /* snap */
        "je .Lf6a520_0006a76c\n"
        "xorl %ecx, %ecx\n" /* line 956 */
        "movl $singleClientEvents, %edx\n"
        ".Lf6a520_0006a75b:\n"
        "addl $1, %ecx\n" /* line 953 */
        "movl 4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf6a520_0006a77e\n"
        "addl $4, %edx\n"
        "cmpl %ebx, %eax\n" /* line 955 | snap */
        "jne .Lf6a520_0006a75b\n"
        /* } scope */
        ".Lf6a520_0006a76c:\n"
        "addl $1, %edi\n" /* line 939 | i */
        "movl 8(%ebp), %esi\n" /* ps, handler */
        "cmpl 0xa4(%esi), %edi\n" /* handler, i */
        "je .Lf6a520_0006a7d5\n"
        ".Lf6a520_0006a77a:\n"
        "movl %esi, %eax\n" /* handler */
        "jmp .Lf6a520_0006a719\n"
        /* { scope 2 */
        ".Lf6a520_0006a77e:\n"
        "movl singleClientEvents(, %ecx, 4), %eax\n" /* line 958 */
        "testl %eax, %eax\n"
        "jns .Lf6a520_0006a76c\n"
        "movl 0xc(%ebp), %ecx\n" /* line 961 | s */
        "movl 0xa4(%ecx), %edx\n"
        "movl %edx, %ecx\n"
        "andl $3, %ecx\n"
        "movl %esi, %ebx\n" /* event, snap */
        "movzbl %bl, %eax\n" /* snap */
        "movl 0xc(%ebp), %esi\n" /* s, event */
        "movl %eax, 0xa8(%esi, %ecx, 4)\n" /* event */
        "movl -0x1c(%ebp), %ebx\n" /* line 962 | snap */
        "movl 8(%ebp), %esi\n" /* ps, event */
        "movzbl 0xb8(%esi, %ebx, 4), %eax\n" /* event */
        "movl 0xc(%ebp), %ebx\n" /* s, snap */
        "movl %eax, 0xb8(%ebx, %ecx, 4)\n" /* snap */
        "addl $1, %edx\n" /* line 963 */
        "movl %edx, 0xa4(%ebx)\n" /* snap */
        /* } scope */
        "addl $1, %edi\n" /* line 939 | i */
        "movl 8(%ebp), %esi\n" /* ps, handler */
        "cmpl 0xa4(%esi), %edi\n" /* handler, i */
        "jne .Lf6a520_0006a77a\n"
        ".Lf6a520_0006a7d5:\n"
        "movl %esi, %eax\n" /* handler */
        "movl %edi, 0xc8(%eax)\n" /* line 965 | i */
        "movl 8(%ebp), %edx\n" /* line 967 | ps */
        "movzbl 0xd4(%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* s */
        "movl %eax, 0xc8(%ecx)\n"
        "movzwl 0x60(%edx), %eax\n" /* line 968 */
        "movl %eax, 0x7c(%ecx)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 969 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6a520_0006a7ff:\n"
        "andl $0xfffbffff, %eax\n" /* line 879 */
        "movl 0xc(%ebp), %edi\n" /* s, i */
        "movl %eax, 8(%edi)\n" /* i */
        "movl 8(%ebp), %edx\n" /* line 882 | ps */
        "movl 0x4c(%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* s */
        "movl %eax, 0xd4(%ecx)\n"
        "movl %edx, (%esp)\n" /* line 885 */
        "calll PM_GetEffectiveStance\n"
        "subl $1, %eax\n"
        "jne .Lf6a520_0006a6ae\n"
        /* { scope 2 */
        ".Lf6a520_0006a82a:\n"
        "movl 8(%ebp), %ebx\n" /* line 890 | ps, snap */
        "movl 0xfc(%ebx), %ecx\n" /* snap */
        "testl %ecx, %ecx\n"
        "jne .Lf6a520_0006a971\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movl 8(%ebp), %edx\n" /* ps */
        ".Lf6a520_0006a846:\n"
        "movaps %xmm1, %xmm0\n" /* line 906 */
        "mulss 0x5a8(%edx), %xmm0\n"
        "movl 0xc(%ebp), %ecx\n" /* s */
        "movss %xmm0, 0xe4(%ecx)\n"
        "movl 0x5ac(%edx), %eax\n" /* line 907 */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movss -0x38(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "movl 0xc(%ebp), %ebx\n" /* s, snap */
        "movss %xmm0, 0xe8(%ebx)\n" /* snap */
        "movl 8(%ebp), %edi\n" /* line 908 | ps, i */
        "movl 0x5b0(%edi), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x20(%ebp)\n"
        "movss -0x38(%ebp), %xmm1\n"
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, 0xec(%ebx)\n" /* snap */
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 918 | ps */
        "movl 0x5cc(%ecx), %edx\n"
        "movl %ecx, %ebx\n" /* snap */
        "movl 0xa4(%ecx), %ecx\n"
        "cmpl %ecx, %edx\n"
        "jns .Lf6a520_0006a6de\n"
        ".Lf6a520_0006a8cf:\n"
        "movl %ecx, %eax\n" /* line 922 */
        "subl %edx, %eax\n"
        "cmpl $4, %eax\n"
        "jg .Lf6a520_0006a948\n"
        "andl $3, %edx\n" /* line 927 */
        "movl 8(%ebp), %edi\n" /* ps, i */
        "movzbl 0xb8(%edi, %edx, 4), %eax\n" /* i */
        "movl 0xc(%ebp), %edx\n" /* s */
        "movl %eax, 0xa0(%edx)\n"
        "addl $1, 0x5cc(%edi)\n" /* line 928 | i */
        ".Lf6a520_0006a8f6:\n"
        "movl 8(%ebp), %ebx\n" /* line 939 | ps, snap */
        "movl 0xc8(%ebx), %edi\n" /* snap, i */
        "cmpl 0xa4(%ebx), %edi\n" /* snap, i */
        "jne .Lf6a520_0006a700\n"
        ".Lf6a520_0006a90b:\n"
        "movl %ebx, %eax\n" /* snap */
        "movl %edi, 0xc8(%eax)\n" /* line 965 | i */
        "movl 8(%ebp), %edx\n" /* line 967 | ps */
        "movzbl 0xd4(%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* s */
        "movl %eax, 0xc8(%ecx)\n"
        "movzwl 0x60(%edx), %eax\n" /* line 968 */
        "movl %eax, 0x7c(%ecx)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 969 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6a520_0006a935:\n"
        "movl 0xc(%ebp), %edx\n" /* line 873 | s */
        "movl 8(%edx), %eax\n"
        "andl $0xfffdffff, %eax\n"
        "movl %eax, 8(%edx)\n"
        "jmp .Lf6a520_0006a676\n"
        ".Lf6a520_0006a948:\n"
        "leal -4(%ecx), %edx\n" /* line 923 */
        "movl %edx, 0x5cc(%ebx)\n" /* snap */
        "andl $3, %edx\n" /* line 927 */
        "movl 8(%ebp), %edi\n" /* ps, i */
        "movzbl 0xb8(%edi, %edx, 4), %eax\n" /* i */
        "movl 0xc(%ebp), %edx\n" /* s */
        "movl %eax, 0xa0(%edx)\n"
        "addl $1, 0x5cc(%edi)\n" /* line 928 | i */
        "jmp .Lf6a520_0006a8f6\n"
        /* { scope 2 */
        ".Lf6a520_0006a971:\n"
        "movl 0x104(%ebx), %eax\n" /* line 892 | snap */
        "movl %eax, 8(%esp)\n"
        "movl 0x100(%ebx), %eax\n" /* snap */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* snap */
        "calll PM_GetViewHeightLerpTime\n"
        "movl (%ebx), %edx\n" /* line 893 | snap */
        "subl 0xfc(%ebx), %edx\n" /* snap */
        "cvtsi2ssl %edx, %xmm1\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 894 | 0.0f */
        "jb .Lf6a520_0006a9e4\n"
        ".Lf6a520_0006a9aa:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 896 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf6a520_0006a9b9:\n"
        "movl 8(%ebp), %eax\n" /* line 898 | ps */
        "movl 0x104(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf6a520_0006a9cd\n"
        "movl %eax, %edx\n"
        "jmp .Lf6a520_0006a846\n"
        ".Lf6a520_0006a9cd:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 899 | 1.0f */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "jmp .Lf6a520_0006a846\n"
        ".Lf6a520_0006a9e4:\n"
        "jp .Lf6a520_0006a9aa\n" /* line 894 */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf6a520_0006a9b9\n"
    );
}

/* line 683 */
__attribute__((naked))
void BG_EvaluateTrajectoryDelta(const trajectory_t *tr, int atTime, vec_t *result)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 683 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* tr */
        "movl 0xc(%ebp), %edx\n" /* atTime */
        "movl 0x10(%ebp), %esi\n" /* result */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 691 | tr */
        "cmpl $8, %eax\n"
        "ja .Lf6a9ee_0006aa0d\n"
        "jmpl *0x2f0690(, %eax, 4)\n"
        ".Lf6a9ee_0006aa0d:\n"
        "movl %eax, 0x10(%ebp)\n" /* line 739 | result */
        "movl $0x21bdd8, 0xc(%ebp)\n" /* atTime */
        "movl $1, 8(%ebp)\n" /* tr */
        /* } scope */
        "addl $0x20, %esp\n" /* line 744 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Error\n" /* line 739 */
        "movl 4(%ebx), %ecx\n" /* line 730 | tr */
        "movl %ecx, %eax\n"
        "addl 8(%ebx), %eax\n" /* tr */
        "cmpl %edx, %eax\n"
        "jge .Lf6a9ee_0006ab22\n"
        ".Lf6a9ee_0006aa39:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, (%esi)\n"
        "movl %eax, 4(%esi)\n" /* line 184 */
        "movl %eax, 8(%esi)\n" /* line 185 */
        /* } scope */
        ".Lf6a9ee_0006aa43:\n"
        "addl $0x20, %esp\n" /* line 744 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 707 | tr */
        "addl 8(%ebx), %eax\n" /* tr */
        "cmpl %eax, %edx\n"
        "jg .Lf6a9ee_0006aa39\n"
        "leal 0x18(%ebx), %edx\n" /* line 712 | tr, from */
        /* { scope 2 */
        "movl 0x18(%ebx), %eax\n" /* line 199 */
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        "jmp .Lf6a9ee_0006aa43\n"
        /* } scope */
        "movl 4(%ebx), %ecx\n" /* line 720 | tr */
        "movl %ecx, %eax\n"
        "addl 8(%ebx), %eax\n" /* tr */
        "cmpl %eax, %edx\n"
        "jg .Lf6a9ee_0006aa39\n"
        "subl %ecx, %edx\n" /* line 725 */
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "mulss %xmm0, %xmm0\n" /* line 727 */
        "jmp .Lf6a9ee_0006aaf5\n"
        "subl 4(%ebx), %edx\n" /* line 715 | tr */
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "leal 0x18(%ebx), %edx\n" /* line 716 | tr, from */
        /* { scope 2 */
        "movl 0x18(%ebx), %eax\n" /* line 199 */
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        /* } scope */
        "mulss 0x2ed6b0, %xmm0\n" /* line 717 | -800.0f */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, 8(%esi)\n" /* result */
        "jmp .Lf6a9ee_0006aa43\n"
        "subl 4(%ebx), %edx\n" /* line 702 | tr */
        "cvtsi2ssl %edx, %xmm0\n"
        "cvtsi2ssl 8(%ebx), %xmm1\n" /* tr */
        "divss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "addsd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* line 703 | 0.5f */
        ".Lf6a9ee_0006aaf5:\n"
        "leal 0x18(%ebx), %eax\n" /* line 736 | tr, v */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0x18(%ebx), %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "mulss 8(%eax), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%esi)\n"
        /* } scope */
        /* } scope */
        "addl $0x20, %esp\n" /* line 744 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6a9ee_0006ab22:\n"
        "subl %ecx, %edx\n" /* line 735 */
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "jmp .Lf6a9ee_0006aaf5\n"
    );
}

/* line 529 */
qboolean BG_CanItemBeGrabbed(const entityState_t *ent, const playerState_t *ps, qboolean bTouched)
{
    int index;
    int giType;
    int weapon;
    char *base;

    index = *(int *)((const char *)ent + 0x8c);
    if (index <= 0 || index >= **(int **)0x195edac) {
        Com_Error(ERR_DROP, va((const char *)0x21be08, index, *(int *)((const char *)ent + 4)));
        index = *(int *)((const char *)ent + 0x8c);
    }

    base = *(char **)0x195eda8;

    if (*(int *)((const char *)ent + 0x90) == *(int *)((const char *)ps + 0xcc)) {
        return 0;
    }

    giType = *(int *)(base + index * 44 + 0x1c);

    switch (giType) {
        case 0:
            Com_Error(ERR_DROP, (const char *)0x21be4c);
            return 0;

        case 1: /* IT_WEAPON */
            weapon = *(int *)(base + index * 44 + 0x20);
            if (BG_DoesWeaponNeedSlot(weapon)) {
                if (!(*(int *)((const char *)ps + 0x544 + (weapon >> 5) * 4) & (1 << (weapon & 0x1f)))) {
                    if (bTouched) {
                        return 0;
                    }
                }
            }
            if (BG_GetMaxPickupableAmmo(ps, weapon) <= 0) {
                return 0;
            }
            return 1;

        case 2: /* IT_AMMO */
            weapon = *(int *)(base + index * 44 + 0x20);
            if (!(*(int *)((const char *)ps + 0x544 + (weapon >> 5) * 4) & (1 << (weapon & 0x1f)))) {
                if (!BG_WeaponIsClipOnly(weapon)) {
                    return 0;
                }
            }
            if (BG_GetMaxPickupableAmmo(ps, weapon) <= 0) {
                return 0;
            }
            return 1;

        case 3: /* IT_HEALTH */
            if (*(int *)((const char *)ps + 0x12c) >= *(int *)((const char *)ps + 0x134)) {
                return 0;
            }
            return 1;

        default:
            return 0;
    }
}

/* line 995 */
__attribute__((naked))
qboolean BG_CheckProneValid(int passEntityNum, const vec_t *vPos, const float fSize, const float fHeight, const float fYaw, float *pfTorsoHeight, float *pfTorsoPitch, float *pfWaistPitch, const qboolean bAlreadyProne, const qboolean bOnGround, vec_t *vGroundNormal, int handler, proneCheckType_t proneCheckType, float prone_feet_dist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 995 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x16c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* vPos */
        /* { scope 1: scale */
        "movzbl 0x34(%ebp), %eax\n" /* line 1019 | handler */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x195edb0, %edx\n"
        "movl (%edx, %eax, 4), %edi\n" /* traceFunc */
        "movss 0x10(%ebp), %xmm1\n" /* line 1022 | fSize, y */
        "xorps 0x2f06c0, %xmm1\n" /* y */
        /* { scope 2 */
        "pxor %xmm2, %xmm2\n" /* line 193 */
        /* } scope */
        "movaps %xmm1, %xmm0\n" /* line 240 */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* vMins */
        "leal 4(%ebx), %eax\n" /* line 241 */
        "movl %eax, -0xdc(%ebp)\n"
        "movaps %xmm1, %xmm0\n"
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "leal 8(%ebx), %edx\n" /* line 242 */
        "movl %edx, -0xd8(%ebp)\n"
        "movss 8(%ebx), %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 240 | fSize */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n" /* vMaxs */
        "movss 0x10(%ebp), %xmm0\n" /* line 241 | fSize */
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 242 | fHeight */
        "addss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "cmpl $1, 0x38(%ebp)\n" /* line 1027 | proneCheckType */
        "sbbl %esi, %esi\n" /* iTraceMask */
        "xorw %si, %si\n" /* iTraceMask */
        "addl $0x820011, %esi\n" /* iTraceMask */
        "movl 0x28(%ebp), %eax\n" /* line 1035 | bAlreadyProne */
        "testl %eax, %eax\n"
        "je .Lf6ac9c_0006b150\n"
        ".Lf6ac9c_0006ad4a:\n"
        "movl 0x2c(%ebp), %eax\n" /* line 1051 | bOnGround */
        "testl %eax, %eax\n"
        "je .Lf6ac9c_0006ad6d\n"
        "movl 0x30(%ebp), %ecx\n" /* vGroundNormal */
        "testl %ecx, %ecx\n"
        "je .Lf6ac9c_0006ad6d\n"
        "movss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "movl 0x30(%ebp), %edx\n" /* vGroundNormal */
        "ucomiss 8(%edx), %xmm0\n"
        "ja .Lf6ac9c_0006b143\n"
        ".Lf6ac9c_0006ad6d:\n"
        "movl $0xc0c00000, %eax\n" /* line 191 */
        "movl %eax, -0x48(%ebp)\n" /* vMins */
        "movl %eax, -0x44(%ebp)\n" /* line 192 */
        "movl %eax, -0x40(%ebp)\n" /* line 193 */
        "movl $0x40c00000, -0x54(%ebp)\n" /* line 191 | vMaxs */
        "movl $0x40c00000, -0x50(%ebp)\n" /* line 192 */
        "movl $0x40c00000, -0x4c(%ebp)\n" /* line 193 */
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, -0x3c(%ebp)\n" /* vEnd */
        "movss 0x18(%ebp), %xmm0\n" /* line 192 | fYaw */
        "subss 0x2ed64c, %xmm0\n" /* 180.0f */
        "movss %xmm0, -0x38(%ebp)\n"
        "movl %eax, -0x34(%ebp)\n" /* line 193 */
        "leal -0x24(%ebp), %eax\n" /* line 1060 | vUp */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* vRight */
        "movl %eax, 8(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* vForward */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, (%esp)\n"
        "calll AngleVectors\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 1063 | fHeight */
        "subss 0x2ed5e0, %xmm0\n" /* 6.0f */
        "movss %xmm0, -0xe8(%ebp)\n" /* fTraceHeight */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* vStart */
        "movl -0xdc(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0xd8(%ebp), %edx\n" /* line 201 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "addss -0x28(%ebp), %xmm0\n" /* line 1070 */
        "movss %xmm0, -0x28(%ebp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* line 1071 | prone_feet_dist */
        "subss 0x2ed5e0, %xmm0\n" /* 6.0f */
        "movss %xmm0, -0xd4(%ebp)\n" /* scale */
        /* { scope 2 */
        "mulss -0x6c(%ebp), %xmm0\n" /* line 288 | vForward */
        "addss -0x30(%ebp), %xmm0\n" /* vStart */
        "movss %xmm0, -0x3c(%ebp)\n" /* vEnd */
        "movss -0xd4(%ebp), %xmm0\n" /* line 289 | scale */
        "mulss -0x68(%ebp), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0xd4(%ebp), %xmm0\n" /* line 290 | scale */
        "mulss -0x64(%ebp), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        "movl %esi, 0x18(%esp)\n" /* line 1072 | iTraceMask */
        "movl 8(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* vMins */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vStart */
        "movl %eax, 4(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *%edi\n" /* traceFunc */
        "movss -0x9c(%ebp), %xmm5\n" /* line 1074 | trace */
        "ucomiss 0x2ed5d0, %xmm5\n" /* 1.0f */
        "jb .Lf6ac9c_0006b132\n"
        ".Lf6ac9c_0006ae9d:\n"
        "movss 0x3c(%ebp), %xmm7\n" /* line 1104 | prone_feet_dist */
        "movl $0, -0xe4(%ebp)\n" /* bFirstTraceHit */
        ".Lf6ac9c_0006aeac:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 1203 | vStart */
        "movss -0x3c(%ebp), %xmm6\n" /* vEnd */
        "subss %xmm0, %xmm6\n"
        "mulss %xmm5, %xmm6\n"
        "addss %xmm0, %xmm6\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 1204 */
        "movss -0x38(%ebp), %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "addss %xmm0, %xmm4\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 1205 */
        "movss -0x34(%ebp), %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm0, %xmm3\n"
        "movss -0x6c(%ebp), %xmm2\n" /* line 288 | vForward */
        "mulss 0x2ed6b8, %xmm2\n" /* 48.0f */
        "addss (%ebx), %xmm2\n"
        "movss %xmm2, -0x30(%ebp)\n" /* vStart */
        "movss -0x68(%ebp), %xmm1\n" /* line 289 */
        "mulss 0x2ed6b8, %xmm1\n" /* 48.0f */
        "movl -0xdc(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 290 */
        "mulss 0x2ed6b8, %xmm0\n" /* 48.0f */
        "movl -0xd8(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss -0xe8(%ebp), %xmm0\n" /* line 1125 | fTraceHeight */
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss %xmm2, -0x3c(%ebp)\n" /* line 199 | vEnd */
        "movss %xmm1, -0x38(%ebp)\n" /* line 200 */
        "movss 0x10(%ebp), %xmm1\n" /* line 1127 | fSize */
        "mulss 0x2ed6c0, %xmm1\n" /* 2.5f */
        "addss -0xe8(%ebp), %xmm1\n" /* fTraceHeight */
        "movss 0x2ed5e0, %xmm5\n" /* 6.0f */
        "subss %xmm5, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl %esi, 0x18(%esp)\n" /* line 1128 | iTraceMask */
        "movl 8(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* vMins */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vStart */
        "movl %eax, 4(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "movss %xmm1, -0x108(%ebp)\n"
        "movss %xmm3, -0x118(%ebp)\n"
        "movss %xmm4, -0x128(%ebp)\n"
        "movss %xmm5, -0x138(%ebp)\n"
        "movss %xmm6, -0x148(%ebp)\n"
        "movss %xmm7, -0x158(%ebp)\n"
        "calll *%edi\n" /* traceFunc */
        "movss -0x9c(%ebp), %xmm2\n" /* line 1131 | trace */
        "movss -0x108(%ebp), %xmm1\n"
        "movss -0x118(%ebp), %xmm3\n"
        "movss -0x128(%ebp), %xmm4\n"
        "movss -0x138(%ebp), %xmm5\n"
        "movss -0x148(%ebp), %xmm6\n"
        "movss -0x158(%ebp), %xmm7\n"
        "ucomiss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "jp .Lf6ac9c_0006b02b\n"
        "je .Lf6ac9c_0006b0e7\n"
        ".Lf6ac9c_0006b02b:\n"
        "movss 0x2ed6ac, %xmm0\n" /* line 1134 | 0.699999988079071f */
        "ucomiss -0x90(%ebp), %xmm0\n"
        "ja .Lf6ac9c_0006b143\n"
        "mulss %xmm2, %xmm1\n" /* line 1138 */
        "addss %xmm5, %xmm1\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 1203 | vEnd */
        "subss -0x30(%ebp), %xmm0\n" /* vStart */
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xc8(%ebp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* vStart */
        "addss -0xc8(%ebp), %xmm0\n"
        "movss %xmm0, -0xc8(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 1204 */
        "subss -0x2c(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "addss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 1205 */
        "subss -0x28(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "movss -0x28(%ebp), %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "subss %xmm5, %xmm0\n" /* line 1140 */
        "movss %xmm0, -0xac(%ebp)\n"
        "movl -0xe4(%ebp), %eax\n" /* line 1143 | bFirstTraceHit */
        "testl %eax, %eax\n"
        "je .Lf6ac9c_0006b3d2\n"
        "subss %xmm1, %xmm7\n" /* line 1145 */
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed6c4, %xmm0\n" /* -0.75f */
        "ucomiss %xmm7, %xmm0\n"
        "jbe .Lf6ac9c_0006b247\n"
        ".Lf6ac9c_0006b0e7:\n"
        "movl 0x2c(%ebp), %eax\n" /* line 1253 | bOnGround */
        "testl %eax, %eax\n"
        "jne .Lf6ac9c_0006b143\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1256 | pfTorsoHeight */
        "testl %eax, %eax\n"
        "je .Lf6ac9c_0006b0fe\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1257 | pfTorsoHeight */
        "movl $0, (%eax)\n"
        ".Lf6ac9c_0006b0fe:\n"
        "movl 0x20(%ebp), %edi\n" /* line 1258 | pfTorsoPitch, traceFunc */
        "testl %edi, %edi\n" /* traceFunc */
        "je .Lf6ac9c_0006b10e\n"
        "movl 0x20(%ebp), %edx\n" /* line 1259 | pfTorsoPitch */
        "movl $0, (%edx)\n"
        ".Lf6ac9c_0006b10e:\n"
        "movl 0x24(%ebp), %esi\n" /* line 1260 | pfWaistPitch, iTraceMask */
        "testl %esi, %esi\n" /* iTraceMask */
        "je .Lf6ac9c_0006b820\n"
        "movl 0x24(%ebp), %eax\n" /* line 1261 | pfWaistPitch */
        "movl $0, (%eax)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x16c, %esp\n" /* line 1267 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: scale */
        ".Lf6ac9c_0006b132:\n"
        "jp .Lf6ac9c_0006ae9d\n" /* line 1074 */
        "movl 0x2c(%ebp), %edx\n" /* line 1077 | bOnGround */
        "testl %edx, %edx\n"
        "jne .Lf6ac9c_0006b1e1\n"
        ".Lf6ac9c_0006b143:\n"
        "xorl %eax, %eax\n" /* line 1261 */
        /* } scope */
        ".Lf6ac9c_0006b145:\n"
        "addl $0x16c, %esp\n" /* line 1267 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: scale */
        ".Lf6ac9c_0006b150:\n"
        "movss %xmm1, -0x48(%ebp)\n" /* line 191 | vMins */
        "movss %xmm1, -0x44(%ebp)\n" /* line 192 */
        "movss %xmm2, -0x40(%ebp)\n" /* line 193 */
        "movss 0x10(%ebp), %xmm0\n" /* line 191 | fSize */
        "movss %xmm0, -0x54(%ebp)\n" /* vMaxs */
        "movss %xmm0, -0x50(%ebp)\n" /* line 192 */
        "movss 0x14(%ebp), %xmm2\n" /* line 193 | fHeight */
        "movss %xmm2, -0x4c(%ebp)\n"
        "movl (%ebx), %edx\n" /* line 199 */
        "movl %edx, -0x30(%ebp)\n" /* vStart */
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss 8(%ebx), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x28(%ebp)\n"
        "movl %edx, -0x3c(%ebp)\n" /* line 199 | vEnd */
        "movl %eax, -0x38(%ebp)\n" /* line 200 */
        "addss 0x2ed6b4, %xmm0\n" /* line 1042 | 10.0f */
        "movss %xmm0, -0x34(%ebp)\n"
        "movl %esi, 0x18(%esp)\n" /* line 1043 | iTraceMask */
        "movl 8(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* vEnd */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* vMins */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vStart */
        "movl %eax, 4(%esp)\n"
        "leal -0x9c(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *%edi\n" /* traceFunc */
        "cmpb $0, -0x7a(%ebp)\n" /* line 1046 */
        "je .Lf6ac9c_0006ad4a\n"
        "jmp .Lf6ac9c_0006b143\n"
        ".Lf6ac9c_0006b1e1:\n"
        "movss -0xd4(%ebp), %xmm7\n" /* line 1081 | scale */
        "mulss %xmm5, %xmm7\n"
        "addss 0x2ed5e0, %xmm7\n" /* 6.0f */
        "movss 0x10(%ebp), %xmm0\n" /* line 1084 | fSize */
        "addss 0x2ed62c, %xmm0\n" /* 2.0f */
        "ucomiss %xmm7, %xmm0\n"
        "ja .Lf6ac9c_0006b143\n"
        "movss -0xe8(%ebp), %xmm0\n" /* line 1088 | fTraceHeight */
        "mulss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "movss 0x2ed6b8, %xmm2\n" /* 48.0f */
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0xf4(%ebp)\n"
        "ucomiss %xmm7, %xmm2\n"
        "ja .Lf6ac9c_0006b82a\n"
        ".Lf6ac9c_0006b238:\n"
        "movl $1, -0xe4(%ebp)\n" /* line 1104 | bFirstTraceHit */
        "jmp .Lf6ac9c_0006aeac\n"
        ".Lf6ac9c_0006b247:\n"
        "subss -0xc8(%ebp), %xmm6\n" /* line 248 */
        "subss -0xcc(%ebp), %xmm4\n" /* line 249 */
        "subss -0xac(%ebp), %xmm3\n" /* line 250 */
        "movss -0x6c(%ebp), %xmm0\n" /* line 288 | vForward */
        "mulss %xmm5, %xmm0\n"
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n" /* vDelta */
        "movss -0x68(%ebp), %xmm0\n" /* line 289 */
        "mulss %xmm5, %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 290 */
        "mulss %xmm5, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "addss %xmm5, %xmm0\n" /* line 1153 */
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x60(%ebp), %eax\n" /* line 1154 | vDelta */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0xd4(%ebp), %xmm1\n" /* line 1155 | scale */
        "subss 0x2ed6b8, %xmm1\n" /* 48.0f, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x60(%ebp), %xmm0\n" /* vDelta */
        "addss -0x30(%ebp), %xmm0\n" /* vStart */
        "movss %xmm0, -0x3c(%ebp)\n" /* vEnd */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x5c(%ebp), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "mulss -0x58(%ebp), %xmm1\n" /* line 290 */
        "addss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        /* } scope */
        "movss -0xd4(%ebp), %xmm0\n" /* line 1156 | scale */
        "mulss -0x6c(%ebp), %xmm0\n" /* vForward */
        "addss (%ebx), %xmm0\n" /* vPos */
        "addss -0x3c(%ebp), %xmm0\n" /* vEnd */
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* vEnd */
        "movss -0xd4(%ebp), %xmm2\n" /* line 1157 | scale */
        "mulss -0x68(%ebp), %xmm2\n"
        "movss %xmm2, -0xd4(%ebp)\n" /* scale */
        "movl -0xdc(%ebp), %eax\n"
        "addss (%eax), %xmm2\n"
        "movss %xmm2, -0xd4(%ebp)\n" /* scale */
        "addss -0x38(%ebp), %xmm2\n"
        "mulss %xmm2, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movl %esi, 0x18(%esp)\n" /* line 1158 | iTraceMask */
        "movl 8(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* vMins */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vStart */
        "movl %eax, 4(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *%edi\n" /* traceFunc */
        "movss -0x9c(%ebp), %xmm5\n" /* line 1161 | trace */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss %xmm5, %xmm0\n"
        "ja .Lf6ac9c_0006b8fd\n"
        ".Lf6ac9c_0006b390:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 1203 | vStart */
        "movss -0x3c(%ebp), %xmm6\n" /* vEnd */
        "subss %xmm0, %xmm6\n"
        "mulss %xmm5, %xmm6\n"
        "addss %xmm0, %xmm6\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 1204 */
        "movss -0x38(%ebp), %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "addss %xmm0, %xmm4\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 1205 */
        "movss -0x34(%ebp), %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "mulss %xmm5, %xmm3\n"
        "addss %xmm0, %xmm3\n"
        ".Lf6ac9c_0006b3d2:\n"
        "movss %xmm6, -0x30(%ebp)\n" /* line 199 | vStart */
        "movss %xmm4, -0x2c(%ebp)\n" /* line 200 */
        "movss %xmm3, -0x28(%ebp)\n" /* line 201 */
        "movss %xmm6, -0x3c(%ebp)\n" /* line 199 | vEnd */
        "movss %xmm4, -0x38(%ebp)\n" /* line 200 */
        "movaps %xmm3, %xmm0\n" /* line 1181 */
        "subss -0xac(%ebp), %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "addss 0x10(%ebp), %xmm0\n" /* fSize */
        "subss %xmm0, %xmm3\n"
        "movss %xmm3, -0x34(%ebp)\n"
        "movl %esi, 0x18(%esp)\n" /* line 1182 | iTraceMask */
        "movl 8(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* vMins */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vStart */
        "movl %eax, 4(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *%edi\n" /* traceFunc */
        "movss -0x9c(%ebp), %xmm1\n" /* line 1185 | trace */
        "ucomiss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "jp .Lf6ac9c_0006b451\n"
        "je .Lf6ac9c_0006b0e7\n"
        ".Lf6ac9c_0006b451:\n"
        "movss 0x2ed6ac, %xmm0\n" /* line 1188 | 0.699999988079071f */
        "ucomiss -0x90(%ebp), %xmm0\n"
        "ja .Lf6ac9c_0006b143\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 1203 | vStart */
        "movss -0x3c(%ebp), %xmm2\n" /* vEnd */
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0xd0(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 1204 */
        "movss -0x38(%ebp), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0xb0(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 1205 */
        "movss -0x34(%ebp), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "subss 0x2ed5e0, %xmm0\n" /* line 1193 | 6.0f */
        "movss %xmm0, -0xb4(%ebp)\n"
        "movss (%ebx), %xmm0\n" /* line 199 */
        "movss %xmm0, -0xbc(%ebp)\n"
        "movl -0xdc(%ebp), %eax\n" /* line 200 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movl -0xd8(%ebp), %eax\n" /* line 201 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss -0xc8(%ebp), %xmm0\n" /* line 248 */
        "subss -0xbc(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n" /* vDelta */
        "movss -0xcc(%ebp), %xmm0\n" /* line 249 */
        "subss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n" /* line 250 */
        "subss -0xc4(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x60(%ebp), %eax\n" /* line 1199 | vDelta */
        "movl %eax, (%esp)\n"
        "calll vectopitch\n"
        "fstps -0xf0(%ebp)\n" /* fTorsoPitch */
        "movss -0xd0(%ebp), %xmm0\n" /* line 248 */
        "subss -0xc8(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n" /* vDelta */
        "movss -0xb0(%ebp), %xmm0\n" /* line 249 */
        "subss -0xcc(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0xb4(%ebp), %xmm0\n" /* line 250 */
        "subss -0xac(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x60(%ebp), %edx\n" /* line 1203 | vDelta */
        "movl %edx, (%esp)\n"
        "calll vectopitch\n"
        "movss -0xf0(%ebp), %xmm0\n" /* line 1206 | fTorsoPitch */
        "movss %xmm0, 4(%esp)\n"
        "fstps (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0xec(%ebp)\n" /* fPitchDiff */
        "movss -0xec(%ebp), %xmm2\n" /* line 1207 | fPitchDiff */
        "ucomiss 0x2ed6cc, %xmm2\n" /* -50.0f */
        "jp .Lf6ac9c_0006b5c5\n"
        "jb .Lf6ac9c_0006b8f1\n"
        ".Lf6ac9c_0006b5c5:\n"
        "ucomiss 0x2ed6d0, %xmm2\n" /* 70.0f */
        "ja .Lf6ac9c_0006b8f1\n"
        "movb $1, -0xdd(%ebp)\n" /* success */
        ".Lf6ac9c_0006b5d9:\n"
        "movl $0x80000000, %eax\n" /* line 191 */
        "movl %eax, -0x48(%ebp)\n" /* vMins */
        "movl %eax, -0x44(%ebp)\n" /* line 192 */
        "movl %eax, -0x40(%ebp)\n" /* line 193 */
        "movl $0, -0x54(%ebp)\n" /* line 191 | vMaxs */
        "movl $0, -0x50(%ebp)\n" /* line 192 */
        "movl $0, -0x4c(%ebp)\n" /* line 193 */
        "movss -0xbc(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x30(%ebp)\n" /* vStart */
        "movss -0xc0(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, -0x2c(%ebp)\n"
        "movss 0x2ed6d4, %xmm1\n" /* line 1218 | 5.0f */
        "movss -0xc4(%ebp), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss -0xc8(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x3c(%ebp)\n" /* vEnd */
        "movss -0xcc(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, -0x38(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n" /* line 1220 */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl %esi, 0x18(%esp)\n" /* line 1221 | iTraceMask */
        "movl 8(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* vMins */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vStart */
        "movl %eax, 4(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "movss %xmm1, -0x108(%ebp)\n"
        "calll *%edi\n" /* traceFunc */
        "xorl %ebx, %ebx\n" /* line 1223 | vPos */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss -0x9c(%ebp), %xmm0\n" /* trace */
        "movzbl -0xdd(%ebp), %eax\n" /* success */
        "cmoval %ebx, %eax\n" /* vPos */
        "movb %al, -0xdd(%ebp)\n" /* success */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | vEnd */
        "movl %eax, -0x30(%ebp)\n" /* vStart */
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "movss -0xd0(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x3c(%ebp)\n" /* vEnd */
        "movss -0xb0(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, -0x38(%ebp)\n"
        "movss -0x108(%ebp), %xmm1\n" /* line 1228 */
        "addss -0xb4(%ebp), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movl %esi, 0x18(%esp)\n" /* line 1229 | iTraceMask */
        "movl 8(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* vMins */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vStart */
        "movl %eax, 4(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *%edi\n" /* traceFunc */
        "movss 0x2ed5d0, %xmm0\n" /* line 1231 | 1.0f */
        "ucomiss -0x9c(%ebp), %xmm0\n" /* trace */
        "movzbl -0xdd(%ebp), %eax\n" /* success */
        "cmoval %ebx, %eax\n" /* vPos */
        "movb %al, -0xdd(%ebp)\n" /* success */
        "movl 0x1c(%ebp), %eax\n" /* line 1235 | pfTorsoHeight */
        "testl %eax, %eax\n"
        "je .Lf6ac9c_0006b757\n"
        "movl 0x1c(%ebp), %edx\n" /* line 1236 | pfTorsoHeight */
        "movl $0, (%edx)\n"
        ".Lf6ac9c_0006b757:\n"
        "movl 0x20(%ebp), %eax\n" /* line 1237 | pfTorsoPitch */
        "testl %eax, %eax\n"
        "je .Lf6ac9c_0006b7b5\n"
        "movss -0xbc(%ebp), %xmm0\n" /* line 248 */
        "subss -0xc8(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n" /* vDelta */
        "movss -0xc0(%ebp), %xmm2\n" /* line 249 */
        "subss -0xcc(%ebp), %xmm2\n"
        "movss %xmm2, -0x5c(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 250 */
        "subss -0xac(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x60(%ebp), %eax\n" /* line 1240 | vDelta */
        "movl %eax, (%esp)\n"
        "calll vectopitch\n"
        "fstps (%esp)\n"
        "calll AngleNormalize180\n"
        "movl 0x20(%ebp), %edx\n" /* pfTorsoPitch */
        "fstps (%edx)\n"
        ".Lf6ac9c_0006b7b5:\n"
        "movl 0x24(%ebp), %eax\n" /* line 1242 | pfWaistPitch */
        "testl %eax, %eax\n"
        "je .Lf6ac9c_0006b813\n"
        "movss -0xc8(%ebp), %xmm0\n" /* line 248 */
        "subss -0xd0(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n" /* vDelta */
        "movss -0xcc(%ebp), %xmm2\n" /* line 249 */
        "subss -0xb0(%ebp), %xmm2\n"
        "movss %xmm2, -0x5c(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n" /* line 250 */
        "subss -0xb4(%ebp), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal -0x60(%ebp), %eax\n" /* line 1245 | vDelta */
        "movl %eax, (%esp)\n"
        "calll vectopitch\n"
        "fstps (%esp)\n"
        "calll AngleNormalize180\n"
        "movl 0x24(%ebp), %edx\n" /* pfWaistPitch */
        "fstps (%edx)\n"
        ".Lf6ac9c_0006b813:\n"
        "cmpb $0, -0xdd(%ebp)\n" /* line 1248 | success */
        "je .Lf6ac9c_0006b0e7\n"
        ".Lf6ac9c_0006b820:\n"
        "movl $1, %eax\n" /* line 1261 */
        "jmp .Lf6ac9c_0006b145\n"
        ".Lf6ac9c_0006b82a:\n"
        "movss 0x2ed6bc, %xmm1\n" /* line 1094 | 22.0f */
        "addss -0x34(%ebp), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 248 | vEnd */
        "subss -0x30(%ebp), %xmm0\n" /* vStart */
        "movss %xmm0, -0x60(%ebp)\n" /* vDelta */
        "movss -0x38(%ebp), %xmm0\n" /* line 249 */
        "subss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "subss -0x28(%ebp), %xmm1\n" /* line 250 */
        "movss %xmm1, -0x58(%ebp)\n"
        "leal -0x6c(%ebp), %eax\n" /* line 1096 | vForward */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* vDelta */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstps -0xb8(%ebp)\n"
        "movl %esi, 0x18(%esp)\n" /* line 1097 | iTraceMask */
        "movl 8(%ebp), %edx\n" /* passEntityNum */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* vEnd */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x54(%ebp), %edx\n" /* vMaxs */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* vMins */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* vStart */
        "movl %edx, 4(%esp)\n"
        "leal -0x9c(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll *%edi\n" /* traceFunc */
        "movss -0x9c(%ebp), %xmm5\n" /* line 1098 | trace */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss %xmm5, %xmm0\n"
        "jbe .Lf6ac9c_0006ae9d\n"
        "movss -0xb8(%ebp), %xmm7\n" /* line 1101 */
        "mulss %xmm5, %xmm7\n"
        "addss 0x2ed5e0, %xmm7\n" /* 6.0f */
        "movss -0xf4(%ebp), %xmm0\n" /* line 1104 */
        "ucomiss %xmm7, %xmm0\n"
        "jbe .Lf6ac9c_0006b238\n"
        "jmp .Lf6ac9c_0006b143\n"
        ".Lf6ac9c_0006b8f1:\n"
        "movb $0, -0xdd(%ebp)\n" /* line 1207 | success */
        "jmp .Lf6ac9c_0006b5d9\n"
        ".Lf6ac9c_0006b8fd:\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1203 | vStart */
        "movss -0x3c(%ebp), %xmm0\n" /* vEnd */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* vStart */
        "movss -0x2c(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x38(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 1205 */
        "movss -0x34(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm1, %xmm5\n"
        "addss %xmm5, %xmm0\n"
        "movss 0x2ed6c8, %xmm1\n" /* line 1164 | 18.0f */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "addss %xmm1, %xmm2\n" /* line 1165 */
        "movss %xmm2, -0x34(%ebp)\n"
        "movl %esi, 0x18(%esp)\n" /* line 1166 | iTraceMask */
        "movl 8(%ebp), %eax\n" /* passEntityNum */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* vEnd */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* vMins */
        "movl %edx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* vStart */
        "movl %eax, 4(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* trace */
        "movl %edx, (%esp)\n"
        "calll *%edi\n" /* traceFunc */
        "movss 0x2ed5d0, %xmm0\n" /* line 1168 | 1.0f */
        "ucomiss -0x9c(%ebp), %xmm0\n" /* trace */
        "ja .Lf6ac9c_0006b0e7\n"
        "movss -0x9c(%ebp), %xmm5\n" /* trace */
        "jmp .Lf6ac9c_0006b390\n"
    );
}

/* line 1275 */
qboolean BG_CheckProne(int passEntityNum, const vec_t *vPos, const float fSize, const float fHeight, const float fYaw, float *pfTorsoHeight, float *pfTorsoPitch, float *pfWaistPitch, const qboolean bAlreadyProne, const qboolean bOnGround, vec_t *vGroundNormal, int handler, proneCheckType_t proneCheckType, float prone_feet_dist)
{
    return BG_CheckProneValid(passEntityNum, vPos, fSize, fHeight, fYaw, pfTorsoHeight, pfTorsoPitch, pfWaistPitch, bAlreadyProne, bOnGround, vGroundNormal, (unsigned char)handler, proneCheckType, prone_feet_dist);
}

/* line 597 */
__attribute__((naked))
void BG_EvaluateTrajectory(const trajectory_t *tr, int atTime, vec_t *result)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 597 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* tr */
        "movl 0xc(%ebp), %ebx\n" /* atTime */
        "movl 0x10(%ebp), %edi\n" /* result */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 606 | tr */
        "cmpl $8, %eax\n"
        "ja .Lf6b9ca_0006b9ea\n"
        "jmpl *0x2f06d0(, %eax, 4)\n"
        ".Lf6b9ca_0006b9ea:\n"
        "movl %eax, 0x10(%ebp)\n" /* line 668 | result */
        "movl $0x21be6c, 0xc(%ebp)\n" /* atTime */
        "movl $1, 8(%ebp)\n" /* tr */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 673 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Error\n" /* line 668 */
        "subl 4(%esi), %ebx\n" /* line 614 | tr, atTime */
        "cvtsi2ssl %ebx, %xmm1\n" /* atTime */
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        ".Lf6b9ca_0006ba16:\n"
        "leal 0x18(%esi), %eax\n" /* line 620 | tr, dir */
        "leal 0xc(%esi), %edx\n" /* tr, start */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        ".Lf6b9ca_0006ba1f:\n"
        "mulss 0x18(%esi), %xmm0\n"
        "addss 0xc(%esi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        /* } scope */
        /* } scope */
        ".Lf6b9ca_0006ba4e:\n"
        "addl $0x4c, %esp\n" /* line 673 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl 4(%esi), %edx\n" /* line 653 | tr */
        "movl 8(%esi), %ecx\n" /* tr */
        "leal (%edx, %ecx), %eax\n"
        "cmpl %ebx, %eax\n" /* atTime */
        "cmovgel %ebx, %eax\n" /* atTime */
        "subl %edx, %eax\n" /* line 657 */
        "cvtsi2ssl %eax, %xmm3\n"
        "movss 0x2ed658, %xmm4\n" /* 0.0010000000474974513f */
        "mulss %xmm4, %xmm3\n"
        "leal 0x18(%esi), %eax\n" /* line 659 | tr, v */
        /* { scope 2 */
        "movss 0x18(%esi), %xmm1\n" /* line 324 */
        "movss 0x1c(%esi), %xmm0\n"
        "movss 0x20(%esi), %xmm2\n"
        /* } scope */
        "mulss %xmm1, %xmm1\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl %edi, 4(%esp)\n" /* line 661 | result */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movss %xmm3, -0x48(%ebp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "leal 0xc(%esi), %eax\n" /* line 663 | tr, start */
        /* { scope 2 */
        "movss -0x48(%ebp), %xmm3\n" /* line 289 */
        "movaps %xmm3, %xmm2\n"
        "mulss 0x1c(%esi), %xmm2\n"
        "addss 4(%eax), %xmm2\n"
        "movaps %xmm3, %xmm4\n" /* line 290 */
        "mulss 0x20(%esi), %xmm4\n"
        "addss 8(%eax), %xmm4\n"
        /* } scope */
        "movss -0x38(%ebp), %xmm1\n" /* line 665 | scale */
        "mulss 0x2ed63c, %xmm1\n" /* -0.5f, scale */
        "mulss %xmm3, %xmm1\n" /* scale */
        "mulss %xmm3, %xmm1\n" /* scale */
        /* { scope 2 */
        "mulss 0x18(%esi), %xmm3\n" /* line 288 */
        "addss 0xc(%esi), %xmm3\n"
        "movaps %xmm1, %xmm0\n"
        "mulss (%edi), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, (%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, 4(%edi)\n"
        "mulss 8(%edi), %xmm1\n" /* line 290 */
        "addss %xmm1, %xmm4\n"
        "movss %xmm4, 8(%edi)\n"
        "jmp .Lf6b9ca_0006ba4e\n"
        /* } scope */
        "movl 4(%esi), %edx\n" /* line 640 | tr */
        "movl 8(%esi), %ecx\n" /* tr */
        "leal (%edx, %ecx), %eax\n"
        "cmpl %eax, %ebx\n" /* atTime */
        "cmovgl %eax, %ebx\n" /* atTime */
        "subl %edx, %ebx\n" /* line 644 | atTime */
        "cvtsi2ssl %ebx, %xmm3\n" /* atTime */
        "movss 0x2ed658, %xmm4\n" /* 0.0010000000474974513f */
        "mulss %xmm4, %xmm3\n"
        "leal 0x18(%esi), %eax\n" /* line 646 | tr, v */
        /* { scope 2 */
        "movss 0x18(%esi), %xmm1\n" /* line 324 */
        "movss 4(%eax), %xmm0\n"
        "movss 8(%eax), %xmm2\n"
        /* } scope */
        "mulss %xmm1, %xmm1\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl %edi, 4(%esp)\n" /* line 648 | result */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movss %xmm3, -0x48(%ebp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 650 | scale */
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f, scale */
        "movss -0x48(%ebp), %xmm3\n"
        "mulss %xmm3, %xmm1\n" /* scale */
        "mulss %xmm3, %xmm1\n" /* scale */
        "leal 0xc(%esi), %eax\n" /* tr, start */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss (%edi), %xmm0\n"
        "addss 0xc(%esi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%edi), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "mulss 8(%edi), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "jmp .Lf6b9ca_0006ba4e\n"
        /* } scope */
        "leal 0xc(%esi), %edx\n" /* line 611 | tr, from */
        /* { scope 2 */
        "movl 0xc(%esi), %eax\n" /* line 199 */
        "movl %eax, (%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%edi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%edi)\n"
        "jmp .Lf6b9ca_0006ba4e\n"
        /* } scope */
        "subl 4(%esi), %ebx\n" /* line 635 | tr, atTime */
        "cvtsi2ssl %ebx, %xmm1\n" /* atTime */
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        "leal 0x18(%esi), %eax\n" /* line 636 | tr, dir */
        "leal 0xc(%esi), %edx\n" /* tr, start */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x18(%esi), %xmm0\n"
        "addss 0xc(%esi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        /* } scope */
        "movaps %xmm1, %xmm0\n" /* line 637 */
        "mulss 8(%eax), %xmm0\n"
        "addss 8(%edx), %xmm0\n"
        "movaps %xmm1, %xmm2\n"
        "mulss 0x2ed6d8, %xmm2\n" /* -400.0f */
        "mulss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%edi)\n" /* result */
        "jmp .Lf6b9ca_0006ba4e\n"
        "subl 4(%esi), %ebx\n" /* line 619 | tr, atTime */
        "cvtsi2ssl %ebx, %xmm0\n" /* atTime */
        "cvtsi2ssl 8(%esi), %xmm1\n" /* tr */
        "divss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "addsd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll sin\n"
        "fstpl -0x20(%ebp)\n"
        "cvtsd2ss -0x20(%ebp), %xmm1\n"
        "jmp .Lf6b9ca_0006ba16\n"
        "movl 4(%esi), %edx\n" /* line 623 | tr */
        "movl %edx, %eax\n"
        "addl 8(%esi), %eax\n" /* tr */
        "cmpl %eax, %ebx\n" /* atTime */
        "cmovgl %eax, %ebx\n" /* atTime */
        "subl %edx, %ebx\n" /* line 627 | atTime */
        "cvtsi2ssl %ebx, %xmm1\n" /* atTime */
        "mulss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        "pxor %xmm0, %xmm0\n" /* line 628 */
        "maxss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "leal 0x18(%esi), %eax\n" /* line 632 | tr */
        "leal 0xc(%esi), %edx\n" /* tr */
        "jmp .Lf6b9ca_0006ba1f\n"
    );
}

/* line 505 */
qboolean BG_PlayerTouchesItem(playerState_t *ps, entityState_t *item, int atTime)
{
    vec3_t origin;
    float dx, dy, dz;

    BG_EvaluateTrajectory((const trajectory_t *)((char *)item + 0xc), atTime, origin);

    dx = *(float *)((char *)ps + 0x14) - origin[0];
    if (dx > 36.0f || dx < -36.0f)
        return 0;

    dy = *(float *)((char *)ps + 0x18) - origin[1];
    if (dy > 36.0f || dy < -36.0f)
        return 0;

    dz = *(float *)((char *)ps + 0x1c) - origin[2];
    if (dz > 18.0f || dz < -88.0f)
        return 0;

    return 1;
}
