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
__attribute__((naked))
CSoundObject * CSoundEngine_GetAvailableSampleBus(const CSoundEngine * _this, UInt32 inSoundType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 797 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x50(%edi), %ecx\n" /* line 803 | this */
        "testl %ecx, %ecx\n"
        "je .Lf116058_001160cf\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf116058_00116077\n"
        ".Lf116058_0011606f:\n"
        "addl $1, %esi\n" /* i */
        "cmpl 0x50(%edi), %esi\n" /* this, i */
        "jae .Lf116058_001160d9\n"
        /* { scope 3 */
        ".Lf116058_00116077:\n"
        "movl 0x54(%edi), %eax\n" /* line 805 | this */
        "movl (%eax, %esi, 4), %ebx\n" /* theSample */
        "testl %ebx, %ebx\n" /* line 806 | theSample */
        "je .Lf116058_0011606f\n"
        "movl %ebx, (%esp)\n" /* theSample */
        "calll CSoundObject_IsAvailable\n"
        "testb %al, %al\n"
        "je .Lf116058_0011606f\n"
        "movl %ebx, (%esp)\n" /* theSample */
        "calll CSoundObject_GetSoundType\n"
        "cmpl %eax, 0xc(%ebp)\n" /* inSoundType */
        "jne .Lf116058_0011606f\n"
        "movl 0x1a4(%edi), %eax\n" /* line 808 | this */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x1a0(%edi), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x19c(%edi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inSoundType */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theSample */
        "calll CSampleSound_InitSample\n"
        "testl %eax, %eax\n" /* line 809 */
        "jne .Lf116058_0011606f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ebx, %eax\n" /* line 826 | theSample */
        "jmp .Lf116058_001160d1\n"
        /* } scope */
        ".Lf116058_001160cf:\n"
        "xorl %eax, %eax\n" /* line 820 */
        /* } scope */
        /* } scope */
        ".Lf116058_001160d1:\n"
        "addl $0x2c, %esp\n" /* line 836 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf116058_001160d9:\n"
        "movl 0x50(%edi), %edx\n" /* line 820 | this */
        "testl %edx, %edx\n"
        "je .Lf116058_001160cf\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf116058_001160ec\n"
        ".Lf116058_001160e4:\n"
        "addl $1, %esi\n" /* i */
        "cmpl 0x50(%edi), %esi\n" /* this, i */
        "jae .Lf116058_001160cf\n"
        /* { scope 3 */
        ".Lf116058_001160ec:\n"
        "movl 0x54(%edi), %eax\n" /* line 822 | this */
        "movl (%eax, %esi, 4), %ebx\n" /* theSample */
        "testl %ebx, %ebx\n" /* line 823 | theSample */
        "je .Lf116058_001160e4\n"
        "movl %ebx, (%esp)\n" /* theSample */
        "calll CSoundObject_IsAvailable\n"
        "testb %al, %al\n"
        "je .Lf116058_001160e4\n"
        "movl 0x1a4(%edi), %eax\n" /* line 825 | this */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x1a0(%edi), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x19c(%edi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inSoundType */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theSample */
        "calll CSampleSound_InitSample\n"
        "testl %eax, %eax\n" /* line 826 */
        "jne .Lf116058_001160e4\n"
        "movl %ebx, %eax\n" /* theSample */
        "jmp .Lf116058_001160d1\n"
    );
}

/* line 520 */
CSoundObject * CSoundEngine_NewSampleSound3D(const CSoundEngine * _this)
{
    return (CSoundObject *)CSoundEngine_GetAvailableSampleBus(_this, 1);
}

/* line 512 */
CSoundObject * CSoundEngine_NewSampleSound(const CSoundEngine * _this)
{
    return (CSoundObject *)CSoundEngine_GetAvailableSampleBus(_this, 0);
}

/* line 842 */
__attribute__((naked))
J_DCT_METHOD CSoundEngine_Execute(const CSoundEngine * _this, J_DCT_METHOD *inArg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 842 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl %edi, (%esp)\n" /* line 844 | this */
        "calll CThread_IsRunning\n"
        "testb %al, %al\n"
        "je .Lf116170_001161f2\n"
        ".Lf116170_00116188:\n"
        "movl 0x188(%edi), %eax\n" /* line 361 */
        "subl 0x184(%edi), %eax\n" /* line 846 | this */
        "sarl $2, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf116170_001161da\n"
        /* { scope 1 */
        "movl %edi, 4(%esp)\n" /* line 848 | this */
        "leal -0x20(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll StThreadLock_StThreadLock\n"
        "movl 0x184(%edi), %ebx\n" /* line 334 */
        "leal 0x188(%edi), %esi\n" /* line 352 */
        "cmpl 0x188(%edi), %ebx\n" /* line 850 | this */
        "je .Lf116170_001161cf\n"
        /* { scope 2 */
        ".Lf116170_001161be:\n"
        "movl (%ebx), %eax\n" /* line 852 | theSound */
        "movl (%eax), %edx\n" /* line 853 */
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        /* } scope */
        "addl $4, %ebx\n" /* line 623 */
        "cmpl (%esi), %ebx\n" /* line 850 */
        "jne .Lf116170_001161be\n"
        ".Lf116170_001161cf:\n"
        "leal -0x20(%ebp), %eax\n" /* line 854 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN12StThreadLockD1Ev\n"
        /* } scope */
        ".Lf116170_001161da:\n"
        "movl $0x186a0, (%esp)\n" /* line 857 */
        "calll usleep\n"
        "movl %edi, (%esp)\n" /* line 844 | this */
        "calll CThread_IsRunning\n"
        "testb %al, %al\n"
        "jne .Lf116170_00116188\n"
        ".Lf116170_001161f2:\n"
        "addl $0x2c, %esp\n" /* line 859 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        /* { scope 1 */
        "leal -0x20(%ebp), %eax\n" /* line 854 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN12StThreadLockD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 676 */
J_DCT_METHOD CSoundEngine_RemoveSoundObject(const CSoundEngine * _this, CSoundObject *inSound)
{
    char *p = (char *)_this;
    StThreadLock lock;

    StThreadLock_StThreadLock(&lock, _this);

    /* Search vector at offset 0x184 for inSound and erase it */
    CSoundObject **begin = *(CSoundObject ***)(p + 0x184);
    CSoundObject **end = *(CSoundObject ***)(p + 0x188);

    for (CSoundObject **it = begin; it != end; it++)
    {
        if (*it == inSound)
        {
            /* Erase element from vector */
            ZNSt6vectorIP12CSoundObjectSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EE(
                (void *)(p + 0x184), it);
            break;
        }
    }

    ZN12StThreadLockD1Ev(&lock);
}

/* line 379 */
J_DCT_METHOD CSoundEngine_set_digital_master_room_type(const CSoundEngine * _this, long int room_type)
{
    *(long int *)((char *)_this + 0x1a8) = room_type;
}

/* line 303 */
void ZN12CSoundEngineD0Ev(CSoundEngine *_this) /* CSoundEngine_~CSoundEngine (D0 - deleting destructor) */
{
    ZN12CSoundEngineD1Ev(_this);
    __ZdlPv(_this);
}

/* line 665 */
__attribute__((naked))
J_DCT_METHOD CSoundEngine_AddSoundObject(const CSoundEngine * _this, CSoundObject *inSound)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 665 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movl %ebx, 4(%esp)\n" /* line 667 | this */
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StThreadLock_StThreadLock\n"
        "leal 0x184(%ebx), %ecx\n" /* line 669 | this */
        "movl 4(%ecx), %edx\n" /* line 604 */
        "cmpl 8(%ecx), %edx\n"
        "je .Lf116418_00116461\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf116418_0011644c\n"
        "movl 0xc(%ebp), %eax\n" /* inSound */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %edx\n"
        ".Lf116418_0011644c:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl %edx, 4(%ecx)\n"
        ".Lf116418_00116452:\n"
        "movl %esi, (%esp)\n" /* line 669 */
        "calll ZN12StThreadLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 670 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf116418_00116461:\n"
        "leal 0xc(%ebp), %eax\n" /* line 610 | inSound */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll ZNSt6vectorIP12CSoundObjectSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_\n"
        "jmp .Lf116418_00116452\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 669 */
        "calll ZN12StThreadLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 303 */
__attribute__((naked))
void ZN12CSoundEngineD2Ev(void) /* CSoundEngine_~CSoundEngine */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 303 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x332328, (%eax)\n"
        /* { scope 1 */
        "movl %eax, 4(%esp)\n" /* line 306 */
        "leal -0x20(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "leal 0x184(%eax), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "calll StThreadLock_StThreadLock\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 352 */
        "movl 4(%ecx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* line 334 | this */
        "movl 0x184(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n" /* line 749 */
        "movl %edx, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZNSt6vectorIP12CSoundObjectSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_\n"
        "movl 8(%ebp), %edx\n" /* line 308 | this */
        "movl %edx, (%esp)\n"
        "calll CThread_Stop\n"
        "movl %ebx, (%esp)\n"
        "calll ZN12StThreadLockD1Ev\n"
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 311 | this */
        "movl 0x54(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf116488_00116500\n"
        /* { scope 1 */
        "movl 0x50(%ecx), %esi\n" /* line 313 | i */
        "testl %esi, %esi\n" /* i */
        "jne .Lf116488_00116564\n"
        /* } scope */
        ".Lf116488_001164f8:\n"
        "movl %eax, (%esp)\n" /* line 324 */
        "calll __ZdaPv\n"
        ".Lf116488_00116500:\n"
        "movl 8(%ebp), %edx\n" /* line 327 | this */
        "movl 0x3c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf116488_00116520\n"
        "movl %eax, (%esp)\n" /* line 329 */
        "calll AUGraphStop\n"
        "movl 8(%ebp), %ecx\n" /* line 330 | this */
        "movl 0x3c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DisposeAUGraph\n"
        ".Lf116488_00116520:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 273 */
        "movl 4(%ecx), %edx\n" /* __last */
        "movl (%ecx), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf116488_00116535\n"
        ".Lf116488_0011652e:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf116488_0011652e\n"
        /* } scope */
        ".Lf116488_00116535:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf116488_00116541\n"
        /* { scope 1 */
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        ".Lf116488_00116541:\n"
        "movl 8(%ebp), %eax\n" /* line 332 | this */
        "addl $0x158, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN6CMutexD1Ev\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll ZN7CThreadD2Ev\n"
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf116488_00116564:\n"
        "xorl %esi, %esi\n" /* line 313 | i */
        /* } scope */
        ".Lf116488_00116566:\n"
        "leal (, %esi, 4), %edi\n" /* line 311 */
        /* { scope 1 */
        /* { scope 2 */
        "movl (%eax, %edi), %ebx\n" /* line 315 | theSample */
        "testl %ebx, %ebx\n" /* line 316 | theSample */
        "je .Lf116488_00116594\n"
        "movl %ebx, (%esp)\n" /* line 318 | theSample */
        "calll CSoundObject_Release\n"
        "movl (%ebx), %eax\n" /* line 319 | theSample */
        "movl %ebx, (%esp)\n" /* theSample */
        "calll *4(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 320 | this */
        "movl 0x54(%edx), %eax\n"
        "movl $0, (%eax, %edi)\n"
        "movl 0x54(%edx), %eax\n"
        /* } scope */
        ".Lf116488_00116594:\n"
        "addl $1, %esi\n" /* line 313 | i */
        "movl 8(%ebp), %ecx\n" /* this */
        "cmpl 0x50(%ecx), %esi\n" /* i */
        "jb .Lf116488_00116566\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 324 */
        "je .Lf116488_00116500\n"
        "jmp .Lf116488_001164f8\n"
        "movl %eax, %esi\n" /* i */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 308 */
        "calll ZN12StThreadLockD1Ev\n"
        /* } scope */
        ".Lf116488_001165b6:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 273 */
        "movl 4(%eax), %edx\n" /* __last */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x184(%ecx), %eax\n"
        /* { scope 1 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf116488_001165d0\n"
        ".Lf116488_001165c9:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf116488_001165c9\n"
        /* } scope */
        ".Lf116488_001165d0:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 109 */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf116488_001165e1\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        ".Lf116488_001165e1:\n"
        "movl 8(%ebp), %eax\n" /* line 332 | this */
        "addl $0x158, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN6CMutexD1Ev\n"
        "jmp .Lf116488_001165f9\n"
        "movl %eax, %esi\n" /* i */
        "jmp .Lf116488_001165b6\n"
        "movl %eax, %esi\n" /* i */
        ".Lf116488_001165f9:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZN7CThreadD2Ev\n"
        "movl %esi, (%esp)\n" /* i */
        "calll __Unwind_Resume\n"
    );
}

/* line 303 */
/* CSoundEngine::~CSoundEngine (D1 - complete destructor) */
void ZN12CSoundEngineD1Ev(CSoundEngine *_this)
{
    char *p = (char *)_this;

    *(int *)p = 0x332328; /* vtable */

    /* Lock and clear sound objects vector */
    StThreadLock lock;
    StThreadLock_StThreadLock(&lock, _this);

    CSoundObject **begin = *(CSoundObject ***)(p + 0x184);
    CSoundObject **end = *(CSoundObject ***)(p + 0x188);
    ZNSt6vectorIP12CSoundObjectSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(
        (void *)(p + 0x184), begin, end);

    CThread_Stop(_this);
    ZN12StThreadLockD1Ev(&lock);

    /* Release all sample bus sounds */
    CSoundObject **samples = *(CSoundObject ***)(p + 0x54);
    if (samples)
    {
        unsigned int count = *(unsigned int *)(p + 0x50);
        for (unsigned int i = 0; i < count; i++)
        {
            CSoundObject *theSample = samples[i];
            if (theSample)
            {
                CSoundObject_Release(theSample);
                /* vtable call: destructor at offset 4 */
                (*(void (**)(void *))(*((int **)theSample) + 1))(theSample);
                samples[i] = NULL;
            }
        }
        __ZdaPv(samples);
    }

    /* Stop and dispose audio graph */
    void *graph = *(void **)(p + 0x3c);
    if (graph)
    {
        AUGraphStop(graph);
        DisposeAUGraph(*(void **)(p + 0x3c));
    }

    /* Free sound objects vector storage */
    CSoundObject **vecData = *(CSoundObject ***)(p + 0x184);
    if (vecData)
        __ZdlPv(vecData);

    /* Destroy mutex and thread base */
    ZN6CMutexD1Ev((void *)(p + 0x158));
    ZN7CThreadD2Ev(_this);
}

/* line 709 */
__attribute__((naked))
UInt32 CSoundEngine_GetPreferredChannelCount(const CSoundEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 709 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1: deviceID, size */
        "xorl %edi, %edi\n" /* line 712 | layout */
        /* { scope 2 */
        "movl $4, -0x20(%ebp)\n" /* line 718 | size */
        "leal -0x20(%ebp), %esi\n" /* line 719 | size */
        "movl %esi, 0x14(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* deviceID */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0x7d0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x4c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116790_00116938\n"
        "movl $0, 0x14(%esp)\n" /* line 724 */
        "movl %esi, 0x10(%esp)\n"
        "movl $0x73726e64, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* deviceID */
        "movl %eax, (%esp)\n"
        "calll AudioDeviceGetPropertyInfo\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116790_00116938\n"
        "movl -0x20(%ebp), %eax\n" /* line 727 | size */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll calloc\n"
        "movl %eax, %ebx\n" /* error */
        "movl %eax, %edi\n" /* layout */
        "testl %eax, %eax\n" /* line 43 */
        "je .Lf116790_00116970\n"
        "movl %eax, 0x14(%esp)\n" /* line 730 */
        "movl %esi, 0x10(%esp)\n"
        "movl $0x73726e64, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* deviceID */
        "movl %eax, (%esp)\n"
        "calll AudioDeviceGetProperty\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116790_00116960\n"
        "movl (%ebx), %eax\n" /* line 735 | error */
        "testl %eax, %eax\n"
        "je .Lf116790_001168a2\n"
        "cmpl $0x10000, %eax\n" /* line 752 */
        "je .Lf116790_001168f5\n"
        "movzwl %ax, %ebx\n" /* line 758 | error */
        /* } scope */
        ".Lf116790_0011687d:\n"
        "movl %edi, (%esp)\n" /* line 770 | layout */
        "calll free\n"
        "testl %ebx, %ebx\n" /* line 775 | error */
        "je .Lf116790_001168db\n"
        "cmpl $3, %ebx\n" /* line 779 | error */
        "jbe .Lf116790_001168db\n"
        "cmpl $5, %ebx\n" /* line 783 | error */
        "jbe .Lf116790_00116898\n"
        "movl $5, %ebx\n" /* error */
        /* } scope */
        ".Lf116790_00116898:\n"
        "movl %ebx, %eax\n" /* line 791 | error */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: deviceID, size */
        /* { scope 2 */
        ".Lf116790_001168a2:\n"
        "movl 8(%ebx), %esi\n" /* line 737 | error */
        "cmpl $2, %esi\n"
        "je .Lf116790_001168ee\n"
        /* { scope 3 */
        "testl %esi, %esi\n" /* line 743 */
        "je .Lf116790_001168ea\n"
        "movl %ebx, %ecx\n" /* error */
        "xorl %ebx, %ebx\n" /* error */
        "xorl %edx, %edx\n" /* i */
        ".Lf116790_001168b4:\n"
        "leal 1(%ebx), %eax\n" /* line 747 | error */
        "cmpl $-1, 0xc(%ecx)\n"
        "cmovnel %eax, %ebx\n" /* error */
        "addl $1, %edx\n" /* line 743 | i */
        "addl $0x14, %ecx\n"
        "cmpl %edx, %esi\n" /* i */
        "jne .Lf116790_001168b4\n"
        "jmp .Lf116790_0011687d\n"
        /* } scope */
        /* } scope */
        "movl %eax, (%esp)\n" /* line 761 */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        "testl %edi, %edi\n" /* line 768 | layout */
        "jne .Lf116790_001168ea\n"
        ".Lf116790_001168db:\n"
        "movl $2, %ebx\n" /* line 783 | error */
        /* } scope */
        "movl %ebx, %eax\n" /* line 791 | error */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: deviceID, size */
        ".Lf116790_001168ea:\n"
        "xorl %ebx, %ebx\n" /* line 768 | error */
        "jmp .Lf116790_0011687d\n"
        /* { scope 2 */
        ".Lf116790_001168ee:\n"
        "movl $2, %ebx\n" /* line 737 | error */
        "jmp .Lf116790_0011687d\n"
        ".Lf116790_001168f5:\n"
        "movl 4(%ebx), %edx\n" /* line 754 | error, x */
        /* { scope 3 */
        "movl %edx, %eax\n" /* line 699 */
        "shrl $1, %eax\n"
        "andl $0x55555555, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n" /* line 701 */
        "shrl $2, %eax\n"
        "andl $0x33333333, %eax\n"
        "andl $0x33333333, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n" /* line 702 */
        "shrl $4, %edx\n"
        "addl %edx, %eax\n"
        "andl $0xf0f0f0f, %eax\n"
        "movl %eax, %edx\n" /* line 703 */
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n" /* line 705 */
        "shll $0x10, %edx\n"
        "leal (%eax, %edx), %ebx\n"
        "shrl $0x18, %ebx\n"
        "jmp .Lf116790_0011687d\n"
        /* } scope */
        ".Lf116790_00116938:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        ".Lf116790_00116946:\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        ".Lf116790_00116960:\n"
        "movl $4, (%esp)\n"
        "calll ___cxa_allocate_exception\n"
        "movl %esi, (%eax)\n"
        "jmp .Lf116790_00116946\n"
        ".Lf116790_00116970:\n"
        "movl $4, (%esp)\n"
        "calll ___cxa_allocate_exception\n"
        "movl $0xffffffce, (%eax)\n"
        "jmp .Lf116790_00116946\n"
    );
}

/* line 22 */
__attribute__((naked))
J_DCT_METHOD CSoundEngine_CSoundEngine(const CSoundEngine * _this, UInt32 inBusCount, int inHighQuality)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 22 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movzbl 0x10(%ebp), %eax\n" /* inHighQuality, inBusCount */
        "movb %al, -0xb5(%ebp)\n" /* inBusCount, inHighQuality */
        "movl %edi, (%esp)\n" /* line 43 | this */
        "calll CThread_CThread\n"
        "movl $0x332328, (%edi)\n" /* this */
        "movl $0, 0x3c(%edi)\n" /* this */
        "movl $0, 0x40(%edi)\n" /* this */
        "movl $0, 0x44(%edi)\n" /* this */
        "movl $0, 0x48(%edi)\n" /* this */
        "movl $0, 0x4c(%edi)\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* inBusCount */
        "movl %eax, 0x50(%edi)\n" /* this */
        "movl $0, 0x54(%edi)\n" /* this */
        "leal 0x158(%edi), %eax\n" /* this */
        "movl %eax, -0xb4(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll CMutex_CMutex\n"
        "leal 0x184(%edi), %eax\n" /* this */
        "movl %eax, -0xb0(%ebp)\n" /* this */
        /* { scope 1: framesPerSlice */
        "movl $0, 0x184(%edi)\n" /* line 85 | this */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        /* } scope */
        "movb $0, 0x190(%edi)\n" /* line 43 | this */
        "movl $0x3f800000, %ecx\n"
        "movl %ecx, 0x194(%edi)\n" /* this */
        "movl $0x47c35000, 0x198(%edi)\n" /* this */
        "movl $5, 0x19c(%edi)\n" /* this */
        "movl $0, 0x1a0(%edi)\n" /* this */
        "movl $0, 0x1a4(%edi)\n" /* this */
        "movl $0, 0x1a8(%edi)\n" /* this */
        "movl %ecx, 0x1ac(%edi)\n" /* this */
        "movl %ecx, 0x1b0(%edi)\n" /* this */
        "leal 0x1b4(%edi), %edx\n" /* this */
        /* { scope 1: framesPerSlice */
        "xorl %eax, %eax\n" /* line 305 */
        "movl %eax, 0x1b4(%edi)\n" /* this */
        "movl %eax, 4(%edx)\n" /* line 306 */
        "movl %eax, 8(%edx)\n" /* line 307 */
        /* } scope */
        "leal 0x1c0(%edi), %edx\n" /* line 43 | this */
        /* { scope 1: framesPerSlice */
        "movl %eax, 0x1c0(%edi)\n" /* line 305 | this */
        "movl %eax, 4(%edx)\n" /* line 306 */
        "movl $0xbf800000, 8(%edx)\n" /* line 307 */
        /* } scope */
        "leal 0x1cc(%edi), %edx\n" /* line 43 | this */
        /* { scope 1: framesPerSlice */
        "movl %eax, 0x1cc(%edi)\n" /* line 305 | this */
        "movl %ecx, 4(%edx)\n" /* line 306 */
        "movl %eax, 8(%edx)\n" /* line 307 */
        /* } scope */
        /* { scope 1: framesPerSlice */
        "leal 0x58(%edi), %eax\n" /* line 45 | this */
        "movl %eax, -0xbc(%ebp)\n"
        "movl $0x61666544, 0x58(%edi)\n" /* this */
        "movl $0x20746c75, 4(%eax)\n"
        "movl $0x69647541, 8(%eax)\n"
        "movw $0x6f, 0xc(%eax)\n"
        "movl $0, -0x40(%ebp)\n" /* line 50 */
        "movl $0, -0x3c(%ebp)\n" /* line 51 */
        "movl $0x61756d78, -0x4c(%ebp)\n" /* line 52 | mixerCD */
        "movl $0x33646d78, -0x48(%ebp)\n" /* line 53 */
        "movl $0x6170706c, -0x44(%ebp)\n" /* line 54 */
        "leal -0x4c(%ebp), %eax\n" /* line 56 | mixerCD, theComponent */
        "movl %eax, 4(%esp)\n" /* theComponent */
        "movl $0, (%esp)\n"
        "calll FindNextComponent\n"
        "testl %eax, %eax\n" /* line 43 */
        "je .Lf116984_001171dd\n"
        "movl %eax, (%esp)\n" /* line 59 */
        "calll OpenComponent\n"
        "movl %eax, %ebx\n" /* theInstance */
        "testl %eax, %eax\n" /* line 43 */
        "je .Lf116984_001171dd\n"
        "movl %eax, (%esp)\n" /* line 62 */
        "calll GetComponentVersion\n"
        "movl %eax, %esi\n" /* theVersion */
        "movl %ebx, (%esp)\n" /* line 64 | theInstance */
        "calll CloseComponent\n"
        "cmpl $0x1ffff, %esi\n" /* line 66 | theVersion */
        "jle .Lf116984_001171f4\n"
        "cmpl $0x20000, %esi\n" /* line 70 | theVersion */
        "je .Lf116984_00116e5d\n"
        ".Lf116984_00116b3d:\n"
        "movl $0, -0x54(%ebp)\n" /* line 78 */
        "movl $0, -0x50(%ebp)\n" /* line 79 */
        "movl $0x61756f75, -0x60(%ebp)\n" /* line 80 | outputCD */
        "movl $0x64656620, -0x5c(%ebp)\n" /* line 81 */
        "movl $0x6170706c, -0x58(%ebp)\n" /* line 82 */
        "leal 0x3c(%edi), %eax\n" /* line 86 | this, error */
        "movl %eax, (%esp)\n" /* error */
        "calll NewAUGraph\n"
        "movl %eax, %ebx\n" /* error, theInstance */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "leal 0x40(%edi), %eax\n" /* line 91 | this */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "leal -0x4c(%ebp), %eax\n" /* mixerCD */
        "movl %eax, 4(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AUGraphNewNode\n"
        "movl %eax, %ebx\n" /* theInstance */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "leal 0x48(%edi), %eax\n" /* line 94 | this */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* outputCD */
        "movl %eax, 4(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AUGraphNewNode\n"
        "movl %eax, %ebx\n" /* theInstance */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "movl 0x3c(%edi), %eax\n" /* line 99 | this */
        "movl %eax, (%esp)\n"
        "calll AUGraphOpen\n"
        "movl %eax, %ebx\n" /* theInstance */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "leal 0x44(%edi), %eax\n" /* line 104 | this */
        "movl %eax, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 0x40(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AUGraphGetNodeInfo\n"
        "movl %eax, %ebx\n" /* theInstance */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "leal 0x4c(%edi), %eax\n" /* line 107 | this */
        "movl %eax, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 0x48(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AUGraphGetNodeInfo\n"
        "movl %eax, %ebx\n" /* theInstance */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "movl $4, -0x28(%ebp)\n" /* line 113 | size */
        "leal -0x28(%ebp), %eax\n" /* line 115 | size */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* busCount */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0xb, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "testl %eax, %eax\n" /* line 116 */
        "jne .Lf116984_00116ce4\n"
        "movl 0x50(%edi), %eax\n" /* this */
        "cmpl -0x24(%ebp), %eax\n" /* busCount */
        "je .Lf116984_00116ce7\n"
        "movl $4, 0x14(%esp)\n" /* line 118 */
        "leal 0x50(%edi), %eax\n" /* this */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0xb, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "testl %eax, %eax\n" /* line 119 */
        "jne .Lf116984_00117150\n"
        ".Lf116984_00116ce4:\n"
        "movl 0x50(%edi), %eax\n" /* this */
        ".Lf116984_00116ce7:\n"
        "shll $2, %eax\n" /* line 128 */
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, 0x54(%edi)\n" /* this */
        /* { scope 2 */
        "movl 0x50(%edi), %ecx\n" /* line 132 | this */
        "testl %ecx, %ecx\n"
        "jne .Lf116984_00116e69\n"
        /* } scope */
        ".Lf116984_00116d00:\n"
        "movl $0, 4(%esp)\n" /* line 142 */
        "movl 0x3c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AUGraphUpdate\n"
        "testl %eax, %eax\n" /* line 143 */
        "jne .Lf116984_00116d00\n"
        "leal -0xa8(%ebp), %esi\n" /* line 149 | format, i */
        "movl %esi, (%esp)\n" /* i */
        "calll CAStreamBasicDescription_CAStreamBasicDescription\n"
        "movl $0x28, -0x28(%ebp)\n" /* line 150 | size */
        "leal -0x28(%ebp), %eax\n" /* line 151 | size */
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* i */
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "movl %eax, %ebx\n" /* theSample */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "movl %edi, (%esp)\n" /* line 154 | this */
        "calll CSoundEngine_GetPreferredChannelCount\n"
        "movl %eax, -0xac(%ebp)\n" /* channelCount */
        "movl $0, 8(%esp)\n" /* line 156 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll CAStreamBasicDescription_SetCanonical\n"
        "movl $0, -0xa8(%ebp)\n" /* line 157 | format */
        "movl $0x40e58880, -0xa4(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 159 | size */
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* i */
        "movl $0, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* theSample */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "movl -0x28(%ebp), %eax\n" /* line 162 | size */
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* i */
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* theSample */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "cmpl $4, -0xac(%ebp)\n" /* line 168 | channelCount */
        "je .Lf116984_00116e9c\n"
        "cmpl $5, -0xac(%ebp)\n" /* channelCount */
        "je .Lf116984_00117144\n"
        "cmpl $2, -0xac(%ebp)\n" /* channelCount */
        "je .Lf116984_001171be\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl $0xffffff33, (%eax)\n"
        ".Lf116984_00116e43:\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        ".Lf116984_00116e5d:\n"
        "movb $1, 0x190(%edi)\n" /* line 72 | this */
        "jmp .Lf116984_00116b3d\n"
        /* { scope 2 */
        ".Lf116984_00116e69:\n"
        "xorl %esi, %esi\n" /* line 132 | i */
        /* { scope 3 */
        ".Lf116984_00116e6b:\n"
        "movl $0x120, (%esp)\n" /* line 134 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* theSample */
        "movl %esi, 8(%esp)\n" /* i */
        "movl %edi, 4(%esp)\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSampleSound_CSampleSound\n"
        "movl 0x54(%edi), %eax\n" /* line 135 | this */
        "movl %ebx, (%eax, %esi, 4)\n" /* theSample */
        /* } scope */
        "addl $1, %esi\n" /* line 132 | i */
        "cmpl 0x50(%edi), %esi\n" /* this, i */
        "jb .Lf116984_00116e6b\n"
        "jmp .Lf116984_00116d00\n"
        /* } scope */
        ".Lf116984_00116e9c:\n"
        "movl $0x6c0004, -0x80(%ebp)\n" /* line 175 | layout */
        ".Lf116984_00116ea3:\n"
        "movl $0, -0x7c(%ebp)\n" /* line 189 */
        "movl $0, -0x78(%ebp)\n" /* line 190 */
        "movl $0x20, -0x28(%ebp)\n" /* line 192 | size */
        "movl $0x20, 0x14(%esp)\n" /* line 194 */
        "leal -0x80(%ebp), %esi\n" /* layout, i */
        "movl %esi, 0x10(%esp)\n" /* i */
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* theSample */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "movl -0x28(%ebp), %eax\n" /* line 197 | size */
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* i */
        "movl $0, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* theSample */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "movl $4, -0x28(%ebp)\n" /* line 203 | size */
        "leal -0x28(%ebp), %eax\n" /* line 204 | size */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* deviceID */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0x7d0, 4(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "testl %eax, %eax\n" /* line 205 */
        "jne .Lf116984_00116fe3\n"
        /* { scope 2 */
        "movl $4, -0x28(%ebp)\n" /* line 208 | size */
        "leal -0x2c(%ebp), %ebx\n" /* line 209 | framesPerSlice, theSample */
        "movl %ebx, 0x14(%esp)\n" /* theSample */
        "leal -0x28(%ebp), %eax\n" /* size */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x6673697a, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* deviceID */
        "movl %eax, (%esp)\n"
        "calll AudioDeviceGetProperty\n"
        "testl %eax, %eax\n" /* line 210 */
        "je .Lf116984_0011715b\n"
        ".Lf116984_00116fa8:\n"
        "movl $0x100, -0x28(%ebp)\n" /* line 217 | size */
        "movl -0xbc(%ebp), %eax\n" /* line 218 */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* size */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x6e616d65, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* deviceID */
        "movl %eax, (%esp)\n"
        "calll AudioDeviceGetProperty\n"
        /* } scope */
        ".Lf116984_00116fe3:\n"
        "movl $0, -0x20(%ebp)\n" /* line 223 | reverbSetting */
        "movl $4, 0x14(%esp)\n" /* line 224 */
        "leal -0x20(%ebp), %eax\n" /* reverbSetting */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3ed, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl $0, 0x10(%esp)\n" /* line 229 */
        "movl 0x48(%edi), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 0x40(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AUGraphConnectNodeInput\n"
        "movl %eax, %ebx\n" /* theSample */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "movl 0x3c(%edi), %eax\n" /* line 234 | this */
        "movl %eax, (%esp)\n"
        "calll AUGraphInitialize\n"
        "movl %eax, %ebx\n" /* theSample */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        ".Lf116984_00117064:\n"
        "movl $0, 4(%esp)\n" /* line 241 */
        "movl 0x3c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AUGraphUpdate\n"
        "testl %eax, %eax\n" /* line 242 */
        "jne .Lf116984_00117064\n"
        "movl $0xc, -0x28(%ebp)\n" /* line 248 | size */
        "leal -0x28(%ebp), %eax\n" /* line 250 | size */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* params */
        "movl %eax, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0xbc2, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "testl %eax, %eax\n" /* line 254 */
        "jne .Lf116984_001170c9\n"
        "movl -0x38(%ebp), %eax\n" /* line 257 | params */
        "movl %eax, 0x194(%edi)\n" /* this */
        "movl -0x34(%ebp), %eax\n" /* line 258 */
        "movl %eax, 0x198(%edi)\n" /* this */
        ".Lf116984_001170c9:\n"
        "cmpl $2, -0xac(%ebp)\n" /* line 263 | channelCount */
        "jbe .Lf116984_0011712e\n"
        "movl $3, 0x19c(%edi)\n" /* line 265 | this */
        ".Lf116984_001170dc:\n"
        "cmpb $1, -0xb5(%ebp)\n" /* line 283 | inHighQuality */
        "sbbl %eax, %eax\n"
        "addl $5, %eax\n"
        "movl %eax, 0x1a0(%edi)\n" /* this */
        "movl -0x20(%ebp), %edx\n" /* line 285 | reverbSetting */
        "testl %edx, %edx\n"
        "je .Lf116984_001170fe\n"
        "orl $0x10, %eax\n" /* line 287 */
        "movl %eax, 0x1a0(%edi)\n" /* this */
        ".Lf116984_001170fe:\n"
        "movl 0x3c(%edi), %eax\n" /* line 293 | this */
        "movl %eax, (%esp)\n"
        "calll AUGraphStart\n"
        "movl %eax, %ebx\n" /* theSample */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf116984_001171ca\n"
        "movl $0, 4(%esp)\n" /* line 298 */
        "movl %edi, (%esp)\n" /* this */
        "calll CThread_Run\n"
        /* } scope */
        "addl $0xdc, %esp\n" /* line 299 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: framesPerSlice */
        ".Lf116984_0011712e:\n"
        "cmpb $1, -0xb5(%ebp)\n" /* line 272 | inHighQuality */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movl %eax, 0x19c(%edi)\n" /* this */
        "jmp .Lf116984_001170dc\n"
        ".Lf116984_00117144:\n"
        "movl $0x760005, -0x80(%ebp)\n" /* line 179 | layout */
        "jmp .Lf116984_00116ea3\n"
        ".Lf116984_00117150:\n"
        "movl -0x24(%ebp), %eax\n" /* line 122 | busCount */
        "movl %eax, 0x50(%edi)\n" /* this */
        "jmp .Lf116984_00116ce7\n"
        /* { scope 2 */
        ".Lf116984_0011715b:\n"
        "movl $4, 0x14(%esp)\n" /* line 213 */
        "movl %ebx, 0x10(%esp)\n" /* theSample */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl $4, 0x14(%esp)\n" /* line 214 */
        "movl %ebx, 0x10(%esp)\n" /* theSample */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "jmp .Lf116984_00116fa8\n"
        /* } scope */
        ".Lf116984_001171be:\n"
        "movl $0x650002, -0x80(%ebp)\n" /* line 171 | layout */
        "jmp .Lf116984_00116ea3\n"
        /* { scope 2 */
        ".Lf116984_001171ca:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "jmp .Lf116984_00116e43\n"
        /* } scope */
        ".Lf116984_001171dd:\n"
        "movl $4, (%esp)\n"
        "calll ___cxa_allocate_exception\n"
        "movl $0xffffffce, (%eax)\n"
        "jmp .Lf116984_00116e43\n"
        ".Lf116984_001171f4:\n"
        "movl $4, (%esp)\n"
        "calll ___cxa_allocate_exception\n"
        "movl $0xffffea83, (%eax)\n"
        "jmp .Lf116984_00116e43\n"
        "movl %eax, %esi\n"
        /* } scope */
        ".Lf116984_0011720d:\n"
        "movl -0xb0(%ebp), %eax\n" /* line 273 | this */
        "movl 4(%eax), %ecx\n" /* __last */
        "movl (%eax), %edx\n"
        "movl %edx, %eax\n"
        /* { scope 1: framesPerSlice */
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf116984_00117225\n"
        ".Lf116984_0011721e:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf116984_0011721e\n"
        /* } scope */
        ".Lf116984_00117225:\n"
        "testl %edx, %edx\n" /* line 122 */
        "je .Lf116984_00117231\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf116984_00117231:\n"
        "movl -0xb4(%ebp), %eax\n" /* line 299 */
        "movl %eax, (%esp)\n"
        "calll ZN6CMutexD1Ev\n"
        "jmp .Lf116984_00117243\n"
        "movl %eax, %esi\n" /* i */
        ".Lf116984_00117243:\n"
        "movl %edi, (%esp)\n" /* this */
        "calll ZN7CThreadD2Ev\n"
        "movl %esi, (%esp)\n" /* i */
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n" /* i */
        /* { scope 1: framesPerSlice */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ebx, (%esp)\n" /* line 134 | theSample */
        "calll __ZdlPv\n"
        "jmp .Lf116984_0011720d\n"
    );
}

/* overload skip: CSoundEngine_CSoundEngine (0x117260) */

/* line 110 — C replacement for vector::erase(iterator) */
void *ZNSt6vectorIP12CSoundObjectSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EE(
    void *_this, CSoundObject **__position)
{
    char *p = (char *)_this;
    CSoundObject **finish = *(CSoundObject ***)(p + 4);

    CSoundObject **next = __position + 1;
    if (next != finish)
    {
        memmove(__position, next, (char *)finish - (char *)next);
    }

    *(CSoundObject ***)(p + 4) = finish - 1;
    return __position;
}

/* line 122 — C replacement for vector::erase(iterator, iterator) */
void *ZNSt6vectorIP12CSoundObjectSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(
    void *_this, CSoundObject **__first, CSoundObject **__last)
{
    char *p = (char *)_this;
    CSoundObject **finish = *(CSoundObject ***)(p + 4);

    size_t tail = (char *)finish - (char *)__last;
    memmove(__first, __last, tail);

    size_t erased = (char *)__last - (char *)__first;
    *(CSoundObject ***)(p + 4) = (CSoundObject **)((char *)finish - erased);
    return __first;
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorIP12CSoundObjectSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) /* std_vector<CSoundObject*, std_allocator<CSoundObject*> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 4(%edi), %edx\n" /* line 251 | this */
        "cmpl 8(%edi), %edx\n" /* this */
        "je .Lf2c0f6c_002c0fc4\n"
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf2c0f6c_002c0f8c\n"
        "movl -4(%edx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %edx\n"
        ".Lf2c0f6c_002c0f8c:\n"
        "movl %edx, %eax\n" /* line 255 */
        "addl $4, %edx\n"
        "movl %edx, 4(%edi)\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 256 | __x */
        "movl (%edx), %ebx\n" /* __x_copy */
        "leal -4(%eax), %edx\n" /* line 257 */
        /* { scope 2 */
        "subl 0xc(%ebp), %edx\n" /* line 424 | __position */
        "andl $0xfffffffc, %edx\n" /* line 425 */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* __position */
        "movl %ecx, 4(%esp)\n"
        "subl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 260 | __position */
        "movl %ebx, (%eax)\n" /* __x_copy */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c0f6c_002c0fc4:\n"
        "movl %edx, %eax\n" /* line 759 */
        "subl (%edi), %eax\n" /* this */
        "sarl $2, %eax\n"
        "cmpl $0x3fffffff, %eax\n" /* line 265 */
        "je .Lf2c0f6c_002c1092\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2c0f6c_002c1070\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2c0f6c_002c0fe3:\n"
        "shll $2, %edx\n" /* line 88 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl (%edi), %eax\n" /* line 279 | this */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%ebp), %ebx\n" /* line 300 | __position, __x_copy */
        "subl %eax, %ebx\n" /* __x_copy */
        "movl %ebx, 8(%esp)\n" /* __x_copy */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        /* } scope */
        "movl -0x20(%ebp), %edx\n" /* line 104 */
        "addl %ebx, %edx\n"
        "je .Lf2c0f6c_002c101c\n"
        "movl 0x10(%ebp), %ecx\n" /* __x */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        ".Lf2c0f6c_002c101c:\n"
        "leal 4(%edx), %esi\n" /* line 286 */
        "movl 4(%edi), %ebx\n" /* line 603 | this, __x_copy */
        /* { scope 2 */
        /* { scope 3 */
        "subl 0xc(%ebp), %ebx\n" /* line 300 | __position, __x_copy */
        "movl %ebx, 8(%esp)\n" /* __x_copy */
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memmove\n"
        "addl %esi, %ebx\n" /* line 354 | __x_copy */
        /* } scope */
        /* } scope */
        "movl 4(%edi), %edx\n" /* line 352 | this */
        "movl (%edi), %ecx\n" /* line 334 | this */
        "movl %ecx, %eax\n"
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf2c0f6c_002c104c\n"
        ".Lf2c0f6c_002c1045:\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %edx, %eax\n" /* line 173 */
        "jne .Lf2c0f6c_002c1045\n"
        ".Lf2c0f6c_002c104c:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2c0f6c_002c1058\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2c0f6c_002c1058:\n"
        "movl -0x20(%ebp), %edx\n" /* line 302 */
        "movl %edx, (%edi)\n" /* this */
        "movl %ebx, 4(%edi)\n" /* line 303 | __x_copy, this */
        "movl %edx, %eax\n" /* line 304 */
        "addl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%edi)\n" /* this */
        /* } scope */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c0f6c_002c1070:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2c0f6c_002c1088\n"
        "cmpl $0x3fffffff, %edx\n" /* line 85 */
        "jbe .Lf2c0f6c_002c0fe3\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2c0f6c_002c1088:\n"
        "movl $0x3fffffff, %edx\n" /* line 272 */
        "jmp .Lf2c0f6c_002c0fe3\n"
        ".Lf2c0f6c_002c1092:\n"
        "movl $str_00215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}
