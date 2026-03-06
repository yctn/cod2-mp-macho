/* ASM dump from: CColorConverter.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CColorConverter.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CColorConverter.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

extern unsigned char sStdConverterARGB[]; /* writable BSS — vtable set by global ctor */
extern unsigned char sStdConverterABGR[]; /* writable BSS */
extern unsigned char sATI4CompsConverterARGB[]; /* writable BSS */
extern unsigned char sATI4CompsConverterABGR[]; /* writable BSS */

void StdConverterARGB_Convert(const StdConverterARGB * _this, const void * pDst, const void * pSrc);
void StdConverterABGR_Convert4ub4f(const StdConverterABGR * _this, const void * pDst, const float *Src);
void StdConverterARGB_Convert4f4ubInverse(const StdConverterARGB * _this, float *Dest, const UINT8 *Src);
void StdConverterABGR_Convert4f4ubInverse(const StdConverterABGR * _this, float *Dest, const UINT8 *Src);
void StdConverterARGB_Convert3f4ubInverse(const StdConverterARGB * _this, float *Dest, const UINT8 *Src);
void StdConverterABGR_Convert3f4ubInverse(const StdConverterABGR * _this, float *Dest, const UINT8 *Src);
void StdConverterABGR_ArrayConvert4f4ub(const StdConverterABGR * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices);
void ATI4CompsConverterARGB_Convert(const ATI4CompsConverterARGB * _this, const void * pDst, const void * pSrc);
void ATI4CompsConverterABGR_Convert(const ATI4CompsConverterABGR * _this, const void * pDst, const void * pSrc);
void ATI4CompsConverterABGR_Convert4ub4f(const ATI4CompsConverterABGR * _this, const void * pDst, const float *Src);
void ATI4CompsConverterARGB_Convert4f4ubInverse(const ATI4CompsConverterARGB * _this, float *Dest, const UINT8 *Src);
void ATI4CompsConverterABGR_Convert4f4ubInverse(const ATI4CompsConverterABGR * _this, float *Dest, const UINT8 *Src);
void ATI4CompsConverterARGB_Convert3f4ubInverse(const ATI4CompsConverterARGB * _this, float *Dest, const UINT8 *Src);
void ATI4CompsConverterABGR_Convert3f4ubInverse(const ATI4CompsConverterABGR * _this, float *Dest, const UINT8 *Src);
void ATI4CompsConverterABGR_ArrayConvert4f4ub(const ATI4CompsConverterABGR * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices);
void StdConverterABGR_Convert(const StdConverterABGR * _this, const void * pDst, const void * pSrc);
void StdConverterARGB_Convert4ub4f(const StdConverterARGB * _this, const void * pDst, const float *Src);
void StdConverterARGB_ArrayConvert4f4ubG3(const StdConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices);
void ATI4CompsConverterARGB_Convert4ub4f(const ATI4CompsConverterARGB * _this, const void * pDst, const float *Src);
void ATI4CompsConverterARGB_ArrayConvert4f4ubG3(const ATI4CompsConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices);
void ATI4CompsConverterARGB_ArrayConvert4f4ub(const ATI4CompsConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices);
void StdConverterARGB_ArrayConvert4f4ub(const StdConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices);
const CColorConverter * CColorConverter_GetColorConverter(Format SrcFormat);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN15CColorConverter17GetColorConverterENS_6FormatE(void); /* global destructors keyed to CColorConverter_GetColorConverter */
static void GLOBAL__I__ZN15CColorConverter17GetColorConverterENS_6FormatE(void); /* global constructors keyed to CColorConverter_GetColorConverter */
void CColorConverter_Convert4ub4f(const CColorConverter * _this, const void * Dest, const float *Src);
void CColorConverter_Convert4f4ubInverse(const CColorConverter * _this, float *Dest, const UINT8 *Src);
void CColorConverter_Convert3f4ubInverse(const CColorConverter * _this, float *Dest, const UINT8 *Src);
void CColorConverter_ArrayConvert4f4ub(const CColorConverter * _this, const void * pDst, const float * pSrc, UINT32 NumVertices);
ConverterType CColorConverter_GetType(const CColorConverter * _this);
void ZN15CColorConverterD1Ev(void); /* CColorConverter_~CColorConverter */
void ZN15CColorConverterD0Ev(void); /* CColorConverter_~CColorConverter */
ConverterType ATI4CompsConverterARGB_GetType(const ATI4CompsConverterARGB * _this);
ConverterType ATI4CompsConverterABGR_GetType(const ATI4CompsConverterABGR * _this);
ConverterType StdConverterARGB_GetType(const StdConverterARGB * _this);
ConverterType StdConverterABGR_GetType(const StdConverterABGR * _this);
void ZN16StdConverterARGBD1Ev(void); /* StdConverterARGB_~StdConverterARGB */
void ZN16StdConverterARGBD0Ev(void); /* StdConverterARGB_~StdConverterARGB */
void ZN16StdConverterABGRD1Ev(void); /* StdConverterABGR_~StdConverterABGR */
void ZN16StdConverterABGRD0Ev(void); /* StdConverterABGR_~StdConverterABGR */
void ZN22ATI4CompsConverterARGBD1Ev(void); /* ATI4CompsConverterARGB_~ATI4CompsConverterARGB */
void ZN22ATI4CompsConverterARGBD0Ev(void); /* ATI4CompsConverterARGB_~ATI4CompsConverterARGB */
void ZN22ATI4CompsConverterABGRD1Ev(void); /* ATI4CompsConverterABGR_~ATI4CompsConverterABGR */
void ZN22ATI4CompsConverterABGRD0Ev(void); /* ATI4CompsConverterABGR_~ATI4CompsConverterABGR */

/* line 59 */
__attribute__((naked))
void StdConverterARGB_Convert(const StdConverterARGB * _this, const void * pDst, const void * pSrc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 59 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %eax\n" /* line 69 | pSrc */
        "movl (%eax), %eax\n"
        "rorl $8, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* pDst */
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 73 */
        "retl\n"
    );
}

/* line 131 */
__attribute__((naked))
void StdConverterABGR_Convert4ub4f(const StdConverterABGR * _this, const void * pDst, const float *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 134 */
        "retl\n"
    );
}

/* line 139 */
__attribute__((naked))
void StdConverterARGB_Convert4f4ubInverse(const StdConverterARGB * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 139 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %ecx\n" /* Dest */
        "movl 0x10(%ebp), %edx\n" /* Src */
        /* { scope 1 */
        "movzbl 1(%edx), %eax\n" /* line 149 */
        "cvtsi2ssl %eax, %xmm2\n" /* g */
        "movzbl 2(%edx), %eax\n" /* line 150 */
        "cvtsi2ssl %eax, %xmm3\n" /* b */
        "movzbl 3(%edx), %eax\n" /* line 151 */
        "cvtsi2ssl %eax, %xmm4\n" /* a */
        "movzbl (%edx), %eax\n" /* line 153 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "mulss %xmm1, %xmm2\n" /* line 154 */
        "movss %xmm2, 4(%ecx)\n"
        "mulss %xmm1, %xmm3\n" /* line 155 */
        "movss %xmm3, 8(%ecx)\n"
        "mulss %xmm1, %xmm4\n" /* line 156 */
        "movss %xmm4, 0xc(%ecx)\n"
        /* } scope */
        "popl %ebp\n" /* line 157 */
        "retl\n"
    );
}

/* line 160 */
__attribute__((naked))
void StdConverterABGR_Convert4f4ubInverse(const StdConverterABGR * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 160 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 163 */
        "retl\n"
    );
}

/* line 168 */
__attribute__((naked))
void StdConverterARGB_Convert3f4ubInverse(const StdConverterARGB * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 168 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %ecx\n" /* Dest */
        "movl 0x10(%ebp), %edx\n" /* Src */
        /* { scope 1 */
        "movzbl 1(%edx), %eax\n" /* line 178 */
        "cvtsi2ssl %eax, %xmm2\n" /* g */
        "movzbl 2(%edx), %eax\n" /* line 179 */
        "cvtsi2ssl %eax, %xmm3\n" /* b */
        "movzbl (%edx), %eax\n" /* line 181 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "mulss %xmm1, %xmm2\n" /* line 182 */
        "movss %xmm2, 4(%ecx)\n"
        "mulss %xmm1, %xmm3\n" /* line 183 */
        "movss %xmm3, 8(%ecx)\n"
        /* } scope */
        "popl %ebp\n" /* line 184 */
        "retl\n"
    );
}

/* line 187 */
__attribute__((naked))
void StdConverterABGR_Convert3f4ubInverse(const StdConverterABGR * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 187 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 190 */
        "retl\n"
    );
}

/* line 425 */
__attribute__((naked))
void StdConverterABGR_ArrayConvert4f4ub(const StdConverterABGR * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 425 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 428 */
        "retl\n"
    );
}

/* line 433 */
__attribute__((naked))
void ATI4CompsConverterARGB_Convert(const ATI4CompsConverterARGB * _this, const void * pDst, const void * pSrc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 433 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %eax\n" /* line 438 | pSrc */
        "movl (%eax), %eax\n"
        "rorl $0x18, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* pDst */
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 442 */
        "retl\n"
    );
}

/* line 445 */
__attribute__((naked))
void ATI4CompsConverterABGR_Convert(const ATI4CompsConverterABGR * _this, const void * pDst, const void * pSrc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 445 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %eax\n" /* line 450 | pSrc */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* pDst */
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 451 */
        "retl\n"
    );
}

/* line 491 */
__attribute__((naked))
void ATI4CompsConverterABGR_Convert4ub4f(const ATI4CompsConverterABGR * _this, const void * pDst, const float *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 491 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 494 */
        "retl\n"
    );
}

/* line 499 */
__attribute__((naked))
void ATI4CompsConverterARGB_Convert4f4ubInverse(const ATI4CompsConverterARGB * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 499 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %ecx\n" /* Dest */
        "movl 0x10(%ebp), %edx\n" /* Src */
        /* { scope 1 */
        "movzbl 2(%edx), %eax\n" /* line 510 */
        "cvtsi2ssl %eax, %xmm2\n" /* g */
        "movzbl 1(%edx), %eax\n" /* line 511 */
        "cvtsi2ssl %eax, %xmm3\n" /* b */
        "movzbl (%edx), %eax\n" /* line 512 */
        "cvtsi2ssl %eax, %xmm4\n" /* a */
        "movzbl 3(%edx), %eax\n" /* line 514 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "mulss %xmm1, %xmm2\n" /* line 515 */
        "movss %xmm2, 4(%ecx)\n"
        "mulss %xmm1, %xmm3\n" /* line 516 */
        "movss %xmm3, 8(%ecx)\n"
        "mulss %xmm1, %xmm4\n" /* line 517 */
        "movss %xmm4, 0xc(%ecx)\n"
        /* } scope */
        "popl %ebp\n" /* line 518 */
        "retl\n"
    );
}

/* line 521 */
__attribute__((naked))
void ATI4CompsConverterABGR_Convert4f4ubInverse(const ATI4CompsConverterABGR * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 521 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 524 */
        "retl\n"
    );
}

/* line 528 */
__attribute__((naked))
void ATI4CompsConverterARGB_Convert3f4ubInverse(const ATI4CompsConverterARGB * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 528 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %ecx\n" /* Dest */
        "movl 0x10(%ebp), %edx\n" /* Src */
        /* { scope 1 */
        "movzbl 2(%edx), %eax\n" /* line 539 */
        "cvtsi2ssl %eax, %xmm2\n" /* g */
        "movzbl 1(%edx), %eax\n" /* line 540 */
        "cvtsi2ssl %eax, %xmm3\n" /* b */
        "movzbl 3(%edx), %eax\n" /* line 542 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "mulss %xmm1, %xmm2\n" /* line 543 */
        "movss %xmm2, 4(%ecx)\n"
        "mulss %xmm1, %xmm3\n" /* line 544 */
        "movss %xmm3, 8(%ecx)\n"
        /* } scope */
        "popl %ebp\n" /* line 545 */
        "retl\n"
    );
}

/* line 548 */
__attribute__((naked))
void ATI4CompsConverterABGR_Convert3f4ubInverse(const ATI4CompsConverterABGR * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 548 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 551 */
        "retl\n"
    );
}

/* line 799 */
__attribute__((naked))
void ATI4CompsConverterABGR_ArrayConvert4f4ub(const ATI4CompsConverterABGR * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 799 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 802 */
        "retl\n"
    );
}

/* line 76 */
__attribute__((naked))
void StdConverterABGR_Convert(const StdConverterABGR * _this, const void * pDst, const void * pSrc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 76 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %eax\n" /* line 83 | pSrc */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* pDst */
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 94 */
        "retl\n"
    );
}

/* line 99 */
__attribute__((naked))
void StdConverterARGB_Convert4ub4f(const StdConverterARGB * _this, const void * pDst, const float *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "subl $0x24, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* Src, pDst */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 106 | r */
        "movss 4(%eax), %xmm1\n" /* line 107 | g */
        "movss 8(%eax), %xmm3\n" /* line 108 | b */
        "movss 0xc(%eax), %xmm4\n" /* line 109 | a */
        "pxor %xmm2, %xmm2\n" /* line 58 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lfd856_0000d970\n"
        "movaps %xmm2, %xmm6\n"
        ".Lfd856_0000d882:\n"
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lfd856_0000d95a\n"
        "movaps %xmm2, %xmm5\n"
        ".Lfd856_0000d88e:\n"
        "ucomiss %xmm3, %xmm2\n"
        "jbe .Lfd856_0000d944\n"
        "movaps %xmm2, %xmm1\n"
        ".Lfd856_0000d89a:\n"
        "ucomiss %xmm4, %xmm2\n"
        "ja .Lfd856_0000d8b4\n"
        "ucomiss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "jbe .Lfd856_0000d9b6\n"
        "movss 0x2ed5d4, %xmm2\n" /* 255.0f */
        ".Lfd856_0000d8b4:\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 126 | 0.5f */
        "addss %xmm0, %xmm1\n"
        "fnstcw -0x12(%ebp)\n"
        "movzwl -0x12(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x14(%ebp)\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "flds -0x24(%ebp)\n"
        "fldcw -0x14(%ebp)\n"
        "fistpll -0x20(%ebp)\n"
        "fldcw -0x12(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0x18, %ecx\n"
        "addss %xmm0, %xmm5\n"
        "movss %xmm5, -0x24(%ebp)\n"
        "flds -0x24(%ebp)\n"
        "fldcw -0x14(%ebp)\n"
        "fistpll -0x20(%ebp)\n"
        "fldcw -0x12(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "shll $0x10, %eax\n"
        "addl %eax, %ecx\n"
        "addss %xmm0, %xmm6\n"
        "movss %xmm6, -0x24(%ebp)\n"
        "flds -0x24(%ebp)\n"
        "fldcw -0x14(%ebp)\n"
        "fistpll -0x20(%ebp)\n"
        "fldcw -0x12(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %ecx\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n"
        "flds -0x24(%ebp)\n"
        "fldcw -0x14(%ebp)\n"
        "fistpll -0x20(%ebp)\n"
        "fldcw -0x12(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "addl %eax, %ecx\n"
        "rorl $8, %ecx\n" /* line 69 */
        "movl 0xc(%ebp), %eax\n" /* pDst */
        "movl %ecx, (%eax)\n"
        /* } scope */
        "leave\n" /* line 128 */
        "retl\n"
        /* { scope 1 */
        ".Lfd856_0000d944:\n"
        "ucomiss 0x2ed5d0, %xmm3\n" /* line 58 | 1.0f */
        "jbe .Lfd856_0000d996\n"
        "movss 0x2ed5d4, %xmm1\n" /* 255.0f */
        "jmp .Lfd856_0000d89a\n"
        ".Lfd856_0000d95a:\n"
        "ucomiss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "jbe .Lfd856_0000d9a6\n"
        "movss 0x2ed5d4, %xmm5\n" /* 255.0f */
        "jmp .Lfd856_0000d88e\n"
        ".Lfd856_0000d970:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lfd856_0000d986\n"
        "movss 0x2ed5d4, %xmm6\n" /* 255.0f */
        "jmp .Lfd856_0000d882\n"
        ".Lfd856_0000d986:\n"
        "movaps %xmm0, %xmm6\n"
        "mulss 0x2ed5d4, %xmm6\n" /* 255.0f */
        "jmp .Lfd856_0000d882\n"
        ".Lfd856_0000d996:\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x2ed5d4, %xmm1\n" /* 255.0f */
        "jmp .Lfd856_0000d89a\n"
        ".Lfd856_0000d9a6:\n"
        "movaps %xmm1, %xmm5\n"
        "mulss 0x2ed5d4, %xmm5\n" /* 255.0f */
        "jmp .Lfd856_0000d88e\n"
        ".Lfd856_0000d9b6:\n"
        "movaps %xmm4, %xmm2\n"
        "mulss 0x2ed5d4, %xmm2\n" /* 255.0f */
        "jmp .Lfd856_0000d8b4\n"
    );
}

/* line 195 */
__attribute__((naked))
void StdConverterARGB_ArrayConvert4f4ubG3(const StdConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 195 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ebx\n" /* line 203 | pSrc, p */
        "subl $4, %ebx\n" /* p */
        "movl 0xc(%ebp), %esi\n" /* line 204 | pRawDst, pDst */
        /* { scope 2: RGBA */
        "movl 0x14(%ebp), %eax\n" /* line 205 | NumVertices */
        "testl %eax, %eax\n"
        "je .Lfd9c6_0000db44\n"
        "xorl %edi, %edi\n" /* i */
        "pxor %xmm5, %xmm5\n"
        "movss 0x2ed5d8, %xmm7\n" /* 0.5f */
        "fnstcw -0x1e(%ebp)\n"
        "movzwl -0x1e(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x20(%ebp)\n"
        "jmp .Lfd9c6_0000daf6\n"
        /* { scope 3 */
        ".Lfd9c6_0000da03:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* line 58 | 1.0f */
        "jbe .Lfd9c6_0000db4c\n"
        "movss 0x2ed5d4, %xmm6\n" /* 255.0f */
        ".Lfd9c6_0000da18:\n"
        "ucomiss %xmm1, %xmm5\n"
        "ja .Lfd9c6_0000db21\n"
        ".Lfd9c6_0000da21:\n"
        "ucomiss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "jbe .Lfd9c6_0000db7c\n"
        "movss 0x2ed5d4, %xmm4\n" /* 255.0f */
        ".Lfd9c6_0000da36:\n"
        "ucomiss %xmm2, %xmm5\n"
        "ja .Lfd9c6_0000db2d\n"
        ".Lfd9c6_0000da3f:\n"
        "ucomiss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "jbe .Lfd9c6_0000db6c\n"
        "movss 0x2ed5d4, %xmm0\n" /* 255.0f */
        ".Lfd9c6_0000da54:\n"
        "ucomiss %xmm3, %xmm5\n"
        "ja .Lfd9c6_0000db39\n"
        ".Lfd9c6_0000da5d:\n"
        "ucomiss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "jbe .Lfd9c6_0000db5c\n"
        "movss 0x2ed5d4, %xmm1\n" /* 255.0f */
        ".Lfd9c6_0000da72:\n"
        "addss %xmm7, %xmm0\n" /* line 227 */
        "movss %xmm0, -0x30(%ebp)\n"
        "flds -0x30(%ebp)\n"
        "fldcw -0x20(%ebp)\n"
        "fistpll -0x2c(%ebp)\n"
        "fldcw -0x1e(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0x18, %ecx\n"
        "addss %xmm7, %xmm4\n"
        "movss %xmm4, -0x30(%ebp)\n"
        "flds -0x30(%ebp)\n"
        "fldcw -0x20(%ebp)\n"
        "fistpll -0x2c(%ebp)\n"
        "fldcw -0x1e(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "shll $0x10, %eax\n"
        "addl %eax, %ecx\n"
        "addss %xmm7, %xmm6\n"
        "movss %xmm6, -0x30(%ebp)\n"
        "flds -0x30(%ebp)\n"
        "fldcw -0x20(%ebp)\n"
        "fistpll -0x2c(%ebp)\n"
        "fldcw -0x1e(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %ecx\n"
        "addss %xmm7, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "flds -0x30(%ebp)\n"
        "fldcw -0x20(%ebp)\n"
        "fistpll -0x2c(%ebp)\n"
        "fldcw -0x1e(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "leal (%ecx, %eax), %edx\n"
        "movl %edx, %eax\n" /* line 69 */
        "rorl $8, %eax\n"
        "movl %eax, (%esi)\n"
        "addl $4, %esi\n" /* line 230 | pDst */
        /* } scope */
        "addl $1, %edi\n" /* line 205 | i */
        "cmpl %edi, 0x14(%ebp)\n" /* i, NumVertices */
        "je .Lfd9c6_0000db41\n"
        /* { scope 3 */
        ".Lfd9c6_0000daf6:\n"
        "movss 4(%ebx), %xmm0\n" /* line 207 | p, r */
        "movss 8(%ebx), %xmm1\n" /* line 208 | p, g */
        "movss 0xc(%ebx), %xmm2\n" /* line 209 | p, b */
        "addl $0x10, %ebx\n" /* line 210 | p */
        "movss (%ebx), %xmm3\n" /* p, a */
        "ucomiss %xmm0, %xmm5\n" /* line 58 */
        "jbe .Lfd9c6_0000da03\n"
        "movaps %xmm5, %xmm6\n"
        "ucomiss %xmm1, %xmm5\n"
        "jbe .Lfd9c6_0000da21\n"
        ".Lfd9c6_0000db21:\n"
        "movaps %xmm5, %xmm4\n"
        "ucomiss %xmm2, %xmm5\n"
        "jbe .Lfd9c6_0000da3f\n"
        ".Lfd9c6_0000db2d:\n"
        "movaps %xmm5, %xmm0\n"
        "ucomiss %xmm3, %xmm5\n"
        "jbe .Lfd9c6_0000da5d\n"
        ".Lfd9c6_0000db39:\n"
        "movaps %xmm5, %xmm1\n"
        "jmp .Lfd9c6_0000da72\n"
        ".Lfd9c6_0000db41:\n"
        "movl %edx, -0x10(%ebp)\n" /* RGBA */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfd9c6_0000db44:\n"
        "addl $0x24, %esp\n" /* line 232 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: RGBA */
        /* { scope 3 */
        ".Lfd9c6_0000db4c:\n"
        "movaps %xmm0, %xmm6\n" /* line 58 */
        "mulss 0x2ed5d4, %xmm6\n" /* 255.0f */
        "jmp .Lfd9c6_0000da18\n"
        ".Lfd9c6_0000db5c:\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x2ed5d4, %xmm1\n" /* 255.0f */
        "jmp .Lfd9c6_0000da72\n"
        ".Lfd9c6_0000db6c:\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lfd9c6_0000da54\n"
        ".Lfd9c6_0000db7c:\n"
        "movaps %xmm1, %xmm4\n"
        "mulss 0x2ed5d4, %xmm4\n" /* 255.0f */
        "jmp .Lfd9c6_0000da36\n"
    );
}

/* line 456 */
__attribute__((naked))
void ATI4CompsConverterARGB_Convert4ub4f(const ATI4CompsConverterARGB * _this, const void * pDst, const float *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 456 */
        "movl %esp, %ebp\n"
        "subl $0x24, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* Src, pDst */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 466 | r */
        "movss 4(%eax), %xmm1\n" /* line 467 | g */
        "movss 8(%eax), %xmm3\n" /* line 468 | b */
        "movss 0xc(%eax), %xmm4\n" /* line 469 | a */
        "pxor %xmm2, %xmm2\n" /* line 58 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lfdb8c_0000dca6\n"
        "movaps %xmm2, %xmm6\n"
        ".Lfdb8c_0000dbb8:\n"
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lfdb8c_0000dc90\n"
        "movaps %xmm2, %xmm5\n"
        ".Lfdb8c_0000dbc4:\n"
        "ucomiss %xmm3, %xmm2\n"
        "jbe .Lfdb8c_0000dc7a\n"
        "movaps %xmm2, %xmm1\n"
        ".Lfdb8c_0000dbd0:\n"
        "ucomiss %xmm4, %xmm2\n"
        "ja .Lfdb8c_0000dbea\n"
        "ucomiss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "jbe .Lfdb8c_0000dcec\n"
        "movss 0x2ed5d4, %xmm2\n" /* 255.0f */
        ".Lfdb8c_0000dbea:\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 486 | 0.5f */
        "addss %xmm0, %xmm1\n"
        "fnstcw -0x12(%ebp)\n"
        "movzwl -0x12(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x14(%ebp)\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "flds -0x24(%ebp)\n"
        "fldcw -0x14(%ebp)\n"
        "fistpll -0x20(%ebp)\n"
        "fldcw -0x12(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0x18, %ecx\n"
        "addss %xmm0, %xmm5\n"
        "movss %xmm5, -0x24(%ebp)\n"
        "flds -0x24(%ebp)\n"
        "fldcw -0x14(%ebp)\n"
        "fistpll -0x20(%ebp)\n"
        "fldcw -0x12(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "shll $0x10, %eax\n"
        "addl %eax, %ecx\n"
        "addss %xmm0, %xmm6\n"
        "movss %xmm6, -0x24(%ebp)\n"
        "flds -0x24(%ebp)\n"
        "fldcw -0x14(%ebp)\n"
        "fistpll -0x20(%ebp)\n"
        "fldcw -0x12(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %ecx\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n"
        "flds -0x24(%ebp)\n"
        "fldcw -0x14(%ebp)\n"
        "fistpll -0x20(%ebp)\n"
        "fldcw -0x12(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "addl %eax, %ecx\n"
        "rorl $0x18, %ecx\n" /* line 438 */
        "movl 0xc(%ebp), %eax\n" /* pDst */
        "movl %ecx, (%eax)\n"
        /* } scope */
        "leave\n" /* line 488 */
        "retl\n"
        /* { scope 1 */
        ".Lfdb8c_0000dc7a:\n"
        "ucomiss 0x2ed5d0, %xmm3\n" /* line 58 | 1.0f */
        "jbe .Lfdb8c_0000dccc\n"
        "movss 0x2ed5d4, %xmm1\n" /* 255.0f */
        "jmp .Lfdb8c_0000dbd0\n"
        ".Lfdb8c_0000dc90:\n"
        "ucomiss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "jbe .Lfdb8c_0000dcdc\n"
        "movss 0x2ed5d4, %xmm5\n" /* 255.0f */
        "jmp .Lfdb8c_0000dbc4\n"
        ".Lfdb8c_0000dca6:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lfdb8c_0000dcbc\n"
        "movss 0x2ed5d4, %xmm6\n" /* 255.0f */
        "jmp .Lfdb8c_0000dbb8\n"
        ".Lfdb8c_0000dcbc:\n"
        "movaps %xmm0, %xmm6\n"
        "mulss 0x2ed5d4, %xmm6\n" /* 255.0f */
        "jmp .Lfdb8c_0000dbb8\n"
        ".Lfdb8c_0000dccc:\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x2ed5d4, %xmm1\n" /* 255.0f */
        "jmp .Lfdb8c_0000dbd0\n"
        ".Lfdb8c_0000dcdc:\n"
        "movaps %xmm1, %xmm5\n"
        "mulss 0x2ed5d4, %xmm5\n" /* 255.0f */
        "jmp .Lfdb8c_0000dbc4\n"
        ".Lfdb8c_0000dcec:\n"
        "movaps %xmm4, %xmm2\n"
        "mulss 0x2ed5d4, %xmm2\n" /* 255.0f */
        "jmp .Lfdb8c_0000dbea\n"
    );
}

/* line 556 */
__attribute__((naked))
void ATI4CompsConverterARGB_ArrayConvert4f4ubG3(const ATI4CompsConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 556 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ebx\n" /* line 565 | pSrc, p */
        "subl $4, %ebx\n" /* p */
        "movl 0xc(%ebp), %esi\n" /* line 566 | pRawDst, pDst */
        /* { scope 2: RGBA */
        "movl 0x14(%ebp), %edx\n" /* line 567 | NumVertices */
        "testl %edx, %edx\n"
        "je .Lfdcfc_0000de7a\n"
        "xorl %edi, %edi\n" /* i */
        "pxor %xmm5, %xmm5\n"
        "movss 0x2ed5d8, %xmm7\n" /* 0.5f */
        "fnstcw -0x1e(%ebp)\n"
        "movzwl -0x1e(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x20(%ebp)\n"
        "jmp .Lfdcfc_0000de2c\n"
        /* { scope 3 */
        ".Lfdcfc_0000dd39:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* line 58 | 1.0f */
        "jbe .Lfdcfc_0000de82\n"
        "movss 0x2ed5d4, %xmm6\n" /* 255.0f */
        ".Lfdcfc_0000dd4e:\n"
        "ucomiss %xmm1, %xmm5\n"
        "ja .Lfdcfc_0000de57\n"
        ".Lfdcfc_0000dd57:\n"
        "ucomiss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "jbe .Lfdcfc_0000deb2\n"
        "movss 0x2ed5d4, %xmm4\n" /* 255.0f */
        ".Lfdcfc_0000dd6c:\n"
        "ucomiss %xmm2, %xmm5\n"
        "ja .Lfdcfc_0000de63\n"
        ".Lfdcfc_0000dd75:\n"
        "ucomiss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "jbe .Lfdcfc_0000dea2\n"
        "movss 0x2ed5d4, %xmm0\n" /* 255.0f */
        ".Lfdcfc_0000dd8a:\n"
        "ucomiss %xmm3, %xmm5\n"
        "ja .Lfdcfc_0000de6f\n"
        ".Lfdcfc_0000dd93:\n"
        "ucomiss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "jbe .Lfdcfc_0000de92\n"
        "movss 0x2ed5d4, %xmm1\n" /* 255.0f */
        ".Lfdcfc_0000dda8:\n"
        "addss %xmm7, %xmm0\n" /* line 589 */
        "movss %xmm0, -0x30(%ebp)\n"
        "flds -0x30(%ebp)\n"
        "fldcw -0x20(%ebp)\n"
        "fistpll -0x2c(%ebp)\n"
        "fldcw -0x1e(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0x18, %ecx\n"
        "addss %xmm7, %xmm4\n"
        "movss %xmm4, -0x30(%ebp)\n"
        "flds -0x30(%ebp)\n"
        "fldcw -0x20(%ebp)\n"
        "fistpll -0x2c(%ebp)\n"
        "fldcw -0x1e(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "shll $0x10, %eax\n"
        "addl %eax, %ecx\n"
        "addss %xmm7, %xmm6\n"
        "movss %xmm6, -0x30(%ebp)\n"
        "flds -0x30(%ebp)\n"
        "fldcw -0x20(%ebp)\n"
        "fistpll -0x2c(%ebp)\n"
        "fldcw -0x1e(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %ecx\n"
        "addss %xmm7, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "flds -0x30(%ebp)\n"
        "fldcw -0x20(%ebp)\n"
        "fistpll -0x2c(%ebp)\n"
        "fldcw -0x1e(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "leal (%ecx, %eax), %edx\n"
        "movl %edx, %eax\n" /* line 438 */
        "rorl $0x18, %eax\n"
        "movl %eax, (%esi)\n"
        "addl $4, %esi\n" /* line 592 | pDst */
        /* } scope */
        "addl $1, %edi\n" /* line 567 | i */
        "cmpl %edi, 0x14(%ebp)\n" /* i, NumVertices */
        "je .Lfdcfc_0000de77\n"
        /* { scope 3 */
        ".Lfdcfc_0000de2c:\n"
        "movss 4(%ebx), %xmm0\n" /* line 569 | p, r */
        "movss 8(%ebx), %xmm1\n" /* line 570 | p, g */
        "movss 0xc(%ebx), %xmm2\n" /* line 571 | p, b */
        "addl $0x10, %ebx\n" /* line 572 | p */
        "movss (%ebx), %xmm3\n" /* p, a */
        "ucomiss %xmm0, %xmm5\n" /* line 58 */
        "jbe .Lfdcfc_0000dd39\n"
        "movaps %xmm5, %xmm6\n"
        "ucomiss %xmm1, %xmm5\n"
        "jbe .Lfdcfc_0000dd57\n"
        ".Lfdcfc_0000de57:\n"
        "movaps %xmm5, %xmm4\n"
        "ucomiss %xmm2, %xmm5\n"
        "jbe .Lfdcfc_0000dd75\n"
        ".Lfdcfc_0000de63:\n"
        "movaps %xmm5, %xmm0\n"
        "ucomiss %xmm3, %xmm5\n"
        "jbe .Lfdcfc_0000dd93\n"
        ".Lfdcfc_0000de6f:\n"
        "movaps %xmm5, %xmm1\n"
        "jmp .Lfdcfc_0000dda8\n"
        ".Lfdcfc_0000de77:\n"
        "movl %edx, -0x10(%ebp)\n" /* RGBA */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfdcfc_0000de7a:\n"
        "addl $0x24, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: RGBA */
        /* { scope 3 */
        ".Lfdcfc_0000de82:\n"
        "movaps %xmm0, %xmm6\n" /* line 58 */
        "mulss 0x2ed5d4, %xmm6\n" /* 255.0f */
        "jmp .Lfdcfc_0000dd4e\n"
        ".Lfdcfc_0000de92:\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x2ed5d4, %xmm1\n" /* 255.0f */
        "jmp .Lfdcfc_0000dda8\n"
        ".Lfdcfc_0000dea2:\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lfdcfc_0000dd8a\n"
        ".Lfdcfc_0000deb2:\n"
        "movaps %xmm1, %xmm4\n"
        "mulss 0x2ed5d4, %xmm4\n" /* 255.0f */
        "jmp .Lfdcfc_0000dd6c\n"
    );
}

/* line 769 */
__attribute__((naked))
void ATI4CompsConverterARGB_ArrayConvert4f4ub(const ATI4CompsConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 769 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, -0x1c(%ebp)\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* pRawDst */
        "movl 0x10(%ebp), %esi\n" /* pSrc */
        "movl 0x14(%ebp), %ebx\n" /* NumVertices */
        /* { scope 1 */
        "calll MacFeatures_IsAltiVecAvailable\n" /* line 775 */
        "testb %al, %al\n" /* line 784 */
        "je .Lfdec2_0000deeb\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 796 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfdec2_0000deeb:\n"
        "movl %ebx, 0x14(%ebp)\n" /* line 790 | NumVertices */
        "movl %esi, 0x10(%ebp)\n" /* pSrc */
        "movl %edi, 0xc(%ebp)\n" /* pRawDst */
        "movl -0x1c(%ebp), %eax\n" /* this */
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 796 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp ATI4CompsConverterARGB_ArrayConvert4f4ubG3\n" /* line 790 */
    );
}

/* line 395 */
__attribute__((naked))
void StdConverterARGB_ArrayConvert4f4ub(const StdConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 395 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, -0x1c(%ebp)\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* pRawDst */
        "movl 0x10(%ebp), %esi\n" /* pSrc */
        "movl 0x14(%ebp), %ebx\n" /* NumVertices */
        /* { scope 1 */
        "calll MacFeatures_IsAltiVecAvailable\n" /* line 401 */
        "testb %al, %al\n" /* line 410 */
        "je .Lfdf06_0000df2f\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 422 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfdf06_0000df2f:\n"
        "movl %ebx, 0x14(%ebp)\n" /* line 416 | NumVertices */
        "movl %esi, 0x10(%ebp)\n" /* pSrc */
        "movl %edi, 0xc(%ebp)\n" /* pRawDst */
        "movl -0x1c(%ebp), %eax\n" /* this */
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 422 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp StdConverterARGB_ArrayConvert4f4ubG3\n" /* line 416 */
    );
}

/* line 25 */
__attribute__((naked))
const CColorConverter * CColorConverter_GetColorConverter(Format SrcFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %ebx\n" /* SrcFormat */
        "calll MacDisplay_GetCardType\n" /* line 178 */
        "subl $1, %eax\n" /* line 30 */
        "je .Lfdf4a_0000df75\n"
        ".Lfdf4a_0000df5e:\n"
        "movl $sStdConverterARGB, %edx\n" /* line 46 */
        "testl %ebx, %ebx\n" /* SrcFormat */
        "movl $sStdConverterABGR, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl %edx, %eax\n" /* line 54 */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfdf4a_0000df75:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 32 */
        "cmpb $0, 0x800(%eax)\n"
        "je .Lfdf4a_0000df5e\n"
        "movl $sATI4CompsConverterARGB, %edx\n" /* line 34 */
        "testl %ebx, %ebx\n" /* SrcFormat */
        "movl $sATI4CompsConverterABGR, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl %edx, %eax\n" /* line 54 */
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 839 */
static __attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 839 */
        "movl %esp, %ebp\n"
        "cmpl $0xffff, %edx\n" /* line 19 */
        "je .Lfdf9a_0000dfa7\n"
        ".Lfdf9a_0000dfa5:\n"
        "popl %ebp\n" /* line 839 */
        "retl\n"
        ".Lfdf9a_0000dfa7:\n"
        "cmpl $1, %eax\n" /* line 19 */
        "je .Lfdf9a_0000dfce\n"
        "testl %eax, %eax\n" /* line 22 */
        "jne .Lfdf9a_0000dfa5\n"
        "movl imp___ZTV15CColorConverter, %eax\n" /* line 38 */
        "addl $8, %eax\n"
        "movl %eax, sATI4CompsConverterABGR\n"
        "movl %eax, sATI4CompsConverterARGB\n"
        "movl %eax, sStdConverterABGR\n"
        "movl %eax, sStdConverterARGB\n"
        "popl %ebp\n" /* line 839 */
        "retl\n"
        ".Lfdf9a_0000dfce:\n"
        "movl $vtbl_StdConverterARGB, sStdConverterARGB\n" /* line 81 */
        "movl $vtbl_StdConverterABGR, sStdConverterABGR\n" /* line 98 */
        "movl $vtbl_ATI4CompsConverterARGB, sATI4CompsConverterARGB\n" /* line 47 */
        "movl $vtbl_ATI4CompsConverterABGR, sATI4CompsConverterABGR\n" /* line 64 */
        "popl %ebp\n" /* line 839 */
        "retl\n"
    );
}

/* line 841 */
static __attribute__((naked))
void GLOBAL__D__ZN15CColorConverter17GetColorConverterENS_6FormatE(void) /* global destructors keyed to CColorConverter_GetColorConverter */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 841 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 840 */
static __attribute__((naked))
void GLOBAL__I__ZN15CColorConverter17GetColorConverterENS_6FormatE(void) /* global constructors keyed to CColorConverter_GetColorConverter */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 840 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 32 */
__attribute__((naked))
void CColorConverter_Convert4ub4f(const CColorConverter * _this, const void * Dest, const float *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 32 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 33 */
__attribute__((naked))
void CColorConverter_Convert4f4ubInverse(const CColorConverter * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 33 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 34 */
__attribute__((naked))
void CColorConverter_Convert3f4ubInverse(const CColorConverter * _this, float *Dest, const UINT8 *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 34 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 35 */
__attribute__((naked))
void CColorConverter_ArrayConvert4f4ub(const CColorConverter * _this, const void * pDst, const float * pSrc, UINT32 NumVertices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 36 */
__attribute__((naked))
ConverterType CColorConverter_GetType(const CColorConverter * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 36 */
        "movl %esp, %ebp\n"
        "movl $4, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 38 */
__attribute__((naked))
void ZN15CColorConverterD1Ev(void) /* CColorConverter_~CColorConverter */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "movl imp___ZTV15CColorConverter, %edx\n"
        "addl $8, %edx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, (%eax)\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 38 */
__attribute__((naked))
void ZN15CColorConverterD0Ev(void) /* CColorConverter_~CColorConverter */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl imp___ZTV15CColorConverter, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl %edx, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 55 */
__attribute__((naked))
ConverterType ATI4CompsConverterARGB_GetType(const ATI4CompsConverterARGB * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 72 */
__attribute__((naked))
ConverterType ATI4CompsConverterABGR_GetType(const ATI4CompsConverterABGR * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 72 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 89 */
__attribute__((naked))
ConverterType StdConverterARGB_GetType(const StdConverterARGB * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "movl $2, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
ConverterType StdConverterABGR_GetType(const StdConverterABGR * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "movl $3, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 82 */
__attribute__((naked))
void ZN16StdConverterARGBD1Ev(void) /* StdConverterARGB_~StdConverterARGB */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 82 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl $vtbl_StdConverterARGB, (%edx)\n"
        "movl imp___ZTV15CColorConverter, %eax\n" /* line 38 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 82 */
        "retl\n"
    );
}

/* line 82 */
__attribute__((naked))
void ZN16StdConverterARGBD0Ev(void) /* StdConverterARGB_~StdConverterARGB */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 82 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_StdConverterARGB, (%eax)\n"
        "movl imp___ZTV15CColorConverter, %edx\n" /* line 38 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 82 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 99 */
__attribute__((naked))
void ZN16StdConverterABGRD1Ev(void) /* StdConverterABGR_~StdConverterABGR */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl $vtbl_StdConverterABGR, (%edx)\n"
        "movl imp___ZTV15CColorConverter, %eax\n" /* line 38 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 99 */
        "retl\n"
    );
}

/* line 99 */
__attribute__((naked))
void ZN16StdConverterABGRD0Ev(void) /* StdConverterABGR_~StdConverterABGR */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_StdConverterABGR, (%eax)\n"
        "movl imp___ZTV15CColorConverter, %edx\n" /* line 38 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 99 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 48 */
__attribute__((naked))
void ZN22ATI4CompsConverterARGBD1Ev(void) /* ATI4CompsConverterARGB_~ATI4CompsConverterARGB */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl $vtbl_ATI4CompsConverterARGB, (%edx)\n"
        "movl imp___ZTV15CColorConverter, %eax\n" /* line 38 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 48 */
        "retl\n"
    );
}

/* line 48 */
__attribute__((naked))
void ZN22ATI4CompsConverterARGBD0Ev(void) /* ATI4CompsConverterARGB_~ATI4CompsConverterARGB */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_ATI4CompsConverterARGB, (%eax)\n"
        "movl imp___ZTV15CColorConverter, %edx\n" /* line 38 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 48 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 65 */
__attribute__((naked))
void ZN22ATI4CompsConverterABGRD1Ev(void) /* ATI4CompsConverterABGR_~ATI4CompsConverterABGR */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 65 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl $vtbl_ATI4CompsConverterABGR, (%edx)\n"
        "movl imp___ZTV15CColorConverter, %eax\n" /* line 38 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 65 */
        "retl\n"
    );
}

/* line 65 */
__attribute__((naked))
void ZN22ATI4CompsConverterABGRD0Ev(void) /* ATI4CompsConverterABGR_~ATI4CompsConverterABGR */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 65 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_ATI4CompsConverterABGR, (%eax)\n"
        "movl imp___ZTV15CColorConverter, %edx\n" /* line 38 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 65 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}


/* Register global constructor in .init_array */
__asm__(".section .init_array,\"aw\",@init_array\n.long GLOBAL__I__ZN15CColorConverter17GetColorConverterENS_6FormatE\n.section .text\n");
