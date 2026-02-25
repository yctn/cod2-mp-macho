/* Converted to C from ASM: FxCurve.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxCurve.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/FxCurve.h"
 */

float FxCurve_Integrate(const FxCurve *curve, float normDuration);

void FxCurveIterator_Create(FxCurveIterator *createe, const FxCurve *master)
{
    createe->master = master;
    createe->currentKeyIndex = 0;
}

/* line 102 */
__attribute__((naked))
float FxCurve_Integrate(const FxCurve *curve, float normDuration)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %ebx\n" /* curve */
        "movss 0xc(%ebp), %xmm3\n" /* normDuration */
        /* { scope 1 */
        "leal 8(%ebx), %ecx\n" /* line 117 | curve */
        "movl (%ebx), %eax\n" /* line 118 | curve */
        "addl $1, %eax\n"
        "leal (, %eax, 4), %esi\n"
        "leal (%ecx, %esi), %edx\n"
        "movss (%edx), %xmm1\n" /* line 122 */
        "ucomiss %xmm1, %xmm3\n"
        "ja .Lfba68e_000ba711\n"
        "addl $0xc, %ebx\n" /* curve */
        "pxor %xmm5, %xmm5\n"
        "movss 0x2ed5d8, %xmm6\n" /* 0.5f */
        /* { scope 2 */
        ".Lfba68e_000ba6c8:\n"
        "movss (%ecx), %xmm4\n" /* line 49 */
        "movss (%ebx), %xmm2\n" /* line 51 */
        "subss %xmm4, %xmm3\n" /* line 56 */
        "movss 0xc(%ecx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss 8(%ecx), %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "mulss %xmm6, %xmm2\n"
        "mulss %xmm2, %xmm3\n"
        "addss %xmm3, %xmm5\n"
        /* } scope */
        /* } scope */
        "movss %xmm5, -0xc(%ebp)\n" /* line 133 */
        "flds -0xc(%ebp)\n"
        "addl $4, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfba68e_000ba711:\n"
        "movl %edx, %eax\n" /* line 122 */
        "pxor %xmm5, %xmm5\n"
        "movss 0x2ed5d8, %xmm6\n" /* 0.5f */
        "jmp .Lfba68e_000ba725\n"
        ".Lfba68e_000ba721:\n"
        "movl %eax, %ecx\n"
        "movl %edx, %eax\n"
        ".Lfba68e_000ba725:\n"
        "leal 4(%edx), %ebx\n" /* line 124 | curve */
        "movss 4(%edx), %xmm0\n"
        "addss 4(%ecx), %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "subss (%ecx), %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "addl %esi, %edx\n" /* line 126 */
        "movss (%edx), %xmm1\n" /* line 122 */
        "ucomiss %xmm1, %xmm3\n"
        "ja .Lfba68e_000ba721\n"
        "movl %eax, %ecx\n"
        "jmp .Lfba68e_000ba6c8\n"
    );
}

