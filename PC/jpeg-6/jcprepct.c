/* ASM dump from: jcprepct.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcprepct.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_prep(j_compress_ptr cinfo, J_BUF_MODE pass_mode);
void jinit_c_prep_controller(j_compress_ptr cinfo, int need_full_buffer);
static void pre_process_context(j_compress_ptr cinfo, JSAMPARRAY input_buf, JDIMENSION *in_row_ctr, JDIMENSION in_rows_avail, JSAMPIMAGE output_buf, JDIMENSION *out_row_group_ctr, JDIMENSION out_row_groups_avail);
static void pre_process_data(j_compress_ptr cinfo, JSAMPARRAY input_buf, JDIMENSION *in_row_ctr, JDIMENSION in_rows_avail, JSAMPIMAGE output_buf, JDIMENSION *out_row_group_ctr, JDIMENSION out_row_groups_avail);

/* line 79 */
static __attribute__((naked))
void start_pass_prep(j_compress_ptr cinfo, J_BUF_MODE pass_mode)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 79 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0x148(%edi), %esi\n" /* line 80 | cinfo, prep */
        "movl 0xc(%ebp), %eax\n" /* line 82 | pass_mode */
        "testl %eax, %eax\n"
        "je .Lf20c568_0020c590\n"
        "movl (%edi), %eax\n" /* line 83 | cinfo */
        "movl $4, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf20c568_0020c590:\n"
        "movl 0x28(%edi), %eax\n" /* line 86 | cinfo */
        "movl %eax, 0x30(%esi)\n" /* prep */
        "movl $0, 0x34(%esi)\n" /* line 88 | prep */
        "movl $0, 0x38(%esi)\n" /* line 93 | prep */
        "movl 0xe0(%edi), %eax\n" /* line 95 | cinfo */
        "addl %eax, %eax\n"
        "movl %eax, 0x3c(%esi)\n" /* prep */
        "addl $0x10, %esp\n" /* line 97 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 316 */
__attribute__((naked))
void jinit_c_prep_controller(j_compress_ptr cinfo, int need_full_buffer)
{
    __asm__ __volatile__ (
        /* { scope 1: rgroup_height, ci, compptr, true_buffer, ... */
        "pushl %ebp\n" /* line 316 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "cmpb $0, 0xc(%ebp)\n" /* line 321 | need_full_buffer */
        "jne .Lf20c5b6_0020c809\n"
        ".Lf20c5b6_0020c5d1:\n"
        "movl 8(%ebp), %ecx\n" /* line 324 | cinfo */
        "movl 4(%ecx), %eax\n"
        "movl $0x40, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, %edx\n"
        "movl 8(%ebp), %esi\n" /* line 327 | cinfo, compptr */
        "movl %eax, 0x148(%esi)\n" /* compptr */
        "leal -0x5f(%ebx), %eax\n" /* line 328 */
        "movl %eax, (%edx)\n"
        "movl 0x158(%esi), %eax\n" /* line 334 | compptr */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf20c5b6_0020c69c\n"
        "leal 0x510(%ebx), %eax\n" /* line 344 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebp), %eax\n" /* line 345 | cinfo */
        "movl 0x48(%eax), %esi\n" /* compptr */
        "movl 0x40(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf20c5b6_0020c630\n"
        ".Lf20c5b6_0020c625:\n"
        "addl $0x8c, %esp\n" /* line 354 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20c5b6_0020c630:\n"
        "movl %edx, %edi\n" /* line 345 | i */
        "movl $0, -0x3c(%ebp)\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20c5b6_0020c640\n"
        ".Lf20c5b6_0020c63e:\n"
        "movl %ecx, %edx\n"
        ".Lf20c5b6_0020c640:\n"
        "movl 4(%edx), %edx\n" /* line 347 */
        "movl %edx, -0x5c(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xe0(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x1c(%esi), %eax\n" /* compptr */
        "imull 0xdc(%ecx), %eax\n"
        "shll $3, %eax\n"
        "cltd\n"
        "idivl 8(%esi)\n" /* compptr */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl -0x5c(%ebp), %edx\n"
        "calll *8(%edx)\n"
        "movl %eax, 8(%edi)\n" /* i */
        "addl $1, -0x3c(%ebp)\n" /* line 346 | ci */
        "addl $0x54, %esi\n" /* compptr */
        "addl $4, %edi\n" /* i */
        "movl -0x3c(%ebp), %eax\n" /* line 345 | ci */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x40(%ecx), %eax\n"
        "jl .Lf20c5b6_0020c63e\n"
        "addl $0x8c, %esp\n" /* line 354 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20c5b6_0020c69c:\n"
        "leal 0x25a(%ebx), %eax\n" /* line 337 */
        "movl %eax, 4(%edx)\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 269 | cinfo */
        "movl 0x148(%eax), %esi\n" /* prep */
        "movl 0xe0(%eax), %edx\n" /* line 270 */
        "movl %edx, -0x34(%ebp)\n" /* rgroup_height */
        "movl 4(%eax), %edx\n" /* line 278 */
        "movl -0x34(%ebp), %eax\n" /* rgroup_height */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "imull 0x40(%ecx), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%edx)\n"
        "movl %eax, -0x24(%ebp)\n" /* fake_buffer */
        "movl 8(%ebp), %eax\n" /* line 283 | cinfo */
        "movl 0x48(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* compptr */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x40(%edx), %edi\n" /* i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf20c5b6_0020c625\n"
        "movl -0x34(%ebp), %ecx\n" /* rgroup_height */
        "addl %ecx, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "addl -0x34(%ebp), %ecx\n" /* rgroup_height */
        "movl %ecx, -0x44(%ebp)\n"
        "shll $2, %ecx\n"
        "movl %ecx, -0x48(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* rgroup_height */
        "shll $2, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "addl -0x34(%ebp), %eax\n" /* line 303 | rgroup_height */
        "shll $2, %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl %esi, -0x1c(%ebp)\n" /* prep */
        "movl $0, -0x30(%ebp)\n" /* ci */
        ".Lf20c5b6_0020c725:\n"
        "movl 8(%ebp), %edx\n" /* line 289 | cinfo */
        "movl 4(%edx), %edi\n" /* i */
        "movl -0x44(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x2c(%ebp), %esi\n" /* compptr, prep */
        "movl 0x1c(%esi), %edx\n" /* prep */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "imull 0xdc(%eax), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl 8(%esi)\n" /* prep */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll *8(%edi)\n" /* i */
        "movl %eax, -0x28(%ebp)\n" /* true_buffer */
        "movl -0x24(%ebp), %ecx\n" /* line 295 | fake_buffer */
        "addl -0x20(%ebp), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl -0x48(%ebp), %esi\n" /* prep */
        "movl %esi, 8(%esp)\n" /* prep */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x34(%ebp), %esi\n" /* line 298 | rgroup_height, prep */
        "testl %esi, %esi\n" /* prep */
        "jle .Lf20c5b6_0020c7d2\n"
        "movl -0x40(%ebp), %eax\n"
        "movl -0x28(%ebp), %edx\n" /* true_buffer */
        "leal (%edx, %eax, 4), %esi\n" /* prep */
        "movl -0x20(%ebp), %ecx\n"
        "movl -0x24(%ebp), %eax\n" /* fake_buffer */
        "leal (%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "xorl %edi, %edi\n" /* i */
        "movl %eax, %edx\n"
        "jmp .Lf20c5b6_0020c7a4\n"
        ".Lf20c5b6_0020c7a1:\n"
        "movl -0x24(%ebp), %edx\n" /* fake_buffer */
        ".Lf20c5b6_0020c7a4:\n"
        "leal (, %edi, 4), %eax\n" /* line 316 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl (%esi), %ecx\n" /* line 299 | prep */
        "movl %ecx, (%edx, %eax)\n"
        "movl -0x28(%ebp), %edx\n" /* line 300 | true_buffer */
        "movl -0x6c(%ebp), %ecx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl -0x7c(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "addl $1, %edi\n" /* line 298 | i */
        "addl $4, %esi\n" /* prep */
        "addl $4, %edx\n"
        "movl %edx, -0x7c(%ebp)\n"
        "cmpl %edi, -0x34(%ebp)\n" /* i, rgroup_height */
        "jne .Lf20c5b6_0020c7a1\n"
        ".Lf20c5b6_0020c7d2:\n"
        "movl -0x38(%ebp), %esi\n" /* line 302 | prep */
        "movl -0x1c(%ebp), %ecx\n"
        "movl %esi, 8(%ecx)\n" /* prep */
        "movl -0x4c(%ebp), %eax\n" /* line 303 */
        "addl %eax, -0x24(%ebp)\n" /* fake_buffer */
        "addl $1, -0x30(%ebp)\n" /* line 284 | ci */
        "addl $0x54, -0x2c(%ebp)\n" /* compptr */
        "addl $4, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl -0x30(%ebp), %ecx\n" /* line 283 | ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl %ecx, 0x40(%edx)\n"
        "jg .Lf20c5b6_0020c725\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 354 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20c5b6_0020c809:\n"
        "movl 8(%ebp), %edx\n" /* line 322 | cinfo */
        "movl (%edx), %eax\n"
        "movl $4, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20c5b6_0020c5d1\n"
    );
}

/* line 200 */
static __attribute__((naked))
void pre_process_context(j_compress_ptr cinfo, JSAMPARRAY input_buf, JDIMENSION *in_row_ctr, JDIMENSION in_rows_avail, JSAMPIMAGE output_buf, JDIMENSION *out_row_group_ctr, JDIMENSION out_row_groups_avail)
{
    __asm__ __volatile__ (
        /* { scope 1: num_cols */
        "pushl %ebp\n" /* line 200 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 201 | cinfo */
        "movl 0x148(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* prep */
        "movl 8(%ebp), %edx\n" /* line 203 | cinfo */
        "movl 0xe0(%edx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        ".Lf20c821_0020c844:\n"
        "movl 0x20(%ebp), %eax\n" /* line 206 | out_row_groups_avail */
        "movl 0x1c(%ebp), %ecx\n" /* out_row_group_ctr */
        "cmpl %eax, (%ecx)\n"
        "jae .Lf20c821_0020c9b6\n"
        ".Lf20c821_0020c852:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 207 | in_row_ctr */
        "movl (%ecx), %esi\n" /* row */
        "cmpl 0x14(%ebp), %esi\n" /* in_rows_avail, row */
        "jb .Lf20c821_0020c9bd\n"
        "movl -0x24(%ebp), %eax\n" /* line 232 | prep */
        "movl 0x30(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf20c821_0020c9b6\n"
        "movl %eax, %edx\n" /* line 235 */
        "movl 0x34(%eax), %eax\n"
        "cmpl 0x3c(%edx), %eax\n"
        "jge .Lf20c821_0020c926\n"
        "movl 8(%ebp), %edx\n" /* line 236 | cinfo */
        "movl 0x40(%edx), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf20c821_0020ca44\n"
        "movl -0x24(%ebp), %ecx\n" /* prep */
        "movl %ecx, -0x14(%ebp)\n"
        "movl $0, -0xc(%ebp)\n"
        "movl 0x3c(%ecx), %edx\n"
        "jmp .Lf20c821_0020c8b5\n"
        ".Lf20c821_0020c89c:\n"
        "addl $1, -0xc(%ebp)\n"
        "addl $4, -0x14(%ebp)\n"
        "movl -0xc(%ebp), %ecx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x40(%eax), %ecx\n"
        "jge .Lf20c821_0020c91e\n"
        ".Lf20c821_0020c8af:\n"
        "movl -0x24(%ebp), %ecx\n" /* prep */
        "movl 0x34(%ecx), %eax\n"
        ".Lf20c821_0020c8b5:\n"
        "movl 8(%ebp), %ecx\n" /* line 237 | cinfo */
        "movl 0x24(%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* num_cols */
        "movl -0x14(%ebp), %ecx\n"
        "movl 8(%ecx), %edi\n" /* image_data */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl %eax, %edx\n" /* line 111 */
        "jle .Lf20c821_0020c89c\n"
        "leal -1(%eax), %ecx\n"
        "movl %ecx, -0x18(%ebp)\n"
        "movl %eax, %esi\n" /* row */
        "movl %edx, -0x2c(%ebp)\n"
        "movl %ecx, %edx\n"
        "jmp .Lf20c821_0020c8da\n"
        ".Lf20c821_0020c8d7:\n"
        "movl -0x18(%ebp), %edx\n"
        ".Lf20c821_0020c8da:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 112 | num_cols */
        "movl %eax, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* row */
        "movl %edi, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll jcopy_sample_rows\n"
        "addl $1, %esi\n" /* line 111 | row */
        "cmpl %esi, -0x2c(%ebp)\n" /* row */
        "jne .Lf20c821_0020c8d7\n"
        "movl -0x24(%ebp), %ecx\n" /* prep */
        "movl 0x3c(%ecx), %edx\n"
        /* } scope */
        /* } scope */
        "addl $1, -0xc(%ebp)\n" /* line 236 */
        "addl $4, -0x14(%ebp)\n"
        "movl -0xc(%ebp), %ecx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x40(%eax), %ecx\n"
        "jl .Lf20c821_0020c8af\n"
        ".Lf20c821_0020c91e:\n"
        "movl -0x24(%ebp), %ecx\n" /* prep */
        "movl %edx, 0x34(%ecx)\n" /* line 240 */
        "movl %edx, %eax\n"
        ".Lf20c821_0020c926:\n"
        "movl -0x24(%ebp), %edx\n" /* line 244 | prep */
        "cmpl 0x3c(%edx), %eax\n"
        "jne .Lf20c821_0020c844\n"
        ".Lf20c821_0020c932:\n"
        "movl 8(%ebp), %ecx\n" /* line 245 | cinfo */
        "movl 0x158(%ecx), %edx\n"
        "movl 0x1c(%ebp), %ecx\n" /* out_row_group_ctr */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* output_buf */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %ecx\n" /* prep */
        "movl 0x38(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ecx, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 249 | out_row_group_ctr */
        "addl $1, (%edx)\n"
        "movl -0x24(%ebp), %ecx\n" /* line 251 | prep */
        "movl 0x38(%ecx), %edx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "addl 0xe0(%eax), %edx\n"
        "xorl %eax, %eax\n" /* line 253 */
        "cmpl %edx, -0x28(%ebp)\n"
        "cmovgl %edx, %eax\n"
        "movl %eax, 0x38(%ecx)\n"
        "movl -0x28(%ebp), %edx\n" /* line 254 */
        "cmpl 0x34(%ecx), %edx\n"
        "jg .Lf20c821_0020c996\n"
        "movl $0, 0x34(%ecx)\n" /* line 255 */
        ".Lf20c821_0020c996:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 256 | prep */
        "movl 0x34(%ecx), %eax\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "addl 0xe0(%edx), %eax\n"
        "movl %eax, 0x3c(%ecx)\n"
        "movl 0x20(%ebp), %eax\n" /* line 206 | out_row_groups_avail */
        "movl 0x1c(%ebp), %ecx\n" /* out_row_group_ctr */
        "cmpl %eax, (%ecx)\n"
        "jb .Lf20c821_0020c852\n"
        ".Lf20c821_0020c9b6:\n"
        "addl $0x50, %esp\n" /* line 259 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20c821_0020c9bd:\n"
        "movl -0x24(%ebp), %eax\n" /* line 210 | prep */
        "movl 0x34(%eax), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* line 211 | in_rows_avail */
        "subl %esi, %ecx\n" /* row */
        "movl %ecx, -0x10(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "subl %edx, %eax\n"
        "cmpl %eax, -0x10(%ebp)\n"
        "cmovbel -0x10(%ebp), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 212 | cinfo */
        "movl 0x154(%eax), %ecx\n"
        "movl -0x10(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* prep */
        "addl $8, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* input_buf */
        "leal (%edx, %esi, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *4(%ecx)\n"
        "movl -0x24(%ebp), %edx\n" /* line 217 | prep */
        "movl 0x30(%edx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x28(%ecx), %eax\n"
        "je .Lf20c821_0020ca56\n"
        ".Lf20c821_0020ca19:\n"
        "movl -0x10(%ebp), %eax\n" /* line 227 */
        "movl 0x10(%ebp), %ecx\n" /* in_row_ctr */
        "addl %eax, (%ecx)\n"
        "movl -0x10(%ebp), %eax\n" /* line 228 */
        "movl -0x24(%ebp), %edx\n" /* prep */
        "addl 0x34(%edx), %eax\n"
        "movl %eax, 0x34(%edx)\n"
        "movl -0x10(%ebp), %ecx\n" /* line 229 */
        "subl %ecx, 0x30(%edx)\n"
        "movl -0x24(%ebp), %edx\n" /* line 244 | prep */
        "cmpl 0x3c(%edx), %eax\n"
        "jne .Lf20c821_0020c844\n"
        "jmp .Lf20c821_0020c932\n"
        ".Lf20c821_0020ca44:\n"
        "movl -0x24(%ebp), %eax\n" /* prep */
        "movl 0x3c(%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movl %edx, 0x34(%ecx)\n" /* line 240 */
        "movl %edx, %eax\n"
        "jmp .Lf20c821_0020c926\n"
        ".Lf20c821_0020ca56:\n"
        "movl 8(%ebp), %eax\n" /* line 218 | cinfo */
        "movl 0x40(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20c821_0020ca19\n"
        "movl -0x24(%ebp), %edi\n" /* prep */
        "movl $0, -0x20(%ebp)\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20c821_0020ca7e\n"
        ".Lf20c821_0020ca6f:\n"
        "addl $1, -0x20(%ebp)\n" /* ci */
        "addl $4, %edi\n"
        "movl -0x20(%ebp), %eax\n" /* ci */
        "cmpl %eax, 0x40(%edx)\n"
        "jle .Lf20c821_0020ca19\n"
        /* { scope 2 */
        ".Lf20c821_0020ca7e:\n"
        "movl 0xe0(%edx), %esi\n" /* line 220 | row */
        "testl %esi, %esi\n" /* row */
        "jle .Lf20c821_0020ca6f\n"
        "movl $2, %esi\n" /* row */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "jmp .Lf20c821_0020ca94\n"
        ".Lf20c821_0020ca92:\n"
        "movl %edx, %ecx\n"
        ".Lf20c821_0020ca94:\n"
        "movl 8(%edi), %edx\n" /* line 221 */
        "movl 0x24(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl $1, %eax\n"
        "subl %esi, %eax\n" /* row */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll jcopy_sample_rows\n"
        "movl %esi, %eax\n" /* row */
        "addl $1, %esi\n" /* row */
        "movl 8(%ebp), %edx\n" /* line 220 | cinfo */
        "cmpl 0xe0(%edx), %eax\n"
        "jle .Lf20c821_0020ca92\n"
        "jmp .Lf20c821_0020ca6f\n"
    );
}

/* line 133 */
static __attribute__((naked))
void pre_process_data(j_compress_ptr cinfo, JSAMPARRAY input_buf, JDIMENSION *in_row_ctr, JDIMENSION in_rows_avail, JSAMPIMAGE output_buf, JDIMENSION *out_row_group_ctr, JDIMENSION out_row_groups_avail)
{
    __asm__ __volatile__ (
        /* { scope 1: num_cols, num_cols */
        "pushl %ebp\n" /* line 133 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 134 | cinfo */
        "movl 0x148(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* prep */
        ".Lf20cad7_0020caeb:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 139 | in_row_ctr */
        "movl (%ecx), %edi\n"
        "cmpl 0x14(%ebp), %edi\n" /* in_rows_avail */
        "jae .Lf20cad7_0020cd56\n"
        "movl 0x20(%ebp), %eax\n" /* out_row_groups_avail */
        "movl 0x1c(%ebp), %esi\n" /* out_row_group_ctr, row */
        "cmpl %eax, (%esi)\n" /* row */
        "jae .Lf20cad7_0020cd56\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 143 | prep */
        "movl 0x34(%ecx), %edx\n"
        "movl 0x14(%ebp), %esi\n" /* line 144 | in_rows_avail, row */
        "subl %edi, %esi\n" /* row */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xe0(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cmpl %eax, %esi\n" /* row */
        "cmoval %eax, %esi\n" /* row */
        "movl -0x2c(%ebp), %eax\n" /* line 145 | prep */
        "addl $8, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x154(%ecx), %ecx\n"
        "movl %esi, 0x10(%esp)\n" /* row */
        "movl %edx, 0xc(%esp)\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* input_buf */
        "leal (%edx, %edi, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl %edi, (%esp)\n"
        "calll *4(%ecx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 149 | in_row_ctr */
        "addl %esi, (%eax)\n" /* row */
        "movl %esi, %edx\n" /* line 150 | row */
        "movl -0x2c(%ebp), %ecx\n" /* prep */
        "addl 0x34(%ecx), %edx\n"
        "movl %edx, %ecx\n"
        "movl -0x2c(%ebp), %edi\n" /* prep */
        "movl %edx, 0x34(%edi)\n"
        "movl 0x30(%edi), %eax\n" /* line 151 */
        "subl %esi, %eax\n" /* row */
        "movl %eax, 0x30(%edi)\n"
        "testl %eax, %eax\n" /* line 153 */
        "jne .Lf20cad7_0020cc33\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0xe0(%eax), %edx\n"
        "jge .Lf20cad7_0020cc33\n"
        "movl %eax, %edx\n"
        "movl 0x40(%eax), %edi\n" /* line 155 */
        "testl %edi, %edi\n"
        "jle .Lf20cad7_0020cd3b\n"
        "movl -0x2c(%ebp), %esi\n" /* prep, row */
        "movl %esi, -0x10(%ebp)\n" /* row */
        "movl $0, -0x28(%ebp)\n" /* ci */
        "movl 0xe0(%eax), %eax\n"
        "movl %esi, %edx\n" /* row */
        "jmp .Lf20cad7_0020cbc7\n"
        ".Lf20cad7_0020cbab:\n"
        "movl 8(%ebp), %esi\n" /* cinfo, row */
        "addl $1, -0x28(%ebp)\n" /* ci */
        "addl $4, -0x10(%ebp)\n"
        "movl -0x28(%ebp), %edi\n" /* ci */
        "cmpl 0x40(%esi), %edi\n" /* row */
        "jge .Lf20cad7_0020cc2b\n"
        ".Lf20cad7_0020cbbe:\n"
        "movl -0x2c(%ebp), %edx\n" /* prep */
        "movl 0x34(%edx), %ecx\n"
        "movl -0x10(%ebp), %edx\n"
        ".Lf20cad7_0020cbc7:\n"
        "movl 8(%ebp), %esi\n" /* line 156 | cinfo, row */
        "movl 0x24(%esi), %esi\n" /* row */
        "movl %esi, -0x20(%ebp)\n" /* row, num_cols */
        "movl 8(%edx), %edi\n" /* image_data */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl %ecx, %eax\n" /* line 111 */
        "jle .Lf20cad7_0020cbab\n"
        "leal -1(%ecx), %esi\n" /* row */
        "movl %esi, -0x14(%ebp)\n" /* row */
        "movl %ecx, %esi\n" /* row */
        "movl %eax, -0x34(%ebp)\n"
        ".Lf20cad7_0020cbe2:\n"
        "movl -0x20(%ebp), %eax\n" /* line 112 | num_cols */
        "movl %eax, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* row */
        "movl %edi, 8(%esp)\n"
        "movl -0x14(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll jcopy_sample_rows\n"
        "addl $1, %esi\n" /* line 111 | row */
        "cmpl -0x34(%ebp), %esi\n" /* row */
        "jne .Lf20cad7_0020cbe2\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xe0(%ecx), %eax\n"
        "movl %ecx, %esi\n" /* row */
        /* } scope */
        /* } scope */
        "addl $1, -0x28(%ebp)\n" /* line 155 | ci */
        "addl $4, -0x10(%ebp)\n"
        "movl -0x28(%ebp), %edi\n" /* ci */
        "cmpl 0x40(%esi), %edi\n" /* row */
        "jl .Lf20cad7_0020cbbe\n"
        ".Lf20cad7_0020cc2b:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 159 | prep */
        "movl %eax, 0x34(%ecx)\n"
        "movl %eax, %ecx\n"
        ".Lf20cad7_0020cc33:\n"
        "movl 8(%ebp), %esi\n" /* line 162 | cinfo, row */
        "cmpl 0xe0(%esi), %ecx\n" /* row */
        "je .Lf20cad7_0020ccfe\n"
        ".Lf20cad7_0020cc42:\n"
        "movl -0x2c(%ebp), %edi\n" /* line 172 | prep, image_data */
        "movl 0x30(%edi), %eax\n" /* image_data */
        "testl %eax, %eax\n"
        "jne .Lf20cad7_0020caeb\n"
        "movl 0x20(%ebp), %edx\n" /* out_row_groups_avail */
        "movl 0x1c(%ebp), %eax\n" /* out_row_group_ctr */
        "cmpl (%eax), %edx\n"
        "jbe .Lf20cad7_0020caeb\n"
        "movl 8(%ebp), %ecx\n" /* line 174 | cinfo */
        "movl 0x48(%ecx), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* compptr */
        "movl 8(%ebp), %esi\n" /* cinfo, row */
        "movl 0x40(%esi), %eax\n" /* row */
        "testl %eax, %eax\n"
        "jle .Lf20cad7_0020cd4e\n"
        "movl $0, -0xc(%ebp)\n"
        "jmp .Lf20cad7_0020cc95\n"
        ".Lf20cad7_0020cc7e:\n"
        "addl $1, -0xc(%ebp)\n" /* line 175 */
        "addl $0x54, -0x24(%ebp)\n" /* compptr */
        "movl -0xc(%ebp), %esi\n" /* line 174 | row */
        "movl 8(%ebp), %edi\n" /* cinfo, image_data */
        "cmpl 0x40(%edi), %esi\n" /* image_data, row */
        "jge .Lf20cad7_0020cd4e\n"
        ".Lf20cad7_0020cc95:\n"
        "movl -0x24(%ebp), %edi\n" /* line 176 | compptr, image_data */
        "movl 0xc(%edi), %eax\n" /* image_data */
        "movl 0x20(%ebp), %ecx\n" /* out_row_groups_avail, output_rows */
        "imull %eax, %ecx\n" /* output_rows */
        "movl %eax, %edx\n"
        "movl 0x1c(%ebp), %esi\n" /* out_row_group_ctr, row */
        "imull (%esi), %edx\n" /* row */
        "movl 0x1c(%edi), %eax\n" /* image_data */
        "shll $3, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* num_cols */
        "movl -0xc(%ebp), %eax\n"
        "movl 0x18(%ebp), %esi\n" /* output_buf, row */
        "movl (%esi, %eax, 4), %edi\n" /* row, image_data */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl %edx, %ecx\n" /* line 111 */
        "jle .Lf20cad7_0020cc7e\n"
        "leal -1(%edx), %eax\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl %edx, %esi\n" /* row */
        "movl %ecx, -0x38(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf20cad7_0020ccd1\n"
        ".Lf20cad7_0020ccce:\n"
        "movl -0x18(%ebp), %ecx\n"
        ".Lf20cad7_0020ccd1:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 112 | num_cols */
        "movl %edx, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* row */
        "movl %edi, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll jcopy_sample_rows\n"
        "addl $1, %esi\n" /* line 111 | row */
        "cmpl %esi, -0x38(%ebp)\n" /* row */
        "jne .Lf20cad7_0020ccce\n"
        "jmp .Lf20cad7_0020cc7e\n"
        /* } scope */
        /* } scope */
        ".Lf20cad7_0020ccfe:\n"
        "movl 0x158(%esi), %edx\n" /* line 163 | row */
        "movl 0x1c(%ebp), %edi\n" /* out_row_group_ctr, image_data */
        "movl (%edi), %eax\n" /* image_data */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* output_buf */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl -0x30(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* row */
        "calll *4(%edx)\n"
        "movl -0x2c(%ebp), %esi\n" /* line 166 | prep, row */
        "movl $0, 0x34(%esi)\n" /* row */
        "addl $1, (%edi)\n" /* line 167 | image_data */
        "jmp .Lf20cad7_0020cc42\n"
        ".Lf20cad7_0020cd3b:\n"
        "movl 0xe0(%edx), %eax\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 159 | prep */
        "movl %eax, 0x34(%ecx)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf20cad7_0020cc33\n"
        ".Lf20cad7_0020cd4e:\n"
        "movl 0x20(%ebp), %edx\n" /* line 181 | out_row_groups_avail */
        "movl 0x1c(%ebp), %eax\n" /* out_row_group_ctr */
        "movl %edx, (%eax)\n"
        ".Lf20cad7_0020cd56:\n"
        "addl $0x50, %esp\n" /* line 185 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

