/* ASM dump from: MacMSS_Stream.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS_Stream.cp */

#include "common_types.h"
#include "imports.h"

extern INT32 CStreamSound_sQTStreams; /* 0x0 */

void CStreamSound_CStreamSound(const CStreamSound * _this, CSoundEngine *inEngine);
void ZN12CStreamSoundD1Ev(void); /* CStreamSound_~CStreamSound */
void ZN12CStreamSoundD0Ev(void); /* CStreamSound_~CStreamSound */
void CStreamSound_stop_sample(const CStreamSound * _this);
void CStreamSound_end_sample(const CStreamSound * _this);
void CStreamSound_get_sample_ms_position(const CStreamSound * _this, long int *total_milliseconds, long int *current_milliseconds);
void CStreamSound_set_sample_ms_position(const CStreamSound * _this, long int milliseconds);
void CStreamSound_ChangedVolume(const CStreamSound * _this);
void CStreamSound_UpdateAllStreams(void);
void CStreamSound_close_stream(const CStreamSound * _this);
void CStreamSound_resume_sample(const CStreamSound * _this);
void CStreamSound_set_sample_playback_rate(const CStreamSound * _this, long int playback_rate);
bool CStreamSound_open_stream(const CStreamSound * _this, const char *filename);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN12CStreamSound10sQTStreamsE(void); /* global destructors keyed to CStreamSound_sQTStreams */
static void GLOBAL__I__ZN12CStreamSound10sQTStreamsE(void); /* global constructors keyed to CStreamSound_sQTStreams */
void ZNSt6vectorIP12CStreamSoundSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EE(void); /* std_vector<CStreamSound*, std_allocator<CStreamSound*> >_erase */
void ZNSt6vectorIP12CStreamSoundSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void); /* std_vector<CStreamSound*, std_allocator<CStreamSound*> >__M_insert_aux */

/* line 34 */
__attribute__((naked))
void CStreamSound_CStreamSound(const CStreamSound * _this, CSoundEngine *inEngine)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 34 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0, 8(%esp)\n" /* line 39 */
        "movl 0xc(%ebp), %eax\n" /* inEngine */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CSoundObject_CSoundObject\n"
        "movl $0x3324e8, (%ebx)\n" /* this */
        "movl $0, 0xe0(%ebx)\n" /* this */
        "movl $0, 0xe4(%ebx)\n" /* this */
        "movl $0, 0xe8(%ebx)\n" /* this */
        "movl $0, 0xec(%ebx)\n" /* this */
        "movl $2, 0x10(%ebx)\n" /* line 41 | this */
        "addl $0x14, %esp\n" /* line 42 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 46 */
__attribute__((naked))
void ZN12CStreamSoundD1Ev(void) /* CStreamSound_~CStreamSound */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 46 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x3324e8, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 48 | this */
        "popl %ebp\n"
        "jmp ZN12CSoundObjectD2Ev\n"
    );
}

/* line 46 */
__attribute__((naked))
void ZN12CStreamSoundD0Ev(void) /* CStreamSound_~CStreamSound */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 46 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x3324e8, (%ebx)\n" /* this */
        "movl %ebx, (%esp)\n" /* line 48 | this */
        "calll ZN12CSoundObjectD2Ev\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 105 */
__attribute__((naked))
void CStreamSound_stop_sample(const CStreamSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 105 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpl $4, 0x60(%ebx)\n" /* line 107 | this */
        "je .Lf13de92_0013dea8\n"
        "addl $0x14, %esp\n" /* line 113 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13de92_0013dea8:\n"
        "movl %ebx, (%esp)\n" /* line 109 | this */
        "calll CSoundObject_stop_sample\n"
        "movl 0xe0(%ebx), %eax\n" /* line 111 | this */
        "movl %eax, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 113 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp StopMovie\n" /* line 111 */
    );
}

/* line 138 */
__attribute__((naked))
void CStreamSound_end_sample(const CStreamSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpl $4, 0x60(%ebx)\n" /* line 140 | this */
        "je .Lf13dec4_0013deda\n"
        "addl $0x14, %esp\n" /* line 147 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13dec4_0013deda:\n"
        "movl %ebx, (%esp)\n" /* line 142 | this */
        "calll CSoundObject_end_sample\n"
        "movl 0xe0(%ebx), %eax\n" /* line 144 | this */
        "movl %eax, (%esp)\n"
        "calll StopMovie\n"
        "movl 0xe0(%ebx), %eax\n" /* line 145 | this */
        "movl %eax, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 147 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp GoToBeginningOfMovie\n" /* line 145 */
    );
}

/* line 152 */
__attribute__((naked))
void CStreamSound_get_sample_ms_position(const CStreamSound * _this, long int *total_milliseconds, long int *current_milliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 152 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* total_milliseconds */
        /* { scope 1 */
        "movl 0xe0(%ebx), %eax\n" /* line 154 | this */
        "movl %eax, (%esp)\n"
        "calll GetMovieTimeScale\n"
        "movl %eax, %esi\n" /* theScale */
        "testl %edi, %edi\n" /* line 156 | total_milliseconds */
        "je .Lf13df04_0013df4f\n"
        /* { scope 2 */
        "movl 0xe0(%ebx), %eax\n" /* line 158 | this, theDuration */
        "movl %eax, (%esp)\n" /* theDuration */
        "calll GetMovieDuration\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 160 */
        "cvtsi2ssl %esi, %xmm1\n" /* theScale */
        "divss %xmm1, %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, (%edi)\n" /* total_milliseconds */
        /* } scope */
        ".Lf13df04_0013df4f:\n"
        "movl 0x10(%ebp), %eax\n" /* line 163 | current_milliseconds */
        "testl %eax, %eax\n"
        "je .Lf13df04_0013df89\n"
        /* { scope 2 */
        "movl $0, 4(%esp)\n" /* line 165 */
        "movl 0xe0(%ebx), %eax\n" /* this, theTime */
        "movl %eax, (%esp)\n" /* theTime */
        "calll GetMovieTime\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 167 */
        "cvtsi2ssl %esi, %xmm1\n" /* theScale */
        "divss %xmm1, %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* current_milliseconds */
        "movl %eax, (%edx)\n"
        /* } scope */
        /* } scope */
        ".Lf13df04_0013df89:\n"
        "addl $0x1c, %esp\n" /* line 169 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 174 */
__attribute__((naked))
void CStreamSound_set_sample_ms_position(const CStreamSound * _this, long int milliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 174 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* milliseconds */
        /* { scope 1 */
        "movl 0xe0(%esi), %eax\n" /* line 178 | this, theScale */
        "movl %eax, (%esp)\n" /* theScale */
        "calll GetMovieTimeScale\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 182 | milliseconds */
        "divss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* milliseconds */
        "movl 0xe0(%esi), %eax\n" /* this */
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x10, %esp\n" /* line 183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SetMovieTimeValue\n" /* line 182 */
    );
}

/* line 354 */
__attribute__((naked))
void CStreamSound_ChangedVolume(const CStreamSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 354 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movss 0x64(%ebx), %xmm1\n" /* line 357 | this */
        "leal 0x68(%ebx), %eax\n" /* this, __b */
        "leal 0x6c(%ebx), %edx\n" /* this */
        /* { scope 2 */
        "movss 0x6c(%ebx), %xmm0\n" /* line 211 */
        "ucomiss 0x68(%ebx), %xmm0\n"
        "cmoval %edx, %eax\n"
        /* } scope */
        "mulss (%eax), %xmm1\n" /* line 359 */
        "mulss 0x2ed8b0, %xmm1\n" /* 256.0f */
        "cvttss2si %xmm1, %eax\n" /* volume */
        "cmpw $0x100, %ax\n" /* line 360 */
        "jle .Lf13dfde_0013e08c\n"
        "movl $0x100, %eax\n"
        ".Lf13dfde_0013e01b:\n"
        "movl %eax, 4(%esp)\n" /* line 368 */
        "movl 0xe4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll SetTrackVolume\n"
        "movss 0x6c(%ebx), %xmm0\n" /* line 374 | this */
        "subss 0x68(%ebx), %xmm0\n" /* this */
        "mulss 0x2ed7cc, %xmm0\n" /* 128.0f */
        "cvttss2si %xmm0, %eax\n" /* balance */
        "cmpw $0x80, %ax\n" /* line 375 */
        "jg .Lf13dfde_0013e099\n"
        "cmpw $-0x80, %ax\n" /* line 379 */
        "jge .Lf13dfde_0013e094\n"
        "movl $0xffffff80, %esi\n"
        ".Lf13dfde_0013e054:\n"
        "movl 0xe8(%ebx), %eax\n" /* line 383 | this */
        "movl %eax, (%esp)\n"
        "calll GetMediaHandler\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MediaSetSoundBalance\n"
        "leal 0x80(%esi), %eax\n" /* line 385 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed5c4, %xmm0\n" /* 0.00390625f */
        "movss %xmm0, 0x70(%ebx)\n" /* this */
        /* } scope */
        "addl $0x10, %esp\n" /* line 386 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13dfde_0013e08c:\n"
        "testw %ax, %ax\n" /* line 364 */
        "js .Lf13dfde_0013e0a0\n"
        "cwtl\n"
        "jmp .Lf13dfde_0013e01b\n"
        ".Lf13dfde_0013e094:\n"
        "movswl %ax, %esi\n" /* line 379 */
        "jmp .Lf13dfde_0013e054\n"
        ".Lf13dfde_0013e099:\n"
        "movl $0x80, %esi\n" /* line 375 */
        "jmp .Lf13dfde_0013e054\n"
        ".Lf13dfde_0013e0a0:\n"
        "xorl %eax, %eax\n" /* line 364 */
        "jmp .Lf13dfde_0013e01b\n"
    );
}

/* line 63 */
__attribute__((naked))
void CStreamSound_UpdateAllStreams(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 63 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl __ZN12CStreamSound10sQTStreamsE, %esi\n" /* line 334 */
        "movl 0x1218f84, %eax\n" /* line 352 */
        "cmpl %eax, %esi\n" /* line 65 */
        "jne .Lf13e0aa_0013e0ca\n"
        "jmp .Lf13e0aa_0013e11b\n"
        ".Lf13e0aa_0013e0c3:\n"
        "addl $4, %esi\n" /* line 623 */
        "cmpl %eax, %esi\n" /* line 65 */
        "je .Lf13e0aa_0013e11b\n"
        /* { scope 1 */
        ".Lf13e0aa_0013e0ca:\n"
        "movl (%esi), %ebx\n" /* line 67 | theStream */
        "cmpl $4, 0x60(%ebx)\n" /* line 69 | theStream */
        "jne .Lf13e0aa_0013e0c3\n"
        "movl $0, 4(%esp)\n" /* line 71 */
        "movl 0xe0(%ebx), %eax\n" /* theStream */
        "movl %eax, (%esp)\n"
        "calll MoviesTask\n"
        "movl 0xe0(%ebx), %eax\n" /* line 73 | theStream */
        "movl %eax, (%esp)\n"
        "calll IsMovieDone\n"
        "testb %al, %al\n"
        "je .Lf13e0aa_0013e10f\n"
        "movl 0x80(%ebx), %eax\n" /* line 75 | theStream */
        "cmpl $1, %eax\n"
        "je .Lf13e0aa_0013e133\n"
        "testl %eax, %eax\n" /* line 79 */
        "jne .Lf13e0aa_0013e122\n"
        "cmpl $4, 0x60(%ebx)\n" /* line 89 | theStream */
        "je .Lf13e0aa_0013e140\n"
        ".Lf13e0aa_0013e10f:\n"
        "movl 0x1218f84, %eax\n"
        /* } scope */
        "addl $4, %esi\n" /* line 623 */
        "cmpl %eax, %esi\n" /* line 65 */
        "jne .Lf13e0aa_0013e0ca\n"
        ".Lf13e0aa_0013e11b:\n"
        "addl $0x10, %esp\n" /* line 98 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13e0aa_0013e122:\n"
        "subl $1, %eax\n" /* line 86 */
        "movl %eax, 0x80(%ebx)\n" /* theStream */
        "cmpl $4, 0x60(%ebx)\n" /* line 89 | theStream */
        "jne .Lf13e0aa_0013e10f\n"
        "jmp .Lf13e0aa_0013e140\n"
        ".Lf13e0aa_0013e133:\n"
        "movl $2, 0x60(%ebx)\n" /* line 77 | theStream */
        "cmpl $4, 0x60(%ebx)\n" /* line 89 | theStream */
        "jne .Lf13e0aa_0013e10f\n"
        ".Lf13e0aa_0013e140:\n"
        "movl 0xe0(%ebx), %eax\n" /* line 91 | theStream */
        "movl %eax, (%esp)\n"
        "calll GoToBeginningOfMovie\n"
        "movl 0xe0(%ebx), %eax\n" /* line 92 | theStream */
        "movl %eax, (%esp)\n"
        "calll StartMovie\n"
        "movl $0, 4(%esp)\n" /* line 93 */
        "movl 0xe0(%ebx), %eax\n" /* theStream */
        "movl %eax, (%esp)\n"
        "calll MoviesTask\n"
        "movl 0x1218f84, %eax\n"
        "jmp .Lf13e0aa_0013e0c3\n"
    );
}

/* line 328 */
__attribute__((naked))
void CStreamSound_close_stream(const CStreamSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 328 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xe0(%ebx), %eax\n" /* line 330 | this */
        "testl %eax, %eax\n"
        "je .Lf13e17c_0013e1e8\n"
        "movl %eax, (%esp)\n" /* line 332 */
        "calll StopMovie\n"
        "movl 0xe0(%ebx), %eax\n" /* line 333 | this */
        "movl %eax, (%esp)\n"
        "calll DisposeMovie\n"
        "movl $0, 0xe0(%ebx)\n" /* line 334 | this */
        "movl $2, 0x60(%ebx)\n" /* line 336 | this */
        "movl __ZN12CStreamSound10sQTStreamsE, %edx\n" /* line 334 */
        "movl %edx, %eax\n" /* line 338 */
        "movl 0x1218f84, %ecx\n" /* line 603 */
        "cmpl %ecx, %edx\n" /* line 338 */
        "je .Lf13e17c_0013e1e8\n"
        "cmpl (%edx), %ebx\n" /* line 340 | this */
        "je .Lf13e17c_0013e1d8\n"
        ".Lf13e17c_0013e1cd:\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %ecx, %eax\n" /* line 338 */
        "je .Lf13e17c_0013e1e8\n"
        "cmpl (%eax), %ebx\n" /* line 340 | this */
        "jne .Lf13e17c_0013e1cd\n"
        ".Lf13e17c_0013e1d8:\n"
        "movl %eax, 4(%esp)\n" /* line 342 */
        "movl $__ZN12CStreamSound10sQTStreamsE, (%esp)\n"
        "calll ZNSt6vectorIP12CStreamSoundSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EE\n"
        ".Lf13e17c_0013e1e8:\n"
        "addl $0x14, %esp\n" /* line 347 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 118 */
__attribute__((naked))
void CStreamSound_resume_sample(const CStreamSound * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 118 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x60(%ebx), %eax\n" /* line 120 | this */
        "cmpl $2, %eax\n"
        "je .Lf13e1ee_0013e20b\n"
        "cmpl $8, %eax\n"
        "je .Lf13e1ee_0013e20b\n"
        ".Lf13e1ee_0013e205:\n"
        "addl $0x14, %esp\n" /* line 133 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13e1ee_0013e20b:\n"
        "movl %ebx, (%esp)\n" /* line 122 | this */
        "calll CSoundObject_resume_sample\n"
        "movl 0xec(%ebx), %edx\n" /* line 124 | this */
        "movl 0x7c(%ebx), %eax\n" /* this */
        "cmpl %eax, %edx\n"
        "je .Lf13e1ee_0013e256\n"
        "cmpl $4, 0x60(%ebx)\n" /* line 393 | this */
        "jne .Lf13e1ee_0013e205\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 396 */
        "cvtsi2ssl %edx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "mulss 0x2ed8b4, %xmm0\n" /* 65536.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xe0(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll SetMovieRate\n"
        "addl $0x14, %esp\n" /* line 133 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13e1ee_0013e256:\n"
        "movl 0xe0(%ebx), %eax\n" /* line 130 | this */
        "movl %eax, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 133 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp StartMovie\n" /* line 130 */
    );
}

/* line 188 */
__attribute__((naked))
void CStreamSound_set_sample_playback_rate(const CStreamSound * _this, long int playback_rate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 188 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* playback_rate */
        "cmpl %eax, 0x7c(%ebx)\n" /* line 190 | this */
        "je .Lf13e26a_0013e28e\n"
        "movl %eax, 4(%esp)\n" /* line 192 */
        "movl %ebx, (%esp)\n" /* this */
        "calll CSoundObject_set_sample_playback_rate\n"
        "cmpl $4, 0x60(%ebx)\n" /* line 393 | this */
        "je .Lf13e26a_0013e294\n"
        ".Lf13e26a_0013e28e:\n"
        "addl $0x14, %esp\n" /* line 196 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13e26a_0013e294:\n"
        "cvtsi2ssl 0x7c(%ebx), %xmm0\n" /* line 396 | this */
        "cvtsi2ssl 0xec(%ebx), %xmm1\n" /* this */
        "divss %xmm1, %xmm0\n"
        "mulss 0x2ed8b4, %xmm0\n" /* 65536.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* playback_rate */
        "movl 0xe0(%ebx), %eax\n" /* this */
        "movl %eax, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n" /* line 196 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SetMovieRate\n" /* line 396 */
    );
}

/* line 203 */
__attribute__((naked))
bool CStreamSound_open_stream(const CStreamSound * _this, const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 203 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 205 | this */
        "movl %esi, (%esp)\n" /* this */
        "calll *0x2c(%eax)\n"
        "leal -0xba(%ebp), %ebx\n" /* line 210 | ref */
        "movl %ebx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* filename, error */
        "movl %eax, (%esp)\n" /* error */
        "calll MacFolders_GetDataFolderItemRef\n"
        "testl %eax, %eax\n" /* line 211 */
        "je .Lf13e2c8_0013e307\n"
        ".Lf13e2c8_0013e2f8:\n"
        "xorl %ebx, %ebx\n" /* line 255 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 323 | soundDesc */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13e2c8_0013e307:\n"
        "movl $0, 0x14(%esp)\n" /* line 226 */
        "leal -0x6a(%ebp), %edi\n" /* spec */
        "movl %edi, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 227 */
        "jne .Lf13e2c8_0013e2f8\n"
        "movl $1, 8(%esp)\n" /* line 236 */
        "leal -0x1a(%ebp), %eax\n" /* refNum */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll OpenMovieFile\n"
        "testw %ax, %ax\n" /* line 237 */
        "jne .Lf13e2c8_0013e2f8\n"
        "calll MacDisplay_GetMainWindow\n" /* line 245 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %edi\n" /* savePort */
        "movl %edi, (%esp)\n"
        "calll StPortState_StPortState\n"
        "movw $0, -0x1c(%ebp)\n" /* line 247 | resID */
        "movl $0, 0x14(%esp)\n" /* line 248 */
        "movl $1, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* resID */
        "movl %eax, 8(%esp)\n"
        "movswl -0x1a(%ebp), %eax\n" /* refNum */
        "movl %eax, 4(%esp)\n"
        "leal 0xe0(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll NewMovieFromFile\n"
        "movl %eax, %ebx\n"
        "movswl -0x1a(%ebp), %eax\n" /* line 250 | refNum */
        "movl %eax, (%esp)\n"
        "calll CloseMovieFile\n"
        "testw %bx, %bx\n" /* line 252 */
        "je .Lf13e2c8_0013e3d0\n"
        "xorl %ebx, %ebx\n"
        ".Lf13e2c8_0013e3bb:\n"
        "movl %edi, (%esp)\n" /* line 322 */
        "calll ZN11StPortStateD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 323 | soundDesc */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf13e2c8_0013e3d0:\n"
        "movl (%esi), %eax\n" /* line 260 | this */
        "movl %esi, (%esp)\n" /* this */
        "calll *0x30(%eax)\n"
        "movl 0xe0(%esi), %eax\n" /* line 265 | this */
        "movl %eax, (%esp)\n"
        "calll GoToBeginningOfMovie\n"
        "movl 0xe0(%esi), %eax\n" /* line 266 | this */
        "movl %eax, (%esp)\n"
        "calll GetMoviePreferredRate\n"
        "movl %eax, %ebx\n"
        "movl $0, 4(%esp)\n"
        "movl 0xe0(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll GetMovieTime\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xe0(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll PrerollMovie\n"
        "movl $6, 0xc(%esp)\n" /* line 270 */
        "movl $0x65617273, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 0xe0(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll GetMovieIndTrackType\n"
        "movl %eax, 0xe4(%esi)\n" /* this */
        "movl %eax, (%esp)\n" /* line 272 */
        "calll GetTrackMedia\n"
        "movl %eax, 0xe8(%esi)\n" /* this */
        "movl $2, 0x60(%esi)\n" /* line 278 | this */
        "movl $0x3f800000, %eax\n" /* line 279 */
        "movl %eax, 0x64(%esi)\n" /* this */
        "movl %eax, 0x68(%esi)\n" /* line 280 | this */
        "movl %eax, 0x6c(%esi)\n" /* line 281 | this */
        "movl $0x3f000000, 0x70(%esi)\n" /* line 282 | this */
        "movl %eax, 0x74(%esi)\n" /* line 283 | this */
        "movl %eax, 0x78(%esi)\n" /* line 284 | this */
        "movl $1, 0x80(%esi)\n" /* line 285 | this */
        "movl $0, (%esp)\n" /* line 289 */
        "calll NewHandle\n"
        "movl %eax, %ebx\n" /* soundDesc */
        "movl %eax, 8(%esp)\n" /* line 290 */
        "movl $1, 4(%esp)\n"
        "movl 0xe8(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll GetMediaSampleDescription\n"
        "movl %ebx, (%esp)\n" /* line 291 | soundDesc */
        "calll GetHandleSize\n"
        "testl %eax, %eax\n"
        "jle .Lf13e2c8_0013e530\n"
        "movl (%ebx), %eax\n" /* line 293 | soundDesc */
        "movl 0x20(%eax), %eax\n"
        "addl $0x8000, %eax\n"
        "shrl $0x10, %eax\n"
        "movl %eax, 0x7c(%esi)\n" /* this */
        "movl $0, 0xa8(%esi)\n" /* line 295 | this */
        "movl (%ebx), %eax\n" /* line 296 | soundDesc */
        "movzwl 0x1a(%eax), %edx\n"
        "cmpw $0x10, %dx\n"
        "je .Lf13e2c8_0013e54c\n"
        "cmpw $0x20, %dx\n" /* line 300 */
        "je .Lf13e2c8_0013e55a\n"
        ".Lf13e2c8_0013e4e8:\n"
        "cmpw $2, 0x18(%eax)\n" /* line 304 */
        "je .Lf13e2c8_0013e543\n"
        ".Lf13e2c8_0013e4ef:\n"
        "movl %ebx, (%esp)\n" /* line 315 | soundDesc */
        "calll DisposeHandle\n"
        "movl 0x7c(%esi), %eax\n" /* line 317 | this */
        "movl %eax, 0xec(%esi)\n" /* this */
        "movl %esi, -0x20(%ebp)\n" /* line 320 | this */
        "movl 0x1218f84, %edx\n" /* line 604 */
        "cmpl 0x1218f88, %edx\n"
        "je .Lf13e2c8_0013e568\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf13e2c8_0013e51d\n"
        "movl %esi, (%edx)\n"
        "movl 0x1218f84, %edx\n"
        ".Lf13e2c8_0013e51d:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl %edx, 0x1218f84\n"
        "movl $1, %ebx\n" /* soundDesc */
        "jmp .Lf13e2c8_0013e3bb\n"
        ".Lf13e2c8_0013e530:\n"
        "movl $0x2b11, 0x7c(%esi)\n" /* line 312 | this */
        "movl $0, 0xa8(%esi)\n" /* line 313 | this */
        "jmp .Lf13e2c8_0013e4ef\n"
        ".Lf13e2c8_0013e543:\n"
        "orl $2, 0xa8(%esi)\n" /* line 306 | this */
        "jmp .Lf13e2c8_0013e4ef\n"
        ".Lf13e2c8_0013e54c:\n"
        "movl $1, 0xa8(%esi)\n" /* line 298 | this */
        "movl (%ebx), %eax\n" /* soundDesc */
        "jmp .Lf13e2c8_0013e4e8\n"
        ".Lf13e2c8_0013e55a:\n"
        "movl $8, 0xa8(%esi)\n" /* line 302 | this */
        "movl (%ebx), %eax\n" /* soundDesc */
        "jmp .Lf13e2c8_0013e4e8\n"
        ".Lf13e2c8_0013e568:\n"
        "leal -0x20(%ebp), %eax\n" /* line 610 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $__ZN12CStreamSound10sQTStreamsE, (%esp)\n"
        "calll ZNSt6vectorIP12CStreamSoundSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_\n"
        "movl $1, %ebx\n" /* line 322 | soundDesc */
        "jmp .Lf13e2c8_0013e3bb\n"
        "movl %eax, %ebx\n" /* soundDesc */
        "movl %edi, (%esp)\n"
        "calll ZN11StPortStateD1Ev\n"
        "movl %ebx, (%esp)\n" /* soundDesc */
        "calll __Unwind_Resume\n"
    );
}

/* line 398 */
static __attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 398 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 29 */
        "je .Lf13e59c_0013e5ac\n"
        ".Lf13e59c_0013e5aa:\n"
        "leave\n" /* line 398 */
        "retl\n"
        ".Lf13e59c_0013e5ac:\n"
        "cmpl $1, %eax\n" /* line 29 */
        "je .Lf13e59c_0013e5dc\n"
        "testl %eax, %eax\n"
        "jne .Lf13e59c_0013e5aa\n"
        "movl 0x1218f84, %edx\n" /* line 273 */
        "movl __ZN12CStreamSound10sQTStreamsE, %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf13e59c_0013e5ce\n"
        ".Lf13e59c_0013e5c7:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf13e59c_0013e5c7\n"
        ".Lf13e59c_0013e5ce:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf13e59c_0013e5aa\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "leave\n" /* line 398 */
        "retl\n"
        ".Lf13e59c_0013e5dc:\n"
        "movl $0, __ZN12CStreamSound10sQTStreamsE\n" /* line 85 */
        "movl $0, 0x1218f84\n"
        "movl $0, 0x1218f88\n"
        "leave\n" /* line 398 */
        "retl\n"
    );
}

/* line 400 */
static __attribute__((naked))
void GLOBAL__D__ZN12CStreamSound10sQTStreamsE(void) /* global destructors keyed to CStreamSound_sQTStreams */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 400 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 399 */
static __attribute__((naked))
void GLOBAL__I__ZN12CStreamSound10sQTStreamsE(void) /* global constructors keyed to CStreamSound_sQTStreams */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 399 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 110 */
__attribute__((naked))
void ZNSt6vectorIP12CStreamSoundSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EE(void) /* std_vector<CStreamSound*, std_allocator<CStreamSound*> >_erase */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 110 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* __position */
        "movl 4(%esi), %eax\n" /* line 352 | this */
        "leal 4(%ebx), %edx\n" /* line 654 | __position */
        "cmpl %eax, %edx\n" /* line 112 */
        "je .Lf2c171a_002c1747\n"
        /* { scope 1 */
        "subl %edx, %eax\n" /* line 300 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* __position */
        "calll memmove\n"
        "movl 4(%esi), %eax\n" /* this */
        /* } scope */
        ".Lf2c171a_002c1747:\n"
        "subl $4, %eax\n" /* line 114 */
        "movl %eax, 4(%esi)\n" /* this */
        "movl %ebx, %eax\n" /* line 116 | __position */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorIP12CStreamSoundSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) /* std_vector<CStreamSound*, std_allocator<CStreamSound*> >__M_insert_aux */
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
        "je .Lf2c1756_002c17ae\n"
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf2c1756_002c1776\n"
        "movl -4(%edx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %edx\n"
        ".Lf2c1756_002c1776:\n"
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
        ".Lf2c1756_002c17ae:\n"
        "movl %edx, %eax\n" /* line 759 */
        "subl (%edi), %eax\n" /* this */
        "sarl $2, %eax\n"
        "cmpl $0x3fffffff, %eax\n" /* line 265 */
        "je .Lf2c1756_002c187c\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2c1756_002c185a\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2c1756_002c17cd:\n"
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
        "je .Lf2c1756_002c1806\n"
        "movl 0x10(%ebp), %ecx\n" /* __x */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        ".Lf2c1756_002c1806:\n"
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
        "je .Lf2c1756_002c1836\n"
        ".Lf2c1756_002c182f:\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %edx, %eax\n" /* line 173 */
        "jne .Lf2c1756_002c182f\n"
        ".Lf2c1756_002c1836:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2c1756_002c1842\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2c1756_002c1842:\n"
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
        ".Lf2c1756_002c185a:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2c1756_002c1872\n"
        "cmpl $0x3fffffff, %edx\n" /* line 85 */
        "jbe .Lf2c1756_002c17cd\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2c1756_002c1872:\n"
        "movl $0x3fffffff, %edx\n" /* line 272 */
        "jmp .Lf2c1756_002c17cd\n"
        ".Lf2c1756_002c187c:\n"
        "movl $0x215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}

