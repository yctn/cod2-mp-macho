/* ASM dump from: MacMSS.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacSwap.h"
 */

extern const char *kHighQualityKey; /* 0x311480 */
static Boolean sHighQualityEngine; /* 0xceb304 */
static CSoundEngine *sSoundEngine; /* 0xceb300 */

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

/* line 64 */
__attribute__((naked))
void AIL_shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 64 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl sSoundEngine, %eax\n" /* line 66 */
        "testl %eax, %eax\n"
        "je .Lf110b8c_00110bd4\n"
        "xorl %eax, %eax\n" /* line 68 */
        "cmpb $0, sHighQualityEngine\n"
        "setne %al\n"
        "movl %eax, 4(%esp)\n"
        "movl kHighQualityKey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacPreferences_PutBoolean\n"
        "movl sSoundEngine, %edx\n" /* line 70 */
        "testl %edx, %edx\n"
        "je .Lf110b8c_00110bca\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf110b8c_00110bca:\n"
        "movl $0, sSoundEngine\n" /* line 71 */
        ".Lf110b8c_00110bd4:\n"
        "leave\n" /* line 73 */
        "retl\n"
    );
}

/* line 78 */
__attribute__((naked))
long int AIL_set_preference(long unsigned int number, long int value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 78 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 86 */
        "movl %eax, 8(%ebp)\n" /* number */
        "popl %ebp\n" /* line 87 */
        "jmp CSoundEngine_mixer_count\n" /* line 86 */
    );
}

/* line 91 */
__attribute__((naked))
char * AIL_last_error(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 91 */
        "movl %esp, %ebp\n"
        "movl $0x228dd4, %eax\n" /* line 95 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 104 */
__attribute__((naked))
HDIGDRIVER AIL_open_digital_driver(long unsigned int frequency, long int bits, long int channel, long unsigned int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "movl $0x4d444449, %eax\n" /* line 109 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 115 */
__attribute__((naked))
char * AIL_set_redist_directory(const char *dir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 115 */
        "movl %esp, %ebp\n"
        "movl $0x2157b8, %eax\n" /* line 120 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 124 */
__attribute__((naked))
long int AIL_digital_CPU_percent(HDIGDRIVER dig)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 124 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl sSoundEngine, %eax\n" /* line 129 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_UpdateAllSounds\n"
        "movl sSoundEngine, %eax\n" /* line 134 */
        "movl %eax, 8(%ebp)\n" /* dig */
        "leave\n" /* line 135 */
        "jmp CSoundEngine_get_cpu_percent\n" /* line 134 */
    );
}

/* line 140 */
__attribute__((naked))
HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER dig)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 140 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* dig */
        "popl %ebp\n" /* line 145 */
        "jmp CSoundEngine_NewSampleSound\n" /* line 144 */
    );
}

/* line 149 */
__attribute__((naked))
void AIL_release_sample_handle(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 149 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 151 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 152 */
        "je .Lf110c3a_00110c61\n"
        "movl %eax, 8(%ebp)\n" /* line 154 | S */
        /* } scope */
        "leave\n" /* line 156 */
        /* { scope 1 */
        "jmp CSoundObject_Release\n" /* line 154 */
        /* } scope */
        ".Lf110c3a_00110c61:\n"
        "leave\n" /* line 156 */
        "retl\n"
    );
}

/* line 160 */
__attribute__((naked))
void AIL_init_sample(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 160 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 162 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 163 */
        "je .Lf110c64_00110c8b\n"
        "movl %eax, 8(%ebp)\n" /* line 165 | S */
        /* } scope */
        "leave\n" /* line 167 */
        /* { scope 1 */
        "jmp CSoundObject_init_sample\n" /* line 165 */
        /* } scope */
        ".Lf110c64_00110c8b:\n"
        "leave\n" /* line 167 */
        "retl\n"
    );
}

/* line 173 */
__attribute__((naked))
void AIL_set_sample_adpcm_block_size(HSAMPLE S, long unsigned int blocksize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* blocksize */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 175 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 176 */
        "je .Lf110c8e_00110cc0\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 178 | blocksize */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x14, %esp\n" /* line 180 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_adpcm_block_size\n" /* line 178 */
        /* } scope */
        ".Lf110c8e_00110cc0:\n"
        "addl $0x14, %esp\n" /* line 180 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 186 */
__attribute__((naked))
void AIL_set_sample_address(HSAMPLE S, const void *start, long unsigned int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 186 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* start */
        "movl 0x10(%ebp), %ebx\n" /* len */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 188 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 189 */
        "je .Lf110cc6_00110d00\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 191 | len */
        "movl %esi, 0xc(%ebp)\n" /* start */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 193 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_address\n" /* line 191 */
        /* } scope */
        ".Lf110cc6_00110d00:\n"
        "addl $0x10, %esp\n" /* line 193 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 199 */
__attribute__((naked))
void AIL_set_sample_type(HSAMPLE S, long int format, long unsigned int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 199 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* format */
        "movl 0x10(%ebp), %ebx\n" /* flags */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 201 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 202 */
        "je .Lf110d08_00110d42\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 204 | flags */
        "movl %esi, 0xc(%ebp)\n" /* format */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 206 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_type\n" /* line 204 */
        /* } scope */
        ".Lf110d08_00110d42:\n"
        "addl $0x10, %esp\n" /* line 206 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 210 */
__attribute__((naked))
void AIL_stop_sample(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 212 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 213 */
        "je .Lf110d4a_00110d75\n"
        "movl (%eax), %eax\n" /* line 215 */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0xc(%eax), %ecx\n"
        /* } scope */
        "leave\n" /* line 217 */
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 215 */
        /* } scope */
        ".Lf110d4a_00110d75:\n"
        "leave\n" /* line 217 */
        "retl\n"
    );
}

/* line 221 */
__attribute__((naked))
void AIL_resume_sample(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 221 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 223 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 224 */
        "je .Lf110d78_00110da3\n"
        "movl (%eax), %eax\n" /* line 226 */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x10(%eax), %ecx\n"
        /* } scope */
        "leave\n" /* line 228 */
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 226 */
        /* } scope */
        ".Lf110d78_00110da3:\n"
        "leave\n" /* line 228 */
        "retl\n"
    );
}

/* line 232 */
__attribute__((naked))
void AIL_end_sample(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 232 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 234 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 235 */
        "je .Lf110da6_00110dd1\n"
        "movl (%eax), %eax\n" /* line 237 */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x14(%eax), %ecx\n"
        /* } scope */
        "leave\n" /* line 239 */
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 237 */
        /* } scope */
        ".Lf110da6_00110dd1:\n"
        "leave\n" /* line 239 */
        "retl\n"
    );
}

/* line 245 */
__attribute__((naked))
void AIL_set_sample_playback_rate(HSAMPLE S, long int playback_rate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 245 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* playback_rate */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 247 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 248 */
        "je .Lf110dd4_00110e0a\n"
        "movl (%eax), %eax\n" /* line 250 */
        "movl %ebx, 0xc(%ebp)\n" /* playback_rate */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x20(%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 252 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 250 */
        /* } scope */
        ".Lf110dd4_00110e0a:\n"
        "addl $0x14, %esp\n" /* line 252 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 258 */
__attribute__((naked))
void AIL_set_sample_volume_levels(HSAMPLE S, float left_level, float right_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 258 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* left_level */
        "movl 0x10(%ebp), %ebx\n" /* right_level */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 260 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 261 */
        "je .Lf110e10_00110e4a\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 263 | right_level */
        "movl %esi, 0xc(%ebp)\n" /* left_level */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 265 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_volume_levels\n" /* line 263 */
        /* } scope */
        ".Lf110e10_00110e4a:\n"
        "addl $0x10, %esp\n" /* line 265 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 271 */
__attribute__((naked))
void AIL_set_sample_reverb_levels(HSAMPLE S, float dry_level, float wet_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 271 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* dry_level */
        "movl 0x10(%ebp), %ebx\n" /* wet_level */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 273 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 274 */
        "je .Lf110e52_00110e8c\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 276 | wet_level */
        "movl %esi, 0xc(%ebp)\n" /* dry_level */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_reverb_levels\n" /* line 276 */
        /* } scope */
        ".Lf110e52_00110e8c:\n"
        "addl $0x10, %esp\n" /* line 278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 283 */
__attribute__((naked))
void AIL_set_sample_loop_count(HSAMPLE S, long int loop_count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 283 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* loop_count */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 285 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 286 */
        "je .Lf110e94_00110ec6\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 288 | loop_count */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x14, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_loop_count\n" /* line 288 */
        /* } scope */
        ".Lf110e94_00110ec6:\n"
        "addl $0x14, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 294 */
__attribute__((naked))
long unsigned int AIL_sample_status(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 294 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 296 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 297 */
        "je .Lf110ecc_00110ef3\n"
        "movl %eax, 8(%ebp)\n" /* line 299 | S */
        /* } scope */
        "leave\n" /* line 306 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_status\n" /* line 299 */
        /* } scope */
        ".Lf110ecc_00110ef3:\n"
        "movl $1, %eax\n" /* line 306 */
        "leave\n"
        "retl\n"
    );
}

/* line 310 */
__attribute__((naked))
long int AIL_sample_playback_rate(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 310 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 312 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf110efa_00110f21\n"
        "movl %eax, 8(%ebp)\n" /* line 315 | S */
        /* } scope */
        "leave\n" /* line 321 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_playback_rate\n" /* line 315 */
        /* } scope */
        ".Lf110efa_00110f21:\n"
        "xorl %eax, %eax\n" /* line 321 */
        "leave\n"
        "retl\n"
    );
}

/* line 325 */
__attribute__((naked))
void AIL_sample_volume_pan(HSAMPLE S, float *volume, float *pan)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 325 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* volume */
        "movl 0x10(%ebp), %ebx\n" /* pan */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 327 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 328 */
        "je .Lf110f26_00110f60\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 330 | pan */
        "movl %esi, 0xc(%ebp)\n" /* volume */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 332 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_get_sample_volume_pan\n" /* line 330 */
        /* } scope */
        ".Lf110f26_00110f60:\n"
        "addl $0x10, %esp\n" /* line 332 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 338 */
__attribute__((naked))
void AIL_sample_volume_levels(HSAMPLE S, float *left_level, float *right_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 338 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* left_level */
        "movl 0x10(%ebp), %ebx\n" /* right_level */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 340 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 341 */
        "je .Lf110f68_00110fa2\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 343 | right_level */
        "movl %esi, 0xc(%ebp)\n" /* left_level */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 345 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_get_sample_volume_levels\n" /* line 343 */
        /* } scope */
        ".Lf110f68_00110fa2:\n"
        "addl $0x10, %esp\n" /* line 345 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 351 */
__attribute__((naked))
void AIL_set_digital_master_room_type(HDIGDRIVER dig, long int room_type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 351 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 355 */
        "movl %eax, 8(%ebp)\n" /* dig */
        "popl %ebp\n" /* line 356 */
        "jmp CSoundEngine_set_digital_master_room_type\n" /* line 355 */
    );
}

/* line 363 */
__attribute__((naked))
void AIL_set_digital_master_reverb_levels(HDIGDRIVER dig, float dry_level, float wet_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 363 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 367 */
        "movl %eax, 8(%ebp)\n" /* dig */
        "popl %ebp\n" /* line 368 */
        "jmp CSoundEngine_set_digital_master_reverb_levels\n" /* line 367 */
    );
}

/* line 376 */
__attribute__((naked))
long int AIL_minimum_sample_buffer_size(HDIGDRIVER dig, long int playback_rate, long int format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 376 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 380 */
        "movl %eax, 8(%ebp)\n" /* dig */
        "popl %ebp\n" /* line 381 */
        "jmp CSoundEngine_minimum_sample_buffer_size\n" /* line 380 */
    );
}

/* line 385 */
__attribute__((naked))
long int AIL_sample_buffer_ready(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 385 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 387 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 388 */
        "je .Lf110fe0_00111007\n"
        "movl %eax, 8(%ebp)\n" /* line 390 | S */
        /* } scope */
        "leave\n" /* line 396 */
        /* { scope 1 */
        "jmp CSoundObject_sample_buffer_ready\n" /* line 390 */
        /* } scope */
        ".Lf110fe0_00111007:\n"
        "movl $0xffffffff, %eax\n" /* line 396 */
        "leave\n"
        "retl\n"
    );
}

/* line 403 */
__attribute__((naked))
void AIL_load_sample_buffer(HSAMPLE S, long unsigned int buff_num, const void *buffer, long unsigned int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 403 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* buff_num */
        "movl 0x10(%ebp), %esi\n" /* buffer */
        "movl 0x14(%ebp), %ebx\n" /* len */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 405 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 406 */
        "je .Lf11100e_00111050\n"
        "movl %ebx, 0x14(%ebp)\n" /* line 408 | len */
        "movl %esi, 0x10(%ebp)\n" /* buffer */
        "movl %edi, 0xc(%ebp)\n" /* buff_num */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 410 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_load_sample_buffer\n" /* line 408 */
        /* } scope */
        ".Lf11100e_00111050:\n"
        "addl $0x1c, %esp\n" /* line 410 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 414 */
__attribute__((naked))
long unsigned int AIL_sample_position(HSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 414 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 416 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound\n"
        "testl %eax, %eax\n" /* line 417 */
        "je .Lf111058_0011107f\n"
        "movl %eax, 8(%ebp)\n" /* line 419 | S */
        /* } scope */
        "leave\n" /* line 425 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_position\n" /* line 419 */
        /* } scope */
        ".Lf111058_0011107f:\n"
        "xorl %eax, %eax\n" /* line 425 */
        "leave\n"
        "retl\n"
    );
}

/* line 430 */
__attribute__((naked))
void AIL_set_sample_ms_position(HSAMPLE S, long int milliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 430 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* milliseconds */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 432 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 433 */
        "je .Lf111084_001110ba\n"
        "movl (%eax), %eax\n" /* line 435 */
        "movl %ebx, 0xc(%ebp)\n" /* milliseconds */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x1c(%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 437 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 435 */
        /* } scope */
        ".Lf111084_001110ba:\n"
        "addl $0x14, %esp\n" /* line 437 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 443 */
__attribute__((naked))
void AIL_sample_ms_position(HSAMPLE S, long int *total_milliseconds, long int *current_milliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 443 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* total_milliseconds */
        "movl 0x10(%ebp), %ebx\n" /* current_milliseconds */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 445 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 446 */
        "je .Lf1110c0_001110fe\n"
        "movl (%eax), %eax\n" /* line 448 */
        "movl %ebx, 0x10(%ebp)\n" /* current_milliseconds */
        "movl %esi, 0xc(%ebp)\n" /* total_milliseconds */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x18(%eax), %ecx\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 450 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 448 */
        /* } scope */
        ".Lf1110c0_001110fe:\n"
        "addl $0x10, %esp\n" /* line 450 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 456 */
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
        "movl $0x228de4, 4(%esp)\n" /* line 468 */
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
        "movl $0x228dec, 4(%esp)\n" /* line 476 */
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

/* line 495 */
__attribute__((naked))
void AIL_close_stream(HSTREAM stream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 495 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 497 | stream, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 498 */
        "je .Lf1111a4_001111cb\n"
        "movl %eax, 8(%ebp)\n" /* line 500 | stream */
        /* } scope */
        "leave\n" /* line 502 */
        /* { scope 1 */
        "jmp CSoundObject_Release\n" /* line 500 */
        /* } scope */
        ".Lf1111a4_001111cb:\n"
        "leave\n" /* line 502 */
        "retl\n"
    );
}

/* line 506 */
__attribute__((naked))
void AIL_pause_stream(HSTREAM stream, long int onoff)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 506 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* onoff */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 508 | stream */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetStreamSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 509 */
        "je .Lf1111ce_00111214\n"
        "testl %ebx, %ebx\n" /* line 512 | onoff */
        "je .Lf1111ce_00111205\n"
        "movl (%eax), %eax\n" /* line 518 */
        "movl %edx, 8(%ebp)\n" /* stream */
        "movl 0xc(%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 521 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 518 */
        ".Lf1111ce_00111205:\n"
        "movl (%eax), %eax\n" /* line 514 */
        "movl %edx, 8(%ebp)\n" /* stream */
        "movl 0x10(%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 521 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 514 */
        /* } scope */
        ".Lf1111ce_00111214:\n"
        "addl $0x14, %esp\n" /* line 521 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 527 */
__attribute__((naked))
void AIL_set_stream_volume_levels(HSTREAM S, float left_level, float right_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 527 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* left_level */
        "movl 0x10(%ebp), %ebx\n" /* right_level */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 529 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 530 */
        "je .Lf11121a_00111254\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 532 | right_level */
        "movl %esi, 0xc(%ebp)\n" /* left_level */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 534 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_volume_levels\n" /* line 532 */
        /* } scope */
        ".Lf11121a_00111254:\n"
        "addl $0x10, %esp\n" /* line 534 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 540 */
__attribute__((naked))
void AIL_set_stream_reverb_levels(HSTREAM S, float dry_level, float wet_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 540 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* dry_level */
        "movl 0x10(%ebp), %ebx\n" /* wet_level */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 542 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 543 */
        "je .Lf11125c_00111296\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 545 | wet_level */
        "movl %esi, 0xc(%ebp)\n" /* dry_level */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 547 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_reverb_levels\n" /* line 545 */
        /* } scope */
        ".Lf11125c_00111296:\n"
        "addl $0x10, %esp\n" /* line 547 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 551 */
__attribute__((naked))
void AIL_stream_volume_pan(HSTREAM stream, float *volume, float *pan)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 551 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* volume */
        "movl 0x10(%ebp), %ebx\n" /* pan */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 553 | stream, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 554 */
        "je .Lf11129e_001112d8\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 556 | pan */
        "movl %esi, 0xc(%ebp)\n" /* volume */
        "movl %eax, 8(%ebp)\n" /* stream */
        /* } scope */
        "addl $0x10, %esp\n" /* line 558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_get_sample_volume_pan\n" /* line 556 */
        /* } scope */
        ".Lf11129e_001112d8:\n"
        "addl $0x10, %esp\n" /* line 558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 564 */
__attribute__((naked))
void AIL_stream_volume_levels(HSTREAM S, float *left_level, float *right_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 564 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* left_level */
        "movl 0x10(%ebp), %ebx\n" /* right_level */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 566 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 567 */
        "je .Lf1112e0_0011131a\n"
        "movl %ebx, 0x10(%ebp)\n" /* line 569 | right_level */
        "movl %esi, 0xc(%ebp)\n" /* left_level */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 571 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_get_sample_volume_levels\n" /* line 569 */
        /* } scope */
        ".Lf1112e0_0011131a:\n"
        "addl $0x10, %esp\n" /* line 571 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 575 */
__attribute__((naked))
void AIL_set_stream_playback_rate(HSTREAM stream, long int rate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 575 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* rate */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 577 | stream */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetStreamSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 578 */
        "je .Lf111322_00111358\n"
        "movl (%eax), %eax\n" /* line 580 */
        "movl %ebx, 0xc(%ebp)\n" /* rate */
        "movl %edx, 8(%ebp)\n" /* stream */
        "movl 0x20(%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 582 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 580 */
        /* } scope */
        ".Lf111322_00111358:\n"
        "addl $0x14, %esp\n" /* line 582 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 586 */
__attribute__((naked))
long int AIL_stream_playback_rate(HSTREAM stream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 586 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 588 | stream, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 589 */
        "je .Lf11135e_00111385\n"
        "movl %eax, 8(%ebp)\n" /* line 591 | stream */
        /* } scope */
        "leave\n" /* line 597 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_playback_rate\n" /* line 591 */
        /* } scope */
        ".Lf11135e_00111385:\n"
        "xorl %eax, %eax\n" /* line 597 */
        "leave\n"
        "retl\n"
    );
}

/* line 601 */
__attribute__((naked))
void AIL_set_stream_loop_count(HSTREAM stream, long int count)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 601 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* count */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 603 | stream, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 604 */
        "je .Lf11138a_001113bc\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 606 | count */
        "movl %eax, 8(%ebp)\n" /* stream */
        /* } scope */
        "addl $0x14, %esp\n" /* line 608 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_loop_count\n" /* line 606 */
        /* } scope */
        ".Lf11138a_001113bc:\n"
        "addl $0x14, %esp\n" /* line 608 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 612 */
__attribute__((naked))
long int AIL_stream_status(HSTREAM stream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 612 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 614 | stream, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 615 */
        "je .Lf1113c2_001113e9\n"
        "movl %eax, 8(%ebp)\n" /* line 617 | stream */
        /* } scope */
        "leave\n" /* line 624 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_status\n" /* line 617 */
        /* } scope */
        ".Lf1113c2_001113e9:\n"
        "movl $1, %eax\n" /* line 624 */
        "leave\n"
        "retl\n"
    );
}

/* line 628 */
__attribute__((naked))
void AIL_stream_info(HSTREAM stream, long int *datarate, long int *sndtype, long int *length, long int *memory)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 628 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* datarate */
        "movl 0x10(%ebp), %esi\n" /* sndtype */
        "movl 0x14(%ebp), %edi\n" /* length */
        "movl 0x18(%ebp), %eax\n" /* memory, stream */
        "movl %eax, -0x1c(%ebp)\n" /* stream, memory */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 630 | stream, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 631 */
        "je .Lf1113f0_0011143e\n"
        "movl -0x1c(%ebp), %edx\n" /* line 633 | memory */
        "movl %edx, 0x18(%ebp)\n" /* memory */
        "movl %edi, 0x14(%ebp)\n" /* length */
        "movl %esi, 0x10(%ebp)\n" /* sndtype */
        "movl %ebx, 0xc(%ebp)\n" /* datarate */
        "movl %eax, 8(%ebp)\n" /* stream */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_get_stream_info\n" /* line 633 */
        ".Lf1113f0_0011143e:\n"
        "testl %ebx, %ebx\n" /* line 637 | datarate */
        "je .Lf1113f0_00111448\n"
        "movl $0, (%ebx)\n" /* line 639 | datarate */
        ".Lf1113f0_00111448:\n"
        "testl %esi, %esi\n" /* line 642 | sndtype */
        "je .Lf1113f0_00111452\n"
        "movl $0, (%esi)\n" /* line 644 | sndtype */
        ".Lf1113f0_00111452:\n"
        "testl %edi, %edi\n" /* line 647 | length */
        "je .Lf1113f0_0011145c\n"
        "movl $0, (%edi)\n" /* line 649 | length */
        ".Lf1113f0_0011145c:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 652 | memory */
        "testl %edx, %edx\n"
        "je .Lf1113f0_0011146c\n"
        "movl -0x1c(%ebp), %eax\n" /* line 654 | memory */
        "movl $0, (%eax)\n"
        /* } scope */
        ".Lf1113f0_0011146c:\n"
        "addl $0x2c, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 662 */
__attribute__((naked))
void AIL_set_stream_ms_position(HSTREAM S, long int milliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 662 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* milliseconds */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 664 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetStreamSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 665 */
        "je .Lf111474_001114aa\n"
        "movl (%eax), %eax\n" /* line 667 */
        "movl %ebx, 0xc(%ebp)\n" /* milliseconds */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x1c(%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 669 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 667 */
        /* } scope */
        ".Lf111474_001114aa:\n"
        "addl $0x14, %esp\n" /* line 669 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 675 */
__attribute__((naked))
void AIL_stream_ms_position(HSTREAM S, long int *total_milliseconds, long int *current_milliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 675 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* total_milliseconds */
        "movl 0x10(%ebp), %ebx\n" /* current_milliseconds */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 677 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetStreamSound\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 678 */
        "je .Lf1114b0_001114ee\n"
        "movl (%eax), %eax\n" /* line 680 */
        "movl %ebx, 0x10(%ebp)\n" /* current_milliseconds */
        "movl %esi, 0xc(%ebp)\n" /* total_milliseconds */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x18(%eax), %ecx\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 682 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 680 */
        /* } scope */
        ".Lf1114b0_001114ee:\n"
        "addl $0x10, %esp\n" /* line 682 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 686 */
__attribute__((naked))
long int AIL_is_3D_stream(HSTREAM S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 686 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 689 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 690 */
        "je .Lf1114f6_0011151f\n"
        "movl %eax, (%esp)\n" /* line 692 */
        "calll CSoundObject_Is3DSound\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lf1114f6_0011151f:\n"
        "leave\n" /* line 698 */
        "retl\n"
    );
}

/* line 705 */
__attribute__((naked))
void AIL_set_3D_stream_position(HSTREAM S, float X, float Y, float Z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 705 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* X */
        "movl 0x10(%ebp), %esi\n" /* Y */
        "movl 0x14(%ebp), %ebx\n" /* Z */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 708 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetStreamSound\n"
        "testl %eax, %eax\n" /* line 709 */
        "je .Lf111522_00111564\n"
        "movl %ebx, 0x14(%ebp)\n" /* line 711 | Z */
        "movl %esi, 0x10(%ebp)\n" /* Y */
        "movl %edi, 0xc(%ebp)\n" /* X */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 713 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_3D_position\n" /* line 711 */
        /* } scope */
        ".Lf111522_00111564:\n"
        "addl $0x1c, %esp\n" /* line 713 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 720 */
__attribute__((naked))
void AIL_set_file_callbacks(AIL_file_open_callback opencb, AIL_file_close_callback closecb, AIL_file_seek_callback seekcb, AIL_file_read_callback readcb)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 720 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 723 */
        "jmp CSoundObject_set_file_callbacks\n" /* line 722 */
    );
}

/* line 912 */
__attribute__((naked))
long int AIL_size_processed_digital_audio(long unsigned int dest_rate, long unsigned int dest_format, long int num_srcs, const AILMIXINFO *src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 912 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* line 915 | dest_format */
        "movl %eax, 0x10(%ebp)\n" /* num_srcs */
        "movl 8(%ebp), %eax\n" /* dest_rate */
        "movl %eax, 0xc(%ebp)\n" /* dest_format */
        "movl sSoundEngine, %eax\n"
        "movl %eax, 8(%ebp)\n" /* dest_rate */
        "popl %ebp\n" /* line 916 */
        "jmp CSoundEngine_size_processed_digital_audio\n" /* line 915 */
    );
}

/* line 926 */
__attribute__((naked))
long int AIL_process_digital_audio(void *dest_buffer, long int dest_buffer_size, long unsigned int dest_rate, long unsigned int dest_format, long int num_srcs, char * * (*src)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 926 */
        "movl %esp, %ebp\n"
        "movl 0x14(%ebp), %eax\n" /* line 929 | dest_format */
        "movl %eax, 0x18(%ebp)\n" /* num_srcs */
        "movl 0x10(%ebp), %eax\n" /* dest_rate */
        "movl %eax, 0x14(%ebp)\n" /* dest_format */
        "movl 0xc(%ebp), %eax\n" /* dest_buffer_size */
        "movl %eax, 0x10(%ebp)\n" /* dest_rate */
        "movl 8(%ebp), %eax\n" /* dest_buffer */
        "movl %eax, 0xc(%ebp)\n" /* dest_buffer_size */
        "movl sSoundEngine, %eax\n"
        "movl %eax, 8(%ebp)\n" /* dest_buffer */
        "popl %ebp\n" /* line 930 */
        "jmp CSoundEngine_process_digital_audio\n" /* line 929 */
    );
}

/* line 938 */
__attribute__((naked))
long int AIL_enumerate_3D_providers(HPROENUM *next, HPROVIDER *dest, char * *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 938 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* next */
        "movl (%eax), %ecx\n" /* line 944 */
        "testl %ecx, %ecx\n"
        "je .Lf1115be_001115d1\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 956 */
        "retl\n"
        ".Lf1115be_001115d1:\n"
        "movl $1, (%eax)\n" /* line 946 */
        "movl 0xc(%ebp), %eax\n" /* line 947 | dest */
        "movl $0x4d504944, (%eax)\n"
        "movl sSoundEngine, %eax\n" /* line 948 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_device_name\n"
        "movl 0x10(%ebp), %edx\n" /* name */
        "movl %eax, (%edx)\n"
        "movl $1, %eax\n"
        "leave\n" /* line 956 */
        "retl\n"
    );
}

/* line 960 */
__attribute__((naked))
M3DRESULT AIL_open_3D_provider(HPROVIDER lib)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 960 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 967 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 971 */
__attribute__((naked))
void AIL_close_3D_provider(HPROVIDER lib)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 971 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 976 */
        "retl\n"
    );
}

/* line 982 */
__attribute__((naked))
void AIL_3D_provider_attribute(HPROVIDER lib, const char *name, void *val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 982 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl sSoundEngine, %eax\n" /* line 988 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_mixer_count_3D\n"
        "movl 0x10(%ebp), %edx\n" /* val */
        "movl %eax, (%edx)\n"
        "leave\n" /* line 989 */
        "retl\n"
    );
}

/* line 996 */
__attribute__((naked))
H3DSAMPLE AIL_allocate_3D_sample_handle(HPROVIDER lib)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 996 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 1000 */
        "movl %eax, 8(%ebp)\n" /* lib */
        "popl %ebp\n" /* line 1001 */
        "jmp CSoundEngine_NewSampleSound3D\n" /* line 1000 */
    );
}

/* line 1005 */
__attribute__((naked))
void AIL_stop_3D_sample(H3DSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1005 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1007 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound3D\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 1008 */
        "je .Lf111634_0011165f\n"
        "movl (%eax), %eax\n" /* line 1010 */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0xc(%eax), %ecx\n"
        /* } scope */
        "leave\n" /* line 1012 */
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 1010 */
        /* } scope */
        ".Lf111634_0011165f:\n"
        "leave\n" /* line 1012 */
        "retl\n"
    );
}

/* line 1016 */
__attribute__((naked))
void AIL_resume_3D_sample(H3DSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1016 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1018 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound3D\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 1019 */
        "je .Lf111662_0011168d\n"
        "movl (%eax), %eax\n" /* line 1021 */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x10(%eax), %ecx\n"
        /* } scope */
        "leave\n" /* line 1023 */
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 1021 */
        /* } scope */
        ".Lf111662_0011168d:\n"
        "leave\n" /* line 1023 */
        "retl\n"
    );
}

/* line 1027 */
__attribute__((naked))
void AIL_end_3D_sample(H3DSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1027 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1029 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound3D\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 1030 */
        "je .Lf111690_001116bb\n"
        "movl (%eax), %eax\n" /* line 1032 */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x14(%eax), %ecx\n"
        /* } scope */
        "leave\n" /* line 1034 */
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 1032 */
        /* } scope */
        ".Lf111690_001116bb:\n"
        "leave\n" /* line 1034 */
        "retl\n"
    );
}

/* line 1039 */
__attribute__((naked))
long int AIL_set_3D_sample_info(H3DSAMPLE S, const AILSOUNDINFO *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1039 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* info */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1041 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound3D\n"
        "movl %eax, %ebx\n" /* theSound */
        "testl %eax, %eax\n" /* line 1042 */
        "je .Lf1116be_001116fc\n"
        "movl %eax, (%esp)\n" /* line 1044 */
        "calll CSoundObject_init_sample\n"
        "movl %esi, 0xc(%ebp)\n" /* line 1045 | info */
        "movl %ebx, 8(%ebp)\n" /* theSound, S */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1051 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_info\n" /* line 1045 */
        /* } scope */
        ".Lf1116be_001116fc:\n"
        "xorl %eax, %eax\n" /* line 1051 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1056 */
__attribute__((naked))
void AIL_set_3D_sample_volume(H3DSAMPLE S, float volume)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1056 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* volume */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1058 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1059 */
        "je .Lf111706_00111738\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 1061 | volume */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1063 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_volume\n" /* line 1061 */
        /* } scope */
        ".Lf111706_00111738:\n"
        "addl $0x14, %esp\n" /* line 1063 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1068 */
__attribute__((naked))
void AIL_set_3D_sample_offset(H3DSAMPLE S, long unsigned int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1068 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* offset */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1070 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1071 */
        "je .Lf11173e_00111770\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 1073 | offset */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1075 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_position\n" /* line 1073 */
        /* } scope */
        ".Lf11173e_00111770:\n"
        "addl $0x14, %esp\n" /* line 1075 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1081 */
__attribute__((naked))
void AIL_set_3D_sample_playback_rate(H3DSAMPLE S, long int playback_rate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1081 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* playback_rate */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1083 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound3D\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 1084 */
        "je .Lf111776_001117ac\n"
        "movl (%eax), %eax\n" /* line 1086 */
        "movl %ebx, 0xc(%ebp)\n" /* playback_rate */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x20(%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1088 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 1086 */
        /* } scope */
        ".Lf111776_001117ac:\n"
        "addl $0x14, %esp\n" /* line 1088 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1093 */
__attribute__((naked))
void AIL_set_3D_sample_loop_count(H3DSAMPLE S, long unsigned int loops)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1093 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* loops */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1095 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1096 */
        "je .Lf1117b2_001117e4\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 1098 | loops */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1100 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_sample_loop_count\n" /* line 1098 */
        /* } scope */
        ".Lf1117b2_001117e4:\n"
        "addl $0x14, %esp\n" /* line 1100 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1104 */
__attribute__((naked))
long unsigned int AIL_3D_sample_status(H3DSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1104 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1106 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1107 */
        "je .Lf1117ea_00111811\n"
        "movl %eax, 8(%ebp)\n" /* line 1109 | S */
        /* } scope */
        "leave\n" /* line 1116 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_status\n" /* line 1109 */
        /* } scope */
        ".Lf1117ea_00111811:\n"
        "movl $1, %eax\n" /* line 1116 */
        "leave\n"
        "retl\n"
    );
}

/* line 1120 */
__attribute__((naked))
float AIL_3D_sample_volume(H3DSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1120 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1122 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1123 */
        "je .Lf111818_0011183f\n"
        "movl %eax, 8(%ebp)\n" /* line 1125 | S */
        /* } scope */
        "leave\n" /* line 1131 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_volume\n" /* line 1125 */
        ".Lf111818_0011183f:\n"
        "fldz\n" /* line 1123 */
        /* } scope */
        "leave\n" /* line 1131 */
        "retl\n"
    );
}

/* line 1135 */
__attribute__((naked))
long unsigned int AIL_3D_sample_offset(H3DSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1135 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1137 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1138 */
        "je .Lf111844_0011186b\n"
        "movl %eax, 8(%ebp)\n" /* line 1140 | S */
        /* } scope */
        "leave\n" /* line 1146 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_position\n" /* line 1140 */
        /* } scope */
        ".Lf111844_0011186b:\n"
        "xorl %eax, %eax\n" /* line 1146 */
        "leave\n"
        "retl\n"
    );
}

/* line 1150 */
__attribute__((naked))
long int AIL_3D_sample_playback_rate(H3DSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1150 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1152 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1153 */
        "je .Lf111870_00111897\n"
        "movl %eax, 8(%ebp)\n" /* line 1155 | S */
        /* } scope */
        "leave\n" /* line 1161 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_playback_rate\n" /* line 1155 */
        /* } scope */
        ".Lf111870_00111897:\n"
        "xorl %eax, %eax\n" /* line 1161 */
        "leave\n"
        "retl\n"
    );
}

/* line 1165 */
__attribute__((naked))
long unsigned int AIL_3D_sample_length(H3DSAMPLE S)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1165 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1167 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1168 */
        "je .Lf11189c_001118c3\n"
        "movl %eax, 8(%ebp)\n" /* line 1170 | S */
        /* } scope */
        "leave\n" /* line 1176 */
        /* { scope 1 */
        "jmp CSoundObject_get_sample_length\n" /* line 1170 */
        /* } scope */
        ".Lf11189c_001118c3:\n"
        "xorl %eax, %eax\n" /* line 1176 */
        "leave\n"
        "retl\n"
    );
}

/* line 1181 */
__attribute__((naked))
void AIL_set_3D_room_type(HPROVIDER lib, long int room_type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1181 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 1185 */
        "movl %eax, 8(%ebp)\n" /* lib */
        "popl %ebp\n" /* line 1186 */
        "jmp CSoundEngine_set_3D_room_type\n" /* line 1185 */
    );
}

/* line 1191 */
__attribute__((naked))
void AIL_set_3D_rolloff_factor(HPROVIDER lib, float factor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1191 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 1195 */
        "movl %eax, 8(%ebp)\n" /* lib */
        "popl %ebp\n" /* line 1196 */
        "jmp CSoundEngine_set_3D_rolloff_factor\n" /* line 1195 */
    );
}

/* line 1201 */
__attribute__((naked))
void AIL_set_3D_distance_factor(HPROVIDER lib, float factor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1201 */
        "movl %esp, %ebp\n"
        "movl sSoundEngine, %eax\n" /* line 1205 */
        "movl %eax, 8(%ebp)\n" /* lib */
        "popl %ebp\n" /* line 1206 */
        "jmp CSoundEngine_set_3D_distance_factor\n" /* line 1205 */
    );
}

/* line 1212 */
__attribute__((naked))
void AIL_set_3D_sample_distances(H3DSAMPLE S, float max_dist, float min_dist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1212 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* max_dist */
        "movl 0x10(%ebp), %ebx\n" /* min_dist */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1214 | S */
        "movl %eax, 4(%esp)\n"
        "movl sSoundEngine, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetSampleSound3D\n"
        "movl %eax, %edx\n" /* theSound */
        "testl %eax, %eax\n" /* line 1215 */
        "je .Lf1118fe_0011193c\n"
        "movl (%eax), %eax\n" /* line 1217 */
        "movl %ebx, 0x10(%ebp)\n" /* min_dist */
        "movl %esi, 0xc(%ebp)\n" /* max_dist */
        "movl %edx, 8(%ebp)\n" /* S */
        "movl 0x24(%eax), %ecx\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1219 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 1217 */
        /* } scope */
        ".Lf1118fe_0011193c:\n"
        "addl $0x10, %esp\n" /* line 1219 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1225 */
__attribute__((naked))
void AIL_set_3D_sample_effects_level(H3DSAMPLE S, float effects_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1225 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* effects_level */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1227 | S, theSound */
        "movl %eax, 4(%esp)\n" /* theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1228 */
        "je .Lf111944_00111976\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 1230 | effects_level */
        "movl %eax, 8(%ebp)\n" /* S */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1232 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_3D_sample_effects_level\n" /* line 1230 */
        /* } scope */
        ".Lf111944_00111976:\n"
        "addl $0x14, %esp\n" /* line 1232 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1241 */
__attribute__((naked))
void AIL_set_3D_position(H3DPOBJECT obj, float X, float Y, float Z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1241 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* obj */
        "movl 0xc(%ebp), %edi\n" /* X */
        "movl 0x10(%ebp), %esi\n" /* Y */
        "movl 0x14(%ebp), %ebx\n" /* Z */
        "cmpl $-1, %eax\n" /* line 1243 */
        "je .Lf11197c_001119c3\n"
        /* { scope 1 */
        "movl %eax, 4(%esp)\n" /* line 1249 | theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1250 */
        "je .Lf11197c_001119d7\n"
        "movl %ebx, 0x14(%ebp)\n" /* line 1252 | Z */
        "movl %esi, 0x10(%ebp)\n" /* Y */
        "movl %edi, 0xc(%ebp)\n" /* X */
        "movl %eax, 8(%ebp)\n" /* obj */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1255 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_set_3D_position\n" /* line 1252 */
        /* } scope */
        ".Lf11197c_001119c3:\n"
        "movl sSoundEngine, %eax\n" /* line 1245 */
        "movl %eax, 8(%ebp)\n" /* obj */
        "addl $0x1c, %esp\n" /* line 1255 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CSoundEngine_set_3D_position\n" /* line 1245 */
        ".Lf11197c_001119d7:\n"
        "addl $0x1c, %esp\n" /* line 1255 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1262 */
__attribute__((naked))
void AIL_3D_position(H3DPOBJECT obj, float *X, float *Y, float *Z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1262 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* obj */
        "movl 0xc(%ebp), %edi\n" /* X */
        "movl 0x10(%ebp), %esi\n" /* Y */
        "movl 0x14(%ebp), %ebx\n" /* Z */
        "cmpl $-1, %eax\n" /* line 1268 */
        "je .Lf1119e0_00111a27\n"
        /* { scope 1 */
        "movl %eax, 4(%esp)\n" /* line 1274 | theSound */
        "movl sSoundEngine, %eax\n" /* theSound */
        "movl %eax, (%esp)\n" /* theSound */
        "calll CSoundEngine_GetSampleSound3D\n"
        "testl %eax, %eax\n" /* line 1275 */
        "je .Lf1119e0_00111a3b\n"
        "movl %ebx, 0x14(%ebp)\n" /* line 1277 | Z */
        "movl %esi, 0x10(%ebp)\n" /* Y */
        "movl %edi, 0xc(%ebp)\n" /* X */
        "movl %eax, 8(%ebp)\n" /* obj */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1280 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CSoundObject_get_3D_position\n" /* line 1277 */
        /* } scope */
        ".Lf1119e0_00111a27:\n"
        "movl sSoundEngine, %eax\n" /* line 1270 */
        "movl %eax, 8(%ebp)\n" /* obj */
        "addl $0x1c, %esp\n" /* line 1280 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CSoundEngine_get_3D_position\n" /* line 1270 */
        ".Lf1119e0_00111a3b:\n"
        "addl $0x1c, %esp\n" /* line 1280 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 729 */
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

