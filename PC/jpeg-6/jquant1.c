/* ASM dump from: jquant1.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jquant1.c */

#include "common_types.h"
#include "imports.h"

static const UINT8 base_dither_matrix[16][16]; /* 0x307280 */

static void color_quantize(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows);
static void color_quantize3(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows);
static void quantize_ord_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows);
static void quantize3_ord_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows);
static void quantize_fs_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows);
static void finish_pass_1_quant(j_decompress_ptr cinfo);
static void new_color_map_1_quant(j_decompress_ptr cinfo);
static void create_colorindex(j_decompress_ptr cinfo);
void jinit_1pass_quantizer(j_decompress_ptr cinfo);
static void start_pass_1_quant(j_decompress_ptr cinfo, int is_pre_scan);

/* line 462 */
static __attribute__((naked))
void color_quantize(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 462 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x1b0(%edx), %eax\n" /* line 464 */
        "movl 0x18(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* colorindex */
        "movl 0x64(%edx), %eax\n" /* line 469 */
        "movl %eax, -0x10(%ebp)\n" /* width */
        "movl 0x6c(%edx), %edx\n" /* line 470 */
        "movl %edx, -0xc(%ebp)\n" /* nc */
        "movl 0x14(%ebp), %ecx\n" /* line 472 | num_rows */
        "testl %ecx, %ecx\n"
        "jle .Lf201ec0_00201f82\n"
        "movl $0, -0x14(%ebp)\n" /* row */
        "movl -0x14(%ebp), %eax\n" /* row */
        ".Lf201ec0_00201ef8:\n"
        "shll $2, %eax\n" /* line 462 */
        "movl 0xc(%ebp), %edx\n" /* line 473 | input_buf */
        "movl (%edx, %eax), %esi\n" /* ptrin */
        "movl 0x10(%ebp), %edx\n" /* line 474 | output_buf */
        "movl (%edx, %eax), %eax\n"
        "movl -0x10(%ebp), %edx\n" /* line 475 | width */
        "testl %edx, %edx\n"
        "je .Lf201ec0_00201f6f\n"
        "movl %eax, -0x18(%ebp)\n" /* ptrout */
        "movl -0x10(%ebp), %edx\n" /* width */
        "leal (%eax, %edx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "jmp .Lf201ec0_00201f30\n"
        ".Lf201ec0_00201f1c:\n"
        "xorl %eax, %eax\n" /* line 477 */
        "movl -0x18(%ebp), %edx\n" /* line 480 | ptrout */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x18(%ebp)\n" /* ptrout */
        "movl -0x20(%ebp), %eax\n" /* line 475 */
        "cmpl %eax, %edx\n"
        "je .Lf201ec0_00201f6f\n"
        ".Lf201ec0_00201f30:\n"
        "movl -0xc(%ebp), %eax\n" /* line 477 | nc */
        "testl %eax, %eax\n"
        "jle .Lf201ec0_00201f1c\n"
        "xorl %ecx, %ecx\n" /* line 475 */
        "xorl %edi, %edi\n" /* pixcode */
        ".Lf201ec0_00201f3b:\n"
        "movzbl (%esi), %eax\n" /* line 478 | ptrin */
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* colorindex */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl -0x24(%ebp), %eax\n"
        "movzbl (%edx, %eax), %edx\n"
        "addl %edx, %edi\n" /* pixcode */
        "addl $1, %esi\n" /* ptrin */
        "addl $1, %ecx\n" /* line 477 */
        "cmpl %ecx, -0xc(%ebp)\n" /* nc */
        "jne .Lf201ec0_00201f3b\n"
        "movl %edi, %eax\n" /* pixcode */
        "movl -0x18(%ebp), %edx\n" /* line 480 | ptrout */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x18(%ebp)\n" /* ptrout */
        "movl -0x20(%ebp), %eax\n" /* line 475 */
        "cmpl %eax, %edx\n"
        "jne .Lf201ec0_00201f30\n"
        ".Lf201ec0_00201f6f:\n"
        "addl $1, -0x14(%ebp)\n" /* line 472 | row */
        "movl -0x14(%ebp), %edx\n" /* row */
        "cmpl %edx, 0x14(%ebp)\n" /* num_rows */
        "je .Lf201ec0_00201f82\n"
        "movl %edx, %eax\n"
        "jmp .Lf201ec0_00201ef8\n"
        ".Lf201ec0_00201f82:\n"
        "addl $0x1c, %esp\n" /* line 483 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 490 */
static __attribute__((naked))
void color_quantize3(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 490 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x1b0(%edx), %eax\n" /* line 494 */
        "movl 0x18(%eax), %eax\n"
        "movl (%eax), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* colorindex0 */
        "movl 4(%eax), %edi\n" /* line 495 */
        "movl %edi, -0x18(%ebp)\n" /* colorindex1 */
        "movl 8(%eax), %eax\n" /* line 496 */
        "movl %eax, -0x14(%ebp)\n" /* colorindex2 */
        "movl 0x64(%edx), %edx\n" /* line 499 */
        "movl %edx, -0xc(%ebp)\n" /* width */
        "movl 0x14(%ebp), %eax\n" /* line 501 | num_rows */
        "testl %eax, %eax\n"
        "jle .Lf201f89_00202023\n"
        "movl $0, -0x10(%ebp)\n" /* row */
        "movl -0x10(%ebp), %eax\n" /* row */
        ".Lf201f89_00201fc5:\n"
        "shll $2, %eax\n" /* line 490 */
        "movl 0xc(%ebp), %edx\n" /* line 502 | input_buf */
        "movl (%eax, %edx), %esi\n" /* ptrin */
        "movl 0x10(%ebp), %ecx\n" /* line 503 | output_buf */
        "movl (%eax, %ecx), %eax\n"
        "movl -0xc(%ebp), %edi\n" /* line 504 | width */
        "testl %edi, %edi\n"
        "je .Lf201f89_00202017\n"
        "movl %eax, %ecx\n"
        "movl -0xc(%ebp), %edi\n" /* width */
        "leal (%eax, %edi), %edi\n"
        "movl %edi, -0x20(%ebp)\n"
        ".Lf201f89_00201fe6:\n"
        "movzbl (%esi), %eax\n" /* line 505 | ptrin */
        "movl -0x1c(%ebp), %edi\n" /* colorindex0 */
        "movzbl (%edi, %eax), %edx\n"
        "movzbl 1(%esi), %eax\n" /* line 506 | ptrin */
        "movl -0x18(%ebp), %edi\n" /* colorindex1 */
        "movzbl (%edi, %eax), %eax\n"
        "addl %eax, %edx\n"
        "movzbl 2(%esi), %eax\n" /* line 507 | ptrin */
        "movl -0x14(%ebp), %edi\n" /* colorindex2 */
        "movzbl (%edi, %eax), %eax\n"
        "addl %eax, %edx\n"
        "addl $3, %esi\n" /* ptrin */
        "movb %dl, (%ecx)\n" /* line 508 */
        "addl $1, %ecx\n"
        "cmpl %ecx, -0x20(%ebp)\n" /* line 504 */
        "jne .Lf201f89_00201fe6\n"
        ".Lf201f89_00202017:\n"
        "addl $1, -0x10(%ebp)\n" /* line 501 | row */
        "movl -0x10(%ebp), %eax\n" /* row */
        "cmpl %eax, 0x14(%ebp)\n" /* num_rows */
        "jne .Lf201f89_00201fc5\n"
        ".Lf201f89_00202023:\n"
        "addl $0x18, %esp\n" /* line 511 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 518 */
static __attribute__((naked))
void quantize_ord_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 518 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x1b0(%eax), %edx\n" /* line 519 */
        "movl %edx, -0x38(%ebp)\n" /* cquantize */
        "movl 0x6c(%eax), %ecx\n" /* line 525 */
        "movl %ecx, -0x24(%ebp)\n" /* nc */
        "movl 0x64(%eax), %eax\n" /* line 529 */
        "movl %eax, -0x18(%ebp)\n" /* width */
        "movl 0x14(%ebp), %eax\n" /* line 531 | num_rows */
        "testl %eax, %eax\n"
        "jg .Lf20202a_00202058\n"
        ".Lf20202a_00202051:\n"
        "addl $0x50, %esp\n" /* line 561 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20202a_00202058:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 531 | row */
        "movl -0x1c(%ebp), %esi\n" /* row, output_ptr */
        ".Lf20202a_00202062:\n"
        "shll $2, %esi\n" /* line 518 */
        "movl %esi, -0xc(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* output_buf */
        "addl %esi, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl -0x18(%ebp), %edx\n" /* line 533 | width */
        "movl %edx, 4(%esp)\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "movl -0x38(%ebp), %esi\n" /* line 535 | cquantize, output_ptr */
        "movl 0x30(%esi), %esi\n" /* output_ptr */
        "movl %esi, -0x28(%ebp)\n" /* output_ptr, row_index */
        "movl -0x24(%ebp), %eax\n" /* line 536 | nc */
        "testl %eax, %eax\n"
        "jle .Lf20202a_0020212b\n"
        "shll $6, %esi\n" /* output_ptr */
        "movl %esi, -0x14(%ebp)\n" /* output_ptr */
        "movl $0, -0x20(%ebp)\n" /* ci */
        "movl $0x30, -0x40(%ebp)\n"
        "movl -0x20(%ebp), %ecx\n" /* ci */
        ".Lf20202a_002020ac:\n"
        "movl 0xc(%ebp), %eax\n" /* line 537 | input_buf */
        "movl -0xc(%ebp), %edx\n"
        "addl (%eax, %edx), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* input_ptr */
        "movl -0x10(%ebp), %esi\n" /* line 538 | output_ptr */
        "movl (%esi), %edx\n" /* output_ptr */
        "movl -0x38(%ebp), %ecx\n" /* line 539 | cquantize */
        "movl 0x18(%ecx), %eax\n"
        "movl -0x20(%ebp), %esi\n" /* ci, output_ptr */
        "movl (%eax, %esi, 4), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* colorindex_ci */
        "movl -0x14(%ebp), %esi\n" /* line 540 | output_ptr */
        "movl -0x40(%ebp), %eax\n"
        "addl 4(%eax, %ecx), %esi\n" /* output_ptr */
        "movl %esi, -0x2c(%ebp)\n" /* output_ptr, dither */
        "movl -0x18(%ebp), %eax\n" /* line 543 | width */
        "testl %eax, %eax\n"
        "je .Lf20202a_00202117\n"
        "movl %edx, %esi\n" /* output_ptr */
        "xorl %edi, %edi\n" /* col_index */
        "movl -0x18(%ebp), %eax\n" /* width */
        "addl %edx, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        ".Lf20202a_002020ec:\n"
        "movl -0x34(%ebp), %edx\n" /* line 551 | input_ptr */
        "movzbl (%edx), %eax\n"
        "movl -0x2c(%ebp), %edx\n" /* dither */
        "movl (%edx, %edi, 4), %ecx\n"
        "addl -0x30(%ebp), %eax\n" /* colorindex_ci */
        "movzbl (%esi), %edx\n" /* output_ptr */
        "addb (%eax, %ecx), %dl\n"
        "movb %dl, (%esi)\n" /* output_ptr */
        "movl -0x24(%ebp), %ecx\n" /* line 552 | nc */
        "addl %ecx, -0x34(%ebp)\n" /* input_ptr */
        "addl $1, %esi\n" /* line 553 | output_ptr */
        "addl $1, %edi\n" /* line 554 | col_index */
        "andl $0xf, %edi\n" /* col_index */
        "cmpl %esi, -0x3c(%ebp)\n" /* line 543 | output_ptr */
        "jne .Lf20202a_002020ec\n"
        ".Lf20202a_00202117:\n"
        "addl $1, -0x20(%ebp)\n" /* line 536 | ci */
        "addl $4, -0x40(%ebp)\n"
        "movl -0x20(%ebp), %esi\n" /* ci, output_ptr */
        "cmpl %esi, -0x24(%ebp)\n" /* output_ptr, nc */
        "je .Lf20202a_00202150\n"
        "movl %esi, %ecx\n" /* output_ptr */
        "jmp .Lf20202a_002020ac\n"
        ".Lf20202a_0020212b:\n"
        "movl %esi, %eax\n" /* output_ptr */
        ".Lf20202a_0020212d:\n"
        "addl $1, %eax\n" /* line 559 */
        "andl $0xf, %eax\n"
        "movl -0x38(%ebp), %edx\n" /* cquantize */
        "movl %eax, 0x30(%edx)\n"
        "addl $1, -0x1c(%ebp)\n" /* line 531 | row */
        "movl -0x1c(%ebp), %ecx\n" /* row */
        "cmpl %ecx, 0x14(%ebp)\n" /* num_rows */
        "je .Lf20202a_00202051\n"
        "movl %ecx, %esi\n" /* output_ptr */
        "jmp .Lf20202a_00202062\n"
        ".Lf20202a_00202150:\n"
        "movl -0x28(%ebp), %eax\n" /* row_index */
        "jmp .Lf20202a_0020212d\n"
    );
}

/* line 568 */
static __attribute__((naked))
void quantize3_ord_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 568 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x38, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x1b0(%edx), %eax\n" /* line 569 */
        "movl %eax, -0x38(%ebp)\n" /* cquantize */
        "movl 0x18(%eax), %eax\n" /* line 573 */
        "movl (%eax), %esi\n"
        "movl %esi, -0x30(%ebp)\n" /* colorindex0 */
        "movl 4(%eax), %ecx\n" /* line 574 */
        "movl %ecx, -0x2c(%ebp)\n" /* colorindex1 */
        "movl 8(%eax), %eax\n" /* line 575 */
        "movl %eax, -0x28(%ebp)\n" /* colorindex2 */
        "movl 0x64(%edx), %edx\n" /* line 582 */
        "movl %edx, -0xc(%ebp)\n" /* width */
        "movl 0x14(%ebp), %eax\n" /* line 584 | num_rows */
        "testl %eax, %eax\n"
        "jle .Lf202155_00202291\n"
        "movl $0, -0x10(%ebp)\n" /* row */
        "movl -0x10(%ebp), %eax\n" /* row */
        ".Lf202155_00202198:\n"
        "movl -0x38(%ebp), %esi\n" /* line 585 | cquantize */
        "movl 0x30(%esi), %esi\n"
        "movl %esi, -0x18(%ebp)\n" /* row_index */
        "shll $2, %eax\n" /* line 568 */
        "movl 0xc(%ebp), %edx\n" /* line 586 | input_buf */
        "movl (%edx, %eax), %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* input_ptr */
        "movl 0x10(%ebp), %ecx\n" /* line 587 | output_buf */
        "movl (%eax, %ecx), %edx\n"
        "movl %esi, %eax\n" /* line 588 */
        "shll $6, %eax\n"
        "movl -0x38(%ebp), %esi\n" /* cquantize */
        "movl 0x34(%esi), %ecx\n"
        "addl %eax, %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* dither0 */
        "movl 0x38(%esi), %ecx\n" /* line 589 */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* dither1 */
        "addl 0x3c(%esi), %eax\n" /* line 590 */
        "movl %eax, -0x1c(%ebp)\n" /* dither2 */
        "movl -0xc(%ebp), %eax\n" /* line 593 | width */
        "testl %eax, %eax\n"
        "je .Lf202155_00202277\n"
        "movl %edx, %edi\n" /* output_ptr */
        "movl $0, -0x14(%ebp)\n" /* col_index */
        "movl -0xc(%ebp), %esi\n" /* width */
        "leal (%edx, %esi), %esi\n"
        "movl %esi, -0x3c(%ebp)\n"
        ".Lf202155_002021ee:\n"
        "movl -0x14(%ebp), %esi\n" /* line 594 | col_index */
        "shll $2, %esi\n"
        "movl -0x34(%ebp), %edx\n" /* input_ptr */
        "movzbl (%edx), %eax\n"
        "movl -0x24(%ebp), %ecx\n" /* dither0 */
        "movl (%ecx, %esi), %edx\n"
        "addl -0x30(%ebp), %eax\n" /* colorindex0 */
        "movzbl (%eax, %edx), %edx\n"
        "movl -0x34(%ebp), %eax\n" /* line 596 | input_ptr */
        "movzbl 1(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* dither1 */
        "movl (%eax, %esi), %ecx\n"
        "movl -0x40(%ebp), %eax\n"
        "addl -0x2c(%ebp), %eax\n" /* colorindex1 */
        "movzbl (%eax, %ecx), %eax\n"
        "addl %eax, %edx\n"
        "movl -0x34(%ebp), %ecx\n" /* line 598 | input_ptr */
        "movzbl 2(%ecx), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* dither2 */
        "movl (%eax, %esi), %ecx\n"
        "movl -0x40(%ebp), %eax\n"
        "addl -0x28(%ebp), %eax\n" /* colorindex2 */
        "movzbl (%eax, %ecx), %eax\n"
        "addl %eax, %edx\n"
        "addl $3, -0x34(%ebp)\n" /* input_ptr */
        "movb %dl, (%edi)\n" /* line 600 | output_ptr */
        "addl $1, %edi\n" /* output_ptr */
        "addl $1, -0x14(%ebp)\n" /* line 601 | col_index */
        "andl $0xf, -0x14(%ebp)\n" /* col_index */
        "cmpl %edi, -0x3c(%ebp)\n" /* line 593 | output_ptr */
        "jne .Lf202155_002021ee\n"
        "movl -0x38(%ebp), %edx\n" /* cquantize */
        "movl -0x18(%ebp), %eax\n" /* line 604 | row_index */
        "addl $1, %eax\n"
        "andl $0xf, %eax\n"
        "movl %eax, 0x30(%edx)\n"
        "addl $1, -0x10(%ebp)\n" /* line 584 | row */
        "movl -0x10(%ebp), %ecx\n" /* row */
        "cmpl %ecx, 0x14(%ebp)\n" /* num_rows */
        "je .Lf202155_00202291\n"
        ".Lf202155_00202270:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf202155_00202198\n"
        ".Lf202155_00202277:\n"
        "movl %esi, %edx\n"
        "movl -0x18(%ebp), %eax\n" /* line 604 | row_index */
        "addl $1, %eax\n"
        "andl $0xf, %eax\n"
        "movl %eax, 0x30(%edx)\n"
        "addl $1, -0x10(%ebp)\n" /* line 584 | row */
        "movl -0x10(%ebp), %ecx\n" /* row */
        "cmpl %ecx, 0x14(%ebp)\n" /* num_rows */
        "jne .Lf202155_00202270\n"
        ".Lf202155_00202291:\n"
        "addl $0x38, %esp\n" /* line 606 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 613 */
static __attribute__((naked))
void quantize_fs_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 613 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x90, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x1b0(%eax), %edx\n" /* line 614 */
        "movl %edx, -0xc(%ebp)\n"
        "movl 0x6c(%eax), %ecx\n" /* line 626 */
        "movl %ecx, -0x40(%ebp)\n" /* nc */
        "movl 0x64(%eax), %edx\n" /* line 632 */
        "movl %edx, -0x2c(%ebp)\n" /* width */
        "movl 0x128(%eax), %eax\n" /* line 633 */
        "movl %eax, -0x28(%ebp)\n" /* range_limit */
        "movl 0x14(%ebp), %esi\n" /* line 636 | num_rows */
        "testl %esi, %esi\n"
        "jg .Lf202298_002022d5\n"
        ".Lf202298_002022cb:\n"
        "addl $0x90, %esp\n" /* line 714 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf202298_002022d5:\n"
        "subl $1, %edx\n" /* line 645 */
        "imull %ecx, %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 649 | width */
        "addl %ecx, %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* row */
        "movl -0x30(%ebp), %eax\n" /* row */
        ".Lf202298_002022f0:\n"
        "shll $2, %eax\n" /* line 613 */
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* output_buf */
        "addl %eax, %edx\n"
        "movl %edx, -0x18(%ebp)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 638 | width */
        "movl %ecx, 4(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "movl -0x40(%ebp), %ecx\n" /* line 640 | nc */
        "testl %ecx, %ecx\n"
        "jle .Lf202298_0020249c\n"
        "movl -0xc(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* ci */
        "movl -0x34(%ebp), %eax\n" /* ci */
        "jmp .Lf202298_00202396\n"
        ".Lf202298_0020232c:\n"
        "movl %edx, %ecx\n"
        "movl -0x60(%ebp), %edx\n" /* line 645 */
        "addl %edx, %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* input_ptr */
        "movl -0x2c(%ebp), %eax\n" /* line 646 | width */
        "leal -1(%ecx, %eax), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n" /* output_ptr */
        "movl -0x40(%ebp), %eax\n" /* line 648 | nc */
        "negl %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* dirnc */
        "movl -0x5c(%ebp), %eax\n" /* line 649 */
        "movl -0x1c(%ebp), %edx\n"
        "addl 0x44(%edx), %eax\n"
        "leal 2(%eax), %edi\n" /* errorptr */
        "movl $0xffffffff, -0x3c(%ebp)\n" /* dir */
        "movl -0x34(%ebp), %eax\n" /* line 654 | ci */
        "shll $2, %eax\n"
        "movl -0xc(%ebp), %ecx\n" /* line 656 */
        "movl 0x18(%ecx), %edx\n"
        "movl (%eax, %edx), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* colorindex_ci */
        "movl 0x10(%ecx), %edx\n" /* line 657 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* colormap_ci */
        "movl -0x2c(%ebp), %edx\n" /* line 663 | width */
        "testl %edx, %edx\n"
        "jne .Lf202298_002023ec\n"
        ".Lf202298_0020237d:\n"
        "xorl %eax, %eax\n"
        "movw %ax, (%edi)\n" /* line 710 | errorptr */
        "addl $1, -0x34(%ebp)\n" /* line 640 | ci */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* ci */
        "cmpl %eax, -0x40(%ebp)\n" /* nc */
        "je .Lf202298_0020249c\n"
        ".Lf202298_00202396:\n"
        "movl 0xc(%ebp), %edx\n" /* line 641 | input_buf */
        "movl -0x14(%ebp), %ecx\n"
        "addl (%edx, %ecx), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* input_ptr */
        "movl -0x18(%ebp), %edx\n" /* line 642 */
        "movl (%edx), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* output_ptr */
        "movl -0xc(%ebp), %ecx\n" /* line 643 */
        "cmpb $0, 0x54(%ecx)\n"
        "jne .Lf202298_0020232c\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 654 */
        "movl 0x44(%ecx), %edi\n" /* errorptr */
        "movl -0x40(%ebp), %eax\n" /* nc */
        "movl %eax, -0x38(%ebp)\n" /* dirnc */
        "movl $1, -0x3c(%ebp)\n" /* dir */
        "movl -0x34(%ebp), %eax\n" /* ci */
        "shll $2, %eax\n"
        "movl -0xc(%ebp), %ecx\n" /* line 656 */
        "movl 0x18(%ecx), %edx\n"
        "movl (%eax, %edx), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* colorindex_ci */
        "movl 0x10(%ecx), %edx\n" /* line 657 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* colormap_ci */
        "movl -0x2c(%ebp), %edx\n" /* line 663 | width */
        "testl %edx, %edx\n"
        "je .Lf202298_0020237d\n"
        ".Lf202298_002023ec:\n"
        "movl -0x3c(%ebp), %eax\n" /* dir */
        "addl %eax, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edi, -0x10(%ebp)\n" /* errorptr */
        "xorl %edx, %edx\n"
        "movl $0, -0x58(%ebp)\n" /* belowerr */
        "movl $0, -0x54(%ebp)\n" /* bpreverr */
        "movl $0, -0x20(%ebp)\n"
        "jmp .Lf202298_00202413\n"
        ".Lf202298_00202410:\n"
        "movl %edi, -0x10(%ebp)\n" /* errorptr */
        ".Lf202298_00202413:\n"
        "addl -0x24(%ebp), %edi\n" /* line 672 | errorptr */
        "movswl (%edi), %eax\n" /* errorptr */
        "leal 8(%edx, %eax), %eax\n"
        "sarl $4, %eax\n"
        "movl -0x50(%ebp), %ecx\n" /* line 678 | input_ptr */
        "movzbl (%ecx), %edx\n"
        "addl -0x28(%ebp), %eax\n" /* range_limit */
        "movzbl (%eax, %edx), %esi\n"
        "movl -0x48(%ebp), %edx\n" /* line 680 | colorindex_ci */
        "movzbl (%edx, %esi), %eax\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 681 | output_ptr */
        "addb %al, (%ecx)\n"
        "movl -0x44(%ebp), %edx\n" /* line 685 | colormap_ci */
        "movzbl (%edx, %eax), %eax\n"
        "subl %eax, %esi\n"
        "leal (%esi, %esi), %ecx\n" /* line 691 */
        "leal (%esi, %ecx), %eax\n" /* line 692 */
        "movl %eax, -0x7c(%ebp)\n"
        "movl -0x54(%ebp), %edx\n" /* line 693 | bpreverr */
        "addl %eax, %edx\n"
        "movl -0x10(%ebp), %eax\n"
        "movw %dx, (%eax)\n"
        "movl -0x7c(%ebp), %edx\n" /* line 694 */
        "leal (%ecx, %edx), %eax\n"
        "movl -0x58(%ebp), %edx\n" /* line 695 | belowerr */
        "addl %eax, %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* bpreverr */
        "leal (%ecx, %eax), %edx\n" /* line 697 */
        "movl -0x38(%ebp), %ecx\n" /* line 702 | dirnc */
        "addl %ecx, -0x50(%ebp)\n" /* input_ptr */
        "movl -0x3c(%ebp), %eax\n" /* line 703 | dir */
        "addl %eax, -0x4c(%ebp)\n" /* output_ptr */
        "addl $1, -0x20(%ebp)\n"
        "movl %esi, -0x58(%ebp)\n" /* belowerr */
        "movl -0x20(%ebp), %ecx\n" /* line 663 */
        "cmpl %ecx, -0x2c(%ebp)\n" /* width */
        "jne .Lf202298_00202410\n"
        "movl -0x54(%ebp), %eax\n" /* bpreverr */
        "movw %ax, (%edi)\n" /* line 710 | errorptr */
        "addl $1, -0x34(%ebp)\n" /* line 640 | ci */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* ci */
        "cmpl %eax, -0x40(%ebp)\n" /* nc */
        "jne .Lf202298_00202396\n"
        ".Lf202298_0020249c:\n"
        "movl -0xc(%ebp), %edx\n" /* line 712 */
        "cmpb $0, 0x54(%edx)\n"
        "sete 0x54(%edx)\n"
        "addl $1, -0x30(%ebp)\n" /* line 636 | row */
        "movl -0x30(%ebp), %ecx\n" /* row */
        "cmpl %ecx, 0x14(%ebp)\n" /* num_rows */
        "je .Lf202298_002022cb\n"
        "movl %ecx, %eax\n"
        "jmp .Lf202298_002022f0\n"
    );
}

/* line 799 */
static __attribute__((naked))
void finish_pass_1_quant(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 799 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 801 */
        "retl\n"
    );
}

/* line 811 */
static __attribute__((naked))
void new_color_map_1_quant(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 811 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl (%eax), %edx\n" /* line 812 */
        "movl $0x2e, 0x14(%edx)\n"
        "movl (%eax), %edx\n"
        "movl %eax, 8(%ebp)\n" /* cinfo */
        "movl (%edx), %ecx\n"
        "popl %ebp\n" /* line 813 */
        "jmpl *%ecx\n" /* line 812 */
    );
}

/* line 334 */
static __attribute__((naked))
void create_colorindex(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: maxj */
        "pushl %ebp\n" /* line 334 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x60, %esp\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x1b0(%eax), %eax\n" /* line 335 */
        "movl %eax, -0x2c(%ebp)\n" /* cquantize */
        "movl -0x30(%ebp), %edx\n" /* line 344 */
        "cmpl $1, 0x54(%edx)\n"
        "je .Lf2024dc_0020265e\n"
        "movl -0x2c(%ebp), %esi\n" /* line 349 | cquantize */
        "movb $0, 0x1c(%esi)\n"
        "movl $0, -0x1c(%ebp)\n" /* pad */
        "movl $0x100, %ecx\n"
        ".Lf2024dc_00202510:\n"
        "movl -0x30(%ebp), %edi\n" /* line 352 | val */
        "movl 4(%edi), %eax\n" /* val */
        "movl 0x6c(%edi), %edx\n" /* val */
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* val */
        "calll *8(%eax)\n"
        "movl -0x2c(%ebp), %edx\n" /* cquantize */
        "movl %eax, 0x18(%edx)\n"
        "movl 0x14(%edx), %esi\n" /* line 358 */
        "movl %esi, -0x20(%ebp)\n" /* blksize */
        "movl 0x6c(%edi), %eax\n" /* line 360 | val */
        "testl %eax, %eax\n"
        "jle .Lf2024dc_00202657\n"
        "movl %edx, -0x10(%ebp)\n"
        "movl $0, -0x24(%ebp)\n" /* i */
        "movl $0, -0x14(%ebp)\n"
        ".Lf2024dc_00202557:\n"
        "movl -0x10(%ebp), %edi\n" /* line 362 | val */
        "movl 0x20(%edi), %ecx\n" /* val */
        "movl -0x20(%ebp), %eax\n" /* line 363 | blksize */
        "cltd\n"
        "idivl %ecx\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %eax, -0x20(%ebp)\n" /* blksize */
        "movl -0x1c(%ebp), %eax\n" /* line 366 | pad */
        "testl %eax, %eax\n"
        "je .Lf2024dc_0020257f\n"
        "movl -0x14(%ebp), %eax\n" /* line 367 */
        "movl -0x2c(%ebp), %edx\n" /* cquantize */
        "addl 0x18(%edx), %eax\n"
        "addl $0xff, (%eax)\n"
        ".Lf2024dc_0020257f:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 371 | cquantize */
        "movl 0x18(%esi), %eax\n"
        "movl -0x14(%ebp), %edi\n" /* val */
        "movl (%eax, %edi), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* indexptr */
        "leal -1(%ecx), %eax\n" /* line 373 */
        "movl %eax, -0x18(%ebp)\n" /* maxj */
        /* { scope 2 */
        "addl %eax, %eax\n" /* line 264 */
        "movl %eax, -0x4c(%ebp)\n"
        "leal 0xfe(%ecx), %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl -0x4c(%ebp)\n"
        "movl %eax, %ecx\n"
        "xorl %edi, %edi\n"
        "movl $0, -0xc(%ebp)\n"
        /* } scope */
        ".Lf2024dc_002025b0:\n"
        "cmpl -0xc(%ebp), %ecx\n" /* line 375 */
        "jge .Lf2024dc_002025e6\n"
        "leal (%edi, %edi), %edx\n" /* val */
        "movl %edi, %eax\n" /* val */
        "shll $9, %eax\n"
        "subl %edx, %eax\n"
        "movl -0x18(%ebp), %edx\n" /* maxj */
        "leal 0x2fd(%edx, %eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "jmp .Lf2024dc_002025d1\n"
        ".Lf2024dc_002025ce:\n"
        "movl -0x3c(%ebp), %eax\n"
        ".Lf2024dc_002025d1:\n"
        "addl $1, %edi\n" /* line 376 | val */
        "cltd\n" /* line 264 */
        "idivl -0x4c(%ebp)\n"
        "movl %eax, %ecx\n"
        "addl $0x1fe, -0x3c(%ebp)\n"
        "cmpl -0xc(%ebp), %eax\n" /* line 375 */
        "jl .Lf2024dc_002025ce\n"
        ".Lf2024dc_002025e6:\n"
        "movl -0x34(%ebp), %edx\n" /* line 378 */
        "imull %edi, %edx\n" /* val */
        "movl -0xc(%ebp), %esi\n"
        "movl -0x28(%ebp), %eax\n" /* indexptr */
        "movb %dl, (%esi, %eax)\n"
        "addl $1, %esi\n" /* line 374 */
        "movl %esi, -0xc(%ebp)\n"
        "cmpl $0x100, %esi\n"
        "jne .Lf2024dc_002025b0\n"
        "movl -0x1c(%ebp), %edi\n" /* line 381 | pad, val */
        "testl %edi, %edi\n" /* val */
        "je .Lf2024dc_0020263c\n"
        "movl -0x28(%ebp), %esi\n" /* indexptr */
        "addl $0xff, %esi\n"
        "movl $1, %ecx\n"
        "movl $0xff, %edx\n"
        ".Lf2024dc_0020261d:\n"
        "movl -0x28(%ebp), %edi\n" /* line 383 | indexptr, val */
        "movzbl (%edi), %eax\n" /* val */
        "movb %al, -0x100(%edi, %edx)\n" /* val */
        "movzbl (%esi), %eax\n" /* line 384 */
        "movb %al, 0xff(%edi, %ecx)\n" /* val */
        "addl $1, %ecx\n" /* line 382 */
        "subl $1, %edx\n"
        "jne .Lf2024dc_0020261d\n"
        ".Lf2024dc_0020263c:\n"
        "addl $1, -0x24(%ebp)\n" /* line 360 | i */
        "addl $4, -0x14(%ebp)\n"
        "addl $4, -0x10(%ebp)\n"
        "movl -0x24(%ebp), %edx\n" /* i */
        "movl -0x30(%ebp), %eax\n"
        "cmpl %edx, 0x6c(%eax)\n"
        "jg .Lf2024dc_00202557\n"
        ".Lf2024dc_00202657:\n"
        "addl $0x60, %esp\n" /* line 387 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2024dc_0020265e:\n"
        "movb $1, 0x1c(%eax)\n" /* line 346 */
        "movl $0x1fe, -0x1c(%ebp)\n" /* pad */
        "movl $0x2fe, %ecx\n"
        "jmp .Lf2024dc_00202510\n"
    );
}

/* line 822 */
__attribute__((naked))
void jinit_1pass_quantizer(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 822 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edx\n" /* line 825 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x58, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 828 | cinfo */
        "movl %eax, 0x1b0(%ecx)\n"
        "leal 0x3db(%ebx), %edx\n" /* line 829 */
        "movl %edx, (%eax)\n"
        "leal -0x1c3(%ebx), %edx\n" /* line 830 */
        "movl %edx, 8(%eax)\n"
        "leal -0x1be(%ebx), %edx\n" /* line 831 */
        "movl %edx, 0xc(%eax)\n"
        "movl $0, 0x44(%eax)\n" /* line 832 */
        "movl $0, 0x34(%eax)\n" /* line 833 */
        "cmpl $4, 0x6c(%ecx)\n" /* line 836 */
        "jg .Lf202673_002029aa\n"
        ".Lf202673_002026d7:\n"
        "movl 8(%ebp), %esi\n" /* line 839 | cinfo, nc */
        "cmpl $0x100, 0x5c(%esi)\n" /* nc */
        "jg .Lf202673_00202986\n"
        "movl %esi, %edi\n" /* nc, i */
        "movl %esi, %eax\n" /* nc */
        /* { scope 1: Ncolors, j, ci */
        ".Lf202673_002026eb:\n"
        "movl 0x1b0(%edi), %edi\n" /* line 275 */
        "movl %edi, -0x58(%ebp)\n" /* cquantize */
        "addl $0x20, %edi\n" /* line 281 */
        "movl %edi, -0x4c(%ebp)\n" /* Ncolors */
        /* { scope 2: max_colors, j, changed */
        /* { scope 3 */
        "movl 0x6c(%eax), %esi\n" /* line 191 | nc */
        "movl 0x5c(%eax), %edx\n" /* line 192 */
        "movl %edx, -0x48(%ebp)\n" /* max_colors */
        "movl $1, %ecx\n"
        "jmp .Lf202673_00202711\n"
        ".Lf202673_0020270a:\n"
        "movl %ecx, %edx\n" /* line 204 */
        "cmpl %edx, -0x48(%ebp)\n" /* line 206 | max_colors */
        "jl .Lf202673_0020272f\n"
        ".Lf202673_00202711:\n"
        "addl $1, %ecx\n" /* line 202 */
        "cmpl $1, %esi\n" /* line 204 | nc */
        "jle .Lf202673_0020270a\n"
        "movl %ecx, %edx\n"
        "movl $1, %eax\n"
        ".Lf202673_00202720:\n"
        "imull %ecx, %edx\n" /* line 205 */
        "addl $1, %eax\n" /* line 204 */
        "cmpl %eax, %esi\n" /* nc */
        "jne .Lf202673_00202720\n"
        "cmpl %edx, -0x48(%ebp)\n" /* line 206 | max_colors */
        "jge .Lf202673_00202711\n"
        ".Lf202673_0020272f:\n"
        "leal -1(%ecx), %edi\n" /* line 207 */
        "cmpl $1, %edi\n" /* line 210 */
        "jle .Lf202673_002029c8\n"
        ".Lf202673_0020273b:\n"
        "testl %esi, %esi\n" /* line 215 | nc */
        "jg .Lf202673_002028b1\n"
        "movl $1, -0x20(%ebp)\n"
        ".Lf202673_0020274a:\n"
        "testl %esi, %esi\n" /* line 227 | nc */
        "jg .Lf202673_002029e5\n"
        "movl -0x20(%ebp), %esi\n" /* nc */
        "movl %esi, -0x1c(%ebp)\n" /* nc */
        /* } scope */
        /* } scope */
        ".Lf202673_00202758:\n"
        "movl 8(%ebp), %ecx\n" /* line 284 | cinfo */
        "cmpl $3, 0x6c(%ecx)\n"
        "je .Lf202673_00202948\n"
        "movl %ecx, %edx\n"
        "movl (%ecx), %eax\n" /* line 289 */
        "movl $0x5f, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl -0x20(%ebp), %ecx\n"
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf202673_00202788:\n"
        "movl 8(%ebp), %esi\n" /* line 295 | cinfo, nc */
        "movl 4(%esi), %edx\n" /* nc */
        "movl 0x6c(%esi), %eax\n" /* nc */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %edi\n"
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* nc */
        "calll *8(%edx)\n"
        "movl %eax, -0x54(%ebp)\n" /* colormap */
        "movl 0x6c(%esi), %edx\n" /* line 303 | nc */
        "testl %edx, %edx\n"
        "jle .Lf202673_0020288a\n"
        "movl -0x58(%ebp), %eax\n" /* cquantize */
        "movl %eax, -0x28(%ebp)\n"
        "movl $0, -0x38(%ebp)\n" /* ci */
        "movl %eax, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        ".Lf202673_002027ca:\n"
        "movl 0x20(%edx), %edx\n" /* line 305 */
        "movl %edx, -0x50(%ebp)\n" /* nci */
        "cltd\n" /* line 306 */
        "idivl -0x50(%ebp)\n" /* nci */
        "movl %eax, -0x74(%ebp)\n"
        "movl -0x50(%ebp), %eax\n" /* line 307 | nci */
        "testl %eax, %eax\n"
        "jle .Lf202673_00202869\n"
        "movl -0x50(%ebp), %edx\n" /* nci */
        "subl $1, %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n" /* j */
        /* { scope 2: max_colors, j, changed */
        ".Lf202673_002027fe:\n"
        "cltd\n" /* line 254 */
        "idivl -0x30(%ebp)\n"
        "movl %eax, -0x5c(%ebp)\n"
        /* } scope */
        "movl -0x3c(%ebp), %edx\n" /* line 311 | j */
        "imull -0x74(%ebp), %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* ptr */
        "movl -0x20(%ebp), %ecx\n"
        "cmpl %ecx, %edx\n"
        "jge .Lf202673_00202851\n"
        ".Lf202673_00202816:\n"
        "movl -0x74(%ebp), %eax\n" /* line 313 */
        "testl %eax, %eax\n"
        "jle .Lf202673_00202843\n"
        "movzbl -0x5c(%ebp), %edx\n"
        "movb %dl, -0x69(%ebp)\n"
        "xorl %edx, %edx\n"
        ".Lf202673_00202826:\n"
        "movl %edx, %eax\n" /* line 314 */
        "movl -0x38(%ebp), %esi\n" /* ci, nc */
        "movl -0x54(%ebp), %edi\n" /* colormap */
        "addl (%edi, %esi, 4), %eax\n"
        "movzbl -0x69(%ebp), %ecx\n"
        "movl -0x70(%ebp), %esi\n" /* ptr, nc */
        "movb %cl, (%eax, %esi)\n"
        "addl $1, %edx\n" /* line 313 */
        "cmpl %edx, -0x74(%ebp)\n"
        "jne .Lf202673_00202826\n"
        ".Lf202673_00202843:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 311 */
        "addl %edi, -0x70(%ebp)\n" /* ptr */
        "movl -0x20(%ebp), %eax\n"
        "cmpl %eax, -0x70(%ebp)\n" /* ptr */
        "jl .Lf202673_00202816\n"
        ".Lf202673_00202851:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 307 | j */
        "addl $0xff, -0x2c(%ebp)\n"
        "movl -0x3c(%ebp), %ecx\n" /* j */
        "cmpl %ecx, -0x50(%ebp)\n" /* nci */
        "je .Lf202673_00202869\n"
        "movl -0x2c(%ebp), %eax\n"
        "jmp .Lf202673_002027fe\n"
        ".Lf202673_00202869:\n"
        "addl $1, -0x38(%ebp)\n" /* line 303 | ci */
        "addl $4, -0x28(%ebp)\n"
        "movl -0x38(%ebp), %esi\n" /* ci, nc */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl 0x6c(%edi), %esi\n" /* nc */
        "jge .Lf202673_002028d5\n"
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf202673_002027ca\n"
        ".Lf202673_0020288a:\n"
        "movl %eax, %ecx\n"
        "movl -0x58(%ebp), %edx\n" /* line 323 | cquantize */
        "movl %ecx, 0x10(%edx)\n"
        "movl -0x20(%ebp), %esi\n" /* line 324 | nc */
        "movl %esi, 0x14(%edx)\n" /* nc */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 844 | cinfo */
        "calll create_colorindex\n"
        "movl 8(%ebp), %edi\n" /* line 852 | cinfo, i */
        "cmpl $2, 0x54(%edi)\n" /* i */
        "je .Lf202673_002028f5\n"
        ".Lf202673_002028a9:\n"
        "addl $0x7c, %esp\n" /* line 854 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Ncolors, j, ci */
        /* { scope 2: max_colors, j, changed */
        /* { scope 3 */
        ".Lf202673_002028b1:\n"
        "xorl %eax, %eax\n" /* line 215 */
        "movl $1, -0x20(%ebp)\n"
        ".Lf202673_002028ba:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 216 | Ncolors */
        "movl %edi, (%edx, %eax, 4)\n"
        "movl -0x20(%ebp), %ecx\n" /* line 217 */
        "imull %edi, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "addl $1, %eax\n" /* line 215 */
        "cmpl %eax, %esi\n" /* nc */
        "jne .Lf202673_002028ba\n"
        "jmp .Lf202673_0020274a\n"
        ".Lf202673_002028d5:\n"
        "movl -0x54(%ebp), %ecx\n" /* colormap */
        /* } scope */
        /* } scope */
        "movl -0x58(%ebp), %edx\n" /* line 323 | cquantize */
        "movl %ecx, 0x10(%edx)\n"
        "movl -0x20(%ebp), %esi\n" /* line 324 | nc */
        "movl %esi, 0x14(%edx)\n" /* nc */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 844 | cinfo */
        "calll create_colorindex\n"
        "movl 8(%ebp), %edi\n" /* line 852 | cinfo, i */
        "cmpl $2, 0x54(%edi)\n" /* i */
        "jne .Lf202673_002028a9\n"
        /* { scope 1: Ncolors, j, ci */
        ".Lf202673_002028f5:\n"
        "movl 0x1b0(%edi), %edx\n" /* line 724 | cquantize */
        "movl 0x64(%edi), %eax\n" /* line 728 | i */
        "leal 4(%eax, %eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* arraysize */
        "movl 0x6c(%edi), %eax\n" /* line 729 | i */
        "testl %eax, %eax\n"
        "jle .Lf202673_002028a9\n"
        "movl %edx, %esi\n" /* nc */
        "xorl %edi, %edi\n" /* i */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf202673_00202917\n"
        ".Lf202673_00202915:\n"
        "movl %eax, %edx\n"
        ".Lf202673_00202917:\n"
        "movl 4(%edx), %eax\n" /* line 730 */
        "movl -0x34(%ebp), %ecx\n" /* arraysize */
        "movl %ecx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl %eax, 0x44(%esi)\n" /* nc */
        "addl $1, %edi\n" /* line 729 | i */
        "addl $4, %esi\n" /* nc */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl %edi, 0x6c(%eax)\n" /* i */
        "jg .Lf202673_00202915\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 854 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Ncolors, j, ci */
        /* { scope 2: max_colors, j, changed */
        ".Lf202673_00202948:\n"
        "movl (%ecx), %eax\n" /* line 285 */
        "leal 0x18(%eax), %edx\n" /* _mp */
        "movl -0x20(%ebp), %esi\n" /* nc */
        "movl %esi, 0x18(%eax)\n" /* nc */
        "movl -0x58(%ebp), %edi\n" /* cquantize */
        "movl 0x20(%edi), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 0x24(%edi), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0x28(%edi), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl $0x5e, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "jmp .Lf202673_00202788\n"
        /* } scope */
        /* } scope */
        ".Lf202673_00202986:\n"
        "movl (%esi), %eax\n" /* line 840 | nc */
        "movl $0x39, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* nc */
        "movl $0x100, 0x18(%eax)\n"
        "movl (%esi), %eax\n" /* nc */
        "movl %esi, (%esp)\n" /* nc */
        "calll *(%eax)\n"
        "movl 8(%ebp), %edi\n" /* cinfo, i */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf202673_002026eb\n"
        ".Lf202673_002029aa:\n"
        "movl (%ecx), %eax\n" /* line 837 */
        "movl $0x37, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $4, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf202673_002026d7\n"
        /* { scope 1: Ncolors, j, ci */
        /* { scope 2: max_colors, j, changed */
        /* { scope 3 */
        ".Lf202673_002029c8:\n"
        "movl 8(%ebp), %ecx\n" /* line 211 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x38, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf202673_0020273b\n"
        ".Lf202673_002029e5:\n"
        "movl -0x20(%ebp), %edi\n" /* line 227 */
        "movl %edi, -0x1c(%ebp)\n"
        "leal 0x104cff(%ebx), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        ".Lf202673_002029f4:\n"
        "movl $0, -0x44(%ebp)\n" /* j */
        "movb $0, -0x3d(%ebp)\n" /* changed */
        "movl -0x60(%ebp), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        ".Lf202673_00202a05:\n"
        "movl 8(%ebp), %ecx\n" /* line 228 | cinfo */
        "cmpl $2, 0x34(%ecx)\n"
        "je .Lf202673_00202a44\n"
        "movl -0x44(%ebp), %eax\n" /* j */
        ".Lf202673_00202a11:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 230 | Ncolors */
        "leal (%edx, %eax, 4), %edi\n"
        "movl -0x1c(%ebp), %eax\n"
        "cltd\n"
        "idivl (%edi)\n"
        "movl %eax, %ecx\n"
        "movl (%edi), %eax\n" /* line 231 */
        "addl $1, %eax\n"
        "imull %eax, %ecx\n"
        "cmpl %ecx, -0x48(%ebp)\n" /* line 232 | max_colors */
        "jl .Lf202673_00202a4b\n"
        "movl %eax, (%edi)\n" /* line 234 */
        "addl $1, -0x44(%ebp)\n" /* line 227 | j */
        "addl $4, -0x24(%ebp)\n"
        "movb $1, -0x3d(%ebp)\n" /* changed */
        "movl %ecx, -0x1c(%ebp)\n"
        "cmpl -0x44(%ebp), %esi\n" /* j, nc */
        "jne .Lf202673_00202a05\n"
        "jmp .Lf202673_002029f4\n"
        ".Lf202673_00202a44:\n"
        "movl -0x24(%ebp), %edi\n" /* line 228 */
        "movl (%edi), %eax\n"
        "jmp .Lf202673_00202a11\n"
        ".Lf202673_00202a4b:\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 238 | changed */
        "jne .Lf202673_002029f4\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "jmp .Lf202673_00202758\n"
    );
}

/* line 742 */
static __attribute__((naked))
void start_pass_1_quant(j_decompress_ptr cinfo, int is_pre_scan)
{
    __asm__ __volatile__ (
        /* { scope 1: cquantize, odither, i, arraysize, ... */
        "pushl %ebp\n" /* line 742 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, -0x3c(%ebp)\n" /* cinfo */
        "movl 0x1b0(%eax), %esi\n" /* line 743 | cquantize */
        "movl 0x10(%esi), %eax\n" /* line 748 | cquantize */
        "movl -0x3c(%ebp), %edx\n" /* cinfo */
        "movl %eax, 0x7c(%edx)\n"
        "movl 0x14(%esi), %eax\n" /* line 749 | cquantize */
        "movl %eax, 0x78(%edx)\n"
        "movl 0x54(%edx), %eax\n" /* line 752 */
        "cmpl $1, %eax\n"
        "je .Lf202a5c_00202ad2\n"
        "jae .Lf202a5c_00202aad\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 754 | cinfo */
        "cmpl $3, 0x6c(%ecx)\n"
        "je .Lf202a5c_00202c2f\n"
        "leal -0xbaa(%ebx), %eax\n" /* line 757 */
        "movl %eax, 4(%esi)\n" /* cquantize */
        ".Lf202a5c_00202aa5:\n"
        "addl $0x4c, %esp\n" /* line 790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf202a5c_00202aad:\n"
        "cmpl $2, %eax\n" /* line 752 */
        "je .Lf202a5c_00202c40\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 787 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x30, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "addl $0x4c, %esp\n" /* line 790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 787 */
        ".Lf202a5c_00202ad2:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 760 | cinfo */
        "cmpl $3, 0x6c(%eax)\n"
        "je .Lf202a5c_00202ca2\n"
        "leal -0xa40(%ebx), %eax\n" /* line 763 */
        "movl %eax, 4(%esi)\n" /* cquantize */
        ".Lf202a5c_00202ae8:\n"
        "movl $0, 0x30(%esi)\n" /* line 764 | cquantize */
        "cmpb $0, 0x1c(%esi)\n" /* line 769 | cquantize */
        "je .Lf202a5c_00202c95\n"
        ".Lf202a5c_00202af9:\n"
        "movl 0x34(%esi), %eax\n" /* line 772 | cquantize */
        "testl %eax, %eax\n"
        "jne .Lf202a5c_00202aa5\n"
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 434 | cinfo */
        "movl 0x1b0(%edx), %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* cquantize */
        "movl -0x3c(%ebp), %ecx\n" /* line 438 | cinfo */
        "movl 0x6c(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf202a5c_00202aa5\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* i */
        "leal 0x104816(%ebx), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl 0x20(%edx), %esi\n" /* line 439 */
        "movl -0x2c(%ebp), %eax\n" /* line 441 | i */
        "testl %eax, %eax\n"
        "jle .Lf202a5c_00202b91\n"
        ".Lf202a5c_00202b33:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 442 | cquantize */
        "cmpl 0x20(%ecx), %esi\n"
        "je .Lf202a5c_00202c28\n"
        "movl %ecx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf202a5c_00202b43:\n"
        "addl $1, %ecx\n" /* line 441 */
        "cmpl %ecx, -0x2c(%ebp)\n" /* i */
        "je .Lf202a5c_00202b91\n"
        "movl 0x24(%edx), %eax\n" /* line 442 */
        "addl $4, %edx\n"
        "cmpl %esi, %eax\n"
        "jne .Lf202a5c_00202b43\n"
        ".Lf202a5c_00202b55:\n"
        "movl -0x34(%ebp), %eax\n" /* line 443 | cquantize */
        "movl 0x34(%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n" /* odither */
        "testl %ecx, %ecx\n" /* line 447 */
        "je .Lf202a5c_00202b91\n"
        "movl %ecx, %eax\n"
        ".Lf202a5c_00202b65:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 449 */
        "movl %eax, 0x34(%ecx)\n"
        "addl $1, -0x2c(%ebp)\n" /* line 438 | i */
        "addl $4, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %ecx\n" /* i */
        "movl -0x3c(%ebp), %edx\n" /* cinfo */
        "cmpl 0x6c(%edx), %ecx\n"
        "jge .Lf202a5c_00202aa5\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl 0x20(%edx), %esi\n" /* line 439 */
        "movl -0x2c(%ebp), %eax\n" /* line 441 | i */
        "testl %eax, %eax\n"
        "jg .Lf202a5c_00202b33\n"
        /* { scope 3: j */
        /* { scope 4 */
        ".Lf202a5c_00202b91:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 402 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, -0x30(%ebp)\n" /* odither */
        "shll $9, %esi\n" /* line 410 */
        "leal -0x200(%esi), %edi\n" /* den */
        "movl %eax, %edx\n"
        "movl $0, -0x28(%ebp)\n" /* j */
        ".Lf202a5c_00202bc1:\n"
        "movl -0x28(%ebp), %eax\n" /* j */
        "shll $4, %eax\n"
        "movl -0x44(%ebp), %ecx\n"
        "leal (%eax, %ecx), %esi\n"
        "movl %edx, %ecx\n"
        "leal 0x40(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "jmp .Lf202a5c_00202be7\n"
        ".Lf202a5c_00202bd7:\n"
        "cltd\n" /* line 418 */
        "idivl %edi\n" /* den */
        "movl %eax, (%ecx)\n"
        "addl $1, %esi\n"
        "addl $4, %ecx\n"
        "cmpl %ecx, -0x40(%ebp)\n" /* line 412 */
        "je .Lf202a5c_00202c11\n"
        ".Lf202a5c_00202be7:\n"
        "movzbl (%esi), %eax\n" /* line 413 */
        "leal (%eax, %eax), %edx\n"
        "shll $9, %eax\n"
        "subl %edx, %eax\n"
        "movl $0xfe01, %edx\n" /* line 418 */
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "jns .Lf202a5c_00202bd7\n"
        "negl %eax\n"
        "cltd\n"
        "idivl %edi\n" /* den */
        "negl %eax\n"
        "movl %eax, (%ecx)\n"
        "addl $1, %esi\n"
        "addl $4, %ecx\n"
        "cmpl %ecx, -0x40(%ebp)\n" /* line 412 */
        "jne .Lf202a5c_00202be7\n"
        ".Lf202a5c_00202c11:\n"
        "addl $1, -0x28(%ebp)\n" /* line 411 | j */
        "cmpl $0x10, -0x28(%ebp)\n" /* j */
        "je .Lf202a5c_00202c20\n"
        "movl -0x40(%ebp), %edx\n"
        "jmp .Lf202a5c_00202bc1\n"
        ".Lf202a5c_00202c20:\n"
        "movl -0x30(%ebp), %eax\n" /* odither */
        "jmp .Lf202a5c_00202b65\n"
        /* } scope */
        /* } scope */
        ".Lf202a5c_00202c28:\n"
        "xorl %ecx, %ecx\n" /* line 442 */
        "jmp .Lf202a5c_00202b55\n"
        /* } scope */
        ".Lf202a5c_00202c2f:\n"
        "leal -0xae1(%ebx), %eax\n" /* line 755 */
        "movl %eax, 4(%esi)\n" /* cquantize */
        "addl $0x4c, %esp\n" /* line 790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf202a5c_00202c40:\n"
        "leal -0x7d2(%ebx), %eax\n" /* line 776 */
        "movl %eax, 4(%esi)\n" /* cquantize */
        "movb $0, 0x54(%esi)\n" /* line 777 | cquantize */
        "movl 0x44(%esi), %eax\n" /* line 779 | cquantize */
        "testl %eax, %eax\n"
        "je .Lf202a5c_00202cb0\n"
        "movl -0x3c(%ebp), %edx\n" /* cinfo */
        "movl 0x64(%edx), %eax\n"
        "movl %edx, %ecx\n"
        ".Lf202a5c_00202c5c:\n"
        "leal 4(%eax, %eax), %eax\n" /* line 782 */
        "movl %eax, -0x38(%ebp)\n" /* arraysize */
        "movl 0x6c(%ecx), %ecx\n" /* line 783 */
        "testl %ecx, %ecx\n"
        "jle .Lf202a5c_00202aa5\n"
        "xorl %edi, %edi\n" /* i */
        ".Lf202a5c_00202c70:\n"
        "movl -0x38(%ebp), %eax\n" /* line 784 | arraysize */
        "movl %eax, 4(%esp)\n"
        "movl 0x44(%esi), %eax\n" /* cquantize */
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "addl $1, %edi\n" /* line 783 | i */
        "addl $4, %esi\n" /* cquantize */
        "movl -0x3c(%ebp), %edx\n" /* cinfo */
        "cmpl 0x6c(%edx), %edi\n" /* i */
        "jl .Lf202a5c_00202c70\n"
        "jmp .Lf202a5c_00202aa5\n"
        ".Lf202a5c_00202c95:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 770 | cinfo */
        "calll create_colorindex\n"
        "jmp .Lf202a5c_00202af9\n"
        ".Lf202a5c_00202ca2:\n"
        "leal -0x915(%ebx), %eax\n" /* line 761 */
        "movl %eax, 4(%esi)\n" /* cquantize */
        "jmp .Lf202a5c_00202ae8\n"
        /* { scope 2 */
        ".Lf202a5c_00202cb0:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 724 | cinfo */
        "movl 0x1b0(%eax), %edx\n" /* cquantize */
        "movl 0x64(%eax), %eax\n" /* line 728 */
        "leal 4(%eax, %eax), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* arraysize */
        "movl -0x3c(%ebp), %ecx\n" /* line 729 | cinfo */
        "movl 0x6c(%ecx), %edi\n" /* den */
        "testl %edi, %edi\n" /* den */
        "jle .Lf202a5c_00202c5c\n"
        "movl %edx, %edi\n" /* den */
        "movl $0, -0x20(%ebp)\n" /* i */
        ".Lf202a5c_00202cd6:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 730 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl -0x24(%ebp), %ecx\n" /* arraysize */
        "movl %ecx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl %eax, 0x44(%edi)\n" /* den */
        "addl $1, -0x20(%ebp)\n" /* line 729 | i */
        "addl $4, %edi\n" /* den */
        "movl -0x20(%ebp), %edx\n" /* i */
        "movl -0x3c(%ebp), %eax\n" /* cinfo */
        "cmpl %edx, 0x6c(%eax)\n"
        "jg .Lf202a5c_00202cd6\n"
        "movl 0x64(%eax), %eax\n"
        "movl -0x3c(%ebp), %ecx\n" /* cinfo */
        "jmp .Lf202a5c_00202c5c\n"
    );
}

