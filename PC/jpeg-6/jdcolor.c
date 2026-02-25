/* ASM dump from: jdcolor.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdcolor.c */

#include "common_types.h"
#include "imports.h"

static void build_ycc_rgb_table(void);
static void ycc_rgb_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows);
static void null_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows);
static void grayscale_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows);
static void gray_rgb_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows);
static void ycck_cmyk_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows);
static void start_pass_dcolor(j_decompress_ptr cinfo);
void jinit_color_deconverter(j_decompress_ptr cinfo);

/* line 71 */
static __attribute__((naked))
void build_ycc_rgb_table(void)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl %eax, %esi\n" /* cinfo */
        "movl 0x1ac(%eax), %edi\n" /* line 72 | cconvert */
        "movl 4(%eax), %eax\n" /* line 77 */
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 8(%edi)\n" /* cconvert */
        "movl 4(%esi), %eax\n" /* line 80 | cinfo */
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0xc(%edi)\n" /* cconvert */
        "movl 4(%esi), %eax\n" /* line 83 | cinfo */
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x10(%edi)\n" /* cconvert */
        "movl 4(%esi), %eax\n" /* line 86 | cinfo */
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x14(%edi)\n" /* cconvert */
        "xorl %ecx, %ecx\n"
        "movl $0xff4d0b80, -0x14(%ebp)\n"
        "movl $0xff1daf00, -0x10(%ebp)\n"
        "movl $0x5b6900, -0xc(%ebp)\n"
        "movl $__Z13FS_CreatePathPc.eh, %esi\n" /* cinfo */
        ".Lf2046b8_00204750:\n"
        "movl 8(%edi), %edx\n" /* line 94 | cconvert */
        "movl -0x14(%ebp), %eax\n"
        "sarl $0x10, %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "movl 0xc(%edi), %edx\n" /* line 97 | cconvert */
        "movl -0x10(%ebp), %eax\n"
        "sarl $0x10, %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "movl 0x10(%edi), %eax\n" /* line 100 | cconvert */
        "movl -0xc(%ebp), %edx\n"
        "movl %edx, (%eax, %ecx)\n"
        "movl 0x14(%edi), %eax\n" /* line 103 | cconvert */
        "movl %esi, (%eax, %ecx)\n" /* cinfo */
        "addl $4, %ecx\n"
        "addl $0x166e9, -0x14(%ebp)\n"
        "addl $0x1c5a2, -0x10(%ebp)\n"
        "subl $0xb6d2, %edx\n"
        "movl %edx, -0xc(%ebp)\n"
        "subl $0x581a, %esi\n" /* cinfo */
        "cmpl $0x400, %ecx\n" /* line 90 */
        "jne .Lf2046b8_00204750\n"
        "addl $0x20, %esp\n" /* line 105 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 123 */
static __attribute__((naked))
void ycc_rgb_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 123 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x38, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x1ac(%edx), %eax\n" /* line 124 | cconvert */
        "movl 0x64(%edx), %ecx\n" /* line 129 */
        "movl %ecx, -0x24(%ebp)\n" /* num_cols */
        "movl 0x128(%edx), %edx\n" /* line 131 */
        "movl %edx, -0x20(%ebp)\n" /* range_limit */
        "movl 8(%eax), %esi\n" /* line 132 | cb */
        "movl %esi, -0x1c(%ebp)\n" /* cb, Crrtab */
        "movl 0xc(%eax), %edx\n" /* line 133 */
        "movl %edx, -0x18(%ebp)\n" /* Cbbtab */
        "movl 0x10(%eax), %ecx\n" /* line 134 */
        "movl %ecx, -0x14(%ebp)\n" /* Crgtab */
        "movl 0x14(%eax), %eax\n" /* line 135 */
        "movl %eax, -0x10(%ebp)\n" /* Cbgtab */
        "movl 0x10(%ebp), %esi\n" /* input_row, cb */
        "shll $2, %esi\n" /* cb */
        "movl %esi, -0xc(%ebp)\n" /* cb */
        "subl $1, 0x18(%ebp)\n" /* line 138 | num_rows */
        "js .Lf2047a6_002048aa\n"
        ".Lf2047a6_002047f1:\n"
        "movl 0xc(%ebp), %edx\n" /* line 139 | input_buf */
        "movl (%edx), %eax\n"
        "movl -0xc(%ebp), %ecx\n"
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* inptr0 */
        "movl 4(%edx), %eax\n" /* line 140 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* inptr1 */
        "movl 8(%edx), %eax\n" /* line 141 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* inptr2 */
        "movl 0x14(%ebp), %esi\n" /* line 143 | output_buf, cb */
        "movl (%esi), %edi\n" /* cb, outptr */
        "addl $4, %esi\n" /* cb */
        "movl %esi, 0x14(%ebp)\n" /* cb, output_buf */
        "movl -0x24(%ebp), %eax\n" /* line 144 | num_cols */
        "testl %eax, %eax\n"
        "je .Lf2047a6_0020489c\n"
        "movl $0, -0x28(%ebp)\n" /* col */
        "movl -0x28(%ebp), %edx\n" /* col */
        "jmp .Lf2047a6_00204831\n"
        ".Lf2047a6_0020482f:\n"
        "movl %ecx, %edx\n"
        ".Lf2047a6_00204831:\n"
        "movl -0x34(%ebp), %eax\n" /* line 145 | inptr0 */
        "movzbl (%eax, %edx), %ecx\n"
        "movl -0x30(%ebp), %eax\n" /* line 146 | inptr1 */
        "movzbl (%eax, %edx), %esi\n" /* cb */
        "movl -0x2c(%ebp), %eax\n" /* line 149 | inptr2 */
        "movzbl (%eax, %edx), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n" /* Crrtab */
        "movl (%edx, %eax), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "addl -0x20(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %edx), %eax\n"
        "movb %al, 2(%edi)\n" /* outptr */
        "shll $2, %esi\n" /* line 150 | cb */
        "movl %esi, -0x40(%ebp)\n" /* cb */
        "movl -0x10(%ebp), %edx\n" /* Cbgtab */
        "movl (%edx, %esi), %eax\n"
        "movl -0x14(%ebp), %esi\n" /* Crgtab, cb */
        "movl -0x38(%ebp), %edx\n"
        "addl (%esi, %edx), %eax\n" /* cb */
        "sarl $0x10, %eax\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movb %al, 1(%edi)\n" /* outptr */
        "movl -0x18(%ebp), %esi\n" /* line 153 | Cbbtab, cb */
        "movl -0x40(%ebp), %edx\n"
        "movl (%esi, %edx), %eax\n" /* cb */
        "movzbl (%ecx, %eax), %eax\n"
        "movb %al, (%edi)\n" /* outptr */
        "addl $3, %edi\n" /* line 154 | outptr */
        "addl $1, -0x28(%ebp)\n" /* line 144 | col */
        "movl -0x28(%ebp), %ecx\n" /* col */
        "cmpl %ecx, -0x24(%ebp)\n" /* num_cols */
        "jne .Lf2047a6_0020482f\n"
        ".Lf2047a6_0020489c:\n"
        "addl $4, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 138 | num_rows */
        "jns .Lf2047a6_002047f1\n"
        ".Lf2047a6_002048aa:\n"
        "addl $0x38, %esp\n" /* line 157 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 172 */
static __attribute__((naked))
void null_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 172 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x2c(%eax), %edi\n" /* line 175 | num_components */
        "movl 0x64(%eax), %eax\n" /* line 176 */
        "movl %eax, -0x18(%ebp)\n" /* num_cols */
        "movl 0x18(%ebp), %eax\n" /* line 179 | num_rows */
        "subl $1, %eax\n"
        "js .Lf2048b1_00204936\n"
        "movl 0x10(%ebp), %edx\n" /* input_row */
        "shll $2, %edx\n"
        "movl %edx, -0xc(%ebp)\n"
        "movl $0, -0x10(%ebp)\n"
        ".Lf2048b1_002048dd:\n"
        "testl %edi, %edi\n" /* line 180 | num_components */
        "jle .Lf2048b1_00204926\n"
        "movl $0, -0x14(%ebp)\n" /* line 179 | ci */
        ".Lf2048b1_002048e8:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 181 | ci */
        "movl 0xc(%ebp), %esi\n" /* input_buf */
        "movl (%esi, %ecx, 4), %eax\n"
        "movl -0xc(%ebp), %edx\n"
        "movl (%eax, %edx), %eax\n"
        "movl -0x10(%ebp), %esi\n" /* line 182 */
        "movl 0x14(%ebp), %edx\n" /* output_buf */
        "addl (%edx, %esi, 4), %ecx\n"
        "movl -0x18(%ebp), %edx\n" /* line 183 | num_cols */
        "testl %edx, %edx\n"
        "je .Lf2048b1_0020491d\n"
        "movl %eax, %edx\n"
        "movl -0x18(%ebp), %eax\n" /* num_cols */
        "leal (%edx, %eax), %esi\n"
        ".Lf2048b1_0020490f:\n"
        "movzbl (%edx), %eax\n" /* line 184 */
        "movb %al, (%ecx)\n"
        "addl $1, %edx\n"
        "addl %edi, %ecx\n" /* line 185 | num_components */
        "cmpl %esi, %edx\n" /* line 183 */
        "jne .Lf2048b1_0020490f\n"
        ".Lf2048b1_0020491d:\n"
        "addl $1, -0x14(%ebp)\n" /* line 180 | ci */
        "cmpl -0x14(%ebp), %edi\n" /* ci, num_components */
        "jne .Lf2048b1_002048e8\n"
        ".Lf2048b1_00204926:\n"
        "addl $1, -0x10(%ebp)\n"
        "addl $4, -0xc(%ebp)\n"
        "movl -0x10(%ebp), %edx\n" /* line 179 */
        "cmpl %edx, 0x18(%ebp)\n" /* num_rows */
        "jne .Lf2048b1_002048dd\n"
        ".Lf2048b1_00204936:\n"
        "addl $0x10, %esp\n" /* line 191 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 204 */
static __attribute__((naked))
void grayscale_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 204 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 205 | cinfo */
        "movl 0x64(%eax), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* num_rows */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* output_buf */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* input_row */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* input_buf */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jcopy_sample_rows\n"
        "leave\n" /* line 207 */
        "retl\n"
    );
}

/* line 220 */
static __attribute__((naked))
void gray_rgb_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $8, %esp\n"
        "movl 0x18(%ebp), %edi\n" /* num_rows */
        "movl 8(%ebp), %eax\n" /* line 223 | cinfo */
        "movl 0x64(%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* num_cols */
        "movl 0x10(%ebp), %eax\n" /* input_row */
        "shll $2, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "subl $1, %edi\n" /* line 225 | num_rows */
        "js .Lf204979_002049da\n"
        ".Lf204979_0020499b:\n"
        "movl 0xc(%ebp), %edx\n" /* line 226 | input_buf */
        "movl (%edx), %eax\n"
        "movl -0xc(%ebp), %edx\n"
        "movl (%eax, %edx), %esi\n" /* inptr */
        "movl 0x14(%ebp), %eax\n" /* line 227 | output_buf */
        "movl (%eax), %edx\n"
        "addl $4, %eax\n"
        "movl %eax, 0x14(%ebp)\n" /* output_buf */
        "movl -0x10(%ebp), %ecx\n" /* line 228 | num_cols */
        "testl %ecx, %ecx\n"
        "je .Lf204979_002049d1\n"
        "xorl %ecx, %ecx\n"
        ".Lf204979_002049ba:\n"
        "movzbl (%esi, %ecx), %eax\n" /* line 230 | inptr */
        "movb %al, (%edx)\n"
        "movb %al, 1(%edx)\n"
        "movb %al, 2(%edx)\n"
        "addl $3, %edx\n" /* line 231 */
        "addl $1, %ecx\n" /* line 228 */
        "cmpl %ecx, -0x10(%ebp)\n" /* num_cols */
        "jne .Lf204979_002049ba\n"
        ".Lf204979_002049d1:\n"
        "addl $4, -0xc(%ebp)\n"
        "subl $1, %edi\n" /* line 225 | num_rows */
        "jns .Lf204979_0020499b\n"
        ".Lf204979_002049da:\n"
        "addl $8, %esp\n" /* line 234 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 248 */
static __attribute__((naked))
void ycck_cmyk_convert(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION input_row, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 248 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x1ac(%edx), %eax\n" /* line 249 | cconvert */
        "movl 0x64(%edx), %ecx\n" /* line 254 */
        "movl %ecx, -0x24(%ebp)\n" /* num_cols */
        "movl 0x128(%edx), %edx\n" /* line 256 */
        "movl %edx, -0x20(%ebp)\n" /* range_limit */
        "movl 8(%eax), %esi\n" /* line 257 */
        "movl %esi, -0x1c(%ebp)\n" /* Crrtab */
        "movl 0xc(%eax), %edx\n" /* line 258 */
        "movl %edx, -0x18(%ebp)\n" /* Cbbtab */
        "movl 0x10(%eax), %ecx\n" /* line 259 */
        "movl %ecx, -0x14(%ebp)\n" /* Crgtab */
        "movl 0x14(%eax), %eax\n" /* line 260 */
        "movl %eax, -0x10(%ebp)\n" /* Cbgtab */
        "movl 0x10(%ebp), %esi\n" /* input_row */
        "shll $2, %esi\n"
        "movl %esi, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 263 | num_rows */
        "js .Lf2049e1_00204b21\n"
        ".Lf2049e1_00204a2c:\n"
        "movl 0xc(%ebp), %edx\n" /* line 264 | input_buf */
        "movl (%edx), %eax\n"
        "movl -0xc(%ebp), %ecx\n"
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* inptr0 */
        "movl 4(%edx), %eax\n" /* line 265 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* inptr1 */
        "movl 8(%edx), %eax\n" /* line 266 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* inptr2 */
        "movl 0xc(%edx), %eax\n" /* line 267 */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* inptr3 */
        "movl 0x14(%ebp), %esi\n" /* line 269 | output_buf */
        "movl (%esi), %eax\n"
        "addl $4, %esi\n"
        "movl %esi, 0x14(%ebp)\n" /* output_buf */
        "movl -0x24(%ebp), %esi\n" /* line 270 | num_cols */
        "testl %esi, %esi\n"
        "je .Lf2049e1_00204b13\n"
        "movl $0, -0x28(%ebp)\n" /* col */
        "movl %eax, %edi\n"
        "movl -0x28(%ebp), %edx\n" /* col */
        "jmp .Lf2049e1_00204a7b\n"
        ".Lf2049e1_00204a79:\n"
        "movl %esi, %edx\n"
        ".Lf2049e1_00204a7b:\n"
        "movl -0x38(%ebp), %eax\n" /* line 271 | inptr0 */
        "movzbl (%eax, %edx), %ecx\n"
        "movl -0x34(%ebp), %esi\n" /* line 272 | inptr1 */
        "movzbl (%esi, %edx), %esi\n"
        "movl %esi, -0x44(%ebp)\n" /* cb */
        "movl -0x30(%ebp), %eax\n" /* line 275 | inptr2 */
        "movzbl (%eax, %edx), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n" /* Crrtab */
        "movl (%edx, %eax), %esi\n"
        "addl %ecx, %esi\n"
        "movl -0x20(%ebp), %eax\n" /* range_limit */
        "subl %esi, %eax\n"
        "movzbl 0xff(%eax), %eax\n"
        "movb %al, (%edi)\n"
        "movl -0x44(%ebp), %esi\n" /* line 276 | cb */
        "shll $2, %esi\n"
        "movl %esi, -0x44(%ebp)\n" /* cb */
        "movl -0x10(%ebp), %edx\n" /* Cbgtab */
        "movl (%edx, %esi), %eax\n"
        "movl -0x14(%ebp), %esi\n" /* Crgtab */
        "movl -0x3c(%ebp), %edx\n"
        "addl (%esi, %edx), %eax\n"
        "sarl $0x10, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movl -0x20(%ebp), %esi\n" /* range_limit */
        "subl %eax, %esi\n"
        "movzbl 0xff(%esi), %eax\n"
        "movb %al, 1(%edi)\n"
        "movl -0x18(%ebp), %eax\n" /* line 279 | Cbbtab */
        "movl -0x44(%ebp), %edx\n" /* cb */
        "addl (%eax, %edx), %ecx\n"
        "movl -0x20(%ebp), %eax\n" /* range_limit */
        "subl %ecx, %eax\n"
        "movzbl 0xff(%eax), %eax\n"
        "movb %al, 2(%edi)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 281 | inptr3 */
        "movl -0x28(%ebp), %esi\n" /* col */
        "movzbl (%ecx, %esi), %eax\n"
        "movb %al, 3(%edi)\n"
        "addl $1, %esi\n" /* line 270 */
        "movl %esi, -0x28(%ebp)\n" /* col */
        "addl $4, %edi\n"
        "cmpl %esi, -0x24(%ebp)\n" /* num_cols */
        "jne .Lf2049e1_00204a79\n"
        ".Lf2049e1_00204b13:\n"
        "addl $4, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 263 | num_rows */
        "jns .Lf2049e1_00204a2c\n"
        ".Lf2049e1_00204b21:\n"
        "addl $0x3c, %esp\n" /* line 285 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 294 */
static __attribute__((naked))
void start_pass_dcolor(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 294 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 296 */
        "retl\n"
    );
}

/* line 305 */
__attribute__((naked))
void jinit_color_deconverter(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 305 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 309 | cinfo */
        "movl $0x18, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, %edi\n" /* cconvert */
        "movl %eax, 0x1ac(%esi)\n" /* line 312 | cinfo */
        "leal -0x13(%ebx), %eax\n" /* line 313 */
        "movl %eax, (%edi)\n" /* cconvert */
        "cmpl $5, 0x30(%esi)\n" /* line 316 | cinfo */
        "ja .Lf204b2d_00204b94\n"
        "movl 0x30(%esi), %eax\n" /* cinfo */
        "movl 0x41(%ebx, %eax, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "nop\n"
        "popl %ecx\n"
        "addb %al, (%eax)\n"
        "addb %bl, %cl\n"
        "addb %al, (%eax)\n"
        "addb %al, -0x7affffff(%ebp)\n"
        "addl %eax, (%eax)\n"
        "addb %dh, 1(%esi)\n" /* cinfo */
        "addb %al, (%eax)\n"
        "jbe .Lf204b2d_00204b93\n"
        "addb %al, (%eax)\n"
        ".Lf204b2d_00204b93:\n"
        ".Lf204b2d_00204b94:\n"
        "movl 0x2c(%esi), %eax\n" /* line 335 | cinfo */
        "testl %eax, %eax\n"
        "jle .Lf204b2d_00204c1a\n"
        ".Lf204b2d_00204b9b:\n"
        "movl 0x34(%esi), %eax\n" /* line 345 | cinfo */
        "cmpl $2, %eax\n"
        "je .Lf204b2d_00204bf1\n"
        "cmpl $4, %eax\n"
        "je .Lf204b2d_00204c2f\n"
        "cmpl $1, %eax\n"
        "je .Lf204b2d_00204c61\n"
        "cmpl 0x30(%esi), %eax\n" /* line 384 | cinfo */
        "je .Lf204b2d_00204c59\n"
        ".Lf204b2d_00204bbe:\n"
        "movl (%esi), %eax\n" /* line 388 | cinfo */
        "movl $0x1b, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf204b2d_00204bce:\n"
        "cmpb $0, 0x52(%esi)\n" /* line 392 | cinfo */
        "je .Lf204b2d_00204be3\n"
        "movl $1, 0x70(%esi)\n" /* line 393 | cinfo */
        "addl $0x1c, %esp\n" /* line 396 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf204b2d_00204be3:\n"
        "movl 0x6c(%esi), %eax\n" /* line 395 | cinfo */
        "movl %eax, 0x70(%esi)\n" /* cinfo */
        "addl $0x1c, %esp\n" /* line 396 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf204b2d_00204bf1:\n"
        "movl $3, 0x6c(%esi)\n" /* line 359 | cinfo */
        "movl 0x30(%esi), %eax\n" /* line 360 | cinfo */
        "cmpl $3, %eax\n"
        "je .Lf204b2d_00204cf2\n"
        "cmpl $1, %eax\n" /* line 363 */
        "je .Lf204b2d_00204ccf\n"
        "cmpl $2, %eax\n" /* line 365 */
        "jne .Lf204b2d_00204bbe\n"
        "jmp .Lf204b2d_00204c4b\n"
        "cmpl $1, 0x2c(%esi)\n" /* line 318 | cinfo */
        "je .Lf204b2d_00204b9b\n"
        ".Lf204b2d_00204c1a:\n"
        "movl (%esi), %eax\n" /* line 336 | cinfo */
        "movl $0xa, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf204b2d_00204b9b\n"
        ".Lf204b2d_00204c2f:\n"
        "movl $4, 0x6c(%esi)\n" /* line 372 | cinfo */
        "movl 0x30(%esi), %eax\n" /* line 373 | cinfo */
        "cmpl $5, %eax\n"
        "je .Lf204b2d_00204cdd\n"
        "cmpl $4, %eax\n" /* line 376 */
        "jne .Lf204b2d_00204bbe\n"
        ".Lf204b2d_00204c4b:\n"
        "leal -0x28a(%ebx), %eax\n" /* line 386 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "jmp .Lf204b2d_00204bce\n"
        ".Lf204b2d_00204c59:\n"
        "movl 0x2c(%esi), %eax\n" /* line 385 | cinfo */
        "movl %eax, 0x6c(%esi)\n" /* cinfo */
        "jmp .Lf204b2d_00204c4b\n"
        ".Lf204b2d_00204c61:\n"
        "movl $1, 0x6c(%esi)\n" /* line 347 | cinfo */
        "movl 0x30(%esi), %eax\n" /* line 348 | cinfo */
        "cmpl $1, %eax\n"
        "je .Lf204b2d_00204c79\n"
        "cmpl $3, %eax\n"
        "jne .Lf204b2d_00204bbe\n"
        ".Lf204b2d_00204c79:\n"
        "leal -0x1fe(%ebx), %eax\n" /* line 350 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "cmpl $1, 0x2c(%esi)\n" /* line 352 | cinfo */
        "jle .Lf204b2d_00204bce\n"
        "movl $1, %ecx\n"
        "movl $0x54, %edx\n"
        ".Lf204b2d_00204c96:\n"
        "movl 0xcc(%esi), %eax\n" /* line 353 | cinfo */
        "movb $0, 0x30(%edx, %eax)\n"
        "addl $1, %ecx\n" /* line 352 */
        "addl $0x54, %edx\n"
        "cmpl %ecx, 0x2c(%esi)\n" /* cinfo */
        "jg .Lf204b2d_00204c96\n"
        "jmp .Lf204b2d_00204bce\n"
        "cmpl $4, 0x2c(%esi)\n" /* line 330 | cinfo */
        "jne .Lf204b2d_00204c1a\n"
        "jmp .Lf204b2d_00204b9b\n"
        "cmpl $3, 0x2c(%esi)\n" /* line 324 | cinfo */
        "jne .Lf204b2d_00204c1a\n"
        "jmp .Lf204b2d_00204b9b\n"
        ".Lf204b2d_00204ccf:\n"
        "leal -0x1c2(%ebx), %eax\n" /* line 364 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "jmp .Lf204b2d_00204bce\n"
        ".Lf204b2d_00204cdd:\n"
        "leal -0x15a(%ebx), %eax\n" /* line 374 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "movl %esi, %eax\n" /* line 375 | cinfo */
        "calll build_ycc_rgb_table\n"
        "jmp .Lf204b2d_00204bce\n"
        ".Lf204b2d_00204cf2:\n"
        "leal -0x395(%ebx), %eax\n" /* line 361 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "movl %esi, %eax\n" /* line 362 | cinfo */
        "calll build_ycc_rgb_table\n"
        "jmp .Lf204b2d_00204bce\n"
    );
}

