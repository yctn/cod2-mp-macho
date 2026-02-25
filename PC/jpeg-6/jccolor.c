/* ASM dump from: jccolor.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jccolor.c */

#include "common_types.h"
#include "imports.h"

static void rgb_ycc_start(j_compress_ptr cinfo);
static void rgb_ycc_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows);
static void rgb_gray_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows);
static void cmyk_ycck_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows);
static void grayscale_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows);
static void null_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows);
static void null_method(j_compress_ptr cinfo);
void jinit_color_converter(j_compress_ptr cinfo);

/* line 87 */
static __attribute__((naked))
void rgb_ycc_start(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 87 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x154(%eax), %esi\n" /* line 88 | cconvert */
        "movl 4(%eax), %edx\n" /* line 93 */
        "movl $0x2000, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl %eax, 8(%esi)\n" /* cconvert */
        "movl $0, -0x1c(%ebp)\n" /* i */
        "movl $0, -0x18(%ebp)\n"
        "movl $0, -0x14(%ebp)\n"
        "movl $0x8000, -0x10(%ebp)\n"
        "movl $0, -0xc(%ebp)\n"
        "xorl %edi, %edi\n"
        "xorl %esi, %esi\n" /* cconvert */
        "xorl %ecx, %ecx\n"
        "movl $0x807fff, -0x2c(%ebp)\n"
        ".Lf20cd60_0020cdbc:\n"
        "movl -0x18(%ebp), %edx\n" /* line 98 */
        "movl %edx, (%eax)\n"
        "movl -0x14(%ebp), %edx\n" /* line 99 */
        "movl %edx, 0x400(%eax)\n"
        "movl -0x10(%ebp), %edx\n" /* line 100 */
        "movl %edx, 0x800(%eax)\n"
        "movl -0xc(%ebp), %edx\n" /* line 101 */
        "movl %edx, 0xc00(%eax)\n"
        "movl %edi, 0x1000(%eax)\n" /* line 102 */
        "movl -0x2c(%ebp), %edx\n" /* line 107 */
        "movl %edx, 0x1400(%eax)\n"
        "movl %esi, 0x1800(%eax)\n" /* line 111 | cconvert */
        "movl %ecx, 0x1c00(%eax)\n" /* line 112 */
        "addl $1, -0x1c(%ebp)\n" /* line 97 | i */
        "addl $4, %eax\n"
        "addl $0x8000, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "addl $0x4c8b, -0x18(%ebp)\n"
        "addl $0x9646, -0x14(%ebp)\n"
        "addl $0x1d2f, -0x10(%ebp)\n"
        "subl $0x2b33, -0xc(%ebp)\n"
        "subl $0x54cd, %edi\n"
        "subl $0x6b2f, %esi\n" /* cconvert */
        "subl $0x14d1, %ecx\n"
        "cmpl $0x100, -0x1c(%ebp)\n" /* i */
        "jne .Lf20cd60_0020cdbc\n"
        "addl $0x40, %esp\n" /* line 114 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 133 */
static __attribute__((naked))
void rgb_ycc_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 133 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x154(%eax), %edx\n" /* line 136 */
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* ctab */
        "movl 0x24(%eax), %eax\n" /* line 140 */
        "movl %eax, -0x10(%ebp)\n" /* num_cols */
        "movl 0x14(%ebp), %eax\n" /* output_row */
        "shll $2, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 142 | num_rows */
        "js .Lf20ce49_0020cf5f\n"
        ".Lf20ce49_0020ce79:\n"
        "movl 0xc(%ebp), %edx\n" /* line 143 | input_buf */
        "movl (%edx), %edi\n" /* inptr */
        "addl $4, %edx\n"
        "movl %edx, 0xc(%ebp)\n" /* input_buf */
        "movl 0x10(%ebp), %ecx\n" /* line 144 | output_buf */
        "movl (%ecx), %eax\n"
        "movl -0xc(%ebp), %edx\n"
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* outptr0 */
        "movl 4(%ecx), %eax\n" /* line 145 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* outptr1 */
        "movl 8(%ecx), %eax\n" /* line 146 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* outptr2 */
        "movl -0x10(%ebp), %eax\n" /* line 148 | num_cols */
        "testl %eax, %eax\n"
        "je .Lf20ce49_0020cf51\n"
        "movl $0, -0x14(%ebp)\n" /* col */
        ".Lf20ce49_0020ceb6:\n"
        "movzbl 2(%edi), %edx\n" /* line 149 | inptr */
        "movzbl 1(%edi), %ecx\n" /* line 150 | inptr */
        "movzbl (%edi), %esi\n" /* line 151 | inptr, b */
        "addl $3, %edi\n" /* line 152 | inptr */
        "shll $2, %edx\n" /* line 159 */
        "movl %edx, -0x28(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* ctab */
        "leal (%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "leal (%eax, %esi, 4), %esi\n" /* b */
        "movl (%eax, %edx), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "addl 0x400(%edx), %eax\n"
        "addl 0x800(%esi), %eax\n" /* b */
        "sarl $0x10, %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* outptr0 */
        "movl -0x14(%ebp), %edx\n" /* col */
        "movb %al, (%ecx, %edx)\n"
        "movl -0x28(%ebp), %ecx\n" /* line 163 */
        "addl -0x24(%ebp), %ecx\n" /* ctab */
        "movl %ecx, -0x28(%ebp)\n"
        "movl 0xc00(%ecx), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "addl 0x1000(%edx), %eax\n"
        "addl 0x1400(%esi), %eax\n" /* b */
        "sarl $0x10, %eax\n"
        "movl -0x1c(%ebp), %ecx\n" /* outptr1 */
        "movl -0x14(%ebp), %edx\n" /* col */
        "movb %al, (%ecx, %edx)\n"
        "movl -0x28(%ebp), %ecx\n" /* line 167 */
        "movl 0x1400(%ecx), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "addl 0x1800(%edx), %eax\n"
        "addl 0x1c00(%esi), %eax\n" /* b */
        "sarl $0x10, %eax\n"
        "movl -0x18(%ebp), %ecx\n" /* outptr2 */
        "movl -0x14(%ebp), %edx\n" /* col */
        "movb %al, (%ecx, %edx)\n"
        "addl $1, %edx\n" /* line 148 */
        "movl %edx, -0x14(%ebp)\n" /* col */
        "cmpl %edx, -0x10(%ebp)\n" /* num_cols */
        "jne .Lf20ce49_0020ceb6\n"
        ".Lf20ce49_0020cf51:\n"
        "addl $4, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 142 | num_rows */
        "jns .Lf20ce49_0020ce79\n"
        ".Lf20ce49_0020cf5f:\n"
        "addl $0x24, %esp\n" /* line 172 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 189 */
static __attribute__((naked))
void rgb_gray_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x154(%eax), %edx\n" /* line 192 */
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x18(%ebp)\n" /* ctab */
        "movl 0x24(%eax), %eax\n" /* line 196 */
        "movl %eax, -0x10(%ebp)\n" /* num_cols */
        "movl 0x14(%ebp), %eax\n" /* output_row */
        "shll $2, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 198 | num_rows */
        "js .Lf20cf66_0020cffd\n"
        ".Lf20cf66_0020cf92:\n"
        "movl 0xc(%ebp), %edx\n" /* line 199 | input_buf */
        "movl (%edx), %esi\n" /* inptr */
        "addl $4, %edx\n"
        "movl %edx, 0xc(%ebp)\n" /* input_buf */
        "movl 0x10(%ebp), %ecx\n" /* line 200 | output_buf */
        "movl (%ecx), %eax\n"
        "movl -0xc(%ebp), %edx\n"
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x14(%ebp)\n" /* outptr */
        "movl -0x10(%ebp), %edx\n" /* line 202 | num_cols */
        "testl %edx, %edx\n"
        "je .Lf20cf66_0020cff3\n"
        "xorl %edi, %edi\n" /* col */
        ".Lf20cf66_0020cfb4:\n"
        "movzbl 2(%esi), %eax\n" /* line 203 | inptr */
        "movzbl 1(%esi), %ecx\n" /* line 204 | inptr */
        "movl %ecx, -0x1c(%ebp)\n" /* g */
        "movzbl (%esi), %edx\n" /* line 205 | inptr */
        "movl %edx, -0x20(%ebp)\n" /* b */
        "addl $3, %esi\n" /* line 206 | inptr */
        "movl -0x18(%ebp), %ecx\n" /* line 208 | ctab */
        "movl (%ecx, %eax, 4), %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* g */
        "addl 0x400(%ecx, %edx, 4), %eax\n"
        "movl -0x20(%ebp), %edx\n" /* b */
        "addl 0x800(%ecx, %edx, 4), %eax\n"
        "sarl $0x10, %eax\n"
        "movl -0x14(%ebp), %ecx\n" /* outptr */
        "movb %al, (%ecx, %edi)\n"
        "addl $1, %edi\n" /* line 202 | col */
        "cmpl %edi, -0x10(%ebp)\n" /* col, num_cols */
        "jne .Lf20cf66_0020cfb4\n"
        ".Lf20cf66_0020cff3:\n"
        "addl $4, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 198 | num_rows */
        "jns .Lf20cf66_0020cf92\n"
        ".Lf20cf66_0020cffd:\n"
        "addl $0x18, %esp\n" /* line 213 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 228 */
static __attribute__((naked))
void cmyk_ycck_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 228 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x154(%eax), %edx\n" /* line 231 */
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* ctab */
        "movl 0x24(%eax), %eax\n" /* line 235 */
        "movl %eax, -0x10(%ebp)\n" /* num_cols */
        "movl 0x14(%ebp), %eax\n" /* output_row */
        "shll $2, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 237 | num_rows */
        "js .Lf20d004_0020d13f\n"
        ".Lf20d004_0020d034:\n"
        "movl 0xc(%ebp), %edx\n" /* line 238 | input_buf */
        "movl (%edx), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* inptr */
        "addl $4, 0xc(%ebp)\n" /* input_buf */
        "movl 0x10(%ebp), %ecx\n" /* line 239 | output_buf */
        "movl (%ecx), %eax\n"
        "movl -0xc(%ebp), %edx\n"
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* outptr0 */
        "movl 4(%ecx), %eax\n" /* line 240 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* outptr1 */
        "movl 8(%ecx), %eax\n" /* line 241 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* outptr2 */
        "movl 0xc(%ecx), %eax\n" /* line 242 */
        "movl (%edx, %eax), %eax\n"
        "movl %eax, -0x14(%ebp)\n" /* outptr3 */
        "movl -0x10(%ebp), %ecx\n" /* line 244 | num_cols */
        "testl %ecx, %ecx\n"
        "je .Lf20d004_0020d131\n"
        "xorl %edi, %edi\n" /* col */
        ".Lf20d004_0020d076:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 245 | inptr */
        "movzbl (%ecx), %eax\n"
        "movl $0xff, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* r */
        "movzbl 1(%ecx), %eax\n" /* line 246 */
        "movl $0xff, %esi\n" /* g */
        "subl %eax, %esi\n" /* g */
        "movzbl 2(%ecx), %eax\n" /* line 247 */
        "movl $0xff, %ecx\n"
        "subl %eax, %ecx\n"
        "movl -0x24(%ebp), %eax\n" /* line 249 | inptr */
        "movzbl 3(%eax), %eax\n"
        "movl -0x14(%ebp), %edx\n" /* outptr3 */
        "movb %al, (%edx, %edi)\n"
        "addl $4, -0x24(%ebp)\n" /* line 250 | inptr */
        "movl -0x2c(%ebp), %eax\n" /* line 257 | r */
        "shll $2, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* r */
        "movl -0x28(%ebp), %edx\n" /* ctab */
        "leal (%edx, %esi, 4), %esi\n" /* g */
        "leal (%edx, %ecx, 4), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movl (%edx, %eax), %eax\n"
        "addl 0x400(%esi), %eax\n" /* g */
        "movl -0x34(%ebp), %edx\n"
        "addl 0x800(%edx), %eax\n"
        "sarl $0x10, %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* outptr0 */
        "movb %al, (%ecx, %edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 261 | r */
        "addl -0x28(%ebp), %eax\n" /* ctab */
        "movl %eax, -0x2c(%ebp)\n" /* r */
        "movl 0xc00(%eax), %eax\n"
        "addl 0x1000(%esi), %eax\n" /* g */
        "movl -0x34(%ebp), %ecx\n"
        "addl 0x1400(%ecx), %eax\n"
        "sarl $0x10, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* outptr1 */
        "movb %al, (%edx, %edi)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 265 | r */
        "movl 0x1400(%ecx), %eax\n"
        "addl 0x1800(%esi), %eax\n" /* g */
        "movl -0x34(%ebp), %edx\n"
        "addl 0x1c00(%edx), %eax\n"
        "sarl $0x10, %eax\n"
        "movl -0x18(%ebp), %ecx\n" /* outptr2 */
        "movb %al, (%ecx, %edi)\n"
        "addl $1, %edi\n" /* line 244 | col */
        "cmpl %edi, -0x10(%ebp)\n" /* col, num_cols */
        "jne .Lf20d004_0020d076\n"
        ".Lf20d004_0020d131:\n"
        "addl $4, -0xc(%ebp)\n"
        "subl $1, 0x18(%ebp)\n" /* line 237 | num_rows */
        "jns .Lf20d004_0020d034\n"
        ".Lf20d004_0020d13f:\n"
        "addl $0x2c, %esp\n" /* line 270 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 283 */
static __attribute__((naked))
void grayscale_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 283 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x24(%eax), %edx\n" /* line 287 */
        "movl %edx, -0x10(%ebp)\n" /* num_cols */
        "movl 0x2c(%eax), %eax\n" /* line 288 */
        "movl %eax, -0xc(%ebp)\n" /* instride */
        "movl 0x14(%ebp), %edi\n" /* output_row */
        "shll $2, %edi\n"
        "subl $1, 0x18(%ebp)\n" /* line 290 | num_rows */
        "js .Lf20d146_0020d19f\n"
        ".Lf20d146_0020d169:\n"
        "movl 0xc(%ebp), %eax\n" /* line 291 | input_buf */
        "movl (%eax), %ecx\n"
        "addl $4, %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* input_buf */
        "movl 0x10(%ebp), %edx\n" /* line 292 | output_buf */
        "movl (%edx), %eax\n"
        "movl (%eax, %edi), %esi\n" /* outptr */
        "movl -0x10(%ebp), %eax\n" /* line 294 | num_cols */
        "testl %eax, %eax\n"
        "je .Lf20d146_0020d196\n"
        "xorl %edx, %edx\n"
        ".Lf20d146_0020d185:\n"
        "movzbl (%ecx), %eax\n" /* line 295 */
        "movb %al, (%esi, %edx)\n" /* outptr */
        "addl -0xc(%ebp), %ecx\n" /* line 296 | instride */
        "addl $1, %edx\n" /* line 294 */
        "cmpl %edx, -0x10(%ebp)\n" /* num_cols */
        "jne .Lf20d146_0020d185\n"
        ".Lf20d146_0020d196:\n"
        "addl $4, %edi\n"
        "subl $1, 0x18(%ebp)\n" /* line 290 | num_rows */
        "jns .Lf20d146_0020d169\n"
        ".Lf20d146_0020d19f:\n"
        "addl $8, %esp\n" /* line 299 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 312 */
static __attribute__((naked))
void null_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 312 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x40(%eax), %edx\n" /* line 317 */
        "movl %edx, -0x18(%ebp)\n" /* nc */
        "movl 0x24(%eax), %eax\n" /* line 318 */
        "movl %eax, -0x14(%ebp)\n" /* num_cols */
        "movl 0x18(%ebp), %eax\n" /* line 320 | num_rows */
        "subl $1, %eax\n"
        "js .Lf20d1a6_0020d226\n"
        "movl 0x14(%ebp), %edx\n" /* output_row */
        "shll $2, %edx\n"
        "movl %edx, -0xc(%ebp)\n"
        "movl $0, -0x10(%ebp)\n"
        ".Lf20d1a6_0020d1d5:\n"
        "movl -0x18(%ebp), %eax\n" /* line 322 | nc */
        "testl %eax, %eax\n"
        "jle .Lf20d1a6_0020d216\n"
        "xorl %edi, %edi\n" /* line 320 | ci */
        ".Lf20d1a6_0020d1de:\n"
        "movl -0x10(%ebp), %eax\n" /* line 323 */
        "movl 0xc(%ebp), %edx\n" /* input_buf */
        "movl (%edx, %eax, 4), %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* line 324 | output_buf */
        "movl (%edx, %edi, 4), %eax\n"
        "movl -0xc(%ebp), %edx\n"
        "movl (%eax, %edx), %esi\n" /* outptr */
        "movl -0x14(%ebp), %eax\n" /* line 325 | num_cols */
        "testl %eax, %eax\n"
        "je .Lf20d1a6_0020d20e\n"
        "xorl %edx, %edx\n"
        ".Lf20d1a6_0020d1fc:\n"
        "movzbl (%ecx, %edi), %eax\n" /* line 326 */
        "movb %al, (%esi, %edx)\n" /* outptr */
        "addl -0x18(%ebp), %ecx\n" /* line 327 | nc */
        "addl $1, %edx\n" /* line 325 */
        "cmpl %edx, -0x14(%ebp)\n" /* num_cols */
        "jne .Lf20d1a6_0020d1fc\n"
        ".Lf20d1a6_0020d20e:\n"
        "addl $1, %edi\n" /* line 322 | ci */
        "cmpl %edi, -0x18(%ebp)\n" /* ci, nc */
        "jne .Lf20d1a6_0020d1de\n"
        ".Lf20d1a6_0020d216:\n"
        "addl $1, -0x10(%ebp)\n"
        "addl $4, -0xc(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 320 | num_rows */
        "cmpl %eax, -0x10(%ebp)\n"
        "jne .Lf20d1a6_0020d1d5\n"
        ".Lf20d1a6_0020d226:\n"
        "addl $0x10, %esp\n" /* line 333 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 342 */
static __attribute__((naked))
void null_method(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 342 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 344 */
        "retl\n"
    );
}

/* line 353 */
__attribute__((naked))
void jinit_color_converter(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 353 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 356 */
        "movl $0xc, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, %edi\n" /* cconvert */
        "movl %eax, 0x154(%esi)\n" /* line 359 */
        "leal -0x13(%ebx), %eax\n" /* line 361 */
        "movl %eax, (%edi)\n" /* cconvert */
        "cmpl $5, 0x30(%esi)\n" /* line 364 */
        "ja .Lf20d232_0020d298\n"
        "movl 0x30(%esi), %eax\n"
        "movl 0x40(%ebx, %eax, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "popl %eax\n"
        "addb %al, (%eax)\n"
        "addb %bh, 0xdc0000(%eax, %eax)\n"
        "addb %al, (%eax)\n"
        "faddl (%eax)\n"
        "addb %al, (%eax)\n"
        "aam $0\n"
        "addb %al, (%eax)\n"
        "aam $0\n"
        "addb %al, (%eax)\n"
        ".Lf20d232_0020d298:\n"
        "movl 0x2c(%esi), %eax\n" /* line 389 */
        "testl %eax, %eax\n"
        "jle .Lf20d232_0020d302\n"
        ".Lf20d232_0020d29f:\n"
        "movl 0x44(%esi), %edx\n" /* line 395 */
        "cmpl $5, %edx\n"
        "ja .Lf20d232_0020d2cc\n"
        "movl 0x74(%ebx, %edx, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "nop\n"
        "movw %es, (%eax)\n"
        "addb %al, (%eax)\n"
        "xchgl %eax, %ecx\n"
        "addl %eax, (%eax)\n"
        "addb %cl, 1(%eax)\n"
        "addb %al, (%eax)\n"
        "imull $0x1270000, (%ecx), %eax\n"
        "addb %al, (%eax)\n"
        "outl %eax, $0\n"
        "addb %al, (%eax)\n"
        ".Lf20d232_0020d2cc:\n"
        "cmpl 0x30(%esi), %edx\n" /* line 453 */
        "je .Lf20d232_0020d2f2\n"
        ".Lf20d232_0020d2d1:\n"
        "movl (%esi), %eax\n" /* line 455 */
        "movl $0x1b, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20d232_0020d2e1:\n"
        "leal -0x9a(%ebx), %eax\n" /* line 456 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        ".Lf20d232_0020d2ea:\n"
        "addl $0x1c, %esp\n" /* line 459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20d232_0020d2f2:\n"
        "movl 0x40(%esi), %eax\n" /* line 453 */
        "cmpl 0x2c(%esi), %eax\n"
        "jne .Lf20d232_0020d2d1\n"
        "jmp .Lf20d232_0020d2e1\n"
        "cmpl $1, 0x2c(%esi)\n" /* line 366 */
        "je .Lf20d232_0020d29f\n"
        ".Lf20d232_0020d302:\n"
        "movl (%esi), %eax\n" /* line 390 */
        "movl $9, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20d232_0020d29f\n"
        "cmpl $4, 0x2c(%esi)\n" /* line 384 */
        "jne .Lf20d232_0020d302\n"
        "jmp .Lf20d232_0020d29f\n"
        "cmpl $3, 0x2c(%esi)\n" /* line 378 */
        "jne .Lf20d232_0020d302\n"
        "jmp .Lf20d232_0020d29f\n"
        "cmpl $4, 0x40(%esi)\n" /* line 441 */
        "je .Lf20d232_0020d33d\n"
        "movl (%esi), %eax\n" /* line 442 */
        "movl $0xa, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20d232_0020d33d:\n"
        "movl 0x30(%esi), %eax\n" /* line 443 */
        "cmpl $4, %eax\n"
        "je .Lf20d232_0020d437\n"
        "cmpl $5, %eax\n" /* line 446 */
        "je .Lf20d232_0020d2e1\n"
        ".Lf20d232_0020d34e:\n"
        "movl (%esi), %eax\n" /* line 449 */
        "movl $0x1b, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "addl $0x1c, %esp\n" /* line 459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 449 */
        "cmpl $4, 0x40(%esi)\n" /* line 432 */
        "je .Lf20d232_0020d37d\n"
        "movl (%esi), %eax\n" /* line 433 */
        "movl $0xa, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20d232_0020d37d:\n"
        "cmpl $4, 0x30(%esi)\n" /* line 434 */
        "jne .Lf20d232_0020d34e\n"
        "jmp .Lf20d232_0020d2e1\n"
        "cmpl $3, 0x40(%esi)\n" /* line 411 */
        "je .Lf20d232_0020d39e\n"
        "movl (%esi), %eax\n" /* line 412 */
        "movl $0xa, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20d232_0020d39e:\n"
        "cmpl $2, 0x30(%esi)\n" /* line 413 */
        "jne .Lf20d232_0020d34e\n"
        "jmp .Lf20d232_0020d2e1\n"
        "cmpl $3, 0x40(%esi)\n" /* line 420 */
        "je .Lf20d232_0020d3bf\n"
        "movl (%esi), %eax\n" /* line 421 */
        "movl $0xa, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20d232_0020d3bf:\n"
        "movl 0x30(%esi), %eax\n" /* line 422 */
        "cmpl $2, %eax\n"
        "je .Lf20d232_0020d421\n"
        "cmpl $3, %eax\n" /* line 425 */
        "jne .Lf20d232_0020d34e\n"
        "jmp .Lf20d232_0020d2e1\n"
        "cmpl $1, 0x40(%esi)\n" /* line 397 */
        "je .Lf20d232_0020d3e7\n"
        "movl (%esi), %eax\n" /* line 398 */
        "movl $0xa, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20d232_0020d3e7:\n"
        "movl 0x30(%esi), %eax\n" /* line 399 */
        "cmpl $1, %eax\n"
        "je .Lf20d232_0020d3fd\n"
        "cmpl $2, %eax\n" /* line 401 */
        "je .Lf20d232_0020d40b\n"
        "cmpl $3, %eax\n" /* line 404 */
        "jne .Lf20d232_0020d34e\n"
        ".Lf20d232_0020d3fd:\n"
        "leal -0xfa(%ebx), %eax\n" /* line 405 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "jmp .Lf20d232_0020d2ea\n"
        ".Lf20d232_0020d40b:\n"
        "leal -0x4e0(%ebx), %eax\n" /* line 402 */
        "movl %eax, (%edi)\n" /* cconvert */
        "leal -0x2da(%ebx), %eax\n" /* line 403 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "jmp .Lf20d232_0020d2ea\n"
        ".Lf20d232_0020d421:\n"
        "leal -0x4e0(%ebx), %eax\n" /* line 423 */
        "movl %eax, (%edi)\n" /* cconvert */
        "leal -0x3f7(%ebx), %eax\n" /* line 424 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "jmp .Lf20d232_0020d2ea\n"
        ".Lf20d232_0020d437:\n"
        "leal -0x4e0(%ebx), %eax\n" /* line 444 */
        "movl %eax, (%edi)\n" /* cconvert */
        "leal -0x23c(%ebx), %eax\n" /* line 445 */
        "movl %eax, 4(%edi)\n" /* cconvert */
        "jmp .Lf20d232_0020d2ea\n"
    );
}

