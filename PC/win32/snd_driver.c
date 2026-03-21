/* ASM dump from: snd_driver.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/snd_driver.cpp */

#include "common_types.h"
#include "imports.h"

extern float floorf(float x);

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern void FS_FCloseFile(int f);
extern int FS_FOpenFileReadStream(const char *filename, long unsigned int *handle, int uniqueFILE);
extern int FS_Seek(int f, long int offset, int origin);
extern int FS_FTell(int f);
extern int FS_Read(void *buffer, int len, int f);
extern int FS_ReadFile(const char *qpath, void **buffer);
extern void FS_FreeFile(void *buffer);
extern const char *FS_ShortOSFilePath(const char *name);
extern int AIL_digital_CPU_percent(void *dig);
extern int AIL_sample_playback_rate(void *S);
extern void AIL_set_sample_playback_rate(void *S, int rate);
extern int AIL_3D_sample_playback_rate(void *S);
extern void AIL_set_3D_sample_playback_rate(void *S, int rate);
extern int AIL_stream_playback_rate(void *stream);
extern void AIL_set_stream_playback_rate(void *stream, int rate);
extern float AIL_3D_sample_volume(void *S);
extern int AIL_3D_sample_length(void *S);
extern void AIL_end_sample(void *S);
extern void AIL_stop_sample(void *S);
extern void AIL_resume_sample(void *S);
extern long unsigned int AIL_sample_status(void *S);
extern void AIL_end_3D_sample(void *S);
extern void AIL_stop_3D_sample(void *S);
extern void AIL_resume_3D_sample(void *S);
extern long unsigned int AIL_3D_sample_status(void *S);
extern void AIL_close_stream(void *stream);
extern void AIL_pause_stream(void *stream, long int onoff);
extern long int AIL_stream_status(void *stream);
extern void AIL_sample_volume_levels(void *S, float *left_level, float *right_level);
extern void AIL_stream_volume_levels(void *S, float *left_level, float *right_level);
extern void AIL_sample_ms_position(void *S, long int *total_milliseconds, long int *current_milliseconds);
extern void AIL_stream_ms_position(void *S, long int *total_milliseconds, long int *current_milliseconds);
extern void AIL_close_3D_provider(void *lib);
extern void AIL_shutdown(void);
extern void AIL_set_stream_reverb_levels(void *S, float dry_level, float wet_level);
extern void AIL_sample_volume_pan(void *S, float *volume, float *pan);
extern void AIL_stream_volume_pan(void *S, float *volume, float *pan);
extern long unsigned int AIL_3D_sample_offset(void *S);
extern void AIL_3D_position(void *obj, float *X, float *Y, float *Z);
extern Bool SND_IsAliasChannel3D(int channel);
extern void AIL_release_sample_handle(void *S);
extern void *AIL_allocate_sample_handle(void *dig);
extern void *AIL_allocate_3D_sample_handle(void *provider);
extern void AIL_init_sample(void *S);
extern void AIL_set_sample_type(void *S, int format, int flags);
extern void AIL_set_sample_volume_levels(void *S, float left, float right);
extern void AIL_set_stream_volume_levels(void *S, float left, float right);
extern int AIL_minimum_sample_buffer_size(void *dig, int rate, int format);
extern void AIL_set_sample_address(void *S, void *ptr, int len);
extern void AIL_set_sample_adpcm_block_size(void *S, int blocksize);
extern void AIL_set_sample_loop_count(void *S, int count);
extern void AIL_set_sample_reverb_levels(void *S, float dry_level, float wet_level);
extern void AIL_set_sample_ms_position(void *S, int ms);
extern long unsigned int AIL_sample_position(void *S);
extern void AIL_set_3D_sample_volume(void *S, float volume);
extern void AIL_set_3D_sample_distances(void *S, float min_dist, float max_dist);
extern void AIL_set_3D_sample_loop_count(void *S, int count);
extern void AIL_set_3D_sample_effects_level(void *S, float level);
extern void AIL_set_3D_sample_info(void *S, void *info);
extern void AIL_set_3D_sample_offset(void *S, int offset);
extern void AIL_set_3D_position(void *S, float x, float y, float z);
extern void AIL_set_3D_stream_position(void *S, float x, float y, float z);
extern int AIL_is_3D_stream(void *stream);
extern void AIL_set_stream_loop_count(void *S, int count);
extern void AIL_set_stream_ms_position(void *S, int ms);
extern void *AIL_open_stream(void *dig, const char *filename, int flags);
extern void AIL_stream_info(void *stream, int *a, int *b, int *c, int *d);
extern int AIL_sample_buffer_ready(void *S);
extern void AIL_load_sample_buffer(void *S, int buf_num, void *buffer, int size);
extern int AIL_WAV_info(void *data, void *info);
extern int AIL_size_processed_digital_audio(int rate, int format, int num, void *info);
extern void AIL_process_digital_audio(void *dest, int size, int rate, int format, int num, void *info);
extern void AIL_set_digital_master_room_type(void *dig, int room_type);
extern void AIL_set_digital_master_reverb_levels(void *dig, float dry, float wet);
extern void AIL_set_3D_room_type(void *provider, int room_type);
extern int AIL_startup(int flags);
extern void AIL_set_redist_directory(const char *dir);
extern void *AIL_open_digital_driver(int freq, int bits, int channels, int flags);
extern int AIL_set_preference(int pref, int value);
extern int AIL_enumerate_3D_providers(void *provider, void **handle, const char **name);
extern int AIL_open_3D_provider(void *handle);
extern void AIL_3D_provider_attribute(void *provider, const char *name, void *val);
extern void AIL_set_3D_distance_factor(void *provider, float factor);
extern void AIL_set_3D_rolloff_factor(void *provider, float factor);
extern void AIL_set_file_callbacks(void *open_cb, void *close_cb, void *seek_cb, void *read_cb);
extern const char *AIL_last_error(void);
extern void *Z_MallocInternal(int size);
extern void Z_FreeInternal(void *ptr);
extern void *Hunk_AllocNoZeroInternal(int size);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void Com_DPrintf(const char *fmt, ...);
extern void Com_Memcpy(void *dst, const void *src, int size);
extern void *Com_GetSoundFileMem(const void *alias);
extern const char *Com_GetSoundFileName(const void *alias);
extern void SND_Update(void);
extern Bool SND_UpdateBackgroundVolume(int streamIdx, int frametime);
extern float SND_Attenuate(void *curve, float dist, float min, float max);
extern float SND_GetLerpedSlavePercentage(void *slave);
extern int SND_GetListenerIndexNearestToOrigin(const float *org);
extern void SND_GetCurrent3DPosition(int entnum, float *prevOrg, float *org);
extern float Vec3Normalize(float *v);
extern float Vec3Distance(const float *a, const float *b);
extern int SND_FindFree2DChannel(int entnum, int channel);
extern int SND_FindFree3DChannel(int entnum, int channel);
extern void SND_SetChannelInfo(int index, int entnum, const void *pAlias0, const void *pAlias1, float lerp, const float *org, float volume, float pitch, int channels, int rate, int total_msec, int start_msec, int startDelay, int master, int system);
extern const dvar_t *Dvar_RegisterBool(const char *name, int value, int flags);
extern const dvar_t *Dvar_RegisterString(const char *name, const char *value, int flags);
extern void Dvar_SetString(const dvar_t *dvar, const char *value);
extern int Dvar_GetInt(const char *name);
extern int stricmp(const char *a, const char *b);

extern const dvar_t *mss_3d_provider; /* 0x0 */
extern const dvar_t *mss_q3fs; /* 0x0 */
static struct MssLocal milesGlob; /* milesGlob */

static long unsigned int MSS_FileOpenCallback(const char *pszFilename, long unsigned int *phFileHandle);
static void MSS_FileCloseCallback(long unsigned int hFileHandle);
static long int MSS_FileSeekCallback(long unsigned int hFileHandle, long int offset, long unsigned int type);
static long unsigned int MSS_FileReadCallback(long unsigned int hFileHandle, void *pBuffer, long unsigned int bytes);
void SND_ShutdownDriver(void);
int SND_GetDriverCPUPercentage(void);
void SND_Stop2DChannel(int index);
void SND_Pause2DChannel(int index);
void SND_Unpause2DChannel(int index, int timeshift);
Bool SND_Is2DChannelFree(int index);
void SND_Stop3DChannel(int index);
void SND_Pause3DChannel(int index);
void SND_Unpause3DChannel(int index, int timeshift);
Bool SND_Is3DChannelFree(int index);
void SND_StopStreamChannel(int index);
void SND_PauseStreamChannel(int index);
void SND_UnpauseStreamChannel(int index, int timeshift);
Bool SND_IsStreamChannelFree(int index);
float SND_Get2DChannelVolume(int index);
float SND_Get3DChannelVolume(int index);
float SND_GetStreamChannelVolume(int index);
int SND_Get2DChannelPlaybackRate(int index);
void SND_Set2DChannelPlaybackRate(int index, int rate);
int SND_Get3DChannelPlaybackRate(int index);
void SND_Set3DChannelPlaybackRate(int index, int rate);
int SND_GetStreamChannelPlaybackRate(int index);
void SND_SetStreamChannelPlaybackRate(int index, int rate);
void SND_UpdateStreamChannelReverb(int index);
int SND_Get2DChannelLength(int index);
int SND_Get3DChannelLength(int index);
int SND_GetStreamChannelLength(int index);
void SND_Get2DChannelSaveInfo(int index, snd_save_2D_sample_t *info);
void SND_Get3DChannelSaveInfo(int index, snd_save_3D_sample_t *info);
void SND_GetStreamChannelSaveInfo(int index, snd_save_stream_t *info);
void SND_EndRawSamples(void);
int SND_RawSamplesTime(void);
void SND_RawSamples(int samples, int rate, int width, int s_channels, const byte *data);
int SND_GetSoundFileSize(const void *pSoundFile);
void SND_DriverPreUpdate(int frametime);
void SND_SetRoomtype(int roomtype);
void SND_Update2DChannelReverb(int index);
void SND_Update3DChannelReverb(int index);
void SND_Set3DPosition(int index, const vec_t *org);
static void MSS_SpatializeStream(float *volume, float *pan);
static void MSS_SpatializeStreamImpl(int i, float *volume, float *pan);
void SND_UpdateStreamChannel(int i, int frametime);
void SND_Update2DChannel(int i, int frametime);
void SND_LoadSoundFile(SoundFile *soundFile);
int SND_StartAlias2DSample(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int *pChannel, snd_alias_system_t system);
int SND_StartAlias3DSample(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int *pChannel, snd_alias_system_t system);
int SND_StartAliasStreamOnChannel(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int index, snd_alias_system_t system);
void SND_Update3DChannel(int i, int frametime);
void SND_Set2DChannelFromSaveInfo(int index, snd_save_2D_sample_t *info);
Bool SND_InitDriver(void);
void SND_SetStreamChannelFromSaveInfo(int index, snd_save_stream_t *info);
void SND_DriverPostUpdate(int frametime);

/* line 114 */
static long unsigned int MSS_FileOpenCallback(const char *pszFilename, long unsigned int *phFileHandle)
{
    return FS_FOpenFileReadStream(pszFilename, phFileHandle, 1) >= 0;
}

/* line 125 */
static void MSS_FileCloseCallback(long unsigned int hFileHandle)
{
    FS_FCloseFile((int)hFileHandle);
}

/* line 131 */
static long int MSS_FileSeekCallback(long unsigned int hFileHandle, long int offset, long unsigned int type)
{
    switch (type) {
        case 0:
            FS_Seek((int)hFileHandle, offset, 2);
            return FS_FTell((int)hFileHandle);
        case 1:
            FS_Seek((int)hFileHandle, offset, 0);
            return FS_FTell((int)hFileHandle);
        case 2:
            FS_Seek((int)hFileHandle, offset, 1);
            return FS_FTell((int)hFileHandle);
        default:
            return 0;
    }
}

/* line 157 */
static long unsigned int MSS_FileReadCallback(long unsigned int hFileHandle, void *pBuffer, long unsigned int bytes)
{
    return FS_Read(pBuffer, (int)bytes, (int)hFileHandle);
}

/* line 469 */
void SND_ShutdownDriver(void)
{
    AIL_close_3D_provider(milesGlob.provider_3D);
    AIL_shutdown();
    memset(&milesGlob, 0, sizeof(MssLocal));
}

/* line 479 */
int SND_GetDriverCPUPercentage(void)
{
    return AIL_digital_CPU_percent(milesGlob.driver_2D);
}

/* line 549 */
void SND_Stop2DChannel(int index)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    AIL_end_sample(milesGlob.handle_2D[index]);
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    chaninfo->paused = 0;
    chaninfo->startDelay = 0;
}

/* line 558 */
void SND_Pause2DChannel(int index)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    AIL_stop_sample(milesGlob.handle_2D[index]);
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    chaninfo->paused = 1;
}

/* line 566 */
void SND_Unpause2DChannel(int index, int timeshift)
{
    snd_local_t *sndGlob = *(snd_local_t **)imp_g_snd;
    snd_channel_info_t *chaninfo = &sndGlob->chaninfo[index];
    if (chaninfo->startDelay == 0) {
        AIL_resume_sample(milesGlob.handle_2D[index]);
    }
    chaninfo->endtime += timeshift;
    chaninfo->paused = 0;
}

/* line 576 */
Bool SND_Is2DChannelFree(int index)
{
    snd_local_t *sndGlob = *(snd_local_t **)imp_g_snd;
    snd_channel_info_t *chaninfo = &sndGlob->chaninfo[index];
    if (chaninfo->paused != 0) {
        return 0;
    }
    if (chaninfo->startDelay != 0) {
        return 0;
    }
    if (chaninfo->pAlias0 == NULL && chaninfo->pAlias1 == NULL) {
        return 1;
    }
    return AIL_sample_status(milesGlob.handle_2D[index]) == 2;
}

/* line 586 */
void SND_Stop3DChannel(int index)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    AIL_end_3D_sample(milesGlob.handle_3D[index]);
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    chaninfo->paused = 0;
    chaninfo->startDelay = 0;
}

/* line 595 */
void SND_Pause3DChannel(int index)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    AIL_stop_3D_sample(milesGlob.handle_3D[index]);
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    chaninfo->paused = 1;
}

/* line 603 */
void SND_Unpause3DChannel(int index, int timeshift)
{
    snd_local_t *sndGlob = *(snd_local_t **)imp_g_snd;
    snd_channel_info_t *chaninfo = &sndGlob->chaninfo[index];
    if (chaninfo->startDelay == 0) {
        AIL_resume_3D_sample(milesGlob.handle_3D[index]);
    }
    chaninfo->endtime += timeshift;
    chaninfo->paused = 0;
}

/* line 613 */
Bool SND_Is3DChannelFree(int index)
{
    snd_local_t *sndGlob = *(snd_local_t **)imp_g_snd;
    snd_channel_info_t *chaninfo = &sndGlob->chaninfo[index];
    if (chaninfo->paused != 0) {
        return 0;
    }
    if (chaninfo->startDelay != 0) {
        return 0;
    }
    if (chaninfo->pAlias0 == NULL && chaninfo->pAlias1 == NULL) {
        return 1;
    }
    return AIL_3D_sample_status(milesGlob.handle_3D[index]) == 2;
}

/* line 623 */
void SND_StopStreamChannel(int index)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    int streamIdx = index - 0x20;
    AIL_close_stream(milesGlob.handle_stream[streamIdx]);
    milesGlob.handle_stream[streamIdx] = NULL;
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    chaninfo->paused = 0;
    chaninfo->startDelay = 0;
}

/* line 635 */
void SND_PauseStreamChannel(int index)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    AIL_pause_stream(milesGlob.handle_stream[index - 0x20], 1);
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    chaninfo->paused = 1;
}

/* line 643 */
void SND_UnpauseStreamChannel(int index, int timeshift)
{
    snd_local_t *sndGlob = *(snd_local_t **)imp_g_snd;
    snd_channel_info_t *chaninfo = &sndGlob->chaninfo[index];
    if (chaninfo->startDelay == 0) {
        AIL_pause_stream(milesGlob.handle_stream[index - 0x20], 0);
    }
    chaninfo->endtime += timeshift;
    chaninfo->paused = 0;
}

/* line 653 */
Bool SND_IsStreamChannelFree(int index)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    void *streamHandle;
    int streamIdx = index - 0x20;
    streamHandle = milesGlob.handle_stream[streamIdx];
    if (streamHandle == NULL) {
        return 1;
    }
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    if (chaninfo->paused != 0) {
        return 0;
    }
    if (chaninfo->startDelay != 0) {
        return 0;
    }
    if (chaninfo->pAlias0 == NULL && chaninfo->pAlias1 == NULL) {
        return 1;
    }
    if (AIL_stream_status(streamHandle) == 2) {
        AIL_close_stream(milesGlob.handle_stream[streamIdx]);
        milesGlob.handle_stream[streamIdx] = NULL;
        return 1;
    }
    return 0;
}

/* line 992 */
float SND_Get2DChannelVolume(int index)
{
    float left, right;
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    AIL_sample_volume_levels(milesGlob.handle_2D[index], &left, &right);
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    if (chaninfo->srcChannelCount == 2) {
        return left;
    }
    return left + right;
}

/* line 1033 */
float SND_Get3DChannelVolume(int index)
{
    return AIL_3D_sample_volume(milesGlob.handle_3D[index]);
}

/* line 1057 */
float SND_GetStreamChannelVolume(int index)
{
    float left, right;
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    const snd_alias_t *pAlias;
    int channel;
    AIL_stream_volume_levels(milesGlob.handle_stream[index - 0x20], &left, &right);
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    if (chaninfo->srcChannelCount == 2) {
        pAlias = chaninfo->pAlias0;
        channel = (pAlias->flags & 0x780) >> 7;
        if (!SND_IsAliasChannel3D(channel)) {
            return left;
        }
    }
    return left + right;
}

/* line 1098 */
int SND_Get2DChannelPlaybackRate(int index)
{
    return AIL_sample_playback_rate(milesGlob.handle_2D[index]);
}

/* line 1105 */
void SND_Set2DChannelPlaybackRate(int index, int rate)
{
    AIL_set_sample_playback_rate(milesGlob.handle_2D[index], rate);
}

/* line 1112 */
int SND_Get3DChannelPlaybackRate(int index)
{
    return AIL_3D_sample_playback_rate(milesGlob.handle_3D[index]);
}

/* line 1119 */
void SND_Set3DChannelPlaybackRate(int index, int rate)
{
    AIL_set_3D_sample_playback_rate(milesGlob.handle_3D[index], rate);
}

/* line 1126 */
int SND_GetStreamChannelPlaybackRate(int index)
{
    return AIL_stream_playback_rate(milesGlob.handle_stream[index - 0x20]);
}

/* line 1133 */
void SND_SetStreamChannelPlaybackRate(int index, int rate)
{
    AIL_set_stream_playback_rate(milesGlob.handle_stream[index - 0x20], rate);
}

/* line 1156 */
void SND_UpdateStreamChannelReverb(int index)
{
    snd_local_t *sndGlob = *(snd_local_t **)imp_g_snd;
    snd_channel_info_t *chaninfo = &sndGlob->chaninfo[index];
    const snd_alias_t *pAlias = chaninfo->pAlias0;
    float reverbLevel;
    if (pAlias != NULL) {
        byte *sndGlob2 = *(byte **)imp_snd_enableReverb;
        byte *ptr = *(byte **)sndGlob2;
        if (((dvar_t *)ptr)->current.enabled == 0 || (pAlias->flags & 0x10)) {
            AIL_set_stream_reverb_levels(milesGlob.handle_stream[index - 0x20], 1.0f, 0.0f);
            return;
        }
    }
    reverbLevel = sndGlob->effect->wetlevel;
    AIL_set_stream_reverb_levels(milesGlob.handle_stream[index - 0x20], 1.0f, reverbLevel);
}

/* line 1164 */
int SND_Get2DChannelLength(int index)
{
    long int length;
    AIL_sample_ms_position(milesGlob.handle_2D[index], &length, NULL);
    return (int)length;
}

/* line 1175 */
int SND_Get3DChannelLength(int index)
{
    return AIL_3D_sample_length(milesGlob.handle_3D[index]);
}

/* line 1182 */
int SND_GetStreamChannelLength(int index)
{
    long int length;
    AIL_stream_ms_position(milesGlob.handle_stream[index - 0x20], &length, NULL);
    return (int)length;
}

/* line 1193 */
void SND_Get2DChannelSaveInfo(int index, snd_save_2D_sample_t *info)
{
    void *handle;
    long int length, offset;
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    float masterVol;

    handle = milesGlob.handle_2D[index];
    AIL_sample_ms_position(handle, &length, &offset);
    info->fraction = (float)offset / (float)length;
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    info->pitch = chaninfo->pitch;
    AIL_sample_volume_pan(handle, &info->volume, &info->pan);
    masterVol = sndGlob->volume;
    if (masterVol != 0.0f) {
        info->volume /= masterVol;
    } else {
        info->volume = chaninfo->basevolume;
    }
}

/* line 1222 */
void SND_Get3DChannelSaveInfo(int index, snd_save_3D_sample_t *info)
{
    void *handle;
    long unsigned int sampleOffset;
    int sampleLength;
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    float vol, masterVol;

    handle = milesGlob.handle_3D[index];
    sampleOffset = AIL_3D_sample_offset(handle);
    sampleLength = AIL_3D_sample_length(handle);
    info->fraction = (float)sampleOffset / (float)sampleLength;
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    info->pitch = chaninfo->pitch;
    vol = AIL_3D_sample_volume(handle);
    info->volume = vol;
    masterVol = sndGlob->volume;
    if (masterVol != 0.0f) {
        info->volume = vol / masterVol;
    } else {
        info->volume = chaninfo->basevolume;
    }
    AIL_3D_position(handle, &info->org[0], &info->org[1], &info->org[2]);
}

/* line 1241 */
void SND_GetStreamChannelSaveInfo(int index, snd_save_stream_t *info)
{
    void *handle;
    long int length, offset;
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    float masterVol;

    handle = milesGlob.handle_stream[index - 0x20];
    AIL_stream_ms_position(handle, &length, &offset);
    info->fraction = (float)offset / (float)length;
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[index];
    info->rate = (int)floorf((float)AIL_stream_playback_rate(handle) / sndGlob->timescale + 0.5f);
    info->basevolume = chaninfo->basevolume;
    AIL_stream_volume_pan(handle, &info->volume, &info->pan);
    masterVol = sndGlob->volume;
    if (masterVol != 0.0f) {
        info->volume /= masterVol;
    } else {
        info->volume = chaninfo->basevolume;
    }
    info->org[0] = chaninfo->org[0];
    info->org[1] = chaninfo->org[1];
    info->org[2] = chaninfo->org[2];
}

/* line 1328 */
void SND_EndRawSamples(void)
{
    if (milesGlob.raw.handle != NULL) {
        AIL_end_sample(milesGlob.raw.handle);
        AIL_release_sample_handle(milesGlob.raw.handle);
        milesGlob.raw.handle = NULL;
        Z_FreeInternal(milesGlob.raw.buf);
    }
}

/* line 1340 */
int SND_RawSamplesTime(void)
{
    if (milesGlob.raw.handle != NULL) {
        long unsigned int pos = AIL_sample_position(milesGlob.raw.handle);
        double dpos = (double)(unsigned long long)pos;
        return (int)(dpos * milesGlob.raw.bufRate + milesGlob.raw.sampleTime);
    }
    return 0;
}

/* line 1377 */
void SND_RawSamples(int samples, int rate, int width, int s_channels, const byte *data)
{
    int bytes, copy, format, bufSize;
    float vol;
    snd_local_t *sndGlob;

    sndGlob = *(snd_local_t **)imp_g_snd;
    if (sndGlob == NULL || !sndGlob->Initialized2d) {
        return;
    }

    if (milesGlob.raw.handle == NULL) {
        /* Initialize raw sample handle */
        milesGlob.raw.handle = AIL_allocate_sample_handle(milesGlob.driver_2D);
        if (milesGlob.raw.handle == NULL) {
            Com_Error(1, (const char *)str_0021992c);
        }
        milesGlob.raw.rate = rate;
        milesGlob.raw.width = width;
        milesGlob.raw.channels = s_channels;
        AIL_init_sample(milesGlob.raw.handle);
        /* Determine format based on channels and width */
        if (s_channels == 1) {
            if (width == 1) {
                format = 0;
            } else if (width == 2) {
                format = 1;
            } else {
                format = 0;
            }
        } else {
            if (width == 1) {
                format = 2;
            } else if (width == 2) {
                format = 3;
            } else {
                format = 0;
            }
        }
        AIL_set_sample_type(milesGlob.raw.handle, format, 0);
        AIL_set_sample_playback_rate(milesGlob.raw.handle, rate);
        vol = 0.5f * sndGlob->volume;
        AIL_set_sample_volume_levels(milesGlob.raw.handle, vol, vol);
        bufSize = AIL_minimum_sample_buffer_size(milesGlob.driver_2D, rate, format);
        if (bufSize < 0x2001) {
            bufSize = 0x2000;
        }
        milesGlob.raw.bufSize = bufSize;
        milesGlob.raw.buf = Z_MallocInternal(bufSize * 32);
        memset(milesGlob.raw.bufReady, 0, 32);
        milesGlob.raw.readBuf = 0;
        milesGlob.raw.writeBuf = 0;
        milesGlob.raw.bufUsed = 0;
        milesGlob.raw.sampleTime = 0.0;
        {
            float bytesPerMs = 1000.0f / (float)(milesGlob.raw.rate * milesGlob.raw.width * milesGlob.raw.channels);
            milesGlob.raw.bufRate = (double)bytesPerMs;
        }
    }

    if (milesGlob.raw.handle == NULL) {
        return;
    }

    bytes = width * samples * s_channels;
    while (bytes != 0) {
        while (milesGlob.raw.bufReady[milesGlob.raw.writeBuf] != 0) {
            SND_Update();
        }
        copy = milesGlob.raw.bufSize - milesGlob.raw.bufUsed;
        if (bytes < copy) {
            copy = bytes;
            bytes = 0;
        } else {
            bytes -= copy;
        }
        Com_Memcpy((void *)(milesGlob.raw.buf + milesGlob.raw.writeBuf * milesGlob.raw.bufSize + milesGlob.raw.bufUsed), (void *)data, copy);
        data += copy;
        milesGlob.raw.bufUsed += copy;
        if (milesGlob.raw.bufUsed == milesGlob.raw.bufSize) {
            milesGlob.raw.bufUsed = 0;
            milesGlob.raw.bufReady[milesGlob.raw.writeBuf] = 1;
            milesGlob.raw.writeBuf = (milesGlob.raw.writeBuf + 1) % 32;
        }
    }
}

/* line 1569 */
int SND_GetSoundFileSize(const void *pSoundFile)
{
    const MssSound *sound = (const MssSound *)pSoundFile;
    return (int)sound->info.data_len + 0x24; /* data_len + sizeof(AILSOUNDINFO) */
}

/* line 1587 */
void SND_DriverPreUpdate(int frametime)
{
}

/* line 984 */
void SND_SetRoomtype(int roomtype)
{
    snd_local_t *sndGlob;
    float reverbLevel;
    AIL_set_digital_master_room_type(milesGlob.driver_2D, roomtype);
    sndGlob = *(snd_local_t **)imp_g_snd;
    reverbLevel = sndGlob->effect->wetlevel;
    AIL_set_digital_master_reverb_levels(milesGlob.driver_2D, 1.0f, reverbLevel);
    AIL_set_3D_room_type(milesGlob.provider_3D, roomtype);
}

/* line 1140 */
void SND_Update2DChannelReverb(int index)
{
    snd_local_t *sndGlob = *(snd_local_t **)imp_g_snd;
    snd_channel_info_t *chaninfo = &sndGlob->chaninfo[index];
    const snd_alias_t *pAlias = chaninfo->pAlias0;
    float reverbLevel;

    if (pAlias == NULL || (((dvar_t *)*(void **)imp_snd_enableReverb)->current.enabled != 0 && !(pAlias->flags & 0x10))) {
        reverbLevel = 0;
    } else {
        reverbLevel = sndGlob->effect->wetlevel;
    }
    AIL_set_sample_reverb_levels(milesGlob.handle_2D[index], 1.0f, reverbLevel);
}

/* line 1148 */
void SND_Update3DChannelReverb(int index)
{
    snd_local_t *sndGlob = *(snd_local_t **)imp_g_snd;
    snd_channel_info_t *chaninfo = &sndGlob->chaninfo[index];
    const snd_alias_t *pAlias = chaninfo->pAlias0;
    float reverbLevel;

    if (pAlias == NULL || (((dvar_t *)*(void **)imp_snd_enableReverb)->current.enabled != 0 && !(pAlias->flags & 0x10))) {
        reverbLevel = 0;
    } else {
        reverbLevel = sndGlob->effect->wetlevel;
    }
    AIL_set_3D_sample_effects_level(milesGlob.handle_3D[index], reverbLevel);
}

/* line 518 */
void SND_Set3DPosition(int index, const vec_t *org)
{
    int listenerIdx;
    snd_local_t *sndGlob;
    snd_listener *listener;
    float *listenerOrigin, *right, *up, *forward;
    float dx, dy, dz;
    float x, y, z;

    listenerIdx = SND_GetListenerIndexNearestToOrigin(org);
    sndGlob = *(snd_local_t **)imp_g_snd;
    listener = &sndGlob->listeners[listenerIdx];
    listenerOrigin = listener->orient.origin;
    right = listener->orient.axis[0];
    up = listener->orient.axis[1];
    forward = listener->orient.axis[2];

    dx = org[0] - listenerOrigin[0];
    dy = org[1] - listenerOrigin[1];
    dz = org[2] - listenerOrigin[2];

    /* Transform to listener-relative coordinates */
    x = dx * right[0] + dy * right[1] + dz * right[2];
    z = dx * forward[0] + dy * forward[1] + dz * forward[2];
    y = -(dx * up[0] + dy * up[1] + dz * up[2]);

    AIL_set_3D_position(milesGlob.handle_3D[index], x, y, z);
}

/* line 485 */
static void MSS_SpatializeStream(float *volume, float *pan)
{
    /* This function is only called from converted C code now */
    /* It accesses the stream channel indexed by a global or caller-provided context */
    /* The original used register CC - keeping as stub, real logic inlined at call sites */
}

/* Helper that implements MSS_SpatializeStream logic for a given stream channel index */
static void MSS_SpatializeStreamImpl(int i, float *volume, float *pan)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    const snd_alias_t *pAlias0, *pAlias1;
    float *orgVec;
    int listenerIdx;
    snd_listener *listener;
    float *listenerOrigin, *right;
    float delta[3];
    float dot;
    float lerp, oneMinusLerp;
    float fDistMin, fDistMax;
    float savedVolume, attenuation;

    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[i];
    pAlias0 = chaninfo->pAlias0;
    pAlias1 = chaninfo->pAlias1;

    orgVec = chaninfo->org;

    listenerIdx = SND_GetListenerIndexNearestToOrigin(orgVec);
    listener = &sndGlob->listeners[listenerIdx];
    listenerOrigin = listener->orient.origin;

    delta[0] = orgVec[0] - listenerOrigin[0];
    delta[1] = orgVec[1] - listenerOrigin[1];
    delta[2] = orgVec[2] - listenerOrigin[2];

    Vec3Normalize(delta);

    right = listener->orient.axis[0];
    dot = delta[0] * right[-1] + delta[1] * right[0] + delta[2] * right[1];

    lerp = chaninfo->lerp;
    oneMinusLerp = 1.0f - lerp;

    fDistMin = oneMinusLerp * pAlias0->fDistMin + lerp * pAlias1->fDistMin;
    fDistMax = oneMinusLerp * pAlias0->fDistMax + lerp * pAlias1->fDistMax;

    savedVolume = *volume;
    attenuation = SND_Attenuate(pAlias0->volumeFalloffCurve, savedVolume, fDistMin, fDistMax);
    *volume = savedVolume * attenuation;
    *pan = (1.0f - dot) * 0.5f;
}

/* line 1716 */
void SND_UpdateStreamChannel(int i, int frametime)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    const snd_alias_t *pAlias0;
    int streamIdx;
    float volume, pan;
    int aliasFlags, channel;
    float *volTable;
    float scaledVol;
    int startDelay;

    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[i];

    if (chaninfo->paused != 0) {
        return;
    }

    if (i <= 0x22) {
        if (!SND_UpdateBackgroundVolume(i - 0x20, frametime)) {
            return;
        }
    }

    pAlias0 = chaninfo->pAlias0;
    if (pAlias0 == NULL || chaninfo->pAlias1 == NULL) {
        return;
    }

    volume = chaninfo->basevolume;
    pan = 0.5f;

    aliasFlags = pAlias0->flags;
    channel = (aliasFlags & 0x780) >> 7;

    if (SND_IsAliasChannel3D(channel)) {
        /* 3D stream path */
        streamIdx = i - 0x20;
        SND_GetCurrent3DPosition(chaninfo->entnum, chaninfo->offset, chaninfo->org);
        MSS_SpatializeStreamImpl(i, &volume, &pan);

        if (AIL_is_3D_stream(milesGlob.handle_stream[streamIdx])) {
            /* Set 3D stream position using listener-relative transform */
            int listenerIdx = SND_GetListenerIndexNearestToOrigin(chaninfo->org);
            snd_listener *listener = &sndGlob->listeners[listenerIdx];
            float *listenerOrigin = listener->orient.origin;
            float *right = listener->orient.axis[0];
            float *up = listener->orient.axis[1];
            float *forward = listener->orient.axis[2];
            float dx = chaninfo->org[0] - listenerOrigin[0];
            float dy = chaninfo->org[1] - listenerOrigin[1];
            float dz = chaninfo->org[2] - listenerOrigin[2];
            float x = dx * right[0] + dy * right[1] + dz * right[2];
            float z = dx * forward[0] + dy * forward[1] + dz * forward[2];
            float y = -(dx * up[0] + dy * up[1] + dz * up[2]);
            AIL_set_3D_stream_position(milesGlob.handle_stream[streamIdx], x, y, z);
            pan = 0.5f;
        }
    } else {
        streamIdx = i - 0x20;
    }

    /* Volume modulation */
    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[i];
    if (sndGlob->slaveLerp != 0.0f && chaninfo->master == 0) {
        aliasFlags = pAlias0->flags;
        if (aliasFlags & 4) {
            volume *= SND_GetLerpedSlavePercentage(&pAlias0->fSlavePercentage);
        }
        aliasFlags = pAlias0->flags;
    } else {
        aliasFlags = pAlias0->flags;
    }

    volTable = (float *)sndGlob->channelvol;
    channel = (aliasFlags & 0x780) >> 7;
    volume *= volTable[channel * 3];
    pan = pan; /* preserve pan */
    scaledVol = volume * sndGlob->volume;

    /* Set volume on stream */
    if (chaninfo->srcChannelCount == 2) {
        /* system == 2: check if 3D alias channel */
        const snd_alias_t *pA = chaninfo->pAlias0;
        int ch3d = (pA->flags & 0x780) >> 7;
        if (!SND_IsAliasChannel3D(ch3d)) {
            AIL_set_stream_volume_levels(milesGlob.handle_stream[streamIdx], scaledVol, scaledVol);
        } else {
            float leftVol = pan * scaledVol;
            float rightVol = (1.0f - pan) * scaledVol;
            AIL_set_stream_volume_levels(milesGlob.handle_stream[streamIdx], rightVol, leftVol);
        }
    } else {
        float leftVol = pan * scaledVol;
        float rightVol = (1.0f - pan) * scaledVol;
        AIL_set_stream_volume_levels(milesGlob.handle_stream[streamIdx], rightVol, leftVol);
    }

    /* Update start delay */
    startDelay = chaninfo->startDelay;
    if (startDelay != 0) {
        int newDelay = startDelay - frametime;
        if (frametime >= startDelay) {
            newDelay = 0;
        }
        chaninfo->startDelay = newDelay;
        if (newDelay == 0) {
            AIL_pause_stream(milesGlob.handle_stream[streamIdx], 0);
        }
    }
}

/* line 1612 */
void SND_Update2DChannel(int i, int frametime)
{
    snd_local_t *sndGlob;
    snd_channel_info_t *chaninfo;
    const snd_alias_t *pAlias0;
    int aliasFlags, channel;
    float volume, scaledVol;
    float *volTable;
    int startDelay, newDelay;

    sndGlob = *(snd_local_t **)imp_g_snd;
    chaninfo = &sndGlob->chaninfo[i];

    if (chaninfo->paused != 0) {
        return;
    }

    pAlias0 = chaninfo->pAlias0;
    if (pAlias0 == NULL || chaninfo->pAlias1 == NULL) {
        return;
    }

    volume = chaninfo->basevolume;

    if (sndGlob->slaveLerp != 0.0f) {
        if (chaninfo->master == 0) {
            aliasFlags = pAlias0->flags;
            if (aliasFlags & 4) {
                float slavePct = SND_GetLerpedSlavePercentage(&pAlias0->fSlavePercentage);
                volume *= slavePct;
            }
            aliasFlags = pAlias0->flags;
        } else {
            aliasFlags = pAlias0->flags;
        }
    } else {
        aliasFlags = pAlias0->flags;
    }

    volTable = (float *)sndGlob->channelvol;
    channel = (aliasFlags & 0x780) >> 7;
    scaledVol = volume * volTable[channel * 3] * sndGlob->volume;

    /* If not stereo system, halve the volume */
    if (chaninfo->srcChannelCount != 2) {
        scaledVol *= 0.5f;
    }
    AIL_set_sample_volume_levels(milesGlob.handle_2D[i], scaledVol, scaledVol);

    /* Update start delay */
    startDelay = chaninfo->startDelay;
    if (startDelay != 0) {
        newDelay = startDelay - frametime;
        if (frametime >= startDelay) {
            newDelay = 0;
        }
        chaninfo->startDelay = newDelay;
        if (newDelay == 0) {
            return AIL_resume_sample(milesGlob.handle_2D[i]);
        }
    }
}

/* line 1540 */
void SND_LoadSoundFile(SoundFile *soundFile)
{
    snd_local_t *sndGlob;
    char realname[384];
    void *buffer;
    int mixinfo[32]; /* large enough for AILSOUNDINFO */
    int datasize, totalSize;
    int rate, bits, channels, samples, blockSize, format;
    void *dataPtr;
    MssSound *sound;
    int maxRate, maxBits, maxChannels;
    int targetBits, targetChannels;
    int procFormat;

    sndGlob = *(snd_local_t **)imp_g_snd;
    if (!sndGlob || !sndGlob->Initialized2d) {
        soundFile->fileMem = NULL;
        return;
    }

    sprintf(realname, (const char *)str_00219968, soundFile->soundName); /* "sound/%s" */
    if (FS_ReadFile(realname, &buffer) < 0) {
        Com_Printf((const char *)str_00219974, realname); /* "^1ERROR: Sound file '%s' not found\n" */
        soundFile->fileMem = NULL;
        return;
    }

    if (!AIL_WAV_info(buffer, mixinfo)) {
        Com_Printf((const char *)str_00219998, realname); /* "^1ERROR: Sound file '%s' is in an invalid..." */
        sound = NULL;
    } else {
        /* mixinfo layout: [0]=format, [1]=dataPtr, [2]=datasize, [3]=rate, [4]=bits, [5]=channels, [6]=samples, [7]=blockSize */
        format = mixinfo[0];
        dataPtr = (void *)mixinfo[1];
        datasize = mixinfo[2];
        rate = mixinfo[3];
        bits = mixinfo[4];
        channels = mixinfo[5];
        samples = mixinfo[6];
        blockSize = mixinfo[7];

        totalSize = datasize + 0x24;
        if (totalSize == 0) {
            Com_Printf((const char *)str_002199d8, realname); /* "^1ERROR: Sound file '%s' is zero length..." */
            sound = NULL;
        } else {
            maxRate = sndGlob->playback_rate;
            maxBits = sndGlob->playback_bits;
            maxChannels = sndGlob->playback_channels;

            if ((unsigned int)rate <= (unsigned int)maxRate &&
                (bits <= maxBits || format == 0x11) &&
                channels <= maxChannels) {
                /* Direct copy - no resampling needed */
                sound = (MssSound *)Hunk_AllocNoZeroInternal(totalSize);
                Com_Memcpy(sound->data, dataPtr, datasize);
                sound->info.format = format;
                sound->info.data_ptr = dataPtr;
                sound->info.data_len = datasize;
                sound->info.rate = rate;
                sound->info.bits = bits;
                sound->info.channels = channels;
                sound->info.samples = samples;
                sound->info.block_size = blockSize;
                sound->info.data_ptr = sound->data;
                sound->info.initial_ptr = sound->data;
            } else {
                /* Resampling path */
                while ((unsigned int)rate > (unsigned int)maxRate) {
                    rate >>= 1;
                    samples >>= 1;
                }

                targetBits = bits;
                if (targetBits >= maxBits) {
                    targetBits = maxBits;
                }
                targetChannels = channels;
                if (targetChannels >= maxChannels) {
                    targetChannels = maxChannels;
                }

                /* Determine process format */
                if (targetChannels - 1 == 0) {
                    /* mono */
                    if (format == 0x11) {
                        procFormat = 5;
                    } else if (targetBits > 8) {
                        if (targetBits > 16) {
                            procFormat = 8;
                        } else {
                            procFormat = targetChannels; /* reuse as dummy */
                            procFormat = 1;
                            if (targetBits > 16) procFormat = 8;
                        }
                        procFormat = 1;
                        if (targetBits > 16) procFormat = 8;
                    } else {
                        procFormat = 0;
                    }
                } else {
                    /* stereo */
                    if (format == 0x11) {
                        procFormat = 7;
                    } else if (targetBits > 8) {
                        procFormat = 3;
                        if (targetBits > 16) {
                            procFormat = 0xa;
                        }
                    } else {
                        procFormat = 2;
                    }
                }

                datasize = AIL_size_processed_digital_audio(rate, procFormat, 1, mixinfo);
                sound = (MssSound *)Hunk_AllocNoZeroInternal(datasize + 0x24);

                sound->info.format = format;
                sound->info.data_ptr = sound->data;
                sound->info.data_len = datasize;
                sound->info.rate = rate;
                sound->info.bits = targetBits;
                sound->info.channels = targetChannels;
                sound->info.samples = samples;
                sound->info.block_size = blockSize;
                sound->info.initial_ptr = sound->data;

                AIL_process_digital_audio(sound->data, datasize, rate, procFormat, 1, mixinfo);
            }
        }
    }

    soundFile->fileMem = sound;
    FS_FreeFile(buffer);
}

/* line 698 */
int SND_StartAlias2DSample(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int *pChannel, snd_alias_system_t system)
{
    int index, channel, aliasFlags, sampleType;
    void *handle;
    byte *sound;
    byte *sndGlob;
    float scaledVol, volMul;
    float *volTable;
    long int total_msec;
    int start_msec;
    int bits, channels, format;
    float reverbLevel;

    aliasFlags = pAlias0->flags;
    channel = (aliasFlags & 0x780) >> 7;
    index = SND_FindFree2DChannel(entnum, channel);
    if (pChannel != NULL) {
        *pChannel = index;
    }
    if (index < 0) {
        return 0;
    }

    handle = *(void **)(0x4a3ad4 + index * 4);
    sound = (byte *)Com_GetSoundFileMem(pAlias0);
    AIL_init_sample(handle);

    /* Determine sample type from sound format */
    bits = (int)((MssSound *)sound)->info.bits;
    channels = (int)((MssSound *)sound)->info.channels;
    format = (int)((MssSound *)sound)->info.format;

    if (channels == 1) {
        if (format == 0x11) sampleType = 5;
        else if (bits <= 8) sampleType = 0;
        else if (bits <= 16) sampleType = 1;
        else sampleType = 8;
    } else {
        if (format == 0x11) sampleType = 7;
        else if (bits <= 8) sampleType = 2;
        else if (bits <= 16) sampleType = 3;
        else sampleType = 0xa;
    }

    AIL_set_sample_type(handle, sampleType, 0);
    AIL_set_sample_address(handle, (void *)((MssSound *)sound)->info.data_ptr, (int)((MssSound *)sound)->info.data_len);
    AIL_set_sample_adpcm_block_size(handle, (int)((MssSound *)sound)->info.block_size);

    sndGlob = *(byte **)imp_g_snd;
    AIL_set_sample_playback_rate(handle, (int)floorf((float)(int)((MssSound *)sound)->info.rate * pitch * ((snd_local_t *)sndGlob)->timescale + 0.5f));

    aliasFlags = pAlias0->flags;
    volTable = (float *)((snd_local_t *)sndGlob)->channelvol;
    channel = (aliasFlags & 0x780) >> 7;
    scaledVol = volume * ((snd_local_t *)sndGlob)->volume * volTable[channel * 3];

    /* Slave volume modulation */
    if (((snd_local_t *)sndGlob)->slaveLerp != 0.0f && !master && (aliasFlags & 4)) {
        scaledVol *= SND_GetLerpedSlavePercentage((void *)&pAlias0->fSlavePercentage);
    }

    /* Mono halving */
    volMul = (channels == 1) ? 0.5f : 1.0f;
    AIL_set_sample_volume_levels(handle, volMul * scaledVol, volMul * scaledVol);

    /* Loop count */
    AIL_set_sample_loop_count(handle, ((byte)(pAlias0->flags) & 1) ^ 1);

    /* Reverb */
    if (((dvar_t *)*(void **)imp_snd_enableReverb)->current.enabled != 0 && !((byte)(pAlias0->flags) & 0x10)) {
        reverbLevel = ((snd_local_t *)*(snd_local_t **)imp_g_snd)->effect->wetlevel;
    } else {
        reverbLevel = 0;
    }
    AIL_set_sample_reverb_levels(handle, 1.0f, reverbLevel);

    AIL_sample_ms_position(handle, &total_msec, NULL);
    if (total_msec <= timeshift) {
        return 0;
    }

    if (fraction != 0.0f) {
        start_msec = (int)floorf((float)total_msec * fraction + 0.5f);
    } else {
        start_msec = timeshift;
    }

    if (start_msec == 0) {
        startDelay = startDelay;
    } else {
        startDelay = 0;
    }

    AIL_set_sample_ms_position(handle, start_msec);

    if (startDelay == 0) {
        sndGlob = *(byte **)imp_g_snd;
        aliasFlags = pAlias0->flags;
        channel = (aliasFlags & 0x780) >> 7;
        if (((snd_local_t *)sndGlob)->paused == 0 || ((snd_local_t *)sndGlob)->pauseSettings[channel] == 0) {
            AIL_resume_sample(handle);
        }
        aliasFlags = pAlias0->flags;
    } else {
        aliasFlags = pAlias0->flags;
    }

    total_msec += startDelay;
    if (aliasFlags & 1) {
        total_msec = 0;
    }

    SND_SetChannelInfo(index, entnum, pAlias0, pAlias1, lerp, NULL, volume, pitch, channels, (int)((MssSound *)sound)->info.rate, total_msec, start_msec, startDelay, master, system);
    return (int)total_msec;
}

/* line 769 */
int SND_StartAlias3DSample(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int *pChannel, snd_alias_system_t system)
{
    int index, channel, aliasFlags;
    void *handle;
    byte *sound;
    byte *sndGlob;
    float scaledVol;
    float *volTable;
    float fDistMin, fDistMax, oneMinusLerp;
    float dist, attenuation;
    int playbackRate, total_msec, start_msec;
    int soundSamples;

    aliasFlags = pAlias0->flags;
    channel = (aliasFlags & 0x780) >> 7;
    index = SND_FindFree3DChannel(entnum, channel);
    if (pChannel != NULL) {
        *pChannel = index;
    }
    if (index < 0) {
        return 0;
    }

    handle = *(void **)(0x4a3ba8 + index * 4);
    sound = (byte *)Com_GetSoundFileMem(pAlias0);

    oneMinusLerp = 1.0f - lerp;
    fDistMin = oneMinusLerp * pAlias0->fDistMin + lerp * pAlias1->fDistMin;
    fDistMax = oneMinusLerp * pAlias0->fDistMax + lerp * pAlias1->fDistMax;

    AIL_set_3D_sample_info(handle, sound);

    /* Compute attenuation from distance */
    {
        int listenerIdx = SND_GetListenerIndexNearestToOrigin(org);
        sndGlob = *(byte **)imp_g_snd;
        dist = Vec3Distance(org, ((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.origin);
    }
    attenuation = SND_Attenuate(pAlias0->volumeFalloffCurve, dist, fDistMin, fDistMax);

    aliasFlags = pAlias0->flags;
    sndGlob = *(byte **)imp_g_snd;
    volTable = (float *)((snd_local_t *)sndGlob)->channelvol;
    channel = (aliasFlags & 0x780) >> 7;
    scaledVol = attenuation * volume * volTable[channel * 3] * ((snd_local_t *)sndGlob)->volume;

    /* Slave volume modulation */
    if (((snd_local_t *)sndGlob)->slaveLerp != 0.0f && !master && (aliasFlags & 4)) {
        scaledVol *= SND_GetLerpedSlavePercentage((void *)&pAlias0->fSlavePercentage);
    }

    AIL_set_3D_sample_volume(handle, scaledVol);
    AIL_set_3D_sample_distances(handle, pAlias0->fDistMin, pAlias0->fDistMax);

    playbackRate = AIL_3D_sample_playback_rate(handle);
    sndGlob = *(byte **)imp_g_snd;
    AIL_set_3D_sample_playback_rate(handle, (int)floorf((float)playbackRate * pitch * ((snd_local_t *)sndGlob)->timescale + 0.5f));
    SND_Set3DPosition(index, org);

    AIL_set_3D_sample_loop_count(handle, ((byte)(pAlias0->flags) & 1) ^ 1);
    AIL_set_3D_sample_effects_level(handle, ((snd_local_t *)sndGlob)->effect->wetlevel);

    /* Compute total_msec from sound samples */
    soundSamples = (int)((MssSound *)sound)->info.samples;
    {
        int val = soundSamples * 5 * 5 * 5 * 8; /* *1000 */
        float totalFloat = (float)val * ((snd_local_t *)*(snd_local_t **)imp_g_snd)->timescale / (float)playbackRate + 0.5f;
        total_msec = (int)floorf(totalFloat);
    }

    if (total_msec <= timeshift) {
        return 0;
    }

    if (fraction != 0.0f) {
        start_msec = (int)floorf((float)total_msec * fraction + 0.5f);
    } else {
        start_msec = timeshift;
    }

    if (start_msec == 0) {
        /* keep startDelay */
    } else {
        startDelay = 0;
    }

    /* Set 3D sample offset using byte position */
    {
        int datasize = (int)((MssSound *)sound)->info.data_len;
        float bytePos = (float)datasize * fraction + 0.5f;
        AIL_set_3D_sample_offset(handle, (int)floorf(bytePos));
    }

    if (startDelay == 0) {
        sndGlob = *(byte **)imp_g_snd;
        aliasFlags = pAlias0->flags;
        channel = (aliasFlags & 0x780) >> 7;
        if (((snd_local_t *)sndGlob)->paused == 0 || ((snd_local_t *)sndGlob)->pauseSettings[channel] == 0) {
            AIL_resume_3D_sample(handle);
        }
        aliasFlags = pAlias0->flags;
    } else {
        aliasFlags = pAlias0->flags;
    }

    total_msec += startDelay;
    if (aliasFlags & 1) {
        total_msec = 0;
    }

    SND_SetChannelInfo(index, entnum, pAlias0, pAlias1, lerp, org, volume, pitch, (int)((MssSound *)sound)->info.channels, (int)((MssSound *)sound)->info.rate, total_msec, start_msec, startDelay, master, system);
    return total_msec;
}

/* REMOVED old SND_StartAlias3DSample asm - replaced with C above */

#if 0
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 769 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 0x34(%ebp), %ebx\n" /* pChannel */
        "movzbl 0x30(%ebp), %eax\n" /* master */
        "movb %al, -0x2d(%ebp)\n" /* master */
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 788 | pAlias0 */
        "movl 0x2c(%edx), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* entnum */
        "movl %eax, (%esp)\n"
        "calll SND_FindFree3DChannel\n"
        "movl %eax, -0x28(%ebp)\n" /* index */
        "testl %ebx, %ebx\n" /* line 789 | total_msec */
        "je .Lf57f6e_00057faa\n"
        "movl %eax, (%ebx)\n" /* line 790 | total_msec */
        ".Lf57f6e_00057faa:\n"
        "movl -0x28(%ebp), %eax\n" /* line 791 | index */
        "testl %eax, %eax\n"
        "js .Lf57f6e_000582af\n"
        "movl -0x28(%ebp), %edx\n" /* line 795 | index */
        "movl milesGlob+40(, %edx, 4), %esi\n" /* handle */
        "movl 8(%ebp), %eax\n" /* line 796 | pAlias0 */
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileMem\n"
        "movl %eax, -0x24(%ebp)\n" /* sound */
        "movss lit4_002ed5d0, %xmm1\n" /* line 798 | 1.0f */
        "subss 0x10(%ebp), %xmm1\n" /* lerp */
        "movaps %xmm1, %xmm0\n"
        "movl 8(%ebp), %edx\n" /* pAlias0 */
        "mulss 0x24(%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* fDistMin */
        "movss 0x10(%ebp), %xmm0\n" /* lerp */
        "movl 0xc(%ebp), %eax\n" /* pAlias1 */
        "mulss 0x24(%eax), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n" /* fDistMin */
        "movss %xmm0, -0x20(%ebp)\n" /* fDistMin */
        "mulss 0x28(%edx), %xmm1\n" /* line 799 */
        "movss %xmm1, -0x1c(%ebp)\n" /* fDistMax */
        "movss 0x10(%ebp), %xmm0\n" /* lerp */
        "mulss 0x28(%eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* fDistMax */
        "movl -0x24(%ebp), %edx\n" /* line 802 | sound */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_3D_sample_info\n"
        "movl 0x18(%ebp), %eax\n" /* line 805 | org */
        "movl %eax, (%esp)\n"
        "calll SND_GetListenerIndexNearestToOrigin\n"
        "leal (, %eax, 8), %edx\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl imp_g_snd, %ebx\n" /* total_msec */
        "leal 0x2f4(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x18(%ebp), %edx\n" /* org */
        "movl %edx, (%esp)\n"
        "calll Vec3Distance\n"
        "movss -0x1c(%ebp), %xmm0\n" /* fDistMax */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x20(%ebp), %xmm0\n" /* fDistMin */
        "movss %xmm0, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* pAlias0 */
        "movl 0x40(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_Attenuate\n"
        "fstps -0x5c(%ebp)\n"
        "movss -0x5c(%ebp), %xmm1\n"
        "movl 8(%ebp), %eax\n" /* pAlias0 */
        "movl 0x2c(%eax), %ecx\n"
        "mulss 0x1c(%ebp), %xmm1\n" /* volume */
        "movl 0x254(%ebx), %edx\n" /* total_msec */
        "movl %ecx, %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "mulss (%edx, %eax, 4), %xmm1\n"
        "mulss 0x24(%ebx), %xmm1\n" /* line 806 | total_msec */
        "pxor %xmm0, %xmm0\n" /* line 807 */
        "ucomiss 0x274(%ebx), %xmm0\n" /* total_msec */
        "jp .Lf57f6e_00058277\n"
        "jne .Lf57f6e_00058277\n"
        ".Lf57f6e_000580cf:\n"
        "movss %xmm1, 4(%esp)\n" /* line 812 */
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_3D_sample_volume\n"
        "movl 8(%ebp), %edx\n" /* line 814 | pAlias0 */
        "movl 0x24(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_3D_sample_distances\n"
        "movl %esi, (%esp)\n" /* line 815 | handle */
        "calll AIL_3D_sample_playback_rate\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "mulss 0x20(%ebp), %xmm0\n" /* pitch */
        "movl imp_g_snd, %ebx\n"
        "mulss 0x10(%ebx), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x34(%ebp)\n"
        "cvttss2si -0x34(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n" /* line 816 | start_msec */
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_3D_sample_playback_rate\n"
        "movl 0x18(%ebp), %eax\n" /* line 817 | org */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* index */
        "movl %edx, (%esp)\n"
        "calll SND_Set3DPosition\n"
        "movl 8(%ebp), %edx\n" /* line 818 | pAlias0 */
        "movzbl 0x2c(%edx), %eax\n"
        "andb $1, %al\n"
        "xorb $1, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_3D_sample_loop_count\n"
        "movl 0x2d8(%ebx), %eax\n" /* line 820 | total_msec */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_3D_sample_effects_level\n"
        "movl -0x24(%ebp), %edx\n" /* line 428 | sound */
        "movl 0x18(%edx), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "js .Lf57f6e_000583ab\n"
        "cvtsi2ssl %eax, %xmm1\n"
        ".Lf57f6e_00058195:\n"
        "movl imp_g_snd, %eax\n"
        "mulss 0x10(%eax), %xmm1\n"
        "cvtsi2ssl %edi, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %ebx\n"
        "cmpl 0x24(%ebp), %ebx\n" /* line 824 | timeshift, total_msec */
        "jle .Lf57f6e_000582af\n"
        "movss 0x28(%ebp), %xmm0\n" /* line 827 | fraction */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf57f6e_00058356\n"
        "jp .Lf57f6e_00058356\n"
        "movl 0x24(%ebp), %edi\n" /* timeshift, start_msec */
        "testl %edi, %edi\n" /* line 832 | start_msec */
        "movl $0, %eax\n"
        "cmovel 0x2c(%ebp), %eax\n" /* startDelay */
        "movl %eax, 0x2c(%ebp)\n" /* startDelay */
        "movl -0x24(%ebp), %eax\n" /* line 428 | sound */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf57f6e_00058395\n"
        ".Lf57f6e_00058201:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf57f6e_00058205:\n"
        "mulss 0x28(%ebp), %xmm0\n" /* fraction */
        "movss %xmm0, 0x28(%ebp)\n" /* fraction */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss 0x28(%ebp), %xmm0\n" /* fraction */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x40(%ebp)\n"
        "cvttss2si -0x40(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll AIL_set_3D_sample_offset\n"
        "movl 0x2c(%ebp), %eax\n" /* line 836 | startDelay */
        "testl %eax, %eax\n"
        "jne .Lf57f6e_000582be\n"
        "movl imp_g_snd, %ecx\n"
        "cmpb $0, 2(%ecx)\n"
        "je .Lf57f6e_00058267\n"
        "movl 8(%ebp), %eax\n" /* pAlias0 */
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "cmpb $0, 0x2e7(%eax, %ecx)\n"
        "jne .Lf57f6e_000582c4\n"
        ".Lf57f6e_00058267:\n"
        "movl %esi, (%esp)\n" /* line 837 | handle */
        "calll AIL_resume_3D_sample\n"
        "movl 8(%ebp), %eax\n" /* pAlias0 */
        "movl 0x2c(%eax), %edx\n"
        "jmp .Lf57f6e_000582c4\n"
        ".Lf57f6e_00058277:\n"
        "cmpb $0, -0x2d(%ebp)\n" /* line 807 | master */
        "jne .Lf57f6e_000580cf\n"
        "andb $4, %cl\n"
        "je .Lf57f6e_000580cf\n"
        "movl 8(%ebp), %edx\n" /* line 808 | pAlias0 */
        "movl 0x30(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "calll SND_GetLerpedSlavePercentage\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x58(%ebp), %xmm1\n"
        "mulss -0x2c(%ebp), %xmm1\n"
        "jmp .Lf57f6e_000580cf\n"
        ".Lf57f6e_000582af:\n"
        "xorl %ebx, %ebx\n" /* line 844 | total_msec */
        /* } scope */
        "movl %ebx, %eax\n" /* line 845 | total_msec */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf57f6e_000582be:\n"
        "movl 8(%ebp), %eax\n" /* pAlias0 */
        "movl 0x2c(%eax), %edx\n"
        /* { scope 1 */
        ".Lf57f6e_000582c4:\n"
        "addl 0x2c(%ebp), %ebx\n" /* line 839 | startDelay, total_msec */
        "andb $1, %dl\n" /* line 840 */
        "movl $0, %eax\n"
        "cmovnel %eax, %ebx\n" /* total_msec */
        "movl 0x38(%ebp), %edx\n" /* line 843 | system */
        "movl %edx, 0x38(%esp)\n"
        "movzbl -0x2d(%ebp), %eax\n" /* master */
        "movl %eax, 0x34(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* startDelay */
        "movl %eax, 0x30(%esp)\n"
        "movl %edi, 0x2c(%esp)\n" /* start_msec */
        "movl %ebx, 0x28(%esp)\n" /* total_msec */
        "movl -0x24(%ebp), %edx\n" /* sound */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movss 0x20(%ebp), %xmm0\n" /* pitch */
        "movss %xmm0, 0x1c(%esp)\n"
        "movss 0x1c(%ebp), %xmm0\n" /* volume */
        "movss %xmm0, 0x18(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* org */
        "movl %eax, 0x14(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* lerp */
        "movss %xmm0, 0x10(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %edx\n" /* pAlias0 */
        "movl %edx, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* entnum */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* index */
        "movl %edx, (%esp)\n"
        "calll SND_SetChannelInfo\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 845 | total_msec */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf57f6e_00058356:\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 428 */
        "mulss 0x28(%ebp), %xmm0\n" /* fraction */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x3c(%ebp)\n"
        "cvttss2si -0x3c(%ebp), %edi\n"
        "testl %edi, %edi\n" /* line 832 | start_msec */
        "movl $0, %eax\n"
        "cmovel 0x2c(%ebp), %eax\n" /* startDelay */
        "movl %eax, 0x2c(%ebp)\n" /* startDelay */
        "movl -0x24(%ebp), %eax\n" /* line 428 | sound */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jns .Lf57f6e_00058201\n"
        ".Lf57f6e_00058395:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf57f6e_00058205\n"
        ".Lf57f6e_000583ab:\n"
        "shrl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lf57f6e_00058195\n"
    );
#endif

/* line 848 */
int SND_StartAliasStreamOnChannel(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int index, snd_alias_system_t system)
{
    int streamIdx;
    void *handle;
    char realname[256];
    int filetype;
    int srcChannelCount;
    int baserate;
    byte *sndGlob;
    int aliasFlags, channel;
    float *volTable;
    float scaledVol;
    float pan;
    float reverbLevel;
    long int total_msec;
    int start_msec;
    byte *chanBase;
    float *to;

    /* Check if sound file data exists */
    if (pAlias0->soundFile->isStreamFound == 0) {
        Com_DPrintf((const char *)str_00219a0c, Com_GetSoundFileName(pAlias0), pAlias0->pszAliasName);
        return 0;
    }

    /* Close existing stream if present */
    streamIdx = index - 0x20;
    if (*(void **)(0x4a3c28 + streamIdx * 4) != NULL) {
        AIL_close_stream(*(void **)(0x4a3c28 + streamIdx * 4));
        *(void **)(0x4a3c28 + streamIdx * 4) = NULL;
    }

    /* Build filename */
    sprintf(realname, (const char *)str_00219968, Com_GetSoundFileName(pAlias0));

    /* Try to open stream - first try mss_q3fs path, then filesystem path */
    if (mss_q3fs->current.enabled != 0) {
        handle = AIL_open_stream(milesGlob.driver_2D, realname, 0);
        if (handle != NULL) {
            goto got_handle;
        }
        /* Fall through to try FS path */
    }

    handle = AIL_open_stream(milesGlob.driver_2D, FS_ShortOSFilePath(realname), 0);
    if (handle == NULL) {
        Com_Printf((const char *)str_00219a64, realname, pAlias0->pszAliasName, AIL_last_error());
        return 0;
    }

got_handle:
    /* Store handle */
    *(void **)(0x4a3c28 + streamIdx * 4) = handle;

    /* Get stream info */
    AIL_stream_info(handle, &filetype, NULL, NULL, NULL);
    srcChannelCount = (filetype & 2) ? 2 : 1;

    /* Set playback rate */
    baserate = AIL_stream_playback_rate(handle);
    sndGlob = *(byte **)imp_g_snd;
    AIL_set_stream_playback_rate(handle, (int)floorf((float)baserate * pitch * ((snd_local_t *)sndGlob)->timescale + 0.5f));

    /* Calculate volume */
    aliasFlags = pAlias0->flags;
    scaledVol = ((snd_local_t *)sndGlob)->volume * volume;
    volTable = (float *)((snd_local_t *)sndGlob)->channelvol;
    channel = (aliasFlags & 0x780) >> 7;
    scaledVol *= volTable[channel * 3];

    /* Slave volume modulation */
    if (((snd_local_t *)sndGlob)->slaveLerp != 0.0f && !master) {
        if (aliasFlags & 4) {
            scaledVol *= SND_GetLerpedSlavePercentage((void *)&pAlias0->fSlavePercentage);
        }
    }

    /* Set volume based on channel count */
    if (srcChannelCount == 1) {
        pan = 0.5f;
    } else {
        pan = 1.0f;
    }
    AIL_set_stream_volume_levels(handle, pan * scaledVol, pan * scaledVol);

    /* Loop count */
    AIL_set_stream_loop_count(handle, ((byte)(pAlias0->flags) & 1) ^ 1);

    /* Reverb */
    if (((dvar_t *)*(void **)imp_snd_enableReverb)->current.enabled != 0 && !((byte)(pAlias0->flags) & 0x10)) {
        reverbLevel = ((snd_local_t *)*(snd_local_t **)imp_g_snd)->effect->wetlevel;
    } else {
        reverbLevel = 0;
    }
    AIL_set_stream_reverb_levels(handle, 1.0f, reverbLevel);

    /* Get stream length */
    AIL_stream_ms_position(handle, &total_msec, NULL);
    if (total_msec <= timeshift) {
        return 0;
    }
    if (total_msec == 0) {
        Com_Printf((const char *)str_002199d8, realname);
        return 0;
    }

    /* Calculate start position */
    if (fraction != 0.0f) {
        start_msec = (int)floorf((float)total_msec * fraction + 0.5f);
    } else {
        start_msec = timeshift;
    }

    /* Adjust startDelay */
    if (start_msec != 0) {
        startDelay = 0;
    }

    AIL_set_stream_ms_position(handle, start_msec);

    /* Start playback if no delay */
    if (startDelay == 0) {
        sndGlob = *(byte **)imp_g_snd;
        aliasFlags = pAlias0->flags;
        channel = (aliasFlags & 0x780) >> 7;
        if (((snd_local_t *)sndGlob)->paused == 0 || ((snd_local_t *)sndGlob)->pauseSettings[channel] == 0) {
            AIL_pause_stream(handle, 0);
        }
        aliasFlags = pAlias0->flags;
    } else {
        aliasFlags = pAlias0->flags;
    }

    /* Adjust total_msec for looping */
    total_msec += startDelay;
    if (aliasFlags & 1) {
        total_msec = 0;
    }

    /* Copy org to channel position */
    {
        sndGlob = *(byte **)imp_g_snd;
        to = ((snd_local_t *)sndGlob)->chaninfo[index].org;
        to[0] = org[0];
        to[1] = org[1];
        to[2] = org[2];
    }

    /* Set channel info */
    SND_SetChannelInfo(index, entnum, pAlias0, pAlias1, lerp, org, volume, pitch, srcChannelCount, baserate, (int)total_msec, start_msec, startDelay, master, (int)system);

    /* Check if 3D alias channel */
    {
        sndGlob = *(byte **)imp_g_snd;
        int chFlags = ((snd_local_t *)sndGlob)->chaninfo[index].pAlias0->flags;
        channel = (chFlags & 0x780) >> 7;
    }

    if (SND_IsAliasChannel3D(channel)) {
        /* Spatialize the stream */
        MSS_SpatializeStreamImpl(streamIdx, &volume, &pan);

        /* If 3D stream, set 3D position */
        if (AIL_is_3D_stream(*(void **)(0x4a3c28 + streamIdx * 4))) {
            sndGlob = *(byte **)imp_g_snd;
            to = ((snd_local_t *)sndGlob)->chaninfo[index].org;
            {
                int listenerIdx = SND_GetListenerIndexNearestToOrigin(to);
                float *listenerOrigin = ((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.origin;
                float *right = ((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.axis[0];
                float *up = ((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.axis[1];
                float *forward = ((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.axis[2];
                float dx = to[0] - listenerOrigin[0];
                float dy = to[1] - listenerOrigin[1];
                float dz = to[2] - listenerOrigin[2];
                float x = dx * right[0] + dy * right[1] + dz * right[2];
                float z = dx * forward[0] + dy * forward[1] + dz * forward[2];
                float y = -(dx * up[0] + dy * up[1] + dz * up[2]);
                AIL_set_3D_stream_position(*(void **)(0x4a3c28 + streamIdx * 4), x, y, z);
            }
            pan = 0.5f;
        }

        /* Recalculate volume with spatialize results */
        sndGlob = *(byte **)imp_g_snd;
        aliasFlags = pAlias0->flags;
        scaledVol = ((snd_local_t *)sndGlob)->volume * volume;
        volTable = (float *)((snd_local_t *)sndGlob)->channelvol;
        channel = (aliasFlags & 0x780) >> 7;
        scaledVol *= volTable[channel * 3];

        if (((snd_local_t *)sndGlob)->slaveLerp != 0.0f && !master && (aliasFlags & 4)) {
            scaledVol *= SND_GetLerpedSlavePercentage((void *)&pAlias0->fSlavePercentage);
        }

        {
            float leftVol = pan * scaledVol;
            float rightVol = (1.0f - pan) * scaledVol;
            AIL_set_stream_volume_levels(handle, rightVol, leftVol);
        }
    }

    return (int)total_msec;
}

/* line 1658 */
void SND_Update3DChannel(int i, int frametime)
{
    byte *sndGlob;
    byte *ch;
    const snd_alias_t *pAlias0, *pAlias1;
    float lerp, oneMinusLerp;
    float volume;
    float fDistMin, fDistMax;
    float org[3];
    float dist, attenuation;
    int aliasFlags, channel;
    float *volTable;
    float scaledVol;
    int startDelay, newDelay;

    sndGlob = *(byte **)imp_g_snd;
    ch = sndGlob + i * 80;

    {
        snd_channel_info_t *ci = &((snd_local_t *)sndGlob)->chaninfo[i];

    if (ci->paused != 0) {
        return;
    }

    pAlias0 = ci->pAlias0;
    pAlias1 = ci->pAlias1;
    if (pAlias0 == NULL || pAlias1 == NULL) {
        return;
    }

    lerp = ci->lerp;
    volume = ci->basevolume;

    SND_GetCurrent3DPosition(ci->entnum, (float *)&ci->system, org);
    SND_Set3DPosition(i, org);

    oneMinusLerp = 1.0f - lerp;
    fDistMin = oneMinusLerp * pAlias0->fDistMin + lerp * pAlias1->fDistMin;
    fDistMax = oneMinusLerp * pAlias0->fDistMax + lerp * pAlias1->fDistMax;

    {
        int listenerIdx = SND_GetListenerIndexNearestToOrigin(org);
        sndGlob = *(byte **)imp_g_snd;
        dist = Vec3Distance(org, ((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.origin);
    }
    attenuation = SND_Attenuate(pAlias0->volumeFalloffCurve, dist, fDistMin, fDistMax);
    volume *= attenuation;

    /* Slave volume modulation */
    sndGlob = *(byte **)imp_g_snd;
    if (((snd_local_t *)sndGlob)->slaveLerp != 0.0f && ci->master == 0) {
        aliasFlags = pAlias0->flags;
        if (aliasFlags & 4) {
            volume *= SND_GetLerpedSlavePercentage((void *)&pAlias0->fSlavePercentage);
        }
        aliasFlags = pAlias0->flags;
    } else {
        aliasFlags = pAlias0->flags;
    }

    sndGlob = *(byte **)imp_g_snd;
    volTable = (float *)((snd_local_t *)sndGlob)->channelvol;
    channel = (aliasFlags & 0x780) >> 7;
    scaledVol = volume * volTable[channel * 3] * ((snd_local_t *)sndGlob)->volume;
    AIL_set_3D_sample_volume(*(void **)(0x4a3ba8 + i * 4), scaledVol);

    /* Update start delay */
    {
        startDelay = ((snd_local_t *)sndGlob)->chaninfo[i].startDelay;
        if (startDelay != 0) {
            newDelay = startDelay - frametime;
            if (frametime >= startDelay) {
                newDelay = 0;
            }
            ((snd_local_t *)sndGlob)->chaninfo[i].startDelay = newDelay;
            if (newDelay == 0) {
                AIL_resume_3D_sample(*(void **)(0x4a3ba8 + i * 4));
            }
        }
    }
}

/* line 1214 */
void SND_Set2DChannelFromSaveInfo(int index, snd_save_2D_sample_t *info)
{
    float pan = info->pan;
    float vol = info->volume * ((snd_local_t *)*(snd_local_t **)imp_g_snd)->volume;

    if (((snd_local_t *)*(snd_local_t **)imp_g_snd)->chaninfo[index].srcChannelCount == 2) {
        AIL_set_sample_volume_levels(*(void **)(0x4a3ad4 + index * 4), vol, vol);
    } else {
        float leftVol = (1.0f - pan) * vol;
        float rightVol = pan * vol;
        AIL_set_sample_volume_levels(*(void **)(0x4a3ad4 + index * 4), leftVol, rightVol);
    }
}

/* line 411 */
Bool SND_InitDriver(void)
{
    int freq, khz, rate;
    int bits, bytes;
    int numChannels;
    const char *channelStr;
    byte *sndGlob;
    const char *wantedName;
    void *providerIter;
    void *handle;
    void *defaultHandle;
    void *wantedHandle;
    const char *name;
    int i;
    int sndKhzVal, sndBitsVal;
    unsigned int maxRate;

    /* Register mss_q3fs dvar */
    mss_q3fs = Dvar_RegisterBool((const char *)str_00219a94, 1, 0x1020);
    if (mss_q3fs->current.enabled != 0) {
        AIL_set_file_callbacks((void *)MSS_FileOpenCallback, (void *)MSS_FileCloseCallback, (void *)MSS_FileSeekCallback, (void *)MSS_FileReadCallback);
    }

    /* Initialize Miles */
    AIL_set_redist_directory((const char *)str_00219aa0);
    if (!AIL_startup(0x75)) {
        goto startup_failed;
    }

    /* Register 3D provider dvar */
    mss_3d_provider = Dvar_RegisterString((const char *)str_00219b04, (const char *)str_00219ae4, 0x1021);

    /* Read snd_khz */
    sndKhzVal = ((dvar_t *)*(void **)imp_snd_khz)->current.integer;
    switch (sndKhzVal) {
        case 0x2c: /* 44 khz */
            freq = 0xac44;
            khz = 0x2c;
            rate = 0xac44;
            break;
        case 0xb: /* 11 khz */
            freq = 0x2b11;
            khz = 0xb;
            rate = 0x2b11;
            break;
        case 0x16: /* 22 khz */
        default:
            if (sndKhzVal != 0x16) {
                Com_Printf((const char *)str_00219b14, sndKhzVal);
            }
            freq = 0x5622;
            khz = 0x16;
            rate = 0x5622;
            break;
    }

    /* Read snd_bits */
    sndBitsVal = ((dvar_t *)*(void **)imp_snd_bits)->current.integer;
    if (sndBitsVal == 8) {
        bytes = 1;
        bits = 8;
    } else {
        if (sndBitsVal != 0x10) {
            Com_Printf((const char *)str_00219b48, sndBitsVal);
        }
        bytes = 2;
        bits = 0x10;
    }

    /* Read snd_channels (stereo) */
    if (((dvar_t *)*(void **)imp_snd_stereo)->current.enabled != 0) {
        channelStr = (const char *)str_00219b90; /* "stereo" */
        numChannels = 2;
    } else {
        channelStr = (const char *)str_00219b98; /* "mono" */
        numChannels = 1;
    }

    /* Print format */
    Com_Printf((const char *)str_00219ba0, khz, bits, channelStr);

    /* Open digital driver */
    AIL_set_preference(1, 0x35);
    milesGlob.driver_2D = AIL_open_digital_driver(rate, bytes, numChannels, 0);

    if (milesGlob.driver_2D == NULL) {
        Com_Printf((const char *)str_00219bc4, AIL_last_error());
        goto shutdown_and_fail;
    }

    /* Configure sound globals */
    sndGlob = *(byte **)imp_g_snd;
    ((snd_local_t *)sndGlob)->Initialized2d = 1;
    ((snd_local_t *)sndGlob)->max_2D_channels = 8;
    ((snd_local_t *)sndGlob)->max_stream_channels = 0xd;

    /* Calculate max rate: min(freq + freq/2, 0x7fffffff) */
    maxRate = ((unsigned int)freq >> 1) + (unsigned int)freq;
    if (maxRate < 0xac44) {
        ((snd_local_t *)sndGlob)->playback_rate = (int)maxRate;
    } else {
        ((snd_local_t *)sndGlob)->playback_rate = 0x7fffffff;
    }
    ((snd_local_t *)sndGlob)->playback_bits = bits;
    ((snd_local_t *)sndGlob)->playback_channels = numChannels;
    ((snd_local_t *)sndGlob)->timescale = 1.0f;

    /* Enumerate 3D providers */
    wantedName = mss_3d_provider->current.string;
    Com_Printf((const char *)str_00219bec);
    providerIter = NULL;
    wantedHandle = NULL;
    defaultHandle = NULL;

    if (AIL_enumerate_3D_providers(&providerIter, &handle, &name)) {
        do {
            Com_Printf((const char *)str_002182fc, name);
            if (stricmp(name, wantedName) == 0) {
                wantedHandle = handle;
            }
            if (stricmp(name, (const char *)str_00219ae4) == 0) {
                defaultHandle = handle;
            }
            if (wantedHandle == NULL && defaultHandle == NULL) {
                wantedHandle = handle;
            }
        } while (AIL_enumerate_3D_providers(&providerIter, &handle, &name));
    }

    milesGlob.provider_3D = NULL;

    /* Try to open wanted provider */
    if (wantedHandle != NULL) {
        if (AIL_open_3D_provider(wantedHandle) != 0) {
            Com_Printf((const char *)str_00219c08, wantedName, AIL_last_error());
            /* provider stays NULL */
        } else {
            milesGlob.provider_3D = wantedHandle;
        }
    }

    /* If provider is open, skip to configure */
    if (milesGlob.provider_3D != NULL) {
        goto configure_provider;
    }

    /* If no default or default is same as wanted, fail */
    if (defaultHandle == NULL || defaultHandle == wantedHandle) {
        goto shutdown_and_fail;
    }

    /* Try default provider */
    if (wantedName[0] != 0) {
        if (stricmp(wantedName, (const char *)str_00219ae4) != 0) {
            Com_Printf((const char *)str_00219c2c, wantedName);
        }
    }

    if (AIL_open_3D_provider(defaultHandle) != 0) {
        Com_Printf((const char *)str_00219c08, (const char *)str_00219ae4, AIL_last_error());
        if (milesGlob.provider_3D == NULL) {
            goto shutdown_and_fail;
        }
    } else {
        milesGlob.provider_3D = defaultHandle;
        Dvar_SetString(mss_3d_provider, (const char *)str_00219ae4);
        if (milesGlob.provider_3D == NULL) {
            goto shutdown_and_fail;
        }
    }

configure_provider:
    /* Configure 3D provider */
    sndGlob = *(byte **)imp_g_snd;
    ((snd_local_t *)sndGlob)->Initialized3d = 1;
    AIL_3D_provider_attribute(milesGlob.provider_3D, (const char *)str_00219c6c, (void *)&((snd_local_t *)sndGlob)->max_3D_channels);
    if (((snd_local_t *)sndGlob)->max_3D_channels > 0x20) {
        ((snd_local_t *)sndGlob)->max_3D_channels = 0x20;
    }
    Com_Printf((const char *)str_00219c88, ((snd_local_t *)sndGlob)->max_3D_channels);
    {
        int distFactor = 0x3cd013a9;
        AIL_set_3D_distance_factor(milesGlob.provider_3D, *(float *)&distFactor);
    }
    AIL_set_3D_rolloff_factor(milesGlob.provider_3D, 0.0f);

    /* Allocate 2D sample handles */
    sndGlob = *(byte **)imp_g_snd;
    for (i = 0; i < ((snd_local_t *)sndGlob)->max_2D_channels; i++) {
        milesGlob.handle_2D[i] = AIL_allocate_sample_handle(milesGlob.driver_2D);
        if (milesGlob.handle_2D[i] == NULL) {
            Com_Error(1, (const char *)str_00219c9c, i + 1);
        }
    }

    /* Allocate 3D sample handles */
    sndGlob = *(byte **)imp_g_snd;
    for (i = 0; i < ((snd_local_t *)sndGlob)->max_3D_channels; i++) {
        *(void **)(0x4a3ba8 + i * 4) = AIL_allocate_3D_sample_handle(milesGlob.provider_3D);
        if (*(void **)(0x4a3ba8 + i * 4) == NULL) {
            Com_Error(1, (const char *)str_00219cd4, i + 1);
        }
    }

    sndGlob = *(byte **)imp_g_snd;
    ((snd_local_t *)sndGlob)->ambient_track = 2;
    return 1;

shutdown_and_fail:
    AIL_shutdown();
    memset(&milesGlob, 0, 0x130);

startup_failed:
    if (Dvar_GetInt((const char *)str_00219aa8) == 2) {
        return 0;
    }
    Com_Printf((const char *)str_00219ab8);
    return 0;
}

#if 0 /* original asm */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 411 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0x1020, 8(%esp)\n" /* line 419 */
        "movl $1, 4(%esp)\n"
        "movl $str_00219a94, (%esp)\n" /* "mss_q3fs" */
        "calll Dvar_RegisterBool_mac\n"
        "movl %eax, mss_q3fs\n"
        "cmpb $0, 8(%eax)\n" /* line 420 */
        "jne .Lf58d2a_000590f8\n"
        ".Lf58d2a_00058d5e:\n"
        "movl $str_00219aa0, (%esp)\n" /* line 424 */
        "calll AIL_set_redist_directory\n"
        "movl $0x75, (%esp)\n" /* line 391 */
        "calll AIL_startup\n"
        "testl %eax, %eax\n" /* line 435 */
        "je .Lf58d2a_000590d1\n"
        "movl $0x1021, 8(%esp)\n" /* line 445 */
        "movl $str_00219ae4, 4(%esp)\n" /* "Miles Fast 2D Positional Audio" */
        "movl $str_00219b04, (%esp)\n" /* "mss_3d_provider" */
        "calll Dvar_RegisterString_mac\n"
        "movl %eax, mss_3d_provider\n"
        "movl imp_snd_khz, %eax\n" /* line 219 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf58d2a_00058dd0\n"
        "cmpl $0x2c, %eax\n"
        "je .Lf58d2a_000591fc\n"
        "cmpl $0xb, %eax\n"
        "je .Lf58d2a_00059149\n"
        "movl %eax, 4(%esp)\n" /* line 228 */
        "movl $str_00219b14, (%esp)\n" /* "invalid value %i for snd_khz, using 22 khz instead
" */
        "calll Com_Printf\n"
        ".Lf58d2a_00058dd0:\n"
        "movl $0x5622, -0x38(%ebp)\n"
        "movl $0x16, -0x30(%ebp)\n"
        "movl $0x5622, -0x2c(%ebp)\n"
        ".Lf58d2a_00058de5:\n"
        "movl imp_snd_bits, %eax\n" /* line 235 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl $8, %eax\n"
        "je .Lf58d2a_000591ed\n"
        "cmpl $0x10, %eax\n"
        "je .Lf58d2a_00058e0d\n"
        "movl %eax, 4(%esp)\n" /* line 241 */
        "movl $str_00219b48, (%esp)\n" /* "invalid value %i for snd_bits (should be 8 or 16), using 16 " */
        "calll Com_Printf\n"
        ".Lf58d2a_00058e0d:\n"
        "movl $2, %edi\n"
        "movl $0x10, %esi\n"
        ".Lf58d2a_00058e17:\n"
        "movl imp_snd_stereo, %eax\n" /* line 248 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf58d2a_0005912b\n"
        "movl $str_00219b90, %eax\n" /* "stereo" */
        "movl $2, %ebx\n"
        ".Lf58d2a_00058e32:\n"
        "movl %eax, 0xc(%esp)\n" /* line 250 */
        "movl %esi, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00219ba0, (%esp)\n" /* "Attempting %i kHz %i bit %s sound
" */
        "calll Com_Printf\n"
        "movl $0x35, 4(%esp)\n" /* line 165 */
        "movl $1, (%esp)\n"
        "calll AIL_set_preference\n"
        "movl $0, 0xc(%esp)\n" /* line 166 */
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_open_digital_driver\n"
        "movl %eax, milesGlob\n" /* line 256 */
        "testl %eax, %eax\n" /* line 262 */
        "je .Lf58d2a_0005909b\n"
        "movl imp_g_snd, %ecx\n" /* line 267 */
        "movb $1, (%ecx)\n"
        "movl $8, 0x13c4(%ecx)\n" /* line 269 */
        "movl $0xd, 0x13cc(%ecx)\n" /* line 270 */
        "movl -0x38(%ebp), %edx\n" /* line 272 */
        "shrl $1, %edx\n"
        "addl -0x38(%ebp), %edx\n"
        "movl $0x7fffffff, %eax\n" /* line 274 */
        "cmpl $0xac44, %edx\n"
        "cmovll %edx, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl %esi, 8(%ecx)\n" /* line 275 */
        "movl %ebx, 0xc(%ecx)\n" /* line 276 */
        "movl $0x3f800000, 0x10(%ecx)\n" /* line 277 */
        "movl mss_3d_provider, %eax\n" /* line 455 */
        "movl 8(%eax), %esi\n" /* wantedName */
        /* { scope 1: provider, handle, defaultHandle, name */
        /* { scope 2 */
        "movl $str_00219bec, (%esp)\n" /* line 294 */
        "calll Com_Printf\n"
        "movl $0, -0x1c(%ebp)\n" /* line 298 | provider */
        "xorl %ebx, %ebx\n" /* wantedHandle */
        "movl $0, -0x34(%ebp)\n" /* defaultHandle */
        "leal -0x1c(%ebp), %edi\n" /* provider */
        ".Lf58d2a_00058ef3:\n"
        "leal -0x24(%ebp), %eax\n" /* line 299 | name */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* handle */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll AIL_enumerate_3D_providers\n"
        "testl %eax, %eax\n"
        "je .Lf58d2a_00058f7b\n"
        ".Lf58d2a_00058f0d:\n"
        "movl -0x24(%ebp), %eax\n" /* line 302 | name */
        "movl %eax, 4(%esp)\n"
        "movl $str_002182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        "movl %esi, 4(%esp)\n" /* line 304 */
        "movl -0x24(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf58d2a_00058f36\n"
        "movl -0x20(%ebp), %ebx\n" /* line 305 | handle, wantedHandle */
        ".Lf58d2a_00058f36:\n"
        "movl $str_00219ae4, 4(%esp)\n" /* line 306 */
        "movl -0x24(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf58d2a_00058f53\n"
        "movl -0x20(%ebp), %eax\n" /* line 307 | handle */
        "movl %eax, -0x34(%ebp)\n" /* defaultHandle */
        ".Lf58d2a_00058f53:\n"
        "testl %ebx, %ebx\n" /* line 309 | wantedHandle */
        "jne .Lf58d2a_00058ef3\n"
        "movl -0x34(%ebp), %eax\n" /* defaultHandle */
        "testl %eax, %eax\n"
        "jne .Lf58d2a_00058ef3\n"
        "movl -0x20(%ebp), %ebx\n" /* line 310 | handle, wantedHandle */
        "leal -0x24(%ebp), %eax\n" /* line 299 | name */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* handle */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll AIL_enumerate_3D_providers\n"
        "testl %eax, %eax\n"
        "jne .Lf58d2a_00058f0d\n"
        ".Lf58d2a_00058f7b:\n"
        "movl $0, milesGlob+4\n" /* line 314 */
        "testl %ebx, %ebx\n" /* line 315 | wantedHandle */
        "jne .Lf58d2a_000591d0\n"
        "movl milesGlob+4, %edx\n"
        ".Lf58d2a_00058f93:\n"
        "testl %edx, %edx\n" /* line 328 */
        "jne .Lf58d2a_00058ff2\n"
        "movl -0x34(%ebp), %edi\n" /* defaultHandle */
        "testl %edi, %edi\n"
        "je .Lf58d2a_000590b0\n"
        "cmpl -0x34(%ebp), %ebx\n" /* defaultHandle, wantedHandle */
        "je .Lf58d2a_000590b0\n"
        "cmpb $0, (%esi)\n" /* line 330 */
        "jne .Lf58d2a_000592a2\n"
        ".Lf58d2a_00058fb4:\n"
        "movl -0x34(%ebp), %eax\n" /* line 333 | defaultHandle */
        "movl %eax, (%esp)\n"
        "calll AIL_open_3D_provider\n"
        "testl %eax, %eax\n"
        "jne .Lf58d2a_00059216\n"
        "movl -0x34(%ebp), %eax\n" /* line 336 | defaultHandle */
        "movl %eax, milesGlob+4\n"
        "movl $str_00219ae4, 4(%esp)\n" /* line 337 */
        "movl mss_3d_provider, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl milesGlob+4, %edx\n"
        ".Lf58d2a_00058fea:\n"
        "testl %edx, %edx\n" /* line 345 */
        "je .Lf58d2a_000590b0\n"
        ".Lf58d2a_00058ff2:\n"
        "movl imp_g_snd, %ebx\n" /* line 348 | wantedHandle */
        "movb $1, 1(%ebx)\n" /* wantedHandle */
        "leal 0x13c8(%ebx), %eax\n" /* line 349 | wantedHandle */
        "movl %eax, 8(%esp)\n"
        "movl $str_00219c6c, 4(%esp)\n" /* "Maximum supported samples" */
        "movl %edx, (%esp)\n"
        "calll AIL_3D_provider_attribute\n"
        "cmpl $0x20, 0x13c8(%ebx)\n" /* line 350 | wantedHandle */
        "jg .Lf58d2a_0005913a\n"
        ".Lf58d2a_00059023:\n"
        "movl 0x13c8(%ebx), %eax\n" /* line 352 | wantedHandle */
        "movl %eax, 4(%esp)\n"
        "movl $str_00219c88, (%esp)\n" /* "%i max 3D channels
" */
        "calll Com_Printf\n"
        "movl $0x3cd013a9, 4(%esp)\n" /* line 354 */
        "movl milesGlob+4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_distance_factor\n"
        "movl $0, 4(%esp)\n" /* line 355 */
        "movl milesGlob+4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_rolloff_factor\n"
        /* } scope */
        /* } scope */
        "movl imp_g_snd, %eax\n" /* line 364 */
        "movl 0x13c4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf58d2a_0005919b\n"
        ".Lf58d2a_00059076:\n"
        "movl 0x13c8(%eax), %ecx\n" /* line 371 */
        "testl %ecx, %ecx\n"
        "jg .Lf58d2a_00059163\n"
        ".Lf58d2a_00059084:\n"
        "movl $2, 0x270(%eax)\n" /* line 381 */
        "movl $1, %eax\n"
        "addl $0x3c, %esp\n" /* line 466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf58d2a_0005909b:\n"
        "calll AIL_last_error\n" /* line 264 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00219bc4, (%esp)\n" /* "couldn't initialize 2D provider: %s
" */
        "calll Com_Printf\n"
        ".Lf58d2a_000590b0:\n"
        "calll AIL_shutdown\n" /* line 457 */
        "movl $0x130, 8(%esp)\n" /* line 407 */
        "movl $0, 4(%esp)\n"
        "movl $milesGlob, (%esp)\n"
        "calll memset\n"
        ".Lf58d2a_000590d1:\n"
        "movl $str_00219aa8, (%esp)\n" /* line 202 */
        "calll Dvar_GetInt\n"
        "cmpl $2, %eax\n"
        "je .Lf58d2a_00059121\n"
        "movl $str_00219ab8, (%esp)\n" /* line 205 */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "addl $0x3c, %esp\n" /* line 466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf58d2a_000590f8:\n"
        "movl $MSS_FileReadCallback, 0xc(%esp)\n" /* line 421 */
        "movl $MSS_FileSeekCallback, 8(%esp)\n"
        "movl $MSS_FileCloseCallback, 4(%esp)\n"
        "movl $MSS_FileOpenCallback, (%esp)\n"
        "calll AIL_set_file_callbacks\n"
        "jmp .Lf58d2a_00058d5e\n"
        ".Lf58d2a_00059121:\n"
        "xorl %eax, %eax\n" /* line 465 */
        "addl $0x3c, %esp\n" /* line 466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf58d2a_0005912b:\n"
        "movl $str_00219b98, %eax\n" /* line 248 */
        "movl $1, %ebx\n"
        "jmp .Lf58d2a_00058e32\n"
        /* { scope 1: provider, handle, defaultHandle, name */
        /* { scope 2 */
        ".Lf58d2a_0005913a:\n"
        "movl $0x20, 0x13c8(%ebx)\n" /* line 351 | wantedHandle */
        "jmp .Lf58d2a_00059023\n"
        /* } scope */
        /* } scope */
        ".Lf58d2a_00059149:\n"
        "movl $0x2b11, -0x38(%ebp)\n" /* line 219 */
        "movl $0xb, -0x30(%ebp)\n"
        "movl $0x2b11, -0x2c(%ebp)\n"
        "jmp .Lf58d2a_00058de5\n"
        ".Lf58d2a_00059163:\n"
        "xorl %ebx, %ebx\n" /* line 371 | wantedHandle */
        "movl $milesGlob+32, %edi\n"
        "movl imp_g_snd, %esi\n"
        ".Lf58d2a_00059170:\n"
        "movl milesGlob+4, %eax\n" /* line 373 */
        "movl %eax, (%esp)\n"
        "calll AIL_allocate_3D_sample_handle\n"
        "movl %eax, 8(%edi, %ebx, 4)\n"
        "testl %eax, %eax\n" /* line 374 */
        "je .Lf58d2a_0005923e\n"
        "addl $1, %ebx\n" /* wantedHandle */
        ".Lf58d2a_0005918c:\n"
        "movl %esi, %eax\n" /* line 371 */
        "cmpl %ebx, 0x13c8(%esi)\n" /* wantedHandle */
        "jg .Lf58d2a_00059170\n"
        "jmp .Lf58d2a_00059084\n"
        ".Lf58d2a_0005919b:\n"
        "xorl %ebx, %ebx\n" /* line 364 | wantedHandle */
        "movl $milesGlob, %esi\n"
        ".Lf58d2a_000591a2:\n"
        "movl milesGlob, %eax\n" /* line 366 */
        "movl %eax, (%esp)\n"
        "calll AIL_allocate_sample_handle\n"
        "movl %eax, 8(%esi, %ebx, 4)\n"
        "testl %eax, %eax\n" /* line 367 */
        "je .Lf58d2a_0005925e\n"
        "addl $1, %ebx\n" /* wantedHandle */
        ".Lf58d2a_000591be:\n"
        "movl imp_g_snd, %eax\n" /* line 364 */
        "cmpl 0x13c4(%eax), %ebx\n" /* wantedHandle */
        "jl .Lf58d2a_000591a2\n"
        "jmp .Lf58d2a_00059076\n"
        /* { scope 1: provider, handle, defaultHandle, name */
        /* { scope 2 */
        ".Lf58d2a_000591d0:\n"
        "movl %ebx, (%esp)\n" /* line 317 | wantedHandle */
        "calll AIL_open_3D_provider\n"
        "testl %eax, %eax\n"
        "jne .Lf58d2a_0005927e\n"
        "movl %ebx, milesGlob+4\n" /* line 320 | wantedHandle */
        "movl %ebx, %edx\n" /* wantedHandle */
        "jmp .Lf58d2a_00058f93\n"
        /* } scope */
        /* } scope */
        ".Lf58d2a_000591ed:\n"
        "movl $1, %edi\n" /* line 235 */
        "movl $8, %esi\n"
        "jmp .Lf58d2a_00058e17\n"
        ".Lf58d2a_000591fc:\n"
        "movl $0xac44, -0x38(%ebp)\n" /* line 219 */
        "movl $0x2c, -0x30(%ebp)\n"
        "movl $0xac44, -0x2c(%ebp)\n"
        "jmp .Lf58d2a_00058de5\n"
        /* { scope 1: provider, handle, defaultHandle, name */
        /* { scope 2 */
        ".Lf58d2a_00059216:\n"
        "calll AIL_last_error\n" /* line 341 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00219ae4, 4(%esp)\n" /* "Miles Fast 2D Positional Audio" */
        "movl $str_00219c08, (%esp)\n" /* "couldn't open 3D provider '%s': %s
" */
        "calll Com_Printf\n"
        "movl milesGlob+4, %edx\n"
        "jmp .Lf58d2a_00058fea\n"
        /* } scope */
        /* } scope */
        ".Lf58d2a_0005923e:\n"
        "addl $1, %ebx\n" /* line 375 | wantedHandle */
        "movl %ebx, 8(%esp)\n" /* wantedHandle */
        "movl $str_00219cd4, 4(%esp)\n" /* "MILES 3D sound sample allocation failed on channel %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf58d2a_0005918c\n"
        ".Lf58d2a_0005925e:\n"
        "addl $1, %ebx\n" /* line 368 | wantedHandle */
        "movl %ebx, 8(%esp)\n" /* wantedHandle */
        "movl $str_00219c9c, 4(%esp)\n" /* "MILES 2D sound sample allocation failed on channel %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf58d2a_000591be\n"
        /* { scope 1: provider, handle, defaultHandle, name */
        /* { scope 2 */
        ".Lf58d2a_0005927e:\n"
        "calll AIL_last_error\n" /* line 324 */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_00219c08, (%esp)\n" /* "couldn't open 3D provider '%s': %s
" */
        "calll Com_Printf\n"
        "movl milesGlob+4, %edx\n"
        "jmp .Lf58d2a_00058f93\n"
        ".Lf58d2a_000592a2:\n"
        "movl $str_00219ae4, 4(%esp)\n" /* line 330 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf58d2a_00058fb4\n"
        "movl %esi, 4(%esp)\n" /* line 331 */
        "movl $str_00219c2c, (%esp)\n" /* "trying to use 'Miles Fast 2D Positional Audio' instead of '%" */
        "calll Com_Printf\n"
        "jmp .Lf58d2a_00058fb4\n"
    );
}
#endif

/* line 1264 */
void SND_SetStreamChannelFromSaveInfo(int index, snd_save_stream_t *info)
{
    float pan = info->pan;
    float vol = info->volume * ((snd_local_t *)*(snd_local_t **)imp_g_snd)->volume;
    byte *sndGlob = *(byte **)imp_g_snd;
    if (((snd_local_t *)sndGlob)->chaninfo[index].srcChannelCount == 2) {
        const snd_alias_t *pA = ((snd_local_t *)sndGlob)->chaninfo[index].pAlias0;
        int ch = (pA->flags & 0x780) >> 7;
        if (!SND_IsAliasChannel3D(ch)) {
            AIL_set_stream_volume_levels(*(void **)(0x4a3ba8 + index * 4), vol, vol);
            return;
        }
    }
    {
        float leftVol = (1.0f - pan) * vol;
        float rightVol = pan * vol;
        AIL_set_stream_volume_levels(*(void **)(0x4a3ba8 + index * 4), leftVol, rightVol);
    }
}

/* line 1599 */
void SND_DriverPostUpdate(int frametime)
{
    void *rawHandle;
    float vol;
    int bufNum;

    rawHandle = milesGlob.raw.handle;
    if (rawHandle == NULL) {
        return;
    }

    vol = 0.5f * ((snd_local_t *)*(snd_local_t **)imp_g_snd)->volume;
    AIL_set_sample_volume_levels(rawHandle, vol, vol);

    if (milesGlob.raw.bufReady[milesGlob.raw.readBuf] == 0) {
        return;
    }

    bufNum = AIL_sample_buffer_ready(milesGlob.raw.handle);
    if (bufNum == -1) {
        return;
    }

    milesGlob.raw.sampleTime += (double)milesGlob.raw.bufSize * milesGlob.raw.bufRate;

    AIL_load_sample_buffer(milesGlob.raw.handle, bufNum,
        (void *)(milesGlob.raw.buf + milesGlob.raw.readBuf * milesGlob.raw.bufSize),
        milesGlob.raw.bufSize);

    milesGlob.raw.bufReady[milesGlob.raw.readBuf] = 0;
    milesGlob.raw.readBuf = (milesGlob.raw.readBuf + 1) % 32;
}
