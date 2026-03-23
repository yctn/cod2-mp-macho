/* ASM dump from: com_sndalias.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_sndalias.cpp */

#include "common_types.h"
#include "imports.h"

extern void * Hunk_AllocateTempMemoryInternal(int size, const char *name);
extern void * Hunk_AllocInternal(int size);
extern float GraphGetValueFromFraction(int knotCount, float *knots, float fraction);

extern struct g_sa_type g_sa; /* 0x0 */

/* Externs for Com_LoadSoundAliases */
extern int strnicmp(const char *s1, const char *s2, int n);
extern char *strcpy(char *dest, const char *src);
extern char *strlwr(char *s);
extern void Com_StripExtension(const char *in, char *out);
extern char **FS_ListFiles(const char *path, const char *extension, int behavior, int *numfiles);
extern void FS_FreeFileList(char **list, int behavior);
extern void *Hunk_HideTempMemory(void);
extern void Hunk_ShowTempMemory(void *mark);
extern void Hunk_ClearTempMemory(void);
extern void Com_InitSoundAlias(void);
extern void Com_MakeSoundAliasesPermanent(void *aliases, void *counts);
extern void Com_LoadSoundAliasFile(const char *trimspec, const char *loadspecCurGame, const char *fileName);
extern int Com_LoadSoundAliasSounds(void *counts);
extern void Com_InitDefaultSoundAliasVolumeFalloffCurve(void *curve);
extern Bool Com_LoadVolumeFalloffCurve(const char *name, void *curve);
extern void Cmd_AddCommand(const char *cmdName, void (*function)(void));
extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void I_strncpyz(char *dest, const char *src, int destsize);
/* Com_SoundList_f declared below as static */

float Com_GetVolumeFalloffCurveValue(SndCurve *volumeFalloffCurve, float fraction);
const char * Com_GetSoundFileName(const snd_alias_t *pAlias);
J_COLOR_SPACE * Com_GetSoundFileMem(const snd_alias_t *pAlias);
J_COLOR_SPACE Com_LoadSoundAliases(const char *loadspec, const char *loadspecCurGame, snd_alias_system_t system);
SndCurve * Com_RegisterSoundAliasVolumeFalloffCurve(const char *filename, const char *sourceFile);
SndCurve * Com_GetDefaultSoundAliasVolumeFalloffCurve(void);
J_COLOR_SPACE * Com_AllocateTempSoundMemory(int size, const char *name);
J_COLOR_SPACE * Com_AllocSoundMemory(int size, const char *name, int type);
J_COLOR_SPACE Com_UnloadSoundAliasSounds(snd_alias_system_t system);
J_COLOR_SPACE Com_UnloadSoundAliases(snd_alias_system_t system);
static J_COLOR_SPACE Com_StreamedSoundList(void);
static J_COLOR_SPACE Com_LoadedSoundList(void);
static J_COLOR_SPACE Com_SoundList_f(void);
snd_alias_t * Com_PickSoundAliasFromList(snd_alias_list_t *aliasList);
snd_alias_list_t * Com_FindSoundAlias(const char *name);
Bool Com_AddAliasList(const char *name, snd_alias_list_t *aliasList);
J_COLOR_SPACE Com_DuplicateSoundAlias(snd_alias_list_t *aliasCopy, const char *name);
int SND_GetAliasOffset(const snd_alias_t *alias);
snd_alias_t * SND_GetAliasWithOffset(const char *name, int offset);
snd_alias_t * Com_PickSoundAlias(const char *aliasname);

/* line 296 */
float Com_GetVolumeFalloffCurveValue(SndCurve *volumeFalloffCurve, float fraction)
{
    return GraphGetValueFromFraction(*(int *)((char *)volumeFalloffCurve + 4), (float *)((char *)volumeFalloffCurve + 8), fraction);
}

/* line 874 */
const char * Com_GetSoundFileName(const snd_alias_t *pAlias)
{
    return pAlias->soundFile->soundName;
}

/* line 887 */
J_COLOR_SPACE * Com_GetSoundFileMem(const snd_alias_t *pAlias)
{
    return (J_COLOR_SPACE *)pAlias->soundFile->fileMem;
}

/* line 979 */
J_COLOR_SPACE Com_LoadSoundAliases(const char *loadspec, const char *loadspecCurGame, snd_alias_system_t system)
{
    char trimspec[0x44];
    int fileCount;
    char **fileNames;
    void *mark;
    int i;
    char *vfcurveFiles;
    int vfcurveCount;
    int sysOffset;

    /* line 950-968: one-time initialization of volume falloff curves */
    if (!*(char *)((byte *)&g_sa + 4240)) {
        /* line 950: zero out curve data */
        memset((byte *)&g_sa + 4244, 0, 0x480);

        /* line 953: init default curve */
        Com_InitDefaultSoundAliasVolumeFalloffCurve((void *)((byte *)&g_sa + 4244));

        /* line 955: list .vfcurve files */
        vfcurveFiles = (char *)FS_ListFiles("soundaliases", "vfcurve", 0, &vfcurveCount);

        /* line 956: check count limit */
        if (vfcurveCount > 15) {
            Com_Error(1, "Snd_Alias Curve initialization: '.vfcurve' file count (%d) "
                         , vfcurveCount, 15);
        }

        /* line 957-966: load each curve file */
        {
            int ci = 0;
            void *curvePtr = (void *)((byte *)&g_sa + 4244);
            char *namePtr = (char *)((byte *)&g_sa + 5396);
            char **fptr = (char **)vfcurveFiles;

            while (ci < vfcurveCount) {
                /* line 961-962: advance pointers */
                ci++;
                namePtr += 0x40;
                fptr++;
                curvePtr = (void *)((byte *)curvePtr + 0x48);

                /* line 962: compute filename length (minus extension ".vfcurve" = 8) */
                {
                    const char *fn = *(fptr - 1);
                    int fnLen = strlen(fn) - 8;
                    I_strncpyz(namePtr, fn, fnLen);
                }

                /* line 963: load the curve */
                if (!Com_LoadVolumeFalloffCurve(namePtr, curvePtr)) {
                    /* line 964 */
                    Com_Error(0, "Failed to load sndcurve file '%s'", *(fptr - 1));
                }
            }
        }

        /* line 967 */
        FS_FreeFileList((char **)vfcurveFiles, 0xa);

        /* line 968 */
        *(char *)((byte *)&g_sa + 4240) = 1;
    }

    /* line 1014: determine loadspec type and extract trimspec */
    if (strnicmp(loadspec, "maps/mp/", 8) == 0) {
        /* line 1015 */
        Com_StripExtension(loadspec + 8, trimspec);
    } else if (strnicmp(loadspec, "maps/", 5) == 0) {
        /* line 1017 */
        Com_StripExtension(loadspec + 5, trimspec);
    } else {
        /* line 1019: copy as-is */
        strcpy(trimspec, loadspec);
    }

    /* line 1027 */
    strlwr(trimspec);

    /* line 1028: if system == 1 and sv_running, copy server aliases to client */
    if (system == 1) {
        const dvar_t *sv_running = *(const dvar_t **)imp_com_sv_running;
        if (sv_running->current.enabled != 0) {
            /* line 1068: copy server system counts to client */
            *(int *)((byte *)&g_sa + 4120) = *(int *)((byte *)&g_sa + 4136);
            *(int *)((byte *)&g_sa + 4124) = *(int *)((byte *)&g_sa + 4140);
            *(int *)((byte *)&g_sa + 4128) = *(int *)((byte *)&g_sa + 4144);
            *(int *)((byte *)&g_sa + 4132) = *(int *)((byte *)&g_sa + 4148);

            /* line 1069 */
            *(int *)((byte *)&g_sa + 4160) = *(int *)((byte *)&g_sa + 4168);
            *(int *)((byte *)&g_sa + 4164) = *(int *)((byte *)&g_sa + 4172);

            goto after_load;
        }
    }

    /* line 1032: list sound alias files */
    fileNames = FS_ListFiles("soundaliases", "csv", 0, &fileCount);

    /* line 1035 */
    if (fileCount == 0) {
        /* line 1037 */
        Com_Printf((const char *)str_0021e5b0);
        goto done;
    }

    /* line 1043 */
    mark = Hunk_HideTempMemory();

    /* line 1045 */
    Com_InitSoundAlias();

    /* line 1047: load each alias file */
    for (i = 0; i < fileCount; i++) {
        /* line 1048 */
        Com_LoadSoundAliasFile(trimspec, loadspecCurGame, fileNames[i]);
    }

    /* line 1053: make aliases permanent */
    sysOffset = (int)system;
    Com_MakeSoundAliasesPermanent(
        (void *)((byte *)&g_sa + 4104 + sysOffset * 16),
        (void *)((byte *)&g_sa + 4152 + sysOffset * 8));

    /* line 1057 */
    Hunk_ClearTempMemory();

    /* line 1058 */
    Hunk_ShowTempMemory(mark);

    /* line 1060 */
    FS_FreeFileList(fileNames, 0xa);

after_load:
    /* line 1075: register snd_list command */
    if (*(short *)((byte *)&g_sa) == 0) {
        /* line 1076 */
        Cmd_AddCommand("snd_list", (void (*)(void))Com_SoundList_f);
    }

    /* line 1081 */
    *(char *)((byte *)&g_sa + (int)system) = 1;

    /* line 1085 */
    if ((int)system <= 1) {
        /* line 1087 */
        int missCount = Com_LoadSoundAliasSounds((void *)((byte *)&g_sa + 4152 + (int)system * 8));
        /* line 1088 */
        if (missCount != 0) {
            const dvar_t *snd_errorOnMissing_dvar = *(const dvar_t **)imp_snd_errorOnMissing;
            if (snd_errorOnMissing_dvar->current.enabled != 0) {
                /* line 1089 */
                int errCode = (system != 0) ? 1 : 0;
                { extern const char *va(const char *fmt, ...);
                Com_Error(errCode, "%s", va("%i sound file(s) are missing or in a bad format\n", missCount)); }
            }
        }
    }

done:
    return (J_COLOR_SPACE)0;
}
