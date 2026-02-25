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

int SND_GetListenerIndexNearestToOrigin(const vec_t *origin);
jpeg_component_info SND_SaveListeners(snd_listener *listeners);
jpeg_component_info SND_RestoreListeners(snd_listener *listeners);
float SND_GetLerpedSlavePercentage(float baseSlavePercentage);
float SND_Attenuate(SndCurve *volumeFalloffCurve, float radius, float mindist, float maxdist);
Bool SND_IsAliasChannel3D(int channel);
static Bool SND_ValidateSoundAliasBlend(Bool bReport);
static jpeg_component_info SND_PauseSounds(void);
static jpeg_component_info SND_UnpauseSounds(void);
jpeg_component_info SND_SetChannelVolumes(int priority, const float *channelvolume, int fademsec);
jpeg_component_info SND_DeactivateChannelVolumes(int priority, int fademsec);
jpeg_component_info SND_UpdateLoopingSounds(void);
Bool SND_UpdateBackgroundVolume(int track, int frametime);
jpeg_component_info SND_DeactivateEnvironmentEffects(int priority, int fademsec);
jpeg_component_info SND_SetEnvironmentEffects(int priority, const char *roomstring, float drylevel, float wetlevel, int fademsec);
jpeg_component_info SND_UpdateReverbs(void);
jpeg_component_info SND_ErrorCleanup(void);
jpeg_component_info SND_DisconnectListener(void);
jpeg_component_info SND_SetListener(int entnum, const vec_t *origin, vec3_t *axis);
jpeg_component_info SND_SetChannelInfo(int index, int entnum, const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, const vec_t *origin, float volume, float pitch, int srcChannelCount, int baserate, int total_msec, int start_msec, int startDelay, int master, snd_alias_system_t system);
jpeg_component_info SND_GetCurrent3DPosition(int entnum, const vec_t *offset, vec_t *pos_out);
int SND_GetSoundOverlay(snd_overlay_type_t type, snd_overlay_info_t *info, int maxcount, int *cpu);
static int SND_StartAliasStream(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int treatAsMaster, int *pChannel, snd_alias_system_t system);
static jpeg_component_info SND_SaveChanInfo(MemoryFile *memFile);
jpeg_component_info SND_Init(void);
static int SND_PlaySoundAlias_Internal(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, int *pChannel, int timeshift, int treatAsMaster, snd_alias_system_t system);
int SND_PlayLocalSoundAliasByName(const char *aliasname, snd_alias_system_t system);
int SND_PlayLocalSoundAlias(snd_alias_list_t *aliasList, snd_alias_system_t system);
int SND_PlayBlendedSoundAliases(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float fLerp, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system);
int SND_PlaySoundAliasAsMaster(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system);
int SND_PlaySoundAlias(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system);
int SND_FindFree2DChannel(int entnum, int entchannel);
int SND_FindFree3DChannel(int entnum, int entchannel);
static jpeg_component_info SND_RestoreChanInfo(void);
static jpeg_component_info SND_StartBackground(int fadetime, snd_alias_system_t system);
jpeg_component_info SND_PlayAmbientAlias(const snd_alias_t *pAlias, int fadetime, snd_alias_system_t system);
jpeg_component_info SND_PlayMusicAlias(const snd_alias_t *pAlias, snd_alias_system_t system);
jpeg_component_info SND_StopMusic(int fadetime);
jpeg_component_info SND_StopSounds(snd_stopsounds_arg_t which);
jpeg_component_info SND_ShutdownChannels(void);
jpeg_component_info SND_Shutdown(void);
jpeg_component_info SND_FadeAllSounds(float volume, int fadetime);
jpeg_component_info SND_SetEnvironmentEffects_f(void);
jpeg_component_info SND_DeactivateEnvironmentEffects_f(void);
jpeg_component_info SND_Save(MemoryFile *memFile);
static Bool SND_RestoreStreamChannel(int channel);
jpeg_component_info SND_Restore(MemoryFile *memFile);
jpeg_component_info SND_Update(void);

/* line 223 */
__attribute__((naked))
int SND_GetListenerIndexNearestToOrigin(const vec_t *origin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 223 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 243 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 272 */
__attribute__((naked))
jpeg_component_info SND_SaveListeners(snd_listener *listeners)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 272 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* listeners */
        "movl 0xffdaf4, %eax\n" /* line 276 */
        "movl %eax, (%edx)\n"
        "movl 0xffdaf8, %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 0xffdafc, %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xffdb00, %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl 0xffdb04, %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 0xffdb08, %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl 0xffdb0c, %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl 0xffdb10, %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl 0xffdb14, %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl 0xffdb18, %eax\n"
        "movl %eax, 0x24(%edx)\n"
        "movl 0xffdb1c, %eax\n"
        "movl %eax, 0x28(%edx)\n"
        "movl 0xffdb20, %eax\n"
        "movl %eax, 0x2c(%edx)\n"
        "movl 0xffdb24, %eax\n"
        "movl %eax, 0x30(%edx)\n"
        "movl 0xffdb28, %eax\n"
        "movl %eax, 0x34(%edx)\n"
        "popl %ebp\n" /* line 277 */
        "retl\n"
    );
}

/* line 280 */
__attribute__((naked))
jpeg_component_info SND_RestoreListeners(snd_listener *listeners)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 280 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* listeners */
        "movl (%edx), %eax\n" /* line 284 */
        "movl %eax, 0xffdaf4\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0xffdaf8\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0xffdafc\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xffdb00\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0xffdb04\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0xffdb08\n"
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 0xffdb0c\n"
        "movl 0x1c(%edx), %eax\n"
        "movl %eax, 0xffdb10\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, 0xffdb14\n"
        "movl 0x24(%edx), %eax\n"
        "movl %eax, 0xffdb18\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, 0xffdb1c\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 0xffdb20\n"
        "movl 0x30(%edx), %eax\n"
        "movl %eax, 0xffdb24\n"
        "movl 0x34(%edx), %eax\n"
        "movl %eax, 0xffdb28\n"
        "popl %ebp\n" /* line 285 */
        "retl\n"
    );
}

/* line 288 */
__attribute__((naked))
float SND_GetLerpedSlavePercentage(float baseSlavePercentage)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 288 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss 8(%ebp), %xmm1\n" /* baseSlavePercentage */
        "mulss 0xffda74, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%ebp)\n" /* line 291 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 294 */
__attribute__((naked))
float SND_Attenuate(SndCurve *volumeFalloffCurve, float radius, float mindist, float maxdist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 294 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* volumeFalloffCurve */
        "movss 0xc(%ebp), %xmm1\n" /* radius */
        "movss 0x10(%ebp), %xmm0\n" /* mindist */
        "movss 0x14(%ebp), %xmm2\n" /* maxdist */
        "subss %xmm0, %xmm1\n" /* line 298 */
        "fldz\n" /* line 299 */
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "jbe .Lf4a5c2_0004a615\n"
        ".Lf4a5c2_0004a5e6:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 302 */
        "je .Lf4a5c2_0004a601\n"
        ".Lf4a5c2_0004a5eb:\n"
        "subss %xmm0, %xmm2\n" /* line 305 */
        "movaps %xmm1, %xmm0\n"
        "divss %xmm2, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* line 306 | 1.0f */
        "jb .Lf4a5c2_0004a605\n"
        "popl %ebp\n" /* line 310 */
        "retl\n"
        ".Lf4a5c2_0004a601:\n"
        "jp .Lf4a5c2_0004a5eb\n" /* line 302 */
        "popl %ebp\n" /* line 310 */
        "retl\n"
        ".Lf4a5c2_0004a605:\n"
        "fstp %st(0)\n"
        "movss %xmm0, 0xc(%ebp)\n" /* line 309 | radius */
        "movl %eax, 8(%ebp)\n" /* volumeFalloffCurve */
        "popl %ebp\n" /* line 310 */
        "jmp Com_GetVolumeFalloffCurveValue\n" /* line 309 */
        ".Lf4a5c2_0004a615:\n"
        "jp .Lf4a5c2_0004a5e6\n" /* line 299 */
        "fstp %st(0)\n"
        "fld1\n"
        "popl %ebp\n" /* line 310 */
        "retl\n"
    );
}

/* line 330 */
__attribute__((naked))
Bool SND_IsAliasChannel3D(int channel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 330 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* channel */
        "cmpl $0xa, %ecx\n" /* line 332 */
        "ja .Lf4a61e_0004a637\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x786, %eax\n"
        "jne .Lf4a61e_0004a63e\n"
        ".Lf4a61e_0004a637:\n"
        "movl $1, %eax\n"
        "popl %ebp\n" /* line 344 */
        "retl\n"
        ".Lf4a61e_0004a63e:\n"
        "xorl %eax, %eax\n" /* line 332 */
        "popl %ebp\n" /* line 344 */
        "retl\n"
    );
}

/* line 924 */
static __attribute__((naked))
Bool SND_ValidateSoundAliasBlend(Bool bReport)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 924 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %edi\n" /* pAlias0 */
        "movl %edx, %esi\n" /* pAlias1 */
        "movb %cl, -0x1d(%ebp)\n"
        "cmpl %edx, %eax\n" /* line 929 */
        "je .Lf4a642_0004a6b1\n"
        "movl %eax, (%esp)\n" /* line 932 */
        "calll Com_GetSoundFileName\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* pAlias1 */
        "calll Com_GetSoundFileName\n"
        "cmpl %eax, %ebx\n"
        "je .Lf4a642_0004a6be\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 934 */
        "jne .Lf4a642_0004a67c\n"
        ".Lf4a642_0004a672:\n"
        "xorl %eax, %eax\n" /* line 1035 */
        ".Lf4a642_0004a674:\n"
        "addl $0x2c, %esp\n" /* line 1040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4a642_0004a67c:\n"
        "movl (%esi), %eax\n" /* line 935 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x218304, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "addl $0x2c, %esp\n" /* line 1040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4a642_0004a6a6:\n"
        "movl 8(%esi), %eax\n" /* line 1032 | pAlias1 */
        "testl %eax, %eax\n"
        "jne .Lf4a642_0004a988\n"
        ".Lf4a642_0004a6b1:\n"
        "movl $1, %eax\n" /* line 1035 */
        "addl $0x2c, %esp\n" /* line 1040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4a642_0004a6be:\n"
        "movl 0x40(%edi), %eax\n" /* line 939 | pAlias0 */
        "cmpl 0x40(%esi), %eax\n" /* pAlias1 */
        "je .Lf4a642_0004a6f0\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 941 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 942 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x218364, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a6f0:\n"
        "movl 0x2c(%edi), %ebx\n" /* line 955 | pAlias0 */
        "movl %ebx, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x2c(%esi), %ecx\n" /* pAlias1 */
        "movl %ecx, %eax\n"
        "andl $1, %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n"
        "je .Lf4a642_0004a739\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 957 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 958 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x2183d0, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a739:\n"
        "movl %ebx, %edx\n" /* line 962 */
        "andl $0x60, %edx\n"
        "movl %ecx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl %edx, %eax\n"
        "je .Lf4a642_0004a778\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 964 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 965 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x218434, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a778:\n"
        "movl %ebx, %edx\n" /* line 969 */
        "andl $0x780, %edx\n"
        "movl %ecx, %eax\n"
        "andl $0x780, %eax\n"
        "cmpl %edx, %eax\n"
        "je .Lf4a642_0004a7bc\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 971 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 972 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x218498, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a7bc:\n"
        "movl %ebx, %edx\n" /* line 976 */
        "andl $2, %edx\n"
        "movl %ecx, %eax\n"
        "andl $2, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf4a642_0004a7fb\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 978 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 979 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x2184f4, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but onl" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a7fb:\n"
        "movl %ebx, %edx\n" /* line 983 */
        "andl $4, %edx\n"
        "movl %ecx, %eax\n"
        "andl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf4a642_0004a83a\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 985 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 986 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x218554, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but onl" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a83a:\n"
        "movl %ebx, %edx\n" /* line 990 */
        "andl $8, %edx\n"
        "movl %ecx, %eax\n"
        "andl $8, %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf4a642_0004a879\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 992 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 993 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x2185b4, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a879:\n"
        "andl $0x10, %ebx\n" /* line 997 */
        "andl $0x10, %ecx\n"
        "cmpl %ecx, %ebx\n"
        "je .Lf4a642_0004a8b4\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 999 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 1000 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x21861c, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a8b4:\n"
        "movss 0x30(%edi), %xmm0\n" /* line 1004 | pAlias0 */
        "ucomiss 0x30(%esi), %xmm0\n" /* pAlias1 */
        "jp .Lf4a642_0004a8c1\n"
        "je .Lf4a642_0004a8f2\n"
        ".Lf4a642_0004a8c1:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 1006 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 1007 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x218684, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a8f2:\n"
        "movl 0x3c(%edi), %eax\n" /* line 1011 | pAlias0 */
        "cmpl 0x3c(%esi), %eax\n" /* pAlias1 */
        "je .Lf4a642_0004a92b\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 1013 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 1014 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x2186ec, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a92b:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1018 */
        "testl %ecx, %ecx\n"
        "je .Lf4a642_0004a97d\n"
        "movss 0x1c(%edi), %xmm0\n" /* pAlias0 */
        "ucomiss 0x20(%edi), %xmm0\n" /* pAlias0 */
        "jne .Lf4a642_0004a94c\n"
        "jp .Lf4a642_0004a94c\n"
        "movss 0x1c(%esi), %xmm0\n" /* pAlias1 */
        "ucomiss 0x20(%esi), %xmm0\n" /* pAlias1 */
        "jp .Lf4a642_0004a94c\n"
        "je .Lf4a642_0004a9b9\n"
        ".Lf4a642_0004a94c:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 1020 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 1021 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x218750, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a97d:\n"
        "movl 8(%edi), %edx\n" /* line 1032 | pAlias0 */
        "testl %edx, %edx\n"
        "je .Lf4a642_0004a6a6\n"
        ".Lf4a642_0004a988:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 1034 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 1035 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x218840, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but one" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
        ".Lf4a642_0004a9b9:\n"
        "movss 0x14(%edi), %xmm0\n" /* line 1025 | pAlias0 */
        "ucomiss 0x18(%edi), %xmm0\n" /* pAlias0 */
        "jne .Lf4a642_0004a9d3\n"
        "jp .Lf4a642_0004a9d3\n"
        "movss 0x14(%esi), %xmm0\n" /* pAlias1 */
        "ucomiss 0x18(%esi), %xmm0\n" /* pAlias1 */
        "jp .Lf4a642_0004a9d3\n"
        "je .Lf4a642_0004a97d\n"
        ".Lf4a642_0004a9d3:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 1027 */
        "je .Lf4a642_0004a672\n"
        "movl (%esi), %eax\n" /* line 1028 | pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* pAlias0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x2187c8, 4(%esp)\n" /* "tried to blend between sound aliases '%s' and '%s', but the" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4a642_0004a674\n"
    );
}

/* line 1104 */
static __attribute__((naked))
jpeg_component_info SND_PauseSounds(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1104 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_snd\n" /* line 1108 */
        "je .Lf4aa04_0004aa57\n"
        "cmpb $0, 0xffd802\n" /* line 1111 */
        "jne .Lf4aa04_0004aa57\n"
        "movl 0xffebc4, %eax\n" /* line 1114 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4aa04_0004aa5e\n"
        ".Lf4aa04_0004aa2b:\n"
        "movl 0xffebc8, %ebx\n" /* line 1120 | i */
        "testl %ebx, %ebx\n" /* i */
        "jg .Lf4aa04_0004aafe\n"
        ".Lf4aa04_0004aa39:\n"
        "movl 0xffebcc, %eax\n" /* line 1126 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jg .Lf4aa04_0004aaac\n"
        ".Lf4aa04_0004aa46:\n"
        "movb $1, 0xffd802\n" /* line 1132 */
        "movl 0xffdb2c, %eax\n" /* line 1133 */
        "movl %eax, 0xffd814\n"
        /* } scope */
        ".Lf4aa04_0004aa57:\n"
        "addl $0x10, %esp\n" /* line 1134 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4aa04_0004aa5e:\n"
        "movl $0x2d, %ebx\n" /* line 1114 | i */
        "movl $g_snd, %esi\n"
        "jmp .Lf4aa04_0004aa7c\n"
        ".Lf4aa04_0004aa6a:\n"
        "addl $1, %ebx\n" /* i */
        "addl $0x50, %esi\n"
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4aa04_0004aa2b\n"
        ".Lf4aa04_0004aa7c:\n"
        "movl %ebx, (%esp)\n" /* line 1116 | i */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4aa04_0004aa6a\n"
        "movl 0x1168(%esi), %eax\n"
        "movl 0x2c(%eax), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "cmpb $0, 0xffdae7(%eax)\n"
        "je .Lf4aa04_0004aa6a\n"
        "movl %ebx, (%esp)\n" /* line 1117 | i */
        "calll SND_Pause2DChannel\n"
        "jmp .Lf4aa04_0004aa6a\n"
        ".Lf4aa04_0004aaac:\n"
        "movl $0x20, %ebx\n" /* line 1126 | i */
        "movl $g_snd, %esi\n"
        "jmp .Lf4aa04_0004aace\n"
        ".Lf4aa04_0004aab8:\n"
        "addl $1, %ebx\n" /* i */
        "addl $0x50, %esi\n"
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4aa04_0004aa46\n"
        ".Lf4aa04_0004aace:\n"
        "movl %ebx, (%esp)\n" /* line 1128 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4aa04_0004aab8\n"
        "movl 0xd58(%esi), %eax\n"
        "movl 0x2c(%eax), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "cmpb $0, 0xffdae7(%eax)\n"
        "je .Lf4aa04_0004aab8\n"
        "movl %ebx, (%esp)\n" /* line 1129 | i */
        "calll SND_PauseStreamChannel\n"
        "jmp .Lf4aa04_0004aab8\n"
        ".Lf4aa04_0004aafe:\n"
        "xorl %ebx, %ebx\n" /* line 1120 | i */
        "movl $g_snd, %esi\n"
        "jmp .Lf4aa04_0004ab19\n"
        ".Lf4aa04_0004ab07:\n"
        "addl $1, %ebx\n" /* i */
        "addl $0x50, %esi\n"
        "cmpl %ebx, 0xffebc8\n" /* i */
        "jle .Lf4aa04_0004aa39\n"
        ".Lf4aa04_0004ab19:\n"
        "movl %ebx, (%esp)\n" /* line 1122 | i */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4aa04_0004ab07\n"
        "movl 0x358(%esi), %eax\n"
        "movl 0x2c(%eax), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "cmpb $0, 0xffdae7(%eax)\n"
        "je .Lf4aa04_0004ab07\n"
        "movl %ebx, (%esp)\n" /* line 1123 | i */
        "calll SND_Pause3DChannel\n"
        "jmp .Lf4aa04_0004ab07\n"
    );
}

/* line 1137 */
static __attribute__((naked))
jpeg_component_info SND_UnpauseSounds(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1137 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_snd\n" /* line 1142 */
        "je .Lf4ab4a_0004abaa\n"
        "cmpb $0, 0xffd802\n" /* line 1145 */
        "je .Lf4ab4a_0004abaa\n"
        "movl 0xffdb2c, %edi\n" /* line 1148 | timeshift */
        "subl 0xffd814, %edi\n" /* timeshift */
        "movl 0xffebc4, %eax\n" /* line 1150 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4ab4a_0004abb2\n"
        ".Lf4ab4a_0004ab7e:\n"
        "movl 0xffebc8, %esi\n" /* line 1156 */
        "testl %esi, %esi\n"
        "jg .Lf4ab4a_0004ac34\n"
        ".Lf4ab4a_0004ab8c:\n"
        "movl 0xffebcc, %eax\n" /* line 1162 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jg .Lf4ab4a_0004abf3\n"
        ".Lf4ab4a_0004ab99:\n"
        "movb $0, 0xffd802\n" /* line 1168 */
        "movl $0, 0xffd814\n" /* line 1169 */
        /* } scope */
        ".Lf4ab4a_0004abaa:\n"
        "addl $0x1c, %esp\n" /* line 1170 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4ab4a_0004abb2:\n"
        "movl $0x2d, %ebx\n" /* line 1150 | i */
        "movl $g_snd, %esi\n"
        "jmp .Lf4ab4a_0004abd0\n"
        ".Lf4ab4a_0004abbe:\n"
        "addl $1, %ebx\n" /* i */
        "addl $0x50, %esi\n"
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4ab4a_0004ab7e\n"
        ".Lf4ab4a_0004abd0:\n"
        "movl %ebx, (%esp)\n" /* line 1152 | i */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4ab4a_0004abbe\n"
        "cmpb $0, 0x118c(%esi)\n"
        "je .Lf4ab4a_0004abbe\n"
        "movl %edi, 4(%esp)\n" /* line 1153 | timeshift */
        "movl %ebx, (%esp)\n" /* i */
        "calll SND_Unpause2DChannel\n"
        "jmp .Lf4ab4a_0004abbe\n"
        ".Lf4ab4a_0004abf3:\n"
        "movl $0x20, %ebx\n" /* line 1162 | i */
        "movl $g_snd, %esi\n"
        "jmp .Lf4ab4a_0004ac11\n"
        ".Lf4ab4a_0004abff:\n"
        "addl $1, %ebx\n" /* i */
        "addl $0x50, %esi\n"
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4ab4a_0004ab99\n"
        ".Lf4ab4a_0004ac11:\n"
        "movl %ebx, (%esp)\n" /* line 1164 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4ab4a_0004abff\n"
        "cmpb $0, 0xd7c(%esi)\n"
        "je .Lf4ab4a_0004abff\n"
        "movl %edi, 4(%esp)\n" /* line 1165 | timeshift */
        "movl %ebx, (%esp)\n" /* i */
        "calll SND_UnpauseStreamChannel\n"
        "jmp .Lf4ab4a_0004abff\n"
        ".Lf4ab4a_0004ac34:\n"
        "xorl %ebx, %ebx\n" /* line 1156 | i */
        "movl $g_snd, %esi\n"
        "jmp .Lf4ab4a_0004ac4f\n"
        ".Lf4ab4a_0004ac3d:\n"
        "addl $1, %ebx\n" /* i */
        "addl $0x50, %esi\n"
        "cmpl %ebx, 0xffebc8\n" /* i */
        "jle .Lf4ab4a_0004ab8c\n"
        ".Lf4ab4a_0004ac4f:\n"
        "movl %ebx, (%esp)\n" /* line 1158 | i */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4ab4a_0004ac3d\n"
        "cmpb $0, 0x37c(%esi)\n"
        "je .Lf4ab4a_0004ac3d\n"
        "movl %edi, 4(%esp)\n" /* line 1159 | timeshift */
        "movl %ebx, (%esp)\n" /* i */
        "calll SND_Unpause3DChannel\n"
        "jmp .Lf4ab4a_0004ac3d\n"
    );
}

/* line 1340 */
__attribute__((naked))
jpeg_component_info SND_SetChannelVolumes(int priority, const float *channelvolume, int fademsec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1340 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0x10(%ebp), %edx\n" /* fademsec */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1354 | priority */
        "shll $7, %eax\n"
        "movl 8(%ebp), %ecx\n" /* priority */
        "leal 0xffd834(%eax, %ecx, 8), %edi\n" /* channelVolGroup */
        "movb $1, 0x84(%edi)\n" /* line 1355 | channelVolGroup */
        "testl %edx, %edx\n" /* line 1357 */
        "jle .Lf4ac72_0004ad37\n"
        "cvtsi2ssl %edx, %xmm2\n"
        ".Lf4ac72_0004ac9e:\n"
        "movl %edi, %edx\n" /* channelVolGroup */
        "xorl %esi, %esi\n"
        "xorl %ebx, %ebx\n"
        "movl 0xc(%ebp), %ecx\n" /* channelvolume */
        ".Lf4ac72_0004aca7:\n"
        "movl (%ecx), %eax\n" /* line 1364 */
        "movl %eax, 4(%edx)\n"
        "movl 0xffda54, %eax\n" /* line 1365 */
        "movss (%ebx, %eax), %xmm1\n"
        "movss %xmm1, (%edx)\n"
        "movss (%ecx), %xmm0\n" /* line 1366 */
        "subss %xmm1, %xmm0\n"
        "divss %xmm2, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "addl $1, %esi\n" /* line 1360 */
        "addl $4, %ecx\n"
        "addl $0xc, %ebx\n"
        "addl $0xc, %edx\n"
        "cmpl $0xb, %esi\n"
        "jne .Lf4ac72_0004aca7\n"
        "cmpl 0xffda54, %edi\n" /* line 1369 | channelVolGroup */
        "je .Lf4ac72_0004ad27\n"
        "movl 8(%ebp), %ecx\n" /* line 1372 | priority */
        "addl $1, %ecx\n"
        "cmpl $3, %ecx\n"
        "jg .Lf4ac72_0004ad2c\n"
        "movl %ecx, %eax\n" /* line 1374 */
        "shll $7, %eax\n"
        "cmpb $0, 0xffd8b8(%eax, %ecx, 8)\n"
        "jne .Lf4ac72_0004ad27\n"
        "movl 8(%ebp), %eax\n" /* line 1375 | priority */
        "shll $7, %eax\n"
        "movl 8(%ebp), %ebx\n" /* priority */
        "leal 0xffd944(%eax, %ebx, 8), %edx\n"
        ".Lf4ac72_0004ad0e:\n"
        "addl $1, %ecx\n" /* line 1372 */
        "cmpl $4, %ecx\n"
        "je .Lf4ac72_0004ad2c\n"
        "movzbl 0x84(%edx), %eax\n" /* line 1374 */
        "addl $0x88, %edx\n"
        "testb %al, %al\n"
        "je .Lf4ac72_0004ad0e\n"
        /* } scope */
        ".Lf4ac72_0004ad27:\n"
        "popl %ebx\n" /* line 1379 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4ac72_0004ad2c:\n"
        "movl %edi, 0xffda54\n" /* line 1378 | channelVolGroup */
        /* } scope */
        "popl %ebx\n" /* line 1379 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4ac72_0004ad37:\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 1357 | 1.0f */
        "jmp .Lf4ac72_0004ac9e\n"
    );
}

/* line 1382 */
__attribute__((naked))
jpeg_component_info SND_DeactivateChannelVolumes(int priority, int fademsec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1382 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* priority */
        /* { scope 1 */
        "movl %ecx, %eax\n" /* line 1395 */
        "shll $7, %eax\n"
        "leal (%eax, %ecx, 8), %ebx\n"
        "leal 0xffd834(%ebx), %edi\n"
        "movb $0, 0x84(%edi)\n" /* line 1396 */
        "cmpl 0xffda54, %edi\n" /* line 1398 */
        "je .Lf4ad44_0004ad6f\n"
        /* } scope */
        "popl %ebx\n" /* line 1417 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4ad44_0004ad6f:\n"
        "movl %ecx, %edx\n" /* line 1401 */
        "subl $1, %edx\n"
        "js .Lf4ad44_0004ad85\n"
        "movl %edx, %eax\n" /* line 1403 */
        "shll $7, %eax\n"
        "cmpb $0, 0xffd8b8(%eax, %edx, 8)\n"
        "je .Lf4ad44_0004ade3\n"
        ".Lf4ad44_0004ad85:\n"
        "movl %edx, %esi\n" /* line 1401 */
        ".Lf4ad44_0004ad87:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1408 | fademsec */
        "testl %eax, %eax\n"
        "jle .Lf4ad44_0004ae0d\n"
        "cvtsi2ssl 0xc(%ebp), %xmm1\n" /* fademsec */
        ".Lf4ad44_0004ad93:\n"
        "movl %esi, %eax\n" /* line 1411 */
        "shll $7, %eax\n"
        "leal 0xffd834(%eax, %esi, 8), %eax\n"
        "movl %eax, 0xffda54\n"
        "movl %edi, %ecx\n"
        "xorl %esi, %esi\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf4ad44_0004adb1\n"
        ".Lf4ad44_0004adac:\n"
        "movl 0xffda54, %eax\n"
        ".Lf4ad44_0004adb1:\n"
        "movl (%ecx), %edx\n" /* line 1414 */
        "movl %edx, (%ebx, %eax)\n"
        "movl %ebx, %eax\n" /* line 1415 */
        "addl 0xffda54, %eax\n"
        "movss 4(%eax), %xmm0\n"
        "subss (%ecx), %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "addl $1, %esi\n" /* line 1412 */
        "addl $0xc, %ebx\n"
        "addl $0xc, %ecx\n"
        "cmpl $0xb, %esi\n"
        "jne .Lf4ad44_0004adac\n"
        /* } scope */
        "popl %ebx\n" /* line 1417 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4ad44_0004ade3:\n"
        "addl $0xffd724, %ebx\n" /* line 1404 */
        "movl %edx, %esi\n"
        "xorl %ecx, %ecx\n"
        ".Lf4ad44_0004aded:\n"
        "subl $1, %esi\n" /* line 1401 */
        "cmpl %edx, %ecx\n"
        "je .Lf4ad44_0004ad87\n"
        "movzbl 0x84(%ebx), %eax\n" /* line 1403 */
        "addl $1, %ecx\n"
        "subl $0x88, %ebx\n"
        "testb %al, %al\n"
        "je .Lf4ad44_0004aded\n"
        "jmp .Lf4ad44_0004ad87\n"
        ".Lf4ad44_0004ae0d:\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 1408 | 1.0f */
        "jmp .Lf4ad44_0004ad93\n"
    );
}

/* line 1420 */
__attribute__((naked))
jpeg_component_info SND_UpdateLoopingSounds(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1420 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_snd\n" /* line 1424 */
        "je .Lf4ae1a_0004ae65\n"
        "cmpb $0, 0xffd802\n" /* line 1427 */
        "jne .Lf4ae1a_0004ae65\n"
        "movl 0xffebc8, %eax\n" /* line 1430 */
        "testl %eax, %eax\n"
        "jg .Lf4ae1a_0004ae6c\n"
        "movl 0xffebc4, %eax\n" /* line 1441 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4ae1a_0004aebc\n"
        ".Lf4ae1a_0004ae4a:\n"
        "movl 0xffebcc, %eax\n" /* line 1452 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jg .Lf4ae1a_0004af17\n"
        ".Lf4ae1a_0004ae5b:\n"
        "movl 0xffdb2c, %eax\n" /* line 1463 */
        "movl %eax, 0xffdb30\n"
        /* } scope */
        ".Lf4ae1a_0004ae65:\n"
        "addl $0x10, %esp\n" /* line 1464 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4ae1a_0004ae6c:\n"
        "xorl %ebx, %ebx\n" /* line 1430 | i */
        "movl $g_snd, %esi\n"
        ".Lf4ae1a_0004ae73:\n"
        "movl %ebx, (%esp)\n" /* line 1432 | i */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4ae1a_0004aea1\n"
        "movl 0x358(%esi), %eax\n" /* line 1435 */
        "testb $1, 0x2c(%eax)\n"
        "je .Lf4ae1a_0004aea1\n"
        "movl 0x340(%esi), %eax\n" /* line 1437 */
        "cmpl 0xffdb30, %eax\n"
        "je .Lf4ae1a_0004aea1\n"
        "movl %ebx, (%esp)\n" /* line 1438 | i */
        "calll SND_Stop3DChannel\n"
        ".Lf4ae1a_0004aea1:\n"
        "addl $1, %ebx\n" /* line 1430 | i */
        "addl $0x50, %esi\n"
        "cmpl 0xffebc8, %ebx\n" /* i */
        "jl .Lf4ae1a_0004ae73\n"
        "movl 0xffebc4, %eax\n" /* line 1441 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jle .Lf4ae1a_0004ae4a\n"
        ".Lf4ae1a_0004aebc:\n"
        "movl $0x2d, %ebx\n" /* i */
        "movl $g_snd, %esi\n"
        ".Lf4ae1a_0004aec6:\n"
        "movl %ebx, (%esp)\n" /* line 1443 | i */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4ae1a_0004aef4\n"
        "movl 0x1168(%esi), %eax\n" /* line 1446 */
        "testb $1, 0x2c(%eax)\n"
        "je .Lf4ae1a_0004aef4\n"
        "movl 0x1150(%esi), %eax\n" /* line 1448 */
        "cmpl 0xffdb30, %eax\n"
        "je .Lf4ae1a_0004aef4\n"
        "movl %ebx, (%esp)\n" /* line 1449 | i */
        "calll SND_Stop2DChannel\n"
        ".Lf4ae1a_0004aef4:\n"
        "addl $1, %ebx\n" /* line 1441 | i */
        "addl $0x50, %esi\n"
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jl .Lf4ae1a_0004aec6\n"
        "movl 0xffebcc, %eax\n" /* line 1452 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jle .Lf4ae1a_0004ae5b\n"
        ".Lf4ae1a_0004af17:\n"
        "movl $0x20, %ebx\n" /* i */
        "movl $g_snd, %esi\n"
        ".Lf4ae1a_0004af21:\n"
        "movl %ebx, (%esp)\n" /* line 1454 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4ae1a_0004af4f\n"
        "movl 0xd58(%esi), %eax\n" /* line 1457 */
        "testb $1, 0x2c(%eax)\n"
        "je .Lf4ae1a_0004af4f\n"
        "movl 0xd40(%esi), %eax\n" /* line 1459 */
        "cmpl 0xffdb30, %eax\n"
        "je .Lf4ae1a_0004af4f\n"
        "movl %ebx, (%esp)\n" /* line 1460 | i */
        "calll SND_StopStreamChannel\n"
        ".Lf4ae1a_0004af4f:\n"
        "addl $1, %ebx\n" /* line 1452 | i */
        "addl $0x50, %esi\n"
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jl .Lf4ae1a_0004af21\n"
        "jmp .Lf4ae1a_0004ae5b\n"
    );
}

/* line 1474 */
__attribute__((naked))
Bool SND_UpdateBackgroundVolume(int track, int frametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1474 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* track */
        /* { scope 1 */
        "leal 0x20(%ecx), %edx\n" /* line 1480 */
        "movss 0xffda5c(, %ecx, 8), %xmm0\n" /* line 1484 */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "cvtsi2ssl 0xc(%ebp), %xmm1\n" /* frametime */
        "mulss %xmm0, %xmm1\n"
        "addss 0xffdb48(%eax), %xmm1\n"
        "pxor %xmm2, %xmm2\n" /* line 1485 */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf4af66_0004afcd\n"
        "movss 0xffda58(, %ecx, 8), %xmm0\n" /* line 1487 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf4af66_0004afe0\n"
        ".Lf4af66_0004afa9:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 1503 */
        "shll $4, %eax\n"
        "movl 0xffdb30, %edx\n"
        "movl %edx, 0xffdb40(%eax)\n"
        "movl $0xffdb40, %edx\n" /* line 1504 */
        "movss %xmm1, 8(%eax, %edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf4af66_0004afcb:\n"
        "leave\n" /* line 1506 */
        "retl\n"
        /* { scope 1 */
        ".Lf4af66_0004afcd:\n"
        "movss 0xffda58(, %ecx, 8), %xmm0\n" /* line 1492 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf4af66_0004afa9\n"
        "ucomiss %xmm2, %xmm0\n" /* line 1495 */
        "je .Lf4af66_0004b007\n"
        ".Lf4af66_0004afe0:\n"
        "movaps %xmm0, %xmm1\n" /* line 1498 */
        "leal (%edx, %edx, 4), %eax\n" /* line 1503 */
        "shll $4, %eax\n"
        "movl 0xffdb30, %edx\n"
        "movl %edx, 0xffdb40(%eax)\n"
        "movl $0xffdb40, %edx\n" /* line 1504 */
        "movss %xmm1, 8(%eax, %edx)\n"
        "movl $1, %eax\n"
        "jmp .Lf4af66_0004afcb\n"
        ".Lf4af66_0004b007:\n"
        "jp .Lf4af66_0004afe0\n" /* line 1495 */
        "movl %edx, (%esp)\n" /* line 1497 */
        "calll SND_StopStreamChannel\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 1506 */
        "retl\n"
    );
}

/* line 1712 */
__attribute__((naked))
jpeg_component_info SND_DeactivateEnvironmentEffects(int priority, int fademsec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1712 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 1725 | priority */
        "shll $5, %edx\n"
        "leal 0xffda78(%edx), %edi\n" /* effect */
        "movb $0, 0x1c(%edi)\n" /* line 1726 | effect */
        "cmpl 0xffdad8, %edi\n" /* line 1728 | effect */
        "je .Lf4b016_0004b03f\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1747 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4b016_0004b03f:\n"
        "movl 8(%ebp), %esi\n" /* line 1731 | priority, i */
        "subl $1, %esi\n" /* i */
        "js .Lf4b016_0004b059\n"
        "movl %esi, %eax\n" /* line 1733 | i */
        "shll $5, %eax\n"
        "cmpb $0, 0xffda94(%eax)\n"
        "je .Lf4b016_0004b0dc\n"
        ".Lf4b016_0004b059:\n"
        "movl %esi, %ebx\n" /* line 1731 | i */
        ".Lf4b016_0004b05b:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1738 | fademsec */
        "testl %eax, %eax\n"
        "jle .Lf4b016_0004b104\n"
        "cvtsi2ssl 0xc(%ebp), %xmm0\n" /* fademsec */
        "movss %xmm0, -0x1c(%ebp)\n"
        ".Lf4b016_0004b070:\n"
        "shll $5, %ebx\n" /* line 1741 */
        "leal 0xffda70(%ebx), %edx\n"
        "leal 8(%edx), %eax\n"
        "movl %eax, 0xffdad8\n"
        "movl 8(%edx), %eax\n" /* line 1742 */
        "movl %eax, (%esp)\n"
        "calll SND_SetRoomtype\n"
        "movl 4(%edi), %edx\n" /* line 1743 | effect */
        "movl 0xffdad8, %eax\n"
        "movl %edx, 4(%eax)\n"
        "movl 0xffdad8, %eax\n" /* line 1744 */
        "movss 8(%eax), %xmm0\n"
        "subss 4(%edi), %xmm0\n" /* effect */
        "divss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        "movl 0x10(%edi), %edx\n" /* line 1745 | effect */
        "movl 0xffdad8, %eax\n"
        "movl %edx, 0x10(%eax)\n"
        "movl 0xffdad8, %eax\n" /* line 1746 */
        "movss 0x14(%eax), %xmm0\n"
        "subss 0x10(%edi), %xmm0\n" /* effect */
        "divss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 0x18(%eax)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1747 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4b016_0004b0dc:\n"
        "addl $0xffda38, %edx\n" /* line 1734 */
        "movl %esi, %ebx\n" /* i */
        "xorl %ecx, %ecx\n"
        ".Lf4b016_0004b0e6:\n"
        "subl $1, %ebx\n" /* line 1731 */
        "cmpl %esi, %ecx\n" /* i */
        "je .Lf4b016_0004b05b\n"
        "movzbl 0x1c(%edx), %eax\n" /* line 1733 */
        "addl $1, %ecx\n"
        "subl $0x20, %edx\n"
        "testb %al, %al\n"
        "je .Lf4b016_0004b0e6\n"
        "jmp .Lf4b016_0004b05b\n"
        ".Lf4b016_0004b104:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 1738 | 1.0f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "jmp .Lf4b016_0004b070\n"
    );
}

/* line 1659 */
__attribute__((naked))
jpeg_component_info SND_SetEnvironmentEffects(int priority, const char *roomstring, float drylevel, float wetlevel, int fademsec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1659 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* priority */
        "movl %eax, -0x20(%ebp)\n" /* priority */
        "movl 0xc(%ebp), %edi\n" /* roomstring */
        "movss 0x10(%ebp), %xmm0\n" /* drylevel */
        "movss %xmm0, -0x24(%ebp)\n" /* drylevel */
        "movss 0x14(%ebp), %xmm1\n" /* wetlevel */
        "movss %xmm1, -0x28(%ebp)\n" /* wetlevel */
        "movl 0x18(%ebp), %eax\n" /* fademsec */
        "movl %eax, -0x2c(%ebp)\n" /* fademsec */
        /* { scope 1 */
        "cmpb $0, g_snd\n" /* line 1676 */
        "je .Lf4b116_0004b292\n"
        "movl -0x20(%ebp), %eax\n" /* line 1679 | priority */
        "shll $5, %eax\n"
        "leal 0xffda78(%eax), %esi\n" /* effect */
        "movb $1, 0x1c(%esi)\n" /* line 1680 | effect */
        "movl 0x195ed1c, %edx\n" /* line 104 */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf4b116_0004b192\n"
        "movl $0, -0x1c(%ebp)\n" /* roomtype */
        "movl %edx, %ebx\n"
        ".Lf4b116_0004b174:\n"
        "movl %eax, 4(%esp)\n" /* line 106 */
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf4b116_0004b1e2\n"
        "addl $1, -0x1c(%ebp)\n" /* line 104 | roomtype */
        "movl 4(%ebx), %eax\n"
        "addl $4, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf4b116_0004b174\n"
        ".Lf4b116_0004b192:\n"
        "movl %edi, 4(%esp)\n" /* line 110 */
        "movl $0x2188a0, (%esp)\n" /* "invalid roomtype string '%s', it must be one of the followin" */
        "calll Com_Printf\n"
        "movl 0x195ed1c, %edx\n" /* line 111 */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf4b116_0004b1db\n"
        "movl %edx, %ebx\n"
        "jmp .Lf4b116_0004b1bc\n"
        ".Lf4b116_0004b1b2:\n"
        "movl 4(%ebx), %eax\n"
        "addl $4, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lf4b116_0004b1db\n"
        ".Lf4b116_0004b1bc:\n"
        "cmpb $0, (%eax)\n" /* line 113 */
        "je .Lf4b116_0004b1b2\n"
        "movl %eax, 4(%esp)\n" /* line 114 */
        "movl $0x2182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        "movl 4(%ebx), %eax\n" /* line 111 */
        "addl $4, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf4b116_0004b1bc\n"
        ".Lf4b116_0004b1db:\n"
        "movl $0, -0x1c(%ebp)\n" /* roomtype */
        ".Lf4b116_0004b1e2:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1683 | roomtype */
        "movl %eax, (%esi)\n" /* effect */
        "movl -0x2c(%ebp), %eax\n" /* line 1685 | fademsec */
        "testl %eax, %eax\n"
        "jle .Lf4b116_0004b2b2\n"
        "cvtsi2ssl -0x2c(%ebp), %xmm0\n" /* fademsec */
        ".Lf4b116_0004b1f7:\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 1688 | drylevel */
        "movss %xmm1, 8(%esi)\n" /* effect */
        "movl 0xffdad8, %eax\n" /* line 1689 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 4(%esi)\n" /* effect */
        "movl 0xffdad8, %eax\n" /* line 1690 */
        "subss 4(%eax), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* drylevel */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esi)\n" /* effect */
        "movss -0x28(%ebp), %xmm1\n" /* line 1691 | wetlevel */
        "movss %xmm1, 0x14(%esi)\n" /* effect */
        "movl 0xffdad8, %eax\n" /* line 1692 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* effect */
        "movl 0xffdad8, %eax\n" /* line 1693 */
        "subss 0x10(%eax), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* wetlevel */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 0x18(%esi)\n" /* effect */
        "cmpl 0xffdad8, %esi\n" /* line 1695 | effect */
        "je .Lf4b116_0004b2a0\n"
        "movl -0x20(%ebp), %ecx\n" /* line 1701 | priority */
        "addl $1, %ecx\n"
        "cmpl $2, %ecx\n"
        "jg .Lf4b116_0004b29a\n"
        "movl %ecx, %eax\n" /* line 1703 */
        "shll $5, %eax\n"
        "cmpb $0, 0xffda94(%eax)\n"
        "jne .Lf4b116_0004b292\n"
        "shll $5, -0x20(%ebp)\n" /* line 1704 | priority */
        "movl -0x20(%ebp), %edx\n" /* priority */
        "addl $0xffdab8, %edx\n"
        ".Lf4b116_0004b27f:\n"
        "addl $1, %ecx\n" /* line 1701 */
        "cmpl $3, %ecx\n"
        "je .Lf4b116_0004b29a\n"
        "movzbl 0x1c(%edx), %eax\n" /* line 1703 */
        "addl $0x20, %edx\n"
        "testb %al, %al\n"
        "je .Lf4b116_0004b27f\n"
        /* } scope */
        ".Lf4b116_0004b292:\n"
        "addl $0x3c, %esp\n" /* line 1709 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4b116_0004b29a:\n"
        "movl %esi, 0xffdad8\n" /* line 1707 | effect */
        ".Lf4b116_0004b2a0:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1708 | roomtype */
        "movl %eax, 8(%ebp)\n" /* priority */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1709 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SND_SetRoomtype\n" /* line 1708 */
        ".Lf4b116_0004b2b2:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 1685 | 1.0f */
        "jmp .Lf4b116_0004b1f7\n"
    );
}

/* line 1750 */
__attribute__((naked))
jpeg_component_info SND_UpdateReverbs(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1750 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 0xffebc8, %eax\n" /* line 1754 */
        "testl %eax, %eax\n"
        "jg .Lf4b2c0_0004b2f0\n"
        ".Lf4b2c0_0004b2d0:\n"
        "movl 0xffebc4, %eax\n" /* line 1761 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4b2c0_0004b341\n"
        ".Lf4b2c0_0004b2dd:\n"
        "movl 0xffebcc, %eax\n" /* line 1768 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jg .Lf4b2c0_0004b315\n"
        /* } scope */
        ".Lf4b2c0_0004b2ea:\n"
        "addl $0x14, %esp\n" /* line 1774 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4b2c0_0004b2f0:\n"
        "xorl %ebx, %ebx\n" /* line 1754 | i */
        "jmp .Lf4b2c0_0004b2ff\n"
        ".Lf4b2c0_0004b2f4:\n"
        "addl $1, %ebx\n" /* i */
        "cmpl 0xffebc8, %ebx\n" /* i */
        "jge .Lf4b2c0_0004b2d0\n"
        ".Lf4b2c0_0004b2ff:\n"
        "movl %ebx, (%esp)\n" /* line 1756 | i */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4b2c0_0004b2f4\n"
        "movl %ebx, (%esp)\n" /* line 1758 | i */
        "calll SND_Update3DChannelReverb\n"
        "jmp .Lf4b2c0_0004b2f4\n"
        ".Lf4b2c0_0004b315:\n"
        "movl $0x20, %ebx\n" /* line 1768 | i */
        "jmp .Lf4b2c0_0004b32b\n"
        ".Lf4b2c0_0004b31c:\n"
        "addl $1, %ebx\n" /* i */
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4b2c0_0004b2ea\n"
        ".Lf4b2c0_0004b32b:\n"
        "movl %ebx, (%esp)\n" /* line 1770 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4b2c0_0004b31c\n"
        "movl %ebx, (%esp)\n" /* line 1772 | i */
        "calll SND_UpdateStreamChannelReverb\n"
        "jmp .Lf4b2c0_0004b31c\n"
        ".Lf4b2c0_0004b341:\n"
        "movl $0x2d, %ebx\n" /* line 1761 | i */
        "jmp .Lf4b2c0_0004b357\n"
        ".Lf4b2c0_0004b348:\n"
        "addl $1, %ebx\n" /* i */
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4b2c0_0004b2dd\n"
        ".Lf4b2c0_0004b357:\n"
        "movl %ebx, (%esp)\n" /* line 1763 | i */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4b2c0_0004b348\n"
        "movl %ebx, (%esp)\n" /* line 1765 | i */
        "calll SND_Update2DChannelReverb\n"
        "jmp .Lf4b2c0_0004b348\n"
    );
}

/* line 2072 */
__attribute__((naked))
jpeg_component_info SND_ErrorCleanup(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2072 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xffd81c, %eax\n" /* line 2074 */
        "testl %eax, %eax\n"
        "je .Lf4b36e_0004b38f\n"
        "movl %eax, (%esp)\n" /* line 2076 */
        "calll Z_FreeInternal\n"
        "movl $0, 0xffd81c\n" /* line 2077 */
        ".Lf4b36e_0004b38f:\n"
        "leave\n" /* line 2079 */
        "retl\n"
    );
}

/* line 246 */
__attribute__((naked))
jpeg_component_info SND_DisconnectListener(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 246 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "movl $0xffdaf4, %edi\n" /* line 248 */
        "cld\n"
        "movl $0xe, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "popl %edi\n" /* line 249 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 252 */
__attribute__((naked))
jpeg_component_info SND_SetListener(int entnum, const vec_t *origin, vec3_t *axis)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 252 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* origin */
        "cmpb $0, g_snd\n" /* line 256 */
        "je .Lf4b3a8_0004b3f4\n"
        "movl $0xffdb00, 4(%esp)\n" /* line 264 */
        "movl 0x10(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xffdaf4\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 0xffdaf8\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 0xffdafc\n"
        "movl 8(%ebp), %eax\n" /* line 267 | entnum */
        "movl %eax, 0xffdb24\n"
        "movb $1, 0xffdb28\n" /* line 268 */
        ".Lf4b3a8_0004b3f4:\n"
        "addl $0x14, %esp\n" /* line 269 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 347 */
__attribute__((naked))
jpeg_component_info SND_SetChannelInfo(int index, int entnum, const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, const vec_t *origin, float volume, float pitch, int srcChannelCount, int baserate, int total_msec, int start_msec, int startDelay, int master, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 347 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x1c(%ebp), %ebx\n" /* origin */
        "movl 0x30(%ebp), %edi\n" /* total_msec */
        "movzbl 0x3c(%ebp), %eax\n" /* master, volume */
        "movb %al, -0x49(%ebp)\n" /* volume, master */
        "cmpl $0x3ff, 0xc(%ebp)\n" /* line 354 | entnum */
        "ja .Lf4b3fa_0004b4f9\n"
        "movl 0x10(%ebp), %edx\n" /* line 332 | pAlias0 */
        "movl 0x2c(%edx), %ecx\n"
        "andl $0x780, %ecx\n"
        "sarl $7, %ecx\n"
        "cmpl $0xa, %ecx\n"
        "jbe .Lf4b3fa_0004b4e7\n"
        /* { scope 1 */
        ".Lf4b3fa_0004b435:\n"
        "leal -0x48(%ebp), %eax\n" /* line 364 | axis */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* org */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* entnum */
        "movl %ecx, (%esp)\n"
        "calll CG_GetEntityOrientation\n"
        "movss (%ebx), %xmm2\n" /* line 248 */
        "subss -0x24(%ebp), %xmm2\n" /* org */
        "movss 4(%ebx), %xmm3\n" /* line 249 */
        "subss -0x20(%ebp), %xmm3\n"
        "movss 8(%ebx), %xmm4\n" /* line 250 */
        "subss -0x1c(%ebp), %xmm4\n"
        "movl 8(%ebp), %ebx\n" /* line 367 | index, origin */
        "leal (%ebx, %ebx, 4), %eax\n" /* origin */
        "shll $4, %eax\n"
        "movaps %xmm2, %xmm0\n"
        "mulss -0x48(%ebp), %xmm0\n" /* axis */
        "movaps %xmm3, %xmm1\n"
        "mulss -0x44(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0x40(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xffdb70(%eax)\n"
        "movaps %xmm2, %xmm0\n" /* line 368 */
        "mulss -0x3c(%ebp), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss -0x38(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0x34(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xffdb74(%eax)\n"
        "mulss -0x30(%ebp), %xmm2\n" /* line 369 */
        "mulss -0x2c(%ebp), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss -0x28(%ebp), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss %xmm2, 0xffdb78(%eax)\n"
        "movl %ebx, %ecx\n" /* origin */
        "jmp .Lf4b3fa_0004b518\n"
        /* } scope */
        ".Lf4b3fa_0004b4e7:\n"
        "movl $1, %eax\n" /* line 332 */
        "shll %cl, %eax\n"
        "testl $0x786, %eax\n"
        "je .Lf4b3fa_0004b435\n"
        ".Lf4b3fa_0004b4f9:\n"
        "movl 8(%ebp), %edx\n" /* line 356 | index */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "addl $0xffdb60, %eax\n"
        "leal 0x10(%eax), %ecx\n" /* v */
        /* { scope 1 */
        "xorl %edx, %edx\n" /* line 183 */
        "movl %edx, 0x10(%eax)\n"
        "movl %edx, 4(%ecx)\n" /* line 184 */
        "movl %edx, 8(%ecx)\n" /* line 185 */
        "movl 8(%ebp), %ecx\n" /* index */
        /* } scope */
        ".Lf4b3fa_0004b518:\n"
        "movl $0xffdb30, %esi\n" /* line 372 */
        "leal (%ecx, %ecx, 4), %edx\n"
        "shll $4, %edx\n"
        "movl 0xc(%ebp), %ebx\n" /* entnum, origin */
        "movl %ebx, 4(%edx, %esi)\n" /* origin */
        "movl 0x10(%ebp), %ecx\n" /* line 373 | pAlias0 */
        "movl 0x2c(%ecx), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, 8(%edx, %esi)\n"
        "movl $0xffdb40, %ebx\n" /* line 374 | origin */
        "movl 0x20(%ebp), %eax\n" /* volume */
        "movl %eax, 8(%edx, %ebx)\n"
        "movl 0x24(%ebp), %eax\n" /* line 375 | pitch */
        "movl %eax, 0x10(%edx, %ebx)\n"
        "movl $0xffdb50, %ecx\n" /* line 376 */
        "movl 0x28(%ebp), %eax\n" /* srcChannelCount */
        "movl %eax, 4(%edx, %ecx)\n"
        "movl 0x2c(%ebp), %eax\n" /* line 377 | baserate */
        "movl %eax, 0xc(%edx, %ebx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 378 | pAlias0 */
        "movl %eax, 8(%edx, %ecx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 379 | pAlias1 */
        "movl %eax, 0xc(%edx, %ecx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 380 | lerp */
        "movl %eax, 0x10(%edx, %ecx)\n"
        "movl 0x38(%ebp), %eax\n" /* line 381 | startDelay */
        "movl %eax, 0xc(%edx, %esi)\n"
        "movl 0xffdb30, %eax\n" /* line 382 */
        "movl %eax, 0x10(%edx, %esi)\n"
        "addl 0xffdb2c, %edi\n" /* line 383 | total_msec */
        "subl 0x34(%ebp), %edi\n" /* start_msec, total_msec */
        "movl %edi, 4(%edx, %ebx)\n" /* total_msec */
        "cmpb $0, 0xffd802\n" /* line 384 */
        "je .Lf4b3fa_0004b5bb\n"
        "movl 0x10(%ebp), %edx\n" /* pAlias0 */
        "movl 0x2c(%edx), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "cmpb $0, 0xffdae7(%eax)\n"
        "je .Lf4b3fa_0004b5bb\n"
        "movl $1, %ecx\n"
        "jmp .Lf4b3fa_0004b5bd\n"
        ".Lf4b3fa_0004b5bb:\n"
        "xorl %ecx, %ecx\n"
        ".Lf4b3fa_0004b5bd:\n"
        "movl $0xffdb70, %eax\n"
        "movl 8(%ebp), %ebx\n" /* index, origin */
        "leal (%ebx, %ebx, 4), %edx\n" /* origin */
        "shll $4, %edx\n"
        "movb %cl, 0xc(%edx, %eax)\n"
        "movzbl -0x49(%ebp), %ecx\n" /* line 385 | master */
        "movb %cl, 0xd(%edx, %eax)\n"
        "movl 0x40(%ebp), %ecx\n" /* line 386 | system */
        "movl %ecx, 0x10(%edx, %eax)\n"
        "addl $0x5c, %esp\n" /* line 387 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 313 */
__attribute__((naked))
jpeg_component_info SND_GetCurrent3DPosition(int entnum, const vec_t *offset, vec_t *pos_out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 313 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* offset */
        "movl 0x10(%ebp), %esi\n" /* pos_out */
        /* { scope 1 */
        "leal -0x38(%ebp), %eax\n" /* line 322 | axis */
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* org */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* entnum */
        "movl %eax, (%esp)\n"
        "calll CG_GetEntityOrientation\n"
        "movss (%ebx), %xmm1\n" /* line 323 | offset, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x38(%ebp), %xmm0\n" /* axis */
        "addss -0x14(%ebp), %xmm0\n" /* org */
        "movss %xmm0, -0x14(%ebp)\n" /* org */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x34(%ebp), %xmm0\n"
        "addss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "mulss -0x30(%ebp), %xmm1\n" /* line 290 */
        "addss -0xc(%ebp), %xmm1\n"
        "movss %xmm1, -0xc(%ebp)\n"
        /* } scope */
        "movss 4(%ebx), %xmm1\n" /* line 324 | offset, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss -0x14(%ebp), %xmm0\n" /* org */
        "movss %xmm0, -0x14(%ebp)\n" /* org */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x28(%ebp), %xmm0\n"
        "addss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "mulss -0x24(%ebp), %xmm1\n" /* line 290 */
        "addss -0xc(%ebp), %xmm1\n"
        "movss %xmm1, -0xc(%ebp)\n"
        /* } scope */
        "movss 8(%ebx), %xmm0\n" /* line 325 | offset, scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm2\n" /* line 288 */
        "mulss -0x20(%ebp), %xmm2\n"
        "addss -0x14(%ebp), %xmm2\n" /* org */
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss -0x1c(%ebp), %xmm1\n"
        "addss -0x10(%ebp), %xmm1\n"
        "mulss -0x18(%ebp), %xmm0\n" /* line 290 */
        "addss -0xc(%ebp), %xmm0\n"
        /* } scope */
        "movss %xmm2, (%esi)\n" /* line 199 */
        "movss %xmm1, 4(%esi)\n" /* line 200 */
        "movss %xmm0, 8(%esi)\n" /* line 201 */
        /* } scope */
        "addl $0x40, %esp\n" /* line 327 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2697 */
__attribute__((naked))
int SND_GetSoundOverlay(snd_overlay_type_t type, snd_overlay_info_t *info, int maxcount, int *cpu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2697 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %edx\n" /* type */
        "movl 0x10(%ebp), %edi\n" /* maxcount */
        "movl 0x14(%ebp), %ecx\n" /* cpu */
        "cmpb $0, g_snd\n" /* line 2702 */
        "je .Lf4b6ba_0004b6f7\n"
        "testl %ecx, %ecx\n" /* line 2705 */
        "je .Lf4b6ba_0004b6e0\n"
        "movl 0xffd818, %eax\n" /* line 2706 */
        "movl %eax, (%ecx)\n"
        ".Lf4b6ba_0004b6e0:\n"
        "cmpl $2, %edx\n" /* line 2708 */
        "je .Lf4b6ba_0004b703\n"
        "cmpl $3, %edx\n"
        "je .Lf4b6ba_0004b963\n"
        "subl $1, %edx\n"
        "je .Lf4b6ba_0004b810\n"
        /* { scope 1 */
        ".Lf4b6ba_0004b6f7:\n"
        "xorl %edi, %edi\n" /* line 2654 */
        /* } scope */
        ".Lf4b6ba_0004b6f9:\n"
        "movl %edi, %eax\n" /* line 2719 | maxcount */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4b6ba_0004b703:\n"
        "movl 0xffebcc, %eax\n" /* line 2651 */
        "cmpl %eax, %edi\n"
        "cmovgl %eax, %edi\n"
        "testl %edi, %edi\n" /* line 2654 */
        "jle .Lf4b6ba_0004b6f9\n"
        "movl 0xc(%ebp), %esi\n" /* info, channel */
        "movl $0, -0x3c(%ebp)\n" /* i */
        "movl $g_snd, -0x34(%ebp)\n"
        "movl $0xffe570, -0x58(%ebp)\n"
        "jmp .Lf4b6ba_0004b745\n"
        ".Lf4b6ba_0004b72b:\n"
        "movl $0, (%esi)\n" /* line 2659 | channel */
        ".Lf4b6ba_0004b731:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 2654 | i */
        "addl $0x50, -0x58(%ebp)\n"
        "addl $0x14, %esi\n" /* channel */
        "addl $0x50, -0x34(%ebp)\n"
        "cmpl -0x3c(%ebp), %edi\n" /* i */
        "je .Lf4b6ba_0004b6f9\n"
        ".Lf4b6ba_0004b745:\n"
        "movl -0x3c(%ebp), %ebx\n" /* i, channel */
        "addl $0x20, %ebx\n" /* channel */
        "movl %ebx, (%esp)\n" /* line 2657 | channel */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4b6ba_0004b72b\n"
        "movl -0x34(%ebp), %edx\n" /* line 2697 | type */
        "addl $0xd58, %edx\n" /* type */
        "movl %edx, -0x30(%ebp)\n" /* type */
        "movl -0x34(%ebp), %edx\n" /* line 2665 */
        "movl 0xd58(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileName\n"
        "movl %eax, (%esi)\n" /* channel */
        "movl %ebx, (%esp)\n" /* line 2667 | channel */
        "calll SND_GetStreamChannelPlaybackRate\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movl -0x34(%ebp), %eax\n"
        "cvtsi2ssl 0xd4c(%eax), %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%esi)\n" /* channel */
        "movl -0x34(%ebp), %edx\n" /* line 2668 */
        "movl 0xd48(%edx), %eax\n"
        "movl %eax, 4(%esi)\n" /* channel */
        "movl %ebx, (%esp)\n" /* line 2669 | channel */
        "calll SND_GetStreamChannelVolume\n"
        "fstps -0x40(%ebp)\n"
        "movss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esi)\n" /* channel */
        "movss 0xffd824, %xmm0\n" /* line 2670 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf4b6ba_0004b7ca\n"
        "je .Lf4b6ba_0004b7d8\n"
        ".Lf4b6ba_0004b7ca:\n"
        "movss -0x40(%ebp), %xmm1\n" /* line 2671 */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esi)\n" /* channel */
        ".Lf4b6ba_0004b7d8:\n"
        "movl -0x30(%ebp), %edx\n" /* line 332 */
        "movl (%edx), %eax\n"
        "movl 0x2c(%eax), %ecx\n"
        "andl $0x780, %ecx\n"
        "sarl $7, %ecx\n"
        "cmpl $0xa, %ecx\n"
        "ja .Lf4b6ba_0004b921\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x786, %eax\n"
        "je .Lf4b6ba_0004b921\n"
        "movl $0xffffffff, 0xc(%esi)\n" /* line 2676 | channel */
        "jmp .Lf4b6ba_0004b731\n"
        /* } scope */
        /* { scope 1 */
        ".Lf4b6ba_0004b810:\n"
        "movl 0xffebc8, %eax\n" /* line 2602 */
        "cmpl %eax, %edi\n"
        "cmovgl %eax, %edi\n"
        "testl %edi, %edi\n" /* line 2605 */
        "jle .Lf4b6ba_0004b6f9\n"
        "movl 0xc(%ebp), %ebx\n" /* info */
        "movl $0, -0x48(%ebp)\n" /* channel */
        "movl $g_snd, %esi\n" /* channel */
        "movl $0xffdb70, -0x5c(%ebp)\n"
        "jmp .Lf4b6ba_0004b857\n"
        ".Lf4b6ba_0004b83a:\n"
        "movl $0, (%ebx)\n" /* line 2610 */
        ".Lf4b6ba_0004b840:\n"
        "addl $1, -0x48(%ebp)\n" /* line 2605 | channel */
        "addl $0x50, -0x5c(%ebp)\n"
        "addl $0x14, %ebx\n"
        "addl $0x50, %esi\n" /* channel */
        "cmpl -0x48(%ebp), %edi\n" /* channel */
        "je .Lf4b6ba_0004b6f9\n"
        ".Lf4b6ba_0004b857:\n"
        "movl -0x48(%ebp), %eax\n" /* line 2608 | channel */
        "movl %eax, (%esp)\n"
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4b6ba_0004b83a\n"
        "movl 0x358(%esi), %eax\n" /* line 2616 | channel */
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileName\n"
        "movl %eax, (%ebx)\n"
        "movl -0x48(%ebp), %edx\n" /* line 2618 | channel */
        "movl %edx, (%esp)\n"
        "calll SND_Get3DChannelPlaybackRate\n"
        "testl %eax, %eax\n" /* line 2619 */
        "jne .Lf4b6ba_0004b88b\n"
        "movl 0x34c(%esi), %eax\n" /* line 2620 | channel */
        ".Lf4b6ba_0004b88b:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 2622 */
        "cvtsi2ssl 0x34c(%esi), %xmm1\n" /* channel */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%ebx)\n"
        "movl 0x348(%esi), %eax\n" /* line 2623 | channel */
        "movl %eax, 4(%ebx)\n"
        "movl -0x48(%ebp), %eax\n" /* line 2624 | channel */
        "movl %eax, (%esp)\n"
        "calll SND_Get3DChannelVolume\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "movss 0xffd824, %xmm0\n" /* line 2625 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf4b6ba_0004b8d4\n"
        "je .Lf4b6ba_0004b8e2\n"
        ".Lf4b6ba_0004b8d4:\n"
        "movss -0x4c(%ebp), %xmm1\n" /* line 2626 */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ebx)\n"
        ".Lf4b6ba_0004b8e2:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2628 | org */
        "movl %eax, 8(%esp)\n"
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x334(%esi), %eax\n" /* channel */
        "movl %eax, (%esp)\n"
        "calll SND_GetCurrent3DPosition\n"
        "movl $0xffdaf4, 4(%esp)\n" /* line 2629 */
        "leal -0x24(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "calll Vec3Distance\n"
        "fstps -0x44(%ebp)\n" /* dist */
        "cvttss2si -0x44(%ebp), %eax\n" /* line 2630 | dist */
        "movl %eax, 0xc(%ebx)\n"
        "jmp .Lf4b6ba_0004b840\n"
        /* } scope */
        /* { scope 1 */
        ".Lf4b6ba_0004b921:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2680 | org */
        "movl %eax, 8(%esp)\n"
        "movl -0x58(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl 0xd34(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_GetCurrent3DPosition\n"
        "movl $0xffdaf4, 4(%esp)\n" /* line 2681 */
        "leal -0x24(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "calll Vec3Distance\n"
        "fstps -0x38(%ebp)\n" /* dist */
        "cvttss2si -0x38(%ebp), %eax\n" /* line 2682 | dist */
        "movl %eax, 0xc(%esi)\n" /* channel */
        "jmp .Lf4b6ba_0004b731\n"
        /* } scope */
        /* { scope 1 */
        ".Lf4b6ba_0004b963:\n"
        "movl 0xffebc4, %eax\n" /* line 2562 */
        "cmpl %eax, %edi\n"
        "cmovgl %eax, %edi\n"
        "testl %edi, %edi\n" /* line 2565 */
        "jle .Lf4b6ba_0004b6f9\n"
        "movl 0xc(%ebp), %ebx\n" /* info */
        "movl $0, -0x50(%ebp)\n" /* i */
        "movl $g_snd, -0x2c(%ebp)\n"
        "jmp .Lf4b6ba_0004b9a2\n"
        ".Lf4b6ba_0004b988:\n"
        "movl $0, (%ebx)\n" /* line 2570 */
        ".Lf4b6ba_0004b98e:\n"
        "addl $1, -0x50(%ebp)\n" /* line 2565 | i */
        "addl $0x14, %ebx\n"
        "addl $0x50, -0x2c(%ebp)\n"
        "cmpl -0x50(%ebp), %edi\n" /* i */
        "je .Lf4b6ba_0004b6f9\n"
        ".Lf4b6ba_0004b9a2:\n"
        "movl -0x50(%ebp), %esi\n" /* i, channel */
        "addl $0x2d, %esi\n" /* channel */
        "movl %esi, (%esp)\n" /* line 2568 | channel */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4b6ba_0004b988\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2576 */
        "movl 0x1168(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileName\n"
        "movl %eax, (%ebx)\n"
        "movl %esi, (%esp)\n" /* line 2578 | channel */
        "calll SND_Get2DChannelPlaybackRate\n"
        "testl %eax, %eax\n" /* line 2579 */
        "jne .Lf4b6ba_0004b9dc\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2580 */
        "movl 0x115c(%edx), %eax\n"
        ".Lf4b6ba_0004b9dc:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 2582 */
        "movl -0x2c(%ebp), %eax\n"
        "cvtsi2ssl 0x115c(%eax), %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%ebx)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2583 */
        "movl 0x1158(%edx), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl %esi, (%esp)\n" /* line 2584 | channel */
        "calll SND_Get2DChannelVolume\n"
        "fstps -0x54(%ebp)\n"
        "movss -0x54(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "movss 0xffd824, %xmm0\n" /* line 2585 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf4b6ba_0004ba28\n"
        "je .Lf4b6ba_0004ba36\n"
        ".Lf4b6ba_0004ba28:\n"
        "movss -0x54(%ebp), %xmm1\n" /* line 2586 */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ebx)\n"
        ".Lf4b6ba_0004ba36:\n"
        "movl $0xffffffff, 0xc(%ebx)\n" /* line 2587 */
        "jmp .Lf4b6ba_0004b98e\n"
    );
}

/* line 563 */
static __attribute__((naked))
int SND_StartAliasStream(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int treatAsMaster, int *pChannel, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 563 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %edx, -0x44(%ebp)\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "movss %xmm2, -0x54(%ebp)\n"
        "movss %xmm3, -0x58(%ebp)\n"
        "movzbl 0x10(%ebp), %eax\n" /* treatAsMaster */
        "movb %al, -0x59(%ebp)\n" /* treatAsMaster */
        /* { scope 1 */
        "movl -0x40(%ebp), %edx\n" /* line 575 */
        "movl 0x2c(%edx), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* entchannel */
        /* { scope 2 */
        "cmpl $3, 0xffebcc\n" /* line 479 */
        "jg .Lf4ba42_0004bccf\n"
        /* } scope */
        ".Lf4ba42_0004ba90:\n"
        "movl 0xffebcc, %edx\n" /* line 429 */
        "addl $0x20, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl $0x23, %edx\n"
        "jle .Lf4ba42_0004bb80\n"
        "movl $0x23, -0x34(%ebp)\n" /* index */
        "movl $0xffffffff, %esi\n"
        "movl $g_snd, %edi\n"
        ".Lf4ba42_0004bab6:\n"
        "movl 0xe28(%edi), %eax\n" /* line 415 */
        "cmpl %eax, -0x30(%ebp)\n" /* line 431 | entchannel */
        "jl .Lf4ba42_0004bb05\n"
        "testl %esi, %esi\n" /* line 433 */
        "js .Lf4ba42_0004bc9d\n"
        "movl 0xe24(%edi), %ebx\n" /* line 393 */
        "leal (%esi, %esi, 4), %edx\n"
        "shll $4, %edx\n"
        "movl 0xffdb34(%edx), %ecx\n"
        "cmpl %ecx, %ebx\n"
        "je .Lf4ba42_0004baed\n"
        "cmpl %ebx, -0x4c(%ebp)\n" /* line 395 */
        "je .Lf4ba42_0004bc9d\n"
        "cmpl %ecx, -0x4c(%ebp)\n" /* line 397 */
        "je .Lf4ba42_0004bb05\n"
        ".Lf4ba42_0004baed:\n"
        "movl 0xffdb38(%edx), %ecx\n" /* line 402 */
        "cmpl %ecx, %eax\n"
        "je .Lf4ba42_0004bcb2\n"
        "subl %ecx, %eax\n" /* line 403 */
        ".Lf4ba42_0004bafd:\n"
        "testl %eax, %eax\n" /* line 433 */
        "js .Lf4ba42_0004bc9d\n"
        ".Lf4ba42_0004bb05:\n"
        "addl $1, -0x34(%ebp)\n" /* line 429 | index */
        "addl $0x50, %edi\n"
        "movl -0x34(%ebp), %eax\n" /* index */
        "cmpl %eax, -0x2c(%ebp)\n"
        "jne .Lf4ba42_0004bab6\n"
        "testl %esi, %esi\n" /* line 580 */
        "js .Lf4ba42_0004bb85\n"
        "leal (%esi, %esi, 4), %edi\n" /* line 582 */
        "shll $4, %edi\n"
        "movl -0x40(%ebp), %edx\n"
        "cmpl 0xffdb58(%edi), %edx\n"
        "je .Lf4ba42_0004bb33\n"
        ".Lf4ba42_0004bb29:\n"
        "movl %esi, (%esp)\n" /* line 590 */
        "calll SND_StopStreamChannel\n"
        "jmp .Lf4ba42_0004bb85\n"
        ".Lf4ba42_0004bb33:\n"
        "movl 0xffdaf4, %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n" /* listenerOrg */
        "movl 0xffdaf8, %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xffdafc, %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %ebx\n" /* line 589 | listenerOrg, i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 8(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x3c(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "leal 0xffdb64(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x38(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "ucomiss -0x3c(%ebp), %xmm0\n"
        "ja .Lf4ba42_0004bb29\n"
        ".Lf4ba42_0004bb80:\n"
        "movl $0xffffffff, %esi\n"
        ".Lf4ba42_0004bb85:\n"
        "movl 0x14(%ebp), %eax\n" /* line 597 | pChannel */
        "testl %eax, %eax\n"
        "je .Lf4ba42_0004bb91\n"
        "movl 0x14(%ebp), %eax\n" /* line 598 | pChannel */
        "movl %esi, (%eax)\n"
        ".Lf4ba42_0004bb91:\n"
        "testl %esi, %esi\n" /* line 599 */
        "js .Lf4ba42_0004bca5\n"
        "movl snd_enableStream, %eax\n" /* line 603 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf4ba42_0004bca5\n"
        "movl -0x40(%ebp), %edx\n" /* line 332 */
        "movl 0x2c(%edx), %ecx\n"
        "andl $0x780, %ecx\n"
        "sarl $7, %ecx\n"
        "cmpl $0xa, %ecx\n"
        "jbe .Lf4ba42_0004bc5c\n"
        "cmpb $0, 0xffdb28\n" /* line 605 */
        "je .Lf4ba42_0004bc7b\n"
        ".Lf4ba42_0004bbcd:\n"
        "cmpb $0, -0x59(%ebp)\n" /* line 608 | treatAsMaster */
        "jne .Lf4ba42_0004bbe0\n"
        "movl -0x40(%ebp), %eax\n"
        "testb $2, 0x2c(%eax)\n"
        "je .Lf4ba42_0004bd01\n"
        ".Lf4ba42_0004bbe0:\n"
        "movl $1, %eax\n"
        ".Lf4ba42_0004bbe5:\n"
        "movl 0x18(%ebp), %edx\n" /* system */
        "movl %edx, 0x30(%esp)\n"
        "movl %esi, 0x2c(%esp)\n"
        "movl %eax, 0x28(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "movss %xmm0, 0x20(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* timeshift */
        "movl %eax, 0x1c(%esp)\n"
        "movss -0x54(%ebp), %xmm0\n"
        "movss %xmm0, 0x18(%esp)\n"
        "movss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, 0x14(%esp)\n"
        "movl 8(%ebp), %eax\n" /* org */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SND_StartAliasStreamOnChannel\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 609 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4ba42_0004bc5c:\n"
        "movl $1, %eax\n" /* line 332 */
        "shll %cl, %eax\n"
        "testl $0x786, %eax\n"
        "jne .Lf4ba42_0004bbcd\n"
        "cmpb $0, 0xffdb28\n" /* line 605 */
        "jne .Lf4ba42_0004bbcd\n"
        ".Lf4ba42_0004bc7b:\n"
        "movl -0x40(%ebp), %edx\n" /* line 606 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2188e8, 4(%esp)\n" /* "attempted to play spatialized alias '%s' while there is no a" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf4ba42_0004bbcd\n"
        ".Lf4ba42_0004bc9d:\n"
        "movl -0x34(%ebp), %esi\n" /* line 433 | index */
        "jmp .Lf4ba42_0004bb05\n"
        ".Lf4ba42_0004bca5:\n"
        "xorl %eax, %eax\n" /* line 608 */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 609 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4ba42_0004bcb2:\n"
        "movl 0xe34(%edi), %ecx\n" /* line 406 */
        "movl 0xffdb44(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf4ba42_0004bb05\n"
        "subl %eax, %ecx\n" /* line 407 */
        "movl %ecx, %eax\n"
        "jmp .Lf4ba42_0004bafd\n"
        /* { scope 2 */
        ".Lf4ba42_0004bccf:\n"
        "movl $3, %ebx\n" /* line 479 | i */
        "jmp .Lf4ba42_0004bce5\n"
        ".Lf4ba42_0004bcd6:\n"
        "addl $1, %ebx\n" /* i */
        "cmpl 0xffebcc, %ebx\n" /* i */
        "jge .Lf4ba42_0004ba90\n"
        ".Lf4ba42_0004bce5:\n"
        "leal 0x20(%ebx), %esi\n" /* i */
        "movl %esi, (%esp)\n" /* line 481 */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4ba42_0004bcd6\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 577 */
        "jns .Lf4ba42_0004bb85\n"
        "jmp .Lf4ba42_0004ba90\n"
        ".Lf4ba42_0004bd01:\n"
        "xorl %eax, %eax\n" /* line 608 */
        "jmp .Lf4ba42_0004bbe5\n"
    );
}

/* line 2082 */
static __attribute__((naked))
jpeg_component_info SND_SaveChanInfo(MemoryFile *memFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2082 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ebx\n" /* chaninfo */
        "movl %edx, -0x2c(%ebp)\n"
        "movswl (%eax), %eax\n"
        "movw %ax, -0x1c(%ebp)\n" /* value */
        /* { scope 1: value */
        "leal -0x1c(%ebp), %esi\n" /* line 88 | value */
        "movl %esi, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteData\n"
        "movzbl 4(%ebx), %eax\n"
        "movb %al, -0x1c(%ebp)\n" /* value */
        /* } scope */
        /* { scope 1: value */
        "movl %esi, 8(%esp)\n" /* line 81 */
        "movl $1, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "movzbl 0x49(%ebx), %eax\n"
        "movb %al, -0x1c(%ebp)\n" /* value */
        /* } scope */
        /* { scope 1: value */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* value */
        /* } scope */
        /* { scope 1: value */
        "movl %esi, 8(%esp)\n" /* line 95 */
        "movl $4, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* value */
        /* } scope */
        /* { scope 1: value */
        "movl %esi, 8(%esp)\n" /* line 102 */
        "movl $4, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "movl 0x2c(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* value */
        /* } scope */
        /* { scope 1: value */
        "movl %esi, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        /* } scope */
        "leal 0x3c(%ebx), %edi\n" /* line 2094 | chaninfo, value */
        "movl 0x3c(%ebx), %eax\n" /* chaninfo */
        "movl %eax, -0x1c(%ebp)\n" /* value */
        /* { scope 1: value */
        /* { scope 2 */
        "movl %esi, 8(%esp)\n" /* line 102 */
        "movl $4, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* value */
        /* } scope */
        /* { scope 2 */
        "movl %esi, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* value */
        /* } scope */
        /* { scope 2 */
        "movl %esi, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2095 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1972 */
__attribute__((naked))
jpeg_component_info SND_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1972 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "movl $0x218988, (%esp)\n" /* line 1976 */
        "calll Com_Printf\n"
        "movl $0x1001, 8(%esp)\n" /* line 1978 */
        "movl $0, 4(%esp)\n"
        "movl $0x2189b8, (%esp)\n" /* "snd_errorOnMissing" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, snd_errorOnMissing\n"
        "movl $0x1021, 0x10(%esp)\n" /* line 1979 */
        "movl $0x2c, 0xc(%esp)\n"
        "movl $0xb, 8(%esp)\n"
        "movl $0x2c, 4(%esp)\n"
        "movl $0x2189cc, (%esp)\n" /* "snd_khz" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, snd_khz\n"
        "movl $0x1021, 0x10(%esp)\n" /* line 1980 */
        "movl $0x10, 0xc(%esp)\n"
        "movl $8, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl $0x2189d4, (%esp)\n" /* "snd_bits" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, snd_bits\n"
        "movl $0x1021, 8(%esp)\n" /* line 1981 */
        "movl $1, 4(%esp)\n"
        "movl $0x2189e0, (%esp)\n" /* "snd_stereo" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, snd_stereo\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 1982 */
        "movl $0x3f800000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2189ec, (%esp)\n" /* "snd_volume" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, snd_volume\n"
        "movl $0x1081, 0x10(%esp)\n" /* line 1983 */
        "movl $0x1388, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1f4, 4(%esp)\n"
        "movl $0x2189f8, (%esp)\n" /* "snd_slaveFadeTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, snd_slaveFadeTime\n"
        "movl $0x1080, 8(%esp)\n" /* line 1984 */
        "movl $1, 4(%esp)\n"
        "movl $0x218a0c, (%esp)\n" /* "snd_enable2D" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, snd_enable2D\n"
        "movl $0x1080, 8(%esp)\n" /* line 1985 */
        "movl $1, 4(%esp)\n"
        "movl $0x218a1c, (%esp)\n" /* "snd_enable3D" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, snd_enable3D\n"
        "movl $0x1080, 8(%esp)\n" /* line 1986 */
        "movl $1, 4(%esp)\n"
        "movl $0x218a2c, (%esp)\n" /* "snd_enableStream" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, snd_enableStream\n"
        "movl $0x1080, 8(%esp)\n" /* line 1987 */
        "movl $1, 4(%esp)\n"
        "movl $0x218a40, (%esp)\n" /* "snd_enableReverb" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, snd_enableReverb\n"
        "movl $0x1001, 8(%esp)\n" /* line 1989 */
        "movl $0, 4(%esp)\n"
        "movl $0x218a54, (%esp)\n" /* "snd_touchStreamFilesOnLoad" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, snd_touchStreamFilesOnLoad\n"
        "movl $0xffda78, 0xffdad8\n" /* line 1992 */
        "movl $0, 0xffda78\n" /* line 1993 */
        "movl %esi, 0xffda7c\n" /* line 1994 */
        "movl %esi, 0xffda80\n" /* line 1995 */
        "movl %ebx, 0xffda84\n" /* line 1996 */
        "movl %ebx, 0xffda88\n" /* line 1997 */
        "movl %ebx, 0xffda8c\n" /* line 1998 */
        "movl %ebx, 0xffda90\n" /* line 1999 */
        "movb $1, 0xffda94\n" /* line 2000 */
        "calll SND_InitDriver\n" /* line 2002 */
        "testb %al, %al\n"
        "je .Lf4be2a_0004c145\n"
        "movl %esi, 0xffd828\n" /* line 2005 */
        "movl %esi, 0xffd82c\n" /* line 2006 */
        "movl %ebx, 0xffd830\n" /* line 2007 */
        "movl $0xffd834, 0xffda54\n" /* line 2008 */
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf4be2a_0004c050:\n"
        "movl 0xffda54, %eax\n" /* line 2011 */
        "movl $0x3f800000, (%edx, %eax)\n"
        "movl %edx, %eax\n" /* line 2012 */
        "addl 0xffda54, %eax\n"
        "movl $0x3f800000, 4(%eax)\n"
        "movl %edx, %eax\n" /* line 2013 */
        "addl 0xffda54, %eax\n"
        "movl $0, 8(%eax)\n"
        "addl $1, %ecx\n" /* line 2009 */
        "addl $0xc, %edx\n"
        "cmpl $0xb, %ecx\n"
        "jne .Lf4be2a_0004c050\n"
        "movl 0xffda54, %eax\n" /* line 2015 */
        "movb $1, 0x84(%eax)\n"
        "calll Sys_Milliseconds\n" /* line 2017 */
        "movl %eax, 0xffdb2c\n"
        "movl %eax, 0xffdb30\n" /* line 2018 */
        "movl $0, 0xffda74\n" /* line 2019 */
        "movss 0x2ed67c, %xmm0\n" /* line 2020 | 0.75f */
        "movl snd_volume, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, 0xffd824\n"
        "movl $0x1010101, 0xffdadc\n" /* line 2022 */
        "movl $0x1010101, 0xffdae0\n"
        "movw $0x101, 0xffdae4\n"
        "movb $1, 0xffdae6\n"
        "movb $0, 0xffdade\n" /* line 2023 */
        "movl $g_snd, %edx\n"
        ".Lf4be2a_0004c0f4:\n"
        "movzbl 0x2dc(%edx), %eax\n" /* line 1100 */
        "movb %al, 0x2e7(%edx)\n"
        "addl $1, %edx\n"
        "cmpl $0xffd80b, %edx\n" /* line 1099 */
        "jne .Lf4be2a_0004c0f4\n"
        "movl $SND_SetEnvironmentEffects_f, 4(%esp)\n" /* line 2026 */
        "movl $0x218a70, (%esp)\n" /* "snd_setEnvironmentEffects" */
        "calll Cmd_AddCommand\n"
        "movl $SND_DeactivateEnvironmentEffects_f, 4(%esp)\n" /* line 2027 */
        "movl $0x218a8c, (%esp)\n" /* "snd_deactivateEnvironmentEffects" */
        "calll Cmd_AddCommand\n"
        "movl $0x218ab0, (%esp)\n" /* line 2029 */
        "calll Com_Printf\n"
        "calll Voice_Init\n" /* line 2032 */
        /* } scope */
        ".Lf4be2a_0004c145:\n"
        "addl $0x20, %esp\n" /* line 2034 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 822 */
static __attribute__((naked))
int SND_PlaySoundAlias_Internal(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, int *pChannel, int timeshift, int treatAsMaster, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        ".Lf4c14c_0004c14c:\n"
        "pushl %ebp\n" /* line 822 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %edx, -0x38(%ebp)\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* org */
        "movl %eax, -0x44(%ebp)\n" /* org */
        "movl 0xc(%ebp), %edx\n" /* pChannel */
        "movl %edx, -0x48(%ebp)\n" /* pChannel */
        "movl 0x10(%ebp), %eax\n" /* timeshift */
        "movl %eax, -0x4c(%ebp)\n" /* timeshift */
        "movl 0x18(%ebp), %edx\n" /* system */
        "movl %edx, -0x54(%ebp)\n" /* system */
        "movzbl 0x14(%ebp), %eax\n" /* treatAsMaster */
        "movb %al, -0x4d(%ebp)\n" /* treatAsMaster */
        /* { scope 1: fPitchMin */
        "cmpb $0, g_snd\n" /* line 833 */
        "je .Lf4c14c_0004c32b\n"
        "movl -0x48(%ebp), %eax\n" /* line 836 | pChannel */
        "testl %eax, %eax\n"
        "je .Lf4c14c_0004c1a2\n"
        "movl -0x48(%ebp), %edx\n" /* line 837 | pChannel */
        "movl $0xffffffff, (%edx)\n"
        ".Lf4c14c_0004c1a2:\n"
        "movl -0x34(%ebp), %edx\n" /* line 844 */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf4c14c_0004c338\n"
        "movl %eax, (%esp)\n" /* line 846 */
        "calll Com_PickSoundAlias\n"
        "movl %eax, %ebx\n" /* secondaryAlias */
        "testl %eax, %eax\n" /* line 847 */
        "je .Lf4c14c_0004c1e9\n"
        "movl 8(%eax), %eax\n" /* line 849 */
        "testl %eax, %eax\n"
        "je .Lf4c14c_0004c717\n"
        "movl %eax, 0xc(%esp)\n" /* line 852 */
        "movl -0x34(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x218ae8, (%esp)\n" /* "^1Error: a secondaryAlias cannot have a secondary Alias of i" */
        "calll Com_Printf\n"
        ".Lf4c14c_0004c1e9:\n"
        "movl -0x34(%ebp), %eax\n"
        ".Lf4c14c_0004c1ec:\n"
        "movl 0x2c(%eax), %ecx\n" /* line 332 */
        "andl $0x780, %ecx\n"
        "sarl $7, %ecx\n"
        "cmpl $0xa, %ecx\n"
        "ja .Lf4c14c_0004c34f\n"
        ".Lf4c14c_0004c201:\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x786, %eax\n"
        "je .Lf4c14c_0004c63b\n"
        /* { scope 2 */
        "movl 0xffebc8, %eax\n" /* line 716 */
        "testl %eax, %eax\n"
        "jle .Lf4c14c_0004c3af\n"
        ".Lf4c14c_0004c220:\n"
        "xorl %esi, %esi\n" /* i */
        "movl $g_snd, %ebx\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss -0x3c(%ebp), %xmm1\n"
        "xorl %edi, %edi\n" /* i */
        "jmp .Lf4c14c_0004c24d\n"
        ".Lf4c14c_0004c238:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x50, %edi\n" /* i */
        "addl $0x50, %ebx\n"
        "cmpl 0xffebc8, %esi\n" /* i */
        "jge .Lf4c14c_0004c3af\n"
        ".Lf4c14c_0004c24d:\n"
        "movl -0x40(%ebp), %eax\n" /* line 718 */
        "cmpl 0x334(%ebx), %eax\n"
        "jne .Lf4c14c_0004c238\n"
        "movl %esi, (%esp)\n" /* line 720 | i */
        "movss %xmm1, -0x88(%ebp)\n"
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "movss -0x88(%ebp), %xmm1\n"
        "jne .Lf4c14c_0004c238\n"
        "movl 0x358(%ebx), %eax\n" /* line 724 */
        "testb $1, 0x2c(%eax)\n"
        "je .Lf4c14c_0004c238\n"
        "movl (%eax), %eax\n" /* line 726 */
        "movl -0x34(%ebp), %edx\n"
        "cmpl (%edx), %eax\n"
        "jne .Lf4c14c_0004c238\n"
        "movl 0x35c(%ebx), %eax\n" /* line 728 */
        "movl (%eax), %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "cmpl (%edx), %eax\n"
        "jne .Lf4c14c_0004c238\n"
        "movl -0x34(%ebp), %eax\n" /* line 731 */
        "mulss 0x14(%eax), %xmm1\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xffdb48(%edi)\n" /* i */
        "cvtsi2ssl 0xffdb4c(%edi), %xmm0\n" /* line 428 */
        "mulss 0xffdb50(%edi), %xmm0\n"
        "mulss 0xffd810, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x58(%ebp)\n"
        "cvttss2si -0x58(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SND_Set3DChannelPlaybackRate\n"
        "movl -0x44(%ebp), %edx\n" /* line 735 | org */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll SND_Set3DPosition\n"
        "movl 0xffdb30, %edx\n" /* line 736 */
        "movl $0xffdb30, %eax\n"
        "movl %edx, 0x10(%edi, %eax)\n" /* i */
        "movss -0x3c(%ebp), %xmm0\n" /* line 737 */
        "movss %xmm0, 0xffdb60(%edi)\n" /* i */
        "movl -0x48(%ebp), %eax\n" /* line 738 | pChannel */
        "testl %eax, %eax\n"
        "je .Lf4c14c_0004c32b\n"
        "movl -0x48(%ebp), %eax\n" /* line 739 | pChannel */
        "movl %esi, (%eax)\n" /* i */
        /* } scope */
        ".Lf4c14c_0004c32b:\n"
        "xorl %eax, %eax\n" /* line 879 */
        /* } scope */
        ".Lf4c14c_0004c32d:\n"
        "addl $0xcc, %esp\n" /* line 887 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4c14c_0004c338:\n"
        "movl %edx, %eax\n"
        /* { scope 1: fPitchMin */
        "movl 0x2c(%eax), %ecx\n" /* line 332 */
        "andl $0x780, %ecx\n"
        "sarl $7, %ecx\n"
        "cmpl $0xa, %ecx\n"
        "jbe .Lf4c14c_0004c201\n"
        ".Lf4c14c_0004c34f:\n"
        "movl %eax, %edx\n"
        /* { scope 2 */
        ".Lf4c14c_0004c351:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 858 | 1.0f, fDistMax */
        "subss -0x3c(%ebp), %xmm0\n" /* fDistMax */
        "mulss 0x28(%edx), %xmm0\n" /* fDistMax */
        "movss -0x3c(%ebp), %xmm1\n"
        "movl -0x38(%ebp), %eax\n"
        "mulss 0x28(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n" /* fDistMax */
        "movl $0xffdaf4, 4(%esp)\n" /* line 860 */
        "movl -0x44(%ebp), %edx\n" /* org */
        "movl %edx, (%esp)\n"
        "movss %xmm0, -0x78(%ebp)\n"
        "calll Vec3DistanceSq\n"
        "fstps -0x30(%ebp)\n"
        "movss -0x78(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "movss -0x30(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf4c14c_0004c32b\n"
        /* } scope */
        /* { scope 2 */
        "movl 0xffebc8, %eax\n" /* line 716 */
        "testl %eax, %eax\n"
        "jg .Lf4c14c_0004c220\n"
        ".Lf4c14c_0004c3af:\n"
        "movl 0xffebc4, %edx\n" /* line 743 */
        "leal 0x2d(%edx), %eax\n"
        "cmpl $0x2d, %eax\n"
        "jle .Lf4c14c_0004c445\n"
        "movl $0x2d, %edi\n" /* i */
        "movl $g_snd, %ebx\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss -0x3c(%ebp), %xmm1\n"
        "movl $0xe10, %esi\n" /* i */
        "jmp .Lf4c14c_0004c3ef\n"
        ".Lf4c14c_0004c3df:\n"
        "addl $1, %edi\n" /* i */
        "addl $0x50, %esi\n" /* i */
        "addl $0x50, %ebx\n"
        "leal 0x2d(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* i */
        "jge .Lf4c14c_0004c445\n"
        ".Lf4c14c_0004c3ef:\n"
        "movl -0x40(%ebp), %eax\n" /* line 745 */
        "cmpl 0x1144(%ebx), %eax\n"
        "jne .Lf4c14c_0004c3df\n"
        "movl %edi, (%esp)\n" /* line 747 | i */
        "movss %xmm1, -0x88(%ebp)\n"
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "movss -0x88(%ebp), %xmm1\n"
        "jne .Lf4c14c_0004c42f\n"
        "movl 0x1168(%ebx), %eax\n" /* line 751 */
        "testb $1, 0x2c(%eax)\n"
        "je .Lf4c14c_0004c42f\n"
        "movl (%eax), %eax\n" /* line 753 */
        "movl -0x34(%ebp), %edx\n"
        "cmpl (%edx), %eax\n"
        "je .Lf4c14c_0004c7b6\n"
        ".Lf4c14c_0004c42f:\n"
        "movl 0xffebc4, %edx\n"
        "addl $1, %edi\n" /* line 743 | i */
        "addl $0x50, %esi\n" /* i */
        "addl $0x50, %ebx\n"
        "leal 0x2d(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* i */
        "jl .Lf4c14c_0004c3ef\n"
        ".Lf4c14c_0004c445:\n"
        "movl 0xffebcc, %edx\n" /* line 769 */
        "leal 0x20(%edx), %eax\n"
        "cmpl $0x20, %eax\n"
        "jle .Lf4c14c_0004c4db\n"
        "movl $0x20, %edi\n" /* i */
        "movl $g_snd, %ebx\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss -0x3c(%ebp), %xmm1\n"
        "movl $0xa00, %esi\n" /* i */
        "jmp .Lf4c14c_0004c485\n"
        ".Lf4c14c_0004c475:\n"
        "addl $1, %edi\n" /* i */
        "addl $0x50, %esi\n" /* i */
        "addl $0x50, %ebx\n"
        "leal 0x20(%edx), %eax\n"
        "cmpl %edi, %eax\n" /* i */
        "jle .Lf4c14c_0004c4db\n"
        ".Lf4c14c_0004c485:\n"
        "movl -0x40(%ebp), %eax\n" /* line 771 */
        "cmpl 0xd34(%ebx), %eax\n"
        "jne .Lf4c14c_0004c475\n"
        "movl %edi, (%esp)\n" /* line 773 | i */
        "movss %xmm1, -0x88(%ebp)\n"
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "movss -0x88(%ebp), %xmm1\n"
        "jne .Lf4c14c_0004c4c5\n"
        "movl 0xd58(%ebx), %eax\n" /* line 777 */
        "testb $1, 0x2c(%eax)\n"
        "je .Lf4c14c_0004c4c5\n"
        "movl (%eax), %eax\n" /* line 779 */
        "movl -0x34(%ebp), %edx\n"
        "cmpl (%edx), %eax\n"
        "je .Lf4c14c_0004c856\n"
        ".Lf4c14c_0004c4c5:\n"
        "movl 0xffebcc, %edx\n"
        "addl $1, %edi\n" /* line 769 | i */
        "addl $0x50, %esi\n" /* i */
        "addl $0x50, %ebx\n"
        "leal 0x20(%edx), %eax\n"
        "cmpl %edi, %eax\n" /* i */
        "jg .Lf4c14c_0004c485\n"
        /* } scope */
        ".Lf4c14c_0004c4db:\n"
        "movl -0x34(%ebp), %edx\n" /* line 867 */
        "movl 0x2c(%edx), %edi\n" /* i */
        "andl $0x780, %edi\n" /* i */
        "sarl $7, %edi\n" /* i */
        "cmpl $2, %edi\n" /* i */
        "jbe .Lf4c14c_0004c4fd\n"
        "movl 8(%edx), %ebx\n" /* secondaryAlias */
        "testl %ebx, %ebx\n" /* secondaryAlias */
        "je .Lf4c14c_0004c754\n"
        ".Lf4c14c_0004c4fa:\n"
        "movl -0x34(%ebp), %edx\n"
        /* { scope 2 */
        ".Lf4c14c_0004c4fd:\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 812 | 1.0f */
        "subss -0x3c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "mulss 0x14(%edx), %xmm2\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movl -0x38(%ebp), %eax\n"
        "mulss 0x14(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm1, %xmm0\n" /* line 814 */
        "mulss 0x1c(%edx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* fPitchMin */
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 0x1c(%eax), %xmm0\n"
        "addss -0x1c(%ebp), %xmm0\n" /* fPitchMin */
        "movss %xmm0, -0x1c(%ebp)\n" /* fPitchMin */
        "movaps %xmm1, %xmm0\n" /* line 815 */
        "mulss 0x20(%edx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* pitch */
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 0x20(%eax), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n" /* pitch */
        "movss %xmm0, -0x28(%ebp)\n" /* pitch */
        "mulss 0x18(%edx), %xmm1\n" /* line 817 */
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 0x18(%eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* volume */
        "movss %xmm2, -0x98(%ebp)\n"
        "calll randomf\n"
        "fstps -0x24(%ebp)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* volume */
        "mulss -0x24(%ebp), %xmm1\n"
        "movss -0x98(%ebp), %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x2c(%ebp)\n" /* volume */
        "calll randomf\n" /* line 818 */
        "fstps -0x20(%ebp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* pitch */
        "subss -0x1c(%ebp), %xmm0\n" /* fPitchMin */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* fPitchMin */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* pitch */
        /* } scope */
        "movl -0x34(%ebp), %eax\n" /* line 872 */
        "movl 0x2c(%eax), %ebx\n" /* secondaryAlias */
        "andl $0x60, %ebx\n" /* secondaryAlias */
        "sarl $5, %ebx\n" /* secondaryAlias */
        "cmpl $1, %ebx\n" /* secondaryAlias */
        "je .Lf4c14c_0004c643\n"
        "jl .Lf4c14c_0004c32b\n"
        "cmpl $3, %ebx\n" /* secondaryAlias */
        "jg .Lf4c14c_0004c32b\n"
        "movl -0x54(%ebp), %edx\n" /* line 879 | system */
        "movl %edx, 0x18(%ebp)\n" /* system */
        "movl -0x48(%ebp), %eax\n" /* pChannel */
        "movl %eax, 0x14(%ebp)\n" /* treatAsMaster */
        "movzbl -0x4d(%ebp), %eax\n" /* treatAsMaster */
        "movl %eax, 0x10(%ebp)\n" /* timeshift */
        "movl -0x4c(%ebp), %edx\n" /* timeshift */
        "movl %edx, 0xc(%ebp)\n" /* pChannel */
        "movl -0x44(%ebp), %eax\n" /* org */
        "movl %eax, 8(%ebp)\n" /* org */
        "pxor %xmm3, %xmm3\n"
        "movss -0x28(%ebp), %xmm2\n" /* pitch */
        "movss -0x2c(%ebp), %xmm1\n" /* volume */
        "movl -0x40(%ebp), %ecx\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movl -0x38(%ebp), %edx\n"
        "movl -0x34(%ebp), %eax\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 887 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: fPitchMin */
        "jmp SND_StartAliasStream\n" /* line 879 */
        ".Lf4c14c_0004c63b:\n"
        "movl -0x34(%ebp), %edx\n"
        "jmp .Lf4c14c_0004c351\n"
        ".Lf4c14c_0004c643:\n"
        "movzbl -0x4d(%ebp), %esi\n" /* line 872 | treatAsMaster, i */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 529 */
        "calll Com_GetSoundFileMem\n"
        "testl %eax, %eax\n"
        "je .Lf4c14c_0004c9db\n"
        "movl -0x34(%ebp), %eax\n" /* line 537 */
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, %ecx\n" /* line 332 */
        "andl $0x780, %ecx\n"
        "sarl $7, %ecx\n"
        "cmpl $0xa, %ecx\n"
        "ja .Lf4c14c_0004c67b\n"
        "shll %cl, %ebx\n"
        "andl $0x786, %ebx\n"
        "jne .Lf4c14c_0004ca2e\n"
        ".Lf4c14c_0004c67b:\n"
        "movl snd_enable3D, %eax\n" /* line 539 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf4c14c_0004c32b\n"
        "cmpb $0, 0xffdb28\n" /* line 543 */
        "je .Lf4c14c_0004c9b7\n"
        "movl %esi, %eax\n" /* line 550 | i */
        "testb %al, %al\n"
        "je .Lf4c14c_0004c7a6\n"
        ".Lf4c14c_0004c6a1:\n"
        "movl $1, %eax\n"
        ".Lf4c14c_0004c6a6:\n"
        "movl -0x54(%ebp), %edx\n" /* system */
        "movl %edx, 0x30(%esp)\n"
        "movl -0x48(%ebp), %edx\n" /* pChannel */
        "movl %edx, 0x2c(%esp)\n"
        "movl %eax, 0x28(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* timeshift */
        "movl %eax, 0x1c(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* pitch */
        "movss %xmm0, 0x18(%esp)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* volume */
        "movss %xmm1, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n" /* org */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SND_StartAlias3DSample\n"
        "jmp .Lf4c14c_0004c32d\n"
        /* } scope */
        ".Lf4c14c_0004c717:\n"
        "movl -0x54(%ebp), %eax\n" /* line 850 | system */
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x4d(%ebp), %eax\n" /* treatAsMaster */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x4c(%ebp), %edx\n" /* timeshift */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x44(%ebp), %eax\n" /* org */
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movl %ebx, %edx\n" /* secondaryAlias */
        "movl %ebx, %eax\n" /* secondaryAlias */
        "calll SND_PlaySoundAlias_Internal\n"
        "movl -0x34(%ebp), %eax\n"
        "jmp .Lf4c14c_0004c1ec\n"
        /* { scope 2 */
        ".Lf4c14c_0004c754:\n"
        "movl 0xffebc8, %edx\n" /* line 493 */
        "testl %edx, %edx\n"
        "jle .Lf4c14c_0004c90f\n"
        "xorl %esi, %esi\n" /* i */
        "movl $g_snd, %ebx\n"
        "jmp .Lf4c14c_0004c77d\n"
        ".Lf4c14c_0004c76b:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x50, %ebx\n"
        "cmpl %esi, 0xffebc8\n" /* i */
        "jle .Lf4c14c_0004c90f\n"
        ".Lf4c14c_0004c77d:\n"
        "movl -0x40(%ebp), %eax\n" /* line 495 */
        "cmpl 0x334(%ebx), %eax\n"
        "jne .Lf4c14c_0004c76b\n"
        "cmpl 0x338(%ebx), %edi\n"
        "jne .Lf4c14c_0004c76b\n"
        "movl %esi, (%esp)\n" /* line 497 | i */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4c14c_0004c76b\n"
        "movl %esi, (%esp)\n" /* line 499 | i */
        "calll SND_Stop3DChannel\n"
        "jmp .Lf4c14c_0004c76b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4c14c_0004c7a6:\n"
        "andb $2, %dl\n" /* line 550 */
        "jne .Lf4c14c_0004c6a1\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4c14c_0004c6a6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4c14c_0004c7b6:\n"
        "movl 0x116c(%ebx), %eax\n" /* line 755 */
        "movl (%eax), %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "cmpl (%edx), %eax\n"
        "jne .Lf4c14c_0004c42f\n"
        "movl -0x34(%ebp), %eax\n" /* line 758 */
        "mulss 0x14(%eax), %xmm1\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xffdb48(%esi)\n" /* i */
        "cvtsi2ssl 0xffdb4c(%esi), %xmm0\n" /* line 428 */
        "mulss 0xffdb50(%esi), %xmm0\n"
        "mulss 0xffd810, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x5c(%ebp)\n"
        "cvttss2si -0x5c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll SND_Set2DChannelPlaybackRate\n"
        "movl 0xffdb30, %edx\n" /* line 762 */
        "movl $0xffdb30, %eax\n"
        "movl %edx, 0x10(%esi, %eax)\n" /* i */
        "movss -0x3c(%ebp), %xmm0\n" /* line 763 */
        "movss %xmm0, 0xffdb60(%esi)\n" /* i */
        "movl -0x48(%ebp), %eax\n" /* line 764 | pChannel */
        "testl %eax, %eax\n"
        "je .Lf4c14c_0004c32b\n"
        "movl -0x48(%ebp), %eax\n" /* line 792 | pChannel */
        "movl %edi, (%eax)\n" /* i */
        "jmp .Lf4c14c_0004c32b\n"
        ".Lf4c14c_0004c856:\n"
        "movl 0xd5c(%ebx), %eax\n" /* line 781 */
        "movl (%eax), %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "cmpl (%edx), %eax\n"
        "jne .Lf4c14c_0004c4c5\n"
        "movl -0x34(%ebp), %eax\n" /* line 784 */
        "mulss 0x14(%eax), %xmm1\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xffdb48(%esi)\n" /* i */
        "cvtsi2ssl 0xffdb4c(%esi), %xmm0\n" /* line 428 */
        "mulss 0xffdb50(%esi), %xmm0\n"
        "mulss 0xffd810, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x60(%ebp)\n"
        "cvttss2si -0x60(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll SND_SetStreamChannelPlaybackRate\n"
        "movl -0x44(%ebp), %edx\n" /* line 199 | org */
        "movl (%edx), %eax\n"
        "movl %eax, 0xffdb64(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 0xffdb68(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0xffdb6c(%esi)\n"
        "movl 0xffdb30, %eax\n" /* line 789 */
        "movl %eax, 0xffdb40(%esi)\n" /* i */
        "movss -0x3c(%ebp), %xmm0\n" /* line 790 */
        "movss %xmm0, 0xffdb60(%esi)\n" /* i */
        "movl -0x48(%ebp), %esi\n" /* line 791 | pChannel, i */
        "testl %esi, %esi\n" /* i */
        "je .Lf4c14c_0004c32b\n"
        "movl -0x48(%ebp), %eax\n" /* line 792 | pChannel */
        "movl %edi, (%eax)\n" /* i */
        "jmp .Lf4c14c_0004c32b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4c14c_0004c90f:\n"
        "movl 0xffebcc, %edx\n" /* line 502 */
        "leal 0x20(%edx), %eax\n"
        "cmpl $0x20, %eax\n"
        "jle .Lf4c14c_0004c961\n"
        "movl $0x20, %esi\n" /* i */
        "movl $g_snd, %ebx\n"
        "jmp .Lf4c14c_0004c936\n"
        ".Lf4c14c_0004c929:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x50, %ebx\n"
        "leal 0x20(%edx), %eax\n"
        "cmpl %esi, %eax\n" /* i */
        "jle .Lf4c14c_0004c961\n"
        ".Lf4c14c_0004c936:\n"
        "movl -0x40(%ebp), %eax\n" /* line 504 */
        "cmpl 0xd34(%ebx), %eax\n"
        "jne .Lf4c14c_0004c929\n"
        "cmpl 0xd38(%ebx), %edi\n"
        "jne .Lf4c14c_0004c929\n"
        "movl %esi, (%esp)\n" /* line 506 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4c14c_0004ca17\n"
        ".Lf4c14c_0004c959:\n"
        "movl 0xffebcc, %edx\n"
        "jmp .Lf4c14c_0004c929\n"
        ".Lf4c14c_0004c961:\n"
        "movl 0xffebc4, %edx\n" /* line 511 */
        "leal 0x2d(%edx), %eax\n"
        "cmpl $0x2d, %eax\n"
        "jle .Lf4c14c_0004c4fa\n"
        "movl $0x2d, %esi\n" /* i */
        "movl $g_snd, %ebx\n"
        "jmp .Lf4c14c_0004c990\n"
        ".Lf4c14c_0004c97f:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x50, %ebx\n"
        "leal 0x2d(%edx), %eax\n"
        "cmpl %esi, %eax\n" /* i */
        "jle .Lf4c14c_0004c4fa\n"
        ".Lf4c14c_0004c990:\n"
        "movl -0x40(%ebp), %eax\n" /* line 513 */
        "cmpl 0x1144(%ebx), %eax\n"
        "jne .Lf4c14c_0004c97f\n"
        "cmpl 0x1148(%ebx), %edi\n"
        "jne .Lf4c14c_0004c97f\n"
        "movl %esi, (%esp)\n" /* line 515 | i */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4c14c_0004ca24\n"
        ".Lf4c14c_0004c9af:\n"
        "movl 0xffebc4, %edx\n"
        "jmp .Lf4c14c_0004c97f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4c14c_0004c9b7:\n"
        "movl -0x34(%ebp), %edx\n" /* line 545 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2188e8, 4(%esp)\n" /* "attempted to play spatialized alias '%s' while there is no a" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4c14c_0004c32d\n"
        ".Lf4c14c_0004c9db:\n"
        "movl -0x34(%ebp), %eax\n" /* line 531 */
        "movl (%eax), %ebx\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileName\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x218b50, (%esp)\n" /* "Tried to play sound '%s' from alias '%s', but it was not suc" */
        "calll Com_DPrintf\n"
        "movl -0x48(%ebp), %ecx\n" /* line 532 | pChannel */
        "testl %ecx, %ecx\n"
        "je .Lf4c14c_0004c32b\n"
        "movl -0x48(%ebp), %edx\n" /* line 533 | pChannel */
        "movl $0xffffffff, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf4c14c_0004c32d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4c14c_0004ca17:\n"
        "movl %esi, (%esp)\n" /* line 508 | i */
        "calll SND_StopStreamChannel\n"
        "jmp .Lf4c14c_0004c959\n"
        ".Lf4c14c_0004ca24:\n"
        "movl %esi, (%esp)\n" /* line 517 | i */
        "calll SND_Stop2DChannel\n"
        "jmp .Lf4c14c_0004c9af\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4c14c_0004ca2e:\n"
        "movl snd_enable2D, %eax\n" /* line 555 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf4c14c_0004c32b\n"
        "movl %esi, %eax\n" /* line 558 | i */
        "testb %al, %al\n"
        "jne .Lf4c14c_0004cab1\n"
        "andb $2, %dl\n"
        "jne .Lf4c14c_0004cab1\n"
        "xorl %eax, %eax\n"
        ".Lf4c14c_0004ca4a:\n"
        "movl -0x54(%ebp), %edx\n" /* system */
        "movl %edx, 0x2c(%esp)\n"
        "movl -0x48(%ebp), %edx\n" /* pChannel */
        "movl %edx, 0x28(%esp)\n"
        "movl %eax, 0x24(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* timeshift */
        "movl %eax, 0x18(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* pitch */
        "movss %xmm0, 0x14(%esp)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* volume */
        "movss %xmm1, 0x10(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SND_StartAlias2DSample\n"
        "jmp .Lf4c14c_0004c32d\n"
        ".Lf4c14c_0004cab1:\n"
        "movl $1, %eax\n"
        "jmp .Lf4c14c_0004ca4a\n"
    );
}

/* line 1069 */
__attribute__((naked))
int SND_PlayLocalSoundAliasByName(const char *aliasname, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1069 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* aliasname */
        "testl %eax, %eax\n" /* line 1073 */
        "je .Lf4cab8_0004cb0a\n"
        "movl %eax, (%esp)\n" /* line 1075 */
        "calll Com_PickSoundAlias\n"
        "testl %eax, %eax\n" /* line 1077 */
        "je .Lf4cab8_0004cb0a\n"
        "movl 0xc(%ebp), %edx\n" /* line 1078 | system */
        "movl %edx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffdaf4, (%esp)\n"
        "movl 0xffdb24, %ecx\n"
        "pxor %xmm0, %xmm0\n"
        "movl %eax, %edx\n"
        "calll SND_PlaySoundAlias_Internal\n"
        "leave\n" /* line 1081 */
        "retl\n"
        ".Lf4cab8_0004cb0a:\n"
        "xorl %eax, %eax\n" /* line 1078 */
        "leave\n" /* line 1081 */
        "retl\n"
    );
}

/* line 1054 */
__attribute__((naked))
int SND_PlayLocalSoundAlias(snd_alias_list_t *aliasList, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1054 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* aliasList */
        "testl %eax, %eax\n" /* line 1058 */
        "je .Lf4cb0e_0004cb60\n"
        "movl %eax, (%esp)\n" /* line 1060 */
        "calll Com_PickSoundAliasFromList\n"
        "testl %eax, %eax\n" /* line 1062 */
        "je .Lf4cb0e_0004cb60\n"
        "movl 0xc(%ebp), %edx\n" /* line 1063 | system */
        "movl %edx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffdaf4, (%esp)\n"
        "movl 0xffdb24, %ecx\n"
        "pxor %xmm0, %xmm0\n"
        "movl %eax, %edx\n"
        "calll SND_PlaySoundAlias_Internal\n"
        "leave\n" /* line 1066 */
        "retl\n"
        ".Lf4cb0e_0004cb60:\n"
        "xorl %eax, %eax\n" /* line 1063 */
        "leave\n" /* line 1066 */
        "retl\n"
    );
}

/* line 1043 */
__attribute__((naked))
int SND_PlayBlendedSoundAliases(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float fLerp, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1043 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pAlias0 */
        "movl 0xc(%ebp), %ebx\n" /* pAlias1 */
        "movss 0x10(%ebp), %xmm0\n" /* fLerp */
        "movss %xmm0, -0x1c(%ebp)\n" /* fLerp */
        "movl 0x14(%ebp), %eax\n" /* entnum */
        "movl %eax, -0x20(%ebp)\n" /* entnum */
        "movl 0x18(%ebp), %eax\n" /* org */
        "movl %eax, -0x24(%ebp)\n" /* org */
        "movl 0x1c(%ebp), %eax\n" /* timeshift */
        "movl %eax, -0x28(%ebp)\n" /* timeshift */
        "movl 0x20(%ebp), %edi\n" /* system */
        "testl %esi, %esi\n" /* line 1047 | pAlias0 */
        "je .Lf4cb64_0004cbdd\n"
        "testl %ebx, %ebx\n" /* pAlias1 */
        "je .Lf4cb64_0004cbdd\n"
        "movl $1, %ecx\n" /* line 1049 */
        "movl %ebx, %edx\n" /* pAlias1 */
        "movl %esi, %eax\n" /* pAlias0 */
        "calll SND_ValidateSoundAliasBlend\n"
        "movl %edi, 0x18(%ebp)\n" /* line 1050 | system, org */
        "movl $0, 0x14(%ebp)\n" /* entnum */
        "movl -0x28(%ebp), %eax\n" /* timeshift */
        "movl %eax, 0x10(%ebp)\n" /* fLerp */
        "movl $0, 0xc(%ebp)\n" /* pAlias1 */
        "movl -0x24(%ebp), %eax\n" /* org */
        "movl %eax, 8(%ebp)\n" /* pAlias0 */
        "movl -0x20(%ebp), %ecx\n" /* entnum */
        "movss -0x1c(%ebp), %xmm0\n" /* fLerp */
        "movl %ebx, %edx\n" /* pAlias1 */
        "movl %esi, %eax\n" /* pAlias0 */
        "addl $0x1c, %esp\n" /* line 1051 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp SND_PlaySoundAlias_Internal\n" /* line 1050 */
        ".Lf4cb64_0004cbdd:\n"
        "xorl %eax, %eax\n" /* line 1051 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 914 */
__attribute__((naked))
int SND_PlaySoundAliasAsMaster(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 914 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* pAlias */
        "movl 0xc(%ebp), %esi\n" /* entnum */
        "movl 0x10(%ebp), %ebx\n" /* org */
        "movl 0x14(%ebp), %ecx\n" /* timeshift */
        "testl %eax, %eax\n" /* line 918 */
        "je .Lf4cbe8_0004cc21\n"
        "movl $1, 0x14(%ebp)\n" /* line 920 | timeshift */
        "movl %ecx, 0x10(%ebp)\n" /* org */
        "movl $0, 0xc(%ebp)\n" /* entnum */
        "movl %ebx, 8(%ebp)\n" /* org, pAlias */
        "movl %esi, %ecx\n" /* entnum */
        "pxor %xmm0, %xmm0\n"
        "movl %eax, %edx\n"
        "popl %ebx\n" /* line 921 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmp SND_PlaySoundAlias_Internal\n" /* line 920 */
        ".Lf4cbe8_0004cc21:\n"
        "xorl %eax, %eax\n" /* line 921 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 897 */
__attribute__((naked))
int SND_PlaySoundAlias(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 897 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* pAlias */
        "movl 0xc(%ebp), %esi\n" /* entnum */
        "movl 0x10(%ebp), %ebx\n" /* org */
        "movl 0x14(%ebp), %ecx\n" /* timeshift */
        "testl %eax, %eax\n" /* line 901 */
        "je .Lf4cc28_0004cc61\n"
        "movl $0, 0x14(%ebp)\n" /* line 903 | timeshift */
        "movl %ecx, 0x10(%ebp)\n" /* org */
        "movl $0, 0xc(%ebp)\n" /* entnum */
        "movl %ebx, 8(%ebp)\n" /* org, pAlias */
        "movl %esi, %ecx\n" /* entnum */
        "pxor %xmm0, %xmm0\n"
        "movl %eax, %edx\n"
        "popl %ebx\n" /* line 904 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmp SND_PlaySoundAlias_Internal\n" /* line 903 */
        ".Lf4cc28_0004cc61:\n"
        "xorl %eax, %eax\n" /* line 904 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 441 */
__attribute__((naked))
int SND_FindFree2DChannel(int entnum, int entchannel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 441 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0xffebc4, %eax\n" /* line 445 */
        "testl %eax, %eax\n"
        "jg .Lf4cc68_0004cd28\n"
        /* { scope 2 */
        ".Lf4cc68_0004cc7e:\n"
        "addl $0x2d, %eax\n" /* line 429 */
        "movl %eax, -0x20(%ebp)\n"
        "cmpl $0x2d, %eax\n"
        "jle .Lf4cc68_0004ccfe\n"
        "movl $0x2d, -0x1c(%ebp)\n"
        "movl $0xffffffff, %ebx\n"
        "movl $g_snd, %edi\n"
        ".Lf4cc68_0004cc9a:\n"
        "movl 0x1148(%edi), %eax\n" /* line 415 */
        "cmpl %eax, 0xc(%ebp)\n" /* line 431 | entchannel */
        "jl .Lf4cc68_0004ccd9\n"
        "testl %ebx, %ebx\n" /* line 433 */
        "js .Lf4cc68_0004cd0d\n"
        "movl 0x1144(%edi), %esi\n" /* line 393 */
        "leal (%ebx, %ebx, 4), %edx\n"
        "shll $4, %edx\n"
        "movl 0xffdb34(%edx), %ecx\n"
        "cmpl %ecx, %esi\n"
        "je .Lf4cc68_0004ccc9\n"
        "cmpl %esi, 8(%ebp)\n" /* line 395 | entnum */
        "je .Lf4cc68_0004cd0d\n"
        "cmpl %ecx, 8(%ebp)\n" /* line 397 | entnum */
        "je .Lf4cc68_0004ccd9\n"
        ".Lf4cc68_0004ccc9:\n"
        "movl 0xffdb38(%edx), %ecx\n" /* line 402 */
        "cmpl %ecx, %eax\n"
        "je .Lf4cc68_0004cd12\n"
        "subl %ecx, %eax\n" /* line 403 */
        ".Lf4cc68_0004ccd5:\n"
        "testl %eax, %eax\n" /* line 433 */
        "js .Lf4cc68_0004cd0d\n"
        ".Lf4cc68_0004ccd9:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 429 */
        "addl $0x50, %edi\n"
        "movl -0x20(%ebp), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n"
        "jne .Lf4cc68_0004cc9a\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 452 */
        "js .Lf4cc68_0004cd03\n"
        "movl %ebx, (%esp)\n" /* line 453 */
        "calll SND_Stop2DChannel\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 455 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf4cc68_0004ccfe:\n"
        "movl $0xffffffff, %ebx\n" /* line 429 */
        /* } scope */
        /* } scope */
        ".Lf4cc68_0004cd03:\n"
        "movl %ebx, %eax\n" /* line 455 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf4cc68_0004cd0d:\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 433 */
        "jmp .Lf4cc68_0004ccd9\n"
        ".Lf4cc68_0004cd12:\n"
        "movl 0x1154(%edi), %ecx\n" /* line 406 */
        "movl 0xffdb44(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf4cc68_0004ccd9\n"
        "subl %eax, %ecx\n" /* line 407 */
        "movl %ecx, %eax\n"
        "jmp .Lf4cc68_0004ccd5\n"
        /* } scope */
        ".Lf4cc68_0004cd28:\n"
        "xorl %esi, %esi\n" /* line 445 | i */
        ".Lf4cc68_0004cd2a:\n"
        "leal 0x2d(%esi), %ebx\n" /* i */
        "movl %ebx, (%esp)\n" /* line 447 */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4cc68_0004cd03\n"
        "addl $1, %esi\n" /* line 445 | i */
        "movl 0xffebc4, %eax\n"
        "cmpl %esi, %eax\n" /* i */
        "jg .Lf4cc68_0004cd2a\n"
        "jmp .Lf4cc68_0004cc7e\n"
    );
}

/* line 458 */
__attribute__((naked))
int SND_FindFree3DChannel(int entnum, int entchannel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 458 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0xffebc8, %eax\n" /* line 462 */
        "testl %eax, %eax\n"
        "jg .Lf4cd4a_0004cd6b\n"
        ".Lf4cd4a_0004cd5c:\n"
        "movl $0xffffffff, %ebx\n" /* line 470 */
        /* } scope */
        ".Lf4cd4a_0004cd61:\n"
        "movl %ebx, %eax\n" /* line 472 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4cd4a_0004cd6b:\n"
        "xorl %ebx, %ebx\n" /* line 462 */
        ".Lf4cd4a_0004cd6d:\n"
        "movl %ebx, (%esp)\n" /* line 464 */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4cd4a_0004cd61\n"
        "addl $1, %ebx\n" /* line 462 */
        "movl 0xffebc8, %esi\n"
        "cmpl %ebx, %esi\n"
        "jg .Lf4cd4a_0004cd6d\n"
        "testl %esi, %esi\n" /* line 429 */
        "jle .Lf4cd4a_0004cd5c\n"
        "movl $0, -0x20(%ebp)\n" /* i */
        "movl $0xffffffff, %ebx\n"
        "movl $g_snd, -0x1c(%ebp)\n"
        ".Lf4cd4a_0004cd9d:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 415 */
        "movl 0x338(%edx), %eax\n"
        "cmpl %eax, 0xc(%ebp)\n" /* line 431 | entchannel */
        "jl .Lf4cd4a_0004cddf\n"
        "testl %ebx, %ebx\n" /* line 433 */
        "js .Lf4cd4a_0004ce06\n"
        "movl 0x334(%edx), %edi\n" /* line 393 */
        "leal (%ebx, %ebx, 4), %edx\n"
        "shll $4, %edx\n"
        "movl 0xffdb34(%edx), %ecx\n"
        "cmpl %ecx, %edi\n"
        "je .Lf4cd4a_0004cdcf\n"
        "cmpl %edi, 8(%ebp)\n" /* line 395 | entnum */
        "je .Lf4cd4a_0004ce06\n"
        "cmpl %ecx, 8(%ebp)\n" /* line 397 | entnum */
        "je .Lf4cd4a_0004cddf\n"
        ".Lf4cd4a_0004cdcf:\n"
        "movl 0xffdb38(%edx), %ecx\n" /* line 402 */
        "cmpl %ecx, %eax\n"
        "je .Lf4cd4a_0004ce0b\n"
        "subl %ecx, %eax\n" /* line 403 */
        ".Lf4cd4a_0004cddb:\n"
        "testl %eax, %eax\n" /* line 433 */
        "js .Lf4cd4a_0004ce06\n"
        ".Lf4cd4a_0004cddf:\n"
        "addl $1, -0x20(%ebp)\n" /* line 429 | i */
        "addl $0x50, -0x1c(%ebp)\n"
        "cmpl %esi, -0x20(%ebp)\n" /* i */
        "jne .Lf4cd4a_0004cd9d\n"
        "testl %ebx, %ebx\n" /* line 469 */
        "js .Lf4cd4a_0004cd61\n"
        "movl %ebx, (%esp)\n" /* line 470 */
        "calll SND_Stop3DChannel\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 472 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4cd4a_0004ce06:\n"
        "movl -0x20(%ebp), %ebx\n" /* line 433 | i */
        "jmp .Lf4cd4a_0004cddf\n"
        ".Lf4cd4a_0004ce0b:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 406 */
        "movl 0x344(%eax), %ecx\n"
        "movl 0xffdb44(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf4cd4a_0004cddf\n"
        "subl %eax, %ecx\n" /* line 407 */
        "movl %ecx, %eax\n"
        "jmp .Lf4cd4a_0004cddb\n"
    );
}

/* line 2098 */
static __attribute__((naked))
jpeg_component_info SND_RestoreChanInfo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2098 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %ebx\n" /* chaninfo */
        "movl %edx, %edi\n" /* memFile */
        "movl $0x50, 8(%esp)\n" /* line 2100 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* { scope 1: value */
        "leal -0x1c(%ebp), %eax\n" /* line 131 | value */
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movswl -0x1c(%ebp), %eax\n" /* line 2101 | value */
        "movl %eax, (%ebx)\n" /* chaninfo */
        /* { scope 1: value */
        "leal -0x1c(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1c(%ebp), %eax\n" /* line 2102 | value */
        "movl %eax, 4(%ebx)\n" /* chaninfo */
        /* { scope 1: value */
        "leal -0x1c(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "cmpb $0, -0x1c(%ebp)\n" /* line 2103 | value */
        "setne 0x49(%ebx)\n" /* chaninfo */
        /* { scope 1: value */
        "leal -0x1c(%ebp), %eax\n" /* line 140 | value */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 2104 | value */
        "movl %eax, 8(%ebx)\n" /* chaninfo */
        /* { scope 1: value */
        "leal -0x1c(%ebp), %eax\n" /* line 149 | value */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 2105 | value */
        "movl %eax, 0x14(%ebx)\n" /* chaninfo */
        /* { scope 1: value */
        "leal -0x1c(%ebp), %eax\n" /* line 149 | value */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 2106 | value */
        "movl %eax, 0x2c(%ebx)\n" /* chaninfo */
        "leal 0x3c(%ebx), %esi\n" /* line 2107 | chaninfo, value */
        /* { scope 1: value */
        /* { scope 2 */
        "leal -0x1c(%ebp), %eax\n" /* line 149 | value */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 157 | value */
        "movl %eax, 0x3c(%ebx)\n"
        /* { scope 2 */
        "leal -0x1c(%ebp), %eax\n" /* line 149 | value */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 158 | value */
        "movl %eax, 4(%esi)\n"
        /* { scope 2 */
        "leal -0x1c(%ebp), %eax\n" /* line 149 | value */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 159 | value */
        "movl %eax, 8(%esi)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2108 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1189 */
static __attribute__((naked))
jpeg_component_info SND_StartBackground(int fadetime, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %edi\n" /* track */
        "movl %edx, %esi\n" /* pAlias */
        "movl %ecx, -0x34(%ebp)\n"
        /* { scope 1 */
        "movl 0x195ed18, %eax\n" /* line 1177 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "cmpb 0xffd802, %al\n" /* line 1178 */
        "je .Lf4cf5c_0004cf90\n"
        "testb %al, %al\n" /* line 1180 */
        "jne .Lf4cf5c_0004d176\n"
        "calll SND_UnpauseSounds\n" /* line 1183 */
        ".Lf4cf5c_0004cf90:\n"
        "movl 0x2c(%esi), %edx\n" /* line 332 */
        "movl %edx, %ecx\n"
        "andl $0x780, %ecx\n"
        "sarl $7, %ecx\n"
        "cmpl $0xa, %ecx\n"
        "ja .Lf4cf5c_0004d148\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x786, %eax\n"
        "je .Lf4cf5c_0004d148\n"
        ".Lf4cf5c_0004cfb9:\n"
        "andl $0x60, %edx\n" /* line 1206 */
        "sarl $5, %edx\n"
        "leal -2(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf4cf5c_0004cfed\n"
        "movl %esi, (%esp)\n" /* line 1208 | pAlias */
        "calll Com_GetSoundFileName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%esi), %eax\n" /* pAlias */
        "movl %eax, 8(%esp)\n"
        "movl $0x218c14, 4(%esp)\n" /* "alias %s sound %s played as an ambient / music track is not" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf4cf5c_0004cfed:\n"
        "movss 0x14(%esi), %xmm0\n" /* line 1211 | pAlias */
        "movss %xmm0, -0x30(%ebp)\n"
        "movss 0x18(%esi), %xmm0\n" /* pAlias */
        "subss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* volume */
        "calll randomf\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x20(%ebp), %xmm0\n" /* volume */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* volume */
        "movss -0x30(%ebp), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n" /* volume */
        "movss %xmm0, -0x20(%ebp)\n" /* volume */
        "movss 0x1c(%esi), %xmm0\n" /* line 1212 | pAlias */
        "movss %xmm0, -0x28(%ebp)\n"
        "movss 0x20(%esi), %xmm0\n" /* pAlias */
        "subss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* pitch */
        "calll randomf\n"
        "fstps -0x24(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* pitch */
        "mulss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* pitch */
        "movss -0x28(%ebp), %xmm0\n"
        "addss -0x1c(%ebp), %xmm0\n" /* pitch */
        "movss %xmm0, -0x1c(%ebp)\n" /* pitch */
        "leal 0x20(%edi), %ebx\n" /* line 1213 | track, channel */
        "movl %ebx, (%esp)\n" /* line 1216 | channel */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4cf5c_0004d180\n"
        ".Lf4cf5c_0004d07e:\n"
        "movl $0xffdb40, %ecx\n" /* line 1219 */
        "leal (%ebx, %ebx, 4), %eax\n" /* channel */
        "shll $4, %eax\n"
        "movss -0x20(%ebp), %xmm0\n" /* volume */
        "movss %xmm0, 8(%eax, %ecx)\n"
        "movl $0xffda50, %edx\n" /* line 1220 */
        "movss %xmm0, 8(%edx, %edi, 8)\n"
        "cmpl $0, -0x34(%ebp)\n" /* line 1221 */
        "jle .Lf4cf5c_0004d18d\n"
        "cvtsi2ssl -0x34(%ebp), %xmm1\n" /* line 1223 */
        "movss 0xffdb48(%eax), %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%edx, %edi, 8)\n"
        "movl $0, 8(%eax, %ecx)\n" /* line 1224 */
        ".Lf4cf5c_0004d0c8:\n"
        "movl snd_enableStream, %eax\n" /* line 1231 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf4cf5c_0004d140\n"
        "movl 8(%ebp), %eax\n" /* line 1232 | system */
        "movl %eax, 0x30(%esp)\n"
        "movl %ebx, 0x2c(%esp)\n" /* channel */
        "movl 0x2c(%esi), %eax\n" /* pAlias */
        "shrl $1, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl 0x3c(%esi), %eax\n" /* pAlias */
        "movl %eax, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* pitch */
        "movss %xmm0, 0x18(%esp)\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* channel */
        "shll $4, %eax\n"
        "movl 0xffdb48(%eax), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl $0xffdaf4, 0x10(%esp)\n"
        "movl $0x400, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pAlias */
        "movl %esi, (%esp)\n" /* pAlias */
        "calll SND_StartAliasStreamOnChannel\n"
        /* } scope */
        ".Lf4cf5c_0004d140:\n"
        "addl $0x6c, %esp\n" /* line 1233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4cf5c_0004d148:\n"
        "movl %esi, (%esp)\n" /* line 1203 | pAlias */
        "calll Com_GetSoundFileName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%esi), %eax\n" /* pAlias */
        "movl %eax, 8(%esp)\n"
        "movl $0x218ba0, 4(%esp)\n" /* "alias %s sound %s played as an ambient / music track uses a" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x2c(%esi), %edx\n" /* pAlias */
        "jmp .Lf4cf5c_0004cfb9\n"
        ".Lf4cf5c_0004d176:\n"
        "calll SND_PauseSounds\n" /* line 1181 */
        "jmp .Lf4cf5c_0004cf90\n"
        ".Lf4cf5c_0004d180:\n"
        "movl %ebx, (%esp)\n" /* line 1217 | channel */
        "calll SND_StopStreamChannel\n"
        "jmp .Lf4cf5c_0004d07e\n"
        ".Lf4cf5c_0004d18d:\n"
        "movl $0, 0xc(%edx, %edi, 8)\n" /* line 1228 */
        "jmp .Lf4cf5c_0004d0c8\n"
    );
}

/* line 1277 */
__attribute__((naked))
jpeg_component_info SND_PlayAmbientAlias(const snd_alias_t *pAlias, int fadetime, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1277 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pAlias */
        "movl 0xc(%ebp), %eax\n" /* fadetime */
        "movl %eax, -0x2c(%ebp)\n" /* fadetime */
        "movl 0x10(%ebp), %edx\n" /* system */
        "movl %edx, -0x30(%ebp)\n" /* system */
        /* { scope 1 */
        "cmpb $0, g_snd\n" /* line 1285 */
        "je .Lf4d19a_0004d358\n"
        "testl %esi, %esi\n" /* line 1288 | pAlias */
        "je .Lf4d19a_0004d358\n"
        "movl 0xffda70, %eax\n" /* line 1291 */
        "leal 0x20(%eax), %ebx\n" /* tracknum */
        "leal 0xffda50(, %eax, 8), %eax\n" /* line 1292 */
        "movl %eax, -0x34(%ebp)\n"
        "addl $8, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* trackptr */
        "movl %ebx, (%esp)\n" /* line 1293 | tracknum */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4d19a_0004d217\n"
        "leal (%ebx, %ebx, 4), %edi\n" /* line 1296 | tracknum */
        "shll $4, %edi\n"
        "movl 0xffdb58(%edi), %edx\n"
        "movl (%edx), %eax\n"
        "cmpl (%esi), %eax\n" /* pAlias */
        "je .Lf4d19a_0004d358\n"
        "movl %edx, (%esp)\n" /* line 1302 */
        "calll Com_GetSoundFileName\n"
        "movl %eax, %ebx\n" /* tracknum */
        "movl %esi, (%esp)\n" /* pAlias */
        "calll Com_GetSoundFileName\n"
        "cmpl %eax, %ebx\n" /* tracknum */
        "je .Lf4d19a_0004d291\n"
        ".Lf4d19a_0004d217:\n"
        "movl 0xffda70, %ebx\n" /* line 1317 | track */
        /* { scope 2 */
        "leal 0x20(%ebx), %edi\n" /* line 1241 */
        "movl %edi, (%esp)\n"
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4d19a_0004d26a\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1244 | fadetime */
        "testl %edx, %edx\n"
        "je .Lf4d19a_0004d360\n"
        "movl $0xffda50, %eax\n" /* line 1248 */
        "movss 0xffda58(, %ebx, 8), %xmm1\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf4d19a_0004d26a\n"
        "xorps 0x2f0200, %xmm1\n" /* line 1250 */
        "cvtsi2ssl -0x2c(%ebp), %xmm0\n" /* fadetime */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%eax, %ebx, 8)\n"
        "movss %xmm2, 8(%eax, %ebx, 8)\n" /* line 1251 */
        /* } scope */
        ".Lf4d19a_0004d26a:\n"
        "movl $3, %eax\n" /* line 1320 */
        "subl 0xffda70, %eax\n"
        "movl %eax, 0xffda70\n"
        "movl -0x30(%ebp), %edx\n" /* line 1321 | system */
        "movl %edx, 8(%ebp)\n" /* pAlias */
        "movl -0x2c(%ebp), %ecx\n" /* fadetime */
        "movl %esi, %edx\n" /* pAlias */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1323 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SND_StartBackground\n" /* line 1321 */
        ".Lf4d19a_0004d291:\n"
        "movl 0xffdb58(%edi), %ecx\n" /* line 1302 */
        "movl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x2c(%esi), %ebx\n" /* pAlias, tracknum */
        "movl %eax, %edx\n"
        "andl $1, %edx\n"
        "movl %ebx, %eax\n" /* tracknum */
        "andl $1, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf4d19a_0004d217\n"
        "movss 0x1c(%ecx), %xmm0\n"
        "ucomiss 0x1c(%esi), %xmm0\n" /* pAlias */
        "jne .Lf4d19a_0004d217\n"
        "jp .Lf4d19a_0004d217\n"
        "movss 0x20(%ecx), %xmm0\n"
        "ucomiss 0x20(%esi), %xmm0\n" /* pAlias */
        "jne .Lf4d19a_0004d217\n"
        "jp .Lf4d19a_0004d217\n"
        "andl $0x780, -0x28(%ebp)\n"
        "andl $0x780, %ebx\n" /* tracknum */
        "cmpl -0x28(%ebp), %ebx\n" /* tracknum */
        "jne .Lf4d19a_0004d217\n"
        "movl %esi, 0xffdb58(%edi)\n" /* line 1305 | pAlias */
        "movl %esi, 0xffdb5c(%edi)\n" /* line 1306 | pAlias */
        "movss 0x14(%esi), %xmm0\n" /* line 1307 | pAlias */
        "movss %xmm0, -0x24(%ebp)\n"
        "movss 0x18(%esi), %xmm0\n" /* pAlias */
        "subss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "calll randomf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "mulss -0x20(%ebp), %xmm2\n"
        "addss -0x24(%ebp), %xmm2\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 1308 | fadetime */
        "testl %ecx, %ecx\n"
        "je .Lf4d19a_0004d36d\n"
        "movaps %xmm2, %xmm0\n" /* line 1309 */
        "movl -0x34(%ebp), %eax\n"
        "subss 8(%eax), %xmm0\n"
        "cvtsi2ssl -0x2c(%ebp), %xmm1\n" /* fadetime */
        "divss %xmm1, %xmm0\n"
        "movl -0x1c(%ebp), %edx\n" /* trackptr */
        "movss %xmm0, 4(%edx)\n"
        ".Lf4d19a_0004d351:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1312 | trackptr */
        "movss %xmm2, (%edx)\n"
        /* } scope */
        ".Lf4d19a_0004d358:\n"
        "addl $0x4c, %esp\n" /* line 1323 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf4d19a_0004d360:\n"
        "movl %edi, (%esp)\n" /* line 1246 */
        "calll SND_StopStreamChannel\n"
        "jmp .Lf4d19a_0004d26a\n"
        /* } scope */
        ".Lf4d19a_0004d36d:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1311 | trackptr */
        "movl $0, 4(%eax)\n"
        "jmp .Lf4d19a_0004d351\n"
    );
}

/* line 1256 */
__attribute__((naked))
jpeg_component_info SND_PlayMusicAlias(const snd_alias_t *pAlias, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1256 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pAlias */
        "movl 0xc(%ebp), %esi\n" /* system */
        "cmpb $0, g_snd\n" /* line 1258 */
        "je .Lf4d37a_0004d3a5\n"
        "testl %ebx, %ebx\n" /* line 1261 | pAlias */
        "je .Lf4d37a_0004d3a5\n"
        "movl $0x20, (%esp)\n" /* line 1264 */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4d37a_0004d3ac\n"
        ".Lf4d37a_0004d3a5:\n"
        "addl $0x10, %esp\n" /* line 1268 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4d37a_0004d3ac:\n"
        "movl %esi, 8(%ebp)\n" /* line 1267 | system, pAlias */
        "xorl %ecx, %ecx\n"
        "movl %ebx, %edx\n" /* pAlias */
        "xorl %eax, %eax\n"
        "addl $0x10, %esp\n" /* line 1268 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp SND_StartBackground\n" /* line 1267 */
    );
}

/* line 1271 */
__attribute__((naked))
jpeg_component_info SND_StopMusic(int fadetime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1271 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* fadetime */
        "movl $0x20, (%esp)\n" /* line 1241 */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4d3c0_0004d40e\n"
        "testl %ebx, %ebx\n" /* line 1244 */
        "je .Lf4d3c0_0004d414\n"
        "movss 0xffda58, %xmm1\n" /* line 1248 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf4d3c0_0004d40e\n"
        "xorps 0x2f0210, %xmm1\n" /* line 1250 */
        "cvtsi2ssl %ebx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 0xffda5c\n"
        "movss %xmm2, 0xffda58\n" /* line 1251 */
        ".Lf4d3c0_0004d40e:\n"
        "addl $0x14, %esp\n" /* line 1274 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf4d3c0_0004d414:\n"
        "movl $0x20, 8(%ebp)\n" /* line 1246 | fadetime */
        "addl $0x14, %esp\n" /* line 1274 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SND_StopStreamChannel\n" /* line 1246 */
    );
}

/* line 1920 */
__attribute__((naked))
jpeg_component_info SND_StopSounds(snd_stopsounds_arg_t which)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1920 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_snd\n" /* line 1924 */
        "je .Lf4d426_0004d63c\n"
        "testb $8, 8(%ebp)\n" /* line 1927 | which */
        "jne .Lf4d426_0004d461\n"
        "movl 0xffebc4, %eax\n" /* line 1929 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4d426_0004d6f7\n"
        ".Lf4d426_0004d453:\n"
        "movl 0xffebc8, %ebx\n" /* line 1935 | i */
        "testl %ebx, %ebx\n" /* i */
        "jg .Lf4d426_0004d6ce\n"
        ".Lf4d426_0004d461:\n"
        "movl 0xffebcc, %eax\n" /* line 1942 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jg .Lf4d426_0004d644\n"
        ".Lf4d426_0004d472:\n"
        "testb $1, 8(%ebp)\n" /* line 1954 | which */
        "jne .Lf4d426_0004d56e\n"
        ".Lf4d426_0004d47c:\n"
        "movl $0, -0x20(%ebp)\n"
        "movl $g_snd, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %esi\n" /* i */
        "addl $1, %esi\n" /* line 1920 | i */
        /* { scope 2 */
        "movl %esi, %eax\n" /* line 1725 | i */
        "shll $5, %eax\n"
        "leal 0xffda78(%eax), %ebx\n" /* effect */
        "movb $0, 0x1c(%ebx)\n" /* line 1726 | effect */
        "cmpl 0xffdad8, %ebx\n" /* line 1728 | effect */
        "je .Lf4d426_0004d4d1\n"
        ".Lf4d426_0004d4a7:\n"
        "addl $0x20, -0x1c(%ebp)\n" /* line 1746 */
        /* } scope */
        "cmpl $2, %esi\n" /* line 1956 | i */
        "je .Lf4d426_0004d56e\n"
        ".Lf4d426_0004d4b4:\n"
        "movl %esi, -0x20(%ebp)\n" /* i */
        "addl $1, %esi\n" /* line 1920 | i */
        /* { scope 2 */
        "movl %esi, %eax\n" /* line 1725 | i */
        "shll $5, %eax\n"
        "leal 0xffda78(%eax), %ebx\n" /* effect */
        "movb $0, 0x1c(%ebx)\n" /* line 1726 | effect */
        "cmpl 0xffdad8, %ebx\n" /* line 1728 | effect */
        "jne .Lf4d426_0004d4a7\n"
        ".Lf4d426_0004d4d1:\n"
        "movl -0x20(%ebp), %edx\n"
        "testl %edx, %edx\n" /* line 1731 */
        "js .Lf4d426_0004d507\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1733 */
        "cmpb $0, 0x294(%eax)\n"
        "jne .Lf4d426_0004d507\n"
        "movl %edx, %eax\n" /* line 1734 */
        "shll $5, %eax\n"
        "leal 0xffda58(%eax), %ecx\n"
        "xorl %edi, %edi\n"
        ".Lf4d426_0004d4f1:\n"
        "subl $1, %edx\n" /* line 1731 */
        "cmpl -0x20(%ebp), %edi\n"
        "je .Lf4d426_0004d507\n"
        "movzbl 0x1c(%ecx), %eax\n" /* line 1733 */
        "addl $1, %edi\n"
        "subl $0x20, %ecx\n"
        "testb %al, %al\n"
        "je .Lf4d426_0004d4f1\n"
        ".Lf4d426_0004d507:\n"
        "shll $5, %edx\n" /* line 1741 */
        "addl $0xffda70, %edx\n"
        "leal 8(%edx), %eax\n"
        "movl %eax, 0xffdad8\n"
        "movl 8(%edx), %eax\n" /* line 1742 */
        "movl %eax, (%esp)\n"
        "calll SND_SetRoomtype\n"
        "movl 4(%ebx), %edx\n" /* line 1743 | effect */
        "movl 0xffdad8, %eax\n"
        "movl %edx, 4(%eax)\n"
        "movl 0xffdad8, %eax\n" /* line 1744 */
        "movss 8(%eax), %xmm0\n"
        "subss 4(%ebx), %xmm0\n" /* effect */
        "movss %xmm0, 0xc(%eax)\n"
        "movl 0x10(%ebx), %edx\n" /* line 1745 | effect */
        "movl 0xffdad8, %eax\n"
        "movl %edx, 0x10(%eax)\n"
        "movl 0xffdad8, %eax\n" /* line 1746 */
        "movss 0x14(%eax), %xmm0\n"
        "subss 0x10(%ebx), %xmm0\n" /* effect */
        "movss %xmm0, 0x18(%eax)\n"
        "addl $0x20, -0x1c(%ebp)\n"
        /* } scope */
        "cmpl $2, %esi\n" /* line 1956 | i */
        "jne .Lf4d426_0004d4b4\n"
        ".Lf4d426_0004d56e:\n"
        "testb $0x10, 8(%ebp)\n" /* line 1962 | which */
        "jne .Lf4d426_0004d63c\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $g_snd, -0x24(%ebp)\n"
        "leal 1(%ebx), %edi\n" /* line 1920 | effect */
        /* { scope 2 */
        "movl %edi, %eax\n" /* line 1395 */
        "shll $7, %eax\n"
        "leal 0xffd834(%eax, %edi, 8), %edx\n"
        "movb $0, 0x84(%edx)\n" /* line 1396 */
        "cmpl 0xffda54, %edx\n" /* line 1398 */
        "je .Lf4d426_0004d5cf\n"
        ".Lf4d426_0004d59f:\n"
        "addl $0x88, -0x24(%ebp)\n" /* line 1412 */
        /* } scope */
        "cmpl $3, %edi\n" /* line 1964 */
        "je .Lf4d426_0004d63c\n"
        ".Lf4d426_0004d5af:\n"
        "movl %edi, %ebx\n" /* i */
        "leal 1(%ebx), %edi\n" /* line 1920 | effect */
        /* { scope 2 */
        "movl %edi, %eax\n" /* line 1395 */
        "shll $7, %eax\n"
        "leal 0xffd834(%eax, %edi, 8), %edx\n"
        "movb $0, 0x84(%edx)\n" /* line 1396 */
        "cmpl 0xffda54, %edx\n" /* line 1398 */
        "jne .Lf4d426_0004d59f\n"
        ".Lf4d426_0004d5cf:\n"
        "movl %ebx, %esi\n" /* i */
        "testl %ebx, %ebx\n" /* line 1401 */
        "js .Lf4d426_0004d5e5\n"
        "movl -0x24(%ebp), %eax\n" /* line 1403 */
        "cmpb $0, 0xb8(%eax)\n"
        "je .Lf4d426_0004d695\n"
        ".Lf4d426_0004d5e5:\n"
        "movl %esi, %eax\n" /* line 1411 | i */
        "shll $7, %eax\n"
        "leal 0xffd834(%eax, %esi, 8), %eax\n"
        "movl %eax, 0xffda54\n"
        "movl %edx, %ecx\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %ebx, %ebx\n"
        "jmp .Lf4d426_0004d603\n"
        ".Lf4d426_0004d5fe:\n"
        "movl 0xffda54, %eax\n"
        ".Lf4d426_0004d603:\n"
        "movl (%ecx), %edx\n" /* line 1414 */
        "movl %edx, (%ebx, %eax)\n"
        "movl %ebx, %eax\n" /* line 1415 */
        "addl 0xffda54, %eax\n"
        "movss 4(%eax), %xmm0\n"
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "addl $1, %esi\n" /* line 1412 | i */
        "addl $0xc, %ebx\n"
        "addl $0xc, %ecx\n"
        "cmpl $0xb, %esi\n" /* i */
        "jne .Lf4d426_0004d5fe\n"
        "addl $0x88, -0x24(%ebp)\n"
        /* } scope */
        "cmpl $3, %edi\n" /* line 1964 */
        "jne .Lf4d426_0004d5af\n"
        /* } scope */
        ".Lf4d426_0004d63c:\n"
        "addl $0x2c, %esp\n" /* line 1969 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4d426_0004d644:\n"
        "movl 8(%ebp), %eax\n" /* line 1946 | which */
        "shrl $1, %eax\n"
        "andl $1, %eax\n"
        "testb $4, 8(%ebp)\n" /* which */
        "jne .Lf4d426_0004d74c\n"
        "testl %eax, %eax\n"
        "jne .Lf4d426_0004d727\n"
        "movl $0x20, %ebx\n" /* i */
        ".Lf4d426_0004d663:\n"
        "movl %ebx, (%esp)\n" /* line 1944 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4d426_0004d677\n"
        "movl %ebx, (%esp)\n" /* line 1950 | i */
        "calll SND_StopStreamChannel\n"
        ".Lf4d426_0004d677:\n"
        "addl $1, %ebx\n" /* line 1942 | i */
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jl .Lf4d426_0004d663\n"
        "testb $1, 8(%ebp)\n" /* line 1954 | which */
        "jne .Lf4d426_0004d56e\n"
        "jmp .Lf4d426_0004d47c\n"
        /* { scope 2 */
        ".Lf4d426_0004d695:\n"
        "movl %ebx, %eax\n" /* line 1404 */
        "shll $7, %eax\n"
        "leal snd_errorOnMissing(%eax, %ebx, 8), %ecx\n"
        "movl $0, -0x28(%ebp)\n"
        ".Lf4d426_0004d6a8:\n"
        "subl $1, %esi\n" /* line 1401 | i */
        "cmpl %ebx, -0x28(%ebp)\n"
        "je .Lf4d426_0004d5e5\n"
        "movzbl 0x84(%ecx), %eax\n" /* line 1403 */
        "addl $1, -0x28(%ebp)\n"
        "subl $0x88, %ecx\n"
        "testb %al, %al\n"
        "je .Lf4d426_0004d6a8\n"
        "jmp .Lf4d426_0004d5e5\n"
        /* } scope */
        ".Lf4d426_0004d6ce:\n"
        "xorl %ebx, %ebx\n" /* line 1935 | i */
        "jmp .Lf4d426_0004d6e1\n"
        ".Lf4d426_0004d6d2:\n"
        "addl $1, %ebx\n" /* i */
        "cmpl %ebx, 0xffebc8\n" /* i */
        "jle .Lf4d426_0004d461\n"
        ".Lf4d426_0004d6e1:\n"
        "movl %ebx, (%esp)\n" /* line 1937 | i */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4d426_0004d6d2\n"
        "movl %ebx, (%esp)\n" /* line 1938 | i */
        "calll SND_Stop3DChannel\n"
        "jmp .Lf4d426_0004d6d2\n"
        ".Lf4d426_0004d6f7:\n"
        "movl $0x2d, %ebx\n" /* line 1929 | i */
        "jmp .Lf4d426_0004d711\n"
        ".Lf4d426_0004d6fe:\n"
        "addl $1, %ebx\n" /* i */
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl %ebx, %eax\n" /* i */
        "jle .Lf4d426_0004d453\n"
        ".Lf4d426_0004d711:\n"
        "movl %ebx, (%esp)\n" /* line 1931 | i */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4d426_0004d6fe\n"
        "movl %ebx, (%esp)\n" /* line 1932 | i */
        "calll SND_Stop2DChannel\n"
        "jmp .Lf4d426_0004d6fe\n"
        /* { scope 2 */
        ".Lf4d426_0004d727:\n"
        "movl $0x20, %ebx\n" /* line 1404 */
        /* } scope */
        ".Lf4d426_0004d72c:\n"
        "movl %ebx, (%esp)\n" /* line 1944 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4d426_0004d775\n"
        ".Lf4d426_0004d738:\n"
        "addl $1, %ebx\n" /* line 1942 | i */
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %ebx, %eax\n" /* i */
        "jg .Lf4d426_0004d72c\n"
        "jmp .Lf4d426_0004d472\n"
        ".Lf4d426_0004d74c:\n"
        "testl %eax, %eax\n" /* line 1950 */
        "jne .Lf4d426_0004d796\n"
        "movl $0x20, %ebx\n" /* i */
        ".Lf4d426_0004d755:\n"
        "movl %ebx, (%esp)\n" /* line 1944 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4d426_0004d784\n"
        ".Lf4d426_0004d761:\n"
        "addl $1, %ebx\n" /* line 1942 | i */
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %ebx, %eax\n" /* i */
        "jg .Lf4d426_0004d755\n"
        "jmp .Lf4d426_0004d472\n"
        ".Lf4d426_0004d775:\n"
        "cmpl $0x20, %ebx\n" /* line 1946 | i */
        "je .Lf4d426_0004d738\n"
        "movl %ebx, (%esp)\n" /* line 1950 | i */
        "calll SND_StopStreamChannel\n"
        "jmp .Lf4d426_0004d738\n"
        ".Lf4d426_0004d784:\n"
        "leal -0x21(%ebx), %eax\n" /* line 1948 | i */
        "cmpl $1, %eax\n"
        "jbe .Lf4d426_0004d761\n"
        "movl %ebx, (%esp)\n" /* line 1950 | i */
        "calll SND_StopStreamChannel\n"
        "jmp .Lf4d426_0004d761\n"
        ".Lf4d426_0004d796:\n"
        "movl $0x20, %ebx\n" /* line 1946 | i */
        ".Lf4d426_0004d79b:\n"
        "movl %ebx, (%esp)\n" /* line 1944 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4d426_0004d7bc\n"
        "cmpl $0x20, %ebx\n" /* line 1946 | i */
        "je .Lf4d426_0004d7bc\n"
        "leal -0x21(%ebx), %eax\n" /* line 1948 | i */
        "cmpl $1, %eax\n"
        "jbe .Lf4d426_0004d7bc\n"
        "movl %ebx, (%esp)\n" /* line 1950 | i */
        "calll SND_StopStreamChannel\n"
        ".Lf4d426_0004d7bc:\n"
        "addl $1, %ebx\n" /* line 1942 | i */
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %ebx, %eax\n" /* i */
        "jg .Lf4d426_0004d79b\n"
        "jmp .Lf4d426_0004d472\n"
    );
}

/* line 2064 */
__attribute__((naked))
jpeg_component_info SND_ShutdownChannels(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2064 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, (%esp)\n" /* line 2066 */
        "calll SND_StopSounds\n"
        "movl $0x1090, 8(%esp)\n" /* line 2068 */
        "movl $0, 4(%esp)\n"
        "movl $0xffdb34, (%esp)\n"
        "calll memset\n"
        "leave\n" /* line 2069 */
        "retl\n"
    );
}

/* line 2037 */
__attribute__((naked))
jpeg_component_info SND_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2037 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll Voice_Shutdown\n" /* line 2040 */
        "movl 0xffd81c, %eax\n" /* line 2043 */
        "testl %eax, %eax\n"
        "je .Lf4d800_0004d81c\n"
        "movl %eax, (%esp)\n" /* line 2044 */
        "calll Z_FreeInternal\n"
        ".Lf4d800_0004d81c:\n"
        "cmpb $0, g_snd\n" /* line 2046 */
        "jne .Lf4d800_0004d827\n"
        "leave\n" /* line 2061 */
        "retl\n"
        ".Lf4d800_0004d827:\n"
        "movl $0, (%esp)\n" /* line 2048 */
        "calll SND_StopSounds\n"
        "movl $1, (%esp)\n" /* line 2051 */
        "calll Com_UnloadSoundAliases\n"
        "movl $0, (%esp)\n" /* line 2052 */
        "calll Com_UnloadSoundAliases\n"
        "calll SND_ShutdownDriver\n" /* line 2055 */
        "movl $0x13d0, 8(%esp)\n" /* line 2056 */
        "movl $0, 4(%esp)\n"
        "movl $g_snd, (%esp)\n"
        "calll memset\n"
        "movl $0x218a70, (%esp)\n" /* line 2058 */
        "calll Cmd_RemoveCommand\n"
        "movl $0x218a8c, (%esp)\n" /* line 2059 */
        "calll Cmd_RemoveCommand\n"
        "leave\n" /* line 2061 */
        "retl\n"
    );
}

/* line 1326 */
__attribute__((naked))
jpeg_component_info SND_FadeAllSounds(float volume, int fadetime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1326 */
        "movl %esp, %ebp\n"
        "movss 8(%ebp), %xmm0\n" /* volume */
        "movl 0xc(%ebp), %eax\n" /* fadetime */
        "movss %xmm0, 0xffd82c\n" /* line 1331 */
        "movaps %xmm0, %xmm1\n" /* line 1332 */
        "subss 0xffd828, %xmm1\n"
        "movss %xmm1, 0xffd830\n"
        "testl %eax, %eax\n" /* line 1333 */
        "je .Lf4d886_0004d8c2\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1334 */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 0xffd830\n"
        ".Lf4d886_0004d8c0:\n"
        "popl %ebp\n" /* line 1337 */
        "retl\n"
        ".Lf4d886_0004d8c2:\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 1335 | 0.0f */
        "jne .Lf4d886_0004d8c0\n"
        "jp .Lf4d886_0004d8c0\n"
        "movl $0, 8(%ebp)\n" /* line 1336 | volume */
        "popl %ebp\n" /* line 1337 */
        "jmp SND_StopSounds\n" /* line 1336 */
    );
}

/* line 121 */
__attribute__((naked))
jpeg_component_info SND_SetEnvironmentEffects_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 121 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 130 */
        "cmpl $6, %eax\n"
        "je .Lf4d8da_0004d901\n"
        "movl $0x218c74, (%esp)\n" /* line 132 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf4d8da_0004d8f9:\n"
        "addl $0x5c, %esp\n" /* line 166 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4d8da_0004d901:\n"
        "movl $1, (%esp)\n" /* line 136 */
        "calll Cmd_Argv\n"
        "movl %eax, %edi\n" /* priorityName */
        /* { scope 2: priorityStrings */
        /* { scope 3 */
        "movl $0x218298, -0x24(%ebp)\n" /* line 75 | priorityStrings */
        "movl $0x2182a0, -0x20(%ebp)\n" /* "level" */
        "movl $0x2182a8, -0x1c(%ebp)\n" /* "shellshock" */
        "movl $1, %esi\n"
        "leal -0x20(%ebp), %ebx\n"
        ".Lf4d8da_0004d92c:\n"
        "movl (%ebx), %eax\n" /* line 83 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf4d8da_0004d984\n"
        "addl $1, %esi\n" /* line 81 */
        "addl $4, %ebx\n"
        "cmpl $3, %esi\n"
        "jne .Lf4d8da_0004d92c\n"
        "movl %edi, 4(%esp)\n" /* line 90 */
        "movl $0x2182b4, (%esp)\n" /* "invalid priority string '%s', it must be one of the followin" */
        "calll Com_Printf\n"
        "xorw %si, %si\n"
        "leal -0x20(%ebp), %ebx\n"
        ".Lf4d8da_0004d95f:\n"
        "movl (%ebx), %eax\n" /* line 92 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        "addl $1, %esi\n"
        "addl $4, %ebx\n"
        "cmpl $2, %esi\n" /* line 91 */
        "jne .Lf4d8da_0004d95f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 166 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: priorityStrings */
        /* { scope 3 */
        ".Lf4d8da_0004d984:\n"
        "movl %esi, -0x34(%ebp)\n" /* line 83 | priority */
        /* } scope */
        /* } scope */
        "movl $2, (%esp)\n" /* line 139 */
        "calll Cmd_Argv\n"
        "movl %eax, %edi\n" /* priorityName */
        "movl 0x195ed1c, %edx\n" /* line 104 */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf4d8da_0004d9c2\n"
        "xorl %esi, %esi\n"
        "movl %edx, %ebx\n"
        ".Lf4d8da_0004d9a5:\n"
        "movl %eax, 4(%esp)\n" /* line 106 */
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf4d8da_0004da06\n"
        "addl $1, %esi\n" /* line 104 */
        "movl 4(%ebx), %eax\n"
        "addl $4, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf4d8da_0004d9a5\n"
        ".Lf4d8da_0004d9c2:\n"
        "movl %edi, 4(%esp)\n" /* line 110 */
        "movl $0x2188a0, (%esp)\n" /* "invalid roomtype string '%s', it must be one of the followin" */
        "calll Com_Printf\n"
        "movl 0x195ed1c, %eax\n" /* line 111 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf4d8da_0004da76\n"
        "movl %eax, %ebx\n"
        "jmp .Lf4d8da_0004d9ef\n"
        ".Lf4d8da_0004d9e5:\n"
        "movl 4(%ebx), %edx\n"
        "addl $4, %ebx\n"
        "testl %edx, %edx\n"
        "je .Lf4d8da_0004da0a\n"
        ".Lf4d8da_0004d9ef:\n"
        "cmpb $0, (%edx)\n" /* line 113 */
        "je .Lf4d8da_0004d9e5\n"
        "movl %edx, 4(%esp)\n" /* line 114 */
        "movl $0x2182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        "jmp .Lf4d8da_0004d9e5\n"
        ".Lf4d8da_0004da06:\n"
        "testl %esi, %esi\n" /* line 141 | roomtypeIndex */
        "jne .Lf4d8da_0004da25\n"
        ".Lf4d8da_0004da0a:\n"
        "movl 0x195ed1c, %eax\n"
        "movl (%eax), %eax\n"
        ".Lf4d8da_0004da11:\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* priorityName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf4d8da_0004d8f9\n"
        ".Lf4d8da_0004da25:\n"
        "movl $3, (%esp)\n" /* line 144 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x48(%ebp)\n"
        "cvtsd2ss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* drylevel */
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 145 | 0.0f */
        "jp .Lf4d8da_0004da51\n"
        "jb .Lf4d8da_0004da5a\n"
        ".Lf4d8da_0004da51:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf4d8da_0004da7a\n"
        ".Lf4d8da_0004da5a:\n"
        "cvtss2sd -0x30(%ebp), %xmm0\n" /* line 147 | drylevel */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x218cf8, (%esp)\n" /* "invalid 'drylevel' %g, must be in the range of 0.0-1.0
" */
        "calll Com_Printf\n"
        "jmp .Lf4d8da_0004d8f9\n"
        ".Lf4d8da_0004da76:\n"
        "movl %edx, %eax\n"
        "jmp .Lf4d8da_0004da11\n"
        ".Lf4d8da_0004da7a:\n"
        "movl $4, (%esp)\n" /* line 151 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x40(%ebp)\n"
        "cvtsd2ss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* wetlevel */
        "pxor %xmm0, %xmm0\n" /* line 152 */
        "ucomiss -0x2c(%ebp), %xmm0\n" /* wetlevel */
        "ja .Lf4d8da_0004dab3\n"
        "movss -0x2c(%ebp), %xmm0\n" /* wetlevel */
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf4d8da_0004dacf\n"
        ".Lf4d8da_0004dab3:\n"
        "cvtss2sd -0x2c(%ebp), %xmm0\n" /* line 154 | wetlevel */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x218d30, (%esp)\n" /* "invalid 'wetlevel' %g, must be in the range of 0.0-1.0
" */
        "calll Com_Printf\n"
        "jmp .Lf4d8da_0004d8f9\n"
        ".Lf4d8da_0004dacf:\n"
        "movl $5, (%esp)\n" /* line 158 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "testl %eax, %eax\n" /* line 159 */
        "js .Lf4d8da_0004db15\n"
        "movl %eax, 0x10(%esp)\n" /* line 165 */
        "movss -0x2c(%ebp), %xmm0\n" /* wetlevel */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* drylevel */
        "movss %xmm0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* priorityName */
        "movl -0x34(%ebp), %eax\n" /* priority */
        "movl %eax, (%esp)\n"
        "calll SND_SetEnvironmentEffects\n"
        "jmp .Lf4d8da_0004d8f9\n"
        ".Lf4d8da_0004db15:\n"
        "movl %eax, 4(%esp)\n" /* line 161 */
        "movl $0x218d68, (%esp)\n" /* "invalid 'fademsec' %i, must be greater than or equal to zero" */
        "calll Com_Printf\n"
        "jmp .Lf4d8da_0004d8f9\n"
    );
}

/* line 169 */
__attribute__((naked))
jpeg_component_info SND_DeactivateEnvironmentEffects_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 169 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1: effect */
        "calll Cmd_Argc\n" /* line 174 */
        "cmpl $3, %eax\n"
        "je .Lf4db2a_0004db51\n"
        "movl $0x218da8, (%esp)\n" /* line 176 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf4db2a_0004db49:\n"
        "addl $0x3c, %esp\n" /* line 191 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: effect */
        ".Lf4db2a_0004db51:\n"
        "movl $1, (%esp)\n" /* line 180 */
        "calll Cmd_Argv\n"
        "movl %eax, %edi\n" /* priorityName */
        /* { scope 2: priorityStrings */
        /* { scope 3 */
        "movl $0x218298, -0x24(%ebp)\n" /* line 75 | priorityStrings */
        "movl $0x2182a0, -0x20(%ebp)\n" /* "level" */
        "movl $0x2182a8, -0x1c(%ebp)\n" /* "shellshock" */
        "movl $1, %esi\n"
        "leal -0x20(%ebp), %ebx\n"
        ".Lf4db2a_0004db7c:\n"
        "movl (%ebx), %eax\n" /* line 83 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf4db2a_0004dbd4\n"
        "addl $1, %esi\n" /* line 81 */
        "addl $4, %ebx\n"
        "cmpl $3, %esi\n"
        "jne .Lf4db2a_0004db7c\n"
        "movl %edi, 4(%esp)\n" /* line 90 */
        "movl $0x2182b4, (%esp)\n" /* "invalid priority string '%s', it must be one of the followin" */
        "calll Com_Printf\n"
        "xorw %si, %si\n"
        "leal -0x20(%ebp), %ebx\n"
        ".Lf4db2a_0004dbaf:\n"
        "movl (%ebx), %eax\n" /* line 92 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        "addl $1, %esi\n"
        "addl $4, %ebx\n"
        "cmpl $2, %esi\n" /* line 91 */
        "jne .Lf4db2a_0004dbaf\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 191 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: effect */
        ".Lf4db2a_0004dbd4:\n"
        "movl $2, (%esp)\n" /* line 183 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %edi\n" /* priorityName */
        "testl %eax, %eax\n" /* line 184 */
        "js .Lf4db2a_0004dce9\n"
        /* { scope 2: priorityStrings */
        "movl %esi, %edx\n" /* line 1725 */
        "shll $5, %edx\n"
        "leal 0xffda78(%edx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* effect */
        "movb $0, 0x1c(%eax)\n" /* line 1726 */
        "cmpl 0xffdad8, %eax\n" /* line 1728 */
        "jne .Lf4db2a_0004db49\n"
        "subl $1, %esi\n" /* line 1731 */
        "js .Lf4db2a_0004dcd4\n"
        "movl %esi, %eax\n" /* line 1733 */
        "shll $5, %eax\n"
        "cmpb $0, 0xffda94(%eax)\n"
        "jne .Lf4db2a_0004dcd4\n"
        "leal 0xffda38(%edx), %ebx\n" /* line 1734 */
        "movl %esi, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf4db2a_0004dc35:\n"
        "subl $1, %edx\n" /* line 1731 */
        "cmpl %esi, %ecx\n"
        "je .Lf4db2a_0004dc4a\n"
        "movzbl 0x1c(%ebx), %eax\n" /* line 1733 */
        "addl $1, %ecx\n"
        "subl $0x20, %ebx\n"
        "testb %al, %al\n"
        "je .Lf4db2a_0004dc35\n"
        ".Lf4db2a_0004dc4a:\n"
        "testl %edi, %edi\n" /* line 1738 | priorityName */
        "jne .Lf4db2a_0004dcdb\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x2c(%ebp)\n"
        ".Lf4db2a_0004dc5f:\n"
        "shll $5, %edx\n" /* line 1741 */
        "addl $0xffda70, %edx\n"
        "leal 8(%edx), %eax\n"
        "movl %eax, 0xffdad8\n"
        "movl 8(%edx), %eax\n" /* line 1742 */
        "movl %eax, (%esp)\n"
        "calll SND_SetRoomtype\n"
        "movl -0x30(%ebp), %eax\n" /* line 1743 | effect */
        "movl 4(%eax), %edx\n"
        "movl 0xffdad8, %eax\n"
        "movl %edx, 4(%eax)\n"
        "movl 0xffdad8, %eax\n" /* line 1744 */
        "movss 8(%eax), %xmm0\n"
        "movl -0x30(%ebp), %edx\n" /* effect */
        "subss 4(%edx), %xmm0\n"
        "divss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        "movl -0x30(%ebp), %eax\n" /* line 1745 | effect */
        "movl 0x10(%eax), %edx\n"
        "movl 0xffdad8, %eax\n"
        "movl %edx, 0x10(%eax)\n"
        "movl 0xffdad8, %eax\n" /* line 1746 */
        "movss 0x14(%eax), %xmm0\n"
        "movl -0x30(%ebp), %edx\n" /* effect */
        "subss 0x10(%edx), %xmm0\n"
        "divss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 0x18(%eax)\n"
        "jmp .Lf4db2a_0004db49\n"
        ".Lf4db2a_0004dcd4:\n"
        "movl %esi, %edx\n" /* line 1731 */
        "jmp .Lf4db2a_0004dc4a\n"
        ".Lf4db2a_0004dcdb:\n"
        "cvtsi2ssl %edi, %xmm0\n" /* line 1738 | priorityName */
        "movss %xmm0, -0x2c(%ebp)\n"
        "jmp .Lf4db2a_0004dc5f\n"
        /* } scope */
        ".Lf4db2a_0004dce9:\n"
        "movl %eax, 4(%esp)\n" /* line 186 */
        "movl $0x218d68, (%esp)\n" /* "invalid 'fademsec' %i, must be greater than or equal to zero" */
        "calll Com_Printf\n"
        "jmp .Lf4db2a_0004db49\n"
    );
}

/* line 2434 */
__attribute__((naked))
jpeg_component_info SND_Save(MemoryFile *memFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2434 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl $1, %esi\n"
        "movl $0xffd8bc, %ebx\n" /* alias */
        /* { scope 1: info */
        ".Lf4dcfe_0004dd11:\n"
        "movl %ebx, 8(%esp)\n" /* line 2441 | alias */
        "movl $0x88, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "addl $1, %esi\n" /* line 2438 */
        "addl $0x88, %ebx\n" /* alias */
        "cmpl $4, %esi\n"
        "jne .Lf4dcfe_0004dd11\n"
        "movw $1, %si\n"
        "movl $0xffda98, %ebx\n" /* alias */
        ".Lf4dcfe_0004dd3f:\n"
        "movl %ebx, 8(%esp)\n" /* line 2448 | alias */
        "movl $0x20, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteData\n"
        "addl $1, %esi\n" /* line 2445 */
        "addl $0x20, %ebx\n" /* alias */
        "cmpl $3, %esi\n"
        "jne .Lf4dcfe_0004dd3f\n"
        "movl $0xffda58, 8(%esp)\n" /* line 2453 */
        "movl $8, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "cmpb $0, g_snd\n" /* line 2456 */
        "je .Lf4dcfe_0004dd93\n"
        "movl 0xffebc8, %esi\n" /* line 2458 */
        "testl %esi, %esi\n"
        "jg .Lf4dcfe_0004deb3\n"
        ".Lf4dcfe_0004dd93:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 2461 */
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "cmpb $0, g_snd\n" /* line 2463 */
        "je .Lf4dcfe_0004ddc0\n"
        "movl 0xffebc4, %eax\n" /* line 2465 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4dcfe_0004de6c\n"
        ".Lf4dcfe_0004ddc0:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 2468 */
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "cmpb $0, g_snd\n" /* line 2470 */
        "je .Lf4dcfe_0004de51\n"
        "movl 0xffebcc, %edx\n" /* line 2472 */
        "leal 0x20(%edx), %eax\n"
        "cmpl $0x20, %eax\n"
        "jle .Lf4dcfe_0004de51\n"
        "movl $0x20, -0x4c(%ebp)\n"
        /* { scope 2 */
        ".Lf4dcfe_0004ddf1:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 2352 */
        "subl $0x21, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf4dcfe_0004de2e\n"
        "movl -0x4c(%ebp), %edx\n" /* line 2359 */
        "movl %edx, (%esp)\n"
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4dcfe_0004e0a8\n"
        ".Lf4dcfe_0004de0f:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 2367 */
        "leal (%edx, %edx, 4), %edx\n"
        "shll $4, %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        "cmpl $1, 0xffdb80(%edx)\n"
        "je .Lf4dcfe_0004e0c6\n"
        ".Lf4dcfe_0004de28:\n"
        "movl 0xffebcc, %edx\n"
        /* } scope */
        ".Lf4dcfe_0004de2e:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 2472 */
        "leal 0x20(%edx), %eax\n"
        "cmpl %eax, -0x4c(%ebp)\n"
        "jge .Lf4dcfe_0004de51\n"
        /* { scope 2 */
        "cmpl $0x22, -0x4c(%ebp)\n" /* line 2347 */
        "jle .Lf4dcfe_0004ddf1\n"
        "movl -0x4c(%ebp), %eax\n" /* line 2349 */
        "movl %eax, (%esp)\n"
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4dcfe_0004de0f\n"
        "jmp .Lf4dcfe_0004de28\n"
        /* } scope */
        ".Lf4dcfe_0004de51:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 2475 */
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteCString\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2476 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: info */
        ".Lf4dcfe_0004de6c:\n"
        "movl $0x2d, -0x50(%ebp)\n" /* line 2465 */
        "movl $g_snd, -0x58(%ebp)\n"
        /* { scope 2 */
        ".Lf4dcfe_0004de7a:\n"
        "movl -0x50(%ebp), %edx\n" /* line 2278 */
        "movl %edx, (%esp)\n"
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4dcfe_0004de99\n"
        "movl -0x58(%ebp), %eax\n" /* line 2281 */
        "cmpl $1, 0x1190(%eax)\n"
        "je .Lf4dcfe_0004dfbe\n"
        /* } scope */
        ".Lf4dcfe_0004de99:\n"
        "addl $1, -0x50(%ebp)\n" /* line 2465 */
        "addl $0x50, -0x58(%ebp)\n"
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl -0x50(%ebp), %eax\n"
        "jg .Lf4dcfe_0004de7a\n"
        "jmp .Lf4dcfe_0004ddc0\n"
        ".Lf4dcfe_0004deb3:\n"
        "xorl %edi, %edi\n" /* line 2458 | i */
        "movl $g_snd, -0x54(%ebp)\n"
        /* { scope 2 */
        ".Lf4dcfe_0004debc:\n"
        "movl %edi, (%esp)\n" /* line 2213 */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4dcfe_0004ded4\n"
        "movl -0x54(%ebp), %edx\n" /* line 2216 */
        "cmpl $1, 0x380(%edx)\n"
        "je .Lf4dcfe_0004dee8\n"
        /* } scope */
        ".Lf4dcfe_0004ded4:\n"
        "addl $1, %edi\n" /* line 2458 | i */
        "addl $0x50, -0x54(%ebp)\n"
        "cmpl 0xffebc8, %edi\n" /* i */
        "jl .Lf4dcfe_0004debc\n"
        "jmp .Lf4dcfe_0004dd93\n"
        /* { scope 2 */
        ".Lf4dcfe_0004dee8:\n"
        "movl %edi, (%esp)\n" /* line 2219 */
        "calll SND_Get3DChannelLength\n"
        "testl %eax, %eax\n"
        "je .Lf4dcfe_0004ded4\n"
        "movl %edi, (%esp)\n"
        "calll SND_Get3DChannelPlaybackRate\n"
        "testl %eax, %eax\n"
        "je .Lf4dcfe_0004ded4\n"
        "leal -0x3c(%ebp), %eax\n" /* line 2223 | info */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll SND_Get3DChannelSaveInfo\n"
        "movl -0x54(%ebp), %edx\n" /* line 2225 */
        "movl 0x358(%edx), %ebx\n" /* alias */
        /* { scope 3: value */
        "movl (%ebx), %eax\n" /* line 2113 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "movl %ebx, (%esp)\n" /* line 2114 */
        "calll SND_GetAliasOffset\n"
        "movw %ax, -0x1a(%ebp)\n" /* value */
        /* { scope 4 */
        "leal -0x1a(%ebp), %esi\n" /* line 88 | value */
        "movl %esi, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteData\n"
        /* } scope */
        /* } scope */
        "movl -0x54(%ebp), %eax\n" /* line 2226 */
        "movl 0x35c(%eax), %ebx\n" /* alias */
        /* { scope 3: value */
        "movl (%ebx), %eax\n" /* line 2113 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "movl %ebx, (%esp)\n" /* line 2114 */
        "calll SND_GetAliasOffset\n"
        "movw %ax, -0x1a(%ebp)\n" /* value */
        /* { scope 4 */
        "movl %esi, 8(%esp)\n" /* line 88 */
        "movl $2, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        /* } scope */
        /* } scope */
        "leal (%edi, %edi, 4), %eax\n" /* line 2227 */
        "shll $4, %eax\n"
        "addl $0xffdb34, %eax\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "calll SND_SaveChanInfo\n"
        "leal -0x3c(%ebp), %edx\n" /* line 2229 | info */
        "movl %edx, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "jmp .Lf4dcfe_0004ded4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4dcfe_0004dfbe:\n"
        "movl -0x50(%ebp), %edx\n" /* line 2284 */
        "movl %edx, (%esp)\n"
        "calll SND_Get2DChannelLength\n"
        "testl %eax, %eax\n"
        "je .Lf4dcfe_0004de99\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_Get2DChannelPlaybackRate\n"
        "testl %eax, %eax\n"
        "je .Lf4dcfe_0004de99\n"
        "leal -0x3c(%ebp), %edx\n" /* line 2288 | info */
        "movl %edx, 4(%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_Get2DChannelSaveInfo\n"
        "movl -0x58(%ebp), %edx\n" /* line 2290 */
        "movl 0x1168(%edx), %ebx\n" /* alias */
        /* { scope 3: value */
        "movl (%ebx), %eax\n" /* line 2113 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "movl %ebx, (%esp)\n" /* line 2114 */
        "calll SND_GetAliasOffset\n"
        "movw %ax, -0x1a(%ebp)\n" /* value */
        /* { scope 4 */
        "leal -0x1a(%ebp), %esi\n" /* line 88 | value */
        "movl %esi, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteData\n"
        /* } scope */
        /* } scope */
        "movl -0x58(%ebp), %eax\n" /* line 2291 */
        "movl 0x116c(%eax), %ebx\n" /* alias */
        /* { scope 3: value */
        "movl (%ebx), %eax\n" /* line 2113 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "movl %ebx, (%esp)\n" /* line 2114 */
        "calll SND_GetAliasOffset\n"
        "movw %ax, -0x1a(%ebp)\n" /* value */
        /* { scope 4 */
        "movl %esi, 8(%esp)\n" /* line 88 */
        "movl $2, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        /* } scope */
        /* } scope */
        "movl -0x50(%ebp), %edx\n" /* line 2292 */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "addl $0xffdb34, %eax\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "calll SND_SaveChanInfo\n"
        "leal -0x3c(%ebp), %eax\n" /* line 2294 | info */
        "movl %eax, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteData\n"
        "jmp .Lf4dcfe_0004de99\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4dcfe_0004e0a8:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 2361 */
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "movl 0xffebcc, %edx\n"
        "jmp .Lf4dcfe_0004de2e\n"
        ".Lf4dcfe_0004e0c6:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 2370 */
        "movl %eax, (%esp)\n"
        "calll SND_GetStreamChannelLength\n"
        "testl %eax, %eax\n"
        "je .Lf4dcfe_0004de28\n"
        "leal -0x3c(%ebp), %edx\n" /* line 2373 | info */
        "movl %edx, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_GetStreamChannelSaveInfo\n"
        "movl -0x5c(%ebp), %edx\n" /* line 2375 */
        "movl 0xffdb58(%edx), %ebx\n" /* alias */
        /* { scope 3: value */
        "movl (%ebx), %eax\n" /* line 2113 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "movl %ebx, (%esp)\n" /* line 2114 */
        "calll SND_GetAliasOffset\n"
        "movw %ax, -0x1a(%ebp)\n" /* value */
        /* { scope 4 */
        "leal -0x1a(%ebp), %esi\n" /* line 88 | value */
        "movl %esi, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteData\n"
        /* } scope */
        /* } scope */
        "movl -0x5c(%ebp), %eax\n" /* line 2376 */
        "movl 0xffdb5c(%eax), %ebx\n" /* alias */
        /* { scope 3: value */
        "movl (%ebx), %eax\n" /* line 2113 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl %edx, (%esp)\n"
        "calll MemFile_WriteCString\n"
        "movl %ebx, (%esp)\n" /* line 2114 */
        "calll SND_GetAliasOffset\n"
        "movw %ax, -0x1a(%ebp)\n" /* value */
        /* { scope 4 */
        "movl %esi, 8(%esp)\n" /* line 88 */
        "movl $2, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        /* } scope */
        /* } scope */
        "movl -0x5c(%ebp), %eax\n" /* line 2377 */
        "addl $0xffdb34, %eax\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "calll SND_SaveChanInfo\n"
        "leal -0x3c(%ebp), %edx\n" /* line 2379 | info */
        "movl %edx, 8(%esp)\n"
        "movl $0x20, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl %eax, (%esp)\n"
        "calll MemFile_WriteData\n"
        "movl 0xffebcc, %edx\n"
        "jmp .Lf4dcfe_0004de2e\n"
    );
}

/* line 2383 */
static __attribute__((naked))
Bool SND_RestoreStreamChannel(int channel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2383 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        "movl %eax, -0x9c(%ebp)\n"
        "movl %edx, %esi\n" /* memFile */
        /* { scope 1 */
        /* { scope 2: value */
        "movl %edx, (%esp)\n" /* line 2124 */
        "calll MemFile_ReadCString\n"
        "movl %eax, %ebx\n" /* name */
        "cmpb $0, (%eax)\n" /* line 2125 */
        "jne .Lf4e19e_0004e1ce\n"
        /* } scope */
        /* { scope 2: value */
        ".Lf4e19e_0004e1c1:\n"
        "xorl %eax, %eax\n" /* line 201 */
        /* } scope */
        /* } scope */
        ".Lf4e19e_0004e1c3:\n"
        "addl $0xdc, %esp\n" /* line 2431 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: value */
        /* { scope 3 */
        ".Lf4e19e_0004e1ce:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 131 | value */
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzwl -0x1a(%ebp), %eax\n" /* line 2128 | value */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* name */
        "calll SND_GetAliasWithOffset\n"
        "movl %eax, %edi\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 2392 */
        "je .Lf4e19e_0004e1c1\n"
        /* { scope 2: value */
        "movl %esi, (%esp)\n" /* line 2124 */
        "calll MemFile_ReadCString\n"
        "movl %eax, %ebx\n" /* name */
        "cmpb $0, (%eax)\n" /* line 2125 */
        "jne .Lf4e19e_0004e39e\n"
        "xorl %ebx, %ebx\n" /* name */
        /* } scope */
        ".Lf4e19e_0004e210:\n"
        "leal -0x8c(%ebp), %eax\n" /* line 2398 | chaninfo */
        "movl %esi, %edx\n" /* memFile */
        "calll SND_RestoreChanInfo\n"
        "leal -0x3c(%ebp), %eax\n" /* line 2399 | info */
        "movl %eax, 8(%esp)\n"
        "movl $0x20, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* memFile */
        "calll MemFile_ReadData\n"
        "movl 0x2c(%edi), %eax\n" /* line 2403 | pAlias0 */
        "andl $0x60, %eax\n"
        "sarl $5, %eax\n"
        "subl $2, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf4e19e_0004e255\n"
        /* { scope 2: value */
        ".Lf4e19e_0004e245:\n"
        "movl $1, %eax\n" /* line 201 */
        /* } scope */
        /* } scope */
        "addl $0xdc, %esp\n" /* line 2431 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4e19e_0004e255:\n"
        "movl 0x2c(%ebx), %eax\n" /* line 2403 | pAlias1 */
        "andl $0x60, %eax\n"
        "sarl $5, %eax\n"
        "subl $2, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf4e19e_0004e245\n"
        "xorl %ecx, %ecx\n" /* line 2405 */
        "movl %ebx, %edx\n" /* pAlias1 */
        "movl %edi, %eax\n" /* pAlias0 */
        "calll SND_ValidateSoundAliasBlend\n"
        "testb %al, %al\n"
        "je .Lf4e19e_0004e245\n"
        "movl -0x9c(%ebp), %edx\n" /* line 2407 */
        "testl %edx, %edx\n"
        "js .Lf4e19e_0004e3cc\n"
        "movl snd_enableStream, %eax\n" /* line 2414 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf4e19e_0004e245\n"
        "movl $1, 0x30(%esp)\n" /* line 2416 */
        "movl %edx, 0x2c(%esp)\n"
        "movzbl -0x43(%ebp), %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl -0x3c(%ebp), %eax\n" /* info */
        "movl %eax, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0x3f800000, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x28(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x8c(%ebp), %eax\n" /* chaninfo */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* pAlias1 */
        "movl %edi, (%esp)\n" /* pAlias0 */
        "calll SND_StartAliasStreamOnChannel\n"
        ".Lf4e19e_0004e2ee:\n"
        "movl -0x9c(%ebp), %eax\n" /* line 2419 */
        "testl %eax, %eax\n"
        "js .Lf4e19e_0004e245\n"
        "movl %eax, (%esp)\n"
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e19e_0004e245\n"
        "leal -0x3c(%ebp), %eax\n" /* line 2423 | info */
        "movl %eax, 4(%esp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_SetStreamChannelFromSaveInfo\n"
        "movl -0x9c(%ebp), %ebx\n" /* line 2424 | pAlias1 */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 428 */
        "shll $4, %eax\n"
        "cvtsi2ssl -0x38(%ebp), %xmm0\n"
        "mulss 0xffdb50(%eax), %xmm0\n"
        "mulss 0xffd810, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xa0(%ebp)\n"
        "cvttss2si -0xa0(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SND_SetStreamChannelPlaybackRate\n"
        "movl -0x9c(%ebp), %eax\n" /* line 2425 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl $0xffdb60, %eax\n"
        "leal 0x10(%eax), %ecx\n" /* to */
        /* { scope 2: value */
        "movl -0x50(%ebp), %edx\n" /* line 199 */
        "movl %edx, 0x10(%eax)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x48(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl $1, %eax\n"
        "jmp .Lf4e19e_0004e1c3\n"
        /* } scope */
        /* { scope 2: value */
        /* { scope 3 */
        ".Lf4e19e_0004e39e:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 131 | value */
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzwl -0x1a(%ebp), %eax\n" /* line 2128 | value */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* name */
        "calll SND_GetAliasWithOffset\n"
        "movl %eax, %ebx\n" /* name */
        "jmp .Lf4e19e_0004e210\n"
        /* } scope */
        ".Lf4e19e_0004e3cc:\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 2409 | chaninfo */
        "movl $1, 0x10(%esp)\n"
        "leal -0x9c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movss -0x3c(%ebp), %xmm3\n" /* info */
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movss -0x34(%ebp), %xmm1\n"
        "movss -0x60(%ebp), %xmm0\n"
        "movl %ebx, %edx\n" /* pAlias1 */
        "movl %edi, %eax\n" /* pAlias0 */
        "calll SND_StartAliasStream\n"
        "jmp .Lf4e19e_0004e2ee\n"
    );
}

/* line 2479 */
__attribute__((naked))
jpeg_component_info SND_Restore(MemoryFile *memFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2479 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 8(%ebp), %edi\n" /* memFile */
        /* { scope 1: pAlias1, chaninfo, info, channel, ... */
        "cmpb $0, g_snd\n" /* line 2483 */
        "jne .Lf4e420_0004e443\n"
        /* } scope */
        ".Lf4e420_0004e438:\n"
        "addl $0xcc, %esp\n" /* line 2540 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pAlias1, chaninfo, info, channel, ... */
        ".Lf4e420_0004e443:\n"
        "movl $1, %esi\n" /* line 2484 | pAlias0 */
        "movl $0xffd8bc, %ebx\n" /* i */
        ".Lf4e420_0004e44d:\n"
        "movl %ebx, 8(%esp)\n" /* line 2489 | i */
        "movl $0x88, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* memFile */
        "calll MemFile_ReadData\n"
        "addl $1, %esi\n" /* line 2487 | pAlias0 */
        "addl $0x88, %ebx\n" /* i */
        "cmpl $4, %esi\n" /* pAlias0 */
        "jne .Lf4e420_0004e44d\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $g_snd, %ecx\n"
        "movl $0xffd834, %edx\n"
        "movl 0xffda54, %eax\n"
        ".Lf4e420_0004e480:\n"
        "cmpb $0, 0xb8(%ecx)\n" /* line 2496 */
        "cmovnel %edx, %eax\n"
        "movl %eax, 0xffda54\n"
        "addl $1, %ebx\n" /* line 2493 | i */
        "addl $0x88, %edx\n"
        "addl $0x88, %ecx\n"
        "cmpl $4, %ebx\n" /* i */
        "jne .Lf4e420_0004e480\n"
        "movl $1, %esi\n" /* pAlias0 */
        "movl $0xffda98, %ebx\n" /* i */
        ".Lf4e420_0004e4ad:\n"
        "movl %ebx, 8(%esp)\n" /* line 2501 | i */
        "movl $0x20, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* memFile */
        "calll MemFile_ReadData\n"
        "addl $1, %esi\n" /* line 2499 | pAlias0 */
        "addl $0x20, %ebx\n" /* i */
        "cmpl $3, %esi\n" /* pAlias0 */
        "jne .Lf4e420_0004e4ad\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $g_snd, %ecx\n"
        "movl $0xffda78, %edx\n"
        "movl 0xffdad8, %eax\n"
        ".Lf4e420_0004e4dd:\n"
        "cmpb $0, 0x294(%ecx)\n" /* line 2508 */
        "cmovnel %edx, %eax\n"
        "movl %eax, 0xffdad8\n"
        "addl $1, %ebx\n" /* line 2505 | i */
        "addl $0x20, %edx\n"
        "addl $0x20, %ecx\n"
        "cmpl $3, %ebx\n" /* i */
        "jne .Lf4e420_0004e4dd\n"
        "movl (%eax), %eax\n" /* line 2511 */
        "movl %eax, (%esp)\n"
        "calll SND_SetRoomtype\n"
        "movl $0xffda58, 8(%esp)\n" /* line 2513 */
        "movl $8, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* memFile */
        "calll MemFile_ReadData\n"
        /* { scope 2 */
        /* { scope 3: value */
        ".Lf4e420_0004e51c:\n"
        "movl %edi, (%esp)\n" /* line 2124 */
        "calll MemFile_ReadCString\n"
        "movl %eax, %ebx\n" /* name */
        "cmpb $0, (%eax)\n" /* line 2125 */
        "jne .Lf4e420_0004e713\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: value */
        ".Lf4e420_0004e52f:\n"
        "movl %edi, (%esp)\n" /* line 2124 */
        "calll MemFile_ReadCString\n"
        "movl %eax, %ebx\n" /* name */
        "cmpb $0, (%eax)\n" /* line 2125 */
        "jne .Lf4e420_0004e58b\n"
        /* } scope */
        /* } scope */
        ".Lf4e420_0004e53e:\n"
        "movl $0xffffffff, %ebx\n" /* line 2524 | i */
        ".Lf4e420_0004e543:\n"
        "leal 0x21(%ebx), %eax\n" /* line 2532 | i */
        "movl %edi, %edx\n" /* memFile */
        "calll SND_RestoreStreamChannel\n"
        "addl $1, %ebx\n" /* i */
        "cmpl $2, %ebx\n" /* line 2528 | i */
        "je .Lf4e420_0004e562\n"
        ".Lf4e420_0004e555:\n"
        "cmpl $1, %ebx\n" /* line 2530 | i */
        "ja .Lf4e420_0004e543\n"
        "addl $1, %ebx\n" /* line 2532 | i */
        "cmpl $2, %ebx\n" /* line 2528 | i */
        "jne .Lf4e420_0004e555\n"
        ".Lf4e420_0004e562:\n"
        "movl %edi, %edx\n" /* line 2537 | memFile */
        "movl $0xffffffff, %eax\n"
        "calll SND_RestoreStreamChannel\n"
        "testb %al, %al\n"
        "je .Lf4e420_0004e438\n"
        "movl %edi, %edx\n" /* memFile */
        "movl $0xffffffff, %eax\n"
        "calll SND_RestoreStreamChannel\n"
        "testb %al, %al\n"
        "jne .Lf4e420_0004e562\n"
        "jmp .Lf4e420_0004e438\n"
        /* { scope 2 */
        /* { scope 3: value */
        /* { scope 4 */
        ".Lf4e420_0004e58b:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 131 | value */
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzwl -0x1a(%ebp), %eax\n" /* line 2128 | value */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* name */
        "calll SND_GetAliasWithOffset\n"
        "movl %eax, %esi\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 2308 */
        "je .Lf4e420_0004e53e\n"
        /* { scope 3: value */
        "movl %edi, (%esp)\n" /* line 2124 */
        "calll MemFile_ReadCString\n"
        "movl %eax, %ebx\n" /* name */
        "cmpb $0, (%eax)\n" /* line 2125 */
        "jne .Lf4e420_0004e8c6\n"
        "movl $0, -0x8c(%ebp)\n" /* pAlias1 */
        /* } scope */
        ".Lf4e420_0004e5d5:\n"
        "movl %edi, %edx\n" /* line 2314 */
        "leal -0x88(%ebp), %eax\n" /* chaninfo */
        "calll SND_RestoreChanInfo\n"
        "leal -0x38(%ebp), %eax\n" /* line 2315 | info */
        "movl %eax, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movl 0x2c(%esi), %eax\n" /* line 2319 | pAlias0 */
        "andl $0x60, %eax\n"
        "cmpl $0x20, %eax\n"
        "jne .Lf4e420_0004e52f\n"
        "movl -0x8c(%ebp), %edx\n" /* pAlias1 */
        "movl 0x2c(%edx), %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x20, %eax\n"
        "jne .Lf4e420_0004e52f\n"
        "movl %esi, (%esp)\n" /* pAlias0 */
        "calll Com_GetSoundFileMem\n"
        "testl %eax, %eax\n"
        "je .Lf4e420_0004e52f\n"
        "movl -0x8c(%ebp), %eax\n" /* pAlias1 */
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileMem\n"
        "movl %eax, %ebx\n" /* name */
        "movl %esi, (%esp)\n" /* pAlias0 */
        "calll Com_GetSoundFileMem\n"
        "cmpl %eax, %ebx\n" /* name */
        "jne .Lf4e420_0004e52f\n"
        "xorl %ecx, %ecx\n" /* line 2321 */
        "movl -0x8c(%ebp), %edx\n" /* pAlias1 */
        "movl %esi, %eax\n" /* pAlias0 */
        "calll SND_ValidateSoundAliasBlend\n"
        "testb %al, %al\n"
        "je .Lf4e420_0004e52f\n"
        "movl snd_enable2D, %eax\n" /* line 2323 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf4e420_0004e52f\n"
        "movl $1, 0x2c(%esp)\n" /* line 2326 */
        "leal -0x20(%ebp), %eax\n" /* channel */
        "movl %eax, 0x28(%esp)\n"
        "movzbl -0x3f(%ebp), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl -0x38(%ebp), %eax\n" /* info */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x88(%ebp), %eax\n" /* chaninfo */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x8c(%ebp), %edx\n" /* pAlias1 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pAlias0 */
        "calll SND_StartAlias2DSample\n"
        "movl -0x20(%ebp), %eax\n" /* line 2327 | channel */
        "testl %eax, %eax\n"
        "js .Lf4e420_0004e52f\n"
        "leal -0x38(%ebp), %edx\n" /* line 2330 | info */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SND_Set2DChannelFromSaveInfo\n"
        "movl -0x20(%ebp), %eax\n" /* line 2331 | channel */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl $0xffdb60, %eax\n"
        "leal 0x10(%eax), %ecx\n" /* to */
        /* { scope 3: value */
        "movl -0x4c(%ebp), %edx\n" /* line 199 */
        "movl %edx, 0x10(%eax)\n"
        "movl -0x48(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x44(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "jmp .Lf4e420_0004e52f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: value */
        /* { scope 4 */
        ".Lf4e420_0004e713:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 131 | value */
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzwl -0x1a(%ebp), %eax\n" /* line 2128 | value */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* name */
        "calll SND_GetAliasWithOffset\n"
        "movl %eax, %esi\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 2242 */
        "je .Lf4e420_0004e52f\n"
        /* { scope 3: value */
        "movl %edi, (%esp)\n" /* line 2124 */
        "calll MemFile_ReadCString\n"
        "movl %eax, %ebx\n" /* name */
        "cmpb $0, (%eax)\n" /* line 2125 */
        "jne .Lf4e420_0004e894\n"
        "movl $0, -0x90(%ebp)\n" /* pAlias1 */
        /* } scope */
        ".Lf4e420_0004e761:\n"
        "movl %edi, %edx\n" /* line 2248 */
        "leal -0x88(%ebp), %eax\n" /* chaninfo */
        "calll SND_RestoreChanInfo\n"
        "leal -0x38(%ebp), %eax\n" /* line 2249 | info */
        "movl %eax, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movl 0x2c(%esi), %eax\n" /* line 2252 | pAlias0 */
        "andl $0x60, %eax\n"
        "cmpl $0x20, %eax\n"
        "jne .Lf4e420_0004e51c\n"
        "movl -0x90(%ebp), %edx\n" /* pAlias1 */
        "movl 0x2c(%edx), %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x20, %eax\n"
        "jne .Lf4e420_0004e51c\n"
        "movl %esi, (%esp)\n" /* pAlias0 */
        "calll Com_GetSoundFileMem\n"
        "testl %eax, %eax\n"
        "je .Lf4e420_0004e51c\n"
        "movl -0x90(%ebp), %eax\n" /* pAlias1 */
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileMem\n"
        "movl %eax, %ebx\n" /* name */
        "movl %esi, (%esp)\n" /* pAlias0 */
        "calll Com_GetSoundFileMem\n"
        "cmpl %eax, %ebx\n" /* name */
        "jne .Lf4e420_0004e51c\n"
        "xorl %ecx, %ecx\n" /* line 2254 */
        "movl -0x90(%ebp), %edx\n" /* pAlias1 */
        "movl %esi, %eax\n" /* pAlias0 */
        "calll SND_ValidateSoundAliasBlend\n"
        "testb %al, %al\n"
        "je .Lf4e420_0004e51c\n"
        "movl snd_enable3D, %eax\n" /* line 2257 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf4e420_0004e51c\n"
        "movl $1, 0x30(%esp)\n" /* line 2260 */
        "leal -0x20(%ebp), %eax\n" /* channel */
        "movl %eax, 0x2c(%esp)\n"
        "movzbl -0x3f(%ebp), %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl -0x38(%ebp), %eax\n" /* info */
        "movl %eax, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x88(%ebp), %eax\n" /* chaninfo */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x90(%ebp), %edx\n" /* pAlias1 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pAlias0 */
        "calll SND_StartAlias3DSample\n"
        "movl -0x20(%ebp), %eax\n" /* line 2261 | channel */
        "testl %eax, %eax\n"
        "js .Lf4e420_0004e51c\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 2264 */
        "shll $4, %eax\n"
        "addl $0xffdb60, %eax\n"
        "leal 0x10(%eax), %ecx\n" /* to */
        /* { scope 3: value */
        "movl -0x4c(%ebp), %edx\n" /* line 199 */
        "movl %edx, 0x10(%eax)\n"
        "movl -0x48(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x44(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "jmp .Lf4e420_0004e51c\n"
        /* } scope */
        /* { scope 3: value */
        /* { scope 4 */
        ".Lf4e420_0004e894:\n"
        "leal -0x1a(%ebp), %edx\n" /* line 131 | value */
        "movl %edx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzwl -0x1a(%ebp), %eax\n" /* line 2128 | value */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* name */
        "calll SND_GetAliasWithOffset\n"
        "movl %eax, -0x90(%ebp)\n" /* pAlias1 */
        "jmp .Lf4e420_0004e761\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: value */
        /* { scope 4 */
        ".Lf4e420_0004e8c6:\n"
        "leal -0x1a(%ebp), %edx\n" /* line 131 | value */
        "movl %edx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzwl -0x1a(%ebp), %eax\n" /* line 2128 | value */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* name */
        "calll SND_GetAliasWithOffset\n"
        "movl %eax, -0x8c(%ebp)\n" /* pAlias1 */
        "jmp .Lf4e420_0004e5d5\n"
    );
}

/* line 1873 */
__attribute__((naked))
jpeg_component_info SND_Update(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1873 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_snd\n" /* line 1878 */
        "jne .Lf4e8f8_0004e912\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1917 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4e8f8_0004e912:\n"
        "calll SND_GetDriverCPUPercentage\n" /* line 1883 */
        "movl %eax, %edx\n"
        "movl %eax, 0xffd818\n"
        "movl 0x195ed14, %eax\n" /* line 1885 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf4e8f8_0004e934\n"
        "cmpl $2, %edx\n"
        "jg .Lf4e8f8_0004ee12\n"
        ".Lf4e8f8_0004e934:\n"
        "calll Sys_Milliseconds\n" /* line 1889 */
        "movl %eax, %edi\n" /* frametime */
        "subl 0xffdb2c, %edi\n" /* frametime */
        "movl %eax, 0xffdb2c\n" /* line 1890 */
        "movl %edi, (%esp)\n" /* line 1892 | frametime */
        "calll SND_DriverPreUpdate\n"
        "movl 0x195ed18, %eax\n" /* line 1177 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "cmpb 0xffd802, %al\n" /* line 1178 */
        "je .Lf4e8f8_0004e972\n"
        "testb %al, %al\n" /* line 1180 */
        "jne .Lf4e8f8_0004ed54\n"
        "calll SND_UnpauseSounds\n" /* line 1183 */
        ".Lf4e8f8_0004e972:\n"
        "cvtsi2ssl %edi, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "xorl %ecx, %ecx\n"
        "pxor %xmm3, %xmm3\n"
        "xorl %edx, %edx\n"
        "jmp .Lf4e8f8_0004e9aa\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf4e8f8_0004e985:\n"
        "movss 4(%eax), %xmm1\n" /* line 1522 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf4e8f8_0004e99a\n"
        ".Lf4e8f8_0004e98f:\n"
        "movss %xmm1, (%eax)\n" /* line 1524 */
        "movl $0, 8(%eax)\n" /* line 1525 */
        /* } scope */
        ".Lf4e8f8_0004e99a:\n"
        "addl $1, %ecx\n" /* line 1535 */
        "addl $0xc, %edx\n"
        "cmpl $0xb, %ecx\n"
        "je .Lf4e8f8_0004e9da\n"
        ".Lf4e8f8_0004e9a5:\n"
        "movss -0x3c(%ebp), %xmm0\n"
        ".Lf4e8f8_0004e9aa:\n"
        "movl %edx, %eax\n" /* line 1536 | volinfo */
        "addl 0xffda54, %eax\n" /* volinfo */
        /* { scope 3 */
        "mulss 8(%eax), %xmm0\n" /* line 1511 */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "ucomiss 8(%eax), %xmm3\n" /* line 1512 */
        "jbe .Lf4e8f8_0004e985\n"
        "movss 4(%eax), %xmm1\n" /* line 1514 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf4e8f8_0004e98f\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 1535 */
        "addl $0xc, %edx\n"
        "cmpl $0xb, %ecx\n"
        "jne .Lf4e8f8_0004e9a5\n"
        ".Lf4e8f8_0004e9da:\n"
        "movss 0xffd830, %xmm0\n" /* line 1538 */
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf4e8f8_0004eb9e\n"
        "jp .Lf4e8f8_0004eb9e\n"
        "movl snd_volume, %eax\n" /* line 1540 */
        "cmpb $0, 7(%eax)\n"
        "jne .Lf4e8f8_0004ebfc\n"
        /* } scope */
        ".Lf4e8f8_0004ea00:\n"
        "cmpb $0, 0xffd802\n" /* line 1898 */
        "jne .Lf4e8f8_0004eb04\n"
        "movl 0xffd81c, %eax\n" /* line 1900 */
        "testl %eax, %eax\n"
        "je .Lf4e8f8_0004ea57\n"
        "movl %eax, 8(%esp)\n" /* line 1902 */
        "movl 0xffd820, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2c(%ebp), %ebx\n" /* memFile, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll MemFile_InitForReading\n"
        "movl %ebx, (%esp)\n" /* line 1903 | i */
        "calll SND_Restore\n"
        "movl 0xffd81c, %eax\n" /* line 1904 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $0, 0xffd81c\n" /* line 1905 */
        "movl $0, 0xffd820\n" /* line 1906 */
        ".Lf4e8f8_0004ea57:\n"
        "calll Com_GetTimescaleForSnd\n" /* line 1837 */
        "fstps -0x5c(%ebp)\n"
        "movss -0x5c(%ebp), %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 1838 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm1, %xmm2\n"
        "cmpnless %xmm3, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movss 0xffd810, %xmm0\n" /* line 1840 */
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lf4e8f8_0004ea90\n"
        "je .Lf4e8f8_0004ead7\n"
        ".Lf4e8f8_0004ea90:\n"
        "movaps %xmm1, %xmm4\n" /* line 1844 */
        "divss %xmm0, %xmm4\n"
        "movss %xmm4, -0x40(%ebp)\n"
        "movss %xmm1, 0xffd810\n" /* line 1845 */
        "movl 0xffebc8, %eax\n" /* line 1847 */
        "testl %eax, %eax\n"
        "jg .Lf4e8f8_0004f07b\n"
        ".Lf4e8f8_0004eab1:\n"
        "movl 0xffebcc, %eax\n" /* line 1855 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jg .Lf4e8f8_0004f01c\n"
        ".Lf4e8f8_0004eac2:\n"
        "movl 0xffebc4, %eax\n" /* line 1863 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4e8f8_0004ef52\n"
        ".Lf4e8f8_0004ead3:\n"
        "pxor %xmm3, %xmm3\n"
        ".Lf4e8f8_0004ead7:\n"
        "movl 0xffdad8, %eax\n" /* line 1779 */
        "movss 0xc(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf4e8f8_0004ed9a\n"
        "jp .Lf4e8f8_0004ed9a\n"
        "movss 0x18(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf4e8f8_0004edd7\n"
        "jp .Lf4e8f8_0004edd7\n"
        ".Lf4e8f8_0004eb04:\n"
        "xorl %ebx, %ebx\n" /* line 1824 | i */
        "movl $g_snd, %esi\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf4e8f8_0004eb0b:\n"
        "cmpl %ebx, 0xffebc8\n" /* line 1585 */
        "jle .Lf4e8f8_0004ec72\n"
        /* { scope 4 */
        ".Lf4e8f8_0004eb17:\n"
        "movl %ebx, (%esp)\n" /* line 1567 */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4e8f8_0004ec2b\n"
        ".Lf4e8f8_0004eb27:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1587 */
        "jne .Lf4e8f8_0004ec46\n"
        ".Lf4e8f8_0004eb31:\n"
        "xorl %edx, %edx\n"
        "addl $1, %ebx\n" /* line 1585 */
        "addl $0x50, %esi\n"
        "testb %dl, %dl\n"
        "je .Lf4e8f8_0004eb0b\n"
        ".Lf4e8f8_0004eb3d:\n"
        "movl snd_slaveFadeTime, %eax\n" /* line 1603 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf4e8f8_0004eca6\n"
        ".Lf4e8f8_0004eb4d:\n"
        "movl $0x3f800000, %eax\n" /* line 1605 */
        "testb %dl, %dl\n"
        "je .Lf4e8f8_0004ed5e\n"
        "movl %eax, 0xffda74\n"
        /* } scope */
        "movl 0xffebc8, %eax\n" /* line 1636 */
        "testl %eax, %eax\n"
        "jg .Lf4e8f8_0004ed27\n"
        ".Lf4e8f8_0004eb6c:\n"
        "movl 0xffebcc, %eax\n" /* line 1643 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jg .Lf4e8f8_0004ee67\n"
        ".Lf4e8f8_0004eb7d:\n"
        "movl 0xffebc4, %eax\n" /* line 1650 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4e8f8_0004ee33\n"
        /* } scope */
        ".Lf4e8f8_0004eb8e:\n"
        "movl %edi, (%esp)\n" /* line 1914 | frametime */
        "calll SND_DriverPostUpdate\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1917 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf4e8f8_0004eb9e:\n"
        "mulss -0x3c(%ebp), %xmm0\n" /* line 1511 */
        "addss 0xffd828, %xmm0\n"
        "movss %xmm0, 0xffd828\n"
        "ucomiss 0xffd830, %xmm3\n" /* line 1512 */
        "ja .Lf4e8f8_0004ee9b\n"
        "movss 0xffd82c, %xmm1\n" /* line 1522 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf4e8f8_0004ebdf\n"
        ".Lf4e8f8_0004ebcd:\n"
        "movss %xmm1, 0xffd828\n" /* line 1524 */
        "movl $0, 0xffd830\n" /* line 1525 */
        ".Lf4e8f8_0004ebdf:\n"
        "ucomiss 0xffd828, %xmm3\n" /* line 1546 */
        "jne .Lf4e8f8_0004ebf7\n"
        "jp .Lf4e8f8_0004ebf7\n"
        "ucomiss 0xffd830, %xmm3\n"
        "je .Lf4e8f8_0004f0d3\n"
        ".Lf4e8f8_0004ebf7:\n"
        "movl snd_volume, %eax\n"
        ".Lf4e8f8_0004ebfc:\n"
        "movl %eax, (%esp)\n" /* line 1550 */
        "calll Dvar_ClearModified\n"
        "movss 0xffd828, %xmm0\n" /* line 1551 */
        "movl snd_volume, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "mulss 0x2ed67c, %xmm0\n" /* 0.75f */
        "movss %xmm0, 0xffd824\n"
        "jmp .Lf4e8f8_0004ea00\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf4e8f8_0004ec2b:\n"
        "movl 0x33c(%esi), %eax\n" /* line 1567 */
        "testl %eax, %eax\n"
        "jne .Lf4e8f8_0004eb27\n"
        "movl $1, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1587 */
        "je .Lf4e8f8_0004eb31\n"
        ".Lf4e8f8_0004ec46:\n"
        "cmpb $0, 0x37d(%esi)\n"
        "je .Lf4e8f8_0004eb31\n"
        "movl $1, %edx\n"
        "addl $1, %ebx\n" /* line 1585 */
        "addl $0x50, %esi\n"
        "testb %dl, %dl\n"
        "jne .Lf4e8f8_0004eb3d\n"
        "cmpl %ebx, 0xffebc8\n"
        "jg .Lf4e8f8_0004eb17\n"
        ".Lf4e8f8_0004ec72:\n"
        "movl 0xffebcc, %eax\n" /* line 1591 */
        "addl $0x20, %eax\n"
        "cmpl $0x20, %eax\n"
        "jg .Lf4e8f8_0004efb1\n"
        ".Lf4e8f8_0004ec83:\n"
        "movl 0xffebc4, %eax\n" /* line 1597 */
        "addl $0x2d, %eax\n"
        "cmpl $0x2d, %eax\n"
        "jg .Lf4e8f8_0004eee7\n"
        ".Lf4e8f8_0004ec94:\n"
        "xorl %edx, %edx\n"
        "movl snd_slaveFadeTime, %eax\n" /* line 1603 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf4e8f8_0004eb4d\n"
        ".Lf4e8f8_0004eca6:\n"
        "testb %dl, %dl\n" /* line 1610 */
        "je .Lf4e8f8_0004ed74\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1611 */
        "movss -0x3c(%ebp), %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "addss 0xffda74, %xmm1\n"
        "movss %xmm1, 0xffda74\n"
        "movaps %xmm1, %xmm0\n"
        ".Lf4e8f8_0004ecd3:\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 45 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm3, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss %xmm0, 0xffda74\n" /* line 1615 */
        /* } scope */
        "movl 0xffebc8, %eax\n" /* line 1636 */
        "testl %eax, %eax\n"
        "jle .Lf4e8f8_0004eb6c\n"
        ".Lf4e8f8_0004ed27:\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf4e8f8_0004ed3a\n"
        ".Lf4e8f8_0004ed2b:\n"
        "addl $1, %ebx\n" /* i */
        "cmpl 0xffebc8, %ebx\n" /* i */
        "jge .Lf4e8f8_0004eb6c\n"
        ".Lf4e8f8_0004ed3a:\n"
        "movl %ebx, (%esp)\n" /* line 1638 | i */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e8f8_0004ed2b\n"
        "movl %edi, 4(%esp)\n" /* line 1640 */
        "movl %ebx, (%esp)\n" /* i */
        "calll SND_Update3DChannel\n"
        "jmp .Lf4e8f8_0004ed2b\n"
        /* } scope */
        ".Lf4e8f8_0004ed54:\n"
        "calll SND_PauseSounds\n" /* line 1181 */
        "jmp .Lf4e8f8_0004e972\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf4e8f8_0004ed5e:\n"
        "xorl %eax, %eax\n" /* line 1605 */
        "movl %eax, 0xffda74\n"
        /* } scope */
        "movl 0xffebc8, %eax\n" /* line 1636 */
        "testl %eax, %eax\n"
        "jle .Lf4e8f8_0004eb6c\n"
        "jmp .Lf4e8f8_0004ed27\n"
        /* { scope 3 */
        ".Lf4e8f8_0004ed74:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1613 */
        "movss -0x3c(%ebp), %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movss 0xffda74, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 0xffda74\n"
        "jmp .Lf4e8f8_0004ecd3\n"
        /* } scope */
        /* } scope */
        ".Lf4e8f8_0004ed9a:\n"
        "mulss -0x3c(%ebp), %xmm0\n" /* line 1783 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movl 0xffdad8, %eax\n" /* line 1784 */
        "ucomiss 0xc(%eax), %xmm3\n"
        "ja .Lf4e8f8_0004f0ef\n"
        "movss 8(%eax), %xmm1\n" /* line 1794 */
        "movss 4(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf4e8f8_0004eeb1\n"
        ".Lf4e8f8_0004edcb:\n"
        "movss 0x18(%eax), %xmm0\n" /* line 1802 */
        "ucomiss %xmm3, %xmm0\n"
        "jp .Lf4e8f8_0004edd7\n"
        "je .Lf4e8f8_0004ee08\n"
        ".Lf4e8f8_0004edd7:\n"
        "mulss -0x3c(%ebp), %xmm0\n" /* line 1804 */
        "addss 0x10(%eax), %xmm0\n"
        "movss %xmm0, 0x10(%eax)\n"
        "movl 0xffdad8, %eax\n" /* line 1805 */
        "ucomiss 0x18(%eax), %xmm3\n"
        "ja .Lf4e8f8_0004f119\n"
        "movss 0x14(%eax), %xmm1\n" /* line 1815 */
        "movss 0x10(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf4e8f8_0004eecc\n"
        ".Lf4e8f8_0004ee08:\n"
        "calll SND_UpdateReverbs\n" /* line 1824 */
        "jmp .Lf4e8f8_0004eb04\n"
        ".Lf4e8f8_0004ee12:\n"
        "movl $0x218df0, 8(%esp)\n" /* line 1886 */
        "movl $0xbb8, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll StatMon_Warning\n"
        "jmp .Lf4e8f8_0004e934\n"
        /* { scope 2 */
        ".Lf4e8f8_0004ee33:\n"
        "movl $0x2d, %ebx\n" /* line 1650 | i */
        "jmp .Lf4e8f8_0004ee4d\n"
        ".Lf4e8f8_0004ee3a:\n"
        "addl $1, %ebx\n" /* i */
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl %ebx, %eax\n" /* i */
        "jle .Lf4e8f8_0004eb8e\n"
        ".Lf4e8f8_0004ee4d:\n"
        "movl %ebx, (%esp)\n" /* line 1652 | i */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e8f8_0004ee3a\n"
        "movl %edi, 4(%esp)\n" /* line 1654 */
        "movl %ebx, (%esp)\n" /* i */
        "calll SND_Update2DChannel\n"
        "jmp .Lf4e8f8_0004ee3a\n"
        ".Lf4e8f8_0004ee67:\n"
        "movl $0x20, %ebx\n" /* line 1643 | i */
        "jmp .Lf4e8f8_0004ee81\n"
        ".Lf4e8f8_0004ee6e:\n"
        "addl $1, %ebx\n" /* i */
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4e8f8_0004eb7d\n"
        ".Lf4e8f8_0004ee81:\n"
        "movl %ebx, (%esp)\n" /* line 1645 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e8f8_0004ee6e\n"
        "movl %edi, 4(%esp)\n" /* line 1647 */
        "movl %ebx, (%esp)\n" /* i */
        "calll SND_UpdateStreamChannel\n"
        "jmp .Lf4e8f8_0004ee6e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf4e8f8_0004ee9b:\n"
        "movss 0xffd82c, %xmm1\n" /* line 1514 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf4e8f8_0004ebdf\n"
        "jmp .Lf4e8f8_0004ebcd\n"
        /* } scope */
        ".Lf4e8f8_0004eeb1:\n"
        "movss %xmm1, 4(%eax)\n" /* line 1796 */
        "movl 0xffdad8, %eax\n" /* line 1797 */
        "movl $0, 0xc(%eax)\n"
        "movl 0xffdad8, %eax\n"
        "jmp .Lf4e8f8_0004edcb\n"
        ".Lf4e8f8_0004eecc:\n"
        "movss %xmm1, 0x10(%eax)\n" /* line 1817 */
        "movl 0xffdad8, %eax\n" /* line 1818 */
        "movl $0, 0x18(%eax)\n"
        "calll SND_UpdateReverbs\n" /* line 1824 */
        "jmp .Lf4e8f8_0004eb04\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf4e8f8_0004eee7:\n"
        "movl $0x2d, %ebx\n" /* line 1597 | index */
        "movl $g_snd, %esi\n"
        /* { scope 4 */
        "movl %ebx, (%esp)\n" /* line 1559 */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4e8f8_0004ef2f\n"
        ".Lf4e8f8_0004eefd:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1599 */
        "jne .Lf4e8f8_0004ef42\n"
        ".Lf4e8f8_0004ef03:\n"
        "xorl %edx, %edx\n"
        ".Lf4e8f8_0004ef05:\n"
        "addl $1, %ebx\n" /* line 1597 | index */
        "testb %dl, %dl\n"
        "jne .Lf4e8f8_0004eb3d\n"
        "addl $0x50, %esi\n"
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl %eax, %ebx\n" /* index */
        "jge .Lf4e8f8_0004ec94\n"
        /* { scope 4 */
        "movl %ebx, (%esp)\n" /* line 1559 */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e8f8_0004eefd\n"
        ".Lf4e8f8_0004ef2f:\n"
        "movl 0x114c(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf4e8f8_0004eefd\n"
        "movl $1, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1599 */
        "je .Lf4e8f8_0004ef03\n"
        ".Lf4e8f8_0004ef42:\n"
        "cmpb $0, 0x118d(%esi)\n"
        "je .Lf4e8f8_0004ef03\n"
        "movl $1, %edx\n"
        "jmp .Lf4e8f8_0004ef05\n"
        /* } scope */
        /* } scope */
        ".Lf4e8f8_0004ef52:\n"
        "movl $0x2d, %ebx\n" /* line 1863 | i */
        "jmp .Lf4e8f8_0004ef6c\n"
        ".Lf4e8f8_0004ef59:\n"
        "addl $1, %ebx\n" /* i */
        "movl 0xffebc4, %eax\n"
        "addl $0x2d, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4e8f8_0004ead3\n"
        ".Lf4e8f8_0004ef6c:\n"
        "movl %ebx, (%esp)\n" /* line 1865 | i */
        "calll SND_Is2DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e8f8_0004ef59\n"
        "movl %ebx, (%esp)\n" /* line 1867 | i */
        "calll SND_Get2DChannelPlaybackRate\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "mulss -0x40(%ebp), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x4c(%ebp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SND_Set2DChannelPlaybackRate\n"
        "jmp .Lf4e8f8_0004ef59\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf4e8f8_0004efb1:\n"
        "movl $0x20, %ebx\n" /* line 1591 | index */
        "movl $g_snd, %esi\n"
        /* { scope 4 */
        "movl %ebx, (%esp)\n" /* line 1575 */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "je .Lf4e8f8_0004eff9\n"
        ".Lf4e8f8_0004efc7:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1593 */
        "jne .Lf4e8f8_0004f00c\n"
        ".Lf4e8f8_0004efcd:\n"
        "xorl %edx, %edx\n"
        ".Lf4e8f8_0004efcf:\n"
        "addl $1, %ebx\n" /* line 1591 | index */
        "testb %dl, %dl\n"
        "jne .Lf4e8f8_0004eb3d\n"
        "addl $0x50, %esi\n"
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %eax, %ebx\n" /* index */
        "jge .Lf4e8f8_0004ec83\n"
        /* { scope 4 */
        "movl %ebx, (%esp)\n" /* line 1575 */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e8f8_0004efc7\n"
        ".Lf4e8f8_0004eff9:\n"
        "movl 0xd3c(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf4e8f8_0004efc7\n"
        "movl $1, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1593 */
        "je .Lf4e8f8_0004efcd\n"
        ".Lf4e8f8_0004f00c:\n"
        "cmpb $0, 0xd7d(%esi)\n"
        "je .Lf4e8f8_0004efcd\n"
        "movl $1, %edx\n"
        "jmp .Lf4e8f8_0004efcf\n"
        /* } scope */
        /* } scope */
        ".Lf4e8f8_0004f01c:\n"
        "movl $0x20, %ebx\n" /* line 1855 | i */
        "jmp .Lf4e8f8_0004f036\n"
        ".Lf4e8f8_0004f023:\n"
        "addl $1, %ebx\n" /* i */
        "movl 0xffebcc, %eax\n"
        "addl $0x20, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jge .Lf4e8f8_0004eac2\n"
        ".Lf4e8f8_0004f036:\n"
        "movl %ebx, (%esp)\n" /* line 1857 | i */
        "calll SND_IsStreamChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e8f8_0004f023\n"
        "movl %ebx, (%esp)\n" /* line 1859 | i */
        "calll SND_GetStreamChannelPlaybackRate\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "mulss -0x40(%ebp), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x48(%ebp)\n"
        "cvttss2si -0x48(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SND_SetStreamChannelPlaybackRate\n"
        "jmp .Lf4e8f8_0004f023\n"
        ".Lf4e8f8_0004f07b:\n"
        "xorl %ebx, %ebx\n" /* line 1847 | i */
        "jmp .Lf4e8f8_0004f08e\n"
        ".Lf4e8f8_0004f07f:\n"
        "addl $1, %ebx\n" /* i */
        "cmpl 0xffebc8, %ebx\n" /* i */
        "jge .Lf4e8f8_0004eab1\n"
        ".Lf4e8f8_0004f08e:\n"
        "movl %ebx, (%esp)\n" /* line 1849 | i */
        "calll SND_Is3DChannelFree\n"
        "testb %al, %al\n"
        "jne .Lf4e8f8_0004f07f\n"
        "movl %ebx, (%esp)\n" /* line 1851 | i */
        "calll SND_Get3DChannelPlaybackRate\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "mulss -0x40(%ebp), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x44(%ebp)\n"
        "cvttss2si -0x44(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SND_Set3DChannelPlaybackRate\n"
        "jmp .Lf4e8f8_0004f07f\n"
        /* { scope 2 */
        ".Lf4e8f8_0004f0d3:\n"
        "jp .Lf4e8f8_0004ebf7\n" /* line 1546 */
        "movl $0, (%esp)\n" /* line 1547 */
        "calll SND_StopSounds\n"
        "movl snd_volume, %eax\n"
        "jmp .Lf4e8f8_0004ebfc\n"
        /* } scope */
        ".Lf4e8f8_0004f0ef:\n"
        "movss 8(%eax), %xmm0\n" /* line 1786 */
        "ucomiss 4(%eax), %xmm0\n"
        "jb .Lf4e8f8_0004edcb\n"
        "movss %xmm0, 4(%eax)\n" /* line 1788 */
        "movl 0xffdad8, %eax\n" /* line 1789 */
        "movl $0, 0xc(%eax)\n"
        "movl 0xffdad8, %eax\n"
        "jmp .Lf4e8f8_0004edcb\n"
        ".Lf4e8f8_0004f119:\n"
        "movss 0x14(%eax), %xmm0\n" /* line 1807 */
        "ucomiss 0x10(%eax), %xmm0\n"
        "jb .Lf4e8f8_0004ee08\n"
        "movss %xmm0, 0x10(%eax)\n" /* line 1809 */
        "movl 0xffdad8, %eax\n" /* line 1810 */
        "movl $0, 0x18(%eax)\n"
        "calll SND_UpdateReverbs\n" /* line 1824 */
        "jmp .Lf4e8f8_0004eb04\n"
    );
}

