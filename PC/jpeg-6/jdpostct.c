/* ASM dump from: jdpostct.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdpostct.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_dpost(j_decompress_ptr cinfo, J_BUF_MODE pass_mode);
static void post_process_1pass(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
static void post_process_prepass(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
static void post_process_2pass(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
void jinit_d_post_controller(j_decompress_ptr cinfo, int need_full_buffer);

/* line 74 */
static __attribute__((naked))
void start_pass_dpost(j_decompress_ptr cinfo, J_BUF_MODE pass_mode)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 74 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xc(%ebp), %eax\n" /* pass_mode */
        "movl 0x194(%ecx), %esi\n" /* line 75 | post */
        "cmpl $2, %eax\n" /* line 77 */
        "je .Lf2069ac_00206a1f\n"
        "cmpl $3, %eax\n"
        "je .Lf2069ac_00206a48\n"
        "testl %eax, %eax\n"
        "je .Lf2069ac_002069f8\n"
        "movl (%ecx), %eax\n" /* line 113 */
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf2069ac_002069e3:\n"
        "movl $0, 0x18(%esi)\n" /* line 116 | post */
        "movl $0, 0x14(%esi)\n" /* post */
        "addl $0x20, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2069ac_002069f8:\n"
        "cmpb $0, 0x52(%ecx)\n" /* line 79 */
        "jne .Lf2069ac_00206a6d\n"
        "movl 0x1a8(%ecx), %eax\n" /* line 95 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 4(%esi)\n" /* post */
        "movl $0, 0x18(%esi)\n" /* line 116 | post */
        "movl $0, 0x14(%esi)\n" /* post */
        "addl $0x20, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2069ac_00206a1f:\n"
        "movl 8(%esi), %eax\n" /* line 107 | post */
        "testl %eax, %eax\n"
        "je .Lf2069ac_00206ac2\n"
        ".Lf2069ac_00206a2a:\n"
        "leal 0x298(%ebx), %eax\n" /* line 109 */
        "movl %eax, 4(%esi)\n" /* post */
        "movl $0, 0x18(%esi)\n" /* line 116 | post */
        "movl $0, 0x14(%esi)\n" /* post */
        "addl $0x20, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2069ac_00206a48:\n"
        "movl 8(%esi), %edx\n" /* line 101 | post */
        "testl %edx, %edx\n"
        "je .Lf2069ac_00206ab0\n"
        ".Lf2069ac_00206a4f:\n"
        "leal 0x1b3(%ebx), %eax\n" /* line 103 */
        "movl %eax, 4(%esi)\n" /* post */
        "movl $0, 0x18(%esi)\n" /* line 116 | post */
        "movl $0, 0x14(%esi)\n" /* post */
        "addl $0x20, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2069ac_00206a6d:\n"
        "leal 0x11e(%ebx), %eax\n" /* line 81 */
        "movl %eax, 4(%esi)\n" /* post */
        "movl 0xc(%esi), %eax\n" /* line 86 | post */
        "testl %eax, %eax\n"
        "jne .Lf2069ac_002069e3\n"
        "movl 4(%ecx), %edx\n" /* line 87 */
        "movl $1, 0x10(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* post */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 8(%esi), %eax\n" /* post */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *0x1c(%edx)\n"
        "movl %eax, 0xc(%esi)\n" /* post */
        "jmp .Lf2069ac_002069e3\n"
        ".Lf2069ac_00206ab0:\n"
        "movl (%ecx), %eax\n" /* line 102 */
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf2069ac_00206a4f\n"
        ".Lf2069ac_00206ac2:\n"
        "movl (%ecx), %eax\n" /* line 108 */
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf2069ac_00206a2a\n"
    );
}

/* line 131 */
static __attribute__((naked))
void post_process_1pass(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x20(%ebp), %eax\n" /* out_rows_avail */
        "movl 0x194(%esi), %edi\n" /* line 132 | cinfo, post */
        "movl 0x1c(%ebp), %edx\n" /* line 137 | out_row_ctr */
        "subl (%edx), %eax\n"
        "movl 0x10(%edi), %edx\n" /* line 138 | post */
        "cmpl %edx, %eax\n"
        "cmoval %edx, %eax\n"
        "movl $0, -0xc(%ebp)\n" /* line 140 | num_rows */
        "movl 0x1a8(%esi), %edx\n" /* line 141 | cinfo */
        "movl %eax, 0x18(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* num_rows */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* post */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* in_row_groups_avail */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* in_row_group_ctr */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* input_buf */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%edx)\n"
        "movl 0x1b0(%esi), %ecx\n" /* line 145 | cinfo */
        "movl -0xc(%ebp), %eax\n" /* num_rows */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x1c(%ebp), %edx\n" /* out_row_ctr */
        "movl (%edx), %eax\n"
        "movl 0x18(%ebp), %edx\n" /* output_buf */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* post */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%ecx)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 147 | out_row_ctr */
        "movl (%edx), %eax\n"
        "addl -0xc(%ebp), %eax\n" /* num_rows */
        "movl %eax, (%edx)\n"
        "addl $0x30, %esp\n" /* line 148 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 163 */
static __attribute__((naked))
void post_process_prepass(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 163 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 164 | cinfo */
        "movl 0x194(%eax), %edi\n" /* post */
        "movl 0x18(%edi), %edx\n" /* line 168 | post */
        "testl %edx, %edx\n"
        "je .Lf206b6c_00206be0\n"
        ".Lf206b6c_00206b84:\n"
        "movl 0x18(%edi), %esi\n" /* line 175 | post, old_next_row */
        "movl 0x1a8(%eax), %edx\n" /* line 176 */
        "movl 0x10(%edi), %eax\n" /* post */
        "movl %eax, 0x18(%esp)\n"
        "leal 0x18(%edi), %eax\n" /* post */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* post */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* in_row_groups_avail */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* in_row_group_ctr */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* input_buf */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "movl 0x18(%edi), %eax\n" /* line 182 | post */
        "cmpl %eax, %esi\n" /* old_next_row */
        "jb .Lf206b6c_00206c14\n"
        ".Lf206b6c_00206bc7:\n"
        "movl 0x10(%edi), %eax\n" /* line 190 | post */
        "cmpl %eax, 0x18(%edi)\n" /* post */
        "jb .Lf206b6c_00206bd9\n"
        "addl %eax, 0x14(%edi)\n" /* line 191 | post */
        "movl $0, 0x18(%edi)\n" /* line 192 | post */
        ".Lf206b6c_00206bd9:\n"
        "addl $0x30, %esp\n" /* line 194 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf206b6c_00206be0:\n"
        "movl 4(%eax), %edx\n" /* line 169 */
        "movl $1, 0x10(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* post */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* post */
        "movl %eax, 8(%esp)\n"
        "movl 8(%edi), %eax\n" /* post */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0x1c(%edx)\n"
        "movl %eax, 0xc(%edi)\n" /* post */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf206b6c_00206b84\n"
        ".Lf206b6c_00206c14:\n"
        "subl %esi, %eax\n" /* line 183 | old_next_row */
        "movl %eax, -0xc(%ebp)\n" /* num_rows */
        "movl 8(%ebp), %eax\n" /* line 184 | cinfo */
        "movl 0x1b0(%eax), %edx\n"
        "movl -0xc(%ebp), %eax\n" /* num_rows */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* post */
        "leal (%eax, %esi, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 186 | num_rows */
        "movl 0x1c(%ebp), %edx\n" /* out_row_ctr */
        "addl %eax, (%edx)\n"
        "jmp .Lf206b6c_00206bc7\n"
    );
}

/* line 207 */
static __attribute__((naked))
void post_process_2pass(j_decompress_ptr cinfo, JSAMPIMAGE input_buf, JDIMENSION *in_row_group_ctr, JDIMENSION in_row_groups_avail, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 207 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 208 | cinfo */
        "movl 0x194(%eax), %edi\n" /* post */
        "movl 0x18(%edi), %ecx\n" /* line 212 | post */
        "testl %ecx, %ecx\n"
        "je .Lf206c51_00206ce4\n"
        ".Lf206c51_00206c69:\n"
        "movl 0x18(%edi), %ecx\n" /* line 219 | post */
        "movl 0x10(%edi), %esi\n" /* post, num_rows */
        "subl %ecx, %esi\n" /* num_rows */
        "movl 0x1c(%ebp), %edx\n" /* line 220 | out_row_ctr */
        "movl (%edx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x20(%ebp), %eax\n" /* out_rows_avail */
        "subl %edx, %eax\n"
        "cmpl %eax, %esi\n" /* line 221 | num_rows */
        "cmoval %eax, %esi\n" /* num_rows */
        "movl 8(%ebp), %edx\n" /* line 224 | cinfo */
        "movl 0x68(%edx), %eax\n"
        "subl 0x14(%edi), %eax\n" /* post */
        "cmpl %eax, %esi\n" /* line 225 | num_rows */
        "cmoval %eax, %esi\n" /* num_rows */
        "movl 0x1b0(%edx), %eax\n" /* line 229 */
        "movl %eax, -0xc(%ebp)\n"
        "movl %esi, 0xc(%esp)\n" /* num_rows */
        "movl -0x1c(%ebp), %edx\n"
        "movl 0x18(%ebp), %eax\n" /* output_buf */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* post */
        "leal (%eax, %ecx, 4), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "movl -0xc(%ebp), %edx\n"
        "calll *4(%edx)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 232 | out_row_ctr */
        "addl %esi, (%eax)\n" /* num_rows */
        "addl 0x18(%edi), %esi\n" /* line 235 | post, num_rows */
        "movl %esi, 0x18(%edi)\n" /* num_rows, post */
        "movl 0x10(%edi), %eax\n" /* line 236 | post */
        "cmpl %eax, %esi\n" /* num_rows */
        "jb .Lf206c51_00206cdd\n"
        "addl %eax, 0x14(%edi)\n" /* line 237 | post */
        "movl $0, 0x18(%edi)\n" /* line 238 | post */
        ".Lf206c51_00206cdd:\n"
        "addl $0x40, %esp\n" /* line 240 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf206c51_00206ce4:\n"
        "movl 4(%eax), %edx\n" /* line 213 */
        "movl $0, 0x10(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* post */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* post */
        "movl %eax, 8(%esp)\n"
        "movl 8(%edi), %eax\n" /* post */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0x1c(%edx)\n"
        "movl %eax, 0xc(%edi)\n" /* post */
        "jmp .Lf206c51_00206c69\n"
    );
}

/* line 251 */
__attribute__((naked))
void jinit_d_post_controller(j_decompress_ptr cinfo, int need_full_buffer)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 251 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movzbl 0xc(%ebp), %eax\n" /* need_full_buffer */
        "movb %al, -0x1d(%ebp)\n" /* need_full_buffer */
        "movl 8(%ebp), %edx\n" /* line 254 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x1c, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, %edi\n" /* post */
        "movl 8(%ebp), %ecx\n" /* line 257 | cinfo */
        "movl %eax, 0x194(%ecx)\n"
        "leal -0x377(%ebx), %eax\n" /* line 258 */
        "movl %eax, (%edi)\n" /* post */
        "movl $0, 8(%edi)\n" /* line 259 | post */
        "movl $0, 0xc(%edi)\n" /* line 260 | post */
        "cmpb $0, 0x52(%ecx)\n" /* line 263 */
        "je .Lf206d15_00206da1\n"
        "movl 0x11c(%ecx), %esi\n" /* line 268 */
        "movl %esi, 0x10(%edi)\n" /* post */
        "cmpb $0, -0x1d(%ebp)\n" /* line 269 | need_full_buffer */
        "jne .Lf206d15_00206da9\n"
        "movl 8(%ebp), %ecx\n" /* line 284 | cinfo */
        "movl 4(%ecx), %eax\n"
        "movl %esi, 0xc(%esp)\n"
        "movl 0x64(%ecx), %edx\n"
        "imull 0x6c(%ecx), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *8(%eax)\n"
        "movl %eax, 0xc(%edi)\n" /* post */
        ".Lf206d15_00206da1:\n"
        "addl $0x3c, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf206d15_00206da9:\n"
        "movl 4(%ecx), %eax\n" /* line 273 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %esi, 4(%esp)\n"
        "movl 0x68(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jround_up\n"
        "movl %esi, 0x14(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x64(%edx), %eax\n"
        "imull 0x6c(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *-0x1c(%ebp)\n"
        "movl %eax, 8(%edi)\n" /* post */
        "addl $0x3c, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

