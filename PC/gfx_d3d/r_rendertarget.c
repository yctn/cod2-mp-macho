/* ASM dump from: r_rendertarget.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_rendertarget.cpp */

#include "common_types.h"
#include "imports.h"

const char * R_DescribeFormat(int format);
long int R_ShutdownRenderTargets(void);
static long int R_InitFullscreenRenderTargetImage(int picmip, D3DFORMAT format, RenderTargetUsage usage, GfxRenderTarget *renderTarget);
long int R_InitRenderTargets(void);

/* line 54 */
__attribute__((naked))
const char * R_DescribeFormat(int format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 54 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* format */
        "leal -0x15(%edx), %eax\n" /* line 56 */
        "cmpl $0x3b, %eax\n"
        "ja .Lfea9c4_000ea9dc\n"
        "jmpl *0x2f2820(, %eax, 4)\n"
        ".Lfea9c4_000ea9dc:\n"
        "movl %edx, 4(%esp)\n" /* line 82 */
        "movl $0x225780, (%esp)\n" /* "unknown format 0x%08x" */
        "calll va\n"
        "leave\n" /* line 84 */
        "retl\n"
        "movl $0x225710, %eax\n" /* line 60 */
        "leave\n" /* line 84 */
        "retl\n"
        "movl $0x2256b0, %eax\n" /* line 56 */
        "leave\n" /* line 84 */
        "retl\n"
        "movl $0x2256d0, %eax\n" /* line 56 */
        "leave\n" /* line 84 */
        "retl\n"
        "movl $0x225740, %eax\n" /* line 66 */
        "leave\n" /* line 84 */
        "retl\n"
        "movl $0x225760, %eax\n" /* line 69 */
        "leave\n" /* line 84 */
        "retl\n"
        "movl $0x2256f0, %eax\n" /* line 56 */
        "leave\n" /* line 84 */
        "retl\n"
        "movl $0x225720, %eax\n" /* line 63 */
        "leave\n" /* line 84 */
        "retl\n"
    );
}

/* line 578 */
__attribute__((naked))
long int R_ShutdownRenderTargets(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 578 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "xorl %esi, %esi\n"
        "jmp .Lfeaa20_000eaa36\n"
        /* { scope 1 */
        ".Lfeaa20_000eaa2c:\n"
        "cmpl $1, %esi\n" /* line 585 | renderTargetId */
        "je .Lfeaa20_000eaa7c\n"
        "cmpl $7, %esi\n" /* renderTargetId */
        "je .Lfeaa20_000eaa7c\n"
        ".Lfeaa20_000eaa36:\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 597 | renderTargetId */
        "leal (, %eax, 4), %ebx\n"
        "addl 0x195eed0, %ebx\n"
        "movl 0x2c34(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfeaa20_000eaa58\n"
        "movl (%edx), %eax\n" /* line 598 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lfeaa20_000eaa58:\n"
        "movl 0x2c38(%ebx), %edx\n" /* line 599 */
        "testl %edx, %edx\n"
        "je .Lfeaa20_000eaa6a\n"
        "movl (%edx), %eax\n" /* line 600 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lfeaa20_000eaa6a:\n"
        "movl 0x2c30(%ebx), %eax\n" /* line 601 */
        "testl %eax, %eax\n"
        "je .Lfeaa20_000eaa7c\n"
        "movl %eax, (%esp)\n" /* line 602 */
        "calll Image_Release\n"
        ".Lfeaa20_000eaa7c:\n"
        "addl $1, %esi\n" /* line 582 | renderTargetId */
        "cmpl $0xc, %esi\n" /* renderTargetId */
        "jle .Lfeaa20_000eaa2c\n"
        "movl 0x195eed0, %ebx\n" /* line 604 */
        "leal 0x2c30(%ebx), %eax\n"
        "movl $0x104, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 0x2d34(%ebx)\n" /* line 605 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 606 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 412 */
static __attribute__((naked))
long int R_InitFullscreenRenderTargetImage(int picmip, D3DFORMAT format, RenderTargetUsage usage, GfxRenderTarget *renderTarget)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 412 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0x195eeec, %esi\n"
        "movl (%esi), %edx\n"
        "movzbl -0x1c(%ebp), %ecx\n"
        "sarl %cl, %edx\n"
        "movl $1, %ebx\n"
        "testl %edx, %edx\n"
        "movl %ebx, %edi\n"
        "cmovgl %edx, %edi\n"
        "movl 4(%esi), %edx\n"
        "sarl %cl, %edx\n"
        "testl %edx, %edx\n"
        "cmovgl %edx, %ebx\n"
        /* { scope 1 */
        "movl $6, 4(%esp)\n" /* line 366 */
        "movl %eax, (%esp)\n"
        "calll Image_AllocProg\n"
        "movl 0xc(%ebp), %edx\n" /* renderTarget */
        "movl %eax, (%edx)\n"
        "cmpl $2, 8(%ebp)\n" /* line 368 | usage */
        "je .Lfeaaba_000eab90\n"
        "movzwl %bx, %esi\n" /* line 371 */
        "movzwl %di, %ebx\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Image_SetupRenderTarget\n"
        ".Lfeaaba_000eab29:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 373 | renderTarget */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_GetSurface\n"
        "movl 0xc(%ebp), %edx\n" /* renderTarget */
        "movl %eax, 4(%edx)\n"
        "movl %ebx, 0xc(%edx)\n" /* line 374 */
        "movl %esi, 0x10(%edx)\n" /* line 375 */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 423 | usage */
        "testl %edx, %edx\n"
        "jne .Lfeaaba_000eab6d\n"
        "movl 0x195eed0, %ebx\n" /* line 133 */
        "movl 0x2d34(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfeaaba_000eabb2\n"
        ".Lfeaaba_000eab59:\n"
        "movl (%edx), %eax\n" /* line 138 */
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl 0x2d34(%ebx), %eax\n" /* line 139 */
        ".Lfeaaba_000eab67:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 440 | renderTarget */
        "movl %eax, 8(%ecx)\n" /* imageProgType */
        ".Lfeaaba_000eab6d:\n"
        "movl -0x20(%ebp), %eax\n" /* line 444 | imageProgType */
        "movl %eax, 8(%esp)\n" /* imageProgType */
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* renderTarget */
        "movl (%ecx), %eax\n" /* imageProgType */
        "movl %eax, (%esp)\n" /* imageProgType */
        "calll Image_TrackFullscreenTexture\n"
        "addl $0x4c, %esp\n" /* line 450 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfeaaba_000eab90:\n"
        "movzwl %bx, %esi\n" /* line 369 */
        "movzwl %di, %ebx\n"
        "movl -0x20(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Image_SetupSystem\n"
        "jmp .Lfeaaba_000eab29\n"
        /* } scope */
        ".Lfeaaba_000eabb2:\n"
        "movl 0x2c24(%ebx), %eax\n" /* line 133 */
        "testl %eax, %eax\n"
        "jne .Lfeaaba_000eabcc\n"
        "movl 0x2c38(%ebx), %edx\n" /* line 134 */
        "movl %edx, 0x2d34(%ebx)\n"
        "testl %edx, %edx\n" /* line 136 */
        "jne .Lfeaaba_000eab59\n"
        ".Lfeaaba_000eabcc:\n"
        "movl 0x195eeec, %eax\n" /* line 100 */
        "movl (%eax), %edi\n" /* line 108 */
        "movl 4(%eax), %esi\n" /* line 109 */
        "movl 8(%ebx), %eax\n" /* line 144 */
        "movl (%eax), %ecx\n"
        "movl $0, 0x20(%esp)\n"
        "leal 0x2d34(%ebx), %edx\n"
        "movl %edx, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x4b, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x74(%ecx)\n"
        "testl %eax, %eax\n" /* line 156 */
        "js .Lfeaaba_000eac2a\n"
        ".Lfeaaba_000eac1f:\n"
        "movl 0x2d34(%ebx), %eax\n" /* line 160 */
        "jmp .Lfeaaba_000eab67\n"
        ".Lfeaaba_000eac2a:\n"
        "movl %eax, (%esp)\n" /* line 157 */
        "calll R_ErrorDescription\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x225798, 4(%esp)\n" /* "Couldn't create a %i x %i depth-stencil surface: %s
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfeaaba_000eac1f\n"
    );
}

/* line 504 */
__attribute__((naked))
long int R_InitRenderTargets(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 504 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 0x195eed0, %edx\n" /* line 210 */
        "movl 0x195eeec, %ecx\n"
        "movl (%ecx), %eax\n"
        "movl %eax, 0x2c3c(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 211 */
        "movl %eax, 0x2c40(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 213 */
        "movl (%eax), %ecx\n"
        "addl $0x2d50, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x38(%ecx)\n"
        "testl %eax, %eax\n" /* line 214 */
        "js .Lfeac54_000eb1be\n"
        ".Lfeac54_000eac9f:\n"
        "movl 0x195eed0, %eax\n" /* line 217 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "addl $0x2c34, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x48(%ecx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfeac54_000eac9f\n"
        "movl 0x195eeec, %eax\n" /* line 100 */
        "movl (%eax), %edx\n" /* line 108 */
        "movl %edx, -0x4c(%ebp)\n"
        "movl 4(%eax), %edi\n" /* line 109 */
        "movl 0x195ec5c, %ebx\n" /* line 223 */
        "movb $1, (%ebx)\n"
        "movl 0x195eed0, %esi\n" /* line 224 */
        "movl 8(%esi), %edx\n"
        "movl (%edx), %ecx\n"
        "movl $0, 0x20(%esp)\n"
        "leal 0x2c38(%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0x2c28(%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2c24(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x4b, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x74(%ecx)\n"
        "movb $0, (%ebx)\n" /* line 225 */
        "testl %eax, %eax\n" /* line 226 */
        "js .Lfeac54_000eb1e3\n"
        ".Lfeac54_000ead4e:\n"
        "movl 0x195eee0, %ebx\n" /* line 491 */
        "movl $0x2256f0, 8(%esp)\n" /* "24-bit color with 8-bit alpha" */
        "movl $0x225804, 4(%esp)\n" /* "Requested frame buffer to be %s
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl 0x2c34(%esi), %edx\n" /* line 492 */
        "movl (%edx), %ecx\n"
        "leal -0x3c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x30(%ecx)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 493 */
        "movl %eax, 0x10(%esi)\n"
        "movl (%ebx), %ebx\n" /* line 495 */
        "leal -0x15(%eax), %edx\n" /* line 56 */
        "cmpl $0x3b, %edx\n"
        "ja .Lfeac54_000ead99\n"
        "jmpl *0x2f2910(, %edx, 4)\n"
        ".Lfeac54_000ead99:\n"
        "movl %eax, 4(%esp)\n" /* line 82 */
        "movl $0x225780, (%esp)\n" /* "unknown format 0x%08x" */
        "calll va\n"
        ".Lfeac54_000eada9:\n"
        "movl %eax, 8(%esp)\n" /* line 495 */
        "movl $0x225828, 4(%esp)\n" /* "DirectX returned a frame buffer that is %s
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl 0x195eed0, %esi\n" /* line 517 */
        "movl 0x10(%esi), %ecx\n"
        "leal 0x2c6c(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll R_InitFullscreenRenderTargetImage\n"
        "movl 0x2c6c(%esi), %eax\n" /* line 520 */
        "movl %eax, 0x2c44(%esi)\n"
        "movl 0x2c70(%esi), %eax\n"
        "movl %eax, 0x2c48(%esi)\n"
        "movl 0x2c74(%esi), %eax\n"
        "movl %eax, 0x2c4c(%esi)\n"
        "movl 0x2c78(%esi), %eax\n"
        "movl %eax, 0x2c50(%esi)\n"
        "movl 0x2c7c(%esi), %eax\n"
        "movl %eax, 0x2c54(%esi)\n"
        "movl 0x10(%esi), %ecx\n" /* line 521 */
        "leal 0x2c58(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "xorl %edx, %edx\n"
        "movl $9, %eax\n"
        "calll R_InitFullscreenRenderTargetImage\n"
        "movl 0x2c44(%esi), %eax\n" /* line 522 */
        "movl %eax, 0x2cbc(%esi)\n"
        "movl 0x2c48(%esi), %eax\n"
        "movl %eax, 0x2cc0(%esi)\n"
        "movl 0x2c4c(%esi), %eax\n"
        "movl %eax, 0x2cc4(%esi)\n"
        "movl 0x2c50(%esi), %eax\n"
        "movl %eax, 0x2cc8(%esi)\n"
        "movl 0x2c54(%esi), %eax\n"
        "movl %eax, 0x2ccc(%esi)\n"
        "movl $6, 4(%esp)\n" /* line 366 */
        "movl $1, (%esp)\n"
        "calll Image_AllocProg\n"
        "movl %eax, 0x2c80(%esi)\n"
        "movl $0x15, 0xc(%esp)\n" /* line 371 */
        "movl $0x80, 8(%esp)\n"
        "movl $0x80, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Image_SetupRenderTarget\n"
        "movl 0x2c80(%esi), %eax\n" /* line 373 */
        "movl %eax, (%esp)\n"
        "calll Image_GetSurface\n"
        "movl %eax, 0x2c84(%esi)\n"
        "movl $0x80, 0x2c8c(%esi)\n" /* line 374 */
        "movl $0x80, 0x2c90(%esi)\n" /* line 375 */
        "movl $1, 0x14(%esp)\n" /* line 383 */
        "movl $0x80, 0x10(%esp)\n"
        "movl $0x80, 0xc(%esp)\n"
        "movl $0x15, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl 0x2c80(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_TrackTexture\n"
        "movl 0x2c88(%esi), %edx\n" /* line 174 */
        "testl %edx, %edx\n"
        "je .Lfeac54_000eb0f6\n"
        "movl (%edx), %eax\n" /* line 176 */
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl 0x2c88(%esi), %eax\n" /* line 177 */
        ".Lfeac54_000eaf2d:\n"
        "movl 0x195eed0, %esi\n" /* line 471 */
        "movl %eax, 0x2c88(%esi)\n"
        "movl $6, 4(%esp)\n" /* line 366 */
        "movl $2, (%esp)\n"
        "calll Image_AllocProg\n"
        "movl %eax, 0x2c94(%esi)\n"
        "movl $0x15, 0xc(%esp)\n" /* line 371 */
        "movl $0x80, 8(%esp)\n"
        "movl $0x80, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Image_SetupRenderTarget\n"
        "movl 0x2c94(%esi), %eax\n" /* line 373 */
        "movl %eax, (%esp)\n"
        "calll Image_GetSurface\n"
        "movl %eax, 0x2c98(%esi)\n"
        "movl $0x80, 0x2ca0(%esi)\n" /* line 374 */
        "movl $0x80, 0x2ca4(%esi)\n" /* line 375 */
        "movl $1, 0x14(%esp)\n" /* line 383 */
        "movl $0x80, 0x10(%esp)\n"
        "movl $0x80, 0xc(%esp)\n"
        "movl $0x15, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl 0x2c94(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_TrackTexture\n"
        "movl 0x2c88(%esi), %edx\n" /* line 174 */
        "testl %edx, %edx\n"
        "je .Lfeac54_000eb15c\n"
        "movl (%edx), %eax\n" /* line 176 */
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl 0x2c88(%esi), %eax\n" /* line 177 */
        ".Lfeac54_000eafed:\n"
        "movl 0x195eed0, %ebx\n" /* line 481 */
        "movl %eax, 0x2c9c(%ebx)\n"
        "movl 0x10(%ebx), %ecx\n" /* line 543 */
        "leal 0x2cd0(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $2, %edx\n"
        "movl $3, %eax\n"
        "calll R_InitFullscreenRenderTargetImage\n"
        "movl 0x10(%ebx), %ecx\n" /* line 544 */
        "leal 0x2ce4(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $2, %edx\n"
        "movl $4, %eax\n"
        "calll R_InitFullscreenRenderTargetImage\n"
        "movl 0x10(%ebx), %ecx\n" /* line 545 */
        "leal 0x2cf8(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $2, %edx\n"
        "movl $5, %eax\n"
        "calll R_InitFullscreenRenderTargetImage\n"
        "movl 0x10(%ebx), %ecx\n" /* line 552 */
        "leal 0x2d0c(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $2, %edx\n"
        "movl $6, %eax\n"
        "calll R_InitFullscreenRenderTargetImage\n"
        "movl 0x10(%ebx), %ecx\n" /* line 553 */
        "addl $0x2d20, %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $2, %edx\n"
        "movl $7, %eax\n"
        "calll R_InitFullscreenRenderTargetImage\n"
        "addl $0x7c, %esp\n" /* line 575 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl $0x225710, %eax\n" /* line 56 */
        "jmp .Lfeac54_000eada9\n"
        "movl $0x2256b0, %eax\n" /* "16-bit depth without stencil" */
        "jmp .Lfeac54_000eada9\n"
        "movl $0x2256d0, %eax\n" /* "24-bit depth without stencil" */
        "jmp .Lfeac54_000eada9\n"
        "movl $0x225740, %eax\n" /* "24-bit depth with 8-bit stencil" */
        "jmp .Lfeac54_000eada9\n"
        "movl $0x225760, %eax\n" /* "15-bit depth with 1-bit stencil" */
        "jmp .Lfeac54_000eada9\n"
        "movl $0x2256f0, %eax\n" /* "24-bit color with 8-bit alpha" */
        "jmp .Lfeac54_000eada9\n"
        "movl $0x225720, %eax\n" /* "15-bit color with 1-bit alpha" */
        "jmp .Lfeac54_000eada9\n"
        ".Lfeac54_000eb0f6:\n"
        "movl 0x195ec5c, %ebx\n" /* line 183 */
        "movb $1, (%ebx)\n"
        "movl 8(%esi), %edx\n" /* line 184 */
        "movl (%edx), %ecx\n"
        "movl $0, 0x20(%esp)\n"
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x4b, 0xc(%esp)\n"
        "movl $0x80, 8(%esp)\n"
        "movl $0x80, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x74(%ecx)\n"
        "movb $0, (%ebx)\n" /* line 185 */
        "testl %eax, %eax\n" /* line 186 */
        "js .Lfeac54_000eb24b\n"
        "movl -0x1c(%ebp), %eax\n" /* line 198 */
        "jmp .Lfeac54_000eaf2d\n"
        ".Lfeac54_000eb15c:\n"
        "movl 0x195ec5c, %ebx\n" /* line 183 */
        "movb $1, (%ebx)\n"
        "movl 8(%esi), %edx\n" /* line 184 */
        "movl (%edx), %ecx\n"
        "movl $0, 0x20(%esp)\n"
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x4b, 0xc(%esp)\n"
        "movl $0x80, 8(%esp)\n"
        "movl $0x80, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x74(%ecx)\n"
        "movb $0, (%ebx)\n" /* line 185 */
        "testl %eax, %eax\n" /* line 186 */
        "js .Lfeac54_000eb213\n"
        "movl -0x1c(%ebp), %eax\n" /* line 198 */
        "jmp .Lfeac54_000eafed\n"
        ".Lfeac54_000eb1be:\n"
        "movl %eax, (%esp)\n" /* line 215 */
        "calll R_ErrorDescription\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2257d0, 4(%esp)\n" /* "Couldn't get an interface to the swap chain: %s
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfeac54_000eac9f\n"
        ".Lfeac54_000eb1e3:\n"
        "movl %eax, (%esp)\n" /* line 227 */
        "calll R_ErrorDescription\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x225798, 4(%esp)\n" /* "Couldn't create a %i x %i depth-stencil surface: %s
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfeac54_000ead4e\n"
        ".Lfeac54_000eb213:\n"
        "movl %eax, (%esp)\n" /* line 187 */
        "calll R_ErrorDescription\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x80, 0xc(%esp)\n"
        "movl $0x80, 8(%esp)\n"
        "movl $0x225798, 4(%esp)\n" /* "Couldn't create a %i x %i depth-stencil surface: %s
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x1c(%ebp), %eax\n" /* line 198 */
        "jmp .Lfeac54_000eafed\n"
        ".Lfeac54_000eb24b:\n"
        "movl %eax, (%esp)\n" /* line 187 */
        "calll R_ErrorDescription\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x80, 0xc(%esp)\n"
        "movl $0x80, 8(%esp)\n"
        "movl $0x225798, 4(%esp)\n" /* "Couldn't create a %i x %i depth-stencil surface: %s
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x1c(%ebp), %eax\n" /* line 198 */
        "jmp .Lfeac54_000eaf2d\n"
    );
}

