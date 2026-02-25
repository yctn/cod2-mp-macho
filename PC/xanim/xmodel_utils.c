/* ASM dump from: xmodel_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/xanim/xmodel_utils.cpp */

#include "common_types.h"
#include "imports.h"

static TestLod g_testLods[4]; /* 0x7ef000 */

const char * XModelGetName(const XModel *model);
unsigned char XModelGetFlags(const XModel *model);
const char * XModelGetSurfaceName(const XModel *model, int subMatIndex, int lod);
int XModelGetSurfaces(const XModel *model, struct XSurface_s * * *surfaces, int lod, int * *partBits);
int XModelGetNumLods(const XModel *model);
int XModelNumBones(const XModel *model);
const DObjAnimMat * XModelGetBasePose(const XModel *model);
const DObjAnimMat * XModelGetBasePoseBone(const XModel *model, int skelMatBoneOffset);
jpeg_scan_info XModelSetTestLods(int lodLevel, float dist);
float XModelGetLodOutDist(const XModel *model);
int XModelGetLodForDist(const XModel *model, float dist);

/* line 23 */
__attribute__((naked))
const char * XModelGetName(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 23 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl 0x88(%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 26 */
        "retl\n"
    );
}

/* line 34 */
__attribute__((naked))
unsigned char XModelGetFlags(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 34 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movzbl 0x8c(%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 37 */
        "retl\n"
    );
}

/* line 45 */
__attribute__((naked))
const char * XModelGetSurfaceName(const XModel *model, int subMatIndex, int lod)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 45 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %eax\n" /* lod, subMatIndex */
        /* { scope 1 */
        "leal (%eax, %eax, 4), %eax\n" /* line 52 */
        "shll $2, %eax\n"
        "addl 8(%ebp), %eax\n" /* model */
        "movl 0x10(%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* subMatIndex */
        "movzwl (%edx, %eax, 2), %eax\n"
        "testw %ax, %ax\n" /* line 53 */
        "jne .Lfb6e56_000b6e7b\n"
        /* } scope */
        "movl $0x217dc0, %eax\n" /* line 54 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb6e56_000b6e7b:\n"
        "movzwl %ax, %eax\n" /* line 53 */
        "movl %eax, 8(%ebp)\n" /* model */
        /* } scope */
        "popl %ebp\n" /* line 54 */
        /* { scope 1 */
        "jmp SL_ConvertToString\n" /* line 53 */
    );
}

/* line 62 */
__attribute__((naked))
int XModelGetSurfaces(const XModel *model, struct XSurface_s * * *surfaces, int lod, int * *partBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 62 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %eax\n" /* lod */
        /* { scope 1 */
        "leal (%eax, %eax, 4), %eax\n" /* line 70 */
        "shll $2, %eax\n"
        "addl 8(%ebp), %eax\n" /* model */
        "addl $4, %eax\n"
        "movl 0x10(%eax), %edx\n" /* line 73 */
        "movl (%edx), %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* surfaces */
        "movl %ecx, (%edx)\n"
        "movl 0x10(%eax), %ecx\n" /* line 74 */
        "addl $4, %ecx\n"
        "movl 0x14(%ebp), %edx\n" /* partBits */
        "movl %ecx, (%edx)\n"
        "movswl 8(%eax), %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 76 */
        "retl\n"
    );
}

/* line 84 */
__attribute__((naked))
int XModelGetNumLods(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 84 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movswl 0x7c(%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 87 */
        "retl\n"
    );
}

/* line 95 */
__attribute__((naked))
int XModelNumBones(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl (%eax), %eax\n" /* model */
        "movswl (%eax), %eax\n" /* model */
        "popl %ebp\n" /* line 98 */
        "retl\n"
    );
}

/* line 107 */
__attribute__((naked))
const DObjAnimMat * XModelGetBasePose(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 107 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl (%eax), %eax\n" /* model */
        "addl $0x44, %eax\n" /* model */
        "popl %ebp\n" /* line 110 */
        "retl\n"
    );
}

/* line 113 */
__attribute__((naked))
const DObjAnimMat * XModelGetBasePoseBone(const XModel *model, int skelMatBoneOffset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 113 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* skelMatBoneOffset */
        "movl 8(%ebp), %eax\n" /* model */
        "movl (%eax), %eax\n" /* model */
        "addl $0x44, %eax\n" /* model */
        "shrl $1, %edx\n" /* skelMatBoneOffset */
        "addl %edx, %eax\n" /* skelMatBoneOffset, model */
        "popl %ebp\n" /* line 126 */
        "retl\n"
    );
}

/* line 175 */
__attribute__((naked))
jpeg_scan_info XModelSetTestLods(int lodLevel, float dist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 175 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* lodLevel */
        "movss 0xc(%ebp), %xmm0\n" /* dist */
        "movl $g_testLods, %edx\n" /* line 178 */
        "movss %xmm0, 4(%edx, %eax, 8)\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 179 | 0.0f */
        "setae (%edx, %eax, 8)\n"
        "popl %ebp\n" /* line 180 */
        "retl\n"
    );
}

/* line 135 */
__attribute__((naked))
float XModelGetLodOutDist(const XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 135 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* model */
        /* { scope 1 */
        "movswl 0x7c(%edx), %eax\n" /* line 139 */
        "subl $1, %eax\n"
        "cmpb $0, g_testLods(, %eax, 8)\n" /* line 140 */
        "jne .Lfb6f16_000b6f36\n"
        "leal (%eax, %eax, 4), %eax\n"
        "flds 4(%edx, %eax, 4)\n"
        /* } scope */
        "popl %ebp\n" /* line 141 */
        "retl\n"
        /* { scope 1 */
        ".Lfb6f16_000b6f36:\n"
        "flds 0x7ef004(, %eax, 8)\n" /* line 140 */
        /* } scope */
        "popl %ebp\n" /* line 141 */
        "retl\n"
    );
}

/* line 149 */
__attribute__((naked))
int XModelGetLodForDist(const XModel *model, float dist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 149 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movss 0xc(%ebp), %xmm2\n" /* dist */
        /* { scope 1 */
        "movswl 0x7c(%eax), %ebx\n" /* line 86 */
        "addl $4, %eax\n" /* line 157 */
        "testl %ebx, %ebx\n" /* line 159 | lodCount */
        "jle .Lfb6f40_000b6f8d\n"
        "xorl %ecx, %ecx\n"
        "movl $g_testLods, %edx\n"
        "pxor %xmm1, %xmm1\n"
        "jmp .Lfb6f40_000b6f81\n"
        ".Lfb6f40_000b6f64:\n"
        "movss (%eax), %xmm0\n" /* line 161 */
        ".Lfb6f40_000b6f68:\n"
        "ucomiss %xmm1, %xmm0\n" /* line 162 */
        "jp .Lfb6f40_000b6f6f\n"
        "je .Lfb6f40_000b6f92\n"
        ".Lfb6f40_000b6f6f:\n"
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lfb6f40_000b6f92\n"
        "addl $1, %ecx\n" /* line 159 */
        "addl $8, %edx\n"
        "addl $0x14, %eax\n"
        "cmpl %ecx, %ebx\n" /* lodCount */
        "je .Lfb6f40_000b6f8d\n"
        ".Lfb6f40_000b6f81:\n"
        "cmpb $0, (%edx)\n" /* line 161 */
        "je .Lfb6f40_000b6f64\n"
        "movss 4(%edx), %xmm0\n"
        "jmp .Lfb6f40_000b6f68\n"
        ".Lfb6f40_000b6f8d:\n"
        "movl $0xffffffff, %ecx\n" /* line 159 */
        /* } scope */
        ".Lfb6f40_000b6f92:\n"
        "movl %ecx, %eax\n" /* line 167 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

