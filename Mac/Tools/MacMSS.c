/* ASM dump from: MacMSS.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacSwap.h"
 */

extern const char str_00228dbc[]; /* "mac.sound.high.quality" */
__attribute__((used)) static const char *kHighQualityKey = str_00228dbc; /* 0x311480 */
static Boolean sHighQualityEngine; /* 0xceb304 */
static CSoundEngine *sSoundEngine; /* 0xceb300 */

/* Forward declarations for CSoundEngine/CSoundObject functions used by AIL wrappers */
void *CSoundEngine_GetSampleSound3D(CSoundEngine *engine, void *S);
void CSoundEngine_set_3D_rolloff_factor(CSoundEngine *engine, float factor);
void CSoundEngine_set_3D_distance_factor(CSoundEngine *engine, float factor);
void CSoundEngine_set_3D_position(CSoundEngine *engine, float X, float Y, float Z);
void CSoundEngine_get_3D_position(CSoundEngine *engine, float *X, float *Y, float *Z);
void CSoundObject_set_3D_sample_effects_level(void *obj, float effects_level);
void CSoundObject_get_3D_position(void *obj, float *X, float *Y, float *Z);

/* CSoundEngine forward declarations */
void CSoundEngine_UpdateAllSounds(CSoundEngine *engine);
int CSoundEngine_get_cpu_percent(CSoundEngine *engine);
void *CSoundEngine_NewSampleSound(CSoundEngine *engine);
void *CSoundEngine_NewSampleSound3D(CSoundEngine *engine);
void *CSoundEngine_GetSampleSound(CSoundEngine *engine, void *S);
void *CSoundEngine_GetStreamSound(CSoundEngine *engine, void *S);
void *CSoundEngine_NewStreamSound(CSoundEngine *engine, void *dig, const char *filename, long int stream_mem);
int CSoundEngine_mixer_count(CSoundEngine *engine);
int CSoundEngine_mixer_count_3D(CSoundEngine *engine);
void CSoundEngine_set_digital_master_room_type(CSoundEngine *engine, long int room_type);
void CSoundEngine_set_digital_master_reverb_levels(CSoundEngine *engine, float dry_level, float wet_level);
long int CSoundEngine_minimum_sample_buffer_size(CSoundEngine *engine, long int playback_rate, long int format);
long int CSoundEngine_size_processed_digital_audio(CSoundEngine *engine, long unsigned int dest_rate, long unsigned int dest_format);
long int CSoundEngine_process_digital_audio(CSoundEngine *engine, void *dest_buffer, long int dest_buffer_size, long unsigned int dest_rate, long unsigned int dest_format);
char *CSoundEngine_device_name(CSoundEngine *engine);
void CSoundEngine_set_3D_room_type(CSoundEngine *engine, long int room_type);

/* CSoundObject forward declarations */
void CSoundObject_Release(void *obj);
void CSoundObject_init_sample(void *obj);
void CSoundObject_set_sample_adpcm_block_size(void *obj, long unsigned int blocksize);
void CSoundObject_set_sample_address(void *obj, const void *start, long unsigned int len);
void CSoundObject_set_sample_type(void *obj, long int format, long unsigned int flags);
void CSoundObject_stop_sample(void *obj);
void CSoundObject_resume_sample(void *obj);
void CSoundObject_end_sample(void *obj);
void CSoundObject_set_sample_playback_rate(void *obj, long int playback_rate);
void CSoundObject_set_sample_volume_levels(void *obj, float left, float right);
void CSoundObject_set_sample_reverb_levels(void *obj, float dry, float wet);
void CSoundObject_set_sample_loop_count(void *obj, long int count);
long unsigned int CSoundObject_get_sample_status(void *obj);
long int CSoundObject_get_sample_playback_rate(void *obj);
void CSoundObject_get_sample_volume_pan(void *obj, float *vol, float *pan);
void CSoundObject_get_sample_volume_levels(void *obj, float *left, float *right);
long int CSoundObject_sample_buffer_ready(void *obj);
void CSoundObject_load_sample_buffer(void *obj, long unsigned int buff_num, const void *buffer, long unsigned int len);
long unsigned int CSoundObject_get_sample_position(void *obj);
void CSoundObject_set_sample_ms_position(void *obj, long int ms);
void CSoundObject_get_sample_ms_position(void *obj, long int *total, long int *current);
void CSoundObject_set_sample_volume(void *obj, float vol);
float CSoundObject_get_sample_volume(void *obj);
void CSoundObject_set_sample_position(void *obj, long unsigned int pos);
long unsigned int CSoundObject_get_sample_length(void *obj);
long int CSoundObject_set_sample_info(void *obj, const void *info);
int CSoundObject_Is3DSound(void *obj);
void CSoundObject_set_3D_position(void *obj, float X, float Y, float Z);
void CSoundObject_set_3D_sample_distances(void *obj, float max_dist, float min_dist);
void CSoundObject_set_file_callbacks(void *cb1, void *cb2, void *cb3, void *cb4);
void CSoundObject_get_stream_info(void *obj, long int *datarate, long int *sndtype, long int *length, long int *memory);
int CSoundObject_SampleBuffersEmpty(void *obj);

/* MacPreferences forward declaration */
void MacPreferences_PutBoolean(const char *key, int value);

long int AIL_startup(long unsigned int bus_count);
void AIL_shutdown(void);
long int AIL_set_preference(long unsigned int number, long int value);
char * AIL_last_error(void);
HDIGDRIVER AIL_open_digital_driver(long unsigned int frequency, long int bits, long int channel, long unsigned int flags);
char * AIL_set_redist_directory(const char *dir);
long int AIL_digital_CPU_percent(HDIGDRIVER dig);
HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER dig);
void AIL_release_sample_handle(HSAMPLE S);
void AIL_init_sample(HSAMPLE S);
void AIL_set_sample_adpcm_block_size(HSAMPLE S, long unsigned int blocksize);
void AIL_set_sample_address(HSAMPLE S, const void *start, long unsigned int len);
void AIL_set_sample_type(HSAMPLE S, long int format, long unsigned int flags);
void AIL_stop_sample(HSAMPLE S);
void AIL_resume_sample(HSAMPLE S);
void AIL_end_sample(HSAMPLE S);
void AIL_set_sample_playback_rate(HSAMPLE S, long int playback_rate);
void AIL_set_sample_volume_levels(HSAMPLE S, float left_level, float right_level);
void AIL_set_sample_reverb_levels(HSAMPLE S, float dry_level, float wet_level);
void AIL_set_sample_loop_count(HSAMPLE S, long int loop_count);
long unsigned int AIL_sample_status(HSAMPLE S);
long int AIL_sample_playback_rate(HSAMPLE S);
void AIL_sample_volume_pan(HSAMPLE S, float *volume, float *pan);
void AIL_sample_volume_levels(HSAMPLE S, float *left_level, float *right_level);
void AIL_set_digital_master_room_type(HDIGDRIVER dig, long int room_type);
void AIL_set_digital_master_reverb_levels(HDIGDRIVER dig, float dry_level, float wet_level);
long int AIL_minimum_sample_buffer_size(HDIGDRIVER dig, long int playback_rate, long int format);
long int AIL_sample_buffer_ready(HSAMPLE S);
void AIL_load_sample_buffer(HSAMPLE S, long unsigned int buff_num, const void *buffer, long unsigned int len);
long unsigned int AIL_sample_position(HSAMPLE S);
void AIL_set_sample_ms_position(HSAMPLE S, long int milliseconds);
void AIL_sample_ms_position(HSAMPLE S, long int *total_milliseconds, long int *current_milliseconds);
HSTREAM AIL_open_stream(HDIGDRIVER dig, const char *filename, long int stream_mem);
void AIL_close_stream(HSTREAM stream);
void AIL_pause_stream(HSTREAM stream, long int onoff);
void AIL_set_stream_volume_levels(HSTREAM S, float left_level, float right_level);
void AIL_set_stream_reverb_levels(HSTREAM S, float dry_level, float wet_level);
void AIL_stream_volume_pan(HSTREAM stream, float *volume, float *pan);
void AIL_stream_volume_levels(HSTREAM S, float *left_level, float *right_level);
void AIL_set_stream_playback_rate(HSTREAM stream, long int rate);
long int AIL_stream_playback_rate(HSTREAM stream);
void AIL_set_stream_loop_count(HSTREAM stream, long int count);
long int AIL_stream_status(HSTREAM stream);
void AIL_stream_info(HSTREAM stream, long int *datarate, long int *sndtype, long int *length, long int *memory);
void AIL_set_stream_ms_position(HSTREAM S, long int milliseconds);
void AIL_stream_ms_position(HSTREAM S, long int *total_milliseconds, long int *current_milliseconds);
long int AIL_is_3D_stream(HSTREAM S);
void AIL_set_3D_stream_position(HSTREAM S, float X, float Y, float Z);
void AIL_set_file_callbacks(AIL_file_open_callback opencb, AIL_file_close_callback closecb, AIL_file_seek_callback seekcb, AIL_file_read_callback readcb);
long int AIL_size_processed_digital_audio(long unsigned int dest_rate, long unsigned int dest_format, long int num_srcs, const AILMIXINFO *src);
long int AIL_process_digital_audio(void *dest_buffer, long int dest_buffer_size, long unsigned int dest_rate, long unsigned int dest_format, long int num_srcs, char * * (*src)());
long int AIL_enumerate_3D_providers(HPROENUM *next, HPROVIDER *dest, char * *name);
M3DRESULT AIL_open_3D_provider(HPROVIDER lib);
void AIL_close_3D_provider(HPROVIDER lib);
void AIL_3D_provider_attribute(HPROVIDER lib, const char *name, void *val);
H3DSAMPLE AIL_allocate_3D_sample_handle(HPROVIDER lib);
void AIL_stop_3D_sample(H3DSAMPLE S);
void AIL_resume_3D_sample(H3DSAMPLE S);
void AIL_end_3D_sample(H3DSAMPLE S);
long int AIL_set_3D_sample_info(H3DSAMPLE S, const AILSOUNDINFO *info);
void AIL_set_3D_sample_volume(H3DSAMPLE S, float volume);
void AIL_set_3D_sample_offset(H3DSAMPLE S, long unsigned int offset);
void AIL_set_3D_sample_playback_rate(H3DSAMPLE S, long int playback_rate);
void AIL_set_3D_sample_loop_count(H3DSAMPLE S, long unsigned int loops);
long unsigned int AIL_3D_sample_status(H3DSAMPLE S);
float AIL_3D_sample_volume(H3DSAMPLE S);
long unsigned int AIL_3D_sample_offset(H3DSAMPLE S);
long int AIL_3D_sample_playback_rate(H3DSAMPLE S);
long unsigned int AIL_3D_sample_length(H3DSAMPLE S);
void AIL_set_3D_room_type(HPROVIDER lib, long int room_type);
void AIL_set_3D_rolloff_factor(HPROVIDER lib, float factor);
void AIL_set_3D_distance_factor(HPROVIDER lib, float factor);
void AIL_set_3D_sample_distances(H3DSAMPLE S, float max_dist, float min_dist);
void AIL_set_3D_sample_effects_level(H3DSAMPLE S, float effects_level);
void AIL_set_3D_position(H3DPOBJECT obj, float X, float Y, float Z);
void AIL_3D_position(H3DPOBJECT obj, float *X, float *Y, float *Z);
long int AIL_WAV_info(const void *data, long int (*info)());

/* line 42 */
/* Skip macOS Core Audio engine init on Linux — return 0 to disable sound.
   Original code throws C++ exception from CSoundEngine constructor when no
   macOS audio units are found, and naked ASM lacks EH tables for unwinding. */
long int AIL_startup(long unsigned int bus_count)
{
    return 0;
}

#if 0 /* original naked ASM */
__attribute__((naked))
long int AIL_startup_original(long unsigned int bus_count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 42 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "xorl %eax, %eax\n" /* line 49 */
        "cmpb $0, sHighQualityEngine\n"
        "setne %al\n"
        "movl %eax, 4(%esp)\n"
        "movl kHighQualityKey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacPreferences_GetBoolean\n"
        "movb %al, sHighQualityEngine\n"
        "movl $0x1d8, (%esp)\n" /* line 51 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n"
        "movzbl sHighQualityEngine, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* bus_count */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CSoundEngine_CSoundEngine\n"
        "movl %ebx, sSoundEngine\n"
        ".Lf110af8_00110b51:\n"
        "xorl %eax, %eax\n" /* line 53 */
        "cmpl $0, sSoundEngine\n"
        "setne %al\n"
        "addl $0x10, %esp\n" /* line 60 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %esi\n"
        ".Lf110af8_00110b66:\n"
        "movl %esi, (%esp)\n" /* line 53 */
        "calll ___cxa_begin_catch\n"
        "movl $0, sSoundEngine\n" /* line 56 */
        "calll ___cxa_end_catch\n" /* line 53 */
        "jmp .Lf110af8_00110b51\n"
        "movl %eax, %esi\n"
        "movl %ebx, (%esp)\n" /* line 51 */
        "calll __ZdlPv\n"
        "jmp .Lf110af8_00110b66\n"
    );
}
#endif /* original naked ASM */

/* line 64 — C replacement from snd_mac.c */
void AIL_shutdown(void)
{
    if (!sSoundEngine)
        return;

    MacPreferences_PutBoolean(kHighQualityKey, sHighQualityEngine != 0);

    if (sSoundEngine)
    {
        /* vtable call: destructor */
        (*(void (**)(void *))((*(int **)sSoundEngine) + 1))(sSoundEngine);
    }
    sSoundEngine = 0;
}

/* line 78 — C replacement from snd_mac.c */
long int AIL_set_preference(long unsigned int number, long int value)
{
    return CSoundEngine_mixer_count(sSoundEngine);
}

/* line 91 — C replacement from snd_mac.c */
char * AIL_last_error(void)
{
    return str_00228dd4;
}

/* line 104 — C replacement from snd_mac.c */
HDIGDRIVER AIL_open_digital_driver(long unsigned int frequency, long int bits, long int channel, long unsigned int flags)
{
    return (HDIGDRIVER)0x4d444449; /* "IDMD" */
}

/* line 115 — C replacement from snd_mac.c */
char * AIL_set_redist_directory(const char *dir)
{
    return (char *)0x2157b8;
}

/* line 124 — C replacement from snd_mac.c */
long int AIL_digital_CPU_percent(HDIGDRIVER dig)
{
    CSoundEngine_UpdateAllSounds(sSoundEngine);
    return CSoundEngine_get_cpu_percent(sSoundEngine);
}

/* line 140 — C replacement from snd_mac.c */
HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER dig)
{
    return CSoundEngine_NewSampleSound(sSoundEngine);
}

/* line 149 — C replacement from snd_mac.c */
void AIL_release_sample_handle(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_Release(theSound);
}

/* line 160 — C replacement from snd_mac.c */
void AIL_init_sample(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_init_sample(theSound);
}

/* line 173 — C replacement from snd_mac.c */
void AIL_set_sample_adpcm_block_size(HSAMPLE S, long unsigned int blocksize)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_adpcm_block_size(theSound, blocksize);
}

/* line 186 — C replacement from snd_mac.c */
void AIL_set_sample_address(HSAMPLE S, const void *start, long unsigned int len)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_address(theSound, start, len);
}

/* line 199 — C replacement from snd_mac.c */
void AIL_set_sample_type(HSAMPLE S, long int format, long unsigned int flags)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_type(theSound, format, flags);
}

/* line 210 — C replacement from snd_mac.c */
void AIL_stop_sample(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0xc: stop */
        (*(void (**)(void *))(*((int **)theSound) + 3))(theSound);
    }
}

/* line 221 — C replacement from snd_mac.c */
void AIL_resume_sample(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x10: resume */
        (*(void (**)(void *))(*((int **)theSound) + 4))(theSound);
    }
}

/* line 232 — C replacement from snd_mac.c */
void AIL_end_sample(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x14: end */
        (*(void (**)(void *))(*((int **)theSound) + 5))(theSound);
    }
}

/* line 245 — C replacement from snd_mac.c */
void AIL_set_sample_playback_rate(HSAMPLE S, long int playback_rate)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x20: set_playback_rate */
        (*(void (**)(void *, long int))(*((int **)theSound) + 8))(theSound, playback_rate);
    }
}

/* line 258 — C replacement from snd_mac.c */
void AIL_set_sample_volume_levels(HSAMPLE S, float left_level, float right_level)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_volume_levels(theSound, left_level, right_level);
}

/* line 271 — C replacement from snd_mac.c */
void AIL_set_sample_reverb_levels(HSAMPLE S, float dry_level, float wet_level)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_reverb_levels(theSound, dry_level, wet_level);
}

/* line 283 — C replacement from snd_mac.c */
void AIL_set_sample_loop_count(HSAMPLE S, long int loop_count)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_loop_count(theSound, loop_count);
}

/* line 294 — C replacement from snd_mac.c */
long unsigned int AIL_sample_status(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        return CSoundObject_get_sample_status(theSound);
    return 1;
}

/* line 310 — C replacement from snd_mac.c */
long int AIL_sample_playback_rate(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        return CSoundObject_get_sample_playback_rate(theSound);
    return 0;
}

/* line 325 — C replacement from snd_mac.c */
void AIL_sample_volume_pan(HSAMPLE S, float *volume, float *pan)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_get_sample_volume_pan(theSound, volume, pan);
}

/* line 338 — C replacement from snd_mac.c */
void AIL_sample_volume_levels(HSAMPLE S, float *left_level, float *right_level)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_get_sample_volume_levels(theSound, left_level, right_level);
}

/* line 351 — C replacement from snd_mac.c */
void AIL_set_digital_master_room_type(HDIGDRIVER dig, long int room_type)
{
    CSoundEngine_set_digital_master_room_type(sSoundEngine, room_type);
}

/* line 363 — C replacement from snd_mac.c */
void AIL_set_digital_master_reverb_levels(HDIGDRIVER dig, float dry_level, float wet_level)
{
    CSoundEngine_set_digital_master_reverb_levels(sSoundEngine, dry_level, wet_level);
}

/* line 376 — C replacement from snd_mac.c */
long int AIL_minimum_sample_buffer_size(HDIGDRIVER dig, long int playback_rate, long int format)
{
    return CSoundEngine_minimum_sample_buffer_size(sSoundEngine, playback_rate, format);
}

/* line 385 — C replacement from snd_mac.c */
long int AIL_sample_buffer_ready(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        return CSoundObject_sample_buffer_ready(theSound);
    return -1;
}

/* line 403 — C replacement from snd_mac.c */
void AIL_load_sample_buffer(HSAMPLE S, long unsigned int buff_num, const void *buffer, long unsigned int len)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_load_sample_buffer(theSound, buff_num, buffer, len);
}

/* line 414 — C replacement from snd_mac.c */
long unsigned int AIL_sample_position(HSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
        return CSoundObject_get_sample_position(theSound);
    return 0;
}

/* line 430 — C replacement from snd_mac.c */
void AIL_set_sample_ms_position(HSAMPLE S, long int milliseconds)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x1c: set_ms_position */
        (*(void (**)(void *, long int))(*((int **)theSound) + 7))(theSound, milliseconds);
    }
}

/* line 443 — C replacement from snd_mac.c */
void AIL_sample_ms_position(HSAMPLE S, long int *total_milliseconds, long int *current_milliseconds)
{
    void *theSound = CSoundEngine_GetSampleSound(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x18: get_ms_position */
        (*(void (**)(void *, long int *, long int *))(*((int **)theSound) + 6))(theSound, total_milliseconds, current_milliseconds);
    }
}

/* line 456 — no C replacement, keeping ASM */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
HSTREAM AIL_open_stream(HDIGDRIVER dig, const char *filename, long int stream_mem)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 456 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* filename */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 462 | filename */
        "je .Lf111106_0011113d\n"
        "movl $str_00228de4, 4(%esp)\n" /* line 468 */
        "movl %esi, (%esp)\n" /* filename */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf111106_00111172\n"
        "movl $4, 4(%esp)\n" /* line 471 */
        "movl %esi, (%esp)\n" /* filename */
        "calll access\n"
        "testl %eax, %eax\n"
        "je .Lf111106_00111146\n"
        ".Lf111106_0011113d:\n"
        "xorl %eax, %eax\n" /* line 485 */
        /* } scope */
        ".Lf111106_0011113f:\n"
        "addl $0x10, %esp\n" /* line 491 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf111106_00111146:\n"
        "movl sSoundEngine, %eax\n" /* line 473 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_NewStreamSound\n"
        "movl %eax, %ebx\n" /* theSound */
        ".Lf111106_00111155:\n"
        "testl %ebx, %ebx\n" /* line 481 | theSound */
        "je .Lf111106_0011113d\n"
        "movl (%ebx), %eax\n" /* line 483 | theSound */
        "movl %esi, 4(%esp)\n" /* filename */
        "movl %ebx, (%esp)\n" /* theSound */
        "calll *0x28(%eax)\n"
        "testb %al, %al\n"
        "je .Lf111106_00111197\n"
        "movl %ebx, %eax\n" /* theSound */
        /* } scope */
        "addl $0x10, %esp\n" /* line 491 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf111106_00111172:\n"
        "movl $str_00228dec, 4(%esp)\n" /* line 476 */
        "movl %esi, (%esp)\n" /* filename */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf111106_0011113d\n"
        "movl sSoundEngine, %eax\n" /* line 478 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_NewSampleSound3D\n"
        "movl %eax, %ebx\n" /* theSound */
        "jmp .Lf111106_00111155\n"
        ".Lf111106_00111197:\n"
        "movl %ebx, (%esp)\n" /* line 485 | theSound */
        "calll CSoundObject_Release\n"
        "xorl %eax, %eax\n"
        "jmp .Lf111106_0011113f\n"
    );
}
#else
HSTREAM AIL_open_stream(HDIGDRIVER dig, const char *filename, long int stream_mem)
{
    return 0;
}
#endif

/* line 495 — C replacement from snd_mac.c */
void AIL_close_stream(HSTREAM stream)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, stream);
    if (theSound)
        CSoundObject_Release(theSound);
}

/* line 506 — C replacement from snd_mac.c */
void AIL_pause_stream(HSTREAM stream, long int onoff)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, stream);
    if (!theSound)
        return;

    if (onoff)
    {
        /* vtable call at offset 0xc: stop */
        (*(void (**)(void *))(*((int **)theSound) + 3))(theSound);
    }
    else
    {
        /* vtable call at offset 0x10: resume */
        (*(void (**)(void *))(*((int **)theSound) + 4))(theSound);
    }
}

/* line 527 — C replacement from snd_mac.c */
void AIL_set_stream_volume_levels(HSTREAM S, float left_level, float right_level)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_volume_levels(theSound, left_level, right_level);
}

/* line 540 — C replacement from snd_mac.c */
void AIL_set_stream_reverb_levels(HSTREAM S, float dry_level, float wet_level)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_reverb_levels(theSound, dry_level, wet_level);
}

/* line 551 — C replacement from snd_mac.c */
void AIL_stream_volume_pan(HSTREAM stream, float *volume, float *pan)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, stream);
    if (theSound)
        CSoundObject_get_sample_volume_pan(theSound, volume, pan);
}

/* line 564 — C replacement from snd_mac.c */
void AIL_stream_volume_levels(HSTREAM S, float *left_level, float *right_level)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_get_sample_volume_levels(theSound, left_level, right_level);
}

/* line 575 — C replacement from snd_mac.c */
void AIL_set_stream_playback_rate(HSTREAM stream, long int rate)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, stream);
    if (theSound)
    {
        /* vtable call at offset 0x20: set_playback_rate */
        (*(void (**)(void *, long int))(*((int **)theSound) + 8))(theSound, rate);
    }
}

/* line 586 — C replacement from snd_mac.c */
long int AIL_stream_playback_rate(HSTREAM stream)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, stream);
    if (theSound)
        return CSoundObject_get_sample_playback_rate(theSound);
    return 0;
}

/* line 601 — C replacement from snd_mac.c */
void AIL_set_stream_loop_count(HSTREAM stream, long int count)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, stream);
    if (theSound)
        CSoundObject_set_sample_loop_count(theSound, count);
}

/* line 612 — C replacement from snd_mac.c */
long int AIL_stream_status(HSTREAM stream)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, stream);
    if (theSound)
        return CSoundObject_get_sample_status(theSound);
    return 1;
}

/* line 628 — C replacement from snd_mac.c */
void AIL_stream_info(HSTREAM stream, long int *datarate, long int *sndtype, long int *length, long int *memory)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, stream);
    if (theSound)
    {
        CSoundObject_get_stream_info(theSound, datarate, sndtype, length, memory);
        return;
    }

    if (datarate)
        *datarate = 0;
    if (sndtype)
        *sndtype = 0;
    if (length)
        *length = 0;
    if (memory)
        *memory = 0;
}

/* line 662 — C replacement from snd_mac.c */
void AIL_set_stream_ms_position(HSTREAM S, long int milliseconds)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x1c: set_ms_position */
        (*(void (**)(void *, long int))(*((int **)theSound) + 7))(theSound, milliseconds);
    }
}

/* line 675 — C replacement from snd_mac.c */
void AIL_stream_ms_position(HSTREAM S, long int *total_milliseconds, long int *current_milliseconds)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x18: get_ms_position */
        (*(void (**)(void *, long int *, long int *))(*((int **)theSound) + 6))(theSound, total_milliseconds, current_milliseconds);
    }
}

/* line 686 — C replacement from snd_mac.c */
long int AIL_is_3D_stream(HSTREAM S)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, S);
    if (theSound)
        return (unsigned char)CSoundObject_Is3DSound(theSound);
    return 0;
}

/* line 705 — C replacement from snd_mac.c */
void AIL_set_3D_stream_position(HSTREAM S, float X, float Y, float Z)
{
    void *theSound = CSoundEngine_GetStreamSound(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_3D_position(theSound, X, Y, Z);
}

/* line 720 — C replacement from snd_mac.c */
void AIL_set_file_callbacks(AIL_file_open_callback opencb, AIL_file_close_callback closecb, AIL_file_seek_callback seekcb, AIL_file_read_callback readcb)
{
    CSoundObject_set_file_callbacks(opencb, closecb, seekcb, readcb);
}

/* line 912 — C replacement from snd_mac.c */
long int AIL_size_processed_digital_audio(long unsigned int dest_rate, long unsigned int dest_format, long int num_srcs, const AILMIXINFO *src)
{
    return CSoundEngine_size_processed_digital_audio(sSoundEngine, dest_rate, dest_format);
}

/* line 926 — C replacement from snd_mac.c */
long int AIL_process_digital_audio(void *dest_buffer, long int dest_buffer_size, long unsigned int dest_rate, long unsigned int dest_format, long int num_srcs, char * * (*src)())
{
    return CSoundEngine_process_digital_audio(sSoundEngine, dest_buffer, dest_buffer_size, dest_rate, dest_format);
}

/* line 938 — C replacement from snd_mac.c */
long int AIL_enumerate_3D_providers(HPROENUM *next, HPROVIDER *dest, char * *name)
{
    if (*next != 0)
        return 0;

    *next = 1;
    *dest = 0x4d504944; /* "DIPM" */
    *name = CSoundEngine_device_name(sSoundEngine);
    return 1;
}

/* line 960 — C replacement from snd_mac.c */
M3DRESULT AIL_open_3D_provider(HPROVIDER lib)
{
    return 0;
}

/* line 971 — C replacement from snd_mac.c */
void AIL_close_3D_provider(HPROVIDER lib)
{
    /* empty */
}

/* line 982 — C replacement from snd_mac.c */
void AIL_3D_provider_attribute(HPROVIDER lib, const char *name, void *val)
{
    *(int *)val = CSoundEngine_mixer_count_3D(sSoundEngine);
}

/* line 996 — C replacement from snd_mac.c */
H3DSAMPLE AIL_allocate_3D_sample_handle(HPROVIDER lib)
{
    return CSoundEngine_NewSampleSound3D(sSoundEngine);
}

/* line 1005 — C replacement from snd_mac.c */
void AIL_stop_3D_sample(H3DSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0xc: stop */
        (*(void (**)(void *))(*((int **)theSound) + 3))(theSound);
    }
}

/* line 1016 — C replacement from snd_mac.c */
void AIL_resume_3D_sample(H3DSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x10: resume */
        (*(void (**)(void *))(*((int **)theSound) + 4))(theSound);
    }
}

/* line 1027 — C replacement from snd_mac.c */
void AIL_end_3D_sample(H3DSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x14: end */
        (*(void (**)(void *))(*((int **)theSound) + 5))(theSound);
    }
}

/* line 1039 — C replacement from snd_mac.c */
long int AIL_set_3D_sample_info(H3DSAMPLE S, const AILSOUNDINFO *info)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (!theSound)
        return 0;

    CSoundObject_init_sample(theSound);
    return CSoundObject_set_sample_info(theSound, info);
}

/* line 1056 — C replacement from snd_mac.c */
void AIL_set_3D_sample_volume(H3DSAMPLE S, float volume)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_volume(theSound, volume);
}

/* line 1068 — C replacement from snd_mac.c */
void AIL_set_3D_sample_offset(H3DSAMPLE S, long unsigned int offset)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_position(theSound, offset);
}

/* line 1081 — C replacement from snd_mac.c */
void AIL_set_3D_sample_playback_rate(H3DSAMPLE S, long int playback_rate)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x20: set_playback_rate */
        (*(void (**)(void *, long int))(*((int **)theSound) + 8))(theSound, playback_rate);
    }
}

/* line 1093 — C replacement from snd_mac.c */
void AIL_set_3D_sample_loop_count(H3DSAMPLE S, long unsigned int loops)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_sample_loop_count(theSound, loops);
}

/* line 1104 — C replacement from snd_mac.c */
long unsigned int AIL_3D_sample_status(H3DSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        return CSoundObject_get_sample_status(theSound);
    return 1;
}

/* line 1120 — C replacement from snd_mac.c */
float AIL_3D_sample_volume(H3DSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        return CSoundObject_get_sample_volume(theSound);
    return 0.0f;
}

/* line 1135 — C replacement from snd_mac.c */
long unsigned int AIL_3D_sample_offset(H3DSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        return CSoundObject_get_sample_position(theSound);
    return 0;
}

/* line 1150 — C replacement from snd_mac.c */
long int AIL_3D_sample_playback_rate(H3DSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        return CSoundObject_get_sample_playback_rate(theSound);
    return 0;
}

/* line 1165 — C replacement from snd_mac.c */
long unsigned int AIL_3D_sample_length(H3DSAMPLE S)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        return CSoundObject_get_sample_length(theSound);
    return 0;
}

/* line 1181 — C replacement from snd_mac.c */
void AIL_set_3D_room_type(HPROVIDER lib, long int room_type)
{
    CSoundEngine_set_3D_room_type(sSoundEngine, room_type);
}

/* line 1191 — C replacement from snd_mac.c */
void AIL_set_3D_rolloff_factor(HPROVIDER lib, float factor)
{
    CSoundEngine_set_3D_rolloff_factor(sSoundEngine, factor);
}

/* line 1201 — C replacement from snd_mac.c */
void AIL_set_3D_distance_factor(HPROVIDER lib, float factor)
{
    CSoundEngine_set_3D_distance_factor(sSoundEngine, factor);
}

/* line 1212 — C replacement from snd_mac.c */
void AIL_set_3D_sample_distances(H3DSAMPLE S, float max_dist, float min_dist)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
    {
        /* vtable call at offset 0x24: set_distances */
        (*(void (**)(void *, float, float))(*((int **)theSound) + 9))(theSound, max_dist, min_dist);
    }
}

/* line 1225 — C replacement from snd_mac.c */
void AIL_set_3D_sample_effects_level(H3DSAMPLE S, float effects_level)
{
    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, S);
    if (theSound)
        CSoundObject_set_3D_sample_effects_level(theSound, effects_level);
}

/* line 1241 — C replacement from snd_mac.c */
void AIL_set_3D_position(H3DPOBJECT obj, float X, float Y, float Z)
{
    if (obj == (H3DPOBJECT)-1)
    {
        CSoundEngine_set_3D_position(sSoundEngine, X, Y, Z);
        return;
    }

    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, obj);
    if (theSound)
        CSoundObject_set_3D_position(theSound, X, Y, Z);
}

/* line 1262 — C replacement from snd_mac.c */
void AIL_3D_position(H3DPOBJECT obj, float *X, float *Y, float *Z)
{
    if (obj == (H3DPOBJECT)-1)
    {
        CSoundEngine_get_3D_position(sSoundEngine, X, Y, Z);
        return;
    }

    void *theSound = CSoundEngine_GetSampleSound3D(sSoundEngine, obj);
    if (theSound)
        CSoundObject_get_3D_position(theSound, X, Y, Z);
}

/* line 729 — no C replacement, keeping ASM */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
long int AIL_WAV_info(const void *data, long int (*info)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 729 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* info */
        /* { scope 1 */
        "cld\n" /* line 734 */
        "movl $9, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* info */
        "rep stosl %eax, %es:(%edi)\n"
        "movl 8(%ebp), %edx\n" /* line 736 | data */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf111a44_00111a5f:\n"
        "movl (%edx), %eax\n" /* line 50 */
        "bswapl %eax\n"
        /* } scope */
        "movl 4(%edx), %ebx\n" /* line 46 */
        "leal 8(%edx), %edi\n" /* line 746 */
        "cmpl $0x52494646, %eax\n" /* line 748 */
        "je .Lf111a44_00111afa\n"
        "ja .Lf111a44_00111a9c\n"
        "cmpl $0x4c495354, %eax\n"
        "je .Lf111a44_00111af2\n"
        "cmpl $0x50414420, %eax\n"
        "je .Lf111a44_00111b3c\n"
        "cmpl $0x4a554e4b, %eax\n"
        "je .Lf111a44_00111af2\n"
        /* } scope */
        ".Lf111a44_00111a8f:\n"
        "xorl %eax, %eax\n" /* line 740 */
        ".Lf111a44_00111a91:\n"
        "andl $1, %eax\n"
        /* } scope */
        "addl $0xc, %esp\n" /* line 904 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf111a44_00111a9c:\n"
        "cmpl $0x66616374, %eax\n" /* line 748 */
        "je .Lf111a44_00111af2\n"
        "cmpl $0x666d7420, %eax\n"
        "je .Lf111a44_00111b0e\n"
        "cmpl $0x64617461, %eax\n"
        "jne .Lf111a44_00111a8f\n"
        "movl 0x14(%esi), %eax\n" /* line 873 | info */
        "movl %eax, -0x18(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf111a44_00111a8f\n"
        "movl 0x10(%esi), %ecx\n" /* info */
        "testl %ecx, %ecx\n"
        "je .Lf111a44_00111a8f\n"
        "movl %edi, 4(%esi)\n" /* line 878 | info */
        "movl %ebx, 8(%esi)\n" /* line 879 | chunkSize, info */
        "movl %ebx, %eax\n" /* line 880 | chunkSize */
        "xorl %edx, %edx\n"
        "divl -0x18(%ebp)\n"
        "movl %ecx, %edi\n"
        "leal 7(%ecx), %ecx\n"
        "cmpl $-1, %edi\n"
        "cmovlel %ecx, %edi\n"
        "sarl $3, %edi\n"
        "xorl %edx, %edx\n"
        "divl %edi\n"
        "movl %eax, 0x18(%esi)\n" /* info */
        "movl $0, 0x20(%esi)\n" /* line 881 | info */
        "movl $1, %eax\n"
        "jmp .Lf111a44_00111a91\n"
        ".Lf111a44_00111af2:\n"
        "leal (%edi, %ebx), %edx\n" /* line 853 */
        "jmp .Lf111a44_00111a5f\n"
        ".Lf111a44_00111afa:\n"
        "movl 8(%edx), %eax\n" /* line 50 */
        "bswapl %eax\n"
        "addl $0xc, %edx\n" /* line 753 */
        "cmpl $0x57415645, %eax\n" /* line 755 */
        "jne .Lf111a44_00111a8f\n"
        "jmp .Lf111a44_00111a5f\n"
        ".Lf111a44_00111b0e:\n"
        "cmpl $0xf, %ebx\n" /* line 773 | chunkSize */
        "jbe .Lf111a44_00111a8f\n"
        /* { scope 3 */
        "movzwl 8(%edx), %eax\n" /* line 775 | format */
        "cmpw $1, %ax\n" /* line 776 */
        "je .Lf111a44_00111b56\n"
        "cmpw $0x11, %ax\n" /* line 800 */
        "je .Lf111a44_00111b81\n"
        "movl $1, %eax\n"
        ".Lf111a44_00111b2c:\n"
        "leal (%edi, %ebx), %edx\n" /* line 833 */
        /* } scope */
        /* } scope */
        "testb %al, %al\n" /* line 740 */
        "jne .Lf111a44_00111a8f\n"
        "jmp .Lf111a44_00111a5f\n"
        /* { scope 2 */
        ".Lf111a44_00111b3c:\n"
        "leal (%edi, %ebx), %edx\n" /* line 860 */
        "movl 4(%esi), %ebx\n" /* line 864 | info, chunkSize */
        "testl %ebx, %ebx\n" /* chunkSize */
        "jne .Lf111a44_00111a5f\n"
        "movl $0xffffffff, 4(%esi)\n" /* line 866 | info */
        "jmp .Lf111a44_00111a5f\n"
        /* { scope 3 */
        ".Lf111a44_00111b56:\n"
        "movzwl 0xc(%edi), %eax\n" /* line 780 */
        "movl %eax, -0x14(%ebp)\n"
        "movzwl 2(%edi), %edx\n"
        "movzwl 0xe(%edi), %eax\n"
        "movl 4(%edi), %ecx\n"
        "movl $1, (%esi)\n" /* line 794 | info */
        "movl %ecx, 0xc(%esi)\n" /* line 795 | info */
        "movl %eax, 0x10(%esi)\n" /* line 796 | info */
        "movl %edx, 0x14(%esi)\n" /* line 797 | info */
        "movl -0x14(%ebp), %eax\n" /* line 798 */
        "movl %eax, 0x1c(%esi)\n" /* info */
        "xorl %eax, %eax\n"
        "jmp .Lf111a44_00111b2c\n"
        ".Lf111a44_00111b81:\n"
        "movzwl 0xc(%edi), %edx\n" /* line 806 */
        "movl %edx, -0x10(%ebp)\n"
        "movzwl 2(%edi), %edx\n"
        "movzwl 0xe(%edi), %eax\n"
        "movl 4(%edi), %ecx\n"
        "movl $0x11, (%esi)\n" /* line 819 | info */
        "movl %ecx, 0xc(%esi)\n" /* line 820 | info */
        "movl %eax, 0x10(%esi)\n" /* line 821 | info */
        "movl %edx, 0x14(%esi)\n" /* line 822 | info */
        "movl -0x10(%ebp), %eax\n" /* line 823 */
        "movl %eax, 0x1c(%esi)\n" /* info */
        "xorl %eax, %eax\n"
        "jmp .Lf111a44_00111b2c\n"
    );
}
#else
long int AIL_WAV_info(const void *data, long int (*info)())
{
    return 0;
}
#endif
