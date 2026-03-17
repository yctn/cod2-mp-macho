/* ASM dump from: MacMSS_Object.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS_Object.cp */

#include "common_types.h"
#include "imports.h"

/* External functions needed by C implementations */
void StMutexLock_StMutexLock(char *lock, void *mutex);
void ZN11StMutexLockD1Ev(char *lock);
void ZN6CMutexD1Ev(void *mutex);
void CMutex_CMutex(void *mutex);
void __ZdlPv(void *ptr);
float CSoundEngine_GetDefaultMaxDistance(const CSoundEngine *inEngine);
float CSoundEngine_GetDefaultReferenceDistance(const CSoundEngine *inEngine);
void free(void *ptr);

/* CSoundObject vtable address (hardcoded from original binary) */
#define CSOUNDOBJECT_VTABLE_PTR ((void *)0x332548)

/* Static callback globals (defined in data.S with mangled names) */
extern AIL_file_open_callback __ZN12CSoundObject13sOpenCallbackE  __asm__("__ZN12CSoundObject13sOpenCallbackE");
extern AIL_file_close_callback __ZN12CSoundObject14sCloseCallbackE __asm__("__ZN12CSoundObject14sCloseCallbackE");
extern AIL_file_seek_callback __ZN12CSoundObject13sSeekCallbackE  __asm__("__ZN12CSoundObject13sSeekCallbackE");
extern AIL_file_read_callback __ZN12CSoundObject13sReadCallbackE  __asm__("__ZN12CSoundObject13sReadCallbackE");

void ZN12CSoundObjectD2Ev(char *_this); /* CSoundObject_~CSoundObject */
void ZN12CSoundObjectD1Ev(char *_this); /* CSoundObject_~CSoundObject */
void ZN12CSoundObjectD0Ev(char *_this); /* CSoundObject_~CSoundObject */
void CSoundObject_Release(char *_this);
Boolean CSoundObject_IsAvailable(char *_this);
UInt32 CSoundObject_GetSoundType(char *_this);
Boolean CSoundObject_Is3DSound(char *_this);
void CSoundObject_TheadIdle(char *_this);
void CSoundObject_set_sample_address(char *_this, const void *start, long unsigned int len);
void CSoundObject_set_sample_type(const CSoundObject * _this, long int format, long unsigned int flags);
void CSoundObject_set_sample_volume(const CSoundObject * _this, float volume);
void CSoundObject_stop_sample(char *_this);
void CSoundObject_resume_sample(char *_this);
void CSoundObject_end_sample(char *_this);
void CSoundObject_set_sample_adpcm_block_size(const CSoundObject * _this, long unsigned int blocksize);
float CSoundObject_get_sample_volume(char *_this);
void CSoundObject_get_sample_volume_levels(char *_this, float *left_level, float *right_level);
void CSoundObject_set_sample_volume_levels(const CSoundObject * _this, float left_level, float right_level);
void CSoundObject_get_sample_volume_pan(char *_this, float *volume, float *pan);
void CSoundObject_set_sample_reverb_levels(char *_this, float dry_level, float wet_level);
long unsigned int CSoundObject_get_sample_position(char *_this);
void CSoundObject_set_sample_position(char *_this, long unsigned int position);
long int CSoundObject_get_sample_playback_rate(char *_this);
void CSoundObject_set_sample_playback_rate(const CSoundObject * _this, long int playback_rate);
void CSoundObject_set_sample_loop_count(char *_this, long unsigned int loops);
long unsigned int CSoundObject_get_sample_status(char *_this);
long unsigned int CSoundObject_get_sample_length(char *_this);
long int CSoundObject_sample_buffer_ready(const CSoundObject * _this);
void CSoundObject_load_sample_buffer(const CSoundObject * _this, long unsigned int buff_num, const void *buffer, long unsigned int len);
void CSoundObject_set_3D_position(const CSoundObject * _this, float X, float Y, float Z);
void CSoundObject_get_3D_position(char *_this, float *X, float *Y, float *Z);
void CSoundObject_set_3D_sample_distances(const CSoundObject * _this, float max_dist, float min_dist);
void CSoundObject_set_3D_sample_effects_level(char *_this, float effects_level);
bool CSoundObject_open_stream(char *_this, const char *filename);
void CSoundObject_close_stream(char *_this);
void CSoundObject_get_stream_info(char *_this, long int *datarate, long int *sndtype, long int *length, long int *memory);
void CSoundObject_set_file_callbacks(AIL_file_open_callback opencb, AIL_file_close_callback closecb, AIL_file_seek_callback seekcb, AIL_file_read_callback readcb);
void CSoundObject_FormatToDescription(long int mssPlaybackRate, long int mssFormat, AudioStreamBasicDescription *outDescription);
bool CSoundObject_IsEqualDescriptions(const AudioStreamBasicDescription *inDesc1, const AudioStreamBasicDescription *inDesc2);
Boolean CSoundObject_SampleBuffersEmpty(char *_this);
void CSoundObject_ChangedVolume(char *_this);
void CSoundObject_ChangedFormat(char *_this);
void CSoundObject_Changed3DPosition(char *_this);
void CSoundObject_Changed3DDistances(char *_this);
long unsigned int CSoundObject_file_open_callback(const char *Filename, long unsigned int *FileHandle);
void CSoundObject_file_close_callback(long unsigned int FileHandle);
long int CSoundObject_file_seek_callback(long unsigned int FileHandle, long int Offset, long unsigned int Type);
long unsigned int CSoundObject_file_read_callback(long unsigned int FileHandle, void *Buffer, long unsigned int Bytes);
void CSoundObject_CSoundObject(char *_this, CSoundEngine *inEngine, UInt32 inBusIndex);
void CSoundObject_get_sample_ms_position(const CSoundObject * _this, long int *total_milliseconds, long int *current_milliseconds);
void CSoundObject_set_sample_ms_position(char *_this, long int milliseconds);
void CSoundObject_init_sample(const CSoundObject * _this);
long int CSoundObject_set_sample_info(const CSoundObject * _this, const AILSOUNDINFO *info);

/* ---- Destructors ---- */

/* ~CSoundObject() - base destructor (D2) */
void ZN12CSoundObjectD2Ev(char *_this)
{
    *(int *)(_this) = (int)CSOUNDOBJECT_VTABLE_PTR;
    ZN6CMutexD1Ev(_this + 0x20);
}

/* ~CSoundObject() - complete destructor (D1) */
void ZN12CSoundObjectD1Ev(char *_this)
{
    *(int *)(_this) = (int)CSOUNDOBJECT_VTABLE_PTR;
    ZN6CMutexD1Ev(_this + 0x20);
}

/* ~CSoundObject() - deleting destructor (D0) */
void ZN12CSoundObjectD0Ev(char *_this)
{
    *(int *)(_this) = (int)CSOUNDOBJECT_VTABLE_PTR;
    ZN6CMutexD1Ev(_this + 0x20);
    __ZdlPv(_this);
}

/* ---- CSoundObject_Release ---- */

void CSoundObject_Release(char *_this)
{
    int (**vtable)(char *);
    int i;
    char *p;

    /* Call virtual function at vtable offset 0xc (vtable[3]) */
    vtable = *(int (***)(char *))_this;
    ((void (*)(char *))vtable[3])(_this);

    /* Call virtual function at vtable offset 0x2c (vtable[11]) */
    vtable = *(int (***)(char *))_this;
    ((void (*)(char *))vtable[11])(_this);

    /* Free 4 sample buffers at offsets 0x4c, 0x50, 0x54, 0x58 */
    p = _this;
    for (i = 0; i < 4; i++) {
        void *buf = *(void **)(p + 0x4c);
        if (buf != 0) {
            free(buf);
            *(void **)(p + 0x4c) = 0;
        }
        p += 4;
    }

    *(int *)(_this + 0x5c) = 0;
    *(unsigned char *)(_this + 0xc) = 1;
}

/* ---- Simple Accessors ---- */

Boolean CSoundObject_IsAvailable(char *_this)
{
    return *(unsigned char *)(_this + 0xc);
}

UInt32 CSoundObject_GetSoundType(char *_this)
{
    return *(int *)(_this + 0x10);
}

Boolean CSoundObject_Is3DSound(char *_this)
{
    return *(int *)(_this + 0x10) == 1;
}

/* ---- No-op / Stub Functions ---- */

void CSoundObject_TheadIdle(char *_this)
{
    (void)_this;
}

/* ---- set_sample_address ---- */

void CSoundObject_set_sample_address(char *_this, const void *start, unsigned long len)
{
    char lock[16];
    char *p;
    int i;

    StMutexLock_StMutexLock(lock, _this + 0x20);

    *(const void **)(_this + 0x84) = start;
    *(unsigned long *)(_this + 0x94) = len;

    /* Clear 3 buffer slots: offsets 0x88+i*4 and 0x98+i*4 */
    p = _this;
    for (i = 0; i < 3; i++) {
        *(int *)(p + 0x88) = 0;
        *(int *)(p + 0x98) = 0;
        p += 4;
    }

    *(int *)(_this + 0xac) = 0;
    *(unsigned long *)(_this + 0xb0) = len;
    *(unsigned char *)(_this + 0x14) = 0;

    ZN11StMutexLockD1Ev(lock);
}

/* line 310 */
#ifndef __EMSCRIPTEN__
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

/* ---- stop_sample ---- */

void CSoundObject_stop_sample(char *_this)
{
    char lock[16];

    StMutexLock_StMutexLock(lock, _this + 0x20);

    if (*(int *)(_this + 0x60) == 4) {
        *(int *)(_this + 0x60) = 8;
    }

    ZN11StMutexLockD1Ev(lock);
}

/* ---- resume_sample ---- */

void CSoundObject_resume_sample(char *_this)
{
    char lock[16];
    int status;

    StMutexLock_StMutexLock(lock, _this + 0x20);

    status = *(int *)(_this + 0x60);
    if (status == 2 || status == 8) {
        *(int *)(_this + 0x60) = 4;
    }

    ZN11StMutexLockD1Ev(lock);
}

/* ---- end_sample ---- */

void CSoundObject_end_sample(char *_this)
{
    char lock[16];

    StMutexLock_StMutexLock(lock, _this + 0x20);

    if (*(int *)(_this + 0x60) == 4) {
        *(int *)(_this + 0x60) = 2;
        *(int *)(_this + 0xac) = 0;
    }

    ZN11StMutexLockD1Ev(lock);
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

/* ---- get_sample_volume ---- */

float CSoundObject_get_sample_volume(char *_this)
{
    return *(float *)(_this + 0x64);
}

/* ---- get_sample_volume_levels ---- */

void CSoundObject_get_sample_volume_levels(char *_this, float *left_level, float *right_level)
{
    *left_level = *(float *)(_this + 0x68);
    *right_level = *(float *)(_this + 0x6c);

    if (!(*(int *)(_this + 0xa8) & 2)) {
        *left_level *= 0.5f;
        *right_level *= 0.5f;
    }
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

/* ---- get_sample_volume_pan ---- */

void CSoundObject_get_sample_volume_pan(char *_this, float *volume, float *pan)
{
    if (volume != 0) {
        *(int *)volume = *(int *)(_this + 0x64);
    }
    if (pan != 0) {
        *(int *)pan = *(int *)(_this + 0x70);
    }
}

/* ---- set_sample_reverb_levels ---- */

void CSoundObject_set_sample_reverb_levels(char *_this, float dry_level, float wet_level)
{
    char lock[16];

    StMutexLock_StMutexLock(lock, _this + 0x20);

    *(float *)(_this + 0x74) = dry_level;
    *(float *)(_this + 0x78) = wet_level;

    ZN11StMutexLockD1Ev(lock);
}

/* ---- get_sample_position ---- */

unsigned long CSoundObject_get_sample_position(char *_this)
{
    char lock[16];
    unsigned long pos;

    StMutexLock_StMutexLock(lock, _this + 0x20);
    pos = *(unsigned long *)(_this + 0xac);
    ZN11StMutexLockD1Ev(lock);

    return pos;
}

/* ---- set_sample_position ---- */

void CSoundObject_set_sample_position(char *_this, unsigned long position)
{
    char lock[16];
    int flags;

    StMutexLock_StMutexLock(lock, _this + 0x20);

    *(unsigned long *)(_this + 0xac) = position;
    flags = *(int *)(_this + 0xa8);

    if (flags & 1) {
        /* Align to even boundary */
        position &= ~1u;
        *(unsigned long *)(_this + 0xac) = position;
    } else if (flags & 8) {
        /* Align to 4-byte boundary (round up) */
        position = (position + 3) & ~3u;
        *(unsigned long *)(_this + 0xac) = position;
    } else {
        *(unsigned long *)(_this + 0xac) = position;
    }

    ZN11StMutexLockD1Ev(lock);
}

/* ---- get_sample_playback_rate ---- */

long CSoundObject_get_sample_playback_rate(char *_this)
{
    return *(long *)(_this + 0x7c);
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

/* ---- set_sample_loop_count ---- */

void CSoundObject_set_sample_loop_count(char *_this, unsigned long loops)
{
    char lock[16];

    StMutexLock_StMutexLock(lock, _this + 0x20);
    *(unsigned long *)(_this + 0x80) = loops;
    ZN11StMutexLockD1Ev(lock);
}

/* ---- get_sample_status ---- */

unsigned long CSoundObject_get_sample_status(char *_this)
{
    char lock[16];
    unsigned long status;

    StMutexLock_StMutexLock(lock, _this + 0x20);
    status = *(unsigned long *)(_this + 0x60);
    ZN11StMutexLockD1Ev(lock);

    return status;
}

/* ---- get_sample_length ---- */

unsigned long CSoundObject_get_sample_length(char *_this)
{
    return *(unsigned long *)(_this + 0xb0);
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

/* ---- get_3D_position ---- */

void CSoundObject_get_3D_position(char *_this, float *X, float *Y, float *Z)
{
    char lock[16];

    StMutexLock_StMutexLock(lock, _this + 0x20);

    *(int *)X = *(int *)(_this + 0xb4);
    *(int *)Y = *(int *)(_this + 0xb8);
    /* Z is negated: XOR the sign bit */
    *(int *)Z = *(int *)(_this + 0xbc) ^ 0x80000000;

    ZN11StMutexLockD1Ev(lock);
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

/* ---- set_3D_sample_effects_level ---- */

void CSoundObject_set_3D_sample_effects_level(char *_this, float effects_level)
{
    char lock[16];

    StMutexLock_StMutexLock(lock, _this + 0x20);
    *(float *)(_this + 0x78) = effects_level;
    ZN11StMutexLockD1Ev(lock);
}

/* ---- open_stream (stub, returns 0) ---- */

bool CSoundObject_open_stream(char *_this, const char *filename)
{
    (void)_this;
    (void)filename;
    return 0;
}

/* ---- close_stream (stub, no-op) ---- */

void CSoundObject_close_stream(char *_this)
{
    (void)_this;
}

/* ---- get_stream_info ---- */

void CSoundObject_get_stream_info(char *_this, long *datarate, long *sndtype, long *length, long *memory)
{
    if (datarate != 0) {
        *datarate = 0;
    }
    if (sndtype != 0) {
        *sndtype = *(long *)(_this + 0xa8);
    }
    if (length != 0) {
        *length = 0;
    }
    if (memory != 0) {
        *memory = 0;
    }
}

/* ---- set_file_callbacks (static function, no this pointer) ---- */

void CSoundObject_set_file_callbacks(AIL_file_open_callback opencb, AIL_file_close_callback closecb, AIL_file_seek_callback seekcb, AIL_file_read_callback readcb)
{
    __ZN12CSoundObject13sOpenCallbackE = opencb;
    __ZN12CSoundObject14sCloseCallbackE = closecb;
    __ZN12CSoundObject13sSeekCallbackE = seekcb;
    __ZN12CSoundObject13sReadCallbackE = readcb;
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

/* ---- SampleBuffersEmpty ---- */

Boolean CSoundObject_SampleBuffersEmpty(char *_this)
{
    char *p = _this;
    int i;

    for (i = 0; i < 4; i++) {
        if (*(int *)(p + 0x84) != 0) {
            return 0;
        }
        p += 4;
    }
    return 1;
}

/* ---- No-op / Stub Functions ---- */

void CSoundObject_ChangedVolume(char *_this)
{
    (void)_this;
}

void CSoundObject_ChangedFormat(char *_this)
{
    (void)_this;
}

void CSoundObject_Changed3DPosition(char *_this)
{
    (void)_this;
}

void CSoundObject_Changed3DDistances(char *_this)
{
    (void)_this;
}

/* ---- file_open_callback (static) ---- */

unsigned long CSoundObject_file_open_callback(const char *Filename, unsigned long *FileHandle)
{
    if (__ZN12CSoundObject13sOpenCallbackE != 0) {
        return __ZN12CSoundObject13sOpenCallbackE(Filename, FileHandle);
    }
    return 0;
}

/* ---- file_close_callback (static) ---- */

void CSoundObject_file_close_callback(unsigned long FileHandle)
{
    if (__ZN12CSoundObject14sCloseCallbackE != 0) {
        __ZN12CSoundObject14sCloseCallbackE(FileHandle);
    }
}

/* ---- file_seek_callback (static) ---- */

long CSoundObject_file_seek_callback(unsigned long FileHandle, long Offset, unsigned long Type)
{
    if (__ZN12CSoundObject13sSeekCallbackE != 0) {
        return __ZN12CSoundObject13sSeekCallbackE(FileHandle, Offset, Type);
    }
    return 0;
}

/* ---- file_read_callback (static) ---- */

unsigned long CSoundObject_file_read_callback(unsigned long FileHandle, void *Buffer, unsigned long Bytes)
{
    if (__ZN12CSoundObject13sReadCallbackE != 0) {
        return __ZN12CSoundObject13sReadCallbackE(FileHandle, Buffer, Bytes);
    }
    return 0;
}

/* ---- CSoundObject_CSoundObject (constructor) ---- */

void CSoundObject_CSoundObject(char *_this, CSoundEngine *inEngine, UInt32 inBusIndex)
{
    int i;
    char *p;
    float one_f = 1.0f;       /* 0x3f800000 */
    float half_f = 0.5f;      /* 0x3f000000 */

    *(int *)(_this + 0) = (int)CSOUNDOBJECT_VTABLE_PTR;
    *(CSoundEngine **)(_this + 4) = inEngine;
    *(UInt32 *)(_this + 8) = inBusIndex;
    *(unsigned char *)(_this + 0xc) = 1;
    *(int *)(_this + 0x10) = 0;
    *(unsigned char *)(_this + 0x14) = 0;
    *(int *)(_this + 0x18) = 0;
    *(int *)(_this + 0x1c) = 1;

    CMutex_CMutex(_this + 0x20);

    *(int *)(_this + 0x5c) = 0;
    *(int *)(_this + 0x60) = 2;
    *(float *)(_this + 0x64) = one_f;
    *(float *)(_this + 0x68) = one_f;
    *(float *)(_this + 0x6c) = one_f;
    *(float *)(_this + 0x70) = half_f;
    *(float *)(_this + 0x74) = one_f;
    *(float *)(_this + 0x78) = 0.0f;
    *(int *)(_this + 0x7c) = 0x2b11;  /* 11025 */
    *(int *)(_this + 0x80) = 1;
    *(int *)(_this + 0xa4) = 0;
    *(int *)(_this + 0xa8) = 0;
    *(int *)(_this + 0xac) = 0;
    *(int *)(_this + 0xb0) = 0;

    /* Initialize 3D position vector at 0xb4 (3 floats) */
    *(int *)(_this + 0xb4) = 0;
    *(int *)(_this + 0xb8) = 0;
    *(int *)(_this + 0xbc) = 0;

    /* Initialize velocity vector at 0xc0 (3 floats) */
    *(int *)(_this + 0xc0) = 0;
    *(int *)(_this + 0xc4) = 0;
    *(int *)(_this + 0xc8) = 0;

    /* Initialize orientation vector at 0xcc (3 floats) */
    *(int *)(_this + 0xcc) = 0;
    *(int *)(_this + 0xd0) = 0;
    *(int *)(_this + 0xd4) = 0;

    /* Get default distances from engine */
    *(float *)(_this + 0xd8) = CSoundEngine_GetDefaultMaxDistance(inEngine);
    *(float *)(_this + 0xdc) = CSoundEngine_GetDefaultReferenceDistance(inEngine);

    /* Initialize 4 buffer slots */
    p = _this;
    for (i = 0; i < 4; i++) {
        *(int *)(p + 0x4c) = 0;
        *(int *)(p + 0x84) = 0;
        *(int *)(p + 0x94) = 0;
        p += 4;
    }
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

/* ---- set_sample_ms_position ---- */

void CSoundObject_set_sample_ms_position(char *_this, long milliseconds)
{
    char lock[16];
    float ms_f;
    float rate_f;
    float channels_f;
    float result;
    unsigned long position;
    int flags;

    /* Convert milliseconds (possibly unsigned-large) to float */
    ms_f = (float)(unsigned long)milliseconds;

    /* position = (ms / 1000.0) * playback_rate * channels_or_bps */
    rate_f = (float)(*(int *)(_this + 0x7c));
    channels_f = (float)(unsigned long)(*(int *)(_this + 0x1c));

    result = (ms_f / 1000.0f) * rate_f * channels_f;

    /* Convert float to unsigned long (truncate toward zero) */
    position = (unsigned long)result;

    /* Inline set_sample_position logic with mutex */
    StMutexLock_StMutexLock(lock, _this + 0x20);

    *(unsigned long *)(_this + 0xac) = position;
    flags = *(int *)(_this + 0xa8);

    if (flags & 1) {
        position &= ~1u;
        *(unsigned long *)(_this + 0xac) = position;
    } else if (flags & 8) {
        position = (position + 3) & ~3u;
        *(unsigned long *)(_this + 0xac) = position;
    }

    ZN11StMutexLockD1Ev(lock);
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
#else
void CSoundObject_set_sample_type(const CSoundObject * _this, long int format, long unsigned int flags) { (void)_this; (void)format; (void)flags; }
#endif
