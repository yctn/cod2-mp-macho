/* ASM dump from: r_water.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_water.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

static struct WaterGlob waterGlob; /* 0xcb7000 */

void RB_UploadWaterTexture(GfxImage *image, water_t *water);

/* line 383 */
__attribute__((naked))
void RB_UploadWaterTexture(GfxImage *image, water_t *water)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 383 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl 0x195f188, %eax\n" /* line 388 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* water */
        "cmpl %eax, (%edx)\n"
        "je .Lffabe4_000fadc4\n"
        "movl %eax, (%edx)\n" /* line 390 */
        "movl 0x195f230, %eax\n" /* line 392 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lffabe4_000fadc4\n"
        "movl 0x195f0c8, %eax\n" /* line 398 */
        "movss 0x3bc(%eax), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n" /* t */
        /* { scope 1: vecKIndex, n, dz, y, ... */
        /* { scope 2 */
        "movl 0x10(%edx), %ebx\n" /* line 133 */
        "movl %ebx, %edx\n"
        "negl %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* n */
        "movl %ebx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %ebx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, -0x48(%ebp)\n" /* n */
        "jge .Lffabe4_000fadcf\n"
        "movl $0, -0x4c(%ebp)\n" /* vecKIndex */
        "movl 0xc(%ebp), %eax\n" /* water */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0xac(%ebp)\n"
        "movl %eax, %edx\n"
        ".Lffabe4_000fac63:\n"
        "negl %edx\n" /* line 136 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %esi\n" /* m */
        "sarl $1, %esi\n" /* m */
        "movl -0xac(%ebp), %eax\n"
        "shrl $0x1f, %eax\n"
        "addl -0xac(%ebp), %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, %esi\n" /* m */
        "jge .Lffabe4_000faf39\n"
        "movl -0x4c(%ebp), %edi\n" /* line 383 | vecKIndex, mipIndex */
        "shll $2, %edi\n" /* mipIndex */
        "movl -0x4c(%ebp), %edx\n" /* vecKIndex */
        "shll $3, %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl %edx, %ebx\n" /* srcWidth */
        "addl $0xcb7004, %ebx\n" /* srcWidth */
        "jmp .Lffabe4_000facde\n"
        ".Lffabe4_000faca1:\n"
        "jp .Lffabe4_000facf2\n" /* line 141 */
        "movl $0, -4(%ebx)\n" /* line 143 */
        "movl $0, (%ebx)\n" /* line 144 */
        ".Lffabe4_000facb0:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 158 | vecKIndex */
        "addl $1, %esi\n" /* line 136 | m */
        "addl $4, %edi\n"
        "addl $8, -0x24(%ebp)\n"
        "addl $8, %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* water */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, %esi\n" /* m */
        "jge .Lffabe4_000faf33\n"
        ".Lffabe4_000facde:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 141 | water */
        "movl 8(%ecx), %eax\n"
        "movss (%eax, %edi), %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "je .Lffabe4_000faca1\n"
        ".Lffabe4_000facf2:\n"
        "mulss -0x50(%ebp), %xmm0\n" /* line 428 | t */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307cf0, %xmm0\n" /* 162.97466172610083 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x54(%ebp)\n"
        "cvttss2si -0x54(%ebp), %edx\n"
        "andl $0x3ff, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* line 150 | water */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0xbc(%ebp)\n"
        "leal 0xff(%edx), %ecx\n"
        "andl $0x3ff, %ecx\n"
        "movl %ecx, -0xcc(%ebp)\n"
        "movl -0x24(%ebp), %ecx\n"
        "movss (%ecx, %eax), %xmm0\n"
        "movl -0xcc(%ebp), %eax\n"
        "movl 0x195eec8, %ecx\n"
        "mulss 0x1510(%ecx, %eax, 4), %xmm0\n"
        "movss %xmm0, -4(%ebx)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 151 | water */
        "movl 4(%ecx), %eax\n"
        "movl -0x24(%ebp), %ecx\n"
        "movss 4(%ecx, %eax), %xmm0\n"
        "movl 0x195eec8, %eax\n"
        "mulss 0x1510(%eax, %edx, 4), %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "jmp .Lffabe4_000facb0\n"
        /* } scope */
        /* } scope */
        ".Lffabe4_000fad8d:\n"
        "movl 0x195f22c, %ebx\n" /* line 413 | srcWidth */
        "movb $1, (%ebx)\n" /* srcWidth */
        "movl $0xcd7000, 0x10(%esp)\n" /* line 415 */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x15, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* image */
        "movl %ecx, (%esp)\n"
        "calll Image_UploadData\n"
        "movb $0, (%ebx)\n" /* line 417 | srcWidth */
        ".Lffabe4_000fadc4:\n"
        "addl $0xec, %esp\n" /* line 440 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lffabe4_000fadcf:\n"
        "movl 0xc(%ebp), %eax\n" /* water */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0xac(%ebp)\n"
        /* { scope 1: vecKIndex, n, dz, y, ... */
        ".Lffabe4_000faddb:\n"
        "cmpl $1, %ebx\n" /* line 174 | waterIndex */
        "je .Lffabe4_000fb22f\n"
        "xorl %edi, %edi\n" /* log2_n */
        "movl $1, %edx\n"
        ".Lffabe4_000fadeb:\n"
        "addl $1, %edi\n" /* log2_n */
        "movl %edx, %eax\n"
        "movl %edi, %ecx\n" /* log2_n */
        "shll %cl, %eax\n"
        "cmpl %eax, %ebx\n" /* waterIndex */
        "jne .Lffabe4_000fadeb\n"
        ".Lffabe4_000fadf8:\n"
        "cmpl $1, -0xac(%ebp)\n" /* line 177 */
        "je .Lffabe4_000fb228\n"
        "xorl %esi, %esi\n" /* fftIndex */
        "movl $1, %edx\n"
        ".Lffabe4_000fae0c:\n"
        "addl $1, %esi\n" /* fftIndex */
        "movl %edx, %eax\n"
        "movl %esi, %ecx\n" /* fftIndex */
        "shll %cl, %eax\n"
        "cmpl %eax, -0xac(%ebp)\n"
        "jne .Lffabe4_000fae0c\n"
        ".Lffabe4_000fae1d:\n"
        "testl %ebx, %ebx\n" /* line 181 | waterIndex */
        "jg .Lffabe4_000faf5a\n"
        "movl -0xac(%ebp), %ebx\n" /* line 190 | waterIndex */
        "testl %ebx, %ebx\n" /* waterIndex */
        "jg .Lffabe4_000fafca\n"
        /* } scope */
        ".Lffabe4_000fae33:\n"
        "movl 0x195eec0, %eax\n" /* line 406 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lffabe4_000fb036\n"
        /* { scope 1: vecKIndex, n, dz, y, ... */
        /* { scope 2 */
        ".Lffabe4_000fae44:\n"
        "movl -0xac(%ebp), %eax\n" /* line 349 */
        "movl 0xc(%ebp), %edx\n" /* water */
        "imull 0x10(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* dz */
        "testl %eax, %eax\n" /* line 350 */
        "jg .Lffabe4_000fb236\n"
        /* } scope */
        /* } scope */
        ".Lffabe4_000fae62:\n"
        "movl 0x195f22c, %eax\n" /* line 429 */
        "movb $1, (%eax)\n"
        "movl $0xcd7000, 0x10(%esp)\n" /* line 431 */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x32, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* image */
        "movl %ecx, (%esp)\n"
        "calll Image_UploadData\n"
        /* { scope 1: vecKIndex, n, dz, y, ... */
        "movl 0xc(%ebp), %eax\n" /* line 369 | water */
        "movl 0xc(%eax), %ebx\n" /* srcWidth */
        "movl 0x10(%eax), %esi\n" /* line 370 | srcHeight */
        "movl $1, %edi\n" /* mipIndex */
        "jmp .Lffabe4_000faf16\n"
        ".Lffabe4_000faea5:\n"
        "movl $0x4000, 0x18(%esp)\n" /* line 374 */
        "movl $0xcd7000, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* srcHeight */
        "movl %ebx, 8(%esp)\n" /* srcWidth */
        "movl $0x4000, 4(%esp)\n"
        "movl $0xcd7000, (%esp)\n"
        "calll R_DownsampleMipMapBilinear\n"
        "movl $0xcd7000, 0x10(%esp)\n" /* line 375 */
        "movl %edi, 0xc(%esp)\n" /* mipIndex */
        "movl $0, 8(%esp)\n"
        "movl $0x32, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* image */
        "movl %edx, (%esp)\n"
        "calll Image_UploadData\n"
        "sarl $1, %ebx\n" /* line 377 | srcWidth */
        "movl $1, %eax\n" /* line 154 */
        "cmpl %ebx, %eax\n"
        "cmovnsl %eax, %ebx\n"
        "sarl $1, %esi\n" /* line 378 | srcHeight */
        "cmpl %esi, %eax\n" /* line 154 | m */
        "cmovnsl %eax, %esi\n" /* m */
        "addl $1, %edi\n" /* line 372 | mipIndex */
        ".Lffabe4_000faf16:\n"
        "cmpl $1, %ebx\n" /* srcWidth */
        "jg .Lffabe4_000faea5\n"
        "cmpl $1, %esi\n" /* srcHeight */
        "jg .Lffabe4_000faea5\n"
        /* } scope */
        "movl 0x195f22c, %eax\n" /* line 437 */
        "movb $0, (%eax)\n"
        "addl $0xec, %esp\n" /* line 440 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lffabe4_000faf33:\n"
        "movl 0xc(%ebp), %ecx\n" /* water */
        "movl 0x10(%ecx), %ebx\n" /* srcWidth */
        /* { scope 1: vecKIndex, n, dz, y, ... */
        /* { scope 2 */
        ".Lffabe4_000faf39:\n"
        "addl $1, -0x48(%ebp)\n" /* line 133 | n */
        "movl %ebx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %ebx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl %eax, -0x48(%ebp)\n" /* n */
        "jge .Lffabe4_000faddb\n"
        "movl -0xac(%ebp), %edx\n"
        "jmp .Lffabe4_000fac63\n"
        /* } scope */
        /* } scope */
        /* { scope 1: vecKIndex, n, dz, y, ... */
        ".Lffabe4_000faf5a:\n"
        "xorl %ebx, %ebx\n" /* line 181 | waterIndex */
        "movl 0x195eec8, %eax\n"
        "leal 0x2510(%eax), %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "addl $0x2d10, %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lffabe4_000faf7c\n"
        ".Lffabe4_000faf76:\n"
        "movl -0x58(%ebp), %ecx\n"
        "movl -0x5c(%ebp), %eax\n"
        ".Lffabe4_000faf7c:\n"
        "movl %ecx, 0x10(%esp)\n" /* line 188 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* fftIndex */
        "movl %ebx, %eax\n" /* waterIndex */
        "movl 0xc(%ebp), %edx\n" /* water */
        "imull 0xc(%edx), %eax\n"
        "leal waterGlob(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FFT\n"
        "addl $1, %ebx\n" /* line 181 | waterIndex */
        "movl 0xc(%ebp), %ecx\n" /* water */
        "cmpl 0x10(%ecx), %ebx\n" /* waterIndex */
        "jl .Lffabe4_000faf76\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, -0xac(%ebp)\n"
        "movl -0xac(%ebp), %ebx\n" /* line 190 | waterIndex */
        "testl %ebx, %ebx\n" /* waterIndex */
        "jle .Lffabe4_000fae33\n"
        ".Lffabe4_000fafca:\n"
        "xorl %esi, %esi\n" /* fftIndex */
        "movl $waterGlob, %ebx\n" /* waterIndex */
        "movl 0x195eec8, %eax\n"
        "leal 0x2510(%eax), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "addl $0x2d10, %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lffabe4_000faff1\n"
        ".Lffabe4_000fafeb:\n"
        "movl -0x60(%ebp), %ecx\n"
        "movl -0x64(%ebp), %eax\n"
        ".Lffabe4_000faff1:\n"
        "movl %ecx, 0x10(%esp)\n" /* line 197 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xac(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* log2_n */
        "movl %ebx, (%esp)\n" /* waterIndex */
        "calll FFT\n"
        "addl $1, %esi\n" /* line 190 | fftIndex */
        "movl 0xc(%ebp), %ecx\n" /* water */
        "movl 0xc(%ecx), %ecx\n"
        "movl %ecx, -0xac(%ebp)\n"
        "addl $8, %ebx\n" /* waterIndex */
        "cmpl %ecx, %esi\n" /* fftIndex */
        "jl .Lffabe4_000fafeb\n"
        /* } scope */
        "movl 0x195eec0, %eax\n" /* line 406 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lffabe4_000fae44\n"
        /* { scope 1: vecKIndex, n, dz, y, ... */
        /* { scope 2 */
        ".Lffabe4_000fb036:\n"
        "movl -0xac(%ebp), %edx\n" /* line 216 */
        "movl 0xc(%ebp), %eax\n" /* water */
        "imull 0x10(%eax), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* dz */
        "cvtsi2ssl %edx, %xmm0\n" /* line 223 */
        "movss %xmm0, -0x30(%ebp)\n" /* dz_sqrd */
        "mulss %xmm0, %xmm0\n" /* line 224 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "testl %edx, %edx\n" /* line 227 */
        "jg .Lffabe4_000fb2c2\n"
        "movl -0xac(%ebp), %ecx\n"
        ".Lffabe4_000fb066:\n"
        "subl $1, %edx\n" /* line 233 */
        "movl %edx, -0x38(%ebp)\n" /* xymask */
        "subl $1, %ecx\n" /* line 235 */
        "movl %ecx, -0x20(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 236 | dz */
        "subl -0xac(%ebp), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* line 242 | water */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lffabe4_000fad8d\n"
        "movl $0xcd7000, -0x44(%ebp)\n" /* pixels */
        "movl $0, -0x34(%ebp)\n" /* ixm1y */
        "movl $0, -0x3c(%ebp)\n" /* y */
        "jmp .Lffabe4_000fb0c2\n"
        ".Lffabe4_000fb0a0:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 333 | dz */
        "subl -0xac(%ebp), %eax\n"
        "addl -0x34(%ebp), %eax\n" /* ixm1y */
        "andl -0x38(%ebp), %eax\n" /* xymask */
        "addl $1, -0x3c(%ebp)\n" /* line 242 | y */
        "movl -0x3c(%ebp), %ecx\n" /* y */
        "movl 0xc(%ebp), %edx\n" /* water */
        "cmpl 0x10(%edx), %ecx\n"
        "jge .Lffabe4_000fad8d\n"
        ".Lffabe4_000fb0c2:\n"
        "movl -0xac(%ebp), %edx\n" /* line 252 */
        "testl %edx, %edx\n"
        "jle .Lffabe4_000fb0a0\n"
        "movl -0x34(%ebp), %edi\n" /* ixm1y, log2_n */
        "shll $3, %edi\n" /* log2_n */
        "leal (, %eax, 8), %esi\n" /* ixy */
        "movl -0x20(%ebp), %eax\n"
        "movl -0x34(%ebp), %edx\n" /* ixm1y */
        "movl %edx, -0x20(%ebp)\n"
        "xorl %ebx, %ebx\n" /* x */
        "jmp .Lffabe4_000fb0ef\n"
        ".Lffabe4_000fb0e6:\n"
        "movl -0x20(%ebp), %eax\n" /* line 242 */
        "movl -0x34(%ebp), %ecx\n" /* ixm1y */
        "movl %ecx, -0x20(%ebp)\n"
        /* { scope 3 */
        ".Lffabe4_000fb0ef:\n"
        "movss waterGlob(%edi), %xmm3\n" /* line 262 | log2_n, h_ixy */
        "movaps %xmm3, %xmm1\n" /* line 265 | dx */
        "subss waterGlob(, %eax, 8), %xmm1\n" /* dx */
        "subss waterGlob(%esi), %xmm3\n" /* line 266 | ixy, dy */
        "movaps %xmm1, %xmm0\n" /* line 269 */
        "mulss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "movss %xmm3, -0xa8(%ebp)\n"
        "calll MacOpenGLUtils_SquareRootLowPrecision\n"
        "fstps -0x40(%ebp)\n"
        "movss 0x2ed888, %xmm0\n" /* 127.5f */
        "divss -0x40(%ebp), %xmm0\n"
        "movss -0x98(%ebp), %xmm1\n" /* line 428 */
        "mulss %xmm0, %xmm1\n"
        "addss 0x2ed888, %xmm1\n" /* 127.5f */
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "calll floorf\n"
        "fstps -0x68(%ebp)\n"
        "cvttss2si -0x68(%ebp), %eax\n"
        "movl -0x44(%ebp), %edx\n" /* pixels */
        "movb %al, 1(%edx)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "movss -0xa8(%ebp), %xmm3\n"
        "mulss %xmm0, %xmm3\n"
        "addss 0x2ed888, %xmm3\n" /* 127.5f */
        "addss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "movss %xmm3, (%esp)\n"
        "calll floorf\n"
        "fstps -0x6c(%ebp)\n"
        "cvttss2si -0x6c(%ebp), %eax\n"
        "movl -0x44(%ebp), %ecx\n" /* pixels */
        "movb %al, 2(%ecx)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "mulss -0x30(%ebp), %xmm0\n" /* dz_sqrd */
        "addss 0x2ed888, %xmm0\n" /* 127.5f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x70(%ebp)\n"
        "cvttss2si -0x70(%ebp), %eax\n"
        "movl -0x44(%ebp), %edx\n" /* pixels */
        "movb %al, 3(%edx)\n"
        "movb $0xff, (%edx)\n" /* line 274 */
        "addl $4, %edx\n" /* line 326 */
        "movl %edx, -0x44(%ebp)\n" /* pixels */
        "addl $1, -0x34(%ebp)\n" /* line 330 | ixm1y */
        /* } scope */
        "addl $1, %ebx\n" /* line 252 | x */
        "movl 0xc(%ebp), %ecx\n" /* water */
        "movl 0xc(%ecx), %ecx\n"
        "movl %ecx, -0xac(%ebp)\n"
        "addl $8, %edi\n" /* log2_n */
        "addl $8, %esi\n" /* ixy */
        "cmpl %ecx, %ebx\n" /* x */
        "jl .Lffabe4_000fb0e6\n"
        "jmp .Lffabe4_000fb0a0\n"
        /* } scope */
        /* } scope */
        /* { scope 1: vecKIndex, n, dz, y, ... */
        ".Lffabe4_000fb228:\n"
        "xorl %esi, %esi\n" /* line 177 | fftIndex */
        "jmp .Lffabe4_000fae1d\n"
        ".Lffabe4_000fb22f:\n"
        "xorl %edi, %edi\n" /* line 174 | log2_n */
        "jmp .Lffabe4_000fadf8\n"
        /* } scope */
        /* { scope 1: vecKIndex, n, dz, y, ... */
        /* { scope 2 */
        ".Lffabe4_000fb236:\n"
        "movl $0xcd7000, %edi\n" /* line 350 | log2_n */
        "xorl %esi, %esi\n" /* ixy */
        "movl $waterGlob, %ebx\n" /* x */
        "jmp .Lffabe4_000fb283\n"
        /* { scope 3 */
        ".Lffabe4_000fb244:\n"
        "movss 0x2ed5d4, %xmm0\n" /* line 45 | 255.0f */
        /* } scope */
        ".Lffabe4_000fb24c:\n"
        "addss 0x2ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x74(%ebp)\n"
        "cvttss2si -0x74(%ebp), %eax\n"
        "movb %al, (%edi)\n" /* pixels */
        "addl $1, %edi\n" /* line 354 | log2_n */
        "addl $1, %esi\n" /* line 350 | ixy */
        "addl $8, %ebx\n" /* x */
        "movl 0xc(%ebp), %edx\n" /* water */
        "movl 0x10(%edx), %eax\n"
        "imull 0xc(%edx), %eax\n"
        "cmpl %esi, %eax\n" /* ixy */
        "jle .Lffabe4_000fae62\n"
        ".Lffabe4_000fb283:\n"
        "movss (%ebx), %xmm0\n" /* line 352 | x */
        "movss 4(%ebx), %xmm1\n" /* x */
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "divss -0x28(%ebp), %xmm1\n" /* dz */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lffabe4_000fb244\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lffabe4_000fb24c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: vecKIndex, n, dz, y, ... */
        /* { scope 2 */
        ".Lffabe4_000fb2c2:\n"
        "xorl %esi, %esi\n" /* line 227 | ixy */
        "movl $0xcb7004, %ebx\n" /* x */
        ".Lffabe4_000fb2c9:\n"
        "movss -4(%ebx), %xmm0\n" /* line 229 | x */
        "movss (%ebx), %xmm1\n" /* x */
        "mulss %xmm0, %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll MacOpenGLUtils_SquareRootLowPrecision\n"
        "fstps -4(%ebx)\n" /* x */
        "addl $1, %esi\n" /* line 227 | ixy */
        "addl $8, %ebx\n" /* x */
        "cmpl %esi, -0x2c(%ebp)\n" /* ixy, dz */
        "jne .Lffabe4_000fb2c9\n"
        "movl 0xc(%ebp), %eax\n" /* water */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0xac(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* dz */
        "movl %eax, %ecx\n"
        "jmp .Lffabe4_000fb066\n"
    );
}

