/* ASM dump from: r_screenshot.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_screenshot.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacMemory.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static int lastNumber; /* 0xc96c18 */
static vec3_t cubemapShotAxis[7][3]; /* 0x2f2720 */
static int cubeShotGlob; /* 0xc96c00 */

void R_BeginCubemapShot(const int pixelWidthHeight, const int pixelBorder);
static Bool R_GetFrontBufferData(int height, int bytesPerPixel, byte *buffer);
void R_EndCubemapShot(const CubemapShot shotIndex);
static void R_UpsamplePixelData(int newSize, int bytesPerPixel, byte *src, byte *dst);
static void R_DownsamplePixelData(int oldSize, int newSize, int bytesPerPixel, byte *src, byte *dst);
static byte * R_TakeResampledScreenshot(int width, int height, int headerSize);
void R_LevelShot(void);
void R_SaveCubemapShot(const char *filename, const CubemapShot shotIndex, const float n0, const float n1);
void R_LightingFromCubemapShots(const vec_t *baseColor);
void R_ScreenshotCommand(GfxScreenshotType type);

/* line 837 */
__attribute__((naked))
void R_BeginCubemapShot(const int pixelWidthHeight, const int pixelBorder)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 837 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0x195eed0, %ebx\n" /* line 844 */
        "movl 8(%ebp), %eax\n" /* pixelWidthHeight */
        "movw %ax, 0x2d38(%ebx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 845 | pixelBorder */
        "movw %ax, 0x2d3a(%ebx)\n"
        "movl $0, (%esp)\n" /* line 826 */
        "calll RB_SetRenderTarget\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfe8f4c_000e8f80:\n"
        "movl 8(%ebx), %eax\n" /* line 827 */
        "movl (%eax), %edx\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0x3f800000, 0x14(%esp)\n"
        "movl $0xffff00ff, 0x10(%esp)\n"
        "movl $7, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xac(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfe8f4c_000e8f80\n"
        "addl $0x20, %esp\n" /* line 848 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 217 */
static __attribute__((naked))
Bool R_GetFrontBufferData(int height, int bytesPerPixel, byte *buffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 217 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %ecx, %edi\n" /* width */
        /* { scope 1 */
        "leal (, %ecx, 4), %eax\n" /* line 221 | x */
        "movl %eax, -0x34(%ebp)\n" /* x, rowBytes */
        "imull 8(%ebp), %eax\n" /* line 98 | height */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll calloc\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl $0xfffff, (%esp)\n" /* line 226 */
        "calll glPushAttrib\n"
        "movl $0xffffffff, (%esp)\n" /* line 227 */
        "calll glPushClientAttrib\n"
        "movl $0x8620, (%esp)\n" /* line 229 */
        "calll glDisable\n"
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 230 | x */
        "je .Lfe8fcc_000e925c\n"
        "calll MacDisplay_GetCardType\n" /* line 178 */
        "subl $1, %eax\n" /* line 235 | x */
        "je .Lfe8fcc_000e92df\n"
        ".Lfe8fcc_000e9038:\n"
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 239 */
        "cmpl $0xffff01ff, %eax\n" /* x */
        "jbe .Lfe8fcc_000e9050\n"
        "movl $0x8804, (%esp)\n" /* line 241 */
        "calll glDisable\n"
        ".Lfe8fcc_000e9050:\n"
        "movl $0xb50, (%esp)\n" /* line 243 */
        "calll glDisable\n"
        "movl $0xbe2, (%esp)\n" /* line 244 */
        "calll glDisable\n"
        "movl $0xbc0, (%esp)\n" /* line 245 */
        "calll glDisable\n"
        "movl $0xb71, (%esp)\n" /* line 246 */
        "calll glDisable\n"
        "movl $0xbd0, (%esp)\n" /* line 247 */
        "calll glDisable\n"
        "movl $1, 0xc(%esp)\n" /* line 248 */
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glColorMask\n"
        "movl $1, (%esp)\n" /* line 249 */
        "calll glDepthMask\n"
        "movl $0xb44, (%esp)\n" /* line 250 */
        "calll glDisable\n"
        "movl $0xb60, (%esp)\n" /* line 251 */
        "calll glDisable\n"
        "movl $0x84c0, (%esp)\n" /* line 252 */
        "calll glActiveTextureARB\n"
        "movl $0xb90, (%esp)\n" /* line 253 */
        "calll glDisable\n"
        "leal -0x1c(%ebp), %eax\n" /* line 255 | NumTexUnits, x */
        "movl %eax, 4(%esp)\n" /* x */
        "movl $0x84e2, (%esp)\n"
        "calll glGetIntegerv\n"
        /* { scope 2 */
        "movl -0x1c(%ebp), %ebx\n" /* line 256 | NumTexUnits, i */
        "testl %ebx, %ebx\n" /* i */
        "jle .Lfe8fcc_000e914e\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lfe8fcc_000e9108:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 258 | i, x */
        "movl %eax, (%esp)\n" /* x */
        "calll glActiveTextureARB\n"
        "movl $0xde1, (%esp)\n" /* line 259 */
        "calll glDisable\n"
        "movl $0x84f5, (%esp)\n" /* line 260 */
        "calll glDisable\n"
        "movl $0x806f, (%esp)\n" /* line 261 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 262 */
        "calll glDisable\n"
        "addl $1, %ebx\n" /* line 256 | i */
        "cmpl -0x1c(%ebp), %ebx\n" /* NumTexUnits, i */
        "jl .Lfe8fcc_000e9108\n"
        /* } scope */
        ".Lfe8fcc_000e914e:\n"
        "leal -0x24(%ebp), %eax\n" /* line 265 | ScreenHeight, x */
        "movl %eax, 4(%esp)\n" /* x */
        "leal -0x20(%ebp), %eax\n" /* ScreenWidth, x */
        "movl %eax, (%esp)\n" /* x */
        "calll MacDisplay_GetCurrentDimensions\n"
        "movl $0x404, (%esp)\n" /* line 269 */
        "calll glReadBuffer\n"
        "movl -0x38(%ebp), %ebx\n" /* line 274 | i */
        "movl %ebx, 0x18(%esp)\n" /* i */
        "movl $0x8035, 0x14(%esp)\n"
        "movl $0x80e1, 0x10(%esp)\n"
        "movl 8(%ebp), %eax\n" /* height, x */
        "movl %eax, 0xc(%esp)\n" /* x */
        "movl %edi, 8(%esp)\n" /* width */
        "movl -0x24(%ebp), %eax\n" /* ScreenHeight, x */
        "subl 8(%ebp), %eax\n" /* height, x */
        "movl %eax, 4(%esp)\n" /* x */
        "movl $0, (%esp)\n"
        "calll glReadPixels\n"
        "calll glPopClientAttrib\n" /* line 278 */
        "calll glPopAttrib\n" /* line 279 */
        "calll glGetError\n" /* line 281 */
        "testl %eax, %eax\n" /* line 282 */
        "jne .Lfe8fcc_000e9245\n"
        "cmpl $3, 0xc(%ebp)\n" /* line 290 | bytesPerPixel */
        "je .Lfe8fcc_000e9279\n"
        "cmpl $4, 0xc(%ebp)\n" /* line 307 | bytesPerPixel */
        "jne .Lfe8fcc_000e9245\n"
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 309 | height */
        "testl %ecx, %ecx\n"
        "jle .Lfe8fcc_000e922b\n"
        "movl 8(%ebp), %ebx\n" /* height, col */
        "leal -4(, %ebx, 4), %ebx\n" /* col */
        "movl %ebx, -0x2c(%ebp)\n" /* col */
        "xorl %esi, %esi\n" /* row */
        /* { scope 3 */
        ".Lfe8fcc_000e91e1:\n"
        "movl -0x34(%ebp), %eax\n" /* line 311 | rowBytes */
        "imull %esi, %eax\n" /* row */
        "movl -0x38(%ebp), %ecx\n" /* srcPixel */
        "addl %eax, %ecx\n" /* srcPixel */
        "movl -0x2c(%ebp), %eax\n" /* line 312 */
        "imull %edi, %eax\n" /* width */
        "movl 0x10(%ebp), %ebx\n" /* buffer, col */
        "leal (%eax, %ebx), %edx\n" /* dstPixel */
        /* { scope 4 */
        "testl %edi, %edi\n" /* line 314 | width */
        "jle .Lfe8fcc_000e921f\n"
        "xorl %ebx, %ebx\n" /* col */
        ".Lfe8fcc_000e91fe:\n"
        "movzbl 3(%ecx), %eax\n" /* line 316 */
        "movb %al, (%edx)\n"
        "movzbl 2(%ecx), %eax\n" /* line 317 */
        "movb %al, 1(%edx)\n"
        "movzbl 1(%ecx), %eax\n" /* line 318 */
        "movb %al, 2(%edx)\n"
        "addl $4, %edx\n" /* line 319 */
        "addl $4, %ecx\n" /* line 320 */
        "addl $1, %ebx\n" /* line 314 | col */
        "cmpl %edi, %ebx\n" /* width, col */
        "jne .Lfe8fcc_000e91fe\n"
        /* } scope */
        /* } scope */
        ".Lfe8fcc_000e921f:\n"
        "addl $1, %esi\n" /* line 309 | row */
        "subl $4, -0x2c(%ebp)\n"
        "cmpl 8(%ebp), %esi\n" /* height, row */
        "jne .Lfe8fcc_000e91e1\n"
        /* } scope */
        ".Lfe8fcc_000e922b:\n"
        "movl $1, %ebx\n" /* line 103 */
        ".Lfe8fcc_000e9230:\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll free\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 450 | col */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe8fcc_000e9245:\n"
        "xorl %ebx, %ebx\n" /* line 103 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll free\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 450 | col */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe8fcc_000e925c:\n"
        "movl $0x86de, (%esp)\n" /* line 232 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 233 */
        "calll glDisable\n"
        "jmp .Lfe8fcc_000e9038\n"
        /* { scope 2 */
        ".Lfe8fcc_000e9279:\n"
        "movl 8(%ebp), %edx\n" /* line 292 | height, y */
        "testl %edx, %edx\n" /* y */
        "jle .Lfe8fcc_000e922b\n"
        "movl 8(%ebp), %eax\n" /* height */
        "leal -3(%eax, %eax, 2), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "xorl %esi, %esi\n" /* row */
        /* { scope 3 */
        ".Lfe8fcc_000e928c:\n"
        "movl -0x34(%ebp), %eax\n" /* line 294 | rowBytes */
        "imull %esi, %eax\n" /* row */
        "movl -0x38(%ebp), %ecx\n" /* srcPixel */
        "addl %eax, %ecx\n" /* srcPixel */
        "movl -0x30(%ebp), %eax\n" /* line 295 */
        "imull %edi, %eax\n" /* width */
        "movl 0x10(%ebp), %edx\n" /* buffer, dstPixel */
        "addl %eax, %edx\n" /* dstPixel */
        /* { scope 4 */
        "testl %edi, %edi\n" /* line 297 | width */
        "jle .Lfe8fcc_000e92c9\n"
        "xorl %ebx, %ebx\n" /* col */
        ".Lfe8fcc_000e92a8:\n"
        "movzbl 3(%ecx), %eax\n" /* line 299 */
        "movb %al, (%edx)\n"
        "movzbl 2(%ecx), %eax\n" /* line 300 */
        "movb %al, 1(%edx)\n"
        "movzbl 1(%ecx), %eax\n" /* line 301 */
        "movb %al, 2(%edx)\n"
        "addl $3, %edx\n" /* line 302 */
        "addl $4, %ecx\n" /* line 303 */
        "addl $1, %ebx\n" /* line 297 | col */
        "cmpl %ebx, %edi\n" /* col, width */
        "jne .Lfe8fcc_000e92a8\n"
        /* } scope */
        /* } scope */
        ".Lfe8fcc_000e92c9:\n"
        "addl $1, %esi\n" /* line 292 | row */
        "subl $3, -0x30(%ebp)\n"
        "cmpl 8(%ebp), %esi\n" /* height, row */
        "jne .Lfe8fcc_000e928c\n"
        /* } scope */
        "movl $1, %ebx\n" /* line 103 */
        "jmp .Lfe8fcc_000e9230\n"
        ".Lfe8fcc_000e92df:\n"
        "movl $0x8200, (%esp)\n" /* line 237 */
        "calll glDisable\n"
        "jmp .Lfe8fcc_000e9038\n"
        "movl %eax, %ebx\n" /* x */
        "movl -0x38(%ebp), %eax\n" /* line 103 */
        "movl %eax, (%esp)\n"
        "calll free\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 851 */
__attribute__((naked))
void R_EndCubemapShot(const CubemapShot shotIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 851 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x195eed0, %edx\n" /* line 791 */
        "movzwl 0x2d38(%edx), %eax\n"
        "imull %eax, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* bufferSizeInBytes */
        "movl %eax, (%esp)\n" /* line 793 */
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, %edi\n"
        "movl 8(%ebp), %eax\n" /* shotIndex */
        "movl %edi, 0xc96bfc(, %eax, 4)\n"
        /* { scope 1: swapBuffer */
        "movl 0x195eed0, %eax\n" /* line 706 */
        "movzwl 0x2d38(%eax), %ecx\n"
        "movzwl 0x2d3a(%eax), %eax\n"
        "movl %edi, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %eax, %edx\n"
        "calll R_GetFrontBufferData\n"
        /* { scope 2 */
        "movl 0x195eed0, %eax\n" /* line 683 */
        "testw $0xfffe, 0x2d38(%eax)\n"
        "je .Lfe9306_000e93df\n"
        "xorl %esi, %esi\n" /* rowIndex */
        "movl 0x195eed0, %eax\n"
        ".Lfe9306_000e937c:\n"
        "movzwl 0x2d38(%eax), %edx\n" /* line 685 */
        "testl %edx, %edx\n"
        "jle .Lfe9306_000e93c5\n"
        "xorl %ebx, %ebx\n" /* colIndex */
        ".Lfe9306_000e9389:\n"
        "movl %esi, %ecx\n" /* line 690 | rowIndex */
        "imull %edx, %ecx\n"
        "leal (%ebx, %ecx), %ecx\n" /* colIndex */
        "leal (%edi, %ecx, 4), %ecx\n"
        "movl (%ecx), %eax\n" /* line 606 */
        "movl %eax, -0x1c(%ebp)\n" /* swapBuffer */
        "movl %edx, %eax\n" /* line 691 */
        "subl %esi, %eax\n" /* rowIndex */
        "subl $1, %eax\n"
        "imull %eax, %edx\n"
        "leal (%ebx, %edx), %eax\n" /* colIndex */
        "leal (%edi, %eax, 4), %eax\n"
        "movl (%eax), %edx\n" /* line 606 */
        "movl %edx, (%ecx)\n"
        "movl -0x1c(%ebp), %edx\n" /* swapBuffer */
        "movl %edx, (%eax)\n"
        "addl $1, %ebx\n" /* line 685 | colIndex */
        "movl 0x195eed0, %eax\n"
        "movzwl 0x2d38(%eax), %edx\n"
        "cmpl %edx, %ebx\n" /* colIndex */
        "jl .Lfe9306_000e9389\n"
        ".Lfe9306_000e93c5:\n"
        "movl %eax, %edx\n"
        "addl $1, %esi\n" /* line 683 | rowIndex */
        "movzwl 0x2d38(%eax), %eax\n"
        "shrw $1, %ax\n"
        "movzwl %ax, %eax\n"
        "cmpl %eax, %esi\n" /* rowIndex */
        "jge .Lfe9306_000e93df\n"
        "movl %edx, %eax\n"
        "jmp .Lfe9306_000e937c\n"
        /* } scope */
        ".Lfe9306_000e93df:\n"
        "movl 0x195f17c, %eax\n" /* line 710 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %esi\n" /* rowIndex */
        "testl %esi, %esi\n" /* rowIndex */
        "jle .Lfe9306_000e93f8\n"
        "movl 0x195eeec, %eax\n"
        "cmpb $0, 0x28(%eax)\n"
        "jne .Lfe9306_000e940c\n"
        /* } scope */
        ".Lfe9306_000e93f8:\n"
        "movl $0, (%esp)\n" /* line 833 */
        "calll RB_SetRenderTarget\n"
        "addl $0x3c, %esp\n" /* line 855 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: swapBuffer */
        ".Lfe9306_000e940c:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 711 | bufferSizeInBytes */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll R_GammaCorrect\n"
        /* } scope */
        "movl $0, (%esp)\n" /* line 833 */
        "calll RB_SetRenderTarget\n"
        "addl $0x3c, %esp\n" /* line 855 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 112 */
static __attribute__((naked))
void R_UpsamplePixelData(int newSize, int bytesPerPixel, byte *src, byte *dst)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 112 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %ebx\n" /* oldSize */
        "movl %edx, -0x38(%ebp)\n"
        /* { scope 1 */
        "imull 8(%ebp), %ecx\n" /* line 123 | bytesPerPixel */
        "movl %ecx, -0x28(%ebp)\n" /* nextSample */
        "leal -1(%eax), %eax\n" /* line 124 */
        "imull %ecx, %eax\n"
        "addl 0xc(%ebp), %eax\n" /* src */
        "movl %eax, -0x24(%ebp)\n" /* currSrc */
        "movl %edx, %ecx\n" /* line 125 */
        "subl $1, %ecx\n"
        "movl -0x28(%ebp), %edi\n" /* nextSample */
        "imull %ecx, %edi\n"
        "addl 0x10(%ebp), %edi\n" /* dst */
        "movl %eax, %edx\n" /* line 126 */
        "movzbl (%eax), %eax\n"
        "movl -0x28(%ebp), %esi\n" /* nextSample, forwardWeight */
        "movb %al, (%edx, %esi)\n"
        "movl -0x24(%ebp), %edx\n" /* line 127 | currSrc */
        "addl %esi, %edx\n" /* forwardWeight */
        "movl -0x24(%ebp), %esi\n" /* currSrc, forwardWeight */
        "movzbl 1(%esi), %eax\n" /* forwardWeight */
        "movb %al, 1(%edx)\n"
        "movzbl 2(%esi), %eax\n" /* line 128 | forwardWeight */
        "movb %al, 2(%edx)\n"
        "movl -0x38(%ebp), %esi\n" /* line 130 | forwardWeight */
        "subl %ebx, %esi\n" /* oldSize, forwardWeight */
        "movl -0x38(%ebp), %eax\n" /* line 131 */
        "addl %ebx, %eax\n" /* oldSize */
        "movl %eax, -0x30(%ebp)\n" /* backwardWeight */
        "cvtsi2ssl -0x38(%ebp), %xmm0\n" /* line 132 */
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n" /* colorScale */
        "testl %ecx, %ecx\n" /* line 134 */
        "js .Lfe9430_000e9666\n"
        "addl %ebx, %ebx\n" /* oldSize */
        "movl %ebx, -0x20(%ebp)\n" /* oldSize */
        "movl -0x38(%ebp), %eax\n" /* line 154 */
        "addl %eax, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n"
        "jmp .Lfe9430_000e9576\n"
        ".Lfe9430_000e94c4:\n"
        "movl -0x30(%ebp), %eax\n" /* line 144 | backwardWeight */
        "leal (%esi, %eax), %ebx\n" /* forwardWeight, oldSize */
        "movzbl (%edx), %eax\n" /* line 428 */
        "imull %ebx, %eax\n" /* oldSize */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x48(%ebp)\n"
        "cvttss2si -0x48(%ebp), %eax\n"
        "movb %al, (%edi)\n"
        "movl 0xc(%ebp), %ecx\n" /* src */
        "movzbl 1(%ecx), %eax\n"
        "imull %ebx, %eax\n" /* oldSize */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x4c(%ebp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "movb %al, 1(%edi)\n"
        "movl 0xc(%ebp), %edx\n" /* src */
        "movzbl 2(%edx), %eax\n"
        "imull %eax, %ebx\n" /* oldSize */
        "cvtsi2ssl %ebx, %xmm0\n" /* oldSize */
        "mulss -0x2c(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x50(%ebp)\n"
        "cvttss2si -0x50(%ebp), %eax\n"
        "movb %al, 2(%edi)\n"
        "subl -0x28(%ebp), %edi\n" /* line 148 | nextSample */
        "movl -0x20(%ebp), %ecx\n" /* line 150 */
        "addl %ecx, -0x30(%ebp)\n" /* backwardWeight */
        "subl %ecx, %esi\n" /* line 152 | forwardWeight */
        "js .Lfe9430_000e9648\n"
        ".Lfe9430_000e9566:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 156 */
        "movl -0x1c(%ebp), %edx\n" /* line 134 */
        "cmpl %edx, -0x38(%ebp)\n"
        "je .Lfe9430_000e9666\n"
        ".Lfe9430_000e9576:\n"
        "movl 0xc(%ebp), %edx\n" /* line 136 | src */
        "cmpl %edx, -0x24(%ebp)\n" /* currSrc */
        "jb .Lfe9430_000e94c4\n"
        "movl -0x24(%ebp), %ecx\n" /* line 428 | currSrc */
        "movzbl (%ecx), %edx\n"
        "imull -0x30(%ebp), %edx\n" /* backwardWeight */
        "movl -0x28(%ebp), %ebx\n" /* nextSample, oldSize */
        "movzbl (%ecx, %ebx), %eax\n"
        "imull %esi, %eax\n" /* forwardWeight */
        "addl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x3c(%ebp)\n"
        "cvttss2si -0x3c(%ebp), %eax\n"
        "movb %al, (%edi)\n"
        "movl -0x24(%ebp), %ebx\n" /* line 139 | currSrc, oldSize */
        "addl -0x28(%ebp), %ebx\n" /* nextSample, oldSize */
        "movl -0x24(%ebp), %eax\n" /* line 428 | currSrc */
        "movzbl 1(%eax), %edx\n"
        "imull -0x30(%ebp), %edx\n" /* backwardWeight */
        "movzbl 1(%ebx), %eax\n" /* oldSize */
        "imull %esi, %eax\n" /* forwardWeight */
        "addl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x40(%ebp)\n"
        "cvttss2si -0x40(%ebp), %eax\n"
        "movb %al, 1(%edi)\n"
        "movl -0x24(%ebp), %ecx\n" /* currSrc */
        "movzbl 2(%ecx), %edx\n"
        "imull -0x30(%ebp), %edx\n" /* backwardWeight */
        "movzbl 2(%ebx), %eax\n" /* oldSize */
        "imull %esi, %eax\n" /* forwardWeight */
        "addl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x44(%ebp)\n"
        "cvttss2si -0x44(%ebp), %eax\n"
        "movb %al, 2(%edi)\n"
        "subl -0x28(%ebp), %edi\n" /* line 148 | nextSample */
        "movl -0x20(%ebp), %ecx\n" /* line 150 */
        "addl %ecx, -0x30(%ebp)\n" /* backwardWeight */
        "subl %ecx, %esi\n" /* line 152 | forwardWeight */
        "jns .Lfe9430_000e9566\n"
        ".Lfe9430_000e9648:\n"
        "movl -0x34(%ebp), %ebx\n" /* line 154 | oldSize */
        "subl %ebx, -0x30(%ebp)\n" /* oldSize, backwardWeight */
        "addl %ebx, %esi\n" /* line 155 | oldSize, forwardWeight */
        "movl -0x28(%ebp), %eax\n" /* line 156 | nextSample */
        "subl %eax, -0x24(%ebp)\n" /* currSrc */
        "addl $1, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 134 */
        "cmpl %edx, -0x38(%ebp)\n"
        "jne .Lfe9430_000e9576\n"
        /* } scope */
        ".Lfe9430_000e9666:\n"
        "addl $0x5c, %esp\n" /* line 159 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 67 */
static __attribute__((naked))
void R_DownsamplePixelData(int oldSize, int newSize, int bytesPerPixel, byte *src, byte *dst)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 67 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* src */
        /* { scope 1 */
        "cvtsi2ssl %eax, %xmm0\n" /* line 77 */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* colorScale */
        "movl %ecx, %eax\n" /* line 78 | stride */
        "imull 8(%ebp), %eax\n" /* bytesPerPixel */
        "movl %eax, -0x24(%ebp)\n" /* nextSample */
        "testl %edx, %edx\n" /* line 81 */
        "jle .Lfe966e_000e97d5\n"
        "movl %edx, -0x30(%ebp)\n" /* residual */
        "movl $0, -0x2c(%ebp)\n" /* column */
        "movl %edx, %ecx\n" /* stride */
        "jmp .Lfe966e_000e976a\n"
        ".Lfe966e_000e96b7:\n"
        "movl -0x38(%ebp), %eax\n" /* line 97 */
        "subl -0x30(%ebp), %eax\n" /* residual */
        "movzbl 1(%edi), %ebx\n" /* line 98 | src */
        "imull %eax, %ebx\n"
        "addl %ecx, %ebx\n" /* stride */
        "movzbl 2(%edi), %esi\n" /* line 99 | src */
        "imull %eax, %esi\n"
        "addl -0x20(%ebp), %esi\n"
        "movzbl (%edi), %edx\n" /* line 428 | src */
        "imull %edx, %eax\n"
        "addl -0x1c(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x3c(%ebp)\n"
        "cvttss2si -0x3c(%ebp), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* dst */
        "movb %al, (%edx)\n"
        "cvtsi2ssl %ebx, %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x40(%ebp)\n"
        "cvttss2si -0x40(%ebp), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* dst */
        "movb %al, 1(%edx)\n"
        "cvtsi2ssl %esi, %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n" /* colorScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x44(%ebp)\n"
        "cvttss2si -0x44(%ebp), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* dst */
        "movb %al, 2(%edx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 103 | nextSample */
        "addl %eax, %edx\n"
        "movl %edx, 0x10(%ebp)\n" /* dst */
        "addl $1, -0x2c(%ebp)\n" /* line 81 | column */
        "movl -0x2c(%ebp), %edx\n" /* column */
        "cmpl %edx, -0x38(%ebp)\n"
        "je .Lfe966e_000e97d5\n"
        "movl -0x30(%ebp), %ecx\n" /* residual, stride */
        ".Lfe966e_000e976a:\n"
        "movzbl (%edi), %eax\n" /* line 84 | src */
        "imull -0x30(%ebp), %eax\n" /* residual */
        "movl %eax, -0x1c(%ebp)\n"
        "movzbl 1(%edi), %eax\n" /* line 85 | src */
        "imull %eax, %ecx\n" /* stride */
        "movzbl 2(%edi), %eax\n" /* line 86 | src */
        "imull -0x30(%ebp), %eax\n" /* residual */
        "movl %eax, -0x20(%ebp)\n"
        "addl -0x24(%ebp), %edi\n" /* line 87 | nextSample, src */
        "movl -0x30(%ebp), %edx\n" /* line 88 | residual */
        "addl -0x38(%ebp), %edx\n"
        "movl %edx, %eax\n"
        "subl -0x34(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* residual */
        "testl %eax, %eax\n"
        "jg .Lfe966e_000e96b7\n"
        ".Lfe966e_000e979f:\n"
        "movzbl (%edi), %eax\n" /* line 90 | src */
        "imull -0x38(%ebp), %eax\n"
        "addl %eax, -0x1c(%ebp)\n"
        "movzbl 1(%edi), %eax\n" /* line 91 | src */
        "imull -0x38(%ebp), %eax\n"
        "addl %eax, %ecx\n" /* stride */
        "movzbl 2(%edi), %eax\n" /* line 92 | src */
        "imull -0x38(%ebp), %eax\n"
        "addl %eax, -0x20(%ebp)\n"
        "addl -0x24(%ebp), %edi\n" /* line 94 | nextSample, src */
        "addl -0x38(%ebp), %edx\n" /* line 88 */
        "movl %edx, %eax\n"
        "subl -0x34(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* residual */
        "testl %eax, %eax\n"
        "jle .Lfe966e_000e979f\n"
        "jmp .Lfe966e_000e96b7\n"
        /* } scope */
        ".Lfe966e_000e97d5:\n"
        "addl $0x4c, %esp\n" /* line 105 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 453 */
static __attribute__((naked))
byte * R_TakeResampledScreenshot(int width, int height, int headerSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 453 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl %ecx, %edi\n" /* bytesPerPixel */
        "movl 8(%ebp), %esi\n" /* headerSize */
        /* { scope 1: oldHeight, oldWidth */
        "movl 0x195eeec, %ebx\n" /* line 459 | dst */
        "movl (%ebx), %eax\n" /* dst */
        "cmpl %eax, -0x48(%ebp)\n" /* line 154 */
        "cmovnsl -0x48(%ebp), %eax\n"
        "movl 4(%ebx), %edx\n" /* line 460 | dst */
        "cmpl %edx, -0x4c(%ebp)\n" /* line 154 */
        "cmovnsl -0x4c(%ebp), %edx\n"
        "imull %edx, %eax\n" /* line 461 */
        "imull %ecx, %eax\n"
        "addl %esi, %eax\n" /* headerSize */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %edx\n"
        "calll *0x14(%edx)\n"
        "movl %eax, -0x44(%ebp)\n" /* buffer */
        "movl %eax, 8(%esp)\n" /* line 463 */
        "movl %edi, 4(%esp)\n" /* bytesPerPixel */
        "movl 4(%ebx), %eax\n" /* dst */
        "movl %eax, (%esp)\n"
        "movl (%ebx), %ecx\n" /* dst */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll R_GetFrontBufferData\n"
        "testb %al, %al\n"
        "je .Lfe97de_000e99ec\n"
        "addl -0x44(%ebp), %esi\n" /* line 469 | buffer, headerSize */
        "movl %esi, -0x1c(%ebp)\n" /* headerSize */
        "movl 4(%ebx), %edx\n" /* dst */
        "movl %edx, -0x40(%ebp)\n" /* oldHeight */
        "movl (%ebx), %ebx\n" /* dst */
        "movl %ebx, -0x3c(%ebp)\n" /* dst, oldWidth */
        /* { scope 2: src */
        /* { scope 3 */
        "cmpl %ebx, -0x48(%ebp)\n" /* line 169 | dst */
        "jge .Lfe97de_000e9886\n"
        "movl -0x40(%ebp), %eax\n" /* line 173 | oldHeight */
        "testl %eax, %eax\n"
        "jg .Lfe97de_000e9998\n"
        ".Lfe97de_000e9864:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 192 | oldHeight */
        "cmpl %ecx, -0x4c(%ebp)\n"
        "jge .Lfe97de_000e9900\n"
        ".Lfe97de_000e9870:\n"
        "movl -0x48(%ebp), %eax\n" /* line 196 */
        "testl %eax, %eax\n"
        "jg .Lfe97de_000e995b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfe97de_000e987b:\n"
        "movl -0x44(%ebp), %eax\n" /* line 471 | buffer */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: oldHeight, oldWidth */
        /* { scope 2: src */
        /* { scope 3 */
        ".Lfe97de_000e9886:\n"
        "jle .Lfe97de_000e9864\n" /* line 180 */
        "movl -0x40(%ebp), %eax\n" /* line 182 | oldHeight */
        "subl $1, %eax\n"
        "movl -0x3c(%ebp), %edx\n" /* oldWidth */
        "imull %eax, %edx\n"
        "imull %edi, %edx\n"
        "movl -0x1c(%ebp), %esi\n"
        "addl %edx, %esi\n"
        "movl -0x48(%ebp), %edx\n" /* line 183 */
        "imull %eax, %edx\n"
        "imull %edi, %edx\n"
        "movl -0x1c(%ebp), %ebx\n" /* dst */
        "addl %edx, %ebx\n" /* dst */
        "testl %eax, %eax\n" /* line 184 */
        "js .Lfe97de_000e9864\n"
        "movl -0x3c(%ebp), %ecx\n" /* oldWidth */
        "imull %edi, %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl -0x48(%ebp), %eax\n"
        "imull %edi, %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl $0, -0x20(%ebp)\n"
        ".Lfe97de_000e98c7:\n"
        "movl %ebx, 8(%esp)\n" /* line 186 | dst */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl $1, %ecx\n"
        "movl -0x48(%ebp), %edx\n"
        "movl -0x3c(%ebp), %eax\n" /* oldWidth */
        "calll R_UpsamplePixelData\n"
        "subl -0x2c(%ebp), %esi\n" /* line 187 */
        "subl -0x28(%ebp), %ebx\n" /* line 188 | dst */
        "addl $1, -0x20(%ebp)\n"
        "movl -0x20(%ebp), %edx\n" /* line 184 */
        "cmpl %edx, -0x40(%ebp)\n" /* oldHeight */
        "jne .Lfe97de_000e98c7\n"
        "movl -0x40(%ebp), %ecx\n" /* line 192 | oldHeight */
        "cmpl %ecx, -0x4c(%ebp)\n"
        "jl .Lfe97de_000e9870\n"
        ".Lfe97de_000e9900:\n"
        "jle .Lfe97de_000e987b\n" /* line 203 */
        "movl -0x48(%ebp), %edx\n" /* line 205 */
        "subl $1, %edx\n"
        "movl %edi, %eax\n"
        "imull %edx, %eax\n"
        "movl -0x1c(%ebp), %esi\n"
        "addl %eax, %esi\n"
        "testl %edx, %edx\n" /* line 207 */
        "js .Lfe97de_000e987b\n"
        "movl %esi, %ebx\n" /* dst */
        "movl $0, -0x24(%ebp)\n"
        ".Lfe97de_000e9927:\n"
        "movl %esi, 8(%esp)\n" /* line 209 */
        "movl %ebx, 4(%esp)\n" /* dst */
        "movl %edi, (%esp)\n"
        "movl -0x48(%ebp), %ecx\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl -0x40(%ebp), %eax\n" /* oldHeight */
        "calll R_UpsamplePixelData\n"
        "subl %edi, %ebx\n" /* line 210 | dst */
        "subl %edi, %esi\n" /* line 211 */
        "addl $1, -0x24(%ebp)\n"
        "movl -0x24(%ebp), %edx\n" /* line 207 */
        "cmpl %edx, -0x48(%ebp)\n"
        "jne .Lfe97de_000e9927\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x44(%ebp), %eax\n" /* line 471 | buffer */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: oldHeight, oldWidth */
        /* { scope 2: src */
        /* { scope 3 */
        ".Lfe97de_000e995b:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 196 */
        "xorl %ebx, %ebx\n" /* dst */
        "movl %esi, %eax\n"
        "jmp .Lfe97de_000e9967\n"
        ".Lfe97de_000e9964:\n"
        "movl -0x1c(%ebp), %eax\n"
        ".Lfe97de_000e9967:\n"
        "movl %eax, 8(%esp)\n" /* line 198 */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl -0x48(%ebp), %ecx\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl -0x40(%ebp), %eax\n" /* oldHeight */
        "calll R_DownsamplePixelData\n"
        "addl %edi, %esi\n" /* line 199 */
        "addl %edi, -0x1c(%ebp)\n" /* line 200 */
        "addl $1, %ebx\n" /* line 196 | dst */
        "cmpl %ebx, -0x48(%ebp)\n" /* dst */
        "jne .Lfe97de_000e9964\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x44(%ebp), %eax\n" /* line 471 | buffer */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: oldHeight, oldWidth */
        /* { scope 2: src */
        /* { scope 3 */
        ".Lfe97de_000e9998:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 173 | oldWidth */
        "imull %edi, %ecx\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movl -0x48(%ebp), %eax\n"
        "imull %edi, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* src */
        "movl %edx, %esi\n"
        "xorl %ebx, %ebx\n" /* dst */
        "movl %edx, %eax\n"
        "jmp .Lfe97de_000e99bb\n"
        ".Lfe97de_000e99b8:\n"
        "movl -0x38(%ebp), %eax\n" /* src */
        ".Lfe97de_000e99bb:\n"
        "movl %esi, 8(%esp)\n" /* line 175 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl $1, %ecx\n"
        "movl -0x48(%ebp), %edx\n"
        "movl -0x3c(%ebp), %eax\n" /* oldWidth */
        "calll R_DownsamplePixelData\n"
        "movl -0x34(%ebp), %edx\n" /* line 176 */
        "addl %edx, -0x38(%ebp)\n" /* src */
        "addl -0x30(%ebp), %esi\n" /* line 177 */
        "addl $1, %ebx\n" /* line 173 | dst */
        "cmpl %ebx, -0x40(%ebp)\n" /* dst, oldHeight */
        "jne .Lfe97de_000e99b8\n"
        "jmp .Lfe97de_000e9864\n"
        /* } scope */
        /* } scope */
        ".Lfe97de_000e99ec:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 465 | buffer */
        "movl %ecx, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "movl $0, -0x44(%ebp)\n" /* buffer */
        "jmp .Lfe97de_000e987b\n"
    );
}

/* line 512 */
__attribute__((naked))
void R_LevelShot(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 512 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1 */
        "movl 0x195eebc, %eax\n" /* line 518 */
        "movl 0x109c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfe9a08_000e9ad7\n"
        "movl 4(%eax), %eax\n" /* line 520 */
        "movl %eax, 8(%esp)\n"
        "movl $0x2255f4, 4(%esp)\n" /* "levelshots/%s.tga" */
        "leal -0x118(%ebp), %edi\n" /* checkname */
        "movl %edi, (%esp)\n"
        "calll sprintf\n"
        ".Lfe9a08_000e9a44:\n"
        "movl $0x12, (%esp)\n" /* line 527 */
        "movl $3, %ecx\n"
        "movl $0x80, %edx\n"
        "movl $0x80, %eax\n"
        "calll R_TakeResampledScreenshot\n"
        "movl %eax, %esi\n" /* buffer */
        "testl %eax, %eax\n" /* line 528 */
        "je .Lfe9a08_000e9acc\n"
        "movl $0, (%eax)\n" /* line 531 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movw $0, 0x10(%eax)\n"
        "movb $2, 2(%eax)\n" /* line 532 */
        "movb $0x80, 0xc(%eax)\n" /* line 533 */
        "movb $0x80, 0xe(%eax)\n" /* line 534 */
        "movb $0x18, 0x10(%eax)\n" /* line 535 */
        "movl 0x195eee0, %ebx\n" /* line 536 */
        "movl $0xc012, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x140(%ebx)\n"
        "movl %esi, (%esp)\n" /* line 538 | buffer */
        "calll *0x18(%ebx)\n"
        "movl %edi, 8(%esp)\n" /* line 540 */
        "movl $0x225614, 4(%esp)\n" /* "Wrote %s
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        /* } scope */
        ".Lfe9a08_000e9acc:\n"
        "addl $0x11c, %esp\n" /* line 542 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe9a08_000e9ad7:\n"
        "movl $0x225608, 8(%esp)\n" /* line 524 */
        "movl $0x2255f4, 4(%esp)\n" /* "levelshots/%s.tga" */
        "leal -0x118(%ebp), %edi\n" /* checkname */
        "movl %edi, (%esp)\n"
        "calll sprintf\n"
        "jmp .Lfe9a08_000e9a44\n"
    );
}

/* line 858 */
__attribute__((naked))
void R_SaveCubemapShot(const char *filename, const CubemapShot shotIndex, const float n0, const float n1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 858 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: srcBuffer, targa */
        "movl 0xc(%ebp), %eax\n" /* line 807 | shotIndex */
        "subl $1, %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* imgIndex */
        "movl 0x195eed0, %ebx\n" /* line 809 | colIndex */
        "movzwl 0x2d38(%ebx), %eax\n" /* colIndex */
        "imull %eax, %eax\n"
        "leal 0x12(, %eax, 4), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* fileSize */
        "movl %eax, (%esp)\n" /* line 810 */
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, -0x34(%ebp)\n" /* targa */
        "movzwl 0x2d38(%ebx), %edx\n" /* line 813 | colIndex, res */
        /* { scope 2: rowIndex */
        "movl $0, (%eax)\n" /* line 722 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movw $0, 0x10(%eax)\n"
        "movb $2, 2(%eax)\n" /* line 726 */
        "movb %dl, 0xc(%eax)\n" /* line 727 */
        "movl %edx, %eax\n" /* line 728 */
        "sarl $8, %eax\n"
        "movl -0x34(%ebp), %ecx\n" /* targa */
        "movb %al, 0xd(%ecx)\n"
        "movb %dl, 0xe(%ecx)\n" /* line 729 */
        "movb %al, 0xf(%ecx)\n" /* line 730 */
        "movb $0x20, 0x10(%ecx)\n" /* line 731 */
        "movl -0x40(%ebp), %eax\n" /* imgIndex */
        "movl cubeShotGlob(, %eax, 4), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* srcBuffer */
        /* } scope */
        /* { scope 2: rowIndex */
        /* { scope 3: dir */
        "movzwl 0x2d38(%ebx), %eax\n" /* line 745 | colIndex */
        "testl %eax, %eax\n"
        "jg .Lfe9afa_000e9d83\n"
        "movl %ebx, %esi\n" /* colIndex */
        /* } scope */
        /* } scope */
        /* { scope 2: rowIndex */
        ".Lfe9afa_000e9b96:\n"
        "movzwl 0x2d38(%esi), %eax\n" /* line 771 */
        "testl %eax, %eax\n"
        "jle .Lfe9afa_000e9d42\n"
        "movl %eax, %ebx\n" /* line 773 | colIndex */
        "movl $0, -0x30(%ebp)\n" /* rowIndex */
        ".Lfe9afa_000e9bae:\n"
        "cvtsi2ssl -0x30(%ebp), %xmm0\n" /* rowIndex */
        "movss %xmm0, -0x2c(%ebp)\n"
        "xorl %edi, %edi\n" /* rowIndex */
        /* { scope 3: dir */
        /* { scope 4 */
        ".Lfe9afa_000e9bba:\n"
        "cvtsi2ssl %ebx, %xmm2\n" /* line 661 */
        "movaps %xmm2, %xmm1\n" /* scale */
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f, scale */
        "movl 0xc(%ebp), %ecx\n" /* shotIndex */
        "leal (%ecx, %ecx, 8), %eax\n"
        "shll $2, %eax\n"
        "leal cubemapShotAxis(%eax), %edx\n" /* v */
        /* { scope 5 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss cubemapShotAxis(%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%edx), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "leal 0xc(%eax), %edx\n" /* line 662 */
        "leal cubemapShotAxis(%edx), %ecx\n" /* dir */
        "mulss 0x2ed63c, %xmm2\n" /* -0.5f */
        "cvtsi2ssl %edi, %xmm1\n" /* scale */
        "addss %xmm2, %xmm1\n" /* scale */
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f, scale */
        /* { scope 5 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss cubemapShotAxis(%edx), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* dir */
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%ecx), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%ecx), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "addl $0x18, %eax\n" /* line 663 */
        "leal cubemapShotAxis(%eax), %edx\n" /* dir */
        "movss -0x2c(%ebp), %xmm1\n" /* scale */
        "addss %xmm2, %xmm1\n" /* scale */
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f, scale */
        /* { scope 5 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss cubemapShotAxis(%eax), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* dir */
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%edx), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%edx), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "leal -0x24(%ebp), %eax\n" /* line 664 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 666 */
        "movl %eax, 8(%esp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* n1 */
        "movss %xmm0, 4(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* n0 */
        "movss %xmm0, (%esp)\n"
        "calll FresnelTerm\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        /* } scope */
        /* } scope */
        "imull -0x30(%ebp), %ebx\n" /* line 777 | rowIndex, colIndex */
        "leal (%edi, %ebx), %ebx\n" /* colIndex */
        "mulss 0x2ed5d4, %xmm0\n" /* line 428 | 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x44(%ebp)\n"
        "cvttss2si -0x44(%ebp), %eax\n"
        "movl -0x34(%ebp), %edx\n" /* targa */
        "movb %al, 0x15(%edx, %ebx, 4)\n"
        "addl $1, %edi\n" /* line 773 | rowIndex */
        "movl 0x195eed0, %esi\n"
        "movzwl 0x2d38(%esi), %ebx\n" /* colIndex */
        "cmpl %ebx, %edi\n" /* colIndex, rowIndex */
        "jl .Lfe9afa_000e9bba\n"
        "movl %ebx, %eax\n" /* colIndex */
        "addl $1, -0x30(%ebp)\n" /* line 771 | rowIndex */
        "cmpl %eax, -0x30(%ebp)\n" /* rowIndex */
        "jge .Lfe9afa_000e9d42\n"
        ".Lfe9afa_000e9d2f:\n"
        "movl %eax, %ebx\n" /* line 773 | colIndex */
        "testl %eax, %eax\n"
        "jg .Lfe9afa_000e9bae\n"
        "addl $1, -0x30(%ebp)\n" /* line 771 | rowIndex */
        "cmpl %eax, -0x30(%ebp)\n" /* rowIndex */
        "jl .Lfe9afa_000e9d2f\n"
        /* } scope */
        ".Lfe9afa_000e9d42:\n"
        "movl 0x195eee0, %ebx\n" /* line 817 | colIndex */
        "movl -0x3c(%ebp), %eax\n" /* fileSize */
        "movl %eax, 8(%esp)\n"
        "movl -0x34(%ebp), %edx\n" /* targa */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll *0x140(%ebx)\n" /* colIndex */
        "movl -0x34(%ebp), %ecx\n" /* line 819 | targa */
        "movl %ecx, (%esp)\n"
        "calll *0x18(%ebx)\n" /* colIndex */
        "movl -0x40(%ebp), %edx\n" /* line 820 | imgIndex */
        "movl cubeShotGlob(, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x18(%ebx)\n" /* colIndex */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 861 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: srcBuffer, targa */
        /* { scope 2: rowIndex */
        /* { scope 3: dir */
        ".Lfe9afa_000e9d83:\n"
        "xorl %edi, %edi\n" /* line 747 | rowIndex */
        "movl 0x195eed0, %esi\n"
        ".Lfe9afa_000e9d8b:\n"
        "xorl %ebx, %ebx\n" /* colIndex */
        ".Lfe9afa_000e9d8d:\n"
        "imull %edi, %eax\n" /* line 749 | rowIndex */
        "leal (%ebx, %eax), %eax\n" /* colIndex */
        "shll $2, %eax\n"
        "movl -0x34(%ebp), %edx\n" /* line 752 | targa */
        "leal 0x12(%eax, %edx), %ecx\n"
        "addl -0x38(%ebp), %eax\n" /* srcBuffer */
        "movzbl 2(%eax), %edx\n"
        "movb %dl, 2(%ecx)\n"
        "movzbl 1(%eax), %edx\n" /* line 753 */
        "movb %dl, 1(%ecx)\n"
        "movzbl (%eax), %edx\n" /* line 754 */
        "movb %dl, (%ecx)\n"
        "movzbl 3(%eax), %eax\n" /* line 755 */
        "movb %al, 3(%ecx)\n"
        "addl $1, %ebx\n" /* line 747 | colIndex */
        "movzwl 0x2d38(%esi), %eax\n"
        "cmpl %ebx, %eax\n" /* colIndex */
        "jg .Lfe9afa_000e9d8d\n"
        "movl %eax, %edx\n"
        ".Lfe9afa_000e9dca:\n"
        "addl $1, %edi\n" /* line 745 | rowIndex */
        "cmpl %edx, %edi\n" /* rowIndex */
        "jge .Lfe9afa_000e9b96\n"
        "movl %edx, %eax\n" /* line 747 */
        "testl %edx, %edx\n"
        "jle .Lfe9afa_000e9dca\n"
        "jmp .Lfe9afa_000e9d8b\n"
    );
}

/* line 962 */
__attribute__((naked))
void R_LightingFromCubemapShots(const vec_t *baseColor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 962 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10c, %esp\n"
        /* { scope 1: height, x, y, dir */
        "movl 0x195eed0, %esi\n" /* line 967 | x */
        "movzwl 0x2d38(%esi), %ebx\n" /* x, pixelsPerFace */
        "imull %ebx, %ebx\n" /* pixelsPerFace */
        "leal (%ebx, %ebx, 8), %eax\n" /* line 968 | pixelsPerFace */
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, -0x48(%ebp)\n" /* linearColors */
        "leal (%ebx, %ebx, 2), %ebx\n" /* line 969 | pixelsPerFace */
        "shll $2, %ebx\n" /* pixelsPerFace */
        "addl %ebx, %eax\n" /* pixelsPerFace */
        "movl %eax, -0x44(%ebp)\n"
        "leal (%ebx, %eax), %eax\n" /* line 970 | pixelsPerFace */
        "movl %eax, -0x40(%ebp)\n"
        "leal (%ebx, %eax), %eax\n" /* line 971 | pixelsPerFace */
        "movl %eax, -0x3c(%ebp)\n"
        "leal (%ebx, %eax), %eax\n" /* line 972 | pixelsPerFace */
        "movl %eax, -0x38(%ebp)\n"
        "addl %eax, %ebx\n" /* line 973 | pixelsPerFace */
        "movl %ebx, -0x34(%ebp)\n" /* pixelsPerFace */
        "movzwl 0x2d38(%esi), %esi\n" /* line 975 | x */
        "movl %esi, -0xa8(%ebp)\n" /* x, height */
        "movl $1, -0x64(%ebp)\n"
        "movl $cubeShotGlob, -0x60(%ebp)\n"
        /* { scope 2: x, y, pixelIndex, faceIndex, ... */
        /* { scope 3: y, sourceDir, sampleCount */
        ".Lfe9dde_000e9e4b:\n"
        "movl -0xa8(%ebp), %ecx\n" /* line 948 | height */
        "testl %ecx, %ecx\n"
        "jle .Lfe9dde_000e9fb7\n"
        "movl $0, -0x9c(%ebp)\n" /* pixelIndex */
        "movl $0, -0xa0(%ebp)\n" /* y */
        ".Lfe9dde_000e9e6d:\n"
        "movl -0x9c(%ebp), %edx\n" /* line 962 | pixelIndex */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl %edx, %edi\n"
        "shll $2, %edi\n"
        "movl $0, -0xa4(%ebp)\n" /* x */
        ".Lfe9dde_000e9e8b:\n"
        "movl -0x64(%ebp), %eax\n"
        "leal -0x48(%ebp, %eax, 4), %ebx\n" /* start */
        "movl -4(%ebx), %esi\n" /* line 952 | start, x */
        "movl -0x60(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movzbl 2(%edi, %eax), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl $0xa0000000, 8(%esp)\n"
        "movl $0x40019999, 0xc(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll pow\n"
        "fstpl -0xb0(%ebp)\n"
        "cvtsd2ss -0xb0(%ebp), %xmm0\n"
        "movl -0x68(%ebp), %eax\n"
        "movss %xmm0, (%eax, %esi)\n"
        "movl -4(%ebx), %esi\n" /* line 953 | start, x */
        "movl -0x60(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movzbl 1(%edi, %eax), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl $0xa0000000, 8(%esp)\n"
        "movl $0x40019999, 0xc(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll pow\n"
        "fstpl -0xb8(%ebp)\n"
        "cvtsd2ss -0xb8(%ebp), %xmm0\n"
        "movl -0x68(%ebp), %eax\n"
        "movss %xmm0, 4(%eax, %esi)\n"
        "movl -4(%ebx), %ebx\n" /* line 954 | start */
        "movl -0x60(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movzbl (%edi, %eax), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl $0xa0000000, 8(%esp)\n"
        "movl $0x40019999, 0xc(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll pow\n"
        "fstpl -0xc0(%ebp)\n"
        "cvtsd2ss -0xc0(%ebp), %xmm0\n"
        "movl -0x68(%ebp), %eax\n"
        "movss %xmm0, 8(%eax, %ebx)\n"
        "addl $1, -0xa4(%ebp)\n" /* line 950 | x */
        "addl $0xc, %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "addl $4, %edi\n"
        "movl -0xa4(%ebp), %eax\n" /* x */
        "cmpl %eax, -0xa8(%ebp)\n" /* height */
        "jne .Lfe9dde_000e9e8b\n"
        "addl %eax, -0x9c(%ebp)\n" /* pixelIndex */
        "addl $1, -0xa0(%ebp)\n" /* line 948 | y */
        "movl -0xa0(%ebp), %edx\n" /* y */
        "cmpl %edx, %eax\n"
        "jne .Lfe9dde_000e9e6d\n"
        ".Lfe9dde_000e9fb7:\n"
        "addl $1, -0x64(%ebp)\n" /* line 962 */
        "addl $4, -0x60(%ebp)\n"
        "cmpl $7, -0x64(%ebp)\n" /* line 945 */
        "jne .Lfe9dde_000e9e4b\n"
        /* } scope */
        /* } scope */
        "movl 0x195eed0, %eax\n" /* line 976 */
        "movzwl 0x2d38(%eax), %eax\n"
        "movl %eax, -0x88(%ebp)\n" /* height */
        "xorl %eax, %eax\n"
        "cvtsi2ssl -0x88(%ebp), %xmm0\n" /* height */
        "movss %xmm0, -0xe8(%ebp)\n"
        /* { scope 2: x, y, pixelIndex, faceIndex, ... */
        ".Lfe9dde_000e9fed:\n"
        "movl -0x88(%ebp), %edx\n" /* line 926 | height */
        "testl %edx, %edx\n"
        "jle .Lfe9dde_000ea549\n"
        "leal 1(%eax), %edx\n"
        "movl %edx, -0x90(%ebp)\n" /* faceIndex */
        "leal cubeShotGlob(, %eax, 4), %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl $0, -0x94(%ebp)\n" /* y */
        ".Lfe9dde_000ea018:\n"
        "cvtsi2ssl -0x94(%ebp), %xmm0\n" /* y */
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "addss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "divss -0xe8(%ebp), %xmm1\n"
        "subss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movss %xmm1, -0x74(%ebp)\n"
        "movl -0x94(%ebp), %eax\n" /* y */
        "imull -0x88(%ebp), %eax\n" /* height */
        "shll $2, %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl $0, -0x98(%ebp)\n" /* x */
        ".Lfe9dde_000ea062:\n"
        "cvtsi2ssl -0x98(%ebp), %xmm0\n" /* line 930 | x */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm0, %xmm0\n"
        "divss -0xe8(%ebp), %xmm0\n"
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        /* { scope 3: y, sourceDir, sampleCount */
        "movl -0x90(%ebp), %edx\n" /* line 869 | faceIndex */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $2, %eax\n"
        "leal 0xc(%eax), %edx\n"
        "leal cubemapShotAxis(%edx), %ecx\n" /* dir */
        "leal cubemapShotAxis(%eax), %ebx\n" /* start */
        /* { scope 4 */
        "movaps %xmm0, %xmm1\n" /* line 288 */
        "mulss cubemapShotAxis(%edx), %xmm1\n"
        "addss cubemapShotAxis(%eax), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* dir */
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss 4(%ecx), %xmm1\n"
        "addss 4(%ebx), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss 8(%ecx), %xmm0\n" /* line 290 */
        "addss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "addl $0x18, %eax\n" /* line 870 */
        "leal cubemapShotAxis(%eax), %edx\n" /* dir */
        /* { scope 4 */
        "movss -0x74(%ebp), %xmm0\n" /* line 288 */
        "mulss cubemapShotAxis(%eax), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* dir */
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movss -0x74(%ebp), %xmm0\n" /* line 289 */
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x74(%ebp), %xmm0\n" /* line 290 */
        "mulss 8(%edx), %xmm0\n"
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "leal -0x24(%ebp), %eax\n" /* line 871 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        /* } scope */
        "movl -0x6c(%ebp), %eax\n" /* line 931 */
        "movl -0x78(%ebp), %edx\n"
        "addl (%edx), %eax\n"
        "movl %eax, -0x8c(%ebp)\n" /* pixel */
        "movl $0, -0x80(%ebp)\n" /* sampleCount */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "movaps %xmm0, %xmm3\n"
        "movl $1, -0x70(%ebp)\n"
        "movl $0x24, %ebx\n" /* start */
        ".Lfe9dde_000ea160:\n"
        "movl $0, -0x84(%ebp)\n" /* y */
        "movl -0x84(%ebp), %eax\n" /* y */
        /* { scope 3: y, sourceDir, sampleCount */
        /* { scope 4 */
        ".Lfe9dde_000ea170:\n"
        "cvtsi2ssl -0x84(%ebp), %xmm2\n" /* line 890 | y */
        "addss 0x2ed5d8, %xmm2\n" /* 0.5f */
        "addss %xmm2, %xmm2\n"
        "divss -0xe8(%ebp), %xmm2\n"
        "subss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "imull -0x88(%ebp), %eax\n" /* height */
        "leal (%eax, %eax, 2), %eax\n"
        "leal (, %eax, 4), %edi\n"
        "xorl %esi, %esi\n" /* x */
        ".Lfe9dde_000ea1a7:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 894 | x */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm0, %xmm0\n"
        "divss -0xe8(%ebp), %xmm0\n"
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        /* { scope 5 */
        "movaps %xmm0, %xmm1\n" /* line 288 */
        "mulss 0x2f272c(%ebx), %xmm1\n"
        "addss cubemapShotAxis(%ebx), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* sourceDir */
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss 0x2f2730(%ebx), %xmm1\n"
        "addss 0x2f2724(%ebx), %xmm1\n"
        "mulss 0x2f2734(%ebx), %xmm0\n" /* line 290 */
        "addss 0x2f2728(%ebx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "movaps %xmm2, %xmm0\n" /* line 288 */
        "mulss 0x2f2738(%ebx), %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n" /* sourceDir */
        "movss %xmm0, -0x30(%ebp)\n" /* sourceDir */
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss 0x2f273c(%ebx), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movaps %xmm2, %xmm0\n" /* line 290 */
        "mulss 0x2f2740(%ebx), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 871 | sourceDir */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0xf8(%ebp)\n"
        "movss %xmm3, -0x108(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 304 | dir */
        "mulss -0x30(%ebp), %xmm1\n" /* sourceDir */
        "movss -0x20(%ebp), %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 896 */
        "ucomiss %xmm1, %xmm0\n"
        "movss -0xf8(%ebp), %xmm2\n"
        "movss -0x108(%ebp), %xmm3\n"
        "jae .Lfe9dde_000ea2da\n"
        "movl %edi, %eax\n" /* line 897 */
        "movl -0x70(%ebp), %edx\n"
        "addl -0x4c(%ebp, %edx, 4), %eax\n"
        /* { scope 5 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss (%eax), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss -0x54(%ebp), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss -0x4c(%ebp), %xmm1\n"
        "movss %xmm1, -0x4c(%ebp)\n"
        /* } scope */
        "addl $1, -0x80(%ebp)\n" /* line 899 | sampleCount */
        ".Lfe9dde_000ea2da:\n"
        "addl $1, %esi\n" /* line 892 | x */
        "addl $0xc, %edi\n"
        "cmpl %esi, -0x88(%ebp)\n" /* x, height */
        "jne .Lfe9dde_000ea1a7\n"
        "addl $1, -0x84(%ebp)\n" /* line 890 | y */
        "movl -0x84(%ebp), %eax\n" /* y */
        "cmpl %eax, -0x88(%ebp)\n" /* height */
        "jne .Lfe9dde_000ea170\n"
        "addl $1, -0x70(%ebp)\n"
        "addl $0x24, %ebx\n" /* start */
        "cmpl $7, -0x70(%ebp)\n" /* line 888 */
        "jne .Lfe9dde_000ea160\n"
        "cvtsi2ssl -0x80(%ebp), %xmm0\n" /* line 904 | sampleCount */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x7c(%ebp)\n"
        "mulss %xmm1, %xmm3\n" /* line 905 */
        "movl $0xc0000000, 8(%esp)\n"
        "movl $0x3fdd1745, 0xc(%esp)\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, (%esp)\n"
        "calll pow\n"
        "fstpl -0xc8(%ebp)\n"
        "cvtsd2ss -0xc8(%ebp), %xmm2\n"
        "movss %xmm2, -0x5c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n" /* line 906 */
        "mulss -0x54(%ebp), %xmm0\n"
        "movl $0xc0000000, 8(%esp)\n"
        "movl $0x3fdd1745, 0xc(%esp)\n"
        "cvtss2sd %xmm0, %xmm1\n"
        "movsd %xmm1, (%esp)\n"
        "calll pow\n"
        "fstpl -0xd0(%ebp)\n"
        "cvtsd2ss -0xd0(%ebp), %xmm2\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "movss -0x7c(%ebp), %xmm0\n" /* line 907 */
        "mulss -0x4c(%ebp), %xmm0\n"
        "movl $0xc0000000, 8(%esp)\n"
        "movl $0x3fdd1745, 0xc(%esp)\n"
        "cvtss2sd %xmm0, %xmm1\n"
        "movsd %xmm1, (%esp)\n"
        "calll pow\n"
        "fstpl -0xd8(%ebp)\n"
        "cvtsd2ss -0xd8(%ebp), %xmm2\n"
        "movss %xmm2, -0x50(%ebp)\n"
        "movss -0x5c(%ebp), %xmm1\n" /* line 280 */
        "movl 8(%ebp), %eax\n" /* baseColor */
        "mulss (%eax), %xmm1\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 281 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "mulss 8(%eax), %xmm2\n" /* line 282 */
        "movss %xmm2, -0x50(%ebp)\n"
        "movl -0x8c(%ebp), %ebx\n" /* line 910 | pixel, start */
        "addl $2, %ebx\n" /* start */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lfe9dde_000ea527\n"
        "movss 0x2ed5d4, %xmm0\n" /* 255.0f */
        ".Lfe9dde_000ea425:\n"
        "addss 0x2ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xdc(%ebp)\n"
        "cvttss2si -0xdc(%ebp), %eax\n"
        "movb %al, (%ebx)\n"
        "movl -0x8c(%ebp), %ebx\n" /* line 911 | pixel, start */
        "addl $1, %ebx\n" /* start */
        "movss -0x58(%ebp), %xmm0\n" /* line 45 */
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lfe9dde_000ea537\n"
        "movss 0x2ed5d4, %xmm0\n" /* 255.0f */
        ".Lfe9dde_000ea472:\n"
        "addss 0x2ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xe0(%ebp)\n"
        "cvttss2si -0xe0(%ebp), %eax\n"
        "movb %al, (%ebx)\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 45 */
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lfe9dde_000ea518\n"
        "movss 0x2ed5d4, %xmm0\n" /* 255.0f */
        ".Lfe9dde_000ea4b2:\n"
        "addss 0x2ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xe4(%ebp)\n"
        "cvttss2si -0xe4(%ebp), %eax\n"
        "movl -0x8c(%ebp), %edx\n" /* pixel */
        "movb %al, (%edx)\n"
        "movb $0xff, 3(%edx)\n" /* line 913 */
        /* } scope */
        /* } scope */
        "addl $1, -0x98(%ebp)\n" /* line 928 | x */
        "addl $4, -0x6c(%ebp)\n"
        "movl -0x98(%ebp), %eax\n" /* x */
        "cmpl %eax, -0x88(%ebp)\n" /* height */
        "jne .Lfe9dde_000ea062\n"
        "addl $1, -0x94(%ebp)\n" /* line 926 | y */
        "movl -0x94(%ebp), %edx\n" /* y */
        "cmpl %edx, %eax\n"
        "jne .Lfe9dde_000ea018\n"
        "movl -0x90(%ebp), %eax\n" /* faceIndex */
        "jmp .Lfe9dde_000ea54c\n"
        /* { scope 3: y, sourceDir, sampleCount */
        /* { scope 4 */
        ".Lfe9dde_000ea518:\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 45 */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lfe9dde_000ea4b2\n"
        ".Lfe9dde_000ea527:\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lfe9dde_000ea425\n"
        ".Lfe9dde_000ea537:\n"
        "movss -0x58(%ebp), %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lfe9dde_000ea472\n"
        /* } scope */
        /* } scope */
        ".Lfe9dde_000ea549:\n"
        "addl $1, %eax\n" /* line 926 */
        ".Lfe9dde_000ea54c:\n"
        "cmpl $5, %eax\n" /* line 924 */
        "jle .Lfe9dde_000e9fed\n"
        /* } scope */
        "movl -0x48(%ebp), %eax\n" /* line 978 | linearColors */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        /* } scope */
        "addl $0x10c, %esp\n" /* line 979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 566 */
__attribute__((naked))
void R_ScreenshotCommand(GfxScreenshotType type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 566 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x26c, %esp\n"
        /* { scope 1: filename */
        "movl 8(%ebp), %eax\n" /* line 574 | type */
        "testl %eax, %eax\n"
        "je .Lfea56e_000ea596\n"
        "cmpl $1, 8(%ebp)\n" /* type */
        "je .Lfea56e_000ea84c\n"
        /* } scope */
        ".Lfea56e_000ea58b:\n"
        "addl $0x26c, %esp\n" /* line 644 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: filename */
        ".Lfea56e_000ea596:\n"
        "movl $0x225620, -0x220(%ebp)\n" /* line 574 | extension */
        ".Lfea56e_000ea5a0:\n"
        "movl 0x195eee0, %ebx\n" /* line 589 | buffer */
        "movl $1, (%esp)\n"
        "calll *0x104(%ebx)\n" /* buffer */
        "movl $0x225628, %edi\n" /* buffer */
        "movl $0xa, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n" /* pixels */
        "repe cmpsb %es:(%edi), (%esi)\n" /* buffer, pixels */
        "movl $0, %eax\n"
        "je .Lfea56e_000ea5d3\n"
        "movzbl -1(%esi), %eax\n" /* pixels */
        "movzbl -1(%edi), %ecx\n" /* buffer */
        "subl %ecx, %eax\n"
        ".Lfea56e_000ea5d3:\n"
        "testl %eax, %eax\n"
        "je .Lfea56e_000ea6f8\n"
        "movl $1, (%esp)\n" /* line 596 */
        "calll *0x104(%ebx)\n" /* buffer */
        "movl $0x225634, %edi\n" /* buffer */
        "movl $9, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n" /* pixels */
        "repe cmpsb %es:(%edi), (%esi)\n" /* buffer, pixels */
        "movl $0, %eax\n"
        "je .Lfea56e_000ea608\n"
        "movzbl -1(%esi), %eax\n" /* pixels */
        "movzbl -1(%edi), %ecx\n" /* buffer */
        "subl %ecx, %eax\n"
        ".Lfea56e_000ea608:\n"
        "testl %eax, %eax\n"
        "je .Lfea56e_000ea7ac\n"
        ".Lfea56e_000ea610:\n"
        "movl 0x195eee0, %ebx\n" /* line 602 | buffer */
        "movl $1, (%esp)\n"
        "calll *0x104(%ebx)\n" /* buffer */
        "movl $0x225640, %edi\n" /* buffer */
        "movl $7, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n" /* pixels */
        "repe cmpsb %es:(%edi), (%esi)\n" /* buffer, pixels */
        "movl $0, %eax\n"
        "je .Lfea56e_000ea643\n"
        "movzbl -1(%esi), %eax\n" /* pixels */
        "movzbl -1(%edi), %ecx\n" /* buffer */
        "subl %ecx, %eax\n"
        ".Lfea56e_000ea643:\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x224(%ebp)\n" /* silent */
        "calll *0x100(%ebx)\n" /* line 604 | buffer */
        "cmpl $2, %eax\n"
        "je .Lfea56e_000ea906\n"
        ".Lfea56e_000ea660:\n"
        "movl lastNumber, %eax\n" /* line 612 */
        "movl %eax, %edx\n"
        "cmpl $0x270f, %eax\n"
        "jg .Lfea56e_000ea70d\n"
        "leal -0x118(%ebp), %ebx\n" /* filename, buffer */
        "movl 0x195eee0, %esi\n" /* pixels */
        "jmp .Lfea56e_000ea6c8\n"
        ".Lfea56e_000ea680:\n"
        "movl -0x220(%ebp), %eax\n" /* line 55 | extension */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x22565c, 8(%esp)\n" /* "screenshots/shot9999.%s" */
        "movl $0x100, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lfea56e_000ea6a2:\n"
        "movl %ebx, (%esp)\n" /* line 615 | buffer */
        "calll *0x13c(%esi)\n" /* pixels */
        "testl %eax, %eax\n"
        "je .Lfea56e_000ea708\n"
        "movl lastNumber, %edx\n" /* line 612 */
        "addl $1, %edx\n"
        "movl %edx, %eax\n"
        "movl %edx, lastNumber\n"
        "cmpl $0x270f, %edx\n"
        "jg .Lfea56e_000ea70d\n"
        ".Lfea56e_000ea6c8:\n"
        "cmpl $0x270f, %edx\n" /* line 53 */
        "ja .Lfea56e_000ea680\n"
        "movl -0x220(%ebp), %eax\n" /* line 59 | extension */
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $0x225674, 8(%esp)\n" /* "screenshots/shot%04i.%s" */
        "movl $0x100, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lfea56e_000ea6a2\n"
        ".Lfea56e_000ea6f8:\n"
        "calll R_LevelShot\n" /* line 592 */
        /* } scope */
        "addl $0x26c, %esp\n" /* line 644 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfea56e_000ea708:\n"
        "movl lastNumber, %eax\n"
        /* { scope 1: filename */
        ".Lfea56e_000ea70d:\n"
        "cmpl $0x270e, %eax\n" /* line 618 */
        "jg .Lfea56e_000ea957\n"
        "addl $1, %eax\n" /* line 623 */
        "movl %eax, lastNumber\n"
        ".Lfea56e_000ea720:\n"
        "movl 8(%ebp), %esi\n" /* line 626 | type, pixels */
        "testl %esi, %esi\n" /* pixels */
        "jne .Lfea56e_000ea85b\n"
        "movl 0x195eeec, %eax\n" /* line 629 */
        "movl 4(%eax), %edi\n" /* height */
        "movl (%eax), %esi\n" /* width */
        /* { scope 2: fileSize */
        /* { scope 3 */
        "movl %edi, %eax\n" /* line 502 | buffer */
        "imull %esi, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %edx\n"
        "calll *0x14(%edx)\n"
        "movl %eax, %ebx\n" /* buffer */
        "movl %eax, 8(%esp)\n" /* line 504 */
        "movl $3, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* buffer */
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll R_GetFrontBufferData\n"
        "testb %al, %al\n"
        "jne .Lfea56e_000ea972\n"
        ".Lfea56e_000ea76d:\n"
        "movl %ebx, (%esp)\n" /* line 507 | buffer */
        "movl 0x195eee0, %esi\n"
        "calll *0x18(%esi)\n"
        /* } scope */
        /* } scope */
        ".Lfea56e_000ea779:\n"
        "movl -0x224(%ebp), %ebx\n" /* line 641 | silent, height */
        "testl %ebx, %ebx\n" /* height */
        "jne .Lfea56e_000ea58b\n"
        "leal -0x118(%ebp), %eax\n" /* line 642 | filename */
        "movl %eax, 8(%esp)\n"
        "movl $0x225614, 4(%esp)\n" /* "Wrote %s
" */
        "movl $0, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfea56e_000ea58b\n"
        ".Lfea56e_000ea7ac:\n"
        "calll *0x100(%ebx)\n" /* line 596 | buffer */
        "cmpl $3, %eax\n"
        "jne .Lfea56e_000ea610\n"
        "movl $2, (%esp)\n"
        "calll *0x104(%ebx)\n" /* buffer */
        "cmpb $0, (%eax)\n"
        "je .Lfea56e_000ea610\n"
        "movl $2, (%esp)\n" /* line 598 */
        "calll *0x104(%ebx)\n" /* buffer */
        /* { scope 2: fileSize */
        "movl %eax, 8(%esp)\n" /* line 555 */
        "movl $0x2255ec, 4(%esp)\n" /* "%s.jpg" */
        "leal -0x218(%ebp), %edi\n" /* filename, buffer */
        "movl %edi, (%esp)\n" /* buffer */
        "calll sprintf\n"
        "movl $0, (%esp)\n" /* line 556 */
        "movl $3, %ecx\n"
        "movl $0x200, %edx\n"
        "movl $0x200, %eax\n"
        "calll R_TakeResampledScreenshot\n"
        "movl %eax, %esi\n" /* pixels */
        "testl %eax, %eax\n" /* line 557 */
        "je .Lfea56e_000ea58b\n"
        "movl %eax, 0x10(%esp)\n" /* line 560 */
        "movl $0x200, 0xc(%esp)\n"
        "movl $0x200, 8(%esp)\n"
        "movl $0x5a, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* buffer */
        "calll R_SaveJpg\n"
        "movl %esi, (%esp)\n" /* line 561 | pixels */
        "calll *0x18(%ebx)\n" /* buffer */
        "jmp .Lfea56e_000ea58b\n"
        /* } scope */
        ".Lfea56e_000ea84c:\n"
        "movl $0x225624, -0x220(%ebp)\n" /* line 574 | extension */
        "jmp .Lfea56e_000ea5a0\n"
        ".Lfea56e_000ea85b:\n"
        "cmpl $1, 8(%ebp)\n" /* line 626 | type */
        "jne .Lfea56e_000ea58b\n"
        "movl 0x195eeec, %eax\n" /* line 633 */
        "movl 4(%eax), %ebx\n" /* height */
        "movl (%eax), %esi\n" /* width */
        /* { scope 2: fileSize */
        /* { scope 3 */
        "movl %ebx, %eax\n" /* line 479 */
        "imull %esi, %eax\n"
        "leal 0x12(%eax, %eax, 2), %eax\n"
        "movl %eax, -0x21c(%ebp)\n" /* fileSize */
        "movl %eax, (%esp)\n" /* line 480 */
        "movl 0x195eee0, %edx\n"
        "calll *0x14(%edx)\n"
        "movl %eax, %edi\n" /* buffer */
        "movl $0, (%eax)\n" /* line 482 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movw $0, 0x10(%eax)\n"
        "movb $2, 2(%eax)\n" /* line 483 */
        "movl %esi, %eax\n" /* line 484 */
        "movb %al, 0xc(%edi)\n" /* buffer */
        "movl %esi, %eax\n" /* line 485 */
        "sarl $8, %eax\n"
        "movb %al, 0xd(%edi)\n" /* buffer */
        "movb %bl, 0xe(%edi)\n" /* line 486 | buffer */
        "movl %ebx, %eax\n" /* line 487 */
        "sarl $8, %eax\n"
        "movb %al, 0xf(%edi)\n" /* buffer */
        "movb $0x18, 0x10(%edi)\n" /* line 488 | buffer */
        "movb $0x20, 0x11(%edi)\n" /* line 489 | buffer */
        "leal 0x12(%edi), %eax\n" /* line 491 | buffer */
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll R_GetFrontBufferData\n"
        "testb %al, %al\n"
        "jne .Lfea56e_000ea999\n"
        ".Lfea56e_000ea8f6:\n"
        "movl %edi, (%esp)\n" /* line 494 | buffer */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "jmp .Lfea56e_000ea779\n"
        /* } scope */
        /* } scope */
        ".Lfea56e_000ea906:\n"
        "movl -0x224(%ebp), %edi\n" /* line 604 | silent, buffer */
        "testl %edi, %edi\n" /* buffer */
        "jne .Lfea56e_000ea660\n"
        "movl $1, (%esp)\n" /* line 607 */
        "movl 0x195eee0, %eax\n"
        "calll *0x104(%eax)\n"
        "movl -0x220(%ebp), %esi\n" /* extension, pixels */
        "movl %esi, 0x10(%esp)\n" /* pixels */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x225648, 8(%esp)\n" /* "screenshots/%s.%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x118(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lfea56e_000ea720\n"
        ".Lfea56e_000ea957:\n"
        "movl $0x22568c, 4(%esp)\n" /* line 620 */
        "movl $0, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfea56e_000ea58b\n"
        /* { scope 2: fileSize */
        /* { scope 3 */
        ".Lfea56e_000ea972:\n"
        "movl %ebx, 0x10(%esp)\n" /* line 505 | buffer */
        "movl %edi, 0xc(%esp)\n" /* buffer */
        "movl %esi, 8(%esp)\n"
        "movl $0x5a, 4(%esp)\n"
        "leal -0x118(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll R_SaveJpg\n"
        "jmp .Lfea56e_000ea76d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: fileSize */
        /* { scope 3 */
        ".Lfea56e_000ea999:\n"
        "movl -0x21c(%ebp), %edx\n" /* line 492 | fileSize */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* buffer */
        "leal -0x118(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %esi\n"
        "calll *0x140(%esi)\n"
        "jmp .Lfea56e_000ea8f6\n"
    );
}

