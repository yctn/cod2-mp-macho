/* ASM dump from: MacMSS_Engine.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS_Engine.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacExceptions.h"
 */

/* C++ operator new/delete */
void *__Znwm(unsigned long size);
void __ZdlPv(void *ptr);
void __ZdaPv(void *ptr);

/* Forward declarations for functions defined in other translation units */
void CStreamSound_CStreamSound();
void CStreamSound_UpdateAllStreams(void);
void StThreadLock_StThreadLock();
void ZN12StThreadLockD1Ev();
void CThread_Stop();
void CSoundObject_Release();
void ZN6CMutexD1Ev();
void ZN7CThreadD2Ev();

static char *sDeviceName; /* 0xceb480 */

/*
 * CSoundEngine layout (deduced from ASM):
 *   offset 0x3c: AUGraph graph
 *   offset 0x44: AudioUnit mixerUnit
 *   offset 0x50: long int mixerCount
 *   offset 0x54: CSoundObject** sampleBuses
 *   offset 0x58: char deviceName[...]
 *   offset 0x184: vector<CSoundObject*> soundObjects
 *   offset 0x190: Boolean distanceScalingRequired
 *   offset 0x194: Float32 defaultReferenceDistance
 *   offset 0x198: Float32 defaultMaxDistance
 *   offset 0x1a8: long int roomType
 *   offset 0x1ac: float rolloffFactor
 *   offset 0x1b0: float distanceFactor
 *   offset 0x1b4: float listenerX
 *   offset 0x1b8: float listenerY
 *   offset 0x1bc: float listenerZ (negated)
 *   offset 0x1c0: float faceVector[3]
 *   offset 0x1cc: float upVector[3]
 */

long int CSoundEngine_mixer_count(const CSoundEngine * _this);
long int CSoundEngine_get_cpu_percent(const CSoundEngine * _this);
long int CSoundEngine_mixer_count_3D(const CSoundEngine * _this);
J_DCT_METHOD CSoundEngine_set_3D_room_type(const CSoundEngine * _this, long int room_type);
J_DCT_METHOD CSoundEngine_set_digital_master_reverb_levels(const CSoundEngine * _this, float dry_level, float wet_level);
long int CSoundEngine_minimum_sample_buffer_size(const CSoundEngine * _this, long int playback_rate, long int format);
long int CSoundEngine_size_processed_digital_audio(const CSoundEngine * _this, long unsigned int dest_rate, long unsigned int dest_format, const AILMIXINFO *src);
long int CSoundEngine_process_digital_audio(const CSoundEngine * _this, J_DCT_METHOD *dest_buffer, long int dest_buffer_size, long unsigned int dest_rate, long unsigned int dest_format, const AILMIXINFO *src);
char * CSoundEngine_device_name(const CSoundEngine * _this);
J_DCT_METHOD CSoundEngine_set_3D_rolloff_factor(const CSoundEngine * _this, float factor);
float CSoundEngine_get_3D_distance_factor(const CSoundEngine * _this);
J_DCT_METHOD CSoundEngine_set_3D_distance_factor(const CSoundEngine * _this, float factor);
J_DCT_METHOD CSoundEngine_set_3D_position(const CSoundEngine * _this, float X, float Y, float Z);
J_DCT_METHOD CSoundEngine_get_3D_position(const CSoundEngine * _this, float *X, float *Y, float *Z);
CSoundObject * CSoundEngine_NewStreamSound(const CSoundEngine * _this);
CSoundObject * CSoundEngine_GetSampleSound(const CSoundEngine * _this, HSAMPLE inSample);
CSoundObject * CSoundEngine_GetSampleSound3D(const CSoundEngine * _this, J_DCT_METHOD *in3DSample);
CSoundObject * CSoundEngine_GetStreamSound(const CSoundEngine * _this, HSTREAM inStream);
J_DCT_METHOD CSoundEngine_UpdateAllSounds(const CSoundEngine * _this);
AudioUnit CSoundEngine_GetMixerUnit(const CSoundEngine * _this);
Boolean CSoundEngine_IsDistanceScalingRequired(const CSoundEngine * _this);
Float32 CSoundEngine_GetDefaultReferenceDistance(const CSoundEngine * _this);
Float32 CSoundEngine_GetDefaultMaxDistance(const CSoundEngine * _this);
J_DCT_METHOD CSoundEngine_GetListenerFaceVector(const CSoundEngine * _this, D3DXVECTOR3 *outFace);
J_DCT_METHOD CSoundEngine_GetListenerUpVector(const CSoundEngine * _this, D3DXVECTOR3 *outUp);
CSoundObject * CSoundEngine_GetAvailableSampleBus(const CSoundEngine * _this, UInt32 inSoundType);
CSoundObject * CSoundEngine_NewSampleSound3D(const CSoundEngine * _this);
CSoundObject * CSoundEngine_NewSampleSound(const CSoundEngine * _this);
J_DCT_METHOD CSoundEngine_Execute(const CSoundEngine * _this, J_DCT_METHOD *inArg);
J_DCT_METHOD CSoundEngine_RemoveSoundObject(const CSoundEngine * _this, CSoundObject *inSound);
J_DCT_METHOD CSoundEngine_set_digital_master_room_type(const CSoundEngine * _this, long int room_type);
void ZN12CSoundEngineD0Ev(CSoundEngine *_this); /* CSoundEngine_~CSoundEngine */
J_DCT_METHOD CSoundEngine_AddSoundObject(const CSoundEngine * _this, CSoundObject *inSound);
void ZN12CSoundEngineD2Ev(void); /* CSoundEngine_~CSoundEngine */
void ZN12CSoundEngineD1Ev(CSoundEngine *_this); /* CSoundEngine_~CSoundEngine */
UInt32 CSoundEngine_GetPreferredChannelCount(const CSoundEngine * _this);
J_DCT_METHOD CSoundEngine_CSoundEngine(const CSoundEngine * _this, UInt32 inBusCount, int inHighQuality);
void *ZNSt6vectorIP12CSoundObjectSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EE(void *_this, CSoundObject **__position); /* std_vector<CSoundObject*, std_allocator<CSoundObject*> >_erase */
void *ZNSt6vectorIP12CSoundObjectSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void *_this, CSoundObject **__first, CSoundObject **__last); /* std_vector<CSoundObject*, std_allocator<CSoundObject*> >_erase */
void ZNSt6vectorIP12CSoundObjectSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void); /* std_vector<CSoundObject*, std_allocator<CSoundObject*> >__M_insert_aux */

/* line 339 */
long int CSoundEngine_mixer_count(const CSoundEngine * _this)
{
    return *(long int *)((char *)_this + 0x50);
}

/* line 347 */
long int CSoundEngine_get_cpu_percent(const CSoundEngine * _this)
{
    float cpuLoad;
    OSStatus error = AUGraphGetCPULoad(*(void **)((char *)_this + 0x3c), &cpuLoad);
    if (error != 0)
        return 1;

    int percent = (int)(cpuLoad * 100.0f);
    if (percent <= 0)
        return 1;

    return percent;
}

/* line 370 */
long int CSoundEngine_mixer_count_3D(const CSoundEngine * _this)
{
    return *(long int *)((char *)_this + 0x50);
}

/* line 441 */
J_DCT_METHOD CSoundEngine_set_3D_room_type(const CSoundEngine * _this, long int room_type)
{
    *(long int *)((char *)_this + 0x1a8) = room_type;
}

/* line 387 */
J_DCT_METHOD CSoundEngine_set_digital_master_reverb_levels(const CSoundEngine * _this, float dry_level, float wet_level)
{
    /* empty */
}

/* line 395 */
long int CSoundEngine_minimum_sample_buffer_size(const CSoundEngine * _this, long int playback_rate, long int format)
{
    return 0x800;
}

/* line 405 */
long int CSoundEngine_size_processed_digital_audio(const CSoundEngine * _this, long unsigned int dest_rate, long unsigned int dest_format, const AILMIXINFO *src)
{
    return 0;
}

/* line 415 */
long int CSoundEngine_process_digital_audio(const CSoundEngine * _this, J_DCT_METHOD *dest_buffer, long int dest_buffer_size, long unsigned int dest_rate, long unsigned int dest_format, const AILMIXINFO *src)
{
    return 0;
}

/* line 424 */
char * CSoundEngine_device_name(const CSoundEngine * _this)
{
    if (sDeviceName)
        return sDeviceName;

    sDeviceName = strdup((const char *)_this + 0x58);
    return sDeviceName;
}

/* line 458 */
J_DCT_METHOD CSoundEngine_set_3D_rolloff_factor(const CSoundEngine * _this, float factor)
{
    *(float *)((char *)_this + 0x1ac) = factor;
}

/* line 467 */
float CSoundEngine_get_3D_distance_factor(const CSoundEngine * _this)
{
    return *(float *)((char *)_this + 0x1b0);
}

/* line 475 */
J_DCT_METHOD CSoundEngine_set_3D_distance_factor(const CSoundEngine * _this, float factor)
{
    *(float *)((char *)_this + 0x1b0) = factor;
}

/* line 484 */
J_DCT_METHOD CSoundEngine_set_3D_position(const CSoundEngine * _this, float X, float Y, float Z)
{
    char *p = (char *)_this;
    *(float *)(p + 0x1b4) = X;
    *(float *)(p + 0x1b8) = Y;
    /* Negate Z by flipping sign bit */
    unsigned int zi = *(unsigned int *)&Z;
    zi ^= 0x80000000;
    *(unsigned int *)(p + 0x1bc) = zi;
}

/* line 498 */
J_DCT_METHOD CSoundEngine_get_3D_position(const CSoundEngine * _this, float *X, float *Y, float *Z)
{
    const char *p = (const char *)_this;
    *X = *(float *)(p + 0x1b4);
    *Y = *(float *)(p + 0x1b8);
    /* Negate Z by flipping sign bit */
    unsigned int zi = *(unsigned int *)(p + 0x1bc);
    zi ^= 0x80000000;
    *(unsigned int *)Z = zi;
}

/* line 528 */
CSoundObject * CSoundEngine_NewStreamSound(const CSoundEngine * _this)
{
    void *sound = __Znwm(0xf0);
    CStreamSound_CStreamSound(sound, _this);
    return (CSoundObject *)sound;
}

/* line 537 */
CSoundObject * CSoundEngine_GetSampleSound(const CSoundEngine * _this, HSAMPLE inSample)
{
    return (CSoundObject *)inSample;
}

/* line 552 */
CSoundObject * CSoundEngine_GetSampleSound3D(const CSoundEngine * _this, J_DCT_METHOD *in3DSample)
{
    return (CSoundObject *)in3DSample;
}

/* line 567 */
CSoundObject * CSoundEngine_GetStreamSound(const CSoundEngine * _this, HSTREAM inStream)
{
    return (CSoundObject *)inStream;
}

/* line 587 */
J_DCT_METHOD CSoundEngine_UpdateAllSounds(const CSoundEngine * _this)
{
    CStreamSound_UpdateAllStreams();
}

/* line 603 */
AudioUnit CSoundEngine_GetMixerUnit(const CSoundEngine * _this)
{
    return *(AudioUnit *)((char *)_this + 0x44);
}

/* line 611 */
Boolean CSoundEngine_IsDistanceScalingRequired(const CSoundEngine * _this)
{
    return *(unsigned char *)((char *)_this + 0x190);
}

/* line 619 */
Float32 CSoundEngine_GetDefaultReferenceDistance(const CSoundEngine * _this)
{
    const char *p = (const char *)_this;
    float refDist = *(float *)(p + 0x194);
    float distFactor = *(float *)(p + 0x1b0);
    return refDist / distFactor;
}

/* line 627 */
Float32 CSoundEngine_GetDefaultMaxDistance(const CSoundEngine * _this)
{
    const char *p = (const char *)_this;
    float maxDist = *(float *)(p + 0x198);
    float distFactor = *(float *)(p + 0x1b0);
    return maxDist / distFactor;
}

/* line 645 */
J_DCT_METHOD CSoundEngine_GetListenerFaceVector(const CSoundEngine * _this, D3DXVECTOR3 *outFace)
{
    const char *p = (const char *)_this;
    *(float *)((char *)outFace + 0) = *(float *)(p + 0x1c0);
    *(float *)((char *)outFace + 4) = *(float *)(p + 0x1c4);
    *(float *)((char *)outFace + 8) = *(float *)(p + 0x1c8);
}

/* line 654 */
J_DCT_METHOD CSoundEngine_GetListenerUpVector(const CSoundEngine * _this, D3DXVECTOR3 *outUp)
{
    const char *p = (const char *)_this;
    *(float *)((char *)outUp + 0) = *(float *)(p + 0x1cc);
    *(float *)((char *)outUp + 4) = *(float *)(p + 0x1d0);
    *(float *)((char *)outUp + 8) = *(float *)(p + 0x1d4);
}

/* line 797 */
CSoundObject * CSoundEngine_GetAvailableSampleBus(const CSoundEngine * _this, UInt32 inSoundType) { return 0; }
