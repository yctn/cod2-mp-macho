/* ASM dump from: rb_imagefilter.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_imagefilter.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_vector.h"
 */

extern bool g_LastGlowFilter; /* 0x0 */
extern UINT32 g_TotalFilterPasses; /* 0x0 */

static int RB_GaussianFilterPoints1D(float *tapOffsets, float *tapWeights);
static int RB_GenerateGaussianFilter2D(float radius, int srcWidth, int srcHeight, int dstWidth, int dstHeight, GfxImageFilterPass *filterPass);
static int RB_GenerateGaussianFilterChain(int dstWidth, int dstHeight, int passLimit, GfxImageFilterPass *filterPass);
static GfxRenderTargetId RB_ApplyGlowFilter(GfxRenderTargetId dstRenderTarget);
int RB_GlowFilterImage(float *radius);
int RB_GaussianFilterImage(float radius, GfxRenderTargetId renderTargetId);

/* line 81 */
static __attribute__((naked))
int RB_GaussianFilterPoints1D(float *tapOffsets, float *tapWeights)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 81 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movaps %xmm0, %xmm1\n" /* pixels */
        "movl %ecx, %edi\n" /* tapLimit */
        /* { scope 1 */
        "cvtsi2ssl %eax, %xmm0\n" /* line 97 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 428 | dstRes */
        "movss -0x2c(%ebp), %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll floorf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %eax\n"
        "testb $1, %al\n"
        "movss -0x48(%ebp), %xmm1\n"
        "je .Lf10611c_001061a3\n"
        "pxor %xmm4, %xmm4\n"
        "movss %xmm4, -0x28(%ebp)\n" /* offset */
        "mulss %xmm1, %xmm1\n" /* line 101 */
        "movss 0x2ed63c, %xmm0\n" /* -0.5f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* gaussianExponent */
        "testl %edi, %edi\n" /* line 104 | tapLimit */
        "jg .Lf10611c_001061c3\n"
        ".Lf10611c_0010618d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 125 | tapWeights */
        "movl $0x3f000000, (%eax)\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf10611c_0010619b:\n"
        "addl $0x7c, %esp\n" /* line 141 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf10611c_001061a3:\n"
        "movl $0x3f000000, -0x28(%ebp)\n" /* line 428 | offset */
        "mulss %xmm1, %xmm1\n" /* line 101 */
        "movss 0x2ed63c, %xmm0\n" /* -0.5f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* gaussianExponent */
        "testl %edi, %edi\n" /* line 104 | tapLimit */
        "jle .Lf10611c_0010618d\n"
        ".Lf10611c_001061c3:\n"
        "xorl %ebx, %ebx\n" /* tapIndex */
        "pxor %xmm2, %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* totalWeight */
        "movl $1, %esi\n"
        "jmp .Lf10611c_00106210\n"
        ".Lf10611c_001061d5:\n"
        "mulss %xmm3, %xmm1\n" /* line 119 */
        "mulss -0x1c(%ebp), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movl 8(%ebp), %eax\n" /* line 117 | tapOffsets */
        "movss %xmm1, -2(%edx, %eax)\n" /* dstRes */
        "movss -0x24(%ebp), %xmm0\n" /* line 120 | totalWeight */
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* totalWeight */
        "addl $1, %ebx\n" /* line 104 | tapIndex */
        "addl $2, %esi\n"
        "cmpl %ebx, %edi\n" /* tapIndex, tapLimit */
        "je .Lf10611c_00106300\n"
        ".Lf10611c_00106210:\n"
        "leal (%ebx, %ebx), %eax\n" /* line 106 | tapIndex */
        "cvtsi2ssl %eax, %xmm1\n"
        "addss -0x28(%ebp), %xmm1\n" /* offset */
        "cvtsi2ssl %esi, %xmm2\n" /* line 107 */
        "addss -0x28(%ebp), %xmm2\n" /* offset */
        "movss -0x20(%ebp), %xmm0\n" /* line 108 | gaussianExponent */
        "mulss %xmm1, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll expf\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm3\n"
        "movss -0x58(%ebp), %xmm2\n" /* line 109 */
        "movss -0x20(%ebp), %xmm0\n" /* gaussianExponent */
        "mulss %xmm2, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm3, -0x68(%ebp)\n"
        "calll expf\n"
        "fstps -0x1c(%ebp)\n"
        "testl %ebx, %ebx\n" /* line 110 | tapIndex */
        "movss -0x48(%ebp), %xmm1\n"
        "movss -0x58(%ebp), %xmm2\n"
        "movss -0x68(%ebp), %xmm3\n"
        "jne .Lf10611c_0010629d\n"
        "movss -0x28(%ebp), %xmm4\n" /* offset */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "jne .Lf10611c_0010629d\n"
        "jp .Lf10611c_0010629d\n"
        "mulss 0x2ed5d8, %xmm3\n" /* line 113 | 0.5f */
        ".Lf10611c_0010629d:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 115 */
        "addss %xmm3, %xmm0\n"
        "leal (%esi, %esi), %edx\n" /* line 81 | dstRes */
        "movl 0xc(%ebp), %ecx\n" /* tapWeights */
        "leal (%edx, %ecx), %eax\n" /* dstRes, srcRes */
        "leal -2(%eax), %ecx\n" /* srcRes */
        "movss %xmm0, -2(%eax)\n" /* line 115 */
        "pxor %xmm4, %xmm4\n" /* line 116 */
        "ucomiss %xmm4, %xmm0\n"
        "jne .Lf10611c_001061d5\n"
        "jp .Lf10611c_001061d5\n"
        "addss %xmm2, %xmm1\n" /* line 117 */
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "divss -0x2c(%ebp), %xmm1\n"
        "movl 8(%ebp), %eax\n" /* tapOffsets */
        "movss %xmm1, -2(%edx, %eax)\n" /* dstRes */
        "movss -0x24(%ebp), %xmm0\n" /* line 120 | totalWeight */
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* totalWeight */
        "addl $1, %ebx\n" /* line 104 | tapIndex */
        "addl $2, %esi\n"
        "cmpl %ebx, %edi\n" /* tapIndex, tapLimit */
        "jne .Lf10611c_00106210\n"
        ".Lf10611c_00106300:\n"
        "ucomiss 0x2ed658, %xmm0\n" /* line 123 | 0.0010000000474974513f */
        "jbe .Lf10611c_0010635b\n"
        ".Lf10611c_00106309:\n"
        "movss 0x2ed5d8, %xmm1\n" /* line 131 | 0.5f */
        "divss -0x24(%ebp), %xmm1\n" /* totalWeight */
        "movl %edi, %eax\n" /* line 133 | tapLimit */
        "subl $1, %eax\n"
        "js .Lf10611c_00106354\n"
        "movl 0xc(%ebp), %edx\n" /* line 81 | tapWeights, dstRes */
        "leal (%edx, %eax, 4), %ecx\n" /* dstRes */
        "movl %edi, %eax\n" /* tapLimit, srcRes */
        "movl %edi, %edx\n" /* tapLimit, dstRes */
        "movss 0x2ed738, %xmm2\n" /* 0.009999999776482582f */
        "xorl %ebx, %ebx\n"
        ".Lf10611c_00106331:\n"
        "movaps %xmm1, %xmm0\n" /* line 135 */
        "mulss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "ucomiss %xmm0, %xmm2\n" /* line 136 */
        "cmoval %edx, %eax\n" /* dstRes */
        "subl $4, %ecx\n"
        "subl $1, %edx\n" /* dstRes */
        "cmpl %edx, %ebx\n" /* line 133 | dstRes, tapIndex */
        "jne .Lf10611c_00106331\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 141 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf10611c_00106354:\n"
        "movl %edi, %eax\n" /* line 133 | tapLimit */
        "jmp .Lf10611c_0010619b\n"
        ".Lf10611c_0010635b:\n"
        "jnp .Lf10611c_0010618d\n" /* line 123 */
        "jmp .Lf10611c_00106309\n"
    );
}

/* line 173 */
static __attribute__((naked))
int RB_GenerateGaussianFilter2D(float radius, int srcWidth, int srcHeight, int dstWidth, int dstHeight, GfxImageFilterPass *filterPass)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl %ecx, -0x50(%ebp)\n"
        /* { scope 1 */
        "leal -0x30(%ebp), %eax\n" /* line 183 | tapWeightsX */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %edx\n" /* tapOffsetsX */
        "movl %edx, (%esp)\n"
        "movl $2, %ecx\n"
        "movl -0x50(%ebp), %edx\n"
        "movl -0x48(%ebp), %eax\n"
        "calll RB_GaussianFilterPoints1D\n"
        "leal -0x38(%ebp), %ecx\n" /* line 184 | tapWeightsY */
        "movl %ecx, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* tapOffsetsY */
        "movl %eax, (%esp)\n"
        "movl $2, %ecx\n"
        "movl 8(%ebp), %edx\n" /* dstHeight */
        "movl -0x4c(%ebp), %eax\n"
        "movss -0x44(%ebp), %xmm0\n"
        "calll RB_GaussianFilterPoints1D\n"
        "movl $0, -0x40(%ebp)\n"
        "movss 0x2f3080, %xmm1\n"
        "movl -0x40(%ebp), %eax\n"
        ".Lf106364_001063cc:\n"
        "shll $5, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* filterPass */
        "leal 0x18(%eax, %edx), %ebx\n"
        "movl $1, %esi\n"
        "movl -0x40(%ebp), %eax\n"
        "addl %eax, %eax\n"
        "leal -0x28(%ebp), %ecx\n" /* tapOffsetsY */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "leal -0x38(%ebp), %edi\n" /* tapWeightsY */
        "addl %eax, %edi\n"
        ".Lf106364_001063ed:\n"
        "leal (, %esi, 4), %edx\n" /* line 173 */
        "leal -0x20(%ebp), %ecx\n" /* tapOffsetsX */
        "addl %edx, %ecx\n"
        "movss -4(%ecx), %xmm0\n" /* line 191 */
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 192 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movl $0, 8(%ebx)\n" /* line 193 */
        "leal -0x30(%ebp), %eax\n" /* line 173 | tapWeightsX */
        "leal (%eax, %edx), %edx\n"
        "movss -4(%edx), %xmm0\n" /* line 194 */
        "mulss (%edi), %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n"
        "movl -4(%ecx), %eax\n" /* line 196 */
        "movl %eax, 0x10(%ebx)\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 197 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl $0, 0x18(%ebx)\n" /* line 198 */
        "movss -4(%edx), %xmm0\n" /* line 199 */
        "mulss (%edi), %xmm0\n"
        "movss %xmm0, 0x1c(%ebx)\n"
        "addl $1, %esi\n" /* line 201 */
        "addl $0x20, %ebx\n"
        "cmpl $3, %esi\n" /* line 189 */
        "jne .Lf106364_001063ed\n"
        "movl -0x40(%ebp), %eax\n"
        "addl $2, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "cmpl $4, %eax\n" /* line 187 */
        "jne .Lf106364_001063cc\n"
        "movl 0x195eebc, %eax\n" /* line 76 */
        "movl 0x10cc(%eax), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* filterPass */
        "movl %eax, (%edx)\n"
        "movl $8, 0x14(%edx)\n" /* line 206 */
        "cvtsi2ssl -0x48(%ebp), %xmm0\n" /* line 208 */
        /* { scope 2 */
        "cmpl $1, -0x48(%ebp)\n" /* line 144 */
        "ja .Lf106364_001064f3\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        /* } scope */
        ".Lf106364_00106496:\n"
        "divss %xmm1, %xmm0\n" /* line 208 */
        "movl 0xc(%ebp), %ecx\n" /* filterPass */
        "movss %xmm0, 4(%ecx)\n"
        "cvtsi2ssl -0x4c(%ebp), %xmm1\n" /* line 209 */
        /* { scope 2 */
        "cmpl $1, -0x4c(%ebp)\n" /* line 144 */
        "jbe .Lf106364_0010652c\n"
        ".Lf106364_001064ad:\n"
        "movl $1, %edx\n"
        "movl $0x20, %eax\n"
        ".Lf106364_001064b7:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, -0x4c(%ebp)\n"
        "jbe .Lf106364_00106554\n"
        "subl $1, %eax\n"
        "jne .Lf106364_001064b7\n"
        "testl %edx, %edx\n"
        "js .Lf106364_0010656b\n"
        ".Lf106364_001064cf:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        /* } scope */
        ".Lf106364_001064d3:\n"
        "divss %xmm0, %xmm1\n" /* line 209 */
        "movl 0xc(%ebp), %eax\n" /* filterPass */
        "movss %xmm1, 8(%eax)\n"
        "movl -0x50(%ebp), %edx\n" /* line 214 */
        "movl %edx, 0xc(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 215 | dstHeight */
        "movl %ecx, 0x10(%eax)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 216 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf106364_001064f3:\n"
        "movl $1, %edx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lf106364_001064fd:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, -0x48(%ebp)\n"
        "jbe .Lf106364_00106597\n"
        "subl $1, %eax\n"
        "jne .Lf106364_001064fd\n"
        "testl %edx, %edx\n"
        "js .Lf106364_00106581\n"
        ".Lf106364_00106511:\n"
        "cvtsi2ssl %edx, %xmm1\n"
        /* } scope */
        "divss %xmm1, %xmm0\n" /* line 208 */
        "movl 0xc(%ebp), %ecx\n" /* filterPass */
        "movss %xmm0, 4(%ecx)\n"
        "cvtsi2ssl -0x4c(%ebp), %xmm1\n" /* line 209 */
        /* { scope 2 */
        "cmpl $1, -0x4c(%ebp)\n" /* line 144 */
        "ja .Lf106364_001064ad\n"
        ".Lf106364_0010652c:\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        "divss %xmm0, %xmm1\n" /* line 209 */
        "movl 0xc(%ebp), %eax\n" /* filterPass */
        "movss %xmm1, 8(%eax)\n"
        "movl -0x50(%ebp), %edx\n" /* line 214 */
        "movl %edx, 0xc(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 215 | dstHeight */
        "movl %ecx, 0x10(%eax)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 216 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf106364_00106554:\n"
        "testl %edx, %edx\n" /* line 144 */
        "jns .Lf106364_001064cf\n"
        "shrl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf106364_001064d3\n"
        ".Lf106364_0010656b:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf106364_001064d3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf106364_00106581:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lf106364_00106496\n"
        ".Lf106364_00106597:\n"
        "testl %edx, %edx\n"
        "jns .Lf106364_00106511\n"
        "shrl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lf106364_00106496\n"
    );
}

/* line 220 */
static __attribute__((naked))
int RB_GenerateGaussianFilterChain(int dstWidth, int dstHeight, int passLimit, GfxImageFilterPass *filterPass)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movaps %xmm0, %xmm2\n" /* radiusX */
        "movaps %xmm1, %xmm3\n" /* radiusY */
        "movl %ecx, -0x74(%ebp)\n"
        /* { scope 1: tapOffsets, tapWeights */
        "movl %ecx, -0x20(%ebp)\n" /* line 228 | dstRes */
        "movl 8(%ebp), %ecx\n" /* line 229 | dstHeight */
        "movl %ecx, -0x1c(%ebp)\n"
        "cmpl %eax, -0x74(%ebp)\n" /* line 232 | srcWidth */
        "je .Lf1065ae_00106937\n"
        ".Lf1065ae_001065d5:\n"
        "movaps %xmm3, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "cmpnltss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "andps %xmm1, %xmm0\n"
        "andnps %xmm3, %xmm1\n"
        "orps %xmm0, %xmm1\n"
        "ucomiss 0x2ed894, %xmm1\n" /* line 235 | 1.3895604610443115f */
        "jbe .Lf1065ae_00106819\n"
        "movss 0x2ed894, %xmm1\n" /* 1.3895604610443115f */
        "movss 0x2ed898, %xmm4\n" /* 1.9308782815933228f */
        ".Lf1065ae_0010660e:\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "subss %xmm4, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "cvtsi2ssl -0x74(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "mulss %xmm3, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "sqrtss %xmm3, %xmm3\n"
        "cvtsi2ssl 8(%ebp), %xmm0\n" /* dstHeight */
        "mulss %xmm0, %xmm3\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        "movl 0x10(%ebp), %ecx\n" /* line 240 | filterPass */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* dstHeight */
        "movl %ecx, (%esp)\n"
        "movl -0x74(%ebp), %ecx\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm2, -0x88(%ebp)\n" /* radiusX */
        "movss %xmm3, -0x98(%ebp)\n" /* radiusY */
        "calll RB_GenerateGaussianFilter2D\n"
        "movl $1, -0x70(%ebp)\n" /* passCount */
        "movss -0x98(%ebp), %xmm3\n" /* radiusY */
        "movss -0x88(%ebp), %xmm2\n" /* radiusX */
        ".Lf1065ae_00106687:\n"
        "movl -0x70(%ebp), %edx\n" /* passCount, srcHeight */
        "leal (%edx, %edx, 8), %eax\n" /* srcHeight, srcWidth */
        "leal (%edx, %eax, 2), %eax\n" /* srcHeight, srcWidth */
        "movl 0x10(%ebp), %ecx\n" /* filterPass */
        "leal (%ecx, %eax, 8), %eax\n" /* srcWidth */
        "movl %eax, -0x6c(%ebp)\n" /* srcWidth */
        ".Lf1065ae_00106699:\n"
        "ucomiss 0x2ed89c, %xmm2\n" /* line 244 | 0.3295051157474518f, radiusX */
        "jae .Lf1065ae_001066af\n"
        "ucomiss 0x2ed89c, %xmm3\n" /* 0.3295051157474518f, radiusY */
        "jb .Lf1065ae_0010680b\n"
        ".Lf1065ae_001066af:\n"
        "movaps %xmm2, %xmm0\n" /* line 246 | radiusX */
        "subss %xmm3, %xmm0\n" /* radiusY */
        "andps 0x2f3090, %xmm0\n"
        "ucomiss 0x2ed89c, %xmm0\n" /* 0.3295051157474518f */
        "jae .Lf1065ae_001066e6\n"
        "jp .Lf1065ae_001066e6\n"
        "movaps %xmm2, %xmm0\n" /* line 248 | radiusX */
        "addss %xmm3, %xmm0\n" /* radiusY */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "ucomiss 0x2ed894, %xmm0\n" /* line 249 | 1.3895604610443115f */
        "jp .Lf1065ae_001066e6\n"
        "jbe .Lf1065ae_0010694b\n"
        ".Lf1065ae_001066e6:\n"
        "ucomiss %xmm3, %xmm2\n" /* line 257 | radiusY, radiusX */
        "jbe .Lf1065ae_00106893\n"
        "movss 0x2ed8a0, %xmm0\n" /* line 259 | 6.497750282287598f */
        "ucomiss %xmm2, %xmm0\n" /* radiusX */
        "jbe .Lf1065ae_001068e2\n"
        "movaps %xmm2, %xmm0\n" /* radiusX */
        "pxor %xmm2, %xmm2\n" /* radiusX */
        "xorl %esi, %esi\n" /* passAxis */
        "xorl %eax, %eax\n" /* srcWidth */
        "movl $1, %ebx\n"
        /* { scope 2 */
        ".Lf1065ae_00106710:\n"
        "movl -0x20(%ebp, %eax, 4), %eax\n" /* line 151 */
        "leal -0x60(%ebp), %edx\n" /* tapWeights */
        "movl %edx, 4(%esp)\n"
        "leal -0x40(%ebp), %ecx\n" /* tapOffsets */
        "movl %ecx, (%esp)\n"
        "movl $8, %ecx\n"
        "movl %eax, %edx\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "movss %xmm3, -0x98(%ebp)\n"
        "calll RB_GaussianFilterPoints1D\n"
        /* { scope 3 */
        "movl 0x195eebc, %edx\n" /* line 76 */
        "movl 0x10ac(%edx, %eax, 4), %edx\n"
        "movl -0x6c(%ebp), %ecx\n"
        "movl %edx, (%ecx)\n"
        /* } scope */
        "movl %eax, 0x14(%ecx)\n" /* line 152 | halfTapCount */
        "leal 0x18(%ecx, %esi, 4), %esi\n"
        "leal 0x18(%ecx, %ebx, 4), %ebx\n"
        "movl -0x6c(%ebp), %ecx\n"
        "movl $1, %edi\n"
        "movss -0x98(%ebp), %xmm3\n"
        "movss -0x88(%ebp), %xmm2\n"
        ".Lf1065ae_00106772:\n"
        "leal (, %edi, 4), %eax\n" /* line 155 */
        "movl -0x44(%ebp, %eax), %edx\n"
        "movl %edx, (%esi)\n"
        "movl $0, (%ebx)\n" /* line 156 */
        "movl $0, 0x20(%ecx)\n" /* line 157 */
        "movl -0x64(%ebp, %eax), %eax\n" /* line 158 */
        "movl %eax, 0x24(%ecx)\n"
        "addl $1, %edi\n"
        "addl $0x10, %esi\n"
        "addl $0x10, %ebx\n"
        "addl $0x10, %ecx\n"
        "cmpl $9, %edi\n" /* line 153 */
        "jne .Lf1065ae_00106772\n"
        "movl -0x20(%ebp), %edx\n" /* line 162 | dstRes */
        "cvtsi2ssl %edx, %xmm0\n"
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf1065ae_0010685b\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        /* } scope */
        ".Lf1065ae_001067bc:\n"
        "divss %xmm1, %xmm0\n" /* line 162 */
        "movl -0x6c(%ebp), %eax\n"
        "movss %xmm0, 4(%eax)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 163 */
        "cvtsi2ssl %edx, %xmm0\n"
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf1065ae_00106825\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        /* } scope */
        ".Lf1065ae_001067dc:\n"
        "divss %xmm1, %xmm0\n" /* line 163 */
        "movl -0x6c(%ebp), %edx\n"
        "movss %xmm0, 8(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 168 | dstRes */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 169 */
        "movl %eax, 0x10(%edx)\n"
        /* } scope */
        "addl $1, -0x70(%ebp)\n" /* line 289 | passCount */
        "addl $0x98, %edx\n" /* srcHeight */
        "movl %edx, -0x6c(%ebp)\n" /* srcHeight */
        "cmpl $0x10, -0x70(%ebp)\n" /* line 244 | passCount */
        "jne .Lf1065ae_00106699\n"
        /* } scope */
        ".Lf1065ae_0010680b:\n"
        "movl -0x70(%ebp), %eax\n" /* line 293 | passCount, srcWidth */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tapOffsets, tapWeights */
        ".Lf1065ae_00106819:\n"
        "movaps %xmm1, %xmm4\n" /* line 235 */
        "mulss %xmm1, %xmm4\n"
        "jmp .Lf1065ae_0010660e\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1065ae_00106825:\n"
        "movl $1, %ecx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lf1065ae_0010682f:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lf1065ae_001068cb\n"
        "subl $1, %eax\n"
        "jne .Lf1065ae_0010682f\n"
        "testl %ecx, %ecx\n"
        "js .Lf1065ae_00106848\n"
        ".Lf1065ae_00106842:\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "jmp .Lf1065ae_001067dc\n"
        ".Lf1065ae_00106848:\n"
        "movl %ecx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %ecx\n"
        "orl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lf1065ae_001067dc\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1065ae_0010685b:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lf1065ae_00106865:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lf1065ae_001068b8\n"
        "subl $1, %eax\n"
        "jne .Lf1065ae_00106865\n"
        "testl %ecx, %ecx\n"
        "js .Lf1065ae_0010687d\n"
        ".Lf1065ae_00106874:\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "jmp .Lf1065ae_001067bc\n"
        ".Lf1065ae_0010687d:\n"
        "movl %ecx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %ecx\n"
        "orl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lf1065ae_001067bc\n"
        /* } scope */
        /* } scope */
        ".Lf1065ae_00106893:\n"
        "movss 0x2ed8a0, %xmm0\n" /* line 274 | 6.497750282287598f */
        "ucomiss %xmm3, %xmm0\n" /* radiusY */
        "jb .Lf1065ae_0010690b\n"
        "movaps %xmm3, %xmm0\n" /* radiusY */
        "pxor %xmm3, %xmm3\n" /* radiusY */
        "movl $1, %esi\n" /* passAxis */
        "movl $1, %eax\n" /* srcWidth */
        "xorl %ebx, %ebx\n"
        "jmp .Lf1065ae_00106710\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1065ae_001068b8:\n"
        "testl %ecx, %ecx\n" /* line 144 */
        "jns .Lf1065ae_00106874\n"
        "shrl $1, %ecx\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lf1065ae_001067bc\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1065ae_001068cb:\n"
        "testl %ecx, %ecx\n"
        "jns .Lf1065ae_00106842\n"
        "shrl $1, %ecx\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lf1065ae_001067dc\n"
        /* } scope */
        /* } scope */
        ".Lf1065ae_001068e2:\n"
        "movaps %xmm2, %xmm0\n" /* line 81 */
        "mulss %xmm2, %xmm0\n"
        "subss 0x2ed8a4, %xmm0\n" /* 42.220760345458984f */
        "sqrtss %xmm0, %xmm2\n"
        "movss 0x2ed8a0, %xmm0\n" /* 6.497750282287598f */
        "xorl %esi, %esi\n"
        "xorl %eax, %eax\n"
        "movl $1, %ebx\n"
        "jmp .Lf1065ae_00106710\n"
        ".Lf1065ae_0010690b:\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "subss 0x2ed8a4, %xmm0\n" /* 42.220760345458984f */
        "sqrtss %xmm0, %xmm3\n"
        "movss 0x2ed8a0, %xmm0\n" /* 6.497750282287598f */
        "movl $1, %esi\n"
        "movl $1, %eax\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf1065ae_00106710\n"
        ".Lf1065ae_00106937:\n"
        "cmpl %edx, %ecx\n" /* line 232 | srcHeight */
        "jne .Lf1065ae_001065d5\n"
        "movl $0, -0x70(%ebp)\n" /* passCount */
        "jmp .Lf1065ae_00106687\n"
        ".Lf1065ae_0010694b:\n"
        "movl -0x70(%ebp), %edx\n" /* line 251 | passCount, srcHeight */
        "leal (%edx, %edx, 8), %eax\n" /* srcHeight, srcWidth */
        "leal (%edx, %eax, 2), %eax\n" /* srcHeight, srcWidth */
        "movl 0x10(%ebp), %ecx\n" /* filterPass */
        "leal (%ecx, %eax, 8), %eax\n" /* srcWidth */
        "movl %eax, 4(%esp)\n" /* srcWidth */
        "movl 8(%ebp), %eax\n" /* dstHeight, srcWidth */
        "movl %eax, (%esp)\n" /* srcWidth */
        "movl -0x74(%ebp), %ecx\n"
        "movl %eax, %edx\n" /* srcWidth, srcHeight */
        "movl %ecx, %eax\n" /* srcWidth */
        "calll RB_GenerateGaussianFilter2D\n"
        "addl $1, -0x70(%ebp)\n" /* line 252 | passCount */
        /* } scope */
        "movl -0x70(%ebp), %eax\n" /* line 293 | passCount, srcWidth */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 500 */
static __attribute__((naked))
GfxRenderTargetId RB_ApplyGlowFilter(GfxRenderTargetId dstRenderTarget)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 500 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9fc, %esp\n"
        "movl %eax, %esi\n" /* srcRenderTarget */
        "movl %edx, -0x9c8(%ebp)\n"
        /* { scope 1 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 509 | 0.0f */
        "jp .Lf106982_001069a5\n"
        "je .Lf106982_00106c0f\n"
        ".Lf106982_001069a5:\n"
        "movl 0x195f0c8, %eax\n" /* line 59 */
        "movl 0x3c8(%eax), %eax\n"
        "movl 0x3c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf106982_00106d45\n"
        "cvtsi2ssl %edx, %xmm1\n"
        ".Lf106982_001069bf:\n"
        "mulss %xmm0, %xmm1\n"
        "divss 0x2ed840, %xmm1\n" /* 480.0f */
        "movl 0x195eeec, %eax\n" /* line 60 */
        "movaps %xmm1, %xmm0\n"
        "mulss 0x14(%eax), %xmm0\n"
        "movl $0xb, -0x20(%ebp)\n" /* line 519 */
        "movl $0xc, -0x1c(%ebp)\n" /* line 520 */
        "movl 0x195eed0, %edi\n" /* line 523 */
        "movl -0x9c8(%ebp), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edi, %eax, 4), %eax\n"
        "movl 0x2c3c(%eax), %ebx\n" /* Mask */
        "movl %ebx, -0x9c4(%ebp)\n" /* Mask, width */
        "movl 0x2c40(%eax), %edx\n" /* line 524 */
        "leal (%esi, %esi, 4), %eax\n" /* line 526 | srcRenderTarget */
        "movl 0x2c30(%edi, %eax, 4), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x9c8(%ebp), %eax\n" /* line 527 */
        "movl %eax, -0x24(%ebp)\n"
        "movl $0, -0x9ac(%ebp)\n" /* line 528 | filter */
        "cmpl $2, %esi\n" /* line 530 | srcRenderTarget */
        "je .Lf106982_00106cbd\n"
        "movl %ebx, %ecx\n" /* Mask */
        ".Lf106982_00106a35:\n"
        "movl -0x9ac(%ebp), %ebx\n" /* line 546 | filter, Mask */
        "leal -0x9ac(%ebp), %edi\n" /* filter */
        "leal (%ebx, %ebx, 8), %eax\n" /* Mask */
        "leal (%ebx, %eax, 2), %eax\n" /* Mask */
        "leal 4(%edi, %eax, 8), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x10, %eax\n"
        "subl %ebx, %eax\n" /* Mask */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl %ecx, %eax\n"
        "calll RB_GenerateGaussianFilterChain\n"
        "leal (%ebx, %eax), %edx\n" /* Mask */
        "movl %edx, -0x9ac(%ebp)\n" /* filter */
        "testl %edx, %edx\n" /* line 547 */
        "je .Lf106982_00106c0f\n"
        "movl 0x195f13c, %eax\n" /* line 552 */
        "addl %edx, (%eax)\n"
        /* { scope 2: passIndex */
        "testl %edx, %edx\n" /* line 400 */
        "jle .Lf106982_00106c09\n"
        "movl $0, -0x9c0(%ebp)\n" /* passIndex */
        "movl %edi, -0x9bc(%ebp)\n"
        "movl 0x195f0c8, %eax\n"
        "movl %eax, -0x9cc(%ebp)\n"
        "leal -0x9a8(%ebp), %ebx\n" /* Mask */
        "movl %ebx, -0x9d0(%ebp)\n" /* Mask */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf106982_00106aab:\n"
        "movl -0x9c0(%ebp), %ecx\n" /* line 325 | passIndex */
        "andl $1, %ecx\n"
        "movl -0x9c0(%ebp), %eax\n" /* line 326 | passIndex */
        "testl %eax, %eax\n"
        "jne .Lf106982_00106c37\n"
        "movl -0x28(%ebp), %eax\n" /* line 360 */
        "movl -0x9cc(%ebp), %ebx\n" /* Mask */
        "movl %eax, 0x2e8c(%ebx)\n" /* Mask */
        "leal -1(%edx), %eax\n" /* line 331 */
        "cmpl %eax, -0x9c0(%ebp)\n" /* passIndex */
        "je .Lf106982_00106c6f\n"
        ".Lf106982_00106ae0:\n"
        "movl -0x20(%ebp, %ecx, 4), %eax\n" /* line 334 */
        "movl %eax, (%esp)\n" /* line 336 */
        "calll RB_SetRenderTarget\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl -0x9d0(%ebp), %eax\n" /* line 301 */
        "movl 0x14(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf106982_00106c8b\n"
        ".Lf106982_00106afd:\n"
        "xorl %esi, %esi\n" /* constIndex */
        "movl 0x195f0c8, %ecx\n"
        "addl $0x230, %ecx\n"
        "movl %eax, %ebx\n" /* Mask */
        "addl $0x10, %ebx\n" /* Mask */
        ".Lf106982_00106b10:\n"
        "leal 8(%ebx), %edx\n" /* line 302 | Mask */
        /* { scope 4 */
        "movl 8(%ebx), %eax\n" /* line 456 | Mask */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        "addl $1, %esi\n" /* line 301 | constIndex */
        "addl $0x10, %ebx\n" /* Mask */
        "addl $0x10, %ecx\n"
        "cmpl %esi, %edi\n" /* constIndex */
        "jne .Lf106982_00106b10\n"
        "movl -0x9d0(%ebp), %edx\n"
        /* } scope */
        ".Lf106982_00106b3d:\n"
        "cvtsi2ssl 0xc(%edx), %xmm1\n" /* line 406 */
        "cvtsi2ssl 0x10(%edx), %xmm0\n" /* line 407 */
        "cmpb $0, g_LastGlowFilter\n" /* line 410 */
        "je .Lf106982_00106c22\n"
        "testb $1, g_TotalFilterPasses\n"
        "jne .Lf106982_00106c1c\n"
        "movl -0x9ac(%ebp), %eax\n" /* line 412 | filter */
        "subl $1, %eax\n"
        "cmpl %eax, -0x9c0(%ebp)\n" /* passIndex */
        "je .Lf106982_00106c92\n"
        "movl $0xa, 0x28(%esp)\n" /* line 418 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl -0x9d0(%ebp), %edx\n"
        ".Lf106982_00106b8c:\n"
        "movl 8(%edx), %eax\n" /* line 423 */
        "movl %eax, 0x20(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        ".Lf106982_00106ba2:\n"
        "movl $0, 0x14(%esp)\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x9bc(%ebp), %ebx\n" /* Mask */
        "movl 4(%ebx), %eax\n" /* Mask */
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 428 */
        "addl $1, -0x9c0(%ebp)\n" /* line 400 | passIndex */
        "addl $0x98, -0x9d0(%ebp)\n"
        "movl -0x9ac(%ebp), %edx\n" /* filter */
        "addl $0x98, -0x9bc(%ebp)\n"
        "cmpl %edx, -0x9c0(%ebp)\n" /* passIndex */
        "jl .Lf106982_00106aab\n"
        ".Lf106982_00106c09:\n"
        "movl -0x9c8(%ebp), %esi\n" /* constIndex */
        /* } scope */
        /* } scope */
        ".Lf106982_00106c0f:\n"
        "movl %esi, %eax\n" /* line 560 | srcRenderTarget */
        "addl $0x9fc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf106982_00106c1c:\n"
        "movl -0x9d0(%ebp), %edx\n"
        /* { scope 1 */
        /* { scope 2: passIndex */
        ".Lf106982_00106c22:\n"
        "movl $0xa, 0x28(%esp)\n" /* line 423 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "jmp .Lf106982_00106b8c\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf106982_00106c37:\n"
        "movl $1, %eax\n" /* line 360 */
        "subl %ecx, %eax\n"
        "movl -0x20(%ebp, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl 0x195eed0, %eax\n"
        "movl 0x2c30(%eax), %eax\n"
        "movl -0x9cc(%ebp), %ebx\n" /* Mask */
        "movl %eax, 0x2e8c(%ebx)\n" /* Mask */
        "leal -1(%edx), %eax\n" /* line 331 */
        "cmpl %eax, -0x9c0(%ebp)\n" /* passIndex */
        "jne .Lf106982_00106ae0\n"
        ".Lf106982_00106c6f:\n"
        "movl -0x24(%ebp), %eax\n" /* line 332 */
        "movl %eax, (%esp)\n" /* line 336 */
        "calll RB_SetRenderTarget\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl -0x9d0(%ebp), %eax\n" /* line 301 */
        "movl 0x14(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jg .Lf106982_00106afd\n"
        ".Lf106982_00106c8b:\n"
        "movl %eax, %edx\n"
        "jmp .Lf106982_00106b3d\n"
        /* } scope */
        ".Lf106982_00106c92:\n"
        "movl $0xa, 0x28(%esp)\n" /* line 414 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "jmp .Lf106982_00106ba2\n"
        /* } scope */
        ".Lf106982_00106cbd:\n"
        "movl 0x2c64(%edi), %ecx\n" /* line 533 */
        "cvtsi2ssl %ecx, %xmm3\n"
        /* { scope 2: passIndex */
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf106982_00106d7a\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        /* } scope */
        ".Lf106982_00106cd8:\n"
        "divss %xmm2, %xmm3\n" /* line 533 */
        "movss %xmm3, -0x9a4(%ebp)\n"
        "movl 0x2c68(%edi), %ecx\n" /* line 534 */
        "cvtsi2ssl %ecx, %xmm3\n"
        /* { scope 2: passIndex */
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf106982_00106d5b\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        /* } scope */
        ".Lf106982_00106cfb:\n"
        "divss %xmm2, %xmm3\n" /* line 534 */
        "movss %xmm3, -0x9a0(%ebp)\n"
        "movl -0x9c4(%ebp), %ebx\n" /* line 539 | width, Mask */
        "movl %ebx, -0x99c(%ebp)\n" /* Mask */
        "movl %edx, -0x998(%ebp)\n" /* line 540 */
        "movl $0, -0x994(%ebp)\n" /* line 541 */
        "movl 0x195eebc, %eax\n" /* line 542 */
        "movl 0x10d4(%eax), %eax\n"
        "movl %eax, -0x9a8(%ebp)\n"
        "movl $1, -0x9ac(%ebp)\n" /* line 543 | filter */
        "movl %ebx, %ecx\n" /* Mask */
        "jmp .Lf106982_00106a35\n"
        ".Lf106982_00106d45:\n"
        "movl %edx, %eax\n" /* line 59 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lf106982_001069bf\n"
        /* { scope 2: passIndex */
        ".Lf106982_00106d5b:\n"
        "movl $1, %ebx\n" /* line 144 | Mask */
        "movl $0x20, %eax\n"
        ".Lf106982_00106d65:\n"
        "addl %ebx, %ebx\n" /* Mask */
        "cmpl %ebx, %ecx\n" /* Mask */
        "jbe .Lf106982_00106ddb\n"
        "subl $1, %eax\n"
        "jne .Lf106982_00106d65\n"
        "testl %ebx, %ebx\n" /* Mask */
        "js .Lf106982_00106db2\n"
        ".Lf106982_00106d74:\n"
        "cvtsi2ssl %ebx, %xmm2\n" /* Mask */
        "jmp .Lf106982_00106cfb\n"
        /* } scope */
        /* { scope 2: passIndex */
        ".Lf106982_00106d7a:\n"
        "movl $1, %ebx\n" /* Mask */
        "movl $0x20, %eax\n"
        ".Lf106982_00106d84:\n"
        "addl %ebx, %ebx\n" /* Mask */
        "cmpl %ebx, %ecx\n" /* Mask */
        "jbe .Lf106982_00106dc8\n"
        "subl $1, %eax\n"
        "jne .Lf106982_00106d84\n"
        "testl %ebx, %ebx\n" /* Mask */
        "js .Lf106982_00106d9c\n"
        ".Lf106982_00106d93:\n"
        "cvtsi2ssl %ebx, %xmm2\n" /* Mask */
        "jmp .Lf106982_00106cd8\n"
        ".Lf106982_00106d9c:\n"
        "movl %ebx, %eax\n" /* Mask */
        "shrl $1, %eax\n"
        "andl $1, %ebx\n" /* Mask */
        "orl %ebx, %eax\n" /* Mask */
        "cvtsi2ssl %eax, %xmm2\n"
        "addss %xmm2, %xmm2\n"
        "jmp .Lf106982_00106cd8\n"
        /* } scope */
        /* { scope 2: passIndex */
        ".Lf106982_00106db2:\n"
        "movl %ebx, %eax\n" /* Mask */
        "shrl $1, %eax\n"
        "andl $1, %ebx\n" /* Mask */
        "orl %ebx, %eax\n" /* Mask */
        "cvtsi2ssl %eax, %xmm2\n"
        "addss %xmm2, %xmm2\n"
        "jmp .Lf106982_00106cfb\n"
        /* } scope */
        /* { scope 2: passIndex */
        ".Lf106982_00106dc8:\n"
        "testl %ebx, %ebx\n" /* Mask */
        "jns .Lf106982_00106d93\n"
        "shrl $1, %ebx\n" /* Mask */
        "cvtsi2ssl %ebx, %xmm2\n" /* Mask */
        "addss %xmm2, %xmm2\n"
        "jmp .Lf106982_00106cd8\n"
        /* } scope */
        /* { scope 2: passIndex */
        ".Lf106982_00106ddb:\n"
        "testl %ebx, %ebx\n" /* Mask */
        "jns .Lf106982_00106d74\n"
        "shrl $1, %ebx\n" /* Mask */
        "cvtsi2ssl %ebx, %xmm2\n" /* Mask */
        "addss %xmm2, %xmm2\n"
        "jmp .Lf106982_00106cfb\n"
    );
}

/* line 562 */
__attribute__((naked))
int RB_GlowFilterImage(float *radius)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 562 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* radius */
        /* { scope 1 */
        "movss (%ebx), %xmm2\n" /* line 570 | radius */
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm2\n"
        "jp .Lf106dee_00106e0d\n"
        "je .Lf106dee_00106ead\n"
        ".Lf106dee_00106e0d:\n"
        "movl 0x195eed0, %eax\n" /* line 576 */
        "cvtsi2ssl 0x2cf0(%eax), %xmm0\n"
        "cvtsi2ssl 0x2c64(%eax), %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n" /* line 577 */
        "movss %xmm2, (%ebx)\n" /* radius */
        "leal 4(%ebx), %edi\n" /* line 578 | radius */
        "mulss 4(%ebx), %xmm0\n" /* radius */
        "movss %xmm0, 4(%ebx)\n" /* radius */
        "ucomiss %xmm3, %xmm0\n" /* line 580 */
        "sete %dl\n"
        "setnp %al\n"
        "andb %al, %dl\n"
        "movb %dl, g_LastGlowFilter\n"
        "movss 4(%ebx), %xmm1\n" /* line 582 | radius */
        "ucomiss %xmm3, %xmm1\n"
        "jp .Lf106dee_00106f14\n"
        "jne .Lf106dee_00106f14\n"
        ".Lf106dee_00106e60:\n"
        "movl 0x195f0c8, %esi\n" /* line 591 */
        "movl 0x2e88(%esi), %eax\n"
        "movl $9, %edx\n"
        "movss (%ebx), %xmm0\n" /* radius */
        "calll RB_ApplyGlowFilter\n"
        "movl %eax, %ecx\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 592 */
        "shll $2, %eax\n"
        "addl 0x195eed0, %eax\n"
        "movl 0x2c30(%eax), %eax\n"
        "movl %eax, 0x4d4(%esi)\n"
        "movss (%edi), %xmm1\n" /* line 593 */
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "jne .Lf106dee_00106eb5\n"
        "jp .Lf106dee_00106eb5\n"
        "movl $1, 0x4d0(%esi)\n" /* line 595 */
        /* } scope */
        ".Lf106dee_00106ead:\n"
        "addl $0xc, %esp\n" /* line 607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf106dee_00106eb5:\n"
        "movss (%ebx), %xmm0\n" /* line 600 | radius */
        "mulss %xmm1, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movb $1, g_LastGlowFilter\n" /* line 602 */
        "movl $9, %edx\n" /* line 604 */
        "movl %ecx, %eax\n"
        "movss (%edi), %xmm0\n"
        "calll RB_ApplyGlowFilter\n"
        "movl 0x195f0c8, %edx\n" /* line 605 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl 0x195eed0, %eax\n"
        "movl 0x2c30(%eax), %eax\n"
        "movl %eax, 0x4d8(%edx)\n"
        "movl $2, 0x4d0(%edx)\n" /* line 606 */
        /* } scope */
        "addl $0xc, %esp\n" /* line 607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf106dee_00106f14:\n"
        "movss (%ebx), %xmm0\n" /* line 584 | radius */
        "mulss %xmm1, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm0\n"
        "movl $1, %eax\n" /* line 587 */
        "ucomiss %xmm3, %xmm0\n"
        "cmovnel %edx, %eax\n"
        "cmovpl %edx, %eax\n"
        "movb %al, g_LastGlowFilter\n"
        "jmp .Lf106dee_00106e60\n"
    );
}

/* line 468 */
__attribute__((naked))
int RB_GaussianFilterImage(float radius, GfxRenderTargetId renderTargetId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 468 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9fc, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* renderTargetId */
        /* { scope 1 */
        "movl 0x195f0c8, %eax\n" /* line 59 */
        "movl 0x3c8(%eax), %eax\n"
        "movl 0x3c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf106f42_001071ed\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf106f42_00106f6b:\n"
        "movss 8(%ebp), %xmm1\n" /* radius */
        "mulss %xmm0, %xmm1\n"
        "divss 0x2ed840, %xmm1\n" /* 480.0f */
        "movl 0x195eeec, %ebx\n" /* line 60 */
        "movaps %xmm1, %xmm0\n"
        "mulss 0x14(%ebx), %xmm0\n"
        "movl $0xb, -0x20(%ebp)\n" /* line 483 */
        "movl $0xc, -0x1c(%ebp)\n" /* line 484 */
        "movl 0x195eed0, %edx\n" /* line 487 */
        "leal (%edi, %edi, 4), %eax\n" /* renderTargetId */
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x2c3c(%eax), %ecx\n"
        "movl 0x2c40(%eax), %esi\n" /* line 488 | height */
        "movl 0x2c58(%edx), %eax\n" /* line 489 */
        "movl %eax, -0x28(%ebp)\n"
        "movl %edi, -0x24(%ebp)\n" /* line 490 | renderTargetId */
        "movl 4(%ebx), %edx\n" /* line 491 */
        "leal -0x9ac(%ebp), %edi\n" /* filter, renderTargetId */
        "leal -0x9a8(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* height */
        "movl (%ebx), %eax\n"
        "calll RB_GenerateGaussianFilterChain\n"
        "movl %eax, %edx\n"
        "movl %eax, -0x9ac(%ebp)\n" /* filter */
        /* { scope 2: passIndex */
        "andl $1, %eax\n" /* line 362 */
        "movl %eax, -0x9c4(%ebp)\n"
        "testl %edx, %edx\n" /* line 364 */
        "jle .Lf106f42_00107170\n"
        "movl $0, -0x9c0(%ebp)\n" /* passIndex */
        "movl %edi, -0x9bc(%ebp)\n"
        "movl 0x195f0c8, %ebx\n"
        "movl %ebx, -0x9c8(%ebp)\n"
        "leal -0x9a8(%ebp), %eax\n"
        "movl %eax, -0x9cc(%ebp)\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf106f42_00107022:\n"
        "movl -0x9c0(%ebp), %ecx\n" /* line 325 | passIndex */
        "andl $1, %ecx\n"
        "movl -0x9c0(%ebp), %ebx\n" /* line 326 | passIndex */
        "testl %ebx, %ebx\n"
        "jne .Lf106f42_00107182\n"
        "movl -0x28(%ebp), %eax\n" /* line 360 */
        "movl -0x9c8(%ebp), %ebx\n"
        "movl %eax, 0x2e8c(%ebx)\n"
        "leal -1(%edx), %eax\n" /* line 331 */
        "cmpl %eax, -0x9c0(%ebp)\n" /* passIndex */
        "je .Lf106f42_001071ba\n"
        ".Lf106f42_00107057:\n"
        "movl -0x20(%ebp, %ecx, 4), %eax\n" /* line 334 */
        ".Lf106f42_0010705b:\n"
        "movl %eax, (%esp)\n" /* line 336 */
        "calll RB_SetRenderTarget\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        "movl -0x9cc(%ebp), %eax\n" /* line 301 */
        "movl 0x14(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf106f42_0010717b\n"
        "xorl %esi, %esi\n" /* constIndex */
        "movl 0x195f0c8, %ecx\n"
        "addl $0x230, %ecx\n"
        "movl %eax, %ebx\n"
        "addl $0x10, %ebx\n"
        ".Lf106f42_00107087:\n"
        "leal 8(%ebx), %edx\n" /* line 302 */
        /* { scope 4 */
        "movl 8(%ebx), %eax\n" /* line 456 */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        "addl $1, %esi\n" /* line 301 | constIndex */
        "addl $0x10, %ebx\n"
        "addl $0x10, %ecx\n"
        "cmpl %edi, %esi\n" /* constIndex */
        "jne .Lf106f42_00107087\n"
        "movl -0x9cc(%ebp), %edx\n"
        /* } scope */
        ".Lf106f42_001070b4:\n"
        "cvtsi2ssl 0xc(%edx), %xmm1\n" /* line 370 */
        "cvtsi2ssl 0x10(%edx), %xmm0\n" /* line 371 */
        "movl -0x9c4(%ebp), %ecx\n" /* line 374 */
        "testl %ecx, %ecx\n"
        "jne .Lf106f42_001070e3\n"
        "movl -0x9ac(%ebp), %eax\n" /* filter */
        "subl $1, %eax\n"
        "cmpl %eax, -0x9c0(%ebp)\n" /* passIndex */
        "je .Lf106f42_001071c2\n"
        "movl -0x9cc(%ebp), %edx\n"
        ".Lf106f42_001070e3:\n"
        "movl $0xa, 0x28(%esp)\n" /* line 381 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        ".Lf106f42_00107109:\n"
        "movl $0, 0x14(%esp)\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x9bc(%ebp), %ebx\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 383 */
        "addl $1, -0x9c0(%ebp)\n" /* line 364 | passIndex */
        "addl $0x98, -0x9cc(%ebp)\n"
        "movl -0x9ac(%ebp), %edx\n" /* filter */
        "addl $0x98, -0x9bc(%ebp)\n"
        "cmpl %edx, -0x9c0(%ebp)\n" /* passIndex */
        "jl .Lf106f42_00107022\n"
        /* } scope */
        /* } scope */
        ".Lf106f42_00107170:\n"
        "addl $0x9fc, %esp\n" /* line 498 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf106f42_0010717b:\n"
        "movl %eax, %edx\n"
        "jmp .Lf106f42_001070b4\n"
        /* { scope 1 */
        /* { scope 2: passIndex */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf106f42_00107182:\n"
        "movl $1, %eax\n" /* line 360 */
        "subl %ecx, %eax\n"
        "movl -0x20(%ebp, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl 0x195eed0, %eax\n"
        "movl 0x2c30(%eax), %eax\n"
        "movl -0x9c8(%ebp), %ebx\n"
        "movl %eax, 0x2e8c(%ebx)\n"
        "leal -1(%edx), %eax\n" /* line 331 */
        "cmpl %eax, -0x9c0(%ebp)\n" /* passIndex */
        "jne .Lf106f42_00107057\n"
        ".Lf106f42_001071ba:\n"
        "movl -0x24(%ebp), %eax\n" /* line 332 */
        "jmp .Lf106f42_0010705b\n"
        /* } scope */
        /* } scope */
        ".Lf106f42_001071c2:\n"
        "movl $0xa, 0x28(%esp)\n" /* line 376 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "jmp .Lf106f42_00107109\n"
        /* } scope */
        ".Lf106f42_001071ed:\n"
        "movl %edx, %eax\n" /* line 59 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf106f42_00106f6b\n"
    );
}

