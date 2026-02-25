/* ASM dump from: MacResources.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacResources.cp */

#include "common_types.h"
#include "imports.h"

static CFStringRef sResult; /* 0x334b00 */
static CFStringRef sResult_00334b04; /* 0x334b04 */
static CFStringRef sResult_00334b04; /* 0x334b04 */
static CFStringRef sResult_00334b08; /* 0x334b08 */
static CFStringRef sResult_00334b08; /* 0x334b08 */
static CFStringRef sResult_00334b0c; /* 0x334b0c */
static CFStringRef sResult_00334b0c; /* 0x334b0c */
static CFStringRef sResult_00334b10; /* 0x334b10 */
static CFStringRef sResult_00334b10; /* 0x334b10 */
static SInt32 sResult_00308060; /* 0x308060 */
static SInt32 sResult_00308060; /* 0x308060 */
static CFStringRef sResult_00334b18; /* 0x334b18 */
static CFStringRef sResult_00334b18; /* 0x334b18 */
static CFStringRef sResult_00334b18; /* 0x334b18 */
static CFStringRef sResult_00334b1c; /* 0x334b1c */
static CFStringRef sResult_00334b1c; /* 0x334b1c */
static CFStringRef sResult_00334b20; /* 0x334b20 */
static CFStringRef sResult_00334b20; /* 0x334b20 */
static CFStringRef sResult_00334b20; /* 0x334b20 */
static CFStringRef sResult_00334b24; /* 0x334b24 */
static CFStringRef sResult_00334b24; /* 0x334b24 */
static CFStringRef sResult_00334b24; /* 0x334b24 */
static CFStringRef sResult_00334b28; /* 0x334b28 */
static CFStringRef sResult_00334b28; /* 0x334b28 */
static CFStringRef sResult_00334b28; /* 0x334b28 */
static CFStringRef sResult_00334b2c; /* 0x334b2c */
static CFStringRef sResult_00334b2c; /* 0x334b2c */
static CFStringRef sResult_00334b2c; /* 0x334b2c */

bool MacResources_GetGameString(CFStringRef inKeyRef, unsigned char *outString);
CFStringRef MacResources_GetProductFamily(void);
CFStringRef MacResources_GetDiscName(void);
SInt32 MacResources_GetLanguageCode(void);
CFStringRef MacResources_GetNeedsNewerOSError(void);
CFStringRef MacResources_GetNoQuickTimeError(void);
CFStringRef MacResources_GetMissingDataFolderError(void);
CFStringRef MacResources_GetInsertDiscError(void);
CFStringRef MacResources_GetNeeds32BitError(void);
CFStringRef MacResources_GetCantRunFromDiscError(void);

/* line 64 */
__attribute__((naked))
bool MacResources_GetGameString(CFStringRef inKeyRef, unsigned char *outString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 64 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* inKeyRef */
        /* { scope 1 */
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 69 */
        "je .Lf9fac_0000a011\n"
        "movl $0, 0xc(%esp)\n" /* line 71 */
        "movl $0x100, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* outString */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* stringRef */
        "calll CFStringGetPascalString\n"
        "movl %eax, %ebx\n" /* inKeyRef */
        "movl %esi, (%esp)\n" /* line 76 | stringRef */
        "calll CFRelease\n"
        "xorl %eax, %eax\n"
        "testb %bl, %bl\n" /* inKeyRef */
        "setne %al\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 80 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9fac_0000a011:\n"
        "xorl %eax, %eax\n" /* line 69 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 80 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 85 */
__attribute__((naked))
CFStringRef MacResources_GetProductFamily(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 85 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl sResult, %eax\n" /* line 89 */
        "testl %eax, %eax\n"
        "je .Lfa01a_0000a030\n"
        "movl sResult, %eax\n"
        /* } scope */
        "leave\n" /* line 95 */
        "retl\n"
        /* { scope 1 */
        ".Lfa01a_0000a030:\n"
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl $0x32e6c4, 8(%esp)\n"
        "movl $0x32e6c4, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 91 */
        /* } scope */
        "leave\n" /* line 95 */
        "retl\n"
    );
}

/* line 145 */
__attribute__((naked))
CFStringRef MacResources_GetDiscName(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 145 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl sResult, %eax\n" /* line 149 */
        "testl %eax, %eax\n"
        "je .Lfa05e_0000a074\n"
        "movl sResult, %eax\n"
        /* } scope */
        "leave\n" /* line 155 */
        "retl\n"
        /* { scope 1 */
        ".Lfa05e_0000a074:\n"
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl $0x32e704, 8(%esp)\n"
        "movl $0x32e704, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 151 */
        /* } scope */
        "leave\n" /* line 155 */
        "retl\n"
    );
}

/* line 266 */
__attribute__((naked))
SInt32 MacResources_GetLanguageCode(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 266 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x110, %esp\n"
        /* { scope 1: buffer */
        "cmpl $0x7fff, sResult\n" /* line 270 */
        "je .Lfa0a0_0000a0c6\n"
        /* { scope 2 */
        "movl sResult, %eax\n" /* line 275 */
        /* } scope */
        /* } scope */
        "addl $0x110, %esp\n" /* line 279 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfa0a0_0000a0c6:\n"
        "calll CFBundleGetMainBundle\n" /* line 165 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x32e714, 8(%esp)\n"
    );
}

/* line 284 */
__attribute__((naked))
CFStringRef MacResources_GetNeedsNewerOSError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 284 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl sResult, %eax\n" /* line 288 */
        "testl %eax, %eax\n"
        "je .Lfa144_0000a15f\n"
        /* { scope 2 */
        ".Lfa144_0000a154:\n"
        "movl sResult, %eax\n" /* line 295 */
        /* } scope */
        /* } scope */
        "addl $0x14, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa144_0000a15f:\n"
        "calll CFBundleGetMainBundle\n" /* line 165 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x32e734, 8(%esp)\n"
        "movl $0x32e734, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 291 */
        "je .Lfa144_0000a154\n"
        "movl sResult, %eax\n" /* line 104 */
        "testl %eax, %eax\n"
        "je .Lfa144_0000a1cc\n"
        "movl sResult, %eax\n"
        ".Lfa144_0000a198:\n"
        "movl %eax, 0xc(%esp)\n" /* line 293 */
        "movl %ebx, 8(%esp)\n" /* stringRef */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithFormat\n"
        "movl %eax, sResult\n"
        "movl %ebx, (%esp)\n" /* line 295 | stringRef */
        "calll CFRelease\n"
        "movl sResult, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x14, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa144_0000a1cc:\n"
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl $0x32e6d4, 8(%esp)\n"
        "movl $0x32e6d4, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 106 */
        "jmp .Lfa144_0000a198\n"
    );
}

/* line 305 */
__attribute__((naked))
CFStringRef MacResources_GetNoQuickTimeError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 305 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl sResult, %eax\n" /* line 309 */
        "testl %eax, %eax\n"
        "je .Lfa1f8_0000a20e\n"
        "movl sResult, %eax\n"
        /* } scope */
        "leave\n" /* line 315 */
        "retl\n"
        /* { scope 1 */
        ".Lfa1f8_0000a20e:\n"
        "calll CFBundleGetMainBundle\n" /* line 165 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x32e744, 8(%esp)\n"
        "movl $0x32e744, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 311 */
        /* } scope */
        "leave\n" /* line 315 */
        "retl\n"
    );
}

/* line 320 */
__attribute__((naked))
CFStringRef MacResources_GetMissingDataFolderError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 320 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl sResult, %edi\n" /* line 324 */
        "testl %edi, %edi\n"
        "je .Lfa23a_0000a25a\n"
        /* { scope 2 */
        ".Lfa23a_0000a24d:\n"
        "movl sResult, %eax\n" /* line 331 */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa23a_0000a25a:\n"
        "calll CFBundleGetMainBundle\n" /* line 165 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x32e754, 8(%esp)\n"
        "movl $0x32e754, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 327 */
        "je .Lfa23a_0000a24d\n"
        "movl sResult, %esi\n" /* line 119 */
        "testl %esi, %esi\n"
        "je .Lfa23a_0000a2f6\n"
        "movl sResult, %edi\n"
        ".Lfa23a_0000a295:\n"
        "movl sResult, %ecx\n" /* line 134 */
        "testl %ecx, %ecx\n"
        "je .Lfa23a_0000a356\n"
        "movl sResult, %esi\n"
        ".Lfa23a_0000a2a9:\n"
        "movl sResult, %edx\n" /* line 104 */
        "testl %edx, %edx\n"
        "je .Lfa23a_0000a327\n"
        "movl sResult, %eax\n"
        ".Lfa23a_0000a2b8:\n"
        "movl %edi, 0x14(%esp)\n" /* line 329 */
        "movl %esi, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* stringRef */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithFormat\n"
        "movl %eax, sResult\n"
        "movl %ebx, (%esp)\n" /* line 331 | stringRef */
        "calll CFRelease\n"
        "movl sResult, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa23a_0000a2f6:\n"
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl $0x32e6e4, 8(%esp)\n"
        "movl $0x32e6e4, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 121 */
        "movl %eax, %edi\n"
        "jmp .Lfa23a_0000a295\n"
        ".Lfa23a_0000a327:\n"
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl $0x32e6d4, 8(%esp)\n"
        "movl $0x32e6d4, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 106 */
        "jmp .Lfa23a_0000a2b8\n"
        ".Lfa23a_0000a356:\n"
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl $0x32e6f4, 8(%esp)\n"
        "movl $0x32e6f4, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 136 */
        "movl %eax, %esi\n"
        "jmp .Lfa23a_0000a2a9\n"
    );
}

/* line 341 */
__attribute__((naked))
CFStringRef MacResources_GetInsertDiscError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 341 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl sResult, %eax\n" /* line 345 */
        "testl %eax, %eax\n"
        "je .Lfa388_0000a3a3\n"
        /* { scope 2 */
        ".Lfa388_0000a398:\n"
        "movl sResult, %eax\n" /* line 352 */
        /* } scope */
        /* } scope */
        "addl $0x14, %esp\n" /* line 357 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa388_0000a3a3:\n"
        "calll CFBundleGetMainBundle\n" /* line 165 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x32e764, 8(%esp)\n"
        "movl $0x32e764, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 348 */
        "je .Lfa388_0000a398\n"
        "movl sResult, %eax\n" /* line 104 */
        "testl %eax, %eax\n"
        "je .Lfa388_0000a410\n"
        "movl sResult, %eax\n"
        ".Lfa388_0000a3dc:\n"
        "movl %eax, 0xc(%esp)\n" /* line 350 */
        "movl %ebx, 8(%esp)\n" /* stringRef */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithFormat\n"
        "movl %eax, sResult\n"
        "movl %ebx, (%esp)\n" /* line 352 | stringRef */
        "calll CFRelease\n"
        "movl sResult, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x14, %esp\n" /* line 357 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa388_0000a410:\n"
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl $0x32e6d4, 8(%esp)\n"
        "movl $0x32e6d4, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 106 */
        "jmp .Lfa388_0000a3dc\n"
    );
}

/* line 362 */
__attribute__((naked))
CFStringRef MacResources_GetNeeds32BitError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 362 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl sResult, %eax\n" /* line 366 */
        "testl %eax, %eax\n"
        "je .Lfa43c_0000a457\n"
        /* { scope 2 */
        ".Lfa43c_0000a44c:\n"
        "movl sResult, %eax\n" /* line 373 */
        /* } scope */
        /* } scope */
        "addl $0x14, %esp\n" /* line 378 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa43c_0000a457:\n"
        "calll CFBundleGetMainBundle\n" /* line 165 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x32e774, 8(%esp)\n"
        "movl $0x32e774, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 369 */
        "je .Lfa43c_0000a44c\n"
        "movl sResult, %eax\n" /* line 104 */
        "testl %eax, %eax\n"
        "je .Lfa43c_0000a4c4\n"
        "movl sResult, %eax\n"
        ".Lfa43c_0000a490:\n"
        "movl %eax, 0xc(%esp)\n" /* line 371 */
        "movl %ebx, 8(%esp)\n" /* stringRef */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CFStringCreateWithFormat\n"
        "movl %eax, sResult\n"
        "movl %ebx, (%esp)\n" /* line 373 | stringRef */
        "calll CFRelease\n"
        "movl sResult, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x14, %esp\n" /* line 378 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa43c_0000a4c4:\n"
        "calll CFBundleGetMainBundle\n" /* line 32 */
        "movl $0x32e6b4, 0xc(%esp)\n"
        "movl $0x32e6d4, 8(%esp)\n"
        "movl $0x32e6d4, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, sResult\n" /* line 106 */
        "jmp .Lfa43c_0000a490\n"
    );
}

/* line 383 */
__attribute__((naked))
CFStringRef MacResources_GetCantRunFromDiscError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 383 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl sResult, %eax\n" /* line 387 */
        "testl %eax, %eax\n"
        "je .Lfa4f0_0000a50b\n"
        /* { scope 2 */
        "movl sResult, %eax\n" /* line 394 */
        /* } scope */
        /* } scope */
        "addl $0x14, %esp\n" /* line 399 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfa4f0_0000a50b:\n"
        "calll CFBundleGetMainBundle\n" /* line 165 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x32e784, 8(%esp)\n"
        "movl $0x32e784, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CFBundleCopyLocalizedString\n"
        "movl %eax, %ebx\n"
    );
}

