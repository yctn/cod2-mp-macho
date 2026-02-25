/* ASM dump from: r_image_wavelet.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_image_wavelet.cpp */

#include "common_types.h"
#include "imports.h"

static const WaveletHuffmanDecode waveletDecodeBlue[4096]; /* 0x2fb100 */
static const WaveletHuffmanDecode waveletDecodeRedGreen[4096]; /* 0x2f7100 */
static const WaveletHuffmanDecode waveletDecodeAlpha[4096]; /* 0x2f3100 */

void Wavelet_DecompressLevel(byte *src, byte *dst, WaveletDecode *decode);

/* line 98 */
__attribute__((naked))
void Wavelet_DecompressLevel(byte *src, byte *dst, WaveletDecode *decode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 98 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xe4, %esp\n"
        /* { scope 1: srcIndex, bitCount, bitCount */
        "movl 0x10(%ebp), %eax\n" /* line 117 | decode */
        "movl 0x18(%eax), %ecx\n"
        "movl 8(%eax), %edx\n"
        "sarl %cl, %edx\n"
        "movl %edx, -0xb4(%ebp)\n" /* w */
        "movl 0xc(%eax), %ebx\n" /* line 118 | value */
        "sarl %cl, %ebx\n" /* value */
        "movl %ebx, -0xb0(%ebp)\n" /* value, h */
        "subl $1, %edx\n" /* line 120 */
        "jle .Lf10a9b8_0010beb2\n"
        "subl $1, %ebx\n" /* value */
        "jle .Lf10a9b8_0010bf45\n"
        "movl 0x10(%ebp), %eax\n" /* line 140 | decode */
        "cmpb $0, 0x1c(%eax)\n"
        "jne .Lf10a9b8_0010acea\n"
        "movl %eax, %ebx\n" /* value */
        "movl 4(%eax), %edx\n" /* line 143 */
        "movl %edx, -0xe0(%ebp)\n"
        "movl %edx, %ecx\n"
        "movzbw (%edx), %dx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movw %dx, (%ebx)\n" /* value */
        "movw $0, 2(%ebx)\n" /* line 144 | value */
        "addl $2, %ecx\n" /* line 145 */
        "movl %ecx, -0xe0(%ebp)\n"
        "movl %ecx, 4(%ebx)\n" /* value */
        "movb $1, 0x1c(%ebx)\n" /* line 146 | value */
        ".Lf10a9b8_0010aa32:\n"
        "movl 0x10(%ebp), %edi\n" /* line 149 | decode, value */
        "movl 0x14(%edi), %edi\n" /* value */
        "movl %edi, -0xa4(%ebp)\n" /* value, dstBpp */
        "movl -0xb4(%ebp), %eax\n" /* line 151 | w */
        "imull %edi, %eax\n" /* value */
        "movl %eax, -0xa8(%ebp)\n" /* stride */
        "subl $1, %edi\n" /* line 152 | value */
        "movl %edi, -0xa0(%ebp)\n" /* value, alpha0 */
        "movl -0xa4(%ebp), %edx\n" /* line 153 | dstBpp */
        "addl %edx, %edx\n"
        "movl %edx, -0xd0(%ebp)\n"
        "subl $1, %edx\n"
        "movl %edx, -0x9c(%ebp)\n" /* alpha1 */
        "movl 0x10(%ebp), %ecx\n" /* line 155 | decode */
        "movzwl (%ecx), %esi\n" /* size */
        "movl %esi, %ebx\n" /* line 33 */
        "sarl $1, %ebx\n"
        "movw %bx, (%ecx)\n"
        "movl -0xe0(%ebp), %edi\n" /* line 35 */
        "movzbl (%edi), %edx\n"
        "movzbl 1(%edi), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%edi), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%edi), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "shll $0xf, %edx\n"
        "orl %edx, %ebx\n"
        "movw %bx, (%eax)\n"
        "movzwl 2(%eax), %edx\n" /* line 36 */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, %edi\n"
        "movl %edi, -0xe0(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %edi, 4(%ecx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ecx)\n"
        "andl $1, %esi\n" /* line 157 | size */
        "je .Lf10a9b8_0010acf8\n"
        "movl -0xb4(%ebp), %eax\n" /* line 158 | w */
        "imull -0xb0(%ebp), %eax\n" /* h */
        "leal 3(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $2, %eax\n"
        "movl %eax, -0xd4(%ebp)\n"
        /* { scope 2: bitCount, bitCount */
        "movl 0x10(%ecx), %ebx\n" /* line 68 | value */
        "movl %ebx, -0xe4(%ebp)\n" /* value */
        "cmpl 0x14(%ecx), %ebx\n" /* value */
        "je .Lf10a9b8_0010bf4d\n"
        "movl $0, -0x10(%ebp)\n" /* line 71 */
        "movl $0, -0x28(%ebp)\n"
        ".Lf10a9b8_0010ab1c:\n"
        "movl 8(%ebp), %ebx\n" /* line 98 | src, value */
        "addl -0x10(%ebp), %ebx\n" /* value */
        "movl %ebx, -0x2c(%ebp)\n" /* value */
        "movl $0, -0x30(%ebp)\n"
        "movl %ebx, %eax\n" /* value */
        "jmp .Lf10a9b8_0010ab66\n"
        ".Lf10a9b8_0010ab30:\n"
        "movzbl -0x95(%ebp), %eax\n" /* line 86 */
        "addl %edi, %eax\n" /* value */
        "movl -0x2c(%ebp), %edi\n" /* value */
        "movb %al, (%edi)\n" /* value */
        "addl $1, -0x30(%ebp)\n"
        "addl $1, %edi\n" /* value */
        "movl %edi, -0x2c(%ebp)\n" /* value */
        "movl -0x30(%ebp), %eax\n" /* line 84 */
        "cmpl %eax, -0xe4(%ebp)\n"
        "je .Lf10a9b8_0010acab\n"
        ".Lf10a9b8_0010ab57:\n"
        "movl 0x10(%ebp), %esi\n" /* decode, bitCount */
        "movl 4(%esi), %esi\n" /* bitCount */
        "movl %esi, -0xe0(%ebp)\n" /* bitCount */
        "movl -0x2c(%ebp), %eax\n"
        ".Lf10a9b8_0010ab66:\n"
        "movzbl (%eax), %eax\n" /* line 86 */
        "movb %al, -0x95(%ebp)\n"
        /* { scope 3 */
        "movl 0x10(%ebp), %edx\n" /* line 50 | decode */
        "movzwl (%edx), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2f3102(%edi), %esi\n" /* value, bitCount */
        /* { scope 4 */
        "movzwl %si, %ecx\n" /* line 33 */
        "movl %ecx, -0x8c(%ebp)\n"
        "sarl %cl, %ebx\n"
        "movw %bx, (%edx)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl $0x10, %ecx\n"
        "subl -0x8c(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %ebx, 4(%ecx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeAlpha(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %edi\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "jne .Lf10a9b8_0010ab30\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x1ff, %eax\n"
        "leal -0xff(%eax), %edi\n" /* value */
        "sarl $9, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %cx, (%eax)\n"
        "movzbl (%ebx), %edx\n" /* line 35 */
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ebx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ebx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $7, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %cx, (%ebx)\n"
        "leal 9(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        /* } scope */
        "movzbl -0x95(%ebp), %eax\n" /* line 86 */
        "addl %edi, %eax\n" /* value */
        "movl -0x2c(%ebp), %edi\n" /* value */
        "movb %al, (%edi)\n" /* value */
        "addl $1, -0x30(%ebp)\n"
        "addl $1, %edi\n" /* value */
        "movl %edi, -0x2c(%ebp)\n" /* value */
        "movl -0x30(%ebp), %eax\n" /* line 84 */
        "cmpl %eax, -0xe4(%ebp)\n"
        "jne .Lf10a9b8_0010ab57\n"
        ".Lf10a9b8_0010acab:\n"
        "movl -0x10(%ebp), %eax\n"
        "addl -0x30(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* line 90 | src */
        "movb $0xff, (%edx, %eax)\n"
        "addl $1, %eax\n" /* line 91 */
        "movl %eax, -0x10(%ebp)\n"
        "addl $1, -0x28(%ebp)\n"
        "movl -0xd4(%ebp), %ecx\n" /* line 81 */
        "cmpl %ecx, -0x28(%ebp)\n"
        "je .Lf10a9b8_0010acf8\n"
        "movl 0x10(%ebp), %edx\n" /* decode */
        "movl 0x10(%edx), %edx\n"
        "movl %edx, -0xe4(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0xe0(%ebp)\n"
        "jmp .Lf10a9b8_0010ab1c\n"
        ".Lf10a9b8_0010acea:\n"
        "movl 4(%eax), %esi\n" /* bitCount */
        "movl %esi, -0xe0(%ebp)\n" /* bitCount */
        "jmp .Lf10a9b8_0010aa32\n"
        ".Lf10a9b8_0010acf8:\n"
        "movl $0, -0xb8(%ebp)\n" /* y */
        /* } scope */
        ".Lf10a9b8_0010ad02:\n"
        "movl $0, -0xbc(%ebp)\n" /* line 160 | x */
        "jmp .Lf10a9b8_0010b5b6\n"
        ".Lf10a9b8_0010ad11:\n"
        "movzwl (%esi), %ebx\n" /* line 181 | size, value */
        "movl %ebx, %edi\n" /* value */
        "andl $1, %edi\n" /* value */
        "movl %edi, -0x18(%ebp)\n" /* value */
        "sarl $1, %ebx\n" /* line 33 */
        "movw %bx, (%esi)\n"
        "movl 4(%esi), %eax\n" /* line 34 */
        "movl %eax, -0xe0(%ebp)\n"
        "movzbl (%eax), %edx\n" /* line 35 */
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movzwl 2(%esi), %ecx\n"
        "shrl %cl, %edx\n"
        "shll $0xf, %edx\n"
        "orl %edx, %ebx\n"
        "movw %bx, (%esi)\n"
        "movzwl 2(%esi), %edx\n" /* line 36 */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %edi\n"
        "movl %edi, 4(%esi)\n"
        "movl %edx, %edi\n" /* line 38 */
        "andl $7, %edi\n"
        "movw %di, 2(%esi)\n"
        /* { scope 2: bitCount, bitCount */
        "movzwl %bx, %ebx\n" /* line 50 | value */
        "movl %ebx, %esi\n" /* line 51 | value, bitCount */
        "andl $0xfff, %esi\n" /* bitCount */
        "shll $2, %esi\n" /* bitCount */
        "movzwl 0x2f7102(%esi), %eax\n" /* bitCount */
        "movw %ax, -0x7a(%ebp)\n" /* bitCount */
        /* { scope 3 */
        "movzwl %ax, %edx\n" /* line 33 */
        "movl %edx, -0xe8(%ebp)\n"
        "movl %edx, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edi, %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0xd8(%ebp), %ecx\n"
        "subl -0xe8(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %dx, (%ebx)\n"
        "movzwl -0x7a(%ebp), %ecx\n" /* line 36 | bitCount */
        "addl %edi, %ecx\n"
        "movl %ecx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %edi\n"
        "movl %edi, 4(%ebx)\n"
        "movl %ecx, %edi\n" /* line 38 */
        "andl $7, %edi\n"
        "movw %di, 2(%ebx)\n"
        /* } scope */
        "movzwl waveletDecodeRedGreen(%esi), %eax\n" /* line 52 | bitCount */
        "movswl %ax, %esi\n" /* bitCount */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010be37\n"
        /* } scope */
        ".Lf10a9b8_0010ae25:\n"
        "addl -0x38(%ebp), %esi\n" /* line 183 | size */
        "movl %esi, -0x44(%ebp)\n" /* size */
        /* { scope 2: bitCount, bitCount */
        "movl 0x10(%ebp), %eax\n" /* line 50 | decode */
        "movzwl (%eax), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2f7102(%edi), %esi\n" /* value, bitCount */
        /* { scope 3 */
        "movzwl %si, %edx\n" /* line 33 */
        "movl %edx, -0x78(%ebp)\n"
        "movl %edx, %ecx\n"
        "sarl %cl, %ebx\n"
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0xd8(%ebp), %ecx\n"
        "subl -0x78(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %ebx, 4(%ecx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeRedGreen(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %ebx\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010bdb9\n"
        /* } scope */
        ".Lf10a9b8_0010aec9:\n"
        "addl -0x3c(%ebp), %ebx\n" /* line 184 | value */
        "movl %ebx, -0x48(%ebp)\n" /* value */
        /* { scope 2: bitCount, bitCount */
        "movl 0x10(%ebp), %edi\n" /* line 50 | decode, value */
        "movzwl (%edi), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2f7102(%edi), %esi\n" /* value, bitCount */
        /* { scope 3 */
        "movzwl %si, %eax\n" /* line 33 */
        "movl %eax, -0x74(%ebp)\n"
        "movl %eax, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0xd8(%ebp), %ecx\n"
        "subl -0x74(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %ebx, 4(%ecx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeRedGreen(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %edi\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010bd40\n"
        /* } scope */
        ".Lf10a9b8_0010af6e:\n"
        "movl -0x40(%ebp), %esi\n" /* line 185 | size */
        "addl %edi, %esi\n" /* value, size */
        "movl 8(%ebp), %edi\n" /* line 186 | src, value */
        "movzbl 1(%edi), %edx\n" /* value */
        "addl %edx, %edx\n"
        "movl -0x44(%ebp), %ecx\n" /* line 187 */
        "addl %edx, %ecx\n"
        "movl -0x48(%ebp), %ebx\n" /* value */
        "addl %esi, %ebx\n" /* size, value */
        "leal (%ecx, %ebx), %eax\n"
        "sarl $1, %eax\n"
        "addb -0x18(%ebp), %al\n"
        "movl 0xc(%ebp), %edi\n" /* dst, value */
        "movb %al, 1(%edi)\n" /* value */
        "addl -0xa4(%ebp), %edi\n" /* line 188 | dstBpp, value */
        "movl %edi, -0xc8(%ebp)\n" /* value */
        "subl %ebx, %ecx\n" /* value */
        "sarl $1, %ecx\n"
        "movb %cl, 1(%edi)\n" /* value */
        "movl 0xc(%ebp), %eax\n" /* line 189 | dst */
        "addl -0xa8(%ebp), %eax\n" /* stride */
        "movl %eax, -0xc4(%ebp)\n"
        "subl -0x44(%ebp), %edx\n"
        "movl -0x48(%ebp), %ecx\n"
        "subl %esi, %ecx\n" /* size */
        "leal (%edx, %ecx), %eax\n"
        "sarl $1, %eax\n"
        "movl -0xc4(%ebp), %ebx\n" /* value */
        "movb %al, 1(%ebx)\n" /* value */
        "movl 0xc(%ebp), %esi\n" /* line 190 | dst, size */
        "addl -0xcc(%ebp), %esi\n" /* size */
        "movl %esi, -0xc0(%ebp)\n" /* size */
        "subl %ecx, %edx\n"
        "sarl $1, %edx\n"
        "movb %dl, 1(%esi)\n" /* size */
        "movl 0x10(%ebp), %edi\n" /* line 192 | decode, value */
        "movzwl (%edi), %ebx\n" /* value */
        "movl %ebx, %eax\n" /* value */
        "andl $1, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "sarl $1, %ebx\n" /* line 33 */
        "movw %bx, (%edi)\n"
        "movl 4(%edi), %edx\n" /* line 34 */
        "movl %edx, -0xe0(%ebp)\n"
        "movl %edx, %ecx\n" /* line 35 */
        "movzbl (%edx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movzwl 2(%edi), %ecx\n"
        "shrl %cl, %edx\n"
        "shll $0xf, %edx\n"
        "orl %edx, %ebx\n"
        "movw %bx, (%edi)\n"
        "movzwl 2(%edi), %edx\n" /* line 36 */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%edi)\n"
        "movl %edx, %edi\n" /* line 38 */
        "andl $7, %edi\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %di, 2(%eax)\n"
        /* { scope 2: bitCount, bitCount */
        "movzwl %bx, %ebx\n" /* line 50 | value */
        "movl %ebx, %esi\n" /* line 51 | value, bitCount */
        "andl $0xfff, %esi\n" /* bitCount */
        "shll $2, %esi\n" /* bitCount */
        "movzwl 0x2f7102(%esi), %edx\n" /* bitCount */
        "movw %dx, -0x6e(%ebp)\n" /* bitCount */
        /* { scope 3 */
        "movzwl %dx, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "sarl %cl, %ebx\n"
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edi, %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0xd8(%ebp), %ecx\n"
        "subl -0xe8(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %dx, (%ebx)\n"
        "movzwl -0x6e(%ebp), %ecx\n" /* line 36 | bitCount */
        "addl %edi, %ecx\n"
        "movl %ecx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %edi\n"
        "movl %edi, 4(%ebx)\n"
        "movl %ecx, %edi\n" /* line 38 */
        "andl $7, %edi\n"
        "movw %di, 2(%ebx)\n"
        /* } scope */
        "movzwl waveletDecodeRedGreen(%esi), %eax\n" /* line 52 | bitCount */
        "movswl %ax, %esi\n" /* bitCount */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010bcc5\n"
        /* } scope */
        ".Lf10a9b8_0010b0f9:\n"
        "addl -0x38(%ebp), %esi\n" /* line 194 | size */
        "movl %esi, -0x4c(%ebp)\n" /* size */
        /* { scope 2: bitCount, bitCount */
        "movl 0x10(%ebp), %eax\n" /* line 50 | decode */
        "movzwl (%eax), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2f7102(%edi), %esi\n" /* value, bitCount */
        /* { scope 3 */
        "movzwl %si, %edx\n" /* line 33 */
        "movl %edx, -0x6c(%ebp)\n"
        "movl %edx, %ecx\n"
        "sarl %cl, %ebx\n"
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0xd8(%ebp), %ecx\n"
        "subl -0x6c(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %ebx, 4(%ecx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeRedGreen(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %ebx\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010bc47\n"
        /* } scope */
        ".Lf10a9b8_0010b19d:\n"
        "addl -0x3c(%ebp), %ebx\n" /* line 195 | value */
        "movl %ebx, -0x50(%ebp)\n" /* value */
        /* { scope 2: bitCount, bitCount */
        "movl 0x10(%ebp), %edi\n" /* line 50 | decode, value */
        "movzwl (%edi), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2f7102(%edi), %esi\n" /* value, bitCount */
        /* { scope 3 */
        "movzwl %si, %eax\n" /* line 33 */
        "movl %eax, -0x68(%ebp)\n"
        "movl %eax, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0x68(%ebp), %ecx\n"
        "subl %ecx, -0xd8(%ebp)\n"
        "movzbl -0xd8(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %eax\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movl %eax, 4(%ebx)\n"
        "movl %esi, %ebx\n" /* line 38 */
        "andl $7, %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movw %bx, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeRedGreen(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %esi\n" /* bitCount */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010bbc9\n"
        /* } scope */
        ".Lf10a9b8_0010b24e:\n"
        "addl -0x40(%ebp), %esi\n" /* line 196 | size */
        "movl 8(%ebp), %edi\n" /* line 197 | src, value */
        "movzbl 2(%edi), %edx\n" /* value */
        "addl %edx, %edx\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 198 */
        "addl %edx, %ecx\n"
        "movl -0x50(%ebp), %ebx\n" /* value */
        "addl %esi, %ebx\n" /* size, value */
        "leal (%ecx, %ebx), %eax\n"
        "sarl $1, %eax\n"
        "addb -0x14(%ebp), %al\n"
        "movl 0xc(%ebp), %edi\n" /* dst, value */
        "movb %al, 2(%edi)\n" /* value */
        "subl %ebx, %ecx\n" /* line 199 | value */
        "sarl $1, %ecx\n"
        "movl -0xc8(%ebp), %eax\n"
        "movb %cl, 2(%eax)\n"
        "subl -0x4c(%ebp), %edx\n" /* line 200 */
        "movl -0x50(%ebp), %ecx\n"
        "subl %esi, %ecx\n" /* size */
        "leal (%edx, %ecx), %eax\n"
        "sarl $1, %eax\n"
        "movl -0xc4(%ebp), %ebx\n" /* value */
        "movb %al, 2(%ebx)\n" /* value */
        "subl %ecx, %edx\n" /* line 201 */
        "sarl $1, %edx\n"
        "movl -0xc0(%ebp), %esi\n" /* size */
        "movb %dl, 2(%esi)\n" /* size */
        "movl 0x10(%ebp), %edi\n" /* decode, value */
        ".Lf10a9b8_0010b2a5:\n"
        "cmpl $3, 0x10(%edi)\n" /* line 205 | value */
        "je .Lf10a9b8_0010b8a1\n"
        ".Lf10a9b8_0010b2af:\n"
        "movzwl (%edi), %ebx\n" /* line 207 | value */
        "movl %ebx, %eax\n" /* value */
        "andl $1, %eax\n"
        "movl %eax, -0xac(%ebp)\n" /* evenOddParity */
        "sarl $1, %ebx\n" /* line 33 */
        "movw %bx, (%edi)\n"
        "movl 4(%edi), %edx\n" /* line 34 */
        "movl %edx, -0xe0(%ebp)\n"
        "movl %edx, %ecx\n" /* line 35 */
        "movzbl (%edx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movzwl 2(%edi), %ecx\n"
        "shrl %cl, %edx\n"
        "shll $0xf, %edx\n"
        "orl %edx, %ebx\n"
        "movw %bx, (%edi)\n"
        "movzwl 2(%edi), %edx\n" /* line 36 */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%edi)\n"
        "movl %edx, %edi\n" /* line 38 */
        "andl $7, %edi\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %di, 2(%eax)\n"
        "movzwl %bx, %ebx\n" /* line 50 | value */
        "movl %ebx, %esi\n" /* line 51 | value, bitCount */
        "andl $0xfff, %esi\n" /* bitCount */
        "shll $2, %esi\n" /* bitCount */
        "movzwl 0x2f3102(%esi), %edx\n" /* bitCount */
        "movw %dx, -0x62(%ebp)\n" /* bitCount */
        /* { scope 2: bitCount, bitCount */
        "movzwl %dx, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "sarl %cl, %ebx\n"
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edi, %ecx\n"
        "shrl %cl, %edx\n"
        "movl $0x10, -0xdc(%ebp)\n"
        "movl $0x10, %ecx\n"
        "subl -0xe8(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %dx, (%ebx)\n"
        "movzwl -0x62(%ebp), %ecx\n" /* line 36 | bitCount */
        "addl %edi, %ecx\n"
        "movl %ecx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %edi\n"
        "movl %edi, 4(%ebx)\n"
        "movl %ecx, %edi\n" /* line 38 */
        "andl $7, %edi\n"
        "movw %di, 2(%ebx)\n"
        /* } scope */
        "movzwl waveletDecodeAlpha(%esi), %eax\n" /* line 52 | bitCount */
        "movswl %ax, %ecx\n"
        "movl %ecx, -0x54(%ebp)\n"
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010b8e4\n"
        ".Lf10a9b8_0010b3d2:\n"
        "movl 0x10(%ebp), %edi\n" /* line 50 | decode, value */
        "movzwl (%edi), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2f3102(%edi), %esi\n" /* value, bitCount */
        /* { scope 2: bitCount, bitCount */
        "movzwl %si, %eax\n" /* line 33 */
        "movl %eax, -0x60(%ebp)\n"
        "movl %eax, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0xdc(%ebp), %ecx\n"
        "subl -0x60(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %ebx, 4(%ecx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeAlpha(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %edi\n" /* value */
        "movl %edi, -0x58(%ebp)\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010bb29\n"
        ".Lf10a9b8_0010b474:\n"
        "movl 0x10(%ebp), %edi\n" /* line 50 | decode, value */
        "movzwl (%edi), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2f3102(%edi), %esi\n" /* value, bitCount */
        /* { scope 2: bitCount, bitCount */
        "movzwl %si, %eax\n" /* line 33 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0x5c(%ebp), %ecx\n"
        "subl %ecx, -0xdc(%ebp)\n"
        "movzbl -0xdc(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %eax\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movl %eax, 4(%ebx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ebx)\n"
        /* } scope */
        "movzwl waveletDecodeAlpha(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %edi\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010bab6\n"
        ".Lf10a9b8_0010b51a:\n"
        "movl -0xa0(%ebp), %ebx\n" /* line 212 | alpha0, value */
        "movl 8(%ebp), %esi\n" /* src, size */
        "movzbl (%ebx, %esi), %edx\n" /* value */
        "addl %edx, %edx\n"
        "movl %edx, -0xf0(%ebp)\n" /* base */
        "movl -0x54(%ebp), %ecx\n" /* line 213 */
        "addl %edx, %ecx\n"
        "movl -0x58(%ebp), %ebx\n" /* value */
        "addl %edi, %ebx\n" /* value */
        "leal (%ecx, %ebx), %eax\n"
        "sarl $1, %eax\n"
        "movzbl -0xac(%ebp), %edx\n" /* evenOddParity */
        "addb %al, %dl\n"
        "movl -0xa0(%ebp), %esi\n" /* alpha0, size */
        "movl 0xc(%ebp), %eax\n" /* dst */
        "movb %dl, (%esi, %eax)\n" /* size */
        "subl %ebx, %ecx\n" /* line 214 | value */
        "sarl $1, %ecx\n"
        "movl -0x9c(%ebp), %edx\n" /* alpha1 */
        "movb %cl, (%edx, %eax)\n"
        "movl -0xf0(%ebp), %edx\n" /* line 215 | base */
        "subl -0x54(%ebp), %edx\n"
        "movl -0x58(%ebp), %ecx\n"
        "subl %edi, %ecx\n" /* value */
        "movl -0xa8(%ebp), %ebx\n" /* stride, value */
        "addl %eax, %ebx\n" /* value */
        "leal (%edx, %ecx), %eax\n"
        "sarl $1, %eax\n"
        "movb %al, (%ebx, %esi)\n" /* value */
        "subl %ecx, %edx\n" /* line 216 */
        "sarl $1, %edx\n"
        "movl -0x9c(%ebp), %ecx\n" /* alpha1 */
        "movb %dl, (%ebx, %ecx)\n" /* value */
        ".Lf10a9b8_0010b58b:\n"
        "movl -0xa4(%ebp), %ecx\n" /* line 226 | dstBpp */
        "addl %ecx, 8(%ebp)\n" /* src */
        "movl -0xd0(%ebp), %ebx\n" /* line 227 | value */
        "addl %ebx, 0xc(%ebp)\n" /* value, dst */
        "addl $2, -0xbc(%ebp)\n" /* line 162 | x */
        "movl -0xbc(%ebp), %esi\n" /* x, size */
        "cmpl %esi, -0xb4(%ebp)\n" /* size, w */
        "jle .Lf10a9b8_0010bb9c\n"
        ".Lf10a9b8_0010b5b6:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 166 | decode, value */
        "cmpl $1, 0x10(%ebx)\n" /* value */
        "je .Lf10a9b8_0010b8dd\n"
        "movl %ebx, %esi\n" /* line 168 | value, size */
        "movzwl (%ebx), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* value */
        "andl $1, %edi\n" /* value */
        "movl %edi, -0x1c(%ebp)\n" /* value */
        "sarl $1, %ebx\n" /* line 33 */
        "movw %bx, (%esi)\n"
        "movl 4(%esi), %eax\n" /* line 34 */
        "movl %eax, -0xe0(%ebp)\n"
        "movzbl (%eax), %edx\n" /* line 35 */
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movzwl 2(%esi), %ecx\n"
        "shrl %cl, %edx\n"
        "shll $0xf, %edx\n"
        "orl %edx, %ebx\n"
        "movw %bx, (%esi)\n"
        "movzwl 2(%esi), %edx\n" /* line 36 */
        "addl $1, %edx\n"
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %edi\n"
        "movl %edi, 4(%esi)\n"
        "movl %edx, %edi\n" /* line 38 */
        "andl $7, %edi\n"
        "movw %di, 2(%esi)\n"
        "movzwl %bx, %ebx\n" /* line 50 | value */
        "movl %ebx, %esi\n" /* line 51 | value, bitCount */
        "andl $0xfff, %esi\n" /* bitCount */
        "shll $2, %esi\n" /* bitCount */
        "movzwl 0x2fb102(%esi), %eax\n" /* bitCount */
        "movw %ax, -0x86(%ebp)\n" /* bitCount */
        /* { scope 2: bitCount, bitCount */
        "movzwl %ax, %edx\n" /* line 33 */
        "movl %edx, -0xe8(%ebp)\n"
        "movl %edx, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edi, %ecx\n"
        "shrl %cl, %edx\n"
        "movl $0x10, -0xd8(%ebp)\n"
        "movl $0x10, %ecx\n"
        "subl -0xe8(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %dx, (%ebx)\n"
        "movzwl -0x86(%ebp), %ecx\n" /* line 36 | bitCount */
        "addl %edi, %ecx\n"
        "movl %ecx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %edi\n"
        "movl %edi, 4(%ebx)\n"
        "movl %ecx, %edi\n" /* line 38 */
        "andl $7, %edi\n"
        "movw %di, 2(%ebx)\n"
        /* } scope */
        "movzwl waveletDecodeBlue(%esi), %eax\n" /* line 52 | bitCount */
        "movswl %ax, %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010ba40\n"
        ".Lf10a9b8_0010b6eb:\n"
        "movl 0x10(%ebp), %edi\n" /* line 50 | decode, value */
        "movzwl (%edi), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2fb102(%edi), %esi\n" /* value, bitCount */
        /* { scope 2: bitCount, bitCount */
        "movzwl %si, %eax\n" /* line 33 */
        "movl %eax, -0x84(%ebp)\n"
        "movl %eax, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0xd8(%ebp), %ecx\n"
        "subl -0x84(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %ebx, 4(%ecx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeBlue(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %edi\n" /* value */
        "movl %edi, -0x3c(%ebp)\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010b9cd\n"
        ".Lf10a9b8_0010b793:\n"
        "movl 0x10(%ebp), %edi\n" /* line 50 | decode, value */
        "movzwl (%edi), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2fb102(%edi), %esi\n" /* value, bitCount */
        /* { scope 2: bitCount, bitCount */
        "movzwl %si, %eax\n" /* line 33 */
        "movl %eax, -0x80(%ebp)\n"
        "movl %eax, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %bx, (%eax)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl -0xd8(%ebp), %ecx\n"
        "subl -0x80(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %ebx, 4(%ecx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeBlue(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %edi\n" /* value */
        "movl %edi, -0x40(%ebp)\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "je .Lf10a9b8_0010b95a\n"
        ".Lf10a9b8_0010b835:\n"
        "movl 8(%ebp), %edi\n" /* line 173 | src, value */
        "movzbl (%edi), %edx\n" /* value */
        "addl %edx, %edx\n"
        "movl -0x38(%ebp), %ecx\n" /* line 174 */
        "addl %edx, %ecx\n"
        "movl -0x3c(%ebp), %ebx\n" /* value */
        "addl -0x40(%ebp), %ebx\n" /* value */
        "leal (%ecx, %ebx), %eax\n"
        "sarl $1, %eax\n"
        "addb -0x1c(%ebp), %al\n"
        "movl 0xc(%ebp), %esi\n" /* dst, size */
        "movb %al, (%esi)\n" /* size */
        "subl %ebx, %ecx\n" /* line 175 | value */
        "sarl $1, %ecx\n"
        "movl -0xa4(%ebp), %edi\n" /* dstBpp, value */
        "movb %cl, (%edi, %esi)\n" /* value */
        "subl -0x38(%ebp), %edx\n" /* line 176 */
        "movl -0x3c(%ebp), %ecx\n"
        "subl -0x40(%ebp), %ecx\n"
        "leal (%edx, %ecx), %eax\n"
        "sarl $1, %eax\n"
        "movl -0xa8(%ebp), %ebx\n" /* stride, value */
        "movb %al, (%esi, %ebx)\n" /* size */
        "addl %ebx, %edi\n" /* line 177 | value */
        "movl %edi, -0xcc(%ebp)\n" /* value */
        "subl %ecx, %edx\n"
        "sarl $1, %edx\n"
        "movb %dl, (%esi, %edi)\n" /* size */
        "movl 0x10(%ebp), %esi\n" /* line 179 | decode, size */
        "cmpl $2, 0x10(%esi)\n" /* size */
        "jg .Lf10a9b8_0010ad11\n"
        "movl %esi, %edi\n" /* size, value */
        "cmpl $3, 0x10(%edi)\n" /* line 205 | value */
        "jne .Lf10a9b8_0010b2af\n"
        ".Lf10a9b8_0010b8a1:\n"
        "cmpl $3, 0x14(%edi)\n" /* line 218 | value */
        "je .Lf10a9b8_0010b58b\n"
        "movl -0xa0(%ebp), %esi\n" /* line 220 | alpha0, size */
        "movl 0xc(%ebp), %edi\n" /* dst, value */
        "movb $0xff, (%esi, %edi)\n" /* size */
        "movl -0x9c(%ebp), %eax\n" /* line 221 | alpha1 */
        "movb $0xff, (%eax, %edi)\n"
        "movl -0xa8(%ebp), %eax\n" /* line 222 | stride */
        "addl %edi, %eax\n" /* value */
        "movb $0xff, (%eax, %esi)\n"
        "movl -0x9c(%ebp), %edx\n" /* line 223 | alpha1 */
        "movb $0xff, (%eax, %edx)\n"
        "jmp .Lf10a9b8_0010b58b\n"
        ".Lf10a9b8_0010b8dd:\n"
        "movl %ebx, %edi\n" /* value */
        "jmp .Lf10a9b8_0010b2a5\n"
        ".Lf10a9b8_0010b8e4:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x1ff, %eax\n"
        "subl $0xff, %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl %ecx, %esi\n" /* line 33 */
        "sarl $9, %esi\n"
        "movw %si, (%ebx)\n"
        "movl -0xe0(%ebp), %ebx\n" /* line 35 */
        "movzbl (%ebx), %edx\n"
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ebx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ebx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $7, %edx\n"
        "movl %esi, %ecx\n"
        "orl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %cx, (%ebx)\n"
        "leal 9(%edi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010b3d2\n"
        ".Lf10a9b8_0010b95a:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x1ff, %eax\n"
        "subl $0xff, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %ecx, %edi\n" /* line 33 */
        "sarl $9, %edi\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %di, (%eax)\n"
        "movzbl (%ebx), %edx\n" /* line 35 */
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ebx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ebx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $7, %edx\n"
        "movl %edi, %ecx\n"
        "orl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %cx, (%ebx)\n"
        "leal 9(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010b835\n"
        ".Lf10a9b8_0010b9cd:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x1ff, %eax\n"
        "subl $0xff, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %ecx, %edi\n" /* line 33 */
        "sarl $9, %edi\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %di, (%eax)\n"
        "movzbl (%ebx), %edx\n" /* line 35 */
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ebx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ebx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $7, %edx\n"
        "movl %edi, %ecx\n"
        "orl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %cx, (%ebx)\n"
        "leal 9(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010b793\n"
        ".Lf10a9b8_0010ba40:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x1ff, %eax\n"
        "subl $0xff, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %ecx, %esi\n" /* line 33 */
        "sarl $9, %esi\n"
        "movw %si, (%ebx)\n"
        "movl -0xe0(%ebp), %ebx\n" /* line 35 */
        "movzbl (%ebx), %edx\n"
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ebx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ebx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $7, %edx\n"
        "movl %esi, %ecx\n"
        "orl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %cx, (%ebx)\n"
        "leal 9(%edi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010b6eb\n"
        ".Lf10a9b8_0010bab6:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x1ff, %eax\n"
        "leal -0xff(%eax), %edi\n" /* value */
        "sarl $9, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movw %cx, (%ebx)\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 35 */
        "movzbl (%ecx), %edx\n"
        "movzbl 1(%ecx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $7, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movw %cx, (%ebx)\n"
        "leal 9(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl -0xe0(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010b51a\n"
        ".Lf10a9b8_0010bb29:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x1ff, %eax\n"
        "subl $0xff, %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl %ecx, %edi\n" /* line 33 */
        "sarl $9, %edi\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %di, (%eax)\n"
        "movzbl (%ebx), %edx\n" /* line 35 */
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ebx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ebx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $7, %edx\n"
        "movl %edi, %ecx\n"
        "orl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %cx, (%ebx)\n"
        "leal 9(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010b474\n"
        ".Lf10a9b8_0010bb9c:\n"
        "movl -0xa8(%ebp), %edi\n" /* line 229 | stride, value */
        "addl %edi, 0xc(%ebp)\n" /* value, dst */
        "addl $2, -0xb8(%ebp)\n" /* line 160 | y */
        "movl -0xb8(%ebp), %eax\n" /* y */
        "cmpl %eax, -0xb0(%ebp)\n" /* h */
        "jg .Lf10a9b8_0010ad02\n"
        /* } scope */
        "addl $0xe4, %esp\n" /* line 231 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: srcIndex, bitCount, bitCount */
        /* { scope 2: bitCount, bitCount */
        ".Lf10a9b8_0010bbc9:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x3ff, %eax\n"
        "leal -0x1fe(%eax), %esi\n" /* bitCount */
        "sarl $0xa, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* decode */
        "movw %cx, (%edi)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %ebx, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $6, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movw %cx, (%edi)\n"
        "leal 0xa(%ebx), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl %ebx, 4(%edi)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%edi)\n"
        "jmp .Lf10a9b8_0010b24e\n"
        /* } scope */
        /* { scope 2: bitCount, bitCount */
        ".Lf10a9b8_0010bc47:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x3ff, %eax\n"
        "leal -0x1fe(%eax), %ebx\n" /* value */
        "sarl $0xa, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* decode */
        "movw %cx, (%edi)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $6, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movw %cx, (%edi)\n"
        "leal 0xa(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%edi)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%edi)\n"
        "jmp .Lf10a9b8_0010b19d\n"
        /* } scope */
        /* { scope 2: bitCount, bitCount */
        ".Lf10a9b8_0010bcc5:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x3ff, %eax\n"
        "leal -0x1fe(%eax), %esi\n" /* bitCount */
        "sarl $0xa, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movw %cx, (%ebx)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $6, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movw %cx, (%ebx)\n"
        "leal 0xa(%edi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %edi\n"
        "movl %edi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010b0f9\n"
        /* } scope */
        /* { scope 2: bitCount, bitCount */
        ".Lf10a9b8_0010bd40:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x3ff, %eax\n"
        "leal -0x1fe(%eax), %edi\n" /* value */
        "sarl $0xa, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %cx, (%eax)\n"
        "movzbl (%ebx), %edx\n" /* line 35 */
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ebx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ebx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $6, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %cx, (%ebx)\n"
        "leal 0xa(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010af6e\n"
        /* } scope */
        /* { scope 2: bitCount, bitCount */
        ".Lf10a9b8_0010bdb9:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x3ff, %eax\n"
        "leal -0x1fe(%eax), %ebx\n" /* value */
        "sarl $0xa, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* decode */
        "movw %cx, (%edi)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $6, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movw %cx, (%edi)\n"
        "leal 0xa(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%edi)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%edi)\n"
        "jmp .Lf10a9b8_0010aec9\n"
        /* } scope */
        /* { scope 2: bitCount, bitCount */
        ".Lf10a9b8_0010be37:\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x3ff, %eax\n"
        "leal -0x1fe(%eax), %esi\n" /* bitCount */
        "sarl $0xa, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movw %cx, (%ebx)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %edi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $6, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movw %cx, (%ebx)\n"
        "leal 0xa(%edi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %edi\n"
        "movl %edi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010ae25\n"
        /* } scope */
        ".Lf10a9b8_0010beb2:\n"
        "movl -0xb4(%ebp), %edx\n" /* line 122 | w */
        "testl %edx, %edx\n"
        "movl $1, %eax\n"
        "cmovgl -0xb4(%ebp), %eax\n" /* w */
        "movl %eax, -0xb4(%ebp)\n" /* w */
        "movl %eax, %edi\n" /* value */
        ".Lf10a9b8_0010bece:\n"
        "movl -0xb0(%ebp), %eax\n" /* line 124 | h */
        "testl %eax, %eax\n"
        "movl $1, %eax\n"
        "cmovgl -0xb0(%ebp), %eax\n" /* h */
        "leal -1(%edi, %eax), %esi\n" /* line 127 | value, size */
        "xorl %ebx, %ebx\n" /* value */
        ".Lf10a9b8_0010bee8:\n"
        "movl 0x10(%ebp), %edx\n" /* line 131 | decode */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf10a9b8_0010bf22\n"
        "xorl %ecx, %ecx\n"
        "movl 0x10(%ebp), %edi\n" /* decode, value */
        "jmp .Lf10a9b8_0010befb\n"
        ".Lf10a9b8_0010bef9:\n"
        "movl %edx, %edi\n" /* value */
        ".Lf10a9b8_0010befb:\n"
        "movl 4(%edi), %edx\n" /* line 132 | value */
        "movzbl (%edx), %eax\n"
        "movl 0xc(%ebp), %edi\n" /* dst, value */
        "movb %al, (%edi)\n" /* value */
        "addl $1, %edi\n" /* value */
        "movl %edi, 0xc(%ebp)\n" /* value, dst */
        "addl $1, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movl %edx, 4(%eax)\n"
        "addl $1, %ecx\n" /* line 131 */
        "movl 0x10(%ebp), %edx\n" /* decode */
        "movl 0x10(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jl .Lf10a9b8_0010bef9\n"
        ".Lf10a9b8_0010bf22:\n"
        "cmpl %eax, 0x14(%edx)\n" /* line 133 */
        "je .Lf10a9b8_0010bf33\n"
        "movl 0xc(%ebp), %edi\n" /* line 134 | dst, value */
        "movb $0xff, (%edi)\n" /* value */
        "addl $1, %edi\n" /* value */
        "movl %edi, 0xc(%ebp)\n" /* value, dst */
        ".Lf10a9b8_0010bf33:\n"
        "addl $1, %ebx\n" /* value */
        "cmpl %ebx, %esi\n" /* line 129 | value, size */
        "jne .Lf10a9b8_0010bee8\n"
        /* } scope */
        "addl $0xe4, %esp\n" /* line 231 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf10a9b8_0010bf45:\n"
        "movl -0xb4(%ebp), %edi\n" /* w, value */
        "jmp .Lf10a9b8_0010bece\n"
        /* { scope 1: srcIndex, bitCount, bitCount */
        /* { scope 2: bitCount, bitCount */
        ".Lf10a9b8_0010bf4d:\n"
        "imull -0xa4(%ebp), %eax\n" /* line 70 | dstBpp */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x94(%ebp)\n" /* srcIndex */
        "jmp .Lf10a9b8_0010bf90\n"
        ".Lf10a9b8_0010bf63:\n"
        "movzbl -0x21(%ebp), %eax\n" /* line 73 */
        "addl %edi, %eax\n" /* value */
        "movl -0x34(%ebp), %edi\n" /* value */
        "movb %al, (%edi)\n" /* value */
        "addl $1, -0x94(%ebp)\n" /* line 74 | srcIndex */
        "movl -0x94(%ebp), %eax\n" /* line 71 | srcIndex */
        "cmpl %eax, -0x20(%ebp)\n"
        "je .Lf10a9b8_0010acf8\n"
        "movl 0x10(%ebp), %esi\n" /* decode, bitCount */
        "movl 4(%esi), %esi\n" /* bitCount */
        "movl %esi, -0xe0(%ebp)\n" /* bitCount */
        ".Lf10a9b8_0010bf90:\n"
        "movl 8(%ebp), %edi\n" /* line 98 | src, value */
        "addl -0x94(%ebp), %edi\n" /* srcIndex, value */
        "movl %edi, -0x34(%ebp)\n" /* value */
        "movzbl (%edi), %eax\n" /* line 73 | value */
        "movb %al, -0x21(%ebp)\n"
        /* { scope 3 */
        "movl 0x10(%ebp), %edx\n" /* line 50 | decode */
        "movzwl (%edx), %ebx\n" /* value */
        "movl %ebx, %edi\n" /* line 51 | value */
        "andl $0xfff, %edi\n" /* value */
        "shll $2, %edi\n" /* value */
        "movzwl 0x2f3102(%edi), %esi\n" /* value, bitCount */
        /* { scope 4 */
        "movzwl %si, %ecx\n" /* line 33 */
        "movl %ecx, -0x90(%ebp)\n"
        "sarl %cl, %ebx\n"
        "movw %bx, (%edx)\n"
        "movl -0xe0(%ebp), %eax\n" /* line 35 */
        "movzbl (%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movzbl 1(%eax), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ecx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ecx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movzwl 2(%eax), %ecx\n"
        "shrl %cl, %edx\n"
        "movl $0x10, %ecx\n"
        "subl -0x90(%ebp), %ecx\n"
        "shll %cl, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, (%eax)\n"
        "addw 2(%eax), %si\n" /* line 36 */
        "movl %esi, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* decode */
        "movl %ebx, 4(%ecx)\n"
        "andl $7, %esi\n" /* line 38 */
        "movw %si, 2(%ecx)\n"
        /* } scope */
        "movzwl waveletDecodeAlpha(%edi), %eax\n" /* line 52 | value */
        "movswl %ax, %edi\n" /* value */
        "cmpw $0x8000, %ax\n" /* line 53 */
        "jne .Lf10a9b8_0010bf63\n"
        "movzwl %dx, %ecx\n" /* line 55 */
        "movl %ecx, %eax\n"
        "andl $0x1ff, %eax\n"
        "leal -0xff(%eax), %edi\n" /* value */
        "sarl $9, %ecx\n" /* line 33 */
        "movl %ecx, -0xe8(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* decode */
        "movw %cx, (%eax)\n"
        "movzbl (%ebx), %edx\n" /* line 35 */
        "movzbl 1(%ebx), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 2(%ebx), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %edx\n"
        "movzbl 3(%ebx), %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %edx\n"
        "movl %esi, %ecx\n"
        "shrl %cl, %edx\n"
        "shll $7, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "orl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* decode */
        "movw %cx, (%ebx)\n"
        "leal 9(%esi), %edx\n" /* line 36 */
        "movl %edx, %eax\n" /* line 37 */
        "shrw $3, %ax\n"
        "movzwl %ax, %eax\n"
        "addl %eax, -0xe0(%ebp)\n"
        "movl -0xe0(%ebp), %esi\n"
        "movl %esi, 4(%ebx)\n"
        "andl $7, %edx\n" /* line 38 */
        "movw %dx, 2(%ebx)\n"
        "jmp .Lf10a9b8_0010bf63\n"
    );
}

