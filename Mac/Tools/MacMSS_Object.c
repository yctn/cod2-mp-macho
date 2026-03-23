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
extern AIL_file_open_callback __ZN12CSoundObject13sOpenCallbackE;
extern AIL_file_close_callback __ZN12CSoundObject14sCloseCallbackE;
extern AIL_file_seek_callback __ZN12CSoundObject13sSeekCallbackE;
extern AIL_file_read_callback __ZN12CSoundObject13sReadCallbackE;

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
void CSoundObject_set_sample_type(const CSoundObject * _this, long int format, long unsigned int flags) { (void)_this; (void)format; (void)flags; }
