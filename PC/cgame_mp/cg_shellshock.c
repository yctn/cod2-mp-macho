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
#define cg (*(byte **)_cg_p)

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

extern const char * cg_shock_dvar_names[29]; /* cg_shock_dvar_names */
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
    byte *cgp = cg;
    vec3_t rot;
    vec3_t up;
    vec3_t cross;
    float (*refdefAxis)[3];
    float axis[3][3];

    /* Check if perturbation angles are non-zero */
    if (*(float *)(cgp + 0x2ccec) == 0.0f && *(float *)(cgp + 0x2ccf0) == 0.0f) {
        return;
    }

    /* line 264-269: build rotation axis */
    rot[0] = 1.0f;
    rot[1] = *(float *)(cgp + 0x2ccec);
    rot[2] = *(float *)(cgp + 0x2ccf0);

    up[0] = 0.0f;
    up[1] = 0.0f;
    up[2] = 1.0f;

    /* line 271-274: orthonormalize */
    Vec3Normalize(rot);
    Vec3Cross(up, rot, cross);
    Vec3Normalize(cross);
    Vec3Cross(rot, cross, up);

    /* line 276-277: apply rotation to refdef axis */
    refdefAxis = (float (*)[3])(cgp + 0x28594);
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
    byte *cgp;
    int timeLeft;
    int blend;
    int fadeDuration;
    int fadeIn;

    /* line 291 */
    if (start == 0 || duration <= 0) {
        /* line 293 */
        cgp = cg;
        *(int *)(cgp + 0x2ccf4) = 0;
        return 0;
    }

    /* line 297 */
    cgp = cg;
    timeLeft = start + duration - *(int *)(cgp + 0x25bb0);

    /* line 298 */
    if (timeLeft <= 0) {
        /* line 300 */
        *(int *)(cgp + 0x2ccf4) = 0;
        return 0;
    }

    /* line 304-305 */
    fadeIn = *(int *)((byte *)parms + 0x10);
    fadeDuration = *(int *)((byte *)parms + 0x0c);

    blend = fadeIn;
    if (timeLeft < fadeDuration) {
        /* line 428: scale blend based on time remaining */
        blend = (int)floorf((float)fadeIn * (float)timeLeft / (float)fadeDuration + 0.5f);
    }

    /* line 310-313 */
    if (*(int *)(cgp + 0x2ccf4) != 0) {
        /* line 311 */
        CL_BlendSavedScreen(blend);
    }

    /* line 312 */
    CL_SaveScreen();

    /* line 313 */
    *(int *)(cgp + 0x2ccf4) = 1;
    return 1;
}

/* line 413 */
void CG_SetShellShockParmsFromDvars(shellshock_parms_t *parms)
{
    byte *p = (byte *)parms;
    float val;
    float epsilon;

    /* line 428: fadein (ms from seconds) */
    *(int *)(p + 0x0c) = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_fadein));

    /* fadeout */
    *(int *)(p + 0x10) = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_fadeout));

    /* line 422: view = 3000 */
    *(int *)(p + 0x00) = 3000;

    /* line 423: screenblend ratio */
    val = dvar_get_float(_dvar_shellshock_screenblend);
    epsilon = 0.001f;
    if (epsilon - val == 0.0f) {
        *(float *)(p + 0x04) = 1.0f;
    } else {
        *(float *)(p + 0x04) = epsilon / val;
    }

    /* line 424: screentype */
    *(int *)(p + 0x08) = dvar_get_int(_dvar_shellshock_screentype);

    /* line 426: screenenabled (bool) */
    *(int *)(p + 0x14) = dvar_get_bool(_dvar_shellshock_screenenabled);

    /* line 428: soundfadein (ms) */
    *(int *)(p + 0x18) = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_soundfadein));

    /* soundfadeout (ms) */
    *(int *)(p + 0x1c) = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_soundfadeout));

    /* loopfadein (ms) */
    *(int *)(p + 0x68) = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_loopfadein));

    /* loopfadeout (ms) */
    *(int *)(p + 0x6c) = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_loopfadeout));

    /* line 431: looptype - enum to string */
    strncpy((char *)(p + 0x28), Dvar_EnumToString(dvar_get_ptr(_dvar_shellshock_looptype)), 0xf);
    *(p + 0x37) = 0; /* null terminator */

    /* line 433: sounddrylevellooptype */
    *(int *)(p + 0x20) = dvar_get_int(_dvar_shellshock_sounddrylevellooptype);

    /* line 434: soundwetlevellooptype */
    *(int *)(p + 0x24) = dvar_get_int(_dvar_shellshock_soundwetlevellooptype);

    /* soundloopsilent (ms) */
    *(int *)(p + 0x64) = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_soundloopsilent));

    /* line 436: viewkickfadein - max(val, 1.0f) */
    val = dvar_get_float(_dvar_shellshock_viewkickfadein);
    *(float *)(p + 0x38) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 437: viewkickperiod */
    val = dvar_get_float(_dvar_shellshock_viewkickperiod);
    *(float *)(p + 0x3c) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 438: viewkickradius */
    val = dvar_get_float(_dvar_shellshock_viewkickradius);
    *(float *)(p + 0x40) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 439: viewkickpitch */
    val = dvar_get_float(_dvar_shellshock_viewkickpitch);
    *(float *)(p + 0x4c) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 440: viewkickyaw */
    val = dvar_get_float(_dvar_shellshock_viewkickyaw);
    *(float *)(p + 0x50) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 441: soundroomtype */
    val = dvar_get_float(_dvar_shellshock_soundroomtype);
    *(float *)(p + 0x48) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 442: sounddrylevel */
    val = dvar_get_float(_dvar_shellshock_sounddrylevel);
    *(float *)(p + 0x44) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 443: soundwetlevel */
    val = dvar_get_float(_dvar_shellshock_soundwetlevel);
    *(float *)(p + 0x54) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 444: soundmodenddelay */
    val = dvar_get_float(_dvar_shellshock_soundmodenddelay);
    *(float *)(p + 0x58) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 445: soundendduration */
    val = dvar_get_float(_dvar_shellshock_soundendduration);
    *(float *)(p + 0x5c) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 446: soundfade */
    val = dvar_get_float(_dvar_shellshock_soundfade);
    *(float *)(p + 0x60) = (val > 0.0f && val > 1.0f) ? val : 1.0f;

    /* line 465: mouseenable (bool) */
    *(int *)(p + 0x70) = dvar_get_bool(_dvar_shellshock_mouseenable);

    /* line 428: mousefadein (ms) */
    *(int *)(p + 0x74) = float_seconds_to_ms(dvar_get_float(_dvar_shellshock_mousefadein));

    /* line 468: mouseturnrate */
    *(int *)(p + 0x7c) = dvar_get_int(_dvar_shellshock_mouseturnrate);

    /* line 469: mousereducemax */
    *(int *)(p + 0x80) = dvar_get_int(_dvar_shellshock_mousereducemax);

    /* line 470: mousesensitivity */
    *(int *)(p + 0x78) = dvar_get_int(_dvar_shellshock_mousesensitivity);
}

/* Deactivate sound and reset shellshock state */
static void CG_DeactivateShellShockSound(byte *cgp)
{
    SND_DeactivateChannelVolumes(3, 0);
    SND_DeactivateEnvironmentEffects(2, 0);

    /* line 488: check and stop loop sound */
    if (*(int *)(cgp + 0x2cce4) != 0) {
        *(int *)(cgp + 0x2cce4) = 0;
        /* line 491 */
        {
            void *alias = CL_PickSoundAlias("shellshock_loop_end");
            SND_PlaySoundAlias(alias, 0x3ff, _snd_local_listener, 0, 1);
        }
    }
}

/* Reset motion/view state on cgp */
static void CG_ResetShellShockMotion(byte *cgp)
{
    /* line 503: sensitivity = 1.0f */
    *(int *)(cgp + 0x2cce8) = 0x3f800000; /* 1.0f as int bits */

    /* line 504: cap turn rate to 0,0 */
    CL_CapTurnRate(0, 0);
}

/* line 706 */
void CG_UpdateShellShock(const shellshock_parms_t *parms, int start, int duration)
{
    byte *cgp;
    int time;
    int timeSinceStart;
    byte *p = (byte *)parms;
    float fade;
    float channelvolume[11];
    int i;
    int loopTimeLeft;
    int loopFadeOut;

    /* line 710 */
    cgp = cg;
    time = *(int *)(cgp + 0x25bb0) - start;

    /* line 711 */
    if (start == 0 || time < 0) {
        /* Deactivate everything */
        CG_DeactivateShellShockSound(cgp);

        /* line 503 */
        CG_ResetShellShockMotion(cgp);

        /* line 515-516 */
        *(int *)(cgp + 0x2ccec) = 0;
        *(int *)(cgp + 0x2ccf0) = 0;

        /* line 530 */
        CL_SetUserCmdInShellshock(0);
        return;
    }

    /* Active shellshock */
    /* line 551: check if sound is enabled in parms */
    if (*(int *)(p + 0x14) == 0) {
        /* Sound not enabled */
        SND_DeactivateChannelVolumes(3, 0);
        SND_DeactivateEnvironmentEffects(2, 0);

        /* line 488 */
        if (*(int *)(cgp + 0x2cce4) != 0) {
            *(int *)(cgp + 0x2cce4) = 0;
            {
                void *alias = CL_PickSoundAlias("shellshock_loop_end");
                SND_PlaySoundAlias(alias, 0x3ff, _snd_local_listener, 0, 1);
            }
        }
        goto check_mouse;
    }

    {
        /* line 557 */
        int soundFadeOut = *(int *)(p + 0x1c);
        int soundFadeIn = *(int *)(p + 0x18);  /* actually this is at +0x18 which is soundfadein in ms */
        int totalWithFade = duration + *(int *)(p + 0x64) + soundFadeOut;
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
                channelvolume[i] = (*(float *)(p + 0x38 + i * 4) - 1.0f) * fade + 1.0f;
            }

            /* line 571 */
            SND_SetChannelVolumes(3, channelvolume, 0);

            /* line 573 */
            SND_SetEnvironmentEffects(2, (const char *)(p + 0x28),
                fade * *(float *)(p + 0x20),
                fade * *(float *)(p + 0x24), 0);
        }
    }

    {
        /* line 583: loop sound */
        int loopFadeOutVal = *(int *)(p + 0x6c);
        loopTimeLeft = duration + loopFadeOutVal + *(int *)(p + 0x68) - time;

        /* line 584 */
        if (loopTimeLeft > 0) {
            /* line 586-587 */
            void *pAlias0 = CL_PickSoundAlias("shellshock_loop");
            void *pAlias1 = CL_PickSoundAlias("shellshock_loop2");
            int loopFadeIn = *(int *)(p + 0x68);

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

            loopFadeOutVal = *(int *)(p + 0x6c);
        }

        /* line 598: check loop end */
        cgp = cg;
        {
            int cgTime = *(int *)(cgp + 0x25bb0);
            int loopEndTime = cgTime - time + duration + loopFadeOutVal;

            /* line 599 */
            if (cgTime < loopEndTime) {
                /* line 601 */
                if (*(int *)(cgp + 0x2cce4) != 0) {
                    /* line 603 */
                    *(int *)(cgp + 0x2cce4) = 0;
                    /* line 604 */
                    {
                        void *alias = CL_PickSoundAlias("shellshock_loop_end");
                        SND_PlaySoundAlias(alias, 0x3ff, _snd_local_listener, 0, 1);
                    }
                }
            } else {
                /* line 607 */
                if (*(int *)(cgp + 0x2cce4) != loopEndTime) {
                    /* line 609 */
                    *(int *)(cgp + 0x2cce4) = loopEndTime;

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
        byte *parms_p = (byte *)parms;
        int mouseEnabled = *(int *)(parms_p + 0x70);
        int timeSinceStart2 = duration - time;

        if (mouseEnabled == 0) {
            /* line 503 */
            cgp = *(byte **)_cg_p;
            CG_ResetShellShockMotion(cgp);

            timeSinceStart2 = duration - time;
            goto check_viewkick;
        }

        {
            /* line 634 */
            int mouseFadeIn = *(int *)(parms_p + 0x74);
            if (timeSinceStart2 >= mouseFadeIn) {
                /* Fully faded in */
                /* line 650 */
                cgp = *(byte **)_cg_p;
                *(int *)(cgp + 0x2cce8) = *(int *)(parms_p + 0x78);

                /* line 651 */
                CL_CapTurnRate(*(int *)(parms_p + 0x7c), *(int *)(parms_p + 0x80));
            } else if (timeSinceStart2 <= 0) {
                /* line 503: not started yet */
                cgp = *(byte **)_cg_p;
                CG_ResetShellShockMotion(cgp);
            } else {
                /* line 640: fading in */
                float t = (float)timeSinceStart2 / (float)mouseFadeIn;

                /* line 648 */
                if (t == 1.0f) {
                    /* Fully faded in */
                    /* line 650 */
                    cgp = *(byte **)_cg_p;
                    *(int *)(cgp + 0x2cce8) = *(int *)(parms_p + 0x78);
                    CL_CapTurnRate(*(int *)(parms_p + 0x7c), *(int *)(parms_p + 0x80));
                } else {
                    /* line 655-656: interpolate */
                    cgp = *(byte **)_cg_p;
                    float sensitivity = *(float *)(parms_p + 0x78);
                    *(float *)(cgp + 0x2cce8) = (sensitivity - 1.0f) * t + 1.0f;

                    float minRate = *(float *)(parms_p + 0x7c) / t;
                    float maxRate = *(float *)(parms_p + 0x80) / t;
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
        *(int *)(cgp + 0x2ccec) = 0;
        *(int *)(cgp + 0x2ccf0) = 0;
    } else {
        /* line 686 */
        int viewKickTime = *(int *)(p + 0x00); /* view (3000ms) */
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
        amplitude = amplitude * *(float *)(p + 0x08);

        /* line 691 */
        {
            float phase = (float)time * *(float *)(p + 0x04);
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
            *(float *)(cgp + 0x2ccec) = amplitude * resultX;

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

            *(float *)(cgp + 0x2ccf0) = amplitude * resultY;
        }
    }

    /* line 720 */
    CL_SetUserCmdInShellshock(time < duration ? 1 : 0);
}
