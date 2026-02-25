/* ASM dump from: jdmerge.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdmerge.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_merged_upsample(j_decompress_ptr cinfo);
static void merged_2v_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
static void merged_1v_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
static void h2v1_merged_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION in_row_group_ctr, JSAMPARRAY output_buf);
static void h2v2_merged_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION in_row_group_ctr, JSAMPARRAY output_buf);
void jinit_merged_upsampler(j_decompress_ptr cinfo);

/* line 127 */
static __attribute__((naked))
void start_pass_merged_upsample(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 127 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x1a8(%eax), %edx\n" /* line 128 | upsample */
        "movb $0, 0x24(%edx)\n" /* line 131 */
        "movl 0x68(%eax), %eax\n" /* line 133 */
        "movl %eax, 0x2c(%edx)\n"
        "popl %ebp\n" /* line 134 */
        "retl\n"
    );
}

/* line 150 */
static __attribute__((naked))
void merged_2v_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 150 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 0x18(%ebp), %ecx\n" /* output_buf */
        "movl 8(%ebp), %eax\n" /* line 151 | cinfo */
        "movl 0x1a8(%eax), %esi\n" /* upsample */
        "cmpb $0, 0x24(%esi)\n" /* line 155 | upsample */
        "jne .Lf2084f4_0020857c\n"
        "movl 0x2c(%esi), %edi\n" /* line 165 | upsample, num_rows */
        "cmpl $2, %edi\n" /* num_rows */
        "movl $2, %eax\n"
        "cmovael %eax, %edi\n" /* num_rows */
        "movl 0x1c(%ebp), %eax\n" /* line 168 | out_row_ctr */
        "movl (%eax), %edx\n"
        "movl 0x20(%ebp), %eax\n" /* out_rows_avail */
        "subl %edx, %eax\n"
        "cmpl %eax, %edi\n" /* line 169 | num_rows */
        "cmoval %eax, %edi\n" /* num_rows */
        "movl (%ecx, %edx, 4), %eax\n" /* line 172 */
        "movl %eax, -0x10(%ebp)\n" /* work_ptrs */
        "cmpl $1, %edi\n" /* line 173 | num_rows */
        "jbe .Lf2084f4_002085bd\n"
        "movl 4(%ecx, %edx, 4), %eax\n" /* line 174 */
        "movl %eax, -0xc(%ebp)\n"
        ".Lf2084f4_00208541:\n"
        "leal -0x10(%ebp), %eax\n" /* line 180 | work_ptrs */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* in_row_group_ctr */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* input_buf */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll *0xc(%esi)\n" /* upsample */
        ".Lf2084f4_00208561:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 184 | out_row_ctr */
        "addl %edi, (%eax)\n" /* num_rows */
        "subl %edi, 0x2c(%esi)\n" /* line 185 | num_rows, upsample */
        "cmpb $0, 0x24(%esi)\n" /* line 187 | upsample */
        "jne .Lf2084f4_00208575\n"
        "movl 0x10(%ebp), %edx\n" /* line 188 | in_row_group_ctr */
        "addl $1, (%edx)\n"
        ".Lf2084f4_00208575:\n"
        "addl $0x30, %esp\n" /* line 189 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2084f4_0020857c:\n"
        "movl 0x28(%esi), %eax\n" /* line 157 | upsample */
        "movl %eax, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0x1c(%ebp), %edx\n" /* out_row_ctr */
        "movl (%edx), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal 0x20(%esi), %eax\n" /* upsample */
        "movl %eax, (%esp)\n"
        "calll jcopy_sample_rows\n"
        "movb $0, 0x24(%esi)\n" /* line 160 | upsample */
        "movl $1, %edi\n" /* num_rows */
        "jmp .Lf2084f4_00208561\n"
        ".Lf2084f4_002085bd:\n"
        "movl 0x20(%esi), %eax\n" /* line 176 | upsample */
        "movl %eax, -0xc(%ebp)\n"
        "movb $1, 0x24(%esi)\n" /* line 177 | upsample */
        "jmp .Lf2084f4_00208541\n"
    );
}

/* line 199 */
static __attribute__((naked))
void merged_1v_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 199 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x10(%ebp), %edi\n" /* in_row_group_ctr */
        "movl 0x1c(%ebp), %esi\n" /* out_row_ctr */
        "movl 0x1a8(%edx), %ecx\n" /* line 203 */
        "movl (%esi), %eax\n" /* out_row_ctr */
        "shll $2, %eax\n"
        "addl 0x18(%ebp), %eax\n" /* output_buf */
        "movl %eax, 0xc(%esp)\n"
        "movl (%edi), %eax\n" /* in_row_group_ctr */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* input_buf */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0xc(%ecx)\n"
        "addl $1, (%esi)\n" /* line 206 | out_row_ctr */
        "addl $1, (%edi)\n" /* line 207 | in_row_group_ctr */
        "addl $0x10, %esp\n" /* line 208 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 229 */
static __attribute__((naked))
void h2v1_merged_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION in_row_group_ctr, JSAMPARRAY output_buf)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 229 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* input_buf */
        "movl 8(%ebp), %ecx\n" /* line 230 | cinfo */
        "movl 0x1a8(%ecx), %eax\n" /* upsample */
        "movl 0x128(%ecx), %esi\n" /* line 237 | inptr1 */
        "movl %esi, -0x20(%ebp)\n" /* inptr1, range_limit */
        "movl 0x10(%eax), %edi\n" /* line 238 | cblue */
        "movl %edi, -0x1c(%ebp)\n" /* cblue, Crrtab */
        "movl 0x14(%eax), %ecx\n" /* line 239 */
        "movl %ecx, -0x18(%ebp)\n" /* Cbbtab */
        "movl 0x18(%eax), %esi\n" /* line 240 | inptr1 */
        "movl %esi, -0x14(%ebp)\n" /* inptr1, Crgtab */
        "movl 0x1c(%eax), %eax\n" /* line 241 */
        "movl %eax, -0x10(%ebp)\n" /* Cbgtab */
        "movl 0x10(%ebp), %ecx\n" /* line 244 | in_row_group_ctr */
        "shll $2, %ecx\n"
        "movl (%edx), %eax\n"
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* inptr0 */
        "movl 4(%edx), %eax\n" /* line 245 */
        "movl (%ecx, %eax), %esi\n" /* inptr1 */
        "movl 8(%edx), %eax\n" /* line 246 */
        "movl (%ecx, %eax), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* inptr2 */
        "movl 0x14(%ebp), %eax\n" /* line 247 | output_buf */
        "movl (%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* outptr */
        "movl 8(%ebp), %edi\n" /* line 249 | cinfo, cblue */
        "movl 0x64(%edi), %eax\n" /* cblue */
        "movl %eax, %edx\n"
        "shrl $1, %edx\n"
        "jne .Lf20860f_002086d6\n"
        "movl %esi, -0xc(%ebp)\n" /* inptr1 */
        ".Lf20860f_00208678:\n"
        "testb $1, %al\n" /* line 269 */
        "je .Lf20860f_002086cf\n"
        "movl -0x24(%ebp), %esi\n" /* line 272 | inptr2, inptr1 */
        "movzbl (%esi), %ecx\n" /* inptr1 */
        "shll $2, %ecx\n"
        "movl -0xc(%ebp), %edi\n" /* line 273 | cblue */
        "movzbl (%edi), %edx\n" /* cblue */
        "shll $2, %edx\n"
        "movl -0x10(%ebp), %esi\n" /* Cbgtab, inptr1 */
        "movl (%esi, %edx), %eax\n" /* inptr1 */
        "movl -0x14(%ebp), %edi\n" /* Crgtab, cblue */
        "addl (%edi, %ecx), %eax\n" /* cblue */
        "sarl $0x10, %eax\n"
        "movl -0x18(%ebp), %esi\n" /* line 274 | Cbbtab, inptr1 */
        "movl (%esi, %edx), %edi\n" /* inptr1, cblue */
        "movl -0x28(%ebp), %edx\n" /* line 275 | inptr0 */
        "movzbl (%edx), %esi\n" /* inptr1 */
        "movl -0x1c(%ebp), %edx\n" /* line 276 | Crrtab */
        "movl (%edx, %ecx), %ecx\n"
        "addl -0x20(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %esi), %edx\n"
        "movl -0x2c(%ebp), %ecx\n" /* outptr */
        "movb %dl, 2(%ecx)\n"
        "addl -0x20(%ebp), %eax\n" /* line 277 | range_limit */
        "movzbl (%eax, %esi), %eax\n"
        "movb %al, 1(%ecx)\n"
        "addl -0x20(%ebp), %edi\n" /* line 278 | range_limit, cblue */
        "movzbl (%edi, %esi), %eax\n" /* cblue */
        "movb %al, (%ecx)\n"
        ".Lf20860f_002086cf:\n"
        "addl $0x30, %esp\n" /* line 280 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20860f_002086d6:\n"
        "movl %esi, -0xc(%ebp)\n" /* line 249 | inptr1 */
        "leal (%esi, %edx), %edx\n" /* inptr1 */
        "movl %edx, -0x34(%ebp)\n"
        "movl %esi, %edx\n" /* inptr1 */
        "jmp .Lf20860f_002086e6\n"
        ".Lf20860f_002086e3:\n"
        "movl -0xc(%ebp), %edx\n"
        ".Lf20860f_002086e6:\n"
        "movzbl (%edx), %eax\n" /* line 251 */
        "addl $1, %edx\n"
        "movl %edx, -0xc(%ebp)\n"
        "movl -0x24(%ebp), %esi\n" /* line 252 | inptr2, inptr1 */
        "movzbl (%esi), %ecx\n" /* inptr1 */
        "addl $1, %esi\n" /* inptr1 */
        "movl %esi, -0x24(%ebp)\n" /* inptr1, inptr2 */
        "shll $2, %ecx\n" /* line 253 */
        "shll $2, %eax\n" /* line 254 */
        "movl -0x10(%ebp), %edi\n" /* Cbgtab, cblue */
        "movl (%edi, %eax), %edx\n" /* cblue */
        "movl -0x14(%ebp), %esi\n" /* Crgtab, inptr1 */
        "addl (%esi, %ecx), %edx\n" /* inptr1 */
        "sarl $0x10, %edx\n"
        "movl -0x18(%ebp), %edi\n" /* line 255 | Cbbtab, cblue */
        "movl (%edi, %eax), %eax\n" /* cblue */
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 257 | inptr0 */
        "movzbl (%eax), %esi\n" /* inptr1 */
        "movl -0x20(%ebp), %eax\n" /* line 258 | range_limit */
        "movl -0x1c(%ebp), %edi\n" /* Crrtab, cblue */
        "addl (%edi, %ecx), %eax\n" /* cblue */
        "movl %eax, -0x30(%ebp)\n"
        "movzbl (%eax, %esi), %eax\n"
        "movl -0x2c(%ebp), %edi\n" /* outptr, cblue */
        "movb %al, 2(%edi)\n" /* cblue */
        "addl -0x20(%ebp), %edx\n" /* line 259 | range_limit */
        "movzbl (%edx, %esi), %eax\n"
        "movb %al, 1(%edi)\n" /* cblue */
        "movl -0x38(%ebp), %edi\n" /* line 260 | cblue */
        "addl -0x20(%ebp), %edi\n" /* range_limit, cblue */
        "movzbl (%edi, %esi), %eax\n" /* cblue */
        "movl -0x2c(%ebp), %ecx\n" /* outptr */
        "movb %al, (%ecx)\n"
        "movl -0x28(%ebp), %esi\n" /* line 262 | inptr0, inptr1 */
        "movzbl 1(%esi), %ecx\n" /* inptr1 */
        "addl $2, %esi\n" /* inptr1 */
        "movl %esi, -0x28(%ebp)\n" /* inptr1, inptr0 */
        "movl -0x30(%ebp), %esi\n" /* line 263 | inptr1 */
        "movzbl (%esi, %ecx), %eax\n" /* inptr1 */
        "movl -0x2c(%ebp), %esi\n" /* outptr, inptr1 */
        "movb %al, 5(%esi)\n" /* inptr1 */
        "movzbl (%edx, %ecx), %eax\n" /* line 264 */
        "movb %al, 4(%esi)\n" /* inptr1 */
        "movzbl (%edi, %ecx), %eax\n" /* line 265 | cblue */
        "movb %al, 3(%esi)\n" /* inptr1 */
        "addl $6, %esi\n" /* line 266 | inptr1 */
        "movl %esi, -0x2c(%ebp)\n" /* inptr1, outptr */
        "movl -0x34(%ebp), %edi\n" /* line 249 | cblue */
        "cmpl %edi, -0xc(%ebp)\n" /* cblue */
        "jne .Lf20860f_002086e3\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x64(%edx), %eax\n"
        "jmp .Lf20860f_00208678\n"
    );
}

/* line 291 */
static __attribute__((naked))
void h2v2_merged_upsample(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION in_row_group_ctr, JSAMPARRAY output_buf)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 291 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* input_buf */
        "movl 0x10(%ebp), %ecx\n" /* in_row_group_ctr */
        "movl 0x14(%ebp), %edi\n" /* output_buf */
        "movl 8(%ebp), %edx\n" /* line 292 | cinfo */
        "movl 0x1a8(%edx), %eax\n" /* upsample */
        "movl 0x128(%edx), %edx\n" /* line 299 */
        "movl %edx, -0x20(%ebp)\n" /* range_limit */
        "movl 0x10(%eax), %edx\n" /* line 300 */
        "movl %edx, -0x1c(%ebp)\n" /* Crrtab */
        "movl 0x14(%eax), %edx\n" /* line 301 */
        "movl %edx, -0x18(%ebp)\n" /* Cbbtab */
        "movl 0x18(%eax), %edx\n" /* line 302 */
        "movl %edx, -0x14(%ebp)\n" /* Crgtab */
        "movl 0x1c(%eax), %eax\n" /* line 303 */
        "movl %eax, -0x10(%ebp)\n" /* Cbgtab */
        "movl (%esi), %edx\n" /* line 306 | y */
        "leal (, %ecx, 8), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl (%edx, %eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* inptr00 */
        "movl -0x48(%ebp), %eax\n" /* line 307 */
        "movl 4(%edx, %eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* inptr01 */
        "shll $2, %ecx\n" /* line 308 */
        "movl 4(%esi), %eax\n" /* y */
        "movl (%eax, %ecx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* inptr1 */
        "movl 8(%esi), %eax\n" /* line 309 | y */
        "movl (%ecx, %eax), %edx\n"
        "movl (%edi), %ecx\n" /* line 310 | output_buf */
        "movl %ecx, -0x34(%ebp)\n" /* outptr0 */
        "movl 4(%edi), %edi\n" /* line 311 | output_buf */
        "movl %edi, -0x30(%ebp)\n" /* output_buf, outptr1 */
        "movl 8(%ebp), %esi\n" /* line 313 | cinfo, y */
        "movl 0x64(%esi), %eax\n" /* y */
        "movl %eax, %ecx\n"
        "shrl $1, %ecx\n"
        "je .Lf208793_00208920\n"
        "movl %edx, -0xc(%ebp)\n"
        "leal (%edx, %ecx), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lf208793_00208827\n"
        ".Lf208793_00208824:\n"
        "movl -0xc(%ebp), %ecx\n"
        ".Lf208793_00208827:\n"
        "movl -0x24(%ebp), %edi\n" /* line 315 | inptr1, output_buf */
        "movzbl (%edi), %eax\n" /* output_buf */
        "addl $1, %edi\n" /* output_buf */
        "movl %edi, -0x24(%ebp)\n" /* output_buf, inptr1 */
        "movzbl (%ecx), %edx\n" /* line 316 */
        "addl $1, %ecx\n"
        "movl %ecx, -0xc(%ebp)\n"
        "shll $2, %edx\n" /* line 317 */
        "shll $2, %eax\n" /* line 318 */
        "movl -0x10(%ebp), %edi\n" /* Cbgtab, output_buf */
        "movl (%edi, %eax), %esi\n" /* output_buf, y */
        "movl -0x14(%ebp), %ecx\n" /* Crgtab */
        "addl (%ecx, %edx), %esi\n" /* y */
        "sarl $0x10, %esi\n" /* y */
        "movl -0x18(%ebp), %edi\n" /* line 319 | Cbbtab, output_buf */
        "movl (%edi, %eax), %eax\n" /* output_buf */
        "movl %eax, -0x44(%ebp)\n" /* cblue */
        "movl -0x2c(%ebp), %eax\n" /* line 321 | inptr00 */
        "movzbl (%eax), %ecx\n"
        "movl -0x20(%ebp), %eax\n" /* line 322 | range_limit */
        "movl -0x1c(%ebp), %edi\n" /* Crrtab, output_buf */
        "addl (%edi, %edx), %eax\n" /* output_buf */
        "movl %eax, -0x38(%ebp)\n"
        "movzbl (%eax, %ecx), %eax\n"
        "movl -0x34(%ebp), %edi\n" /* outptr0, output_buf */
        "movb %al, 2(%edi)\n" /* output_buf */
        "addl -0x20(%ebp), %esi\n" /* line 323 | range_limit, y */
        "movzbl (%esi, %ecx), %eax\n" /* y */
        "movb %al, 1(%edi)\n" /* output_buf */
        "movl -0x44(%ebp), %edi\n" /* line 324 | cblue, output_buf */
        "addl -0x20(%ebp), %edi\n" /* range_limit, output_buf */
        "movzbl (%edi, %ecx), %eax\n" /* output_buf */
        "movl -0x34(%ebp), %edx\n" /* outptr0 */
        "movb %al, (%edx)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 326 | inptr00 */
        "movzbl 1(%ecx), %edx\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n" /* inptr00 */
        "movl -0x38(%ebp), %ecx\n" /* line 327 */
        "movzbl (%ecx, %edx), %eax\n"
        "movl -0x34(%ebp), %ecx\n" /* outptr0 */
        "movb %al, 5(%ecx)\n"
        "movzbl (%esi, %edx), %eax\n" /* line 328 | y */
        "movb %al, 4(%ecx)\n"
        "movzbl (%edi, %edx), %eax\n" /* line 329 | output_buf */
        "movb %al, 3(%ecx)\n"
        "addl $6, %ecx\n" /* line 330 */
        "movl %ecx, -0x34(%ebp)\n" /* outptr0 */
        "movl -0x28(%ebp), %eax\n" /* line 331 | inptr01 */
        "movzbl (%eax), %edx\n"
        "movl -0x38(%ebp), %ecx\n" /* line 332 */
        "movzbl (%ecx, %edx), %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* outptr1 */
        "movb %al, 2(%ecx)\n"
        "movzbl (%esi, %edx), %eax\n" /* line 333 | y */
        "movb %al, 1(%ecx)\n"
        "movzbl (%edi, %edx), %eax\n" /* line 334 | output_buf */
        "movb %al, (%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 336 | inptr01 */
        "movzbl 1(%eax), %edx\n"
        "addl $2, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* inptr01 */
        "movl -0x38(%ebp), %ecx\n" /* line 337 */
        "movzbl (%ecx, %edx), %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* outptr1 */
        "movb %al, 5(%ecx)\n"
        "movzbl (%esi, %edx), %eax\n" /* line 338 | y */
        "movb %al, 4(%ecx)\n"
        "movzbl (%edi, %edx), %eax\n" /* line 339 | output_buf */
        "movb %al, 3(%ecx)\n"
        "addl $6, %ecx\n" /* line 340 */
        "movl %ecx, -0x30(%ebp)\n" /* outptr1 */
        "movl -0x40(%ebp), %esi\n" /* line 313 | y */
        "cmpl %esi, -0xc(%ebp)\n" /* y */
        "jne .Lf208793_00208824\n"
        "movl -0xc(%ebp), %edx\n"
        "movl 8(%ebp), %edi\n" /* cinfo, output_buf */
        "movl 0x64(%edi), %eax\n" /* output_buf */
        ".Lf208793_00208920:\n"
        "testb $1, %al\n" /* line 343 */
        "je .Lf208793_0020899d\n"
        "movzbl (%edx), %edx\n" /* line 346 */
        "shll $2, %edx\n"
        "movl -0x24(%ebp), %ecx\n" /* line 347 | inptr1 */
        "movzbl (%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl -0x10(%ebp), %esi\n" /* Cbgtab, y */
        "movl (%esi, %eax), %ecx\n" /* y */
        "movl -0x14(%ebp), %edi\n" /* Crgtab, output_buf */
        "addl (%edi, %edx), %ecx\n" /* output_buf */
        "sarl $0x10, %ecx\n"
        "movl -0x18(%ebp), %esi\n" /* line 348 | Cbbtab, y */
        "movl (%esi, %eax), %eax\n" /* y */
        "movl %eax, -0x44(%ebp)\n" /* cblue */
        "movl -0x2c(%ebp), %edi\n" /* line 349 | inptr00, output_buf */
        "movzbl (%edi), %esi\n" /* output_buf, y */
        "movl -0x20(%ebp), %edi\n" /* line 350 | range_limit, output_buf */
        "movl -0x1c(%ebp), %eax\n" /* Crrtab */
        "addl (%eax, %edx), %edi\n" /* output_buf */
        "movl %edi, -0x3c(%ebp)\n" /* output_buf */
        "movzbl (%edi, %esi), %eax\n" /* output_buf */
        "movl -0x34(%ebp), %edx\n" /* outptr0 */
        "movb %al, 2(%edx)\n"
        "addl -0x20(%ebp), %ecx\n" /* line 351 | range_limit */
        "movzbl (%ecx, %esi), %eax\n"
        "movb %al, 1(%edx)\n"
        "movl -0x44(%ebp), %edi\n" /* line 352 | cblue, output_buf */
        "addl -0x20(%ebp), %edi\n" /* range_limit, output_buf */
        "movzbl (%edi, %esi), %eax\n" /* output_buf */
        "movb %al, (%edx)\n"
        "movl -0x28(%ebp), %esi\n" /* line 353 | inptr01, y */
        "movzbl (%esi), %edx\n" /* y */
        "movl -0x3c(%ebp), %esi\n" /* line 354 | y */
        "movzbl (%esi, %edx), %eax\n" /* y */
        "movl -0x30(%ebp), %esi\n" /* outptr1, y */
        "movb %al, 2(%esi)\n" /* y */
        "movzbl (%ecx, %edx), %eax\n" /* line 355 */
        "movb %al, 1(%esi)\n" /* y */
        "movzbl (%edi, %edx), %eax\n" /* line 356 | output_buf */
        "movb %al, (%esi)\n" /* y */
        ".Lf208793_0020899d:\n"
        "addl $0x40, %esp\n" /* line 358 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 371 */
__attribute__((naked))
void jinit_merged_upsampler(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 371 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 4(%edi), %eax\n" /* line 374 | cinfo */
        "movl $0x30, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, %esi\n" /* upsample */
        "movl %eax, 0x1a8(%edi)\n" /* line 377 | cinfo */
        "leal -0x4d6(%ebx), %eax\n" /* line 378 */
        "movl %eax, (%esi)\n" /* upsample */
        "movb $0, 8(%esi)\n" /* line 379 | upsample */
        "movl 0x64(%edi), %edx\n" /* line 381 | cinfo */
        "imull 0x6c(%edi), %edx\n" /* cinfo */
        "movl %edx, 0x28(%esi)\n" /* upsample */
        "cmpl $2, 0x11c(%edi)\n" /* line 383 | cinfo */
        "je .Lf2089a4_00208af6\n"
        "leal -0x3e6(%ebx), %eax\n" /* line 391 */
        "movl %eax, 4(%esi)\n" /* upsample */
        "leal -0x3a3(%ebx), %eax\n" /* line 392 */
        "movl %eax, 0xc(%esi)\n" /* upsample */
        "movl $0, 0x20(%esi)\n" /* line 394 | upsample */
        /* { scope 2 */
        ".Lf2089a4_00208a11:\n"
        "movl 0x1a8(%edi), %esi\n" /* line 85 | upsample */
        "movl 4(%edi), %eax\n" /* line 90 */
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x10(%esi)\n" /* upsample */
        "movl 4(%edi), %eax\n" /* line 93 */
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x14(%esi)\n" /* upsample */
        "movl 4(%edi), %eax\n" /* line 96 */
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x18(%esi)\n" /* upsample */
        "movl 4(%edi), %eax\n" /* line 99 */
        "movl $0x400, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x1c(%esi)\n" /* upsample */
        "xorl %ecx, %ecx\n"
        "movl $0xff4d0b80, -0x24(%ebp)\n"
        "movl $0xff1daf00, -0x20(%ebp)\n"
        "movl $0x5b6900, -0x1c(%ebp)\n"
        "movl $__Z13FS_CreatePathPc.eh, %edi\n"
        ".Lf2089a4_00208a9f:\n"
        "movl 0x10(%esi), %edx\n" /* line 107 | upsample */
        "movl -0x24(%ebp), %eax\n"
        "sarl $0x10, %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "movl 0x14(%esi), %edx\n" /* line 110 | upsample */
        "movl -0x20(%ebp), %eax\n"
        "sarl $0x10, %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "movl 0x18(%esi), %eax\n" /* line 113 | upsample */
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, (%eax, %ecx)\n"
        "movl 0x1c(%esi), %eax\n" /* line 116 | upsample */
        "movl %edi, (%eax, %ecx)\n"
        "addl $4, %ecx\n"
        "addl $0x166e9, -0x24(%ebp)\n"
        "addl $0x1c5a2, -0x20(%ebp)\n"
        "subl $0xb6d2, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "subl $0x581a, %edi\n"
        "cmpl $0x400, %ecx\n" /* line 103 */
        "jne .Lf2089a4_00208a9f\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 398 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2089a4_00208af6:\n"
        "leal -0x4be(%ebx), %eax\n" /* line 384 */
        "movl %eax, 4(%esi)\n" /* upsample */
        "leal -0x21f(%ebx), %eax\n" /* line 385 */
        "movl %eax, 0xc(%esi)\n" /* upsample */
        "movl 4(%edi), %eax\n" /* line 387 | cinfo */
        "movl %edx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "movl %eax, 0x20(%esi)\n" /* upsample */
        "jmp .Lf2089a4_00208a11\n"
    );
}

