/* ASM dump from: snd_driver.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/snd_driver.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern void FS_FCloseFile(int f);
extern int FS_FOpenFileReadStream(const char *filename, long unsigned int *handle, int uniqueFILE);
extern int AIL_digital_CPU_percent(void *dig);
extern int AIL_sample_playback_rate(void *S);
extern void AIL_set_sample_playback_rate(void *S, int rate);
extern int AIL_3D_sample_playback_rate(void *S);
extern void AIL_set_3D_sample_playback_rate(void *S, int rate);
extern int AIL_stream_playback_rate(void *stream);
extern void AIL_set_stream_playback_rate(void *stream, int rate);
extern float AIL_3D_sample_volume(void *S);
extern int AIL_3D_sample_length(void *S);

extern const dvar_t *mss_3d_provider; /* 0x0 */
extern const dvar_t *mss_q3fs; /* 0x0 */
static struct MssLocal milesGlob; /* 0x4a3b80 */

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
static __attribute__((naked))
long int MSS_FileSeekCallback(long unsigned int hFileHandle, long int offset, long unsigned int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* hFileHandle */
        "movl 0xc(%ebp), %edx\n" /* offset */
        "movl 0x10(%ebp), %eax\n" /* type */
        /* { scope 1 */
        "cmpl $1, %eax\n" /* line 135 */
        "je .Lf561de_00056224\n"
        "jae .Lf561de_00056217\n"
        "movl $2, %eax\n"
        "movl %eax, 8(%esp)\n" /* line 152 */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* hFileHandle */
        "calll FS_Seek\n"
        "movl %ebx, 8(%ebp)\n" /* line 153 | hFileHandle */
        /* } scope */
        "addl $0x14, %esp\n" /* line 154 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp FS_FTell\n" /* line 153 */
        ".Lf561de_00056217:\n"
        "cmpl $2, %eax\n" /* line 135 */
        "je .Lf561de_00056243\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 154 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf561de_00056224:\n"
        "xorl %eax, %eax\n" /* line 135 */
        "movl %eax, 8(%esp)\n" /* line 152 */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* hFileHandle */
        "calll FS_Seek\n"
        "movl %ebx, 8(%ebp)\n" /* line 153 | hFileHandle */
        /* } scope */
        "addl $0x14, %esp\n" /* line 154 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp FS_FTell\n" /* line 153 */
        ".Lf561de_00056243:\n"
        "movl $1, %eax\n" /* line 135 */
        "movl %eax, 8(%esp)\n" /* line 152 */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* hFileHandle */
        "calll FS_Seek\n"
        "movl %ebx, 8(%ebp)\n" /* line 153 | hFileHandle */
        /* } scope */
        "addl $0x14, %esp\n" /* line 154 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp FS_FTell\n" /* line 153 */
    );
}

/* line 157 */
static __attribute__((naked))
long unsigned int MSS_FileReadCallback(long unsigned int hFileHandle, void *pBuffer, long unsigned int bytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 157 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %ecx\n" /* pBuffer */
        "movl 0x10(%ebp), %edx\n" /* bytes */
        "movl 8(%ebp), %eax\n" /* line 159 | hFileHandle */
        "movl %eax, 0x10(%ebp)\n" /* bytes */
        "movl %edx, 0xc(%ebp)\n" /* pBuffer */
        "movl %ecx, 8(%ebp)\n" /* hFileHandle */
        "popl %ebp\n" /* line 160 */
        "jmp FS_Read\n" /* line 159 */
    );
}

/* line 469 */
__attribute__((naked))
void SND_ShutdownDriver(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 469 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x4a3b84, %eax\n" /* line 471 */
        "movl %eax, (%esp)\n"
        "calll AIL_close_3D_provider\n"
        "calll AIL_shutdown\n" /* line 473 */
        "movl $0x130, 8(%esp)\n" /* line 407 */
        "movl $0, 4(%esp)\n"
        "movl $milesGlob, (%esp)\n"
        "calll memset\n"
        "leave\n" /* line 476 */
        "retl\n"
    );
}

/* line 479 */
int SND_GetDriverCPUPercentage(void)
{
    return AIL_digital_CPU_percent(*(void **)&milesGlob);
}

/* line 549 */
__attribute__((naked))
void SND_Stop2DChannel(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 549 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0x4a3ad4(, %ebx, 4), %eax\n" /* line 552 */
        "movl %eax, (%esp)\n"
        "calll AIL_end_sample\n"
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 553 | index */
        "shll $4, %ebx\n" /* index */
        "addl 0x195ed34, %ebx\n" /* index */
        "movb $0, 0x37c(%ebx)\n" /* index */
        "movl $0, 0x33c(%ebx)\n" /* line 554 | index */
        "addl $0x14, %esp\n" /* line 555 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 558 */
__attribute__((naked))
void SND_Pause2DChannel(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 558 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0x4a3ad4(, %ebx, 4), %eax\n" /* line 561 */
        "movl %eax, (%esp)\n"
        "calll AIL_stop_sample\n"
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 562 | index */
        "shll $4, %ebx\n" /* index */
        "addl 0x195ed34, %ebx\n" /* index */
        "movb $1, 0x37c(%ebx)\n" /* index */
        "addl $0x14, %esp\n" /* line 563 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 566 */
__attribute__((naked))
void SND_Unpause2DChannel(int index, int timeshift)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 566 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* index, timeshift */
        "leal (%eax, %eax, 4), %ebx\n" /* line 569 */
        "shll $4, %ebx\n"
        "addl 0x195ed34, %ebx\n"
        "movl 0x33c(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf5633c_0005636b\n"
        "movl 0x4a3ad4(, %eax, 4), %eax\n" /* line 570 */
        "movl %eax, (%esp)\n"
        "calll AIL_resume_sample\n"
        ".Lf5633c_0005636b:\n"
        "movl 0xc(%ebp), %eax\n" /* line 571 | timeshift */
        "addl %eax, 0x344(%ebx)\n"
        "movb $0, 0x37c(%ebx)\n" /* line 572 */
        "addl $0x14, %esp\n" /* line 573 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 576 */
__attribute__((naked))
Bool SND_Is2DChannelFree(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 576 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* index */
        "leal (%edx, %edx, 4), %eax\n" /* line 579 */
        "shll $4, %eax\n"
        "addl 0x195ed34, %eax\n"
        "cmpb $0, 0x37c(%eax)\n"
        "jne .Lf56382_000563d0\n"
        "movl 0x33c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf56382_000563d0\n"
        "addl $0x350, %eax\n" /* line 581 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf56382_000563d4\n"
        ".Lf56382_000563b6:\n"
        "movl 0x4a3ad4(, %edx, 4), %eax\n" /* line 582 */
        "movl %eax, (%esp)\n"
        "calll AIL_sample_status\n"
        "cmpl $2, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 583 */
        "retl\n"
        ".Lf56382_000563d0:\n"
        "xorl %eax, %eax\n" /* line 582 */
        "leave\n" /* line 583 */
        "retl\n"
        ".Lf56382_000563d4:\n"
        "movl 0xc(%eax), %ecx\n" /* line 581 */
        "testl %ecx, %ecx\n"
        "jne .Lf56382_000563b6\n"
        "movl $1, %eax\n"
        "leave\n" /* line 583 */
        "retl\n"
    );
}

/* line 586 */
__attribute__((naked))
void SND_Stop3DChannel(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 586 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0x4a3ba8(, %ebx, 4), %eax\n" /* line 589 */
        "movl %eax, (%esp)\n"
        "calll AIL_end_3D_sample\n"
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 590 | index */
        "shll $4, %ebx\n" /* index */
        "addl 0x195ed34, %ebx\n" /* index */
        "movb $0, 0x37c(%ebx)\n" /* index */
        "movl $0, 0x33c(%ebx)\n" /* line 591 | index */
        "addl $0x14, %esp\n" /* line 592 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 595 */
__attribute__((naked))
void SND_Pause3DChannel(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 595 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0x4a3ba8(, %ebx, 4), %eax\n" /* line 598 */
        "movl %eax, (%esp)\n"
        "calll AIL_stop_3D_sample\n"
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 599 | index */
        "shll $4, %ebx\n" /* index */
        "addl 0x195ed34, %ebx\n" /* index */
        "movb $1, 0x37c(%ebx)\n" /* index */
        "addl $0x14, %esp\n" /* line 600 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 603 */
__attribute__((naked))
void SND_Unpause3DChannel(int index, int timeshift)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 603 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* index, timeshift */
        "leal (%eax, %eax, 4), %ebx\n" /* line 606 */
        "shll $4, %ebx\n"
        "addl 0x195ed34, %ebx\n"
        "movl 0x33c(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf56450_0005647f\n"
        "movl 0x4a3ba8(, %eax, 4), %eax\n" /* line 607 */
        "movl %eax, (%esp)\n"
        "calll AIL_resume_3D_sample\n"
        ".Lf56450_0005647f:\n"
        "movl 0xc(%ebp), %eax\n" /* line 608 | timeshift */
        "addl %eax, 0x344(%ebx)\n"
        "movb $0, 0x37c(%ebx)\n" /* line 609 */
        "addl $0x14, %esp\n" /* line 610 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 613 */
__attribute__((naked))
Bool SND_Is3DChannelFree(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 613 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* index */
        "leal (%edx, %edx, 4), %eax\n" /* line 616 */
        "shll $4, %eax\n"
        "addl 0x195ed34, %eax\n"
        "cmpb $0, 0x37c(%eax)\n"
        "jne .Lf56496_000564e4\n"
        "movl 0x33c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf56496_000564e4\n"
        "addl $0x350, %eax\n" /* line 618 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf56496_000564e8\n"
        ".Lf56496_000564ca:\n"
        "movl 0x4a3ba8(, %edx, 4), %eax\n" /* line 619 */
        "movl %eax, (%esp)\n"
        "calll AIL_3D_sample_status\n"
        "cmpl $2, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 620 */
        "retl\n"
        ".Lf56496_000564e4:\n"
        "xorl %eax, %eax\n" /* line 619 */
        "leave\n" /* line 620 */
        "retl\n"
        ".Lf56496_000564e8:\n"
        "movl 0xc(%eax), %ecx\n" /* line 618 */
        "testl %ecx, %ecx\n"
        "jne .Lf56496_000564ca\n"
        "movl $1, %eax\n"
        "leave\n" /* line 620 */
        "retl\n"
    );
}

/* line 623 */
__attribute__((naked))
void SND_StopStreamChannel(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 623 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "leal -0x20(%ebx), %edi\n" /* line 628 | index */
        "movl $0x4a3c20, %esi\n"
        "movl 8(%esi, %edi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_close_stream\n"
        "movl $0, 8(%esi, %edi, 4)\n" /* line 629 */
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 630 | index */
        "shll $4, %ebx\n" /* index */
        "addl 0x195ed34, %ebx\n" /* index */
        "movb $0, 0x37c(%ebx)\n" /* index */
        "movl $0, 0x33c(%ebx)\n" /* line 631 | index */
        "addl $0x1c, %esp\n" /* line 632 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 635 */
__attribute__((naked))
void SND_PauseStreamChannel(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 635 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl $1, 4(%esp)\n" /* line 638 */
        "movl 0x4a3ba8(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_pause_stream\n"
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 639 | index */
        "shll $4, %ebx\n" /* index */
        "addl 0x195ed34, %ebx\n" /* index */
        "movb $1, 0x37c(%ebx)\n" /* index */
        "addl $0x14, %esp\n" /* line 640 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 643 */
__attribute__((naked))
void SND_UnpauseStreamChannel(int index, int timeshift)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 643 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* index, timeshift */
        "leal (%eax, %eax, 4), %ebx\n" /* line 646 */
        "shll $4, %ebx\n"
        "addl 0x195ed34, %ebx\n"
        "movl 0x33c(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf5657e_000565b5\n"
        "movl $0, 4(%esp)\n" /* line 647 */
        "movl 0x4a3ba8(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_pause_stream\n"
        ".Lf5657e_000565b5:\n"
        "movl 0xc(%ebp), %eax\n" /* line 648 | timeshift */
        "addl %eax, 0x344(%ebx)\n"
        "movb $0, 0x37c(%ebx)\n" /* line 649 */
        "addl $0x14, %esp\n" /* line 650 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 653 */
__attribute__((naked))
Bool SND_IsStreamChannelFree(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 653 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* index */
        "leal -0x20(%eax), %ebx\n" /* line 656 */
        "movl 0x4a3c28(, %ebx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf565cc_00056652\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 658 */
        "shll $4, %eax\n"
        "addl 0x195ed34, %eax\n"
        "cmpb $0, 0x37c(%eax)\n"
        "jne .Lf565cc_0005661c\n"
        "movl 0x33c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf565cc_0005661c\n"
        "addl $0x350, %eax\n" /* line 660 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf565cc_0005664b\n"
        ".Lf565cc_0005660f:\n"
        "movl %edx, (%esp)\n" /* line 661 */
        "calll AIL_stream_status\n"
        "cmpl $2, %eax\n"
        "je .Lf565cc_00056624\n"
        ".Lf565cc_0005661c:\n"
        "xorl %eax, %eax\n" /* line 665 */
        "addl $0x14, %esp\n" /* line 668 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf565cc_00056624:\n"
        "movl 0x4a3c28(, %ebx, 4), %eax\n" /* line 663 */
        "movl %eax, (%esp)\n"
        "calll AIL_close_stream\n"
        "movl $0x4a3c20, %eax\n" /* line 664 */
        "movl $0, 8(%eax, %ebx, 4)\n"
        "movl $1, %eax\n"
        "addl $0x14, %esp\n" /* line 668 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf565cc_0005664b:\n"
        "movl 0xc(%eax), %ecx\n" /* line 660 */
        "testl %ecx, %ecx\n"
        "jne .Lf565cc_0005660f\n"
        ".Lf565cc_00056652:\n"
        "movl $1, %eax\n" /* line 665 */
        "addl $0x14, %esp\n" /* line 668 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 992 */
__attribute__((naked))
float SND_Get2DChannelVolume(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 992 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        /* { scope 1 */
        "leal -0x10(%ebp), %eax\n" /* line 999 | right */
        "movl %eax, 8(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* left */
        "movl %eax, 4(%esp)\n"
        "movl 0x4a3ad4(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_sample_volume_levels\n"
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 1001 | index */
        "shll $4, %ebx\n" /* index */
        "addl 0x195ed34, %ebx\n" /* index */
        "cmpl $2, 0x354(%ebx)\n" /* index */
        "je .Lf5665e_000566b2\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 1004 | left */
        "addss -0x10(%ebp), %xmm0\n" /* right */
        /* } scope */
        "movss %xmm0, -0x1c(%ebp)\n" /* line 1005 */
        "flds -0x1c(%ebp)\n"
        "addl $0x34, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5665e_000566b2:\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 1002 | left */
        /* } scope */
        "movss %xmm0, -0x1c(%ebp)\n" /* line 1005 */
        "flds -0x1c(%ebp)\n"
        "addl $0x34, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1033 */
float SND_Get3DChannelVolume(int index)
{
    return AIL_3D_sample_volume(*(void **)(0x4a3ba8 + index * 4));
}

/* line 1057 */
__attribute__((naked))
float SND_GetStreamChannelVolume(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1057 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        /* { scope 1 */
        "leal -0x10(%ebp), %eax\n" /* line 1064 | right */
        "movl %eax, 8(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* left */
        "movl %eax, 4(%esp)\n"
        "movl 0x4a3ba8(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_stream_volume_levels\n"
        "leal (%ebx, %ebx, 4), %ebx\n" /* line 1066 | index */
        "shll $4, %ebx\n" /* index */
        "addl 0x195ed34, %ebx\n" /* index */
        "leal 0x350(%ebx), %eax\n" /* index */
        "cmpl $2, 4(%eax)\n"
        "je .Lf566de_00056735\n"
        ".Lf566de_0005671d:\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 1069 | left */
        "addss -0x10(%ebp), %xmm0\n" /* right */
        /* } scope */
        ".Lf566de_00056727:\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* line 1070 */
        "flds -0x1c(%ebp)\n"
        "addl $0x34, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf566de_00056735:\n"
        "movl 8(%eax), %eax\n" /* line 1066 */
        "movl 0x2c(%eax), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_IsAliasChannel3D\n"
        "testb %al, %al\n"
        "jne .Lf566de_0005671d\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 1067 | left */
        "jmp .Lf566de_00056727\n"
    );
}

/* line 1098 */
int SND_Get2DChannelPlaybackRate(int index)
{
    return AIL_sample_playback_rate(*(void **)(0x4a3ad4 + index * 4));
}

/* line 1105 */
void SND_Set2DChannelPlaybackRate(int index, int rate)
{
    AIL_set_sample_playback_rate(*(void **)(0x4a3ad4 + index * 4), rate);
}

/* line 1112 */
int SND_Get3DChannelPlaybackRate(int index)
{
    return AIL_3D_sample_playback_rate(*(void **)(0x4a3ba8 + index * 4));
}

/* line 1119 */
void SND_Set3DChannelPlaybackRate(int index, int rate)
{
    AIL_set_3D_sample_playback_rate(*(void **)(0x4a3ba8 + index * 4), rate);
}

/* line 1126 */
int SND_GetStreamChannelPlaybackRate(int index)
{
    return AIL_stream_playback_rate(*(void **)(0x4a3ba8 + index * 4));
}

/* line 1133 */
void SND_SetStreamChannelPlaybackRate(int index, int rate)
{
    AIL_set_stream_playback_rate(*(void **)(0x4a3ba8 + index * 4), rate);
}

/* line 1156 */
__attribute__((naked))
void SND_UpdateStreamChannelReverb(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1156 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0x195ed34, %ecx\n" /* line 1160 */
        "leal (%ebx, %ebx, 4), %eax\n" /* index */
        "shll $4, %eax\n"
        "movl 0x358(%eax, %ecx), %edx\n" /* pAlias */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 193 */
        "je .Lf567dc_00056810\n"
        "movl 0x195ed40, %eax\n" /* line 196 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf567dc_0005683a\n"
        "testb $0x10, 0x2c(%edx)\n"
        "jne .Lf567dc_0005683a\n"
        ".Lf567dc_00056810:\n"
        "movl 0x2d8(%ecx), %eax\n"
        "movl 0x10(%eax), %eax\n"
        /* } scope */
        "movl %eax, 8(%esp)\n" /* line 1160 */
        "movl $0x3f800000, 4(%esp)\n"
        "movl 0x4a3ba8(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_stream_reverb_levels\n"
        "addl $0x14, %esp\n" /* line 1161 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf567dc_0005683a:\n"
        "xorl %eax, %eax\n" /* line 196 */
        /* } scope */
        "movl %eax, 8(%esp)\n" /* line 1160 */
        "movl $0x3f800000, 4(%esp)\n"
        "movl 0x4a3ba8(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_stream_reverb_levels\n"
        "addl $0x14, %esp\n" /* line 1161 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1164 */
__attribute__((naked))
int SND_Get2DChannelLength(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1164 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 1170 | length */
        "movl $0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* index */
        "movl 0x4a3ad4(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_sample_ms_position\n"
        "movl -0xc(%ebp), %eax\n" /* length */
        /* } scope */
        "leave\n" /* line 1172 */
        "retl\n"
    );
}

/* line 1175 */
int SND_Get3DChannelLength(int index)
{
    return AIL_3D_sample_length(*(void **)(0x4a3ba8 + index * 4));
}

/* line 1182 */
__attribute__((naked))
int SND_GetStreamChannelLength(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1182 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 1188 | length */
        "movl $0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* index */
        "movl 0x4a3ba8(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_stream_ms_position\n"
        "movl -0xc(%ebp), %eax\n" /* length */
        /* } scope */
        "leave\n" /* line 1190 */
        "retl\n"
    );
}

/* line 1193 */
__attribute__((naked))
void SND_Get2DChannelSaveInfo(int index, snd_save_2D_sample_t *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1193 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* index */
        "movl 0xc(%ebp), %esi\n" /* info */
        /* { scope 1 */
        "movl 0x4a3ad4(, %edi, 4), %eax\n" /* line 1200 */
        "movl %eax, -0x2c(%ebp)\n" /* handle */
        "leal -0x1c(%ebp), %eax\n" /* line 1203 | offset */
        "leal -0x20(%ebp), %edx\n" /* length */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll AIL_sample_ms_position\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1204 | offset */
        "testl %edx, %edx\n"
        "js .Lf568cc_00056996\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "movl -0x20(%ebp), %edx\n" /* length */
        "testl %edx, %edx\n"
        "js .Lf568cc_000569b2\n"
        ".Lf568cc_00056918:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf568cc_0005691c:\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n" /* info */
        "movl 0x195ed34, %ebx\n" /* line 1205 */
        "leal (%edi, %edi, 4), %eax\n" /* index */
        "shll $4, %eax\n"
        "movl 0x350(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esi)\n" /* info */
        "leal 0xc(%esi), %eax\n" /* line 1206 | info */
        "movl %eax, 8(%esp)\n"
        "leal 8(%esi), %eax\n" /* info */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll AIL_sample_volume_pan\n"
        "movss 0x24(%ebx), %xmm1\n" /* line 1207 */
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lf568cc_00056963\n"
        "je .Lf568cc_00056979\n"
        ".Lf568cc_00056963:\n"
        "movss 8(%esi), %xmm0\n" /* line 1208 | info */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esi)\n" /* info */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1211 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf568cc_00056979:\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 1210 | index */
        "shll $4, %eax\n"
        "addl 0x195ed34, %eax\n"
        "movl 0x348(%eax), %eax\n"
        "movl %eax, 8(%esi)\n" /* info */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1211 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf568cc_00056996:\n"
        "movl %edx, %eax\n" /* line 1204 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "movl -0x20(%ebp), %edx\n" /* length */
        "testl %edx, %edx\n"
        "jns .Lf568cc_00056918\n"
        ".Lf568cc_000569b2:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf568cc_0005691c\n"
    );
}

/* line 1222 */
__attribute__((naked))
void SND_Get3DChannelSaveInfo(int index, snd_save_3D_sample_t *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1222 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* info */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1227 | index */
        "movl 0x4a3ba8(, %eax, 4), %edi\n" /* handle */
        "movl %edi, (%esp)\n" /* line 1230 | handle */
        "calll AIL_3D_sample_offset\n"
        "movl %eax, %ebx\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_3D_sample_length\n"
        "movl %eax, %edx\n"
        "testl %ebx, %ebx\n"
        "js .Lf569c8_00056ac0\n"
        "cvtsi2ssl %ebx, %xmm1\n"
        "testl %edx, %edx\n"
        "js .Lf569c8_00056ad9\n"
        ".Lf569c8_00056a06:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf569c8_00056a0a:\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n" /* info */
        "movl 0x195ed34, %ebx\n" /* line 1231 */
        "movl 8(%ebp), %edx\n" /* index */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "movl 0x350(%eax, %ebx), %eax\n"
        "movl %eax, 4(%esi)\n" /* info */
        "movl %edi, (%esp)\n" /* line 1232 | handle */
        "calll AIL_3D_sample_volume\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esi)\n" /* info */
        "movss 0x24(%ebx), %xmm0\n" /* line 1233 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf569c8_00056a50\n"
        "je .Lf569c8_00056a83\n"
        ".Lf569c8_00056a50:\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 1234 */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esi)\n" /* info */
        "leal 0x14(%esi), %eax\n" /* line 1237 | info */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x10(%esi), %eax\n" /* info */
        "movl %eax, 8(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* info */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_3D_position\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1238 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf569c8_00056a83:\n"
        "movl 8(%ebp), %edx\n" /* line 1236 | index */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "addl 0x195ed34, %eax\n"
        "movl 0x348(%eax), %eax\n"
        "movl %eax, 8(%esi)\n" /* info */
        "leal 0x14(%esi), %eax\n" /* line 1237 | info */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x10(%esi), %eax\n" /* info */
        "movl %eax, 8(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* info */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_3D_position\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1238 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf569c8_00056ac0:\n"
        "movl %ebx, %eax\n" /* line 1230 */
        "shrl $1, %eax\n"
        "andl $1, %ebx\n"
        "orl %ebx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "testl %edx, %edx\n"
        "jns .Lf569c8_00056a06\n"
        ".Lf569c8_00056ad9:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf569c8_00056a0a\n"
    );
}

/* line 1241 */
__attribute__((naked))
void SND_GetStreamChannelSaveInfo(int index, snd_save_stream_t *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1241 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* info */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1248 | index */
        "movl 0x4a3ba8(, %eax, 4), %edi\n" /* handle */
        "leal -0x1c(%ebp), %eax\n" /* line 1251 | offset */
        "leal -0x20(%ebp), %edx\n" /* length */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_stream_ms_position\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1252 | offset */
        "testl %edx, %edx\n"
        "js .Lf56af0_00056c0a\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "movl -0x20(%ebp), %edx\n" /* length */
        "testl %edx, %edx\n"
        "js .Lf56af0_00056c26\n"
        ".Lf56af0_00056b36:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf56af0_00056b3a:\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, (%ebx)\n" /* info */
        "movl %edi, (%esp)\n" /* line 1253 | handle */
        "calll AIL_stream_playback_rate\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "movl 0x195ed34, %esi\n"
        "divss 0x10(%esi), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ebp), %edx\n" /* line 1254 | index */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "movl 0x348(%eax, %esi), %eax\n"
        "movl %eax, 8(%ebx)\n" /* info */
        "leal 0x10(%ebx), %eax\n" /* line 1255 | info */
        "movl %eax, 8(%esp)\n"
        "leal 0xc(%ebx), %eax\n" /* info */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_stream_volume_pan\n"
        "movss 0x24(%esi), %xmm1\n" /* line 1256 */
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lf56af0_00056baf\n"
        "je .Lf56af0_00056bef\n"
        ".Lf56af0_00056baf:\n"
        "movss 0xc(%ebx), %xmm0\n" /* line 1257 | info */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n" /* info */
        "movl %esi, %edx\n"
        ".Lf56af0_00056bbf:\n"
        "leal 0x14(%ebx), %ecx\n" /* line 1260 | info, to */
        "movl 8(%ebp), %esi\n" /* index */
        "leal (%esi, %esi, 4), %eax\n"
        "shll $4, %eax\n"
        "leal 0x360(%eax, %edx), %eax\n"
        "leal 4(%eax), %edx\n" /* from */
        /* { scope 2 */
        "movl 4(%eax), %eax\n" /* line 199 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1261 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf56af0_00056bef:\n"
        "movl 0x195ed34, %edx\n" /* line 1259 */
        "movl 8(%ebp), %ecx\n" /* index */
        "leal (%ecx, %ecx, 4), %eax\n"
        "shll $4, %eax\n"
        "movl 0x348(%eax, %edx), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* info */
        "jmp .Lf56af0_00056bbf\n"
        ".Lf56af0_00056c0a:\n"
        "movl %edx, %eax\n" /* line 1252 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "movl -0x20(%ebp), %edx\n" /* length */
        "testl %edx, %edx\n"
        "jns .Lf56af0_00056b36\n"
        ".Lf56af0_00056c26:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf56af0_00056b3a\n"
    );
}

/* line 1328 */
__attribute__((naked))
void SND_EndRawSamples(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1328 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x4a3c5c, %eax\n" /* line 1330 */
        "testl %eax, %eax\n"
        "je .Lf56c3c_00056c77\n"
        "movl %eax, (%esp)\n" /* line 1332 */
        "calll AIL_end_sample\n"
        "movl 0x4a3c5c, %eax\n" /* line 1333 */
        "movl %eax, (%esp)\n"
        "calll AIL_release_sample_handle\n"
        "movl $0, 0x4a3c5c\n" /* line 1334 */
        "movl 0x4a3c6c, %eax\n" /* line 1335 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        ".Lf56c3c_00056c77:\n"
        "leave\n" /* line 1337 */
        "retl\n"
    );
}

/* line 1340 */
__attribute__((naked))
int SND_RawSamplesTime(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1340 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl 0x4a3c5c, %eax\n" /* line 1344 */
        "testl %eax, %eax\n"
        "je .Lf56c7a_00056cb7\n"
        "movl %eax, (%esp)\n" /* line 1347 */
        "calll AIL_sample_position\n"
        "xorl %edx, %edx\n" /* line 1348 */
        "pushl %edx\n"
        "pushl %eax\n"
        "fildll (%esp)\n"
        "addl $8, %esp\n"
        "fstpl -0x10(%ebp)\n"
        "movsd -0x10(%ebp), %xmm0\n"
        "mulsd 0x4a3ca8, %xmm0\n"
        "addsd 0x4a3ca0, %xmm0\n"
        "cvttsd2si %xmm0, %eax\n"
        /* } scope */
        ".Lf56c7a_00056cb7:\n"
        "leave\n" /* line 1349 */
        "retl\n"
    );
}

/* line 1377 */
__attribute__((naked))
void SND_RawSamples(int samples, int rate, int width, int s_channels, const byte *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1377 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0x18(%ebp), %esi\n" /* data */
        /* { scope 1 */
        "movl 0x195ed34, %eax\n" /* line 1383 */
        "cmpb $0, (%eax)\n"
        "je .Lf56cba_00056ced\n"
        "movl 0x4a3c5c, %edi\n" /* line 1386 | copy */
        "testl %edi, %edi\n" /* copy */
        "je .Lf56cba_00056db1\n"
        ".Lf56cba_00056cde:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1399 | width, bytes */
        "imull 8(%ebp), %ebx\n" /* samples, bytes */
        "imull 0x14(%ebp), %ebx\n" /* s_channels, bytes */
        "testl %ebx, %ebx\n" /* line 1408 | bytes */
        "jne .Lf56cba_00056d2f\n"
        /* } scope */
        ".Lf56cba_00056ced:\n"
        "addl $0x1c, %esp\n" /* line 1428 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf56cba_00056cf5:\n"
        "movl %ebx, %edi\n" /* line 1414 | bytes, copy */
        "xorl %ebx, %ebx\n" /* bytes */
        ".Lf56cba_00056cf9:\n"
        "movl %edi, 8(%esp)\n" /* line 1417 | copy */
        "movl %esi, 4(%esp)\n" /* data */
        "imull %edx, %eax\n"
        "addl 0x4a3c6c, %eax\n"
        "addl %ecx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "addl %edi, %esi\n" /* line 1418 | copy, data */
        "movl %edi, %eax\n" /* line 1420 | copy */
        "addl 0x4a3c94, %eax\n"
        "movl %eax, 0x4a3c94\n"
        "cmpl 0x4a3c90, %eax\n" /* line 1421 */
        "je .Lf56cba_00056d7f\n"
        ".Lf56cba_00056d2b:\n"
        "testl %ebx, %ebx\n" /* line 1408 | bytes */
        "je .Lf56cba_00056ced\n"
        ".Lf56cba_00056d2f:\n"
        "movl 0x4a3c9c, %edx\n" /* line 1410 */
        "cmpb $0, 0x4a3c70(%edx)\n"
        "jne .Lf56cba_00056d55\n"
        ".Lf56cba_00056d3e:\n"
        "movl 0x4a3c90, %eax\n" /* line 1413 */
        "movl 0x4a3c94, %ecx\n"
        "movl %eax, %edi\n" /* copy */
        "subl %ecx, %edi\n" /* copy */
        "cmpl %edi, %ebx\n" /* line 1414 | copy, bytes */
        "jl .Lf56cba_00056cf5\n"
        "subl %edi, %ebx\n" /* copy, bytes */
        "jmp .Lf56cba_00056cf9\n"
        ".Lf56cba_00056d55:\n"
        "calll SND_Update\n" /* line 1411 */
        "movl 0x4a3c9c, %edx\n" /* line 1410 */
        "cmpb $0, 0x4a3c70(%edx)\n"
        "je .Lf56cba_00056d3e\n"
        "calll SND_Update\n" /* line 1411 */
        "movl 0x4a3c9c, %edx\n" /* line 1410 */
        "cmpb $0, 0x4a3c70(%edx)\n"
        "jne .Lf56cba_00056d55\n"
        "jmp .Lf56cba_00056d3e\n"
        ".Lf56cba_00056d7f:\n"
        "movl $0, 0x4a3c94\n" /* line 1423 */
        "movl 0x4a3c9c, %eax\n" /* line 1424 */
        "movb $1, 0x4a3c70(%eax)\n"
        "addl $1, %eax\n" /* line 1425 */
        "andl $0x8000001f, %eax\n"
        "js .Lf56cba_00056da6\n"
        ".Lf56cba_00056d9f:\n"
        "movl %eax, 0x4a3c9c\n"
        "jmp .Lf56cba_00056d2b\n"
        ".Lf56cba_00056da6:\n"
        "subl $1, %eax\n"
        "orl $0xffffffe0, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf56cba_00056d9f\n"
        /* { scope 2 */
        ".Lf56cba_00056db1:\n"
        "movl milesGlob, %eax\n" /* line 1281 */
        "movl %eax, (%esp)\n"
        "calll AIL_allocate_sample_handle\n"
        "movl %eax, 0x4a3c5c\n"
        "testl %eax, %eax\n" /* line 1282 */
        "je .Lf56cba_00056f58\n"
        ".Lf56cba_00056dcb:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1285 | rate */
        "movl %eax, 0x4a3c60\n"
        "movl 0x10(%ebp), %eax\n" /* line 1286 | width */
        "movl %eax, 0x4a3c64\n"
        "movl 0x14(%ebp), %eax\n" /* line 1287 | s_channels */
        "movl %eax, 0x4a3c68\n"
        "movl 0x4a3c5c, %eax\n" /* line 1289 */
        "movl %eax, (%esp)\n"
        "calll AIL_init_sample\n"
        "cmpl $1, 0x14(%ebp)\n" /* line 1290 | s_channels */
        "je .Lf56cba_00056f26\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1301 | width */
        "je .Lf56cba_00056f4e\n"
        "cmpl $2, 0x10(%ebp)\n" /* line 1303 | width */
        "je .Lf56cba_00056f44\n"
        ".Lf56cba_00056e0e:\n"
        "xorl %ebx, %ebx\n" /* format */
        ".Lf56cba_00056e10:\n"
        "movl $0, 8(%esp)\n" /* line 1308 */
        "movl %ebx, 4(%esp)\n" /* format */
        "movl 0x4a3c5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_type\n"
        "movl 0xc(%ebp), %eax\n" /* line 1309 | rate */
        "movl %eax, 4(%esp)\n"
        "movl 0x4a3c5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_playback_rate\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 1311 | 0.5f */
        "movl 0x195ed34, %eax\n"
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl 0x4a3c5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_volume_levels\n"
        "movl %ebx, 8(%esp)\n" /* line 1313 | format */
        "movl 0xc(%ebp), %eax\n" /* rate */
        "movl %eax, 4(%esp)\n"
        "movl milesGlob, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_minimum_sample_buffer_size\n"
        "movl $0x2000, %edx\n" /* line 1316 */
        "cmpl $0x2001, %eax\n"
        "cmovgel %eax, %edx\n"
        "movl %edx, 0x4a3c90\n"
        "shll $5, %edx\n" /* line 1317 */
        "movl %edx, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 0x4a3c6c\n"
        "movl $0x4a3c70, %edi\n" /* line 1318 */
        "cld\n"
        "movl $8, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $0, 0x4a3c98\n" /* line 1319 */
        "movl $0, 0x4a3c9c\n" /* line 1320 */
        "movl $0, 0x4a3c94\n" /* line 1321 */
        "movl $0, 0x4a3ca0\n" /* line 1323 */
        "movl $0, 0x4a3ca4\n"
        "movl 0x4a3c60, %eax\n" /* line 1324 */
        "imull 0x4a3c64, %eax\n"
        "imull 0x4a3c68, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0x4a3ca8\n"
        /* } scope */
        "movl 0x4a3c5c, %ebx\n" /* line 1389 | bytes */
        "testl %ebx, %ebx\n" /* bytes */
        "jne .Lf56cba_00056cde\n"
        "jmp .Lf56cba_00056ced\n"
        /* { scope 2 */
        ".Lf56cba_00056f26:\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1292 | width */
        "je .Lf56cba_00056e0e\n"
        "cmpl $2, 0x10(%ebp)\n" /* line 1294 | width */
        "jne .Lf56cba_00056e0e\n"
        "movl $1, %ebx\n" /* format */
        "jmp .Lf56cba_00056e10\n"
        ".Lf56cba_00056f44:\n"
        "movl $3, %ebx\n" /* line 1303 | format */
        "jmp .Lf56cba_00056e10\n"
        ".Lf56cba_00056f4e:\n"
        "movl $2, %ebx\n" /* line 1301 | format */
        "jmp .Lf56cba_00056e10\n"
        ".Lf56cba_00056f58:\n"
        "movl $0x21992c, 4(%esp)\n" /* line 1283 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf56cba_00056dcb\n"
    );
}

/* line 1569 */
int SND_GetSoundFileSize(const void *pSoundFile)
{
    return *(int *)((byte *)pSoundFile + 8) + 0x24;
}

/* line 1587 */
void SND_DriverPreUpdate(int frametime)
{
}

/* line 984 */
__attribute__((naked))
void SND_SetRoomtype(int roomtype)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 984 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* roomtype */
        "movl %ebx, 4(%esp)\n" /* line 986 | roomtype */
        "movl milesGlob, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_digital_master_room_type\n"
        "movl 0x195ed34, %eax\n" /* line 987 */
        "movl 0x2d8(%eax), %eax\n"
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl milesGlob, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_digital_master_reverb_levels\n"
        "movl %ebx, 4(%esp)\n" /* line 988 | roomtype */
        "movl 0x4a3b84, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_room_type\n"
        "addl $0x14, %esp\n" /* line 989 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1140 */
__attribute__((naked))
void SND_Update2DChannelReverb(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1140 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0x195ed34, %ecx\n" /* line 1144 */
        "leal (%ebx, %ebx, 4), %eax\n" /* index */
        "shll $4, %eax\n"
        "movl 0x358(%eax, %ecx), %edx\n" /* pAlias */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 193 */
        "je .Lf56fe0_00057014\n"
        "movl 0x195ed40, %eax\n" /* line 196 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf56fe0_0005703e\n"
        "testb $0x10, 0x2c(%edx)\n"
        "jne .Lf56fe0_0005703e\n"
        ".Lf56fe0_00057014:\n"
        "movl 0x2d8(%ecx), %eax\n"
        "movl 0x10(%eax), %eax\n"
        /* } scope */
        "movl %eax, 8(%esp)\n" /* line 1144 */
        "movl $0x3f800000, 4(%esp)\n"
        "movl 0x4a3ad4(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_reverb_levels\n"
        "addl $0x14, %esp\n" /* line 1145 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf56fe0_0005703e:\n"
        "xorl %eax, %eax\n" /* line 196 */
        /* } scope */
        "movl %eax, 8(%esp)\n" /* line 1144 */
        "movl $0x3f800000, 4(%esp)\n"
        "movl 0x4a3ad4(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_reverb_levels\n"
        "addl $0x14, %esp\n" /* line 1145 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1148 */
__attribute__((naked))
void SND_Update3DChannelReverb(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1148 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0x195ed34, %ecx\n" /* line 1152 */
        "leal (%ebx, %ebx, 4), %eax\n" /* index */
        "shll $4, %eax\n"
        "movl 0x358(%eax, %ecx), %edx\n" /* pAlias */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 193 */
        "je .Lf57062_00057096\n"
        "movl 0x195ed40, %eax\n" /* line 196 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf57062_000570b8\n"
        "testb $0x10, 0x2c(%edx)\n"
        "jne .Lf57062_000570b8\n"
        ".Lf57062_00057096:\n"
        "movl 0x2d8(%ecx), %eax\n"
        "movl 0x10(%eax), %eax\n"
        /* } scope */
        "movl %eax, 4(%esp)\n" /* line 1152 */
        "movl 0x4a3ba8(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_sample_effects_level\n"
        "addl $0x14, %esp\n" /* line 1153 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf57062_000570b8:\n"
        "xorl %eax, %eax\n" /* line 196 */
        /* } scope */
        "movl %eax, 4(%esp)\n" /* line 1152 */
        "movl 0x4a3ba8(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_sample_effects_level\n"
        "addl $0x14, %esp\n" /* line 1153 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 518 */
__attribute__((naked))
void SND_Set3DPosition(int index, const vec_t *org)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 518 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* org */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 526 | org */
        "calll SND_GetListenerIndexNearestToOrigin\n"
        "leal (, %eax, 8), %edx\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x195ed34, %ecx\n"
        "leal 0x2f0(%eax, %ecx), %edx\n"
        "leal 4(%edx), %esi\n"
        /* { scope 2 */
        "movss (%ebx), %xmm2\n" /* line 248 */
        "subss 4(%edx), %xmm2\n"
        "movss 4(%ebx), %xmm3\n" /* line 249 */
        "subss 4(%esi), %xmm3\n"
        "movss 8(%ebx), %xmm4\n" /* line 250 */
        "subss 8(%esi), %xmm4\n"
        "leal 0x10(%edx), %ebx\n"
        "leal 0x2fc(%eax, %ecx), %esi\n"
        "leal 0x10(%esi), %edi\n"
        "leal 0x308(%eax, %ecx), %eax\n"
        "leal 0x10(%eax), %ecx\n"
        /* } scope */
        "movaps %xmm2, %xmm0\n" /* line 532 */
        "mulss 0x10(%edx), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%ebx), %xmm1\n" /* org */
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%ebx), %xmm1\n" /* org */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x10(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "mulss 0x10(%esi), %xmm2\n" /* b */
        "mulss 4(%edi), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss 8(%edi), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "xorps 0x2f0360, %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* index */
        "movl 0x4a3ba8(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_position\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 533 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 485 */
static __attribute__((naked))
void MSS_SpatializeStream(float *volume, float *pan)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 485 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl %ecx, -0x40(%ebp)\n"
        /* { scope 1 */
        "leal 0xa0(%eax, %eax, 4), %eax\n" /* line 498 | i */
        "shll $4, %eax\n" /* i */
        "movl 0x195ed34, %edx\n"
        "leal 0x350(%eax, %edx), %edx\n" /* i */
        "movl %edx, -0x44(%ebp)\n"
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* pAlias0 */
        "movl -0x44(%ebp), %edx\n" /* line 499 */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* pAlias1 */
        "movl 0x195ed34, %edx\n" /* line 505 */
        "leal 0x360(%eax, %edx), %esi\n" /* i */
        "leal 4(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll SND_GetListenerIndexNearestToOrigin\n"
        "movl %eax, %edx\n" /* i */
        "leal (, %eax, 8), %eax\n" /* i */
        "movl %edx, %edi\n"
        "shll $6, %edi\n"
        "subl %eax, %edi\n" /* i */
        "movl 0x195ed34, %edx\n"
        "leal 0x2f0(%edi, %edx), %eax\n" /* i */
        "leal 4(%eax), %edx\n" /* i */
        /* { scope 2 */
        "movss 4(%esi), %xmm0\n" /* line 248 */
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* delta */
        "movss 4(%ebx), %xmm0\n" /* line 249 */
        "subss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%ebx), %xmm0\n" /* line 250 */
        "subss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "leal -0x24(%ebp), %eax\n" /* line 507 | delta, i */
        "movl %eax, (%esp)\n" /* i */
        "calll Vec3Normalize\n"
        "movl 0x195ed34, %eax\n" /* i */
        "leal 0x2fc(%edi, %eax), %edx\n"
        "leal 0x10(%edx), %eax\n" /* i */
        /* { scope 2 */
        "movss -0x24(%ebp), %xmm5\n" /* line 304 | delta */
        "mulss 0x10(%edx), %xmm5\n"
        "movss -0x20(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        /* } scope */
        "movl -0x44(%ebp), %edx\n" /* line 510 */
        "movss 0x10(%edx), %xmm4\n"
        "movss 0x2ed5d0, %xmm3\n" /* line 511 | 1.0f */
        "movaps %xmm3, %xmm2\n"
        "subss %xmm4, %xmm2\n"
        "movl -0x3c(%ebp), %eax\n" /* line 513 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "movl -0x30(%ebp), %eax\n" /* pAlias0 */
        "mulss 0x28(%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "movl -0x2c(%ebp), %edx\n" /* pAlias1 */
        "mulss 0x28(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "mulss 0x24(%eax), %xmm2\n"
        "mulss 0x24(%edx), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss %xmm2, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movl 0x40(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm3, -0x58(%ebp)\n"
        "movss %xmm5, -0x68(%ebp)\n"
        "calll SND_Attenuate\n"
        "fstps -0x34(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "mulss -0x34(%ebp), %xmm0\n"
        "movl -0x3c(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "movss -0x58(%ebp), %xmm3\n" /* line 514 */
        "movss -0x68(%ebp), %xmm5\n"
        "subss %xmm5, %xmm3\n"
        "mulss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "movl -0x40(%ebp), %edx\n"
        "movss %xmm3, (%edx)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 515 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1716 */
__attribute__((naked))
void SND_UpdateStreamChannel(int i, int frametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1716 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: pan */
        "movl 8(%ebp), %eax\n" /* line 1725 | i */
        "leal (%eax, %eax, 4), %ebx\n"
        "shll $4, %ebx\n"
        "movl 0x195ed34, %edx\n"
        "leal (%ebx, %edx), %esi\n"
        "cmpb $0, 0x37c(%esi)\n"
        "jne .Lf57348_000574af\n"
        "cmpl $0x22, %eax\n" /* line 1728 */
        "jle .Lf57348_000574b7\n"
        ".Lf57348_00057379:\n"
        "leal 0x350(%esi), %eax\n" /* line 1734 */
        "movl 8(%eax), %edi\n" /* pAlias0 */
        "movl 0xc(%eax), %eax\n" /* line 1735 */
        "testl %edi, %edi\n" /* line 1737 | pAlias0 */
        "je .Lf57348_000574af\n"
        "testl %eax, %eax\n"
        "je .Lf57348_000574af\n"
        "movl 0x348(%esi), %eax\n" /* line 1742 */
        "movl %eax, -0x1c(%ebp)\n" /* volume */
        "movl $0x3f000000, -0x20(%ebp)\n" /* line 1743 | pan */
        "movl 0x2c(%edi), %eax\n" /* line 1745 | pAlias0 */
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_IsAliasChannel3D\n"
        "testb %al, %al\n"
        "jne .Lf57348_00057525\n"
        "movl 8(%ebp), %ebx\n" /* i */
        "subl $0x20, %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n"
        ".Lf57348_000573c9:\n"
        "movl 0x195ed34, %ebx\n" /* line 1769 */
        "pxor %xmm0, %xmm0\n"
        "ucomiss 0x274(%ebx), %xmm0\n"
        "jp .Lf57348_000573de\n"
        "je .Lf57348_000573f5\n"
        ".Lf57348_000573de:\n"
        "movl 8(%ebp), %ecx\n" /* i */
        "leal (%ecx, %ecx, 4), %eax\n"
        "shll $4, %eax\n"
        "cmpb $0, 0x37d(%eax, %ebx)\n"
        "je .Lf57348_000574f5\n"
        ".Lf57348_000573f5:\n"
        "movl 0x2c(%edi), %eax\n" /* pAlias0 */
        ".Lf57348_000573f8:\n"
        "movl 0x254(%ebx), %edx\n" /* line 1773 */
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movss (%edx, %eax, 4), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* volume */
        "movss %xmm0, -0x1c(%ebp)\n" /* volume */
        "movss -0x20(%ebp), %xmm1\n" /* line 1774 | pan, volume */
        "movss %xmm1, -0x30(%ebp)\n" /* volume, pan */
        "movaps %xmm0, %xmm1\n" /* volume */
        "mulss 0x24(%ebx), %xmm1\n" /* volume */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 1091 | i */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "leal 0x350(%eax, %ebx), %eax\n"
        "cmpl $2, 4(%eax)\n"
        "je .Lf57348_00057680\n"
        ".Lf57348_00057444:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 1094 | pan */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x30(%ebp), %xmm0\n" /* pan */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl 0x4a3c28(, %ecx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_stream_volume_levels\n"
        /* } scope */
        ".Lf57348_0005747c:\n"
        "movl 8(%ebp), %edx\n" /* line 1776 | i */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "addl 0x195ed34, %eax\n"
        "leal 0x330(%eax), %ecx\n"
        "movl 0xc(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf57348_000574af\n"
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 154 */
        "subl 0xc(%ebp), %eax\n" /* frametime */
        "cmpl %edx, 0xc(%ebp)\n" /* frametime */
        "movl $0, %edx\n"
        "cmovnsl %edx, %eax\n"
        /* } scope */
        "movl %eax, 0xc(%ecx)\n" /* line 1778 */
        "testl %eax, %eax\n" /* line 1779 */
        "je .Lf57348_000574d3\n"
        /* } scope */
        ".Lf57348_000574af:\n"
        "addl $0x5c, %esp\n" /* line 1784 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pan */
        ".Lf57348_000574b7:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1730 | frametime */
        "movl %ecx, 4(%esp)\n"
        "subl $0x20, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_UpdateBackgroundVolume\n"
        "testb %al, %al\n"
        "jne .Lf57348_00057379\n"
        "jmp .Lf57348_000574af\n"
        ".Lf57348_000574d3:\n"
        "movl $0, 4(%esp)\n" /* line 1781 */
        "movl -0x2c(%ebp), %ecx\n"
        "movl 0x4a3c28(, %ecx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_pause_stream\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1784 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pan */
        ".Lf57348_000574f5:\n"
        "movl 0x2c(%edi), %eax\n" /* line 1769 | pAlias0 */
        "testb $4, %al\n"
        "je .Lf57348_000573f8\n"
        "movl 0x30(%edi), %eax\n" /* line 1770 | pAlias0 */
        "movl %eax, (%esp)\n"
        "calll SND_GetLerpedSlavePercentage\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* volume */
        "movss %xmm0, -0x1c(%ebp)\n" /* volume */
        "movl 0x2c(%edi), %eax\n" /* pAlias0 */
        "jmp .Lf57348_000573f8\n"
        ".Lf57348_00057525:\n"
        "movl 0x195ed34, %eax\n" /* line 1747 */
        "leal 0x360(%ebx, %eax), %ebx\n"
        "leal 4(%ebx), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, 8(%esp)\n"
        "leal 0x10(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x334(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_GetCurrent3DPosition\n"
        "movl 8(%ebp), %ecx\n" /* line 1748 | i */
        "subl $0x20, %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "leal -0x20(%ebp), %ecx\n" /* pan */
        "leal -0x1c(%ebp), %edx\n" /* volume */
        "movl -0x2c(%ebp), %eax\n"
        "calll MSS_SpatializeStream\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1751 */
        "movl 0x4a3c28(, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_is_3D_stream\n"
        "testl %eax, %eax\n"
        "je .Lf57348_000573c9\n"
        /* { scope 2 */
        "movl -0x38(%ebp), %ecx\n" /* line 1757 */
        "movl %ecx, (%esp)\n"
        "calll SND_GetListenerIndexNearestToOrigin\n"
        "leal (, %eax, 8), %edx\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x195ed34, %ecx\n"
        "leal 0x2f0(%eax, %ecx), %edx\n"
        "leal 4(%edx), %ecx\n"
        /* { scope 3 */
        "movss 4(%ebx), %xmm2\n" /* line 248 */
        "subss 4(%edx), %xmm2\n"
        "movl -0x38(%ebp), %ebx\n" /* line 249 */
        "movss 4(%ebx), %xmm3\n"
        "subss 4(%ecx), %xmm3\n"
        "movss 8(%ebx), %xmm4\n" /* line 250 */
        "subss 8(%ecx), %xmm4\n"
        "leal 0x10(%edx), %ecx\n"
        "movl 0x195ed34, %ebx\n"
        "leal 0x2fc(%eax, %ebx), %esi\n"
        "leal 0x10(%esi), %ebx\n"
        "movl %ebx, -0x34(%ebp)\n"
        "movl 0x195ed34, %ebx\n"
        "leal 0x308(%eax, %ebx), %eax\n"
        "leal 0x10(%eax), %ebx\n"
        /* } scope */
        "movaps %xmm2, %xmm0\n" /* line 1763 */
        "mulss 0x10(%edx), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x10(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "mulss 0x10(%esi), %xmm2\n"
        "movl -0x34(%ebp), %eax\n"
        "mulss 4(%eax), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss 8(%eax), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "xorps 0x2f0370, %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl 0x4a3c28(, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_stream_position\n"
        "movl $0x3f000000, -0x20(%ebp)\n" /* line 1764 | pan */
        "jmp .Lf57348_000573c9\n"
        /* } scope */
        /* { scope 2 */
        ".Lf57348_00057680:\n"
        "movl 8(%eax), %eax\n" /* line 1091 */
        "movl 0x2c(%eax), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll SND_IsAliasChannel3D\n"
        "testb %al, %al\n"
        "movss -0x48(%ebp), %xmm1\n"
        "jne .Lf57348_00057444\n"
        "movss %xmm1, 8(%esp)\n" /* line 1092 */
        "movss %xmm1, 4(%esp)\n"
        "movl -0x2c(%ebp), %ebx\n"
        "movl 0x4a3c28(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_stream_volume_levels\n"
        "jmp .Lf57348_0005747c\n"
    );
}

/* line 1612 */
__attribute__((naked))
void SND_Update2DChannel(int i, int frametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1612 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* i */
        "movl 0xc(%ebp), %eax\n" /* frametime */
        "movl %eax, -0x24(%ebp)\n" /* frametime */
        /* { scope 1 */
        "movl 0x195ed34, %edi\n" /* line 1620 */
        "leal (%ebx, %ebx, 4), %eax\n" /* i */
        "shll $4, %eax\n"
        "leal (%eax, %edi), %edx\n"
        "leal 0x370(%edx), %ecx\n"
        "cmpb $0, 0xc(%ecx)\n"
        "jne .Lf576cc_000577c3\n"
        "leal 0x350(%edx), %eax\n" /* line 1623 */
        "movl 8(%eax), %esi\n" /* pAlias0 */
        "movl 0xc(%eax), %eax\n" /* line 1624 */
        "testl %esi, %esi\n" /* line 1626 | pAlias0 */
        "je .Lf576cc_000577c3\n"
        "testl %eax, %eax\n"
        "je .Lf576cc_000577c3\n"
        "movss 0x348(%edx), %xmm0\n" /* line 1631 */
        "movss %xmm0, -0x1c(%ebp)\n" /* volume */
        "pxor %xmm0, %xmm0\n" /* line 1633 */
        "ucomiss 0x274(%edi), %xmm0\n"
        "jp .Lf576cc_000577cb\n"
        "jne .Lf576cc_000577cb\n"
        ".Lf576cc_0005773d:\n"
        "movl 0x2c(%esi), %eax\n" /* pAlias0 */
        ".Lf576cc_00057740:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* volume */
        ".Lf576cc_00057745:\n"
        "movl 0x254(%edi), %edx\n" /* line 1638 */
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "mulss (%edx, %eax, 4), %xmm0\n" /* volume */
        "mulss 0x24(%edi), %xmm0\n" /* volume */
        /* { scope 2 */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 1026 */
        "shll $4, %eax\n"
        "cmpl $2, 0x354(%eax, %edi)\n"
        "je .Lf576cc_00057778\n"
        "mulss 0x2ed5d8, %xmm0\n" /* line 1029 | 0.5f */
        ".Lf576cc_00057778:\n"
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl 0x4a3ad4(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_volume_levels\n"
        /* } scope */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 1640 | i */
        "shll $4, %eax\n"
        "addl 0x195ed34, %eax\n"
        "leal 0x330(%eax), %ecx\n"
        "movl 0xc(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf576cc_000577c3\n"
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 154 */
        "subl -0x24(%ebp), %eax\n" /* frametime */
        "cmpl %edx, -0x24(%ebp)\n" /* frametime */
        "movl $0, %edx\n"
        "cmovnsl %edx, %eax\n"
        /* } scope */
        "movl %eax, 0xc(%ecx)\n" /* line 1642 */
        "testl %eax, %eax\n" /* line 1643 */
        "je .Lf576cc_00057805\n"
        /* } scope */
        ".Lf576cc_000577c3:\n"
        "addl $0x2c, %esp\n" /* line 1648 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf576cc_000577cb:\n"
        "cmpb $0, 0xd(%ecx)\n" /* line 1633 */
        "jne .Lf576cc_0005773d\n"
        "movl 0x2c(%esi), %eax\n" /* pAlias0 */
        "testb $4, %al\n"
        "je .Lf576cc_00057740\n"
        "movl 0x30(%esi), %eax\n" /* line 1634 | pAlias0 */
        "movl %eax, (%esp)\n"
        "calll SND_GetLerpedSlavePercentage\n"
        "fstps -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* volume */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* volume */
        "movl 0x2c(%esi), %eax\n" /* pAlias0 */
        "jmp .Lf576cc_00057745\n"
        ".Lf576cc_00057805:\n"
        "movl 0x4a3ad4(, %ebx, 4), %eax\n" /* line 1645 */
        "movl %eax, 8(%ebp)\n" /* i */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1648 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp AIL_resume_sample\n" /* line 1645 */
    );
}

/* line 1540 */
__attribute__((naked))
void SND_LoadSoundFile(SoundFile *soundFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1540 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1bc, %esp\n"
        /* { scope 1: sound */
        "movl 0x195ed34, %ebx\n" /* line 1546 | datasize */
        "cmpb $0, (%ebx)\n" /* datasize */
        "jne .Lf5781c_00057848\n"
        "movl 8(%ebp), %eax\n" /* line 1548 | soundFile */
        "movl $0, 4(%eax)\n"
        /* } scope */
        ".Lf5781c_0005783d:\n"
        "addl $0x1bc, %esp\n" /* line 1564 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: sound */
        ".Lf5781c_00057848:\n"
        "movl 8(%ebp), %edx\n" /* line 1553 | soundFile */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x219968, 4(%esp)\n" /* "sound/%s" */
        "leal -0x194(%ebp), %esi\n" /* realname, rate */
        "movl %esi, (%esp)\n" /* rate */
        "calll sprintf\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1554 | buffer */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* rate */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 1555 */
        "js .Lf5781c_0005798d\n"
        /* { scope 2: mixinfo */
        /* { scope 3 */
        "leal -0x94(%ebp), %eax\n" /* line 1440 | mixinfo */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll AIL_WAV_info\n"
        "testl %eax, %eax\n"
        "je .Lf5781c_00057951\n"
        "movl -0x8c(%ebp), %edi\n" /* line 1451 */
        "addl $0x24, %edi\n"
        "je .Lf5781c_00057af5\n"
        "movl -0x88(%ebp), %esi\n" /* line 1457 */
        "movl 4(%ebx), %eax\n" /* datasize */
        "cmpl %eax, %esi\n"
        "ja .Lf5781c_000579ac\n"
        "movl -0x84(%ebp), %ecx\n"
        "cmpl 8(%ebx), %ecx\n" /* datasize */
        "jg .Lf5781c_00057ab6\n"
        ".Lf5781c_000578ca:\n"
        "movl -0x80(%ebp), %edx\n"
        "cmpl 0xc(%ebx), %edx\n" /* datasize */
        "jg .Lf5781c_000579b5\n"
        "movl %edi, (%esp)\n" /* line 98 */
        "calll Hunk_AllocNoZeroInternal\n"
        "movl %eax, -0x1a8(%ebp)\n" /* sound */
        "movl %eax, %ebx\n" /* line 1461 | datasize */
        "addl $0x24, %ebx\n" /* datasize */
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* datasize */
        "calll Com_Memcpy\n"
        "movl -0x94(%ebp), %eax\n" /* line 1469 | mixinfo */
        "movl -0x1a8(%ebp), %edx\n" /* sound */
        "movl %eax, (%edx)\n"
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x78(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl %ebx, 4(%edx)\n" /* line 1470 | datasize */
        "movl %ebx, 0x20(%edx)\n" /* line 1471 | datasize */
        "jmp .Lf5781c_0005796b\n"
        ".Lf5781c_00057951:\n"
        "movl %esi, 4(%esp)\n" /* line 1442 */
        "movl $0x219998, (%esp)\n" /* "^1ERROR: Sound file '%s' is in an invalid or corrupted forma" */
        "calll Com_Printf\n"
        "movl $0, -0x1a8(%ebp)\n" /* sound */
        /* } scope */
        /* } scope */
        ".Lf5781c_0005796b:\n"
        "movl -0x1a8(%ebp), %ecx\n" /* line 1562 | sound */
        "movl 8(%ebp), %edx\n" /* soundFile */
        "movl %ecx, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1563 | buffer */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "addl $0x1bc, %esp\n" /* line 1564 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: sound */
        ".Lf5781c_0005798d:\n"
        "movl %esi, 4(%esp)\n" /* line 1557 | rate */
        "movl $0x219974, (%esp)\n" /* "^1ERROR: Sound file '%s' not found
" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %ecx\n" /* line 1558 | soundFile */
        "movl $0, 4(%ecx)\n"
        "jmp .Lf5781c_0005783d\n"
        ".Lf5781c_000579ac:\n"
        "movl -0x84(%ebp), %ecx\n"
        "movl -0x80(%ebp), %edx\n"
        /* { scope 2: mixinfo */
        /* { scope 3 */
        /* { scope 4: valGE, valGE */
        ".Lf5781c_000579b5:\n"
        "movl -0x7c(%ebp), %edi\n" /* line 1488 | samples */
        "cmpl %eax, %esi\n" /* line 1489 */
        "jbe .Lf5781c_000579c4\n"
        ".Lf5781c_000579bc:\n"
        "shrl $1, %esi\n" /* line 1491 */
        "shrl $1, %edi\n" /* line 1492 | samples */
        "cmpl %esi, %eax\n" /* line 1489 */
        "jb .Lf5781c_000579bc\n"
        ".Lf5781c_000579c4:\n"
        "movl 0x195ed34, %eax\n" /* line 1495 */
        "movl 8(%eax), %ebx\n" /* datasize */
        /* { scope 5 */
        "cmpl %ebx, %ecx\n" /* line 154 */
        "cmovnsl %ebx, %ecx\n"
        "movl %ecx, -0x1a4(%ebp)\n" /* valGE */
        /* } scope */
        "movl 0xc(%eax), %eax\n" /* line 1496 */
        /* { scope 5 */
        "cmpl %eax, %edx\n" /* line 154 */
        "cmovnsl %eax, %edx\n"
        "movl %edx, -0x1a0(%ebp)\n" /* valGE */
        /* } scope */
        "movl -0x94(%ebp), %eax\n" /* line 1497 | mixinfo, format */
        /* { scope 5 */
        "subl $1, %edx\n" /* line 673 */
        "je .Lf5781c_00057b14\n"
        "cmpl $0x11, %eax\n" /* line 686 */
        "je .Lf5781c_00057b37\n"
        "cmpl $8, -0x1a4(%ebp)\n" /* line 688 | valGE */
        "jg .Lf5781c_00057acb\n"
        "movl $2, -0x19c(%ebp)\n"
        "movl -0x19c(%ebp), %edx\n"
        /* } scope */
        ".Lf5781c_00057a1a:\n"
        "leal -0x94(%ebp), %eax\n" /* line 1498 | mixinfo */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll AIL_size_processed_digital_audio\n"
        "movl %eax, %ebx\n" /* datasize */
        /* { scope 5 */
        "leal 0x24(%eax), %eax\n" /* line 98 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocNoZeroInternal\n"
        "movl %eax, -0x1a8(%ebp)\n" /* sound */
        /* } scope */
        "movl -0x94(%ebp), %eax\n" /* line 1506 | mixinfo */
        "movl -0x1a8(%ebp), %ecx\n" /* sound */
        "movl %eax, (%ecx)\n"
        "movl %ecx, %edx\n" /* line 1507 */
        "addl $0x24, %edx\n"
        "movl %edx, 4(%ecx)\n"
        "movl %ebx, 8(%ecx)\n" /* line 1508 | datasize */
        "movl %esi, 0xc(%ecx)\n" /* line 1509 | rate */
        "movl -0x1a4(%ebp), %eax\n" /* line 1510 | valGE */
        "movl %eax, 0x10(%ecx)\n"
        "movl -0x1a0(%ebp), %eax\n" /* line 1511 | valGE */
        "movl %eax, 0x14(%ecx)\n"
        "movl %edi, 0x18(%ecx)\n" /* line 1512 | samples */
        "movl -0x78(%ebp), %eax\n" /* line 1513 */
        "movl %eax, 0x1c(%ecx)\n"
        "movl %edx, 0x20(%ecx)\n" /* line 1514 */
        "leal -0x94(%ebp), %ecx\n" /* line 1516 | mixinfo */
        "movl %ecx, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl -0x19c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* rate */
        "movl %ebx, 4(%esp)\n" /* datasize */
        "movl %edx, (%esp)\n"
        "calll AIL_process_digital_audio\n"
        "jmp .Lf5781c_0005796b\n"
        /* } scope */
        ".Lf5781c_00057ab6:\n"
        "cmpl $0x11, -0x94(%ebp)\n" /* line 1457 | mixinfo */
        "je .Lf5781c_000578ca\n"
        "movl -0x80(%ebp), %edx\n"
        "jmp .Lf5781c_000579b5\n"
        /* { scope 4: valGE, valGE */
        /* { scope 5 */
        ".Lf5781c_00057acb:\n"
        "movl $3, -0x19c(%ebp)\n" /* line 690 */
        "cmpl $0x10, -0x1a4(%ebp)\n" /* valGE */
        "movl $0xa, %eax\n"
        "cmovlel -0x19c(%ebp), %eax\n"
        "movl %eax, -0x19c(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf5781c_00057a1a\n"
        /* } scope */
        /* } scope */
        ".Lf5781c_00057af5:\n"
        "movl %esi, 4(%esp)\n" /* line 1453 */
        "movl $0x2199d8, (%esp)\n" /* "^1ERROR: Sound file '%s' is zero length, invalid
" */
        "calll Com_Printf\n"
        "movl $0, -0x1a8(%ebp)\n" /* sound */
        "jmp .Lf5781c_0005796b\n"
        /* { scope 4: valGE, valGE */
        /* { scope 5 */
        ".Lf5781c_00057b14:\n"
        "cmpl $0x11, %eax\n" /* line 675 */
        "je .Lf5781c_00057b6c\n"
        "cmpl $8, -0x1a4(%ebp)\n" /* line 677 | valGE */
        "jg .Lf5781c_00057b4c\n"
        "movl $0, -0x19c(%ebp)\n"
        "movl -0x19c(%ebp), %edx\n"
        "jmp .Lf5781c_00057a1a\n"
        ".Lf5781c_00057b37:\n"
        "movl $7, -0x19c(%ebp)\n" /* line 686 */
        "movl -0x19c(%ebp), %edx\n"
        "jmp .Lf5781c_00057a1a\n"
        ".Lf5781c_00057b4c:\n"
        "cmpl $0x10, -0x1a4(%ebp)\n" /* line 679 | valGE */
        "movl $8, %eax\n"
        "cmovlel -0x1a0(%ebp), %eax\n" /* valGE */
        "movl %eax, -0x19c(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf5781c_00057a1a\n"
        ".Lf5781c_00057b6c:\n"
        "movl $5, -0x19c(%ebp)\n" /* line 675 */
        "movl -0x19c(%ebp), %edx\n"
        "jmp .Lf5781c_00057a1a\n"
    );
}

/* line 698 */
__attribute__((naked))
int SND_StartAlias2DSample(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int *pChannel, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 698 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 0x30(%ebp), %ebx\n" /* pChannel */
        "movzbl 0x2c(%ebp), %eax\n" /* master */
        "movb %al, -0x31(%ebp)\n" /* master */
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 715 | pAlias0 */
        "movl 0x2c(%edx), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* entnum */
        "movl %eax, (%esp)\n"
        "calll SND_FindFree2DChannel\n"
        "movl %eax, -0x2c(%ebp)\n" /* index */
        "testl %ebx, %ebx\n" /* line 716 | start_msec */
        "je .Lf57b82_00057bbe\n"
        "movl %eax, (%ebx)\n" /* line 717 | start_msec */
        ".Lf57b82_00057bbe:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 718 | index */
        "testl %eax, %eax\n"
        "js .Lf57b82_00057e87\n"
        "movl -0x2c(%ebp), %edx\n" /* line 722 | index */
        "movl 0x4a3ad4(, %edx, 4), %esi\n" /* handle */
        "movl 8(%ebp), %eax\n" /* line 723 | pAlias0 */
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileMem\n"
        "movl %eax, %edi\n" /* sound */
        "movl %esi, (%esp)\n" /* line 726 | handle */
        "calll AIL_init_sample\n"
        "movl 0x10(%edi), %edx\n" /* line 728 | sound, bits */
        "movl (%edi), %eax\n" /* sound, format */
        /* { scope 2 */
        "cmpl $1, 0x14(%edi)\n" /* line 673 */
        "je .Lf57b82_00057e94\n"
        "cmpl $0x11, %eax\n" /* line 686 */
        "je .Lf57b82_00057ebe\n"
        "cmpl $8, %edx\n" /* line 688 */
        "jg .Lf57b82_00057ea9\n"
        "movl $2, %ecx\n"
        /* } scope */
        ".Lf57b82_00057c0e:\n"
        "movl $0, 8(%esp)\n" /* line 728 */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_sample_type\n"
        "movl 8(%edi), %eax\n" /* line 729 | sound */
        "movl %eax, 8(%esp)\n"
        "movl 4(%edi), %eax\n" /* sound */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_sample_address\n"
        "movl 0x1c(%edi), %eax\n" /* line 730 | sound */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_sample_adpcm_block_size\n"
        "movl 0xc(%edi), %edx\n" /* line 428 */
        "testl %edx, %edx\n"
        "js .Lf57b82_00057ef1\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf57b82_00057c56:\n"
        "mulss 0x1c(%ebp), %xmm0\n" /* pitch */
        "movl 0x195ed34, %ebx\n"
        "mulss 0x10(%ebx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll AIL_set_sample_playback_rate\n"
        "movl 8(%ebp), %edx\n" /* line 733 | pAlias0 */
        "movl 0x2c(%edx), %ecx\n"
        "movss 0x18(%ebp), %xmm1\n" /* volume */
        "mulss 0x24(%ebx), %xmm1\n" /* start_msec */
        "movl 0x254(%ebx), %edx\n" /* start_msec */
        "movl %ecx, %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "mulss (%edx, %eax, 4), %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 734 */
        "ucomiss 0x274(%ebx), %xmm0\n" /* start_msec */
        "jp .Lf57b82_00057cc3\n"
        "je .Lf57b82_00057cd2\n"
        ".Lf57b82_00057cc3:\n"
        "cmpb $0, -0x31(%ebp)\n" /* master */
        "jne .Lf57b82_00057cd2\n"
        "andb $4, %cl\n"
        "jne .Lf57b82_00057f49\n"
        ".Lf57b82_00057cd2:\n"
        "cmpl $1, 0x14(%edi)\n" /* line 737 | sound */
        "je .Lf57b82_00057ee4\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        ".Lf57b82_00057ce4:\n"
        "mulss %xmm1, %xmm0\n" /* line 738 */
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_sample_volume_levels\n"
        "movl 8(%ebp), %edx\n" /* line 740 | pAlias0 */
        "movzbl 0x2c(%edx), %eax\n"
        "andb $1, %al\n"
        "xorb $1, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_sample_loop_count\n"
        "movl 0x195ed40, %eax\n" /* line 196 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf57b82_00057ed2\n"
        "movl 8(%ebp), %eax\n" /* pAlias0 */
        "testb $0x10, 0x2c(%eax)\n"
        "jne .Lf57b82_00057ed2\n"
        "movl 0x195ed34, %eax\n"
        "movl 0x2d8(%eax), %eax\n"
        "movl 0x10(%eax), %eax\n"
        ".Lf57b82_00057d42:\n"
        "movl %eax, 8(%esp)\n" /* line 742 */
        "movl $0x3f800000, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_sample_reverb_levels\n"
        "movl $0, 8(%esp)\n" /* line 744 */
        "leal -0x1c(%ebp), %eax\n" /* total_msec */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_sample_ms_position\n"
        "movl -0x1c(%ebp), %eax\n" /* line 745 | total_msec */
        "cmpl 0x20(%ebp), %eax\n" /* timeshift */
        "jle .Lf57b82_00057e87\n"
        "movss 0x24(%ebp), %xmm0\n" /* line 748 | fraction */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf57b82_00057f07\n"
        "jp .Lf57b82_00057f07\n"
        "movl 0x20(%ebp), %ebx\n" /* timeshift, start_msec */
        ".Lf57b82_00057d94:\n"
        "testl %ebx, %ebx\n" /* line 753 | start_msec */
        "movl $0, %eax\n"
        "cmovel 0x28(%ebp), %eax\n" /* startDelay */
        "movl %eax, 0x28(%ebp)\n" /* startDelay */
        "movl %ebx, 4(%esp)\n" /* line 756 | start_msec */
        "movl %esi, (%esp)\n" /* handle */
        "calll AIL_set_sample_ms_position\n"
        "movl 0x28(%ebp), %eax\n" /* line 757 | startDelay */
        "testl %eax, %eax\n"
        "jne .Lf57b82_00057ed9\n"
        "movl 0x195ed34, %edx\n"
        "cmpb $0, 2(%edx)\n"
        "je .Lf57b82_00057ddf\n"
        "movl 8(%ebp), %eax\n" /* pAlias0 */
        "movl 0x2c(%eax), %ecx\n"
        "movl %ecx, %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "cmpb $0, 0x2e7(%eax, %edx)\n"
        "jne .Lf57b82_00057ded\n"
        ".Lf57b82_00057ddf:\n"
        "movl %esi, (%esp)\n" /* line 758 | handle */
        "calll AIL_resume_sample\n"
        "movl 8(%ebp), %edx\n" /* pAlias0 */
        "movl 0x2c(%edx), %ecx\n"
        ".Lf57b82_00057ded:\n"
        "movl 0x28(%ebp), %edx\n" /* line 760 | startDelay */
        "addl -0x1c(%ebp), %edx\n" /* total_msec */
        "movl %edx, -0x1c(%ebp)\n" /* total_msec */
        "andb $1, %cl\n" /* line 761 */
        "je .Lf57b82_00057e04\n"
        "xorl %edx, %edx\n" /* line 762 */
        "movl $0, -0x1c(%ebp)\n" /* total_msec */
        ".Lf57b82_00057e04:\n"
        "movl 0x34(%ebp), %eax\n" /* line 764 | system */
        "movl %eax, 0x38(%esp)\n"
        "movzbl -0x31(%ebp), %eax\n" /* master */
        "movl %eax, 0x34(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* startDelay */
        "movl %eax, 0x30(%esp)\n"
        "movl %ebx, 0x2c(%esp)\n" /* start_msec */
        "movl %edx, 0x28(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* sound */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* sound */
        "movl %eax, 0x20(%esp)\n"
        "movss 0x1c(%ebp), %xmm0\n" /* pitch */
        "movss %xmm0, 0x1c(%esp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* volume */
        "movss %xmm0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* lerp */
        "movss %xmm0, 0x10(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %edx\n" /* pAlias0 */
        "movl %edx, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* entnum */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %edx\n" /* index */
        "movl %edx, (%esp)\n"
        "calll SND_SetChannelInfo\n"
        "movl -0x1c(%ebp), %eax\n" /* line 765 | total_msec */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 766 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf57b82_00057e87:\n"
        "xorl %eax, %eax\n" /* line 765 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 766 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf57b82_00057e94:\n"
        "cmpl $0x11, %eax\n" /* line 675 */
        "je .Lf57b82_00057ec8\n"
        "cmpl $8, %edx\n" /* line 677 */
        "jg .Lf57b82_00057f34\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf57b82_00057c0e\n"
        ".Lf57b82_00057ea9:\n"
        "movl $3, %ecx\n" /* line 690 */
        "cmpl $0x10, %edx\n"
        "movl $0xa, %eax\n"
        "cmovgl %eax, %ecx\n"
        "jmp .Lf57b82_00057c0e\n"
        ".Lf57b82_00057ebe:\n"
        "movl $7, %ecx\n" /* line 686 */
        "jmp .Lf57b82_00057c0e\n"
        ".Lf57b82_00057ec8:\n"
        "movl $5, %ecx\n" /* line 675 */
        "jmp .Lf57b82_00057c0e\n"
        /* } scope */
        ".Lf57b82_00057ed2:\n"
        "xorl %eax, %eax\n" /* line 196 */
        "jmp .Lf57b82_00057d42\n"
        ".Lf57b82_00057ed9:\n"
        "movl 8(%ebp), %eax\n" /* pAlias0 */
        "movl 0x2c(%eax), %ecx\n"
        "jmp .Lf57b82_00057ded\n"
        ".Lf57b82_00057ee4:\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 737 | 0.5f */
        "jmp .Lf57b82_00057ce4\n"
        ".Lf57b82_00057ef1:\n"
        "movl %edx, %eax\n" /* line 428 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf57b82_00057c56\n"
        ".Lf57b82_00057f07:\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x24(%ebp), %xmm0\n" /* fraction */
        "movss %xmm0, 0x24(%ebp)\n" /* fraction */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x3c(%ebp)\n"
        "cvttss2si -0x3c(%ebp), %ebx\n"
        "jmp .Lf57b82_00057d94\n"
        /* { scope 2 */
        ".Lf57b82_00057f34:\n"
        "movl $1, %ecx\n" /* line 679 */
        "cmpl $0x10, %edx\n"
        "movl $8, %eax\n"
        "cmovgl %eax, %ecx\n"
        "jmp .Lf57b82_00057c0e\n"
        /* } scope */
        ".Lf57b82_00057f49:\n"
        "movl 8(%ebp), %edx\n" /* line 735 | pAlias0 */
        "movl 0x30(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "calll SND_GetLerpedSlavePercentage\n"
        "fstps -0x30(%ebp)\n"
        "movss -0x58(%ebp), %xmm1\n"
        "mulss -0x30(%ebp), %xmm1\n"
        "jmp .Lf57b82_00057cd2\n"
    );
}

/* line 769 */
__attribute__((naked))
int SND_StartAlias3DSample(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int *pChannel, snd_alias_system_t system)
{
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
        "movl 0x4a3ba8(, %edx, 4), %esi\n" /* handle */
        "movl 8(%ebp), %eax\n" /* line 796 | pAlias0 */
        "movl %eax, (%esp)\n"
        "calll Com_GetSoundFileMem\n"
        "movl %eax, -0x24(%ebp)\n" /* sound */
        "movss 0x2ed5d0, %xmm1\n" /* line 798 | 1.0f */
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
        "movl 0x195ed34, %ebx\n" /* total_msec */
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
        "movl 0x195ed34, %ebx\n"
        "mulss 0x10(%ebx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
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
        "movl 0x195ed34, %eax\n"
        "mulss 0x10(%eax), %xmm1\n"
        "cvtsi2ssl %edi, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %ebx\n"
        "cmpl 0x24(%ebp), %ebx\n" /* line 824 | timeshift, total_msec */
        "jle .Lf57f6e_000582af\n"
        "movss 0x28(%ebp), %xmm0\n" /* line 827 | fraction */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
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
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
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
        "movl 0x195ed34, %ecx\n"
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
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
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
}

/* line 848 */
__attribute__((naked))
int SND_StartAliasStreamOnChannel(const snd_alias_t *pAlias0, const snd_alias_t *pAlias1, float lerp, int entnum, const vec_t *org, float volume, float pitch, int timeshift, float fraction, int startDelay, int master, int index, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 848 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1ac, %esp\n"
        "movzbl 0x30(%ebp), %eax\n" /* master */
        "movb %al, -0x145(%ebp)\n" /* master */
        /* { scope 1: to */
        "movl 8(%ebp), %edx\n" /* line 869 | pAlias0 */
        "movl 0xc(%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf583ba_000587a6\n"
        "movl 0x34(%ebp), %ecx\n" /* line 875 | index */
        "subl $0x20, %ecx\n"
        "movl %ecx, -0x144(%ebp)\n"
        "movl $0x4a3c20, %ebx\n"
        "movl 0x4a3c28(, %ecx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf583ba_00058412\n"
        "movl %eax, (%esp)\n" /* line 877 */
        "calll AIL_close_stream\n"
        "movl -0x144(%ebp), %eax\n" /* line 878 */
        "movl $0, 8(%ebx, %eax, 4)\n"
        ".Lf583ba_00058412:\n"
        "movl 8(%ebp), %edx\n" /* line 882 | pAlias0 */
        "movl %edx, (%esp)\n"
        "calll Com_GetSoundFileName\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x219968, 4(%esp)\n" /* "sound/%s" */
        "leal -0x124(%ebp), %esi\n" /* realname, start_msec */
        "movl %esi, (%esp)\n" /* start_msec */
        "calll sprintf\n"
        "movl mss_q3fs, %eax\n" /* line 885 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf583ba_0005877e\n"
        ".Lf583ba_00058446:\n"
        "movl %esi, (%esp)\n" /* line 895 | start_msec */
        "calll FS_ShortOSFilePath\n"
        "movl $0, 8(%esp)\n" /* line 897 */
        "movl %eax, 4(%esp)\n"
        "movl milesGlob, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_open_stream\n"
        "movl %eax, %edi\n" /* handle */
        "testl %eax, %eax\n" /* line 900 */
        "je .Lf583ba_0005894f\n"
        ".Lf583ba_00058471:\n"
        "movl -0x144(%ebp), %eax\n" /* line 905 */
        "movl %edi, 8(%ebx, %eax, 4)\n" /* handle */
        "movl $0, 0x10(%esp)\n" /* line 907 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* filetype */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_stream_info\n"
        "movl -0x24(%ebp), %eax\n" /* line 908 | filetype */
        "andl $2, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %edx, %edx\n"
        "addl $2, %edx\n"
        "movl %edx, -0x134(%ebp)\n" /* srcChannelCount */
        "movl %edi, (%esp)\n" /* line 910 | handle */
        "calll AIL_stream_playback_rate\n"
        "movl %eax, -0x138(%ebp)\n" /* baserate */
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "mulss 0x20(%ebp), %xmm0\n" /* pitch */
        "movl 0x195ed34, %ebx\n"
        "mulss 0x10(%ebx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x14c(%ebp)\n"
        "cvttss2si -0x14c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll AIL_set_stream_playback_rate\n"
        "movl 8(%ebp), %eax\n" /* line 912 | pAlias0 */
        "movl 0x2c(%eax), %ecx\n"
        "movss 0x24(%ebx), %xmm1\n"
        "mulss 0x1c(%ebp), %xmm1\n" /* volume */
        "movl 0x254(%ebx), %edx\n"
        "movl %ecx, %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "mulss (%edx, %eax, 4), %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 913 */
        "ucomiss 0x274(%ebx), %xmm0\n"
        "jp .Lf583ba_0005853b\n"
        "je .Lf583ba_00058548\n"
        ".Lf583ba_0005853b:\n"
        "cmpb $0, -0x145(%ebp)\n" /* master */
        "je .Lf583ba_000587e4\n"
        ".Lf583ba_00058548:\n"
        "cmpl $1, -0x134(%ebp)\n" /* line 916 | srcChannelCount */
        "je .Lf583ba_000588fa\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        ".Lf583ba_0005855d:\n"
        "movss %xmm0, -0x20(%ebp)\n" /* pan */
        "mulss %xmm1, %xmm0\n" /* line 917 */
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_set_stream_volume_levels\n"
        "movl 8(%ebp), %ecx\n" /* line 919 | pAlias0 */
        "movzbl 0x2c(%ecx), %eax\n"
        "andb $1, %al\n"
        "xorb $1, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_set_stream_loop_count\n"
        "movl 0x195ed40, %eax\n" /* line 196 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf583ba_000585ae\n"
        "movl 8(%ebp), %ebx\n" /* pAlias0 */
        "testb $0x10, 0x2c(%ebx)\n"
        "je .Lf583ba_000587d1\n"
        ".Lf583ba_000585ae:\n"
        "xorl %eax, %eax\n"
        ".Lf583ba_000585b0:\n"
        "movl %eax, 8(%esp)\n" /* line 921 */
        "movl $0x3f800000, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_set_stream_reverb_levels\n"
        "movl $0, 8(%esp)\n" /* line 923 */
        "leal -0x1c(%ebp), %eax\n" /* total_msec */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_stream_ms_position\n"
        "movl -0x1c(%ebp), %eax\n" /* line 924 | total_msec */
        "cmpl 0x24(%ebp), %eax\n" /* timeshift */
        "jle .Lf583ba_000587c4\n"
        "testl %eax, %eax\n" /* line 927 */
        "je .Lf583ba_00058907\n"
        "movss 0x28(%ebp), %xmm0\n" /* line 933 | fraction */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf583ba_0005891c\n"
        "jp .Lf583ba_0005891c\n"
        "movl 0x24(%ebp), %esi\n" /* timeshift, start_msec */
        ".Lf583ba_0005860a:\n"
        "testl %esi, %esi\n" /* line 938 | start_msec */
        "movl $0, %eax\n"
        "cmovel 0x2c(%ebp), %eax\n" /* startDelay */
        "movl %eax, 0x2c(%ebp)\n" /* startDelay */
        "movl %esi, 4(%esp)\n" /* line 941 | start_msec */
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_set_stream_ms_position\n"
        "movl 0x2c(%ebp), %eax\n" /* line 942 | startDelay */
        "testl %eax, %eax\n"
        "jne .Lf583ba_0005881e\n"
        "movl 0x195ed34, %eax\n"
        "cmpb $0, 2(%eax)\n"
        "je .Lf583ba_00058656\n"
        "movl %eax, %ebx\n"
        "movl 8(%ebp), %ecx\n" /* pAlias0 */
        "movl 0x2c(%ecx), %edx\n"
        "movl %edx, %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "cmpb $0, 0x2e7(%eax, %ebx)\n"
        "jne .Lf583ba_0005866c\n"
        ".Lf583ba_00058656:\n"
        "movl $0, 4(%esp)\n" /* line 943 */
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_pause_stream\n"
        "movl 8(%ebp), %eax\n" /* pAlias0 */
        "movl 0x2c(%eax), %edx\n"
        ".Lf583ba_0005866c:\n"
        "movl 0x2c(%ebp), %ebx\n" /* line 945 | startDelay */
        "addl %ebx, -0x1c(%ebp)\n" /* total_msec */
        "xorl %eax, %eax\n" /* line 947 */
        "andb $1, %dl\n"
        "cmovel -0x1c(%ebp), %eax\n" /* total_msec */
        "movl %eax, -0x1c(%ebp)\n" /* total_msec */
        "movl 0x34(%ebp), %eax\n" /* line 949 | index */
        "leal (%eax, %eax, 4), %ebx\n"
        "shll $4, %ebx\n"
        "movl 0x195ed34, %edx\n"
        "movl %edx, -0x158(%ebp)\n"
        "leal 0x360(%ebx, %edx), %ecx\n"
        "movl %ecx, -0x154(%ebp)\n"
        "addl $4, %ecx\n"
        "movl %ecx, -0x130(%ebp)\n" /* to */
        /* { scope 2 */
        "movl 0x18(%ebp), %edx\n" /* line 199 | org */
        "movl (%edx), %eax\n"
        "movl -0x154(%ebp), %ecx\n"
        "movl %eax, 4(%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl -0x130(%ebp), %edx\n" /* to */
        "movl %eax, 4(%edx)\n"
        "movl 0x18(%ebp), %ecx\n" /* line 201 | org */
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x38(%ebp), %eax\n" /* line 951 | system */
        "movl %eax, 0x38(%esp)\n"
        "movzbl -0x145(%ebp), %eax\n" /* master */
        "movl %eax, 0x34(%esp)\n"
        "movl 0x2c(%ebp), %edx\n" /* startDelay */
        "movl %edx, 0x30(%esp)\n"
        "movl %esi, 0x2c(%esp)\n" /* start_msec */
        "movl -0x1c(%ebp), %eax\n" /* total_msec */
        "movl %eax, 0x28(%esp)\n"
        "movl -0x138(%ebp), %ecx\n" /* baserate */
        "movl %ecx, 0x24(%esp)\n"
        "movl -0x134(%ebp), %eax\n" /* srcChannelCount */
        "movl %eax, 0x20(%esp)\n"
        "movss 0x20(%ebp), %xmm0\n" /* pitch */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* volume */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* org */
        "movl %eax, 0x14(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* lerp */
        "movss %xmm0, 0x10(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pAlias1 */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %edx\n" /* pAlias0 */
        "movl %edx, 8(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* entnum */
        "movl %ecx, 4(%esp)\n"
        "movl 0x34(%ebp), %eax\n" /* index */
        "movl %eax, (%esp)\n"
        "calll SND_SetChannelInfo\n"
        "movl -0x158(%ebp), %edx\n" /* line 952 */
        "movl 0x358(%ebx, %edx), %eax\n"
        "movl 0x2c(%eax), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_IsAliasChannel3D\n"
        "testb %al, %al\n"
        "jne .Lf583ba_00058829\n"
        "movl -0x1c(%ebp), %eax\n" /* line 980 | total_msec */
        /* } scope */
        ".Lf583ba_00058773:\n"
        "addl $0x1ac, %esp\n" /* line 981 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: to */
        ".Lf583ba_0005877e:\n"
        "movl $0, 8(%esp)\n" /* line 888 */
        "movl %esi, 4(%esp)\n" /* start_msec */
        "movl milesGlob, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_open_stream\n"
        "movl %eax, %edi\n" /* handle */
        "testl %eax, %eax\n" /* line 893 */
        "jne .Lf583ba_00058471\n"
        "jmp .Lf583ba_00058446\n"
        ".Lf583ba_000587a6:\n"
        "movl (%edx), %ebx\n" /* line 871 */
        "movl %edx, (%esp)\n"
        "calll Com_GetSoundFileName\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x219a0c, (%esp)\n" /* "Tried to play streamed sound '%s' from alias '%s', but it wa" */
        "calll Com_DPrintf\n"
        ".Lf583ba_000587c4:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf583ba_000587c6:\n"
        "addl $0x1ac, %esp\n" /* line 981 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: to */
        ".Lf583ba_000587d1:\n"
        "movl 0x195ed34, %eax\n" /* line 196 */
        "movl 0x2d8(%eax), %eax\n"
        "movl 0x10(%eax), %eax\n"
        "jmp .Lf583ba_000585b0\n"
        ".Lf583ba_000587e4:\n"
        "andb $4, %cl\n" /* line 913 */
        "je .Lf583ba_00058548\n"
        "movl 8(%ebp), %edx\n" /* line 914 | pAlias0 */
        "movl 0x30(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x168(%ebp)\n"
        "calll SND_GetLerpedSlavePercentage\n"
        "fstps -0x140(%ebp)\n"
        "movss -0x168(%ebp), %xmm1\n"
        "mulss -0x140(%ebp), %xmm1\n"
        "jmp .Lf583ba_00058548\n"
        ".Lf583ba_0005881e:\n"
        "movl 8(%ebp), %ecx\n" /* pAlias0 */
        "movl 0x2c(%ecx), %edx\n"
        "jmp .Lf583ba_0005866c\n"
        ".Lf583ba_00058829:\n"
        "leal -0x20(%ebp), %ecx\n" /* line 954 | pan */
        "leal 0x1c(%ebp), %edx\n" /* volume */
        "movl -0x144(%ebp), %eax\n"
        "calll MSS_SpatializeStream\n"
        "movl %edi, (%esp)\n" /* line 957 | handle */
        "calll AIL_is_3D_stream\n"
        "testl %eax, %eax\n"
        "jne .Lf583ba_00058978\n"
        ".Lf583ba_0005884a:\n"
        "movl 8(%ebp), %edx\n" /* line 974 | pAlias0 */
        "movl 0x2c(%edx), %ecx\n"
        "movl 0x195ed34, %ebx\n"
        "movss 0x24(%ebx), %xmm2\n"
        "mulss 0x1c(%ebp), %xmm2\n" /* volume */
        "movl 0x254(%ebx), %eax\n"
        "movl %ecx, %edx\n"
        "andl $0x780, %edx\n"
        "sarl $7, %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "mulss (%eax, %edx, 4), %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 975 */
        "ucomiss 0x274(%ebx), %xmm0\n"
        "jp .Lf583ba_00058888\n"
        "je .Lf583ba_000588c2\n"
        ".Lf583ba_00058888:\n"
        "cmpb $0, -0x145(%ebp)\n" /* master */
        "jne .Lf583ba_000588c2\n"
        "andb $4, %cl\n"
        "je .Lf583ba_000588c2\n"
        "movl 8(%ebp), %edx\n" /* line 976 | pAlias0 */
        "movl 0x30(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x178(%ebp)\n"
        "calll SND_GetLerpedSlavePercentage\n"
        "fstps -0x13c(%ebp)\n"
        "movss -0x178(%ebp), %xmm2\n"
        "mulss -0x13c(%ebp), %xmm2\n"
        ".Lf583ba_000588c2:\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 978 | pan */
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_set_stream_volume_levels\n"
        "movl -0x1c(%ebp), %eax\n" /* line 980 | total_msec */
        "jmp .Lf583ba_00058773\n"
        ".Lf583ba_000588fa:\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 916 | 0.5f */
        "jmp .Lf583ba_0005855d\n"
        ".Lf583ba_00058907:\n"
        "movl %esi, 4(%esp)\n" /* line 929 | start_msec */
        "movl $0x2199d8, (%esp)\n" /* "^1ERROR: Sound file '%s' is zero length, invalid
" */
        "calll Com_Printf\n"
        "jmp .Lf583ba_000587c4\n"
        ".Lf583ba_0005891c:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "mulss 0x28(%ebp), %xmm0\n" /* fraction */
        "movss %xmm0, 0x28(%ebp)\n" /* fraction */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x150(%ebp)\n"
        "cvttss2si -0x150(%ebp), %esi\n"
        "jmp .Lf583ba_0005860a\n"
        ".Lf583ba_0005894f:\n"
        "calll AIL_last_error\n" /* line 902 */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* pAlias0 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* start_msec */
        "movl $0x219a64, (%esp)\n" /* "Couldn't play stream '%s' from alias '%s' - %s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf583ba_000587c6\n"
        /* { scope 2 */
        ".Lf583ba_00058978:\n"
        "movl -0x130(%ebp), %ecx\n" /* line 963 | to */
        "movl %ecx, (%esp)\n"
        "calll SND_GetListenerIndexNearestToOrigin\n"
        "leal (, %eax, 8), %edx\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl -0x158(%ebp), %ebx\n"
        "leal 0x2f0(%eax, %ebx), %edx\n"
        "leal 4(%edx), %ecx\n"
        /* { scope 3 */
        "movl -0x154(%ebp), %ebx\n" /* line 248 */
        "movss 4(%ebx), %xmm2\n"
        "subss 4(%edx), %xmm2\n"
        "movl -0x130(%ebp), %ebx\n" /* line 249 | to */
        "movss 4(%ebx), %xmm3\n"
        "subss 4(%ecx), %xmm3\n"
        "movss 8(%ebx), %xmm4\n" /* line 250 */
        "subss 8(%ecx), %xmm4\n"
        "leal 0x10(%edx), %ecx\n"
        "movl -0x158(%ebp), %ebx\n"
        "leal 0x2fc(%eax, %ebx), %esi\n"
        "leal 0x10(%esi), %ebx\n"
        "movl %ebx, -0x12c(%ebp)\n"
        "movl -0x158(%ebp), %ebx\n"
        "leal 0x308(%eax, %ebx), %eax\n"
        "leal 0x10(%eax), %ebx\n"
        /* } scope */
        "movaps %xmm2, %xmm0\n" /* line 969 */
        "mulss 0x10(%edx), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x10(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 8(%ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "mulss 0x10(%esi), %xmm2\n" /* start_msec */
        "movl -0x12c(%ebp), %eax\n"
        "mulss 4(%eax), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss 8(%eax), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "xorps 0x2f0380, %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll AIL_set_3D_stream_position\n"
        "movl $0x3f000000, -0x20(%ebp)\n" /* line 970 | pan */
        "jmp .Lf583ba_0005884a\n"
    );
}

/* line 1658 */
__attribute__((naked))
void SND_Update3DChannel(int i, int frametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1658 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1670 | i */
        "leal (%eax, %eax, 4), %edx\n"
        "shll $4, %edx\n"
        "movl 0x195ed34, %eax\n"
        "leal (%edx, %eax), %ecx\n"
        "leal 0x370(%ecx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "cmpb $0, 0xc(%eax)\n"
        "jne .Lf58a80_00058c53\n"
        "leal 0x350(%ecx), %eax\n" /* line 1673 */
        "movl 8(%eax), %edi\n" /* pAlias0 */
        "movl 0xc(%eax), %esi\n" /* line 1674 | pAlias1 */
        "testl %edi, %edi\n" /* line 1676 | pAlias0 */
        "je .Lf58a80_00058c53\n"
        "testl %esi, %esi\n" /* pAlias1 */
        "je .Lf58a80_00058c53\n"
        "movss 0x10(%eax), %xmm0\n" /* line 1681 */
        "movss %xmm0, -0x30(%ebp)\n" /* lerp */
        "movss 0x348(%ecx), %xmm1\n" /* line 1682 */
        "movss %xmm1, -0x2c(%ebp)\n" /* volume */
        "leal -0x24(%ebp), %ebx\n" /* line 1684 | org */
        "movl %ebx, 8(%esp)\n"
        "movl 0x195ed34, %eax\n"
        "leal 0x370(%edx, %eax), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x334(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_GetCurrent3DPosition\n"
        "movl %ebx, 4(%esp)\n" /* line 1685 */
        "movl 8(%ebp), %edx\n" /* i */
        "movl %edx, (%esp)\n"
        "calll SND_Set3DPosition\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 1687 | 1.0f */
        "subss -0x30(%ebp), %xmm0\n" /* lerp */
        "movaps %xmm0, %xmm1\n"
        "mulss 0x24(%edi), %xmm1\n" /* pAlias0 */
        "movss %xmm1, -0x34(%ebp)\n" /* fDistMin */
        "movss -0x30(%ebp), %xmm1\n" /* lerp */
        "mulss 0x24(%esi), %xmm1\n" /* pAlias1 */
        "addss -0x34(%ebp), %xmm1\n" /* fDistMin */
        "movss %xmm1, -0x34(%ebp)\n" /* fDistMin */
        "mulss 0x28(%edi), %xmm0\n" /* line 1688 | pAlias0 */
        "movss -0x30(%ebp), %xmm1\n" /* lerp */
        "mulss 0x28(%esi), %xmm1\n" /* pAlias1 */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* lerp */
        "movl %ebx, (%esp)\n" /* line 1689 */
        "calll SND_GetListenerIndexNearestToOrigin\n"
        "leal (, %eax, 8), %edx\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x195ed34, %edx\n"
        "leal 0x2f4(%eax, %edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Vec3Distance\n"
        "movss -0x30(%ebp), %xmm0\n" /* lerp */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x34(%ebp), %xmm1\n" /* fDistMin */
        "movss %xmm1, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movl 0x40(%edi), %eax\n" /* pAlias0 */
        "movl %eax, (%esp)\n"
        "calll SND_Attenuate\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* volume */
        "mulss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* volume */
        "pxor %xmm0, %xmm0\n" /* line 1691 */
        "movl 0x195ed34, %eax\n"
        "ucomiss 0x274(%eax), %xmm0\n"
        "jp .Lf58a80_00058bd2\n"
        "je .Lf58a80_00058bdf\n"
        ".Lf58a80_00058bd2:\n"
        "movl -0x40(%ebp), %edx\n"
        "cmpb $0, 0xd(%edx)\n"
        "je .Lf58a80_00058c75\n"
        ".Lf58a80_00058bdf:\n"
        "movl 0x2c(%edi), %eax\n" /* pAlias0 */
        ".Lf58a80_00058be2:\n"
        "movss -0x2c(%ebp), %xmm1\n" /* volume */
        ".Lf58a80_00058be7:\n"
        "movl 0x195ed34, %ebx\n" /* line 1049 */
        "movl 0x254(%ebx), %edx\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "mulss (%edx, %eax, 4), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n" /* volume */
        "mulss 0x24(%ebx), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* i */
        "movl 0x4a3ba8(, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_sample_volume\n"
        "movl 8(%ebp), %edx\n" /* line 1698 | i */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "leal 0x330(%eax, %ebx), %ecx\n"
        "movl 0xc(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf58a80_00058c53\n"
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 154 */
        "subl 0xc(%ebp), %eax\n" /* frametime */
        "cmpl %edx, 0xc(%ebp)\n" /* frametime */
        "movl $0, %edx\n"
        "cmovnsl %edx, %eax\n"
        /* } scope */
        "movl %eax, 0xc(%ecx)\n" /* line 1700 */
        "testl %eax, %eax\n" /* line 1701 */
        "je .Lf58a80_00058c5b\n"
        /* } scope */
        ".Lf58a80_00058c53:\n"
        "addl $0x4c, %esp\n" /* line 1706 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf58a80_00058c5b:\n"
        "movl 8(%ebp), %edx\n" /* line 1703 | i */
        "movl 0x4a3ba8(, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_resume_3D_sample\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1706 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf58a80_00058c75:\n"
        "movl 0x2c(%edi), %eax\n" /* line 1691 | pAlias0 */
        "testb $4, %al\n"
        "je .Lf58a80_00058be2\n"
        "movl 0x30(%edi), %eax\n" /* line 1692 | pAlias0 */
        "movl %eax, (%esp)\n"
        "calll SND_GetLerpedSlavePercentage\n"
        "fstps -0x38(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* volume */
        "mulss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* volume */
        "movl 0x2c(%edi), %eax\n" /* pAlias0 */
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf58a80_00058be7\n"
    );
}

/* line 1214 */
__attribute__((naked))
void SND_Set2DChannelFromSaveInfo(int index, snd_save_2D_sample_t *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1214 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* index */
        "movl 0xc(%ebp), %eax\n" /* info */
        "movss 0xc(%eax), %xmm2\n" /* line 1218 | pan */
        "movl 0x195ed34, %edx\n"
        "movss 8(%eax), %xmm1\n" /* volume */
        "mulss 0x24(%edx), %xmm1\n" /* volume */
        /* { scope 1 */
        "leal (%ecx, %ecx, 4), %eax\n" /* line 1026 */
        "shll $4, %eax\n"
        "cmpl $2, 0x354(%eax, %edx)\n"
        "je .Lf58ca8_00058d0d\n"
        "movaps %xmm2, %xmm0\n" /* line 1029 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl 0x4a3ad4(, %ecx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_volume_levels\n"
        /* } scope */
        "leave\n" /* line 1219 */
        "retl\n"
        /* { scope 1 */
        ".Lf58ca8_00058d0d:\n"
        "movss %xmm1, 8(%esp)\n" /* line 1027 */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x4a3ad4(, %ecx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_sample_volume_levels\n"
        /* } scope */
        "leave\n" /* line 1219 */
        "retl\n"
    );
}

/* line 411 */
__attribute__((naked))
Bool SND_InitDriver(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 411 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0x1020, 8(%esp)\n" /* line 419 */
        "movl $1, 4(%esp)\n"
        "movl $0x219a94, (%esp)\n" /* "mss_q3fs" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, mss_q3fs\n"
        "cmpb $0, 8(%eax)\n" /* line 420 */
        "jne .Lf58d2a_000590f8\n"
        ".Lf58d2a_00058d5e:\n"
        "movl $0x219aa0, (%esp)\n" /* line 424 */
        "calll AIL_set_redist_directory\n"
        "movl $0x75, (%esp)\n" /* line 391 */
        "calll AIL_startup\n"
        "testl %eax, %eax\n" /* line 435 */
        "je .Lf58d2a_000590d1\n"
        "movl $0x1021, 8(%esp)\n" /* line 445 */
        "movl $0x219ae4, 4(%esp)\n" /* "Miles Fast 2D Positional Audio" */
        "movl $0x219b04, (%esp)\n" /* "mss_3d_provider" */
        "calll Dvar_RegisterString\n"
        "movl %eax, mss_3d_provider\n"
        "movl 0x195ed3c, %eax\n" /* line 219 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf58d2a_00058dd0\n"
        "cmpl $0x2c, %eax\n"
        "je .Lf58d2a_000591fc\n"
        "cmpl $0xb, %eax\n"
        "je .Lf58d2a_00059149\n"
        "movl %eax, 4(%esp)\n" /* line 228 */
        "movl $0x219b14, (%esp)\n" /* "invalid value %i for snd_khz, using 22 khz instead
" */
        "calll Com_Printf\n"
        ".Lf58d2a_00058dd0:\n"
        "movl $0x5622, -0x38(%ebp)\n"
        "movl $0x16, -0x30(%ebp)\n"
        "movl $0x5622, -0x2c(%ebp)\n"
        ".Lf58d2a_00058de5:\n"
        "movl 0x195ed38, %eax\n" /* line 235 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl $8, %eax\n"
        "je .Lf58d2a_000591ed\n"
        "cmpl $0x10, %eax\n"
        "je .Lf58d2a_00058e0d\n"
        "movl %eax, 4(%esp)\n" /* line 241 */
        "movl $0x219b48, (%esp)\n" /* "invalid value %i for snd_bits (should be 8 or 16), using 16 " */
        "calll Com_Printf\n"
        ".Lf58d2a_00058e0d:\n"
        "movl $2, %edi\n"
        "movl $0x10, %esi\n"
        ".Lf58d2a_00058e17:\n"
        "movl 0x195ed30, %eax\n" /* line 248 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf58d2a_0005912b\n"
        "movl $0x219b90, %eax\n" /* "stereo" */
        "movl $2, %ebx\n"
        ".Lf58d2a_00058e32:\n"
        "movl %eax, 0xc(%esp)\n" /* line 250 */
        "movl %esi, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x219ba0, (%esp)\n" /* "Attempting %i kHz %i bit %s sound
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
        "movl 0x195ed34, %ecx\n" /* line 267 */
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
        "movl $0x219bec, (%esp)\n" /* line 294 */
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
        "movl $0x2182fc, (%esp)\n" /* "  %s
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
        "movl $0x219ae4, 4(%esp)\n" /* line 306 */
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
        "movl $0, 0x4a3b84\n" /* line 314 */
        "testl %ebx, %ebx\n" /* line 315 | wantedHandle */
        "jne .Lf58d2a_000591d0\n"
        "movl 0x4a3b84, %edx\n"
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
        "movl %eax, 0x4a3b84\n"
        "movl $0x219ae4, 4(%esp)\n" /* line 337 */
        "movl mss_3d_provider, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl 0x4a3b84, %edx\n"
        ".Lf58d2a_00058fea:\n"
        "testl %edx, %edx\n" /* line 345 */
        "je .Lf58d2a_000590b0\n"
        ".Lf58d2a_00058ff2:\n"
        "movl 0x195ed34, %ebx\n" /* line 348 | wantedHandle */
        "movb $1, 1(%ebx)\n" /* wantedHandle */
        "leal 0x13c8(%ebx), %eax\n" /* line 349 | wantedHandle */
        "movl %eax, 8(%esp)\n"
        "movl $0x219c6c, 4(%esp)\n" /* "Maximum supported samples" */
        "movl %edx, (%esp)\n"
        "calll AIL_3D_provider_attribute\n"
        "cmpl $0x20, 0x13c8(%ebx)\n" /* line 350 | wantedHandle */
        "jg .Lf58d2a_0005913a\n"
        ".Lf58d2a_00059023:\n"
        "movl 0x13c8(%ebx), %eax\n" /* line 352 | wantedHandle */
        "movl %eax, 4(%esp)\n"
        "movl $0x219c88, (%esp)\n" /* "%i max 3D channels
" */
        "calll Com_Printf\n"
        "movl $0x3cd013a9, 4(%esp)\n" /* line 354 */
        "movl 0x4a3b84, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_distance_factor\n"
        "movl $0, 4(%esp)\n" /* line 355 */
        "movl 0x4a3b84, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_3D_rolloff_factor\n"
        /* } scope */
        /* } scope */
        "movl 0x195ed34, %eax\n" /* line 364 */
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
        "movl $0x219bc4, (%esp)\n" /* "couldn't initialize 2D provider: %s
" */
        "calll Com_Printf\n"
        ".Lf58d2a_000590b0:\n"
        "calll AIL_shutdown\n" /* line 457 */
        "movl $0x130, 8(%esp)\n" /* line 407 */
        "movl $0, 4(%esp)\n"
        "movl $milesGlob, (%esp)\n"
        "calll memset\n"
        ".Lf58d2a_000590d1:\n"
        "movl $0x219aa8, (%esp)\n" /* line 202 */
        "calll Dvar_GetInt\n"
        "cmpl $2, %eax\n"
        "je .Lf58d2a_00059121\n"
        "movl $0x219ab8, (%esp)\n" /* line 205 */
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
        "movl $0x219b98, %eax\n" /* line 248 */
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
        "movl $0x4a3ba0, %edi\n"
        "movl 0x195ed34, %esi\n"
        ".Lf58d2a_00059170:\n"
        "movl 0x4a3b84, %eax\n" /* line 373 */
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
        "movl 0x195ed34, %eax\n" /* line 364 */
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
        "movl %ebx, 0x4a3b84\n" /* line 320 | wantedHandle */
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
        "movl $0x219ae4, 4(%esp)\n" /* "Miles Fast 2D Positional Audio" */
        "movl $0x219c08, (%esp)\n" /* "couldn't open 3D provider '%s': %s
" */
        "calll Com_Printf\n"
        "movl 0x4a3b84, %edx\n"
        "jmp .Lf58d2a_00058fea\n"
        /* } scope */
        /* } scope */
        ".Lf58d2a_0005923e:\n"
        "addl $1, %ebx\n" /* line 375 | wantedHandle */
        "movl %ebx, 8(%esp)\n" /* wantedHandle */
        "movl $0x219cd4, 4(%esp)\n" /* "MILES 3D sound sample allocation failed on channel %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf58d2a_0005918c\n"
        ".Lf58d2a_0005925e:\n"
        "addl $1, %ebx\n" /* line 368 | wantedHandle */
        "movl %ebx, 8(%esp)\n" /* wantedHandle */
        "movl $0x219c9c, 4(%esp)\n" /* "MILES 2D sound sample allocation failed on channel %i
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
        "movl $0x219c08, (%esp)\n" /* "couldn't open 3D provider '%s': %s
" */
        "calll Com_Printf\n"
        "movl 0x4a3b84, %edx\n"
        "jmp .Lf58d2a_00058f93\n"
        ".Lf58d2a_000592a2:\n"
        "movl $0x219ae4, 4(%esp)\n" /* line 330 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf58d2a_00058fb4\n"
        "movl %esi, 4(%esp)\n" /* line 331 */
        "movl $0x219c2c, (%esp)\n" /* "trying to use 'Miles Fast 2D Positional Audio' instead of '%" */
        "calll Com_Printf\n"
        "jmp .Lf58d2a_00058fb4\n"
    );
}

/* line 1264 */
__attribute__((naked))
void SND_SetStreamChannelFromSaveInfo(int index, snd_save_stream_t *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1264 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0xc(%ebp), %eax\n" /* info */
        "movss 0x10(%eax), %xmm0\n" /* line 1268 */
        "movss %xmm0, -0xc(%ebp)\n" /* pan */
        "movl 0x195ed34, %edx\n"
        "movss 0xc(%eax), %xmm1\n" /* volume */
        "mulss 0x24(%edx), %xmm1\n" /* volume */
        /* { scope 1 */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 1091 */
        "shll $4, %eax\n"
        "leal 0x350(%eax, %edx), %eax\n"
        "cmpl $2, 4(%eax)\n"
        "je .Lf592d0_00059340\n"
        ".Lf592d0_0005930a:\n"
        "mulss %xmm1, %xmm0\n" /* line 1094 */
        "movss %xmm0, 8(%esp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0xc(%ebp), %xmm0\n" /* pan */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl 0x4a3ba8(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_stream_volume_levels\n"
        /* } scope */
        ".Lf592d0_0005933a:\n"
        "addl $0x34, %esp\n" /* line 1269 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf592d0_00059340:\n"
        "movl 8(%eax), %eax\n" /* line 1091 */
        "movl 0x2c(%eax), %eax\n"
        "andl $0x780, %eax\n"
        "sarl $7, %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "calll SND_IsAliasChannel3D\n"
        "testb %al, %al\n"
        "movss -0x28(%ebp), %xmm1\n"
        "je .Lf592d0_0005936b\n"
        "movss -0xc(%ebp), %xmm0\n" /* pan */
        "jmp .Lf592d0_0005930a\n"
        ".Lf592d0_0005936b:\n"
        "movss %xmm1, 8(%esp)\n" /* line 1092 */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x4a3ba8(, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_set_stream_volume_levels\n"
        "jmp .Lf592d0_0005933a\n"
    );
}

/* line 1599 */
__attribute__((naked))
void SND_DriverPostUpdate(int frametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1599 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x4a3c5c, %edx\n" /* line 1356 */
        "testl %edx, %edx\n"
        "je .Lf59388_000593cc\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 1359 | 0.5f */
        "movl 0x195ed34, %eax\n"
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll AIL_set_sample_volume_levels\n"
        "movl 0x4a3c98, %eax\n" /* line 1361 */
        "cmpb $0, 0x4a3c70(%eax)\n"
        "jne .Lf59388_000593ce\n"
        ".Lf59388_000593cc:\n"
        "leave\n" /* line 1602 */
        "retl\n"
        ".Lf59388_000593ce:\n"
        "movl 0x4a3c5c, %eax\n" /* line 1364 */
        "movl %eax, (%esp)\n"
        "calll AIL_sample_buffer_ready\n"
        "movl %eax, %edx\n"
        "cmpl $-1, %eax\n" /* line 1365 */
        "je .Lf59388_000593cc\n"
        "cvtsi2sdl 0x4a3c90, %xmm0\n" /* line 1369 */
        "mulsd 0x4a3ca8, %xmm0\n"
        "addsd 0x4a3ca0, %xmm0\n"
        "movsd %xmm0, 0x4a3ca0\n"
        "movl 0x4a3c90, %eax\n" /* line 1371 */
        "movl %eax, 0xc(%esp)\n"
        "imull 0x4a3c98, %eax\n"
        "addl 0x4a3c6c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x4a3c5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AIL_load_sample_buffer\n"
        "movl 0x4a3c98, %edx\n" /* line 1372 */
        "movl $0x4a3c60, %eax\n"
        "movb $0, 0x10(%edx, %eax)\n"
        "addl $1, %edx\n" /* line 1373 */
        "movl %edx, %eax\n"
        "andl $0x8000001f, %eax\n"
        "js .Lf59388_00059450\n"
        ".Lf59388_00059449:\n"
        "movl %eax, 0x4a3c98\n"
        "leave\n" /* line 1602 */
        "retl\n"
        ".Lf59388_00059450:\n"
        "subl $1, %eax\n" /* line 1373 */
        "orl $0xffffffe0, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf59388_00059449\n"
    );
}

