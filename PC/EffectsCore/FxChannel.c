/* ASM dump from: FxChannel.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxChannel.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

void FxChannel_CreateDefault(FxChannel *createe, int dimensions, float value1, float value2);
void FxChannel_CreateViaMigration(const FxChannelBackwardCompatible *source, int dimensions, float lifetime, int forceUnitScale, FxChannel *target);

/* line 20 */
__attribute__((naked))
void FxChannel_CreateDefault(FxChannel *createe, int dimensions, float value1, float value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 20 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* dimensions */
        "movl 0x14(%ebp), %edi\n" /* value2 */
        /* { scope 1 */
        "leal 1(%ebx), %eax\n" /* line 31 | dimensions */
        "movl $0, -0x58(%ebp)\n" /* line 33 | keys */
        "movl $0x3f800000, -0x58(%ebp, %eax, 4)\n" /* line 34 */
        "testl %ebx, %ebx\n" /* line 36 | dimensions */
        "je .Lfacb5c_000acba8\n"
        "xorl %ecx, %ecx\n"
        "leal -0x58(%ebp, %eax, 4), %eax\n"
        "movl $4, %esi\n"
        "leal -0x54(%ebp), %edx\n"
        ".Lfacb5c_000acb8f:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 38 | value1 */
        "movss %xmm0, (%edx)\n"
        "movl %edi, (%eax, %esi)\n" /* line 39 | value2 */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl %ebx, %ecx\n" /* line 36 | dimensions */
        "jne .Lfacb5c_000acb8f\n"
        ".Lfacb5c_000acba8:\n"
        "movl $2, 8(%esp)\n" /* line 42 */
        "movl %ebx, 4(%esp)\n" /* dimensions */
        "leal -0x58(%ebp), %eax\n" /* keys */
        "movl %eax, (%esp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl 8(%ebp), %edx\n" /* createe */
        "movl %eax, (%edx)\n"
        "movl $0x3f800000, %eax\n" /* line 43 */
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, %eax\n"
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxRange_SetRange\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 44 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 190 */
__attribute__((naked))
void FxChannel_CreateViaMigration(const FxChannelBackwardCompatible *source, int dimensions, float lifetime, int forceUnitScale, FxChannel *target)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 190 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2cc, %esp\n"
        /* { scope 1: keys, keySize, dimensionId, valLT */
        "cmpb $0, 0x14(%ebp)\n" /* line 203 | forceUnitScale */
        "je .Lfacbe8_000ad0b4\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        ".Lfacbe8_000acc06:\n"
        "movss %xmm0, -0x24c(%ebp)\n"
        "movaps %xmm0, %xmm2\n"
        ".Lfacbe8_000acc11:\n"
        "movl 8(%ebp), %eax\n" /* line 209 | source */
        "movss 4(%eax), %xmm0\n"
        "subss (%eax), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movaps %xmm2, %xmm1\n" /* line 211 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* target */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxRange_SetRange\n"
        "movl 0xc(%ebp), %esi\n" /* line 217 | dimensions, dimensionId */
        "testl %esi, %esi\n" /* dimensionId */
        "je .Lfacbe8_000ad0a0\n"
        "movl $0, -0x25c(%ebp)\n" /* dimensionId */
        "movl 8(%ebp), %edx\n" /* source */
        "addl $0x30, %edx\n"
        "movl %edx, -0x268(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* source, timeStep */
        "addl $0x18, %edi\n" /* timeStep */
        "movl 8(%ebp), %esi\n" /* source, dimensionId */
        ".Lfacbe8_000acc74:\n"
        "movl $0x3f000000, 4(%esp)\n" /* line 219 */
        "movl %esi, (%esp)\n" /* dimensionId */
        "calll FxRange_GetValPct\n"
        "fstps -0x2bc(%ebp)\n"
        "movss -0x2bc(%ebp), %xmm0\n"
        "movl -0x25c(%ebp), %ebx\n" /* dimensionId, currentKey */
        "shll $2, %ebx\n" /* currentKey */
        "mulss -0x24c(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp, %ebx)\n"
        "movl $0x3f000000, 4(%esp)\n" /* line 220 */
        "movl %edi, (%esp)\n" /* timeStep */
        "calll FxRange_GetValPct\n"
        "fstps -0x2bc(%ebp)\n"
        "movss -0x2bc(%ebp), %xmm0\n"
        "mulss -0x24c(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp, %ebx)\n"
        "movl $0x3f000000, 4(%esp)\n" /* line 221 */
        "movl -0x268(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxRange_GetValPct\n"
        "fstps -0x2bc(%ebp)\n"
        "movss -0x2bc(%ebp), %xmm0\n"
        "mulss -0x24c(%ebp), %xmm0\n"
        "addl $1, -0x25c(%ebp)\n" /* line 217 | dimensionId */
        "addl $8, %esi\n" /* dimensionId */
        "addl $8, %edi\n" /* timeStep */
        "movl -0x25c(%ebp), %edx\n" /* dimensionId */
        "cmpl %edx, 0xc(%ebp)\n" /* dimensions */
        "jne .Lfacbe8_000acc74\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 0x2ed738, %xmm1\n" /* 0.009999999776482582f */
        "movss %xmm1, -0x248(%ebp)\n"
        "mulss 0x2ed818, %xmm0\n" /* 0.0031415929552167654f */
        "pxor %xmm6, %xmm6\n"
        ".Lfacbe8_000acd3c:\n"
        "mulss 0x10(%ebp), %xmm0\n" /* line 226 | lifetime */
        "movss %xmm0, -0x260(%ebp)\n" /* waveParm */
        "movl 8(%ebp), %edx\n" /* line 228 | source */
        "movl 0x38(%edx), %eax\n"
        "movl %eax, %edx\n" /* line 230 */
        "andb $1, %dl\n"
        "movb %dl, -0x261(%ebp)\n"
        "je .Lfacbe8_000acf93\n"
        "movl %eax, %esi\n" /* dimensionId */
        "andl $0xc, %esi\n" /* dimensionId */
        "je .Lfacbe8_000ad01e\n"
        /* { scope 2 */
        ".Lfacbe8_000acd6b:\n"
        "movl 0xc(%ebp), %edx\n" /* line 121 | dimensions */
        "addl $1, %edx\n"
        "movl %edx, -0x254(%ebp)\n" /* keySize */
        "shrl $1, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, -0x240(%ebp)\n"
        "movaps %xmm6, %xmm4\n"
        "xorl %edi, %edi\n" /* timeStep */
        "movss 0x2ed5d0, %xmm5\n" /* 1.0f */
        "cmpb $0, -0x261(%ebp)\n" /* line 134 */
        "je .Lfacbe8_000ace86\n"
        ".Lfacbe8_000acd9c:\n"
        "movaps %xmm5, %xmm3\n" /* line 135 */
        "subss %xmm4, %xmm3\n"
        "cmpl $4, %esi\n" /* line 137 | dimensionId */
        "je .Lfacbe8_000ace92\n"
        ".Lfacbe8_000acdac:\n"
        "cmpl $8, %esi\n" /* line 147 | dimensionId */
        "je .Lfacbe8_000acf09\n"
        "cmpl $0xc, %esi\n" /* line 151 | dimensionId */
        "je .Lfacbe8_000acec4\n"
        "movaps %xmm3, %xmm2\n"
        ".Lfacbe8_000acdc1:\n"
        "movl -0x254(%ebp), %eax\n" /* line 164 | keySize */
        "imull %edi, %eax\n" /* timeStep */
        "leal -0x230(%ebp, %eax, 4), %ebx\n" /* currentKey */
        "movss %xmm4, (%ebx)\n" /* line 165 | currentKey */
        "movl 0xc(%ebp), %edx\n" /* line 167 | dimensions */
        "testl %edx, %edx\n"
        "je .Lfacbe8_000ace53\n"
        "movaps %xmm5, %xmm3\n"
        "subss %xmm2, %xmm3\n"
        "movss %xmm3, -0x244(%ebp)\n"
        "movl -0x240(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfacbe8_000ad140\n"
        "ucomiss %xmm5, %xmm2\n"
        "ja .Lfacbe8_000ad27e\n"
        "xorl %edx, %edx\n"
        "pxor %xmm6, %xmm6\n"
        "movaps %xmm6, %xmm3\n"
        "jmp .Lfacbe8_000ace1b\n"
        ".Lfacbe8_000ace0d:\n"
        "movss %xmm1, 4(%ebx, %edx, 4)\n" /* line 179 | currentKey */
        "addl $1, %edx\n" /* line 167 */
        "cmpl %edx, 0xc(%ebp)\n" /* dimensions */
        "je .Lfacbe8_000ace53\n"
        ".Lfacbe8_000ace1b:\n"
        "leal (, %edx, 4), %eax\n" /* line 169 */
        "movss -0x244(%ebp), %xmm1\n"
        "mulss -0x30(%ebp, %eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss -0x24(%ebp, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm1, %xmm6\n" /* line 171 */
        "jbe .Lfacbe8_000ace0d\n"
        "movaps %xmm3, %xmm1\n" /* line 167 */
        "movss %xmm1, 4(%ebx, %edx, 4)\n" /* line 179 | currentKey */
        "addl $1, %edx\n" /* line 167 */
        "cmpl %edx, 0xc(%ebp)\n" /* dimensions */
        "jne .Lfacbe8_000ace1b\n"
        ".Lfacbe8_000ace53:\n"
        "addl $1, %edi\n" /* line 123 | timeStep */
        "addss 0x2ed81c, %xmm4\n" /* 0.06666667014360428f */
        "cmpl $0x10, %edi\n" /* timeStep */
        "je .Lfacbe8_000acf66\n"
        "movss 0x2ed5d0, %xmm5\n" /* line 126 | 1.0f */
        "movaps %xmm5, %xmm0\n"
        "minss %xmm4, %xmm0\n"
        "movaps %xmm0, %xmm4\n"
        "cmpb $0, -0x261(%ebp)\n" /* line 134 */
        "jne .Lfacbe8_000acd9c\n"
        ".Lfacbe8_000ace86:\n"
        "movaps %xmm5, %xmm3\n"
        "cmpl $4, %esi\n" /* line 137 | dimensionId */
        "jne .Lfacbe8_000acdac\n"
        ".Lfacbe8_000ace92:\n"
        "ucomiss -0x248(%ebp), %xmm4\n" /* line 139 */
        "ja .Lfacbe8_000acee6\n"
        "movaps %xmm5, %xmm2\n"
        ".Lfacbe8_000ace9e:\n"
        "cmpb $0, -0x261(%ebp)\n" /* line 158 */
        "je .Lfacbe8_000acdc1\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 159 | 0.5f */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm3, %xmm2\n"
        "jmp .Lfacbe8_000acdc1\n"
        ".Lfacbe8_000acec4:\n"
        "movss -0x248(%ebp), %xmm1\n" /* line 153 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm4, %xmm1\n"
        "jbe .Lfacbe8_000ace9e\n"
        "movaps %xmm1, %xmm2\n"
        "subss %xmm4, %xmm2\n" /* line 154 */
        "divss -0x248(%ebp), %xmm2\n"
        "jmp .Lfacbe8_000ace9e\n"
        ".Lfacbe8_000acee6:\n"
        "movaps %xmm4, %xmm0\n" /* line 140 */
        "subss -0x248(%ebp), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "subss -0x248(%ebp), %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movaps %xmm5, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "jmp .Lfacbe8_000ace9e\n"
        ".Lfacbe8_000acf09:\n"
        "movss -0x260(%ebp), %xmm0\n" /* line 149 | waveParm */
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm3, -0x288(%ebp)\n"
        "movss %xmm4, -0x298(%ebp)\n"
        "movss %xmm5, -0x2a8(%ebp)\n"
        "calll cosf\n"
        "fstps -0x2bc(%ebp)\n"
        "movss -0x2bc(%ebp), %xmm2\n"
        "movss -0x288(%ebp), %xmm3\n"
        "mulss %xmm3, %xmm2\n"
        "movss -0x298(%ebp), %xmm4\n"
        "movss -0x2a8(%ebp), %xmm5\n"
        "jmp .Lfacbe8_000acdc1\n"
        ".Lfacbe8_000acf66:\n"
        "movl $0x10, 8(%esp)\n" /* line 186 */
        "movl 0xc(%ebp), %edx\n" /* dimensions */
        "movl %edx, 4(%esp)\n"
        "leal -0x230(%ebp), %eax\n" /* keys */
        "movl %eax, (%esp)\n"
        /* } scope */
        /* { scope 2 */
        "calll FxCurve_AllocAndCreateWithKeys\n" /* line 105 */
        "movl 0x18(%ebp), %edx\n" /* target */
        "movl %eax, (%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x2cc, %esp\n" /* line 236 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keys, keySize, dimensionId, valLT */
        ".Lfacbe8_000acf93:\n"
        "movl %eax, %esi\n" /* line 232 | dimensionId */
        "andl $0xc, %esi\n" /* dimensionId */
        "cmpl $4, %esi\n" /* dimensionId */
        "jne .Lfacbe8_000acd6b\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 89 | dimensions */
        "addl $1, %eax\n"
        "movl $0, -0x230(%ebp)\n" /* line 91 | keys */
        "movss -0x248(%ebp), %xmm0\n" /* line 92 */
        "movss %xmm0, -0x230(%ebp, %eax, 4)\n"
        "movl $0x3f800000, -0x230(%ebp, %eax, 8)\n" /* line 93 */
        "movl 0xc(%ebp), %ecx\n" /* line 95 | dimensions */
        "testl %ecx, %ecx\n"
        "je .Lfacbe8_000ad014\n"
        "xorw %si, %si\n" /* dimensionId */
        "leal -0x24(%ebp), %edi\n" /* start */
        "leal -0x230(%ebp, %eax, 4), %ebx\n" /* dimensionId */
        "leal -0x230(%ebp, %eax, 8), %ecx\n"
        "xorl %edx, %edx\n"
        ".Lfacbe8_000acfea:\n"
        "addl $1, %esi\n" /* line 97 | dimensionId */
        "addl $4, %edx\n"
        "movl -4(%edx, %edi), %eax\n"
        "movl %eax, -0x230(%edx, %ebp)\n"
        "movl -4(%edx, %edi), %eax\n" /* line 98 */
        "movl %eax, 4(%ebx)\n" /* dimensionId */
        "movl -0x34(%edx, %ebp), %eax\n" /* line 99 */
        "movl %eax, 4(%ecx)\n"
        "addl $4, %ebx\n" /* dimensionId */
        "addl $4, %ecx\n"
        "cmpl %esi, 0xc(%ebp)\n" /* line 95 | dimensionId, dimensions */
        "jne .Lfacbe8_000acfea\n"
        ".Lfacbe8_000ad014:\n"
        "movl $3, 8(%esp)\n" /* line 105 */
        "jmp .Lfacbe8_000ad07b\n"
        /* } scope */
        /* { scope 2 */
        ".Lfacbe8_000ad01e:\n"
        "movl 0xc(%ebp), %eax\n" /* line 64 | dimensions */
        "addl $1, %eax\n"
        "movl $0, -0x230(%ebp)\n" /* line 66 | keys */
        "movl $0x3f800000, -0x230(%ebp, %eax, 4)\n" /* line 67 */
        "movl 0xc(%ebp), %ebx\n" /* line 69 | dimensions, dimensionId */
        "testl %ebx, %ebx\n" /* dimensionId */
        "je .Lfacbe8_000ad073\n"
        "xorl %ebx, %ebx\n" /* dimensionId */
        "leal -0x24(%ebp), %edi\n" /* start */
        "leal -0x230(%ebp, %eax, 4), %edx\n"
        "movl $4, %esi\n"
        "xorl %ecx, %ecx\n"
        ".Lfacbe8_000ad053:\n"
        "addl $1, %ebx\n" /* line 71 | dimensionId */
        "addl $4, %ecx\n"
        "movl -4(%ecx, %edi), %eax\n"
        "movl %eax, -0x230(%ecx, %ebp)\n"
        "movl -0x34(%ecx, %ebp), %eax\n" /* line 72 */
        "movl %eax, (%edx, %esi)\n"
        "addl $4, %edx\n"
        "cmpl %ebx, 0xc(%ebp)\n" /* line 69 | dimensionId, dimensions */
        "jne .Lfacbe8_000ad053\n"
        ".Lfacbe8_000ad073:\n"
        "movl $2, 8(%esp)\n" /* line 78 */
        /* } scope */
        /* { scope 2 */
        ".Lfacbe8_000ad07b:\n"
        "movl 0xc(%ebp), %eax\n" /* line 105 | dimensions */
        "movl %eax, 4(%esp)\n"
        "leal -0x230(%ebp), %edx\n" /* keys */
        "movl %edx, (%esp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl 0x18(%ebp), %edx\n" /* target */
        "movl %eax, (%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x2cc, %esp\n" /* line 236 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keys, keySize, dimensionId, valLT */
        ".Lfacbe8_000ad0a0:\n"
        "pxor %xmm6, %xmm6\n" /* line 217 */
        "movss %xmm6, -0x248(%ebp)\n"
        "movaps %xmm6, %xmm0\n"
        "jmp .Lfacbe8_000acd3c\n"
        ".Lfacbe8_000ad0b4:\n"
        "movl $0x3f000000, %ebx\n" /* line 204 | currentKey */
        "movl %ebx, 4(%esp)\n" /* currentKey */
        "movl 8(%ebp), %eax\n" /* source */
        "addl $0x18, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxRange_GetValPct\n"
        "fstps -0x258(%ebp)\n" /* valLT */
        "movl %ebx, 4(%esp)\n" /* currentKey */
        "movl 8(%ebp), %eax\n" /* source */
        "movl %eax, (%esp)\n"
        "calll FxRange_GetValPct\n"
        "fstps -0x2bc(%ebp)\n"
        "movss -0x2bc(%ebp), %xmm0\n"
        /* { scope 2 */
        "movaps %xmm0, %xmm2\n" /* line 45 */
        "subss -0x258(%ebp), %xmm2\n" /* valLT */
        "movss -0x258(%ebp), %xmm3\n" /* valLT */
        "movaps %xmm3, %xmm1\n"
        "cmpltss 0x2ed5e8, %xmm2\n" /* 0.0f */
        "andps %xmm2, %xmm1\n"
        "andnps %xmm0, %xmm2\n"
        "orps %xmm1, %xmm2\n"
        /* } scope */
        "mulss 0x2ed814, %xmm2\n" /* line 204 | 1.3333333730697632f */
        "movss 0x2ed5d0, %xmm0\n" /* line 206 | 1.0f */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lfacbe8_000acc06\n"
        "divss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24c(%ebp)\n"
        "jmp .Lfacbe8_000acc11\n"
        /* { scope 2 */
        ".Lfacbe8_000ad140:\n"
        "ucomiss %xmm5, %xmm2\n" /* line 167 */
        "ja .Lfacbe8_000ad1d3\n"
        "movl $0, -0x23c(%ebp)\n"
        ".Lfacbe8_000ad153:\n"
        "movl -0x23c(%ebp), %eax\n" /* line 169 */
        "shll $2, %eax\n"
        "movaps %xmm2, %xmm1\n"
        "mulss -0x24(%ebp, %eax), %xmm1\n"
        "movss -0x244(%ebp), %xmm0\n"
        "mulss -0x30(%ebp, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 171 */
        "ucomiss %xmm1, %xmm3\n"
        "jbe .Lfacbe8_000ad184\n"
        "pxor %xmm1, %xmm1\n" /* line 167 */
        ".Lfacbe8_000ad184:\n"
        "movss %xmm1, 4(%esp)\n" /* line 177 */
        "movl $0, (%esp)\n"
        "movss %xmm2, -0x278(%ebp)\n"
        "movss %xmm4, -0x298(%ebp)\n"
        "calll flrand\n"
        "movl -0x23c(%ebp), %eax\n" /* line 179 */
        "fstps 4(%ebx, %eax, 4)\n" /* currentKey */
        "addl $1, %eax\n" /* line 167 */
        "movl %eax, -0x23c(%ebp)\n"
        "cmpl %eax, 0xc(%ebp)\n" /* dimensions */
        "movss -0x278(%ebp), %xmm2\n"
        "movss -0x298(%ebp), %xmm4\n"
        "jne .Lfacbe8_000ad153\n"
        "jmp .Lfacbe8_000ace53\n"
        ".Lfacbe8_000ad1d3:\n"
        "movl $0, -0x250(%ebp)\n" /* dimensionId */
        "pxor %xmm6, %xmm6\n"
        ".Lfacbe8_000ad1e1:\n"
        "movl -0x250(%ebp), %eax\n" /* line 171 | dimensionId */
        "shll $2, %eax\n"
        "movaps %xmm2, %xmm0\n"
        "mulss -0x24(%ebp, %eax), %xmm0\n"
        "movss -0x244(%ebp), %xmm1\n"
        "mulss -0x30(%ebp, %eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movl $0x3f800000, %eax\n"
        "ucomiss %xmm0, %xmm6\n"
        "jbe .Lfacbe8_000ad21d\n"
        "movss %xmm6, -0x2bc(%ebp)\n"
        "movl -0x2bc(%ebp), %eax\n"
        ".Lfacbe8_000ad21d:\n"
        "movl %eax, 4(%esp)\n" /* line 177 */
        "movl $0, (%esp)\n"
        "movss %xmm2, -0x278(%ebp)\n"
        "movss %xmm4, -0x298(%ebp)\n"
        "movss %xmm6, -0x2b8(%ebp)\n"
        "calll flrand\n"
        "movl -0x250(%ebp), %eax\n" /* line 179 | dimensionId */
        "fstps 4(%ebx, %eax, 4)\n" /* currentKey */
        "addl $1, %eax\n" /* line 167 */
        "movl %eax, -0x250(%ebp)\n" /* dimensionId */
        "cmpl %eax, 0xc(%ebp)\n" /* dimensions */
        "movss -0x278(%ebp), %xmm2\n"
        "movss -0x298(%ebp), %xmm4\n"
        "movss -0x2b8(%ebp), %xmm6\n"
        "jne .Lfacbe8_000ad1e1\n"
        "jmp .Lfacbe8_000ace53\n"
        ".Lfacbe8_000ad27e:\n"
        "xorl %edx, %edx\n" /* line 236 */
        "pxor %xmm6, %xmm6\n"
        "movss %xmm6, -0x2bc(%ebp)\n"
        "movl -0x2bc(%ebp), %ecx\n"
        ".Lfacbe8_000ad292:\n"
        "leal (, %edx, 4), %eax\n" /* line 171 */
        "movaps %xmm2, %xmm0\n"
        "mulss -0x24(%ebp, %eax), %xmm0\n"
        "movss -0x244(%ebp), %xmm1\n"
        "mulss -0x30(%ebp, %eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm6\n"
        "ja .Lfacbe8_000ad2d8\n"
        "movss %xmm5, -0x2bc(%ebp)\n"
        "movl -0x2bc(%ebp), %eax\n"
        ".Lfacbe8_000ad2c7:\n"
        "movl %eax, 4(%ebx, %edx, 4)\n" /* line 179 | currentKey */
        "addl $1, %edx\n" /* line 167 */
        "cmpl %edx, 0xc(%ebp)\n" /* dimensions */
        "jne .Lfacbe8_000ad292\n"
        "jmp .Lfacbe8_000ace53\n"
        ".Lfacbe8_000ad2d8:\n"
        "movl %ecx, %eax\n"
        "jmp .Lfacbe8_000ad2c7\n"
    );
}

