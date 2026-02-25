/* ASM dump from: FxCurve_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxCurve_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

const FxCurve * FxCurve_AllocAndCreateWithKeys(const float *keyArray, int dimensionCount, int keyCount);

/* line 10 */
__attribute__((naked))
const FxCurve * FxCurve_AllocAndCreateWithKeys(const float *keyArray, int dimensionCount, int keyCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 10 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 24 | dimensionCount */
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* keySize */
        "pxor %xmm0, %xmm0\n"
        "movl 8(%ebp), %edx\n" /* keyArray */
        "ucomiss (%edx), %xmm0\n"
        "setne %bl\n" /* keyIndex */
        "setp %al\n"
        "orb %al, %bl\n" /* keyIndex */
        "movl 0x10(%ebp), %edx\n" /* keyCount */
        "leal -4(, %edx, 4), %eax\n"
        "imull -0x1c(%ebp), %eax\n" /* keySize */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movl 8(%ebp), %edi\n" /* keyArray */
        "ucomiss (%edi, %eax), %xmm0\n"
        "setne %al\n"
        "movl %eax, %edi\n"
        "setp %al\n"
        "orl %eax, %edi\n"
        "movl $4, 4(%esp)\n" /* line 38 */
        "movl %edi, %edx\n"
        "movzbl %dl, %eax\n"
        "movzbl %bl, %edx\n" /* keyIndex */
        "addl 0x10(%ebp), %edx\n" /* keyCount */
        "addl %edx, %eax\n"
        "imull -0x1c(%ebp), %eax\n" /* keySize */
        "leal 8(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %esi\n" /* newCurve */
        "movl 0xc(%ebp), %eax\n" /* line 45 | dimensionCount */
        "movl %eax, (%esi)\n" /* newCurve */
        "testb %bl, %bl\n" /* line 48 | keyIndex */
        "jne .Lfaca24_000acb16\n"
        "xorl %ebx, %ebx\n" /* keyIndex */
        "xorl %eax, %eax\n"
        ".Lfaca24_000acaa6:\n"
        "leal 8(%esi, %eax, 4), %edx\n" /* line 56 | newCurve */
        "movl -0x1c(%ebp), %eax\n" /* keySize */
        "imull 0x10(%ebp), %eax\n" /* keyCount */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* keyArray */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x10(%ebp), %edx\n" /* line 57 | keyCount */
        "leal (%ebx, %edx), %eax\n" /* keyIndex */
        "movl %edi, %ebx\n" /* line 59 | keyIndex */
        "testb %bl, %bl\n" /* keyIndex */
        "je .Lfaca24_000acb4a\n"
        "imull -0x1c(%ebp), %eax\n" /* line 61 | keySize */
        "movl $0x3f800000, 8(%esi, %eax, 4)\n" /* newCurve */
        "movl 0xc(%ebp), %edx\n" /* line 62 | dimensionCount */
        "testl %edx, %edx\n"
        "je .Lfaca24_000acb06\n"
        "xorl %ecx, %ecx\n"
        "leal 8(%esi, %eax, 4), %edx\n" /* newCurve */
        "movl $4, %ebx\n" /* keyIndex */
        ".Lfaca24_000acaf1:\n"
        "movl 8(%ebp), %edi\n" /* line 63 | keyArray */
        "movl 4(%edi, %ecx, 4), %eax\n"
        "movl %eax, (%edx, %ebx)\n"
        "addl $1, %ecx\n" /* line 62 */
        "addl $4, %edx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* dimensionCount */
        "jne .Lfaca24_000acaf1\n"
        ".Lfaca24_000acb06:\n"
        "movl 0x10(%ebp), %eax\n" /* keyCount */
        "movl %eax, 4(%esi)\n" /* line 71 | newCurve */
        /* } scope */
        "movl %esi, %eax\n" /* line 73 | newCurve */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaca24_000acb16:\n"
        "movl $0, 8(%esi)\n" /* line 50 | newCurve */
        "movl 0xc(%ebp), %ecx\n" /* line 51 | dimensionCount */
        "testl %ecx, %ecx\n"
        "je .Lfaca24_000acb3d\n"
        "movl %esi, %edx\n" /* newCurve */
        "xorl %ecx, %ecx\n"
        ".Lfaca24_000acb28:\n"
        "movl 8(%ebp), %ebx\n" /* line 52 | keyArray, keyIndex */
        "movl 4(%ebx, %ecx, 4), %eax\n" /* keyIndex */
        "movl %eax, 0xc(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl 0xc(%ebp), %ecx\n" /* line 51 | dimensionCount */
        "jne .Lfaca24_000acb28\n"
        ".Lfaca24_000acb3d:\n"
        "movl -0x1c(%ebp), %eax\n" /* keySize */
        "movl $1, %ebx\n" /* keyIndex */
        "jmp .Lfaca24_000acaa6\n"
        ".Lfaca24_000acb4a:\n"
        "movl %edx, %eax\n"
        "movl %eax, 4(%esi)\n" /* line 71 | newCurve */
        /* } scope */
        "movl %esi, %eax\n" /* line 73 | newCurve */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

