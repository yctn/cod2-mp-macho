/* ASM dump from: MacMSS_Sample.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS_Sample.cp */

#include "common_types.h"
#include "imports.h"

void CSampleSound_CSampleSound(const CSampleSound * _this, CSoundEngine *inEngine, UInt32 inBusIndex);
void CSampleSound_TheadIdle(const CSampleSound * _this);
void CSampleSound_stop_sample(const CSampleSound * _this);
void CSampleSound_end_sample(const CSampleSound * _this);
bool CSampleSound_open_stream(const CSampleSound * _this, const char *filename);
void CSampleSound_close_stream(const CSampleSound * _this);
void CSampleSound_ChangedFormat(const CSampleSound * _this);
void CSampleSound_Changed3DPosition(const CSampleSound * _this);
OSStatus CSampleSound_DoConvert(const CSampleSound * _this, UInt32 *ioNumberDataPackets, AudioBufferList *ioData);
OSStatus CSampleSound_AudioConverterProc(AudioConverterRef inAudioConverter, UInt32 *ioNumberDataPackets, AudioBufferList *ioData, AudioStreamPacketDescription * *outDataPacketDescription, void *inUserData);
void CSampleSound_UpdateStreamFormat(const CSampleSound * _this);
void CSampleSound_ChangedVolume(const CSampleSound * _this);
void CSampleSound_Update3DValues(const CSampleSound * _this);
OSStatus CSampleSound_DoRender(const CSampleSound * _this, AudioUnitRenderActionFlags *ioActionFlags, UInt32 inNumberFrames, AudioBufferList *ioData);
OSStatus CSampleSound_RenderCallbackProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData);
void CSampleSound_resume_sample(const CSampleSound * _this);
OSStatus CSampleSound_InitSample(const CSampleSound * _this, UInt32 inSoundType, UInt32 inSpatializationAlgorithm, UInt32 in3DRenderFlags, UInt32 inDopplerShift);
void CSampleSound_Changed3DDistances(const CSampleSound * _this);
OSStatus CSampleSound_RenderNotifyProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData);
void ZN12CSampleSoundD2Ev(void); /* CSampleSound_~CSampleSound */
void ZN12CSampleSoundD1Ev(void); /* CSampleSound_~CSampleSound */
void ZN12CSampleSoundD0Ev(void); /* CSampleSound_~CSampleSound */
OSStatus CSampleSound_DoPreRender(const CSampleSound * _this);
OSStatus CSampleSound_DoPostRender(const CSampleSound * _this);

/* line 23 */
__attribute__((naked))
void CSampleSound_CSampleSound(const CSampleSound * _this, CSoundEngine *inEngine, UInt32 inBusIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 23 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x10(%ebp), %eax\n" /* line 37 | inBusIndex */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inEngine */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CSoundObject_CSoundObject\n"
        "movl $0x3322c8, (%ebx)\n" /* this */
        "movl $0, 0x108(%ebx)\n" /* this */
        "movb $0, 0x10c(%ebx)\n" /* this */
        "movb $0, 0x10d(%ebx)\n" /* this */
        "movb $0, 0x10e(%ebx)\n" /* this */
        "movb $1, 0x10f(%ebx)\n" /* this */
        "movb $0, 0x110(%ebx)\n" /* this */
        "movb $0, 0x111(%ebx)\n" /* this */
        "movl $0, 0x114(%ebx)\n" /* this */
        "movl $0, 0x118(%ebx)\n" /* this */
        "movb $0, 0x11c(%ebx)\n" /* this */
        "leal 0xe0(%ebx), %eax\n" /* line 39 | this */
        "movl $0xffffffff, 0xe0(%ebx)\n" /* this */
        "movl $0xffffffff, 4(%eax)\n"
        "movl $0xffffffff, 8(%eax)\n"
        "movl $0xffffffff, 0xc(%eax)\n"
        "movl $0xffffffff, 0x10(%eax)\n"
        "movl $0xffffffff, 0x14(%eax)\n"
        "movl $0xffffffff, 0x18(%eax)\n"
        "movl $0xffffffff, 0x1c(%eax)\n"
        "movl $0xffffffff, 0x20(%eax)\n"
        "movl $0xffffffff, 0x24(%eax)\n"
        "addl $0x14, %esp\n" /* line 40 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 146 */
__attribute__((naked))
void CSampleSound_TheadIdle(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 146 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "leal 0x20(%esi), %eax\n" /* line 148 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl $4, 0x60(%esi)\n" /* line 152 | this */
        "je .Lf114484_001144d0\n"
        ".Lf114484_001144a8:\n"
        "movl %edi, (%esp)\n" /* line 193 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 194 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf114484_001144b8:\n"
        "movl %eax, 0xc(%esp)\n" /* line 191 */
        "movl 0x4c(%esi, %ebx, 4), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* index */
        "movl %esi, (%esp)\n" /* this */
        "calll CSoundObject_load_sample_buffer\n"
        ".Lf114484_001144d0:\n"
        "movl %esi, (%esp)\n" /* line 157 | this */
        "calll CSoundObject_sample_buffer_ready\n"
        "movl %eax, %ebx\n" /* index */
        "cmpl $-1, %eax\n" /* line 158 */
        "je .Lf114484_001144a8\n"
        "movl 0x5c(%esi), %eax\n" /* line 164 | this, result */
        "movl %eax, 8(%esp)\n" /* result */
        "movl 0x4c(%esi, %ebx, 4), %eax\n" /* this, result */
        "movl %eax, 4(%esp)\n" /* result */
        "movl 0x114(%esi), %eax\n" /* this, result */
        "movl %eax, (%esp)\n" /* result */
        "calll CSoundObject_file_read_callback\n"
        "testl %eax, %eax\n" /* line 165 */
        "jg .Lf114484_001144b8\n"
        "movl 0x80(%esi), %eax\n" /* line 169 | this */
        "cmpl $1, %eax\n"
        "je .Lf114484_00114548\n"
        "testl %eax, %eax\n" /* line 178 */
        "je .Lf114484_00114518\n"
        "subl $1, %eax\n" /* line 185 */
        "movl %eax, 0x80(%esi)\n" /* this */
        ".Lf114484_00114518:\n"
        "movl $0, 8(%esp)\n" /* line 180 */
        "movl 0x118(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x114(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_file_seek_callback\n"
        /* } scope */
        "movl %edi, (%esp)\n" /* line 193 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 194 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf114484_00114548:\n"
        "movl %esi, (%esp)\n" /* line 173 | this */
        "calll CSoundObject_SampleBuffersEmpty\n"
        "testb %al, %al\n"
        "je .Lf114484_001144a8\n"
        "movl $2, 0x60(%esi)\n" /* line 175 | this */
        "jmp .Lf114484_001144a8\n"
        "movl %eax, %ebx\n" /* index */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 193 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* index */
        "calll __Unwind_Resume\n"
    );
}

/* line 201 */
__attribute__((naked))
void CSampleSound_stop_sample(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 201 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 205 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl $4, 0x60(%ebx)\n" /* line 207 | this */
        "jne .Lf114576_001145b9\n"
        "movl $8, 0x60(%ebx)\n" /* line 209 | this */
        "movb $1, 0x10e(%ebx)\n" /* line 211 | this */
        "movl 0x108(%ebx), %eax\n" /* line 213 | this */
        "testl %eax, %eax\n"
        "je .Lf114576_001145b9\n"
        "movl %eax, (%esp)\n" /* line 215 */
        "calll AudioConverterReset\n"
        ".Lf114576_001145b9:\n"
        "movl %esi, (%esp)\n" /* line 217 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 218 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 217 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 252 */
__attribute__((naked))
void CSampleSound_end_sample(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 252 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "leal 0x20(%ebx), %eax\n" /* line 256 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl $4, 0x60(%ebx)\n" /* line 258 | this */
        "jne .Lf1145da_00114627\n"
        "movl $2, 0x60(%ebx)\n" /* line 260 | this */
        "movl $0, 0xac(%ebx)\n" /* line 262 | this */
        "movb $1, 0x10e(%ebx)\n" /* line 264 | this */
        "movl 0x108(%ebx), %eax\n" /* line 266 | this */
        "testl %eax, %eax\n"
        "je .Lf1145da_00114627\n"
        "movl %eax, (%esp)\n" /* line 268 */
        "calll AudioConverterReset\n"
        ".Lf1145da_00114627:\n"
        "movl %esi, (%esp)\n" /* line 270 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 271 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 270 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 279 */
__attribute__((naked))
bool CSampleSound_open_stream(const CSampleSound * _this, const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 279 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 289 | this */
        "movl %esi, (%esp)\n" /* this */
        "calll *0x2c(%eax)\n"
        "movl %esi, (%esp)\n" /* line 290 | this */
        "calll CSoundObject_init_sample\n"
        "leal 0x114(%esi), %eax\n" /* line 293 | this */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_file_open_callback\n"
        "testl %eax, %eax\n"
        "jne .Lf114648_0011468d\n"
        "xorl %eax, %eax\n" /* line 394 */
        /* } scope */
        ".Lf114648_00114682:\n"
        "addl $0x24c, %esp\n" /* line 395 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf114648_0011468d:\n"
        "movl $0x200, 8(%esp)\n" /* line 305 */
        "leal -0x244(%ebp), %ebx\n" /* buffer */
        "movl %ebx, 4(%esp)\n"
        "movl 0x114(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_file_read_callback\n"
        "testl %eax, %eax\n"
        "je .Lf114648_001146ce\n"
        "leal -0x44(%ebp), %eax\n" /* line 315 | info */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll AIL_WAV_info\n"
        "testl %eax, %eax\n"
        "jne .Lf114648_001146eb\n"
        /* { scope 2 */
        "cmpl $-1, -0x40(%ebp)\n" /* line 321 */
        "je .Lf114648_001147c4\n"
        ".Lf114648_001146ce:\n"
        "movl (%esi), %eax\n" /* line 347 | this */
        "movl %esi, (%esp)\n" /* this */
        "calll *0x2c(%eax)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x24c, %esp\n" /* line 395 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf114648_001146e3:\n"
        "movl %edi, (%esp)\n" /* line 351 */
        "calll free\n"
        /* } scope */
        ".Lf114648_001146eb:\n"
        "movl -0x40(%ebp), %eax\n" /* line 357 */
        "subl %ebx, %eax\n"
        "movl %eax, 0x118(%esi)\n" /* this */
        "movl $0, 8(%esp)\n" /* line 358 */
        "movl %eax, 4(%esp)\n"
        "movl 0x114(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_file_seek_callback\n"
        "leal 0x20(%esi), %eax\n" /* line 364 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl $0, 8(%esp)\n" /* line 370 */
        "movl $0, 4(%esp)\n"
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_minimum_sample_buffer_size\n"
        "shll $2, %eax\n"
        "movl %eax, 0x5c(%esi)\n" /* this */
        "movl %esi, %ebx\n" /* this */
        "leal 0x10(%esi), %edi\n" /* this */
        "movl %eax, (%esp)\n" /* line 373 */
        "calll malloc\n"
        "movl %eax, 0x4c(%ebx)\n"
        "addl $4, %ebx\n"
        "cmpl %edi, %ebx\n" /* line 371 */
        "je .Lf114648_0011476f\n"
        ".Lf114648_0011475a:\n"
        "movl 0x5c(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* line 373 */
        "calll malloc\n"
        "movl %eax, 0x4c(%ebx)\n"
        "addl $4, %ebx\n"
        "cmpl %edi, %ebx\n" /* line 371 */
        "jne .Lf114648_0011475a\n"
        ".Lf114648_0011476f:\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 378 | dataLength */
        "movl $0, -0x40(%ebp)\n" /* line 380 */
        "movl $0, -0x3c(%ebp)\n" /* line 381 */
        "leal -0x44(%ebp), %eax\n" /* line 382 | info */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll CSoundObject_set_sample_info\n"
        "movl %ebx, 0xb0(%esi)\n" /* line 384 | dataLength, this */
        "movl %esi, 4(%esp)\n" /* line 388 | this */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_AddSoundObject\n"
        "movb $1, 0x14(%esi)\n" /* line 391 | this */
        "movb $1, 0x11c(%esi)\n" /* line 392 | this */
        "leal -0x20(%ebp), %eax\n" /* line 394 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        "movl $1, %eax\n"
        "jmp .Lf114648_00114682\n"
        /* { scope 2 */
        ".Lf114648_001147c4:\n"
        "movl $0, 8(%esp)\n" /* line 331 */
        "movl $0, 4(%esp)\n"
        "movl 0x114(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_file_seek_callback\n"
        "movl $0x1400, (%esp)\n" /* line 334 */
        "calll malloc\n"
        "movl %eax, %edi\n"
        "movl $0x1400, 8(%esp)\n" /* line 336 */
        "movl %eax, 4(%esp)\n"
        "movl 0x114(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_file_read_callback\n"
        "testl %eax, %eax\n"
        "je .Lf114648_00114825\n"
        "leal -0x44(%ebp), %eax\n" /* line 343 | info */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll AIL_WAV_info\n"
        "testl %eax, %eax\n"
        "jne .Lf114648_001146e3\n"
        ".Lf114648_00114825:\n"
        "movl %edi, (%esp)\n" /* line 346 */
        "calll free\n"
        "jmp .Lf114648_001146ce\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "leal -0x20(%ebp), %eax\n" /* line 394 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* dataLength */
        "calll __Unwind_Resume\n"
    );
}

/* line 400 */
__attribute__((naked))
void CSampleSound_close_stream(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 400 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 0x11c(%ebx)\n" /* line 402 | this */
        "jne .Lf114848_00114863\n"
        "addl $0x20, %esp\n" /* line 424 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf114848_00114863:\n"
        "movl %ebx, 4(%esp)\n" /* line 404 | this */
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_RemoveSoundObject\n"
        "leal 0x20(%ebx), %eax\n" /* line 409 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x114(%ebx), %eax\n" /* line 411 | this */
        "testl %eax, %eax\n"
        "jne .Lf114848_001148b6\n"
        ".Lf114848_0011488e:\n"
        "movb $0, 0x11c(%ebx)\n" /* line 417 | this */
        "movl 0x108(%ebx), %eax\n" /* line 419 | this */
        "testl %eax, %eax\n"
        "je .Lf114848_001148a7\n"
        "movl %eax, (%esp)\n" /* line 421 */
        "calll AudioConverterReset\n"
        ".Lf114848_001148a7:\n"
        "movl %esi, (%esp)\n" /* line 422 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 424 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf114848_001148b6:\n"
        "movl %eax, (%esp)\n" /* line 413 */
        "calll CSoundObject_file_close_callback\n"
        "movl $0, 0x114(%ebx)\n" /* line 414 | this */
        "jmp .Lf114848_0011488e\n"
        "movl %eax, %ebx\n" /* this */
        "movl %esi, (%esp)\n" /* line 422 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 469 */
__attribute__((naked))
void CSampleSound_ChangedFormat(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 469 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 471 | this */
        "movb $1, 0x10f(%eax)\n"
        "popl %ebp\n" /* line 472 */
        "retl\n"
    );
}

/* line 477 */
__attribute__((naked))
void CSampleSound_Changed3DPosition(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 477 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 479 | this */
        "movb $1, 0x110(%eax)\n"
        "popl %ebp\n" /* line 480 */
        "retl\n"
    );
}

/* line 926 */
__attribute__((naked))
OSStatus CSampleSound_DoConvert(const CSampleSound * _this, UInt32 *ioNumberDataPackets, AudioBufferList *ioData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 926 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: bufferStart */
        "leal 0x20(%ebx), %eax\n" /* line 928 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpl $4, 0x60(%ebx)\n" /* line 930 | this */
        "je .Lf1148fc_00114991\n"
        ".Lf1148fc_00114920:\n"
        "movl 0x60(%ebx), %eax\n" /* line 1010 | this */
        "cmpl $2, %eax\n"
        "je .Lf1148fc_00114971\n"
        "cmpl $8, %eax\n"
        "je .Lf1148fc_00114971\n"
        "xorl %ebx, %ebx\n" /* this */
        "movl %edi, (%esp)\n" /* line 1016 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1017 | this */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bufferStart */
        ".Lf1148fc_00114941:\n"
        "movl 0x80(%ebx), %eax\n" /* line 962 | this */
        "cmpl $1, %eax\n"
        "je .Lf1148fc_00114a72\n"
        "testl %eax, %eax\n" /* line 966 */
        "je .Lf1148fc_0011495d\n"
        "subl $1, %eax\n" /* line 973 */
        "movl %eax, 0x80(%ebx)\n" /* this */
        ".Lf1148fc_0011495d:\n"
        "movl $0, 0xac(%ebx)\n" /* line 974 | this */
        ".Lf1148fc_00114967:\n"
        "cmpl $2, 0x60(%ebx)\n" /* line 978 | this */
        "jne .Lf1148fc_001149f4\n"
        ".Lf1148fc_00114971:\n"
        "movl 0xc(%ebp), %esi\n" /* line 1012 | ioNumberDataPackets */
        "movl $0, (%esi)\n"
        "movl $0x69354e44, %ebx\n" /* this */
        ".Lf1148fc_0011497f:\n"
        "movl %edi, (%esp)\n" /* line 1016 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1017 | this */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bufferStart */
        ".Lf1148fc_00114991:\n"
        "movl 0x18(%ebx), %edx\n" /* line 932 | this */
        "movl 0xac(%ebx), %eax\n" /* this */
        "cmpl 0x94(%ebx, %edx, 4), %eax\n" /* this */
        "jl .Lf1148fc_00114967\n"
        "cmpb $0, 0x14(%ebx)\n" /* line 934 | this */
        "je .Lf1148fc_00114941\n"
        "movl $0, 0x84(%ebx, %edx, 4)\n" /* line 936 | this */
        "movl $0, 0x94(%ebx, %edx, 4)\n" /* line 937 | this */
        "addl $1, %edx\n" /* line 939 */
        "xorl %eax, %eax\n" /* line 942 */
        "cmpl $4, %edx\n"
        "cmovbl %edx, %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* this */
        "movl $0, 0xac(%ebx)\n" /* line 945 | this */
        "movl %eax, %edx\n" /* line 947 */
        "movl 0x84(%ebx, %eax, 4), %ecx\n" /* this */
        "testl %ecx, %ecx\n"
        "jne .Lf1148fc_00114967\n"
        "movl 0xc(%ebp), %eax\n" /* line 958 | ioNumberDataPackets */
        "movl $0, (%eax)\n"
        "movl $0x69354e44, %ebx\n" /* this */
        "jmp .Lf1148fc_0011497f\n"
        ".Lf1148fc_001149f4:\n"
        "movl 0x84(%ebx, %edx, 4), %esi\n" /* line 980 | this */
        "testl %esi, %esi\n"
        "je .Lf1148fc_00114a64\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %ecx\n" /* line 982 | ioNumberDataPackets */
        "movl (%ecx), %eax\n" /* requestedBytes */
        "imull 0x1c(%ebx), %eax\n" /* this, requestedBytes */
        "movl 0xac(%ebx), %ecx\n" /* line 984 | this */
        "movl 0x94(%ebx, %edx, 4), %edx\n" /* this, actualBytes */
        "subl %ecx, %edx\n" /* actualBytes */
        "cmpl %edx, %eax\n" /* line 985 */
        "cmovbl %eax, %edx\n"
        "addl %ecx, %esi\n" /* line 990 */
        "movl %esi, -0x2c(%ebp)\n" /* bufferStart */
        /* { scope 3 */
        "movl 0x10(%ebp), %esi\n" /* line 992 | ioData */
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1148fc_00114a4a\n"
        "movl %esi, %eax\n"
        "xorl %ecx, %ecx\n" /* i */
        ".Lf1148fc_00114a2e:\n"
        "movl %edx, 8(%eax)\n" /* line 995 */
        "movl -0x2c(%ebp), %esi\n" /* line 996 | bufferStart */
        "movl %esi, 0xc(%eax)\n"
        "addl $1, %ecx\n" /* line 992 | i */
        "addl $0xc, %eax\n"
        "movl 0x10(%ebp), %esi\n" /* ioData */
        "cmpl %ecx, (%esi)\n" /* i */
        "ja .Lf1148fc_00114a2e\n"
        "movl 0xac(%ebx), %ecx\n" /* this, i */
        /* } scope */
        ".Lf1148fc_00114a4a:\n"
        "leal (%edx, %ecx), %eax\n" /* line 999 */
        "movl %eax, 0xac(%ebx)\n" /* this */
        "movl %edx, %eax\n" /* line 1001 */
        "xorl %edx, %edx\n"
        "divl 0x1c(%ebx)\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* ioNumberDataPackets */
        "movl %eax, (%edx)\n"
        "jmp .Lf1148fc_00114920\n"
        /* } scope */
        ".Lf1148fc_00114a64:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1005 | ioNumberDataPackets */
        "movl $0, (%ecx)\n"
        "jmp .Lf1148fc_00114920\n"
        ".Lf1148fc_00114a72:\n"
        "movl $2, 0x60(%ebx)\n" /* line 964 | this */
        "jmp .Lf1148fc_00114967\n"
    );
}

/* line 755 */
__attribute__((naked))
OSStatus CSampleSound_AudioConverterProc(AudioConverterRef inAudioConverter, UInt32 *ioNumberDataPackets, AudioBufferList *ioData, AudioStreamPacketDescription * *outDataPacketDescription, void *inUserData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 755 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x18(%ebp), %eax\n" /* inUserData */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 761 */
        "je .Lf114a7e_00114ab0\n"
        "movl 0x10(%ebp), %edx\n" /* line 763 | ioData */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* ioNumberDataPackets */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CSampleSound_DoConvert\n"
        /* } scope */
        "leave\n" /* line 771 */
        "retl\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 766 */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        ".Lf114a7e_00114ab0:\n"
        "movl $0xffffffce, %eax\n"
        /* } scope */
        "leave\n" /* line 771 */
        "retl\n"
    );
}

/* line 525 */
__attribute__((naked))
void CSampleSound_UpdateStreamFormat(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 525 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "cmpb $0, 0x10f(%esi)\n" /* line 527 | this */
        "jne .Lf114ab8_00114adb\n"
        "addl $0x8c, %esp\n" /* line 592 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inDataSize */
        ".Lf114ab8_00114adb:\n"
        "leal -0x48(%ebp), %eax\n" /* line 531 | sourceFormat */
        "movl %eax, 8(%esp)\n"
        "movl 0xa8(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x7c(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_FormatToDescription\n"
        "movl $0x28, -0x1c(%ebp)\n" /* inDataSize */
        /* { scope 2 */
        "movl 8(%esi), %ebx\n" /* line 1029 | this */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "leal -0x1c(%ebp), %edx\n" /* inDataSize */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x70(%ebp), %edi\n" /* destFormat */
        "movl %edi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 537 */
        "je .Lf114ab8_00114b6f\n"
        ".Lf114ab8_00114b3a:\n"
        "movl 0x108(%esi), %eax\n" /* line 580 | this */
        "testl %eax, %eax\n"
        "je .Lf114ab8_00114b56\n"
        "movl %eax, (%esp)\n" /* line 582 */
        "calll AudioConverterDispose\n"
        "movl $0, 0x108(%esi)\n" /* line 583 | this */
        ".Lf114ab8_00114b56:\n"
        "movb $0, 0x10c(%esi)\n" /* line 586 | this */
        ".Lf114ab8_00114b5d:\n"
        "movb $0, 0x10f(%esi)\n" /* line 590 | this */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 592 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inDataSize */
        ".Lf114ab8_00114b6f:\n"
        "movl %edi, 4(%esp)\n" /* line 541 */
        "leal -0x48(%ebp), %eax\n" /* sourceFormat */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_IsEqualDescriptions\n"
        "testb %al, %al\n"
        "jne .Lf114ab8_00114c39\n"
        "movb $0, 0x10c(%esi)\n" /* line 549 | this */
        "movl 0x108(%esi), %ebx\n" /* line 552 | this */
        "testl %ebx, %ebx\n"
        "je .Lf114ab8_00114ca7\n"
        "leal 0xe0(%esi), %ebx\n" /* this */
        "movl %ebx, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* sourceFormat */
        "movl %eax, (%esp)\n"
        "calll CSoundObject_IsEqualDescriptions\n"
        "testb %al, %al\n"
        "jne .Lf114ab8_00114c94\n"
        ".Lf114ab8_00114bb8:\n"
        "movl -0x48(%ebp), %eax\n" /* line 561 | sourceFormat */
        "movl %eax, 0xe0(%esi)\n" /* this */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x1c(%ebx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x20(%ebx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x24(%ebx)\n"
        "movl 0x108(%esi), %eax\n" /* line 563 | this */
        "testl %eax, %eax\n"
        "je .Lf114ab8_00114c13\n"
        "movl %eax, (%esp)\n" /* line 565 */
        "calll AudioConverterDispose\n"
        "movl $0, 0x108(%esi)\n" /* line 566 | this */
        ".Lf114ab8_00114c13:\n"
        "leal 0x108(%esi), %eax\n" /* line 569 | this */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* sourceFormat */
        "movl %eax, (%esp)\n"
        "calll AudioConverterNew\n"
        "testl %eax, %eax\n" /* line 576 */
        "je .Lf114ab8_00114b5d\n"
        "jmp .Lf114ab8_00114b3a\n"
        ".Lf114ab8_00114c39:\n"
        "movb $1, 0x10c(%esi)\n" /* line 543 | this */
        "leal 0xe0(%esi), %eax\n" /* line 545 | this */
        "movl $0xffffffff, 0xe0(%esi)\n" /* this */
        "movl $0xffffffff, 4(%eax)\n"
        "movl $0xffffffff, 8(%eax)\n"
        "movl $0xffffffff, 0xc(%eax)\n"
        "movl $0xffffffff, 0x10(%eax)\n"
        "movl $0xffffffff, 0x14(%eax)\n"
        "movl $0xffffffff, 0x18(%eax)\n"
        "movl $0xffffffff, 0x1c(%eax)\n"
        "movl $0xffffffff, 0x20(%eax)\n"
        "movl $0xffffffff, 0x24(%eax)\n"
        "jmp .Lf114ab8_00114b5d\n"
        ".Lf114ab8_00114c94:\n"
        "movl 0x108(%esi), %eax\n" /* line 556 | this */
        "movl %eax, (%esp)\n"
        "calll AudioConverterReset\n"
        "jmp .Lf114ab8_00114b5d\n"
        ".Lf114ab8_00114ca7:\n"
        "leal 0xe0(%esi), %ebx\n" /* this */
        "jmp .Lf114ab8_00114bb8\n"
    );
}

/* line 431 */
__attribute__((naked))
void CSampleSound_ChangedVolume(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 431 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movss 0x68(%esi), %xmm0\n" /* line 433 | this, realVolume */
        "addss 0x6c(%esi), %xmm0\n" /* this, realVolume */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f, realVolume */
        "mulss 0x64(%esi), %xmm0\n" /* this, realVolume */
        "movss 0x2ed5d0, %xmm1\n" /* line 435 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf114cb2_00114d5a\n"
        "movaps %xmm1, %xmm0\n"
        /* { scope 2 */
        ".Lf114cb2_00114ce4:\n"
        "movss %xmm0, (%esp)\n" /* line 446 */
        "calll log10f\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* db */
        "mulss 0x2ed694, %xmm1\n" /* 20.0f, db */
        "movss 0x2ed8ac, %xmm0\n" /* line 447 | -120.0f */
        "maxss %xmm1, %xmm0\n"
        "movl 8(%esi), %ebx\n" /* line 1060 | this */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x18(%ebp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x18(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetParameter\n"
        "movb $0, 0x111(%esi)\n" /* line 455 | this */
        /* } scope */
        /* } scope */
        "addl $0x40, %esp\n" /* line 464 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf114cb2_00114d5a:\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 439 | 0.0f */
        "jp .Lf114cb2_00114d65\n"
        "jb .Lf114cb2_00114d72\n"
        ".Lf114cb2_00114d65:\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 444 | 0.0f */
        "ja .Lf114cb2_00114ce4\n"
        ".Lf114cb2_00114d72:\n"
        "movb $1, 0x111(%esi)\n" /* line 462 | this */
        /* } scope */
        "addl $0x40, %esp\n" /* line 464 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 597 */
__attribute__((naked))
void CSampleSound_Update3DValues(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 597 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "cmpb $0, 0x110(%edi)\n" /* line 599 | this */
        "jne .Lf114d80_00114d9d\n"
        "addl $0x4c, %esp\n" /* line 622 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf114d80_00114d9d:\n"
        "leal -0x24(%ebp), %eax\n" /* line 604 | distance */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* elevation */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* azimuth */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* this */
        "calll CSampleSound_Calculate3DAttributes\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 606 | azimuth, inValue */
        /* { scope 2 */
        "movl 8(%edi), %esi\n" /* line 1060 | this */
        "movl 4(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* inValue */
        "movl %esi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetParameter\n"
        /* } scope */
        "movl -0x20(%ebp), %ebx\n" /* line 609 | elevation, inValue */
        /* { scope 2 */
        "movl 8(%edi), %esi\n" /* line 1060 | this */
        "movl 4(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* inValue */
        "movl %esi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetParameter\n"
        /* } scope */
        "movl 4(%edi), %eax\n" /* line 612 | this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_IsDistanceScalingRequired\n"
        "testb %al, %al\n"
        "jne .Lf114d80_00114e83\n"
        ".Lf114d80_00114e3b:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 617 | distance, inValue */
        /* { scope 2 */
        "movl 8(%edi), %esi\n" /* line 1060 | this */
        "movl 4(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* inValue */
        "movl %esi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetParameter\n"
        /* } scope */
        "movb $0, 0x110(%edi)\n" /* line 620 | this */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 622 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf114d80_00114e83:\n"
        "movss 0xd8(%edi), %xmm0\n" /* line 614 | this */
        "movss %xmm0, -0x30(%ebp)\n"
        "movl 4(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_get_3D_distance_factor\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x30(%ebp), %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss 0x2ed6b4, %xmm0\n" /* 10.0f */
        "divss -0x30(%ebp), %xmm0\n"
        "mulss -0x24(%ebp), %xmm0\n" /* distance */
        "movss %xmm0, -0x24(%ebp)\n" /* distance */
        "jmp .Lf114d80_00114e3b\n"
    );
}

/* line 779 */
__attribute__((naked))
OSStatus CSampleSound_DoRender(const CSampleSound * _this, AudioUnitRenderActionFlags *ioActionFlags, UInt32 inNumberFrames, AudioBufferList *ioData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 779 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* ioActionFlags */
        "movl 0x14(%ebp), %edi\n" /* ioData */
        /* { scope 1: bufferList, convertedFrames */
        "leal 0x20(%ebx), %eax\n" /* line 781 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl %ebx, (%esp)\n" /* line 629 */
        "calll CSampleSound_UpdateStreamFormat\n"
        "movl %ebx, (%esp)\n" /* line 631 */
        "calll CSoundObject_Is3DSound\n"
        "testb %al, %al\n"
        "jne .Lf114ecc_00115005\n"
        ".Lf114ecc_00114f08:\n"
        "movl 0x60(%ebx), %eax\n" /* line 787 | this */
        "cmpl $2, %eax\n"
        "je .Lf114ecc_00114fe7\n"
        "cmpl $8, %eax\n"
        "je .Lf114ecc_00114fe7\n"
        "cmpb $0, 0x111(%ebx)\n" /* line 791 | this */
        "jne .Lf114ecc_00114fc4\n"
        "movl 0x108(%ebx), %eax\n" /* this */
        "testl %eax, %eax\n"
        "je .Lf114ecc_00114fc4\n"
        "cmpb $0, 0x10c(%ebx)\n" /* line 807 | this */
        "je .Lf114ecc_0011504f\n"
        /* { scope 2: srcPtr, srcSize, bytesToZero */
        "movl $1, -0x34(%ebp)\n" /* line 814 | bufferList */
        "movl 0x10(%ebp), %eax\n" /* line 817 | inNumberFrames */
        "movl %eax, -0x1c(%ebp)\n" /* convertedFrames */
        "leal -0x34(%ebp), %eax\n" /* line 819 | bufferList, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x1c(%ebp), %eax\n" /* convertedFrames, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl %ebx, (%esp)\n" /* this */
        "calll CSampleSound_DoConvert\n"
        "testl %eax, %eax\n" /* line 820 */
        "jne .Lf114ecc_001150dd\n"
        /* { scope 3 */
        "movl -0x28(%ebp), %edx\n" /* line 822 */
        "movl %edx, -0x44(%ebp)\n" /* srcPtr */
        "movl -0x2c(%ebp), %eax\n" /* line 823 */
        "movl %eax, -0x40(%ebp)\n" /* srcSize */
        /* { scope 4 */
        "movl (%edi), %eax\n" /* line 826 | ioData */
        "testl %eax, %eax\n"
        "jne .Lf114ecc_001150ed\n"
        /* } scope */
        ".Lf114ecc_00114f86:\n"
        "movl 0x10(%ebp), %eax\n" /* line 834 | inNumberFrames */
        "cmpl -0x1c(%ebp), %eax\n" /* convertedFrames */
        "jbe .Lf114ecc_00114ff0\n"
        /* { scope 4 */
        "movl (%edi), %esi\n" /* line 836 | ioData, i */
        "testl %esi, %esi\n" /* i */
        "je .Lf114ecc_00114ff0\n"
        "movl %edi, %ebx\n" /* ioData, this */
        "xorl %esi, %esi\n" /* i */
        ".Lf114ecc_00114f98:\n"
        "movl 8(%ebx), %eax\n" /* line 840 | this */
        "subl -0x40(%ebp), %eax\n" /* srcSize */
        "movl -0x40(%ebp), %edx\n" /* srcSize */
        "addl 0xc(%ebx), %edx\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "addl $1, %esi\n" /* line 836 | i */
        "addl $0xc, %ebx\n" /* this */
        "cmpl (%edi), %esi\n" /* ioData, i */
        "jb .Lf114ecc_00114f98\n"
        "jmp .Lf114ecc_00114ff0\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: srcPtr, srcSize, bytesToZero */
        ".Lf114ecc_00114fc4:\n"
        "movl $1, -0x34(%ebp)\n" /* line 797 | bufferList */
        "movl 0x10(%ebp), %edx\n" /* line 801 | inNumberFrames */
        "movl %edx, -0x1c(%ebp)\n" /* convertedFrames */
        "leal -0x34(%ebp), %eax\n" /* line 803 | bufferList */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* convertedFrames */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CSampleSound_DoConvert\n"
        /* } scope */
        ".Lf114ecc_00114fe7:\n"
        "orl $0x10, (%esi)\n" /* line 875 | i */
        /* { scope 2: srcPtr, srcSize, bytesToZero */
        "movl (%edi), %eax\n" /* line 876 | ioData */
        "testl %eax, %eax\n"
        "jne .Lf114ecc_00115012\n"
        /* } scope */
        ".Lf114ecc_00114ff0:\n"
        "leal -0x24(%ebp), %edx\n" /* line 882 | lock */
        "movl %edx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 883 */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bufferList, convertedFrames */
        ".Lf114ecc_00115005:\n"
        "movl %ebx, (%esp)\n" /* line 633 */
        "calll CSampleSound_Update3DValues\n"
        "jmp .Lf114ecc_00114f08\n"
        /* { scope 2: srcPtr, srcSize, bytesToZero */
        ".Lf114ecc_00115012:\n"
        "movl %edi, %ebx\n" /* line 876 | ioData, this */
        "xorl %esi, %esi\n" /* i */
        ".Lf114ecc_00115016:\n"
        "movl 0xc(%ebx), %edx\n" /* line 878 | this */
        "movl 8(%ebx), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "addl $1, %esi\n" /* line 876 | i */
        "addl $0xc, %ebx\n" /* this */
        "cmpl (%edi), %esi\n" /* ioData, i */
        "jb .Lf114ecc_00115016\n"
        /* } scope */
        "leal -0x24(%ebp), %edx\n" /* line 882 | lock */
        "movl %edx, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 883 */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bufferList, convertedFrames */
        /* { scope 2: srcPtr, srcSize, bytesToZero */
        ".Lf114ecc_0011504f:\n"
        "movl 0x10(%ebp), %edx\n" /* line 851 | inNumberFrames */
        "movl %edx, -0x1c(%ebp)\n" /* convertedFrames */
        "movl $0, 0x14(%esp)\n" /* line 852 */
        "movl %edi, 0x10(%esp)\n" /* ioData */
        "leal -0x1c(%ebp), %eax\n" /* convertedFrames, error */
        "movl %eax, 0xc(%esp)\n" /* error */
        "movl %ebx, 8(%esp)\n" /* this */
        "movl $CSampleSound_AudioConverterProc, 4(%esp)\n"
        "movl 0x108(%ebx), %eax\n" /* this, error */
        "movl %eax, (%esp)\n" /* error */
        "calll AudioConverterFillComplexBuffer\n"
        "testl %eax, %eax\n" /* line 853 */
        "jne .Lf114ecc_001150dd\n"
        "movl -0x1c(%ebp), %edx\n" /* line 857 | convertedFrames */
        "cmpl %edx, 0x10(%ebp)\n" /* inNumberFrames */
        "jbe .Lf114ecc_00114ff0\n"
        /* { scope 3 */
        "subl %edx, 0x10(%ebp)\n" /* line 859 | inNumberFrames */
        "movl 0x10(%ebp), %eax\n" /* inNumberFrames */
        "shll $2, %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* bytesToZero */
        /* { scope 4 */
        "movl (%edi), %eax\n" /* line 860 | ioData */
        "testl %eax, %eax\n"
        "je .Lf114ecc_00114ff0\n"
        "movl %edi, %ebx\n" /* ioData, this */
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf114ecc_001150b1\n"
        ".Lf114ecc_001150ae:\n"
        "movl -0x1c(%ebp), %edx\n" /* convertedFrames */
        ".Lf114ecc_001150b1:\n"
        "movl 0xc(%ebx), %eax\n" /* line 863 | this */
        "leal (%eax, %edx, 4), %eax\n"
        "movl -0x3c(%ebp), %edx\n" /* bytesToZero */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "addl $1, %esi\n" /* line 860 | i */
        "addl $0xc, %ebx\n" /* this */
        "cmpl (%edi), %esi\n" /* ioData, i */
        "jb .Lf114ecc_001150ae\n"
        "jmp .Lf114ecc_00114ff0\n"
        /* } scope */
        /* } scope */
        ".Lf114ecc_001150dd:\n"
        "cmpl $0x69354e44, %eax\n" /* line 867 */
        "jne .Lf114ecc_00114ff0\n"
        "jmp .Lf114ecc_00114fe7\n"
        /* } scope */
        /* { scope 2: srcPtr, srcSize, bytesToZero */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf114ecc_001150ed:\n"
        "movl %edi, %ebx\n" /* line 826 | ioData, this */
        "xorl %esi, %esi\n" /* i */
        ".Lf114ecc_001150f1:\n"
        "movl 0xc(%ebx), %eax\n" /* line 829 | this */
        "movl -0x40(%ebp), %edx\n" /* srcSize */
        "movl %edx, 8(%esp)\n"
        "movl -0x44(%ebp), %edx\n" /* srcPtr */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %esi\n" /* line 826 | i */
        "addl $0xc, %ebx\n" /* this */
        "cmpl %esi, (%edi)\n" /* i, ioData */
        "ja .Lf114ecc_001150f1\n"
        "jmp .Lf114ecc_00114f86\n"
        "movl %eax, %ebx\n" /* this */
        /* } scope */
        /* } scope */
        /* } scope */
        "leal -0x24(%ebp), %eax\n" /* line 882 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 691 */
__attribute__((naked))
OSStatus CSampleSound_RenderCallbackProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 691 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* inRefCon */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 697 */
        "je .Lf11512e_00115167\n"
        "movl 0x1c(%ebp), %edx\n" /* line 699 | ioData */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x18(%ebp), %edx\n" /* inNumberFrames */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* ioActionFlags */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CSampleSound_DoRender\n"
        /* } scope */
        "leave\n" /* line 707 */
        "retl\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 702 */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        ".Lf11512e_00115167:\n"
        "movl $0xffffffce, %eax\n"
        /* } scope */
        "leave\n" /* line 707 */
        "retl\n"
    );
}

/* line 223 */
__attribute__((naked))
void CSampleSound_resume_sample(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 223 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: callbackInfo */
        "leal 0x20(%ebx), %eax\n" /* line 228 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x60(%ebx), %eax\n" /* line 230 | this */
        "cmpl $2, %eax\n"
        "je .Lf11516e_001151a9\n"
        "cmpl $8, %eax\n"
        "je .Lf11516e_001151a9\n"
        ".Lf11516e_00115199:\n"
        "movl %esi, (%esp)\n" /* line 246 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: callbackInfo */
        ".Lf11516e_001151a9:\n"
        "movl $4, 0x60(%ebx)\n" /* line 232 | this */
        "movl %ebx, (%esp)\n" /* line 629 | this */
        "calll CSampleSound_UpdateStreamFormat\n"
        "movl %ebx, (%esp)\n" /* line 631 | this */
        "calll CSoundObject_Is3DSound\n"
        "testb %al, %al\n"
        "jne .Lf11516e_00115206\n"
        ".Lf11516e_001151c4:\n"
        "movl %ebx, (%esp)\n" /* line 235 | this */
        "calll CSoundObject_Is3DSound\n"
        "testb %al, %al\n"
        "jne .Lf11516e_00115293\n"
        "cmpb $0, 0x10d(%ebx)\n" /* line 644 | this */
        "je .Lf11516e_00115210\n"
        ".Lf11516e_001151dd:\n"
        "movb $0, 0x10e(%ebx)\n" /* line 661 | this */
        "movl 0x108(%ebx), %eax\n" /* line 242 | this */
        "testl %eax, %eax\n"
        "je .Lf11516e_00115199\n"
        ".Lf11516e_001151ee:\n"
        "movl %eax, (%esp)\n" /* line 244 */
        "calll AudioConverterReset\n"
        "movl %esi, (%esp)\n" /* line 246 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: callbackInfo */
        ".Lf11516e_00115206:\n"
        "movl %ebx, (%esp)\n" /* line 633 | this */
        "calll CSampleSound_Update3DValues\n"
        "jmp .Lf11516e_001151c4\n"
        /* { scope 2 */
        ".Lf11516e_00115210:\n"
        "movl $CSampleSound_RenderCallbackProc, -0x28(%ebp)\n" /* line 648 | callbackInfo */
        "movl %ebx, -0x24(%ebp)\n" /* line 649 | this */
        "movl 8(%ebx), %edi\n" /* line 1040 | this */
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $8, 0x14(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* callbackInfo */
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl 4(%ebx), %eax\n" /* line 655 | this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl %ebx, 8(%esp)\n" /* this */
        "movl $CSampleSound_RenderNotifyProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitAddRenderNotify\n"
        "movb $1, 0x10d(%ebx)\n" /* line 658 | this */
        /* } scope */
        "movb $0, 0x10e(%ebx)\n" /* line 661 | this */
        "movl 0x108(%ebx), %eax\n" /* line 242 | this */
        "testl %eax, %eax\n"
        "jne .Lf11516e_001151ee\n"
        "jmp .Lf11516e_00115199\n"
        ".Lf11516e_00115293:\n"
        "movl (%ebx), %eax\n" /* line 237 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x3c(%eax)\n"
        "cmpb $0, 0x10d(%ebx)\n" /* line 644 | this */
        "jne .Lf11516e_001151dd\n"
        "jmp .Lf11516e_00115210\n"
        "movl %eax, %ebx\n" /* this */
        "movl %esi, (%esp)\n" /* line 246 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 84 */
__attribute__((naked))
OSStatus CSampleSound_InitSample(const CSampleSound * _this, UInt32 inSoundType, UInt32 inSpatializationAlgorithm, UInt32 in3DRenderFlags, UInt32 inDopplerShift)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 84 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: inDataSize */
        "leal 0x20(%esi), %eax\n" /* line 86 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* lock */
        "movl %eax, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl %esi, (%esp)\n" /* line 90 | this */
        "calll CSoundObject_init_sample\n"
        "movl 0x108(%esi), %eax\n" /* line 91 | this */
        "testl %eax, %eax\n"
        "je .Lf1152c0_001152f8\n"
        "movl %eax, (%esp)\n" /* line 93 */
        "calll AudioConverterReset\n"
        ".Lf1152c0_001152f8:\n"
        "movb $0, 0xc(%esi)\n" /* line 98 | this */
        "movl 0xc(%ebp), %eax\n" /* line 99 | inSoundType */
        "movl %eax, 0x10(%esi)\n" /* this */
        "movl $0x28, -0x1c(%ebp)\n" /* inDataSize */
        /* { scope 2 */
        "movl 8(%esi), %ebx\n" /* line 1029 | this, error */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "leal -0x1c(%ebp), %edx\n" /* inDataSize */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x50(%ebp), %edi\n" /* format */
        "movl %edi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* error */
        "movl $1, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        "movl %eax, %ebx\n" /* error */
        /* } scope */
        "testl %eax, %eax\n" /* line 105 */
        "jne .Lf1152c0_001153ee\n"
        "movl %esi, (%esp)\n" /* line 107 | this */
        "calll CSoundObject_Is3DSound\n"
        "cmpb $1, %al\n" /* numChannels */
        "sbbl %eax, %eax\n" /* numChannels */
        "notl %eax\n" /* numChannels */
        "addl $2, %eax\n" /* numChannels */
        "cmpl -0x34(%ebp), %eax\n" /* line 108 */
        "je .Lf1152c0_001153a0\n"
        "movl %eax, -0x34(%ebp)\n" /* line 110 */
        "movl 8(%esi), %ebx\n" /* line 1040 | this, error */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $0x28, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* error */
        "movl $1, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf1152c0_001153ee\n"
        ".Lf1152c0_001153a0:\n"
        "movl %esi, (%esp)\n" /* line 118 | this */
        "calll CSoundObject_Is3DSound\n"
        "testb %al, %al\n"
        "jne .Lf1152c0_00115403\n"
        "movl $5, 0x10(%ebp)\n" /* line 135 | inSpatializationAlgorithm */
        "movl 8(%esi), %ebx\n" /* line 1040 | this, error */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $4, 0x14(%esp)\n"
        "leal 0x10(%ebp), %edx\n" /* inSpatializationAlgorithm */
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* error */
        "movl $1, 8(%esp)\n"
        "movl $0xbb8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        ".Lf1152c0_001153ee:\n"
        "leal -0x24(%ebp), %eax\n" /* line 140 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 141 | error */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inDataSize */
        ".Lf1152c0_00115403:\n"
        "movl 8(%esi), %ebx\n" /* line 1040 | this, error */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $4, 0x14(%esp)\n"
        "leal 0x10(%ebp), %edx\n" /* inSpatializationAlgorithm */
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* error */
        "movl $1, 8(%esp)\n"
        "movl $0xbb8, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 121 */
        "jne .Lf1152c0_001153ee\n"
        "movl 8(%esi), %ebx\n" /* line 1040 | this, error */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $4, 0x14(%esp)\n"
        "leal 0x14(%ebp), %edx\n" /* in3DRenderFlags */
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* error */
        "movl $1, 8(%esp)\n"
        "movl $0xbbb, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 124 */
        "jne .Lf1152c0_001153ee\n"
        "movl 8(%esi), %ebx\n" /* line 1040 | this, error */
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $4, 0x14(%esp)\n"
        "leal 0x18(%ebp), %edx\n" /* inDopplerShift */
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* error */
        "movl $1, 8(%esp)\n"
        "movl $0xbba, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 128 */
        "jne .Lf1152c0_001153ee\n"
        "movb $1, 0x110(%esi)\n" /* line 130 | this */
        "jmp .Lf1152c0_001153ee\n"
        "movl %eax, %ebx\n" /* error */
        "leal -0x24(%ebp), %eax\n" /* line 140 | lock */
        "movl %eax, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* error */
        "calll __Unwind_Resume\n"
    );
}

/* line 485 */
__attribute__((naked))
void CSampleSound_Changed3DDistances(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 485 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: inDataSize */
        "leal 0x20(%ebx), %eax\n" /* line 487 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl $0xc, -0x1c(%ebp)\n" /* inDataSize */
        /* { scope 2 */
        "movl 8(%ebx), %esi\n" /* line 1029 | this */
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "leal -0x1c(%ebp), %edx\n" /* inDataSize */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* params */
        "movl %edx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0xbc2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitGetProperty\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 491 */
        "jne .Lf1154ea_0011562c\n"
        /* { scope 2 */
        "movss 0xdc(%ebx), %xmm0\n" /* line 493 | this */
        "movss %xmm0, -0x40(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_get_3D_distance_factor\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm1\n" /* minDistance */
        "mulss -0x40(%ebp), %xmm1\n" /* minDistance */
        "movss 0xd8(%ebx), %xmm0\n" /* line 494 | this, maxDistance */
        "movss %xmm0, -0x3c(%ebp)\n" /* maxDistance */
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "calll CSoundEngine_get_3D_distance_factor\n"
        "movss -0x68(%ebp), %xmm1\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n" /* maxDistance */
        "mulss -0x3c(%ebp), %xmm0\n" /* maxDistance */
        "ucomiss %xmm0, %xmm1\n" /* line 496 */
        "jae .Lf1154ea_0011563f\n"
        "ucomiss -0x30(%ebp), %xmm1\n" /* line 501 | params */
        "jne .Lf1154ea_001155bf\n"
        ".Lf1154ea_001155b5:\n"
        "jp .Lf1154ea_001155bf\n"
        "ucomiss -0x2c(%ebp), %xmm0\n"
        "jp .Lf1154ea_001155bf\n"
        "je .Lf1154ea_0011562c\n"
        ".Lf1154ea_001155bf:\n"
        "movl 4(%ebx), %eax\n" /* line 503 | this */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "calll CSoundEngine_IsDistanceScalingRequired\n"
        "movss -0x68(%ebp), %xmm1\n"
        "movss -0x58(%ebp), %xmm0\n"
        "testb %al, %al\n"
        "jne .Lf1154ea_00115659\n"
        ".Lf1154ea_001155e2:\n"
        "movss %xmm1, -0x30(%ebp)\n" /* line 505 | params */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 506 */
        "movl $0, -0x28(%ebp)\n" /* line 514 */
        "movl 8(%ebx), %esi\n" /* line 1040 | this */
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $0xc, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* params */
        "movl %edx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0xbc2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        /* } scope */
        ".Lf1154ea_0011562c:\n"
        "movl %edi, (%esp)\n" /* line 519 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 520 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inDataSize */
        /* { scope 2 */
        ".Lf1154ea_0011563f:\n"
        "movaps %xmm1, %xmm0\n" /* line 498 */
        "addss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "ucomiss -0x30(%ebp), %xmm1\n" /* line 501 | params */
        "je .Lf1154ea_001155b5\n"
        "jmp .Lf1154ea_001155bf\n"
        ".Lf1154ea_00115659:\n"
        "divss %xmm0, %xmm1\n" /* line 505 */
        "movss 0x2ed6b4, %xmm0\n" /* 10.0f */
        "mulss %xmm0, %xmm1\n"
        "jmp .Lf1154ea_001155e2\n"
        "movl %eax, %ebx\n" /* this */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 519 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 718 */
__attribute__((naked))
OSStatus CSampleSound_RenderNotifyProc(void *inRefCon, AudioUnitRenderActionFlags *ioActionFlags, const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber, UInt32 inNumberFrames, AudioBufferList *ioData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 718 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* inRefCon */
        /* { scope 1: lock, lock */
        "testl %ebx, %ebx\n" /* line 724 | inRefCon */
        "je .Lf115680_00115794\n"
        "movl 0xc(%ebp), %edx\n" /* line 726 | ioActionFlags */
        "movl (%edx), %eax\n"
        "testb $4, %al\n"
        "jne .Lf115680_001156b4\n"
        "testb $8, %al\n" /* line 730 */
        "je .Lf115680_001156aa\n"
        "cmpb $0, 0x10e(%ebx)\n" /* line 908 | inRefCon */
        "jne .Lf115680_001156f6\n"
        ".Lf115680_001156aa:\n"
        "xorl %eax, %eax\n" /* line 740 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 745 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lock, lock */
        ".Lf115680_001156b4:\n"
        "cmpb $0, 0x10e(%ebx)\n" /* line 890 | inRefCon */
        "je .Lf115680_001156aa\n"
        /* { scope 2: callbackInfo, callbackInfo */
        "leal 0x20(%ebx), %eax\n" /* line 894 | inRefCon */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpb $0, 0x10d(%ebx)\n" /* line 669 */
        "je .Lf115680_001156e5\n"
        "cmpb $0, 0x10e(%ebx)\n"
        "jne .Lf115680_001157a1\n"
        /* } scope */
        /* { scope 2: callbackInfo, callbackInfo */
        ".Lf115680_001156e5:\n"
        "movb $0, 0x10e(%ebx)\n" /* line 915 | inRefCon */
        "movl %esi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf115680_001156aa\n"
        ".Lf115680_001156f6:\n"
        "leal 0x20(%ebx), %eax\n" /* line 912 | inRefCon */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpb $0, 0x10d(%ebx)\n" /* line 669 */
        "je .Lf115680_001156e5\n"
        "cmpb $0, 0x10e(%ebx)\n"
        "je .Lf115680_001156e5\n"
        /* { scope 3 */
        "movl 4(%ebx), %eax\n" /* line 671 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl %ebx, 8(%esp)\n"
        "movl $CSampleSound_RenderNotifyProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitRemoveRenderNotify\n"
        "movl $0, -0x28(%ebp)\n" /* line 674 | lock */
        "movl $0, -0x24(%ebp)\n" /* line 675 */
        "movl 8(%ebx), %edi\n" /* line 1040 | inRefCon */
        "movl 4(%ebx), %eax\n" /* inRefCon */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $8, 0x14(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* lock */
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "jmp .Lf115680_00115807\n"
        "movl %eax, %ebx\n" /* inRefCon */
        /* } scope */
        /* } scope */
        ".Lf115680_00115787:\n"
        "movl %ebx, (%esp)\n" /* line 740 | inRefCon */
        "calll ___cxa_begin_catch\n"
        "calll ___cxa_end_catch\n"
        ".Lf115680_00115794:\n"
        "movl $0xffffffce, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 745 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lock, lock */
        /* { scope 2: callbackInfo, callbackInfo */
        /* { scope 3 */
        ".Lf115680_001157a1:\n"
        "movl 4(%ebx), %eax\n" /* line 671 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl %ebx, 8(%esp)\n"
        "movl $CSampleSound_RenderNotifyProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitRemoveRenderNotify\n"
        "movl $0, -0x20(%ebp)\n" /* line 674 | lock */
        "movl $0, -0x1c(%ebp)\n" /* line 675 */
        "movl 8(%ebx), %edi\n" /* line 1040 | inRefCon */
        "movl 4(%ebx), %eax\n" /* inRefCon */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $8, 0x14(%esp)\n"
        "leal -0x20(%ebp), %edx\n" /* lock */
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        /* } scope */
        /* } scope */
        /* { scope 2: callbackInfo, callbackInfo */
        /* { scope 3 */
        ".Lf115680_00115807:\n"
        "movb $0, 0x10d(%ebx)\n" /* line 678 */
        "jmp .Lf115680_001156e5\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 915 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf115680_00115787\n"
    );
}

/* line 44 */
__attribute__((naked))
void ZN12CSampleSoundD2Ev(void) /* CSampleSound_~CSampleSound */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 44 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $0x3322c8, (%esi)\n" /* this */
        /* { scope 1: lock */
        "cmpb $0, 0x10d(%esi)\n" /* line 48 | this */
        "je .Lf115822_00115859\n"
        "movb $1, 0x10e(%esi)\n" /* line 50 | this */
        "movl $0x4e20, (%esp)\n" /* line 52 */
        "calll usleep\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 54 | this */
        "jne .Lf115822_00115895\n"
        ".Lf115822_00115859:\n"
        "leal 0x20(%esi), %ebx\n" /* this */
        ".Lf115822_0011585c:\n"
        "movl %ebx, 4(%esp)\n" /* line 70 */
        "leal -0x20(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x108(%esi), %eax\n" /* line 71 | this */
        "testl %eax, %eax\n"
        "je .Lf115822_0011587d\n"
        "movl %eax, (%esp)\n" /* line 73 */
        "calll AudioConverterDispose\n"
        ".Lf115822_0011587d:\n"
        "movl %ebx, (%esp)\n" /* line 74 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 75 | this */
        "calll ZN12CSoundObjectD2Ev\n"
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lock */
        ".Lf115822_00115895:\n"
        "movl $0x7530, (%esp)\n" /* line 58 */
        "calll usleep\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 61 | this */
        "je .Lf115822_00115859\n"
        /* { scope 2: callbackInfo */
        "leal 0x20(%esi), %ebx\n" /* line 65 | this */
        "movl %ebx, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 669 | this */
        "je .Lf115822_001158ce\n"
        "cmpb $0, 0x10e(%esi)\n" /* this */
        "jne .Lf115822_001158d8\n"
        ".Lf115822_001158ce:\n"
        "movl %edi, (%esp)\n" /* line 66 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf115822_0011585c\n"
        /* { scope 3 */
        ".Lf115822_001158d8:\n"
        "movl 4(%esi), %eax\n" /* line 671 | this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl %esi, 8(%esp)\n" /* this */
        "movl $CSampleSound_RenderNotifyProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitRemoveRenderNotify\n"
        "movl $0, -0x30(%ebp)\n" /* line 674 | callbackInfo */
        "movl $0, -0x2c(%ebp)\n" /* line 675 */
        "movl 8(%esi), %eax\n" /* line 1040 | this */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $8, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* callbackInfo */
        "movl %edx, 0x10(%esp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movb $0, 0x10d(%esi)\n" /* line 678 | this */
        "jmp .Lf115822_001158ce\n"
        "movl %eax, -0x40(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf115822_00115950:\n"
        "movl %esi, (%esp)\n" /* line 75 | this */
        "calll ZN12CSoundObjectD2Ev\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 1: lock */
        "movl %ebx, (%esp)\n" /* line 74 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf115822_00115950\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 2: callbackInfo */
        "movl %edi, (%esp)\n" /* line 66 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf115822_00115950\n"
    );
}

/* line 44 */
__attribute__((naked))
void ZN12CSampleSoundD1Ev(void) /* CSampleSound_~CSampleSound */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 44 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $0x3322c8, (%esi)\n" /* this */
        /* { scope 1: lock */
        "cmpb $0, 0x10d(%esi)\n" /* line 48 | this */
        "je .Lf11597e_001159b5\n"
        "movb $1, 0x10e(%esi)\n" /* line 50 | this */
        "movl $0x4e20, (%esp)\n" /* line 52 */
        "calll usleep\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 54 | this */
        "jne .Lf11597e_001159f1\n"
        ".Lf11597e_001159b5:\n"
        "leal 0x20(%esi), %ebx\n" /* this */
        ".Lf11597e_001159b8:\n"
        "movl %ebx, 4(%esp)\n" /* line 70 */
        "leal -0x20(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x108(%esi), %eax\n" /* line 71 | this */
        "testl %eax, %eax\n"
        "je .Lf11597e_001159d9\n"
        "movl %eax, (%esp)\n" /* line 73 */
        "calll AudioConverterDispose\n"
        ".Lf11597e_001159d9:\n"
        "movl %ebx, (%esp)\n" /* line 74 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 75 | this */
        "calll ZN12CSoundObjectD2Ev\n"
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lock */
        ".Lf11597e_001159f1:\n"
        "movl $0x7530, (%esp)\n" /* line 58 */
        "calll usleep\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 61 | this */
        "je .Lf11597e_001159b5\n"
        /* { scope 2: callbackInfo */
        "leal 0x20(%esi), %ebx\n" /* line 65 | this */
        "movl %ebx, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 669 | this */
        "je .Lf11597e_00115a2a\n"
        "cmpb $0, 0x10e(%esi)\n" /* this */
        "jne .Lf11597e_00115a34\n"
        ".Lf11597e_00115a2a:\n"
        "movl %edi, (%esp)\n" /* line 66 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf11597e_001159b8\n"
        /* { scope 3 */
        ".Lf11597e_00115a34:\n"
        "movl 4(%esi), %eax\n" /* line 671 | this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl %esi, 8(%esp)\n" /* this */
        "movl $CSampleSound_RenderNotifyProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitRemoveRenderNotify\n"
        "movl $0, -0x30(%ebp)\n" /* line 674 | callbackInfo */
        "movl $0, -0x2c(%ebp)\n" /* line 675 */
        "movl 8(%esi), %eax\n" /* line 1040 | this */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $8, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* callbackInfo */
        "movl %edx, 0x10(%esp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movb $0, 0x10d(%esi)\n" /* line 678 | this */
        "jmp .Lf11597e_00115a2a\n"
        "movl %eax, -0x40(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf11597e_00115aac:\n"
        "movl %esi, (%esp)\n" /* line 75 | this */
        "calll ZN12CSoundObjectD2Ev\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 1: lock */
        "movl %ebx, (%esp)\n" /* line 74 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf11597e_00115aac\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 2: callbackInfo */
        "movl %edi, (%esp)\n" /* line 66 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf11597e_00115aac\n"
    );
}

/* line 44 */
__attribute__((naked))
void ZN12CSampleSoundD0Ev(void) /* CSampleSound_~CSampleSound */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 44 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $0x3322c8, (%esi)\n" /* this */
        /* { scope 1: lock */
        "cmpb $0, 0x10d(%esi)\n" /* line 48 | this */
        "je .Lf115ada_00115b11\n"
        "movb $1, 0x10e(%esi)\n" /* line 50 | this */
        "movl $0x4e20, (%esp)\n" /* line 52 */
        "calll usleep\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 54 | this */
        "jne .Lf115ada_00115b55\n"
        ".Lf115ada_00115b11:\n"
        "leal 0x20(%esi), %ebx\n" /* this */
        ".Lf115ada_00115b14:\n"
        "movl %ebx, 4(%esp)\n" /* line 70 */
        "leal -0x20(%ebp), %ebx\n" /* lock */
        "movl %ebx, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "movl 0x108(%esi), %eax\n" /* line 71 | this */
        "testl %eax, %eax\n"
        "je .Lf115ada_00115b35\n"
        "movl %eax, (%esp)\n" /* line 73 */
        "calll AudioConverterDispose\n"
        ".Lf115ada_00115b35:\n"
        "movl %ebx, (%esp)\n" /* line 74 */
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 75 | this */
        "calll ZN12CSoundObjectD2Ev\n"
        "movl %esi, (%esp)\n" /* this */
        "calll __ZdlPv\n"
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lock */
        ".Lf115ada_00115b55:\n"
        "movl $0x7530, (%esp)\n" /* line 58 */
        "calll usleep\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 61 | this */
        "je .Lf115ada_00115b11\n"
        /* { scope 2: callbackInfo */
        "leal 0x20(%esi), %ebx\n" /* line 65 | this */
        "movl %ebx, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n" /* lock */
        "movl %edi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpb $0, 0x10d(%esi)\n" /* line 669 | this */
        "je .Lf115ada_00115b8e\n"
        "cmpb $0, 0x10e(%esi)\n" /* this */
        "jne .Lf115ada_00115b9b\n"
        ".Lf115ada_00115b8e:\n"
        "movl %edi, (%esp)\n" /* line 66 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf115ada_00115b14\n"
        /* { scope 3 */
        ".Lf115ada_00115b9b:\n"
        "movl 4(%esi), %eax\n" /* line 671 | this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl %esi, 8(%esp)\n" /* this */
        "movl $CSampleSound_RenderNotifyProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitRemoveRenderNotify\n"
        "movl $0, -0x30(%ebp)\n" /* line 674 | callbackInfo */
        "movl $0, -0x2c(%ebp)\n" /* line 675 */
        "movl 8(%esi), %eax\n" /* line 1040 | this */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $8, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* callbackInfo */
        "movl %edx, 0x10(%esp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movb $0, 0x10d(%esi)\n" /* line 678 | this */
        "jmp .Lf115ada_00115b8e\n"
        "movl %eax, -0x40(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf115ada_00115c16:\n"
        "movl %esi, (%esp)\n" /* line 75 | this */
        "calll ZN12CSoundObjectD2Ev\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 1: lock */
        "movl %ebx, (%esp)\n" /* line 74 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf115ada_00115c16\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 2: callbackInfo */
        "movl %edi, (%esp)\n" /* line 66 */
        "calll ZN11StMutexLockD1Ev\n"
        "jmp .Lf115ada_00115c16\n"
    );
}

/* line 888 */
__attribute__((naked))
OSStatus CSampleSound_DoPreRender(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 888 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 0x10e(%ebx)\n" /* line 890 | this */
        "jne .Lf115c44_00115c63\n"
        "xorl %eax, %eax\n" /* line 901 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: callbackInfo */
        ".Lf115c44_00115c63:\n"
        "leal 0x20(%ebx), %eax\n" /* line 894 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpb $0, 0x10d(%ebx)\n" /* line 669 */
        "je .Lf115c44_00115c87\n"
        "cmpb $0, 0x10e(%ebx)\n"
        "jne .Lf115c44_00115ca0\n"
        ".Lf115c44_00115c87:\n"
        "movb $0, 0x10e(%ebx)\n" /* line 897 | this */
        "movl %esi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 901 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: callbackInfo */
        /* { scope 2 */
        ".Lf115c44_00115ca0:\n"
        "movl 4(%ebx), %eax\n" /* line 671 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl %ebx, 8(%esp)\n"
        "movl $CSampleSound_RenderNotifyProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitRemoveRenderNotify\n"
        "movl $0, -0x28(%ebp)\n" /* line 674 | callbackInfo */
        "movl $0, -0x24(%ebp)\n" /* line 675 */
        "movl 8(%ebx), %edi\n" /* line 1040 | this */
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $8, 0x14(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* callbackInfo */
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movb $0, 0x10d(%ebx)\n" /* line 678 */
        "jmp .Lf115c44_00115c87\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 897 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 906 */
__attribute__((naked))
OSStatus CSampleSound_DoPostRender(const CSampleSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 906 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 0x10e(%ebx)\n" /* line 908 | this */
        "jne .Lf115d24_00115d43\n"
        "xorl %eax, %eax\n" /* line 919 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: callbackInfo */
        ".Lf115d24_00115d43:\n"
        "leal 0x20(%ebx), %eax\n" /* line 912 | this */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* lock */
        "movl %esi, (%esp)\n"
        "calll StMutexLock_StMutexLock\n"
        "cmpb $0, 0x10d(%ebx)\n" /* line 669 */
        "je .Lf115d24_00115d67\n"
        "cmpb $0, 0x10e(%ebx)\n"
        "jne .Lf115d24_00115d80\n"
        ".Lf115d24_00115d67:\n"
        "movb $0, 0x10e(%ebx)\n" /* line 915 | this */
        "movl %esi, (%esp)\n"
        "calll ZN11StMutexLockD1Ev\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 919 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: callbackInfo */
        /* { scope 2 */
        ".Lf115d24_00115d80:\n"
        "movl 4(%ebx), %eax\n" /* line 671 */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl %ebx, 8(%esp)\n"
        "movl $CSampleSound_RenderNotifyProc, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitRemoveRenderNotify\n"
        "movl $0, -0x28(%ebp)\n" /* line 674 | callbackInfo */
        "movl $0, -0x24(%ebp)\n" /* line 675 */
        "movl 8(%ebx), %edi\n" /* line 1040 | this */
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetMixerUnit\n"
        "movl $8, 0x14(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* callbackInfo */
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x17, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AudioUnitSetProperty\n"
        "movb $0, 0x10d(%ebx)\n" /* line 678 */
        "jmp .Lf115d24_00115d67\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 915 */
        "calll ZN11StMutexLockD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

