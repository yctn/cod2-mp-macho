/* ASM dump from: MacAppleEvents.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacAppleEvents.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacExceptions.h"
 */

void ZN8CAEEventD1Ev(void); /* CAEEvent_~CAEEvent */
void ZN9CAETargetD1Ev(void); /* CAETarget_~CAETarget */
double CAETarget_CAETarget(const CAETarget * _this, const ProcessSerialNumber *inPSN);
double CAEDesc_GetData(const CAEDesc * _this, DescType inTypeCode, double *outDataPtr, Size inDataSize);
double CAEDesc_PutData(const CAEDesc * _this, DescType inTypeCode, const double *inDataPtr, Size inDataSize);
double CAEObject_CAEObject(const CAEObject * _this, DescType inDesiredClass, const AEDesc *inContainer, DescType inKeyForm, const AEDesc *inKeyData);
double CAERecord_PutParam(const CAERecord * _this, AEKeyword inKeyword, const AEDesc *inParam);
double CAEEvent_Create(const CAEEvent * _this, CAETarget *inTarget, AEEventClass inEventClass, AEEventID inEventID);
double CAEEvent_CAEEvent(const CAEEvent * _this);
double CAEEvent_Send(const CAEEvent * _this);
double CAETarget_SetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, const AEDesc *inData, const CAERecord * _this_4, AEKeyword inKeyword, SInt32 *outParam, const CAERecord * _this_7, AEKeyword inKeyword_8, StringPtr outParam_9);
double CAETarget_CountElements(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inElementClass, SInt32 *outCount);
double CAETarget_GetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, DescType inRequestedType, AEDesc *outData);

/* line 505 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZN8CAEEventD1Ev(void) /* CAEEvent_~CAEEvent */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 505 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 4(%ebx), %edx\n" /* line 187 */
        "testl %edx, %edx\n"
        "je .Lf28f2_0000290b\n"
        "movl %ebx, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf28f2_0000290b:\n"
        "movl $0x6e756c6c, (%ebx)\n" /* line 192 */
        "movl $0, 4(%ebx)\n" /* line 193 */
        "addl $0x14, %esp\n" /* line 507 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void ZN8CAEEventD1Ev(void) /* CAEEvent_~CAEEvent */
{ }
#endif

/* line 565 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZN9CAETargetD1Ev(void) /* CAETarget_~CAETarget */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 565 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 4(%ebx), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf291e_00002937\n"
        "movl %ebx, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf291e_00002937:\n"
        "movl $0x6e756c6c, (%ebx)\n" /* line 192 */
        "movl $0, 4(%ebx)\n" /* line 193 */
        "addl $0x14, %esp\n" /* line 567 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void ZN9CAETargetD1Ev(void) /* CAETarget_~CAETarget */
{ }
#endif

/* line 557 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAETarget_CAETarget(const CAETarget * _this, const ProcessSerialNumber *inPSN)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 557 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x6e756c6c, (%ebx)\n" /* line 159 */
        "movl $0, 4(%ebx)\n" /* line 160 */
        "movl %ebx, 0xc(%esp)\n" /* line 559 | this */
        "movl $8, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inPSN */
        "movl %eax, 4(%esp)\n"
        "movl $0x70736e20, (%esp)\n"
        "calll AECreateDesc\n"
        "movswl %ax, %esi\n" /* inError */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf294a_00002990\n"
        "addl $0x10, %esp\n" /* line 561 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf294a_00002990:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %esi, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl 4(%ebx), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf294a_000029c9\n"
        "movl %ebx, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf294a_000029c9:\n"
        "movl $0x6e756c6c, (%ebx)\n" /* line 192 */
        "movl $0, 4(%ebx)\n" /* line 193 */
        "movl %esi, (%esp)\n" /* line 180 | inError */
        "calll __Unwind_Resume\n"
    );
}
#else
double CAETarget_CAETarget(const CAETarget * _this, const ProcessSerialNumber *inPSN)
{ return 0; }
#endif

/* line 210 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAEDesc_GetData(const CAEDesc * _this, DescType inTypeCode, double *outDataPtr, Size inDataSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* inTypeCode */
        "cmpl %edx, (%eax)\n" /* line 212 */
        "je .Lf29e0_00002a4f\n"
        /* { scope 1 */
        "movl $0x6e756c6c, -0x10(%ebp)\n" /* line 159 | coercedDesc */
        "movl $0, -0xc(%ebp)\n" /* line 160 */
        "leal -0x10(%ebp), %esi\n" /* line 220 | coercedDesc */
        "movl %esi, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AECoerceDesc\n"
        "movswl %ax, %ebx\n" /* error */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf29e0_00002a95\n"
        "movl 0x14(%ebp), %eax\n" /* line 223 | inDataSize */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* outDataPtr */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll AEGetDescData\n"
        "movswl %ax, %ebx\n" /* error */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf29e0_00002a95\n"
        "movl -0xc(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf29e0_00002a48\n"
        "movl %esi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        /* } scope */
        ".Lf29e0_00002a48:\n"
        "addl $0x20, %esp\n" /* line 226 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf29e0_00002a4f:\n"
        "movl 0x14(%ebp), %edx\n" /* line 214 | inDataSize */
        "movl %edx, 8(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* outDataPtr */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll AEGetDescData\n"
        "movswl %ax, %ebx\n" /* error */
        "testw %ax, %ax\n" /* line 30 */
        "je .Lf29e0_00002a48\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        /* } scope */
        /* { scope 1 */
        ".Lf29e0_00002a95:\n"
        "movl $4, (%esp)\n"
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        "movl %eax, %ebx\n"
        "movl -0xc(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf29e0_00002ace\n"
        "movl %esi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf29e0_00002ace:\n"
        "movl %ebx, (%esp)\n" /* line 180 */
        "calll __Unwind_Resume\n"
    );
}
#else
double CAEDesc_GetData(const CAEDesc * _this, DescType inTypeCode, double *outDataPtr, Size inDataSize)
{ return 0; }
#endif

/* overload skip: CAEDesc_GetData (0x2ad6) */

/* line 299 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAEDesc_PutData(const CAEDesc * _this, DescType inTypeCode, const double *inDataPtr, Size inDataSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 299 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf2be8_00002c01\n"
        "movl %ebx, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf2be8_00002c01:\n"
        "movl $0x6e756c6c, (%ebx)\n" /* line 192 */
        "movl $0, 4(%ebx)\n" /* line 193 */
        "movl %ebx, 0xc(%esp)\n" /* line 303 | error */
        "movl 0x14(%ebp), %eax\n" /* inDataSize */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* inDataPtr */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inTypeCode */
        "movl %eax, (%esp)\n"
        "calll AECreateDesc\n"
        "movswl %ax, %ebx\n" /* error */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf2be8_00002c39\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 305 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2be8_00002c39:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
    );
}
#else
double CAEDesc_PutData(const CAEDesc * _this, DescType inTypeCode, const double *inDataPtr, Size inDataSize)
{ return 0; }
#endif

/* line 349 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAEObject_CAEObject(const CAEObject * _this, DescType inDesiredClass, const AEDesc *inContainer, DescType inKeyForm, const AEDesc *inKeyData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 349 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x6e756c6c, (%ebx)\n" /* line 159 */
        "movl $0, 4(%ebx)\n" /* line 160 */
        "movl %ebx, 0x14(%esp)\n" /* line 351 | this */
        "movl $0, 0x10(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* inKeyData */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* inKeyForm */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* inContainer */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inDesiredClass */
        "movl %eax, (%esp)\n"
        "calll CreateObjSpecifier\n"
        "movswl %ax, %esi\n" /* inError */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf2c62_00002cb5\n"
        "addl $0x20, %esp\n" /* line 353 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c62_00002cb5:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %esi, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl 4(%ebx), %edx\n" /* line 187 */
        "testl %edx, %edx\n"
        "je .Lf2c62_00002cee\n"
        "movl %ebx, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf2c62_00002cee:\n"
        "movl $0x6e756c6c, (%ebx)\n" /* line 192 */
        "movl $0, 4(%ebx)\n" /* line 193 */
        "movl %esi, (%esp)\n" /* line 180 | inError */
        "calll __Unwind_Resume\n"
    );
}
#else
double CAEObject_CAEObject(const CAEObject * _this, DescType inDesiredClass, const AEDesc *inContainer, DescType inKeyForm, const AEDesc *inKeyData)
{ return 0; }
#endif

/* overload skip: CAEObject_CAEObject (0x2d04) */

/* line 471 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAERecord_PutParam(const CAERecord * _this, AEKeyword inKeyword, const AEDesc *inParam)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 471 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 473 | inParam */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inKeyword */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AEPutParamDesc\n"
        "movswl %ax, %ebx\n" /* error */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf2da6_00002dd4\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 475 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2da6_00002dd4:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
    );
}
#else
double CAERecord_PutParam(const CAERecord * _this, AEKeyword inKeyword, const AEDesc *inParam)
{ return 0; }
#endif

/* line 515 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAEEvent_Create(const CAEEvent * _this, CAETarget *inTarget, AEEventClass inEventClass, AEEventID inEventID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 515 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf2dfc_00002e15\n"
        "movl %ebx, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf2dfc_00002e15:\n"
        "movl $0x6e756c6c, (%ebx)\n" /* line 192 */
        "movl $0, 4(%ebx)\n" /* line 193 */
        "movl %ebx, 0x14(%esp)\n" /* line 519 | error */
        "movl $0, 0x10(%esp)\n"
        "movl $0xffffffff, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inTarget */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* inEventID */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* inEventClass */
        "movl %eax, (%esp)\n"
        "calll AECreateAppleEvent\n"
        "movswl %ax, %ebx\n" /* error */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf2dfc_00002e5d\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 521 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2dfc_00002e5d:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
    );
}
#else
double CAEEvent_Create(const CAEEvent * _this, CAETarget *inTarget, AEEventClass inEventClass, AEEventID inEventID)
{ return 0; }
#endif

/* overload skip: CAETarget_CAETarget (0x2e86) */

/* overload skip: CAETarget_CAETarget (0x2f1a) */

/* overload skip: CAETarget_CAETarget (0x2fae) */

/* line 491 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAEEvent_CAEEvent(const CAEEvent * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 491 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x6e756c6c, (%eax)\n" /* line 159 */
        "movl $0, 4(%eax)\n" /* line 160 */
        "popl %ebp\n" /* line 493 */
        "retl\n"
    );
}
#else
double CAEEvent_CAEEvent(const CAEEvent * _this)
{ return 0; }
#endif

/* line 526 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAEEvent_Send(const CAEEvent * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 526 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        /* { scope 1 */
        "leal -0x10(%ebp), %esi\n" /* line 528 | reply */
        "movl %esi, (%esp)\n"
        "calll CAEEvent_CAEEvent\n"
        "movl $0, 0x18(%esp)\n" /* line 529 */
        "movl $0, 0x14(%esp)\n"
        "movl $0xffffffff, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x11, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll AESend\n"
        "movswl %ax, %ebx\n" /* error */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf305a_000030c2\n"
        "movl -0xc(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf305a_000030bb\n"
        "movl %esi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        /* } scope */
        ".Lf305a_000030bb:\n"
        "addl $0x30, %esp\n" /* line 531 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf305a_000030c2:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        "movl %eax, %ebx\n"
        "movl -0xc(%ebp), %edx\n" /* line 187 */
        "testl %edx, %edx\n"
        "je .Lf305a_000030fb\n"
        "movl %esi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf305a_000030fb:\n"
        "movl $0x6e756c6c, -0x10(%ebp)\n" /* line 192 | reply */
        "movl $0, -0xc(%ebp)\n" /* line 193 */
        "movl %ebx, (%esp)\n" /* line 507 */
        "calll __Unwind_Resume\n"
    );
}
#else
double CAEEvent_Send(const CAEEvent * _this)
{ return 0; }
#endif

/* line 638 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAETarget_SetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, const AEDesc *inData, const CAERecord * _this_4, AEKeyword inKeyword, SInt32 *outParam, const CAERecord * _this_7, AEKeyword inKeyword_8, StringPtr outParam_9)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 638 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: inData */
        "leal -0x24(%ebp), %esi\n" /* line 640 | event, inKeyword */
        "movl %esi, (%esp)\n" /* inKeyword */
        "calll CAEEvent_CAEEvent\n"
        "movl $0x73657464, 0xc(%esp)\n" /* line 641 */
        "movl $0x636f7265, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* inKeyword */
        "calll CAEEvent_Create\n"
        "movl $0x6e756c6c, -0x2c(%ebp)\n" /* line 159 | data */
        "movl $0, -0x28(%ebp)\n" /* line 160 | actualSize */
        "movl 0x10(%ebp), %eax\n" /* inPropertyID */
        "movl %eax, -0x1c(%ebp)\n" /* inData */
        /* { scope 2 */
        "movl $4, 0xc(%esp)\n" /* line 322 */
        "leal -0x1c(%ebp), %eax\n" /* inData */
        "movl %eax, 8(%esp)\n"
        "movl $0x74797065, 4(%esp)\n"
        "leal -0x2c(%ebp), %edi\n" /* data */
        "movl %edi, (%esp)\n"
        "calll CAEDesc_PutData\n"
        /* } scope */
        "movl %edi, 0x10(%esp)\n" /* line 646 | this */
        "movl $0x70726f70, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inObjectSpecifier */
        "movl %eax, 8(%esp)\n"
        "movl $0x70726f70, 4(%esp)\n"
        "leal -0x34(%ebp), %ebx\n" /* property, error */
        "movl %ebx, (%esp)\n" /* error */
        "calll CAEObject_CAEObject\n"
        "movl %ebx, 8(%esp)\n" /* line 648 | error */
        "movl $0x2d2d2d2d, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* inKeyword */
        "calll CAERecord_PutParam\n"
        "movl 0x14(%ebp), %eax\n" /* line 650 | inData */
        "movl %eax, 8(%esp)\n"
        "movl $0x64617461, 4(%esp)\n"
    );
}
#else
double CAETarget_SetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, const AEDesc *inData, const CAERecord * _this_4, AEKeyword inKeyword, SInt32 *outParam, const CAERecord * _this_7, AEKeyword inKeyword_8, StringPtr outParam_9)
{ return 0; }
#endif

/* line 575 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAETarget_CountElements(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inElementClass, SInt32 *outCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 575 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1: inParam, actualSize */
        "leal -0x28(%ebp), %esi\n" /* line 577 | event */
        "movl %esi, (%esp)\n"
        "calll CAEEvent_CAEEvent\n"
        "movl $0x636e7465, 0xc(%esp)\n" /* line 578 */
        "movl $0x636f7265, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CAEEvent_Create\n"
        "movl 0xc(%ebp), %eax\n" /* line 580 | inObjectSpecifier */
        "movl %eax, 8(%esp)\n"
        "movl $0x2d2d2d2d, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CAERecord_PutParam\n"
        "movl 0x10(%ebp), %eax\n" /* inElementClass */
        "movl %eax, -0x1c(%ebp)\n" /* inParam */
        /* { scope 2 */
        "movl $4, 0x10(%esp)\n" /* line 462 */
        "leal -0x1c(%ebp), %eax\n" /* inParam */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x74797065, 8(%esp)\n"
        "movl $0x6b6f636c, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll AEPutParamPtr\n"
        "movswl %ax, %ebx\n" /* inError */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf3294_000033f7\n"
        /* } scope */
        "leal -0x30(%ebp), %edi\n" /* line 584 | reply */
        "movl %edi, (%esp)\n"
        "calll CAEEvent_CAEEvent\n"
        "movl $0, 0x18(%esp)\n" /* line 539 */
        "movl $0, 0x14(%esp)\n"
        "movl $0xffffffff, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x13, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll AESend\n"
        "movswl %ax, %ebx\n" /* inError */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf3294_000033cf\n"
        /* { scope 2 */
        "leal -0x20(%ebp), %eax\n" /* line 405 | actualSize */
        "movl %eax, 0x18(%esp)\n"
        "movl $4, 0x14(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* outCount */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* inParam */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x6c6f6e67, 8(%esp)\n"
        "movl $0x2d2d2d2d, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll AEGetParamPtr\n"
        "movswl %ax, %ebx\n" /* inError */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf3294_000033cf\n"
        /* } scope */
        "movl -0x2c(%ebp), %edx\n" /* line 187 */
        "testl %edx, %edx\n"
        "je .Lf3294_000033aa\n"
        "movl %edi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf3294_000033aa:\n"
        "movl $0x6e756c6c, -0x30(%ebp)\n" /* line 192 | reply */
        "movl $0, -0x2c(%ebp)\n" /* line 193 */
        "movl -0x24(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf3294_000033c7\n"
        "movl %esi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        /* } scope */
        ".Lf3294_000033c7:\n"
        "addl $0x4c, %esp\n" /* line 588 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inParam, actualSize */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf3294_000033cf:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf3294_000033f7:\n"
        "movl $4, (%esp)\n"
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* } scope */
        "movl -0x2c(%ebp), %ecx\n" /* line 187 */
        "testl %ecx, %ecx\n"
        "je .Lf3294_00003430\n"
        "movl %edi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf3294_00003430:\n"
        "movl $0x6e756c6c, -0x30(%ebp)\n" /* line 192 | reply */
        "movl $0, -0x2c(%ebp)\n" /* line 193 */
        ".Lf3294_0000343e:\n"
        "movl -0x24(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf3294_0000344d\n"
        "movl %esi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf3294_0000344d:\n"
        "movl $0x6e756c6c, -0x28(%ebp)\n" /* line 192 | event */
        "movl $0, -0x24(%ebp)\n" /* line 193 */
        "movl %ebx, (%esp)\n" /* line 507 | inError */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n" /* inError */
        "jmp .Lf3294_0000343e\n"
    );
}
#else
double CAETarget_CountElements(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inElementClass, SInt32 *outCount)
{ return 0; }
#endif

/* line 608 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
double CAETarget_GetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, DescType inRequestedType, AEDesc *outData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 608 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x14(%ebp), %esi\n" /* inRequestedType */
        /* { scope 1: inData */
        "leal -0x24(%ebp), %edi\n" /* line 610 | event */
        "movl %edi, (%esp)\n"
        "calll CAEEvent_CAEEvent\n"
        "movl $0x67657464, 0xc(%esp)\n" /* line 611 */
        "movl $0x636f7265, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CAEEvent_Create\n"
        "movl $0x6e756c6c, -0x2c(%ebp)\n" /* line 159 | data */
        "movl $0, -0x28(%ebp)\n" /* line 160 */
        "movl 0x10(%ebp), %eax\n" /* inPropertyID */
        "movl %eax, -0x1c(%ebp)\n" /* inData */
        /* { scope 2 */
        "movl $4, 0xc(%esp)\n" /* line 322 */
        "leal -0x1c(%ebp), %ebx\n" /* inData, inError */
        "movl %ebx, 8(%esp)\n" /* inError */
        "movl $0x74797065, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* data */
        "movl %eax, (%esp)\n"
        "calll CAEDesc_PutData\n"
        /* } scope */
        "leal -0x2c(%ebp), %eax\n" /* line 616 | data */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x70726f70, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* inObjectSpecifier */
        "movl %eax, 8(%esp)\n"
        "movl $0x70726f70, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* property */
        "movl %eax, (%esp)\n"
        "calll CAEObject_CAEObject\n"
        "leal -0x34(%ebp), %eax\n" /* line 618 | property */
        "movl %eax, 8(%esp)\n"
        "movl $0x2d2d2d2d, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CAERecord_PutParam\n"
        "testl %esi, %esi\n" /* line 620 | inRequestedType */
        "je .Lf3468_00003551\n"
        "movl %esi, -0x1c(%ebp)\n" /* inRequestedType, inData */
        /* { scope 2 */
        "movl $4, 0xc(%esp)\n" /* line 322 */
        "movl %ebx, 8(%esp)\n" /* inError */
        "movl $0x74797065, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* data */
        "movl %eax, (%esp)\n"
        "calll CAEDesc_PutData\n"
        /* } scope */
        "leal -0x2c(%ebp), %eax\n" /* line 623 | data */
        "movl %eax, 8(%esp)\n"
        "movl $0x72747970, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CAERecord_PutParam\n"
        ".Lf3468_00003551:\n"
        "leal -0x3c(%ebp), %esi\n" /* line 626 | reply, inRequestedType */
        "movl %esi, (%esp)\n" /* inRequestedType */
        "calll CAEEvent_CAEEvent\n"
        "movl $0, 0x18(%esp)\n" /* line 539 */
        "movl $0, 0x14(%esp)\n"
        "movl $0xffffffff, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x13, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll AESend\n"
        "movswl %ax, %ebx\n" /* inError */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf3468_00003637\n"
        "movl 0x18(%ebp), %eax\n" /* line 417 | outData */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2a2a2a2a, 8(%esp)\n"
        "movl $0x2d2d2d2d, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll AEGetParamDesc\n"
        "movswl %ax, %ebx\n" /* inError */
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf3468_00003637\n"
        "movl -0x38(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf3468_000035d2\n"
        "movl %esi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf3468_000035d2:\n"
        "movl $0x6e756c6c, -0x3c(%ebp)\n" /* line 192 | reply */
        "movl $0, -0x38(%ebp)\n" /* line 193 */
        "movl -0x30(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf3468_000035f2\n"
        "leal -0x34(%ebp), %eax\n" /* line 189 | property */
        "movl %eax, (%esp)\n"
        "calll AEDisposeDesc\n"
        ".Lf3468_000035f2:\n"
        "movl $0x6e756c6c, -0x34(%ebp)\n" /* line 192 | property */
        "movl $0, -0x30(%ebp)\n" /* line 193 */
        "movl -0x28(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf3468_00003612\n"
        "leal -0x2c(%ebp), %eax\n" /* line 189 | data */
        "movl %eax, (%esp)\n"
        "calll AEDisposeDesc\n"
        ".Lf3468_00003612:\n"
        "movl $0x6e756c6c, -0x2c(%ebp)\n" /* line 192 | data */
        "movl $0, -0x28(%ebp)\n" /* line 193 */
        "movl -0x20(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf3468_0000362f\n"
        "movl %edi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        /* } scope */
        ".Lf3468_0000362f:\n"
        "addl $0x5c, %esp\n" /* line 630 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inData */
        /* { scope 2 */
        ".Lf3468_00003637:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n"
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl -0x38(%ebp), %edx\n" /* line 187 */
        "testl %edx, %edx\n"
        "je .Lf3468_00003670\n"
        "movl %esi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf3468_00003670:\n"
        "movl $0x6e756c6c, -0x3c(%ebp)\n" /* line 192 | reply */
        "movl $0, -0x38(%ebp)\n" /* line 193 */
        ".Lf3468_0000367e:\n"
        "movl -0x30(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf3468_00003690\n"
        "leal -0x34(%ebp), %eax\n" /* line 189 | property */
        "movl %eax, (%esp)\n"
        "calll AEDisposeDesc\n"
        ".Lf3468_00003690:\n"
        "movl $0x6e756c6c, -0x34(%ebp)\n" /* line 192 | property */
        "movl $0, -0x30(%ebp)\n" /* line 193 */
        ".Lf3468_0000369e:\n"
        "movl -0x28(%ebp), %eax\n" /* line 187 */
        "testl %eax, %eax\n"
        "je .Lf3468_000036b0\n"
        "leal -0x2c(%ebp), %eax\n" /* line 189 | data */
        "movl %eax, (%esp)\n"
        "calll AEDisposeDesc\n"
        ".Lf3468_000036b0:\n"
        "movl $0x6e756c6c, -0x2c(%ebp)\n" /* line 192 | data */
        "movl $0, -0x28(%ebp)\n" /* line 193 */
        ".Lf3468_000036be:\n"
        "movl -0x20(%ebp), %esi\n" /* line 187 */
        "testl %esi, %esi\n"
        "je .Lf3468_000036cd\n"
        "movl %edi, (%esp)\n" /* line 189 */
        "calll AEDisposeDesc\n"
        ".Lf3468_000036cd:\n"
        "movl $0x6e756c6c, -0x24(%ebp)\n" /* line 192 | event */
        "movl $0, -0x20(%ebp)\n" /* line 193 */
        "movl %ebx, (%esp)\n" /* line 507 | inError */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n" /* inError */
        "jmp .Lf3468_0000367e\n"
        "movl %eax, %ebx\n" /* inError */
        "jmp .Lf3468_0000369e\n"
        "movl %eax, %ebx\n" /* inError */
        "jmp .Lf3468_000036be\n"
    );
}
#else
double CAETarget_GetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, DescType inRequestedType, AEDesc *outData)
{ return 0; }
#endif

