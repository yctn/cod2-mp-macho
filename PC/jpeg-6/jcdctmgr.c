/* ASM dump from: jcdctmgr.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcdctmgr.c */

#include "common_types.h"
#include "imports.h"

static const INT16 aanscales[64]; /* 0x3075a0 */
static const double aanscalefactor[8]; /* 0x307560 */

static void start_pass_fdctmgr(j_compress_ptr cinfo);
static void forward_DCT(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY sample_data, JBLOCKROW coef_blocks, JDIMENSION start_row, JDIMENSION start_col, JDIMENSION num_blocks);
static void forward_DCT_float(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY sample_data, JBLOCKROW coef_blocks, JDIMENSION start_row, JDIMENSION start_col, JDIMENSION num_blocks);
void jinit_forward_dct(j_compress_ptr cinfo);

/* line 55 */
static __attribute__((naked))
void start_pass_fdctmgr(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 56 | cinfo */
        "movl 0x15c(%eax), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* fdct */
        "movl 8(%ebp), %edx\n" /* line 62 | cinfo */
        "movl 0x48(%edx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* compptr */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x40(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20dfe4_0020e0c8\n"
        "movl $0, -0x34(%ebp)\n" /* ci */
        "leal 0xf95ae(%ebx), %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "jmp .Lf20dfe4_0020e056\n"
        ".Lf20dfe4_0020e027:\n"
        "cmpl $2, %eax\n" /* line 72 */
        "je .Lf20dfe4_0020e151\n"
        "movl 8(%ebp), %edx\n" /* line 164 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x30, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20dfe4_0020e043:\n"
        "addl $1, -0x34(%ebp)\n" /* line 63 | ci */
        "addl $0x54, -0x2c(%ebp)\n" /* compptr */
        "movl -0x34(%ebp), %edx\n" /* line 62 | ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x40(%eax), %edx\n"
        "jge .Lf20dfe4_0020e0c8\n"
        ".Lf20dfe4_0020e056:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 64 | compptr */
        "movl 0x10(%eax), %esi\n" /* qtblno */
        "cmpl $3, %esi\n" /* line 66 | qtblno */
        "ja .Lf20dfe4_0020e0d0\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x4c(%edx, %esi, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf20dfe4_0020e0d3\n"
        "movl %edx, %eax\n"
        "movl 0x4c(%eax, %esi, 4), %eax\n" /* line 69 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 72 | cinfo */
        "movl 0xbc(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf20dfe4_0020e100\n"
        ".Lf20dfe4_0020e083:\n"
        "jae .Lf20dfe4_0020e027\n"
        "movl -0x38(%ebp), %eax\n" /* line 78 | fdct */
        "movl 0xc(%eax, %esi, 4), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf20dfe4_0020e1f1\n"
        ".Lf20dfe4_0020e094:\n"
        "movl 0xc(%eax, %esi, 4), %esi\n" /* line 83 | qtblno */
        "movl -0x1c(%ebp), %edx\n"
        "movl $1, %ecx\n"
        ".Lf20dfe4_0020e0a0:\n"
        "movzwl (%edx), %eax\n" /* line 85 */
        "shll $3, %eax\n"
        "movl %eax, -4(%esi, %ecx, 4)\n" /* qtblno */
        "addl $1, %ecx\n"
        "addl $2, %edx\n"
        "cmpl $0x41, %ecx\n" /* line 84 */
        "jne .Lf20dfe4_0020e0a0\n"
        "addl $1, -0x34(%ebp)\n" /* line 63 | ci */
        "addl $0x54, -0x2c(%ebp)\n" /* compptr */
        "movl -0x34(%ebp), %edx\n" /* line 62 | ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x40(%eax), %edx\n"
        "jl .Lf20dfe4_0020e056\n"
        ".Lf20dfe4_0020e0c8:\n"
        "addl $0x4c, %esp\n" /* line 168 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20dfe4_0020e0d0:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        ".Lf20dfe4_0020e0d3:\n"
        "movl (%edx), %eax\n" /* line 68 */
        "movl $0x34, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* qtblno */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x4c(%eax, %esi, 4), %eax\n" /* line 69 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 72 | cinfo */
        "movl 0xbc(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jne .Lf20dfe4_0020e083\n"
        /* { scope 2 */
        ".Lf20dfe4_0020e100:\n"
        "movl -0x38(%ebp), %edx\n" /* line 112 | fdct */
        "movl 0xc(%edx, %esi, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf20dfe4_0020e21b\n"
        "movl %edx, %eax\n"
        ".Lf20dfe4_0020e111:\n"
        "movl 0xc(%eax, %esi, 4), %esi\n" /* line 117 | qtblno */
        "movl %esi, -0x28(%ebp)\n" /* qtblno, dtbl */
        "movl -0x1c(%ebp), %ecx\n"
        "movl $1, %esi\n" /* qtblno */
        "leal 0xf95ae(%ebx), %edi\n"
        ".Lf20dfe4_0020e126:\n"
        "movzwl (%ecx), %eax\n" /* line 119 */
        "movswl (%edi), %edx\n"
        "imull %edx, %eax\n"
        "addl $0x400, %eax\n"
        "sarl $0xb, %eax\n"
        "movl -0x28(%ebp), %edx\n" /* dtbl */
        "movl %eax, -4(%edx, %esi, 4)\n"
        "addl $1, %esi\n" /* qtblno */
        "addl $2, %ecx\n"
        "addl $2, %edi\n"
        "cmpl $0x41, %esi\n" /* line 118 | qtblno */
        "jne .Lf20dfe4_0020e126\n"
        "jmp .Lf20dfe4_0020e043\n"
        /* } scope */
        /* { scope 2 */
        ".Lf20dfe4_0020e151:\n"
        "movl -0x38(%ebp), %eax\n" /* line 145 | fdct */
        "movl 0x20(%eax, %esi, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf20dfe4_0020e245\n"
        ".Lf20dfe4_0020e160:\n"
        "movl 0x20(%eax, %esi, 4), %edi\n" /* line 146 */
        "movl $0, -0x30(%ebp)\n" /* i */
        "leal 0xf956e(%ebx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl %edx, -0x3c(%ebp)\n"
        "leal 0xf9e26(%ebx), %eax\n" /* 8.0 */
        "movsd (%eax), %xmm3\n"
        "leal 0xf9c1e(%ebx), %edx\n" /* 1.0 */
        "movsd (%edx), %xmm2\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        ".Lf20dfe4_0020e191:\n"
        "movl -0x30(%ebp), %edx\n" /* i */
        "movl -0x1c(%ebp), %eax\n"
        "leal (%eax, %edx, 2), %ecx\n"
        "movl %edi, %edx\n"
        "movl -0x3c(%ebp), %esi\n" /* qtblno */
        "movl -0x20(%ebp), %eax\n"
        "movsd (%eax), %xmm1\n"
        ".Lf20dfe4_0020e1a6:\n"
        "movzwl (%ecx), %eax\n" /* line 154 */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "mulsd (%esi), %xmm0\n" /* qtblno */
        "mulsd %xmm3, %xmm0\n"
        "movapd %xmm2, %xmm4\n"
        "divsd %xmm0, %xmm4\n"
        "cvtsd2ss %xmm4, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $2, %ecx\n"
        "addl $8, %esi\n" /* qtblno */
        "addl $4, %edx\n"
        "cmpl -0x24(%ebp), %esi\n" /* line 153 | qtblno */
        "jne .Lf20dfe4_0020e1a6\n"
        "movl -0x30(%ebp), %eax\n" /* line 55 | i */
        "addl $8, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* i */
        "addl $0x20, %edi\n"
        "addl $8, -0x20(%ebp)\n"
        "cmpl $0x40, %eax\n" /* line 152 */
        "jne .Lf20dfe4_0020e191\n"
        "jmp .Lf20dfe4_0020e043\n"
        /* } scope */
        ".Lf20dfe4_0020e1f1:\n"
        "movl 8(%ebp), %edx\n" /* line 79 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x100, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* fdct */
        "movl %eax, 0xc(%edx, %esi, 4)\n"
        "movl -0x38(%ebp), %eax\n" /* fdct */
        "jmp .Lf20dfe4_0020e094\n"
        /* { scope 2 */
        ".Lf20dfe4_0020e21b:\n"
        "movl 8(%ebp), %edx\n" /* line 113 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x100, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* fdct */
        "movl %eax, 0xc(%edx, %esi, 4)\n"
        "movl -0x38(%ebp), %eax\n" /* fdct */
        "jmp .Lf20dfe4_0020e111\n"
        /* } scope */
        /* { scope 2 */
        ".Lf20dfe4_0020e245:\n"
        "movl 8(%ebp), %edx\n" /* line 146 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x100, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* fdct */
        "movl %eax, 0x20(%edx, %esi, 4)\n"
        "movl -0x38(%ebp), %eax\n" /* fdct */
        "jmp .Lf20dfe4_0020e160\n"
    );
}

/* line 185 */
static __attribute__((naked))
void forward_DCT(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY sample_data, JBLOCKROW coef_blocks, JDIMENSION start_row, JDIMENSION start_col, JDIMENSION num_blocks)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 185 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x130, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 187 | cinfo */
        "movl 0x15c(%eax), %edx\n" /* fdct */
        "movl 8(%edx), %eax\n" /* line 188 */
        "movl %eax, -0x118(%ebp)\n" /* do_dct */
        "movl 0xc(%ebp), %eax\n" /* line 189 | compptr */
        "movl 0x10(%eax), %eax\n"
        "movl 0xc(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x114(%ebp)\n" /* divisors */
        "movl 0x18(%ebp), %ecx\n" /* line 193 | start_row */
        "shll $2, %ecx\n"
        "movl 0x10(%ebp), %eax\n" /* sample_data */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x10c(%ebp)\n"
        "movl 0x20(%ebp), %eax\n" /* line 195 | num_blocks */
        "testl %eax, %eax\n"
        "je .Lf20e26f_0020e3cc\n"
        "movl 0x14(%ebp), %edi\n" /* coef_blocks */
        "movl $0, -0x110(%ebp)\n" /* bi */
        "leal -0xe8(%ebp), %ecx\n"
        "movl %ecx, -0x11c(%ebp)\n"
        "leal -0x108(%ebp), %eax\n" /* workspace */
        "movl %eax, -0x120(%ebp)\n"
        ".Lf20e26f_0020e2dd:\n"
        "movl $1, %esi\n"
        /* { scope 2 */
        ".Lf20e26f_0020e2e2:\n"
        "movl 0x1c(%ebp), %edx\n" /* line 203 | start_col */
        "movl -0x10c(%ebp), %eax\n"
        "addl -4(%eax, %esi, 4), %edx\n"
        "movzbl (%edx), %eax\n" /* line 205 */
        "addl $-0x80, %eax\n"
        "movl %eax, -0x20(%ecx)\n"
        "movzbl 1(%edx), %eax\n" /* line 206 */
        "addl $-0x80, %eax\n"
        "movl %eax, -0x1c(%ecx)\n"
        "movzbl 2(%edx), %eax\n" /* line 207 */
        "addl $-0x80, %eax\n"
        "movl %eax, -0x18(%ecx)\n"
        "movzbl 3(%edx), %eax\n" /* line 208 */
        "addl $-0x80, %eax\n"
        "movl %eax, -0x14(%ecx)\n"
        "movzbl 4(%edx), %eax\n" /* line 209 */
        "addl $-0x80, %eax\n"
        "movl %eax, -0x10(%ecx)\n"
        "movzbl 5(%edx), %eax\n" /* line 210 */
        "addl $-0x80, %eax\n"
        "movl %eax, -0xc(%ecx)\n"
        "movzbl 6(%edx), %eax\n" /* line 211 */
        "addl $-0x80, %eax\n"
        "movl %eax, -8(%ecx)\n"
        "movzbl 7(%edx), %eax\n" /* line 212 */
        "addl $-0x80, %eax\n"
        "movl %eax, -4(%ecx)\n"
        "addl $0x20, %ecx\n"
        "addl $1, %esi\n"
        "cmpl $9, %esi\n" /* line 202 */
        "jne .Lf20e26f_0020e2e2\n"
        /* } scope */
        "movl -0x120(%ebp), %ecx\n" /* line 224 */
        "movl %ecx, (%esp)\n"
        "calll *-0x118(%ebp)\n" /* do_dct */
        "movw $1, %si\n"
        /* { scope 2 */
        ".Lf20e26f_0020e35c:\n"
        "movl -0x114(%ebp), %eax\n" /* line 232 | divisors */
        "movl -4(%eax, %esi, 4), %edx\n"
        "movl -0x120(%ebp), %eax\n" /* line 233 */
        "movl -4(%eax, %esi, 4), %ecx\n"
        "testl %ecx, %ecx\n" /* line 251 */
        "js .Lf20e26f_0020e3b9\n"
        "movl %edx, %eax\n" /* line 257 */
        "sarl $1, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "cmpl %eax, %edx\n" /* line 258 */
        "jle .Lf20e26f_0020e3b2\n"
        ".Lf20e26f_0020e37f:\n"
        "xorl %eax, %eax\n"
        ".Lf20e26f_0020e381:\n"
        "movw %ax, -2(%edi, %esi, 2)\n" /* line 260 */
        "addl $1, %esi\n"
        "cmpl $0x41, %esi\n" /* line 231 */
        "jne .Lf20e26f_0020e35c\n"
        /* } scope */
        "addl $1, -0x110(%ebp)\n" /* line 195 | bi */
        "addl $8, 0x1c(%ebp)\n" /* start_col */
        "subl $-0x80, %edi\n"
        "movl -0x110(%ebp), %eax\n" /* bi */
        "cmpl %eax, 0x20(%ebp)\n" /* num_blocks */
        "je .Lf20e26f_0020e3cc\n"
        "movl -0x11c(%ebp), %ecx\n"
        "jmp .Lf20e26f_0020e2dd\n"
        /* { scope 2 */
        ".Lf20e26f_0020e3b2:\n"
        "movl %edx, %ecx\n" /* line 258 */
        "cltd\n"
        "idivl %ecx\n"
        "jmp .Lf20e26f_0020e381\n"
        ".Lf20e26f_0020e3b9:\n"
        "movl %edx, %eax\n" /* line 253 */
        "sarl $1, %eax\n"
        "subl %ecx, %eax\n"
        "cmpl %eax, %edx\n" /* line 254 */
        "jg .Lf20e26f_0020e37f\n"
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "negl %eax\n"
        "jmp .Lf20e26f_0020e381\n"
        /* } scope */
        ".Lf20e26f_0020e3cc:\n"
        "addl $0x130, %esp\n" /* line 264 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 275 */
static __attribute__((naked))
void forward_DCT_float(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY sample_data, JBLOCKROW coef_blocks, JDIMENSION start_row, JDIMENSION start_col, JDIMENSION num_blocks)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 275 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 277 | cinfo */
        "movl 0x15c(%eax), %edx\n" /* fdct */
        "movl 0x1c(%edx), %eax\n" /* line 278 */
        "movl %eax, -0x128(%ebp)\n" /* do_dct */
        "movl 0xc(%ebp), %eax\n" /* line 279 | compptr */
        "movl 0x10(%eax), %eax\n"
        "movl 0x20(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x13c(%ebp)\n" /* divisors */
        "movl 0x18(%ebp), %edi\n" /* line 283 | start_row */
        "shll $2, %edi\n"
        "movl 0x10(%ebp), %eax\n" /* sample_data */
        "addl %eax, %edi\n"
        "movl %edi, -0x11c(%ebp)\n"
        "movl 0x20(%ebp), %eax\n" /* line 285 | num_blocks */
        "testl %eax, %eax\n"
        "je .Lf20e3d6_0020e570\n"
        "movl 0x14(%ebp), %esi\n" /* coef_blocks */
        "movl $0, -0x124(%ebp)\n" /* bi */
        "leal -0xf8(%ebp), %edi\n"
        "movl %edi, -0x12c(%ebp)\n"
        "leal -0x118(%ebp), %eax\n" /* workspace */
        "movl %eax, -0x130(%ebp)\n"
        "movl %edi, %ecx\n"
        ".Lf20e3d6_0020e44c:\n"
        "movl $1, -0x120(%ebp)\n"
        "movl -0x120(%ebp), %edi\n"
        /* { scope 2 */
        ".Lf20e3d6_0020e45c:\n"
        "movl 0x1c(%ebp), %edx\n" /* line 293 | start_col */
        "movl -0x11c(%ebp), %eax\n"
        "addl -4(%eax, %edi, 4), %edx\n"
        "movzbl (%edx), %eax\n" /* line 295 */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x20(%ecx)\n"
        "movzbl 1(%edx), %eax\n" /* line 296 */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x1c(%ecx)\n"
        "movzbl 2(%edx), %eax\n" /* line 297 */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x18(%ecx)\n"
        "movzbl 3(%edx), %eax\n" /* line 298 */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x14(%ecx)\n"
        "movzbl 4(%edx), %eax\n" /* line 299 */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x10(%ecx)\n"
        "movzbl 5(%edx), %eax\n" /* line 300 */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0xc(%ecx)\n"
        "movzbl 6(%edx), %eax\n" /* line 301 */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -8(%ecx)\n"
        "movzbl 7(%edx), %eax\n" /* line 302 */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -4(%ecx)\n"
        "addl $0x20, %ecx\n"
        "addl $1, %edi\n"
        "movl %edi, -0x120(%ebp)\n"
        "cmpl $9, %edi\n" /* line 292 */
        "jne .Lf20e3d6_0020e45c\n"
        /* } scope */
        "movl -0x130(%ebp), %edi\n" /* line 315 */
        "movl %edi, (%esp)\n"
        "calll *-0x128(%ebp)\n" /* do_dct */
        "movl $1, %edx\n"
        "leal 0xdf6e9(%ebx), %eax\n" /* 16384.5f */
        "movss (%eax), %xmm1\n"
        ".Lf20e3d6_0020e51b:\n"
        "movl -0x130(%ebp), %edi\n" /* line 331 */
        "movss -4(%edi, %edx, 4), %xmm0\n"
        "movl -0x13c(%ebp), %eax\n" /* divisors */
        "mulss -4(%eax, %edx, 4), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "subw $0x4000, %ax\n"
        "movw %ax, -2(%esi, %edx, 2)\n"
        "addl $1, %edx\n"
        "cmpl $0x41, %edx\n" /* line 322 */
        "jne .Lf20e3d6_0020e51b\n"
        "addl $1, -0x124(%ebp)\n" /* line 285 | bi */
        "addl $8, 0x1c(%ebp)\n" /* start_col */
        "subl $-0x80, %esi\n"
        "movl -0x124(%ebp), %edi\n" /* bi */
        "cmpl %edi, 0x20(%ebp)\n" /* num_blocks */
        "je .Lf20e3d6_0020e570\n"
        "movl -0x12c(%ebp), %ecx\n"
        "jmp .Lf20e3d6_0020e44c\n"
        ".Lf20e3d6_0020e570:\n"
        "addl $0x14c, %esp\n" /* line 335 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 346 */
__attribute__((naked))
void jinit_forward_dct(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 346 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 4(%edi), %eax\n" /* line 350 | cinfo */
        "movl $0x30, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, %esi\n" /* fdct */
        "movl %eax, 0x15c(%edi)\n" /* line 353 | cinfo */
        "leal -0x5a5(%ebx), %eax\n" /* line 354 */
        "movl %eax, (%esi)\n" /* fdct */
        "movl 0xbc(%edi), %eax\n" /* line 356 | cinfo */
        "cmpl $1, %eax\n"
        "je .Lf20e57b_0020e60f\n"
        "jb .Lf20e57b_0020e5fb\n"
        "cmpl $2, %eax\n"
        "je .Lf20e57b_0020e623\n"
        "movl (%edi), %eax\n" /* line 376 | cinfo */
        "movl $0x30, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf20e57b_0020e5d6:\n"
        "movl %esi, %eax\n" /* fdct */
        "movl $4, %edx\n"
        ".Lf20e57b_0020e5dd:\n"
        "movl $0, 0xc(%eax)\n" /* line 382 */
        "movl $0, 0x20(%eax)\n" /* line 384 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 381 */
        "jne .Lf20e57b_0020e5dd\n"
        "addl $0x1c, %esp\n" /* line 387 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20e57b_0020e5fb:\n"
        "leal -0x31a(%ebx), %eax\n" /* line 359 */
        "movl %eax, 4(%esi)\n" /* fdct */
        "movl 0x1751463(%ebx), %eax\n" /* line 360 */
        "movl %eax, 8(%esi)\n" /* fdct */
        "jmp .Lf20e57b_0020e5d6\n"
        ".Lf20e57b_0020e60f:\n"
        "leal -0x31a(%ebx), %eax\n" /* line 365 */
        "movl %eax, 4(%esi)\n" /* fdct */
        "movl 0x175145f(%ebx), %eax\n" /* line 366 */
        "movl %eax, 8(%esi)\n" /* fdct */
        "jmp .Lf20e57b_0020e5d6\n"
        ".Lf20e57b_0020e623:\n"
        "leal -0x1b3(%ebx), %eax\n" /* line 371 */
        "movl %eax, 4(%esi)\n" /* fdct */
        "movl 0x175145b(%ebx), %eax\n" /* line 372 */
        "movl %eax, 0x1c(%esi)\n" /* fdct */
        "jmp .Lf20e57b_0020e5d6\n"
    );
}

