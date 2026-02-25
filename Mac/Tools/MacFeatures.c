/* ASM dump from: MacFeatures.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacFeatures.cp */

#include "common_types.h"
#include "imports.h"

static Boolean sTested; /* 0x334982 */
static SInt16 sResult; /* 0x334980 */
static Boolean hasAltiVecBeenDetermined; /* 0x334984 */
static Boolean hasAltiVec; /* 0x334983 */

SInt16 MacFeatures_GetSystemVersion(void);
Boolean MacFeatures_HasGestaltAttribute(OSType inSelector, UInt32 inAttribute);
Boolean MacFeatures_IsAltiVecAvailable(UInt8 *outMajor, UInt8 *outMinor, UInt8 *outBug);
float MacFeatures_GetCPUSpeedInGHz(void);
UInt32 MacFeatures_GetMemorySizeInMB(void);

/* line 19 */
__attribute__((naked))
SInt16 MacFeatures_GetSystemVersion(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 19 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1: response */
        "cmpb $0, sTested\n" /* line 24 */
        "je .Lf8b20_00008b38\n"
        /* { scope 2 */
        ".Lf8b20_00008b2f:\n"
        "movswl sResult, %eax\n" /* line 32 */
        /* } scope */
        /* } scope */
        "leave\n" /* line 37 */
        "retl\n"
        /* { scope 1: response */
        /* { scope 2 */
        ".Lf8b20_00008b38:\n"
        "movb $1, sTested\n" /* line 26 */
        "leal -0xc(%ebp), %eax\n" /* line 29 | response, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl $0x73797376, (%esp)\n"
        "calll Gestalt\n"
        "testw %ax, %ax\n" /* line 30 */
        "jne .Lf8b20_00008b2f\n"
        "movl -0xc(%ebp), %eax\n" /* line 32 | response */
        "movw %ax, sResult\n"
        "movswl sResult, %eax\n"
        /* } scope */
        /* } scope */
        "leave\n" /* line 37 */
        "retl\n"
    );
}

/* line 128 */
__attribute__((naked))
Boolean MacFeatures_HasGestaltAttribute(OSType inSelector, UInt32 inAttribute)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 128 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 131 | result */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inSelector */
        "movl %eax, (%esp)\n"
        "calll Gestalt\n"
        "testw %ax, %ax\n"
        "jne .Lf8b6a_00008b9b\n"
        "movl -0xc(%ebp), %eax\n" /* result */
        "movzbl 0xc(%ebp), %ecx\n" /* inAttribute */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf8b6a_00008b9b\n"
        "movl $1, %eax\n"
        /* } scope */
        "leave\n" /* line 132 */
        "retl\n"
        /* { scope 1 */
        ".Lf8b6a_00008b9b:\n"
        "xorl %eax, %eax\n" /* line 131 */
        /* } scope */
        "leave\n" /* line 132 */
        "retl\n"
    );
}

/* line 57 */
__attribute__((naked))
Boolean MacFeatures_IsAltiVecAvailable(UInt8 *outMajor, UInt8 *outMinor, UInt8 *outBug)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 57 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1: result */
        "cmpb $0, hasAltiVecBeenDetermined\n" /* line 62 */
        "je .Lf8ba2_00008bba\n"
        "movzbl hasAltiVec, %eax\n" /* line 64 */
        /* } scope */
        "leave\n" /* line 73 */
        "retl\n"
        /* { scope 1: result */
        /* { scope 2 */
        ".Lf8ba2_00008bba:\n"
        "leal -0xc(%ebp), %eax\n" /* line 131 | result */
        "movl %eax, 4(%esp)\n"
        "movl $0x70706366, (%esp)\n"
        "calll Gestalt\n"
        "testw %ax, %ax\n"
        "je .Lf8ba2_00008be3\n"
        ".Lf8ba2_00008bd2:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf8ba2_00008bd4:\n"
        "movb %al, hasAltiVec\n" /* line 68 */
        "movb $1, hasAltiVecBeenDetermined\n" /* line 69 */
        /* } scope */
        "leave\n" /* line 73 */
        "retl\n"
        /* { scope 1: result */
        /* { scope 2 */
        ".Lf8ba2_00008be3:\n"
        "testb $0x10, -0xc(%ebp)\n" /* line 131 | result */
        "je .Lf8ba2_00008bd2\n"
        "movl $1, %eax\n"
        "jmp .Lf8ba2_00008bd4\n"
        "addb %al, (%eax)\n"
        /* } scope */
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "subl $0x48, %esp\n"
        "movl $6, -0x18(%ebp)\n"
        "movl $0xf, -0x14(%ebp)\n"
        "movl $4, -0x10(%ebp)\n"
        "leal -0xc(%ebp), %edx\n" /* result */
    );
}

/* line 78 */
__attribute__((naked))
float MacFeatures_GetCPUSpeedInGHz(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 78 */
        "movl %esp, %ebp\n"
        "subl $0x48, %esp\n"
        /* { scope 1: name, len */
        /* { scope 2 */
        "movl $6, -0x18(%ebp)\n" /* line 144 | name */
        "movl $0xf, -0x14(%ebp)\n" /* line 145 */
        "movl $4, -0x10(%ebp)\n" /* line 147 | len */
        "leal -0xc(%ebp), %edx\n" /* line 149 | value */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* len, result */
        "movl %eax, 0xc(%esp)\n" /* result */
        "movl %edx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x18(%ebp), %eax\n" /* name, result */
        "movl %eax, (%esp)\n" /* result */
        "calll sysctl\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 81 */
        "je .Lf8bf2_00008c64\n"
        "movl $0x320, %edx\n" /* line 87 */
        "movl $0x320, -0xc(%ebp)\n" /* value */
        ".Lf8bf2_00008c4e:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "divss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        /* } scope */
        "movss %xmm0, -0x1c(%ebp)\n" /* line 91 */
        "flds -0x1c(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1: name, len */
        ".Lf8bf2_00008c64:\n"
        "movl $0x431bde83, %eax\n" /* line 83 */
        "mull -0xc(%ebp)\n" /* value */
        "shrl $0x12, %edx\n"
        "movl %edx, -0xc(%ebp)\n" /* value */
        "jmp .Lf8bf2_00008c4e\n"
    );
}

/* line 96 */
__attribute__((naked))
UInt32 MacFeatures_GetMemorySizeInMB(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        /* { scope 1: name, len */
        /* { scope 2 */
        "movl $6, -0x18(%ebp)\n" /* line 144 | name */
        "movl $5, -0x14(%ebp)\n" /* line 145 */
        "movl $4, -0x10(%ebp)\n" /* line 147 | len */
        "leal -0xc(%ebp), %edx\n" /* line 149 | value */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* len, result */
        "movl %eax, 0xc(%esp)\n" /* result */
        "movl %edx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x18(%ebp), %eax\n" /* name, result */
        "movl %eax, (%esp)\n" /* result */
        "calll sysctl\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 99 */
        "jne .Lf8c74_00008ccf\n"
        "movl -0xc(%ebp), %eax\n" /* line 101 | value */
        "shrl $0x14, %eax\n"
        "movl %eax, -0xc(%ebp)\n" /* value */
        /* } scope */
        "leave\n" /* line 109 */
        "retl\n"
        /* { scope 1: name, len */
        ".Lf8c74_00008ccf:\n"
        "movl $0x80, %eax\n" /* line 105 */
        "movl $0x80, -0xc(%ebp)\n" /* value */
        /* } scope */
        "leave\n" /* line 109 */
        "retl\n"
    );
}

