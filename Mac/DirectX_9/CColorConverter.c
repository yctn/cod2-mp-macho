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

static UINT32 CColorConverter_FloatToByte(float value)
{
    float scaled;

    if (0.0f > value) {
        scaled = 0.0f;
    } else if (1.0f < value) {
        scaled = 255.0f;
    } else {
        scaled = value * 255.0f;
    }

    return (UINT32)(scaled + 0.5f);
}

static UINT32 CColorConverter_PackStdARGB(float r, float g, float b, float a)
{
    UINT32 packed;

    packed = (CColorConverter_FloatToByte(b) << 24)
           | (CColorConverter_FloatToByte(g) << 16)
           | (CColorConverter_FloatToByte(r) << 8)
           | CColorConverter_FloatToByte(a);
    return CColorConverter_RotateRight32(packed, 8);
}

static UINT32 CColorConverter_PackATI4CompsARGB(float r, float g, float b, float a)
{
    UINT32 packed;

    packed = (CColorConverter_FloatToByte(b) << 24)
           | (CColorConverter_FloatToByte(g) << 16)
           | (CColorConverter_FloatToByte(r) << 8)
           | CColorConverter_FloatToByte(a);
    return CColorConverter_RotateRight32(packed, 24);
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
void StdConverterARGB_Convert4ub4f(const StdConverterARGB * _this, const void * pDst, const float *Src)
{
    UINT32 packed;

    (void)_this;

    packed = CColorConverter_PackStdARGB(Src[0], Src[1], Src[2], Src[3]);
    memcpy((void *)pDst, &packed, sizeof(packed));
}

/* line 195 */
void StdConverterARGB_ArrayConvert4f4ubG3(const StdConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    UINT32 *pDst;
    UINT32 i;

    (void)_this;

    pDst = (UINT32 *)pRawDst;
    for (i = 0; i < NumVertices; ++i) {
        *pDst++ = CColorConverter_PackStdARGB(pSrc[0], pSrc[1], pSrc[2], pSrc[3]);
        pSrc += 4;
    }
}

/* line 456 */
void ATI4CompsConverterARGB_Convert4ub4f(const ATI4CompsConverterARGB * _this, const void * pDst, const float *Src)
{
    UINT32 packed;

    (void)_this;

    packed = CColorConverter_PackATI4CompsARGB(Src[0], Src[1], Src[2], Src[3]);
    memcpy((void *)pDst, &packed, sizeof(packed));
}

/* line 556 */
void ATI4CompsConverterARGB_ArrayConvert4f4ubG3(const ATI4CompsConverterARGB * _this, const void * pRawDst, const float * pSrc, UINT32 NumVertices)
{
    UINT32 *pDst;
    UINT32 i;

    (void)_this;

    pDst = (UINT32 *)pRawDst;
    for (i = 0; i < NumVertices; ++i) {
        *pDst++ = CColorConverter_PackATI4CompsARGB(pSrc[0], pSrc[1], pSrc[2], pSrc[3]);
        pSrc += 4;
    }
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
