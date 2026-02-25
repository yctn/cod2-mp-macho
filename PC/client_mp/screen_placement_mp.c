/* ASM dump from: screen_placement_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/screen_placement_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static struct ScreenPlacementGlob spGlob; /* 0xf2f580 */

float GetRealWidthFromVirtualWidth(float width);
float GetRealHeightFromVirtualHeight(float height);
float GetVirtualWidthFromRealWidth(float width);
float GetVirtualHeightFromRealHeight(float height);
float CalcScreenX(float *x, int horzAlign);
float CalcScreenY(float *y, int vertAlign);
float CalcSplitScreenTextOffset(FontHandle font, float *y);
float SetScreenScaling(float safeAreaRatioHorizontal, float safeAreaRatioVertical, int viewportX, int viewportY, int viewportWidth, int viewportHeight);
float CalcScreenPlacement(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign);

/* line 141 */
__attribute__((naked))
float GetRealWidthFromVirtualWidth(float width)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 141 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* width */
        "mulss spGlob, %xmm0\n" /* width */
        "movss %xmm0, -4(%ebp)\n" /* line 144 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 147 */
__attribute__((naked))
float GetRealHeightFromVirtualHeight(float height)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 147 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* height */
        "mulss 0xf2f584, %xmm0\n" /* height */
        "movss %xmm0, -4(%ebp)\n" /* line 150 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 153 */
__attribute__((naked))
float GetVirtualWidthFromRealWidth(float width)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 153 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* width */
        "mulss 0xf2f590, %xmm0\n" /* width */
        "movss %xmm0, -4(%ebp)\n" /* line 156 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 159 */
__attribute__((naked))
float GetVirtualHeightFromRealHeight(float height)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 159 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* height */
        "mulss 0xf2f594, %xmm0\n" /* height */
        "movss %xmm0, -4(%ebp)\n" /* line 162 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 165 */
__attribute__((naked))
float CalcScreenX(float *x, int horzAlign)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 165 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* x */
        "movl 0xc(%ebp), %eax\n" /* horzAlign */
        "cmpl $7, %eax\n" /* line 169 */
        "ja .Lf18c7dc_0018c80b\n"
        "jmpl *0x302f60(, %eax, 4)\n"
        "movss (%edx), %xmm0\n" /* line 194 */
        "mulss 0xf2f590, %xmm0\n"
        "addss 0xf2f598, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 197 */
        "retl\n"
        ".Lf18c7dc_0018c80b:\n"
        "movss (%edx), %xmm0\n" /* line 174 */
        "mulss spGlob, %xmm0\n"
        "addss 0xf2f5c4, %xmm0\n"
        "addss 0xf2f598, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 197 */
        "retl\n"
        "movss (%edx), %xmm0\n" /* line 177 */
        "mulss spGlob, %xmm0\n"
        "addss 0xf2f5b4, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 197 */
        "retl\n"
        "movss (%edx), %xmm1\n" /* line 183 */
        "mulss spGlob, %xmm1\n"
        "movss 0xf2f5b4, %xmm0\n"
        "addss 0xf2f5bc, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%edx)\n"
        "popl %ebp\n" /* line 197 */
        "retl\n"
        "movss (%edx), %xmm0\n" /* line 189 */
        "mulss 0xf2f588, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 197 */
        "retl\n"
        "movss (%edx), %xmm0\n" /* line 186 */
        "mulss spGlob, %xmm0\n"
        "addss 0xf2f5bc, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 197 */
        "retl\n"
        "movss (%edx), %xmm1\n" /* line 180 */
        "mulss spGlob, %xmm1\n"
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "mulss 0xf2f5ac, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%edx)\n"
        "popl %ebp\n" /* line 197 */
        "retl\n"
    );
}

/* line 200 */
__attribute__((naked))
float CalcScreenY(float *y, int vertAlign)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 200 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* y */
        "movl 0xc(%ebp), %eax\n" /* vertAlign */
        "cmpl $7, %eax\n" /* line 204 */
        "ja .Lf18c8c8_0018c8ef\n"
        "jmpl *0x302f80(, %eax, 4)\n"
        "movss (%edx), %xmm0\n" /* line 229 */
        "mulss 0xf2f594, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 232 */
        "retl\n"
        ".Lf18c8c8_0018c8ef:\n"
        "movss (%edx), %xmm0\n" /* line 209 */
        "mulss 0xf2f584, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 232 */
        "retl\n"
        "movss (%edx), %xmm0\n" /* line 212 */
        "mulss 0xf2f584, %xmm0\n"
        "addss 0xf2f5b8, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 232 */
        "retl\n"
        "movss (%edx), %xmm1\n" /* line 218 */
        "mulss 0xf2f584, %xmm1\n"
        "movss 0xf2f5b8, %xmm0\n"
        "addss 0xf2f5c0, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%edx)\n"
        "popl %ebp\n" /* line 232 */
        "retl\n"
        "movss (%edx), %xmm0\n" /* line 224 */
        "mulss 0xf2f58c, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 232 */
        "retl\n"
        "movss (%edx), %xmm0\n" /* line 221 */
        "mulss 0xf2f584, %xmm0\n"
        "addss 0xf2f5c0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 232 */
        "retl\n"
        "movss (%edx), %xmm1\n" /* line 215 */
        "mulss 0xf2f584, %xmm1\n"
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "mulss 0xf2f5b0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%edx)\n"
        "popl %ebp\n" /* line 232 */
        "retl\n"
    );
}

/* line 235 */
__attribute__((naked))
float CalcSplitScreenTextOffset(FontHandle font, float *y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 235 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 253 */
        "retl\n"
    );
}

/* line 135 */
__attribute__((naked))
float SetScreenScaling(float safeAreaRatioHorizontal, float safeAreaRatioVertical, int viewportX, int viewportY, int viewportWidth, int viewportHeight)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 135 */
        "movl %esp, %ebp\n"
        "subl $0x1c, %esp\n"
        "cvtsi2ssl 0x1c(%ebp), %xmm0\n" /* line 137 | viewportHeight */
        "movss %xmm0, -0x10(%ebp)\n" /* viewportHeight */
        "cvtsi2ssl 0x18(%ebp), %xmm1\n" /* viewportWidth */
        "movss %xmm1, -0xc(%ebp)\n" /* viewportWidth */
        "cvtsi2ssl 0x14(%ebp), %xmm2\n" /* viewportY */
        "movss %xmm2, -4(%ebp)\n"
        "cvtsi2ssl 0x10(%ebp), %xmm4\n" /* viewportX */
        "movss %xmm4, -8(%ebp)\n"
        /* { scope 1: horzAspectScale, viewportHeight, viewportWidth */
        "movss %xmm1, 0xf2f5ac\n" /* line 30 */
        "movss %xmm0, 0xf2f5b0\n" /* line 31 */
        "mulss 0x2ed814, %xmm0\n" /* line 120 | 1.3333333730697632f */
        "movl 0x195ecac, %eax\n"
        "divss 0x2a0a78(%eax), %xmm0\n"
        "movss %xmm0, -0x18(%ebp)\n" /* adjustedRealWidth */
        "subss %xmm0, %xmm1\n" /* line 121 */
        "movss %xmm1, -0x1c(%ebp)\n" /* horzAspectPixelDiff */
        "movss -0xc(%ebp), %xmm7\n" /* line 122 | viewportWidth */
        "divss %xmm0, %xmm7\n"
        "movss %xmm7, -0x14(%ebp)\n" /* horzAspectScale */
        /* { scope 2 */
        "cvtsi2ssl 0x2a0a64(%eax), %xmm7\n" /* line 82 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss 8(%ebp), %xmm1\n" /* safeAreaRatioHorizontal */
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss %xmm7, %xmm1\n"
        "cvtsi2ssl 0x2a0a68(%eax), %xmm6\n" /* line 83 */
        "subss 0xc(%ebp), %xmm0\n" /* safeAreaRatioVertical */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm6, %xmm0\n"
        "subss %xmm0, %xmm6\n" /* line 85 */
        "subss %xmm1, %xmm7\n"
        "movaps %xmm4, %xmm5\n" /* line 45 */
        "subss %xmm1, %xmm5\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm4, %xmm2\n"
        "cmpnltss %xmm3, %xmm5\n"
        "andps %xmm5, %xmm2\n"
        "andnps %xmm1, %xmm5\n"
        "orps %xmm2, %xmm5\n"
        "movss -4(%ebp), %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "movss -4(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "cmpnltss %xmm3, %xmm4\n"
        "andps %xmm4, %xmm1\n"
        "andnps %xmm0, %xmm4\n"
        "orps %xmm1, %xmm4\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 88 | viewportWidth */
        "addss -8(%ebp), %xmm0\n"
        "movaps %xmm7, %xmm2\n" /* line 45 */
        "subss %xmm0, %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "cmpnltss %xmm3, %xmm2\n"
        "andps %xmm2, %xmm1\n"
        "andnps %xmm7, %xmm2\n"
        "orps %xmm1, %xmm2\n"
        "movss -0x10(%ebp), %xmm0\n" /* line 89 | viewportHeight */
        "addss -4(%ebp), %xmm0\n"
        "movaps %xmm6, %xmm1\n" /* line 45 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm0, %xmm7\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm7\n"
        "andnps %xmm6, %xmm1\n"
        "orps %xmm7, %xmm1\n"
        "subss -8(%ebp), %xmm5\n" /* line 91 */
        "movss %xmm5, 0xf2f5b4\n"
        "subss -4(%ebp), %xmm4\n" /* line 92 */
        "movss %xmm4, 0xf2f5b8\n"
        "subss -8(%ebp), %xmm2\n" /* line 93 */
        "movss %xmm2, 0xf2f5bc\n"
        "subss -4(%ebp), %xmm1\n" /* line 94 */
        "movss %xmm1, 0xf2f5c0\n"
        "movss 0x2ed860, %xmm1\n" /* line 96 | 640.0f */
        "movaps %xmm1, %xmm2\n"
        "divss -0xc(%ebp), %xmm2\n" /* viewportWidth */
        "movss -0x14(%ebp), %xmm0\n" /* horzAspectScale */
        "mulss %xmm5, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, 0xf2f59c\n"
        "movss 0x2ed840, %xmm4\n" /* line 97 | 480.0f */
        "movaps %xmm4, %xmm3\n"
        "divss -0x10(%ebp), %xmm3\n" /* viewportHeight */
        "movaps %xmm3, %xmm0\n"
        "mulss 0xf2f5b8, %xmm0\n"
        "movss %xmm0, 0xf2f5a0\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 98 | horzAspectScale */
        "mulss 0xf2f5bc, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "movss %xmm2, 0xf2f5a4\n"
        "movaps %xmm3, %xmm0\n" /* line 99 */
        "mulss 0xf2f5c0, %xmm0\n"
        "movss %xmm0, 0xf2f5a8\n"
        /* } scope */
        "movss -0x10(%ebp), %xmm2\n" /* line 126 | viewportHeight, y */
        "divss %xmm4, %xmm2\n" /* y */
        /* { scope 2 */
        "movss -0x18(%ebp), %xmm0\n" /* line 30 | adjustedRealWidth */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, spGlob\n"
        "movss %xmm2, 0xf2f584\n" /* line 31 */
        /* } scope */
        "movss -0xc(%ebp), %xmm4\n" /* line 30 | viewportWidth */
        "divss %xmm1, %xmm4\n"
        "movss %xmm4, 0xf2f588\n"
        "movss %xmm2, 0xf2f58c\n" /* line 31 */
        "movaps %xmm1, %xmm0\n" /* line 30 */
        "divss -0x18(%ebp), %xmm0\n" /* adjustedRealWidth */
        "movss %xmm0, 0xf2f590\n"
        "movss %xmm3, 0xf2f594\n" /* line 31 */
        "movss 0x2ed5d8, %xmm7\n" /* line 130 | 0.5f */
        "mulss -0x1c(%ebp), %xmm7\n" /* horzAspectPixelDiff */
        "movss %xmm7, 0xf2f5c4\n"
        "movss -0x18(%ebp), %xmm0\n" /* line 131 | adjustedRealWidth */
        "mulss 0xf2f590, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xf2f598\n"
        /* } scope */
        "leave\n" /* line 138 */
        "retl\n"
    );
}

/* line 285 */
__attribute__((naked))
float CalcScreenPlacement(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* x */
        "movl 0xc(%ebp), %ebx\n" /* y */
        "movl 0x10(%ebp), %ecx\n" /* w */
        "movl 0x14(%ebp), %esi\n" /* h */
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl 0x1c(%ebp), %edi\n" /* vertAlign */
        "cmpl $7, %eax\n" /* line 294 */
        "ja .Lf18cc02_0018ccd8\n"
        "jmpl *0x302fa0(, %eax, 4)\n"
        "movss (%edx), %xmm0\n" /* line 311 */
        "mulss spGlob, %xmm0\n"
        "movss 0xf2f5b4, %xmm1\n"
        "addss 0xf2f5bc, %xmm1\n"
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        ".Lf18cc02_0018cc4e:\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%ecx), %xmm0\n" /* line 312 */
        "mulss spGlob, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        ".Lf18cc02_0018cc66:\n"
        "cmpl $7, %edi\n" /* line 330 | vertAlign */
        "ja .Lf18cc02_0018ccb3\n"
        "jmpl *0x302fc0(, %edi, 4)\n"
        "movss (%ebx), %xmm0\n" /* line 347 | y */
        "mulss 0xf2f584, %xmm0\n"
        "movss 0xf2f5b8, %xmm1\n"
        "addss 0xf2f5c0, %xmm1\n"
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        ".Lf18cc02_0018cc96:\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* y */
        "movss (%esi), %xmm0\n" /* line 348 | h */
        "mulss 0xf2f584, %xmm0\n"
        "movss %xmm0, (%esi)\n" /* h */
        "popl %ebx\n" /* line 365 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18cc02_0018ccb3:\n"
        "movss (%ebx), %xmm0\n" /* line 335 | y */
        "mulss 0xf2f584, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* y */
        "movss (%esi), %xmm0\n" /* line 336 | h */
        "mulss 0xf2f584, %xmm0\n"
        "movss %xmm0, (%esi)\n" /* h */
        "popl %ebx\n" /* line 365 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18cc02_0018ccd8:\n"
        "movss (%edx), %xmm0\n" /* line 299 */
        "mulss spGlob, %xmm0\n"
        "addss 0xf2f5c4, %xmm0\n"
        "addss 0xf2f598, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%ecx), %xmm0\n" /* line 300 */
        "mulss spGlob, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "jmp .Lf18cc02_0018cc66\n"
        "movss (%ebx), %xmm0\n" /* line 339 | y */
        "mulss 0xf2f584, %xmm0\n"
        "addss 0xf2f5b8, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* y */
        "movss (%esi), %xmm0\n" /* line 340 | h */
        "mulss 0xf2f584, %xmm0\n"
        "movss %xmm0, (%esi)\n" /* h */
        "popl %ebx\n" /* line 365 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movss (%edx), %xmm0\n" /* line 325 */
        "mulss 0xf2f590, %xmm0\n"
        "addss 0xf2f598, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%ecx), %xmm0\n" /* line 326 */
        "mulss 0xf2f590, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "jmp .Lf18cc02_0018cc66\n"
        "movss (%edx), %xmm0\n" /* line 319 */
        "mulss 0xf2f588, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%ecx), %xmm0\n" /* line 320 */
        "mulss 0xf2f588, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "jmp .Lf18cc02_0018cc66\n"
        "movss (%edx), %xmm0\n" /* line 315 */
        "mulss spGlob, %xmm0\n"
        "addss 0xf2f5bc, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%ecx), %xmm0\n" /* line 316 */
        "mulss spGlob, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "jmp .Lf18cc02_0018cc66\n"
        "movss (%edx), %xmm0\n" /* line 307 */
        "mulss spGlob, %xmm0\n"
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss 0xf2f5ac, %xmm1\n"
        "jmp .Lf18cc02_0018cc4e\n"
        "movss (%edx), %xmm0\n" /* line 303 */
        "mulss spGlob, %xmm0\n"
        "addss 0xf2f5b4, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss (%ecx), %xmm0\n" /* line 304 */
        "mulss spGlob, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "jmp .Lf18cc02_0018cc66\n"
        "movss (%ebx), %xmm0\n" /* line 361 | y */
        "mulss 0xf2f594, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* y */
        "movss (%esi), %xmm0\n" /* line 362 | h */
        "mulss 0xf2f594, %xmm0\n"
        "movss %xmm0, (%esi)\n" /* h */
        "popl %ebx\n" /* line 365 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movss (%ebx), %xmm0\n" /* line 355 | y */
        "mulss 0xf2f58c, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* y */
        "movss (%esi), %xmm0\n" /* line 356 | h */
        "mulss 0xf2f58c, %xmm0\n"
        "movss %xmm0, (%esi)\n" /* h */
        "popl %ebx\n" /* line 365 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movss (%ebx), %xmm0\n" /* line 351 | y */
        "mulss 0xf2f584, %xmm0\n"
        "addss 0xf2f5c0, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* y */
        "movss (%esi), %xmm0\n" /* line 352 | h */
        "mulss 0xf2f584, %xmm0\n"
        "movss %xmm0, (%esi)\n" /* h */
        "popl %ebx\n" /* line 365 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movss (%ebx), %xmm0\n" /* line 343 | y */
        "mulss 0xf2f584, %xmm0\n"
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss 0xf2f5b0, %xmm1\n"
        "jmp .Lf18cc02_0018cc96\n"
    );
}

