/* ASM dump from: cg_shellshock.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_shellshock.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern float floorf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

/* extern globals */
extern byte *_cg_p; /* imp_cg - pointer to cg_t* */
#define cg (*(cg_t **)_cg_p)

/* dvar pointers - each is a dvar_t** (pointer to pointer to dvar_s) */
extern byte *_dvar_shellshock_fadein;          /* imp_cg_shock_screenBlendFadeTime */
extern byte *_dvar_shellshock_fadeout;         /* imp_cg_shock_screenBlendTime */
extern byte *_dvar_shellshock_screenblend;     /* imp_cg_shock_viewKickPeriod */
extern byte *_dvar_shellshock_screentype;      /* imp_cg_shock_viewKickRadius */
extern byte *_dvar_shellshock_screenenabled;   /* imp_cg_shock_sound */
extern byte *_dvar_shellshock_soundfadein;     /* imp_cg_shock_soundFadeInTime */
extern byte *_dvar_shellshock_soundfadeout;    /* imp_cg_shock_soundFadeOutTime */
extern byte *_dvar_shellshock_loopfadein;      /* imp_cg_shock_soundLoopFadeTime */
extern byte *_dvar_shellshock_loopfadeout;     /* imp_cg_shock_soundLoopEndDelay */
extern byte *_dvar_shellshock_looptype;        /* imp_cg_shock_soundRoomType */
extern byte *_dvar_shellshock_sounddrylevellooptype; /* imp_cg_shock_soundDryLevel */
extern byte *_dvar_shellshock_soundwetlevellooptype; /* imp_cg_shock_soundWetLevel */
extern byte *_dvar_shellshock_soundloopsilent; /* imp_cg_shock_soundModEndDelay */
extern byte *_dvar_shellshock_viewkickfadein;  /* imp_cg_shock_volume_auto */
extern byte *_dvar_shellshock_viewkickperiod;  /* imp_cg_shock_volume_auto2d */
extern byte *_dvar_shellshock_viewkickradius;  /* imp_cg_shock_volume_menu */
extern byte *_dvar_shellshock_viewkickpitch;   /* imp_cg_shock_volume_weapon */
extern byte *_dvar_shellshock_viewkickyaw;     /* imp_cg_shock_volume_voice */
extern byte *_dvar_shellshock_soundroomtype;   /* imp_cg_shock_volume_item */
extern byte *_dvar_shellshock_sounddrylevel;   /* imp_cg_shock_volume_body */
extern byte *_dvar_shellshock_soundwetlevel;   /* imp_cg_shock_volume_local */
extern byte *_dvar_shellshock_soundmodenddelay;/* imp_cg_shock_volume_music */
extern byte *_dvar_shellshock_soundendduration;/* imp_cg_shock_volume_announcer */
extern byte *_dvar_shellshock_soundfade;       /* imp_cg_shock_volume_shellshock */
extern byte *_dvar_shellshock_mouseenable;     /* imp_cg_shock_mouse */
extern byte *_dvar_shellshock_mousefadein;     /* imp_cg_shock_mouse_fadeTime */
extern byte *_dvar_shellshock_mouseturnrate;   /* imp_cg_shock_mouse_maxpitchspeed */
extern byte *_dvar_shellshock_mousereducemax;  /* imp_cg_shock_mouse_maxyawspeed */
extern byte *_dvar_shellshock_mousesensitivity;/* imp_cg_shock_mouse_sensitivityscale */

extern int _snd_local_listener; /* imp_vec3_origin */

/* extern function declarations */
extern float Vec3Normalize(vec3_t v);
extern void Vec3Cross(const vec3_t v1, const vec3_t v2, vec3_t out);
extern void AxisCopy(const float (*src)[3], float (*dst)[3]);
extern void MatrixMultiply(const vec3_t axis, const float (*in1)[3], float (*out)[3]);
extern qboolean Com_SaveDvarsToBuffer(const char **dvar_names, int count, char *buf, int bufsize);
extern qboolean Com_LoadDvarsFromBuffer(const char **dvar_names, int count, const char *buf, const char *path);
extern const char *va(const char *format, ...);
extern int FS_FOpenFileByMode(const char *name, int *fh, int mode);
extern void FS_Write(const void *buf, int len, int fh);
extern void FS_Read(void *buf, int len, int fh);
extern void FS_FCloseFile(int fh);
extern void *Z_MallocInternal(int size);
extern void Z_FreeInternal(void *ptr);
extern void Com_Printf(const char *fmt, ...);
extern void CL_SaveScreen(void);
extern void CL_BlendSavedScreen(int blend);
extern const char *Dvar_EnumToString(dvar_t *dvar);
extern void SND_SetChannelVolumes(int type, float *volumes, int flags);
extern void SND_SetEnvironmentEffects(int type, const char *name, float drylevel, float wetlevel, int flags);
extern void SND_DeactivateChannelVolumes(int type, int flags);
extern void SND_DeactivateEnvironmentEffects(int type, int flags);
extern void *CL_PickSoundAlias(const char *name);
extern void SND_PlayBlendedSoundAliases(void *alias0, void *alias1, float fade, int channel, int entity, int flags, int loop);
extern void SND_PlaySoundAlias(void *alias, int channel, int entity, int duration, int loop);
extern void CL_CapTurnRate(int min_rate, int max_rate);
extern void CL_SetUserCmdInShellshock(int inShellshock);

/* Helper: read dvar float current value: *(float *)(&(*(dvar_t**)addr)->current) */
static inline float dvar_get_float(byte *dvar_pp) {
    dvar_t *dvar = *(dvar_t **)dvar_pp;
    return dvar->current.value;
}

/* Helper: read dvar int current value */
static inline int dvar_get_int(byte *dvar_pp) {
    dvar_t *dvar = *(dvar_t **)dvar_pp;
    return dvar->current.integer;
}

/* Helper: read dvar bool current value */
static inline int dvar_get_bool(byte *dvar_pp) {
    dvar_t *dvar = *(dvar_t **)dvar_pp;
    return (int)dvar->current.enabled;
}

/* Helper: get dvar_t* from pointer-to-pointer */
static inline dvar_t *dvar_get_ptr(byte *dvar_pp) {
    return *(dvar_t **)dvar_pp;
}

/* Helper: convert seconds float to milliseconds int with rounding */
static inline int float_seconds_to_ms(float val) {
    return (int)floorf(val * 1000.0f + 0.5f);
}

__attribute__((used, packed, aligned(4)))
const char * cg_shock_dvar_names[] = {
    "cg_shock_screenBlendTime",
    "cg_shock_screenBlendFadeTime",
    "cg_shock_viewKickPeriod",
    "cg_shock_viewKickRadius",
    "cg_shock_sound",
    "cg_shock_soundFadeInTime",
    "cg_shock_soundFadeOutTime",
    "cg_shock_soundLoopFadeTime",
    "cg_shock_soundLoopEndDelay",
    "cg_shock_soundRoomType",
    "cg_shock_soundDryLevel",
    "cg_shock_soundWetLevel",
    "cg_shock_soundModEndDelay",
    "cg_shock_volume_auto",
    "cg_shock_volume_auto2d",
    "cg_shock_volume_menu",
    "cg_shock_volume_weapon",
    "cg_shock_volume_voice",
    "cg_shock_volume_item",
    "cg_shock_volume_body",
    "cg_shock_volume_local",
    "cg_shock_volume_music",
    "cg_shock_volume_announcer",
    "cg_shock_volume_shellshock",
    "cg_shock_mouse",
    "cg_shock_mouse_maxpitchspeed",
    "cg_shock_mouse_maxyawspeed",
    "cg_shock_mouse_sensitivityscale",
    "cg_shock_mouse_fadeTime",
    NULL,
    NULL,
    NULL,
}; /* 0x314a80 */

static vec2_t cg_perturbations[131]; /* cg_perturbations */

void CG_PerturbCamera(void);
qboolean CG_SaveShellShockDvars(const char *name);
qboolean CG_LoadShellShockDvars(const char *name);
qboolean CG_DrawShellShockSavedScreenBlend(const shellshock_parms_t *parms, int start, int duration);
void CG_SetShellShockParmsFromDvars(shellshock_parms_t *parms);
void CG_UpdateShellShock(const shellshock_parms_t *parms, int start, int duration);

/* line 256 */
void CG_PerturbCamera(void)
{
    cg_t *cgp = cg;
    vec3_t rot;
    vec3_t up;
    vec3_t cross;
    float (*refdefAxis)[3];
    float axis[3][3];

    /* Check if perturbation angles are non-zero */
    if (cgp->shellshock.viewDelta[0] == 0.0f && cgp->shellshock.viewDelta[1] == 0.0f) {
        return;
    }

    /* line 264-269: build rotation axis */
    rot[0] = 1.0f;
    rot[1] = cgp->shellshock.viewDelta[0];
    rot[2] = cgp->shellshock.viewDelta[1];

    up[0] = 0.0f;
    up[1] = 0.0f;
    up[2] = 1.0f;

    /* line 271-274: orthonormalize */
    Vec3Normalize(rot);
    Vec3Cross(up, rot, cross);
    Vec3Normalize(cross);
    Vec3Cross(rot, cross, up);

    /* line 276-277: apply rotation to refdef axis */
    refdefAxis = (float (*)[3])cgp->refdef.viewaxis;
    AxisCopy(refdefAxis, axis);
    MatrixMultiply(rot, axis, refdefAxis);
}

/* line 323 */
qboolean CG_SaveShellShockDvars(const char *name)
{
    char filebuf[0x10000];
    int fh;
    const char *path;

    /* line 329: save dvars to buffer */
    if (!Com_SaveDvarsToBuffer(cg_shock_dvar_names, 0x1d, filebuf, 0x10000)) {
        return 0; /* line 338 */
    }

    /* line 332: build path */
    path = va("shock/%s.shock", name);

    /* line 333: open file for writing (mode 1 = write) */
    if (FS_FOpenFileByMode(path, &fh, 1) < 0) {
        return 0; /* line 338 */
    }

    /* line 336: write buffer, then close */
    FS_Write(filebuf, (int)strlen(filebuf), fh);

    /* line 337 */
    FS_FCloseFile(fh);
    return 1;
}

/* line 347 */
qboolean CG_LoadShellShockDvars(const char *name)
{
    const char *fullpath;
    int fh;
    int filesize;
    char *buf;
    qboolean result;

    /* line 362 */
    fullpath = va("shock/%s.shock", name);

    /* line 380: open file for reading (mode 0 = read) */
    filesize = FS_FOpenFileByMode(fullpath, &fh, 0);
    if (filesize < 0) {
        /* line 383 */
        Com_Printf("^1couldn't open '%s'.\n", fullpath);

        /* line 384: try default */
        filesize = FS_FOpenFileByMode("shock/default.shock", &fh, 0);
        if (filesize < 0) {
            /* line 387 */
            Com_Printf("^1couldn't open 'shock/default.shock'.\n");
            filesize = 0;
            return filesize;
        }
    }

    /* line 392 */
    buf = (char *)Z_MallocInternal(filesize + 1);

    /* line 393 */
    FS_Read(buf, filesize, fh);

    /* line 394 */
    buf[filesize] = '\0';

    /* line 395 */
    FS_FCloseFile(fh);

    /* line 398 */
    result = Com_LoadDvarsFromBuffer(cg_shock_dvar_names, 0x1d, buf, fullpath);

    /* line 401 */
    Z_FreeInternal(buf);

    return result;
}

/* line 286 */
qboolean CG_DrawShellShockSavedScreenBlend(const shellshock_parms_t *parms, int start, int duration)
{
    cg_t *cgp;
    int timeLeft;
    int blend;
    int fadeDuration;
    int fadeIn;

    /* line 291 */
    if (start == 0 || duration <= 0) {
        /* line 293 */
        cgp = cg;
        cgp->shellshock.hasSavedScreen = 0;
        return 0;
    }

    /* line 297 */
    cgp = cg;
    timeLeft = start + duration - cgp->time;

    /* line 298 */
    if (timeLeft <= 0) {
        /* line 300 */
        cgp->shellshock.hasSavedScreen = 0;
        return 0;
    }

    /* line 304-305 */
    fadeIn = parms->screenBlend.effectTime;
    fadeDuration = parms->screenBlend.fadeTime;

    blend = fadeIn;
    if (timeLeft < fadeDuration) {
        /* line 428: scale blend based on time remaining */
        blend = (int)floorf((float)fadeIn * (float)timeLeft / (float)fadeDuration + 0.5f);
    }

    /* line 310-313 */
    if (cgp->shellshock.hasSavedScreen != 0) {
        /* line 311 */
        CL_BlendSavedScreen(blend);
    }

    /* line 312 */
    CL_SaveScreen();

    /* line 313 */
    cgp->shellshock.hasSavedScreen = 1;
    return 1;
}

/* line 413 */
void CG_SetShellShockParmsFromDvars(shellshock_parms_t *parms)
{
    float val;
    float epsilon;

    /* line 428: fadein (ms from seconds) */
    parms->screenBlend.fadeTime = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_fadein));

    /* fadeout */
    parms->screenBlend.effectTime = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_fadeout));

    /* line 422: view = 3000 */
    parms->view.fadeTime = 3000;

    /* line 423: screenblend ratio */
    val = dvar_get_float(_dvar_shellshock_screenblend);
    epsilon = 0.001f;
    if (epsilon - val == 0.0f) {
        parms->view.kickRate = 1.0f;
    } else {
        parms->view.kickRate = epsilon / val;
    }

    /* line 424: screentype */
    *(int *)&parms->view.kickRadius = dvar_get_int(_dvar_shellshock_screentype);

    /* line 426: screenenabled (bool) */
    parms->sound.use = dvar_get_bool(_dvar_shellshock_screenenabled);

    /* line 428: soundfadein (ms) */
    parms->sound.fadeInTime = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_soundfadein));

    /* soundfadeout (ms) */
    parms->sound.fadeOutTime = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_soundfadeout));

    /* loopfadein (ms) */
    parms->sound.loopFadeTime = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_loopfadein));

    /* loopfadeout (ms) */
    parms->sound.loopEndDelay = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_loopfadeout));

    /* line 431: looptype - enum to string */
    strncpy(parms->sound.roomtype, Dvar_EnumToString(dvar_get_ptr(_dvar_shellshock_looptype)), 0xf);
    parms->sound.roomtype[15] = 0; /* null terminator */

    /* line 433: sounddrylevellooptype */
    *(int *)&parms->sound.drylevel = dvar_get_int(_dvar_shellshock_sounddrylevellooptype);

    /* line 434: soundwetlevellooptype */
    *(int *)&parms->sound.wetlevel = dvar_get_int(_dvar_shellshock_soundwetlevellooptype);

    /* soundloopsilent (ms) */
    parms->sound.modEndDelay = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_soundloopsilent));

    /* line 436: viewkickfadein - max(val, 1.0f) */
    val = dvar_get_float(_dvar_shellshock_viewkickfadein);
    parms->sound.channelvolume[0] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 437: viewkickperiod */
    val = dvar_get_float(_dvar_shellshock_viewkickperiod);
    parms->sound.channelvolume[1] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 438: viewkickradius */
    val = dvar_get_float(_dvar_shellshock_viewkickradius);
    parms->sound.channelvolume[2] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 439: viewkickpitch */
    val = dvar_get_float(_dvar_shellshock_viewkickpitch);
    parms->sound.channelvolume[5] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 440: viewkickyaw */
    val = dvar_get_float(_dvar_shellshock_viewkickyaw);
    parms->sound.channelvolume[6] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 441: soundroomtype */
    val = dvar_get_float(_dvar_shellshock_soundroomtype);
    parms->sound.channelvolume[4] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 442: sounddrylevel */
    val = dvar_get_float(_dvar_shellshock_sounddrylevel);
    parms->sound.channelvolume[3] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 443: soundwetlevel */
    val = dvar_get_float(_dvar_shellshock_soundwetlevel);
    parms->sound.channelvolume[7] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 444: soundmodenddelay */
    val = dvar_get_float(_dvar_shellshock_soundmodenddelay);
    parms->sound.channelvolume[8] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 445: soundendduration */
    val = dvar_get_float(_dvar_shellshock_soundendduration);
    parms->sound.channelvolume[9] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 446: soundfade */
    val = dvar_get_float(_dvar_shellshock_soundfade);
    parms->sound.channelvolume[10] = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 465: mouseenable (bool) */
    parms->mouse.use = dvar_get_bool(_dvar_shellshock_mouseenable);

    /* line 428: mousefadein (ms) */
    parms->mouse.fadeTime = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_mousefadein));

    /* line 468: mouseturnrate */
    *(int *)&parms->mouse.maxPitchSpeed = dvar_get_int(_dvar_shellshock_mouseturnrate);

    /* line 469: mousereducemax */
    *(int *)&parms->mouse.maxYawSpeed = dvar_get_int(_dvar_shellshock_mousereducemax);

    /* line 470: mousesensitivity */
    *(int *)&parms->mouse.sensitivity = dvar_get_int(_dvar_shellshock_mousesensitivity);
}

/* Deactivate sound and reset shellshock state */
static void CG_DeactivateShellShockSound(cg_t *cgp)
{
    SND_DeactivateChannelVolumes(3, 0);
    SND_DeactivateEnvironmentEffects(2, 0);

    /* line 488: check and stop loop sound */
    if (cgp->shellshock.loopEndTime != 0) {
        cgp->shellshock.loopEndTime = 0;
        /* line 491 */
        {
            void *alias = CL_PickSoundAlias("shellshock_loop_end");
            SND_PlaySoundAlias(alias, 0x3ff, _snd_local_listener, 0, 1);
        }
    }
}

/* Reset motion/view state on cgp */
static void CG_ResetShellShockMotion(cg_t *cgp)
{
    /* line 503: sensitivity = 1.0f */
    cgp->shellshock.sensitivity = 1.0f;

    /* line 504: cap turn rate to 0,0 */
    CL_CapTurnRate(0, 0);
}

/* line 706 */
void CG_UpdateShellShock(const shellshock_parms_t *parms, int start, int duration)
{
    cg_t *cgp;
    int time;
    int timeSinceStart;
    float fade;
    float channelvolume[11];
    int i;
    int loopTimeLeft;
    int loopFadeOut;

    /* line 710 */
    cgp = cg;
    time = cgp->time - start;

    /* line 711 */
    if (start == 0 || time < 0) {
        /* Deactivate everything */
        CG_DeactivateShellShockSound(cgp);

        /* line 503 */
        CG_ResetShellShockMotion(cgp);

        /* line 515-516 */
        cgp->shellshock.viewDelta[0] = 0.0f;
        cgp->shellshock.viewDelta[1] = 0.0f;

        /* line 530 */
        CL_SetUserCmdInShellshock(0);
        return;
    }

    /* Active shellshock */
    /* line 551: check if sound is enabled in parms */
    if (parms->sound.use == 0) {
        /* Sound not enabled */
        SND_DeactivateChannelVolumes(3, 0);
        SND_DeactivateEnvironmentEffects(2, 0);

        /* line 488 */
        if (cgp->shellshock.loopEndTime != 0) {
            cgp->shellshock.loopEndTime = 0;
            {
                void *alias = CL_PickSoundAlias("shellshock_loop_end");
                SND_PlaySoundAlias(alias, 0x3ff, _snd_local_listener, 0, 1);
            }
        }
        goto check_mouse;
    }

    {
        /* line 557 */
        int soundFadeOut = parms->sound.fadeOutTime;
        int soundFadeIn = parms->sound.fadeInTime;
        int totalWithFade = duration + parms->sound.modEndDelay + soundFadeOut;
        int soundTimeLeft = totalWithFade - time;

        /* line 558 */
        if (soundFadeOut > soundTimeLeft) {
            /* In fadeout phase */
            /* line 560 */
            if (time < soundFadeIn) {
                /* line 561: still fading in */
                fade = (float)time / (float)soundFadeIn;
            } else {
                fade = 1.0f;
            }
        } else {
            /* line 559 */
            fade = (float)soundTimeLeft / (float)soundFadeOut;
        }

        /* line 564 */
        if (fade < 0.0f) {
            fade = 0.0f;
        }

        /* line 567 */
        if (fade == 0.0f) {
            /* line 577 */
            SND_DeactivateChannelVolumes(3, 0);
            SND_DeactivateEnvironmentEffects(2, 0);
        } else {
            /* line 570: compute channel volumes */
            for (i = 0; i < 11; i++) {
                channelvolume[i] = (parms->sound.channelvolume[i] - 1.0f) * fade + 1.0f;
            }

            /* line 571 */
            SND_SetChannelVolumes(3, channelvolume, 0);

            /* line 573 */
            SND_SetEnvironmentEffects(2, parms->sound.roomtype,
                fade * parms->sound.drylevel,
                fade * parms->sound.wetlevel, 0);
        }
    }

    {
        /* line 583: loop sound */
        int loopFadeOutVal = parms->sound.loopEndDelay;
        loopTimeLeft = duration + loopFadeOutVal + parms->sound.loopFadeTime - time;

        /* line 584 */
        if (loopTimeLeft > 0) {
            /* line 586-587 */
            void *pAlias0 = CL_PickSoundAlias("shellshock_loop");
            void *pAlias1 = CL_PickSoundAlias("shellshock_loop2");
            int loopFadeIn = parms->sound.loopFadeTime;

            /* line 589 */
            if (loopFadeIn == 0) {
                /* fade stays as previous sound fade value */
            } else {
                /* line 591: compute loop fade */
                fade = 1.0f - (float)loopTimeLeft / (float)loopFadeIn;

                /* line 592: clamp to 0 */
                if (fade < 0.0f) fade = 0.0f;
            }

            /* line 595: play blended loop */
            SND_PlayBlendedSoundAliases(pAlias0, pAlias1, fade, 0x3ff, _snd_local_listener, 0, 1);

            loopFadeOutVal = parms->sound.loopEndDelay;
        }

        /* line 598: check loop end */
        cgp = cg;
        {
            int cgTime = cgp->time;
            int loopEndTime = cgTime - time + duration + loopFadeOutVal;

            /* line 599 */
            if (cgTime < loopEndTime) {
                /* line 601 */
                if (cgp->shellshock.loopEndTime != 0) {
                    /* line 603 */
                    cgp->shellshock.loopEndTime = 0;
                    /* line 604 */
                    {
                        void *alias = CL_PickSoundAlias("shellshock_loop_end");
                        SND_PlaySoundAlias(alias, 0x3ff, _snd_local_listener, 0, 1);
                    }
                }
            } else {
                /* line 607 */
                if (cgp->shellshock.loopEndTime != loopEndTime) {
                    /* line 609 */
                    cgp->shellshock.loopEndTime = loopEndTime;

                    /* line 610 */
                    {
                        int delayMs = cgTime - loopEndTime;
                        void *alias = CL_PickSoundAlias("shellshock_end");
                        SND_PlaySoundAlias(alias, 0x3ff, _snd_local_listener, delayMs, 1);
                    }
                }
            }
        }
    }

check_mouse:
    {
        /* line 628: check mouse enabled */
        int mouseEnabled = parms->mouse.use;
        int timeSinceStart2 = duration - time;

        if (mouseEnabled == 0) {
            /* line 503 */
            cgp = cg;
            CG_ResetShellShockMotion(cgp);

            timeSinceStart2 = duration - time;
            goto check_viewkick;
        }

        {
            /* line 634 */
            int mouseFadeIn = parms->mouse.fadeTime;
            if (timeSinceStart2 >= mouseFadeIn) {
                /* Fully faded in */
                /* line 650 */
                cgp = cg;
                cgp->shellshock.sensitivity = parms->mouse.sensitivity;

                /* line 651 */
                CL_CapTurnRate(*(int *)&parms->mouse.maxPitchSpeed, *(int *)&parms->mouse.maxYawSpeed);
            } else if (timeSinceStart2 <= 0) {
                /* line 503: not started yet */
                cgp = cg;
                CG_ResetShellShockMotion(cgp);
            } else {
                /* line 640: fading in */
                float t = (float)timeSinceStart2 / (float)mouseFadeIn;

                /* line 648 */
                if (t == 1.0f) {
                    /* Fully faded in */
                    /* line 650 */
                    cgp = cg;
                    cgp->shellshock.sensitivity = parms->mouse.sensitivity;
                    CL_CapTurnRate(*(int *)&parms->mouse.maxPitchSpeed, *(int *)&parms->mouse.maxYawSpeed);
                } else {
                    /* line 655-656: interpolate */
                    cgp = cg;
                    float sensitivity = parms->mouse.sensitivity;
                    cgp->shellshock.sensitivity = (sensitivity - 1.0f) * t + 1.0f;

                    float minRate = parms->mouse.maxPitchSpeed / t;
                    float maxRate = parms->mouse.maxYawSpeed / t;
                    CL_CapTurnRate(*(int *)&minRate, *(int *)&maxRate);
                }
            }
        }
    }

check_viewkick:
    /* line 679: view kick */
    timeSinceStart = duration - time;
    if (timeSinceStart <= 0) {
        /* line 515 */
        cgp = cg;
        cgp->shellshock.viewDelta[0] = 0.0f;
        cgp->shellshock.viewDelta[1] = 0.0f;
    } else {
        /* line 686 */
        int viewKickTime = parms->view.fadeTime;
        float t;
        float amplitude;

        if (timeSinceStart >= viewKickTime) {
            t = 1.0f;
            amplitude = (-2.0f + 3.0f) * t * t; /* = t*t = 1.0 */
        } else {
            /* line 687 */
            t = (float)timeSinceStart / (float)viewKickTime;
            amplitude = (-2.0f * t + 3.0f) * t * t;
        }

        /* line 689 */
        amplitude = amplitude * parms->view.kickRadius;

        /* line 691 */
        {
            float phase = (float)time * parms->view.kickRate;
            int phaseFloor = (int)floorf(phase);
            float frac = phase - (float)phaseFloor;

            /* line 695: compute index into perturbation table */
            int idx = (phaseFloor + duration * 60) & 0x7f;
            int byteOff = idx * 8; /* sizeof(vec2_t) = 8 */
            byte *base = (byte *)cg_perturbations + byteOff;

            /* Catmull-Rom spline interpolation for X */
            float x0 = *(float *)(base + 0);
            float x1 = *(float *)(base + 8);
            float x2 = *(float *)(base + 16);
            float x3 = *(float *)(base + 24);

            /* Cubic interpolation (matching asm exactly) */
            float coeff_a = x3 - x2 + x1 - x0;
            float c_x = x2 - x0;
            float b_x = x0 - x1 - coeff_a;
            b_x = (coeff_a * frac + b_x) * frac;
            c_x = (c_x + b_x) * frac;
            float resultX = x1 + c_x;

            cgp = cg;
            cgp->shellshock.viewDelta[0] = amplitude * resultX;

            /* Same interpolation for Y component */
            float y0 = *(float *)(base + 4);
            float y1 = *(float *)(base + 12);
            float y2 = *(float *)(base + 20);
            float y3 = *(float *)(base + 28);

            float coeff_a_y = y3 - y2 + y1 - y0;
            float yxmm2 = y2 - y0;
            float yxmm1 = y0 - y1 - coeff_a_y;
            float ytmp = coeff_a_y * frac;
            yxmm1 += ytmp;
            yxmm1 *= frac;
            yxmm2 += yxmm1;
            yxmm2 *= frac;
            float resultY = y1 + yxmm2;

            cgp->shellshock.viewDelta[1] = amplitude * resultY;
        }
    }

    /* line 720 */
    CL_SetUserCmdInShellshock(time < duration ? 1 : 0);
}
