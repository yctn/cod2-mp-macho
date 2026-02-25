/* ASM dump from: jdsample.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdsample.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_upsample(j_decompress_ptr cinfo);
static void sep_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
static void fullsize_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr);
static void noop_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr);
static void int_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr);
static void h2v1_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr);
static void h2v2_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr);
static void h2v1_fancy_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr);
static void h2v2_fancy_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr);
void jinit_upsampler(j_decompress_ptr cinfo);

/* line 70 */
static __attribute__((naked))
void start_pass_upsample(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x1a8(%eax), %ecx\n" /* line 71 | upsample */
        "movl 0x11c(%eax), %edx\n" /* line 74 */
        "movl %edx, 0x5c(%ecx)\n"
        "movl 0x68(%eax), %eax\n" /* line 76 */
        "movl %eax, 0x60(%ecx)\n"
        "popl %ebp\n" /* line 77 */
        "retl\n"
    );
}

/* line 94 */
static __attribute__((naked))
void sep_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 94 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 95 | cinfo */
        "movl 0x1a8(%eax), %edi\n" /* upsample */
        "movl 0x5c(%edi), %ecx\n" /* line 101 | upsample */
        "cmpl 0x11c(%eax), %ecx\n"
        "jl .Lf209ec1_00209f02\n"
        "movl 0xcc(%eax), %edx\n" /* line 102 */
        "movl %edx, -0xc(%ebp)\n" /* compptr */
        "movl 0x2c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf209ec1_00209f81\n"
        "leal 0xc(%edi), %edx\n" /* upsample */
        "movl %edx, -0x14(%ebp)\n"
        ".Lf209ec1_00209ef7:\n"
        "xorl %ecx, %ecx\n" /* line 111 */
        "movl $0, 0x5c(%edi)\n" /* upsample */
        "jmp .Lf209ec1_00209f08\n"
        ".Lf209ec1_00209f02:\n"
        "leal 0xc(%edi), %eax\n" /* upsample */
        "movl %eax, -0x14(%ebp)\n"
        ".Lf209ec1_00209f08:\n"
        "movl 8(%ebp), %edx\n" /* line 117 | cinfo */
        "movl 0x11c(%edx), %esi\n" /* num_rows */
        "subl %ecx, %esi\n" /* num_rows */
        "movl 0x60(%edi), %eax\n" /* line 121 | upsample */
        "cmpl %eax, %esi\n" /* num_rows */
        "cmoval %eax, %esi\n" /* num_rows */
        "movl 0x1c(%ebp), %eax\n" /* line 124 | out_row_ctr */
        "movl (%eax), %edx\n"
        "movl 0x20(%ebp), %eax\n" /* out_rows_avail */
        "subl %edx, %eax\n"
        "cmpl %eax, %esi\n" /* line 125 | num_rows */
        "cmoval %eax, %esi\n" /* num_rows */
        "movl 8(%ebp), %eax\n" /* line 128 | cinfo */
        "movl 0x1ac(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %esi, 0x10(%esp)\n" /* num_rows */
        "movl 0x18(%ebp), %eax\n" /* output_buf */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl -0x14(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "calll *4(%eax)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 134 | out_row_ctr */
        "addl %esi, (%edx)\n" /* num_rows */
        "subl %esi, 0x60(%edi)\n" /* line 135 | num_rows, upsample */
        "addl 0x5c(%edi), %esi\n" /* line 136 | upsample, num_rows */
        "movl %esi, 0x5c(%edi)\n" /* num_rows, upsample */
        "movl 8(%ebp), %ecx\n" /* line 138 | cinfo */
        "cmpl 0x11c(%ecx), %esi\n" /* num_rows */
        "jl .Lf209ec1_00209f7a\n"
        "movl 0x10(%ebp), %eax\n" /* line 139 | in_row_group_ctr */
        "addl $1, (%eax)\n"
        ".Lf209ec1_00209f7a:\n"
        "addl $0x40, %esp\n" /* line 140 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf209ec1_00209f81:\n"
        "movl %edi, %esi\n" /* line 102 | upsample, num_rows */
        "movl $0, -0x10(%ebp)\n" /* ci */
        "leal 0xc(%edi), %ecx\n" /* upsample */
        "movl %ecx, -0x14(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf209ec1_00209f97\n"
        ".Lf209ec1_00209f94:\n"
        "movl -0x14(%ebp), %eax\n"
        ".Lf209ec1_00209f97:\n"
        "movl -0x10(%ebp), %edx\n" /* ci */
        "shll $2, %edx\n"
        "addl %edx, %eax\n" /* line 107 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* in_row_group_ctr */
        "movl (%ecx), %eax\n"
        "imull 0x64(%esi), %eax\n" /* num_rows */
        "movl 0xc(%ebp), %ecx\n" /* input_buf */
        "movl (%ecx, %edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xc(%ebp), %eax\n" /* compptr */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll *0x34(%esi)\n" /* num_rows */
        "addl $1, -0x10(%ebp)\n" /* line 103 | ci */
        "addl $0x54, -0xc(%ebp)\n" /* compptr */
        "addl $4, %esi\n" /* num_rows */
        "movl -0x10(%ebp), %ecx\n" /* line 102 | ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl %ecx, 0x2c(%eax)\n"
        "jg .Lf209ec1_00209f94\n"
        "jmp .Lf209ec1_00209ef7\n"
    );
}

/* line 159 */
static __attribute__((naked))
void fullsize_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 159 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %edx\n" /* line 160 | input_data */
        "movl 0x14(%ebp), %eax\n" /* output_data_ptr */
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 161 */
        "retl\n"
    );
}

/* line 172 */
static __attribute__((naked))
void noop_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 172 */
        "movl %esp, %ebp\n"
        "movl 0x14(%ebp), %eax\n" /* line 173 | output_data_ptr */
        "movl $0, (%eax)\n"
        "popl %ebp\n" /* line 174 */
        "retl\n"
    );
}

/* line 191 */
static __attribute__((naked))
void int_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 191 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 192 | cinfo */
        "movl 0x1a8(%eax), %edx\n" /* upsample */
        "movl 0x14(%ebp), %eax\n" /* line 193 | output_data_ptr */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* output_data */
        "movl 0xc(%ebp), %eax\n" /* line 201 | compptr */
        "movl 4(%eax), %eax\n"
        "movzbl 0x8c(%eax, %edx), %ecx\n"
        "movl %ecx, -0x18(%ebp)\n" /* h_expand */
        "movzbl 0x96(%eax, %edx), %eax\n" /* line 202 */
        "movl %eax, -0x14(%ebp)\n" /* v_expand */
        "movl 8(%ebp), %edi\n" /* line 205 | cinfo */
        "movl 0x11c(%edi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf209fff_0020a0eb\n"
        "movl 0x10(%ebp), %eax\n" /* input_data */
        "movl %eax, -0xc(%ebp)\n"
        "movl $0, -0x10(%ebp)\n" /* outrow */
        "movl %eax, %edx\n"
        ".Lf209fff_0020a054:\n"
        "movl (%edx), %esi\n" /* line 207 | inptr */
        "movl -0x10(%ebp), %ecx\n" /* line 208 | outrow */
        "movl -0x1c(%ebp), %edi\n" /* output_data */
        "movl (%edi, %ecx, 4), %eax\n"
        "movl 8(%ebp), %edx\n" /* line 209 | cinfo */
        "movl 0x64(%edx), %ecx\n"
        "addl %eax, %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n" /* outend */
        "cmpl %ecx, %eax\n" /* line 210 */
        "jae .Lf209fff_0020a091\n"
        ".Lf209fff_0020a06e:\n"
        "movzbl (%esi), %ecx\n" /* line 211 | inptr */
        "addl $1, %esi\n" /* inptr */
        "movl -0x18(%ebp), %edx\n" /* line 212 | h_expand */
        "testl %edx, %edx\n"
        "jle .Lf209fff_0020a08c\n"
        "movl -0x18(%ebp), %edi\n" /* h_expand */
        "leal (%eax, %edi), %edx\n"
        ".Lf209fff_0020a081:\n"
        "movb %cl, (%eax)\n" /* line 213 */
        "addl $1, %eax\n"
        "cmpl %eax, %edx\n" /* line 212 */
        "jne .Lf209fff_0020a081\n"
        "movl %edx, %eax\n"
        ".Lf209fff_0020a08c:\n"
        "cmpl %eax, -0x2c(%ebp)\n" /* line 210 | outend */
        "ja .Lf209fff_0020a06e\n"
        ".Lf209fff_0020a091:\n"
        "cmpl $1, -0x14(%ebp)\n" /* line 217 | v_expand */
        "jle .Lf209fff_0020a0cb\n"
        "movl 8(%ebp), %edx\n" /* line 218 | cinfo */
        "movl 0x64(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x14(%ebp), %eax\n" /* v_expand */
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x10(%ebp), %eax\n" /* outrow */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %ecx\n" /* output_data */
        "movl %ecx, 8(%esp)\n"
        "movl -0x10(%ebp), %edi\n" /* outrow */
        "movl %edi, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll jcopy_sample_rows\n"
        ".Lf209fff_0020a0cb:\n"
        "movl -0x14(%ebp), %eax\n" /* line 222 | v_expand */
        "addl %eax, -0x10(%ebp)\n" /* outrow */
        "addl $4, -0xc(%ebp)\n"
        "movl -0x10(%ebp), %edx\n" /* line 205 | outrow */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl %edx, 0x11c(%ecx)\n"
        "jle .Lf209fff_0020a0eb\n"
        "movl -0xc(%ebp), %edx\n"
        "jmp .Lf209fff_0020a054\n"
        ".Lf209fff_0020a0eb:\n"
        "addl $0x50, %esp\n" /* line 224 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 235 */
static __attribute__((naked))
void h2v1_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 235 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $4, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* line 236 | output_data_ptr */
        "movl (%eax), %eax\n"
        "movl %eax, -0xc(%ebp)\n" /* output_data */
        "movl 8(%ebp), %eax\n" /* line 242 | cinfo */
        "movl 0x11c(%eax), %esi\n" /* outend */
        "testl %esi, %esi\n" /* outend */
        "jle .Lf20a0f2_0020a157\n"
        "movl $1, %edi\n"
        ".Lf20a0f2_0020a114:\n"
        "leal (, %edi, 4), %eax\n" /* line 235 */
        "movl 0x10(%ebp), %edx\n" /* line 243 | input_data */
        "movl -4(%edx, %eax), %ecx\n"
        "movl -0xc(%ebp), %esi\n" /* line 244 | output_data, outend */
        "movl -4(%esi, %eax), %edx\n" /* outend */
        "movl %edx, %esi\n" /* line 245 | outend */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "addl 0x64(%eax), %esi\n" /* outend */
        "cmpl %esi, %edx\n" /* line 246 | outend */
        "jae .Lf20a0f2_0020a15e\n"
        ".Lf20a0f2_0020a135:\n"
        "movzbl (%ecx), %eax\n" /* line 247 */
        "addl $1, %ecx\n"
        "movb %al, (%edx)\n" /* line 248 */
        "movb %al, 1(%edx)\n" /* line 249 */
        "addl $2, %edx\n"
        "cmpl %edx, %esi\n" /* line 246 | outend */
        "ja .Lf20a0f2_0020a135\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        ".Lf20a0f2_0020a14a:\n"
        "movl %edi, %eax\n"
        "addl $1, %edi\n"
        "cmpl %eax, 0x11c(%edx)\n" /* line 242 */
        "jg .Lf20a0f2_0020a114\n"
        ".Lf20a0f2_0020a157:\n"
        "addl $4, %esp\n" /* line 252 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20a0f2_0020a15e:\n"
        "movl %eax, %edx\n"
        "jmp .Lf20a0f2_0020a14a\n"
    );
}

/* line 263 */
static __attribute__((naked))
void h2v2_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 263 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* line 264 | output_data_ptr */
        "movl (%eax), %eax\n"
        "movl %eax, -0xc(%ebp)\n" /* output_data */
        "movl 8(%ebp), %eax\n" /* line 271 | cinfo */
        "movl 0x11c(%eax), %edi\n" /* outrow */
        "testl %edi, %edi\n" /* outrow */
        "jle .Lf20a162_0020a1e6\n"
        "xorl %edi, %edi\n" /* outrow */
        ".Lf20a162_0020a181:\n"
        "movl 0x10(%ebp), %edx\n" /* line 272 | input_data */
        "movl (%edx, %edi, 2), %ecx\n"
        "movl -0xc(%ebp), %esi\n" /* line 273 | output_data, outend */
        "movl (%esi, %edi, 4), %edx\n" /* outend */
        "movl 8(%ebp), %esi\n" /* line 274 | cinfo, outend */
        "movl 0x64(%esi), %eax\n" /* outend */
        "leal (%edx, %eax), %esi\n" /* outend */
        "cmpl %esi, %edx\n" /* line 275 | outend */
        "jae .Lf20a162_0020a1b2\n"
        ".Lf20a162_0020a19a:\n"
        "movzbl (%ecx), %eax\n" /* line 276 */
        "addl $1, %ecx\n"
        "movb %al, (%edx)\n" /* line 277 */
        "movb %al, 1(%edx)\n" /* line 278 */
        "addl $2, %edx\n"
        "cmpl %edx, %esi\n" /* line 275 | outend */
        "ja .Lf20a162_0020a19a\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x64(%edx), %eax\n"
        ".Lf20a162_0020a1b2:\n"
        "movl %eax, 0x14(%esp)\n" /* line 280 */
        "movl $1, 0x10(%esp)\n"
        "leal 1(%edi), %eax\n" /* outrow */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xc(%ebp), %esi\n" /* output_data, outend */
        "movl %esi, 8(%esp)\n" /* outend */
        "movl %edi, 4(%esp)\n" /* outrow */
        "movl %esi, (%esp)\n" /* outend */
        "calll jcopy_sample_rows\n"
        "addl $2, %edi\n" /* line 283 | outrow */
        "movl 8(%ebp), %eax\n" /* line 271 | cinfo */
        "cmpl 0x11c(%eax), %edi\n" /* outrow */
        "jl .Lf20a162_0020a181\n"
        ".Lf20a162_0020a1e6:\n"
        "addl $0x30, %esp\n" /* line 285 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 306 */
static __attribute__((naked))
void h2v1_fancy_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 306 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0xc, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* line 307 | output_data_ptr */
        "movl (%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* output_data */
        "movl 8(%ebp), %eax\n" /* line 313 | cinfo */
        "movl 0x11c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20a1ed_0020a2b7\n"
        "movl $1, -0xc(%ebp)\n"
        ".Lf20a1ed_0020a215:\n"
        "movl -0xc(%ebp), %eax\n" /* line 306 */
        "shll $2, %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* line 314 | input_data */
        "movl -4(%ecx, %eax), %edx\n"
        "movl -0x10(%ebp), %esi\n" /* line 315 | output_data */
        "movl -4(%esi, %eax), %ecx\n"
        "movzbl (%edx), %eax\n" /* line 317 */
        "leal 1(%edx), %edi\n"
        "movb %al, (%ecx)\n" /* line 318 */
        "leal (%eax, %eax, 2), %eax\n" /* line 319 */
        "movzbl 1(%edx), %edx\n"
        "leal 2(%eax, %edx), %eax\n"
        "sarl $2, %eax\n"
        "movb %al, 1(%ecx)\n"
        "leal 2(%ecx), %esi\n"
        "movl 0xc(%ebp), %edx\n" /* line 321 | compptr */
        "movl 0x28(%edx), %eax\n"
        "subl $2, %eax\n"
        "je .Lf20a1ed_0020a28b\n"
        "movl %edi, %ecx\n"
        "leal (%edi, %eax), %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "jmp .Lf20a1ed_0020a25c\n"
        ".Lf20a1ed_0020a25a:\n"
        "movl %edi, %ecx\n"
        ".Lf20a1ed_0020a25c:\n"
        "movzbl (%ecx), %edx\n" /* line 323 */
        "leal (%edx, %edx, 2), %edx\n"
        "leal 1(%ecx), %edi\n"
        "movzbl -1(%ecx), %eax\n" /* line 324 */
        "leal 1(%edx, %eax), %eax\n"
        "sarl $2, %eax\n"
        "movb %al, (%esi)\n"
        "movzbl 1(%ecx), %eax\n" /* line 325 */
        "leal 2(%edx, %eax), %edx\n"
        "sarl $2, %edx\n"
        "movb %dl, 1(%esi)\n"
        "addl $2, %esi\n"
        "cmpl %edi, -0x14(%ebp)\n" /* line 321 */
        "jne .Lf20a1ed_0020a25a\n"
        "movl -0x14(%ebp), %edi\n"
        ".Lf20a1ed_0020a28b:\n"
        "movzbl (%edi), %ecx\n" /* line 329 */
        "leal (%ecx, %ecx, 2), %eax\n" /* line 330 */
        "movzbl -1(%edi), %edx\n"
        "leal 1(%eax, %edx), %eax\n"
        "sarl $2, %eax\n"
        "movb %al, (%esi)\n"
        "movb %cl, 1(%esi)\n" /* line 331 */
        "movl -0xc(%ebp), %eax\n"
        "addl $1, -0xc(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 313 | cinfo */
        "cmpl %eax, 0x11c(%ecx)\n"
        "jg .Lf20a1ed_0020a215\n"
        ".Lf20a1ed_0020a2b7:\n"
        "addl $0xc, %esp\n" /* line 333 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 347 */
static __attribute__((naked))
void h2v2_fancy_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr, JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 347 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 0x14(%ebp), %eax\n" /* line 348 | output_data_ptr, output_data */
        "movl (%eax), %eax\n" /* output_data */
        "movl 8(%ebp), %edx\n" /* line 359 | cinfo */
        "movl 0x11c(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf20a2be_0020a42b\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl $0, -0x20(%ebp)\n" /* outrow */
        "movl 0x10(%ebp), %ecx\n" /* input_data */
        "movl %ecx, -0x30(%ebp)\n"
        "movl %eax, %esi\n" /* inptr1 */
        "jmp .Lf20a2be_0020a39a\n"
        ".Lf20a2be_0020a2f3:\n"
        "movl -4(%eax), %esi\n" /* line 364 | inptr1 */
        ".Lf20a2be_0020a2f6:\n"
        "movl -0x18(%ebp), %eax\n" /* line 367 */
        "movl (%eax), %ecx\n"
        "movzbl (%edi), %eax\n" /* line 370 */
        "leal (%eax, %eax, 2), %eax\n"
        "movzbl (%esi), %edx\n" /* inptr1 */
        "addl %edx, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* thiscolsum */
        "movzbl 1(%edi), %eax\n" /* line 371 */
        "leal (%eax, %eax, 2), %eax\n"
        "movzbl 1(%esi), %edx\n" /* inptr1 */
        "leal (%eax, %edx), %edx\n"
        "addl $2, %edi\n"
        "addl $2, %esi\n" /* inptr1 */
        "movl %esi, -0xc(%ebp)\n" /* inptr1 */
        "movl -0x28(%ebp), %esi\n" /* line 372 | thiscolsum, inptr1 */
        "leal 8(, %esi, 4), %eax\n"
        "sarl $4, %eax\n"
        "movb %al, (%ecx)\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 373 | inptr1 */
        "leal 7(%edx, %eax), %eax\n"
        "sarl $4, %eax\n"
        "movb %al, 1(%ecx)\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 376 | compptr */
        "movl 0x28(%ecx), %eax\n"
        "subl $2, %eax\n"
        "jne .Lf20a2be_0020a3bc\n"
        "movl %esi, %ecx\n" /* inptr1 */
        ".Lf20a2be_0020a34f:\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 386 */
        "leal 8(%eax, %ecx), %eax\n"
        "sarl $4, %eax\n"
        "movl -0x10(%ebp), %esi\n" /* inptr1 */
        "movb %al, (%esi)\n" /* inptr1 */
        "leal 7(, %edx, 4), %eax\n" /* line 387 */
        "sarl $4, %eax\n"
        "movb %al, 1(%esi)\n" /* inptr1 */
        "addl $1, -0x1c(%ebp)\n" /* line 360 | v */
        "addl $4, -0x18(%ebp)\n"
        "cmpl $2, -0x1c(%ebp)\n" /* v */
        "jne .Lf20a2be_0020a3a4\n"
        "addl $2, -0x20(%ebp)\n" /* outrow */
        "addl $4, -0x30(%ebp)\n"
        "addl $8, -0x14(%ebp)\n"
        "movl -0x20(%ebp), %edx\n" /* line 359 | outrow */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl %edx, 0x11c(%eax)\n"
        "jle .Lf20a2be_0020a42b\n"
        "movl -0x14(%ebp), %esi\n" /* inptr1 */
        ".Lf20a2be_0020a39a:\n"
        "movl %esi, -0x18(%ebp)\n" /* inptr1 */
        "movl $0, -0x1c(%ebp)\n" /* v */
        ".Lf20a2be_0020a3a4:\n"
        "movl -0x30(%ebp), %eax\n" /* line 362 */
        "movl (%eax), %edi\n"
        "movl -0x1c(%ebp), %edx\n" /* line 363 | v */
        "testl %edx, %edx\n"
        "je .Lf20a2be_0020a2f3\n"
        "movl 4(%eax), %esi\n" /* line 366 | inptr1 */
        "jmp .Lf20a2be_0020a2f6\n"
        ".Lf20a2be_0020a3bc:\n"
        "movl %edi, %esi\n" /* line 376 | inptr1 */
        "movl %edx, %edi\n"
        "movl -0x28(%ebp), %edx\n" /* thiscolsum */
        "movl %edx, -0x24(%ebp)\n" /* lastcolsum */
        "leal (%esi, %eax), %eax\n" /* inptr1 */
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf20a2be_0020a3d1\n"
        ".Lf20a2be_0020a3ce:\n"
        "movl -0x38(%ebp), %edi\n"
        ".Lf20a2be_0020a3d1:\n"
        "movzbl (%esi), %eax\n" /* line 379 | inptr1 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0xc(%ebp), %ecx\n"
        "movzbl (%ecx), %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "addl $1, %esi\n" /* inptr1 */
        "addl $1, %ecx\n"
        "movl %ecx, -0xc(%ebp)\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 380 */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x24(%ebp), %ecx\n" /* lastcolsum */
        "leal 8(%eax, %ecx), %eax\n"
        "sarl $4, %eax\n"
        "movl -0x10(%ebp), %edx\n"
        "movb %al, (%edx)\n"
        "movl -0x38(%ebp), %ecx\n" /* line 381 */
        "movl -0x34(%ebp), %edx\n"
        "leal 7(%ecx, %edx), %eax\n"
        "sarl $4, %eax\n"
        "movl -0x10(%ebp), %ecx\n"
        "movb %al, 1(%ecx)\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl %edi, -0x24(%ebp)\n" /* lastcolsum */
        "cmpl -0x2c(%ebp), %esi\n" /* line 376 | inptr1 */
        "jne .Lf20a2be_0020a3ce\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edi, %ecx\n"
        "jmp .Lf20a2be_0020a34f\n"
        ".Lf20a2be_0020a42b:\n"
        "addl $0x30, %esp\n" /* line 391 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 400 */
__attribute__((naked))
void jinit_upsampler(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 400 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edx\n" /* line 407 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0xa0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %esi\n" /* line 410 | cinfo */
        "movl %eax, 0x1a8(%esi)\n"
        "leal -0x59c(%ebx), %eax\n" /* line 411 */
        "movl -0x1c(%ebp), %edi\n" /* v_out_group */
        "movl %eax, (%edi)\n" /* v_out_group */
        "leal -0x57f(%ebx), %eax\n" /* line 412 */
        "movl %eax, 4(%edi)\n" /* v_out_group */
        "movb $0, 8(%edi)\n" /* line 413 | v_out_group */
        "cmpb $0, 0x112(%esi)\n" /* line 415 */
        "jne .Lf20a432_0020a650\n"
        ".Lf20a432_0020a48c:\n"
        "movl 8(%ebp), %eax\n" /* line 421 | cinfo */
        "cmpb $0, 0x50(%eax)\n"
        "je .Lf20a432_0020a4c0\n"
        "cmpl $1, 0x120(%eax)\n"
        "jle .Lf20a432_0020a4c0\n"
        "movb $1, -0x25(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 426 | cinfo */
        "movl 0xcc(%edx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* compptr */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x2c(%esi), %esi\n"
        "testl %esi, %esi\n"
        "jg .Lf20a432_0020a4da\n"
        ".Lf20a432_0020a4b8:\n"
        "addl $0x4c, %esp\n" /* line 478 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20a432_0020a4c0:\n"
        "movb $0, -0x25(%ebp)\n" /* line 421 */
        "movl 8(%ebp), %edx\n" /* line 426 | cinfo */
        "movl 0xcc(%edx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* compptr */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x2c(%esi), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf20a432_0020a4b8\n"
        ".Lf20a432_0020a4da:\n"
        "movl -0x1c(%ebp), %edi\n" /* v_out_group */
        "movl %edi, -0x20(%ebp)\n" /* v_out_group */
        "movl %edi, -0x24(%ebp)\n" /* v_out_group */
        "movl $0, -0x30(%ebp)\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20a432_0020a518\n"
        ".Lf20a432_0020a4ef:\n"
        "leal -0x44f(%ebx), %eax\n" /* line 441 */
        "movl -0x24(%ebp), %edx\n"
        "movl %eax, 0x34(%edx)\n"
        ".Lf20a432_0020a4fb:\n"
        "addl $1, -0x30(%ebp)\n" /* line 427 | ci */
        "addl $0x54, -0x2c(%ebp)\n" /* compptr */
        "addl $4, -0x24(%ebp)\n"
        "addl $1, -0x20(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 426 | ci */
        "movl 8(%ebp), %edi\n" /* cinfo, v_out_group */
        "cmpl 0x2c(%edi), %eax\n" /* v_out_group */
        "jge .Lf20a432_0020a4b8\n"
        "movl %edi, %edx\n" /* v_out_group */
        ".Lf20a432_0020a518:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 431 | compptr */
        "movl 0x24(%eax), %ecx\n"
        "movl 0x120(%edx), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl %ecx, %edi\n" /* v_out_group */
        "imull 8(%eax), %edi\n" /* v_out_group */
        "movl %edi, %eax\n" /* v_out_group */
        "cltd\n"
        "idivl -0x3c(%ebp)\n"
        "movl %eax, %esi\n"
        "movl -0x2c(%ebp), %edi\n" /* line 433 | compptr, v_out_group */
        "imull 0xc(%edi), %ecx\n" /* v_out_group */
        "movl %ecx, %eax\n"
        "cltd\n"
        "idivl -0x3c(%ebp)\n"
        "movl %eax, %ecx\n"
        "movl 8(%ebp), %edi\n" /* line 435 | cinfo, v_out_group */
        "movl 0x118(%edi), %edx\n" /* v_out_group */
        "movl 0x11c(%edi), %edi\n" /* line 436 | v_out_group */
        "movl -0x24(%ebp), %eax\n" /* line 437 */
        "movl %ecx, 0x64(%eax)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 439 | compptr */
        "cmpb $0, 0x30(%eax)\n"
        "je .Lf20a432_0020a4ef\n"
        "cmpl %edx, %esi\n" /* line 443 */
        "je .Lf20a432_0020a608\n"
        ".Lf20a432_0020a56a:\n"
        "leal (%esi, %esi), %eax\n" /* line 447 */
        "cmpl %eax, %edx\n"
        "je .Lf20a432_0020a621\n"
        ".Lf20a432_0020a575:\n"
        "movl %edx, %eax\n" /* line 462 */
        "cltd\n"
        "idivl %esi\n"
        "movl %eax, %esi\n"
        "testl %edx, %edx\n"
        "jne .Lf20a432_0020a5f3\n"
        "movl %edi, %eax\n" /* v_out_group */
        "cltd\n"
        "idivl %ecx\n"
        "movl %eax, %ecx\n"
        "testl %edx, %edx\n"
        "jne .Lf20a432_0020a5f3\n"
        "leal -0x441(%ebx), %eax\n" /* line 465 */
        "movl -0x24(%ebp), %edx\n"
        "movl %eax, 0x34(%edx)\n"
        "movl %esi, %eax\n" /* line 466 */
        "movl -0x20(%ebp), %edx\n"
        "movb %al, 0x8c(%edx)\n"
        "movb %cl, 0x96(%edx)\n" /* line 467 */
        ".Lf20a432_0020a5a8:\n"
        "movl 8(%ebp), %esi\n" /* line 471 | cinfo */
        "movl 4(%esi), %eax\n"
        "movl 8(%eax), %edi\n" /* v_out_group */
        "movl %esi, %eax\n"
        "movl 0x11c(%esi), %esi\n"
        "movl %eax, %edx\n"
        "movl 0x118(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x64(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jround_up\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl %esi, (%esp)\n"
        "calll *%edi\n" /* v_out_group */
        "movl -0x24(%ebp), %edi\n" /* v_out_group */
        "movl %eax, 0xc(%edi)\n" /* v_out_group */
        "jmp .Lf20a432_0020a4fb\n"
        ".Lf20a432_0020a5f3:\n"
        "movl 8(%ebp), %esi\n" /* line 469 | cinfo */
        "movl (%esi), %eax\n"
        "movl $0x26, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20a432_0020a5a8\n"
        ".Lf20a432_0020a608:\n"
        "cmpl %edi, %ecx\n" /* line 443 | v_out_group */
        "jne .Lf20a432_0020a56a\n"
        "leal -0x45c(%ebx), %eax\n" /* line 445 */
        "movl -0x24(%ebp), %edx\n"
        "movl %eax, 0x34(%edx)\n"
        "jmp .Lf20a432_0020a4fb\n"
        ".Lf20a432_0020a621:\n"
        "cmpl %edi, %ecx\n" /* line 447 | v_out_group */
        "je .Lf20a432_0020a665\n"
        "leal (%ecx, %ecx), %eax\n" /* line 454 */
        "cmpl %eax, %edi\n" /* v_out_group */
        "jne .Lf20a432_0020a575\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 457 */
        "je .Lf20a432_0020a63f\n"
        "movl -0x2c(%ebp), %esi\n" /* compptr */
        "cmpl $2, 0x28(%esi)\n"
        "ja .Lf20a432_0020a696\n"
        ".Lf20a432_0020a63f:\n"
        "leal -0x2de(%ebx), %eax\n" /* line 461 */
        "movl -0x24(%ebp), %edx\n"
        "movl %eax, 0x34(%edx)\n"
        "jmp .Lf20a432_0020a5a8\n"
        ".Lf20a432_0020a650:\n"
        "movl (%esi), %eax\n" /* line 416 */
        "movl $0x19, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20a432_0020a48c\n"
        ".Lf20a432_0020a665:\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 450 */
        "je .Lf20a432_0020a674\n"
        "movl -0x2c(%ebp), %esi\n" /* compptr */
        "cmpl $2, 0x28(%esi)\n"
        "ja .Lf20a432_0020a685\n"
        ".Lf20a432_0020a674:\n"
        "leal -0x34e(%ebx), %eax\n" /* line 453 */
        "movl -0x24(%ebp), %edx\n"
        "movl %eax, 0x34(%edx)\n"
        "jmp .Lf20a432_0020a5a8\n"
        ".Lf20a432_0020a685:\n"
        "leal -0x253(%ebx), %eax\n" /* line 451 */
        "movl -0x24(%ebp), %edi\n" /* v_out_group */
        "movl %eax, 0x34(%edi)\n" /* v_out_group */
        "jmp .Lf20a432_0020a5a8\n"
        ".Lf20a432_0020a696:\n"
        "leal -0x182(%ebx), %eax\n" /* line 458 */
        "movl -0x24(%ebp), %edi\n" /* v_out_group */
        "movl %eax, 0x34(%edi)\n" /* v_out_group */
        "movl -0x1c(%ebp), %eax\n" /* line 459 */
        "movb $1, 8(%eax)\n"
        "jmp .Lf20a432_0020a5a8\n"
    );
}

