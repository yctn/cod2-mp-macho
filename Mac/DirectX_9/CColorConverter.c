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
extern void *vtbl_StdConverterARGB[];
extern void *vtbl_StdConverterABGR[];
extern void *vtbl_ATI4CompsConverterARGB[];
extern void *vtbl_ATI4CompsConverterABGR[];
extern void *imp___ZN7COpenGL7sOpenGLE;
extern void *imp___ZTV15CColorConverter;

extern int MacDisplay_GetCardType(void);
extern Boolean MacFeatures_IsAltiVecAvailable(void);
void __ZdlPv(void *ptr);

static UINT32 CColorConverter_RotateRight32(UINT32 value, unsigned int shift)
{
    return (value >> shift) | (value << (32 - shift));
}

static float CColorConverter_ByteToFloat(UINT8 value)
{
    return (float)value * (1.0f / 255.0f);
}

static void CColorConverter_SetVTable(void *object, void **vtable)
{
    *(void ***)object = vtable;
}

static void **CColorConverter_GetBaseVTable(void)
{
    return (void **)((char *)imp___ZTV15CColorConverter + 8);
}

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
static void __static_initialization_and_destruction_0(int __initialize_p, int __priority);
static void GLOBAL__D__ZN15CColorConverter17GetColorConverterENS_6FormatE(void); /* global destructors keyed to CColorConverter_GetColorConverter */
static void GLOBAL__I__ZN15CColorConverter17GetColorConverterENS_6FormatE(void); /* global constructors keyed to CColorConverter_GetColorConverter */
void CColorConverter_Convert4ub4f(const CColorConverter * _this, const void * Dest, const float *Src);
void CColorConverter_Convert4f4ubInverse(const CColorConverter * _this, float *Dest, const UINT8 *Src);
void CColorConverter_Convert3f4ubInverse(const CColorConverter * _this, float *Dest, const UINT8 *Src);
void CColorConverter_ArrayConvert4f4ub(const CColorConverter * _this, const void * pDst, const float * pSrc, UINT32 NumVertices);
ConverterType CColorConverter_GetType(const CColorConverter * _this);
void ZN15CColorConverterD1Ev(CColorConverter * _this); /* CColorConverter_~CColorConverter */
void ZN15CColorConverterD0Ev(CColorConverter * _this); /* CColorConverter_~CColorConverter */
ConverterType ATI4CompsConverterARGB_GetType(const ATI4CompsConverterARGB * _this);
ConverterType ATI4CompsConverterABGR_GetType(const ATI4CompsConverterABGR * _this);
ConverterType StdConverterARGB_GetType(const StdConverterARGB * _this);
ConverterType StdConverterABGR_GetType(const StdConverterABGR * _this);
void ZN16StdConverterARGBD1Ev(StdConverterARGB * _this); /* StdConverterARGB_~StdConverterARGB */
void ZN16StdConverterARGBD0Ev(StdConverterARGB * _this); /* StdConverterARGB_~StdConverterARGB */
void ZN16StdConverterABGRD1Ev(StdConverterABGR * _this); /* StdConverterABGR_~StdConverterABGR */
void ZN16StdConverterABGRD0Ev(StdConverterABGR * _this); /* StdConverterABGR_~StdConverterABGR */
void ZN22ATI4CompsConverterARGBD1Ev(ATI4CompsConverterARGB * _this); /* ATI4CompsConverterARGB_~ATI4CompsConverterARGB */
void ZN22ATI4CompsConverterARGBD0Ev(ATI4CompsConverterARGB * _this); /* ATI4CompsConverterARGB_~ATI4CompsConverterARGB */
void ZN22ATI4CompsConverterABGRD1Ev(ATI4CompsConverterABGR * _this); /* ATI4CompsConverterABGR_~ATI4CompsConverterABGR */
void ZN22ATI4CompsConverterABGRD0Ev(ATI4CompsConverterABGR * _this); /* ATI4CompsConverterABGR_~ATI4CompsConverterABGR */

/* line 59 */
void StdConverterARGB_Convert(const StdConverterARGB * _this, const void * pDst, const void * pSrc)
{
    UINT32 value;

    (void)_this;

    memcpy(&value, pSrc, sizeof(value));
    value = CColorConverter_RotateRight32(value, 8);
    memcpy((void *)pDst, &value, sizeof(value));
}

/* line 131 */
void StdConverterABGR_Convert4ub4f(const StdConverterABGR * _this, const void * pDst, const float *Src)
{
    (void)_this;
    (void)pDst;
    (void)Src;
}

/* line 139 */
void StdConverterARGB_Convert4f4ubInverse(const StdConverterARGB * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;

    Dest[0] = CColorConverter_ByteToFloat(Src[0]);
    Dest[1] = CColorConverter_ByteToFloat(Src[1]);
    Dest[2] = CColorConverter_ByteToFloat(Src[2]);
    Dest[3] = CColorConverter_ByteToFloat(Src[3]);
}

/* line 160 */
void StdConverterABGR_Convert4f4ubInverse(const StdConverterABGR * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;
    (void)Dest;
    (void)Src;
}

/* line 168 */
void StdConverterARGB_Convert3f4ubInverse(const StdConverterARGB * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;

    Dest[0] = CColorConverter_ByteToFloat(Src[0]);
    Dest[1] = CColorConverter_ByteToFloat(Src[1]);
    Dest[2] = CColorConverter_ByteToFloat(Src[2]);
}

/* line 187 */
void StdConverterABGR_Convert3f4ubInverse(const StdConverterABGR * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;
    (void)Dest;
    (void)Src;
}

/* line 425 */
void StdConverterABGR_ArrayConvert4f4ub(const StdConverterABGR * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    (void)_this;
    (void)pRawDst;
    (void)pSrc;
    (void)NumVertices;
}

/* line 433 */
void ATI4CompsConverterARGB_Convert(const ATI4CompsConverterARGB * _this, const void * pDst, const void * pSrc)
{
    UINT32 value;

    (void)_this;

    memcpy(&value, pSrc, sizeof(value));
    value = CColorConverter_RotateRight32(value, 24);
    memcpy((void *)pDst, &value, sizeof(value));
}

/* line 445 */
void ATI4CompsConverterABGR_Convert(const ATI4CompsConverterABGR * _this, const void * pDst, const void * pSrc)
{
    (void)_this;

    memcpy((void *)pDst, pSrc, sizeof(UINT32));
}

/* line 491 */
void ATI4CompsConverterABGR_Convert4ub4f(const ATI4CompsConverterABGR * _this, const void * pDst, const float *Src)
{
    (void)_this;
    (void)pDst;
    (void)Src;
}

/* line 499 */
void ATI4CompsConverterARGB_Convert4f4ubInverse(const ATI4CompsConverterARGB * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;

    Dest[0] = CColorConverter_ByteToFloat(Src[3]);
    Dest[1] = CColorConverter_ByteToFloat(Src[2]);
    Dest[2] = CColorConverter_ByteToFloat(Src[1]);
    Dest[3] = CColorConverter_ByteToFloat(Src[0]);
}

/* line 521 */
void ATI4CompsConverterABGR_Convert4f4ubInverse(const ATI4CompsConverterABGR * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;
    (void)Dest;
    (void)Src;
}

/* line 528 */
void ATI4CompsConverterARGB_Convert3f4ubInverse(const ATI4CompsConverterARGB * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;

    Dest[0] = CColorConverter_ByteToFloat(Src[3]);
    Dest[1] = CColorConverter_ByteToFloat(Src[2]);
    Dest[2] = CColorConverter_ByteToFloat(Src[1]);
}

/* line 548 */
void ATI4CompsConverterABGR_Convert3f4ubInverse(const ATI4CompsConverterABGR * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;
    (void)Dest;
    (void)Src;
}

/* line 799 */
void ATI4CompsConverterABGR_ArrayConvert4f4ub(const ATI4CompsConverterABGR * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    (void)_this;
    (void)pRawDst;
    (void)pSrc;
    (void)NumVertices;
}

/* line 76 */
void StdConverterABGR_Convert(const StdConverterABGR * _this, const void * pDst, const void * pSrc)
{
    (void)_this;

    memcpy((void *)pDst, pSrc, sizeof(UINT32));
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
void ATI4CompsConverterARGB_ArrayConvert4f4ub(const ATI4CompsConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    if (!MacFeatures_IsAltiVecAvailable()) {
        ATI4CompsConverterARGB_ArrayConvert4f4ubG3(_this, pRawDst, pSrc, NumVertices);
    }
}

/* line 395 */
void StdConverterARGB_ArrayConvert4f4ub(const StdConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    if (!MacFeatures_IsAltiVecAvailable()) {
        StdConverterARGB_ArrayConvert4f4ubG3(_this, pRawDst, pSrc, NumVertices);
    }
}

/* line 25 */
const CColorConverter * CColorConverter_GetColorConverter(Format SrcFormat)
{
    const unsigned char *openGlState;

    openGlState = (const unsigned char *)imp___ZN7COpenGL7sOpenGLE;
    if (MacDisplay_GetCardType() == 2 && openGlState[0x800] != 0) {
        return (const CColorConverter *)(SrcFormat ? sATI4CompsConverterABGR : sATI4CompsConverterARGB);
    }

    return (const CColorConverter *)(SrcFormat ? sStdConverterABGR : sStdConverterARGB);
}

/* line 839 */
static void __static_initialization_and_destruction_0(int __initialize_p, int __priority)
{
    if (__priority != 0xffff) {
        return;
    }

    if (__initialize_p == 0) {
        void **baseVTable;

        baseVTable = CColorConverter_GetBaseVTable();
        CColorConverter_SetVTable(sATI4CompsConverterABGR, baseVTable);
        CColorConverter_SetVTable(sATI4CompsConverterARGB, baseVTable);
        CColorConverter_SetVTable(sStdConverterABGR, baseVTable);
        CColorConverter_SetVTable(sStdConverterARGB, baseVTable);
        return;
    }

    if (__initialize_p == 1) {
        CColorConverter_SetVTable(sStdConverterARGB, vtbl_StdConverterARGB);
        CColorConverter_SetVTable(sStdConverterABGR, vtbl_StdConverterABGR);
        CColorConverter_SetVTable(sATI4CompsConverterARGB, vtbl_ATI4CompsConverterARGB);
        CColorConverter_SetVTable(sATI4CompsConverterABGR, vtbl_ATI4CompsConverterABGR);
    }
}

/* line 841 */
static void GLOBAL__D__ZN15CColorConverter17GetColorConverterENS_6FormatE(void) /* global destructors keyed to CColorConverter_GetColorConverter */
{
    __static_initialization_and_destruction_0(0, 0xffff);
}

/* line 840 */
static void GLOBAL__I__ZN15CColorConverter17GetColorConverterENS_6FormatE(void) /* global constructors keyed to CColorConverter_GetColorConverter */
{
    __static_initialization_and_destruction_0(1, 0xffff);
}

/* line 32 */
void CColorConverter_Convert4ub4f(const CColorConverter * _this, const void * Dest, const float *Src)
{
    (void)_this;
    (void)Dest;
    (void)Src;
}

/* line 33 */
void CColorConverter_Convert4f4ubInverse(const CColorConverter * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;
    (void)Dest;
    (void)Src;
}

/* line 34 */
void CColorConverter_Convert3f4ubInverse(const CColorConverter * _this, float *Dest, const UINT8 *Src)
{
    (void)_this;
    (void)Dest;
    (void)Src;
}

/* line 35 */
void CColorConverter_ArrayConvert4f4ub(const CColorConverter * _this, const void * pDst, const float * pSrc, UINT32 NumVertices)
{
    (void)_this;
    (void)pDst;
    (void)pSrc;
    (void)NumVertices;
}

/* line 36 */
ConverterType CColorConverter_GetType(const CColorConverter * _this)
{
    (void)_this;
    return UNKNOWN_CONVERTER;
}

/* line 38 */
void ZN15CColorConverterD1Ev(CColorConverter * _this) /* CColorConverter_~CColorConverter */
{
    CColorConverter_SetVTable(_this, CColorConverter_GetBaseVTable());
}

/* line 38 */
void ZN15CColorConverterD0Ev(CColorConverter * _this) /* CColorConverter_~CColorConverter */
{
    ZN15CColorConverterD1Ev(_this);
    __ZdlPv(_this);
}

/* line 55 */
ConverterType ATI4CompsConverterARGB_GetType(const ATI4CompsConverterARGB * _this)
{
    (void)_this;
    return ATI_4_COMPS_CONVERTER_ARGB;
}

/* line 72 */
ConverterType ATI4CompsConverterABGR_GetType(const ATI4CompsConverterABGR * _this)
{
    (void)_this;
    return ATI_4_COMPS_CONVERTER_ABGR;
}

/* line 89 */
ConverterType StdConverterARGB_GetType(const StdConverterARGB * _this)
{
    (void)_this;
    return STD_CONVERTER_ARGB;
}

/* line 106 */
ConverterType StdConverterABGR_GetType(const StdConverterABGR * _this)
{
    (void)_this;
    return STD_CONVERTER_ABGR;
}

/* line 82 */
void ZN16StdConverterARGBD1Ev(StdConverterARGB * _this) /* StdConverterARGB_~StdConverterARGB */
{
    CColorConverter_SetVTable(_this, vtbl_StdConverterARGB);
    CColorConverter_SetVTable(_this, CColorConverter_GetBaseVTable());
}

/* line 82 */
void ZN16StdConverterARGBD0Ev(StdConverterARGB * _this) /* StdConverterARGB_~StdConverterARGB */
{
    ZN16StdConverterARGBD1Ev(_this);
    __ZdlPv(_this);
}

/* line 99 */
void ZN16StdConverterABGRD1Ev(StdConverterABGR * _this) /* StdConverterABGR_~StdConverterABGR */
{
    CColorConverter_SetVTable(_this, vtbl_StdConverterABGR);
    CColorConverter_SetVTable(_this, CColorConverter_GetBaseVTable());
}

/* line 99 */
void ZN16StdConverterABGRD0Ev(StdConverterABGR * _this) /* StdConverterABGR_~StdConverterABGR */
{
    ZN16StdConverterABGRD1Ev(_this);
    __ZdlPv(_this);
}

/* line 48 */
void ZN22ATI4CompsConverterARGBD1Ev(ATI4CompsConverterARGB * _this) /* ATI4CompsConverterARGB_~ATI4CompsConverterARGB */
{
    CColorConverter_SetVTable(_this, vtbl_ATI4CompsConverterARGB);
    CColorConverter_SetVTable(_this, CColorConverter_GetBaseVTable());
}

/* line 48 */
void ZN22ATI4CompsConverterARGBD0Ev(ATI4CompsConverterARGB * _this) /* ATI4CompsConverterARGB_~ATI4CompsConverterARGB */
{
    ZN22ATI4CompsConverterARGBD1Ev(_this);
    __ZdlPv(_this);
}

/* line 65 */
void ZN22ATI4CompsConverterABGRD1Ev(ATI4CompsConverterABGR * _this) /* ATI4CompsConverterABGR_~ATI4CompsConverterABGR */
{
    CColorConverter_SetVTable(_this, vtbl_ATI4CompsConverterABGR);
    CColorConverter_SetVTable(_this, CColorConverter_GetBaseVTable());
}

/* line 65 */
void ZN22ATI4CompsConverterABGRD0Ev(ATI4CompsConverterABGR * _this) /* ATI4CompsConverterABGR_~ATI4CompsConverterABGR */
{
    ZN22ATI4CompsConverterABGRD1Ev(_this);
    __ZdlPv(_this);
}


/* Register global constructor in .init_array */
__asm__(".section .init_array,\"aw\",@init_array\n.long GLOBAL__I__ZN15CColorConverter17GetColorConverterENS_6FormatE\n.section .text\n");
