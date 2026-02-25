/* ASM dump from: r_image_load_common.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_image_load_common.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/gfx_d3d/r_image.h"
 */

void Image_GetPicmip(const GfxImage *image, Picmip *picmip);
D3DCUBEMAP_FACES Image_CubemapFace(int face);
int Image_GetCardMemoryAmount(int imageFlags, D3DFORMAT format, int width, int height, int depth);
void Image_Setup(GfxImage *image, int width, int height, int depth, int imageFlags, DWORD usage, D3DFORMAT imageFormat);
void Image_UploadData(GfxImage *image, D3DFORMAT format, int face, int mipLevel, const byte *src);

/* line 403 */
__attribute__((naked))
void Image_GetPicmip(const GfxImage *image, Picmip *picmip)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 403 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* image */
        "movl 0xc(%ebp), %edx\n" /* picmip */
        "cmpb $0, 0xb(%eax)\n" /* line 409 */
        "jne .Lf109878_00109894\n"
        "movzbl 0xa(%eax), %eax\n" /* line 411 */
        "movl %eax, 8(%ebp)\n" /* image */
        "popl %ebp\n" /* line 417 */
        "jmp Image_PicmipForSemantic\n" /* line 411 */
        ".Lf109878_00109894:\n"
        "movw $0, (%edx)\n" /* line 416 */
        "popl %ebp\n" /* line 417 */
        "retl\n"
    );
}

/* line 506 */
__attribute__((naked))
D3DCUBEMAP_FACES Image_CubemapFace(int face)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 506 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* face */
        "popl %ebp\n" /* line 516 */
        "retl\n"
    );
}

/* line 559 */
__attribute__((naked))
int Image_GetCardMemoryAmount(int imageFlags, D3DFORMAT format, int width, int height, int depth)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 559 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* format */
        "movl 0x10(%ebp), %ecx\n" /* width */
        "movl 0x14(%ebp), %ebx\n" /* height */
        "movl 0x18(%ebp), %esi\n" /* depth */
        /* { scope 1 */
        "cmpl $0x47, %edi\n" /* line 522 */
        "je .Lf1098a4_00109945\n"
        "jle .Lf1098a4_0010990d\n"
        "cmpl $0x72, %edi\n"
        "je .Lf1098a4_00109945\n"
        "jle .Lf1098a4_00109a72\n"
        "cmpl $0x33545844, %edi\n"
        "je .Lf1098a4_00109a9e\n"
        "cmpl $0x35545844, %edi\n"
        "je .Lf1098a4_00109a9e\n"
        "cmpl $0x31545844, %edi\n"
        "jne .Lf1098a4_00109a80\n"
        "leal 3(%ecx), %eax\n" /* line 541 */
        "sarl $2, %eax\n"
        "leal 3(%ebx), %edx\n"
        "sarl $2, %edx\n"
        "imull %edx, %eax\n"
        "imull %esi, %eax\n"
        "shll $3, %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* memory */
        "jmp .Lf1098a4_00109953\n"
        ".Lf1098a4_0010990d:\n"
        "cmpl $0x17, %edi\n" /* line 522 */
        "je .Lf1098a4_00109a8c\n"
        "jle .Lf1098a4_0010993c\n"
        "cmpl $0x32, %edi\n"
        "je .Lf1098a4_0010992f\n"
        "cmpl $0x33, %edi\n"
        "je .Lf1098a4_00109a8c\n"
        "cmpl $0x1c, %edi\n"
        "jne .Lf1098a4_00109a80\n"
        ".Lf1098a4_0010992f:\n"
        "movl %ecx, %eax\n" /* line 538 */
        "imull %ebx, %eax\n"
        "imull %esi, %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* memory */
        "jmp .Lf1098a4_00109953\n"
        ".Lf1098a4_0010993c:\n"
        "cmpl $0x15, %edi\n" /* line 522 */
        "jl .Lf1098a4_00109a80\n"
        ".Lf1098a4_00109945:\n"
        "movl %ecx, %eax\n" /* line 529 */
        "imull %ebx, %eax\n"
        "imull %esi, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* memory */
        ".Lf1098a4_00109953:\n"
        "testb $2, 8(%ebp)\n" /* line 580 | imageFlags */
        "jne .Lf1098a4_001099a3\n"
        "cmpl $1, %ecx\n" /* line 582 */
        "jle .Lf1098a4_00109999\n"
        ".Lf1098a4_0010995e:\n"
        "sarl $1, %ecx\n" /* line 584 */
        "movl $1, %eax\n" /* line 154 */
        "cmpl %ecx, %eax\n"
        "cmovnsl %eax, %ecx\n"
        "sarl $1, %ebx\n" /* line 585 | height */
        "cmpl %ebx, %eax\n" /* line 154 */
        "cmovnsl %eax, %ebx\n"
        "sarl $1, %esi\n" /* line 586 | depth */
        "cmpl %esi, %eax\n" /* line 154 */
        "cmovnsl %eax, %esi\n"
        "cmpl $0x47, %edi\n" /* line 522 */
        "je .Lf1098a4_001099c0\n"
        "jg .Lf1098a4_001099d0\n"
        "cmpl $0x17, %edi\n"
        "je .Lf1098a4_001099e1\n"
        "jg .Lf1098a4_00109a25\n"
        "cmpl $0x15, %edi\n"
        "jge .Lf1098a4_001099c0\n"
        ".Lf1098a4_0010998f:\n"
        "xorl %eax, %eax\n"
        "addl %eax, -0x10(%ebp)\n" /* line 587 | memory */
        ".Lf1098a4_00109994:\n"
        "cmpl $1, %ecx\n" /* line 582 */
        "jg .Lf1098a4_0010995e\n"
        ".Lf1098a4_00109999:\n"
        "cmpl $1, %ebx\n" /* height */
        "jg .Lf1098a4_0010995e\n"
        "cmpl $1, %esi\n" /* depth */
        "jg .Lf1098a4_0010995e\n"
        ".Lf1098a4_001099a3:\n"
        "testb $4, 8(%ebp)\n" /* line 590 | imageFlags */
        "je .Lf1098a4_00109a67\n"
        "movl -0x10(%ebp), %edx\n" /* line 591 | memory */
        "leal (%edx, %edx, 2), %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* memory */
        /* } scope */
        "addl $4, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1098a4_001099c0:\n"
        "movl %ecx, %eax\n" /* line 529 */
        "imull %ebx, %eax\n"
        "imull %esi, %eax\n"
        "shll $2, %eax\n"
        "addl %eax, -0x10(%ebp)\n" /* line 587 | memory */
        "jmp .Lf1098a4_00109994\n"
        ".Lf1098a4_001099d0:\n"
        "cmpl $0x72, %edi\n" /* line 522 */
        "je .Lf1098a4_001099c0\n"
        "jg .Lf1098a4_001099f0\n"
        "cmpl $0x4b, %edi\n"
        "je .Lf1098a4_001099c0\n"
        "cmpl $0x50, %edi\n"
        "jne .Lf1098a4_0010998f\n"
        ".Lf1098a4_001099e1:\n"
        "movl %ecx, %eax\n" /* line 534 */
        "imull %ebx, %eax\n"
        "imull %esi, %eax\n"
        "addl %eax, %eax\n"
        "addl %eax, -0x10(%ebp)\n" /* line 587 | memory */
        "jmp .Lf1098a4_00109994\n"
        ".Lf1098a4_001099f0:\n"
        "cmpl $0x33545844, %edi\n" /* line 522 */
        "je .Lf1098a4_00109a48\n"
        "cmpl $0x35545844, %edi\n"
        "je .Lf1098a4_00109a48\n"
        "cmpl $0x31545844, %edi\n"
        "jne .Lf1098a4_0010998f\n"
        "leal 3(%ecx), %eax\n" /* line 541 */
        "sarl $2, %eax\n"
        "leal 3(%ebx), %edx\n"
        "sarl $2, %edx\n"
        "imull %edx, %eax\n"
        "imull %esi, %eax\n"
        "shll $3, %eax\n"
        "addl %eax, -0x10(%ebp)\n" /* line 587 | memory */
        "jmp .Lf1098a4_00109994\n"
        ".Lf1098a4_00109a25:\n"
        "cmpl $0x32, %edi\n" /* line 522 */
        "je .Lf1098a4_00109a38\n"
        "cmpl $0x33, %edi\n"
        "je .Lf1098a4_001099e1\n"
        "cmpl $0x1c, %edi\n"
        "jne .Lf1098a4_0010998f\n"
        ".Lf1098a4_00109a38:\n"
        "movl %ecx, %eax\n" /* line 538 */
        "imull %ebx, %eax\n"
        "imull %esi, %eax\n"
        "addl %eax, -0x10(%ebp)\n" /* line 587 | memory */
        "jmp .Lf1098a4_00109994\n"
        ".Lf1098a4_00109a48:\n"
        "leal 3(%ecx), %edx\n" /* line 548 */
        "sarl $2, %edx\n"
        "leal 3(%ebx), %eax\n"
        "sarl $2, %eax\n"
        "imull %eax, %edx\n"
        "movl %esi, %eax\n"
        "imull %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %eax, -0x10(%ebp)\n" /* line 587 | memory */
        "jmp .Lf1098a4_00109994\n"
        ".Lf1098a4_00109a67:\n"
        "movl -0x10(%ebp), %eax\n" /* memory */
        /* } scope */
        "addl $4, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1098a4_00109a72:\n"
        "cmpl $0x4b, %edi\n" /* line 522 */
        "je .Lf1098a4_00109945\n"
        "cmpl $0x50, %edi\n"
        "je .Lf1098a4_00109a8c\n"
        ".Lf1098a4_00109a80:\n"
        "movl $0, -0x10(%ebp)\n" /* memory */
        "jmp .Lf1098a4_00109953\n"
        ".Lf1098a4_00109a8c:\n"
        "movl %ecx, %eax\n" /* line 534 */
        "imull %ebx, %eax\n"
        "imull %esi, %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* memory */
        "jmp .Lf1098a4_00109953\n"
        ".Lf1098a4_00109a9e:\n"
        "leal 3(%ecx), %edx\n" /* line 548 */
        "sarl $2, %edx\n"
        "leal 3(%ebx), %eax\n"
        "sarl $2, %eax\n"
        "imull %eax, %edx\n"
        "imull %esi, %edx\n"
        "shll $4, %edx\n"
        "movl %edx, -0x10(%ebp)\n" /* memory */
        "jmp .Lf1098a4_00109953\n"
    );
}

/* line 420 */
__attribute__((naked))
void Image_Setup(GfxImage *image, int width, int height, int depth, int imageFlags, DWORD usage, D3DFORMAT imageFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 420 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* image */
        "movl 0xc(%ebp), %eax\n" /* width */
        "movl %eax, -0x30(%ebp)\n" /* width */
        "movl 0x10(%ebp), %edx\n" /* height */
        "movl %edx, -0x34(%ebp)\n" /* height */
        "movl 0x14(%ebp), %ecx\n" /* depth */
        "movl %ecx, -0x38(%ebp)\n" /* depth */
        "movl 0x18(%ebp), %eax\n" /* imageFlags */
        "movl %eax, -0x3c(%ebp)\n" /* imageFlags */
        "movl 0x1c(%ebp), %edx\n" /* usage */
        "movl %edx, -0x40(%ebp)\n" /* usage */
        "movl 0x20(%ebp), %ecx\n" /* imageFormat */
        "movl %ecx, -0x44(%ebp)\n" /* imageFormat */
        "testb $3, %al\n" /* line 427 */
        "setne 0xb(%esi)\n" /* image */
        "leal 8(%esi), %eax\n" /* line 428 | image */
        "movl %eax, -0x2c(%ebp)\n" /* picmip */
        /* { scope 1 */
        "cmpb $0, 0xb(%esi)\n" /* line 409 */
        "jne .Lf109abc_00109c34\n"
        "movl %eax, 4(%esp)\n" /* line 411 */
        "movzbl 0xa(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_PicmipForSemantic\n"
        /* } scope */
        /* { scope 1 */
        ".Lf109abc_00109b12:\n"
        "cmpl $0x31545844, -0x44(%ebp)\n" /* line 368 | imageFormat */
        "je .Lf109abc_00109b34\n"
        "cmpl $0x33545844, -0x44(%ebp)\n" /* imageFormat */
        "je .Lf109abc_00109b34\n"
        "cmpl $0x35545844, -0x44(%ebp)\n" /* imageFormat */
        "je .Lf109abc_00109b34\n"
        "movl $1, %edi\n"
        "jmp .Lf109abc_00109b39\n"
        ".Lf109abc_00109b34:\n"
        "movl $4, %edi\n"
        ".Lf109abc_00109b39:\n"
        "movl -0x30(%ebp), %edx\n" /* line 154 | width */
        "cmpl %edx, -0x34(%ebp)\n" /* height */
        "movl %edx, %ebx\n"
        "cmovsl -0x34(%ebp), %ebx\n" /* height */
        "movl $3, %ecx\n"
        ".Lf109abc_00109b4a:\n"
        "movl %ecx, %edx\n"
        "movl %ebx, %eax\n" /* line 391 */
        "sarl %cl, %eax\n"
        "cmpl %eax, %edi\n" /* minSize */
        "jle .Lf109abc_00109b5c\n"
        "subb $1, %dl\n" /* line 392 */
        "subl $1, %ecx\n" /* line 389 */
        "jne .Lf109abc_00109b4a\n"
        ".Lf109abc_00109b5c:\n"
        "movl -0x2c(%ebp), %eax\n" /* picmip */
        "movl $2, %ecx\n"
        ".Lf109abc_00109b64:\n"
        "cmpb %dl, (%eax)\n" /* line 397 */
        "jbe .Lf109abc_00109b6a\n"
        "movb %dl, (%eax)\n" /* line 398 */
        ".Lf109abc_00109b6a:\n"
        "addl $1, %eax\n"
        "subl $1, %ecx\n" /* line 395 */
        "jne .Lf109abc_00109b64\n"
        /* } scope */
        "movzbl 8(%esi), %ebx\n" /* line 142 */
        "movl -0x30(%ebp), %eax\n" /* width */
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        /* { scope 1 */
        "movl $1, %edx\n" /* line 154 */
        "cmpl %eax, %edx\n"
        "movl $1, %ecx\n"
        "cmovsl %eax, %ecx\n"
        "movw %cx, -0x28(%ebp)\n"
        /* } scope */
        "movw %cx, 0x18(%esi)\n" /* line 431 | image */
        "movl -0x34(%ebp), %eax\n" /* line 142 | height */
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        /* { scope 1 */
        "cmpl %eax, %edx\n" /* line 154 */
        "movl $1, %edi\n"
        "cmovsl %eax, %edi\n"
        /* } scope */
        "movw %di, 0x1a(%esi)\n" /* line 432 | minSize, image */
        "movl -0x38(%ebp), %eax\n" /* line 142 | depth */
        "sarl %cl, %eax\n"
        /* { scope 1 */
        "cmpl %eax, %edx\n" /* line 154 */
        "cmovnsl %edx, %eax\n"
        /* } scope */
        "movw %ax, 0x1c(%esi)\n" /* line 433 | image */
        "movl -0x3c(%ebp), %edx\n" /* line 440 | imageFlags */
        "shrl $1, %edx\n"
        "andl $1, %edx\n"
        "testb $4, -0x3c(%ebp)\n" /* line 444 | imageFlags */
        "jne .Lf109abc_00109c72\n"
        "testb $8, -0x3c(%ebp)\n" /* line 448 | imageFlags */
        "je .Lf109abc_00109c3f\n"
        "movl $1, 0x1c(%esp)\n" /* line 450 */
        "movl -0x44(%ebp), %ecx\n" /* imageFormat */
        "movl %ecx, 0x18(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* usage */
        "movl %ecx, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movzwl %ax, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzwl %di, %eax\n" /* minSize */
        "movl %eax, 8(%esp)\n"
        "movzwl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* image */
        "calll Image_Create3DTexture\n"
        ".Lf109abc_00109c07:\n"
        "movl -0x38(%ebp), %eax\n" /* line 481 | depth */
        "movl %eax, 0x1c(%ebp)\n" /* usage */
        "movl -0x34(%ebp), %edx\n" /* height */
        "movl %edx, 0x18(%ebp)\n" /* imageFlags */
        "movl -0x30(%ebp), %ecx\n" /* width */
        "movl %ecx, 0x14(%ebp)\n" /* depth */
        "movl -0x44(%ebp), %eax\n" /* imageFormat */
        "movl %eax, 0x10(%ebp)\n" /* height */
        "movl -0x3c(%ebp), %edx\n" /* imageFlags */
        "movl %edx, 0xc(%ebp)\n" /* width */
        "movl %esi, 8(%ebp)\n" /* image */
        "addl $0x5c, %esp\n" /* line 483 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Image_TrackTexture\n" /* line 481 */
        /* { scope 1 */
        ".Lf109abc_00109c34:\n"
        "movw $0, 8(%esi)\n" /* line 416 */
        "jmp .Lf109abc_00109b12\n"
        /* } scope */
        ".Lf109abc_00109c3f:\n"
        "movl $1, 0x18(%esp)\n" /* line 454 */
        "movl -0x44(%ebp), %eax\n" /* imageFormat */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* usage */
        "movl %ecx, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movzwl %di, %eax\n" /* minSize */
        "movl %eax, 8(%esp)\n"
        "movzwl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* image */
        "calll Image_Create2DTexture\n"
        "jmp .Lf109abc_00109c07\n"
        ".Lf109abc_00109c72:\n"
        "movl $1, 0x14(%esp)\n" /* line 446 */
        "movl -0x44(%ebp), %ecx\n" /* imageFormat */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* usage */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movzwl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* image */
        "calll Image_CreateCubeTexture\n"
        "jmp .Lf109abc_00109c07\n"
    );
}

/* line 296 */
__attribute__((naked))
void Image_UploadData(GfxImage *image, D3DFORMAT format, int face, int mipLevel, const byte *src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 296 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 298 | image */
        "movl (%eax), %edx\n"
        "cmpl $4, %edx\n"
        "je .Lf109ca2_00109db1\n"
        "cmpl $5, %edx\n" /* line 305 */
        "je .Lf109ca2_00109e51\n"
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        ".Lf109ca2_00109cc5:\n"
        "movl 8(%ebp), %eax\n" /* line 142 | image */
        "movzwl 0x18(%eax), %esi\n" /* srcStride */
        "movzbl 0x14(%ebp), %ecx\n" /* mipLevel */
        "sarl %cl, %esi\n" /* srcStride */
        "movl $1, %eax\n" /* line 154 */
        "cmpl %esi, %eax\n" /* srcStride */
        "cmovnsl %eax, %esi\n" /* srcStride */
        "movl 8(%ebp), %ecx\n" /* line 142 | image */
        "movzwl 0x1a(%ecx), %edi\n" /* height */
        "movzbl 0x14(%ebp), %ecx\n" /* mipLevel */
        "sarl %cl, %edi\n" /* height */
        "cmpl %edi, %eax\n" /* line 154 | height */
        "cmovnsl %eax, %edi\n" /* height */
        "cmpl $3, %edx\n" /* line 128 */
        "je .Lf109ca2_0010a12a\n"
        "movl 0x195f0e0, %ebx\n" /* y */
        ".Lf109ca2_00109cfd:\n"
        "movl 8(%ebp), %edx\n" /* line 141 | image */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* lockedRect */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* mipLevel */
        "movl %ecx, 8(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* face */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x4c(%edx)\n"
        "movl (%ebx), %edx\n" /* y */
        "testl %edx, %edx\n"
        "jne .Lf109ca2_00109cfd\n"
        "movl -0x20(%ebp), %eax\n" /* line 142 */
        "movl %eax, -0x48(%ebp)\n" /* dst */
        "movl -0x24(%ebp), %edx\n" /* lockedRect */
        "movl %edx, -0x44(%ebp)\n" /* dstPitch */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        "cmpl $0x32, 0xc(%ebp)\n" /* line 60 | format */
        "je .Lf109ca2_00109d67\n"
        "jg .Lf109ca2_00109e73\n"
        "cmpl $0x17, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_00109e8c\n"
        "jg .Lf109ca2_0010a231\n"
        "cmpl $0x15, 0xc(%ebp)\n" /* format */
        "jl .Lf109ca2_00109d7f\n"
        "shll $2, %esi\n" /* line 64 | srcStride */
        ".Lf109ca2_00109d67:\n"
        "movl $1, -0x40(%ebp)\n" /* line 70 | dy */
        ".Lf109ca2_00109d6e:\n"
        "cmpl -0x44(%ebp), %esi\n" /* line 97 | dstPitch, srcStride */
        "je .Lf109ca2_0010a240\n"
        "testl %edi, %edi\n" /* line 105 | y */
        "jg .Lf109ca2_0010a0fd\n"
        /* } scope */
        /* } scope */
        ".Lf109ca2_00109d7f:\n"
        "movl 8(%ebp), %edx\n" /* line 143 | image */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* mipLevel */
        "movl %ecx, 8(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* face */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x50(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf109ca2_00109d7f\n"
        /* } scope */
        ".Lf109ca2_00109da6:\n"
        "addl $0x8c, %esp\n" /* line 310 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        ".Lf109ca2_00109db1:\n"
        "movzwl 0x18(%eax), %edx\n" /* line 142 */
        "movzbl 0x14(%ebp), %ecx\n" /* mipLevel */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n" /* line 154 */
        "cmpl %edx, %eax\n"
        "cmovnsl %eax, %edx\n"
        "movl %edx, -0x58(%ebp)\n" /* srcStride */
        "movl 8(%ebp), %edx\n" /* line 142 | image */
        "movzwl 0x1a(%edx), %edx\n"
        "sarl %cl, %edx\n"
        "cmpl %edx, %eax\n" /* line 154 */
        "cmovnsl %eax, %edx\n"
        "movl %edx, -0x60(%ebp)\n" /* height */
        "movl 8(%ebp), %edx\n" /* line 142 | image */
        "movzwl 0x1c(%edx), %edx\n"
        "sarl %cl, %edx\n"
        "cmpl %edx, %eax\n" /* line 154 */
        "cmovsl %edx, %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* depth */
        "cmpl $0x47, 0xc(%ebp)\n" /* line 12 | format */
        "je .Lf109ca2_00109ee2\n"
        "jle .Lf109ca2_00109e93\n"
        "cmpl $0x72, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_00109ee2\n"
        "jle .Lf109ca2_0010a268\n"
        "cmpl $0x33545844, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_0010a304\n"
        "cmpl $0x35545844, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_0010a304\n"
        "cmpl $0x31545844, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_0010a278\n"
        "movl -0x58(%ebp), %edx\n" /* line 33 | srcStride */
        "addl $3, %edx\n"
        "sarl $2, %edx\n"
        "movl -0x60(%ebp), %eax\n" /* height */
        "addl $3, %eax\n"
        "sarl $2, %eax\n"
        "imull %eax, %edx\n"
        "shll $3, %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* srcRowPitch */
        "jmp .Lf109ca2_00109eef\n"
        /* } scope */
        ".Lf109ca2_00109e51:\n"
        "movl 0x14(%ebp), %eax\n" /* line 305 | mipLevel */
        "testl %eax, %eax\n"
        "je .Lf109ca2_00109cc5\n"
        "movl 0x195eed0, %eax\n"
        "cmpb $0, 0x2d7b(%eax)\n"
        "jne .Lf109ca2_00109cc5\n"
        "jmp .Lf109ca2_00109da6\n"
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        ".Lf109ca2_00109e73:\n"
        "cmpl $0x31545844, 0xc(%ebp)\n" /* line 60 | format */
        "je .Lf109ca2_00109ec9\n"
        "jg .Lf109ca2_0010a206\n"
        "cmpl $0x33, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_00109d7f\n"
        ".Lf109ca2_00109e8c:\n"
        "addl %esi, %esi\n" /* line 70 | srcStride */
        "jmp .Lf109ca2_00109d67\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        ".Lf109ca2_00109e93:\n"
        "cmpl $0x17, 0xc(%ebp)\n" /* line 12 | format */
        "je .Lf109ca2_0010a2f3\n"
        "jle .Lf109ca2_0010a284\n"
        "cmpl $0x32, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_00109ebd\n"
        "cmpl $0x33, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_0010a2f3\n"
        "cmpl $0x1c, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_0010a278\n"
        ".Lf109ca2_00109ebd:\n"
        "movl -0x58(%ebp), %eax\n" /* line 30 | srcStride */
        "imull -0x60(%ebp), %eax\n" /* height */
        "movl %eax, -0x70(%ebp)\n" /* srcRowPitch */
        "jmp .Lf109ca2_00109eef\n"
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        ".Lf109ca2_00109ec9:\n"
        "leal 3(%esi), %eax\n" /* line 81 | srcStride */
        "sarl $2, %eax\n"
        "leal (, %eax, 8), %esi\n" /* srcStride */
        "movl $4, -0x40(%ebp)\n" /* dy */
        "jmp .Lf109ca2_00109d6e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        ".Lf109ca2_00109ee2:\n"
        "movl -0x58(%ebp), %eax\n" /* line 21 | srcStride */
        "imull -0x60(%ebp), %eax\n" /* height */
        "shll $2, %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* srcRowPitch */
        ".Lf109ca2_00109eef:\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lf109ca2_00109ef5:\n"
        "movl 8(%ebp), %ecx\n" /* line 243 | image */
        "movl 4(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* lockedRect */
        "movl %ecx, 8(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* mipLevel */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x4c(%edx)\n"
        "movl (%ebx), %eax\n" /* y */
        "testl %eax, %eax\n"
        "jne .Lf109ca2_00109ef5\n"
        "movl -0x1c(%ebp), %eax\n" /* line 245 */
        "movl %eax, -0x68(%ebp)\n" /* dst */
        "movl -0x6c(%ebp), %eax\n" /* line 246 | depth */
        "testl %eax, %eax\n"
        "jle .Lf109ca2_0010a02b\n"
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        "movl -0x58(%ebp), %eax\n" /* line 87 | srcStride */
        "addl $3, %eax\n"
        "sarl $2, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "shll $3, %eax\n" /* line 81 */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x58(%ebp), %ecx\n" /* line 70 | srcStride */
        "addl %ecx, %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl -0x58(%ebp), %eax\n" /* line 64 | srcStride */
        "shll $2, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl $0, -0x74(%ebp)\n" /* sliceIndex */
        "jmp .Lf109ca2_00109f9b\n"
        ".Lf109ca2_00109f69:\n"
        "cmpl $0x17, 0xc(%ebp)\n" /* line 60 | format */
        "je .Lf109ca2_00109fc6\n"
        "jg .Lf109ca2_0010a074\n"
        "cmpl $0x15, 0xc(%ebp)\n" /* format */
        "jge .Lf109ca2_0010a1f4\n"
        /* } scope */
        /* } scope */
        ".Lf109ca2_00109f7f:\n"
        "movl -0x70(%ebp), %ecx\n" /* line 249 | srcRowPitch */
        "addl %ecx, 0x18(%ebp)\n" /* src */
        "movl -0x20(%ebp), %eax\n" /* line 250 */
        "addl %eax, -0x68(%ebp)\n" /* dst */
        "addl $1, -0x74(%ebp)\n" /* line 246 | sliceIndex */
        "movl -0x74(%ebp), %edx\n" /* sliceIndex */
        "cmpl %edx, -0x6c(%ebp)\n" /* depth */
        "je .Lf109ca2_0010a02b\n"
        ".Lf109ca2_00109f9b:\n"
        "movl -0x24(%ebp), %edx\n" /* line 248 | lockedRect */
        "movl %edx, -0x64(%ebp)\n" /* dstPitch */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        "cmpl $0x32, 0xc(%ebp)\n" /* line 60 | format */
        "je .Lf109ca2_0010a07e\n"
        "jle .Lf109ca2_00109f69\n"
        "cmpl $0x31545844, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_0010a0eb\n"
        "jg .Lf109ca2_0010a0c3\n"
        "cmpl $0x33, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_00109f7f\n"
        ".Lf109ca2_00109fc6:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 66 */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl $1, -0x5c(%ebp)\n" /* dy */
        ".Lf109ca2_00109fd3:\n"
        "movl -0x64(%ebp), %edx\n" /* line 97 | dstPitch */
        "cmpl %edx, -0x3c(%ebp)\n"
        "je .Lf109ca2_0010a097\n"
        ".Lf109ca2_00109fdf:\n"
        "movl -0x60(%ebp), %eax\n" /* line 105 | height */
        "testl %eax, %eax\n"
        "jle .Lf109ca2_00109f7f\n"
        "movl 0x18(%ebp), %esi\n" /* src, srcStride */
        "movl -0x68(%ebp), %ebx\n" /* dst, y */
        "xorl %edi, %edi\n" /* y */
        ".Lf109ca2_00109fee:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 108 */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* srcStride */
        "movl %ebx, (%esp)\n" /* y */
        "calll memcpy\n"
        "addl -0x64(%ebp), %ebx\n" /* line 111 | dstPitch, y */
        "addl -0x3c(%ebp), %esi\n" /* line 112 | srcStride */
        "addl -0x5c(%ebp), %edi\n" /* line 105 | dy, y */
        "cmpl %edi, -0x60(%ebp)\n" /* y, height */
        "jg .Lf109ca2_00109fee\n"
        /* } scope */
        /* } scope */
        "movl -0x70(%ebp), %ecx\n" /* line 249 | srcRowPitch */
        "addl %ecx, 0x18(%ebp)\n" /* src */
        "movl -0x20(%ebp), %eax\n" /* line 250 */
        "addl %eax, -0x68(%ebp)\n" /* dst */
        "addl $1, -0x74(%ebp)\n" /* line 246 | sliceIndex */
        "movl -0x74(%ebp), %edx\n" /* sliceIndex */
        "cmpl %edx, -0x6c(%ebp)\n" /* depth */
        "jne .Lf109ca2_00109f9b\n"
        ".Lf109ca2_0010a02b:\n"
        "movl 8(%ebp), %ecx\n" /* line 253 | image */
        "movl 4(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* mipLevel */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x50(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf109ca2_00109da6\n"
        "movl 8(%ebp), %ecx\n" /* image */
        "movl 4(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* mipLevel */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x50(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf109ca2_0010a02b\n"
        "jmp .Lf109ca2_00109da6\n"
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        ".Lf109ca2_0010a074:\n"
        "cmpl $0x1c, 0xc(%ebp)\n" /* line 60 | format */
        "jne .Lf109ca2_00109f7f\n"
        ".Lf109ca2_0010a07e:\n"
        "movl -0x58(%ebp), %eax\n" /* srcStride */
        "movl %eax, -0x3c(%ebp)\n"
        "movl $1, -0x5c(%ebp)\n" /* dy */
        "movl -0x64(%ebp), %edx\n" /* line 97 | dstPitch */
        "cmpl %edx, -0x3c(%ebp)\n"
        "jne .Lf109ca2_00109fdf\n"
        ".Lf109ca2_0010a097:\n"
        "movl -0x60(%ebp), %eax\n" /* line 100 | height */
        "subl $1, %eax\n"
        "cltd\n"
        "idivl -0x5c(%ebp)\n" /* dy */
        "addl $1, %eax\n"
        "imull -0x3c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x18(%ebp), %ecx\n" /* src */
        "movl %ecx, 4(%esp)\n"
        "movl -0x68(%ebp), %eax\n" /* dst */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf109ca2_00109f7f\n"
        ".Lf109ca2_0010a0c3:\n"
        "cmpl $0x33545844, 0xc(%ebp)\n" /* line 60 | format */
        "je .Lf109ca2_0010a0d9\n"
        "cmpl $0x35545844, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_00109f7f\n"
        ".Lf109ca2_0010a0d9:\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movl $4, -0x5c(%ebp)\n" /* dy */
        "jmp .Lf109ca2_00109fd3\n"
        ".Lf109ca2_0010a0eb:\n"
        "movl -0x34(%ebp), %eax\n" /* line 72 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl $4, -0x5c(%ebp)\n" /* dy */
        "jmp .Lf109ca2_00109fd3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        ".Lf109ca2_0010a0fd:\n"
        "xorl %ebx, %ebx\n" /* line 105 | y */
        ".Lf109ca2_0010a0ff:\n"
        "movl %esi, 8(%esp)\n" /* line 108 | srcStride */
        "movl 0x18(%ebp), %edx\n" /* src */
        "movl %edx, 4(%esp)\n"
        "movl -0x48(%ebp), %ecx\n" /* dst */
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x44(%ebp), %eax\n" /* line 111 | dstPitch */
        "addl %eax, -0x48(%ebp)\n" /* dst */
        "addl %esi, 0x18(%ebp)\n" /* line 112 | srcStride, src */
        "addl -0x40(%ebp), %ebx\n" /* line 105 | dy, y */
        "cmpl %ebx, %edi\n" /* y */
        "jg .Lf109ca2_0010a0ff\n"
        "jmp .Lf109ca2_00109d7f\n"
        ".Lf109ca2_0010a12a:\n"
        "movl 0x195f0e0, %ebx\n" /* y */
        /* } scope */
        /* } scope */
        ".Lf109ca2_0010a130:\n"
        "movl 8(%ebp), %edx\n" /* line 131 | image */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* lockedRect */
        "movl %ecx, 8(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* mipLevel */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x4c(%edx)\n"
        "movl (%ebx), %eax\n" /* y */
        "testl %eax, %eax\n"
        "jne .Lf109ca2_0010a130\n"
        "movl -0x20(%ebp), %eax\n" /* line 132 */
        "movl %eax, -0x54(%ebp)\n" /* dst */
        "movl -0x24(%ebp), %edx\n" /* lockedRect */
        "movl %edx, -0x50(%ebp)\n" /* dstPitch */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        "cmpl $0x32, 0xc(%ebp)\n" /* line 60 | format */
        "je .Lf109ca2_0010a193\n"
        "jg .Lf109ca2_0010a2a6\n"
        "cmpl $0x17, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_0010a2bf\n"
        "jg .Lf109ca2_0010a324\n"
        "cmpl $0x15, 0xc(%ebp)\n" /* format */
        "jl .Lf109ca2_0010a1ab\n"
        "shll $2, %esi\n" /* line 64 | srcStride */
        ".Lf109ca2_0010a193:\n"
        "movl $1, -0x4c(%ebp)\n" /* line 70 | dy */
        ".Lf109ca2_0010a19a:\n"
        "cmpl -0x50(%ebp), %esi\n" /* line 97 | dstPitch, srcStride */
        "je .Lf109ca2_0010a35e\n"
        "testl %edi, %edi\n" /* line 105 | y */
        "jg .Lf109ca2_0010a2c6\n"
        /* } scope */
        /* } scope */
        ".Lf109ca2_0010a1ab:\n"
        "movl 8(%ebp), %edx\n" /* line 133 | image */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* mipLevel */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x50(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf109ca2_00109da6\n"
        "movl 8(%ebp), %edx\n" /* image */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* mipLevel */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x50(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf109ca2_0010a1ab\n"
        "jmp .Lf109ca2_00109da6\n"
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        ".Lf109ca2_0010a1f4:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 60 */
        "movl %edx, -0x3c(%ebp)\n"
        "movl $1, -0x5c(%ebp)\n" /* dy */
        "jmp .Lf109ca2_00109fd3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        ".Lf109ca2_0010a206:\n"
        "cmpl $0x33545844, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_0010a21c\n"
        "cmpl $0x35545844, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_00109d7f\n"
        ".Lf109ca2_0010a21c:\n"
        "addl $3, %esi\n" /* line 87 | srcStride */
        "sarl $2, %esi\n" /* srcStride */
        "shll $4, %esi\n" /* srcStride */
        "movl $4, -0x40(%ebp)\n" /* dy */
        "jmp .Lf109ca2_00109d6e\n"
        ".Lf109ca2_0010a231:\n"
        "cmpl $0x1c, 0xc(%ebp)\n" /* line 60 | format */
        "jne .Lf109ca2_00109d7f\n"
        "jmp .Lf109ca2_00109d67\n"
        ".Lf109ca2_0010a240:\n"
        "leal -1(%edi), %eax\n" /* line 100 | y */
        "cltd\n"
        "idivl -0x40(%ebp)\n" /* dy */
        "addl $1, %eax\n"
        "imull %eax, %esi\n" /* srcStride */
        "movl %esi, 8(%esp)\n" /* srcStride */
        "movl 0x18(%ebp), %ecx\n" /* src */
        "movl %ecx, 4(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* dst */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf109ca2_00109d7f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        ".Lf109ca2_0010a268:\n"
        "cmpl $0x4b, 0xc(%ebp)\n" /* line 12 | format */
        "je .Lf109ca2_00109ee2\n"
        "cmpl $0x50, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_0010a2f3\n"
        ".Lf109ca2_0010a278:\n"
        "movl $0, -0x70(%ebp)\n" /* srcRowPitch */
        "jmp .Lf109ca2_00109eef\n"
        ".Lf109ca2_0010a284:\n"
        "cmpl $0x15, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_00109ee2\n"
        "cmpl $0x16, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_0010a278\n"
        "movl -0x58(%ebp), %eax\n" /* line 15 | srcStride */
        "imull -0x60(%ebp), %eax\n" /* height */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* srcRowPitch */
        "jmp .Lf109ca2_00109eef\n"
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        ".Lf109ca2_0010a2a6:\n"
        "cmpl $0x31545844, 0xc(%ebp)\n" /* line 60 | format */
        "je .Lf109ca2_0010a386\n"
        "jg .Lf109ca2_0010a333\n"
        "cmpl $0x33, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_0010a1ab\n"
        ".Lf109ca2_0010a2bf:\n"
        "addl %esi, %esi\n" /* line 70 | srcStride */
        "jmp .Lf109ca2_0010a193\n"
        ".Lf109ca2_0010a2c6:\n"
        "xorl %ebx, %ebx\n" /* line 105 | y */
        ".Lf109ca2_0010a2c8:\n"
        "movl %esi, 8(%esp)\n" /* line 108 | srcStride */
        "movl 0x18(%ebp), %edx\n" /* src */
        "movl %edx, 4(%esp)\n"
        "movl -0x54(%ebp), %ecx\n" /* dst */
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x50(%ebp), %eax\n" /* line 111 | dstPitch */
        "addl %eax, -0x54(%ebp)\n" /* dst */
        "addl %esi, 0x18(%ebp)\n" /* line 112 | srcStride, src */
        "addl -0x4c(%ebp), %ebx\n" /* line 105 | dy, y */
        "cmpl %ebx, %edi\n" /* y */
        "jg .Lf109ca2_0010a2c8\n"
        "jmp .Lf109ca2_0010a1ab\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        ".Lf109ca2_0010a2f3:\n"
        "movl -0x58(%ebp), %eax\n" /* line 26 | srcStride */
        "imull -0x60(%ebp), %eax\n" /* height */
        "addl %eax, %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* srcRowPitch */
        "jmp .Lf109ca2_00109eef\n"
        ".Lf109ca2_0010a304:\n"
        "movl -0x58(%ebp), %edx\n" /* line 40 | srcStride */
        "addl $3, %edx\n"
        "sarl $2, %edx\n"
        "movl -0x60(%ebp), %eax\n" /* height */
        "addl $3, %eax\n"
        "sarl $2, %eax\n"
        "imull %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* srcRowPitch */
        "jmp .Lf109ca2_00109eef\n"
        /* } scope */
        /* { scope 1: dst, dstPitch, dst, dstPitch, ... */
        /* { scope 2: dy, dy, srcStride, dy */
        /* { scope 3 */
        ".Lf109ca2_0010a324:\n"
        "cmpl $0x1c, 0xc(%ebp)\n" /* line 60 | format */
        "jne .Lf109ca2_0010a1ab\n"
        "jmp .Lf109ca2_0010a193\n"
        ".Lf109ca2_0010a333:\n"
        "cmpl $0x33545844, 0xc(%ebp)\n" /* format */
        "je .Lf109ca2_0010a349\n"
        "cmpl $0x35545844, 0xc(%ebp)\n" /* format */
        "jne .Lf109ca2_0010a1ab\n"
        ".Lf109ca2_0010a349:\n"
        "addl $3, %esi\n" /* line 87 | srcStride */
        "sarl $2, %esi\n" /* srcStride */
        "shll $4, %esi\n" /* srcStride */
        "movl $4, -0x4c(%ebp)\n" /* dy */
        "jmp .Lf109ca2_0010a19a\n"
        ".Lf109ca2_0010a35e:\n"
        "leal -1(%edi), %eax\n" /* line 100 | y */
        "cltd\n"
        "idivl -0x4c(%ebp)\n" /* dy */
        "addl $1, %eax\n"
        "imull %eax, %esi\n" /* srcStride */
        "movl %esi, 8(%esp)\n" /* srcStride */
        "movl 0x18(%ebp), %ecx\n" /* src */
        "movl %ecx, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* dst */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf109ca2_0010a1ab\n"
        ".Lf109ca2_0010a386:\n"
        "leal 3(%esi), %eax\n" /* line 81 | srcStride */
        "sarl $2, %eax\n"
        "leal (, %eax, 8), %esi\n" /* srcStride */
        "movl $4, -0x4c(%ebp)\n" /* dy */
        "jmp .Lf109ca2_0010a19a\n"
    );
}

