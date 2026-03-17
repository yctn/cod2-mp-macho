/* ASM dump from: snd.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/snd.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/memfile.h"
 *   #include "PC/universal/com_math.h"
 */

extern const dvar_t *snd_errorOnMissing; /* 0x0 */
extern const dvar_t *snd_touchStreamFilesOnLoad; /* 0x0 */
extern const dvar_t *snd_khz; /* 0x0 */
extern const dvar_t *snd_bits; /* 0x0 */
extern const dvar_t *snd_stereo; /* 0x0 */
extern const dvar_t *snd_volume; /* 0x0 */
extern const dvar_t *snd_enableReverb; /* 0x0 */
extern struct snd_local_t g_snd; /* 0x0 */
extern const dvar_t *snd_slaveFadeTime; /* 0x0 */
extern const dvar_t *snd_enable2D; /* 0x0 */
extern const dvar_t *snd_enable3D; /* 0x0 */
extern const dvar_t *snd_enableStream; /* 0x0 */
extern const char *snd_roomStrings[];

float Com_GetVolumeFalloffCurveValue(SndCurve *volumeFalloffCurve, float fraction);
int stricmp(const char *str1, const char *str2);
void Com_Printf(const char *fmt, ...);
void Com_DPrintf(const char *fmt, ...);
void Z_FreeInternal(void *ptr);
void AxisCopy(vec3_t *in, vec3_t *out);
unsigned int Voice_Shutdown(void);
void Com_UnloadSoundAliases(snd_alias_system_t system);
void SND_ShutdownDriver(void);
void Cmd_RemoveCommand(const char *cmdName);
int Cmd_Argc(void);
char *Cmd_Argv(int arg);
int atoi(const char *str);
double atof(const char *str);
const dvar_t *Dvar_RegisterBool(const char *name, int defaultValue, unsigned int flags);
const dvar_t *Dvar_RegisterInt(const char *name, int defaultValue, int min, int max, unsigned int flags);
const dvar_t *Dvar_RegisterFloat(const char *name, float defaultValue, float min, float max, unsigned int flags);
Bool SND_InitDriver(void);
int Sys_Milliseconds(void);
void Cmd_AddCommand(const char *cmdName, void (*function)(void));
void Voice_Init(void);
void CG_GetEntityOrientation(int entnum, vec_t *origin, vec3_t *axis);

/* from snd_driver.c */
Bool SND_Is2DChannelFree(int index);
Bool SND_Is3DChannelFree(int index);
Bool SND_IsStreamChannelFree(int index);
void SND_Stop2DChannel(int index);
void SND_Stop3DChannel(int index);
void SND_StopStreamChannel(int index);
void SND_Pause2DChannel(int index);
void SND_Pause3DChannel(int index);
void SND_PauseStreamChannel(int index);
void SND_Unpause2DChannel(int index, int timeshift);
void SND_Unpause3DChannel(int index, int timeshift);
void SND_UnpauseStreamChannel(int index, int timeshift);
void SND_SetRoomtype(int roomtype);
void SND_Update2DChannelReverb(int index);
void SND_Update3DChannelReverb(int index);
void SND_UpdateStreamChannelReverb(int index);
float SND_Get2DChannelVolume(int index);
float SND_Get3DChannelVolume(int index);
float SND_GetStreamChannelVolume(int index);
int SND_Get2DChannelPlaybackRate(int index);
int SND_Get3DChannelPlaybackRate(int index);
int SND_GetStreamChannelPlaybackRate(int index);
const char *Com_GetSoundFileName(const snd_alias_t *alias);
float Vec3Distance(const vec_t *v1, const vec_t *v2);
float Vec3DistanceSq(const vec_t *v1, const vec_t *v2);
void SND_Set3DPosition(int index, const vec_t *org);
extern const dvar_t *cl_paused;
extern const dvar_t *com_statmon;
int SND_GetDriverCPUPercentage(void);
void StatMon_Warning(int severity, int timeout, const char *msg);
void SND_DriverPreUpdate(int frametime);
void SND_DriverPostUpdate(int frametime);
float Com_GetTimescaleForSnd(void);
void MemFile_InitForReading(MemoryFile *memFile, int size, void *buffer);
void MemFile_WriteData(MemoryFile *memFile, int bytes, const void *data);
void MemFile_ReadData(MemoryFile *memFile, int bytes, void *data);
void MemFile_WriteCString(MemoryFile *memFile, const char *str);
const char *MemFile_ReadCString(MemoryFile *memFile);
short SND_GetAliasOffset(const snd_alias_t *alias);
const snd_alias_t *SND_GetAliasWithOffset(const char *name, int offset);
int SND_Get3DChannelLength(int index);
int SND_Get2DChannelLength(int index);
int SND_GetStreamChannelLength(int index);
void SND_Get3DChannelSaveInfo(int index, void *info);
void SND_Get2DChannelSaveInfo(int index, void *info);
void SND_GetStreamChannelSaveInfo(int index, void *info);
void SND_Set2DChannelFromSaveInfo(int index, void *info);
void SND_SetStreamChannelFromSaveInfo(int index, void *info);
int SND_StartAlias2DSample(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int *pChannel, snd_alias_system_t system);
int SND_StartAlias3DSample(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int *pChannel, snd_alias_system_t system);
int SND_StartAliasStreamOnChannel(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int index, snd_alias_system_t system);
int Com_GetSoundFileMem(const snd_alias_t *alias);
float randomf(void);
void Dvar_ClearModified(const dvar_t *dvar);
void SND_Update3DChannel(int index, int frametime);
void SND_UpdateStreamChannel(int index, int frametime);
void SND_Update2DChannel(int index, int frametime);
void SND_Set3DChannelPlaybackRate(int index, int rate);
void SND_SetStreamChannelPlaybackRate(int index, int rate);
void SND_Set2DChannelPlaybackRate(int index, int rate);
float floorf(float x);
void Com_Error(int level, const char *fmt, ...);
const snd_alias_t *Com_PickSoundAlias(const char *aliasname);
const snd_alias_t *Com_PickSoundAliasFromList(snd_alias_list_t *aliasList);

int SND_GetListenerIndexNearestToOrigin(const vec_t *origin);
void SND_SaveListeners(snd_listener *listeners);
void SND_RestoreListeners(snd_listener *listeners);
float SND_GetLerpedSlavePercentage(float baseSlavePercentage);
float SND_Attenuate(SndCurve *volumeFalloffCurve, float radius, float mindist, float maxdist);
Bool SND_IsAliasChannel3D(int channel);
static __attribute_regparm__(3) Bool SND_ValidateSoundAliasBlend(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, Bool bReport);
static void SND_PauseSounds(void);
static void SND_UnpauseSounds(void);
void SND_SetChannelVolumes(int priority, const float *channelvolume, int fademsec);
void SND_DeactivateChannelVolumes(int priority, int fademsec);
void SND_UpdateLoopingSounds(void);
Bool SND_UpdateBackgroundVolume(int track, int frametime);
void SND_DeactivateEnvironmentEffects(int priority, int fademsec);
void SND_SetEnvironmentEffects(int priority, const char *roomstring, float drylevel, float wetlevel, int fademsec);
void SND_UpdateReverbs(void);
void SND_ErrorCleanup(void);
void SND_DisconnectListener(void);
void SND_SetListener(int entnum, const vec_t *origin, vec3_t *axis);
void SND_SetChannelInfo(int index, int entnum, const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, const vec_t *origin, float volume, float pitch, int srcChannelCount, int baserate, int total_msec, int start_msec, int startDelay, int master, snd_alias_system_t system);
void SND_GetCurrent3DPosition(int entnum, const vec_t *offset, vec_t *pos_out);
int SND_GetSoundOverlay(snd_overlay_type_t type, snd_overlay_info_t *info, int maxcount, int *cpu);
static __attribute__((regparm(3), sseregparm)) int SND_StartAliasStream(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int treatAsMaster, int *pChannel, snd_alias_system_t system);
static __attribute_regparm__(2) void SND_SaveChanInfo(snd_channel_info_t *chaninfo, MemoryFile *memFile);
void SND_Init(void);
static __attribute__((regparm(3), sseregparm)) int SND_PlaySoundAlias_Internal(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, int *pChannel, int timeshift, int treatAsMaster, snd_alias_system_t system);
int SND_PlayLocalSoundAliasByName(const char *aliasname, snd_alias_system_t system);
int SND_PlayLocalSoundAlias(snd_alias_list_t *aliasList, snd_alias_system_t system);
int SND_PlayBlendedSoundAliases(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float fLerp, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system);
int SND_PlaySoundAliasAsMaster(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system);
int SND_PlaySoundAlias(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system);
int SND_FindFree2DChannel(int entnum, int entchannel);
int SND_FindFree3DChannel(int entnum, int entchannel);
static __attribute_regparm__(2) void SND_RestoreChanInfo(snd_channel_info_t *chaninfo, MemoryFile *memFile);
static __attribute_regparm__(3) void SND_StartBackground(int track, const snd_alias_t *pAlias, int fadetime, snd_alias_system_t system);
void SND_PlayAmbientAlias(const snd_alias_t *pAlias, int fadetime, snd_alias_system_t system);
void SND_PlayMusicAlias(const snd_alias_t *pAlias, snd_alias_system_t system);
void SND_StopMusic(int fadetime);
void SND_StopSounds(snd_stopsounds_arg_t which);
void SND_ShutdownChannels(void);
void SND_Shutdown(void);
void SND_FadeAllSounds(float volume, int fadetime);
void SND_SetEnvironmentEffects_f(void);
void SND_DeactivateEnvironmentEffects_f(void);
void SND_Save(MemoryFile *memFile);
static __attribute_regparm__(2) Bool SND_RestoreStreamChannel(int channel, MemoryFile *memFile);
void SND_Restore(MemoryFile *memFile);
void SND_Update(void);

int SND_GetListenerIndexNearestToOrigin(const vec_t *origin)
{
    return 0;
}

void SND_SaveListeners(snd_listener *listeners)
{
    *listeners = g_snd.listeners[0];
}

void SND_RestoreListeners(snd_listener *listeners)
{
    g_snd.listeners[0] = *listeners;
}

float SND_GetLerpedSlavePercentage(float baseSlavePercentage)
{
    return 1.0f - (1.0f - baseSlavePercentage) * g_snd.slaveLerp;
}

float SND_Attenuate(SndCurve *volumeFalloffCurve, float radius, float mindist, float maxdist)
{
    float dist = radius - mindist;
    if (dist <= 0.0f) {
        return 1.0f;
    }
    if (mindist == maxdist) {
        return 0.0f;
    }
    float fraction = dist / (maxdist - mindist);
    if (fraction >= 1.0f) {
        return 0.0f;
    }
    return Com_GetVolumeFalloffCurveValue(volumeFalloffCurve, fraction);
}

Bool SND_IsAliasChannel3D(int channel)
{
    if (channel <= 10 && ((1 << channel) & 0x786)) {
        return 0;
    }
    return 1;
}

/* line 924 */
static __attribute_regparm__(3)
Bool SND_ValidateSoundAliasBlend(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, Bool bReport)
{
    int flags0, flags1;
    int isLooping;

    if (pAlias0 == pAlias1)
        return 1;

    if (Com_GetSoundFileName(pAlias0) != Com_GetSoundFileName(pAlias1)) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they don't use the same sound file\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if (pAlias0->volumeFalloffCurve != pAlias1->volumeFalloffCurve) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they do not have the same volume falloff curve\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    flags0 = pAlias0->flags;
    flags1 = pAlias1->flags;
    isLooping = flags0 & 1;

    if (isLooping != (flags1 & 1)) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they do not have the same looping status\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if ((flags0 & 0x60) != (flags1 & 0x60)) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they are not both loaded or both streamed\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if ((flags0 & 0x780) != (flags1 & 0x780)) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they don't use the same channel\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if ((flags0 & 2) != (flags1 & 2)) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but only one of them is a 'master' alias\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if ((flags0 & 4) != (flags1 & 4)) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but only one of them is a 'slave' alias\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if ((flags0 & 8) != (flags1 & 8)) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they don't use the same fulldrylevel setting\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if ((flags0 & 0x10) != (flags1 & 0x10)) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they don't use the same nowetlevel setting\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if (pAlias0->fSlavePercentage != pAlias1->fSlavePercentage) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they do not have the same slave percentages.\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if (pAlias0->startDelay != pAlias1->startDelay) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they do not have the same start delay.\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    if (isLooping) {
        if (pAlias0->fPitchMin != pAlias0->fPitchMax || pAlias1->fPitchMin != pAlias1->fPitchMax) {
            if (!bReport)
                return 0;
            Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they are looping and at least one of them has a random pitch\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
            return 0;
        }
        if (pAlias0->fVolMin != pAlias0->fVolMax || pAlias1->fVolMin != pAlias1->fVolMax) {
            if (!bReport)
                return 0;
            Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but they are looping and at least one of them has a random volume\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
            return 0;
        }
    }

    if (pAlias0->pszSecondaryAliasName || pAlias1->pszSecondaryAliasName) {
        if (!bReport)
            return 0;
        Com_Error(1, "tried to blend between sound aliases '%s' and '%s', but one or both has a secondary alias.\n", pAlias0->pszAliasName, pAlias1->pszAliasName);
        return 0;
    }

    return 1;
}

/* line 1104 */
static void SND_PauseSounds(void)
{
    int i;

    if (!g_snd.Initialized2d)
        return;
    if (g_snd.paused)
        return;

    for (i = 45; i < 45 + g_snd.max_2D_channels; i++) {
        if (SND_Is2DChannelFree(i))
            continue;
        if (!g_snd.pauseSettings[(g_snd.chaninfo[i].pAlias0->flags & 0x780) >> 7])
            continue;
        SND_Pause2DChannel(i);
    }

    for (i = 0; i < g_snd.max_3D_channels; i++) {
        if (SND_Is3DChannelFree(i))
            continue;
        if (!g_snd.pauseSettings[(g_snd.chaninfo[i].pAlias0->flags & 0x780) >> 7])
            continue;
        SND_Pause3DChannel(i);
    }

    for (i = 32; i < 32 + g_snd.max_stream_channels; i++) {
        if (SND_IsStreamChannelFree(i))
            continue;
        if (!g_snd.pauseSettings[(g_snd.chaninfo[i].pAlias0->flags & 0x780) >> 7])
            continue;
        SND_PauseStreamChannel(i);
    }

    g_snd.paused = 1;
    g_snd.pausetime = g_snd.time;
}

/* line 1137 */
static void SND_UnpauseSounds(void)
{
    int i;
    int timeshift;

    if (!g_snd.Initialized2d)
        return;
    if (!g_snd.paused)
        return;

    timeshift = g_snd.time - g_snd.pausetime;

    for (i = 45; i < 45 + g_snd.max_2D_channels; i++) {
        if (SND_Is2DChannelFree(i))
            continue;
        if (!g_snd.chaninfo[i].paused)
            continue;
        SND_Unpause2DChannel(i, timeshift);
    }

    for (i = 0; i < g_snd.max_3D_channels; i++) {
        if (SND_Is3DChannelFree(i))
            continue;
        if (!g_snd.chaninfo[i].paused)
            continue;
        SND_Unpause3DChannel(i, timeshift);
    }

    for (i = 32; i < 32 + g_snd.max_stream_channels; i++) {
        if (SND_IsStreamChannelFree(i))
            continue;
        if (!g_snd.chaninfo[i].paused)
            continue;
        SND_UnpauseStreamChannel(i, timeshift);
    }

    g_snd.paused = 0;
    g_snd.pausetime = 0;
}

/* line 1340 */
void SND_SetChannelVolumes(int priority, const float *channelvolume, int fademsec)
{
    int j;
    int k;
    snd_channelvolgroup *channelVolGroup;
    float fadetime;

    channelVolGroup = &g_snd.channelVolGroups[priority];
    channelVolGroup->active = 1;

    if (fademsec <= 0)
        fadetime = 1.0f;
    else
        fadetime = (float)fademsec;

    for (j = 0; j < 11; j++) {
        channelVolGroup->channelvol[j].goalvolume = channelvolume[j];
        channelVolGroup->channelvol[j].volume = g_snd.channelvol->channelvol[j].volume;
        channelVolGroup->channelvol[j].goalrate = (channelvolume[j] - g_snd.channelvol->channelvol[j].volume) / fadetime;
    }

    if (channelVolGroup == g_snd.channelvol)
        return;

    for (k = priority + 1; k <= 3; k++) {
        if (g_snd.channelVolGroups[k].active)
            return;
    }

    g_snd.channelvol = channelVolGroup;
}

/* line 1382 */
void SND_DeactivateChannelVolumes(int priority, int fademsec)
{
    int j;
    snd_channelvolgroup *channelVolGroup;
    float fadetime;
    int newPriority;

    channelVolGroup = &g_snd.channelVolGroups[priority];
    channelVolGroup->active = 0;

    if (channelVolGroup != g_snd.channelvol)
        return;

    newPriority = priority - 1;
    while (newPriority >= 0 && !g_snd.channelVolGroups[newPriority].active) {
        newPriority--;
    }

    if (fademsec <= 0)
        fadetime = 1.0f;
    else
        fadetime = (float)fademsec;

    g_snd.channelvol = &g_snd.channelVolGroups[newPriority];
    for (j = 0; j < 11; j++) {
        g_snd.channelvol->channelvol[j].volume = channelVolGroup->channelvol[j].volume;
        g_snd.channelvol->channelvol[j].goalrate = (g_snd.channelvol->channelvol[j].goalvolume - channelVolGroup->channelvol[j].volume) / fadetime;
    }
}

/* line 1420 */
void SND_UpdateLoopingSounds(void)
{
    int i;

    if (!g_snd.Initialized2d)
        return;
    if (g_snd.paused)
        return;

    for (i = 0; i < g_snd.max_3D_channels; i++) {
        if (SND_Is3DChannelFree(i))
            continue;
        if (!(g_snd.chaninfo[i].pAlias0->flags & 1))
            continue;
        if (g_snd.chaninfo[i].looptime == g_snd.looptime)
            continue;
        SND_Stop3DChannel(i);
    }

    for (i = 45; i < 45 + g_snd.max_2D_channels; i++) {
        if (SND_Is2DChannelFree(i))
            continue;
        if (!(g_snd.chaninfo[i].pAlias0->flags & 1))
            continue;
        if (g_snd.chaninfo[i].looptime == g_snd.looptime)
            continue;
        SND_Stop2DChannel(i);
    }

    for (i = 32; i < 32 + g_snd.max_stream_channels; i++) {
        if (SND_IsStreamChannelFree(i))
            continue;
        if (!(g_snd.chaninfo[i].pAlias0->flags & 1))
            continue;
        if (g_snd.chaninfo[i].looptime == g_snd.looptime)
            continue;
        SND_StopStreamChannel(i);
    }

    g_snd.looptime = g_snd.time;
}

/* line 1474 */
Bool SND_UpdateBackgroundVolume(int track, int frametime)
{
    int channel = track + 32;
    float goalrate = g_snd.background[track].goalrate;
    float goalvolume = g_snd.background[track].goalvolume;
    float newvol = g_snd.chaninfo[channel].basevolume + goalrate * (float)frametime;

    if (goalrate > 0.0f) {
        if (newvol > goalvolume)
            newvol = goalvolume;
    } else {
        if (goalvolume > newvol) {
            if (goalvolume == 0.0f) {
                SND_StopStreamChannel(channel);
                return 0;
            }
            newvol = goalvolume;
        }
    }

    g_snd.chaninfo[channel].looptime = g_snd.looptime;
    g_snd.chaninfo[channel].basevolume = newvol;
    return 1;
}

/* line 1712 */
void SND_DeactivateEnvironmentEffects(int priority, int fademsec)
{
    snd_enveffect *effect;
    float fadetime;
    int newPriority;

    effect = &g_snd.envEffects[priority];
    effect->active = 0;

    if (effect != g_snd.effect)
        return;

    newPriority = priority - 1;
    while (newPriority >= 0 && !g_snd.envEffects[newPriority].active) {
        newPriority--;
    }

    if (fademsec <= 0)
        fadetime = 1.0f;
    else
        fadetime = (float)fademsec;

    g_snd.effect = &g_snd.envEffects[newPriority];
    SND_SetRoomtype(g_snd.effect->roomtype);
    g_snd.effect->drylevel = effect->drylevel;
    g_snd.effect->dryrate = (g_snd.effect->drygoal - effect->drylevel) / fadetime;
    g_snd.effect->wetlevel = effect->wetlevel;
    g_snd.effect->wetrate = (g_snd.effect->wetgoal - effect->wetlevel) / fadetime;
}

/* line 1659 */
void SND_SetEnvironmentEffects(int priority, const char *roomstring, float drylevel, float wetlevel, int fademsec)
{
    snd_enveffect *effect;
    int roomtype;
    float fadetime;
    int k;
    const char **names;

    if (!g_snd.Initialized2d)
        return;

    effect = &g_snd.envEffects[priority];
    effect->active = 1;

    roomtype = 0;
    names = (const char **)(void *)snd_roomStrings;
    if (names[0]) {
        while (names[roomtype]) {
            if (stricmp(roomstring, names[roomtype]) == 0)
                break;
            roomtype++;
        }
        if (!names[roomtype]) {
            Com_Printf("invalid roomtype string '%s', it must be one of the following strings:\n", roomstring);
            names = (const char **)(void *)snd_roomStrings;
            for (k = 0; names[k]; k++) {
                if (names[k][0])
                    Com_Printf("  %s\n", names[k]);
            }
            roomtype = 0;
        }
    }

    effect->roomtype = roomtype;

    if (fademsec <= 0)
        fadetime = 1.0f;
    else
        fadetime = (float)fademsec;

    effect->drygoal = drylevel;
    effect->drylevel = g_snd.effect->drylevel;
    effect->dryrate = (drylevel - g_snd.effect->drylevel) / fadetime;
    effect->wetgoal = wetlevel;
    effect->wetlevel = g_snd.effect->wetlevel;
    effect->wetrate = (wetlevel - g_snd.effect->wetlevel) / fadetime;

    if (effect == g_snd.effect) {
        SND_SetRoomtype(roomtype);
        return;
    }

    for (k = priority + 1; k <= 2; k++) {
        if (g_snd.envEffects[k].active)
            return;
    }

    g_snd.effect = effect;
    SND_SetRoomtype(roomtype);
}

void SND_UpdateReverbs(void)
{
    int i;
    for (i = 0; i < g_snd.max_3D_channels; i++) {
        if (!SND_Is3DChannelFree(i)) {
            SND_Update3DChannelReverb(i);
        }
    }
    for (i = 45; i < 45 + g_snd.max_2D_channels; i++) {
        if (!SND_Is2DChannelFree(i)) {
            SND_Update2DChannelReverb(i);
        }
    }
    for (i = 32; i < 32 + g_snd.max_stream_channels; i++) {
        if (!SND_IsStreamChannelFree(i)) {
            SND_UpdateStreamChannelReverb(i);
        }
    }
}

void SND_ErrorCleanup(void)
{
    if (g_snd.restore.buffer) {
        Z_FreeInternal((void *)g_snd.restore.buffer);
        g_snd.restore.buffer = 0;
    }
}

void SND_DisconnectListener(void)
{
    memset(&g_snd.listeners[0], 0, sizeof(snd_listener));
}

void SND_SetListener(int entnum, const vec_t *origin, vec3_t *axis)
{
    if (!g_snd.Initialized2d) {
        return;
    }
    AxisCopy(axis, g_snd.listeners[0].orient.axis);
    g_snd.listeners[0].orient.origin[0] = origin[0];
    g_snd.listeners[0].orient.origin[1] = origin[1];
    g_snd.listeners[0].orient.origin[2] = origin[2];
    g_snd.listeners[0].entnum = entnum;
    g_snd.listeners[0].active = 1;
}

/* line 313 */
void SND_GetCurrent3DPosition(int entnum, const vec_t *offset, vec_t *pos_out)
{
    vec3_t org;
    vec3_t axis[3];
    float scale;

    CG_GetEntityOrientation(entnum, org, axis);

    /* Apply offset[0] along forward axis */
    scale = offset[0];
    org[0] += scale * axis[0][0];
    org[1] += scale * axis[0][1];
    org[2] += scale * axis[0][2];

    /* Apply offset[1] along right axis */
    scale = offset[1];
    org[0] += scale * axis[1][0];
    org[1] += scale * axis[1][1];
    org[2] += scale * axis[1][2];

    /* Apply offset[2] along up axis */
    scale = offset[2];
    pos_out[0] = org[0] + scale * axis[2][0];
    pos_out[1] = org[1] + scale * axis[2][1];
    pos_out[2] = org[2] + scale * axis[2][2];
}
/* line 2697 */
int SND_GetSoundOverlay(snd_overlay_type_t type, snd_overlay_info_t *info, int maxcount, int *cpu)
{
    vec3_t org;
    float dist;
    float vol;
    int rate;
    int i;
    int category;
    const snd_alias_t *pAlias;

    if (!g_snd.Initialized2d)
        return 0;

    if (cpu != NULL)
        *cpu = g_snd.cpu;

    switch (type) {
    case 2: /* stream channels */
        if (maxcount > g_snd.max_stream_channels)
            maxcount = g_snd.max_stream_channels;
        if (maxcount <= 0)
            return maxcount;
        for (i = 0; i < maxcount; i++) {
            if (SND_IsStreamChannelFree(i + 32)) {
                info[i].pszSampleName = NULL;
            } else {
                info[i].pszSampleName = Com_GetSoundFileName(g_snd.chaninfo[32 + i].pAlias0);

                rate = SND_GetStreamChannelPlaybackRate(i + 32);
                info[i].fPitch = (float)rate / (float)g_snd.chaninfo[32 + i].baserate;

                info[i].fBaseVolume = g_snd.chaninfo[32 + i].basevolume;

                vol = SND_GetStreamChannelVolume(i + 32);
                info[i].fCurVolume = vol;
                if (g_snd.volume != 0.0f)
                    info[i].fCurVolume = vol / g_snd.volume;

                pAlias = g_snd.chaninfo[32 + i].pAlias0;
                category = (pAlias->flags & 0x780) >> 7;
                if (category > 10 || !((1 << category) & 0x786)) {
                    SND_GetCurrent3DPosition(g_snd.chaninfo[32 + i].entnum, g_snd.chaninfo[32 + i].offset, org);
                    dist = Vec3Distance(org, g_snd.listeners[0].orient.origin);
                    info[i].dist = (int)dist;
                } else {
                    info[i].dist = -1;
                }
            }
        }
        return maxcount;

    case 1: /* 3D channels */
        if (maxcount > g_snd.max_3D_channels)
            maxcount = g_snd.max_3D_channels;
        if (maxcount <= 0)
            return maxcount;
        for (i = 0; i < maxcount; i++) {
            if (SND_Is3DChannelFree(i)) {
                info[i].pszSampleName = NULL;
            } else {
                info[i].pszSampleName = Com_GetSoundFileName(g_snd.chaninfo[i].pAlias0);

                rate = SND_Get3DChannelPlaybackRate(i);
                if (rate == 0)
                    rate = g_snd.chaninfo[i].baserate;
                info[i].fPitch = (float)rate / (float)g_snd.chaninfo[i].baserate;

                info[i].fBaseVolume = g_snd.chaninfo[i].basevolume;

                vol = SND_Get3DChannelVolume(i);
                info[i].fCurVolume = vol;
                if (g_snd.volume != 0.0f)
                    info[i].fCurVolume = vol / g_snd.volume;

                SND_GetCurrent3DPosition(g_snd.chaninfo[i].entnum, g_snd.chaninfo[i].offset, org);
                dist = Vec3Distance(org, g_snd.listeners[0].orient.origin);
                info[i].dist = (int)dist;
            }
        }
        return maxcount;

    case 3: /* 2D channels */
        if (maxcount > g_snd.max_2D_channels)
            maxcount = g_snd.max_2D_channels;
        if (maxcount <= 0)
            return maxcount;
        for (i = 0; i < maxcount; i++) {
            if (SND_Is2DChannelFree(i + 45)) {
                info[i].pszSampleName = NULL;
            } else {
                info[i].pszSampleName = Com_GetSoundFileName(g_snd.chaninfo[45 + i].pAlias0);

                rate = SND_Get2DChannelPlaybackRate(i + 45);
                if (rate == 0)
                    rate = g_snd.chaninfo[45 + i].baserate;
                info[i].fPitch = (float)rate / (float)g_snd.chaninfo[45 + i].baserate;

                info[i].fBaseVolume = g_snd.chaninfo[45 + i].basevolume;

                vol = SND_Get2DChannelVolume(i + 45);
                info[i].fCurVolume = vol;
                if (g_snd.volume != 0.0f)
                    info[i].fCurVolume = vol / g_snd.volume;

                info[i].dist = -1;
            }
        }
        return maxcount;

    default:
        return 0;
    }
}

/* line 563 */
static __attribute__((regparm(3), sseregparm))
int SND_StartAliasStream(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int treatAsMaster, int *pChannel, snd_alias_system_t system)
{
    int entchannel;
    int index;
    int channel;
    int i;
    int diff;
    vec3_t listenerOrg;
    float distNew, distOld;

    entchannel = (pAlias0->flags & 0x780) >> 7;

    /* Try to find a free stream channel */
    if (g_snd.max_stream_channels > 3) {
        for (i = 3; i < g_snd.max_stream_channels; i++) {
            channel = i + 32;
            if (SND_IsStreamChannelFree(channel)) {
                if (channel >= 0)
                    goto found;
                goto scan_replace;
            }
        }
    }

scan_replace:
    index = g_snd.max_stream_channels + 32;
    if (index <= 0x23) {
        channel = -1;
        goto after_scan;
    }

    channel = -1;

    for (i = 0x23; i < index; i++) {
        if (entchannel < g_snd.chaninfo[i].entchannel)
            goto next;

        if (channel < 0) {
            channel = i;
            goto next;
        }

        if (g_snd.chaninfo[i].entnum != g_snd.chaninfo[channel].entnum) {
            if (entnum == g_snd.chaninfo[i].entnum) {
                channel = i;
                goto next;
            }
            if (entnum == g_snd.chaninfo[channel].entnum)
                goto next;
        }

        if (g_snd.chaninfo[channel].entchannel != g_snd.chaninfo[i].entchannel) {
            diff = g_snd.chaninfo[i].entchannel - g_snd.chaninfo[channel].entchannel;
        } else if (g_snd.chaninfo[channel].endtime != g_snd.chaninfo[i].endtime) {
            diff = g_snd.chaninfo[channel].endtime - g_snd.chaninfo[i].endtime;
        } else {
            goto next;
        }

        if (diff < 0)
            channel = i;
next:
        ;
    }

    if (channel < 0)
        goto after_scan;

    /* Check if the existing sound is closer */
    listenerOrg[0] = g_snd.listeners[0].orient.origin[0];
    listenerOrg[1] = g_snd.listeners[0].orient.origin[1];
    listenerOrg[2] = g_snd.listeners[0].orient.origin[2];

    if (g_snd.chaninfo[channel].pAlias0 == pAlias0) {
        distNew = Vec3DistanceSq(org, listenerOrg);
        distOld = Vec3DistanceSq(g_snd.chaninfo[channel].org, listenerOrg);
        if (!(distOld > distNew))
            goto no_channel;
    }

    SND_StopStreamChannel(channel);

after_scan:
found:
    if (pChannel)
        *pChannel = channel;

    if (channel < 0)
        return 0;

    if (!*(unsigned char *)((char *)snd_enableStream + 8))
        return 0;

    /* Validate channel is not 3D */
    entchannel = (pAlias0->flags & 0x780) >> 7;
    if (entchannel <= 10 && ((1 << entchannel) & 0x786)) {
        /* OK - not 3D */
    } else if (!g_snd.listeners[0].active) {
        Com_Error(1, "attempted to play spatialized alias '%s' while there is no active listener\n", pAlias0->pszAliasName);
    }

    if (treatAsMaster || (pAlias0->flags & 2)) {
        return SND_StartAliasStreamOnChannel(pAlias0, pAlias1, lerp, entnum, org, volume, pitch, timeshift, fraction, pAlias0->startDelay, 1, channel, system);
    }

    return SND_StartAliasStreamOnChannel(pAlias0, pAlias1, lerp, entnum, org, volume, pitch, timeshift, fraction, pAlias0->startDelay, 0, channel, system);

no_channel:
    channel = -1;
    goto after_scan;
}

/* line 2082 */
/* line 2082 */
static __attribute_regparm__(2)
void SND_SaveChanInfo(snd_channel_info_t *chaninfo, MemoryFile *memFile)
{
    short value_s;
    unsigned char value_b;
    int value_i;
    float value_f;

    /* Save entnum as short */
    value_s = (short)chaninfo->entnum;
    MemFile_WriteData(memFile, 2, &value_s);

    /* Save entchannel as byte */
    value_b = (unsigned char)chaninfo->entchannel;
    MemFile_WriteData(memFile, 1, &value_b);

    /* Save master as byte */
    value_b = chaninfo->master;
    MemFile_WriteData(memFile, 1, &value_b);

    /* Save startDelay */
    value_i = chaninfo->startDelay;
    MemFile_WriteData(memFile, 4, &value_i);

    /* Save basevolume */
    value_f = chaninfo->basevolume;
    MemFile_WriteData(memFile, 4, &value_f);

    /* Save lerp */
    value_f = chaninfo->lerp;
    MemFile_WriteData(memFile, 4, &value_f);

    /* Save offset vector (3 floats) */
    MemFile_WriteData(memFile, 4, &chaninfo->offset[0]);
    MemFile_WriteData(memFile, 4, &chaninfo->offset[1]);
    MemFile_WriteData(memFile, 4, &chaninfo->offset[2]);
}

/* line 1972 */
void SND_Init(void)
{
    int i;

    Com_Printf("------- Sound Initialization -------\n");

    snd_errorOnMissing = Dvar_RegisterBool("snd_errorOnMissing", 0, 0x1001);
    snd_khz = Dvar_RegisterInt("snd_khz", 44, 11, 44, 0x1021);
    snd_bits = Dvar_RegisterInt("snd_bits", 16, 8, 16, 0x1021);
    snd_stereo = Dvar_RegisterBool("snd_stereo", 1, 0x1021);
    snd_volume = Dvar_RegisterFloat("snd_volume", 1.0f, 0.0f, 1.0f, 0x1001);
    snd_slaveFadeTime = Dvar_RegisterInt("snd_slaveFadeTime", 500, 0, 5000, 0x1081);
    snd_enable2D = Dvar_RegisterBool("snd_enable2D", 1, 0x1080);
    snd_enable3D = Dvar_RegisterBool("snd_enable3D", 1, 0x1080);
    snd_enableStream = Dvar_RegisterBool("snd_enableStream", 1, 0x1080);
    snd_enableReverb = Dvar_RegisterBool("snd_enableReverb", 1, 0x1080);
    snd_touchStreamFilesOnLoad = Dvar_RegisterBool("snd_touchStreamFilesOnLoad", 0, 0x1001);

    /* Initialize default environment effect */
    g_snd.effect = &g_snd.envEffects[0];
    g_snd.envEffects[0].roomtype = 0;
    g_snd.envEffects[0].drylevel = 1.0f;
    g_snd.envEffects[0].drygoal = 1.0f;
    g_snd.envEffects[0].dryrate = 0.0f;
    g_snd.envEffects[0].wetlevel = 0.0f;
    g_snd.envEffects[0].wetgoal = 0.0f;
    g_snd.envEffects[0].wetrate = 0.0f;
    g_snd.envEffects[0].active = 1;

    if (!SND_InitDriver())
        return;

    /* Initialize master volume */
    g_snd.mastervol.volume = 1.0f;
    g_snd.mastervol.goalvolume = 1.0f;
    g_snd.mastervol.goalrate = 0.0f;

    /* Initialize default channel volume group */
    g_snd.channelvol = &g_snd.channelVolGroups[0];
    for (i = 0; i < 11; i++) {
        g_snd.channelvol->channelvol[i].volume = 1.0f;
        g_snd.channelvol->channelvol[i].goalvolume = 1.0f;
        g_snd.channelvol->channelvol[i].goalrate = 0.0f;
    }
    g_snd.channelvol->active = 1;

    g_snd.time = Sys_Milliseconds();
    g_snd.looptime = g_snd.time;
    g_snd.slaveLerp = 0.0f;

    /* Set initial volume */
    g_snd.volume = 0.75f * *(float *)((char *)snd_volume + 8);

    /* Initialize default pause settings (all true except index 2) */
    for (i = 0; i < 11; i++) {
        g_snd.defaultPauseSettings[i] = 1;
    }
    g_snd.defaultPauseSettings[2] = 0;

    /* Copy defaults to active pause settings */
    for (i = 0; i < 11; i++) {
        g_snd.pauseSettings[i] = g_snd.defaultPauseSettings[i];
    }

    Cmd_AddCommand("snd_setEnvironmentEffects", SND_SetEnvironmentEffects_f);
    Cmd_AddCommand("snd_deactivateEnvironmentEffects", SND_DeactivateEnvironmentEffects_f);

    Com_Printf("------- Sound Initialized -------\n");

    Voice_Init();
}

/* line 822 */
static __attribute__((regparm(3), sseregparm))
int SND_PlaySoundAlias_Internal(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, int *pChannel, int timeshift, int treatAsMaster, snd_alias_system_t system)
{
    const snd_alias_t *secondaryAlias;
    int channelType;
    int playType;
    int i;
    int rate;
    int master;
    float fPitchMin;
    float fPitchMax;
    float volMin;
    float volMax;
    float pitch;
    float volume;
    float oneMinusLerp;
    float fDistMax;

    if (!g_snd.Initialized2d)
        return 0;

    if (pChannel)
        *pChannel = -1;

    /* Handle secondary alias */
    if (pAlias0->pszSecondaryAliasName) {
        secondaryAlias = Com_PickSoundAlias(pAlias0->pszSecondaryAliasName);
        if (secondaryAlias) {
            if (!secondaryAlias->pszSecondaryAliasName) {
                SND_PlaySoundAlias_Internal(secondaryAlias, secondaryAlias, lerp, entnum, org, NULL, timeshift, treatAsMaster, system);
            } else {
                Com_Printf("^1Error: a secondaryAlias cannot have a secondary Alias of its own.\nAlias sequence: '%s'->'%s'->'%s'\n",
                    pAlias0->pszAliasName, pAlias0->pszSecondaryAliasName, secondaryAlias->pszSecondaryAliasName);
            }
        }
    }

    /* Extract channel type */
    channelType = (pAlias0->flags & 0x780) >> 7;

    /* Distance check for spatialized sounds */
    if (channelType > 10 || !((1 << channelType) & 0x786)) {
        fDistMax = (1.0f - lerp) * pAlias0->fDistMax + lerp * pAlias1->fDistMax;
        if (Vec3DistanceSq(org, g_snd.listeners[0].orient.origin) > fDistMax * fDistMax)
            return 0;
    }

    /* Scan existing 3D channels for matching looping sound */
    for (i = 0; i < g_snd.max_3D_channels; i++) {
        if (g_snd.chaninfo[i].entnum != entnum)
            continue;
        if (SND_Is3DChannelFree(i))
            continue;
        if (!(g_snd.chaninfo[i].pAlias0->flags & 1))
            continue;
        if (g_snd.chaninfo[i].pAlias0->pszAliasName != pAlias0->pszAliasName)
            continue;
        if (g_snd.chaninfo[i].pAlias1->pszAliasName != pAlias1->pszAliasName)
            continue;

        /* Update existing 3D channel */
        g_snd.chaninfo[i].basevolume = (1.0f - lerp) * pAlias0->fVolMin + lerp * pAlias1->fVolMin;
        rate = (int)floorf((float)g_snd.chaninfo[i].baserate * g_snd.chaninfo[i].pitch * g_snd.timescale + 0.5f);
        SND_Set3DChannelPlaybackRate(i, rate);
        SND_Set3DPosition(i, org);
        g_snd.chaninfo[i].looptime = g_snd.looptime;
        g_snd.chaninfo[i].lerp = lerp;
        if (pChannel)
            *pChannel = i;
        return 0;
    }

    /* Scan existing 2D channels for matching looping sound */
    for (i = 45; i < 45 + g_snd.max_2D_channels; i++) {
        if (g_snd.chaninfo[i].entnum != entnum)
            continue;
        if (SND_Is2DChannelFree(i))
            continue;
        if (!(g_snd.chaninfo[i].pAlias0->flags & 1))
            continue;
        if (g_snd.chaninfo[i].pAlias0->pszAliasName != pAlias0->pszAliasName)
            continue;
        if (g_snd.chaninfo[i].pAlias1->pszAliasName != pAlias1->pszAliasName)
            continue;

        /* Update existing 2D channel */
        g_snd.chaninfo[i].basevolume = (1.0f - lerp) * pAlias0->fVolMin + lerp * pAlias1->fVolMin;
        rate = (int)floorf((float)g_snd.chaninfo[i].baserate * g_snd.chaninfo[i].pitch * g_snd.timescale + 0.5f);
        SND_Set2DChannelPlaybackRate(i, rate);
        g_snd.chaninfo[i].looptime = g_snd.looptime;
        g_snd.chaninfo[i].lerp = lerp;
        if (pChannel)
            *pChannel = i;
        return 0;
    }

    /* Scan existing stream channels for matching looping sound */
    for (i = 32; i < 32 + g_snd.max_stream_channels; i++) {
        if (g_snd.chaninfo[i].entnum != entnum)
            continue;
        if (SND_IsStreamChannelFree(i))
            continue;
        if (!(g_snd.chaninfo[i].pAlias0->flags & 1))
            continue;
        if (g_snd.chaninfo[i].pAlias0->pszAliasName != pAlias0->pszAliasName)
            continue;
        if (g_snd.chaninfo[i].pAlias1->pszAliasName != pAlias1->pszAliasName)
            continue;

        /* Update existing stream channel */
        g_snd.chaninfo[i].basevolume = (1.0f - lerp) * pAlias0->fVolMin + lerp * pAlias1->fVolMin;
        rate = (int)floorf((float)g_snd.chaninfo[i].baserate * g_snd.chaninfo[i].pitch * g_snd.timescale + 0.5f);
        SND_SetStreamChannelPlaybackRate(i, rate);
        g_snd.chaninfo[i].org[0] = org[0];
        g_snd.chaninfo[i].org[1] = org[1];
        g_snd.chaninfo[i].org[2] = org[2];
        g_snd.chaninfo[i].looptime = g_snd.looptime;
        g_snd.chaninfo[i].lerp = lerp;
        if (pChannel)
            *pChannel = i;
        return 0;
    }

    /* Stop conflicting channels for higher channel types without secondary */
    channelType = (pAlias0->flags & 0x780) >> 7;
    if (channelType > 2 && !pAlias0->pszSecondaryAliasName) {
        for (i = 0; i < g_snd.max_3D_channels; i++) {
            if (g_snd.chaninfo[i].entnum != entnum)
                continue;
            if (g_snd.chaninfo[i].entchannel != channelType)
                continue;
            if (!SND_Is3DChannelFree(i))
                SND_Stop3DChannel(i);
        }
        for (i = 32; i < 32 + g_snd.max_stream_channels; i++) {
            if (g_snd.chaninfo[i].entnum != entnum)
                continue;
            if (g_snd.chaninfo[i].entchannel != channelType)
                continue;
            if (!SND_IsStreamChannelFree(i))
                SND_StopStreamChannel(i);
        }
        for (i = 45; i < 45 + g_snd.max_2D_channels; i++) {
            if (g_snd.chaninfo[i].entnum != entnum)
                continue;
            if (g_snd.chaninfo[i].entchannel != channelType)
                continue;
            if (!SND_Is2DChannelFree(i))
                SND_Stop2DChannel(i);
        }
    }

    /* Compute volume and pitch with randomization */
    oneMinusLerp = 1.0f - lerp;
    volMin = oneMinusLerp * pAlias0->fVolMin + lerp * pAlias1->fVolMin;
    volMax = oneMinusLerp * pAlias0->fVolMax + lerp * pAlias1->fVolMax;
    fPitchMin = oneMinusLerp * pAlias0->fPitchMin + lerp * pAlias1->fPitchMin;
    fPitchMax = oneMinusLerp * pAlias0->fPitchMax + lerp * pAlias1->fPitchMax;
    volume = volMin + randomf() * (volMax - volMin);
    pitch = fPitchMin + randomf() * (fPitchMax - fPitchMin);

    /* Determine play type */
    playType = (pAlias0->flags & 0x60) >> 5;
    if (playType == 1) {
        /* Play as sample */
        if (!Com_GetSoundFileMem(pAlias0)) {
            Com_DPrintf("Tried to play sound '%s' from alias '%s', but it was not successfully loaded.\n",
                Com_GetSoundFileName(pAlias0), pAlias0->pszAliasName);
            if (pChannel)
                *pChannel = -1;
            return 0;
        }

        channelType = (pAlias0->flags & 0x780) >> 7;
        if (channelType <= 10 && ((1 << channelType) & 0x786)) {
            /* 2D sample */
            if (!snd_enable2D->current.enabled)
                return 0;
            master = treatAsMaster || (pAlias0->flags & 2);
            return SND_StartAlias2DSample(pAlias0, pAlias1, lerp, entnum, volume, pitch, timeshift, 0.0f, pAlias0->startDelay, master, pChannel, system);
        } else {
            /* 3D sample */
            if (!snd_enable3D->current.enabled)
                return 0;
            if (!g_snd.listeners[0].active) {
                Com_Error(1, "attempted to play spatialized alias '%s' while there is no active listener. Most likely this means you tried to play a spatialized sound while not in a level.\n", pAlias0->pszAliasName);
                return 0;
            }
            master = treatAsMaster || (pAlias0->flags & 2);
            return SND_StartAlias3DSample(pAlias0, pAlias1, lerp, entnum, org, volume, pitch, timeshift, 0.0f, pAlias0->startDelay, master, pChannel, system);
        }
    } else if (playType >= 2 && playType <= 3) {
        /* Play as stream */
        return SND_StartAliasStream(pAlias0, pAlias1, lerp, entnum, org, volume, pitch, timeshift, 0.0f, treatAsMaster, pChannel, system);
    }

    return 0;
}

/* line 1069 */
/* line 1069 */
int SND_PlayLocalSoundAliasByName(const char *aliasname, snd_alias_system_t system)
{
    const snd_alias_t *pAlias;

    if (!aliasname)
        return 0;

    pAlias = Com_PickSoundAlias(aliasname);
    if (!pAlias)
        return 0;

    return SND_PlaySoundAlias_Internal(pAlias, pAlias, 0.0f, g_snd.listeners[0].entnum, g_snd.listeners[0].orient.origin, NULL, 0, 0, system);
}

/* line 1054 */
/* line 1054 */
int SND_PlayLocalSoundAlias(snd_alias_list_t *aliasList, snd_alias_system_t system)
{
    const snd_alias_t *pAlias;

    if (!aliasList)
        return 0;

    pAlias = Com_PickSoundAliasFromList(aliasList);
    if (!pAlias)
        return 0;

    return SND_PlaySoundAlias_Internal(pAlias, pAlias, 0.0f, g_snd.listeners[0].entnum, g_snd.listeners[0].orient.origin, NULL, 0, 0, system);
}

/* line 1043 */
/* line 1043 */
int SND_PlayBlendedSoundAliases(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float fLerp, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system)
{
    if (!pAlias0 || !pAlias1)
        return 0;

    SND_ValidateSoundAliasBlend(pAlias0, pAlias1, 1);
    return SND_PlaySoundAlias_Internal(pAlias0, pAlias1, fLerp, entnum, org, NULL, timeshift, 0, system);
}

/* line 914 */
int SND_PlaySoundAliasAsMaster(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system)
{
    if (!pAlias)
        return 0;
    return SND_PlaySoundAlias_Internal(pAlias, pAlias, 0.0f, entnum, org, NULL, timeshift, 1, system);
}

/* line 897 */
int SND_PlaySoundAlias(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system)
{
    if (!pAlias)
        return 0;
    return SND_PlaySoundAlias_Internal(pAlias, pAlias, 0.0f, entnum, org, NULL, timeshift, 0, system);
}

/* line 441 */
int SND_FindFree2DChannel(int entnum, int entchannel)
{
    int i;
    int best;
    int diff;
    int total;

    /* Phase 1: scan for a free 2D channel */
    for (i = 0; i < g_snd.max_2D_channels; i++) {
        if (SND_Is2DChannelFree(i + 45))
            return i + 45;
    }

    /* Phase 2: find best channel to replace */
    total = g_snd.max_2D_channels + 45;
    best = -1;

    for (i = 45; i < total; i++) {
        if (entchannel < g_snd.chaninfo[i].entchannel)
            continue;

        if (best < 0) {
            best = i;
            continue;
        }

        if (g_snd.chaninfo[i].entnum != g_snd.chaninfo[best].entnum) {
            if (entnum == g_snd.chaninfo[i].entnum) {
                best = i;
                continue;
            }
            if (entnum == g_snd.chaninfo[best].entnum)
                continue;
        }

        if (g_snd.chaninfo[best].entchannel != g_snd.chaninfo[i].entchannel) {
            diff = g_snd.chaninfo[i].entchannel - g_snd.chaninfo[best].entchannel;
        } else if (g_snd.chaninfo[i].endtime != g_snd.chaninfo[best].endtime) {
            diff = g_snd.chaninfo[i].endtime - g_snd.chaninfo[best].endtime;
        } else {
            continue;
        }

        if (diff < 0)
            best = i;
    }

    if (best < 0)
        return -1;

    SND_Stop2DChannel(best);
    return best;
}

/* line 458 */
int SND_FindFree3DChannel(int entnum, int entchannel)
{
    int i;
    int best;
    int diff;

    /* Phase 1: scan for a free 3D channel */
    for (i = 0; i < g_snd.max_3D_channels; i++) {
        if (SND_Is3DChannelFree(i))
            return i;
    }

    /* Phase 2: find best channel to replace */
    if (g_snd.max_3D_channels <= 0)
        return -1;

    best = -1;

    for (i = 0; i < g_snd.max_3D_channels; i++) {
        if (entchannel < g_snd.chaninfo[i].entchannel)
            continue;

        if (best < 0) {
            best = i;
            continue;
        }

        if (g_snd.chaninfo[i].entnum != g_snd.chaninfo[best].entnum) {
            if (entnum == g_snd.chaninfo[i].entnum) {
                best = i;
                continue;
            }
            if (entnum == g_snd.chaninfo[best].entnum)
                continue;
        }

        if (g_snd.chaninfo[best].entchannel != g_snd.chaninfo[i].entchannel) {
            diff = g_snd.chaninfo[i].entchannel - g_snd.chaninfo[best].entchannel;
        } else if (g_snd.chaninfo[i].endtime != g_snd.chaninfo[best].endtime) {
            diff = g_snd.chaninfo[i].endtime - g_snd.chaninfo[best].endtime;
        } else {
            continue;
        }

        if (diff < 0)
            best = i;
    }

    if (best < 0)
        return -1;

    SND_Stop3DChannel(best);
    return best;
}

/* line 2098 */
/* line 2098 */
static __attribute_regparm__(2)
void SND_RestoreChanInfo(snd_channel_info_t *chaninfo, MemoryFile *memFile)
{
    short value_s;
    unsigned char value_b;
    int value_i;

    memset(chaninfo, 0, sizeof(snd_channel_info_t));

    /* Read entnum from short */
    MemFile_ReadData(memFile, 2, &value_s);
    chaninfo->entnum = (int)value_s;

    /* Read entchannel from byte */
    MemFile_ReadData(memFile, 1, &value_b);
    chaninfo->entchannel = (int)value_b;

    /* Read master from byte */
    MemFile_ReadData(memFile, 1, &value_b);
    chaninfo->master = (value_b != 0);

    /* Read startDelay */
    MemFile_ReadData(memFile, 4, &value_i);
    chaninfo->startDelay = value_i;

    /* Read basevolume */
    MemFile_ReadData(memFile, 4, &value_i);
    chaninfo->basevolume = *(float *)&value_i;

    /* Read lerp */
    MemFile_ReadData(memFile, 4, &value_i);
    chaninfo->lerp = *(float *)&value_i;

    /* Read offset vector (3 floats) */
    MemFile_ReadData(memFile, 4, &chaninfo->offset[0]);
    MemFile_ReadData(memFile, 4, &chaninfo->offset[1]);
    MemFile_ReadData(memFile, 4, &chaninfo->offset[2]);
}

/* line 1189 */
static __attribute_regparm__(3)
void SND_StartBackground(int track, const snd_alias_t *pAlias, int fadetime, snd_alias_system_t system)
{
    int channel;
    int entchannel;
    int flags;
    float volume;
    float pitch;
    Bool newPaused;

    /* Check pause state */
    newPaused = (*(int *)((char *)cl_paused + 8) != 0);
    if (newPaused != g_snd.paused) {
        if (newPaused)
            SND_PauseSounds();
        else
            SND_UnpauseSounds();
    }

    /* Validate channel type - must not be 3D */
    flags = pAlias->flags;
    entchannel = (flags & 0x780) >> 7;
    if (entchannel > 10 || !((1 << entchannel) & 0x786)) {
        Com_Error(1, "alias %s sound %s played as an ambient / music track uses a 3D channel\n", pAlias->pszAliasName, Com_GetSoundFileName(pAlias));
        flags = pAlias->flags;
    }

    /* Validate stream type - must be streamed */
    if ((unsigned)((flags & 0x60) >> 5) - 2 > 1) {
        Com_Error(1, "alias %s sound %s played as an ambient / music track is not streamed\n", pAlias->pszAliasName, Com_GetSoundFileName(pAlias));
    }

    /* Compute random volume: fVolMin + randomf() * (fVolMax - fVolMin) */
    volume = pAlias->fVolMin + randomf() * (pAlias->fVolMax - pAlias->fVolMin);

    /* Compute random pitch: fPitchMin + randomf() * (fPitchMax - fPitchMin) */
    pitch = pAlias->fPitchMin + randomf() * (pAlias->fPitchMax - pAlias->fPitchMin);

    /* Get stream channel */
    channel = track + 32;

    /* Stop existing channel if needed */
    if (!SND_IsStreamChannelFree(channel))
        SND_StopStreamChannel(channel);

    /* Set basevolume and background info */
    g_snd.chaninfo[channel].basevolume = volume;
    g_snd.background[track].goalvolume = volume;

    if (fadetime > 0) {
        g_snd.background[track].goalrate = g_snd.chaninfo[channel].basevolume / (float)fadetime;
        g_snd.chaninfo[channel].basevolume = 0.0f;
    } else {
        g_snd.background[track].goalrate = 0.0f;
    }

    /* Start stream */
    if (!*(unsigned char *)((char *)snd_enableStream + 8))
        return;

    SND_StartAliasStreamOnChannel(pAlias, pAlias, 0.0f, 0x400, (vec_t *)&g_snd.listeners[0].orient.origin, g_snd.chaninfo[channel].basevolume, pitch, 0, 0.0f, pAlias->startDelay, (pAlias->flags >> 1) & 1, channel, system);
}

/* line 1277 */
void SND_PlayAmbientAlias(const snd_alias_t *pAlias, int fadetime, snd_alias_system_t system)
{
    int tracknum;
    int curTrack;
    snd_background_info_t *trackptr;
    const snd_alias_t *curAlias;
    int curFlags, newFlags;
    float volume;

    if (!g_snd.Initialized2d)
        return;
    if (!pAlias)
        return;

    curTrack = g_snd.ambient_track;
    tracknum = curTrack + 32;

    if (!SND_IsStreamChannelFree(tracknum)) {
        /* Check if same alias is already playing */
        curAlias = g_snd.chaninfo[tracknum].pAlias0;
        if (curAlias->pszAliasName == pAlias->pszAliasName)
            return;

        /* Check if same sound file with compatible settings */
        if (Com_GetSoundFileName(curAlias) == Com_GetSoundFileName(pAlias)) {
            curFlags = curAlias->flags;
            newFlags = pAlias->flags;
            if ((curFlags & 1) == (newFlags & 1) &&
                curAlias->fPitchMin == pAlias->fPitchMin &&
                curAlias->fPitchMax == pAlias->fPitchMax &&
                (curFlags & 0x780) == (newFlags & 0x780)) {
                /* Compatible - just swap alias and adjust volume */
                g_snd.chaninfo[tracknum].pAlias0 = pAlias;
                g_snd.chaninfo[tracknum].pAlias1 = pAlias;
                volume = pAlias->fVolMin + randomf() * (pAlias->fVolMax - pAlias->fVolMin);
                if (fadetime != 0) {
                    trackptr = &g_snd.background[curTrack];
                    trackptr->goalrate = (volume - trackptr->goalvolume) / (float)fadetime;
                } else {
                    trackptr = &g_snd.background[curTrack];
                    trackptr->goalrate = 0.0f;
                }
                trackptr->goalvolume = volume;
                return;
            }
        }
    }

    /* Need to start on a new track */
    curTrack = g_snd.ambient_track;
    tracknum = curTrack + 32;

    /* Fade out current track if needed */
    if (!SND_IsStreamChannelFree(tracknum)) {
        if (fadetime == 0) {
            SND_StopStreamChannel(tracknum);
        } else if (g_snd.background[curTrack].goalvolume > 0.0f) {
            g_snd.background[curTrack].goalrate = -g_snd.background[curTrack].goalvolume / (float)fadetime;
            g_snd.background[curTrack].goalvolume = 0.0f;
        }
    }

    /* Switch to other track */
    g_snd.ambient_track = 3 - g_snd.ambient_track;
    SND_StartBackground(g_snd.ambient_track, pAlias, fadetime, system);
}

/* line 1256 */
/* line 1256 */
void SND_PlayMusicAlias(const snd_alias_t *pAlias, snd_alias_system_t system)
{
    if (!g_snd.Initialized2d)
        return;
    if (!pAlias)
        return;
    if (!SND_IsStreamChannelFree(32))
        return;

    SND_StartBackground(0, pAlias, 0, system);
}

/* line 1271 */
void SND_StopMusic(int fadetime)
{
    if (SND_IsStreamChannelFree(32))
        return;

    if (fadetime == 0) {
        SND_StopStreamChannel(32);
        return;
    }

    if (g_snd.background[0].goalvolume <= 0.0f)
        return;

    g_snd.background[0].goalrate = -g_snd.background[0].goalvolume / (float)fadetime;
    g_snd.background[0].goalvolume = 0.0f;
}

/* line 1920 */
void SND_StopSounds(snd_stopsounds_arg_t which)
{
    int i;
    int total;

    if (!g_snd.Initialized2d)
        return;

    if (!(which & 8)) {
        /* Stop 2D channels */
        total = g_snd.max_2D_channels + 45;
        for (i = 45; i < total; i++) {
            if (!SND_Is2DChannelFree(i))
                SND_Stop2DChannel(i);
        }

        /* Stop 3D channels */
        for (i = 0; i < g_snd.max_3D_channels; i++) {
            if (!SND_Is3DChannelFree(i))
                SND_Stop3DChannel(i);
        }
    }

    /* Stop stream channels */
    total = g_snd.max_stream_channels + 32;
    for (i = 32; i < total; i++) {
        if (SND_IsStreamChannelFree(i))
            continue;

        if ((which & 4) && (unsigned)(i - 33) <= 1)
            continue;
        if ((which & 2) && i == 32)
            continue;

        SND_StopStreamChannel(i);
    }

    /* Deactivate environment effects for priorities 1 and 2 */
    if (!(which & 1)) {
        for (i = 1; i <= 2; i++) {
            SND_DeactivateEnvironmentEffects(i, 0);
        }
    }

    /* Deactivate channel volumes for priorities 1, 2, and 3 */
    if (!(which & 0x10)) {
        for (i = 1; i <= 3; i++) {
            SND_DeactivateChannelVolumes(i, 0);
        }
    }
}


void SND_ShutdownChannels(void)
{
    SND_StopSounds(0);
    memset(g_snd.chaninfo, 0, sizeof(g_snd.chaninfo));
}

void SND_Shutdown(void)
{
    Voice_Shutdown();
    if (g_snd.restore.buffer) {
        Z_FreeInternal((void *)g_snd.restore.buffer);
    }
    if (!g_snd.Initialized2d) {
        return;
    }
    SND_StopSounds(0);
    Com_UnloadSoundAliases(1);
    Com_UnloadSoundAliases(0);
    SND_ShutdownDriver();
    memset(&g_snd, 0, sizeof(g_snd));
    Cmd_RemoveCommand("snd_setEnvironmentEffects");
    Cmd_RemoveCommand("snd_deactivateEnvironmentEffects");
}

void SND_FadeAllSounds(float volume, int fadetime)
{
    g_snd.mastervol.goalvolume = volume;
    g_snd.mastervol.goalrate = volume - g_snd.mastervol.volume;
    if (fadetime != 0) {
        g_snd.mastervol.goalrate /= (float)fadetime;
    } else if (volume == 0.0f) {
        SND_StopSounds(0);
    }
}

/* line 169 */
void SND_DeactivateEnvironmentEffects_f(void)
{
    const char *priorityStrings[3];
    const char *priorityName;
    int priority;
    int fademsec;
    int i;

    if (Cmd_Argc() != 3) {
        Com_Printf("usage: snd_deactivateenveffects <priority> <fademsec>\n");
        return;
    }

    priorityStrings[0] = "effect";
    priorityStrings[1] = "level";
    priorityStrings[2] = "shellshock";

    priorityName = Cmd_Argv(1);

    priority = -1;
    for (i = 1; i < 3; i++) {
        if (stricmp(priorityName, priorityStrings[i]) == 0) {
            priority = i;
            break;
        }
    }

    if (priority < 0) {
        Com_Printf("invalid priority string '%s', it must be one of the following:\n", priorityName);
        for (i = 1; i < 3; i++) {
            Com_Printf("  %s\n", priorityStrings[i]);
        }
        return;
    }

    fademsec = atoi(Cmd_Argv(2));
    if (fademsec < 0) {
        Com_Printf("invalid 'fademsec' %i, must be greater than or equal to zero\n", fademsec);
        return;
    }

    SND_DeactivateEnvironmentEffects(priority, fademsec);
}

/* line 2434 */
void SND_Save(MemoryFile *memFile)
{
    int i;
    short value;
    char info3D[0x18];
    char info2D[0x10];
    char infoStream[0x20];
    const snd_alias_t *alias;

    /* Save channel volume groups (indices 1,2,3) */
    for (i = 1; i < 4; i++) {
        MemFile_WriteData(memFile, 0x88, &g_snd.channelVolGroups[i]);
    }

    /* Save environment effects (indices 1,2) */
    for (i = 1; i < 3; i++) {
        MemFile_WriteData(memFile, 0x20, &g_snd.envEffects[i]);
    }

    /* Save background info for music track */
    MemFile_WriteData(memFile, 8, &g_snd.background[1]);

    /* Save 3D channel data */
    if (g_snd.Initialized2d && g_snd.max_3D_channels > 0) {
        for (i = 0; i < g_snd.max_3D_channels; i++) {
            if (SND_Is3DChannelFree(i))
                continue;
            if (g_snd.chaninfo[i].system != 1)
                continue;
            if (SND_Get3DChannelLength(i) == 0)
                continue;
            if (SND_Get3DChannelPlaybackRate(i) == 0)
                continue;

            SND_Get3DChannelSaveInfo(i, info3D);

            alias = g_snd.chaninfo[i].pAlias0;
            MemFile_WriteCString(memFile, alias->pszAliasName);
            value = SND_GetAliasOffset(alias);
            MemFile_WriteData(memFile, 2, &value);

            alias = g_snd.chaninfo[i].pAlias1;
            MemFile_WriteCString(memFile, alias->pszAliasName);
            value = SND_GetAliasOffset(alias);
            MemFile_WriteData(memFile, 2, &value);

            SND_SaveChanInfo(&g_snd.chaninfo[i], memFile);
            MemFile_WriteData(memFile, 0x18, info3D);
        }
    }

    /* Write empty string terminator for 3D section */
    MemFile_WriteCString(memFile, "");

    /* Save 2D channel data */
    if (g_snd.Initialized2d && g_snd.max_2D_channels + 45 > 45) {
        for (i = 45; i < g_snd.max_2D_channels + 45; i++) {
            if (SND_Is2DChannelFree(i))
                continue;
            if (g_snd.chaninfo[i].system != 1)
                continue;
            if (SND_Get2DChannelLength(i) == 0)
                continue;
            if (SND_Get2DChannelPlaybackRate(i) == 0)
                continue;

            SND_Get2DChannelSaveInfo(i, info2D);

            alias = g_snd.chaninfo[i].pAlias0;
            MemFile_WriteCString(memFile, alias->pszAliasName);
            value = SND_GetAliasOffset(alias);
            MemFile_WriteData(memFile, 2, &value);

            alias = g_snd.chaninfo[i].pAlias1;
            MemFile_WriteCString(memFile, alias->pszAliasName);
            value = SND_GetAliasOffset(alias);
            MemFile_WriteData(memFile, 2, &value);

            SND_SaveChanInfo(&g_snd.chaninfo[i], memFile);
            MemFile_WriteData(memFile, 0x10, info2D);
        }
    }

    /* Write empty string terminator for 2D section */
    MemFile_WriteCString(memFile, "");

    /* Save stream channel data */
    if (g_snd.Initialized2d && g_snd.max_stream_channels + 32 > 32) {
        for (i = 32; i < g_snd.max_stream_channels + 32; i++) {
            /* Skip ambient tracks (33, 34) */
            if ((unsigned)(i - 33) <= 1)
                continue;

            if (SND_IsStreamChannelFree(i)) {
                MemFile_WriteCString(memFile, "");
                continue;
            }

            if (g_snd.chaninfo[i].system != 1) {
                continue;
            }

            if (SND_GetStreamChannelLength(i) == 0)
                continue;

            SND_GetStreamChannelSaveInfo(i, infoStream);

            alias = g_snd.chaninfo[i].pAlias0;
            MemFile_WriteCString(memFile, alias->pszAliasName);
            value = SND_GetAliasOffset(alias);
            MemFile_WriteData(memFile, 2, &value);

            alias = g_snd.chaninfo[i].pAlias1;
            MemFile_WriteCString(memFile, alias->pszAliasName);
            value = SND_GetAliasOffset(alias);
            MemFile_WriteData(memFile, 2, &value);

            SND_SaveChanInfo(&g_snd.chaninfo[i], memFile);
            MemFile_WriteData(memFile, 0x20, infoStream);
        }
    }

    /* Write empty string terminator for stream section */
    MemFile_WriteCString(memFile, "");
}

/* line 2383 */
static __attribute_regparm__(2)
Bool SND_RestoreStreamChannel(int channel, MemoryFile *memFile)
{
    const char *name;
    short value;
    const snd_alias_t *pAlias0;
    const snd_alias_t *pAlias1;
    snd_channel_info_t chaninfo;
    char info[0x20];
    int rate;

    /* Read pAlias0 */
    name = MemFile_ReadCString(memFile);
    if (*name == '\0')
        return 0;

    MemFile_ReadData(memFile, 2, &value);
    pAlias0 = SND_GetAliasWithOffset(name, (unsigned short)value);
    if (!pAlias0)
        return 0;

    /* Read pAlias1 */
    name = MemFile_ReadCString(memFile);
    if (*name != '\0') {
        MemFile_ReadData(memFile, 2, &value);
        pAlias1 = SND_GetAliasWithOffset(name, (unsigned short)value);
    } else {
        pAlias1 = 0;
    }

    /* Read chaninfo and save info */
    SND_RestoreChanInfo(&chaninfo, memFile);
    MemFile_ReadData(memFile, 0x20, info);

    /* Validate alias type - must be streamed */
    if ((unsigned)((pAlias0->flags & 0x60) >> 5) - 2 > 1)
        return 1;
    if ((unsigned)((pAlias1->flags & 0x60) >> 5) - 2 > 1)
        return 1;

    /* Validate blend compatibility */
    if (!SND_ValidateSoundAliasBlend(pAlias0, pAlias1, 0))
        return 1;

    if (channel < 0) {
        /* Need to find a free stream channel */
        SND_StartAliasStream(pAlias0, pAlias1, chaninfo.lerp, chaninfo.entnum, (const vec_t *)&info[0x14], *(float *)&info[8], 1.0f, 0, *(float *)&info[0], 0, &channel, 1);
    } else {
        /* Use specified channel */
        if (!*(unsigned char *)((char *)snd_enableStream + 8))
            return 1;

        SND_StartAliasStreamOnChannel(pAlias0, pAlias1, chaninfo.lerp, chaninfo.entnum, (const vec_t *)&info[0x14], *(float *)&info[8], 1.0f, 0, *(float *)&info[0], chaninfo.startDelay, chaninfo.master, channel, 1);
    }

    if (channel < 0)
        return 1;

    if (SND_IsStreamChannelFree(channel))
        return 1;

    /* Restore stream channel state */
    SND_SetStreamChannelFromSaveInfo(channel, info);

    /* Set playback rate */
    rate = (int)floorf((float)(*(int *)&info[4]) * g_snd.chaninfo[channel].pitch * g_snd.timescale + 0.5f);
    SND_SetStreamChannelPlaybackRate(channel, rate);

    /* Restore offset */
    g_snd.chaninfo[channel].offset[0] = chaninfo.offset[0];
    g_snd.chaninfo[channel].offset[1] = chaninfo.offset[1];
    g_snd.chaninfo[channel].offset[2] = chaninfo.offset[2];

    return 1;
}


void SND_Restore(MemoryFile *memFile)
{
    int i;
    const char *name;
    short value;
    const snd_alias_t *pAlias0;
    const snd_alias_t *pAlias1;
    snd_channel_info_t chaninfo;
    char info[0x20];
    int channel;

    if (!g_snd.Initialized2d)
        return;

    /* Restore channel volume groups (indices 1,2,3) */
    for (i = 1; i < 4; i++) {
        MemFile_ReadData(memFile, 0x88, &g_snd.channelVolGroups[i]);
    }

    /* Recalculate active channel volume group */
    for (i = 0; i < 4; i++) {
        if (g_snd.channelVolGroups[i].active)
            g_snd.channelvol = &g_snd.channelVolGroups[i];
    }

    /* Restore environment effects (indices 1,2) */
    for (i = 1; i < 3; i++) {
        MemFile_ReadData(memFile, 0x20, &g_snd.envEffects[i]);
    }

    /* Recalculate active env effect */
    for (i = 0; i < 3; i++) {
        if (g_snd.envEffects[i].active)
            g_snd.effect = &g_snd.envEffects[i];
    }

    /* Apply roomtype */
    SND_SetRoomtype(g_snd.effect->roomtype);

    /* Restore background info for music track */
    MemFile_ReadData(memFile, 8, &g_snd.background[1]);

    /* Restore 3D channels */
    for (;;) {
        name = MemFile_ReadCString(memFile);
        if (*name == '\0')
            break;

        MemFile_ReadData(memFile, 2, &value);
        pAlias0 = SND_GetAliasWithOffset(name, (unsigned short)value);
        if (!pAlias0)
            break;

        name = MemFile_ReadCString(memFile);
        if (*name != '\0') {
            MemFile_ReadData(memFile, 2, &value);
            pAlias1 = SND_GetAliasWithOffset(name, (unsigned short)value);
        } else {
            pAlias1 = 0;
        }

        SND_RestoreChanInfo(&chaninfo, memFile);
        MemFile_ReadData(memFile, 0x18, info);

        /* Validate alias is loaded */
        if ((pAlias0->flags & 0x60) != 0x20)
            continue;
        if ((pAlias1->flags & 0x60) != 0x20)
            continue;
        if (!Com_GetSoundFileMem(pAlias0))
            continue;
        if (Com_GetSoundFileMem(pAlias1) != Com_GetSoundFileMem(pAlias0))
            continue;
        if (!SND_ValidateSoundAliasBlend(pAlias0, pAlias1, 0))
            continue;
        if (!*(unsigned char *)((char *)snd_enable3D + 8))
            continue;

        /* Start 3D sample */
        SND_StartAlias3DSample(pAlias0, pAlias1, chaninfo.lerp, chaninfo.entnum, (const vec_t *)&info[0x0C], *(float *)&info[8], *(float *)&info[4], 0, *(float *)&info[0], chaninfo.startDelay, chaninfo.master, &channel, 1);
        if (channel < 0)
            continue;

        /* Copy offset to channel */
        g_snd.chaninfo[channel].offset[0] = chaninfo.offset[0];
        g_snd.chaninfo[channel].offset[1] = chaninfo.offset[1];
        g_snd.chaninfo[channel].offset[2] = chaninfo.offset[2];
    }

    /* Restore 2D channels */
    for (;;) {
        name = MemFile_ReadCString(memFile);
        if (*name == '\0')
            break;

        MemFile_ReadData(memFile, 2, &value);
        pAlias0 = SND_GetAliasWithOffset(name, (unsigned short)value);
        if (!pAlias0)
            goto restore_streams;

        name = MemFile_ReadCString(memFile);
        if (*name != '\0') {
            MemFile_ReadData(memFile, 2, &value);
            pAlias1 = SND_GetAliasWithOffset(name, (unsigned short)value);
        } else {
            pAlias1 = 0;
        }

        SND_RestoreChanInfo(&chaninfo, memFile);
        MemFile_ReadData(memFile, 0x10, info);

        /* Validate alias is loaded */
        if ((pAlias0->flags & 0x60) != 0x20)
            continue;
        if ((pAlias1->flags & 0x60) != 0x20)
            continue;
        if (!Com_GetSoundFileMem(pAlias0))
            continue;
        if (Com_GetSoundFileMem(pAlias1) != Com_GetSoundFileMem(pAlias0))
            continue;
        if (!SND_ValidateSoundAliasBlend(pAlias0, pAlias1, 0))
            continue;
        if (!*(unsigned char *)((char *)snd_enable2D + 8))
            continue;

        /* Start 2D sample */
        SND_StartAlias2DSample(pAlias0, pAlias1, chaninfo.lerp, chaninfo.entnum, *(float *)&info[8], *(float *)&info[4], 0, *(float *)&info[0], chaninfo.startDelay, chaninfo.master, &channel, 1);
        if (channel < 0)
            continue;

        /* Restore from save info */
        SND_Set2DChannelFromSaveInfo(channel, info);

        /* Copy offset to channel */
        g_snd.chaninfo[channel].offset[0] = chaninfo.offset[0];
        g_snd.chaninfo[channel].offset[1] = chaninfo.offset[1];
        g_snd.chaninfo[channel].offset[2] = chaninfo.offset[2];
    }

restore_streams:
    /* Restore stream channel 32 */
    SND_RestoreStreamChannel(32, memFile);

    /* Restore additional stream channels */
    if (!SND_RestoreStreamChannel(-1, memFile))
        return;

    while (SND_RestoreStreamChannel(-1, memFile))
        ;
}

/* line 1873 */
void SND_Update(void)
{
    int cpu;
    int frametime;
    int now;
    float frametime_f;
    float ratio;
    float timescale;
    float newTimescale;
    int i;
    int rate;
    int fadeTime;
    float delta;
    Bool hasMaster;
    Bool newPaused;
    snd_volume_info_t *vi;
    snd_enveffect *eff;
    MemoryFile memFile;

    if (!g_snd.Initialized2d)
        return;

    /* Get CPU usage */
    cpu = SND_GetDriverCPUPercentage();
    g_snd.cpu = cpu;

    /* Performance warning check */
    if (*(unsigned char *)((char *)com_statmon + 8) && cpu > 2)
        StatMon_Warning(2, 3000, "gfx/2d/warning@soundcpu.jpg");

    /* Frame timing */
    now = Sys_Milliseconds();
    frametime = now - g_snd.time;
    g_snd.time = now;
    SND_DriverPreUpdate(frametime);

    /* Check pause state change */
    newPaused = (*(int *)((char *)cl_paused + 8) != 0);
    if (newPaused != g_snd.paused) {
        if (newPaused)
            SND_PauseSounds();
        else
            SND_UnpauseSounds();
    }

    frametime_f = (float)frametime;

    /* Update active channel volume group */
    for (i = 0; i < 11; i++) {
        vi = &g_snd.channelvol->channelvol[i];
        vi->volume += frametime_f * vi->goalrate;
        if (vi->goalrate >= 0.0f) {
            if (vi->volume > vi->goalvolume) {
                vi->volume = vi->goalvolume;
                vi->goalrate = 0.0f;
            }
        } else {
            if (vi->goalvolume > vi->volume) {
                vi->volume = vi->goalvolume;
                vi->goalrate = 0.0f;
            }
        }
    }

    /* Update master volume */
    if (g_snd.mastervol.goalrate != 0.0f) {
        g_snd.mastervol.volume += frametime_f * g_snd.mastervol.goalrate;
        if (g_snd.mastervol.goalrate >= 0.0f) {
            if (g_snd.mastervol.volume > g_snd.mastervol.goalvolume) {
                g_snd.mastervol.volume = g_snd.mastervol.goalvolume;
                g_snd.mastervol.goalrate = 0.0f;
            }
        } else {
            if (g_snd.mastervol.goalvolume > g_snd.mastervol.volume) {
                g_snd.mastervol.volume = g_snd.mastervol.goalvolume;
                g_snd.mastervol.goalrate = 0.0f;
            }
        }
        /* Check for complete silence */
        if (g_snd.mastervol.volume == 0.0f && g_snd.mastervol.goalrate == 0.0f)
            SND_StopSounds(0);
        /* Recalculate global volume */
        Dvar_ClearModified(snd_volume);
        g_snd.volume = g_snd.mastervol.volume * *(float *)((char *)snd_volume + 8) * 0.75f;
    } else if (*(unsigned char *)((char *)snd_volume + 7)) {
        /* snd_volume dvar was modified */
        Dvar_ClearModified(snd_volume);
        g_snd.volume = g_snd.mastervol.volume * *(float *)((char *)snd_volume + 8) * 0.75f;
    }

    /* If paused, skip game logic updates */
    if (!g_snd.paused) {
        /* Restore saved sound state if available */
        if (g_snd.restore.buffer) {
            MemFile_InitForReading(&memFile, g_snd.restore.size, g_snd.restore.buffer);
            SND_Restore(&memFile);
            Z_FreeInternal((void *)g_snd.restore.buffer);
            g_snd.restore.buffer = 0;
            *(int *)((char *)&g_snd + 0x20) = 0;
        }

        /* Update timescale */
        timescale = Com_GetTimescaleForSnd();
        newTimescale = (timescale > 0.0f) ? timescale : 1.0f;
        if (newTimescale != g_snd.timescale) {
            ratio = newTimescale / g_snd.timescale;
            g_snd.timescale = newTimescale;

            /* Adjust 3D channel playback rates */
            for (i = 0; i < g_snd.max_3D_channels; i++) {
                if (SND_Is3DChannelFree(i))
                    continue;
                rate = SND_Get3DChannelPlaybackRate(i);
                SND_Set3DChannelPlaybackRate(i, (int)floorf((float)rate * ratio + 0.5f));
            }

            /* Adjust stream channel playback rates */
            for (i = 32; i < 32 + g_snd.max_stream_channels; i++) {
                if (SND_IsStreamChannelFree(i))
                    continue;
                rate = SND_GetStreamChannelPlaybackRate(i);
                SND_SetStreamChannelPlaybackRate(i, (int)floorf((float)rate * ratio + 0.5f));
            }

            /* Adjust 2D channel playback rates */
            for (i = 45; i < 45 + g_snd.max_2D_channels; i++) {
                if (SND_Is2DChannelFree(i))
                    continue;
                rate = SND_Get2DChannelPlaybackRate(i);
                SND_Set2DChannelPlaybackRate(i, (int)floorf((float)rate * ratio + 0.5f));
            }
        }

        /* Update environment effects */
        eff = g_snd.effect;
        if (eff->dryrate != 0.0f) {
            eff->drylevel += frametime_f * eff->dryrate;
            if (eff->dryrate < 0.0f) {
                if (eff->drygoal >= eff->drylevel) {
                    eff->drylevel = eff->drygoal;
                    eff->dryrate = 0.0f;
                }
            } else {
                if (eff->drylevel >= eff->drygoal) {
                    eff->drylevel = eff->drygoal;
                    eff->dryrate = 0.0f;
                }
            }
        }
        if (eff->wetrate != 0.0f) {
            eff->wetlevel += frametime_f * eff->wetrate;
            if (eff->wetrate < 0.0f) {
                if (eff->wetgoal >= eff->wetlevel) {
                    eff->wetlevel = eff->wetgoal;
                    eff->wetrate = 0.0f;
                }
            } else {
                if (eff->wetlevel >= eff->wetgoal) {
                    eff->wetlevel = eff->wetgoal;
                    eff->wetrate = 0.0f;
                }
            }
        }
        SND_UpdateReverbs();
    }

    /* Check for slave channels (master-present tracking) */
    hasMaster = 0;
    for (i = 0; i < g_snd.max_3D_channels && !hasMaster; i++) {
        if (!SND_Is3DChannelFree(i) && g_snd.chaninfo[i].startDelay == 0 && g_snd.chaninfo[i].master)
            hasMaster = 1;
    }
    if (!hasMaster) {
        for (i = 32; i < 32 + g_snd.max_stream_channels && !hasMaster; i++) {
            if (!SND_IsStreamChannelFree(i) && g_snd.chaninfo[i].startDelay == 0 && g_snd.chaninfo[i].master)
                hasMaster = 1;
        }
    }
    if (!hasMaster) {
        for (i = 45; i < 45 + g_snd.max_2D_channels && !hasMaster; i++) {
            if (!SND_Is2DChannelFree(i) && g_snd.chaninfo[i].startDelay == 0 && g_snd.chaninfo[i].master)
                hasMaster = 1;
        }
    }

    /* Update slave lerp */
    fadeTime = *(int *)((char *)snd_slaveFadeTime + 8);
    if (fadeTime == 0) {
        g_snd.slaveLerp = hasMaster ? 1.0f : 0.0f;
    } else {
        delta = frametime_f / (float)fadeTime;
        if (hasMaster)
            g_snd.slaveLerp += delta;
        else
            g_snd.slaveLerp -= delta;
        if (g_snd.slaveLerp > 1.0f) g_snd.slaveLerp = 1.0f;
        if (g_snd.slaveLerp < 0.0f) g_snd.slaveLerp = 0.0f;
    }

    /* Update active 3D channels */
    for (i = 0; i < g_snd.max_3D_channels; i++) {
        if (!SND_Is3DChannelFree(i))
            SND_Update3DChannel(i, frametime);
    }

    /* Update active stream channels */
    for (i = 32; i < 32 + g_snd.max_stream_channels; i++) {
        if (!SND_IsStreamChannelFree(i))
            SND_UpdateStreamChannel(i, frametime);
    }

    /* Update active 2D channels */
    for (i = 45; i < 45 + g_snd.max_2D_channels; i++) {
        if (!SND_Is2DChannelFree(i))
            SND_Update2DChannel(i, frametime);
    }

    SND_DriverPostUpdate(frametime);
}

