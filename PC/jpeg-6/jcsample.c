/* ASM dump from: jcsample.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcsample.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_downsample(j_compress_ptr cinfo);
static void sep_downsample(j_compress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION in_row_index, JSAMPIMAGE output_buf, JDIMENSION out_row_group_index);
static void int_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data);
void jinit_downsampler(j_compress_ptr cinfo);
static void fullsize_smooth_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data);
static void fullsize_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data);
static void h2v1_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data);
static void h2v2_smooth_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data);
static void h2v2_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data);

/* line 76 */
static __attribute__((naked))
void start_pass_downsample(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 76 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 78 */
        "retl\n"
    );
}

/* line 117 */
static __attribute__((naked))
void sep_downsample(j_compress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION in_row_index, JSAMPIMAGE output_buf, JDIMENSION out_row_group_index)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %edx\n" /* line 118 | cinfo */
        "movl 0x158(%edx), %eax\n" /* downsample */
        "movl 0x48(%edx), %esi\n" /* line 123 | compptr */
        "movl 0x40(%edx), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf20d455_0020d477\n"
        "addl $0x30, %esp\n" /* line 129 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20d455_0020d477:\n"
        "movl 0x10(%ebp), %edx\n" /* line 123 | in_row_index */
        "shll $2, %edx\n"
        "movl %edx, -0x10(%ebp)\n"
        "movl %eax, %edi\n"
        "movl $1, -0xc(%ebp)\n"
        ".Lf20d455_0020d489:\n"
        "movl -0xc(%ebp), %ecx\n" /* line 117 */
        "shll $2, %ecx\n"
        "movl 0x18(%ebp), %eax\n" /* line 127 | out_row_group_index */
        "imull 0xc(%esi), %eax\n" /* compptr */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* output_buf */
        "movl -4(%eax, %ecx), %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0x10(%ebp), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* input_buf */
        "addl -4(%edx, %ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* compptr */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edi)\n"
        "movl -0xc(%ebp), %eax\n"
        "addl $0x54, %esi\n" /* line 124 | compptr */
        "addl $1, -0xc(%ebp)\n"
        "addl $4, %edi\n"
        "movl 8(%ebp), %edx\n" /* line 123 | cinfo */
        "cmpl %eax, 0x40(%edx)\n"
        "jg .Lf20d455_0020d489\n"
        "addl $0x30, %esp\n" /* line 129 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 142 */
static __attribute__((naked))
void int_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    __asm__ __volatile__ (
        /* { scope 1: input_cols */
        "pushl %ebp\n" /* line 142 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0xc(%ebp), %edx\n" /* line 145 | compptr */
        "movl 0x1c(%edx), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* output_cols */
        "movl 0xdc(%esi), %ecx\n" /* line 149 | outvalue */
        "movl %ecx, %eax\n"
        "movl %edx, %edi\n" /* v */
        "cltd\n"
        "idivl 8(%edi)\n" /* v */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0xe0(%esi), %eax\n" /* line 150 | outvalue */
        "movl %eax, -0x30(%ebp)\n"
        "cltd\n"
        "idivl 0xc(%edi)\n" /* v */
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x34(%ebp), %edi\n" /* line 151 | v */
        "imull %eax, %edi\n" /* v */
        "movl %edi, -0x24(%ebp)\n" /* v, numpix */
        "movl %edi, %eax\n" /* line 152 | v */
        "shrl $0x1f, %eax\n"
        "addl %edi, %eax\n" /* v */
        "sarl $1, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x24(%esi), %esi\n" /* line 158 | outvalue */
        "movl %esi, -0x10(%ebp)\n" /* outvalue, input_cols */
        /* { scope 2 */
        /* { scope 3 */
        "movl -0x18(%ebp), %edi\n" /* line 94 | output_cols, count */
        "imull -0x34(%ebp), %edi\n" /* count */
        "subl %esi, %edi\n" /* row, count */
        "testl %edi, %edi\n" /* line 96 | count */
        "jle .Lf20d4e1_0020d54c\n"
        "movl -0x30(%ebp), %ecx\n" /* line 97 */
        "testl %ecx, %ecx\n"
        "jg .Lf20d4e1_0020d619\n"
        /* } scope */
        /* } scope */
        ".Lf20d4e1_0020d54c:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 162 | compptr */
        "movl 0xc(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20d4e1_0020d612\n"
        "movl $0, -0x2c(%ebp)\n" /* inrow */
        "movl $0, -0x28(%ebp)\n" /* outrow */
        ".Lf20d4e1_0020d568:\n"
        "movl -0x28(%ebp), %edi\n" /* line 163 | outrow, v */
        "movl 0x14(%ebp), %eax\n" /* output_data */
        "movl (%eax, %edi, 4), %edi\n" /* v */
        "movl %edi, -0x14(%ebp)\n" /* v, outptr */
        "movl -0x18(%ebp), %eax\n" /* line 164 | output_cols */
        "testl %eax, %eax\n"
        "je .Lf20d4e1_0020d5f9\n"
        "movl $0, -0x20(%ebp)\n" /* outcol */
        "movl $0, -0x1c(%ebp)\n" /* outcol_h */
        "jmp .Lf20d4e1_0020d5b3\n"
        ".Lf20d4e1_0020d58b:\n"
        "xorl %esi, %esi\n" /* line 167 | outvalue */
        ".Lf20d4e1_0020d58d:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 173 */
        "addl %esi, %eax\n" /* outvalue */
        "cltd\n"
        "idivl -0x24(%ebp)\n" /* numpix */
        "movl -0x14(%ebp), %edx\n" /* outptr */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x14(%ebp)\n" /* outptr */
        "addl $1, -0x20(%ebp)\n" /* line 165 | outcol */
        "movl -0x34(%ebp), %ecx\n"
        "addl %ecx, -0x1c(%ebp)\n" /* outcol_h */
        "movl -0x20(%ebp), %edi\n" /* line 164 | outcol, v */
        "cmpl %edi, -0x18(%ebp)\n" /* v, output_cols */
        "je .Lf20d4e1_0020d5f9\n"
        ".Lf20d4e1_0020d5b3:\n"
        "movl -0x38(%ebp), %esi\n" /* line 167 | outvalue */
        "testl %esi, %esi\n" /* outvalue */
        "jle .Lf20d4e1_0020d58b\n"
        "movl -0x2c(%ebp), %eax\n" /* inrow */
        "movl 0x10(%ebp), %edx\n" /* input_data */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "xorl %edi, %edi\n" /* v */
        "xorl %esi, %esi\n" /* outvalue */
        ".Lf20d4e1_0020d5ca:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 168 | outcol_h */
        "addl (%eax), %edx\n"
        "movl -0x34(%ebp), %eax\n" /* line 169 */
        "testl %eax, %eax\n"
        "jle .Lf20d4e1_0020d5e8\n"
        "xorl %ecx, %ecx\n"
        ".Lf20d4e1_0020d5d8:\n"
        "movzbl (%edx), %eax\n" /* line 170 */
        "addl %eax, %esi\n" /* outvalue */
        "addl $1, %edx\n"
        "addl $1, %ecx\n" /* line 169 */
        "cmpl %ecx, -0x34(%ebp)\n"
        "jne .Lf20d4e1_0020d5d8\n"
        ".Lf20d4e1_0020d5e8:\n"
        "addl $1, %edi\n" /* line 167 | v */
        "addl $4, -0xc(%ebp)\n"
        "cmpl %edi, -0x38(%ebp)\n" /* v */
        "je .Lf20d4e1_0020d58d\n"
        "movl -0xc(%ebp), %eax\n"
        "jmp .Lf20d4e1_0020d5ca\n"
        ".Lf20d4e1_0020d5f9:\n"
        "movl -0x38(%ebp), %edx\n" /* line 175 */
        "addl %edx, -0x2c(%ebp)\n" /* inrow */
        "addl $1, -0x28(%ebp)\n" /* line 162 | outrow */
        "movl -0x28(%ebp), %ecx\n" /* outrow */
        "movl 0xc(%ebp), %edi\n" /* compptr, v */
        "cmpl %ecx, 0xc(%edi)\n" /* v */
        "jg .Lf20d4e1_0020d568\n"
        ".Lf20d4e1_0020d612:\n"
        "addl $0x34, %esp\n" /* line 177 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20d4e1_0020d619:\n"
        "xorl %esi, %esi\n" /* line 97 | row */
        ".Lf20d4e1_0020d61b:\n"
        "movl -0x10(%ebp), %eax\n" /* line 98 | input_cols */
        "movl 0x10(%ebp), %edx\n" /* input_data */
        "addl (%edx, %esi, 4), %eax\n"
        "movzbl -1(%eax), %ecx\n" /* line 99 */
        "leal (%eax, %edi), %edx\n"
        ".Lf20d4e1_0020d62b:\n"
        "movb %cl, (%eax)\n" /* line 101 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n" /* line 100 */
        "jne .Lf20d4e1_0020d62b\n"
        "addl $1, %esi\n" /* line 97 | row */
        "cmpl %esi, -0x30(%ebp)\n" /* row */
        "jne .Lf20d4e1_0020d61b\n"
        "jmp .Lf20d4e1_0020d54c\n"
    );
}

/* line 465 */
__attribute__((naked))
void jinit_downsampler(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 465 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edx\n" /* line 471 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x34, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, -0x28(%ebp)\n" /* downsample */
        "movl 8(%ebp), %edi\n" /* line 474 | cinfo */
        "movl %eax, 0x158(%edi)\n"
        "leal -0x1ff(%ebx), %eax\n" /* line 475 */
        "movl -0x28(%ebp), %edx\n" /* downsample */
        "movl %eax, (%edx)\n"
        "leal -0x1fa(%ebx), %eax\n" /* line 476 */
        "movl %eax, 4(%edx)\n"
        "movb $0, 8(%edx)\n" /* line 477 */
        "cmpb $0, 0xb7(%edi)\n" /* line 479 */
        "jne .Lf20d641_0020d81b\n"
        ".Lf20d641_0020d69b:\n"
        "movl 8(%ebp), %edi\n" /* line 483 | cinfo */
        "movl 0x48(%edi), %esi\n" /* compptr */
        "movl 0x40(%edi), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf20d641_0020d7ce\n"
        "movl -0x28(%ebp), %eax\n" /* downsample */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x24(%ebp)\n" /* ci */
        "movb $1, -0x1d(%ebp)\n" /* smoothok */
        "jmp .Lf20d641_0020d714\n"
        ".Lf20d641_0020d6bf:\n"
        "leal (%edx, %edx), %eax\n" /* line 494 */
        "cmpl %eax, %ecx\n"
        "je .Lf20d641_0020d78b\n"
        ".Lf20d641_0020d6ca:\n"
        "movl %ecx, %eax\n" /* line 507 */
        "movl %edx, %edi\n"
        "cltd\n"
        "idivl %edi\n"
        "testl %edx, %edx\n"
        "jne .Lf20d641_0020d773\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0xe0(%edx), %eax\n"
        "cltd\n"
        "idivl 0xc(%esi)\n" /* compptr */
        "testl %edx, %edx\n"
        "jne .Lf20d641_0020d773\n"
        "leal -0x16e(%ebx), %eax\n" /* line 510 */
        "movl -0x1c(%ebp), %edi\n"
        "movl %eax, 0xc(%edi)\n"
        "movb $0, -0x1d(%ebp)\n" /* smoothok */
        ".Lf20d641_0020d6fe:\n"
        "addl $1, -0x24(%ebp)\n" /* line 484 | ci */
        "addl $0x54, %esi\n" /* compptr */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 483 | ci */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl 0x40(%edi), %eax\n"
        "jge .Lf20d641_0020d75f\n"
        ".Lf20d641_0020d714:\n"
        "movl 8(%esi), %edx\n" /* line 485 | compptr */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0xdc(%edi), %ecx\n"
        "cmpl %ecx, %edx\n"
        "jne .Lf20d641_0020d6bf\n"
        "movl 0xc(%esi), %eax\n" /* compptr */
        "cmpl 0xe0(%edi), %eax\n"
        "jne .Lf20d641_0020d6bf\n"
        "movl 0xb8(%edi), %eax\n" /* line 488 */
        "testl %eax, %eax\n"
        "jne .Lf20d641_0020d830\n"
        "leal 0x421(%ebx), %eax\n" /* line 493 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "addl $1, -0x24(%ebp)\n" /* line 484 | ci */
        "addl $0x54, %esi\n" /* compptr */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 483 | ci */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl 0x40(%edi), %eax\n"
        "jl .Lf20d641_0020d714\n"
        ".Lf20d641_0020d75f:\n"
        "movl %edi, %edx\n"
        "movl 0xb8(%edx), %eax\n" /* line 516 */
        "testl %eax, %eax\n"
        "jne .Lf20d641_0020d7df\n"
        ".Lf20d641_0020d76b:\n"
        "addl $0x3c, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20d641_0020d773:\n"
        "movl 8(%ebp), %edx\n" /* line 512 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x26, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20d641_0020d6fe\n"
        ".Lf20d641_0020d78b:\n"
        "movl 0xc(%esi), %edi\n" /* line 494 | compptr */
        "movl %edi, -0x2c(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0xe0(%eax), %edi\n"
        "cmpl %edi, -0x2c(%ebp)\n"
        "je .Lf20d641_0020d806\n"
        "movl -0x2c(%ebp), %eax\n" /* line 498 */
        "addl %eax, %eax\n"
        "cmpl %edi, %eax\n"
        "jne .Lf20d641_0020d6ca\n"
        "movl 8(%ebp), %edi\n" /* line 501 | cinfo */
        "movl 0xb8(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf20d641_0020d848\n"
        "leal 0x89d(%ebx), %eax\n" /* line 506 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "jmp .Lf20d641_0020d6fe\n"
        ".Lf20d641_0020d7ce:\n"
        "movb $1, -0x1d(%ebp)\n" /* line 483 | smoothok */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0xb8(%edx), %eax\n" /* line 516 */
        "testl %eax, %eax\n"
        "je .Lf20d641_0020d76b\n"
        ".Lf20d641_0020d7df:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* smoothok */
        "jne .Lf20d641_0020d76b\n"
        "movl (%edx), %eax\n" /* line 517 */
        "movl $0x63, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "addl $0x3c, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20d641_0020d806:\n"
        "leal 0x4b2(%ebx), %eax\n" /* line 497 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "movb $0, -0x1d(%ebp)\n" /* smoothok */
        "jmp .Lf20d641_0020d6fe\n"
        ".Lf20d641_0020d81b:\n"
        "movl (%edi), %eax\n" /* line 480 */
        "movl $0x19, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20d641_0020d69b\n"
        ".Lf20d641_0020d830:\n"
        "leal 0x211(%ebx), %eax\n" /* line 489 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x28(%ebp), %edi\n" /* line 490 | downsample */
        "movb $1, 8(%edi)\n"
        "jmp .Lf20d641_0020d6fe\n"
        ".Lf20d641_0020d848:\n"
        "leal 0x583(%ebx), %eax\n" /* line 502 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x28(%ebp), %edi\n" /* line 503 | downsample */
        "movb $1, 8(%edi)\n"
        "jmp .Lf20d641_0020d6fe\n"
    );
}

/* line 394 */
static __attribute__((naked))
void fullsize_smooth_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    __asm__ __volatile__ (
        /* { scope 1: input_cols, num_rows, image_data */
        "pushl %ebp\n" /* line 394 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x50, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* line 397 | compptr */
        "movl 0x1c(%edx), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* output_cols */
        "movl 8(%ebp), %ecx\n" /* line 406 | cinfo */
        "movl 0x24(%ecx), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n" /* input_cols */
        "movl 8(%ebp), %edi\n" /* cinfo, lastcolsum */
        "movl 0xe0(%edi), %eax\n" /* lastcolsum */
        "addl $2, %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* num_rows */
        "movl 0x10(%ebp), %edx\n" /* input_data */
        "subl $4, %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* image_data */
        /* { scope 2 */
        /* { scope 3 */
        "movl -0x50(%ebp), %edi\n" /* line 94 | output_cols, count */
        "subl %ecx, %edi\n" /* count */
        "testl %edi, %edi\n" /* line 96 | count */
        "jle .Lf20d860_0020d8a9\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 97 | num_rows */
        "testl %ecx, %ecx\n"
        "jg .Lf20d860_0020da48\n"
        /* } scope */
        /* } scope */
        ".Lf20d860_0020d8a9:\n"
        "movl 8(%ebp), %edi\n" /* line 415 | cinfo, lastcolsum */
        "movl 0xb8(%edi), %edx\n" /* lastcolsum */
        "movl %edx, %eax\n"
        "shll $9, %eax\n"
        "movl $0x10000, -0x48(%ebp)\n" /* memberscale */
        "subl %eax, -0x48(%ebp)\n" /* memberscale */
        "shll $6, %edx\n" /* line 416 */
        "movl %edx, -0x44(%ebp)\n" /* neighscale */
        "movl 0xc(%ebp), %eax\n" /* line 418 | compptr */
        "movl 0xc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20d860_0020da41\n"
        "movl -0x50(%ebp), %edx\n" /* output_cols */
        "subl $2, %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl $1, -0x28(%ebp)\n"
        "jmp .Lf20d860_0020d929\n"
        ".Lf20d860_0020d8e7:\n"
        "movl -0x24(%ebp), %edi\n" /* line 435 | lastcolsum */
        ".Lf20d860_0020d8ea:\n"
        "movl -0x10(%ebp), %edx\n" /* line 447 */
        "movzbl (%edx), %eax\n"
        "movl -0x48(%ebp), %edx\n" /* line 450 | memberscale */
        "imull %eax, %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl %ecx, %edx\n"
        "subl %eax, %edx\n"
        "leal (%edi, %edx), %eax\n" /* lastcolsum */
        "leal (%ecx, %eax), %eax\n"
        "imull -0x44(%ebp), %eax\n" /* neighscale */
        "movl -0x58(%ebp), %ecx\n"
        "leal 0x8000(%ecx, %eax), %edx\n"
        "sarl $0x10, %edx\n"
        "movb %dl, (%esi)\n" /* below_ptr */
        "movl -0x28(%ebp), %eax\n"
        "addl $1, -0x28(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* line 418 | compptr, lastcolsum */
        "cmpl %eax, 0xc(%edi)\n" /* lastcolsum */
        "jle .Lf20d860_0020da41\n"
        ".Lf20d860_0020d929:\n"
        "movl -0x28(%ebp), %eax\n" /* line 394 */
        "shll $2, %eax\n"
        "movl 0x14(%ebp), %ecx\n" /* line 419 | output_data */
        "movl -4(%eax, %ecx), %ecx\n"
        "movl %ecx, -0xc(%ebp)\n"
        "addl 0x10(%ebp), %eax\n" /* line 394 | input_data */
        "movl -4(%eax), %edi\n" /* line 420 | lastcolsum */
        "movl %edi, -0x4c(%ebp)\n" /* lastcolsum, inptr */
        "movl -8(%eax), %ecx\n" /* line 421 */
        "movl (%eax), %esi\n" /* line 422 | below_ptr */
        "movzbl (%ecx), %eax\n" /* line 425 */
        "movzbl (%esi), %edx\n" /* below_ptr */
        "addl %edx, %eax\n"
        "movzbl (%edi), %edi\n" /* lastcolsum */
        "addl %edi, %eax\n" /* lastcolsum */
        "movl %eax, -0x24(%ebp)\n"
        "leal 1(%ecx), %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "leal 1(%esi), %edx\n" /* below_ptr */
        "movl %edx, -0x18(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 427 | inptr */
        "addl $1, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movzbl 1(%ecx), %eax\n" /* line 428 */
        "movzbl 1(%esi), %edx\n" /* below_ptr */
        "addl %edx, %eax\n"
        "movl -0x4c(%ebp), %ecx\n" /* inptr */
        "movzbl 1(%ecx), %edx\n"
        "leal (%eax, %edx), %ecx\n"
        "movl -0x48(%ebp), %edx\n" /* line 432 | memberscale */
        "imull %edi, %edx\n" /* lastcolsum */
        "movl -0x24(%ebp), %eax\n"
        "subl %edi, %eax\n" /* lastcolsum */
        "addl -0x24(%ebp), %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "imull -0x44(%ebp), %eax\n" /* neighscale */
        "leal 0x8000(%edx, %eax), %edx\n"
        "sarl $0x10, %edx\n"
        "movl -0xc(%ebp), %edi\n" /* lastcolsum */
        "movb %dl, (%edi)\n" /* lastcolsum */
        "movl %edi, %esi\n" /* lastcolsum, below_ptr */
        "addl $1, %esi\n" /* below_ptr */
        "movl -0x34(%ebp), %edi\n" /* line 435 | lastcolsum */
        "testl %edi, %edi\n" /* lastcolsum */
        "je .Lf20d860_0020d8e7\n"
        "movl -0x14(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x18(%ebp), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl -0x34(%ebp), %edi\n" /* lastcolsum */
        "addl %esi, %edi\n" /* below_ptr, lastcolsum */
        "movl %edi, -0x54(%ebp)\n" /* lastcolsum */
        "movl %eax, %edx\n"
        "jmp .Lf20d860_0020d9db\n"
        ".Lf20d860_0020d9d5:\n"
        "movl %edi, -0x20(%ebp)\n" /* lastcolsum */
        "movl -0x30(%ebp), %edx\n"
        ".Lf20d860_0020d9db:\n"
        "movl -0x10(%ebp), %eax\n" /* line 436 */
        "movzbl (%eax), %ecx\n"
        "addl $1, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movzbl 1(%edx), %eax\n" /* line 438 */
        "movl -0x2c(%ebp), %edi\n" /* lastcolsum */
        "movzbl 1(%edi), %edx\n" /* lastcolsum */
        "addl %edx, %eax\n"
        "movl -0x10(%ebp), %edi\n" /* lastcolsum */
        "movzbl (%edi), %edx\n" /* lastcolsum */
        "leal (%eax, %edx), %edi\n" /* lastcolsum */
        "movl -0x48(%ebp), %edx\n" /* line 442 | memberscale */
        "imull %ecx, %edx\n"
        "movl -0x20(%ebp), %eax\n"
        "subl %ecx, %eax\n"
        "addl -0x1c(%ebp), %eax\n"
        "leal (%edi, %eax), %eax\n" /* lastcolsum */
        "imull -0x44(%ebp), %eax\n" /* neighscale */
        "leal 0x8000(%edx, %eax), %edx\n"
        "sarl $0x10, %edx\n"
        "movb %dl, (%esi)\n" /* below_ptr */
        "addl $1, %esi\n" /* below_ptr */
        "addl $1, -0x30(%ebp)\n"
        "addl $1, -0x2c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 394 */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl %esi, -0x54(%ebp)\n" /* line 435 | below_ptr */
        "jne .Lf20d860_0020d9d5\n"
        "movl -0x54(%ebp), %esi\n" /* below_ptr */
        "movl %edi, %ecx\n" /* lastcolsum */
        "movl -0x20(%ebp), %edi\n" /* lastcolsum */
        "jmp .Lf20d860_0020d8ea\n"
        ".Lf20d860_0020da41:\n"
        "addl $0x50, %esp\n" /* line 453 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20d860_0020da48:\n"
        "xorl %esi, %esi\n" /* line 97 | row */
        ".Lf20d860_0020da4a:\n"
        "movl -0x40(%ebp), %eax\n" /* line 98 | input_cols */
        "movl -0x38(%ebp), %ecx\n" /* image_data */
        "addl (%ecx, %esi, 4), %eax\n"
        "movzbl -1(%eax), %ecx\n" /* line 99 */
        "leal (%eax, %edi), %edx\n"
        ".Lf20d860_0020da5a:\n"
        "movb %cl, (%eax)\n" /* line 101 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n" /* line 100 */
        "jne .Lf20d860_0020da5a\n"
        "addl $1, %esi\n" /* line 97 | row */
        "cmpl %esi, -0x3c(%ebp)\n" /* row, num_rows */
        "jne .Lf20d860_0020da4a\n"
        "jmp .Lf20d860_0020d8a9\n"
    );
}

/* line 189 */
static __attribute__((naked))
void fullsize_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x24(%esi), %eax\n" /* line 191 | cinfo */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xe0(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* output_data */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* input_data */
        "movl %eax, (%esp)\n"
        "calll jcopy_sample_rows\n"
        "movl 0x24(%esi), %edx\n" /* line 194 | cinfo */
        "movl %edx, -0x10(%ebp)\n" /* input_cols */
        "movl 0xe0(%esi), %esi\n" /* cinfo */
        "movl %esi, -0xc(%ebp)\n" /* cinfo, num_rows */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 94 | compptr */
        "movl 0x1c(%eax), %eax\n"
        "leal (, %eax, 8), %edi\n" /* count */
        "subl %edx, %edi\n" /* count */
        "testl %edi, %edi\n" /* line 96 | count */
        "jle .Lf20da70_0020dafa\n"
        "movl -0xc(%ebp), %eax\n" /* line 97 | num_rows */
        "testl %eax, %eax\n"
        "jle .Lf20da70_0020dafa\n"
        "xorl %esi, %esi\n" /* row */
        ".Lf20da70_0020dad9:\n"
        "movl -0x10(%ebp), %eax\n" /* line 98 | input_cols */
        "movl 0x14(%ebp), %edx\n" /* output_data */
        "addl (%edx, %esi, 4), %eax\n"
        "movzbl -1(%eax), %ecx\n" /* line 99 */
        "leal (%eax, %edi), %edx\n"
        ".Lf20da70_0020dae9:\n"
        "movb %cl, (%eax)\n" /* line 101 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n" /* line 100 */
        "jne .Lf20da70_0020dae9\n"
        "addl $1, %esi\n" /* line 97 | row */
        "cmpl %esi, -0xc(%ebp)\n" /* row, num_rows */
        "jne .Lf20da70_0020dad9\n"
        /* } scope */
        /* } scope */
        ".Lf20da70_0020dafa:\n"
        "addl $0x30, %esp\n" /* line 196 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 214 */
static __attribute__((naked))
void h2v1_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    __asm__ __volatile__ (
        /* { scope 1: input_cols, num_rows */
        "pushl %ebp\n" /* line 214 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0xc(%ebp), %ecx\n" /* line 217 | compptr */
        "movl 0x1c(%ecx), %eax\n"
        "leal (, %eax, 8), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* output_cols */
        "movl 0x24(%edx), %ecx\n" /* line 225 */
        "movl %ecx, -0x14(%ebp)\n" /* input_cols */
        "movl 0xe0(%edx), %edx\n"
        "movl %edx, -0x10(%ebp)\n" /* num_rows */
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, %edi\n" /* line 94 | count */
        "shll $4, %edi\n" /* count */
        "subl %ecx, %edi\n" /* count */
        "testl %edi, %edi\n" /* line 96 | count */
        "jle .Lf20db01_0020db3d\n"
        "movl -0x10(%ebp), %eax\n" /* line 97 | num_rows */
        "testl %eax, %eax\n"
        "jg .Lf20db01_0020dbaa\n"
        /* } scope */
        /* } scope */
        ".Lf20db01_0020db3d:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 228 | compptr */
        "movl 0xc(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20db01_0020dba3\n"
        "movl $1, -0xc(%ebp)\n"
        ".Lf20db01_0020db4e:\n"
        "movl -0xc(%ebp), %eax\n" /* line 214 */
        "shll $2, %eax\n"
        "movl 0x14(%ebp), %edx\n" /* line 229 | output_data */
        "movl -4(%edx, %eax), %esi\n" /* outptr */
        "movl 0x10(%ebp), %edx\n" /* line 230 | input_data */
        "movl -4(%edx, %eax), %ecx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 232 | output_cols */
        "testl %eax, %eax\n"
        "je .Lf20db01_0020db94\n"
        "movl $0, -0x18(%ebp)\n" /* bias */
        "xorl %edi, %edi\n" /* outcol */
        ".Lf20db01_0020db72:\n"
        "movzbl (%ecx), %eax\n" /* line 233 */
        "movzbl 1(%ecx), %edx\n"
        "addl %edx, %eax\n"
        "addl -0x18(%ebp), %eax\n" /* bias */
        "sarl $1, %eax\n"
        "movb %al, (%esi)\n" /* outptr */
        "addl $1, %esi\n" /* outptr */
        "xorl $1, -0x18(%ebp)\n" /* line 235 | bias */
        "addl $2, %ecx\n" /* line 236 */
        "addl $1, %edi\n" /* line 232 | outcol */
        "cmpl %edi, -0x1c(%ebp)\n" /* outcol, output_cols */
        "jne .Lf20db01_0020db72\n"
        ".Lf20db01_0020db94:\n"
        "movl -0xc(%ebp), %eax\n"
        "addl $1, -0xc(%ebp)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 228 | compptr */
        "cmpl %eax, 0xc(%ecx)\n"
        "jg .Lf20db01_0020db4e\n"
        ".Lf20db01_0020dba3:\n"
        "addl $0x14, %esp\n" /* line 239 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20db01_0020dbaa:\n"
        "xorl %esi, %esi\n" /* line 97 | row */
        ".Lf20db01_0020dbac:\n"
        "movl -0x14(%ebp), %eax\n" /* line 98 | input_cols */
        "movl 0x10(%ebp), %edx\n" /* input_data */
        "addl (%edx, %esi, 4), %eax\n"
        "movzbl -1(%eax), %ecx\n" /* line 99 */
        "leal (%eax, %edi), %edx\n"
        ".Lf20db01_0020dbbc:\n"
        "movb %cl, (%eax)\n" /* line 101 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n" /* line 100 */
        "jne .Lf20db01_0020dbbc\n"
        "addl $1, %esi\n" /* line 97 | row */
        "cmpl %esi, -0x10(%ebp)\n" /* row, num_rows */
        "jne .Lf20db01_0020dbac\n"
        "jmp .Lf20db01_0020db3d\n"
    );
}

/* line 294 */
static __attribute__((naked))
void h2v2_smooth_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    __asm__ __volatile__ (
        /* { scope 1: input_cols, num_rows, image_data */
        "pushl %ebp\n" /* line 294 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x60, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* line 297 | compptr */
        "movl 0x1c(%edx), %eax\n"
        "leal (, %eax, 8), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n" /* output_cols */
        "movl 8(%ebp), %esi\n" /* line 305 | cinfo, row */
        "movl 0x24(%esi), %esi\n" /* row */
        "movl %esi, -0x3c(%ebp)\n" /* row, input_cols */
        "movl 8(%ebp), %edi\n" /* cinfo, inptr0 */
        "movl 0xe0(%edi), %edx\n" /* inptr0 */
        "addl $2, %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* num_rows */
        "movl 0x10(%ebp), %ecx\n" /* input_data */
        "subl $4, %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* image_data */
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, %edi\n" /* line 94 | count */
        "shll $4, %edi\n" /* count */
        "subl %esi, %edi\n" /* row, count */
        "testl %edi, %edi\n" /* line 96 | count */
        "jle .Lf20dbd2_0020dc21\n"
        "movl -0x38(%ebp), %eax\n" /* line 97 | num_rows */
        "testl %eax, %eax\n"
        "jg .Lf20dbd2_0020dec4\n"
        /* } scope */
        /* } scope */
        ".Lf20dbd2_0020dc21:\n"
        "movl 8(%ebp), %ecx\n" /* line 321 | cinfo */
        "movl 0xb8(%ecx), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "shll $4, %eax\n"
        "movl $0x4000, -0x44(%ebp)\n" /* memberscale */
        "subl %eax, -0x44(%ebp)\n" /* memberscale */
        "shll $4, %edx\n" /* line 322 */
        "movl %edx, -0x40(%ebp)\n" /* neighscale */
        "movl 0xc(%ebp), %esi\n" /* line 325 | compptr, row */
        "movl 0xc(%esi), %ecx\n" /* row */
        "testl %ecx, %ecx\n"
        "jle .Lf20dbd2_0020debd\n"
        "movl -0x4c(%ebp), %edi\n" /* output_cols, inptr0 */
        "subl $2, %edi\n" /* inptr0 */
        "movl %edi, -0x30(%ebp)\n" /* inptr0 */
        "movl 0x10(%ebp), %eax\n" /* input_data */
        "movl %eax, -0x24(%ebp)\n"
        "movl $0, -0x50(%ebp)\n" /* outrow */
        ".Lf20dbd2_0020dc64:\n"
        "movl -0x50(%ebp), %edx\n" /* line 326 | outrow */
        "movl 0x14(%ebp), %ecx\n" /* output_data */
        "movl (%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* outptr */
        "movl -0x24(%ebp), %ecx\n" /* line 327 */
        "movl (%ecx), %edi\n" /* inptr0 */
        "movl 4(%ecx), %esi\n" /* line 328 | row */
        "movl %esi, -0x64(%ebp)\n" /* row, inptr1 */
        "movl -4(%ecx), %eax\n" /* line 329 */
        "movl %eax, -0x60(%ebp)\n" /* above_ptr */
        "movl 8(%ecx), %edx\n" /* line 330 */
        "movl %edx, -0x5c(%ebp)\n" /* below_ptr */
        "movzbl (%edi), %ecx\n" /* line 333 | inptr0 */
        "movzbl (%esi), %esi\n" /* row */
        "movl %esi, -0x58(%ebp)\n" /* row */
        "movzbl (%eax), %eax\n" /* line 335 */
        "movl %eax, -0x54(%ebp)\n"
        "movzbl (%edx), %esi\n" /* row */
        "leal 2(%edi), %edx\n" /* inptr0 */
        "movl %edx, -0xc(%ebp)\n"
        "movl -0x64(%ebp), %eax\n" /* inptr1 */
        "addl $2, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl -0x60(%ebp), %edx\n" /* above_ptr */
        "movzbl 1(%edx), %eax\n"
        "addl -0x54(%ebp), %eax\n"
        "addl %esi, %eax\n" /* row */
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x5c(%ebp), %eax\n" /* below_ptr */
        "movzbl 1(%eax), %edx\n"
        "movl -0x68(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movzbl 2(%edi), %edx\n" /* inptr0 */
        "addl %edx, %eax\n"
        "addl -0x58(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x64(%ebp), %eax\n" /* inptr1 */
        "movzbl 2(%eax), %edx\n"
        "movl -0x68(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "movl -0x60(%ebp), %edx\n" /* line 340 | above_ptr */
        "addl $2, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x5c(%ebp), %edx\n" /* below_ptr */
        "addl $2, %edx\n"
        "movl %edx, -0x18(%ebp)\n"
        "movzbl 1(%edi), %edx\n" /* line 343 | inptr0 */
        "addl %edx, %ecx\n"
        "addl -0x58(%ebp), %ecx\n"
        "movl -0x64(%ebp), %edi\n" /* inptr1, inptr0 */
        "movzbl 1(%edi), %edx\n" /* inptr0 */
        "addl %edx, %ecx\n"
        "imull -0x44(%ebp), %ecx\n" /* memberscale */
        "movl -0x60(%ebp), %edi\n" /* above_ptr, inptr0 */
        "movzbl 2(%edi), %edx\n" /* inptr0 */
        "addl -0x54(%ebp), %edx\n"
        "addl %edx, %esi\n" /* row */
        "movl -0x5c(%ebp), %edi\n" /* below_ptr, inptr0 */
        "movzbl 2(%edi), %edx\n" /* inptr0 */
        "addl %edx, %esi\n" /* row */
        "leal (%esi, %eax, 2), %eax\n" /* row */
        "imull -0x40(%ebp), %eax\n" /* neighscale */
        "leal 0x8000(%ecx, %eax), %ecx\n"
        "sarl $0x10, %ecx\n"
        "movl -0x48(%ebp), %eax\n" /* outptr */
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl -0x30(%ebp), %edx\n" /* line 346 */
        "testl %edx, %edx\n"
        "je .Lf20dbd2_0020de07\n"
        "movl $0, -0x2c(%ebp)\n"
        ".Lf20dbd2_0020dd49:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 294 */
        "addl %ecx, %ecx\n"
        "movl -0xc(%ebp), %edx\n"
        "leal (%ecx, %edx), %edi\n" /* count */
        "movl -0x10(%ebp), %esi\n" /* row */
        "addl %ecx, %esi\n" /* row */
        "movl %esi, -0x28(%ebp)\n" /* row */
        "addl -0x1c(%ebp), %ecx\n"
        "movzbl (%ecx), %edx\n" /* line 351 */
        "movzbl 1(%ecx), %eax\n"
        "addl %eax, %edx\n"
        "movl -0x18(%ebp), %esi\n" /* row */
        "movzbl (%esi), %eax\n" /* row */
        "addl %eax, %edx\n"
        "movzbl 1(%esi), %eax\n" /* row */
        "addl %eax, %edx\n"
        "movzbl -1(%edi), %eax\n" /* inptr0 */
        "addl %eax, %edx\n"
        "movzbl 2(%edi), %eax\n" /* inptr0 */
        "addl %eax, %edx\n"
        "movl -0x28(%ebp), %esi\n" /* row */
        "movzbl -1(%esi), %eax\n" /* row */
        "addl %eax, %edx\n"
        "movzbl 2(%esi), %eax\n" /* row */
        "addl %eax, %edx\n"
        "movzbl -1(%ecx), %esi\n" /* line 358 | row */
        "movzbl 2(%ecx), %eax\n"
        "addl %eax, %esi\n" /* row */
        "movl -0x18(%ebp), %ecx\n"
        "movzbl -1(%ecx), %eax\n"
        "addl %eax, %esi\n" /* row */
        "addl $2, %ecx\n"
        "movl %ecx, -0x18(%ebp)\n"
        "movzbl (%edi), %eax\n" /* line 363 | inptr0 */
        "movzbl 1(%edi), %ecx\n" /* inptr0 */
        "addl %ecx, %eax\n"
        "movl -0x28(%ebp), %edi\n" /* inptr0 */
        "movzbl (%edi), %ecx\n" /* inptr0 */
        "addl %ecx, %eax\n"
        "movzbl 1(%edi), %ecx\n" /* inptr0 */
        "addl %ecx, %eax\n"
        "imull -0x44(%ebp), %eax\n" /* memberscale */
        "movl -0x18(%ebp), %edi\n" /* inptr0 */
        "movzbl (%edi), %ecx\n" /* inptr0 */
        "addl %ecx, %esi\n" /* row */
        "leal (%esi, %edx, 2), %edx\n" /* row */
        "imull -0x40(%ebp), %edx\n" /* neighscale */
        "leal 0x8000(%eax, %edx), %eax\n"
        "sarl $0x10, %eax\n"
        "movl -0x14(%ebp), %edx\n"
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x14(%ebp)\n"
        "addl $1, -0x2c(%ebp)\n"
        "movl -0x30(%ebp), %ecx\n" /* line 346 */
        "cmpl %ecx, -0x2c(%ebp)\n"
        "jne .Lf20dbd2_0020dd49\n"
        "movl -0x2c(%ebp), %eax\n" /* line 294 */
        "addl %eax, %eax\n"
        "addl %eax, -0xc(%ebp)\n"
        "addl %eax, -0x10(%ebp)\n"
        "addl %eax, -0x1c(%ebp)\n"
        ".Lf20dbd2_0020de07:\n"
        "movl -0xc(%ebp), %esi\n" /* line 368 | row */
        "movzbl 1(%esi), %ecx\n" /* row */
        "movl -0x10(%ebp), %edi\n" /* inptr0 */
        "movzbl 1(%edi), %edi\n" /* inptr0 */
        "movl %edi, -0x20(%ebp)\n" /* inptr0 */
        "movl -0x1c(%ebp), %eax\n" /* line 370 */
        "movzbl 1(%eax), %esi\n" /* row */
        "movl -0x18(%ebp), %edx\n"
        "movzbl 1(%edx), %edi\n" /* inptr0 */
        "movzbl (%eax), %eax\n"
        "addl %esi, %eax\n" /* row */
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x18(%ebp), %eax\n"
        "movzbl (%eax), %edx\n"
        "movl -0x68(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "addl %edi, %eax\n" /* inptr0 */
        "movl %eax, -0x68(%ebp)\n"
        "movl -0xc(%ebp), %eax\n"
        "movzbl -1(%eax), %edx\n"
        "movl -0x68(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x10(%ebp), %eax\n"
        "movzbl -1(%eax), %edx\n"
        "movl -0x68(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "addl -0x20(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0xc(%ebp), %eax\n" /* line 378 */
        "movzbl (%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl -0x10(%ebp), %eax\n"
        "movzbl (%eax), %ecx\n"
        "addl %ecx, %edx\n"
        "addl -0x20(%ebp), %edx\n"
        "imull -0x44(%ebp), %edx\n" /* memberscale */
        "movl -0x1c(%ebp), %eax\n"
        "movzbl -1(%eax), %ecx\n"
        "addl %ecx, %esi\n" /* row */
        "movl -0x18(%ebp), %eax\n"
        "movzbl -1(%eax), %ecx\n"
        "addl %ecx, %esi\n" /* row */
        "addl %esi, %edi\n" /* row, inptr0 */
        "movl -0x68(%ebp), %ecx\n"
        "leal (%edi, %ecx, 2), %eax\n" /* inptr0 */
        "imull -0x40(%ebp), %eax\n" /* neighscale */
        "leal 0x8000(%edx, %eax), %edx\n"
        "sarl $0x10, %edx\n"
        "movl -0x14(%ebp), %esi\n" /* row */
        "movb %dl, (%esi)\n" /* row */
        "addl $1, -0x50(%ebp)\n" /* line 325 | outrow */
        "addl $8, -0x24(%ebp)\n"
        "movl -0x50(%ebp), %edi\n" /* outrow, inptr0 */
        "movl 0xc(%ebp), %eax\n" /* compptr */
        "cmpl %edi, 0xc(%eax)\n" /* inptr0 */
        "jg .Lf20dbd2_0020dc64\n"
        ".Lf20dbd2_0020debd:\n"
        "addl $0x60, %esp\n" /* line 382 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20dbd2_0020dec4:\n"
        "xorl %esi, %esi\n" /* line 97 | row */
        ".Lf20dbd2_0020dec6:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 98 | input_cols */
        "movl -0x34(%ebp), %edx\n" /* image_data */
        "addl (%edx, %esi, 4), %eax\n"
        "movzbl -1(%eax), %ecx\n" /* line 99 */
        "leal (%eax, %edi), %edx\n"
        ".Lf20dbd2_0020ded6:\n"
        "movb %cl, (%eax)\n" /* line 101 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n" /* line 100 */
        "jne .Lf20dbd2_0020ded6\n"
        "addl $1, %esi\n" /* line 97 | row */
        "cmpl %esi, -0x38(%ebp)\n" /* row, num_rows */
        "jne .Lf20dbd2_0020dec6\n"
        "jmp .Lf20dbd2_0020dc21\n"
    );
}

/* line 251 */
static __attribute__((naked))
void h2v2_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY output_data)
{
    __asm__ __volatile__ (
        /* { scope 1: input_cols, num_rows */
        "pushl %ebp\n" /* line 251 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0xc(%ebp), %ecx\n" /* line 254 | compptr */
        "movl 0x1c(%ecx), %eax\n"
        "leal (, %eax, 8), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* output_cols */
        "movl 0x24(%edx), %ecx\n" /* line 262 */
        "movl %ecx, -0x14(%ebp)\n" /* input_cols */
        "movl 0xe0(%edx), %edx\n"
        "movl %edx, -0x10(%ebp)\n" /* num_rows */
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, %edi\n" /* line 94 | count */
        "shll $4, %edi\n" /* count */
        "subl %ecx, %edi\n" /* count */
        "testl %edi, %edi\n" /* line 96 | count */
        "jle .Lf20deec_0020df2c\n"
        "movl -0x10(%ebp), %esi\n" /* line 97 | num_rows, row */
        "testl %esi, %esi\n" /* row */
        "jg .Lf20deec_0020dfba\n"
        /* } scope */
        /* } scope */
        ".Lf20deec_0020df2c:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 266 | compptr */
        "movl 0xc(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20deec_0020dfb3\n"
        "movl 0x10(%ebp), %eax\n" /* input_data */
        "movl %eax, -0xc(%ebp)\n"
        "movl $0, -0x24(%ebp)\n" /* outrow */
        ".Lf20deec_0020df43:\n"
        "movl -0x24(%ebp), %edx\n" /* line 267 | outrow */
        "movl 0x14(%ebp), %ecx\n" /* output_data */
        "movl (%ecx, %edx, 4), %edi\n" /* outptr */
        "movl (%eax), %esi\n" /* line 268 | inptr0 */
        "movl 4(%eax), %ecx\n" /* line 269 */
        "movl -0x1c(%ebp), %eax\n" /* line 271 | output_cols */
        "testl %eax, %eax\n"
        "je .Lf20deec_0020df9b\n"
        "movl $1, -0x18(%ebp)\n" /* bias */
        "movl $0, -0x20(%ebp)\n" /* outcol */
        ".Lf20deec_0020df66:\n"
        "movzbl (%esi), %eax\n" /* line 272 | inptr0 */
        "movzbl 1(%esi), %edx\n" /* inptr0 */
        "addl %edx, %eax\n"
        "movzbl (%ecx), %edx\n"
        "addl %edx, %eax\n"
        "movzbl 1(%ecx), %edx\n"
        "addl %edx, %eax\n"
        "addl -0x18(%ebp), %eax\n" /* bias */
        "sarl $2, %eax\n"
        "movb %al, (%edi)\n" /* outptr */
        "addl $1, %edi\n" /* outptr */
        "xorl $3, -0x18(%ebp)\n" /* line 275 | bias */
        "addl $2, %esi\n" /* line 276 | inptr0 */
        "addl $2, %ecx\n"
        "addl $1, -0x20(%ebp)\n" /* line 271 | outcol */
        "movl -0x20(%ebp), %edx\n" /* outcol */
        "cmpl %edx, -0x1c(%ebp)\n" /* output_cols */
        "jne .Lf20deec_0020df66\n"
        ".Lf20deec_0020df9b:\n"
        "addl $1, -0x24(%ebp)\n" /* line 266 | outrow */
        "addl $8, -0xc(%ebp)\n"
        "movl -0x24(%ebp), %ecx\n" /* outrow */
        "movl 0xc(%ebp), %eax\n" /* compptr */
        "cmpl %ecx, 0xc(%eax)\n"
        "jle .Lf20deec_0020dfb3\n"
        "movl -0xc(%ebp), %eax\n"
        "jmp .Lf20deec_0020df43\n"
        ".Lf20deec_0020dfb3:\n"
        "addl $0x1c, %esp\n" /* line 280 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20deec_0020dfba:\n"
        "xorl %esi, %esi\n" /* line 97 | row */
        ".Lf20deec_0020dfbc:\n"
        "movl -0x14(%ebp), %eax\n" /* line 98 | input_cols */
        "movl 0x10(%ebp), %edx\n" /* input_data */
        "addl (%edx, %esi, 4), %eax\n"
        "movzbl -1(%eax), %ecx\n" /* line 99 */
        "leal (%eax, %edi), %edx\n"
        ".Lf20deec_0020dfcc:\n"
        "movb %cl, (%eax)\n" /* line 101 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n" /* line 100 */
        "jne .Lf20deec_0020dfcc\n"
        "addl $1, %esi\n" /* line 97 | row */
        "cmpl %esi, -0x10(%ebp)\n" /* row, num_rows */
        "jne .Lf20deec_0020dfbc\n"
        "jmp .Lf20deec_0020df2c\n"
    );
}

