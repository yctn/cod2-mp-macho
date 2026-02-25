/* ASM dump from: D3DXMath.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/D3DXMath.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/MacOpenGLMath.h"
 */

D3DXMATRIX * D3DXMatrixMultiply(D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2);
int D3DXVec4Transform(float (*pOut)[10][16], const D3DXVECTOR4 *pV, const D3DXMATRIX *pM);
const char * DXGetErrorDescription9A(HRESULT hr);
D3DXMATRIX * D3DXMatrixInverse(D3DXMATRIX *pOut, FLOAT *pDeterminant, const D3DXMATRIX *pM);

/* line 166 */
__attribute__((naked))
D3DXMATRIX * D3DXMatrixMultiply(D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pOut */
        /* { scope 1: a, b, c, d */
        "xorl %edi, %edi\n" /* line 172 */
        "movl 0x10(%ebp), %eax\n" /* pM2 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n"
        "movss 0x10(%eax), %xmm0\n"
        "movss %xmm0, -0x78(%ebp)\n"
        "movss 0x20(%eax), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movss 0x30(%eax), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "leal -0x4c(%ebp), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl 0xc(%ebp), %ebx\n" /* pM1 */
        "movaps %xmm0, %xmm4\n"
        /* { scope 2 */
        ".Lf24334_00024378:\n"
        "movss (%ebx), %xmm0\n" /* line 263 */
        "movss %xmm0, -0x68(%ebp)\n" /* a */
        "movss 4(%ebx), %xmm0\n" /* line 264 */
        "movss %xmm0, -0x64(%ebp)\n" /* b */
        "movss 8(%ebx), %xmm0\n" /* line 265 */
        "movss %xmm0, -0x60(%ebp)\n" /* c */
        "movss 0xc(%ebx), %xmm0\n" /* line 266 */
        "movss %xmm0, -0x5c(%ebp)\n" /* d */
        "movss -0x6c(%ebp), %xmm7\n" /* line 268 */
        "movss -0x78(%ebp), %xmm6\n" /* line 269 */
        "movss -0x74(%ebp), %xmm5\n" /* line 270 */
        "movl 0x10(%ebp), %eax\n" /* line 271 | pM2 */
        "movl $1, %ecx\n"
        "leal -0x58(%ebp, %edi, 4), %edx\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf24334_000243bd:\n"
        "movss -0x68(%ebp), %xmm2\n" /* line 275 | a */
        "mulss %xmm7, %xmm2\n"
        "movss -0x64(%ebp), %xmm3\n" /* line 276 | b */
        "mulss %xmm6, %xmm3\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 277 | c */
        "mulss %xmm5, %xmm0\n"
        "mulss %xmm4, %xmm1\n" /* line 278 */
        "movss 4(%eax), %xmm7\n" /* line 282 */
        "movss 0x14(%eax), %xmm6\n" /* line 283 */
        "movss 0x24(%eax), %xmm5\n" /* line 284 */
        "movss 0x34(%eax), %xmm4\n" /* line 285 */
        "addss %xmm3, %xmm2\n" /* line 287 */
        "addss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 273 */
        "je .Lf24334_00024415\n"
        "movss -0x5c(%ebp), %xmm1\n" /* d */
        "jmp .Lf24334_000243bd\n"
        ".Lf24334_00024415:\n"
        "mulss -0x5c(%ebp), %xmm4\n" /* line 295 | d */
        "movss %xmm4, -0x5c(%ebp)\n" /* d */
        "mulss -0x60(%ebp), %xmm5\n" /* c */
        "mulss -0x68(%ebp), %xmm7\n" /* a */
        "mulss -0x64(%ebp), %xmm6\n" /* b */
        "movss %xmm6, -0x64(%ebp)\n" /* b */
        "movaps %xmm7, %xmm0\n"
        "addss %xmm6, %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n" /* a */
        "movaps %xmm5, %xmm0\n"
        "addss -0x68(%ebp), %xmm0\n" /* a */
        "movss %xmm0, -0x60(%ebp)\n" /* c */
        "movaps %xmm4, %xmm0\n"
        "addss -0x60(%ebp), %xmm0\n" /* c */
        "movl -0x7c(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "addl $4, %edi\n"
        "addl $0x10, %ebx\n"
        "addl $0x10, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        /* } scope */
        "cmpl $0x10, %edi\n" /* line 256 */
        "je .Lf24334_00024476\n"
        "movss -0x70(%ebp), %xmm4\n"
        "jmp .Lf24334_00024378\n"
        ".Lf24334_00024476:\n"
        "movl -0x58(%ebp), %eax\n" /* line 299 | pM */
        "movl %eax, (%esi)\n" /* pOut */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 4(%esi)\n" /* pOut */
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 8(%esi)\n" /* pOut */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* pOut */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* pOut */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x14(%esi)\n" /* pOut */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x18(%esi)\n" /* pOut */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x1c(%esi)\n" /* pOut */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x20(%esi)\n" /* pOut */
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x24(%esi)\n" /* pOut */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x28(%esi)\n" /* pOut */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x2c(%esi)\n" /* pOut */
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x30(%esi)\n" /* pOut */
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x34(%esi)\n" /* pOut */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x38(%esi)\n" /* pOut */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x3c(%esi)\n" /* pOut */
        /* } scope */
        "movl %esi, %eax\n" /* line 302 | pOut */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 597 */
__attribute__((naked))
int D3DXVec4Transform(float (*pOut)[10][16], const D3DXVECTOR4 *pV, const D3DXMATRIX *pM)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 597 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* pOut */
        "movl 0xc(%ebp), %ecx\n" /* pV */
        "movl 0x10(%ebp), %edx\n" /* pM */
        "movss (%ecx), %xmm2\n" /* line 599 */
        "movss 4(%ecx), %xmm5\n"
        "movss 8(%ecx), %xmm6\n"
        "movss 0xc(%ecx), %xmm7\n"
        "movaps %xmm2, %xmm4\n" /* line 600 */
        "mulss 4(%edx), %xmm4\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm6, %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm7, %xmm0\n"
        "mulss 0x34(%edx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm3\n" /* line 601 */
        "mulss 8(%edx), %xmm3\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm6, %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm7, %xmm0\n"
        "mulss 0x38(%edx), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm2, %xmm1\n" /* line 602 */
        "mulss 0xc(%edx), %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 0x1c(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm6, %xmm0\n"
        "mulss 0x2c(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm7, %xmm0\n"
        "mulss 0x3c(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss (%edx), %xmm2\n" /* line 604 */
        "mulss 0x10(%edx), %xmm5\n"
        "addss %xmm5, %xmm2\n"
        "mulss 0x20(%edx), %xmm6\n"
        "addss %xmm6, %xmm2\n"
        "mulss 0x30(%edx), %xmm7\n"
        "addss %xmm7, %xmm2\n"
        "movss %xmm2, (%eax)\n"
        "movss %xmm4, 4(%eax)\n" /* line 605 */
        "movss %xmm3, 8(%eax)\n" /* line 606 */
        "movss %xmm1, 0xc(%eax)\n" /* line 607 */
        "popl %ebp\n" /* line 610 */
        "retl\n"
    );
}

/* line 858 */
__attribute__((naked))
const char * DXGetErrorDescription9A(HRESULT hr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 858 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 863 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 618 */
__attribute__((naked))
D3DXMATRIX * D3DXMatrixInverse(D3DXMATRIX *pOut, FLOAT *pDeterminant, const D3DXMATRIX *pM)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 618 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pOut */
        "movl 0x10(%ebp), %ecx\n" /* pM */
        "movl 0x1c(%ecx), %edi\n" /* line 626 */
        "movl 0xc(%ecx), %esi\n"
        "movl %esi, %eax\n"
        "orl %edi, %eax\n"
        "movl 0x2c(%ecx), %edx\n"
        "movl %edx, -0x9c(%ebp)\n"
        "orl %edx, %eax\n"
        "jne .Lf245c2_000245f8\n"
        "cmpl $0x3f800000, 0x3c(%ecx)\n"
        "je .Lf245c2_000246f7\n"
        /* { scope 1 */
        ".Lf245c2_000245f8:\n"
        "leal -0x58(%ebp), %edx\n" /* line 100 | m */
        "movl (%ecx), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* m */
        "movl 4(%ecx), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl %esi, -0x4c(%ebp)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %edi, -0x3c(%ebp)\n"
        "movl 0x20(%ecx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x24(%ecx), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x30(%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x34(%ecx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x38(%ecx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x3c(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x98(%ebp), %eax\n" /* line 689 | Result */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll COpenGLMatrix_Inverse\n"
        "movl -0x98(%ebp), %eax\n" /* line 690 | Result */
        "movl %eax, (%ebx)\n" /* pOut */
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n" /* pOut */
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n" /* pOut */
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* pOut */
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* pOut */
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* pOut */
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* pOut */
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 0x1c(%ebx)\n" /* pOut */
        "movl -0x78(%ebp), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* pOut */
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* pOut */
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 0x28(%ebx)\n" /* pOut */
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 0x2c(%ebx)\n" /* pOut */
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x30(%ebx)\n" /* pOut */
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x34(%ebx)\n" /* pOut */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x38(%ebx)\n" /* pOut */
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x3c(%ebx)\n" /* pOut */
        /* } scope */
        ".Lf245c2_000246da:\n"
        "movl 0xc(%ebp), %eax\n" /* line 693 | pDeterminant */
        "testl %eax, %eax\n"
        "je .Lf245c2_000246ea\n"
        "movl 0xc(%ebp), %edx\n" /* line 697 | pDeterminant */
        "movl $0, (%edx)\n"
        ".Lf245c2_000246ea:\n"
        "movl %ebx, %eax\n" /* line 701 | pOut */
        "addl $0xac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf245c2_000246f7:\n"
        "movss 0x30(%ecx), %xmm4\n" /* line 630 | Cx */
        "movss 0x34(%ecx), %xmm5\n" /* line 631 | Cy */
        "movss 0x38(%ecx), %xmm6\n" /* line 632 | Cz */
        "movss (%ecx), %xmm0\n" /* line 634 | a */
        "movl 0x10(%ecx), %eax\n" /* line 635 | b */
        "movl 0x20(%ecx), %edx\n" /* line 636 | c */
        "movss 4(%ecx), %xmm1\n" /* line 637 | d */
        "movss 8(%ecx), %xmm2\n" /* line 638 | e */
        "movss %xmm0, (%ebx)\n" /* line 640 | pOut */
        "movl %eax, 4(%ebx)\n" /* line 641 | pOut */
        "movl %edx, 8(%ebx)\n" /* line 642 | pOut */
        "mulss %xmm4, %xmm0\n" /* line 643 */
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss 0x2ef850, %xmm1\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x30(%ebx)\n" /* pOut */
        "movss 0x14(%ecx), %xmm2\n" /* line 646 */
        "movl 0x24(%ecx), %edx\n" /* line 647 */
        "movss 0x10(%ecx), %xmm0\n" /* line 648 */
        "movss 0x18(%ecx), %xmm3\n" /* line 649 */
        "movl 4(%ecx), %eax\n" /* line 651 */
        "movl %eax, 0x10(%ebx)\n" /* pOut */
        "movss %xmm2, 0x14(%ebx)\n" /* line 652 | pOut */
        "movl %edx, 0x18(%ebx)\n" /* line 653 | pOut */
        "mulss %xmm4, %xmm0\n" /* line 654 */
        "mulss %xmm5, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm6, %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x34(%ebx)\n" /* pOut */
        "movl 0x18(%ecx), %edx\n" /* line 657 */
        "movss 0x28(%ecx), %xmm3\n" /* line 658 */
        "movss 0x20(%ecx), %xmm0\n" /* line 659 */
        "movss 0x24(%ecx), %xmm2\n" /* line 660 */
        "movl 8(%ecx), %eax\n" /* line 662 */
        "movl %eax, 0x20(%ebx)\n" /* pOut */
        "movl %edx, 0x24(%ebx)\n" /* line 663 | pOut */
        "movss %xmm3, 0x28(%ebx)\n" /* line 664 | pOut */
        "mulss %xmm0, %xmm4\n" /* line 665 */
        "mulss %xmm2, %xmm5\n"
        "addss %xmm5, %xmm4\n"
        "mulss %xmm3, %xmm6\n"
        "addss %xmm6, %xmm4\n"
        "xorps %xmm1, %xmm4\n"
        "movss %xmm4, 0x38(%ebx)\n" /* pOut */
        "movl $0, 0xc(%ebx)\n" /* line 667 | pOut */
        "movl $0, 0x1c(%ebx)\n" /* line 668 | pOut */
        "movl $0, 0x2c(%ebx)\n" /* line 669 | pOut */
        "movl $0x3f800000, 0x3c(%ebx)\n" /* line 670 | pOut */
        "jmp .Lf245c2_000246da\n"
        /* } scope */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 99 */
        "calll __Unwind_Resume\n"
    );
}

