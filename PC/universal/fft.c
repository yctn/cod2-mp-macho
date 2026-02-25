/* ASM dump from: fft.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/fft.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

void FFT_Init(int *fftBitswap, complex_t *fftTrigTable);
void FFT(complex_t *data, long unsigned int log2_count, long unsigned int stride, int *bitSwap, complex_t *trigTable);

/* line 14 */
__attribute__((naked))
void FFT_Init(int *fftBitswap, complex_t *fftTrigTable)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 14 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* fftTrigTable */
        "xorl %esi, %esi\n"
        "movl 8(%ebp), %ebx\n" /* fftBitswap */
        /* { scope 1: radians */
        ".Lffa89c_000fa8ad:\n"
        "movl $0, (%ebx)\n" /* line 24 */
        "xorl %edx, %edx\n"
        ".Lffa89c_000fa8b5:\n"
        "movl %esi, %eax\n" /* line 27 | fftIndex */
        "movl %edx, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lffa89c_000fa8cf\n"
        "movl $7, %ecx\n" /* line 28 */
        "subl %edx, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orl %eax, (%ebx)\n"
        ".Lffa89c_000fa8cf:\n"
        "addl $1, %edx\n" /* line 25 */
        "cmpl $8, %edx\n"
        "jne .Lffa89c_000fa8b5\n"
        "cvtsi2sdl %esi, %xmm0\n" /* line 31 | fftIndex */
        "mulsd 0x307ce8, %xmm0\n" /* 0.02454369260617026 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps 4(%edi)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps (%edi)\n"
        /* } scope */
        "addl $1, %esi\n" /* line 22 | fftIndex */
        "addl $4, %ebx\n"
        "addl $8, %edi\n"
        "cmpl $0x100, %esi\n" /* fftIndex */
        "jne .Lffa89c_000fa8ad\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 33 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 40 */
__attribute__((naked))
void FFT(complex_t *data, long unsigned int log2_count, long unsigned int stride, int *bitSwap, complex_t *trigTable)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 40 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 0xc(%ebp), %ecx\n" /* log2_count */
        /* { scope 1 */
        "movl $1, -0x28(%ebp)\n" /* line 51 | count */
        "shll %cl, -0x28(%ebp)\n" /* count */
        "movl $8, -0x10(%ebp)\n" /* line 54 */
        "subl %ecx, -0x10(%ebp)\n"
        "movl -0x28(%ebp), %edx\n" /* line 55 | count */
        "testl %edx, %edx\n"
        "jle .Lffa924_000fa9a0\n"
        "movl $0, -0x2c(%ebp)\n" /* i */
        "movl 8(%ebp), %edi\n" /* data */
        "movl 0x10(%ebp), %eax\n" /* stride */
        "shll $3, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* i */
        ".Lffa924_000fa961:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 57 | bitSwap */
        "movl (%ecx, %edx, 4), %eax\n"
        "movzbl -0x10(%ebp), %ecx\n"
        "sarl %cl, %eax\n"
        "cmpl %eax, %edx\n" /* line 58 */
        "jle .Lffa924_000fa991\n"
        "movl (%edi), %ebx\n" /* line 60 | m */
        "movl 4(%edi), %esi\n"
        "movl 0x10(%ebp), %ecx\n" /* line 61 | stride */
        "imull %eax, %ecx\n"
        "movl 8(%ebp), %eax\n" /* data */
        "leal (%eax, %ecx, 8), %ecx\n"
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%edi)\n"
        "movl %edx, 4(%edi)\n"
        "movl %ebx, (%ecx)\n" /* line 62 | m */
        "movl %esi, 4(%ecx)\n"
        ".Lffa924_000fa991:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 55 | i */
        "addl -0x44(%ebp), %edi\n"
        "movl -0x2c(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x28(%ebp)\n" /* count */
        "jne .Lffa924_000fa961\n"
        ".Lffa924_000fa9a0:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 69 | stride */
        "imull -0x28(%ebp), %ecx\n" /* count */
        "movl %ecx, -0x40(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je .Lffa924_000faab7\n"
        "movl 0x10(%ebp), %ebx\n" /* stride, m */
        "leal (%ebx, %ebx, 2), %eax\n" /* m */
        "shll $2, %ebx\n" /* m */
        "movl %ebx, -0x18(%ebp)\n" /* m */
        "movl $0, -0x4c(%ebp)\n"
        "movl 8(%ebp), %esi\n" /* data */
        "leal (%esi, %eax, 8), %ecx\n"
        "movl 0x10(%ebp), %edi\n" /* stride */
        "leal (%esi, %edi, 8), %edx\n"
        "movl %edi, %eax\n"
        "shll $4, %eax\n"
        "leal (%eax, %esi), %ebx\n" /* m */
        "shll $5, %edi\n"
        "movl %edi, -0x50(%ebp)\n"
        "movl -0x4c(%ebp), %esi\n"
        "jmp .Lffa924_000fa9e6\n"
        ".Lffa924_000fa9e4:\n"
        "movl %eax, %esi\n"
        ".Lffa924_000fa9e6:\n"
        "movl 8(%ebp), %edi\n" /* line 72 | data */
        "leal (%edi, %esi, 8), %eax\n"
        "movl (%eax), %esi\n"
        "movl 4(%eax), %edi\n"
        "movl %esi, -0x3c(%ebp)\n"
        "movl %edi, -0x38(%ebp)\n"
        "movl (%ebx), %esi\n" /* line 73 | m */
        "movl 4(%ebx), %edi\n" /* m */
        "movl %esi, -0x34(%ebp)\n"
        "movl %edi, -0x30(%ebp)\n"
        "movss (%eax), %xmm1\n" /* line 75 */
        "addss (%edx), %xmm1\n"
        "movss (%ebx), %xmm0\n" /* line 76 | m */
        "addss (%ecx), %xmm0\n"
        "movaps %xmm1, %xmm2\n" /* line 77 */
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, (%eax)\n"
        "subss %xmm0, %xmm1\n" /* line 78 */
        "movss %xmm1, (%ebx)\n" /* m */
        "movss 4(%eax), %xmm1\n" /* line 80 */
        "addss 4(%edx), %xmm1\n"
        "movss 4(%ebx), %xmm0\n" /* line 81 | m */
        "addss 4(%ecx), %xmm0\n"
        "movaps %xmm1, %xmm2\n" /* line 82 */
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, 4(%eax)\n"
        "subss %xmm0, %xmm1\n" /* line 83 */
        "movss %xmm1, 4(%ebx)\n" /* m */
        "movss -0x3c(%ebp), %xmm1\n" /* line 85 */
        "subss (%edx), %xmm1\n"
        "movss -0x30(%ebp), %xmm2\n" /* line 86 */
        "subss 4(%ecx), %xmm2\n"
        "movaps %xmm1, %xmm0\n" /* line 88 */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss -0x34(%ebp), %xmm3\n" /* line 90 */
        "subss (%ecx), %xmm3\n"
        "addss %xmm2, %xmm1\n" /* line 92 */
        "movss %xmm1, (%ecx)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 94 */
        "subss 4(%edx), %xmm0\n"
        "movaps %xmm3, %xmm1\n" /* line 96 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%edx)\n"
        "subss %xmm3, %xmm0\n" /* line 97 */
        "movss %xmm0, 4(%ecx)\n"
        "movl -0x18(%ebp), %edi\n" /* line 69 */
        "addl %edi, -0x4c(%ebp)\n"
        "addl -0x50(%ebp), %ebx\n" /* m */
        "addl -0x50(%ebp), %edx\n"
        "addl -0x50(%ebp), %ecx\n"
        "movl -0x4c(%ebp), %eax\n"
        "cmpl %eax, -0x40(%ebp)\n"
        "ja .Lffa924_000fa9e4\n"
        ".Lffa924_000faab7:\n"
        "cmpl $4, -0x28(%ebp)\n" /* line 194 | count */
        "jle .Lffa924_000fabdb\n"
        "movl $5, -0x24(%ebp)\n" /* bitshave */
        "movl $4, -0x20(%ebp)\n" /* mmax */
        "movl -0x20(%ebp), %edx\n" /* mmax */
        "addl %edx, %edx\n" /* line 196 */
        "movl %edx, -0x1c(%ebp)\n" /* iStep */
        "movl -0x20(%ebp), %eax\n" /* line 197 | mmax */
        "testl %eax, %eax\n"
        "jle .Lffa924_000fabd0\n"
        ".Lffa924_000faae2:\n"
        "movl -0x20(%ebp), %ecx\n" /* mmax */
        "imull 0x10(%ebp), %ecx\n" /* stride */
        "movl %ecx, -0x14(%ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* stride */
        "imull %edx, %edi\n"
        "xorl %ebx, %ebx\n" /* m */
        "leal (, %edi, 8), %esi\n"
        "movl %esi, -0x50(%ebp)\n"
        ".Lffa924_000faafe:\n"
        "movl %ebx, %eax\n" /* line 199 | m */
        "movzbl -0x24(%ebp), %ecx\n" /* bitshave */
        "shll %cl, %eax\n"
        "movl 0x18(%ebp), %esi\n" /* trigTable */
        "movl 4(%esi, %eax, 8), %edx\n"
        "movl (%esi, %eax, 8), %eax\n"
        "movl %edx, -0x48(%ebp)\n"
        "movss -0x48(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm5\n"
        "movl %eax, -0x48(%ebp)\n"
        "movss -0x48(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm4\n"
        "movl 0x10(%ebp), %ecx\n" /* line 200 | stride */
        "imull %ebx, %ecx\n" /* m */
        "cmpl %ecx, -0x40(%ebp)\n"
        "jbe .Lffa924_000faba3\n"
        "movl -0x14(%ebp), %edx\n"
        "addl %ecx, %edx\n"
        "movl 8(%ebp), %eax\n" /* data */
        "leal (%eax, %edx, 8), %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffa924_000fab43\n"
        ".Lffa924_000fab40:\n"
        "movl 8(%ebp), %esi\n" /* data */
        ".Lffa924_000fab43:\n"
        "movss (%edx), %xmm2\n" /* line 203 */
        "movss 4(%edx), %xmm1\n"
        "movaps %xmm2, %xmm3\n"
        "mulss %xmm4, %xmm3\n"
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "subss %xmm0, %xmm3\n"
        "mulss %xmm4, %xmm1\n" /* line 204 */
        "mulss %xmm5, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "leal (%esi, %ecx, 8), %eax\n" /* line 205 */
        "movss (%eax), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss 4(%eax), %xmm0\n" /* line 206 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "addss (%eax), %xmm3\n" /* line 207 */
        "movss %xmm3, (%eax)\n"
        "addss 4(%eax), %xmm1\n" /* line 208 */
        "movss %xmm1, 4(%eax)\n"
        "addl %edi, %ecx\n" /* line 200 */
        "addl -0x50(%ebp), %edx\n"
        "cmpl %ecx, -0x40(%ebp)\n"
        "ja .Lffa924_000fab40\n"
        ".Lffa924_000faba3:\n"
        "addl $1, %ebx\n" /* line 197 | m */
        "cmpl %ebx, -0x20(%ebp)\n" /* m, mmax */
        "jne .Lffa924_000faafe\n"
        "movl -0x1c(%ebp), %edi\n" /* iStep */
        "subl $1, -0x24(%ebp)\n" /* line 194 | bitshave */
        "cmpl %edi, -0x28(%ebp)\n" /* count */
        "jle .Lffa924_000fabdb\n"
        ".Lffa924_000fabbb:\n"
        "movl %edi, -0x20(%ebp)\n" /* mmax */
        "movl %edi, %edx\n"
        "addl %edx, %edx\n" /* line 196 */
        "movl %edx, -0x1c(%ebp)\n" /* iStep */
        "movl -0x20(%ebp), %eax\n" /* line 197 | mmax */
        "testl %eax, %eax\n"
        "jg .Lffa924_000faae2\n"
        ".Lffa924_000fabd0:\n"
        "movl %edx, %edi\n"
        "subl $1, -0x24(%ebp)\n" /* line 194 | bitshave */
        "cmpl %edi, -0x28(%ebp)\n" /* count */
        "jg .Lffa924_000fabbb\n"
        /* } scope */
        ".Lffa924_000fabdb:\n"
        "addl $0x44, %esp\n" /* line 212 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

