/* ASM dump from: ui_atoms.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui_mp/ui_atoms.cpp */

#include "common_types.h"
#include "imports.h"

float UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle hMaterial);
float UI_DrawLoadBar(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle material);
float UI_FillRectPhysical(float x, float y, float width, float height, const vec_t *color);
float UI_FillRect(float x, float y, float width, float height, int horzAlign, int vertAlign, const vec_t *color);

/* line 56 */
__attribute__((naked))
float UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle hMaterial)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movss 0x10(%ebp), %xmm2\n" /* w */
        "movss 0x14(%ebp), %xmm1\n" /* h */
        /* { scope 1 */
        "xorl %eax, %eax\n" /* line 63 */
        "ucomiss 0x2ed5e8, %xmm2\n" /* 0.0f */
        "jp .Lf1c9728_001c9747\n"
        "jb .Lf1c9728_001c97bd\n"
        ".Lf1c9728_001c9747:\n"
        "movl %eax, %ebx\n" /* s0 */
        "movl $0x3f800000, %ecx\n"
        "movl %ecx, %edx\n"
        ".Lf1c9728_001c9750:\n"
        "movl %eax, -0xc(%ebp)\n" /* line 75 */
        "movss -0xc(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1c9728_001c97b0\n"
        "movl %eax, %esi\n" /* t0 */
        ".Lf1c9728_001c975f:\n"
        "movl 0x24(%ebp), %eax\n" /* line 87 | hMaterial */
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* color */
        "movl %eax, 0x28(%esp)\n"
        "movl %edx, 0x24(%esp)\n"
        "movl %ecx, 0x20(%esp)\n"
        "movl %esi, 0x1c(%esp)\n" /* t0 */
        "movl %ebx, 0x18(%esp)\n" /* s0 */
        "movl 0x1c(%ebp), %eax\n" /* vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss %xmm2, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 88 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c9728_001c97b0:\n"
        "xorps 0x3033a0, %xmm1\n" /* line 77 */
        "movl %edx, %esi\n" /* t0 */
        "movl %eax, %edx\n"
        "jmp .Lf1c9728_001c975f\n"
        ".Lf1c9728_001c97bd:\n"
        "xorps 0x3033a0, %xmm2\n" /* line 65 */
        "movl $0x3f800000, %ebx\n" /* s0 */
        "movl %ebx, %edx\n" /* s0 */
        "movl %eax, %ecx\n"
        "jmp .Lf1c9728_001c9750\n"
    );
}

/* line 91 */
__attribute__((naked))
float UI_DrawLoadBar(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 91 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1 */
        "movl $0x2a7364, (%esp)\n" /* line 104 */
        "calll Dvar_GetInt\n"
        "movl %eax, %ebx\n" /* expectedHunk */
        "pxor %xmm1, %xmm1\n" /* line 105 */
        "testl %eax, %eax\n"
        "jle .Lf1c97d0_001c980d\n"
        "calll Hunk_Used\n" /* line 107 */
        "cvtsi2ssl %eax, %xmm1\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* expectedHunk */
        "divss %xmm0, %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 108 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1c97d0_001c980d:\n"
        "movl 0x24(%ebp), %eax\n" /* line 127 | material */
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* color */
        "movl %eax, 0x28(%esp)\n"
        "movl $0x3f800000, 0x24(%esp)\n"
        "movss %xmm1, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* h */
        "movl %eax, 0xc(%esp)\n"
        "mulss 0x10(%ebp), %xmm1\n" /* w */
        "movss %xmm1, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 128 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 138 */
__attribute__((naked))
float UI_FillRectPhysical(float x, float y, float width, float height, const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl 0x195f5d8, %eax\n" /* line 140 */
        "movl 0x20(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1c9872_001c98d1\n"
        "movl %eax, 0x24(%esp)\n" /* line 141 */
        "movl 0x18(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* height */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* width */
        "movss %xmm0, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPicPhysical\n"
        ".Lf1c9872_001c98d1:\n"
        "leave\n" /* line 142 */
        "retl\n"
    );
}

/* line 152 */
__attribute__((naked))
float UI_FillRect(float x, float y, float width, float height, int horzAlign, int vertAlign, const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 152 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl 0x195f5d8, %eax\n" /* line 154 */
        "movl 0x20(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1c98d4_001c9941\n"
        "movl %eax, 0x2c(%esp)\n" /* line 155 */
        "movl 0x20(%ebp), %eax\n" /* color */
        "movl %eax, 0x28(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* height */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* width */
        "movss %xmm0, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        ".Lf1c98d4_001c9941:\n"
        "leave\n" /* line 156 */
        "retl\n"
    );
}

