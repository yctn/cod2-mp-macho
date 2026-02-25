/* ASM dump from: MacMSS_Object.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS_Object.cp */

#include "common_types.h"
#include "imports.h"

extern AIL_file_open_callback CSoundObject_sOpenCallback; /* 0x0 */
extern AIL_file_close_callback CSoundObject_sCloseCallback; /* 0x0 */
extern AIL_file_seek_callback CSoundObject_sSeekCallback; /* 0x0 */
extern AIL_file_read_callback CSoundObject_sReadCallback; /* 0x0 */

void ZN12CSoundObjectD2Ev(void); /* CSoundObject_~CSoundObject */
void ZN12CSoundObjectD1Ev(void); /* CSoundObject_~CSoundObject */
void ZN12CSoundObjectD0Ev(void); /* CSoundObject_~CSoundObject */
void CSoundObject_Release(const CSoundObject * _this);
Boolean CSoundObject_IsAvailable(const CSoundObject * _this);
UInt32 CSoundObject_GetSoundType(const CSoundObject * _this);
Boolean CSoundObject_Is3DSound(const CSoundObject * _this);
void CSoundObject_TheadIdle(const CSoundObject * _this);
void CSoundObject_set_sample_address(const CSoundObject * _this, const void *start, long unsigned int len);
void CSoundObject_set_sample_type(const CSoundObject * _this, long int format, long unsigned int flags);
void CSoundObject_set_sample_volume(const CSoundObject * _this, float volume);
void CSoundObject_stop_sample(const CSoundObject * _this);
void CSoundObject_resume_sample(const CSoundObject * _this);
void CSoundObject_end_sample(const CSoundObject * _this);
void CSoundObject_set_sample_adpcm_block_size(const CSoundObject * _this, long unsigned int blocksize);
float CSoundObject_get_sample_volume(const CSoundObject * _this);
void CSoundObject_get_sample_volume_levels(const CSoundObject * _this, float *left_level, float *right_level);
void CSoundObject_set_sample_volume_levels(const CSoundObject * _this, float left_level, float right_level);
void CSoundObject_get_sample_volume_pan(const CSoundObject * _this, float *volume, float *pan);
void CSoundObject_set_sample_reverb_levels(const CSoundObject * _this, float dry_level, float wet_level);
long unsigned int CSoundObject_get_sample_position(const CSoundObject * _this);
void CSoundObject_set_sample_position(const CSoundObject * _this, long unsigned int position);
long int CSoundObject_get_sample_playback_rate(const CSoundObject * _this);
void CSoundObject_set_sample_playback_rate(const CSoundObject * _this, long int playback_rate);
void CSoundObject_set_sample_loop_count(const CSoundObject * _this, long unsigned int loops);
long unsigned int CSoundObject_get_sample_status(const CSoundObject * _this);
long unsigned int CSoundObject_get_sample_length(const CSoundObject * _this);
long int CSoundObject_sample_buffer_ready(const CSoundObject * _this);
void CSoundObject_load_sample_buffer(const CSoundObject * _this, long unsigned int buff_num, const void *buffer, long unsigned int len);
void CSoundObject_set_3D_position(const CSoundObject * _this, float X, float Y, float Z);
void CSoundObject_get_3D_position(const CSoundObject * _this, float *X, float *Y, float *Z);
void CSoundObject_set_3D_sample_distances(const CSoundObject * _this, float max_dist, float min_dist);
void CSoundObject_set_3D_sample_effects_level(const CSoundObject * _this, float effects_level);
bool CSoundObject_open_stream(const CSoundObject * _this, const char *filename);
void CSoundObject_close_stream(const CSoundObject * _this);
void CSoundObject_get_stream_info(const CSoundObject * _this, long int *datarate, long int *sndtype, long int *length, long int *memory);
void CSoundObject_set_file_callbacks(AIL_file_open_callback opencb, AIL_file_close_callback closecb, AIL_file_seek_callback seekcb, AIL_file_read_callback readcb);
void CSoundObject_FormatToDescription(long int mssPlaybackRate, long int mssFormat, AudioStreamBasicDescription *outDescription);
bool CSoundObject_IsEqualDescriptions(const AudioStreamBasicDescription *inDesc1, const AudioStreamBasicDescription *inDesc2);
Boolean CSoundObject_SampleBuffersEmpty(const CSoundObject * _this);
void CSoundObject_ChangedVolume(const CSoundObject * _this);
void CSoundObject_ChangedFormat(const CSoundObject * _this);
void CSoundObject_Changed3DPosition(const CSoundObject * _this);
void CSoundObject_Changed3DDistances(const CSoundObject * _this);
long unsigned int CSoundObject_file_open_callback(const char *Filename, long unsigned int *FileHandle);
void CSoundObject_file_close_callback(long unsigned int FileHandle);
long int CSoundObject_file_seek_callback(long unsigned int FileHandle, long int Offset, long unsigned int Type);
long unsigned int CSoundObject_file_read_callback(long unsigned int FileHandle, void *Buffer, long unsigned int Bytes);
void CSoundObject_CSoundObject(const CSoundObject * _this, CSoundEngine *inEngine, UInt32 inBusIndex);
void CSoundObject_get_sample_ms_position(const CSoundObject * _this, long int *total_milliseconds, long int *current_milliseconds);
void CSoundObject_set_sample_ms_position(const CSoundObject * _this, long int milliseconds);
void CSoundObject_init_sample(const CSoundObject * _this);
long int CSoundObject_set_sample_info(const CSoundObject * _this, const AILSOUNDINFO *info);

/* line 70 */
__attribute__((naked))
void ZN12CSoundObjectD2Ev(void) /* CSoundObject_~CSoundObject */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x332548, (%eax)\n"
        "addl $0x20, %eax\n" /* line 72 */
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp ZN6CMutexD1Ev\n"
    );
}

/* line 70 */
__attribute__((naked))
void ZN12CSoundObjectD1Ev(void) /* CSoundObject_~CSoundObject */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x332548, (%eax)\n"
        "addl $0x20, %eax\n" /* line 72 */
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp ZN6CMutexD1Ev\n"
    );
}

/* line 70 */
__attribute__((naked))
void ZN12CSoundObjectD0Ev(void) /* CSoundObject_~CSoundObject */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x332548, (%ebx)\n" /* this */
        "leal 0x20(%ebx), %eax\n" /* line 72 | this */
        "movl %eax, (%esp)\n"
        "calll ZN6CMutexD1Ev\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 77 */
__attribute__((naked))
void CSoundObject_Release(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl (%edi), %eax\n" /* line 79 | this */
        "movl %edi, (%esp)\n" /* this */
        "calll *0xc(%eax)\n"
        "movl (%edi), %eax\n" /* line 80 | this */
        "movl %edi, (%esp)\n" /* this */
        "calll *0x2c(%eax)\n"
        "movl %edi, %ebx\n" /* this */
        "movl $4, %esi\n"
        ".Lf13e678_0013e69b:\n"
        "movl 0x4c(%ebx), %eax\n" /* line 84 */
        "testl %eax, %eax\n"
        "je .Lf13e678_0013e6b1\n"
        "movl %eax, (%esp)\n" /* line 86 */
        "calll free\n"
        "movl $0, 0x4c(%ebx)\n" /* line 87 */
        ".Lf13e678_0013e6b1:\n"
        "addl $4, %ebx\n"
        "subl $1, %esi\n" /* line 82 */
        "jne .Lf13e678_0013e69b\n"
        "movl $0, 0x5c(%edi)\n" /* line 90 | this */
        "movb $1, 0xc(%edi)\n" /* line 92 | this */
        "addl $0x1c, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
Boolean CSoundObject_IsAvailable(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movzbl 0xc(%eax), %eax\n" /* this */
        "popl %ebp\n" /* line 109 */
        "retl\n"
    );
}

/* line 114 */
__attribute__((naked))
UInt32 CSoundObject_GetSoundType(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 114 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%eax), %eax\n" /* this */
        "popl %ebp\n" /* line 117 */
        "retl\n"
    );
}

/* line 122 */
__attribute__((naked))
Boolean CSoundObject_Is3DSound(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "cmpl $1, 0x10(%eax)\n"
        "sete %al\n" /* this */
        "movzbl %al, %eax\n" /* this */
        "popl %ebp\n" /* line 125 */
        "retl\n"
    );
}

/* line 130 */
__attribute__((naked))
void CSoundObject_TheadIdle(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 130 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 133 */
        "retl\n"
    );
}

/* line 274 */
__attribute__((naked))
void CSoundObject_set_sample_address(const CSoundObject * _this, const void *start, long unsigned int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 274 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x10(%ebp), %edi\n" /* len */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 276 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xc(%ebp), %eax\n" /* line 278 | start */
        "movl %eax, 0x84(%ebx)\n" /* this */
        "movl %edi, 0x94(%ebx)\n" /* line 279 | len, this */
        "movl %ebx, %eax\n" /* this */
        "movl $3, %edx\n"
        ".Lf13e6fe_0013e735:\n"
        "movl $0, 0x88(%eax)\n" /* line 283 */
        "movl $0, 0x98(%eax)\n" /* line 284 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 281 */
        "jne .Lf13e6fe_0013e735\n"
        "movl $0, 0xac(%ebx)\n" /* line 287 | this */
        "movl %edi, 0xb0(%ebx)\n" /* line 288 | len, this */
        "movb $0, 0x14(%ebx)\n" /* line 290 | this */
        "movl %esi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 310 */
__attribute__((naked))
void CSoundObject_set_sample_type(const CSoundObject * _this, long int format, long unsigned int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 310 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* format */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 315 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl %ebx, 0xa8(%esi)\n" /* line 317 | format, this */
        "je .Lf13e776_0013e7b9\n"
        "movl %ebx, 0xa8(%esi)\n" /* line 319 | format, this */
        "cmpl $0xa, %ebx\n" /* line 321 | format */
        "jbe .Lf13e776_0013e7c9\n"
        "movl $1, 0x1c(%esi)\n" /* line 349 | this */
        ".Lf13e776_0013e7b1:\n"
        "movl (%esi), %eax\n" /* line 353 | this */
        "movl %esi, (%esp)\n" /* this */
        "calll *0x34(%eax)\n"
        ".Lf13e776_0013e7b9:\n"
        "movl %edi, (%esp)\n" /* line 354 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 355 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13e776_0013e7c9:\n"
        "jmpl *0x302480(, %ebx, 4)\n" /* line 321 */
        "movl $4, 0x1c(%esi)\n" /* line 340 | this */
        "jmp .Lf13e776_0013e7b1\n"
        "movl $2, 0x1c(%esi)\n" /* line 336 | this */
        "jmp .Lf13e776_0013e7b1\n"
        "movl $8, 0x1c(%esi)\n" /* line 344 | this */
        "jmp .Lf13e776_0013e7b1\n"
        "movl %eax, %ebx\n" /* format */
        "movl %edi, (%esp)\n" /* line 354 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* format */
        "calll __Unwind_Resume\n"
    );
}

/* line 370 */
__attribute__((naked))
void CSoundObject_set_sample_volume(const CSoundObject * _this, float volume)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 370 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 372 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 374 | volume */
        "ucomiss 0x64(%ebx), %xmm0\n" /* this */
        "jp .Lf13e7fe_0013e828\n"
        "je .Lf13e7fe_0013e835\n"
        ".Lf13e7fe_0013e828:\n"
        "movss %xmm0, 0x64(%ebx)\n" /* line 376 | this */
        "movl (%ebx), %eax\n" /* line 378 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x30(%eax)\n"
        ".Lf13e7fe_0013e835:\n"
        "movl %esi, (%esp)\n" /* line 379 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 380 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 379 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 206 */
__attribute__((naked))
void CSoundObject_stop_sample(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 206 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 210 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl $4, 0x60(%ebx)\n" /* line 212 | this */
        "jne .Lf13e856_0013e880\n"
        "movl $8, 0x60(%ebx)\n" /* line 214 | this */
        ".Lf13e856_0013e880:\n"
        "movl %esi, (%esp)\n" /* line 215 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 216 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 221 */
__attribute__((naked))
void CSoundObject_resume_sample(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 221 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 226 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x60(%ebx), %eax\n" /* line 228 | this */
        "cmpl $2, %eax\n"
        "je .Lf13e890_0013e8c9\n"
        "cmpl $8, %eax\n"
        "je .Lf13e890_0013e8c9\n"
        "movl %esi, (%esp)\n" /* line 231 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 232 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13e890_0013e8c9:\n"
        "movl $4, 0x60(%ebx)\n" /* line 230 | this */
        "movl %esi, (%esp)\n" /* line 231 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 232 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 237 */
__attribute__((naked))
void CSoundObject_end_sample(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 237 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 241 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl $4, 0x60(%ebx)\n" /* line 243 | this */
        "jne .Lf13e8e0_0013e914\n"
        "movl $2, 0x60(%ebx)\n" /* line 245 | this */
        "movl $0, 0xac(%ebx)\n" /* line 247 | this */
        ".Lf13e8e0_0013e914:\n"
        "movl %esi, (%esp)\n" /* line 248 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 249 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 296 */
__attribute__((naked))
void CSoundObject_set_sample_adpcm_block_size(const CSoundObject * _this, long unsigned int blocksize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 296 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* blocksize */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 298 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl %edi, 0xa4(%ebx)\n" /* line 300 | blocksize, this */
        "je .Lf13e924_0013e95b\n"
        "movl %edi, 0xa4(%ebx)\n" /* line 302 | blocksize, this */
        "movl (%ebx), %eax\n" /* line 303 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x34(%eax)\n"
        ".Lf13e924_0013e95b:\n"
        "movl %esi, (%esp)\n" /* line 304 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 305 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 304 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 360 */
__attribute__((naked))
float CSoundObject_get_sample_volume(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 360 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "flds 0x64(%eax)\n"
        "popl %ebp\n" /* line 365 */
        "retl\n"
    );
}

/* line 385 */
__attribute__((naked))
void CSoundObject_get_sample_volume_levels(const CSoundObject * _this, float *left_level, float *right_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 385 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* left_level */
        "movl 0x10(%ebp), %ebx\n" /* right_level */
        "movl 0x68(%eax), %edx\n" /* line 389 */
        "movl %edx, (%ecx)\n"
        "movl 0x6c(%eax), %edx\n" /* line 390 */
        "movl %edx, (%ebx)\n" /* right_level */
        "testb $2, 0xa8(%eax)\n" /* line 392 */
        "jne .Lf13e98a_0013e9c6\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 394 | 0.5f */
        "movss (%ecx), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "mulss (%ebx), %xmm0\n" /* line 395 | right_level */
        "movss %xmm0, (%ebx)\n" /* right_level */
        ".Lf13e98a_0013e9c6:\n"
        "popl %ebx\n" /* line 397 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 402 */
__attribute__((naked))
void CSoundObject_set_sample_volume_levels(const CSoundObject * _this, float left_level, float right_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 402 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movss 0xc(%ebp), %xmm1\n" /* left_level */
        "movss 0x10(%ebp), %xmm2\n" /* right_level */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 404 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll StMutexLock_StMutexLock\n"
        "testb $2, 0xa8(%ebx)\n" /* line 406 | this */
        "movss -0x28(%ebp), %xmm1\n"
        "movss -0x38(%ebp), %xmm2\n"
        "jne .Lf13e9ca_0013ea16\n"
        "addss %xmm1, %xmm1\n" /* line 409 */
        "addss %xmm2, %xmm2\n" /* line 410 */
        ".Lf13e9ca_0013ea16:\n"
        "pxor %xmm3, %xmm3\n" /* line 413 */
        "ucomiss %xmm1, %xmm3\n"
        "ja .Lf13e9ca_0013ea73\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 417 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "ucomiss %xmm2, %xmm3\n" /* line 423 */
        "ja .Lf13e9ca_0013ea7b\n"
        ".Lf13e9ca_0013ea33:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 427 | 1.0f */
        "minss %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        ".Lf13e9ca_0013ea42:\n"
        "ucomiss 0x68(%ebx), %xmm1\n" /* line 433 | this */
        "jne .Lf13e9ca_0013ea52\n"
        "jp .Lf13e9ca_0013ea52\n"
        "ucomiss 0x6c(%ebx), %xmm2\n" /* this */
        "jp .Lf13e9ca_0013ea52\n"
        "je .Lf13e9ca_0013ea64\n"
        ".Lf13e9ca_0013ea52:\n"
        "movss %xmm1, 0x68(%ebx)\n" /* line 435 | this */
        "movss %xmm2, 0x6c(%ebx)\n" /* line 436 | this */
        "movl (%ebx), %eax\n" /* line 438 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x30(%eax)\n"
        ".Lf13e9ca_0013ea64:\n"
        "movl %esi, (%esp)\n" /* line 439 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 440 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13e9ca_0013ea73:\n"
        "movaps %xmm3, %xmm1\n" /* line 413 */
        "ucomiss %xmm2, %xmm3\n" /* line 423 */
        "jbe .Lf13e9ca_0013ea33\n"
        ".Lf13e9ca_0013ea7b:\n"
        "movaps %xmm3, %xmm2\n"
        "jmp .Lf13e9ca_0013ea42\n"
        "movl %eax, %ebx\n" /* this */
        "movl %esi, (%esp)\n" /* line 439 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 445 */
__attribute__((naked))
void CSoundObject_get_sample_volume_pan(const CSoundObject * _this, float *volume, float *pan)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 445 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* volume */
        "movl 0x10(%ebp), %ecx\n" /* pan */
        "testl %edx, %edx\n" /* line 449 */
        "je .Lf13ea92_0013eaa8\n"
        "movl 0x64(%ebx), %eax\n" /* line 451 | this */
        "movl %eax, (%edx)\n"
        ".Lf13ea92_0013eaa8:\n"
        "testl %ecx, %ecx\n" /* line 454 */
        "je .Lf13ea92_0013eab1\n"
        "movl 0x70(%ebx), %eax\n" /* line 456 | this */
        "movl %eax, (%ecx)\n"
        ".Lf13ea92_0013eab1:\n"
        "popl %ebx\n" /* line 458 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 463 */
__attribute__((naked))
void CSoundObject_set_sample_reverb_levels(const CSoundObject * _this, float dry_level, float wet_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 463 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 465 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xc(%ebp), %eax\n" /* line 467 | dry_level */
        "movl %eax, 0x74(%ebx)\n" /* this */
        "movl 0x10(%ebp), %eax\n" /* line 468 | wet_level */
        "movl %eax, 0x78(%ebx)\n" /* this */
        "movl %esi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 469 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 474 */
__attribute__((naked))
long unsigned int CSoundObject_get_sample_position(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 474 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 476 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xac(%esi), %esi\n" /* line 478 | this */
        "movl %ebx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 479 | this */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 484 */
__attribute__((naked))
void CSoundObject_set_sample_position(const CSoundObject * _this, long unsigned int position)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 484 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* position */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 486 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl %ebx, 0xac(%esi)\n" /* line 488 | position, this */
        "movl 0xa8(%esi), %eax\n" /* line 490 | this */
        "testb $1, %al\n"
        "je .Lf13eb20_0013eb6a\n"
        "andl $0xfffffffe, %ebx\n" /* line 492 | position */
        "movl %ebx, 0xac(%esi)\n" /* position, this */
        "movl %edi, (%esp)\n" /* line 503 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 504 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13eb20_0013eb6a:\n"
        "testb $8, %al\n" /* line 494 */
        "jne .Lf13eb20_0013eb84\n"
        "movl %ebx, 0xac(%esi)\n" /* line 502 | position, this */
        "movl %edi, (%esp)\n" /* line 503 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 504 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13eb20_0013eb84:\n"
        "leal 3(%ebx), %eax\n" /* line 498 | position */
        "andl $0xfffffffc, %eax\n"
        "movl %eax, 0xac(%esi)\n" /* this */
        "movl %edi, (%esp)\n" /* line 503 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 504 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 535 */
__attribute__((naked))
long int CSoundObject_get_sample_playback_rate(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 535 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x7c(%eax), %eax\n" /* this */
        "popl %ebp\n" /* line 540 */
        "retl\n"
    );
}

/* line 545 */
__attribute__((naked))
void CSoundObject_set_sample_playback_rate(const CSoundObject * _this, long int playback_rate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 545 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* playback_rate */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 547 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl %edi, 0x7c(%ebx)\n" /* line 549 | playback_rate, this */
        "je .Lf13ebac_0013ebdd\n"
        "movl %edi, 0x7c(%ebx)\n" /* line 551 | playback_rate, this */
        "movl (%ebx), %eax\n" /* line 552 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x34(%eax)\n"
        ".Lf13ebac_0013ebdd:\n"
        "movl %esi, (%esp)\n" /* line 553 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 554 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 553 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 559 */
__attribute__((naked))
void CSoundObject_set_sample_loop_count(const CSoundObject * _this, long unsigned int loops)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 559 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 569 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xc(%ebp), %eax\n" /* line 571 | loops */
        "movl %eax, 0x80(%esi)\n" /* this */
        "movl %ebx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 572 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 577 */
__attribute__((naked))
long unsigned int CSoundObject_get_sample_status(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 577 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 579 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x60(%esi), %esi\n" /* line 581 | this */
        "movl %ebx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 582 | this */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 587 */
__attribute__((naked))
long unsigned int CSoundObject_get_sample_length(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 587 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xb0(%eax), %eax\n" /* this */
        "popl %ebp\n" /* line 592 */
        "retl\n"
    );
}

/* line 597 */
__attribute__((naked))
long int CSoundObject_sample_buffer_ready(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 597 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 599 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movb $1, 0x14(%esi)\n" /* line 601 | this */
        /* { scope 2 */
        "movl 0x18(%esi), %ebx\n" /* line 604 | this */
        "cmpl $3, %ebx\n"
        "jg .Lf13ec76_0013ecda\n"
        "movl 0x84(%esi, %ebx, 4), %edx\n" /* line 606 | this */
        "testl %edx, %edx\n"
        "je .Lf13ec76_0013ecc8\n"
        "leal 0x84(%esi, %ebx, 4), %ecx\n" /* this */
        "movl %ebx, %edx\n"
        ".Lf13ec76_0013ecb4:\n"
        "addl $1, %edx\n" /* line 604 | i */
        "cmpl $4, %edx\n" /* i */
        "je .Lf13ec76_0013ecda\n"
        "movl 4(%ecx), %eax\n" /* line 606 */
        "addl $4, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf13ec76_0013ecb4\n"
        ".Lf13ec76_0013ecc6:\n"
        "movl %edx, %ebx\n"
        /* } scope */
        ".Lf13ec76_0013ecc8:\n"
        "movl %edi, (%esp)\n" /* line 621 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 622 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf13ec76_0013ecda:\n"
        "testl %ebx, %ebx\n" /* line 613 */
        "je .Lf13ec76_0013ecfc\n"
        "movl 0x84(%esi), %eax\n" /* line 615 | this */
        "testl %eax, %eax\n"
        "jne .Lf13ec76_0013ed13\n"
        "xorl %ebx, %ebx\n"
        /* } scope */
        "movl %edi, (%esp)\n" /* line 621 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 622 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf13ec76_0013ecfc:\n"
        "movl $0xffffffff, %ebx\n" /* line 613 */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 621 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 622 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf13ec76_0013ed13:\n"
        "movl %esi, %ecx\n" /* line 615 | this */
        "xorl %edx, %edx\n"
        ".Lf13ec76_0013ed17:\n"
        "addl $1, %edx\n" /* line 613 | i */
        "cmpl %edx, %ebx\n" /* i */
        "je .Lf13ec76_0013ecfc\n"
        "movl 0x88(%ecx), %eax\n" /* line 615 */
        "addl $4, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf13ec76_0013ed17\n"
        "jmp .Lf13ec76_0013ecc6\n"
    );
}

/* line 627 */
__attribute__((naked))
void CSoundObject_load_sample_buffer(const CSoundObject * _this, long unsigned int buff_num, const void *buffer, long unsigned int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 627 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* buff_num */
        "movb $1, 0x14(%ebx)\n" /* line 631 | this */
        "cmpl $3, %esi\n" /* line 633 | buff_num */
        "jbe .Lf13ed2e_0013ed56\n"
        "movl (%ebx), %eax\n" /* line 650 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x10(%eax)\n"
        "addl $0x2c, %esp\n" /* line 651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13ed2e_0013ed56:\n"
        "leal 0x20(%ebx), %eax\n" /* line 635 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x84(%ebx, %esi, 4), %eax\n" /* line 637 | this */
        "testl %eax, %eax\n"
        "je .Lf13ed2e_0013ed9e\n"
        ".Lf13ed2e_0013ed73:\n"
        "movl 0xb0(%ebx), %ecx\n" /* line 644 | this */
        "testl %ecx, %ecx\n"
        "jne .Lf13ed2e_0013ed86\n"
        "movl 0x14(%ebp), %eax\n" /* line 646 | len */
        "movl %eax, 0xb0(%ebx)\n" /* this */
        ".Lf13ed2e_0013ed86:\n"
        "movl %edi, (%esp)\n" /* line 647 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl (%ebx), %eax\n" /* line 650 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x10(%eax)\n"
        "addl $0x2c, %esp\n" /* line 651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13ed2e_0013ed9e:\n"
        "movl 0x10(%ebp), %eax\n" /* line 639 | buffer */
        "movl %eax, 0x84(%ebx, %esi, 4)\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* line 640 | len */
        "movl %eax, 0x94(%ebx, %esi, 4)\n" /* this */
        "jmp .Lf13ed2e_0013ed73\n"
    );
}

/* line 658 */
__attribute__((naked))
void CSoundObject_set_3D_position(const CSoundObject * _this, float X, float Y, float Z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 658 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x14(%ebp), %esi\n" /* Z */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 660 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xc(%ebp), %eax\n" /* line 662 | X */
        "movl %eax, 0xb4(%ebx)\n" /* this */
        "movl 0x10(%ebp), %eax\n" /* line 663 | Y */
        "movl %eax, 0xb8(%ebx)\n" /* this */
        "xorl $0x80000000, %esi\n" /* line 664 | Z */
        "movl %esi, 0xbc(%ebx)\n" /* Z, this */
        "movl (%ebx), %eax\n" /* line 666 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x38(%eax)\n"
        "movl %edi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 667 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl %edi, (%esp)\n" /* line 666 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 672 */
__attribute__((naked))
void CSoundObject_get_3D_position(const CSoundObject * _this, float *X, float *Y, float *Z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 672 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 674 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xb4(%ebx), %edx\n" /* line 676 | this */
        "movl 0xc(%ebp), %eax\n" /* X */
        "movl %edx, (%eax)\n"
        "movl 0xb8(%ebx), %edx\n" /* line 677 | this */
        "movl 0x10(%ebp), %eax\n" /* Y */
        "movl %edx, (%eax)\n"
        "movl 0xbc(%ebx), %eax\n" /* line 678 | this */
        "xorl $0x80000000, %eax\n"
        "movl 0x14(%ebp), %edx\n" /* Z */
        "movl %eax, (%edx)\n"
        "movl %esi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 679 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 684 */
__attribute__((naked))
void CSoundObject_set_3D_sample_distances(const CSoundObject * _this, float max_dist, float min_dist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 684 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 686 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 688 | max_dist */
        "ucomiss 0xd8(%ebx), %xmm0\n" /* this */
        "jne .Lf13ee70_0013eeb2\n"
        "jp .Lf13ee70_0013eeb2\n"
        "movss 0x10(%ebp), %xmm0\n" /* min_dist */
        "ucomiss 0xdc(%ebx), %xmm0\n" /* this */
        "jp .Lf13ee70_0013eead\n"
        "je .Lf13ee70_0013eecf\n"
        ".Lf13ee70_0013eead:\n"
        "movss 0xc(%ebp), %xmm0\n" /* max_dist */
        ".Lf13ee70_0013eeb2:\n"
        "movss %xmm0, 0xd8(%ebx)\n" /* line 690 | this */
        "movss 0x10(%ebp), %xmm0\n" /* line 691 | min_dist */
        "movss %xmm0, 0xdc(%ebx)\n" /* this */
        "movl (%ebx), %eax\n" /* line 692 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x3c(%eax)\n"
        ".Lf13ee70_0013eecf:\n"
        "movl %esi, (%esp)\n" /* line 693 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 694 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 693 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 699 */
__attribute__((naked))
void CSoundObject_set_3D_sample_effects_level(const CSoundObject * _this, float effects_level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 699 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 701 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xc(%ebp), %eax\n" /* line 703 | effects_level */
        "movl %eax, 0x78(%esi)\n" /* this */
        "movl %ebx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 704 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 711 */
__attribute__((naked))
bool CSoundObject_open_stream(const CSoundObject * _this, const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 711 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 715 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 720 */
__attribute__((naked))
void CSoundObject_close_stream(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 720 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 723 */
        "retl\n"
    );
}

/* line 728 */
__attribute__((naked))
void CSoundObject_get_stream_info(const CSoundObject * _this, long int *datarate, long int *sndtype, long int *length, long int *memory)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 728 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %eax\n" /* datarate */
        "movl 0x10(%ebp), %edx\n" /* sndtype */
        "movl 0x14(%ebp), %ecx\n" /* length */
        "movl 0x18(%ebp), %ebx\n" /* memory */
        "testl %eax, %eax\n" /* line 730 */
        "je .Lf13ef30_0013ef4b\n"
        "movl $0, (%eax)\n" /* line 733 */
        ".Lf13ef30_0013ef4b:\n"
        "testl %edx, %edx\n" /* line 736 */
        "je .Lf13ef30_0013ef5a\n"
        "movl 8(%ebp), %esi\n" /* line 738 | this */
        "movl 0xa8(%esi), %eax\n"
        "movl %eax, (%edx)\n"
        ".Lf13ef30_0013ef5a:\n"
        "testl %ecx, %ecx\n" /* line 741 */
        "je .Lf13ef30_0013ef64\n"
        "movl $0, (%ecx)\n" /* line 744 */
        ".Lf13ef30_0013ef64:\n"
        "testl %ebx, %ebx\n" /* line 747 | memory */
        "je .Lf13ef30_0013ef6e\n"
        "movl $0, (%ebx)\n" /* line 750 | memory */
        ".Lf13ef30_0013ef6e:\n"
        "popl %ebx\n" /* line 752 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 761 */
__attribute__((naked))
void CSoundObject_set_file_callbacks(AIL_file_open_callback opencb, AIL_file_close_callback closecb, AIL_file_seek_callback seekcb, AIL_file_read_callback readcb)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 761 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 765 | opencb */
        "movl %eax, __ZN12CSoundObject13sOpenCallbackE\n"
        "movl 0xc(%ebp), %eax\n" /* line 766 | closecb */
        "movl %eax, __ZN12CSoundObject14sCloseCallbackE\n"
        "movl 0x10(%ebp), %eax\n" /* line 767 | seekcb */
        "movl %eax, __ZN12CSoundObject13sSeekCallbackE\n"
        "movl 0x14(%ebp), %eax\n" /* line 768 | readcb */
        "movl %eax, __ZN12CSoundObject13sReadCallbackE\n"
        "popl %ebp\n" /* line 769 */
        "retl\n"
    );
}

/* line 807 */
__attribute__((naked))
void CSoundObject_FormatToDescription(long int mssPlaybackRate, long int mssFormat, AudioStreamBasicDescription *outDescription)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 807 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* mssFormat */
        "movl 0x10(%ebp), %eax\n" /* outDescription */
        /* { scope 1 */
        "cmpl $0xa, %edx\n" /* line 834 */
        "ja .Lf13ef98_0013efaf\n"
        "jmpl *0x3024ac(, %edx, 4)\n"
        ".Lf13ef98_0013efaf:\n"
        "xorl %esi, %esi\n" /* formatFlags */
        "xorl %ebx, %ebx\n" /* numChannels */
        "xorl %edx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf13ef98_0013efb7:\n"
        "cvtsi2sdl 8(%ebp), %xmm0\n" /* line 920 | mssPlaybackRate */
        "movsd %xmm0, (%eax)\n"
        "movl $0x6c70636d, 8(%eax)\n" /* line 921 */
        "movl %esi, 0xc(%eax)\n" /* line 922 | formatFlags */
        "movl %edx, 0x10(%eax)\n" /* line 923 */
        "movl $1, 0x14(%eax)\n" /* line 924 */
        "movl %edx, 0x18(%eax)\n" /* line 925 */
        "movl %ebx, 0x1c(%eax)\n" /* line 926 | numChannels */
        "movl %ecx, 0x20(%eax)\n" /* line 927 */
        /* } scope */
        "popl %ebx\n" /* line 928 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl $0x28, %esi\n" /* line 834 | formatFlags */
        "movl $2, %ebx\n" /* numChannels */
        "movl $1, %edx\n"
        "movl $8, %ecx\n"
        "jmp .Lf13ef98_0013efb7\n"
        "movl $9, %esi\n" /* formatFlags */
        "movl $2, %ebx\n" /* numChannels */
        "movl $8, %edx\n"
        "movl $0x20, %ecx\n"
        "jmp .Lf13ef98_0013efb7\n"
        "movl $0x29, %esi\n" /* line 857 | formatFlags */
        "movl $2, %ebx\n" /* numChannels */
        "movl $4, %edx\n"
        "movl $0x20, %ecx\n"
        "jmp .Lf13ef98_0013efb7\n"
        "movl $0xc, %esi\n" /* line 883 | formatFlags */
        "movl $2, %ebx\n" /* numChannels */
        "movl $4, %edx\n"
        "movl $0x10, %ecx\n"
        "jmp .Lf13ef98_0013efb7\n"
        "movl $8, %esi\n" /* line 873 | formatFlags */
        "movl $2, %ebx\n" /* numChannels */
        "movl $2, %edx\n"
        "movl $8, %ecx\n"
        "jmp .Lf13ef98_0013efb7\n"
        "movl $0x2c, %esi\n" /* line 845 | formatFlags */
        "movl $2, %ebx\n" /* numChannels */
        "movl $2, %edx\n"
        "movl $0x10, %ecx\n"
        "jmp .Lf13ef98_0013efb7\n"
    );
}

/* line 980 */
__attribute__((naked))
bool CSoundObject_IsEqualDescriptions(const AudioStreamBasicDescription *inDesc1, const AudioStreamBasicDescription *inDesc2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 980 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %ecx\n" /* inDesc1 */
        "movl 0xc(%ebp), %esi\n" /* inDesc2 */
        "movsd (%ecx), %xmm1\n" /* line 1009 */
        "pxor %xmm2, %xmm2\n"
        "ucomisd %xmm2, %xmm1\n"
        "jp .Lf13f06e_0013f08d\n"
        "je .Lf13f06e_0013f0a1\n"
        ".Lf13f06e_0013f08d:\n"
        "movsd (%esi), %xmm0\n" /* inDesc2 */
        "ucomisd %xmm2, %xmm0\n"
        "jp .Lf13f06e_0013f161\n"
        "jne .Lf13f06e_0013f161\n"
        ".Lf13f06e_0013f0a1:\n"
        "movl 8(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf13f06e_0013f0bd\n"
        ".Lf13f06e_0013f0a8:\n"
        "movl 8(%esi), %edx\n" /* inDesc2 */
        "testl %edx, %edx\n"
        "je .Lf13f06e_0013f0bd\n"
        "cmpl %edx, %eax\n"
        "je .Lf13f06e_0013f0bd\n"
        ".Lf13f06e_0013f0b3:\n"
        "xorl %eax, %eax\n"
        "addl $4, %esp\n" /* line 1010 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13f06e_0013f0bd:\n"
        "movl 0xc(%ecx), %ebx\n" /* line 939 | xFlags */
        "movl 0xc(%esi), %edx\n" /* line 940 */
        "testl %eax, %eax\n" /* line 943 */
        "jne .Lf13f06e_0013f10d\n"
        /* } scope */
        ".Lf13f06e_0013f0c7:\n"
        "movl 0x10(%ecx), %eax\n" /* line 1009 */
        "testl %eax, %eax\n"
        "jne .Lf13f06e_0013f12b\n"
        ".Lf13f06e_0013f0ce:\n"
        "movl 0x14(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf13f06e_0013f13c\n"
        ".Lf13f06e_0013f0d5:\n"
        "movl 0x18(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf13f06e_0013f14d\n"
        ".Lf13f06e_0013f0dc:\n"
        "movl 0x1c(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf13f06e_0013f0ee\n"
        "movl 0x1c(%esi), %edx\n" /* inDesc2 */
        "testl %edx, %edx\n"
        "jne .Lf13f06e_0013f181\n"
        ".Lf13f06e_0013f0ee:\n"
        "movl 0x20(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf13f06e_0013f100\n"
        "movl 0x20(%esi), %edx\n" /* inDesc2 */
        "testl %edx, %edx\n"
        "jne .Lf13f06e_0013f18e\n"
        ".Lf13f06e_0013f100:\n"
        "movl $1, %eax\n"
        ".Lf13f06e_0013f105:\n"
        "addl $4, %esp\n" /* line 1010 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13f06e_0013f10d:\n"
        "movl 8(%esi), %edi\n" /* line 943 | yFlags */
        "testl %edi, %edi\n" /* yFlags */
        "je .Lf13f06e_0013f0c7\n"
        "testl %ebx, %ebx\n" /* xFlags */
        "je .Lf13f06e_0013f0c7\n"
        "testl %edx, %edx\n"
        "je .Lf13f06e_0013f0c7\n"
        "cmpl $0x6c70636d, %eax\n" /* line 946 */
        "je .Lf13f06e_0013f1a0\n"
        "movl %edx, %edi\n" /* yFlags */
        /* } scope */
        ".Lf13f06e_0013f125:\n"
        "cmpl %edi, %ebx\n" /* line 1009 | yFlags, xFlags */
        "je .Lf13f06e_0013f0c7\n"
        "jmp .Lf13f06e_0013f0b3\n"
        ".Lf13f06e_0013f12b:\n"
        "movl 0x10(%esi), %edx\n" /* inDesc2 */
        "testl %edx, %edx\n"
        "je .Lf13f06e_0013f0ce\n"
        "cmpl %edx, %eax\n"
        "jne .Lf13f06e_0013f0b3\n"
        "jmp .Lf13f06e_0013f0ce\n"
        ".Lf13f06e_0013f13c:\n"
        "movl 0x14(%esi), %edx\n" /* inDesc2 */
        "testl %edx, %edx\n"
        "je .Lf13f06e_0013f0d5\n"
        "cmpl %edx, %eax\n"
        "jne .Lf13f06e_0013f0b3\n"
        "jmp .Lf13f06e_0013f0d5\n"
        ".Lf13f06e_0013f14d:\n"
        "movl 0x18(%esi), %edx\n" /* inDesc2 */
        "testl %edx, %edx\n"
        "je .Lf13f06e_0013f0dc\n"
        "cmpl %edx, %eax\n"
        "jne .Lf13f06e_0013f0b3\n"
        "jmp .Lf13f06e_0013f0dc\n"
        ".Lf13f06e_0013f161:\n"
        "ucomisd %xmm0, %xmm1\n"
        "jne .Lf13f06e_0013f0b3\n"
        "jp .Lf13f06e_0013f0b3\n"
        "movl 8(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf13f06e_0013f0bd\n"
        "jmp .Lf13f06e_0013f0a8\n"
        ".Lf13f06e_0013f181:\n"
        "cmpl %edx, %eax\n"
        "jne .Lf13f06e_0013f0b3\n"
        "jmp .Lf13f06e_0013f0ee\n"
        ".Lf13f06e_0013f18e:\n"
        "cmpl %edx, %eax\n"
        "jne .Lf13f06e_0013f0b3\n"
        "movl $1, %eax\n"
        "jmp .Lf13f06e_0013f105\n"
        /* { scope 1 */
        ".Lf13f06e_0013f1a0:\n"
        "movl %ebx, %eax\n" /* line 949 | xFlags */
        "andl $0x7fffffff, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl %edx, %edi\n" /* line 950 | yFlags */
        "andl $0x7fffffff, %edi\n" /* yFlags */
        "andl %edi, %eax\n" /* line 953 | yFlags */
        "testb $8, %al\n"
        "jne .Lf13f06e_0013f1f3\n"
        "movl -0x10(%ebp), %ebx\n" /* xFlags */
        ".Lf13f06e_0013f1bb:\n"
        "testb $1, %al\n" /* line 959 */
        "je .Lf13f06e_0013f1c5\n"
        "andl $0xfffffffb, %ebx\n" /* line 960 | xFlags */
        "andl $0xfffffffb, %edi\n" /* line 961 | yFlags */
        ".Lf13f06e_0013f1c5:\n"
        "cmpl $8, 0x20(%ecx)\n" /* line 965 */
        "ja .Lf13f06e_0013f1d6\n"
        "movl %ebx, %eax\n" /* line 967 | xFlags */
        "andl $0xfffffffd, %eax\n"
        "testb $8, %bl\n" /* xFlags */
        "cmovnel %eax, %ebx\n" /* xFlags */
        ".Lf13f06e_0013f1d6:\n"
        "cmpl $8, 0x20(%esi)\n" /* line 969 */
        "ja .Lf13f06e_0013f125\n"
        "movl %edi, %eax\n" /* line 971 | yFlags */
        "andl $0xfffffffd, %eax\n"
        "testl $8, %edi\n" /* yFlags */
        "cmovnel %eax, %edi\n" /* yFlags */
        "jmp .Lf13f06e_0013f125\n"
        ".Lf13f06e_0013f1f3:\n"
        "andl $0x7fffffef, %ebx\n" /* line 954 | xFlags */
        "movl %edx, %edi\n" /* line 955 | yFlags */
        "andl $0x7fffffef, %edi\n" /* yFlags */
        "movl %ebx, %eax\n" /* xFlags */
        "andl %edi, %eax\n" /* yFlags */
        "jmp .Lf13f06e_0013f1bb\n"
    );
}

/* line 1017 */
__attribute__((naked))
Boolean CSoundObject_SampleBuffersEmpty(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1017 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $4, %edx\n"
        ".Lf13f208_0013f213:\n"
        "movl 0x84(%eax), %ecx\n" /* line 1021 */
        "testl %ecx, %ecx\n"
        "jne .Lf13f208_0013f22c\n"
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 1019 */
        "jne .Lf13f208_0013f213\n"
        "movl $1, %eax\n"
        "popl %ebp\n" /* line 1028 */
        "retl\n"
        ".Lf13f208_0013f22c:\n"
        "xorl %eax, %eax\n" /* line 1021 */
        "popl %ebp\n" /* line 1028 */
        "retl\n"
    );
}

/* line 1059 */
__attribute__((naked))
void CSoundObject_ChangedVolume(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1059 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1062 */
        "retl\n"
    );
}

/* line 1067 */
__attribute__((naked))
void CSoundObject_ChangedFormat(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1067 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1070 */
        "retl\n"
    );
}

/* line 1075 */
__attribute__((naked))
void CSoundObject_Changed3DPosition(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1075 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1078 */
        "retl\n"
    );
}

/* line 1083 */
__attribute__((naked))
void CSoundObject_Changed3DDistances(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1083 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1086 */
        "retl\n"
    );
}

/* line 1091 */
__attribute__((naked))
long unsigned int CSoundObject_file_open_callback(const char *Filename, long unsigned int *FileHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1091 */
        "movl %esp, %ebp\n"
        "movl __ZN12CSoundObject13sOpenCallbackE, %ecx\n" /* line 1093 */
        "testl %ecx, %ecx\n"
        "je .Lf13f248_0013f258\n"
        "popl %ebp\n" /* line 1101 */
        "jmpl *%ecx\n" /* line 1095 */
        ".Lf13f248_0013f258:\n"
        "xorl %eax, %eax\n" /* line 1101 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1106 */
__attribute__((naked))
void CSoundObject_file_close_callback(long unsigned int FileHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1106 */
        "movl %esp, %ebp\n"
        "movl __ZN12CSoundObject14sCloseCallbackE, %ecx\n" /* line 1108 */
        "testl %ecx, %ecx\n"
        "je .Lf13f25c_0013f26c\n"
        "popl %ebp\n" /* line 1112 */
        "jmpl *%ecx\n" /* line 1110 */
        ".Lf13f25c_0013f26c:\n"
        "popl %ebp\n" /* line 1112 */
        "retl\n"
    );
}

/* line 1117 */
__attribute__((naked))
long int CSoundObject_file_seek_callback(long unsigned int FileHandle, long int Offset, long unsigned int Type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1117 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl __ZN12CSoundObject13sSeekCallbackE, %ecx\n" /* line 1119 */
        "testl %ecx, %ecx\n"
        "je .Lf13f26e_0013f280\n"
        "popl %ebx\n" /* line 1127 */
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 1121 */
        ".Lf13f26e_0013f280:\n"
        "xorl %eax, %eax\n" /* line 1127 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1132 */
__attribute__((naked))
long unsigned int CSoundObject_file_read_callback(long unsigned int FileHandle, void *Buffer, long unsigned int Bytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1132 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl __ZN12CSoundObject13sReadCallbackE, %ecx\n" /* line 1134 */
        "testl %ecx, %ecx\n"
        "je .Lf13f286_0013f298\n"
        "popl %ebx\n" /* line 1142 */
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 1136 */
        ".Lf13f286_0013f298:\n"
        "xorl %eax, %eax\n" /* line 1142 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 25 */
__attribute__((naked))
void CSoundObject_CSoundObject(const CSoundObject * _this, CSoundEngine *inEngine, UInt32 inBusIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* inEngine */
        "movl $0x332548, (%ebx)\n" /* line 54 | this */
        "movl %esi, 4(%ebx)\n" /* inEngine, this */
        "movl 0x10(%ebp), %eax\n" /* inBusIndex */
        "movl %eax, 8(%ebx)\n" /* this */
        "movb $1, 0xc(%ebx)\n" /* this */
        "movl $0, 0x10(%ebx)\n" /* this */
        "movb $0, 0x14(%ebx)\n" /* this */
        "movl $0, 0x18(%ebx)\n" /* this */
        "movl $1, 0x1c(%ebx)\n" /* this */
        "leal 0x20(%ebx), %edi\n" /* this */
        "movl %edi, (%esp)\n"
        "calll CMutex_CMutex\n"
        "movl $0, 0x5c(%ebx)\n" /* this */
        "movl $2, 0x60(%ebx)\n" /* this */
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x64(%ebx)\n" /* this */
        "movl %eax, 0x68(%ebx)\n" /* this */
        "movl %eax, 0x6c(%ebx)\n" /* this */
        "movl $0x3f000000, 0x70(%ebx)\n" /* this */
        "movl %eax, 0x74(%ebx)\n" /* this */
        "xorl %eax, %eax\n"
        "movl %eax, 0x78(%ebx)\n" /* this */
        "movl $0x2b11, 0x7c(%ebx)\n" /* this */
        "movl $1, 0x80(%ebx)\n" /* this */
        "movl $0, 0xa4(%ebx)\n" /* this */
        "movl $0, 0xa8(%ebx)\n" /* this */
        "movl $0, 0xac(%ebx)\n" /* this */
        "movl $0, 0xb0(%ebx)\n" /* this */
        "leal 0xb4(%ebx), %edx\n" /* this */
        /* { scope 1 */
        "movl %eax, 0xb4(%ebx)\n" /* line 305 | this */
        "movl %eax, 4(%edx)\n" /* line 306 */
        "movl %eax, 8(%edx)\n" /* line 307 */
        /* } scope */
        "leal 0xc0(%ebx), %edx\n" /* line 54 | this */
        /* { scope 1 */
        "movl %eax, 0xc0(%ebx)\n" /* line 305 | this */
        "movl %eax, 4(%edx)\n" /* line 306 */
        "movl %eax, 8(%edx)\n" /* line 307 */
        /* } scope */
        "leal 0xcc(%ebx), %edx\n" /* line 54 | this */
        /* { scope 1 */
        "movl %eax, 0xcc(%ebx)\n" /* line 305 | this */
        "movl %eax, 4(%edx)\n" /* line 306 */
        "movl %eax, 8(%edx)\n" /* line 307 */
        /* } scope */
        "movl %esi, (%esp)\n" /* line 54 | inEngine */
        "calll CSoundEngine_GetDefaultMaxDistance\n"
        "fstps 0xd8(%ebx)\n" /* this */
        "movl %esi, (%esp)\n" /* inEngine */
        "calll CSoundEngine_GetDefaultReferenceDistance\n"
        "fstps 0xdc(%ebx)\n" /* this */
        "movl %ebx, %eax\n" /* this */
        "movl $4, %edx\n" /* this */
        ".Lf13f29e_0013f3a1:\n"
        "movl $0, 0x4c(%eax)\n" /* line 58 */
        "movl $0, 0x84(%eax)\n" /* line 59 */
        "movl $0, 0x94(%eax)\n" /* line 60 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 56 */
        "jne .Lf13f29e_0013f3a1\n"
        "addl $0x1c, %esp\n" /* line 66 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        "movl %edi, (%esp)\n"
        "calll ZN6CMutexD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* overload skip: CSoundObject_CSoundObject (0x13f3de) */

/* line 509 */
__attribute__((naked))
void CSoundObject_get_sample_ms_position(const CSoundObject * _this, long int *total_milliseconds, long int *current_milliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 509 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* total_milliseconds */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 511 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "testl %esi, %esi\n" /* line 513 | total_milliseconds */
        "je .Lf13f51e_0013f59c\n"
        "movl 0xb0(%ebx), %edx\n" /* line 515 | this */
        "testl %edx, %edx\n"
        "js .Lf13f51e_0013f632\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "movl 0x1c(%ebx), %edx\n" /* this */
        "testl %edx, %edx\n"
        "js .Lf13f51e_0013f64e\n"
        ".Lf13f51e_0013f560:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf13f51e_0013f564:\n"
        "divss %xmm0, %xmm1\n"
        "cvtsi2ssl 0x7c(%ebx), %xmm0\n" /* this */
        "divss %xmm0, %xmm1\n"
        "mulss 0x2ed5c8, %xmm1\n" /* 1000.0f */
        "fnstcw -0x2a(%ebp)\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x2c(%ebp)\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "flds -0x3c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, (%esi)\n" /* total_milliseconds */
        ".Lf13f51e_0013f59c:\n"
        "movl 0x10(%ebp), %esi\n" /* line 518 | current_milliseconds, total_milliseconds */
        "testl %esi, %esi\n" /* total_milliseconds */
        "je .Lf13f51e_0013f5f7\n"
        "movl 0xac(%ebx), %edx\n" /* line 520 | this */
        "testl %edx, %edx\n"
        "js .Lf13f51e_0013f607\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "movl 0x1c(%ebx), %edx\n" /* this */
        "testl %edx, %edx\n"
        "js .Lf13f51e_0013f61f\n"
        ".Lf13f51e_0013f5b8:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf13f51e_0013f5bc:\n"
        "divss %xmm0, %xmm1\n"
        "cvtsi2ssl 0x7c(%ebx), %xmm0\n" /* this */
        "divss %xmm0, %xmm1\n"
        "mulss 0x2ed5c8, %xmm1\n" /* 1000.0f */
        "fnstcw -0x2a(%ebp)\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x2c(%ebp)\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "flds -0x3c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* current_milliseconds */
        "movl %eax, (%ecx)\n"
        ".Lf13f51e_0013f5f7:\n"
        "movl %edi, (%esp)\n" /* line 521 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 522 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13f51e_0013f607:\n"
        "movl %edx, %eax\n" /* line 520 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "movl 0x1c(%ebx), %edx\n" /* this */
        "testl %edx, %edx\n"
        "jns .Lf13f51e_0013f5b8\n"
        ".Lf13f51e_0013f61f:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf13f51e_0013f5bc\n"
        ".Lf13f51e_0013f632:\n"
        "movl %edx, %eax\n" /* line 515 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "movl 0x1c(%ebx), %edx\n" /* this */
        "testl %edx, %edx\n"
        "jns .Lf13f51e_0013f560\n"
        ".Lf13f51e_0013f64e:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf13f51e_0013f564\n"
    );
}

/* line 527 */
__attribute__((naked))
void CSoundObject_set_sample_ms_position(const CSoundObject * _this, long int milliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 527 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* milliseconds */
        "testl %edx, %edx\n" /* line 1053 */
        "js .Lf13f664_0013f75b\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf13f664_0013f67f:\n"
        "movaps %xmm0, %xmm1\n"
        "divss 0x2ed5c8, %xmm1\n" /* 1000.0f */
        "cvtsi2ssl 0x7c(%edi), %xmm0\n" /* this */
        "mulss %xmm0, %xmm1\n"
        "movl 0x1c(%edi), %edx\n" /* this */
        "testl %edx, %edx\n"
        "js .Lf13f664_0013f745\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf13f664_0013f6a2:\n"
        "mulss %xmm0, %xmm1\n"
        "fnstcw -0x2a(%ebp)\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x2c(%ebp)\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "flds -0x3c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %ebx\n"
        /* { scope 1 */
        "leal 0x20(%edi), %eax\n" /* line 486 */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl %ebx, %eax\n" /* line 488 */
        "movl %ebx, 0xac(%edi)\n"
        "movl 0xa8(%edi), %edx\n" /* line 490 */
        "testb $1, %dl\n"
        "je .Lf13f664_0013f708\n"
        "andl $0xfffffffe, %eax\n" /* line 492 */
        "movl %eax, 0xac(%edi)\n"
        "leal -0x20(%ebp), %eax\n" /* line 503 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13f664_0013f708:\n"
        "andb $8, %dl\n" /* line 494 */
        "jne .Lf13f664_0013f726\n"
        "movl %ebx, 0xac(%edi)\n" /* line 502 */
        "leal -0x20(%ebp), %eax\n" /* line 503 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13f664_0013f726:\n"
        "addl $3, %eax\n" /* line 498 */
        "andl $0xfffffffc, %eax\n"
        "movl %eax, 0xac(%edi)\n"
        "leal -0x20(%ebp), %eax\n" /* line 503 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13f664_0013f745:\n"
        "movl %edx, %eax\n" /* line 1053 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf13f664_0013f6a2\n"
        ".Lf13f664_0013f75b:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf13f664_0013f67f\n"
    );
}

/* line 167 */
__attribute__((naked))
void CSoundObject_init_sample(const CSoundObject * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 167 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: lock */
        "leal 0x20(%ebx), %edi\n" /* line 169 | this */
        "movl %edi, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl (%ebx), %eax\n" /* line 171 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0xc(%eax)\n"
        "movl (%ebx), %eax\n" /* line 172 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x2c(%eax)\n"
        "movl $2, 0x60(%ebx)\n" /* line 174 | this */
        /* { scope 2 */
        "movl %edi, 4(%esp)\n" /* line 276 */
        "leal -0x28(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl $0, 0x84(%ebx)\n" /* line 278 | this */
        "movl $0, 0x94(%ebx)\n" /* line 279 | this */
        "movl %ebx, %eax\n" /* this */
        "movl $3, %edx\n"
        ".Lf13f772_0013f7d1:\n"
        "movl $0, 0x88(%eax)\n" /* line 283 */
        "movl $0, 0x98(%eax)\n" /* line 284 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 281 */
        "jne .Lf13f772_0013f7d1\n"
        "movl $0, 0xac(%ebx)\n" /* line 287 | this */
        "movl $0, 0xb0(%ebx)\n" /* line 288 | this */
        "movb $0, 0x14(%ebx)\n" /* line 290 | this */
        "movl %esi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl $1, 0x80(%ebx)\n" /* line 178 | this */
        "movl (%ebx), %eax\n" /* line 180 | this */
        "movl $0x2b11, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x20(%eax)\n"
        /* { scope 2 */
        "movl %edi, 4(%esp)\n" /* line 315 */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xa8(%ebx), %eax\n" /* line 317 | this */
        "testl %eax, %eax\n"
        "je .Lf13f772_0013f856\n"
        "movl $0, 0xa8(%ebx)\n" /* line 319 | this */
        "movl $1, 0x1c(%ebx)\n" /* line 324 | this */
        "movl (%ebx), %eax\n" /* line 353 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x34(%eax)\n"
        ".Lf13f772_0013f856:\n"
        "movl %esi, (%esp)\n" /* line 354 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl %edi, 4(%esp)\n" /* line 372 */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 374 | 1.0f */
        "ucomiss 0x64(%ebx), %xmm0\n" /* this */
        "jp .Lf13f772_0013f87a\n"
        "je .Lf13f772_0013f887\n"
        ".Lf13f772_0013f87a:\n"
        "movss %xmm0, 0x64(%ebx)\n" /* line 376 | this */
        "movl (%ebx), %eax\n" /* line 378 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x30(%eax)\n"
        ".Lf13f772_0013f887:\n"
        "movl %esi, (%esp)\n" /* line 379 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl $0x3f000000, 0x70(%ebx)\n" /* line 186 | this */
        "movl $0, 0xac(%ebx)\n" /* line 188 | this */
        "movl $0, 0xb0(%ebx)\n" /* line 189 | this */
        "movl (%ebx), %eax\n" /* line 191 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x34(%eax)\n"
        "cmpl $1, 0x10(%ebx)\n" /* line 192 | this */
        "jne .Lf13f772_0013f8c0\n"
        "movl (%ebx), %eax\n" /* line 194 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x38(%eax)\n"
        ".Lf13f772_0013f8c0:\n"
        "movb $0, 0x14(%ebx)\n" /* line 196 | this */
        "leal -0x20(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1: lock */
        ".Lf13f772_0013f8d9:\n"
        "leal -0x20(%ebp), %eax\n" /* line 196 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 2 */
        "movl %esi, (%esp)\n" /* line 379 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf13f772_0013f8d9\n"
    );
}

/* line 254 */
__attribute__((naked))
long int CSoundObject_set_sample_info(const CSoundObject * _this, const AILSOUNDINFO *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 254 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 258 | this */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* lock */
        "movl %ecx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0xc(%ebp), %eax\n" /* line 260 | info, inBits */
        "movl 0x14(%eax), %edx\n" /* inChannels */
        "movl 0x10(%eax), %eax\n" /* inBits */
        /* { scope 2: lock */
        "cmpl $0x10, %eax\n" /* line 782 */
        "je .Lf13f8f8_0013fa57\n"
        "xorl %ebx, %ebx\n" /* line 786 | blocksize */
        "cmpl $0x20, %eax\n"
        "sete %bl\n" /* blocksize */
        "shll $3, %ebx\n" /* blocksize */
        ".Lf13f8f8_0013f936:\n"
        "movl %ebx, %eax\n" /* line 793 | blocksize */
        "orl $2, %eax\n"
        "cmpl $2, %edx\n"
        "cmovel %eax, %ebx\n" /* blocksize */
        /* } scope */
        /* { scope 2: lock */
        /* { scope 3 */
        "movl -0x2c(%ebp), %eax\n" /* line 315 */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %ecx\n" /* lock */
        "movl %ecx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl 0xa8(%esi), %ebx\n" /* line 317 | this, blocksize */
        "je .Lf13f8f8_0013f979\n"
        "movl %ebx, 0xa8(%esi)\n" /* line 319 | blocksize, this */
        "cmpl $0xa, %ebx\n" /* line 321 | blocksize */
        "jbe .Lf13f8f8_0013fa50\n"
        "movl $1, 0x1c(%esi)\n" /* line 349 | this */
        ".Lf13f8f8_0013f971:\n"
        "movl (%esi), %eax\n" /* line 353 | this */
        "movl %esi, (%esp)\n" /* this */
        "calll *0x34(%eax)\n"
        ".Lf13f8f8_0013f979:\n"
        "leal -0x28(%ebp), %ecx\n" /* line 354 | lock */
        "movl %ecx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 262 | info */
        "movl 8(%eax), %edi\n" /* len */
        "movl 4(%eax), %ebx\n" /* start */
        /* { scope 2: lock */
        /* { scope 3 */
        "movl -0x2c(%ebp), %ecx\n" /* line 276 */
        "movl %ecx, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl %ebx, 0x84(%esi)\n" /* line 278 | blocksize, this */
        "movl %edi, 0x94(%esi)\n" /* line 279 | len, this */
        "movl %esi, %eax\n" /* this */
        "movl $3, %edx\n"
        ".Lf13f8f8_0013f9b2:\n"
        "movl $0, 0x88(%eax)\n" /* line 283 */
        "movl $0, 0x98(%eax)\n" /* line 284 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 281 */
        "jne .Lf13f8f8_0013f9b2\n"
        "movl $0, 0xac(%esi)\n" /* line 287 | this */
        "movl %edi, 0xb0(%esi)\n" /* line 288 | len, this */
        "movb $0, 0x14(%esi)\n" /* line 290 | this */
        "leal -0x28(%ebp), %ecx\n" /* lock */
        "movl %ecx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        /* } scope */
        "movl (%esi), %edx\n" /* line 264 | this */
        "movl 0xc(%ebp), %ecx\n" /* info */
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll *0x20(%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 266 | info */
        "movl 0x1c(%eax), %ebx\n" /* blocksize */
        /* { scope 2: lock */
        /* { scope 3 */
        "movl -0x2c(%ebp), %ecx\n" /* line 298 */
        "movl %ecx, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl 0xa4(%esi), %ebx\n" /* line 300 | this, blocksize */
        "je .Lf13f8f8_0013fa2d\n"
        "movl %ebx, 0xa4(%esi)\n" /* line 302 | blocksize, this */
        "movl (%esi), %eax\n" /* line 303 | this */
        "movl %esi, (%esp)\n" /* this */
        "calll *0x34(%eax)\n"
        ".Lf13f8f8_0013fa2d:\n"
        "leal -0x28(%ebp), %eax\n" /* line 304 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        /* } scope */
        "leal -0x20(%ebp), %eax\n" /* line 268 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl $1, %eax\n" /* line 269 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: lock */
        /* { scope 3 */
        ".Lf13f8f8_0013fa50:\n"
        "jmpl *0x3024d8(, %ebx, 4)\n" /* line 321 */
        /* } scope */
        /* } scope */
        /* { scope 2: lock */
        ".Lf13f8f8_0013fa57:\n"
        "movl $1, %ebx\n" /* line 782 | blocksize */
        "jmp .Lf13f8f8_0013f936\n"
        /* } scope */
        /* { scope 2: lock */
        /* { scope 3 */
        "movl $4, 0x1c(%esi)\n" /* line 340 | this */
        "jmp .Lf13f8f8_0013f971\n"
        "movl $2, 0x1c(%esi)\n" /* line 336 | this */
        "jmp .Lf13f8f8_0013f971\n"
        "movl $8, 0x1c(%esi)\n" /* line 344 | this */
        "jmp .Lf13f8f8_0013f971\n"
        "movl %eax, %ebx\n" /* blocksize */
        "leal -0x28(%ebp), %eax\n" /* line 354 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        /* } scope */
        ".Lf13f8f8_0013fa92:\n"
        "leal -0x20(%ebp), %ecx\n" /* line 268 | lock */
        "movl %ecx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* blocksize */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n" /* blocksize */
        "jmp .Lf13f8f8_0013fa92\n"
        "movl %eax, %ebx\n" /* blocksize */
        /* { scope 2: lock */
        /* { scope 3 */
        "leal -0x28(%ebp), %ecx\n" /* line 304 | lock */
        "movl %ecx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf13f8f8_0013fa92\n"
    );
}

